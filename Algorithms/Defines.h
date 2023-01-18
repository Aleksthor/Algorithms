#pragma once
// Defines
#define TimePoint std::chrono::steady_clock::time_point
#define SteadyClock_Now std::chrono::steady_clock::now()

#define GetNanoSeconds(x,y) std::chrono::duration_cast<std::chrono::nanoseconds>(x - y).count()
#define GetMicroSeconds(x,y) std::chrono::duration_cast<std::chrono::microseconds>(x - y).count()
#define GetMilliSeconds(x,y) std::chrono::duration_cast<std::chrono::milliseconds>(x - y).count()
#define GetSeconds(x,y) std::chrono::duration_cast<std::chrono::seconds>(x - y).count()

#define startprint std::cout <<
#define endprint << std::endl

#define TimeFunction(x,y,z) TimePoint x = SteadyClock_Now;	y; TimePoint z =  SteadyClock_Now;





#define Key_A 97
#define Key_B 98
#define Key_C 99
#define Key_D 100
#define Key_E 101
#define Key_F 102
#define Key_G 103
#define Key_H 104
#define Key_I 105
#define Key_J 106
#define Key_K 107
#define Key_L 108
#define Key_M 109
#define Key_N 110
#define Key_O 111
#define Key_P 112
#define Key_Q 113
#define Key_R 114
#define Key_s 115
#define Key_S 83
#define Key_T 116
#define Key_U 117
#define Key_V 118
#define Key_w 119 
#define Key_W 87
#define Key_X 120
#define Key_Y 121
#define Key_Z 122

#define Key_Enter 13
