static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( V_2 , NULL ) ;
return 0 ;
}
static int F_3 ( struct V_4 * V_4 , struct V_5 * V_6 )
{
return F_4 ( V_6 , F_1 , NULL ) ;
}
static int T_1 F_5 ( void )
{
V_7 = F_6 ( L_1 , V_8 , NULL , NULL ,
& V_9 ) ;
if ( ! V_7 )
return - V_10 ;
return 0 ;
}
static void T_2 F_7 ( void )
{
F_8 ( V_7 ) ;
}
