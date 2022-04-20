#include "CaptureThread.h"
#include<iostream>
#include<sstream>
//#include <pylon/PylonGUI.h>
#include <pylon/PylonIncludes.h>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include <pylon/PylonIncludes.h>
#include <pylon/gige/PylonGigEIncludes.h>
#include <pylon/gige/BaslerGigEInstantCamera.h>
#include <pylon/gige/_BaslerGigECameraParams.h>
#include <pylon/Platform.h>
#include <pylon/PylonUtility.h>
#include <pylon/_ImageFormatConverterParams.h>
#include <pylon/gige/BaslerGigEInstantCamera.h>
#include <pylon/gige/BaslerGigEInstantCameraArray.h>

using namespace std;
using namespace cv;
using namespace Pylon;
using namespace Basler_GigECameraParams;
using namespace Basler_GigECamera;
int exposureautotimemax = 70000;
int exposureautotimemin = 200;
bool exposureuto = true;
int exposuretime = 100000;

CaptureThread::CaptureThread(String_t devNum) :
	devNum(devNum)
{
	ImgCount_1 = 0;
	ImgCount_2 = 0;
	ImgCount_3 = 0;
	ImgCount_4 = 0;
}

CaptureThread::~CaptureThread()
{
	deleteAll();
}



void CaptureThread::saveImg()
{
    if (devNum == "23189967")
	{
		/*�ɼ�ͼƬ*/
		//std::stringstream stemp3;
		//stemp3 << ImgCount_3;
		//string scount3 = stemp3.str();
		//string str3 = "flow//3//cam3_";
		//str3 += scount3;
		//str3 += ".jpg";
		//cvtColor(frame, frame, CV_BGR2RGB);
		//imwrite(str3, frame);
		//ImgCount_3++;

		char cam[150] = {};
        sprintf(cam, "../flow/0/%06d.jpg", ImgCount_3);
		//cv::cvtColor(frame, frame, CV_BGR2RGB);
		//cv::imshow("frame", frame);
		cv::imwrite(cam, frame);
		ImgCount_3++;

		/*�ɼ��궨ԭͼƬ��δѹ��*/
		//std::stringstream stemp3;
		//stemp3 << ImgCount_3;
		//string scount3 = stemp3.str();
		//string str3 = "flow//2//cam2_";
		//str3 += scount3;
		//str3 += ".png";
		//CImagePersistence::Save(ImageFileFormat_Png, str3.c_str(), ptrGrabResult);
		//ImgCount_3++;
	}
    if (devNum == "22805912")
	{
		/*�ɼ�ͼƬ*/
		//std::stringstream stemp3;
		//stemp3 << ImgCount_3;
		//string scount3 = stemp3.str();
		//string str3 = "flow//3//cam3_";
		//str3 += scount3;
		//str3 += ".jpg";
		//cvtColor(frame, frame, CV_BGR2RGB);
		//imwrite(str3, frame);
		//ImgCount_3++;

		char cam[150] = {};
        sprintf(cam, "../flow/2/%06d.jpg", ImgCount_3);
		//cv::cvtColor(frame, frame, CV_BGR2RGB);
		//cv::imshow("frame", frame);
		cv::imwrite(cam, frame);
		ImgCount_3++;

		/*�ɼ��궨ԭͼƬ��δѹ��*/
		//std::stringstream stemp3;
		//stemp3 << ImgCount_3;
		//string scount3 = stemp3.str();
		//string str3 = "flow//2//cam2_";
		//str3 += scount3;
		//str3 += ".png";
		//CImagePersistence::Save(ImageFileFormat_Png, str3.c_str(), ptrGrabResult);
		//ImgCount_3++;
	}
	if (devNum == "21915643")
	{
		/*�ɼ�ͼƬ*/
		//std::stringstream stemp3;
		//stemp3 << ImgCount_3;
		//string scount3 = stemp3.str();
		//string str3 = "flow//3//cam3_";
		//str3 += scount3;
		//str3 += ".jpg";
		//cvtColor(frame, frame, CV_BGR2RGB);
		//imwrite(str3, frame);
		//ImgCount_3++;

		char cam[150] = {};
        sprintf(cam, "../flow/1/%06d.jpg", ImgCount_3);
		//cv::cvtColor(frame, frame, CV_BGR2RGB);
		//cv::imshow("frame", frame);
		cv::imwrite(cam, frame);
		ImgCount_3++;

		/*�ɼ��궨ԭͼƬ��δѹ��*/
		//std::stringstream stemp3;
		//stemp3 << ImgCount_3;
		//string scount3 = stemp3.str();
		//string str3 = "flow//2//cam2_";
		//str3 += scount3;
		//str3 += ".png";
		//CImagePersistence::Save(ImageFileFormat_Png, str3.c_str(), ptrGrabResult);
		//ImgCount_3++;
	}
	if (devNum == "40027620")
	{
		/*�ɼ�ͼƬ*/
		//std::stringstream stemp3;
		//stemp3 << ImgCount_3;
		//string scount3 = stemp3.str();
		//string str3 = "flow//3//cam3_";
		//str3 += scount3;
		//str3 += ".jpg";
		//cvtColor(frame, frame, CV_BGR2RGB);
		//imwrite(str3, frame);
		//ImgCount_3++;

		char cam[150] = {};
        sprintf(cam, "../flow/3/%06d.jpg", ImgCount_3);
		//cv:: cvtColor(frame, frame, CV_BGR2RGB);
		//cv::imshow("frame", frame);
		cv::imwrite(cam, frame);
		ImgCount_3++;

		/*�ɼ��궨ԭͼƬ��δѹ��*/
		//std::stringstream stemp3;
		//stemp3 << ImgCount_3;
		//string scount3 = stemp3.str();
		//string str3 = "flow//2//cam2_";
		//str3 += scount3;
		//str3 += ".png";
		//CImagePersistence::Save(ImageFileFormat_Png, str3.c_str(), ptrGrabResult);
		//ImgCount_3++;
	}
}

