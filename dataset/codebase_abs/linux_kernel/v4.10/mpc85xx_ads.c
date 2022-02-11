static void T_1 F_1 ( void )
{
struct V_1 * V_1 = F_2 ( NULL , 0 , V_2 ,
0 , 256 , L_1 ) ;
F_3 ( V_1 == NULL ) ;
F_4 ( V_1 ) ;
F_5 () ;
}
static void T_1 F_6 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_7 ( V_4 ) ; V_3 ++ ) {
const struct V_5 * V_6 = & V_4 [ V_3 ] ;
F_8 ( V_6 -> V_7 , V_6 -> V_6 , V_6 -> V_8 ) ;
}
F_9 ( V_9 , V_10 , V_11 ) ;
F_9 ( V_9 , V_10 , V_12 ) ;
F_9 ( V_13 , V_14 , V_11 ) ;
F_9 ( V_13 , V_14 , V_12 ) ;
F_9 ( V_15 , V_16 , V_11 ) ;
F_9 ( V_15 , V_17 , V_12 ) ;
F_9 ( V_18 , V_19 , V_11 ) ;
F_9 ( V_18 , V_20 , V_12 ) ;
}
static void T_1 F_10 ( void )
{
if ( V_21 . V_22 )
V_21 . V_22 ( L_2 , 0 ) ;
#ifdef F_11
F_12 () ;
F_6 () ;
#endif
F_13 () ;
}
static void F_14 ( struct V_23 * V_24 )
{
T_2 V_25 , V_26 , V_27 ;
V_25 = F_15 ( V_28 ) ;
V_26 = F_15 ( V_29 ) ;
F_16 ( V_24 , L_3 ) ;
F_16 ( V_24 , L_4 , V_25 ) ;
F_16 ( V_24 , L_5 , V_26 ) ;
V_27 = F_15 ( V_30 ) ;
F_16 ( V_24 , L_6 , ( ( V_27 >> 24 ) & 0x3f ) ) ;
}
static int T_1 F_17 ( void )
{
return F_18 ( L_7 ) ;
}
