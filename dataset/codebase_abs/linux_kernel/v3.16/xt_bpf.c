static int F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 V_7 ;
V_7 . V_8 = V_4 -> V_9 ;
V_7 . V_10 = V_4 -> V_11 ;
if ( F_2 ( & V_4 -> V_10 , & V_7 ) ) {
F_3 ( L_1 ) ;
return - V_12 ;
}
return 0 ;
}
static bool F_4 ( const struct V_13 * V_14 , struct V_15 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
return F_5 ( V_4 -> V_10 , V_14 ) ;
}
static void F_6 ( const struct V_16 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
F_7 ( V_4 -> V_10 ) ;
}
static int T_1 F_8 ( void )
{
return F_9 ( & V_17 ) ;
}
static void T_2 F_10 ( void )
{
F_11 ( & V_17 ) ;
}
