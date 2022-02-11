static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 , 1 ) ;
F_3 ( & V_4 ) ;
}
struct V_5 * F_4 ( void )
{
struct V_5 * V_6 = & V_7 . V_6 ;
F_5 ( V_6 == NULL ) ;
return V_6 ;
}
static int T_1 F_6 ( void )
{
int V_8 ;
V_8 = F_7 ( & V_7 , L_1 ) ;
if ( F_8 ( V_8 != 0 ) )
return V_8 ;
F_2 ( & V_3 , 0 ) ;
V_8 = F_9 ( & V_7 ) ;
if ( F_8 ( V_8 != 0 ) )
goto V_9;
return 0 ;
V_9:
F_2 ( & V_3 , 1 ) ;
F_3 ( & V_4 ) ;
return V_8 ;
}
static void T_2 F_10 ( void )
{
F_11 ( & V_7 ) ;
F_12 ( V_4 , F_13 ( & V_3 ) == 1 ) ;
}
