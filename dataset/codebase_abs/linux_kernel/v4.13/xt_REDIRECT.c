static unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
return F_2 ( V_2 , V_4 -> V_5 , F_3 ( V_4 ) ) ;
}
static int F_4 ( const struct V_6 * V_4 )
{
const struct V_7 * V_8 = V_4 -> V_5 ;
if ( V_8 -> V_9 & V_10 )
return - V_11 ;
return F_5 ( V_4 -> V_12 , V_4 -> V_13 ) ;
}
static void F_6 ( const struct V_14 * V_4 )
{
F_7 ( V_4 -> V_12 , V_4 -> V_13 ) ;
}
static int F_8 ( const struct V_6 * V_4 )
{
const struct V_15 * V_16 = V_4 -> V_5 ;
if ( V_16 -> V_8 [ 0 ] . V_9 & V_10 ) {
F_9 ( L_1 ) ;
return - V_11 ;
}
if ( V_16 -> V_17 != 1 ) {
F_9 ( L_2 , V_16 -> V_17 ) ;
return - V_11 ;
}
return F_5 ( V_4 -> V_12 , V_4 -> V_13 ) ;
}
static unsigned int
F_10 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
return F_11 ( V_2 , V_4 -> V_5 , F_3 ( V_4 ) ) ;
}
static int T_1 F_12 ( void )
{
return F_13 ( V_18 ,
F_14 ( V_18 ) ) ;
}
static void T_2 F_15 ( void )
{
F_16 ( V_18 , F_14 ( V_18 ) ) ;
}
