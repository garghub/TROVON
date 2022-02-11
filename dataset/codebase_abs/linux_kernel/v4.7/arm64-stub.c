T_1 F_1 ( T_2 * V_1 )
{
T_3 V_2 ;
if ( F_2 ( V_3 ) )
return V_4 ;
V_2 = ( F_3 ( V_5 ) >> V_6 ) & 0xf ;
if ( V_2 != V_7 ) {
if ( F_2 ( V_8 ) )
F_4 ( V_1 , L_1 ) ;
else
F_4 ( V_1 , L_2 ) ;
return V_9 ;
}
return V_4 ;
}
T_1 F_5 ( T_2 * V_1 ,
unsigned long * V_10 ,
unsigned long * V_11 ,
unsigned long * V_12 ,
unsigned long * V_13 ,
unsigned long V_14 ,
T_4 * V_15 )
{
T_1 V_16 ;
unsigned long V_17 , V_18 = 0 ;
void * V_19 = ( void * ) * V_10 ;
unsigned long V_20 ;
T_3 V_21 = 0 ;
if ( F_2 ( V_22 ) ) {
if ( ! V_23 ) {
V_16 = F_6 ( V_1 ,
sizeof( V_21 ) ,
( V_24 * ) & V_21 ) ;
if ( V_16 == V_25 ) {
F_7 ( V_1 , L_3 ) ;
} else if ( V_16 != V_4 ) {
F_4 ( V_1 , L_4 ) ;
return V_16 ;
}
} else {
F_7 ( V_1 , L_5 ) ;
}
}
V_20 = F_8 ( V_14 , V_26 ) + V_27 ;
if ( V_20 < V_14 )
V_20 += V_26 ;
V_17 = V_28 - V_29 ;
V_18 = V_17 + ( V_30 - V_28 ) ;
if ( F_2 ( V_22 ) && V_21 != 0 ) {
T_5 V_31 = ( V_26 - 1 ) & ~ ( V_32 - 1 ) ;
T_5 V_33 = ! F_2 ( V_34 ) ?
( V_21 >> 32 ) & V_31 : V_27 ;
* V_13 = V_18 + V_33 ;
V_16 = F_9 ( V_1 , * V_13 ,
V_26 , V_12 ,
( T_5 ) V_21 ) ;
* V_10 = * V_12 + V_33 ;
} else {
if ( * V_10 == V_20 )
return V_4 ;
* V_10 = * V_12 = V_20 ;
* V_13 = F_10 ( V_18 , V_35 ) ;
V_16 = F_11 ( V_36 , V_37 ,
V_38 ,
* V_13 / V_39 ,
( V_40 * ) V_12 ) ;
}
if ( V_16 != V_4 ) {
* V_13 = V_18 + V_27 ;
V_16 = F_12 ( V_1 , * V_13 ,
V_26 , V_12 ) ;
if ( V_16 != V_4 ) {
F_4 ( V_1 , L_6 ) ;
* V_13 = 0 ;
return V_16 ;
}
* V_10 = * V_12 + V_27 ;
}
memcpy ( ( void * ) * V_10 , V_19 , V_17 ) ;
return V_4 ;
}
