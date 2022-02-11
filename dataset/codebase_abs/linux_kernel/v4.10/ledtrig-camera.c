void F_1 ( bool V_1 )
{
enum V_2 V_3 = V_1 ? V_4 : V_5 ;
F_2 ( V_6 , V_3 ) ;
}
void F_3 ( bool V_1 )
{
enum V_2 V_3 = V_1 ? V_4 : V_5 ;
F_2 ( V_7 , V_3 ) ;
}
static int T_1 F_4 ( void )
{
F_5 ( L_1 , & V_6 ) ;
F_5 ( L_2 , & V_7 ) ;
return 0 ;
}
static void T_2 F_6 ( void )
{
F_7 ( V_7 ) ;
F_7 ( V_6 ) ;
}
