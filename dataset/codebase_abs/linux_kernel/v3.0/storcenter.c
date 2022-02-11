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
struct V_2 * V_17 ;
const void * V_18 ;
int V_19 ;
T_2 V_20 ;
V_17 = F_13 ( NULL , L_6 ) ;
if ( V_17 == NULL )
return;
V_18 = F_7 ( V_17 , L_7 , & V_19 ) ;
if ( V_18 == NULL ) {
F_14 ( V_17 ) ;
return;
}
V_20 = ( T_2 ) F_15 ( V_17 , V_18 ) ;
V_16 = F_16 ( V_17 , V_20 , V_21 | V_22 ,
16 , 32 , L_8 ) ;
F_14 ( V_17 ) ;
F_17 ( V_16 == NULL ) ;
F_18 ( V_16 , 0 , V_20 + 0x10200 ) ;
F_18 ( V_16 , 1 , V_20 + 0x11000 ) ;
F_19 ( V_16 ) ;
}
static void F_20 ( char * V_23 )
{
F_21 () ;
F_22 ( 0 , V_24 ) ;
for (; ; ) ;
}
static int T_1 F_23 ( void )
{
unsigned long V_25 = F_24 () ;
return F_25 ( V_25 , L_9 ) ;
}
