static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_4 ) ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
enum V_7 V_8 )
{
F_4 ( V_2 , L_1 , V_8 ,
V_6 -> V_9 . V_10 ) ;
F_5 ( & V_2 -> V_11 ) ;
switch ( V_8 ) {
case V_12 :
if ( V_2 -> V_13 == V_14 ) {
V_2 -> V_15 = V_6 ;
F_6 ( V_2 , V_16 ) ;
} else {
F_4 ( V_2 , L_2
L_3
L_4
L_5
L_6 , V_6 -> V_9 . V_10 ,
V_2 -> V_13 ) ;
V_2 -> V_17 . V_18 ( V_6 ) ;
}
break;
case V_19 :
case V_20 :
case V_21 :
V_2 -> V_15 = NULL ;
break;
case V_22 :
break;
}
F_7 ( & V_2 -> V_11 ) ;
}
static const char * F_8 ( struct V_1 * V_2 )
{
const char * V_23 ;
V_23 = V_24 [ V_2 -> V_13 ] ;
if ( ! V_23 )
V_23 = L_7 ;
return V_23 ;
}
static void F_9 ( struct V_1 * V_2 ,
T_1 V_25 , T_2 V_26 ,
T_2 V_27 )
{
F_5 ( & V_2 -> V_28 . V_29 ) ;
if ( V_2 -> V_30 ) {
V_2 -> V_17 . V_18 ( V_2 -> V_30 ) ;
F_10 ( & V_2 -> V_30 -> V_31 , V_2 -> V_17 . V_32 ) ;
}
V_2 -> V_30 = V_2 -> V_17 . V_33 ( V_2 , V_25 ) ;
F_11 ( & V_2 -> V_30 -> V_31 ) ;
V_2 -> V_30 -> V_9 . V_34 = V_26 ;
V_2 -> V_30 -> V_9 . V_35 = V_27 ;
F_7 ( & V_2 -> V_28 . V_29 ) ;
V_2 -> V_17 . V_36 ( V_2 -> V_30 ) ;
F_12 ( V_2 ) ;
}
void F_13 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_38 ) ;
F_5 ( & V_2 -> V_11 ) ;
if ( ! V_2 -> V_39 )
F_15 ( V_38 ) = V_40 ;
else
switch ( V_2 -> V_13 ) {
case V_41 :
F_15 ( V_38 ) = V_42 ;
break;
default:
F_15 ( V_38 ) = V_43 ;
}
F_7 ( & V_2 -> V_11 ) ;
}
void F_16 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_38 ) ;
F_17 ( V_38 ) = V_2 -> V_44 ;
}
struct V_45 * F_18 ( struct V_37 * V_38 )
{
struct V_45 * V_46 ;
struct V_1 * V_2 = F_14 ( V_38 ) ;
struct V_47 V_48 , V_49 ;
unsigned int V_50 ;
T_2 V_51 = 0 ;
T_2 V_52 = 0 ;
V_46 = & V_2 -> V_53 ;
memset ( V_46 , 0 , sizeof( struct V_45 ) ) ;
F_19 ( V_54 , & V_48 ) ;
F_19 ( V_2 -> V_55 , & V_49 ) ;
V_46 -> V_56 = ( V_48 . V_57 - V_49 . V_57 ) ;
F_20 (cpu) {
struct V_58 * V_59 ;
V_59 = F_21 ( V_2 -> V_60 , V_50 ) ;
V_46 -> V_61 += V_59 -> V_62 ;
V_46 -> V_63 += V_59 -> V_64 ;
V_46 -> V_65 += V_59 -> V_66 ;
V_46 -> V_67 += V_59 -> V_68 ;
V_46 -> V_69 += V_59 -> V_70 ;
V_46 -> V_71 += V_59 -> V_72 ;
V_46 -> V_73 += V_59 -> V_74 ;
V_46 -> V_75 += V_59 -> V_76 ;
V_46 -> V_77 += V_59 -> V_78 ;
V_51 += V_59 -> V_79 ;
V_52 += V_59 -> V_80 ;
V_46 -> V_81 += V_59 -> V_82 ;
}
V_46 -> V_83 = F_22 ( V_51 , 1000000 ) ;
V_46 -> V_84 = F_22 ( V_52 , 1000000 ) ;
V_46 -> V_85 = - 1 ;
V_46 -> V_86 = - 1 ;
V_46 -> V_87 = - 1 ;
V_46 -> V_88 = - 1 ;
V_46 -> V_89 = - 1 ;
V_46 -> V_90 = - 1 ;
return V_46 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
unsigned int V_93 )
{
struct V_94 * V_95 ;
struct V_96 * V_23 ;
memset ( V_92 , 0 , sizeof( * V_92 ) ) ;
V_92 -> V_97 = ( V_98 ) V_93 ;
F_24 ( V_2 -> V_99 , & V_92 -> V_100 ) ;
F_24 ( V_2 -> V_101 , & V_92 -> V_102 ) ;
V_95 = & V_92 -> V_103 ;
V_95 -> V_104 = 0x20 ;
V_95 -> V_105 = 0x20 ;
V_95 -> V_106 = F_25 ( 10 ) ;
V_95 -> V_107 = F_25 ( ( V_108 ) V_2 -> V_109 ) ;
V_23 = & V_92 -> V_110 [ 3 - 1 ] ;
V_23 -> V_111 = F_25 ( V_112 | V_113 ) ;
if ( V_93 != V_114 ) {
V_95 -> V_115 = F_25 ( V_116 ) ;
V_95 -> V_117 = F_25 ( 255 ) ;
V_95 -> V_118 = F_25 ( 0x1f ) ;
V_95 -> V_119 = F_26 ( V_2 -> V_120 ) ;
V_23 -> V_121 = F_25 ( ( V_108 ) V_2 -> V_109 ) ;
V_23 -> V_122 = F_25 ( 255 ) ;
V_23 -> V_123 = 1 ;
}
}
static void F_27 ( struct V_1 * V_2 , enum V_124 type )
{
T_3 * V_125 ;
V_125 = & V_2 -> V_126 . V_127 [ type / V_128 ] ;
* V_125 = F_26 ( F_28 ( * V_125 ) | 1UL << ( type % V_128 ) ) ;
}
static void F_29 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_4 ( V_2 , L_8 ,
F_8 ( V_2 ) ) ;
V_2 -> V_17 . V_129 ( V_4 , V_130 , NULL ) ;
F_2 ( V_4 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_3 * V_131 )
{
struct V_3 * V_4 ;
unsigned int V_132 ;
void * V_133 ;
void * V_134 ;
F_4 ( V_2 , L_9 ,
F_8 ( V_2 ) ) ;
V_132 = F_31 ( V_131 ) - sizeof( struct V_135 ) ;
V_133 = F_32 ( V_131 , V_132 ) ;
if ( V_132 < sizeof( T_3 ) )
V_132 = sizeof( T_3 ) ;
V_4 = F_33 ( V_2 , V_132 ) ;
if ( V_4 ) {
V_134 = F_32 ( V_4 , V_132 ) ;
memcpy ( V_134 , V_133 , V_132 ) ;
* ( ( T_3 * ) V_134 ) = F_26 ( V_130 << 24 ) ;
F_34 ( V_4 , V_131 , V_136 , 0 ) ;
V_2 -> V_17 . V_137 ( V_2 , V_4 ) ;
}
F_2 ( V_131 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_3 * V_131 )
{
struct V_3 * V_4 ;
struct V_138 * V_139 ;
struct {
struct V_140 V_141 ;
struct V_142 V_143 ;
struct V_144 V_145 ;
} * V_146 ;
struct V_147 V_148 ;
V_98 V_149 ;
T_4 V_132 ;
F_4 ( V_2 , L_10 ,
F_8 ( V_2 ) ) ;
V_139 = F_32 ( V_131 , sizeof( * V_139 ) ) ;
if ( ! V_139 ) {
V_148 . V_150 = V_151 ;
V_148 . V_152 = V_153 ;
V_2 -> V_17 . V_129 ( V_131 , V_154 , & V_148 ) ;
} else {
V_149 = V_139 -> V_155 ;
V_132 = sizeof( * V_146 ) ;
if ( V_149 != V_156 ||
F_28 ( V_2 -> V_157 . V_158 ) == 0 ) {
V_149 = V_159 ;
V_132 -= sizeof( V_146 -> V_145 ) ;
}
V_4 = F_33 ( V_2 , V_132 ) ;
if ( V_4 ) {
V_146 = F_32 ( V_4 , V_132 ) ;
memset ( V_146 , 0 , V_132 ) ;
V_146 -> V_141 . V_160 = V_130 ;
V_146 -> V_141 . V_155 = V_149 ;
V_146 -> V_141 . V_161 = sizeof( V_146 -> V_143 ) ;
V_146 -> V_143 . V_162 = F_36 ( V_2 -> V_99 ) ;
V_146 -> V_143 . V_163 = F_36 ( V_2 -> V_101 ) ;
if ( V_149 == V_156 ) {
V_146 -> V_141 . V_164 = sizeof( V_146 -> V_145 ) ;
memcpy ( & V_146 -> V_145 , & V_2 -> V_157 ,
sizeof( V_146 -> V_145 ) ) ;
}
F_34 ( V_4 , V_131 , V_136 , 0 ) ;
V_2 -> V_17 . V_137 ( V_2 , V_4 ) ;
}
}
F_2 ( V_131 ) ;
}
static void F_37 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_17 . V_129 ( V_4 , V_130 , NULL ) ;
F_38 ( V_2 ) ;
F_2 ( V_4 ) ;
}
int F_39 ( struct V_1 * V_2 )
{
int V_165 = - 1 ;
F_5 ( & V_2 -> V_11 ) ;
if ( V_2 -> V_13 == V_166 ||
V_2 -> V_13 == V_167 ) {
F_40 ( V_2 , V_168 ) ;
F_38 ( V_2 ) ;
V_165 = 0 ;
}
F_7 ( & V_2 -> V_11 ) ;
return V_165 ;
}
void F_41 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_39 ) {
V_2 -> V_39 = 1 ;
if ( V_2 -> V_13 == V_168 )
F_42 ( V_2 ) ;
}
}
void F_43 ( struct V_1 * V_2 )
{
F_44 ( V_169 L_11 ,
V_2 -> V_170 -> V_171 , V_2 -> V_10 ) ;
F_5 ( & V_2 -> V_11 ) ;
F_41 ( V_2 ) ;
F_7 ( & V_2 -> V_11 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
if ( V_2 -> V_39 ) {
V_2 -> V_39 = 0 ;
F_38 ( V_2 ) ;
V_2 -> V_17 . V_172 ( V_2 ) ;
}
}
void F_46 ( struct V_1 * V_2 )
{
F_44 ( V_169 L_12 ,
V_2 -> V_170 -> V_171 , V_2 -> V_10 ) ;
F_5 ( & V_2 -> V_11 ) ;
F_45 ( V_2 ) ;
F_7 ( & V_2 -> V_11 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
V_2 -> V_17 . V_173 ( V_2 ) ;
F_5 ( & V_2 -> V_11 ) ;
if ( V_2 -> V_15 )
V_2 -> V_17 . V_18 ( V_2 -> V_15 ) ;
F_7 ( & V_2 -> V_11 ) ;
V_2 -> V_17 . V_174 () ;
F_5 ( & V_2 -> V_11 ) ;
F_48 ( V_2 ) ;
F_7 ( & V_2 -> V_11 ) ;
F_49 ( & V_2 -> V_175 ) ;
return 0 ;
}
int F_50 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_11 ) ;
V_2 -> V_13 = V_166 ;
V_2 -> V_39 = 0 ;
V_2 -> V_17 . V_137 = F_1 ;
F_7 ( & V_2 -> V_11 ) ;
V_2 -> V_17 . V_176 ( V_2 ) ;
V_2 -> V_17 . V_173 ( V_2 ) ;
V_2 -> V_17 . V_177 ( V_2 , 0 , 0 ) ;
F_51 ( V_2 ) ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 , T_1 V_109 )
{
unsigned int V_178 ;
int V_165 = - V_179 ;
F_5 ( & V_2 -> V_11 ) ;
V_178 = V_2 -> V_109 ;
if ( V_109 >= V_180 ) {
V_109 &= ~ 3 ;
if ( V_109 > V_181 )
V_109 = V_181 ;
V_109 -= sizeof( struct V_135 ) ;
V_2 -> V_109 = V_109 ;
V_165 = 0 ;
}
if ( ! V_165 && V_109 < V_178 )
F_38 ( V_2 ) ;
F_7 ( & V_2 -> V_11 ) ;
return V_165 ;
}
void F_53 ( struct V_1 * V_2 , enum V_182 V_8 )
{
switch ( V_8 ) {
case V_183 :
F_4 ( V_2 , L_13 ) ;
break;
case V_184 :
F_44 ( V_185 L_14
L_15 ,
V_2 -> V_170 -> V_171 , V_2 -> V_10 ) ;
F_5 ( & V_2 -> V_11 ) ;
F_38 ( V_2 ) ;
F_7 ( & V_2 -> V_11 ) ;
break;
case V_186 :
F_54 ( 1 ) ;
break;
}
}
static void F_12 ( struct V_1 * V_2 )
{
F_4 ( V_2 , L_16 ,
F_8 ( V_2 ) ) ;
F_40 ( V_2 , V_41 ) ;
if ( V_2 -> V_187 )
F_55 ( V_2 -> V_187 , V_188 ) ;
F_56 ( V_2 ) ;
if ( ! V_2 -> V_30 )
V_2 -> V_17 . V_189 ( F_53 , V_2 ) ;
}
static void F_57 ( struct V_1 * V_2 , T_1 V_10 ,
struct V_3 * V_4 )
{
if ( V_10 )
F_44 ( V_169 L_17 ,
V_2 -> V_170 -> V_171 , V_10 ) ;
V_2 -> V_10 = V_10 ;
F_58 ( V_2 -> V_170 ) = V_10 ;
if ( V_2 -> V_17 . V_190 )
V_2 -> V_17 . V_190 ( V_2 , V_10 , V_4 ) ;
}
void F_59 ( struct V_1 * V_2 , T_1 V_10 )
{
F_5 ( & V_2 -> V_11 ) ;
F_57 ( V_2 , V_10 , NULL ) ;
switch ( V_2 -> V_13 ) {
case V_168 :
case V_191 :
if ( V_10 )
F_12 ( V_2 ) ;
break;
default:
break;
}
F_7 ( & V_2 -> V_11 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_3 * V_192 )
{
struct V_3 * V_4 ;
struct V_135 * V_193 ;
struct V_91 * V_194 ;
struct V_91 * V_195 ;
T_2 V_26 ;
T_1 V_25 ;
T_1 V_196 ;
F_4 ( V_2 , L_18 ,
F_8 ( V_2 ) ) ;
V_25 = F_61 ( V_192 ) ;
V_194 = F_32 ( V_192 , sizeof( * V_194 ) ) ;
if ( ! V_194 )
goto V_197;
V_26 = F_62 ( & V_194 -> V_100 ) ;
if ( V_26 == V_2 -> V_99 ) {
F_44 ( V_198 L_19
L_20 ,
V_2 -> V_170 -> V_171 , V_26 ) ;
goto V_197;
}
F_4 ( V_2 , L_21 , V_26 ) ;
V_196 = V_199 ;
if ( V_26 < V_2 -> V_99 ) {
V_196 = V_200 ;
if ( ! V_25 || V_25 == V_196 )
V_25 = V_199 ;
} else if ( ! V_25 ) {
V_25 = V_200 ;
}
F_57 ( V_2 , V_196 , V_192 ) ;
V_4 = F_33 ( V_2 , sizeof( * V_194 ) ) ;
if ( V_4 ) {
V_195 = F_32 ( V_4 , sizeof( * V_194 ) ) ;
F_23 ( V_2 , V_195 , V_114 ) ;
V_195 -> V_97 = ( V_98 ) V_130 ;
F_34 ( V_4 , V_192 , V_136 , 0 ) ;
V_193 = F_63 ( V_4 ) ;
F_64 ( V_193 -> V_201 , V_196 ) ;
F_64 ( V_193 -> V_202 , V_25 ) ;
V_2 -> V_17 . V_137 ( V_2 , V_4 ) ;
} else {
F_65 ( V_2 , V_4 ) ;
}
F_9 ( V_2 , V_25 , V_26 ,
F_62 ( & V_194 -> V_102 ) ) ;
V_197:
F_2 ( V_192 ) ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
void (* F_67)( struct V_1 * , struct V_3 * );
F_5 ( & V_2 -> V_11 ) ;
if ( ! V_2 -> V_39 )
F_2 ( V_4 ) ;
else {
F_67 = V_2 -> V_17 . V_203 ;
switch ( F_68 ( V_4 ) ) {
case V_114 :
if ( ! V_2 -> V_204 )
F_67 = F_60 ;
break;
case V_205 :
if ( F_61 ( V_4 ) == V_206 )
F_67 = F_37 ;
break;
case V_207 :
F_67 = V_2 -> V_17 . V_208 ;
break;
case V_209 :
F_67 = F_30 ;
break;
case V_210 :
F_67 = F_29 ;
break;
case V_211 :
F_67 = F_35 ;
break;
}
F_67 ( V_2 , V_4 ) ;
}
F_7 ( & V_2 -> V_11 ) ;
}
static int F_69 ( struct V_5 * V_6 , T_1 V_212 ,
const struct V_213 * V_214 ,
struct V_213 * V_215 )
{
return V_216 ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_135 * V_193 = F_63 ( V_4 ) ;
struct V_217 * V_95 = F_71 ( V_4 ) ;
struct V_218 * V_219 ;
F_72 () ;
if ( V_193 -> V_220 >= V_221 )
goto V_222;
V_219 = F_73 ( V_223 [ V_193 -> V_220 ] ) ;
if ( ! V_219 || ! F_74 ( V_219 -> V_224 ) )
goto V_222;
F_75 () ;
V_219 -> F_67 ( V_2 , V_4 ) ;
F_76 ( V_219 -> V_224 ) ;
return;
V_222:
F_75 () ;
F_4 ( V_2 , L_22 , V_193 -> V_220 ) ;
F_2 ( V_4 ) ;
V_2 -> V_17 . V_225 ( V_95 ) ;
}
int F_77 ( struct V_1 * V_2 )
{
F_49 ( & V_2 -> V_175 ) ;
F_5 ( & V_2 -> V_11 ) ;
F_38 ( V_2 ) ;
F_7 ( & V_2 -> V_11 ) ;
return 0 ;
}
static void F_78 ( struct V_1 * V_2 )
{
if ( V_2 -> V_15 )
V_2 -> V_17 . V_18 ( V_2 -> V_15 ) ;
if ( V_2 -> V_30 ) {
V_2 -> V_17 . V_18 ( V_2 -> V_30 ) ;
F_10 ( & V_2 -> V_30 -> V_31 , V_2 -> V_17 . V_32 ) ;
V_2 -> V_30 = NULL ;
}
V_2 -> V_17 . V_226 ( V_2 ) ;
V_2 -> V_17 . V_177 ( V_2 , 0 , 0 ) ;
F_79 ( V_2 -> V_170 ) = 0 ;
if ( V_2 -> V_10 && ( ! V_2 -> V_204 || ! V_2 -> V_39 ) )
F_57 ( V_2 , 0 , NULL ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_4 ( V_2 , L_23 ,
F_8 ( V_2 ) ) ;
if ( V_2 -> V_13 == V_166 || V_2 -> V_13 == V_167 )
return;
if ( V_2 -> V_187 ) {
if ( V_2 -> V_39 )
F_55 ( V_2 -> V_187 , V_227 ) ;
else
F_55 ( V_2 -> V_187 , V_228 ) ;
}
F_40 ( V_2 , V_168 ) ;
F_80 ( V_2 -> V_170 , F_81 () ,
V_229 , 0 ) ;
F_56 ( V_2 ) ;
F_78 ( V_2 ) ;
if ( V_2 -> V_39 )
F_42 ( V_2 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
F_4 ( V_2 , L_24 ,
F_8 ( V_2 ) ) ;
F_40 ( V_2 , V_166 ) ;
F_56 ( V_2 ) ;
F_78 ( V_2 ) ;
}
static void F_65 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_230 = 0 ;
F_4 ( V_2 , L_25 ,
F_83 ( V_4 ) , F_8 ( V_2 ) ,
V_2 -> V_231 ) ;
if ( F_83 ( V_4 ) == - V_232 )
return;
if ( V_2 -> V_231 < V_2 -> V_233 ) {
V_2 -> V_231 ++ ;
if ( ! V_4 )
V_230 = F_84 ( 500 ) ;
else
V_230 = F_84 ( V_2 -> V_120 ) ;
F_85 ( & V_2 -> V_175 , V_230 ) ;
} else
F_38 ( V_2 ) ;
}
static void F_86 ( struct V_217 * V_95 , struct V_3 * V_4 ,
void * V_234 )
{
struct V_1 * V_2 = V_234 ;
struct V_135 * V_193 ;
struct V_235 * V_236 ;
F_4 ( V_2 , L_26 , F_87 ( V_4 ) ) ;
if ( V_4 == F_88 ( - V_232 ) )
return;
F_5 ( & V_2 -> V_11 ) ;
if ( V_2 -> V_13 < V_16 || V_2 -> V_13 > V_237 ) {
F_4 ( V_2 , L_27
L_28 , F_8 ( V_2 ) ) ;
if ( F_89 ( V_4 ) )
goto V_238;
goto V_197;
}
if ( F_89 ( V_4 ) ) {
F_65 ( V_2 , V_4 ) ;
goto V_238;
}
V_193 = F_63 ( V_4 ) ;
V_236 = F_32 ( V_4 , sizeof( * V_236 ) ) ;
if ( V_193 && V_236 && V_193 -> V_220 == V_239 &&
V_236 -> V_240 == V_241 &&
V_236 -> V_242 == V_243 &&
F_90 ( V_236 -> V_244 ) == V_245 )
switch ( V_2 -> V_13 ) {
case V_16 :
F_6 ( V_2 , V_246 ) ;
break;
case V_246 :
F_6 ( V_2 , V_247 ) ;
break;
case V_247 :
F_6 ( V_2 , V_248 ) ;
break;
case V_248 :
F_6 ( V_2 , V_237 ) ;
break;
case V_237 :
F_91 ( V_2 ) ;
break;
default:
break;
}
else
F_65 ( V_2 , V_4 ) ;
V_197:
F_2 ( V_4 ) ;
V_238:
F_7 ( & V_2 -> V_11 ) ;
}
static void F_92 ( struct V_217 * V_95 , struct V_3 * V_4 ,
void * V_234 )
{
struct V_1 * V_2 = V_234 ;
V_98 V_93 ;
F_4 ( V_2 , L_29 , F_87 ( V_4 ) ) ;
if ( V_4 == F_88 ( - V_232 ) )
return;
F_5 ( & V_2 -> V_11 ) ;
if ( V_2 -> V_13 != V_249 ) {
F_4 ( V_2 , L_30
L_31 , F_8 ( V_2 ) ) ;
if ( F_89 ( V_4 ) )
goto V_238;
goto V_197;
}
if ( F_89 ( V_4 ) ) {
F_65 ( V_2 , V_4 ) ;
goto V_238;
}
V_93 = F_68 ( V_4 ) ;
if ( V_93 == V_130 )
F_12 ( V_2 ) ;
else
F_65 ( V_2 , V_4 ) ;
V_197:
F_2 ( V_4 ) ;
V_238:
F_7 ( & V_2 -> V_11 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_4 ( V_2 , L_32 ,
F_8 ( V_2 ) ) ;
F_40 ( V_2 , V_249 ) ;
V_4 = F_33 ( V_2 , sizeof( struct V_250 ) ) ;
if ( ! V_4 ) {
F_65 ( V_2 , V_4 ) ;
return;
}
if ( ! V_2 -> V_17 . V_251 ( V_2 , V_252 , V_4 , V_253 ,
F_92 , V_2 ,
2 * V_2 -> V_254 ) )
F_65 ( V_2 , NULL ) ;
}
static void F_6 ( struct V_1 * V_2 , enum F_8 V_13 )
{
struct V_3 * V_4 ;
enum V_255 V_256 ;
int V_257 = sizeof( struct V_235 ) ;
T_4 V_132 ;
F_4 ( V_2 , L_33 ,
V_24 [ V_13 ] ,
F_8 ( V_2 ) ) ;
F_40 ( V_2 , V_13 ) ;
switch ( V_13 ) {
case V_16 :
V_256 = V_258 ;
V_257 += sizeof( struct V_259 ) ;
break;
case V_246 :
V_132 = F_93 ( F_94 ( V_2 -> V_170 ) , 255 ) ;
if ( ! V_132 )
return F_6 ( V_2 , V_248 ) ;
V_256 = V_260 ;
V_257 += sizeof( struct V_261 ) + V_132 ;
break;
case V_247 :
V_132 = F_93 ( F_94 ( V_2 -> V_170 ) , 255 ) ;
if ( ! V_132 )
return F_6 ( V_2 , V_248 ) ;
V_256 = V_262 ;
V_257 += sizeof( struct V_263 ) + V_132 ;
break;
case V_248 :
V_256 = V_264 ;
V_257 += sizeof( struct V_265 ) ;
break;
case V_237 :
V_256 = V_266 ;
V_257 += sizeof( struct V_267 ) ;
break;
default:
F_65 ( V_2 , NULL ) ;
return;
}
V_4 = F_33 ( V_2 , V_257 ) ;
if ( ! V_4 ) {
F_65 ( V_2 , V_4 ) ;
return;
}
if ( ! V_2 -> V_17 . V_251 ( V_2 , V_268 , V_4 , V_256 ,
F_86 ,
V_2 , 3 * V_2 -> V_254 ) )
F_65 ( V_2 , V_4 ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
F_4 ( V_2 , L_34 ,
F_8 ( V_2 ) ) ;
F_40 ( V_2 , V_14 ) ;
F_5 ( & V_2 -> V_28 . V_29 ) ;
V_6 = V_2 -> V_17 . V_33 ( V_2 , V_268 ) ;
F_7 ( & V_2 -> V_28 . V_29 ) ;
if ( ! V_6 )
goto V_238;
V_6 -> V_269 = & V_270 ;
V_2 -> V_17 . V_36 ( V_6 ) ;
return;
V_238:
F_65 ( V_2 , NULL ) ;
}
static void F_96 ( struct V_271 * V_272 )
{
struct V_1 * V_2 =
F_97 ( V_272 , struct V_1 ,
V_175 . V_272 ) ;
F_5 ( & V_2 -> V_11 ) ;
switch ( V_2 -> V_13 ) {
case V_166 :
F_54 ( 1 ) ;
break;
case V_41 :
break;
case V_168 :
break;
case V_191 :
F_42 ( V_2 ) ;
break;
case V_14 :
F_95 ( V_2 ) ;
break;
case V_16 :
case V_246 :
case V_247 :
case V_248 :
case V_237 :
F_6 ( V_2 , V_2 -> V_13 ) ;
break;
case V_249 :
F_91 ( V_2 ) ;
break;
case V_167 :
F_48 ( V_2 ) ;
break;
}
F_7 ( & V_2 -> V_11 ) ;
}
void F_98 ( struct V_217 * V_95 , struct V_3 * V_4 ,
void * V_234 )
{
struct V_1 * V_2 = V_234 ;
V_98 V_93 ;
F_4 ( V_2 , L_35 , F_87 ( V_4 ) ) ;
if ( V_4 == F_88 ( - V_232 ) )
return;
F_5 ( & V_2 -> V_11 ) ;
if ( V_2 -> V_13 != V_167 ) {
F_4 ( V_2 , L_36
L_31 , F_8 ( V_2 ) ) ;
if ( F_89 ( V_4 ) )
goto V_238;
goto V_197;
}
if ( F_89 ( V_4 ) ) {
F_65 ( V_2 , V_4 ) ;
goto V_238;
}
V_93 = F_68 ( V_4 ) ;
if ( V_93 == V_130 )
F_82 ( V_2 ) ;
else
F_65 ( V_2 , V_4 ) ;
V_197:
F_2 ( V_4 ) ;
V_238:
F_7 ( & V_2 -> V_11 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_273 * V_274 ;
F_4 ( V_2 , L_37 ,
F_8 ( V_2 ) ) ;
F_40 ( V_2 , V_167 ) ;
F_56 ( V_2 ) ;
V_4 = F_33 ( V_2 , sizeof( * V_274 ) ) ;
if ( ! V_4 ) {
F_65 ( V_2 , V_4 ) ;
return;
}
if ( ! V_2 -> V_17 . V_251 ( V_2 , V_206 , V_4 , V_205 ,
F_98 , V_2 ,
2 * V_2 -> V_254 ) )
F_65 ( V_2 , NULL ) ;
}
void F_99 ( struct V_217 * V_95 , struct V_3 * V_4 ,
void * V_234 )
{
struct V_1 * V_2 = V_234 ;
struct V_135 * V_193 ;
struct V_91 * V_194 ;
T_1 V_275 ;
V_108 V_276 ;
unsigned int V_254 ;
unsigned int V_120 ;
V_108 V_109 ;
F_4 ( V_2 , L_38 , F_87 ( V_4 ) ) ;
if ( V_4 == F_88 ( - V_232 ) )
return;
F_5 ( & V_2 -> V_11 ) ;
if ( V_2 -> V_13 != V_191 ) {
F_4 ( V_2 , L_39
L_31 , F_8 ( V_2 ) ) ;
if ( F_89 ( V_4 ) )
goto V_238;
goto V_197;
}
if ( F_89 ( V_4 ) ) {
F_65 ( V_2 , V_4 ) ;
goto V_238;
}
V_193 = F_63 ( V_4 ) ;
V_275 = F_100 ( V_4 ) ;
if ( V_193 -> V_277 != V_136 || V_275 == 0 ||
F_68 ( V_4 ) != V_130 ) {
F_4 ( V_2 , L_40 ) ;
F_65 ( V_2 , V_4 ) ;
goto V_238;
}
V_194 = F_32 ( V_4 , sizeof( * V_194 ) ) ;
if ( ! V_194 ) {
F_4 ( V_2 , L_41 ) ;
F_65 ( V_2 , V_4 ) ;
goto V_238;
}
V_109 = F_90 ( V_194 -> V_103 . V_107 ) &
V_278 ;
if ( V_109 >= V_279 &&
V_109 < V_2 -> V_109 )
V_2 -> V_109 = V_109 ;
V_276 = F_90 ( V_194 -> V_103 . V_115 ) ;
V_254 = F_28 ( V_194 -> V_103 . V_280 ) ;
V_120 = F_28 ( V_194 -> V_103 . V_119 ) ;
if ( V_276 & V_281 )
V_120 /= 1000000 ;
V_2 -> V_282 = ! ! ( V_276 & V_283 ) ;
if ( ( V_276 & V_284 ) == 0 ) {
if ( V_120 > V_2 -> V_120 )
V_2 -> V_120 = V_120 ;
V_2 -> V_254 = 2 * V_120 ;
F_57 ( V_2 , V_275 , V_4 ) ;
F_44 ( V_169 L_14
L_42
L_43 ,
V_2 -> V_170 -> V_171 , V_275 ) ;
F_9 ( V_2 , F_61 ( V_4 ) ,
F_62 (
& V_194 -> V_100 ) ,
F_62 (
& V_194 -> V_102 ) ) ;
} else {
V_2 -> V_120 = V_120 ;
V_2 -> V_254 = V_254 ;
F_79 ( V_2 -> V_170 ) =
F_62 ( & V_194 -> V_102 ) ;
F_57 ( V_2 , V_275 , V_4 ) ;
F_95 ( V_2 ) ;
}
V_197:
F_2 ( V_4 ) ;
V_238:
F_7 ( & V_2 -> V_11 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_4 ( V_2 , L_44 ,
F_8 ( V_2 ) ) ;
F_40 ( V_2 , V_191 ) ;
if ( V_2 -> V_204 ) {
if ( V_2 -> V_10 )
F_12 ( V_2 ) ;
return;
}
V_4 = F_33 ( V_2 , sizeof( struct V_91 ) ) ;
if ( ! V_4 )
return F_65 ( V_2 , V_4 ) ;
if ( ! V_2 -> V_17 . V_251 ( V_2 , V_206 , V_4 ,
V_2 -> V_187 ? V_285 : V_114 ,
F_99 , V_2 ,
V_2 -> V_187 ? 2 * V_2 -> V_254 :
V_2 -> V_120 ) )
F_65 ( V_2 , NULL ) ;
}
int F_101 ( struct V_1 * V_2 )
{
F_102 ( & V_2 -> V_175 , F_96 ) ;
F_103 ( & V_2 -> V_11 ) ;
F_40 ( V_2 , V_166 ) ;
F_27 ( V_2 , V_286 ) ;
F_27 ( V_2 , V_239 ) ;
F_104 ( V_2 , V_286 ) ;
return 0 ;
}
int F_105 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_17 . V_287 )
V_2 -> V_17 . V_287 = F_70 ;
if ( ! V_2 -> V_17 . V_288 )
V_2 -> V_17 . V_288 = F_77 ;
F_106 ( V_2 -> V_170 ) = V_289 ;
F_107 ( V_2 -> V_170 ) = V_2 -> V_101 ;
F_108 ( V_2 -> V_170 ) = V_2 -> V_99 ;
F_109 ( V_2 -> V_170 ) = V_290 ;
memset ( F_110 ( V_2 -> V_170 ) , 0 ,
sizeof( F_110 ( V_2 -> V_170 ) ) ) ;
F_110 ( V_2 -> V_170 ) [ 2 ] = 1 ;
F_110 ( V_2 -> V_170 ) [ 7 ] = 1 ;
memset ( F_111 ( V_2 -> V_170 ) , 0 ,
sizeof( F_111 ( V_2 -> V_170 ) ) ) ;
F_111 ( V_2 -> V_170 ) [ 2 ] = 1 ;
F_111 ( V_2 -> V_170 ) [ 7 ] = 1 ;
F_112 ( V_2 -> V_170 ) = V_2 -> V_109 ;
F_113 ( V_2 -> V_170 ) = 0 ;
if ( V_2 -> V_291 & V_292 )
F_113 ( V_2 -> V_170 ) |= V_292 ;
if ( V_2 -> V_291 & V_293 )
F_113 ( V_2 -> V_170 ) |= V_293 ;
F_114 ( V_2 ) ;
return 0 ;
}
static void F_115 ( struct V_217 * V_95 , struct V_3 * V_4 ,
void * V_294 )
{
struct V_295 * V_296 = V_294 ;
struct V_297 * V_298 = V_296 -> V_298 ;
struct V_1 * V_2 = V_296 -> V_2 ;
struct V_135 * V_193 ;
T_4 V_132 ;
void * V_299 ;
if ( F_89 ( V_4 ) ) {
V_298 -> V_300 -> V_301 = ( F_83 ( V_4 ) == - V_232 ) ?
- V_302 : - V_303 ;
V_298 -> V_304 = sizeof( V_305 ) ;
V_298 -> V_306 |= V_307 ;
V_298 -> V_308 ( V_298 ) ;
F_116 ( V_296 ) ;
return;
}
F_5 ( & V_2 -> V_11 ) ;
V_193 = F_63 ( V_4 ) ;
V_132 = F_31 ( V_4 ) - sizeof( * V_193 ) ;
V_299 = F_32 ( V_4 , 0 ) ;
if ( F_117 ( V_4 ) == V_309 && ! F_90 ( V_193 -> V_310 ) ) {
unsigned short V_256 = ( V_296 -> V_311 == V_245 ) ?
F_90 ( ( (struct V_235 * ) V_299 ) -> V_244 ) :
( unsigned short ) F_68 ( V_4 ) ;
V_298 -> V_300 -> V_312 . V_313 . V_314 =
( V_256 == V_296 -> V_311 ) ?
V_315 : V_316 ;
}
V_298 -> V_300 -> V_317 +=
F_118 ( V_299 , V_132 , V_296 -> V_318 , & V_296 -> V_319 ,
& V_296 -> V_320 , V_321 , NULL ) ;
if ( F_119 ( V_4 ) == V_322 &&
( F_120 ( V_193 -> V_323 ) & ( V_324 | V_325 ) ) ==
( V_324 | V_325 ) ) {
if ( V_298 -> V_300 -> V_317 >
V_298 -> V_326 . V_327 )
V_298 -> V_300 -> V_317 =
V_298 -> V_326 . V_327 ;
V_298 -> V_300 -> V_301 = 0 ;
V_298 -> V_306 |= V_307 ;
V_298 -> V_308 ( V_298 ) ;
F_116 ( V_296 ) ;
}
F_2 ( V_4 ) ;
F_7 ( & V_2 -> V_11 ) ;
}
static int F_121 ( struct V_297 * V_298 ,
struct V_1 * V_2 ,
T_1 V_275 , T_1 V_328 )
{
struct V_295 * V_296 ;
struct V_3 * V_4 ;
struct V_135 * V_193 ;
char * V_133 ;
int V_132 ;
V_4 = F_33 ( V_2 , V_298 -> V_329 . V_327 ) ;
if ( ! V_4 )
return - V_330 ;
V_132 = V_298 -> V_329 . V_327 ;
V_133 = F_32 ( V_4 , V_132 ) ;
F_122 ( V_298 -> V_329 . V_331 ,
V_298 -> V_329 . V_332 ,
V_133 , V_132 ) ;
V_193 = F_63 ( V_4 ) ;
V_193 -> V_277 = V_333 ;
F_64 ( V_193 -> V_202 , V_275 ) ;
F_64 ( V_193 -> V_201 , V_2 -> V_10 ) ;
V_193 -> V_220 = V_334 ;
F_64 ( V_193 -> V_323 , V_335 ) ;
V_193 -> V_336 = 0 ;
V_193 -> V_337 = 0 ;
V_193 -> V_338 = 0 ;
V_296 = F_123 ( sizeof( struct V_295 ) , V_339 ) ;
if ( ! V_296 ) {
F_2 ( V_4 ) ;
return - V_330 ;
}
V_296 -> V_298 = V_298 ;
V_296 -> V_2 = V_2 ;
V_296 -> V_311 = V_130 ;
V_296 -> V_319 = V_298 -> V_326 . V_332 ;
V_296 -> V_318 = V_298 -> V_326 . V_331 ;
if ( ! V_2 -> V_17 . V_340 ( V_2 , V_4 , F_115 ,
NULL , V_296 , V_328 ) ) {
F_116 ( V_296 ) ;
return - V_341 ;
}
return 0 ;
}
static int F_124 ( struct V_297 * V_298 ,
struct V_1 * V_2 , T_1 V_275 , T_1 V_328 )
{
struct V_295 * V_296 ;
struct V_3 * V_4 ;
struct V_135 * V_193 ;
struct V_342 * V_236 ;
T_4 V_132 ;
V_4 = F_33 ( V_2 , sizeof( struct V_235 ) +
V_298 -> V_329 . V_327 ) ;
if ( ! V_4 )
return - V_330 ;
V_132 = V_298 -> V_329 . V_327 ;
V_236 = F_32 ( V_4 , V_132 ) ;
F_122 ( V_298 -> V_329 . V_331 ,
V_298 -> V_329 . V_332 ,
V_236 , V_132 ) ;
V_193 = F_63 ( V_4 ) ;
V_193 -> V_277 = V_343 ;
F_64 ( V_193 -> V_202 , V_275 ) ;
F_64 ( V_193 -> V_201 , V_2 -> V_10 ) ;
V_193 -> V_220 = V_239 ;
F_64 ( V_193 -> V_323 , V_335 ) ;
V_193 -> V_336 = 0 ;
V_193 -> V_337 = 0 ;
V_193 -> V_338 = 0 ;
V_296 = F_123 ( sizeof( struct V_295 ) , V_339 ) ;
if ( ! V_296 ) {
F_2 ( V_4 ) ;
return - V_330 ;
}
V_296 -> V_298 = V_298 ;
V_296 -> V_2 = V_2 ;
V_296 -> V_311 = V_245 ;
V_296 -> V_319 = V_298 -> V_326 . V_332 ;
V_296 -> V_318 = V_298 -> V_326 . V_331 ;
if ( ! V_2 -> V_17 . V_340 ( V_2 , V_4 , F_115 ,
NULL , V_296 , V_328 ) ) {
F_116 ( V_296 ) ;
return - V_341 ;
}
return 0 ;
}
int F_125 ( struct V_297 * V_298 )
{
struct V_344 * V_345 = V_298 -> V_139 -> V_346 ;
struct V_37 * V_38 = V_298 -> V_38 ;
struct V_1 * V_2 = F_14 ( V_38 ) ;
struct V_347 * V_348 ;
struct V_5 * V_6 ;
int V_165 = - V_179 ;
T_1 V_275 ;
V_298 -> V_300 -> V_317 = 0 ;
if ( V_345 )
V_345 -> V_349 = V_298 -> V_326 . V_327 ;
F_5 ( & V_2 -> V_11 ) ;
switch ( V_298 -> V_344 -> V_350 ) {
case V_351 :
V_348 = V_298 -> V_348 ;
if ( ! V_348 )
break;
V_6 = V_348 -> V_352 ;
V_165 = F_121 ( V_298 , V_2 , V_348 -> V_10 ,
V_6 -> V_120 ) ;
break;
case V_353 :
V_348 = V_298 -> V_348 ;
if ( ! V_348 )
break;
V_6 = V_348 -> V_352 ;
V_165 = F_124 ( V_298 , V_2 , V_348 -> V_10 ,
V_6 -> V_120 ) ;
break;
case V_354 :
V_275 = F_120 ( V_298 -> V_344 -> V_355 . V_356 . V_10 ) ;
if ( V_275 == V_268 )
V_6 = V_2 -> V_15 ;
else
V_6 = V_2 -> V_17 . V_357 ( V_2 , V_275 ) ;
if ( ! V_6 )
break;
V_165 = F_124 ( V_298 , V_2 , V_275 , V_6 -> V_120 ) ;
break;
case V_358 :
V_275 = F_120 ( V_298 -> V_344 -> V_355 . V_359 . V_10 ) ;
V_165 = F_121 ( V_298 , V_2 , V_275 , V_2 -> V_120 ) ;
break;
}
F_7 ( & V_2 -> V_11 ) ;
return V_165 ;
}
