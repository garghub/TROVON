int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
if ( ! V_3 ) {
F_2 ( L_1 , V_4 ) ;
return - V_5 ;
}
if ( V_1 >= F_3 ( V_6 ) )
return - V_7 ;
F_4 ( V_2 , V_3 + V_6 [ V_1 ] ) ;
return 0 ;
}
static int F_5 ( void )
{
#ifdef F_6
if ( F_7 () )
V_3 = F_8 ( V_8 ) ;
else
#endif
#ifdef F_9
if ( F_10 () )
V_3 = F_11 ( V_9 ) ;
else
#endif
( void ) 0 ;
return 0 ;
}
