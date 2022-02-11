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
F_13 (KERN_ERR PFX L_1 , event->event) ;
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
static void F_49 ( struct V_154 * V_155 )
{
struct V_1 * V_6 =
F_50 ( V_155 , struct V_1 , V_155 ) ;
if ( ! F_45 ( V_6 , V_156 , V_157 ) )
return;
F_51 ( & V_6 -> V_12 -> V_158 ) ;
F_52 ( & V_6 -> V_159 ) ;
F_53 ( & V_6 -> V_12 -> V_158 ) ;
F_54 ( V_6 -> V_85 ) ;
F_55 ( V_6 -> V_85 ) ;
F_22 ( V_6 -> V_52 ) ;
F_29 ( V_6 ) ;
F_48 ( V_6 ) ;
F_56 ( V_6 -> V_85 ) ;
}
static int F_57 ( struct V_1 * V_6 )
{
int V_160 = 3 ;
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
case V_161 :
V_32 = F_33 ( V_6 ) ;
if ( V_32 )
return V_32 ;
break;
case V_162 :
break;
case V_163 :
if ( ! V_160 -- || F_18 ( V_6 ) ) {
F_31 ( V_84 , V_6 -> V_85 , V_86
L_7 ) ;
V_6 -> V_80 = - V_164 ;
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
static void F_58 ( struct V_165 * V_166 ,
struct V_1 * V_6 ,
struct V_145 * V_103 )
{
struct V_143 * V_144 = V_6 -> V_12 -> V_22 -> V_23 ;
struct V_167 * * V_168 ;
if ( ! F_59 ( V_166 ) ||
( V_166 -> V_169 != V_152 &&
V_166 -> V_169 != V_170 ) )
return;
V_168 = V_103 -> V_148 ;
while ( V_103 -> V_171 -- )
F_60 ( * V_168 ++ ) ;
F_61 ( V_144 , F_59 ( V_166 ) , F_62 ( V_166 ) ,
V_166 -> V_169 ) ;
}
static void F_63 ( struct V_1 * V_6 ,
struct V_145 * V_103 , T_4 V_172 )
{
unsigned long V_173 ;
F_58 ( V_103 -> V_166 , V_6 , V_103 ) ;
F_64 ( & V_6 -> V_141 , V_173 ) ;
V_6 -> V_174 += V_172 ;
V_103 -> V_166 = NULL ;
F_65 ( & V_103 -> V_159 , & V_6 -> V_175 ) ;
F_66 ( & V_6 -> V_141 , V_173 ) ;
}
static void F_67 ( struct V_1 * V_6 , struct V_145 * V_103 )
{
V_103 -> V_166 -> V_176 = V_177 << 16 ;
V_103 -> V_166 -> V_178 ( V_103 -> V_166 ) ;
F_63 ( V_6 , V_103 , 0 ) ;
}
static int F_68 ( struct V_1 * V_6 )
{
struct V_30 V_179 ;
struct V_180 V_181 ;
int V_77 , V_32 ;
if ( ! F_45 ( V_6 , V_182 , V_183 ) )
return - V_184 ;
F_43 ( V_6 ) ;
V_32 = F_18 ( V_6 ) ;
if ( V_32 )
goto V_58;
V_179 . V_39 = V_185 ;
V_32 = F_17 ( V_6 -> V_29 , & V_179 , V_45 ) ;
if ( V_32 )
goto V_58;
V_32 = F_14 ( V_6 , V_6 -> V_29 ) ;
if ( V_32 )
goto V_58;
while ( F_69 ( V_6 -> V_55 , 1 , & V_181 ) > 0 )
;
while ( F_69 ( V_6 -> V_59 , 1 , & V_181 ) > 0 )
;
for ( V_77 = 0 ; V_77 < V_147 ; ++ V_77 ) {
struct V_145 * V_103 = & V_6 -> V_146 [ V_77 ] ;
if ( V_103 -> V_166 )
F_67 ( V_6 , V_103 ) ;
}
F_70 ( & V_6 -> V_186 ) ;
for ( V_77 = 0 ; V_77 < V_61 ; ++ V_77 )
F_71 ( & V_6 -> V_79 [ V_77 ] -> V_159 , & V_6 -> V_186 ) ;
V_6 -> V_187 = 0 ;
V_32 = F_57 ( V_6 ) ;
if ( V_32 )
goto V_58;
if ( ! F_45 ( V_6 , V_183 , V_182 ) )
V_32 = - V_184 ;
return V_32 ;
V_58:
F_31 ( V_84 , V_6 -> V_85 ,
V_86 L_9 , V_32 ) ;
F_46 ( & V_6 -> V_141 ) ;
if ( V_6 -> V_142 == V_183 ) {
V_6 -> V_142 = V_156 ;
F_72 ( & V_6 -> V_155 , F_49 ) ;
F_73 ( V_188 , & V_6 -> V_155 ) ;
}
F_47 ( & V_6 -> V_141 ) ;
return V_32 ;
}
static void F_74 ( struct V_189 * V_142 , T_5 V_190 ,
unsigned int V_191 , T_6 V_192 )
{
struct V_193 * V_194 = V_142 -> V_194 ;
V_194 -> V_195 = F_75 ( V_190 ) ;
V_194 -> V_196 = F_39 ( V_192 ) ;
V_194 -> V_197 = F_39 ( V_191 ) ;
V_142 -> V_198 += V_191 ;
V_142 -> V_194 ++ ;
V_142 -> V_199 ++ ;
}
static int F_76 ( struct V_189 * V_142 ,
struct V_1 * V_6 )
{
struct V_200 * V_23 = V_6 -> V_12 -> V_22 ;
struct V_167 * V_201 ;
T_7 V_202 = 0 ;
if ( ! V_142 -> V_203 )
return 0 ;
if ( V_142 -> V_203 == 1 ) {
F_74 ( V_142 , V_142 -> V_204 , V_142 -> V_205 ,
V_6 -> V_192 ) ;
V_142 -> V_203 = V_142 -> V_205 = 0 ;
return 0 ;
}
V_201 = F_77 ( V_23 -> V_206 , V_142 -> V_207 ,
V_142 -> V_203 , V_202 ) ;
if ( F_20 ( V_201 ) )
return F_21 ( V_201 ) ;
* V_142 -> V_208 ++ = V_201 ;
V_142 -> V_171 ++ ;
F_74 ( V_142 , 0 , V_142 -> V_205 , V_201 -> V_201 -> V_192 ) ;
V_142 -> V_203 = V_142 -> V_205 = 0 ;
return 0 ;
}
static void F_78 ( struct V_189 * V_142 ,
struct V_209 * V_210 , int V_211 ,
T_5 V_190 )
{
V_142 -> V_212 = V_210 ;
V_142 -> V_213 = V_211 ;
V_142 -> V_214 = V_190 ;
}
static int F_79 ( struct V_189 * V_142 ,
struct V_1 * V_6 ,
struct V_209 * V_210 , int V_211 ,
int V_215 )
{
struct V_200 * V_23 = V_6 -> V_12 -> V_22 ;
struct V_143 * V_144 = V_23 -> V_23 ;
T_5 V_190 = F_80 ( V_144 , V_210 ) ;
unsigned int V_191 = F_81 ( V_144 , V_210 ) ;
unsigned int V_197 ;
int V_32 ;
if ( ! V_191 )
return 0 ;
if ( V_215 == V_216 ) {
F_74 ( V_142 , V_190 , V_191 , V_6 -> V_192 ) ;
return 0 ;
}
if ( V_190 & ~ V_23 -> V_217 || V_191 > V_23 -> V_218 ) {
V_32 = F_76 ( V_142 , V_6 ) ;
if ( V_32 )
return V_32 ;
F_74 ( V_142 , V_190 , V_191 , V_6 -> V_192 ) ;
F_78 ( V_142 , NULL , 0 , 0 ) ;
return 0 ;
}
if ( ! V_142 -> V_212 )
F_78 ( V_142 , V_210 , V_211 , V_190 ) ;
while ( V_191 ) {
if ( V_142 -> V_203 == V_219 ) {
V_32 = F_76 ( V_142 , V_6 ) ;
if ( V_32 )
return V_32 ;
F_78 ( V_142 , V_210 , V_211 , V_190 ) ;
}
V_197 = F_82 (unsigned int, dma_len, dev->fmr_page_size) ;
if ( ! V_142 -> V_203 )
V_142 -> V_204 = V_190 ;
V_142 -> V_207 [ V_142 -> V_203 ++ ] = V_190 ;
V_142 -> V_205 += V_197 ;
V_190 += V_197 ;
V_191 -= V_197 ;
}
V_32 = 0 ;
if ( V_197 != V_23 -> V_220 ) {
V_32 = F_76 ( V_142 , V_6 ) ;
if ( ! V_32 )
F_78 ( V_142 , NULL , 0 , 0 ) ;
}
return V_32 ;
}
static int F_83 ( struct V_165 * V_166 , struct V_1 * V_6 ,
struct V_145 * V_103 )
{
struct V_209 * V_221 , * V_210 ;
struct V_222 * V_223 = V_103 -> V_223 -> V_19 ;
int V_77 , V_197 , V_224 , V_225 , V_215 ;
struct V_200 * V_23 ;
struct V_143 * V_144 ;
struct V_189 V_142 ;
struct V_226 * V_227 ;
T_6 V_228 ;
T_1 V_229 ;
if ( ! F_59 ( V_166 ) || V_166 -> V_169 == V_230 )
return sizeof ( struct V_222 ) ;
if ( V_166 -> V_169 != V_170 &&
V_166 -> V_169 != V_152 ) {
F_31 ( V_98 , V_6 -> V_85 ,
V_86 L_10 ,
V_166 -> V_169 ) ;
return - V_231 ;
}
V_224 = F_62 ( V_166 ) ;
V_221 = F_59 ( V_166 ) ;
V_23 = V_6 -> V_12 -> V_22 ;
V_144 = V_23 -> V_23 ;
V_225 = F_84 ( V_144 , V_221 , V_224 , V_166 -> V_169 ) ;
if ( F_85 ( V_225 == 0 ) )
return - V_232 ;
V_229 = V_233 ;
V_197 = sizeof ( struct V_222 ) + sizeof ( struct V_193 ) ;
if ( V_225 == 1 ) {
struct V_193 * V_19 = ( void * ) V_223 -> V_234 ;
V_19 -> V_195 = F_75 ( F_80 ( V_144 , V_221 ) ) ;
V_19 -> V_196 = F_39 ( V_6 -> V_192 ) ;
V_19 -> V_197 = F_39 ( F_81 ( V_144 , V_221 ) ) ;
V_103 -> V_171 = 0 ;
goto V_235;
}
V_227 = ( void * ) V_223 -> V_234 ;
F_86 ( V_144 , V_103 -> V_150 ,
V_6 -> V_151 , V_152 ) ;
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_194 = V_103 -> V_153 ;
V_142 . V_207 = V_103 -> V_149 ;
V_142 . V_208 = V_103 -> V_148 ;
V_215 = V_23 -> V_206 ? V_236 : V_216 ;
F_87 (scat, sg, count, i) {
if ( F_79 ( & V_142 , V_6 , V_210 , V_77 , V_215 ) ) {
T_5 V_190 ;
unsigned int V_191 ;
V_237:
V_210 = V_142 . V_212 ;
V_77 = V_142 . V_213 ;
V_190 = F_80 ( V_144 , V_210 ) ;
V_191 = F_81 ( V_144 , V_210 ) ;
V_191 -= ( V_142 . V_214 - V_190 ) ;
V_190 = V_142 . V_214 ;
V_215 = V_216 ;
F_74 ( & V_142 , V_190 , V_191 , V_6 -> V_192 ) ;
}
}
if ( V_215 == V_236 && F_76 ( & V_142 , V_6 ) )
goto V_237;
V_103 -> V_171 = V_142 . V_171 ;
if ( V_142 . V_199 == 1 ) {
struct V_193 * V_19 = ( void * ) V_223 -> V_234 ;
* V_19 = V_103 -> V_153 [ 0 ] ;
goto V_235;
}
if ( F_85 ( V_6 -> V_238 < V_142 . V_199 &&
! V_6 -> V_239 ) ) {
F_31 ( V_84 , V_6 -> V_85 ,
L_11 ) ;
return - V_232 ;
}
V_225 = F_88 ( V_142 . V_199 , V_6 -> V_238 ) ;
V_228 = V_142 . V_199 * sizeof ( struct V_193 ) ;
V_229 = V_240 ;
V_197 = sizeof( struct V_222 ) + sizeof ( struct V_226 ) ;
V_197 += V_225 * sizeof ( struct V_193 ) ;
memcpy ( V_227 -> V_241 , V_103 -> V_153 ,
V_225 * sizeof ( struct V_193 ) ) ;
V_227 -> V_242 . V_195 = F_75 ( V_103 -> V_150 ) ;
V_227 -> V_242 . V_196 = F_39 ( V_6 -> V_192 ) ;
V_227 -> V_242 . V_197 = F_39 ( V_228 ) ;
V_227 -> V_197 = F_39 ( V_142 . V_198 ) ;
if ( V_166 -> V_169 == V_152 )
V_223 -> V_243 = V_225 ;
else
V_223 -> V_244 = V_225 ;
F_89 ( V_144 , V_103 -> V_150 , V_228 ,
V_152 ) ;
V_235:
if ( V_166 -> V_169 == V_152 )
V_223 -> V_245 = V_229 << 4 ;
else
V_223 -> V_245 = V_229 ;
return V_197 ;
}
static void F_90 ( struct V_1 * V_6 , struct V_11 * V_17 ,
enum V_246 V_247 )
{
unsigned long V_173 ;
F_64 ( & V_6 -> V_141 , V_173 ) ;
F_71 ( & V_17 -> V_159 , & V_6 -> V_186 ) ;
if ( V_247 != V_248 )
++ V_6 -> V_174 ;
F_66 ( & V_6 -> V_141 , V_173 ) ;
}
static struct V_11 * F_91 ( struct V_1 * V_6 ,
enum V_246 V_247 )
{
T_4 V_249 = ( V_247 == V_250 ) ? 0 : V_251 ;
struct V_11 * V_17 ;
V_60 ( V_6 -> V_59 , V_6 ) ;
if ( F_92 ( & V_6 -> V_186 ) )
return NULL ;
if ( V_247 != V_248 ) {
if ( V_6 -> V_174 <= V_249 ) {
++ V_6 -> V_252 ;
return NULL ;
}
-- V_6 -> V_174 ;
}
V_17 = F_93 ( & V_6 -> V_186 , struct V_11 , V_159 ) ;
F_52 ( & V_17 -> V_159 ) ;
return V_17 ;
}
static int F_94 ( struct V_1 * V_6 ,
struct V_11 * V_17 , int V_197 )
{
struct V_253 V_159 ;
struct V_254 V_255 , * V_256 ;
V_159 . V_257 = V_17 -> V_21 ;
V_159 . V_258 = V_197 ;
V_159 . V_259 = V_6 -> V_259 ;
V_255 . V_260 = NULL ;
V_255 . V_261 = ( V_262 ) V_17 ;
V_255 . V_263 = & V_159 ;
V_255 . V_264 = 1 ;
V_255 . V_118 = V_265 ;
V_255 . V_266 = V_267 ;
return F_95 ( V_6 -> V_29 , & V_255 , & V_256 ) ;
}
static int F_96 ( struct V_1 * V_6 , struct V_11 * V_17 )
{
struct V_268 V_255 , * V_256 ;
struct V_253 V_159 ;
V_159 . V_257 = V_17 -> V_21 ;
V_159 . V_258 = V_17 -> V_13 ;
V_159 . V_259 = V_6 -> V_259 ;
V_255 . V_260 = NULL ;
V_255 . V_261 = ( V_262 ) V_17 ;
V_255 . V_263 = & V_159 ;
V_255 . V_264 = 1 ;
return F_97 ( V_6 -> V_29 , & V_255 , & V_256 ) ;
}
static void F_98 ( struct V_1 * V_6 , struct V_269 * V_270 )
{
struct V_145 * V_103 ;
struct V_165 * V_166 ;
unsigned long V_173 ;
if ( F_85 ( V_270 -> V_120 & V_271 ) ) {
F_64 ( & V_6 -> V_141 , V_173 ) ;
V_6 -> V_174 += F_99 ( V_270 -> V_172 ) ;
F_66 ( & V_6 -> V_141 , V_173 ) ;
V_6 -> V_272 = - 1 ;
if ( F_99 ( V_270 -> V_273 ) >= 4 )
V_6 -> V_272 = V_270 -> V_274 [ 3 ] ;
F_32 ( & V_6 -> V_275 ) ;
} else {
V_103 = & V_6 -> V_146 [ V_270 -> V_120 ] ;
V_166 = V_103 -> V_166 ;
if ( ! V_166 )
F_31 ( V_84 , V_6 -> V_85 ,
L_12 ,
( unsigned long long ) V_270 -> V_120 ) ;
V_166 -> V_176 = V_270 -> V_80 ;
if ( V_270 -> V_173 & V_276 ) {
memcpy ( V_166 -> V_277 , V_270 -> V_274 +
F_99 ( V_270 -> V_273 ) ,
F_82 ( int , F_99 ( V_270 -> V_278 ) ,
V_279 ) ) ;
}
if ( V_270 -> V_173 & ( V_280 | V_281 ) )
F_100 ( V_166 , F_99 ( V_270 -> V_282 ) ) ;
else if ( V_270 -> V_173 & ( V_283 | V_284 ) )
F_100 ( V_166 , F_99 ( V_270 -> V_285 ) ) ;
F_63 ( V_6 , V_103 , F_99 ( V_270 -> V_172 ) ) ;
V_166 -> V_286 = NULL ;
V_166 -> V_178 ( V_166 ) ;
}
}
static int F_101 ( struct V_1 * V_6 , T_4 V_287 ,
void * V_270 , int V_197 )
{
struct V_143 * V_23 = V_6 -> V_12 -> V_22 -> V_23 ;
unsigned long V_173 ;
struct V_11 * V_17 ;
int V_58 ;
F_64 ( & V_6 -> V_141 , V_173 ) ;
V_6 -> V_174 += V_287 ;
V_17 = F_91 ( V_6 , V_248 ) ;
F_66 ( & V_6 -> V_141 , V_173 ) ;
if ( ! V_17 ) {
F_31 ( V_84 , V_6 -> V_85 , V_86
L_13 ) ;
return 1 ;
}
F_86 ( V_23 , V_17 -> V_21 , V_197 , V_152 ) ;
memcpy ( V_17 -> V_19 , V_270 , V_197 ) ;
F_89 ( V_23 , V_17 -> V_21 , V_197 , V_152 ) ;
V_58 = F_94 ( V_6 , V_17 , V_197 ) ;
if ( V_58 ) {
F_31 ( V_84 , V_6 -> V_85 , V_86
L_14 , V_58 ) ;
F_90 ( V_6 , V_17 , V_248 ) ;
}
return V_58 ;
}
static void F_102 ( struct V_1 * V_6 ,
struct V_288 * V_103 )
{
struct V_289 V_270 = {
. V_118 = V_290 ,
. V_120 = V_103 -> V_120 ,
} ;
T_4 V_291 = F_99 ( V_103 -> V_172 ) ;
if ( F_101 ( V_6 , V_291 , & V_270 , sizeof V_270 ) )
F_31 ( V_84 , V_6 -> V_85 , V_86
L_15 ) ;
}
static void F_103 ( struct V_1 * V_6 ,
struct V_292 * V_103 )
{
struct V_293 V_270 = {
. V_118 = V_294 ,
. V_120 = V_103 -> V_120 ,
} ;
T_4 V_291 = F_99 ( V_103 -> V_172 ) ;
F_31 ( V_84 , V_6 -> V_85 , V_86
L_16 , F_41 ( V_103 -> V_295 ) ) ;
if ( F_101 ( V_6 , V_291 , & V_270 , sizeof V_270 ) )
F_31 ( V_84 , V_6 -> V_85 , V_86
L_17 ) ;
}
static void F_104 ( struct V_1 * V_6 , struct V_180 * V_181 )
{
struct V_143 * V_23 = V_6 -> V_12 -> V_22 -> V_23 ;
struct V_11 * V_17 = (struct V_11 * ) ( V_262 ) V_181 -> V_261 ;
int V_296 ;
T_1 V_118 ;
F_86 ( V_23 , V_17 -> V_21 , V_6 -> V_297 ,
V_170 ) ;
V_118 = * ( T_1 * ) V_17 -> V_19 ;
if ( 0 ) {
F_31 ( V_84 , V_6 -> V_85 ,
V_86 L_18 , V_118 ) ;
F_105 ( V_84 , L_19 , V_298 , 8 , 1 ,
V_17 -> V_19 , V_181 -> V_299 , true ) ;
}
switch ( V_118 ) {
case V_300 :
F_98 ( V_6 , V_17 -> V_19 ) ;
break;
case V_301 :
F_102 ( V_6 , V_17 -> V_19 ) ;
break;
case V_302 :
F_103 ( V_6 , V_17 -> V_19 ) ;
break;
case V_303 :
F_31 ( V_98 , V_6 -> V_85 ,
V_86 L_20 ) ;
break;
default:
F_31 ( V_98 , V_6 -> V_85 ,
V_86 L_21 , V_118 ) ;
break;
}
F_89 ( V_23 , V_17 -> V_21 , V_6 -> V_297 ,
V_170 ) ;
V_296 = F_96 ( V_6 , V_17 ) ;
if ( V_296 != 0 )
F_31 ( V_84 , V_6 -> V_85 ,
V_86 L_22 , V_296 ) ;
}
static void V_56 ( struct V_304 * V_305 , void * V_83 )
{
struct V_1 * V_6 = V_83 ;
struct V_180 V_181 ;
F_25 ( V_305 , V_63 ) ;
while ( F_69 ( V_305 , 1 , & V_181 ) > 0 ) {
if ( V_181 . V_80 ) {
F_31 ( V_84 , V_6 -> V_85 ,
V_86 L_23 ,
V_181 . V_80 ) ;
V_6 -> V_187 = 1 ;
break;
}
F_104 ( V_6 , & V_181 ) ;
}
}
static void V_60 ( struct V_304 * V_305 , void * V_83 )
{
struct V_1 * V_6 = V_83 ;
struct V_180 V_181 ;
struct V_11 * V_17 ;
while ( F_69 ( V_305 , 1 , & V_181 ) > 0 ) {
if ( V_181 . V_80 ) {
F_31 ( V_84 , V_6 -> V_85 ,
V_86 L_24 ,
V_181 . V_80 ) ;
V_6 -> V_187 = 1 ;
break;
}
V_17 = (struct V_11 * ) ( V_262 ) V_181 . V_261 ;
F_71 ( & V_17 -> V_159 , & V_6 -> V_186 ) ;
}
}
static int F_106 ( struct V_2 * V_306 , struct V_165 * V_166 )
{
struct V_1 * V_6 = F_1 ( V_306 ) ;
struct V_145 * V_103 ;
struct V_11 * V_17 ;
struct V_222 * V_223 ;
struct V_143 * V_23 ;
unsigned long V_173 ;
int V_197 ;
if ( V_6 -> V_142 == V_183 )
goto V_58;
if ( V_6 -> V_142 == V_156 ||
V_6 -> V_142 == V_157 ) {
V_166 -> V_176 = V_307 << 16 ;
V_166 -> V_178 ( V_166 ) ;
return 0 ;
}
F_64 ( & V_6 -> V_141 , V_173 ) ;
V_17 = F_91 ( V_6 , V_308 ) ;
if ( ! V_17 )
goto V_309;
V_103 = F_93 ( & V_6 -> V_175 , struct V_145 , V_159 ) ;
F_52 ( & V_103 -> V_159 ) ;
F_66 ( & V_6 -> V_141 , V_173 ) ;
V_23 = V_6 -> V_12 -> V_22 -> V_23 ;
F_86 ( V_23 , V_17 -> V_21 , V_6 -> V_122 ,
V_152 ) ;
V_166 -> V_176 = 0 ;
V_166 -> V_286 = ( void * ) V_103 ;
V_223 = V_17 -> V_19 ;
memset ( V_223 , 0 , sizeof *V_223 ) ;
V_223 -> V_118 = V_310 ;
V_223 -> V_295 = F_75 ( ( T_7 ) V_166 -> V_311 -> V_295 << 48 ) ;
V_223 -> V_120 = V_103 -> V_312 ;
memcpy ( V_223 -> V_313 , V_166 -> V_314 , V_166 -> V_315 ) ;
V_103 -> V_166 = V_166 ;
V_103 -> V_223 = V_17 ;
V_197 = F_83 ( V_166 , V_6 , V_103 ) ;
if ( V_197 < 0 ) {
F_31 ( V_84 , V_6 -> V_85 ,
V_86 L_25 ) ;
goto V_316;
}
F_89 ( V_23 , V_17 -> V_21 , V_6 -> V_122 ,
V_152 ) ;
if ( F_94 ( V_6 , V_17 , V_197 ) ) {
F_31 ( V_84 , V_6 -> V_85 , V_86 L_26 ) ;
goto V_317;
}
return 0 ;
V_317:
F_58 ( V_166 , V_6 , V_103 ) ;
V_316:
F_90 ( V_6 , V_17 , V_308 ) ;
F_64 ( & V_6 -> V_141 , V_173 ) ;
F_71 ( & V_103 -> V_159 , & V_6 -> V_175 ) ;
V_309:
F_66 ( & V_6 -> V_141 , V_173 ) ;
V_58:
return V_318 ;
}
static int F_107 ( struct V_1 * V_6 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_57 ; ++ V_77 ) {
V_6 -> V_78 [ V_77 ] = F_4 ( V_6 -> V_12 ,
V_6 -> V_297 ,
V_33 , V_170 ) ;
if ( ! V_6 -> V_78 [ V_77 ] )
goto V_58;
}
for ( V_77 = 0 ; V_77 < V_61 ; ++ V_77 ) {
V_6 -> V_79 [ V_77 ] = F_4 ( V_6 -> V_12 ,
V_6 -> V_122 ,
V_33 , V_152 ) ;
if ( ! V_6 -> V_79 [ V_77 ] )
goto V_58;
F_71 ( & V_6 -> V_79 [ V_77 ] -> V_159 , & V_6 -> V_186 ) ;
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
static void F_108 ( struct V_49 * V_52 ,
struct V_319 * V_320 ,
struct V_1 * V_6 )
{
struct V_30 * V_179 = NULL ;
int V_321 = 0 ;
int V_32 ;
int V_77 ;
if ( V_320 -> V_118 == V_322 ) {
V_6 -> V_297 = F_99 ( V_320 -> V_297 ) ;
V_6 -> V_174 = F_99 ( V_320 -> V_172 ) ;
V_6 -> V_85 -> V_323
= F_88 ( V_6 -> V_174 - V_251 ,
V_6 -> V_85 -> V_323 ) ;
} else {
F_31 ( V_98 , V_6 -> V_85 ,
V_86 L_27 , V_320 -> V_118 ) ;
V_32 = - V_164 ;
goto error;
}
if ( ! V_6 -> V_78 [ 0 ] ) {
V_32 = F_107 ( V_6 ) ;
if ( V_32 )
goto error;
}
V_32 = - V_34 ;
V_179 = F_5 ( sizeof *V_179 , V_33 ) ;
if ( ! V_179 )
goto error;
V_179 -> V_39 = V_324 ;
V_32 = F_109 ( V_52 , V_179 , & V_321 ) ;
if ( V_32 )
goto V_325;
V_32 = F_17 ( V_6 -> V_29 , V_179 , V_321 ) ;
if ( V_32 )
goto V_325;
for ( V_77 = 0 ; V_77 < V_57 ; V_77 ++ ) {
struct V_11 * V_17 = V_6 -> V_78 [ V_77 ] ;
V_32 = F_96 ( V_6 , V_17 ) ;
if ( V_32 )
goto V_325;
}
V_179 -> V_39 = V_326 ;
V_32 = F_109 ( V_52 , V_179 , & V_321 ) ;
if ( V_32 )
goto V_325;
V_32 = F_17 ( V_6 -> V_29 , V_179 , V_321 ) ;
if ( V_32 )
goto V_325;
V_32 = F_110 ( V_52 , NULL , 0 ) ;
V_325:
F_9 ( V_179 ) ;
error:
V_6 -> V_80 = V_32 ;
}
static void F_111 ( struct V_49 * V_52 ,
struct V_327 * V_26 ,
struct V_1 * V_6 )
{
struct V_2 * V_306 = V_6 -> V_85 ;
struct V_328 * V_329 ;
int V_118 ;
switch ( V_26 -> V_100 . V_330 . V_331 ) {
case V_332 :
V_329 = V_26 -> V_100 . V_330 . V_333 ;
V_6 -> V_36 . V_334 = V_329 -> V_335 ;
V_6 -> V_36 . V_37 = V_329 -> V_336 ;
V_52 -> V_337 = F_99 ( V_329 -> V_338 ) & 0x00ffffff ;
memcpy ( V_6 -> V_36 . V_339 . V_340 , V_329 -> V_341 , 16 ) ;
V_6 -> V_80 = V_6 -> V_36 . V_334 ?
V_162 : V_161 ;
break;
case V_342 :
if ( F_3 ( V_6 ) ) {
memcpy ( V_6 -> V_36 . V_339 . V_340 ,
V_26 -> V_100 . V_330 . V_333 , 16 ) ;
F_31 ( V_135 , V_306 ,
V_86 L_28 ,
( unsigned long long ) F_41 ( V_6 -> V_36 . V_339 . V_130 . V_343 ) ,
( unsigned long long ) F_41 ( V_6 -> V_36 . V_339 . V_130 . V_131 ) ) ;
V_6 -> V_80 = V_161 ;
} else {
F_31 ( V_98 , V_306 ,
L_29 ) ;
V_6 -> V_80 = - V_164 ;
}
break;
case V_344 :
F_31 ( V_98 , V_306 ,
L_30 ) ;
V_6 -> V_80 = - V_164 ;
break;
case V_345 :
V_118 = * ( T_1 * ) V_26 -> V_108 ;
if ( V_118 == V_346 ) {
struct V_347 * V_348 = V_26 -> V_108 ;
T_6 V_331 = F_99 ( V_348 -> V_331 ) ;
if ( V_331 == V_349 )
F_31 ( V_98 , V_306 ,
V_86 L_31 ) ;
else
F_31 ( V_98 , V_306 ,
V_86 L_32 , V_331 ) ;
} else
F_31 ( V_98 , V_306 ,
L_33
L_34 , V_118 ) ;
V_6 -> V_80 = - V_164 ;
break;
case V_350 :
F_31 ( V_98 , V_306 , L_35 ) ;
V_6 -> V_80 = V_163 ;
break;
default:
F_31 ( V_98 , V_306 , L_36 ,
V_26 -> V_100 . V_330 . V_331 ) ;
V_6 -> V_80 = - V_164 ;
}
}
static int V_51 ( struct V_49 * V_52 , struct V_327 * V_26 )
{
struct V_1 * V_6 = V_52 -> V_27 ;
int V_351 = 0 ;
switch ( V_26 -> V_26 ) {
case V_352 :
F_31 ( V_135 , V_6 -> V_85 ,
V_86 L_37 ) ;
V_351 = 1 ;
V_6 -> V_80 = - V_164 ;
break;
case V_353 :
V_351 = 1 ;
F_108 ( V_52 , V_26 -> V_108 , V_6 ) ;
break;
case V_354 :
F_31 ( V_135 , V_6 -> V_85 , V_86 L_38 ) ;
V_351 = 1 ;
F_111 ( V_52 , V_26 , V_6 ) ;
break;
case V_355 :
F_31 ( V_98 , V_6 -> V_85 ,
V_86 L_39 ) ;
if ( F_112 ( V_52 , NULL , 0 ) )
F_31 ( V_84 , V_6 -> V_85 ,
V_86 L_40 ) ;
break;
case V_356 :
F_31 ( V_84 , V_6 -> V_85 ,
V_86 L_41 ) ;
V_351 = 1 ;
V_6 -> V_80 = 0 ;
break;
case V_357 :
case V_358 :
case V_359 :
break;
default:
F_31 ( V_98 , V_6 -> V_85 ,
V_86 L_42 , V_26 -> V_26 ) ;
break;
}
if ( V_351 )
F_32 ( & V_6 -> V_87 ) ;
return 0 ;
}
static int F_113 ( struct V_1 * V_6 ,
T_7 V_360 , unsigned int V_295 , T_1 V_361 )
{
struct V_143 * V_23 = V_6 -> V_12 -> V_22 -> V_23 ;
struct V_11 * V_17 ;
struct V_362 * V_363 ;
if ( V_6 -> V_142 == V_156 ||
V_6 -> V_142 == V_157 )
return - 1 ;
F_34 ( & V_6 -> V_275 ) ;
F_46 ( & V_6 -> V_141 ) ;
V_17 = F_91 ( V_6 , V_250 ) ;
F_47 ( & V_6 -> V_141 ) ;
if ( ! V_17 )
return - 1 ;
F_86 ( V_23 , V_17 -> V_21 , sizeof *V_363 ,
V_152 ) ;
V_363 = V_17 -> V_19 ;
memset ( V_363 , 0 , sizeof *V_363 ) ;
V_363 -> V_118 = V_364 ;
V_363 -> V_295 = F_75 ( ( T_7 ) V_295 << 48 ) ;
V_363 -> V_120 = V_360 | V_271 ;
V_363 -> V_365 = V_361 ;
V_363 -> V_366 = V_360 ;
F_89 ( V_23 , V_17 -> V_21 , sizeof *V_363 ,
V_152 ) ;
if ( F_94 ( V_6 , V_17 , sizeof *V_363 ) ) {
F_90 ( V_6 , V_17 , V_250 ) ;
return - 1 ;
}
if ( ! F_114 ( & V_6 -> V_275 ,
F_115 ( V_367 ) ) )
return - 1 ;
return 0 ;
}
static int F_116 ( struct V_165 * V_166 )
{
struct V_1 * V_6 = F_1 ( V_166 -> V_311 -> V_3 ) ;
struct V_145 * V_103 = (struct V_145 * ) V_166 -> V_286 ;
int V_32 = V_368 ;
F_31 ( V_84 , V_6 -> V_85 , L_43 ) ;
if ( ! V_103 || V_6 -> V_187 )
return V_369 ;
if ( F_113 ( V_6 , V_103 -> V_312 , V_166 -> V_311 -> V_295 ,
V_370 ) )
return V_369 ;
if ( V_103 -> V_166 ) {
if ( ! V_6 -> V_272 ) {
F_63 ( V_6 , V_103 , 0 ) ;
V_166 -> V_176 = V_371 << 16 ;
} else
V_32 = V_369 ;
}
return V_32 ;
}
static int F_117 ( struct V_165 * V_166 )
{
struct V_1 * V_6 = F_1 ( V_166 -> V_311 -> V_3 ) ;
int V_77 ;
F_31 ( V_84 , V_6 -> V_85 , L_44 ) ;
if ( V_6 -> V_187 )
return V_369 ;
if ( F_113 ( V_6 , V_372 , V_166 -> V_311 -> V_295 ,
V_373 ) )
return V_369 ;
if ( V_6 -> V_272 )
return V_369 ;
for ( V_77 = 0 ; V_77 < V_147 ; ++ V_77 ) {
struct V_145 * V_103 = & V_6 -> V_146 [ V_77 ] ;
if ( V_103 -> V_166 && V_103 -> V_166 -> V_311 == V_166 -> V_311 )
F_67 ( V_6 , V_103 ) ;
}
return V_368 ;
}
static int F_118 ( struct V_165 * V_166 )
{
struct V_1 * V_6 = F_1 ( V_166 -> V_311 -> V_3 ) ;
int V_32 = V_369 ;
F_31 ( V_84 , V_6 -> V_85 , V_86 L_45 ) ;
if ( ! F_68 ( V_6 ) )
V_32 = V_368 ;
return V_32 ;
}
static T_8 F_119 ( struct V_311 * V_23 , struct V_374 * V_31 ,
char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_120 ( V_23 ) ) ;
if ( V_6 -> V_142 == V_156 ||
V_6 -> V_142 == V_157 )
return - V_375 ;
return sprintf ( V_19 , L_46 ,
( unsigned long long ) F_41 ( V_6 -> V_134 ) ) ;
}
static T_8 F_121 ( struct V_311 * V_23 , struct V_374 * V_31 ,
char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_120 ( V_23 ) ) ;
if ( V_6 -> V_142 == V_156 ||
V_6 -> V_142 == V_157 )
return - V_375 ;
return sprintf ( V_19 , L_46 ,
( unsigned long long ) F_41 ( V_6 -> V_10 ) ) ;
}
static T_8 F_122 ( struct V_311 * V_23 ,
struct V_374 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_120 ( V_23 ) ) ;
if ( V_6 -> V_142 == V_156 ||
V_6 -> V_142 == V_157 )
return - V_375 ;
return sprintf ( V_19 , L_46 ,
( unsigned long long ) F_41 ( V_6 -> V_106 ) ) ;
}
static T_8 F_123 ( struct V_311 * V_23 , struct V_374 * V_31 ,
char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_120 ( V_23 ) ) ;
if ( V_6 -> V_142 == V_156 ||
V_6 -> V_142 == V_157 )
return - V_375 ;
return sprintf ( V_19 , L_47 , F_16 ( V_6 -> V_36 . V_37 ) ) ;
}
static T_8 F_124 ( struct V_311 * V_23 , struct V_374 * V_31 ,
char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_120 ( V_23 ) ) ;
if ( V_6 -> V_142 == V_156 ||
V_6 -> V_142 == V_157 )
return - V_375 ;
return sprintf ( V_19 , L_48 , V_6 -> V_36 . V_339 . V_340 ) ;
}
static T_8 F_125 ( struct V_311 * V_23 ,
struct V_374 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_120 ( V_23 ) ) ;
if ( V_6 -> V_142 == V_156 ||
V_6 -> V_142 == V_157 )
return - V_375 ;
return sprintf ( V_19 , L_48 , V_6 -> V_376 ) ;
}
static T_8 F_126 ( struct V_311 * V_23 ,
struct V_374 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_120 ( V_23 ) ) ;
if ( V_6 -> V_142 == V_156 ||
V_6 -> V_142 == V_157 )
return - V_375 ;
return sprintf ( V_19 , L_49 , V_6 -> V_174 ) ;
}
static T_8 F_127 ( struct V_311 * V_23 ,
struct V_374 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_120 ( V_23 ) ) ;
if ( V_6 -> V_142 == V_156 ||
V_6 -> V_142 == V_157 )
return - V_375 ;
return sprintf ( V_19 , L_49 , V_6 -> V_252 ) ;
}
static T_8 F_128 ( struct V_311 * V_23 ,
struct V_374 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_120 ( V_23 ) ) ;
return sprintf ( V_19 , L_49 , V_6 -> V_12 -> V_35 ) ;
}
static T_8 F_129 ( struct V_311 * V_23 ,
struct V_374 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_120 ( V_23 ) ) ;
return sprintf ( V_19 , L_50 , V_6 -> V_12 -> V_22 -> V_23 -> V_377 ) ;
}
static T_8 F_130 ( struct V_311 * V_23 ,
struct V_374 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_120 ( V_23 ) ) ;
return sprintf ( V_19 , L_51 , V_6 -> V_238 ) ;
}
static T_8 F_131 ( struct V_311 * V_23 ,
struct V_374 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_120 ( V_23 ) ) ;
return sprintf ( V_19 , L_50 , V_6 -> V_239 ? L_52 : L_53 ) ;
}
static int F_132 ( struct V_12 * V_3 , struct V_1 * V_6 )
{
struct V_378 V_379 ;
struct V_380 * V_381 ;
sprintf ( V_6 -> V_5 , L_54 ,
( unsigned long long ) F_41 ( V_6 -> V_134 ) ) ;
if ( F_133 ( V_6 -> V_85 , V_3 -> V_22 -> V_23 -> V_382 ) )
return - V_375 ;
memcpy ( V_379 . V_383 , & V_6 -> V_134 , 8 ) ;
memcpy ( V_379 . V_383 + 8 , & V_6 -> V_10 , 8 ) ;
V_379 . V_384 = V_385 ;
V_381 = F_134 ( V_6 -> V_85 , & V_379 ) ;
if ( F_20 ( V_381 ) ) {
F_55 ( V_6 -> V_85 ) ;
return F_21 ( V_381 ) ;
}
F_51 ( & V_3 -> V_158 ) ;
F_65 ( & V_6 -> V_159 , & V_3 -> V_386 ) ;
F_53 ( & V_3 -> V_158 ) ;
V_6 -> V_142 = V_182 ;
F_135 ( & V_6 -> V_85 -> V_387 ,
0 , V_6 -> V_388 , V_389 , 0 ) ;
return 0 ;
}
static void F_136 ( struct V_311 * V_23 )
{
struct V_12 * V_3 =
F_50 ( V_23 , struct V_12 , V_23 ) ;
F_32 ( & V_3 -> V_390 ) ;
}
static int F_137 ( const char * V_19 , struct V_1 * V_6 )
{
char * V_391 , * V_392 ;
char * V_393 ;
char V_339 [ 3 ] ;
T_9 args [ V_394 ] ;
int V_395 = 0 ;
int V_396 ;
int V_32 = - V_231 ;
int V_77 ;
V_391 = F_138 ( V_19 , V_33 ) ;
if ( ! V_391 )
return - V_34 ;
V_392 = V_391 ;
while ( ( V_393 = F_139 ( & V_392 , L_55 ) ) != NULL ) {
if ( ! * V_393 )
continue;
V_396 = F_140 ( V_393 , V_397 , args ) ;
V_395 |= V_396 ;
switch ( V_396 ) {
case V_398 :
V_393 = F_141 ( args ) ;
if ( ! V_393 ) {
V_32 = - V_34 ;
goto V_18;
}
V_6 -> V_134 = F_75 ( F_142 ( V_393 , NULL , 16 ) ) ;
F_9 ( V_393 ) ;
break;
case V_399 :
V_393 = F_141 ( args ) ;
if ( ! V_393 ) {
V_32 = - V_34 ;
goto V_18;
}
V_6 -> V_10 = F_75 ( F_142 ( V_393 , NULL , 16 ) ) ;
F_9 ( V_393 ) ;
break;
case V_400 :
V_393 = F_141 ( args ) ;
if ( ! V_393 ) {
V_32 = - V_34 ;
goto V_18;
}
if ( strlen ( V_393 ) != 32 ) {
F_13 (KERN_WARNING PFX L_56 , p) ;
F_9 ( V_393 ) ;
goto V_18;
}
for ( V_77 = 0 ; V_77 < 16 ; ++ V_77 ) {
F_143 ( V_339 , V_393 + V_77 * 2 , 3 ) ;
V_6 -> V_36 . V_339 . V_340 [ V_77 ] = F_144 ( V_339 , NULL , 16 ) ;
}
F_9 ( V_393 ) ;
memcpy ( V_6 -> V_376 , V_6 -> V_36 . V_339 . V_340 , 16 ) ;
break;
case V_401 :
if ( F_145 ( args , & V_396 ) ) {
F_13 (KERN_WARNING PFX L_57 , p) ;
goto V_18;
}
V_6 -> V_36 . V_37 = F_40 ( V_396 ) ;
break;
case V_402 :
V_393 = F_141 ( args ) ;
if ( ! V_393 ) {
V_32 = - V_34 ;
goto V_18;
}
V_6 -> V_106 = F_75 ( F_142 ( V_393 , NULL , 16 ) ) ;
V_6 -> V_36 . V_106 = V_6 -> V_106 ;
F_9 ( V_393 ) ;
break;
case V_403 :
if ( F_146 ( args , & V_396 ) ) {
F_13 (KERN_WARNING PFX L_58 , p) ;
goto V_18;
}
V_6 -> V_85 -> V_404 = V_396 ;
break;
case V_405 :
if ( F_146 ( args , & V_396 ) ) {
F_13 (KERN_WARNING PFX L_59 , p) ;
goto V_18;
}
V_6 -> V_85 -> V_406 = F_88 ( V_396 , V_147 ) ;
break;
case V_407 :
if ( F_145 ( args , & V_396 ) ) {
F_13 (KERN_WARNING PFX L_60 , p) ;
goto V_18;
}
if ( V_396 != V_127 &&
V_396 != V_408 ) {
F_13 (KERN_WARNING PFX L_61
L_62 ,
token, SRP_REV10_IB_IO_CLASS, SRP_REV16A_IB_IO_CLASS) ;
goto V_18;
}
V_6 -> V_126 = V_396 ;
break;
case V_409 :
V_393 = F_141 ( args ) ;
if ( ! V_393 ) {
V_32 = - V_34 ;
goto V_18;
}
V_6 -> V_132 = F_75 ( F_142 ( V_393 , NULL , 16 ) ) ;
F_9 ( V_393 ) ;
break;
case V_410 :
if ( F_146 ( args , & V_396 ) || V_396 < 1 || V_396 > 255 ) {
F_13 (KERN_WARNING PFX L_63 , p) ;
goto V_18;
}
V_6 -> V_238 = V_396 ;
break;
case V_411 :
if ( F_146 ( args , & V_396 ) ) {
F_13 (KERN_WARNING PFX L_64 , p) ;
goto V_18;
}
V_6 -> V_239 = ! ! V_396 ;
break;
case V_412 :
if ( F_146 ( args , & V_396 ) || V_396 < 1 ||
V_396 > V_413 ) {
F_13 (KERN_WARNING PFX L_65 , p) ;
goto V_18;
}
V_6 -> V_414 = V_396 ;
break;
default:
F_13 (KERN_WARNING PFX L_66
L_67 , p) ;
goto V_18;
}
}
if ( ( V_395 & V_415 ) == V_415 )
V_32 = 0 ;
else
for ( V_77 = 0 ; V_77 < F_147 ( V_397 ) ; ++ V_77 )
if ( ( V_397 [ V_77 ] . V_396 & V_415 ) &&
! ( V_397 [ V_77 ] . V_396 & V_395 ) )
F_13 (KERN_WARNING PFX L_68
L_69 ,
srp_opt_tokens[i].pattern) ;
V_18:
F_9 ( V_391 ) ;
return V_32 ;
}
static T_8 F_148 ( struct V_311 * V_23 ,
struct V_374 * V_31 ,
const char * V_19 , T_2 V_225 )
{
struct V_12 * V_3 =
F_50 ( V_23 , struct V_12 , V_23 ) ;
struct V_2 * V_416 ;
struct V_1 * V_6 ;
struct V_143 * V_144 = V_3 -> V_22 -> V_23 ;
T_5 V_190 ;
int V_77 , V_32 ;
V_416 = F_149 ( & V_417 ,
sizeof ( struct V_1 ) ) ;
if ( ! V_416 )
return - V_34 ;
V_416 -> V_418 = V_419 ;
V_416 -> V_420 = V_421 ;
V_416 -> V_422 = sizeof ( (struct V_222 * ) ( void * ) 0L ) -> V_313 ;
V_6 = F_1 ( V_416 ) ;
V_6 -> V_126 = V_408 ;
V_6 -> V_85 = V_416 ;
V_6 -> V_12 = V_3 ;
V_6 -> V_259 = V_3 -> V_22 -> V_423 -> V_259 ;
V_6 -> V_192 = V_3 -> V_22 -> V_423 -> V_192 ;
V_6 -> V_238 = V_424 ;
V_6 -> V_414 = V_425 ? : V_424 ;
V_6 -> V_239 = V_239 ;
V_32 = F_137 ( V_19 , V_6 ) ;
if ( V_32 )
goto V_58;
if ( ! V_3 -> V_22 -> V_206 && ! V_6 -> V_239 &&
V_6 -> V_238 < V_6 -> V_414 ) {
F_13 (KERN_WARNING PFX L_70 ) ;
V_6 -> V_414 = V_6 -> V_238 ;
}
V_416 -> V_414 = V_6 -> V_414 ;
V_6 -> V_151 = V_6 -> V_414 *
sizeof ( struct V_193 ) ;
V_6 -> V_122 = sizeof ( struct V_222 ) +
sizeof ( struct V_226 ) +
V_6 -> V_238 * sizeof ( struct V_193 ) ;
F_150 ( & V_6 -> V_141 ) ;
F_70 ( & V_6 -> V_186 ) ;
F_70 ( & V_6 -> V_175 ) ;
for ( V_77 = 0 ; V_77 < V_147 ; ++ V_77 ) {
struct V_145 * V_103 = & V_6 -> V_146 [ V_77 ] ;
V_103 -> V_148 = F_5 ( V_6 -> V_238 * sizeof ( void * ) ,
V_33 ) ;
V_103 -> V_149 = F_5 ( V_219 * sizeof ( void * ) ,
V_33 ) ;
V_103 -> V_153 = F_5 ( V_6 -> V_151 , V_33 ) ;
if ( ! V_103 -> V_148 || ! V_103 -> V_149 || ! V_103 -> V_153 )
goto V_426;
V_190 = F_7 ( V_144 , V_103 -> V_153 ,
V_6 -> V_151 ,
V_152 ) ;
if ( F_8 ( V_144 , V_190 ) )
goto V_426;
V_103 -> V_150 = V_190 ;
V_103 -> V_312 = V_77 ;
F_65 ( & V_103 -> V_159 , & V_6 -> V_175 ) ;
}
F_151 ( V_144 , V_3 -> V_35 , 0 , & V_6 -> V_36 . V_129 ) ;
F_31 ( V_135 , V_6 -> V_85 , V_86
L_71
L_72 ,
( unsigned long long ) F_41 ( V_6 -> V_134 ) ,
( unsigned long long ) F_41 ( V_6 -> V_10 ) ,
F_16 ( V_6 -> V_36 . V_37 ) ,
( unsigned long long ) F_41 ( V_6 -> V_106 ) ,
V_6 -> V_36 . V_339 . V_340 ) ;
V_32 = F_23 ( V_6 ) ;
if ( V_32 )
goto V_426;
V_32 = F_18 ( V_6 ) ;
if ( V_32 )
goto V_427;
V_6 -> V_187 = 0 ;
V_32 = F_57 ( V_6 ) ;
if ( V_32 ) {
F_31 ( V_84 , V_6 -> V_85 ,
V_86 L_73 ) ;
goto V_428;
}
V_32 = F_132 ( V_3 , V_6 ) ;
if ( V_32 )
goto V_429;
return V_225 ;
V_429:
F_43 ( V_6 ) ;
V_428:
F_22 ( V_6 -> V_52 ) ;
V_427:
F_29 ( V_6 ) ;
V_426:
F_48 ( V_6 ) ;
V_58:
F_56 ( V_416 ) ;
return V_32 ;
}
static T_8 F_152 ( struct V_311 * V_23 , struct V_374 * V_31 ,
char * V_19 )
{
struct V_12 * V_3 = F_50 ( V_23 , struct V_12 , V_23 ) ;
return sprintf ( V_19 , L_50 , V_3 -> V_22 -> V_23 -> V_377 ) ;
}
static T_8 F_153 ( struct V_311 * V_23 , struct V_374 * V_31 ,
char * V_19 )
{
struct V_12 * V_3 = F_50 ( V_23 , struct V_12 , V_23 ) ;
return sprintf ( V_19 , L_49 , V_3 -> V_35 ) ;
}
static struct V_12 * F_154 ( struct V_200 * V_311 , T_1 V_35 )
{
struct V_12 * V_3 ;
V_3 = F_6 ( sizeof *V_3 , V_33 ) ;
if ( ! V_3 )
return NULL ;
F_70 ( & V_3 -> V_386 ) ;
F_150 ( & V_3 -> V_158 ) ;
F_34 ( & V_3 -> V_390 ) ;
V_3 -> V_22 = V_311 ;
V_3 -> V_35 = V_35 ;
V_3 -> V_23 . V_430 = & V_431 ;
V_3 -> V_23 . V_432 = V_311 -> V_23 -> V_382 ;
F_155 ( & V_3 -> V_23 , L_74 , V_311 -> V_23 -> V_377 , V_35 ) ;
if ( F_156 ( & V_3 -> V_23 ) )
goto V_433;
if ( F_157 ( & V_3 -> V_23 , & V_434 ) )
goto V_435;
if ( F_157 ( & V_3 -> V_23 , & V_436 ) )
goto V_435;
if ( F_157 ( & V_3 -> V_23 , & V_437 ) )
goto V_435;
return V_3 ;
V_435:
F_158 ( & V_3 -> V_23 ) ;
V_433:
F_9 ( V_3 ) ;
return NULL ;
}
static void F_159 ( struct V_143 * V_311 )
{
struct V_200 * V_22 ;
struct V_438 * V_439 ;
struct V_440 V_441 ;
struct V_12 * V_3 ;
int V_442 , V_443 , V_444 , V_445 , V_393 ;
V_439 = F_5 ( sizeof *V_439 , V_33 ) ;
if ( ! V_439 )
return;
if ( F_160 ( V_311 , V_439 ) ) {
F_13 (KERN_WARNING PFX L_75 ,
device->name) ;
goto V_446;
}
V_22 = F_5 ( sizeof *V_22 , V_33 ) ;
if ( ! V_22 )
goto V_446;
V_443 = F_161 ( 12 , F_162 ( V_439 -> V_447 ) - 1 ) ;
V_22 -> V_220 = 1 << V_443 ;
V_22 -> V_217 = ~ ( ( T_7 ) V_22 -> V_220 - 1 ) ;
V_22 -> V_218 = V_22 -> V_220 * V_219 ;
F_70 ( & V_22 -> V_448 ) ;
V_22 -> V_23 = V_311 ;
V_22 -> V_74 = F_163 ( V_311 ) ;
if ( F_20 ( V_22 -> V_74 ) )
goto V_449;
V_22 -> V_423 = F_164 ( V_22 -> V_74 ,
V_450 |
V_42 |
V_43 ) ;
if ( F_20 ( V_22 -> V_423 ) )
goto V_451;
for ( V_442 = V_219 ;
V_442 >= V_452 ;
V_442 /= 2 , V_22 -> V_218 /= 2 ) {
memset ( & V_441 , 0 , sizeof V_441 ) ;
V_441 . V_453 = V_454 ;
V_441 . V_455 = V_456 ;
V_441 . V_457 = 1 ;
V_441 . V_442 = V_442 ;
V_441 . V_458 = V_443 ;
V_441 . V_459 = ( V_450 |
V_43 |
V_42 ) ;
V_22 -> V_206 = F_165 ( V_22 -> V_74 , & V_441 ) ;
if ( ! F_20 ( V_22 -> V_206 ) )
break;
}
if ( F_20 ( V_22 -> V_206 ) )
V_22 -> V_206 = NULL ;
if ( V_311 -> V_460 == V_461 ) {
V_444 = 0 ;
V_445 = 0 ;
} else {
V_444 = 1 ;
V_445 = V_311 -> V_462 ;
}
for ( V_393 = V_444 ; V_393 <= V_445 ; ++ V_393 ) {
V_3 = F_154 ( V_22 , V_393 ) ;
if ( V_3 )
F_65 ( & V_3 -> V_159 , & V_22 -> V_448 ) ;
}
F_166 ( V_311 , & V_463 , V_22 ) ;
goto V_446;
V_451:
F_167 ( V_22 -> V_74 ) ;
V_449:
F_9 ( V_22 ) ;
V_446:
F_9 ( V_439 ) ;
}
static void F_168 ( struct V_143 * V_311 )
{
struct V_200 * V_22 ;
struct V_12 * V_3 , * V_464 ;
F_169 ( V_386 ) ;
struct V_1 * V_6 , * V_465 ;
V_22 = F_170 ( V_311 , & V_463 ) ;
F_171 (host, tmp_host, &srp_dev->dev_list, list) {
F_158 ( & V_3 -> V_23 ) ;
F_36 ( & V_3 -> V_390 ) ;
F_51 ( & V_3 -> V_158 ) ;
F_172 (target, &host->target_list, list) {
F_46 ( & V_6 -> V_141 ) ;
V_6 -> V_142 = V_157 ;
F_47 ( & V_6 -> V_141 ) ;
}
F_53 ( & V_3 -> V_158 ) ;
F_173 ( V_188 ) ;
F_171 (target, tmp_target,
&host->target_list, list) {
F_54 ( V_6 -> V_85 ) ;
F_55 ( V_6 -> V_85 ) ;
F_43 ( V_6 ) ;
F_22 ( V_6 -> V_52 ) ;
F_29 ( V_6 ) ;
F_48 ( V_6 ) ;
F_56 ( V_6 -> V_85 ) ;
}
F_9 ( V_3 ) ;
}
if ( V_22 -> V_206 )
F_174 ( V_22 -> V_206 ) ;
F_175 ( V_22 -> V_423 ) ;
F_167 ( V_22 -> V_74 ) ;
F_9 ( V_22 ) ;
}
static int T_10 F_176 ( void )
{
int V_32 ;
F_177 ( F_178 ( struct V_180 , V_261 ) < sizeof( void * ) ) ;
if ( V_466 ) {
F_13 (KERN_WARNING PFX L_76 ) ;
if ( ! V_424 )
V_424 = V_466 ;
}
if ( ! V_424 )
V_424 = V_467 ;
if ( V_424 > 255 ) {
F_13 (KERN_WARNING PFX L_77 ) ;
V_424 = 255 ;
}
if ( ! V_425 )
V_425 = V_424 ;
else if ( V_425 < V_424 ) {
F_13 (KERN_WARNING PFX L_78 , cmd_sg_entries) ;
V_425 = V_424 ;
}
V_419 =
F_179 ( & V_468 ) ;
if ( ! V_419 )
return - V_34 ;
V_32 = F_180 ( & V_431 ) ;
if ( V_32 ) {
F_13 (KERN_ERR PFX L_79 ) ;
F_181 ( V_419 ) ;
return V_32 ;
}
F_182 ( & V_90 ) ;
V_32 = F_183 ( & V_463 ) ;
if ( V_32 ) {
F_13 (KERN_ERR PFX L_80 ) ;
F_181 ( V_419 ) ;
F_184 ( & V_90 ) ;
F_185 ( & V_431 ) ;
return V_32 ;
}
return 0 ;
}
static void T_11 F_186 ( void )
{
F_187 ( & V_463 ) ;
F_184 ( & V_90 ) ;
F_185 ( & V_431 ) ;
F_181 ( V_419 ) ;
}
