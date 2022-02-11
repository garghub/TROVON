static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
if ( V_2 -> V_5 . V_6 [ 4 ] != 0x00 && V_2 -> V_5 . V_6 [ 5 ] == 0x00 &&
V_2 -> V_5 . V_6 [ 6 ] == 0x00 && V_2 -> V_5 . V_6 [ 7 ] == 0x00 &&
V_4 -> V_7 == 512 ) {
V_4 -> V_8 = 128 * 1024 ;
V_4 -> V_8 <<= ( ( V_2 -> V_5 . V_6 [ 3 ] & 0x03 ) << 1 ) ;
}
}
static int F_4 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 ) )
V_2 -> V_9 |= V_10 ;
return 0 ;
}
