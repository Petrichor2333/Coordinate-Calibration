#include "pch.h"
#include <Eigen/SVD>
#include "config.h"
#include "FindIsometryofRobotbasetoTablebase.h"


using namespace std;
//using namespace Eigen;
//using namespace Eigen::internal;
//using namespace Eigen::Architecture;

Eigen::Isometry3d FindIsometryofRobotbasetoTablebase(vector<Eigen::Vector3d> CoordinatesinTablebase,
	vector<Eigen::Vector3d> CoordinatesinRobotbase, 
	int NunofPoints)
{
	Eigen::Vector3d centerofCoordinatesinTablebase = Eigen::Vector3d::Zero();
	Eigen::Vector3d centerofCoordinatesinRobotbase = Eigen::Vector3d::Zero();


	for (int i = 0;i < NunofPoints;i++) {
		centerofCoordinatesinTablebase = centerofCoordinatesinTablebase + CoordinatesinTablebase[i];
		centerofCoordinatesinRobotbase = centerofCoordinatesinRobotbase + CoordinatesinRobotbase[i];
	}
	centerofCoordinatesinTablebase = centerofCoordinatesinTablebase / NunofPoints;
	centerofCoordinatesinRobotbase = centerofCoordinatesinRobotbase / NunofPoints;


	vector<Eigen::Vector3d> centralizedCoordinatesinTablebase;
	vector<Eigen::Vector3d> centralizedCoordinatesinRobotbase;
	for (int i = 0;i < NunofPoints;i++) {
		centralizedCoordinatesinTablebase.push_back(CoordinatesinTablebase[i] - centerofCoordinatesinTablebase);
		centralizedCoordinatesinRobotbase.push_back(CoordinatesinRobotbase[i] - centerofCoordinatesinRobotbase);
	}


	Eigen::Matrix3d CovarMarix = Eigen::Matrix3d::Zero();
	for (int i = 0;i < NunofPoints;i++) {
		CovarMarix = CovarMarix + centralizedCoordinatesinRobotbase[i] * centralizedCoordinatesinTablebase[i].transpose();
	}

	cout <<"Covariance Matrix:"<<endl<< CovarMarix;
	cout << endl << endl << "---------------------" << endl << endl;

	Eigen::JacobiSVD<Eigen::MatrixXd> svd(CovarMarix, Eigen::ComputeThinU | Eigen::ComputeThinV);
	Eigen::Matrix3d V = svd.matrixV(), U = svd.matrixU();
	//Eigen::Matrix3d  S = U.inverse() * CovarMarix * (V.transpose()).inverse();

	Eigen::Matrix3d rotation_matrix_RobotbaseToTablebase = U * V.transpose();

	Eigen::Vector3d translate_vector_RobotbaseToTable;
	translate_vector_RobotbaseToTable = centerofCoordinatesinRobotbase - rotation_matrix_RobotbaseToTablebase * centerofCoordinatesinTablebase;

	Eigen::Isometry3d RobotbaseToTablebase = Eigen::Isometry3d::Identity();
	RobotbaseToTablebase.rotate(rotation_matrix_RobotbaseToTablebase);
	RobotbaseToTablebase.pretranslate(translate_vector_RobotbaseToTable);

	return RobotbaseToTablebase;
}