void F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned long * V_4 , unsigned long * V_5 ,
unsigned long * V_6 )
{
T_2 V_7 ;
const T_1 * V_8 ;
* V_4 = F_2 ( V_3 , 1 ) ;
V_3 ++ ;
V_8 = F_3 ( V_2 , L_1 , NULL ) ;
if ( ! V_8 )
V_8 = F_3 ( V_2 , L_2 , NULL ) ;
V_7 = V_8 ? F_2 ( V_8 , 1 ) : F_4 ( V_2 ) ;
* V_5 = F_2 ( V_3 , V_7 ) ;
V_3 += V_7 ;
V_8 = F_3 ( V_2 , L_3 , NULL ) ;
V_7 = V_8 ? F_2 ( V_8 , 1 ) : F_5 ( V_2 ) ;
* V_6 = F_2 ( V_3 , V_7 ) ;
}
