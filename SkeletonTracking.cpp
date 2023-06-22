#include"Simple_window.h"
#include <sstream>
#include"Graph.h"
#include"function.h"
#include <Windows.h>
#include <NuiApi.h>
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include "function.h"
#include <stdlib.h>
#include <FL/Fl_Button.H>
#include "Window.h"
#include "Graph.h"
#include "Point.h"
#include <FL/Fl_Text_Display.H>
#include <string>
#include <fstream>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Slider.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
	/*
	#define _WINSOCK_DEPRECATED_NO_WARNINGS   //FU
	#pragma comment(lib,"ws2_32.lib")   //FU
	#include <WinSock2.h>   //FU
	#include <iostream>  //FU
	#include <ws2tcpip.h>  //FU
	*/

#define BG_COLOR   45
#define TICK_COLOR 50
#define CIRC_COLOR 0
	//global variable
	SOCKET newConnection;//Socket to hold the client's connection
						 //upper limb of arm
class vector_1 {
	double x;
	double y;
	double z;

public:
	void set_x(double xval) {
		x = xval;
	}
	void set_y(double yval) {
		y = yval;
	}
	void set_z(double zval) {
		z = zval;
	}
	double get_x(void) {
		return x;
	}
	double get_y(void) {
		return y;
	}
	double get_z(void) {
		return z;
	}
};

//lower limb of arm
class vector_2 {
	double x;
	double y;
	double z;
public:
	void set_x(double xval) {
		x = xval;
	}
	void set_y(double yval) {
		y = yval;
	}
	void set_z(double zval) {
		z = zval;
	}
	double get_x(void) {
		return x;
	}
	double get_y(void) {
		return y;
	}
	double get_z(void) {
		return z;
	}
};

// bool functions
class logic {
	bool a1;
	bool a2;
	bool a3;
	bool a4;
	bool a5;
	bool a6;
public:
	logic::logic() :a1(false), a2(false), a3(false), a4(false), a5(false), a6(false) {}
	bool get_a1(void) { return a1; }
	bool get_a2(void) { return a2; }
	bool get_a3(void) { return a3; }
	bool get_a4(void) { return a4; }
	bool get_a5(void) { return a5; }
	bool get_a6(void) { return a6; }

	void set_a1(bool xa1) { a1 = xa1; }
	void set_a2(bool xa2) { a2 = xa2; }
	void set_a3(bool xa3) { a3 = xa3; }
	void set_a4(bool xa4) { a4 = xa4; }
	void set_a5(bool xa5) { a5 = xa5; }
	void set_a6(bool xa6) { a6 = xa6; }
};

class stage {
	int StageNumber;
public:
	stage::stage() : StageNumber(0) {};
	void set_stage(int x) { StageNumber = x; }
	int get_stage(void) { return StageNumber; }
};

class calibr_data {
	double user_hand_x_left;		//Cali_step=1    left boundary
	double user_hand_x_right;		//Cali_step=0    right boundary
	double user_origin_elbow_x;		//Cali_step=3    origin position
	double user_origin_elbow_y;
	double user_origin_elbow_z;
	double user_origin_wrist_x;
	double user_origin_wrist_y;
	double user_origin_wrist_z;
	double user_origin_shoulder_x;
	double user_origin_shoulder_y;
	double user_origin_shoulder_z;

	double vector3_x;
	double vector3_y;
	double vector3_z;

	double vector4_x;
	double vector4_y;
	double vector4_z;

	double vector5_x;
	double vector5_y;
	double vector5_z;


public:
	calibr_data::calibr_data() :user_hand_x_left(0),
		user_hand_x_right(0), user_origin_elbow_x(0),
		user_origin_elbow_y(0), user_origin_elbow_z(0),
		user_origin_wrist_x(0), user_origin_wrist_y(0),
		user_origin_wrist_z(0), user_origin_shoulder_x(0),
		user_origin_shoulder_y(0), user_origin_shoulder_z(0),
		vector3_x(0), vector3_y(0), vector3_z(0), vector4_x(0),
		vector4_y(0), vector4_z(0), vector5_x(0), vector5_y(0),
		vector5_z(0) {}

	void set_uhxr(double x) { user_hand_x_right = x; }
	void set_uhxl(double x) { user_hand_x_left = x; }
	void set_uoex(double x) { user_origin_elbow_x = x; }
	void set_uoey(double x) { user_origin_elbow_y = x; }
	void set_uoez(double x) { user_origin_elbow_z = x; }
	void set_uowx(double x) { user_origin_wrist_x = x; }
	void set_uowy(double x) { user_origin_wrist_y = x; }
	void set_uowz(double x) { user_origin_wrist_z = x; }
	void set_uosx(double x) { user_origin_shoulder_x = x; }
	void set_uosy(double x) { user_origin_shoulder_y = x; }
	void set_uosz(double x) { user_origin_shoulder_z = x; }

	void set_v3_x(double x) { vector3_x = x; }
	void set_v3_y(double x) { vector3_y = x; }
	void set_v3_z(double x) { vector3_z = x; }

	void set_v4_x(double x) { vector4_x = x; }
	void set_v4_y(double x) { vector4_y = x; }
	void set_v4_z(double x) { vector4_z = x; }

	void set_v5_x(double x) { vector4_x = x; }
	void set_v5_y(double x) { vector4_y = x; }
	void set_v5_z(double x) { vector4_z = x; }

	double get_uhxr(void) { return user_hand_x_right; }
	double get_uhxl(void) { return user_hand_x_left; }
	double get_uoex(void) { return user_origin_elbow_x; }
	double get_uoey(void) { return user_origin_elbow_y; }
	double get_uoez(void) { return user_origin_elbow_z; }
	double get_uowx(void) { return user_origin_wrist_x; }
	double get_uowy(void) { return user_origin_wrist_y; }
	double get_uowz(void) { return user_origin_wrist_z; }
	double get_uosx(void) { return user_origin_shoulder_x; }
	double get_uosy(void) { return user_origin_shoulder_y; }
	double get_uosz(void) { return user_origin_shoulder_z; }

