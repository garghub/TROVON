void T_1 F_1 ( void )
{
struct V_1 * V_1 = F_2 ( NULL , 0 ,
V_2 |
V_3 | V_4 ,
0 , 256 , L_1 ) ;
F_3 ( V_1 == NULL ) ;
F_4 ( V_1 ) ;
}
static void T_1 F_5 ( void )
{
#ifdef F_6
struct V_5 * V_6 ;
struct V_7 * V_8 ;
#endif
T_2 V_9 = 0xffffffff ;
if ( V_10 . V_11 )
V_10 . V_11 ( L_2 , 0 ) ;
#ifdef F_6
F_7 (np, L_3 ) {
if ( F_8 ( V_6 , L_4 ) ||
F_8 ( V_6 , L_5 ) ) {
struct V_12 V_13 ;
F_9 ( V_6 , 0 , & V_13 ) ;
if ( ( V_13 . V_14 & 0xfffff ) == 0x8000 )
F_10 ( V_6 , 1 ) ;
else
F_10 ( V_6 , 0 ) ;
V_8 = F_11 ( V_6 ) ;
V_9 = F_12 ( V_9 , V_8 -> V_15 +
V_8 -> V_16 ) ;
}
}
#endif
#ifdef F_13
if ( F_14 () > V_9 ) {
V_17 = 1 ;
F_15 ( & V_18 ) ;
V_10 . V_19 = V_20 ;
}
#endif
F_16 ( L_6 ) ;
}
static int T_1 F_17 ( void )
{
unsigned long V_21 = F_18 () ;
return F_19 ( V_21 , L_7 ) ;
}
