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
F_20 (np, L_2 , L_3 ) {
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
V_11 = F_26 ( NULL , NULL , L_7 ) ;
if ( ! V_11 ) {
V_11 = F_6 ( NULL , L_8 ) ;
if ( ! V_11 )
return;
}
if ( ! F_27 ( V_11 ) ) {
F_8 ( V_11 ) ;
return;
}
F_28 () ;
F_8 ( V_11 ) ;
V_11 = F_6 ( NULL , L_9 ) ;
if ( V_11 ) {
struct V_10 * V_18 ;
F_29 ( V_11 ) ;
F_8 ( V_11 ) ;
F_30 (ucc, L_10 )
F_31 ( V_18 ) ;
}
F_5 () ;
if ( F_9 ( V_17 ) ) {
struct V_19 T_3 * V_20 ;
V_11 = F_6 ( NULL , L_11 ) ;
if ( V_11 ) {
V_20 = F_7 ( V_11 , 0 ) ;
if ( ! V_20 )
F_32 ( L_12 ) ;
else{
F_33 ( & V_20 -> V_21 , F_34 ( 0 ) |
F_34 ( 3 ) |
F_34 ( 9 ) |
F_34 ( 12 ) ) ;
F_24 ( V_20 ) ;
}
F_8 ( V_11 ) ;
}
}
}
static void T_1 F_35 ( void )
{
struct V_10 * V_11 ;
V_11 = F_26 ( NULL , NULL , L_7 ) ;
if ( ! F_27 ( V_11 ) ) {
F_8 ( V_11 ) ;
return;
}
V_11 = F_26 ( NULL , NULL , L_13 ) ;
if ( ! V_11 ) {
V_11 = F_36 ( NULL , L_14 ) ;
if ( ! V_11 )
return;
}
if ( F_9 ( V_17 ) )
F_37 ( V_11 , 0 , V_22 ,
V_23 ) ;
else
F_37 ( V_11 , 0 , V_24 , NULL ) ;
F_8 ( V_11 ) ;
}
static void T_1 F_25 ( void ) { }
static void T_1 F_35 ( void ) { }
static void T_1 F_38 ( void )
{
if ( V_25 . V_26 )
V_25 . V_26 ( L_15 , 0 ) ;
F_39 () ;
F_25 () ;
F_40 () ;
F_41 () ;
}
static int T_1 F_42 ( void )
{
char V_27 [ 20 ] ;
char * V_28 [ 2 ] = { L_16 , L_17 } ;
struct V_10 * V_29 ;
struct V_30 V_31 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < F_43 ( V_28 ) ; V_32 ++ ) {
V_29 = F_26 ( NULL , NULL , V_28 [ V_32 ] ) ;
F_44 ( V_29 , 0 , & V_31 ) ;
snprintf ( V_27 , sizeof( V_27 ) , L_18 ,
( unsigned long long ) V_31 . V_33 , 1 ) ;
F_45 ( V_27 , F_1 ) ;
F_45 ( V_27 , F_4 ) ;
snprintf ( V_27 , sizeof( V_27 ) , L_18 ,
( unsigned long long ) V_31 . V_33 , 7 ) ;
F_45 ( V_27 , F_4 ) ;
F_8 ( V_29 ) ;
}
return 0 ;
}
static int T_1 F_46 ( void )
{
if ( F_9 ( V_13 ) )
F_47 ( L_19 ) ;
if ( F_9 ( V_14 ) )
F_47 ( L_20 ) ;
return F_48 () ;
}
static void T_1 F_49 ( void )
{
struct V_34 * V_34 = F_50 ( NULL , 0 , V_35 |
V_36 ,
0 , 256 , L_21 ) ;
F_51 ( V_34 == NULL ) ;
F_52 ( V_34 ) ;
F_35 () ;
}
static int T_1 F_53 ( void )
{
unsigned long V_37 = F_54 () ;
return F_55 ( V_37 , L_22 ) ;
}
static int T_1 F_56 ( void )
{
unsigned long V_37 = F_54 () ;
return F_55 ( V_37 , L_23 ) ;
}
static int T_1 F_57 ( void )
{
unsigned long V_37 = F_54 () ;
return F_55 ( V_37 , L_24 ) ;
}
