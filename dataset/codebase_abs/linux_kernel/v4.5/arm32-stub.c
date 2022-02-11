T_1 F_1 ( T_2 * V_1 ,
unsigned long * V_2 ,
unsigned long * V_3 ,
unsigned long * V_4 ,
unsigned long * V_5 ,
unsigned long V_6 ,
T_3 * V_7 )
{
unsigned long V_8 ;
T_1 V_9 ;
T_4 V_10 ;
V_6 = F_2 ( V_6 , V_11 ) ;
V_10 = V_6 ;
* V_5 = V_12 ;
V_8 = F_2 ( * V_5 , V_13 ) / V_13 ;
V_9 = V_1 -> V_14 -> V_15 ( V_16 ,
V_17 ,
V_8 , & V_10 ) ;
if ( V_9 != V_18 ) {
* V_5 = 0 ;
F_3 ( V_1 , L_1 ) ;
return V_9 ;
}
* V_4 = V_10 ;
* V_3 = V_7 -> V_3 ;
V_9 = F_4 ( V_1 , V_2 , * V_3 ,
* V_3 ,
V_6 + V_12 , 0 ) ;
if ( V_9 != V_18 ) {
F_3 ( V_1 , L_2 ) ;
F_5 ( V_1 , * V_5 , * V_4 ) ;
* V_5 = 0 ;
return V_9 ;
}
if ( * V_2 + * V_3 > V_6 + V_19 ) {
F_3 ( V_1 , L_3 ) ;
F_5 ( V_1 , * V_5 , * V_4 ) ;
* V_5 = 0 ;
F_5 ( V_1 , * V_3 , * V_2 ) ;
* V_3 = 0 ;
return V_20 ;
}
return V_18 ;
}
