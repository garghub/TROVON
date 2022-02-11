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
static int F_20 ( struct V_9 * V_9 )
{
struct V_20 * V_21 ;
char V_22 [ V_23 + 3 ] ;
snprintf ( V_22 , sizeof( V_22 ) , V_24 , V_9 -> V_25 -> V_5 ,
V_9 -> V_26 ) ;
V_21 = F_21 ( V_9 -> V_27 , V_22 , V_28 ,
V_29 ) ;
if ( F_22 ( V_21 ) ) {
F_23 ( V_9 -> V_30 , L_1 ) ;
return F_24 ( V_21 ) ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_3 -> V_4 ;
struct V_33 * V_34 = & V_2 -> V_3 -> V_34 ;
struct V_25 * V_25 ;
struct V_9 * V_9 ;
T_3 * V_35 ;
int V_36 ;
V_9 = F_26 ( & V_2 -> V_30 ) ;
if ( ! V_9 )
return - V_37 ;
V_9 -> V_11 . V_2 = V_2 ;
V_9 -> V_38 = V_2 -> V_38 ;
V_9 -> V_39 = V_2 -> V_39 ;
F_27 ( V_2 , V_9 ) ;
switch ( V_2 -> V_40 ) {
case 0 :
V_35 = V_34 -> V_41 ;
break;
case 1 :
V_35 = V_34 -> V_42 ;
break;
case 2 :
V_35 = V_34 -> V_43 ;
break;
default:
F_23 ( V_9 -> V_30 , L_2 ,
V_2 -> V_40 ) ;
V_36 = - V_44 ;
goto V_36;
}
F_28 ( V_9 -> V_27 -> V_45 , V_35 ) ;
if ( V_2 -> V_5 . V_5 == V_46 &&
! V_2 -> V_3 -> V_47 . V_2 ) {
F_23 ( V_9 -> V_30 , L_3 ) ;
V_36 = - V_48 ;
goto V_36;
}
V_9 -> V_11 . V_19 = V_2 -> V_3 -> V_47 . V_2 ;
switch ( V_2 -> V_40 ) {
case 0 :
V_9 -> V_26 = V_34 -> V_49 ;
break;
case 1 :
V_9 -> V_26 = V_34 -> V_50 ;
break;
case 2 :
V_9 -> V_26 = V_34 -> V_51 ;
break;
}
V_9 -> V_26 &= V_52 ;
if ( V_9 -> V_26 == V_52 ) {
F_23 ( V_9 -> V_30 , L_4 ) ;
V_36 = - V_48 ;
goto V_36;
}
F_29 ( V_9 -> V_30 , L_5 , V_9 -> V_26 ,
V_9 -> V_26 == V_53 ? L_6 : L_7 ) ;
if ( ! F_1 ( V_2 ) &&
! ( V_32 -> V_5 == V_54 && V_2 -> V_40 == 1 ) ) {
V_25 = F_30 ( V_9 ) ;
if ( F_22 ( V_25 ) ) {
V_36 = F_24 ( V_25 ) ;
goto V_36;
}
V_9 -> V_25 = V_25 ;
}
if ( V_2 -> V_3 -> V_55 == V_56 ) {
F_23 ( V_9 -> V_30 , L_8 ) ;
V_36 = - V_44 ;
goto V_57;
}
V_9 -> V_58 = ! ! ( V_2 -> V_3 -> V_34 . V_59 &
V_60 ) ;
if ( V_9 -> V_58 )
F_31 ( V_9 -> V_30 , L_9 ) ;
if ( V_2 -> V_3 -> V_34 . V_59 & V_61 )
F_31 ( V_9 -> V_30 , L_10 ) ;
switch ( V_2 -> V_3 -> V_4 . V_5 ) {
case V_62 :
V_9 -> V_63 |= V_64 ;
V_9 -> V_63 |= V_65 ;
V_9 -> V_63 |= V_66 ;
V_9 -> V_63 |= V_67 ;
if ( V_2 -> V_3 -> V_4 . V_68 == V_69 ) {
V_9 -> V_63 |= V_70 ;
V_9 -> V_63 |= V_71 ;
}
if ( V_2 -> V_3 -> V_4 . V_68 == V_72 )
V_9 -> V_63 |= V_73 ;
break;
case V_74 :
V_9 -> V_63 |= V_64 ;
V_9 -> V_63 |= V_65 ;
V_9 -> V_63 |= V_66 ;
V_9 -> V_63 |= V_67 ;
if ( V_2 -> V_3 -> V_4 . V_68 == V_75 ) {
V_9 -> V_63 |= V_71 ;
V_9 -> V_63 |= V_70 ;
}
break;
case V_76 :
V_9 -> V_63 |= V_64 ;
V_9 -> V_63 |= V_65 ;
V_9 -> V_63 |= V_66 ;
V_9 -> V_63 |= V_67 ;
if ( V_2 -> V_3 -> V_4 . V_68 == 10 ) {
V_9 -> V_63 |= V_71 ;
V_9 -> V_63 |= V_70 ;
}
break;
case V_77 :
V_9 -> V_63 |= V_65 ;
case V_78 :
V_9 -> V_63 |= V_79 ;
V_9 -> V_63 |= V_64 ;
break;
case V_6 :
case V_7 :
case V_8 :
V_9 -> V_63 |= V_65 ;
V_9 -> V_63 |= V_80 ;
V_9 -> V_63 |= V_81 ;
break;
case V_54 :
V_9 -> V_63 |= V_65 ;
V_9 -> V_63 |= V_64 ;
if ( V_32 -> V_68 == V_82 )
V_9 -> V_63 |= V_70 ;
if ( V_2 -> V_40 == 0 ) {
V_9 -> V_63 |= V_83 ;
if ( V_32 -> V_68 == V_82 )
V_9 -> V_63 |=
V_84 ;
} else if ( V_2 -> V_40 == 1 ) {
V_9 -> V_63 |= V_85 ;
V_9 -> V_63 |= V_86 ;
}
break;
default:
V_9 -> V_63 |= V_65 ;
V_9 -> V_63 |= V_64 ;
}
if ( ! F_1 ( V_2 ) && V_2 -> V_5 . V_87 > 2 )
V_9 -> V_63 |= V_88 ;
if ( V_2 -> V_5 . V_5 == V_46 ) {
V_9 -> V_63 |= V_89 ;
V_9 -> V_63 |= V_90 ;
}
if ( V_2 -> V_5 . V_87 >= 4 ) {
V_9 -> V_63 |= V_91 ;
V_9 -> V_63 |= V_92 ;
V_9 -> V_63 |= V_93 ;
}
V_9 -> V_94 = F_2 ;
V_9 -> V_95 = F_4 ;
V_9 -> V_96 = F_6 ;
V_9 -> V_97 = F_8 ;
V_9 -> V_98 = F_10 ;
V_9 -> V_99 = F_12 ;
V_9 -> V_100 = F_14 ;
V_9 -> V_101 = F_16 ;
V_9 -> V_102 = F_18 ;
if ( V_9 -> V_25 )
V_9 -> F_21 = F_20 ;
else
V_9 -> F_21 = V_103 ;
V_36 = F_32 ( V_9 ) ;
if ( V_36 )
goto V_57;
return 0 ;
V_57:
F_33 ( V_9 -> V_25 ) ;
V_36:
F_27 ( V_2 , NULL ) ;
return V_36 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_35 ( V_2 ) ;
F_33 ( V_9 -> V_25 ) ;
F_36 ( V_9 ) ;
F_27 ( V_2 , NULL ) ;
F_37 ( V_9 ) ;
}
static int T_4 F_38 ( void )
{
int V_36 ;
V_36 = F_39 ( & V_104 ) ;
if ( V_36 )
return V_36 ;
F_40 ( L_11 ) ;
return 0 ;
}
static void T_5 F_41 ( void )
{
F_42 ( & V_104 ) ;
}
