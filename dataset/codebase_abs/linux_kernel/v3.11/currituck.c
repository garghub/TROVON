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
static void F_14 ( int V_11 )
{
F_15 () ;
}
static int F_16 ( int V_11 )
{
struct V_4 * V_12 = F_17 ( V_11 , NULL ) ;
const T_2 * V_13 ;
T_3 * V_14 ;
extern void V_15 ( void ) ;
F_12 ( V_12 == NULL ) ;
V_13 =
F_8 ( V_12 , L_8 , NULL ) ;
if ( V_13 == NULL ) {
F_18 ( L_9 ,
V_11 ) ;
return 1 ;
}
V_14 = ( T_3 * ) F_19 ( * V_13 ) ;
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
static int T_1 F_31 ( void )
{
T_4 V_20 ;
void * V_21 ;
struct V_4 * V_5 ;
V_5 = F_32 ( NULL , NULL , L_11 ) ;
if ( ! V_5 )
goto V_22;
V_21 = F_33 ( V_5 , 0 ) ;
F_34 ( V_5 ) ;
if ( ! V_21 )
goto V_22;
V_20 = F_35 ( V_21 ) ;
V_23 = V_20 & 0x03 ;
F_36 ( L_12 , V_24 , V_23 ) ;
F_37 ( V_21 ) ;
return 0 ;
V_22:
F_36 ( L_13 , V_24 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 == 0x1033 && ( V_2 -> V_26 == 0x0035 ||
V_2 -> V_26 == 0x00e0 ) ) {
if ( V_23 == 0 ) {
V_2 -> V_27 = F_39 ( NULL , 47 ) ;
F_36 ( L_14 , V_24 , V_2 -> V_27 ) ;
} else if ( V_23 == 2 ) {
V_2 -> V_27 = F_39 ( NULL , 49 ) ;
F_36 ( L_14 , V_24 , V_2 -> V_27 ) ;
} else {
F_40 ( L_15 , V_24 ) ;
}
}
}
