static int F_1 ( T_1 V_1 , unsigned char * V_2 , int V_3 )
{
const unsigned char * V_4 ;
unsigned char V_5 = V_1 & 0x00ff ;
unsigned char V_6 = ( V_1 & 0xff00 ) >> 8 ;
if ( V_3 <= 0 )
return - V_7 ;
V_4 = V_8 [ V_6 ] ;
if ( V_4 && V_4 [ V_5 ] )
V_2 [ 0 ] = V_4 [ V_5 ] ;
else
return - V_9 ;
return 1 ;
}
static int F_2 ( const unsigned char * V_10 , int V_3 , T_1 * V_1 )
{
* V_1 = V_11 [ * V_10 ] ;
if ( * V_1 == 0x0000 )
return - V_9 ;
return 1 ;
}
static int T_2 F_3 ( void )
{
return F_4 ( & V_12 ) ;
}
static void T_3 F_5 ( void )
{
F_6 ( & V_12 ) ;
}
