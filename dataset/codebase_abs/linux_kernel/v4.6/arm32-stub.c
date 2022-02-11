T_1 F_1 ( T_2 * V_1 )
{
int V_2 ;
if ( ! F_2 ( V_3 ) )
return V_4 ;
V_2 = F_3 ( V_5 , 0 ) ;
if ( V_2 < 5 ) {
F_4 ( V_1 , L_1 ) ;
return V_6 ;
}
return V_4 ;
}
T_1 F_5 ( T_2 * V_7 ,
unsigned long * V_8 ,
unsigned long * V_9 ,
unsigned long * V_10 ,
unsigned long * V_11 ,
unsigned long V_12 ,
T_3 * V_13 )
{
unsigned long V_14 ;
T_1 V_15 ;
T_4 V_16 ;
V_12 = F_6 ( V_12 , V_17 ) ;
V_16 = V_12 ;
* V_11 = V_18 ;
V_14 = F_6 ( * V_11 , V_19 ) / V_19 ;
V_15 = V_7 -> V_20 -> V_21 ( V_22 ,
V_23 ,
V_14 , & V_16 ) ;
if ( V_15 != V_4 ) {
* V_11 = 0 ;
F_4 ( V_7 , L_2 ) ;
return V_15 ;
}
* V_10 = V_16 ;
* V_9 = V_13 -> V_9 ;
V_15 = F_7 ( V_7 , V_8 , * V_9 ,
* V_9 ,
V_12 + V_18 , 0 ) ;
if ( V_15 != V_4 ) {
F_4 ( V_7 , L_3 ) ;
F_8 ( V_7 , * V_11 , * V_10 ) ;
* V_11 = 0 ;
return V_15 ;
}
if ( * V_8 + * V_9 > V_12 + V_24 ) {
F_4 ( V_7 , L_4 ) ;
F_8 ( V_7 , * V_11 , * V_10 ) ;
* V_11 = 0 ;
F_8 ( V_7 , * V_9 , * V_8 ) ;
* V_9 = 0 ;
return V_25 ;
}
return V_4 ;
}
