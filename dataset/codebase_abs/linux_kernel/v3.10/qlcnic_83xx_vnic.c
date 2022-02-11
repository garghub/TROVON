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
static int F_6 ( struct V_1 * V_2 )
{
T_1 V_12 ;
int V_13 , V_14 = - V_4 ;
T_2 V_15 = V_16 ;
struct V_8 * V_5 = V_2 -> V_5 ;
if ( F_2 ( V_2 ) )
return V_14 ;
if ( V_17 ) {
for ( V_13 = 0 ; V_13 < V_5 -> V_18 ; V_13 ++ ) {
V_12 = V_2 -> V_19 [ V_13 ] . V_20 ;
if ( V_12 == V_5 -> V_20 )
continue;
V_15 |= V_17 &
F_7 ( 0x3 , V_12 ) ;
}
} else {
V_15 = F_8 ( V_2 -> V_5 , V_21 ) ;
V_15 = ( V_15 & ~ F_7 ( 0x3 , V_5 -> V_20 ) ) |
F_7 ( V_16 ,
V_5 -> V_20 ) ;
}
F_3 ( V_2 -> V_5 , V_21 , V_15 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static void
F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_5 = V_2 -> V_5 ;
if ( V_5 -> V_22 == V_23 ) {
V_2 -> V_24 = V_25 ;
V_2 -> V_26 = V_27 ;
V_2 -> V_28 = V_29 ;
V_2 -> V_30 = V_29 ;
} else if ( V_5 -> V_22 == V_31 ) {
V_2 -> V_24 = V_32 ;
V_2 -> V_28 = V_33 ;
V_2 -> V_30 = V_33 ;
V_2 -> V_26 = V_34 ;
}
V_2 -> V_35 = V_36 ;
V_2 -> V_37 = V_38 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_39 = - V_40 ;
F_11 ( V_2 ) ;
if ( ! ( V_2 -> V_41 & V_42 ) ) {
if ( F_12 ( V_2 ) )
return V_39 ;
if ( F_6 ( V_2 ) )
return V_39 ;
if ( F_13 ( V_2 ) )
return V_39 ;
} else {
if ( F_14 ( V_2 ) )
return V_39 ;
}
if ( F_15 ( V_2 ) )
return V_39 ;
F_9 ( V_2 ) ;
V_2 -> V_5 -> V_43 = ! ! V_44 ;
V_2 -> V_41 |= V_42 ;
F_1 ( V_2 , 1 ) ;
F_16 ( & V_2 -> V_45 -> V_46 , L_1 ,
V_2 -> V_5 -> V_47 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_39 = - V_40 ;
F_11 ( V_2 ) ;
if ( F_15 ( V_2 ) )
return V_39 ;
F_9 ( V_2 ) ;
V_2 -> V_5 -> V_43 = ! ! V_44 ;
V_2 -> V_41 |= V_42 ;
F_16 ( & V_2 -> V_45 -> V_46 ,
L_2 ,
V_2 -> V_5 -> V_47 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_39 = - V_40 ;
F_19 ( V_2 ) ;
if ( F_20 ( V_2 ) )
return V_39 ;
if ( F_15 ( V_2 ) )
return V_39 ;
F_9 ( V_2 ) ;
V_2 -> V_5 -> V_43 = ! ! V_44 ;
V_2 -> V_41 |= V_42 ;
F_16 ( & V_2 -> V_45 -> V_46 , L_3 ,
V_2 -> V_5 -> V_47 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
T_2 V_48 , V_49 ;
struct V_8 * V_5 = V_2 -> V_5 ;
struct V_50 * V_51 = V_2 -> V_51 ;
F_22 ( V_2 ) ;
V_48 = F_8 ( V_2 -> V_5 , V_21 ) ;
if ( V_48 == V_52 )
V_49 = V_16 ;
else
V_49 = F_23 ( V_48 ,
V_5 -> V_20 ) ;
if ( V_49 == V_53 ) {
V_5 -> V_48 = V_53 ;
V_5 -> V_10 . V_54 = V_55 ;
V_51 -> V_56 = F_18 ;
} else if ( V_49 == V_57 ) {
V_5 -> V_48 = V_57 ;
V_5 -> V_10 . V_54 = V_58 ;
V_51 -> V_56 = F_17 ;
} else if ( V_49 == V_16 ) {
V_5 -> V_48 = V_16 ;
V_5 -> V_10 . V_54 = V_55 ;
V_51 -> V_56 = F_10 ;
} else {
return - V_40 ;
}
if ( V_5 -> V_59 & V_60 )
V_2 -> V_41 |= V_61 ;
else
V_2 -> V_41 &= ~ V_61 ;
V_2 -> V_5 -> V_10 . V_11 = V_9 ;
V_2 -> V_5 -> V_10 . V_62 = V_63 ;
return 0 ;
}
