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
V_15 = F_13 ( NULL , 0 , 0 , 4 , 0 , L_9 ) ;
F_14 ( V_15 == NULL ) ;
F_15 ( V_15 , 0 , V_15 -> V_16 + 0x10200 ) ;
F_15 ( V_15 , 1 , V_15 -> V_16 + 0x11000 ) ;
F_15 ( V_15 , 2 , V_15 -> V_16 + 0x11100 ) ;
F_16 ( V_15 ) ;
}
static void F_17 ( char * V_17 )
{
F_18 () ;
F_19 () ;
F_20 ( 'C' ) ;
for(; ; )
F_20 ( 'G' ) ;
}
static void F_21 ( void )
{
F_18 () ;
F_19 () ;
F_20 ( 'E' ) ;
for(; ; )
F_20 ( 'G' ) ;
}
static void F_22 ( void )
{
F_21 () ;
}
static void F_23 ( struct V_18 * V_19 )
{
F_24 ( V_19 , L_10 ) ;
F_24 ( V_19 , L_11 ) ;
}
static int T_1 F_25 ( void )
{
unsigned long V_20 ;
V_20 = F_26 () ;
if ( ! F_27 ( V_20 , L_12 ) )
return 0 ;
return 1 ;
}
