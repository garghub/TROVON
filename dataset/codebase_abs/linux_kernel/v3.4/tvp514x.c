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
V_95 = F_16 ( V_3 ) ;
if ( V_95 == V_35 )
return 0 ;
V_97 = V_77 -> V_102 ;
switch ( V_97 ) {
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
V_99 = V_113 |
V_114 |
V_115 ;
break;
case V_116 :
case V_117 :
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
V_99 = V_114 |
V_115 ;
break;
default:
return - V_100 ;
}
V_98 = F_4 ( V_3 , V_128 ) ;
if ( V_99 != ( V_98 & V_99 ) )
return 0 ;
* V_94 = V_77 -> V_129 [ V_95 ] . V_130 . V_131 ;
F_20 ( 1 , V_79 , V_3 , L_8 ,
V_77 -> V_129 [ V_95 ] . V_130 . V_91 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , T_3 V_94 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
int V_9 , V_132 ;
for ( V_132 = 0 ; V_132 < V_77 -> V_133 ; V_132 ++ )
if ( V_94 & V_77 -> V_129 [ V_132 ] . V_130 . V_131 )
break;
if ( ( V_132 == V_77 -> V_133 ) || ( V_132 == V_35 ) )
return - V_100 ;
V_9 = F_11 ( V_3 , V_27 ,
V_77 -> V_129 [ V_132 ] . V_134 ) ;
if ( V_9 )
return V_9 ;
V_77 -> V_95 = V_132 ;
V_77 -> V_78 [ V_27 ] . V_15 =
V_77 -> V_129 [ V_132 ] . V_134 ;
F_20 ( 1 , V_79 , V_3 , L_9 ,
V_77 -> V_129 [ V_132 ] . V_130 . V_91 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 ,
T_2 V_102 , T_2 V_135 , T_2 V_136 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
int V_9 ;
enum V_96 V_97 ;
enum V_137 V_138 ;
T_1 V_98 , V_99 ;
int V_139 = V_140 ;
if ( ( V_102 >= V_141 ) ||
( V_135 >= V_142 ) )
return - V_100 ;
if ( ! V_77 -> V_143 )
F_24 ( V_3 , 1 ) ;
V_97 = V_102 ;
V_138 = V_135 ;
V_9 = F_11 ( V_3 , V_36 , V_97 ) ;
if ( V_9 )
return V_9 ;
V_138 |= F_4 ( V_3 ,
V_70 ) & 0x7 ;
V_9 = F_11 ( V_3 , V_70 ,
V_138 ) ;
if ( V_9 )
return V_9 ;
V_77 -> V_78 [ V_36 ] . V_15 = V_97 ;
V_77 -> V_78 [ V_70 ] . V_15 = V_138 ;
F_14 ( V_144 ) ;
V_9 =
F_11 ( V_3 , V_76 , 0x01 ) ;
if ( V_9 )
return V_9 ;
switch ( V_97 ) {
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
V_99 = V_113 |
V_114 |
V_115 ;
break;
case V_116 :
case V_117 :
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
V_99 = V_114 |
V_115 ;
break;
default:
return - V_100 ;
}
while ( V_139 -- > 0 ) {
F_14 ( V_144 ) ;
V_98 = F_4 ( V_3 ,
V_128 ) ;
if ( V_99 == ( V_98 & V_99 ) )
break;
}
if ( V_139 < 0 )
return - V_100 ;
V_77 -> V_102 = V_102 ;
V_77 -> V_135 = V_135 ;
F_20 ( 1 , V_79 , V_3 , L_10 , V_97 ) ;
return 0 ;
}
static int F_25 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
struct V_1 * V_77 = F_1 ( V_3 ) ;
int V_9 = - V_100 , V_145 ;
V_145 = V_5 -> V_15 ;
switch ( V_5 -> V_131 ) {
case V_146 :
V_9 = F_11 ( V_3 , V_43 , V_145 ) ;
if ( ! V_9 )
V_77 -> V_78 [ V_43 ] . V_15 = V_145 ;
break;
case V_147 :
V_9 = F_11 ( V_3 , V_44 , V_145 ) ;
if ( ! V_9 )
V_77 -> V_78 [ V_44 ] . V_15 = V_145 ;
break;
case V_148 :
V_9 = F_11 ( V_3 , V_45 , V_145 ) ;
if ( ! V_9 )
V_77 -> V_78 [ V_45 ] . V_15 = V_145 ;
break;
case V_149 :
if ( V_145 == 180 )
V_145 = 0x7F ;
else if ( V_145 == - 180 )
V_145 = 0x80 ;
V_9 = F_11 ( V_3 , V_46 , V_145 ) ;
if ( ! V_9 )
V_77 -> V_78 [ V_46 ] . V_15 = V_145 ;
break;
case V_150 :
V_9 = F_11 ( V_3 , V_37 , V_145 ? 0x0f : 0x0c ) ;
if ( ! V_9 )
V_77 -> V_78 [ V_37 ] . V_15 = V_145 ;
break;
}
F_20 ( 1 , V_79 , V_3 , L_11 ,
V_5 -> V_131 , V_5 -> V_15 ) ;
return V_9 ;
}
static int
F_26 ( struct V_2 * V_3 , unsigned V_151 ,
enum V_152 * V_153 )
{
if ( V_151 )
return - V_100 ;
* V_153 = V_154 ;
return 0 ;
}
static int
F_27 ( struct V_2 * V_3 , struct V_155 * V_156 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
enum V_24 V_95 ;
if ( V_156 == NULL )
return - V_100 ;
V_95 = V_77 -> V_95 ;
V_156 -> V_153 = V_154 ;
V_156 -> V_157 = V_77 -> V_129 [ V_95 ] . V_157 ;
V_156 -> V_158 = V_77 -> V_129 [ V_95 ] . V_158 ;
V_156 -> V_159 = V_160 ;
V_156 -> V_161 = V_162 ;
F_20 ( 1 , V_79 , V_3 , L_12 ,
V_156 -> V_157 , V_156 -> V_158 ) ;
return 0 ;
}
static int
F_28 ( struct V_2 * V_3 , struct V_163 * V_164 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_165 * V_166 ;
enum V_24 V_95 ;
if ( V_164 == NULL )
return - V_100 ;
if ( V_164 -> type != V_167 )
return - V_100 ;
V_95 = V_77 -> V_95 ;
V_166 = & V_164 -> V_168 . V_169 ;
V_166 -> V_170 = V_171 ;
V_166 -> V_172 =
V_77 -> V_129 [ V_95 ] . V_130 . V_173 ;
return 0 ;
}
static int
F_29 ( struct V_2 * V_3 , struct V_163 * V_164 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
struct V_174 * V_172 ;
enum V_24 V_95 ;
if ( V_164 == NULL )
return - V_100 ;
if ( V_164 -> type != V_167 )
return - V_100 ;
V_172 = & V_164 -> V_168 . V_169 . V_172 ;
V_95 = V_77 -> V_95 ;
* V_172 =
V_77 -> V_129 [ V_95 ] . V_130 . V_173 ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , int V_175 )
{
int V_9 = 0 ;
struct V_11 * V_12 = F_5 ( V_3 ) ;
struct V_1 * V_77 = F_1 ( V_3 ) ;
if ( V_77 -> V_143 == V_175 )
return 0 ;
switch ( V_175 ) {
case 0 :
{
V_9 = F_11 ( V_3 , V_38 , 0x01 ) ;
if ( V_9 ) {
F_15 ( V_3 , L_13 ) ;
return V_9 ;
}
V_77 -> V_143 = V_175 ;
break;
}
case 1 :
{
struct V_17 * V_176 = (struct V_17 * )
V_12 -> V_177 -> V_178 -> V_179 ;
V_9 = F_13 ( V_3 , V_176 ) ;
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
V_77 -> V_143 = V_175 ;
break;
}
default:
V_9 = - V_89 ;
break;
}
return V_9 ;
}
static int
F_30 ( struct V_11 * V_12 , const struct V_180 * V_131 )
{
struct V_1 * V_77 ;
struct V_2 * V_3 ;
if ( ! F_31 ( V_12 -> V_93 , V_181 ) )
return - V_182 ;
if ( ! V_12 -> V_183 . V_184 ) {
F_15 ( V_12 , L_17 ) ;
return - V_89 ;
}
V_77 = F_32 ( sizeof( * V_77 ) , V_185 ) ;
if ( ! V_77 )
return - V_186 ;
* V_77 = V_187 ;
memcpy ( V_77 -> V_78 , V_188 ,
sizeof( V_188 ) ) ;
V_77 -> V_189 = V_12 -> V_183 . V_184 ;
V_77 -> V_78 [ V_71 ] . V_15 |=
( V_77 -> V_189 -> V_190 << 1 ) ;
V_77 -> V_78 [ V_69 ] . V_15 |=
( ( V_77 -> V_189 -> V_191 << 2 ) |
( V_77 -> V_189 -> V_192 << 3 ) ) ;
V_77 -> V_78 [ V_27 ] . V_15 =
V_29 ;
V_3 = & V_77 -> V_3 ;
F_33 ( V_3 , V_12 , & V_193 ) ;
F_34 ( & V_77 -> V_7 , 5 ) ;
F_35 ( & V_77 -> V_7 , & V_194 ,
V_146 , 0 , 255 , 1 , 128 ) ;
F_35 ( & V_77 -> V_7 , & V_194 ,
V_147 , 0 , 255 , 1 , 128 ) ;
F_35 ( & V_77 -> V_7 , & V_194 ,
V_148 , 0 , 255 , 1 , 128 ) ;
F_35 ( & V_77 -> V_7 , & V_194 ,
V_149 , - 180 , 180 , 180 , 0 ) ;
F_35 ( & V_77 -> V_7 , & V_194 ,
V_150 , 0 , 1 , 1 , 1 ) ;
V_3 -> V_195 = & V_77 -> V_7 ;
if ( V_77 -> V_7 . error ) {
int V_9 = V_77 -> V_7 . error ;
F_36 ( & V_77 -> V_7 ) ;
F_37 ( V_77 ) ;
return V_9 ;
}
F_38 ( & V_77 -> V_7 ) ;
F_10 ( V_3 , L_18 , V_3 -> V_91 ) ;
return 0 ;
}
static int F_39 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = F_40 ( V_12 ) ;
struct V_1 * V_77 = F_1 ( V_3 ) ;
F_41 ( V_3 ) ;
F_36 ( & V_77 -> V_7 ) ;
F_37 ( V_77 ) ;
return 0 ;
}
