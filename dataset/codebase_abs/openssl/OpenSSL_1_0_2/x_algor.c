void F_1 ( T_1 * V_1 , const T_2 * V_2 )
{
int V_3 ;
if ( V_2 -> V_4 & V_5 )
V_3 = V_6 ;
else
V_3 = V_7 ;
F_2 ( V_1 , F_3 ( F_4 ( V_2 ) ) , V_3 , NULL ) ;
}
int F_5 ( const T_1 * V_8 , const T_1 * V_9 )
{
int V_10 ;
V_10 = F_6 ( V_8 -> V_11 , V_9 -> V_11 ) ;
if ( V_10 )
return V_10 ;
if ( ! V_8 -> V_12 && ! V_9 -> V_12 )
return 0 ;
return F_7 ( V_8 -> V_12 , V_9 -> V_12 ) ;
}
