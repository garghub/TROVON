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
static void F_5 ( enum V_7 V_8 , const char * V_9 )
{
struct V_10 * V_11 ;
void T_3 * V_12 ;
V_11 = F_6 ( NULL , NULL , L_1 ) ;
V_12 = F_7 ( V_11 , 0 ) ;
if ( ! V_12 )
goto V_13;
F_8 () ;
F_9 ( 1 << 2 , V_12 ) ;
F_9 ( 1 << 2 , V_12 ) ;
F_10 ( 500 ) ;
F_11 ( L_2 ) ;
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
static void T_1 F_16 ( void )
{
struct V_17 * V_18 , * V_19 , * V_20 ;
unsigned long V_21 ;
V_18 = F_17 ( NULL , L_3 ) ;
V_19 = F_17 ( NULL , L_4 ) ;
V_20 = F_17 ( NULL , L_5 ) ;
if ( F_18 ( V_18 ) || F_18 ( V_19 ) || F_18 ( V_20 ) ) {
F_11 ( L_6 ) ;
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
static void T_1 F_23 ( void )
{
if ( F_14 ( V_16 ) )
F_24 ( V_23 , V_24 ,
F_13 ) ;
F_16 () ;
}
static void T_1 F_25 ( void )
{
struct V_17 * V_18 , * V_25 , * V_26 , * V_20 ;
unsigned long V_21 ;
V_18 = F_17 ( NULL , L_3 ) ;
V_25 = F_17 ( NULL , L_7 ) ;
V_26 = F_17 ( NULL , L_8 ) ;
V_20 = F_17 ( NULL , L_5 ) ;
if ( F_18 ( V_18 ) || F_18 ( V_25 )
|| F_18 ( V_26 ) || F_18 ( V_20 ) ) {
F_11 ( L_6 ) ;
goto V_22;
}
F_21 ( V_25 , 768000000 ) ;
F_19 ( V_18 , V_26 ) ;
V_21 = F_20 ( V_20 , 24000000 ) ;
F_21 ( V_20 , V_21 ) ;
V_22:
if ( ! F_18 ( V_18 ) )
F_22 ( V_18 ) ;
if ( ! F_18 ( V_26 ) )
F_22 ( V_26 ) ;
if ( ! F_18 ( V_25 ) )
F_22 ( V_25 ) ;
if ( ! F_18 ( V_20 ) )
F_22 ( V_20 ) ;
}
static void T_1 F_26 ( void )
{
F_25 () ;
}
static void T_1 F_27 ( void )
{
struct V_27 * V_28 ;
V_28 = F_28 ( L_9 ) ;
if ( ! F_18 ( V_28 ) )
F_29 ( V_28 , 0x4 , 1 << 21 , 1 << 21 ) ;
else
F_11 ( L_10 ) ;
}
static void T_1 F_30 ( void )
{
F_31 () ;
}
static void T_1 F_32 ( void )
{
if ( F_33 ( L_11 ) )
F_23 () ;
else if ( F_33 ( L_12 ) ||
F_33 ( L_13 ) )
F_26 () ;
F_34 ( NULL , V_29 , NULL , NULL ) ;
F_35 () ;
F_36 () ;
F_30 () ;
F_27 () ;
}
static void T_1 F_37 ( struct V_30 * V_31 )
{
struct V_10 * V_11 ;
void T_3 * V_32 ;
T_2 V_33 ;
V_11 = F_6 ( NULL , NULL , L_14 ) ;
if ( ! V_11 ) {
F_38 ( L_15 ) ;
return;
}
V_32 = F_7 ( V_11 , 0 ) ;
if ( ! V_32 ) {
F_38 ( L_16 ) ;
goto V_34;
}
V_33 = F_39 ( V_32 + V_35 ) ;
V_33 >>= V_36 ;
if ( ( V_33 & 0x3 ) != V_37 )
if ( F_40 ( V_31 , 1200000000 ) )
F_38 ( L_17 ) ;
V_34:
F_41 ( V_11 ) ;
}
static void T_1 F_42 ( struct V_30 * V_31 )
{
struct V_10 * V_11 ;
V_11 = F_43 ( L_18 ) ;
if ( ! V_11 ) {
F_38 ( L_19 ) ;
return;
}
V_31 -> V_38 = V_11 ;
if ( F_44 ( V_31 ) ) {
F_38 ( L_20 ) ;
goto V_34;
}
F_37 ( V_31 ) ;
V_34:
F_41 ( V_11 ) ;
}
static void T_1 F_45 ( void )
{
if ( F_1 () > V_4 )
F_46 () ;
if ( F_47 ( V_39 ) ) {
F_42 ( & V_40 . V_41 ) ;
F_48 ( & V_40 ) ;
}
}
static void T_1 F_49 ( void )
{
F_50 () ;
F_51 () ;
}
static void T_1 F_52 ( void )
{
void T_3 * V_42 ;
struct V_10 * V_11 ;
unsigned int V_33 ;
V_11 = F_6 ( NULL , NULL , L_21 ) ;
if ( ! V_11 )
goto V_43;
V_42 = F_7 ( V_11 , 0 ) ;
if ( ! V_42 ) {
F_41 ( V_11 ) ;
goto V_43;
}
V_33 = F_39 ( V_42 + V_44 ) ;
V_33 |= 0x70800000 ;
F_53 ( V_33 , V_42 + V_44 ) ;
V_33 = V_45 | V_46 ;
F_53 ( V_33 , V_42 + V_47 ) ;
F_54 ( V_42 ) ;
F_41 ( V_11 ) ;
V_43:
F_55 ( 0 , ~ 0UL ) ;
}
static inline void F_52 ( void ) {}
static void T_1 F_56 ( void )
{
F_2 () ;
F_52 () ;
F_57 () ;
F_58 () ;
F_59 () ;
}
static void T_1 F_60 ( void )
{
F_61 ( NULL ) ;
F_62 () ;
F_63 ( F_64 () ? L_22 : L_23 ,
F_1 () ) ;
}
