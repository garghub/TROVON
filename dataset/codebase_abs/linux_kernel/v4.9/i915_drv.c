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
struct V_10 * V_11 = V_6 -> V_12 . V_13 ;
bool V_14 = V_7 [ 1 ] <= V_15 [ 1 ] ;
bool V_16 = V_7 [ 1 ] == V_17 [ 1 ] ;
struct V_18 V_19 ;
T_1 args ;
if ( V_16 && ! ( V_20 & V_21 ) )
return;
va_start ( args , V_8 ) ;
V_19 . V_8 = V_8 ;
V_19 . V_22 = & args ;
F_4 ( V_7 , V_11 , L_2 V_23 L_3 ,
F_5 ( 0 ) , & V_19 ) ;
if ( V_14 && ! V_9 ) {
F_6 ( V_11 , L_4 , V_24 ) ;
V_9 = true ;
}
va_end ( args ) ;
}
static bool F_7 ( struct V_5 * V_6 )
{
return V_3 . V_4 &&
V_2 == V_3 . V_4 ;
}
static enum V_25 F_8 ( struct V_26 * V_13 )
{
enum V_25 V_27 = V_28 ;
if ( F_9 ( V_13 ) ) {
V_27 = V_29 ;
F_10 ( L_5 ) ;
} else if ( F_11 ( V_13 ) || F_12 ( V_13 ) ) {
V_27 = V_30 ;
F_10 ( L_6 ) ;
} else if ( F_13 ( V_13 ) || F_14 ( V_13 ) ) {
V_27 = V_31 ;
F_10 ( L_7 ) ;
} else if ( F_15 ( V_13 ) || F_16 ( V_13 ) ) {
V_27 = V_32 ;
F_10 ( L_8 ) ;
}
return V_27 ;
}
static void F_17 ( struct V_26 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
struct V_33 * V_34 = NULL ;
if ( F_19 ( V_13 ) -> V_35 == 0 ) {
V_6 -> V_36 = V_28 ;
return;
}
while ( ( V_34 = F_20 ( V_37 << 8 , V_34 ) ) ) {
if ( V_34 -> V_38 == V_39 ) {
unsigned short V_40 = V_34 -> V_10 & V_41 ;
V_6 -> V_42 = V_40 ;
if ( V_40 == V_43 ) {
V_6 -> V_36 = V_29 ;
F_10 ( L_9 ) ;
F_21 ( ! F_9 ( V_13 ) ) ;
} else if ( V_40 == V_44 ) {
V_6 -> V_36 = V_30 ;
F_10 ( L_10 ) ;
F_21 ( ! ( F_11 ( V_13 ) || F_12 ( V_13 ) ) ) ;
} else if ( V_40 == V_45 ) {
V_6 -> V_36 = V_30 ;
F_10 ( L_11 ) ;
F_21 ( ! ( F_11 ( V_13 ) || F_12 ( V_13 ) ) ) ;
} else if ( V_40 == V_46 ) {
V_6 -> V_36 = V_31 ;
F_10 ( L_12 ) ;
F_21 ( ! F_13 ( V_13 ) && ! F_14 ( V_13 ) ) ;
F_21 ( F_22 ( V_13 ) || F_23 ( V_13 ) ) ;
} else if ( V_40 == V_47 ) {
V_6 -> V_36 = V_31 ;
F_10 ( L_13 ) ;
F_21 ( ! F_13 ( V_13 ) && ! F_14 ( V_13 ) ) ;
F_21 ( ! F_22 ( V_13 ) && ! F_23 ( V_13 ) ) ;
} else if ( V_40 == V_48 ) {
V_6 -> V_36 = V_32 ;
F_10 ( L_14 ) ;
F_21 ( ! F_15 ( V_13 ) &&
! F_16 ( V_13 ) ) ;
} else if ( V_40 == V_49 ) {
V_6 -> V_36 = V_32 ;
F_10 ( L_15 ) ;
F_21 ( ! F_15 ( V_13 ) &&
! F_16 ( V_13 ) ) ;
} else if ( V_40 == V_50 ) {
V_6 -> V_36 = V_51 ;
F_10 ( L_16 ) ;
F_21 ( ! F_16 ( V_13 ) ) ;
} else if ( ( V_40 == V_52 ) ||
( V_40 == V_53 ) ||
( ( V_40 == V_54 ) &&
V_34 -> V_55 ==
V_56 &&
V_34 -> V_57 ==
V_58 ) ) {
V_6 -> V_36 = F_8 ( V_13 ) ;
} else
continue;
break;
}
}
if ( ! V_34 )
F_10 ( L_17 ) ;
F_24 ( V_34 ) ;
}
static int F_25 ( struct V_26 * V_13 , void * V_59 ,
struct V_60 * V_61 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
struct V_33 * V_62 = V_6 -> V_12 . V_62 ;
T_2 * V_63 = V_59 ;
int V_64 ;
switch ( V_63 -> V_63 ) {
case V_65 :
case V_66 :
case V_67 :
return - V_68 ;
case V_69 :
V_64 = V_62 -> V_10 ;
break;
case V_70 :
V_64 = V_62 -> V_71 ;
break;
case V_72 :
V_64 = V_6 -> V_73 ;
break;
case V_74 :
V_64 = V_6 -> V_75 ? 1 : 0 ;
break;
case V_76 :
V_64 = F_26 ( & V_6 -> V_77 [ V_78 ] ) ;
break;
case V_79 :
V_64 = F_26 ( & V_6 -> V_77 [ V_80 ] ) ;
break;
case V_81 :
V_64 = F_26 ( & V_6 -> V_77 [ V_82 ] ) ;
break;
case V_83 :
V_64 = F_26 ( & V_6 -> V_77 [ V_84 ] ) ;
break;
case V_85 :
V_64 = F_27 ( V_6 ) >= 4 ;
break;
case V_86 :
V_64 = F_28 ( V_6 ) ;
break;
case V_87 :
V_64 = F_29 ( V_6 ) ;
break;
case V_88 :
V_64 = F_30 ( V_6 ) ;
break;
case V_89 :
V_64 = V_3 . V_90 ;
break;
case V_91 :
V_64 = F_31 ( V_92 ) ;
break;
case V_93 :
V_64 = F_32 ( V_6 ) ;
break;
case V_94 :
V_64 = F_33 ( & F_19 ( V_6 ) -> V_95 ) ;
if ( ! V_64 )
return - V_68 ;
break;
case V_96 :
V_64 = F_19 ( V_6 ) -> V_95 . V_97 ;
if ( ! V_64 )
return - V_68 ;
break;
case V_98 :
V_64 = V_3 . V_99 && F_34 ( V_6 ) ;
break;
case V_100 :
V_64 = F_35 ( V_6 ) ;
break;
case V_101 :
V_64 = F_36 ( V_6 ) ;
break;
case V_102 :
V_64 = F_19 ( V_6 ) -> V_95 . V_103 ;
break;
case V_104 :
V_64 = F_37 () ;
break;
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
V_64 = 1 ;
break;
default:
F_38 ( L_18 , V_63 -> V_63 ) ;
return - V_120 ;
}
if ( F_39 ( V_64 , V_63 -> V_64 ) )
return - V_121 ;
return 0 ;
}
static int F_40 ( struct V_26 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
V_6 -> V_122 = F_41 ( 0 , F_42 ( 0 , 0 ) ) ;
if ( ! V_6 -> V_122 ) {
F_43 ( L_19 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_44 ( struct V_26 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
int V_123 = F_19 ( V_13 ) -> V_124 >= 4 ? V_125 : V_126 ;
T_3 V_127 , V_128 = 0 ;
T_4 V_129 ;
int V_27 ;
if ( F_19 ( V_13 ) -> V_124 >= 4 )
F_45 ( V_6 -> V_122 , V_123 + 4 , & V_128 ) ;
F_45 ( V_6 -> V_122 , V_123 , & V_127 ) ;
V_129 = ( ( T_4 ) V_128 << 32 ) | V_127 ;
#ifdef F_46
if ( V_129 &&
F_47 ( V_129 , V_129 + V_130 ) )
return 0 ;
#endif
V_6 -> V_131 . V_132 = L_20 ;
V_6 -> V_131 . V_133 = V_134 ;
V_27 = F_48 ( V_6 -> V_122 -> V_135 ,
& V_6 -> V_131 ,
V_130 , V_130 ,
V_136 ,
0 , V_137 ,
V_6 -> V_122 ) ;
if ( V_27 ) {
F_49 ( L_21 , V_27 ) ;
V_6 -> V_131 . V_138 = 0 ;
return V_27 ;
}
if ( F_19 ( V_13 ) -> V_124 >= 4 )
F_50 ( V_6 -> V_122 , V_123 + 4 ,
F_51 ( V_6 -> V_131 . V_138 ) ) ;
F_50 ( V_6 -> V_122 , V_123 ,
F_52 ( V_6 -> V_131 . V_138 ) ) ;
return 0 ;
}
static void
F_53 ( struct V_26 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
int V_139 = F_19 ( V_13 ) -> V_124 >= 4 ? V_125 : V_126 ;
T_3 V_140 ;
bool V_141 ;
if ( F_54 ( V_13 ) || F_55 ( V_13 ) )
return;
V_6 -> V_142 = false ;
if ( F_56 ( V_13 ) || F_57 ( V_13 ) ) {
F_45 ( V_6 -> V_122 , V_143 , & V_140 ) ;
V_141 = ! ! ( V_140 & V_144 ) ;
} else {
F_45 ( V_6 -> V_122 , V_139 , & V_140 ) ;
V_141 = V_140 & 1 ;
}
if ( V_141 )
return;
if ( F_44 ( V_13 ) )
return;
V_6 -> V_142 = true ;
if ( F_56 ( V_13 ) || F_57 ( V_13 ) ) {
F_50 ( V_6 -> V_122 , V_143 ,
V_140 | V_144 ) ;
} else {
F_45 ( V_6 -> V_122 , V_139 , & V_140 ) ;
F_50 ( V_6 -> V_122 , V_139 , V_140 | 1 ) ;
}
}
static void
F_58 ( struct V_26 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
int V_139 = F_19 ( V_13 ) -> V_124 >= 4 ? V_125 : V_126 ;
if ( V_6 -> V_142 ) {
if ( F_56 ( V_13 ) || F_57 ( V_13 ) ) {
T_3 V_145 ;
F_45 ( V_6 -> V_122 , V_143 ,
& V_145 ) ;
V_145 &= ~ V_144 ;
F_50 ( V_6 -> V_122 , V_143 ,
V_145 ) ;
} else {
T_3 V_146 ;
F_45 ( V_6 -> V_122 , V_139 ,
& V_146 ) ;
V_146 &= ~ 1 ;
F_50 ( V_6 -> V_122 , V_139 ,
V_146 ) ;
}
}
if ( V_6 -> V_131 . V_138 )
F_59 ( & V_6 -> V_131 ) ;
}
static unsigned int F_60 ( void * V_147 , bool V_148 )
{
struct V_26 * V_13 = V_147 ;
F_61 ( V_13 , V_148 ) ;
if ( V_148 )
return V_149 | V_150 |
V_151 | V_152 ;
else
return V_151 | V_152 ;
}
static void F_62 ( struct V_33 * V_62 , enum V_153 V_148 )
{
struct V_26 * V_13 = F_63 ( V_62 ) ;
T_5 V_154 = { . V_155 = V_156 } ;
if ( V_148 == V_157 ) {
F_64 ( L_22 ) ;
V_13 -> V_158 = V_159 ;
F_65 ( V_62 , V_160 ) ;
F_66 ( V_13 ) ;
V_13 -> V_158 = V_161 ;
} else {
F_64 ( L_23 ) ;
V_13 -> V_158 = V_159 ;
F_67 ( V_13 , V_154 ) ;
V_13 -> V_158 = V_162 ;
}
}
static bool F_68 ( struct V_33 * V_62 )
{
struct V_26 * V_13 = F_63 ( V_62 ) ;
return V_13 -> V_163 == 0 ;
}
static void F_69 ( struct V_26 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
if ( F_70 ( V_13 ) ) {
int V_164 = F_71 ( V_6 , V_165 ) ;
F_21 ( V_164 && V_164 != - V_68 ) ;
}
F_72 ( & V_13 -> V_166 ) ;
F_73 ( V_13 ) ;
F_74 ( V_13 ) ;
F_75 ( & V_13 -> V_166 ) ;
F_21 ( ! F_76 ( & F_18 ( V_13 ) -> V_167 ) ) ;
}
static int F_77 ( struct V_26 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
struct V_33 * V_62 = V_6 -> V_12 . V_62 ;
int V_27 ;
if ( F_78 () )
return - V_68 ;
V_27 = F_79 ( V_6 ) ;
if ( V_27 )
F_2 ( L_24 ) ;
V_27 = F_80 ( V_62 , V_13 , NULL , F_60 ) ;
if ( V_27 && V_27 != - V_68 )
goto V_168;
F_81 () ;
V_27 = F_82 ( V_62 , & V_169 , false ) ;
if ( V_27 )
goto V_170;
F_83 ( V_6 ) ;
F_84 ( V_6 , false ) ;
F_85 ( V_6 ) ;
V_27 = F_86 ( V_6 ) ;
if ( V_27 )
goto V_171;
F_87 ( V_13 ) ;
F_88 ( V_13 ) ;
F_89 ( V_13 ) ;
V_27 = F_90 ( V_13 ) ;
if ( V_27 )
goto V_172;
F_91 ( V_13 ) ;
if ( F_19 ( V_13 ) -> V_35 == 0 )
return 0 ;
V_27 = F_92 ( V_13 ) ;
if ( V_27 )
goto V_173;
F_93 ( V_6 ) ;
F_94 ( V_13 ) ;
return 0 ;
V_173:
F_69 ( V_13 ) ;
V_172:
F_95 ( V_13 ) ;
F_96 ( V_13 ) ;
F_97 ( V_13 ) ;
V_171:
F_98 ( V_6 ) ;
F_99 ( V_6 ) ;
F_100 ( V_62 ) ;
V_170:
F_80 ( V_62 , NULL , NULL , NULL ) ;
V_168:
return V_27 ;
}
static int F_101 ( struct V_5 * V_6 )
{
struct V_174 * V_175 ;
struct V_33 * V_62 = V_6 -> V_12 . V_62 ;
struct V_176 * V_177 = & V_6 -> V_177 ;
bool V_178 ;
int V_27 ;
V_175 = F_102 ( 1 ) ;
if ( ! V_175 )
return - V_179 ;
V_175 -> V_180 [ 0 ] . V_181 = V_177 -> V_182 ;
V_175 -> V_180 [ 0 ] . V_183 = V_177 -> V_184 ;
V_178 =
V_62 -> V_185 [ V_186 ] . V_133 & V_187 ;
V_27 = F_103 ( V_175 , L_25 , V_178 ) ;
F_104 ( V_175 ) ;
return V_27 ;
}
static int F_101 ( struct V_5 * V_6 )
{
return 0 ;
}
static int F_105 ( struct V_5 * V_6 )
{
return 0 ;
}
static int F_105 ( struct V_5 * V_6 )
{
return - V_68 ;
}
static int F_105 ( struct V_5 * V_6 )
{
int V_27 = 0 ;
F_2 ( L_26 ) ;
F_106 () ;
if ( F_107 ( & V_188 ) )
V_27 = F_108 ( & V_189 , 0 , V_190 - 1 , 1 ) ;
if ( V_27 == 0 ) {
V_27 = F_109 ( & V_188 ) ;
if ( V_27 == - V_68 )
V_27 = 0 ;
}
F_110 () ;
return V_27 ;
}
static void F_111 ( struct V_5 * V_6 )
{
if ( F_55 ( V_6 ) ) {
F_112 ( V_191 ) = V_192 ;
F_112 ( V_193 ) = V_194 ;
} else if ( F_54 ( V_6 ) ) {
F_112 ( V_191 ) = V_194 ;
}
}
static int F_113 ( struct V_5 * V_6 )
{
V_6 -> V_195 = F_114 ( L_27 , 0 ) ;
if ( V_6 -> V_195 == NULL )
goto V_196;
V_6 -> V_197 . V_198 = F_114 ( L_28 , 0 ) ;
if ( V_6 -> V_197 . V_198 == NULL )
goto V_199;
return 0 ;
V_199:
F_115 ( V_6 -> V_195 ) ;
V_196:
F_43 ( L_29 ) ;
return - V_179 ;
}
static void F_116 ( struct V_5 * V_6 )
{
F_115 ( V_6 -> V_197 . V_198 ) ;
F_115 ( V_6 -> V_195 ) ;
}
static int F_117 ( struct V_5 * V_6 ,
const struct V_200 * V_201 )
{
const struct V_202 * V_203 =
(struct V_202 * ) V_201 -> V_204 ;
struct V_202 * V_205 ;
int V_27 = 0 ;
if ( F_78 () )
return - V_68 ;
V_205 = F_118 ( V_6 ) ;
memcpy ( V_205 , V_203 , sizeof( * V_205 ) ) ;
V_205 -> V_206 = V_6 -> V_12 . V_62 -> V_10 ;
F_119 ( V_205 -> V_124 > sizeof( V_205 -> V_207 ) * V_208 ) ;
V_205 -> V_207 = F_120 ( V_205 -> V_124 - 1 ) ;
F_121 ( & V_6 -> V_209 ) ;
F_121 ( & V_6 -> V_210 . V_211 ) ;
F_122 ( & V_6 -> V_212 ) ;
F_121 ( & V_6 -> V_213 . V_211 ) ;
F_121 ( & V_6 -> V_214 . V_215 ) ;
F_121 ( & V_6 -> V_216 ) ;
F_122 ( & V_6 -> V_217 ) ;
F_122 ( & V_6 -> V_218 ) ;
F_122 ( & V_6 -> V_219 ) ;
F_122 ( & V_6 -> V_220 . V_221 ) ;
F_122 ( & V_6 -> V_222 ) ;
F_123 ( V_6 ) ;
V_27 = F_113 ( V_6 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_124 ( V_6 ) ;
if ( V_27 < 0 )
goto V_223;
F_17 ( & V_6 -> V_12 ) ;
F_125 ( & V_6 -> V_12 ) ;
F_111 ( V_6 ) ;
F_126 ( V_6 ) ;
F_127 ( V_6 ) ;
F_128 ( V_6 ) ;
F_129 ( V_6 ) ;
F_130 ( V_6 ) ;
F_131 ( & V_6 -> V_12 ) ;
F_132 ( V_6 ) ;
F_133 ( V_6 ) ;
if ( F_134 ( V_6 ) )
F_2 ( L_30
L_31 ) ;
return 0 ;
V_223:
F_116 ( V_6 ) ;
return V_27 ;
}
static void F_135 ( struct V_5 * V_6 )
{
F_136 ( & V_6 -> V_12 ) ;
F_116 ( V_6 ) ;
}
static int F_137 ( struct V_26 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
struct V_33 * V_62 = V_6 -> V_12 . V_62 ;
int V_224 ;
int V_225 ;
V_224 = F_138 ( V_13 ) ? 1 : 0 ;
if ( F_19 ( V_13 ) -> V_124 < 5 )
V_225 = 512 * 1024 ;
else
V_225 = 2 * 1024 * 1024 ;
V_6 -> V_226 = F_139 ( V_62 , V_224 , V_225 ) ;
if ( V_6 -> V_226 == NULL ) {
F_43 ( L_32 ) ;
return - V_227 ;
}
F_53 ( V_13 ) ;
return 0 ;
}
static void F_140 ( struct V_26 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
struct V_33 * V_62 = V_6 -> V_12 . V_62 ;
F_58 ( V_13 ) ;
F_141 ( V_62 , V_6 -> V_226 ) ;
}
static int F_142 ( struct V_5 * V_6 )
{
struct V_26 * V_13 = & V_6 -> V_12 ;
int V_27 ;
if ( F_78 () )
return - V_68 ;
if ( F_40 ( V_13 ) )
return - V_227 ;
V_27 = F_137 ( V_13 ) ;
if ( V_27 < 0 )
goto V_228;
F_143 ( V_6 ) ;
return 0 ;
V_228:
F_24 ( V_6 -> V_122 ) ;
return V_27 ;
}
static void F_144 ( struct V_5 * V_6 )
{
struct V_26 * V_13 = & V_6 -> V_12 ;
F_145 ( V_6 ) ;
F_140 ( V_13 ) ;
F_24 ( V_6 -> V_122 ) ;
}
static void F_146 ( struct V_5 * V_6 )
{
V_3 . V_229 =
F_147 ( V_6 ,
V_3 . V_229 ) ;
V_3 . V_230 =
F_148 ( V_6 , V_3 . V_230 ) ;
F_49 ( L_33 , V_3 . V_230 ) ;
V_3 . V_90 = F_149 ( V_6 , V_3 . V_90 ) ;
F_49 ( L_34 , F_150 ( V_3 . V_90 ) ) ;
}
static int F_151 ( struct V_5 * V_6 )
{
struct V_33 * V_62 = V_6 -> V_12 . V_62 ;
struct V_26 * V_13 = & V_6 -> V_12 ;
int V_27 ;
if ( F_78 () )
return - V_68 ;
F_152 ( V_6 ) ;
F_146 ( V_6 ) ;
V_27 = F_153 ( V_6 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_101 ( V_6 ) ;
if ( V_27 ) {
F_43 ( L_35 ) ;
goto V_231;
}
V_27 = F_105 ( V_6 ) ;
if ( V_27 ) {
F_43 ( L_36 ) ;
goto V_231;
}
V_27 = F_154 ( V_6 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_155 ( V_6 ) ;
if ( V_27 ) {
F_43 ( L_37 ) ;
goto V_231;
}
F_156 ( V_62 ) ;
if ( F_138 ( V_13 ) ) {
V_27 = F_157 ( & V_62 -> V_13 , F_158 ( 30 ) ) ;
if ( V_27 ) {
F_43 ( L_38 ) ;
goto V_231;
}
}
if ( F_159 ( V_13 ) || F_160 ( V_13 ) ) {
V_27 = F_157 ( & V_62 -> V_13 , F_158 ( 32 ) ) ;
if ( V_27 ) {
F_43 ( L_38 ) ;
goto V_231;
}
}
F_161 ( & V_6 -> V_232 , V_233 ,
V_234 ) ;
F_162 ( V_6 ) ;
F_163 ( V_6 ) ;
F_164 ( V_6 ) ;
if ( ! F_165 ( V_13 ) && ! F_166 ( V_13 ) ) {
if ( F_167 ( V_62 ) < 0 )
F_49 ( L_39 ) ;
}
return 0 ;
V_231:
F_168 ( V_6 ) ;
return V_27 ;
}
static void F_169 ( struct V_5 * V_6 )
{
struct V_33 * V_62 = V_6 -> V_12 . V_62 ;
if ( V_62 -> V_235 )
F_170 ( V_62 ) ;
F_171 ( & V_6 -> V_232 ) ;
F_168 ( V_6 ) ;
}
static void F_172 ( struct V_5 * V_6 )
{
struct V_26 * V_13 = & V_6 -> V_12 ;
F_173 ( V_6 ) ;
if ( F_174 ( V_6 ) )
F_175 ( F_176 ( V_236 ) , V_237 ) ;
if ( F_177 ( V_13 , 0 ) == 0 ) {
F_178 ( V_6 ) ;
F_179 ( V_6 ) ;
} else
F_43 ( L_40 ) ;
if ( F_19 ( V_6 ) -> V_35 ) {
F_180 ( V_6 ) ;
F_181 () ;
}
if ( F_9 ( V_6 ) )
F_182 ( V_6 ) ;
F_183 ( V_6 ) ;
F_184 ( V_13 ) ;
}
static void F_185 ( struct V_5 * V_6 )
{
F_186 ( V_6 ) ;
F_187 () ;
F_188 () ;
F_189 ( V_6 ) ;
F_190 ( V_6 ) ;
F_191 ( V_6 ) ;
F_192 ( & V_6 -> V_12 ) ;
F_193 ( V_6 ) ;
}
int F_194 ( struct V_33 * V_62 , const struct V_200 * V_201 )
{
struct V_5 * V_6 ;
int V_27 ;
if ( V_3 . V_238 )
V_239 . V_240 |= V_241 ;
V_27 = - V_179 ;
V_6 = F_195 ( sizeof( * V_6 ) , V_242 ) ;
if ( V_6 )
V_27 = F_196 ( & V_6 -> V_12 , & V_239 , & V_62 -> V_13 ) ;
if ( V_27 ) {
F_4 ( V_15 , & V_62 -> V_13 ,
L_2 V_23 L_41 , V_243 ) ;
F_104 ( V_6 ) ;
return V_27 ;
}
V_6 -> V_12 . V_62 = V_62 ;
V_6 -> V_12 . V_244 = V_6 ;
V_27 = F_197 ( V_62 ) ;
if ( V_27 )
goto V_245;
F_198 ( V_62 , & V_6 -> V_12 ) ;
V_27 = F_117 ( V_6 , V_201 ) ;
if ( V_27 < 0 )
goto V_246;
F_199 ( V_6 ) ;
V_27 = F_142 ( V_6 ) ;
if ( V_27 < 0 )
goto V_247;
V_27 = F_151 ( V_6 ) ;
if ( V_27 < 0 )
goto V_248;
if ( F_19 ( V_6 ) -> V_35 ) {
V_27 = F_200 ( & V_6 -> V_12 ,
F_19 ( V_6 ) -> V_35 ) ;
if ( V_27 )
goto V_249;
}
V_27 = F_77 ( & V_6 -> V_12 ) ;
if ( V_27 < 0 )
goto V_250;
F_172 ( V_6 ) ;
F_201 ( V_6 ) ;
F_2 ( L_42 ,
V_239 . V_132 , V_239 . V_251 , V_239 . V_252 , V_239 . V_253 ,
V_239 . V_254 , F_202 ( V_62 ) , V_6 -> V_12 . V_178 -> V_255 ) ;
F_203 ( V_6 ) ;
return 0 ;
V_250:
F_204 ( & V_6 -> V_12 ) ;
V_249:
F_169 ( V_6 ) ;
V_248:
F_144 ( V_6 ) ;
V_247:
F_203 ( V_6 ) ;
F_135 ( V_6 ) ;
V_246:
F_205 ( V_62 ) ;
V_245:
F_206 ( V_6 , L_43 , V_27 ) ;
F_207 ( & V_6 -> V_12 ) ;
return V_27 ;
}
void F_208 ( struct V_26 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
struct V_33 * V_62 = V_6 -> V_12 . V_62 ;
F_209 ( V_13 ) ;
if ( F_210 ( V_13 ) )
F_43 ( L_44 ) ;
F_211 ( V_6 , V_256 ) ;
F_185 ( V_6 ) ;
F_204 ( V_13 ) ;
F_212 ( V_13 ) ;
if ( V_6 -> V_257 . V_258 && V_6 -> V_257 . V_259 ) {
F_104 ( V_6 -> V_257 . V_258 ) ;
V_6 -> V_257 . V_258 = NULL ;
V_6 -> V_257 . V_259 = 0 ;
}
F_104 ( V_6 -> V_257 . V_260 ) ;
V_6 -> V_257 . V_260 = NULL ;
F_104 ( V_6 -> V_257 . V_261 ) ;
V_6 -> V_257 . V_261 = NULL ;
F_100 ( V_62 ) ;
F_80 ( V_62 , NULL , NULL , NULL ) ;
F_98 ( V_6 ) ;
F_213 ( & V_6 -> V_210 . V_262 ) ;
F_214 ( V_13 ) ;
F_215 ( V_6 -> V_195 ) ;
F_95 ( V_13 ) ;
F_69 ( V_13 ) ;
F_216 ( V_6 ) ;
F_99 ( V_6 ) ;
F_169 ( V_6 ) ;
F_144 ( V_6 ) ;
F_217 ( V_6 , V_256 ) ;
F_135 ( V_6 ) ;
}
static int F_218 ( struct V_26 * V_13 , struct V_60 * V_263 )
{
int V_27 ;
V_27 = F_219 ( V_13 , V_263 ) ;
if ( V_27 )
return V_27 ;
return 0 ;
}
static void F_220 ( struct V_26 * V_13 )
{
F_221 ( V_13 ) ;
F_222 () ;
}
static void F_223 ( struct V_26 * V_13 , struct V_60 * V_263 )
{
F_72 ( & V_13 -> V_166 ) ;
F_224 ( V_13 , V_263 ) ;
F_225 ( V_13 , V_263 ) ;
F_75 ( & V_13 -> V_166 ) ;
}
static void F_226 ( struct V_26 * V_13 , struct V_60 * V_263 )
{
struct V_264 * V_61 = V_263 -> V_265 ;
F_104 ( V_61 ) ;
}
static void F_227 ( struct V_5 * V_6 )
{
struct V_26 * V_13 = & V_6 -> V_12 ;
struct V_266 * V_267 ;
F_228 ( V_13 ) ;
F_229 (dev, encoder)
if ( V_267 -> V_268 )
V_267 -> V_268 ( V_267 ) ;
F_230 ( V_13 ) ;
}
static bool F_231 ( struct V_5 * V_6 )
{
#if F_232 ( V_269 )
if ( F_233 () < V_270 )
return true ;
#endif
return false ;
}
static int F_234 ( struct V_26 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
struct V_33 * V_62 = V_6 -> V_12 . V_62 ;
T_6 V_271 ;
int error ;
F_72 ( & V_6 -> V_218 ) ;
V_6 -> V_272 = V_273 ;
F_75 ( & V_6 -> V_218 ) ;
F_235 ( V_6 ) ;
F_236 ( V_6 , true ) ;
F_237 ( V_13 ) ;
F_238 ( V_62 ) ;
error = F_210 ( V_13 ) ;
if ( error ) {
F_239 ( & V_62 -> V_13 ,
L_45 ) ;
goto V_168;
}
F_240 ( V_13 ) ;
F_241 ( V_13 ) ;
F_242 ( V_13 ) ;
F_243 ( V_6 ) ;
F_244 ( V_6 ) ;
F_227 ( V_6 ) ;
F_245 ( V_13 ) ;
F_246 ( V_13 ) ;
F_247 ( V_13 ) ;
V_271 = F_231 ( V_6 ) ? V_274 : V_275 ;
F_248 ( V_6 , V_271 ) ;
F_249 ( V_6 , false ) ;
F_189 ( V_6 ) ;
F_250 ( V_13 , V_276 , true ) ;
V_6 -> V_277 ++ ;
F_251 ( V_6 ) ;
V_168:
F_252 ( V_6 ) ;
return error ;
}
static int F_253 ( struct V_26 * V_13 , bool V_278 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
struct V_33 * V_62 = V_6 -> V_12 . V_62 ;
bool V_279 ;
int V_27 ;
F_235 ( V_6 ) ;
F_236 ( V_6 , false ) ;
V_279 = ! F_254 ( V_6 ) &&
F_231 ( V_6 ) && V_6 -> V_280 . V_281 ;
if ( ! V_279 )
F_255 ( V_6 ) ;
V_27 = 0 ;
if ( F_254 ( V_6 ) )
F_256 ( V_6 ) ;
else if ( F_13 ( V_6 ) || F_14 ( V_6 ) )
F_257 ( V_6 ) ;
else if ( F_54 ( V_6 ) || F_55 ( V_6 ) )
V_27 = F_258 ( V_6 ) ;
if ( V_27 ) {
F_43 ( L_46 , V_27 ) ;
if ( ! V_279 )
F_84 ( V_6 , true ) ;
goto V_168;
}
F_205 ( V_62 ) ;
if ( ! ( V_278 && F_19 ( V_6 ) -> V_124 < 6 ) )
F_65 ( V_62 , V_282 ) ;
V_6 -> V_283 = F_231 ( V_6 ) ;
V_168:
F_252 ( V_6 ) ;
return V_27 ;
}
int F_67 ( struct V_26 * V_13 , T_5 V_148 )
{
int error ;
if ( ! V_13 ) {
F_43 ( L_47 , V_13 ) ;
F_43 ( L_48 ) ;
return - V_68 ;
}
if ( F_259 ( V_148 . V_155 != V_156 &&
V_148 . V_155 != V_284 ) )
return - V_120 ;
if ( V_13 -> V_158 == V_162 )
return 0 ;
error = F_234 ( V_13 ) ;
if ( error )
return error ;
return F_253 ( V_13 , false ) ;
}
static int F_260 ( struct V_26 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
int V_27 ;
F_235 ( V_6 ) ;
F_261 ( V_6 ) ;
V_27 = F_155 ( V_6 ) ;
if ( V_27 )
F_43 ( L_49 ) ;
F_262 ( V_6 ) ;
F_263 ( V_13 ) ;
F_264 ( V_13 ) ;
F_265 ( V_6 ) ;
F_163 ( V_6 ) ;
F_266 ( V_13 ) ;
F_267 ( V_13 ) ;
F_268 ( V_6 ) ;
F_72 ( & V_13 -> V_166 ) ;
if ( F_269 ( V_13 ) ) {
F_43 ( L_50 ) ;
F_270 ( V_6 ) ;
}
F_75 ( & V_13 -> V_166 ) ;
F_271 ( V_13 ) ;
F_272 ( V_13 ) ;
F_273 ( & V_6 -> V_209 ) ;
if ( V_6 -> V_285 . V_286 )
V_6 -> V_285 . V_286 ( V_6 ) ;
F_274 ( & V_6 -> V_209 ) ;
F_275 ( V_13 ) ;
F_276 ( V_13 ) ;
F_93 ( V_6 ) ;
F_277 ( V_13 ) ;
F_180 ( V_6 ) ;
F_250 ( V_13 , V_287 , false ) ;
F_72 ( & V_6 -> V_218 ) ;
V_6 -> V_272 = V_288 ;
F_75 ( & V_6 -> V_218 ) ;
F_248 ( V_6 , V_160 ) ;
F_278 ( V_6 ) ;
F_279 ( V_13 ) ;
F_252 ( V_6 ) ;
return 0 ;
}
static int F_280 ( struct V_26 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
struct V_33 * V_62 = V_6 -> V_12 . V_62 ;
int V_27 ;
V_27 = F_65 ( V_62 , V_160 ) ;
if ( V_27 ) {
F_43 ( L_51 , V_27 ) ;
goto V_168;
}
if ( F_197 ( V_62 ) ) {
V_27 = - V_227 ;
goto V_168;
}
F_156 ( V_62 ) ;
F_235 ( V_6 ) ;
if ( F_54 ( V_6 ) || F_55 ( V_6 ) )
V_27 = F_281 ( V_6 , false ) ;
if ( V_27 )
F_43 ( L_52 ,
V_27 ) ;
F_282 ( V_6 , true ) ;
if ( F_254 ( V_6 ) ) {
if ( ! V_6 -> V_283 )
F_283 ( V_6 ) ;
F_284 ( V_6 ) ;
} else if ( F_13 ( V_6 ) || F_14 ( V_6 ) ) {
F_285 ( V_6 ) ;
}
F_162 ( V_6 ) ;
if ( F_254 ( V_6 ) ||
! ( V_6 -> V_283 && V_6 -> V_280 . V_281 ) )
F_84 ( V_6 , true ) ;
F_252 ( V_6 ) ;
V_168:
V_6 -> V_283 = false ;
return V_27 ;
}
int F_66 ( struct V_26 * V_13 )
{
int V_27 ;
if ( V_13 -> V_158 == V_162 )
return 0 ;
V_27 = F_280 ( V_13 ) ;
if ( V_27 )
return V_27 ;
return F_260 ( V_13 ) ;
}
void F_286 ( struct V_5 * V_6 )
{
struct V_26 * V_13 = & V_6 -> V_12 ;
struct V_289 * error = & V_6 -> V_210 ;
int V_27 ;
F_287 ( & V_13 -> V_166 ) ;
if ( ! F_288 ( V_290 , & error -> V_133 ) )
return;
F_289 ( V_291 , & error -> V_133 ) ;
error -> V_292 ++ ;
F_290 ( L_53 ) ;
V_27 = F_71 ( V_6 , V_165 ) ;
if ( V_27 ) {
if ( V_27 != - V_68 )
F_43 ( L_54 , V_27 ) ;
else
F_49 ( L_55 ) ;
goto error;
}
F_291 ( V_6 ) ;
F_292 ( V_6 ) ;
V_27 = F_269 ( V_13 ) ;
if ( V_27 ) {
F_43 ( L_56 , V_27 ) ;
goto error;
}
V_293:
F_293 ( & error -> V_133 , V_290 ) ;
return;
error:
F_270 ( V_6 ) ;
goto V_293;
}
static int F_294 ( struct V_10 * V_11 )
{
struct V_33 * V_62 = F_295 ( V_11 ) ;
struct V_26 * V_13 = F_63 ( V_62 ) ;
if ( ! V_13 ) {
F_239 ( V_11 , L_48 ) ;
return - V_68 ;
}
if ( V_13 -> V_158 == V_162 )
return 0 ;
return F_234 ( V_13 ) ;
}
static int F_296 ( struct V_10 * V_11 )
{
struct V_26 * V_13 = & F_297 ( V_11 ) -> V_12 ;
if ( V_13 -> V_158 == V_162 )
return 0 ;
return F_253 ( V_13 , false ) ;
}
static int F_298 ( struct V_10 * V_11 )
{
struct V_26 * V_13 = & F_297 ( V_11 ) -> V_12 ;
if ( V_13 -> V_158 == V_162 )
return 0 ;
return F_253 ( V_13 , true ) ;
}
static int F_299 ( struct V_10 * V_11 )
{
struct V_26 * V_13 = & F_297 ( V_11 ) -> V_12 ;
if ( V_13 -> V_158 == V_162 )
return 0 ;
return F_280 ( V_13 ) ;
}
static int F_300 ( struct V_10 * V_11 )
{
struct V_26 * V_13 = & F_297 ( V_11 ) -> V_12 ;
if ( V_13 -> V_158 == V_162 )
return 0 ;
return F_260 ( V_13 ) ;
}
static int F_301 ( struct V_10 * V_11 )
{
int V_27 ;
V_27 = F_294 ( V_11 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_302 ( F_297 ( V_11 ) ) ;
if ( V_27 )
return V_27 ;
return 0 ;
}
static int F_303 ( struct V_10 * V_11 )
{
int V_27 ;
V_27 = F_296 ( V_11 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_304 ( F_297 ( V_11 ) ) ;
if ( V_27 )
return V_27 ;
return 0 ;
}
static int F_305 ( struct V_10 * V_11 )
{
return F_299 ( V_11 ) ;
}
static int F_306 ( struct V_10 * V_11 )
{
return F_300 ( V_11 ) ;
}
static int F_307 ( struct V_10 * V_11 )
{
return F_299 ( V_11 ) ;
}
static int F_308 ( struct V_10 * V_11 )
{
return F_300 ( V_11 ) ;
}
static void F_309 ( struct V_5 * V_6 )
{
struct V_294 * V_295 = & V_6 -> V_294 ;
int V_296 ;
V_295 -> V_297 = F_310 ( V_298 ) ;
V_295 -> V_299 = F_310 ( V_300 ) ;
V_295 -> V_301 = F_310 ( V_302 ) ;
V_295 -> V_303 = F_310 ( V_304 ) ;
V_295 -> V_305 = F_310 ( V_306 ) ;
for ( V_296 = 0 ; V_296 < F_311 ( V_295 -> V_307 ) ; V_296 ++ )
V_295 -> V_307 [ V_296 ] = F_310 ( F_312 ( V_296 ) ) ;
V_295 -> V_308 = F_310 ( V_309 ) ;
V_295 -> V_310 = F_310 ( V_311 ) ;
V_295 -> V_312 = F_310 ( V_313 ) ;
V_295 -> V_314 = F_310 ( V_315 ) ;
V_295 -> V_316 = F_310 ( V_317 ) ;
V_295 -> V_318 = F_310 ( V_319 ) ;
V_295 -> V_320 = F_310 ( V_321 ) ;
V_295 -> V_322 = F_310 ( V_323 ) ;
V_295 -> V_324 = F_310 ( V_325 ) ;
V_295 -> V_326 = F_310 ( V_327 ) ;
V_295 -> V_328 = F_310 ( V_329 ) ;
V_295 -> V_330 = F_310 ( V_331 ) ;
V_295 -> V_332 = F_310 ( V_333 ) ;
V_295 -> V_334 = F_310 ( V_335 ) ;
V_295 -> V_336 = F_310 ( V_337 ) ;
V_295 -> V_338 = F_310 ( V_339 ) ;
V_295 -> V_340 = F_310 ( V_341 ) ;
V_295 -> V_342 = F_310 ( V_343 ) ;
V_295 -> V_344 = F_310 ( V_345 ) ;
V_295 -> V_346 = F_310 ( V_347 ) ;
V_295 -> V_348 = F_310 ( V_349 ) ;
V_295 -> V_350 = F_310 ( V_351 ) ;
V_295 -> V_352 = F_310 ( V_353 ) ;
V_295 -> V_354 = F_310 ( V_355 ) ;
V_295 -> V_356 = F_310 ( V_357 ) ;
V_295 -> V_358 = F_310 ( V_359 ) ;
V_295 -> V_360 = F_310 ( V_361 ) ;
V_295 -> V_362 = F_310 ( V_363 ) ;
V_295 -> V_364 = F_310 ( V_365 ) ;
V_295 -> V_366 = F_310 ( V_367 ) ;
for ( V_296 = 0 ; V_296 < F_311 ( V_295 -> V_368 ) ; V_296 ++ )
V_295 -> V_368 [ V_296 ] = F_310 ( F_313 ( V_296 ) ) ;
V_295 -> V_369 = F_310 ( V_370 ) ;
V_295 -> V_371 = F_310 ( V_372 ) ;
V_295 -> V_373 = F_310 ( V_374 ) ;
V_295 -> V_375 = F_310 ( V_376 ) ;
V_295 -> V_377 = F_310 ( V_378 ) ;
V_295 -> V_379 = F_310 ( V_380 ) ;
V_295 -> V_381 = F_310 ( V_382 ) ;
V_295 -> V_383 = F_310 ( V_384 ) ;
V_295 -> V_385 = F_310 ( V_386 ) ;
}
static void F_314 ( struct V_5 * V_6 )
{
struct V_294 * V_295 = & V_6 -> V_294 ;
T_3 V_387 ;
int V_296 ;
F_175 ( V_298 , V_295 -> V_297 ) ;
F_175 ( V_300 , V_295 -> V_299 ) ;
F_175 ( V_302 , V_295 -> V_301 | ( 0xffff << 16 ) ) ;
F_175 ( V_304 , V_295 -> V_303 ) ;
F_175 ( V_306 , V_295 -> V_305 ) ;
for ( V_296 = 0 ; V_296 < F_311 ( V_295 -> V_307 ) ; V_296 ++ )
F_175 ( F_312 ( V_296 ) , V_295 -> V_307 [ V_296 ] ) ;
F_175 ( V_309 , V_295 -> V_308 ) ;
F_175 ( V_311 , V_295 -> V_310 ) ;
F_175 ( V_313 , V_295 -> V_312 ) ;
F_175 ( V_315 , V_295 -> V_314 ) ;
F_175 ( V_317 , V_295 -> V_316 ) ;
F_175 ( V_319 , V_295 -> V_318 ) ;
F_175 ( V_321 , V_295 -> V_320 ) ;
F_175 ( V_323 , V_295 -> V_322 ) ;
F_175 ( V_325 , V_295 -> V_324 ) ;
F_175 ( V_327 , V_295 -> V_326 ) ;
F_175 ( V_329 , V_295 -> V_328 ) ;
F_175 ( V_331 , V_295 -> V_330 ) ;
F_175 ( V_333 , V_295 -> V_332 ) ;
F_175 ( V_335 , V_295 -> V_334 ) ;
F_175 ( V_337 , V_295 -> V_336 ) ;
F_175 ( V_339 , V_295 -> V_338 ) ;
F_175 ( V_341 , V_295 -> V_340 ) ;
F_175 ( V_343 , V_295 -> V_342 ) ;
F_175 ( V_345 , V_295 -> V_344 ) ;
F_175 ( V_347 , V_295 -> V_346 ) ;
F_175 ( V_349 , V_295 -> V_348 ) ;
F_175 ( V_351 , V_295 -> V_350 ) ;
F_175 ( V_353 , V_295 -> V_352 ) ;
F_175 ( V_355 , V_295 -> V_354 ) ;
F_175 ( V_357 , V_295 -> V_356 ) ;
F_175 ( V_359 , V_295 -> V_358 ) ;
F_175 ( V_361 , V_295 -> V_360 ) ;
F_175 ( V_363 , V_295 -> V_362 ) ;
F_175 ( V_365 , V_295 -> V_364 ) ;
F_175 ( V_367 , V_295 -> V_366 ) ;
for ( V_296 = 0 ; V_296 < F_311 ( V_295 -> V_368 ) ; V_296 ++ )
F_175 ( F_313 ( V_296 ) , V_295 -> V_368 [ V_296 ] ) ;
F_175 ( V_370 , V_295 -> V_369 ) ;
F_175 ( V_372 , V_295 -> V_371 ) ;
V_387 = F_310 ( V_374 ) ;
V_387 &= V_388 ;
V_387 |= V_295 -> V_373 & ~ V_388 ;
F_175 ( V_374 , V_387 ) ;
V_387 = F_310 ( V_376 ) ;
V_387 &= V_389 ;
V_387 |= V_295 -> V_375 & ~ V_389 ;
F_175 ( V_376 , V_387 ) ;
F_175 ( V_378 , V_295 -> V_377 ) ;
F_175 ( V_380 , V_295 -> V_379 ) ;
F_175 ( V_382 , V_295 -> V_381 ) ;
F_175 ( V_384 , V_295 -> V_383 ) ;
F_175 ( V_386 , V_295 -> V_385 ) ;
}
int F_315 ( struct V_5 * V_6 , bool V_390 )
{
T_3 V_387 ;
int V_391 ;
V_387 = F_310 ( V_376 ) ;
V_387 &= ~ V_389 ;
if ( V_390 )
V_387 |= V_389 ;
F_175 ( V_376 , V_387 ) ;
if ( ! V_390 )
return 0 ;
V_391 = F_316 ( V_6 ,
V_376 ,
V_392 ,
V_392 ,
20 ) ;
if ( V_391 )
F_43 ( L_57 ,
F_310 ( V_376 ) ) ;
return V_391 ;
}
static int F_317 ( struct V_5 * V_6 , bool V_393 )
{
T_3 V_387 ;
int V_391 = 0 ;
V_387 = F_310 ( V_374 ) ;
V_387 &= ~ V_388 ;
if ( V_393 )
V_387 |= V_388 ;
F_175 ( V_374 , V_387 ) ;
F_318 ( V_374 ) ;
V_391 = F_316 ( V_6 ,
V_394 ,
V_395 ,
V_393 ,
1 ) ;
if ( V_391 )
F_43 ( L_58 ) ;
return V_391 ;
}
static int F_319 ( struct V_5 * V_6 ,
bool V_396 )
{
T_3 V_397 ;
T_3 V_387 ;
int V_391 ;
V_397 = V_398 | V_399 ;
V_387 = V_396 ? V_397 : 0 ;
if ( ( F_310 ( V_394 ) & V_397 ) == V_387 )
return 0 ;
F_10 ( L_59 ,
F_320 ( V_396 ) ,
F_310 ( V_394 ) ) ;
V_391 = F_316 ( V_6 ,
V_394 , V_397 , V_387 ,
3 ) ;
if ( V_391 )
F_43 ( L_60 ,
F_320 ( V_396 ) ) ;
return V_391 ;
}
static void F_321 ( struct V_5 * V_6 )
{
if ( ! ( F_310 ( V_394 ) & V_400 ) )
return;
F_49 ( L_61 ) ;
F_175 ( V_394 , V_400 ) ;
}
static int F_258 ( struct V_5 * V_6 )
{
T_3 V_397 ;
int V_391 ;
( void ) F_319 ( V_6 , false ) ;
V_397 = V_401 | V_402 ;
F_21 ( ( F_310 ( V_374 ) & V_397 ) != V_397 ) ;
F_321 ( V_6 ) ;
V_391 = F_315 ( V_6 , true ) ;
if ( V_391 )
goto V_403;
V_391 = F_317 ( V_6 , false ) ;
if ( V_391 )
goto V_404;
if ( ! F_55 ( V_6 ) )
F_309 ( V_6 ) ;
V_391 = F_315 ( V_6 , false ) ;
if ( V_391 )
goto V_404;
return 0 ;
V_404:
F_317 ( V_6 , true ) ;
V_403:
F_315 ( V_6 , false ) ;
return V_391 ;
}
static int F_281 ( struct V_5 * V_6 ,
bool V_405 )
{
struct V_26 * V_13 = & V_6 -> V_12 ;
int V_391 ;
int V_27 ;
V_27 = F_315 ( V_6 , true ) ;
if ( ! F_55 ( V_6 ) )
F_314 ( V_6 ) ;
V_391 = F_317 ( V_6 , true ) ;
if ( ! V_27 )
V_27 = V_391 ;
V_391 = F_315 ( V_6 , false ) ;
if ( ! V_27 )
V_27 = V_391 ;
F_321 ( V_6 ) ;
if ( V_405 ) {
F_322 ( V_13 ) ;
F_323 ( V_13 ) ;
}
return V_27 ;
}
static int F_324 ( struct V_10 * V_11 )
{
struct V_33 * V_62 = F_295 ( V_11 ) ;
struct V_26 * V_13 = F_63 ( V_62 ) ;
struct V_5 * V_6 = F_18 ( V_13 ) ;
int V_27 ;
if ( F_259 ( ! ( V_6 -> V_406 . V_141 && F_325 () ) ) )
return - V_68 ;
if ( F_259 ( ! F_326 ( V_13 ) ) )
return - V_68 ;
F_10 ( L_62 ) ;
if ( ! F_327 ( & V_13 -> V_166 ) ) {
F_10 ( L_63 ) ;
F_328 ( V_11 ) ;
return - V_407 ;
}
F_235 ( V_6 ) ;
F_329 ( V_6 ) ;
F_75 ( & V_13 -> V_166 ) ;
F_240 ( V_13 ) ;
F_243 ( V_6 ) ;
V_27 = 0 ;
if ( F_254 ( V_6 ) ) {
F_330 ( V_6 ) ;
F_256 ( V_6 ) ;
} else if ( F_13 ( V_6 ) || F_14 ( V_6 ) ) {
F_257 ( V_6 ) ;
} else if ( F_54 ( V_6 ) || F_55 ( V_6 ) ) {
V_27 = F_258 ( V_6 ) ;
}
if ( V_27 ) {
F_43 ( L_64 , V_27 ) ;
F_268 ( V_6 ) ;
F_252 ( V_6 ) ;
return V_27 ;
}
F_249 ( V_6 , false ) ;
F_252 ( V_6 ) ;
F_259 ( F_331 ( & V_6 -> V_408 . V_409 ) ) ;
if ( F_332 ( V_6 ) )
F_43 ( L_65 ) ;
V_6 -> V_408 . V_410 = true ;
if ( F_14 ( V_6 ) ) {
F_248 ( V_6 , V_282 ) ;
} else {
F_248 ( V_6 , V_274 ) ;
}
F_333 ( V_6 ) ;
if ( ! F_54 ( V_6 ) || ! F_55 ( V_6 ) )
F_334 ( V_6 ) ;
F_10 ( L_66 ) ;
return 0 ;
}
static int F_335 ( struct V_10 * V_11 )
{
struct V_33 * V_62 = F_295 ( V_11 ) ;
struct V_26 * V_13 = F_63 ( V_62 ) ;
struct V_5 * V_6 = F_18 ( V_13 ) ;
int V_27 = 0 ;
if ( F_259 ( ! F_326 ( V_13 ) ) )
return - V_68 ;
F_10 ( L_67 ) ;
F_259 ( F_331 ( & V_6 -> V_408 . V_409 ) ) ;
F_235 ( V_6 ) ;
F_248 ( V_6 , V_160 ) ;
V_6 -> V_408 . V_410 = false ;
if ( F_336 ( V_6 ) )
F_49 ( L_68 ) ;
F_271 ( V_13 ) ;
if ( F_11 ( V_6 ) )
F_266 ( V_13 ) ;
if ( F_254 ( V_13 ) ) {
F_284 ( V_6 ) ;
F_337 ( V_6 , true ) ;
if ( V_6 -> V_280 . V_281 &&
( V_6 -> V_280 . V_411 & V_412 ) )
F_338 ( V_6 ) ;
} else if ( F_13 ( V_6 ) || F_14 ( V_6 ) ) {
F_285 ( V_6 ) ;
} else if ( F_54 ( V_6 ) || F_55 ( V_6 ) ) {
V_27 = F_281 ( V_6 , true ) ;
}
F_339 ( V_13 ) ;
F_268 ( V_6 ) ;
if ( ! F_54 ( V_6 ) && ! F_55 ( V_6 ) )
F_93 ( V_6 ) ;
F_252 ( V_6 ) ;
if ( V_27 )
F_43 ( L_69 , V_27 ) ;
else
F_10 ( L_70 ) ;
return V_27 ;
}
static int
F_340 ( struct V_26 * V_13 , void * V_59 ,
struct V_60 * V_263 )
{
return - V_68 ;
}
