static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
F_4 ( 0 ) ;
F_5 ( V_2 , F_3 ( V_2 ) ) ;
}
static T_2
F_6 ( int V_3 , void * V_4 )
{
return V_5 ;
}
static void F_7 ( void )
{
int V_6 = 0 ;
V_6 = F_8 ( V_7 , & F_6 ,
V_8 | V_9 ,
L_1 , & F_6 ) ;
if ( V_6 != 0 ) {
F_9 ( V_10 L_2 , V_6 ) ;
} else {
F_10 ( V_7 ) ;
F_11 ( F_12 ( 2 ) , V_11 ) ;
F_13 ( F_12 ( 2 ) , V_12 ) ;
}
}
static void T_1 F_14 ( void )
{
F_7 () ;
#ifdef F_15
F_16 ( & V_13 ) ;
#endif
F_17 ( NULL ) ;
F_18 ( V_14 , F_3 ( V_14 ) ) ;
}
