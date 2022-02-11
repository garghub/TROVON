int F_1 ( T_1 * V_1 )
{
if ( ( V_1 -> V_2 . V_3 != NULL ) || ( V_1 -> type == V_4 ) )
return ( V_1 -> type ) ;
else
return ( 0 ) ;
}
void F_2 ( T_1 * V_1 , int type , void * V_2 )
{
if ( V_1 -> V_2 . V_3 != NULL )
F_3 ( ( V_5 * * ) & V_1 , NULL ) ;
V_1 -> type = type ;
V_1 -> V_2 . V_3 = V_2 ;
}
