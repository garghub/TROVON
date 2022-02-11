static inline bool F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 -> V_4 . V_5 ) {
case V_6 :
case V_7 :
case V_8 :
return true ;
default:
return false ;
}
}
static T_1 F_2 ( struct V_9 * V_9 , T_2 V_10 )
{
return F_3 ( V_9 -> V_11 . V_2 , V_10 ) ;
}
static void F_4 ( struct V_9 * V_9 , T_2 V_10 , T_1 V_12 )
{
F_5 ( V_9 -> V_11 . V_2 , V_10 , V_12 ) ;
}
static T_1 F_6 ( struct V_9 * V_9 , T_2 V_10 )
{
return F_7 ( V_9 -> V_11 . V_2 , V_10 ) ;
}
static void F_8 ( struct V_9 * V_9 , T_2 V_10 , T_1 V_12 )
{
return F_9 ( V_9 -> V_11 . V_2 , V_10 , V_12 ) ;
}
static bool F_10 ( struct V_9 * V_9 )
{
return F_11 ( V_9 -> V_11 . V_2 ) ;
}
static void F_12 ( struct V_9 * V_9 , T_1 V_13 )
{
F_13 ( V_9 -> V_11 . V_2 , V_13 ) ;
}
static void F_14 ( struct V_9 * V_9 , T_1 V_10 ,
T_1 V_14 , T_1 V_15 )
{
struct V_16 * V_17 = & V_9 -> V_11 . V_2 -> V_3 -> V_18 ;
F_15 ( V_17 , V_10 , V_14 , V_15 ) ;
}
static T_1 F_16 ( struct V_9 * V_9 )
{
struct V_16 * V_17 = & V_9 -> V_11 . V_2 -> V_3 -> V_18 ;
return F_17 ( V_17 ) ;
}
static void F_18 ( struct V_9 * V_9 , T_2 V_10 , T_1 V_14 ,
T_1 V_15 )
{
F_19 ( V_9 -> V_11 . V_19 , V_10 , V_14 , V_15 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = & V_2 -> V_3 -> V_21 ;
struct V_22 * V_22 ;
struct V_9 * V_9 ;
T_3 * V_23 ;
int V_24 ;
V_9 = F_21 ( sizeof( * V_9 ) , V_25 ) ;
if ( ! V_9 )
return - V_26 ;
V_9 -> V_11 . V_2 = V_2 ;
V_9 -> V_27 = & V_2 -> V_27 ;
V_9 -> V_28 = V_2 -> V_28 ;
V_9 -> V_29 = V_2 -> V_29 ;
F_22 ( V_2 , V_9 ) ;
switch ( V_2 -> V_30 ) {
case 0 :
V_23 = V_21 -> V_31 ;
break;
case 1 :
V_23 = V_21 -> V_32 ;
break;
case 2 :
V_23 = V_21 -> V_33 ;
break;
default:
F_23 ( V_9 -> V_27 , L_1 ,
V_2 -> V_30 ) ;
V_24 = - V_34 ;
goto V_24;
}
F_24 ( V_9 -> V_35 , V_23 ) ;
if ( V_2 -> V_5 . V_5 == V_36 &&
! V_2 -> V_3 -> V_37 . V_2 ) {
F_23 ( V_9 -> V_27 , L_2 ) ;
V_24 = - V_38 ;
goto V_24;
}
V_9 -> V_11 . V_19 = V_2 -> V_3 -> V_37 . V_2 ;
switch ( V_2 -> V_30 ) {
case 0 :
V_9 -> V_39 = V_21 -> V_40 ;
break;
case 1 :
V_9 -> V_39 = V_21 -> V_41 ;
break;
case 2 :
V_9 -> V_39 = V_21 -> V_42 ;
break;
}
V_9 -> V_39 &= V_43 ;
if ( V_9 -> V_39 == V_43 ) {
F_23 ( V_9 -> V_27 , L_3 ) ;
V_24 = - V_38 ;
goto V_24;
}
F_25 ( V_9 -> V_27 , L_4 , V_9 -> V_39 ,
V_9 -> V_39 == V_44 ? L_5 : L_6 ) ;
if ( ! F_1 ( V_2 ) ) {
V_22 = F_26 ( V_2 , V_9 -> V_39 ) ;
if ( F_27 ( V_22 ) ) {
V_24 = F_28 ( V_22 ) ;
goto V_24;
}
V_9 -> V_22 = V_22 ;
}
if ( V_2 -> V_3 -> V_45 == V_46 ) {
F_23 ( V_9 -> V_27 , L_7 ) ;
V_24 = - V_34 ;
goto V_47;
}
V_9 -> V_48 = ! ! ( V_2 -> V_3 -> V_21 . V_49 &
V_50 ) ;
if ( V_9 -> V_48 )
F_29 ( V_9 -> V_27 , L_8 ) ;
if ( V_2 -> V_3 -> V_21 . V_49 & V_51 )
F_29 ( V_9 -> V_27 , L_9 ) ;
switch ( V_2 -> V_3 -> V_4 . V_5 ) {
case V_52 :
V_9 -> V_53 |= V_54 ;
V_9 -> V_53 |= V_55 ;
V_9 -> V_53 |= V_56 ;
V_9 -> V_53 |= V_57 ;
if ( V_2 -> V_3 -> V_4 . V_58 == V_59 ) {
V_9 -> V_53 |= V_60 ;
V_9 -> V_53 |= V_61 ;
}
if ( V_2 -> V_3 -> V_4 . V_58 == V_62 )
V_9 -> V_53 |= V_63 ;
break;
case V_64 :
V_9 -> V_53 |= V_54 ;
V_9 -> V_53 |= V_55 ;
V_9 -> V_53 |= V_56 ;
V_9 -> V_53 |= V_57 ;
if ( V_2 -> V_3 -> V_4 . V_58 == V_65 ) {
V_9 -> V_53 |= V_61 ;
V_9 -> V_53 |= V_60 ;
}
break;
case V_66 :
V_9 -> V_53 |= V_54 ;
V_9 -> V_53 |= V_55 ;
V_9 -> V_53 |= V_56 ;
V_9 -> V_53 |= V_57 ;
if ( V_2 -> V_3 -> V_4 . V_58 == 10 ) {
V_9 -> V_53 |= V_61 ;
V_9 -> V_53 |= V_60 ;
}
break;
case V_67 :
V_9 -> V_53 |= V_55 ;
case V_68 :
V_9 -> V_53 |= V_69 ;
V_9 -> V_53 |= V_54 ;
break;
case V_6 :
case V_7 :
case V_8 :
V_9 -> V_53 |= V_55 ;
V_9 -> V_53 |= V_70 ;
V_9 -> V_53 |= V_71 ;
break;
default:
V_9 -> V_53 |= V_55 ;
V_9 -> V_53 |= V_54 ;
}
if ( ! F_1 ( V_2 ) && V_2 -> V_5 . V_72 > 2 )
V_9 -> V_53 |= V_73 ;
if ( V_2 -> V_5 . V_5 == V_36 ) {
V_9 -> V_53 |= V_74 ;
V_9 -> V_53 |= V_75 ;
}
if ( V_2 -> V_5 . V_72 >= 4 ) {
V_9 -> V_53 |= V_76 ;
V_9 -> V_53 |= V_77 ;
V_9 -> V_53 |= V_78 ;
}
V_9 -> V_79 = F_2 ;
V_9 -> V_80 = F_4 ;
V_9 -> V_81 = F_6 ;
V_9 -> V_82 = F_8 ;
V_9 -> V_83 = F_10 ;
V_9 -> V_84 = F_12 ;
V_9 -> V_85 = F_14 ;
V_9 -> V_86 = F_16 ;
V_9 -> V_87 = F_18 ;
V_24 = F_30 ( V_9 ) ;
if ( V_24 )
goto V_47;
return 0 ;
V_47:
F_31 ( V_9 -> V_22 ) ;
V_24:
F_32 ( V_9 ) ;
F_22 ( V_2 , NULL ) ;
return V_24 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_34 ( V_2 ) ;
F_31 ( V_9 -> V_22 ) ;
F_35 ( V_9 ) ;
F_22 ( V_2 , NULL ) ;
F_32 ( V_9 ) ;
}
static int T_4 F_36 ( void )
{
int V_24 ;
V_24 = F_37 ( & V_88 ) ;
if ( V_24 )
return V_24 ;
F_38 ( L_10 ) ;
return 0 ;
}
static void T_5 F_39 ( void )
{
F_40 ( & V_88 ) ;
}
