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
static void F_4 ( int V_6 )
{
F_2 ( V_7 , ! ! V_6 ) ;
F_5 ( ( F_6 ( V_8 ) & 0xf0ff ) | ( V_6 << 8 ) , V_8 ) ;
}
static void T_1 F_7 ( void )
{
F_8 ( V_9 , V_10 ) ;
}
static void T_1
F_9 ( struct V_11 * V_12 , char * * V_13 )
{
F_10 ( 0xc0000000 , V_14 ) ;
F_10 ( 0xc1000000 , V_14 ) ;
}
static void T_1 F_11 ( void )
{
F_12 () ;
}
static void T_1 F_13 ( void )
{
F_14 ( V_15 , F_15 ( V_15 ) ) ;
F_16 ( & V_16 ) ;
F_17 ( & V_17 , L_1 , 0 ,
& V_18 ,
sizeof( V_18 ) ) ;
F_17 ( & V_17 , L_2 , 0 ,
& V_19 ,
sizeof( V_19 ) ) ;
F_18 ( L_3 , 0 , NULL , 0 ) ;
F_18 ( L_4 , 0 , V_20 ,
F_15 ( V_20 ) ) ;
F_17 ( & V_17 , L_5 , 0 ,
& V_21 ,
sizeof( V_21 ) ) ;
}
