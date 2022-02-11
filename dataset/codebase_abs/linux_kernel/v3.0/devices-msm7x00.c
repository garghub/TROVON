int T_1 F_1 ( unsigned int V_1 ,
struct V_2 * V_3 ,
unsigned int V_4 , unsigned long V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
if ( V_1 < 1 || V_1 > 4 )
return - V_10 ;
V_7 = V_11 [ V_1 - 1 ] ;
V_7 -> V_12 . V_13 = V_3 ;
V_9 = F_2 ( V_7 , V_14 , L_1 ) ;
if ( ! V_9 )
return - V_10 ;
else if ( V_4 ) {
V_9 -> V_15 = V_9 -> V_16 = V_4 ;
V_9 -> V_17 &= ~ V_18 ;
V_9 -> V_17 |= V_5 ;
}
return F_3 ( V_7 ) ;
}
