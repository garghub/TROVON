static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( 0 , 0xF0 ) ;
if ( V_3 || ! V_4 . V_5 )
return V_6 ;
F_3 ( F_4 () , 0 , V_7 ) ;
return V_8 ;
}
int F_5 ( unsigned int V_9 )
{
int V_10 ;
F_6 (cpu) {
if ( F_7 ( V_11 , V_10 ) [ V_9 ] != - 1 )
return 1 ;
}
return 0 ;
}
void T_2 F_8 ( void )
{
struct V_12 * V_13 = V_14 -> V_13 ;
const char * V_15 = V_13 -> V_15 ;
int V_16 ;
#if F_9 ( V_17 ) || F_9 ( V_18 )
F_10 () ;
#endif
V_14 -> V_19 ( 0 ) ;
for ( V_16 = 0 ; V_16 < V_14 -> V_20 ; V_16 ++ )
F_11 ( V_16 , V_13 , V_21 , V_15 ) ;
}
void T_2 F_12 ( void )
{
int V_16 ;
F_13 () ;
for ( V_16 = 0 ; V_16 < V_14 -> V_20 ; V_16 ++ )
F_7 ( V_11 , 0 ) [ V_22 + V_16 ] = V_16 ;
V_23 . V_24 . V_25 () ;
}
void F_14 ( int V_10 )
{
#ifndef F_15
int V_26 ;
for ( V_26 = 0 ; V_26 < V_14 -> V_20 ; V_26 ++ )
F_7 ( V_11 , V_10 ) [ V_22 + V_26 ] = V_26 ;
#endif
F_16 ( V_10 ) ;
}
static void T_2 F_17 ( void )
{
#ifdef F_18
#if F_9 ( V_17 ) || F_9 ( V_18 )
F_19 ( V_27 , V_28 ) ;
F_19 ( V_29 , V_30 ) ;
F_19 ( V_31 ,
V_32 ) ;
F_20 ( V_33 , V_34 ) ;
F_21 ( V_33 , V_35 ) ;
F_19 ( V_36 , V_37 ) ;
#endif
#endif
}
static void T_2 F_22 ( void )
{
F_17 () ;
#ifdef F_23
F_19 ( V_38 , V_39 ) ;
#endif
#ifdef F_24
F_19 ( V_40 , V_41 ) ;
#endif
#if F_9 ( V_17 ) || F_9 ( V_18 )
F_19 ( V_42 , V_43 ) ;
F_19 ( V_44 , V_45 ) ;
F_19 ( V_46 , V_47 ) ;
F_19 ( V_48 , V_49 ) ;
# ifdef F_25
F_19 ( V_50 , V_51 ) ;
# endif
#endif
}
void T_2 F_26 ( void )
{
int V_16 ;
V_23 . V_24 . V_52 () ;
F_22 () ;
V_16 = V_53 ;
F_27 (i, used_vectors, NR_VECTORS) {
F_20 ( V_16 , V_54 [ V_16 - V_53 ] ) ;
}
if ( ! V_55 && ! V_56 )
F_28 ( 2 , & V_57 ) ;
#ifdef F_29
if ( V_4 . V_5 && ! V_58 )
F_28 ( V_59 , & V_60 ) ;
F_30 ( F_31 () ) ;
#endif
}
