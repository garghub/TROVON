static int F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
F_2 ( V_3 , 0 ) ;
return V_4 ;
}
static int F_3 ( void )
{
if ( F_4 ( V_5 , F_1 ,
0 , L_1 ) )
return 1 ;
return 0 ;
}
static void F_5 ( void )
{
F_6 ( V_5 , L_1 ) ;
F_7 () ;
}
int T_1 F_8 ( struct V_6 * V_7 )
{
V_7 -> V_8 = F_3 ;
V_7 -> V_9 = F_5 ;
V_7 -> V_10 = L_2 ;
F_9 ( V_11 L_3 ) ;
return 0 ;
}
