T_1
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 , T_3 * V_5 )
{
T_1 V_6 = F_2 ( V_2 , V_3 + 0x18 ) ;
if ( V_6 ) {
V_6 += V_3 ;
switch ( F_3 ( V_2 , V_6 + 0x00 ) ) {
case 0x52494350 :
case 0x53494752 :
case 0x5344504e :
* V_5 = F_2 ( V_2 , V_6 + 0x0a ) ;
* V_4 = F_4 ( V_2 , V_6 + 0x0c ) ;
break;
default:
F_5 ( V_2 , L_1 ,
V_6 , F_3 ( V_2 , V_6 + 0x00 ) ) ;
V_6 = 0 ;
break;
}
}
return V_6 ;
}
T_1
F_6 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 , T_3 * V_5 ,
struct V_7 * V_8 )
{
T_1 V_6 = F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
memset ( V_8 , 0x00 , sizeof( * V_8 ) ) ;
if ( V_6 ) {
V_8 -> V_9 = F_2 ( V_2 , V_6 + 0x04 ) ;
V_8 -> V_10 = F_2 ( V_2 , V_6 + 0x06 ) ;
V_8 -> V_11 [ 0 ] = F_4 ( V_2 , V_6 + 0x0d ) ;
V_8 -> V_11 [ 1 ] = F_4 ( V_2 , V_6 + 0x0e ) ;
V_8 -> V_11 [ 2 ] = F_4 ( V_2 , V_6 + 0x0f ) ;
V_8 -> V_12 = F_2 ( V_2 , V_6 + 0x10 ) * 512 ;
V_8 -> V_13 = F_2 ( V_2 , V_6 + 0x12 ) ;
V_8 -> V_14 = F_4 ( V_2 , V_6 + 0x14 ) ;
V_8 -> V_15 = F_4 ( V_2 , V_6 + 0x15 ) & 0x80 ;
}
return V_6 ;
}
