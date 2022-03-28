// CoordinateCalibration.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "config.h"
#include "dataInitialize.h"
#include "FindIsometryofRobotbasetoTablebase.h"

using namespace std;



int main()
{
	Eigen::Isometry3d RobotbaseToTable;
	Eigen::Matrix3d rotation_matrix_RobotbaseToTablebase;
	//rotation_matrix_RobotbaseToTable << 1, 2, 3, 1, 0, 0, 1, 0, 0;
	//cout << rotation_matrix_RobotbaseToTable;
	int NunofPoints = 10;

	vector<Eigen::Vector3d> CoordinatesinTablebase;
	vector<Eigen::Vector3d> CoordinatesinRobotbase;

	CoordinatesinTablebaseInitialize(CoordinatesinTablebase);
	CoordinatesinRobotbaseInitialize(CoordinatesinRobotbase);

	Eigen::Isometry3d RobotbaseToTablebase = FindIsometryofRobotbasetoTablebase(CoordinatesinTablebase, CoordinatesinRobotbase, NunofPoints);

	cout.precision(8);

	cout << RobotbaseToTablebase.rotation() << endl;
	cout << RobotbaseToTablebase.translation() << endl;

	cout << endl << endl << "-----test-----" << endl << endl;

	Eigen::Vector3d px(41.8, 12.55, 14.5);
	Eigen::Vector3d py = RobotbaseToTablebase * px;
	cout << py;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