	double get_v3_x(void) { return vector3_x; }
	double get_v3_y(void) { return vector3_y; }
	double get_v3_z(void) { return vector3_z; }
	double get_v4_x(void) { return vector4_x; }
	double get_v4_y(void) { return vector4_y; }
	double get_v4_z(void) { return vector4_z; }
	double get_v5_x(void) { return vector5_x; }
	double get_v5_y(void) { return vector5_y; }
	double get_v5_z(void) { return vector5_z; }

};
class theta_x {
	double thetaX;
	double angleX;
	double arm_extend_length;
public:
	theta_x::theta_x() : thetaX(0), angleX(0), arm_extend_length(0) {}

	void set_thetaX(double x) {
		thetaX = x;
	}
	void set_angleX(double x) {
		angleX = x;
	}
	void set_arm_extend_length(double x) {
		arm_extend_length = x;
	}

	double get_thetaX(void) {
		return thetaX;
	}
	double get_angleX(void) {
		return angleX;
	}
	double get_arm_extend_length(void) {
		return arm_extend_length;
	}
};
bool CalcIK_2D_TwoBoneAnalytic(double& angle1, double& angle2, bool solvePosAngle2, double length1, double length2, double targetX, double targetY) {
	if (length1 < 0 || length2 < 0) return false;
	const double epsilon = 0.0001; // used to prevent division by small numbers
	bool foundValidSolution = true;
	double targetDistSqr = (targetX * targetX + targetY * targetY);
	double sinAngle2;
	double cosAngle2;
	double cosAngle2_denom = 2 * length1 * length2;
	if (cosAngle2_denom > epsilon)
	{
		cosAngle2 = (targetDistSqr - length1 * length1 - length2 * length2) / (cosAngle2_denom);

		// if our result is not in the legal cosine range, we can not find a
		// legal solution for the target
		if ((cosAngle2 < -1.0) || (cosAngle2 > 1.0))
			foundValidSolution = false;

		// clamp our value into range so we can calculate the best
		// solution when there are no valid ones
		cosAngle2 = fmax(-1, fmin(1, cosAngle2));

		// compute a new value for angle2
		angle2 = acos(cosAngle2);

		// adjust for the desired bend direction
		if (!solvePosAngle2)
			angle2 = -angle2;

		// compute the sine of our angle
		sinAngle2 = sin(angle2);
	}
	else
	{
		// At least one of the bones had a zero length. This means our
		// solvable domain is a circle around the origin with a radius
		// equal to the sum of our bone lengths.
		double totalLenSqr = (length1 + length2) * (length1 + length2);
		if (targetDistSqr < (totalLenSqr - epsilon) || targetDistSqr >(totalLenSqr + epsilon))
		{
			foundValidSolution = false;
		}

		// Only the value of angle1 matters at this point. We can just
		// set angle2 to zero. 
		angle2 = 0.0;
		cosAngle2 = 1.0;
		sinAngle2 = 0.0;
	}
	//===
	// Compute the value of angle1 based on the sine and cosine of angle2
	double triAdjacent = length1 + length2 * cosAngle2;
	double triOpposite = length2 * sinAngle2;

	double tanY = targetY * triAdjacent - targetX * triOpposite;
	double tanX = targetX * triAdjacent + targetY * triOpposite;

	// Note that it is safe to call Atan2(0,0) which will happen if targetX and
	// targetY are zero
	angle1 = atan2(tanY, tanX);

	return foundValidSolution;
}


class MyTimer : public Fl_Box {

	void draw() {

		// TELL BASE WIDGET TO DRAW ITS BACKGROUND
		//Fl_Box::draw();
		buff_Hand_X->text(to_string(res_Hand_X).c_str());
		buff_Hand_Y->text(to_string(res_Hand_Y).c_str());
		buff_Hand_Z->text(to_string(res_Hand_Z).c_str());
		buff_Elbow_X->text(to_string(res_Elbow_X).c_str());
		buff_Elbow_Y->text(to_string(res_Elbow_Y).c_str());
		buff_Elbow_Z->text(to_string(res_Elbow_Z).c_str());
		buff_Shoulder_X->text(to_string(res_Shoulder_X).c_str());
		buff_Shoulder_Y->text(to_string(res_Shoulder_Y).c_str());
		buff_Shoulder_Z->text(to_string(res_Shoulder_Z).c_str());
		buff_thetaX->text(to_string(thetaX.get_angleX()).c_str());
		buff_theta1->text(to_string(res_theta1_angle).c_str());
		buff_theta2->text(to_string(res_theta2_angle).c_str());

		buff_diff_thetaX->text(to_string(diff_thetaX).c_str());
		buff_diff_theta1->text(to_string(diff_theta1_angle).c_str());
		buff_diff_theta2->text(to_string(diff_theta2_angle).c_str());
		buff_SystemStutas->text(Sys_status.c_str());
		buff_user_arm->text(to_string(thetaX.get_arm_extend_length()).c_str());

		buff2->text(to_string(Count_sec / 20).c_str());
		buff3->text(to_string(Count_min).c_str());
		buff4->text(to_string(Count_hr).c_str());

	}

