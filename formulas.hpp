float time_of_the_flight(float v0, float angle);
float max_height(float v0, float angle);
float distance_of_the_flight(float v0, float angle);
float v_diff(float v0, float t);
float x_diff(float x0, float v0, float a, float t);
float horizontal_speed(float v0, float angle);
float vertical_speed(float v0, float angle, float t);

// goes up
float acceleration(float F, float m);
float v_up(float v0, float a, float t);
float h_up(float h0, float a, float t);

// goes down 
