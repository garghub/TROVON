static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 V_9 ;
V_9 . type = V_10 ;
V_9 . V_11 . V_12 . V_13 = V_6 -> V_14 ;
V_9 . V_11 . V_12 . V_15 = V_6 -> V_15 ;
V_9 . V_11 . V_12 . V_16 = V_6 -> V_17 ;
F_2 ( V_4 -> V_18 , V_4 -> V_19 , V_2 , V_4 -> V_20 ,
V_4 -> V_21 , & V_9 , V_6 -> V_22 ) ;
return V_23 ;
}
static int F_3 ( const struct V_24 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 -> V_25 & ~ V_26 )
return - V_27 ;
if ( V_6 -> V_22 [ sizeof( V_6 -> V_22 ) - 1 ] != '\0' )
return - V_27 ;
return 0 ;
}
static int T_1 F_4 ( void )
{
return F_5 ( & V_28 ) ;
}
static void T_2 F_6 ( void )
{
F_7 ( & V_28 ) ;
}
