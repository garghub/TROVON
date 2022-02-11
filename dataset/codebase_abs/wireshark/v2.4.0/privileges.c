void
F_1 ( void )
{
T_1 V_1 ;
typedef BOOL (F_2 * F_3)( T_2 );
F_3 V_2 ;
#ifndef F_4
#define F_4 1
#endif
V_1 = F_5 ( F_6 ( L_1 ) ) ;
if ( V_1 != NULL ) {
V_2 = ( F_3 ) F_7 ( V_1 , L_2 ) ;
if ( V_2 ) {
V_2 ( F_4 ) ;
}
}
}
T_3
F_8 ( void )
{
return FALSE ;
}
T_3
F_9 ( void )
{
return FALSE ;
}
void
F_10 ( void )
{
}
T_4 *
F_11 ( void ) {
T_4 * V_3 ;
V_3 = F_12 ( L_3 ) ;
return V_3 ;
}
T_4 *
F_13 ( void ) {
T_4 * V_4 ;
V_4 = F_12 ( L_3 ) ;
return V_4 ;
}
void
F_1 ( void )
{
V_5 = F_14 () ;
V_6 = F_15 () ;
V_7 = F_16 () ;
V_8 = F_17 () ;
V_9 = TRUE ;
}
T_3
F_8 ( void )
{
F_18 ( V_9 ) ;
#ifdef F_19
return F_20 () ;
#else
return ( V_5 != V_6 || V_7 != V_8 || V_5 == 0 || V_7 == 0 ) ;
#endif
}
T_3
F_9 ( void )
{
#ifdef F_21
T_5 V_10 , V_11 , V_12 ;
#endif
#ifdef F_22
T_6 V_13 , V_14 , V_15 ;
#endif
#ifdef F_21
F_23 ( & V_10 , & V_11 , & V_12 ) ;
if ( V_10 == 0 || V_11 == 0 || V_12 == 0 )
return TRUE ;
#else
if ( F_14 () == 0 || F_15 () == 0 )
return TRUE ;
#endif
#ifdef F_22
F_24 ( & V_13 , & V_14 , & V_15 ) ;
if ( V_13 == 0 || V_14 == 0 || V_15 == 0 )
return TRUE ;
#else
if ( F_16 () == 0 || F_17 () == 0 )
return TRUE ;
#endif
return FALSE ;
}
static void
F_25 ( const T_4 * V_16 )
{
F_26 ( L_4 ,
V_16 , F_27 ( V_17 ) ) ;
}
void
F_10 ( void )
{
if ( F_8 () ) {
#ifdef F_22
if ( F_28 ( V_7 , V_7 , V_7 ) == - 1 ) { F_25 ( L_5 ) ; }
#else
if ( F_29 ( V_7 ) == - 1 ) { F_25 ( L_6 ) ; }
if ( F_30 ( V_7 ) == - 1 ) { F_25 ( L_7 ) ; }
#endif
#ifdef F_21
if ( F_31 ( V_5 , V_5 , V_5 ) == - 1 ) { F_25 ( L_8 ) ; }
#else
if ( F_32 ( V_5 ) == - 1 ) { F_25 ( L_9 ) ; }
if ( F_33 ( V_5 ) == - 1 ) { F_25 ( L_10 ) ; }
#endif
}
}
T_4 *
F_11 ( void ) {
T_4 * V_3 ;
struct V_18 * V_19 = F_34 ( F_14 () ) ;
if ( V_19 ) {
V_3 = F_12 ( V_19 -> V_20 ) ;
} else {
V_3 = F_12 ( L_3 ) ;
}
F_35 () ;
return V_3 ;
}
T_4 *
F_13 ( void ) {
T_4 * V_4 ;
struct V_21 * V_22 = F_36 ( F_16 () ) ;
if ( V_22 ) {
V_4 = F_12 ( V_22 -> V_23 ) ;
} else {
V_4 = F_12 ( L_3 ) ;
}
F_37 () ;
return V_4 ;
}
