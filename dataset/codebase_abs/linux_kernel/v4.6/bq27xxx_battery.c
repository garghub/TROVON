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
if ( V_77 > 0 ) {
F_24 ( & V_2 -> V_76 . V_78 , V_77 * V_79 / 4 ) ;
F_25 ( & V_2 -> V_76 , V_77 * V_79 ) ;
}
}
static int F_26 ( struct V_1 * V_2 ,
union V_80 * V_81 )
{
int V_82 ;
int V_20 ;
V_82 = F_1 ( V_2 , V_83 , false ) ;
if ( V_82 < 0 ) {
F_10 ( V_2 -> V_15 , L_11 ) ;
return V_82 ;
}
if ( V_2 -> V_11 == V_12 || V_2 -> V_11 == V_13 ) {
V_20 = F_1 ( V_2 , V_21 , false ) ;
if ( V_20 & V_84 ) {
F_3 ( V_2 -> V_15 , L_12 ) ;
V_82 = - V_82 ;
}
V_81 -> V_85 = V_82 * V_18 / V_19 ;
} else {
V_81 -> V_85 = ( int ) ( ( V_86 ) V_82 ) * 1000 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
union V_80 * V_81 )
{
int V_87 ;
if ( V_2 -> V_11 == V_12 || V_2 -> V_11 == V_13 ) {
if ( V_2 -> V_55 . V_20 & V_88 )
V_87 = V_89 ;
else if ( V_2 -> V_55 . V_20 & V_84 )
V_87 = V_90 ;
else if ( F_28 ( V_2 -> V_72 ) )
V_87 = V_91 ;
else
V_87 = V_92 ;
} else {
if ( V_2 -> V_55 . V_20 & V_93 )
V_87 = V_89 ;
else if ( V_2 -> V_55 . V_20 & V_94 )
V_87 = V_92 ;
else
V_87 = V_90 ;
}
V_81 -> V_85 = V_87 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
union V_80 * V_81 )
{
int V_95 ;
if ( V_2 -> V_11 == V_12 || V_2 -> V_11 == V_13 ) {
if ( V_2 -> V_55 . V_20 & V_88 )
V_95 = V_96 ;
else if ( V_2 -> V_55 . V_20 & V_46 )
V_95 = V_97 ;
else if ( V_2 -> V_55 . V_20 & V_47 )
V_95 = V_98 ;
else
V_95 = V_99 ;
} else {
if ( V_2 -> V_55 . V_20 & V_93 )
V_95 = V_96 ;
else if ( V_2 -> V_55 . V_20 & V_48 )
V_95 = V_97 ;
else if ( V_2 -> V_55 . V_20 & V_49 )
V_95 = V_98 ;
else
V_95 = V_99 ;
}
V_81 -> V_85 = V_95 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
union V_80 * V_81 )
{
int V_100 ;
V_100 = F_1 ( V_2 , V_101 , false ) ;
if ( V_100 < 0 ) {
F_10 ( V_2 -> V_15 , L_13 ) ;
return V_100 ;
}
V_81 -> V_85 = V_100 * 1000 ;
return 0 ;
}
static int F_31 ( int V_102 ,
union V_80 * V_81 )
{
if ( V_102 < 0 )
return V_102 ;
V_81 -> V_85 = V_102 ;
return 0 ;
}
static int F_32 ( struct V_103 * V_104 ,
enum V_105 V_106 ,
union V_80 * V_81 )
{
int V_107 = 0 ;
struct V_1 * V_2 = F_33 ( V_104 ) ;
F_34 ( & V_2 -> V_108 ) ;
if ( F_35 ( V_2 -> V_73 + 5 * V_79 ) ) {
F_36 ( & V_2 -> V_76 ) ;
F_22 ( & V_2 -> V_76 . V_76 ) ;
}
F_37 ( & V_2 -> V_108 ) ;
if ( V_106 != V_109 && V_2 -> V_55 . V_20 < 0 )
return - V_110 ;
switch ( V_106 ) {
case V_111 :
V_107 = F_27 ( V_2 , V_81 ) ;
break;
case V_112 :
V_107 = F_30 ( V_2 , V_81 ) ;
break;
case V_109 :
V_81 -> V_85 = V_2 -> V_55 . V_20 < 0 ? 0 : 1 ;
break;
case V_113 :
V_107 = F_26 ( V_2 , V_81 ) ;
break;
case V_114 :
V_107 = F_31 ( V_2 -> V_55 . V_59 , V_81 ) ;
break;
case V_115 :
V_107 = F_29 ( V_2 , V_81 ) ;
break;
case V_116 :
V_107 = F_31 ( V_2 -> V_55 . V_58 , V_81 ) ;
if ( V_107 == 0 )
V_81 -> V_85 -= 2731 ;
break;
case V_117 :
V_107 = F_31 ( V_2 -> V_55 . V_61 , V_81 ) ;
break;
case V_118 :
V_107 = F_31 ( V_2 -> V_55 . V_62 , V_81 ) ;
break;
case V_119 :
V_107 = F_31 ( V_2 -> V_55 . V_63 , V_81 ) ;
break;
case V_120 :
V_81 -> V_85 = V_121 ;
break;
case V_122 :
V_107 = F_31 ( F_5 ( V_2 ) , V_81 ) ;
break;
case V_123 :
V_107 = F_31 ( V_2 -> V_55 . V_64 , V_81 ) ;
break;
case V_124 :
V_107 = F_31 ( V_2 -> V_71 , V_81 ) ;
break;
case V_125 :
V_107 = F_31 ( V_2 -> V_55 . V_69 , V_81 ) ;
break;
case V_126 :
V_107 = F_31 ( V_2 -> V_55 . V_60 , V_81 ) ;
break;
case V_127 :
V_107 = F_31 ( V_2 -> V_55 . V_70 , V_81 ) ;
break;
case V_128 :
V_107 = F_31 ( V_2 -> V_55 . V_65 , V_81 ) ;
break;
case V_129 :
V_81 -> V_130 = V_131 ;
break;
default:
return - V_7 ;
}
return V_107 ;
}
static void F_38 ( struct V_103 * V_104 )
{
struct V_1 * V_2 = F_33 ( V_104 ) ;
F_36 ( & V_2 -> V_76 ) ;
F_25 ( & V_2 -> V_76 , 0 ) ;
}
int F_39 ( struct V_1 * V_2 )
{
struct V_132 * V_133 ;
struct V_134 V_135 = { . V_136 = V_2 , } ;
F_40 ( & V_2 -> V_76 , F_22 ) ;
F_41 ( & V_2 -> V_108 ) ;
V_2 -> V_5 = V_137 [ V_2 -> V_11 ] ;
V_133 = F_42 ( V_2 -> V_15 , sizeof( * V_133 ) , V_138 ) ;
if ( ! V_133 )
return - V_139 ;
V_133 -> V_140 = V_2 -> V_140 ;
V_133 -> type = V_141 ;
V_133 -> V_142 = V_143 [ V_2 -> V_11 ] . V_144 ;
V_133 -> V_145 = V_143 [ V_2 -> V_11 ] . V_146 ;
V_133 -> V_147 = F_32 ;
V_133 -> V_148 = F_38 ;
V_2 -> V_72 = F_43 ( V_2 -> V_15 , V_133 , & V_135 ) ;
if ( F_44 ( V_2 -> V_72 ) ) {
F_10 ( V_2 -> V_15 , L_14 ) ;
return F_45 ( V_2 -> V_72 ) ;
}
F_46 ( V_2 -> V_15 , L_15 , V_149 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
void F_47 ( struct V_1 * V_2 )
{
V_77 = 0 ;
F_36 ( & V_2 -> V_76 ) ;
F_48 ( V_2 -> V_72 ) ;
F_49 ( & V_2 -> V_108 ) ;
}
static int F_50 ( struct V_1 * V_2 , T_1 V_16 ,
bool V_4 )
{
struct V_150 * V_15 = V_2 -> V_15 ;
struct V_151 * V_152 = V_15 -> V_153 ;
unsigned int V_154 = 3 ;
int V_155 , V_156 ;
int V_31 ;
if ( ! V_4 ) {
V_155 = V_152 -> V_9 ( V_15 , V_16 + 1 ) ;
do {
V_31 = V_155 ;
if ( V_155 < 0 )
return V_155 ;
V_156 = V_152 -> V_9 ( V_15 , V_16 ) ;
if ( V_156 < 0 )
return V_156 ;
V_155 = V_152 -> V_9 ( V_15 , V_16 + 1 ) ;
} while ( V_31 != V_155 && -- V_154 );
if ( V_154 == 0 )
return - V_157 ;
return ( V_155 << 8 ) | V_156 ;
}
return V_152 -> V_9 ( V_15 , V_16 ) ;
}
static int F_51 ( struct V_158 * V_159 )
{
struct V_1 * V_2 ;
struct V_151 * V_152 = V_159 -> V_15 . V_153 ;
if ( ! V_152 ) {
F_10 ( & V_159 -> V_15 , L_16 ) ;
return - V_7 ;
}
if ( ! V_152 -> V_9 ) {
F_10 ( & V_159 -> V_15 , L_17 ) ;
return - V_7 ;
}
if ( ! V_152 -> V_11 ) {
F_10 ( & V_159 -> V_15 , L_18 ) ;
return - V_7 ;
}
V_2 = F_42 ( & V_159 -> V_15 , sizeof( * V_2 ) , V_138 ) ;
if ( ! V_2 )
return - V_139 ;
F_52 ( V_159 , V_2 ) ;
V_2 -> V_15 = & V_159 -> V_15 ;
V_2 -> V_11 = V_152 -> V_11 ;
V_2 -> V_140 = V_152 -> V_140 ? : F_53 ( & V_159 -> V_15 ) ;
V_2 -> V_8 . V_9 = F_50 ;
return F_39 ( V_2 ) ;
}
static int F_54 ( struct V_158 * V_159 )
{
struct V_1 * V_2 = F_55 ( V_159 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
