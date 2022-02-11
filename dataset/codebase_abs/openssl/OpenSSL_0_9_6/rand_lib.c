void F_1 ( T_1 * V_1 )
{
V_2 = V_1 ;
}
T_1 * F_2 ( void )
{
return ( V_2 ) ;
}
void F_3 ( void )
{
if ( V_2 != NULL )
V_2 -> V_3 () ;
}
void F_4 ( const void * V_4 , int V_5 )
{
if ( V_2 != NULL )
V_2 -> V_6 ( V_4 , V_5 ) ;
}
void F_5 ( const void * V_4 , int V_5 , double V_7 )
{
if ( V_2 != NULL )
V_2 -> V_8 ( V_4 , V_5 , V_7 ) ;
}
int F_6 ( unsigned char * V_4 , int V_5 )
{
if ( V_2 != NULL )
return V_2 -> V_9 ( V_4 , V_5 ) ;
return ( - 1 ) ;
}
int F_7 ( unsigned char * V_4 , int V_5 )
{
if ( V_2 != NULL )
return V_2 -> V_10 ( V_4 , V_5 ) ;
return ( - 1 ) ;
}
int F_8 ( void )
{
if ( V_2 != NULL )
return V_2 -> V_11 () ;
return 0 ;
}
