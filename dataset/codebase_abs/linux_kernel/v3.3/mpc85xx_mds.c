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
#define F_31 0x60
#define F_32 0x00008000
#define F_33 0x00001000
#define F_34 0x00000040
#define F_35 0x00000008
static T_4 T_3 * V_19 ;
V_11 = F_6 ( NULL , L_11 ) ;
if ( V_11 ) {
V_19 = F_7 ( V_11 , 0 ) + F_31 ;
if ( ! V_19 )
F_36 ( V_20 L_12
L_13
L_14 ) ;
else
F_37 ( V_19 , F_32 |
F_33 |
F_34 |
F_35 ) ;
F_8 ( V_11 ) ;
}
}
}
static void T_1 F_38 ( void )
{
struct V_10 * V_11 ;
V_11 = F_20 ( NULL , NULL , L_7 ) ;
if ( ! F_26 ( V_11 ) ) {
F_8 ( V_11 ) ;
return;
}
V_11 = F_20 ( NULL , NULL , L_15 ) ;
if ( ! V_11 ) {
V_11 = F_39 ( NULL , L_16 ) ;
if ( ! V_11 )
return;
}
if ( F_9 ( V_17 ) )
F_40 ( V_11 , 0 , V_21 ,
V_22 ) ;
else
F_40 ( V_11 , 0 , V_23 , NULL ) ;
F_8 ( V_11 ) ;
}
static void T_1 F_25 ( void ) { }
static void T_1 F_38 ( void ) { }
static void T_1 F_41 ( void )
{
#ifdef F_42
struct V_24 * V_25 ;
struct V_10 * V_11 ;
#endif
T_5 V_26 = 0xffffffff ;
if ( V_27 . V_28 )
V_27 . V_28 ( L_17 , 0 ) ;
#ifdef F_42
F_43 (np, L_18 ) {
if ( F_44 ( V_11 , L_19 ) ||
F_44 ( V_11 , L_20 ) ) {
struct V_29 V_30 ;
F_45 ( V_11 , 0 , & V_30 ) ;
if ( ( V_30 . V_31 & 0xfffff ) == 0x8000 )
F_46 ( V_11 , 1 ) ;
else
F_46 ( V_11 , 0 ) ;
V_25 = F_47 ( V_11 ) ;
V_26 = F_48 ( V_26 , V_25 -> V_32 +
V_25 -> V_33 ) ;
}
}
#endif
F_49 () ;
F_25 () ;
#ifdef F_50
if ( F_51 () > V_26 ) {
V_34 = 1 ;
F_52 ( & V_35 ) ;
V_27 . V_36 = V_37 ;
}
#endif
}
static int T_1 F_53 ( void )
{
char V_38 [ 20 ] ;
char * V_39 [ 2 ] = { L_21 , L_22 } ;
struct V_10 * V_40 ;
struct V_29 V_41 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < F_54 ( V_39 ) ; V_42 ++ ) {
V_40 = F_20 ( NULL , NULL , V_39 [ V_42 ] ) ;
F_45 ( V_40 , 0 , & V_41 ) ;
snprintf ( V_38 , sizeof( V_38 ) , L_23 ,
( unsigned long long ) V_41 . V_31 , 1 ) ;
F_55 ( V_38 , F_1 ) ;
F_55 ( V_38 , F_4 ) ;
snprintf ( V_38 , sizeof( V_38 ) , L_23 ,
( unsigned long long ) V_41 . V_31 , 7 ) ;
F_55 ( V_38 , F_4 ) ;
F_8 ( V_40 ) ;
}
return 0 ;
}
static int T_1 F_56 ( void )
{
if ( F_9 ( V_13 ) )
F_57 ( L_24 ) ;
if ( F_9 ( V_14 ) )
F_57 ( L_25 ) ;
F_58 () ;
F_59 ( NULL , V_43 , NULL ) ;
return 0 ;
}
static void T_1 F_60 ( void )
{
struct V_44 * V_44 = F_61 ( NULL , 0 ,
V_45 | V_46 |
V_47 | V_48 ,
0 , 256 , L_26 ) ;
F_62 ( V_44 == NULL ) ;
F_63 ( V_44 ) ;
F_38 () ;
}
static int T_1 F_64 ( void )
{
unsigned long V_49 = F_65 () ;
return F_66 ( V_49 , L_27 ) ;
}
static int T_1 F_67 ( void )
{
unsigned long V_49 = F_65 () ;
return F_66 ( V_49 , L_28 ) ;
}
static int T_1 F_68 ( void )
{
unsigned long V_49 = F_65 () ;
return F_66 ( V_49 , L_29 ) ;
}
