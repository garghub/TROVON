static void T_1 F_1 ( void )
{
F_2 ( V_1 , L_1 ) ;
F_3 ( V_1 ) ;
F_2 ( V_2 , L_2 ) ;
F_4 ( V_2 , 1 ) ;
}
static int F_5 ( void )
{
T_2 V_3 ;
void T_3 * V_4 , * V_5 ;
V_4 = F_6 ( V_6 , V_7 ) ;
if ( ! V_4 )
return - V_8 ;
V_5 = F_6 ( V_9 , V_7 ) ;
if ( ! V_5 ) {
F_7 ( V_4 ) ;
return - V_8 ;
}
F_8 ( 0x20001 , ( V_4 + 0x18 ) ) ;
F_8 ( 0x0 , ( V_4 + 0x1C ) ) ;
F_8 ( 0x16000202 , ( V_4 + 0x20 ) ) ;
F_8 ( 0x00000002 , ( V_4 + 0x24 ) ) ;
F_8 ( 0x16002082 , ( V_4 + 0x28 ) ) ;
F_8 ( 0x00000000 , ( V_4 + 0x2C ) ) ;
F_8 ( 0x00000000 , ( V_4 + 0x90 ) ) ;
V_3 = F_9 ( V_5 + 0x4 ) ;
V_3 &= ~ 0x3F ;
V_3 |= 0x1B ;
F_8 ( V_3 , ( V_5 + 0x4 ) ) ;
F_7 ( V_5 ) ;
F_7 ( V_4 ) ;
return 0 ;
}
void T_1 F_10 ( void )
{
F_11 ( V_10 ,
F_12 ( V_10 ) ) ;
F_5 () ;
}
static void T_1 F_13 ( void )
{
F_14 () ;
F_15 ( 0 , NULL ) ;
F_10 () ;
F_1 () ;
F_16 ( 0 , V_11 , F_12 ( V_11 ) ) ;
F_17 ( V_12 , F_12 ( V_12 ) ) ;
F_18 ( 0 , & V_13 ) ;
F_19 ( 0 , NULL ) ;
F_20 ( 1 , & V_14 ) ;
F_20 ( 2 , & V_15 ) ;
F_21 ( & V_16 ) ;
F_22 () ;
}
static void T_1 F_23 ( void )
{
F_24 ( 32768 , 24000000 , 22579200 , 0 ) ;
}
