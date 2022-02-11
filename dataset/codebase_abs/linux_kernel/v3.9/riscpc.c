static int T_1 F_1 ( const struct V_1 * V_1 )
{
V_2 = V_1 -> V_3 . V_4 . V_5 ;
V_6 = V_1 -> V_3 . V_4 . V_7 ;
switch ( V_1 -> V_3 . V_4 . V_8 ) {
case 512 :
V_9 += V_10 * 256 ;
case 256 :
V_9 += V_10 * 256 ;
default:
break;
}
#if 0
if (vram_size) {
desc->video_start = 0x02000000;
desc->video_end = 0x02000000 + vram_size;
}
#endif
return 0 ;
}
static void T_1 F_2 ( void )
{
F_3 ( V_11 , F_4 ( V_11 ) ) ;
F_5 ( 0xc , V_12 + ( 0x3f2 << 2 ) ) ;
V_13 &= ~ V_14 ;
}
static int T_1 F_6 ( void )
{
F_7 ( 0 , & V_15 , 1 ) ;
return F_8 ( V_16 , F_4 ( V_16 ) ) ;
}
static void F_9 ( char V_17 , const char * V_18 )
{
F_10 ( 0 , V_19 ) ;
F_11 ( 0 ) ;
}
