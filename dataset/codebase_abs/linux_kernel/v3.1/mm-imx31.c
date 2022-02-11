void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
void T_1 F_4 ( void )
{
F_5 ( V_2 ) ;
F_6 ( F_7 ( V_3 ) ) ;
}
void T_1 F_8 ( void )
{
F_9 ( F_7 ( V_4 ) ) ;
}
void T_1 F_10 ( void )
{
int V_5 = F_11 () >> 4 ;
F_12 ( L_1 , 0 , V_6 , V_7 , V_8 , 0 ) ;
F_12 ( L_1 , 1 , V_9 , V_7 , V_10 , 0 ) ;
F_12 ( L_1 , 2 , V_11 , V_7 , V_12 , 0 ) ;
if ( V_5 == 1 ) {
strncpy ( V_13 . V_14 , L_2 ,
strlen ( V_13 . V_14 ) ) ;
V_13 . V_15 = & V_16 ;
}
F_13 ( L_3 , V_17 , V_18 , & V_13 ) ;
}
