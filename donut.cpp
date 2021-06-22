#include "donut.h"
#include <math.h>

#define two_pi 6.28
using namespace std;

donut::donut()
{
    // intialize values
    R2=2;
    K2=5;
    screen_width=80; //arbitrary
    screen_height=24;
    A=0;
    B=0;
    phi=0;
    theta =0;
    phi_spacing=0.07;
    theta_spacing=0.02;
    sz =((screen_height-R2)*screen_width);
}

string donut::iterate() {
    //actual donut ascii generated per iteration
    string label_data="";
    out = new char[sz]();
    depths = new float[sz]();
    for(theta=0;theta<two_pi;theta+=theta_spacing){
        for(phi=0;phi<two_pi;phi+=phi_spacing){
            float theta_c= cos(theta), theta_s = sin(theta);
            float phi_c= cos(phi), phi_s = sin(phi);
            float A_c = cos(A), A_s=sin(A);
            float B_c=cos(B), B_s=sin(B);
            float d=R2+theta_c, l=d*A_c*phi_s-A_s*theta_s;
            float x=d*B_c*phi_c -l*B_s;
            float y = d*phi_c*B_s + l*B_c;
            float z = (A_s*d*phi_s)+(A_c*theta_s);
            float L= (-1*phi_c*theta_c*B_s)-(A_s*theta_c*phi_s)-(A_c*theta_s)+(B_c*(A_s*theta_s - theta_c*A_c*phi_s));
            float proj_z= K2+z, inv_proj_z=1/proj_z;
            int proj_x = (x*30*inv_proj_z)+ 40; //projected x
            int proj_y = (y*15*inv_proj_z) + 12; //projected y
            int idx = L*8, m_idx=proj_x+screen_width*proj_y;
            if(proj_y>0 && proj_y<(screen_height-R2)&&proj_x>0&&proj_x<screen_width && inv_proj_z>depths[m_idx]){
                out[m_idx]= ".,-~:;=!*#$@"[idx>0?idx:0]; //set character
                depths[m_idx] = inv_proj_z;
            }
        }
    }
    for (int i=0;i<sz;i++){
        label_data += (i % screen_width ? (out[i]== '\0'?' ':char(out[i])) : '\n'); //actual string
        A+= (theta_spacing/sz);
        B+=(phi_spacing/sz);
    }
    delete[] out ; // clean up
    delete[] depths ;
    return label_data;
}
