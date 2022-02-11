int T_1 F_1 ( void )
{
if ( ! F_2 () )
return 0 ;
if ( F_3 () || V_1 || V_2 == V_3 )
V_4 = 1 ;
V_1 = 0 ;
#ifdef F_4
if ( V_5 > V_6 )
V_7 = 1 ;
#endif
return V_4 ;
}
void T_1 F_5 ( void )
{
if ( V_4 ) {
F_6 ( 1 , true ) ;
V_8 = & V_9 ;
#ifdef F_7
F_8 () ;
#endif
}
}
int F_9 ( void )
{
int V_10 ;
if ( V_4 )
return 0 ;
V_10 = F_6 ( 1 , false ) ;
if ( V_10 )
return V_10 ;
V_8 = & V_9 ;
#ifdef F_7
F_8 () ;
#endif
return 0 ;
}
