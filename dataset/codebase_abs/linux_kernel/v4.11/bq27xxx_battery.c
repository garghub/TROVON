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
switch ( V_5 -> V_19 ) {
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
return V_28 & ( V_57 | V_58 ) ;
case V_59 :
case V_60 :
return V_28 & V_61 ;
default:
return false ;
}
}
static bool F_22 ( struct V_4 * V_5 , T_2 V_28 )
{
if ( V_5 -> V_19 == V_59 || V_5 -> V_19 == V_60 )
return V_28 & V_62 ;
return false ;
}
static bool F_23 ( struct V_4 * V_5 , T_2 V_28 )
{
if ( V_5 -> V_19 == V_20 || V_5 -> V_19 == V_21 )
return V_28 & ( V_63 | V_64 ) ;
else
return V_28 & ( V_65 | V_66 ) ;
}
static int F_24 ( struct V_4 * V_5 )
{
int V_28 ;
bool V_67 = V_5 -> V_19 == V_20 || V_5 -> V_19 == V_21 ;
V_28 = F_8 ( V_5 , V_29 , V_67 ) ;
if ( V_28 < 0 ) {
F_17 ( V_5 -> V_23 , L_9 , V_28 ) ;
return V_28 ;
}
if ( F_25 ( F_21 ( V_5 , V_28 ) ) )
return V_68 ;
if ( F_25 ( F_22 ( V_5 , V_28 ) ) )
return V_69 ;
if ( F_25 ( F_23 ( V_5 , V_28 ) ) )
return V_70 ;
return V_71 ;
}
void F_26 ( struct V_4 * V_5 )
{
struct V_72 V_73 = { 0 , } ;
bool V_74 = V_5 -> V_19 == V_20 || V_5 -> V_19 == V_21 ;
bool V_67 = V_5 -> V_19 == V_20 || V_5 -> V_19 == V_21 ;
V_73 . V_28 = F_8 ( V_5 , V_29 , V_67 ) ;
if ( ( V_73 . V_28 & 0xff ) == 0xff )
V_73 . V_28 = - 1 ;
if ( V_73 . V_28 >= 0 ) {
V_73 . V_75 = F_16 ( V_5 ) ;
if ( V_74 && ( V_73 . V_28 & V_30 ) ) {
F_27 ( V_5 -> V_23 , L_10 ) ;
V_73 . V_76 = - V_31 ;
V_73 . V_77 = - V_31 ;
V_73 . V_78 = - V_31 ;
V_73 . V_79 = - V_31 ;
V_73 . V_80 = - V_31 ;
V_73 . V_81 = - V_31 ;
V_73 . V_82 = - V_31 ;
} else {
if ( V_5 -> V_13 [ V_83 ] != V_14 )
V_73 . V_78 = F_19 ( V_5 , V_83 ) ;
if ( V_5 -> V_13 [ V_84 ] != V_14 )
V_73 . V_79 = F_19 ( V_5 , V_84 ) ;
if ( V_5 -> V_13 [ V_85 ] != V_14 )
V_73 . V_80 = F_19 ( V_5 , V_85 ) ;
V_73 . V_81 = F_13 ( V_5 ) ;
V_73 . V_76 = F_9 ( V_5 ) ;
if ( V_5 -> V_13 [ V_37 ] != V_14 )
V_73 . V_77 = F_15 ( V_5 ) ;
V_73 . V_82 = F_24 ( V_5 ) ;
}
if ( V_5 -> V_13 [ V_42 ] != V_14 )
V_73 . V_86 = F_18 ( V_5 ) ;
if ( V_5 -> V_13 [ V_44 ] != V_14 )
V_73 . V_87 = F_20 ( V_5 ) ;
if ( V_5 -> V_88 <= 0 )
V_5 -> V_88 = F_14 ( V_5 ) ;
}
if ( V_5 -> V_73 . V_76 != V_73 . V_76 )
F_28 ( V_5 -> V_89 ) ;
if ( memcmp ( & V_5 -> V_73 , & V_73 , sizeof( V_73 ) ) != 0 )
V_5 -> V_73 = V_73 ;
V_5 -> V_90 = V_91 ;
}
static void F_29 ( struct V_92 * V_10 )
{
struct V_4 * V_5 =
F_30 ( V_10 , struct V_4 ,
V_10 . V_10 ) ;
F_26 ( V_5 ) ;
if ( V_93 > 0 )
F_6 ( & V_5 -> V_10 , V_93 * V_94 ) ;
}
static int F_31 ( struct V_4 * V_5 ,
union V_95 * V_1 )
{
int V_96 ;
int V_28 ;
V_96 = F_8 ( V_5 , V_97 , false ) ;
if ( V_96 < 0 ) {
F_17 ( V_5 -> V_23 , L_11 ) ;
return V_96 ;
}
if ( V_5 -> V_19 == V_20 || V_5 -> V_19 == V_21 ) {
V_28 = F_8 ( V_5 , V_29 , true ) ;
if ( V_28 & V_98 ) {
F_10 ( V_5 -> V_23 , L_12 ) ;
V_96 = - V_96 ;
}
V_1 -> V_99 = V_96 * V_26 / V_27 ;
} else {
V_1 -> V_99 = ( int ) ( ( V_100 ) V_96 ) * 1000 ;
}
return 0 ;
}
static int F_32 ( struct V_4 * V_5 ,
union V_95 * V_1 )
{
int V_101 ;
if ( V_5 -> V_19 == V_20 || V_5 -> V_19 == V_21 ) {
if ( V_5 -> V_73 . V_28 & V_102 )
V_101 = V_103 ;
else if ( V_5 -> V_73 . V_28 & V_98 )
V_101 = V_104 ;
else if ( F_33 ( V_5 -> V_89 ) )
V_101 = V_105 ;
else
V_101 = V_106 ;
} else {
if ( V_5 -> V_73 . V_28 & V_107 )
V_101 = V_103 ;
else if ( V_5 -> V_73 . V_28 & V_108 )
V_101 = V_106 ;
else
V_101 = V_104 ;
}
V_1 -> V_99 = V_101 ;
return 0 ;
}
static int F_34 ( struct V_4 * V_5 ,
union V_95 * V_1 )
{
int V_109 ;
if ( V_5 -> V_19 == V_20 || V_5 -> V_19 == V_21 ) {
if ( V_5 -> V_73 . V_28 & V_102 )
V_109 = V_110 ;
else if ( V_5 -> V_73 . V_28 & V_63 )
V_109 = V_111 ;
else if ( V_5 -> V_73 . V_28 & V_64 )
V_109 = V_112 ;
else
V_109 = V_113 ;
} else {
if ( V_5 -> V_73 . V_28 & V_107 )
V_109 = V_110 ;
else if ( V_5 -> V_73 . V_28 & V_65 )
V_109 = V_111 ;
else if ( V_5 -> V_73 . V_28 & V_66 )
V_109 = V_112 ;
else
V_109 = V_113 ;
}
V_1 -> V_99 = V_109 ;
return 0 ;
}
static int F_35 ( struct V_4 * V_5 ,
union V_95 * V_1 )
{
int V_114 ;
V_114 = F_8 ( V_5 , V_115 , false ) ;
if ( V_114 < 0 ) {
F_17 ( V_5 -> V_23 , L_13 ) ;
return V_114 ;
}
V_1 -> V_99 = V_114 * 1000 ;
return 0 ;
}
static int F_36 ( int V_116 ,
union V_95 * V_1 )
{
if ( V_116 < 0 )
return V_116 ;
V_1 -> V_99 = V_116 ;
return 0 ;
}
static int F_37 ( struct V_117 * V_118 ,
enum V_119 V_120 ,
union V_95 * V_1 )
{
int V_8 = 0 ;
struct V_4 * V_5 = F_38 ( V_118 ) ;
F_3 ( & V_5 -> V_121 ) ;
if ( F_39 ( V_5 -> V_90 + 5 * V_94 ) ) {
F_5 ( & V_5 -> V_10 ) ;
F_29 ( & V_5 -> V_10 . V_10 ) ;
}
F_7 ( & V_5 -> V_121 ) ;
if ( V_120 != V_122 && V_5 -> V_73 . V_28 < 0 )
return - V_123 ;
switch ( V_120 ) {
case V_124 :
V_8 = F_32 ( V_5 , V_1 ) ;
break;
case V_125 :
V_8 = F_35 ( V_5 , V_1 ) ;
break;
case V_122 :
V_1 -> V_99 = V_5 -> V_73 . V_28 < 0 ? 0 : 1 ;
break;
case V_126 :
V_8 = F_31 ( V_5 , V_1 ) ;
break;
case V_127 :
V_8 = F_36 ( V_5 -> V_73 . V_76 , V_1 ) ;
break;
case V_128 :
V_8 = F_34 ( V_5 , V_1 ) ;
break;
case V_129 :
V_8 = F_36 ( V_5 -> V_73 . V_75 , V_1 ) ;
if ( V_8 == 0 )
V_1 -> V_99 -= 2731 ;
break;
case V_130 :
V_8 = F_36 ( V_5 -> V_73 . V_78 , V_1 ) ;
break;
case V_131 :
V_8 = F_36 ( V_5 -> V_73 . V_79 , V_1 ) ;
break;
case V_132 :
V_8 = F_36 ( V_5 -> V_73 . V_80 , V_1 ) ;
break;
case V_133 :
V_1 -> V_99 = V_134 ;
break;
case V_135 :
V_8 = F_36 ( F_12 ( V_5 ) , V_1 ) ;
break;
case V_136 :
V_8 = F_36 ( V_5 -> V_73 . V_81 , V_1 ) ;
break;
case V_137 :
V_8 = F_36 ( V_5 -> V_88 , V_1 ) ;
break;
case V_138 :
V_8 = F_36 ( V_5 -> V_73 . V_86 , V_1 ) ;
break;
case V_139 :
V_8 = F_36 ( V_5 -> V_73 . V_77 , V_1 ) ;
break;
case V_140 :
V_8 = F_36 ( V_5 -> V_73 . V_87 , V_1 ) ;
break;
case V_141 :
V_8 = F_36 ( V_5 -> V_73 . V_82 , V_1 ) ;
break;
case V_142 :
V_1 -> V_143 = V_144 ;
break;
default:
return - V_15 ;
}
return V_8 ;
}
static void F_40 ( struct V_117 * V_118 )
{
struct V_4 * V_5 = F_38 ( V_118 ) ;
F_5 ( & V_5 -> V_10 ) ;
F_6 ( & V_5 -> V_10 , 0 ) ;
}
int F_41 ( struct V_4 * V_5 )
{
struct V_145 * V_146 ;
struct V_147 V_148 = { . V_149 = V_5 , } ;
F_42 ( & V_5 -> V_10 , F_29 ) ;
F_43 ( & V_5 -> V_121 ) ;
V_5 -> V_13 = V_150 [ V_5 -> V_19 ] ;
V_146 = F_44 ( V_5 -> V_23 , sizeof( * V_146 ) , V_151 ) ;
if ( ! V_146 )
return - V_152 ;
V_146 -> V_153 = V_5 -> V_153 ;
V_146 -> type = V_154 ;
V_146 -> V_155 = V_156 [ V_5 -> V_19 ] . V_157 ;
V_146 -> V_158 = V_156 [ V_5 -> V_19 ] . V_159 ;
V_146 -> V_160 = F_37 ;
V_146 -> V_161 = F_40 ;
V_5 -> V_89 = F_45 ( V_5 -> V_23 , V_146 , & V_148 ) ;
if ( F_46 ( V_5 -> V_89 ) ) {
F_17 ( V_5 -> V_23 , L_14 ) ;
return F_47 ( V_5 -> V_89 ) ;
}
F_48 ( V_5 -> V_23 , L_15 , V_162 ) ;
F_26 ( V_5 ) ;
F_3 ( & V_9 ) ;
F_49 ( & V_5 -> V_163 , & V_164 ) ;
F_7 ( & V_9 ) ;
return 0 ;
}
void F_50 ( struct V_4 * V_5 )
{
V_93 = 0 ;
F_5 ( & V_5 -> V_10 ) ;
F_51 ( V_5 -> V_89 ) ;
F_3 ( & V_9 ) ;
F_52 ( & V_5 -> V_163 ) ;
F_7 ( & V_9 ) ;
F_53 ( & V_5 -> V_121 ) ;
}
static int F_54 ( struct V_4 * V_5 , T_1 V_24 ,
bool V_12 )
{
struct V_165 * V_23 = V_5 -> V_23 ;
struct V_166 * V_167 = V_23 -> V_168 ;
unsigned int V_169 = 3 ;
int V_170 , V_171 ;
int V_39 ;
if ( ! V_12 ) {
V_170 = V_167 -> V_17 ( V_23 , V_24 + 1 ) ;
do {
V_39 = V_170 ;
if ( V_170 < 0 )
return V_170 ;
V_171 = V_167 -> V_17 ( V_23 , V_24 ) ;
if ( V_171 < 0 )
return V_171 ;
V_170 = V_167 -> V_17 ( V_23 , V_24 + 1 ) ;
} while ( V_39 != V_170 && -- V_169 );
if ( V_169 == 0 )
return - V_172 ;
return ( V_170 << 8 ) | V_171 ;
}
return V_167 -> V_17 ( V_23 , V_24 ) ;
}
static int F_55 ( struct V_173 * V_174 )
{
struct V_4 * V_5 ;
struct V_166 * V_167 = V_174 -> V_23 . V_168 ;
if ( ! V_167 ) {
F_17 ( & V_174 -> V_23 , L_16 ) ;
return - V_15 ;
}
if ( ! V_167 -> V_17 ) {
F_17 ( & V_174 -> V_23 , L_17 ) ;
return - V_15 ;
}
if ( ! V_167 -> V_19 ) {
F_17 ( & V_174 -> V_23 , L_18 ) ;
return - V_15 ;
}
V_5 = F_44 ( & V_174 -> V_23 , sizeof( * V_5 ) , V_151 ) ;
if ( ! V_5 )
return - V_152 ;
F_56 ( V_174 , V_5 ) ;
V_5 -> V_23 = & V_174 -> V_23 ;
V_5 -> V_19 = V_167 -> V_19 ;
V_5 -> V_153 = V_167 -> V_153 ? : F_57 ( & V_174 -> V_23 ) ;
V_5 -> V_16 . V_17 = F_54 ;
return F_41 ( V_5 ) ;
}
static int F_58 ( struct V_173 * V_174 )
{
struct V_4 * V_5 = F_59 ( V_174 ) ;
F_50 ( V_5 ) ;
return 0 ;
}
