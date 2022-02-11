void T_1 * F_1 ( struct V_1 * V_2 ,
int V_3 ,
unsigned long V_4 ,
unsigned long V_5 )
{
T_2 V_6 = F_2 ( V_2 , V_3 ) ;
T_2 V_7 = F_3 ( V_2 , V_3 ) ;
unsigned long V_8 = F_4 ( V_2 , V_3 ) ;
if ( V_7 <= V_4 || ! V_6 )
return NULL ;
V_7 -= V_4 ;
V_6 += V_4 ;
if ( V_5 && V_7 > V_5 )
V_7 = V_5 ;
if ( V_8 & V_9 )
return F_5 ( V_2 , V_6 , V_7 ) ;
if ( V_8 & V_10 ) {
if ( V_8 & V_11 )
return F_6 ( V_6 , V_7 ) ;
return F_7 ( V_6 , V_7 ) ;
}
return NULL ;
}
void T_1 * F_8 ( struct V_1 * V_2 , int V_3 , unsigned long V_5 )
{
return F_1 ( V_2 , V_3 , 0 , V_5 ) ;
}
