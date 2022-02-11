static void T_1 F_1 ( void )
{
struct V_1 * V_1 = F_2 ( NULL , 0 , V_2 ,
0 , 256 , L_1 ) ;
F_3 ( V_1 == NULL ) ;
F_4 ( V_1 ) ;
}
static int T_1 F_5 ( void )
{
struct V_3 * V_4 ;
struct V_5 V_6 ;
unsigned int * V_7 ;
int V_8 = 0 ;
V_4 = F_6 ( NULL , NULL , L_2 ) ;
if ( V_4 == NULL ) {
F_7 ( L_3 ) ;
return - V_9 ;
}
F_8 ( V_4 , 0 , & V_6 ) ;
F_9 ( V_4 ) ;
V_7 = F_10 ( V_6 . V_10 , sizeof( unsigned int ) ) ;
V_8 = ( * V_7 ) >> 28 ;
F_11 ( V_7 ) ;
return V_8 ;
}
static void T_1 F_12 ( void )
{
#ifdef F_13
struct V_3 * V_4 ;
#endif
if ( V_11 . V_12 )
V_11 . V_12 ( L_4 , 0 ) ;
#ifdef F_13
F_14 (np, L_5 ) {
if ( F_15 ( V_4 , L_6 ) ||
F_15 ( V_4 , L_7 ) ) {
struct V_5 V_13 ;
F_8 ( V_4 , 0 , & V_13 ) ;
if ( ( V_13 . V_10 & 0xfffff ) == 0x8000 )
F_16 ( V_4 , 1 ) ;
else
F_16 ( V_4 , 0 ) ;
}
}
#endif
V_14 = F_5 () ;
}
static void F_17 ( struct V_15 * V_16 )
{
T_2 V_17 , V_18 , V_19 ;
V_17 = F_18 ( V_20 ) ;
V_18 = F_18 ( V_21 ) ;
F_19 ( V_16 , L_8 ) ;
F_19 ( V_16 , L_9 , V_14 ) ;
F_19 ( V_16 , L_10 , V_17 ) ;
F_19 ( V_16 , L_11 , V_18 ) ;
V_19 = F_18 ( V_22 ) ;
F_19 ( V_16 , L_12 , ( ( V_19 >> 24 ) & 0x3f ) ) ;
}
static int T_1 F_20 ( void )
{
unsigned long V_23 = F_21 () ;
return F_22 ( V_23 , L_13 ) ;
}
