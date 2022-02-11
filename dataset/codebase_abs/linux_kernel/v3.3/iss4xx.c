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
struct V_7 * V_7 = F_11 ( V_3 , 0 , 0 , 0 , 0 ,
L_6 ) ;
F_12 ( V_7 == NULL ) ;
F_13 ( V_7 ) ;
V_4 . V_5 = V_8 ;
#endif
} else
F_7 ( L_7 ) ;
}
static void T_2 F_14 ( int V_9 )
{
F_15 () ;
}
static int T_2 F_16 ( int V_9 )
{
struct V_2 * V_10 = F_17 ( V_9 , NULL ) ;
const T_3 * V_11 ;
T_4 * V_12 ;
extern void V_13 ( void ) ;
F_12 ( V_10 == NULL ) ;
V_11 = F_6 ( V_10 , L_8 ,
NULL ) ;
if ( V_11 == NULL ) {
F_18 ( L_9 , V_9 ) ;
return - V_14 ;
}
V_12 = ( T_4 * ) F_19 ( * V_11 ) ;
F_20 ( L_10 , V_9 , V_12 ) ;
V_12 [ 3 ] = V_9 ;
F_21 () ;
V_12 [ 1 ] = F_22 ( V_13 ) ;
F_23 () ;
return 0 ;
}
static void T_1 F_24 ( void )
{
if ( F_25 ( V_15 ) )
V_16 = & V_17 ;
}
static void T_1 F_24 ( void ) { }
static void T_1 F_26 ( void )
{
F_24 () ;
}
static int T_1 F_27 ( void )
{
unsigned long V_18 = F_28 () ;
if ( ! F_29 ( V_18 , L_11 ) )
return 0 ;
return 1 ;
}
