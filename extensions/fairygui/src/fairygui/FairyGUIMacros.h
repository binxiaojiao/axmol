#ifndef __FAIRYGUIMACROS_H__
#define __FAIRYGUIMACROS_H__

#include "cocos2d.h"

#define NS_FGUI_BEGIN                     namespace fairygui {
#define NS_FGUI_END                       }
#define USING_NS_FGUI                     using namespace fairygui

#define CALL_LATER_FUNC(__TYPE__,__FUNC__) \
void __selector_##__FUNC__(float dt) \
{\
    ax::Director::getInstance()->getScheduler()->unschedule(AX_SCHEDULE_SELECTOR(__TYPE__::__selector_##__FUNC__), this);\
    __FUNC__(); \
}\
void __FUNC__()

#define CALL_LATER(__TYPE__,__FUNC__,...) \
if (!ax::Director::getInstance()->getScheduler()->isScheduled(AX_SCHEDULE_SELECTOR(__TYPE__::__selector_##__FUNC__), this))\
    ax::Director::getInstance()->getScheduler()->schedule(AX_SCHEDULE_SELECTOR(__TYPE__::__selector_##__FUNC__), this, (__VA_ARGS__+0), false)

#define CALL_LATER_CANCEL(__TYPE__,__FUNC__) \
ax::Director::getInstance()->getScheduler()->unschedule(AX_SCHEDULE_SELECTOR(__TYPE__::__selector_##__FUNC__), this)

#define CALL_PER_FRAME(__TYPE__,__FUNC__) \
if (!ax::Director::getInstance()->getScheduler()->isScheduled(AX_SCHEDULE_SELECTOR(__TYPE__::__FUNC__), this))\
    ax::Director::getInstance()->getScheduler()->schedule(AX_SCHEDULE_SELECTOR(__TYPE__::__FUNC__), this, 0, false)

#define CALL_PER_FRAME_CANCEL(__TYPE__,__FUNC__) \
ax::Director::getInstance()->getScheduler()->unschedule(AX_SCHEDULE_SELECTOR(__TYPE__::__FUNC__), this)

#define UIRoot GRoot::getInstance()

#include "FieldTypes.h"

#endif