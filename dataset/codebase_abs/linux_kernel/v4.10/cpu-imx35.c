static int F_1 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( F_3 ( V_2 + V_3 ) ) ;
switch ( V_1 ) {
case 0x00 :
return V_4 ;
case 0x10 :
return V_5 ;
case 0x11 :
return V_6 ;
default:
return V_7 ;
}
}
int F_4 ( void )
{
if ( V_8 == - 1 )
V_8 = F_1 () ;
return V_8 ;
}
