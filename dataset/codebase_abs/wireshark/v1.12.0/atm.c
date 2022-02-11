void
F_1 ( struct V_1 * V_2 , const T_1 * V_3 )
{
V_2 -> V_4 . V_5 . V_6 = V_7 ;
V_2 -> V_4 . V_5 . type = V_8 ;
V_2 -> V_4 . V_5 . V_9 = V_10 ;
if ( V_2 -> V_4 . V_5 . V_11 == 0 ) {
switch ( V_2 -> V_4 . V_5 . V_12 ) {
case 5 :
V_2 -> V_4 . V_5 . V_6 = V_13 ;
return;
case 16 :
V_2 -> V_4 . V_5 . type = V_14 ;
return;
}
}
if ( V_2 -> V_15 >= 3 ) {
if ( V_3 [ 0 ] == 0xaa && V_3 [ 1 ] == 0xaa && V_3 [ 2 ] == 0x03 ) {
V_2 -> V_4 . V_5 . type = V_16 ;
} else if ( ( V_2 -> V_4 . V_5 . V_17 && V_2 -> V_4 . V_5 . V_17 < 16 ) ||
V_2 -> V_15 < 16 ) {
V_2 -> V_4 . V_5 . V_6 = V_13 ;
} else if ( V_3 [ 0 ] == 0x83 || V_3 [ 0 ] == 0x81 ) {
V_2 -> V_4 . V_5 . V_6 = V_13 ;
} else {
V_2 -> V_4 . V_5 . type = V_18 ;
F_2 ( V_2 , V_3 ) ;
}
} else {
V_2 -> V_4 . V_5 . V_6 = V_13 ;
}
}
void
F_2 ( struct V_1 * V_2 , const T_1 * V_3 )
{
if ( V_2 -> V_15 >= 2 ) {
if ( V_3 [ 0 ] == 0xff && V_3 [ 1 ] == 0x00 ) {
V_2 -> V_4 . V_5 . V_9 = V_19 ;
} else {
V_2 -> V_4 . V_5 . V_9 = V_20 ;
}
}
}
