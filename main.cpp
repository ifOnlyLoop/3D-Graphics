#include <stdio.h>
#include"./vec3.h"
#include<iostream>
int main(){

    vec3<float> v(5,5,5);
    std::cout<<v.x<<v.y<<v.z;
	
	return 0;
}