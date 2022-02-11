static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
F_4 ( 0 ) ;
F_5 ( V_2 , F_3 ( V_2 ) ) ;
F_6 ( V_3 , V_4 ) ;
}
static T_2
F_7 ( int V_5 , void * V_6 )
{
return V_7 ;
}
static void F_8 ( void )
{
int V_8 = 0 ;
V_8 = F_9 ( V_9 , & F_7 ,
V_10 | V_11 ,
L_1 , & F_7 ) ;
if ( V_8 != 0 ) {
F_10 ( V_12 L_2 , V_8 ) ;
} else {
F_11 ( V_9 ) ;
F_12 ( F_13 ( 2 ) , V_13 ) ;
F_14 ( F_13 ( 2 ) , V_14 ) ;
}
}
static void T_1 F_15 ( void )
{
F_8 () ;
#ifdef F_16
F_17 ( & V_15 ) ;
#endif
F_18 ( NULL ) ;
F_19 ( V_16 , F_3 ( V_16 ) ) ;
}
