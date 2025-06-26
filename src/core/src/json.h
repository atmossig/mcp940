#ifndef CORE_JSON_H_
#define CORE_JSON_H_

#include <string>
#include <vector>
#include "rapidjson/document.h"

#include "core_config.h"

MC_BEGIN_NAMESPACE

class Json {
public:
	// Get float value with default fallback
	static float getFloat(const rapidjson::Value& obj, const char* key, float defaultValue);

	// Get boolean value with default fallback
	static bool getBoolean(const rapidjson::Value& obj, const char* key, bool defaultValue);
	
	// Get string value (returns empty string if not found)
	static std::string getString(const rapidjson::Value& obj, const char* key);
	
	// Get string value with default fallback
	static std::string getString(const rapidjson::Value& obj, const char* key, const char* defaultValue);
	
	// Parse float array with expected length
	static std::vector<float> parseFloatArray(const rapidjson::Value& element, int expectedLength);
	
	// Parse float array with expected length and default fallback
	static std::vector<float> parseFloatArray(const rapidjson::Value& element, int expectedLength, const float* defaultArray);
	
	// Parse int array with expected length
	static std::vector<int> parseIntArray(const rapidjson::Value& element, int expectedLength);
	
	// Parse int array with expected length and default fallback
	static std::vector<int> parseIntArray(const rapidjson::Value& element, int expectedLength, const int* defaultArray);
};

MC_END_NAMESPACE

#endif // CORE_JSON_H_