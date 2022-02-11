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
F_4 ( L_1 ) ;
V_1 = F_5 ( V_7 ) ;
V_1 &= ~ ( 1 << 7 ) ;
F_6 ( V_1 , V_7 ) ;
V_1 = F_5 ( V_8 ) ;
V_1 &= ~ ( 1 << 8 ) ;
F_6 ( V_1 , V_8 ) ;
}
}
static void T_1 F_7 ( void )
{
F_8 () ;
F_1 () ;
F_9 ( V_9 L_2 ) ;
}
static void T_1 F_10 ( void )
{
if ( F_2 ( V_10 ) & 0x8000 ) {
F_9 ( V_11 L_3 ) ;
F_3 ( 0xF5 , V_10 ) ;
F_3 ( 0xA0 , V_10 ) ;
}
}
static void T_1 F_11 ( void )
{
unsigned int V_2 = 20 ;
unsigned int V_12 = 0 ;
if ( F_12 ( V_13 , L_4 ) < 0 )
goto V_14;
if ( F_12 ( V_15 , L_4 ) < 0 )
goto V_16;
if ( F_12 ( V_17 , L_4 ) < 0 )
goto V_18;
if ( F_12 ( V_19 , L_4 ) < 0 )
goto V_20;
do {
F_13 ( V_13 , 0 ) ;
} while ( ( V_12 = F_14 ( V_13 ) ) == 1 &&
-- V_2 );
if ( V_12 == 1 )
F_9 ( V_11 L_5 ) ;
F_13 ( V_15 , 0 ) ;
F_15 ( V_17 ) ;
F_15 ( V_19 ) ;
goto V_21;
V_20:
F_16 ( V_17 ) ;
V_18:
F_16 ( V_15 ) ;
V_16:
F_16 ( V_13 ) ;
V_14:
F_9 ( V_22 L_6 ) ;
V_21:
F_9 ( V_9 L_7 ) ;
}
static void T_1 F_17 ( void )
{
F_9 ( V_9 L_8 ) ;
V_23 [ 0 ] . V_24 = F_18 ( V_25 ) ;
V_23 [ 0 ] . V_26 = F_18 ( V_25 ) ;
F_19 ( V_27 , F_20 ( V_27 ) ) ;
F_10 () ;
F_11 () ;
F_21 ( & V_28 ) ;
V_29 [ 0 ] . V_30 = F_18 ( V_31 ) ;
F_22 ( V_29 ,
F_20 ( V_29 ) ) ;
F_23 ( 1 , 100 , NULL , 0 ) ;
#if F_24 ( V_32 ) || F_24 ( V_33 )
V_34 [ 0 ] = & V_35 ;
F_25 ( V_34 , 1 ) ;
#endif
F_26 ( & V_36 ) ;
}
