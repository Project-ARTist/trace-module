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

#include <artist/api/filtering/method_name_filters.h>

#include "module.h"
#include "instrumentation_pass.h"
#include "codelib.h"

using std::make_shared;
using std::unique_ptr;

using art::MethodNameBlacklist;
using art::FilesystemHelper;


HArtist *TraceModule::createPass(const MethodInfo &method_info) const {
  return new(method_info.GetGraph()->GetArena()) HTraceArtist(method_info);
}

shared_ptr<const CodeLib> TraceModule::createCodeLib() const {
  return make_shared<TraceCodeLib>();
}

// skip android support lib ui methods since they bloat up the log
unique_ptr<Filter> TraceModule::getMethodFilter() const {
  const vector<const string> blackListDefinition = {
      "android.support.",
  };
  return unique_ptr<Filter>(new MethodNameBlacklist(blackListDefinition));
}

TraceModule::TraceModule(shared_ptr<const FilesystemHelper> fs) : Module(fs) {}


// the class factory

extern "C" shared_ptr <art::Module> create(shared_ptr<const FilesystemHelper> fshelper) {
  return make_shared<TraceModule>(fshelper);
}

extern "C" art::ModuleId get_id() {
  return "saarland.cispa.artist.modules.trace";
}