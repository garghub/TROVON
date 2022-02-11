static void T_1 F_1 ( void )
{
F_2 () ;
F_3 ( V_1 ,
F_4 ( V_1 ) ) ;
F_5 () ;
F_6 () ;
F_7 ( & V_2 , L_1 , - 1 ,
& V_3 ,
sizeof( V_3 ) ) ;
F_7 ( & V_2 , L_2 , - 1 ,
& V_4 ,
sizeof( V_4 ) ) ;
F_8 ( 0 , L_3 , V_5 ,
F_4 ( V_5 ) , 3300000 ) ;
F_9 ( & V_2 , L_4 , 1 ,
V_6 , F_4 ( V_6 ) ,
& V_7 , sizeof( V_7 ) ) ;
F_9 ( & V_2 , L_5 , - 1 ,
V_8 ,
F_4 ( V_8 ) ,
& V_9 , sizeof( V_9 ) ) ;
}
static int F_10 ( struct V_10 * V_11 )
{
T_2 V_12 = F_11 ( V_11 , 0x1e ) ;
V_12 &= ~ 0xc000 ;
V_12 |= 0x4000 ;
return F_12 ( V_11 , 0x1e , V_12 ) ;
}
static void T_1 F_13 ( void )
{
F_1 () ;
F_14 ( L_6 , F_10 ) ;
}
