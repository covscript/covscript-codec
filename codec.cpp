/*
* Covariant Script Network Extension
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* Copyright (C) 2019 Michael Lee(李登淳)
* Email: mikecovlee@163.com
* Github: https://github.com/mikecovlee
*/
// Base32
#include <cppcodec/base32_rfc4648.hpp>
#include <cppcodec/base32_crockford.hpp>
#include <cppcodec/base32_hex.hpp>
// Base64
#include <cppcodec/base64_rfc4648.hpp>
#include <cppcodec/base64_url.hpp>
#include <cppcodec/base64_url_unpadded.hpp>
// JSON
#include <json/json.h>
// CovScript DLL Header
#include <covscript/dll.hpp>
#include <covscript/cni.hpp>

#define gen_invoker(NAME) [](const cs::string &str) -> cs::string { return NAME<std::string>(str); }

CNI_ROOT_NAMESPACE {
	CNI_NAMESPACE(base32)
	{
		CNI_NAMESPACE(rfc4648) {
			CNI_CONST_V(encode, gen_invoker(cppcodec::base32_rfc4648::encode));
			CNI_CONST_V(decode, gen_invoker(cppcodec::base32_rfc4648::decode));
		}
		CNI_NAMESPACE_ALIAS(rfc4648, standard);

		CNI_NAMESPACE(crockford) {
			CNI_CONST_V(encode, gen_invoker(cppcodec::base32_crockford::encode));
			CNI_CONST_V(decode, gen_invoker(cppcodec::base32_crockford::decode));
		}

		CNI_NAMESPACE(hex) {
			CNI_CONST_V(encode, gen_invoker(cppcodec::base32_hex::encode));
			CNI_CONST_V(decode, gen_invoker(cppcodec::base32_hex::decode));
		}
	}

	CNI_NAMESPACE(base64)
	{
		CNI_NAMESPACE(rfc4648) {
			CNI_CONST_V(encode, gen_invoker(cppcodec::base64_rfc4648::encode));
			CNI_CONST_V(decode, gen_invoker(cppcodec::base64_rfc4648::decode));
		}
		CNI_NAMESPACE_ALIAS(rfc4648, standard);

		CNI_NAMESPACE(url) {
			CNI_CONST_V(encode, gen_invoker(cppcodec::base64_url::encode));
			CNI_CONST_V(decode, gen_invoker(cppcodec::base64_url::decode));
		}

		CNI_NAMESPACE(url_unpadded) {
			CNI_CONST_V(encode, gen_invoker(cppcodec::base64_url_unpadded::encode))
			CNI_CONST_V(decode, gen_invoker(cppcodec::base64_url_unpadded::decode))
		}
	}

	CNI_NAMESPACE(json)
	{
		CNI_NAMESPACE(value) {
			// Constructor
			CNI_CONST_V(make_null, []() {
				return cs::var::make<Json::Value>(Json::ValueType::nullValue);
			});
			CNI_CONST_V(make_array, []() {
				return cs::var::make<Json::Value>(Json::ValueType::arrayValue);
			});
			CNI_CONST_V(make_object, []() {
				return cs::var::make<Json::Value>(Json::ValueType::objectValue);
			});
			CNI_CONST_V(make_int, [](int num) {
				return cs::var::make<Json::Value>(num);
			});
			CNI_CONST_V(make_uint, [](unsigned int num) {
				return cs::var::make<Json::Value>(num);
			});
			CNI_CONST_V(make_real, [](double num) {
				return cs::var::make<Json::Value>(num);
			});
			CNI_CONST_V(make_string, [](const std::string &str) {
				return cs::var::make<Json::Value>(str);
			});
			CNI_CONST_V(make_boolean, [](bool val) {
				return cs::var::make<Json::Value>(val);
			});
			// Type Conversion
			CNI_CONST_V(as_int, &Json::Value::asInt);
			CNI_CONST_V(as_uint, &Json::Value::asUInt);
			CNI_CONST_V(as_real, &Json::Value::asDouble);
			CNI_CONST_V(as_string, &Json::Value::asString);
			CNI_CONST_V(as_boolean, &Json::Value::asBool);
			// Type Predicator
			CNI_CONST_V(is_int, &Json::Value::isInt);
			CNI_CONST_V(is_uint, &Json::Value::isUInt);
			CNI_CONST_V(is_real, &Json::Value::isDouble);
			CNI_CONST_V(is_null, &Json::Value::isNull);
			CNI_CONST_V(is_array, &Json::Value::isArray);
			CNI_CONST_V(is_object, &Json::Value::isObject);
			CNI_CONST_V(is_number, &Json::Value::isNumeric);
			CNI_CONST_V(is_string, &Json::Value::isString);
			CNI_CONST_V(is_boolean, &Json::Value::isBool);
			// Array Operations
			CNI_CONST_V(arr_size, &Json::Value::size);
			CNI_CONST_V(arr_empty, &Json::Value::empty);
			CNI_CONST_V(arr_clear, &Json::Value::clear);
			CNI_CONST_V(arr_resize, &Json::Value::resize);
			CNI_CONST_V(arr_append, &Json::Value::append);
			CNI_CONST_V(arr_get, [](const Json::Value &value, int idx) {
				return value[idx];
			});
			CNI_CONST_V(arr_set, [](Json::Value &value, int idx, const Json::Value &target) {
				value[idx] = target;
			});
			// Member Enumeration
			CNI_CONST_V(get_member, [](const Json::Value &value, const std::string &key) {
				return value[key];
			});
			CNI_CONST_V(set_member, [](Json::Value &value, const std::string &key, const Json::Value &target) {
				value[key] = target;
			});
			CNI_CONST_V(has_member, [](const Json::Value &value, const std::string &key) {
				return value.isMember(key);
			});
			CNI_CONST_V(remove_member, [](Json::Value &value, const std::string &key) {
				return value.removeMember(key);
			});
			CNI_CONST_V(get_member_names, [](const Json::Value &value) {
				std::vector<std::string> names = value.getMemberNames();
				cs::var val = cs::var::make<cs::array>();
				cs::array &arr = val.val<cs::array>();
				for (auto &name:names)
					arr.emplace_back(name);
				return val;
			});
			// Write
			CNI_V(to_stream, [](const Json::Value &root, cs::ostream &os) {
				Json::StreamWriterBuilder builder;
				std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
				writer->write(root, os.get());
			});
		}

		// Read
		CNI_CONST_V(from_string, [](const std::string &doc) {
			cs::var val = cs::var::make<Json::Value>(Json::ValueType::nullValue);
			Json::Reader reader;
			reader.parse(doc, val.val<Json::Value>());
			return val;
		});

		CNI_V(from_stream, [](cs::istream &is) {
			cs::var val = cs::var::make<Json::Value>(Json::ValueType::nullValue);
			Json::CharReaderBuilder builder;
			std::string errs;
			if (!Json::parseFromStream(builder, *is, &val.val<Json::Value>(), &errs))
				throw cs::lang_error(errs);
			return val;
		});

		Json::Value from_var(const cs::var &val) {
			if (val == cs::null_pointer)
				return Json::Value(Json::ValueType::nullValue);
			else if (val.type() == typeid(cs::number))
				return Json::Value(static_cast<double>(val.const_val<cs::number>()));
			else if (val.type() == typeid(cs::string))
				return Json::Value(val.const_val<cs::string>());
			else if (val.type() == typeid(cs::boolean))
				return Json::Value(val.const_val<cs::boolean>());
			else if (val.type() == typeid(cs::array)) {
				const cs::array &arr = val.const_val<cs::array>();
				Json::Value value(Json::ValueType::arrayValue);
				for (auto &it:arr)
					value.append(from_var(it));
				return std::move(value);
			}
			else if (val.type() == typeid(cs::hash_map)) {
				const cs::hash_map &map = val.const_val<cs::hash_map>();
				Json::Value value(Json::ValueType::objectValue);
				for (auto &it:map) {
					if (it.first.type() != typeid(cs::string))
						throw cs::lang_error("Only support string key in map.");
					value[it.first.const_val<cs::string>()] = from_var(it.second);
				}
				return std::move(value);
			}
			else {
				try {
					return Json::Value(val.to_string());
				}
				catch (cov::error &e) {
					if (std::strcmp(e.what(), "E000D"))
						return Json::Value(cs_impl::cxx_demangle(val.type().name()));
					else
						throw;
				}
			}
		}

		CNI_CONST(from_var);

		// Write
		CNI_CONST_V(to_string, [](const Json::Value &root) {
			Json::FastWriter writer;
			return writer.write(root);
		});

		cs::var to_var(const Json::Value &root) {
			switch (root.type()) {
			case Json::ValueType::nullValue:
				return cs::null_pointer;
			case Json::ValueType::intValue:
				return cs::cni_convertor::to_covscript(root.asInt());
			case Json::ValueType::uintValue:
				return cs::cni_convertor::to_covscript(root.asUInt());
			case Json::ValueType::realValue:
				return cs::cni_convertor::to_covscript(root.asDouble());
			case Json::ValueType::stringValue:
				return root.asString();
			case Json::ValueType::booleanValue:
				return root.asBool();
			case Json::ValueType::arrayValue: {
				cs::var val = cs::var::make<cs::array>();
				cs::array &arr = val.val<cs::array>();
				for (int i = 0; i < root.size(); ++i)
					arr.emplace_back(to_var(root[i]));
				return val;
			}
			case Json::ValueType::objectValue: {
				cs::var val = cs::var::make<cs::hash_map>();
				cs::hash_map &map = val.val<cs::hash_map>();
				std::vector<std::string> names = root.getMemberNames();
				for (auto &name:names)
					map.emplace(name, to_var(root[name]));
				return val;
			}
			}
			return cs::null_pointer;
		}

		CNI_CONST(to_var);
	}
}

CNI_ENABLE_TYPE_EXT_V(json::value, Json::Value, json::value);
