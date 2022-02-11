static int F_1 ( const char * V_1 , const struct V_2 * V_3 )
{
struct V_4 * V_5 ;
unsigned int V_6 = * ( unsigned int * ) V_3 -> V_7 ;
int V_8 ;
V_8 = F_2 ( V_1 , V_3 ) ;
if ( V_8 < 0 || V_6 == * ( unsigned int * ) V_3 -> V_7 )
return V_8 ;
F_3 ( & V_9 ) ;
F_4 (di, &bq27xxx_battery_devices, list) {
F_5 ( & V_5 -> V_10 ) ;
F_6 ( & V_5 -> V_10 , 0 ) ;
}
F_7 ( & V_9 ) ;
return V_8 ;
}
static inline int F_8 ( struct V_4 * V_5 , int V_11 ,
bool V_12 )
{
if ( ! V_5 || V_5 -> V_13 [ V_11 ] == V_14 )
return - V_15 ;
return V_5 -> V_16 . V_17 ( V_5 , V_5 -> V_13 [ V_11 ] , V_12 ) ;
}
static int F_9 ( struct V_4 * V_5 )
{
int V_18 ;
if ( V_5 -> V_19 == V_20 || V_5 -> V_19 == V_21 )
V_18 = F_8 ( V_5 , V_22 , true ) ;
else
V_18 = F_8 ( V_5 , V_22 , false ) ;
if ( V_18 < 0 )
F_10 ( V_5 -> V_23 , L_1 ) ;
return V_18 ;
}
static int F_11 ( struct V_4 * V_5 , T_1 V_24 )
{
int V_25 ;
V_25 = F_8 ( V_5 , V_24 , false ) ;
if ( V_25 < 0 ) {
F_10 ( V_5 -> V_23 , L_2 ,
V_24 , V_25 ) ;
return V_25 ;
}
if ( V_5 -> V_19 == V_20 || V_5 -> V_19 == V_21 )
V_25 *= V_26 / V_27 ;
else
V_25 *= 1000 ;
return V_25 ;
}
static inline int F_12 ( struct V_4 * V_5 )
{
int V_28 ;
if ( V_5 -> V_19 == V_20 || V_5 -> V_19 == V_21 ) {
V_28 = F_8 ( V_5 , V_29 , true ) ;
if ( V_28 >= 0 && ( V_28 & V_30 ) )
return - V_31 ;
}
return F_11 ( V_5 , V_32 ) ;
}
static inline int F_13 ( struct V_4 * V_5 )
{
return F_11 ( V_5 , V_33 ) ;
}
static int F_14 ( struct V_4 * V_5 )
{
int V_34 ;
if ( V_5 -> V_19 == V_20 || V_5 -> V_19 == V_21 )
V_34 = F_8 ( V_5 , V_35 , true ) ;
else
V_34 = F_8 ( V_5 , V_35 , false ) ;
if ( V_34 < 0 ) {
F_10 ( V_5 -> V_23 , L_3 ) ;
return V_34 ;
}
if ( V_5 -> V_19 == V_20 || V_5 -> V_19 == V_21 )
V_34 = ( V_34 << 8 ) * V_26 / V_27 ;
else
V_34 *= 1000 ;
return V_34 ;
}
static int F_15 ( struct V_4 * V_5 )
{
int V_36 ;
V_36 = F_8 ( V_5 , V_37 , false ) ;
if ( V_36 < 0 ) {
F_10 ( V_5 -> V_23 , L_4 ) ;
return V_36 ;
}
if ( V_5 -> V_19 == V_20 || V_5 -> V_19 == V_21 )
V_36 *= V_38 / V_27 ;
else
V_36 *= 1000 ;
return V_36 ;
}
static int F_16 ( struct V_4 * V_5 )
{
int V_39 ;
V_39 = F_8 ( V_5 , V_40 , false ) ;
if ( V_39 < 0 ) {
F_17 ( V_5 -> V_23 , L_5 ) ;
return V_39 ;
}
if ( V_5 -> V_19 == V_20 || V_5 -> V_19 == V_21 )
V_39 = 5 * V_39 / 2 ;
return V_39 ;
}
static int F_18 ( struct V_4 * V_5 )
{
int V_41 ;
V_41 = F_8 ( V_5 , V_42 , false ) ;
if ( V_41 < 0 )
F_17 ( V_5 -> V_23 , L_6 ) ;
return V_41 ;
}
static int F_19 ( struct V_4 * V_5 , T_1 V_24 )
{
int V_43 ;
V_43 = F_8 ( V_5 , V_24 , false ) ;
if ( V_43 < 0 ) {
F_10 ( V_5 -> V_23 , L_7 ,
V_24 , V_43 ) ;
return V_43 ;
}
if ( V_43 == 65535 )
return - V_31 ;
return V_43 * 60 ;
}
static int F_20 ( struct V_4 * V_5 )
{
int V_43 ;
V_43 = F_8 ( V_5 , V_44 , false ) ;
if ( V_43 < 0 ) {
F_17 ( V_5 -> V_23 , L_8 ,
V_44 , V_43 ) ;
return V_43 ;
}
if ( V_5 -> V_19 == V_20 || V_5 -> V_19 == V_21 )
return ( V_43 * V_38 ) / V_27 ;
else
return V_43 ;
}
static bool F_21 ( struct V_4 * V_5 , T_2 V_28 )
{
if ( V_5 -> V_19 == V_45 || V_5 -> V_19 == V_46 ||
V_5 -> V_19 == V_47 || V_5 -> V_19 == V_48 )
return V_28 & ( V_49 | V_50 ) ;
if ( V_5 -> V_19 == V_51 || V_5 -> V_19 == V_52 )
return V_28 & V_53 ;
return false ;
}
static bool F_22 ( struct V_4 * V_5 , T_2 V_28 )
{
if ( V_5 -> V_19 == V_51 || V_5 -> V_19 == V_52 )
return V_28 & V_54 ;
return false ;
}
static bool F_23 ( struct V_4 * V_5 , T_2 V_28 )
{
if ( V_5 -> V_19 == V_20 || V_5 -> V_19 == V_21 )
return V_28 & ( V_55 | V_56 ) ;
else
return V_28 & ( V_57 | V_58 ) ;
}
static int F_24 ( struct V_4 * V_5 )
{
int V_28 ;
bool V_59 = V_5 -> V_19 == V_20 || V_5 -> V_19 == V_21 ;
V_28 = F_8 ( V_5 , V_29 , V_59 ) ;
if ( V_28 < 0 ) {
F_17 ( V_5 -> V_23 , L_9 , V_28 ) ;
return V_28 ;
}
if ( F_25 ( F_21 ( V_5 , V_28 ) ) )
return V_60 ;
if ( F_25 ( F_22 ( V_5 , V_28 ) ) )
return V_61 ;
if ( F_25 ( F_23 ( V_5 , V_28 ) ) )
return V_62 ;
return V_63 ;
}
void F_26 ( struct V_4 * V_5 )
{
struct V_64 V_65 = { 0 , } ;
bool V_66 = V_5 -> V_19 == V_20 || V_5 -> V_19 == V_21 ;
bool V_59 = V_5 -> V_19 == V_20 || V_5 -> V_19 == V_21 ;
V_65 . V_28 = F_8 ( V_5 , V_29 , V_59 ) ;
if ( ( V_65 . V_28 & 0xff ) == 0xff )
V_65 . V_28 = - 1 ;
if ( V_65 . V_28 >= 0 ) {
V_65 . V_67 = F_16 ( V_5 ) ;
if ( V_66 && ( V_65 . V_28 & V_30 ) ) {
F_27 ( V_5 -> V_23 , L_10 ) ;
V_65 . V_68 = - V_31 ;
V_65 . V_69 = - V_31 ;
V_65 . V_70 = - V_31 ;
V_65 . V_71 = - V_31 ;
V_65 . V_72 = - V_31 ;
V_65 . V_73 = - V_31 ;
V_65 . V_74 = - V_31 ;
} else {
if ( V_5 -> V_13 [ V_75 ] != V_14 )
V_65 . V_70 = F_19 ( V_5 , V_75 ) ;
if ( V_5 -> V_13 [ V_76 ] != V_14 )
V_65 . V_71 = F_19 ( V_5 , V_76 ) ;
if ( V_5 -> V_13 [ V_77 ] != V_14 )
V_65 . V_72 = F_19 ( V_5 , V_77 ) ;
V_65 . V_73 = F_13 ( V_5 ) ;
V_65 . V_68 = F_9 ( V_5 ) ;
if ( V_5 -> V_13 [ V_37 ] != V_14 )
V_65 . V_69 = F_15 ( V_5 ) ;
V_65 . V_74 = F_24 ( V_5 ) ;
}
if ( V_5 -> V_13 [ V_42 ] != V_14 )
V_65 . V_78 = F_18 ( V_5 ) ;
if ( V_5 -> V_13 [ V_44 ] != V_14 )
V_65 . V_79 = F_20 ( V_5 ) ;
if ( V_5 -> V_80 <= 0 )
V_5 -> V_80 = F_14 ( V_5 ) ;
}
if ( V_5 -> V_65 . V_68 != V_65 . V_68 )
F_28 ( V_5 -> V_81 ) ;
if ( memcmp ( & V_5 -> V_65 , & V_65 , sizeof( V_65 ) ) != 0 )
V_5 -> V_65 = V_65 ;
V_5 -> V_82 = V_83 ;
}
static void F_29 ( struct V_84 * V_10 )
{
struct V_4 * V_5 =
F_30 ( V_10 , struct V_4 ,
V_10 . V_10 ) ;
F_26 ( V_5 ) ;
if ( V_85 > 0 )
F_6 ( & V_5 -> V_10 , V_85 * V_86 ) ;
}
static int F_31 ( struct V_4 * V_5 ,
union V_87 * V_1 )
{
int V_88 ;
int V_28 ;
V_88 = F_8 ( V_5 , V_89 , false ) ;
if ( V_88 < 0 ) {
F_17 ( V_5 -> V_23 , L_11 ) ;
return V_88 ;
}
if ( V_5 -> V_19 == V_20 || V_5 -> V_19 == V_21 ) {
V_28 = F_8 ( V_5 , V_29 , true ) ;
if ( V_28 & V_90 ) {
F_10 ( V_5 -> V_23 , L_12 ) ;
V_88 = - V_88 ;
}
V_1 -> V_91 = V_88 * V_26 / V_27 ;
} else {
V_1 -> V_91 = ( int ) ( ( V_92 ) V_88 ) * 1000 ;
}
return 0 ;
}
static int F_32 ( struct V_4 * V_5 ,
union V_87 * V_1 )
{
int V_93 ;
if ( V_5 -> V_19 == V_20 || V_5 -> V_19 == V_21 ) {
if ( V_5 -> V_65 . V_28 & V_94 )
V_93 = V_95 ;
else if ( V_5 -> V_65 . V_28 & V_90 )
V_93 = V_96 ;
else if ( F_33 ( V_5 -> V_81 ) )
V_93 = V_97 ;
else
V_93 = V_98 ;
} else {
if ( V_5 -> V_65 . V_28 & V_99 )
V_93 = V_95 ;
else if ( V_5 -> V_65 . V_28 & V_100 )
V_93 = V_98 ;
else
V_93 = V_96 ;
}
V_1 -> V_91 = V_93 ;
return 0 ;
}
static int F_34 ( struct V_4 * V_5 ,
union V_87 * V_1 )
{
int V_101 ;
if ( V_5 -> V_19 == V_20 || V_5 -> V_19 == V_21 ) {
if ( V_5 -> V_65 . V_28 & V_94 )
V_101 = V_102 ;
else if ( V_5 -> V_65 . V_28 & V_55 )
V_101 = V_103 ;
else if ( V_5 -> V_65 . V_28 & V_56 )
V_101 = V_104 ;
else
V_101 = V_105 ;
} else {
if ( V_5 -> V_65 . V_28 & V_99 )
V_101 = V_102 ;
else if ( V_5 -> V_65 . V_28 & V_57 )
V_101 = V_103 ;
else if ( V_5 -> V_65 . V_28 & V_58 )
V_101 = V_104 ;
else
V_101 = V_105 ;
}
V_1 -> V_91 = V_101 ;
return 0 ;
}
static int F_35 ( struct V_4 * V_5 ,
union V_87 * V_1 )
{
int V_106 ;
V_106 = F_8 ( V_5 , V_107 , false ) ;
if ( V_106 < 0 ) {
F_17 ( V_5 -> V_23 , L_13 ) ;
return V_106 ;
}
V_1 -> V_91 = V_106 * 1000 ;
return 0 ;
}
static int F_36 ( int V_108 ,
union V_87 * V_1 )
{
if ( V_108 < 0 )
return V_108 ;
V_1 -> V_91 = V_108 ;
return 0 ;
}
static int F_37 ( struct V_109 * V_110 ,
enum V_111 V_112 ,
union V_87 * V_1 )
{
int V_8 = 0 ;
struct V_4 * V_5 = F_38 ( V_110 ) ;
F_3 ( & V_5 -> V_113 ) ;
if ( F_39 ( V_5 -> V_82 + 5 * V_86 ) ) {
F_5 ( & V_5 -> V_10 ) ;
F_29 ( & V_5 -> V_10 . V_10 ) ;
}
F_7 ( & V_5 -> V_113 ) ;
if ( V_112 != V_114 && V_5 -> V_65 . V_28 < 0 )
return - V_115 ;
switch ( V_112 ) {
case V_116 :
V_8 = F_32 ( V_5 , V_1 ) ;
break;
case V_117 :
V_8 = F_35 ( V_5 , V_1 ) ;
break;
case V_114 :
V_1 -> V_91 = V_5 -> V_65 . V_28 < 0 ? 0 : 1 ;
break;
case V_118 :
V_8 = F_31 ( V_5 , V_1 ) ;
break;
case V_119 :
V_8 = F_36 ( V_5 -> V_65 . V_68 , V_1 ) ;
break;
case V_120 :
V_8 = F_34 ( V_5 , V_1 ) ;
break;
case V_121 :
V_8 = F_36 ( V_5 -> V_65 . V_67 , V_1 ) ;
if ( V_8 == 0 )
V_1 -> V_91 -= 2731 ;
break;
case V_122 :
V_8 = F_36 ( V_5 -> V_65 . V_70 , V_1 ) ;
break;
case V_123 :
V_8 = F_36 ( V_5 -> V_65 . V_71 , V_1 ) ;
break;
case V_124 :
V_8 = F_36 ( V_5 -> V_65 . V_72 , V_1 ) ;
break;
case V_125 :
V_1 -> V_91 = V_126 ;
break;
case V_127 :
V_8 = F_36 ( F_12 ( V_5 ) , V_1 ) ;
break;
case V_128 :
V_8 = F_36 ( V_5 -> V_65 . V_73 , V_1 ) ;
break;
case V_129 :
V_8 = F_36 ( V_5 -> V_80 , V_1 ) ;
break;
case V_130 :
V_8 = F_36 ( V_5 -> V_65 . V_78 , V_1 ) ;
break;
case V_131 :
V_8 = F_36 ( V_5 -> V_65 . V_69 , V_1 ) ;
break;
case V_132 :
V_8 = F_36 ( V_5 -> V_65 . V_79 , V_1 ) ;
break;
case V_133 :
V_8 = F_36 ( V_5 -> V_65 . V_74 , V_1 ) ;
break;
case V_134 :
V_1 -> V_135 = V_136 ;
break;
default:
return - V_15 ;
}
return V_8 ;
}
static void F_40 ( struct V_109 * V_110 )
{
struct V_4 * V_5 = F_38 ( V_110 ) ;
F_5 ( & V_5 -> V_10 ) ;
F_6 ( & V_5 -> V_10 , 0 ) ;
}
int F_41 ( struct V_4 * V_5 )
{
struct V_137 * V_138 ;
struct V_139 V_140 = { . V_141 = V_5 , } ;
F_42 ( & V_5 -> V_10 , F_29 ) ;
F_43 ( & V_5 -> V_113 ) ;
V_5 -> V_13 = V_142 [ V_5 -> V_19 ] ;
V_138 = F_44 ( V_5 -> V_23 , sizeof( * V_138 ) , V_143 ) ;
if ( ! V_138 )
return - V_144 ;
V_138 -> V_145 = V_5 -> V_145 ;
V_138 -> type = V_146 ;
V_138 -> V_147 = V_148 [ V_5 -> V_19 ] . V_149 ;
V_138 -> V_150 = V_148 [ V_5 -> V_19 ] . V_151 ;
V_138 -> V_152 = F_37 ;
V_138 -> V_153 = F_40 ;
V_5 -> V_81 = F_45 ( V_5 -> V_23 , V_138 , & V_140 ) ;
if ( F_46 ( V_5 -> V_81 ) ) {
F_17 ( V_5 -> V_23 , L_14 ) ;
return F_47 ( V_5 -> V_81 ) ;
}
F_48 ( V_5 -> V_23 , L_15 , V_154 ) ;
F_26 ( V_5 ) ;
F_3 ( & V_9 ) ;
F_49 ( & V_5 -> V_155 , & V_156 ) ;
F_7 ( & V_9 ) ;
return 0 ;
}
void F_50 ( struct V_4 * V_5 )
{
V_85 = 0 ;
F_5 ( & V_5 -> V_10 ) ;
F_51 ( V_5 -> V_81 ) ;
F_3 ( & V_9 ) ;
F_52 ( & V_5 -> V_155 ) ;
F_7 ( & V_9 ) ;
F_53 ( & V_5 -> V_113 ) ;
}
static int F_54 ( struct V_4 * V_5 , T_1 V_24 ,
bool V_12 )
{
struct V_157 * V_23 = V_5 -> V_23 ;
struct V_158 * V_159 = V_23 -> V_160 ;
unsigned int V_161 = 3 ;
int V_162 , V_163 ;
int V_39 ;
if ( ! V_12 ) {
V_162 = V_159 -> V_17 ( V_23 , V_24 + 1 ) ;
do {
V_39 = V_162 ;
if ( V_162 < 0 )
return V_162 ;
V_163 = V_159 -> V_17 ( V_23 , V_24 ) ;
if ( V_163 < 0 )
return V_163 ;
V_162 = V_159 -> V_17 ( V_23 , V_24 + 1 ) ;
} while ( V_39 != V_162 && -- V_161 );
if ( V_161 == 0 )
return - V_164 ;
return ( V_162 << 8 ) | V_163 ;
}
return V_159 -> V_17 ( V_23 , V_24 ) ;
}
static int F_55 ( struct V_165 * V_166 )
{
struct V_4 * V_5 ;
struct V_158 * V_159 = V_166 -> V_23 . V_160 ;
if ( ! V_159 ) {
F_17 ( & V_166 -> V_23 , L_16 ) ;
return - V_15 ;
}
if ( ! V_159 -> V_17 ) {
F_17 ( & V_166 -> V_23 , L_17 ) ;
return - V_15 ;
}
if ( ! V_159 -> V_19 ) {
F_17 ( & V_166 -> V_23 , L_18 ) ;
return - V_15 ;
}
V_5 = F_44 ( & V_166 -> V_23 , sizeof( * V_5 ) , V_143 ) ;
if ( ! V_5 )
return - V_144 ;
F_56 ( V_166 , V_5 ) ;
V_5 -> V_23 = & V_166 -> V_23 ;
V_5 -> V_19 = V_159 -> V_19 ;
V_5 -> V_145 = V_159 -> V_145 ? : F_57 ( & V_166 -> V_23 ) ;
V_5 -> V_16 . V_17 = F_54 ;
return F_41 ( V_5 ) ;
}
static int F_58 ( struct V_165 * V_166 )
{
struct V_4 * V_5 = F_59 ( V_166 ) ;
F_50 ( V_5 ) ;
return 0 ;
}
