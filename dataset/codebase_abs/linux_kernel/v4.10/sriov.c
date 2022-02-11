int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> type -> V_7 )
return V_6 -> type -> V_7 ( V_6 , V_3 , V_4 ) ;
else
return - V_8 ;
}
int F_3 ( struct V_1 * V_2 , int V_3 , T_2 V_9 ,
T_1 V_10 , T_3 V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> type -> V_12 ) {
if ( ( V_9 & ~ V_13 ) ||
( V_10 & ~ ( V_14 >> V_15 ) ) )
return - V_16 ;
if ( V_11 != F_4 ( V_17 ) )
return - V_18 ;
return V_6 -> type -> V_12 ( V_6 , V_3 , V_9 , V_10 ) ;
} else {
return - V_8 ;
}
}
int F_5 ( struct V_1 * V_2 , int V_3 ,
bool V_19 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> type -> V_20 )
return V_6 -> type -> V_20 ( V_6 , V_3 , V_19 ) ;
else
return - V_8 ;
}
int F_6 ( struct V_1 * V_2 , int V_3 ,
struct V_21 * V_22 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> type -> V_23 )
return V_6 -> type -> V_23 ( V_6 , V_3 , V_22 ) ;
else
return - V_8 ;
}
int F_7 ( struct V_1 * V_2 , int V_3 ,
int V_24 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> type -> V_25 )
return V_6 -> type -> V_25 ( V_6 , V_3 ,
V_24 ) ;
else
return - V_8 ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> type -> V_28 )
return V_6 -> type -> V_28 ( V_6 , V_27 ) ;
else
return - V_8 ;
}
