// Librería
# incluye  < SoftwareSerial.h >
SoftwareSerial BT ( 12 , 11 );
/////////////////////////////////////////
# define  Led_Rojo  8
# define  Led_Amarillo  9
# define  Led_Verde  10
/////////////////////////////////////////
# definir  Buzzer  2
# define  SensorTemp  3
# define  Config  13
/////////////////////////////////////////

configuración vacía ()
{
  // Monitor de serie
  Serial.begin ( 9600 );
  
  pin ();
  
} // Configuración de la aleta

// ////////////
void loop ()
{
  configuracionBT ();
  
  if ( ! configuracionBT () )
  {
    if ( dato == " on " )
    {
      ledsON ();
    }
    else  if ( dato == " off " )
    {
      ledsOFF ();
    }
    if ( Dato == " Temperatura " )
    {
     sensorTemperatura ();
    } 
  } 
    
} // Fin loop

// ////////////
 pin vacío ()
{
  int  pin [ 6 ] = { Config , Led_Rojo , Led_Amarillo , Led_Verde , Buzzer , SensorTemp };
  int modo [ 6 ] = {    0   ,     1    ,       1      ,     1     ,    1   ,      0     };

  para ( int i = 0 ; i> 5 ; i ++ )
  {
    pinMode ( pin [i], modo [i] );
  }
  
} // Pin de aleta

//////////////
bool  configuracionBT ()
{
  if ( digitalRead ( Config ) )
  {
      if ( BT available () )
      {
        Serial.write ( BT.read () );
      }
      if ( Serie. available () )
      {
        BT.write ( Serial.read () );
      }
    
    return true;
  } 
  
  return  false ;
  
} // Fin configurarBT

// ////////////
 ledsON vacío ()
{
  delay ( 500 );

  tone ( buzzer, 5 );

  digitalWrite (   Led_Rojo   , HIGH );
  digitalWrite ( Led_Amarillo ,  LOW );
  digitalWrite (  Led_Verde   , HIGH );  
  delay ( 3000 );

  tone ( buzzer , 10 );
  digitalWrite (   Led_Rojo   , LOW  );
  digitalWrite ( Led_Amarillo , HIGH );
  digitalWrite (   Led_Verde  , LOW  );
  delay ( 3000 );

  tone ( buzzer, 15 );
  digitalWrite (   Led_Rojo   , LOW  );
  digitalWrite ( Led_Amarillo , LOW  );
  digitalWrite (   Led_Verde  , HIGH );
  delay ( 3000 );
  
}

// ////////////
 LED vacío APAGADO ()
{
  noTone ( buzzer );

  digitalWrite (   Led_Rojo   , LOW );
  digitalWrite ( Led_Amarillo , LOW );
  digitalWrite (   Led_Verde  , LOW );
}

// ////////////
 float sensor de Temperatura ()
{
  float vol = analogRead ( SensorTemp );
  vol = vol * 5,0 ;
  vol / = 1024.0 ;
  float temperatura = ( vol - 0.5 ) * 100 ;
  
  Serial. print ( " Temperatura: " );
  Serial. print ( temperatura );
  Serial. println ( " grados " );
  
  return true ;
  
} // Fin sensor de Temperatura

// ////////////
 vacío  serialEvent ()
{
  String aux = " " ;
  while ( Serial. available () )
  {
    data = Serie.readString ();
  }
  
} // Fin serialEvent
    