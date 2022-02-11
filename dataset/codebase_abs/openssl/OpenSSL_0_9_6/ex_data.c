int F_1 ( T_1 * V_1 , int V_2 , void * V_3 )
{
int V_4 ;
if ( V_1 -> V_5 == NULL )
{
if ( ( V_1 -> V_5 = F_2 () ) == NULL )
{
F_3 ( V_6 , V_7 ) ;
return ( 0 ) ;
}
}
V_4 = F_4 ( V_1 -> V_5 ) ;
while ( V_4 <= V_2 )
{
if ( ! F_5 ( V_1 -> V_5 , NULL ) )
{
F_3 ( V_6 , V_7 ) ;
return ( 0 ) ;
}
V_4 ++ ;
}
F_6 ( V_1 -> V_5 , V_2 , V_3 ) ;
return ( 1 ) ;
}
void * F_7 ( T_1 * V_1 , int V_2 )
{
if ( V_1 -> V_5 == NULL )
return ( 0 ) ;
else if ( V_2 >= F_4 ( V_1 -> V_5 ) )
return ( 0 ) ;
else
return ( F_8 ( V_1 -> V_5 , V_2 ) ) ;
}