	static void Timer_CB(void* userdata) {
		MyTimer* o = (MyTimer*)userdata;
		if (o->flag) {
			NUI_SKELETON_FRAME ourframe;

			if ((o->Count_sec) == 1199)
			{
				o->Count_sec = 0;
				if (o->Count_min == 59)
				{
					o->Count_min = 0;
					o->Count_hr++;
				}
				else {
					o->Count_min++;
				}

			}                                  //3
			else {                              //4
				o->Count_sec++;
				o->Count_sec_cali++;


			}
			NuiSkeletonGetNextFrame(0, &ourframe);
			for (int i = 0; i < 6; i++) {
				if (ourframe.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED)
				{

					if (o->stage.get_stage() == 0) {
						o->Shoulder_center = ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_SHOULDER_CENTER].z;
						//cout << o->Shoulder_center << endl;

						if (o->Shoulder_center <= 2.0 && o->Shoulder_center >= 1.5)
						{
							o->logic.set_a1(true);
							//cout << "1" << endl;

						}
						else {
							o->logic.set_a1(false);
							o->stage.set_stage(0);
						}

						if (o->logic.get_a1() == true) {
							//cout << "3" << endl;
							switch (o->Cali_step) {
							case 0:
								if (o->logic.get_a2() == false) {
									o->temp_count = o->Count_sec_cali;
									o->logic.set_a2(true);
									//cout << "4" << endl;
								}
								else {
									if (o->Count_sec_cali == (o->temp_count + 100))
									{
										o->user.set_uhxr(ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_WRIST_RIGHT].x);
										o->Cali_step = 1;
										//cout << "5" << endl;
									}
									else if (o->Count_sec_cali < (o->temp_count + 100)) {
										o->Sys_status = "Stay where you are. Raise your arm straight and stretch to the left side";
									}
									else {// cout << "6" << endl; 
									}
								}
								break;
							case 1:
								if (o->logic.get_a3() == false) {
									o->temp_count = o->Count_sec_cali;
									o->logic.set_a3(true);
									//cout << "3" << endl;
								}
								else {
									if (o->Count_sec_cali == (o->temp_count + 100))
									{
										o->user.set_uhxl(ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_WRIST_RIGHT].x);
										o->Cali_step = 2;
									}
									else if (o->Count_sec_cali < (o->temp_count + 100)) {
										o->Sys_status = "CALIBRATION STAGE:(3) RAISE ARM AND STRETCH TO YOUR Right SIDE";
										o->thetaX.set_arm_extend_length(sqrt(pow((ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_WRIST_RIGHT].x - ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_SHOULDER_RIGHT].x), 2) + pow((ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_WRIST_RIGHT].y - ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_SHOULDER_RIGHT].y), 2) + pow((ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_WRIST_RIGHT].z - ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_SHOULDER_RIGHT].z), 2)));

									}
									else {}
								}
								break;
							case 2:
								if (o->logic.get_a4() == false) {
									o->temp_count = o->Count_sec_cali;
									o->logic.set_a4(true);
								}
								else {
									if (o->Count_sec_cali == (o->temp_count + 100))
									{

										o->user.set_uoex(ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_RIGHT].x);
										o->user.set_uoey(ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_RIGHT].y);
										o->user.set_uoez(ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_RIGHT].z);
										o->user.set_uowx(ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_WRIST_RIGHT].x);
										o->user.set_uowy(ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_WRIST_RIGHT].y);
										o->user.set_uowz(ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_WRIST_RIGHT].z);
										o->user.set_uosx(ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_SHOULDER_RIGHT].x);
										o->user.set_uosy(ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_SHOULDER_RIGHT].y);
										o->user.set_uosz(ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_SHOULDER_RIGHT].z);
										/* test version 1: doesn't work well*/
										o->user.set_v3_x(ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_RIGHT].x - ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_SHOULDER_RIGHT].x);
										o->user.set_v3_y(ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_RIGHT].y - ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_SHOULDER_RIGHT].y);
										o->user.set_v3_z(ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_RIGHT].z - ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_SHOULDER_RIGHT].z);




										o->stage.set_stage(1);
									}
									else if (o->Count_sec_cali < (o->temp_count + 100)) {
										o->Sys_status = "Success. Now, please lay down your arm natrually to the side of your body";
									}
									else {}
								}
								break;
							default:
								break;
							}
						}
						else {
							if (o->Shoulder_center > 2) {
								o->Sys_status = "Please move foward a little bit to get into sampling range";

							}
							else if (o->Shoulder_center < 1.5) {
								o->Sys_status = "Please back up a little bit to get into sampling range";

							}
						}
					}
					if (o->stage.get_stage() == 1) {
						o->Sys_status = "Enter mimicking stage";

						o->res_Hand_X = ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_WRIST_RIGHT].x;
						o->res_Hand_Y = ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_WRIST_RIGHT].y;
						o->res_Hand_Z = ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_WRIST_RIGHT].z;

						o->res_Elbow_X = ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_RIGHT].x;
						o->res_Elbow_Y = ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_RIGHT].y;
						o->res_Elbow_Z = ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_RIGHT].z;

						o->res_Shoulder_X = ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_SHOULDER_RIGHT].x;
						o->res_Shoulder_Y = ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_SHOULDER_RIGHT].y;
						o->res_Shoulder_Z = ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_SHOULDER_RIGHT].z;

						o->res_XZ_length = sqrt(pow((o->res_Hand_X - o->res_Shoulder_X), 2) + pow((o->res_Hand_Z - o->res_Shoulder_Z), 2));
						o->res_Hand_Y_diff = o->res_Shoulder_Y - o->res_Hand_Y;
						o->user.set_v4_x(ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_WRIST_RIGHT].x - ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_RIGHT].x);
						o->user.set_v4_y(ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_WRIST_RIGHT].y - ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_RIGHT].y);
						o->user.set_v4_z(ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_WRIST_RIGHT].z - ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ELBOW_RIGHT].z);

						o->user.set_v5_x(ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].x - ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_WRIST_RIGHT].x);
						o->user.set_v5_y(ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].y - ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_WRIST_RIGHT].y);
						o->user.set_v5_z(ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].z - ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_WRIST_RIGHT].z);

						o->Length1 = o->res_XZ_length * (0.33 / o->thetaX.get_arm_extend_length());
						o->Length2 = o->res_Hand_Y_diff * (0.33 / o->thetaX.get_arm_extend_length());







						/**************************************************************************************************************************************/
						//servo motor 1 (tested)

						// plan 1 (Using Origin User Coordinates.)
						/*
						double diff = o->res_Hand_X - o->user.get_uosx();
						double diff1 = abs(o->res_Hand_X - o->user.get_uosx());
						double diff2 = abs(o->res_Hand_Y - o->user.get_uosy());
						*/

						//plan 2 (Use user's instant Coordinates)
						double diff = o->res_Hand_X - o->res_Shoulder_X;
						double diff1 = abs(o->res_Hand_X - o->res_Shoulder_X);
						double diff2 = abs(o->res_Hand_Z - o->res_Shoulder_Z);


						if (diff1 < 0.1 && diff2 < 0.1) {
							o->thetaX.set_thetaX(1.57);
							o->thetaX.set_angleX(90);
						}
						else {
							if (diff > 0) {
								//plan 1:
								/*o->thetaX.set_thetaX(atan(abs(o->res_Hand_Y - o->user.get_uosy()) / abs(o->res_Hand_X - o->user.get_uosx())));
								o->thetaX.set_angleX(atan(abs(o->res_Hand_Y - o->user.get_uosy()) / abs(o->res_Hand_X - o->user.get_uosx()))*57.29);
								*/

								//plan 2:
								//o->thetaX.set_thetaX(atan(abs(o->res_Hand_Z - o->res_Shoulder_Z) / abs(o->res_Hand_X - o->res_Shoulder_X)));
								//o->thetaX.set_angleX(atan(abs(o->res_Hand_Z - o->res_Shoulder_Z) / abs(o->res_Hand_X - o->res_Shoulder_X))*57.29);

								//plan 3:
								o->thetaX.set_thetaX(atan(abs(o->res_Hand_Z - o->res_Elbow_Z) / abs(o->res_Hand_X - o->res_Elbow_X)));
								o->thetaX.set_angleX(atan(abs(o->res_Hand_Z - o->res_Elbow_Z) / abs(o->res_Hand_X - o->res_Elbow_X)) * 57.29);
							}
							else if (diff = 0) {
								o->thetaX.set_thetaX(1.57);
								o->thetaX.set_angleX(90);

							}
							else
							{
								// plan 1:
								/*
								o->thetaX.set_thetaX(1.57 + atan(abs(o->res_Hand_Y - o->user.get_uosy()) / abs(o->res_Hand_X - o->user.get_uosx())));
								o->thetaX.set_angleX(90 + atan(abs(o->res_Hand_Y - o->user.get_uosy()) / abs(o->res_Hand_X - o->user.get_uosx()))*57.29);
								*/
								// plan 2:
								//o->thetaX.set_thetaX(1.57 + atan(abs(o->res_Hand_Z - o->res_Shoulder_Z) / abs(o->res_Hand_X - o->res_Shoulder_X)));
								//o->thetaX.set_angleX(180 - atan(abs(o->res_Hand_Z - o->res_Shoulder_Z) / abs(o->res_Hand_X - o->res_Shoulder_X))*57.29);
								// plan 3:
								o->thetaX.set_thetaX(1.57 + atan(abs(o->res_Hand_Z - o->res_Elbow_Z) / abs(o->res_Hand_X - o->res_Elbow_X)));
								o->thetaX.set_angleX(180 - atan(abs(o->res_Hand_Z - o->res_Elbow_Z) / abs(o->res_Hand_X - o->res_Elbow_X)) * 57.29);
							}

						}

						/**********************************************************************************************************************************/
						//servo motor 2  (tested)

						CalcIK_2D_TwoBoneAnalytic(o->res_theta1, o->res_theta2, 1, 0.145, 0.185, o->Length1, -(o->Length2));

						//o->v1.set_x(o->res_Elbow_X - o->res_Shoulder_X);       
						//o->v1.set_y(o->res_Elbow_Y - o->res_Shoulder_Y);
						//o->v1.set_z(o->res_Elbow_Z - o->res_Shoulder_Z);

						//o->v2.set_x(o->res_Hand_X - o->res_Elbow_X);
						//o->v2.set_y(o->res_Hand_Y - o->res_Elbow_Y);
						//o->v2.set_z(o->res_Hand_Z - o->res_Elbow_Z);


						o->res_theta3 = 57.2 * acos(((o->user.get_v5_x() * o->user.get_v4_x()) + (o->user.get_v5_y() * o->user.get_v4_y()) + (o->user.get_v5_z() * o->user.get_v4_z())) / (sqrt(pow(o->user.get_v5_x(), 2) + pow(o->user.get_v5_y(), 2) + pow(o->user.get_v5_y(), 2)) * sqrt(pow(o->user.get_v4_x(), 2) + pow(o->user.get_v4_y(), 2) + pow(o->user.get_v4_z(), 2))));


						//o->res_theta1_angle = o->res_theta1*57.2*(-15)/8+255;
						o->res_theta1_angle = o->res_theta1 * 57.2;
						o->res_theta2_angle = o->res_theta2 * 57.2;

						cout << o->res_theta1_angle;
						cout << o->res_theta2_angle;
						int a = o->res_theta1_angle;
						int b = o->res_theta2_angle;
						//						cout << a;
						//						cout << b;
						double values[] = { o->res_theta1_angle };
						stringstream ss;
						ss << values << endl;
						string newString = ss.str();
						char tab2[256];
						strcpy_s(tab2, newString.c_str());
						cout << newString;
						//						char MOTD[256] = { tab2 };
						send(newConnection, tab2, sizeof(tab2), NULL);


						//ofstream datafile("Data_Collector.txt", std::fstream::app);
						/*ofstream datafile;
						datafile.open("Data_Collector.txt", ofstream::out | ofstream::app);
						if (!datafile)error("can't open data file");
						datafile << o->thetaX.get_angleX() << ":" << o->res_theta1_angle << ":"<<o->res_theta2_angle<< "\n";
						datafile.close();
						*/
						//double res_theta1_angle = (o->res_theta1*57.2);

						/*******************************************************************************************************************************/
						//servo motor 3

						//1.

						//2.
						//double res_theta2_mid = 57.2*acos(((o->v1.get_x()*o->user.get_v4_x()) + (o->v1.get_y()*o->user.get_v4_y()) + (o->v1.get_z()*o->user.get_v4_z())) / (sqrt(pow(o->v1.get_x(), 2) + pow(o->v1.get_y(), 2) + pow(o->v1.get_y(), 2))*sqrt(pow(o->user.get_v4_x(), 2) + pow(o->user.get_v4_y(), 2) + pow(o->user.get_v4_z(), 2))));
						// o->res_theta2 = res_theta2_mid*2 - 90;
						//3.
						/*
double arm_extend_length=(sqrt(pow((o->res_Elbow_X - o->res_Shoulder_X), 2) + pow((o->res_Elbow_Y - o->res_Shoulder_Y), 2) + pow((o->res_Elbow_Z - o->res_Shoulder_Z), 2)));
																	 o->res_theta2 =57.2*acos(sqrt(pow((o->res_Elbow_X - o->res_Shoulder_X), 2) + pow((o->res_Elbow_Y - o->res_Shoulder_Y), 2)) / (arm_extend_length));
																	 double diff3 = o->res_Elbow_Z - o->user.get_uoez();
																	 */
																	 // o->res_theta2 = 57.2*acos(((o->v1.get_x()*o->user.get_v4_x()) + (o->v1.get_y()*o->user.get_v4_y()) + (o->v1.get_z()*o->user.get_v4_z())) / (sqrt(pow(o->v1.get_x(), 2) + pow(o->v1.get_y(), 2) + pow(o->v1.get_y(), 2))*sqrt(pow(o->user.get_v4_x(), 2) + pow(o->user.get_v4_y(), 2) + pow(o->user.get_v4_z(), 2))));

																	 /******************************************************************************************************************************/
						o->temp_1 = o->array_angleX[0];
						o->temp_2 = o->array_theta2_angle[0];
						o->temp_3 = o->array_theta1_angle[0];

						if (o->array_index != 2) {
							o->array_angleX_diff[o->array_index] = o->thetaX.get_angleX();
							o->array_theta1_angle_diff[o->array_index] = o->res_theta1_angle;
							o->array_theta2_angle_diff[o->array_index] = o->res_theta2_angle;

							o->array_index++;
						}
						else {
							o->array_angleX_diff[o->array_index] = o->thetaX.get_angleX();
							o->array_theta1_angle_diff[o->array_index] = o->res_theta1_angle;
							o->array_theta2_angle_diff[o->array_index] = o->res_theta2_angle;

							o->array_angleX[0] = (o->array_angleX_diff[0] + o->array_angleX_diff[1] + o->array_angleX_diff[2]) / 3;
							o->array_theta1_angle[0] = (o->array_theta1_angle_diff[0] + o->array_theta1_angle_diff[1] + o->array_theta1_angle_diff[2]) / 3;
							o->array_theta2_angle[0] = (o->array_theta2_angle_diff[0] + o->array_theta2_angle_diff[1] + o->array_theta2_angle_diff[2]) / 3;

							o->diff_thetaX = (o->array_angleX[0] - o->temp_1);
							o->diff_theta1_angle = (o->array_theta1_angle[0] - o->temp_3);
							o->diff_theta2_angle = (o->array_theta2_angle[0] - o->temp_2);

							o->array_index = 0;
						}
						//o->diff_thetaX = (o->array_angleX[0] - o->temp_1);


						/*cout << o->diff_Hand_X << endl;*/
						/*cout << o->v1.get_x() << endl;*/
						//cout << o->res_theta1<< endl;

						//o->diff_theta1_angle = (o->array_theta1_angle[0] - o->temp_3);



						//cout << o->diff_Hand_X << endl;
						//cout << o->diff_Elbow_Y << endl;
						//cout << o->res_theta1 << endl;
						//cout << o->thetaX.get_angleX()<<endl;
						//cout << o->thetaX.get_arm_extend_length() << endl;
						//cout << o->res_theta1_angle << endl;
						//cout << o->diff_thetaX << endl;
						//cout << o->diff_theta1_angle << endl;

					}
				}
				/*if(o->logic.get_a6()==true){
				cout << "sucess" << endl;
				}
				*/
			}
			o->redraw();
		}
		if (o->GetFrequency() == 20)//user didn't input frequency, use default frequency instead, 1/0.05
			Fl::repeat_timeout(0.05, Timer_CB, userdata);
		else //user input freqeuncty
			Fl::repeat_timeout(1 / o->GetFrequency(), Timer_CB, userdata);
	}


	static void start_cb(Fl_Widget* o, void* userdata) {
		MyTimer* v = (MyTimer*)userdata;
		//v->result = 214;

		v->flag = true;
		////////////////////////////////////
		v->start->hide();
		v->End->show();
		///////////////////////////////////
	}

	static void End_cb(Fl_Widget* o, void* userdata) {
		MyTimer* v = (MyTimer*)userdata;
		//v->result = 214;
		v->flag = false;
		cout << ((v->Count_sec_cali) / 20) << "seconds" << endl;
		//cout << ""
		/////////////////////////////////////
		v->get_window()->hide();
		Graph_lib::Window* new_win = new Graph_lib::Window(Point(200, 100), 800, 600, "");
		new_win->begin();
		//////////////add widget
		//Fl_Text_Display* text = new Fl_Text_Display(70, 50, 100, 30, "Hand X Coordinate");
		//Graph_lib::Text* text = new Graph_lib::Text(Graph_lib::Point(70, 50)
		//////////////end widget
		new_win->end();
		new_win->show();
		while (new_win->shown())Fl::wait();
		/////////////////////////////////////
	}

	int frequency; //private member

