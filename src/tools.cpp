#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
    * Calculate the RMSE here.
  */

	// Lesson 5:6 Evaluation KF Performance

	VectorXd rmse(4);
	rmse << 0,0,0,0;

	// check the validity of the following inputs:
	//  * the estimation vector size should not be zero
	//  * the estimation vector size should equal ground truth vector size
    int estimation_size = estimations.size();
    int ground_truth_size = ground_truth.size();
    int same_size = estimation_size == ground_truth_size;
	if (estimation_size == 0 or same_size == false)
	{
	    return rmse;
	}
	VectorXd acc(4);
	acc << 0,0,0,0;
	//accumulate squared residuals
	for(int i=0; i < estimations.size(); ++i){
        VectorXd diff = estimations[i] - ground_truth[i];
        VectorXd diff_2 = diff.array() * diff.array();
        acc = acc + diff_2;
	}

	//calculate the mean
	VectorXd mean(4);
	mean << 0,0,0,0;
	mean = acc / estimation_size;

	//calculate the squared root
	rmse = mean.array().sqrt();

	return rmse;
}