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
V_22 = F_17 ( L_2 ) ;
if ( ! F_18 ( V_22 ) )
F_19 ( V_22 , V_23 ,
V_24 ,
V_25 ) ;
else
F_20 ( L_3 ) ;
}
static void T_3 F_21 ( void )
{
struct V_9 * V_26 ;
F_22 ( F_23 () ? L_4 : L_5 ,
F_24 () ) ;
F_25 () ;
V_26 = F_26 () ;
if ( V_26 == NULL )
F_27 ( L_6 ) ;
F_14 () ;
F_28 ( NULL , V_27 , NULL , V_26 ) ;
F_29 () ;
F_30 () ;
F_16 () ;
}
static void T_3 F_31 ( struct V_9 * V_28 )
{
struct V_29 * V_30 ;
void T_4 * V_31 ;
T_1 V_11 ;
V_30 = F_32 ( NULL , NULL , L_7 ) ;
if ( ! V_30 ) {
F_27 ( L_8 ) ;
return;
}
V_31 = F_33 ( V_30 , 0 ) ;
if ( ! V_31 ) {
F_27 ( L_9 ) ;
goto V_32;
}
V_11 = F_34 ( V_31 + V_33 ) ;
V_11 >>= V_34 ;
if ( ( V_11 & 0x3 ) != V_35 )
if ( F_35 ( V_28 , 1200000000 ) )
F_27 ( L_10 ) ;
V_32:
F_36 ( V_30 ) ;
}
static void T_3 F_37 ( void )
{
struct V_29 * V_30 ;
struct V_9 * V_28 = F_38 ( 0 ) ;
if ( ! V_28 ) {
F_27 ( L_11 ) ;
return;
}
V_30 = F_39 ( V_28 -> V_36 ) ;
if ( ! V_30 ) {
F_27 ( L_12 ) ;
return;
}
if ( F_40 ( V_28 ) ) {
F_27 ( L_13 ) ;
goto V_32;
}
F_31 ( V_28 ) ;
V_32:
F_36 ( V_30 ) ;
}
static void T_3 F_41 ( void )
{
if ( F_24 () > V_37 )
F_42 () ;
if ( F_43 ( V_38 ) ) {
F_37 () ;
F_44 ( & V_39 ) ;
}
}
static void T_3 F_45 ( void )
{
F_46 () ;
F_47 () ;
}
static void T_3 F_48 ( void )
{
F_49 () ;
F_50 () ;
F_51 () ;
F_52 () ;
F_53 () ;
}
