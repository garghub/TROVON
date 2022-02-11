void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
void T_1 F_4 ( void )
{
F_5 ( V_2 ,
F_3 ( V_2 ) ) ;
}
static int F_6 ( struct V_3 * V_4 )
{
if ( F_7 ( V_5 ) )
return F_8 ( V_5 ) ;
F_9 ( & V_4 -> V_6 ) ;
F_10 ( & V_4 -> V_6 ) ;
F_11 ( V_5 ) ;
return 0 ;
}
static void F_12 ( struct V_3 * V_4 )
{
if ( F_7 ( V_5 ) )
return;
F_13 ( V_5 ) ;
F_14 ( & V_4 -> V_6 ) ;
F_15 ( & V_4 -> V_6 ) ;
}
static int F_16 ( struct V_7 * V_8 )
{
F_17 ( 0x00ff0040 , V_8 -> V_9 + 0x0094 ) ;
F_17 ( 0x00000001 , V_8 -> V_9 + 0x009C ) ;
return 0 ;
}
void T_1 F_18 ( void )
{
#ifdef F_19
F_20 ( F_21 ( 0xf0100000 ) , 0x40470000 , 0x82000fff ) ;
#endif
F_22 () ;
F_23 () ;
F_5 ( V_10 ,
F_3 ( V_10 ) ) ;
F_5 ( V_11 ,
F_3 ( V_11 ) ) ;
}
void T_1 F_24 ( struct V_12 * V_13 )
{
F_25 ( & V_14 , L_1 , - 1 ,
V_15 ,
F_3 ( V_15 ) ,
V_13 , sizeof( * V_13 ) ) ;
}
void T_1 F_26 ( struct V_16 * V_13 )
{
F_25 ( & V_14 , L_2 , - 1 ,
V_17 ,
F_3 ( V_17 ) ,
V_13 , sizeof( * V_13 ) ) ;
}
void T_1 __weak F_27 ( void ) { }
void T_1 F_28 ( void )
{
F_29 () ;
F_30 () ;
F_27 () ;
}
void T_1 F_31 ( void )
{
F_32 ( V_10 ,
F_3 ( V_10 ) ) ;
}
void T_1 F_33 ( void )
{
V_5 = F_34 ( V_18 ) ;
F_35 () ;
F_5 ( V_19 ,
F_3 ( V_19 ) ) ;
}
void T_1 F_36 ( void )
{
F_37 ( 1000 , 2 , 4 ) ;
}
void T_1 F_38 ( void )
{
F_29 () ;
F_5 ( V_10 ,
F_3 ( V_10 ) ) ;
F_39 ( NULL , V_20 ,
V_21 , NULL ) ;
}
