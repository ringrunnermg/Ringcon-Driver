#pragma once
#include <chrono>
#include <thread>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <consoleapi.h>
#include <random>

//#include <curl/curl.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

static uint8_t mcu_crc8_table[256] = {
0x00, 0x07, 0x0E, 0x09, 0x1C, 0x1B, 0x12, 0x15, 0x38, 0x3F, 0x36, 0x31, 0x24, 0x23, 0x2A, 0x2D,
0x70, 0x77, 0x7E, 0x79, 0x6C, 0x6B, 0x62, 0x65, 0x48, 0x4F, 0x46, 0x41, 0x54, 0x53, 0x5A, 0x5D,
0xE0, 0xE7, 0xEE, 0xE9, 0xFC, 0xFB, 0xF2, 0xF5, 0xD8, 0xDF, 0xD6, 0xD1, 0xC4, 0xC3, 0xCA, 0xCD,
0x90, 0x97, 0x9E, 0x99, 0x8C, 0x8B, 0x82, 0x85, 0xA8, 0xAF, 0xA6, 0xA1, 0xB4, 0xB3, 0xBA, 0xBD,
0xC7, 0xC0, 0xC9, 0xCE, 0xDB, 0xDC, 0xD5, 0xD2, 0xFF, 0xF8, 0xF1, 0xF6, 0xE3, 0xE4, 0xED, 0xEA,
0xB7, 0xB0, 0xB9, 0xBE, 0xAB, 0xAC, 0xA5, 0xA2, 0x8F, 0x88, 0x81, 0x86, 0x93, 0x94, 0x9D, 0x9A,
0x27, 0x20, 0x29, 0x2E, 0x3B, 0x3C, 0x35, 0x32, 0x1F, 0x18, 0x11, 0x16, 0x03, 0x04, 0x0D, 0x0A,
0x57, 0x50, 0x59, 0x5E, 0x4B, 0x4C, 0x45, 0x42, 0x6F, 0x68, 0x61, 0x66, 0x73, 0x74, 0x7D, 0x7A,
0x89, 0x8E, 0x87, 0x80, 0x95, 0x92, 0x9B, 0x9C, 0xB1, 0xB6, 0xBF, 0xB8, 0xAD, 0xAA, 0xA3, 0xA4,
0xF9, 0xFE, 0xF7, 0xF0, 0xE5, 0xE2, 0xEB, 0xEC, 0xC1, 0xC6, 0xCF, 0xC8, 0xDD, 0xDA, 0xD3, 0xD4,
0x69, 0x6E, 0x67, 0x60, 0x75, 0x72, 0x7B, 0x7C, 0x51, 0x56, 0x5F, 0x58, 0x4D, 0x4A, 0x43, 0x44,
0x19, 0x1E, 0x17, 0x10, 0x05, 0x02, 0x0B, 0x0C, 0x21, 0x26, 0x2F, 0x28, 0x3D, 0x3A, 0x33, 0x34,
0x4E, 0x49, 0x40, 0x47, 0x52, 0x55, 0x5C, 0x5B, 0x76, 0x71, 0x78, 0x7F, 0x6A, 0x6D, 0x64, 0x63,
0x3E, 0x39, 0x30, 0x37, 0x22, 0x25, 0x2C, 0x2B, 0x06, 0x01, 0x08, 0x0F, 0x1A, 0x1D, 0x14, 0x13,
0xAE, 0xA9, 0xA0, 0xA7, 0xB2, 0xB5, 0xBC, 0xBB, 0x96, 0x91, 0x98, 0x9F, 0x8A, 0x8D, 0x84, 0x83,
0xDE, 0xD9, 0xD0, 0xD7, 0xC2, 0xC5, 0xCC, 0xCB, 0xE6, 0xE1, 0xE8, 0xEF, 0xFA, 0xFD, 0xF4, 0xF3
};

