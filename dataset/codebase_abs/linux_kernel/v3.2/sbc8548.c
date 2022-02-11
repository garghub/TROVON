static void T_1 F_1 ( void )
{
struct V_1 * V_1 ;
struct V_2 V_3 ;
struct V_4 * V_5 = NULL ;
V_5 = F_2 ( V_5 , L_1 ) ;
if ( V_5 == NULL ) {
F_3 ( V_6 L_2 ) ;
return;
}
if ( F_4 ( V_5 , 0 , & V_3 ) ) {
F_3 ( V_6 L_3 ) ;
F_5 ( V_5 ) ;
return;
}
V_1 = F_6 ( V_5 , V_3 . V_7 ,
V_8 | V_9 | V_10 ,
0 , 256 , L_4 ) ;
F_7 ( V_1 == NULL ) ;
F_5 ( V_5 ) ;
F_8 ( V_1 ) ;
}
static int T_1 F_9 ( void )
{
struct V_4 * V_5 ;
struct V_2 V_11 ;
unsigned int * V_12 ;
int V_13 = 0 ;
V_5 = F_10 ( NULL , NULL , L_5 ) ;
if ( V_5 == NULL ) {
F_3 ( L_6 ) ;
return - V_14 ;
}
F_4 ( V_5 , 0 , & V_11 ) ;
F_5 ( V_5 ) ;
V_12 = F_11 ( V_11 . V_7 , sizeof( unsigned int ) ) ;
V_13 = ( * V_12 ) >> 28 ;
F_12 ( V_12 ) ;
return V_13 ;
}
static void T_1 F_13 ( void )
{
#ifdef F_14
struct V_4 * V_5 ;
#endif
if ( V_15 . V_16 )
V_15 . V_16 ( L_7 , 0 ) ;
#ifdef F_14
F_15 (np, L_8 ) {
if ( F_16 ( V_5 , L_9 ) ||
F_16 ( V_5 , L_10 ) ) {
struct V_2 V_17 ;
F_4 ( V_5 , 0 , & V_17 ) ;
if ( ( V_17 . V_7 & 0xfffff ) == 0x8000 )
F_17 ( V_5 , 1 ) ;
else
F_17 ( V_5 , 0 ) ;
}
}
#endif
V_18 = F_9 () ;
}
static void F_18 ( struct V_19 * V_20 )
{
T_2 V_21 , V_22 , V_23 ;
V_21 = F_19 ( V_24 ) ;
V_22 = F_19 ( V_25 ) ;
F_20 ( V_20 , L_11 ) ;
F_20 ( V_20 , L_12 , V_18 ) ;
F_20 ( V_20 , L_13 , V_21 ) ;
F_20 ( V_20 , L_14 , V_22 ) ;
V_23 = F_19 ( V_26 ) ;
F_20 ( V_20 , L_15 , ( ( V_23 >> 24 ) & 0x3f ) ) ;
}
static int T_1 F_21 ( void )
{
F_22 ( NULL , V_27 , NULL ) ;
return 0 ;
}
static int T_1 F_23 ( void )
{
unsigned long V_28 = F_24 () ;
return F_25 ( V_28 , L_16 ) ;
}
