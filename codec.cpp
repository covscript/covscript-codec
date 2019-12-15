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
	CNI_NAMESPACE(base32) {
		CNI_NAMESPACE(rfc4648) {
			CNI_CONST_V(encode, gen_invoker(cppcodec::base32_rfc4648::encode));
			CNI_CONST_V(decode, gen_invoker(cppcodec::base32_rfc4648::decode));
		} 	CNI_NAMESPACE_ALIAS(rfc4648, standard);

		CNI_NAMESPACE(crockford) {
			CNI_CONST_V(encode, gen_invoker(cppcodec::base32_crockford::encode));
			CNI_CONST_V(decode, gen_invoker(cppcodec::base32_crockford::decode));
		}

		CNI_NAMESPACE(hex) {
			CNI_CONST_V(encode, gen_invoker(cppcodec::base32_hex::encode));
			CNI_CONST_V(decode, gen_invoker(cppcodec::base32_hex::decode));
		}
	}

	CNI_NAMESPACE(base64) {
		CNI_NAMESPACE(rfc4648) {
			CNI_CONST_V(encode, gen_invoker(cppcodec::base64_rfc4648::encode));
			CNI_CONST_V(decode, gen_invoker(cppcodec::base64_rfc4648::decode));
		} 	CNI_NAMESPACE_ALIAS(rfc4648, standard);

		CNI_NAMESPACE(url) {
			CNI_CONST_V(encode, gen_invoker(cppcodec::base64_url::encode));
			CNI_CONST_V(decode, gen_invoker(cppcodec::base64_url::decode));
		}

		CNI_NAMESPACE(url_unpadded) {
			CNI_CONST_V(encode, gen_invoker(cppcodec::base64_url_unpadded::encode))
			CNI_CONST_V(decode, gen_invoker(cppcodec::base64_url_unpadded::decode))
		}
	}

	CNI_NAMESPACE(json) {
		CNI_NAMESPACE(reader) {

		}

		CNI_NAMESPACE(writer) {

		}

		CNI_TYPE_EXT_V(value_ext, Json::Value, value, cs::var::make<Json::Value>()) {

		}
	}
}

CNI_ENABLE_TYPE_EXT_V(json::value_ext, Json::Value, json::value);