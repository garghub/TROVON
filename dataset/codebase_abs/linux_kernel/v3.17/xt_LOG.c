static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 V_9 ;
struct V_10 * V_10 = F_2 ( V_4 -> V_11 ? V_4 -> V_11 : V_4 -> V_12 ) ;
V_9 . type = V_13 ;
V_9 . V_14 . log . V_15 = V_6 -> V_15 ;
V_9 . V_14 . log . V_16 = V_6 -> V_16 ;
F_3 ( V_10 , V_4 -> V_17 , V_4 -> V_18 , V_2 , V_4 -> V_11 , V_4 -> V_12 ,
& V_9 , L_1 , V_6 -> V_19 ) ;
return V_20 ;
}
static int F_4 ( const struct V_21 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_4 -> V_17 != V_22 && V_4 -> V_17 != V_23 )
return - V_24 ;
if ( V_6 -> V_15 >= 8 ) {
F_5 ( L_2 , V_6 -> V_15 ) ;
return - V_24 ;
}
if ( V_6 -> V_19 [ sizeof( V_6 -> V_19 ) - 1 ] != '\0' ) {
F_5 ( L_3 ) ;
return - V_24 ;
}
return F_6 ( V_4 -> V_17 , V_13 ) ;
}
static void F_7 ( const struct V_25 * V_4 )
{
F_8 ( V_4 -> V_17 , V_13 ) ;
}
static int T_1 F_9 ( void )
{
return F_10 ( V_26 , F_11 ( V_26 ) ) ;
}
static void T_2 F_12 ( void )
{
F_13 ( V_26 , F_11 ( V_26 ) ) ;
}
