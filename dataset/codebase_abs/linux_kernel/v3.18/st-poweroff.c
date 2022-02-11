static void F_1 ( enum V_1 V_1 , const char * V_2 )
{
F_2 ( V_3 -> V_4 ,
V_3 -> V_5 ,
V_3 -> V_6 ,
0 ) ;
F_2 ( V_3 -> V_4 ,
V_3 -> V_7 ,
V_3 -> V_8 ,
0 ) ;
}
static int F_3 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 . V_14 ;
const struct V_15 * V_16 ;
struct V_17 * V_13 = & V_10 -> V_13 ;
V_16 = F_4 ( V_18 , V_13 ) ;
if ( ! V_16 )
return - V_19 ;
V_3 = (struct V_20 * ) V_16 -> V_21 ;
V_3 -> V_4 =
F_5 ( V_12 , L_1 ) ;
if ( F_6 ( V_3 -> V_4 ) ) {
F_7 ( V_13 , L_2 ) ;
return F_8 ( V_3 -> V_4 ) ;
}
V_22 = F_1 ;
return 0 ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_23 ) ;
}
