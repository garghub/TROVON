void F_1 ( char V_1 , const char * V_2 )
{
struct V_3 * V_4 ;
void T_1 * V_5 ;
V_4 = F_2 ( NULL , NULL , L_1 ) ;
V_5 = F_3 ( V_4 , 0 ) ;
if ( ! V_5 )
goto V_6;
F_4 () ;
F_5 ( 1 << 2 , V_5 ) ;
F_5 ( 1 << 2 , V_5 ) ;
F_6 ( 500 ) ;
F_7 ( L_2 ) ;
F_6 ( 50 ) ;
V_6:
F_8 ( 0 ) ;
}
static int F_9 ( struct V_7 * V_8 )
{
F_10 ( V_8 , 0x0b , 0x8105 ) ;
F_10 ( V_8 , 0x0c , 0x0000 ) ;
F_10 ( V_8 , 0x0b , 0x8104 ) ;
F_10 ( V_8 , 0x0c , 0xf0f0 ) ;
F_10 ( V_8 , 0x0b , 0x104 ) ;
return 0 ;
}
static void T_2 F_11 ( void )
{
if ( F_12 ( L_3 ) )
F_13 ( V_9 , V_10 ,
F_9 ) ;
F_14 ( NULL , V_11 , NULL , NULL ) ;
F_15 () ;
}
static void T_2 F_16 ( void )
{
F_17 () ;
F_18 () ;
F_19 () ;
}
static int T_2 F_20 ( struct V_3 * V_4 ,
struct V_3 * V_12 )
{
static int V_13 = V_14 + V_15 ;
V_13 -= 32 ;
F_21 ( V_4 , 32 , V_13 , 0 , & V_16 ,
NULL ) ;
return 0 ;
}
static void T_2 F_22 ( void )
{
F_23 ( 0 , ~ 0UL ) ;
F_24 () ;
F_25 () ;
F_26 ( V_17 ) ;
}
static void T_2 F_27 ( void )
{
F_28 () ;
F_29 () ;
}
