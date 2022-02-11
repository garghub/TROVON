void F_1 ( struct V_1 * V_2 )
{
static T_1 V_3 [ 256 ] ;
if ( V_2 -> V_4 [ 0 ] . V_5 == 0 ) {
V_2 -> V_4 [ 0 ] . V_6 . V_7 = 0xa0 >> 1 ;
F_2 ( & V_2 -> V_4 [ 0 ] . V_6 , V_3 ,
sizeof( V_3 ) ) ;
}
}
