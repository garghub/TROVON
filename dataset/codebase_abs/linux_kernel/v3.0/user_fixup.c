static unsigned long F_1 ( unsigned long V_1 , unsigned long V_2 , unsigned long * V_3 )
{
unsigned long V_4 = F_2 () -> V_5 ;
unsigned long V_6 = V_1 + V_2 ;
if ( V_4 < V_1 || V_4 >= V_6 ) {
* V_3 = 0 ;
} else {
* V_3 = V_4 - V_1 ;
V_2 = V_6 - V_4 ;
}
return V_2 ;
}
unsigned long F_3 ( void * V_7 , const void T_1 * V_8 , unsigned long V_2 )
{
unsigned long V_3 ;
V_2 = F_1 ( ( unsigned long ) V_8 , V_2 , & V_3 ) ;
if ( F_4 ( V_2 ) )
memset ( V_7 + V_3 , 0 , V_2 ) ;
return V_2 ;
}
unsigned long F_5 ( void T_1 * V_7 , const void * V_8 , unsigned long V_2 )
{
unsigned long V_3 ;
return F_1 ( ( unsigned long ) V_7 , V_2 , & V_3 ) ;
}
unsigned long F_6 ( void T_1 * V_7 , void T_1 * V_8 , unsigned long V_2 )
{
unsigned long V_4 = F_2 () -> V_5 ;
unsigned long V_1 = ( unsigned long ) V_7 ;
unsigned long V_6 = V_1 + V_2 ;
if ( V_4 >= V_1 && V_4 < V_6 )
return V_6 - V_4 ;
V_1 = ( unsigned long ) V_8 ;
V_6 = V_1 + V_2 ;
if ( V_4 >= V_1 && V_4 < V_6 )
return V_6 - V_4 ;
return V_2 ;
}
