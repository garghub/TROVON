int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> type -> V_7 )
return V_6 -> type -> V_7 ( V_6 , V_3 , V_4 ) ;
else
return - V_8 ;
}
int F_3 ( struct V_1 * V_2 , int V_3 , T_2 V_9 ,
T_1 V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> type -> V_11 ) {
if ( ( V_9 & ~ V_12 ) ||
( V_10 & ~ ( V_13 >> V_14 ) ) )
return - V_15 ;
return V_6 -> type -> V_11 ( V_6 , V_3 , V_9 , V_10 ) ;
} else {
return - V_8 ;
}
}
int F_4 ( struct V_1 * V_2 , int V_3 ,
bool V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> type -> V_17 )
return V_6 -> type -> V_17 ( V_6 , V_3 , V_16 ) ;
else
return - V_8 ;
}
int F_5 ( struct V_1 * V_2 , int V_3 ,
struct V_18 * V_19 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> type -> V_20 )
return V_6 -> type -> V_20 ( V_6 , V_3 , V_19 ) ;
else
return - V_8 ;
}
int F_6 ( struct V_1 * V_2 , int V_3 ,
int V_21 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> type -> V_22 )
return V_6 -> type -> V_22 ( V_6 , V_3 ,
V_21 ) ;
else
return - V_8 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> type -> V_25 )
return V_6 -> type -> V_25 ( V_6 , V_24 ) ;
else
return - V_8 ;
}
