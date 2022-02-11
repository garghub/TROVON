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
struct V_20 * V_21 = & V_2 -> V_3 -> V_4 ;
struct V_22 * V_23 = & V_2 -> V_3 -> V_23 ;
struct V_24 * V_24 ;
struct V_9 * V_9 ;
T_3 * V_25 ;
int V_26 ;
V_9 = F_21 ( sizeof( * V_9 ) , V_27 ) ;
if ( ! V_9 )
return - V_28 ;
V_9 -> V_11 . V_2 = V_2 ;
V_9 -> V_29 = & V_2 -> V_29 ;
V_9 -> V_30 = V_2 -> V_30 ;
V_9 -> V_31 = V_2 -> V_31 ;
F_22 ( V_2 , V_9 ) ;
switch ( V_2 -> V_32 ) {
case 0 :
V_25 = V_23 -> V_33 ;
break;
case 1 :
V_25 = V_23 -> V_34 ;
break;
case 2 :
V_25 = V_23 -> V_35 ;
break;
default:
F_23 ( V_9 -> V_29 , L_1 ,
V_2 -> V_32 ) ;
V_26 = - V_36 ;
goto V_26;
}
F_24 ( V_9 -> V_37 , V_25 ) ;
if ( V_2 -> V_5 . V_5 == V_38 &&
! V_2 -> V_3 -> V_39 . V_2 ) {
F_23 ( V_9 -> V_29 , L_2 ) ;
V_26 = - V_40 ;
goto V_26;
}
V_9 -> V_11 . V_19 = V_2 -> V_3 -> V_39 . V_2 ;
switch ( V_2 -> V_32 ) {
case 0 :
V_9 -> V_41 = V_23 -> V_42 ;
break;
case 1 :
V_9 -> V_41 = V_23 -> V_43 ;
break;
case 2 :
V_9 -> V_41 = V_23 -> V_44 ;
break;
}
V_9 -> V_41 &= V_45 ;
if ( V_9 -> V_41 == V_45 ) {
F_23 ( V_9 -> V_29 , L_3 ) ;
V_26 = - V_40 ;
goto V_26;
}
F_25 ( V_9 -> V_29 , L_4 , V_9 -> V_41 ,
V_9 -> V_41 == V_46 ? L_5 : L_6 ) ;
if ( ! F_1 ( V_2 ) &&
! ( V_21 -> V_5 == V_47 && V_2 -> V_32 == 1 ) ) {
V_24 = F_26 ( V_2 , V_9 -> V_41 ) ;
if ( F_27 ( V_24 ) ) {
V_26 = F_28 ( V_24 ) ;
goto V_26;
}
V_9 -> V_24 = V_24 ;
}
if ( V_2 -> V_3 -> V_48 == V_49 ) {
F_23 ( V_9 -> V_29 , L_7 ) ;
V_26 = - V_36 ;
goto V_50;
}
V_9 -> V_51 = ! ! ( V_2 -> V_3 -> V_23 . V_52 &
V_53 ) ;
if ( V_9 -> V_51 )
F_29 ( V_9 -> V_29 , L_8 ) ;
if ( V_2 -> V_3 -> V_23 . V_52 & V_54 )
F_29 ( V_9 -> V_29 , L_9 ) ;
switch ( V_2 -> V_3 -> V_4 . V_5 ) {
case V_55 :
V_9 -> V_56 |= V_57 ;
V_9 -> V_56 |= V_58 ;
V_9 -> V_56 |= V_59 ;
V_9 -> V_56 |= V_60 ;
if ( V_2 -> V_3 -> V_4 . V_61 == V_62 ) {
V_9 -> V_56 |= V_63 ;
V_9 -> V_56 |= V_64 ;
}
if ( V_2 -> V_3 -> V_4 . V_61 == V_65 )
V_9 -> V_56 |= V_66 ;
break;
case V_67 :
V_9 -> V_56 |= V_57 ;
V_9 -> V_56 |= V_58 ;
V_9 -> V_56 |= V_59 ;
V_9 -> V_56 |= V_60 ;
if ( V_2 -> V_3 -> V_4 . V_61 == V_68 ) {
V_9 -> V_56 |= V_64 ;
V_9 -> V_56 |= V_63 ;
}
break;
case V_69 :
V_9 -> V_56 |= V_57 ;
V_9 -> V_56 |= V_58 ;
V_9 -> V_56 |= V_59 ;
V_9 -> V_56 |= V_60 ;
if ( V_2 -> V_3 -> V_4 . V_61 == 10 ) {
V_9 -> V_56 |= V_64 ;
V_9 -> V_56 |= V_63 ;
}
break;
case V_70 :
V_9 -> V_56 |= V_58 ;
case V_71 :
V_9 -> V_56 |= V_72 ;
V_9 -> V_56 |= V_57 ;
break;
case V_6 :
case V_7 :
case V_8 :
V_9 -> V_56 |= V_58 ;
V_9 -> V_56 |= V_73 ;
V_9 -> V_56 |= V_74 ;
break;
case V_47 :
V_9 -> V_56 |= V_58 ;
V_9 -> V_56 |= V_57 ;
if ( V_21 -> V_61 == V_75 )
V_9 -> V_56 |= V_63 ;
if ( V_2 -> V_32 == 0 ) {
V_9 -> V_56 |= V_76 ;
if ( V_21 -> V_61 == V_75 )
V_9 -> V_56 |=
V_77 ;
} else if ( V_2 -> V_32 == 1 ) {
V_9 -> V_56 |= V_78 ;
V_9 -> V_56 |= V_79 ;
}
break;
default:
V_9 -> V_56 |= V_58 ;
V_9 -> V_56 |= V_57 ;
}
if ( ! F_1 ( V_2 ) && V_2 -> V_5 . V_80 > 2 )
V_9 -> V_56 |= V_81 ;
if ( V_2 -> V_5 . V_5 == V_38 ) {
V_9 -> V_56 |= V_82 ;
V_9 -> V_56 |= V_83 ;
}
if ( V_2 -> V_5 . V_80 >= 4 ) {
V_9 -> V_56 |= V_84 ;
V_9 -> V_56 |= V_85 ;
V_9 -> V_56 |= V_86 ;
}
V_9 -> V_87 = F_2 ;
V_9 -> V_88 = F_4 ;
V_9 -> V_89 = F_6 ;
V_9 -> V_90 = F_8 ;
V_9 -> V_91 = F_10 ;
V_9 -> V_92 = F_12 ;
V_9 -> V_93 = F_14 ;
V_9 -> V_94 = F_16 ;
V_9 -> V_95 = F_18 ;
V_26 = F_30 ( V_9 ) ;
if ( V_26 )
goto V_50;
return 0 ;
V_50:
F_31 ( V_9 -> V_24 ) ;
V_26:
F_32 ( V_9 ) ;
F_22 ( V_2 , NULL ) ;
return V_26 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_34 ( V_2 ) ;
F_31 ( V_9 -> V_24 ) ;
F_35 ( V_9 ) ;
F_22 ( V_2 , NULL ) ;
F_32 ( V_9 ) ;
}
static int T_4 F_36 ( void )
{
int V_26 ;
V_26 = F_37 ( & V_96 ) ;
if ( V_26 )
return V_26 ;
F_38 ( L_10 ) ;
return 0 ;
}
static void T_5 F_39 ( void )
{
F_40 ( & V_96 ) ;
}
