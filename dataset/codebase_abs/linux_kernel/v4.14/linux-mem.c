void * F_1 ( T_1 V_1 , T_2 V_2 )
{
void * V_3 ;
V_3 = F_2 ( V_1 , V_2 | V_4 ) ;
if ( ! V_3 )
V_3 = F_3 ( V_1 , V_2 | V_5 , V_6 ) ;
return V_3 ;
}
void * F_4 ( struct V_7 * V_8 , int V_9 , T_1 V_1 ,
T_2 V_2 )
{
return F_5 ( V_1 , V_2 , F_6 ( V_8 , V_9 ) ) ;
}
