void F_1 ( void * V_1 , const void * V_2 , T_1 V_3 )
{
memcpy ( V_1 , V_2 , V_3 ) ;
F_2 ( V_1 , V_3 ) ;
}
void F_3 ( char * V_4 , struct V_5 * V_5 , T_1 V_6 ,
T_1 V_7 )
{
F_1 ( V_4 , F_4 ( V_5 ) + V_6 , V_7 ) ;
}
unsigned long F_5 ( void * V_4 , const void T_2 * V_8 ,
unsigned long V_9 )
{
unsigned long V_10 = F_6 ( V_4 , V_8 , V_9 ) ;
F_2 ( V_4 , V_9 - V_10 ) ;
return V_10 ;
}
