static void T_1 F_1 ( void )
{
struct V_1 * V_1 = F_2 ( NULL , 0 ,
V_2 | V_3 ,
0 , 256 , L_1 ) ;
F_3 ( V_1 == NULL ) ;
F_4 ( V_1 ) ;
}
static int T_1 F_5 ( void )
{
struct V_4 * V_5 ;
struct V_6 V_7 ;
unsigned int * V_8 ;
int V_9 = 0 ;
V_5 = F_6 ( NULL , NULL , L_2 ) ;
if ( V_5 == NULL ) {
F_7 ( L_3 ) ;
return - V_10 ;
}
F_8 ( V_5 , 0 , & V_7 ) ;
F_9 ( V_5 ) ;
V_8 = F_10 ( V_7 . V_11 , sizeof( unsigned int ) ) ;
V_9 = ( * V_8 ) >> 28 ;
F_11 ( V_8 ) ;
return V_9 ;
}
static void T_1 F_12 ( void )
{
#ifdef F_13
struct V_4 * V_5 ;
#endif
if ( V_12 . V_13 )
V_12 . V_13 ( L_4 , 0 ) ;
#ifdef F_13
F_14 (np, L_5 ) {
if ( F_15 ( V_5 , L_6 ) ||
F_15 ( V_5 , L_7 ) ) {
struct V_6 V_14 ;
F_8 ( V_5 , 0 , & V_14 ) ;
if ( ( V_14 . V_11 & 0xfffff ) == 0x8000 )
F_16 ( V_5 , 1 ) ;
else
F_16 ( V_5 , 0 ) ;
}
}
#endif
V_15 = F_5 () ;
}
static void F_17 ( struct V_16 * V_17 )
{
T_2 V_18 , V_19 , V_20 ;
V_18 = F_18 ( V_21 ) ;
V_19 = F_18 ( V_22 ) ;
F_19 ( V_17 , L_8 ) ;
F_19 ( V_17 , L_9 , V_15 ) ;
F_19 ( V_17 , L_10 , V_18 ) ;
F_19 ( V_17 , L_11 , V_19 ) ;
V_20 = F_18 ( V_23 ) ;
F_19 ( V_17 , L_12 , ( ( V_20 >> 24 ) & 0x3f ) ) ;
}
static int T_1 F_20 ( void )
{
unsigned long V_24 = F_21 () ;
return F_22 ( V_24 , L_13 ) ;
}
