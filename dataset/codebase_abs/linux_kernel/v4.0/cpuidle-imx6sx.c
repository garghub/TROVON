static int F_1 ( unsigned long V_1 )
{
F_2 () ;
return 0 ;
}
static int F_3 ( struct V_2 * V_3 ,
struct V_4 * V_5 , int V_6 )
{
F_4 ( V_7 ) ;
switch ( V_6 ) {
case 1 :
F_2 () ;
break;
case 2 :
F_5 ( true ) ;
F_6 ( true ) ;
F_7 ( 0 , V_8 ) ;
F_8 () ;
F_9 () ;
F_10 ( 0 , F_1 ) ;
F_11 () ;
F_12 () ;
F_6 ( false ) ;
F_5 ( false ) ;
break;
default:
break;
}
F_4 ( V_9 ) ;
return V_6 ;
}
int T_1 F_13 ( void )
{
F_5 ( false ) ;
F_14 ( 2 , 1 ) ;
F_15 ( 1 , 1 ) ;
return F_16 ( & V_10 , NULL ) ;
}
