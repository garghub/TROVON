static int F_1 ( void )
{
return F_2 ( V_1 ) ;
}
static int F_3 ( T_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
F_4 ( V_4 ) ;
break;
case V_5 :
F_4 ( V_6 ) ;
break;
default:
return - V_7 ;
}
if ( V_2 == V_3 ) {
F_5 () ;
F_6 () ;
F_7 ( 0 , V_8 ) ;
F_7 ( 0 , V_9 ) ;
}
F_8 () ;
return 0 ;
}
static void F_9 ( void )
{
F_10 ( V_1 ) ;
}
static int F_11 ( T_1 V_2 )
{
return ( V_2 > V_10 && V_2 <= V_11 ) ;
}
static int T_2 F_12 ( void )
{
if ( V_1 == NULL )
V_1 = F_13 ( NULL , L_1 ) ;
if ( ! F_14 ( V_1 ) ) {
if ( F_15 () )
F_16 ( & V_12 ) ;
} else
return - V_13 ;
return 0 ;
}