public:
	double array_angleX[1];
	double array_theta2_angle[1];
	double array_theta1_angle[1];
	double array_angleX_diff[3];
	double array_theta1_angle_diff[3];
	double array_theta2_angle_diff[3];
	double Shoulder_center = 0;
	vector_1 v1;
	vector_2 v2;
	logic logic;
	stage stage;
	calibr_data user;
	string Sys_status = " Please Press 'start' button when you are ready";

	theta_x thetaX;
	int Cali_step = 0;


	double temp_1 = 0;
	double temp_2 = 0;
	double temp_3 = 0;

	double cali_hand_x;


	double diff_thetaX = 0;
	double diff_theta1_angle = 0;
	double diff_theta2_angle = 0;
	//double diff_theta1 = 0;
	//double theta1;
	bool flag = false;
	double Count_sec = 0;
	double Count_min = 0;
	double Count_hr = 0;

	double Count_sec_cali = 0;
	double temp_count = 0;

	int array_index = 0;
	Fl_Button* start = NULL;// button 
	Fl_Button* End = NULL;

	double res_Hand_X = 0;
	double res_Hand_Y = 0;
	double res_Hand_Z = 0;
	double res_Elbow_X = 0;
	double res_Elbow_Y = 0;
	double res_Elbow_Z = 0;
	double res_Shoulder_X = 0;
	double res_Shoulder_Y = 0;
	double res_Shoulder_Z = 0;

	double res_XZ_length = 0;
	double res_Hand_Y_diff = 0;

	double Length1 = 0;
	double Length2 = 0;

	double cali_Hand_X = 0;

	double res_theta1 = 0;
	double res_theta1_angle = 0;
	double res_theta2 = 0;
	double res_theta2_angle = 0;
	double res_theta3 = 0;;




	Fl_Text_Buffer* buff_Hand_X;
	Fl_Text_Buffer* buff_Hand_Y;
	Fl_Text_Buffer* buff_Hand_Z;
	Fl_Text_Buffer* buff_Elbow_X;
	Fl_Text_Buffer* buff_Elbow_Y;
	Fl_Text_Buffer* buff_Elbow_Z;
	Fl_Text_Buffer* buff_Shoulder_X;
	Fl_Text_Buffer* buff_Shoulder_Y;
	Fl_Text_Buffer* buff_Shoulder_Z;
	Fl_Text_Buffer* buff_thetaX;
	Fl_Text_Buffer* buff_theta1;
	Fl_Text_Buffer* buff_theta2;

	Fl_Text_Buffer* buff_diff_thetaX;
	Fl_Text_Buffer* buff_diff_theta1;
	Fl_Text_Buffer* buff_diff_theta2;
	//Fl_Text_Buffer *buff_diff_Elbow_Y;

	Fl_Text_Buffer* buff_SystemStutas;
	Fl_Text_Buffer* buff_user_arm;


	Fl_Text_Buffer* buff2;
	Fl_Text_Buffer* buff3;
	Fl_Text_Buffer* buff4;

	Fl_Text_Display* disp_Hand_X;
	Fl_Text_Display* disp_Hand_Y;
	Fl_Text_Display* disp_Hand_Z;
	Fl_Text_Display* disp_Elbow_X;
	Fl_Text_Display* disp_Elbow_Y;
	Fl_Text_Display* disp_Elbow_Z;
	Fl_Text_Display* disp_Shoulder_X;
	Fl_Text_Display* disp_Shoulder_Y;
	Fl_Text_Display* disp_Shoulder_Z;
	Fl_Text_Display* disp_thetaX;
	Fl_Text_Display* disp_theta1;
	Fl_Text_Display* disp_theta2;


	Fl_Text_Display* disp_diff_thetaX;
	Fl_Text_Display* disp_diff_theta1;
	Fl_Text_Display* disp_diff_theta2;
	//Fl_Text_Display *disp_diff_Elbow_Y;

	Fl_Text_Display* disp_SystemStutas;
	Fl_Text_Display* disp_user_arm;


	Fl_Text_Display* disp2;
	Fl_Text_Display* disp3;
	Fl_Text_Display* disp4;

	////////////////////////////////////////////
	Graph_lib::Window* m_win = NULL;
	Graph_lib::Window* get_window() {
		return m_win;
	}

	int GetFrequency() {
		return frequency;
	}
	////////////////////////////////////////////
	// CONSTRUCTOR
	MyTimer(int X, int Y, int W, int H, Graph_lib::Window* win, int _frequency = 20, const char* L = 0) : Fl_Box(X, Y, W, H, L) {
		///////////////////////////////////
		m_win = win;
		frequency = _frequency; //user input frequency
								///////////////////////////////////
								//	box(FL_FLAT_BOX);
		color(BG_COLOR);
		Fl::add_timeout(0.1, Timer_CB, (void*)this);
		start = new Fl_Button(x() + 240, y() + h() + 10, 100, 50, "start"); start->callback(start_cb, (void*)this);//define button
		End = new Fl_Button(x() + 240, y() + h() + 10, 100, 50, "End"); End->callback(End_cb, (void*)this);
		////////////////////////////////////
		End->hide();
		////////////////////////////////////
		buff_Hand_X = new Fl_Text_Buffer();
		buff_Hand_Y = new Fl_Text_Buffer();
		buff_Hand_Z = new Fl_Text_Buffer();

		buff_Elbow_X = new Fl_Text_Buffer();
		buff_Elbow_Y = new Fl_Text_Buffer();
		buff_Elbow_Z = new Fl_Text_Buffer();

		buff_Shoulder_X = new Fl_Text_Buffer();
		buff_Shoulder_Y = new Fl_Text_Buffer();
		buff_Shoulder_Z = new Fl_Text_Buffer();

		buff_thetaX = new Fl_Text_Buffer();
		buff_theta1 = new Fl_Text_Buffer();
		buff_theta2 = new Fl_Text_Buffer();

		buff_diff_thetaX = new Fl_Text_Buffer();
		buff_diff_theta1 = new Fl_Text_Buffer();
		buff_diff_theta2 = new Fl_Text_Buffer();
		//buff_diff_Elbow_Y = new Fl_Text_Buffer();

		buff_SystemStutas = new Fl_Text_Buffer();
		buff_user_arm = new Fl_Text_Buffer();

		buff2 = new Fl_Text_Buffer();
		buff3 = new Fl_Text_Buffer();
		buff4 = new Fl_Text_Buffer();


		disp_Hand_X = new Fl_Text_Display(x() + 70, y() + h() - 250, 100, 30, "Hand X Coordinate");
		disp_Hand_Y = new Fl_Text_Display(x() + 70, y() + h() - 200, 100, 30, "Hand Y Coordinate");
		disp_Hand_Z = new Fl_Text_Display(x() + 70, y() + h() - 150, 100, 30, "Hand Z Coordinate");
		disp_Elbow_X = new Fl_Text_Display(x() + 240, y() + h() - 250, 100, 30, "Elbow X Coordinate");
		disp_Elbow_Y = new Fl_Text_Display(x() + 240, y() + h() - 200, 100, 30, "Elbow Y Coordinate");
		disp_Elbow_Z = new Fl_Text_Display(x() + 240, y() + h() - 150, 100, 30, "Elbow Z Coordinate");
		disp_Shoulder_X = new Fl_Text_Display(x() + 410, y() + h() - 250, 100, 30, "Shoulder X Coordinate");
		disp_Shoulder_Y = new Fl_Text_Display(x() + 410, y() + h() - 200, 100, 30, "Shoulder Y Coordinate");
		disp_Shoulder_Z = new Fl_Text_Display(x() + 410, y() + h() - 150, 100, 30, "Shoulder Z Coordinate");

		disp_thetaX = new Fl_Text_Display(x() + 70, y() + h() - 100, 100, 30, "Theta 1");
		disp_theta1 = new Fl_Text_Display(x() + 240, y() + h() - 100, 100, 30, "Theta 2");
		disp_theta2 = new Fl_Text_Display(x() + 410, y() + h() - 100, 100, 30, "Theta 3");



		disp_diff_thetaX = new Fl_Text_Display(x() + 70, y() + h() - 300, 100, 30, "Theta 1 Diff");
		//disp_diff_theta1 = new Fl_Text_Display(x() + 200, y() + h() - 300, 80, 30, "Theta 1 Difference");
		disp_diff_theta1 = new Fl_Text_Display(x() + 240, y() + h() - 300, 100, 30, "Theta 2 Diff");
		disp_diff_theta2 = new Fl_Text_Display(x() + 410, y() + h() - 300, 100, 30, "Theta 3 Diff");

		disp_SystemStutas = new Fl_Text_Display(x() + 20, y() + h() - 380, 550, 50, "System Message");
		disp_user_arm = new Fl_Text_Display(x() - 50, y() + h() - 450, 100, 30, "Current User Arm Length");

		disp2 = new Fl_Text_Display(x() + 170, y() + h() - 30, 80, 30, "Second");
		disp3 = new Fl_Text_Display(x() + 250, y() + h() - 30, 80, 30, "Minite");
		disp4 = new Fl_Text_Display(x() + 330, y() + h() - 30, 80, 30, "Hour");

		disp_Hand_X->buffer(buff_Hand_X);
		disp_Hand_Y->buffer(buff_Hand_Y);
		disp_Hand_Z->buffer(buff_Hand_Z);
		disp_Elbow_X->buffer(buff_Elbow_X);
		disp_Elbow_Y->buffer(buff_Elbow_Y);
		disp_Elbow_Z->buffer(buff_Elbow_Z);
		disp_Shoulder_X->buffer(buff_Shoulder_X);
		disp_Shoulder_Y->buffer(buff_Shoulder_Y);
		disp_Shoulder_Z->buffer(buff_Shoulder_Z);
		disp_thetaX->buffer(buff_thetaX);
		disp_theta1->buffer(buff_theta1);
		disp_theta2->buffer(buff_theta2);
		disp_diff_thetaX->buffer(buff_diff_thetaX);
		disp_diff_theta1->buffer(buff_diff_theta1);
		disp_diff_theta2->buffer(buff_diff_theta2);

		//disp_diff_Elbow_Y->buffer(buff_diff_Elbow_Y);

		disp_SystemStutas->buffer(buff_SystemStutas);
		disp_user_arm->buffer(buff_user_arm);

		disp2->buffer(buff2);
		disp3->buffer(buff3);
		disp4->buffer(buff4);

		buff_Hand_X->text(to_string(res_Hand_X).c_str());
		buff_Hand_Y->text(to_string(res_Hand_Y).c_str());
		buff_Hand_Z->text(to_string(res_Hand_Z).c_str());
		buff_Elbow_X->text(to_string(res_Elbow_X).c_str());
		buff_Elbow_Y->text(to_string(res_Elbow_Y).c_str());
		buff_Elbow_Z->text(to_string(res_Elbow_Z).c_str());
		buff_Shoulder_X->text(to_string(res_Shoulder_X).c_str());
		buff_Shoulder_Y->text(to_string(res_Shoulder_Y).c_str());
		buff_Shoulder_Z->text(to_string(res_Shoulder_Z).c_str());
		buff_thetaX->text(to_string(thetaX.get_angleX()).c_str());
		buff_theta1->text(to_string(res_theta1_angle).c_str());
		buff_theta2->text(to_string(res_theta2_angle).c_str());

		buff_diff_thetaX->text(to_string(diff_thetaX).c_str());
		buff_diff_theta1->text(to_string(diff_theta1_angle).c_str());
		buff_diff_theta1->text(to_string(diff_theta2_angle).c_str());
		//buff_diff_Elbow_Y->text(to_string(diff_Elbow_Y).c_str());
		buff_SystemStutas->text(Sys_status.c_str());
		buff_user_arm->text(to_string(thetaX.get_arm_extend_length()).c_str());

		buff2->text(to_string(Count_sec).c_str());
		buff3->text(to_string(Count_min).c_str());
		buff4->text(to_string(Count_hr).c_str());

	}
};
class SliderInput : public Fl_Group {
	Fl_Int_Input* input;
	Fl_Slider* slider;

