void
F_1 ( const T_1 * V_1 , T_2 V_2 ,
union V_3 * V_4 )
{
V_4 -> V_5 . V_6 = V_7 ;
V_4 -> V_5 . type = V_8 ;
V_4 -> V_5 . V_9 = V_10 ;
if ( V_4 -> V_5 . V_11 == 0 ) {
switch ( V_4 -> V_5 . V_12 ) {
case 5 :
V_4 -> V_5 . V_6 = V_13 ;
return;
case 16 :
V_4 -> V_5 . type = V_14 ;
return;
}
}
if ( V_2 >= 3 ) {
if ( V_1 [ 0 ] == 0xaa && V_1 [ 1 ] == 0xaa && V_1 [ 2 ] == 0x03 ) {
V_4 -> V_5 . type = V_15 ;
} else if ( ( V_4 -> V_5 . V_16 &&
V_4 -> V_5 . V_16 < 16 ) || V_2 < 16 ) {
V_4 -> V_5 . V_6 = V_13 ;
} else if ( V_1 [ 0 ] == 0x83 || V_1 [ 0 ] == 0x81 ) {
V_4 -> V_5 . V_6 = V_13 ;
} else {
V_4 -> V_5 . type = V_17 ;
F_2 ( V_1 , V_2 , V_4 ) ;
}
} else {
V_4 -> V_5 . V_6 = V_13 ;
}
}
void
F_2 ( const T_1 * V_1 , T_2 V_2 ,
union V_3 * V_4 )
{
if ( V_2 >= 2 ) {
if ( V_1 [ 0 ] == 0xff && V_1 [ 1 ] == 0x00 ) {
V_4 -> V_5 . V_9 = V_18 ;
} else {
V_4 -> V_5 . V_9 = V_19 ;
}
}
}
