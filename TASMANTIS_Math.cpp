#include "TASMANTIS_Math.h"


static void TASMANTIS_Math::move(struct pose *p, float dist, bool is_fwd) { /* -------------------------------------------------
* This STATIC FUNCTION ...
* --------------------------------------------------------------------------------------------------------------------------- */

    float theta;


    if (!is_fwd) dist *= -1.0f;

    theta = degreesToRadians(p->angle);


    p->x = ((dist * cos(theta)) + p->x);

    p->y = ((dist * sin(theta)) + p->y);
}


static void TASMANTIS_Math::rotate(struct pose *p, float deg, bool is_ccw) { /* ------------------------------------------------
* This STATIC FUNCTION ...
* --------------------------------------------------------------------------------------------------------------------------- */

    if (!is_ccw) deg *= -1.0f;


    p->angle += deg;

    while (p->angle < 0.0f) p->angle += 360.0f;

    while (p->angle >= 360.0f) p->angle -= 360.0f;
}


static float TASMANTIS_Math::distanceBetween(float x1, float y1, float x2, float y2) { /* --------------------------------------
* This STATIC FUNCTION ...
* --------------------------------------------------------------------------------------------------------------------------- */

    float dx, dy,

          dist;


    dx = (x2 - x1);

    dy = (y2 - y1);

    dist = sqrt((dx * dx) + (dy * dy));     // sqrt(dx^2 + dy^2)


    return dist;
}


static float TASMANTIS_Math::degreesBetween(float angle1, float angle2) { /* ---------------------------------------------------
* This STATIC FUNCTION ...
* --------------------------------------------------------------------------------------------------------------------------- */

    float deg;

    
    if (angle2 > angle1)

        deg = (angle2 - angle1);

    else {

        deg = (angle1 - angle2);

        deg = (360.0f - deg);
    }
    

    return deg;
}


static float TASMANTIS_Math::angleRespectToOrigin(float x, float y) { /* -------------------------------------------------------
* This STATIC FUNCTION ...
* --------------------------------------------------------------------------------------------------------------------------- */

    float theta,

          deg;


    theta = atan2(y, x);

    if (theta < 0.0f) theta += (2.0f * PI);


    deg = radiansToDegrees(theta);


    return deg;
}


static float TASMANTIS_Math::angleRespectToPose(struct pose p, float x2, float y2) { /* ----------------------------------------
* This STATIC FUNCTION ...
* --------------------------------------------------------------------------------------------------------------------------- */

    float angle;


    x2 -= p.x;

    y2 -= p.y;


    angle = angleRespectToOrigin(x2, y2);

    angle -= p.angle;

    while (angle < 0.0f) angle += 360.0f;

    while (angle >= 360.0f) angle -= 360.0f;


    return angle;
}


static float TASMANTIS_Math::shortestRotation(float angle, bool *is_ccw) { /* --------------------------------------------------
* This STATIC FUNCTION ...
* --------------------------------------------------------------------------------------------------------------------------- */

    if (angle > 180.0f) {

        angle = (360.0f - angle);

        *is_ccw = false;

    } else

        *is_ccw = true;


    return angle;
}
