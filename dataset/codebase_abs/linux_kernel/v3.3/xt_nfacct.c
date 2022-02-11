static bool F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
F_2 ( V_2 , V_6 -> V_8 ) ;
return true ;
}
static int
F_3 ( const struct V_9 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_10 ;
struct V_11 * V_8 ;
V_8 = F_4 ( V_6 -> V_12 ) ;
if ( V_8 == NULL ) {
F_5 ( L_1
L_2 , V_6 -> V_12 ) ;
return - V_13 ;
}
V_6 -> V_8 = V_8 ;
return 0 ;
}
static void
F_6 ( const struct V_14 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_10 ;
F_7 ( V_6 -> V_8 ) ;
}
static int T_1 F_8 ( void )
{
return F_9 ( & V_15 ) ;
}
static void T_2 F_10 ( void )
{
F_11 ( & V_15 ) ;
}
