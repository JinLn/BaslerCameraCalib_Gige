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
	Mat                     frame;//单帧
//	CInstantCamera          cam; //相机实例
    CBaslerGigEInstantCamera cam;
	String_t                devNum;//相机序列号
    CBaslerGigEGrabResultPtr          ptrGrabResult;
	bool                    isOpenAquire;
	bool                    isOpen;
	int                     ImgCount_1;
	int                     ImgCount_2;
	int                     ImgCount_3;
	int                     ImgCount_4;
	void initPylon();//初始化Pylon
	void connectCamera(String_t devNum);//连接相机
	void closeCamera();//关闭相机

	void GrabImage();//获取图片
	void GrabImage1();//获取图片
	void GrabImage2();//获取图片
    void StartAquire();
    void StopAquire();
	void deleteAll();//取消初始化
	void saveImg();//保存图片

};
