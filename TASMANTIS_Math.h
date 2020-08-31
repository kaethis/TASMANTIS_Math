#ifndef _TASMANTIS_MATH_H_

#define _TASMANTIS_MATH_H_


#include <Arduino.h>

#include "TASMANTIS_Math.h"


class TASMANTIS_Math { /* ------------------------------------------------------------------------------------------------------
* This CLASS ...
* --------------------------------------------------------------------------------------------------------------------------- */

  public:

    struct pose {

        float x = 0.0f,

              y = 0.0f,

              angle = 0.0f;
    };


    static void move(struct pose*, float, bool);

    static void rotate(struct pose*, float, bool);

    static float distanceBetween(float, float, float, float);

    static float distanceBetween(struct pose p, float x2, float y2) { return distanceBetween(p.x, p.y, x2, y2); }

    static float distanceBetween(struct pose p1, struct pose p2)    { return distanceBetween(p1, p2.x, p2.y); }

    static float degreesBetween(float, float);

    static float degreesBetween(struct pose p, float angle2)        { return degreesBetween(p.angle, angle2); }

    static float angleRespectToOrigin(float, float);

    static float angleRespectToOrigin(struct pose p)                { return angleRespectToOrigin(p.x, p.y); }

    static float angleRespectToPose(struct pose, float, float);

    static float angleRespectToPose(struct pose p1, struct pose p2) { return angleRespectToPose(p1, p2.x, p2.y); }

    static float shortestRotation(float, bool*);

    static float degreesToRadians(float deg)                        { return ((deg * PI) / 180.0f); }

    static float radiansToDegrees(float theta)                      { return ((theta * 180.0f) / PI); }

};


#endif /* _TASMANTIS_MATH_H_ */
