void
F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_1 , V_6 ) ;
F_3 ( & V_7 ) ;
F_4 ( & V_3 -> V_8 , V_5 ) ;
F_5 ( & V_7 ) ;
}
void
F_6 ( struct V_2 * V_3 )
{
F_3 ( & V_7 ) ;
F_7 ( & V_3 -> V_8 ) ;
F_5 ( & V_7 ) ;
}
int
F_8 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_2 ( V_1 , V_6 ) ;
return ! F_9 ( V_5 ) ;
}
static int T_1
F_10 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_2 ( V_1 , V_6 ) ;
F_11 ( V_5 ) ;
return 0 ;
}
static void T_2
F_12 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = F_2 ( V_1 , V_6 ) ;
F_13 ( ! F_9 ( V_5 ) ) ;
}
static int T_3
F_14 ( void )
{
return F_15 ( & V_9 ) ;
}
static void T_4
F_16 ( void )
{
F_17 ( & V_9 ) ;
}
