static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 V_9 ;
struct V_10 * V_10 = V_4 -> V_10 ;
V_9 . type = V_11 ;
V_9 . V_12 . V_13 . V_14 = V_6 -> V_15 ;
V_9 . V_12 . V_13 . V_16 = V_6 -> V_16 ;
V_9 . V_12 . V_13 . V_17 = V_6 -> V_18 ;
F_2 ( V_10 , V_19 , V_4 -> V_20 , V_2 , V_4 -> V_21 ,
V_4 -> V_22 , & V_9 , L_1 , V_6 -> V_23 ) ;
return V_24 ;
}
static int F_3 ( const struct V_25 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_26 & ~ V_27 )
return - V_28 ;
V_6 -> V_23 [ V_29 - 1 ] = '\0' ;
return 0 ;
}
static int T_1 F_4 ( void )
{
return F_5 ( & V_30 ) ;
}
static void T_2 F_6 ( void )
{
F_7 ( & V_30 ) ;
}