	// CALLBACK HANDLERS
	//    These 'attach' the input and slider's values together.
	//
	void Slider_CB2() {
		static int recurse = 0;
		if (recurse) {
			return;
		}
		else {
			recurse = 1;
			char s[80];
			sprintf_s(s, "%d", (int)(slider->value() + .5));
			// fprintf(stderr, "SPRINTF(%d) -> '%s'\n", (int)(slider->value()+.5), s);
			input->value(s);          // pass slider's value to input
			recurse = 0;
		}
	}

	static void Slider_CB(Fl_Widget* w, void* data) {
		((SliderInput*)data)->Slider_CB2();
	}

	void Input_CB2() {
		static int recurse = 0;
		if (recurse) {
			return;
		}
		else {
			recurse = 1;
			int val = 0;
			if (sscanf_s(input->value(), "%d", &val) != 1) {
				val = 0;
			}
			// fprintf(stderr, "SCANF('%s') -> %d\n", input->value(), val);
			slider->value(val);         // pass input's value to slider
			recurse = 0;
		}
	}
	static void Input_CB(Fl_Widget* w, void* data) {
		((SliderInput*)data)->Input_CB2();
	}

public:
	// CTOR
	SliderInput(int x, int y, int w, int h, const char* l = 0) : Fl_Group(x, y, w, h, l) {
		int in_w = 40;
		input = new Fl_Int_Input(x, y, in_w, h);
		input->callback(Input_CB, (void*)this);
		input->when(FL_WHEN_ENTER_KEY | FL_WHEN_NOT_CHANGED);

		slider = new Fl_Slider(x + in_w, y, w - in_w, h);
		slider->type(1);
		slider->callback(Slider_CB, (void*)this);

		bounds(1, 10);     // some usable default
		value(5);          // some usable default
		end();             // close the group
	}

