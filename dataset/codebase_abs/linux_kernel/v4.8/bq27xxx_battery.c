static inline int F_1 ( struct V_1 * V_2 , int V_3 ,
bool V_4 )
{
if ( ! V_2 || V_2 -> V_5 [ V_3 ] == V_6 )
return - V_7 ;
return V_2 -> V_8 . V_9 ( V_2 , V_2 -> V_5 [ V_3 ] , V_4 ) ;
}
static int F_2 ( struct V_1 * V_2 )
{
int V_10 ;
if ( V_2 -> V_11 == V_12 || V_2 -> V_11 == V_13 )
V_10 = F_1 ( V_2 , V_14 , true ) ;
else
V_10 = F_1 ( V_2 , V_14 , false ) ;
if ( V_10 < 0 )
F_3 ( V_2 -> V_15 , L_1 ) ;
return V_10 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_16 )
{
int V_17 ;
V_17 = F_1 ( V_2 , V_16 , false ) ;
if ( V_17 < 0 ) {
F_3 ( V_2 -> V_15 , L_2 ,
V_16 , V_17 ) ;
return V_17 ;
}
if ( V_2 -> V_11 == V_12 || V_2 -> V_11 == V_13 )
V_17 *= V_18 / V_19 ;
else
V_17 *= 1000 ;
return V_17 ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
int V_20 ;
if ( V_2 -> V_11 == V_12 || V_2 -> V_11 == V_13 ) {
V_20 = F_1 ( V_2 , V_21 , true ) ;
if ( V_20 >= 0 && ( V_20 & V_22 ) )
return - V_23 ;
}
return F_4 ( V_2 , V_24 ) ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , V_25 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_26 ;
if ( V_2 -> V_11 == V_12 || V_2 -> V_11 == V_13 )
V_26 = F_1 ( V_2 , V_27 , true ) ;
else
V_26 = F_1 ( V_2 , V_27 , false ) ;
if ( V_26 < 0 ) {
F_3 ( V_2 -> V_15 , L_3 ) ;
return V_26 ;
}
if ( V_2 -> V_11 == V_12 || V_2 -> V_11 == V_13 )
V_26 = ( V_26 << 8 ) * V_18 / V_19 ;
else
V_26 *= 1000 ;
return V_26 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_28 ;
V_28 = F_1 ( V_2 , V_29 , false ) ;
if ( V_28 < 0 ) {
F_3 ( V_2 -> V_15 , L_4 ) ;
return V_28 ;
}
if ( V_2 -> V_11 == V_12 || V_2 -> V_11 == V_13 )
V_28 *= V_30 / V_19 ;
else
V_28 *= 1000 ;
return V_28 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_31 ;
V_31 = F_1 ( V_2 , V_32 , false ) ;
if ( V_31 < 0 ) {
F_10 ( V_2 -> V_15 , L_5 ) ;
return V_31 ;
}
if ( V_2 -> V_11 == V_12 || V_2 -> V_11 == V_13 )
V_31 = 5 * V_31 / 2 ;
return V_31 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_33 ;
V_33 = F_1 ( V_2 , V_34 , false ) ;
if ( V_33 < 0 )
F_10 ( V_2 -> V_15 , L_6 ) ;
return V_33 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_16 )
{
int V_35 ;
V_35 = F_1 ( V_2 , V_16 , false ) ;
if ( V_35 < 0 ) {
F_3 ( V_2 -> V_15 , L_7 ,
V_16 , V_35 ) ;
return V_35 ;
}
if ( V_35 == 65535 )
return - V_23 ;
return V_35 * 60 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_35 ;
V_35 = F_1 ( V_2 , V_36 , false ) ;
if ( V_35 < 0 ) {
F_10 ( V_2 -> V_15 , L_8 ,
V_36 , V_35 ) ;
return V_35 ;
}
if ( V_2 -> V_11 == V_12 || V_2 -> V_11 == V_13 )
return ( V_35 * V_30 ) / V_19 ;
else
return V_35 ;
}
static bool F_14 ( struct V_1 * V_2 , T_2 V_20 )
{
if ( V_2 -> V_11 == V_37 || V_2 -> V_11 == V_38 || V_2 -> V_11 == V_39 )
return V_20 & ( V_40 | V_41 ) ;
if ( V_2 -> V_11 == V_42 || V_2 -> V_11 == V_43 )
return V_20 & V_44 ;
return false ;
}
static bool F_15 ( struct V_1 * V_2 , T_2 V_20 )
{
if ( V_2 -> V_11 == V_42 || V_2 -> V_11 == V_43 )
return V_20 & V_45 ;
return false ;
}
static bool F_16 ( struct V_1 * V_2 , T_2 V_20 )
{
if ( V_2 -> V_11 == V_12 || V_2 -> V_11 == V_13 )
return V_20 & ( V_46 | V_47 ) ;
else
return V_20 & ( V_48 | V_49 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_1 ( V_2 , V_21 , false ) ;
if ( V_20 < 0 ) {
F_10 ( V_2 -> V_15 , L_9 , V_20 ) ;
return V_20 ;
}
if ( F_18 ( F_14 ( V_2 , V_20 ) ) )
return V_50 ;
if ( F_18 ( F_15 ( V_2 , V_20 ) ) )
return V_51 ;
if ( F_18 ( F_16 ( V_2 , V_20 ) ) )
return V_52 ;
return V_53 ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_54 V_55 = { 0 , } ;
bool V_56 = V_2 -> V_11 == V_12 || V_2 -> V_11 == V_13 ;
bool V_57 = V_2 -> V_11 == V_12 || V_2 -> V_11 == V_13 ;
V_55 . V_20 = F_1 ( V_2 , V_21 , V_57 ) ;
if ( ( V_55 . V_20 & 0xff ) == 0xff )
V_55 . V_20 = - 1 ;
if ( V_55 . V_20 >= 0 ) {
V_55 . V_58 = F_9 ( V_2 ) ;
if ( V_56 && ( V_55 . V_20 & V_22 ) ) {
F_20 ( V_2 -> V_15 , L_10 ) ;
V_55 . V_59 = - V_23 ;
V_55 . V_60 = - V_23 ;
V_55 . V_61 = - V_23 ;
V_55 . V_62 = - V_23 ;
V_55 . V_63 = - V_23 ;
V_55 . V_64 = - V_23 ;
V_55 . V_65 = - V_23 ;
} else {
if ( V_2 -> V_5 [ V_66 ] != V_6 )
V_55 . V_61 = F_12 ( V_2 , V_66 ) ;
if ( V_2 -> V_5 [ V_67 ] != V_6 )
V_55 . V_62 = F_12 ( V_2 , V_67 ) ;
if ( V_2 -> V_5 [ V_68 ] != V_6 )
V_55 . V_63 = F_12 ( V_2 , V_68 ) ;
V_55 . V_64 = F_6 ( V_2 ) ;
V_55 . V_59 = F_2 ( V_2 ) ;
if ( V_2 -> V_5 [ V_29 ] != V_6 )
V_55 . V_60 = F_8 ( V_2 ) ;
V_55 . V_65 = F_17 ( V_2 ) ;
}
if ( V_2 -> V_5 [ V_34 ] != V_6 )
V_55 . V_69 = F_11 ( V_2 ) ;
if ( V_2 -> V_5 [ V_36 ] != V_6 )
V_55 . V_70 = F_13 ( V_2 ) ;
if ( V_2 -> V_71 <= 0 )
V_2 -> V_71 = F_7 ( V_2 ) ;
}
if ( V_2 -> V_55 . V_59 != V_55 . V_59 )
F_21 ( V_2 -> V_72 ) ;
if ( memcmp ( & V_2 -> V_55 , & V_55 , sizeof( V_55 ) ) != 0 )
V_2 -> V_55 = V_55 ;
V_2 -> V_73 = V_74 ;
}
static void F_22 ( struct V_75 * V_76 )
{
struct V_1 * V_2 =
F_23 ( V_76 , struct V_1 ,
V_76 . V_76 ) ;
F_19 ( V_2 ) ;
if ( V_77 > 0 )
F_24 ( & V_2 -> V_76 , V_77 * V_78 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
union V_79 * V_80 )
{
int V_81 ;
int V_20 ;
V_81 = F_1 ( V_2 , V_82 , false ) ;
if ( V_81 < 0 ) {
F_10 ( V_2 -> V_15 , L_11 ) ;
return V_81 ;
}
if ( V_2 -> V_11 == V_12 || V_2 -> V_11 == V_13 ) {
V_20 = F_1 ( V_2 , V_21 , false ) ;
if ( V_20 & V_83 ) {
F_3 ( V_2 -> V_15 , L_12 ) ;
V_81 = - V_81 ;
}
V_80 -> V_84 = V_81 * V_18 / V_19 ;
} else {
V_80 -> V_84 = ( int ) ( ( V_85 ) V_81 ) * 1000 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
union V_79 * V_80 )
{
int V_86 ;
if ( V_2 -> V_11 == V_12 || V_2 -> V_11 == V_13 ) {
if ( V_2 -> V_55 . V_20 & V_87 )
V_86 = V_88 ;
else if ( V_2 -> V_55 . V_20 & V_83 )
V_86 = V_89 ;
else if ( F_27 ( V_2 -> V_72 ) )
V_86 = V_90 ;
else
V_86 = V_91 ;
} else {
if ( V_2 -> V_55 . V_20 & V_92 )
V_86 = V_88 ;
else if ( V_2 -> V_55 . V_20 & V_93 )
V_86 = V_91 ;
else
V_86 = V_89 ;
}
V_80 -> V_84 = V_86 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
union V_79 * V_80 )
{
int V_94 ;
if ( V_2 -> V_11 == V_12 || V_2 -> V_11 == V_13 ) {
if ( V_2 -> V_55 . V_20 & V_87 )
V_94 = V_95 ;
else if ( V_2 -> V_55 . V_20 & V_46 )
V_94 = V_96 ;
else if ( V_2 -> V_55 . V_20 & V_47 )
V_94 = V_97 ;
else
V_94 = V_98 ;
} else {
if ( V_2 -> V_55 . V_20 & V_92 )
V_94 = V_95 ;
else if ( V_2 -> V_55 . V_20 & V_48 )
V_94 = V_96 ;
else if ( V_2 -> V_55 . V_20 & V_49 )
V_94 = V_97 ;
else
V_94 = V_98 ;
}
V_80 -> V_84 = V_94 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
union V_79 * V_80 )
{
int V_99 ;
V_99 = F_1 ( V_2 , V_100 , false ) ;
if ( V_99 < 0 ) {
F_10 ( V_2 -> V_15 , L_13 ) ;
return V_99 ;
}
V_80 -> V_84 = V_99 * 1000 ;
return 0 ;
}
static int F_30 ( int V_101 ,
union V_79 * V_80 )
{
if ( V_101 < 0 )
return V_101 ;
V_80 -> V_84 = V_101 ;
return 0 ;
}
static int F_31 ( struct V_102 * V_103 ,
enum V_104 V_105 ,
union V_79 * V_80 )
{
int V_106 = 0 ;
struct V_1 * V_2 = F_32 ( V_103 ) ;
F_33 ( & V_2 -> V_107 ) ;
if ( F_34 ( V_2 -> V_73 + 5 * V_78 ) ) {
F_35 ( & V_2 -> V_76 ) ;
F_22 ( & V_2 -> V_76 . V_76 ) ;
}
F_36 ( & V_2 -> V_107 ) ;
if ( V_105 != V_108 && V_2 -> V_55 . V_20 < 0 )
return - V_109 ;
switch ( V_105 ) {
case V_110 :
V_106 = F_26 ( V_2 , V_80 ) ;
break;
case V_111 :
V_106 = F_29 ( V_2 , V_80 ) ;
break;
case V_108 :
V_80 -> V_84 = V_2 -> V_55 . V_20 < 0 ? 0 : 1 ;
break;
case V_112 :
V_106 = F_25 ( V_2 , V_80 ) ;
break;
case V_113 :
V_106 = F_30 ( V_2 -> V_55 . V_59 , V_80 ) ;
break;
case V_114 :
V_106 = F_28 ( V_2 , V_80 ) ;
break;
case V_115 :
V_106 = F_30 ( V_2 -> V_55 . V_58 , V_80 ) ;
if ( V_106 == 0 )
V_80 -> V_84 -= 2731 ;
break;
case V_116 :
V_106 = F_30 ( V_2 -> V_55 . V_61 , V_80 ) ;
break;
case V_117 :
V_106 = F_30 ( V_2 -> V_55 . V_62 , V_80 ) ;
break;
case V_118 :
V_106 = F_30 ( V_2 -> V_55 . V_63 , V_80 ) ;
break;
case V_119 :
V_80 -> V_84 = V_120 ;
break;
case V_121 :
V_106 = F_30 ( F_5 ( V_2 ) , V_80 ) ;
break;
case V_122 :
V_106 = F_30 ( V_2 -> V_55 . V_64 , V_80 ) ;
break;
case V_123 :
V_106 = F_30 ( V_2 -> V_71 , V_80 ) ;
break;
case V_124 :
V_106 = F_30 ( V_2 -> V_55 . V_69 , V_80 ) ;
break;
case V_125 :
V_106 = F_30 ( V_2 -> V_55 . V_60 , V_80 ) ;
break;
case V_126 :
V_106 = F_30 ( V_2 -> V_55 . V_70 , V_80 ) ;
break;
case V_127 :
V_106 = F_30 ( V_2 -> V_55 . V_65 , V_80 ) ;
break;
case V_128 :
V_80 -> V_129 = V_130 ;
break;
default:
return - V_7 ;
}
return V_106 ;
}
static void F_37 ( struct V_102 * V_103 )
{
struct V_1 * V_2 = F_32 ( V_103 ) ;
F_35 ( & V_2 -> V_76 ) ;
F_24 ( & V_2 -> V_76 , 0 ) ;
}
int F_38 ( struct V_1 * V_2 )
{
struct V_131 * V_132 ;
struct V_133 V_134 = { . V_135 = V_2 , } ;
F_39 ( & V_2 -> V_76 , F_22 ) ;
F_40 ( & V_2 -> V_107 ) ;
V_2 -> V_5 = V_136 [ V_2 -> V_11 ] ;
V_132 = F_41 ( V_2 -> V_15 , sizeof( * V_132 ) , V_137 ) ;
if ( ! V_132 )
return - V_138 ;
V_132 -> V_139 = V_2 -> V_139 ;
V_132 -> type = V_140 ;
V_132 -> V_141 = V_142 [ V_2 -> V_11 ] . V_143 ;
V_132 -> V_144 = V_142 [ V_2 -> V_11 ] . V_145 ;
V_132 -> V_146 = F_31 ;
V_132 -> V_147 = F_37 ;
V_2 -> V_72 = F_42 ( V_2 -> V_15 , V_132 , & V_134 ) ;
if ( F_43 ( V_2 -> V_72 ) ) {
F_10 ( V_2 -> V_15 , L_14 ) ;
return F_44 ( V_2 -> V_72 ) ;
}
F_45 ( V_2 -> V_15 , L_15 , V_148 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
void F_46 ( struct V_1 * V_2 )
{
V_77 = 0 ;
F_35 ( & V_2 -> V_76 ) ;
F_47 ( V_2 -> V_72 ) ;
F_48 ( & V_2 -> V_107 ) ;
}
static int F_49 ( struct V_1 * V_2 , T_1 V_16 ,
bool V_4 )
{
struct V_149 * V_15 = V_2 -> V_15 ;
struct V_150 * V_151 = V_15 -> V_152 ;
unsigned int V_153 = 3 ;
int V_154 , V_155 ;
int V_31 ;
if ( ! V_4 ) {
V_154 = V_151 -> V_9 ( V_15 , V_16 + 1 ) ;
do {
V_31 = V_154 ;
if ( V_154 < 0 )
return V_154 ;
V_155 = V_151 -> V_9 ( V_15 , V_16 ) ;
if ( V_155 < 0 )
return V_155 ;
V_154 = V_151 -> V_9 ( V_15 , V_16 + 1 ) ;
} while ( V_31 != V_154 && -- V_153 );
if ( V_153 == 0 )
return - V_156 ;
return ( V_154 << 8 ) | V_155 ;
}
return V_151 -> V_9 ( V_15 , V_16 ) ;
}
static int F_50 ( struct V_157 * V_158 )
{
struct V_1 * V_2 ;
struct V_150 * V_151 = V_158 -> V_15 . V_152 ;
if ( ! V_151 ) {
F_10 ( & V_158 -> V_15 , L_16 ) ;
return - V_7 ;
}
if ( ! V_151 -> V_9 ) {
F_10 ( & V_158 -> V_15 , L_17 ) ;
return - V_7 ;
}
if ( ! V_151 -> V_11 ) {
F_10 ( & V_158 -> V_15 , L_18 ) ;
return - V_7 ;
}
V_2 = F_41 ( & V_158 -> V_15 , sizeof( * V_2 ) , V_137 ) ;
if ( ! V_2 )
return - V_138 ;
F_51 ( V_158 , V_2 ) ;
V_2 -> V_15 = & V_158 -> V_15 ;
V_2 -> V_11 = V_151 -> V_11 ;
V_2 -> V_139 = V_151 -> V_139 ? : F_52 ( & V_158 -> V_15 ) ;
V_2 -> V_8 . V_9 = F_49 ;
return F_38 ( V_2 ) ;
}
static int F_53 ( struct V_157 * V_158 )
{
struct V_1 * V_2 = F_54 ( V_158 ) ;
F_46 ( V_2 ) ;
return 0 ;
}
