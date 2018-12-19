//
// Created by elkanatovey on 12/19/18.
//

#ifndef EX3CPP_MATRIX3D_H
#define EX3CPP_MATRIX3D_H


#include "Vector3D.h"

class Matrix3D {

    Matrix3D();

    explicit Matrix3D(double diagonal);

    Matrix3D(double a, double b, double c, double d, double e, double f, double g, double h,
            double i);

    explicit Matrix3D(double params[9]);

    explicit Matrix3D(double params[3][3]);

    Matrix3D(Vector3D a, Vector3D b, Vector3D c);

    Matrix3D(Matrix3D& toCopy);

    Matrix3D& operator-= (const Matrix3D& other);

    Matrix3D& operator+= (const Matrix3D& other);

    Matrix3D operator*= (const Matrix3D& other) const;

    Matrix3D operator-(const Matrix3D& other);

};


#endif //EX3CPP_MATRIX3D_H
