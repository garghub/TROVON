int F_1 ( const T_1 * V_1 )
{
if ( ! V_1 )
return 0 ;
return V_1 -> V_2 ;
}
T_2 * F_2 ( const T_1 * V_1 ,
int V_3 )
{
if ( ! V_1 || ( V_3 < 0 ) || ( V_3 >= V_1 -> V_2 ) )
return NULL ;
return V_1 -> V_4 + V_3 ;
}
T_3 * F_3 ( T_2 * V_5 , int V_3 )
{
if ( ! V_5 )
return NULL ;
if ( V_5 -> V_6 ) {
if ( V_3 == 0 )
return V_5 -> V_6 ;
V_3 -- ;
}
return F_4 ( V_5 -> V_7 , V_3 ) ;
}
const T_4 * F_5 ( const T_3 * V_8 )
{
if ( ! V_8 )
return NULL ;
return V_8 -> V_9 -> V_10 ;
}
T_3 * F_6 ( const T_3
* V_8 )
{
if ( ! V_8 )
return NULL ;
return V_8 -> V_11 ;
}
