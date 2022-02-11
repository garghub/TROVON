static int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 ) ) {
F_3 ( V_2 , V_4 ,
0x8000 | V_5 ) ;
F_3 ( V_2 , V_6 , 0x0000 ) ;
F_3 ( V_2 , V_4 ,
0x8000 | V_7 ) ;
F_3 ( V_2 , V_6 , 0xf0f0 ) ;
F_3 ( V_2 , V_4 ,
V_7 ) ;
}
return 0 ;
}
static void F_4 ( struct V_1 * V_8 , int V_9 , int V_10 , int V_11 )
{
F_3 ( V_8 , 0x0d , V_9 ) ;
F_3 ( V_8 , 0x0e , V_10 ) ;
F_3 ( V_8 , 0x0d , ( 1 << 14 ) | V_9 ) ;
F_3 ( V_8 , 0x0e , V_11 ) ;
}
static int F_5 ( struct V_1 * V_8 )
{
F_4 ( V_8 , 2 , 4 , 0 ) ;
F_4 ( V_8 , 2 , 5 , 0 ) ;
F_4 ( V_8 , 2 , 8 , 0x003ff ) ;
return 0 ;
}
static void F_6 ( struct V_12 * V_8 )
{
T_1 V_13 ;
if ( ! F_7 ( L_1 ) )
return;
if ( V_8 -> V_14 != 0 )
return;
F_8 ( V_8 , 0x62c , & V_13 ) ;
V_13 |= 0xaaa8 ;
F_9 ( V_8 , 0x62c , V_13 ) ;
F_8 ( V_8 , 0x644 , & V_13 ) ;
V_13 |= 0xfe ;
F_9 ( V_8 , 0x644 , V_13 ) ;
F_10 ( 100 ) ;
}
static int F_11 ( struct V_1 * V_8 )
{
T_2 V_11 ;
F_3 ( V_8 , 0xd , 0x7 ) ;
F_3 ( V_8 , 0xe , 0x8016 ) ;
F_3 ( V_8 , 0xd , 0x4007 ) ;
V_11 = F_12 ( V_8 , 0xe ) ;
V_11 &= 0xffe3 ;
V_11 |= 0x18 ;
F_3 ( V_8 , 0xe , V_11 ) ;
F_3 ( V_8 , 0x1d , 0x5 ) ;
V_11 = F_12 ( V_8 , 0x1e ) ;
V_11 |= 0x0100 ;
F_3 ( V_8 , 0x1e , V_11 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_8 )
{
T_2 V_11 ;
F_3 ( V_8 , 0xd , 0x3 ) ;
F_3 ( V_8 , 0xe , 0x805d ) ;
F_3 ( V_8 , 0xd , 0x4003 ) ;
V_11 = F_12 ( V_8 , 0xe ) ;
F_3 ( V_8 , 0xe , V_11 & ~ ( 1 << 8 ) ) ;
F_11 ( V_8 ) ;
V_11 = F_12 ( V_8 , 0x0 ) ;
if ( V_11 & V_15 )
F_3 ( V_8 , 0x0 , V_11 & ~ V_15 ) ;
return 0 ;
}
static void T_3 F_14 ( void )
{
if ( F_2 ( V_3 ) ) {
F_15 ( V_16 , V_17 ,
F_1 ) ;
F_15 ( V_18 , V_17 ,
F_5 ) ;
F_15 ( V_19 , 0xffffffff ,
F_11 ) ;
F_15 ( V_20 , 0xffffffef ,
F_13 ) ;
}
}
static void T_3 F_16 ( void )
{
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_23 * V_25 ;
struct V_26 * V_27 ;
T_1 V_28 ;
V_22 = F_17 ( NULL , NULL , L_2 ) ;
if ( ! V_22 ) {
F_18 ( L_3 , V_29 ) ;
return;
}
V_24 = F_19 ( V_22 , 2 ) ;
if ( F_20 ( V_24 ) ) {
F_18 ( L_4 , V_29 ) ;
goto V_30;
}
V_25 = F_21 ( NULL , L_5 ) ;
if ( F_20 ( V_25 ) ) {
F_18 ( L_6 , V_29 ) ;
goto V_31;
}
V_28 = V_24 == V_25 ? V_32 :
V_33 ;
V_27 = F_22 ( L_7 ) ;
if ( ! F_20 ( V_27 ) )
F_23 ( V_27 , V_34 ,
V_35 ,
V_28 ) ;
else
F_24 ( L_8 ) ;
F_25 ( V_25 ) ;
V_31:
F_25 ( V_24 ) ;
V_30:
F_26 ( V_22 ) ;
}
static void T_3 F_27 ( void )
{
struct V_26 * V_27 ;
unsigned int V_36 ;
V_27 = F_22 ( L_7 ) ;
if ( ! F_20 ( V_27 ) ) {
V_36 = V_37 |
V_38 |
V_39 |
V_40 |
V_41 |
V_42 ;
F_23 ( V_27 , V_43 , V_36 , V_36 ) ;
F_23 ( V_27 , V_44 ,
V_45 |
V_46 ,
( 0xf << 16 ) | ( 0x7 << 20 ) ) ;
F_23 ( V_27 , V_47 ,
V_48 |
V_49 ,
( 0xf << 16 ) | ( 0x7 << 20 ) ) ;
} else {
F_18 ( L_9 ) ;
}
}
static void T_3 F_28 ( void )
{
struct V_9 * V_50 ;
F_29 ( F_30 () ? L_10 : L_11 ,
F_31 () ) ;
V_50 = F_32 () ;
if ( V_50 == NULL )
F_18 ( L_12 ) ;
F_14 () ;
F_33 ( NULL , V_51 , NULL , V_50 ) ;
F_34 () ;
F_35 () ? F_36 () : F_37 () ;
F_16 () ;
F_27 () ;
}
static void T_3 F_38 ( struct V_9 * V_52 )
{
struct V_21 * V_22 ;
void T_4 * V_53 ;
T_1 V_11 ;
V_22 = F_17 ( NULL , NULL , L_13 ) ;
if ( ! V_22 ) {
F_18 ( L_14 ) ;
return;
}
V_53 = F_39 ( V_22 , 0 ) ;
if ( ! V_53 ) {
F_18 ( L_15 ) ;
goto V_30;
}
V_11 = F_40 ( V_53 + V_54 ) ;
V_11 >>= V_55 ;
V_11 &= 0x3 ;
if ( ( V_11 != V_56 ) && F_35 () )
if ( F_41 ( V_52 , 1200000000 ) )
F_18 ( L_16 ) ;
if ( V_11 < V_57 )
if ( F_41 ( V_52 , 996000000 ) )
F_18 ( L_17 ) ;
if ( F_35 () ) {
if ( V_11 != V_58 )
if ( F_41 ( V_52 , 852000000 ) )
F_18 ( L_18 ) ;
}
V_30:
F_26 ( V_22 ) ;
}
static void T_3 F_42 ( void )
{
struct V_21 * V_22 ;
struct V_9 * V_52 = F_43 ( 0 ) ;
if ( ! V_52 ) {
F_18 ( L_19 ) ;
return;
}
V_22 = F_44 ( V_52 -> V_59 ) ;
if ( ! V_22 ) {
F_18 ( L_20 ) ;
return;
}
if ( F_45 ( V_52 ) ) {
F_18 ( L_21 ) ;
goto V_30;
}
F_38 ( V_52 ) ;
V_30:
F_26 ( V_22 ) ;
}
static void T_3 F_46 ( void )
{
if ( F_31 () > V_60 )
F_47 () ;
if ( F_48 ( V_61 ) ) {
F_42 () ;
F_49 ( & V_62 ) ;
}
}
static void T_3 F_50 ( void )
{
F_51 () ;
F_52 () ;
}
static void T_3 F_53 ( void )
{
F_54 () ;
F_55 () ;
F_56 () ;
F_57 () ;
F_58 () ;
}
