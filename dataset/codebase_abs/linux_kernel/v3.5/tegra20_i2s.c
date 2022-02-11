static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_2 -> V_5 , V_3 , V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
F_4 ( V_2 -> V_5 , V_3 , & V_4 ) ;
return V_4 ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
F_7 ( V_2 -> V_8 ) ;
return 0 ;
}
static int F_8 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
int V_9 ;
V_9 = F_9 ( V_2 -> V_8 ) ;
if ( V_9 ) {
F_10 ( V_7 , L_1 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
static int F_11 ( struct V_10 * V_11 ,
unsigned int V_12 )
{
struct V_1 * V_2 = F_12 ( V_11 ) ;
switch ( V_12 & V_13 ) {
case V_14 :
break;
default:
return - V_15 ;
}
V_2 -> V_16 &= ~ V_17 ;
switch ( V_12 & V_18 ) {
case V_19 :
V_2 -> V_16 |= V_17 ;
break;
case V_20 :
break;
default:
return - V_15 ;
}
V_2 -> V_16 &= ~ ( V_21 |
V_22 ) ;
switch ( V_12 & V_23 ) {
case V_24 :
V_2 -> V_16 |= V_25 ;
V_2 -> V_16 |= V_26 ;
break;
case V_27 :
V_2 -> V_16 |= V_25 ;
V_2 -> V_16 |= V_28 ;
break;
case V_29 :
V_2 -> V_16 |= V_30 ;
V_2 -> V_16 |= V_26 ;
break;
case V_31 :
V_2 -> V_16 |= V_32 ;
V_2 -> V_16 |= V_26 ;
break;
case V_33 :
V_2 -> V_16 |= V_34 ;
V_2 -> V_16 |= V_26 ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_13 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
struct V_10 * V_11 )
{
struct V_6 * V_7 = V_36 -> V_39 -> V_40 -> V_7 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
T_1 V_3 ;
int V_9 , V_41 , V_42 , V_43 , V_44 ;
V_2 -> V_16 &= ~ V_45 ;
switch ( F_14 ( V_38 ) ) {
case V_46 :
V_2 -> V_16 |= V_47 ;
V_41 = 16 ;
break;
case V_48 :
V_2 -> V_16 |= V_49 ;
V_41 = 24 ;
break;
case V_50 :
V_2 -> V_16 |= V_51 ;
V_41 = 32 ;
break;
default:
return - V_15 ;
}
V_42 = F_15 ( V_38 ) ;
V_43 = V_42 * F_16 ( V_38 ) * V_41 * 2 ;
V_9 = F_17 ( V_2 -> V_8 , V_43 ) ;
if ( V_9 ) {
F_10 ( V_7 , L_2 , V_9 ) ;
return V_9 ;
}
V_44 = ( V_43 / ( 2 * V_42 ) ) - 1 ;
if ( V_44 < 0 || V_44 > V_52 )
return - V_15 ;
V_3 = V_44 << V_53 ;
if ( V_43 % ( 2 * V_42 ) )
V_3 |= V_54 ;
F_1 ( V_2 , V_55 , V_3 ) ;
F_1 ( V_2 , V_56 ,
V_57 |
V_58 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
V_2 -> V_16 |= V_59 ;
F_1 ( V_2 , V_60 , V_2 -> V_16 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
V_2 -> V_16 &= ~ V_59 ;
F_1 ( V_2 , V_60 , V_2 -> V_16 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
V_2 -> V_16 |= V_61 ;
F_1 ( V_2 , V_60 , V_2 -> V_16 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
V_2 -> V_16 &= ~ V_61 ;
F_1 ( V_2 , V_60 , V_2 -> V_16 ) ;
}
static int F_22 ( struct V_35 * V_36 , int V_62 ,
struct V_10 * V_11 )
{
struct V_1 * V_2 = F_12 ( V_11 ) ;
switch ( V_62 ) {
case V_63 :
case V_64 :
case V_65 :
if ( V_36 -> V_66 == V_67 )
F_18 ( V_2 ) ;
else
F_20 ( V_2 ) ;
break;
case V_68 :
case V_69 :
case V_70 :
if ( V_36 -> V_66 == V_67 )
F_19 ( V_2 ) ;
else
F_21 ( V_2 ) ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_23 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_12 ( V_11 ) ;
V_11 -> V_71 = & V_2 -> V_71 ;
V_11 -> V_72 = & V_2 -> V_72 ;
return 0 ;
}
static bool F_24 ( struct V_6 * V_7 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_60 :
case V_73 :
case V_55 :
case V_56 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
return true ;
default:
return false ;
} ;
}
static bool F_25 ( struct V_6 * V_7 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_73 :
case V_56 :
case V_78 :
case V_79 :
return true ;
default:
return false ;
} ;
}
static bool F_26 ( struct V_6 * V_7 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_78 :
case V_79 :
return true ;
default:
return false ;
} ;
}
static T_2 int F_27 ( struct V_80 * V_81 )
{
struct V_1 * V_2 ;
struct V_82 * V_83 , * V_84 , * V_85 ;
T_1 V_86 [ 2 ] ;
T_1 V_87 ;
void T_3 * V_88 ;
int V_9 ;
V_2 = F_28 ( & V_81 -> V_7 , sizeof( struct V_1 ) , V_89 ) ;
if ( ! V_2 ) {
F_10 ( & V_81 -> V_7 , L_3 ) ;
V_9 = - V_90 ;
goto V_91;
}
F_29 ( & V_81 -> V_7 , V_2 ) ;
V_2 -> V_11 = V_92 ;
V_2 -> V_11 . V_93 = F_30 ( & V_81 -> V_7 ) ;
V_2 -> V_8 = F_31 ( & V_81 -> V_7 , NULL ) ;
if ( F_32 ( V_2 -> V_8 ) ) {
F_10 ( & V_81 -> V_7 , L_4 ) ;
V_9 = F_33 ( V_2 -> V_8 ) ;
goto V_91;
}
V_83 = F_34 ( V_81 , V_94 , 0 ) ;
if ( ! V_83 ) {
F_10 ( & V_81 -> V_7 , L_5 ) ;
V_9 = - V_95 ;
goto V_96;
}
V_85 = F_34 ( V_81 , V_97 , 0 ) ;
if ( ! V_85 ) {
if ( F_35 ( V_81 -> V_7 . V_98 ,
L_6 ,
V_86 , 2 ) < 0 ) {
F_10 ( & V_81 -> V_7 , L_7 ) ;
V_9 = - V_95 ;
goto V_96;
}
V_87 = V_86 [ 1 ] ;
} else {
V_87 = V_85 -> V_99 ;
}
V_84 = F_36 ( & V_81 -> V_7 , V_83 -> V_99 ,
F_37 ( V_83 ) , V_100 ) ;
if ( ! V_84 ) {
F_10 ( & V_81 -> V_7 , L_8 ) ;
V_9 = - V_101 ;
goto V_96;
}
V_88 = F_38 ( & V_81 -> V_7 , V_83 -> V_99 , F_37 ( V_83 ) ) ;
if ( ! V_88 ) {
F_10 ( & V_81 -> V_7 , L_9 ) ;
V_9 = - V_90 ;
goto V_96;
}
V_2 -> V_5 = F_39 ( & V_81 -> V_7 , V_88 ,
& V_102 ) ;
if ( F_32 ( V_2 -> V_5 ) ) {
F_10 ( & V_81 -> V_7 , L_10 ) ;
V_9 = F_33 ( V_2 -> V_5 ) ;
goto V_96;
}
V_2 -> V_71 . V_103 = V_83 -> V_99 + V_79 ;
V_2 -> V_71 . V_104 = 4 ;
V_2 -> V_71 . V_105 = 32 ;
V_2 -> V_71 . V_106 = V_87 ;
V_2 -> V_72 . V_103 = V_83 -> V_99 + V_78 ;
V_2 -> V_72 . V_104 = 4 ;
V_2 -> V_72 . V_105 = 32 ;
V_2 -> V_72 . V_106 = V_87 ;
V_2 -> V_16 = V_107 ;
F_40 ( & V_81 -> V_7 ) ;
if ( ! F_41 ( & V_81 -> V_7 ) ) {
V_9 = F_8 ( & V_81 -> V_7 ) ;
if ( V_9 )
goto V_108;
}
V_9 = F_42 ( & V_81 -> V_7 , & V_2 -> V_11 ) ;
if ( V_9 ) {
F_10 ( & V_81 -> V_7 , L_11 , V_9 ) ;
V_9 = - V_90 ;
goto V_109;
}
V_9 = F_43 ( & V_81 -> V_7 ) ;
if ( V_9 ) {
F_10 ( & V_81 -> V_7 , L_12 , V_9 ) ;
goto V_110;
}
return 0 ;
V_110:
F_44 ( & V_81 -> V_7 ) ;
V_109:
if ( ! F_45 ( & V_81 -> V_7 ) )
F_5 ( & V_81 -> V_7 ) ;
V_108:
F_46 ( & V_81 -> V_7 ) ;
V_96:
F_47 ( V_2 -> V_8 ) ;
V_91:
return V_9 ;
}
static int T_4 F_48 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_6 ( & V_81 -> V_7 ) ;
F_46 ( & V_81 -> V_7 ) ;
if ( ! F_45 ( & V_81 -> V_7 ) )
F_5 ( & V_81 -> V_7 ) ;
F_49 ( & V_81 -> V_7 ) ;
F_44 ( & V_81 -> V_7 ) ;
F_47 ( V_2 -> V_8 ) ;
return 0 ;
}
