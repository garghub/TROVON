static void F_1 ( struct V_1 * V_2 , char * V_3 )
{
struct V_4 * V_5 ;
if ( ! V_2 )
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
struct V_13 * V_14 = F_8 ( V_9 ) ;
F_9 ( V_11 -> V_15 , V_14 -> V_16 -> V_15 -> V_17 ,
sizeof( V_11 -> V_15 ) ) ;
F_9 ( V_11 -> V_3 , V_18 , sizeof( V_11 -> V_3 ) ) ;
F_1 ( V_14 -> V_2 , V_12 ) ;
snprintf ( V_11 -> V_19 , sizeof( V_11 -> V_19 ) ,
L_2 ,
V_14 -> V_20 . V_21 , V_14 -> V_20 . V_22 ,
V_14 -> V_20 . V_23 , V_14 -> V_20 . V_24 , V_12 ,
F_10 ( V_14 -> V_2 ) , F_11 ( V_14 -> V_2 ) ) ;
F_9 ( V_11 -> V_25 , F_12 ( V_14 -> V_16 ) ,
sizeof( V_11 -> V_25 ) ) ;
V_11 -> V_26 = V_27 ;
V_11 -> V_28 = V_29 ;
}
static int
F_13 ( struct V_8 * V_9 ,
struct V_30 * V_31 )
{
static const T_1 V_32 [] = {
[ V_33 ] = 0 ,
[ V_34 ] = V_35 ,
[ V_36 ] = V_37 ,
[ V_38 ] = V_39 ,
[ V_40 ] = V_41 ,
[ V_42 ] = V_43 ,
[ V_44 ] = V_45 ,
[ V_46 ] = V_47 ,
} ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
struct V_13 * V_14 ;
T_1 V_52 , V_53 ;
F_14 ( V_31 , V_54 , V_55 ) ;
V_31 -> V_56 . V_51 = V_57 ;
V_31 -> V_56 . V_58 = V_35 ;
V_31 -> V_56 . V_59 = V_60 ;
V_51 = F_15 ( V_9 ) ;
V_49 = F_16 ( V_51 ) ;
if ( V_49 )
V_31 -> V_56 . V_61 = V_49 -> V_62 != V_63 ?
V_64 : V_65 ;
if ( ! F_17 ( V_9 ) )
return 0 ;
if ( V_49 ) {
V_31 -> V_56 . V_51 = V_49 -> V_66 ;
V_31 -> V_56 . V_58 = V_49 -> V_58 ;
V_31 -> V_56 . V_59 = V_67 ;
return 0 ;
}
if ( ! F_18 ( V_9 ) )
return - V_68 ;
V_14 = F_8 ( V_9 ) ;
V_52 = F_19 ( V_14 , V_69 ) ;
V_53 = F_20 ( V_70 , V_52 ) ;
if ( V_53 == V_33 )
return - V_68 ;
if ( V_53 == V_34 ||
V_53 >= F_21 ( V_32 ) )
return 0 ;
V_31 -> V_56 . V_58 = V_32 [ V_52 ] ;
V_31 -> V_56 . V_59 = V_67 ;
return 0 ;
}
static int
F_22 ( struct V_8 * V_9 ,
const struct V_30 * V_31 )
{
struct V_48 * V_49 ;
struct V_50 * V_51 ;
struct V_4 * V_5 ;
int V_71 ;
V_51 = F_15 ( V_9 ) ;
V_49 = F_23 ( V_51 ) ;
if ( ! V_49 )
return - V_68 ;
if ( F_24 ( V_9 ) ) {
F_25 ( V_9 , L_3 ) ;
return - V_72 ;
}
V_5 = F_26 ( V_51 -> V_2 -> V_6 , V_49 -> V_73 ) ;
if ( F_3 ( V_5 ) )
return F_27 ( V_5 ) ;
V_71 = F_28 ( V_5 , V_31 -> V_56 . V_61 == V_64 ?
V_74 : V_63 ) ;
if ( V_71 )
goto V_75;
if ( V_31 -> V_56 . V_58 != V_35 ) {
T_1 V_58 = V_31 -> V_56 . V_58 / V_49 -> V_76 ;
V_71 = F_29 ( V_5 , V_58 ) ;
if ( V_71 )
goto V_75;
}
V_71 = F_30 ( V_5 ) ;
if ( V_71 > 0 )
return 0 ;
F_31 ( V_51 ) ;
return V_71 ;
V_75:
F_32 ( V_5 ) ;
return V_71 ;
}
static void F_33 ( struct V_8 * V_9 ,
struct V_77 * V_78 )
{
struct V_13 * V_14 = F_8 ( V_9 ) ;
V_78 -> V_79 = V_80 ;
V_78 -> V_81 = V_82 ;
V_78 -> V_83 = V_14 -> V_84 . V_85 ;
V_78 -> V_86 = V_14 -> V_84 . V_87 ;
}
static int F_34 ( struct V_13 * V_14 , T_1 V_85 , T_1 V_87 )
{
struct V_88 * V_84 ;
V_84 = F_35 ( V_14 ) ;
if ( ! V_84 )
return - V_89 ;
V_84 -> V_85 = V_85 ;
V_84 -> V_87 = V_87 ;
return F_36 ( V_14 , V_84 , NULL ) ;
}
static int F_37 ( struct V_8 * V_9 ,
struct V_77 * V_78 )
{
struct V_13 * V_14 = F_8 ( V_9 ) ;
T_1 V_85 , V_87 ;
if ( V_78 -> V_90 || V_78 -> V_91 )
return - V_92 ;
V_85 = F_38 ( V_78 -> V_83 ) ;
V_87 = F_38 ( V_78 -> V_86 ) ;
if ( V_85 < V_93 || V_85 > V_80 ||
V_87 < V_94 || V_87 > V_82 )
return - V_92 ;
if ( V_14 -> V_84 . V_85 == V_85 && V_14 -> V_84 . V_87 == V_87 )
return 0 ;
F_39 ( V_14 , L_4 ,
V_14 -> V_84 . V_85 , V_85 , V_14 -> V_84 . V_87 , V_87 ) ;
return F_34 ( V_14 , V_85 , V_87 ) ;
}
static void F_40 ( struct V_8 * V_9 ,
T_1 V_95 , T_2 * V_96 )
{
struct V_13 * V_14 = F_8 ( V_9 ) ;
T_2 * V_97 = V_96 ;
int V_98 ;
switch ( V_95 ) {
case V_99 :
for ( V_98 = 0 ; V_98 < V_100 ; V_98 ++ ) {
memcpy ( V_97 , V_101 [ V_98 ] . V_17 , V_102 ) ;
V_97 += V_102 ;
}
for ( V_98 = 0 ; V_98 < V_14 -> V_84 . V_103 ; V_98 ++ ) {
sprintf ( V_97 , L_5 , V_98 ) ;
V_97 += V_102 ;
sprintf ( V_97 , L_6 , V_98 ) ;
V_97 += V_102 ;
sprintf ( V_97 , L_7 , V_98 ) ;
V_97 += V_102 ;
}
strncpy ( V_97 , L_8 , V_102 ) ;
V_97 += V_102 ;
strncpy ( V_97 , L_9 , V_102 ) ;
V_97 += V_102 ;
strncpy ( V_97 , L_10 , V_102 ) ;
V_97 += V_102 ;
strncpy ( V_97 , L_11 , V_102 ) ;
V_97 += V_102 ;
strncpy ( V_97 , L_12 , V_102 ) ;
V_97 += V_102 ;
strncpy ( V_97 , L_13 , V_102 ) ;
V_97 += V_102 ;
strncpy ( V_97 , L_14 , V_102 ) ;
V_97 += V_102 ;
for ( V_98 = 0 ; V_98 < V_14 -> V_84 . V_104 ; V_98 ++ ) {
sprintf ( V_97 , L_15 , V_98 ) ;
V_97 += V_102 ;
sprintf ( V_97 , L_16 , V_98 ) ;
V_97 += V_102 ;
}
for ( V_98 = 0 ; V_98 < V_14 -> V_84 . V_105 ; V_98 ++ ) {
sprintf ( V_97 , L_17 , V_98 ) ;
V_97 += V_102 ;
sprintf ( V_97 , L_18 , V_98 ) ;
V_97 += V_102 ;
}
break;
}
}
static void F_41 ( struct V_8 * V_9 ,
struct V_106 * V_107 , T_3 * V_96 )
{
T_3 V_108 [ V_109 ] = {} ;
struct V_13 * V_14 = F_8 ( V_9 ) ;
struct V_110 * V_111 ;
struct V_110 V_112 = {} ;
T_3 V_113 [ V_109 ] ;
T_2 T_4 * V_114 ;
int V_98 , V_115 , V_116 ;
T_2 * V_97 ;
V_111 = F_42 ( V_9 , & V_112 ) ;
for ( V_98 = 0 ; V_98 < V_100 ; V_98 ++ ) {
switch ( V_101 [ V_98 ] . type ) {
case V_117 :
V_97 = ( char * ) V_111 + V_101 [ V_98 ] . V_118 ;
V_96 [ V_98 ] = V_101 [ V_98 ] . V_119 == sizeof( T_3 ) ?
* ( T_3 * ) V_97 : * ( T_1 * ) V_97 ;
break;
case V_120 :
V_114 = V_14 -> V_84 . V_121 + V_101 [ V_98 ] . V_118 ;
V_96 [ V_98 ] = F_43 ( V_114 ) ;
break;
}
}
for ( V_115 = 0 ; V_115 < V_14 -> V_84 . V_103 ; V_115 ++ ) {
unsigned int V_122 ;
do {
V_122 = F_44 ( & V_14 -> V_123 [ V_115 ] . V_124 ) ;
V_96 [ V_98 ++ ] = V_14 -> V_123 [ V_115 ] . V_125 ;
V_113 [ 0 ] = V_14 -> V_123 [ V_115 ] . V_126 ;
V_113 [ 1 ] = V_14 -> V_123 [ V_115 ] . V_127 ;
V_113 [ 2 ] = V_14 -> V_123 [ V_115 ] . V_128 ;
} while ( F_45 ( & V_14 -> V_123 [ V_115 ] . V_124 , V_122 ) );
do {
V_122 = F_44 ( & V_14 -> V_123 [ V_115 ] . V_129 ) ;
V_96 [ V_98 ++ ] = V_14 -> V_123 [ V_115 ] . V_130 ;
V_96 [ V_98 ++ ] = V_14 -> V_123 [ V_115 ] . V_131 ;
V_113 [ 3 ] = V_14 -> V_123 [ V_115 ] . V_132 ;
V_113 [ 4 ] = V_14 -> V_123 [ V_115 ] . V_133 ;
V_113 [ 5 ] = V_14 -> V_123 [ V_115 ] . V_134 ;
V_113 [ 6 ] = V_14 -> V_123 [ V_115 ] . V_135 ;
} while ( F_45 ( & V_14 -> V_123 [ V_115 ] . V_129 , V_122 ) );
for ( V_116 = 0 ; V_116 < V_109 ; V_116 ++ )
V_108 [ V_116 ] += V_113 [ V_116 ] ;
}
for ( V_115 = 0 ; V_115 < V_109 ; V_115 ++ )
V_96 [ V_98 ++ ] = V_108 [ V_115 ] ;
for ( V_115 = 0 ; V_115 < V_14 -> V_84 . V_104 ; V_115 ++ ) {
V_114 = V_14 -> V_84 . V_121 + F_46 ( V_115 ) ;
V_96 [ V_98 ++ ] = F_43 ( V_114 ) ;
V_114 = V_14 -> V_84 . V_121 + F_46 ( V_115 ) + 8 ;
V_96 [ V_98 ++ ] = F_43 ( V_114 ) ;
}
for ( V_115 = 0 ; V_115 < V_14 -> V_84 . V_105 ; V_115 ++ ) {
V_114 = V_14 -> V_84 . V_121 + F_47 ( V_115 ) ;
V_96 [ V_98 ++ ] = F_43 ( V_114 ) ;
V_114 = V_14 -> V_84 . V_121 + F_47 ( V_115 ) + 8 ;
V_96 [ V_98 ++ ] = F_43 ( V_114 ) ;
}
}
static int F_48 ( struct V_8 * V_9 , int V_136 )
{
struct V_13 * V_14 = F_8 ( V_9 ) ;
switch ( V_136 ) {
case V_99 :
return V_27 ;
default:
return - V_68 ;
}
}
static T_1 F_49 ( T_1 V_137 )
{
static const T_1 V_138 [ V_139 + 1 ] = {
[ V_140 ] = V_141 ,
[ V_142 ] = V_143 ,
[ V_144 ] = V_145 ,
[ V_146 ] = V_147 ,
[ V_148 ] = V_149 ,
[ V_139 ] = V_150 ,
} ;
if ( V_137 >= F_21 ( V_138 ) )
return 0 ;
return V_138 [ V_137 ] ;
}
static int F_50 ( struct V_13 * V_14 ,
struct V_151 * V_31 )
{
T_1 V_152 ;
V_31 -> V_96 = 0 ;
if ( ! ( V_14 -> V_153 & V_154 ) )
return - V_68 ;
V_152 = F_49 ( V_31 -> V_137 ) ;
if ( ! V_152 )
return - V_92 ;
V_31 -> V_96 |= V_155 | V_156 ;
if ( V_14 -> V_157 & V_152 )
V_31 -> V_96 |= V_158 | V_159 ;
return 0 ;
}
static int F_51 ( struct V_8 * V_9 ,
struct V_151 * V_31 , T_1 * V_160 )
{
struct V_13 * V_14 = F_8 ( V_9 ) ;
switch ( V_31 -> V_31 ) {
case V_161 :
V_31 -> V_96 = V_14 -> V_84 . V_105 ;
return 0 ;
case V_162 :
return F_50 ( V_14 , V_31 ) ;
default:
return - V_68 ;
}
}
static int F_52 ( struct V_13 * V_14 ,
struct V_151 * V_163 )
{
T_1 V_164 = V_14 -> V_157 ;
T_1 V_152 ;
int V_71 ;
if ( ! ( V_14 -> V_153 & V_154 ) )
return - V_68 ;
if ( V_163 -> V_96 & ~ ( V_155 | V_156 |
V_158 | V_159 ) )
return - V_92 ;
if ( ! ( V_163 -> V_96 & V_155 ) ||
! ( V_163 -> V_96 & V_156 ) )
return - V_92 ;
V_152 = F_49 ( V_163 -> V_137 ) ;
if ( ! V_152 )
return - V_92 ;
switch ( V_163 -> V_96 & ( V_158 | V_159 ) ) {
case 0 :
V_164 &= ~ V_152 ;
break;
case ( V_158 | V_159 ) :
V_164 |= V_152 ;
break;
default:
return - V_92 ;
}
V_164 |= F_53 ( V_165 , V_14 -> V_166 ) ;
V_164 |= V_167 ;
if ( V_164 == V_14 -> V_157 )
return 0 ;
F_54 ( V_164 , V_14 -> V_84 . V_121 + V_168 ) ;
V_71 = F_55 ( V_14 , V_169 ) ;
if ( V_71 )
return V_71 ;
V_14 -> V_157 = V_164 ;
F_39 ( V_14 , L_19 , V_14 -> V_157 ) ;
return 0 ;
}
static int F_56 ( struct V_8 * V_9 ,
struct V_151 * V_31 )
{
struct V_13 * V_14 = F_8 ( V_9 ) ;
switch ( V_31 -> V_31 ) {
case V_170 :
return F_52 ( V_14 , V_31 ) ;
default:
return - V_68 ;
}
}
static T_1 F_57 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = F_8 ( V_9 ) ;
if ( ! ( V_14 -> V_153 & V_154 ) )
return 0 ;
return F_21 ( V_14 -> V_171 ) ;
}
static T_1 F_58 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = F_8 ( V_9 ) ;
if ( ! ( V_14 -> V_153 & V_154 ) )
return - V_68 ;
return F_59 ( V_14 ) ;
}
static int F_60 ( struct V_8 * V_9 , T_1 * V_172 , T_2 * V_173 ,
T_2 * V_174 )
{
struct V_13 * V_14 = F_8 ( V_9 ) ;
int V_98 ;
if ( ! ( V_14 -> V_153 & V_154 ) )
return - V_68 ;
if ( V_172 )
for ( V_98 = 0 ; V_98 < F_21 ( V_14 -> V_171 ) ; V_98 ++ )
V_172 [ V_98 ] = V_14 -> V_171 [ V_98 ] ;
if ( V_173 )
memcpy ( V_173 , V_14 -> V_175 , F_59 ( V_14 ) ) ;
if ( V_174 ) {
* V_174 = V_14 -> V_166 ;
if ( * V_174 >= 1 << V_176 )
* V_174 = V_177 ;
}
return 0 ;
}
static int F_61 ( struct V_8 * V_9 ,
const T_1 * V_172 , const T_2 * V_173 ,
const T_2 V_174 )
{
struct V_13 * V_14 = F_8 ( V_9 ) ;
int V_98 ;
if ( ! ( V_14 -> V_153 & V_154 ) ||
! ( V_174 == V_178 || V_174 == V_14 -> V_166 ) )
return - V_68 ;
if ( ! V_173 && ! V_172 )
return 0 ;
if ( V_173 ) {
memcpy ( V_14 -> V_175 , V_173 , F_59 ( V_14 ) ) ;
F_62 ( V_14 ) ;
}
if ( V_172 ) {
for ( V_98 = 0 ; V_98 < F_21 ( V_14 -> V_171 ) ; V_98 ++ )
V_14 -> V_171 [ V_98 ] = V_172 [ V_98 ] ;
F_63 ( V_14 ) ;
}
return F_55 ( V_14 , V_169 ) ;
}
static int F_64 ( struct V_8 * V_9 )
{
return V_29 ;
}
static void F_65 ( struct V_8 * V_9 ,
struct V_179 * V_180 , void * V_97 )
{
struct V_13 * V_14 = F_8 ( V_9 ) ;
T_1 * V_181 = V_97 ;
int V_98 ;
V_180 -> V_3 = F_19 ( V_14 , V_182 ) ;
for ( V_98 = 0 ; V_98 < V_29 / sizeof( T_1 ) ; V_98 ++ )
V_181 [ V_98 ] = F_66 ( V_14 -> V_84 . V_121 + ( V_98 * sizeof( T_1 ) ) ) ;
}
static int F_67 ( struct V_8 * V_9 ,
struct V_183 * V_184 )
{
struct V_13 * V_14 = F_8 ( V_9 ) ;
if ( ! ( V_14 -> V_153 & V_185 ) )
return - V_92 ;
V_184 -> V_186 = V_14 -> V_186 ;
V_184 -> V_187 = V_14 -> V_188 ;
V_184 -> V_189 = V_14 -> V_189 ;
V_184 -> V_190 = V_14 -> V_191 ;
return 0 ;
}
static int
F_68 ( struct V_13 * V_14 , struct V_192 * V_193 , void * V_194 )
{
struct V_195 * V_196 ;
int V_197 ;
if ( ! V_14 -> V_2 )
return - V_68 ;
V_193 -> V_3 = 1 ;
V_193 -> V_198 = V_199 ;
V_196 = F_69 ( V_14 -> V_2 -> V_6 , V_200 ) ;
if ( F_3 ( V_196 ) )
return F_27 ( V_196 ) ;
if ( V_194 ) {
if ( V_193 -> V_201 != F_70 ( V_196 ) ) {
V_197 = - V_92 ;
goto V_202;
}
V_197 = F_71 ( V_14 -> V_2 -> V_6 , F_72 ( V_196 ) ,
F_73 ( V_196 ) ,
V_194 , V_193 -> V_201 ) ;
if ( V_197 != V_193 -> V_201 )
V_197 = V_197 < 0 ? V_197 : - V_203 ;
else
V_197 = 0 ;
} else {
V_193 -> V_201 = F_70 ( V_196 ) ;
V_197 = 0 ;
}
V_202:
F_74 ( V_196 ) ;
return V_197 ;
}
static int F_75 ( struct V_8 * V_9 , struct V_192 * V_204 )
{
struct V_13 * V_14 = F_8 ( V_9 ) ;
if ( ! V_14 -> V_2 )
return - V_68 ;
if ( V_204 -> V_198 != V_199 )
return - V_92 ;
V_14 -> V_205 = V_204 -> V_198 ;
return 0 ;
}
static int
F_76 ( struct V_8 * V_9 , struct V_192 * V_193 )
{
return F_68 ( F_8 ( V_9 ) , V_193 , NULL ) ;
}
static int
F_77 ( struct V_8 * V_9 , struct V_192 * V_193 ,
void * V_194 )
{
return F_68 ( F_8 ( V_9 ) , V_193 , V_194 ) ;
}
static int F_78 ( struct V_8 * V_9 ,
struct V_183 * V_184 )
{
struct V_13 * V_14 = F_8 ( V_9 ) ;
unsigned int V_206 ;
if ( V_184 -> V_207 ||
V_184 -> V_208 ||
V_184 -> V_209 ||
V_184 -> V_210 ||
V_184 -> V_211 ||
V_184 -> V_212 ||
V_184 -> V_213 ||
V_184 -> V_214 ||
V_184 -> V_215 ||
V_184 -> V_216 ||
V_184 -> V_217 ||
V_184 -> V_218 ||
V_184 -> V_219 ||
V_184 -> V_220 ||
V_184 -> V_221 ||
V_184 -> V_222 ||
V_184 -> V_223 ||
V_184 -> V_224 )
return - V_68 ;
V_206 = V_14 -> V_225 / 16 ;
if ( ! ( V_14 -> V_153 & V_185 ) )
return - V_92 ;
if ( ! V_184 -> V_186 && ! V_184 -> V_187 )
return - V_92 ;
if ( ! V_184 -> V_189 && ! V_184 -> V_190 )
return - V_92 ;
if ( V_184 -> V_186 * V_206 >= ( ( 1 << 16 ) - 1 ) )
return - V_92 ;
if ( V_184 -> V_189 * V_206 >= ( ( 1 << 16 ) - 1 ) )
return - V_92 ;
if ( V_184 -> V_187 >= ( ( 1 << 16 ) - 1 ) )
return - V_92 ;
if ( V_184 -> V_190 >= ( ( 1 << 16 ) - 1 ) )
return - V_92 ;
V_14 -> V_186 = V_184 -> V_186 ;
V_14 -> V_188 = V_184 -> V_187 ;
V_14 -> V_189 = V_184 -> V_189 ;
V_14 -> V_191 = V_184 -> V_190 ;
F_79 ( V_14 ) ;
return F_55 ( V_14 , V_226 ) ;
}
static void F_80 ( struct V_8 * V_9 ,
struct V_227 * V_228 )
{
struct V_13 * V_14 = F_8 ( V_9 ) ;
unsigned int V_104 ;
V_104 = V_14 -> V_84 . V_104 ;
if ( V_14 -> V_84 . V_229 )
V_104 -= V_14 -> V_84 . V_105 ;
V_228 -> V_230 = F_81 ( V_14 -> V_231 , V_14 -> V_232 ) ;
V_228 -> V_233 = F_81 ( V_14 -> V_234 , V_14 -> V_232 ) ;
V_228 -> V_235 = F_81 ( V_228 -> V_230 , V_228 -> V_233 ) ;
V_228 -> V_236 = V_237 ;
V_228 -> V_238 = F_81 ( V_14 -> V_84 . V_105 , V_104 ) ;
V_228 -> V_239 = V_14 -> V_84 . V_105 - V_228 -> V_238 ;
V_228 -> V_240 = V_104 - V_228 -> V_238 ;
V_228 -> V_241 = V_237 ;
}
static int F_82 ( struct V_13 * V_14 , unsigned int V_242 ,
unsigned int V_243 )
{
struct V_88 * V_84 ;
V_84 = F_35 ( V_14 ) ;
if ( ! V_84 )
return - V_89 ;
V_84 -> V_105 = V_242 ;
V_84 -> V_104 = V_243 ;
if ( V_84 -> V_229 )
V_84 -> V_104 += V_242 ;
return F_36 ( V_14 , V_84 , NULL ) ;
}
static int F_83 ( struct V_8 * V_9 ,
struct V_227 * V_228 )
{
struct V_13 * V_14 = F_8 ( V_9 ) ;
unsigned int V_242 , V_243 ;
if ( ! V_228 -> V_238 ||
V_228 -> V_241 != V_237 ||
( V_228 -> V_239 && V_228 -> V_240 ) )
return - V_92 ;
V_242 = V_228 -> V_238 + V_228 -> V_239 ;
V_243 = V_228 -> V_238 + V_228 -> V_240 ;
if ( V_242 > F_81 ( V_14 -> V_231 , V_14 -> V_232 ) ||
V_243 > F_81 ( V_14 -> V_234 , V_14 -> V_232 ) )
return - V_92 ;
return F_82 ( V_14 , V_242 , V_243 ) ;
}
void F_84 ( struct V_8 * V_9 )
{
V_9 -> V_244 = & V_245 ;
}
