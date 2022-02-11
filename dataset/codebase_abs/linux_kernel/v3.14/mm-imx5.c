void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
void T_1 F_4 ( void )
{
F_2 ( V_2 , F_3 ( V_2 ) ) ;
}
static void T_1 F_5 ( void )
{
void T_2 * V_3 ;
V_3 = F_6 ( V_4 ) ;
F_7 ( 0xf00 , V_3 ) ;
F_7 ( F_8 ( V_3 + 0x800 ) | 0x30ff ,
V_3 + 0x800 ) ;
}
void T_1 F_9 ( void )
{
F_5 () ;
F_10 ( V_5 ) ;
F_11 ( F_6 ( V_6 ) ) ;
F_12 () ;
}
void T_1 F_13 ( void )
{
F_10 ( V_7 ) ;
F_12 () ;
}
void T_1 F_14 ( void )
{
F_15 ( F_6 ( V_8 ) ) ;
}
void T_1 F_16 ( void )
{
struct V_9 * V_10 ;
void T_2 * V_11 ;
V_10 = F_17 ( NULL , NULL , L_1 ) ;
V_11 = F_18 ( V_10 , 0 ) ;
F_19 ( ! V_11 ) ;
F_15 ( V_11 ) ;
}
void T_1 F_20 ( void )
{
F_21 ( F_6 ( V_12 ) ) ;
F_22 () ;
F_23 ( L_2 , 0 , V_13 , V_14 , V_15 , V_16 ) ;
F_23 ( L_2 , 1 , V_17 , V_14 , V_18 , V_19 ) ;
F_23 ( L_2 , 2 , V_20 , V_14 , V_21 , V_22 ) ;
F_23 ( L_2 , 3 , V_23 , V_14 , V_24 , V_25 ) ;
F_24 () ;
F_25 ( L_3 , V_26 , V_27 , & V_28 ) ;
F_26 ( F_6 ( V_29 ) ) ;
F_26 ( F_6 ( V_30 ) ) ;
F_27 ( L_4 , 0 , V_31 ,
F_3 ( V_31 ) ) ;
}
void T_1 F_28 ( void )
{
F_29 () ;
F_30 () ;
}
void T_1 F_31 ( void )
{
F_30 () ;
}
