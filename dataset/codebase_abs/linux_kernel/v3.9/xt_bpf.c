static int F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 V_7 ;
V_7 . V_8 = V_4 -> V_9 ;
V_7 . V_10 = (struct V_11 V_12 * ) V_4 -> V_13 ;
if ( F_2 ( & V_4 -> V_10 , & V_7 ) ) {
F_3 ( L_1 ) ;
return - V_14 ;
}
return 0 ;
}
static bool F_4 ( const struct V_15 * V_16 , struct V_17 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
return F_5 ( V_4 -> V_10 , V_16 ) ;
}
static void F_6 ( const struct V_18 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
F_7 ( V_4 -> V_10 ) ;
}
static int T_1 F_8 ( void )
{
return F_9 ( & V_19 ) ;
}
static void T_2 F_10 ( void )
{
F_11 ( & V_19 ) ;
}
