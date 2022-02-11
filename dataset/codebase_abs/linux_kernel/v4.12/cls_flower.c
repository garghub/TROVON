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
V_71 -> V_81 -> V_82 ( V_71 , V_25 -> V_83 -> V_84 , V_25 -> V_59 , V_74 ) ;
}
static int F_29 ( struct V_24 * V_25 ,
struct V_85 * V_60 ,
struct V_12 * V_2 ,
struct V_17 * V_29 )
{
struct V_70 * V_71 = V_25 -> V_83 -> V_86 -> V_71 ;
struct V_68 V_69 = { 0 } ;
struct V_73 * V_74 = & V_29 -> V_74 ;
int V_87 ;
if ( ! F_28 ( V_71 , V_25 ) ) {
if ( F_30 ( V_71 , & V_29 -> V_62 , & V_29 -> V_72 ) ||
( V_29 -> V_72 && ! F_28 ( V_29 -> V_72 , V_25 ) ) ) {
V_29 -> V_72 = V_71 ;
return F_17 ( V_29 -> V_61 ) ? - V_88 : 0 ;
}
V_71 = V_29 -> V_72 ;
V_74 -> V_89 = true ;
} else {
V_29 -> V_72 = V_71 ;
}
V_69 . V_75 = V_90 ;
V_69 . V_77 = V_25 -> V_77 ;
V_69 . V_78 = ( unsigned long ) V_29 ;
V_69 . V_60 = V_60 ;
V_69 . V_2 = V_2 ;
V_69 . V_7 = & V_29 -> V_13 ;
V_69 . V_62 = & V_29 -> V_62 ;
V_74 -> type = V_79 ;
V_74 -> V_80 = & V_69 ;
V_87 = V_71 -> V_81 -> V_82 ( V_71 , V_25 -> V_83 -> V_84 , V_25 -> V_59 ,
V_74 ) ;
if ( ! V_87 )
V_29 -> V_61 |= V_91 ;
if ( F_17 ( V_29 -> V_61 ) )
return V_87 ;
return 0 ;
}
static void F_31 ( struct V_24 * V_25 , struct V_17 * V_29 )
{
struct V_68 V_69 = { 0 } ;
struct V_70 * V_71 = V_29 -> V_72 ;
struct V_73 * V_74 = & V_29 -> V_74 ;
if ( ! F_28 ( V_71 , V_25 ) )
return;
V_69 . V_75 = V_92 ;
V_69 . V_77 = V_25 -> V_77 ;
V_69 . V_78 = ( unsigned long ) V_29 ;
V_69 . V_62 = & V_29 -> V_62 ;
V_74 -> type = V_79 ;
V_74 -> V_80 = & V_69 ;
V_71 -> V_81 -> V_82 ( V_71 , V_25 -> V_83 -> V_84 , V_25 -> V_59 , V_74 ) ;
}
static void F_32 ( struct V_24 * V_25 , struct V_17 * V_29 )
{
F_33 ( & V_29 -> V_93 ) ;
if ( ! F_34 ( V_29 -> V_61 ) )
F_27 ( V_25 , V_29 ) ;
F_35 ( V_25 , & V_29 -> V_27 ) ;
F_36 ( & V_29 -> V_67 , F_23 ) ;
}
static void F_37 ( struct V_94 * V_95 )
{
struct V_18 * V_19 = F_24 ( V_95 , struct V_18 ,
V_95 ) ;
if ( V_19 -> V_96 )
F_38 ( & V_19 -> V_20 ) ;
F_26 ( V_19 ) ;
F_39 ( V_97 ) ;
}
static void F_40 ( struct V_66 * V_67 )
{
struct V_18 * V_19 = F_24 ( V_67 , struct V_18 , V_67 ) ;
F_41 ( & V_19 -> V_95 , F_37 ) ;
F_42 ( & V_19 -> V_95 ) ;
}
static void F_43 ( struct V_24 * V_25 )
{
struct V_18 * V_19 = F_44 ( V_25 -> V_28 ) ;
struct V_17 * V_29 , * V_98 ;
F_45 (f, next, &head->filters, list)
F_32 ( V_25 , V_29 ) ;
F_46 ( V_97 ) ;
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
static void F_49 ( struct V_99 * * V_100 ,
void * V_101 , int V_102 ,
void * V_2 , int V_103 , int V_104 )
{
if ( ! V_100 [ V_102 ] )
return;
memcpy ( V_101 , F_50 ( V_100 [ V_102 ] ) , V_104 ) ;
if ( V_103 == V_105 || ! V_100 [ V_103 ] )
memset ( V_2 , 0xff , V_104 ) ;
else
memcpy ( V_2 , F_50 ( V_100 [ V_103 ] ) , V_104 ) ;
}
static int F_51 ( struct V_99 * * V_100 ,
struct V_106 * V_107 ,
struct V_106 * V_108 )
{
if ( V_100 [ V_109 ] ) {
V_107 -> V_110 = F_52 ( V_100 [ V_109 ] ) ;
V_108 -> V_110 = V_111 ;
}
if ( V_100 [ V_112 ] ) {
T_1 V_113 = F_52 ( V_100 [ V_112 ] ) ;
if ( V_113 & ~ V_114 )
return - V_88 ;
V_107 -> V_115 = V_113 ;
V_108 -> V_115 = V_114 ;
}
if ( V_100 [ V_116 ] ) {
T_1 V_74 = F_52 ( V_100 [ V_116 ] ) ;
if ( V_74 & ~ V_117 )
return - V_88 ;
V_107 -> V_118 = V_74 ;
V_108 -> V_118 = V_117 ;
}
if ( V_100 [ V_119 ] ) {
T_3 V_120 = F_53 ( V_100 [ V_119 ] ) ;
if ( V_120 & ~ V_121 )
return - V_88 ;
V_107 -> V_122 = V_120 ;
V_108 -> V_122 = V_121 ;
}
return 0 ;
}
static void F_54 ( struct V_99 * * V_100 ,
struct V_123 * V_107 ,
struct V_123 * V_108 )
{
#define F_55 0x7
if ( V_100 [ V_124 ] ) {
V_107 -> V_125 =
F_56 ( V_100 [ V_124 ] ) & V_126 ;
V_108 -> V_125 = V_126 ;
}
if ( V_100 [ V_127 ] ) {
V_107 -> V_128 =
F_52 ( V_100 [ V_127 ] ) &
F_55 ;
V_108 -> V_128 = F_55 ;
}
}
static void F_57 ( T_3 V_129 , T_3 V_130 ,
T_3 * V_131 , T_3 * V_132 ,
T_3 V_133 , T_3 V_134 )
{
if ( V_130 & V_133 ) {
* V_132 |= V_134 ;
if ( V_129 & V_133 )
* V_131 |= V_134 ;
}
}
static int F_58 ( struct V_99 * * V_100 ,
T_3 * V_135 , T_3 * V_136 )
{
T_3 V_7 , V_2 ;
if ( ! V_100 [ V_137 ] )
return - V_88 ;
V_7 = F_59 ( F_53 ( V_100 [ V_138 ] ) ) ;
V_2 = F_59 ( F_53 ( V_100 [ V_137 ] ) ) ;
* V_135 = 0 ;
* V_136 = 0 ;
F_57 ( V_7 , V_2 , V_135 , V_136 ,
V_139 , V_140 ) ;
return 0 ;
}
static int F_60 ( struct V_141 * V_141 , struct V_99 * * V_100 ,
struct V_12 * V_7 , struct V_12 * V_2 )
{
T_4 V_142 ;
int V_143 = 0 ;
#ifdef F_61
if ( V_100 [ V_144 ] ) {
int V_87 = F_62 ( V_141 , V_100 [ V_144 ] ) ;
if ( V_87 < 0 )
return V_87 ;
V_7 -> V_55 = V_87 ;
V_2 -> V_55 = 0xffffffff ;
}
#endif
F_49 ( V_100 , V_7 -> V_145 . V_44 , V_146 ,
V_2 -> V_145 . V_44 , V_147 ,
sizeof( V_7 -> V_145 . V_44 ) ) ;
F_49 ( V_100 , V_7 -> V_145 . V_41 , V_148 ,
V_2 -> V_145 . V_41 , V_149 ,
sizeof( V_7 -> V_145 . V_41 ) ) ;
if ( V_100 [ V_150 ] ) {
V_142 = F_63 ( V_100 [ V_150 ] ) ;
if ( V_142 == F_64 ( V_151 ) ) {
F_54 ( V_100 , & V_7 -> V_152 , & V_2 -> V_152 ) ;
F_49 ( V_100 , & V_7 -> V_57 . V_58 ,
V_153 ,
& V_2 -> V_57 . V_58 , V_105 ,
sizeof( V_7 -> V_57 . V_58 ) ) ;
} else {
V_7 -> V_57 . V_58 = V_142 ;
V_2 -> V_57 . V_58 = F_65 ( ~ 0 ) ;
}
}
if ( V_7 -> V_57 . V_58 == F_64 ( V_154 ) ||
V_7 -> V_57 . V_58 == F_64 ( V_155 ) ) {
F_49 ( V_100 , & V_7 -> V_57 . V_156 , V_157 ,
& V_2 -> V_57 . V_156 , V_105 ,
sizeof( V_7 -> V_57 . V_156 ) ) ;
}
if ( V_100 [ V_158 ] || V_100 [ V_159 ] ) {
V_7 -> V_160 . V_38 = V_39 ;
V_2 -> V_160 . V_38 = ~ 0 ;
F_49 ( V_100 , & V_7 -> V_43 . V_41 , V_158 ,
& V_2 -> V_43 . V_41 , V_161 ,
sizeof( V_7 -> V_43 . V_41 ) ) ;
F_49 ( V_100 , & V_7 -> V_43 . V_44 , V_159 ,
& V_2 -> V_43 . V_44 , V_162 ,
sizeof( V_7 -> V_43 . V_44 ) ) ;
} else if ( V_100 [ V_163 ] || V_100 [ V_164 ] ) {
V_7 -> V_160 . V_38 = V_46 ;
V_2 -> V_160 . V_38 = ~ 0 ;
F_49 ( V_100 , & V_7 -> V_48 . V_41 , V_163 ,
& V_2 -> V_48 . V_41 , V_165 ,
sizeof( V_7 -> V_48 . V_41 ) ) ;
F_49 ( V_100 , & V_7 -> V_48 . V_44 , V_164 ,
& V_2 -> V_48 . V_44 , V_166 ,
sizeof( V_7 -> V_48 . V_44 ) ) ;
}
if ( V_7 -> V_57 . V_156 == V_167 ) {
F_49 ( V_100 , & V_7 -> V_25 . V_41 , V_168 ,
& V_2 -> V_25 . V_41 , V_169 ,
sizeof( V_7 -> V_25 . V_41 ) ) ;
F_49 ( V_100 , & V_7 -> V_25 . V_44 , V_170 ,
& V_2 -> V_25 . V_44 , V_171 ,
sizeof( V_7 -> V_25 . V_44 ) ) ;
} else if ( V_7 -> V_57 . V_156 == V_172 ) {
F_49 ( V_100 , & V_7 -> V_25 . V_41 , V_173 ,
& V_2 -> V_25 . V_41 , V_174 ,
sizeof( V_7 -> V_25 . V_41 ) ) ;
F_49 ( V_100 , & V_7 -> V_25 . V_44 , V_175 ,
& V_2 -> V_25 . V_44 , V_176 ,
sizeof( V_7 -> V_25 . V_44 ) ) ;
} else if ( V_7 -> V_57 . V_156 == V_177 ) {
F_49 ( V_100 , & V_7 -> V_25 . V_41 , V_178 ,
& V_2 -> V_25 . V_41 , V_179 ,
sizeof( V_7 -> V_25 . V_41 ) ) ;
F_49 ( V_100 , & V_7 -> V_25 . V_44 , V_180 ,
& V_2 -> V_25 . V_44 , V_181 ,
sizeof( V_7 -> V_25 . V_44 ) ) ;
} else if ( V_7 -> V_57 . V_58 == F_64 ( V_154 ) &&
V_7 -> V_57 . V_156 == V_182 ) {
F_49 ( V_100 , & V_7 -> V_183 . type , V_184 ,
& V_2 -> V_183 . type ,
V_185 ,
sizeof( V_7 -> V_183 . type ) ) ;
F_49 ( V_100 , & V_7 -> V_183 . V_186 , V_187 ,
& V_2 -> V_183 . V_186 ,
V_188 ,
sizeof( V_7 -> V_183 . V_186 ) ) ;
} else if ( V_7 -> V_57 . V_58 == F_64 ( V_155 ) &&
V_7 -> V_57 . V_156 == V_189 ) {
F_49 ( V_100 , & V_7 -> V_183 . type , V_190 ,
& V_2 -> V_183 . type ,
V_191 ,
sizeof( V_7 -> V_183 . type ) ) ;
F_49 ( V_100 , & V_7 -> V_183 . V_186 , V_192 ,
& V_2 -> V_183 . V_186 ,
V_193 ,
sizeof( V_7 -> V_183 . V_186 ) ) ;
} else if ( V_7 -> V_57 . V_58 == F_64 ( V_194 ) ||
V_7 -> V_57 . V_58 == F_64 ( V_195 ) ) {
V_143 = F_51 ( V_100 , & V_7 -> V_196 , & V_2 -> V_196 ) ;
if ( V_143 )
return V_143 ;
} else if ( V_7 -> V_57 . V_58 == F_64 ( V_197 ) ||
V_7 -> V_57 . V_58 == F_64 ( V_198 ) ) {
F_49 ( V_100 , & V_7 -> V_199 . V_200 , V_201 ,
& V_2 -> V_199 . V_200 , V_202 ,
sizeof( V_7 -> V_199 . V_200 ) ) ;
F_49 ( V_100 , & V_7 -> V_199 . V_203 , V_204 ,
& V_2 -> V_199 . V_203 , V_205 ,
sizeof( V_7 -> V_199 . V_203 ) ) ;
F_49 ( V_100 , & V_7 -> V_199 . V_206 , V_207 ,
& V_2 -> V_199 . V_206 , V_208 ,
sizeof( V_7 -> V_199 . V_206 ) ) ;
F_49 ( V_100 , V_7 -> V_199 . V_209 , V_210 ,
V_2 -> V_199 . V_209 , V_211 ,
sizeof( V_7 -> V_199 . V_209 ) ) ;
F_49 ( V_100 , V_7 -> V_199 . V_212 , V_213 ,
V_2 -> V_199 . V_212 , V_214 ,
sizeof( V_7 -> V_199 . V_212 ) ) ;
}
if ( V_100 [ V_215 ] ||
V_100 [ V_216 ] ) {
V_7 -> V_37 . V_38 = V_39 ;
V_2 -> V_37 . V_38 = ~ 0 ;
F_49 ( V_100 , & V_7 -> V_40 . V_41 ,
V_215 ,
& V_2 -> V_40 . V_41 ,
V_217 ,
sizeof( V_7 -> V_40 . V_41 ) ) ;
F_49 ( V_100 , & V_7 -> V_40 . V_44 ,
V_216 ,
& V_2 -> V_40 . V_44 ,
V_218 ,
sizeof( V_7 -> V_40 . V_44 ) ) ;
}
if ( V_100 [ V_219 ] ||
V_100 [ V_220 ] ) {
V_7 -> V_37 . V_38 = V_46 ;
V_2 -> V_37 . V_38 = ~ 0 ;
F_49 ( V_100 , & V_7 -> V_47 . V_41 ,
V_219 ,
& V_2 -> V_47 . V_41 ,
V_221 ,
sizeof( V_7 -> V_47 . V_41 ) ) ;
F_49 ( V_100 , & V_7 -> V_47 . V_44 ,
V_220 ,
& V_2 -> V_47 . V_44 ,
V_222 ,
sizeof( V_7 -> V_47 . V_44 ) ) ;
}
F_49 ( V_100 , & V_7 -> V_49 . V_50 , V_223 ,
& V_2 -> V_49 . V_50 , V_105 ,
sizeof( V_7 -> V_49 . V_50 ) ) ;
F_49 ( V_100 , & V_7 -> V_52 . V_41 , V_224 ,
& V_2 -> V_52 . V_41 , V_225 ,
sizeof( V_7 -> V_52 . V_41 ) ) ;
F_49 ( V_100 , & V_7 -> V_52 . V_44 , V_226 ,
& V_2 -> V_52 . V_44 , V_227 ,
sizeof( V_7 -> V_52 . V_44 ) ) ;
if ( V_100 [ V_138 ] )
V_143 = F_58 ( V_100 , & V_7 -> V_160 . V_61 , & V_2 -> V_160 . V_61 ) ;
return V_143 ;
}
static bool F_66 ( struct V_1 * V_228 ,
struct V_1 * V_229 )
{
const long * V_230 = F_5 ( & V_228 -> V_7 , V_228 ) ;
const long * V_231 = F_5 ( & V_229 -> V_7 , V_229 ) ;
return ! memcmp ( & V_228 -> V_3 , & V_229 -> V_3 , sizeof( V_228 -> V_3 ) ) &&
! memcmp ( V_230 , V_231 , F_1 ( V_228 ) ) ;
}
static int F_67 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
V_19 -> V_21 = V_232 ;
V_19 -> V_21 . V_233 = F_1 ( V_2 ) ;
V_19 -> V_21 . V_234 += V_2 -> V_3 . V_5 ;
return F_68 ( & V_19 -> V_20 , & V_19 -> V_21 ) ;
}
static void F_69 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
struct V_235 V_236 [ V_237 ] ;
T_2 V_238 = 0 ;
F_70 ( V_236 , V_238 , V_239 , V_160 ) ;
F_70 ( V_236 , V_238 , V_240 , V_57 ) ;
F_71 ( & V_2 -> V_7 , V_236 , V_238 ,
V_241 , V_145 ) ;
F_71 ( & V_2 -> V_7 , V_236 , V_238 ,
V_39 , V_43 ) ;
F_71 ( & V_2 -> V_7 , V_236 , V_238 ,
V_46 , V_48 ) ;
F_71 ( & V_2 -> V_7 , V_236 , V_238 ,
V_242 , V_25 ) ;
F_71 ( & V_2 -> V_7 , V_236 , V_238 ,
V_243 , V_183 ) ;
F_71 ( & V_2 -> V_7 , V_236 , V_238 ,
V_244 , V_199 ) ;
F_71 ( & V_2 -> V_7 , V_236 , V_238 ,
V_245 , V_196 ) ;
F_71 ( & V_2 -> V_7 , V_236 , V_238 ,
V_246 , V_152 ) ;
F_71 ( & V_2 -> V_7 , V_236 , V_238 ,
V_247 , V_49 ) ;
F_71 ( & V_2 -> V_7 , V_236 , V_238 ,
V_248 , V_40 ) ;
F_71 ( & V_2 -> V_7 , V_236 , V_238 ,
V_249 , V_47 ) ;
if ( F_72 ( & V_2 -> V_7 , V_40 ) ||
F_72 ( & V_2 -> V_7 , V_47 ) )
F_70 ( V_236 , V_238 , V_250 ,
V_37 ) ;
F_71 ( & V_2 -> V_7 , V_236 , V_238 ,
V_251 , V_52 ) ;
F_73 ( & V_19 -> V_60 , V_236 , V_238 ) ;
}
static int F_74 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
int V_87 ;
if ( V_19 -> V_96 ) {
if ( ! F_66 ( & V_19 -> V_2 , V_2 ) )
return - V_88 ;
else
return 0 ;
}
V_87 = F_67 ( V_19 , V_2 ) ;
if ( V_87 )
return V_87 ;
memcpy ( & V_19 -> V_2 , V_2 , sizeof( V_19 -> V_2 ) ) ;
V_19 -> V_96 = true ;
F_69 ( V_19 , V_2 ) ;
return 0 ;
}
static int F_75 ( struct V_141 * V_141 , struct V_24 * V_25 ,
struct V_17 * V_29 , struct V_1 * V_2 ,
unsigned long V_252 , struct V_99 * * V_100 ,
struct V_99 * V_253 , bool V_254 )
{
struct V_255 V_256 ;
int V_87 ;
V_87 = F_76 ( & V_256 , V_257 , 0 ) ;
if ( V_87 < 0 )
return V_87 ;
V_87 = F_77 ( V_141 , V_25 , V_100 , V_253 , & V_256 , V_254 ) ;
if ( V_87 < 0 )
goto V_258;
if ( V_100 [ V_259 ] ) {
V_29 -> V_27 . V_260 = F_53 ( V_100 [ V_259 ] ) ;
F_78 ( V_25 , & V_29 -> V_27 , V_252 ) ;
}
V_87 = F_60 ( V_141 , V_100 , & V_29 -> V_7 , & V_2 -> V_7 ) ;
if ( V_87 )
goto V_258;
F_2 ( V_2 ) ;
F_6 ( & V_29 -> V_13 , & V_29 -> V_7 , V_2 ) ;
F_79 ( V_25 , & V_29 -> V_62 , & V_256 ) ;
return 0 ;
V_258:
F_25 ( & V_256 ) ;
return V_87 ;
}
static T_3 F_80 ( struct V_24 * V_25 ,
struct V_18 * V_19 )
{
unsigned int V_9 = 0x80000000 ;
T_3 V_84 ;
do {
if ( ++ V_19 -> V_261 == 0x7FFFFFFF )
V_19 -> V_261 = 1 ;
} while ( -- V_9 > 0 && F_47 ( V_25 , V_19 -> V_261 ) );
if ( F_81 ( V_9 == 0 ) ) {
F_82 ( L_1 ) ;
V_84 = 0 ;
} else {
V_84 = V_19 -> V_261 ;
}
return V_84 ;
}
static int F_83 ( struct V_141 * V_141 , struct V_22 * V_262 ,
struct V_24 * V_25 , unsigned long V_252 ,
T_3 V_84 , struct V_99 * * V_263 ,
unsigned long * V_264 , bool V_254 )
{
struct V_18 * V_19 = F_44 ( V_25 -> V_28 ) ;
struct V_17 * V_265 = (struct V_17 * ) * V_264 ;
struct V_17 * V_266 ;
struct V_99 * * V_100 ;
struct V_1 V_2 = {} ;
int V_87 ;
if ( ! V_263 [ V_267 ] )
return - V_88 ;
V_100 = F_84 ( V_268 + 1 , sizeof( struct V_99 * ) , V_63 ) ;
if ( ! V_100 )
return - V_64 ;
V_87 = F_85 ( V_100 , V_268 , V_263 [ V_267 ] ,
V_269 , NULL ) ;
if ( V_87 < 0 )
goto V_270;
if ( V_265 && V_84 && V_265 -> V_84 != V_84 ) {
V_87 = - V_88 ;
goto V_270;
}
V_266 = F_20 ( sizeof( * V_266 ) , V_63 ) ;
if ( ! V_266 ) {
V_87 = - V_64 ;
goto V_270;
}
V_87 = F_76 ( & V_266 -> V_62 , V_257 , 0 ) ;
if ( V_87 < 0 )
goto V_258;
if ( ! V_84 ) {
V_84 = F_80 ( V_25 , V_19 ) ;
if ( ! V_84 ) {
V_87 = - V_88 ;
goto V_258;
}
}
V_266 -> V_84 = V_84 ;
if ( V_100 [ V_271 ] ) {
V_266 -> V_61 = F_53 ( V_100 [ V_271 ] ) ;
if ( ! F_86 ( V_266 -> V_61 ) ) {
V_87 = - V_88 ;
goto V_258;
}
}
V_87 = F_75 ( V_141 , V_25 , V_266 , & V_2 , V_252 , V_100 , V_263 [ V_272 ] , V_254 ) ;
if ( V_87 )
goto V_258;
V_87 = F_74 ( V_19 , & V_2 ) ;
if ( V_87 )
goto V_258;
if ( ! F_17 ( V_266 -> V_61 ) ) {
if ( ! V_265 && F_8 ( V_19 , & V_266 -> V_13 ) ) {
V_87 = - V_273 ;
goto V_258;
}
V_87 = F_87 ( & V_19 -> V_20 , & V_266 -> V_274 ,
V_19 -> V_21 ) ;
if ( V_87 )
goto V_258;
}
if ( ! F_34 ( V_266 -> V_61 ) ) {
V_87 = F_29 ( V_25 ,
& V_19 -> V_60 ,
& V_2 . V_7 ,
V_266 ) ;
if ( V_87 )
goto V_258;
}
if ( ! F_88 ( V_266 -> V_61 ) )
V_266 -> V_61 |= V_275 ;
if ( V_265 ) {
if ( ! F_17 ( V_265 -> V_61 ) )
F_89 ( & V_19 -> V_20 , & V_265 -> V_274 ,
V_19 -> V_21 ) ;
if ( ! F_34 ( V_265 -> V_61 ) )
F_27 ( V_25 , V_265 ) ;
}
* V_264 = ( unsigned long ) V_266 ;
if ( V_265 ) {
F_90 ( & V_265 -> V_93 , & V_266 -> V_93 ) ;
F_35 ( V_25 , & V_265 -> V_27 ) ;
F_36 ( & V_265 -> V_67 , F_23 ) ;
} else {
F_91 ( & V_266 -> V_93 , & V_19 -> V_65 ) ;
}
F_26 ( V_100 ) ;
return 0 ;
V_258:
F_25 ( & V_266 -> V_62 ) ;
F_26 ( V_266 ) ;
V_270:
F_26 ( V_100 ) ;
return V_87 ;
}
static int F_92 ( struct V_24 * V_25 , unsigned long V_264 , bool * V_11 )
{
struct V_18 * V_19 = F_44 ( V_25 -> V_28 ) ;
struct V_17 * V_29 = (struct V_17 * ) V_264 ;
if ( ! F_17 ( V_29 -> V_61 ) )
F_89 ( & V_19 -> V_20 , & V_29 -> V_274 ,
V_19 -> V_21 ) ;
F_32 ( V_25 , V_29 ) ;
* V_11 = F_93 ( & V_19 -> V_65 ) ;
return 0 ;
}
static void F_94 ( struct V_24 * V_25 , struct V_276 * V_264 )
{
struct V_18 * V_19 = F_44 ( V_25 -> V_28 ) ;
struct V_17 * V_29 ;
F_95 (f, &head->filters, list) {
if ( V_264 -> V_277 < V_264 -> V_278 )
goto V_278;
if ( V_264 -> V_279 ( V_25 , ( unsigned long ) V_29 , V_264 ) < 0 ) {
V_264 -> V_280 = 1 ;
break;
}
V_278:
V_264 -> V_277 ++ ;
}
}
static int F_96 ( struct V_22 * V_23 ,
void * V_101 , int V_102 ,
void * V_2 , int V_103 , int V_104 )
{
int V_87 ;
if ( ! F_97 ( V_2 , 0 , V_104 ) )
return 0 ;
V_87 = F_98 ( V_23 , V_102 , V_104 , V_101 ) ;
if ( V_87 )
return V_87 ;
if ( V_103 != V_105 ) {
V_87 = F_98 ( V_23 , V_103 , V_104 , V_2 ) ;
if ( V_87 )
return V_87 ;
}
return 0 ;
}
static int F_99 ( struct V_22 * V_23 ,
struct V_106 * V_281 ,
struct V_106 * V_282 )
{
int V_87 ;
if ( ! F_97 ( V_282 , 0 , sizeof( * V_282 ) ) )
return 0 ;
if ( V_282 -> V_110 ) {
V_87 = F_100 ( V_23 , V_109 ,
V_281 -> V_110 ) ;
if ( V_87 )
return V_87 ;
}
if ( V_282 -> V_118 ) {
V_87 = F_100 ( V_23 , V_116 ,
V_281 -> V_118 ) ;
if ( V_87 )
return V_87 ;
}
if ( V_282 -> V_122 ) {
V_87 = F_101 ( V_23 , V_119 ,
V_281 -> V_122 ) ;
if ( V_87 )
return V_87 ;
}
if ( V_282 -> V_115 ) {
V_87 = F_100 ( V_23 , V_112 ,
V_281 -> V_115 ) ;
if ( V_87 )
return V_87 ;
}
return 0 ;
}
static int F_102 ( struct V_22 * V_23 ,
struct V_123 * V_283 ,
struct V_123 * V_284 )
{
int V_87 ;
if ( ! F_97 ( V_284 , 0 , sizeof( * V_284 ) ) )
return 0 ;
if ( V_284 -> V_125 ) {
V_87 = F_103 ( V_23 , V_124 ,
V_283 -> V_125 ) ;
if ( V_87 )
return V_87 ;
}
if ( V_284 -> V_128 ) {
V_87 = F_100 ( V_23 , V_127 ,
V_283 -> V_128 ) ;
if ( V_87 )
return V_87 ;
}
return 0 ;
}
static void F_104 ( T_3 V_131 , T_3 V_132 ,
T_3 * V_129 , T_3 * V_130 ,
T_3 V_133 , T_3 V_134 )
{
if ( V_132 & V_134 ) {
* V_130 |= V_133 ;
if ( V_131 & V_134 )
* V_129 |= V_133 ;
}
}
static int F_105 ( struct V_22 * V_23 , T_3 V_135 , T_3 V_136 )
{
T_3 V_7 , V_2 ;
T_5 V_285 , V_286 ;
int V_87 ;
if ( ! F_97 ( & V_136 , 0 , sizeof( V_136 ) ) )
return 0 ;
V_7 = 0 ;
V_2 = 0 ;
F_104 ( V_135 , V_136 , & V_7 , & V_2 ,
V_139 , V_140 ) ;
V_285 = F_106 ( V_7 ) ;
V_286 = F_106 ( V_2 ) ;
V_87 = F_98 ( V_23 , V_138 , 4 , & V_285 ) ;
if ( V_87 )
return V_87 ;
return F_98 ( V_23 , V_137 , 4 , & V_286 ) ;
}
static int F_107 ( struct V_141 * V_141 , struct V_24 * V_25 , unsigned long V_287 ,
struct V_22 * V_23 , struct V_288 * V_289 )
{
struct V_18 * V_19 = F_44 ( V_25 -> V_28 ) ;
struct V_17 * V_29 = (struct V_17 * ) V_287 ;
struct V_99 * V_290 ;
struct V_12 * V_7 , * V_2 ;
if ( ! V_29 )
return V_23 -> V_104 ;
V_289 -> V_291 = V_29 -> V_84 ;
V_290 = F_108 ( V_23 , V_267 ) ;
if ( ! V_290 )
goto V_292;
if ( V_29 -> V_27 . V_260 &&
F_101 ( V_23 , V_259 , V_29 -> V_27 . V_260 ) )
goto V_292;
V_7 = & V_29 -> V_7 ;
V_2 = & V_19 -> V_2 . V_7 ;
if ( V_2 -> V_55 ) {
struct V_70 * V_71 ;
V_71 = F_109 ( V_141 , V_7 -> V_55 ) ;
if ( V_71 && F_110 ( V_23 , V_144 , V_71 -> V_293 ) )
goto V_292;
}
if ( ! F_34 ( V_29 -> V_61 ) )
F_31 ( V_25 , V_29 ) ;
if ( F_96 ( V_23 , V_7 -> V_145 . V_44 , V_146 ,
V_2 -> V_145 . V_44 , V_147 ,
sizeof( V_7 -> V_145 . V_44 ) ) ||
F_96 ( V_23 , V_7 -> V_145 . V_41 , V_148 ,
V_2 -> V_145 . V_41 , V_149 ,
sizeof( V_7 -> V_145 . V_41 ) ) ||
F_96 ( V_23 , & V_7 -> V_57 . V_58 , V_150 ,
& V_2 -> V_57 . V_58 , V_105 ,
sizeof( V_7 -> V_57 . V_58 ) ) )
goto V_292;
if ( F_99 ( V_23 , & V_7 -> V_196 , & V_2 -> V_196 ) )
goto V_292;
if ( F_102 ( V_23 , & V_7 -> V_152 , & V_2 -> V_152 ) )
goto V_292;
if ( ( V_7 -> V_57 . V_58 == F_64 ( V_154 ) ||
V_7 -> V_57 . V_58 == F_64 ( V_155 ) ) &&
F_96 ( V_23 , & V_7 -> V_57 . V_156 , V_157 ,
& V_2 -> V_57 . V_156 , V_105 ,
sizeof( V_7 -> V_57 . V_156 ) ) )
goto V_292;
if ( V_7 -> V_160 . V_38 == V_39 &&
( F_96 ( V_23 , & V_7 -> V_43 . V_41 , V_158 ,
& V_2 -> V_43 . V_41 , V_161 ,
sizeof( V_7 -> V_43 . V_41 ) ) ||
F_96 ( V_23 , & V_7 -> V_43 . V_44 , V_159 ,
& V_2 -> V_43 . V_44 , V_162 ,
sizeof( V_7 -> V_43 . V_44 ) ) ) )
goto V_292;
else if ( V_7 -> V_160 . V_38 == V_46 &&
( F_96 ( V_23 , & V_7 -> V_48 . V_41 , V_163 ,
& V_2 -> V_48 . V_41 , V_165 ,
sizeof( V_7 -> V_48 . V_41 ) ) ||
F_96 ( V_23 , & V_7 -> V_48 . V_44 , V_164 ,
& V_2 -> V_48 . V_44 , V_166 ,
sizeof( V_7 -> V_48 . V_44 ) ) ) )
goto V_292;
if ( V_7 -> V_57 . V_156 == V_167 &&
( F_96 ( V_23 , & V_7 -> V_25 . V_41 , V_168 ,
& V_2 -> V_25 . V_41 , V_169 ,
sizeof( V_7 -> V_25 . V_41 ) ) ||
F_96 ( V_23 , & V_7 -> V_25 . V_44 , V_170 ,
& V_2 -> V_25 . V_44 , V_171 ,
sizeof( V_7 -> V_25 . V_44 ) ) ) )
goto V_292;
else if ( V_7 -> V_57 . V_156 == V_172 &&
( F_96 ( V_23 , & V_7 -> V_25 . V_41 , V_173 ,
& V_2 -> V_25 . V_41 , V_174 ,
sizeof( V_7 -> V_25 . V_41 ) ) ||
F_96 ( V_23 , & V_7 -> V_25 . V_44 , V_175 ,
& V_2 -> V_25 . V_44 , V_176 ,
sizeof( V_7 -> V_25 . V_44 ) ) ) )
goto V_292;
else if ( V_7 -> V_57 . V_156 == V_177 &&
( F_96 ( V_23 , & V_7 -> V_25 . V_41 , V_178 ,
& V_2 -> V_25 . V_41 , V_179 ,
sizeof( V_7 -> V_25 . V_41 ) ) ||
F_96 ( V_23 , & V_7 -> V_25 . V_44 , V_180 ,
& V_2 -> V_25 . V_44 , V_181 ,
sizeof( V_7 -> V_25 . V_44 ) ) ) )
goto V_292;
else if ( V_7 -> V_57 . V_58 == F_64 ( V_154 ) &&
V_7 -> V_57 . V_156 == V_182 &&
( F_96 ( V_23 , & V_7 -> V_183 . type ,
V_184 , & V_2 -> V_183 . type ,
V_185 ,
sizeof( V_7 -> V_183 . type ) ) ||
F_96 ( V_23 , & V_7 -> V_183 . V_186 ,
V_187 , & V_2 -> V_183 . V_186 ,
V_188 ,
sizeof( V_7 -> V_183 . V_186 ) ) ) )
goto V_292;
else if ( V_7 -> V_57 . V_58 == F_64 ( V_155 ) &&
V_7 -> V_57 . V_156 == V_189 &&
( F_96 ( V_23 , & V_7 -> V_183 . type ,
V_190 , & V_2 -> V_183 . type ,
V_191 ,
sizeof( V_7 -> V_183 . type ) ) ||
F_96 ( V_23 , & V_7 -> V_183 . V_186 ,
V_192 , & V_2 -> V_183 . V_186 ,
V_193 ,
sizeof( V_7 -> V_183 . V_186 ) ) ) )
goto V_292;
else if ( ( V_7 -> V_57 . V_58 == F_64 ( V_197 ) ||
V_7 -> V_57 . V_58 == F_64 ( V_198 ) ) &&
( F_96 ( V_23 , & V_7 -> V_199 . V_200 ,
V_201 , & V_2 -> V_199 . V_200 ,
V_202 ,
sizeof( V_7 -> V_199 . V_200 ) ) ||
F_96 ( V_23 , & V_7 -> V_199 . V_203 ,
V_204 , & V_2 -> V_199 . V_203 ,
V_205 ,
sizeof( V_7 -> V_199 . V_203 ) ) ||
F_96 ( V_23 , & V_7 -> V_199 . V_206 ,
V_207 , & V_2 -> V_199 . V_206 ,
V_208 ,
sizeof( V_7 -> V_199 . V_206 ) ) ||
F_96 ( V_23 , V_7 -> V_199 . V_209 , V_210 ,
V_2 -> V_199 . V_209 , V_211 ,
sizeof( V_7 -> V_199 . V_209 ) ) ||
F_96 ( V_23 , V_7 -> V_199 . V_212 , V_213 ,
V_2 -> V_199 . V_212 , V_214 ,
sizeof( V_7 -> V_199 . V_212 ) ) ) )
goto V_292;
if ( V_7 -> V_37 . V_38 == V_39 &&
( F_96 ( V_23 , & V_7 -> V_40 . V_41 ,
V_215 , & V_2 -> V_40 . V_41 ,
V_217 ,
sizeof( V_7 -> V_40 . V_41 ) ) ||
F_96 ( V_23 , & V_7 -> V_40 . V_44 ,
V_216 , & V_2 -> V_40 . V_44 ,
V_218 ,
sizeof( V_7 -> V_40 . V_44 ) ) ) )
goto V_292;
else if ( V_7 -> V_37 . V_38 == V_46 &&
( F_96 ( V_23 , & V_7 -> V_47 . V_41 ,
V_219 , & V_2 -> V_47 . V_41 ,
V_221 ,
sizeof( V_7 -> V_47 . V_41 ) ) ||
F_96 ( V_23 , & V_7 -> V_47 . V_44 ,
V_220 ,
& V_2 -> V_47 . V_44 ,
V_222 ,
sizeof( V_7 -> V_47 . V_44 ) ) ) )
goto V_292;
if ( F_96 ( V_23 , & V_7 -> V_49 , V_223 ,
& V_2 -> V_49 , V_105 ,
sizeof( V_7 -> V_49 ) ) ||
F_96 ( V_23 , & V_7 -> V_52 . V_41 ,
V_224 ,
& V_2 -> V_52 . V_41 ,
V_225 ,
sizeof( V_7 -> V_52 . V_41 ) ) ||
F_96 ( V_23 , & V_7 -> V_52 . V_44 ,
V_226 ,
& V_2 -> V_52 . V_44 ,
V_227 ,
sizeof( V_7 -> V_52 . V_44 ) ) )
goto V_292;
if ( F_105 ( V_23 , V_7 -> V_160 . V_61 , V_2 -> V_160 . V_61 ) )
goto V_292;
if ( V_29 -> V_61 && F_101 ( V_23 , V_271 , V_29 -> V_61 ) )
goto V_292;
if ( F_111 ( V_23 , & V_29 -> V_62 ) )
goto V_292;
F_112 ( V_23 , V_290 ) ;
if ( F_113 ( V_23 , & V_29 -> V_62 ) < 0 )
goto V_292;
return V_23 -> V_104 ;
V_292:
F_114 ( V_23 , V_290 ) ;
return - 1 ;
}
static int T_6 F_115 ( void )
{
return F_116 ( & V_294 ) ;
}
static void T_7 F_117 ( void )
{
F_118 ( & V_294 ) ;
}
