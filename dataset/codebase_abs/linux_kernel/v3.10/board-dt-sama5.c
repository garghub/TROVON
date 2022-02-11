static void T_1 F_1 ( void )
{
F_2 ( V_1 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
int V_4 ;
#define F_4 260
#define F_5 261
#define F_6 11
#define F_7 12
V_4 = F_4 | 0x8000 ;
F_8 ( V_3 , F_6 , V_4 ) ;
V_4 = 0xF2F4 ;
F_8 ( V_3 , F_7 , V_4 ) ;
V_4 = F_5 | 0x8000 ;
F_8 ( V_3 , F_6 , V_4 ) ;
V_4 = 0x2222 ;
F_8 ( V_3 , F_7 , V_4 ) ;
return 0 ;
}
static void T_1 F_9 ( void )
{
if ( F_10 ( L_1 ) )
F_11 ( V_5 , V_6 ,
F_3 ) ;
F_12 ( NULL , V_7 , NULL , NULL ) ;
}
