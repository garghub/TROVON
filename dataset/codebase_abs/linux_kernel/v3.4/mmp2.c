void F_1 ( void )
{
void T_1 * V_1 ;
unsigned long V_2 ;
V_1 = V_3 + 0x1e000 + 0x2c4 ;
V_2 = F_2 ( V_1 ) ;
F_3 ( V_2 | ( 1 << 6 ) , V_1 ) ;
F_3 ( V_2 , V_1 ) ;
}
void T_2 F_4 ( void )
{
F_5 () ;
}
static void F_6 ( struct V_4 * V_4 )
{
T_3 V_5 ;
V_5 = F_2 ( V_4 -> V_5 ) ;
V_5 |= V_4 -> V_6 ;
F_3 ( V_5 , V_4 -> V_5 ) ;
}
static void F_7 ( struct V_4 * V_4 )
{
T_3 V_5 ;
V_5 = F_2 ( V_4 -> V_5 ) ;
V_5 &= ~ V_4 -> V_6 ;
F_3 ( V_5 , V_4 -> V_5 ) ;
}
static int T_2 F_8 ( void )
{
if ( F_9 () ) {
#ifdef F_10
F_11 () ;
#endif
F_12 ( V_7 ) ;
F_13 ( V_8 ) ;
F_14 ( V_9 , 16 ) ;
F_15 ( F_16 ( V_10 ) ) ;
}
return 0 ;
}
static void T_2 F_17 ( void )
{
unsigned long V_5 ;
F_3 ( V_11 | V_12 , V_13 ) ;
V_5 = V_11 | V_14 | F_18 ( 1 ) ;
F_3 ( V_5 , V_13 ) ;
F_19 ( V_15 ) ;
}
