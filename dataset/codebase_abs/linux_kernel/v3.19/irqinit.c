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
F_3 ( V_3 , 0 ) [ V_13 + V_8 ] = V_8 ;
V_14 . V_15 . V_16 () ;
}
static void T_1 F_10 ( void )
{
#ifdef F_11
F_12 ( V_17 , V_18 ) ;
F_12 ( V_19 , V_20 ) ;
F_12 ( V_21 ,
V_22 ) ;
F_13 ( V_23 , V_24 ) ;
F_14 ( V_23 , V_25 ) ;
F_12 ( V_26 , V_27 ) ;
#endif
}
static void T_1 F_15 ( void )
{
F_10 () ;
#ifdef F_16
F_12 ( V_28 , V_29 ) ;
#endif
#ifdef F_17
F_12 ( V_30 , V_31 ) ;
#endif
#ifdef V_10
F_12 ( V_32 , V_33 ) ;
F_12 ( V_34 , V_35 ) ;
#ifdef F_18
F_12 ( V_36 , V_37 ) ;
#endif
F_12 ( V_38 , V_39 ) ;
F_12 ( V_40 , V_41 ) ;
# ifdef F_19
F_12 ( V_42 , V_43 ) ;
# endif
#endif
}
void T_1 F_20 ( void )
{
int V_8 ;
V_14 . V_15 . V_44 () ;
F_15 () ;
V_8 = V_45 ;
#ifndef V_10
#define F_21 NR_VECTORS
#endif
F_22 (i, used_vectors, first_system_vector) {
F_13 ( V_8 , V_46 [ V_8 - V_45 ] ) ;
}
#ifdef V_10
F_22 (i, used_vectors, NR_VECTORS)
F_13 ( V_8 , V_39 ) ;
#endif
if ( ! V_47 && ! V_48 && F_7 () )
F_23 ( 2 , & V_49 ) ;
#ifdef F_24
F_25 ( F_26 () ) ;
#endif
}
