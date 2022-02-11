int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
V_2 -> V_4 = 0 ;
V_2 -> V_5 = 70 + 52 * V_3 ;
V_2 -> V_6 = 8 ;
V_2 -> V_7 = 65 ;
V_2 -> V_8 = 95 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 80 ;
V_2 -> V_11 = 260 ;
V_2 -> V_12 = 0 ;
V_2 -> V_13 = 0 ;
V_2 -> V_14 = 120 ;
V_2 -> V_15 = 65 + 5 * V_3 ;
V_2 -> V_16 = 145 + 5 * V_3 ;
V_2 -> V_17 = 85 + 6 * V_3 ;
V_2 -> V_18 = 40 ;
V_2 -> V_19 = F_2 ( 4 * 8 * V_3 , 60 + 4 * 4 * V_3 ) ;
V_2 -> V_20 = 100000 ;
V_2 -> V_21 = 60 ;
V_2 -> V_22 = 5 * V_2 -> V_21 ;
V_2 -> V_23 = 4 * V_2 -> V_21 ;
V_2 -> V_24 = 2 * V_2 -> V_21 ;
V_2 -> V_25 = 1000000 ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
if ( V_2 -> V_4 > 60 )
return - V_26 ;
if ( V_2 -> V_5 < ( 60 + 52 * V_3 ) )
return - V_26 ;
if ( V_2 -> V_6 < 8 )
return - V_26 ;
if ( V_2 -> V_7 < 38 || V_2 -> V_7 > 95 )
return - V_26 ;
if ( V_2 -> V_8 < 95 || V_2 -> V_8 > 300 )
return - V_26 ;
if ( V_2 -> V_9 > 38 )
return - V_26 ;
if ( V_2 -> V_10 < 60 )
return - V_26 ;
if ( V_2 -> V_7 + V_2 -> V_11 < 300 )
return - V_26 ;
if ( V_2 -> V_12 > 35 + 4 * V_3 )
return - V_26 ;
if ( V_2 -> V_13 > 105 + 12 * V_3 )
return - V_26 ;
if ( V_2 -> V_14 < 100 )
return - V_26 ;
if ( V_2 -> V_15 < 40 + 4 * V_3 ||
V_2 -> V_15 > 85 + 6 * V_3 )
return - V_26 ;
if ( V_2 -> V_15 + V_2 -> V_16 < 145 + 10 * V_3 )
return - V_26 ;
if ( ( V_2 -> V_17 < 85 + 6 * V_3 ) ||
( V_2 -> V_17 > 145 + 10 * V_3 ) )
return - V_26 ;
if ( V_2 -> V_18 < 40 || V_2 -> V_18 > 55 + 4 * V_3 )
return - V_26 ;
if ( V_2 -> V_19 < F_2 ( 8 * V_3 , 60 + 4 * V_3 ) )
return - V_26 ;
if ( V_2 -> V_20 < 100000 )
return - V_26 ;
if ( V_2 -> V_21 < 50 )
return - V_26 ;
if ( V_2 -> V_22 != 5 * V_2 -> V_21 )
return - V_26 ;
if ( V_2 -> V_23 != 4 * V_2 -> V_21 )
return - V_26 ;
if ( V_2 -> V_24 < V_2 -> V_21 || V_2 -> V_24 > 2 * V_2 -> V_21 )
return - V_26 ;
if ( V_2 -> V_25 < 1000000 )
return - V_26 ;
return 0 ;
}
