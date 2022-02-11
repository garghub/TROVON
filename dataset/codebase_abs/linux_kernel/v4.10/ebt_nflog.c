static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_4 ) ;
struct V_9 V_10 ;
V_10 . type = V_11 ;
V_10 . V_12 . V_13 . V_14 = V_6 -> V_15 ;
V_10 . V_12 . V_13 . V_16 = V_6 -> V_16 ;
V_10 . V_12 . V_13 . V_17 = V_6 -> V_18 ;
F_3 ( V_8 , V_19 , F_4 ( V_4 ) , V_2 , F_5 ( V_4 ) ,
F_6 ( V_4 ) , & V_10 , L_1 , V_6 -> V_20 ) ;
return V_21 ;
}
static int F_7 ( const struct V_22 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_23 & ~ V_24 )
return - V_25 ;
V_6 -> V_20 [ V_26 - 1 ] = '\0' ;
return 0 ;
}
static int T_1 F_8 ( void )
{
return F_9 ( & V_27 ) ;
}
static void T_2 F_10 ( void )
{
F_11 ( & V_27 ) ;
}
