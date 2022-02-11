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
int V_68 ;
V_64 = V_32 -> V_64 ;
F_20 ( V_69 , 1 ) ;
V_34 = & V_32 -> V_35 [ V_36 ] ;
V_59 = & V_32 -> V_35 [ V_70 ] ;
V_68 = V_16 = F_7 ( V_32 -> V_25 ) ;
if ( V_68 < 0 ) {
F_21 ( L_1 ) ;
return - V_30 ;
}
V_16 = V_16 << V_71 ;
V_62 = F_10 ( V_32 ) ;
V_16 |= V_62 << V_72 ;
V_16 |= V_61 . V_73 << V_74 ;
V_16 |= V_61 . V_75 << V_76 ;
V_16 |= V_61 . V_55 << V_77 ;
V_66 = F_1 ( V_34 -> V_37 ) ;
V_16 |= V_66 << V_78 ;
V_67 = F_8 ( V_32 ) ;
V_16 |= V_67 << V_79 ;
V_65 = F_9 ( V_32 ) ;
if ( V_62 != V_44 )
V_16 |= V_65 << V_80 ;
else
V_16 &= ~ ( V_81 << V_80 ) ;
F_4 ( V_16 , V_64 , V_82 ) ;
switch ( V_62 ) {
case V_38 :
F_4 ( V_32 -> V_83 , V_64 , V_84 ) ;
break;
case V_45 :
case V_85 :
F_4 ( V_32 -> V_83 , V_64 , V_84 ) ;
case V_44 :
V_16 |= V_65 << V_80 ;
F_4 ( V_61 . V_86 , V_64 , V_87 ) ;
F_4 ( V_61 . V_88 , V_64 , V_89 ) ;
F_4 ( V_34 -> V_90 , V_64 , V_91 ) ;
F_4 ( V_34 -> V_92 ,
V_64 , V_93 ) ;
break;
default:
return - V_30 ;
}
if ( V_61 . V_55 )
F_4 ( V_61 . V_56 , V_64 , V_94 ) ;
V_16 = V_61 . V_95 . V_96 & 1 ;
V_16 <<= V_97 ;
V_16 |= V_61 . V_95 . V_98 & V_99 ;
F_4 ( V_16 , V_64 , V_100 ) ;
V_63 = V_34 -> V_37 ;
if ( V_63 == V_4 )
V_63 = V_101 ;
else if ( V_63 == V_6 )
V_63 = V_10 ;
switch ( V_62 ) {
case V_45 :
V_16 = 0 ;
if ( V_59 -> V_37 == V_5 ) {
V_16 = 1 ;
V_16 |= ( V_102 & 1 ) <<
V_103 ;
V_16 |= ( V_32 -> V_104 & 1 ) <<
V_105 ;
}
F_4 ( V_16 , V_64 , V_106 ) ;
F_6 ( V_64 , & V_61 . V_95 . V_18 ) ;
F_4 ( V_61 . V_95 . V_107 ,
V_64 , V_108 ) ;
V_16 = F_2 ( V_64 , V_109 ) ;
switch ( V_63 ) {
case V_101 :
case V_43 :
case V_4 :
F_22 ( V_16 , V_110 ) ;
F_23 ( V_16 , V_111 ) ;
F_4 ( V_16 , V_64 , V_109 ) ;
break;
default:
F_22 ( V_16 , V_110 ) ;
F_22 ( V_16 , V_111 ) ;
F_4 ( V_16 , V_64 , V_109 ) ;
break;
}
case V_44 :
if ( V_61 . V_73 == V_112 ) {
V_16 = F_2 ( V_64 , V_113 ) ;
V_16 |= ( V_61 . V_95 . V_114 . V_115 - 1 ) <<
V_116 ;
V_16 |= ( V_61 . V_95 . V_114 . V_117 - 1 ) ;
F_4 ( V_16 , V_64 , V_113 ) ;
}
break;
case V_38 :
case V_85 :
F_6 ( V_64 , & V_61 . V_95 . V_18 ) ;
V_16 = 0 ;
if ( V_61 . V_95 . V_118 ) {
V_16 = V_61 . V_95 . V_119 &
V_120 ;
F_4 ( V_16 , V_64 , V_121 ) ;
V_16 = ( V_61 . V_95 . V_118 & 1 ) <<
V_122 ;
V_16 |= V_61 . V_95 . V_123 &
V_124 ;
}
F_4 ( V_16 , V_64 , V_125 ) ;
V_16 = V_126 << V_127 ;
V_16 |= V_126 << V_128 ;
switch ( V_63 ) {
case V_101 :
case V_129 :
F_22 ( V_16 , V_110 ) ;
F_23 ( V_16 , V_111 ) ;
break;
case V_130 :
case V_43 :
case V_4 :
case V_131 :
F_23 ( V_16 , V_110 ) ;
F_23 ( V_16 , V_111 ) ;
V_16 |= V_132 << V_133 ;
break;
default:
F_4 ( V_61 . V_95 . V_107 , V_64 ,
V_108 ) ;
}
F_4 ( V_16 , V_64 , V_109 ) ;
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
struct V_134 * V_135 = V_32 -> V_136 . V_137 -> V_135 ;
if ( ! V_54 ) {
F_25 ( V_135 , L_2 ) ;
return - V_30 ;
}
V_32 -> V_54 . V_73 = V_54 -> V_73 ;
V_32 -> V_54 . V_86 = V_54 -> V_86 ;
V_32 -> V_54 . V_88 = V_54 -> V_88 ;
V_32 -> V_54 . V_56 = V_54 -> V_56 ;
V_32 -> V_54 . V_55 = V_54 -> V_55 ;
if ( V_32 -> V_54 . V_55 &&
( V_32 -> V_54 . V_56 < V_138 ||
V_32 -> V_54 . V_56 > V_139 ) ) {
F_25 ( V_135 , L_3 ,
V_138 , V_139 ) ;
return - V_30 ;
}
V_32 -> V_54 . V_75 = V_54 -> V_75 ;
V_32 -> V_54 . V_95 . V_119 = V_54 -> V_95 . V_119 ;
V_32 -> V_54 . V_95 . V_123 = V_54 -> V_95 . V_123 ;
V_32 -> V_54 . V_95 . V_118 = V_54 -> V_95 . V_118 ;
V_32 -> V_54 . V_95 . V_98 = V_54 -> V_95 . V_98 ;
V_32 -> V_54 . V_95 . V_96 = V_54 -> V_95 . V_96 ;
V_32 -> V_54 . V_95 . V_107 = V_54 -> V_95 . V_107 ;
V_32 -> V_54 . V_95 . V_18 . V_19 = V_54 -> V_95 . V_18 . V_19 ;
V_32 -> V_54 . V_95 . V_18 . V_21 = V_54 -> V_95 . V_18 . V_21 ;
V_32 -> V_54 . V_95 . V_114 . V_115 = V_54 -> V_95 . V_114 . V_115 ;
V_32 -> V_54 . V_95 . V_114 . V_117 = V_54 -> V_95 . V_114 . V_117 ;
return 0 ;
}
static int
F_26 ( struct V_57 * V_58 , void T_2 * V_140 )
{
struct V_31 * V_32 = F_19 ( V_58 ) ;
struct V_60 * V_54 = (struct V_60 * ) V_140 ;
struct V_134 * V_135 = V_32 -> V_136 . V_137 -> V_135 ;
if ( ! V_140 ) {
F_25 ( V_135 , L_2 ) ;
return - V_30 ;
}
V_54 -> V_73 = V_32 -> V_54 . V_73 ;
V_54 -> V_86 = V_32 -> V_54 . V_86 ;
V_54 -> V_88 = V_32 -> V_54 . V_88 ;
V_54 -> V_56 = V_32 -> V_54 . V_56 ;
V_54 -> V_55 = V_32 -> V_54 . V_55 ;
V_54 -> V_75 = V_32 -> V_54 . V_75 ;
V_54 -> V_95 . V_119 = V_32 -> V_54 . V_95 . V_119 ;
V_54 -> V_95 . V_123 = V_32 -> V_54 . V_95 . V_123 ;
V_54 -> V_95 . V_118 = V_32 -> V_54 . V_95 . V_118 ;
V_54 -> V_95 . V_98 = V_32 -> V_54 . V_95 . V_98 ;
V_54 -> V_95 . V_96 = V_32 -> V_54 . V_95 . V_96 ;
V_54 -> V_95 . V_107 = V_32 -> V_54 . V_95 . V_107 ;
V_54 -> V_95 . V_18 . V_19 = V_32 -> V_54 . V_95 . V_18 . V_19 ;
V_54 -> V_95 . V_18 . V_21 = V_32 -> V_54 . V_95 . V_18 . V_21 ;
V_54 -> V_95 . V_114 . V_115 = V_32 -> V_54 . V_95 . V_114 . V_115 ;
V_54 -> V_95 . V_114 . V_117 = V_32 -> V_54 . V_95 . V_114 . V_117 ;
return 0 ;
}
static long F_27 ( struct V_57 * V_58 ,
unsigned int V_141 , void * V_140 )
{
struct V_60 * V_54 = (struct V_60 * ) V_140 ;
int V_142 = - V_143 ;
switch ( V_141 ) {
case V_144 :
V_142 = F_24 ( V_58 , V_54 ) ;
break;
case V_145 :
V_142 = F_26 ( V_58 , V_140 ) ;
break;
}
return V_142 ;
}
static int F_28 ( struct V_146 * V_147 )
{
struct V_31 * V_32 =
F_29 ( V_147 -> V_148 , struct V_31 , V_149 ) ;
switch ( V_147 -> V_150 ) {
case V_151 :
V_32 -> V_104 = V_147 -> V_16 ;
break;
case V_152 :
V_32 -> V_83 = V_147 -> V_16 ;
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
V_16 = F_2 ( V_64 , V_153 ) ;
} while ( V_16 & 0x1 );
F_4 ( V_154 , V_64 , V_153 ) ;
}
static int F_31 ( struct V_57 * V_58 , int V_155 )
{
struct V_31 * V_32 = F_19 ( V_58 ) ;
struct V_51 * V_52 = F_32 ( V_32 ) ;
int V_142 = 0 ;
if ( ! V_155 )
return V_142 ;
V_142 = F_18 ( V_58 ) ;
if ( ! V_142 )
F_30 ( V_52 ) ;
return V_142 ;
}
static int F_33 ( struct V_57 * V_58 ,
struct V_156 * V_157 ,
struct V_158 * V_37 )
{
switch ( V_37 -> V_159 ) {
case V_36 :
if ( V_37 -> V_160 >= F_34 ( V_161 ) )
return - V_30 ;
V_37 -> V_37 = V_161 [ V_37 -> V_160 ] ;
break;
case V_70 :
if ( V_37 -> V_160 >= F_34 ( V_162 ) )
return - V_30 ;
V_37 -> V_37 = V_162 [ V_37 -> V_160 ] ;
break;
default:
return - V_30 ;
}
return 0 ;
}
static int
F_35 ( struct V_57 * V_58 , struct V_156 * V_157 ,
struct V_163 * V_164 )
{
struct V_31 * V_32 = F_19 ( V_58 ) ;
if ( V_164 -> V_165 == V_166 )
V_164 -> V_167 = V_32 -> V_35 [ V_164 -> V_159 ] ;
else
V_164 -> V_167 = * ( F_36 ( V_157 , V_164 -> V_159 ) ) ;
return 0 ;
}
static void
F_37 ( struct V_31 * V_32 ,
struct V_156 * V_157 , unsigned int V_159 ,
struct V_33 * V_164 ,
enum V_168 V_165 )
{
unsigned int V_169 ;
unsigned int V_170 ;
unsigned int V_171 ;
V_170 = V_172 ;
V_169 = V_173 ;
if ( V_159 == V_36 ) {
for ( V_171 = 0 ; V_171 < F_34 ( V_161 ) ; V_171 ++ )
if ( V_164 -> V_37 == V_161 [ V_171 ] )
break;
if ( V_171 >= F_34 ( V_161 ) )
V_164 -> V_37 = V_10 ;
} else if ( V_159 == V_70 ) {
for ( V_171 = 0 ; V_171 < F_34 ( V_162 ) ; V_171 ++ )
if ( V_164 -> V_37 == V_162 [ V_171 ] )
break;
if ( V_171 >= F_34 ( V_162 ) )
V_164 -> V_37 = V_43 ;
}
V_164 -> V_90 = F_38 ( T_1 , V_164 -> V_90 , V_174 , V_170 ) ;
V_164 -> V_92 = F_38 ( T_1 , V_164 -> V_92 , V_175 , V_169 ) ;
}
static int
F_39 ( struct V_57 * V_58 , struct V_156 * V_157 ,
struct V_176 * V_177 )
{
struct V_31 * V_32 = F_19 ( V_58 ) ;
struct V_33 V_167 ;
if ( V_177 -> V_160 != 0 )
return - V_30 ;
V_167 . V_37 = V_177 -> V_37 ;
V_167 . V_90 = 1 ;
V_167 . V_92 = 1 ;
F_37 ( V_32 , V_157 , V_177 -> V_159 , & V_167 ,
V_178 ) ;
V_177 -> V_179 = V_167 . V_90 ;
V_177 -> V_180 = V_167 . V_92 ;
if ( V_167 . V_37 != V_177 -> V_37 )
return - V_30 ;
V_167 . V_37 = V_177 -> V_37 ;
V_167 . V_90 = - 1 ;
V_167 . V_92 = - 1 ;
F_37 ( V_32 , V_157 , V_177 -> V_159 , & V_167 ,
V_178 ) ;
V_177 -> V_181 = V_167 . V_90 ;
V_177 -> V_182 = V_167 . V_92 ;
return 0 ;
}
static struct V_33 *
F_40 ( struct V_31 * V_32 ,
struct V_156 * V_157 , unsigned int V_159 ,
enum V_168 V_165 )
{
if ( V_165 == V_178 )
return F_36 ( V_157 , V_159 ) ;
return & V_32 -> V_35 [ V_159 ] ;
}
static int
F_41 ( struct V_57 * V_58 , struct V_156 * V_157 ,
struct V_163 * V_164 )
{
struct V_31 * V_32 = F_19 ( V_58 ) ;
struct V_33 * V_167 ;
V_167 = F_40 ( V_32 , V_157 , V_164 -> V_159 , V_164 -> V_165 ) ;
if ( V_167 == NULL )
return - V_30 ;
F_37 ( V_32 , V_157 , V_164 -> V_159 , & V_164 -> V_167 , V_164 -> V_165 ) ;
* V_167 = V_164 -> V_167 ;
if ( V_164 -> V_165 == V_178 )
return 0 ;
if ( V_164 -> V_159 == V_36 &&
V_32 -> V_25 != V_183 )
V_32 -> V_35 [ V_164 -> V_159 ] = V_164 -> V_167 ;
else if ( V_164 -> V_159 == V_70 &&
V_32 -> V_184 != V_185 )
V_32 -> V_35 [ V_164 -> V_159 ] = V_164 -> V_167 ;
else
return - V_30 ;
return 0 ;
}
static void F_42 ( struct V_31 * V_32 )
{
#define F_43 640
#define F_44 480
const struct V_60 V_186 = {
. V_73 = V_112 ,
. V_86 = F_43 + 8 ,
. V_88 = F_44 + 10 ,
. V_56 = 16 ,
. V_55 = V_187 ,
. V_75 = V_188 ,
. V_95 = {
. V_114 = {
. V_115 = 1 ,
. V_117 = 6
} ,
. V_107 = 4095 ,
} ,
} ;
memset ( & V_32 -> V_54 , 0 , sizeof( struct V_60 ) ) ;
memcpy ( & V_32 -> V_54 , & V_186 ,
sizeof( struct V_60 ) ) ;
}
static int
F_45 ( struct V_57 * V_58 , struct V_156 * V_157 )
{
struct V_31 * V_32 = F_19 ( V_58 ) ;
struct V_163 V_167 ;
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
V_167 . V_159 = V_36 ;
V_167 . V_165 = V_157 ? V_178 : V_166 ;
V_167 . V_167 . V_37 = V_10 ;
V_167 . V_167 . V_90 = V_172 ;
V_167 . V_167 . V_92 = V_173 ;
F_41 ( V_58 , V_157 , & V_167 ) ;
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
V_167 . V_159 = V_70 ;
V_167 . V_165 = V_157 ? V_178 : V_166 ;
V_167 . V_167 . V_37 = V_43 ;
V_167 . V_167 . V_90 = V_172 ;
V_167 . V_167 . V_92 = V_173 ;
F_41 ( V_58 , V_157 , & V_167 ) ;
F_42 ( V_32 ) ;
return 0 ;
}
static int
F_46 ( struct V_51 * V_52 , unsigned long V_14 )
{
struct V_31 * V_32 = & V_52 -> V_53 ;
void * V_64 = V_32 -> V_64 ;
unsigned int V_189 ;
T_1 V_16 ;
if ( V_32 -> V_25 != V_26 )
return - V_30 ;
switch ( V_32 -> V_35 [ V_36 ] . V_37 ) {
case V_4 :
case V_6 :
case V_190 :
V_189 = V_32 -> V_35 [ V_36 ] . V_90 ;
break;
default:
V_189 = V_32 -> V_35 [ V_36 ] . V_90 << 1 ;
break;
}
V_189 += 31 ;
V_189 &= ~ 0x1f ;
V_16 = ( V_189 >> 5 ) & V_191 ;
F_4 ( V_16 , V_64 , V_192 ) ;
V_16 = ( V_14 >> V_193 ) & V_194 ;
F_4 ( V_16 , V_64 , V_195 ) ;
V_16 = ( V_14 >> V_196 ) & V_197 ;
F_4 ( V_16 , V_64 , V_198 ) ;
return 0 ;
}
static int
F_47 ( struct V_199 * V_200 , const struct V_201 * V_202 ,
const struct V_201 * V_203 , T_1 V_204 )
{
struct V_57 * V_58 = F_48 ( V_200 ) ;
struct V_31 * V_32 = F_19 ( V_58 ) ;
struct V_51 * V_205 = F_32 ( V_32 ) ;
switch ( V_202 -> V_160 | F_49 ( V_203 -> V_200 ) ) {
case V_36 | V_206 :
if ( ! ( V_204 & V_207 ) ) {
V_32 -> V_25 = V_183 ;
break;
}
V_32 -> V_25 = V_26 ;
break;
case V_36 | V_208 :
if ( ! ( V_204 & V_207 ) ) {
V_32 -> V_25 = V_183 ;
break;
}
if ( V_32 -> V_25 != V_183 )
return - V_209 ;
V_32 -> V_25 = V_28 ;
break;
case V_70 | V_208 :
if ( ! ( V_204 & V_207 ) ) {
V_32 -> V_184 = V_185 ;
break;
}
if ( V_203 -> V_200 == & V_205 -> V_210 . V_136 . V_200 )
V_32 -> V_184 = V_211 ;
else if ( V_203 -> V_200 == & V_205 -> V_212 .
V_213 . V_136 . V_200 )
V_32 -> V_184 = V_214 ;
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
F_52 ( & V_32 -> V_136 ) ;
F_53 ( & V_32 -> V_136 . V_200 ) ;
}
int
F_54 ( struct V_31 * V_32 ,
struct V_215 * V_216 )
{
struct V_51 * V_52 = F_32 ( V_32 ) ;
unsigned int V_204 ;
int V_142 ;
V_142 = F_55 ( V_216 , & V_32 -> V_136 ) ;
if ( V_142 < 0 )
return V_142 ;
V_142 = F_56 ( & V_32 -> V_47 , V_216 ) ;
if ( V_142 ) {
F_21 ( L_4 ) ;
goto V_217;
}
V_32 -> V_47 . V_52 = V_52 ;
V_204 = 0 ;
V_142 = F_57 ( & V_32 -> V_47 . V_218 . V_200 , 0 ,
& V_32 -> V_136 . V_200 , 0 , V_204 ) ;
if ( V_142 < 0 )
goto V_217;
return 0 ;
V_217:
F_52 ( & V_32 -> V_136 ) ;
return V_142 ;
}
int F_58 ( struct V_31 * V_32 ,
struct V_219 * V_220 )
{
struct V_57 * V_58 = & V_32 -> V_136 ;
struct V_201 * V_221 = & V_32 -> V_221 [ 0 ] ;
struct V_199 * V_222 = & V_58 -> V_200 ;
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
V_32 -> V_64 = F_62 ( V_225 -> V_228 , V_223 ) ;
if ( ! V_32 -> V_64 ) {
V_142 = - V_209 ;
goto V_217;
}
F_63 ( V_58 , & V_230 ) ;
V_58 -> V_231 = & V_232 ;
F_64 ( V_58 -> V_229 , L_5 , sizeof( V_58 -> V_229 ) ) ;
V_58 -> V_233 = 1 << 16 ;
F_65 ( V_58 , V_32 ) ;
V_58 -> V_204 |= V_234 | V_235 ;
V_221 [ V_36 ] . V_204 = V_236 ;
V_221 [ V_70 ] . V_204 = V_237 ;
V_32 -> V_25 = V_183 ;
V_32 -> V_184 = V_185 ;
V_222 -> V_238 = & V_239 ;
V_142 = F_66 ( V_222 , V_240 , V_221 , 0 ) ;
if ( V_142 )
goto V_217;
F_67 ( & V_32 -> V_149 , 2 ) ;
F_68 ( & V_32 -> V_149 , & V_241 ,
V_152 , 0 ,
V_242 , 1 , V_243 ) ;
F_69 ( & V_32 -> V_149 , & V_244 , NULL ) ;
F_70 ( & V_32 -> V_149 ) ;
V_58 -> V_245 = & V_32 -> V_149 ;
V_32 -> V_47 . V_238 = & V_246 ;
V_32 -> V_47 . type = V_247 ;
V_142 = F_71 ( & V_32 -> V_47 , L_6 ) ;
if ( V_142 ) {
F_21 ( L_7 ) ;
goto V_217;
}
F_42 ( V_32 ) ;
return 0 ;
V_217:
F_72 ( V_225 -> V_228 , V_223 ) ;
return V_142 ;
}
void
F_73 ( struct V_31 * V_32 ,
struct V_219 * V_220 )
{
struct V_224 * V_225 ;
F_74 ( & V_32 -> V_149 ) ;
F_75 ( V_32 -> V_64 ) ;
V_225 = F_59 ( V_220 , V_226 , 3 ) ;
if ( V_225 )
F_72 ( V_225 -> V_228 , F_60 ( V_225 ) ) ;
}
