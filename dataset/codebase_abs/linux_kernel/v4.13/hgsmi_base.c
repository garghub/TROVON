int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 , sizeof( * V_5 ) , V_6 ,
V_7 ) ;
if ( ! V_5 )
return - V_8 ;
V_5 -> V_9 = V_3 ;
V_5 -> V_10 = sizeof( struct V_11 ) ;
F_3 ( V_2 , V_5 ) ;
F_4 ( V_2 , V_5 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_13 * V_5 ;
V_5 = F_2 ( V_2 , sizeof( * V_5 ) , V_14 , V_15 ) ;
if ( ! V_5 )
return - V_8 ;
V_5 -> V_16 = V_17 ;
V_5 -> V_12 = V_12 ;
F_3 ( V_2 , V_5 ) ;
F_6 ( F_7 ( V_5 -> V_16 ) ) ;
F_4 ( V_2 , V_5 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 )
{
T_1 V_18 = 0 ;
int V_19 ;
V_19 = F_9 ( V_2 , V_20 , & V_18 ) ;
if ( V_19 )
return V_19 ;
return V_18 == V_20 ? 0 : - V_21 ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_22 , T_1 * V_23 )
{
struct V_24 * V_5 ;
V_5 = F_2 ( V_2 , sizeof( * V_5 ) , V_14 ,
V_25 ) ;
if ( ! V_5 )
return - V_8 ;
V_5 -> V_22 = V_22 ;
V_5 -> V_18 = V_20 ;
F_3 ( V_2 , V_5 ) ;
* V_23 = V_5 -> V_18 ;
F_4 ( V_2 , V_5 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_26 ,
T_1 V_27 , T_1 V_28 , T_1 V_29 , T_1 V_30 ,
T_2 * V_31 , T_1 V_32 )
{
struct V_33 * V_5 ;
T_1 V_34 = 0 ;
int V_16 ;
if ( V_26 & V_35 ) {
V_34 = ( ( ( ( V_29 + 7 ) / 8 ) * V_30 + 3 ) & ~ 3 ) +
V_29 * 4 * V_30 ;
if ( V_34 > V_32 )
return - V_36 ;
V_26 |= V_37 ;
}
V_5 = F_2 ( V_2 , sizeof( * V_5 ) + V_34 , V_14 ,
V_38 ) ;
if ( ! V_5 )
return - V_8 ;
V_5 -> V_39 = V_40 ;
V_5 -> V_26 = V_26 ;
V_5 -> V_41 = V_27 ;
V_5 -> V_28 = V_28 ;
V_5 -> V_29 = V_29 ;
V_5 -> V_30 = V_30 ;
if ( V_34 )
memcpy ( V_5 -> V_42 , V_31 , V_34 ) ;
F_3 ( V_2 , V_5 ) ;
switch ( V_5 -> V_39 ) {
case V_40 :
V_16 = 0 ;
break;
case V_43 :
V_16 = - V_8 ;
break;
case V_44 :
V_16 = - V_45 ;
break;
default:
V_16 = - V_36 ;
}
F_4 ( V_2 , V_5 ) ;
return V_16 ;
}
int F_11 ( struct V_1 * V_2 , bool V_46 ,
T_1 V_47 , T_1 V_48 , T_1 * V_49 , T_1 * V_50 )
{
struct V_51 * V_5 ;
V_5 = F_2 ( V_2 , sizeof( * V_5 ) , V_14 ,
V_52 ) ;
if ( ! V_5 )
return - V_8 ;
V_5 -> V_46 = V_46 ;
V_5 -> V_47 = V_47 ;
V_5 -> V_48 = V_48 ;
F_3 ( V_2 , V_5 ) ;
* V_49 = V_5 -> V_47 ;
* V_50 = V_5 -> V_48 ;
F_4 ( V_2 , V_5 ) ;
return 0 ;
}
