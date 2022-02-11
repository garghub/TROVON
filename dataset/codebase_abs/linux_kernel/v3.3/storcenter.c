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
V_6 = F_6 ( V_3 ) ;
if ( V_6 == NULL )
return - V_9 ;
V_7 = F_7 ( V_3 , L_2 , & V_4 ) ;
V_6 -> V_10 = V_7 ? V_7 [ 0 ] : 0 ;
V_6 -> V_11 = V_7 ? V_7 [ 1 ] : 0xff ;
F_8 ( V_6 , V_12 , V_13 , 0 ) ;
F_9 ( V_6 , V_3 , 1 ) ;
#endif
return 0 ;
}
static void T_1 F_10 ( void )
{
struct V_2 * V_14 ;
F_11 (np, L_3 , L_4 )
F_3 ( V_14 ) ;
F_5 ( V_15 L_5 ) ;
}
static void T_1 F_12 ( void )
{
struct V_16 * V_16 ;
V_16 = F_13 ( NULL , 0 , V_17 ,
16 , 32 , L_6 ) ;
F_14 ( V_16 == NULL ) ;
F_15 ( V_16 , 0 , V_16 -> V_18 + 0x10200 ) ;
F_15 ( V_16 , 1 , V_16 -> V_18 + 0x11000 ) ;
F_16 ( V_16 ) ;
}
static void F_17 ( char * V_19 )
{
F_18 () ;
F_19 ( 0 , V_20 ) ;
for (; ; ) ;
}
static int T_1 F_20 ( void )
{
unsigned long V_21 = F_21 () ;
return F_22 ( V_21 , L_7 ) ;
}
