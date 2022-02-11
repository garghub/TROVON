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
void F_10 ( int V_2 )
{
#ifndef F_11
int V_17 ;
for ( V_17 = 0 ; V_17 < F_7 () ; V_17 ++ )
F_3 ( V_3 , V_2 ) [ V_13 + V_17 ] = V_17 ;
#endif
F_12 ( V_2 ) ;
}
static void T_1 F_13 ( void )
{
#ifdef F_14
#if F_5 ( V_9 ) || F_5 ( V_10 )
F_15 ( V_18 , V_19 ) ;
F_15 ( V_20 , V_21 ) ;
F_15 ( V_22 ,
V_23 ) ;
F_16 ( V_24 , V_25 ) ;
F_17 ( V_24 , V_26 ) ;
F_15 ( V_27 , V_28 ) ;
#endif
#endif
}
static void T_1 F_18 ( void )
{
F_13 () ;
#ifdef F_19
F_15 ( V_29 , V_30 ) ;
#endif
#ifdef F_20
F_15 ( V_31 , V_32 ) ;
#endif
#if F_5 ( V_9 ) || F_5 ( V_10 )
F_15 ( V_33 , V_34 ) ;
F_15 ( V_35 , V_36 ) ;
#ifdef F_21
F_15 ( V_37 , V_38 ) ;
#endif
F_15 ( V_39 , V_40 ) ;
F_15 ( V_41 , V_42 ) ;
# ifdef F_22
F_15 ( V_43 , V_44 ) ;
# endif
#endif
}
void T_1 F_23 ( void )
{
int V_8 ;
V_14 . V_15 . V_45 () ;
F_18 () ;
V_8 = V_46 ;
F_24 (i, used_vectors, NR_VECTORS) {
F_16 ( V_8 , V_47 [ V_8 - V_46 ] ) ;
}
if ( ! V_48 && ! V_49 && F_7 () )
F_25 ( 2 , & V_50 ) ;
#ifdef F_26
F_27 ( F_28 () ) ;
#endif
}
