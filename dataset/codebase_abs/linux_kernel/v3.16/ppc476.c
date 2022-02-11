static void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( L_1 ) ) {
F_3 ( V_2 , 0xe0 , 0x0114231f ) ;
F_3 ( V_2 , 0xe4 , 0x00006c40 ) ;
}
}
static void F_4 ( int V_3 )
{
F_5 ( V_4 ,
V_5 , V_3 ) ;
while ( 1 )
;
}
static void F_6 ( void )
{
F_4 ( V_6 ) ;
}
static void F_7 ( char * V_7 )
{
F_4 ( V_8 ) ;
}
static int F_8 ( struct V_9 * V_10 ,
const struct V_11 * V_12 )
{
V_4 = V_10 ;
V_13 . V_14 = F_7 ;
V_13 . V_15 = F_6 ;
return 0 ;
}
static int T_1 F_9 ( void )
{
F_10 ( & V_16 ) ;
F_11 ( NULL , V_17 , NULL ) ;
return 0 ;
}
static void T_1 F_12 ( void )
{
struct V_18 * V_19 ;
F_13 (np, L_2 ) {
if ( F_14 ( V_19 , L_3 , NULL ) == NULL )
break;
}
if ( V_19 == NULL )
F_15 ( L_4 ) ;
if ( F_16 ( V_19 , L_5 ) ) {
struct V_20 * V_20 =
F_17 ( V_19 , 0 , V_21 , 0 , 0 , L_6 ) ;
F_18 ( V_20 == NULL ) ;
F_19 ( V_20 ) ;
V_13 . V_22 = V_23 ;
} else
F_15 ( L_7 ) ;
}
static void F_20 ( int V_24 )
{
F_21 () ;
}
static int F_22 ( int V_24 )
{
struct V_18 * V_25 = F_23 ( V_24 , NULL ) ;
const T_2 * V_26 ;
T_3 * V_27 ;
extern void V_28 ( void ) ;
F_18 ( V_25 == NULL ) ;
V_26 =
F_14 ( V_25 , L_8 , NULL ) ;
if ( V_26 == NULL ) {
F_24 ( L_9 ,
V_24 ) ;
return 1 ;
}
V_27 = ( T_3 * ) F_25 ( * V_26 ) ;
F_26 ( L_10 , V_24 , V_27 ) ;
V_27 [ 3 ] = V_24 ;
F_27 () ;
V_27 [ 1 ] = F_28 ( V_28 ) ;
F_29 () ;
return 0 ;
}
static void T_1 F_30 ( void )
{
if ( F_31 ( V_29 ) )
V_30 = & V_31 ;
}
static void T_1 F_30 ( void ) { }
static void T_1 F_32 ( void )
{
F_33 () ;
F_30 () ;
}
static int T_1 F_34 ( void )
{
int V_32 ;
T_4 * V_33 ;
struct V_18 * V_19 = NULL ;
if ( F_2 ( L_1 ) ) {
V_19 = F_35 ( NULL , NULL , L_11 ) ;
V_32 = 0 ;
} else if ( F_2 ( L_12 ) ) {
V_19 = F_35 ( NULL , NULL , L_13 ) ;
V_32 = 2 ;
}
if ( ! V_19 )
goto V_34;
V_33 = ( T_4 * ) F_36 ( V_19 , 0 ) ;
F_37 ( V_19 ) ;
if ( ! V_33 )
goto V_34;
V_35 = F_38 ( V_33 + V_32 ) & 0x03 ;
F_39 ( L_14 , V_36 , V_35 ) ;
F_40 ( V_33 ) ;
return 0 ;
V_34:
F_39 ( L_15 , V_36 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 == 0x1033 && ( V_2 -> V_38 == 0x0035 ||
V_2 -> V_38 == 0x00e0 ) ) {
if ( V_35 == 0 ) {
V_2 -> V_39 = F_42 ( NULL , 47 ) ;
F_39 ( L_16 , V_36 , V_2 -> V_39 ) ;
} else if ( V_35 == 2 ) {
V_2 -> V_39 = F_42 ( NULL , 49 ) ;
F_39 ( L_16 , V_36 , V_2 -> V_39 ) ;
} else {
F_43 ( L_17 , V_36 ) ;
}
}
}
static int T_1 F_44 ( void )
{
unsigned long V_40 = F_45 () ;
if ( F_46 ( V_40 , L_12 ) )
return 1 ;
if ( F_46 ( V_40 , L_1 ) ) {
V_13 . V_41 = F_41 ;
return 1 ;
}
return 0 ;
}
