void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 = 0 ;
V_8 = F_2 ( V_6 , V_3 , V_4 , V_9 , 0 ) ;
if ( F_3 ( V_8 != 0 ) ) {
F_4 ( L_1 \
L_2 ,
V_6 , ( unsigned long long ) V_3 ,
( unsigned long long ) V_4 , V_8 ) ;
}
F_5 ( L_1 \
L_3 ,
V_6 , ( unsigned long long ) V_3 ,
( unsigned long long ) V_4 , V_8 ) ;
return;
}
int F_6 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_1 * V_12 = F_7 ( V_2 -> V_7 ) -> V_12 ;
struct V_13 * V_14 = F_7 ( V_2 -> V_7 ) -> V_13 ;
struct V_5 * V_6 = V_12 -> V_7 ;
int V_15 , V_16 ;
T_1 V_17 , V_18 , V_19 ;
T_1 V_20 = 0 ;
V_17 = V_11 -> V_17 >> V_6 -> V_21 ;
V_18 = V_17 + ( V_11 -> V_22 >> V_6 -> V_21 ) - 1 ;
V_19 = V_11 -> V_19 >> V_6 -> V_21 ;
if ( V_19 == 0 )
V_19 = 1 ;
if ( V_19 > V_14 -> V_23 ||
V_17 >= V_14 -> V_24 ||
V_11 -> V_22 < V_6 -> V_25 )
return - V_26 ;
if ( V_18 >= V_14 -> V_24 )
V_18 = V_14 -> V_24 - 1 ;
V_15 = F_8 ( V_17 , F_7 ( V_2 -> V_7 ) ) ;
V_16 = F_8 ( V_18 , F_7 ( V_2 -> V_7 ) ) ;
while ( V_15 <= V_16 ) {
V_20 += F_9 ( V_2 , V_15 , V_19 ) ;
V_15 ++ ;
}
V_11 -> V_22 = V_20 << V_6 -> V_21 ;
return 0 ;
}
