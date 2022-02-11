T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
unsigned long V_5 = V_2 -> V_6 ;
unsigned long V_7 ;
T_1 V_8 ;
T_1 V_9 ;
int V_10 = V_2 -> V_11 ;
if ( V_3 == 0 )
return 0 ;
F_2 ( V_10 ) -> F_3 ( V_2 , & V_4 , NULL , & V_8 ) ;
V_7 = F_4 ( V_3 , V_5 ) ;
if ( V_7 )
V_9 = V_3 * V_8 + V_4 * V_5 + V_7 ;
else
V_9 = ( V_3 - 1 ) * V_8 + ( V_4 + 1 ) * V_5 ;
return V_9 ;
}
T_2 F_5 ( struct V_1 * V_2 , T_2 V_12 ,
int V_13 )
{
T_3 V_14 ;
V_14 = F_1 ( V_2 , ( V_12 << V_15 ) + 1 , V_13 ) ;
return V_14 >> V_15 ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_16 ,
int V_4 , T_1 * V_17 )
{
unsigned long V_5 = V_2 -> V_6 ;
T_1 V_18 , V_19 , V_8 ;
int V_10 = V_2 -> V_11 ;
int V_20 = 0 ;
if ( V_16 == V_21 ) {
* V_17 = V_21 ;
return 0 ;
}
F_2 ( V_10 ) -> F_3 ( V_2 , & V_4 , & V_16 ,
& V_8 ) ;
V_18 = F_4 ( V_16 , V_8 ) ;
V_19 = ( T_1 ) V_4 * V_5 ;
if ( V_18 < V_19 ) {
V_18 = 0 ;
V_20 = - 1 ;
} else {
V_18 -= V_19 ;
if ( V_18 >= V_5 ) {
V_18 = V_5 ;
V_20 = 1 ;
}
}
* V_17 = V_16 * V_5 + V_18 ;
return V_20 ;
}
T_1 F_7 ( struct V_1 * V_2 , T_1 V_22 ,
int V_4 )
{
unsigned long V_5 = V_2 -> V_6 ;
T_1 V_18 , V_19 , V_8 ;
int V_10 = V_2 -> V_11 ;
if ( V_22 == V_21 )
return V_21 ;
F_2 ( V_10 ) -> F_3 ( V_2 , & V_4 , & V_22 ,
& V_8 ) ;
V_18 = F_4 ( V_22 , V_8 ) ;
V_19 = ( T_1 ) V_4 * V_5 ;
if ( V_18 < V_19 ) {
if ( V_22 > 0 ) {
V_22 -- ;
V_18 = V_5 ;
} else {
V_18 = 0 ;
}
} else {
V_18 -= V_19 ;
if ( V_18 >= V_5 ) {
V_18 = V_5 ;
}
}
return ( V_22 * V_5 + V_18 ) ;
}
int F_8 ( struct V_1 * V_2 , int V_4 ,
T_1 V_23 , T_1 V_24 , T_1 * V_25 , T_1 * V_26 )
{
int V_27 , V_28 ;
V_27 = F_6 ( V_2 , V_23 , V_4 , V_25 ) ;
V_28 = F_6 ( V_2 , V_24 , V_4 , V_26 ) ;
F_9 ( V_29 , L_1 ,
V_23 , V_24 , V_27 , * V_25 , * V_26 , V_28 ) ;
if ( V_27 != 0 && V_28 != 0 && * V_25 == * V_26 )
return 0 ;
if ( V_28 != 0 )
( * V_26 ) -- ;
return 1 ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_16 )
{
unsigned long V_5 = V_2 -> V_6 ;
T_1 V_18 , V_8 ;
int V_10 = V_2 -> V_11 ;
F_2 ( V_10 ) -> F_11 ( V_2 , NULL , & V_16 , & V_8 ) ;
V_18 = F_4 ( V_16 , V_8 ) ;
F_4 ( V_18 , V_5 ) ;
return V_18 ;
}
