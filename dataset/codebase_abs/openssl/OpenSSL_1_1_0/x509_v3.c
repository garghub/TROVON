int F_1 ( T_1 * V_1 , int V_2 )
{
if ( V_1 == NULL )
return ( 0 ) ;
V_1 -> V_3 = ( V_2 ) ? 0xFF : - 1 ;
return ( 1 ) ;
}
int F_2 ( T_1 * V_1 , T_2 * V_4 )
{
int V_5 ;
if ( V_1 == NULL )
return ( 0 ) ;
V_5 = F_3 ( & V_1 -> V_6 , V_4 -> V_4 , V_4 -> V_7 ) ;
if ( ! V_5 )
return ( 0 ) ;
return ( 1 ) ;
}
T_3 * F_4 ( T_1 * V_1 )
{
if ( V_1 == NULL )
return ( NULL ) ;
return ( V_1 -> V_8 ) ;
}
T_2 * F_5 ( T_1 * V_1 )
{
if ( V_1 == NULL )
return ( NULL ) ;
return & V_1 -> V_6 ;
}
int F_6 ( const T_1 * V_1 )
{
if ( V_1 == NULL )
return ( 0 ) ;
if ( V_1 -> V_3 > 0 )
return 1 ;
return 0 ;
}
