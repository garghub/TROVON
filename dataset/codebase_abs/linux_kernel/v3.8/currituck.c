static void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( L_1 ) ) {
F_3 ( V_2 , 0xe0 , 0x0114231f ) ;
F_3 ( V_2 , 0xe4 , 0x00006c40 ) ;
}
}
static int T_1 F_4 ( void )
{
F_5 ( NULL , V_3 , NULL ) ;
return 0 ;
}
static void T_1 F_6 ( void )
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
F_11 ( V_5 , 0 , V_7 , 0 , 0 , L_6 ) ;
F_12 ( V_6 == NULL ) ;
F_13 ( V_6 ) ;
V_8 . V_9 = V_10 ;
} else
F_9 ( L_7 ) ;
}
static void T_2 F_14 ( int V_11 )
{
F_15 () ;
}
static int T_2 F_16 ( int V_11 )
{
struct V_4 * V_12 = F_17 ( V_11 , NULL ) ;
const T_3 * V_13 ;
T_4 * V_14 ;
extern void V_15 ( void ) ;
F_12 ( V_12 == NULL ) ;
V_13 =
F_8 ( V_12 , L_8 , NULL ) ;
if ( V_13 == NULL ) {
F_18 ( L_9 ,
V_11 ) ;
return 1 ;
}
V_14 = ( T_4 * ) F_19 ( * V_13 ) ;
F_20 ( L_10 , V_11 , V_14 ) ;
V_14 [ 3 ] = V_11 ;
F_21 () ;
V_14 [ 1 ] = F_22 ( V_15 ) ;
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
F_27 () ;
F_24 () ;
}
static int T_1 F_28 ( void )
{
unsigned long V_19 = F_29 () ;
if ( ! F_30 ( V_19 , L_1 ) )
return 0 ;
return 1 ;
}
static void F_31 ( struct V_1 * V_2 )
{
if ( V_2 -> V_20 == 0x1033 && ( V_2 -> V_21 == 0x0035 ||
V_2 -> V_21 == 0x00e0 ) ) {
V_2 -> V_22 = F_32 ( NULL , 47 ) ;
F_33 ( L_11 , V_23 , V_2 -> V_22 ) ;
}
}
