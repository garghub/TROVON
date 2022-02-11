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
static enum V_25 F_8 ( struct V_5 * V_6 )
{
enum V_25 V_26 = V_27 ;
if ( F_9 ( V_6 ) ) {
V_26 = V_28 ;
F_10 ( L_5 ) ;
} else if ( F_11 ( V_6 ) || F_12 ( V_6 ) ) {
V_26 = V_29 ;
F_10 ( L_6 ) ;
} else if ( F_13 ( V_6 ) || F_14 ( V_6 ) ) {
V_26 = V_30 ;
F_10 ( L_7 ) ;
} else if ( F_15 ( V_6 ) || F_16 ( V_6 ) ) {
V_26 = V_31 ;
F_10 ( L_8 ) ;
}
return V_26 ;
}
static void F_17 ( struct V_5 * V_6 )
{
struct V_32 * V_33 = NULL ;
if ( F_18 ( V_6 ) -> V_34 == 0 ) {
V_6 -> V_35 = V_27 ;
return;
}
while ( ( V_33 = F_19 ( V_36 << 8 , V_33 ) ) ) {
if ( V_33 -> V_37 == V_38 ) {
unsigned short V_39 = V_33 -> V_10 & V_40 ;
V_6 -> V_41 = V_39 ;
if ( V_39 == V_42 ) {
V_6 -> V_35 = V_28 ;
F_10 ( L_9 ) ;
F_20 ( ! F_9 ( V_6 ) ) ;
} else if ( V_39 == V_43 ) {
V_6 -> V_35 = V_29 ;
F_10 ( L_10 ) ;
F_20 ( ! ( F_11 ( V_6 ) ||
F_12 ( V_6 ) ) ) ;
} else if ( V_39 == V_44 ) {
V_6 -> V_35 = V_29 ;
F_10 ( L_11 ) ;
F_20 ( ! ( F_11 ( V_6 ) ||
F_12 ( V_6 ) ) ) ;
} else if ( V_39 == V_45 ) {
V_6 -> V_35 = V_30 ;
F_10 ( L_12 ) ;
F_20 ( ! F_13 ( V_6 ) &&
! F_14 ( V_6 ) ) ;
F_20 ( F_21 ( V_6 ) ||
F_22 ( V_6 ) ) ;
} else if ( V_39 == V_46 ) {
V_6 -> V_35 = V_30 ;
F_10 ( L_13 ) ;
F_20 ( ! F_13 ( V_6 ) &&
! F_14 ( V_6 ) ) ;
F_20 ( ! F_21 ( V_6 ) &&
! F_22 ( V_6 ) ) ;
} else if ( V_39 == V_47 ) {
V_6 -> V_35 = V_31 ;
F_10 ( L_14 ) ;
F_20 ( ! F_15 ( V_6 ) &&
! F_16 ( V_6 ) ) ;
} else if ( V_39 == V_48 ) {
V_6 -> V_35 = V_31 ;
F_10 ( L_15 ) ;
F_20 ( ! F_15 ( V_6 ) &&
! F_16 ( V_6 ) ) ;
} else if ( V_39 == V_49 ) {
V_6 -> V_35 = V_50 ;
F_10 ( L_16 ) ;
F_20 ( ! F_15 ( V_6 ) &&
! F_16 ( V_6 ) ) ;
} else if ( ( V_39 == V_51 ) ||
( V_39 == V_52 ) ||
( ( V_39 == V_53 ) &&
V_33 -> V_54 ==
V_55 &&
V_33 -> V_56 ==
V_57 ) ) {
V_6 -> V_35 =
F_8 ( V_6 ) ;
} else
continue;
break;
}
}
if ( ! V_33 )
F_10 ( L_17 ) ;
F_23 ( V_33 ) ;
}
static int F_24 ( struct V_58 * V_13 , void * V_59 ,
struct V_60 * V_61 )
{
struct V_5 * V_6 = F_25 ( V_13 ) ;
struct V_32 * V_62 = V_6 -> V_12 . V_62 ;
T_2 * V_63 = V_59 ;
int V_64 ;
switch ( V_63 -> V_63 ) {
case V_65 :
case V_66 :
case V_67 :
case V_68 :
return - V_69 ;
case V_70 :
V_64 = V_62 -> V_10 ;
break;
case V_71 :
V_64 = V_62 -> V_72 ;
break;
case V_73 :
V_64 = V_6 -> V_74 ;
break;
case V_75 :
V_64 = V_6 -> V_76 ? 1 : 0 ;
break;
case V_77 :
V_64 = ! ! V_6 -> V_78 [ V_79 ] ;
break;
case V_80 :
V_64 = ! ! V_6 -> V_78 [ V_81 ] ;
break;
case V_82 :
V_64 = ! ! V_6 -> V_78 [ V_83 ] ;
break;
case V_84 :
V_64 = ! ! V_6 -> V_78 [ V_85 ] ;
break;
case V_86 :
V_64 = F_26 ( V_6 ) ;
break;
case V_87 :
V_64 = F_27 ( V_6 ) ;
break;
case V_88 :
V_64 = F_28 ( V_6 ) ;
break;
case V_89 :
V_64 = V_3 . V_90 ;
break;
case V_91 :
V_64 = F_29 ( V_92 ) ;
break;
case V_93 :
V_64 = F_30 ( V_6 ) ;
break;
case V_94 :
V_64 = F_31 ( & F_18 ( V_6 ) -> V_95 ) ;
if ( ! V_64 )
return - V_69 ;
break;
case V_96 :
V_64 = F_18 ( V_6 ) -> V_95 . V_97 ;
if ( ! V_64 )
return - V_69 ;
break;
case V_98 :
V_64 = V_3 . V_99 && F_32 ( V_6 ) ;
break;
case V_100 :
V_64 = F_33 ( V_6 ) ;
break;
case V_101 :
V_64 = F_34 ( V_6 ) ;
break;
case V_102 :
V_64 = F_18 ( V_6 ) -> V_95 . V_103 ;
break;
case V_104 :
V_64 = F_35 ( V_105 ) & V_106 ;
break;
case V_107 :
V_64 = F_36 () ;
break;
case V_108 :
V_64 = V_6 -> V_78 [ V_109 ] &&
V_6 -> V_78 [ V_109 ] -> V_110 ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
V_64 = 1 ;
break;
default:
F_37 ( L_18 , V_63 -> V_63 ) ;
return - V_126 ;
}
if ( F_38 ( V_64 , V_63 -> V_64 ) )
return - V_127 ;
return 0 ;
}
static int F_39 ( struct V_5 * V_6 )
{
V_6 -> V_128 = F_40 ( 0 , F_41 ( 0 , 0 ) ) ;
if ( ! V_6 -> V_128 ) {
F_42 ( L_19 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_43 ( struct V_5 * V_6 )
{
int V_129 = F_44 ( V_6 ) >= 4 ? V_130 : V_131 ;
T_3 V_132 , V_133 = 0 ;
T_4 V_134 ;
int V_26 ;
if ( F_44 ( V_6 ) >= 4 )
F_45 ( V_6 -> V_128 , V_129 + 4 , & V_133 ) ;
F_45 ( V_6 -> V_128 , V_129 , & V_132 ) ;
V_134 = ( ( T_4 ) V_133 << 32 ) | V_132 ;
#ifdef F_46
if ( V_134 &&
F_47 ( V_134 , V_134 + V_135 ) )
return 0 ;
#endif
V_6 -> V_136 . V_137 = L_20 ;
V_6 -> V_136 . V_138 = V_139 ;
V_26 = F_48 ( V_6 -> V_128 -> V_140 ,
& V_6 -> V_136 ,
V_135 , V_135 ,
V_141 ,
0 , V_142 ,
V_6 -> V_128 ) ;
if ( V_26 ) {
F_49 ( L_21 , V_26 ) ;
V_6 -> V_136 . V_143 = 0 ;
return V_26 ;
}
if ( F_44 ( V_6 ) >= 4 )
F_50 ( V_6 -> V_128 , V_129 + 4 ,
F_51 ( V_6 -> V_136 . V_143 ) ) ;
F_50 ( V_6 -> V_128 , V_129 ,
F_52 ( V_6 -> V_136 . V_143 ) ) ;
return 0 ;
}
static void
F_53 ( struct V_5 * V_6 )
{
int V_144 = F_44 ( V_6 ) >= 4 ? V_130 : V_131 ;
T_3 V_145 ;
bool V_146 ;
if ( F_54 ( V_6 ) || F_55 ( V_6 ) )
return;
V_6 -> V_147 = false ;
if ( F_56 ( V_6 ) || F_57 ( V_6 ) ) {
F_45 ( V_6 -> V_128 , V_148 , & V_145 ) ;
V_146 = ! ! ( V_145 & V_149 ) ;
} else {
F_45 ( V_6 -> V_128 , V_144 , & V_145 ) ;
V_146 = V_145 & 1 ;
}
if ( V_146 )
return;
if ( F_43 ( V_6 ) )
return;
V_6 -> V_147 = true ;
if ( F_56 ( V_6 ) || F_57 ( V_6 ) ) {
F_50 ( V_6 -> V_128 , V_148 ,
V_145 | V_149 ) ;
} else {
F_45 ( V_6 -> V_128 , V_144 , & V_145 ) ;
F_50 ( V_6 -> V_128 , V_144 , V_145 | 1 ) ;
}
}
static void
F_58 ( struct V_5 * V_6 )
{
int V_144 = F_44 ( V_6 ) >= 4 ? V_130 : V_131 ;
if ( V_6 -> V_147 ) {
if ( F_56 ( V_6 ) || F_57 ( V_6 ) ) {
T_3 V_150 ;
F_45 ( V_6 -> V_128 , V_148 ,
& V_150 ) ;
V_150 &= ~ V_149 ;
F_50 ( V_6 -> V_128 , V_148 ,
V_150 ) ;
} else {
T_3 V_151 ;
F_45 ( V_6 -> V_128 , V_144 ,
& V_151 ) ;
V_151 &= ~ 1 ;
F_50 ( V_6 -> V_128 , V_144 ,
V_151 ) ;
}
}
if ( V_6 -> V_136 . V_143 )
F_59 ( & V_6 -> V_136 ) ;
}
static unsigned int F_60 ( void * V_152 , bool V_153 )
{
struct V_5 * V_6 = V_152 ;
F_61 ( V_6 , V_153 ) ;
if ( V_153 )
return V_154 | V_155 |
V_156 | V_157 ;
else
return V_156 | V_157 ;
}
static void F_62 ( struct V_32 * V_62 , enum V_158 V_153 )
{
struct V_58 * V_13 = F_63 ( V_62 ) ;
T_5 V_159 = { . V_160 = V_161 } ;
if ( V_153 == V_162 ) {
F_64 ( L_22 ) ;
V_13 -> V_163 = V_164 ;
F_65 ( V_62 , V_165 ) ;
F_66 ( V_13 ) ;
V_13 -> V_163 = V_166 ;
} else {
F_64 ( L_23 ) ;
V_13 -> V_163 = V_164 ;
F_67 ( V_13 , V_159 ) ;
V_13 -> V_163 = V_167 ;
}
}
static bool F_68 ( struct V_32 * V_62 )
{
struct V_58 * V_13 = F_63 ( V_62 ) ;
return V_13 -> V_168 == 0 ;
}
static void F_69 ( struct V_5 * V_6 )
{
F_70 ( & V_6 -> V_12 . V_169 ) ;
F_71 ( V_6 ) ;
F_72 ( V_6 ) ;
F_73 ( & V_6 -> V_12 . V_169 ) ;
F_74 ( V_6 ) ;
F_20 ( ! F_75 ( & V_6 -> V_170 ) ) ;
}
static int F_76 ( struct V_58 * V_13 )
{
struct V_5 * V_6 = F_25 ( V_13 ) ;
struct V_32 * V_62 = V_6 -> V_12 . V_62 ;
int V_26 ;
if ( F_77 () )
return - V_69 ;
V_26 = F_78 ( V_6 ) ;
if ( V_26 )
F_2 ( L_24 ) ;
V_26 = F_79 ( V_62 , V_6 , NULL , F_60 ) ;
if ( V_26 && V_26 != - V_69 )
goto V_171;
F_80 () ;
V_26 = F_81 ( V_62 , & V_172 , false ) ;
if ( V_26 )
goto V_173;
F_82 ( V_6 ) ;
F_83 ( V_6 , false ) ;
F_84 ( V_6 ) ;
V_26 = F_85 ( V_6 ) ;
if ( V_26 )
goto V_174;
F_86 ( V_6 ) ;
V_26 = F_87 ( V_13 ) ;
if ( V_26 )
goto V_175;
F_88 ( V_6 ) ;
F_89 ( V_6 ) ;
V_26 = F_90 ( V_6 ) ;
if ( V_26 )
goto V_175;
F_91 ( V_13 ) ;
if ( F_18 ( V_6 ) -> V_34 == 0 )
return 0 ;
V_26 = F_92 ( V_13 ) ;
if ( V_26 )
goto V_176;
F_93 ( V_6 ) ;
F_94 ( V_13 ) ;
return 0 ;
V_176:
if ( F_95 ( V_6 ) )
F_42 ( L_25 ) ;
F_69 ( V_6 ) ;
V_175:
F_96 ( V_6 ) ;
F_97 ( V_6 ) ;
F_98 ( V_13 ) ;
F_99 ( V_6 ) ;
V_174:
F_100 ( V_6 ) ;
F_101 ( V_6 ) ;
F_102 ( V_62 ) ;
V_173:
F_79 ( V_62 , NULL , NULL , NULL ) ;
V_171:
return V_26 ;
}
static int F_103 ( struct V_5 * V_6 )
{
struct V_177 * V_178 ;
struct V_32 * V_62 = V_6 -> V_12 . V_62 ;
struct V_179 * V_180 = & V_6 -> V_180 ;
bool V_181 ;
int V_26 ;
V_178 = F_104 ( 1 ) ;
if ( ! V_178 )
return - V_182 ;
V_178 -> V_183 [ 0 ] . V_184 = V_180 -> V_185 ;
V_178 -> V_183 [ 0 ] . V_186 = V_180 -> V_187 ;
V_181 =
V_62 -> V_188 [ V_189 ] . V_138 & V_190 ;
V_26 = F_105 ( V_178 , L_26 , V_181 ) ;
F_106 ( V_178 ) ;
return V_26 ;
}
static int F_107 ( struct V_5 * V_6 )
{
return 0 ;
}
static int F_107 ( struct V_5 * V_6 )
{
return - V_69 ;
}
static int F_107 ( struct V_5 * V_6 )
{
int V_26 = 0 ;
F_2 ( L_27 ) ;
F_108 () ;
if ( F_109 ( & V_191 ) )
V_26 = F_110 ( & V_192 , 0 , V_193 - 1 , 1 ) ;
if ( V_26 == 0 ) {
V_26 = F_111 ( & V_191 ) ;
if ( V_26 == - V_69 )
V_26 = 0 ;
}
F_112 () ;
return V_26 ;
}
static void F_113 ( struct V_5 * V_6 )
{
if ( F_55 ( V_6 ) ) {
F_114 ( V_194 ) = V_195 ;
F_114 ( V_196 ) = V_197 ;
} else if ( F_54 ( V_6 ) ) {
F_114 ( V_194 ) = V_197 ;
}
}
static int F_115 ( struct V_5 * V_6 )
{
V_6 -> V_198 = F_116 ( L_28 , 0 ) ;
if ( V_6 -> V_198 == NULL )
goto V_199;
V_6 -> V_200 . V_201 = F_116 ( L_29 , 0 ) ;
if ( V_6 -> V_200 . V_201 == NULL )
goto V_202;
return 0 ;
V_202:
F_117 ( V_6 -> V_198 ) ;
V_199:
F_42 ( L_30 ) ;
return - V_182 ;
}
static void F_118 ( struct V_5 * V_6 )
{
F_117 ( V_6 -> V_200 . V_201 ) ;
F_117 ( V_6 -> V_198 ) ;
}
static void F_119 ( struct V_5 * V_6 )
{
if ( F_120 ( V_6 ) ||
F_121 ( V_6 , 0 , V_203 ) )
F_42 ( L_31
L_32 ) ;
}
static int F_122 ( struct V_5 * V_6 ,
const struct V_204 * V_205 )
{
const struct V_206 * V_207 =
(struct V_206 * ) V_205 -> V_208 ;
struct V_206 * V_209 ;
int V_26 = 0 ;
if ( F_77 () )
return - V_69 ;
V_209 = F_123 ( V_6 ) ;
memcpy ( V_209 , V_207 , sizeof( * V_209 ) ) ;
V_209 -> V_210 = V_6 -> V_12 . V_62 -> V_10 ;
F_124 ( V_209 -> V_211 > sizeof( V_209 -> V_212 ) * V_213 ) ;
V_209 -> V_212 = F_125 ( V_209 -> V_211 - 1 ) ;
F_126 ( & V_6 -> V_214 ) ;
F_126 ( & V_6 -> V_215 . V_216 ) ;
F_127 ( & V_6 -> V_217 ) ;
F_126 ( & V_6 -> V_218 . V_216 ) ;
F_126 ( & V_6 -> V_219 . V_220 ) ;
F_126 ( & V_6 -> V_221 ) ;
F_126 ( & V_6 -> V_222 . V_223 ) ;
F_127 ( & V_6 -> V_224 ) ;
F_127 ( & V_6 -> V_225 ) ;
F_127 ( & V_6 -> V_226 ) ;
F_127 ( & V_6 -> V_222 . V_227 ) ;
F_127 ( & V_6 -> V_228 ) ;
F_128 ( V_6 ) ;
F_129 ( V_6 ) ;
V_26 = F_115 ( V_6 ) ;
if ( V_26 < 0 )
return V_26 ;
F_17 ( V_6 ) ;
F_130 ( V_6 ) ;
F_113 ( V_6 ) ;
F_131 ( V_6 ) ;
F_132 ( V_6 ) ;
F_133 ( V_6 ) ;
F_134 ( V_6 ) ;
F_135 ( V_6 ) ;
F_136 ( V_6 ) ;
V_26 = F_137 ( V_6 ) ;
if ( V_26 < 0 )
goto V_229;
F_138 ( V_6 ) ;
F_139 ( V_6 ) ;
F_119 ( V_6 ) ;
F_140 ( V_6 ) ;
return 0 ;
V_229:
F_118 ( V_6 ) ;
return V_26 ;
}
static void F_141 ( struct V_5 * V_6 )
{
F_142 ( V_6 ) ;
F_143 ( V_6 ) ;
F_118 ( V_6 ) ;
}
static int F_144 ( struct V_5 * V_6 )
{
struct V_32 * V_62 = V_6 -> V_12 . V_62 ;
int V_230 ;
int V_231 ;
V_230 = F_145 ( V_6 ) ? 1 : 0 ;
if ( F_44 ( V_6 ) < 5 )
V_231 = 512 * 1024 ;
else
V_231 = 2 * 1024 * 1024 ;
V_6 -> V_232 = F_146 ( V_62 , V_230 , V_231 ) ;
if ( V_6 -> V_232 == NULL ) {
F_42 ( L_33 ) ;
return - V_233 ;
}
F_53 ( V_6 ) ;
return 0 ;
}
static void F_147 ( struct V_5 * V_6 )
{
struct V_32 * V_62 = V_6 -> V_12 . V_62 ;
F_58 ( V_6 ) ;
F_148 ( V_62 , V_6 -> V_232 ) ;
}
static int F_149 ( struct V_5 * V_6 )
{
int V_26 ;
if ( F_77 () )
return - V_69 ;
if ( F_39 ( V_6 ) )
return - V_233 ;
V_26 = F_144 ( V_6 ) ;
if ( V_26 < 0 )
goto V_234;
F_150 ( V_6 ) ;
return 0 ;
V_234:
F_23 ( V_6 -> V_128 ) ;
return V_26 ;
}
static void F_151 ( struct V_5 * V_6 )
{
F_152 ( V_6 ) ;
F_147 ( V_6 ) ;
F_23 ( V_6 -> V_128 ) ;
}
static void F_153 ( struct V_5 * V_6 )
{
V_3 . V_235 =
F_154 ( V_6 ,
V_3 . V_235 ) ;
V_3 . V_236 =
F_155 ( V_6 , V_3 . V_236 ) ;
F_49 ( L_34 , V_3 . V_236 ) ;
V_3 . V_90 = F_156 ( V_6 , V_3 . V_90 ) ;
F_49 ( L_35 , F_157 ( V_3 . V_90 ) ) ;
}
static int F_158 ( struct V_5 * V_6 )
{
struct V_32 * V_62 = V_6 -> V_12 . V_62 ;
int V_26 ;
if ( F_77 () )
return - V_69 ;
F_159 ( V_6 ) ;
F_153 ( V_6 ) ;
V_26 = F_160 ( V_6 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_103 ( V_6 ) ;
if ( V_26 ) {
F_42 ( L_36 ) ;
goto V_237;
}
V_26 = F_107 ( V_6 ) ;
if ( V_26 ) {
F_42 ( L_37 ) ;
goto V_237;
}
V_26 = F_161 ( V_6 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_162 ( V_6 ) ;
if ( V_26 ) {
F_42 ( L_38 ) ;
goto V_237;
}
F_163 ( V_62 ) ;
if ( F_145 ( V_6 ) ) {
V_26 = F_164 ( & V_62 -> V_13 , F_165 ( 30 ) ) ;
if ( V_26 ) {
F_42 ( L_39 ) ;
goto V_237;
}
}
if ( F_166 ( V_6 ) || F_167 ( V_6 ) ) {
V_26 = F_164 ( & V_62 -> V_13 , F_165 ( 32 ) ) ;
if ( V_26 ) {
F_42 ( L_39 ) ;
goto V_237;
}
}
F_168 ( & V_6 -> V_238 , V_239 ,
V_240 ) ;
F_169 ( V_6 ) ;
F_170 ( V_6 ) ;
F_171 ( V_6 ) ;
if ( ! F_172 ( V_6 ) && ! F_173 ( V_6 ) ) {
if ( F_174 ( V_62 ) < 0 )
F_49 ( L_40 ) ;
}
V_26 = F_175 ( V_6 ) ;
if ( V_26 )
goto V_237;
return 0 ;
V_237:
F_176 ( V_6 ) ;
return V_26 ;
}
static void F_177 ( struct V_5 * V_6 )
{
struct V_32 * V_62 = V_6 -> V_12 . V_62 ;
if ( V_62 -> V_241 )
F_178 ( V_62 ) ;
F_179 ( & V_6 -> V_238 ) ;
F_176 ( V_6 ) ;
}
static void F_180 ( struct V_5 * V_6 )
{
struct V_58 * V_13 = & V_6 -> V_12 ;
F_181 ( V_6 ) ;
if ( F_182 ( V_6 ) )
F_183 ( F_184 ( V_242 ) , V_243 ) ;
if ( F_185 ( V_13 , 0 ) == 0 ) {
F_186 ( V_6 ) ;
F_187 ( V_6 ) ;
F_188 ( V_6 ) ;
F_189 ( V_6 ) ;
} else
F_42 ( L_41 ) ;
if ( F_18 ( V_6 ) -> V_34 ) {
F_190 ( V_6 ) ;
F_191 () ;
}
if ( F_9 ( V_6 ) )
F_192 ( V_6 ) ;
F_193 ( V_6 ) ;
F_194 ( V_13 ) ;
}
static void F_195 ( struct V_5 * V_6 )
{
F_196 ( V_6 ) ;
F_197 () ;
F_198 () ;
F_199 ( V_6 ) ;
F_200 ( V_6 ) ;
F_201 ( V_6 ) ;
F_202 ( V_6 ) ;
F_203 ( V_6 ) ;
F_204 ( & V_6 -> V_12 ) ;
F_205 ( V_6 ) ;
}
int F_206 ( struct V_32 * V_62 , const struct V_204 * V_205 )
{
struct V_5 * V_6 ;
int V_26 ;
if ( V_3 . V_244 )
V_245 . V_246 |= V_247 ;
V_26 = - V_182 ;
V_6 = F_207 ( sizeof( * V_6 ) , V_248 ) ;
if ( V_6 )
V_26 = F_208 ( & V_6 -> V_12 , & V_245 , & V_62 -> V_13 ) ;
if ( V_26 ) {
F_209 ( & V_62 -> V_13 , L_42 ) ;
F_106 ( V_6 ) ;
return V_26 ;
}
V_6 -> V_12 . V_62 = V_62 ;
V_6 -> V_12 . V_249 = V_6 ;
V_26 = F_210 ( V_62 ) ;
if ( V_26 )
goto V_250;
F_211 ( V_62 , & V_6 -> V_12 ) ;
V_26 = F_122 ( V_6 , V_205 ) ;
if ( V_26 < 0 )
goto V_251;
F_212 ( V_6 ) ;
V_26 = F_149 ( V_6 ) ;
if ( V_26 < 0 )
goto V_252;
V_26 = F_158 ( V_6 ) ;
if ( V_26 < 0 )
goto V_253;
if ( F_18 ( V_6 ) -> V_34 ) {
V_26 = F_213 ( & V_6 -> V_12 ,
F_18 ( V_6 ) -> V_34 ) ;
if ( V_26 )
goto V_254;
}
V_26 = F_76 ( & V_6 -> V_12 ) ;
if ( V_26 < 0 )
goto V_255;
F_180 ( V_6 ) ;
F_214 ( V_6 ) ;
V_6 -> V_256 = false ;
F_2 ( L_43 ,
V_245 . V_137 , V_245 . V_257 , V_245 . V_258 , V_245 . V_259 ,
V_245 . V_260 , F_215 ( V_62 ) , V_6 -> V_12 . V_181 -> V_261 ) ;
if ( F_216 ( V_262 ) )
F_2 ( L_44 ) ;
if ( F_216 ( V_263 ) )
F_2 ( L_45 ) ;
F_217 ( V_6 ) ;
return 0 ;
V_255:
F_218 ( & V_6 -> V_12 ) ;
V_254:
F_177 ( V_6 ) ;
V_253:
F_151 ( V_6 ) ;
V_252:
F_217 ( V_6 ) ;
F_141 ( V_6 ) ;
V_251:
F_219 ( V_62 ) ;
V_250:
F_220 ( V_6 , L_46 , V_26 ) ;
F_221 ( & V_6 -> V_12 ) ;
return V_26 ;
}
void F_222 ( struct V_58 * V_13 )
{
struct V_5 * V_6 = F_25 ( V_13 ) ;
struct V_32 * V_62 = V_6 -> V_12 . V_62 ;
F_223 ( V_13 ) ;
if ( F_95 ( V_6 ) )
F_42 ( L_25 ) ;
F_224 ( V_6 , V_264 ) ;
F_225 ( V_6 ) ;
F_195 ( V_6 ) ;
F_218 ( V_13 ) ;
F_226 ( V_13 ) ;
if ( V_6 -> V_265 . V_266 && V_6 -> V_265 . V_267 ) {
F_106 ( V_6 -> V_265 . V_266 ) ;
V_6 -> V_265 . V_266 = NULL ;
V_6 -> V_265 . V_267 = 0 ;
}
F_106 ( V_6 -> V_265 . V_268 ) ;
V_6 -> V_265 . V_268 = NULL ;
F_106 ( V_6 -> V_265 . V_269 ) ;
V_6 -> V_265 . V_269 = NULL ;
F_102 ( V_62 ) ;
F_79 ( V_62 , NULL , NULL , NULL ) ;
F_100 ( V_6 ) ;
F_227 ( & V_6 -> V_215 . V_270 ) ;
F_228 ( V_6 ) ;
F_229 ( V_6 -> V_198 ) ;
F_96 ( V_6 ) ;
F_97 ( V_6 ) ;
F_69 ( V_6 ) ;
F_230 ( V_6 ) ;
F_101 ( V_6 ) ;
F_177 ( V_6 ) ;
F_151 ( V_6 ) ;
F_231 ( V_6 , V_264 ) ;
F_141 ( V_6 ) ;
}
static int F_232 ( struct V_58 * V_13 , struct V_60 * V_271 )
{
int V_26 ;
V_26 = F_233 ( V_13 , V_271 ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
static void F_234 ( struct V_58 * V_13 )
{
F_235 ( V_13 ) ;
F_236 () ;
}
static void F_237 ( struct V_58 * V_13 , struct V_60 * V_271 )
{
F_70 ( & V_13 -> V_169 ) ;
F_238 ( V_13 , V_271 ) ;
F_239 ( V_13 , V_271 ) ;
F_73 ( & V_13 -> V_169 ) ;
}
static void F_240 ( struct V_58 * V_13 , struct V_60 * V_271 )
{
struct V_272 * V_61 = V_271 -> V_273 ;
F_106 ( V_61 ) ;
}
static void F_241 ( struct V_5 * V_6 )
{
struct V_58 * V_13 = & V_6 -> V_12 ;
struct V_274 * V_275 ;
F_242 ( V_13 ) ;
F_243 (dev, encoder)
if ( V_275 -> V_276 )
V_275 -> V_276 ( V_275 ) ;
F_244 ( V_13 ) ;
}
static bool F_245 ( struct V_5 * V_6 )
{
#if F_216 ( V_277 )
if ( F_246 () < V_278 )
return true ;
#endif
return false ;
}
static int F_247 ( struct V_58 * V_13 )
{
struct V_5 * V_6 = F_25 ( V_13 ) ;
struct V_32 * V_62 = V_6 -> V_12 . V_62 ;
T_6 V_279 ;
int error ;
F_70 ( & V_6 -> V_225 ) ;
V_6 -> V_280 = V_281 ;
F_73 ( & V_6 -> V_225 ) ;
F_248 ( V_6 ) ;
F_249 ( V_6 , true ) ;
F_250 ( V_13 ) ;
F_251 ( V_62 ) ;
error = F_95 ( V_6 ) ;
if ( error ) {
F_252 ( & V_62 -> V_13 ,
L_47 ) ;
goto V_171;
}
F_253 ( V_13 ) ;
F_254 ( V_13 ) ;
F_255 ( V_6 ) ;
F_256 ( V_6 ) ;
F_241 ( V_6 ) ;
F_257 ( V_6 ) ;
F_258 ( V_6 ) ;
F_259 ( V_6 ) ;
V_279 = F_245 ( V_6 ) ? V_282 : V_283 ;
F_260 ( V_6 , V_279 ) ;
F_261 ( V_6 , false ) ;
F_199 ( V_6 ) ;
F_262 ( V_13 , V_284 , true ) ;
V_6 -> V_285 ++ ;
F_263 ( V_6 ) ;
V_171:
F_264 ( V_6 ) ;
return error ;
}
static int F_265 ( struct V_58 * V_13 , bool V_286 )
{
struct V_5 * V_6 = F_25 ( V_13 ) ;
struct V_32 * V_62 = V_6 -> V_12 . V_62 ;
bool V_287 ;
int V_26 ;
F_248 ( V_6 ) ;
F_249 ( V_6 , false ) ;
V_287 = ! F_266 ( V_6 ) &&
F_245 ( V_6 ) && V_6 -> V_288 . V_289 ;
if ( ! V_287 )
F_267 ( V_6 ) ;
V_26 = 0 ;
if ( F_266 ( V_6 ) )
F_268 ( V_6 ) ;
else if ( F_13 ( V_6 ) || F_14 ( V_6 ) )
F_269 ( V_6 ) ;
else if ( F_54 ( V_6 ) || F_55 ( V_6 ) )
V_26 = F_270 ( V_6 ) ;
if ( V_26 ) {
F_42 ( L_48 , V_26 ) ;
if ( ! V_287 )
F_83 ( V_6 , true ) ;
goto V_171;
}
F_219 ( V_62 ) ;
if ( ! ( V_286 && F_44 ( V_6 ) < 6 ) )
F_65 ( V_62 , V_290 ) ;
V_6 -> V_291 = F_245 ( V_6 ) ;
V_171:
F_264 ( V_6 ) ;
return V_26 ;
}
static int F_67 ( struct V_58 * V_13 , T_5 V_153 )
{
int error ;
if ( ! V_13 ) {
F_42 ( L_49 , V_13 ) ;
F_42 ( L_50 ) ;
return - V_69 ;
}
if ( F_271 ( V_153 . V_160 != V_161 &&
V_153 . V_160 != V_292 ) )
return - V_126 ;
if ( V_13 -> V_163 == V_167 )
return 0 ;
error = F_247 ( V_13 ) ;
if ( error )
return error ;
return F_265 ( V_13 , false ) ;
}
static int F_272 ( struct V_58 * V_13 )
{
struct V_5 * V_6 = F_25 ( V_13 ) ;
int V_26 ;
F_248 ( V_6 ) ;
F_273 ( V_6 ) ;
V_26 = F_162 ( V_6 ) ;
if ( V_26 )
F_42 ( L_51 ) ;
F_274 ( V_6 ) ;
F_275 ( V_6 ) ;
F_276 ( V_6 ) ;
F_277 ( V_6 ) ;
F_170 ( V_6 ) ;
F_278 ( V_6 ) ;
F_279 ( V_6 ) ;
F_280 ( V_13 ) ;
F_70 ( & V_13 -> V_169 ) ;
if ( F_281 ( V_6 ) ) {
F_42 ( L_52 ) ;
F_282 ( V_6 ) ;
}
F_73 ( & V_13 -> V_169 ) ;
F_283 ( V_6 ) ;
F_284 ( V_13 ) ;
F_285 ( & V_6 -> V_214 ) ;
if ( V_6 -> V_293 . V_294 )
V_6 -> V_293 . V_294 ( V_6 ) ;
F_286 ( & V_6 -> V_214 ) ;
F_287 ( V_13 ) ;
F_288 ( V_13 ) ;
F_289 ( V_13 ) ;
F_93 ( V_6 ) ;
F_190 ( V_6 ) ;
F_262 ( V_13 , V_295 , false ) ;
F_70 ( & V_6 -> V_225 ) ;
V_6 -> V_280 = V_296 ;
F_73 ( & V_6 -> V_225 ) ;
F_260 ( V_6 , V_165 ) ;
F_290 ( V_6 ) ;
F_264 ( V_6 ) ;
return 0 ;
}
static int F_291 ( struct V_58 * V_13 )
{
struct V_5 * V_6 = F_25 ( V_13 ) ;
struct V_32 * V_62 = V_6 -> V_12 . V_62 ;
int V_26 ;
V_26 = F_65 ( V_62 , V_165 ) ;
if ( V_26 ) {
F_42 ( L_53 , V_26 ) ;
goto V_171;
}
if ( F_210 ( V_62 ) ) {
V_26 = - V_233 ;
goto V_171;
}
F_163 ( V_62 ) ;
F_248 ( V_6 ) ;
if ( F_54 ( V_6 ) || F_55 ( V_6 ) )
V_26 = F_292 ( V_6 , false ) ;
if ( V_26 )
F_42 ( L_54 ,
V_26 ) ;
F_293 ( V_6 , true ) ;
if ( F_266 ( V_6 ) ) {
if ( ! V_6 -> V_291 )
F_294 ( V_6 ) ;
F_295 ( V_6 ) ;
} else if ( F_13 ( V_6 ) || F_14 ( V_6 ) ) {
F_296 ( V_6 ) ;
}
F_169 ( V_6 ) ;
if ( F_266 ( V_6 ) ||
! ( V_6 -> V_291 && V_6 -> V_288 . V_289 ) )
F_83 ( V_6 , true ) ;
F_264 ( V_6 ) ;
V_171:
V_6 -> V_291 = false ;
return V_26 ;
}
static int F_66 ( struct V_58 * V_13 )
{
int V_26 ;
if ( V_13 -> V_163 == V_167 )
return 0 ;
V_26 = F_291 ( V_13 ) ;
if ( V_26 )
return V_26 ;
return F_272 ( V_13 ) ;
}
void F_297 ( struct V_5 * V_6 )
{
struct V_297 * error = & V_6 -> V_215 ;
int V_26 ;
F_298 ( & V_6 -> V_12 . V_169 ) ;
if ( ! F_299 ( V_298 , & error -> V_138 ) )
return;
F_300 ( V_299 , & error -> V_138 ) ;
error -> V_300 ++ ;
F_301 ( L_55 ) ;
F_302 ( V_6 -> V_12 . V_301 ) ;
V_26 = F_303 ( V_6 ) ;
if ( V_26 ) {
F_42 ( L_56 ) ;
F_304 ( V_6 , V_302 ) ;
goto error;
}
V_26 = F_304 ( V_6 , V_302 ) ;
if ( V_26 ) {
if ( V_26 != - V_69 )
F_42 ( L_57 , V_26 ) ;
else
F_49 ( L_58 ) ;
goto error;
}
F_305 ( V_6 ) ;
F_306 ( V_6 ) ;
V_26 = F_281 ( V_6 ) ;
if ( V_26 ) {
F_42 ( L_59 , V_26 ) ;
goto error;
}
F_307 ( V_6 ) ;
V_303:
F_308 ( V_6 ) ;
F_309 ( V_6 -> V_12 . V_301 ) ;
F_310 ( & error -> V_138 , V_298 ) ;
return;
error:
F_282 ( V_6 ) ;
goto V_303;
}
static int F_311 ( struct V_10 * V_11 )
{
struct V_32 * V_62 = F_312 ( V_11 ) ;
struct V_58 * V_13 = F_63 ( V_62 ) ;
if ( ! V_13 ) {
F_252 ( V_11 , L_50 ) ;
return - V_69 ;
}
if ( V_13 -> V_163 == V_167 )
return 0 ;
return F_247 ( V_13 ) ;
}
static int F_313 ( struct V_10 * V_11 )
{
struct V_58 * V_13 = & F_314 ( V_11 ) -> V_12 ;
if ( V_13 -> V_163 == V_167 )
return 0 ;
return F_265 ( V_13 , false ) ;
}
static int F_315 ( struct V_10 * V_11 )
{
struct V_58 * V_13 = & F_314 ( V_11 ) -> V_12 ;
if ( V_13 -> V_163 == V_167 )
return 0 ;
return F_265 ( V_13 , true ) ;
}
static int F_316 ( struct V_10 * V_11 )
{
struct V_58 * V_13 = & F_314 ( V_11 ) -> V_12 ;
if ( V_13 -> V_163 == V_167 )
return 0 ;
return F_291 ( V_13 ) ;
}
static int F_317 ( struct V_10 * V_11 )
{
struct V_58 * V_13 = & F_314 ( V_11 ) -> V_12 ;
if ( V_13 -> V_163 == V_167 )
return 0 ;
return F_272 ( V_13 ) ;
}
static int F_318 ( struct V_10 * V_11 )
{
int V_26 ;
V_26 = F_311 ( V_11 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_319 ( F_314 ( V_11 ) ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
static int F_320 ( struct V_10 * V_11 )
{
int V_26 ;
V_26 = F_313 ( V_11 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_321 ( F_314 ( V_11 ) ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
static int F_322 ( struct V_10 * V_11 )
{
return F_316 ( V_11 ) ;
}
static int F_323 ( struct V_10 * V_11 )
{
return F_317 ( V_11 ) ;
}
static int F_324 ( struct V_10 * V_11 )
{
return F_316 ( V_11 ) ;
}
static int F_325 ( struct V_10 * V_11 )
{
return F_317 ( V_11 ) ;
}
static void F_326 ( struct V_5 * V_6 )
{
struct V_304 * V_305 = & V_6 -> V_304 ;
int V_306 ;
V_305 -> V_307 = F_35 ( V_308 ) ;
V_305 -> V_309 = F_35 ( V_310 ) ;
V_305 -> V_311 = F_35 ( V_312 ) ;
V_305 -> V_313 = F_35 ( V_314 ) ;
V_305 -> V_315 = F_35 ( V_316 ) ;
for ( V_306 = 0 ; V_306 < F_327 ( V_305 -> V_317 ) ; V_306 ++ )
V_305 -> V_317 [ V_306 ] = F_35 ( F_328 ( V_306 ) ) ;
V_305 -> V_318 = F_35 ( V_319 ) ;
V_305 -> V_320 = F_35 ( V_321 ) ;
V_305 -> V_322 = F_35 ( V_323 ) ;
V_305 -> V_324 = F_35 ( V_325 ) ;
V_305 -> V_326 = F_35 ( V_327 ) ;
V_305 -> V_328 = F_35 ( V_329 ) ;
V_305 -> V_330 = F_35 ( V_331 ) ;
V_305 -> V_332 = F_35 ( V_333 ) ;
V_305 -> V_334 = F_35 ( V_335 ) ;
V_305 -> V_336 = F_35 ( V_337 ) ;
V_305 -> V_338 = F_35 ( V_339 ) ;
V_305 -> V_340 = F_35 ( V_341 ) ;
V_305 -> V_342 = F_35 ( V_343 ) ;
V_305 -> V_344 = F_35 ( V_345 ) ;
V_305 -> V_346 = F_35 ( V_347 ) ;
V_305 -> V_348 = F_35 ( V_349 ) ;
V_305 -> V_350 = F_35 ( V_351 ) ;
V_305 -> V_352 = F_35 ( V_353 ) ;
V_305 -> V_354 = F_35 ( V_355 ) ;
V_305 -> V_356 = F_35 ( V_357 ) ;
V_305 -> V_358 = F_35 ( V_359 ) ;
V_305 -> V_360 = F_35 ( V_361 ) ;
V_305 -> V_362 = F_35 ( V_363 ) ;
V_305 -> V_364 = F_35 ( V_365 ) ;
V_305 -> V_366 = F_35 ( V_367 ) ;
V_305 -> V_368 = F_35 ( V_369 ) ;
V_305 -> V_370 = F_35 ( V_371 ) ;
V_305 -> V_372 = F_35 ( V_373 ) ;
V_305 -> V_374 = F_35 ( V_375 ) ;
V_305 -> V_376 = F_35 ( V_377 ) ;
for ( V_306 = 0 ; V_306 < F_327 ( V_305 -> V_378 ) ; V_306 ++ )
V_305 -> V_378 [ V_306 ] = F_35 ( F_329 ( V_306 ) ) ;
V_305 -> V_379 = F_35 ( V_380 ) ;
V_305 -> V_381 = F_35 ( V_382 ) ;
V_305 -> V_383 = F_35 ( V_384 ) ;
V_305 -> V_385 = F_35 ( V_386 ) ;
V_305 -> V_387 = F_35 ( V_388 ) ;
V_305 -> V_389 = F_35 ( V_390 ) ;
V_305 -> V_391 = F_35 ( V_392 ) ;
V_305 -> V_393 = F_35 ( V_394 ) ;
V_305 -> V_395 = F_35 ( V_396 ) ;
}
static void F_330 ( struct V_5 * V_6 )
{
struct V_304 * V_305 = & V_6 -> V_304 ;
T_3 V_397 ;
int V_306 ;
F_183 ( V_308 , V_305 -> V_307 ) ;
F_183 ( V_310 , V_305 -> V_309 ) ;
F_183 ( V_312 , V_305 -> V_311 | ( 0xffff << 16 ) ) ;
F_183 ( V_314 , V_305 -> V_313 ) ;
F_183 ( V_316 , V_305 -> V_315 ) ;
for ( V_306 = 0 ; V_306 < F_327 ( V_305 -> V_317 ) ; V_306 ++ )
F_183 ( F_328 ( V_306 ) , V_305 -> V_317 [ V_306 ] ) ;
F_183 ( V_319 , V_305 -> V_318 ) ;
F_183 ( V_321 , V_305 -> V_320 ) ;
F_183 ( V_323 , V_305 -> V_322 ) ;
F_183 ( V_325 , V_305 -> V_324 ) ;
F_183 ( V_327 , V_305 -> V_326 ) ;
F_183 ( V_329 , V_305 -> V_328 ) ;
F_183 ( V_331 , V_305 -> V_330 ) ;
F_183 ( V_333 , V_305 -> V_332 ) ;
F_183 ( V_335 , V_305 -> V_334 ) ;
F_183 ( V_337 , V_305 -> V_336 ) ;
F_183 ( V_339 , V_305 -> V_338 ) ;
F_183 ( V_341 , V_305 -> V_340 ) ;
F_183 ( V_343 , V_305 -> V_342 ) ;
F_183 ( V_345 , V_305 -> V_344 ) ;
F_183 ( V_347 , V_305 -> V_346 ) ;
F_183 ( V_349 , V_305 -> V_348 ) ;
F_183 ( V_351 , V_305 -> V_350 ) ;
F_183 ( V_353 , V_305 -> V_352 ) ;
F_183 ( V_355 , V_305 -> V_354 ) ;
F_183 ( V_357 , V_305 -> V_356 ) ;
F_183 ( V_359 , V_305 -> V_358 ) ;
F_183 ( V_361 , V_305 -> V_360 ) ;
F_183 ( V_363 , V_305 -> V_362 ) ;
F_183 ( V_365 , V_305 -> V_364 ) ;
F_183 ( V_367 , V_305 -> V_366 ) ;
F_183 ( V_369 , V_305 -> V_368 ) ;
F_183 ( V_371 , V_305 -> V_370 ) ;
F_183 ( V_373 , V_305 -> V_372 ) ;
F_183 ( V_375 , V_305 -> V_374 ) ;
F_183 ( V_377 , V_305 -> V_376 ) ;
for ( V_306 = 0 ; V_306 < F_327 ( V_305 -> V_378 ) ; V_306 ++ )
F_183 ( F_329 ( V_306 ) , V_305 -> V_378 [ V_306 ] ) ;
F_183 ( V_380 , V_305 -> V_379 ) ;
F_183 ( V_382 , V_305 -> V_381 ) ;
V_397 = F_35 ( V_384 ) ;
V_397 &= V_398 ;
V_397 |= V_305 -> V_383 & ~ V_398 ;
F_183 ( V_384 , V_397 ) ;
V_397 = F_35 ( V_386 ) ;
V_397 &= V_399 ;
V_397 |= V_305 -> V_385 & ~ V_399 ;
F_183 ( V_386 , V_397 ) ;
F_183 ( V_388 , V_305 -> V_387 ) ;
F_183 ( V_390 , V_305 -> V_389 ) ;
F_183 ( V_392 , V_305 -> V_391 ) ;
F_183 ( V_394 , V_305 -> V_393 ) ;
F_183 ( V_396 , V_305 -> V_395 ) ;
}
int F_331 ( struct V_5 * V_6 , bool V_400 )
{
T_3 V_397 ;
int V_401 ;
V_397 = F_35 ( V_386 ) ;
V_397 &= ~ V_399 ;
if ( V_400 )
V_397 |= V_399 ;
F_183 ( V_386 , V_397 ) ;
if ( ! V_400 )
return 0 ;
V_401 = F_332 ( V_6 ,
V_386 ,
V_402 ,
V_402 ,
20 ) ;
if ( V_401 )
F_42 ( L_60 ,
F_35 ( V_386 ) ) ;
return V_401 ;
}
static int F_333 ( struct V_5 * V_6 , bool V_403 )
{
T_3 V_397 ;
int V_401 = 0 ;
V_397 = F_35 ( V_384 ) ;
V_397 &= ~ V_398 ;
if ( V_403 )
V_397 |= V_398 ;
F_183 ( V_384 , V_397 ) ;
F_334 ( V_384 ) ;
V_401 = F_332 ( V_6 ,
V_404 ,
V_405 ,
V_403 ,
1 ) ;
if ( V_401 )
F_42 ( L_61 ) ;
return V_401 ;
}
static int F_335 ( struct V_5 * V_6 ,
bool V_406 )
{
T_3 V_407 ;
T_3 V_397 ;
int V_401 ;
V_407 = V_408 | V_409 ;
V_397 = V_406 ? V_407 : 0 ;
if ( ( F_35 ( V_404 ) & V_407 ) == V_397 )
return 0 ;
F_10 ( L_62 ,
F_336 ( V_406 ) ,
F_35 ( V_404 ) ) ;
V_401 = F_332 ( V_6 ,
V_404 , V_407 , V_397 ,
3 ) ;
if ( V_401 )
F_42 ( L_63 ,
F_336 ( V_406 ) ) ;
return V_401 ;
}
static void F_337 ( struct V_5 * V_6 )
{
if ( ! ( F_35 ( V_404 ) & V_410 ) )
return;
F_49 ( L_64 ) ;
F_183 ( V_404 , V_410 ) ;
}
static int F_270 ( struct V_5 * V_6 )
{
T_3 V_407 ;
int V_401 ;
( void ) F_335 ( V_6 , false ) ;
V_407 = V_411 | V_412 ;
F_20 ( ( F_35 ( V_384 ) & V_407 ) != V_407 ) ;
F_337 ( V_6 ) ;
V_401 = F_331 ( V_6 , true ) ;
if ( V_401 )
goto V_413;
V_401 = F_333 ( V_6 , false ) ;
if ( V_401 )
goto V_414;
if ( ! F_55 ( V_6 ) )
F_326 ( V_6 ) ;
V_401 = F_331 ( V_6 , false ) ;
if ( V_401 )
goto V_414;
return 0 ;
V_414:
F_333 ( V_6 , true ) ;
V_413:
F_331 ( V_6 , false ) ;
return V_401 ;
}
static int F_292 ( struct V_5 * V_6 ,
bool V_415 )
{
int V_401 ;
int V_26 ;
V_26 = F_331 ( V_6 , true ) ;
if ( ! F_55 ( V_6 ) )
F_330 ( V_6 ) ;
V_401 = F_333 ( V_6 , true ) ;
if ( ! V_26 )
V_26 = V_401 ;
V_401 = F_331 ( V_6 , false ) ;
if ( ! V_26 )
V_26 = V_401 ;
F_337 ( V_6 ) ;
if ( V_415 )
F_338 ( V_6 ) ;
return V_26 ;
}
static int F_339 ( struct V_10 * V_11 )
{
struct V_32 * V_62 = F_312 ( V_11 ) ;
struct V_58 * V_13 = F_63 ( V_62 ) ;
struct V_5 * V_6 = F_25 ( V_13 ) ;
int V_26 ;
if ( F_271 ( ! ( V_6 -> V_416 . V_146 && F_340 () ) ) )
return - V_69 ;
if ( F_271 ( ! F_341 ( V_6 ) ) )
return - V_69 ;
F_10 ( L_65 ) ;
F_248 ( V_6 ) ;
F_342 ( V_6 ) ;
F_343 ( V_6 ) ;
F_255 ( V_6 ) ;
V_26 = 0 ;
if ( F_266 ( V_6 ) ) {
F_344 ( V_6 ) ;
F_268 ( V_6 ) ;
} else if ( F_13 ( V_6 ) || F_14 ( V_6 ) ) {
F_269 ( V_6 ) ;
} else if ( F_54 ( V_6 ) || F_55 ( V_6 ) ) {
V_26 = F_270 ( V_6 ) ;
}
if ( V_26 ) {
F_42 ( L_66 , V_26 ) ;
F_279 ( V_6 ) ;
F_264 ( V_6 ) ;
return V_26 ;
}
F_261 ( V_6 , false ) ;
F_264 ( V_6 ) ;
F_271 ( F_345 ( & V_6 -> V_417 . V_418 ) ) ;
if ( F_346 ( V_6 ) )
F_42 ( L_67 ) ;
V_6 -> V_417 . V_419 = true ;
if ( F_14 ( V_6 ) ) {
F_260 ( V_6 , V_290 ) ;
} else {
F_260 ( V_6 , V_282 ) ;
}
F_347 ( V_6 ) ;
if ( ! F_54 ( V_6 ) && ! F_55 ( V_6 ) )
F_348 ( V_6 ) ;
F_10 ( L_68 ) ;
return 0 ;
}
static int F_349 ( struct V_10 * V_11 )
{
struct V_32 * V_62 = F_312 ( V_11 ) ;
struct V_58 * V_13 = F_63 ( V_62 ) ;
struct V_5 * V_6 = F_25 ( V_13 ) ;
int V_26 = 0 ;
if ( F_271 ( ! F_341 ( V_6 ) ) )
return - V_69 ;
F_10 ( L_69 ) ;
F_271 ( F_345 ( & V_6 -> V_417 . V_418 ) ) ;
F_248 ( V_6 ) ;
F_260 ( V_6 , V_165 ) ;
V_6 -> V_417 . V_419 = false ;
if ( F_350 ( V_6 ) )
F_49 ( L_70 ) ;
F_283 ( V_6 ) ;
if ( F_11 ( V_6 ) )
F_278 ( V_6 ) ;
if ( F_266 ( V_6 ) ) {
F_295 ( V_6 ) ;
F_351 ( V_6 , true ) ;
if ( V_6 -> V_288 . V_289 &&
( V_6 -> V_288 . V_420 & V_421 ) )
F_352 ( V_6 ) ;
} else if ( F_13 ( V_6 ) || F_14 ( V_6 ) ) {
F_296 ( V_6 ) ;
} else if ( F_54 ( V_6 ) || F_55 ( V_6 ) ) {
V_26 = F_292 ( V_6 , true ) ;
}
F_353 ( V_6 ) ;
F_354 ( V_6 ) ;
F_279 ( V_6 ) ;
if ( ! F_54 ( V_6 ) && ! F_55 ( V_6 ) )
F_93 ( V_6 ) ;
F_264 ( V_6 ) ;
if ( V_26 )
F_42 ( L_71 , V_26 ) ;
else
F_10 ( L_72 ) ;
return V_26 ;
}
static int
F_355 ( struct V_58 * V_13 , void * V_59 ,
struct V_60 * V_271 )
{
return - V_69 ;
}
