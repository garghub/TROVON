int F_1 ( T_1 * V_1 , long V_2 )
{
if ( V_1 == NULL ) return ( 0 ) ;
return ( F_2 ( V_1 -> V_3 -> V_2 , V_2 ) ) ;
}
int F_3 ( T_1 * V_1 , T_2 * V_4 )
{
if ( ( V_1 == NULL ) || ( V_1 -> V_3 == NULL ) ) return ( 0 ) ;
return ( F_4 ( & V_1 -> V_3 -> V_5 , V_4 ) ) ;
}
int F_5 ( T_1 * V_1 , T_3 * V_6 )
{
if ( ( V_1 == NULL ) || ( V_1 -> V_3 == NULL ) ) return ( 0 ) ;
return ( F_6 ( & V_1 -> V_3 -> V_7 , V_6 ) ) ;
}
