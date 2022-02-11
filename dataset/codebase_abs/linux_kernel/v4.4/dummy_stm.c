static T_1
F_1 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned int V_3 , unsigned int V_4 , unsigned int V_5 ,
unsigned int V_6 , const unsigned char * V_7 )
{
#ifdef F_2
T_2 V_8 = 0 ;
if ( V_7 )
V_8 = * ( T_2 * ) V_7 ;
if ( V_6 < 8 )
V_8 &= ( 1ull << ( V_6 * 8 ) ) - 1 ;
F_3 ( L_1 , V_2 , V_3 ,
V_4 , V_6 , V_8 ) ;
#endif
return V_6 ;
}
static int F_4 ( void )
{
return F_5 ( NULL , & V_9 , V_10 ) ;
}
static void F_6 ( void )
{
F_7 ( & V_9 ) ;
}
