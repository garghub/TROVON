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
F_11 ( F_14 ( V_8 ) ) ;
F_12 () ;
}
void T_1 F_15 ( void )
{
F_16 ( F_6 ( V_9 ) ) ;
}
void T_1 F_17 ( void )
{
F_16 ( F_14 ( V_10 ) ) ;
}
void T_1 F_18 ( void )
{
F_19 ( F_6 ( V_11 ) ) ;
F_20 () ;
F_21 ( L_1 , 0 , V_12 , V_13 , V_14 , V_15 ) ;
F_21 ( L_1 , 1 , V_16 , V_13 , V_17 , V_18 ) ;
F_21 ( L_1 , 2 , V_19 , V_13 , V_20 , V_21 ) ;
F_21 ( L_1 , 3 , V_22 , V_13 , V_23 , V_24 ) ;
F_22 () ;
F_23 ( L_2 , V_25 , V_26 , & V_27 ) ;
F_24 ( F_6 ( V_28 ) ) ;
F_24 ( F_6 ( V_29 ) ) ;
F_25 ( L_3 , 0 , V_30 ,
F_3 ( V_30 ) ) ;
}
void T_1 F_26 ( void )
{
F_27 () ;
F_28 () ;
}
void T_1 F_29 ( void )
{
F_30 () ;
}
