int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 , struct V_6 * V_7 ,
T_1 V_8 , struct V_9 * V_10 )
{
int V_11 = F_2 ( V_4 ) ;
int V_12 , V_13 = V_11 - V_5 ;
struct V_3 * V_14 ;
T_2 V_15 = 0 ;
if ( V_13 > 0 ) {
if ( V_13 > V_8 )
V_13 = V_8 ;
V_15 = F_3 ( V_2 , V_7 , V_10 ,
V_4 -> V_16 + V_5 , V_13 ) ;
if ( V_15 < 0 )
goto V_17;
V_8 -= V_13 ;
if ( V_8 == 0 )
goto V_18;
V_5 += V_13 ;
}
for ( V_12 = 0 ; V_12 < F_4 ( V_4 ) -> V_19 ; V_12 ++ ) {
int V_18 ;
const T_3 * V_20 = & F_4 ( V_4 ) -> V_21 [ V_12 ] ;
F_5 ( V_11 > V_5 + V_8 ) ;
V_18 = V_11 + F_6 ( V_20 ) ;
V_13 = V_18 - V_5 ;
if ( V_13 > 0 ) {
struct V_22 * V_22 = F_7 ( V_20 ) ;
if ( V_13 > V_8 )
V_13 = V_8 ;
V_15 = F_8 ( V_2 , V_7 , V_10 , V_22 ,
V_20 -> V_23 + V_5 - V_11 , V_13 ) ;
if ( V_15 < 0 )
goto V_17;
V_8 -= V_13 ;
if ( V_8 == 0 )
goto V_18;
V_5 += V_13 ;
}
V_11 = V_18 ;
}
F_9 (skb, frag_iter) {
int V_18 ;
F_5 ( V_11 > V_5 + V_8 ) ;
V_18 = V_11 + V_14 -> V_8 ;
V_13 = V_18 - V_5 ;
if ( V_13 > 0 ) {
if ( V_13 > V_8 )
V_13 = V_8 ;
V_15 = F_1 ( V_2 , V_14 ,
V_5 - V_11 ,
V_7 , V_13 ,
V_10 ) ;
if ( V_15 < 0 )
goto V_17;
V_8 -= V_13 ;
if ( V_8 == 0 )
goto V_18;
V_5 += V_13 ;
}
V_11 = V_18 ;
}
V_18:
if ( ! V_8 ) {
V_4 -> V_24 = V_15 ;
return V_15 ;
}
V_17:
return - V_25 ;
}
