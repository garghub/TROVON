static void
F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 ) ;
}
unsigned int
F_3 ( const unsigned char * V_4 , int V_5 , struct V_6 * V_7 )
{
if ( ( V_5 < 2 ) || ( V_5 > 3 ) )
return V_8 ;
if ( ( V_4 [ 0 ] != '^' ) && ( V_4 [ 0 ] != '\252' ) )
return V_8 ;
#ifdef F_4
if ( V_5 == 3 && V_4 [ 1 ] == '-' ) {
V_3 = V_4 [ 2 ] ;
F_5 ( & V_9 ) ;
return V_10 ;
}
#endif
if ( V_5 != 2 )
return V_8 ;
switch ( tolower ( V_4 [ 1 ] ) ) {
case 'c' :
return F_6 ( V_7 ) | V_11 ;
case 'd' :
return F_7 ( V_7 ) | V_11 ;
case 'z' :
return F_8 ( V_7 ) | V_11 ;
}
return V_8 ;
}
