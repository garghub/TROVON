static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
void T_2 * V_4 ;
void T_2 * V_5 ;
V_4 = F_2 ( V_6 , V_7 ) ;
if ( ! V_4 )
return - V_8 ;
V_5 = V_4 + V_9 ;
V_3 = F_3 ( V_5 + V_10 ) ;
V_3 &= ~ V_11 ;
V_3 |= V_12 ;
F_4 ( V_3 , V_5 + V_10 ) ;
F_5 ( V_4 ) ;
F_6 ( 10 ) ;
return F_7 ( 0 , V_13 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
T_1 V_3 ;
void T_2 * V_4 ;
void T_2 * V_5 ;
V_4 = F_2 ( V_6 , V_7 ) ;
if ( ! V_4 )
return - V_8 ;
V_5 = V_4 + V_9 ;
V_3 = F_3 ( V_5 + V_14 ) ;
F_4 ( V_3 | V_15 , V_5 + V_14 ) ;
F_5 ( V_4 ) ;
F_6 ( 10 ) ;
return F_7 ( 1 , V_16 |
V_17 ) ;
}
static int T_3 F_9 ( char * V_18 )
{
if ( ! strcmp ( V_18 , L_1 ) )
V_19 = 1 ;
else if ( ! strcmp ( V_18 , L_2 ) )
V_19 = 0 ;
else
F_10 ( L_3
L_4 ) ;
return 0 ;
}
static void T_3 F_11 ( void )
{
F_12 () ;
F_13 ( V_20 ,
F_14 ( V_20 ) ) ;
F_15 ( 0 , & V_21 ) ;
F_16 ( & V_22 ) ;
F_17 ( V_23 , L_5 ) ;
F_18 ( V_23 ) ;
F_19 ( V_23 ) ;
F_17 ( V_24 , L_6 ) ;
F_18 ( V_24 ) ;
F_19 ( V_24 ) ;
F_17 ( V_25 , L_7 ) ;
F_18 ( V_25 ) ;
F_19 ( V_25 ) ;
F_17 ( V_26 , L_8 ) ;
F_18 ( V_26 ) ;
F_19 ( V_26 ) ;
F_20 ( NULL ) ;
F_21 ( V_27 , F_14 ( V_27 ) ) ;
F_22 ( 1 , & V_28 ) ;
F_23 ( 1 , V_29 ,
F_14 ( V_29 ) ) ;
if ( V_19 )
F_24 ( & V_30 , & V_31 ) ;
else {
F_1 ( NULL ) ;
F_24 ( & V_32 , & V_33 ) ;
}
F_24 ( & V_34 , & V_35 ) ;
#ifdef F_25
F_26 () ;
#endif
}
static void T_3 F_27 ( void )
{
F_28 ( 32768 , 24000000 , 22579200 , 0 ) ;
}
