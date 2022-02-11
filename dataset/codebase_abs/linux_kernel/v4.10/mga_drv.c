static int T_1 F_1 ( void )
{
V_1 . V_2 = V_3 ;
return F_2 ( & V_1 , & V_4 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 , & V_4 ) ;
}
static int F_5 ( struct V_5 * V_6 )
{
const struct V_7 * const V_8 = V_6 -> V_8 ;
if ( ( V_8 -> V_9 == 0x0525 ) && V_8 -> V_10 -> V_11
&& ( V_8 -> V_10 -> V_11 -> V_12 == 0x3388 )
&& ( V_8 -> V_10 -> V_11 -> V_9 == 0x0021 ) ) {
return 0 ;
}
return 2 ;
}
