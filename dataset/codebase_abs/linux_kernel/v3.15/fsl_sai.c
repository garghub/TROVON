static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_5 * V_6 = & V_4 -> V_7 -> V_6 ;
T_2 V_8 , V_9 ;
V_9 = ( V_10 >> V_11 ) << V_12 ;
F_2 ( V_4 -> V_13 , V_14 , & V_8 ) ;
V_8 &= V_9 ;
if ( V_8 & V_15 )
F_3 ( V_6 , L_1 ) ;
if ( V_8 & V_16 )
F_4 ( V_6 , L_2 ) ;
if ( V_8 & V_17 ) {
F_4 ( V_6 , L_3 ) ;
V_8 |= V_18 ;
}
if ( V_8 & V_19 )
F_3 ( V_6 , L_4 ) ;
if ( V_8 & V_20 )
F_3 ( V_6 , L_5 ) ;
F_5 ( V_4 -> V_13 , V_14 ,
V_21 | V_18 , V_8 ) ;
F_2 ( V_4 -> V_13 , V_22 , & V_8 ) ;
V_8 &= V_9 ;
if ( V_8 & V_15 )
F_3 ( V_6 , L_6 ) ;
if ( V_8 & V_16 )
F_4 ( V_6 , L_7 ) ;
if ( V_8 & V_17 ) {
F_4 ( V_6 , L_8 ) ;
V_8 |= V_18 ;
}
if ( V_8 & V_19 )
F_3 ( V_6 , L_9 ) ;
if ( V_8 & V_20 )
F_3 ( V_6 , L_10 ) ;
F_5 ( V_4 -> V_13 , V_22 ,
V_21 | V_18 , V_8 ) ;
return V_23 ;
}
static int F_6 ( struct V_24 * V_25 ,
int V_26 , unsigned int V_27 , int V_28 )
{
struct V_3 * V_4 = F_7 ( V_25 ) ;
T_2 V_29 , V_30 ;
if ( V_28 == V_31 )
V_30 = V_32 ;
else
V_30 = V_33 ;
F_2 ( V_4 -> V_13 , V_30 , & V_29 ) ;
V_29 &= ~ V_34 ;
switch ( V_26 ) {
case V_35 :
V_29 |= V_36 ;
break;
case V_37 :
V_29 |= V_38 ;
break;
case V_39 :
V_29 |= V_40 ;
break;
case V_41 :
V_29 |= V_42 ;
break;
default:
return - V_43 ;
}
F_8 ( V_4 -> V_13 , V_30 , V_29 ) ;
return 0 ;
}
static int F_9 ( struct V_24 * V_25 ,
int V_26 , unsigned int V_27 , int V_44 )
{
int V_45 ;
if ( V_44 == V_46 )
return 0 ;
V_45 = F_6 ( V_25 , V_26 , V_27 ,
V_31 ) ;
if ( V_45 ) {
F_10 ( V_25 -> V_6 , L_11 , V_45 ) ;
return V_45 ;
}
V_45 = F_6 ( V_25 , V_26 , V_27 ,
V_47 ) ;
if ( V_45 )
F_10 ( V_25 -> V_6 , L_12 , V_45 ) ;
return V_45 ;
}
static int F_11 ( struct V_24 * V_25 ,
unsigned int V_48 , int V_28 )
{
struct V_3 * V_4 = F_7 ( V_25 ) ;
T_2 V_29 , V_49 , V_30 , V_50 ;
if ( V_28 == V_31 ) {
V_30 = V_32 ;
V_50 = V_51 ;
} else {
V_30 = V_33 ;
V_50 = V_52 ;
}
F_2 ( V_4 -> V_13 , V_30 , & V_29 ) ;
F_2 ( V_4 -> V_13 , V_50 , & V_49 ) ;
if ( V_4 -> V_53 )
V_49 &= ~ V_54 ;
else
V_49 |= V_54 ;
switch ( V_48 & V_55 ) {
case V_56 :
V_29 |= V_57 ;
V_49 |= V_58 | V_59 ;
break;
case V_60 :
V_29 |= V_57 ;
V_49 &= ~ ( V_58 | V_59 ) ;
break;
case V_61 :
V_29 |= V_57 ;
V_49 &= ~ V_59 ;
V_49 |= V_58 ;
V_4 -> V_62 = true ;
break;
case V_63 :
V_29 |= V_57 ;
V_49 &= ~ ( V_58 | V_59 ) ;
V_4 -> V_62 = true ;
break;
case V_64 :
default:
return - V_43 ;
}
switch ( V_48 & V_65 ) {
case V_66 :
V_29 ^= V_57 ;
V_49 ^= V_59 ;
break;
case V_67 :
V_29 ^= V_57 ;
break;
case V_68 :
V_49 ^= V_59 ;
break;
case V_69 :
break;
default:
return - V_43 ;
}
switch ( V_48 & V_70 ) {
case V_71 :
V_29 |= V_72 ;
V_49 |= V_73 ;
break;
case V_74 :
V_29 &= ~ V_72 ;
V_49 &= ~ V_73 ;
break;
case V_75 :
V_29 |= V_72 ;
V_49 &= ~ V_73 ;
break;
case V_76 :
V_29 &= ~ V_72 ;
V_49 |= V_73 ;
break;
default:
return - V_43 ;
}
F_8 ( V_4 -> V_13 , V_30 , V_29 ) ;
F_8 ( V_4 -> V_13 , V_50 , V_49 ) ;
return 0 ;
}
static int F_12 ( struct V_24 * V_25 , unsigned int V_48 )
{
int V_45 ;
V_45 = F_11 ( V_25 , V_48 , V_31 ) ;
if ( V_45 ) {
F_10 ( V_25 -> V_6 , L_13 , V_45 ) ;
return V_45 ;
}
V_45 = F_11 ( V_25 , V_48 , V_47 ) ;
if ( V_45 )
F_10 ( V_25 -> V_6 , L_14 , V_45 ) ;
return V_45 ;
}
static int F_13 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_24 * V_25 )
{
struct V_3 * V_4 = F_7 ( V_25 ) ;
T_2 V_49 , V_81 , V_82 , V_50 , V_83 , V_84 ;
unsigned int V_85 = F_14 ( V_80 ) ;
T_2 V_86 = F_15 ( F_16 ( V_80 ) ) ;
if ( V_78 -> V_87 == V_88 ) {
V_50 = V_51 ;
V_83 = V_89 ;
V_84 = V_90 ;
} else {
V_50 = V_52 ;
V_83 = V_91 ;
V_84 = V_92 ;
}
F_2 ( V_4 -> V_13 , V_50 , & V_49 ) ;
F_2 ( V_4 -> V_13 , V_50 , & V_81 ) ;
V_49 &= ~ V_93 ;
V_49 &= ~ V_94 ;
V_81 &= ~ V_95 ;
V_81 &= ~ V_96 ;
V_81 &= ~ V_97 ;
if ( ! V_4 -> V_62 )
V_49 |= F_17 ( V_86 ) ;
V_81 |= F_18 ( V_86 ) ;
V_81 |= F_19 ( V_86 ) ;
V_81 &= ~ V_97 ;
if ( V_4 -> V_53 )
V_81 |= F_20 ( 0 ) ;
else
V_81 |= F_20 ( V_86 - 1 ) ;
V_49 |= F_21 ( V_85 ) ;
V_82 = ~ 0UL - ( ( 1 << V_85 ) - 1 ) ;
F_8 ( V_4 -> V_13 , V_50 , V_49 ) ;
F_8 ( V_4 -> V_13 , V_83 , V_81 ) ;
F_8 ( V_4 -> V_13 , V_84 , V_82 ) ;
return 0 ;
}
static int F_22 ( struct V_77 * V_78 , int V_98 ,
struct V_24 * V_25 )
{
struct V_3 * V_4 = F_7 ( V_25 ) ;
T_2 V_99 , V_100 ;
F_5 ( V_4 -> V_13 , V_32 , V_101 ,
~ V_101 ) ;
F_5 ( V_4 -> V_13 , V_33 , V_101 ,
V_101 ) ;
F_2 ( V_4 -> V_13 , V_14 , & V_99 ) ;
F_2 ( V_4 -> V_13 , V_22 , & V_100 ) ;
if ( V_78 -> V_87 == V_88 ) {
V_99 |= V_102 ;
V_100 &= ~ V_102 ;
} else {
V_100 |= V_102 ;
V_99 &= ~ V_102 ;
}
switch ( V_98 ) {
case V_103 :
case V_104 :
case V_105 :
V_99 |= V_106 ;
V_100 |= V_106 ;
F_8 ( V_4 -> V_13 , V_22 , V_100 ) ;
F_8 ( V_4 -> V_13 , V_14 , V_99 ) ;
break;
case V_107 :
case V_108 :
case V_109 :
if ( ! ( V_25 -> V_110 || V_25 -> V_111 ) ) {
V_99 &= ~ V_106 ;
V_100 &= ~ V_106 ;
}
F_8 ( V_4 -> V_13 , V_14 , V_99 ) ;
F_8 ( V_4 -> V_13 , V_22 , V_100 ) ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static int F_23 ( struct V_77 * V_78 ,
struct V_24 * V_25 )
{
struct V_3 * V_4 = F_7 ( V_25 ) ;
T_2 V_112 ;
if ( V_78 -> V_87 == V_88 )
V_112 = V_113 ;
else
V_112 = V_114 ;
F_5 ( V_4 -> V_13 , V_112 , V_115 ,
V_115 ) ;
return 0 ;
}
static void F_24 ( struct V_77 * V_78 ,
struct V_24 * V_25 )
{
struct V_3 * V_4 = F_7 ( V_25 ) ;
T_2 V_112 ;
if ( V_78 -> V_87 == V_88 )
V_112 = V_113 ;
else
V_112 = V_114 ;
F_5 ( V_4 -> V_13 , V_112 , V_115 ,
~ V_115 ) ;
}
static int F_25 ( struct V_24 * V_25 )
{
struct V_3 * V_4 = F_26 ( V_25 -> V_6 ) ;
F_5 ( V_4 -> V_13 , V_14 , 0xffffffff , V_10 ) ;
F_5 ( V_4 -> V_13 , V_22 , 0xffffffff , V_10 ) ;
F_5 ( V_4 -> V_13 , V_116 , V_117 ,
V_118 * 2 ) ;
F_5 ( V_4 -> V_13 , V_119 , V_117 ,
V_120 - 1 ) ;
F_27 ( V_25 , & V_4 -> V_121 ,
& V_4 -> V_122 ) ;
F_28 ( V_25 , V_4 ) ;
return 0 ;
}
static bool F_29 ( struct V_5 * V_6 , unsigned int V_112 )
{
switch ( V_112 ) {
case V_14 :
case V_116 :
case V_32 :
case V_113 :
case V_51 :
case V_89 :
case V_123 :
case V_90 :
case V_22 :
case V_119 :
case V_33 :
case V_114 :
case V_52 :
case V_91 :
case V_124 :
case V_125 :
case V_92 :
return true ;
default:
return false ;
}
}
static bool F_30 ( struct V_5 * V_6 , unsigned int V_112 )
{
switch ( V_112 ) {
case V_123 :
case V_125 :
case V_126 :
case V_124 :
return true ;
default:
return false ;
}
}
static bool F_31 ( struct V_5 * V_6 , unsigned int V_112 )
{
switch ( V_112 ) {
case V_14 :
case V_116 :
case V_32 :
case V_113 :
case V_51 :
case V_89 :
case V_126 :
case V_90 :
case V_22 :
case V_119 :
case V_33 :
case V_114 :
case V_52 :
case V_91 :
case V_92 :
return true ;
default:
return false ;
}
}
static int F_32 ( struct V_127 * V_7 )
{
struct V_128 * V_129 = V_7 -> V_6 . V_130 ;
struct V_3 * V_4 ;
struct V_131 * V_132 ;
void T_3 * V_133 ;
int V_1 , V_45 ;
V_4 = F_33 ( & V_7 -> V_6 , sizeof( * V_4 ) , V_134 ) ;
if ( ! V_4 )
return - V_135 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_136 = F_34 ( V_129 , L_15 ) ;
if ( V_4 -> V_136 )
V_137 . V_138 = V_139 ;
V_4 -> V_53 = F_34 ( V_129 , L_16 ) ;
V_132 = F_35 ( V_7 , V_140 , 0 ) ;
V_133 = F_36 ( & V_7 -> V_6 , V_132 ) ;
if ( F_37 ( V_133 ) )
return F_38 ( V_133 ) ;
V_4 -> V_13 = F_39 ( & V_7 -> V_6 ,
L_17 , V_133 , & V_137 ) ;
if ( F_37 ( V_4 -> V_13 ) ) {
F_10 ( & V_7 -> V_6 , L_18 ) ;
return F_38 ( V_4 -> V_13 ) ;
}
V_1 = F_40 ( V_7 , 0 ) ;
if ( V_1 < 0 ) {
F_10 ( & V_7 -> V_6 , L_19 , V_129 -> V_141 ) ;
return V_1 ;
}
V_45 = F_41 ( & V_7 -> V_6 , V_1 , F_1 , 0 , V_129 -> V_142 , V_4 ) ;
if ( V_45 ) {
F_10 ( & V_7 -> V_6 , L_20 , V_1 ) ;
return V_45 ;
}
V_4 -> V_122 . V_143 = V_132 -> V_144 + V_124 ;
V_4 -> V_121 . V_143 = V_132 -> V_144 + V_126 ;
V_4 -> V_122 . V_145 = V_120 ;
V_4 -> V_121 . V_145 = V_118 ;
F_42 ( V_7 , V_4 ) ;
V_45 = F_43 ( & V_7 -> V_6 , & V_146 ,
& V_147 , 1 ) ;
if ( V_45 )
return V_45 ;
return F_44 ( & V_7 -> V_6 , NULL ,
V_148 ) ;
}
