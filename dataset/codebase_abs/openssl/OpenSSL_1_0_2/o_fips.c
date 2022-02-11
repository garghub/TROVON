int F_1 ( void )
{
F_2 () ;
#ifdef F_3
return F_4 () ;
#else
return 0 ;
#endif
}
int F_5 ( int V_1 )
{
F_2 () ;
#ifdef F_3
# ifndef F_6
# define F_6 "Default FIPS Crypto User Password"
# endif
if ( ! F_7 ( V_1 , F_6 ) )
return 0 ;
if ( V_1 )
F_8 ( F_9 () ) ;
else
F_8 ( NULL ) ;
return 1 ;
#else
if ( V_1 == 0 )
return 1 ;
F_10 ( V_2 , V_3 ) ;
return 0 ;
#endif
}
