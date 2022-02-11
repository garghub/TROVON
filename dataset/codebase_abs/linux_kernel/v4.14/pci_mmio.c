static long F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long * V_3 )
{
struct V_4 * V_5 ;
long V_6 ;
F_2 ( & V_7 -> V_8 -> V_9 ) ;
V_6 = - V_10 ;
V_5 = F_3 ( V_7 -> V_8 , V_1 ) ;
if ( ! V_5 )
goto V_11;
V_6 = - V_12 ;
if ( ! ( V_5 -> V_13 & V_2 ) )
goto V_11;
V_6 = F_4 ( V_5 , V_1 , V_3 ) ;
V_11:
F_5 ( & V_7 -> V_8 -> V_9 ) ;
return V_6 ;
}
