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
F_5 ( L_1 , V_3 ) ;
V_7 = F_6 ( V_3 , L_2 , & V_4 ) ;
if ( V_7 == NULL || V_4 < 2 * sizeof( int ) )
F_5 ( V_8 L_3
L_4 , V_3 ) ;
V_6 = F_7 ( V_3 ) ;
if ( V_6 == NULL )
return - V_9 ;
V_6 -> V_10 = V_7 ? V_7 [ 0 ] : 0 ;
V_6 -> V_11 = V_7 ? V_7 [ 1 ] : 0xff ;
F_8 ( V_6 , 0xfec00000 , 0xfee00000 , 0 ) ;
F_9 ( V_6 , V_3 , 1 ) ;
#endif
return 0 ;
}
static void T_1 F_10 ( void )
{
struct V_2 * V_12 ;
F_11 (np, L_5 , L_6 )
F_3 ( V_12 ) ;
F_5 ( V_13 L_7 ) ;
F_5 ( V_13 L_8 ) ;
}
static void T_1 F_12 ( void )
{
struct V_14 * V_14 ;
V_14 = F_13 ( NULL , 0 , 0 , 4 , 0 , L_9 ) ;
F_14 ( V_14 == NULL ) ;
F_15 ( V_14 , 0 , V_14 -> V_15 + 0x10200 ) ;
F_15 ( V_14 , 1 , V_14 -> V_15 + 0x11000 ) ;
F_15 ( V_14 , 2 , V_14 -> V_15 + 0x11100 ) ;
F_16 ( V_14 ) ;
}
static void T_2 F_17 ( char * V_16 )
{
F_18 () ;
F_19 () ;
F_20 ( 'C' ) ;
for(; ; )
F_20 ( 'G' ) ;
}
static void T_2 F_21 ( void )
{
F_18 () ;
F_19 () ;
F_20 ( 'E' ) ;
for(; ; )
F_20 ( 'G' ) ;
}
static void T_2 F_22 ( void )
{
F_21 () ;
}
static void F_23 ( struct V_17 * V_18 )
{
F_24 ( V_18 , L_10 ) ;
F_24 ( V_18 , L_11 ) ;
}
static int T_1 F_25 ( void )
{
if ( ! F_26 ( L_12 ) )
return 0 ;
V_19 = F_21 ;
return 1 ;
}
