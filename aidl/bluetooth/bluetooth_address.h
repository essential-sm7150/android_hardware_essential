//
// Copyright 2016 The Android Open Source Project
// Copyright 2024-2025 NXP
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#pragma once

#include <cstdint>

namespace aidl::android::hardware::bluetooth::impl {

// Encapsulate handling for Bluetooth Addresses:
class BluetoothAddress {
  public:
    static constexpr size_t kBytes = 6;

    static void get_local_address(uint8_t* addr);
};

}  // namespace aidl::android::hardware::bluetooth::impl
