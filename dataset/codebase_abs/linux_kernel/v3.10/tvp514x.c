static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static int F_4 ( struct V_2 * V_3 , T_1 V_8 )
{
int V_9 , V_10 = 0 ;
struct V_11 * V_12 = F_5 ( V_3 ) ;
V_13:
V_9 = F_6 ( V_12 , V_8 ) ;
if ( V_9 < 0 ) {
if ( V_10 <= V_14 ) {
F_7 ( V_3 , L_1 , V_10 ) ;
V_10 ++ ;
F_8 ( 10 ) ;
goto V_13;
}
}
return V_9 ;
}
static void F_9 ( struct V_2 * V_3 , T_1 V_8 )
{
T_2 V_15 ;
V_15 = F_4 ( V_3 , V_8 ) ;
F_10 ( V_3 , L_2 , V_8 , V_15 ) ;
}
static int F_11 ( struct V_2 * V_3 , T_1 V_8 , T_1 V_15 )
{
int V_9 , V_10 = 0 ;
struct V_11 * V_12 = F_5 ( V_3 ) ;
V_16:
V_9 = F_12 ( V_12 , V_8 , V_15 ) ;
if ( V_9 ) {
if ( V_10 <= V_14 ) {
F_7 ( V_3 , L_3 , V_10 ) ;
V_10 ++ ;
F_8 ( 10 ) ;
goto V_16;
}
}
return V_9 ;
}
static int F_13 ( struct V_2 * V_3 ,
const struct V_17 V_18 [] )
{
int V_9 ;
const struct V_17 * V_19 = V_18 ;
for (; V_19 -> V_20 != V_21 ; V_19 ++ ) {
if ( V_19 -> V_20 == V_22 ) {
F_14 ( V_19 -> V_15 ) ;
continue;
}
if ( V_19 -> V_20 == V_23 )
continue;
V_9 = F_11 ( V_3 , V_19 -> V_8 , ( T_1 ) V_19 -> V_15 ) ;
if ( V_9 ) {
F_15 ( V_3 , L_4 , V_9 ) ;
return V_9 ;
}
}
return 0 ;
}
static enum V_24 F_16 ( struct V_2 * V_3 )
{
T_1 V_25 , V_26 ;
V_25 = F_4 ( V_3 , V_27 ) ;
if ( ( V_25 & V_28 ) == V_29 )
V_26 = F_4 ( V_3 , V_30 ) ;
else
V_26 = V_25 ;
switch ( V_26 & V_28 ) {
case V_31 :
return V_32 ;
case V_33 :
return V_34 ;
default:
return V_35 ;
}
return V_35 ;
}
static void F_17 ( struct V_2 * V_3 )
{
F_9 ( V_3 , V_36 ) ;
F_9 ( V_3 , V_37 ) ;
F_9 ( V_3 , V_27 ) ;
F_9 ( V_3 , V_38 ) ;
F_9 ( V_3 , V_39 ) ;
F_9 ( V_3 , V_40 ) ;
F_9 ( V_3 , V_41 ) ;
F_9 ( V_3 , V_42 ) ;
F_9 ( V_3 , V_43 ) ;
F_9 ( V_3 , V_44 ) ;
F_9 ( V_3 , V_45 ) ;
F_9 ( V_3 , V_46 ) ;
F_9 ( V_3 , V_47 ) ;
F_9 ( V_3 , V_48 ) ;
F_9 ( V_3 , V_49 ) ;
F_9 ( V_3 , V_50 ) ;
F_9 ( V_3 , V_51 ) ;
F_9 ( V_3 , V_52 ) ;
F_9 ( V_3 , V_53 ) ;
F_9 ( V_3 , V_54 ) ;
F_9 ( V_3 , V_55 ) ;
F_9 ( V_3 , V_56 ) ;
F_9 ( V_3 , V_57 ) ;
F_9 ( V_3 , V_58 ) ;
F_9 ( V_3 , V_59 ) ;
F_9 ( V_3 , V_60 ) ;
F_9 ( V_3 , V_61 ) ;
F_9 ( V_3 , V_62 ) ;
F_9 ( V_3 , V_63 ) ;
F_9 ( V_3 , V_64 ) ;
F_9 ( V_3 , V_65 ) ;
F_9 ( V_3 , V_66 ) ;
F_9 ( V_3 , V_67 ) ;
F_9 ( V_3 , V_68 ) ;
F_9 ( V_3 , V_69 ) ;
F_9 ( V_3 , V_70 ) ;
F_9 ( V_3 , V_71 ) ;
F_9 ( V_3 , V_72 ) ;
F_9 ( V_3 , V_73 ) ;
F_9 ( V_3 , V_74 ) ;
F_9 ( V_3 , V_75 ) ;
F_9 ( V_3 , V_76 ) ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_1 * V_77 )
{
int V_9 ;
V_9 =
F_13 ( V_3 , V_77 -> V_78 ) ;
if ( V_9 )
return V_9 ;
if ( V_79 )
F_17 ( V_3 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 ,
struct V_1 * V_77 )
{
T_1 V_80 , V_81 , V_82 ;
struct V_11 * V_12 = F_5 ( V_3 ) ;
V_80 = F_4 ( V_3 , V_83 ) ;
V_81 = F_4 ( V_3 , V_84 ) ;
V_82 = F_4 ( V_3 , V_85 ) ;
F_20 ( 1 , V_79 , V_3 ,
L_5 ,
V_80 , V_81 , V_82 ) ;
if ( ( V_80 != V_86 )
|| ( ( V_81 != V_87 )
&& ( V_81 != V_88 ) ) ) {
F_15 ( V_3 , L_6 ,
V_80 , V_81 ) ;
return - V_89 ;
}
V_77 -> V_90 = V_82 ;
F_10 ( V_3 , L_7 ,
V_12 -> V_91 , V_77 -> V_90 ,
V_12 -> V_92 << 1 , V_12 -> V_93 -> V_91 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , T_3 * V_94 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
enum V_24 V_95 ;
enum V_96 V_97 ;
T_1 V_98 , V_99 ;
if ( V_94 == NULL )
return - V_100 ;
* V_94 = V_101 ;
if ( ! V_77 -> V_102 ) {
F_22 ( V_3 , 1 ) ;
F_14 ( V_103 ) ;
}
V_95 = F_16 ( V_3 ) ;
if ( V_95 == V_35 )
return 0 ;
V_97 = V_77 -> V_104 ;
switch ( V_97 ) {
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_99 = V_115 |
V_116 |
V_117 ;
break;
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
V_99 = V_116 |
V_117 ;
break;
default:
return - V_100 ;
}
V_98 = F_4 ( V_3 , V_130 ) ;
if ( V_99 != ( V_98 & V_99 ) )
return 0 ;
* V_94 = V_77 -> V_131 [ V_95 ] . V_132 . V_133 ;
F_20 ( 1 , V_79 , V_3 , L_8 ,
V_77 -> V_131 [ V_95 ] . V_132 . V_91 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , T_3 V_94 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
int V_9 , V_134 ;
for ( V_134 = 0 ; V_134 < V_77 -> V_135 ; V_134 ++ )
if ( V_94 & V_77 -> V_131 [ V_134 ] . V_132 . V_133 )
break;
if ( ( V_134 == V_77 -> V_135 ) || ( V_134 == V_35 ) )
return - V_100 ;
V_9 = F_11 ( V_3 , V_27 ,
V_77 -> V_131 [ V_134 ] . V_136 ) ;
if ( V_9 )
return V_9 ;
V_77 -> V_95 = V_134 ;
V_77 -> V_78 [ V_27 ] . V_15 =
V_77 -> V_131 [ V_134 ] . V_136 ;
F_20 ( 1 , V_79 , V_3 , L_9 ,
V_77 -> V_131 [ V_134 ] . V_132 . V_91 ) ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 ,
T_2 V_104 , T_2 V_137 , T_2 V_138 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
int V_9 ;
enum V_96 V_97 ;
enum V_139 V_140 ;
if ( ( V_104 >= V_141 ) ||
( V_137 >= V_142 ) )
return - V_100 ;
V_97 = V_104 ;
V_140 = V_137 ;
V_9 = F_11 ( V_3 , V_36 , V_97 ) ;
if ( V_9 )
return V_9 ;
V_140 |= F_4 ( V_3 ,
V_70 ) & 0x7 ;
V_9 = F_11 ( V_3 , V_70 ,
V_140 ) ;
if ( V_9 )
return V_9 ;
V_77 -> V_78 [ V_36 ] . V_15 = V_97 ;
V_77 -> V_78 [ V_70 ] . V_15 = V_140 ;
V_77 -> V_104 = V_104 ;
V_77 -> V_137 = V_137 ;
F_20 ( 1 , V_79 , V_3 , L_10 , V_97 ) ;
return 0 ;
}
static int F_25 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_77 = F_1 ( V_3 ) ;
int V_9 = - V_100 , V_143 ;
V_143 = V_5 -> V_15 ;
switch ( V_5 -> V_133 ) {
case V_144 :
V_9 = F_11 ( V_3 , V_43 , V_143 ) ;
if ( ! V_9 )
V_77 -> V_78 [ V_43 ] . V_15 = V_143 ;
break;
case V_145 :
V_9 = F_11 ( V_3 , V_44 , V_143 ) ;
if ( ! V_9 )
V_77 -> V_78 [ V_44 ] . V_15 = V_143 ;
break;
case V_146 :
V_9 = F_11 ( V_3 , V_45 , V_143 ) ;
if ( ! V_9 )
V_77 -> V_78 [ V_45 ] . V_15 = V_143 ;
break;
case V_147 :
if ( V_143 == 180 )
V_143 = 0x7F ;
else if ( V_143 == - 180 )
V_143 = 0x80 ;
V_9 = F_11 ( V_3 , V_46 , V_143 ) ;
if ( ! V_9 )
V_77 -> V_78 [ V_46 ] . V_15 = V_143 ;
break;
case V_148 :
V_9 = F_11 ( V_3 , V_37 , V_143 ? 0x0f : 0x0c ) ;
if ( ! V_9 )
V_77 -> V_78 [ V_37 ] . V_15 = V_143 ;
break;
}
F_20 ( 1 , V_79 , V_3 , L_11 ,
V_5 -> V_133 , V_5 -> V_15 ) ;
return V_9 ;
}
static int
F_26 ( struct V_2 * V_3 , unsigned V_149 ,
enum V_150 * V_151 )
{
if ( V_149 )
return - V_100 ;
* V_151 = V_152 ;
return 0 ;
}
static int
F_27 ( struct V_2 * V_3 , struct V_153 * V_154 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
enum V_24 V_95 ;
if ( V_154 == NULL )
return - V_100 ;
V_95 = V_77 -> V_95 ;
V_154 -> V_151 = V_155 ;
V_154 -> V_156 = V_77 -> V_131 [ V_95 ] . V_156 ;
V_154 -> V_157 = V_77 -> V_131 [ V_95 ] . V_157 ;
V_154 -> V_158 = V_159 ;
V_154 -> V_160 = V_161 ;
F_20 ( 1 , V_79 , V_3 , L_12 ,
V_154 -> V_156 , V_154 -> V_157 ) ;
return 0 ;
}
static int
F_28 ( struct V_2 * V_3 , struct V_162 * V_163 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_164 * V_165 ;
enum V_24 V_95 ;
if ( V_163 == NULL )
return - V_100 ;
if ( V_163 -> type != V_166 )
return - V_100 ;
V_95 = V_77 -> V_95 ;
V_165 = & V_163 -> V_167 . V_168 ;
V_165 -> V_169 = V_170 ;
V_165 -> V_171 =
V_77 -> V_131 [ V_95 ] . V_132 . V_172 ;
return 0 ;
}
static int
F_29 ( struct V_2 * V_3 , struct V_162 * V_163 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_173 * V_171 ;
enum V_24 V_95 ;
if ( V_163 == NULL )
return - V_100 ;
if ( V_163 -> type != V_166 )
return - V_100 ;
V_171 = & V_163 -> V_167 . V_168 . V_171 ;
V_95 = V_77 -> V_95 ;
* V_171 =
V_77 -> V_131 [ V_95 ] . V_132 . V_172 ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , int V_174 )
{
int V_9 = 0 ;
struct V_11 * V_12 = F_5 ( V_3 ) ;
struct V_1 * V_77 = F_1 ( V_3 ) ;
if ( V_77 -> V_102 == V_174 )
return 0 ;
switch ( V_174 ) {
case 0 :
{
V_9 = F_11 ( V_3 , V_38 , 0x01 ) ;
if ( V_9 ) {
F_15 ( V_3 , L_13 ) ;
return V_9 ;
}
V_77 -> V_102 = V_174 ;
break;
}
case 1 :
{
struct V_17 * V_175 = (struct V_17 * )
V_12 -> V_176 -> V_177 -> V_178 ;
V_9 = F_13 ( V_3 , V_175 ) ;
if ( V_9 ) {
F_15 ( V_3 , L_14 ) ;
return V_9 ;
}
V_9 = F_19 ( V_3 , V_77 ) ;
if ( V_9 ) {
F_15 ( V_3 , L_15 ) ;
return V_9 ;
}
V_9 = F_18 ( V_3 , V_77 ) ;
if ( V_9 ) {
F_15 ( V_3 , L_16 ) ;
return V_9 ;
}
V_77 -> V_102 = V_174 ;
break;
}
default:
V_9 = - V_89 ;
break;
}
return V_9 ;
}
static int F_30 ( struct V_2 * V_3 ,
struct V_179 * V_180 ,
struct V_181 * V_151 )
{
T_2 V_182 = V_151 -> V_182 ;
T_2 V_149 = V_151 -> V_149 ;
memset ( V_151 , 0 , sizeof( * V_151 ) ) ;
V_151 -> V_149 = V_149 ;
V_151 -> V_182 = V_182 ;
if ( V_149 != 0 )
return - V_100 ;
V_151 -> V_151 = V_155 ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 ,
struct V_179 * V_180 ,
struct V_183 * V_184 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
T_4 V_185 = V_184 -> V_185 ;
if ( V_185 == V_186 ) {
V_184 -> V_184 = V_77 -> V_184 ;
return 0 ;
}
V_184 -> V_184 . V_151 = V_155 ;
V_184 -> V_184 . V_156 = V_187 [ V_77 -> V_95 ] . V_156 ;
V_184 -> V_184 . V_157 = V_187 [ V_77 -> V_95 ] . V_157 ;
V_184 -> V_184 . V_160 = V_161 ;
V_184 -> V_184 . V_158 = V_159 ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 ,
struct V_179 * V_180 ,
struct V_183 * V_188 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
if ( V_188 -> V_184 . V_158 != V_159 ||
V_188 -> V_184 . V_151 != V_155 ||
V_188 -> V_184 . V_160 != V_161 ||
V_188 -> V_184 . V_156 != V_187 [ V_77 -> V_95 ] . V_156 ||
V_188 -> V_184 . V_157 != V_187 [ V_77 -> V_95 ] . V_157 )
return - V_100 ;
V_77 -> V_184 = V_188 -> V_184 ;
return 0 ;
}
static int
F_33 ( struct V_11 * V_12 , const struct V_189 * V_133 )
{
struct V_1 * V_77 ;
struct V_2 * V_3 ;
int V_190 ;
if ( ! F_34 ( V_12 -> V_93 , V_191 ) )
return - V_192 ;
if ( ! V_12 -> V_193 . V_194 ) {
F_15 ( V_12 , L_17 ) ;
return - V_89 ;
}
V_77 = F_35 ( & V_12 -> V_193 , sizeof( * V_77 ) , V_195 ) ;
if ( ! V_77 )
return - V_196 ;
* V_77 = V_197 ;
memcpy ( V_77 -> V_78 , V_198 ,
sizeof( V_198 ) ) ;
V_77 -> V_199 = V_12 -> V_193 . V_194 ;
V_77 -> V_78 [ V_71 ] . V_15 |=
( V_77 -> V_199 -> V_200 << 1 ) ;
V_77 -> V_78 [ V_69 ] . V_15 |=
( ( V_77 -> V_199 -> V_201 << 2 ) |
( V_77 -> V_199 -> V_202 << 3 ) ) ;
V_77 -> V_78 [ V_27 ] . V_15 =
V_29 ;
V_3 = & V_77 -> V_3 ;
F_36 ( V_3 , V_12 , & V_203 ) ;
F_37 ( V_3 -> V_91 , V_204 , sizeof( V_3 -> V_91 ) ) ;
#if F_38 ( V_205 )
V_77 -> V_182 . V_206 = V_207 ;
V_77 -> V_3 . V_206 |= V_208 ;
V_77 -> V_3 . V_209 . V_206 |= V_210 ;
V_190 = F_39 ( & V_77 -> V_3 . V_209 , 1 , & V_77 -> V_182 , 0 ) ;
if ( V_190 < 0 ) {
F_15 ( V_3 , L_18 ,
V_3 -> V_91 ) ;
F_40 ( V_77 ) ;
return V_190 ;
}
#endif
F_41 ( & V_77 -> V_7 , 5 ) ;
F_42 ( & V_77 -> V_7 , & V_211 ,
V_144 , 0 , 255 , 1 , 128 ) ;
F_42 ( & V_77 -> V_7 , & V_211 ,
V_145 , 0 , 255 , 1 , 128 ) ;
F_42 ( & V_77 -> V_7 , & V_211 ,
V_146 , 0 , 255 , 1 , 128 ) ;
F_42 ( & V_77 -> V_7 , & V_211 ,
V_147 , - 180 , 180 , 180 , 0 ) ;
F_42 ( & V_77 -> V_7 , & V_211 ,
V_148 , 0 , 1 , 1 , 1 ) ;
V_3 -> V_212 = & V_77 -> V_7 ;
if ( V_77 -> V_7 . error ) {
V_190 = V_77 -> V_7 . error ;
F_43 ( & V_77 -> V_7 ) ;
return V_190 ;
}
F_44 ( & V_77 -> V_7 ) ;
F_10 ( V_3 , L_19 , V_3 -> V_91 ) ;
return 0 ;
}
static int F_45 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_46 ( V_12 ) ;
struct V_1 * V_77 = F_1 ( V_3 ) ;
F_47 ( V_3 ) ;
#if F_38 ( V_205 )
F_48 ( & V_77 -> V_3 . V_209 ) ;
#endif
F_43 ( & V_77 -> V_7 ) ;
return 0 ;
}
