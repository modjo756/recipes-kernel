# Adapted from linux-imx.inc, copyright (C) 2012, 2013 O.S. Systems Software LTDA
# Released under the MIT license (see COPYING.MIT for the terms)

SUMMARY = "Linux kernel for UDOO boards"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

require recipes-kernel/linux/linux-imx.inc

DEPENDS += "lzop-native bc-native"

# Put a local version until we have a true SRCREV to point to
SCMVERSION ?= "y"

# UDOOboard branch - based on 4.1.15-2.0.x-udoo from Freescale git
SRCBRANCH = "4.1.15_2.x-udoo"
LOCALVERSION = "_2.0.x-udoo"

# Allow override of UDOOBOARD_GITHUB_MIRROR to make use of
# local repository easier
UDOOBOARD_GITHUB_MIRROR ?= "git://github.com/fmntf/linux_kernel.git"

# SRC_URI for udoo boards kernel
SRC_URI = "${UDOOBOARD_GITHUB_MIRROR};branch=${SRCBRANCH} \
           file://0003-avoid-endless-loop.patch \
           file://0005-add-support-for-gcc6.patch \
           file://defconfig \
"
SRC_URI_append_udooqdl = "file://0010-default-bpp-to-16.patch \
"

SRC_URI_append_udooneo = " \
    file://0003-fix-build-acc-gyro.patch \
    ${@base_conditional("ENABLE_CAN_BUS", "1", "file://0001-Enable-FlexCAN-interfaces-for-UDOO-Neo.patch", "", d)} \
    ${@base_conditional("ENABLE_SPI_BUS", "1", "file://0020-udooneo-enable-ecspi2.patch", "", d)} \
"
