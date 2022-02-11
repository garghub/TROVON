static struct V_1 * F_1 ( struct V_2 * V_2 , char * V_3 ,
enum V_4 type ,
T_1 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_1 * V_10 ;
struct V_11 * V_12 ;
int V_13 ;
V_13 = F_3 ( V_9 , V_3 , & V_10 , type , V_7 ) ;
if ( V_13 )
return F_4 ( V_13 ) ;
if ( type == V_14 && V_5 ) {
V_12 = F_5 ( V_10 ) ;
V_12 -> V_15 . V_16 = * V_5 ;
}
return V_10 ;
}
static int F_6 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
F_7 ( F_5 ( V_10 ) ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
enum V_4 type , T_1 * V_5 ,
struct V_6 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
int V_17 ;
V_17 = F_9 ( V_12 , type ) ;
if ( V_17 )
return V_17 ;
if ( type == V_18 &&
V_7 && V_7 -> V_19 == 0 )
F_10 ( V_12 -> V_15 . V_20 . V_21 , NULL ) ;
else if ( type == V_22 &&
V_7 && V_7 -> V_19 >= 0 )
V_12 -> V_15 . V_23 . V_19 = V_7 -> V_19 ;
if ( V_12 -> V_24 . type == V_14 && V_5 ) {
struct V_8 * V_9 = V_12 -> V_9 ;
if ( F_11 ( V_12 ) ) {
if ( ( * V_5 & V_25 ) !=
( V_12 -> V_15 . V_16 & V_25 ) )
return - V_26 ;
F_12 ( V_12 , - 1 ) ;
V_12 -> V_15 . V_16 = * V_5 ;
F_12 ( V_12 , 1 ) ;
F_13 ( V_9 ) ;
} else {
V_12 -> V_15 . V_16 = * V_5 ;
}
}
return 0 ;
}
static int F_14 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 V_27 , bool V_28 , const T_2 * V_29 ,
struct V_30 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_31 * V_21 = NULL ;
struct V_32 * V_33 ;
int V_13 ;
if ( ! F_11 ( V_12 ) )
return - V_34 ;
switch ( V_7 -> V_35 ) {
case V_36 :
case V_37 :
case V_38 :
if ( F_15 ( V_12 -> V_9 -> V_39 ) )
return - V_40 ;
break;
default:
break;
}
V_33 = F_16 ( V_7 -> V_35 , V_27 , V_7 -> V_41 ,
V_7 -> V_33 , V_7 -> V_42 , V_7 -> V_43 ) ;
if ( F_15 ( V_33 ) )
return F_17 ( V_33 ) ;
if ( V_28 )
V_33 -> V_44 . V_5 |= V_45 ;
F_18 ( & V_12 -> V_9 -> V_46 ) ;
if ( V_29 ) {
if ( F_19 ( & V_12 -> V_24 ) )
V_21 = F_20 ( V_12 , V_29 ) ;
else
V_21 = F_21 ( V_12 , V_29 ) ;
if ( ! V_21 ) {
F_22 ( V_12 -> V_9 , V_33 ) ;
V_13 = - V_47 ;
goto V_48;
}
}
V_13 = F_23 ( V_33 , V_12 , V_21 ) ;
if ( V_13 )
F_22 ( V_12 -> V_9 , V_33 ) ;
V_48:
F_24 ( & V_12 -> V_9 -> V_46 ) ;
return V_13 ;
}
static int F_25 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 V_27 , bool V_28 , const T_2 * V_29 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_31 * V_21 ;
struct V_32 * V_33 = NULL ;
int V_17 ;
F_18 ( & V_9 -> V_46 ) ;
F_18 ( & V_9 -> V_49 ) ;
if ( V_29 ) {
V_17 = - V_47 ;
V_21 = F_21 ( V_12 , V_29 ) ;
if ( ! V_21 )
goto V_48;
if ( V_28 )
V_33 = F_26 ( V_9 , V_21 -> V_50 ) ;
else
V_33 = F_26 ( V_9 , V_21 -> V_51 [ V_27 ] ) ;
} else
V_33 = F_26 ( V_9 , V_12 -> V_52 [ V_27 ] ) ;
if ( ! V_33 ) {
V_17 = - V_47 ;
goto V_48;
}
F_27 ( V_33 ) ;
V_17 = 0 ;
V_48:
F_24 ( & V_9 -> V_49 ) ;
F_24 ( & V_9 -> V_46 ) ;
return V_17 ;
}
static int F_28 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 V_27 , bool V_28 , const T_2 * V_29 ,
void * V_53 ,
void (* F_29)( void * V_53 ,
struct V_30 * V_7 ) )
{
struct V_11 * V_12 ;
struct V_31 * V_21 = NULL ;
T_2 V_43 [ 6 ] = { 0 } ;
struct V_30 V_7 ;
struct V_32 * V_33 = NULL ;
T_3 V_54 ;
T_1 V_55 ;
T_4 V_56 ;
int V_13 = - V_47 ;
V_12 = F_5 ( V_10 ) ;
F_30 () ;
if ( V_29 ) {
V_21 = F_21 ( V_12 , V_29 ) ;
if ( ! V_21 )
goto V_57;
if ( V_28 )
V_33 = F_31 ( V_21 -> V_50 ) ;
else if ( V_27 < V_58 )
V_33 = F_31 ( V_21 -> V_51 [ V_27 ] ) ;
} else
V_33 = F_31 ( V_12 -> V_52 [ V_27 ] ) ;
if ( ! V_33 )
goto V_57;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_35 = V_33 -> V_44 . V_35 ;
switch ( V_33 -> V_44 . V_35 ) {
case V_37 :
V_55 = V_33 -> V_15 . V_59 . V_60 . V_55 ;
V_56 = V_33 -> V_15 . V_59 . V_60 . V_56 ;
if ( V_33 -> V_5 & V_61 )
F_32 ( V_12 -> V_9 ,
V_33 -> V_44 . V_62 ,
& V_55 , & V_56 ) ;
V_43 [ 0 ] = V_56 & 0xff ;
V_43 [ 1 ] = ( V_56 >> 8 ) & 0xff ;
V_43 [ 2 ] = V_55 & 0xff ;
V_43 [ 3 ] = ( V_55 >> 8 ) & 0xff ;
V_43 [ 4 ] = ( V_55 >> 16 ) & 0xff ;
V_43 [ 5 ] = ( V_55 >> 24 ) & 0xff ;
V_7 . V_43 = V_43 ;
V_7 . V_42 = 6 ;
break;
case V_63 :
V_54 = F_33 ( & V_33 -> V_15 . V_64 . V_65 ) ;
V_43 [ 0 ] = V_54 ;
V_43 [ 1 ] = V_54 >> 8 ;
V_43 [ 2 ] = V_54 >> 16 ;
V_43 [ 3 ] = V_54 >> 24 ;
V_43 [ 4 ] = V_54 >> 32 ;
V_43 [ 5 ] = V_54 >> 40 ;
V_7 . V_43 = V_43 ;
V_7 . V_42 = 6 ;
break;
case V_66 :
V_54 = F_33 ( & V_33 -> V_15 . V_67 . V_65 ) ;
V_43 [ 0 ] = V_54 ;
V_43 [ 1 ] = V_54 >> 8 ;
V_43 [ 2 ] = V_54 >> 16 ;
V_43 [ 3 ] = V_54 >> 24 ;
V_43 [ 4 ] = V_54 >> 32 ;
V_43 [ 5 ] = V_54 >> 40 ;
V_7 . V_43 = V_43 ;
V_7 . V_42 = 6 ;
break;
}
V_7 . V_33 = V_33 -> V_44 . V_33 ;
V_7 . V_41 = V_33 -> V_44 . V_68 ;
F_29 ( V_53 , & V_7 ) ;
V_13 = 0 ;
V_57:
F_34 () ;
return V_13 ;
}
static int F_35 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_27 , bool V_69 ,
bool V_70 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
F_36 ( V_12 , V_27 , V_69 , V_70 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_27 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
F_38 ( V_12 , V_27 ) ;
return 0 ;
}
static void F_39 ( struct V_71 * V_72 , struct V_31 * V_21 , int V_73 )
{
if ( ! ( V_72 -> V_5 & V_74 ) ) {
struct V_75 * V_76 ;
V_76 = V_21 -> V_9 -> V_77 . V_2 -> V_78 [
V_21 -> V_9 -> V_77 . V_44 . V_79 -> V_80 ] ;
V_72 -> V_81 = V_76 -> V_82 [ V_73 ] . V_83 ;
} else
V_72 -> V_84 = V_73 ;
}
static void F_40 ( struct V_31 * V_21 , struct V_85 * V_86 )
{
struct V_11 * V_12 = V_21 -> V_12 ;
struct V_87 V_88 ;
V_86 -> V_89 = V_12 -> V_9 -> V_90 ;
V_86 -> V_91 = V_92 |
V_93 |
V_94 |
V_95 |
V_96 |
V_97 |
V_98 |
V_99 |
V_100 |
V_101 |
V_102 |
V_103 ;
F_41 ( & V_88 ) ;
V_86 -> V_104 = V_88 . V_105 - V_21 -> V_106 ;
V_86 -> V_107 = F_42 ( V_108 - V_21 -> V_109 ) ;
V_86 -> V_110 = V_21 -> V_110 ;
V_86 -> V_111 = V_21 -> V_111 ;
V_86 -> V_112 = V_21 -> V_112 ;
V_86 -> V_113 = V_21 -> V_113 ;
V_86 -> V_114 = V_21 -> V_115 ;
V_86 -> V_116 = V_21 -> V_117 ;
V_86 -> V_118 = V_21 -> V_119 ;
if ( ( V_21 -> V_9 -> V_77 . V_5 & V_120 ) ||
( V_21 -> V_9 -> V_77 . V_5 & V_121 ) ) {
V_86 -> V_91 |= V_122 | V_123 ;
V_86 -> signal = ( V_124 ) V_21 -> V_125 ;
V_86 -> V_126 = ( V_124 ) - F_43 ( & V_21 -> V_127 ) ;
}
V_86 -> V_128 . V_5 = 0 ;
if ( V_21 -> V_129 . V_5 & V_130 )
V_86 -> V_128 . V_5 |= V_74 ;
if ( V_21 -> V_129 . V_5 & V_131 )
V_86 -> V_128 . V_5 |= V_132 ;
if ( V_21 -> V_129 . V_5 & V_133 )
V_86 -> V_128 . V_5 |= V_134 ;
F_39 ( & V_86 -> V_128 , V_21 , V_21 -> V_129 . V_73 ) ;
V_86 -> V_135 . V_5 = 0 ;
if ( V_21 -> V_136 & V_137 )
V_86 -> V_135 . V_5 |= V_74 ;
if ( V_21 -> V_136 & V_138 )
V_86 -> V_135 . V_5 |= V_132 ;
if ( V_21 -> V_136 & V_139 )
V_86 -> V_135 . V_5 |= V_134 ;
F_39 ( & V_86 -> V_135 , V_21 , V_21 -> V_140 ) ;
if ( F_19 ( & V_12 -> V_24 ) ) {
#ifdef F_44
V_86 -> V_91 |= V_141 |
V_142 |
V_143 ;
V_86 -> V_144 = F_45 ( V_21 -> V_144 ) ;
V_86 -> V_145 = F_45 ( V_21 -> V_145 ) ;
V_86 -> V_146 = V_21 -> V_146 ;
#endif
}
V_86 -> V_147 . V_5 = 0 ;
if ( V_12 -> V_24 . V_148 . V_149 )
V_86 -> V_147 . V_5 |= V_150 ;
if ( V_12 -> V_24 . V_148 . V_151 )
V_86 -> V_147 . V_5 |= V_152 ;
if ( V_12 -> V_24 . V_148 . V_153 )
V_86 -> V_147 . V_5 |= V_154 ;
V_86 -> V_147 . V_155 = V_12 -> V_9 -> V_77 . V_44 . V_156 ;
V_86 -> V_147 . V_157 = V_12 -> V_24 . V_148 . V_158 ;
}
static int F_46 ( struct V_2 * V_2 , struct V_1 * V_10 ,
int V_73 , T_2 * V_159 , struct V_85 * V_86 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_31 * V_21 ;
int V_17 = - V_47 ;
F_30 () ;
V_21 = F_47 ( V_12 , V_73 ) ;
if ( V_21 ) {
V_17 = 0 ;
memcpy ( V_159 , V_21 -> V_21 . V_160 , V_161 ) ;
F_40 ( V_21 , V_86 ) ;
}
F_34 () ;
return V_17 ;
}
static int F_48 ( struct V_2 * V_2 , struct V_1 * V_10 ,
int V_73 , struct V_162 * V_163 )
{
struct V_8 * V_9 = F_49 ( V_10 -> V_164 ) ;
return F_50 ( V_9 , V_73 , V_163 ) ;
}
static int F_51 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 * V_159 , struct V_85 * V_86 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_31 * V_21 ;
int V_17 = - V_47 ;
F_30 () ;
V_21 = F_21 ( V_12 , V_159 ) ;
if ( V_21 ) {
V_17 = 0 ;
F_40 ( V_21 , V_86 ) ;
}
F_34 () ;
return V_17 ;
}
static int F_52 ( struct V_11 * V_12 ,
struct V_165 * V_7 )
{
struct V_166 * V_167 , * V_168 ;
int V_169 , V_170 ;
int V_171 ;
int V_13 = - V_40 ;
V_168 = F_53 ( V_12 -> V_15 . V_172 . V_173 ) ;
if ( V_7 -> V_174 && ! V_7 -> V_175 )
return - V_40 ;
if ( V_7 -> V_176 &&
( V_12 -> V_24 . V_148 . V_158 != V_7 -> V_176 ) ) {
V_12 -> V_24 . V_148 . V_158 = V_7 -> V_176 ;
F_54 ( V_12 ,
V_177 ) ;
}
if ( ! V_7 -> V_174 && ! V_168 )
return V_13 ;
if ( ! V_7 -> V_155 && ! V_168 )
return V_13 ;
if ( V_7 -> V_174 )
V_169 = V_7 -> V_175 ;
else
V_169 = V_168 -> V_175 ;
if ( V_7 -> V_178 || ! V_168 )
V_170 = V_7 -> V_179 ;
else
V_170 = V_168 -> V_179 ;
V_171 = sizeof( * V_167 ) + V_169 + V_170 ;
V_167 = F_55 ( V_171 , V_180 ) ;
if ( ! V_167 )
return - V_181 ;
if ( V_7 -> V_155 )
V_167 -> V_155 = V_7 -> V_155 ;
else
V_167 -> V_155 = V_168 -> V_155 ;
V_167 -> V_174 = ( ( T_2 * ) V_167 ) + sizeof( * V_167 ) ;
V_167 -> V_178 = V_167 -> V_174 + V_169 ;
V_167 -> V_175 = V_169 ;
V_167 -> V_179 = V_170 ;
if ( V_7 -> V_174 )
memcpy ( V_167 -> V_174 , V_7 -> V_174 , V_169 ) ;
else
memcpy ( V_167 -> V_174 , V_168 -> V_174 , V_169 ) ;
if ( V_7 -> V_178 )
memcpy ( V_167 -> V_178 , V_7 -> V_178 , V_170 ) ;
else
if ( V_168 )
memcpy ( V_167 -> V_178 , V_168 -> V_178 , V_170 ) ;
V_12 -> V_24 . V_148 . V_155 = V_167 -> V_155 ;
F_10 ( V_12 -> V_15 . V_172 . V_173 , V_167 ) ;
F_56 () ;
F_57 ( V_168 ) ;
F_54 ( V_12 , V_182 |
V_183 ) ;
return 0 ;
}
static int F_58 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_165 * V_7 )
{
struct V_11 * V_12 ;
struct V_166 * V_168 ;
V_12 = F_5 ( V_10 ) ;
V_168 = F_53 ( V_12 -> V_15 . V_172 . V_173 ) ;
if ( V_168 )
return - V_184 ;
return F_52 ( V_12 , V_7 ) ;
}
static int F_59 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_165 * V_7 )
{
struct V_11 * V_12 ;
struct V_166 * V_168 ;
V_12 = F_5 ( V_10 ) ;
V_168 = F_53 ( V_12 -> V_15 . V_172 . V_173 ) ;
if ( ! V_168 )
return - V_47 ;
return F_52 ( V_12 , V_7 ) ;
}
static int F_60 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 ;
struct V_166 * V_168 ;
V_12 = F_5 ( V_10 ) ;
V_168 = F_53 ( V_12 -> V_15 . V_172 . V_173 ) ;
if ( ! V_168 )
return - V_47 ;
F_10 ( V_12 -> V_15 . V_172 . V_173 , NULL ) ;
F_56 () ;
F_57 ( V_168 ) ;
F_54 ( V_12 , V_182 ) ;
return 0 ;
}
static void F_61 ( struct V_31 * V_21 )
{
struct V_185 * V_186 ;
struct V_187 * V_188 ;
V_188 = F_62 ( sizeof( * V_186 ) ) ;
if ( ! V_188 )
return;
V_186 = (struct V_185 * ) F_63 ( V_188 , sizeof( * V_186 ) ) ;
memset ( V_186 -> V_189 , 0xff , V_161 ) ;
memcpy ( V_186 -> V_190 , V_21 -> V_21 . V_160 , V_161 ) ;
V_186 -> V_191 = F_64 ( 6 ) ;
V_186 -> V_192 = 0 ;
V_186 -> V_193 = 0x01 ;
V_186 -> V_194 = 0xaf ;
V_186 -> V_195 [ 0 ] = 0x81 ;
V_186 -> V_195 [ 1 ] = 1 ;
V_186 -> V_195 [ 2 ] = 0 ;
V_188 -> V_10 = V_21 -> V_12 -> V_10 ;
V_188 -> V_196 = F_65 ( V_188 , V_21 -> V_12 -> V_10 ) ;
memset ( V_188 -> V_197 , 0 , sizeof( V_188 -> V_197 ) ) ;
F_66 ( V_188 ) ;
}
static void F_67 ( struct V_8 * V_9 ,
struct V_31 * V_21 ,
struct V_198 * V_7 )
{
unsigned long V_5 ;
T_1 V_199 ;
int V_200 , V_201 ;
struct V_75 * V_76 ;
struct V_11 * V_12 = V_21 -> V_12 ;
T_1 V_202 , V_203 ;
V_76 = V_9 -> V_77 . V_2 -> V_78 [ V_9 -> V_204 -> V_80 ] ;
F_68 ( & V_21 -> V_205 , V_5 ) ;
V_202 = V_7 -> V_206 ;
V_203 = V_7 -> V_207 ;
if ( V_202 & F_69 ( V_208 ) ) {
V_21 -> V_5 &= ~ V_209 ;
if ( V_203 & F_69 ( V_208 ) )
V_21 -> V_5 |= V_209 ;
}
if ( V_202 & F_69 ( V_210 ) ) {
V_21 -> V_5 &= ~ V_211 ;
if ( V_203 & F_69 ( V_210 ) )
V_21 -> V_5 |= V_211 ;
}
if ( V_202 & F_69 ( V_212 ) ) {
V_21 -> V_5 &= ~ V_213 ;
V_21 -> V_21 . V_214 = false ;
if ( V_203 & F_69 ( V_212 ) ) {
V_21 -> V_5 |= V_213 ;
V_21 -> V_21 . V_214 = true ;
}
}
if ( V_202 & F_69 ( V_215 ) ) {
V_21 -> V_5 &= ~ V_216 ;
if ( V_203 & F_69 ( V_215 ) )
V_21 -> V_5 |= V_216 ;
}
if ( V_202 & F_69 ( V_217 ) ) {
V_21 -> V_5 &= ~ V_218 ;
if ( V_203 & F_69 ( V_217 ) )
V_21 -> V_5 |= V_218 ;
}
F_70 ( & V_21 -> V_205 , V_5 ) ;
if ( V_7 -> V_219 )
V_21 -> V_21 . V_219 = V_7 -> V_219 ;
if ( V_7 -> V_220 >= 0 )
V_21 -> V_220 = V_7 -> V_220 ;
if ( V_7 -> V_221 ) {
V_199 = 0 ;
for ( V_200 = 0 ; V_200 < V_7 -> V_222 ; V_200 ++ ) {
int V_72 = ( V_7 -> V_221 [ V_200 ] & 0x7f ) * 5 ;
for ( V_201 = 0 ; V_201 < V_76 -> V_223 ; V_201 ++ ) {
if ( V_76 -> V_82 [ V_201 ] . V_83 == V_72 )
V_199 |= F_69 ( V_201 ) ;
}
}
V_21 -> V_21 . V_224 [ V_9 -> V_204 -> V_80 ] = V_199 ;
}
if ( V_7 -> V_225 )
F_71 ( V_76 ,
V_7 -> V_225 ,
& V_21 -> V_21 . V_226 ) ;
if ( F_19 ( & V_12 -> V_24 ) ) {
#ifdef F_44
if ( V_12 -> V_15 . V_227 . V_228 & V_229 )
switch ( V_7 -> V_146 ) {
case V_230 :
case V_231 :
case V_232 :
V_21 -> V_146 = V_7 -> V_146 ;
break;
default:
break;
}
else
switch ( V_7 -> V_233 ) {
case V_234 :
F_72 ( V_21 ) ;
break;
case V_235 :
F_73 ( V_21 ) ;
break;
}
#endif
}
}
static int F_74 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 * V_159 , struct V_198 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_31 * V_21 ;
struct V_11 * V_12 ;
int V_13 ;
int V_236 ;
if ( V_7 -> V_20 ) {
V_12 = F_5 ( V_7 -> V_20 ) ;
if ( V_12 -> V_24 . type != V_18 &&
V_12 -> V_24 . type != V_237 )
return - V_40 ;
} else
V_12 = F_5 ( V_10 ) ;
if ( F_75 ( V_159 , V_12 -> V_24 . V_160 ) == 0 )
return - V_40 ;
if ( F_76 ( V_159 ) )
return - V_40 ;
V_21 = F_77 ( V_12 , V_159 , V_180 ) ;
if ( ! V_21 )
return - V_181 ;
V_21 -> V_5 = V_218 | V_238 ;
F_67 ( V_9 , V_21 , V_7 ) ;
F_78 ( V_21 ) ;
V_236 = V_12 -> V_24 . type == V_18 ||
V_12 -> V_24 . type == V_237 ;
V_13 = F_79 ( V_21 ) ;
if ( V_13 ) {
F_34 () ;
return V_13 ;
}
if ( V_236 )
F_61 ( V_21 ) ;
F_34 () ;
return 0 ;
}
static int F_80 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 * V_159 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
if ( V_159 )
return F_81 ( V_12 , V_159 ) ;
F_82 ( V_9 , V_12 ) ;
return 0 ;
}
static int F_83 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 * V_159 ,
struct V_198 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_31 * V_21 ;
struct V_11 * V_239 ;
F_30 () ;
V_21 = F_21 ( V_12 , V_159 ) ;
if ( ! V_21 ) {
F_34 () ;
return - V_47 ;
}
if ( V_7 -> V_20 && V_7 -> V_20 != V_21 -> V_12 -> V_10 ) {
V_239 = F_5 ( V_7 -> V_20 ) ;
if ( V_239 -> V_24 . type != V_18 &&
V_239 -> V_24 . type != V_237 ) {
F_34 () ;
return - V_40 ;
}
if ( V_7 -> V_20 -> V_164 -> V_19 ) {
if ( V_239 -> V_15 . V_20 . V_21 ) {
F_34 () ;
return - V_26 ;
}
F_10 ( V_239 -> V_15 . V_20 . V_21 , V_21 ) ;
}
V_21 -> V_12 = V_239 ;
F_61 ( V_21 ) ;
}
F_67 ( V_9 , V_21 , V_7 ) ;
F_34 () ;
if ( V_12 -> V_24 . type == V_22 &&
V_7 -> V_206 & F_69 ( V_208 ) )
F_84 ( V_9 , - 1 ) ;
return 0 ;
}
static int F_85 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 * V_240 , T_2 * V_241 )
{
struct V_11 * V_12 ;
struct V_242 * V_243 ;
struct V_31 * V_21 ;
int V_13 ;
V_12 = F_5 ( V_10 ) ;
F_30 () ;
V_21 = F_20 ( V_12 , V_241 ) ;
if ( ! V_21 ) {
F_34 () ;
return - V_47 ;
}
V_13 = F_86 ( V_240 , V_12 ) ;
if ( V_13 ) {
F_34 () ;
return V_13 ;
}
V_243 = F_87 ( V_240 , V_12 ) ;
if ( ! V_243 ) {
F_34 () ;
return - V_244 ;
}
F_88 ( V_243 , V_21 ) ;
F_34 () ;
return 0 ;
}
static int F_89 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 * V_240 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( V_240 )
return F_90 ( V_240 , V_12 ) ;
F_91 ( V_12 ) ;
return 0 ;
}
static int F_92 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 * V_240 , T_2 * V_241 )
{
struct V_11 * V_12 ;
struct V_242 * V_243 ;
struct V_31 * V_21 ;
V_12 = F_5 ( V_10 ) ;
F_30 () ;
V_21 = F_20 ( V_12 , V_241 ) ;
if ( ! V_21 ) {
F_34 () ;
return - V_47 ;
}
V_243 = F_87 ( V_240 , V_12 ) ;
if ( ! V_243 ) {
F_34 () ;
return - V_47 ;
}
F_88 ( V_243 , V_21 ) ;
F_34 () ;
return 0 ;
}
static void F_93 ( struct V_242 * V_243 , T_2 * V_241 ,
struct V_245 * V_246 )
{
struct V_31 * V_247 = F_31 ( V_243 -> V_241 ) ;
if ( V_247 )
memcpy ( V_241 , V_247 -> V_21 . V_160 , V_161 ) ;
else
memset ( V_241 , 0 , V_161 ) ;
V_246 -> V_89 = V_248 ;
V_246 -> V_91 = V_249 |
V_250 |
V_251 |
V_252 |
V_253 |
V_254 |
V_255 ;
V_246 -> V_256 = V_243 -> V_257 . V_258 ;
V_246 -> V_259 = V_243 -> V_259 ;
V_246 -> V_260 = V_243 -> V_260 ;
if ( F_94 ( V_108 , V_243 -> V_261 ) )
V_246 -> V_262 = F_42 ( V_243 -> V_261 - V_108 ) ;
V_246 -> V_263 =
F_42 ( V_243 -> V_263 ) ;
V_246 -> V_264 = V_243 -> V_264 ;
V_246 -> V_5 = 0 ;
if ( V_243 -> V_5 & V_265 )
V_246 -> V_5 |= V_266 ;
if ( V_243 -> V_5 & V_267 )
V_246 -> V_5 |= V_268 ;
if ( V_243 -> V_5 & V_269 )
V_246 -> V_5 |= V_270 ;
if ( V_243 -> V_5 & V_271 )
V_246 -> V_5 |= V_272 ;
if ( V_243 -> V_5 & V_267 )
V_246 -> V_5 |= V_268 ;
V_246 -> V_5 = V_243 -> V_5 ;
}
static int F_95 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 * V_240 , T_2 * V_241 , struct V_245 * V_246 )
{
struct V_11 * V_12 ;
struct V_242 * V_243 ;
V_12 = F_5 ( V_10 ) ;
F_30 () ;
V_243 = F_87 ( V_240 , V_12 ) ;
if ( ! V_243 ) {
F_34 () ;
return - V_47 ;
}
memcpy ( V_240 , V_243 -> V_240 , V_161 ) ;
F_93 ( V_243 , V_241 , V_246 ) ;
F_34 () ;
return 0 ;
}
static int F_96 ( struct V_2 * V_2 , struct V_1 * V_10 ,
int V_73 , T_2 * V_240 , T_2 * V_241 ,
struct V_245 * V_246 )
{
struct V_11 * V_12 ;
struct V_242 * V_243 ;
V_12 = F_5 ( V_10 ) ;
F_30 () ;
V_243 = F_97 ( V_73 , V_12 ) ;
if ( ! V_243 ) {
F_34 () ;
return - V_47 ;
}
memcpy ( V_240 , V_243 -> V_240 , V_161 ) ;
F_93 ( V_243 , V_241 , V_246 ) ;
F_34 () ;
return 0 ;
}
static int F_98 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_273 * V_44 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
memcpy ( V_44 , & ( V_12 -> V_15 . V_227 . V_274 ) , sizeof( struct V_273 ) ) ;
return 0 ;
}
static inline bool F_99 ( enum V_275 V_276 , T_1 V_202 )
{
return ( V_202 >> ( V_276 - 1 ) ) & 0x1 ;
}
static int F_100 ( struct V_277 * V_278 ,
const struct V_279 * V_280 )
{
T_2 * V_281 ;
const T_2 * V_282 ;
V_281 = NULL ;
V_282 = V_278 -> V_283 ;
if ( V_280 -> V_284 ) {
V_281 = F_101 ( V_280 -> V_283 , V_280 -> V_284 ,
V_180 ) ;
if ( ! V_281 )
return - V_181 ;
}
V_278 -> V_284 = V_280 -> V_284 ;
V_278 -> V_283 = V_281 ;
F_57 ( V_282 ) ;
V_278 -> V_285 = V_280 -> V_285 ;
memcpy ( V_278 -> V_286 , V_280 -> V_286 , V_278 -> V_285 ) ;
V_278 -> V_287 = V_280 -> V_288 ;
V_278 -> V_289 = V_280 -> V_290 ;
V_278 -> V_228 = V_291 ;
if ( V_280 -> V_292 )
V_278 -> V_228 |= V_293 ;
if ( V_280 -> V_294 )
V_278 -> V_228 |= V_229 ;
return 0 ;
}
static int F_102 ( struct V_2 * V_2 ,
struct V_1 * V_10 , T_1 V_202 ,
const struct V_273 * V_295 )
{
struct V_273 * V_44 ;
struct V_11 * V_12 ;
struct V_277 * V_278 ;
V_12 = F_5 ( V_10 ) ;
V_278 = & V_12 -> V_15 . V_227 ;
V_44 = & ( V_12 -> V_15 . V_227 . V_274 ) ;
if ( F_99 ( V_296 , V_202 ) )
V_44 -> V_297 = V_295 -> V_297 ;
if ( F_99 ( V_298 , V_202 ) )
V_44 -> V_299 = V_295 -> V_299 ;
if ( F_99 ( V_300 , V_202 ) )
V_44 -> V_301 = V_295 -> V_301 ;
if ( F_99 ( V_302 , V_202 ) )
V_44 -> V_303 = V_295 -> V_303 ;
if ( F_99 ( V_304 , V_202 ) )
V_44 -> V_305 = V_295 -> V_305 ;
if ( F_99 ( V_306 , V_202 ) )
V_44 -> V_307 = V_295 -> V_307 ;
if ( F_99 ( V_308 , V_202 ) )
V_44 -> V_307 = V_295 -> V_309 ;
if ( F_99 ( V_310 , V_202 ) )
V_44 -> V_311 = V_295 -> V_311 ;
if ( F_99 ( V_312 , V_202 ) )
V_44 -> V_313 =
V_295 -> V_313 ;
if ( F_99 ( V_314 , V_202 ) )
V_44 -> V_315 = V_295 -> V_315 ;
if ( F_99 ( V_316 , V_202 ) )
V_44 -> V_317 = V_295 -> V_317 ;
if ( F_99 ( V_318 , V_202 ) )
V_44 -> V_319 =
V_295 -> V_319 ;
if ( F_99 ( V_320 , V_202 ) )
V_44 -> V_321 =
V_295 -> V_321 ;
if ( F_99 ( V_322 ,
V_202 ) )
V_44 -> V_323 =
V_295 -> V_323 ;
if ( F_99 ( V_324 , V_202 ) ) {
V_44 -> V_325 = V_295 -> V_325 ;
F_103 ( V_278 ) ;
}
return 0 ;
}
static int F_104 ( struct V_2 * V_2 , struct V_1 * V_10 ,
const struct V_273 * V_44 ,
const struct V_279 * V_280 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_277 * V_278 = & V_12 -> V_15 . V_227 ;
int V_13 ;
memcpy ( & V_278 -> V_274 , V_44 , sizeof( struct V_273 ) ) ;
V_13 = F_100 ( V_278 , V_280 ) ;
if ( V_13 )
return V_13 ;
F_105 ( V_12 ) ;
return 0 ;
}
static int F_106 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
F_107 ( V_12 ) ;
return 0 ;
}
static int F_108 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_326 * V_7 )
{
struct V_11 * V_12 ;
T_1 V_327 = 0 ;
V_12 = F_5 ( V_10 ) ;
if ( V_7 -> V_149 >= 0 ) {
V_12 -> V_24 . V_148 . V_149 = V_7 -> V_149 ;
V_327 |= V_328 ;
}
if ( V_7 -> V_151 >= 0 ) {
V_12 -> V_24 . V_148 . V_151 =
V_7 -> V_151 ;
V_327 |= V_329 ;
}
if ( ! V_12 -> V_24 . V_148 . V_153 &&
V_12 -> V_9 -> V_77 . V_44 . V_79 -> V_80 == V_330 ) {
V_12 -> V_24 . V_148 . V_153 = true ;
V_327 |= V_331 ;
}
if ( V_7 -> V_332 >= 0 ) {
V_12 -> V_24 . V_148 . V_153 =
V_7 -> V_332 ;
V_327 |= V_331 ;
}
if ( V_7 -> V_333 ) {
int V_200 , V_201 ;
T_1 V_199 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_75 * V_76 =
V_2 -> V_78 [ V_9 -> V_204 -> V_80 ] ;
for ( V_200 = 0 ; V_200 < V_7 -> V_334 ; V_200 ++ ) {
int V_72 = ( V_7 -> V_333 [ V_200 ] & 0x7f ) * 5 ;
for ( V_201 = 0 ; V_201 < V_76 -> V_223 ; V_201 ++ ) {
if ( V_76 -> V_82 [ V_201 ] . V_83 == V_72 )
V_199 |= F_69 ( V_201 ) ;
}
}
V_12 -> V_24 . V_148 . V_333 = V_199 ;
V_327 |= V_335 ;
}
if ( V_7 -> V_336 >= 0 ) {
if ( V_7 -> V_336 )
V_12 -> V_5 |= V_337 ;
else
V_12 -> V_5 &= ~ V_337 ;
}
if ( V_7 -> V_338 >= 0 ) {
V_12 -> V_24 . V_148 . V_339 =
( T_4 ) V_7 -> V_338 ;
V_327 |= V_340 ;
}
F_54 ( V_12 , V_327 ) ;
return 0 ;
}
static int F_109 ( struct V_2 * V_2 ,
struct V_341 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_342 V_343 ;
if ( ! V_9 -> V_344 -> V_345 )
return - V_346 ;
memset ( & V_343 , 0 , sizeof( V_343 ) ) ;
V_343 . V_347 = V_7 -> V_347 ;
V_343 . V_348 = V_7 -> V_349 ;
V_343 . V_350 = V_7 -> V_351 ;
V_343 . V_352 = V_7 -> V_352 ;
V_343 . V_353 = false ;
if ( V_7 -> V_354 >= V_9 -> V_77 . V_355 )
return - V_40 ;
V_9 -> V_356 [ V_7 -> V_354 ] = V_343 ;
if ( F_110 ( V_9 , V_7 -> V_354 , & V_343 ) ) {
F_111 ( V_9 -> V_77 . V_2 ,
L_1 ,
V_7 -> V_354 ) ;
return - V_40 ;
}
return 0 ;
}
static int F_112 ( struct V_2 * V_2 ,
struct V_1 * V_357 ,
struct V_358 * V_359 ,
enum V_360 V_361 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = NULL ;
struct V_358 * V_362 ;
enum V_360 V_363 ;
enum V_360 V_364 = V_365 ;
if ( V_357 )
V_12 = F_5 ( V_357 ) ;
switch ( F_113 ( V_9 , NULL ) ) {
case V_366 :
return - V_26 ;
case V_367 :
if ( V_9 -> V_204 != V_359 )
return - V_26 ;
if ( ! V_12 && V_9 -> V_368 == V_361 )
return 0 ;
break;
case V_369 :
break;
}
if ( V_12 )
V_364 = V_12 -> V_24 . V_148 . V_361 ;
V_363 = V_9 -> V_368 ;
if ( ! F_114 ( V_9 , V_12 , V_361 ) )
return - V_26 ;
V_362 = V_9 -> V_204 ;
V_9 -> V_204 = V_359 ;
if ( ( V_362 != V_9 -> V_204 ) ||
( V_363 != V_9 -> V_368 ) )
F_115 ( V_9 , V_370 ) ;
if ( ( V_12 && V_12 -> V_24 . type != V_14 ) &&
V_364 != V_12 -> V_24 . V_148 . V_361 )
F_54 ( V_12 , V_340 ) ;
return 0 ;
}
static int F_116 ( struct V_2 * V_2 ,
struct V_371 * V_372 )
{
return F_117 ( F_2 ( V_2 ) , V_372 ) ;
}
static int F_118 ( struct V_2 * V_2 )
{
return F_119 ( F_2 ( V_2 ) ) ;
}
static int F_120 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_373 * V_374 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( F_121 ( & V_12 -> V_24 ) ) {
case V_22 :
case V_375 :
case V_376 :
case V_377 :
break;
case V_378 :
if ( V_12 -> V_9 -> V_344 -> V_379 )
break;
case V_237 :
if ( V_12 -> V_15 . V_172 . V_173 )
return - V_346 ;
break;
default:
return - V_346 ;
}
return F_122 ( V_12 , V_374 ) ;
}
static int
F_123 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_380 * V_374 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_12 -> V_9 -> V_344 -> V_381 )
return - V_346 ;
return F_124 ( V_12 , V_374 ) ;
}
static int
F_125 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_12 -> V_9 -> V_344 -> V_382 )
return - V_346 ;
return F_126 ( V_12 ) ;
}
static int F_127 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_383 * V_374 )
{
return F_128 ( F_5 ( V_10 ) , V_374 ) ;
}
static int F_129 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_384 * V_374 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( F_113 ( V_9 , V_12 ) ) {
case V_366 :
return - V_26 ;
case V_367 :
if ( V_9 -> V_204 == V_374 -> V_385 -> V_79 )
break;
return - V_26 ;
case V_369 :
break;
}
return F_130 ( F_5 ( V_10 ) , V_374 ) ;
}
static int F_131 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_386 * V_374 ,
void * V_53 )
{
return F_132 ( F_5 ( V_10 ) ,
V_374 , V_53 ) ;
}
static int F_133 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_387 * V_374 ,
void * V_53 )
{
return F_134 ( F_5 ( V_10 ) ,
V_374 , V_53 ) ;
}
static int F_135 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_388 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( F_113 ( V_9 , V_12 ) ) {
case V_366 :
return - V_26 ;
case V_367 :
if ( ! V_7 -> V_389 )
return - V_26 ;
if ( V_9 -> V_204 == V_7 -> V_79 )
break;
return - V_26 ;
case V_369 :
break;
}
return F_136 ( V_12 , V_7 ) ;
}
static int F_137 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
return F_138 ( V_12 ) ;
}
static int F_139 ( struct V_2 * V_2 , T_1 V_327 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_327 & V_390 ) {
V_13 = F_140 ( V_9 , V_2 -> V_391 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_327 & V_392 ) {
V_13 = F_141 ( V_9 , V_2 -> V_393 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_327 & V_394 ) {
V_13 = F_142 ( V_9 , V_2 -> V_395 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_327 & V_396 )
V_9 -> V_77 . V_44 . V_397 = V_2 -> V_398 ;
if ( V_327 & V_399 )
V_9 -> V_77 . V_44 . V_400 = V_2 -> V_401 ;
if ( V_327 &
( V_396 | V_399 ) )
F_115 ( V_9 , V_402 ) ;
return 0 ;
}
static int F_143 ( struct V_2 * V_2 ,
enum V_403 type , int V_404 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_358 * V_359 = V_9 -> V_77 . V_44 . V_79 ;
T_1 V_405 = 0 ;
switch ( type ) {
case V_406 :
V_9 -> V_407 = - 1 ;
break;
case V_408 :
if ( V_404 < 0 || ( V_404 % 100 ) )
return - V_346 ;
V_9 -> V_407 = F_144 ( V_404 ) ;
break;
case V_409 :
if ( V_404 < 0 || ( V_404 % 100 ) )
return - V_346 ;
if ( F_144 ( V_404 ) > V_359 -> V_410 )
return - V_40 ;
V_9 -> V_407 = F_144 ( V_404 ) ;
break;
}
F_115 ( V_9 , V_405 ) ;
return 0 ;
}
static int F_145 ( struct V_2 * V_2 , int * V_411 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
* V_411 = V_9 -> V_77 . V_44 . V_412 ;
return 0 ;
}
static int F_146 ( struct V_2 * V_2 , struct V_1 * V_10 ,
const T_2 * V_160 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
memcpy ( & V_12 -> V_15 . V_413 . V_414 , V_160 , V_161 ) ;
return 0 ;
}
static void F_147 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_148 ( V_9 ) ;
}
static int F_149 ( struct V_2 * V_2 , void * V_415 , int V_191 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_344 -> V_416 )
return - V_346 ;
return V_9 -> V_344 -> V_416 ( & V_9 -> V_77 , V_415 , V_191 ) ;
}
static int F_150 ( struct V_2 * V_2 ,
struct V_187 * V_188 ,
struct V_417 * V_197 ,
void * V_415 , int V_191 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_344 -> V_418 )
return - V_346 ;
return V_9 -> V_344 -> V_418 ( & V_9 -> V_77 , V_188 , V_197 , V_415 , V_191 ) ;
}
int F_151 ( struct V_11 * V_12 ,
enum V_419 V_420 )
{
const T_2 * V_172 ;
enum V_419 V_421 ;
int V_13 ;
F_152 ( & V_12 -> V_15 . V_23 . V_422 ) ;
V_421 = V_12 -> V_15 . V_23 . V_423 ;
V_12 -> V_15 . V_23 . V_423 = V_420 ;
if ( V_421 == V_420 &&
V_420 != V_424 )
return 0 ;
if ( ! V_12 -> V_15 . V_23 . V_425 ||
V_12 -> V_24 . V_148 . V_361 == V_365 ) {
F_18 ( & V_12 -> V_9 -> V_426 ) ;
F_153 ( V_12 -> V_9 ) ;
F_24 ( & V_12 -> V_9 -> V_426 ) ;
return 0 ;
}
V_172 = V_12 -> V_15 . V_23 . V_425 -> V_427 ;
if ( V_420 == V_424 ) {
if ( V_12 -> V_15 . V_23 . V_428 )
V_420 = V_429 ;
else
V_420 = V_430 ;
}
V_13 = F_154 ( V_12 , V_420 ,
V_172 , V_172 ) ;
if ( V_13 )
V_12 -> V_15 . V_23 . V_423 = V_421 ;
return V_13 ;
}
static int F_155 ( struct V_2 * V_2 , struct V_1 * V_10 ,
bool V_431 , int V_432 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_49 ( V_10 -> V_164 ) ;
if ( V_12 -> V_24 . type != V_22 )
return - V_346 ;
if ( ! ( V_9 -> V_77 . V_5 & V_433 ) )
return - V_346 ;
if ( V_431 == V_12 -> V_15 . V_23 . V_428 &&
V_432 == V_9 -> V_434 )
return 0 ;
V_12 -> V_15 . V_23 . V_428 = V_431 ;
V_9 -> V_434 = V_432 ;
F_18 ( & V_12 -> V_15 . V_23 . V_422 ) ;
F_151 ( V_12 , V_12 -> V_15 . V_23 . V_423 ) ;
F_24 ( & V_12 -> V_15 . V_23 . V_422 ) ;
if ( V_9 -> V_77 . V_5 & V_435 )
F_115 ( V_9 , V_436 ) ;
F_84 ( V_9 , - 1 ) ;
return 0 ;
}
static int F_156 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_5 V_437 , T_1 V_438 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_49 ( V_10 -> V_164 ) ;
struct V_439 * V_24 = & V_12 -> V_24 ;
struct V_440 * V_148 = & V_24 -> V_148 ;
if ( V_437 == V_148 -> V_441 &&
V_438 == V_148 -> V_442 )
return 0 ;
V_148 -> V_441 = V_437 ;
V_148 -> V_442 = V_438 ;
if ( ! ( V_9 -> V_77 . V_5 & V_443 ) ) {
if ( V_12 -> V_24 . type != V_22 )
return - V_346 ;
return 0 ;
}
if ( V_12 -> V_15 . V_23 . V_425 )
F_54 ( V_12 , V_444 ) ;
return 0 ;
}
static int F_157 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
const T_2 * V_160 ,
const struct V_445 * V_202 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_49 ( V_10 -> V_164 ) ;
int V_200 , V_17 ;
if ( V_9 -> V_77 . V_5 & V_446 ) {
V_17 = F_158 ( V_9 , V_12 , V_202 ) ;
if ( V_17 )
return V_17 ;
}
for ( V_200 = 0 ; V_200 < V_447 ; V_200 ++ )
V_12 -> V_448 [ V_200 ] = V_202 -> V_194 [ V_200 ] . V_81 ;
return 0 ;
}
static int F_159 ( struct V_8 * V_9 ,
struct V_1 * V_10 ,
struct V_358 * V_359 ,
enum V_360 V_449 ,
unsigned int V_450 , T_3 * V_53 )
{
int V_17 ;
T_1 V_451 ;
F_152 ( & V_9 -> V_422 ) ;
if ( V_9 -> V_452 )
return - V_26 ;
V_451 = F_160 () | 1 ;
* V_53 = V_451 ;
V_9 -> V_453 = V_10 ;
V_9 -> V_452 = V_451 ;
V_9 -> V_454 = V_359 ;
V_9 -> V_455 = V_449 ;
V_9 -> V_456 = V_450 ;
V_17 = F_161 ( V_9 , V_359 , V_449 , V_450 ) ;
if ( V_17 ) {
V_9 -> V_454 = NULL ;
V_9 -> V_452 = 0 ;
}
return V_17 ;
}
static int F_162 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_358 * V_359 ,
enum V_360 V_361 ,
unsigned int V_450 ,
T_3 * V_53 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
if ( V_9 -> V_344 -> V_457 ) {
int V_17 ;
F_18 ( & V_9 -> V_422 ) ;
V_17 = F_159 ( V_9 , V_10 ,
V_359 , V_361 ,
V_450 , V_53 ) ;
V_9 -> V_458 = false ;
F_24 ( & V_9 -> V_422 ) ;
return V_17 ;
}
return F_163 ( V_12 , V_359 , V_361 ,
V_450 , V_53 ) ;
}
static int F_164 ( struct V_8 * V_9 ,
T_3 V_53 )
{
int V_17 ;
F_152 ( & V_9 -> V_422 ) ;
if ( V_9 -> V_452 != V_53 )
return - V_47 ;
V_17 = F_165 ( V_9 ) ;
if ( V_17 )
return V_17 ;
V_9 -> V_452 = 0 ;
V_9 -> V_454 = NULL ;
F_166 ( V_9 ) ;
return 0 ;
}
static int F_167 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_3 V_53 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
if ( V_9 -> V_344 -> V_459 ) {
int V_17 ;
F_18 ( & V_9 -> V_422 ) ;
V_17 = F_164 ( V_9 , V_53 ) ;
F_24 ( & V_9 -> V_422 ) ;
return V_17 ;
}
return F_168 ( V_12 , V_53 ) ;
}
static enum V_460
F_169 ( struct V_461 * V_462 , struct V_187 * V_188 )
{
if ( V_462 -> V_463 . V_464 && V_462 -> V_463 . V_465 )
F_170 ( V_462 -> V_12 -> V_10 ,
( unsigned long ) V_462 -> V_463 . V_465 ,
V_462 -> V_283 , V_462 -> V_284 , false , V_180 ) ;
return V_466 ;
}
static int F_171 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_358 * V_359 , bool V_467 ,
enum V_360 V_361 ,
bool V_468 , unsigned int V_464 ,
const T_2 * V_469 , T_6 V_191 , T_3 * V_53 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_187 * V_188 ;
struct V_31 * V_21 ;
struct V_461 * V_462 ;
const struct V_470 * V_471 = ( void * ) V_469 ;
T_1 V_5 = V_472 |
V_473 ;
bool V_474 = false ;
if ( V_359 != V_9 -> V_475 &&
V_359 != V_9 -> V_204 )
V_474 = true ;
if ( V_468 &&
( V_361 != V_9 -> V_476 &&
V_361 != V_9 -> V_368 ) )
V_474 = true ;
if ( V_359 == V_9 -> V_454 ) {
V_474 = false ;
V_5 |= V_477 ;
}
if ( V_474 && ! V_467 )
return - V_26 ;
switch ( V_12 -> V_24 . type ) {
case V_375 :
case V_237 :
case V_18 :
case V_378 :
case V_376 :
if ( ! F_172 ( V_471 -> V_478 ) ||
V_471 -> V_15 . V_479 . V_480 == V_481 )
break;
F_30 () ;
V_21 = F_20 ( V_12 , V_471 -> V_189 ) ;
F_34 () ;
if ( ! V_21 )
return - V_482 ;
break;
case V_22 :
case V_377 :
break;
default:
return - V_346 ;
}
V_188 = F_62 ( V_9 -> V_77 . V_483 + V_191 ) ;
if ( ! V_188 )
return - V_181 ;
F_173 ( V_188 , V_9 -> V_77 . V_483 ) ;
memcpy ( F_63 ( V_188 , V_191 ) , V_469 , V_191 ) ;
F_174 ( V_188 ) -> V_5 = V_5 ;
V_188 -> V_10 = V_12 -> V_10 ;
* V_53 = ( unsigned long ) V_188 ;
if ( V_474 && V_9 -> V_344 -> V_484 ) {
int V_17 ;
F_174 ( V_188 ) -> V_80 = V_359 -> V_80 ;
F_18 ( & V_9 -> V_422 ) ;
if ( V_9 -> V_485 ) {
F_24 ( & V_9 -> V_422 ) ;
return - V_26 ;
}
V_17 = F_175 ( V_9 , V_188 , V_359 , V_361 , V_464 ) ;
if ( V_17 == 0 )
V_9 -> V_485 = * V_53 ;
F_24 ( & V_9 -> V_422 ) ;
if ( V_17 != 1 )
return V_17 ;
}
if ( V_474 && V_9 -> V_344 -> V_457 ) {
unsigned int V_450 ;
int V_17 ;
F_18 ( & V_9 -> V_422 ) ;
V_450 = 100 ;
if ( V_464 )
V_450 = V_464 ;
V_17 = F_159 ( V_9 , V_10 , V_359 ,
V_361 ,
V_450 , V_53 ) ;
if ( V_17 ) {
F_176 ( V_188 ) ;
F_24 ( & V_9 -> V_422 ) ;
return V_17 ;
}
V_9 -> V_458 = true ;
V_9 -> V_456 = V_464 ;
* V_53 ^= 2 ;
F_174 ( V_188 ) -> V_5 |= V_477 ;
V_9 -> V_486 = V_188 ;
V_9 -> V_487 = V_188 ;
F_24 ( & V_9 -> V_422 ) ;
return 0 ;
}
if ( ! V_474 && ! V_464 && ! V_12 -> V_24 . V_148 . V_488 ) {
F_177 ( V_12 , V_188 ) ;
return 0 ;
}
V_462 = F_55 ( sizeof( * V_462 ) + V_191 , V_180 ) ;
if ( ! V_462 ) {
F_176 ( V_188 ) ;
return - V_181 ;
}
V_462 -> type = V_489 ;
V_462 -> V_359 = V_359 ;
V_462 -> V_490 = V_361 ;
V_462 -> V_12 = V_12 ;
V_462 -> V_491 = F_169 ;
V_462 -> V_463 . V_465 = V_188 ;
V_462 -> V_463 . V_464 = V_464 ;
V_462 -> V_284 = V_191 ;
memcpy ( V_462 -> V_283 , V_469 , V_191 ) ;
F_178 ( V_462 ) ;
return 0 ;
}
static int F_179 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_3 V_53 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_461 * V_462 ;
int V_17 = - V_47 ;
F_18 ( & V_9 -> V_422 ) ;
if ( V_9 -> V_344 -> V_492 &&
V_9 -> V_485 == V_53 ) {
V_17 = F_180 ( V_9 ) ;
if ( ! V_17 )
V_9 -> V_485 = 0 ;
F_24 ( & V_9 -> V_422 ) ;
return V_17 ;
}
if ( V_9 -> V_344 -> V_459 ) {
V_53 ^= 2 ;
V_17 = F_164 ( V_9 , V_53 ) ;
if ( V_17 == 0 ) {
F_176 ( V_9 -> V_486 ) ;
V_9 -> V_486 = NULL ;
V_9 -> V_487 = NULL ;
}
F_24 ( & V_9 -> V_422 ) ;
return V_17 ;
}
F_181 (wk, &local->work_list, list) {
if ( V_462 -> V_12 != V_12 )
continue;
if ( V_462 -> type != V_489 )
continue;
if ( V_53 != ( unsigned long ) V_462 -> V_463 . V_465 )
continue;
V_462 -> V_432 = V_108 ;
F_182 ( & V_9 -> V_77 , & V_9 -> V_493 ) ;
V_17 = 0 ;
break;
}
F_24 ( & V_9 -> V_422 ) ;
return V_17 ;
}
static void F_183 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_494 , bool V_495 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_494 != ( V_496 | V_497 ) )
return;
if ( V_495 )
V_9 -> V_498 ++ ;
else
V_9 -> V_498 -- ;
F_182 ( & V_9 -> V_77 , & V_9 -> V_499 ) ;
}
static int F_184 ( struct V_2 * V_2 , T_1 V_500 , T_1 V_501 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_502 )
return - V_346 ;
return F_185 ( V_9 , V_500 , V_501 ) ;
}
static int F_186 ( struct V_2 * V_2 , T_1 * V_500 , T_1 * V_501 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_187 ( V_9 , V_500 , V_501 ) ;
}
static int F_188 ( struct V_2 * V_2 , T_1 V_60 , T_1 V_503 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_189 ( V_9 , V_60 , V_503 ) ;
}
static void F_190 ( struct V_2 * V_2 ,
T_1 * V_60 , T_1 * V_504 , T_1 * V_503 , T_1 * V_505 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_191 ( V_9 , V_60 , V_504 , V_503 , V_505 ) ;
}
static int F_192 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_506 * V_415 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_9 -> V_344 -> V_507 )
return - V_346 ;
F_193 ( V_9 , V_12 , V_415 ) ;
return 0 ;
}
