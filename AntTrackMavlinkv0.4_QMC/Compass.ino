QMC5883LCompass compass;

// Get the mag declination of your location here http://www.magnetic-declination.com/ and insert in # defined in next line
#define DECLINATION  1.1 // In degrees

//******************************************************************************
uint8_t Initialise_Compass() {
  int azimuth = 2000; //Initialize with a non-sens value >360 degres
  
  compass.init();
  compass.read();
  azimuth = compass.getAzimuth();

  if ((azimuth >= 0) and (azimuth <= 360))
    return 1; //It works !
  else
    return 0; //Caramba, encore rate!
}

//******************************************************************************
float GetMagHeading() {
  int x = 0;
  int y = 0;
  int z = 0;

  while (x==0&&y==0&&z==0){ //ignorer premiere mesure erronee a 0 Gauss
    compass.read();
    // Return XYZ readings
    x = compass.getX();
    y = compass.getY();  
    z = compass.getZ();
  }
  
  float fHeading = RadToDeg(atan2(y, x));  //All in degrees now
  #if defined Compass_Swap_E_W
    fHeading = fHeading * -1;  //patch for my cheap and strange QMC5883 compass which inverts E and W directions
  #endif
  fHeading += DECLINATION;  // Add magnetic declination
  fHeading = Normalise_360(fHeading);
  

  #if defined Debug_All || defined Debug_Compass
    /* Display the results */
    Debug.print("X: "); Debug.print(x); Debug.println(" G");
    Debug.print("Y: "); Debug.print(y); Debug.println(" G");
    Debug.print("Z: "); Debug.print(z); Debug.println(" G");
    Debug.print("Heading = "); Debug.print(fHeading); Debug.println(" degres (inclus 1.1 decl. mag.)");
    int azimuth = compass.getAzimuth();
    char txtHeading[3];
    compass.getDirection(txtHeading, azimuth);
    Debug.print("Azimuth = "); Debug.print(azimuth); Debug.print(" degres / Direction : "); Debug.print(txtHeading[0]);Debug.print(txtHeading[1]);Debug.print(txtHeading[2]);Debug.println();
  #endif

  return fHeading;
}

//******************************************************************************
int16_t Normalise_360(int16_t arg) {
  if (arg < 0) arg += 360;
  if (arg > 359) arg -= 360;
  return arg;
}
//***************************************************
float RadToDeg (float _Rad) {
  return _Rad * 180 / PI;  
}
//***************************************************
