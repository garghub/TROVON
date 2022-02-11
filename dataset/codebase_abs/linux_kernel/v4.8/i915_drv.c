bool F_1 ( const char * V_1 , int line )
{
if ( V_2 >= V_3 . V_4 )
return false ;
if ( ++ V_2 == V_3 . V_4 ) {
F_2 ( L_1 ,
V_3 . V_4 , V_1 , line ) ;
return true ;
}
return false ;
}
void
F_3 ( struct V_5 * V_6 , const char * V_7 ,
const char * V_8 , ... )
{
static bool V_9 ;
struct V_10 * V_11 = V_6 -> V_12 . V_11 ;
bool V_13 = V_7 [ 1 ] <= V_14 [ 1 ] ;
bool V_15 = V_7 [ 1 ] == V_16 [ 1 ] ;
struct V_17 V_18 ;
T_1 args ;
if ( V_15 && ! ( V_19 & V_20 ) )
return;
va_start ( args , V_8 ) ;
V_18 . V_8 = V_8 ;
V_18 . V_21 = & args ;
F_4 ( V_7 , V_11 , L_2 V_22 L_3 ,
F_5 ( 0 ) , & V_18 ) ;
if ( V_13 && ! V_9 ) {
F_6 ( V_11 , L_4 , V_23 ) ;
V_9 = true ;
}
va_end ( args ) ;
}
static bool F_7 ( struct V_5 * V_6 )
{
return V_3 . V_4 &&
V_2 == V_3 . V_4 ;
}
static enum V_24 F_8 ( struct V_25 * V_11 )
{
enum V_24 V_26 = V_27 ;
if ( F_9 ( V_11 ) ) {
V_26 = V_28 ;
F_10 ( L_5 ) ;
} else if ( F_11 ( V_11 ) || F_12 ( V_11 ) ) {
V_26 = V_29 ;
F_10 ( L_6 ) ;
} else if ( F_13 ( V_11 ) || F_14 ( V_11 ) ) {
V_26 = V_30 ;
F_10 ( L_7 ) ;
} else if ( F_15 ( V_11 ) || F_16 ( V_11 ) ) {
V_26 = V_31 ;
F_10 ( L_8 ) ;
}
return V_26 ;
}
static void F_17 ( struct V_25 * V_11 )
{
struct V_5 * V_6 = F_18 ( V_11 ) ;
struct V_32 * V_33 = NULL ;
if ( F_19 ( V_11 ) -> V_34 == 0 ) {
V_6 -> V_35 = V_27 ;
return;
}
while ( ( V_33 = F_20 ( V_36 << 8 , V_33 ) ) ) {
if ( V_33 -> V_37 == V_38 ) {
unsigned short V_39 = V_33 -> V_10 & V_40 ;
V_6 -> V_41 = V_39 ;
if ( V_39 == V_42 ) {
V_6 -> V_35 = V_28 ;
F_10 ( L_9 ) ;
F_21 ( ! F_9 ( V_11 ) ) ;
} else if ( V_39 == V_43 ) {
V_6 -> V_35 = V_29 ;
F_10 ( L_10 ) ;
F_21 ( ! ( F_11 ( V_11 ) || F_12 ( V_11 ) ) ) ;
} else if ( V_39 == V_44 ) {
V_6 -> V_35 = V_29 ;
F_10 ( L_11 ) ;
F_21 ( ! ( F_11 ( V_11 ) || F_12 ( V_11 ) ) ) ;
} else if ( V_39 == V_45 ) {
V_6 -> V_35 = V_30 ;
F_10 ( L_12 ) ;
F_21 ( ! F_13 ( V_11 ) && ! F_14 ( V_11 ) ) ;
F_21 ( F_22 ( V_11 ) || F_23 ( V_11 ) ) ;
} else if ( V_39 == V_46 ) {
V_6 -> V_35 = V_30 ;
F_10 ( L_13 ) ;
F_21 ( ! F_13 ( V_11 ) && ! F_14 ( V_11 ) ) ;
F_21 ( ! F_22 ( V_11 ) && ! F_23 ( V_11 ) ) ;
} else if ( V_39 == V_47 ) {
V_6 -> V_35 = V_31 ;
F_10 ( L_14 ) ;
F_21 ( ! F_15 ( V_11 ) &&
! F_16 ( V_11 ) ) ;
} else if ( V_39 == V_48 ) {
V_6 -> V_35 = V_31 ;
F_10 ( L_15 ) ;
F_21 ( ! F_15 ( V_11 ) &&
! F_16 ( V_11 ) ) ;
} else if ( V_39 == V_49 ) {
V_6 -> V_35 = V_50 ;
F_10 ( L_16 ) ;
F_21 ( ! F_16 ( V_11 ) ) ;
} else if ( ( V_39 == V_51 ) ||
( V_39 == V_52 ) ||
( ( V_39 == V_53 ) &&
V_33 -> V_54 ==
V_55 &&
V_33 -> V_56 ==
V_57 ) ) {
V_6 -> V_35 = F_8 ( V_11 ) ;
} else
continue;
break;
}
}
if ( ! V_33 )
F_10 ( L_17 ) ;
F_24 ( V_33 ) ;
}
bool F_25 ( struct V_5 * V_6 )
{
if ( F_26 ( V_6 ) < 6 )
return false ;
if ( V_3 . V_58 >= 0 )
return V_3 . V_58 ;
if ( V_3 . V_59 )
return false ;
#ifdef F_27
if ( F_11 ( V_6 ) && V_60 )
return false ;
#endif
return true ;
}
static int F_28 ( struct V_25 * V_11 , void * V_61 ,
struct V_62 * V_63 )
{
struct V_5 * V_6 = F_18 ( V_11 ) ;
T_2 * V_64 = V_61 ;
int V_65 ;
switch ( V_64 -> V_64 ) {
case V_66 :
case V_67 :
case V_68 :
return - V_69 ;
case V_70 :
V_65 = V_11 -> V_71 -> V_10 ;
break;
case V_72 :
V_65 = V_11 -> V_71 -> V_73 ;
break;
case V_74 :
V_65 = 1 ;
break;
case V_75 :
V_65 = V_6 -> V_76 ;
break;
case V_77 :
V_65 = V_6 -> V_78 ? 1 : 0 ;
break;
case V_79 :
V_65 = 1 ;
break;
case V_80 :
V_65 = 1 ;
break;
case V_81 :
V_65 = F_29 ( & V_6 -> V_82 [ V_83 ] ) ;
break;
case V_84 :
V_65 = F_29 ( & V_6 -> V_82 [ V_85 ] ) ;
break;
case V_86 :
V_65 = F_29 ( & V_6 -> V_82 [ V_87 ] ) ;
break;
case V_88 :
V_65 = F_29 ( & V_6 -> V_82 [ V_89 ] ) ;
break;
case V_90 :
V_65 = 1 ;
break;
case V_91 :
V_65 = 1 ;
break;
case V_92 :
V_65 = F_19 ( V_11 ) -> V_93 >= 4 ;
break;
case V_94 :
V_65 = 1 ;
break;
case V_95 :
V_65 = 1 ;
break;
case V_96 :
V_65 = F_30 ( V_11 ) ;
break;
case V_97 :
V_65 = F_31 ( V_11 ) ;
break;
case V_98 :
V_65 = F_32 ( V_11 ) ;
break;
case V_99 :
V_65 = 1 ;
break;
case V_100 :
V_65 = F_25 ( V_6 ) ;
break;
case V_101 :
V_65 = 1 ;
break;
case V_102 :
V_65 = F_33 ( V_103 ) ;
break;
case V_104 :
V_65 = 1 ;
break;
case V_105 :
V_65 = 1 ;
break;
case V_106 :
V_65 = 1 ;
break;
case V_107 :
V_65 = F_34 ( V_6 ) ;
break;
case V_108 :
V_65 = 1 ;
break;
case V_109 :
V_65 = 1 ;
break;
case V_110 :
V_65 = F_19 ( V_11 ) -> V_111 ;
if ( ! V_65 )
return - V_69 ;
break;
case V_112 :
V_65 = F_19 ( V_11 ) -> V_113 ;
if ( ! V_65 )
return - V_69 ;
break;
case V_114 :
V_65 = V_3 . V_115 && F_35 ( V_6 ) ;
break;
case V_116 :
V_65 = F_36 ( V_11 ) ;
break;
case V_117 :
V_65 = 1 ;
break;
case V_118 :
V_65 = F_37 ( V_11 ) ;
break;
case V_119 :
V_65 = F_19 ( V_11 ) -> V_120 ;
break;
default:
F_38 ( L_18 , V_64 -> V_64 ) ;
return - V_121 ;
}
if ( F_39 ( V_65 , V_64 -> V_65 ) )
return - V_122 ;
return 0 ;
}
static int F_40 ( struct V_25 * V_11 )
{
struct V_5 * V_6 = F_18 ( V_11 ) ;
V_6 -> V_123 = F_41 ( 0 , F_42 ( 0 , 0 ) ) ;
if ( ! V_6 -> V_123 ) {
F_43 ( L_19 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_44 ( struct V_25 * V_11 )
{
struct V_5 * V_6 = F_18 ( V_11 ) ;
int V_124 = F_19 ( V_11 ) -> V_93 >= 4 ? V_125 : V_126 ;
T_3 V_127 , V_128 = 0 ;
T_4 V_129 ;
int V_26 ;
if ( F_19 ( V_11 ) -> V_93 >= 4 )
F_45 ( V_6 -> V_123 , V_124 + 4 , & V_128 ) ;
F_45 ( V_6 -> V_123 , V_124 , & V_127 ) ;
V_129 = ( ( T_4 ) V_128 << 32 ) | V_127 ;
#ifdef F_46
if ( V_129 &&
F_47 ( V_129 , V_129 + V_130 ) )
return 0 ;
#endif
V_6 -> V_131 . V_132 = L_20 ;
V_6 -> V_131 . V_133 = V_134 ;
V_26 = F_48 ( V_6 -> V_123 -> V_135 ,
& V_6 -> V_131 ,
V_130 , V_130 ,
V_136 ,
0 , V_137 ,
V_6 -> V_123 ) ;
if ( V_26 ) {
F_49 ( L_21 , V_26 ) ;
V_6 -> V_131 . V_138 = 0 ;
return V_26 ;
}
if ( F_19 ( V_11 ) -> V_93 >= 4 )
F_50 ( V_6 -> V_123 , V_124 + 4 ,
F_51 ( V_6 -> V_131 . V_138 ) ) ;
F_50 ( V_6 -> V_123 , V_124 ,
F_52 ( V_6 -> V_131 . V_138 ) ) ;
return 0 ;
}
static void
F_53 ( struct V_25 * V_11 )
{
struct V_5 * V_6 = F_18 ( V_11 ) ;
int V_139 = F_19 ( V_11 ) -> V_93 >= 4 ? V_125 : V_126 ;
T_3 V_140 ;
bool V_141 ;
if ( F_54 ( V_11 ) || F_55 ( V_11 ) )
return;
V_6 -> V_142 = false ;
if ( F_56 ( V_11 ) || F_57 ( V_11 ) ) {
F_45 ( V_6 -> V_123 , V_143 , & V_140 ) ;
V_141 = ! ! ( V_140 & V_144 ) ;
} else {
F_45 ( V_6 -> V_123 , V_139 , & V_140 ) ;
V_141 = V_140 & 1 ;
}
if ( V_141 )
return;
if ( F_44 ( V_11 ) )
return;
V_6 -> V_142 = true ;
if ( F_56 ( V_11 ) || F_57 ( V_11 ) ) {
F_50 ( V_6 -> V_123 , V_143 ,
V_140 | V_144 ) ;
} else {
F_45 ( V_6 -> V_123 , V_139 , & V_140 ) ;
F_50 ( V_6 -> V_123 , V_139 , V_140 | 1 ) ;
}
}
static void
F_58 ( struct V_25 * V_11 )
{
struct V_5 * V_6 = F_18 ( V_11 ) ;
int V_139 = F_19 ( V_11 ) -> V_93 >= 4 ? V_125 : V_126 ;
if ( V_6 -> V_142 ) {
if ( F_56 ( V_11 ) || F_57 ( V_11 ) ) {
T_3 V_145 ;
F_45 ( V_6 -> V_123 , V_143 ,
& V_145 ) ;
V_145 &= ~ V_144 ;
F_50 ( V_6 -> V_123 , V_143 ,
V_145 ) ;
} else {
T_3 V_146 ;
F_45 ( V_6 -> V_123 , V_139 ,
& V_146 ) ;
V_146 &= ~ 1 ;
F_50 ( V_6 -> V_123 , V_139 ,
V_146 ) ;
}
}
if ( V_6 -> V_131 . V_138 )
F_59 ( & V_6 -> V_131 ) ;
}
static unsigned int F_60 ( void * V_147 , bool V_148 )
{
struct V_25 * V_11 = V_147 ;
F_61 ( V_11 , V_148 ) ;
if ( V_148 )
return V_149 | V_150 |
V_151 | V_152 ;
else
return V_151 | V_152 ;
}
static void F_62 ( struct V_32 * V_71 , enum V_153 V_148 )
{
struct V_25 * V_11 = F_63 ( V_71 ) ;
T_5 V_154 = { . V_155 = V_156 } ;
if ( V_148 == V_157 ) {
F_64 ( L_22 ) ;
V_11 -> V_158 = V_159 ;
F_65 ( V_11 -> V_71 , V_160 ) ;
F_66 ( V_11 ) ;
V_11 -> V_158 = V_161 ;
} else {
F_64 ( L_23 ) ;
V_11 -> V_158 = V_159 ;
F_67 ( V_11 , V_154 ) ;
V_11 -> V_158 = V_162 ;
}
}
static bool F_68 ( struct V_32 * V_71 )
{
struct V_25 * V_11 = F_63 ( V_71 ) ;
return V_11 -> V_163 == 0 ;
}
static void F_69 ( struct V_25 * V_11 )
{
struct V_5 * V_6 = F_18 ( V_11 ) ;
if ( F_70 ( V_11 ) ) {
int V_164 = F_71 ( V_6 , V_165 ) ;
F_21 ( V_164 && V_164 != - V_69 ) ;
}
F_72 ( & V_11 -> V_166 ) ;
F_73 ( V_11 ) ;
F_74 ( V_11 ) ;
F_75 ( V_11 ) ;
F_76 ( & V_11 -> V_166 ) ;
F_21 ( ! F_77 ( & F_18 ( V_11 ) -> V_167 ) ) ;
}
static int F_78 ( struct V_25 * V_11 )
{
struct V_5 * V_6 = F_18 ( V_11 ) ;
int V_26 ;
if ( F_79 () )
return - V_69 ;
V_26 = F_80 ( V_6 ) ;
if ( V_26 )
F_2 ( L_24 ) ;
V_26 = F_81 ( V_11 -> V_71 , V_11 , NULL , F_60 ) ;
if ( V_26 && V_26 != - V_69 )
goto V_168;
F_82 () ;
V_26 = F_83 ( V_11 -> V_71 , & V_169 , false ) ;
if ( V_26 )
goto V_170;
F_84 ( V_6 ) ;
F_85 ( V_6 , false ) ;
F_86 ( V_6 ) ;
V_26 = F_87 ( V_6 ) ;
if ( V_26 )
goto V_171;
F_88 ( V_11 ) ;
F_89 ( V_11 ) ;
F_90 ( V_11 ) ;
V_26 = F_91 ( V_11 ) ;
if ( V_26 )
goto V_172;
F_92 ( V_11 ) ;
if ( F_19 ( V_11 ) -> V_34 == 0 )
return 0 ;
V_26 = F_93 ( V_11 ) ;
if ( V_26 )
goto V_173;
F_94 ( V_6 ) ;
F_95 ( V_11 ) ;
return 0 ;
V_173:
F_69 ( V_11 ) ;
V_172:
F_96 ( V_11 ) ;
F_97 ( V_11 ) ;
F_98 ( V_11 ) ;
V_171:
F_99 ( V_6 ) ;
F_100 ( V_6 ) ;
F_101 ( V_11 -> V_71 ) ;
V_170:
F_81 ( V_11 -> V_71 , NULL , NULL , NULL ) ;
V_168:
return V_26 ;
}
static int F_102 ( struct V_5 * V_6 )
{
struct V_174 * V_175 ;
struct V_32 * V_71 = V_6 -> V_12 . V_71 ;
struct V_176 * V_177 = & V_6 -> V_177 ;
bool V_178 ;
int V_26 ;
V_175 = F_103 ( 1 ) ;
if ( ! V_175 )
return - V_179 ;
V_175 -> V_180 [ 0 ] . V_181 = V_177 -> V_182 ;
V_175 -> V_180 [ 0 ] . V_183 = V_177 -> V_184 ;
V_178 =
V_71 -> V_185 [ V_186 ] . V_133 & V_187 ;
V_26 = F_104 ( V_175 , L_25 , V_178 ) ;
F_105 ( V_175 ) ;
return V_26 ;
}
static int F_102 ( struct V_5 * V_6 )
{
return 0 ;
}
static int F_106 ( struct V_5 * V_6 )
{
return 0 ;
}
static int F_106 ( struct V_5 * V_6 )
{
return - V_69 ;
}
static int F_106 ( struct V_5 * V_6 )
{
int V_26 = 0 ;
F_2 ( L_26 ) ;
F_107 () ;
if ( F_108 ( & V_188 ) )
V_26 = F_109 ( & V_189 , 0 , V_190 - 1 , 1 ) ;
if ( V_26 == 0 ) {
V_26 = F_110 ( & V_188 ) ;
if ( V_26 == - V_69 )
V_26 = 0 ;
}
F_111 () ;
return V_26 ;
}
static void F_112 ( struct V_5 * V_6 )
{
if ( F_55 ( V_6 ) ) {
F_113 ( V_191 ) = V_192 ;
F_113 ( V_193 ) = V_194 ;
} else if ( F_54 ( V_6 ) ) {
F_113 ( V_191 ) = V_194 ;
}
}
static int F_114 ( struct V_5 * V_6 )
{
V_6 -> V_195 = F_115 ( L_27 , 0 ) ;
if ( V_6 -> V_195 == NULL )
goto V_196;
V_6 -> V_197 . V_198 = F_115 ( L_28 , 0 ) ;
if ( V_6 -> V_197 . V_198 == NULL )
goto V_199;
return 0 ;
V_199:
F_116 ( V_6 -> V_195 ) ;
V_196:
F_43 ( L_29 ) ;
return - V_179 ;
}
static void F_117 ( struct V_5 * V_6 )
{
F_116 ( V_6 -> V_197 . V_198 ) ;
F_116 ( V_6 -> V_195 ) ;
}
static int F_118 ( struct V_5 * V_6 ,
const struct V_200 * V_201 )
{
const struct V_202 * V_203 =
(struct V_202 * ) V_201 -> V_204 ;
struct V_202 * V_205 ;
int V_26 = 0 ;
if ( F_79 () )
return - V_69 ;
V_205 = F_119 ( V_6 ) ;
memcpy ( V_205 , V_203 , sizeof( * V_205 ) ) ;
V_205 -> V_206 = V_6 -> V_12 . V_71 -> V_10 ;
F_120 ( V_205 -> V_93 > sizeof( V_205 -> V_207 ) * V_208 ) ;
V_205 -> V_207 = F_121 ( V_205 -> V_93 - 1 ) ;
F_122 ( & V_6 -> V_209 ) ;
F_122 ( & V_6 -> V_210 . V_211 ) ;
F_123 ( & V_6 -> V_212 ) ;
F_122 ( & V_6 -> V_213 . V_211 ) ;
F_122 ( & V_6 -> V_214 . V_215 ) ;
F_122 ( & V_6 -> V_216 ) ;
F_123 ( & V_6 -> V_217 ) ;
F_123 ( & V_6 -> V_218 ) ;
F_123 ( & V_6 -> V_219 ) ;
F_123 ( & V_6 -> V_220 . V_221 ) ;
F_123 ( & V_6 -> V_222 ) ;
V_26 = F_114 ( V_6 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_124 ( V_6 ) ;
if ( V_26 < 0 )
goto V_223;
F_17 ( & V_6 -> V_12 ) ;
F_125 ( & V_6 -> V_12 ) ;
F_112 ( V_6 ) ;
F_126 ( V_6 ) ;
F_127 ( V_6 ) ;
F_128 ( V_6 ) ;
F_129 ( V_6 ) ;
F_130 ( V_6 ) ;
F_131 ( & V_6 -> V_12 ) ;
F_132 ( & V_6 -> V_12 ) ;
F_133 ( V_6 ) ;
if ( F_134 ( V_6 ) )
F_2 ( L_30
L_31 ) ;
return 0 ;
V_223:
F_117 ( V_6 ) ;
return V_26 ;
}
static void F_135 ( struct V_5 * V_6 )
{
F_136 ( & V_6 -> V_12 ) ;
F_117 ( V_6 ) ;
}
static int F_137 ( struct V_25 * V_11 )
{
struct V_5 * V_6 = F_18 ( V_11 ) ;
int V_224 ;
int V_225 ;
V_224 = F_138 ( V_11 ) ? 1 : 0 ;
if ( F_19 ( V_11 ) -> V_93 < 5 )
V_225 = 512 * 1024 ;
else
V_225 = 2 * 1024 * 1024 ;
V_6 -> V_226 = F_139 ( V_11 -> V_71 , V_224 , V_225 ) ;
if ( V_6 -> V_226 == NULL ) {
F_43 ( L_32 ) ;
return - V_227 ;
}
F_53 ( V_11 ) ;
return 0 ;
}
static void F_140 ( struct V_25 * V_11 )
{
struct V_5 * V_6 = F_18 ( V_11 ) ;
F_58 ( V_11 ) ;
F_141 ( V_11 -> V_71 , V_6 -> V_226 ) ;
}
static int F_142 ( struct V_5 * V_6 )
{
struct V_25 * V_11 = & V_6 -> V_12 ;
int V_26 ;
if ( F_79 () )
return - V_69 ;
if ( F_40 ( V_11 ) )
return - V_227 ;
V_26 = F_137 ( V_11 ) ;
if ( V_26 < 0 )
goto V_228;
F_143 ( V_6 ) ;
return 0 ;
V_228:
F_24 ( V_6 -> V_123 ) ;
return V_26 ;
}
static void F_144 ( struct V_5 * V_6 )
{
struct V_25 * V_11 = & V_6 -> V_12 ;
F_145 ( V_6 ) ;
F_140 ( V_11 ) ;
F_24 ( V_6 -> V_123 ) ;
}
static void F_146 ( struct V_5 * V_6 )
{
V_3 . V_59 =
F_147 ( V_6 ,
V_3 . V_59 ) ;
V_3 . V_229 =
F_148 ( V_6 , V_3 . V_229 ) ;
F_49 ( L_33 , V_3 . V_229 ) ;
}
static int F_149 ( struct V_5 * V_6 )
{
struct V_25 * V_11 = & V_6 -> V_12 ;
struct V_176 * V_177 = & V_6 -> V_177 ;
T_6 V_230 ;
int V_26 ;
if ( F_79 () )
return - V_69 ;
F_150 ( V_6 ) ;
F_146 ( V_6 ) ;
V_26 = F_151 ( V_11 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_152 ( V_11 ) ;
if ( V_26 ) {
F_43 ( L_34 ) ;
goto V_231;
}
V_26 = F_102 ( V_6 ) ;
if ( V_26 ) {
F_43 ( L_35 ) ;
goto V_231;
}
V_26 = F_106 ( V_6 ) ;
if ( V_26 ) {
F_43 ( L_36 ) ;
goto V_231;
}
F_153 ( V_11 -> V_71 ) ;
if ( F_138 ( V_11 ) ) {
V_26 = F_154 ( & V_11 -> V_71 -> V_11 , F_155 ( 30 ) ) ;
if ( V_26 ) {
F_43 ( L_37 ) ;
goto V_231;
}
}
if ( F_156 ( V_11 ) || F_157 ( V_11 ) ) {
V_26 = F_154 ( & V_11 -> V_71 -> V_11 , F_155 ( 32 ) ) ;
if ( V_26 ) {
F_43 ( L_37 ) ;
goto V_231;
}
}
V_230 = V_177 -> V_184 ;
V_177 -> V_232 =
F_158 ( V_177 -> V_182 ,
V_230 ) ;
if ( ! V_177 -> V_232 ) {
V_26 = - V_227 ;
goto V_231;
}
V_177 -> V_233 = F_159 ( V_177 -> V_182 ,
V_230 ) ;
F_160 ( & V_6 -> V_234 , V_235 ,
V_236 ) ;
F_161 ( V_6 ) ;
F_162 ( V_6 ) ;
F_163 ( V_6 ) ;
if ( ! F_164 ( V_11 ) && ! F_165 ( V_11 ) ) {
if ( F_166 ( V_11 -> V_71 ) < 0 )
F_49 ( L_38 ) ;
}
return 0 ;
V_231:
F_167 ( V_11 ) ;
return V_26 ;
}
static void F_168 ( struct V_5 * V_6 )
{
struct V_25 * V_11 = & V_6 -> V_12 ;
struct V_176 * V_177 = & V_6 -> V_177 ;
if ( V_11 -> V_71 -> V_237 )
F_169 ( V_11 -> V_71 ) ;
F_170 ( & V_6 -> V_234 ) ;
F_171 ( V_177 -> V_233 ) ;
F_172 ( V_177 -> V_232 ) ;
F_167 ( V_11 ) ;
}
static void F_173 ( struct V_5 * V_6 )
{
struct V_25 * V_11 = & V_6 -> V_12 ;
F_174 ( V_6 ) ;
if ( F_175 ( V_6 ) )
F_176 ( F_177 ( V_238 ) , V_239 ) ;
if ( F_178 ( V_11 , 0 ) == 0 ) {
F_179 ( V_6 ) ;
F_180 ( V_11 ) ;
} else
F_43 ( L_39 ) ;
if ( F_19 ( V_6 ) -> V_34 ) {
F_181 ( V_6 ) ;
F_182 () ;
}
if ( F_9 ( V_6 ) )
F_183 ( V_6 ) ;
F_184 ( V_6 ) ;
F_185 ( V_11 ) ;
}
static void F_186 ( struct V_5 * V_6 )
{
F_187 ( V_6 ) ;
F_188 () ;
F_189 () ;
F_190 ( V_6 ) ;
F_191 ( & V_6 -> V_12 ) ;
F_192 ( V_6 ) ;
F_193 ( & V_6 -> V_12 ) ;
F_194 ( V_6 ) ;
}
int F_195 ( struct V_32 * V_71 , const struct V_200 * V_201 )
{
struct V_5 * V_6 ;
int V_26 ;
if ( V_3 . V_240 )
V_241 . V_242 |= V_243 ;
V_26 = - V_179 ;
V_6 = F_196 ( sizeof( * V_6 ) , V_244 ) ;
if ( V_6 )
V_26 = F_197 ( & V_6 -> V_12 , & V_241 , & V_71 -> V_11 ) ;
if ( V_26 ) {
F_4 ( V_14 , & V_71 -> V_11 ,
L_2 V_22 L_40 , V_245 ) ;
F_105 ( V_6 ) ;
return V_26 ;
}
V_6 -> V_12 . V_71 = V_71 ;
V_6 -> V_12 . V_246 = V_6 ;
V_26 = F_198 ( V_71 ) ;
if ( V_26 )
goto V_247;
F_199 ( V_71 , & V_6 -> V_12 ) ;
V_26 = F_118 ( V_6 , V_201 ) ;
if ( V_26 < 0 )
goto V_248;
F_200 ( V_6 ) ;
V_26 = F_142 ( V_6 ) ;
if ( V_26 < 0 )
goto V_249;
V_26 = F_149 ( V_6 ) ;
if ( V_26 < 0 )
goto V_250;
if ( F_19 ( V_6 ) -> V_34 ) {
V_26 = F_201 ( & V_6 -> V_12 ,
F_19 ( V_6 ) -> V_34 ) ;
if ( V_26 )
goto V_251;
}
V_26 = F_78 ( & V_6 -> V_12 ) ;
if ( V_26 < 0 )
goto V_252;
F_173 ( V_6 ) ;
F_202 ( V_6 ) ;
F_2 ( L_41 ,
V_241 . V_132 , V_241 . V_253 , V_241 . V_254 , V_241 . V_255 ,
V_241 . V_256 , F_203 ( V_71 ) , V_6 -> V_12 . V_178 -> V_257 ) ;
F_204 ( V_6 ) ;
return 0 ;
V_252:
F_205 ( & V_6 -> V_12 ) ;
V_251:
F_168 ( V_6 ) ;
V_250:
F_144 ( V_6 ) ;
V_249:
F_204 ( V_6 ) ;
F_135 ( V_6 ) ;
V_248:
F_206 ( V_71 ) ;
V_247:
F_207 ( V_6 , L_42 , V_26 ) ;
F_208 ( & V_6 -> V_12 ) ;
return V_26 ;
}
void F_209 ( struct V_25 * V_11 )
{
struct V_5 * V_6 = F_18 ( V_11 ) ;
F_210 ( V_11 ) ;
if ( F_211 ( V_11 ) )
F_43 ( L_43 ) ;
F_212 ( V_6 , V_258 ) ;
F_186 ( V_6 ) ;
F_205 ( V_11 ) ;
F_213 ( V_11 ) ;
if ( V_6 -> V_259 . V_260 && V_6 -> V_259 . V_261 ) {
F_105 ( V_6 -> V_259 . V_260 ) ;
V_6 -> V_259 . V_260 = NULL ;
V_6 -> V_259 . V_261 = 0 ;
}
F_105 ( V_6 -> V_259 . V_262 ) ;
V_6 -> V_259 . V_262 = NULL ;
F_105 ( V_6 -> V_259 . V_263 ) ;
V_6 -> V_259 . V_263 = NULL ;
F_101 ( V_11 -> V_71 ) ;
F_81 ( V_11 -> V_71 , NULL , NULL , NULL ) ;
F_99 ( V_6 ) ;
F_214 ( & V_6 -> V_210 . V_264 ) ;
F_215 ( V_11 ) ;
F_216 ( V_6 -> V_195 ) ;
F_96 ( V_11 ) ;
F_69 ( V_11 ) ;
F_217 ( V_6 ) ;
F_100 ( V_6 ) ;
F_168 ( V_6 ) ;
F_144 ( V_6 ) ;
F_218 ( V_6 , V_258 ) ;
F_135 ( V_6 ) ;
}
static int F_219 ( struct V_25 * V_11 , struct V_62 * V_265 )
{
int V_26 ;
V_26 = F_220 ( V_11 , V_265 ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
static void F_221 ( struct V_25 * V_11 )
{
F_222 ( V_11 ) ;
F_223 () ;
}
static void F_224 ( struct V_25 * V_11 , struct V_62 * V_265 )
{
F_72 ( & V_11 -> V_166 ) ;
F_225 ( V_11 , V_265 ) ;
F_226 ( V_11 , V_265 ) ;
F_76 ( & V_11 -> V_166 ) ;
}
static void F_227 ( struct V_25 * V_11 , struct V_62 * V_265 )
{
struct V_266 * V_63 = V_265 -> V_267 ;
F_105 ( V_63 ) ;
}
static void F_228 ( struct V_5 * V_6 )
{
struct V_25 * V_11 = & V_6 -> V_12 ;
struct V_268 * V_269 ;
F_229 ( V_11 ) ;
F_230 (dev, encoder)
if ( V_269 -> V_270 )
V_269 -> V_270 ( V_269 ) ;
F_231 ( V_11 ) ;
}
static bool F_232 ( struct V_5 * V_6 )
{
#if F_233 ( V_271 )
if ( F_234 () < V_272 )
return true ;
#endif
return false ;
}
static int F_235 ( struct V_25 * V_11 )
{
struct V_5 * V_6 = F_18 ( V_11 ) ;
T_7 V_273 ;
int error ;
F_72 ( & V_6 -> V_218 ) ;
V_6 -> V_274 = V_275 ;
F_76 ( & V_6 -> V_218 ) ;
F_236 ( V_6 ) ;
F_237 ( V_6 , true ) ;
F_238 ( V_11 ) ;
F_239 ( V_11 -> V_71 ) ;
error = F_211 ( V_11 ) ;
if ( error ) {
F_240 ( & V_11 -> V_71 -> V_11 ,
L_44 ) ;
goto V_168;
}
F_241 ( V_11 ) ;
F_242 ( V_6 ) ;
F_243 ( V_11 ) ;
F_244 ( V_11 ) ;
F_245 ( V_6 ) ;
F_246 ( V_6 ) ;
F_228 ( V_6 ) ;
F_247 ( V_11 ) ;
F_248 ( V_11 ) ;
F_249 ( V_11 ) ;
V_273 = F_232 ( V_6 ) ? V_276 : V_277 ;
F_250 ( V_6 , V_273 ) ;
F_251 ( V_6 , false ) ;
F_190 ( V_6 ) ;
F_252 ( V_11 , V_278 , true ) ;
V_6 -> V_279 ++ ;
F_237 ( V_6 , false ) ;
F_253 ( V_6 ) ;
V_168:
F_254 ( V_6 ) ;
return error ;
}
static int F_255 ( struct V_25 * V_280 , bool V_281 )
{
struct V_5 * V_6 = F_18 ( V_280 ) ;
bool V_282 ;
int V_26 ;
F_236 ( V_6 ) ;
V_282 = ! F_256 ( V_6 ) &&
F_232 ( V_6 ) && V_6 -> V_283 . V_284 ;
if ( ! V_282 )
F_257 ( V_6 ) ;
V_26 = 0 ;
if ( F_256 ( V_6 ) )
F_258 ( V_6 ) ;
else if ( F_13 ( V_6 ) || F_14 ( V_6 ) )
F_259 ( V_6 ) ;
else if ( F_54 ( V_6 ) || F_55 ( V_6 ) )
V_26 = F_260 ( V_6 ) ;
if ( V_26 ) {
F_43 ( L_45 , V_26 ) ;
if ( ! V_282 )
F_85 ( V_6 , true ) ;
goto V_168;
}
F_206 ( V_280 -> V_71 ) ;
if ( ! ( V_281 && F_19 ( V_6 ) -> V_93 < 6 ) )
F_65 ( V_280 -> V_71 , V_285 ) ;
V_6 -> V_286 = F_232 ( V_6 ) ;
V_168:
F_254 ( V_6 ) ;
return V_26 ;
}
int F_67 ( struct V_25 * V_11 , T_5 V_148 )
{
int error ;
if ( ! V_11 ) {
F_43 ( L_46 , V_11 ) ;
F_43 ( L_47 ) ;
return - V_69 ;
}
if ( F_261 ( V_148 . V_155 != V_156 &&
V_148 . V_155 != V_287 ) )
return - V_121 ;
if ( V_11 -> V_158 == V_162 )
return 0 ;
error = F_235 ( V_11 ) ;
if ( error )
return error ;
return F_255 ( V_11 , false ) ;
}
static int F_262 ( struct V_25 * V_11 )
{
struct V_5 * V_6 = F_18 ( V_11 ) ;
int V_26 ;
F_236 ( V_6 ) ;
V_26 = F_152 ( V_11 ) ;
if ( V_26 )
F_43 ( L_48 ) ;
F_263 ( V_6 ) ;
F_72 ( & V_11 -> V_166 ) ;
F_264 ( V_11 ) ;
F_76 ( & V_11 -> V_166 ) ;
F_265 ( V_11 ) ;
F_162 ( V_6 ) ;
F_266 ( V_11 ) ;
F_267 ( V_11 ) ;
F_268 ( V_6 ) ;
F_72 ( & V_11 -> V_166 ) ;
if ( F_269 ( V_11 ) ) {
F_43 ( L_49 ) ;
F_270 ( V_288 , & V_6 -> V_210 . V_289 ) ;
}
F_76 ( & V_11 -> V_166 ) ;
F_271 ( V_11 ) ;
F_272 ( V_11 ) ;
F_273 ( & V_6 -> V_209 ) ;
if ( V_6 -> V_290 . V_291 )
V_6 -> V_290 . V_291 ( V_6 ) ;
F_274 ( & V_6 -> V_209 ) ;
F_275 ( V_11 ) ;
F_276 ( V_11 ) ;
F_94 ( V_6 ) ;
F_277 ( V_11 ) ;
F_181 ( V_6 ) ;
F_252 ( V_11 , V_292 , false ) ;
F_72 ( & V_6 -> V_218 ) ;
V_6 -> V_274 = V_293 ;
F_76 ( & V_6 -> V_218 ) ;
F_250 ( V_6 , V_160 ) ;
F_278 ( V_11 ) ;
F_254 ( V_6 ) ;
return 0 ;
}
static int F_279 ( struct V_25 * V_11 )
{
struct V_5 * V_6 = F_18 ( V_11 ) ;
int V_26 ;
V_26 = F_65 ( V_11 -> V_71 , V_160 ) ;
if ( V_26 ) {
F_43 ( L_50 , V_26 ) ;
goto V_168;
}
if ( F_198 ( V_11 -> V_71 ) ) {
V_26 = - V_227 ;
goto V_168;
}
F_153 ( V_11 -> V_71 ) ;
F_236 ( V_6 ) ;
if ( F_54 ( V_6 ) || F_55 ( V_6 ) )
V_26 = F_280 ( V_6 , false ) ;
if ( V_26 )
F_43 ( L_51 ,
V_26 ) ;
F_281 ( V_6 , true ) ;
if ( F_256 ( V_6 ) ) {
if ( ! V_6 -> V_286 )
F_282 ( V_6 ) ;
F_283 ( V_6 ) ;
} else if ( F_13 ( V_6 ) || F_14 ( V_6 ) ) {
F_284 ( V_6 ) ;
}
F_161 ( V_6 ) ;
if ( F_256 ( V_6 ) ||
! ( V_6 -> V_286 && V_6 -> V_283 . V_284 ) )
F_85 ( V_6 , true ) ;
F_254 ( V_6 ) ;
V_168:
V_6 -> V_286 = false ;
return V_26 ;
}
int F_66 ( struct V_25 * V_11 )
{
int V_26 ;
if ( V_11 -> V_158 == V_162 )
return 0 ;
V_26 = F_279 ( V_11 ) ;
if ( V_26 )
return V_26 ;
return F_262 ( V_11 ) ;
}
int F_285 ( struct V_5 * V_6 )
{
struct V_25 * V_11 = & V_6 -> V_12 ;
struct V_294 * error = & V_6 -> V_210 ;
unsigned V_289 ;
int V_26 ;
F_286 ( V_6 ) ;
F_72 ( & V_11 -> V_166 ) ;
F_287 ( V_288 , & error -> V_289 ) ;
V_289 = F_288 ( & error -> V_289 ) ;
if ( F_21 ( F_289 ( V_289 ) ) ) {
V_26 = - V_227 ;
goto error;
}
F_290 ( L_52 ) ;
F_73 ( V_11 ) ;
V_26 = F_71 ( V_6 , V_165 ) ;
if ( V_26 ) {
if ( V_26 != - V_69 )
F_43 ( L_53 , V_26 ) ;
else
F_49 ( L_54 ) ;
goto error;
}
F_291 ( V_6 ) ;
V_26 = F_269 ( V_11 ) ;
if ( V_26 ) {
F_43 ( L_55 , V_26 ) ;
goto error;
}
F_76 ( & V_11 -> V_166 ) ;
if ( F_19 ( V_11 ) -> V_93 > 5 )
F_292 ( V_6 ) ;
return 0 ;
error:
F_270 ( V_288 , & error -> V_289 ) ;
F_76 ( & V_11 -> V_166 ) ;
return V_26 ;
}
static int F_293 ( struct V_10 * V_11 )
{
struct V_32 * V_71 = F_294 ( V_11 ) ;
struct V_25 * V_280 = F_63 ( V_71 ) ;
if ( ! V_280 ) {
F_240 ( V_11 , L_47 ) ;
return - V_69 ;
}
if ( V_280 -> V_158 == V_162 )
return 0 ;
return F_235 ( V_280 ) ;
}
static int F_295 ( struct V_10 * V_11 )
{
struct V_25 * V_280 = & F_296 ( V_11 ) -> V_12 ;
if ( V_280 -> V_158 == V_162 )
return 0 ;
return F_255 ( V_280 , false ) ;
}
static int F_297 ( struct V_10 * V_11 )
{
struct V_25 * V_280 = & F_296 ( V_11 ) -> V_12 ;
if ( V_280 -> V_158 == V_162 )
return 0 ;
return F_255 ( V_280 , true ) ;
}
static int F_298 ( struct V_10 * V_11 )
{
struct V_25 * V_280 = & F_296 ( V_11 ) -> V_12 ;
if ( V_280 -> V_158 == V_162 )
return 0 ;
return F_279 ( V_280 ) ;
}
static int F_299 ( struct V_10 * V_11 )
{
struct V_25 * V_280 = & F_296 ( V_11 ) -> V_12 ;
if ( V_280 -> V_158 == V_162 )
return 0 ;
return F_262 ( V_280 ) ;
}
static int F_300 ( struct V_10 * V_11 )
{
return F_293 ( V_11 ) ;
}
static int F_301 ( struct V_10 * V_11 )
{
int V_26 ;
V_26 = F_295 ( V_11 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_302 ( F_296 ( V_11 ) ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
static int F_303 ( struct V_10 * V_11 )
{
return F_298 ( V_11 ) ;
}
static int F_304 ( struct V_10 * V_11 )
{
return F_299 ( V_11 ) ;
}
static int F_305 ( struct V_10 * V_11 )
{
return F_298 ( V_11 ) ;
}
static int F_306 ( struct V_10 * V_11 )
{
return F_299 ( V_11 ) ;
}
static void F_307 ( struct V_5 * V_6 )
{
struct V_295 * V_296 = & V_6 -> V_295 ;
int V_297 ;
V_296 -> V_298 = F_308 ( V_299 ) ;
V_296 -> V_300 = F_308 ( V_301 ) ;
V_296 -> V_302 = F_308 ( V_303 ) ;
V_296 -> V_304 = F_308 ( V_305 ) ;
V_296 -> V_306 = F_308 ( V_307 ) ;
for ( V_297 = 0 ; V_297 < F_309 ( V_296 -> V_308 ) ; V_297 ++ )
V_296 -> V_308 [ V_297 ] = F_308 ( F_310 ( V_297 ) ) ;
V_296 -> V_309 = F_308 ( V_310 ) ;
V_296 -> V_311 = F_308 ( V_312 ) ;
V_296 -> V_313 = F_308 ( V_314 ) ;
V_296 -> V_315 = F_308 ( V_316 ) ;
V_296 -> V_317 = F_308 ( V_318 ) ;
V_296 -> V_319 = F_308 ( V_320 ) ;
V_296 -> V_321 = F_308 ( V_322 ) ;
V_296 -> V_323 = F_308 ( V_324 ) ;
V_296 -> V_325 = F_308 ( V_326 ) ;
V_296 -> V_327 = F_308 ( V_328 ) ;
V_296 -> V_329 = F_308 ( V_330 ) ;
V_296 -> V_331 = F_308 ( V_332 ) ;
V_296 -> V_333 = F_308 ( V_334 ) ;
V_296 -> V_335 = F_308 ( V_336 ) ;
V_296 -> V_337 = F_308 ( V_338 ) ;
V_296 -> V_339 = F_308 ( V_340 ) ;
V_296 -> V_341 = F_308 ( V_342 ) ;
V_296 -> V_343 = F_308 ( V_344 ) ;
V_296 -> V_345 = F_308 ( V_346 ) ;
V_296 -> V_347 = F_308 ( V_348 ) ;
V_296 -> V_349 = F_308 ( V_350 ) ;
V_296 -> V_351 = F_308 ( V_352 ) ;
V_296 -> V_353 = F_308 ( V_354 ) ;
V_296 -> V_355 = F_308 ( V_356 ) ;
V_296 -> V_357 = F_308 ( V_358 ) ;
V_296 -> V_359 = F_308 ( V_360 ) ;
V_296 -> V_361 = F_308 ( V_362 ) ;
V_296 -> V_363 = F_308 ( V_364 ) ;
V_296 -> V_365 = F_308 ( V_366 ) ;
V_296 -> V_367 = F_308 ( V_368 ) ;
for ( V_297 = 0 ; V_297 < F_309 ( V_296 -> V_369 ) ; V_297 ++ )
V_296 -> V_369 [ V_297 ] = F_308 ( F_311 ( V_297 ) ) ;
V_296 -> V_370 = F_308 ( V_371 ) ;
V_296 -> V_372 = F_308 ( V_373 ) ;
V_296 -> V_374 = F_308 ( V_375 ) ;
V_296 -> V_376 = F_308 ( V_377 ) ;
V_296 -> V_378 = F_308 ( V_379 ) ;
V_296 -> V_380 = F_308 ( V_381 ) ;
V_296 -> V_382 = F_308 ( V_383 ) ;
V_296 -> V_384 = F_308 ( V_385 ) ;
V_296 -> V_386 = F_308 ( V_387 ) ;
}
static void F_312 ( struct V_5 * V_6 )
{
struct V_295 * V_296 = & V_6 -> V_295 ;
T_3 V_388 ;
int V_297 ;
F_176 ( V_299 , V_296 -> V_298 ) ;
F_176 ( V_301 , V_296 -> V_300 ) ;
F_176 ( V_303 , V_296 -> V_302 | ( 0xffff << 16 ) ) ;
F_176 ( V_305 , V_296 -> V_304 ) ;
F_176 ( V_307 , V_296 -> V_306 ) ;
for ( V_297 = 0 ; V_297 < F_309 ( V_296 -> V_308 ) ; V_297 ++ )
F_176 ( F_310 ( V_297 ) , V_296 -> V_308 [ V_297 ] ) ;
F_176 ( V_310 , V_296 -> V_309 ) ;
F_176 ( V_312 , V_296 -> V_311 ) ;
F_176 ( V_314 , V_296 -> V_313 ) ;
F_176 ( V_316 , V_296 -> V_315 ) ;
F_176 ( V_318 , V_296 -> V_317 ) ;
F_176 ( V_320 , V_296 -> V_319 ) ;
F_176 ( V_322 , V_296 -> V_321 ) ;
F_176 ( V_324 , V_296 -> V_323 ) ;
F_176 ( V_326 , V_296 -> V_325 ) ;
F_176 ( V_328 , V_296 -> V_327 ) ;
F_176 ( V_330 , V_296 -> V_329 ) ;
F_176 ( V_332 , V_296 -> V_331 ) ;
F_176 ( V_334 , V_296 -> V_333 ) ;
F_176 ( V_336 , V_296 -> V_335 ) ;
F_176 ( V_338 , V_296 -> V_337 ) ;
F_176 ( V_340 , V_296 -> V_339 ) ;
F_176 ( V_342 , V_296 -> V_341 ) ;
F_176 ( V_344 , V_296 -> V_343 ) ;
F_176 ( V_346 , V_296 -> V_345 ) ;
F_176 ( V_348 , V_296 -> V_347 ) ;
F_176 ( V_350 , V_296 -> V_349 ) ;
F_176 ( V_352 , V_296 -> V_351 ) ;
F_176 ( V_354 , V_296 -> V_353 ) ;
F_176 ( V_356 , V_296 -> V_355 ) ;
F_176 ( V_358 , V_296 -> V_357 ) ;
F_176 ( V_360 , V_296 -> V_359 ) ;
F_176 ( V_362 , V_296 -> V_361 ) ;
F_176 ( V_364 , V_296 -> V_363 ) ;
F_176 ( V_366 , V_296 -> V_365 ) ;
F_176 ( V_368 , V_296 -> V_367 ) ;
for ( V_297 = 0 ; V_297 < F_309 ( V_296 -> V_369 ) ; V_297 ++ )
F_176 ( F_311 ( V_297 ) , V_296 -> V_369 [ V_297 ] ) ;
F_176 ( V_371 , V_296 -> V_370 ) ;
F_176 ( V_373 , V_296 -> V_372 ) ;
V_388 = F_308 ( V_375 ) ;
V_388 &= V_389 ;
V_388 |= V_296 -> V_374 & ~ V_389 ;
F_176 ( V_375 , V_388 ) ;
V_388 = F_308 ( V_377 ) ;
V_388 &= V_390 ;
V_388 |= V_296 -> V_376 & ~ V_390 ;
F_176 ( V_377 , V_388 ) ;
F_176 ( V_379 , V_296 -> V_378 ) ;
F_176 ( V_381 , V_296 -> V_380 ) ;
F_176 ( V_383 , V_296 -> V_382 ) ;
F_176 ( V_385 , V_296 -> V_384 ) ;
F_176 ( V_387 , V_296 -> V_386 ) ;
}
int F_313 ( struct V_5 * V_6 , bool V_391 )
{
T_3 V_388 ;
int V_392 ;
V_388 = F_308 ( V_377 ) ;
V_388 &= ~ V_390 ;
if ( V_391 )
V_388 |= V_390 ;
F_176 ( V_377 , V_388 ) ;
if ( ! V_391 )
return 0 ;
V_392 = F_314 ( V_6 ,
V_377 ,
V_393 ,
V_393 ,
20 ) ;
if ( V_392 )
F_43 ( L_56 ,
F_308 ( V_377 ) ) ;
return V_392 ;
}
static int F_315 ( struct V_5 * V_6 , bool V_394 )
{
T_3 V_388 ;
int V_392 = 0 ;
V_388 = F_308 ( V_375 ) ;
V_388 &= ~ V_389 ;
if ( V_394 )
V_388 |= V_389 ;
F_176 ( V_375 , V_388 ) ;
F_316 ( V_375 ) ;
V_392 = F_314 ( V_6 ,
V_395 ,
V_396 ,
V_394 ,
1 ) ;
if ( V_392 )
F_43 ( L_57 ) ;
return V_392 ;
}
static int F_317 ( struct V_5 * V_6 ,
bool V_397 )
{
T_3 V_398 ;
T_3 V_388 ;
int V_392 ;
V_398 = V_399 | V_400 ;
V_388 = V_397 ? V_398 : 0 ;
if ( ( F_308 ( V_395 ) & V_398 ) == V_388 )
return 0 ;
F_10 ( L_58 ,
F_318 ( V_397 ) ,
F_308 ( V_395 ) ) ;
V_392 = F_314 ( V_6 ,
V_395 , V_398 , V_388 ,
3 ) ;
if ( V_392 )
F_43 ( L_59 ,
F_318 ( V_397 ) ) ;
return V_392 ;
}
static void F_319 ( struct V_5 * V_6 )
{
if ( ! ( F_308 ( V_395 ) & V_401 ) )
return;
F_49 ( L_60 ) ;
F_176 ( V_395 , V_401 ) ;
}
static int F_260 ( struct V_5 * V_6 )
{
T_3 V_398 ;
int V_392 ;
( void ) F_317 ( V_6 , false ) ;
V_398 = V_402 | V_403 ;
F_21 ( ( F_308 ( V_375 ) & V_398 ) != V_398 ) ;
F_319 ( V_6 ) ;
V_392 = F_313 ( V_6 , true ) ;
if ( V_392 )
goto V_404;
V_392 = F_315 ( V_6 , false ) ;
if ( V_392 )
goto V_405;
if ( ! F_55 ( V_6 ) )
F_307 ( V_6 ) ;
V_392 = F_313 ( V_6 , false ) ;
if ( V_392 )
goto V_405;
return 0 ;
V_405:
F_315 ( V_6 , true ) ;
V_404:
F_313 ( V_6 , false ) ;
return V_392 ;
}
static int F_280 ( struct V_5 * V_6 ,
bool V_406 )
{
struct V_25 * V_11 = & V_6 -> V_12 ;
int V_392 ;
int V_26 ;
V_26 = F_313 ( V_6 , true ) ;
if ( ! F_55 ( V_6 ) )
F_312 ( V_6 ) ;
V_392 = F_315 ( V_6 , true ) ;
if ( ! V_26 )
V_26 = V_392 ;
V_392 = F_313 ( V_6 , false ) ;
if ( ! V_26 )
V_26 = V_392 ;
F_319 ( V_6 ) ;
if ( V_406 ) {
F_320 ( V_11 ) ;
F_321 ( V_11 ) ;
}
return V_26 ;
}
static int F_322 ( struct V_10 * V_10 )
{
struct V_32 * V_71 = F_294 ( V_10 ) ;
struct V_25 * V_11 = F_63 ( V_71 ) ;
struct V_5 * V_6 = F_18 ( V_11 ) ;
int V_26 ;
if ( F_261 ( ! ( V_6 -> V_407 . V_141 && F_323 () ) ) )
return - V_69 ;
if ( F_261 ( ! F_324 ( V_11 ) ) )
return - V_69 ;
F_10 ( L_61 ) ;
if ( ! F_325 ( & V_11 -> V_166 ) ) {
F_10 ( L_62 ) ;
F_326 ( V_10 ) ;
return - V_408 ;
}
F_236 ( V_6 ) ;
F_327 ( V_6 ) ;
F_76 ( & V_11 -> V_166 ) ;
F_241 ( V_11 ) ;
F_245 ( V_6 ) ;
V_26 = 0 ;
if ( F_256 ( V_6 ) ) {
F_328 ( V_6 ) ;
F_258 ( V_6 ) ;
} else if ( F_13 ( V_6 ) || F_14 ( V_6 ) ) {
F_259 ( V_6 ) ;
} else if ( F_54 ( V_6 ) || F_55 ( V_6 ) ) {
V_26 = F_260 ( V_6 ) ;
}
if ( V_26 ) {
F_43 ( L_63 , V_26 ) ;
F_268 ( V_6 ) ;
F_254 ( V_6 ) ;
return V_26 ;
}
F_251 ( V_6 , false ) ;
F_254 ( V_6 ) ;
F_261 ( F_329 ( & V_6 -> V_409 . V_410 ) ) ;
if ( F_330 ( V_6 ) )
F_43 ( L_64 ) ;
V_6 -> V_409 . V_411 = true ;
if ( F_14 ( V_6 ) ) {
F_250 ( V_6 , V_285 ) ;
} else {
F_250 ( V_6 , V_276 ) ;
}
F_331 ( V_6 ) ;
if ( ! F_54 ( V_6 ) || ! F_55 ( V_6 ) )
F_332 ( V_6 ) ;
F_10 ( L_65 ) ;
return 0 ;
}
static int F_333 ( struct V_10 * V_10 )
{
struct V_32 * V_71 = F_294 ( V_10 ) ;
struct V_25 * V_11 = F_63 ( V_71 ) ;
struct V_5 * V_6 = F_18 ( V_11 ) ;
int V_26 = 0 ;
if ( F_261 ( ! F_324 ( V_11 ) ) )
return - V_69 ;
F_10 ( L_66 ) ;
F_261 ( F_329 ( & V_6 -> V_409 . V_410 ) ) ;
F_236 ( V_6 ) ;
F_250 ( V_6 , V_160 ) ;
V_6 -> V_409 . V_411 = false ;
if ( F_334 ( V_6 ) )
F_49 ( L_67 ) ;
F_271 ( V_11 ) ;
if ( F_11 ( V_6 ) )
F_266 ( V_11 ) ;
if ( F_256 ( V_11 ) ) {
F_283 ( V_6 ) ;
F_335 ( V_6 , true ) ;
if ( V_6 -> V_283 . V_284 &&
( V_6 -> V_283 . V_412 & V_413 ) )
F_336 ( V_6 ) ;
} else if ( F_13 ( V_6 ) || F_14 ( V_6 ) ) {
F_284 ( V_6 ) ;
} else if ( F_54 ( V_6 ) || F_55 ( V_6 ) ) {
V_26 = F_280 ( V_6 , true ) ;
}
F_337 ( V_11 ) ;
F_338 ( V_6 ) ;
F_268 ( V_6 ) ;
if ( ! F_54 ( V_6 ) && ! F_55 ( V_6 ) )
F_94 ( V_6 ) ;
F_254 ( V_6 ) ;
if ( V_26 )
F_43 ( L_68 , V_26 ) ;
else
F_10 ( L_69 ) ;
return V_26 ;
}
static int
F_339 ( struct V_25 * V_11 , void * V_61 ,
struct V_62 * V_265 )
{
return - V_69 ;
}
