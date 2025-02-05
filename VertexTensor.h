#ifndef VERTEX_TENSOR
#define VERTEX_TENSOR

class VertexTensor{
public:
    float x;
    float y;
    float z;
    float norm_x;
    float norm_y;
    float norm_z;

public:
    VertexTensor();
    void FromFacet(float* vertex1, float* vertex2, float* vertex3, float* normal);
    VertexTensor Rotate(float angle_x, float angle_y, float angle_z);

private:
    float* _centroid(float* vertex1, float* vertex2, float* vertex3);
};

#endif
