static bool F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
V_6 = F_2 ( V_1 -> V_7 ) ;
V_5 = F_3 ( V_1 , V_6 ) ;
if ( F_4 ( ! V_5 ) )
goto V_8;
V_5 = F_5 ( V_1 , V_5 ) ;
if ( F_4 ( ! V_5 ) )
goto V_8;
if ( F_6 ( V_1 , V_5 , V_3 ) )
return false ;
return true ;
V_8:
F_7 ( V_3 ) ;
return false ;
}
static int T_1 F_8 ( void )
{
return F_9 ( & V_9 ) ;
}
static void T_2 F_10 ( void )
{
F_11 ( & V_9 ) ;
}
