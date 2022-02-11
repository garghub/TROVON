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
F_2 ( V_7 , V_6 ) ;
}
void T_1 F_5 ( void )
{
F_6 () ;
F_7 ( V_8 , F_8 ( V_8 ) ) ;
}
static void T_1 F_9 ( void )
{
F_10 ( V_9 , V_10 ) ;
}
static void T_1
F_11 ( struct V_11 * V_12 , char * * V_13 , struct V_14 * V_15 )
{
V_15 -> V_16 [ 0 ] . V_17 = 0xc0000000 ;
V_15 -> V_16 [ 0 ] . V_18 = V_19 ;
V_15 -> V_16 [ 1 ] . V_17 = 0xc1000000 ;
V_15 -> V_16 [ 1 ] . V_18 = V_19 ;
V_15 -> V_20 = 2 ;
}
static void T_1 F_12 ( void )
{
F_13 ( V_21 , F_8 ( V_21 ) ) ;
F_14 ( & V_22 ) ;
F_15 ( & V_23 , L_1 , 0 ,
& V_24 ,
sizeof( V_24 ) ) ;
F_15 ( & V_23 , L_2 , 0 ,
& V_25 ,
sizeof( V_25 ) ) ;
F_16 ( L_3 , 0 , NULL , 0 ) ;
F_16 ( L_4 , 0 , V_26 ,
F_8 ( V_26 ) ) ;
}
