int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 ,
int * V_6 , int * V_7 , int * V_8 , int * V_9 , int * V_10 )
{
struct V_11 V_12 ;
int V_13 ;
V_13 = F_2 ( V_2 , V_4 , V_5 , & V_12 ) ;
if ( V_13 <= 0 )
return V_13 ;
* V_6 = V_12 . V_6 ;
* V_7 = V_12 . V_7 ;
* V_8 = V_12 . V_8 ;
* V_9 = V_12 . V_9 ;
* V_10 = V_12 . V_14 ;
return V_13 ;
}
int
F_3 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 ,
int * V_15 , int * V_16 , int * V_17 , int * V_10 )
{
T_1 V_18 = ~ 0 , V_19 ;
int V_20 , V_21 , V_22 , V_23 , V_24 ;
* V_10 = V_4 -> V_25 . V_26 / V_5 ;
if ( * V_10 > V_4 -> V_27 )
* V_10 = V_4 -> V_27 ;
if ( * V_10 < V_4 -> V_28 )
* V_10 = V_4 -> V_28 ;
V_21 = ( V_4 -> V_29 + V_4 -> V_25 . V_30 ) / V_4 -> V_25 . V_30 ;
V_21 = F_4 ( V_21 , ( int ) V_4 -> V_25 . V_31 ) ;
V_22 = ( V_4 -> V_29 + V_4 -> V_25 . V_32 ) / V_4 -> V_25 . V_32 ;
V_22 = F_5 ( V_22 , ( int ) V_4 -> V_25 . V_33 ) ;
for ( V_20 = V_21 ; V_20 <= V_22 ; V_20 ++ ) {
T_1 V_34 = V_5 * * V_10 * V_20 ;
V_23 = V_34 / V_4 -> V_29 ;
V_24 = V_34 % V_4 -> V_29 ;
if ( ! V_16 && V_24 >= V_4 -> V_29 / 2 )
V_23 ++ ;
if ( V_23 < V_4 -> V_25 . V_35 )
continue;
if ( V_23 > V_4 -> V_25 . V_36 )
break;
V_19 = abs ( V_5 - ( V_4 -> V_29 * V_23 / V_20 / * V_10 ) ) ;
if ( V_19 < V_18 ) {
V_18 = V_19 ;
* V_15 = V_23 ;
* V_17 = V_20 ;
}
if ( V_16 ) {
* V_16 = ( ( ( V_24 << 13 ) / V_4 -> V_29 ) - 4096 ) & 0xffff ;
return V_5 ;
}
}
if ( F_6 ( V_18 == ~ 0 ) ) {
F_7 ( V_2 , L_1 ) ;
return - V_37 ;
}
return V_4 -> V_29 * * V_15 / * V_17 / * V_10 ;
}
