unsigned long F_1 ( void * V_1 , const void T_1 * V_2 , unsigned long V_3 )
{
if ( F_2 ( F_3 ( V_4 , V_2 , V_3 ) ) )
V_3 = F_4 ( V_1 , V_2 , V_3 ) ;
else
memset ( V_1 , 0 , V_3 ) ;
return V_3 ;
}
unsigned long F_5 ( void T_1 * V_1 , const void * V_2 , unsigned long V_3 )
{
if ( F_2 ( F_3 ( V_5 , V_1 , V_3 ) ) )
V_3 = F_6 ( V_1 , V_2 , V_3 ) ;
return V_3 ;
}
unsigned long F_7 ( void T_1 * V_1 , const void T_1 * V_2 ,
unsigned long V_3 )
{
F_8 () ;
if ( F_2 ( F_3 ( V_4 , V_2 , V_3 ) &&
F_3 ( V_5 , V_1 , V_3 ) ) )
V_3 = F_9 ( V_1 , V_2 , V_3 ) ;
return V_3 ;
}
