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
void F_5 ( unsigned char * V_4 , int V_5 )
{
if ( V_2 != NULL )
V_2 -> V_7 ( V_4 , V_5 ) ;
}
