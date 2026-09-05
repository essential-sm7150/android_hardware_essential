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

#include "bluetooth_address.h"

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <utils/Log.h>

using aidl::android::hardware::bluetooth::impl::BluetoothAddress;

namespace {
constexpr char kNvPath[] = "/mnt/vendor/persist/bluetooth/.bt_nv.bin";
constexpr size_t kNvPathSize = 9;
constexpr uint8_t kDefaultAddress[BluetoothAddress::kBytes] = {0xDE, 0xAD, 0xBE, 0xEF, 0x00, 0x11};
}  // namespace

namespace aidl::android::hardware::bluetooth::impl {

void BluetoothAddress::get_local_address(uint8_t* local_addr) {
    int addr_fd = open(kNvPath, O_RDONLY);
    if (addr_fd == -1) {
        ALOGW("%s: %s does not exist (%s), using default address", __func__, kNvPath,
              strerror(errno));
        memcpy(local_addr, kDefaultAddress, sizeof(kDefaultAddress));
        return;
    }

    char address[kNvPathSize] = {0};
    int bytes_read = read(addr_fd, address, kNvPathSize);
    close(addr_fd);

    if (bytes_read == -1) {
        ALOGE("%s: Error reading address from %s: %s, using default address", __func__, kNvPath,
              strerror(errno));
        memcpy(local_addr, kDefaultAddress, sizeof(kDefaultAddress));
        return;
    }

    // Swap into local_addr
    local_addr[0] = address[8];
    local_addr[1] = address[7];
    local_addr[2] = address[6];
    local_addr[3] = address[5];
    local_addr[4] = address[4];
    local_addr[5] = address[3];

    return;
}

}  // namespace aidl::android::hardware::bluetooth::impl
