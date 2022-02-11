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
V_1 = F_5 ( V_2 ) ;
V_1 |= F_5 ( V_3 ) << 1 ;
V_1 |= F_5 ( V_4 ) << 2 ;
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
void F_7 ( void )
{
if ( V_5 == 0x11 )
F_8 ( V_7 , 0 ) ;
else
F_8 ( V_8 , 0 ) ;
}
static void F_9 ( void )
{
if ( ! F_10 ( V_9 ) )
F_11 ( V_9 ) ;
if ( ! F_10 ( V_10 ) && ! F_10 ( V_11 ) ) {
F_11 ( V_11 ) ;
F_11 ( V_10 ) ;
}
F_8 ( V_12 , 1 ) ;
}
static int T_1 F_12 ( void )
{
if ( F_13 () ) {
V_10 = F_14 ( NULL , L_5 ) ;
V_11 = F_14 ( NULL , L_6 ) ;
if ( ! F_10 ( V_10 ) && ! F_10 ( V_11 ) ) {
F_15 ( V_10 ) ;
F_15 ( V_11 ) ;
}
F_3 ( V_12 , L_7 ) ;
V_13 = F_9 ;
V_9 = F_14 ( NULL , L_8 ) ;
if ( ! F_10 ( V_9 ) ) {
F_16 ( V_9 , 3000000 , 3000000 ) ;
F_15 ( V_9 ) ;
}
F_17 () ;
}
return 0 ;
}
static void T_1 F_18 ( void )
{
F_19 ( V_14 ,
F_20 ( V_14 ) ) ;
F_21 () ;
F_1 () ;
if ( V_5 < 0x12 ) {
F_22 ( 1 , NULL ) ;
V_15 [ 2 ] . V_16 = L_9 ;
}
F_23 ( & V_17 ) ;
F_24 ( & V_18 ) ;
if ( V_5 == 0x11 ) {
F_3 ( V_7 , L_10 ) ;
F_8 ( V_7 , 1 ) ;
} else {
F_3 ( V_8 , L_10 ) ;
F_8 ( V_8 , 1 ) ;
}
F_3 ( V_19 , L_11 ) ;
F_8 ( V_19 , 0 ) ;
F_2 ( 10 ) ;
F_3 ( V_20 , L_12 ) ;
F_8 ( V_20 , 0 ) ;
F_2 ( 10 ) ;
F_25 ( V_20 , 1 ) ;
}
static void T_1 F_26 ( void )
{
F_27 ( 32768 , 24000000 , 22579200 , 24576000 ) ;
}
