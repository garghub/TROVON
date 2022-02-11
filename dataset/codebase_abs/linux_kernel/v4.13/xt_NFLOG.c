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
V_10 . V_12 . V_13 . V_19 = 0 ;
if ( V_6 -> V_19 & V_20 )
V_10 . V_12 . V_13 . V_19 |= V_21 ;
F_3 ( V_8 , F_4 ( V_4 ) , F_5 ( V_4 ) , V_2 ,
F_6 ( V_4 ) , F_7 ( V_4 ) , & V_10 , V_6 -> V_22 ) ;
return V_23 ;
}
static int F_8 ( const struct V_24 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_19 & ~ V_25 )
return - V_26 ;
if ( V_6 -> V_22 [ sizeof( V_6 -> V_22 ) - 1 ] != '\0' )
return - V_26 ;
return 0 ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_27 ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_27 ) ;
}
