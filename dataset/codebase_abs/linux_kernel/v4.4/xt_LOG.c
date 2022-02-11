static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 V_9 ;
struct V_10 * V_10 = V_4 -> V_10 ;
V_9 . type = V_11 ;
V_9 . V_12 . log . V_13 = V_6 -> V_13 ;
V_9 . V_12 . log . V_14 = V_6 -> V_14 ;
F_2 ( V_10 , V_4 -> V_15 , V_4 -> V_16 , V_2 , V_4 -> V_17 , V_4 -> V_18 ,
& V_9 , L_1 , V_6 -> V_19 ) ;
return V_20 ;
}
static int F_3 ( const struct V_21 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_4 -> V_15 != V_22 && V_4 -> V_15 != V_23 )
return - V_24 ;
if ( V_6 -> V_13 >= 8 ) {
F_4 ( L_2 , V_6 -> V_13 ) ;
return - V_24 ;
}
if ( V_6 -> V_19 [ sizeof( V_6 -> V_19 ) - 1 ] != '\0' ) {
F_4 ( L_3 ) ;
return - V_24 ;
}
return F_5 ( V_4 -> V_15 , V_11 ) ;
}
static void F_6 ( const struct V_25 * V_4 )
{
F_7 ( V_4 -> V_15 , V_11 ) ;
}
static int T_1 F_8 ( void )
{
return F_9 ( V_26 , F_10 ( V_26 ) ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( V_26 , F_10 ( V_26 ) ) ;
}
