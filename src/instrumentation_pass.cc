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
 * @author "Sebastian Weisgerber <weisgerber@cispa.saarland>"
 *
 */

#include <atomic>

#include <artist/artist_log.h>
#include <artist/injection/injection_visitor.h>
#include <artist/env/java_env.h>
#include <artist/injection/primitives.h>
#include <artist/injection/boolean.h>
#include <artist/injection/integer.h>
#include <artist/injection/float.h>
#include <artist/verbose_printer.h>
#include <artist/injection/char.h>

#include "instrumentation_pass.h"
#include "codelib.h"

using std::string;
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::endl;
using std::sort;

using art::Target;
using art::Parameter;
using art::Char;
using art::InjectionTarget ;

vector<Injection> HTraceArtist::ProvideInjections() const {
  vector<shared_ptr<const Parameter>> params;
  auto param = make_shared<const Char>();
  params.push_back(param);

  vector<const Target> targets;
  const Target target(Target::GENERIC_TARGET, InjectionTarget::METHOD_END);
  targets.push_back(target);

  Injection injection(TraceCodeLib::TRACELOG, params, targets);

  vector<Injection> results;
  results.push_back(injection);
  return results;
}
