T_1 int F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 ;
if ( V_2 == 0 )
return 0 ;
if ( V_3 )
return - V_6 ;
if ( V_1 + V_2 < V_1 )
return - V_7 ;
V_5 = F_2 ( V_8 -> V_9 , V_1 ) ;
if ( V_5 == NULL || V_1 < V_5 -> V_10 || V_1 + V_2 > V_5 -> V_11 )
return - V_7 ;
F_3 ( V_5 , V_1 , V_1 + V_2 ) ;
return 0 ;
}
T_1 int F_4 ( void )
{
return V_12 ;
}
