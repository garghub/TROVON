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
V_10 = F_1 ( V_2 , V_11 , false ) ;
if ( V_10 < 0 )
F_3 ( V_2 -> V_12 , L_1 ) ;
return V_10 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_13 )
{
int V_14 ;
V_14 = F_1 ( V_2 , V_13 , false ) ;
if ( V_14 < 0 ) {
F_3 ( V_2 -> V_12 , L_2 ,
V_13 , V_14 ) ;
return V_14 ;
}
if ( V_2 -> V_15 == V_16 || V_2 -> V_15 == V_17 )
V_14 *= V_18 / V_19 ;
else
V_14 *= 1000 ;
return V_14 ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
int V_20 ;
if ( V_2 -> V_15 == V_16 || V_2 -> V_15 == V_17 ) {
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
V_26 = F_1 ( V_2 , V_27 , false ) ;
if ( V_26 < 0 ) {
F_3 ( V_2 -> V_12 , L_3 ) ;
return V_26 ;
}
if ( V_2 -> V_15 == V_16 || V_2 -> V_15 == V_17 )
V_26 *= V_18 / V_19 ;
else
V_26 *= 1000 ;
return V_26 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_28 ;
V_28 = F_1 ( V_2 , V_29 , false ) ;
if ( V_28 < 0 ) {
F_3 ( V_2 -> V_12 , L_4 ) ;
return V_28 ;
}
if ( V_2 -> V_15 == V_16 || V_2 -> V_15 == V_17 )
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
F_10 ( V_2 -> V_12 , L_5 ) ;
return V_31 ;
}
if ( V_2 -> V_15 == V_16 || V_2 -> V_15 == V_17 )
V_31 = 5 * V_31 / 2 ;
return V_31 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_33 ;
V_33 = F_1 ( V_2 , V_34 , false ) ;
if ( V_33 < 0 )
F_10 ( V_2 -> V_12 , L_6 ) ;
return V_33 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_13 )
{
int V_35 ;
V_35 = F_1 ( V_2 , V_13 , false ) ;
if ( V_35 < 0 ) {
F_3 ( V_2 -> V_12 , L_7 ,
V_13 , V_35 ) ;
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
F_10 ( V_2 -> V_12 , L_8 ,
V_36 , V_35 ) ;
return V_35 ;
}
if ( V_2 -> V_15 == V_16 || V_2 -> V_15 == V_17 )
return ( V_35 * V_30 ) / V_19 ;
else
return V_35 ;
}
static bool F_14 ( struct V_1 * V_2 , T_2 V_20 )
{
if ( V_2 -> V_15 == V_37 || V_2 -> V_15 == V_38 || V_2 -> V_15 == V_39 )
return V_20 & ( V_40 | V_41 ) ;
if ( V_2 -> V_15 == V_42 || V_2 -> V_15 == V_43 )
return V_20 & V_44 ;
return false ;
}
static bool F_15 ( struct V_1 * V_2 , T_2 V_20 )
{
if ( V_2 -> V_15 == V_42 || V_2 -> V_15 == V_43 )
return V_20 & V_45 ;
return false ;
}
static bool F_16 ( struct V_1 * V_2 , T_2 V_20 )
{
if ( V_2 -> V_15 == V_16 || V_2 -> V_15 == V_17 )
return V_20 & ( V_46 | V_47 ) ;
else
return V_20 & ( V_48 | V_49 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_1 ( V_2 , V_21 , false ) ;
if ( V_20 < 0 ) {
F_10 ( V_2 -> V_12 , L_9 , V_20 ) ;
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
static void F_19 ( struct V_1 * V_2 )
{
struct V_54 V_55 = { 0 , } ;
bool V_56 = V_2 -> V_15 == V_16 || V_2 -> V_15 == V_17 ;
bool V_57 = V_2 -> V_15 == V_16 || V_2 -> V_15 == V_17 ;
V_55 . V_20 = F_1 ( V_2 , V_21 , V_57 ) ;
if ( ( V_55 . V_20 & 0xff ) == 0xff )
V_55 . V_20 = - 1 ;
if ( V_55 . V_20 >= 0 ) {
V_55 . V_58 = F_9 ( V_2 ) ;
if ( V_56 && ( V_55 . V_20 & V_22 ) ) {
F_20 ( V_2 -> V_12 , L_10 ) ;
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
F_10 ( V_2 -> V_12 , L_11 ) ;
return V_82 ;
}
if ( V_2 -> V_15 == V_16 || V_2 -> V_15 == V_17 ) {
V_20 = F_1 ( V_2 , V_21 , false ) ;
if ( V_20 & V_84 ) {
F_3 ( V_2 -> V_12 , L_12 ) ;
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
if ( V_2 -> V_15 == V_16 || V_2 -> V_15 == V_17 ) {
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
if ( V_2 -> V_15 == V_16 || V_2 -> V_15 == V_17 ) {
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
F_10 ( V_2 -> V_12 , L_13 ) ;
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
static int F_39 ( struct V_1 * V_2 ,
const char * V_132 )
{
int V_107 ;
struct V_133 * V_134 ;
struct V_135 V_136 = { . V_137 = V_2 , } ;
V_134 = F_40 ( V_2 -> V_12 , sizeof( * V_134 ) , V_138 ) ;
if ( ! V_134 )
return - V_139 ;
V_134 -> V_132 = V_132 ;
V_134 -> type = V_140 ;
V_134 -> V_141 = V_142 [ V_2 -> V_15 ] . V_143 ;
V_134 -> V_144 = V_142 [ V_2 -> V_15 ] . V_145 ;
V_134 -> V_146 = F_32 ;
V_134 -> V_147 = F_38 ;
F_41 ( & V_2 -> V_76 , F_22 ) ;
F_42 ( & V_2 -> V_108 ) ;
V_2 -> V_72 = F_43 ( V_2 -> V_12 , V_134 , & V_136 ) ;
if ( F_44 ( V_2 -> V_72 ) ) {
V_107 = F_45 ( V_2 -> V_72 ) ;
F_10 ( V_2 -> V_12 , L_14 , V_107 ) ;
return V_107 ;
}
F_20 ( V_2 -> V_12 , L_15 , V_148 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
V_77 = 0 ;
F_36 ( & V_2 -> V_76 ) ;
F_47 ( V_2 -> V_72 ) ;
F_48 ( & V_2 -> V_108 ) ;
}
static T_3 F_49 ( int V_149 , void * V_150 )
{
struct V_1 * V_2 = V_150 ;
F_19 ( V_2 ) ;
return V_151 ;
}
static int F_50 ( struct V_1 * V_2 , T_1 V_13 ,
bool V_4 )
{
struct V_152 * V_153 = F_51 ( V_2 -> V_12 ) ;
struct V_154 V_155 [ 2 ] ;
unsigned char V_150 [ 2 ] ;
int V_107 ;
if ( ! V_153 -> V_156 )
return - V_110 ;
V_155 [ 0 ] . V_157 = V_153 -> V_157 ;
V_155 [ 0 ] . V_20 = 0 ;
V_155 [ 0 ] . V_158 = & V_13 ;
V_155 [ 0 ] . V_159 = sizeof( V_13 ) ;
V_155 [ 1 ] . V_157 = V_153 -> V_157 ;
V_155 [ 1 ] . V_20 = V_160 ;
V_155 [ 1 ] . V_158 = V_150 ;
if ( V_4 )
V_155 [ 1 ] . V_159 = 1 ;
else
V_155 [ 1 ] . V_159 = 2 ;
V_107 = F_52 ( V_153 -> V_156 , V_155 , F_53 ( V_155 ) ) ;
if ( V_107 < 0 )
return V_107 ;
if ( ! V_4 )
V_107 = F_54 ( V_150 ) ;
else
V_107 = V_150 [ 0 ] ;
return V_107 ;
}
static int F_55 ( struct V_152 * V_153 ,
const struct V_161 * V_162 )
{
char * V_132 ;
struct V_1 * V_2 ;
int V_163 ;
int V_164 = 0 ;
F_34 ( & V_165 ) ;
V_163 = F_56 ( & V_166 , V_153 , 0 , 0 , V_138 ) ;
F_37 ( & V_165 ) ;
if ( V_163 < 0 )
return V_163 ;
V_132 = F_57 ( & V_153 -> V_12 , V_138 , L_16 , V_162 -> V_132 , V_163 ) ;
if ( ! V_132 ) {
V_164 = - V_139 ;
goto V_167;
}
V_2 = F_40 ( & V_153 -> V_12 , sizeof( * V_2 ) , V_138 ) ;
if ( ! V_2 ) {
V_164 = - V_139 ;
goto V_167;
}
V_2 -> V_162 = V_163 ;
V_2 -> V_12 = & V_153 -> V_12 ;
V_2 -> V_15 = V_162 -> V_168 ;
V_2 -> V_8 . V_9 = & F_50 ;
V_2 -> V_5 = V_169 [ V_2 -> V_15 ] ;
V_164 = F_39 ( V_2 , V_132 ) ;
if ( V_164 )
goto V_167;
F_25 ( & V_2 -> V_76 , 60 * V_79 ) ;
F_58 ( V_153 , V_2 ) ;
if ( V_153 -> V_149 ) {
V_164 = F_59 ( & V_153 -> V_12 , V_153 -> V_149 ,
NULL , F_49 ,
V_170 ,
V_132 , V_2 ) ;
if ( V_164 ) {
F_10 ( & V_153 -> V_12 ,
L_17 ,
V_153 -> V_149 , V_164 ) ;
return V_164 ;
}
}
return 0 ;
V_167:
F_34 ( & V_165 ) ;
F_60 ( & V_166 , V_163 ) ;
F_37 ( & V_165 ) ;
return V_164 ;
}
static int F_61 ( struct V_152 * V_153 )
{
struct V_1 * V_2 = F_62 ( V_153 ) ;
F_46 ( V_2 ) ;
F_34 ( & V_165 ) ;
F_60 ( & V_166 , V_2 -> V_162 ) ;
F_37 ( & V_165 ) ;
return 0 ;
}
static inline int F_63 ( void )
{
int V_107 = F_64 ( & V_171 ) ;
if ( V_107 )
F_65 ( L_18 ) ;
return V_107 ;
}
static inline void F_66 ( void )
{
F_67 ( & V_171 ) ;
}
static inline int F_63 ( void ) { return 0 ; }
static inline void F_66 ( void ) {}
static int F_68 ( struct V_1 * V_2 , T_1 V_13 ,
bool V_4 )
{
struct V_172 * V_12 = V_2 -> V_12 ;
struct V_173 * V_174 = V_12 -> V_175 ;
unsigned int V_176 = 3 ;
int V_177 , V_178 ;
int V_31 ;
if ( ! V_4 ) {
V_177 = V_174 -> V_9 ( V_12 , V_13 + 1 ) ;
do {
V_31 = V_177 ;
if ( V_177 < 0 )
return V_177 ;
V_178 = V_174 -> V_9 ( V_12 , V_13 ) ;
if ( V_178 < 0 )
return V_178 ;
V_177 = V_174 -> V_9 ( V_12 , V_13 + 1 ) ;
} while ( V_31 != V_177 && -- V_176 );
if ( V_176 == 0 )
return - V_179 ;
return ( V_177 << 8 ) | V_178 ;
}
return V_174 -> V_9 ( V_12 , V_13 ) ;
}
static int F_69 ( struct V_180 * V_181 )
{
struct V_1 * V_2 ;
struct V_173 * V_174 = V_181 -> V_12 . V_175 ;
const char * V_132 ;
if ( ! V_174 ) {
F_10 ( & V_181 -> V_12 , L_19 ) ;
return - V_7 ;
}
if ( ! V_174 -> V_9 ) {
F_10 ( & V_181 -> V_12 , L_20 ) ;
return - V_7 ;
}
if ( ! V_174 -> V_15 ) {
F_10 ( & V_181 -> V_12 , L_21 ) ;
return - V_7 ;
}
V_2 = F_40 ( & V_181 -> V_12 , sizeof( * V_2 ) , V_138 ) ;
if ( ! V_2 )
return - V_139 ;
F_70 ( V_181 , V_2 ) ;
V_2 -> V_12 = & V_181 -> V_12 ;
V_2 -> V_15 = V_174 -> V_15 ;
V_2 -> V_5 = V_169 [ V_2 -> V_15 ] ;
V_132 = V_174 -> V_132 ? : F_71 ( & V_181 -> V_12 ) ;
V_2 -> V_8 . V_9 = & F_68 ;
return F_39 ( V_2 , V_132 ) ;
}
static int F_72 ( struct V_180 * V_181 )
{
struct V_1 * V_2 = F_73 ( V_181 ) ;
F_46 ( V_2 ) ;
return 0 ;
}
static inline int F_74 ( void )
{
int V_107 = F_75 ( & V_182 ) ;
if ( V_107 )
F_65 ( L_22 ) ;
return V_107 ;
}
static inline void F_76 ( void )
{
F_77 ( & V_182 ) ;
}
static inline int F_74 ( void ) { return 0 ; }
static inline void F_76 ( void ) {}
static int T_4 F_78 ( void )
{
int V_107 ;
V_107 = F_63 () ;
if ( V_107 )
return V_107 ;
V_107 = F_74 () ;
if ( V_107 )
F_66 () ;
return V_107 ;
}
static void T_5 F_79 ( void )
{
F_76 () ;
F_66 () ;
}
