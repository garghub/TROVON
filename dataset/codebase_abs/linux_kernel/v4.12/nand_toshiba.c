static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
if ( V_2 -> V_5 . V_6 >= 6 && F_4 ( V_2 ) &&
( V_2 -> V_5 . V_7 [ 5 ] & 0x7 ) == 0x6 &&
! ( V_2 -> V_5 . V_7 [ 4 ] & 0x80 ) )
V_4 -> V_8 = 32 * V_4 -> V_9 >> 9 ;
}
static int F_5 ( struct V_1 * V_2 )
{
if ( F_4 ( V_2 ) )
V_2 -> V_10 |= V_11 ;
return 0 ;
}