	// MINIMAL ACCESSORS --  Add your own as needed
	int  value() const { return((int)(slider->value() + 0.5)); }
	void value(int val) { slider->value(val); Slider_CB2(); }
	void minumum(int val) { slider->minimum(val); }
	int  minumum() const { return((int)slider->minimum()); }
	void maximum(int val) { slider->maximum(val); }
	int  maximum() const { return((int)slider->maximum()); }
	void bounds(int low, int high) { slider->bounds(low, high); }

	/////////////qq li////////////
	int GetFrequency() {
		return (int)((int)(slider->value() + .5));
	}

};

void button_cb(Fl_Widget*, void* usrdata);
void button_cb(Fl_Widget* obj, void* usrdata)

{
	Graph_lib::Window* o = (Graph_lib::Window*)usrdata;
	o->hide();
}
// MAIN
int main() {

	//Fu added code
	//Winsock Startup...
	WSAData wsaData;
	int iResult;
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("shit failed:%d\n", iResult);
		return 1;
	}

	SOCKADDR_IN addr;//address that we will bind our socket to
	int addrlen = sizeof(addr); //length of the address
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");//broadcast locally
	addr.sin_port = htons(1111);//Port
	addr.sin_family = AF_INET;//IPv4 Socket

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);///Creating a new socket
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));//Bind address to the socket
	listen(sListen, SOMAXCONN);//place socket in state for incomming connection

							   //SOCKET newConnection;//Socket to hold the client's connection
	newConnection = accept(sListen, (SOCKADDR*)&addr, &addrlen); //Accept a new connection
	if (newConnection == 0) //If connection fails
	{
		std::cout << "failed to accept the client's connection." << std::endl;
	}
	else
	{
		std::cout << "Client is  Connected!" << std::endl;
		char MOTD[256] = "Welcome! This is the Message of the Day.";
		send(newConnection, MOTD, sizeof(MOTD), NULL);//Send MOTD buffer
	}

	int frequency;  // stores user-input frequency
	Graph_lib::Window win_start(Point(200, 100), 800, 600, "");
	win_start.begin();
	Fl_Button* confirm = new Fl_Button(200, 200, 100, 50, "Confirm");
	confirm->callback((Fl_Callback*)button_cb, (void*)&win_start);
	SliderInput* si = new SliderInput(20, 20, 200, 50, "Sampling Frequency");
	si->bounds(1, 30);       // set min/max for slider
	si->value(20);

	while (win_start.shown())Fl::wait();
	win_start.end();
	frequency = si->GetFrequency();
	//cout << "testing...." << frequency << endl;
	Graph_lib::Window win(Point(200, 100), 800, 600, "");
	win.begin();
	MyTimer tim(100, 100, 600, 400, &win, frequency);
	NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON);
	win.end();
	win.show();
	while (win.shown())Fl::wait();

}
