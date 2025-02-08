#include "Render.h"

Render::Render(
    uint32_t tensorarray_len,
    uint32_t w,
    uint32_t h,
    float disp_z,
    float proj_z,
    float lighting_x,
    float lighting_y,
    float lighting_z)
:   width(w), 
    height(h),
    displacement_z(disp_z),
    projection_z(proj_z)
{
    tensors = TensorArray(tensorarray_len);
    SetLighting(lighting_x, lighting_y, lighting_z);
}




void Render::Interpolate(void){
    // TODO
    TensorArray Projection = tensors.GetProjection(
        displacement_z,
        projection_z);
    
    
}


void Render::SetProjectionZ(float proj_z){
    projection_z = proj_z;
}




void Render::SetDisplacementZ(float disp_z){
    displacement_z = disp_z;
}



void Render::SetLighting(float lx, float ly, float lz){
    float mag = sqrtf(lx + ly + lz);
    lighting_x = lx/mag;
    lighting_y = ly/mag;
    lighting_z = lz/mag;
}




float Render::_NormLuminence(VertexTensor face)
{
    float dot = face.norm_x*lighting_x + face.norm_y*lighting_y + face.norm_z*lighting_z;
    return -1*dot;
}