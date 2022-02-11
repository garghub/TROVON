static void F_1 ( void )
{
F_2 ( V_1 ) ;
}
static void F_3 ( void )
{
F_2 ( V_2 ) ;
}
static T_1 F_4 ( int V_3 , void * V_4 )
{
return V_5 ;
}
static T_1 F_5 ( int V_3 , void * V_4 )
{
F_6 () ;
return V_5 ;
}
void T_2 F_7 ( int V_3 , struct V_6 * V_7 )
{
F_8 ( V_3 , V_7 ) ;
F_9 ( V_3 , V_8 ) ;
}
void T_2 F_10 ( void )
{
F_11 ( V_1 , F_1 ) ;
F_11 ( V_2 , F_3 ) ;
F_7 ( V_1 , & V_9 ) ;
F_7 ( V_2 , & V_10 ) ;
}
