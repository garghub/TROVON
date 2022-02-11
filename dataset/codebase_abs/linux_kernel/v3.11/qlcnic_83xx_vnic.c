int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 ) {
if ( F_2 ( V_2 ) )
return - V_4 ;
}
F_3 ( V_2 -> V_5 , V_6 , V_7 ) ;
if ( V_3 )
F_4 ( V_2 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , int V_3 )
{
struct V_8 * V_5 = V_2 -> V_5 ;
if ( V_3 ) {
if ( F_2 ( V_2 ) )
return - V_4 ;
}
F_3 ( V_2 -> V_5 , V_6 , V_9 ) ;
V_5 -> V_10 . V_11 = V_9 ;
if ( V_3 )
F_4 ( V_2 ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 )
{
T_1 V_12 ;
int V_13 = - V_4 ;
T_2 V_14 = V_15 ;
struct V_8 * V_5 = V_2 -> V_5 ;
if ( F_2 ( V_2 ) )
return V_13 ;
V_12 = V_5 -> V_16 ;
V_14 = F_7 ( V_2 -> V_5 , V_17 ) ;
V_14 = ( V_14 & ~ F_8 ( 0x3 , V_12 ) ) |
F_8 ( V_15 , V_12 ) ;
F_3 ( V_2 -> V_5 , V_17 , V_14 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static void
F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_5 = V_2 -> V_5 ;
if ( V_5 -> V_18 == V_19 ) {
V_2 -> V_20 = V_21 ;
V_2 -> V_22 = V_23 ;
V_2 -> V_24 = V_25 ;
V_2 -> V_26 = V_25 ;
} else if ( V_5 -> V_18 == V_27 ) {
V_2 -> V_20 = V_28 ;
V_2 -> V_24 = V_29 ;
V_2 -> V_26 = V_29 ;
V_2 -> V_22 = V_30 ;
}
V_2 -> V_31 = V_32 ;
V_2 -> V_33 = V_34 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_35 = - V_36 ;
F_11 ( V_2 ) ;
if ( ! ( V_2 -> V_37 & V_38 ) ) {
if ( F_12 ( V_2 ) )
return V_35 ;
if ( F_6 ( V_2 ) )
return V_35 ;
if ( F_13 ( V_2 ) )
return V_35 ;
} else {
if ( F_14 ( V_2 ) )
return V_35 ;
}
if ( F_15 ( V_2 ) )
return V_35 ;
F_9 ( V_2 ) ;
V_2 -> V_5 -> V_39 = ! ! V_40 ;
V_2 -> V_37 |= V_38 ;
F_1 ( V_2 , 1 ) ;
F_16 ( & V_2 -> V_41 -> V_42 , L_1 ,
V_2 -> V_5 -> V_43 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_35 = - V_36 ;
F_11 ( V_2 ) ;
if ( F_15 ( V_2 ) )
return V_35 ;
F_9 ( V_2 ) ;
V_2 -> V_5 -> V_39 = ! ! V_40 ;
V_2 -> V_37 |= V_38 ;
F_16 ( & V_2 -> V_41 -> V_42 ,
L_2 ,
V_2 -> V_5 -> V_43 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_35 = - V_36 ;
F_19 ( V_2 ) ;
if ( F_20 ( V_2 ) )
return V_35 ;
if ( F_15 ( V_2 ) )
return V_35 ;
F_9 ( V_2 ) ;
V_2 -> V_5 -> V_39 = ! ! V_40 ;
V_2 -> V_37 |= V_38 ;
F_16 ( & V_2 -> V_41 -> V_42 , L_3 ,
V_2 -> V_5 -> V_43 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
T_2 V_44 , V_45 ;
struct V_8 * V_5 = V_2 -> V_5 ;
struct V_46 * V_47 = V_2 -> V_47 ;
F_22 ( V_2 ) ;
V_44 = F_7 ( V_2 -> V_5 , V_17 ) ;
if ( V_44 == V_48 )
V_45 = V_15 ;
else
V_45 = F_23 ( V_44 ,
V_5 -> V_16 ) ;
switch ( V_45 ) {
case V_49 :
V_5 -> V_44 = V_49 ;
V_5 -> V_10 . V_50 = V_51 ;
V_47 -> V_52 = F_18 ;
break;
case V_53 :
V_5 -> V_44 = V_53 ;
V_5 -> V_10 . V_50 = V_54 ;
V_47 -> V_52 = F_17 ;
break;
case V_15 :
V_5 -> V_44 = V_15 ;
V_5 -> V_10 . V_50 = V_51 ;
V_47 -> V_52 = F_10 ;
break;
default:
F_24 ( & V_2 -> V_41 -> V_42 , L_4 ) ;
return - V_36 ;
}
if ( V_5 -> V_55 & V_56 )
V_2 -> V_37 |= V_57 ;
else
V_2 -> V_37 &= ~ V_57 ;
V_5 -> V_10 . V_11 = V_9 ;
V_5 -> V_10 . V_58 = V_59 ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_8 * V_5 = V_2 -> V_5 ;
struct V_60 * V_10 = & V_5 -> V_10 ;
T_2 V_61 ;
V_61 = F_7 ( V_5 , V_6 ) ;
while ( V_61 != V_7 && V_10 -> V_58 -- ) {
F_26 ( 1000 ) ;
V_61 = F_7 ( V_5 , V_6 ) ;
}
if ( ! V_10 -> V_58 ) {
F_24 ( & V_2 -> V_41 -> V_42 ,
L_5 ) ;
return - V_36 ;
}
return 0 ;
}
