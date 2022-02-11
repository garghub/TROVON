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
if ( F_10 ( V_9 ) ) {
F_11 ( V_8 , 0x0b , 0x8105 ) ;
F_11 ( V_8 , 0x0c , 0x0000 ) ;
F_11 ( V_8 , 0x0b , 0x8104 ) ;
F_11 ( V_8 , 0x0c , 0xf0f0 ) ;
F_11 ( V_8 , 0x0b , 0x104 ) ;
}
return 0 ;
}
static void T_2 F_12 ( void )
{
struct V_10 * V_11 , * V_12 , * V_13 ;
unsigned long V_14 ;
V_11 = F_13 ( NULL , L_3 ) ;
V_12 = F_13 ( NULL , L_4 ) ;
V_13 = F_13 ( NULL , L_5 ) ;
if ( F_14 ( V_11 ) || F_14 ( V_12 ) || F_14 ( V_13 ) ) {
F_7 ( L_6 ) ;
goto V_15;
}
F_15 ( V_11 , V_12 ) ;
V_14 = F_16 ( V_13 , 16000000 ) ;
F_17 ( V_13 , V_14 ) ;
V_15:
if ( ! F_14 ( V_11 ) )
F_18 ( V_11 ) ;
if ( ! F_14 ( V_12 ) )
F_18 ( V_12 ) ;
if ( ! F_14 ( V_13 ) )
F_18 ( V_13 ) ;
}
static void T_2 F_19 ( void )
{
if ( F_10 ( V_9 ) )
F_20 ( V_16 , V_17 ,
F_9 ) ;
F_12 () ;
}
static void T_2 F_21 ( void )
{
struct V_18 * V_19 ;
#define F_22 0x000001b0
#define F_23 0x00000210
#define F_24 0x00100000
#define F_25 0x00080000
V_19 = F_26 ( L_7 ) ;
if ( ! F_14 ( V_19 ) ) {
F_27 ( V_19 , F_22 ,
F_24
| F_25 ) ;
F_27 ( V_19 , F_23 ,
F_24 |
F_25 ) ;
} else {
F_28 ( L_8 ) ;
}
}
static void T_2 F_29 ( void )
{
if ( F_30 ( L_9 ) )
F_19 () ;
F_31 ( NULL , V_20 , NULL , NULL ) ;
F_32 () ;
F_21 () ;
}
static void T_2 F_33 ( void )
{
F_34 ( & V_21 ) ;
}
static void T_2 F_35 ( void )
{
F_36 () ;
F_37 () ;
F_38 () ;
}
static void T_2 F_39 ( void )
{
F_40 ( 0 , ~ 0UL ) ;
F_41 () ;
F_42 () ;
F_43 ( V_22 ) ;
}
static void T_2 F_44 ( void )
{
F_45 () ;
F_46 () ;
}
