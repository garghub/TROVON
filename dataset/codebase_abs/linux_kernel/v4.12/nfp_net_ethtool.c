static void F_1 ( struct V_1 * V_2 , char * V_3 )
{
struct V_4 * V_5 ;
if ( ! V_2 -> V_6 )
return;
V_5 = F_2 ( V_2 -> V_6 ) ;
if ( F_3 ( V_5 ) )
return;
snprintf ( V_3 , V_7 , L_1 ,
F_4 ( V_5 ) ,
F_5 ( V_5 ) ) ;
F_6 ( V_5 ) ;
}
static void F_7 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
char V_12 [ V_7 ] = {} ;
struct V_1 * V_2 = F_8 ( V_9 ) ;
F_9 ( V_11 -> V_13 , V_2 -> V_14 -> V_13 -> V_15 ,
sizeof( V_11 -> V_13 ) ) ;
F_9 ( V_11 -> V_3 , V_16 , sizeof( V_11 -> V_3 ) ) ;
F_1 ( V_2 , V_12 ) ;
snprintf ( V_11 -> V_17 , sizeof( V_11 -> V_17 ) ,
L_2 ,
V_2 -> V_18 . V_19 , V_2 -> V_18 . V_20 ,
V_2 -> V_18 . V_21 , V_2 -> V_18 . V_22 , V_12 ) ;
F_9 ( V_11 -> V_23 , F_10 ( V_2 -> V_14 ) ,
sizeof( V_11 -> V_23 ) ) ;
V_11 -> V_24 = V_25 ;
V_11 -> V_26 = V_27 ;
}
static int
F_11 ( struct V_8 * V_9 ,
struct V_28 * V_29 )
{
static const T_1 V_30 [] = {
[ V_31 ] = 0 ,
[ V_32 ] = V_33 ,
[ V_34 ] = V_35 ,
[ V_36 ] = V_37 ,
[ V_38 ] = V_39 ,
[ V_40 ] = V_41 ,
[ V_42 ] = V_43 ,
[ V_44 ] = V_45 ,
} ;
struct V_1 * V_2 = F_8 ( V_9 ) ;
T_1 V_46 , V_47 ;
F_12 ( V_29 , V_48 , V_49 ) ;
V_29 -> V_50 . V_51 = V_52 ;
V_29 -> V_50 . V_53 = V_33 ;
V_29 -> V_50 . V_54 = V_55 ;
if ( V_2 -> V_56 )
V_29 -> V_50 . V_57 = V_2 -> V_56 -> V_58 != V_59 ?
V_60 : V_61 ;
if ( ! F_13 ( V_9 ) )
return 0 ;
if ( V_2 -> V_56 ) {
int V_62 ;
if ( F_14 ( V_2 ) ) {
V_62 = F_15 ( V_2 ) ;
if ( V_62 )
return V_62 ;
}
V_29 -> V_50 . V_51 = V_2 -> V_56 -> V_63 ;
V_29 -> V_50 . V_53 = V_2 -> V_56 -> V_53 ;
V_29 -> V_50 . V_54 = V_64 ;
return 0 ;
}
V_46 = F_16 ( V_2 , V_65 ) ;
V_47 = F_17 ( V_66 , V_46 ) ;
if ( V_47 == V_31 )
return - V_67 ;
if ( V_47 == V_32 ||
V_47 >= F_18 ( V_30 ) )
return 0 ;
V_29 -> V_50 . V_53 = V_30 [ V_46 ] ;
V_29 -> V_50 . V_54 = V_64 ;
return 0 ;
}
static int
F_19 ( struct V_8 * V_9 ,
const struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
struct V_4 * V_5 ;
int V_62 ;
if ( ! V_2 -> V_56 )
return - V_67 ;
if ( F_20 ( V_9 ) ) {
F_21 ( V_2 , L_3 ) ;
return - V_68 ;
}
V_5 = F_22 ( V_2 -> V_6 , V_2 -> V_56 -> V_69 ) ;
if ( F_3 ( V_5 ) )
return F_23 ( V_5 ) ;
V_62 = F_24 ( V_5 , V_29 -> V_50 . V_57 == V_60 ?
V_70 : V_59 ) ;
if ( V_62 )
goto V_71;
if ( V_29 -> V_50 . V_53 != V_33 ) {
T_1 V_53 = V_29 -> V_50 . V_53 / V_2 -> V_56 -> V_72 ;
V_62 = F_25 ( V_5 , V_53 ) ;
if ( V_62 )
goto V_71;
}
V_62 = F_26 ( V_5 ) ;
if ( V_62 > 0 )
return 0 ;
F_27 ( V_2 ) ;
return V_62 ;
V_71:
F_28 ( V_5 ) ;
return V_62 ;
}
static void F_29 ( struct V_8 * V_9 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
V_74 -> V_75 = V_76 ;
V_74 -> V_77 = V_78 ;
V_74 -> V_79 = V_2 -> V_80 . V_81 ;
V_74 -> V_82 = V_2 -> V_80 . V_83 ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_81 , T_1 V_83 )
{
struct V_84 * V_80 ;
V_80 = F_31 ( V_2 ) ;
if ( ! V_80 )
return - V_85 ;
V_80 -> V_81 = V_81 ;
V_80 -> V_83 = V_83 ;
return F_32 ( V_2 , V_80 , NULL ) ;
}
static int F_33 ( struct V_8 * V_9 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
T_1 V_81 , V_83 ;
if ( V_74 -> V_86 || V_74 -> V_87 )
return - V_88 ;
V_81 = F_34 ( V_74 -> V_79 ) ;
V_83 = F_34 ( V_74 -> V_82 ) ;
if ( V_81 < V_89 || V_81 > V_76 ||
V_83 < V_90 || V_83 > V_78 )
return - V_88 ;
if ( V_2 -> V_80 . V_81 == V_81 && V_2 -> V_80 . V_83 == V_83 )
return 0 ;
F_35 ( V_2 , L_4 ,
V_2 -> V_80 . V_81 , V_81 , V_2 -> V_80 . V_83 , V_83 ) ;
return F_30 ( V_2 , V_81 , V_83 ) ;
}
static void F_36 ( struct V_8 * V_9 ,
T_1 V_91 , T_2 * V_92 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
T_2 * V_93 = V_92 ;
int V_94 ;
switch ( V_91 ) {
case V_95 :
for ( V_94 = 0 ; V_94 < V_96 ; V_94 ++ ) {
memcpy ( V_93 , V_97 [ V_94 ] . V_15 , V_98 ) ;
V_93 += V_98 ;
}
for ( V_94 = 0 ; V_94 < V_2 -> V_80 . V_99 ; V_94 ++ ) {
sprintf ( V_93 , L_5 , V_94 ) ;
V_93 += V_98 ;
sprintf ( V_93 , L_6 , V_94 ) ;
V_93 += V_98 ;
sprintf ( V_93 , L_7 , V_94 ) ;
V_93 += V_98 ;
}
strncpy ( V_93 , L_8 , V_98 ) ;
V_93 += V_98 ;
strncpy ( V_93 , L_9 , V_98 ) ;
V_93 += V_98 ;
strncpy ( V_93 , L_10 , V_98 ) ;
V_93 += V_98 ;
strncpy ( V_93 , L_11 , V_98 ) ;
V_93 += V_98 ;
strncpy ( V_93 , L_12 , V_98 ) ;
V_93 += V_98 ;
strncpy ( V_93 , L_13 , V_98 ) ;
V_93 += V_98 ;
strncpy ( V_93 , L_14 , V_98 ) ;
V_93 += V_98 ;
for ( V_94 = 0 ; V_94 < V_2 -> V_80 . V_100 ; V_94 ++ ) {
sprintf ( V_93 , L_15 , V_94 ) ;
V_93 += V_98 ;
sprintf ( V_93 , L_16 , V_94 ) ;
V_93 += V_98 ;
}
for ( V_94 = 0 ; V_94 < V_2 -> V_80 . V_101 ; V_94 ++ ) {
sprintf ( V_93 , L_17 , V_94 ) ;
V_93 += V_98 ;
sprintf ( V_93 , L_18 , V_94 ) ;
V_93 += V_98 ;
}
break;
}
}
static void F_37 ( struct V_8 * V_9 ,
struct V_102 * V_103 , T_3 * V_92 )
{
T_3 V_104 [ V_105 ] = {} ;
struct V_1 * V_2 = F_8 ( V_9 ) ;
struct V_106 * V_107 ;
struct V_106 V_108 = {} ;
T_3 V_109 [ V_105 ] ;
T_2 T_4 * V_110 ;
int V_94 , V_111 , V_112 ;
T_2 * V_93 ;
V_107 = F_38 ( V_9 , & V_108 ) ;
for ( V_94 = 0 ; V_94 < V_96 ; V_94 ++ ) {
switch ( V_97 [ V_94 ] . type ) {
case V_113 :
V_93 = ( char * ) V_107 + V_97 [ V_94 ] . V_114 ;
V_92 [ V_94 ] = V_97 [ V_94 ] . V_115 == sizeof( T_3 ) ?
* ( T_3 * ) V_93 : * ( T_1 * ) V_93 ;
break;
case V_116 :
V_110 = V_2 -> V_80 . V_117 + V_97 [ V_94 ] . V_114 ;
V_92 [ V_94 ] = F_39 ( V_110 ) ;
break;
}
}
for ( V_111 = 0 ; V_111 < V_2 -> V_80 . V_99 ; V_111 ++ ) {
unsigned int V_118 ;
do {
V_118 = F_40 ( & V_2 -> V_119 [ V_111 ] . V_120 ) ;
V_92 [ V_94 ++ ] = V_2 -> V_119 [ V_111 ] . V_121 ;
V_109 [ 0 ] = V_2 -> V_119 [ V_111 ] . V_122 ;
V_109 [ 1 ] = V_2 -> V_119 [ V_111 ] . V_123 ;
V_109 [ 2 ] = V_2 -> V_119 [ V_111 ] . V_124 ;
} while ( F_41 ( & V_2 -> V_119 [ V_111 ] . V_120 , V_118 ) );
do {
V_118 = F_40 ( & V_2 -> V_119 [ V_111 ] . V_125 ) ;
V_92 [ V_94 ++ ] = V_2 -> V_119 [ V_111 ] . V_126 ;
V_92 [ V_94 ++ ] = V_2 -> V_119 [ V_111 ] . V_127 ;
V_109 [ 3 ] = V_2 -> V_119 [ V_111 ] . V_128 ;
V_109 [ 4 ] = V_2 -> V_119 [ V_111 ] . V_129 ;
V_109 [ 5 ] = V_2 -> V_119 [ V_111 ] . V_130 ;
V_109 [ 6 ] = V_2 -> V_119 [ V_111 ] . V_131 ;
} while ( F_41 ( & V_2 -> V_119 [ V_111 ] . V_125 , V_118 ) );
for ( V_112 = 0 ; V_112 < V_105 ; V_112 ++ )
V_104 [ V_112 ] += V_109 [ V_112 ] ;
}
for ( V_111 = 0 ; V_111 < V_105 ; V_111 ++ )
V_92 [ V_94 ++ ] = V_104 [ V_111 ] ;
for ( V_111 = 0 ; V_111 < V_2 -> V_80 . V_100 ; V_111 ++ ) {
V_110 = V_2 -> V_80 . V_117 + F_42 ( V_111 ) ;
V_92 [ V_94 ++ ] = F_39 ( V_110 ) ;
V_110 = V_2 -> V_80 . V_117 + F_42 ( V_111 ) + 8 ;
V_92 [ V_94 ++ ] = F_39 ( V_110 ) ;
}
for ( V_111 = 0 ; V_111 < V_2 -> V_80 . V_101 ; V_111 ++ ) {
V_110 = V_2 -> V_80 . V_117 + F_43 ( V_111 ) ;
V_92 [ V_94 ++ ] = F_39 ( V_110 ) ;
V_110 = V_2 -> V_80 . V_117 + F_43 ( V_111 ) + 8 ;
V_92 [ V_94 ++ ] = F_39 ( V_110 ) ;
}
}
static int F_44 ( struct V_8 * V_9 , int V_132 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
switch ( V_132 ) {
case V_95 :
return V_25 ;
default:
return - V_67 ;
}
}
static T_1 F_45 ( T_1 V_133 )
{
static const T_1 V_134 [ V_135 + 1 ] = {
[ V_136 ] = V_137 ,
[ V_138 ] = V_139 ,
[ V_140 ] = V_141 ,
[ V_142 ] = V_143 ,
[ V_144 ] = V_145 ,
[ V_135 ] = V_146 ,
} ;
if ( V_133 >= F_18 ( V_134 ) )
return 0 ;
return V_134 [ V_133 ] ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_147 * V_29 )
{
T_1 V_148 ;
V_29 -> V_92 = 0 ;
if ( ! ( V_2 -> V_149 & V_150 ) )
return - V_67 ;
V_148 = F_45 ( V_29 -> V_133 ) ;
if ( ! V_148 )
return - V_88 ;
V_29 -> V_92 |= V_151 | V_152 ;
if ( V_2 -> V_153 & V_148 )
V_29 -> V_92 |= V_154 | V_155 ;
return 0 ;
}
static int F_47 ( struct V_8 * V_9 ,
struct V_147 * V_29 , T_1 * V_156 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
switch ( V_29 -> V_29 ) {
case V_157 :
V_29 -> V_92 = V_2 -> V_80 . V_101 ;
return 0 ;
case V_158 :
return F_46 ( V_2 , V_29 ) ;
default:
return - V_67 ;
}
}
static int F_48 ( struct V_1 * V_2 ,
struct V_147 * V_159 )
{
T_1 V_160 = V_2 -> V_153 ;
T_1 V_148 ;
int V_62 ;
if ( ! ( V_2 -> V_149 & V_150 ) )
return - V_67 ;
if ( V_159 -> V_92 & ~ ( V_151 | V_152 |
V_154 | V_155 ) )
return - V_88 ;
if ( ! ( V_159 -> V_92 & V_151 ) ||
! ( V_159 -> V_92 & V_152 ) )
return - V_88 ;
V_148 = F_45 ( V_159 -> V_133 ) ;
if ( ! V_148 )
return - V_88 ;
switch ( V_159 -> V_92 & ( V_154 | V_155 ) ) {
case 0 :
V_160 &= ~ V_148 ;
break;
case ( V_154 | V_155 ) :
V_160 |= V_148 ;
break;
default:
return - V_88 ;
}
V_160 |= F_49 ( V_161 , V_2 -> V_162 ) ;
V_160 |= V_163 ;
if ( V_160 == V_2 -> V_153 )
return 0 ;
F_50 ( V_160 , V_2 -> V_80 . V_117 + V_164 ) ;
V_62 = F_51 ( V_2 , V_165 ) ;
if ( V_62 )
return V_62 ;
V_2 -> V_153 = V_160 ;
F_35 ( V_2 , L_19 , V_2 -> V_153 ) ;
return 0 ;
}
static int F_52 ( struct V_8 * V_9 ,
struct V_147 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
switch ( V_29 -> V_29 ) {
case V_166 :
return F_48 ( V_2 , V_29 ) ;
default:
return - V_67 ;
}
}
static T_1 F_53 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
if ( ! ( V_2 -> V_149 & V_150 ) )
return 0 ;
return F_18 ( V_2 -> V_167 ) ;
}
static T_1 F_54 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
if ( ! ( V_2 -> V_149 & V_150 ) )
return - V_67 ;
return F_55 ( V_2 ) ;
}
static int F_56 ( struct V_8 * V_9 , T_1 * V_168 , T_2 * V_169 ,
T_2 * V_170 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
int V_94 ;
if ( ! ( V_2 -> V_149 & V_150 ) )
return - V_67 ;
if ( V_168 )
for ( V_94 = 0 ; V_94 < F_18 ( V_2 -> V_167 ) ; V_94 ++ )
V_168 [ V_94 ] = V_2 -> V_167 [ V_94 ] ;
if ( V_169 )
memcpy ( V_169 , V_2 -> V_171 , F_55 ( V_2 ) ) ;
if ( V_170 ) {
* V_170 = V_2 -> V_162 ;
if ( * V_170 >= 1 << V_172 )
* V_170 = V_173 ;
}
return 0 ;
}
static int F_57 ( struct V_8 * V_9 ,
const T_1 * V_168 , const T_2 * V_169 ,
const T_2 V_170 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
int V_94 ;
if ( ! ( V_2 -> V_149 & V_150 ) ||
! ( V_170 == V_174 || V_170 == V_2 -> V_162 ) )
return - V_67 ;
if ( ! V_169 && ! V_168 )
return 0 ;
if ( V_169 ) {
memcpy ( V_2 -> V_171 , V_169 , F_55 ( V_2 ) ) ;
F_58 ( V_2 ) ;
}
if ( V_168 ) {
for ( V_94 = 0 ; V_94 < F_18 ( V_2 -> V_167 ) ; V_94 ++ )
V_2 -> V_167 [ V_94 ] = V_168 [ V_94 ] ;
F_59 ( V_2 ) ;
}
return F_51 ( V_2 , V_165 ) ;
}
static int F_60 ( struct V_8 * V_9 )
{
return V_27 ;
}
static void F_61 ( struct V_8 * V_9 ,
struct V_175 * V_176 , void * V_93 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
T_1 * V_177 = V_93 ;
int V_94 ;
V_176 -> V_3 = F_16 ( V_2 , V_178 ) ;
for ( V_94 = 0 ; V_94 < V_27 / sizeof( T_1 ) ; V_94 ++ )
V_177 [ V_94 ] = F_62 ( V_2 -> V_80 . V_117 + ( V_94 * sizeof( T_1 ) ) ) ;
}
static int F_63 ( struct V_8 * V_9 ,
struct V_179 * V_180 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
if ( ! ( V_2 -> V_149 & V_181 ) )
return - V_88 ;
V_180 -> V_182 = V_2 -> V_182 ;
V_180 -> V_183 = V_2 -> V_184 ;
V_180 -> V_185 = V_2 -> V_185 ;
V_180 -> V_186 = V_2 -> V_187 ;
return 0 ;
}
static int
F_64 ( struct V_1 * V_2 , struct V_188 * V_189 , void * V_190 )
{
struct V_191 * V_192 ;
int V_193 ;
if ( ! V_2 -> V_6 )
return - V_67 ;
V_189 -> V_3 = 1 ;
V_189 -> V_194 = V_195 ;
V_192 = F_65 ( V_2 -> V_6 , V_196 ) ;
if ( F_3 ( V_192 ) )
return F_23 ( V_192 ) ;
if ( V_190 ) {
if ( V_189 -> V_197 != F_66 ( V_192 ) ) {
V_193 = - V_88 ;
goto V_198;
}
V_193 = F_67 ( V_2 -> V_6 , F_68 ( V_192 ) ,
F_69 ( V_192 ) ,
V_190 , V_189 -> V_197 ) ;
if ( V_193 != V_189 -> V_197 )
V_193 = V_193 < 0 ? V_193 : - V_199 ;
else
V_193 = 0 ;
} else {
V_189 -> V_197 = F_66 ( V_192 ) ;
V_193 = 0 ;
}
V_198:
F_70 ( V_192 ) ;
return V_193 ;
}
static int F_71 ( struct V_8 * V_9 , struct V_188 * V_200 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
if ( ! V_2 -> V_6 )
return - V_67 ;
if ( V_200 -> V_194 != V_195 )
return - V_88 ;
V_2 -> V_201 = V_200 -> V_194 ;
return 0 ;
}
static int
F_72 ( struct V_8 * V_9 , struct V_188 * V_189 )
{
return F_64 ( F_8 ( V_9 ) , V_189 , NULL ) ;
}
static int
F_73 ( struct V_8 * V_9 , struct V_188 * V_189 ,
void * V_190 )
{
return F_64 ( F_8 ( V_9 ) , V_189 , V_190 ) ;
}
static int F_74 ( struct V_8 * V_9 ,
struct V_179 * V_180 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
unsigned int V_202 ;
if ( V_180 -> V_203 ||
V_180 -> V_204 ||
V_180 -> V_205 ||
V_180 -> V_206 ||
V_180 -> V_207 ||
V_180 -> V_208 ||
V_180 -> V_209 ||
V_180 -> V_210 ||
V_180 -> V_211 ||
V_180 -> V_212 ||
V_180 -> V_213 ||
V_180 -> V_214 ||
V_180 -> V_215 ||
V_180 -> V_216 ||
V_180 -> V_217 ||
V_180 -> V_218 ||
V_180 -> V_219 ||
V_180 -> V_220 )
return - V_67 ;
V_202 = V_2 -> V_221 / 16 ;
if ( ! ( V_2 -> V_149 & V_181 ) )
return - V_88 ;
if ( ! V_180 -> V_182 && ! V_180 -> V_183 )
return - V_88 ;
if ( ! V_180 -> V_185 && ! V_180 -> V_186 )
return - V_88 ;
if ( V_180 -> V_182 * V_202 >= ( ( 1 << 16 ) - 1 ) )
return - V_88 ;
if ( V_180 -> V_185 * V_202 >= ( ( 1 << 16 ) - 1 ) )
return - V_88 ;
if ( V_180 -> V_183 >= ( ( 1 << 16 ) - 1 ) )
return - V_88 ;
if ( V_180 -> V_186 >= ( ( 1 << 16 ) - 1 ) )
return - V_88 ;
V_2 -> V_182 = V_180 -> V_182 ;
V_2 -> V_184 = V_180 -> V_183 ;
V_2 -> V_185 = V_180 -> V_185 ;
V_2 -> V_187 = V_180 -> V_186 ;
F_75 ( V_2 ) ;
return F_51 ( V_2 , V_222 ) ;
}
static void F_76 ( struct V_8 * V_9 ,
struct V_223 * V_224 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
unsigned int V_100 ;
V_100 = V_2 -> V_80 . V_100 ;
if ( V_2 -> V_80 . V_225 )
V_100 -= V_2 -> V_80 . V_101 ;
V_224 -> V_226 = F_77 ( V_2 -> V_227 , V_2 -> V_228 ) ;
V_224 -> V_229 = F_77 ( V_2 -> V_230 , V_2 -> V_228 ) ;
V_224 -> V_231 = F_77 ( V_224 -> V_226 , V_224 -> V_229 ) ;
V_224 -> V_232 = V_233 ;
V_224 -> V_234 = F_77 ( V_2 -> V_80 . V_101 , V_100 ) ;
V_224 -> V_235 = V_2 -> V_80 . V_101 - V_224 -> V_234 ;
V_224 -> V_236 = V_100 - V_224 -> V_234 ;
V_224 -> V_237 = V_233 ;
}
static int F_78 ( struct V_1 * V_2 , unsigned int V_238 ,
unsigned int V_239 )
{
struct V_84 * V_80 ;
V_80 = F_31 ( V_2 ) ;
if ( ! V_80 )
return - V_85 ;
V_80 -> V_101 = V_238 ;
V_80 -> V_100 = V_239 ;
if ( V_80 -> V_225 )
V_80 -> V_100 += V_238 ;
return F_32 ( V_2 , V_80 , NULL ) ;
}
static int F_79 ( struct V_8 * V_9 ,
struct V_223 * V_224 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
unsigned int V_238 , V_239 ;
if ( ! V_224 -> V_234 ||
V_224 -> V_237 != V_233 ||
( V_224 -> V_235 && V_224 -> V_236 ) )
return - V_88 ;
V_238 = V_224 -> V_234 + V_224 -> V_235 ;
V_239 = V_224 -> V_234 + V_224 -> V_236 ;
if ( V_238 > F_77 ( V_2 -> V_227 , V_2 -> V_228 ) ||
V_239 > F_77 ( V_2 -> V_230 , V_2 -> V_228 ) )
return - V_88 ;
return F_78 ( V_2 , V_238 , V_239 ) ;
}
void F_80 ( struct V_8 * V_9 )
{
V_9 -> V_240 = & V_241 ;
}
