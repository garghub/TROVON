static void T_1 F_1 ( void )
{
T_2 V_1 ;
unsigned int V_2 = 200 ;
V_1 = F_2 ( V_3 ) ;
if ( V_1 & V_4 ) {
V_1 &= ~ V_4 ;
F_3 ( V_1 , V_3 ) ;
while ( ! ( F_2 ( V_5 ) & V_6 ) ) {
V_2 -- ;
if ( ! V_2 )
break;
}
if ( ! V_2 )
F_4 ( V_7 L_1
L_2 ) ;
V_1 = F_5 ( V_8 ) ;
V_1 &= ~ ( 1 << 7 ) ;
F_6 ( V_1 , V_8 ) ;
V_1 = F_5 ( V_9 ) ;
V_1 &= ~ ( 1 << 8 ) ;
F_6 ( V_1 , V_9 ) ;
}
}
static void T_1 F_7 ( void )
{
F_8 () ;
F_1 () ;
F_4 ( V_10 L_3 ) ;
}
static void T_1 F_9 ( void )
{
if ( F_2 ( V_11 ) & 0x8000 ) {
F_4 ( V_7 L_4 ) ;
F_3 ( 0xF5 , V_11 ) ;
F_3 ( 0xA0 , V_11 ) ;
}
}
static void T_1 F_10 ( void )
{
unsigned int V_2 = 20 ;
unsigned int V_12 = 0 ;
if ( F_11 ( V_13 , L_5 ) < 0 )
goto V_14;
if ( F_11 ( V_15 , L_5 ) < 0 )
goto V_16;
if ( F_11 ( V_17 , L_5 ) < 0 )
goto V_18;
if ( F_11 ( V_19 , L_5 ) < 0 )
goto V_20;
do {
F_12 ( V_13 , 0 ) ;
} while ( ( V_12 = F_13 ( V_13 ) ) == 1 &&
-- V_2 );
if ( V_12 == 1 )
F_4 ( V_7 L_6 ) ;
F_12 ( V_15 , 0 ) ;
F_14 ( V_17 ) ;
F_14 ( V_19 ) ;
goto V_21;
V_20:
F_15 ( V_17 ) ;
V_18:
F_15 ( V_15 ) ;
V_16:
F_15 ( V_13 ) ;
V_14:
F_4 ( V_22 L_7 ) ;
V_21:
F_4 ( V_10 L_8 ) ;
}
static void T_1 F_16 ( void )
{
F_4 ( V_10 L_9 ) ;
V_23 = V_24 ;
V_25 = F_17 ( V_24 ) ;
F_18 ( V_26 , F_17 ( V_26 ) ) ;
F_9 () ;
F_10 () ;
F_19 ( & V_27 ) ;
F_20 ( V_28 ,
F_17 ( V_28 ) ) ;
F_21 ( 1 , 100 , NULL , 0 ) ;
#if F_22 ( V_29 ) || F_22 ( V_30 )
V_31 [ 0 ] = & V_32 ;
F_23 ( V_31 , 1 ) ;
#endif
}
static void T_1 F_24 ( void )
{
F_4 ( V_10 L_10 ) ;
F_25 () ;
F_26 () ;
}