static uint8_t ringmcu_crc8_table[256] = {
0x00, 0x8D, 0x97, 0x1A, 0xA3, 0x2E, 0x34, 0xB9, 0xCB, 0x46, 0x5C, 0xD1, 0x68, 0xE5, 0xFF, 0x72,
0x1B, 0x96, 0x8C, 0x01, 0xB8, 0x35, 0x2F, 0xA2, 0xD0, 0x5D, 0x47, 0xCA, 0x73, 0xFE, 0xE4, 0x69,
0x36, 0xBB, 0xA1, 0x2C, 0x95, 0x18, 0x02, 0x8F, 0xFD, 0x70, 0x6A, 0xE7, 0x5E, 0xD3, 0xC9, 0x44,
0x2D, 0xA0, 0xBA, 0x37, 0x8E, 0x03, 0x19, 0x94, 0xE6, 0x6B, 0x71, 0xFC, 0x45, 0xC8, 0xD2, 0x5F,
0x6C, 0xE1, 0xFB, 0x76, 0xCF, 0x42, 0x58, 0xD5, 0xA7, 0x2A, 0x30, 0xBD, 0x04, 0x89, 0x93, 0x1E,
0x77, 0xFA, 0xE0, 0x6D, 0xD4, 0x59, 0x43, 0xCE, 0xBC, 0x31, 0x2B, 0xA6, 0x1F, 0x92, 0x88, 0x05,
0x5A, 0xD7, 0xCD, 0x40, 0xF9, 0x74, 0x6E, 0xE3, 0x91, 0x1C, 0x06, 0x8B, 0x32, 0xBF, 0xA5, 0x28,
0x41, 0xCC, 0xD6, 0x5B, 0xE2, 0x6F, 0x75, 0xF8, 0x8A, 0x07, 0x1D, 0x90, 0x29, 0xA4, 0xBE, 0x33,
0xD8, 0x55, 0x4F, 0xC2, 0x7B, 0xF6, 0xEC, 0x61, 0x13, 0x9E, 0x84, 0x09, 0xB0, 0x3D, 0x27, 0xAA,
0xC3, 0x4E, 0x54, 0xD9, 0x60, 0xED, 0xF7, 0x7A, 0x08, 0x85, 0x9F, 0x12, 0xAB, 0x26, 0x3C, 0xB1,
0xEE, 0x63, 0x79, 0xF4, 0x4D, 0xC0, 0xDA, 0x57, 0x25, 0xA8, 0xB2, 0x3F, 0x86, 0x0B, 0x11, 0x9C,
0xF5, 0x78, 0x62, 0xEF, 0x56, 0xDB, 0xC1, 0x4C, 0x3E, 0xB3, 0xA9, 0x24, 0x9D, 0x10, 0x0A, 0x87,
0xB4, 0x39, 0x23, 0xAE, 0x17, 0x9A, 0x80, 0x0D, 0x7F, 0xF2, 0xE8, 0x65, 0xDC, 0x51, 0x4B, 0xC6,
0xAF, 0x22, 0x38, 0xB5, 0x0C, 0x81, 0x9B, 0x16, 0x64, 0xE9, 0xF3, 0x7E, 0xC7, 0x4A, 0x50, 0xDD,
0x82, 0x0F, 0x15, 0x98, 0x21, 0xAC, 0xB6, 0x3B, 0x49, 0xC4, 0xDE, 0x53, 0xEA, 0x67, 0x7D, 0xF0,
0x99, 0x14, 0x0E, 0x83, 0x3A, 0xB7, 0xAD, 0x20, 0x52, 0xDF, 0xC5, 0x48, 0xF1, 0x7C, 0x66, 0xEB
};

double lowpassFilter(double a, double thresh) {
	if (abs(a) > thresh) {
		return a;
	}
	else {
		return 0;
	}
}

int rand_range(int min, int max) {
	return rand() % (max + 1 - min) + min;
}

// sleeps accurately:
void accurateSleep(double durationMS, double sleepThreshold = 1.8) {

	// get current time
	auto tNow = std::chrono::high_resolution_clock::now();

	auto tSleepStart = std::chrono::high_resolution_clock::now();

	auto tSleepDuration = std::chrono::duration_cast<std::chrono::microseconds>(tNow - tSleepStart);

	// get the application's runtime duration in ms
	//runningTimeMS = std::chrono::duration_cast<std::chrono::milliseconds>(tNow - tApplicationStart).count();
	//auto tFrameDuration = std::chrono::duration_cast<std::chrono::microseconds>(tNow - tFrameStart);
	//double tFrameDurationMS = tFrameDuration.count() / 1000.0;


	// time spent sleeping (0):
	double tSleepTimeMS = tSleepDuration.count() / 1000.0;

	//float lowerThres = 0.2;
	//float sleepThreshold = 1.8;//1.4

	// run cpu in circles
	while (tSleepTimeMS < durationMS) {
		// allow cpu to sleep if there is lots of time to kill
		if (tSleepTimeMS < durationMS - sleepThreshold) {
			std::this_thread::sleep_for(std::chrono::microseconds(100));
			//Sleep(1);
		}
		tNow = std::chrono::high_resolution_clock::now();
		tSleepDuration = std::chrono::duration_cast<std::chrono::microseconds>(tNow - tSleepStart);
		tSleepTimeMS = tSleepDuration.count() / 1000.0;
	}

	// done sleeping

}

