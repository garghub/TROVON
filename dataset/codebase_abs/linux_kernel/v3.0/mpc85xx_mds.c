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
V_11 = F_6 ( NULL , NULL , L_1 ) ;
if ( ! F_7 ( V_11 ) ) {
F_8 ( V_11 ) ;
return;
}
F_9 ( NULL , V_12 , NULL ) ;
}
static void T_1 F_10 ( void )
{
struct V_10 * V_11 ;
static T_2 T_3 * V_13 ;
V_11 = F_11 ( NULL , L_2 ) ;
if ( ! V_11 )
return;
V_13 = F_12 ( V_11 , 0 ) ;
F_8 ( V_11 ) ;
if ( ! V_13 )
return;
if ( F_13 ( V_14 ) ) {
#define F_14 (0x1 << 7)
#define F_15 (0x1 << 7)
#define F_16 (0x3 << 4)
#define F_17 (0x3 << 0)
F_18 ( & V_13 [ 8 ] , F_14 ) ;
F_18 ( & V_13 [ 9 ] , F_15 ) ;
F_18 ( & V_13 [ 11 ] , F_16 |
F_17 ) ;
F_19 ( & V_13 [ 8 ] , F_14 ) ;
F_19 ( & V_13 [ 9 ] , F_15 ) ;
} else if ( F_13 ( V_15 ) ) {
#define F_20 (0x1 << 2)
#define F_21 (0x1 << 1)
#define F_22 (0x1 << 6)
#define F_23 (0x1 << 5)
F_18 ( & V_13 [ 7 ] , F_20 ) ;
F_19 ( & V_13 [ 8 ] , F_21 ) ;
F_19 ( & V_13 [ 7 ] , F_20 ) ;
F_18 ( & V_13 [ 8 ] , F_21 ) ;
for ( V_11 = NULL ; ( V_11 = F_6 ( V_11 ,
L_3 ,
L_4 ) ) != NULL ; ) {
const unsigned int * V_16 ;
int V_17 ;
V_16 = F_24 ( V_11 , L_5 , NULL ) ;
if ( V_16 == NULL )
continue;
V_17 = * V_16 - 1 ;
V_16 = F_24 ( V_11 , L_6 , NULL ) ;
if ( V_16 == NULL )
continue;
if ( strcmp ( L_7 , ( const char * ) V_16 ) == 0 )
F_25 ( & V_13 [ 7 + V_17 ] ,
F_22 , F_23 ) ;
}
} else if ( F_13 ( V_18 ) ) {
#define F_26 (0x1 << 5)
F_18 ( & V_13 [ 11 ] , F_26 ) ;
F_19 ( & V_13 [ 11 ] , F_26 ) ;
}
F_27 ( V_13 ) ;
}
static void T_1 F_28 ( void )
{
struct V_10 * V_11 ;
V_11 = F_6 ( NULL , NULL , L_1 ) ;
if ( ! V_11 ) {
V_11 = F_11 ( NULL , L_8 ) ;
if ( ! V_11 )
return;
}
if ( ! F_7 ( V_11 ) ) {
F_8 ( V_11 ) ;
return;
}
F_29 () ;
F_8 ( V_11 ) ;
V_11 = F_11 ( NULL , L_9 ) ;
if ( V_11 ) {
struct V_10 * V_19 ;
F_30 ( V_11 ) ;
F_8 ( V_11 ) ;
F_31 (ucc, L_10 )
F_32 ( V_19 ) ;
}
F_10 () ;
if ( F_13 ( V_18 ) ) {
#define F_33 0x60
#define F_34 0x00008000
#define F_35 0x00001000
#define F_36 0x00000040
#define F_37 0x00000008
static T_4 T_3 * V_20 ;
V_11 = F_11 ( NULL , L_11 ) ;
if ( V_11 ) {
V_20 = F_12 ( V_11 , 0 ) + F_33 ;
if ( ! V_20 )
F_38 ( V_21 L_12
L_13
L_14 ) ;
else
F_39 ( V_20 , F_34 |
F_35 |
F_36 |
F_37 ) ;
F_8 ( V_11 ) ;
}
}
}
static void T_1 F_40 ( void )
{
struct V_10 * V_11 ;
V_11 = F_6 ( NULL , NULL , L_1 ) ;
if ( ! F_7 ( V_11 ) ) {
F_8 ( V_11 ) ;
return;
}
V_11 = F_6 ( NULL , NULL , L_15 ) ;
if ( ! V_11 ) {
V_11 = F_41 ( NULL , L_16 ) ;
if ( ! V_11 )
return;
}
if ( F_13 ( V_18 ) )
F_42 ( V_11 , 0 , V_22 ,
V_23 ) ;
else
F_42 ( V_11 , 0 , V_24 , NULL ) ;
F_8 ( V_11 ) ;
}
static void T_1 F_5 ( void ) { }
static void T_1 F_28 ( void ) { }
static void T_1 F_40 ( void ) { }
static void T_1 F_43 ( void )
{
#ifdef F_44
struct V_25 * V_26 ;
struct V_10 * V_11 ;
#endif
T_5 V_27 = 0xffffffff ;
if ( V_28 . V_29 )
V_28 . V_29 ( L_17 , 0 ) ;
#ifdef F_44
F_45 (np, L_18 ) {
if ( F_46 ( V_11 , L_19 ) ||
F_46 ( V_11 , L_20 ) ) {
struct V_30 V_31 ;
F_47 ( V_11 , 0 , & V_31 ) ;
if ( ( V_31 . V_32 & 0xfffff ) == 0x8000 )
F_48 ( V_11 , 1 ) ;
else
F_48 ( V_11 , 0 ) ;
V_26 = F_49 ( V_11 ) ;
V_27 = F_50 ( V_27 , V_26 -> V_33 +
V_26 -> V_34 ) ;
}
}
#endif
#ifdef F_51
F_52 () ;
#endif
F_28 () ;
#ifdef F_53
if ( F_54 () > V_27 ) {
V_35 = 1 ;
F_55 ( & V_36 ) ;
V_28 . V_37 = V_38 ;
}
#endif
}
static int T_1 F_56 ( void )
{
char V_39 [ 20 ] ;
char * V_40 [ 2 ] = { L_21 , L_22 } ;
struct V_10 * V_41 ;
struct V_30 V_42 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < F_57 ( V_40 ) ; V_43 ++ ) {
V_41 = F_6 ( NULL , NULL , V_40 [ V_43 ] ) ;
F_47 ( V_41 , 0 , & V_42 ) ;
snprintf ( V_39 , sizeof( V_39 ) , L_23 ,
( unsigned long long ) V_42 . V_32 , 1 ) ;
F_58 ( V_39 , F_1 ) ;
F_58 ( V_39 , F_4 ) ;
snprintf ( V_39 , sizeof( V_39 ) , L_23 ,
( unsigned long long ) V_42 . V_32 , 7 ) ;
F_58 ( V_39 , F_4 ) ;
F_8 ( V_41 ) ;
}
return 0 ;
}
static int T_1 F_59 ( void )
{
if ( F_13 ( V_14 ) )
F_60 ( L_24 ) ;
if ( F_13 ( V_15 ) )
F_60 ( L_25 ) ;
F_9 ( NULL , V_44 , NULL ) ;
F_5 () ;
return 0 ;
}
static int T_1 F_61 ( void )
{
F_9 ( NULL , V_45 , NULL ) ;
F_5 () ;
return 0 ;
}
static void T_1 F_62 ( void )
{
struct V_46 * V_46 ;
struct V_30 V_47 ;
struct V_10 * V_11 = NULL ;
V_11 = F_41 ( NULL , L_26 ) ;
if ( ! V_11 )
return;
if ( F_47 ( V_11 , 0 , & V_47 ) ) {
F_38 ( V_48 L_27 ) ;
F_8 ( V_11 ) ;
return;
}
V_46 = F_63 ( V_11 , V_47 . V_32 ,
V_49 | V_50 | V_51 |
V_52 | V_53 ,
0 , 256 , L_28 ) ;
F_64 ( V_46 == NULL ) ;
F_8 ( V_11 ) ;
F_65 ( V_46 ) ;
F_40 () ;
}
static int T_1 F_66 ( void )
{
unsigned long V_54 = F_67 () ;
return F_68 ( V_54 , L_29 ) ;
}
static int T_1 F_69 ( void )
{
unsigned long V_54 = F_67 () ;
return F_68 ( V_54 , L_30 ) ;
}
static int T_1 F_70 ( void )
{
unsigned long V_54 = F_67 () ;
return F_68 ( V_54 , L_31 ) ;
}
