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
F_7 ( V_2 -> V_5 , true ) ;
F_8 ( V_2 -> V_8 ) ;
return 0 ;
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
int V_9 ;
V_9 = F_10 ( V_2 -> V_8 ) ;
if ( V_9 ) {
F_11 ( V_7 , L_1 , V_9 ) ;
return V_9 ;
}
F_7 ( V_2 -> V_5 , false ) ;
return 0 ;
}
int F_12 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_1 * V_2 = F_13 ( V_13 ) ;
int V_9 ;
if ( V_11 -> V_14 == V_15 ) {
V_9 = F_14 ( & V_2 -> V_16 ,
& V_2 -> V_17 . V_18 ,
& V_2 -> V_17 . V_19 ) ;
V_2 -> V_17 . V_20 = 4 ;
V_2 -> V_17 . V_21 = 32 ;
F_15 ( V_2 -> V_22 ,
V_2 -> V_16 ) ;
} else {
V_9 = F_16 ( & V_2 -> V_23 ,
& V_2 -> V_24 . V_18 ,
& V_2 -> V_24 . V_19 ) ;
V_2 -> V_24 . V_20 = 4 ;
V_2 -> V_24 . V_21 = 32 ;
F_15 ( V_2 -> V_23 ,
V_2 -> V_25 ) ;
}
return V_9 ;
}
void F_17 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_1 * V_2 = F_13 ( V_13 ) ;
if ( V_11 -> V_14 == V_15 ) {
F_18 ( V_2 -> V_22 ) ;
F_19 ( V_2 -> V_16 ) ;
} else {
F_18 ( V_2 -> V_23 ) ;
F_20 ( V_2 -> V_23 ) ;
}
}
static int F_21 ( struct V_12 * V_13 ,
unsigned int V_26 )
{
struct V_1 * V_2 = F_13 ( V_13 ) ;
switch ( V_26 & V_27 ) {
case V_28 :
break;
default:
return - V_29 ;
}
V_2 -> V_30 &= ~ V_31 ;
switch ( V_26 & V_32 ) {
case V_33 :
V_2 -> V_30 |= V_31 ;
break;
case V_34 :
break;
default:
return - V_29 ;
}
V_2 -> V_30 &= ~ ( V_35 |
V_36 ) ;
switch ( V_26 & V_37 ) {
case V_38 :
V_2 -> V_30 |= V_39 ;
V_2 -> V_30 |= V_40 ;
break;
case V_41 :
V_2 -> V_30 |= V_39 ;
V_2 -> V_30 |= V_42 ;
break;
case V_43 :
V_2 -> V_30 |= V_44 ;
V_2 -> V_30 |= V_40 ;
break;
case V_45 :
V_2 -> V_30 |= V_44 ;
V_2 -> V_30 |= V_40 ;
break;
case V_46 :
V_2 -> V_30 |= V_44 ;
V_2 -> V_30 |= V_40 ;
break;
default:
return - V_29 ;
}
return 0 ;
}
static int F_22 ( struct V_10 * V_11 ,
struct V_47 * V_48 ,
struct V_12 * V_13 )
{
struct V_6 * V_7 = V_11 -> V_49 -> V_50 -> V_7 ;
struct V_1 * V_2 = F_13 ( V_13 ) ;
T_1 V_4 ;
int V_9 , V_51 , V_52 , V_53 , V_54 ;
if ( F_23 ( V_48 ) != 2 )
return - V_29 ;
V_2 -> V_30 &= ~ V_55 ;
switch ( F_24 ( V_48 ) ) {
case V_56 :
V_2 -> V_30 |= V_57 ;
V_51 = 16 ;
break;
default:
return - V_29 ;
}
V_52 = F_25 ( V_48 ) ;
V_53 = V_52 * F_23 ( V_48 ) * V_51 * 2 ;
V_54 = ( V_53 / ( 2 * V_52 ) ) - 1 ;
if ( V_54 < 0 || V_54 > V_58 )
return - V_29 ;
V_9 = F_26 ( V_2 -> V_8 , V_53 ) ;
if ( V_9 ) {
F_11 ( V_7 , L_2 , V_9 ) ;
return V_9 ;
}
V_4 = V_54 << V_59 ;
if ( V_53 % ( 2 * V_52 ) )
V_4 |= V_60 ;
F_1 ( V_2 , V_61 , V_4 ) ;
V_4 = ( 0 << V_62 ) |
( 1 << V_63 ) |
( 1 << V_64 ) |
V_65 |
V_66 ;
if ( V_11 -> V_14 == V_15 ) {
V_4 |= V_67 ;
F_1 ( V_2 , V_68 , V_4 ) ;
} else {
V_4 |= V_69 ;
F_1 ( V_2 , V_70 , V_4 ) ;
}
V_4 = ( 1 << V_71 ) |
( 1 << V_72 ) ;
F_1 ( V_2 , V_73 , V_4 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_28 ( V_2 -> V_16 ) ;
V_2 -> V_30 |= V_74 ;
F_1 ( V_2 , V_75 , V_2 -> V_30 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_30 ( V_2 -> V_16 ) ;
V_2 -> V_30 &= ~ V_74 ;
F_1 ( V_2 , V_75 , V_2 -> V_30 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_32 ( V_2 -> V_23 ) ;
V_2 -> V_30 |= V_76 ;
F_1 ( V_2 , V_75 , V_2 -> V_30 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_34 ( V_2 -> V_23 ) ;
V_2 -> V_30 &= ~ V_76 ;
F_1 ( V_2 , V_75 , V_2 -> V_30 ) ;
}
static int F_35 ( struct V_10 * V_11 , int V_77 ,
struct V_12 * V_13 )
{
struct V_1 * V_2 = F_13 ( V_13 ) ;
switch ( V_77 ) {
case V_78 :
case V_79 :
case V_80 :
if ( V_11 -> V_14 == V_15 )
F_27 ( V_2 ) ;
else
F_31 ( V_2 ) ;
break;
case V_81 :
case V_82 :
case V_83 :
if ( V_11 -> V_14 == V_15 )
F_29 ( V_2 ) ;
else
F_33 ( V_2 ) ;
break;
default:
return - V_29 ;
}
return 0 ;
}
static int F_36 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_13 ( V_13 ) ;
V_13 -> V_24 = & V_2 -> V_24 ;
V_13 -> V_17 = & V_2 -> V_17 ;
return 0 ;
}
static bool F_37 ( struct V_6 * V_7 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_75 :
case V_61 :
case V_73 :
case V_84 :
case V_85 :
case V_68 :
case V_70 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
return true ;
default:
return false ;
} ;
}
static bool F_38 ( struct V_6 * V_7 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_88 :
case V_89 :
case V_90 :
case V_91 :
return true ;
default:
return false ;
} ;
}
static T_2 int F_39 ( struct V_101 * V_102 )
{
struct V_1 * V_2 ;
T_1 V_103 [ 2 ] ;
struct V_104 * V_105 , * V_106 ;
void T_3 * V_107 ;
int V_9 ;
V_2 = F_40 ( & V_102 -> V_7 , sizeof( struct V_1 ) , V_108 ) ;
if ( ! V_2 ) {
F_11 ( & V_102 -> V_7 , L_3 ) ;
V_9 = - V_109 ;
goto V_110;
}
F_41 ( & V_102 -> V_7 , V_2 ) ;
V_2 -> V_13 = V_111 ;
V_2 -> V_13 . V_112 = F_42 ( & V_102 -> V_7 ) ;
V_9 = F_43 ( V_102 -> V_7 . V_113 ,
L_4 , V_103 ,
F_44 ( V_103 ) ) ;
if ( V_9 < 0 )
goto V_110;
V_2 -> V_22 = V_103 [ 0 ] ;
V_2 -> V_25 = V_103 [ 1 ] ;
V_2 -> V_8 = F_45 ( & V_102 -> V_7 , NULL ) ;
if ( F_46 ( V_2 -> V_8 ) ) {
F_11 ( & V_102 -> V_7 , L_5 ) ;
V_9 = F_47 ( V_2 -> V_8 ) ;
goto V_110;
}
V_105 = F_48 ( V_102 , V_114 , 0 ) ;
if ( ! V_105 ) {
F_11 ( & V_102 -> V_7 , L_6 ) ;
V_9 = - V_115 ;
goto V_116;
}
V_106 = F_49 ( & V_102 -> V_7 , V_105 -> V_117 ,
F_50 ( V_105 ) , V_118 ) ;
if ( ! V_106 ) {
F_11 ( & V_102 -> V_7 , L_7 ) ;
V_9 = - V_119 ;
goto V_116;
}
V_107 = F_51 ( & V_102 -> V_7 , V_105 -> V_117 , F_50 ( V_105 ) ) ;
if ( ! V_107 ) {
F_11 ( & V_102 -> V_7 , L_8 ) ;
V_9 = - V_109 ;
goto V_116;
}
V_2 -> V_5 = F_52 ( & V_102 -> V_7 , V_107 ,
& V_120 ) ;
if ( F_46 ( V_2 -> V_5 ) ) {
F_11 ( & V_102 -> V_7 , L_9 ) ;
V_9 = F_47 ( V_2 -> V_5 ) ;
goto V_116;
}
F_7 ( V_2 -> V_5 , true ) ;
F_53 ( & V_102 -> V_7 ) ;
if ( ! F_54 ( & V_102 -> V_7 ) ) {
V_9 = F_9 ( & V_102 -> V_7 ) ;
if ( V_9 )
goto V_121;
}
V_9 = F_55 ( & V_102 -> V_7 , & V_2 -> V_13 ) ;
if ( V_9 ) {
F_11 ( & V_102 -> V_7 , L_10 , V_9 ) ;
V_9 = - V_109 ;
goto V_122;
}
V_9 = F_56 ( & V_102 -> V_7 ) ;
if ( V_9 ) {
F_11 ( & V_102 -> V_7 , L_11 , V_9 ) ;
goto V_123;
}
return 0 ;
V_123:
F_57 ( & V_102 -> V_7 ) ;
V_122:
if ( ! F_58 ( & V_102 -> V_7 ) )
F_5 ( & V_102 -> V_7 ) ;
V_121:
F_59 ( & V_102 -> V_7 ) ;
V_116:
F_60 ( V_2 -> V_8 ) ;
V_110:
return V_9 ;
}
static int T_4 F_61 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = F_6 ( & V_102 -> V_7 ) ;
F_59 ( & V_102 -> V_7 ) ;
if ( ! F_58 ( & V_102 -> V_7 ) )
F_5 ( & V_102 -> V_7 ) ;
F_62 ( & V_102 -> V_7 ) ;
F_57 ( & V_102 -> V_7 ) ;
F_60 ( V_2 -> V_8 ) ;
return 0 ;
}
