void F_1 ( T_1 * V_1 )
{
F_2 ( V_1 -> V_2 ) ;
if ( ! ( V_1 -> V_3 & V_4 ) )
F_3 ( V_1 -> V_5 ,
V_6 ) ;
F_4 ( V_1 -> V_7 , F_2 ) ;
F_5 ( V_1 ) ;
}
T_1 * F_6 ( T_2 * V_8 , T_3 * V_9 , int V_10 )
{
T_1 * V_11 ;
if ( ! V_8 && ! V_9 )
return NULL ;
V_11 = F_7 ( sizeof( T_1 ) ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_7 = F_8 () ;
if ( ! V_11 -> V_7 )
{
F_5 ( V_11 ) ;
return NULL ;
}
if ( V_10 )
V_11 -> V_3 = V_12 ;
else
V_11 -> V_3 = 0 ;
if ( V_9 )
V_11 -> V_2 = V_9 ;
else
{
V_11 -> V_2 = V_8 -> V_13 ;
V_8 -> V_13 = NULL ;
}
if ( V_8 )
{
V_11 -> V_5 = V_8 -> V_14 ;
V_8 -> V_14 = NULL ;
}
else
V_11 -> V_5 = NULL ;
return V_11 ;
}
