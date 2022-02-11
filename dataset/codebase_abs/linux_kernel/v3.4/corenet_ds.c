void T_1 F_1 ( void )
{
struct V_1 * V_1 ;
unsigned int V_2 = V_3 | V_4 |
V_5 ;
if ( V_6 . V_7 == V_8 )
V_2 |= V_9 ;
V_1 = F_2 ( NULL , 0 , V_2 , 0 , 256 , L_1 ) ;
F_3 ( V_1 == NULL ) ;
F_4 ( V_1 ) ;
}
void T_1 F_5 ( void )
{
#ifdef F_6
struct V_10 * V_11 ;
struct V_12 * V_13 ;
#endif
T_2 V_14 = 0xffffffff ;
F_7 () ;
#ifdef F_6
F_8 (np, L_2 ) {
if ( F_9 ( V_11 , L_3 ) ||
F_9 ( V_11 , L_4 ) ) {
F_10 ( V_11 , 0 ) ;
V_13 = F_11 ( V_11 ) ;
V_14 = F_12 ( V_14 , V_13 -> V_15 +
V_13 -> V_16 ) ;
}
}
#ifdef F_13
F_14 () ;
#endif
#endif
#ifdef F_15
if ( F_16 () > V_14 ) {
V_17 = 1 ;
F_17 ( & V_18 ) ;
V_6 . V_19 = V_20 ;
}
#endif
F_18 ( L_5 , V_6 . V_21 ) ;
}
int T_1 F_19 ( void )
{
return F_20 ( NULL , V_22 , NULL ) ;
}
