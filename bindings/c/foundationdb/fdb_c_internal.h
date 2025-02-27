/*
 * fdb_c_internal.h
 *
 * This source file is part of the FoundationDB open source project
 *
 * Copyright 2013-2022 Apple Inc. and the FoundationDB project authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FDB_C_INTERNAL_H
#define FDB_C_INTERNAL_H
#include "flow/ProtocolVersion.h"
#pragma once

#ifndef DLLEXPORT
#define DLLEXPORT
#endif

#ifndef WARN_UNUSED_RESULT
#define WARN_UNUSED_RESULT
#endif

#include "fdb_c_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// forward declaration and typedef
typedef struct DatabaseSharedState DatabaseSharedState;

DLLEXPORT FDBFuture* fdb_database_create_shared_state(FDBDatabase* db);

DLLEXPORT void fdb_database_set_shared_state(FDBDatabase* db, DatabaseSharedState* p);

DLLEXPORT WARN_UNUSED_RESULT fdb_error_t fdb_future_get_shared_state(FDBFuture* f, DatabaseSharedState** outPtr);

DLLEXPORT WARN_UNUSED_RESULT fdb_error_t fdb_create_database_from_connection_string(const char* connection_string,
                                                                                    FDBDatabase** out_database);

DLLEXPORT void fdb_use_future_protocol_version();

#ifdef __cplusplus
}
#endif
#endif
