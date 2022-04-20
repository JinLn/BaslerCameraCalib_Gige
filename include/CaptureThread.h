#pragma once
#include<pylon/PylonIncludes.h>

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include <pylon/PylonIncludes.h>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include <pylon/PylonIncludes.h>
#include <pylon/gige/PylonGigEIncludes.h>
#include <pylon/gige/BaslerGigEInstantCamera.h>
#include <pylon/gige/_BaslerGigECameraParams.h>

using namespace std;
using namespace cv;
using namespace Pylon;
using namespace Basler_GigECameraParams;
class CaptureThread
{
	

public:

	CaptureThread(String_t devNum);
	~CaptureThread();
	Mat                     frame;//��֡
//	CInstantCamera          cam; //���ʵ��
    CBaslerGigEInstantCamera cam;
	String_t                devNum;//������к�
    CBaslerGigEGrabResultPtr          ptrGrabResult;
	bool                    isOpenAquire;
	bool                    isOpen;
	int                     ImgCount_1;
	int                     ImgCount_2;
	int                     ImgCount_3;
	int                     ImgCount_4;
	void initPylon();//��ʼ��Pylon
	void connectCamera(String_t devNum);//�������
	void closeCamera();//�ر����

	void GrabImage();//��ȡͼƬ
	void GrabImage1();//��ȡͼƬ
	void GrabImage2();//��ȡͼƬ
    void StartAquire();
    void StopAquire();
	void deleteAll();//ȡ����ʼ��
	void saveImg();//����ͼƬ

};
