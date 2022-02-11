T_1 T_2 F_1 ( void )
{
T_3 V_1 = V_2 ;
T_3 V_3 ;
T_3 V_4 ;
V_3 = F_2 ( V_5 ) & 7 ;
V_1 |= V_3 << 16 ;
switch ( V_3 ) {
case 0 :
V_3 = 32 ;
break;
case 1 :
V_3 = 36 ;
break;
case 2 :
V_3 = 40 ;
break;
case 3 :
V_3 = 42 ;
break;
case 4 :
V_3 = 44 ;
break;
case 5 :
default:
V_3 = 48 ;
break;
}
V_1 |= 64 - ( V_3 > 40 ? 40 : V_3 ) ;
V_4 = ( F_2 ( V_6 ) >> V_7 ) & 0xf ;
V_1 |= ( V_4 == V_8 ) ?
V_9 :
V_10 ;
F_3 ( V_1 , V_11 ) ;
return V_3 ;
}
