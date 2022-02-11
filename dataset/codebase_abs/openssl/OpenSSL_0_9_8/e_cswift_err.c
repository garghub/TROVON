static void F_1 ( void )
{
if ( V_1 == 0 )
V_1 = F_2 () ;
if ( V_2 )
{
V_2 = 0 ;
#ifndef F_3
F_4 ( V_1 , V_3 ) ;
F_4 ( V_1 , V_4 ) ;
#endif
#ifdef F_5
V_5 -> error = F_6 ( V_1 , 0 , 0 ) ;
F_4 ( 0 , V_5 ) ;
#endif
}
}
static void F_7 ( void )
{
if ( V_2 == 0 )
{
#ifndef F_3
F_8 ( V_1 , V_3 ) ;
F_8 ( V_1 , V_4 ) ;
#endif
#ifdef F_5
F_8 ( 0 , V_5 ) ;
#endif
V_2 = 1 ;
}
}
static void F_9 ( int V_6 , int V_7 , char * V_8 , int line )
{
if ( V_1 == 0 )
V_1 = F_2 () ;
F_10 ( V_1 , V_6 , V_7 , V_8 , line ) ;
}
