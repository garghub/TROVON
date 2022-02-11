static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_4 ) ;
struct V_9 V_10 ;
V_10 . type = V_11 ;
V_10 . V_12 . log . V_13 = V_6 -> V_13 ;
V_10 . V_12 . log . V_14 = V_6 -> V_14 ;
F_3 ( V_8 , F_4 ( V_4 ) , F_5 ( V_4 ) , V_2 , F_6 ( V_4 ) ,
F_7 ( V_4 ) , & V_10 , L_1 , V_6 -> V_15 ) ;
return V_16 ;
}
static int F_8 ( const struct V_17 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_4 -> V_18 != V_19 && V_4 -> V_18 != V_20 )
return - V_21 ;
if ( V_6 -> V_13 >= 8 ) {
F_9 ( L_2 , V_6 -> V_13 ) ;
return - V_21 ;
}
if ( V_6 -> V_15 [ sizeof( V_6 -> V_15 ) - 1 ] != '\0' ) {
F_9 ( L_3 ) ;
return - V_21 ;
}
return F_10 ( V_4 -> V_18 , V_11 ) ;
}
static void F_11 ( const struct V_22 * V_4 )
{
F_12 ( V_4 -> V_18 , V_11 ) ;
}
static int T_1 F_13 ( void )
{
return F_14 ( V_23 , F_15 ( V_23 ) ) ;
}
static void T_2 F_16 ( void )
{
F_17 ( V_23 , F_15 ( V_23 ) ) ;
}
