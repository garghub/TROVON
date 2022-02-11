static void T_1 F_1 ( void T_2 * V_1 )
{
unsigned int V_2 ;
V_2 = ( F_2 ( 7 ) | F_3 ( 7 ) |
V_3 | V_4 |
V_5 | V_6 |
V_7 | V_8 ) ;
F_4 ( V_2 , V_1 + V_9 ) ;
F_4 ( 0x0 , V_1 + V_10 ) ;
}
static void T_1 F_5 ( struct V_11 * V_12 )
{
struct V_13 * V_14 ;
V_14 = F_6 ( V_12 , & V_15 ) ;
if ( ! V_14 )
return;
F_7 ( V_14 , V_16 , L_1 ,
V_17 [ 0 ] , V_17 [ 1 ] , 0x14200 ,
V_18 , F_8 ( V_18 ) ,
V_19 ) ;
F_1 ( V_14 -> V_1 ) ;
}
static void T_1 F_9 ( struct V_11 * V_12 )
{
F_6 ( V_12 , & V_20 ) ;
}
static int T_1 F_10 ( struct V_21 * V_22 )
{
struct V_11 * V_12 = V_22 -> V_23 . V_24 ;
F_6 ( V_12 , & V_25 ) ;
return 0 ;
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_26 ,
F_10 ) ;
}
