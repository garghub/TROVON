static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 . V_8 ) ;
if ( V_6 -> V_9 -> V_10 . V_11 == 1 ) {
switch ( V_2 -> V_12 ) {
case V_13 :
case V_14 :
if ( * V_4 >= 122 && V_3 [ 115 ] == 0xff && V_3 [ 116 ] == 0x7f
&& V_3 [ 120 ] == 0xff && V_3 [ 121 ] == 0x7f ) {
F_3 ( V_2 , L_1 ) ;
V_3 [ 116 ] = V_3 [ 121 ] = 0x2f ;
}
break;
case V_15 :
case V_16 :
case V_17 :
if ( * V_4 >= 113 && V_3 [ 106 ] == 0xff && V_3 [ 107 ] == 0x7f
&& V_3 [ 111 ] == 0xff && V_3 [ 112 ] == 0x7f ) {
F_3 ( V_2 , L_1 ) ;
V_3 [ 107 ] = V_3 [ 112 ] = 0x2f ;
}
break;
}
}
return V_3 ;
}
