static T_1 F_1 ( unsigned int V_1 )
{
return F_2 ( F_3 () , V_1 ) ;
}
static bool F_4 ( struct V_2 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
V_7 = F_1 ( V_2 -> V_8 ) ;
V_6 = F_5 ( V_2 , V_7 ) ;
if ( F_6 ( ! V_6 ) )
goto V_9;
V_6 = F_7 ( V_2 , V_6 ) ;
if ( F_6 ( ! V_6 ) )
goto V_9;
if ( F_8 ( V_2 , V_6 , V_4 ) )
return false ;
return true ;
V_9:
F_9 ( V_4 ) ;
return false ;
}
static int T_2 F_10 ( void )
{
return F_11 ( & V_10 ) ;
}
static void T_3 F_12 ( void )
{
F_13 ( & V_10 ) ;
}
