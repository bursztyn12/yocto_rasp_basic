SUMMARY = "Test rasp uart2 recipe"
DESCRIPTION = "Custom recipe to build uart_test.c app"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

#specify where to find source files (relative)
SRC_URI = "file://src"

#specify where to store files 
S = "${WORKDIR}/src"

#pass arguments to linker
TARGET_CC_ARCH += "${LDFLAGS}"

inherit cmake

EXTRA_OECMAKE = ""

#cross-compile src code 
#do_compile(){
# ${CC} -o uart_test uart_test.c
# ${CC} -o test test.c
#}

#create /usr/bin + access  
#do_install(){
# install -d ${D}${bindir}
# install -m 0755 uart_test ${D}${bindir}
# install -m 0755 test ${D}${bindir}
#}
