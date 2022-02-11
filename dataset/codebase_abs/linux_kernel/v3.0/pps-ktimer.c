static void F_1 ( unsigned long V_1 )
{
struct V_2 V_3 ;
F_2 ( & V_3 ) ;
F_3 ( V_4 , & V_3 , V_5 , NULL ) ;
F_4 ( & V_6 , V_7 + V_8 ) ;
}
static void F_5 ( struct V_9 * V_4 , int V_10 , void * V_11 )
{
F_6 ( V_4 -> V_12 , L_1 ,
V_10 & V_5 ? L_2 : L_3 ,
V_10 & V_13 ? L_4 : L_3 ) ;
}
static void T_1 F_7 ( void )
{
F_6 ( V_4 -> V_12 , L_5 ) ;
F_8 ( & V_6 ) ;
F_9 ( V_4 ) ;
}
static int T_2 F_10 ( void )
{
V_4 = F_11 ( & V_14 ,
V_5 | V_15 ) ;
if ( V_4 == NULL ) {
F_12 ( L_6 ) ;
return - V_16 ;
}
F_13 ( & V_6 , F_1 , 0 ) ;
F_4 ( & V_6 , V_7 + V_8 ) ;
F_6 ( V_4 -> V_12 , L_7 ) ;
return 0 ;
}
