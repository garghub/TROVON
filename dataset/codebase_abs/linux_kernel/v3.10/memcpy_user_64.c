unsigned long F_1 ( void * V_1 , const void T_1 * V_2 ,
unsigned long V_3 )
{
unsigned long V_4 = F_2 ( V_1 , V_2 , V_3 ) ;
if ( F_3 ( V_4 ) )
memset ( V_1 + V_3 - V_4 , 0 , V_4 ) ;
return V_4 ;
}
