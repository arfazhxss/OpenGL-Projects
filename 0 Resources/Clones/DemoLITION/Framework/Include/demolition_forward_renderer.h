/*

        Copyright 2022 Etay Meiri

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once 

#include "ogldev_basic_glfw_camera.h"
#include "ogldev_shadow_mapping_technique.h"
#include "demolition_rendering_subsystem.h"
#include "demolition_forward_lighting.h"
#include "demolition_model.h"
#include "GL/gl_scene.h"


class ForwardRenderer {
 public:

    ForwardRenderer();

    ~ForwardRenderer();

    void InitForwardRenderer(BaseRenderingSubsystem* pRenderingSubsystem);

    void StartShadowPass();

    //
    // Fog
    //
    void SetLinearFog(float FogStart, float FogEnd, const Vector3f& FogColor);

    void SetExpFog(float FogEnd, const Vector3f& FogColor, float FogDensity);

    void SetExpSquaredFog(float FogEnd, const Vector3f& FogColor, float FogDensity);

    void SetLayeredFog(float FogTop, float FogEnd, const Vector3f& FogColor);

    void SetAnimatedFog(float FogEnd, float FogDensity, const Vector3f& FogColor);

    void UpdateAnimatedFogTime(float FogTime);

    void DisableFog();

    void ControlRimLight(bool IsEnabled);

    void ControlCellShading(bool IsEnabled);

    void Render(GLScene* pScene);

   // void RenderAnimation(SkinnedMesh* pMesh, float AnimationTimeSec, int AnimationIndex = 0);

 /*   void RenderAnimationBlended(SkinnedMesh* pMesh,
                                float AnimationTimeSec,
                                int StartAnimIndex,
                                int EndAnimIndex,
                                float BlendFactor);*/

    void RenderToShadowMap(DemolitionModel* pMesh, const SpotLight& SpotLight);
 
private:

    void CreateDefaultCamera();

    void GetWVP(DemolitionModel* pMesh, Matrix4f& WVP);

    void SwitchToLightingTech();

    //void RenderAnimationCommon(SkinnedMesh* pMesh);

    void UpdateMatrices(ForwardLightingTechnique* pBaseTech, DemolitionModel* pMesh);

    BaseRenderingSubsystem* m_pRenderingSubsystem = NULL;
    BasicCamera* m_pCurCamera = NULL;
    BasicCamera* m_pDefaultCamera = NULL;
    ForwardLightingTechnique m_lightingTech;
    //ForwardSkinningTechnique m_skinningTech;
    ShadowMappingTechnique m_shadowMapTech;
};

