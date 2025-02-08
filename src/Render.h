/* Singleton class to package main rendering tasks*/
// Interporlate: Vertex Array -> Float** discrete array
//      ->_NormLuminence
// _NormLuminence(params: vector parallel to light direction)
#ifndef RENDER_H
#define RENDER_H
#include "TensorArray.h"
#include <vector>


class Render{

private:
    uint32_t width;
    uint32_t height;

    /* Projection paramters that will be applied onto the tensor array during interpolation*/
    float displacement_z;
    float projection_z;

    /* Lighting Norm vectors */
    float lighting_x;
    float lighting_y;
    float lighting_z;

    /* holds the final product of interpolation, 2 dimensional vector with luminence values*/
    std::vector<std::vector<float>> Interpolation;

    /* holds the z value of the closest vertexTensor to the user, mirrors Interpolation*/
    std::vector<std::vector<float>> Zbuffer;

public:
    // unaltered tensors of the original object
    TensorArray tensors;



private:
    float _NormLuminence(VertexTensor face);
public:
    /* rendering window size (in number of chars in width and length) */
    Render(
        uint32_t tensorarray_len,
        uint32_t w, uint32_t h,
        float disp_z,
        float proj_z,
        float lighting_x,
        float lighting_y,
        float lighting_z);

    /* Gets projection of current tensors onto plane
    and interpolates it onto the interpolation vector[2] with luminence*/
    void Interpolate(void);


    void SetProjectionZ(float proj_z);
    void SetDisplacementZ(float disp_z);

    // Normalize before setting
    void SetLighting(float x, float y, float z); 
};

#endif