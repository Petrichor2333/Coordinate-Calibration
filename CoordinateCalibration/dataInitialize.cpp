#include "pch.h"
#include "config.h"
#include "dataInitialize.h"

using namespace std;

void CoordinatesinTablebaseInitialize(vector<Eigen::Vector3d> &CoordinatesinTablebase)
{
	Eigen::Vector3d CoordinateinTablebase;
	CoordinateinTablebase << 34, 19.23, 19.5;
	CoordinatesinTablebase.push_back(CoordinateinTablebase);
	CoordinateinTablebase << 27.85, 11.85, 19.4;
	CoordinatesinTablebase.push_back(CoordinateinTablebase);
	CoordinateinTablebase << 33.85, 33.35, 19.3;
	CoordinatesinTablebase.push_back(CoordinateinTablebase);
	CoordinateinTablebase << 26.23, 40.08, 19.2;
	CoordinatesinTablebase.push_back(CoordinateinTablebase);
	CoordinateinTablebase << 19.36, 32.58, 19.2;
	CoordinatesinTablebase.push_back(CoordinateinTablebase);
	CoordinateinTablebase << 16.64, 21.95, 14.13;
	CoordinatesinTablebase.push_back(CoordinateinTablebase);
	CoordinateinTablebase << 22.2, 50.65, 13.9;
	CoordinatesinTablebase.push_back(CoordinateinTablebase);
	CoordinateinTablebase << 41.8, 12.55, 14.5;
	CoordinatesinTablebase.push_back(CoordinateinTablebase);
	CoordinateinTablebase << 41.15, 26.7, 14.4;
	CoordinatesinTablebase.push_back(CoordinateinTablebase);
	CoordinateinTablebase << 47.38, 48.24, 9.29;
	CoordinatesinTablebase.push_back(CoordinateinTablebase);
}

void CoordinatesinRobotbaseInitialize(vector<Eigen::Vector3d> &CoordinatesinRobotbase)
{
	Eigen::Vector3d CoordinateinRobotbase;
	CoordinateinRobotbase << 40, -50, 10;
	CoordinatesinRobotbase.push_back(CoordinateinRobotbase);
	CoordinateinRobotbase << 50, -50, 10;
	CoordinatesinRobotbase.push_back(CoordinateinRobotbase);
	CoordinateinRobotbase << 30, -60, 10;
	CoordinatesinRobotbase.push_back(CoordinateinRobotbase);
	CoordinateinRobotbase << 30, -70, 10;
	CoordinatesinRobotbase.push_back(CoordinateinRobotbase);
	CoordinateinRobotbase << 40, -70, 10;
	CoordinatesinRobotbase.push_back(CoordinateinRobotbase);
	CoordinateinRobotbase << 50, -65, 5;
	CoordinatesinRobotbase.push_back(CoordinateinRobotbase);
	CoordinateinRobotbase << 25, -80, 5;
	CoordinatesinRobotbase.push_back(CoordinateinRobotbase);
	CoordinateinRobotbase << 40, -40, 5;
	CoordinatesinRobotbase.push_back(CoordinateinRobotbase);
	CoordinateinRobotbase << 30, -50, 5;
	CoordinatesinRobotbase.push_back(CoordinateinRobotbase);
	CoordinateinRobotbase << 10, -60, 0;
	CoordinatesinRobotbase.push_back(CoordinateinRobotbase);
}

