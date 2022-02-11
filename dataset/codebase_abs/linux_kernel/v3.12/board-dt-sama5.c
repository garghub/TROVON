static void T_1 F_1 ( void )
{
F_2 ( V_1 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
int V_4 ;
V_4 = V_5 | 0x8000 ;
F_4 ( V_3 , V_6 , V_4 ) ;
V_4 = 0xF2F4 ;
F_4 ( V_3 , V_7 , V_4 ) ;
V_4 = V_8 | 0x8000 ;
F_4 ( V_3 , V_6 , V_4 ) ;
V_4 = 0x2222 ;
F_4 ( V_3 , V_7 , V_4 ) ;
return 0 ;
}
static void T_1 F_5 ( void )
{
if ( F_6 ( L_1 ) &&
F_7 ( V_9 ) )
F_8 ( V_10 , V_11 ,
F_3 ) ;
F_9 ( NULL , V_12 , NULL , NULL ) ;
}
