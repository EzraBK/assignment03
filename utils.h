/*
 *This header file will prototype the definition of all utils function
 *@Author ( Dat Nguyen )
 *Date Feb 15th, 2018
 *
 */

//TODO: store all enum tyoe declaration in utils.h file
//  add MIN and MAX to the Mode enum type
/*
 *This function will convert degree to radians , then passed by reference to a
 *a variable .
 *@parameter double degree - degrees you would like to convert
 *           double *radian - the variable you would liek to passed by reference
 *@return 0 - no error
 *        1 - error ( NULL ERROR, INVALID INPUT ERROR )
 *Ex: errorCode = degreesToRadians(130,radian);
 * >> radian  = radian
 */
int degreesToRadians(double degree, double *radian);

/*
 *This function compute the annual percentage yield given an annual percentage rate using
 *@parameter double apr - percent
 *           double *arpy - variable pass by reference
 *return 0 - no error
 *       1 - error
 */
int annualPercentageYield(double apr, double *apy);

/*
 *this function compute the air distance between the two location given by their latitude/longtitude.
 *range [-180, 180]
 *@ parameter double latitude, double longtitude, double lattitudeB, double longtittudeB, double distance.
 *the formula assume that long and lat are measure in radia.
 *return 0 // no error
 *       1 // invalid lat and long
 *       2 // NULL POINTER ERROR
 */
int getAirDistance(double latA, double longA, double LatB, double longB, double *distance);

/*
 *this function convert from an RGB color model to CMYK(cyab-magneta-yellow-key) color model
 *@paramater int r, int g, int b, double *c, double *m, double *y, double *k
 *return ERROR_CODE
 *  0 - NOEROR
 *  1 - INVALID INPUT
 *  2 - NULLPOINTER
 */
int rgbToCMYK(int r,int g, int b, double *c, double *m, double *y, double *k);

/*
 *
 *this function convert from CMYK to RGB
 *@paramater double c, double m, double y, double k, int *r, int *g, int *b
 *return ERROR CODE
 *  0 - NO ERROR
 *  1 - INVALID INPUT
 *  2 -NULL POINTER
 */
int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b);

/*
 *this function take an RGB color valud and transform it to a grayscale version * @parameter
 *Their are several technique to perform this conversion.
 * AVERAGE technique
 * LIGHTNESS technique
 * LUMINOSITY technique
 *@ parameter int *r, int *g, int *b, Mode m
 * return Error CODE
 */
 int toGrayScale(int *r, int *g, int *b, Mode);

 /**
  *This function return the max or min value among 3 input number
  *@ parameter double r, double g, double b,Mode m
  *return the max or min valueN
  */
  double getMinMax(double a, double b, double c, Mode m);