// sleeps very accurately:
void veryAccurateSleep(double durationMS) {

	// get current time
	auto tNow = std::chrono::high_resolution_clock::now();

	auto tSleepStart = std::chrono::high_resolution_clock::now();

	auto tSleepDuration = std::chrono::duration_cast<std::chrono::microseconds>(tNow - tSleepStart);

	// get the application's runtime duration in ms
	//runningTimeMS = std::chrono::duration_cast<std::chrono::milliseconds>(tNow - tApplicationStart).count();
	//auto tFrameDuration = std::chrono::duration_cast<std::chrono::microseconds>(tNow - tFrameStart);
	//double tFrameDurationMS = tFrameDuration.count() / 1000.0;


	// time spent sleeping (0):
	double tSleepTimeMS = tSleepDuration.count() / 1000.0;

	//float lowerThres = 0.2;
	//float sleepThreshold = 1.8;//1.4

	// run cpu in circles
	while (tSleepTimeMS < durationMS) {

		// never sleep, burn the CPU
		tNow = std::chrono::high_resolution_clock::now();
		tSleepDuration = std::chrono::duration_cast<std::chrono::microseconds>(tNow - tSleepStart);
		tSleepTimeMS = tSleepDuration.count() / 1000.0;
	}

	// done "sleeping"
}



/* The LoadConfig function loads the configuration file given by filename
It returns a map of key-value pairs stored in the conifuration file */
std::map<std::string, std::string> LoadConfig(std::string filename)
{
	std::ifstream input(filename); //The input stream
	std::map<std::string, std::string> ans; //A map of key-value pairs in the file
	while (input) //Keep on going as long as the file stream is good
	{
		std::string key; //The key
		std::string value; //The value
		std::getline(input, key, ':'); //Read up to the : delimiter into key
		std::getline(input, value, '\n'); //Read up to the newline into value
		std::string::size_type pos1 = value.find_first_of("\""); //Find the first quote in the value
		std::string::size_type pos2 = value.find_last_of("\""); //Find the last quote in the value
		if (pos1 != std::string::npos && pos2 != std::string::npos && pos2 > pos1) //Check if the found positions are all valid
		{
			value = value.substr(pos1 + 1, pos2 - pos1 - 1); //Take a substring of the part between the quotes
			ans[key] = value; //Store the result in the map
		}
	}
	input.close(); //Close the file stream
	return ans; //And return the result
}


void setupConsole(std::string title) {
	// setup console
	AllocConsole();
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);
	printf("Debugging Window:\n");
}


int16_t unsignedToSigned16(uint16_t n) {
	uint16_t A = n;
	uint16_t B = 0xFFFF - A;
	if (A < B) {
		return (int16_t)A;
	}
	else {
		return (int16_t)(-1 * B);
	}
}

int16_t uint16_to_int16(uint16_t a) {
	int16_t b;
	char* aPointer = (char*)&a, * bPointer = (char*)&b;
	memcpy(bPointer, aPointer, sizeof(a));
	return b;
}

uint16_t combine_uint8_t(uint8_t a, uint8_t b) {
	uint16_t c = ((uint16_t)a << 8) | b;
	return c;
}

int16_t combine_gyro_data(uint8_t a, uint8_t b) {
	uint16_t c = combine_uint8_t(a, b);
	int16_t d = uint16_to_int16(c);
	return d;
}


float clamp(float a, float min, float max) {
	if (a < min) {
		return min;
	}
	else if (a > max) {
		return max;
	}
	else {
		return a;
	}
}

