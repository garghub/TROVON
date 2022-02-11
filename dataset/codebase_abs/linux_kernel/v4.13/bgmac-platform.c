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
F_4 ( V_5 , V_1 -> V_3 . V_6 + V_2 ) ;
}
static bool F_7 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_3 . V_6 )
return true ;
if ( ( F_8 ( V_1 , V_7 ) & V_8 ) != V_8 )
return false ;
if ( F_8 ( V_1 , V_9 ) & V_10 )
return false ;
return true ;
}
static void F_9 ( struct V_1 * V_1 , T_1 V_11 )
{
T_1 V_12 ;
if ( ! V_1 -> V_3 . V_6 )
return;
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
F_4 ( V_22 ,
V_1 -> V_3 . V_21 + V_23 ) ;
V_12 = V_24 ;
switch ( V_1 -> V_20 -> V_25 -> V_26 ) {
default:
F_18 ( V_20 , L_1 ) ;
case V_27 :
V_12 |= V_28 << V_29 ;
break;
case V_30 :
V_12 |= V_31 << V_29 ;
break;
case V_32 :
V_12 |= V_33 << V_29 ;
break;
}
F_4 ( V_12 , V_1 -> V_3 . V_21 + V_34 ) ;
F_19 ( V_1 -> V_20 ) ;
}
static int F_20 ( struct V_1 * V_1 )
{
struct V_35 * V_36 ;
if ( V_1 -> V_3 . V_21 )
V_36 = F_21 ( V_1 -> V_20 ,
V_1 -> V_37 -> V_38 ,
F_16 ) ;
else
V_36 = F_21 ( V_1 -> V_20 ,
V_1 -> V_37 -> V_38 ,
F_19 ) ;
if ( ! V_36 ) {
F_22 ( V_1 -> V_37 , L_2 ) ;
return - V_39 ;
}
return 0 ;
}
static int F_23 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_37 . V_38 ;
struct V_1 * V_1 ;
struct V_44 * V_45 ;
const T_3 * V_46 ;
V_1 = F_24 ( & V_41 -> V_37 ) ;
if ( ! V_1 )
return - V_47 ;
F_25 ( V_41 , V_1 ) ;
V_1 -> V_48 |= V_49 ;
V_1 -> V_48 |= V_50 ;
V_1 -> V_48 |= V_51 ;
V_1 -> V_48 |= V_52 ;
V_1 -> V_48 |= V_53 ;
V_1 -> V_48 |= V_54 ;
V_1 -> V_37 = & V_41 -> V_37 ;
V_1 -> V_55 = & V_41 -> V_37 ;
V_46 = F_26 ( V_43 ) ;
if ( V_46 )
F_27 ( V_1 -> V_20 -> V_56 , V_46 ) ;
else
F_28 ( & V_41 -> V_37 , L_3 ) ;
V_1 -> V_57 = F_29 ( V_41 , 0 ) ;
if ( V_1 -> V_57 < 0 ) {
F_22 ( & V_41 -> V_37 , L_4 ) ;
return V_1 -> V_57 ;
}
V_45 = F_30 ( V_41 , V_58 , L_5 ) ;
if ( ! V_45 ) {
F_22 ( & V_41 -> V_37 , L_6 ) ;
return - V_59 ;
}
V_1 -> V_3 . V_4 = F_31 ( & V_41 -> V_37 , V_45 ) ;
if ( F_32 ( V_1 -> V_3 . V_4 ) )
return F_33 ( V_1 -> V_3 . V_4 ) ;
V_45 = F_30 ( V_41 , V_58 , L_7 ) ;
if ( V_45 ) {
V_1 -> V_3 . V_6 = F_31 ( & V_41 -> V_37 , V_45 ) ;
if ( F_32 ( V_1 -> V_3 . V_6 ) )
return F_33 ( V_1 -> V_3 . V_6 ) ;
V_1 -> V_48 &= ~ V_54 ;
}
V_45 = F_30 ( V_41 , V_58 , L_8 ) ;
if ( V_45 ) {
V_1 -> V_3 . V_21 = F_31 ( & V_41 -> V_37 ,
V_45 ) ;
if ( F_32 ( V_1 -> V_3 . V_21 ) )
return F_33 ( V_1 -> V_3 . V_21 ) ;
}
V_1 -> V_60 = F_1 ;
V_1 -> V_61 = F_3 ;
V_1 -> V_62 = F_5 ;
V_1 -> V_63 = F_6 ;
V_1 -> V_64 = F_7 ;
V_1 -> V_65 = F_9 ;
V_1 -> V_66 = F_12 ;
V_1 -> V_67 = F_14 ;
V_1 -> V_68 = F_15 ;
if ( F_34 ( V_43 , L_9 , 0 ) ) {
V_1 -> V_69 = F_20 ;
} else {
V_1 -> V_69 = V_70 ;
V_1 -> V_48 |= V_71 ;
}
return F_35 ( V_1 ) ;
}
static int F_36 ( struct V_40 * V_41 )
{
struct V_1 * V_1 = F_37 ( V_41 ) ;
F_38 ( V_1 ) ;
return 0 ;
}
static int F_39 ( struct V_72 * V_37 )
{
struct V_1 * V_1 = F_40 ( V_37 ) ;
return F_41 ( V_1 ) ;
}
static int F_42 ( struct V_72 * V_37 )
{
struct V_1 * V_1 = F_40 ( V_37 ) ;
return F_43 ( V_1 ) ;
}
