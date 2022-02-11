void T_1 F_1 ( void )
{
struct V_1 * V_1 ;
struct V_2 V_3 ;
struct V_4 * V_5 = NULL ;
unsigned int V_6 = V_7 | V_8 |
V_9 | V_10 ;
V_5 = F_2 ( V_5 , L_1 ) ;
if ( V_5 == NULL ) {
F_3 ( V_11 L_2 ) ;
return;
}
if ( F_4 ( V_5 , 0 , & V_3 ) ) {
F_3 ( V_11 L_3 ) ;
F_5 ( V_5 ) ;
return;
}
if ( V_12 . V_13 == V_14 )
V_6 |= V_15 ;
V_1 = F_6 ( V_5 , V_3 . V_16 , V_6 , 0 , 256 , L_4 ) ;
F_7 ( V_1 == NULL ) ;
F_8 ( V_1 ) ;
}
void T_1 F_9 ( void )
{
#ifdef F_10
struct V_4 * V_5 ;
struct V_17 * V_18 ;
#endif
T_2 V_19 = 0xffffffff ;
#ifdef F_11
F_12 () ;
#endif
#ifdef F_10
F_13 (np, L_5 ) {
if ( F_14 ( V_5 , L_6 ) ||
F_14 ( V_5 , L_7 ) ) {
F_15 ( V_5 , 0 ) ;
V_18 = F_16 ( V_5 ) ;
V_19 = F_17 ( V_19 , V_18 -> V_20 +
V_18 -> V_21 ) ;
}
}
#ifdef F_18
F_19 () ;
#endif
#endif
#ifdef F_20
if ( F_21 () > V_19 ) {
V_22 = 1 ;
F_22 ( & V_23 ) ;
V_12 . V_24 = V_25 ;
}
#endif
F_23 ( L_8 , V_12 . V_26 ) ;
}
int T_1 F_24 ( void )
{
return F_25 ( NULL , V_27 , NULL ) ;
}
