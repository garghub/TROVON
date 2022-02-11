static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_2 ( L_1 ) ;
V_6 = F_3 ( sizeof( * V_6 ) , V_7 ) ;
if ( ! V_6 )
return - V_8 ;
V_4 -> V_9 = V_6 ;
F_4 ( & V_6 -> V_10 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_9 ;
F_6 ( V_6 ) ;
}
static int T_1 F_7 ( void )
{
V_11 . V_12 = V_13 ;
F_8 () ;
return F_9 ( & V_11 , & V_14 ) ;
}
static void T_2 F_10 ( void )
{
F_11 ( & V_11 , & V_14 ) ;
}
