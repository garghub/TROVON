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
F_15 ( V_15 , V_17 ,
0x8000 | V_18 ) ;
F_15 ( V_15 , V_19 , 0x0000 ) ;
F_15 ( V_15 , V_17 ,
0x8000 | V_20 ) ;
F_15 ( V_15 , V_19 , 0xf0f0 ) ;
F_15 ( V_15 , V_17 ,
V_20 ) ;
}
return 0 ;
}
static void F_16 ( struct V_14 * V_21 , int V_22 , int V_23 , int V_24 )
{
F_15 ( V_21 , 0x0d , V_22 ) ;
F_15 ( V_21 , 0x0e , V_23 ) ;
F_15 ( V_21 , 0x0d , ( 1 << 14 ) | V_22 ) ;
F_15 ( V_21 , 0x0e , V_24 ) ;
}
static int F_17 ( struct V_14 * V_21 )
{
F_16 ( V_21 , 2 , 4 , 0 ) ;
F_16 ( V_21 , 2 , 5 , 0 ) ;
F_16 ( V_21 , 2 , 8 , 0x003ff ) ;
return 0 ;
}
static int F_18 ( struct V_14 * V_21 )
{
T_4 V_24 ;
F_15 ( V_21 , 0xd , 0x7 ) ;
F_15 ( V_21 , 0xe , 0x8016 ) ;
F_15 ( V_21 , 0xd , 0x4007 ) ;
V_24 = F_19 ( V_21 , 0xe ) ;
V_24 &= 0xffe3 ;
V_24 |= 0x18 ;
F_15 ( V_21 , 0xe , V_24 ) ;
F_15 ( V_21 , 0x1d , 0x5 ) ;
V_24 = F_19 ( V_21 , 0x1e ) ;
V_24 |= 0x0100 ;
F_15 ( V_21 , 0x1e , V_24 ) ;
return 0 ;
}
static void T_1 F_20 ( void )
{
if ( F_14 ( V_16 ) ) {
F_21 ( V_25 , V_26 ,
F_13 ) ;
F_21 ( V_27 , V_26 ,
F_17 ) ;
F_21 ( V_28 , 0xffffffff ,
F_18 ) ;
}
}
static void T_1 F_22 ( void )
{
struct V_29 * V_30 ;
V_30 = F_23 ( L_3 ) ;
if ( ! F_24 ( V_30 ) )
F_25 ( V_30 , V_31 ,
V_32 ,
V_33 ) ;
else
F_11 ( L_4 ) ;
}
static void T_1 F_26 ( void )
{
F_20 () ;
F_27 ( NULL , V_34 , NULL , NULL ) ;
F_28 () ;
F_29 () ;
F_22 () ;
}
static void T_1 F_30 ( struct V_22 * V_35 )
{
struct V_10 * V_11 ;
void T_3 * V_36 ;
T_2 V_24 ;
V_11 = F_6 ( NULL , NULL , L_5 ) ;
if ( ! V_11 ) {
F_31 ( L_6 ) ;
return;
}
V_36 = F_7 ( V_11 , 0 ) ;
if ( ! V_36 ) {
F_31 ( L_7 ) ;
goto V_37;
}
V_24 = F_32 ( V_36 + V_38 ) ;
V_24 >>= V_39 ;
if ( ( V_24 & 0x3 ) != V_40 )
if ( F_33 ( V_35 , 1200000000 ) )
F_31 ( L_8 ) ;
V_37:
F_34 ( V_11 ) ;
}
static void T_1 F_35 ( void )
{
struct V_10 * V_11 ;
struct V_22 * V_35 = F_36 ( 0 ) ;
if ( ! V_35 ) {
F_31 ( L_9 ) ;
return;
}
V_11 = F_37 ( V_35 -> V_41 ) ;
if ( ! V_11 ) {
F_31 ( L_10 ) ;
return;
}
if ( F_38 ( V_35 ) ) {
F_31 ( L_11 ) ;
goto V_37;
}
F_30 ( V_35 ) ;
V_37:
F_34 ( V_11 ) ;
}
static void T_1 F_39 ( void )
{
if ( F_1 () > V_4 )
F_40 () ;
if ( F_41 ( V_42 ) ) {
F_35 () ;
F_42 ( & V_43 ) ;
}
}
static void T_1 F_43 ( void )
{
F_44 () ;
F_45 () ;
}
static void T_1 F_46 ( void )
{
F_2 () ;
F_47 () ;
F_48 () ;
F_49 () ;
F_50 () ;
}
static void T_1 F_51 ( void )
{
F_52 ( NULL ) ;
F_53 () ;
F_54 ( F_55 () ? L_12 : L_13 ,
F_1 () ) ;
}
