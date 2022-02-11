static T_1 F_1 ( T_2 * V_1 ,
unsigned long * V_2 ,
unsigned long * V_3 ,
unsigned long * V_4 ,
unsigned long * V_5 ,
unsigned long V_6 ,
T_3 * V_7 )
{
T_1 V_8 ;
unsigned long V_9 , V_10 = 0 ;
V_9 = V_11 - V_12 ;
if ( * V_2 != ( V_6 + V_13 ) ) {
V_10 = V_9 + ( V_14 - V_11 ) ;
V_8 = F_2 ( V_1 , V_2 ,
V_9 , V_10 ,
V_6 + V_13 ,
V_15 ) ;
if ( V_8 != V_16 ) {
F_3 ( V_1 , L_1 ) ;
return V_8 ;
}
if ( * V_2 != ( V_6 + V_13 ) ) {
F_3 ( V_1 , L_2 ) ;
F_4 ( V_1 , V_10 , * V_2 ) ;
return V_17 ;
}
* V_3 = V_10 ;
}
return V_16 ;
}
