static void F_1 ( enum V_1 V_1 , const char * V_2 )
{
F_2 ( V_3 , V_4 , 0xab ) ;
F_2 ( V_3 , V_5 , 0x00000040 ) ;
F_2 ( V_3 , V_6 , V_7 ) ;
F_3 ( V_3 , V_8 ,
V_9 , V_9 ) ;
}
static int F_4 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = & V_11 -> V_13 ;
V_3 = F_5 ( V_13 -> V_14 , L_1 ) ;
if ( F_6 ( V_3 ) ) {
F_7 ( L_2 , V_13 -> V_14 -> V_15 ) ;
return F_8 ( V_3 ) ;
}
V_16 = F_1 ;
return 0 ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_17 ) ;
}
