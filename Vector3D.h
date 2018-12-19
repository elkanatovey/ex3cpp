//Vector3d.h

#ifndef VECTOR3D_H
#define VECTOR3D_H
/**
 * A 3d vector class
 * This class represents a vector in 3d space
 */
class Vector3D
{
public:
    /**
     * default constructor
     * generates the 0 vector
     * @see
     */
    Vector3D();

    Vector3D(int, int, int);

    Vector3D(int[3]);

    Vector3D(Vector3D);

private:
    double _x; /**< the x coordinate of the vector. */
    double _y; /**< the y coordinate of the vector. */
    double _z; /**< the z coordinate of the vector. */

};

#endif