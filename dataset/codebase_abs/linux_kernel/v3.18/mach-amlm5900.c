static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
F_4 ( V_2 , F_3 ( V_2 ) ) ;
F_5 ( V_3 , V_4 ) ;
}
static void T_1 F_6 ( void )
{
F_7 ( 12000000 ) ;
F_8 () ;
}
static T_2
F_9 ( int V_5 , void * V_6 )
{
return V_7 ;
}
static void F_10 ( void )
{
int V_8 = 0 ;
V_8 = F_11 ( V_9 , & F_9 ,
V_10 | V_11 ,
L_1 , & F_9 ) ;
if ( V_8 != 0 ) {
F_12 ( V_12 L_2 , V_8 ) ;
} else {
F_13 ( V_9 ) ;
F_14 ( F_15 ( 2 ) , V_13 ) ;
F_16 ( F_15 ( 2 ) , V_14 ) ;
}
}
static void T_1 F_17 ( void )
{
F_10 () ;
#ifdef F_18
F_19 ( & V_15 ) ;
#endif
F_20 ( NULL ) ;
F_21 ( V_16 , F_3 ( V_16 ) ) ;
}