unsigned createMask(unsigned a, unsigned b) {
	unsigned r = 0;
	for (unsigned i = a; i <= b; i++)
		r |= 1 << i;

	return r;
}

inline int mk_even(int n) {
	return n - n % 2;
}

inline int mk_odd(int n) {
	return n - (n % 2 ? 0 : 1);
}


float rand0t1() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0.0f, 1.0f);
	float rnd = dis(gen);
	return rnd;
}

//struct s_button_map {
//	int bit;
//	char *name;
//};
//
//
//struct s_button_map button_map[16] = {
//	{ 0, "D" },{ 1, "R" },{ 2, "L" },{ 3, "U" },{ 4, "SL" },{ 5, "SR" },
//	{ 6, "?" },{ 7, "?" },{ 8, "-" },{ 9, "+" },{ 10, "LS" },{ 11, "RS" },
//	{ 12, "Ho" },{ 13, "Sc" },{ 14, "LR" },{ 15, "ZLR" },
//};
//
//void print_buttons(Joycon *jc) {
//
//	for (int i = 0; i < 16; i++) {
//		if (jc->buttons & (1 << button_map[i].bit)) {
//			printf("1");
//		} else {
//			printf("0");
//		}
//	}
//	printf("\n");
//}


//void print_buttons2(Joycon *jc) {
//
//	printf("Joycon %c (Unattached): ", L_OR_R(jc->left_right));
//
//	for (int i = 0; i < 32; i++) {
//		if (jc->buttons2[i]) {
//			printf("1");
//		} else {
//			printf("0");
//		}
//
//	}
//	printf("\n");
//}

//void print_stick2(Joycon *jc) {
//
//	printf("Joycon %c (Unattached): ", L_OR_R(jc->left_right));
//
//	printf("%d %d\n", jc->stick.horizontal, jc->stick.vertical);
//}




const char* const dstick_names[9] = { "Up", "UR", "Ri", "DR", "Do", "DL", "Le", "UL", "Neu" };



void hex_dump(unsigned char* buf, int len) {
	for (int i = 0; i < len; i++) {
		printf("%02x ", buf[i]);
	}
	printf("\n");
}

void hex_dump2(unsigned char* buf, int len) {
	for (int i = 0; i < len; i++) {
		printf("%02x ", buf[i]);
	}
}

void hex_dump_0(unsigned char* buf, int len) {
	for (int i = 0; i < len; i++) {
		if (buf[i] != 0) {
			printf("%02x ", buf[i]);
		}
	}
}

void int_dump(unsigned char* buf, int len) {
	for (int i = 0; i < len; i++) {
		printf("%i ", buf[i]);
	}
	printf("\n");
}

int _floor(float n) {
	return (int)n;
}


//void device_print(struct hid_device_info *dev) {
//	printf("USB device info:\n  vid: 0x%04hX pid: 0x%04hX\n  path: %s\n  serial_number: %ls\n  interface_number: %d\n",
//		dev->vendor_id, dev->product_id, dev->path, dev->serial_number, dev->interface_number);
//	printf("  Manufacturer: %ls\n", dev->manufacturer_string);
//	printf("  Product:      %ls\n\n", dev->product_string);
//}



//void print_dstick(Joycon *jc) {
//	printf("%s\n", dstick_names[jc->dstick]);
//}

//inline bool exists_test0(const std::string& name) {
//	ifstream f(name.c_str());
//	return f.good();
//}

/*inline bool exists_test0(const std::string& name) {
	if (FILE* file = fopen(name.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}*/

template<typename T>
std::string get_time(std::chrono::time_point<T> time) {
	using namespace std;
	using namespace std::chrono;

	time_t curr_time = T::to_time_t(time);
	char sRep[100];
	strftime(sRep, sizeof(sRep), "%Y-%m-%d %H:%M:%S", localtime(&curr_time));

	typename T::duration since_epoch = time.time_since_epoch();
	seconds sec = duration_cast<seconds>(since_epoch);
	since_epoch -= sec;
	milliseconds milli = duration_cast<milliseconds>(since_epoch);


	string s = "";
	stringstream ss;
	ss << "[" << sRep << ":" << milli.count() << "]";
	s = ss.str();

	//s = to_string(sRep);

	return s;

}