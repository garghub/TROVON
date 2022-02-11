static void T_1 F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( L_1 ) ) {
F_3 ( V_2 , 0xe0 , 0x0114231f ) ;
F_3 ( V_2 , 0xe4 , 0x00006c40 ) ;
}
}
static int T_2 F_4 ( void )
{
F_5 ( NULL , V_3 , NULL ) ;
return 0 ;
}
static void T_2 F_6 ( void )
{
struct V_4 * V_5 ;
F_7 (np, L_2 ) {
if ( F_8 ( V_5 , L_3 , NULL ) == NULL )
break;
}
if ( V_5 == NULL )
F_9 ( L_4 ) ;
if ( F_10 ( V_5 , L_5 ) ) {
struct V_6 * V_6 =
F_11 ( V_5 , 0 , 0 , 0 , 0 , L_6 ) ;
F_12 ( V_6 == NULL ) ;
F_13 ( V_6 ) ;
V_7 . V_8 = V_9 ;
} else
F_9 ( L_7 ) ;
}
static void T_3 F_14 ( int V_10 )
{
F_15 () ;
}
static int T_3 F_16 ( int V_10 )
{
struct V_4 * V_11 = F_17 ( V_10 , NULL ) ;
const T_4 * V_12 ;
T_5 * V_13 ;
extern void V_14 ( void ) ;
F_12 ( V_11 == NULL ) ;
V_12 =
F_8 ( V_11 , L_8 , NULL ) ;
if ( V_12 == NULL ) {
F_18 ( L_9 ,
V_10 ) ;
return 1 ;
}
V_13 = ( T_5 * ) F_19 ( * V_12 ) ;
F_20 ( L_10 , V_10 , V_13 ) ;
V_13 [ 3 ] = V_10 ;
F_21 () ;
V_13 [ 1 ] = F_22 ( V_14 ) ;
F_23 () ;
return 0 ;
}
static void T_2 F_24 ( void )
{
if ( F_25 ( V_15 ) )
V_16 = & V_17 ;
}
static void T_2 F_24 ( void ) { }
static void T_2 F_26 ( void )
{
#ifdef F_27
if ( F_28 () > 0xffffffff ) {
V_18 = 1 ;
F_29 ( & V_19 ) ;
V_7 . V_20 = V_21 ;
}
#endif
F_24 () ;
}
static int T_2 F_30 ( void )
{
unsigned long V_22 = F_31 () ;
if ( ! F_32 ( V_22 , L_1 ) )
return 0 ;
return 1 ;
}
static void F_33 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 == 0x1033 && ( V_2 -> V_24 == 0x0035 ||
V_2 -> V_24 == 0x00e0 ) ) {
V_2 -> V_25 = F_34 ( NULL , 47 ) ;
F_35 ( L_11 , V_26 , V_2 -> V_25 ) ;
}
}
