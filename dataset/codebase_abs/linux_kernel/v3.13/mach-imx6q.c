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
static int F_6 ( struct V_1 * V_8 )
{
T_1 V_11 ;
F_3 ( V_8 , 0xd , 0x7 ) ;
F_3 ( V_8 , 0xe , 0x8016 ) ;
F_3 ( V_8 , 0xd , 0x4007 ) ;
V_11 = F_7 ( V_8 , 0xe ) ;
V_11 &= 0xffe3 ;
V_11 |= 0x18 ;
F_3 ( V_8 , 0xe , V_11 ) ;
F_3 ( V_8 , 0x1d , 0x5 ) ;
V_11 = F_7 ( V_8 , 0x1e ) ;
V_11 |= 0x0100 ;
F_3 ( V_8 , 0x1e , V_11 ) ;
return 0 ;
}
static void T_2 F_8 ( void )
{
if ( F_2 ( V_3 ) ) {
F_9 ( V_12 , V_13 ,
F_1 ) ;
F_9 ( V_14 , V_13 ,
F_5 ) ;
F_9 ( V_15 , 0xffffffff ,
F_6 ) ;
}
}
static void T_2 F_10 ( void )
{
struct V_16 * V_17 ;
V_17 = F_11 ( L_1 ) ;
if ( ! F_12 ( V_17 ) )
F_13 ( V_17 , V_18 ,
V_19 ,
V_20 ) ;
else
F_14 ( L_2 ) ;
}
static void T_2 F_15 ( void )
{
struct V_9 * V_21 ;
F_16 ( F_17 () ? L_3 : L_4 ,
F_18 () ) ;
F_19 () ;
V_21 = F_20 () ;
if ( V_21 == NULL )
F_21 ( L_5 ) ;
F_8 () ;
F_22 ( NULL , V_22 , NULL , V_21 ) ;
F_23 () ;
F_24 () ;
F_10 () ;
}
static void T_2 F_25 ( struct V_9 * V_23 )
{
struct V_24 * V_25 ;
void T_3 * V_26 ;
T_4 V_11 ;
V_25 = F_26 ( NULL , NULL , L_6 ) ;
if ( ! V_25 ) {
F_21 ( L_7 ) ;
return;
}
V_26 = F_27 ( V_25 , 0 ) ;
if ( ! V_26 ) {
F_21 ( L_8 ) ;
goto V_27;
}
V_11 = F_28 ( V_26 + V_28 ) ;
V_11 >>= V_29 ;
if ( ( V_11 & 0x3 ) != V_30 )
if ( F_29 ( V_23 , 1200000000 ) )
F_21 ( L_9 ) ;
V_27:
F_30 ( V_25 ) ;
}
static void T_2 F_31 ( void )
{
struct V_24 * V_25 ;
struct V_9 * V_23 = F_32 ( 0 ) ;
if ( ! V_23 ) {
F_21 ( L_10 ) ;
return;
}
V_25 = F_33 ( V_23 -> V_31 ) ;
if ( ! V_25 ) {
F_21 ( L_11 ) ;
return;
}
if ( F_34 ( V_23 ) ) {
F_21 ( L_12 ) ;
goto V_27;
}
F_25 ( V_23 ) ;
V_27:
F_30 ( V_25 ) ;
}
static void T_2 F_35 ( void )
{
if ( F_18 () > V_32 )
F_36 () ;
if ( F_37 ( V_33 ) ) {
F_31 () ;
F_38 ( & V_34 ) ;
}
}
static void T_2 F_39 ( void )
{
F_40 () ;
F_41 () ;
}
static void T_2 F_42 ( void )
{
F_43 () ;
F_44 () ;
F_45 () ;
F_46 () ;
F_47 () ;
}
