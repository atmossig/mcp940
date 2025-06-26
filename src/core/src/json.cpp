#include "json.h"
#include "core_config.h"
#include <stdexcept>
#include <sstream>

MC_BEGIN_NAMESPACE

float Json::getFloat(const rapidjson::Value& obj, const char* key, float defaultValue) {
	if (!obj.IsObject() || !obj.HasMember(key) || !obj[key].IsNumber()) {
		return defaultValue;
	}
	return obj[key].GetFloat();
}

bool Json::getBoolean(const rapidjson::Value& obj, const char* key, bool defaultValue) {
	if (!obj.IsObject() || !obj.HasMember(key) || !obj[key].IsBool()) {
		return defaultValue;
	}
	return obj[key].GetBool();
}

std::string Json::getString(const rapidjson::Value& obj, const char* key) {
	return getString(obj, key, "");
}

std::string Json::getString(const rapidjson::Value& obj, const char* key, const char* defaultValue) {
	if (!obj.IsObject() || !obj.HasMember(key) || !obj[key].IsString()) {
		return defaultValue;
	}
	return obj[key].GetString();
}

std::vector<float> Json::parseFloatArray(const rapidjson::Value& element, int expectedLength) {
	return parseFloatArray(element, expectedLength, nullptr);
}

std::vector<float> Json::parseFloatArray(const rapidjson::Value& element, int expectedLength, const float* defaultArray) {
	if (element.IsNull()) {
		if (defaultArray) {
			return std::vector<float>(defaultArray, defaultArray + expectedLength);
		}
		return std::vector<float>();
	}
	
	if (!element.IsArray()) {
		throw std::runtime_error("JSON element is not an array");
	}
	
	if (element.Size() != expectedLength) {
		std::stringstream ss;
		ss << "Wrong array length: " << element.Size() << ", should be: " << expectedLength;
		throw std::runtime_error(ss.str());
	}
	
	std::vector<float> result(expectedLength);
	for (int i = 0; i < expectedLength; ++i) {
		if (!element[i].IsNumber()) {
			throw std::runtime_error("Array element is not a number");
		}
		result[i] = element[i].GetFloat();
	}
	
	return result;
}

std::vector<int> Json::parseIntArray(const rapidjson::Value& element, int expectedLength) {
	return parseIntArray(element, expectedLength, nullptr);
}

std::vector<int> Json::parseIntArray(const rapidjson::Value& element, int expectedLength, const int* defaultArray) {
	if (element.IsNull()) {
		if (defaultArray) {
			return std::vector<int>(defaultArray, defaultArray + expectedLength);
		}
		return std::vector<int>();
	}
	
	if (!element.IsArray()) {
		throw std::runtime_error("JSON element is not an array");
	}
	
	if (element.Size() != expectedLength) {
		std::stringstream ss;
		ss << "Wrong array length: " << element.Size() << ", should be: " << expectedLength;
		throw std::runtime_error(ss.str());
	}
	
	std::vector<int> result(expectedLength);
	for (int i = 0; i < expectedLength; ++i) {
		if (!element[i].IsNumber()) {
			throw std::runtime_error("Array element is not a number");
		}
		result[i] = element[i].GetInt();
	}
	
	return result;
}

MC_END_NAMESPACE