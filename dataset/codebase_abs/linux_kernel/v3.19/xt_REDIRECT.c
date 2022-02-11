static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
return F_2 ( V_2 , V_4 -> V_5 , V_4 -> V_6 ) ;
}
static int F_3 ( const struct V_7 * V_4 )
{
const struct V_8 * V_9 = V_4 -> V_5 ;
if ( V_9 -> V_10 & V_11 )
return - V_12 ;
return 0 ;
}
static int F_4 ( const struct V_7 * V_4 )
{
const struct V_13 * V_14 = V_4 -> V_5 ;
if ( V_14 -> V_9 [ 0 ] . V_10 & V_11 ) {
F_5 ( L_1 ) ;
return - V_12 ;
}
if ( V_14 -> V_15 != 1 ) {
F_5 ( L_2 , V_14 -> V_15 ) ;
return - V_12 ;
}
return 0 ;
}
static unsigned int
F_6 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
return F_7 ( V_2 , V_4 -> V_5 , V_4 -> V_6 ) ;
}
static int T_1 F_8 ( void )
{
return F_9 ( V_16 ,
F_10 ( V_16 ) ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( V_16 , F_10 ( V_16 ) ) ;
}
