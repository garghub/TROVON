int F_1 ( unsigned int V_1 )
{
int V_2 ;
F_2 (cpu) {
if ( ! F_3 ( F_4 ( V_3 , V_2 ) [ V_1 ] ) )
return 1 ;
}
return 0 ;
}
void T_1 F_5 ( void )
{
struct V_4 * V_5 = V_6 -> V_5 ;
int V_7 ;
#if F_6 ( V_8 ) || F_6 ( V_9 )
F_7 () ;
#endif
V_6 -> V_10 ( 0 ) ;
for ( V_7 = 0 ; V_7 < F_8 () ; V_7 ++ )
F_9 ( V_7 , V_5 , V_11 ) ;
}
void T_1 F_10 ( void )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_8 () ; V_7 ++ )
F_4 ( V_3 , 0 ) [ F_11 ( V_7 ) ] = F_12 ( V_7 ) ;
V_12 . V_13 . V_14 () ;
}
static void T_1 F_13 ( void )
{
#ifdef F_14
F_15 ( V_15 , V_16 ) ;
F_15 ( V_17 , V_18 ) ;
F_15 ( V_19 ,
V_20 ) ;
F_16 ( V_21 , V_22 ) ;
F_17 ( V_21 , V_23 ) ;
F_15 ( V_24 , V_25 ) ;
#endif
}
static void T_1 F_18 ( void )
{
F_13 () ;
#ifdef F_19
F_15 ( V_26 , V_27 ) ;
#endif
#ifdef F_20
F_15 ( V_28 , V_29 ) ;
#endif
#ifdef F_21
F_15 ( V_30 , V_31 ) ;
#endif
#ifdef V_9
F_15 ( V_32 , V_33 ) ;
F_15 ( V_34 , V_35 ) ;
#ifdef F_22
F_15 ( V_36 , V_37 ) ;
F_15 ( V_38 , V_39 ) ;
F_15 ( V_40 , V_41 ) ;
#endif
F_15 ( V_42 , V_43 ) ;
F_15 ( V_44 , V_45 ) ;
# ifdef F_23
F_15 ( V_46 , V_47 ) ;
# endif
#endif
}
void T_1 F_24 ( void )
{
int V_7 ;
V_12 . V_13 . V_48 () ;
F_18 () ;
V_7 = V_49 ;
#ifndef V_9
#define F_25 NR_VECTORS
#endif
F_26 (i, used_vectors, first_system_vector) {
F_16 ( V_7 , V_50 +
8 * ( V_7 - V_49 ) ) ;
}
#ifdef V_9
F_26 (i, used_vectors, NR_VECTORS)
F_16 ( V_7 , V_43 ) ;
#endif
if ( ! V_51 && ! V_52 && F_8 () )
F_27 ( 2 , & V_53 ) ;
F_28 ( F_29 () ) ;
}
