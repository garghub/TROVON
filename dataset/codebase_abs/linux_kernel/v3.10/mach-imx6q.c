int F_1 ( void )
{
return V_1 ;
}
static void T_1 F_2 ( void )
{
T_2 V_2 = F_3 () ;
switch ( V_2 & 0xff ) {
case 0 :
V_1 = V_3 ;
break;
case 1 :
V_1 = V_4 ;
break;
case 2 :
V_1 = V_5 ;
break;
default:
V_1 = V_6 ;
}
F_4 ( V_2 >> 16 & 0xff ) ;
}
static void F_5 ( char V_7 , const char * V_8 )
{
struct V_9 * V_10 ;
void T_3 * V_11 ;
V_10 = F_6 ( NULL , NULL , L_1 ) ;
V_11 = F_7 ( V_10 , 0 ) ;
if ( ! V_11 )
goto V_12;
F_8 () ;
F_9 ( 1 << 2 , V_11 ) ;
F_9 ( 1 << 2 , V_11 ) ;
F_10 ( 500 ) ;
F_11 ( L_2 ) ;
F_10 ( 50 ) ;
V_12:
F_12 ( 0 ) ;
}
static int F_13 ( struct V_13 * V_14 )
{
if ( F_14 ( V_15 ) ) {
F_15 ( V_14 , 0x0b , 0x8105 ) ;
F_15 ( V_14 , 0x0c , 0x0000 ) ;
F_15 ( V_14 , 0x0b , 0x8104 ) ;
F_15 ( V_14 , 0x0c , 0xf0f0 ) ;
F_15 ( V_14 , 0x0b , 0x104 ) ;
}
return 0 ;
}
static void T_1 F_16 ( void )
{
struct V_16 * V_17 , * V_18 , * V_19 ;
unsigned long V_20 ;
V_17 = F_17 ( NULL , L_3 ) ;
V_18 = F_17 ( NULL , L_4 ) ;
V_19 = F_17 ( NULL , L_5 ) ;
if ( F_18 ( V_17 ) || F_18 ( V_18 ) || F_18 ( V_19 ) ) {
F_11 ( L_6 ) ;
goto V_21;
}
F_19 ( V_17 , V_18 ) ;
V_20 = F_20 ( V_19 , 16000000 ) ;
F_21 ( V_19 , V_20 ) ;
V_21:
if ( ! F_18 ( V_17 ) )
F_22 ( V_17 ) ;
if ( ! F_18 ( V_18 ) )
F_22 ( V_18 ) ;
if ( ! F_18 ( V_19 ) )
F_22 ( V_19 ) ;
}
static void T_1 F_23 ( void )
{
if ( F_14 ( V_15 ) )
F_24 ( V_22 , V_23 ,
F_13 ) ;
F_16 () ;
}
static void T_1 F_25 ( void )
{
struct V_24 * V_25 ;
V_25 = F_26 ( L_7 ) ;
if ( ! F_18 ( V_25 ) )
F_27 ( V_25 , 0x4 , 1 << 21 , 1 << 21 ) ;
else
F_11 ( L_8 ) ;
}
static void T_1 F_28 ( void )
{
F_29 () ;
}
static void T_1 F_30 ( void )
{
if ( F_31 ( L_9 ) )
F_23 () ;
F_32 ( NULL , V_26 , NULL , NULL ) ;
F_33 () ;
F_34 () ;
F_28 () ;
F_25 () ;
}
static void T_1 F_35 ( struct V_27 * V_28 )
{
struct V_9 * V_10 ;
void T_3 * V_29 ;
T_2 V_30 ;
V_10 = F_6 ( NULL , NULL , L_10 ) ;
if ( ! V_10 ) {
F_36 ( L_11 ) ;
return;
}
V_29 = F_7 ( V_10 , 0 ) ;
if ( ! V_29 ) {
F_36 ( L_12 ) ;
goto V_31;
}
V_30 = F_37 ( V_29 + V_32 ) ;
V_30 >>= V_33 ;
if ( ( V_30 & 0x3 ) != V_34 )
if ( F_38 ( V_28 , 1200000000 ) )
F_36 ( L_13 ) ;
V_31:
F_39 ( V_10 ) ;
}
static void T_1 F_40 ( struct V_27 * V_28 )
{
struct V_9 * V_10 ;
V_10 = F_41 ( L_14 ) ;
if ( ! V_10 ) {
F_36 ( L_15 ) ;
return;
}
V_28 -> V_35 = V_10 ;
if ( F_42 ( V_28 ) ) {
F_36 ( L_16 ) ;
goto V_31;
}
F_35 ( V_28 ) ;
V_31:
F_39 ( V_10 ) ;
}
static void T_1 F_43 ( void )
{
if ( F_1 () > V_4 )
F_44 () ;
if ( F_45 ( V_36 ) ) {
F_40 ( & V_37 . V_38 ) ;
F_46 ( & V_37 ) ;
}
}
static void T_1 F_47 ( void )
{
F_48 () ;
F_49 () ;
}
static void T_1 F_50 ( void )
{
F_2 () ;
F_51 ( 0 , ~ 0UL ) ;
F_52 () ;
F_53 () ;
F_54 () ;
}
static void T_1 F_55 ( void )
{
F_56 () ;
F_57 () ;
F_58 ( F_59 () ? L_17 : L_18 ,
F_1 () ) ;
}
