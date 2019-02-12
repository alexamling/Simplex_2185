/*----------------------------------------------
Programmer: Alberto Bobadilla (labigm@gmail.com)
Date: 2017/05
----------------------------------------------*/
#ifndef __MYMESH_H_
#define __MYMESH_H_

#include "Definitions.h"

class MyMesh 
{
public:
	GLuint m_uShaderProgramID = 0; //Shader program
	GLuint m_uVAO = 0; //Vertex Array Object
	GLuint m_uVBO = 0; //Vertex Buffer Object

	std::vector<vector3> m_lVertex;
	std::vector<vector3> m_lVertexPos;
	std::vector<vector3> m_lVertexCol;

	void Init();
	MyMesh();

	~MyMesh();
	void Release();

	void AddVertexPos(vector3 a_v3Pos);
	void AddVertexCol(vector3 a_v3Col);

	void CompleteMesh();

	void CompileOpenGL3X(void);

	void Render(matrix4 a_m4Model, matrix4 a_m4View, matrix4 a_m4Projection);
private:
};

#endif // __MYMESH
