static int F_1 ( void )
{
struct V_1 * V_2 ;
void T_1 * V_3 ;
static T_2 V_4 ;
if ( ! V_4 ) {
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 )
return V_5 ;
V_3 = F_3 ( V_2 , 0 ) ;
if ( ! V_3 ) {
F_4 ( V_2 ) ;
return V_5 ;
}
V_4 = F_5 ( V_3 + V_6 ) ;
F_6 ( V_3 ) ;
F_4 ( V_2 ) ;
}
switch ( V_4 & 0xff ) {
case 0 :
return V_7 ;
case 1 :
return V_8 ;
case 2 :
return V_9 ;
default:
return V_5 ;
}
}
void F_7 ( char V_10 , const char * V_11 )
{
struct V_1 * V_2 ;
void T_1 * V_12 ;
V_2 = F_2 ( NULL , NULL , L_2 ) ;
V_12 = F_3 ( V_2 , 0 ) ;
if ( ! V_12 )
goto V_13;
F_8 () ;
F_9 ( 1 << 2 , V_12 ) ;
F_9 ( 1 << 2 , V_12 ) ;
F_10 ( 500 ) ;
F_11 ( L_3 ) ;
F_10 ( 50 ) ;
V_13:
F_12 ( 0 ) ;
}
static int F_13 ( struct V_14 * V_15 )
{
if ( F_14 ( V_16 ) ) {
F_15 ( V_15 , 0x0b , 0x8105 ) ;
F_15 ( V_15 , 0x0c , 0x0000 ) ;
F_15 ( V_15 , 0x0b , 0x8104 ) ;
F_15 ( V_15 , 0x0c , 0xf0f0 ) ;
F_15 ( V_15 , 0x0b , 0x104 ) ;
}
return 0 ;
}
static void T_3 F_16 ( void )
{
struct V_17 * V_18 , * V_19 , * V_20 ;
unsigned long V_21 ;
V_18 = F_17 ( NULL , L_4 ) ;
V_19 = F_17 ( NULL , L_5 ) ;
V_20 = F_17 ( NULL , L_6 ) ;
if ( F_18 ( V_18 ) || F_18 ( V_19 ) || F_18 ( V_20 ) ) {
F_11 ( L_7 ) ;
goto V_22;
}
F_19 ( V_18 , V_19 ) ;
V_21 = F_20 ( V_20 , 16000000 ) ;
F_21 ( V_20 , V_21 ) ;
V_22:
if ( ! F_18 ( V_18 ) )
F_22 ( V_18 ) ;
if ( ! F_18 ( V_19 ) )
F_22 ( V_19 ) ;
if ( ! F_18 ( V_20 ) )
F_22 ( V_20 ) ;
}
static void T_3 F_23 ( void )
{
if ( F_14 ( V_16 ) )
F_24 ( V_23 , V_24 ,
F_13 ) ;
F_16 () ;
}
static void T_3 F_25 ( void )
{
struct V_25 * V_26 ;
V_26 = F_26 ( L_8 ) ;
if ( ! F_18 ( V_26 ) )
F_27 ( V_26 , 0x4 , 1 << 21 , 1 << 21 ) ;
else
F_11 ( L_9 ) ;
}
static void T_3 F_28 ( void )
{
struct V_25 * V_27 ;
#define F_29 0x000001b0
#define F_30 0x00000210
#define F_31 0x00100000
#define F_32 0x00080000
V_27 = F_26 ( L_1 ) ;
if ( ! F_18 ( V_27 ) ) {
F_33 ( V_27 , F_29 ,
F_31
| F_32 ) ;
F_33 ( V_27 , F_30 ,
F_31 |
F_32 ) ;
} else {
F_34 ( L_10 ) ;
}
}
static void T_3 F_35 ( void )
{
if ( F_36 ( L_11 ) )
F_23 () ;
F_37 ( NULL , V_28 , NULL , NULL ) ;
F_38 () ;
F_28 () ;
F_25 () ;
}
static void T_3 F_39 ( struct V_29 * V_30 )
{
struct V_1 * V_2 ;
void T_1 * V_3 ;
T_2 V_31 ;
V_2 = F_2 ( NULL , NULL , L_12 ) ;
if ( ! V_2 ) {
F_34 ( L_13 ) ;
return;
}
V_3 = F_3 ( V_2 , 0 ) ;
if ( ! V_3 ) {
F_34 ( L_14 ) ;
goto V_32;
}
V_31 = F_5 ( V_3 + V_33 ) ;
V_31 >>= V_34 ;
if ( ( V_31 & 0x3 ) != V_35 )
if ( F_40 ( V_30 , 1200000000 ) )
F_34 ( L_15 ) ;
V_32:
F_4 ( V_2 ) ;
}
static void T_3 F_41 ( struct V_29 * V_30 )
{
struct V_1 * V_2 ;
V_2 = F_42 ( L_16 ) ;
if ( ! V_2 ) {
F_34 ( L_17 ) ;
return;
}
V_30 -> V_36 = V_2 ;
if ( F_43 ( V_30 ) ) {
F_34 ( L_18 ) ;
goto V_32;
}
F_39 ( V_30 ) ;
V_32:
F_4 ( V_2 ) ;
}
static void T_3 F_44 ( void )
{
if ( F_1 () > V_8 )
F_45 () ;
if ( F_46 ( V_37 ) ) {
F_41 ( & V_38 . V_39 ) ;
F_47 ( & V_38 ) ;
}
}
static void T_3 F_48 ( void )
{
F_49 () ;
F_50 () ;
}
static void T_3 F_51 ( void )
{
F_52 ( 0 , ~ 0UL ) ;
F_53 () ;
F_54 () ;
F_55 () ;
}
static void T_3 F_56 ( void )
{
F_57 () ;
F_58 () ;
F_59 ( L_19 , F_1 () ) ;
}
