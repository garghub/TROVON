static int F_1 ( unsigned long V_1 )
{
F_2 () ;
F_3 () ;
return 0 ;
}
static int F_4 ( struct V_2 * V_3 ,
struct V_4 * V_5 , int V_6 )
{
F_5 ( V_7 ) ;
switch ( V_6 ) {
case 1 :
F_3 () ;
break;
case 2 :
F_6 ( true ) ;
F_7 ( true ) ;
F_8 ( 0 , V_8 ) ;
F_9 () ;
F_10 () ;
F_11 ( 0 , F_1 ) ;
F_12 () ;
F_13 () ;
F_7 ( false ) ;
F_6 ( false ) ;
break;
default:
break;
}
F_5 ( V_9 ) ;
return V_6 ;
}
int T_1 F_14 ( void )
{
F_15 ( true ) ;
F_6 ( false ) ;
F_16 ( 2 , 1 ) ;
F_17 ( 1 , 1 ) ;
return F_18 ( & V_10 , NULL ) ;
}
