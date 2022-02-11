void F_1 ( struct V_1 * V_2 )
{
T_1 clock ;
struct V_3 * V_4 = F_2 ( 0 , 0 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_3 ( V_4 , 0xD0 , 0xD0050300 ) ;
F_4 ( V_4 , 0xD4 , & clock ) ;
F_5 ( V_4 ) ;
switch ( clock & 0x07 ) {
case 0 :
V_6 -> V_8 = 100 ;
break;
case 1 :
V_6 -> V_8 = 133 ;
break;
case 2 :
V_6 -> V_8 = 150 ;
break;
case 3 :
V_6 -> V_8 = 178 ;
break;
case 4 :
V_6 -> V_8 = 200 ;
break;
case 5 :
case 6 :
case 7 :
V_6 -> V_8 = 266 ;
break;
default:
V_6 -> V_8 = 0 ;
}
}
