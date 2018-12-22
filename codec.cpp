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
* Copyright (C) 2018 Michael Lee(李登淳)
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
// CovScript DLL Header
#include <covscript/dll.hpp>

#define gen_invoker(NAME) [](const cs::string &str) -> cs::string { return NAME<std::string>(str); }

void cs_extension_main(cs::name_space *ns)
{
	// Base32 root namespace
	cs::namespace_t base32_ns = cs::make_shared_namespace<cs::name_space>();
	// Base32 child namespace
	cs::namespace_t base32_rfc4648_ns = cs::make_shared_namespace<cs::name_space>();
	cs::namespace_t base32_crockford_ns = cs::make_shared_namespace<cs::name_space>();
	cs::namespace_t base32_hex_ns = cs::make_shared_namespace<cs::name_space>();
	// Base64 root namespace
	cs::namespace_t base64_ns = cs::make_shared_namespace<cs::name_space>();
	// Base64 child namespace
	cs::namespace_t base64_rfc4648_ns = cs::make_shared_namespace<cs::name_space>();
	cs::namespace_t base64_url_ns = cs::make_shared_namespace<cs::name_space>();
	cs::namespace_t base64_url_unpadded_ns = cs::make_shared_namespace<cs::name_space>();
	// Register
	(*ns)
	.add_var("base32", cs::make_namespace(base32_ns))
	.add_var("base64", cs::make_namespace(base64_ns));
	(*base32_ns)
	.add_var("standard", cs::make_namespace(base32_rfc4648_ns))
	.add_var("rfc4648", cs::make_namespace(base32_rfc4648_ns))
	.add_var("crockford", cs::make_namespace(base32_crockford_ns))
	.add_var("hex", cs::make_namespace(base32_hex_ns));
	(*base32_rfc4648_ns)
	.add_var("encode", cs::make_cni(gen_invoker(cppcodec::base32_rfc4648::encode), true))
	.add_var("decode", cs::make_cni(gen_invoker(cppcodec::base32_rfc4648::decode), true));
	(*base32_crockford_ns)
	.add_var("encode", cs::make_cni(gen_invoker(cppcodec::base32_crockford::encode), true))
	.add_var("decode", cs::make_cni(gen_invoker(cppcodec::base32_crockford::decode), true));
	(*base32_hex_ns)
	.add_var("encode", cs::make_cni(gen_invoker(cppcodec::base32_hex::encode), true))
	.add_var("decode", cs::make_cni(gen_invoker(cppcodec::base32_hex::decode), true));
	(*base64_ns)
	.add_var("standard", cs::make_namespace(base64_rfc4648_ns))
	.add_var("rfc4648", cs::make_namespace(base64_rfc4648_ns))
	.add_var("url", cs::make_namespace(base64_url_ns))
	.add_var("url_unpadded", cs::make_namespace(base64_url_unpadded_ns));
	(*base64_rfc4648_ns)
	.add_var("encode", cs::make_cni(gen_invoker(cppcodec::base64_rfc4648::encode), true))
	.add_var("decode", cs::make_cni(gen_invoker(cppcodec::base64_rfc4648::decode), true));
	(*base64_url_ns)
	.add_var("encode", cs::make_cni(gen_invoker(cppcodec::base64_url::encode), true))
	.add_var("decode", cs::make_cni(gen_invoker(cppcodec::base64_url::decode), true));
	(*base64_url_unpadded_ns)
	.add_var("encode", cs::make_cni(gen_invoker(cppcodec::base64_url_unpadded::encode), true))
	.add_var("decode", cs::make_cni(gen_invoker(cppcodec::base64_url_unpadded::decode), true));
}