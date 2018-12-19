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

    Vector3D(double , double, double);

    explicit Vector3D(double[3]);

    /**
     * add another vector to the current
     * @param other other vector
     * @return the current vector
     */
    Vector3D& operator+= (const Vector3D& other);

    /**
    * minus another vector to the current
    * @param other other vector
    * @return the current vector
    */
    Vector3D& operator-= (const Vector3D& other);

    /**
    * add a scalar to the current
    * @param the scalar
    * @return the current vector
    */
    Vector3D& operator+ (const double & other);


    /**
    * minus a scalar to the current
    * @param the scalar
    * @return the current vector
    */
    Vector3D& operator- (const double & other);

    /**
    * add two vectors togethor
    * @param the scalar
    * @return the current vector
    */
    Vector3D operator+ (const Vector3D& other);

    /**
    * minus the received vector and add new
    * @param the scalar
    * @return the current vector
    */
    Vector3D operator- (const Vector3D& other);
//
//    /**
//     * minus another vector to the current
//     * @param other other vector
//     * @return
//     */
//
//    Vector3D& operator<<(const Vector3D& other);
//
//    Vector3D& operator>>(const Vector3D& other);
//
//    Vector3D& operator/(const Vector3D& other);


private:
    double _x; /**< the x coordinate of the vector. */
    double _y; /**< the y coordinate of the vector. */
    double _z; /**< the z coordinate of the vector. */

};

#endif