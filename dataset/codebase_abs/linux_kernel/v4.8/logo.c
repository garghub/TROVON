static int T_1 F_1 ( void )
{
V_1 = true ;
return 0 ;
}
const struct V_2 * T_2 F_2 ( int V_3 )
{
const struct V_2 * V_4 = NULL ;
if ( V_5 || V_1 )
return NULL ;
if ( V_3 >= 1 ) {
#ifdef F_3
V_4 = & V_6 ;
#endif
#ifdef F_4
V_4 = & V_7 ;
#endif
}
if ( V_3 >= 4 ) {
#ifdef F_5
V_4 = & V_8 ;
#endif
#ifdef F_6
V_4 = & V_9 ;
#endif
#ifdef F_7
V_4 = & V_10 ;
#endif
}
if ( V_3 >= 8 ) {
#ifdef F_8
V_4 = & V_11 ;
#endif
#ifdef F_9
V_4 = & V_12 ;
#endif
#ifdef F_10
V_4 = & V_13 ;
#endif
#ifdef F_11
if ( V_14 )
V_4 = & V_15 ;
#endif
#ifdef F_12
V_4 = & V_16 ;
#endif
#ifdef F_13
V_4 = & V_17 ;
#endif
#ifdef F_14
V_4 = & V_18 ;
#endif
#ifdef F_15
V_4 = & V_19 ;
#endif
#ifdef F_16
V_4 = & V_20 ;
#endif
}
return V_4 ;
}
