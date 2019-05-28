#pragma once
#ifndef _avl_polycentroid_
#define _avl_polycentroid_

#include "avl_trianglecentroid.h"
#include "avl_trianglearea.h"
#include "avl_polyperimeter.h"

/*
corners
edges
areas
*/

vector
avl_polycentroid(const vector vertices[]; const string mode)
{
    int vertexCount = len(vertices);
    if (vertexCount == 3)  // Triangle
        return avl_trianglecentroid(vertices);
    if (vertexCount < 3)  // Not polygon
        return {0.0, 0.0, 0.0};
    if (mode == 'corners')
        return avg(vertices);
    else if (mode == 'edges')
    {
        vector centroid = {0.0, 0.0, 0.0};
        float perimeter2 = avl_polyperimeter(vertices);//
        vector pos1, pos2;
        for (int i = 0; i < vertexCount; ++i)
        {
            pos1 = vertices[i-1];
            pos2 = vertices[i];
            centroid += (pos1 + pos2) / 2) *
                        (distance2(pos1, pos2) / perimeter2);
        }
        return centroid;
    } else if (mode == 'areas')
    {
        vector centroid = {0.0, 0.0, 0.0};
        float area = avl_polyarea(0, 0);//
        vector pos0 = vertices[0];
        vector pos1, pos2;
        for (int i = 1; i < vertexCount-1; ++i)
        {
            pos1 = vertices[i];
            pos2 = vertices[i+1];
            vector cross = cross(pos0-pos1, pos0-pos2);
            if (dot(cross, {1.0, 0.9, 0.8}) >= 0)
                centroid += avl_trianglecentroid(pos0, pos1, pos2) *
                            (avl_trianglearea(pos0, pos1, pos2) / area);
            else
                centroid -= avl_trianglecentroid(pos0, pos1, pos2) *
                            (avl_trianglearea(pos0, pos1, pos2) / area);
        }
        return abs(centroid);
    } else
    {
        error('AVL Polygon Centroid: Unknown mode ' + mode);
        return {0.0, 0.0, 0.0};
    }
}

#endif
