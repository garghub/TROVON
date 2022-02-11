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
int F_5 ( struct V_1 * V_2 , T_1 V_12 ,
int V_4 , T_1 * V_13 )
{
unsigned long V_5 = V_2 -> V_6 ;
T_1 V_14 , V_15 , V_8 ;
int V_10 = V_2 -> V_11 ;
int V_16 = 0 ;
if ( V_12 == V_17 ) {
* V_13 = V_17 ;
return 0 ;
}
F_2 ( V_10 ) -> F_3 ( V_2 , & V_4 , & V_12 ,
& V_8 ) ;
V_14 = F_4 ( V_12 , V_8 ) ;
V_15 = ( T_1 ) V_4 * V_5 ;
if ( V_14 < V_15 ) {
V_14 = 0 ;
V_16 = - 1 ;
} else {
V_14 -= V_15 ;
if ( V_14 >= V_5 ) {
V_14 = V_5 ;
V_16 = 1 ;
}
}
* V_13 = V_12 * V_5 + V_14 ;
return V_16 ;
}
T_1 F_6 ( struct V_1 * V_2 , T_1 V_18 ,
int V_4 )
{
unsigned long V_5 = V_2 -> V_6 ;
T_1 V_14 , V_15 , V_8 ;
int V_10 = V_2 -> V_11 ;
if ( V_18 == V_17 )
return V_17 ;
F_2 ( V_10 ) -> F_3 ( V_2 , & V_4 , & V_18 ,
& V_8 ) ;
V_14 = F_4 ( V_18 , V_8 ) ;
V_15 = ( T_1 ) V_4 * V_5 ;
if ( V_14 < V_15 ) {
if ( V_18 > 0 ) {
V_18 -- ;
V_14 = V_5 ;
} else {
V_14 = 0 ;
}
} else {
V_14 -= V_15 ;
if ( V_14 >= V_5 ) {
V_14 = V_5 ;
}
}
return ( V_18 * V_5 + V_14 ) ;
}
int F_7 ( struct V_1 * V_2 , int V_4 ,
T_1 V_19 , T_1 V_20 , T_1 * V_21 , T_1 * V_22 )
{
int V_23 , V_24 ;
V_23 = F_5 ( V_2 , V_19 , V_4 , V_21 ) ;
V_24 = F_5 ( V_2 , V_20 , V_4 , V_22 ) ;
F_8 ( V_25 , L_1 ,
V_19 , V_20 , V_23 , * V_21 , * V_22 , V_24 ) ;
if ( V_23 != 0 && V_24 != 0 && * V_21 == * V_22 )
return 0 ;
if ( V_24 != 0 )
( * V_22 ) -- ;
return 1 ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_12 )
{
unsigned long V_5 = V_2 -> V_6 ;
T_1 V_14 , V_8 ;
int V_10 = V_2 -> V_11 ;
F_2 ( V_10 ) -> F_10 ( V_2 , NULL , & V_12 , & V_8 ) ;
V_14 = F_4 ( V_12 , V_8 ) ;
F_4 ( V_14 , V_5 ) ;
return V_14 ;
}
