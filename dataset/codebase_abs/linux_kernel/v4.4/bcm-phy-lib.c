int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 , V_6 , V_3 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_2 ( V_2 , V_7 , V_4 ) ;
}
int F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 , V_6 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_4 ( V_2 , V_7 ) ;
F_2 ( V_2 , V_6 , 0 ) ;
return V_4 ;
}
int F_5 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_8 , T_1 V_4 )
{
int V_5 ;
int V_9 ;
V_5 = F_2 ( V_2 , V_10 ,
V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
V_9 = F_4 ( V_2 , V_10 ) ;
V_9 |= V_12 ;
V_5 = F_2 ( V_2 , V_10 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
V_9 = ( V_8 * V_13 ) | V_3 ;
V_5 = F_1 ( V_2 , V_9 , V_4 ) ;
return V_5 ;
}
int F_6 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_8 )
{
int V_5 ;
int V_9 ;
V_5 = F_2 ( V_2 , V_10 ,
V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
V_9 = F_4 ( V_2 , V_10 ) ;
V_9 |= V_12 ;
V_5 = F_2 ( V_2 , V_10 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
V_9 = ( V_8 * V_13 ) | V_3 ;
V_5 = F_3 ( V_2 , V_9 ) ;
return V_5 ;
}
int F_7 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_14 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_15 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_16 == V_17 )
V_3 &= ~ V_18 ;
else
V_3 |= V_18 ;
return F_2 ( V_2 , V_15 , V_3 ) ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_19 )
{
F_2 ( V_2 , V_20 , F_10 ( V_19 ) ) ;
return F_11 ( F_4 ( V_2 , V_20 ) ) ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_19 ,
T_1 V_4 )
{
return F_2 ( V_2 , V_20 ,
V_21 |
F_10 ( V_19 ) |
F_11 ( V_4 ) ) ;
}
int F_13 ( struct V_1 * V_2 , bool V_22 )
{
int V_4 ;
if ( V_22 ) {
V_4 = F_9 ( V_2 , V_23 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 |= V_24 ;
F_12 ( V_2 , V_23 , V_4 ) ;
}
V_4 = F_9 ( V_2 , V_25 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 &= V_26 ;
if ( V_2 -> V_27 == V_28 )
V_4 |= V_29 ;
else
V_4 |= V_30 ;
V_4 |= V_31 ;
return F_12 ( V_2 , V_25 , V_4 ) ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_15 ( V_2 , V_32 ,
V_33 , V_2 -> V_34 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 |= V_35 | V_36 ;
F_16 ( V_2 , V_32 ,
V_33 , V_2 -> V_34 , ( V_37 ) V_4 ) ;
V_4 = F_15 ( V_2 , V_38 ,
V_33 , V_2 -> V_34 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 |= ( V_39 | V_40 ) ;
F_16 ( V_2 , V_38 ,
V_33 , V_2 -> V_34 , ( V_37 ) V_4 ) ;
return 0 ;
}
