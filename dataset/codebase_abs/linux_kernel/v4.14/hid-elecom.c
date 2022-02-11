static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
switch ( V_2 -> V_5 ) {
case V_6 :
if ( * V_4 >= 48 && V_3 [ 46 ] == 0x05 && V_3 [ 47 ] == 0x0c ) {
F_2 ( V_2 , L_1 ) ;
V_3 [ 47 ] = 0x00 ;
}
break;
case V_7 :
case V_8 :
case V_9 :
case V_10 :
if ( * V_4 == 213 && V_3 [ 13 ] == 5 && V_3 [ 21 ] == 5 ) {
F_2 ( V_2 , L_2 ) ;
V_3 [ 13 ] = 8 ;
V_3 [ 21 ] = 8 ;
V_3 [ 29 ] = 0 ;
}
break;
}
return V_3 ;
}
