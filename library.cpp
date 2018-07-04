#include "library.h"

cv::Mat growCuts::segment(std::vector<cv::Point> points, std::vector<int> seeds) {

    cv::Mat label(cv::Size(im.rows, im.cols), CV_8UC1);
    cv::Mat strength(cv::Size(im.rows, im.cols), CV_8UC1);

    //!Set seeds
    for(int i = 0; i<points.size(); i++){
        label.at<int>(points[i].y,points[i].x) = seeds[i];
        strength.at<int>(points[i].y,points[i].x) = 1;
    }

    //!Grow cuts
    for(int iter = 0; iter<100; iter++){

        for(int i = 1; i<(im.rows - 1); i++){
            for(int j = 1; j<(im.cols - 1); j++){

                cv::Vec3i feat = im.at<cv::Vec3i>(i,j);
                float denom = sqrt((feat[0]*feat[0]) + (feat[1]*feat[1]) + (feat[2]*feat[2]));

                for(int k = i-1; k<=(i+1); k++){
                    for(int l = j-1; l<=(j+1); l++){

                        cv::Vec3i new_feat = im.at<cv::Vec3i>(k,l);
                        float diff = sqrt((feat[0] - new_feat[0])^2 + (feat[1] - new_feat[1])^2 + (feat[2] - new_feat[2]));
                        float gVal = 1 - (diff/denom);

                        if((gVal * strength.at<int>(k, l))>strength.at<int>(i,j)){
                            label.at<int>(i,j) = label.at<int>(k,l);
                            strength.at<int>(i,j) = gVal*strength.at<int>(k,l);
                        }

                    }
                }

            }
        }

    }

    return label;

}

void growCuts::setIm(cv::Mat im) {
    this->im = im;
}
