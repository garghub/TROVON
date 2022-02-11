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
V_58 , NULL , V_6 , V_59 ,
V_6 -> V_60 ) ;
if ( F_20 ( V_56 ) ) {
V_32 = F_21 ( V_56 ) ;
goto V_61;
}
V_57 = F_24 ( V_6 -> V_12 -> V_22 -> V_23 ,
V_62 , NULL , V_6 , V_63 ,
V_6 -> V_60 ) ;
if ( F_20 ( V_57 ) ) {
V_32 = F_21 ( V_57 ) ;
goto V_64;
}
F_25 ( V_56 , V_65 ) ;
V_54 -> V_66 = F_12 ;
V_54 -> V_67 . V_68 = V_63 ;
V_54 -> V_67 . V_69 = V_59 ;
V_54 -> V_67 . V_70 = 1 ;
V_54 -> V_67 . V_71 = 1 ;
V_54 -> V_72 = V_73 ;
V_54 -> V_74 = V_75 ;
V_54 -> V_57 = V_57 ;
V_54 -> V_56 = V_56 ;
V_29 = F_26 ( V_6 -> V_12 -> V_22 -> V_76 , V_54 ) ;
if ( F_20 ( V_29 ) ) {
V_32 = F_21 ( V_29 ) ;
goto V_77;
}
V_32 = F_14 ( V_6 , V_29 ) ;
if ( V_32 )
goto V_78;
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
V_78:
F_27 ( V_29 ) ;
V_77:
F_28 ( V_57 ) ;
V_64:
F_28 ( V_56 ) ;
V_61:
F_9 ( V_54 ) ;
return V_32 ;
}
static void F_29 ( struct V_1 * V_6 )
{
int V_79 ;
F_27 ( V_6 -> V_29 ) ;
F_28 ( V_6 -> V_57 ) ;
F_28 ( V_6 -> V_56 ) ;
V_6 -> V_29 = NULL ;
V_6 -> V_57 = V_6 -> V_56 = NULL ;
for ( V_79 = 0 ; V_79 < V_59 ; ++ V_79 )
F_10 ( V_6 -> V_12 , V_6 -> V_80 [ V_79 ] ) ;
for ( V_79 = 0 ; V_79 < V_63 ; ++ V_79 )
F_10 ( V_6 -> V_12 , V_6 -> V_81 [ V_79 ] ) ;
}
static void F_30 ( int V_82 ,
struct V_83 * V_84 ,
void * V_85 )
{
struct V_1 * V_6 = V_85 ;
V_6 -> V_82 = V_82 ;
if ( V_82 )
F_31 ( V_86 , V_6 -> V_87 ,
V_88 L_2 , V_82 ) ;
else
V_6 -> V_36 = * V_84 ;
F_32 ( & V_6 -> V_89 ) ;
}
static int F_33 ( struct V_1 * V_6 )
{
V_6 -> V_36 . V_90 = 1 ;
F_34 ( & V_6 -> V_89 ) ;
V_6 -> V_91 = F_35 ( & V_92 ,
V_6 -> V_12 -> V_22 -> V_23 ,
V_6 -> V_12 -> V_35 ,
& V_6 -> V_36 ,
V_93 |
V_94 |
V_95 |
V_96 |
V_97 ,
V_98 ,
V_33 ,
F_30 ,
V_6 , & V_6 -> V_99 ) ;
if ( V_6 -> V_91 < 0 )
return V_6 -> V_91 ;
F_36 ( & V_6 -> V_89 ) ;
if ( V_6 -> V_82 < 0 )
F_31 ( V_100 , V_6 -> V_87 ,
V_88 L_3 ) ;
return V_6 -> V_82 ;
}
static int F_37 ( struct V_1 * V_6 )
{
struct {
struct V_101 V_102 ;
struct V_103 V_104 ;
} * V_105 = NULL ;
int V_82 ;
V_105 = F_6 ( sizeof *V_105 , V_33 ) ;
if ( ! V_105 )
return - V_34 ;
V_105 -> V_102 . V_106 = & V_6 -> V_36 ;
V_105 -> V_102 . V_107 = NULL ;
V_105 -> V_102 . V_108 = V_6 -> V_108 ;
V_105 -> V_102 . V_109 = V_6 -> V_29 -> V_109 ;
V_105 -> V_102 . V_74 = V_6 -> V_29 -> V_74 ;
V_105 -> V_102 . V_110 = & V_105 -> V_104 ;
V_105 -> V_102 . V_111 = sizeof V_105 -> V_104 ;
V_105 -> V_102 . V_112 = 1 ;
F_38 ( & V_105 -> V_102 . V_113 , 4 ) ;
V_105 -> V_102 . V_113 &= 0xffffff ;
V_105 -> V_102 . V_114 = 4 ;
V_105 -> V_102 . V_115 = 20 ;
V_105 -> V_102 . V_116 = 20 ;
V_105 -> V_102 . V_117 = 7 ;
V_105 -> V_102 . V_118 = 7 ;
V_105 -> V_102 . V_119 = 15 ;
V_105 -> V_104 . V_120 = V_121 ;
V_105 -> V_104 . V_122 = 0 ;
V_105 -> V_104 . V_123 = F_39 ( V_6 -> V_124 ) ;
V_105 -> V_104 . V_125 = F_40 ( V_126 |
V_127 ) ;
if ( V_6 -> V_128 == V_129 ) {
memcpy ( V_105 -> V_104 . V_130 ,
& V_6 -> V_36 . V_131 . V_132 . V_133 , 8 ) ;
memcpy ( V_105 -> V_104 . V_130 + 8 ,
& V_6 -> V_134 , 8 ) ;
memcpy ( V_105 -> V_104 . V_135 , & V_6 -> V_10 , 8 ) ;
memcpy ( V_105 -> V_104 . V_135 + 8 , & V_6 -> V_136 , 8 ) ;
} else {
memcpy ( V_105 -> V_104 . V_130 ,
& V_6 -> V_134 , 8 ) ;
memcpy ( V_105 -> V_104 . V_130 + 8 ,
& V_6 -> V_36 . V_131 . V_132 . V_133 , 8 ) ;
memcpy ( V_105 -> V_104 . V_135 , & V_6 -> V_136 , 8 ) ;
memcpy ( V_105 -> V_104 . V_135 + 8 , & V_6 -> V_10 , 8 ) ;
}
if ( F_3 ( V_6 ) ) {
F_31 ( V_137 , V_6 -> V_87 ,
V_88 L_4
L_5 ,
( unsigned long long ) F_41 ( V_6 -> V_10 ) ) ;
memset ( V_105 -> V_104 . V_130 , 0 , 8 ) ;
memcpy ( V_105 -> V_104 . V_130 + 8 ,
& V_6 -> V_12 -> V_22 -> V_23 -> V_138 , 8 ) ;
}
V_82 = F_42 ( V_6 -> V_52 , & V_105 -> V_102 ) ;
F_9 ( V_105 ) ;
return V_82 ;
}
static bool F_43 ( struct V_1 * V_6 )
{
bool V_139 = false ;
F_44 ( & V_6 -> V_140 ) ;
if ( V_6 -> V_141 != V_142 ) {
V_6 -> V_141 = V_142 ;
V_139 = true ;
}
F_45 ( & V_6 -> V_140 ) ;
if ( V_139 )
F_46 ( V_143 , & V_6 -> V_144 ) ;
return V_139 ;
}
static bool F_47 ( struct V_1 * V_6 ,
bool V_145 )
{
bool V_139 = false ;
F_44 ( & V_6 -> V_140 ) ;
if ( V_6 -> V_145 != V_145 ) {
V_6 -> V_145 = V_145 ;
V_139 = true ;
}
F_45 ( & V_6 -> V_140 ) ;
return V_139 ;
}
static void F_48 ( struct V_1 * V_6 )
{
if ( F_47 ( V_6 , false ) ) {
if ( F_49 ( V_6 -> V_52 , NULL , 0 ) ) {
F_31 ( V_137 , V_6 -> V_87 ,
V_88 L_6 ) ;
}
}
}
static void F_50 ( struct V_1 * V_6 )
{
struct V_146 * V_147 = V_6 -> V_12 -> V_22 -> V_23 ;
struct V_148 * V_105 ;
int V_79 ;
for ( V_79 = 0 , V_105 = V_6 -> V_149 ; V_79 < V_150 ; ++ V_79 , ++ V_105 ) {
F_9 ( V_105 -> V_151 ) ;
F_9 ( V_105 -> V_152 ) ;
if ( V_105 -> V_153 ) {
F_11 ( V_147 , V_105 -> V_153 ,
V_6 -> V_154 ,
V_155 ) ;
}
F_9 ( V_105 -> V_156 ) ;
}
}
static void F_51 ( struct V_2 * V_157 )
{
struct V_158 * * V_31 ;
for ( V_31 = V_157 -> V_159 -> V_160 ; V_31 && * V_31 ; ++ V_31 )
F_52 ( & V_157 -> V_161 , * V_31 ) ;
}
static void F_53 ( struct V_1 * V_6 )
{
F_54 ( V_6 -> V_141 != V_142 ) ;
F_51 ( V_6 -> V_87 ) ;
F_55 ( V_6 -> V_87 ) ;
F_56 ( V_6 -> V_87 ) ;
F_48 ( V_6 ) ;
F_22 ( V_6 -> V_52 ) ;
F_29 ( V_6 ) ;
F_50 ( V_6 ) ;
F_57 ( V_6 -> V_87 ) ;
}
static void F_58 ( struct V_162 * V_163 )
{
struct V_1 * V_6 =
F_59 ( V_163 , struct V_1 , V_144 ) ;
F_54 ( V_6 -> V_141 != V_142 ) ;
F_53 ( V_6 ) ;
F_60 ( & V_6 -> V_12 -> V_164 ) ;
F_61 ( & V_6 -> V_165 ) ;
F_62 ( & V_6 -> V_12 -> V_164 ) ;
}
static void F_63 ( struct V_166 * V_167 )
{
struct V_1 * V_6 = V_167 -> V_168 ;
F_43 ( V_6 ) ;
}
static int F_64 ( struct V_1 * V_6 )
{
int V_169 = 3 ;
int V_32 ;
F_54 ( V_6 -> V_145 ) ;
V_6 -> V_170 = false ;
V_32 = F_33 ( V_6 ) ;
if ( V_32 )
return V_32 ;
while ( 1 ) {
F_34 ( & V_6 -> V_89 ) ;
V_32 = F_37 ( V_6 ) ;
if ( V_32 )
return V_32 ;
F_36 ( & V_6 -> V_89 ) ;
switch ( V_6 -> V_82 ) {
case 0 :
F_47 ( V_6 , true ) ;
return 0 ;
case V_171 :
V_32 = F_33 ( V_6 ) ;
if ( V_32 )
return V_32 ;
break;
case V_172 :
break;
case V_173 :
if ( ! V_169 -- || F_18 ( V_6 ) ) {
F_31 ( V_86 , V_6 -> V_87 , V_88
L_7 ) ;
V_6 -> V_82 = - V_174 ;
return V_6 -> V_82 ;
}
F_31 ( V_86 , V_6 -> V_87 , V_88
L_8 ) ;
break;
default:
return V_6 -> V_82 ;
}
}
}
static void F_65 ( struct V_175 * V_176 ,
struct V_1 * V_6 ,
struct V_148 * V_105 )
{
struct V_146 * V_147 = V_6 -> V_12 -> V_22 -> V_23 ;
struct V_177 * * V_178 ;
if ( ! F_66 ( V_176 ) ||
( V_176 -> V_179 != V_155 &&
V_176 -> V_179 != V_180 ) )
return;
V_178 = V_105 -> V_151 ;
while ( V_105 -> V_181 -- )
F_67 ( * V_178 ++ ) ;
F_68 ( V_147 , F_66 ( V_176 ) , F_69 ( V_176 ) ,
V_176 -> V_179 ) ;
}
static struct V_175 * F_70 ( struct V_1 * V_6 ,
struct V_148 * V_105 ,
struct V_175 * V_176 )
{
unsigned long V_182 ;
F_71 ( & V_6 -> V_140 , V_182 ) ;
if ( ! V_176 ) {
V_176 = V_105 -> V_176 ;
V_105 -> V_176 = NULL ;
} else if ( V_105 -> V_176 == V_176 ) {
V_105 -> V_176 = NULL ;
} else {
V_176 = NULL ;
}
F_72 ( & V_6 -> V_140 , V_182 ) ;
return V_176 ;
}
static void F_73 ( struct V_1 * V_6 ,
struct V_148 * V_105 , struct V_175 * V_176 ,
T_4 V_183 )
{
unsigned long V_182 ;
F_65 ( V_176 , V_6 , V_105 ) ;
F_71 ( & V_6 -> V_140 , V_182 ) ;
V_6 -> V_184 += V_183 ;
F_74 ( & V_105 -> V_165 , & V_6 -> V_185 ) ;
F_72 ( & V_6 -> V_140 , V_182 ) ;
}
static void F_75 ( struct V_1 * V_6 , struct V_148 * V_105 )
{
struct V_175 * V_176 = F_70 ( V_6 , V_105 , NULL ) ;
if ( V_176 ) {
F_73 ( V_6 , V_105 , V_176 , 0 ) ;
V_176 -> V_186 = V_187 << 16 ;
V_176 -> V_188 ( V_176 ) ;
}
}
static int F_76 ( struct V_1 * V_6 )
{
struct V_2 * V_157 = V_6 -> V_87 ;
int V_79 , V_32 ;
F_77 ( & V_157 -> V_189 ) ;
F_48 ( V_6 ) ;
V_32 = F_18 ( V_6 ) ;
if ( V_32 == 0 )
V_32 = F_23 ( V_6 ) ;
else
F_23 ( V_6 ) ;
for ( V_79 = 0 ; V_79 < V_150 ; ++ V_79 ) {
struct V_148 * V_105 = & V_6 -> V_149 [ V_79 ] ;
if ( V_105 -> V_176 )
F_75 ( V_6 , V_105 ) ;
}
F_78 ( & V_6 -> V_190 ) ;
for ( V_79 = 0 ; V_79 < V_63 ; ++ V_79 )
F_79 ( & V_6 -> V_81 [ V_79 ] -> V_165 , & V_6 -> V_190 ) ;
if ( V_32 == 0 )
V_32 = F_64 ( V_6 ) ;
F_80 ( & V_157 -> V_189 , V_32 == 0 ? V_191 :
V_192 ) ;
V_6 -> V_193 = ! ! V_32 ;
if ( V_32 )
goto V_61;
F_31 ( V_194 , V_6 -> V_87 , V_88 L_9 ) ;
return V_32 ;
V_61:
F_31 ( V_86 , V_6 -> V_87 ,
V_88 L_10 , V_32 ) ;
F_43 ( V_6 ) ;
return V_32 ;
}
static void F_81 ( struct V_195 * V_141 , T_5 V_196 ,
unsigned int V_197 , T_6 V_198 )
{
struct V_199 * V_200 = V_141 -> V_200 ;
V_200 -> V_201 = F_82 ( V_196 ) ;
V_200 -> V_202 = F_39 ( V_198 ) ;
V_200 -> V_203 = F_39 ( V_197 ) ;
V_141 -> V_204 += V_197 ;
V_141 -> V_200 ++ ;
V_141 -> V_205 ++ ;
}
static int F_83 ( struct V_195 * V_141 ,
struct V_1 * V_6 )
{
struct V_206 * V_23 = V_6 -> V_12 -> V_22 ;
struct V_177 * V_207 ;
T_7 V_208 = 0 ;
if ( ! V_141 -> V_209 )
return 0 ;
if ( V_141 -> V_209 == 1 ) {
F_81 ( V_141 , V_141 -> V_210 , V_141 -> V_211 ,
V_6 -> V_198 ) ;
V_141 -> V_209 = V_141 -> V_211 = 0 ;
return 0 ;
}
V_207 = F_84 ( V_23 -> V_212 , V_141 -> V_213 ,
V_141 -> V_209 , V_208 ) ;
if ( F_20 ( V_207 ) )
return F_21 ( V_207 ) ;
* V_141 -> V_214 ++ = V_207 ;
V_141 -> V_181 ++ ;
F_81 ( V_141 , 0 , V_141 -> V_211 , V_207 -> V_207 -> V_198 ) ;
V_141 -> V_209 = V_141 -> V_211 = 0 ;
return 0 ;
}
static void F_85 ( struct V_195 * V_141 ,
struct V_215 * V_216 , int V_217 ,
T_5 V_196 )
{
V_141 -> V_218 = V_216 ;
V_141 -> V_219 = V_217 ;
V_141 -> V_220 = V_196 ;
}
static int F_86 ( struct V_195 * V_141 ,
struct V_1 * V_6 ,
struct V_215 * V_216 , int V_217 ,
int V_221 )
{
struct V_206 * V_23 = V_6 -> V_12 -> V_22 ;
struct V_146 * V_147 = V_23 -> V_23 ;
T_5 V_196 = F_87 ( V_147 , V_216 ) ;
unsigned int V_197 = F_88 ( V_147 , V_216 ) ;
unsigned int V_203 ;
int V_32 ;
if ( ! V_197 )
return 0 ;
if ( V_221 == V_222 ) {
F_81 ( V_141 , V_196 , V_197 , V_6 -> V_198 ) ;
return 0 ;
}
if ( V_196 & ~ V_23 -> V_223 || V_197 > V_23 -> V_224 ) {
V_32 = F_83 ( V_141 , V_6 ) ;
if ( V_32 )
return V_32 ;
F_81 ( V_141 , V_196 , V_197 , V_6 -> V_198 ) ;
F_85 ( V_141 , NULL , 0 , 0 ) ;
return 0 ;
}
if ( ! V_141 -> V_218 )
F_85 ( V_141 , V_216 , V_217 , V_196 ) ;
while ( V_197 ) {
if ( V_141 -> V_209 == V_225 ) {
V_32 = F_83 ( V_141 , V_6 ) ;
if ( V_32 )
return V_32 ;
F_85 ( V_141 , V_216 , V_217 , V_196 ) ;
}
V_203 = F_89 (unsigned int, dma_len, dev->fmr_page_size) ;
if ( ! V_141 -> V_209 )
V_141 -> V_210 = V_196 ;
V_141 -> V_213 [ V_141 -> V_209 ++ ] = V_196 ;
V_141 -> V_211 += V_203 ;
V_196 += V_203 ;
V_197 -= V_203 ;
}
V_32 = 0 ;
if ( V_203 != V_23 -> V_226 ) {
V_32 = F_83 ( V_141 , V_6 ) ;
if ( ! V_32 )
F_85 ( V_141 , NULL , 0 , 0 ) ;
}
return V_32 ;
}
static int F_90 ( struct V_175 * V_176 , struct V_1 * V_6 ,
struct V_148 * V_105 )
{
struct V_215 * V_227 , * V_216 ;
struct V_228 * V_229 = V_105 -> V_229 -> V_19 ;
int V_79 , V_203 , V_230 , V_231 , V_221 ;
struct V_206 * V_23 ;
struct V_146 * V_147 ;
struct V_195 V_141 ;
struct V_232 * V_233 ;
T_6 V_234 ;
T_1 V_235 ;
if ( ! F_66 ( V_176 ) || V_176 -> V_179 == V_236 )
return sizeof ( struct V_228 ) ;
if ( V_176 -> V_179 != V_180 &&
V_176 -> V_179 != V_155 ) {
F_31 ( V_100 , V_6 -> V_87 ,
V_88 L_11 ,
V_176 -> V_179 ) ;
return - V_237 ;
}
V_230 = F_69 ( V_176 ) ;
V_227 = F_66 ( V_176 ) ;
V_23 = V_6 -> V_12 -> V_22 ;
V_147 = V_23 -> V_23 ;
V_231 = F_91 ( V_147 , V_227 , V_230 , V_176 -> V_179 ) ;
if ( F_92 ( V_231 == 0 ) )
return - V_238 ;
V_235 = V_239 ;
V_203 = sizeof ( struct V_228 ) + sizeof ( struct V_199 ) ;
if ( V_231 == 1 ) {
struct V_199 * V_19 = ( void * ) V_229 -> V_240 ;
V_19 -> V_201 = F_82 ( F_87 ( V_147 , V_227 ) ) ;
V_19 -> V_202 = F_39 ( V_6 -> V_198 ) ;
V_19 -> V_203 = F_39 ( F_88 ( V_147 , V_227 ) ) ;
V_105 -> V_181 = 0 ;
goto V_241;
}
V_233 = ( void * ) V_229 -> V_240 ;
F_93 ( V_147 , V_105 -> V_153 ,
V_6 -> V_154 , V_155 ) ;
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
V_141 . V_200 = V_105 -> V_156 ;
V_141 . V_213 = V_105 -> V_152 ;
V_141 . V_214 = V_105 -> V_151 ;
V_221 = V_23 -> V_212 ? V_242 : V_222 ;
F_94 (scat, sg, count, i) {
if ( F_86 ( & V_141 , V_6 , V_216 , V_79 , V_221 ) ) {
T_5 V_196 ;
unsigned int V_197 ;
V_243:
V_216 = V_141 . V_218 ;
V_79 = V_141 . V_219 ;
V_196 = F_87 ( V_147 , V_216 ) ;
V_197 = F_88 ( V_147 , V_216 ) ;
V_197 -= ( V_141 . V_220 - V_196 ) ;
V_196 = V_141 . V_220 ;
V_221 = V_222 ;
F_81 ( & V_141 , V_196 , V_197 , V_6 -> V_198 ) ;
}
}
if ( V_221 == V_242 && F_83 ( & V_141 , V_6 ) )
goto V_243;
V_105 -> V_181 = V_141 . V_181 ;
if ( V_141 . V_205 == 1 ) {
struct V_199 * V_19 = ( void * ) V_229 -> V_240 ;
* V_19 = V_105 -> V_156 [ 0 ] ;
goto V_241;
}
if ( F_92 ( V_6 -> V_244 < V_141 . V_205 &&
! V_6 -> V_245 ) ) {
F_31 ( V_86 , V_6 -> V_87 ,
L_12 ) ;
return - V_238 ;
}
V_231 = F_95 ( V_141 . V_205 , V_6 -> V_244 ) ;
V_234 = V_141 . V_205 * sizeof ( struct V_199 ) ;
V_235 = V_246 ;
V_203 = sizeof( struct V_228 ) + sizeof ( struct V_232 ) ;
V_203 += V_231 * sizeof ( struct V_199 ) ;
memcpy ( V_233 -> V_247 , V_105 -> V_156 ,
V_231 * sizeof ( struct V_199 ) ) ;
V_233 -> V_248 . V_201 = F_82 ( V_105 -> V_153 ) ;
V_233 -> V_248 . V_202 = F_39 ( V_6 -> V_198 ) ;
V_233 -> V_248 . V_203 = F_39 ( V_234 ) ;
V_233 -> V_203 = F_39 ( V_141 . V_204 ) ;
if ( V_176 -> V_179 == V_155 )
V_229 -> V_249 = V_231 ;
else
V_229 -> V_250 = V_231 ;
F_96 ( V_147 , V_105 -> V_153 , V_234 ,
V_155 ) ;
V_241:
if ( V_176 -> V_179 == V_155 )
V_229 -> V_251 = V_235 << 4 ;
else
V_229 -> V_251 = V_235 ;
return V_203 ;
}
static void F_97 ( struct V_1 * V_6 , struct V_11 * V_17 ,
enum V_252 V_253 )
{
unsigned long V_182 ;
F_71 ( & V_6 -> V_140 , V_182 ) ;
F_79 ( & V_17 -> V_165 , & V_6 -> V_190 ) ;
if ( V_253 != V_254 )
++ V_6 -> V_184 ;
F_72 ( & V_6 -> V_140 , V_182 ) ;
}
static struct V_11 * F_98 ( struct V_1 * V_6 ,
enum V_252 V_253 )
{
T_4 V_255 = ( V_253 == V_256 ) ? 0 : V_257 ;
struct V_11 * V_17 ;
V_62 ( V_6 -> V_57 , V_6 ) ;
if ( F_99 ( & V_6 -> V_190 ) )
return NULL ;
if ( V_253 != V_254 ) {
if ( V_6 -> V_184 <= V_255 ) {
++ V_6 -> V_258 ;
return NULL ;
}
-- V_6 -> V_184 ;
}
V_17 = F_100 ( & V_6 -> V_190 , struct V_11 , V_165 ) ;
F_61 ( & V_17 -> V_165 ) ;
return V_17 ;
}
static int F_101 ( struct V_1 * V_6 ,
struct V_11 * V_17 , int V_203 )
{
struct V_259 V_165 ;
struct V_260 V_261 , * V_262 ;
V_165 . V_263 = V_17 -> V_21 ;
V_165 . V_264 = V_203 ;
V_165 . V_265 = V_6 -> V_265 ;
V_261 . V_266 = NULL ;
V_261 . V_267 = ( V_268 ) V_17 ;
V_261 . V_269 = & V_165 ;
V_261 . V_270 = 1 ;
V_261 . V_120 = V_271 ;
V_261 . V_272 = V_273 ;
return F_102 ( V_6 -> V_29 , & V_261 , & V_262 ) ;
}
static int F_103 ( struct V_1 * V_6 , struct V_11 * V_17 )
{
struct V_274 V_261 , * V_262 ;
struct V_259 V_165 ;
V_165 . V_263 = V_17 -> V_21 ;
V_165 . V_264 = V_17 -> V_13 ;
V_165 . V_265 = V_6 -> V_265 ;
V_261 . V_266 = NULL ;
V_261 . V_267 = ( V_268 ) V_17 ;
V_261 . V_269 = & V_165 ;
V_261 . V_270 = 1 ;
return F_104 ( V_6 -> V_29 , & V_261 , & V_262 ) ;
}
static void F_105 ( struct V_1 * V_6 , struct V_275 * V_276 )
{
struct V_148 * V_105 ;
struct V_175 * V_176 ;
unsigned long V_182 ;
if ( F_92 ( V_276 -> V_122 & V_277 ) ) {
F_71 ( & V_6 -> V_140 , V_182 ) ;
V_6 -> V_184 += F_106 ( V_276 -> V_183 ) ;
F_72 ( & V_6 -> V_140 , V_182 ) ;
V_6 -> V_278 = - 1 ;
if ( F_106 ( V_276 -> V_279 ) >= 4 )
V_6 -> V_278 = V_276 -> V_280 [ 3 ] ;
F_32 ( & V_6 -> V_281 ) ;
} else {
V_105 = & V_6 -> V_149 [ V_276 -> V_122 ] ;
V_176 = F_70 ( V_6 , V_105 , NULL ) ;
if ( ! V_176 ) {
F_31 ( V_86 , V_6 -> V_87 ,
L_13 ,
( unsigned long long ) V_276 -> V_122 ) ;
F_71 ( & V_6 -> V_140 , V_182 ) ;
V_6 -> V_184 += F_106 ( V_276 -> V_183 ) ;
F_72 ( & V_6 -> V_140 , V_182 ) ;
return;
}
V_176 -> V_186 = V_276 -> V_82 ;
if ( V_276 -> V_182 & V_282 ) {
memcpy ( V_176 -> V_283 , V_276 -> V_280 +
F_106 ( V_276 -> V_279 ) ,
F_89 ( int , F_106 ( V_276 -> V_284 ) ,
V_285 ) ) ;
}
if ( V_276 -> V_182 & ( V_286 | V_287 ) )
F_107 ( V_176 , F_106 ( V_276 -> V_288 ) ) ;
else if ( V_276 -> V_182 & ( V_289 | V_290 ) )
F_107 ( V_176 , F_106 ( V_276 -> V_291 ) ) ;
F_73 ( V_6 , V_105 , V_176 ,
F_106 ( V_276 -> V_183 ) ) ;
V_176 -> V_292 = NULL ;
V_176 -> V_188 ( V_176 ) ;
}
}
static int F_108 ( struct V_1 * V_6 , T_4 V_293 ,
void * V_276 , int V_203 )
{
struct V_146 * V_23 = V_6 -> V_12 -> V_22 -> V_23 ;
unsigned long V_182 ;
struct V_11 * V_17 ;
int V_61 ;
F_71 ( & V_6 -> V_140 , V_182 ) ;
V_6 -> V_184 += V_293 ;
V_17 = F_98 ( V_6 , V_254 ) ;
F_72 ( & V_6 -> V_140 , V_182 ) ;
if ( ! V_17 ) {
F_31 ( V_86 , V_6 -> V_87 , V_88
L_14 ) ;
return 1 ;
}
F_93 ( V_23 , V_17 -> V_21 , V_203 , V_155 ) ;
memcpy ( V_17 -> V_19 , V_276 , V_203 ) ;
F_96 ( V_23 , V_17 -> V_21 , V_203 , V_155 ) ;
V_61 = F_101 ( V_6 , V_17 , V_203 ) ;
if ( V_61 ) {
F_31 ( V_86 , V_6 -> V_87 , V_88
L_15 , V_61 ) ;
F_97 ( V_6 , V_17 , V_254 ) ;
}
return V_61 ;
}
static void F_109 ( struct V_1 * V_6 ,
struct V_294 * V_105 )
{
struct V_295 V_276 = {
. V_120 = V_296 ,
. V_122 = V_105 -> V_122 ,
} ;
T_4 V_297 = F_106 ( V_105 -> V_183 ) ;
if ( F_108 ( V_6 , V_297 , & V_276 , sizeof V_276 ) )
F_31 ( V_86 , V_6 -> V_87 , V_88
L_16 ) ;
}
static void F_110 ( struct V_1 * V_6 ,
struct V_298 * V_105 )
{
struct V_299 V_276 = {
. V_120 = V_300 ,
. V_122 = V_105 -> V_122 ,
} ;
T_4 V_297 = F_106 ( V_105 -> V_183 ) ;
F_31 ( V_86 , V_6 -> V_87 , V_88
L_17 , F_41 ( V_105 -> V_301 ) ) ;
if ( F_108 ( V_6 , V_297 , & V_276 , sizeof V_276 ) )
F_31 ( V_86 , V_6 -> V_87 , V_88
L_18 ) ;
}
static void F_111 ( struct V_1 * V_6 , struct V_302 * V_303 )
{
struct V_146 * V_23 = V_6 -> V_12 -> V_22 -> V_23 ;
struct V_11 * V_17 = (struct V_11 * ) ( V_268 ) V_303 -> V_267 ;
int V_304 ;
T_1 V_120 ;
F_93 ( V_23 , V_17 -> V_21 , V_6 -> V_305 ,
V_180 ) ;
V_120 = * ( T_1 * ) V_17 -> V_19 ;
if ( 0 ) {
F_31 ( V_86 , V_6 -> V_87 ,
V_88 L_19 , V_120 ) ;
F_112 ( V_86 , L_20 , V_306 , 8 , 1 ,
V_17 -> V_19 , V_303 -> V_307 , true ) ;
}
switch ( V_120 ) {
case V_308 :
F_105 ( V_6 , V_17 -> V_19 ) ;
break;
case V_309 :
F_109 ( V_6 , V_17 -> V_19 ) ;
break;
case V_310 :
F_110 ( V_6 , V_17 -> V_19 ) ;
break;
case V_311 :
F_31 ( V_100 , V_6 -> V_87 ,
V_88 L_21 ) ;
break;
default:
F_31 ( V_100 , V_6 -> V_87 ,
V_88 L_22 , V_120 ) ;
break;
}
F_96 ( V_23 , V_17 -> V_21 , V_6 -> V_305 ,
V_180 ) ;
V_304 = F_103 ( V_6 , V_17 ) ;
if ( V_304 != 0 )
F_31 ( V_86 , V_6 -> V_87 ,
V_88 L_23 , V_304 ) ;
}
static void F_113 ( enum V_312 V_313 ,
enum V_314 V_315 ,
struct V_1 * V_6 )
{
if ( V_6 -> V_145 && ! V_6 -> V_170 ) {
F_31 ( V_86 , V_6 -> V_87 ,
V_88 L_24 ,
V_315 & V_316 ? L_25 : L_26 ,
V_313 ) ;
}
V_6 -> V_170 = true ;
}
static void V_58 ( struct V_55 * V_317 , void * V_85 )
{
struct V_1 * V_6 = V_85 ;
struct V_302 V_303 ;
F_25 ( V_317 , V_65 ) ;
while ( F_114 ( V_317 , 1 , & V_303 ) > 0 ) {
if ( F_115 ( V_303 . V_82 == V_318 ) ) {
F_111 ( V_6 , & V_303 ) ;
} else {
F_113 ( V_303 . V_82 , V_303 . V_120 , V_6 ) ;
}
}
}
static void V_62 ( struct V_55 * V_317 , void * V_85 )
{
struct V_1 * V_6 = V_85 ;
struct V_302 V_303 ;
struct V_11 * V_17 ;
while ( F_114 ( V_317 , 1 , & V_303 ) > 0 ) {
if ( F_115 ( V_303 . V_82 == V_318 ) ) {
V_17 = (struct V_11 * ) ( V_268 ) V_303 . V_267 ;
F_79 ( & V_17 -> V_165 , & V_6 -> V_190 ) ;
} else {
F_113 ( V_303 . V_82 , V_303 . V_120 , V_6 ) ;
}
}
}
static int F_116 ( struct V_2 * V_157 , struct V_175 * V_176 )
{
struct V_1 * V_6 = F_1 ( V_157 ) ;
struct V_148 * V_105 ;
struct V_11 * V_17 ;
struct V_228 * V_229 ;
struct V_146 * V_23 ;
unsigned long V_182 ;
int V_203 ;
if ( F_92 ( V_6 -> V_193 ) ) {
V_176 -> V_186 = V_319 << 16 ;
V_176 -> V_188 ( V_176 ) ;
return 0 ;
}
F_71 ( & V_6 -> V_140 , V_182 ) ;
V_17 = F_98 ( V_6 , V_320 ) ;
if ( ! V_17 )
goto V_321;
V_105 = F_100 ( & V_6 -> V_185 , struct V_148 , V_165 ) ;
F_61 ( & V_105 -> V_165 ) ;
F_72 ( & V_6 -> V_140 , V_182 ) ;
V_23 = V_6 -> V_12 -> V_22 -> V_23 ;
F_93 ( V_23 , V_17 -> V_21 , V_6 -> V_124 ,
V_155 ) ;
V_176 -> V_186 = 0 ;
V_176 -> V_292 = ( void * ) V_105 ;
V_229 = V_17 -> V_19 ;
memset ( V_229 , 0 , sizeof *V_229 ) ;
V_229 -> V_120 = V_322 ;
V_229 -> V_301 = F_82 ( ( T_7 ) V_176 -> V_323 -> V_301 << 48 ) ;
V_229 -> V_122 = V_105 -> V_324 ;
memcpy ( V_229 -> V_325 , V_176 -> V_326 , V_176 -> V_327 ) ;
V_105 -> V_176 = V_176 ;
V_105 -> V_229 = V_17 ;
V_203 = F_90 ( V_176 , V_6 , V_105 ) ;
if ( V_203 < 0 ) {
F_31 ( V_86 , V_6 -> V_87 ,
V_88 L_27 ) ;
goto V_328;
}
F_96 ( V_23 , V_17 -> V_21 , V_6 -> V_124 ,
V_155 ) ;
if ( F_101 ( V_6 , V_17 , V_203 ) ) {
F_31 ( V_86 , V_6 -> V_87 , V_88 L_28 ) ;
goto V_329;
}
return 0 ;
V_329:
F_65 ( V_176 , V_6 , V_105 ) ;
V_328:
F_97 ( V_6 , V_17 , V_320 ) ;
F_71 ( & V_6 -> V_140 , V_182 ) ;
F_79 ( & V_105 -> V_165 , & V_6 -> V_185 ) ;
V_321:
F_72 ( & V_6 -> V_140 , V_182 ) ;
return V_330 ;
}
static int F_117 ( struct V_1 * V_6 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 < V_59 ; ++ V_79 ) {
V_6 -> V_80 [ V_79 ] = F_4 ( V_6 -> V_12 ,
V_6 -> V_305 ,
V_33 , V_180 ) ;
if ( ! V_6 -> V_80 [ V_79 ] )
goto V_61;
}
for ( V_79 = 0 ; V_79 < V_63 ; ++ V_79 ) {
V_6 -> V_81 [ V_79 ] = F_4 ( V_6 -> V_12 ,
V_6 -> V_124 ,
V_33 , V_155 ) ;
if ( ! V_6 -> V_81 [ V_79 ] )
goto V_61;
F_79 ( & V_6 -> V_81 [ V_79 ] -> V_165 , & V_6 -> V_190 ) ;
}
return 0 ;
V_61:
for ( V_79 = 0 ; V_79 < V_59 ; ++ V_79 ) {
F_10 ( V_6 -> V_12 , V_6 -> V_80 [ V_79 ] ) ;
V_6 -> V_80 [ V_79 ] = NULL ;
}
for ( V_79 = 0 ; V_79 < V_63 ; ++ V_79 ) {
F_10 ( V_6 -> V_12 , V_6 -> V_81 [ V_79 ] ) ;
V_6 -> V_81 [ V_79 ] = NULL ;
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
int V_79 ;
if ( V_342 -> V_120 == V_343 ) {
V_6 -> V_305 = F_106 ( V_342 -> V_305 ) ;
V_6 -> V_184 = F_106 ( V_342 -> V_183 ) ;
V_6 -> V_87 -> V_344
= F_95 ( V_6 -> V_184 - V_257 ,
V_6 -> V_87 -> V_344 ) ;
} else {
F_31 ( V_100 , V_6 -> V_87 ,
V_88 L_29 , V_342 -> V_120 ) ;
V_32 = - V_174 ;
goto error;
}
if ( ! V_6 -> V_80 [ 0 ] ) {
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
for ( V_79 = 0 ; V_79 < V_59 ; V_79 ++ ) {
struct V_11 * V_17 = V_6 -> V_80 [ V_79 ] ;
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
V_6 -> V_82 = V_32 ;
}
static void F_124 ( struct V_49 * V_52 ,
struct V_348 * V_26 ,
struct V_1 * V_6 )
{
struct V_2 * V_157 = V_6 -> V_87 ;
struct V_349 * V_350 ;
int V_120 ;
switch ( V_26 -> V_102 . V_351 . V_352 ) {
case V_353 :
V_350 = V_26 -> V_102 . V_351 . V_354 ;
V_6 -> V_36 . V_355 = V_350 -> V_356 ;
V_6 -> V_36 . V_37 = V_350 -> V_357 ;
V_52 -> V_358 = F_106 ( V_350 -> V_359 ) & 0x00ffffff ;
memcpy ( V_6 -> V_36 . V_360 . V_361 , V_350 -> V_362 , 16 ) ;
V_6 -> V_82 = V_6 -> V_36 . V_355 ?
V_172 : V_171 ;
break;
case V_363 :
if ( F_3 ( V_6 ) ) {
memcpy ( V_6 -> V_36 . V_360 . V_361 ,
V_26 -> V_102 . V_351 . V_354 , 16 ) ;
F_31 ( V_137 , V_157 ,
V_88 L_30 ,
( unsigned long long ) F_41 ( V_6 -> V_36 . V_360 . V_132 . V_364 ) ,
( unsigned long long ) F_41 ( V_6 -> V_36 . V_360 . V_132 . V_133 ) ) ;
V_6 -> V_82 = V_171 ;
} else {
F_31 ( V_100 , V_157 ,
L_31 ) ;
V_6 -> V_82 = - V_174 ;
}
break;
case V_365 :
F_31 ( V_100 , V_157 ,
L_32 ) ;
V_6 -> V_82 = - V_174 ;
break;
case V_366 :
V_120 = * ( T_1 * ) V_26 -> V_110 ;
if ( V_120 == V_367 ) {
struct V_368 * V_369 = V_26 -> V_110 ;
T_6 V_352 = F_106 ( V_369 -> V_352 ) ;
if ( V_352 == V_370 )
F_31 ( V_100 , V_157 ,
V_88 L_33 ) ;
else
F_31 ( V_100 , V_157 ,
V_88 L_34 , V_352 ) ;
} else
F_31 ( V_100 , V_157 ,
L_35
L_36 , V_120 ) ;
V_6 -> V_82 = - V_174 ;
break;
case V_371 :
F_31 ( V_100 , V_157 , L_37 ) ;
V_6 -> V_82 = V_173 ;
break;
default:
F_31 ( V_100 , V_157 , L_38 ,
V_26 -> V_102 . V_351 . V_352 ) ;
V_6 -> V_82 = - V_174 ;
}
}
static int V_51 ( struct V_49 * V_52 , struct V_348 * V_26 )
{
struct V_1 * V_6 = V_52 -> V_27 ;
int V_372 = 0 ;
switch ( V_26 -> V_26 ) {
case V_373 :
F_31 ( V_137 , V_6 -> V_87 ,
V_88 L_39 ) ;
V_372 = 1 ;
V_6 -> V_82 = - V_174 ;
break;
case V_374 :
V_372 = 1 ;
F_121 ( V_52 , V_26 -> V_110 , V_6 ) ;
break;
case V_375 :
F_31 ( V_137 , V_6 -> V_87 , V_88 L_40 ) ;
V_372 = 1 ;
F_124 ( V_52 , V_26 , V_6 ) ;
break;
case V_376 :
F_31 ( V_100 , V_6 -> V_87 ,
V_88 L_41 ) ;
F_47 ( V_6 , false ) ;
if ( F_125 ( V_52 , NULL , 0 ) )
F_31 ( V_86 , V_6 -> V_87 ,
V_88 L_42 ) ;
break;
case V_377 :
F_31 ( V_86 , V_6 -> V_87 ,
V_88 L_43 ) ;
V_6 -> V_82 = 0 ;
break;
case V_378 :
case V_379 :
case V_380 :
break;
default:
F_31 ( V_100 , V_6 -> V_87 ,
V_88 L_44 , V_26 -> V_26 ) ;
break;
}
if ( V_372 )
F_32 ( & V_6 -> V_89 ) ;
return 0 ;
}
static int F_126 ( struct V_1 * V_6 ,
T_7 V_381 , unsigned int V_301 , T_1 V_382 )
{
struct V_146 * V_23 = V_6 -> V_12 -> V_22 -> V_23 ;
struct V_11 * V_17 ;
struct V_383 * V_384 ;
if ( ! V_6 -> V_145 || V_6 -> V_170 )
return - 1 ;
F_34 ( & V_6 -> V_281 ) ;
F_44 ( & V_6 -> V_140 ) ;
V_17 = F_98 ( V_6 , V_256 ) ;
F_45 ( & V_6 -> V_140 ) ;
if ( ! V_17 )
return - 1 ;
F_93 ( V_23 , V_17 -> V_21 , sizeof *V_384 ,
V_155 ) ;
V_384 = V_17 -> V_19 ;
memset ( V_384 , 0 , sizeof *V_384 ) ;
V_384 -> V_120 = V_385 ;
V_384 -> V_301 = F_82 ( ( T_7 ) V_301 << 48 ) ;
V_384 -> V_122 = V_381 | V_277 ;
V_384 -> V_386 = V_382 ;
V_384 -> V_387 = V_381 ;
F_96 ( V_23 , V_17 -> V_21 , sizeof *V_384 ,
V_155 ) ;
if ( F_101 ( V_6 , V_17 , sizeof *V_384 ) ) {
F_97 ( V_6 , V_17 , V_256 ) ;
return - 1 ;
}
if ( ! F_127 ( & V_6 -> V_281 ,
F_120 ( V_388 ) ) )
return - 1 ;
return 0 ;
}
static int F_128 ( struct V_175 * V_176 )
{
struct V_1 * V_6 = F_1 ( V_176 -> V_323 -> V_3 ) ;
struct V_148 * V_105 = (struct V_148 * ) V_176 -> V_292 ;
int V_32 ;
F_31 ( V_86 , V_6 -> V_87 , L_45 ) ;
if ( ! V_105 || ! F_70 ( V_6 , V_105 , V_176 ) )
return V_389 ;
if ( F_126 ( V_6 , V_105 -> V_324 , V_176 -> V_323 -> V_301 ,
V_390 ) == 0 )
V_32 = V_391 ;
else if ( V_6 -> V_193 )
V_32 = V_392 ;
else
V_32 = V_389 ;
F_73 ( V_6 , V_105 , V_176 , 0 ) ;
V_176 -> V_186 = V_393 << 16 ;
V_176 -> V_188 ( V_176 ) ;
return V_32 ;
}
static int F_129 ( struct V_175 * V_176 )
{
struct V_1 * V_6 = F_1 ( V_176 -> V_323 -> V_3 ) ;
int V_79 ;
F_31 ( V_86 , V_6 -> V_87 , L_46 ) ;
if ( F_126 ( V_6 , V_394 , V_176 -> V_323 -> V_301 ,
V_395 ) )
return V_389 ;
if ( V_6 -> V_278 )
return V_389 ;
for ( V_79 = 0 ; V_79 < V_150 ; ++ V_79 ) {
struct V_148 * V_105 = & V_6 -> V_149 [ V_79 ] ;
if ( V_105 -> V_176 && V_105 -> V_176 -> V_323 == V_176 -> V_323 )
F_75 ( V_6 , V_105 ) ;
}
return V_391 ;
}
static int F_130 ( struct V_175 * V_176 )
{
struct V_1 * V_6 = F_1 ( V_176 -> V_323 -> V_3 ) ;
int V_32 = V_389 ;
F_31 ( V_86 , V_6 -> V_87 , V_88 L_47 ) ;
if ( ! F_76 ( V_6 ) )
V_32 = V_391 ;
return V_32 ;
}
static int F_131 ( struct V_396 * V_397 )
{
struct V_2 * V_157 = V_397 -> V_3 ;
struct V_1 * V_6 = F_1 ( V_157 ) ;
struct V_398 * V_399 = V_397 -> V_398 ;
unsigned long V_338 ;
if ( V_397 -> type == V_400 ) {
V_338 = F_132 ( unsigned , 30 * V_401 , V_6 -> V_335 ) ;
F_133 ( V_399 , V_338 ) ;
}
return 0 ;
}
static T_10 F_134 ( struct V_323 * V_23 , struct V_158 * V_31 ,
char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_48 ,
( unsigned long long ) F_41 ( V_6 -> V_136 ) ) ;
}
static T_10 F_136 ( struct V_323 * V_23 , struct V_158 * V_31 ,
char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_48 ,
( unsigned long long ) F_41 ( V_6 -> V_10 ) ) ;
}
static T_10 F_137 ( struct V_323 * V_23 ,
struct V_158 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_48 ,
( unsigned long long ) F_41 ( V_6 -> V_108 ) ) ;
}
static T_10 F_138 ( struct V_323 * V_23 , struct V_158 * V_31 ,
char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_49 , F_16 ( V_6 -> V_36 . V_37 ) ) ;
}
static T_10 F_139 ( struct V_323 * V_23 , struct V_158 * V_31 ,
char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_50 , V_6 -> V_36 . V_360 . V_361 ) ;
}
static T_10 F_140 ( struct V_323 * V_23 ,
struct V_158 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_50 , V_6 -> V_402 ) ;
}
static T_10 F_141 ( struct V_323 * V_23 ,
struct V_158 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_51 , V_6 -> V_184 ) ;
}
static T_10 F_142 ( struct V_323 * V_23 ,
struct V_158 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_51 , V_6 -> V_258 ) ;
}
static T_10 F_143 ( struct V_323 * V_23 ,
struct V_158 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_51 , V_6 -> V_12 -> V_35 ) ;
}
static T_10 F_144 ( struct V_323 * V_23 ,
struct V_158 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_52 , V_6 -> V_12 -> V_22 -> V_23 -> V_403 ) ;
}
static T_10 F_145 ( struct V_323 * V_23 ,
struct V_158 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_51 , V_6 -> V_60 ) ;
}
static T_10 F_146 ( struct V_323 * V_23 ,
struct V_158 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_53 , V_6 -> V_244 ) ;
}
static T_10 F_147 ( struct V_323 * V_23 ,
struct V_158 * V_31 , char * V_19 )
{
struct V_1 * V_6 = F_1 ( F_135 ( V_23 ) ) ;
return sprintf ( V_19 , L_52 , V_6 -> V_245 ? L_54 : L_55 ) ;
}
static int F_148 ( struct V_12 * V_3 , struct V_1 * V_6 )
{
struct V_404 V_405 ;
struct V_166 * V_167 ;
sprintf ( V_6 -> V_5 , L_56 ,
( unsigned long long ) F_41 ( V_6 -> V_136 ) ) ;
if ( F_149 ( V_6 -> V_87 , V_3 -> V_22 -> V_23 -> V_406 ) )
return - V_407 ;
memcpy ( V_405 . V_408 , & V_6 -> V_136 , 8 ) ;
memcpy ( V_405 . V_408 + 8 , & V_6 -> V_10 , 8 ) ;
V_405 . V_409 = V_410 ;
V_167 = F_150 ( V_6 -> V_87 , & V_405 ) ;
if ( F_20 ( V_167 ) ) {
F_56 ( V_6 -> V_87 ) ;
return F_21 ( V_167 ) ;
}
V_167 -> V_168 = V_6 ;
F_60 ( & V_3 -> V_164 ) ;
F_74 ( & V_6 -> V_165 , & V_3 -> V_411 ) ;
F_62 ( & V_3 -> V_164 ) ;
V_6 -> V_141 = V_412 ;
F_151 ( & V_6 -> V_87 -> V_189 ,
0 , V_6 -> V_413 , V_414 , 0 ) ;
return 0 ;
}
static void F_152 ( struct V_323 * V_23 )
{
struct V_12 * V_3 =
F_59 ( V_23 , struct V_12 , V_23 ) ;
F_32 ( & V_3 -> V_415 ) ;
}
static bool F_153 ( struct V_12 * V_3 ,
struct V_1 * V_6 )
{
struct V_1 * V_416 ;
bool V_32 = false ;
if ( V_6 -> V_141 == V_142 )
goto V_18;
V_32 = true ;
F_60 ( & V_3 -> V_164 ) ;
F_154 (t, &host->target_list, list) {
if ( V_416 != V_6 &&
V_6 -> V_136 == V_416 -> V_136 &&
V_6 -> V_10 == V_416 -> V_10 &&
V_6 -> V_134 == V_416 -> V_134 ) {
V_32 = false ;
break;
}
}
F_62 ( & V_3 -> V_164 ) ;
V_18:
return V_32 ;
}
static int F_155 ( const char * V_19 , struct V_1 * V_6 )
{
char * V_417 , * V_418 ;
char * V_419 ;
char V_360 [ 3 ] ;
T_11 args [ V_420 ] ;
int V_421 = 0 ;
int V_422 ;
int V_32 = - V_237 ;
int V_79 ;
V_417 = F_156 ( V_19 , V_33 ) ;
if ( ! V_417 )
return - V_34 ;
V_418 = V_417 ;
while ( ( V_419 = F_157 ( & V_418 , L_57 ) ) != NULL ) {
if ( ! * V_419 )
continue;
V_422 = F_158 ( V_419 , V_423 , args ) ;
V_421 |= V_422 ;
switch ( V_422 ) {
case V_424 :
V_419 = F_159 ( args ) ;
if ( ! V_419 ) {
V_32 = - V_34 ;
goto V_18;
}
V_6 -> V_136 = F_82 ( F_160 ( V_419 , NULL , 16 ) ) ;
F_9 ( V_419 ) ;
break;
case V_425 :
V_419 = F_159 ( args ) ;
if ( ! V_419 ) {
V_32 = - V_34 ;
goto V_18;
}
V_6 -> V_10 = F_82 ( F_160 ( V_419 , NULL , 16 ) ) ;
F_9 ( V_419 ) ;
break;
case V_426 :
V_419 = F_159 ( args ) ;
if ( ! V_419 ) {
V_32 = - V_34 ;
goto V_18;
}
if ( strlen ( V_419 ) != 32 ) {
F_161 ( L_58 , V_419 ) ;
F_9 ( V_419 ) ;
goto V_18;
}
for ( V_79 = 0 ; V_79 < 16 ; ++ V_79 ) {
F_162 ( V_360 , V_419 + V_79 * 2 , 3 ) ;
V_6 -> V_36 . V_360 . V_361 [ V_79 ] = F_163 ( V_360 , NULL , 16 ) ;
}
F_9 ( V_419 ) ;
memcpy ( V_6 -> V_402 , V_6 -> V_36 . V_360 . V_361 , 16 ) ;
break;
case V_427 :
if ( F_164 ( args , & V_422 ) ) {
F_161 ( L_59 , V_419 ) ;
goto V_18;
}
V_6 -> V_36 . V_37 = F_40 ( V_422 ) ;
break;
case V_428 :
V_419 = F_159 ( args ) ;
if ( ! V_419 ) {
V_32 = - V_34 ;
goto V_18;
}
V_6 -> V_108 = F_82 ( F_160 ( V_419 , NULL , 16 ) ) ;
V_6 -> V_36 . V_108 = V_6 -> V_108 ;
F_9 ( V_419 ) ;
break;
case V_429 :
if ( F_165 ( args , & V_422 ) ) {
F_161 ( L_60 , V_419 ) ;
goto V_18;
}
V_6 -> V_87 -> V_430 = V_422 ;
break;
case V_431 :
if ( F_165 ( args , & V_422 ) ) {
F_161 ( L_61 ,
V_419 ) ;
goto V_18;
}
V_6 -> V_87 -> V_432 = F_95 ( V_422 , V_150 ) ;
break;
case V_433 :
if ( F_164 ( args , & V_422 ) ) {
F_161 ( L_62 , V_419 ) ;
goto V_18;
}
if ( V_422 != V_129 &&
V_422 != V_434 ) {
F_161 ( L_63 ,
V_422 , V_129 ,
V_434 ) ;
goto V_18;
}
V_6 -> V_128 = V_422 ;
break;
case V_435 :
V_419 = F_159 ( args ) ;
if ( ! V_419 ) {
V_32 = - V_34 ;
goto V_18;
}
V_6 -> V_134 = F_82 ( F_160 ( V_419 , NULL , 16 ) ) ;
F_9 ( V_419 ) ;
break;
case V_436 :
if ( F_165 ( args , & V_422 ) || V_422 < 1 || V_422 > 255 ) {
F_161 ( L_64 ,
V_419 ) ;
goto V_18;
}
V_6 -> V_244 = V_422 ;
break;
case V_437 :
if ( F_165 ( args , & V_422 ) ) {
F_161 ( L_65 , V_419 ) ;
goto V_18;
}
V_6 -> V_245 = ! ! V_422 ;
break;
case V_438 :
if ( F_165 ( args , & V_422 ) || V_422 < 1 ||
V_422 > V_439 ) {
F_161 ( L_66 ,
V_419 ) ;
goto V_18;
}
V_6 -> V_440 = V_422 ;
break;
case V_441 :
if ( F_165 ( args , & V_422 ) || V_422 < 0 ) {
F_161 ( L_67 , V_419 ) ;
goto V_18;
}
V_6 -> V_60 = V_422 ;
break;
default:
F_161 ( L_68 ,
V_419 ) ;
goto V_18;
}
}
if ( ( V_421 & V_442 ) == V_442 )
V_32 = 0 ;
else
for ( V_79 = 0 ; V_79 < F_166 ( V_423 ) ; ++ V_79 )
if ( ( V_423 [ V_79 ] . V_422 & V_442 ) &&
! ( V_423 [ V_79 ] . V_422 & V_421 ) )
F_161 ( L_69 ,
V_423 [ V_79 ] . V_443 ) ;
V_18:
F_9 ( V_417 ) ;
return V_32 ;
}
static T_10 F_167 ( struct V_323 * V_23 ,
struct V_158 * V_31 ,
const char * V_19 , T_2 V_231 )
{
struct V_12 * V_3 =
F_59 ( V_23 , struct V_12 , V_23 ) ;
struct V_2 * V_444 ;
struct V_1 * V_6 ;
struct V_146 * V_147 = V_3 -> V_22 -> V_23 ;
T_5 V_196 ;
int V_79 , V_32 ;
V_444 = F_168 ( & V_445 ,
sizeof ( struct V_1 ) ) ;
if ( ! V_444 )
return - V_34 ;
V_444 -> V_446 = V_447 ;
V_444 -> V_448 = 0 ;
V_444 -> V_449 = 1 ;
V_444 -> V_450 = V_451 ;
V_444 -> V_452 = sizeof ( (struct V_228 * ) ( void * ) 0L ) -> V_325 ;
V_6 = F_1 ( V_444 ) ;
V_6 -> V_128 = V_434 ;
V_6 -> V_87 = V_444 ;
V_6 -> V_12 = V_3 ;
V_6 -> V_265 = V_3 -> V_22 -> V_453 -> V_265 ;
V_6 -> V_198 = V_3 -> V_22 -> V_453 -> V_198 ;
V_6 -> V_244 = V_454 ;
V_6 -> V_440 = V_455 ? : V_454 ;
V_6 -> V_245 = V_245 ;
V_32 = F_155 ( V_19 , V_6 ) ;
if ( V_32 )
goto V_61;
if ( ! F_153 ( V_6 -> V_12 , V_6 ) ) {
F_31 ( V_194 , V_6 -> V_87 ,
V_88 L_70 ,
F_41 ( V_6 -> V_136 ) ,
F_41 ( V_6 -> V_10 ) ,
F_41 ( V_6 -> V_134 ) ) ;
V_32 = - V_456 ;
goto V_61;
}
if ( ! V_3 -> V_22 -> V_212 && ! V_6 -> V_245 &&
V_6 -> V_244 < V_6 -> V_440 ) {
F_161 ( L_71 ) ;
V_6 -> V_440 = V_6 -> V_244 ;
}
V_444 -> V_440 = V_6 -> V_440 ;
V_6 -> V_154 = V_6 -> V_440 *
sizeof ( struct V_199 ) ;
V_6 -> V_124 = sizeof ( struct V_228 ) +
sizeof ( struct V_232 ) +
V_6 -> V_244 * sizeof ( struct V_199 ) ;
F_169 ( & V_6 -> V_144 , F_58 ) ;
F_170 ( & V_6 -> V_140 ) ;
F_78 ( & V_6 -> V_190 ) ;
F_78 ( & V_6 -> V_185 ) ;
for ( V_79 = 0 ; V_79 < V_150 ; ++ V_79 ) {
struct V_148 * V_105 = & V_6 -> V_149 [ V_79 ] ;
V_105 -> V_151 = F_5 ( V_6 -> V_244 * sizeof ( void * ) ,
V_33 ) ;
V_105 -> V_152 = F_5 ( V_225 * sizeof ( void * ) ,
V_33 ) ;
V_105 -> V_156 = F_5 ( V_6 -> V_154 , V_33 ) ;
if ( ! V_105 -> V_151 || ! V_105 -> V_152 || ! V_105 -> V_156 )
goto V_457;
V_196 = F_7 ( V_147 , V_105 -> V_156 ,
V_6 -> V_154 ,
V_155 ) ;
if ( F_8 ( V_147 , V_196 ) )
goto V_457;
V_105 -> V_153 = V_196 ;
V_105 -> V_324 = V_79 ;
F_74 ( & V_105 -> V_165 , & V_6 -> V_185 ) ;
}
F_171 ( V_147 , V_3 -> V_35 , 0 , & V_6 -> V_36 . V_131 ) ;
F_31 ( V_137 , V_6 -> V_87 , V_88
L_72
L_73 ,
( unsigned long long ) F_41 ( V_6 -> V_136 ) ,
( unsigned long long ) F_41 ( V_6 -> V_10 ) ,
F_16 ( V_6 -> V_36 . V_37 ) ,
( unsigned long long ) F_41 ( V_6 -> V_108 ) ,
V_6 -> V_36 . V_360 . V_361 ) ;
V_32 = F_23 ( V_6 ) ;
if ( V_32 )
goto V_457;
V_32 = F_18 ( V_6 ) ;
if ( V_32 )
goto V_458;
V_32 = F_64 ( V_6 ) ;
if ( V_32 ) {
F_31 ( V_86 , V_6 -> V_87 ,
V_88 L_74 ) ;
goto V_459;
}
V_32 = F_148 ( V_3 , V_6 ) ;
if ( V_32 )
goto V_460;
return V_231 ;
V_460:
F_48 ( V_6 ) ;
V_459:
F_22 ( V_6 -> V_52 ) ;
V_458:
F_29 ( V_6 ) ;
V_457:
F_50 ( V_6 ) ;
V_61:
F_57 ( V_444 ) ;
return V_32 ;
}
static T_10 F_172 ( struct V_323 * V_23 , struct V_158 * V_31 ,
char * V_19 )
{
struct V_12 * V_3 = F_59 ( V_23 , struct V_12 , V_23 ) ;
return sprintf ( V_19 , L_52 , V_3 -> V_22 -> V_23 -> V_403 ) ;
}
static T_10 F_173 ( struct V_323 * V_23 , struct V_158 * V_31 ,
char * V_19 )
{
struct V_12 * V_3 = F_59 ( V_23 , struct V_12 , V_23 ) ;
return sprintf ( V_19 , L_51 , V_3 -> V_35 ) ;
}
static struct V_12 * F_174 ( struct V_206 * V_323 , T_1 V_35 )
{
struct V_12 * V_3 ;
V_3 = F_6 ( sizeof *V_3 , V_33 ) ;
if ( ! V_3 )
return NULL ;
F_78 ( & V_3 -> V_411 ) ;
F_170 ( & V_3 -> V_164 ) ;
F_34 ( & V_3 -> V_415 ) ;
V_3 -> V_22 = V_323 ;
V_3 -> V_35 = V_35 ;
V_3 -> V_23 . V_461 = & V_462 ;
V_3 -> V_23 . V_463 = V_323 -> V_23 -> V_406 ;
F_175 ( & V_3 -> V_23 , L_75 , V_323 -> V_23 -> V_403 , V_35 ) ;
if ( F_176 ( & V_3 -> V_23 ) )
goto V_464;
if ( F_177 ( & V_3 -> V_23 , & V_465 ) )
goto V_466;
if ( F_177 ( & V_3 -> V_23 , & V_467 ) )
goto V_466;
if ( F_177 ( & V_3 -> V_23 , & V_468 ) )
goto V_466;
return V_3 ;
V_466:
F_178 ( & V_3 -> V_23 ) ;
V_464:
F_9 ( V_3 ) ;
return NULL ;
}
static void F_179 ( struct V_146 * V_323 )
{
struct V_206 * V_22 ;
struct V_469 * V_470 ;
struct V_471 V_472 ;
struct V_12 * V_3 ;
int V_473 , V_474 , V_475 , V_476 , V_419 ;
V_470 = F_5 ( sizeof *V_470 , V_33 ) ;
if ( ! V_470 )
return;
if ( F_180 ( V_323 , V_470 ) ) {
F_161 ( L_76 , V_323 -> V_403 ) ;
goto V_477;
}
V_22 = F_5 ( sizeof *V_22 , V_33 ) ;
if ( ! V_22 )
goto V_477;
V_474 = F_181 ( 12 , F_182 ( V_470 -> V_478 ) - 1 ) ;
V_22 -> V_226 = 1 << V_474 ;
V_22 -> V_223 = ~ ( ( T_7 ) V_22 -> V_226 - 1 ) ;
V_22 -> V_224 = V_22 -> V_226 * V_225 ;
F_78 ( & V_22 -> V_479 ) ;
V_22 -> V_23 = V_323 ;
V_22 -> V_76 = F_183 ( V_323 ) ;
if ( F_20 ( V_22 -> V_76 ) )
goto V_480;
V_22 -> V_453 = F_184 ( V_22 -> V_76 ,
V_481 |
V_42 |
V_43 ) ;
if ( F_20 ( V_22 -> V_453 ) )
goto V_482;
for ( V_473 = V_225 ;
V_473 >= V_483 ;
V_473 /= 2 , V_22 -> V_224 /= 2 ) {
memset ( & V_472 , 0 , sizeof V_472 ) ;
V_472 . V_484 = V_485 ;
V_472 . V_486 = V_487 ;
V_472 . V_488 = 1 ;
V_472 . V_473 = V_473 ;
V_472 . V_489 = V_474 ;
V_472 . V_490 = ( V_481 |
V_43 |
V_42 ) ;
V_22 -> V_212 = F_185 ( V_22 -> V_76 , & V_472 ) ;
if ( ! F_20 ( V_22 -> V_212 ) )
break;
}
if ( F_20 ( V_22 -> V_212 ) )
V_22 -> V_212 = NULL ;
if ( V_323 -> V_491 == V_492 ) {
V_475 = 0 ;
V_476 = 0 ;
} else {
V_475 = 1 ;
V_476 = V_323 -> V_493 ;
}
for ( V_419 = V_475 ; V_419 <= V_476 ; ++ V_419 ) {
V_3 = F_174 ( V_22 , V_419 ) ;
if ( V_3 )
F_74 ( & V_3 -> V_165 , & V_22 -> V_479 ) ;
}
F_186 ( V_323 , & V_494 , V_22 ) ;
goto V_477;
V_482:
F_187 ( V_22 -> V_76 ) ;
V_480:
F_9 ( V_22 ) ;
V_477:
F_9 ( V_470 ) ;
}
static void F_188 ( struct V_146 * V_323 )
{
struct V_206 * V_22 ;
struct V_12 * V_3 , * V_495 ;
struct V_1 * V_6 ;
V_22 = F_189 ( V_323 , & V_494 ) ;
if ( ! V_22 )
return;
F_190 (host, tmp_host, &srp_dev->dev_list, list) {
F_178 ( & V_3 -> V_23 ) ;
F_36 ( & V_3 -> V_415 ) ;
F_60 ( & V_3 -> V_164 ) ;
F_154 (target, &host->target_list, list)
F_43 ( V_6 ) ;
F_62 ( & V_3 -> V_164 ) ;
F_191 ( V_143 ) ;
F_9 ( V_3 ) ;
}
if ( V_22 -> V_212 )
F_192 ( V_22 -> V_212 ) ;
F_193 ( V_22 -> V_453 ) ;
F_187 ( V_22 -> V_76 ) ;
F_9 ( V_22 ) ;
}
static int T_12 F_194 ( void )
{
int V_32 ;
F_195 ( F_196 ( struct V_302 , V_267 ) < sizeof( void * ) ) ;
if ( V_496 ) {
F_161 ( L_77 ) ;
if ( ! V_454 )
V_454 = V_496 ;
}
if ( ! V_454 )
V_454 = V_497 ;
if ( V_454 > 255 ) {
F_161 ( L_78 ) ;
V_454 = 255 ;
}
if ( ! V_455 )
V_455 = V_454 ;
else if ( V_455 < V_454 ) {
F_161 ( L_79 ,
V_454 ) ;
V_455 = V_454 ;
}
V_447 =
F_197 ( & V_498 ) ;
if ( ! V_447 )
return - V_34 ;
V_32 = F_198 ( & V_462 ) ;
if ( V_32 ) {
F_199 ( L_80 ) ;
F_200 ( V_447 ) ;
return V_32 ;
}
F_201 ( & V_92 ) ;
V_32 = F_202 ( & V_494 ) ;
if ( V_32 ) {
F_199 ( L_81 ) ;
F_200 ( V_447 ) ;
F_203 ( & V_92 ) ;
F_204 ( & V_462 ) ;
return V_32 ;
}
return 0 ;
}
static void T_13 F_205 ( void )
{
F_206 ( & V_494 ) ;
F_203 ( & V_92 ) ;
F_204 ( & V_462 ) ;
F_200 ( V_447 ) ;
}
