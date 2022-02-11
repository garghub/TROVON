void T_1 * F_1 ( struct V_1 * V_2 , int V_3 , unsigned long V_4 )
{
T_2 V_5 = F_2 ( V_2 , V_3 ) ;
T_2 V_6 = F_3 ( V_2 , V_3 ) ;
unsigned long V_7 = F_4 ( V_2 , V_3 ) ;
if ( ! V_6 || ! V_5 )
return NULL ;
if ( ( V_7 & V_8 ) || ( V_7 & V_9 ) ) {
if ( V_7 & V_10 && ! ( V_7 & V_8 ) )
return F_5 ( V_5 , V_6 ) ;
else
return F_6 ( V_5 , V_6 ) ;
}
return NULL ;
}
