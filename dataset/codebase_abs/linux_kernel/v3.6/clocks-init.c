static void F_1 ( void )
{
F_2 () ;
}
void F_3 ( void )
{
#ifdef F_4
F_5 ( V_1 , V_2 ) ;
F_6 ( V_3 ) ;
#else
T_1 V_4 ;
for ( V_4 = 0 ; V_4 < V_5 ; ++ V_4 ) {
struct V_6 * V_7 = V_8 [ V_4 ] ;
V_7 -> V_9 = 0 ;
}
F_1 () ;
#ifdef F_7
F_8 ( F_9 ( 0 ) ) ;
# ifdef F_10
if ( V_10 )
F_11 ( F_9 ( 10 ) | F_9 ( 11 ) ) ;
else
F_11 ( V_11 ) ;
# endif
# ifdef F_12
F_13 ( V_11 ) ;
# endif
#else
F_14 ( F_9 ( 0 ) ) ;
#endif
F_1 () ;
#ifdef F_15
F_16 ( F_17 () | V_12 ) ;
F_1 () ;
#endif
#ifdef F_18
F_19 ( V_13 , F_20 () | F_18 ) ;
F_1 () ;
__asm__ __volatile__("IDLE;");
#endif
F_21 ( 0x300 ) ;
F_1 () ;
F_19 ( V_14 , V_15 ) ;
__asm__ __volatile__("IDLE;");
F_22 ( V_16 | V_17 ) ;
#ifdef F_15
F_23 ( V_18 ) ;
F_16 ( ( F_17 () & V_19 ) | V_20 ) ;
#else
F_24 ( F_25 () & ~ ( V_21 ) ) ;
F_1 () ;
F_24 ( F_25 () | 0x1 ) ;
F_26 ( V_22 ) ;
F_27 ( V_23 ) ;
F_28 ( V_24 ) ;
#ifdef F_29
F_30 ( F_29 ) ;
#endif
#endif
#endif
F_1 () ;
F_31 ( 0 ) ;
}
