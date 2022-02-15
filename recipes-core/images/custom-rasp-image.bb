SUMMARY = "Custom linux image just capable of allowing rasp to boot."

IMAGE_INSTALL = "packagegroup-core-boot ${CORE_IMAGE_EXTRA_INSTALL}"

IMAGE_LINGUAS = " "

LICENSE = "MIT"

inherit core-image
inherit extrausers

IMAGE_OVERHEAD_FACTOR = "1.0"
IMAGE_ROOTFS_SIZE ?= "204800"

EXTRA_USERS_PARAMS = "\
 usermod -P 'test' root \
 "
#include uart_test app 
IMAGE_INSTALL += "test"
IMAGE_INSTALL += "bc"
IMAGE_FEATURES += "ssh-server-dropbear"
