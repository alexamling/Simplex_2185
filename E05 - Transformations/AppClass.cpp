#include "AppClass.h"
void Application::InitVariables(void)
{
	m_pMesh = new MyMesh();
	m_pMesh->GenerateCube(1.0f, C_BLACK);

	for (int x = 0; x < 11; x++) {
		for (int y = 0; y < 8; y++) {
			if (placementValues[y][x] == 1) {
				positions.push_back(vector3(5.5f - x, 4.0f - y, 0.0f));
			}
		}
	}
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	matrix4 m4View = m_pCameraMngr->GetViewMatrix();
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();

	for (int i = 0; i < positions.size(); i++)
	{
		//matrix4 m4Scale = glm::scale(IDENTITY_M4, vector3(2.0f,2.0f,2.0f));
		static float value;
		matrix4 m4Translate = glm::translate(IDENTITY_M4, positions[i] + vector3( 5 * sinf(value), cos(value * 2.5f), 0));
		value += 0.001f;

		matrix4 m4Model = m4Translate;
		//matrix4 m4Model = m4Scale * m4Translate;

		m_pMesh->Render(m4Projection, m4View, m4Model);	
	}
	
	
	// draw a skybox
	m_pMeshMngr->AddSkyboxToRenderList();
	m_pMeshMngr->AddGridToRenderList();

	//render list call
	m_uRenderCallCount = m_pMeshMngr->Render();

	//clear the render list
	m_pMeshMngr->ClearRenderList();
	
	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	SafeDelete(m_pMesh);

	//release GUI
	ShutdownGUI();
}