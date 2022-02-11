static void T_1 F_1 ( void )
{
int V_1 ;
F_2 ( 150 ) ;
F_3 ( V_2 , L_1 ) ;
F_4 ( V_2 ) ;
F_3 ( V_3 , L_2 ) ;
F_4 ( V_3 ) ;
F_3 ( V_4 , L_3 ) ;
F_4 ( V_4 ) ;
V_1 = F_5 ( V_2 ) ? 1 : 0 ;
V_1 |= ( F_5 ( V_3 ) ? 1 : 0 ) << 1 ;
V_1 |= ( F_5 ( V_4 ) ? 1 : 0 ) << 2 ;
switch ( V_1 ) {
case 7 :
V_5 = 0x11 ;
break;
case 6 :
V_5 = 0x12 ;
break;
case 5 :
V_5 = 0x13 ;
break;
case 4 :
V_5 = 0x14 ;
break;
default:
V_5 = 0x10 ;
break;
}
if ( ( V_5 == 0x10 )
|| ( V_5 == 0x12 )
|| ( V_5 == 0x14 ) ) {
F_6 ( V_6
L_4 ,
V_5 & 0xf ) ;
}
}
static void F_7 ( char V_7 , const char * V_8 )
{
if ( V_5 == 0x11 )
F_8 ( V_9 , 0 ) ;
else
F_8 ( V_10 , 0 ) ;
}
static void F_9 ( void )
{
if ( ! F_10 ( V_11 ) )
F_11 ( V_11 ) ;
if ( ! F_10 ( V_12 ) && ! F_10 ( V_13 ) ) {
F_11 ( V_13 ) ;
F_11 ( V_12 ) ;
}
F_8 ( V_14 , 1 ) ;
}
static int T_1 F_12 ( void )
{
V_12 = F_13 ( NULL , L_5 ) ;
V_13 = F_13 ( NULL , L_6 ) ;
if ( ! F_10 ( V_12 ) && ! F_10 ( V_13 ) ) {
F_14 ( V_12 ) ;
F_14 ( V_13 ) ;
}
F_3 ( V_14 , L_7 ) ;
V_15 = F_9 ;
V_11 = F_13 ( NULL , L_8 ) ;
if ( ! F_10 ( V_11 ) ) {
F_15 ( V_11 , 3000000 , 3000000 ) ;
F_14 ( V_11 ) ;
}
F_16 () ;
return 0 ;
}
static void T_1 F_17 ( void )
{
F_18 () ;
F_12 () ;
}
static void T_1 F_19 ( void )
{
F_20 () ;
F_21 ( V_16 ,
F_22 ( V_16 ) ) ;
F_23 () ;
F_1 () ;
if ( V_5 < 0x12 ) {
F_24 ( 0 , NULL ) ;
F_24 ( 1 , & V_17 ) ;
V_18 [ 2 ] . V_19 = L_9 ;
} else
F_24 ( 0 , & V_17 ) ;
F_25 ( - 1 , & V_20 ) ;
F_26 ( & V_21 ) ;
if ( V_5 == 0x11 ) {
F_3 ( V_9 , L_10 ) ;
F_8 ( V_9 , 1 ) ;
} else {
F_3 ( V_10 , L_10 ) ;
F_8 ( V_10 , 1 ) ;
}
F_3 ( V_22 , L_11 ) ;
F_8 ( V_22 , 0 ) ;
F_2 ( 10 ) ;
F_3 ( V_23 , L_12 ) ;
F_8 ( V_23 , 0 ) ;
F_2 ( 10 ) ;
F_27 ( V_23 , 1 ) ;
}
static void T_1 F_28 ( void )
{
F_29 ( 32768 , 24000000 , 22579200 , 24576000 ) ;
}
