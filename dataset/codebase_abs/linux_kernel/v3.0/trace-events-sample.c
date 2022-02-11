static void F_1 ( int V_1 )
{
F_2 ( V_2 ) ;
F_3 ( V_3 ) ;
F_4 ( L_1 , V_1 ) ;
}
static int F_5 ( void * V_4 )
{
int V_1 = 0 ;
while ( ! F_6 () )
F_1 ( V_1 ++ ) ;
return 0 ;
}
static int T_1 F_7 ( void )
{
V_5 = F_8 ( F_5 , NULL , L_2 ) ;
if ( F_9 ( V_5 ) )
return - 1 ;
return 0 ;
}
static void T_2 F_10 ( void )
{
F_11 ( V_5 ) ;
}
