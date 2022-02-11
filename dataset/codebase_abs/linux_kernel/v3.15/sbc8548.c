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
if ( V_11 . V_12 )
V_11 . V_12 ( L_4 , 0 ) ;
F_13 () ;
V_13 = F_5 () ;
}
static void F_14 ( struct V_14 * V_15 )
{
T_2 V_16 , V_17 , V_18 ;
V_16 = F_15 ( V_19 ) ;
V_17 = F_15 ( V_20 ) ;
F_16 ( V_15 , L_5 ) ;
F_16 ( V_15 , L_6 , V_13 ) ;
F_16 ( V_15 , L_7 , V_16 ) ;
F_16 ( V_15 , L_8 , V_17 ) ;
V_18 = F_15 ( V_21 ) ;
F_16 ( V_15 , L_9 , ( ( V_18 >> 24 ) & 0x3f ) ) ;
}
static int T_1 F_17 ( void )
{
unsigned long V_22 = F_18 () ;
return F_19 ( V_22 , L_10 ) ;
}
