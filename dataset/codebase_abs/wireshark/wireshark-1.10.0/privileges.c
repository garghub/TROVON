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
F_8 () ;
}
T_3
F_9 ( void )
{
return FALSE ;
}
T_3
F_10 ( void )
{
return FALSE ;
}
void
F_11 ( void )
{
}
T_4 *
F_12 ( void ) {
T_4 * V_3 ;
V_3 = F_13 ( L_3 ) ;
return V_3 ;
}
T_4 *
F_14 ( void ) {
T_4 * V_4 ;
V_4 = F_13 ( L_3 ) ;
return V_4 ;
}
T_3
F_8 () {
T_5 V_5 , V_6 ;
T_6 V_7 ;
V_5 = F_15 ( NULL , NULL , 0 ) ;
if ( ! V_5 )
return FALSE ;
V_6 = F_16 ( V_5 , F_6 ( L_4 ) , V_8 | V_9 ) ;
if ( ! V_6 )
return FALSE ;
if ( F_17 ( V_6 , & V_7 ) ) {
if ( V_7 . V_10 & V_11 )
return TRUE ;
}
return FALSE ;
}
void
F_1 ( void )
{
V_12 = F_18 () ;
V_13 = F_19 () ;
V_14 = F_20 () ;
V_15 = F_21 () ;
V_16 = TRUE ;
}
T_3
F_9 ( void )
{
F_22 ( V_16 ) ;
#ifdef F_23
return F_24 () ;
#else
return ( V_12 != V_13 || V_14 != V_15 || V_12 == 0 || V_14 == 0 ) ;
#endif
}
T_3
F_10 ( void )
{
#ifdef F_25
T_7 V_17 , V_18 , V_19 ;
#endif
#ifdef F_26
T_8 V_20 , V_21 , V_22 ;
#endif
#ifdef F_25
F_27 ( & V_17 , & V_18 , & V_19 ) ;
if ( V_17 == 0 || V_18 == 0 || V_19 == 0 )
return TRUE ;
#else
if ( F_18 () == 0 || F_19 () == 0 )
return TRUE ;
#endif
#ifdef F_26
F_28 ( & V_20 , & V_21 , & V_22 ) ;
if ( V_20 == 0 || V_21 == 0 || V_22 == 0 )
return TRUE ;
#else
if ( F_20 () == 0 || F_21 () == 0 )
return TRUE ;
#endif
return FALSE ;
}
static void
F_29 ( const T_4 * V_23 )
{
F_30 ( L_5 ,
V_23 , F_31 ( V_24 ) ) ;
}
void
F_11 ( void )
{
if ( F_9 () ) {
#ifdef F_26
if ( F_32 ( V_14 , V_14 , V_14 ) == - 1 ) { F_29 ( L_6 ) ; }
#else
if ( F_33 ( V_14 ) == - 1 ) { F_29 ( L_7 ) ; }
if ( F_34 ( V_14 ) == - 1 ) { F_29 ( L_8 ) ; }
#endif
#ifdef F_25
if ( F_35 ( V_12 , V_12 , V_12 ) == - 1 ) { F_29 ( L_9 ) ; }
#else
if ( F_36 ( V_12 ) == - 1 ) { F_29 ( L_10 ) ; }
if ( F_37 ( V_12 ) == - 1 ) { F_29 ( L_11 ) ; }
#endif
}
}
T_4 *
F_12 ( void ) {
T_4 * V_3 ;
struct V_25 * V_26 = F_38 ( F_18 () ) ;
if ( V_26 ) {
V_3 = F_13 ( V_26 -> V_27 ) ;
} else {
V_3 = F_13 ( L_3 ) ;
}
F_39 () ;
return V_3 ;
}
T_4 *
F_14 ( void ) {
T_4 * V_4 ;
struct V_28 * V_29 = F_40 ( F_20 () ) ;
if ( V_29 ) {
V_4 = F_13 ( V_29 -> V_30 ) ;
} else {
V_4 = F_13 ( L_3 ) ;
}
F_41 () ;
return V_4 ;
}
