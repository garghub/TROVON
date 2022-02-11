void F_1 ( struct V_1 * V_2 , const void * V_3 ,
unsigned long * V_4 , unsigned long * V_5 , unsigned long * V_6 )
{
const T_1 * V_7 ;
T_1 V_8 ;
const unsigned char * V_9 ;
V_7 = V_3 ;
* V_4 = * ( V_7 ++ ) ;
V_9 = F_2 ( V_2 , L_1 , NULL ) ;
if ( ! V_9 )
V_9 = F_2 ( V_2 , L_2 , NULL ) ;
V_8 = V_9 ? * ( T_1 * ) V_9 : F_3 ( V_2 ) ;
* V_5 = F_4 ( V_7 , V_8 ) ;
V_7 += V_8 ;
V_9 = F_2 ( V_2 , L_3 , NULL ) ;
V_8 = V_9 ? * ( T_1 * ) V_9 : F_5 ( V_2 ) ;
* V_6 = F_4 ( V_7 , V_8 ) ;
}
