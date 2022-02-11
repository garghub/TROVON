static int F_1 ( T_1 V_1 )
{
F_2 ( V_2 ) ;
switch ( V_1 ) {
case V_3 :
F_3 ( V_4 ) ;
break;
case V_5 :
F_3 ( V_6 ) ;
break;
default:
return - V_7 ;
}
if ( V_1 == V_3 ) {
F_4 () ;
F_5 () ;
F_6 ( 0 , V_8 ) ;
F_6 ( 0 , V_9 ) ;
}
F_7 () ;
F_8 ( V_2 ) ;
return 0 ;
}
static int F_9 ( T_1 V_1 )
{
return ( V_1 > V_10 && V_1 <= V_11 ) ;
}
static int T_2 F_10 ( void )
{
if ( V_2 == NULL )
V_2 = F_11 ( NULL , L_1 ) ;
if ( ! F_12 ( V_2 ) ) {
if ( F_13 () )
F_14 ( & V_12 ) ;
} else
return - V_13 ;
return 0 ;
}
