T_1 int F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
return F_3 ( V_3 , V_2 -> V_4 , V_2 , 0 , NULL , NULL ) ;
#else
return ( - V_5 ) ;
#endif
}
T_1 int F_4 ( unsigned long V_6 , unsigned long V_7 ,
int T_2 * V_8 , int V_9 ,
int T_2 * V_10 , struct V_1 * V_2 )
{
if ( ! V_7 )
V_7 = V_2 -> V_4 ;
return F_3 ( V_6 , V_7 , V_2 , 0 , V_8 , V_10 ) ;
}
T_1 int F_5 ( struct V_1 * V_2 )
{
return F_3 ( V_11 | V_12 | V_3 , V_2 -> V_4 , V_2 , 0 , NULL , NULL ) ;
}
T_1 long F_6 ( int V_13 , int V_14 ,
T_3 V_15 , T_3 V_16 )
{
return F_7 ( V_13 , V_15 , V_16 , V_14 ) ;
}
