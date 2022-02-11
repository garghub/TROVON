T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 ,
int V_4 )
{
unsigned long V_5 = V_2 -> V_6 ;
unsigned long V_7 ;
T_2 V_8 ;
T_1 V_9 ;
int V_10 = V_2 -> V_11 ;
V_12 ;
if ( V_3 == 0 )
RETURN ( 0 ) ;
F_2 ( F_3 ( V_10 ) != NULL ) ;
F_3 ( V_10 ) -> F_4 ( V_2 , & V_4 , NULL , & V_8 ) ;
V_7 = F_5 ( V_3 , V_5 ) ;
if ( V_7 )
V_9 = V_3 * V_8 + V_4 * V_5 + V_7 ;
else
V_9 = ( V_3 - 1 ) * V_8 + ( V_4 + 1 ) * V_5 ;
RETURN ( V_9 ) ;
}
int F_6 ( struct V_1 * V_2 , T_2 V_13 ,
int V_4 , T_2 * V_14 )
{
unsigned long V_5 = V_2 -> V_6 ;
T_2 V_15 , V_16 , V_8 ;
int V_10 = V_2 -> V_11 ;
int V_17 = 0 ;
if ( V_13 == V_18 ) {
* V_14 = V_18 ;
return 0 ;
}
F_2 ( F_3 ( V_10 ) != NULL ) ;
F_3 ( V_10 ) -> F_4 ( V_2 , & V_4 , & V_13 ,
& V_8 ) ;
V_15 = F_5 ( V_13 , V_8 ) ;
V_16 = ( T_2 ) V_4 * V_5 ;
if ( V_15 < V_16 ) {
V_15 = 0 ;
V_17 = - 1 ;
} else {
V_15 -= V_16 ;
if ( V_15 >= V_5 ) {
V_15 = V_5 ;
V_17 = 1 ;
}
}
* V_14 = V_13 * V_5 + V_15 ;
return V_17 ;
}
T_2 F_7 ( struct V_1 * V_2 , T_2 V_19 ,
int V_4 )
{
unsigned long V_5 = V_2 -> V_6 ;
T_2 V_15 , V_16 , V_8 ;
int V_10 = V_2 -> V_11 ;
if ( V_19 == V_18 )
return V_18 ;
F_2 ( F_3 ( V_10 ) != NULL ) ;
F_3 ( V_10 ) -> F_4 ( V_2 , & V_4 , & V_19 ,
& V_8 ) ;
V_15 = F_5 ( V_19 , V_8 ) ;
V_16 = ( T_2 ) V_4 * V_5 ;
if ( V_15 < V_16 ) {
if ( V_19 > 0 ) {
V_19 -- ;
V_15 = V_5 ;
} else {
V_15 = 0 ;
}
} else {
V_15 -= V_16 ;
if ( V_15 >= V_5 ) {
V_15 = V_5 ;
}
}
return ( V_19 * V_5 + V_15 ) ;
}
int F_8 ( struct V_1 * V_2 , int V_4 ,
T_2 V_20 , T_2 V_21 ,
T_2 * V_22 , T_2 * V_23 )
{
int V_24 , V_25 ;
V_24 = F_6 ( V_2 , V_20 , V_4 , V_22 ) ;
V_25 = F_6 ( V_2 , V_21 , V_4 , V_23 ) ;
F_9 ( V_26 , L_1 V_27 L_2 V_27 L_3 V_27 L_2 V_27 L_4 ,
V_20 , V_21 , V_24 , * V_22 , * V_23 , V_25 ) ;
if ( V_24 != 0 && V_25 != 0 && * V_22 == * V_23 )
return 0 ;
if ( V_25 != 0 )
( * V_23 ) -- ;
return 1 ;
}
int F_10 ( struct V_1 * V_2 , T_2 V_13 )
{
unsigned long V_5 = V_2 -> V_6 ;
T_2 V_15 , V_8 ;
int V_10 = V_2 -> V_11 ;
F_2 ( F_3 ( V_10 ) != NULL ) ;
F_3 ( V_10 ) -> F_11 ( V_2 , NULL , & V_13 , & V_8 ) ;
V_15 = F_5 ( V_13 , V_8 ) ;
F_5 ( V_15 , V_5 ) ;
return V_15 ;
}
