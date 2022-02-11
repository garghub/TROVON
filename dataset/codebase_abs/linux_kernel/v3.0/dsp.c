static int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 = - V_4 ;
struct V_5 * V_6 = & V_7 ;
V_6 -> V_8 = F_2 () ;
if ( V_6 -> V_8 ) {
V_6 -> V_9 = V_10 ;
F_3 ( L_1 , V_11 ,
V_6 -> V_9 , V_6 -> V_8 ) ;
}
V_2 = F_4 ( L_2 , - 1 ) ;
if ( ! V_2 )
goto V_12;
V_3 = F_5 ( V_2 , V_6 , sizeof( * V_6 ) ) ;
if ( V_3 )
goto V_12;
V_3 = F_6 ( V_2 ) ;
if ( V_3 )
goto V_12;
V_13 = V_2 ;
return 0 ;
V_12:
F_7 ( V_2 ) ;
return V_3 ;
}
static void T_2 F_8 ( void )
{
F_9 ( V_13 ) ;
}
