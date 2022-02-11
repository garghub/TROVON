static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_4 = V_3 -> V_4 ;
struct V_5 * V_5 = V_3 -> V_5 ;
F_3 ( V_3 -> V_6 , L_1 ,
V_7 , V_3 -> div , V_3 -> V_8 ) ;
F_4 ( V_5 , V_9 ,
F_5 ( V_4 ) | F_6 ( V_4 ) ,
( V_3 -> div << F_7 ( V_4 ) ) |
( V_3 -> V_8 << F_8 ( V_4 ) ) ) ;
F_9 ( V_5 , V_10 , F_10 ( V_4 ) ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_4 = V_3 -> V_4 ;
F_9 ( V_3 -> V_5 , V_11 , F_10 ( V_4 ) ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_12 ;
F_13 ( V_3 -> V_5 , V_13 , & V_12 ) ;
return V_12 & F_10 ( V_3 -> V_4 ) ? 1 : 0 ;
}
static unsigned long
F_14 ( struct V_1 * V_2 , unsigned long V_14 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return F_15 ( V_14 , V_3 -> div + 1 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
long V_17 = - V_18 ;
int V_19 = - 1 ;
unsigned int V_20 , div ;
for ( V_20 = 0 ; V_20 < F_17 ( V_2 ) ; V_20 ++ ) {
struct V_1 * V_21 ;
unsigned long V_14 ;
V_21 = F_18 ( V_2 , V_20 ) ;
if ( ! V_21 )
continue;
V_14 = F_19 ( V_21 ) ;
if ( ! V_14 )
continue;
for ( div = 1 ; div < V_22 + 2 ; div ++ ) {
unsigned long V_23 ;
int V_24 ;
V_23 = F_15 ( V_14 , div ) ;
V_24 = abs ( V_16 -> V_23 - V_23 ) ;
if ( V_19 < 0 || V_19 > V_24 ) {
V_17 = V_23 ;
V_19 = V_24 ;
V_16 -> V_25 = V_14 ;
V_16 -> V_26 = V_21 ;
}
if ( ! V_19 || V_23 < V_16 -> V_23 )
break;
}
if ( ! V_19 )
break;
}
F_3 ( V_3 -> V_6 ,
L_2 ,
V_7 , V_17 ,
F_20 ( ( V_16 -> V_26 ) -> V_27 ) ,
V_16 -> V_25 ) ;
if ( V_17 < 0 )
return V_17 ;
V_16 -> V_23 = V_17 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_28 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_28 >= F_17 ( V_2 ) )
return - V_18 ;
V_3 -> V_8 = V_28 ;
return 0 ;
}
static T_2 F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return V_3 -> V_8 ;
}
static int F_23 ( struct V_1 * V_2 ,
unsigned long V_23 ,
unsigned long V_14 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 div ;
if ( ! V_23 )
return - V_18 ;
div = F_15 ( V_14 , V_23 ) ;
if ( div > ( V_22 + 1 ) || ! div )
return - V_18 ;
V_3 -> div = div - 1 ;
return 0 ;
}
static int F_24 ( struct V_29 * V_30 , unsigned int V_4 )
{
struct V_5 * V_5 = V_30 -> V_5 ;
struct V_31 * V_32 = V_30 -> V_6 -> V_33 ;
struct V_3 * V_3 ;
struct V_34 V_35 ;
const char * V_36 = V_32 -> V_37 ;
const char * V_38 [ 3 ] ;
int V_39 ;
V_39 = F_25 ( V_32 ) ;
if ( V_39 < 1 || V_39 > 3 )
return - V_18 ;
if ( V_39 > 2 && V_4 == V_40 )
V_39 = 2 ;
F_26 ( V_32 , V_38 , V_39 ) ;
if ( V_4 == V_41 )
F_27 ( V_32 , L_3 , & V_36 ) ;
else
V_36 = L_4 ;
V_35 . V_38 = V_38 ;
V_35 . V_39 = V_39 ;
V_35 . V_37 = V_36 ;
V_35 . V_42 = & V_43 ;
V_35 . V_44 = V_45 | V_46 ;
V_3 = & V_30 -> V_47 [ V_4 ] ;
V_3 -> V_2 . V_35 = & V_35 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_6 = V_30 -> V_6 ;
V_3 -> V_27 = F_28 ( V_30 -> V_6 , & V_3 -> V_2 ) ;
if ( F_29 ( V_3 -> V_27 ) ) {
F_30 ( V_30 -> V_6 , L_5 , V_36 ) ;
return F_31 ( V_3 -> V_27 ) ;
} else if ( V_4 == V_41 )
F_32 ( V_32 , V_48 , V_3 -> V_27 ) ;
return 0 ;
}
static int F_33 ( struct V_29 * V_30 )
{
unsigned int V_20 ;
int V_49 ;
for ( V_20 = 0 ; V_20 < F_34 ( V_30 -> V_47 ) ; V_20 ++ )
V_30 -> V_47 [ V_20 ] . V_27 = F_35 ( - V_18 ) ;
for ( V_20 = 0 ; V_20 < F_34 ( V_30 -> V_47 ) ; V_20 ++ ) {
V_49 = F_24 ( V_30 , V_20 ) ;
if ( V_49 )
return V_49 ;
}
return 0 ;
}
static void F_36 ( struct V_29 * V_30 )
{
unsigned int V_20 ;
F_37 ( V_30 -> V_6 -> V_33 ) ;
for ( V_20 = 0 ; V_20 < F_34 ( V_30 -> V_47 ) ; V_20 ++ ) {
struct V_3 * V_3 = & V_30 -> V_47 [ V_20 ] ;
if ( ! F_29 ( V_3 -> V_27 ) )
F_38 ( V_3 -> V_27 ) ;
}
}
static int F_39 ( struct V_50 * V_51 ,
unsigned int * V_52 , unsigned int * V_53 ,
unsigned int V_54 [] , struct V_55 * V_56 [] )
{
struct V_29 * V_30 = F_40 ( V_51 ) ;
unsigned int V_57 = V_30 -> V_58 . V_58 . V_59 . V_60 ;
if ( * V_53 )
return V_54 [ 0 ] < V_57 ? - V_18 : 0 ;
* V_53 = 1 ;
V_54 [ 0 ] = V_57 ;
return 0 ;
}
static int F_41 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_42 ( V_62 ) ;
struct V_29 * V_30 = F_40 ( V_62 -> V_50 ) ;
unsigned long V_57 = V_30 -> V_58 . V_58 . V_59 . V_60 ;
if ( F_43 ( V_62 , 0 ) < V_57 ) {
F_44 ( & V_30 -> V_65 , L_6 ,
F_43 ( V_62 , 0 ) , V_57 ) ;
return - V_18 ;
}
F_45 ( V_62 , 0 , V_57 ) ;
V_64 -> V_66 = V_30 -> V_58 . V_58 . V_59 . V_66 ;
return 0 ;
}
static inline bool F_46 ( const struct V_67 * V_68 )
{
return ( V_69 && V_68 -> V_70 ) ||
! V_68 -> V_71 ;
}
static void F_47 ( struct V_29 * V_30 )
{
struct V_5 * V_5 = V_30 -> V_5 ;
struct V_72 * V_73 = & V_30 -> V_58 . V_58 . V_59 ;
T_1 V_60 = V_73 -> V_60 ;
T_1 V_74 ;
T_3 V_75 ;
V_75 = F_48 ( & V_30 -> V_76 -> V_62 . V_77 , 0 ) ;
F_9 ( V_5 , V_78 , V_75 ) ;
switch ( V_73 -> V_79 ) {
case V_80 :
F_9 ( V_5 , V_81 , V_75 + ( V_60 * 2 ) / 3 ) ;
F_9 ( V_5 , V_82 , V_75 + ( V_60 * 5 ) / 6 ) ;
break;
case V_83 :
F_9 ( V_5 , V_81 , V_75 + V_60 / 2 ) ;
F_9 ( V_5 , V_82 , V_75 + ( V_60 * 3 ) / 4 ) ;
break;
default:
break;
}
if ( F_46 ( V_30 -> V_84 ) )
V_74 = V_85 ;
else
V_74 = V_30 -> V_84 -> V_86 ;
F_9 ( V_5 , V_87 , V_74 | V_88 ) ;
F_9 ( V_5 , V_89 , V_90 ) ;
}
static void F_49 ( struct V_29 * V_30 , T_1 V_91 )
{
struct V_5 * V_5 = V_30 -> V_5 ;
struct V_92 * V_93 = & V_30 -> V_93 ;
T_1 V_94 , V_95 ;
const T_1 * gamma ;
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < V_96 ; V_20 ++ ) {
V_94 = V_91 & F_50 ( V_20 ) ? 1 : 0 ;
F_51 ( V_30 -> V_91 [ V_20 ] , V_94 ) ;
}
if ( ! V_91 )
return;
V_95 = V_30 -> V_97 -> V_98 ;
F_9 ( V_5 , V_99 , V_95 ) ;
F_9 ( V_5 , V_100 , 0x0 ) ;
F_9 ( V_5 , V_101 , 0x0 ) ;
F_9 ( V_5 , V_102 , V_93 -> V_103 | ( 0x1 << 25 ) ) ;
F_9 ( V_5 , V_104 , V_93 -> V_105 | ( 0x1 << 25 ) ) ;
F_9 ( V_5 , V_106 , V_95 | V_107 ) ;
gamma = & V_108 [ V_93 -> V_109 ] [ 0 ] ;
F_52 ( V_5 , V_110 , gamma , V_111 ) ;
F_52 ( V_5 , V_112 , gamma , V_111 ) ;
F_52 ( V_5 , V_113 , gamma , V_111 ) ;
F_9 ( V_5 , V_114 , 0x42 | ( 0x81 << 16 ) ) ;
F_9 ( V_5 , V_115 , 0x19 | ( 0x10 << 16 ) ) ;
F_9 ( V_5 , V_116 , 0xFDA | ( 0xFB6 << 16 ) ) ;
F_9 ( V_5 , V_117 , 0x70 | ( 0x80 << 16 ) ) ;
F_9 ( V_5 , V_118 , 0x70 | ( 0xFA2 << 16 ) ) ;
F_9 ( V_5 , V_119 , 0xFEE | ( 0x80 << 16 ) ) ;
F_9 ( V_5 , V_120 , V_93 -> V_121 ) ;
F_9 ( V_5 , V_122 , V_93 -> V_123 ) ;
}
static int F_53 ( struct V_29 * V_30 )
{
struct V_5 * V_5 = V_30 -> V_5 ;
T_1 V_124 ;
int V_125 = 100 ;
F_9 ( V_5 , V_89 , V_126 ) ;
F_13 ( V_5 , V_127 , & V_124 ) ;
while ( ( V_124 & V_126 ) && V_125 -- ) {
F_54 ( 1000 , 2000 ) ;
F_13 ( V_5 , V_127 , & V_124 ) ;
}
if ( V_125 < 0 ) {
F_55 ( & V_30 -> V_65 , L_7 ) ;
return - V_128 ;
}
return 0 ;
}
static void F_56 ( struct V_29 * V_30 )
{
struct V_5 * V_5 = V_30 -> V_5 ;
struct V_92 * V_93 = & V_30 -> V_93 ;
if ( V_93 -> V_129 && ( V_93 -> V_130 != V_131 ) ) {
F_9 ( V_5 , V_132 , V_133 |
( V_30 -> V_97 -> V_98 << V_134 ) |
V_135 ) ;
F_9 ( V_5 , V_136 , V_137 ) ;
F_9 ( V_5 , V_138 , V_139 ) ;
V_93 -> V_140 = V_133 ;
F_53 ( V_30 ) ;
F_9 ( V_5 , V_89 , V_141 ) ;
V_93 -> V_130 = V_131 ;
} else if ( ! V_93 -> V_129 && ( V_93 -> V_130 != V_142 ) ) {
F_9 ( V_5 , V_143 , V_139 ) ;
F_9 ( V_5 , V_136 , V_144 ) ;
V_93 -> V_130 = V_142 ;
}
}
static inline void F_57 ( const struct V_67 * V_58 ,
T_1 * V_145 , T_1 * V_146 )
{
switch ( V_58 -> V_147 ) {
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
* V_145 = V_58 -> V_156 ;
* V_146 = V_58 -> V_157 ;
break;
default:
* V_145 = V_158 ;
* V_146 = V_159 ;
break;
}
}
static int F_58 ( struct V_29 * V_30 )
{
struct V_5 * V_5 = V_30 -> V_5 ;
const struct V_67 * V_84 = V_30 -> V_84 ;
struct V_160 * V_161 = V_30 -> V_162 ;
T_1 V_163 , V_145 , V_146 , V_164 , V_91 ;
if ( F_46 ( V_84 ) ) {
V_163 = V_84 -> V_165 ;
V_91 = 0x0 ;
F_57 ( V_84 , & V_145 , & V_146 ) ;
V_30 -> V_93 . V_130 = V_166 ;
} else {
V_163 = V_30 -> V_97 -> V_165 ;
V_91 = V_84 -> V_91 ;
V_145 = V_84 -> V_156 ;
V_146 = V_84 -> V_157 ;
}
V_163 |= V_161 -> V_163 | V_167 ;
V_164 = V_168 | V_169 |
V_170 | V_171 |
V_172 ;
F_4 ( V_5 , V_173 , V_164 , V_163 ) ;
F_4 ( V_5 , V_174 , V_175 ,
V_145 ) ;
F_4 ( V_5 , V_176 , V_177 , V_146 ) ;
F_49 ( V_30 , V_91 ) ;
if ( V_91 )
F_56 ( V_30 ) ;
return F_53 ( V_30 ) ;
}
static int F_59 ( struct V_50 * V_51 , unsigned int V_178 )
{
struct V_29 * V_30 = F_40 ( V_51 ) ;
struct V_5 * V_5 = V_30 -> V_5 ;
struct V_179 * V_180 ;
unsigned long V_44 ;
int V_49 ;
V_49 = F_60 ( V_30 -> V_162 -> V_181 , V_182 , V_183 , 1 ) ;
if ( V_49 && V_49 != - V_184 ) {
F_44 ( & V_30 -> V_65 , L_8 ) ;
goto V_185;
}
F_61 ( V_30 -> V_6 ) ;
V_49 = F_58 ( V_30 ) ;
if ( F_62 ( V_49 ) )
goto V_186;
F_9 ( V_5 , V_138 , V_187 ) ;
F_63 ( & V_30 -> V_188 , V_44 ) ;
V_30 -> V_189 = 0 ;
V_30 -> V_190 = false ;
F_64 ( & V_30 -> V_191 ) ;
V_30 -> V_76 = F_65 ( & V_30 -> V_192 ,
struct V_179 , V_193 ) ;
F_66 ( & V_30 -> V_76 -> V_193 ) ;
F_47 ( V_30 ) ;
F_67 ( & V_30 -> V_188 , V_44 ) ;
return 0 ;
V_186:
F_68 ( V_30 -> V_6 ) ;
F_60 ( V_30 -> V_162 -> V_181 , V_182 , V_183 , 0 ) ;
V_185:
F_63 ( & V_30 -> V_188 , V_44 ) ;
F_69 (buf, &isc->dma_queue, list)
F_70 ( & V_180 -> V_62 . V_77 , V_194 ) ;
F_71 ( & V_30 -> V_192 ) ;
F_67 ( & V_30 -> V_188 , V_44 ) ;
return V_49 ;
}
static void F_72 ( struct V_50 * V_51 )
{
struct V_29 * V_30 = F_40 ( V_51 ) ;
unsigned long V_44 ;
struct V_179 * V_180 ;
int V_49 ;
V_30 -> V_190 = true ;
if ( V_30 -> V_76 && ! F_73 ( & V_30 -> V_191 , 5 * V_195 ) )
F_44 ( & V_30 -> V_65 ,
L_9 ) ;
F_9 ( V_30 -> V_5 , V_143 , V_187 ) ;
F_68 ( V_30 -> V_6 ) ;
V_49 = F_60 ( V_30 -> V_162 -> V_181 , V_182 , V_183 , 0 ) ;
if ( V_49 && V_49 != - V_184 )
F_44 ( & V_30 -> V_65 , L_10 ) ;
F_63 ( & V_30 -> V_188 , V_44 ) ;
if ( F_62 ( V_30 -> V_76 ) ) {
F_70 ( & V_30 -> V_76 -> V_62 . V_77 ,
V_196 ) ;
V_30 -> V_76 = NULL ;
}
F_69 (buf, &isc->dma_queue, list)
F_70 ( & V_180 -> V_62 . V_77 , V_196 ) ;
F_71 ( & V_30 -> V_192 ) ;
F_67 ( & V_30 -> V_188 , V_44 ) ;
}
static void F_74 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_42 ( V_62 ) ;
struct V_179 * V_180 = F_75 ( V_64 , struct V_179 , V_62 ) ;
struct V_29 * V_30 = F_40 ( V_62 -> V_50 ) ;
unsigned long V_44 ;
F_63 ( & V_30 -> V_188 , V_44 ) ;
if ( ! V_30 -> V_76 && F_76 ( & V_30 -> V_192 ) &&
F_77 ( V_62 -> V_50 ) ) {
V_30 -> V_76 = V_180 ;
F_47 ( V_30 ) ;
} else
F_78 ( & V_180 -> V_193 , & V_30 -> V_192 ) ;
F_67 ( & V_30 -> V_188 , V_44 ) ;
}
static int F_79 ( struct V_197 * V_197 , void * V_198 ,
struct V_199 * V_200 )
{
struct V_29 * V_30 = F_80 ( V_197 ) ;
strcpy ( V_200 -> V_201 , V_202 ) ;
strcpy ( V_200 -> V_203 , L_11 ) ;
snprintf ( V_200 -> V_204 , sizeof( V_200 -> V_204 ) ,
L_12 , V_30 -> V_65 . V_37 ) ;
return 0 ;
}
static int F_81 ( struct V_197 * V_197 , void * V_198 ,
struct V_205 * V_206 )
{
struct V_29 * V_30 = F_80 ( V_197 ) ;
T_1 V_28 = V_206 -> V_28 ;
if ( V_28 >= V_30 -> V_207 )
return - V_18 ;
V_206 -> V_79 = V_30 -> V_208 [ V_28 ] -> V_147 ;
return 0 ;
}
static int F_82 ( struct V_197 * V_197 , void * V_198 ,
struct V_209 * V_58 )
{
struct V_29 * V_30 = F_80 ( V_197 ) ;
* V_58 = V_30 -> V_58 ;
return 0 ;
}
static struct V_67 * F_83 ( struct V_29 * V_30 ,
unsigned int V_147 )
{
unsigned int V_210 = V_30 -> V_207 ;
struct V_67 * V_58 ;
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < V_210 ; V_20 ++ ) {
V_58 = V_30 -> V_208 [ V_20 ] ;
if ( V_58 -> V_147 == V_147 )
return V_58 ;
}
return NULL ;
}
static int F_84 ( struct V_29 * V_30 , struct V_209 * V_206 ,
struct V_67 * * V_84 , T_1 * V_211 )
{
struct V_67 * V_68 ;
struct V_72 * V_73 = & V_206 -> V_58 . V_59 ;
struct V_212 V_213 = {
. V_214 = V_215 ,
} ;
T_1 V_216 ;
int V_49 ;
if ( V_206 -> type != V_217 )
return - V_18 ;
V_68 = F_83 ( V_30 , V_73 -> V_79 ) ;
if ( ! V_68 ) {
F_55 ( & V_30 -> V_65 , L_13 ,
V_73 -> V_79 ) ;
V_68 = V_30 -> V_208 [ V_30 -> V_207 - 1 ] ;
V_73 -> V_79 = V_68 -> V_147 ;
}
if ( V_73 -> V_218 > V_219 )
V_73 -> V_218 = V_219 ;
if ( V_73 -> V_220 > V_221 )
V_73 -> V_220 = V_221 ;
if ( F_46 ( V_68 ) )
V_216 = V_68 -> V_216 ;
else
V_216 = V_30 -> V_97 -> V_216 ;
F_85 ( & V_213 . V_213 , V_73 , V_216 ) ;
V_49 = F_60 ( V_30 -> V_162 -> V_181 , V_222 , V_223 ,
V_30 -> V_162 -> V_224 , & V_213 ) ;
if ( V_49 < 0 )
return V_49 ;
F_86 ( V_73 , & V_213 . V_213 ) ;
V_73 -> V_66 = V_225 ;
V_73 -> V_226 = ( V_73 -> V_218 * V_68 -> V_227 ) >> 3 ;
V_73 -> V_60 = V_73 -> V_226 * V_73 -> V_220 ;
if ( V_84 )
* V_84 = V_68 ;
if ( V_211 )
* V_211 = V_216 ;
return 0 ;
}
static int F_87 ( struct V_29 * V_30 , struct V_209 * V_206 )
{
struct V_212 V_213 = {
. V_214 = V_228 ,
} ;
struct V_67 * V_84 ;
T_1 V_216 ;
int V_49 ;
V_49 = F_84 ( V_30 , V_206 , & V_84 , & V_216 ) ;
if ( V_49 )
return V_49 ;
F_85 ( & V_213 . V_213 , & V_206 -> V_58 . V_59 , V_216 ) ;
V_49 = F_60 ( V_30 -> V_162 -> V_181 , V_222 ,
V_223 , NULL , & V_213 ) ;
if ( V_49 < 0 )
return V_49 ;
V_30 -> V_58 = * V_206 ;
V_30 -> V_84 = V_84 ;
return 0 ;
}
static int F_88 ( struct V_197 * V_197 , void * V_198 ,
struct V_209 * V_206 )
{
struct V_29 * V_30 = F_80 ( V_197 ) ;
if ( F_77 ( & V_30 -> V_229 ) )
return - V_230 ;
return F_87 ( V_30 , V_206 ) ;
}
static int F_89 ( struct V_197 * V_197 , void * V_198 ,
struct V_209 * V_206 )
{
struct V_29 * V_30 = F_80 ( V_197 ) ;
return F_84 ( V_30 , V_206 , NULL , NULL ) ;
}
static int F_90 ( struct V_197 * V_197 , void * V_198 ,
struct V_231 * V_232 )
{
if ( V_232 -> V_28 != 0 )
return - V_18 ;
V_232 -> type = V_233 ;
V_232 -> V_234 = 0 ;
strcpy ( V_232 -> V_37 , L_14 ) ;
return 0 ;
}
static int F_91 ( struct V_197 * V_197 , void * V_198 , unsigned int * V_20 )
{
* V_20 = 0 ;
return 0 ;
}
static int F_92 ( struct V_197 * V_197 , void * V_198 , unsigned int V_20 )
{
if ( V_20 > 0 )
return - V_18 ;
return 0 ;
}
static int F_93 ( struct V_197 * V_197 , void * V_235 , struct V_236 * V_237 )
{
struct V_29 * V_30 = F_80 ( V_197 ) ;
if ( V_237 -> type != V_217 )
return - V_18 ;
return F_60 ( V_30 -> V_162 -> V_181 , V_182 , V_238 , V_237 ) ;
}
static int F_94 ( struct V_197 * V_197 , void * V_235 , struct V_236 * V_237 )
{
struct V_29 * V_30 = F_80 ( V_197 ) ;
if ( V_237 -> type != V_217 )
return - V_18 ;
return F_60 ( V_30 -> V_162 -> V_181 , V_182 , V_239 , V_237 ) ;
}
static int F_95 ( struct V_197 * V_197 , void * V_235 ,
struct V_240 * V_241 )
{
struct V_29 * V_30 = F_80 ( V_197 ) ;
const struct V_67 * V_68 ;
struct V_242 V_243 = {
. V_28 = V_241 -> V_28 ,
. V_214 = V_228 ,
} ;
int V_49 ;
V_68 = F_83 ( V_30 , V_241 -> V_244 ) ;
if ( ! V_68 )
return - V_18 ;
if ( F_46 ( V_68 ) )
V_243 . V_211 = V_68 -> V_216 ;
else
V_243 . V_211 = V_30 -> V_97 -> V_216 ;
V_49 = F_60 ( V_30 -> V_162 -> V_181 , V_222 , V_245 ,
NULL , & V_243 ) ;
if ( V_49 )
return V_49 ;
V_241 -> type = V_246 ;
V_241 -> V_247 . V_218 = V_243 . V_248 ;
V_241 -> V_247 . V_220 = V_243 . V_249 ;
return 0 ;
}
static int F_96 ( struct V_197 * V_197 , void * V_235 ,
struct V_250 * V_251 )
{
struct V_29 * V_30 = F_80 ( V_197 ) ;
const struct V_67 * V_68 ;
struct V_252 V_253 = {
. V_28 = V_251 -> V_28 ,
. V_218 = V_251 -> V_218 ,
. V_220 = V_251 -> V_220 ,
. V_214 = V_228 ,
} ;
int V_49 ;
V_68 = F_83 ( V_30 , V_251 -> V_244 ) ;
if ( ! V_68 )
return - V_18 ;
if ( F_46 ( V_68 ) )
V_253 . V_211 = V_68 -> V_216 ;
else
V_253 . V_211 = V_30 -> V_97 -> V_216 ;
V_49 = F_60 ( V_30 -> V_162 -> V_181 , V_222 ,
V_254 , NULL , & V_253 ) ;
if ( V_49 )
return V_49 ;
V_251 -> type = V_255 ;
V_251 -> V_247 = V_253 . V_256 ;
return 0 ;
}
static int F_97 ( struct V_197 * V_197 )
{
struct V_29 * V_30 = F_80 ( V_197 ) ;
struct V_257 * V_181 = V_30 -> V_162 -> V_181 ;
int V_49 ;
if ( F_98 ( & V_30 -> V_258 ) )
return - V_259 ;
V_49 = F_99 ( V_197 ) ;
if ( V_49 < 0 )
goto V_260;
if ( ! F_100 ( V_197 ) )
goto V_260;
V_49 = F_60 ( V_181 , V_261 , V_262 , 1 ) ;
if ( V_49 < 0 && V_49 != - V_184 ) {
F_101 ( V_197 ) ;
goto V_260;
}
V_49 = F_87 ( V_30 , & V_30 -> V_58 ) ;
if ( V_49 ) {
F_60 ( V_181 , V_261 , V_262 , 0 ) ;
F_101 ( V_197 ) ;
}
V_260:
F_102 ( & V_30 -> V_258 ) ;
return V_49 ;
}
static int F_103 ( struct V_197 * V_197 )
{
struct V_29 * V_30 = F_80 ( V_197 ) ;
struct V_257 * V_181 = V_30 -> V_162 -> V_181 ;
bool V_263 ;
int V_49 ;
F_104 ( & V_30 -> V_258 ) ;
V_263 = F_100 ( V_197 ) ;
V_49 = F_105 ( V_197 , NULL ) ;
if ( V_263 )
F_60 ( V_181 , V_261 , V_262 , 0 ) ;
F_102 ( & V_30 -> V_258 ) ;
return V_49 ;
}
static T_4 F_106 ( int V_264 , void * V_265 )
{
struct V_29 * V_30 = (struct V_29 * ) V_265 ;
struct V_5 * V_5 = V_30 -> V_5 ;
T_1 V_266 , V_267 , V_268 ;
T_4 V_49 = V_269 ;
F_13 ( V_5 , V_270 , & V_266 ) ;
F_13 ( V_5 , V_271 , & V_267 ) ;
V_268 = V_266 & V_267 ;
if ( F_107 ( V_268 & V_187 ) ) {
F_108 ( & V_30 -> V_188 ) ;
if ( V_30 -> V_76 ) {
struct V_63 * V_64 = & V_30 -> V_76 -> V_62 ;
struct V_61 * V_62 = & V_64 -> V_77 ;
V_62 -> V_272 = F_109 () ;
V_64 -> V_189 = V_30 -> V_189 ++ ;
F_70 ( V_62 , V_273 ) ;
V_30 -> V_76 = NULL ;
}
if ( ! F_76 ( & V_30 -> V_192 ) && ! V_30 -> V_190 ) {
V_30 -> V_76 = F_65 ( & V_30 -> V_192 ,
struct V_179 , V_193 ) ;
F_66 ( & V_30 -> V_76 -> V_193 ) ;
F_47 ( V_30 ) ;
}
if ( V_30 -> V_190 )
F_110 ( & V_30 -> V_191 ) ;
V_49 = V_274 ;
F_111 ( & V_30 -> V_188 ) ;
}
if ( V_268 & V_139 ) {
F_112 ( & V_30 -> V_275 ) ;
V_49 = V_274 ;
}
return V_49 ;
}
static void F_113 ( struct V_29 * V_30 )
{
struct V_5 * V_5 = V_30 -> V_5 ;
struct V_92 * V_93 = & V_30 -> V_93 ;
T_1 * V_276 = & V_93 -> V_276 [ V_93 -> V_140 ] ;
T_1 * V_277 = & V_93 -> V_277 [ 0 ] ;
T_1 V_20 ;
F_114 ( V_5 , V_278 , V_277 , V_279 ) ;
* V_276 = 0 ;
for ( V_20 = 0 ; V_20 < V_279 ; V_20 ++ )
* V_276 += V_20 * ( * V_277 ++ ) ;
}
static void F_115 ( struct V_92 * V_93 )
{
T_1 * V_276 = & V_93 -> V_276 [ 0 ] ;
T_5 V_280 = ( T_5 ) V_276 [ V_281 ] << 9 ;
T_1 V_282 = V_276 [ V_133 ] ;
T_1 V_283 = V_276 [ V_284 ] ;
if ( V_282 )
V_93 -> V_103 = F_116 ( V_280 , V_282 ) ;
if ( V_283 )
V_93 -> V_105 = F_116 ( V_280 , V_283 ) ;
}
static void F_117 ( struct V_285 * V_286 )
{
struct V_29 * V_30 =
F_75 ( V_286 , struct V_29 , V_275 ) ;
struct V_5 * V_5 = V_30 -> V_5 ;
struct V_92 * V_93 = & V_30 -> V_93 ;
T_1 V_140 = V_93 -> V_140 ;
T_1 V_287 ;
if ( V_93 -> V_130 != V_131 )
return;
F_113 ( V_30 ) ;
if ( V_140 != V_284 ) {
V_140 ++ ;
} else {
F_115 ( V_93 ) ;
V_140 = V_133 ;
}
V_93 -> V_140 = V_140 ;
V_287 = V_30 -> V_97 -> V_98 << V_134 ;
F_61 ( V_30 -> V_6 ) ;
F_9 ( V_5 , V_132 , V_140 | V_287 | V_135 ) ;
F_53 ( V_30 ) ;
F_9 ( V_5 , V_89 , V_141 ) ;
F_68 ( V_30 -> V_6 ) ;
}
static int F_118 ( struct V_288 * V_289 )
{
struct V_29 * V_30 = F_75 ( V_289 -> V_290 ,
struct V_29 , V_93 . V_290 ) ;
struct V_92 * V_93 = & V_30 -> V_93 ;
switch ( V_289 -> V_4 ) {
case V_291 :
V_93 -> V_121 = V_289 -> V_94 & V_292 ;
break;
case V_293 :
V_93 -> V_123 = V_289 -> V_94 & V_294 ;
break;
case V_295 :
V_93 -> V_109 = V_289 -> V_94 ;
break;
case V_296 :
V_93 -> V_129 = V_289 -> V_94 ;
if ( V_93 -> V_130 != V_131 ) {
V_93 -> V_103 = 0x1 << 9 ;
V_93 -> V_105 = 0x1 << 9 ;
}
break;
default:
return - V_18 ;
}
return 0 ;
}
static int F_119 ( struct V_29 * V_30 )
{
const struct V_297 * V_42 = & V_298 ;
struct V_92 * V_93 = & V_30 -> V_93 ;
struct V_299 * V_300 = & V_93 -> V_290 ;
int V_49 ;
V_93 -> V_130 = V_166 ;
V_49 = F_120 ( V_300 , 4 ) ;
if ( V_49 < 0 )
return V_49 ;
F_121 ( V_300 , V_42 , V_291 , - 1024 , 1023 , 1 , 0 ) ;
F_121 ( V_300 , V_42 , V_293 , - 2048 , 2047 , 1 , 256 ) ;
F_121 ( V_300 , V_42 , V_295 , 0 , V_301 , 1 , 2 ) ;
F_121 ( V_300 , V_42 , V_296 , 0 , 1 , 1 , 1 ) ;
F_122 ( V_300 ) ;
return 0 ;
}
static int F_123 ( struct V_302 * V_303 ,
struct V_257 * V_161 ,
struct V_304 * V_305 )
{
struct V_29 * V_30 = F_75 ( V_303 -> V_65 ,
struct V_29 , V_65 ) ;
struct V_160 * V_306 =
F_75 ( V_303 , struct V_160 , V_303 ) ;
if ( F_124 ( & V_30 -> V_307 ) ) {
F_44 ( & V_30 -> V_65 , L_15 ) ;
return - V_230 ;
}
V_306 -> V_181 = V_161 ;
return 0 ;
}
static void F_125 ( struct V_302 * V_303 ,
struct V_257 * V_161 ,
struct V_304 * V_305 )
{
struct V_29 * V_30 = F_75 ( V_303 -> V_65 ,
struct V_29 , V_65 ) ;
F_126 ( & V_30 -> V_275 ) ;
F_127 ( & V_30 -> V_307 ) ;
if ( V_30 -> V_162 -> V_224 )
F_128 ( V_30 -> V_162 -> V_224 ) ;
F_129 ( & V_30 -> V_93 . V_290 ) ;
}
static struct V_67 * F_130 ( unsigned int V_211 , int * V_28 )
{
struct V_67 * V_58 = & V_308 [ 0 ] ;
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < F_34 ( V_308 ) ; V_20 ++ ) {
if ( V_58 -> V_216 == V_211 ) {
* V_28 = V_20 ;
return V_58 ;
}
V_58 ++ ;
}
return NULL ;
}
static int F_131 ( struct V_29 * V_30 )
{
struct V_67 * V_58 ;
struct V_257 * V_161 = V_30 -> V_162 -> V_181 ;
unsigned int V_309 , V_20 , V_310 ;
struct V_311 V_216 = {
. V_214 = V_228 ,
} ;
V_58 = & V_308 [ 0 ] ;
for ( V_20 = 0 ; V_20 < F_34 ( V_308 ) ; V_20 ++ ) {
V_58 -> V_71 = false ;
V_58 -> V_70 = false ;
V_58 ++ ;
}
while ( ! F_60 ( V_161 , V_222 , V_312 ,
NULL , & V_216 ) ) {
V_216 . V_28 ++ ;
V_58 = F_130 ( V_216 . V_211 , & V_20 ) ;
if ( ! V_58 )
continue;
V_58 -> V_70 = true ;
if ( V_20 <= V_313 ) {
for ( V_310 = V_314 ; V_310 <= V_315 ; V_310 ++ )
V_308 [ V_310 ] . V_71 = true ;
V_30 -> V_97 = V_58 ;
}
}
V_58 = & V_308 [ 0 ] ;
for ( V_20 = 0 , V_309 = 0 ; V_20 < F_34 ( V_308 ) ; V_20 ++ ) {
if ( V_58 -> V_71 || V_58 -> V_70 )
V_309 ++ ;
V_58 ++ ;
}
if ( ! V_309 )
return - V_316 ;
V_30 -> V_207 = V_309 ;
V_30 -> V_208 = F_132 ( V_30 -> V_6 ,
V_309 , sizeof( struct V_67 * ) ,
V_317 ) ;
if ( ! V_30 -> V_208 ) {
F_44 ( & V_30 -> V_65 , L_16 ) ;
return - V_318 ;
}
V_58 = & V_308 [ 0 ] ;
for ( V_20 = 0 , V_310 = 0 ; V_20 < F_34 ( V_308 ) ; V_20 ++ ) {
if ( V_58 -> V_71 || V_58 -> V_70 )
V_30 -> V_208 [ V_310 ++ ] = V_58 ;
V_58 ++ ;
}
return 0 ;
}
static int F_133 ( struct V_29 * V_30 )
{
struct V_209 V_206 = {
. type = V_217 ,
. V_58 . V_59 = {
. V_218 = V_319 ,
. V_220 = V_320 ,
. V_66 = V_225 ,
. V_79 = V_30 -> V_208 [ 0 ] -> V_147 ,
} ,
} ;
int V_49 ;
V_49 = F_84 ( V_30 , & V_206 , NULL , NULL ) ;
if ( V_49 )
return V_49 ;
V_30 -> V_84 = V_30 -> V_208 [ 0 ] ;
V_30 -> V_58 = V_206 ;
return 0 ;
}
static int F_134 ( struct V_302 * V_303 )
{
struct V_29 * V_30 = F_75 ( V_303 -> V_65 ,
struct V_29 , V_65 ) ;
struct V_160 * V_321 ;
struct V_322 * V_323 = & V_30 -> V_307 ;
struct V_50 * V_324 = & V_30 -> V_229 ;
int V_49 ;
V_49 = F_135 ( & V_30 -> V_65 ) ;
if ( V_49 < 0 ) {
F_44 ( & V_30 -> V_65 , L_17 ) ;
return V_49 ;
}
V_30 -> V_162 = F_75 ( V_303 ,
struct V_160 , V_303 ) ;
V_321 = V_30 -> V_162 ;
F_136 ( & V_30 -> V_258 ) ;
F_137 ( & V_30 -> V_191 ) ;
V_324 -> type = V_217 ;
V_324 -> V_325 = V_326 | V_327 | V_328 ;
V_324 -> V_329 = V_30 ;
V_324 -> V_330 = sizeof( struct V_179 ) ;
V_324 -> V_42 = & V_331 ;
V_324 -> V_332 = & V_333 ;
V_324 -> V_334 = V_335 ;
V_324 -> V_258 = & V_30 -> V_258 ;
V_324 -> V_336 = 1 ;
V_324 -> V_6 = V_30 -> V_6 ;
V_49 = F_138 ( V_324 ) ;
if ( V_49 < 0 ) {
F_44 ( & V_30 -> V_65 ,
L_18 , V_49 ) ;
return V_49 ;
}
F_71 ( & V_30 -> V_192 ) ;
F_139 ( & V_30 -> V_188 ) ;
V_321 -> V_224 = F_140 ( V_321 -> V_181 ) ;
if ( V_321 -> V_224 == NULL )
return - V_318 ;
V_49 = F_131 ( V_30 ) ;
if ( V_49 < 0 ) {
F_44 ( & V_30 -> V_65 ,
L_19 , V_49 ) ;
return V_49 ;
}
V_49 = F_133 ( V_30 ) ;
if ( V_49 ) {
F_44 ( & V_30 -> V_65 , L_20 ) ;
return V_49 ;
}
V_49 = F_119 ( V_30 ) ;
if ( V_49 ) {
F_44 ( & V_30 -> V_65 , L_21 , V_49 ) ;
return V_49 ;
}
F_141 ( & V_30 -> V_275 , F_117 ) ;
F_142 ( V_323 -> V_37 , V_202 , sizeof( V_323 -> V_37 ) ) ;
V_323 -> V_337 = V_338 ;
V_323 -> V_339 = & V_340 ;
V_323 -> V_341 = & V_342 ;
V_323 -> V_65 = & V_30 -> V_65 ;
V_323 -> V_343 = V_344 ;
V_323 -> V_345 = V_324 ;
V_323 -> V_258 = & V_30 -> V_258 ;
V_323 -> V_346 = & V_30 -> V_93 . V_290 ;
V_323 -> V_347 = V_348 | V_349 ;
F_143 ( V_323 , V_30 ) ;
V_49 = F_144 ( V_323 , V_350 , - 1 ) ;
if ( V_49 < 0 ) {
F_44 ( & V_30 -> V_65 ,
L_22 , V_49 ) ;
return V_49 ;
}
return 0 ;
}
static void F_145 ( struct V_29 * V_30 )
{
struct V_160 * V_306 ;
F_69 (subdev_entity, &isc->subdev_entities, list)
F_146 ( & V_306 -> V_303 ) ;
F_71 ( & V_30 -> V_351 ) ;
}
static int F_147 ( struct V_29 * V_30 )
{
struct V_55 * V_6 = V_30 -> V_6 ;
struct V_5 * V_5 = V_30 -> V_5 ;
struct V_352 * V_353 ;
unsigned int V_20 ;
const struct V_354 V_355 [ V_96 ] = {
F_148 ( V_356 , 0 , 0 ) ,
F_148 ( V_357 , 0 , 0 ) ,
F_148 ( V_358 , 0 , 0 ) ,
F_148 ( V_359 , 0 , 0 ) ,
F_148 ( V_359 , 1 , 1 ) ,
F_148 ( V_359 , 2 , 2 ) ,
F_148 ( V_359 , 3 , 3 ) ,
F_148 ( V_360 , 0 , 0 ) ,
F_148 ( V_361 , 0 , 0 ) ,
F_148 ( V_362 , 0 , 0 ) ,
F_148 ( V_363 , 0 , 0 ) ,
} ;
for ( V_20 = 0 ; V_20 < V_96 ; V_20 ++ ) {
V_353 = F_149 ( V_6 , V_5 , V_355 [ V_20 ] ) ;
if ( F_29 ( V_353 ) )
return F_31 ( V_353 ) ;
V_30 -> V_91 [ V_20 ] = V_353 ;
}
return 0 ;
}
static int F_150 ( struct V_55 * V_6 , struct V_29 * V_30 )
{
struct V_31 * V_32 = V_6 -> V_33 ;
struct V_31 * V_364 = NULL , * V_365 ;
struct V_366 V_367 ;
struct V_160 * V_306 ;
unsigned int V_44 ;
int V_49 ;
F_71 ( & V_30 -> V_351 ) ;
for (; ; ) {
V_364 = F_151 ( V_32 , V_364 ) ;
if ( ! V_364 )
break;
V_365 = F_152 ( V_364 ) ;
if ( ! V_365 ) {
F_153 ( V_6 , L_23 ,
F_154 ( V_364 ) ) ;
continue;
}
V_49 = F_155 ( V_364 , & V_367 ) ;
if ( V_49 ) {
F_156 ( V_365 ) ;
V_49 = - V_18 ;
F_30 ( V_6 , L_24 ) ;
break;
}
V_306 = F_157 ( V_6 ,
sizeof( * V_306 ) , V_317 ) ;
if ( V_306 == NULL ) {
F_156 ( V_365 ) ;
V_49 = - V_318 ;
break;
}
V_306 -> V_305 = F_157 ( V_6 ,
sizeof( * V_306 -> V_305 ) , V_317 ) ;
if ( V_306 -> V_305 == NULL ) {
F_156 ( V_365 ) ;
V_49 = - V_318 ;
break;
}
V_44 = V_367 . V_368 . V_369 . V_44 ;
if ( V_44 & V_370 )
V_306 -> V_163 = V_169 ;
if ( V_44 & V_371 )
V_306 -> V_163 |= V_170 ;
if ( V_44 & V_372 )
V_306 -> V_163 |= V_171 ;
V_306 -> V_305 -> V_373 = V_374 ;
V_306 -> V_305 -> V_375 . V_376 . V_377 = V_365 ;
F_78 ( & V_306 -> V_193 , & V_30 -> V_351 ) ;
}
F_156 ( V_364 ) ;
return V_49 ;
}
static int F_158 ( struct V_378 * V_379 )
{
struct V_55 * V_6 = & V_379 -> V_6 ;
struct V_29 * V_30 ;
struct V_380 * V_381 ;
void T_6 * V_382 ;
struct V_160 * V_306 ;
int V_264 ;
int V_49 ;
V_30 = F_157 ( V_6 , sizeof( * V_30 ) , V_317 ) ;
if ( ! V_30 )
return - V_318 ;
F_159 ( V_379 , V_30 ) ;
V_30 -> V_6 = V_6 ;
V_381 = F_160 ( V_379 , V_383 , 0 ) ;
V_382 = F_161 ( V_6 , V_381 ) ;
if ( F_29 ( V_382 ) )
return F_31 ( V_382 ) ;
V_30 -> V_5 = F_162 ( V_6 , V_382 , & V_384 ) ;
if ( F_29 ( V_30 -> V_5 ) ) {
V_49 = F_31 ( V_30 -> V_5 ) ;
F_30 ( V_6 , L_25 , V_49 ) ;
return V_49 ;
}
V_264 = F_163 ( V_379 , 0 ) ;
if ( V_264 < 0 ) {
V_49 = V_264 ;
F_30 ( V_6 , L_26 , V_49 ) ;
return V_49 ;
}
V_49 = F_164 ( V_6 , V_264 , F_106 , 0 ,
V_202 , V_30 ) ;
if ( V_49 < 0 ) {
F_30 ( V_6 , L_27 ,
V_264 , V_49 ) ;
return V_49 ;
}
V_49 = F_147 ( V_30 ) ;
if ( V_49 )
return V_49 ;
V_30 -> V_385 = F_165 ( V_6 , L_28 ) ;
if ( F_29 ( V_30 -> V_385 ) ) {
V_49 = F_31 ( V_30 -> V_385 ) ;
F_30 ( V_6 , L_29 , V_49 ) ;
return V_49 ;
}
V_49 = F_33 ( V_30 ) ;
if ( V_49 ) {
F_30 ( V_6 , L_30 , V_49 ) ;
goto V_386;
}
V_30 -> V_387 = V_30 -> V_47 [ V_40 ] . V_27 ;
V_49 = F_166 ( V_30 -> V_387 , F_167 ( V_30 -> V_385 ) ) ;
if ( V_49 ) {
F_30 ( V_6 , L_31 , V_49 ) ;
goto V_386;
}
V_49 = F_168 ( V_6 , & V_30 -> V_65 ) ;
if ( V_49 ) {
F_30 ( V_6 , L_32 ) ;
goto V_386;
}
V_49 = F_150 ( V_6 , V_30 ) ;
if ( V_49 ) {
F_30 ( V_6 , L_33 ) ;
goto V_388;
}
if ( F_76 ( & V_30 -> V_351 ) ) {
F_30 ( V_6 , L_34 ) ;
V_49 = - V_389 ;
goto V_388;
}
F_69 (subdev_entity, &isc->subdev_entities, list) {
V_306 -> V_303 . V_390 = & V_306 -> V_305 ;
V_306 -> V_303 . V_391 = 1 ;
V_306 -> V_303 . V_392 = F_123 ;
V_306 -> V_303 . V_393 = F_125 ;
V_306 -> V_303 . F_110 = F_134 ;
V_49 = F_169 ( & V_30 -> V_65 ,
& V_306 -> V_303 ) ;
if ( V_49 ) {
F_30 ( V_6 , L_35 ) ;
goto V_394;
}
if ( F_124 ( & V_30 -> V_307 ) )
break;
}
F_170 ( V_6 ) ;
return 0 ;
V_394:
F_145 ( V_30 ) ;
V_388:
F_171 ( & V_30 -> V_65 ) ;
V_386:
F_36 ( V_30 ) ;
return V_49 ;
}
static int F_172 ( struct V_378 * V_379 )
{
struct V_29 * V_30 = F_173 ( V_379 ) ;
F_174 ( & V_379 -> V_6 ) ;
F_145 ( V_30 ) ;
F_171 ( & V_30 -> V_65 ) ;
F_36 ( V_30 ) ;
return 0 ;
}
static int T_7 F_175 ( struct V_55 * V_6 )
{
struct V_29 * V_30 = F_176 ( V_6 ) ;
F_177 ( V_30 -> V_387 ) ;
F_177 ( V_30 -> V_385 ) ;
return 0 ;
}
static int T_7 F_178 ( struct V_55 * V_6 )
{
struct V_29 * V_30 = F_176 ( V_6 ) ;
int V_49 ;
V_49 = F_179 ( V_30 -> V_385 ) ;
if ( V_49 )
return V_49 ;
return F_179 ( V_30 -> V_387 ) ;
}
