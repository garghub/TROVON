static void F_1 ( void )
{
F_2 () ;
}
void F_3 ( void )
{
T_1 V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
struct V_3 * V_4 = V_5 [ V_1 ] ;
V_4 -> V_6 = 0 ;
}
F_1 () ;
#ifdef F_4
F_5 ( F_6 ( 0 ) ) ;
# ifdef F_7
if ( V_7 )
F_8 ( F_6 ( 10 ) | F_6 ( 11 ) ) ;
else
F_8 ( V_8 ) ;
# endif
# ifdef F_9
F_10 ( V_8 ) ;
# endif
#else
F_11 ( F_6 ( 0 ) ) ;
#endif
F_1 () ;
#ifdef F_12
F_13 ( F_14 () | V_9 ) ;
F_1 () ;
#endif
#ifdef F_15
F_16 ( V_10 , F_17 () | F_15 ) ;
F_1 () ;
__asm__ __volatile__("IDLE;");
#endif
F_18 ( 0x300 ) ;
F_1 () ;
F_16 ( V_11 , V_12 ) ;
__asm__ __volatile__("IDLE;");
F_19 ( V_13 | V_14 ) ;
#ifdef F_12
F_20 ( V_15 ) ;
F_13 ( ( F_14 () & V_16 ) | V_17 ) ;
#else
F_21 ( F_22 () & ~ ( V_18 ) ) ;
F_1 () ;
F_21 ( F_22 () | 0x1 ) ;
F_23 ( V_19 ) ;
F_24 ( V_20 ) ;
F_25 ( V_21 ) ;
#ifdef F_26
F_27 ( F_26 ) ;
#endif
#endif
F_1 () ;
F_28 ( 0 ) ;
}
