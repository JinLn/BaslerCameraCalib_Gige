#include "CaptureThread.h"
#include <thread>
#include <iostream> 
#include <fstream>
#include <cmath>
#include <iostream>
#include <string>
#include <chrono>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

int kbhit(void)
{
      struct termios oldt, newt;
      int ch;
      int oldf;
      tcgetattr(STDIN_FILENO, &oldt);
      newt = oldt;
      newt.c_lflag &= ~(ICANON | ECHO);
      tcsetattr(STDIN_FILENO, TCSANOW, &newt);
      oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
      fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
      ch = getchar();
      tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
      fcntl(STDIN_FILENO, F_SETFL, oldf);
      if(ch != EOF)
      {
        ungetc(ch, stdin);
        return 1;
      }
      return 0;
}

int main()
{
//    std::string sstr = "./flow/times.txt";
//	std::ofstream fout(sstr);
    CaptureThread cap0("23189967");
    CaptureThread cap1("22805912");
//	CaptureThread cap2("21915643");
	//CaptureThread cap3("40027620");
    cap0.StartAquire();
    cap1.StartAquire();
//	cap2.StartAquire();
	//cap3.StartAquire();
//    auto start = std::chrono::high_resolution_clock::now();
	int temp = 0;
	while (1)
	{
        cap0.GrabImage();
        cap1.GrabImage1();
//        cap2.GrabImage2();
		while (1)
		{
            cap0.GrabImage();
            cap1.GrabImage1();
//			cap2.GrabImage2();
			//cap3.GrabImage();
            if (kbhit())
			{
                int ch = getchar();
				if (ch == 32 || ch == 13)
				{
                    cout << "get img " << temp++<<endl;
					break;
				}
			}
		}
	
        cap0.saveImg();
        cap1.saveImg();
//        cap2.saveImg();
		//cap3.saveImg();
//		auto end = std::chrono::high_resolution_clock::now();
//		std::chrono::duration<float, std::milli> tm = end - start;
//		int S = (int)log10(tm.count() / 1000);
//		if ((tm.count() / 1000) < 1)
//		{
//			fout << setprecision(13) << (tm.count() / 1000) * 10 << "e-01" << endl;
//		}
//		if ((tm.count() / 1000) >= 1)
//		{
//			fout << setprecision(13) << (tm.count() / 1000) / pow(10, S) << "e+0" << S << endl;
//		}
		
        cv::waitKey(10);

	}
	return 0;
}

