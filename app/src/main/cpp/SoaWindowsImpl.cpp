//
// Created by eason on 2022/7/15.
//

#include "header/SoaWindowsImpl.h"
#include "header/commonDef.h"

#define LOG_TAG "SoaWindowsImpl"

void SoaWindowsImpl::open(int level) {

}

void SoaWindowsImpl::close(int level) {

}

int SoaWindowsImpl::getWindowStatus(int position) {
    return 0;
}

void SoaWindowsImpl::initSoaWindows() {
    //todo 初始化
    LOGD("initSoaWindows....");

}

SoaWindowsImpl::~SoaWindowsImpl() {
    LOGI("~SoaWindowsImpl");
}
