static int F_1 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( F_3 ( V_2
+ V_3 ) ) ;
V_4 = ( int ) ( ( V_1 >> 12 ) & 0xFFFF ) ;
switch ( V_1 >> 28 ) {
case 0 :
return V_5 ;
case 1 :
return V_6 ;
case 2 :
return V_7 ;
default:
return V_8 ;
}
}
int F_4 ( void )
{
if ( V_9 == - 1 )
V_9 = F_1 () ;
if ( V_4 != 0x8821 )
return - V_10 ;
return V_9 ;
}
