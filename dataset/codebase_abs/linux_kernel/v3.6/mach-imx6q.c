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
F_18 ( V_13 , NULL , L_7 ) ;
V_15:
if ( ! F_14 ( V_11 ) )
F_19 ( V_11 ) ;
if ( ! F_14 ( V_12 ) )
F_19 ( V_12 ) ;
if ( ! F_14 ( V_13 ) )
F_19 ( V_13 ) ;
}
static void T_2 F_20 ( void )
{
if ( F_10 ( V_9 ) )
F_21 ( V_16 , V_17 ,
F_9 ) ;
F_12 () ;
}
static void T_2 F_22 ( void )
{
struct V_3 * V_4 ;
struct V_18 * V_19 = NULL ;
struct V_20 * V_21 = NULL ;
V_4 = F_2 ( NULL , NULL , L_8 ) ;
if ( V_4 )
V_19 = F_23 ( V_4 ) ;
if ( V_19 )
V_21 = F_24 ( V_19 ) ;
if ( ! V_21 ) {
if ( V_4 )
F_25 ( V_4 ) ;
return;
}
#define F_26 0x000001b0
#define F_27 0x00000210
#define F_28 0x00100000
#define F_29 0x00080000
F_30 ( V_21 , F_26 ,
F_28
| F_29 ,
~ 0 ) ;
F_30 ( V_21 , F_27 ,
F_28 |
F_29 ,
~ 0 ) ;
F_25 ( V_4 ) ;
}
static void T_2 F_31 ( void )
{
F_32 () ;
if ( F_33 ( L_9 ) )
F_20 () ;
F_34 ( NULL , V_22 , NULL , NULL ) ;
F_35 () ;
F_22 () ;
}
static void T_2 F_36 ( void )
{
F_37 ( & V_23 ) ;
}
static void T_2 F_38 ( void )
{
F_39 () ;
F_40 () ;
F_41 () ;
}
static void T_2 F_42 ( void )
{
F_43 ( 0 , ~ 0UL ) ;
F_44 () ;
F_45 () ;
F_46 ( V_24 ) ;
}
static void T_2 F_47 ( void )
{
F_48 () ;
F_49 () ;
}
