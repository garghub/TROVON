static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 ;
T_1 V_5 = V_6 ;
F_2 ( V_5 ) ;
F_3 ( V_7 , L_1 ) ;
F_4 ( V_7 , 0 ) ;
F_5 ( 1 ) ;
F_6 ( V_7 , 1 ) ;
F_5 ( 1 ) ;
F_7 ( V_7 ) ;
F_2 ( V_3 ) ;
F_8 ( 10 ) ;
return F_9 ( V_2 -> V_8 , V_9 ) ;
}
static void T_2 F_10 ( void )
{
V_10 . V_11 = F_11 ( V_12 |
V_13 | V_14 ) ;
if ( V_10 . V_11 )
F_12 ( & V_15 , & V_10 ) ;
}
static void F_13 ( void )
{
F_6 ( V_16 , 0 ) ;
if ( ! F_14 ( V_17 ) && ! F_14 ( V_18 ) ) {
F_15 ( V_18 ) ;
F_15 ( V_17 ) ;
}
F_4 ( V_19 , 1 ) ;
}
static int T_2 F_16 ( void )
{
if ( F_17 () ) {
V_17 = F_18 ( NULL , L_2 ) ;
V_18 = F_18 ( NULL , L_3 ) ;
if ( ! F_14 ( V_17 ) && ! F_14 ( V_18 ) ) {
F_19 ( V_17 ) ;
F_19 ( V_18 ) ;
}
F_3 ( V_19 , L_4 ) ;
V_20 = F_13 ;
F_20 () ;
}
return 0 ;
}
static void T_2 F_21 ( void )
{
int V_8 ;
F_3 ( V_21 , L_5 ) ;
F_22 ( V_21 ) ;
F_3 ( V_22 , L_6 ) ;
F_22 ( V_22 ) ;
V_8 = F_23 ( V_21 ) ? 1 : 0 ;
V_8 |= ( F_23 ( V_22 ) ? 1 : 0 ) << 1 ;
switch ( V_8 ) {
default:
break;
case 1 :
V_23 = 0x13 ;
break;
case 2 :
V_23 = 0x20 ;
break;
}
}
static void T_2 F_24 ( void )
{
F_25 () ;
F_26 ( V_24 ,
F_27 ( V_24 ) ) ;
F_28 () ;
F_21 () ;
F_10 () ;
F_29 ( 1 , NULL ) ;
F_30 ( - 1 , & V_25 ) ;
F_31 ( & V_26 ) ;
}
static void T_2 F_32 ( void )
{
F_33 ( 32768 , 24000000 , 22579200 , 24576000 ) ;
}
