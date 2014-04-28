//  testApp.h
//
//  Created by James Acres on 12-08-15
//  http://www.jamesacres.com
//  http://github.com/jacres
//  @jimmyacres

#pragma once

#include "ofMain.h"
#include "gBuffer.h"
#include "ssaoPass.h"
#include "pointLight.h"
#include "primitives.h"

class ofxDeferredShading {
    
    static const int skMaxPointLightRadius = 4;
    static const int skRadius = 20;
    
    
    enum TEXTURE_UNITS {
        TEX_UNIT_ALBEDO,
        TEX_UNIT_NORMALS_DEPTH,
        TEX_UNIT_SSAO,
        TEX_UNIT_POINTLIGHT_PASS,
        TEX_UNIT_NUM_UNITS
    };
    
public:
    ofxDeferredShading();
    
    void setup(ofCamera* cam);
    void update();
    //  void draw();
    //
    //  void keyPressed(int key);
    //  void keyReleased(int key);
    //  void mouseMoved(int x, int y);
    //  void mouseDragged(int x, int y, int button);
    //  void mousePressed(int x, int y, int button);
    //  void mouseReleased(int x, int y, int button);
    //  void windowResized(int w, int h);
    //  void dragEvent(ofDragInfo dragInfo);
    //  void gotMessage(ofMessage msg);
    
    void setupModel();
    void setupLights();
    void setupScreenQuad();
    void setupPointLightPassFbo();
    void resizeBuffersAndTextures();
    
    void addRandomLight();
    void randomizeLightColors();
    
    void unbindGBufferTextures();
    void bindGBufferTextures();
    
    void drawScreenQuad();
    
    void beginGeometryPass();
    void endGeometryPass();
    
    void pointLightStencilPass();
    void pointLightPass();
    void pointLightPassFBX();
    void deferredRender();
	
    GBuffer m_gBuffer;
    SSAOPass m_ssaoPass;
    
    ofVbo m_quadVbo;
    
    ofShader m_shader;
    ofShader m_pointLightPassShader;
    ofShader m_pointLightStencilShader;
    
    ofImage m_texture;
    
    GLuint m_textureUnits[TEX_UNIT_NUM_UNITS];
    
    ofVbo  m_sphereVbo;
    int    m_numSphereVerts;
    
    ofVbo  m_boxVbo;
    int    m_numBoxVerts;
    
    float   m_angle;
    
    bool    m_bDrawDebug;
    bool    m_bPulseLights;
    
    int     m_windowWidth;
    int     m_windowHeight;
    
    vector<PointLight> m_lights;
	
	//______j
    bool activeAO;
    void addLight(ofVec3f _pos, ofColor _ambient, ofColor _diffuse, ofColor _specular, ofVec3f _attenuation);
    ofCamera* cam;
    
    void begin();
    void end();
    
    
};
