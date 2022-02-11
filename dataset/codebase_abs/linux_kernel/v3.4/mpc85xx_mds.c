static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 ;
V_3 = F_2 ( V_2 , V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_4 = F_3 ( V_2 , V_5 , V_3 & ~ ( V_6 ) ) ;
if ( V_4 )
return V_4 ;
V_4 = F_3 ( V_2 , V_7 , V_8 ) ;
if ( V_4 )
return V_4 ;
V_3 = F_2 ( V_2 , V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_4 = F_3 ( V_2 , V_5 , V_3 | 0x0008 ) ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_9 ;
int V_4 ;
V_4 = F_3 ( V_2 , 29 , 0x0006 ) ;
if ( V_4 )
return V_4 ;
V_9 = F_2 ( V_2 , 30 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = ( V_9 & ( ~ 0x8000 ) ) | 0x4000 ;
V_4 = F_3 ( V_2 , 30 , V_9 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_3 ( V_2 , 29 , 0x000a ) ;
if ( V_4 )
return V_4 ;
V_9 = F_2 ( V_2 , 30 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_2 ( V_2 , 30 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 &= ~ 0x0020 ;
V_4 = F_3 ( V_2 , 30 , V_9 ) ;
if ( V_4 )
return V_4 ;
V_9 = F_2 ( V_2 , 16 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 &= ~ 0x0060 ;
V_4 = F_3 ( V_2 , 16 , V_9 ) ;
return V_4 ;
}
static void T_1 F_5 ( void )
{
struct V_10 * V_11 ;
static T_2 T_3 * V_12 ;
V_11 = F_6 ( NULL , L_1 ) ;
if ( ! V_11 )
return;
V_12 = F_7 ( V_11 , 0 ) ;
F_8 ( V_11 ) ;
if ( ! V_12 )
return;
if ( F_9 ( V_13 ) ) {
#define F_10 (0x1 << 7)
#define F_11 (0x1 << 7)
#define F_12 (0x3 << 4)
#define F_13 (0x3 << 0)
F_14 ( & V_12 [ 8 ] , F_10 ) ;
F_14 ( & V_12 [ 9 ] , F_11 ) ;
F_14 ( & V_12 [ 11 ] , F_12 |
F_13 ) ;
F_15 ( & V_12 [ 8 ] , F_10 ) ;
F_15 ( & V_12 [ 9 ] , F_11 ) ;
} else if ( F_9 ( V_14 ) ) {
#define F_16 (0x1 << 2)
#define F_17 (0x1 << 1)
#define F_18 (0x1 << 6)
#define F_19 (0x1 << 5)
F_14 ( & V_12 [ 7 ] , F_16 ) ;
F_15 ( & V_12 [ 8 ] , F_17 ) ;
F_15 ( & V_12 [ 7 ] , F_16 ) ;
F_14 ( & V_12 [ 8 ] , F_17 ) ;
for ( V_11 = NULL ; ( V_11 = F_20 ( V_11 ,
L_2 ,
L_3 ) ) != NULL ; ) {
const unsigned int * V_15 ;
int V_16 ;
V_15 = F_21 ( V_11 , L_4 , NULL ) ;
if ( V_15 == NULL )
continue;
V_16 = * V_15 - 1 ;
V_15 = F_21 ( V_11 , L_5 , NULL ) ;
if ( V_15 == NULL )
continue;
if ( strcmp ( L_6 , ( const char * ) V_15 ) == 0 )
F_22 ( & V_12 [ 7 + V_16 ] ,
F_18 , F_19 ) ;
}
} else if ( F_9 ( V_17 ) ) {
#define F_23 (0x1 << 5)
F_14 ( & V_12 [ 11 ] , F_23 ) ;
F_15 ( & V_12 [ 11 ] , F_23 ) ;
}
F_24 ( V_12 ) ;
}
static void T_1 F_25 ( void )
{
struct V_10 * V_11 ;
V_11 = F_20 ( NULL , NULL , L_7 ) ;
if ( ! V_11 ) {
V_11 = F_6 ( NULL , L_8 ) ;
if ( ! V_11 )
return;
}
if ( ! F_26 ( V_11 ) ) {
F_8 ( V_11 ) ;
return;
}
F_27 () ;
F_8 ( V_11 ) ;
V_11 = F_6 ( NULL , L_9 ) ;
if ( V_11 ) {
struct V_10 * V_18 ;
F_28 ( V_11 ) ;
F_8 ( V_11 ) ;
F_29 (ucc, L_10 )
F_30 ( V_18 ) ;
}
F_5 () ;
if ( F_9 ( V_17 ) ) {
struct V_19 T_3 * V_20 ;
V_11 = F_6 ( NULL , L_11 ) ;
if ( V_11 ) {
V_20 = F_7 ( V_11 , 0 ) ;
if ( ! V_20 )
F_31 ( L_12 ) ;
else{
F_32 ( & V_20 -> V_21 , F_33 ( 0 ) |
F_33 ( 3 ) |
F_33 ( 9 ) |
F_33 ( 12 ) ) ;
F_24 ( V_20 ) ;
}
F_8 ( V_11 ) ;
}
}
}
static void T_1 F_34 ( void )
{
struct V_10 * V_11 ;
V_11 = F_20 ( NULL , NULL , L_7 ) ;
if ( ! F_26 ( V_11 ) ) {
F_8 ( V_11 ) ;
return;
}
V_11 = F_20 ( NULL , NULL , L_13 ) ;
if ( ! V_11 ) {
V_11 = F_35 ( NULL , L_14 ) ;
if ( ! V_11 )
return;
}
if ( F_9 ( V_17 ) )
F_36 ( V_11 , 0 , V_22 ,
V_23 ) ;
else
F_36 ( V_11 , 0 , V_24 , NULL ) ;
F_8 ( V_11 ) ;
}
static void T_1 F_25 ( void ) { }
static void T_1 F_34 ( void ) { }
static void T_1 F_37 ( void )
{
#ifdef F_38
struct V_25 * V_26 ;
struct V_10 * V_11 ;
#endif
T_4 V_27 = 0xffffffff ;
if ( V_28 . V_29 )
V_28 . V_29 ( L_15 , 0 ) ;
#ifdef F_38
F_39 (np, L_16 ) {
if ( F_40 ( V_11 , L_17 ) ||
F_40 ( V_11 , L_18 ) ) {
struct V_30 V_31 ;
F_41 ( V_11 , 0 , & V_31 ) ;
if ( ( V_31 . V_32 & 0xfffff ) == 0x8000 )
F_42 ( V_11 , 1 ) ;
else
F_42 ( V_11 , 0 ) ;
V_26 = F_43 ( V_11 ) ;
V_27 = F_44 ( V_27 , V_26 -> V_33 +
V_26 -> V_34 ) ;
}
}
#endif
F_45 () ;
F_25 () ;
#ifdef F_46
if ( F_47 () > V_27 ) {
V_35 = 1 ;
F_48 ( & V_36 ) ;
V_28 . V_37 = V_38 ;
}
#endif
}
static int T_1 F_49 ( void )
{
char V_39 [ 20 ] ;
char * V_40 [ 2 ] = { L_19 , L_20 } ;
struct V_10 * V_41 ;
struct V_30 V_42 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < F_50 ( V_40 ) ; V_43 ++ ) {
V_41 = F_20 ( NULL , NULL , V_40 [ V_43 ] ) ;
F_41 ( V_41 , 0 , & V_42 ) ;
snprintf ( V_39 , sizeof( V_39 ) , L_21 ,
( unsigned long long ) V_42 . V_32 , 1 ) ;
F_51 ( V_39 , F_1 ) ;
F_51 ( V_39 , F_4 ) ;
snprintf ( V_39 , sizeof( V_39 ) , L_21 ,
( unsigned long long ) V_42 . V_32 , 7 ) ;
F_51 ( V_39 , F_4 ) ;
F_8 ( V_41 ) ;
}
return 0 ;
}
static int T_1 F_52 ( void )
{
if ( F_9 ( V_13 ) )
F_53 ( L_22 ) ;
if ( F_9 ( V_14 ) )
F_53 ( L_23 ) ;
return F_54 () ;
}
static void T_1 F_55 ( void )
{
struct V_44 * V_44 = F_56 ( NULL , 0 , V_45 |
V_46 ,
0 , 256 , L_24 ) ;
F_57 ( V_44 == NULL ) ;
F_58 ( V_44 ) ;
F_34 () ;
}
static int T_1 F_59 ( void )
{
unsigned long V_47 = F_60 () ;
return F_61 ( V_47 , L_25 ) ;
}
static int T_1 F_62 ( void )
{
unsigned long V_47 = F_60 () ;
return F_61 ( V_47 , L_26 ) ;
}
static int T_1 F_63 ( void )
{
unsigned long V_47 = F_60 () ;
return F_61 ( V_47 , L_27 ) ;
}
