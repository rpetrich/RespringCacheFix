TWEAK_NAME = RespringCacheFix
RespringCacheFix_FILES = Tweak.c
RespringCacheFix_ARCHS = armv7

OPTFLAG = -Os
TARGET_IPHONEOS_DEPLOYMENT_VERSION = 6.0

TARGET_LD = xcrun -sdk iphoneos clang
TARGET_CC = xcrun -sdk iphoneos clang

include framework/makefiles/common.mk
include framework/makefiles/tweak.mk
