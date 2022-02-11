T_1
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 V_5 ;
T_2 V_6 ; T_3 V_7 ;
T_1 V_8 = F_2 ( V_2 , V_3 , & V_6 , & V_7 , & V_5 ) ;
if ( V_8 = ( V_8 + V_7 + 0x0f ) & ~ 0x0f , V_8 ) {
switch ( F_3 ( V_2 , V_8 + 0x00 ) ) {
case 0x4544504e :
break;
default:
F_4 ( V_2 , L_1 ,
V_8 , F_3 ( V_2 , V_8 + 0x00 ) ) ;
V_8 = 0 ;
break;
}
}
return V_8 ;
}
T_1
F_5 ( struct V_1 * V_2 , T_1 V_3 , struct V_9 * V_10 )
{
T_1 V_8 = F_1 ( V_2 , V_3 ) ;
memset ( V_10 , 0x00 , sizeof( * V_10 ) ) ;
if ( V_8 ) {
V_10 -> V_11 = F_6 ( V_2 , V_8 + 0x08 ) * 512 ;
V_10 -> V_12 = F_7 ( V_2 , V_8 + 0x0a ) & 0x80 ;
}
return V_8 ;
}
