int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 = 0 ;
T_1 V_8 = 0 ;
T_1 V_9 ;
unsigned long V_10 , V_11 , V_12 ;
struct V_13 * V_14 ;
struct V_13 * V_15 ;
int V_16 ;
unsigned long V_17 ;
if ( ! V_6 || ! V_3 )
return - V_18 ;
V_7 = F_3 ( V_4 , V_3 ) ;
V_10 = V_4 / V_7 ;
if ( V_10 != V_3 )
return - V_18 ;
V_11 = F_4 ( V_19 ) ;
V_17 = F_5 ( V_2 ) ;
if ( V_3 > V_17 )
V_11 <<= ( ( V_3 / V_17 ) >> 1 ) ;
else
V_11 >>= ( ( V_17 / V_3 ) >> 1 ) ;
V_16 = F_6 ( V_11 , & V_14 , & V_15 ) ;
if ( V_16 )
return - V_18 ;
if ( V_11 < V_20 ) {
F_7 ( L_1 ) ;
V_8 = 1 ;
}
V_12 = F_4 ( V_21 ) / V_22 ;
V_9 = ( V_12 << V_23 ) >> V_24 ;
V_9 += 1 ;
V_9 *= V_25 ;
V_9 >>= V_23 ;
if ( V_9 == 0 )
V_9 = 1 ;
F_7 ( L_2 ,
V_17 , V_10 ) ;
F_7 ( L_3 ,
V_14 -> V_26 , V_14 -> V_27 ,
V_14 -> V_28 , V_14 -> V_29 ) ;
if ( V_15 )
F_7 ( L_4 ,
V_15 -> V_26 , V_15 -> V_27 ,
V_15 -> V_28 , V_15 -> V_29 ) ;
if ( V_15 )
F_8 (
V_7 , V_8 , V_9 , V_3 > V_17 ,
V_14 -> V_26 , V_14 -> V_27 ,
V_14 -> V_28 , V_14 -> V_29 ,
V_15 -> V_26 , V_15 -> V_27 ,
V_15 -> V_28 , V_15 -> V_29 ) ;
else
F_8 (
V_7 , V_8 , V_9 , V_3 > V_17 ,
V_14 -> V_26 , V_14 -> V_27 ,
V_14 -> V_28 , V_14 -> V_29 ,
0 , 0 , 0 , 0 ) ;
return 0 ;
}
