void T_1 * F_1 ( struct V_1 * V_2 , T_2 V_3 ,
T_3 V_4 , unsigned long V_5 )
{
void T_1 * * V_6 , * V_7 ;
V_6 = F_2 ( V_8 , sizeof( * V_6 ) , V_9 ) ;
if ( ! V_6 )
return NULL ;
V_7 = F_3 ( V_3 , V_4 , V_5 ) ;
if ( V_7 ) {
* V_6 = V_7 ;
F_4 ( V_2 , V_6 ) ;
} else
F_5 ( V_6 ) ;
return V_7 ;
}
