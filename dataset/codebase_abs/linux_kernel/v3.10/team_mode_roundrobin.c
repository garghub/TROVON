static struct V_1 * V_1 ( struct V_2 * V_2 )
{
return (struct V_1 * ) & V_2 -> V_3 ;
}
static bool F_1 ( struct V_2 * V_2 , struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int V_8 ;
V_8 = V_1 ( V_2 ) -> V_9 ++ % V_2 -> V_10 ;
V_7 = F_2 ( V_2 , V_8 ) ;
if ( F_3 ( ! V_7 ) )
goto V_11;
V_7 = F_4 ( V_2 , V_7 ) ;
if ( F_3 ( ! V_7 ) )
goto V_11;
if ( F_5 ( V_2 , V_7 , V_5 ) )
return false ;
return true ;
V_11:
F_6 ( V_5 ) ;
return false ;
}
static int T_1 F_7 ( void )
{
return F_8 ( & V_12 ) ;
}
static void T_2 F_9 ( void )
{
F_10 ( & V_12 ) ;
}
