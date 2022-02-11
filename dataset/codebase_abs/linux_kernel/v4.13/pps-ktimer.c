static void F_1 ( unsigned long V_1 )
{
struct V_2 V_3 ;
F_2 ( & V_3 ) ;
F_3 ( V_4 , & V_3 , V_5 , NULL ) ;
F_4 ( & V_6 , V_7 + V_8 ) ;
}
static void T_1 F_5 ( void )
{
F_6 ( V_4 -> V_9 , L_1 ) ;
F_7 ( & V_6 ) ;
F_8 ( V_4 ) ;
}
static int T_2 F_9 ( void )
{
V_4 = F_10 ( & V_10 ,
V_5 | V_11 ) ;
if ( V_4 == NULL ) {
F_11 ( L_2 ) ;
return - V_12 ;
}
F_12 ( & V_6 , F_1 , 0 ) ;
F_4 ( & V_6 , V_7 + V_8 ) ;
F_6 ( V_4 -> V_9 , L_3 ) ;
return 0 ;
}
