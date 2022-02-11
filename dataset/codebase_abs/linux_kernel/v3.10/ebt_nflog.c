static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 V_9 ;
struct V_10 * V_10 = F_2 ( V_4 -> V_11 ? V_4 -> V_11 : V_4 -> V_12 ) ;
V_9 . type = V_13 ;
V_9 . V_14 . V_15 . V_16 = V_6 -> V_17 ;
V_9 . V_14 . V_15 . V_18 = V_6 -> V_18 ;
V_9 . V_14 . V_15 . V_19 = V_6 -> V_20 ;
F_3 ( V_10 , V_21 , V_4 -> V_22 , V_2 , V_4 -> V_11 ,
V_4 -> V_12 , & V_9 , L_1 , V_6 -> V_23 ) ;
return V_24 ;
}
static int F_4 ( const struct V_25 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_26 & ~ V_27 )
return - V_28 ;
V_6 -> V_23 [ V_29 - 1 ] = '\0' ;
return 0 ;
}
static int T_1 F_5 ( void )
{
return F_6 ( & V_30 ) ;
}
static void T_2 F_7 ( void )
{
F_8 ( & V_30 ) ;
}
