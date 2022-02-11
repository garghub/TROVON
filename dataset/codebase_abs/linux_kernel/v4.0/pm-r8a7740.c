static int F_1 ( void )
{
return - V_1 ;
}
static int F_2 ( void )
{
return V_2 ? 0 : - V_1 ;
}
static int F_3 ( void )
{
return - V_1 ;
}
void T_1 F_4 ( void )
{
F_5 ( V_3 , F_6 ( V_3 ) ) ;
F_7 ( L_1 , L_2 ) ;
F_7 ( L_3 , L_4 ) ;
F_7 ( L_3 , L_5 ) ;
F_7 ( L_3 , L_6 ) ;
}
static int F_8 ( T_2 V_4 )
{
F_9 () ;
return 0 ;
}
static void F_10 ( void )
{
V_5 . V_6 = F_8 ;
}
static void F_10 ( void ) {}
void T_1 F_11 ( void )
{
F_10 () ;
}
