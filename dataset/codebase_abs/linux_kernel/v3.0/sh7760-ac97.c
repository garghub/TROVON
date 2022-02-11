static int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 -> V_4 ) ;
return 0 ;
}
static int T_1 F_3 ( void )
{
int V_5 ;
unsigned short V_6 ;
V_6 = F_4 ( V_7 ) ;
F_5 ( V_6 | ( 3 << 10 ) , V_7 ) ;
V_5 = - V_8 ;
V_9 = F_6 ( L_1 , - 1 ) ;
if ( ! V_9 )
goto V_10;
F_7 ( V_9 ,
& V_11 ) ;
V_5 = F_8 ( V_9 ) ;
if ( V_5 )
F_9 ( V_9 ) ;
V_10:
return V_5 ;
}
static void T_2 F_10 ( void )
{
F_11 ( V_9 ) ;
}
