#pragma once
#ifndef _avl_copyedgegroup_
#define _avl_copyedgegroup_

#include "avl_setedgegroup.h"

int
avl_copyedgegroup(const int srcGeometry;
                  const int dstGeometry;
                  const int srcPtnum0;
                  const int srcPtnum1;
                  const int dstPtnum0;
                  const int dstPtnum1;
                  const string groupName;
                  const string mode)
{
    int value = inedgegroup(srcGeometry, groupName, srcPtnum0, srcPtnum1);
    return avl_setedgegroup(dstGeometry, groupName, dstPtnum0, dstPtnum1, value, mode);
}

#endif
