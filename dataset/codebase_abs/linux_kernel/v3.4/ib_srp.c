static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 -> V_4 ;
}
static const char * F_2 ( struct V_2 * V_3 )
{
return F_1 ( V_3 ) -> V_5 ;
}
static int F_3 ( struct V_1 * V_6 )
{
static const T_1 V_7 [ 3 ] = { 0x00 , 0x05 , 0xad } ;
static const T_1 V_8 [ 3 ] = { 0x00 , 0x1b , 0x0d } ;
return V_9 &&
( ! memcmp ( & V_6 -> V_10 , V_7 , sizeof V_7 ) ||
! memcmp ( & V_6 -> V_10 , V_8 , sizeof V_8 ) ) ;
}
static struct V_11 * F_4 ( struct V_12 * V_3 , T_2 V_13 ,
T_3 V_14 ,
enum V_15 V_16 )
{
struct V_11 * V_17 ;
V_17 = F_5 ( sizeof *V_17 , V_14 ) ;
if ( ! V_17 )
goto V_18;
V_17 -> V_19 = F_6 ( V_13 , V_14 ) ;
if ( ! V_17 -> V_19 )
goto V_20;
V_17 -> V_21 = F_7 ( V_3 -> V_22 -> V_23 , V_17 -> V_19 , V_13 ,
V_16 ) ;
if ( F_8 ( V_3 -> V_22 -> V_23 , V_17 -> V_21 ) )
goto V_24;
V_17 -> V_13 = V_13 ;
V_17 -> V_16 = V_16 ;
return V_17 ;
V_24:
F_9 ( V_17 -> V_19 ) ;
V_20:
F_9 ( V_17 ) ;
V_18:
return NULL ;
}
static void F_10 ( struct V_12 * V_3 , struct V_11 * V_17 )
{
if ( ! V_17 )
return;
F_11 ( V_3 -> V_22 -> V_23 , V_17 -> V_21 , V_17 -> V_13 ,
V_17 -> V_16 ) ;
F_9 ( V_17 -> V_19 ) ;
F_9 ( V_17 ) ;
}
static void F_12 ( struct V_25 * V_26 , void * V_27 )
{
F_13 ( L_1 , V_26 -> V_26 ) ;
}
static int F_14 ( struct V_1 * V_6 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 ;
int V_32 ;
V_31 = F_5 ( sizeof *V_31 , V_33 ) ;
if ( ! V_31 )
return - V_34 ;
V_32 = F_15 ( V_6 -> V_12 -> V_22 -> V_23 ,
V_6 -> V_12 -> V_35 ,
F_16 ( V_6 -> V_36 . V_37 ) ,
& V_31 -> V_38 ) ;
if ( V_32 )
goto V_18;
V_31 -> V_39 = V_40 ;
V_31 -> V_41 = ( V_42 |
V_43 ) ;
V_31 -> V_44 = V_6 -> V_12 -> V_35 ;
V_32 = F_17 ( V_29 , V_31 ,
V_45 |
V_46 |
V_47 |
V_48 ) ;
V_18:
F_9 ( V_31 ) ;
return V_32 ;
}
static int F_18 ( struct V_1 * V_6 )
{
struct V_49 * V_50 ;
V_50 = F_19 ( V_6 -> V_12 -> V_22 -> V_23 ,
V_51 , V_6 ) ;
if ( F_20 ( V_50 ) )
return F_21 ( V_50 ) ;
if ( V_6 -> V_52 )
F_22 ( V_6 -> V_52 ) ;
V_6 -> V_52 = V_50 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_6 )
{
struct V_53 * V_54 ;
int V_32 ;
V_54 = F_6 ( sizeof *V_54 , V_33 ) ;
if ( ! V_54 )
return - V_34 ;
V_6 -> V_55 = F_24 ( V_6 -> V_12 -> V_22 -> V_23 ,
V_56 , NULL , V_6 , V_57 , 0 ) ;
if ( F_20 ( V_6 -> V_55 ) ) {
V_32 = F_21 ( V_6 -> V_55 ) ;
goto V_58;
}
V_6 -> V_59 = F_24 ( V_6 -> V_12 -> V_22 -> V_23 ,
V_60 , NULL , V_6 , V_61 , 0 ) ;
if ( F_20 ( V_6 -> V_59 ) ) {
V_32 = F_21 ( V_6 -> V_59 ) ;
goto V_62;
}
F_25 ( V_6 -> V_55 , V_63 ) ;
V_54 -> V_64 = F_12 ;
V_54 -> V_65 . V_66 = V_61 ;
V_54 -> V_65 . V_67 = V_57 ;
V_54 -> V_65 . V_68 = 1 ;
V_54 -> V_65 . V_69 = 1 ;
V_54 -> V_70 = V_71 ;
V_54 -> V_72 = V_73 ;
V_54 -> V_59 = V_6 -> V_59 ;
V_54 -> V_55 = V_6 -> V_55 ;
V_6 -> V_29 = F_26 ( V_6 -> V_12 -> V_22 -> V_74 , V_54 ) ;
if ( F_20 ( V_6 -> V_29 ) ) {
V_32 = F_21 ( V_6 -> V_29 ) ;
goto V_75;
}
V_32 = F_14 ( V_6 , V_6 -> V_29 ) ;
if ( V_32 )
goto V_76;
F_9 ( V_54 ) ;
return 0 ;
V_76:
F_27 ( V_6 -> V_29 ) ;
V_75:
F_28 ( V_6 -> V_59 ) ;
V_62:
F_28 ( V_6 -> V_55 ) ;
V_58:
F_9 ( V_54 ) ;
return V_32 ;
}
static void F_29 ( struct V_1 * V_6 )
{
int V_77 ;
F_27 ( V_6 -> V_29 ) ;
F_28 ( V_6 -> V_59 ) ;
F_28 ( V_6 -> V_55 ) ;
for ( V_77 = 0 ; V_77 < V_57 ; ++ V_77 )
F_10 ( V_6 -> V_12 , V_6 -> V_78 [ V_77 ] ) ;
for ( V_77 = 0 ; V_77 < V_61 ; ++ V_77 )
F_10 ( V_6 -> V_12 , V_6 -> V_79 [ V_77 ] ) ;
}
static void F_30 ( int V_80 ,
struct V_81 * V_82 ,
void * V_83 )
{
struct V_1 * V_6 = V_83 ;
V_6 -> V_80 = V_80 ;
if ( V_80 )
F_31 ( V_84 , V_6 -> V_85 ,
V_86 L_2 , V_80 ) ;
else
V_6 -> V_36 = * V_82 ;
F_32 ( & V_6 -> V_87 ) ;
}
static int F_33 ( struct V_1 * V_6 )
{
V_6 -> V_36 . V_88 = 1 ;
F_34 ( & V_6 -> V_87 ) ;
V_6 -> V_89 = F_35 ( & V_90 ,
V_6 -> V_12 -> V_22 -> V_23 ,
V_6 -> V_12 -> V_35 ,
& V_6 -> V_36 ,
V_91 |
V_92 |
V_93 |
V_94 |
V_95 ,
V_96 ,
V_33 ,
F_30 ,
V_6 , & V_6 -> V_97 ) ;
if ( V_6 -> V_89 < 0 )
return V_6 -> V_89 ;
F_36 ( & V_6 -> V_87 ) ;
if ( V_6 -> V_80 < 0 )
F_31 ( V_98 , V_6 -> V_85 ,
V_86 L_3 ) ;
return V_6 -> V_80 ;
}
static int F_37 ( struct V_1 * V_6 )
{
struct {
struct V_99 V_100 ;
struct V_101 V_102 ;
} * V_103 = NULL ;
int V_80 ;
V_103 = F_6 ( sizeof *V_103 , V_33 ) ;
if ( ! V_103 )
return - V_34 ;
V_103 -> V_100 . V_104 = & V_6 -> V_36 ;
V_103 -> V_100 . V_105 = NULL ;
V_103 -> V_100 . V_106 = V_6 -> V_106 ;
V_103 -> V_100 . V_107 = V_6 -> V_29 -> V_107 ;
V_103 -> V_100 . V_72 = V_6 -> V_29 -> V_72 ;
V_103 -> V_100 . V_108 = & V_103 -> V_102 ;
V_103 -> V_100 . V_109 = sizeof V_103 -> V_102 ;
V_103 -> V_100 . V_110 = 1 ;
F_38 ( & V_103 -> V_100 . V_111 , 4 ) ;
V_103 -> V_100 . V_111 &= 0xffffff ;
V_103 -> V_100 . V_112 = 4 ;
V_103 -> V_100 . V_113 = 20 ;
V_103 -> V_100 . V_114 = 20 ;
V_103 -> V_100 . V_115 = 7 ;
V_103 -> V_100 . V_116 = 7 ;
V_103 -> V_100 . V_117 = 15 ;
V_103 -> V_102 . V_118 = V_119 ;
V_103 -> V_102 . V_120 = 0 ;
V_103 -> V_102 . V_121 = F_39 ( V_6 -> V_122 ) ;
V_103 -> V_102 . V_123 = F_40 ( V_124 |
V_125 ) ;
if ( V_6 -> V_126 == V_127 ) {
memcpy ( V_103 -> V_102 . V_128 ,
& V_6 -> V_36 . V_129 . V_130 . V_131 , 8 ) ;
memcpy ( V_103 -> V_102 . V_128 + 8 ,
& V_6 -> V_132 , 8 ) ;
memcpy ( V_103 -> V_102 . V_133 , & V_6 -> V_10 , 8 ) ;
memcpy ( V_103 -> V_102 . V_133 + 8 , & V_6 -> V_134 , 8 ) ;
} else {
memcpy ( V_103 -> V_102 . V_128 ,
& V_6 -> V_132 , 8 ) ;
memcpy ( V_103 -> V_102 . V_128 + 8 ,
& V_6 -> V_36 . V_129 . V_130 . V_131 , 8 ) ;
memcpy ( V_103 -> V_102 . V_133 , & V_6 -> V_134 , 8 ) ;
memcpy ( V_103 -> V_102 . V_133 + 8 , & V_6 -> V_10 , 8 ) ;
}
if ( F_3 ( V_6 ) ) {
F_31 ( V_135 , V_6 -> V_85 ,
V_86 L_4
L_5 ,
( unsigned long long ) F_41 ( V_6 -> V_10 ) ) ;
memset ( V_103 -> V_102 . V_128 , 0 , 8 ) ;
memcpy ( V_103 -> V_102 . V_128 + 8 ,
& V_6 -> V_12 -> V_22 -> V_23 -> V_136 , 8 ) ;
}
V_80 = F_42 ( V_6 -> V_52 , & V_103 -> V_100 ) ;
F_9 ( V_103 ) ;
return V_80 ;
}
static void F_43 ( struct V_1 * V_6 )
{
F_34 ( & V_6 -> V_87 ) ;
if ( F_44 ( V_6 -> V_52 , NULL , 0 ) ) {
F_31 ( V_135 , V_6 -> V_85 ,
V_86 L_6 ) ;
return;
}
F_36 ( & V_6 -> V_87 ) ;
}
static bool F_45 ( struct V_1 * V_6 ,
enum V_137 V_138 ,
enum V_137 V_139 )
{
bool V_140 = false ;
F_46 ( & V_6 -> V_141 ) ;
if ( V_6 -> V_142 == V_138 ) {
V_6 -> V_142 = V_139 ;
V_140 = true ;
}
F_47 ( & V_6 -> V_141 ) ;
return V_140 ;
}
static void F_48 ( struct V_1 * V_6 )
{
struct V_143 * V_144 = V_6 -> V_12 -> V_22 -> V_23 ;
struct V_145 * V_103 ;
int V_77 ;
for ( V_77 = 0 , V_103 = V_6 -> V_146 ; V_77 < V_147 ; ++ V_77 , ++ V_103 ) {
F_9 ( V_103 -> V_148 ) ;
F_9 ( V_103 -> V_149 ) ;
if ( V_103 -> V_150 ) {
F_11 ( V_144 , V_103 -> V_150 ,
V_6 -> V_151 ,
V_152 ) ;
}
F_9 ( V_103 -> V_153 ) ;
}
}
static void F_49 ( struct V_2 * V_154 )
{
struct V_155 * * V_31 ;
for ( V_31 = V_154 -> V_156 -> V_157 ; V_31 && * V_31 ; ++ V_31 )
F_50 ( & V_154 -> V_158 , * V_31 ) ;
}
static void F_51 ( struct V_159 * V_160 )
{
struct V_1 * V_6 =
F_52 ( V_160 , struct V_1 , V_160 ) ;
if ( ! F_45 ( V_6 , V_161 , V_162 ) )
return;
F_53 ( & V_6 -> V_12 -> V_163 ) ;
F_54 ( & V_6 -> V_164 ) ;
F_55 ( & V_6 -> V_12 -> V_163 ) ;
F_49 ( V_6 -> V_85 ) ;
F_56 ( V_6 -> V_85 ) ;
F_57 ( V_6 -> V_85 ) ;
F_22 ( V_6 -> V_52 ) ;
F_29 ( V_6 ) ;
F_48 ( V_6 ) ;
F_58 ( V_6 -> V_85 ) ;
}
static int F_59 ( struct V_1 * V_6 )
{
int V_165 = 3 ;
int V_32 ;
V_32 = F_33 ( V_6 ) ;
if ( V_32 )
return V_32 ;
while ( 1 ) {
F_34 ( & V_6 -> V_87 ) ;
V_32 = F_37 ( V_6 ) ;
if ( V_32 )
return V_32 ;
F_36 ( & V_6 -> V_87 ) ;
switch ( V_6 -> V_80 ) {
case 0 :
return 0 ;
case V_166 :
V_32 = F_33 ( V_6 ) ;
if ( V_32 )
return V_32 ;
break;
case V_167 :
break;
case V_168 :
if ( ! V_165 -- || F_18 ( V_6 ) ) {
F_31 ( V_84 , V_6 -> V_85 , V_86
L_7 ) ;
V_6 -> V_80 = - V_169 ;
return V_6 -> V_80 ;
}
F_31 ( V_84 , V_6 -> V_85 , V_86
L_8 ) ;
break;
default:
return V_6 -> V_80 ;
}
}
}
static void F_60 ( struct V_170 * V_171 ,
struct V_1 * V_6 ,
struct V_145 * V_103 )
{
struct V_143 * V_144 = V_6 -> V_12 -> V_22 -> V_23 ;
struct V_172 * * V_173 ;
if ( ! F_61 ( V_171 ) ||
( V_171 -> V_174 != V_152 &&
V_171 -> V_174 != V_175 ) )
return;
V_173 = V_103 -> V_148 ;
while ( V_103 -> V_176 -- )
F_62 ( * V_173 ++ ) ;
F_63 ( V_144 , F_61 ( V_171 ) , F_64 ( V_171 ) ,
V_171 -> V_174 ) ;
}
static void F_65 ( struct V_1 * V_6 ,
struct V_145 * V_103 , T_4 V_177 )
{
unsigned long V_178 ;
F_60 ( V_103 -> V_171 , V_6 , V_103 ) ;
F_66 ( & V_6 -> V_141 , V_178 ) ;
V_6 -> V_179 += V_177 ;
V_103 -> V_171 = NULL ;
F_67 ( & V_103 -> V_164 , & V_6 -> V_180 ) ;
F_68 ( & V_6 -> V_141 , V_178 ) ;
}
static void F_69 ( struct V_1 * V_6 , struct V_145 * V_103 )
{
V_103 -> V_171 -> V_181 = V_182 << 16 ;
V_103 -> V_171 -> V_183 ( V_103 -> V_171 ) ;
F_65 ( V_6 , V_103 , 0 ) ;
}
static int F_70 ( struct V_1 * V_6 )
{
struct V_30 V_184 ;
struct V_185 V_186 ;
int V_77 , V_32 ;
if ( ! F_45 ( V_6 , V_187 , V_188 ) )
return - V_189 ;
F_43 ( V_6 ) ;
V_32 = F_18 ( V_6 ) ;
if ( V_32 )
goto V_58;
V_184 . V_39 = V_190 ;
V_32 = F_17 ( V_6 -> V_29 , & V_184 , V_45 ) ;
if ( V_32 )
goto V_58;
V_32 = F_14 ( V_6 , V_6 -> V_29 ) ;
if ( V_32 )
goto V_58;
while ( F_71 ( V_6 -> V_55 , 1 , & V_186 ) > 0 )
;
while ( F_71 ( V_6 -> V_59 , 1 , & V_186 ) > 0 )
;
for ( V_77 = 0 ; V_77 < V_147 ; ++ V_77 ) {
struct V_145 * V_103 = & V_6 -> V_146 [ V_77 ] ;
if ( V_103 -> V_171 )
F_69 ( V_6 , V_103 ) ;
}
F_72 ( & V_6 -> V_191 ) ;
for ( V_77 = 0 ; V_77 < V_61 ; ++ V_77 )
F_73 ( & V_6 -> V_79 [ V_77 ] -> V_164 , & V_6 -> V_191 ) ;
V_6 -> V_192 = 0 ;
V_32 = F_59 ( V_6 ) ;
if ( V_32 )
goto V_58;
if ( ! F_45 ( V_6 , V_188 , V_187 ) )
V_32 = - V_189 ;
return V_32 ;
V_58:
F_31 ( V_84 , V_6 -> V_85 ,
V_86 L_9 , V_32 ) ;
F_46 ( & V_6 -> V_141 ) ;
if ( V_6 -> V_142 == V_188 ) {
V_6 -> V_142 = V_161 ;
F_74 ( & V_6 -> V_160 , F_51 ) ;
F_75 ( V_193 , & V_6 -> V_160 ) ;
}
F_47 ( & V_6 -> V_141 ) ;
return V_32 ;
}
static void F_76 ( struct V_194 * V_142 , T_5 V_195 ,
unsigned int V_196 , T_6 V_197 )
{
struct V_198 * V_199 = V_142 -> V_199 ;
V_199 -> V_200 = F_77 ( V_195 ) ;
V_199 -> V_201 = F_39 ( V_197 ) ;
V_199 -> V_202 = F_39 ( V_196 ) ;
V_142 -> V_203 += V_196 ;
V_142 -> V_199 ++ ;
V_142 -> V_204 ++ ;
}
static int F_78 ( struct V_194 * V_142 ,
struct V_1 * V_6 )
{
struct V_205 * V_23 = V_6 -> V_12 -> V_22 ;
struct V_172 * V_206 ;
T_7 V_207 = 0 ;
if ( ! V_142 -> V_208 )
return 0 ;
if ( V_142 -> V_208 == 1 ) {
F_76 ( V_142 , V_142 -> V_209 , V_142 -> V_210 ,
V_6 -> V_197 ) ;
V_142 -> V_208 = V_142 -> V_210 = 0 ;
return 0 ;
}
V_206 = F_79 ( V_23 -> V_211 , V_142 -> V_212 ,
V_142 -> V_208 , V_207 ) ;
if ( F_20 ( V_206 ) )
return F_21 ( V_206 ) ;
* V_142 -> V_213 ++ = V_206 ;
V_142 -> V_176 ++ ;
F_76 ( V_142 , 0 , V_142 -> V_210 , V_206 -> V_206 -> V_197 ) ;
V_142 -> V_208 = V_142 -> V_210 = 0 ;
return 0 ;
}
static void F_80 ( struct V_194 * V_142 ,
struct V_214 * V_215 , int V_216 ,
T_5 V_195 )
{
V_142 -> V_217 = V_215 ;
V_142 -> V_218 = V_216 ;
V_142 -> V_219 = V_195 ;
}
static int F_81 ( struct V_194 * V_142 ,
struct V_1 * V_6 ,
struct V_214 * V_215 , int V_216 ,
int V_220 )
{
struct V_205 * V_23 = V_6 -> V_12 -> V_22 ;
struct V_143 * V_144 = V_23 -> V_23 ;
T_5 V_195 = F_82 ( V_144 , V_215 ) ;
unsigned int V_196 = F_83 ( V_144 , V_215 ) ;
unsigned int V_202 ;
int V_32 ;
if ( ! V_196 )
return 0 ;
if ( V_220 == V_221 ) {
F_76 ( V_142 , V_195 , V_196 , V_6 -> V_197 ) ;
return 0 ;
}
if ( V_195 & ~ V_23 -> V_222 || V_196 > V_23 -> V_223 ) {
V_32 = F_78 ( V_142 , V_6 ) ;
if ( V_32 )
return V_32 ;
F_76 ( V_142 , V_195 , V_196 , V_6 -> V_197 ) ;
F_80 ( V_142 , NULL , 0 , 0 ) ;
return 0 ;
}
if ( ! V_142 -> V_217 )
F_80 ( V_142 , V_215 , V_216 , V_195 ) ;
while ( V_196 ) {
if ( V_142 -> V_208 == V_224 ) {
V_32 = F_78 ( V_142 , V_6 ) ;
if ( V_32 )
return V_32 ;
F_80 ( V_142 , V_215 , V_216 , V_195 ) ;
}
V_202 = F_84 (unsigned int, dma_len, dev->fmr_page_size) ;
if ( ! V_142 -> V_208 )
V_142 -> V_209 = V_195 ;
V_142 -> V_212 [ V_142 -> V_208 ++ ] = V_195 ;
V_142 -> V_210 += V_202 ;
V_195 += V_202 ;
V_196 -= V_202 ;
}
V_32 = 0 ;
if ( V_202 != V_23 -> V_225 ) {
V_32 = F_78 ( V_142 , V_6 ) ;
if ( ! V_32 )
F_80 ( V_142 , NULL , 0 , 0 ) ;
}
return V_32 ;
}
static int F_85 ( struct V_170 * V_171 , struct V_1 * V_6 ,
struct V_145 * V_103 )
{
struct V_214 * V_226 , * V_215 ;
struct V_227 * V_228 = V_103 -> V_228 -> V_19 ;
int V_77 , V_202 , V_229 , V_230 , V_220 ;
struct V_205 * V_23 ;
struct V_143 * V_144 ;
struct V_194 V_142 ;
struct V_231 * V_232 ;
T_6 V_233 ;
T_1 V_234 ;
if ( ! F_61 ( V_171 ) || V_171 -> V_174 == V_235 )
return sizeof ( struct V_227 ) ;
if ( V_171 -> V_174 != V_175 &&
V_171 -> V_174 != V_152 ) {
F_31 ( V_98 , V_6 -> V_85 ,
V_86 L_10 ,
V_171 -> V_174 ) ;
return - V_236 ;
}
V_229 = F_64 ( V_171 ) ;
V_226 = F_61 ( V_171 ) ;
V_23 = V_6 -> V_12 -> V_22 ;
V_144 = V_23 -> V_23 ;
V_230 = F_86 ( V_144 , V_226 , V_229 , V_171 -> V_174 ) ;
if ( F_87 ( V_230 == 0 ) )
return - V_237 ;
V_234 = V_238 ;
V_202 = sizeof ( struct V_227 ) + sizeof ( struct V_198 ) ;
if ( V_230 == 1 ) {
struct V_198 * V_19 = ( void * ) V_228 -> V_239 ;
V_19 -> V_200 = F_77 ( F_82 ( V_144 , V_226 ) ) ;
V_19 -> V_201 = F_39 ( V_6 -> V_197 ) ;
V_19 -> V_202 = F_39 ( F_83 ( V_144 , V_226 ) ) ;
V_103 -> V_176 = 0 ;
goto V_240;
}
V_232 = ( void * ) V_228 -> V_239 ;
F_88 ( V_144 , V_103 -> V_150 ,
V_6 -> V_151 , V_152 ) ;
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_199 = V_103 -> V_153 ;
V_142 . V_212 = V_103 -> V_149 ;
V_142 . V_213 = V_103 -> V_148 ;
V_220 = V_23 -> V_211 ? V_241 : V_221 ;
F_89 (scat, sg, count, i) {
if ( F_81 ( & V_142 , V_6 , V_215 , V_77 , V_220 ) ) {
T_5 V_195 ;
unsigned int V_196 ;
V_242:
V_215 = V_142 . V_217 ;
V_77 = V_142 . V_218 ;
V_195 = F_82 ( V_144 , V_215 ) ;
V_196 = F_83 ( V_144 , V_215 ) ;
V_196 -= ( V_142 . V_219 - V_195 ) ;
V_195 = V_142 . V_219 ;
V_220 = V_221 ;
F_76 ( & V_142 , V_195 , V_196 , V_6 -> V_197 ) ;
}
}
if ( V_220 == V_241 && F_78 ( & V_142 , V_6 ) )
goto V_242;
V_103 -> V_176 = V_142 . V_176 ;
if ( V_142 . V_204 == 1 ) {
struct V_198 * V_19 = ( void * ) V_228 -> V_239 ;
* V_19 = V_103 -> V_153 [ 0 ] ;
goto V_240;
}
if ( F_87 ( V_6 -> V_243 < V_142 . V_204 &&
! V_6 -> V_244 ) ) {
F_31 ( V_84 , V_6 -> V_85 ,
L_11 ) ;
return - V_237 ;
}
V_230 = F_90 ( V_142 . V_204 , V_6 -> V_243 ) ;
V_233 = V_142 . V_204 * sizeof ( struct V_198 ) ;
V_234 = V_245 ;
V_202 = sizeof( struct V_227 ) + sizeof ( struct V_231 ) ;
V_202 += V_230 * sizeof ( struct V_198 ) ;
memcpy ( V_232 -> V_246 , V_103 -> V_153 ,
V_230 * sizeof ( struct V_198 ) ) ;
V_232 -> V_247 . V_200 = F_77 ( V_103 -> V_150 ) ;
V_232 -> V_247 . V_201 = F_39 ( V_6 -> V_197 ) ;
V_232 -> V_247 . V_202 = F_39 ( V_233 ) ;
V_232 -> V_202 = F_39 ( V_142 . V_203 ) ;
if ( V_171 -> V_174 == V_152 )
V_228 -> V_248 = V_230 ;
else
V_228 -> V_249 = V_230 ;
F_91 ( V_144 , V_103 -> V_150 , V_233 ,
V_152 ) ;
V_240:
if ( V_171 -> V_174 == V_152 )
V_228 -> V_250 = V_234 << 4 ;
else
V_228 -> V_250 = V_234 ;
return V_202 ;
}
static void F_92 ( struct V_1 * V_6 , struct V_11 * V_17 ,
enum V_251 V_252 )
{
unsigned long V_178 ;
F_66 ( & V_6 -> V_141 , V_178 ) ;
F_73 ( & V_17 -> V_164 , & V_6 -> V_191 ) ;
if ( V_252 != V_253 )
++ V_6 -> V_179 ;
F_68 ( & V_6 -> V_141 , V_178 ) ;
}
static struct V_11 * F_93 ( struct V_1 * V_6 ,
enum V_251 V_252 )
{
T_4 V_254 = ( V_252 == V_255 ) ? 0 : V_256 ;
struct V_11 * V_17 ;
V_60 ( V_6 -> V_59 , V_6 ) ;
if ( F_94 ( & V_6 -> V_191 ) )
return NULL ;
if ( V_252 != V_253 ) {
if ( V_6 -> V_179 <= V_254 ) {
++ V_6 -> V_257 ;
return NULL ;
}
-- V_6 -> V_179 ;
}
V_17 = F_95 ( & V_6 -> V_191 , struct V_11 , V_164 ) ;
F_54 ( & V_17 -> V_164 ) ;
return V_17 ;
}
static int F_96 ( struct V_1 * V_6 ,
struct V_11 * V_17 , int V_202 )
{
struct V_258 V_164 ;
struct V_259 V_260 , * V_261 ;
V_164 . V_262 = V_17 -> V_21 ;
V_164 . V_263 = V_202 ;
V_164 . V_264 = V_6 -> V_264 ;
V_260 . V_265 = NULL ;
V_260 . V_266 = ( V_267 ) V_17 ;
V_260 . V_268 = & V_164 ;
V_260 . V_269 = 1 ;
V_260 . V_118 = V_270 ;
V_260 . V_271 = V_272 ;
return F_97 ( V_6 -> V_29 , & V_260 , & V_261 ) ;
}
static int F_98 ( struct V_1 * V_6 , struct V_11 * V_17 )
{
struct V_273 V_260 , * V_261 ;
struct V_258 V_164 ;
V_164 . V_262 = V_17 -> V_21 ;
V_164 . V_263 = V_17 -> V_13 ;
V_164 . V_264 = V_6 -> V_264 ;
V_260 . V_265 = NULL ;
V_260 . V_266 = ( V_267 ) V_17 ;
V_260 . V_268 = & V_164 ;
V_260 . V_269 = 1 ;
return F_99 ( V_6 -> V_29 , & V_260 , & V_261 ) ;
}
static void F_100 ( struct V_1 * V_6 , struct V_274 * V_275 )
{
struct V_145 * V_103 ;
struct V_170 * V_171 ;
unsigned long V_178 ;
if ( F_87 ( V_275 -> V_120 & V_276 ) ) {
F_66 ( & V_6 -> V_141 , V_178 ) ;
V_6 -> V_179 += F_101 ( V_275 -> V_177 ) ;
F_68 ( & V_6 -> V_141 , V_178 ) ;
V_6 -> V_277 = - 1 ;
if ( F_101 ( V_275 -> V_278 ) >= 4 )
V_6 -> V_277 = V_275 -> V_279 [ 3 ] ;
F_32 ( & V_6 -> V_280 ) ;
} else {
V_103 = & V_6 -> V_146 [ V_275 -> V_120 ] ;
V_171 = V_103 -> V_171 ;
if ( ! V_171 )
F_31 ( V_84 , V_6 -> V_85 ,
L_12 ,
( unsigned long long ) V_275 -> V_120 ) ;
V_171 -> V_181 = V_275 -> V_80 ;
if ( V_275 -> V_178 & V_281 ) {
memcpy ( V_171 -> V_282 , V_275 -> V_279 +
F_101 ( V_275 -> V_278 ) ,
F_84 ( int , F_101 ( V_275 -> V_283 ) ,
V_284 ) ) ;
}
if ( V_275 -> V_178 & ( V_285 | V_286 ) )
F_102 ( V_171 , F_101 ( V_275 -> V_287 ) ) ;
else if ( V_275 -> V_178 & ( V_288 | V_289 ) )
F_102 ( V_171 , F_101 ( V_275 -> V_290 ) ) ;
F_65 ( V_6 , V_103 , F_101 ( V_275 -> V_177 ) ) ;
V_171 -> V_291 = NULL ;
V_171 -> V_183 ( V_171 ) ;
}
}
static int F_103 ( struct V_1 * V_6 , T_4 V_292 ,
void * V_275 , int V_202 )
{
struct V_143 * V_23 = V_6 -> V_12 -> V_22 -> V_23 ;
unsigned long V_178 ;
struct V_11 * V_17 ;
int V_58 ;
F_66 ( & V_6 -> V_141 , V_178 ) ;
V_6 -> V_179 += V_292 ;
V_17 = F_93 ( V_6 , V_253 ) ;
F_68 ( & V_6 -> V_141 , V_178 ) ;
if ( ! V_17 ) {
F_31 ( V_84 , V_6 -> V_85 , V_86
L_13 ) ;
return 1 ;
}
F_88 ( V_23 , V_17 -> V_21 , V_202 , V_152 ) ;
memcpy ( V_17 -> V_19 , V_275 , V_202 ) ;
F_91 ( V_23 , V_17 -> V_21 , V_202 , V_152 ) ;
V_58 = F_96 ( V_6 , V_17 , V_202 ) ;
if ( V_58 ) {
F_31 ( V_84 , V_6 -> V_85 , V_86
L_14 , V_58 ) ;
F_92 ( V_6 , V_17 , V_253 ) ;
}
return V_58 ;
}
static void F_104 ( struct V_1 * V_6 ,
struct V_293 * V_103 )
{
struct V_294 V_275 = {
. V_118 = V_295 ,
. V_120 = V_103 -> V_120 ,
} ;
T_4 V_296 = F_101 ( V_103 -> V_177 ) ;
if ( F_103 ( V_6 , V_296 , & V_275 , sizeof V_275 ) )
F_31 ( V_84 , V_6 -> V_85 , V_86
L_15 ) ;
}
static void F_105 ( struct V_1 * V_6 ,
struct V_297 * V_103 )
{
struct V_298 V_275 = {
. V_118 = V_299 ,
. V_120 = V_103 -> V_120 ,
} ;
T_4 V_296 = F_101 ( V_103 -> V_177 ) ;
F_31 ( V_84 , V_6 -> V_85 , V_86
L_16 , F_41 ( V_103 -> V_300 ) ) ;
if ( F_103 ( V_6 , V_296 , & V_275 , sizeof V_275 ) )
F_31 ( V_84 , V_6 -> V_85 , V_86
L_17 ) ;
}
static void F_106 ( struct V_1 * V_6 , struct V_185 * V_186 )
{
struct V_143 * V_23 = V_6 -> V_12 -> V_22 -> V_23 ;
struct V_11 * V_17 = (struct V_11 * ) ( V_267 ) V_186 -> V_266 ;
int V_301 ;
T_1 V_118 ;
F_88 ( V_23 , V_17 -> V_21 , V_6 -> V_302 ,
V_175 ) ;
V_118 = * ( T_1 * ) V_17 -> V_19 ;
if ( 0 ) {
F_31 ( V_84 , V_6 -> V_85 ,
V_86 L_18 , V_118 ) ;
F_107 ( V_84 , L_19 , V_303 , 8 , 1 ,
V_17 -> V_19 , V_186 -> V_304 , true ) ;
}
switch ( V_118 ) {
case V_305 :
F_100 ( V_6 , V_17 -> V_19 ) ;
break;
case V_306 :
F_104 ( V_6 , V_17 -> V_19 ) ;
break;
case V_307 :
F_105 ( V_6 , V_17 -> V_19 ) ;
break;
case V_308 :
F_31 ( V_98 , V_6 -> V_85 ,
V_86 L_20 ) ;
break;
default:
F_31 ( V_98 , V_6 -> V_85 ,
V_86 L_21 , V_118 ) ;
break;
}
F_91 ( V_23 , V_17 -> V_21 , V_6 -> V_302 ,
V_175 ) ;
V_301 = F_98 ( V_6 , V_17 ) ;
if ( V_301 != 0 )
F_31 ( V_84 , V_6 -> V_85 ,
V_86 L_22 , V_301 ) ;
}
static void V_56 ( struct V_309 * V_310 , void * V_83 )
{
struct V_1 * V_6 = V_83 ;
struct V_185 V_186 ;
F_25 ( V_310 , V_63 ) ;
while ( F_71 ( V_310 , 1 , & V_186 ) > 0 ) {
if ( V_186 . V_80 ) {
F_31 ( V_84 , V_6 -> V_85 ,
V_86 L_23 ,
V_186 . V_80 ) ;
V_6 -> V_192 = 1 ;
break;
}
F_106 ( V_6 , & V_186 ) ;
}
}
static void V_60 ( struct V_309 * V_310 , void * V_83 )
{
struct V_1 * V_6 = V_83 ;
struct V_185 V_186 ;
struct V_11 * V_17 ;
while ( F_71 ( V_310 , 1 , & V_186 ) > 0 ) {
if ( V_186 . V_80 ) {
F_31 ( V_84 , V_6 -> V_85 ,
V_86 L_24 ,
V_186 . V_80 ) ;
V_6 -> V_192 = 1 ;
break;
}
V_17 = (struct V_11 * ) ( V_267 ) V_186 . V_266 ;
F_73 ( & V_17 -> V_164 , & V_6 -> V_191 ) ;
}
}
static int F_108 ( struct V_2 * V_154 , struct V_170 * V_171 )
{
struct V_1 * V_6 = F_1 ( V_154 ) ;
struct V_145 * V_103 ;
struct V_11 * V_17 ;
struct V_227 * V_228 ;
struct V_143 * V_23 ;
unsigned long V_178 ;
int V_202 ;
if ( V_6 -> V_142 == V_188 )
goto V_58;
if ( V_6 -> V_142 == V_161 ||
V_6 -> V_142 == V_162 ) {
V_171 -> V_181 = V_311 << 16 ;
V_171 -> V_183 ( V_171 ) ;
return 0 ;
}
F_66 ( & V_6 -> V_141 , V_178 ) ;
V_17 = F_93 ( V_6 , V_312 ) ;
if ( ! V_17 )
goto V_313;
V_103 = F_95 ( & V_6 -> V_180 , struct V_145 , V_164 ) ;
F_54 ( & V_103 -> V_164 ) ;
F_68 ( & V_6 -> V_141 , V_178 ) ;
V_23 = V_6 -> V_12 -> V_22 -> V_23 ;
F_88 ( V_23 , V_17 -> V_21 , V_6 -> V_122 ,
V_152 ) ;
V_171 -> V_181 = 0 ;
V_171 -> V_291 = ( void * ) V_103 ;
V_228 = V_17 -> V_19 ;
memset ( V_228 , 0 , sizeof *V_228 ) ;
V_228 -> V_118 = V_314 ;
V_228 -> V_300 = F_77 ( ( T_7 ) V_171 -> V_315 -> V_300 << 48 ) ;
V_228 -> V_120 = V_103 -> V_316 ;
memcpy ( V_228 -> V_317 , V_171 -> V_318 , V_171 -> V_319 ) ;
V_103 -> V_171 = V_171 ;
V_103 -> V_228 = V_17 ;
V_202 = F_85 ( V_171 , V_6 , V_103 ) ;
if ( V_202 < 0 ) {
F_31 ( V_84 , V_6 -> V_85 ,
V_86 L_25 ) ;
goto V_320;
}
F_91 ( V_23 , V_17 -> V_21 , V_6 -> V_122 ,
V_152 ) ;
if ( F_96 ( V_6 , V_17 , V_202 ) ) {
F_31 ( V_84 , V_6 -> V_85 , V_86 L_26 ) ;
goto V_321;
}
return 0 ;
V_321:
F_60 ( V_171 , V_6 , V_103 ) ;
V_320:
F_92 ( V_6 , V_17 , V_312 ) ;
F_66 ( & V_6 -> V_141 , V_178 ) ;
F_73 ( & V_103 -> V_164 , & V_6 -> V_180 ) ;
V_313:
F_68 ( & V_6 -> V_141 , V_178 ) ;
V_58:
return V_322 ;
}
static int F_109 ( struct V_1 * V_6 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_57 ; ++ V_77 ) {
V_6 -> V_78 [ V_77 ] = F_4 ( V_6 -> V_12 ,
V_6 -> V_302 ,
V_33 , V_175 ) ;
if ( ! V_6 -> V_78 [ V_77 ] )
goto V_58;
}
for ( V_77 = 0 ; V_77 < V_61 ; ++ V_77 ) {
V_6 -> V_79 [ V_77 ] = F_4 ( V_6 -> V_12 ,
V_6 -> V_122 ,
V_33 , V_152 ) ;
if ( ! V_6 -> V_79 [ V_77 ] )
goto V_58;
F_73 ( & V_6 -> V_79 [ V_77 ] -> V_164 , & V_6 -> V_191 ) ;
}
return 0 ;
V_58:
for ( V_77 = 0 ; V_77 < V_57 ; ++ V_77 ) {
F_10 ( V_6 -> V_12 , V_6 -> V_78 [ V_77 ] ) ;
V_6 -> V_78 [ V_77 ] = NULL ;
}
for ( V_77 = 0 ; V_77 < V_61 ; ++ V_77 ) {
F_10 ( V_6 -> V_12 , V_6 -> V_79 [ V_77 ] ) ;
V_6 -> V_79 [ V_77 ] = NULL ;
}
return - V_34 ;
}
static void F_110 ( struct V_49 * V_52 ,
struct V_323 * V_324 ,
struct V_1 * V_6 )
{
struct V_30 * V_184 = NULL ;
int V_325 = 0 ;
int V_32 ;
int V_77 ;
if ( V_324 -> V_118 == V_326 ) {
V_6 -> V_302 = F_101 ( V_324 -> V_302 ) ;
V_6 -> V_179 = F_101 ( V_324 -> V_177 ) ;
V_6 -> V_85 -> V_327
= F_90 ( V_6 -> V_179 - V_256 ,
V_6 -> V_85 -> V_327 ) ;
} else {
F_31 ( V_98 , V_6 -> V_85 ,
V_86 L_27 , V_324 -> V_118 ) ;
V_32 = - V_169 ;
goto error;
}
if ( ! V_6 -> V_78 [ 0 ] ) {
V_32 = F_109 ( V_6 ) ;
if ( V_32 )
goto error;
}
V_32 = - V_34 ;
V_184 = F_5 ( sizeof *V_184 , V_33 ) ;
if ( ! V_184 )
goto error;
V_184 -> V_39 = V_328 ;
V_32 = F_111 ( V_52 , V_184 , & V_325 ) ;
if ( V_32 )
goto V_329;
V_32 = F_17 ( V_6 -> V_29 , V_184 , V_325 ) ;
if ( V_32 )
goto V_329;
for ( V_77 = 0 ; V_77 < V_57 ; V_77 ++ ) {
struct V_11 * V_17 = V_6 -> V_78 [ V_77 ] ;
V_32 = F_98 ( V_6 , V_17 ) ;
if ( V_32 )
goto V_329;
}
V_184 -> V_39 = V_330 ;
V_32 = F_111 ( V_52 , V_184 , & V_325 ) ;
if ( V_32 )
goto V_329;
V_32 = F_17 ( V_6 -> V_29 , V_184 , V_325 ) ;
if ( V_32 )
goto V_329;
V_32 = F_112 ( V_52 , NULL , 0 ) ;
V_329:
F_9 ( V_184 ) ;
error:
V_6 -> V_80 = V_32 ;
}
static void F_113 ( struct V_49 * V_52 ,
struct V_331 * V_26 ,
struct V_1 * V_6 )
{
struct V_2 * V_154 = V_6 -> V_85 ;
struct V_332 * V_333 ;
int V_118 ;
switch ( V_26 -> V_100 . V_334 . V_335 ) {
case V_336 :
V_333 = V_26 -> V_100 . V_334 . V_337 ;
V_6 -> V_36 . V_338 = V_333 -> V_339 ;
V_6 -> V_36 . V_37 = V_333 -> V_340 ;
V_52 -> V_341 = F_101 ( V_333 -> V_342 ) & 0x00ffffff ;
memcpy ( V_6 -> V_36 . V_343 . V_344 , V_333 -> V_345 , 16 ) ;
V_6 -> V_80 = V_6 -> V_36 . V_338 ?
V_167 : V_166 ;
break;
case V_346 :
if ( F_3 ( V_6 ) ) {
memcpy ( V_6 -> V_36 . V_343 . V_344 ,
V_26 -> V_100 . V_334 . V_337 , 16 ) ;
F_31 ( V_135 , V_154 ,
V_86 L_28 ,
( unsigned long long ) F_41 ( V_6 -> V_36 . V_343 . V_130 . V_347 ) ,
( unsigned long long ) F_41 ( V_6 -> V_36 . V_343 . V_130 . V_131 ) ) ;
V_6 -> V_80 = V_166 ;
} else {
F_31 ( V_98 , V_154 ,
L_29 ) ;
V_6 -> V_80 = - V_169 ;
}
break;
case V_348 :
F_31 ( V_98 , V_154 ,
L_30 ) ;
V_6 -> V_80 = - V_169 ;
break;
case V_349 :
V_118 = * ( T_1 * ) V_26 -> V_108 ;
if ( V_118 == V_350 ) {
struct V_351 * V_352 = V_26 -> V_108 ;
T_6 V_335 = F_101 ( V_352 -> V_335 ) ;
if ( V_335 == V_353 )
F_31 ( V_98 , V_154 ,
V_86 L_31 ) ;
else
F_31 ( V_98 , V_154 ,
V_86 L_32 , V_335 ) ;
} else
F_31 ( V_98 , V_154 ,
L_33
L_34 , V_118 ) ;
V_6 -> V_80 = - V_169 ;
break;
case V_354 :
F_31 ( V_98 , V_154 , L_35 ) ;
V_6 -> V_80 = V_168 ;
break;
default:
F_31 ( V_98 , V_154 , L_36 ,
V_26 -> V_100 . V_334 . V_335 ) ;
V_6 -> V_80 = - V_169 ;
}
}
static int V_51 ( struct V_49 * V_52 , struct V_331 * V_26 )
{
struct V_1 * V_6 = V_52 -> V_27 ;
int V_355 = 0 ;
switch ( V_26 -> V_26 ) {
case V_356 :
F_31 ( V_135 , V_6 -> V_85 ,
V_86 L_37 ) ;
V_355 = 1 ;
V_6 -> V_80 = - V_169 ;
break;
case V_357 :
V_355 = 1 ;
F_110 ( V_52 , V_26 -> V_108 , V_6 ) ;
break;
case V_358 :
F_31 ( V_135 , V_6 -> V_85 , V_86 L_38 ) ;
V_355 = 1 ;
F_113 ( V_52 , V_26 , V_6 ) ;
break;
case V_359 :
F_31 ( V_98 , V_6 -> V_85 ,
V_86 L_39 ) ;
if ( F_114 ( V_52 , NULL , 0 ) )
F_31 ( V_84 , V_6 -> V_85 ,
V_86 L_40 ) ;
break;
case V_360 :
F_31 ( V_84 , V_6 -> V_85 ,
V_86 L_41 ) ;
V_355 = 1 ;
V_6 -> V_80 = 0 ;
break;
case V_361 :
case V_362 :
case V_363 :
break;
default:
F_31 ( V_98 , V_6 -> V_85 ,
V_86 L_42 , V_26 -> V_26 ) ;
break;
}
if ( V_355 )
F_32 ( & V_6 -> V_87 ) ;
return 0 ;
}
static int F_115 ( struct V_1 * V_6 ,
T_7 V_364 , unsigned int V_300 , T_1 V_365 )
{
struct V_143 * V_23 = V_6 -> V_12 -> V_22 -> V_23 ;
struct V_11 * V_17 ;
struct V_366 * V_367 ;
if ( V_6 -> V_142 == V_161 ||
V_6 -> V_142 == V_162 )
return - 1 ;
F_34 ( & V_6 -> V_280 ) ;
F_46 ( & V_6 -> V_141 ) ;
V_17 = F_93 ( V_6 , V_255 ) ;
F_47 ( & V_6 -> V_141 ) ;
if ( ! V_17 )
return - 1 ;
F_88 ( V_23 , V_17 -> V_21 , sizeof *V_367 ,
V_152 ) ;
V_367 = V_17 -> V_19 ;
memset ( V_367 , 0 , sizeof *V_367 ) ;
V_367 -> V_118 = V_368 ;
V_367 -> V_300 = F_77 ( ( T_7 ) V_300 << 48 ) ;
V_367 -> V_120 = V_364 | V_276 ;
V_367 -> V_369 = V_365 ;
V_367 -> V_370 = V_364 ;
F_91 ( V_23 , V_17 -> V_21 , sizeof *V_367 ,
V_152 ) ;
if ( F_96 ( V_6 , V_17 , sizeof *V_367 ) ) {
F_92 ( V_6 , V_17 , V_255 ) ;
return - 1 ;
}
if ( ! F_116 ( & V_6 -> V_280 ,
F_117 ( V_371 ) ) )
return - 1 ;
return 0 ;
}
static int F_118 ( struct V_170 * V_171 )
{
struct V_1 * V_6 = F_1 ( V_171 -> V_315 -> V_3 ) ;
struct V_145 * V_103 = (struct V_145 * ) V_171 -> V_291 ;
int V_32 = V_372 ;
F_31 ( V_84 , V_6 -> V_85 , L_43 ) ;
if ( ! V_103 || V_6 -> V_192 )
return V_373 ;
if ( F_115 ( V_6 , V_103 -> V_316 , V_171 -> V_315 -> V_300 ,
V_374 ) )
return V_373 ;
if ( V_103 -> V_171 ) {
if ( ! V_6 -> V_277 ) {
F_65 ( V_6 , V_103 , 0 ) ;
V_171 -> V_181 = V_375 << 16 ;
} else
V_32 = V_373 ;
}
return V_32 ;
}
static int F_119 ( struct V_170 * V_171 )
{
struct V_1 * V_6 = F_1 ( V_171 -> V_315 -> V_3 ) ;
int V_77 ;
F_31 ( V_84 , V_6 -> V_85 , L_44 ) ;
if ( V_6 -> V_192 )
return V_373 ;
if ( F_115 ( V_6 , V_376 , V_171 -> V_315 -> V_300 ,
V_377 ) )
return V_373 ;
if ( V_6 -> V_277 )
return V_373 ;
for ( V_77 = 0 ; V_77 < V_147 ; ++ V_77 ) {
struct V_145 * V_103 = & V_6 -> V_146 [ V_77 ] ;
if ( V_103 -> V_171 && V_103 -> V_171 -> V_315 == V_171 -> V_315 )
F_69 ( V_6 , V_103 ) ;
}
return V_372 ;
}
static int F_120 ( struct V_170 * V_171 )
{
struct V_1 * V_6 = F_1 ( V_171 -> V_315 -> V_3 ) ;
int V_32 = V_373 ;
F_31 ( V_84 , V_6 -> V_85 , V_86 L_45 ) ;
if ( ! F_70 ( V_6 ) )
V_32 = V_372 ;
return V_32 ;
}
static T_8 F_121 ( struct V_315 * V_23 , struct V_155 * V_31 ,
char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_122 ( V_23 ) ) ;
return sprintf ( V_19 , L_46 ,
( unsigned long long ) F_41 ( V_6 -> V_134 ) ) ;
}
static T_8 F_123 ( struct V_315 * V_23 , struct V_155 * V_31 ,
char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_122 ( V_23 ) ) ;
return sprintf ( V_19 , L_46 ,
( unsigned long long ) F_41 ( V_6 -> V_10 ) ) ;
}
static T_8 F_124 ( struct V_315 * V_23 ,
struct V_155 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_122 ( V_23 ) ) ;
return sprintf ( V_19 , L_46 ,
( unsigned long long ) F_41 ( V_6 -> V_106 ) ) ;
}
static T_8 F_125 ( struct V_315 * V_23 , struct V_155 * V_31 ,
char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_122 ( V_23 ) ) ;
return sprintf ( V_19 , L_47 , F_16 ( V_6 -> V_36 . V_37 ) ) ;
}
static T_8 F_126 ( struct V_315 * V_23 , struct V_155 * V_31 ,
char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_122 ( V_23 ) ) ;
return sprintf ( V_19 , L_48 , V_6 -> V_36 . V_343 . V_344 ) ;
}
static T_8 F_127 ( struct V_315 * V_23 ,
struct V_155 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_122 ( V_23 ) ) ;
return sprintf ( V_19 , L_48 , V_6 -> V_378 ) ;
}
static T_8 F_128 ( struct V_315 * V_23 ,
struct V_155 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_122 ( V_23 ) ) ;
return sprintf ( V_19 , L_49 , V_6 -> V_179 ) ;
}
static T_8 F_129 ( struct V_315 * V_23 ,
struct V_155 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_122 ( V_23 ) ) ;
return sprintf ( V_19 , L_49 , V_6 -> V_257 ) ;
}
static T_8 F_130 ( struct V_315 * V_23 ,
struct V_155 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_122 ( V_23 ) ) ;
return sprintf ( V_19 , L_49 , V_6 -> V_12 -> V_35 ) ;
}
static T_8 F_131 ( struct V_315 * V_23 ,
struct V_155 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_122 ( V_23 ) ) ;
return sprintf ( V_19 , L_50 , V_6 -> V_12 -> V_22 -> V_23 -> V_379 ) ;
}
static T_8 F_132 ( struct V_315 * V_23 ,
struct V_155 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_122 ( V_23 ) ) ;
return sprintf ( V_19 , L_51 , V_6 -> V_243 ) ;
}
static T_8 F_133 ( struct V_315 * V_23 ,
struct V_155 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_122 ( V_23 ) ) ;
return sprintf ( V_19 , L_50 , V_6 -> V_244 ? L_52 : L_53 ) ;
}
static int F_134 ( struct V_12 * V_3 , struct V_1 * V_6 )
{
struct V_380 V_381 ;
struct V_382 * V_383 ;
sprintf ( V_6 -> V_5 , L_54 ,
( unsigned long long ) F_41 ( V_6 -> V_134 ) ) ;
if ( F_135 ( V_6 -> V_85 , V_3 -> V_22 -> V_23 -> V_384 ) )
return - V_385 ;
memcpy ( V_381 . V_386 , & V_6 -> V_134 , 8 ) ;
memcpy ( V_381 . V_386 + 8 , & V_6 -> V_10 , 8 ) ;
V_381 . V_387 = V_388 ;
V_383 = F_136 ( V_6 -> V_85 , & V_381 ) ;
if ( F_20 ( V_383 ) ) {
F_57 ( V_6 -> V_85 ) ;
return F_21 ( V_383 ) ;
}
F_53 ( & V_3 -> V_163 ) ;
F_67 ( & V_6 -> V_164 , & V_3 -> V_389 ) ;
F_55 ( & V_3 -> V_163 ) ;
V_6 -> V_142 = V_187 ;
F_137 ( & V_6 -> V_85 -> V_390 ,
0 , V_6 -> V_391 , V_392 , 0 ) ;
return 0 ;
}
static void F_138 ( struct V_315 * V_23 )
{
struct V_12 * V_3 =
F_52 ( V_23 , struct V_12 , V_23 ) ;
F_32 ( & V_3 -> V_393 ) ;
}
static int F_139 ( const char * V_19 , struct V_1 * V_6 )
{
char * V_394 , * V_395 ;
char * V_396 ;
char V_343 [ 3 ] ;
T_9 args [ V_397 ] ;
int V_398 = 0 ;
int V_399 ;
int V_32 = - V_236 ;
int V_77 ;
V_394 = F_140 ( V_19 , V_33 ) ;
if ( ! V_394 )
return - V_34 ;
V_395 = V_394 ;
while ( ( V_396 = F_141 ( & V_395 , L_55 ) ) != NULL ) {
if ( ! * V_396 )
continue;
V_399 = F_142 ( V_396 , V_400 , args ) ;
V_398 |= V_399 ;
switch ( V_399 ) {
case V_401 :
V_396 = F_143 ( args ) ;
if ( ! V_396 ) {
V_32 = - V_34 ;
goto V_18;
}
V_6 -> V_134 = F_77 ( F_144 ( V_396 , NULL , 16 ) ) ;
F_9 ( V_396 ) ;
break;
case V_402 :
V_396 = F_143 ( args ) ;
if ( ! V_396 ) {
V_32 = - V_34 ;
goto V_18;
}
V_6 -> V_10 = F_77 ( F_144 ( V_396 , NULL , 16 ) ) ;
F_9 ( V_396 ) ;
break;
case V_403 :
V_396 = F_143 ( args ) ;
if ( ! V_396 ) {
V_32 = - V_34 ;
goto V_18;
}
if ( strlen ( V_396 ) != 32 ) {
F_145 ( L_56 , V_396 ) ;
F_9 ( V_396 ) ;
goto V_18;
}
for ( V_77 = 0 ; V_77 < 16 ; ++ V_77 ) {
F_146 ( V_343 , V_396 + V_77 * 2 , 3 ) ;
V_6 -> V_36 . V_343 . V_344 [ V_77 ] = F_147 ( V_343 , NULL , 16 ) ;
}
F_9 ( V_396 ) ;
memcpy ( V_6 -> V_378 , V_6 -> V_36 . V_343 . V_344 , 16 ) ;
break;
case V_404 :
if ( F_148 ( args , & V_399 ) ) {
F_145 ( L_57 , V_396 ) ;
goto V_18;
}
V_6 -> V_36 . V_37 = F_40 ( V_399 ) ;
break;
case V_405 :
V_396 = F_143 ( args ) ;
if ( ! V_396 ) {
V_32 = - V_34 ;
goto V_18;
}
V_6 -> V_106 = F_77 ( F_144 ( V_396 , NULL , 16 ) ) ;
V_6 -> V_36 . V_106 = V_6 -> V_106 ;
F_9 ( V_396 ) ;
break;
case V_406 :
if ( F_149 ( args , & V_399 ) ) {
F_145 ( L_58 , V_396 ) ;
goto V_18;
}
V_6 -> V_85 -> V_407 = V_399 ;
break;
case V_408 :
if ( F_149 ( args , & V_399 ) ) {
F_145 ( L_59 ,
V_396 ) ;
goto V_18;
}
V_6 -> V_85 -> V_409 = F_90 ( V_399 , V_147 ) ;
break;
case V_410 :
if ( F_148 ( args , & V_399 ) ) {
F_145 ( L_60 , V_396 ) ;
goto V_18;
}
if ( V_399 != V_127 &&
V_399 != V_411 ) {
F_145 ( L_61 ,
V_399 , V_127 ,
V_411 ) ;
goto V_18;
}
V_6 -> V_126 = V_399 ;
break;
case V_412 :
V_396 = F_143 ( args ) ;
if ( ! V_396 ) {
V_32 = - V_34 ;
goto V_18;
}
V_6 -> V_132 = F_77 ( F_144 ( V_396 , NULL , 16 ) ) ;
F_9 ( V_396 ) ;
break;
case V_413 :
if ( F_149 ( args , & V_399 ) || V_399 < 1 || V_399 > 255 ) {
F_145 ( L_62 ,
V_396 ) ;
goto V_18;
}
V_6 -> V_243 = V_399 ;
break;
case V_414 :
if ( F_149 ( args , & V_399 ) ) {
F_145 ( L_63 , V_396 ) ;
goto V_18;
}
V_6 -> V_244 = ! ! V_399 ;
break;
case V_415 :
if ( F_149 ( args , & V_399 ) || V_399 < 1 ||
V_399 > V_416 ) {
F_145 ( L_64 ,
V_396 ) ;
goto V_18;
}
V_6 -> V_417 = V_399 ;
break;
default:
F_145 ( L_65 ,
V_396 ) ;
goto V_18;
}
}
if ( ( V_398 & V_418 ) == V_418 )
V_32 = 0 ;
else
for ( V_77 = 0 ; V_77 < F_150 ( V_400 ) ; ++ V_77 )
if ( ( V_400 [ V_77 ] . V_399 & V_418 ) &&
! ( V_400 [ V_77 ] . V_399 & V_398 ) )
F_145 ( L_66 ,
V_400 [ V_77 ] . V_419 ) ;
V_18:
F_9 ( V_394 ) ;
return V_32 ;
}
static T_8 F_151 ( struct V_315 * V_23 ,
struct V_155 * V_31 ,
const char * V_19 , T_2 V_230 )
{
struct V_12 * V_3 =
F_52 ( V_23 , struct V_12 , V_23 ) ;
struct V_2 * V_420 ;
struct V_1 * V_6 ;
struct V_143 * V_144 = V_3 -> V_22 -> V_23 ;
T_5 V_195 ;
int V_77 , V_32 ;
V_420 = F_152 ( & V_421 ,
sizeof ( struct V_1 ) ) ;
if ( ! V_420 )
return - V_34 ;
V_420 -> V_422 = V_423 ;
V_420 -> V_424 = 0 ;
V_420 -> V_425 = 1 ;
V_420 -> V_426 = V_427 ;
V_420 -> V_428 = sizeof ( (struct V_227 * ) ( void * ) 0L ) -> V_317 ;
V_6 = F_1 ( V_420 ) ;
V_6 -> V_126 = V_411 ;
V_6 -> V_85 = V_420 ;
V_6 -> V_12 = V_3 ;
V_6 -> V_264 = V_3 -> V_22 -> V_429 -> V_264 ;
V_6 -> V_197 = V_3 -> V_22 -> V_429 -> V_197 ;
V_6 -> V_243 = V_430 ;
V_6 -> V_417 = V_431 ? : V_430 ;
V_6 -> V_244 = V_244 ;
V_32 = F_139 ( V_19 , V_6 ) ;
if ( V_32 )
goto V_58;
if ( ! V_3 -> V_22 -> V_211 && ! V_6 -> V_244 &&
V_6 -> V_243 < V_6 -> V_417 ) {
F_145 ( L_67 ) ;
V_6 -> V_417 = V_6 -> V_243 ;
}
V_420 -> V_417 = V_6 -> V_417 ;
V_6 -> V_151 = V_6 -> V_417 *
sizeof ( struct V_198 ) ;
V_6 -> V_122 = sizeof ( struct V_227 ) +
sizeof ( struct V_231 ) +
V_6 -> V_243 * sizeof ( struct V_198 ) ;
F_153 ( & V_6 -> V_141 ) ;
F_72 ( & V_6 -> V_191 ) ;
F_72 ( & V_6 -> V_180 ) ;
for ( V_77 = 0 ; V_77 < V_147 ; ++ V_77 ) {
struct V_145 * V_103 = & V_6 -> V_146 [ V_77 ] ;
V_103 -> V_148 = F_5 ( V_6 -> V_243 * sizeof ( void * ) ,
V_33 ) ;
V_103 -> V_149 = F_5 ( V_224 * sizeof ( void * ) ,
V_33 ) ;
V_103 -> V_153 = F_5 ( V_6 -> V_151 , V_33 ) ;
if ( ! V_103 -> V_148 || ! V_103 -> V_149 || ! V_103 -> V_153 )
goto V_432;
V_195 = F_7 ( V_144 , V_103 -> V_153 ,
V_6 -> V_151 ,
V_152 ) ;
if ( F_8 ( V_144 , V_195 ) )
goto V_432;
V_103 -> V_150 = V_195 ;
V_103 -> V_316 = V_77 ;
F_67 ( & V_103 -> V_164 , & V_6 -> V_180 ) ;
}
F_154 ( V_144 , V_3 -> V_35 , 0 , & V_6 -> V_36 . V_129 ) ;
F_31 ( V_135 , V_6 -> V_85 , V_86
L_68
L_69 ,
( unsigned long long ) F_41 ( V_6 -> V_134 ) ,
( unsigned long long ) F_41 ( V_6 -> V_10 ) ,
F_16 ( V_6 -> V_36 . V_37 ) ,
( unsigned long long ) F_41 ( V_6 -> V_106 ) ,
V_6 -> V_36 . V_343 . V_344 ) ;
V_32 = F_23 ( V_6 ) ;
if ( V_32 )
goto V_432;
V_32 = F_18 ( V_6 ) ;
if ( V_32 )
goto V_433;
V_6 -> V_192 = 0 ;
V_32 = F_59 ( V_6 ) ;
if ( V_32 ) {
F_31 ( V_84 , V_6 -> V_85 ,
V_86 L_70 ) ;
goto V_434;
}
V_32 = F_134 ( V_3 , V_6 ) ;
if ( V_32 )
goto V_435;
return V_230 ;
V_435:
F_43 ( V_6 ) ;
V_434:
F_22 ( V_6 -> V_52 ) ;
V_433:
F_29 ( V_6 ) ;
V_432:
F_48 ( V_6 ) ;
V_58:
F_58 ( V_420 ) ;
return V_32 ;
}
static T_8 F_155 ( struct V_315 * V_23 , struct V_155 * V_31 ,
char * V_19 )
{
struct V_12 * V_3 = F_52 ( V_23 , struct V_12 , V_23 ) ;
return sprintf ( V_19 , L_50 , V_3 -> V_22 -> V_23 -> V_379 ) ;
}
static T_8 F_156 ( struct V_315 * V_23 , struct V_155 * V_31 ,
char * V_19 )
{
struct V_12 * V_3 = F_52 ( V_23 , struct V_12 , V_23 ) ;
return sprintf ( V_19 , L_49 , V_3 -> V_35 ) ;
}
static struct V_12 * F_157 ( struct V_205 * V_315 , T_1 V_35 )
{
struct V_12 * V_3 ;
V_3 = F_6 ( sizeof *V_3 , V_33 ) ;
if ( ! V_3 )
return NULL ;
F_72 ( & V_3 -> V_389 ) ;
F_153 ( & V_3 -> V_163 ) ;
F_34 ( & V_3 -> V_393 ) ;
V_3 -> V_22 = V_315 ;
V_3 -> V_35 = V_35 ;
V_3 -> V_23 . V_436 = & V_437 ;
V_3 -> V_23 . V_438 = V_315 -> V_23 -> V_384 ;
F_158 ( & V_3 -> V_23 , L_71 , V_315 -> V_23 -> V_379 , V_35 ) ;
if ( F_159 ( & V_3 -> V_23 ) )
goto V_439;
if ( F_160 ( & V_3 -> V_23 , & V_440 ) )
goto V_441;
if ( F_160 ( & V_3 -> V_23 , & V_442 ) )
goto V_441;
if ( F_160 ( & V_3 -> V_23 , & V_443 ) )
goto V_441;
return V_3 ;
V_441:
F_161 ( & V_3 -> V_23 ) ;
V_439:
F_9 ( V_3 ) ;
return NULL ;
}
static void F_162 ( struct V_143 * V_315 )
{
struct V_205 * V_22 ;
struct V_444 * V_445 ;
struct V_446 V_447 ;
struct V_12 * V_3 ;
int V_448 , V_449 , V_450 , V_451 , V_396 ;
V_445 = F_5 ( sizeof *V_445 , V_33 ) ;
if ( ! V_445 )
return;
if ( F_163 ( V_315 , V_445 ) ) {
F_145 ( L_72 , V_315 -> V_379 ) ;
goto V_452;
}
V_22 = F_5 ( sizeof *V_22 , V_33 ) ;
if ( ! V_22 )
goto V_452;
V_449 = F_164 ( 12 , F_165 ( V_445 -> V_453 ) - 1 ) ;
V_22 -> V_225 = 1 << V_449 ;
V_22 -> V_222 = ~ ( ( T_7 ) V_22 -> V_225 - 1 ) ;
V_22 -> V_223 = V_22 -> V_225 * V_224 ;
F_72 ( & V_22 -> V_454 ) ;
V_22 -> V_23 = V_315 ;
V_22 -> V_74 = F_166 ( V_315 ) ;
if ( F_20 ( V_22 -> V_74 ) )
goto V_455;
V_22 -> V_429 = F_167 ( V_22 -> V_74 ,
V_456 |
V_42 |
V_43 ) ;
if ( F_20 ( V_22 -> V_429 ) )
goto V_457;
for ( V_448 = V_224 ;
V_448 >= V_458 ;
V_448 /= 2 , V_22 -> V_223 /= 2 ) {
memset ( & V_447 , 0 , sizeof V_447 ) ;
V_447 . V_459 = V_460 ;
V_447 . V_461 = V_462 ;
V_447 . V_463 = 1 ;
V_447 . V_448 = V_448 ;
V_447 . V_464 = V_449 ;
V_447 . V_465 = ( V_456 |
V_43 |
V_42 ) ;
V_22 -> V_211 = F_168 ( V_22 -> V_74 , & V_447 ) ;
if ( ! F_20 ( V_22 -> V_211 ) )
break;
}
if ( F_20 ( V_22 -> V_211 ) )
V_22 -> V_211 = NULL ;
if ( V_315 -> V_466 == V_467 ) {
V_450 = 0 ;
V_451 = 0 ;
} else {
V_450 = 1 ;
V_451 = V_315 -> V_468 ;
}
for ( V_396 = V_450 ; V_396 <= V_451 ; ++ V_396 ) {
V_3 = F_157 ( V_22 , V_396 ) ;
if ( V_3 )
F_67 ( & V_3 -> V_164 , & V_22 -> V_454 ) ;
}
F_169 ( V_315 , & V_469 , V_22 ) ;
goto V_452;
V_457:
F_170 ( V_22 -> V_74 ) ;
V_455:
F_9 ( V_22 ) ;
V_452:
F_9 ( V_445 ) ;
}
static void F_171 ( struct V_143 * V_315 )
{
struct V_205 * V_22 ;
struct V_12 * V_3 , * V_470 ;
F_172 ( V_389 ) ;
struct V_1 * V_6 , * V_471 ;
V_22 = F_173 ( V_315 , & V_469 ) ;
F_174 (host, tmp_host, &srp_dev->dev_list, list) {
F_161 ( & V_3 -> V_23 ) ;
F_36 ( & V_3 -> V_393 ) ;
F_53 ( & V_3 -> V_163 ) ;
F_175 (target, &host->target_list, list) {
F_46 ( & V_6 -> V_141 ) ;
V_6 -> V_142 = V_162 ;
F_47 ( & V_6 -> V_141 ) ;
}
F_55 ( & V_3 -> V_163 ) ;
F_176 ( V_193 ) ;
F_174 (target, tmp_target,
&host->target_list, list) {
F_49 ( V_6 -> V_85 ) ;
F_56 ( V_6 -> V_85 ) ;
F_57 ( V_6 -> V_85 ) ;
F_43 ( V_6 ) ;
F_22 ( V_6 -> V_52 ) ;
F_29 ( V_6 ) ;
F_48 ( V_6 ) ;
F_58 ( V_6 -> V_85 ) ;
}
F_9 ( V_3 ) ;
}
if ( V_22 -> V_211 )
F_177 ( V_22 -> V_211 ) ;
F_178 ( V_22 -> V_429 ) ;
F_170 ( V_22 -> V_74 ) ;
F_9 ( V_22 ) ;
}
static int T_10 F_179 ( void )
{
int V_32 ;
F_180 ( F_181 ( struct V_185 , V_266 ) < sizeof( void * ) ) ;
if ( V_472 ) {
F_145 ( L_73 ) ;
if ( ! V_430 )
V_430 = V_472 ;
}
if ( ! V_430 )
V_430 = V_473 ;
if ( V_430 > 255 ) {
F_145 ( L_74 ) ;
V_430 = 255 ;
}
if ( ! V_431 )
V_431 = V_430 ;
else if ( V_431 < V_430 ) {
F_145 ( L_75 ,
V_430 ) ;
V_431 = V_430 ;
}
V_423 =
F_182 ( & V_474 ) ;
if ( ! V_423 )
return - V_34 ;
V_32 = F_183 ( & V_437 ) ;
if ( V_32 ) {
F_184 ( L_76 ) ;
F_185 ( V_423 ) ;
return V_32 ;
}
F_186 ( & V_90 ) ;
V_32 = F_187 ( & V_469 ) ;
if ( V_32 ) {
F_184 ( L_77 ) ;
F_185 ( V_423 ) ;
F_188 ( & V_90 ) ;
F_189 ( & V_437 ) ;
return V_32 ;
}
return 0 ;
}
static void T_11 F_190 ( void )
{
F_191 ( & V_469 ) ;
F_188 ( & V_90 ) ;
F_189 ( & V_437 ) ;
F_185 ( V_423 ) ;
}
