static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , 0x16 ) ;
V_3 &= ~ 0x20 ;
F_3 ( V_2 , 0x16 , V_3 ) ;
return 0 ;
}
static void T_1 F_4 ( void )
{
if ( F_5 ( L_1 ) &&
F_6 ( V_4 ) ) {
F_7 ( L_2 ,
F_1 ) ;
}
F_8 ( NULL , V_5 , NULL , NULL ) ;
F_9 () ;
}
static void T_1 F_10 ( void )
{
F_11 () ;
F_12 ( V_6 , F_13 ( V_6 ) ) ;
}
