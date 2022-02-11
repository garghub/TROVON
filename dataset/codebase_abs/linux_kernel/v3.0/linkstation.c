static int T_1 F_1 ( void )
{
F_2 ( NULL , V_1 , NULL ) ;
return 0 ;
}
static int T_1 F_3 ( struct V_2 * V_3 )
{
#ifdef F_4
int V_4 ;
struct V_5 * V_6 ;
const int * V_7 ;
F_5 ( L_1 , V_3 -> V_8 ) ;
V_7 = F_6 ( V_3 , L_2 , & V_4 ) ;
if ( V_7 == NULL || V_4 < 2 * sizeof( int ) )
F_5 ( V_9 L_3
L_4 , V_3 -> V_8 ) ;
V_6 = F_7 ( V_3 ) ;
if ( V_6 == NULL )
return - V_10 ;
V_6 -> V_11 = V_7 ? V_7 [ 0 ] : 0 ;
V_6 -> V_12 = V_7 ? V_7 [ 1 ] : 0xff ;
F_8 ( V_6 , 0xfec00000 , 0xfee00000 , 0 ) ;
F_9 ( V_6 , V_3 , 1 ) ;
#endif
return 0 ;
}
static void T_1 F_10 ( void )
{
struct V_2 * V_13 ;
F_11 (np, L_5 , L_6 )
F_3 ( V_13 ) ;
F_5 ( V_14 L_7 ) ;
F_5 ( V_14 L_8 ) ;
}
static void T_1 F_12 ( void )
{
struct V_15 * V_15 ;
struct V_2 * V_16 ;
const T_2 * V_17 ;
int V_18 ;
T_3 V_19 ;
V_16 = F_13 ( NULL , L_9 ) ;
if ( V_16 == NULL )
return;
V_17 = F_6 ( V_16 , L_10 , & V_18 ) ;
V_19 = ( T_3 ) F_14 ( V_16 , V_17 ) ;
V_15 = F_15 ( V_16 , V_19 , V_20 | V_21 , 4 , 32 , L_11 ) ;
F_16 ( V_15 == NULL ) ;
F_17 ( V_15 , 0 , V_19 + 0x10200 ) ;
F_17 ( V_15 , 1 , V_19 + 0x11000 ) ;
F_17 ( V_15 , 2 , V_19 + 0x11100 ) ;
F_18 ( V_15 ) ;
}
static void F_19 ( char * V_22 )
{
F_20 () ;
F_21 () ;
F_22 ( 'C' ) ;
for(; ; )
F_22 ( 'G' ) ;
}
static void F_23 ( void )
{
F_20 () ;
F_21 () ;
F_22 ( 'E' ) ;
for(; ; )
F_22 ( 'G' ) ;
}
static void F_24 ( void )
{
F_23 () ;
}
static void F_25 ( struct V_23 * V_24 )
{
F_26 ( V_24 , L_12 ) ;
F_26 ( V_24 , L_13 ) ;
}
static int T_1 F_27 ( void )
{
unsigned long V_25 ;
V_25 = F_28 () ;
if ( ! F_29 ( V_25 , L_14 ) )
return 0 ;
return 1 ;
}
