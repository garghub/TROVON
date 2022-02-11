static int F_1 ( void )
{
F_2 ( 0x0000000E , F_3 ( 0 ) ) ;
F_2 ( 0x000D0A00 , F_4 ( 0 ) ) ;
F_2 ( 0x00100A00 , F_5 ( 0 ) ) ;
F_2 ( F_6 ( F_3 ( 0 ) ) | 0x04 , F_3 ( 0 ) ) ;
return 0 ;
}
static void T_1 F_7 ( void )
{
#ifdef F_8
F_2 ( 0x000030db , F_9 ( 0 ) ) ;
F_2 ( 0x02100551 , F_10 ( 0 ) ) ;
#endif
}
static int T_1 F_11 ( void )
{
int V_1 ;
V_1 = F_12 ( 112 , L_1 ) ;
if ( V_1 )
return V_1 ;
F_13 ( 112 , 0 ) ;
F_14 ( NULL , L_2 , V_2 , V_3 , V_4 , 0 , & V_5 , 0x10180180 ) ;
return 0 ;
}
static int T_1 F_15 ( void )
{
int V_6 = 115 ;
int V_7 ;
V_7 = F_12 ( V_6 , L_3 ) ;
if ( ! V_7 ) V_7 = F_16 ( V_6 , V_8 ) ;
if ( ! V_7 ) V_7 = F_17 ( V_6 ) ;
if ( V_7 )
F_18 ( L_4 , V_7 , V_9 ) ;
return V_7 ;
}
static void T_1 F_19 ( void )
{
T_2 V_10 ;
V_10 = F_6 ( F_20 ( V_11 ) ) ;
V_10 &= V_12 ;
V_10 |= V_13 ;
F_2 ( V_10 , F_20 ( V_11 ) ) ;
F_21 ( F_20 ( V_14 ) ) ;
}
static void T_1 F_22 ( void )
{
F_23 ( V_15 , F_24 ( V_15 ) ) ;
F_25 () ;
F_7 () ;
F_26 ( V_16 ,
F_24 ( V_16 ) ) ;
F_14 ( NULL , L_5 , V_17 , V_3 , V_18 , 0 , NULL , 0 ) ;
F_14 ( NULL , L_6 , V_19 , V_3 , V_20 , 0 , NULL , 0 ) ;
F_27 ( 0 , V_21 ,
F_24 ( V_21 ) ) ;
F_27 ( 1 , V_22 ,
F_24 ( V_22 ) ) ;
F_27 ( 2 , V_23 ,
F_24 ( V_23 ) ) ;
}
