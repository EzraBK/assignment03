/**
 *Author @Dat Nguyen
 *Date Feb 17th, 2018
 *last modified date: feb 22nd, 2018
 */

#include<math.h>
#include<utils.h>

enum{
  NO_ERROR = 0,
  INPUT_ERROR = 1,
  NULL_ERROR,
}Error;

enum{
  AVERAGE = 0,
  LIGHTNESS,
  LUMINOSITY,
  MIN,
  MAX,
} Mode;

int degreesToRadians(double degree, double *radian){
  //declare vairable
  double radian;
  int error;

  // input validation
  if(degree < 0 || degree > 360){
    error = INPUT_ERROR;
  }else{
    *radian = degree * (M_PI / 180);
    error = NO_ERROR;
  }
  return error;

}

int annualPercentageYield(double apr, double *apy){

  //declare variable
  int error = 0;

  //input validation
  if(apr < 0 || apr > 1){
    error = INPUT_ERROR;
  }else{
    *apy = pow(M_E,apr) - 1;
  }
  return error;
}

int getAirDistance(double latA, double longA, double latB, double longB, double *distance){
  //TODO: make an enum error for this function
  // to handle invalid radian and degree.

  //declare variable
  int error = 0;
  double _latA, _latB, _longA, _longB = 0; // these arevalue in radian
  #define R 6371 // the average radius of the earth
  #define ONE_RADIAN M_PI/180

  // input validation and computation
  if(latA < -90 || latA > 90 || latB < -90 || latB >90 ||
     longA < -180 || longA > 180 || longA < -180 || longA > 180){
    error = INPUT_ERROR;
  }else{
    // convert degree to radian
    _latA  = latA * ONE_RADIAN;
    _longA = longA * ONE_RADIAN;
    _latB  = latB * ONE_RADIAN;
    _longB = longB * ONE_RADIAN;

    // compute
    *distance = acos( (sin(_latA)*sin(_latB)) + (cos(_latA) * cos(_latB) * cos(fabs(_longA - _longB)) )) * R ;
    error = 0; // return 0 if no error
  }
  return error;
}

int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k){

  //declare variable
  int error = 0;
  double _r, _g, _b ;// variable store scaled rgb value

  //input validation and computation
  if( r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255){
    error = INPUT_ERROR;
  }else{

    // scale RGB value to [0,1] range
    _r = r / 255;
    _g = g / 255;
    _b = b / 255;

    // computation

    k  = 1 - getMinMax(_r,_g,_b,MAX);
    *c = (1 - _r - k)/(1 - k);
    *m = (1 - _g - k)/(1 - k);
    *y = (1 - _b - k)/(1 - k);

    return error;
  }

  return error;
}


int toGrayScale(int *r, int *g, int *b, Mode M){
  //declare variable
  int error = 0 ;

  // copy content of pointer variables to regular tyope variable
  int _r = *r;
  int _g = *g;
  int _b = *b;
  double average, lightness, luminosity = 0;

  // inputvalidation
  if( r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255){
    error = INPUT_ERROR;
  }else if{
    // mode selection and computation
    if(M == AVERAGE){
      average = (_r + _g + _b) / 3;
    }else if(M == LIGHTNESS){
      lightness = (getMinMax(_r,_g,_b,MAX) + getMinMax(_r,_g,_b,MIN))) / 2;
    }else if(M == LUMINOSITY){
      luminosity = 0.21 * _r + 0.72 * _g + 0.07 * _b;
    }
    return error;
  }// end input validation check
}// end function

double getMinMax(double a, double b, double c, Mode m){

  // check adn return the max number of the 3
  if(m == MAX && a >= b && a >= c){
    return a;
  }else if(m == MAX && b >= a && b >= c){
    return b;
  }else if(m == MAX && c >= a && c >= b){
    return c;
  }else{
    printf("DEBUG:getMinMax() - checkMax");
    //TODO: create Mode enum type then add INVALID error
  }

  // chcek and return the min number of the 3
  if(m == MIN && a <= b && a <= c){
    return a;
  }else if(m == MIN && b <= a && b <= c){
    return b;n
  }else if(m == MIN && c <= a && c <= b){
    return c;
  }else{
    printf("DEBUG:getMinMax() - checkMin\n");
  }
}// end get minMax
