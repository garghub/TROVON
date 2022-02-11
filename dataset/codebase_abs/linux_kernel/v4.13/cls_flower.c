static unsigned short int F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 - V_2 -> V_3 . V_5 ;
}
static void F_2 ( struct V_1 * V_2 )
{
const T_1 * V_6 = ( const T_1 * ) & V_2 -> V_7 ;
T_2 V_8 = sizeof( V_2 -> V_7 ) ;
T_2 V_9 , V_10 = 0 , V_11 = V_8 - 1 ;
for ( V_9 = 0 ; V_9 < sizeof( V_2 -> V_7 ) ; V_9 ++ ) {
if ( V_6 [ V_9 ] ) {
if ( ! V_10 && V_9 )
V_10 = V_9 ;
V_11 = V_9 ;
}
}
V_2 -> V_3 . V_5 = F_3 ( V_10 , sizeof( long ) ) ;
V_2 -> V_3 . V_4 = F_4 ( V_11 + 1 , sizeof( long ) ) ;
}
static void * F_5 ( struct V_12 * V_7 ,
const struct V_1 * V_2 )
{
return ( T_1 * ) V_7 + V_2 -> V_3 . V_5 ;
}
static void F_6 ( struct V_12 * V_13 , struct V_12 * V_7 ,
struct V_1 * V_2 )
{
const long * V_14 = F_5 ( V_7 , V_2 ) ;
const long * V_15 = F_5 ( & V_2 -> V_7 , V_2 ) ;
long * V_16 = F_5 ( V_13 , V_2 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < F_1 ( V_2 ) ; V_9 += sizeof( long ) )
* V_16 ++ = * V_14 ++ & * V_15 ++ ;
}
static void F_7 ( struct V_12 * V_7 ,
struct V_1 * V_2 )
{
memset ( F_5 ( V_7 , V_2 ) , 0 , F_1 ( V_2 ) ) ;
}
static struct V_17 * F_8 ( struct V_18 * V_19 ,
struct V_12 * V_13 )
{
return F_9 ( & V_19 -> V_20 ,
F_5 ( V_13 , & V_19 -> V_2 ) ,
V_19 -> V_21 ) ;
}
static int F_10 ( struct V_22 * V_23 , const struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_18 * V_19 = F_11 ( V_25 -> V_28 ) ;
struct V_17 * V_29 ;
struct V_12 V_30 ;
struct V_12 V_31 ;
struct V_32 * V_33 ;
if ( ! F_12 ( & V_19 -> V_20 . V_34 ) )
return - 1 ;
F_7 ( & V_30 , & V_19 -> V_2 ) ;
V_33 = F_13 ( V_23 ) ;
if ( V_33 ) {
struct V_35 * V_7 = & V_33 -> V_7 ;
switch ( F_14 ( V_33 ) ) {
case V_36 :
V_30 . V_37 . V_38 =
V_39 ;
V_30 . V_40 . V_41 = V_7 -> V_42 . V_43 . V_41 ;
V_30 . V_40 . V_44 = V_7 -> V_42 . V_43 . V_44 ;
break;
case V_45 :
V_30 . V_37 . V_38 =
V_46 ;
V_30 . V_47 . V_41 = V_7 -> V_42 . V_48 . V_41 ;
V_30 . V_47 . V_44 = V_7 -> V_42 . V_48 . V_44 ;
break;
}
V_30 . V_49 . V_50 = F_15 ( V_7 -> V_51 ) ;
V_30 . V_52 . V_41 = V_7 -> V_53 ;
V_30 . V_52 . V_44 = V_7 -> V_54 ;
}
V_30 . V_55 = V_23 -> V_56 ;
V_30 . V_57 . V_58 = V_23 -> V_59 ;
F_16 ( V_23 , & V_19 -> V_60 , & V_30 , 0 ) ;
F_6 ( & V_31 , & V_30 , & V_19 -> V_2 ) ;
V_29 = F_8 ( V_19 , & V_31 ) ;
if ( V_29 && ! F_17 ( V_29 -> V_61 ) ) {
* V_27 = V_29 -> V_27 ;
return F_18 ( V_23 , & V_29 -> V_62 , V_27 ) ;
}
return - 1 ;
}
static int F_19 ( struct V_24 * V_25 )
{
struct V_18 * V_19 ;
V_19 = F_20 ( sizeof( * V_19 ) , V_63 ) ;
if ( ! V_19 )
return - V_64 ;
F_21 ( & V_19 -> V_65 ) ;
F_22 ( V_25 -> V_28 , V_19 ) ;
return 0 ;
}
static void F_23 ( struct V_66 * V_19 )
{
struct V_17 * V_29 = F_24 ( V_19 , struct V_17 , V_67 ) ;
F_25 ( & V_29 -> V_62 ) ;
F_26 ( V_29 ) ;
}
static void F_27 ( struct V_24 * V_25 , struct V_17 * V_29 )
{
struct V_68 V_69 = { 0 } ;
struct V_70 * V_71 = V_29 -> V_72 ;
struct V_73 * V_74 = & V_29 -> V_74 ;
if ( ! F_28 ( V_71 , V_25 ) )
return;
V_69 . V_75 = V_76 ;
V_69 . V_77 = V_25 -> V_77 ;
V_69 . V_78 = ( unsigned long ) V_29 ;
V_74 -> type = V_79 ;
V_74 -> V_80 = & V_69 ;
V_71 -> V_81 -> V_82 ( V_71 , V_25 -> V_83 -> V_84 , V_25 -> V_85 -> V_86 ,
V_25 -> V_59 , V_74 ) ;
}
static int F_29 ( struct V_24 * V_25 ,
struct V_87 * V_60 ,
struct V_12 * V_2 ,
struct V_17 * V_29 )
{
struct V_70 * V_71 = V_25 -> V_83 -> V_88 -> V_71 ;
struct V_68 V_69 = { 0 } ;
struct V_73 * V_74 = & V_29 -> V_74 ;
int V_89 ;
if ( ! F_28 ( V_71 , V_25 ) ) {
if ( F_30 ( V_71 , & V_29 -> V_62 , & V_29 -> V_72 ) ||
( V_29 -> V_72 && ! F_28 ( V_29 -> V_72 , V_25 ) ) ) {
V_29 -> V_72 = V_71 ;
return F_17 ( V_29 -> V_61 ) ? - V_90 : 0 ;
}
V_71 = V_29 -> V_72 ;
V_74 -> V_91 = true ;
} else {
V_29 -> V_72 = V_71 ;
}
V_69 . V_75 = V_92 ;
V_69 . V_77 = V_25 -> V_77 ;
V_69 . V_78 = ( unsigned long ) V_29 ;
V_69 . V_60 = V_60 ;
V_69 . V_2 = V_2 ;
V_69 . V_7 = & V_29 -> V_13 ;
V_69 . V_62 = & V_29 -> V_62 ;
V_74 -> type = V_79 ;
V_74 -> V_80 = & V_69 ;
V_89 = V_71 -> V_81 -> V_82 ( V_71 , V_25 -> V_83 -> V_84 ,
V_25 -> V_85 -> V_86 , V_25 -> V_59 , V_74 ) ;
if ( ! V_89 )
V_29 -> V_61 |= V_93 ;
if ( F_17 ( V_29 -> V_61 ) )
return V_89 ;
return 0 ;
}
static void F_31 ( struct V_24 * V_25 , struct V_17 * V_29 )
{
struct V_68 V_69 = { 0 } ;
struct V_70 * V_71 = V_29 -> V_72 ;
struct V_73 * V_74 = & V_29 -> V_74 ;
if ( ! F_28 ( V_71 , V_25 ) )
return;
V_69 . V_75 = V_94 ;
V_69 . V_77 = V_25 -> V_77 ;
V_69 . V_78 = ( unsigned long ) V_29 ;
V_69 . V_62 = & V_29 -> V_62 ;
V_74 -> type = V_79 ;
V_74 -> V_80 = & V_69 ;
V_71 -> V_81 -> V_82 ( V_71 , V_25 -> V_83 -> V_84 ,
V_25 -> V_85 -> V_86 , V_25 -> V_59 , V_74 ) ;
}
static void F_32 ( struct V_24 * V_25 , struct V_17 * V_29 )
{
F_33 ( & V_29 -> V_95 ) ;
if ( ! F_34 ( V_29 -> V_61 ) )
F_27 ( V_25 , V_29 ) ;
F_35 ( V_25 , & V_29 -> V_27 ) ;
F_36 ( & V_29 -> V_67 , F_23 ) ;
}
static void F_37 ( struct V_96 * V_97 )
{
struct V_18 * V_19 = F_24 ( V_97 , struct V_18 ,
V_97 ) ;
if ( V_19 -> V_98 )
F_38 ( & V_19 -> V_20 ) ;
F_26 ( V_19 ) ;
F_39 ( V_99 ) ;
}
static void F_40 ( struct V_66 * V_67 )
{
struct V_18 * V_19 = F_24 ( V_67 , struct V_18 , V_67 ) ;
F_41 ( & V_19 -> V_97 , F_37 ) ;
F_42 ( & V_19 -> V_97 ) ;
}
static void F_43 ( struct V_24 * V_25 )
{
struct V_18 * V_19 = F_44 ( V_25 -> V_28 ) ;
struct V_17 * V_29 , * V_100 ;
F_45 (f, next, &head->filters, list)
F_32 ( V_25 , V_29 ) ;
F_46 ( V_99 ) ;
F_36 ( & V_19 -> V_67 , F_40 ) ;
}
static unsigned long F_47 ( struct V_24 * V_25 , T_3 V_84 )
{
struct V_18 * V_19 = F_44 ( V_25 -> V_28 ) ;
struct V_17 * V_29 ;
F_48 (f, &head->filters, list)
if ( V_29 -> V_84 == V_84 )
return ( unsigned long ) V_29 ;
return 0 ;
}
static void F_49 ( struct V_101 * * V_102 ,
void * V_103 , int V_104 ,
void * V_2 , int V_105 , int V_106 )
{
if ( ! V_102 [ V_104 ] )
return;
memcpy ( V_103 , F_50 ( V_102 [ V_104 ] ) , V_106 ) ;
if ( V_105 == V_107 || ! V_102 [ V_105 ] )
memset ( V_2 , 0xff , V_106 ) ;
else
memcpy ( V_2 , F_50 ( V_102 [ V_105 ] ) , V_106 ) ;
}
static int F_51 ( struct V_101 * * V_102 ,
struct V_108 * V_109 ,
struct V_108 * V_110 )
{
if ( V_102 [ V_111 ] ) {
V_109 -> V_112 = F_52 ( V_102 [ V_111 ] ) ;
V_110 -> V_112 = V_113 ;
}
if ( V_102 [ V_114 ] ) {
T_1 V_115 = F_52 ( V_102 [ V_114 ] ) ;
if ( V_115 & ~ V_116 )
return - V_90 ;
V_109 -> V_117 = V_115 ;
V_110 -> V_117 = V_116 ;
}
if ( V_102 [ V_118 ] ) {
T_1 V_74 = F_52 ( V_102 [ V_118 ] ) ;
if ( V_74 & ~ V_119 )
return - V_90 ;
V_109 -> V_120 = V_74 ;
V_110 -> V_120 = V_119 ;
}
if ( V_102 [ V_121 ] ) {
T_3 V_122 = F_53 ( V_102 [ V_121 ] ) ;
if ( V_122 & ~ V_123 )
return - V_90 ;
V_109 -> V_124 = V_122 ;
V_110 -> V_124 = V_123 ;
}
return 0 ;
}
static void F_54 ( struct V_101 * * V_102 ,
struct V_125 * V_109 ,
struct V_125 * V_110 )
{
#define F_55 0x7
if ( V_102 [ V_126 ] ) {
V_109 -> V_127 =
F_56 ( V_102 [ V_126 ] ) & V_128 ;
V_110 -> V_127 = V_128 ;
}
if ( V_102 [ V_129 ] ) {
V_109 -> V_130 =
F_52 ( V_102 [ V_129 ] ) &
F_55 ;
V_110 -> V_130 = F_55 ;
}
}
static void F_57 ( T_3 V_131 , T_3 V_132 ,
T_3 * V_133 , T_3 * V_134 ,
T_3 V_135 , T_3 V_136 )
{
if ( V_132 & V_135 ) {
* V_134 |= V_136 ;
if ( V_131 & V_135 )
* V_133 |= V_136 ;
}
}
static int F_58 ( struct V_101 * * V_102 ,
T_3 * V_137 , T_3 * V_138 )
{
T_3 V_7 , V_2 ;
if ( ! V_102 [ V_139 ] )
return - V_90 ;
V_7 = F_59 ( F_53 ( V_102 [ V_140 ] ) ) ;
V_2 = F_59 ( F_53 ( V_102 [ V_139 ] ) ) ;
* V_137 = 0 ;
* V_138 = 0 ;
F_57 ( V_7 , V_2 , V_137 , V_138 ,
V_141 , V_142 ) ;
return 0 ;
}
static void F_60 ( struct V_101 * * V_102 ,
struct V_143 * V_7 ,
struct V_143 * V_2 )
{
F_49 ( V_102 , & V_7 -> V_144 , V_145 ,
& V_2 -> V_144 , V_146 ,
sizeof( V_7 -> V_144 ) ) ;
F_49 ( V_102 , & V_7 -> V_147 , V_148 ,
& V_2 -> V_147 , V_149 ,
sizeof( V_7 -> V_147 ) ) ;
}
static int F_61 ( struct V_150 * V_150 , struct V_101 * * V_102 ,
struct V_12 * V_7 , struct V_12 * V_2 )
{
T_4 V_151 ;
int V_152 = 0 ;
#ifdef F_62
if ( V_102 [ V_153 ] ) {
int V_89 = F_63 ( V_150 , V_102 [ V_153 ] ) ;
if ( V_89 < 0 )
return V_89 ;
V_7 -> V_55 = V_89 ;
V_2 -> V_55 = 0xffffffff ;
}
#endif
F_49 ( V_102 , V_7 -> V_154 . V_44 , V_155 ,
V_2 -> V_154 . V_44 , V_156 ,
sizeof( V_7 -> V_154 . V_44 ) ) ;
F_49 ( V_102 , V_7 -> V_154 . V_41 , V_157 ,
V_2 -> V_154 . V_41 , V_158 ,
sizeof( V_7 -> V_154 . V_41 ) ) ;
if ( V_102 [ V_159 ] ) {
V_151 = F_64 ( V_102 [ V_159 ] ) ;
if ( V_151 == F_65 ( V_160 ) ) {
F_54 ( V_102 , & V_7 -> V_161 , & V_2 -> V_161 ) ;
F_49 ( V_102 , & V_7 -> V_57 . V_58 ,
V_162 ,
& V_2 -> V_57 . V_58 , V_107 ,
sizeof( V_7 -> V_57 . V_58 ) ) ;
} else {
V_7 -> V_57 . V_58 = V_151 ;
V_2 -> V_57 . V_58 = F_66 ( ~ 0 ) ;
}
}
if ( V_7 -> V_57 . V_58 == F_65 ( V_163 ) ||
V_7 -> V_57 . V_58 == F_65 ( V_164 ) ) {
F_49 ( V_102 , & V_7 -> V_57 . V_165 , V_166 ,
& V_2 -> V_57 . V_165 , V_107 ,
sizeof( V_7 -> V_57 . V_165 ) ) ;
F_60 ( V_102 , & V_7 -> V_167 , & V_2 -> V_167 ) ;
}
if ( V_102 [ V_168 ] || V_102 [ V_169 ] ) {
V_7 -> V_170 . V_38 = V_39 ;
V_2 -> V_170 . V_38 = ~ 0 ;
F_49 ( V_102 , & V_7 -> V_43 . V_41 , V_168 ,
& V_2 -> V_43 . V_41 , V_171 ,
sizeof( V_7 -> V_43 . V_41 ) ) ;
F_49 ( V_102 , & V_7 -> V_43 . V_44 , V_169 ,
& V_2 -> V_43 . V_44 , V_172 ,
sizeof( V_7 -> V_43 . V_44 ) ) ;
} else if ( V_102 [ V_173 ] || V_102 [ V_174 ] ) {
V_7 -> V_170 . V_38 = V_46 ;
V_2 -> V_170 . V_38 = ~ 0 ;
F_49 ( V_102 , & V_7 -> V_48 . V_41 , V_173 ,
& V_2 -> V_48 . V_41 , V_175 ,
sizeof( V_7 -> V_48 . V_41 ) ) ;
F_49 ( V_102 , & V_7 -> V_48 . V_44 , V_174 ,
& V_2 -> V_48 . V_44 , V_176 ,
sizeof( V_7 -> V_48 . V_44 ) ) ;
}
if ( V_7 -> V_57 . V_165 == V_177 ) {
F_49 ( V_102 , & V_7 -> V_25 . V_41 , V_178 ,
& V_2 -> V_25 . V_41 , V_179 ,
sizeof( V_7 -> V_25 . V_41 ) ) ;
F_49 ( V_102 , & V_7 -> V_25 . V_44 , V_180 ,
& V_2 -> V_25 . V_44 , V_181 ,
sizeof( V_7 -> V_25 . V_44 ) ) ;
F_49 ( V_102 , & V_7 -> V_182 . V_61 , V_183 ,
& V_2 -> V_182 . V_61 , V_184 ,
sizeof( V_7 -> V_182 . V_61 ) ) ;
} else if ( V_7 -> V_57 . V_165 == V_185 ) {
F_49 ( V_102 , & V_7 -> V_25 . V_41 , V_186 ,
& V_2 -> V_25 . V_41 , V_187 ,
sizeof( V_7 -> V_25 . V_41 ) ) ;
F_49 ( V_102 , & V_7 -> V_25 . V_44 , V_188 ,
& V_2 -> V_25 . V_44 , V_189 ,
sizeof( V_7 -> V_25 . V_44 ) ) ;
} else if ( V_7 -> V_57 . V_165 == V_190 ) {
F_49 ( V_102 , & V_7 -> V_25 . V_41 , V_191 ,
& V_2 -> V_25 . V_41 , V_192 ,
sizeof( V_7 -> V_25 . V_41 ) ) ;
F_49 ( V_102 , & V_7 -> V_25 . V_44 , V_193 ,
& V_2 -> V_25 . V_44 , V_194 ,
sizeof( V_7 -> V_25 . V_44 ) ) ;
} else if ( V_7 -> V_57 . V_58 == F_65 ( V_163 ) &&
V_7 -> V_57 . V_165 == V_195 ) {
F_49 ( V_102 , & V_7 -> V_196 . type , V_197 ,
& V_2 -> V_196 . type ,
V_198 ,
sizeof( V_7 -> V_196 . type ) ) ;
F_49 ( V_102 , & V_7 -> V_196 . V_199 , V_200 ,
& V_2 -> V_196 . V_199 ,
V_201 ,
sizeof( V_7 -> V_196 . V_199 ) ) ;
} else if ( V_7 -> V_57 . V_58 == F_65 ( V_164 ) &&
V_7 -> V_57 . V_165 == V_202 ) {
F_49 ( V_102 , & V_7 -> V_196 . type , V_203 ,
& V_2 -> V_196 . type ,
V_204 ,
sizeof( V_7 -> V_196 . type ) ) ;
F_49 ( V_102 , & V_7 -> V_196 . V_199 , V_205 ,
& V_2 -> V_196 . V_199 ,
V_206 ,
sizeof( V_7 -> V_196 . V_199 ) ) ;
} else if ( V_7 -> V_57 . V_58 == F_65 ( V_207 ) ||
V_7 -> V_57 . V_58 == F_65 ( V_208 ) ) {
V_152 = F_51 ( V_102 , & V_7 -> V_209 , & V_2 -> V_209 ) ;
if ( V_152 )
return V_152 ;
} else if ( V_7 -> V_57 . V_58 == F_65 ( V_210 ) ||
V_7 -> V_57 . V_58 == F_65 ( V_211 ) ) {
F_49 ( V_102 , & V_7 -> V_212 . V_213 , V_214 ,
& V_2 -> V_212 . V_213 , V_215 ,
sizeof( V_7 -> V_212 . V_213 ) ) ;
F_49 ( V_102 , & V_7 -> V_212 . V_216 , V_217 ,
& V_2 -> V_212 . V_216 , V_218 ,
sizeof( V_7 -> V_212 . V_216 ) ) ;
F_49 ( V_102 , & V_7 -> V_212 . V_219 , V_220 ,
& V_2 -> V_212 . V_219 , V_221 ,
sizeof( V_7 -> V_212 . V_219 ) ) ;
F_49 ( V_102 , V_7 -> V_212 . V_222 , V_223 ,
V_2 -> V_212 . V_222 , V_224 ,
sizeof( V_7 -> V_212 . V_222 ) ) ;
F_49 ( V_102 , V_7 -> V_212 . V_225 , V_226 ,
V_2 -> V_212 . V_225 , V_227 ,
sizeof( V_7 -> V_212 . V_225 ) ) ;
}
if ( V_102 [ V_228 ] ||
V_102 [ V_229 ] ) {
V_7 -> V_37 . V_38 = V_39 ;
V_2 -> V_37 . V_38 = ~ 0 ;
F_49 ( V_102 , & V_7 -> V_40 . V_41 ,
V_228 ,
& V_2 -> V_40 . V_41 ,
V_230 ,
sizeof( V_7 -> V_40 . V_41 ) ) ;
F_49 ( V_102 , & V_7 -> V_40 . V_44 ,
V_229 ,
& V_2 -> V_40 . V_44 ,
V_231 ,
sizeof( V_7 -> V_40 . V_44 ) ) ;
}
if ( V_102 [ V_232 ] ||
V_102 [ V_233 ] ) {
V_7 -> V_37 . V_38 = V_46 ;
V_2 -> V_37 . V_38 = ~ 0 ;
F_49 ( V_102 , & V_7 -> V_47 . V_41 ,
V_232 ,
& V_2 -> V_47 . V_41 ,
V_234 ,
sizeof( V_7 -> V_47 . V_41 ) ) ;
F_49 ( V_102 , & V_7 -> V_47 . V_44 ,
V_233 ,
& V_2 -> V_47 . V_44 ,
V_235 ,
sizeof( V_7 -> V_47 . V_44 ) ) ;
}
F_49 ( V_102 , & V_7 -> V_49 . V_50 , V_236 ,
& V_2 -> V_49 . V_50 , V_107 ,
sizeof( V_7 -> V_49 . V_50 ) ) ;
F_49 ( V_102 , & V_7 -> V_52 . V_41 , V_237 ,
& V_2 -> V_52 . V_41 , V_238 ,
sizeof( V_7 -> V_52 . V_41 ) ) ;
F_49 ( V_102 , & V_7 -> V_52 . V_44 , V_239 ,
& V_2 -> V_52 . V_44 , V_240 ,
sizeof( V_7 -> V_52 . V_44 ) ) ;
if ( V_102 [ V_140 ] )
V_152 = F_58 ( V_102 , & V_7 -> V_170 . V_61 , & V_2 -> V_170 . V_61 ) ;
return V_152 ;
}
static bool F_67 ( struct V_1 * V_241 ,
struct V_1 * V_242 )
{
const long * V_243 = F_5 ( & V_241 -> V_7 , V_241 ) ;
const long * V_244 = F_5 ( & V_242 -> V_7 , V_242 ) ;
return ! memcmp ( & V_241 -> V_3 , & V_242 -> V_3 , sizeof( V_241 -> V_3 ) ) &&
! memcmp ( V_243 , V_244 , F_1 ( V_241 ) ) ;
}
static int F_68 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
V_19 -> V_21 = V_245 ;
V_19 -> V_21 . V_246 = F_1 ( V_2 ) ;
V_19 -> V_21 . V_247 += V_2 -> V_3 . V_5 ;
return F_69 ( & V_19 -> V_20 , & V_19 -> V_21 ) ;
}
static void F_70 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
struct V_248 V_249 [ V_250 ] ;
T_2 V_251 = 0 ;
F_71 ( V_249 , V_251 , V_252 , V_170 ) ;
F_71 ( V_249 , V_251 , V_253 , V_57 ) ;
F_72 ( & V_2 -> V_7 , V_249 , V_251 ,
V_254 , V_154 ) ;
F_72 ( & V_2 -> V_7 , V_249 , V_251 ,
V_39 , V_43 ) ;
F_72 ( & V_2 -> V_7 , V_249 , V_251 ,
V_46 , V_48 ) ;
F_72 ( & V_2 -> V_7 , V_249 , V_251 ,
V_255 , V_25 ) ;
F_72 ( & V_2 -> V_7 , V_249 , V_251 ,
V_256 , V_167 ) ;
F_72 ( & V_2 -> V_7 , V_249 , V_251 ,
V_257 , V_182 ) ;
F_72 ( & V_2 -> V_7 , V_249 , V_251 ,
V_258 , V_196 ) ;
F_72 ( & V_2 -> V_7 , V_249 , V_251 ,
V_259 , V_212 ) ;
F_72 ( & V_2 -> V_7 , V_249 , V_251 ,
V_260 , V_209 ) ;
F_72 ( & V_2 -> V_7 , V_249 , V_251 ,
V_261 , V_161 ) ;
F_72 ( & V_2 -> V_7 , V_249 , V_251 ,
V_262 , V_49 ) ;
F_72 ( & V_2 -> V_7 , V_249 , V_251 ,
V_263 , V_40 ) ;
F_72 ( & V_2 -> V_7 , V_249 , V_251 ,
V_264 , V_47 ) ;
if ( F_73 ( & V_2 -> V_7 , V_40 ) ||
F_73 ( & V_2 -> V_7 , V_47 ) )
F_71 ( V_249 , V_251 , V_265 ,
V_37 ) ;
F_72 ( & V_2 -> V_7 , V_249 , V_251 ,
V_266 , V_52 ) ;
F_74 ( & V_19 -> V_60 , V_249 , V_251 ) ;
}
static int F_75 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
int V_89 ;
if ( V_19 -> V_98 ) {
if ( ! F_67 ( & V_19 -> V_2 , V_2 ) )
return - V_90 ;
else
return 0 ;
}
V_89 = F_68 ( V_19 , V_2 ) ;
if ( V_89 )
return V_89 ;
memcpy ( & V_19 -> V_2 , V_2 , sizeof( V_19 -> V_2 ) ) ;
V_19 -> V_98 = true ;
F_70 ( V_19 , V_2 ) ;
return 0 ;
}
static int F_76 ( struct V_150 * V_150 , struct V_24 * V_25 ,
struct V_17 * V_29 , struct V_1 * V_2 ,
unsigned long V_267 , struct V_101 * * V_102 ,
struct V_101 * V_268 , bool V_269 )
{
struct V_270 V_271 ;
int V_89 ;
V_89 = F_77 ( & V_271 , V_272 , 0 ) ;
if ( V_89 < 0 )
return V_89 ;
V_89 = F_78 ( V_150 , V_25 , V_102 , V_268 , & V_271 , V_269 ) ;
if ( V_89 < 0 )
goto V_273;
if ( V_102 [ V_274 ] ) {
V_29 -> V_27 . V_275 = F_53 ( V_102 [ V_274 ] ) ;
F_79 ( V_25 , & V_29 -> V_27 , V_267 ) ;
}
V_89 = F_61 ( V_150 , V_102 , & V_29 -> V_7 , & V_2 -> V_7 ) ;
if ( V_89 )
goto V_273;
F_2 ( V_2 ) ;
F_6 ( & V_29 -> V_13 , & V_29 -> V_7 , V_2 ) ;
F_80 ( V_25 , & V_29 -> V_62 , & V_271 ) ;
return 0 ;
V_273:
F_25 ( & V_271 ) ;
return V_89 ;
}
static T_3 F_81 ( struct V_24 * V_25 ,
struct V_18 * V_19 )
{
unsigned int V_9 = 0x80000000 ;
T_3 V_84 ;
do {
if ( ++ V_19 -> V_276 == 0x7FFFFFFF )
V_19 -> V_276 = 1 ;
} while ( -- V_9 > 0 && F_47 ( V_25 , V_19 -> V_276 ) );
if ( F_82 ( V_9 == 0 ) ) {
F_83 ( L_1 ) ;
V_84 = 0 ;
} else {
V_84 = V_19 -> V_276 ;
}
return V_84 ;
}
static int F_84 ( struct V_150 * V_150 , struct V_22 * V_277 ,
struct V_24 * V_25 , unsigned long V_267 ,
T_3 V_84 , struct V_101 * * V_278 ,
unsigned long * V_279 , bool V_269 )
{
struct V_18 * V_19 = F_44 ( V_25 -> V_28 ) ;
struct V_17 * V_280 = (struct V_17 * ) * V_279 ;
struct V_17 * V_281 ;
struct V_101 * * V_102 ;
struct V_1 V_2 = {} ;
int V_89 ;
if ( ! V_278 [ V_282 ] )
return - V_90 ;
V_102 = F_85 ( V_283 + 1 , sizeof( struct V_101 * ) , V_63 ) ;
if ( ! V_102 )
return - V_64 ;
V_89 = F_86 ( V_102 , V_283 , V_278 [ V_282 ] ,
V_284 , NULL ) ;
if ( V_89 < 0 )
goto V_285;
if ( V_280 && V_84 && V_280 -> V_84 != V_84 ) {
V_89 = - V_90 ;
goto V_285;
}
V_281 = F_20 ( sizeof( * V_281 ) , V_63 ) ;
if ( ! V_281 ) {
V_89 = - V_64 ;
goto V_285;
}
V_89 = F_77 ( & V_281 -> V_62 , V_272 , 0 ) ;
if ( V_89 < 0 )
goto V_273;
if ( ! V_84 ) {
V_84 = F_81 ( V_25 , V_19 ) ;
if ( ! V_84 ) {
V_89 = - V_90 ;
goto V_273;
}
}
V_281 -> V_84 = V_84 ;
if ( V_102 [ V_286 ] ) {
V_281 -> V_61 = F_53 ( V_102 [ V_286 ] ) ;
if ( ! F_87 ( V_281 -> V_61 ) ) {
V_89 = - V_90 ;
goto V_273;
}
}
V_89 = F_76 ( V_150 , V_25 , V_281 , & V_2 , V_267 , V_102 , V_278 [ V_287 ] , V_269 ) ;
if ( V_89 )
goto V_273;
V_89 = F_75 ( V_19 , & V_2 ) ;
if ( V_89 )
goto V_273;
if ( ! F_17 ( V_281 -> V_61 ) ) {
if ( ! V_280 && F_8 ( V_19 , & V_281 -> V_13 ) ) {
V_89 = - V_288 ;
goto V_273;
}
V_89 = F_88 ( & V_19 -> V_20 , & V_281 -> V_289 ,
V_19 -> V_21 ) ;
if ( V_89 )
goto V_273;
}
if ( ! F_34 ( V_281 -> V_61 ) ) {
V_89 = F_29 ( V_25 ,
& V_19 -> V_60 ,
& V_2 . V_7 ,
V_281 ) ;
if ( V_89 )
goto V_273;
}
if ( ! F_89 ( V_281 -> V_61 ) )
V_281 -> V_61 |= V_290 ;
if ( V_280 ) {
if ( ! F_17 ( V_280 -> V_61 ) )
F_90 ( & V_19 -> V_20 , & V_280 -> V_289 ,
V_19 -> V_21 ) ;
if ( ! F_34 ( V_280 -> V_61 ) )
F_27 ( V_25 , V_280 ) ;
}
* V_279 = ( unsigned long ) V_281 ;
if ( V_280 ) {
F_91 ( & V_280 -> V_95 , & V_281 -> V_95 ) ;
F_35 ( V_25 , & V_280 -> V_27 ) ;
F_36 ( & V_280 -> V_67 , F_23 ) ;
} else {
F_92 ( & V_281 -> V_95 , & V_19 -> V_65 ) ;
}
F_26 ( V_102 ) ;
return 0 ;
V_273:
F_25 ( & V_281 -> V_62 ) ;
F_26 ( V_281 ) ;
V_285:
F_26 ( V_102 ) ;
return V_89 ;
}
static int F_93 ( struct V_24 * V_25 , unsigned long V_279 , bool * V_11 )
{
struct V_18 * V_19 = F_44 ( V_25 -> V_28 ) ;
struct V_17 * V_29 = (struct V_17 * ) V_279 ;
if ( ! F_17 ( V_29 -> V_61 ) )
F_90 ( & V_19 -> V_20 , & V_29 -> V_289 ,
V_19 -> V_21 ) ;
F_32 ( V_25 , V_29 ) ;
* V_11 = F_94 ( & V_19 -> V_65 ) ;
return 0 ;
}
static void F_95 ( struct V_24 * V_25 , struct V_291 * V_279 )
{
struct V_18 * V_19 = F_44 ( V_25 -> V_28 ) ;
struct V_17 * V_29 ;
F_96 (f, &head->filters, list) {
if ( V_279 -> V_292 < V_279 -> V_293 )
goto V_293;
if ( V_279 -> V_294 ( V_25 , ( unsigned long ) V_29 , V_279 ) < 0 ) {
V_279 -> V_295 = 1 ;
break;
}
V_293:
V_279 -> V_292 ++ ;
}
}
static int F_97 ( struct V_22 * V_23 ,
void * V_103 , int V_104 ,
void * V_2 , int V_105 , int V_106 )
{
int V_89 ;
if ( ! F_98 ( V_2 , 0 , V_106 ) )
return 0 ;
V_89 = F_99 ( V_23 , V_104 , V_106 , V_103 ) ;
if ( V_89 )
return V_89 ;
if ( V_105 != V_107 ) {
V_89 = F_99 ( V_23 , V_105 , V_106 , V_2 ) ;
if ( V_89 )
return V_89 ;
}
return 0 ;
}
static int F_100 ( struct V_22 * V_23 ,
struct V_108 * V_296 ,
struct V_108 * V_297 )
{
int V_89 ;
if ( ! F_98 ( V_297 , 0 , sizeof( * V_297 ) ) )
return 0 ;
if ( V_297 -> V_112 ) {
V_89 = F_101 ( V_23 , V_111 ,
V_296 -> V_112 ) ;
if ( V_89 )
return V_89 ;
}
if ( V_297 -> V_120 ) {
V_89 = F_101 ( V_23 , V_118 ,
V_296 -> V_120 ) ;
if ( V_89 )
return V_89 ;
}
if ( V_297 -> V_124 ) {
V_89 = F_102 ( V_23 , V_121 ,
V_296 -> V_124 ) ;
if ( V_89 )
return V_89 ;
}
if ( V_297 -> V_117 ) {
V_89 = F_101 ( V_23 , V_114 ,
V_296 -> V_117 ) ;
if ( V_89 )
return V_89 ;
}
return 0 ;
}
static int F_103 ( struct V_22 * V_23 ,
struct V_143 * V_7 ,
struct V_143 * V_2 )
{
if ( F_97 ( V_23 , & V_7 -> V_144 , V_145 , & V_2 -> V_144 ,
V_146 , sizeof( V_7 -> V_144 ) ) ||
F_97 ( V_23 , & V_7 -> V_147 , V_148 , & V_2 -> V_147 ,
V_149 , sizeof( V_7 -> V_147 ) ) )
return - 1 ;
return 0 ;
}
static int F_104 ( struct V_22 * V_23 ,
struct V_125 * V_298 ,
struct V_125 * V_299 )
{
int V_89 ;
if ( ! F_98 ( V_299 , 0 , sizeof( * V_299 ) ) )
return 0 ;
if ( V_299 -> V_127 ) {
V_89 = F_105 ( V_23 , V_126 ,
V_298 -> V_127 ) ;
if ( V_89 )
return V_89 ;
}
if ( V_299 -> V_130 ) {
V_89 = F_101 ( V_23 , V_129 ,
V_298 -> V_130 ) ;
if ( V_89 )
return V_89 ;
}
return 0 ;
}
static void F_106 ( T_3 V_133 , T_3 V_134 ,
T_3 * V_131 , T_3 * V_132 ,
T_3 V_135 , T_3 V_136 )
{
if ( V_134 & V_136 ) {
* V_132 |= V_135 ;
if ( V_133 & V_136 )
* V_131 |= V_135 ;
}
}
static int F_107 ( struct V_22 * V_23 , T_3 V_137 , T_3 V_138 )
{
T_3 V_7 , V_2 ;
T_5 V_300 , V_301 ;
int V_89 ;
if ( ! F_98 ( & V_138 , 0 , sizeof( V_138 ) ) )
return 0 ;
V_7 = 0 ;
V_2 = 0 ;
F_106 ( V_137 , V_138 , & V_7 , & V_2 ,
V_141 , V_142 ) ;
V_300 = F_108 ( V_7 ) ;
V_301 = F_108 ( V_2 ) ;
V_89 = F_99 ( V_23 , V_140 , 4 , & V_300 ) ;
if ( V_89 )
return V_89 ;
return F_99 ( V_23 , V_139 , 4 , & V_301 ) ;
}
static int F_109 ( struct V_150 * V_150 , struct V_24 * V_25 , unsigned long V_302 ,
struct V_22 * V_23 , struct V_303 * V_304 )
{
struct V_18 * V_19 = F_44 ( V_25 -> V_28 ) ;
struct V_17 * V_29 = (struct V_17 * ) V_302 ;
struct V_101 * V_305 ;
struct V_12 * V_7 , * V_2 ;
if ( ! V_29 )
return V_23 -> V_106 ;
V_304 -> V_306 = V_29 -> V_84 ;
V_305 = F_110 ( V_23 , V_282 ) ;
if ( ! V_305 )
goto V_307;
if ( V_29 -> V_27 . V_275 &&
F_102 ( V_23 , V_274 , V_29 -> V_27 . V_275 ) )
goto V_307;
V_7 = & V_29 -> V_7 ;
V_2 = & V_19 -> V_2 . V_7 ;
if ( V_2 -> V_55 ) {
struct V_70 * V_71 ;
V_71 = F_111 ( V_150 , V_7 -> V_55 ) ;
if ( V_71 && F_112 ( V_23 , V_153 , V_71 -> V_308 ) )
goto V_307;
}
if ( ! F_34 ( V_29 -> V_61 ) )
F_31 ( V_25 , V_29 ) ;
if ( F_97 ( V_23 , V_7 -> V_154 . V_44 , V_155 ,
V_2 -> V_154 . V_44 , V_156 ,
sizeof( V_7 -> V_154 . V_44 ) ) ||
F_97 ( V_23 , V_7 -> V_154 . V_41 , V_157 ,
V_2 -> V_154 . V_41 , V_158 ,
sizeof( V_7 -> V_154 . V_41 ) ) ||
F_97 ( V_23 , & V_7 -> V_57 . V_58 , V_159 ,
& V_2 -> V_57 . V_58 , V_107 ,
sizeof( V_7 -> V_57 . V_58 ) ) )
goto V_307;
if ( F_100 ( V_23 , & V_7 -> V_209 , & V_2 -> V_209 ) )
goto V_307;
if ( F_104 ( V_23 , & V_7 -> V_161 , & V_2 -> V_161 ) )
goto V_307;
if ( ( V_7 -> V_57 . V_58 == F_65 ( V_163 ) ||
V_7 -> V_57 . V_58 == F_65 ( V_164 ) ) &&
( F_97 ( V_23 , & V_7 -> V_57 . V_165 , V_166 ,
& V_2 -> V_57 . V_165 , V_107 ,
sizeof( V_7 -> V_57 . V_165 ) ) ||
F_103 ( V_23 , & V_7 -> V_167 , & V_2 -> V_167 ) ) )
goto V_307;
if ( V_7 -> V_170 . V_38 == V_39 &&
( F_97 ( V_23 , & V_7 -> V_43 . V_41 , V_168 ,
& V_2 -> V_43 . V_41 , V_171 ,
sizeof( V_7 -> V_43 . V_41 ) ) ||
F_97 ( V_23 , & V_7 -> V_43 . V_44 , V_169 ,
& V_2 -> V_43 . V_44 , V_172 ,
sizeof( V_7 -> V_43 . V_44 ) ) ) )
goto V_307;
else if ( V_7 -> V_170 . V_38 == V_46 &&
( F_97 ( V_23 , & V_7 -> V_48 . V_41 , V_173 ,
& V_2 -> V_48 . V_41 , V_175 ,
sizeof( V_7 -> V_48 . V_41 ) ) ||
F_97 ( V_23 , & V_7 -> V_48 . V_44 , V_174 ,
& V_2 -> V_48 . V_44 , V_176 ,
sizeof( V_7 -> V_48 . V_44 ) ) ) )
goto V_307;
if ( V_7 -> V_57 . V_165 == V_177 &&
( F_97 ( V_23 , & V_7 -> V_25 . V_41 , V_178 ,
& V_2 -> V_25 . V_41 , V_179 ,
sizeof( V_7 -> V_25 . V_41 ) ) ||
F_97 ( V_23 , & V_7 -> V_25 . V_44 , V_180 ,
& V_2 -> V_25 . V_44 , V_181 ,
sizeof( V_7 -> V_25 . V_44 ) ) ||
F_97 ( V_23 , & V_7 -> V_182 . V_61 , V_183 ,
& V_2 -> V_182 . V_61 , V_184 ,
sizeof( V_7 -> V_182 . V_61 ) ) ) )
goto V_307;
else if ( V_7 -> V_57 . V_165 == V_185 &&
( F_97 ( V_23 , & V_7 -> V_25 . V_41 , V_186 ,
& V_2 -> V_25 . V_41 , V_187 ,
sizeof( V_7 -> V_25 . V_41 ) ) ||
F_97 ( V_23 , & V_7 -> V_25 . V_44 , V_188 ,
& V_2 -> V_25 . V_44 , V_189 ,
sizeof( V_7 -> V_25 . V_44 ) ) ) )
goto V_307;
else if ( V_7 -> V_57 . V_165 == V_190 &&
( F_97 ( V_23 , & V_7 -> V_25 . V_41 , V_191 ,
& V_2 -> V_25 . V_41 , V_192 ,
sizeof( V_7 -> V_25 . V_41 ) ) ||
F_97 ( V_23 , & V_7 -> V_25 . V_44 , V_193 ,
& V_2 -> V_25 . V_44 , V_194 ,
sizeof( V_7 -> V_25 . V_44 ) ) ) )
goto V_307;
else if ( V_7 -> V_57 . V_58 == F_65 ( V_163 ) &&
V_7 -> V_57 . V_165 == V_195 &&
( F_97 ( V_23 , & V_7 -> V_196 . type ,
V_197 , & V_2 -> V_196 . type ,
V_198 ,
sizeof( V_7 -> V_196 . type ) ) ||
F_97 ( V_23 , & V_7 -> V_196 . V_199 ,
V_200 , & V_2 -> V_196 . V_199 ,
V_201 ,
sizeof( V_7 -> V_196 . V_199 ) ) ) )
goto V_307;
else if ( V_7 -> V_57 . V_58 == F_65 ( V_164 ) &&
V_7 -> V_57 . V_165 == V_202 &&
( F_97 ( V_23 , & V_7 -> V_196 . type ,
V_203 , & V_2 -> V_196 . type ,
V_204 ,
sizeof( V_7 -> V_196 . type ) ) ||
F_97 ( V_23 , & V_7 -> V_196 . V_199 ,
V_205 , & V_2 -> V_196 . V_199 ,
V_206 ,
sizeof( V_7 -> V_196 . V_199 ) ) ) )
goto V_307;
else if ( ( V_7 -> V_57 . V_58 == F_65 ( V_210 ) ||
V_7 -> V_57 . V_58 == F_65 ( V_211 ) ) &&
( F_97 ( V_23 , & V_7 -> V_212 . V_213 ,
V_214 , & V_2 -> V_212 . V_213 ,
V_215 ,
sizeof( V_7 -> V_212 . V_213 ) ) ||
F_97 ( V_23 , & V_7 -> V_212 . V_216 ,
V_217 , & V_2 -> V_212 . V_216 ,
V_218 ,
sizeof( V_7 -> V_212 . V_216 ) ) ||
F_97 ( V_23 , & V_7 -> V_212 . V_219 ,
V_220 , & V_2 -> V_212 . V_219 ,
V_221 ,
sizeof( V_7 -> V_212 . V_219 ) ) ||
F_97 ( V_23 , V_7 -> V_212 . V_222 , V_223 ,
V_2 -> V_212 . V_222 , V_224 ,
sizeof( V_7 -> V_212 . V_222 ) ) ||
F_97 ( V_23 , V_7 -> V_212 . V_225 , V_226 ,
V_2 -> V_212 . V_225 , V_227 ,
sizeof( V_7 -> V_212 . V_225 ) ) ) )
goto V_307;
if ( V_7 -> V_37 . V_38 == V_39 &&
( F_97 ( V_23 , & V_7 -> V_40 . V_41 ,
V_228 , & V_2 -> V_40 . V_41 ,
V_230 ,
sizeof( V_7 -> V_40 . V_41 ) ) ||
F_97 ( V_23 , & V_7 -> V_40 . V_44 ,
V_229 , & V_2 -> V_40 . V_44 ,
V_231 ,
sizeof( V_7 -> V_40 . V_44 ) ) ) )
goto V_307;
else if ( V_7 -> V_37 . V_38 == V_46 &&
( F_97 ( V_23 , & V_7 -> V_47 . V_41 ,
V_232 , & V_2 -> V_47 . V_41 ,
V_234 ,
sizeof( V_7 -> V_47 . V_41 ) ) ||
F_97 ( V_23 , & V_7 -> V_47 . V_44 ,
V_233 ,
& V_2 -> V_47 . V_44 ,
V_235 ,
sizeof( V_7 -> V_47 . V_44 ) ) ) )
goto V_307;
if ( F_97 ( V_23 , & V_7 -> V_49 , V_236 ,
& V_2 -> V_49 , V_107 ,
sizeof( V_7 -> V_49 ) ) ||
F_97 ( V_23 , & V_7 -> V_52 . V_41 ,
V_237 ,
& V_2 -> V_52 . V_41 ,
V_238 ,
sizeof( V_7 -> V_52 . V_41 ) ) ||
F_97 ( V_23 , & V_7 -> V_52 . V_44 ,
V_239 ,
& V_2 -> V_52 . V_44 ,
V_240 ,
sizeof( V_7 -> V_52 . V_44 ) ) )
goto V_307;
if ( F_107 ( V_23 , V_7 -> V_170 . V_61 , V_2 -> V_170 . V_61 ) )
goto V_307;
if ( V_29 -> V_61 && F_102 ( V_23 , V_286 , V_29 -> V_61 ) )
goto V_307;
if ( F_113 ( V_23 , & V_29 -> V_62 ) )
goto V_307;
F_114 ( V_23 , V_305 ) ;
if ( F_115 ( V_23 , & V_29 -> V_62 ) < 0 )
goto V_307;
return V_23 -> V_106 ;
V_307:
F_116 ( V_23 , V_305 ) ;
return - 1 ;
}
static int T_6 F_117 ( void )
{
return F_118 ( & V_309 ) ;
}
static void T_7 F_119 ( void )
{
F_120 ( & V_309 ) ;
}
