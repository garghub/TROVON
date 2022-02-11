static void F_1 ( void )
{
F_2 () ;
}
void F_3 ( void )
{
#ifdef F_4
int V_1 , V_2 , V_3 ;
F_5 ( V_4 , V_5 ) ;
F_5 ( V_6 , V_7 ) ;
while ( ( F_6 ( V_8 ) & 0x8 ) || ! ( F_6 ( V_8 ) & 0x4 ) )
continue;
F_5 ( V_4 , V_5 | ( 1 << V_9 ) ) ;
while ( F_6 ( V_8 ) & ( 1 << 3 ) )
continue;
for ( V_1 = 0 ; V_1 < 7 ; V_1 ++ ) {
if ( V_10 [ V_1 ] . V_11 == V_12 ) {
F_7 ( V_10 [ V_1 ] . V_13 ) ;
F_8 ( V_10 [ V_1 ] . V_14 ) ;
F_9 ( V_10 [ V_1 ] . V_15 ) ;
F_10 ( V_10 [ V_1 ] . V_16 ) ;
F_11 ( V_10 [ V_1 ] . V_17 ) ;
F_12 ( V_10 [ V_1 ] . V_18 ) ;
F_13 ( V_10 [ V_1 ] . V_19 ) ;
break;
}
}
F_1 () ;
while ( ! ( F_14 () & 0x4 ) )
continue;
V_2 = ( F_14 () & 0x00f00000 ) >> 20 ;
V_3 = F_15 () ;
V_3 &= 0x0ff ;
F_16 ( V_3 | ( V_2 << 8 ) ) ;
F_1 () ;
while ( ! ( F_14 () & 0x2000 ) )
continue;
#else
T_1 V_1 ;
for ( V_1 = 0 ; V_1 < V_20 ; ++ V_1 ) {
struct V_21 * V_22 = V_23 [ V_1 ] ;
V_22 -> V_24 = 0 ;
}
F_1 () ;
#ifdef F_17
F_18 ( F_19 ( 0 ) ) ;
# ifdef F_20
if ( V_25 )
F_21 ( F_19 ( 10 ) | F_19 ( 11 ) ) ;
else
F_21 ( V_26 ) ;
# endif
# ifdef F_22
F_23 ( V_26 ) ;
# endif
#else
F_24 ( F_19 ( 0 ) ) ;
#endif
F_1 () ;
#ifdef F_25
F_26 ( F_27 () | V_27 ) ;
F_1 () ;
#endif
#ifdef F_28
F_29 ( V_28 , F_30 () | F_28 ) ;
F_1 () ;
__asm__ __volatile__("IDLE;");
#endif
F_31 ( 0x300 ) ;
F_1 () ;
F_29 ( V_29 , V_30 ) ;
__asm__ __volatile__("IDLE;");
F_32 ( V_31 | V_32 ) ;
#ifdef F_25
F_33 ( V_33 ) ;
F_26 ( ( F_27 () & V_34 ) | V_35 ) ;
#else
F_34 ( F_35 () & ~ ( V_36 ) ) ;
F_1 () ;
F_34 ( F_35 () | 0x1 ) ;
F_36 ( V_37 ) ;
F_37 ( V_38 ) ;
F_38 ( V_39 ) ;
#ifdef F_39
F_40 ( F_39 ) ;
#endif
#endif
#endif
F_1 () ;
F_41 ( 0 ) ;
}
