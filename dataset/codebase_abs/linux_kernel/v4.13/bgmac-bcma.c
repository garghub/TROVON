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
const T_3 * V_35 = NULL ;
int V_36 ;
V_9 = F_26 ( & V_2 -> V_30 ) ;
if ( ! V_9 )
return - V_37 ;
V_9 -> V_11 . V_2 = V_2 ;
V_9 -> V_38 = V_2 -> V_38 ;
V_9 -> V_39 = V_2 -> V_39 ;
F_27 ( V_2 , V_9 ) ;
if ( V_9 -> V_30 -> V_40 )
V_35 = F_28 ( V_9 -> V_30 -> V_40 ) ;
if ( ! V_35 ) {
switch ( V_2 -> V_41 ) {
case 0 :
V_35 = V_34 -> V_42 ;
break;
case 1 :
V_35 = V_34 -> V_43 ;
break;
case 2 :
V_35 = V_34 -> V_44 ;
break;
default:
F_23 ( V_9 -> V_30 , L_2 ,
V_2 -> V_41 ) ;
V_36 = - V_45 ;
goto V_36;
}
}
F_29 ( V_9 -> V_27 -> V_46 , V_35 ) ;
if ( V_2 -> V_5 . V_5 == V_47 &&
! V_2 -> V_3 -> V_48 . V_2 ) {
F_23 ( V_9 -> V_30 , L_3 ) ;
V_36 = - V_49 ;
goto V_36;
}
V_9 -> V_11 . V_19 = V_2 -> V_3 -> V_48 . V_2 ;
switch ( V_2 -> V_41 ) {
case 0 :
V_9 -> V_26 = V_34 -> V_50 ;
break;
case 1 :
V_9 -> V_26 = V_34 -> V_51 ;
break;
case 2 :
V_9 -> V_26 = V_34 -> V_52 ;
break;
}
V_9 -> V_26 &= V_53 ;
if ( V_9 -> V_26 == V_53 ) {
F_23 ( V_9 -> V_30 , L_4 ) ;
V_36 = - V_49 ;
goto V_36;
}
F_30 ( V_9 -> V_30 , L_5 , V_9 -> V_26 ,
V_9 -> V_26 == V_54 ? L_6 : L_7 ) ;
if ( ! F_1 ( V_2 ) &&
! ( V_32 -> V_5 == V_55 && V_2 -> V_41 == 1 ) ) {
V_25 = F_31 ( V_9 ) ;
if ( F_22 ( V_25 ) ) {
V_36 = F_24 ( V_25 ) ;
goto V_36;
}
V_9 -> V_25 = V_25 ;
}
if ( V_2 -> V_3 -> V_56 == V_57 ) {
F_23 ( V_9 -> V_30 , L_8 ) ;
V_36 = - V_45 ;
goto V_58;
}
V_9 -> V_59 = ! ! ( V_34 -> V_60 & V_61 ) ;
if ( V_9 -> V_59 )
F_32 ( V_9 -> V_30 , L_9 ) ;
if ( V_34 -> V_60 & V_62 )
F_32 ( V_9 -> V_30 , L_10 ) ;
switch ( V_32 -> V_5 ) {
case V_63 :
V_9 -> V_64 |= V_65 ;
case V_66 :
V_9 -> V_64 |= V_67 ;
V_9 -> V_64 |= V_68 ;
break;
case V_69 :
case V_70 :
V_9 -> V_64 |= V_68 ;
V_9 -> V_64 |= V_65 ;
V_9 -> V_64 |= V_71 ;
V_9 -> V_64 |= V_72 ;
if ( V_32 -> V_73 == V_74 ||
V_32 -> V_73 == V_75 ) {
V_9 -> V_64 |= V_76 ;
V_9 -> V_64 |= V_77 ;
}
if ( V_32 -> V_73 == V_78 )
V_9 -> V_64 |= V_79 ;
break;
case V_55 :
V_9 -> V_64 |= V_65 ;
V_9 -> V_64 |= V_68 ;
if ( V_32 -> V_73 == V_80 )
V_9 -> V_64 |= V_77 ;
if ( V_2 -> V_41 == 0 ) {
V_9 -> V_64 |= V_81 ;
if ( V_32 -> V_73 == V_80 )
V_9 -> V_64 |=
V_82 ;
} else if ( V_2 -> V_41 == 1 ) {
V_9 -> V_64 |= V_83 ;
V_9 -> V_64 |= V_84 ;
}
break;
case V_85 :
V_9 -> V_64 |= V_68 ;
V_9 -> V_64 |= V_65 ;
V_9 -> V_64 |= V_71 ;
V_9 -> V_64 |= V_72 ;
if ( V_32 -> V_73 == 10 ) {
V_9 -> V_64 |= V_76 ;
V_9 -> V_64 |= V_77 ;
}
break;
case V_6 :
case V_7 :
case V_8 :
V_9 -> V_64 |= V_65 ;
V_9 -> V_64 |= V_86 ;
V_9 -> V_64 |= V_87 ;
break;
default:
V_9 -> V_64 |= V_65 ;
V_9 -> V_64 |= V_68 ;
}
if ( ! F_1 ( V_2 ) && V_2 -> V_5 . V_88 > 2 )
V_9 -> V_64 |= V_89 ;
if ( V_2 -> V_5 . V_5 == V_47 ) {
V_9 -> V_64 |= V_90 ;
V_9 -> V_64 |= V_91 ;
}
if ( V_2 -> V_5 . V_88 >= 4 ) {
V_9 -> V_64 |= V_92 ;
V_9 -> V_64 |= V_93 ;
V_9 -> V_64 |= V_94 ;
}
V_9 -> V_95 = F_2 ;
V_9 -> V_96 = F_4 ;
V_9 -> V_97 = F_6 ;
V_9 -> V_98 = F_8 ;
V_9 -> V_99 = F_10 ;
V_9 -> V_100 = F_12 ;
V_9 -> V_101 = F_14 ;
V_9 -> V_102 = F_16 ;
V_9 -> V_103 = F_18 ;
if ( V_9 -> V_25 )
V_9 -> F_21 = F_20 ;
else
V_9 -> F_21 = V_104 ;
V_36 = F_33 ( V_9 ) ;
if ( V_36 )
goto V_58;
return 0 ;
V_58:
F_34 ( V_9 -> V_25 ) ;
V_36:
F_27 ( V_2 , NULL ) ;
return V_36 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_36 ( V_2 ) ;
F_34 ( V_9 -> V_25 ) ;
F_37 ( V_9 ) ;
F_27 ( V_2 , NULL ) ;
F_38 ( V_9 ) ;
}
static int T_4 F_39 ( void )
{
int V_36 ;
V_36 = F_40 ( & V_105 ) ;
if ( V_36 )
return V_36 ;
F_41 ( L_11 ) ;
return 0 ;
}
static void T_5 F_42 ( void )
{
F_43 ( & V_105 ) ;
}
