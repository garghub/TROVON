static void F_1 ( struct V_1 * V_2 , int V_3 )
{
switch ( V_3 ) {
case V_4 :
F_2 ( F_3 ( 5 ) , 0 ) ;
break;
case V_5 :
F_2 ( F_3 ( 5 ) , 1 ) ;
break;
}
}
static int T_1 F_4 ( char * V_6 )
{
V_7 = V_6 [ 0 ] ;
return 1 ;
}
static void T_1 F_5 ( void )
{
F_6 ( V_8 , F_7 ( V_8 ) ) ;
F_8 ( 12 * 1000 * 1000 ) ;
F_9 ( V_9 , F_7 ( V_9 ) ) ;
}
static void T_1 F_10 ( void )
{
F_11 ( & V_10 ) ;
switch ( V_7 ) {
case 'p' :
V_11 . V_12 = 1 ;
break;
case 'b' :
V_11 . V_12 = 0 ;
break;
case 's' :
default:
V_11 . V_12 = 2 ;
break;
}
F_12 ( & V_11 ) ;
F_13 ( F_3 ( 0 ) , V_13 ) ;
F_14 ( F_3 ( 0 ) , 1 ) ;
F_15 ( & V_14 ) ;
F_16 ( NULL ) ;
F_17 ( F_18 ( F_3 ( 5 ) , L_1 ) ) ;
F_19 ( F_3 ( 5 ) , 1 ) ;
F_20 ( V_15 , F_7 ( V_15 ) ) ;
F_21 () ;
}
