static void F_1 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( F_3 ( V_2
+ V_3 ) ) ;
switch ( V_1 >> 28 ) {
case 0 :
V_4 = V_5 ;
break;
case 1 :
V_4 = V_6 ;
break;
case 2 :
V_4 = V_7 ;
break;
default:
V_4 = V_8 ;
}
V_9 = ( int ) ( ( V_1 >> 12 ) & 0xFFFF ) ;
}
int F_4 ( void )
{
if ( V_4 == - 1 )
F_1 () ;
if ( V_9 != 0x8821 )
return - V_10 ;
return V_4 ;
}
