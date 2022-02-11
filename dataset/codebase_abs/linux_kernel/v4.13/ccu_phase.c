static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 , * V_6 ;
unsigned int V_7 , V_8 ;
T_1 V_9 , V_10 ;
T_2 V_11 ;
T_3 V_12 ;
V_11 = F_3 ( V_4 -> V_13 . V_14 + V_4 -> V_13 . V_11 ) ;
V_12 = ( V_11 >> V_4 -> V_15 ) ;
V_12 &= ( 1 << V_4 -> V_16 ) - 1 ;
if ( ! V_12 )
return 180 ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_5 )
return - V_17 ;
V_7 = F_5 ( V_5 ) ;
if ( ! V_7 )
return - V_17 ;
V_6 = F_4 ( V_5 ) ;
if ( ! V_6 )
return - V_17 ;
V_8 = F_5 ( V_6 ) ;
if ( ! V_8 )
return - V_17 ;
V_10 = V_8 / V_7 ;
V_9 = F_6 ( 360 , V_10 ) ;
return V_12 * V_9 ;
}
static int F_7 ( struct V_1 * V_2 , int V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_1 * V_5 , * V_6 ;
unsigned int V_7 , V_8 ;
unsigned long V_19 ;
T_2 V_11 ;
T_3 V_12 ;
V_5 = F_4 ( V_2 ) ;
if ( ! V_5 )
return - V_17 ;
V_7 = F_5 ( V_5 ) ;
if ( ! V_7 )
return - V_17 ;
V_6 = F_4 ( V_5 ) ;
if ( ! V_6 )
return - V_17 ;
V_8 = F_5 ( V_6 ) ;
if ( ! V_8 )
return - V_17 ;
if ( V_18 != 180 ) {
T_1 V_9 , V_10 ;
V_10 = V_8 / V_7 ;
V_9 = F_6 ( 360 , V_10 ) ;
V_12 = F_6 ( V_18 , V_9 ) ;
} else {
V_12 = 0 ;
}
F_8 ( V_4 -> V_13 . V_20 , V_19 ) ;
V_11 = F_3 ( V_4 -> V_13 . V_14 + V_4 -> V_13 . V_11 ) ;
V_11 &= ~ F_9 ( V_4 -> V_16 + V_4 -> V_15 - 1 , V_4 -> V_15 ) ;
F_10 ( V_11 | ( V_12 << V_4 -> V_15 ) ,
V_4 -> V_13 . V_14 + V_4 -> V_13 . V_11 ) ;
F_11 ( V_4 -> V_13 . V_20 , V_19 ) ;
return 0 ;
}
