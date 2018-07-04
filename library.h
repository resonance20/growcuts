#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H

#include <opencv/cv.h>

class growCuts{

private:
    cv::Mat im;//!Image that will be segmented

public:

    /**
     * Function to set the image that will be segmented
     * @param im : Image to be segmented
     */
    void setIm(cv::Mat im);

    /**
     * Function to perform GrowCuts segmentation
     * @param points : Coordinates for the seeds
     * @param seeds : Seeds to start the evolution
     * @return : Segmented image
     */
    cv::Mat segment(std::vector<cv::Point> points, std::vector<int> seeds);

};

#endif