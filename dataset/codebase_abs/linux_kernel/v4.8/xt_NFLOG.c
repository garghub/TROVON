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
if ( V_6 -> V_19 & V_20 )
V_9 . V_12 . V_13 . V_19 |= V_21 ;
F_2 ( V_10 , V_4 -> V_22 , V_4 -> V_23 , V_2 , V_4 -> V_24 ,
V_4 -> V_25 , & V_9 , V_6 -> V_26 ) ;
return V_27 ;
}
static int F_3 ( const struct V_28 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_19 & ~ V_29 )
return - V_30 ;
if ( V_6 -> V_26 [ sizeof( V_6 -> V_26 ) - 1 ] != '\0' )
return - V_30 ;
return 0 ;
}
static int T_1 F_4 ( void )
{
return F_5 ( & V_31 ) ;
}
static void T_2 F_6 ( void )
{
F_7 ( & V_31 ) ;
}
