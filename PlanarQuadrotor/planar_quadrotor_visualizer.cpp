#include "planar_quadrotor_visualizer.h"

PlanarQuadrotorVisualizer::PlanarQuadrotorVisualizer(PlanarQuadrotor *quadrotor_ptr): quadrotor_ptr(quadrotor_ptr) {}

/**
 * TODO: Improve visualizetion
 * 1. Transform coordinates from quadrotor frame to image frame so the circle is in the middle of the screen
 * 2. Use more shapes to represent quadrotor (e.x. try replicate http://underactuated.mit.edu/acrobot.html#section3 or do something prettier)
 * 3. Animate proppelers (extra points)
 */
void PlanarQuadrotorVisualizer::render(std::shared_ptr<SDL_Renderer> &gRenderer) {
    Eigen::VectorXf state = quadrotor_ptr->GetState();
    float q_x, q_y, q_theta;


    /* x, y, theta coordinates */
    q_x = state[0]+600;
    q_y = state[1]+360;
    q_theta = state[2];

    SDL_SetRenderDrawColor(gRenderer.get(), 0x00, 0x00, 0x00, 0x00);
    float x = q_x + 250;
    float y = q_y + 25;
    boxColor(gRenderer.get(), q_x, q_y, x, y, 0x73a46c00);
    boxColor(gRenderer.get(), q_x+30, q_y-40, q_x+40, q_y, 0x73a46c00);
    boxColor(gRenderer.get(), x-40, q_y-40, x-30, q_y, 0x73a46c00);
    filledEllipseColor(gRenderer.get(), q_x-10, q_y-40, 40, 7, 0x73a46c00);
    filledEllipseColor(gRenderer.get(), q_x+80, q_y-40, 40, 7, 0x73a46c00);
    filledEllipseColor(gRenderer.get(), x-80, q_y-40, 40, 7, 0x73a46c00);
    filledEllipseColor(gRenderer.get(), x+10, q_y-40, 40, 7, 0x73a46c00);
}