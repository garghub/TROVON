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
F_23 ( & V_19 -> V_66 ) ;
return 0 ;
}
static void F_24 ( struct V_17 * V_29 )
{
F_25 ( & V_29 -> V_62 ) ;
F_26 ( & V_29 -> V_62 ) ;
F_27 ( V_29 ) ;
}
static void F_28 ( struct V_67 * V_68 )
{
struct V_17 * V_29 = F_29 ( V_68 , struct V_17 , V_68 ) ;
F_30 () ;
F_24 ( V_29 ) ;
F_31 () ;
}
static void F_32 ( struct V_69 * V_19 )
{
struct V_17 * V_29 = F_29 ( V_19 , struct V_17 , V_70 ) ;
F_33 ( & V_29 -> V_68 , F_28 ) ;
F_34 ( & V_29 -> V_68 ) ;
}
static void F_35 ( struct V_24 * V_25 , struct V_17 * V_29 )
{
struct V_71 V_72 = {} ;
struct V_73 * V_74 = V_29 -> V_75 ;
if ( ! F_36 ( V_74 ) )
return;
F_37 ( & V_72 . V_76 , V_25 ) ;
V_72 . V_77 = V_78 ;
V_72 . V_79 = ( unsigned long ) V_29 ;
V_72 . V_80 = V_29 -> V_75 != V_25 -> V_81 -> V_82 -> V_74 ;
V_74 -> V_83 -> V_84 ( V_74 , V_85 , & V_72 ) ;
}
static int F_38 ( struct V_24 * V_25 ,
struct V_86 * V_60 ,
struct V_12 * V_2 ,
struct V_17 * V_29 )
{
struct V_73 * V_74 = V_25 -> V_81 -> V_82 -> V_74 ;
struct V_71 V_72 = {} ;
int V_87 ;
if ( ! F_36 ( V_74 ) ) {
if ( F_39 ( V_74 , & V_29 -> V_62 , & V_29 -> V_75 ) ||
( V_29 -> V_75 && ! F_36 ( V_29 -> V_75 ) ) ) {
V_29 -> V_75 = V_74 ;
return F_17 ( V_29 -> V_61 ) ? - V_88 : 0 ;
}
V_74 = V_29 -> V_75 ;
V_72 . V_80 = true ;
} else {
V_29 -> V_75 = V_74 ;
}
F_37 ( & V_72 . V_76 , V_25 ) ;
V_72 . V_77 = V_89 ;
V_72 . V_79 = ( unsigned long ) V_29 ;
V_72 . V_60 = V_60 ;
V_72 . V_2 = V_2 ;
V_72 . V_7 = & V_29 -> V_13 ;
V_72 . V_62 = & V_29 -> V_62 ;
V_87 = V_74 -> V_83 -> V_84 ( V_74 , V_85 ,
& V_72 ) ;
if ( ! V_87 )
V_29 -> V_61 |= V_90 ;
if ( F_17 ( V_29 -> V_61 ) )
return V_87 ;
return 0 ;
}
static void F_40 ( struct V_24 * V_25 , struct V_17 * V_29 )
{
struct V_71 V_72 = {} ;
struct V_73 * V_74 = V_29 -> V_75 ;
if ( ! F_36 ( V_74 ) )
return;
F_37 ( & V_72 . V_76 , V_25 ) ;
V_72 . V_77 = V_91 ;
V_72 . V_79 = ( unsigned long ) V_29 ;
V_72 . V_62 = & V_29 -> V_62 ;
V_72 . V_80 = V_29 -> V_75 != V_25 -> V_81 -> V_82 -> V_74 ;
V_74 -> V_83 -> V_84 ( V_74 , V_85 ,
& V_72 ) ;
}
static void F_41 ( struct V_24 * V_25 , struct V_17 * V_29 )
{
struct V_18 * V_19 = F_42 ( V_25 -> V_28 ) ;
F_43 ( & V_19 -> V_66 , V_29 -> V_92 ) ;
F_44 ( & V_29 -> V_93 ) ;
if ( ! F_45 ( V_29 -> V_61 ) )
F_35 ( V_25 , V_29 ) ;
F_46 ( V_25 , & V_29 -> V_27 ) ;
if ( F_47 ( & V_29 -> V_62 ) )
F_48 ( & V_29 -> V_70 , F_32 ) ;
else
F_24 ( V_29 ) ;
}
static void F_49 ( struct V_67 * V_68 )
{
struct V_18 * V_19 = F_29 ( V_68 , struct V_18 ,
V_68 ) ;
if ( V_19 -> V_94 )
F_50 ( & V_19 -> V_20 ) ;
F_27 ( V_19 ) ;
F_51 ( V_95 ) ;
}
static void F_52 ( struct V_69 * V_70 )
{
struct V_18 * V_19 = F_29 ( V_70 , struct V_18 , V_70 ) ;
F_33 ( & V_19 -> V_68 , F_49 ) ;
F_53 ( & V_19 -> V_68 ) ;
}
static void F_54 ( struct V_24 * V_25 )
{
struct V_18 * V_19 = F_42 ( V_25 -> V_28 ) ;
struct V_17 * V_29 , * V_96 ;
F_55 (f, next, &head->filters, list)
F_41 ( V_25 , V_29 ) ;
F_56 ( & V_19 -> V_66 ) ;
F_57 ( V_95 ) ;
F_48 ( & V_19 -> V_70 , F_52 ) ;
}
static void * F_58 ( struct V_24 * V_25 , T_3 V_92 )
{
struct V_18 * V_19 = F_42 ( V_25 -> V_28 ) ;
return F_59 ( & V_19 -> V_66 , V_92 ) ;
}
static void F_60 ( struct V_97 * * V_98 ,
void * V_99 , int V_100 ,
void * V_2 , int V_101 , int V_102 )
{
if ( ! V_98 [ V_100 ] )
return;
memcpy ( V_99 , F_61 ( V_98 [ V_100 ] ) , V_102 ) ;
if ( V_101 == V_103 || ! V_98 [ V_101 ] )
memset ( V_2 , 0xff , V_102 ) ;
else
memcpy ( V_2 , F_61 ( V_98 [ V_101 ] ) , V_102 ) ;
}
static int F_62 ( struct V_97 * * V_98 ,
struct V_104 * V_105 ,
struct V_104 * V_106 )
{
if ( V_98 [ V_107 ] ) {
V_105 -> V_108 = F_63 ( V_98 [ V_107 ] ) ;
V_106 -> V_108 = V_109 ;
}
if ( V_98 [ V_110 ] ) {
T_1 V_111 = F_63 ( V_98 [ V_110 ] ) ;
if ( V_111 & ~ V_112 )
return - V_88 ;
V_105 -> V_113 = V_111 ;
V_106 -> V_113 = V_112 ;
}
if ( V_98 [ V_114 ] ) {
T_1 V_115 = F_63 ( V_98 [ V_114 ] ) ;
if ( V_115 & ~ V_116 )
return - V_88 ;
V_105 -> V_117 = V_115 ;
V_106 -> V_117 = V_116 ;
}
if ( V_98 [ V_118 ] ) {
T_3 V_119 = F_64 ( V_98 [ V_118 ] ) ;
if ( V_119 & ~ V_120 )
return - V_88 ;
V_105 -> V_121 = V_119 ;
V_106 -> V_121 = V_120 ;
}
return 0 ;
}
static void F_65 ( struct V_97 * * V_98 ,
struct V_122 * V_105 ,
struct V_122 * V_106 )
{
#define F_66 0x7
if ( V_98 [ V_123 ] ) {
V_105 -> V_124 =
F_67 ( V_98 [ V_123 ] ) & V_125 ;
V_106 -> V_124 = V_125 ;
}
if ( V_98 [ V_126 ] ) {
V_105 -> V_127 =
F_63 ( V_98 [ V_126 ] ) &
F_66 ;
V_106 -> V_127 = F_66 ;
}
}
static void F_68 ( T_3 V_128 , T_3 V_129 ,
T_3 * V_130 , T_3 * V_131 ,
T_3 V_132 , T_3 V_133 )
{
if ( V_129 & V_132 ) {
* V_131 |= V_133 ;
if ( V_128 & V_132 )
* V_130 |= V_133 ;
}
}
static int F_69 ( struct V_97 * * V_98 ,
T_3 * V_134 , T_3 * V_135 )
{
T_3 V_7 , V_2 ;
if ( ! V_98 [ V_136 ] )
return - V_88 ;
V_7 = F_70 ( F_64 ( V_98 [ V_137 ] ) ) ;
V_2 = F_70 ( F_64 ( V_98 [ V_136 ] ) ) ;
* V_134 = 0 ;
* V_135 = 0 ;
F_68 ( V_7 , V_2 , V_134 , V_135 ,
V_138 , V_139 ) ;
return 0 ;
}
static void F_71 ( struct V_97 * * V_98 ,
struct V_140 * V_7 ,
struct V_140 * V_2 )
{
F_60 ( V_98 , & V_7 -> V_141 , V_142 ,
& V_2 -> V_141 , V_143 ,
sizeof( V_7 -> V_141 ) ) ;
F_60 ( V_98 , & V_7 -> V_144 , V_145 ,
& V_2 -> V_144 , V_146 ,
sizeof( V_7 -> V_144 ) ) ;
}
static int F_72 ( struct V_147 * V_147 , struct V_97 * * V_98 ,
struct V_12 * V_7 , struct V_12 * V_2 )
{
T_4 V_148 ;
int V_149 = 0 ;
#ifdef F_73
if ( V_98 [ V_150 ] ) {
int V_87 = F_74 ( V_147 , V_98 [ V_150 ] ) ;
if ( V_87 < 0 )
return V_87 ;
V_7 -> V_55 = V_87 ;
V_2 -> V_55 = 0xffffffff ;
}
#endif
F_60 ( V_98 , V_7 -> V_151 . V_44 , V_152 ,
V_2 -> V_151 . V_44 , V_153 ,
sizeof( V_7 -> V_151 . V_44 ) ) ;
F_60 ( V_98 , V_7 -> V_151 . V_41 , V_154 ,
V_2 -> V_151 . V_41 , V_155 ,
sizeof( V_7 -> V_151 . V_41 ) ) ;
if ( V_98 [ V_156 ] ) {
V_148 = F_75 ( V_98 [ V_156 ] ) ;
if ( V_148 == F_76 ( V_157 ) ) {
F_65 ( V_98 , & V_7 -> V_158 , & V_2 -> V_158 ) ;
F_60 ( V_98 , & V_7 -> V_57 . V_58 ,
V_159 ,
& V_2 -> V_57 . V_58 , V_103 ,
sizeof( V_7 -> V_57 . V_58 ) ) ;
} else {
V_7 -> V_57 . V_58 = V_148 ;
V_2 -> V_57 . V_58 = F_77 ( ~ 0 ) ;
}
}
if ( V_7 -> V_57 . V_58 == F_76 ( V_160 ) ||
V_7 -> V_57 . V_58 == F_76 ( V_161 ) ) {
F_60 ( V_98 , & V_7 -> V_57 . V_162 , V_163 ,
& V_2 -> V_57 . V_162 , V_103 ,
sizeof( V_7 -> V_57 . V_162 ) ) ;
F_71 ( V_98 , & V_7 -> V_164 , & V_2 -> V_164 ) ;
}
if ( V_98 [ V_165 ] || V_98 [ V_166 ] ) {
V_7 -> V_167 . V_38 = V_39 ;
V_2 -> V_167 . V_38 = ~ 0 ;
F_60 ( V_98 , & V_7 -> V_43 . V_41 , V_165 ,
& V_2 -> V_43 . V_41 , V_168 ,
sizeof( V_7 -> V_43 . V_41 ) ) ;
F_60 ( V_98 , & V_7 -> V_43 . V_44 , V_166 ,
& V_2 -> V_43 . V_44 , V_169 ,
sizeof( V_7 -> V_43 . V_44 ) ) ;
} else if ( V_98 [ V_170 ] || V_98 [ V_171 ] ) {
V_7 -> V_167 . V_38 = V_46 ;
V_2 -> V_167 . V_38 = ~ 0 ;
F_60 ( V_98 , & V_7 -> V_48 . V_41 , V_170 ,
& V_2 -> V_48 . V_41 , V_172 ,
sizeof( V_7 -> V_48 . V_41 ) ) ;
F_60 ( V_98 , & V_7 -> V_48 . V_44 , V_171 ,
& V_2 -> V_48 . V_44 , V_173 ,
sizeof( V_7 -> V_48 . V_44 ) ) ;
}
if ( V_7 -> V_57 . V_162 == V_174 ) {
F_60 ( V_98 , & V_7 -> V_25 . V_41 , V_175 ,
& V_2 -> V_25 . V_41 , V_176 ,
sizeof( V_7 -> V_25 . V_41 ) ) ;
F_60 ( V_98 , & V_7 -> V_25 . V_44 , V_177 ,
& V_2 -> V_25 . V_44 , V_178 ,
sizeof( V_7 -> V_25 . V_44 ) ) ;
F_60 ( V_98 , & V_7 -> V_179 . V_61 , V_180 ,
& V_2 -> V_179 . V_61 , V_181 ,
sizeof( V_7 -> V_179 . V_61 ) ) ;
} else if ( V_7 -> V_57 . V_162 == V_182 ) {
F_60 ( V_98 , & V_7 -> V_25 . V_41 , V_183 ,
& V_2 -> V_25 . V_41 , V_184 ,
sizeof( V_7 -> V_25 . V_41 ) ) ;
F_60 ( V_98 , & V_7 -> V_25 . V_44 , V_185 ,
& V_2 -> V_25 . V_44 , V_186 ,
sizeof( V_7 -> V_25 . V_44 ) ) ;
} else if ( V_7 -> V_57 . V_162 == V_187 ) {
F_60 ( V_98 , & V_7 -> V_25 . V_41 , V_188 ,
& V_2 -> V_25 . V_41 , V_189 ,
sizeof( V_7 -> V_25 . V_41 ) ) ;
F_60 ( V_98 , & V_7 -> V_25 . V_44 , V_190 ,
& V_2 -> V_25 . V_44 , V_191 ,
sizeof( V_7 -> V_25 . V_44 ) ) ;
} else if ( V_7 -> V_57 . V_58 == F_76 ( V_160 ) &&
V_7 -> V_57 . V_162 == V_192 ) {
F_60 ( V_98 , & V_7 -> V_193 . type , V_194 ,
& V_2 -> V_193 . type ,
V_195 ,
sizeof( V_7 -> V_193 . type ) ) ;
F_60 ( V_98 , & V_7 -> V_193 . V_196 , V_197 ,
& V_2 -> V_193 . V_196 ,
V_198 ,
sizeof( V_7 -> V_193 . V_196 ) ) ;
} else if ( V_7 -> V_57 . V_58 == F_76 ( V_161 ) &&
V_7 -> V_57 . V_162 == V_199 ) {
F_60 ( V_98 , & V_7 -> V_193 . type , V_200 ,
& V_2 -> V_193 . type ,
V_201 ,
sizeof( V_7 -> V_193 . type ) ) ;
F_60 ( V_98 , & V_7 -> V_193 . V_196 , V_202 ,
& V_2 -> V_193 . V_196 ,
V_203 ,
sizeof( V_7 -> V_193 . V_196 ) ) ;
} else if ( V_7 -> V_57 . V_58 == F_76 ( V_204 ) ||
V_7 -> V_57 . V_58 == F_76 ( V_205 ) ) {
V_149 = F_62 ( V_98 , & V_7 -> V_206 , & V_2 -> V_206 ) ;
if ( V_149 )
return V_149 ;
} else if ( V_7 -> V_57 . V_58 == F_76 ( V_207 ) ||
V_7 -> V_57 . V_58 == F_76 ( V_208 ) ) {
F_60 ( V_98 , & V_7 -> V_209 . V_210 , V_211 ,
& V_2 -> V_209 . V_210 , V_212 ,
sizeof( V_7 -> V_209 . V_210 ) ) ;
F_60 ( V_98 , & V_7 -> V_209 . V_213 , V_214 ,
& V_2 -> V_209 . V_213 , V_215 ,
sizeof( V_7 -> V_209 . V_213 ) ) ;
F_60 ( V_98 , & V_7 -> V_209 . V_216 , V_217 ,
& V_2 -> V_209 . V_216 , V_218 ,
sizeof( V_7 -> V_209 . V_216 ) ) ;
F_60 ( V_98 , V_7 -> V_209 . V_219 , V_220 ,
V_2 -> V_209 . V_219 , V_221 ,
sizeof( V_7 -> V_209 . V_219 ) ) ;
F_60 ( V_98 , V_7 -> V_209 . V_222 , V_223 ,
V_2 -> V_209 . V_222 , V_224 ,
sizeof( V_7 -> V_209 . V_222 ) ) ;
}
if ( V_98 [ V_225 ] ||
V_98 [ V_226 ] ) {
V_7 -> V_37 . V_38 = V_39 ;
V_2 -> V_37 . V_38 = ~ 0 ;
F_60 ( V_98 , & V_7 -> V_40 . V_41 ,
V_225 ,
& V_2 -> V_40 . V_41 ,
V_227 ,
sizeof( V_7 -> V_40 . V_41 ) ) ;
F_60 ( V_98 , & V_7 -> V_40 . V_44 ,
V_226 ,
& V_2 -> V_40 . V_44 ,
V_228 ,
sizeof( V_7 -> V_40 . V_44 ) ) ;
}
if ( V_98 [ V_229 ] ||
V_98 [ V_230 ] ) {
V_7 -> V_37 . V_38 = V_46 ;
V_2 -> V_37 . V_38 = ~ 0 ;
F_60 ( V_98 , & V_7 -> V_47 . V_41 ,
V_229 ,
& V_2 -> V_47 . V_41 ,
V_231 ,
sizeof( V_7 -> V_47 . V_41 ) ) ;
F_60 ( V_98 , & V_7 -> V_47 . V_44 ,
V_230 ,
& V_2 -> V_47 . V_44 ,
V_232 ,
sizeof( V_7 -> V_47 . V_44 ) ) ;
}
F_60 ( V_98 , & V_7 -> V_49 . V_50 , V_233 ,
& V_2 -> V_49 . V_50 , V_103 ,
sizeof( V_7 -> V_49 . V_50 ) ) ;
F_60 ( V_98 , & V_7 -> V_52 . V_41 , V_234 ,
& V_2 -> V_52 . V_41 , V_235 ,
sizeof( V_7 -> V_52 . V_41 ) ) ;
F_60 ( V_98 , & V_7 -> V_52 . V_44 , V_236 ,
& V_2 -> V_52 . V_44 , V_237 ,
sizeof( V_7 -> V_52 . V_44 ) ) ;
if ( V_98 [ V_137 ] )
V_149 = F_69 ( V_98 , & V_7 -> V_167 . V_61 , & V_2 -> V_167 . V_61 ) ;
return V_149 ;
}
static bool F_78 ( struct V_1 * V_238 ,
struct V_1 * V_239 )
{
const long * V_240 = F_5 ( & V_238 -> V_7 , V_238 ) ;
const long * V_241 = F_5 ( & V_239 -> V_7 , V_239 ) ;
return ! memcmp ( & V_238 -> V_3 , & V_239 -> V_3 , sizeof( V_238 -> V_3 ) ) &&
! memcmp ( V_240 , V_241 , F_1 ( V_238 ) ) ;
}
static int F_79 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
V_19 -> V_21 = V_242 ;
V_19 -> V_21 . V_243 = F_1 ( V_2 ) ;
V_19 -> V_21 . V_244 += V_2 -> V_3 . V_5 ;
return F_80 ( & V_19 -> V_20 , & V_19 -> V_21 ) ;
}
static void F_81 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
struct V_245 V_246 [ V_247 ] ;
T_2 V_248 = 0 ;
F_82 ( V_246 , V_248 , V_249 , V_167 ) ;
F_82 ( V_246 , V_248 , V_250 , V_57 ) ;
F_83 ( & V_2 -> V_7 , V_246 , V_248 ,
V_251 , V_151 ) ;
F_83 ( & V_2 -> V_7 , V_246 , V_248 ,
V_39 , V_43 ) ;
F_83 ( & V_2 -> V_7 , V_246 , V_248 ,
V_46 , V_48 ) ;
F_83 ( & V_2 -> V_7 , V_246 , V_248 ,
V_252 , V_25 ) ;
F_83 ( & V_2 -> V_7 , V_246 , V_248 ,
V_253 , V_164 ) ;
F_83 ( & V_2 -> V_7 , V_246 , V_248 ,
V_254 , V_179 ) ;
F_83 ( & V_2 -> V_7 , V_246 , V_248 ,
V_255 , V_193 ) ;
F_83 ( & V_2 -> V_7 , V_246 , V_248 ,
V_256 , V_209 ) ;
F_83 ( & V_2 -> V_7 , V_246 , V_248 ,
V_257 , V_206 ) ;
F_83 ( & V_2 -> V_7 , V_246 , V_248 ,
V_258 , V_158 ) ;
F_83 ( & V_2 -> V_7 , V_246 , V_248 ,
V_259 , V_49 ) ;
F_83 ( & V_2 -> V_7 , V_246 , V_248 ,
V_260 , V_40 ) ;
F_83 ( & V_2 -> V_7 , V_246 , V_248 ,
V_261 , V_47 ) ;
if ( F_84 ( & V_2 -> V_7 , V_40 ) ||
F_84 ( & V_2 -> V_7 , V_47 ) )
F_82 ( V_246 , V_248 , V_262 ,
V_37 ) ;
F_83 ( & V_2 -> V_7 , V_246 , V_248 ,
V_263 , V_52 ) ;
F_85 ( & V_19 -> V_60 , V_246 , V_248 ) ;
}
static int F_86 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
int V_87 ;
if ( V_19 -> V_94 ) {
if ( ! F_78 ( & V_19 -> V_2 , V_2 ) )
return - V_88 ;
else
return 0 ;
}
V_87 = F_79 ( V_19 , V_2 ) ;
if ( V_87 )
return V_87 ;
memcpy ( & V_19 -> V_2 , V_2 , sizeof( V_19 -> V_2 ) ) ;
V_19 -> V_94 = true ;
F_81 ( V_19 , V_2 ) ;
return 0 ;
}
static int F_87 ( struct V_147 * V_147 , struct V_24 * V_25 ,
struct V_17 * V_29 , struct V_1 * V_2 ,
unsigned long V_264 , struct V_97 * * V_98 ,
struct V_97 * V_265 , bool V_266 )
{
int V_87 ;
V_87 = F_88 ( V_147 , V_25 , V_98 , V_265 , & V_29 -> V_62 , V_266 ) ;
if ( V_87 < 0 )
return V_87 ;
if ( V_98 [ V_267 ] ) {
V_29 -> V_27 . V_268 = F_64 ( V_98 [ V_267 ] ) ;
F_89 ( V_25 , & V_29 -> V_27 , V_264 ) ;
}
V_87 = F_72 ( V_147 , V_98 , & V_29 -> V_7 , & V_2 -> V_7 ) ;
if ( V_87 )
return V_87 ;
F_2 ( V_2 ) ;
F_6 ( & V_29 -> V_13 , & V_29 -> V_7 , V_2 ) ;
return 0 ;
}
static int F_90 ( struct V_147 * V_147 , struct V_22 * V_269 ,
struct V_24 * V_25 , unsigned long V_264 ,
T_3 V_92 , struct V_97 * * V_270 ,
void * * V_271 , bool V_266 )
{
struct V_18 * V_19 = F_42 ( V_25 -> V_28 ) ;
struct V_17 * V_272 = * V_271 ;
struct V_17 * V_273 ;
struct V_97 * * V_98 ;
struct V_1 V_2 = {} ;
unsigned long V_274 ;
int V_87 ;
if ( ! V_270 [ V_275 ] )
return - V_88 ;
V_98 = F_91 ( V_276 + 1 , sizeof( struct V_97 * ) , V_63 ) ;
if ( ! V_98 )
return - V_64 ;
V_87 = F_92 ( V_98 , V_276 , V_270 [ V_275 ] ,
V_277 , NULL ) ;
if ( V_87 < 0 )
goto V_278;
if ( V_272 && V_92 && V_272 -> V_92 != V_92 ) {
V_87 = - V_88 ;
goto V_278;
}
V_273 = F_20 ( sizeof( * V_273 ) , V_63 ) ;
if ( ! V_273 ) {
V_87 = - V_64 ;
goto V_278;
}
V_87 = F_93 ( & V_273 -> V_62 , V_279 , 0 ) ;
if ( V_87 < 0 )
goto V_280;
if ( ! V_92 ) {
V_87 = F_94 ( & V_19 -> V_66 , V_273 , & V_274 ,
1 , 0x80000000 , V_63 ) ;
if ( V_87 )
goto V_280;
V_273 -> V_92 = V_274 ;
}
if ( V_92 && ! V_272 ) {
V_87 = F_94 ( & V_19 -> V_66 , V_273 , & V_274 ,
V_92 , V_92 + 1 , V_63 ) ;
if ( V_87 )
goto V_280;
V_273 -> V_92 = V_274 ;
}
if ( V_98 [ V_281 ] ) {
V_273 -> V_61 = F_64 ( V_98 [ V_281 ] ) ;
if ( ! F_95 ( V_273 -> V_61 ) ) {
V_87 = - V_88 ;
goto V_282;
}
}
V_87 = F_87 ( V_147 , V_25 , V_273 , & V_2 , V_264 , V_98 , V_270 [ V_283 ] , V_266 ) ;
if ( V_87 )
goto V_282;
V_87 = F_86 ( V_19 , & V_2 ) ;
if ( V_87 )
goto V_282;
if ( ! F_17 ( V_273 -> V_61 ) ) {
if ( ! V_272 && F_8 ( V_19 , & V_273 -> V_13 ) ) {
V_87 = - V_284 ;
goto V_282;
}
V_87 = F_96 ( & V_19 -> V_20 , & V_273 -> V_285 ,
V_19 -> V_21 ) ;
if ( V_87 )
goto V_282;
}
if ( ! F_45 ( V_273 -> V_61 ) ) {
V_87 = F_38 ( V_25 ,
& V_19 -> V_60 ,
& V_2 . V_7 ,
V_273 ) ;
if ( V_87 )
goto V_282;
}
if ( ! F_97 ( V_273 -> V_61 ) )
V_273 -> V_61 |= V_286 ;
if ( V_272 ) {
if ( ! F_17 ( V_272 -> V_61 ) )
F_98 ( & V_19 -> V_20 , & V_272 -> V_285 ,
V_19 -> V_21 ) ;
if ( ! F_45 ( V_272 -> V_61 ) )
F_35 ( V_25 , V_272 ) ;
}
* V_271 = V_273 ;
if ( V_272 ) {
V_273 -> V_92 = V_92 ;
F_99 ( & V_19 -> V_66 , V_273 , V_273 -> V_92 ) ;
F_100 ( & V_272 -> V_93 , & V_273 -> V_93 ) ;
F_46 ( V_25 , & V_272 -> V_27 ) ;
F_47 ( & V_272 -> V_62 ) ;
F_48 ( & V_272 -> V_70 , F_32 ) ;
} else {
F_101 ( & V_273 -> V_93 , & V_19 -> V_65 ) ;
}
F_27 ( V_98 ) ;
return 0 ;
V_282:
if ( V_273 -> V_92 )
F_43 ( & V_19 -> V_66 , V_273 -> V_92 ) ;
V_280:
F_25 ( & V_273 -> V_62 ) ;
F_27 ( V_273 ) ;
V_278:
F_27 ( V_98 ) ;
return V_87 ;
}
static int F_102 ( struct V_24 * V_25 , void * V_271 , bool * V_11 )
{
struct V_18 * V_19 = F_42 ( V_25 -> V_28 ) ;
struct V_17 * V_29 = V_271 ;
if ( ! F_17 ( V_29 -> V_61 ) )
F_98 ( & V_19 -> V_20 , & V_29 -> V_285 ,
V_19 -> V_21 ) ;
F_41 ( V_25 , V_29 ) ;
* V_11 = F_103 ( & V_19 -> V_65 ) ;
return 0 ;
}
static void F_104 ( struct V_24 * V_25 , struct V_287 * V_271 )
{
struct V_18 * V_19 = F_42 ( V_25 -> V_28 ) ;
struct V_17 * V_29 ;
F_105 (f, &head->filters, list) {
if ( V_271 -> V_288 < V_271 -> V_289 )
goto V_289;
if ( V_271 -> V_290 ( V_25 , V_29 , V_271 ) < 0 ) {
V_271 -> V_291 = 1 ;
break;
}
V_289:
V_271 -> V_288 ++ ;
}
}
static int F_106 ( struct V_22 * V_23 ,
void * V_99 , int V_100 ,
void * V_2 , int V_101 , int V_102 )
{
int V_87 ;
if ( ! F_107 ( V_2 , 0 , V_102 ) )
return 0 ;
V_87 = F_108 ( V_23 , V_100 , V_102 , V_99 ) ;
if ( V_87 )
return V_87 ;
if ( V_101 != V_103 ) {
V_87 = F_108 ( V_23 , V_101 , V_102 , V_2 ) ;
if ( V_87 )
return V_87 ;
}
return 0 ;
}
static int F_109 ( struct V_22 * V_23 ,
struct V_104 * V_292 ,
struct V_104 * V_293 )
{
int V_87 ;
if ( ! F_107 ( V_293 , 0 , sizeof( * V_293 ) ) )
return 0 ;
if ( V_293 -> V_108 ) {
V_87 = F_110 ( V_23 , V_107 ,
V_292 -> V_108 ) ;
if ( V_87 )
return V_87 ;
}
if ( V_293 -> V_117 ) {
V_87 = F_110 ( V_23 , V_114 ,
V_292 -> V_117 ) ;
if ( V_87 )
return V_87 ;
}
if ( V_293 -> V_121 ) {
V_87 = F_111 ( V_23 , V_118 ,
V_292 -> V_121 ) ;
if ( V_87 )
return V_87 ;
}
if ( V_293 -> V_113 ) {
V_87 = F_110 ( V_23 , V_110 ,
V_292 -> V_113 ) ;
if ( V_87 )
return V_87 ;
}
return 0 ;
}
static int F_112 ( struct V_22 * V_23 ,
struct V_140 * V_7 ,
struct V_140 * V_2 )
{
if ( F_106 ( V_23 , & V_7 -> V_141 , V_142 , & V_2 -> V_141 ,
V_143 , sizeof( V_7 -> V_141 ) ) ||
F_106 ( V_23 , & V_7 -> V_144 , V_145 , & V_2 -> V_144 ,
V_146 , sizeof( V_7 -> V_144 ) ) )
return - 1 ;
return 0 ;
}
static int F_113 ( struct V_22 * V_23 ,
struct V_122 * V_294 ,
struct V_122 * V_295 )
{
int V_87 ;
if ( ! F_107 ( V_295 , 0 , sizeof( * V_295 ) ) )
return 0 ;
if ( V_295 -> V_124 ) {
V_87 = F_114 ( V_23 , V_123 ,
V_294 -> V_124 ) ;
if ( V_87 )
return V_87 ;
}
if ( V_295 -> V_127 ) {
V_87 = F_110 ( V_23 , V_126 ,
V_294 -> V_127 ) ;
if ( V_87 )
return V_87 ;
}
return 0 ;
}
static void F_115 ( T_3 V_130 , T_3 V_131 ,
T_3 * V_128 , T_3 * V_129 ,
T_3 V_132 , T_3 V_133 )
{
if ( V_131 & V_133 ) {
* V_129 |= V_132 ;
if ( V_130 & V_133 )
* V_128 |= V_132 ;
}
}
static int F_116 ( struct V_22 * V_23 , T_3 V_134 , T_3 V_135 )
{
T_3 V_7 , V_2 ;
T_5 V_296 , V_297 ;
int V_87 ;
if ( ! F_107 ( & V_135 , 0 , sizeof( V_135 ) ) )
return 0 ;
V_7 = 0 ;
V_2 = 0 ;
F_115 ( V_134 , V_135 , & V_7 , & V_2 ,
V_138 , V_139 ) ;
V_296 = F_117 ( V_7 ) ;
V_297 = F_117 ( V_2 ) ;
V_87 = F_108 ( V_23 , V_137 , 4 , & V_296 ) ;
if ( V_87 )
return V_87 ;
return F_108 ( V_23 , V_136 , 4 , & V_297 ) ;
}
static int F_118 ( struct V_147 * V_147 , struct V_24 * V_25 , void * V_298 ,
struct V_22 * V_23 , struct V_299 * V_300 )
{
struct V_18 * V_19 = F_42 ( V_25 -> V_28 ) ;
struct V_17 * V_29 = V_298 ;
struct V_97 * V_301 ;
struct V_12 * V_7 , * V_2 ;
if ( ! V_29 )
return V_23 -> V_102 ;
V_300 -> V_302 = V_29 -> V_92 ;
V_301 = F_119 ( V_23 , V_275 ) ;
if ( ! V_301 )
goto V_303;
if ( V_29 -> V_27 . V_268 &&
F_111 ( V_23 , V_267 , V_29 -> V_27 . V_268 ) )
goto V_303;
V_7 = & V_29 -> V_7 ;
V_2 = & V_19 -> V_2 . V_7 ;
if ( V_2 -> V_55 ) {
struct V_73 * V_74 ;
V_74 = F_120 ( V_147 , V_7 -> V_55 ) ;
if ( V_74 && F_121 ( V_23 , V_150 , V_74 -> V_304 ) )
goto V_303;
}
if ( ! F_45 ( V_29 -> V_61 ) )
F_40 ( V_25 , V_29 ) ;
if ( F_106 ( V_23 , V_7 -> V_151 . V_44 , V_152 ,
V_2 -> V_151 . V_44 , V_153 ,
sizeof( V_7 -> V_151 . V_44 ) ) ||
F_106 ( V_23 , V_7 -> V_151 . V_41 , V_154 ,
V_2 -> V_151 . V_41 , V_155 ,
sizeof( V_7 -> V_151 . V_41 ) ) ||
F_106 ( V_23 , & V_7 -> V_57 . V_58 , V_156 ,
& V_2 -> V_57 . V_58 , V_103 ,
sizeof( V_7 -> V_57 . V_58 ) ) )
goto V_303;
if ( F_109 ( V_23 , & V_7 -> V_206 , & V_2 -> V_206 ) )
goto V_303;
if ( F_113 ( V_23 , & V_7 -> V_158 , & V_2 -> V_158 ) )
goto V_303;
if ( ( V_7 -> V_57 . V_58 == F_76 ( V_160 ) ||
V_7 -> V_57 . V_58 == F_76 ( V_161 ) ) &&
( F_106 ( V_23 , & V_7 -> V_57 . V_162 , V_163 ,
& V_2 -> V_57 . V_162 , V_103 ,
sizeof( V_7 -> V_57 . V_162 ) ) ||
F_112 ( V_23 , & V_7 -> V_164 , & V_2 -> V_164 ) ) )
goto V_303;
if ( V_7 -> V_167 . V_38 == V_39 &&
( F_106 ( V_23 , & V_7 -> V_43 . V_41 , V_165 ,
& V_2 -> V_43 . V_41 , V_168 ,
sizeof( V_7 -> V_43 . V_41 ) ) ||
F_106 ( V_23 , & V_7 -> V_43 . V_44 , V_166 ,
& V_2 -> V_43 . V_44 , V_169 ,
sizeof( V_7 -> V_43 . V_44 ) ) ) )
goto V_303;
else if ( V_7 -> V_167 . V_38 == V_46 &&
( F_106 ( V_23 , & V_7 -> V_48 . V_41 , V_170 ,
& V_2 -> V_48 . V_41 , V_172 ,
sizeof( V_7 -> V_48 . V_41 ) ) ||
F_106 ( V_23 , & V_7 -> V_48 . V_44 , V_171 ,
& V_2 -> V_48 . V_44 , V_173 ,
sizeof( V_7 -> V_48 . V_44 ) ) ) )
goto V_303;
if ( V_7 -> V_57 . V_162 == V_174 &&
( F_106 ( V_23 , & V_7 -> V_25 . V_41 , V_175 ,
& V_2 -> V_25 . V_41 , V_176 ,
sizeof( V_7 -> V_25 . V_41 ) ) ||
F_106 ( V_23 , & V_7 -> V_25 . V_44 , V_177 ,
& V_2 -> V_25 . V_44 , V_178 ,
sizeof( V_7 -> V_25 . V_44 ) ) ||
F_106 ( V_23 , & V_7 -> V_179 . V_61 , V_180 ,
& V_2 -> V_179 . V_61 , V_181 ,
sizeof( V_7 -> V_179 . V_61 ) ) ) )
goto V_303;
else if ( V_7 -> V_57 . V_162 == V_182 &&
( F_106 ( V_23 , & V_7 -> V_25 . V_41 , V_183 ,
& V_2 -> V_25 . V_41 , V_184 ,
sizeof( V_7 -> V_25 . V_41 ) ) ||
F_106 ( V_23 , & V_7 -> V_25 . V_44 , V_185 ,
& V_2 -> V_25 . V_44 , V_186 ,
sizeof( V_7 -> V_25 . V_44 ) ) ) )
goto V_303;
else if ( V_7 -> V_57 . V_162 == V_187 &&
( F_106 ( V_23 , & V_7 -> V_25 . V_41 , V_188 ,
& V_2 -> V_25 . V_41 , V_189 ,
sizeof( V_7 -> V_25 . V_41 ) ) ||
F_106 ( V_23 , & V_7 -> V_25 . V_44 , V_190 ,
& V_2 -> V_25 . V_44 , V_191 ,
sizeof( V_7 -> V_25 . V_44 ) ) ) )
goto V_303;
else if ( V_7 -> V_57 . V_58 == F_76 ( V_160 ) &&
V_7 -> V_57 . V_162 == V_192 &&
( F_106 ( V_23 , & V_7 -> V_193 . type ,
V_194 , & V_2 -> V_193 . type ,
V_195 ,
sizeof( V_7 -> V_193 . type ) ) ||
F_106 ( V_23 , & V_7 -> V_193 . V_196 ,
V_197 , & V_2 -> V_193 . V_196 ,
V_198 ,
sizeof( V_7 -> V_193 . V_196 ) ) ) )
goto V_303;
else if ( V_7 -> V_57 . V_58 == F_76 ( V_161 ) &&
V_7 -> V_57 . V_162 == V_199 &&
( F_106 ( V_23 , & V_7 -> V_193 . type ,
V_200 , & V_2 -> V_193 . type ,
V_201 ,
sizeof( V_7 -> V_193 . type ) ) ||
F_106 ( V_23 , & V_7 -> V_193 . V_196 ,
V_202 , & V_2 -> V_193 . V_196 ,
V_203 ,
sizeof( V_7 -> V_193 . V_196 ) ) ) )
goto V_303;
else if ( ( V_7 -> V_57 . V_58 == F_76 ( V_207 ) ||
V_7 -> V_57 . V_58 == F_76 ( V_208 ) ) &&
( F_106 ( V_23 , & V_7 -> V_209 . V_210 ,
V_211 , & V_2 -> V_209 . V_210 ,
V_212 ,
sizeof( V_7 -> V_209 . V_210 ) ) ||
F_106 ( V_23 , & V_7 -> V_209 . V_213 ,
V_214 , & V_2 -> V_209 . V_213 ,
V_215 ,
sizeof( V_7 -> V_209 . V_213 ) ) ||
F_106 ( V_23 , & V_7 -> V_209 . V_216 ,
V_217 , & V_2 -> V_209 . V_216 ,
V_218 ,
sizeof( V_7 -> V_209 . V_216 ) ) ||
F_106 ( V_23 , V_7 -> V_209 . V_219 , V_220 ,
V_2 -> V_209 . V_219 , V_221 ,
sizeof( V_7 -> V_209 . V_219 ) ) ||
F_106 ( V_23 , V_7 -> V_209 . V_222 , V_223 ,
V_2 -> V_209 . V_222 , V_224 ,
sizeof( V_7 -> V_209 . V_222 ) ) ) )
goto V_303;
if ( V_7 -> V_37 . V_38 == V_39 &&
( F_106 ( V_23 , & V_7 -> V_40 . V_41 ,
V_225 , & V_2 -> V_40 . V_41 ,
V_227 ,
sizeof( V_7 -> V_40 . V_41 ) ) ||
F_106 ( V_23 , & V_7 -> V_40 . V_44 ,
V_226 , & V_2 -> V_40 . V_44 ,
V_228 ,
sizeof( V_7 -> V_40 . V_44 ) ) ) )
goto V_303;
else if ( V_7 -> V_37 . V_38 == V_46 &&
( F_106 ( V_23 , & V_7 -> V_47 . V_41 ,
V_229 , & V_2 -> V_47 . V_41 ,
V_231 ,
sizeof( V_7 -> V_47 . V_41 ) ) ||
F_106 ( V_23 , & V_7 -> V_47 . V_44 ,
V_230 ,
& V_2 -> V_47 . V_44 ,
V_232 ,
sizeof( V_7 -> V_47 . V_44 ) ) ) )
goto V_303;
if ( F_106 ( V_23 , & V_7 -> V_49 , V_233 ,
& V_2 -> V_49 , V_103 ,
sizeof( V_7 -> V_49 ) ) ||
F_106 ( V_23 , & V_7 -> V_52 . V_41 ,
V_234 ,
& V_2 -> V_52 . V_41 ,
V_235 ,
sizeof( V_7 -> V_52 . V_41 ) ) ||
F_106 ( V_23 , & V_7 -> V_52 . V_44 ,
V_236 ,
& V_2 -> V_52 . V_44 ,
V_237 ,
sizeof( V_7 -> V_52 . V_44 ) ) )
goto V_303;
if ( F_116 ( V_23 , V_7 -> V_167 . V_61 , V_2 -> V_167 . V_61 ) )
goto V_303;
if ( V_29 -> V_61 && F_111 ( V_23 , V_281 , V_29 -> V_61 ) )
goto V_303;
if ( F_122 ( V_23 , & V_29 -> V_62 ) )
goto V_303;
F_123 ( V_23 , V_301 ) ;
if ( F_124 ( V_23 , & V_29 -> V_62 ) < 0 )
goto V_303;
return V_23 -> V_102 ;
V_303:
F_125 ( V_23 , V_301 ) ;
return - 1 ;
}
static void F_126 ( void * V_298 , T_3 V_268 , unsigned long V_305 )
{
struct V_17 * V_29 = V_298 ;
if ( V_29 && V_29 -> V_27 . V_268 == V_268 )
V_29 -> V_27 . V_306 = V_305 ;
}
static int T_6 F_127 ( void )
{
return F_128 ( & V_307 ) ;
}
static void T_7 F_129 ( void )
{
F_130 ( & V_307 ) ;
}
