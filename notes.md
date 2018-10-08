# P7: Unscented Kalman Filter Project

The project includes the following files

* CMakeLists.txt
* src folder
* notes.txt (this file)

## Description

The project was addressed the following way:

* Move code from the quizzes while veryfing it compiles.
* Initialization, add new definitions in the ukf.h file
* Review the [QA session](https://www.youtube.com/watch?v=gej_-2hxgck).
* Check if all matrixes and vectors are correctly initialized.
* Check division by zero.
* Try several initialization values.

I got several errors and troubleshooting took time; the ones that took more time are:

* Initialization issues
* Prevent division by zero or very low values
* Angle normalization (Every operation involving angles should be normalized), I applied the tips from [here](https://discussions.udacity.com/t/ukf-getting-stuck-on-second-dataset/240080/23) and separated it to another function.
* Parameters using ideas from [here](https://discussions.udacity.com/t/nis-for-radar-incorrect-over-estimated-certainty-for-system/352967) and [here](https://discussions.udacity.com/t/numerical-instability-of-the-implementation/230449).

## Test

Follow these steps for validation:

1. Compile the program as detailed on the repository.
2. Run `./UnscentedKF`
3. select the dataset and test it.
4. When switching between datasets, please rerun the program.

## Results

Dataset 1

RMSE
x:0.0670
y:0.0814
VX:0.3278
VY:0.1864

Dataset 2

RMSE
x:0.0662
y:0.0608
VX:0.1915
VY:0.1950
