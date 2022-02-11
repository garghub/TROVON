static int F_1 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( F_3 ( V_2 + V_3 ) ) ;
switch ( V_1 ) {
case 0x00 :
return V_4 ;
case 0x01 :
return V_5 ;
default:
return V_6 ;
}
}
int F_4 ( void )
{
if ( V_7 == - 1 )
V_7 = F_1 () ;
return V_7 ;
}
