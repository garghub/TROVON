static void T_1 F_1 ( void )
{
struct V_1 * V_1 = F_2 ( NULL , 0 ,
V_2 | V_3 ,
0 , 256 , L_1 ) ;
F_3 ( V_1 == NULL ) ;
F_4 ( V_1 ) ;
F_5 () ;
}
static void T_1 F_6 ( void )
{
#ifdef F_7
struct V_4 * V_5 ;
#endif
if ( V_6 . V_7 )
V_6 . V_7 ( L_2 , 0 ) ;
#ifdef F_8
F_9 () ;
#endif
#ifdef F_7
F_10 (np, L_3 ) {
if ( F_11 ( V_5 , L_4 ) ||
F_11 ( V_5 , L_5 ) ) {
struct V_8 V_9 ;
if ( ! F_12 ( V_5 , 0 , & V_9 ) ) {
if ( ( V_9 . V_10 & 0xfffff ) == 0x8000 )
F_13 ( V_5 , 1 ) ;
else
F_13 ( V_5 , 0 ) ;
}
}
}
#endif
}
static void F_14 ( struct V_11 * V_12 )
{
T_2 V_13 , V_14 , V_15 ;
V_13 = F_15 ( V_16 ) ;
V_14 = F_15 ( V_17 ) ;
F_16 ( V_12 , L_6 ) ;
F_16 ( V_12 , L_7 , V_13 ) ;
F_16 ( V_12 , L_8 , V_14 ) ;
V_15 = F_15 ( V_18 ) ;
F_16 ( V_12 , L_9 , ( ( V_15 >> 24 ) & 0x3f ) ) ;
}
static void T_1 F_17 ( struct V_19 * V_20 )
{
unsigned int V_21 ;
if ( ! F_18 ( V_22 ) )
return;
F_19 ( & V_20 -> V_23 , L_10 ) ;
F_20 ( V_20 , 0x80 , & V_21 ) ;
F_21 ( V_20 , 0x80 , V_21 | ( 1 << 27 ) ) ;
}
static int T_1 F_22 ( void )
{
return F_23 ( F_24 () , V_24 ) ;
}
