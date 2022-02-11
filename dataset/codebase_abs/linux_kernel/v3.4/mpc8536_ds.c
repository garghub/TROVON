void T_1 F_1 ( void )
{
struct V_1 * V_1 = F_2 ( NULL , 0 , V_2 ,
0 , 256 , L_1 ) ;
F_3 ( V_1 == NULL ) ;
F_4 ( V_1 ) ;
}
static void T_1 F_5 ( void )
{
#ifdef F_6
struct V_3 * V_4 ;
struct V_5 * V_6 ;
#endif
T_2 V_7 = 0xffffffff ;
if ( V_8 . V_9 )
V_8 . V_9 ( L_2 , 0 ) ;
#ifdef F_6
F_7 (np, L_3 ) {
if ( F_8 ( V_4 , L_4 ) ||
F_8 ( V_4 , L_5 ) ) {
struct V_10 V_11 ;
F_9 ( V_4 , 0 , & V_11 ) ;
if ( ( V_11 . V_12 & 0xfffff ) == 0x8000 )
F_10 ( V_4 , 1 ) ;
else
F_10 ( V_4 , 0 ) ;
V_6 = F_11 ( V_4 ) ;
V_7 = F_12 ( V_7 , V_6 -> V_13 +
V_6 -> V_14 ) ;
}
}
#endif
#ifdef F_13
if ( F_14 () > V_7 ) {
V_15 = 1 ;
F_15 ( & V_16 ) ;
V_8 . V_17 = V_18 ;
}
#endif
F_16 ( L_6 ) ;
}
static int T_1 F_17 ( void )
{
unsigned long V_19 = F_18 () ;
return F_19 ( V_19 , L_7 ) ;
}
