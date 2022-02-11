int F_1 ( unsigned int V_1 )
{
int V_2 ;
F_2 (cpu) {
if ( F_3 ( V_3 , V_2 ) [ V_1 ] > V_4 )
return 1 ;
}
return 0 ;
}
void T_1 F_4 ( void )
{
struct V_5 * V_6 = V_7 -> V_6 ;
int V_8 ;
#if F_5 ( V_9 ) || F_5 ( V_10 )
F_6 () ;
#endif
V_7 -> V_11 ( 0 ) ;
for ( V_8 = 0 ; V_8 < F_7 () ; V_8 ++ )
F_8 ( V_8 , V_6 , V_12 ) ;
}
void T_1 F_9 ( void )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_7 () ; V_8 ++ )
F_3 ( V_3 , 0 ) [ F_10 ( V_8 ) ] = V_8 ;
V_13 . V_14 . V_15 () ;
}
static void T_1 F_11 ( void )
{
#ifdef F_12
F_13 ( V_16 , V_17 ) ;
F_13 ( V_18 , V_19 ) ;
F_13 ( V_20 ,
V_21 ) ;
F_14 ( V_22 , V_23 ) ;
F_15 ( V_22 , V_24 ) ;
F_13 ( V_25 , V_26 ) ;
#endif
}
static void T_1 F_16 ( void )
{
F_11 () ;
#ifdef F_17
F_13 ( V_27 , V_28 ) ;
#endif
#ifdef F_18
F_13 ( V_29 , V_30 ) ;
#endif
#ifdef F_19
F_13 ( V_31 , V_32 ) ;
#endif
#ifdef V_10
F_13 ( V_33 , V_34 ) ;
F_13 ( V_35 , V_36 ) ;
#ifdef F_20
F_13 ( V_37 , V_38 ) ;
F_13 ( V_39 , V_40 ) ;
#endif
F_13 ( V_41 , V_42 ) ;
F_13 ( V_43 , V_44 ) ;
# ifdef F_21
F_13 ( V_45 , V_46 ) ;
# endif
#endif
}
void T_1 F_22 ( void )
{
int V_8 ;
V_13 . V_14 . V_47 () ;
F_16 () ;
V_8 = V_48 ;
#ifndef V_10
#define F_23 NR_VECTORS
#endif
F_24 (i, used_vectors, first_system_vector) {
F_14 ( V_8 , V_49 +
8 * ( V_8 - V_48 ) ) ;
}
#ifdef V_10
F_24 (i, used_vectors, NR_VECTORS)
F_14 ( V_8 , V_42 ) ;
#endif
if ( ! V_50 && ! V_51 && F_7 () )
F_25 ( 2 , & V_52 ) ;
#ifdef F_26
F_27 ( F_28 () ) ;
#endif
}
