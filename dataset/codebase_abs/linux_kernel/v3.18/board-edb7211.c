static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 ) {
F_2 ( V_4 , 1 ) ;
F_3 ( 100 ) ;
F_2 ( V_5 , 1 ) ;
} else {
F_2 ( V_5 , 0 ) ;
F_3 ( 100 ) ;
F_2 ( V_4 , 0 ) ;
}
}
static void T_1 F_4 ( void )
{
F_5 ( V_6 , V_7 ) ;
}
static void T_1
F_6 ( struct V_8 * V_9 , char * * V_10 )
{
F_7 ( 0xc0000000 , V_11 ) ;
F_7 ( 0xc1000000 , V_11 ) ;
}
static void T_1 F_8 ( void )
{
F_9 ( V_12 , F_10 ( V_12 ) ) ;
F_11 ( & V_13 ) ;
F_12 ( NULL , L_1 , 0 ,
& V_14 ,
sizeof( V_14 ) ) ;
F_13 ( L_2 , V_15 ,
& V_16 , 1 ) ;
F_14 ( V_17 , F_10 ( V_17 ) ) ;
F_12 ( & V_18 , L_3 , 0 ,
& V_19 , sizeof( V_19 ) ) ;
F_13 ( L_4 , 0 , NULL , 0 ) ;
F_13 ( L_5 , 0 , V_20 ,
F_10 ( V_20 ) ) ;
F_12 ( NULL , L_6 , 0 ,
& V_21 ,
sizeof( V_21 ) ) ;
}
