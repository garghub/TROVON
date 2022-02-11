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
int V_1 = 115 ;
int V_2 ;
V_2 = F_12 ( V_1 , L_1 ) ;
if ( ! V_2 ) V_2 = F_13 ( V_1 , V_3 ) ;
if ( ! V_2 ) V_2 = F_14 ( V_1 ) ;
if ( V_2 )
F_15 ( L_2 , V_2 , V_4 ) ;
return V_2 ;
}
static void T_1 F_16 ( void )
{
T_2 V_5 ;
V_5 = F_6 ( F_17 ( V_6 ) ) ;
V_5 &= V_7 ;
V_5 |= V_8 ;
F_2 ( V_5 , F_17 ( V_6 ) ) ;
F_18 ( F_17 ( V_9 ) ) ;
}
static void T_1 F_19 ( void )
{
int V_10 ;
F_20 () ;
F_7 () ;
F_21 ( V_11 ,
F_22 ( V_11 ) ) ;
for ( V_10 = 0 ; V_10 < F_22 ( V_12 ) ; V_10 ++ )
F_23 ( V_12 [ V_10 ] , & V_13 ) ;
}
