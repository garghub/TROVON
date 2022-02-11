static int T_1 F_1 ( void )
{
F_2 ( NULL , V_1 , NULL ) ;
F_3 () ;
return 0 ;
}
static void T_1 F_4 ( void )
{
struct V_2 * V_3 ;
F_5 (np, L_1 ) {
if ( F_6 ( V_3 , L_2 , NULL ) == NULL )
break;
}
if ( V_3 == NULL )
F_7 ( L_3 ) ;
if ( F_8 ( V_3 , L_4 ) ) {
F_9 () ;
V_4 . V_5 = V_6 ;
#ifdef F_10
} else if ( F_8 ( V_3 , L_5 ) ) {
struct V_7 * V_7 = F_11 ( V_3 , 0 , V_8 , 0 , 0 ,
L_6 ) ;
F_12 ( V_7 == NULL ) ;
F_13 ( V_7 ) ;
V_4 . V_5 = V_9 ;
#endif
} else
F_7 ( L_7 ) ;
}
static void T_2 F_14 ( int V_10 )
{
F_15 () ;
}
static int T_2 F_16 ( int V_10 )
{
struct V_2 * V_11 = F_17 ( V_10 , NULL ) ;
const T_3 * V_12 ;
T_4 * V_13 ;
extern void V_14 ( void ) ;
F_12 ( V_11 == NULL ) ;
V_12 = F_6 ( V_11 , L_8 ,
NULL ) ;
if ( V_12 == NULL ) {
F_18 ( L_9 , V_10 ) ;
return - V_15 ;
}
V_13 = ( T_4 * ) F_19 ( * V_12 ) ;
F_20 ( L_10 , V_10 , V_13 ) ;
V_13 [ 3 ] = V_10 ;
F_21 () ;
V_13 [ 1 ] = F_22 ( V_14 ) ;
F_23 () ;
return 0 ;
}
static void T_1 F_24 ( void )
{
if ( F_25 ( V_16 ) )
V_17 = & V_18 ;
}
static void T_1 F_24 ( void ) { }
static void T_1 F_26 ( void )
{
F_24 () ;
}
static int T_1 F_27 ( void )
{
unsigned long V_19 = F_28 () ;
if ( ! F_29 ( V_19 , L_11 ) )
return 0 ;
return 1 ;
}
