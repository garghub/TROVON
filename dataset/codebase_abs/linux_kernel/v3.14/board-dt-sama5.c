static void T_1 F_1 ( void )
{
#if F_2 ( V_1 )
F_3 ( NULL ) ;
#endif
F_4 () ;
}
static void T_1 F_5 ( void )
{
F_6 ( V_2 ) ;
}
static int F_7 ( struct V_3 * V_4 )
{
int V_5 ;
V_5 = V_6 | 0x8000 ;
F_8 ( V_4 , V_7 , V_5 ) ;
V_5 = 0xF2F4 ;
F_8 ( V_4 , V_8 , V_5 ) ;
V_5 = V_9 | 0x8000 ;
F_8 ( V_4 , V_7 , V_5 ) ;
V_5 = 0x2222 ;
F_8 ( V_4 , V_8 , V_5 ) ;
return 0 ;
}
static void T_1 F_9 ( void )
{
if ( F_10 ( L_1 ) &&
F_11 ( V_10 ) )
F_12 ( V_11 , V_12 ,
F_7 ) ;
F_13 ( NULL , V_13 , NULL , NULL ) ;
}
