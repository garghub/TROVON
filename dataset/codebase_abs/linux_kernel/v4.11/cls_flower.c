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
static bool F_43 ( struct V_24 * V_25 , bool V_98 )
{
struct V_18 * V_19 = F_44 ( V_25 -> V_28 ) ;
struct V_17 * V_29 , * V_99 ;
if ( ! V_98 && ! F_45 ( & V_19 -> V_65 ) )
return false ;
F_46 (f, next, &head->filters, list)
F_32 ( V_25 , V_29 ) ;
F_47 ( V_97 ) ;
F_36 ( & V_19 -> V_67 , F_40 ) ;
return true ;
}
static unsigned long F_48 ( struct V_24 * V_25 , T_3 V_84 )
{
struct V_18 * V_19 = F_44 ( V_25 -> V_28 ) ;
struct V_17 * V_29 ;
F_49 (f, &head->filters, list)
if ( V_29 -> V_84 == V_84 )
return ( unsigned long ) V_29 ;
return 0 ;
}
static void F_50 ( struct V_100 * * V_101 ,
void * V_102 , int V_103 ,
void * V_2 , int V_104 , int V_105 )
{
if ( ! V_101 [ V_103 ] )
return;
memcpy ( V_102 , F_51 ( V_101 [ V_103 ] ) , V_105 ) ;
if ( V_104 == V_106 || ! V_101 [ V_104 ] )
memset ( V_2 , 0xff , V_105 ) ;
else
memcpy ( V_2 , F_51 ( V_101 [ V_104 ] ) , V_105 ) ;
}
static void F_52 ( struct V_100 * * V_101 ,
struct V_107 * V_108 ,
struct V_107 * V_109 )
{
#define F_53 0x7
if ( V_101 [ V_110 ] ) {
V_108 -> V_111 =
F_54 ( V_101 [ V_110 ] ) & V_112 ;
V_109 -> V_111 = V_112 ;
}
if ( V_101 [ V_113 ] ) {
V_108 -> V_114 =
F_55 ( V_101 [ V_113 ] ) &
F_53 ;
V_109 -> V_114 = F_53 ;
}
}
static void F_56 ( T_3 V_115 , T_3 V_116 ,
T_3 * V_117 , T_3 * V_118 ,
T_3 V_119 , T_3 V_120 )
{
if ( V_116 & V_119 ) {
* V_118 |= V_120 ;
if ( V_115 & V_119 )
* V_117 |= V_120 ;
}
}
static int F_57 ( struct V_100 * * V_101 ,
T_3 * V_121 , T_3 * V_122 )
{
T_3 V_7 , V_2 ;
if ( ! V_101 [ V_123 ] )
return - V_88 ;
V_7 = F_58 ( F_59 ( V_101 [ V_124 ] ) ) ;
V_2 = F_58 ( F_59 ( V_101 [ V_123 ] ) ) ;
* V_121 = 0 ;
* V_122 = 0 ;
F_56 ( V_7 , V_2 , V_121 , V_122 ,
V_125 , V_126 ) ;
return 0 ;
}
static int F_60 ( struct V_127 * V_127 , struct V_100 * * V_101 ,
struct V_12 * V_7 , struct V_12 * V_2 )
{
T_4 V_128 ;
int V_129 = 0 ;
#ifdef F_61
if ( V_101 [ V_130 ] ) {
int V_87 = F_62 ( V_127 , V_101 [ V_130 ] ) ;
if ( V_87 < 0 )
return V_87 ;
V_7 -> V_55 = V_87 ;
V_2 -> V_55 = 0xffffffff ;
}
#endif
F_50 ( V_101 , V_7 -> V_131 . V_44 , V_132 ,
V_2 -> V_131 . V_44 , V_133 ,
sizeof( V_7 -> V_131 . V_44 ) ) ;
F_50 ( V_101 , V_7 -> V_131 . V_41 , V_134 ,
V_2 -> V_131 . V_41 , V_135 ,
sizeof( V_7 -> V_131 . V_41 ) ) ;
if ( V_101 [ V_136 ] ) {
V_128 = F_63 ( V_101 [ V_136 ] ) ;
if ( V_128 == F_64 ( V_137 ) ) {
F_52 ( V_101 , & V_7 -> V_138 , & V_2 -> V_138 ) ;
F_50 ( V_101 , & V_7 -> V_57 . V_58 ,
V_139 ,
& V_2 -> V_57 . V_58 , V_106 ,
sizeof( V_7 -> V_57 . V_58 ) ) ;
} else {
V_7 -> V_57 . V_58 = V_128 ;
V_2 -> V_57 . V_58 = F_65 ( ~ 0 ) ;
}
}
if ( V_7 -> V_57 . V_58 == F_64 ( V_140 ) ||
V_7 -> V_57 . V_58 == F_64 ( V_141 ) ) {
F_50 ( V_101 , & V_7 -> V_57 . V_142 , V_143 ,
& V_2 -> V_57 . V_142 , V_106 ,
sizeof( V_7 -> V_57 . V_142 ) ) ;
}
if ( V_101 [ V_144 ] || V_101 [ V_145 ] ) {
V_7 -> V_146 . V_38 = V_39 ;
V_2 -> V_146 . V_38 = ~ 0 ;
F_50 ( V_101 , & V_7 -> V_43 . V_41 , V_144 ,
& V_2 -> V_43 . V_41 , V_147 ,
sizeof( V_7 -> V_43 . V_41 ) ) ;
F_50 ( V_101 , & V_7 -> V_43 . V_44 , V_145 ,
& V_2 -> V_43 . V_44 , V_148 ,
sizeof( V_7 -> V_43 . V_44 ) ) ;
} else if ( V_101 [ V_149 ] || V_101 [ V_150 ] ) {
V_7 -> V_146 . V_38 = V_46 ;
V_2 -> V_146 . V_38 = ~ 0 ;
F_50 ( V_101 , & V_7 -> V_48 . V_41 , V_149 ,
& V_2 -> V_48 . V_41 , V_151 ,
sizeof( V_7 -> V_48 . V_41 ) ) ;
F_50 ( V_101 , & V_7 -> V_48 . V_44 , V_150 ,
& V_2 -> V_48 . V_44 , V_152 ,
sizeof( V_7 -> V_48 . V_44 ) ) ;
}
if ( V_7 -> V_57 . V_142 == V_153 ) {
F_50 ( V_101 , & V_7 -> V_25 . V_41 , V_154 ,
& V_2 -> V_25 . V_41 , V_155 ,
sizeof( V_7 -> V_25 . V_41 ) ) ;
F_50 ( V_101 , & V_7 -> V_25 . V_44 , V_156 ,
& V_2 -> V_25 . V_44 , V_157 ,
sizeof( V_7 -> V_25 . V_44 ) ) ;
} else if ( V_7 -> V_57 . V_142 == V_158 ) {
F_50 ( V_101 , & V_7 -> V_25 . V_41 , V_159 ,
& V_2 -> V_25 . V_41 , V_160 ,
sizeof( V_7 -> V_25 . V_41 ) ) ;
F_50 ( V_101 , & V_7 -> V_25 . V_44 , V_161 ,
& V_2 -> V_25 . V_44 , V_162 ,
sizeof( V_7 -> V_25 . V_44 ) ) ;
} else if ( V_7 -> V_57 . V_142 == V_163 ) {
F_50 ( V_101 , & V_7 -> V_25 . V_41 , V_164 ,
& V_2 -> V_25 . V_41 , V_165 ,
sizeof( V_7 -> V_25 . V_41 ) ) ;
F_50 ( V_101 , & V_7 -> V_25 . V_44 , V_166 ,
& V_2 -> V_25 . V_44 , V_167 ,
sizeof( V_7 -> V_25 . V_44 ) ) ;
} else if ( V_7 -> V_57 . V_58 == F_64 ( V_140 ) &&
V_7 -> V_57 . V_142 == V_168 ) {
F_50 ( V_101 , & V_7 -> V_169 . type , V_170 ,
& V_2 -> V_169 . type ,
V_171 ,
sizeof( V_7 -> V_169 . type ) ) ;
F_50 ( V_101 , & V_7 -> V_169 . V_172 , V_173 ,
& V_2 -> V_169 . V_172 ,
V_174 ,
sizeof( V_7 -> V_169 . V_172 ) ) ;
} else if ( V_7 -> V_57 . V_58 == F_64 ( V_141 ) &&
V_7 -> V_57 . V_142 == V_175 ) {
F_50 ( V_101 , & V_7 -> V_169 . type , V_176 ,
& V_2 -> V_169 . type ,
V_177 ,
sizeof( V_7 -> V_169 . type ) ) ;
F_50 ( V_101 , & V_7 -> V_169 . V_172 , V_178 ,
& V_2 -> V_169 . V_172 ,
V_179 ,
sizeof( V_7 -> V_169 . V_172 ) ) ;
} else if ( V_7 -> V_57 . V_58 == F_64 ( V_180 ) ||
V_7 -> V_57 . V_58 == F_64 ( V_181 ) ) {
F_50 ( V_101 , & V_7 -> V_182 . V_183 , V_184 ,
& V_2 -> V_182 . V_183 , V_185 ,
sizeof( V_7 -> V_182 . V_183 ) ) ;
F_50 ( V_101 , & V_7 -> V_182 . V_186 , V_187 ,
& V_2 -> V_182 . V_186 , V_188 ,
sizeof( V_7 -> V_182 . V_186 ) ) ;
F_50 ( V_101 , & V_7 -> V_182 . V_189 , V_190 ,
& V_2 -> V_182 . V_189 , V_191 ,
sizeof( V_7 -> V_182 . V_189 ) ) ;
F_50 ( V_101 , V_7 -> V_182 . V_192 , V_193 ,
V_2 -> V_182 . V_192 , V_194 ,
sizeof( V_7 -> V_182 . V_192 ) ) ;
F_50 ( V_101 , V_7 -> V_182 . V_195 , V_196 ,
V_2 -> V_182 . V_195 , V_197 ,
sizeof( V_7 -> V_182 . V_195 ) ) ;
}
if ( V_101 [ V_198 ] ||
V_101 [ V_199 ] ) {
V_7 -> V_37 . V_38 = V_39 ;
V_2 -> V_37 . V_38 = ~ 0 ;
F_50 ( V_101 , & V_7 -> V_40 . V_41 ,
V_198 ,
& V_2 -> V_40 . V_41 ,
V_200 ,
sizeof( V_7 -> V_40 . V_41 ) ) ;
F_50 ( V_101 , & V_7 -> V_40 . V_44 ,
V_199 ,
& V_2 -> V_40 . V_44 ,
V_201 ,
sizeof( V_7 -> V_40 . V_44 ) ) ;
}
if ( V_101 [ V_202 ] ||
V_101 [ V_203 ] ) {
V_7 -> V_37 . V_38 = V_46 ;
V_2 -> V_37 . V_38 = ~ 0 ;
F_50 ( V_101 , & V_7 -> V_47 . V_41 ,
V_202 ,
& V_2 -> V_47 . V_41 ,
V_204 ,
sizeof( V_7 -> V_47 . V_41 ) ) ;
F_50 ( V_101 , & V_7 -> V_47 . V_44 ,
V_203 ,
& V_2 -> V_47 . V_44 ,
V_205 ,
sizeof( V_7 -> V_47 . V_44 ) ) ;
}
F_50 ( V_101 , & V_7 -> V_49 . V_50 , V_206 ,
& V_2 -> V_49 . V_50 , V_106 ,
sizeof( V_7 -> V_49 . V_50 ) ) ;
F_50 ( V_101 , & V_7 -> V_52 . V_41 , V_207 ,
& V_2 -> V_52 . V_41 , V_208 ,
sizeof( V_7 -> V_52 . V_41 ) ) ;
F_50 ( V_101 , & V_7 -> V_52 . V_44 , V_209 ,
& V_2 -> V_52 . V_44 , V_210 ,
sizeof( V_7 -> V_52 . V_44 ) ) ;
if ( V_101 [ V_124 ] )
V_129 = F_57 ( V_101 , & V_7 -> V_146 . V_61 , & V_2 -> V_146 . V_61 ) ;
return V_129 ;
}
static bool F_66 ( struct V_1 * V_211 ,
struct V_1 * V_212 )
{
const long * V_213 = F_5 ( & V_211 -> V_7 , V_211 ) ;
const long * V_214 = F_5 ( & V_212 -> V_7 , V_212 ) ;
return ! memcmp ( & V_211 -> V_3 , & V_212 -> V_3 , sizeof( V_211 -> V_3 ) ) &&
! memcmp ( V_213 , V_214 , F_1 ( V_211 ) ) ;
}
static int F_67 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
V_19 -> V_21 = V_215 ;
V_19 -> V_21 . V_216 = F_1 ( V_2 ) ;
V_19 -> V_21 . V_217 += V_2 -> V_3 . V_5 ;
return F_68 ( & V_19 -> V_20 , & V_19 -> V_21 ) ;
}
static void F_69 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
struct V_218 V_219 [ V_220 ] ;
T_2 V_221 = 0 ;
F_70 ( V_219 , V_221 , V_222 , V_146 ) ;
F_70 ( V_219 , V_221 , V_223 , V_57 ) ;
F_71 ( & V_2 -> V_7 , V_219 , V_221 ,
V_224 , V_131 ) ;
F_71 ( & V_2 -> V_7 , V_219 , V_221 ,
V_39 , V_43 ) ;
F_71 ( & V_2 -> V_7 , V_219 , V_221 ,
V_46 , V_48 ) ;
F_71 ( & V_2 -> V_7 , V_219 , V_221 ,
V_225 , V_25 ) ;
F_71 ( & V_2 -> V_7 , V_219 , V_221 ,
V_226 , V_169 ) ;
F_71 ( & V_2 -> V_7 , V_219 , V_221 ,
V_227 , V_182 ) ;
F_71 ( & V_2 -> V_7 , V_219 , V_221 ,
V_228 , V_138 ) ;
F_71 ( & V_2 -> V_7 , V_219 , V_221 ,
V_229 , V_49 ) ;
F_71 ( & V_2 -> V_7 , V_219 , V_221 ,
V_230 , V_40 ) ;
F_71 ( & V_2 -> V_7 , V_219 , V_221 ,
V_231 , V_47 ) ;
if ( F_72 ( & V_2 -> V_7 , V_40 ) ||
F_72 ( & V_2 -> V_7 , V_47 ) )
F_70 ( V_219 , V_221 , V_232 ,
V_37 ) ;
F_71 ( & V_2 -> V_7 , V_219 , V_221 ,
V_233 , V_52 ) ;
F_73 ( & V_19 -> V_60 , V_219 , V_221 ) ;
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
static int F_75 ( struct V_127 * V_127 , struct V_24 * V_25 ,
struct V_17 * V_29 , struct V_1 * V_2 ,
unsigned long V_234 , struct V_100 * * V_101 ,
struct V_100 * V_235 , bool V_236 )
{
struct V_237 V_238 ;
int V_87 ;
V_87 = F_76 ( & V_238 , V_239 , 0 ) ;
if ( V_87 < 0 )
return V_87 ;
V_87 = F_77 ( V_127 , V_25 , V_101 , V_235 , & V_238 , V_236 ) ;
if ( V_87 < 0 )
goto V_240;
if ( V_101 [ V_241 ] ) {
V_29 -> V_27 . V_242 = F_59 ( V_101 [ V_241 ] ) ;
F_78 ( V_25 , & V_29 -> V_27 , V_234 ) ;
}
V_87 = F_60 ( V_127 , V_101 , & V_29 -> V_7 , & V_2 -> V_7 ) ;
if ( V_87 )
goto V_240;
F_2 ( V_2 ) ;
F_6 ( & V_29 -> V_13 , & V_29 -> V_7 , V_2 ) ;
F_79 ( V_25 , & V_29 -> V_62 , & V_238 ) ;
return 0 ;
V_240:
F_25 ( & V_238 ) ;
return V_87 ;
}
static T_3 F_80 ( struct V_24 * V_25 ,
struct V_18 * V_19 )
{
unsigned int V_9 = 0x80000000 ;
T_3 V_84 ;
do {
if ( ++ V_19 -> V_243 == 0x7FFFFFFF )
V_19 -> V_243 = 1 ;
} while ( -- V_9 > 0 && F_48 ( V_25 , V_19 -> V_243 ) );
if ( F_81 ( V_9 == 0 ) ) {
F_82 ( L_1 ) ;
V_84 = 0 ;
} else {
V_84 = V_19 -> V_243 ;
}
return V_84 ;
}
static int F_83 ( struct V_127 * V_127 , struct V_22 * V_244 ,
struct V_24 * V_25 , unsigned long V_234 ,
T_3 V_84 , struct V_100 * * V_245 ,
unsigned long * V_246 , bool V_236 )
{
struct V_18 * V_19 = F_44 ( V_25 -> V_28 ) ;
struct V_17 * V_247 = (struct V_17 * ) * V_246 ;
struct V_17 * V_248 ;
struct V_100 * * V_101 ;
struct V_1 V_2 = {} ;
int V_87 ;
if ( ! V_245 [ V_249 ] )
return - V_88 ;
V_101 = F_84 ( V_250 + 1 , sizeof( struct V_100 * ) , V_63 ) ;
if ( ! V_101 )
return - V_64 ;
V_87 = F_85 ( V_101 , V_250 , V_245 [ V_249 ] , V_251 ) ;
if ( V_87 < 0 )
goto V_252;
if ( V_247 && V_84 && V_247 -> V_84 != V_84 ) {
V_87 = - V_88 ;
goto V_252;
}
V_248 = F_20 ( sizeof( * V_248 ) , V_63 ) ;
if ( ! V_248 ) {
V_87 = - V_64 ;
goto V_252;
}
V_87 = F_76 ( & V_248 -> V_62 , V_239 , 0 ) ;
if ( V_87 < 0 )
goto V_240;
if ( ! V_84 ) {
V_84 = F_80 ( V_25 , V_19 ) ;
if ( ! V_84 ) {
V_87 = - V_88 ;
goto V_240;
}
}
V_248 -> V_84 = V_84 ;
if ( V_101 [ V_253 ] ) {
V_248 -> V_61 = F_59 ( V_101 [ V_253 ] ) ;
if ( ! F_86 ( V_248 -> V_61 ) ) {
V_87 = - V_88 ;
goto V_240;
}
}
V_87 = F_75 ( V_127 , V_25 , V_248 , & V_2 , V_234 , V_101 , V_245 [ V_254 ] , V_236 ) ;
if ( V_87 )
goto V_240;
V_87 = F_74 ( V_19 , & V_2 ) ;
if ( V_87 )
goto V_240;
if ( ! F_17 ( V_248 -> V_61 ) ) {
if ( ! V_247 && F_8 ( V_19 , & V_248 -> V_13 ) ) {
V_87 = - V_255 ;
goto V_240;
}
V_87 = F_87 ( & V_19 -> V_20 , & V_248 -> V_256 ,
V_19 -> V_21 ) ;
if ( V_87 )
goto V_240;
}
if ( ! F_34 ( V_248 -> V_61 ) ) {
V_87 = F_29 ( V_25 ,
& V_19 -> V_60 ,
& V_2 . V_7 ,
V_248 ) ;
if ( V_87 )
goto V_240;
}
if ( ! F_88 ( V_248 -> V_61 ) )
V_248 -> V_61 |= V_257 ;
if ( V_247 ) {
if ( ! F_17 ( V_247 -> V_61 ) )
F_89 ( & V_19 -> V_20 , & V_247 -> V_256 ,
V_19 -> V_21 ) ;
if ( ! F_34 ( V_247 -> V_61 ) )
F_27 ( V_25 , V_247 ) ;
}
* V_246 = ( unsigned long ) V_248 ;
if ( V_247 ) {
F_90 ( & V_247 -> V_93 , & V_248 -> V_93 ) ;
F_35 ( V_25 , & V_247 -> V_27 ) ;
F_36 ( & V_247 -> V_67 , F_23 ) ;
} else {
F_91 ( & V_248 -> V_93 , & V_19 -> V_65 ) ;
}
F_26 ( V_101 ) ;
return 0 ;
V_240:
F_25 ( & V_248 -> V_62 ) ;
F_26 ( V_248 ) ;
V_252:
F_26 ( V_101 ) ;
return V_87 ;
}
static int F_92 ( struct V_24 * V_25 , unsigned long V_246 )
{
struct V_18 * V_19 = F_44 ( V_25 -> V_28 ) ;
struct V_17 * V_29 = (struct V_17 * ) V_246 ;
if ( ! F_17 ( V_29 -> V_61 ) )
F_89 ( & V_19 -> V_20 , & V_29 -> V_256 ,
V_19 -> V_21 ) ;
F_32 ( V_25 , V_29 ) ;
return 0 ;
}
static void F_93 ( struct V_24 * V_25 , struct V_258 * V_246 )
{
struct V_18 * V_19 = F_44 ( V_25 -> V_28 ) ;
struct V_17 * V_29 ;
F_94 (f, &head->filters, list) {
if ( V_246 -> V_259 < V_246 -> V_260 )
goto V_260;
if ( V_246 -> V_261 ( V_25 , ( unsigned long ) V_29 , V_246 ) < 0 ) {
V_246 -> V_262 = 1 ;
break;
}
V_260:
V_246 -> V_259 ++ ;
}
}
static int F_95 ( struct V_22 * V_23 ,
void * V_102 , int V_103 ,
void * V_2 , int V_104 , int V_105 )
{
int V_87 ;
if ( ! F_96 ( V_2 , 0 , V_105 ) )
return 0 ;
V_87 = F_97 ( V_23 , V_103 , V_105 , V_102 ) ;
if ( V_87 )
return V_87 ;
if ( V_104 != V_106 ) {
V_87 = F_97 ( V_23 , V_104 , V_105 , V_2 ) ;
if ( V_87 )
return V_87 ;
}
return 0 ;
}
static int F_98 ( struct V_22 * V_23 ,
struct V_107 * V_263 ,
struct V_107 * V_264 )
{
int V_87 ;
if ( ! F_96 ( V_264 , 0 , sizeof( * V_264 ) ) )
return 0 ;
if ( V_264 -> V_111 ) {
V_87 = F_99 ( V_23 , V_110 ,
V_263 -> V_111 ) ;
if ( V_87 )
return V_87 ;
}
if ( V_264 -> V_114 ) {
V_87 = F_100 ( V_23 , V_113 ,
V_263 -> V_114 ) ;
if ( V_87 )
return V_87 ;
}
return 0 ;
}
static void F_101 ( T_3 V_117 , T_3 V_118 ,
T_3 * V_115 , T_3 * V_116 ,
T_3 V_119 , T_3 V_120 )
{
if ( V_118 & V_120 ) {
* V_116 |= V_119 ;
if ( V_117 & V_120 )
* V_115 |= V_119 ;
}
}
static int F_102 ( struct V_22 * V_23 , T_3 V_121 , T_3 V_122 )
{
T_3 V_7 , V_2 ;
T_5 V_265 , V_266 ;
int V_87 ;
if ( ! F_96 ( & V_122 , 0 , sizeof( V_122 ) ) )
return 0 ;
V_7 = 0 ;
V_2 = 0 ;
F_101 ( V_121 , V_122 , & V_7 , & V_2 ,
V_125 , V_126 ) ;
V_265 = F_103 ( V_7 ) ;
V_266 = F_103 ( V_2 ) ;
V_87 = F_97 ( V_23 , V_124 , 4 , & V_265 ) ;
if ( V_87 )
return V_87 ;
return F_97 ( V_23 , V_123 , 4 , & V_266 ) ;
}
static int F_104 ( struct V_127 * V_127 , struct V_24 * V_25 , unsigned long V_267 ,
struct V_22 * V_23 , struct V_268 * V_269 )
{
struct V_18 * V_19 = F_44 ( V_25 -> V_28 ) ;
struct V_17 * V_29 = (struct V_17 * ) V_267 ;
struct V_100 * V_270 ;
struct V_12 * V_7 , * V_2 ;
if ( ! V_29 )
return V_23 -> V_105 ;
V_269 -> V_271 = V_29 -> V_84 ;
V_270 = F_105 ( V_23 , V_249 ) ;
if ( ! V_270 )
goto V_272;
if ( V_29 -> V_27 . V_242 &&
F_106 ( V_23 , V_241 , V_29 -> V_27 . V_242 ) )
goto V_272;
V_7 = & V_29 -> V_7 ;
V_2 = & V_19 -> V_2 . V_7 ;
if ( V_2 -> V_55 ) {
struct V_70 * V_71 ;
V_71 = F_107 ( V_127 , V_7 -> V_55 ) ;
if ( V_71 && F_108 ( V_23 , V_130 , V_71 -> V_273 ) )
goto V_272;
}
if ( ! F_34 ( V_29 -> V_61 ) )
F_31 ( V_25 , V_29 ) ;
if ( F_95 ( V_23 , V_7 -> V_131 . V_44 , V_132 ,
V_2 -> V_131 . V_44 , V_133 ,
sizeof( V_7 -> V_131 . V_44 ) ) ||
F_95 ( V_23 , V_7 -> V_131 . V_41 , V_134 ,
V_2 -> V_131 . V_41 , V_135 ,
sizeof( V_7 -> V_131 . V_41 ) ) ||
F_95 ( V_23 , & V_7 -> V_57 . V_58 , V_136 ,
& V_2 -> V_57 . V_58 , V_106 ,
sizeof( V_7 -> V_57 . V_58 ) ) )
goto V_272;
if ( F_98 ( V_23 , & V_7 -> V_138 , & V_2 -> V_138 ) )
goto V_272;
if ( ( V_7 -> V_57 . V_58 == F_64 ( V_140 ) ||
V_7 -> V_57 . V_58 == F_64 ( V_141 ) ) &&
F_95 ( V_23 , & V_7 -> V_57 . V_142 , V_143 ,
& V_2 -> V_57 . V_142 , V_106 ,
sizeof( V_7 -> V_57 . V_142 ) ) )
goto V_272;
if ( V_7 -> V_146 . V_38 == V_39 &&
( F_95 ( V_23 , & V_7 -> V_43 . V_41 , V_144 ,
& V_2 -> V_43 . V_41 , V_147 ,
sizeof( V_7 -> V_43 . V_41 ) ) ||
F_95 ( V_23 , & V_7 -> V_43 . V_44 , V_145 ,
& V_2 -> V_43 . V_44 , V_148 ,
sizeof( V_7 -> V_43 . V_44 ) ) ) )
goto V_272;
else if ( V_7 -> V_146 . V_38 == V_46 &&
( F_95 ( V_23 , & V_7 -> V_48 . V_41 , V_149 ,
& V_2 -> V_48 . V_41 , V_151 ,
sizeof( V_7 -> V_48 . V_41 ) ) ||
F_95 ( V_23 , & V_7 -> V_48 . V_44 , V_150 ,
& V_2 -> V_48 . V_44 , V_152 ,
sizeof( V_7 -> V_48 . V_44 ) ) ) )
goto V_272;
if ( V_7 -> V_57 . V_142 == V_153 &&
( F_95 ( V_23 , & V_7 -> V_25 . V_41 , V_154 ,
& V_2 -> V_25 . V_41 , V_155 ,
sizeof( V_7 -> V_25 . V_41 ) ) ||
F_95 ( V_23 , & V_7 -> V_25 . V_44 , V_156 ,
& V_2 -> V_25 . V_44 , V_157 ,
sizeof( V_7 -> V_25 . V_44 ) ) ) )
goto V_272;
else if ( V_7 -> V_57 . V_142 == V_158 &&
( F_95 ( V_23 , & V_7 -> V_25 . V_41 , V_159 ,
& V_2 -> V_25 . V_41 , V_160 ,
sizeof( V_7 -> V_25 . V_41 ) ) ||
F_95 ( V_23 , & V_7 -> V_25 . V_44 , V_161 ,
& V_2 -> V_25 . V_44 , V_162 ,
sizeof( V_7 -> V_25 . V_44 ) ) ) )
goto V_272;
else if ( V_7 -> V_57 . V_142 == V_163 &&
( F_95 ( V_23 , & V_7 -> V_25 . V_41 , V_164 ,
& V_2 -> V_25 . V_41 , V_165 ,
sizeof( V_7 -> V_25 . V_41 ) ) ||
F_95 ( V_23 , & V_7 -> V_25 . V_44 , V_166 ,
& V_2 -> V_25 . V_44 , V_167 ,
sizeof( V_7 -> V_25 . V_44 ) ) ) )
goto V_272;
else if ( V_7 -> V_57 . V_58 == F_64 ( V_140 ) &&
V_7 -> V_57 . V_142 == V_168 &&
( F_95 ( V_23 , & V_7 -> V_169 . type ,
V_170 , & V_2 -> V_169 . type ,
V_171 ,
sizeof( V_7 -> V_169 . type ) ) ||
F_95 ( V_23 , & V_7 -> V_169 . V_172 ,
V_173 , & V_2 -> V_169 . V_172 ,
V_174 ,
sizeof( V_7 -> V_169 . V_172 ) ) ) )
goto V_272;
else if ( V_7 -> V_57 . V_58 == F_64 ( V_141 ) &&
V_7 -> V_57 . V_142 == V_175 &&
( F_95 ( V_23 , & V_7 -> V_169 . type ,
V_176 , & V_2 -> V_169 . type ,
V_177 ,
sizeof( V_7 -> V_169 . type ) ) ||
F_95 ( V_23 , & V_7 -> V_169 . V_172 ,
V_178 , & V_2 -> V_169 . V_172 ,
V_179 ,
sizeof( V_7 -> V_169 . V_172 ) ) ) )
goto V_272;
else if ( ( V_7 -> V_57 . V_58 == F_64 ( V_180 ) ||
V_7 -> V_57 . V_58 == F_64 ( V_181 ) ) &&
( F_95 ( V_23 , & V_7 -> V_182 . V_183 ,
V_184 , & V_2 -> V_182 . V_183 ,
V_185 ,
sizeof( V_7 -> V_182 . V_183 ) ) ||
F_95 ( V_23 , & V_7 -> V_182 . V_186 ,
V_187 , & V_2 -> V_182 . V_186 ,
V_188 ,
sizeof( V_7 -> V_182 . V_186 ) ) ||
F_95 ( V_23 , & V_7 -> V_182 . V_189 ,
V_190 , & V_2 -> V_182 . V_189 ,
V_191 ,
sizeof( V_7 -> V_182 . V_189 ) ) ||
F_95 ( V_23 , V_7 -> V_182 . V_192 , V_193 ,
V_2 -> V_182 . V_192 , V_194 ,
sizeof( V_7 -> V_182 . V_192 ) ) ||
F_95 ( V_23 , V_7 -> V_182 . V_195 , V_196 ,
V_2 -> V_182 . V_195 , V_197 ,
sizeof( V_7 -> V_182 . V_195 ) ) ) )
goto V_272;
if ( V_7 -> V_37 . V_38 == V_39 &&
( F_95 ( V_23 , & V_7 -> V_40 . V_41 ,
V_198 , & V_2 -> V_40 . V_41 ,
V_200 ,
sizeof( V_7 -> V_40 . V_41 ) ) ||
F_95 ( V_23 , & V_7 -> V_40 . V_44 ,
V_199 , & V_2 -> V_40 . V_44 ,
V_201 ,
sizeof( V_7 -> V_40 . V_44 ) ) ) )
goto V_272;
else if ( V_7 -> V_37 . V_38 == V_46 &&
( F_95 ( V_23 , & V_7 -> V_47 . V_41 ,
V_202 , & V_2 -> V_47 . V_41 ,
V_204 ,
sizeof( V_7 -> V_47 . V_41 ) ) ||
F_95 ( V_23 , & V_7 -> V_47 . V_44 ,
V_203 ,
& V_2 -> V_47 . V_44 ,
V_205 ,
sizeof( V_7 -> V_47 . V_44 ) ) ) )
goto V_272;
if ( F_95 ( V_23 , & V_7 -> V_49 , V_206 ,
& V_2 -> V_49 , V_106 ,
sizeof( V_7 -> V_49 ) ) ||
F_95 ( V_23 , & V_7 -> V_52 . V_41 ,
V_207 ,
& V_2 -> V_52 . V_41 ,
V_208 ,
sizeof( V_7 -> V_52 . V_41 ) ) ||
F_95 ( V_23 , & V_7 -> V_52 . V_44 ,
V_209 ,
& V_2 -> V_52 . V_44 ,
V_210 ,
sizeof( V_7 -> V_52 . V_44 ) ) )
goto V_272;
if ( F_102 ( V_23 , V_7 -> V_146 . V_61 , V_2 -> V_146 . V_61 ) )
goto V_272;
if ( V_29 -> V_61 && F_106 ( V_23 , V_253 , V_29 -> V_61 ) )
goto V_272;
if ( F_109 ( V_23 , & V_29 -> V_62 ) )
goto V_272;
F_110 ( V_23 , V_270 ) ;
if ( F_111 ( V_23 , & V_29 -> V_62 ) < 0 )
goto V_272;
return V_23 -> V_105 ;
V_272:
F_112 ( V_23 , V_270 ) ;
return - 1 ;
}
static int T_6 F_113 ( void )
{
return F_114 ( & V_274 ) ;
}
static void T_7 F_115 ( void )
{
F_116 ( & V_274 ) ;
}
