static T_1 F_1 ( struct V_1 * V_1 , T_2 V_2 )
{
return F_2 ( V_1 -> V_3 . V_4 + V_2 ) ;
}
static void F_3 ( struct V_1 * V_1 , T_2 V_2 , T_1 V_5 )
{
F_4 ( V_5 , V_1 -> V_3 . V_4 + V_2 ) ;
}
static T_1 F_5 ( struct V_1 * V_1 , T_2 V_2 )
{
return F_2 ( V_1 -> V_3 . V_6 + V_2 ) ;
}
static void F_6 ( struct V_1 * V_1 , T_2 V_2 , T_1 V_5 )
{
return F_4 ( V_5 , V_1 -> V_3 . V_6 + V_2 ) ;
}
static bool F_7 ( struct V_1 * V_1 )
{
if ( ( F_8 ( V_1 , V_7 ) & V_8 ) != V_8 )
return false ;
if ( F_8 ( V_1 , V_9 ) & V_10 )
return false ;
return true ;
}
static void F_9 ( struct V_1 * V_1 , T_1 V_11 )
{
T_1 V_12 ;
V_12 = F_8 ( V_1 , V_9 ) ;
if ( V_12 ) {
F_10 ( V_1 , V_9 , 0 ) ;
F_8 ( V_1 , V_9 ) ;
F_11 ( 1 ) ;
}
V_12 = F_8 ( V_1 , V_7 ) ;
V_12 |= V_11 & ~ ( V_13 | V_14 | V_15 |
V_16 ) ;
V_12 |= V_8 ;
F_10 ( V_1 , V_7 , V_12 ) ;
F_8 ( V_1 , V_7 ) ;
F_11 ( 1 ) ;
}
static void F_12 ( struct V_1 * V_1 , T_1 V_2 ,
T_1 V_17 , T_1 V_18 )
{
F_13 ( 1 ) ;
}
static T_1 F_14 ( struct V_1 * V_1 )
{
F_13 ( 1 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_1 , T_2 V_2 ,
T_1 V_17 , T_1 V_18 )
{
F_13 ( 1 ) ;
}
static void F_16 ( struct V_19 * V_20 )
{
struct V_1 * V_1 = F_17 ( V_20 ) ;
T_1 V_12 ;
if ( ! V_1 -> V_3 . V_21 )
return;
V_12 = V_22 ;
switch ( V_1 -> V_20 -> V_23 -> V_24 ) {
default:
F_18 ( V_20 , L_1 ) ;
case V_25 :
V_12 |= V_26 << V_27 ;
break;
case V_28 :
V_12 |= V_29 << V_27 ;
break;
case V_30 :
V_12 |= V_31 << V_27 ;
break;
}
F_4 ( V_12 , V_1 -> V_3 . V_21 + V_32 ) ;
F_19 ( V_1 -> V_20 ) ;
}
static int F_20 ( struct V_1 * V_1 )
{
struct V_33 * V_34 ;
if ( V_1 -> V_3 . V_21 )
V_34 = F_21 ( V_1 -> V_20 ,
V_1 -> V_35 -> V_36 ,
F_16 ) ;
else
V_34 = F_21 ( V_1 -> V_20 ,
V_1 -> V_35 -> V_36 ,
F_19 ) ;
if ( ! V_34 ) {
F_22 ( V_1 -> V_35 , L_2 ) ;
return - V_37 ;
}
return 0 ;
}
static int F_23 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = V_39 -> V_35 . V_36 ;
struct V_1 * V_1 ;
struct V_42 * V_43 ;
const T_3 * V_44 ;
V_1 = F_24 ( & V_39 -> V_35 ) ;
if ( ! V_1 )
return - V_45 ;
F_25 ( V_39 , V_1 ) ;
V_1 -> V_46 |= V_47 ;
V_1 -> V_46 |= V_48 ;
V_1 -> V_46 |= V_49 ;
V_1 -> V_46 |= V_50 ;
V_1 -> V_46 |= V_51 ;
V_1 -> V_35 = & V_39 -> V_35 ;
V_1 -> V_52 = & V_39 -> V_35 ;
V_44 = F_26 ( V_41 ) ;
if ( V_44 )
F_27 ( V_1 -> V_20 -> V_53 , V_44 ) ;
else
F_28 ( & V_39 -> V_35 , L_3 ) ;
V_1 -> V_54 = F_29 ( V_39 , 0 ) ;
if ( V_1 -> V_54 < 0 ) {
F_22 ( & V_39 -> V_35 , L_4 ) ;
return V_1 -> V_54 ;
}
V_43 = F_30 ( V_39 , V_55 , L_5 ) ;
if ( ! V_43 ) {
F_22 ( & V_39 -> V_35 , L_6 ) ;
return - V_56 ;
}
V_1 -> V_3 . V_4 = F_31 ( & V_39 -> V_35 , V_43 ) ;
if ( F_32 ( V_1 -> V_3 . V_4 ) )
return F_33 ( V_1 -> V_3 . V_4 ) ;
V_43 = F_30 ( V_39 , V_55 , L_7 ) ;
if ( ! V_43 ) {
F_22 ( & V_39 -> V_35 , L_8 ) ;
return - V_56 ;
}
V_1 -> V_3 . V_6 = F_31 ( & V_39 -> V_35 , V_43 ) ;
if ( F_32 ( V_1 -> V_3 . V_6 ) )
return F_33 ( V_1 -> V_3 . V_6 ) ;
V_43 = F_30 ( V_39 , V_55 , L_9 ) ;
if ( V_43 ) {
V_1 -> V_3 . V_21 = F_31 ( & V_39 -> V_35 ,
V_43 ) ;
if ( F_32 ( V_1 -> V_3 . V_21 ) )
return F_33 ( V_1 -> V_3 . V_21 ) ;
}
V_1 -> V_57 = F_1 ;
V_1 -> V_58 = F_3 ;
V_1 -> V_59 = F_5 ;
V_1 -> V_60 = F_6 ;
V_1 -> V_61 = F_7 ;
V_1 -> V_62 = F_9 ;
V_1 -> V_63 = F_12 ;
V_1 -> V_64 = F_14 ;
V_1 -> V_65 = F_15 ;
if ( F_34 ( V_41 , L_10 , 0 ) ) {
V_1 -> V_66 = F_20 ;
} else {
V_1 -> V_66 = V_67 ;
V_1 -> V_46 |= V_68 ;
}
return F_35 ( V_1 ) ;
}
static int F_36 ( struct V_38 * V_39 )
{
struct V_1 * V_1 = F_37 ( V_39 ) ;
F_38 ( V_1 ) ;
return 0 ;
}
