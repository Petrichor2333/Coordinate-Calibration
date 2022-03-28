#pragma once
#include "config.h"

using namespace std;

Eigen::Isometry3d FindIsometryofRobotbasetoTablebase(vector<Eigen::Vector3d> CoordinatesinTablebase,
	vector<Eigen::Vector3d> CoordinatesinRobotbase, 
	int NunofPoints);