void CaptureThread::initPylon()
{
	//qDebug() << "Init Pylon ...";
	PylonInitialize();//pylon�����ʼ��                   
	connectCamera(devNum);//�����
}

void  CaptureThread::deleteAll()//�ر�������������
{
	if (isOpenAquire)
	{
		StopAquire();
	}
	closeCamera();
	PylonTerminate();
	//qDebug() << "Pylon cameras : Close ...";
}


void  CaptureThread::connectCamera(String_t devNum)//�ر�������������
{
	try {
		CTlFactory& tlFactory = CTlFactory::GetInstance();//���ô��乤��
//		CDeviceInfo dev;
        CBaslerGigEDeviceInfo dev;//����豸
		dev.SetSerialNumber(devNum);                      //����ָ��������к�
		//����
        dev.SetDeviceClass(BaslerGigEDeviceClass);
		//usb
//		dev.SetDeviceClass(BaslerUsbDeviceClass);//�����������
		cam.Attach(tlFactory.CreateDevice(dev));          //��cam��
		cam.Open();
        if (!exposureuto) {
            cam.ExposureAuto.SetValue(ExposureAuto_Off);
            cam.ExposureTimeAbs.SetValue(exposuretime);
        }
        else {
            cam.ExposureAuto.SetValue(ExposureAuto_Continuous);
            cam.AutoExposureTimeAbsLowerLimit.SetValue(exposureautotimemin);
            cam.AutoExposureTimeAbsUpperLimit.SetValue(exposureautotimemax);
        }
		isOpen = true;
	}
	catch (GenICam::GenericException &e) {
		//Debug() << "OpenCamera Error" << String(e.GetDescription());
		isOpen = false;
	}

}

void CaptureThread::closeCamera()
{
	if (!isOpen) {
		//qDebug() << "cameras are closed ... ";
	}
	try {
		if (cam.IsOpen()) {
			cam.DetachDevice();
			cam.Close();
		}
	}
	catch (GenICam::GenericException &e) {
		//qDebug() << "CloseCamera Error:" << QString(e.GetDescription());
	}
}

void CaptureThread::StartAquire()
{
	initPylon();
	isOpenAquire = true;
	try {
		cam.StartGrabbing(GrabStrategy_LatestImageOnly);
	}
	catch (GenICam::GenericException &e) {
        //qDebug() << "StartAcquire Error:" << QString(e.GetDescription());
	}
}

void CaptureThread::StopAquire()
{
	isOpenAquire = false;
	//qDebug() << "StopAcquire ...";
	try {
		if (cam.IsGrabbing()) {
			cam.StopGrabbing();
		}
	}
	catch (GenICam::GenericException &e) {
		//qDebug() << "StopAcquire Error:" << QString(e.GetDescription());
	}
}



void  CaptureThread::GrabImage()
{
	CImageFormatConverter   formatConverter;//��ʽת��
	CPylonImage             pylonImage;//���ԭ��ͼ���ʽ
	//CGrabResultPtr          ptrGrabResult;//���ץȡ���ָ��
	//ȷ��������ظ�ʽ
	formatConverter.OutputPixelFormat = PixelType_BGR8packed;

	try {

		if (cam.IsGrabbing())
		{
			cam.RetrieveResult(5000, ptrGrabResult, TimeoutHandling_ThrowException);
			//qDebug() << "ptrGrabResult GrabSucceeded";

			if (ptrGrabResult->GrabSucceeded())
			{
				formatConverter.Convert(pylonImage, ptrGrabResult);
				//frame = cv::Mat(ptrGrabResult->GetHeight(), ptrGrabResult->GetWidth(), CV_8UC3, (uint8_t *)pylonImage.GetBuffer());
				cv::Mat src = cv::Mat(ptrGrabResult->GetHeight(), ptrGrabResult->GetWidth(), CV_8UC3, (uint8_t*)pylonImage.GetBuffer());
				cv::Mat dst;
				resize(src, dst, Size(src.cols*0.47, src.rows*0.47));
//				cvtColor(dst, dst,COLOR_BGR2GRAY);

				//dst = src(Rect(0, 300, src.cols, 500));
				Mat Leftimg;
				dst.copyTo(Leftimg);
				resize(Leftimg, Leftimg, Size(Leftimg.cols/2, Leftimg.rows/2));
				cv::imshow("Left", Leftimg);
//                cout<<"left"<<endl;
                cv::waitKey(1);
				//Leftimg.release();
				frame = dst.clone();
				//cv::cvtColor(frame, frame, CV_BGR2RGB);//Qt��֧�ֵ���RGBͼ��, OpenCV��֧�ֵ���BGR
				//qDebug() << "Convert Complete ...";
			}

		}

	}
	catch (GenICam::GenericException& e) {

		//qDebug() << "GrabImage Error:" << QString(e.GetDescription());

	}
	catch (...) {
		//qDebug() << "Error";

	}


}

