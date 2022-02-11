static bool F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
const struct V_6 * V_7 = V_4 -> V_8 ;
F_2 ( V_2 , V_7 -> V_9 ) ;
V_5 = F_3 ( V_2 , V_7 -> V_9 ) ;
return V_5 == V_10 ? false : true ;
}
static int
F_4 ( const struct V_11 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_12 ;
struct V_13 * V_9 ;
V_9 = F_5 ( V_4 -> V_14 , V_7 -> V_15 ) ;
if ( V_9 == NULL ) {
F_6 ( L_1
L_2 , V_7 -> V_15 ) ;
return - V_16 ;
}
V_7 -> V_9 = V_9 ;
return 0 ;
}
static void
F_7 ( const struct V_17 * V_4 )
{
const struct V_6 * V_7 = V_4 -> V_12 ;
F_8 ( V_7 -> V_9 ) ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_18 ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_18 ) ;
}
