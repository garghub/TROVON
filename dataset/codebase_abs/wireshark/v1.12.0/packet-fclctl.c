const T_1 *
F_1 ( T_2 V_1 , T_2 type )
{
if ( ( V_1 == V_2 ) ||
( V_1 == V_3 ) ) {
return ( F_2 ( ( type & 0xF0 ) , V_4 , L_1 ) ) ;
}
return L_2 ;
}
const T_1 *
F_3 ( T_3 V_1 , T_3 V_5 )
{
if ( V_1 == V_6 ) {
return F_4 ( F_5 () , L_3 ,
F_2 ( ( ( V_5 & 0xFF000000 ) >> 24 ) , V_7 , L_1 ) ,
F_2 ( ( ( V_5 & 0x00FF0000 ) >> 16 ) , V_8 , L_1 ) ) ;
}
if ( ( V_1 == V_9 ) ||
( V_1 == V_10 ) ) {
return F_4 ( F_5 () , L_3 ,
F_2 ( ( ( V_5 & 0xFF000000 ) >> 24 ) , V_11 , L_1 ) ,
F_2 ( ( ( V_5 & 0x00FF0000 ) >> 16 ) , V_12 , L_4 ) ) ;
}
return L_2 ;
}
