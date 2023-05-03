#include "planar_quadrotor_visualizer.h"

PlanarQuadrotorVisualizer::PlanarQuadrotorVisualizer(PlanarQuadrotor *quadrotor_ptr): quadrotor_ptr(quadrotor_ptr) {}

/**
 * TODO: Improve visualizetion
 * 1. Transform coordinates from quadrotor frame to image frame so the circle is in the middle of the screen ++
 * 2. Use more shapes to represent quadrotor (e.x. try replicate http://underactuated.mit.edu/acrobot.html#section3 or do something prettier) ++
 * 3. Animate proppelers (extra points)
 */
void PlanarQuadrotorVisualizer::render(std::shared_ptr<SDL_Renderer> &gRenderer) {
    Eigen::VectorXf state = quadrotor_ptr->GetState();
    float q_x, q_y, q_theta;


    /* x, y, theta coordinates */
    q_x = state[0]+640;
    q_y = state[1]+360;
    q_theta = state[2];

    SDL_SetRenderDrawColor(gRenderer.get(), 0xFF, 0x00, 0x00, 0x0FF);
    float x1 = q_x-125*cos(q_theta);
    float x2 = 125*cos(q_theta)+q_x;
    float y1 = q_y-125*sin(q_theta);
    float y2 = 125*sin(q_theta)+q_y;

    float n = 42.5;
    float m = 90;
    float alpha = atan(n/m);
    float l = n/sin(alpha);
    float x3 = q_x - l*cos(alpha+q_theta);
    float y3 = q_y - l*sin(alpha+q_theta);
    float x4 = q_x - 90*cos(q_theta);
    float y4 = q_y - 90*sin(q_theta);

    
    float x31 = q_x + l*cos(-alpha+q_theta);
    float y31 = q_y + l*sin(-alpha+q_theta);
    float x41 = q_x + 90*cos(q_theta);
    float y41 = q_y + 90*sin(q_theta);

    float n1 = 42.5;
    float m1 = 90;
    float alpha1 = atan(n1/m1);
    float l1 = n1/sin(alpha1);
    float x51 = q_x + l1*cos(-alpha1+q_theta);
    float y51 = q_y + l1*sin(-alpha1+q_theta);

    float n2 = 42.5;
    float m2 = 90;
    float alpha2 = atan(n2/m2);
    float l2 = n2/sin(alpha2);
    float x52 = q_x - l2*cos(alpha2+q_theta);
    float y52 = q_y - l2*sin(alpha2+q_theta);


    thickLineColor(gRenderer.get(), x1, y1, x2, y2, 25, 0xFF0000FF);
    thickLineColor(gRenderer.get(), x4, y4, x3, y3, 10, 0xFF0000FF);
    thickLineColor(gRenderer.get(), x41, y41, x31, y31, 10, 0xFF0000FF);
    filledEllipseColor(gRenderer.get(), x51, y51, 80, 7, 0x73a46c00);
    filledEllipseColor(gRenderer.get(), x52, y52, 80, 7, 0x73a46c00);

}