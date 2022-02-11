int F_1 ( T_1 * V_1 , long V_2 )
{
if ( V_1 == NULL ) return ( 0 ) ;
if ( V_1 -> V_3 -> V_2 == NULL )
{
if ( ( V_1 -> V_3 -> V_2 = F_2 () ) == NULL )
return ( 0 ) ;
}
return ( F_3 ( V_1 -> V_3 -> V_2 , V_2 ) ) ;
}
int F_4 ( T_1 * V_1 , T_2 * V_4 )
{
T_2 * V_5 ;
if ( V_1 == NULL ) return ( 0 ) ;
V_5 = V_1 -> V_3 -> V_6 ;
if ( V_5 != V_4 )
{
V_5 = F_5 ( V_4 ) ;
if ( V_5 != NULL )
{
F_6 ( V_1 -> V_3 -> V_6 ) ;
V_1 -> V_3 -> V_6 = V_5 ;
}
}
return ( V_5 != NULL ) ;
}
int F_7 ( T_1 * V_1 , T_3 * V_7 )
{
if ( ( V_1 == NULL ) || ( V_1 -> V_3 == NULL ) ) return ( 0 ) ;
return ( F_8 ( & V_1 -> V_3 -> V_8 , V_7 ) ) ;
}
int F_9 ( T_1 * V_1 , T_3 * V_7 )
{
if ( ( V_1 == NULL ) || ( V_1 -> V_3 == NULL ) ) return ( 0 ) ;
return ( F_8 ( & V_1 -> V_3 -> V_9 , V_7 ) ) ;
}
int F_10 ( T_1 * V_1 , const T_4 * V_10 )
{
T_4 * V_5 ;
if ( ( V_1 == NULL ) || ( V_1 -> V_3 -> V_11 == NULL ) ) return ( 0 ) ;
V_5 = V_1 -> V_3 -> V_11 -> V_12 ;
if ( V_5 != V_10 )
{
V_5 = F_11 ( V_10 ) ;
if ( V_5 != NULL )
{
F_12 ( V_1 -> V_3 -> V_11 -> V_12 ) ;
V_1 -> V_3 -> V_11 -> V_12 = V_5 ;
}
}
return ( V_5 != NULL ) ;
}
int F_13 ( T_1 * V_1 , const T_4 * V_10 )
{
T_4 * V_5 ;
if ( ( V_1 == NULL ) || ( V_1 -> V_3 -> V_11 == NULL ) ) return ( 0 ) ;
V_5 = V_1 -> V_3 -> V_11 -> V_13 ;
if ( V_5 != V_10 )
{
V_5 = F_11 ( V_10 ) ;
if ( V_5 != NULL )
{
F_12 ( V_1 -> V_3 -> V_11 -> V_13 ) ;
V_1 -> V_3 -> V_11 -> V_13 = V_5 ;
}
}
return ( V_5 != NULL ) ;
}
int F_14 ( T_1 * V_1 , T_5 * V_14 )
{
if ( ( V_1 == NULL ) || ( V_1 -> V_3 == NULL ) ) return ( 0 ) ;
return ( F_15 ( & ( V_1 -> V_3 -> V_15 ) , V_14 ) ) ;
}
