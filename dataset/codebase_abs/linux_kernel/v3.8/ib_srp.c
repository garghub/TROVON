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
struct V_55 * V_56 , * V_57 ;
struct V_28 * V_29 ;
int V_32 ;
V_54 = F_6 ( sizeof *V_54 , V_33 ) ;
if ( ! V_54 )
return - V_34 ;
V_56 = F_24 ( V_6 -> V_12 -> V_22 -> V_23 ,
V_58 , NULL , V_6 , V_59 , 0 ) ;
if ( F_20 ( V_56 ) ) {
V_32 = F_21 ( V_56 ) ;
goto V_60;
}
V_57 = F_24 ( V_6 -> V_12 -> V_22 -> V_23 ,
V_61 , NULL , V_6 , V_62 , 0 ) ;
if ( F_20 ( V_57 ) ) {
V_32 = F_21 ( V_57 ) ;
goto V_63;
}
F_25 ( V_56 , V_64 ) ;
V_54 -> V_65 = F_12 ;
V_54 -> V_66 . V_67 = V_62 ;
V_54 -> V_66 . V_68 = V_59 ;
V_54 -> V_66 . V_69 = 1 ;
V_54 -> V_66 . V_70 = 1 ;
V_54 -> V_71 = V_72 ;
V_54 -> V_73 = V_74 ;
V_54 -> V_57 = V_57 ;
V_54 -> V_56 = V_56 ;
V_29 = F_26 ( V_6 -> V_12 -> V_22 -> V_75 , V_54 ) ;
if ( F_20 ( V_29 ) ) {
V_32 = F_21 ( V_29 ) ;
goto V_76;
}
V_32 = F_14 ( V_6 , V_29 ) ;
if ( V_32 )
goto V_77;
if ( V_6 -> V_29 )
F_27 ( V_6 -> V_29 ) ;
if ( V_6 -> V_56 )
F_28 ( V_6 -> V_56 ) ;
if ( V_6 -> V_57 )
F_28 ( V_6 -> V_57 ) ;
V_6 -> V_29 = V_29 ;
V_6 -> V_56 = V_56 ;
V_6 -> V_57 = V_57 ;
F_9 ( V_54 ) ;
return 0 ;
V_77:
F_27 ( V_29 ) ;
V_76:
F_28 ( V_57 ) ;
V_63:
F_28 ( V_56 ) ;
V_60:
F_9 ( V_54 ) ;
return V_32 ;
}
static void F_29 ( struct V_1 * V_6 )
{
int V_78 ;
F_27 ( V_6 -> V_29 ) ;
F_28 ( V_6 -> V_57 ) ;
F_28 ( V_6 -> V_56 ) ;
V_6 -> V_29 = NULL ;
V_6 -> V_57 = V_6 -> V_56 = NULL ;
for ( V_78 = 0 ; V_78 < V_59 ; ++ V_78 )
F_10 ( V_6 -> V_12 , V_6 -> V_79 [ V_78 ] ) ;
for ( V_78 = 0 ; V_78 < V_62 ; ++ V_78 )
F_10 ( V_6 -> V_12 , V_6 -> V_80 [ V_78 ] ) ;
}
static void F_30 ( int V_81 ,
struct V_82 * V_83 ,
void * V_84 )
{
struct V_1 * V_6 = V_84 ;
V_6 -> V_81 = V_81 ;
if ( V_81 )
F_31 ( V_85 , V_6 -> V_86 ,
V_87 L_2 , V_81 ) ;
else
V_6 -> V_36 = * V_83 ;
F_32 ( & V_6 -> V_88 ) ;
}
static int F_33 ( struct V_1 * V_6 )
{
V_6 -> V_36 . V_89 = 1 ;
F_34 ( & V_6 -> V_88 ) ;
V_6 -> V_90 = F_35 ( & V_91 ,
V_6 -> V_12 -> V_22 -> V_23 ,
V_6 -> V_12 -> V_35 ,
& V_6 -> V_36 ,
V_92 |
V_93 |
V_94 |
V_95 |
V_96 ,
V_97 ,
V_33 ,
F_30 ,
V_6 , & V_6 -> V_98 ) ;
if ( V_6 -> V_90 < 0 )
return V_6 -> V_90 ;
F_36 ( & V_6 -> V_88 ) ;
if ( V_6 -> V_81 < 0 )
F_31 ( V_99 , V_6 -> V_86 ,
V_87 L_3 ) ;
return V_6 -> V_81 ;
}
static int F_37 ( struct V_1 * V_6 )
{
struct {
struct V_100 V_101 ;
struct V_102 V_103 ;
} * V_104 = NULL ;
int V_81 ;
V_104 = F_6 ( sizeof *V_104 , V_33 ) ;
if ( ! V_104 )
return - V_34 ;
V_104 -> V_101 . V_105 = & V_6 -> V_36 ;
V_104 -> V_101 . V_106 = NULL ;
V_104 -> V_101 . V_107 = V_6 -> V_107 ;
V_104 -> V_101 . V_108 = V_6 -> V_29 -> V_108 ;
V_104 -> V_101 . V_73 = V_6 -> V_29 -> V_73 ;
V_104 -> V_101 . V_109 = & V_104 -> V_103 ;
V_104 -> V_101 . V_110 = sizeof V_104 -> V_103 ;
V_104 -> V_101 . V_111 = 1 ;
F_38 ( & V_104 -> V_101 . V_112 , 4 ) ;
V_104 -> V_101 . V_112 &= 0xffffff ;
V_104 -> V_101 . V_113 = 4 ;
V_104 -> V_101 . V_114 = 20 ;
V_104 -> V_101 . V_115 = 20 ;
V_104 -> V_101 . V_116 = 7 ;
V_104 -> V_101 . V_117 = 7 ;
V_104 -> V_101 . V_118 = 15 ;
V_104 -> V_103 . V_119 = V_120 ;
V_104 -> V_103 . V_121 = 0 ;
V_104 -> V_103 . V_122 = F_39 ( V_6 -> V_123 ) ;
V_104 -> V_103 . V_124 = F_40 ( V_125 |
V_126 ) ;
if ( V_6 -> V_127 == V_128 ) {
memcpy ( V_104 -> V_103 . V_129 ,
& V_6 -> V_36 . V_130 . V_131 . V_132 , 8 ) ;
memcpy ( V_104 -> V_103 . V_129 + 8 ,
& V_6 -> V_133 , 8 ) ;
memcpy ( V_104 -> V_103 . V_134 , & V_6 -> V_10 , 8 ) ;
memcpy ( V_104 -> V_103 . V_134 + 8 , & V_6 -> V_135 , 8 ) ;
} else {
memcpy ( V_104 -> V_103 . V_129 ,
& V_6 -> V_133 , 8 ) ;
memcpy ( V_104 -> V_103 . V_129 + 8 ,
& V_6 -> V_36 . V_130 . V_131 . V_132 , 8 ) ;
memcpy ( V_104 -> V_103 . V_134 , & V_6 -> V_135 , 8 ) ;
memcpy ( V_104 -> V_103 . V_134 + 8 , & V_6 -> V_10 , 8 ) ;
}
if ( F_3 ( V_6 ) ) {
F_31 ( V_136 , V_6 -> V_86 ,
V_87 L_4
L_5 ,
( unsigned long long ) F_41 ( V_6 -> V_10 ) ) ;
memset ( V_104 -> V_103 . V_129 , 0 , 8 ) ;
memcpy ( V_104 -> V_103 . V_129 + 8 ,
& V_6 -> V_12 -> V_22 -> V_23 -> V_137 , 8 ) ;
}
V_81 = F_42 ( V_6 -> V_52 , & V_104 -> V_101 ) ;
F_9 ( V_104 ) ;
return V_81 ;
}
static bool F_43 ( struct V_1 * V_6 )
{
bool V_138 = false ;
F_44 ( & V_6 -> V_139 ) ;
if ( V_6 -> V_140 != V_141 ) {
V_6 -> V_140 = V_141 ;
V_138 = true ;
}
F_45 ( & V_6 -> V_139 ) ;
if ( V_138 )
F_46 ( V_142 , & V_6 -> V_143 ) ;
return V_138 ;
}
static bool F_47 ( struct V_1 * V_6 ,
bool V_144 )
{
bool V_138 = false ;
F_44 ( & V_6 -> V_139 ) ;
if ( V_6 -> V_144 != V_144 ) {
V_6 -> V_144 = V_144 ;
V_138 = true ;
}
F_45 ( & V_6 -> V_139 ) ;
return V_138 ;
}
static void F_48 ( struct V_1 * V_6 )
{
if ( F_47 ( V_6 , false ) ) {
if ( F_49 ( V_6 -> V_52 , NULL , 0 ) ) {
F_31 ( V_136 , V_6 -> V_86 ,
V_87 L_6 ) ;
}
}
}
static void F_50 ( struct V_1 * V_6 )
{
struct V_145 * V_146 = V_6 -> V_12 -> V_22 -> V_23 ;
struct V_147 * V_104 ;
int V_78 ;
for ( V_78 = 0 , V_104 = V_6 -> V_148 ; V_78 < V_149 ; ++ V_78 , ++ V_104 ) {
F_9 ( V_104 -> V_150 ) ;
F_9 ( V_104 -> V_151 ) ;
if ( V_104 -> V_152 ) {
F_11 ( V_146 , V_104 -> V_152 ,
V_6 -> V_153 ,
V_154 ) ;
}
F_9 ( V_104 -> V_155 ) ;
}
}
static void F_51 ( struct V_2 * V_156 )
{
struct V_157 * * V_31 ;
for ( V_31 = V_156 -> V_158 -> V_159 ; V_31 && * V_31 ; ++ V_31 )
F_52 ( & V_156 -> V_160 , * V_31 ) ;
}
static void F_53 ( struct V_1 * V_6 )
{
F_54 ( V_6 -> V_140 != V_141 ) ;
F_51 ( V_6 -> V_86 ) ;
F_55 ( V_6 -> V_86 ) ;
F_56 ( V_6 -> V_86 ) ;
F_48 ( V_6 ) ;
F_22 ( V_6 -> V_52 ) ;
F_29 ( V_6 ) ;
F_50 ( V_6 ) ;
F_57 ( V_6 -> V_86 ) ;
}
static void F_58 ( struct V_161 * V_162 )
{
struct V_1 * V_6 =
F_59 ( V_162 , struct V_1 , V_143 ) ;
F_54 ( V_6 -> V_140 != V_141 ) ;
F_60 ( & V_6 -> V_12 -> V_163 ) ;
F_61 ( & V_6 -> V_164 ) ;
F_62 ( & V_6 -> V_12 -> V_163 ) ;
F_53 ( V_6 ) ;
}
static void F_63 ( struct V_165 * V_166 )
{
struct V_1 * V_6 = V_166 -> V_167 ;
F_43 ( V_6 ) ;
}
static int F_64 ( struct V_1 * V_6 )
{
int V_168 = 3 ;
int V_32 ;
F_54 ( V_6 -> V_144 ) ;
V_6 -> V_169 = false ;
V_32 = F_33 ( V_6 ) ;
if ( V_32 )
return V_32 ;
while ( 1 ) {
F_34 ( & V_6 -> V_88 ) ;
V_32 = F_37 ( V_6 ) ;
if ( V_32 )
return V_32 ;
F_36 ( & V_6 -> V_88 ) ;
switch ( V_6 -> V_81 ) {
case 0 :
F_47 ( V_6 , true ) ;
return 0 ;
case V_170 :
V_32 = F_33 ( V_6 ) ;
if ( V_32 )
return V_32 ;
break;
case V_171 :
break;
case V_172 :
if ( ! V_168 -- || F_18 ( V_6 ) ) {
F_31 ( V_85 , V_6 -> V_86 , V_87
L_7 ) ;
V_6 -> V_81 = - V_173 ;
return V_6 -> V_81 ;
}
F_31 ( V_85 , V_6 -> V_86 , V_87
L_8 ) ;
break;
default:
return V_6 -> V_81 ;
}
}
}
static void F_65 ( struct V_174 * V_175 ,
struct V_1 * V_6 ,
struct V_147 * V_104 )
{
struct V_145 * V_146 = V_6 -> V_12 -> V_22 -> V_23 ;
struct V_176 * * V_177 ;
if ( ! F_66 ( V_175 ) ||
( V_175 -> V_178 != V_154 &&
V_175 -> V_178 != V_179 ) )
return;
V_177 = V_104 -> V_150 ;
while ( V_104 -> V_180 -- )
F_67 ( * V_177 ++ ) ;
F_68 ( V_146 , F_66 ( V_175 ) , F_69 ( V_175 ) ,
V_175 -> V_178 ) ;
}
static struct V_174 * F_70 ( struct V_1 * V_6 ,
struct V_147 * V_104 ,
struct V_174 * V_175 )
{
unsigned long V_181 ;
F_71 ( & V_6 -> V_139 , V_181 ) ;
if ( ! V_175 ) {
V_175 = V_104 -> V_175 ;
V_104 -> V_175 = NULL ;
} else if ( V_104 -> V_175 == V_175 ) {
V_104 -> V_175 = NULL ;
} else {
V_175 = NULL ;
}
F_72 ( & V_6 -> V_139 , V_181 ) ;
return V_175 ;
}
static void F_73 ( struct V_1 * V_6 ,
struct V_147 * V_104 , struct V_174 * V_175 ,
T_4 V_182 )
{
unsigned long V_181 ;
F_65 ( V_175 , V_6 , V_104 ) ;
F_71 ( & V_6 -> V_139 , V_181 ) ;
V_6 -> V_183 += V_182 ;
F_74 ( & V_104 -> V_164 , & V_6 -> V_184 ) ;
F_72 ( & V_6 -> V_139 , V_181 ) ;
}
static void F_75 ( struct V_1 * V_6 , struct V_147 * V_104 )
{
struct V_174 * V_175 = F_70 ( V_6 , V_104 , NULL ) ;
if ( V_175 ) {
F_73 ( V_6 , V_104 , V_175 , 0 ) ;
V_175 -> V_185 = V_186 << 16 ;
V_175 -> V_187 ( V_175 ) ;
}
}
static int F_76 ( struct V_1 * V_6 )
{
struct V_2 * V_156 = V_6 -> V_86 ;
int V_78 , V_32 ;
if ( V_6 -> V_140 != V_188 )
return - V_189 ;
F_77 ( & V_156 -> V_190 ) ;
F_48 ( V_6 ) ;
V_32 = F_18 ( V_6 ) ;
if ( V_32 )
goto V_191;
V_32 = F_23 ( V_6 ) ;
if ( V_32 )
goto V_191;
for ( V_78 = 0 ; V_78 < V_149 ; ++ V_78 ) {
struct V_147 * V_104 = & V_6 -> V_148 [ V_78 ] ;
if ( V_104 -> V_175 )
F_75 ( V_6 , V_104 ) ;
}
F_78 ( & V_6 -> V_192 ) ;
for ( V_78 = 0 ; V_78 < V_62 ; ++ V_78 )
F_79 ( & V_6 -> V_80 [ V_78 ] -> V_164 , & V_6 -> V_192 ) ;
V_32 = F_64 ( V_6 ) ;
V_191:
F_80 ( & V_156 -> V_190 , V_32 == 0 ? V_193 :
V_194 ) ;
if ( V_32 )
goto V_60;
F_31 ( V_195 , V_6 -> V_86 , V_87 L_9 ) ;
return V_32 ;
V_60:
F_31 ( V_85 , V_6 -> V_86 ,
V_87 L_10 , V_32 ) ;
F_43 ( V_6 ) ;
return V_32 ;
}
static void F_81 ( struct V_196 * V_140 , T_5 V_197 ,
unsigned int V_198 , T_6 V_199 )
{
struct V_200 * V_201 = V_140 -> V_201 ;
V_201 -> V_202 = F_82 ( V_197 ) ;
V_201 -> V_203 = F_39 ( V_199 ) ;
V_201 -> V_204 = F_39 ( V_198 ) ;
V_140 -> V_205 += V_198 ;
V_140 -> V_201 ++ ;
V_140 -> V_206 ++ ;
}
static int F_83 ( struct V_196 * V_140 ,
struct V_1 * V_6 )
{
struct V_207 * V_23 = V_6 -> V_12 -> V_22 ;
struct V_176 * V_208 ;
T_7 V_209 = 0 ;
if ( ! V_140 -> V_210 )
return 0 ;
if ( V_140 -> V_210 == 1 ) {
F_81 ( V_140 , V_140 -> V_211 , V_140 -> V_212 ,
V_6 -> V_199 ) ;
V_140 -> V_210 = V_140 -> V_212 = 0 ;
return 0 ;
}
V_208 = F_84 ( V_23 -> V_213 , V_140 -> V_214 ,
V_140 -> V_210 , V_209 ) ;
if ( F_20 ( V_208 ) )
return F_21 ( V_208 ) ;
* V_140 -> V_215 ++ = V_208 ;
V_140 -> V_180 ++ ;
F_81 ( V_140 , 0 , V_140 -> V_212 , V_208 -> V_208 -> V_199 ) ;
V_140 -> V_210 = V_140 -> V_212 = 0 ;
return 0 ;
}
static void F_85 ( struct V_196 * V_140 ,
struct V_216 * V_217 , int V_218 ,
T_5 V_197 )
{
V_140 -> V_219 = V_217 ;
V_140 -> V_220 = V_218 ;
V_140 -> V_221 = V_197 ;
}
static int F_86 ( struct V_196 * V_140 ,
struct V_1 * V_6 ,
struct V_216 * V_217 , int V_218 ,
int V_222 )
{
struct V_207 * V_23 = V_6 -> V_12 -> V_22 ;
struct V_145 * V_146 = V_23 -> V_23 ;
T_5 V_197 = F_87 ( V_146 , V_217 ) ;
unsigned int V_198 = F_88 ( V_146 , V_217 ) ;
unsigned int V_204 ;
int V_32 ;
if ( ! V_198 )
return 0 ;
if ( V_222 == V_223 ) {
F_81 ( V_140 , V_197 , V_198 , V_6 -> V_199 ) ;
return 0 ;
}
if ( V_197 & ~ V_23 -> V_224 || V_198 > V_23 -> V_225 ) {
V_32 = F_83 ( V_140 , V_6 ) ;
if ( V_32 )
return V_32 ;
F_81 ( V_140 , V_197 , V_198 , V_6 -> V_199 ) ;
F_85 ( V_140 , NULL , 0 , 0 ) ;
return 0 ;
}
if ( ! V_140 -> V_219 )
F_85 ( V_140 , V_217 , V_218 , V_197 ) ;
while ( V_198 ) {
if ( V_140 -> V_210 == V_226 ) {
V_32 = F_83 ( V_140 , V_6 ) ;
if ( V_32 )
return V_32 ;
F_85 ( V_140 , V_217 , V_218 , V_197 ) ;
}
V_204 = F_89 (unsigned int, dma_len, dev->fmr_page_size) ;
if ( ! V_140 -> V_210 )
V_140 -> V_211 = V_197 ;
V_140 -> V_214 [ V_140 -> V_210 ++ ] = V_197 ;
V_140 -> V_212 += V_204 ;
V_197 += V_204 ;
V_198 -= V_204 ;
}
V_32 = 0 ;
if ( V_204 != V_23 -> V_227 ) {
V_32 = F_83 ( V_140 , V_6 ) ;
if ( ! V_32 )
F_85 ( V_140 , NULL , 0 , 0 ) ;
}
return V_32 ;
}
static int F_90 ( struct V_174 * V_175 , struct V_1 * V_6 ,
struct V_147 * V_104 )
{
struct V_216 * V_228 , * V_217 ;
struct V_229 * V_230 = V_104 -> V_230 -> V_19 ;
int V_78 , V_204 , V_231 , V_232 , V_222 ;
struct V_207 * V_23 ;
struct V_145 * V_146 ;
struct V_196 V_140 ;
struct V_233 * V_234 ;
T_6 V_235 ;
T_1 V_236 ;
if ( ! F_66 ( V_175 ) || V_175 -> V_178 == V_237 )
return sizeof ( struct V_229 ) ;
if ( V_175 -> V_178 != V_179 &&
V_175 -> V_178 != V_154 ) {
F_31 ( V_99 , V_6 -> V_86 ,
V_87 L_11 ,
V_175 -> V_178 ) ;
return - V_238 ;
}
V_231 = F_69 ( V_175 ) ;
V_228 = F_66 ( V_175 ) ;
V_23 = V_6 -> V_12 -> V_22 ;
V_146 = V_23 -> V_23 ;
V_232 = F_91 ( V_146 , V_228 , V_231 , V_175 -> V_178 ) ;
if ( F_92 ( V_232 == 0 ) )
return - V_239 ;
V_236 = V_240 ;
V_204 = sizeof ( struct V_229 ) + sizeof ( struct V_200 ) ;
if ( V_232 == 1 ) {
struct V_200 * V_19 = ( void * ) V_230 -> V_241 ;
V_19 -> V_202 = F_82 ( F_87 ( V_146 , V_228 ) ) ;
V_19 -> V_203 = F_39 ( V_6 -> V_199 ) ;
V_19 -> V_204 = F_39 ( F_88 ( V_146 , V_228 ) ) ;
V_104 -> V_180 = 0 ;
goto V_242;
}
V_234 = ( void * ) V_230 -> V_241 ;
F_93 ( V_146 , V_104 -> V_152 ,
V_6 -> V_153 , V_154 ) ;
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_140 . V_201 = V_104 -> V_155 ;
V_140 . V_214 = V_104 -> V_151 ;
V_140 . V_215 = V_104 -> V_150 ;
V_222 = V_23 -> V_213 ? V_243 : V_223 ;
F_94 (scat, sg, count, i) {
if ( F_86 ( & V_140 , V_6 , V_217 , V_78 , V_222 ) ) {
T_5 V_197 ;
unsigned int V_198 ;
V_244:
V_217 = V_140 . V_219 ;
V_78 = V_140 . V_220 ;
V_197 = F_87 ( V_146 , V_217 ) ;
V_198 = F_88 ( V_146 , V_217 ) ;
V_198 -= ( V_140 . V_221 - V_197 ) ;
V_197 = V_140 . V_221 ;
V_222 = V_223 ;
F_81 ( & V_140 , V_197 , V_198 , V_6 -> V_199 ) ;
}
}
if ( V_222 == V_243 && F_83 ( & V_140 , V_6 ) )
goto V_244;
V_104 -> V_180 = V_140 . V_180 ;
if ( V_140 . V_206 == 1 ) {
struct V_200 * V_19 = ( void * ) V_230 -> V_241 ;
* V_19 = V_104 -> V_155 [ 0 ] ;
goto V_242;
}
if ( F_92 ( V_6 -> V_245 < V_140 . V_206 &&
! V_6 -> V_246 ) ) {
F_31 ( V_85 , V_6 -> V_86 ,
L_12 ) ;
return - V_239 ;
}
V_232 = F_95 ( V_140 . V_206 , V_6 -> V_245 ) ;
V_235 = V_140 . V_206 * sizeof ( struct V_200 ) ;
V_236 = V_247 ;
V_204 = sizeof( struct V_229 ) + sizeof ( struct V_233 ) ;
V_204 += V_232 * sizeof ( struct V_200 ) ;
memcpy ( V_234 -> V_248 , V_104 -> V_155 ,
V_232 * sizeof ( struct V_200 ) ) ;
V_234 -> V_249 . V_202 = F_82 ( V_104 -> V_152 ) ;
V_234 -> V_249 . V_203 = F_39 ( V_6 -> V_199 ) ;
V_234 -> V_249 . V_204 = F_39 ( V_235 ) ;
V_234 -> V_204 = F_39 ( V_140 . V_205 ) ;
if ( V_175 -> V_178 == V_154 )
V_230 -> V_250 = V_232 ;
else
V_230 -> V_251 = V_232 ;
F_96 ( V_146 , V_104 -> V_152 , V_235 ,
V_154 ) ;
V_242:
if ( V_175 -> V_178 == V_154 )
V_230 -> V_252 = V_236 << 4 ;
else
V_230 -> V_252 = V_236 ;
return V_204 ;
}
static void F_97 ( struct V_1 * V_6 , struct V_11 * V_17 ,
enum V_253 V_254 )
{
unsigned long V_181 ;
F_71 ( & V_6 -> V_139 , V_181 ) ;
F_79 ( & V_17 -> V_164 , & V_6 -> V_192 ) ;
if ( V_254 != V_255 )
++ V_6 -> V_183 ;
F_72 ( & V_6 -> V_139 , V_181 ) ;
}
static struct V_11 * F_98 ( struct V_1 * V_6 ,
enum V_253 V_254 )
{
T_4 V_256 = ( V_254 == V_257 ) ? 0 : V_258 ;
struct V_11 * V_17 ;
V_61 ( V_6 -> V_57 , V_6 ) ;
if ( F_99 ( & V_6 -> V_192 ) )
return NULL ;
if ( V_254 != V_255 ) {
if ( V_6 -> V_183 <= V_256 ) {
++ V_6 -> V_259 ;
return NULL ;
}
-- V_6 -> V_183 ;
}
V_17 = F_100 ( & V_6 -> V_192 , struct V_11 , V_164 ) ;
F_61 ( & V_17 -> V_164 ) ;
return V_17 ;
}
static int F_101 ( struct V_1 * V_6 ,
struct V_11 * V_17 , int V_204 )
{
struct V_260 V_164 ;
struct V_261 V_262 , * V_263 ;
V_164 . V_264 = V_17 -> V_21 ;
V_164 . V_265 = V_204 ;
V_164 . V_266 = V_6 -> V_266 ;
V_262 . V_267 = NULL ;
V_262 . V_268 = ( V_269 ) V_17 ;
V_262 . V_270 = & V_164 ;
V_262 . V_271 = 1 ;
V_262 . V_119 = V_272 ;
V_262 . V_273 = V_274 ;
return F_102 ( V_6 -> V_29 , & V_262 , & V_263 ) ;
}
static int F_103 ( struct V_1 * V_6 , struct V_11 * V_17 )
{
struct V_275 V_262 , * V_263 ;
struct V_260 V_164 ;
V_164 . V_264 = V_17 -> V_21 ;
V_164 . V_265 = V_17 -> V_13 ;
V_164 . V_266 = V_6 -> V_266 ;
V_262 . V_267 = NULL ;
V_262 . V_268 = ( V_269 ) V_17 ;
V_262 . V_270 = & V_164 ;
V_262 . V_271 = 1 ;
return F_104 ( V_6 -> V_29 , & V_262 , & V_263 ) ;
}
static void F_105 ( struct V_1 * V_6 , struct V_276 * V_277 )
{
struct V_147 * V_104 ;
struct V_174 * V_175 ;
unsigned long V_181 ;
if ( F_92 ( V_277 -> V_121 & V_278 ) ) {
F_71 ( & V_6 -> V_139 , V_181 ) ;
V_6 -> V_183 += F_106 ( V_277 -> V_182 ) ;
F_72 ( & V_6 -> V_139 , V_181 ) ;
V_6 -> V_279 = - 1 ;
if ( F_106 ( V_277 -> V_280 ) >= 4 )
V_6 -> V_279 = V_277 -> V_281 [ 3 ] ;
F_32 ( & V_6 -> V_282 ) ;
} else {
V_104 = & V_6 -> V_148 [ V_277 -> V_121 ] ;
V_175 = F_70 ( V_6 , V_104 , NULL ) ;
if ( ! V_175 ) {
F_31 ( V_85 , V_6 -> V_86 ,
L_13 ,
( unsigned long long ) V_277 -> V_121 ) ;
F_71 ( & V_6 -> V_139 , V_181 ) ;
V_6 -> V_183 += F_106 ( V_277 -> V_182 ) ;
F_72 ( & V_6 -> V_139 , V_181 ) ;
return;
}
V_175 -> V_185 = V_277 -> V_81 ;
if ( V_277 -> V_181 & V_283 ) {
memcpy ( V_175 -> V_284 , V_277 -> V_281 +
F_106 ( V_277 -> V_280 ) ,
F_89 ( int , F_106 ( V_277 -> V_285 ) ,
V_286 ) ) ;
}
if ( V_277 -> V_181 & ( V_287 | V_288 ) )
F_107 ( V_175 , F_106 ( V_277 -> V_289 ) ) ;
else if ( V_277 -> V_181 & ( V_290 | V_291 ) )
F_107 ( V_175 , F_106 ( V_277 -> V_292 ) ) ;
F_73 ( V_6 , V_104 , V_175 ,
F_106 ( V_277 -> V_182 ) ) ;
V_175 -> V_293 = NULL ;
V_175 -> V_187 ( V_175 ) ;
}
}
static int F_108 ( struct V_1 * V_6 , T_4 V_294 ,
void * V_277 , int V_204 )
{
struct V_145 * V_23 = V_6 -> V_12 -> V_22 -> V_23 ;
unsigned long V_181 ;
struct V_11 * V_17 ;
int V_60 ;
F_71 ( & V_6 -> V_139 , V_181 ) ;
V_6 -> V_183 += V_294 ;
V_17 = F_98 ( V_6 , V_255 ) ;
F_72 ( & V_6 -> V_139 , V_181 ) ;
if ( ! V_17 ) {
F_31 ( V_85 , V_6 -> V_86 , V_87
L_14 ) ;
return 1 ;
}
F_93 ( V_23 , V_17 -> V_21 , V_204 , V_154 ) ;
memcpy ( V_17 -> V_19 , V_277 , V_204 ) ;
F_96 ( V_23 , V_17 -> V_21 , V_204 , V_154 ) ;
V_60 = F_101 ( V_6 , V_17 , V_204 ) ;
if ( V_60 ) {
F_31 ( V_85 , V_6 -> V_86 , V_87
L_15 , V_60 ) ;
F_97 ( V_6 , V_17 , V_255 ) ;
}
return V_60 ;
}
static void F_109 ( struct V_1 * V_6 ,
struct V_295 * V_104 )
{
struct V_296 V_277 = {
. V_119 = V_297 ,
. V_121 = V_104 -> V_121 ,
} ;
T_4 V_298 = F_106 ( V_104 -> V_182 ) ;
if ( F_108 ( V_6 , V_298 , & V_277 , sizeof V_277 ) )
F_31 ( V_85 , V_6 -> V_86 , V_87
L_16 ) ;
}
static void F_110 ( struct V_1 * V_6 ,
struct V_299 * V_104 )
{
struct V_300 V_277 = {
. V_119 = V_301 ,
. V_121 = V_104 -> V_121 ,
} ;
T_4 V_298 = F_106 ( V_104 -> V_182 ) ;
F_31 ( V_85 , V_6 -> V_86 , V_87
L_17 , F_41 ( V_104 -> V_302 ) ) ;
if ( F_108 ( V_6 , V_298 , & V_277 , sizeof V_277 ) )
F_31 ( V_85 , V_6 -> V_86 , V_87
L_18 ) ;
}
static void F_111 ( struct V_1 * V_6 , struct V_303 * V_304 )
{
struct V_145 * V_23 = V_6 -> V_12 -> V_22 -> V_23 ;
struct V_11 * V_17 = (struct V_11 * ) ( V_269 ) V_304 -> V_268 ;
int V_305 ;
T_1 V_119 ;
F_93 ( V_23 , V_17 -> V_21 , V_6 -> V_306 ,
V_179 ) ;
V_119 = * ( T_1 * ) V_17 -> V_19 ;
if ( 0 ) {
F_31 ( V_85 , V_6 -> V_86 ,
V_87 L_19 , V_119 ) ;
F_112 ( V_85 , L_20 , V_307 , 8 , 1 ,
V_17 -> V_19 , V_304 -> V_308 , true ) ;
}
switch ( V_119 ) {
case V_309 :
F_105 ( V_6 , V_17 -> V_19 ) ;
break;
case V_310 :
F_109 ( V_6 , V_17 -> V_19 ) ;
break;
case V_311 :
F_110 ( V_6 , V_17 -> V_19 ) ;
break;
case V_312 :
F_31 ( V_99 , V_6 -> V_86 ,
V_87 L_21 ) ;
break;
default:
F_31 ( V_99 , V_6 -> V_86 ,
V_87 L_22 , V_119 ) ;
break;
}
F_96 ( V_23 , V_17 -> V_21 , V_6 -> V_306 ,
V_179 ) ;
V_305 = F_103 ( V_6 , V_17 ) ;
if ( V_305 != 0 )
F_31 ( V_85 , V_6 -> V_86 ,
V_87 L_23 , V_305 ) ;
}
static void F_113 ( enum V_313 V_314 ,
enum V_315 V_316 ,
struct V_1 * V_6 )
{
if ( V_6 -> V_144 && ! V_6 -> V_169 ) {
F_31 ( V_85 , V_6 -> V_86 ,
V_87 L_24 ,
V_316 & V_317 ? L_25 : L_26 ,
V_314 ) ;
}
V_6 -> V_169 = true ;
}
static void V_58 ( struct V_55 * V_318 , void * V_84 )
{
struct V_1 * V_6 = V_84 ;
struct V_303 V_304 ;
F_25 ( V_318 , V_64 ) ;
while ( F_114 ( V_318 , 1 , & V_304 ) > 0 ) {
if ( F_115 ( V_304 . V_81 == V_319 ) ) {
F_111 ( V_6 , & V_304 ) ;
} else {
F_113 ( V_304 . V_81 , V_304 . V_119 , V_6 ) ;
}
}
}
static void V_61 ( struct V_55 * V_318 , void * V_84 )
{
struct V_1 * V_6 = V_84 ;
struct V_303 V_304 ;
struct V_11 * V_17 ;
while ( F_114 ( V_318 , 1 , & V_304 ) > 0 ) {
if ( F_115 ( V_304 . V_81 == V_319 ) ) {
V_17 = (struct V_11 * ) ( V_269 ) V_304 . V_268 ;
F_79 ( & V_17 -> V_164 , & V_6 -> V_192 ) ;
} else {
F_113 ( V_304 . V_81 , V_304 . V_119 , V_6 ) ;
}
}
}
static int F_116 ( struct V_2 * V_156 , struct V_174 * V_175 )
{
struct V_1 * V_6 = F_1 ( V_156 ) ;
struct V_147 * V_104 ;
struct V_11 * V_17 ;
struct V_229 * V_230 ;
struct V_145 * V_23 ;
unsigned long V_181 ;
int V_204 ;
F_71 ( & V_6 -> V_139 , V_181 ) ;
V_17 = F_98 ( V_6 , V_320 ) ;
if ( ! V_17 )
goto V_321;
V_104 = F_100 ( & V_6 -> V_184 , struct V_147 , V_164 ) ;
F_61 ( & V_104 -> V_164 ) ;
F_72 ( & V_6 -> V_139 , V_181 ) ;
V_23 = V_6 -> V_12 -> V_22 -> V_23 ;
F_93 ( V_23 , V_17 -> V_21 , V_6 -> V_123 ,
V_154 ) ;
V_175 -> V_185 = 0 ;
V_175 -> V_293 = ( void * ) V_104 ;
V_230 = V_17 -> V_19 ;
memset ( V_230 , 0 , sizeof *V_230 ) ;
V_230 -> V_119 = V_322 ;
V_230 -> V_302 = F_82 ( ( T_7 ) V_175 -> V_323 -> V_302 << 48 ) ;
V_230 -> V_121 = V_104 -> V_324 ;
memcpy ( V_230 -> V_325 , V_175 -> V_326 , V_175 -> V_327 ) ;
V_104 -> V_175 = V_175 ;
V_104 -> V_230 = V_17 ;
V_204 = F_90 ( V_175 , V_6 , V_104 ) ;
if ( V_204 < 0 ) {
F_31 ( V_85 , V_6 -> V_86 ,
V_87 L_27 ) ;
goto V_328;
}
F_96 ( V_23 , V_17 -> V_21 , V_6 -> V_123 ,
V_154 ) ;
if ( F_101 ( V_6 , V_17 , V_204 ) ) {
F_31 ( V_85 , V_6 -> V_86 , V_87 L_28 ) ;
goto V_329;
}
return 0 ;
V_329:
F_65 ( V_175 , V_6 , V_104 ) ;
V_328:
F_97 ( V_6 , V_17 , V_320 ) ;
F_71 ( & V_6 -> V_139 , V_181 ) ;
F_79 ( & V_104 -> V_164 , & V_6 -> V_184 ) ;
V_321:
F_72 ( & V_6 -> V_139 , V_181 ) ;
return V_330 ;
}
static int F_117 ( struct V_1 * V_6 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_59 ; ++ V_78 ) {
V_6 -> V_79 [ V_78 ] = F_4 ( V_6 -> V_12 ,
V_6 -> V_306 ,
V_33 , V_179 ) ;
if ( ! V_6 -> V_79 [ V_78 ] )
goto V_60;
}
for ( V_78 = 0 ; V_78 < V_62 ; ++ V_78 ) {
V_6 -> V_80 [ V_78 ] = F_4 ( V_6 -> V_12 ,
V_6 -> V_123 ,
V_33 , V_154 ) ;
if ( ! V_6 -> V_80 [ V_78 ] )
goto V_60;
F_79 ( & V_6 -> V_80 [ V_78 ] -> V_164 , & V_6 -> V_192 ) ;
}
return 0 ;
V_60:
for ( V_78 = 0 ; V_78 < V_59 ; ++ V_78 ) {
F_10 ( V_6 -> V_12 , V_6 -> V_79 [ V_78 ] ) ;
V_6 -> V_79 [ V_78 ] = NULL ;
}
for ( V_78 = 0 ; V_78 < V_62 ; ++ V_78 ) {
F_10 ( V_6 -> V_12 , V_6 -> V_80 [ V_78 ] ) ;
V_6 -> V_80 [ V_78 ] = NULL ;
}
return - V_34 ;
}
static T_8 F_118 ( struct V_30 * V_331 , int V_332 )
{
T_9 V_333 , V_334 ;
T_8 V_335 ;
F_54 ( ( V_332 & ( V_336 | V_337 ) ) !=
( V_336 | V_337 ) ) ;
V_333 = 4096 * ( 1ULL << V_331 -> V_338 ) ;
V_334 = V_331 -> V_339 * 4 * V_333 ;
F_119 ( V_334 , V_340 ) ;
V_335 = F_120 ( V_334 + 1000 ) ;
return V_335 ;
}
static void F_121 ( struct V_49 * V_52 ,
struct V_341 * V_342 ,
struct V_1 * V_6 )
{
struct V_30 * V_331 = NULL ;
int V_332 = 0 ;
int V_32 ;
int V_78 ;
if ( V_342 -> V_119 == V_343 ) {
V_6 -> V_306 = F_106 ( V_342 -> V_306 ) ;
V_6 -> V_183 = F_106 ( V_342 -> V_182 ) ;
V_6 -> V_86 -> V_344
= F_95 ( V_6 -> V_183 - V_258 ,
V_6 -> V_86 -> V_344 ) ;
} else {
F_31 ( V_99 , V_6 -> V_86 ,
V_87 L_29 , V_342 -> V_119 ) ;
V_32 = - V_173 ;
goto error;
}
if ( ! V_6 -> V_79 [ 0 ] ) {
V_32 = F_117 ( V_6 ) ;
if ( V_32 )
goto error;
}
V_32 = - V_34 ;
V_331 = F_5 ( sizeof *V_331 , V_33 ) ;
if ( ! V_331 )
goto error;
V_331 -> V_39 = V_345 ;
V_32 = F_122 ( V_52 , V_331 , & V_332 ) ;
if ( V_32 )
goto V_346;
V_32 = F_17 ( V_6 -> V_29 , V_331 , V_332 ) ;
if ( V_32 )
goto V_346;
for ( V_78 = 0 ; V_78 < V_59 ; V_78 ++ ) {
struct V_11 * V_17 = V_6 -> V_79 [ V_78 ] ;
V_32 = F_103 ( V_6 , V_17 ) ;
if ( V_32 )
goto V_346;
}
V_331 -> V_39 = V_347 ;
V_32 = F_122 ( V_52 , V_331 , & V_332 ) ;
if ( V_32 )
goto V_346;
V_6 -> V_335 = F_118 ( V_331 , V_332 ) ;
V_32 = F_17 ( V_6 -> V_29 , V_331 , V_332 ) ;
if ( V_32 )
goto V_346;
V_32 = F_123 ( V_52 , NULL , 0 ) ;
V_346:
F_9 ( V_331 ) ;
error:
V_6 -> V_81 = V_32 ;
}
static void F_124 ( struct V_49 * V_52 ,
struct V_348 * V_26 ,
struct V_1 * V_6 )
{
struct V_2 * V_156 = V_6 -> V_86 ;
struct V_349 * V_350 ;
int V_119 ;
switch ( V_26 -> V_101 . V_351 . V_352 ) {
case V_353 :
V_350 = V_26 -> V_101 . V_351 . V_354 ;
V_6 -> V_36 . V_355 = V_350 -> V_356 ;
V_6 -> V_36 . V_37 = V_350 -> V_357 ;
V_52 -> V_358 = F_106 ( V_350 -> V_359 ) & 0x00ffffff ;
memcpy ( V_6 -> V_36 . V_360 . V_361 , V_350 -> V_362 , 16 ) ;
V_6 -> V_81 = V_6 -> V_36 . V_355 ?
V_171 : V_170 ;
break;
case V_363 :
if ( F_3 ( V_6 ) ) {
memcpy ( V_6 -> V_36 . V_360 . V_361 ,
V_26 -> V_101 . V_351 . V_354 , 16 ) ;
F_31 ( V_136 , V_156 ,
V_87 L_30 ,
( unsigned long long ) F_41 ( V_6 -> V_36 . V_360 . V_131 . V_364 ) ,
( unsigned long long ) F_41 ( V_6 -> V_36 . V_360 . V_131 . V_132 ) ) ;
V_6 -> V_81 = V_170 ;
} else {
F_31 ( V_99 , V_156 ,
L_31 ) ;
V_6 -> V_81 = - V_173 ;
}
break;
case V_365 :
F_31 ( V_99 , V_156 ,
L_32 ) ;
V_6 -> V_81 = - V_173 ;
break;
case V_366 :
V_119 = * ( T_1 * ) V_26 -> V_109 ;
if ( V_119 == V_367 ) {
struct V_368 * V_369 = V_26 -> V_109 ;
T_6 V_352 = F_106 ( V_369 -> V_352 ) ;
if ( V_352 == V_370 )
F_31 ( V_99 , V_156 ,
V_87 L_33 ) ;
else
F_31 ( V_99 , V_156 ,
V_87 L_34 , V_352 ) ;
} else
F_31 ( V_99 , V_156 ,
L_35
L_36 , V_119 ) ;
V_6 -> V_81 = - V_173 ;
break;
case V_371 :
F_31 ( V_99 , V_156 , L_37 ) ;
V_6 -> V_81 = V_172 ;
break;
default:
F_31 ( V_99 , V_156 , L_38 ,
V_26 -> V_101 . V_351 . V_352 ) ;
V_6 -> V_81 = - V_173 ;
}
}
static int V_51 ( struct V_49 * V_52 , struct V_348 * V_26 )
{
struct V_1 * V_6 = V_52 -> V_27 ;
int V_372 = 0 ;
switch ( V_26 -> V_26 ) {
case V_373 :
F_31 ( V_136 , V_6 -> V_86 ,
V_87 L_39 ) ;
V_372 = 1 ;
V_6 -> V_81 = - V_173 ;
break;
case V_374 :
V_372 = 1 ;
F_121 ( V_52 , V_26 -> V_109 , V_6 ) ;
break;
case V_375 :
F_31 ( V_136 , V_6 -> V_86 , V_87 L_40 ) ;
V_372 = 1 ;
F_124 ( V_52 , V_26 , V_6 ) ;
break;
case V_376 :
F_31 ( V_99 , V_6 -> V_86 ,
V_87 L_41 ) ;
F_47 ( V_6 , false ) ;
if ( F_125 ( V_52 , NULL , 0 ) )
F_31 ( V_85 , V_6 -> V_86 ,
V_87 L_42 ) ;
break;
case V_377 :
F_31 ( V_85 , V_6 -> V_86 ,
V_87 L_43 ) ;
V_6 -> V_81 = 0 ;
break;
case V_378 :
case V_379 :
case V_380 :
break;
default:
F_31 ( V_99 , V_6 -> V_86 ,
V_87 L_44 , V_26 -> V_26 ) ;
break;
}
if ( V_372 )
F_32 ( & V_6 -> V_88 ) ;
return 0 ;
}
static int F_126 ( struct V_1 * V_6 ,
T_7 V_381 , unsigned int V_302 , T_1 V_382 )
{
struct V_145 * V_23 = V_6 -> V_12 -> V_22 -> V_23 ;
struct V_11 * V_17 ;
struct V_383 * V_384 ;
F_34 ( & V_6 -> V_282 ) ;
F_44 ( & V_6 -> V_139 ) ;
V_17 = F_98 ( V_6 , V_257 ) ;
F_45 ( & V_6 -> V_139 ) ;
if ( ! V_17 )
return - 1 ;
F_93 ( V_23 , V_17 -> V_21 , sizeof *V_384 ,
V_154 ) ;
V_384 = V_17 -> V_19 ;
memset ( V_384 , 0 , sizeof *V_384 ) ;
V_384 -> V_119 = V_385 ;
V_384 -> V_302 = F_82 ( ( T_7 ) V_302 << 48 ) ;
V_384 -> V_121 = V_381 | V_278 ;
V_384 -> V_386 = V_382 ;
V_384 -> V_387 = V_381 ;
F_96 ( V_23 , V_17 -> V_21 , sizeof *V_384 ,
V_154 ) ;
if ( F_101 ( V_6 , V_17 , sizeof *V_384 ) ) {
F_97 ( V_6 , V_17 , V_257 ) ;
return - 1 ;
}
if ( ! F_127 ( & V_6 -> V_282 ,
F_120 ( V_388 ) ) )
return - 1 ;
return 0 ;
}
static int F_128 ( struct V_174 * V_175 )
{
struct V_1 * V_6 = F_1 ( V_175 -> V_323 -> V_3 ) ;
struct V_147 * V_104 = (struct V_147 * ) V_175 -> V_293 ;
F_31 ( V_85 , V_6 -> V_86 , L_45 ) ;
if ( ! V_104 || V_6 -> V_169 || ! F_70 ( V_6 , V_104 , V_175 ) )
return V_389 ;
F_126 ( V_6 , V_104 -> V_324 , V_175 -> V_323 -> V_302 ,
V_390 ) ;
F_73 ( V_6 , V_104 , V_175 , 0 ) ;
V_175 -> V_185 = V_391 << 16 ;
V_175 -> V_187 ( V_175 ) ;
return V_392 ;
}
static int F_129 ( struct V_174 * V_175 )
{
struct V_1 * V_6 = F_1 ( V_175 -> V_323 -> V_3 ) ;
int V_78 ;
F_31 ( V_85 , V_6 -> V_86 , L_46 ) ;
if ( V_6 -> V_169 )
return V_389 ;
if ( F_126 ( V_6 , V_393 , V_175 -> V_323 -> V_302 ,
V_394 ) )
return V_389 ;
if ( V_6 -> V_279 )
return V_389 ;
for ( V_78 = 0 ; V_78 < V_149 ; ++ V_78 ) {
struct V_147 * V_104 = & V_6 -> V_148 [ V_78 ] ;
if ( V_104 -> V_175 && V_104 -> V_175 -> V_323 == V_175 -> V_323 )
F_75 ( V_6 , V_104 ) ;
}
return V_392 ;
}
static int F_130 ( struct V_174 * V_175 )
{
struct V_1 * V_6 = F_1 ( V_175 -> V_323 -> V_3 ) ;
int V_32 = V_389 ;
F_31 ( V_85 , V_6 -> V_86 , V_87 L_47 ) ;
if ( ! F_76 ( V_6 ) )
V_32 = V_392 ;
return V_32 ;
}
static int F_131 ( struct V_395 * V_396 )
{
struct V_2 * V_156 = V_396 -> V_3 ;
struct V_1 * V_6 = F_1 ( V_156 ) ;
struct V_397 * V_398 = V_396 -> V_397 ;
unsigned long V_338 ;
if ( V_396 -> type == V_399 ) {
V_338 = F_132 ( unsigned , 30 * V_400 , V_6 -> V_335 ) ;
F_133 ( V_398 , V_338 ) ;
}
return 0 ;
}
static T_10 F_134 ( struct V_323 * V_23 , struct V_157 * V_31 ,
char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_48 ,
( unsigned long long ) F_41 ( V_6 -> V_135 ) ) ;
}
static T_10 F_136 ( struct V_323 * V_23 , struct V_157 * V_31 ,
char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_48 ,
( unsigned long long ) F_41 ( V_6 -> V_10 ) ) ;
}
static T_10 F_137 ( struct V_323 * V_23 ,
struct V_157 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_48 ,
( unsigned long long ) F_41 ( V_6 -> V_107 ) ) ;
}
static T_10 F_138 ( struct V_323 * V_23 , struct V_157 * V_31 ,
char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_49 , F_16 ( V_6 -> V_36 . V_37 ) ) ;
}
static T_10 F_139 ( struct V_323 * V_23 , struct V_157 * V_31 ,
char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_50 , V_6 -> V_36 . V_360 . V_361 ) ;
}
static T_10 F_140 ( struct V_323 * V_23 ,
struct V_157 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_50 , V_6 -> V_401 ) ;
}
static T_10 F_141 ( struct V_323 * V_23 ,
struct V_157 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_51 , V_6 -> V_183 ) ;
}
static T_10 F_142 ( struct V_323 * V_23 ,
struct V_157 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_51 , V_6 -> V_259 ) ;
}
static T_10 F_143 ( struct V_323 * V_23 ,
struct V_157 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_51 , V_6 -> V_12 -> V_35 ) ;
}
static T_10 F_144 ( struct V_323 * V_23 ,
struct V_157 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_52 , V_6 -> V_12 -> V_22 -> V_23 -> V_402 ) ;
}
static T_10 F_145 ( struct V_323 * V_23 ,
struct V_157 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_53 , V_6 -> V_245 ) ;
}
static T_10 F_146 ( struct V_323 * V_23 ,
struct V_157 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_52 , V_6 -> V_246 ? L_54 : L_55 ) ;
}
static int F_147 ( struct V_12 * V_3 , struct V_1 * V_6 )
{
struct V_403 V_404 ;
struct V_165 * V_166 ;
sprintf ( V_6 -> V_5 , L_56 ,
( unsigned long long ) F_41 ( V_6 -> V_135 ) ) ;
if ( F_148 ( V_6 -> V_86 , V_3 -> V_22 -> V_23 -> V_405 ) )
return - V_406 ;
memcpy ( V_404 . V_407 , & V_6 -> V_135 , 8 ) ;
memcpy ( V_404 . V_407 + 8 , & V_6 -> V_10 , 8 ) ;
V_404 . V_408 = V_409 ;
V_166 = F_149 ( V_6 -> V_86 , & V_404 ) ;
if ( F_20 ( V_166 ) ) {
F_56 ( V_6 -> V_86 ) ;
return F_21 ( V_166 ) ;
}
V_166 -> V_167 = V_6 ;
F_60 ( & V_3 -> V_163 ) ;
F_74 ( & V_6 -> V_164 , & V_3 -> V_410 ) ;
F_62 ( & V_3 -> V_163 ) ;
V_6 -> V_140 = V_188 ;
V_6 -> V_144 = false ;
F_150 ( & V_6 -> V_86 -> V_190 ,
0 , V_6 -> V_411 , V_412 , 0 ) ;
return 0 ;
}
static void F_151 ( struct V_323 * V_23 )
{
struct V_12 * V_3 =
F_59 ( V_23 , struct V_12 , V_23 ) ;
F_32 ( & V_3 -> V_413 ) ;
}
static int F_152 ( const char * V_19 , struct V_1 * V_6 )
{
char * V_414 , * V_415 ;
char * V_416 ;
char V_360 [ 3 ] ;
T_11 args [ V_417 ] ;
int V_418 = 0 ;
int V_419 ;
int V_32 = - V_238 ;
int V_78 ;
V_414 = F_153 ( V_19 , V_33 ) ;
if ( ! V_414 )
return - V_34 ;
V_415 = V_414 ;
while ( ( V_416 = F_154 ( & V_415 , L_57 ) ) != NULL ) {
if ( ! * V_416 )
continue;
V_419 = F_155 ( V_416 , V_420 , args ) ;
V_418 |= V_419 ;
switch ( V_419 ) {
case V_421 :
V_416 = F_156 ( args ) ;
if ( ! V_416 ) {
V_32 = - V_34 ;
goto V_18;
}
V_6 -> V_135 = F_82 ( F_157 ( V_416 , NULL , 16 ) ) ;
F_9 ( V_416 ) ;
break;
case V_422 :
V_416 = F_156 ( args ) ;
if ( ! V_416 ) {
V_32 = - V_34 ;
goto V_18;
}
V_6 -> V_10 = F_82 ( F_157 ( V_416 , NULL , 16 ) ) ;
F_9 ( V_416 ) ;
break;
case V_423 :
V_416 = F_156 ( args ) ;
if ( ! V_416 ) {
V_32 = - V_34 ;
goto V_18;
}
if ( strlen ( V_416 ) != 32 ) {
F_158 ( L_58 , V_416 ) ;
F_9 ( V_416 ) ;
goto V_18;
}
for ( V_78 = 0 ; V_78 < 16 ; ++ V_78 ) {
F_159 ( V_360 , V_416 + V_78 * 2 , 3 ) ;
V_6 -> V_36 . V_360 . V_361 [ V_78 ] = F_160 ( V_360 , NULL , 16 ) ;
}
F_9 ( V_416 ) ;
memcpy ( V_6 -> V_401 , V_6 -> V_36 . V_360 . V_361 , 16 ) ;
break;
case V_424 :
if ( F_161 ( args , & V_419 ) ) {
F_158 ( L_59 , V_416 ) ;
goto V_18;
}
V_6 -> V_36 . V_37 = F_40 ( V_419 ) ;
break;
case V_425 :
V_416 = F_156 ( args ) ;
if ( ! V_416 ) {
V_32 = - V_34 ;
goto V_18;
}
V_6 -> V_107 = F_82 ( F_157 ( V_416 , NULL , 16 ) ) ;
V_6 -> V_36 . V_107 = V_6 -> V_107 ;
F_9 ( V_416 ) ;
break;
case V_426 :
if ( F_162 ( args , & V_419 ) ) {
F_158 ( L_60 , V_416 ) ;
goto V_18;
}
V_6 -> V_86 -> V_427 = V_419 ;
break;
case V_428 :
if ( F_162 ( args , & V_419 ) ) {
F_158 ( L_61 ,
V_416 ) ;
goto V_18;
}
V_6 -> V_86 -> V_429 = F_95 ( V_419 , V_149 ) ;
break;
case V_430 :
if ( F_161 ( args , & V_419 ) ) {
F_158 ( L_62 , V_416 ) ;
goto V_18;
}
if ( V_419 != V_128 &&
V_419 != V_431 ) {
F_158 ( L_63 ,
V_419 , V_128 ,
V_431 ) ;
goto V_18;
}
V_6 -> V_127 = V_419 ;
break;
case V_432 :
V_416 = F_156 ( args ) ;
if ( ! V_416 ) {
V_32 = - V_34 ;
goto V_18;
}
V_6 -> V_133 = F_82 ( F_157 ( V_416 , NULL , 16 ) ) ;
F_9 ( V_416 ) ;
break;
case V_433 :
if ( F_162 ( args , & V_419 ) || V_419 < 1 || V_419 > 255 ) {
F_158 ( L_64 ,
V_416 ) ;
goto V_18;
}
V_6 -> V_245 = V_419 ;
break;
case V_434 :
if ( F_162 ( args , & V_419 ) ) {
F_158 ( L_65 , V_416 ) ;
goto V_18;
}
V_6 -> V_246 = ! ! V_419 ;
break;
case V_435 :
if ( F_162 ( args , & V_419 ) || V_419 < 1 ||
V_419 > V_436 ) {
F_158 ( L_66 ,
V_416 ) ;
goto V_18;
}
V_6 -> V_437 = V_419 ;
break;
default:
F_158 ( L_67 ,
V_416 ) ;
goto V_18;
}
}
if ( ( V_418 & V_438 ) == V_438 )
V_32 = 0 ;
else
for ( V_78 = 0 ; V_78 < F_163 ( V_420 ) ; ++ V_78 )
if ( ( V_420 [ V_78 ] . V_419 & V_438 ) &&
! ( V_420 [ V_78 ] . V_419 & V_418 ) )
F_158 ( L_68 ,
V_420 [ V_78 ] . V_439 ) ;
V_18:
F_9 ( V_414 ) ;
return V_32 ;
}
static T_10 F_164 ( struct V_323 * V_23 ,
struct V_157 * V_31 ,
const char * V_19 , T_2 V_232 )
{
struct V_12 * V_3 =
F_59 ( V_23 , struct V_12 , V_23 ) ;
struct V_2 * V_440 ;
struct V_1 * V_6 ;
struct V_145 * V_146 = V_3 -> V_22 -> V_23 ;
T_5 V_197 ;
int V_78 , V_32 ;
V_440 = F_165 ( & V_441 ,
sizeof ( struct V_1 ) ) ;
if ( ! V_440 )
return - V_34 ;
V_440 -> V_442 = V_443 ;
V_440 -> V_444 = 0 ;
V_440 -> V_445 = 1 ;
V_440 -> V_446 = V_447 ;
V_440 -> V_448 = sizeof ( (struct V_229 * ) ( void * ) 0L ) -> V_325 ;
V_6 = F_1 ( V_440 ) ;
V_6 -> V_127 = V_431 ;
V_6 -> V_86 = V_440 ;
V_6 -> V_12 = V_3 ;
V_6 -> V_266 = V_3 -> V_22 -> V_449 -> V_266 ;
V_6 -> V_199 = V_3 -> V_22 -> V_449 -> V_199 ;
V_6 -> V_245 = V_450 ;
V_6 -> V_437 = V_451 ? : V_450 ;
V_6 -> V_246 = V_246 ;
V_32 = F_152 ( V_19 , V_6 ) ;
if ( V_32 )
goto V_60;
if ( ! V_3 -> V_22 -> V_213 && ! V_6 -> V_246 &&
V_6 -> V_245 < V_6 -> V_437 ) {
F_158 ( L_69 ) ;
V_6 -> V_437 = V_6 -> V_245 ;
}
V_440 -> V_437 = V_6 -> V_437 ;
V_6 -> V_153 = V_6 -> V_437 *
sizeof ( struct V_200 ) ;
V_6 -> V_123 = sizeof ( struct V_229 ) +
sizeof ( struct V_233 ) +
V_6 -> V_245 * sizeof ( struct V_200 ) ;
F_166 ( & V_6 -> V_143 , F_58 ) ;
F_167 ( & V_6 -> V_139 ) ;
F_78 ( & V_6 -> V_192 ) ;
F_78 ( & V_6 -> V_184 ) ;
for ( V_78 = 0 ; V_78 < V_149 ; ++ V_78 ) {
struct V_147 * V_104 = & V_6 -> V_148 [ V_78 ] ;
V_104 -> V_150 = F_5 ( V_6 -> V_245 * sizeof ( void * ) ,
V_33 ) ;
V_104 -> V_151 = F_5 ( V_226 * sizeof ( void * ) ,
V_33 ) ;
V_104 -> V_155 = F_5 ( V_6 -> V_153 , V_33 ) ;
if ( ! V_104 -> V_150 || ! V_104 -> V_151 || ! V_104 -> V_155 )
goto V_452;
V_197 = F_7 ( V_146 , V_104 -> V_155 ,
V_6 -> V_153 ,
V_154 ) ;
if ( F_8 ( V_146 , V_197 ) )
goto V_452;
V_104 -> V_152 = V_197 ;
V_104 -> V_324 = V_78 ;
F_74 ( & V_104 -> V_164 , & V_6 -> V_184 ) ;
}
F_168 ( V_146 , V_3 -> V_35 , 0 , & V_6 -> V_36 . V_130 ) ;
F_31 ( V_136 , V_6 -> V_86 , V_87
L_70
L_71 ,
( unsigned long long ) F_41 ( V_6 -> V_135 ) ,
( unsigned long long ) F_41 ( V_6 -> V_10 ) ,
F_16 ( V_6 -> V_36 . V_37 ) ,
( unsigned long long ) F_41 ( V_6 -> V_107 ) ,
V_6 -> V_36 . V_360 . V_361 ) ;
V_32 = F_23 ( V_6 ) ;
if ( V_32 )
goto V_452;
V_32 = F_18 ( V_6 ) ;
if ( V_32 )
goto V_453;
V_32 = F_64 ( V_6 ) ;
if ( V_32 ) {
F_31 ( V_85 , V_6 -> V_86 ,
V_87 L_72 ) ;
goto V_454;
}
V_32 = F_147 ( V_3 , V_6 ) ;
if ( V_32 )
goto V_455;
return V_232 ;
V_455:
F_48 ( V_6 ) ;
V_454:
F_22 ( V_6 -> V_52 ) ;
V_453:
F_29 ( V_6 ) ;
V_452:
F_50 ( V_6 ) ;
V_60:
F_57 ( V_440 ) ;
return V_32 ;
}
static T_10 F_169 ( struct V_323 * V_23 , struct V_157 * V_31 ,
char * V_19 )
{
struct V_12 * V_3 = F_59 ( V_23 , struct V_12 , V_23 ) ;
return sprintf ( V_19 , L_52 , V_3 -> V_22 -> V_23 -> V_402 ) ;
}
static T_10 F_170 ( struct V_323 * V_23 , struct V_157 * V_31 ,
char * V_19 )
{
struct V_12 * V_3 = F_59 ( V_23 , struct V_12 , V_23 ) ;
return sprintf ( V_19 , L_51 , V_3 -> V_35 ) ;
}
static struct V_12 * F_171 ( struct V_207 * V_323 , T_1 V_35 )
{
struct V_12 * V_3 ;
V_3 = F_6 ( sizeof *V_3 , V_33 ) ;
if ( ! V_3 )
return NULL ;
F_78 ( & V_3 -> V_410 ) ;
F_167 ( & V_3 -> V_163 ) ;
F_34 ( & V_3 -> V_413 ) ;
V_3 -> V_22 = V_323 ;
V_3 -> V_35 = V_35 ;
V_3 -> V_23 . V_456 = & V_457 ;
V_3 -> V_23 . V_458 = V_323 -> V_23 -> V_405 ;
F_172 ( & V_3 -> V_23 , L_73 , V_323 -> V_23 -> V_402 , V_35 ) ;
if ( F_173 ( & V_3 -> V_23 ) )
goto V_459;
if ( F_174 ( & V_3 -> V_23 , & V_460 ) )
goto V_461;
if ( F_174 ( & V_3 -> V_23 , & V_462 ) )
goto V_461;
if ( F_174 ( & V_3 -> V_23 , & V_463 ) )
goto V_461;
return V_3 ;
V_461:
F_175 ( & V_3 -> V_23 ) ;
V_459:
F_9 ( V_3 ) ;
return NULL ;
}
static void F_176 ( struct V_145 * V_323 )
{
struct V_207 * V_22 ;
struct V_464 * V_465 ;
struct V_466 V_467 ;
struct V_12 * V_3 ;
int V_468 , V_469 , V_470 , V_471 , V_416 ;
V_465 = F_5 ( sizeof *V_465 , V_33 ) ;
if ( ! V_465 )
return;
if ( F_177 ( V_323 , V_465 ) ) {
F_158 ( L_74 , V_323 -> V_402 ) ;
goto V_472;
}
V_22 = F_5 ( sizeof *V_22 , V_33 ) ;
if ( ! V_22 )
goto V_472;
V_469 = F_178 ( 12 , F_179 ( V_465 -> V_473 ) - 1 ) ;
V_22 -> V_227 = 1 << V_469 ;
V_22 -> V_224 = ~ ( ( T_7 ) V_22 -> V_227 - 1 ) ;
V_22 -> V_225 = V_22 -> V_227 * V_226 ;
F_78 ( & V_22 -> V_474 ) ;
V_22 -> V_23 = V_323 ;
V_22 -> V_75 = F_180 ( V_323 ) ;
if ( F_20 ( V_22 -> V_75 ) )
goto V_475;
V_22 -> V_449 = F_181 ( V_22 -> V_75 ,
V_476 |
V_42 |
V_43 ) ;
if ( F_20 ( V_22 -> V_449 ) )
goto V_477;
for ( V_468 = V_226 ;
V_468 >= V_478 ;
V_468 /= 2 , V_22 -> V_225 /= 2 ) {
memset ( & V_467 , 0 , sizeof V_467 ) ;
V_467 . V_479 = V_480 ;
V_467 . V_481 = V_482 ;
V_467 . V_483 = 1 ;
V_467 . V_468 = V_468 ;
V_467 . V_484 = V_469 ;
V_467 . V_485 = ( V_476 |
V_43 |
V_42 ) ;
V_22 -> V_213 = F_182 ( V_22 -> V_75 , & V_467 ) ;
if ( ! F_20 ( V_22 -> V_213 ) )
break;
}
if ( F_20 ( V_22 -> V_213 ) )
V_22 -> V_213 = NULL ;
if ( V_323 -> V_486 == V_487 ) {
V_470 = 0 ;
V_471 = 0 ;
} else {
V_470 = 1 ;
V_471 = V_323 -> V_488 ;
}
for ( V_416 = V_470 ; V_416 <= V_471 ; ++ V_416 ) {
V_3 = F_171 ( V_22 , V_416 ) ;
if ( V_3 )
F_74 ( & V_3 -> V_164 , & V_22 -> V_474 ) ;
}
F_183 ( V_323 , & V_489 , V_22 ) ;
goto V_472;
V_477:
F_184 ( V_22 -> V_75 ) ;
V_475:
F_9 ( V_22 ) ;
V_472:
F_9 ( V_465 ) ;
}
static void F_185 ( struct V_145 * V_323 )
{
struct V_207 * V_22 ;
struct V_12 * V_3 , * V_490 ;
struct V_1 * V_6 ;
V_22 = F_186 ( V_323 , & V_489 ) ;
F_187 (host, tmp_host, &srp_dev->dev_list, list) {
F_175 ( & V_3 -> V_23 ) ;
F_36 ( & V_3 -> V_413 ) ;
F_60 ( & V_3 -> V_163 ) ;
F_188 (target, &host->target_list, list)
F_43 ( V_6 ) ;
F_62 ( & V_3 -> V_163 ) ;
F_189 ( V_142 ) ;
F_9 ( V_3 ) ;
}
if ( V_22 -> V_213 )
F_190 ( V_22 -> V_213 ) ;
F_191 ( V_22 -> V_449 ) ;
F_184 ( V_22 -> V_75 ) ;
F_9 ( V_22 ) ;
}
static int T_12 F_192 ( void )
{
int V_32 ;
F_193 ( F_194 ( struct V_303 , V_268 ) < sizeof( void * ) ) ;
if ( V_491 ) {
F_158 ( L_75 ) ;
if ( ! V_450 )
V_450 = V_491 ;
}
if ( ! V_450 )
V_450 = V_492 ;
if ( V_450 > 255 ) {
F_158 ( L_76 ) ;
V_450 = 255 ;
}
if ( ! V_451 )
V_451 = V_450 ;
else if ( V_451 < V_450 ) {
F_158 ( L_77 ,
V_450 ) ;
V_451 = V_450 ;
}
V_443 =
F_195 ( & V_493 ) ;
if ( ! V_443 )
return - V_34 ;
V_32 = F_196 ( & V_457 ) ;
if ( V_32 ) {
F_197 ( L_78 ) ;
F_198 ( V_443 ) ;
return V_32 ;
}
F_199 ( & V_91 ) ;
V_32 = F_200 ( & V_489 ) ;
if ( V_32 ) {
F_197 ( L_79 ) ;
F_198 ( V_443 ) ;
F_201 ( & V_91 ) ;
F_202 ( & V_457 ) ;
return V_32 ;
}
return 0 ;
}
static void T_13 F_203 ( void )
{
F_204 ( & V_489 ) ;
F_201 ( & V_91 ) ;
F_202 ( & V_457 ) ;
F_198 ( V_443 ) ;
}
