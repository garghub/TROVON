char * F_1 ( T_1 V_1 , T_2 * V_2 )
{
if ( V_2 -> V_3 == NULL )
return V_2 -> V_4 ;
return F_2 ( V_1 , V_2 -> V_4 , V_2 -> V_3 ) ;
}
char * F_3 ( T_3 V_1 , T_2 * V_2 )
{
if ( V_2 -> V_3 == NULL )
return V_2 -> V_4 ;
return F_2 ( V_1 , V_2 -> V_4 , V_2 -> V_3 ) ;
}
char * F_4 ( double V_1 , T_2 * V_2 )
{
if ( V_2 -> V_3 == NULL )
return V_2 -> V_4 ;
return F_2 ( V_1 , V_2 -> V_4 , V_2 -> V_3 ) ;
}
