int F_1 ( unsigned int V_1 , unsigned int V_2 ,
unsigned long V_3 ,
unsigned long V_4 )
{
F_2 ( ! F_3 ( V_4 ) ) ;
V_3 = ( V_3 + V_1 ) & ( V_4 - 1 ) ;
return V_3 + V_2 > V_4 ;
}
unsigned long F_4 ( unsigned long * V_5 , unsigned long V_6 ,
unsigned long V_7 , unsigned int V_2 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned long V_8 )
{
unsigned long V_1 ;
V_6 -= 1 ;
V_9:
V_1 = F_5 ( V_5 , V_6 , V_7 , V_2 , V_8 ) ;
if ( V_1 < V_6 ) {
if ( F_1 ( V_1 , V_2 , V_3 , V_4 ) ) {
V_7 = F_6 ( V_3 + V_1 , V_4 ) - V_3 ;
goto V_9;
}
F_7 ( V_5 , V_1 , V_2 ) ;
return V_1 ;
}
return - 1 ;
}