void  CaptureThread::GrabImage1()
{
    CImageFormatConverter   formatConverter;//��ʽת��
    CPylonImage             pylonImage;//���ԭ��ͼ���ʽ
	//CGrabResultPtr          ptrGrabResult;//���ץȡ���ָ��
	//ȷ��������ظ�ʽ
    formatConverter.OutputPixelFormat = PixelType_BGR8packed;

	try {

        if (cam.IsGrabbing())
		{
            cam.RetrieveResult(5000, ptrGrabResult, TimeoutHandling_ThrowException);
			//qDebug() << "ptrGrabResult GrabSucceeded";

			if (ptrGrabResult->GrabSucceeded())
            {
                formatConverter.Convert(pylonImage, ptrGrabResult);
				//frame = cv::Mat(ptrGrabResult->GetHeight(), ptrGrabResult->GetWidth(), CV_8UC3, (uint8_t *)pylonImage.GetBuffer());
                cv::Mat src = cv::Mat(ptrGrabResult->GetHeight(), ptrGrabResult->GetWidth(), CV_8UC3, (uint8_t*)pylonImage.GetBuffer());
				cv::Mat dst;
				resize(src, dst, Size(src.cols*0.47, src.rows*0.47));
//				cvtColor(dst, dst, COLOR_BGR2GRAY);
				//dst = src(Rect(0, 300, src.cols, 500));
				Mat Rightimg;
				dst.copyTo(Rightimg);
				resize(Rightimg, Rightimg, Size(Rightimg.cols / 2, Rightimg.rows / 2));
                cv::imshow("Right", Rightimg);
//                cout<<"right"<<endl;
                cv::waitKey(1);
				frame = dst.clone();
				//cv::cvtColor(frame, frame, CV_BGR2RGB);//Qt��֧�ֵ���RGBͼ��, OpenCV��֧�ֵ���BGR
				//qDebug() << "Convert Complete ...";
			}

		}

	}
	catch (GenICam::GenericException& e) {

		//qDebug() << "GrabImage Error:" << QString(e.GetDescription());

	}
	catch (...) {
		//qDebug() << "Error";

	}


}
void  CaptureThread::GrabImage2()
{
    CPylonImage             pylonImage;
    CGrabResultPtr          ptrGrabResult;
    CImageFormatConverter   formatConverter;


    //ȷ��������ظ�ʽ
    formatConverter.OutputPixelFormat = PixelType_BGR8packed;

    try {

        if (cam.IsGrabbing())
        {
            cam.RetrieveResult(5000, ptrGrabResult, TimeoutHandling_ThrowException);
            //qDebug() << "ptrGrabResult GrabSucceeded";

            if (ptrGrabResult->GrabSucceeded())
            {
                formatConverter.Convert(pylonImage, ptrGrabResult);
                //frame = cv::Mat(ptrGrabResult->GetHeight(), ptrGrabResult->GetWidth(), CV_8UC3, (uint8_t *)pylonImage.GetBuffer());
                cv::Mat src = cv::Mat(ptrGrabResult->GetHeight(), ptrGrabResult->GetWidth(), CV_8UC3, (uint8_t*)pylonImage.GetBuffer());
                cv::Mat dst;
                resize(src, dst, Size(src.cols*0.47, src.rows*0.47));
//				cvtColor(dst, dst, COLOR_BGR2GRAY);
                //dst = src(Rect(0, 300, src.cols, 500));
                Mat Centerimg;
                dst.copyTo(Centerimg);
                resize(Centerimg, Centerimg, Size(Centerimg.cols / 2, Centerimg.rows / 2));
                cv::imshow("Centre", Centerimg);
                cv::waitKey(1);
                frame = dst.clone();
                //cv::cvtColor(frame, frame, CV_BGR2RGB);//Qt��֧�ֵ���RGBͼ��, OpenCV��֧�ֵ���BGR
                //qDebug() << "Convert Complete ...";
            }

        }

    }
    catch (GenICam::GenericException& e) {

        //qDebug() << "GrabImage Error:" << QString(e.GetDescription());

    }
    catch (...) {
        //qDebug() << "Error";

    }


}
