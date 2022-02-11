static int F_1 ( int V_1 , unsigned long V_2 , int V_3 )
{
int V_4 ;
V_4 = F_2 ( ( V_1 * V_2 ) , V_5 ) - 1 ;
F_3 ( L_1 , V_6 , V_4 , V_2 , V_1 ) ;
if ( V_4 < 0 )
V_4 = 0 ;
else if ( V_4 > V_3 )
V_4 = - V_7 ;
return V_4 ;
}
int F_4 ( struct V_8 * V_9 ,
void T_1 * V_10 , unsigned V_11 )
{
unsigned V_12 , V_13 ;
int V_14 , V_15 , V_16 , V_17 , V_18 , V_19 , V_20 ;
unsigned V_21 = V_22 + V_11 * 4 ;
struct V_2 * V_23 ;
unsigned long V_24 ;
if ( ! V_9 )
return 0 ;
V_23 = F_5 ( NULL , L_2 ) ;
if ( F_6 ( V_23 ) )
return F_7 ( V_23 ) ;
V_24 = F_8 ( V_23 ) ;
V_24 /= 1000 ;
V_14 = F_1 ( V_9 -> V_14 , V_24 , V_25 ) ;
V_15 = F_1 ( V_9 -> V_15 , V_24 , V_26 ) ;
V_16 = F_1 ( V_9 -> V_16 , V_24 , V_27 ) ;
V_17 = F_1 ( V_9 -> V_17 , V_24 , V_28 ) ;
V_18 = F_1 ( V_9 -> V_18 , V_24 , V_29 ) ;
V_19 = F_1 ( V_9 -> V_19 , V_24 , V_30 ) ;
V_20 = F_1 ( V_9 -> V_20 , V_24 , V_31 ) ;
if ( V_14 < 0 || V_15 < 0 || V_16 < 0 || V_17 < 0 ||
V_18 < 0 || V_19 < 0 || V_20 < 0 ) {
F_9 ( L_3 , V_6 ) ;
return - V_7 ;
}
V_12 = F_10 ( V_14 ) | F_11 ( V_15 ) | F_12 ( V_16 ) | F_13 ( V_17 ) |
F_14 ( V_18 ) | F_15 ( V_19 ) | F_16 ( V_20 ) ;
V_13 = F_17 ( V_10 + V_21 ) ;
V_13 &= ~ V_32 ;
V_13 |= V_12 ;
F_18 ( V_13 , V_10 + V_21 ) ;
return 0 ;
}
