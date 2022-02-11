void F_1 ( void )
{
unsigned long V_1 , V_2 ;
V_1 = V_3 + 0x1e000 + 0x2c4 ;
V_2 = F_2 ( V_1 ) ;
F_3 ( V_2 | ( 1 << 6 ) , V_1 ) ;
F_3 ( V_2 , V_1 ) ;
}
static void T_1 F_4 ( void )
{
int V_4 ;
F_3 ( V_5 | V_6 , V_7 ) ;
for ( V_4 = 0 ; V_4 < 6 ; V_4 ++ )
F_3 ( 0xffffffff , F_5 ( V_4 ) ) ;
F_6 ( V_8 , 0 , 167 , NULL ) ;
}
void T_1 F_7 ( void )
{
F_8 () ;
F_4 () ;
}
static void F_9 ( struct V_9 * V_9 )
{
T_2 V_10 ;
V_10 = F_2 ( V_9 -> V_10 ) ;
V_10 |= V_9 -> V_11 ;
F_3 ( V_10 , V_9 -> V_10 ) ;
}
static void F_10 ( struct V_9 * V_9 )
{
T_2 V_10 ;
V_10 = F_2 ( V_9 -> V_10 ) ;
V_10 &= ~ V_9 -> V_11 ;
F_3 ( V_10 , V_9 -> V_10 ) ;
}
static int T_1 F_11 ( void )
{
if ( F_12 () ) {
#ifdef F_13
F_14 () ;
#endif
F_15 ( V_12 ) ;
F_16 ( V_13 ) ;
F_17 ( V_14 , 16 ) ;
F_18 ( F_19 ( V_15 ) ) ;
}
return 0 ;
}
static void T_1 F_20 ( void )
{
unsigned long V_10 ;
F_3 ( V_5 | V_16 , V_17 ) ;
V_10 = V_5 | V_6 | F_21 ( 1 ) ;
F_3 ( V_10 , V_17 ) ;
F_22 ( V_18 ) ;
}
