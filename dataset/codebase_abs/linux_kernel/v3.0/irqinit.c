static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( 0 , 0xF0 ) ;
if ( V_3 || ! V_4 . V_5 )
return V_6 ;
F_3 ( F_4 () , 0 , 16 ) ;
return V_7 ;
}
int F_5 ( unsigned int V_8 )
{
int V_9 ;
F_6 (cpu) {
if ( F_7 ( V_10 , V_9 ) [ V_8 ] != - 1 )
return 1 ;
}
return 0 ;
}
void T_2 F_8 ( void )
{
struct V_11 * V_12 = V_13 -> V_12 ;
const char * V_14 = V_12 -> V_14 ;
int V_15 ;
#if F_9 ( V_16 ) || F_9 ( V_17 )
F_10 () ;
#endif
V_13 -> V_18 ( 0 ) ;
for ( V_15 = 0 ; V_15 < V_13 -> V_19 ; V_15 ++ )
F_11 ( V_15 , V_12 , V_20 , V_14 ) ;
}
void T_2 F_12 ( void )
{
int V_15 ;
F_13 () ;
for ( V_15 = 0 ; V_15 < V_13 -> V_19 ; V_15 ++ )
F_7 ( V_10 , 0 ) [ V_21 + V_15 ] = V_15 ;
V_22 . V_23 . V_24 () ;
}
void F_14 ( int V_9 )
{
#ifndef F_15
int V_25 ;
for ( V_25 = 0 ; V_25 < V_13 -> V_19 ; V_25 ++ )
F_7 ( V_10 , V_9 ) [ V_21 + V_25 ] = V_25 ;
#endif
F_16 ( V_9 ) ;
}
static void T_2 F_17 ( void )
{
#ifdef F_18
#if F_9 ( V_16 ) || F_9 ( V_17 )
F_19 ( V_26 , V_27 ) ;
#define F_20 ( T_3 ) \
alloc_intr_gate(INVALIDATE_TLB_VECTOR_START+NR, \
invalidate_interrupt##NR)
switch ( V_28 ) {
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
F_19 ( V_29 , V_30 ) ;
F_19 ( V_31 ,
V_32 ) ;
F_21 ( V_33 , V_34 ) ;
F_22 ( V_33 , V_35 ) ;
F_19 ( V_36 , V_37 ) ;
#endif
#endif
}
static void T_2 F_23 ( void )
{
F_17 () ;
#ifdef F_24
F_19 ( V_38 , V_39 ) ;
#endif
#ifdef F_25
F_19 ( V_40 , V_41 ) ;
#endif
#if F_9 ( V_42 ) && F_9 ( V_17 )
F_19 ( V_43 , V_44 ) ;
#endif
#if F_9 ( V_16 ) || F_9 ( V_17 )
F_19 ( V_45 , V_46 ) ;
F_19 ( V_47 , V_48 ) ;
F_19 ( V_49 , V_50 ) ;
F_19 ( V_51 , V_52 ) ;
# ifdef F_26
F_19 ( V_53 , V_54 ) ;
# endif
#endif
}
void T_2 F_27 ( void )
{
int V_15 ;
V_22 . V_23 . V_55 () ;
F_23 () ;
for ( V_15 = V_56 ; V_15 < V_57 ; V_15 ++ ) {
if ( ! F_28 ( V_15 , V_35 ) )
F_21 ( V_15 , V_58 [ V_15 - V_56 ] ) ;
}
if ( ! V_59 && ! V_60 )
F_29 ( 2 , & V_61 ) ;
#ifdef F_30
if ( V_4 . V_5 && ! V_62 )
F_29 ( V_63 , & V_64 ) ;
F_31 ( F_32 () ) ;
#endif
}
