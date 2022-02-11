T_1 long F_1 ( unsigned long V_1 , unsigned long V_2 ,
int T_2 * V_3 , int T_2 * V_4 ,
struct V_5 * V_6 )
{
long V_7 ;
if ( ! V_2 )
V_2 = V_6 -> V_8 ;
V_7 = F_2 ( V_1 , V_2 , V_6 , 0 , V_3 , V_4 ) ;
return V_7 ;
}
T_1 int F_3 ( struct V_5 * V_6 )
{
#ifdef F_4
return F_2 ( V_9 , V_6 -> V_8 , V_6 , 0 , NULL , NULL ) ;
#else
return - V_10 ;
#endif
}
