static int
F_1 ( T_1 V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 :
case V_4 :
case V_5 :
return V_6 ;
case V_7 :
return V_8 ;
case V_9 :
return V_10 ;
case V_11 :
return V_12 ;
default:
return V_10 ;
}
}
static inline T_1 F_2 ( void * V_13 , T_1 V_14 )
{
return F_3 ( V_13 + V_14 ) ;
}
static inline void F_4 ( T_1 V_15 , void * V_13 , T_1 V_14 )
{
F_5 ( V_15 , V_13 + V_14 ) ;
}
static void F_6 ( void * V_13 , struct V_16 * V_17 )
{
T_1 V_15 = 0 ;
if ( V_17 -> V_18 ) {
V_15 = ( V_17 -> V_18 & 1 ) << V_19 ;
V_15 |= V_17 -> V_20 & V_21 ;
}
F_4 ( V_15 , V_13 , V_22 ) ;
}
static int F_7 ( enum V_23 V_24 )
{
if ( V_24 == V_25 )
return V_26 ;
else if ( V_24 == V_27 )
return V_28 ;
return - V_29 ;
}
static int
F_8 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
V_33 = & V_31 -> V_34 [ V_35 ] ;
if ( V_31 -> V_24 == V_25 &&
( V_33 -> V_36 == V_3 ||
V_33 -> V_36 == V_5 ) )
return V_37 ;
return V_38 ;
}
static int
F_9 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
V_33 = & V_31 -> V_34 [ V_35 ] ;
switch ( V_33 -> V_36 ) {
case V_9 :
return V_39 ;
case V_3 :
case V_5 :
return V_39 ;
default:
return V_40 ;
}
}
static enum V_41
F_10 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
V_33 = & V_31 -> V_34 [ V_35 ] ;
if ( V_31 -> V_24 == V_27 )
return V_37 ;
if ( V_33 -> V_36 == V_42 )
return V_43 ;
return V_44 ;
}
void F_11 ( struct V_30 * V_31 )
{
struct V_45 * V_46 = & V_31 -> V_46 ;
if ( V_31 -> V_24 != V_25 )
return;
F_12 ( & V_46 -> V_47 ) ;
F_13 ( V_46 ) ;
V_46 -> V_48 = V_49 ;
F_14 ( V_46 ) ;
F_15 ( & V_46 -> V_47 ) ;
}
int F_16 ( struct V_50 * V_51 )
{
struct V_30 * V_31 = & V_51 -> V_52 ;
return V_31 -> V_53 . V_54 ;
}
int F_17 ( struct V_50 * V_51 )
{
struct V_30 * V_31 = & V_51 -> V_52 ;
return V_31 -> V_53 . V_55 ;
}
static int F_18 ( struct V_56 * V_57 )
{
struct V_30 * V_31 = F_19 ( V_57 ) ;
struct V_32 * V_33 , * V_58 ;
struct V_59 V_60 = V_31 -> V_53 ;
enum V_41 V_61 ;
T_1 V_62 ;
void * V_63 ;
unsigned int V_15 ;
int V_64 ;
int V_65 ;
int V_66 ;
int V_67 ;
V_63 = V_31 -> V_63 ;
F_20 ( V_68 , 1 ) ;
V_33 = & V_31 -> V_34 [ V_35 ] ;
V_58 = & V_31 -> V_34 [ V_69 ] ;
V_67 = V_15 = F_7 ( V_31 -> V_24 ) ;
if ( V_67 < 0 ) {
F_21 ( & V_57 -> V_70 -> V_71 , L_1 ) ;
return - V_29 ;
}
V_15 <<= V_72 ;
V_61 = F_10 ( V_31 ) ;
V_15 |= V_61 << V_73 ;
V_15 |= V_60 . V_74 << V_75 ;
V_15 |= V_60 . V_76 << V_77 ;
V_15 |= V_60 . V_54 << V_78 ;
V_65 = F_1 ( V_33 -> V_36 ) ;
V_15 |= V_65 << V_79 ;
V_66 = F_8 ( V_31 ) ;
V_15 |= V_66 << V_80 ;
V_64 = F_9 ( V_31 ) ;
if ( V_61 != V_43 )
V_15 |= V_64 << V_81 ;
else
V_15 &= ~ ( V_82 << V_81 ) ;
F_4 ( V_15 , V_63 , V_83 ) ;
switch ( V_61 ) {
case V_37 :
F_4 ( V_31 -> V_84 , V_63 , V_85 ) ;
break;
case V_44 :
case V_86 :
F_4 ( V_31 -> V_84 , V_63 , V_85 ) ;
case V_43 :
V_15 |= V_64 << V_81 ;
F_4 ( V_60 . V_87 , V_63 , V_88 ) ;
F_4 ( V_60 . V_89 , V_63 , V_90 ) ;
F_4 ( V_33 -> V_91 , V_63 , V_92 ) ;
F_4 ( V_33 -> V_93 ,
V_63 , V_94 ) ;
break;
default:
return - V_29 ;
}
if ( V_60 . V_54 )
F_4 ( V_60 . V_55 , V_63 , V_95 ) ;
V_15 = V_60 . V_96 . V_97 & 1 ;
V_15 <<= V_98 ;
V_15 |= V_60 . V_96 . V_99 & V_100 ;
F_4 ( V_15 , V_63 , V_101 ) ;
V_62 = V_33 -> V_36 ;
if ( V_62 == V_3 )
V_62 = V_102 ;
else if ( V_62 == V_5 )
V_62 = V_9 ;
switch ( V_61 ) {
case V_44 :
V_15 = 0 ;
if ( V_58 -> V_36 == V_4 ) {
V_15 = 1 ;
V_15 |= ( V_103 & 1 ) <<
V_104 ;
V_15 |= ( V_31 -> V_105 & 1 ) <<
V_106 ;
}
F_4 ( V_15 , V_63 , V_107 ) ;
F_6 ( V_63 , & V_60 . V_96 . V_17 ) ;
F_4 ( V_60 . V_96 . V_108 ,
V_63 , V_109 ) ;
V_15 = F_2 ( V_63 , V_110 ) ;
switch ( V_62 ) {
case V_102 :
case V_42 :
case V_3 :
F_22 ( V_15 , V_111 ) ;
F_23 ( V_15 , V_112 ) ;
F_4 ( V_15 , V_63 , V_110 ) ;
break;
default:
F_22 ( V_15 , V_111 ) ;
F_22 ( V_15 , V_112 ) ;
F_4 ( V_15 , V_63 , V_110 ) ;
break;
}
case V_43 :
if ( V_60 . V_74 == V_113 ) {
V_15 = F_2 ( V_63 , V_114 ) ;
V_15 |= ( V_60 . V_96 . V_115 . V_116 - 1 ) <<
V_117 ;
V_15 |= ( V_60 . V_96 . V_115 . V_118 - 1 ) ;
F_4 ( V_15 , V_63 , V_114 ) ;
}
break;
case V_37 :
case V_86 :
F_6 ( V_63 , & V_60 . V_96 . V_17 ) ;
V_15 = 0 ;
if ( V_60 . V_96 . V_119 ) {
V_15 = V_60 . V_96 . V_120 &
V_121 ;
F_4 ( V_15 , V_63 , V_122 ) ;
V_15 = ( V_60 . V_96 . V_119 & 1 ) <<
V_123 ;
V_15 |= V_60 . V_96 . V_124 &
V_125 ;
}
F_4 ( V_15 , V_63 , V_126 ) ;
V_15 = V_127 << V_128 ;
V_15 |= V_127 << V_129 ;
switch ( V_62 ) {
case V_102 :
case V_130 :
F_22 ( V_15 , V_111 ) ;
F_23 ( V_15 , V_112 ) ;
break;
case V_131 :
case V_42 :
case V_3 :
case V_132 :
F_23 ( V_15 , V_111 ) ;
F_23 ( V_15 , V_112 ) ;
V_15 |= V_133 << V_134 ;
break;
default:
F_4 ( V_60 . V_96 . V_108 , V_63 ,
V_109 ) ;
}
F_4 ( V_15 , V_63 , V_110 ) ;
break;
default:
return - V_29 ;
}
return 0 ;
}
static int
F_24 ( struct V_56 * V_57 , struct V_59 * V_53 )
{
struct V_30 * V_31 = F_19 ( V_57 ) ;
struct V_135 * V_71 = V_31 -> V_136 . V_137 -> V_71 ;
if ( ! V_53 ) {
F_21 ( V_71 , L_2 ) ;
return - V_29 ;
}
V_31 -> V_53 . V_74 = V_53 -> V_74 ;
V_31 -> V_53 . V_87 = V_53 -> V_87 ;
V_31 -> V_53 . V_89 = V_53 -> V_89 ;
V_31 -> V_53 . V_55 = V_53 -> V_55 ;
V_31 -> V_53 . V_54 = V_53 -> V_54 ;
if ( V_31 -> V_53 . V_54 &&
( V_31 -> V_53 . V_55 < V_138 ||
V_31 -> V_53 . V_55 > V_139 ) ) {
F_21 ( V_71 , L_3 ,
V_138 , V_139 ) ;
return - V_29 ;
}
V_31 -> V_53 . V_76 = V_53 -> V_76 ;
V_31 -> V_53 . V_96 . V_120 = V_53 -> V_96 . V_120 ;
V_31 -> V_53 . V_96 . V_124 = V_53 -> V_96 . V_124 ;
V_31 -> V_53 . V_96 . V_119 = V_53 -> V_96 . V_119 ;
V_31 -> V_53 . V_96 . V_99 = V_53 -> V_96 . V_99 ;
V_31 -> V_53 . V_96 . V_97 = V_53 -> V_96 . V_97 ;
V_31 -> V_53 . V_96 . V_108 = V_53 -> V_96 . V_108 ;
V_31 -> V_53 . V_96 . V_17 . V_18 = V_53 -> V_96 . V_17 . V_18 ;
V_31 -> V_53 . V_96 . V_17 . V_20 = V_53 -> V_96 . V_17 . V_20 ;
V_31 -> V_53 . V_96 . V_115 . V_116 = V_53 -> V_96 . V_115 . V_116 ;
V_31 -> V_53 . V_96 . V_115 . V_118 = V_53 -> V_96 . V_115 . V_118 ;
return 0 ;
}
static int
F_25 ( struct V_56 * V_57 , void T_2 * V_140 )
{
struct V_30 * V_31 = F_19 ( V_57 ) ;
struct V_59 * V_53 = V_140 ;
struct V_135 * V_71 = V_31 -> V_136 . V_137 -> V_71 ;
if ( ! V_140 ) {
F_21 ( V_71 , L_2 ) ;
return - V_29 ;
}
V_53 -> V_74 = V_31 -> V_53 . V_74 ;
V_53 -> V_87 = V_31 -> V_53 . V_87 ;
V_53 -> V_89 = V_31 -> V_53 . V_89 ;
V_53 -> V_55 = V_31 -> V_53 . V_55 ;
V_53 -> V_54 = V_31 -> V_53 . V_54 ;
V_53 -> V_76 = V_31 -> V_53 . V_76 ;
V_53 -> V_96 . V_120 = V_31 -> V_53 . V_96 . V_120 ;
V_53 -> V_96 . V_124 = V_31 -> V_53 . V_96 . V_124 ;
V_53 -> V_96 . V_119 = V_31 -> V_53 . V_96 . V_119 ;
V_53 -> V_96 . V_99 = V_31 -> V_53 . V_96 . V_99 ;
V_53 -> V_96 . V_97 = V_31 -> V_53 . V_96 . V_97 ;
V_53 -> V_96 . V_108 = V_31 -> V_53 . V_96 . V_108 ;
V_53 -> V_96 . V_17 . V_18 = V_31 -> V_53 . V_96 . V_17 . V_18 ;
V_53 -> V_96 . V_17 . V_20 = V_31 -> V_53 . V_96 . V_17 . V_20 ;
V_53 -> V_96 . V_115 . V_116 = V_31 -> V_53 . V_96 . V_115 . V_116 ;
V_53 -> V_96 . V_115 . V_118 = V_31 -> V_53 . V_96 . V_115 . V_118 ;
return 0 ;
}
static long F_26 ( struct V_56 * V_57 ,
unsigned int V_141 , void * V_140 )
{
struct V_59 * V_53 = V_140 ;
int V_142 = - V_143 ;
switch ( V_141 ) {
case V_144 :
V_142 = F_24 ( V_57 , V_53 ) ;
break;
case V_145 :
V_142 = F_25 ( V_57 , V_140 ) ;
break;
}
return V_142 ;
}
static int F_27 ( struct V_146 * V_147 )
{
struct V_30 * V_31 =
F_28 ( V_147 -> V_148 , struct V_30 , V_149 ) ;
switch ( V_147 -> V_150 ) {
case V_151 :
V_31 -> V_105 = V_147 -> V_15 ;
break;
case V_152 :
V_31 -> V_84 = V_147 -> V_15 ;
break;
default:
return - V_29 ;
}
return 0 ;
}
void F_29 ( struct V_50 * V_51 )
{
struct V_30 * V_31 = & V_51 -> V_52 ;
void * V_63 = V_31 -> V_63 ;
unsigned char V_15 ;
if ( V_31 -> V_24 != V_25 )
return;
do {
V_15 = F_2 ( V_63 , V_153 ) ;
} while ( V_15 & 0x1 );
F_4 ( V_154 , V_63 , V_153 ) ;
}
static int F_30 ( struct V_56 * V_57 , int V_155 )
{
struct V_30 * V_31 = F_19 ( V_57 ) ;
struct V_50 * V_51 = F_31 ( V_31 ) ;
int V_142 = 0 ;
if ( ! V_155 )
return V_142 ;
V_142 = F_18 ( V_57 ) ;
if ( ! V_142 )
F_29 ( V_51 ) ;
return V_142 ;
}
static int F_32 ( struct V_56 * V_57 ,
struct V_156 * V_157 ,
struct V_158 * V_36 )
{
switch ( V_36 -> V_159 ) {
case V_35 :
if ( V_36 -> V_160 >= F_33 ( V_161 ) )
return - V_29 ;
V_36 -> V_36 = V_161 [ V_36 -> V_160 ] ;
break;
case V_69 :
if ( V_36 -> V_160 >= F_33 ( V_162 ) )
return - V_29 ;
V_36 -> V_36 = V_162 [ V_36 -> V_160 ] ;
break;
default:
return - V_29 ;
}
return 0 ;
}
static int
F_34 ( struct V_56 * V_57 , struct V_156 * V_157 ,
struct V_163 * V_164 )
{
struct V_30 * V_31 = F_19 ( V_57 ) ;
if ( V_164 -> V_165 == V_166 )
V_164 -> V_167 = V_31 -> V_34 [ V_164 -> V_159 ] ;
else
V_164 -> V_167 = * ( F_35 ( V_57 , V_157 , V_164 -> V_159 ) ) ;
return 0 ;
}
static void
F_36 ( struct V_30 * V_31 ,
struct V_156 * V_157 , unsigned int V_159 ,
struct V_32 * V_164 ,
enum V_168 V_165 )
{
unsigned int V_169 ;
unsigned int V_170 ;
unsigned int V_171 ;
V_170 = V_172 ;
V_169 = V_173 ;
if ( V_159 == V_35 ) {
for ( V_171 = 0 ; V_171 < F_33 ( V_161 ) ; V_171 ++ )
if ( V_164 -> V_36 == V_161 [ V_171 ] )
break;
if ( V_171 >= F_33 ( V_161 ) )
V_164 -> V_36 = V_9 ;
} else if ( V_159 == V_69 ) {
for ( V_171 = 0 ; V_171 < F_33 ( V_162 ) ; V_171 ++ )
if ( V_164 -> V_36 == V_162 [ V_171 ] )
break;
if ( V_171 >= F_33 ( V_162 ) )
V_164 -> V_36 = V_42 ;
}
V_164 -> V_91 = F_37 ( T_1 , V_164 -> V_91 , V_174 , V_170 ) ;
V_164 -> V_93 = F_37 ( T_1 , V_164 -> V_93 , V_175 , V_169 ) ;
}
static int
F_38 ( struct V_56 * V_57 , struct V_156 * V_157 ,
struct V_176 * V_177 )
{
struct V_30 * V_31 = F_19 ( V_57 ) ;
struct V_32 V_167 ;
if ( V_177 -> V_160 != 0 )
return - V_29 ;
V_167 . V_36 = V_177 -> V_36 ;
V_167 . V_91 = 1 ;
V_167 . V_93 = 1 ;
F_36 ( V_31 , V_157 , V_177 -> V_159 , & V_167 , V_177 -> V_165 ) ;
V_177 -> V_178 = V_167 . V_91 ;
V_177 -> V_179 = V_167 . V_93 ;
if ( V_167 . V_36 != V_177 -> V_36 )
return - V_29 ;
V_167 . V_36 = V_177 -> V_36 ;
V_167 . V_91 = - 1 ;
V_167 . V_93 = - 1 ;
F_36 ( V_31 , V_157 , V_177 -> V_159 , & V_167 , V_177 -> V_165 ) ;
V_177 -> V_180 = V_167 . V_91 ;
V_177 -> V_181 = V_167 . V_93 ;
return 0 ;
}
static struct V_32 *
F_39 ( struct V_30 * V_31 ,
struct V_156 * V_157 , unsigned int V_159 ,
enum V_168 V_165 )
{
if ( V_165 == V_182 )
return F_35 ( & V_31 -> V_136 , V_157 , V_159 ) ;
return & V_31 -> V_34 [ V_159 ] ;
}
static int
F_40 ( struct V_56 * V_57 , struct V_156 * V_157 ,
struct V_163 * V_164 )
{
struct V_30 * V_31 = F_19 ( V_57 ) ;
struct V_32 * V_167 ;
V_167 = F_39 ( V_31 , V_157 , V_164 -> V_159 , V_164 -> V_165 ) ;
if ( V_167 == NULL )
return - V_29 ;
F_36 ( V_31 , V_157 , V_164 -> V_159 , & V_164 -> V_167 , V_164 -> V_165 ) ;
* V_167 = V_164 -> V_167 ;
if ( V_164 -> V_165 == V_182 )
return 0 ;
if ( V_164 -> V_159 == V_35 &&
V_31 -> V_24 != V_183 )
V_31 -> V_34 [ V_164 -> V_159 ] = V_164 -> V_167 ;
else if ( V_164 -> V_159 == V_69 &&
V_31 -> V_184 != V_185 )
V_31 -> V_34 [ V_164 -> V_159 ] = V_164 -> V_167 ;
else
return - V_29 ;
return 0 ;
}
static void F_41 ( struct V_30 * V_31 )
{
#define F_42 640
#define F_43 480
const struct V_59 V_186 = {
. V_74 = V_113 ,
. V_87 = F_42 + 8 ,
. V_89 = F_43 + 10 ,
. V_55 = 16 ,
. V_54 = V_187 ,
. V_76 = V_188 ,
. V_96 = {
. V_115 = {
. V_116 = 1 ,
. V_118 = 6
} ,
. V_108 = 4095 ,
} ,
} ;
memcpy ( & V_31 -> V_53 , & V_186 ,
sizeof( struct V_59 ) ) ;
}
static int
F_44 ( struct V_56 * V_57 , struct V_189 * V_190 )
{
struct V_30 * V_31 = F_19 ( V_57 ) ;
struct V_163 V_167 ;
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
V_167 . V_159 = V_35 ;
V_167 . V_165 = V_182 ;
V_167 . V_167 . V_36 = V_9 ;
V_167 . V_167 . V_91 = V_172 ;
V_167 . V_167 . V_93 = V_173 ;
F_40 ( V_57 , V_190 -> V_159 , & V_167 ) ;
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
V_167 . V_159 = V_69 ;
V_167 . V_165 = V_182 ;
V_167 . V_167 . V_36 = V_42 ;
V_167 . V_167 . V_91 = V_172 ;
V_167 . V_167 . V_93 = V_173 ;
F_40 ( V_57 , V_190 -> V_159 , & V_167 ) ;
F_41 ( V_31 ) ;
return 0 ;
}
static int
F_45 ( struct V_50 * V_51 , unsigned long V_13 )
{
struct V_30 * V_31 = & V_51 -> V_52 ;
void * V_63 = V_31 -> V_63 ;
unsigned int V_191 ;
T_1 V_15 ;
if ( V_31 -> V_24 != V_25 )
return - V_29 ;
switch ( V_31 -> V_34 [ V_35 ] . V_36 ) {
case V_3 :
case V_5 :
case V_192 :
V_191 = V_31 -> V_34 [ V_35 ] . V_91 ;
break;
default:
V_191 = V_31 -> V_34 [ V_35 ] . V_91 << 1 ;
break;
}
V_191 += 31 ;
V_191 &= ~ 0x1f ;
V_15 = ( V_191 >> 5 ) & V_193 ;
F_4 ( V_15 , V_63 , V_194 ) ;
V_15 = ( V_13 >> V_195 ) & V_196 ;
F_4 ( V_15 , V_63 , V_197 ) ;
V_15 = ( V_13 >> V_198 ) & V_199 ;
F_4 ( V_15 , V_63 , V_200 ) ;
return 0 ;
}
static int
F_46 ( struct V_201 * V_202 , const struct V_203 * V_204 ,
const struct V_203 * V_205 , T_1 V_206 )
{
struct V_56 * V_57 = F_47 ( V_202 ) ;
struct V_30 * V_31 = F_19 ( V_57 ) ;
struct V_50 * V_207 = F_31 ( V_31 ) ;
unsigned int V_160 = V_204 -> V_160 ;
if ( F_48 ( V_205 -> V_202 ) )
V_160 |= 2 << 16 ;
switch ( V_160 ) {
case V_35 :
if ( ! ( V_206 & V_208 ) ) {
V_31 -> V_24 = V_183 ;
break;
}
V_31 -> V_24 = V_25 ;
break;
case V_35 | 2 << 16 :
if ( ! ( V_206 & V_208 ) ) {
V_31 -> V_24 = V_183 ;
break;
}
if ( V_31 -> V_24 != V_183 )
return - V_209 ;
V_31 -> V_24 = V_27 ;
break;
case V_69 | 2 << 16 :
if ( ! ( V_206 & V_208 ) ) {
V_31 -> V_184 = V_185 ;
break;
}
if ( V_205 -> V_202 == & V_207 -> V_210 . V_136 . V_202 )
V_31 -> V_184 = V_211 ;
else if ( V_205 -> V_202 == & V_207 -> V_212 .
V_213 . V_136 . V_202 )
V_31 -> V_184 = V_214 ;
else
return - V_29 ;
break;
default:
return - V_29 ;
}
return 0 ;
}
void F_49 ( struct V_30 * V_31 )
{
F_50 ( & V_31 -> V_46 ) ;
F_51 ( & V_31 -> V_136 ) ;
F_52 ( & V_31 -> V_136 . V_202 ) ;
}
int
F_53 ( struct V_30 * V_31 ,
struct V_215 * V_216 )
{
struct V_50 * V_51 = F_31 ( V_31 ) ;
unsigned int V_206 ;
int V_142 ;
V_142 = F_54 ( V_216 , & V_31 -> V_136 ) ;
if ( V_142 < 0 )
return V_142 ;
V_142 = F_55 ( & V_31 -> V_46 , V_216 ) ;
if ( V_142 ) {
F_56 ( L_4 ) ;
goto V_217;
}
V_31 -> V_46 . V_51 = V_51 ;
V_206 = 0 ;
V_142 = F_57 ( & V_31 -> V_46 . V_218 . V_202 , 0 ,
& V_31 -> V_136 . V_202 , 0 , V_206 ) ;
if ( V_142 < 0 )
goto V_217;
return 0 ;
V_217:
F_51 ( & V_31 -> V_136 ) ;
return V_142 ;
}
int F_58 ( struct V_30 * V_31 ,
struct V_219 * V_220 )
{
struct V_56 * V_57 = & V_31 -> V_136 ;
struct V_203 * V_221 = & V_31 -> V_221 [ 0 ] ;
struct V_201 * V_222 = & V_57 -> V_202 ;
static T_3 V_223 ;
struct V_224 * V_225 ;
int V_142 ;
V_225 = F_59 ( V_220 , V_226 , 3 ) ;
if ( ! V_225 )
return - V_227 ;
V_223 = F_60 ( V_225 ) ;
V_225 = F_61 ( V_225 -> V_228 , V_223 , V_225 -> V_229 ) ;
if ( ! V_225 )
return - V_209 ;
V_31 -> V_63 = F_62 ( V_225 -> V_228 , V_223 ) ;
if ( ! V_31 -> V_63 ) {
V_142 = - V_209 ;
goto V_217;
}
F_63 ( V_57 , & V_230 ) ;
V_57 -> V_231 = & V_232 ;
F_64 ( V_57 -> V_229 , L_5 , sizeof( V_57 -> V_229 ) ) ;
V_57 -> V_233 = 1 << 16 ;
F_65 ( V_57 , V_31 ) ;
V_57 -> V_206 |= V_234 | V_235 ;
V_221 [ V_35 ] . V_206 = V_236 ;
V_221 [ V_69 ] . V_206 = V_237 ;
V_31 -> V_24 = V_183 ;
V_31 -> V_184 = V_185 ;
V_222 -> V_238 = & V_239 ;
V_142 = F_66 ( V_222 , V_240 , V_221 ) ;
if ( V_142 )
goto V_217;
F_67 ( & V_31 -> V_149 , 2 ) ;
F_68 ( & V_31 -> V_149 , & V_241 ,
V_152 , 0 ,
V_242 , 1 , V_243 ) ;
F_69 ( & V_31 -> V_149 , & V_244 , NULL ) ;
F_70 ( & V_31 -> V_149 ) ;
V_57 -> V_245 = & V_31 -> V_149 ;
V_31 -> V_46 . V_238 = & V_246 ;
V_31 -> V_46 . type = V_247 ;
V_142 = F_71 ( & V_31 -> V_46 , L_6 ) ;
if ( V_142 ) {
F_56 ( L_7 ) ;
goto V_217;
}
F_41 ( V_31 ) ;
return 0 ;
V_217:
F_72 ( V_225 -> V_228 , V_223 ) ;
return V_142 ;
}
void
F_73 ( struct V_30 * V_31 ,
struct V_219 * V_220 )
{
struct V_224 * V_225 ;
F_74 ( & V_31 -> V_149 ) ;
F_75 ( V_31 -> V_63 ) ;
V_225 = F_59 ( V_220 , V_226 , 3 ) ;
if ( V_225 )
F_72 ( V_225 -> V_228 , F_60 ( V_225 ) ) ;
}
