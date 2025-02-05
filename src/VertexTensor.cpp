#include "VertexTensor.h"

VertexTensor::VertexTensor(){
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    norm_x = 0.0f;
    norm_y = 0.0f;
    norm_z = 0.0f;
}


void VertexTensor::FromFacet(float* vertex1, float* vertex2, float* vertex3, float* normal){
    norm_x = normal[0];
    norm_y = normal[1];
    norm_z = normal[2];

    float* centroid = _centroid(vertex1, vertex2, vertex3);
    x = centroid[0];
    y = centroid[1];
    z = centroid[2];
    delete(centroid);
}

float* VertexTensor::_centroid(float* vertex1, float* vertex2, float* vertex3){
    float* centroid = new float[3];
    centroid[0] = (vertex1[0] + vertex2[0] + vertex3[0]) / 3.0f;
    centroid[1] = (vertex1[1] + vertex2[1] + vertex3[1]) / 3.0f;
    centroid[2] = (vertex1[2] + vertex2[2] + vertex3[2]) / 3.0f;
    return centroid;

}

VertexTensor Rotate()
