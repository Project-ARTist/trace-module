/**
 * The ARTist Project (https://artist.cispa.saarland)
 *
 * Copyright (C) 2017 CISPA (https://cispa.saarland), Saarland University
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @author "Oliver Schranz <oliver.schranz@cispa.saarland>"
 *
 */

#ifndef  ART_MODULES_TRACE_TRACE_MODULE_H_
#define  ART_MODULES_TRACE_TRACE_MODULE_H_

#include <artist/modules/module.h>

using art::Module;
using art::HArtist;
using art::MethodInfo;
using art::CodeLib;
using art::Filter;

class TraceModule : public Module {
    shared_ptr<HArtist> createPass(const MethodInfo& method_info) const OVERRIDE;
    shared_ptr<const CodeLib> createCodeLib() const OVERRIDE;

 public:
  unique_ptr<Filter> getMethodFilter() const OVERRIDE;
};

#endif  // ART_MODULES_TRACE_TRACE_MODULE_H_
