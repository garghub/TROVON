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
F_26 () ;
F_5 () ;
if ( F_9 ( V_17 ) ) {
struct V_18 T_3 * V_19 ;
V_11 = F_6 ( NULL , L_7 ) ;
if ( V_11 ) {
V_19 = F_7 ( V_11 , 0 ) ;
if ( ! V_19 )
F_27 ( L_8 ) ;
else{
F_28 ( & V_19 -> V_20 , F_29 ( 0 ) |
F_29 ( 3 ) |
F_29 ( 9 ) |
F_29 ( 12 ) ) ;
F_24 ( V_19 ) ;
}
F_8 ( V_11 ) ;
}
}
}
static void T_1 F_30 ( void )
{
struct V_10 * V_11 ;
V_11 = F_31 ( NULL , NULL , L_9 ) ;
if ( ! F_32 ( V_11 ) ) {
F_8 ( V_11 ) ;
return;
}
V_11 = F_31 ( NULL , NULL , L_10 ) ;
if ( ! V_11 ) {
V_11 = F_33 ( NULL , L_11 ) ;
if ( ! V_11 )
return;
}
if ( F_9 ( V_17 ) )
F_34 ( V_11 , 0 , V_21 ,
V_22 ) ;
else
F_34 ( V_11 , 0 , V_23 , NULL ) ;
F_8 ( V_11 ) ;
}
static void T_1 F_25 ( void ) { }
static void T_1 F_30 ( void ) { }
static void T_1 F_35 ( void )
{
if ( V_24 . V_25 )
V_24 . V_25 ( L_12 , 0 ) ;
F_36 () ;
F_25 () ;
F_37 () ;
F_38 () ;
}
static int T_1 F_39 ( void )
{
char V_26 [ 20 ] ;
char * V_27 [ 2 ] = { L_13 , L_14 } ;
struct V_10 * V_28 ;
struct V_29 V_30 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < F_40 ( V_27 ) ; V_31 ++ ) {
V_28 = F_31 ( NULL , NULL , V_27 [ V_31 ] ) ;
F_41 ( V_28 , 0 , & V_30 ) ;
snprintf ( V_26 , sizeof( V_26 ) , L_15 ,
( unsigned long long ) V_30 . V_32 , 1 ) ;
F_42 ( V_26 , F_1 ) ;
F_42 ( V_26 , F_4 ) ;
snprintf ( V_26 , sizeof( V_26 ) , L_15 ,
( unsigned long long ) V_30 . V_32 , 7 ) ;
F_42 ( V_26 , F_4 ) ;
F_8 ( V_28 ) ;
}
return 0 ;
}
static int T_1 F_43 ( void )
{
if ( F_9 ( V_13 ) )
F_44 ( L_16 ) ;
if ( F_9 ( V_14 ) )
F_44 ( L_17 ) ;
return F_45 () ;
}
static void T_1 F_46 ( void )
{
struct V_33 * V_33 = F_47 ( NULL , 0 , V_34 |
V_35 ,
0 , 256 , L_18 ) ;
F_48 ( V_33 == NULL ) ;
F_49 ( V_33 ) ;
F_30 () ;
}
static int T_1 F_50 ( void )
{
unsigned long V_36 = F_51 () ;
return F_52 ( V_36 , L_19 ) ;
}
static int T_1 F_53 ( void )
{
unsigned long V_36 = F_51 () ;
return F_52 ( V_36 , L_20 ) ;
}
static int T_1 F_54 ( void )
{
unsigned long V_36 = F_51 () ;
return F_52 ( V_36 , L_21 ) ;
}
