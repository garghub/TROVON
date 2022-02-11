static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( & V_2 -> V_4 ) ;
V_3 = F_3 ( V_2 -> V_4 . V_5 , NULL , NULL , & V_2 -> V_4 ) ;
if ( V_3 )
goto V_6;
return 0 ;
V_6:
F_4 ( & V_2 -> V_4 ) ;
return V_3 ;
}
static int T_1 F_5 ( void )
{
return F_6 ( & V_7 ) ;
}
