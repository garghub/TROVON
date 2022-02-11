int F_1 ( void * V_1 , T_1 V_2 , const T_2 * V_3 ,
T_3 * V_4 ,
void * (* F_2) ( const void * V_5 , T_1 V_6 , void * V_1 ,
T_1 * V_2 ) )
{
T_4 * V_7 = F_3 ( V_4 ) ;
if ( V_7 == NULL )
return 0 ;
return V_7 -> V_8 -> V_9 ( V_1 , V_2 , V_3 , V_4 , F_2 ) ;
}
