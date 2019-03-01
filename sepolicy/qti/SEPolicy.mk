#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

BOARD_VENDOR_SEPOLICY_DIRS += \
    hardware/essential/sepolicy/qti/vendor

ifeq (,$(filter device/qcom/sepolicy-legacy-um/legacy/vendor/common device/qcom/sepolicy_vndr/legacy-um/legacy/vendor/common, $(BOARD_VENDOR_SEPOLICY_DIRS)))
BOARD_SEPOLICY_M4DEFS += \
    persist_bluetooth_file=vendor_persist_bluetooth_file
endif
