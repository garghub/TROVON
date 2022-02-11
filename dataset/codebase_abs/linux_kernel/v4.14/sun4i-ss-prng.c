int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_6 = F_3 ( V_8 , struct V_5 , V_8 . V_9 ) ;
memcpy ( V_6 -> V_10 -> V_3 , V_3 , V_4 ) ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , const T_1 * V_11 ,
unsigned int V_4 , T_1 * V_12 , unsigned int V_13 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_14 ;
T_2 V_15 ;
T_2 * V_16 = ( T_2 * ) V_12 ;
const T_2 V_17 = V_18 | V_19 | V_20 ;
T_3 V_21 ;
struct V_22 * V_10 ;
unsigned int V_23 = ( V_13 / 4 ) * 4 ;
V_6 = F_3 ( V_8 , struct V_5 , V_8 . V_9 ) ;
V_10 = V_6 -> V_10 ;
F_5 ( & V_10 -> V_24 ) ;
F_6 ( V_17 , V_10 -> V_25 + V_26 ) ;
while ( V_23 > 0 ) {
for ( V_14 = 0 ; V_14 < V_27 / V_28 ; V_14 ++ )
F_6 ( V_10 -> V_3 [ V_14 ] , V_10 -> V_25 + V_29 + V_14 * 4 ) ;
V_21 = F_7 ( T_3 , V_30 / V_31 , V_23 ) ;
F_8 ( V_10 -> V_25 + V_32 , V_16 , V_21 / 4 ) ;
V_16 += V_21 / 4 ;
V_23 -= V_21 ;
for ( V_14 = 0 ; V_14 < V_27 / V_28 ; V_14 ++ ) {
V_15 = F_9 ( V_10 -> V_25 + V_29 + V_14 * 4 ) ;
V_10 -> V_3 [ V_14 ] = V_15 ;
}
}
F_6 ( 0 , V_10 -> V_25 + V_26 ) ;
F_10 ( & V_10 -> V_24 ) ;
return V_13 ;
}
