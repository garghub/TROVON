static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 . V_7 . V_4 ;
T_1 V_8 ;
if ( 1 ) {
F_2 ( V_4 , 0x100ce4 , 0xffffffff ) ;
}
V_8 = F_3 ( V_4 , 0x100c80 ) ;
V_8 &= 0xf000087f ;
F_2 ( V_4 , 0x418880 , V_8 ) ;
F_2 ( V_4 , 0x418890 , 0 ) ;
F_2 ( V_4 , 0x418894 , 0 ) ;
F_2 ( V_4 , 0x4188b0 , F_3 ( V_4 , 0x100cc4 ) ) ;
F_2 ( V_4 , 0x4188b4 , F_3 ( V_4 , 0x100cc8 ) ) ;
F_2 ( V_4 , 0x4188b8 , F_3 ( V_4 , 0x100ccc ) ) ;
F_2 ( V_4 , 0x4188ac , F_3 ( V_4 , 0x100800 ) ) ;
}
static void
F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 . V_7 . V_4 ;
F_2 ( V_4 , 0x419e44 , 0xdffffe ) ;
F_2 ( V_4 , 0x419e4c , 0x5 ) ;
}
int
F_5 ( struct V_3 * V_4 , int V_9 , struct V_10 * * V_11 )
{
return F_6 ( & V_12 , V_4 , V_9 , V_11 ) ;
}
