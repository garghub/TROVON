T_1 T_2 F_1 ( T_3 * V_1 ,
unsigned long * V_2 ,
unsigned long * V_3 ,
unsigned long * V_4 ,
unsigned long * V_5 ,
unsigned long V_6 ,
T_4 * V_7 )
{
T_1 V_8 ;
unsigned long V_9 , V_10 = 0 ;
unsigned long V_11 ;
void * V_12 = ( void * ) * V_2 ;
unsigned long V_13 ;
V_13 = F_2 ( V_6 , V_14 ) + V_15 ;
if ( V_13 < V_6 )
V_13 += V_14 ;
V_9 = V_16 - V_17 ;
if ( * V_2 != V_13 ) {
V_10 = V_9 + ( V_18 - V_16 ) ;
* V_2 = * V_4 = V_13 ;
V_11 = F_3 ( V_10 , V_19 ) /
V_20 ;
V_8 = F_4 ( V_21 , V_22 ,
V_23 , V_11 ,
( V_24 * ) V_4 ) ;
if ( V_8 != V_25 ) {
V_10 += V_15 ;
V_8 = F_5 ( V_1 , V_10 ,
V_14 , V_4 ) ;
if ( V_8 != V_25 ) {
F_6 ( V_1 , L_1 ) ;
return V_8 ;
}
* V_2 = * V_4 + V_15 ;
}
memcpy ( ( void * ) * V_2 , V_12 , V_9 ) ;
* V_5 = V_10 ;
}
return V_25 ;
}
