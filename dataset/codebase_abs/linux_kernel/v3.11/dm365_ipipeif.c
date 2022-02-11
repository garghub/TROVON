static int
F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
return V_7 ;
case V_8 :
return V_9 ;
case V_10 :
return V_11 ;
case V_12 :
return V_13 ;
default:
return V_11 ;
}
}
static inline T_1 F_2 ( void * V_14 , T_1 V_15 )
{
return F_3 ( V_14 + V_15 ) ;
}
static inline void F_4 ( T_1 V_16 , void * V_14 , T_1 V_15 )
{
F_5 ( V_16 , V_14 + V_15 ) ;
}
static void F_6 ( void * V_14 , struct V_17 * V_18 )
{
T_1 V_16 = 0 ;
if ( V_18 -> V_19 ) {
V_16 = ( V_18 -> V_19 & 1 ) << V_20 ;
V_16 |= V_18 -> V_21 & V_22 ;
}
F_4 ( V_16 , V_14 , V_23 ) ;
}
static int F_7 ( enum V_24 V_25 )
{
if ( V_25 == V_26 )
return V_27 ;
else if ( V_25 == V_28 )
return V_29 ;
return - V_30 ;
}
static int
F_8 ( struct V_31 * V_32 )
{
struct V_33 * V_34 ;
V_34 = & V_32 -> V_35 [ V_36 ] ;
if ( V_32 -> V_25 == V_26 &&
( V_34 -> V_37 == V_4 ||
V_34 -> V_37 == V_6 ) )
return V_38 ;
return V_39 ;
}
static int
F_9 ( struct V_31 * V_32 )
{
struct V_33 * V_34 ;
V_34 = & V_32 -> V_35 [ V_36 ] ;
switch ( V_34 -> V_37 ) {
case V_10 :
return V_40 ;
case V_4 :
case V_6 :
return V_40 ;
default:
return V_41 ;
}
}
static enum V_42
F_10 ( struct V_31 * V_32 )
{
struct V_33 * V_34 ;
V_34 = & V_32 -> V_35 [ V_36 ] ;
if ( V_32 -> V_25 == V_28 )
return V_38 ;
if ( V_34 -> V_37 == V_43 )
return V_44 ;
return V_45 ;
}
void F_11 ( struct V_31 * V_32 )
{
struct V_46 * V_47 = & V_32 -> V_47 ;
if ( V_32 -> V_25 != V_26 )
return;
F_12 ( & V_47 -> V_48 ) ;
F_13 ( V_47 ) ;
V_47 -> V_49 = V_50 ;
F_14 ( V_47 ) ;
F_15 ( & V_47 -> V_48 ) ;
}
int F_16 ( struct V_51 * V_52 )
{
struct V_31 * V_32 = & V_52 -> V_53 ;
return V_32 -> V_54 . V_55 ;
}
int F_17 ( struct V_51 * V_52 )
{
struct V_31 * V_32 = & V_52 -> V_53 ;
return V_32 -> V_54 . V_56 ;
}
static int F_18 ( struct V_57 * V_58 )
{
struct V_31 * V_32 = F_19 ( V_58 ) ;
struct V_33 * V_34 , * V_59 ;
struct V_60 V_61 = V_32 -> V_54 ;
enum V_42 V_62 ;
enum V_1 V_63 ;
void * V_64 ;
unsigned int V_16 ;
int V_65 ;
int V_66 ;
int V_67 ;
V_64 = V_32 -> V_64 ;
F_20 ( V_68 , 1 ) ;
V_34 = & V_32 -> V_35 [ V_36 ] ;
V_59 = & V_32 -> V_35 [ V_69 ] ;
V_16 = F_7 ( V_32 -> V_25 ) ;
if ( V_16 < 0 ) {
F_21 ( L_1 ) ;
return - V_30 ;
}
V_16 = V_16 << V_70 ;
V_62 = F_10 ( V_32 ) ;
V_16 |= V_62 << V_71 ;
V_16 |= V_61 . V_72 << V_73 ;
V_16 |= V_61 . V_74 << V_75 ;
V_16 |= V_61 . V_55 << V_76 ;
V_66 = F_1 ( V_34 -> V_37 ) ;
V_16 |= V_66 << V_77 ;
V_67 = F_8 ( V_32 ) ;
V_16 |= V_67 << V_78 ;
V_65 = F_9 ( V_32 ) ;
if ( V_62 != V_44 )
V_16 |= V_65 << V_79 ;
else
V_16 &= ~ ( V_80 << V_79 ) ;
F_4 ( V_16 , V_64 , V_81 ) ;
switch ( V_62 ) {
case V_38 :
F_4 ( V_32 -> V_82 , V_64 , V_83 ) ;
break;
case V_45 :
case V_84 :
F_4 ( V_32 -> V_82 , V_64 , V_83 ) ;
case V_44 :
V_16 |= V_65 << V_79 ;
F_4 ( V_61 . V_85 , V_64 , V_86 ) ;
F_4 ( V_61 . V_87 , V_64 , V_88 ) ;
F_4 ( V_34 -> V_89 , V_64 , V_90 ) ;
F_4 ( V_34 -> V_91 ,
V_64 , V_92 ) ;
break;
default:
return - V_30 ;
}
if ( V_61 . V_55 )
F_4 ( V_61 . V_56 , V_64 , V_93 ) ;
V_16 = V_61 . V_94 . V_95 & 1 ;
V_16 <<= V_96 ;
V_16 |= V_61 . V_94 . V_97 & V_98 ;
F_4 ( V_16 , V_64 , V_99 ) ;
V_63 = V_34 -> V_37 ;
if ( V_63 == V_4 )
V_63 = V_100 ;
else if ( V_63 == V_6 )
V_63 = V_10 ;
switch ( V_62 ) {
case V_45 :
V_16 = 0 ;
if ( V_59 -> V_37 == V_5 ) {
V_16 = 1 ;
V_16 |= ( V_101 & 1 ) <<
V_102 ;
V_16 |= ( V_32 -> V_103 & 1 ) <<
V_104 ;
}
F_4 ( V_16 , V_64 , V_105 ) ;
F_6 ( V_64 , & V_61 . V_94 . V_18 ) ;
F_4 ( V_61 . V_94 . V_106 ,
V_64 , V_107 ) ;
V_16 = F_2 ( V_64 , V_108 ) ;
switch ( V_63 ) {
case V_100 :
case V_43 :
case V_4 :
F_22 ( V_16 , V_109 ) ;
F_23 ( V_16 , V_110 ) ;
F_4 ( V_16 , V_64 , V_108 ) ;
break;
default:
F_22 ( V_16 , V_109 ) ;
F_22 ( V_16 , V_110 ) ;
F_4 ( V_16 , V_64 , V_108 ) ;
break;
}
case V_44 :
if ( V_61 . V_72 == V_111 ) {
V_16 = F_2 ( V_64 , V_112 ) ;
V_16 |= ( V_61 . V_94 . V_113 . V_114 - 1 ) <<
V_115 ;
V_16 |= ( V_61 . V_94 . V_113 . V_116 - 1 ) ;
F_4 ( V_16 , V_64 , V_112 ) ;
}
break;
case V_38 :
case V_84 :
F_6 ( V_64 , & V_61 . V_94 . V_18 ) ;
V_16 = 0 ;
if ( V_61 . V_94 . V_117 ) {
V_16 = V_61 . V_94 . V_118 &
V_119 ;
F_4 ( V_16 , V_64 , V_120 ) ;
V_16 = ( V_61 . V_94 . V_117 & 1 ) <<
V_121 ;
V_16 |= V_61 . V_94 . V_122 &
V_123 ;
}
F_4 ( V_16 , V_64 , V_124 ) ;
V_16 = V_125 << V_126 ;
V_16 |= V_125 << V_127 ;
switch ( V_63 ) {
case V_100 :
case V_128 :
F_22 ( V_16 , V_109 ) ;
F_23 ( V_16 , V_110 ) ;
break;
case V_129 :
case V_43 :
case V_4 :
case V_130 :
F_23 ( V_16 , V_109 ) ;
F_23 ( V_16 , V_110 ) ;
V_16 |= V_131 << V_132 ;
break;
default:
F_4 ( V_61 . V_94 . V_106 , V_64 ,
V_107 ) ;
}
F_4 ( V_16 , V_64 , V_108 ) ;
break;
default:
return - V_30 ;
}
return 0 ;
}
static int
F_24 ( struct V_57 * V_58 , struct V_60 * V_54 )
{
struct V_31 * V_32 = F_19 ( V_58 ) ;
struct V_133 * V_134 = V_32 -> V_135 . V_136 -> V_134 ;
if ( ! V_54 ) {
F_25 ( V_134 , L_2 ) ;
return - V_30 ;
}
V_32 -> V_54 . V_72 = V_54 -> V_72 ;
V_32 -> V_54 . V_85 = V_54 -> V_85 ;
V_32 -> V_54 . V_87 = V_54 -> V_87 ;
V_32 -> V_54 . V_56 = V_54 -> V_56 ;
V_32 -> V_54 . V_55 = V_54 -> V_55 ;
if ( V_32 -> V_54 . V_55 &&
( V_32 -> V_54 . V_56 < V_137 ||
V_32 -> V_54 . V_56 > V_138 ) ) {
F_25 ( V_134 , L_3 ,
V_137 , V_138 ) ;
return - V_30 ;
}
V_32 -> V_54 . V_74 = V_54 -> V_74 ;
V_32 -> V_54 . V_94 . V_118 = V_54 -> V_94 . V_118 ;
V_32 -> V_54 . V_94 . V_122 = V_54 -> V_94 . V_122 ;
V_32 -> V_54 . V_94 . V_117 = V_54 -> V_94 . V_117 ;
V_32 -> V_54 . V_94 . V_97 = V_54 -> V_94 . V_97 ;
V_32 -> V_54 . V_94 . V_95 = V_54 -> V_94 . V_95 ;
V_32 -> V_54 . V_94 . V_106 = V_54 -> V_94 . V_106 ;
V_32 -> V_54 . V_94 . V_18 . V_19 = V_54 -> V_94 . V_18 . V_19 ;
V_32 -> V_54 . V_94 . V_18 . V_21 = V_54 -> V_94 . V_18 . V_21 ;
V_32 -> V_54 . V_94 . V_113 . V_114 = V_54 -> V_94 . V_113 . V_114 ;
V_32 -> V_54 . V_94 . V_113 . V_116 = V_54 -> V_94 . V_113 . V_116 ;
return 0 ;
}
static int
F_26 ( struct V_57 * V_58 , void T_2 * V_139 )
{
struct V_31 * V_32 = F_19 ( V_58 ) ;
struct V_60 * V_54 = (struct V_60 * ) V_139 ;
struct V_133 * V_134 = V_32 -> V_135 . V_136 -> V_134 ;
if ( ! V_139 ) {
F_25 ( V_134 , L_2 ) ;
return - V_30 ;
}
V_54 -> V_72 = V_32 -> V_54 . V_72 ;
V_54 -> V_85 = V_32 -> V_54 . V_85 ;
V_54 -> V_87 = V_32 -> V_54 . V_87 ;
V_54 -> V_56 = V_32 -> V_54 . V_56 ;
V_54 -> V_55 = V_32 -> V_54 . V_55 ;
V_54 -> V_74 = V_32 -> V_54 . V_74 ;
V_54 -> V_94 . V_118 = V_32 -> V_54 . V_94 . V_118 ;
V_54 -> V_94 . V_122 = V_32 -> V_54 . V_94 . V_122 ;
V_54 -> V_94 . V_117 = V_32 -> V_54 . V_94 . V_117 ;
V_54 -> V_94 . V_97 = V_32 -> V_54 . V_94 . V_97 ;
V_54 -> V_94 . V_95 = V_32 -> V_54 . V_94 . V_95 ;
V_54 -> V_94 . V_106 = V_32 -> V_54 . V_94 . V_106 ;
V_54 -> V_94 . V_18 . V_19 = V_32 -> V_54 . V_94 . V_18 . V_19 ;
V_54 -> V_94 . V_18 . V_21 = V_32 -> V_54 . V_94 . V_18 . V_21 ;
V_54 -> V_94 . V_113 . V_114 = V_32 -> V_54 . V_94 . V_113 . V_114 ;
V_54 -> V_94 . V_113 . V_116 = V_32 -> V_54 . V_94 . V_113 . V_116 ;
return 0 ;
}
static long F_27 ( struct V_57 * V_58 ,
unsigned int V_140 , void * V_139 )
{
struct V_60 * V_54 = (struct V_60 * ) V_139 ;
int V_141 = - V_142 ;
switch ( V_140 ) {
case V_143 :
V_141 = F_24 ( V_58 , V_54 ) ;
break;
case V_144 :
V_141 = F_26 ( V_58 , V_139 ) ;
break;
}
return V_141 ;
}
static int F_28 ( struct V_145 * V_146 )
{
struct V_31 * V_32 =
F_29 ( V_146 -> V_147 , struct V_31 , V_148 ) ;
switch ( V_146 -> V_149 ) {
case V_150 :
V_32 -> V_103 = V_146 -> V_16 ;
break;
case V_151 :
V_32 -> V_82 = V_146 -> V_16 ;
break;
default:
return - V_30 ;
}
return 0 ;
}
void F_30 ( struct V_51 * V_52 )
{
struct V_31 * V_32 = & V_52 -> V_53 ;
void * V_64 = V_32 -> V_64 ;
unsigned char V_16 ;
if ( V_32 -> V_25 != V_26 )
return;
do {
V_16 = F_2 ( V_64 , V_152 ) ;
} while ( V_16 & 0x1 );
F_4 ( V_153 , V_64 , V_152 ) ;
}
static int F_31 ( struct V_57 * V_58 , int V_154 )
{
struct V_31 * V_32 = F_19 ( V_58 ) ;
struct V_51 * V_52 = F_32 ( V_32 ) ;
int V_141 = 0 ;
if ( ! V_154 )
return V_141 ;
V_141 = F_18 ( V_58 ) ;
if ( ! V_141 )
F_30 ( V_52 ) ;
return V_141 ;
}
static int F_33 ( struct V_57 * V_58 ,
struct V_155 * V_156 ,
struct V_157 * V_37 )
{
switch ( V_37 -> V_158 ) {
case V_36 :
if ( V_37 -> V_159 >= F_34 ( V_160 ) )
return - V_30 ;
V_37 -> V_37 = V_160 [ V_37 -> V_159 ] ;
break;
case V_69 :
if ( V_37 -> V_159 >= F_34 ( V_161 ) )
return - V_30 ;
V_37 -> V_37 = V_161 [ V_37 -> V_159 ] ;
break;
default:
return - V_30 ;
}
return 0 ;
}
static int
F_35 ( struct V_57 * V_58 , struct V_155 * V_156 ,
struct V_162 * V_163 )
{
struct V_31 * V_32 = F_19 ( V_58 ) ;
if ( V_163 -> V_164 == V_165 )
V_163 -> V_166 = V_32 -> V_35 [ V_163 -> V_158 ] ;
else
V_163 -> V_166 = * ( F_36 ( V_156 , V_163 -> V_158 ) ) ;
return 0 ;
}
static void
F_37 ( struct V_31 * V_32 ,
struct V_155 * V_156 , unsigned int V_158 ,
struct V_33 * V_163 ,
enum V_167 V_164 )
{
unsigned int V_168 ;
unsigned int V_169 ;
unsigned int V_170 ;
V_169 = V_171 ;
V_168 = V_172 ;
if ( V_158 == V_36 ) {
for ( V_170 = 0 ; V_170 < F_34 ( V_160 ) ; V_170 ++ )
if ( V_163 -> V_37 == V_160 [ V_170 ] )
break;
if ( V_170 >= F_34 ( V_160 ) )
V_163 -> V_37 = V_10 ;
} else if ( V_158 == V_69 ) {
for ( V_170 = 0 ; V_170 < F_34 ( V_161 ) ; V_170 ++ )
if ( V_163 -> V_37 == V_161 [ V_170 ] )
break;
if ( V_170 >= F_34 ( V_161 ) )
V_163 -> V_37 = V_43 ;
}
V_163 -> V_89 = F_38 ( T_1 , V_163 -> V_89 , V_173 , V_169 ) ;
V_163 -> V_91 = F_38 ( T_1 , V_163 -> V_91 , V_174 , V_168 ) ;
}
static int
F_39 ( struct V_57 * V_58 , struct V_155 * V_156 ,
struct V_175 * V_176 )
{
struct V_31 * V_32 = F_19 ( V_58 ) ;
struct V_33 V_166 ;
if ( V_176 -> V_159 != 0 )
return - V_30 ;
V_166 . V_37 = V_176 -> V_37 ;
V_166 . V_89 = 1 ;
V_166 . V_91 = 1 ;
F_37 ( V_32 , V_156 , V_176 -> V_158 , & V_166 ,
V_177 ) ;
V_176 -> V_178 = V_166 . V_89 ;
V_176 -> V_179 = V_166 . V_91 ;
if ( V_166 . V_37 != V_176 -> V_37 )
return - V_30 ;
V_166 . V_37 = V_176 -> V_37 ;
V_166 . V_89 = - 1 ;
V_166 . V_91 = - 1 ;
F_37 ( V_32 , V_156 , V_176 -> V_158 , & V_166 ,
V_177 ) ;
V_176 -> V_180 = V_166 . V_89 ;
V_176 -> V_181 = V_166 . V_91 ;
return 0 ;
}
static struct V_33 *
F_40 ( struct V_31 * V_32 ,
struct V_155 * V_156 , unsigned int V_158 ,
enum V_167 V_164 )
{
if ( V_164 == V_177 )
return F_36 ( V_156 , V_158 ) ;
return & V_32 -> V_35 [ V_158 ] ;
}
static int
F_41 ( struct V_57 * V_58 , struct V_155 * V_156 ,
struct V_162 * V_163 )
{
struct V_31 * V_32 = F_19 ( V_58 ) ;
struct V_33 * V_166 ;
V_166 = F_40 ( V_32 , V_156 , V_163 -> V_158 , V_163 -> V_164 ) ;
if ( V_166 == NULL )
return - V_30 ;
F_37 ( V_32 , V_156 , V_163 -> V_158 , & V_163 -> V_166 , V_163 -> V_164 ) ;
* V_166 = V_163 -> V_166 ;
if ( V_163 -> V_164 == V_177 )
return 0 ;
if ( V_163 -> V_158 == V_36 &&
V_32 -> V_25 != V_182 )
V_32 -> V_35 [ V_163 -> V_158 ] = V_163 -> V_166 ;
else if ( V_163 -> V_158 == V_69 &&
V_32 -> V_183 != V_184 )
V_32 -> V_35 [ V_163 -> V_158 ] = V_163 -> V_166 ;
else
return - V_30 ;
return 0 ;
}
static void F_42 ( struct V_31 * V_32 )
{
#define F_43 640
#define F_44 480
const struct V_60 V_185 = {
. V_72 = V_111 ,
. V_85 = F_43 + 8 ,
. V_87 = F_44 + 10 ,
. V_56 = 16 ,
. V_55 = V_186 ,
. V_74 = V_187 ,
. V_94 = {
. V_113 = {
. V_114 = 1 ,
. V_116 = 6
} ,
. V_106 = 4095 ,
} ,
} ;
memset ( & V_32 -> V_54 , 0 , sizeof( struct V_60 ) ) ;
memcpy ( & V_32 -> V_54 , & V_185 ,
sizeof( struct V_60 ) ) ;
}
static int
F_45 ( struct V_57 * V_58 , struct V_155 * V_156 )
{
struct V_31 * V_32 = F_19 ( V_58 ) ;
struct V_162 V_166 ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_158 = V_36 ;
V_166 . V_164 = V_156 ? V_177 : V_165 ;
V_166 . V_166 . V_37 = V_10 ;
V_166 . V_166 . V_89 = V_171 ;
V_166 . V_166 . V_91 = V_172 ;
F_41 ( V_58 , V_156 , & V_166 ) ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_158 = V_69 ;
V_166 . V_164 = V_156 ? V_177 : V_165 ;
V_166 . V_166 . V_37 = V_43 ;
V_166 . V_166 . V_89 = V_171 ;
V_166 . V_166 . V_91 = V_172 ;
F_41 ( V_58 , V_156 , & V_166 ) ;
F_42 ( V_32 ) ;
return 0 ;
}
static int
F_46 ( struct V_51 * V_52 , unsigned long V_14 )
{
struct V_31 * V_32 = & V_52 -> V_53 ;
void * V_64 = V_32 -> V_64 ;
unsigned int V_188 ;
T_1 V_16 ;
if ( V_32 -> V_25 != V_26 )
return - V_30 ;
switch ( V_32 -> V_35 [ V_36 ] . V_37 ) {
case V_4 :
case V_6 :
case V_189 :
V_188 = V_32 -> V_35 [ V_36 ] . V_89 ;
break;
default:
V_188 = V_32 -> V_35 [ V_36 ] . V_89 << 1 ;
break;
}
V_188 += 31 ;
V_188 &= ~ 0x1f ;
V_16 = ( V_188 >> 5 ) & V_190 ;
F_4 ( V_16 , V_64 , V_191 ) ;
V_16 = ( V_14 >> V_192 ) & V_193 ;
F_4 ( V_16 , V_64 , V_194 ) ;
V_16 = ( V_14 >> V_195 ) & V_196 ;
F_4 ( V_16 , V_64 , V_197 ) ;
return 0 ;
}
static int
F_47 ( struct V_198 * V_199 , const struct V_200 * V_201 ,
const struct V_200 * V_202 , T_1 V_203 )
{
struct V_57 * V_58 = F_48 ( V_199 ) ;
struct V_31 * V_32 = F_19 ( V_58 ) ;
struct V_51 * V_204 = F_32 ( V_32 ) ;
switch ( V_201 -> V_159 | F_49 ( V_202 -> V_199 ) ) {
case V_36 | V_205 :
if ( ! ( V_203 & V_206 ) ) {
V_32 -> V_25 = V_182 ;
break;
}
V_32 -> V_25 = V_26 ;
break;
case V_36 | V_207 :
if ( ! ( V_203 & V_206 ) ) {
V_32 -> V_25 = V_182 ;
break;
}
if ( V_32 -> V_25 != V_182 )
return - V_208 ;
V_32 -> V_25 = V_28 ;
break;
case V_69 | V_207 :
if ( ! ( V_203 & V_206 ) ) {
V_32 -> V_183 = V_184 ;
break;
}
if ( V_202 -> V_199 == & V_204 -> V_209 . V_135 . V_199 )
V_32 -> V_183 = V_210 ;
else if ( V_202 -> V_199 == & V_204 -> V_211 .
V_212 . V_135 . V_199 )
V_32 -> V_183 = V_213 ;
else
return - V_30 ;
break;
default:
return - V_30 ;
}
return 0 ;
}
void F_50 ( struct V_31 * V_32 )
{
F_51 ( & V_32 -> V_47 ) ;
F_52 ( & V_32 -> V_135 ) ;
F_53 ( & V_32 -> V_135 . V_199 ) ;
}
int
F_54 ( struct V_31 * V_32 ,
struct V_214 * V_215 )
{
struct V_51 * V_52 = F_32 ( V_32 ) ;
unsigned int V_203 ;
int V_141 ;
V_141 = F_55 ( V_215 , & V_32 -> V_135 ) ;
if ( V_141 < 0 )
return V_141 ;
V_141 = F_56 ( & V_32 -> V_47 , V_215 ) ;
if ( V_141 ) {
F_21 ( L_4 ) ;
goto V_216;
}
V_32 -> V_47 . V_52 = V_52 ;
V_203 = 0 ;
V_141 = F_57 ( & V_32 -> V_47 . V_217 . V_199 , 0 ,
& V_32 -> V_135 . V_199 , 0 , V_203 ) ;
if ( V_141 < 0 )
goto V_216;
return 0 ;
V_216:
F_52 ( & V_32 -> V_135 ) ;
return V_141 ;
}
int F_58 ( struct V_31 * V_32 ,
struct V_218 * V_219 )
{
struct V_57 * V_58 = & V_32 -> V_135 ;
struct V_200 * V_220 = & V_32 -> V_220 [ 0 ] ;
struct V_198 * V_221 = & V_58 -> V_199 ;
static T_3 V_222 ;
struct V_223 * V_224 ;
int V_141 ;
V_224 = F_59 ( V_219 , V_225 , 3 ) ;
if ( ! V_224 )
return - V_226 ;
V_222 = F_60 ( V_224 ) ;
V_224 = F_61 ( V_224 -> V_227 , V_222 , V_224 -> V_228 ) ;
if ( ! V_224 )
return - V_208 ;
V_32 -> V_64 = F_62 ( V_224 -> V_227 , V_222 ) ;
if ( ! V_32 -> V_64 ) {
V_141 = - V_208 ;
goto V_216;
}
F_63 ( V_58 , & V_229 ) ;
V_58 -> V_230 = & V_231 ;
F_64 ( V_58 -> V_228 , L_5 , sizeof( V_58 -> V_228 ) ) ;
V_58 -> V_232 = 1 << 16 ;
F_65 ( V_58 , V_32 ) ;
V_58 -> V_203 |= V_233 | V_234 ;
V_220 [ V_36 ] . V_203 = V_235 ;
V_220 [ V_69 ] . V_203 = V_236 ;
V_32 -> V_25 = V_182 ;
V_32 -> V_183 = V_184 ;
V_221 -> V_237 = & V_238 ;
V_141 = F_66 ( V_221 , V_239 , V_220 , 0 ) ;
if ( V_141 )
goto V_216;
F_67 ( & V_32 -> V_148 , 2 ) ;
F_68 ( & V_32 -> V_148 , & V_240 ,
V_151 , 0 ,
V_241 , 1 , V_242 ) ;
F_69 ( & V_32 -> V_148 , & V_243 , NULL ) ;
F_70 ( & V_32 -> V_148 ) ;
V_58 -> V_244 = & V_32 -> V_148 ;
V_32 -> V_47 . V_237 = & V_245 ;
V_32 -> V_47 . type = V_246 ;
V_141 = F_71 ( & V_32 -> V_47 , L_6 ) ;
if ( V_141 ) {
F_21 ( L_7 ) ;
goto V_216;
}
F_42 ( V_32 ) ;
return 0 ;
V_216:
F_72 ( V_224 -> V_227 , V_222 ) ;
return V_141 ;
}
void
F_73 ( struct V_31 * V_32 ,
struct V_218 * V_219 )
{
struct V_223 * V_224 ;
F_74 ( & V_32 -> V_148 ) ;
F_75 ( V_32 -> V_64 ) ;
V_224 = F_59 ( V_219 , V_225 , 3 ) ;
if ( V_224 )
F_72 ( V_224 -> V_227 , F_60 ( V_224 ) ) ;
}
