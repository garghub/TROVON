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
void T_1 F_7 ( void )
{
F_8 () ;
F_9 ( V_9 , F_10 ( V_9 ) ) ;
}
static void T_1 F_11 ( void )
{
F_12 ( V_10 , V_11 ) ;
}
static void T_1
F_13 ( struct V_12 * V_13 , char * * V_14 , struct V_15 * V_16 )
{
V_16 -> V_17 [ 0 ] . V_18 = 0xc0000000 ;
V_16 -> V_17 [ 0 ] . V_19 = V_20 ;
V_16 -> V_17 [ 1 ] . V_18 = 0xc1000000 ;
V_16 -> V_17 [ 1 ] . V_19 = V_20 ;
V_16 -> V_21 = 2 ;
}
static void T_1 F_14 ( void )
{
F_15 () ;
}
static void T_1 F_16 ( void )
{
F_17 ( V_22 , F_10 ( V_22 ) ) ;
F_18 ( & V_23 ) ;
F_19 ( & V_24 , L_1 , 0 ,
& V_25 ,
sizeof( V_25 ) ) ;
F_19 ( & V_24 , L_2 , 0 ,
& V_26 ,
sizeof( V_26 ) ) ;
F_20 ( L_3 , 0 , NULL , 0 ) ;
F_20 ( L_4 , 0 , V_27 ,
F_10 ( V_27 ) ) ;
F_19 ( & V_24 , L_5 , 0 ,
& V_28 ,
sizeof( V_28 ) ) ;
}
