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
#define F_20 ( T_3 ) \
alloc_intr_gate(INVALIDATE_TLB_VECTOR_START+NR, \
invalidate_interrupt##NR)
switch ( V_29 ) {
default:
F_20 ( 31 ) ;
case 31 :
F_20 ( 30 ) ;
case 30 :
F_20 ( 29 ) ;
case 29 :
F_20 ( 28 ) ;
case 28 :
F_20 ( 27 ) ;
case 27 :
F_20 ( 26 ) ;
case 26 :
F_20 ( 25 ) ;
case 25 :
F_20 ( 24 ) ;
case 24 :
F_20 ( 23 ) ;
case 23 :
F_20 ( 22 ) ;
case 22 :
F_20 ( 21 ) ;
case 21 :
F_20 ( 20 ) ;
case 20 :
F_20 ( 19 ) ;
case 19 :
F_20 ( 18 ) ;
case 18 :
F_20 ( 17 ) ;
case 17 :
F_20 ( 16 ) ;
case 16 :
F_20 ( 15 ) ;
case 15 :
F_20 ( 14 ) ;
case 14 :
F_20 ( 13 ) ;
case 13 :
F_20 ( 12 ) ;
case 12 :
F_20 ( 11 ) ;
case 11 :
F_20 ( 10 ) ;
case 10 :
F_20 ( 9 ) ;
case 9 :
F_20 ( 8 ) ;
case 8 :
F_20 ( 7 ) ;
case 7 :
F_20 ( 6 ) ;
case 6 :
F_20 ( 5 ) ;
case 5 :
F_20 ( 4 ) ;
case 4 :
F_20 ( 3 ) ;
case 3 :
F_20 ( 2 ) ;
case 2 :
F_20 ( 1 ) ;
case 1 :
F_20 ( 0 ) ;
break;
}
F_19 ( V_30 , V_31 ) ;
F_19 ( V_32 ,
V_33 ) ;
F_21 ( V_34 , V_35 ) ;
F_22 ( V_34 , V_36 ) ;
F_19 ( V_37 , V_38 ) ;
#endif
#endif
}
static void T_2 F_23 ( void )
{
F_17 () ;
#ifdef F_24
F_19 ( V_39 , V_40 ) ;
#endif
#ifdef F_25
F_19 ( V_41 , V_42 ) ;
#endif
#if F_9 ( V_17 ) || F_9 ( V_18 )
F_19 ( V_43 , V_44 ) ;
F_19 ( V_45 , V_46 ) ;
F_19 ( V_47 , V_48 ) ;
F_19 ( V_49 , V_50 ) ;
# ifdef F_26
F_19 ( V_51 , V_52 ) ;
# endif
#endif
}
void T_2 F_27 ( void )
{
int V_16 ;
V_23 . V_24 . V_53 () ;
F_23 () ;
V_16 = V_54 ;
F_28 (i, used_vectors, NR_VECTORS) {
F_21 ( V_16 , V_55 [ V_16 - V_54 ] ) ;
}
if ( ! V_56 && ! V_57 )
F_29 ( 2 , & V_58 ) ;
#ifdef F_30
if ( V_4 . V_5 && ! V_59 )
F_29 ( V_60 , & V_61 ) ;
F_31 ( F_32 () ) ;
#endif
}
