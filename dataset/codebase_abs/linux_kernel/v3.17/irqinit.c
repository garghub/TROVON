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
const char * V_8 = V_6 -> V_8 ;
int V_9 ;
#if F_5 ( V_10 ) || F_5 ( V_11 )
F_6 () ;
#endif
V_7 -> V_12 ( 0 ) ;
for ( V_9 = 0 ; V_9 < F_7 () ; V_9 ++ )
F_8 ( V_9 , V_6 , V_13 , V_8 ) ;
}
void T_1 F_9 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_7 () ; V_9 ++ )
F_3 ( V_3 , 0 ) [ V_14 + V_9 ] = V_9 ;
V_15 . V_16 . V_17 () ;
}
void F_10 ( int V_2 )
{
#ifndef F_11
int V_18 ;
for ( V_18 = 0 ; V_18 < F_7 () ; V_18 ++ )
F_3 ( V_3 , V_2 ) [ V_14 + V_18 ] = V_18 ;
#endif
F_12 ( V_2 ) ;
}
static void T_1 F_13 ( void )
{
#ifdef F_14
#if F_5 ( V_10 ) || F_5 ( V_11 )
F_15 ( V_19 , V_20 ) ;
F_15 ( V_21 , V_22 ) ;
F_15 ( V_23 ,
V_24 ) ;
F_16 ( V_25 , V_26 ) ;
F_17 ( V_25 , V_27 ) ;
F_15 ( V_28 , V_29 ) ;
#endif
#endif
}
static void T_1 F_18 ( void )
{
F_13 () ;
#ifdef F_19
F_15 ( V_30 , V_31 ) ;
#endif
#ifdef F_20
F_15 ( V_32 , V_33 ) ;
#endif
#if F_5 ( V_10 ) || F_5 ( V_11 )
F_15 ( V_34 , V_35 ) ;
F_15 ( V_36 , V_37 ) ;
#ifdef F_21
F_15 ( V_38 , V_39 ) ;
#endif
F_15 ( V_40 , V_41 ) ;
F_15 ( V_42 , V_43 ) ;
# ifdef F_22
F_15 ( V_44 , V_45 ) ;
# endif
#endif
}
void T_1 F_23 ( void )
{
int V_9 ;
V_15 . V_16 . V_46 () ;
F_18 () ;
V_9 = V_47 ;
F_24 (i, used_vectors, NR_VECTORS) {
F_16 ( V_9 , V_48 [ V_9 - V_47 ] ) ;
}
if ( ! V_49 && ! V_50 && F_7 () )
F_25 ( 2 , & V_51 ) ;
#ifdef F_26
F_27 ( F_28 () ) ;
#endif
}
