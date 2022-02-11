void *
F_1 ( T_1 * V_1 , const void * V_2 , const T_2 V_3 )
{
void * V_4 ;
V_4 = F_2 ( V_1 , V_3 ) ;
memcpy ( V_4 , V_2 , V_3 ) ;
return V_4 ;
}
