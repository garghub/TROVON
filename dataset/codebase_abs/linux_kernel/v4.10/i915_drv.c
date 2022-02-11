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
static void F_17 ( struct V_32 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
struct V_33 * V_34 = NULL ;
if ( F_19 ( V_6 ) -> V_35 == 0 ) {
V_6 -> V_36 = V_27 ;
return;
}
while ( ( V_34 = F_20 ( V_37 << 8 , V_34 ) ) ) {
if ( V_34 -> V_38 == V_39 ) {
unsigned short V_40 = V_34 -> V_10 & V_41 ;
V_6 -> V_42 = V_40 ;
if ( V_40 == V_43 ) {
V_6 -> V_36 = V_28 ;
F_10 ( L_9 ) ;
F_21 ( ! F_9 ( V_6 ) ) ;
} else if ( V_40 == V_44 ) {
V_6 -> V_36 = V_29 ;
F_10 ( L_10 ) ;
F_21 ( ! ( F_11 ( V_6 ) ||
F_12 ( V_6 ) ) ) ;
} else if ( V_40 == V_45 ) {
V_6 -> V_36 = V_29 ;
F_10 ( L_11 ) ;
F_21 ( ! ( F_11 ( V_6 ) ||
F_12 ( V_6 ) ) ) ;
} else if ( V_40 == V_46 ) {
V_6 -> V_36 = V_30 ;
F_10 ( L_12 ) ;
F_21 ( ! F_13 ( V_6 ) &&
! F_14 ( V_6 ) ) ;
F_21 ( F_22 ( V_6 ) ||
F_23 ( V_6 ) ) ;
} else if ( V_40 == V_47 ) {
V_6 -> V_36 = V_30 ;
F_10 ( L_13 ) ;
F_21 ( ! F_13 ( V_6 ) &&
! F_14 ( V_6 ) ) ;
F_21 ( ! F_22 ( V_6 ) &&
! F_23 ( V_6 ) ) ;
} else if ( V_40 == V_48 ) {
V_6 -> V_36 = V_31 ;
F_10 ( L_14 ) ;
F_21 ( ! F_15 ( V_6 ) &&
! F_16 ( V_6 ) ) ;
} else if ( V_40 == V_49 ) {
V_6 -> V_36 = V_31 ;
F_10 ( L_15 ) ;
F_21 ( ! F_15 ( V_6 ) &&
! F_16 ( V_6 ) ) ;
} else if ( V_40 == V_50 ) {
V_6 -> V_36 = V_51 ;
F_10 ( L_16 ) ;
F_21 ( ! F_15 ( V_6 ) &&
! F_16 ( V_6 ) ) ;
} else if ( ( V_40 == V_52 ) ||
( V_40 == V_53 ) ||
( ( V_40 == V_54 ) &&
V_34 -> V_55 ==
V_56 &&
V_34 -> V_57 ==
V_58 ) ) {
V_6 -> V_36 =
F_8 ( V_6 ) ;
} else
continue;
break;
}
}
if ( ! V_34 )
F_10 ( L_17 ) ;
F_24 ( V_34 ) ;
}
static int F_25 ( struct V_32 * V_13 , void * V_59 ,
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
V_64 = ! ! V_6 -> V_77 [ V_78 ] ;
break;
case V_79 :
V_64 = ! ! V_6 -> V_77 [ V_80 ] ;
break;
case V_81 :
V_64 = ! ! V_6 -> V_77 [ V_82 ] ;
break;
case V_83 :
V_64 = ! ! V_6 -> V_77 [ V_84 ] ;
break;
case V_85 :
V_64 = F_26 ( V_6 ) >= 4 ;
break;
case V_86 :
V_64 = F_27 ( V_6 ) ;
break;
case V_87 :
V_64 = F_28 ( V_6 ) ;
break;
case V_88 :
V_64 = F_29 ( V_6 ) ;
break;
case V_89 :
V_64 = V_3 . V_90 ;
break;
case V_91 :
V_64 = F_30 ( V_92 ) ;
break;
case V_93 :
V_64 = F_31 ( V_6 ) ;
break;
case V_94 :
V_64 = F_32 ( & F_19 ( V_6 ) -> V_95 ) ;
if ( ! V_64 )
return - V_68 ;
break;
case V_96 :
V_64 = F_19 ( V_6 ) -> V_95 . V_97 ;
if ( ! V_64 )
return - V_68 ;
break;
case V_98 :
V_64 = V_3 . V_99 && F_33 ( V_6 ) ;
break;
case V_100 :
V_64 = F_34 ( V_6 ) ;
break;
case V_101 :
V_64 = F_35 ( V_6 ) ;
break;
case V_102 :
V_64 = F_19 ( V_6 ) -> V_95 . V_103 ;
break;
case V_104 :
V_64 = F_36 () ;
break;
case V_105 :
V_64 = V_6 -> V_77 [ V_106 ] &&
V_6 -> V_77 [ V_106 ] -> V_107 ;
break;
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
case V_120 :
case V_121 :
case V_122 :
V_64 = 1 ;
break;
default:
F_37 ( L_18 , V_63 -> V_63 ) ;
return - V_123 ;
}
if ( F_38 ( V_64 , V_63 -> V_64 ) )
return - V_124 ;
return 0 ;
}
static int F_39 ( struct V_32 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
V_6 -> V_125 = F_40 ( 0 , F_41 ( 0 , 0 ) ) ;
if ( ! V_6 -> V_125 ) {
F_42 ( L_19 ) ;
return - 1 ;
}
return 0 ;
}
static int
F_43 ( struct V_32 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
int V_126 = F_26 ( V_6 ) >= 4 ? V_127 : V_128 ;
T_3 V_129 , V_130 = 0 ;
T_4 V_131 ;
int V_26 ;
if ( F_26 ( V_6 ) >= 4 )
F_44 ( V_6 -> V_125 , V_126 + 4 , & V_130 ) ;
F_44 ( V_6 -> V_125 , V_126 , & V_129 ) ;
V_131 = ( ( T_4 ) V_130 << 32 ) | V_129 ;
#ifdef F_45
if ( V_131 &&
F_46 ( V_131 , V_131 + V_132 ) )
return 0 ;
#endif
V_6 -> V_133 . V_134 = L_20 ;
V_6 -> V_133 . V_135 = V_136 ;
V_26 = F_47 ( V_6 -> V_125 -> V_137 ,
& V_6 -> V_133 ,
V_132 , V_132 ,
V_138 ,
0 , V_139 ,
V_6 -> V_125 ) ;
if ( V_26 ) {
F_48 ( L_21 , V_26 ) ;
V_6 -> V_133 . V_140 = 0 ;
return V_26 ;
}
if ( F_26 ( V_6 ) >= 4 )
F_49 ( V_6 -> V_125 , V_126 + 4 ,
F_50 ( V_6 -> V_133 . V_140 ) ) ;
F_49 ( V_6 -> V_125 , V_126 ,
F_51 ( V_6 -> V_133 . V_140 ) ) ;
return 0 ;
}
static void
F_52 ( struct V_32 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
int V_141 = F_26 ( V_6 ) >= 4 ? V_127 : V_128 ;
T_3 V_142 ;
bool V_143 ;
if ( F_53 ( V_6 ) || F_54 ( V_6 ) )
return;
V_6 -> V_144 = false ;
if ( F_55 ( V_6 ) || F_56 ( V_6 ) ) {
F_44 ( V_6 -> V_125 , V_145 , & V_142 ) ;
V_143 = ! ! ( V_142 & V_146 ) ;
} else {
F_44 ( V_6 -> V_125 , V_141 , & V_142 ) ;
V_143 = V_142 & 1 ;
}
if ( V_143 )
return;
if ( F_43 ( V_13 ) )
return;
V_6 -> V_144 = true ;
if ( F_55 ( V_6 ) || F_56 ( V_6 ) ) {
F_49 ( V_6 -> V_125 , V_145 ,
V_142 | V_146 ) ;
} else {
F_44 ( V_6 -> V_125 , V_141 , & V_142 ) ;
F_49 ( V_6 -> V_125 , V_141 , V_142 | 1 ) ;
}
}
static void
F_57 ( struct V_32 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
int V_141 = F_26 ( V_6 ) >= 4 ? V_127 : V_128 ;
if ( V_6 -> V_144 ) {
if ( F_55 ( V_6 ) || F_56 ( V_6 ) ) {
T_3 V_147 ;
F_44 ( V_6 -> V_125 , V_145 ,
& V_147 ) ;
V_147 &= ~ V_146 ;
F_49 ( V_6 -> V_125 , V_145 ,
V_147 ) ;
} else {
T_3 V_148 ;
F_44 ( V_6 -> V_125 , V_141 ,
& V_148 ) ;
V_148 &= ~ 1 ;
F_49 ( V_6 -> V_125 , V_141 ,
V_148 ) ;
}
}
if ( V_6 -> V_133 . V_140 )
F_58 ( & V_6 -> V_133 ) ;
}
static unsigned int F_59 ( void * V_149 , bool V_150 )
{
struct V_32 * V_13 = V_149 ;
F_60 ( F_18 ( V_13 ) , V_150 ) ;
if ( V_150 )
return V_151 | V_152 |
V_153 | V_154 ;
else
return V_153 | V_154 ;
}
static void F_61 ( struct V_33 * V_62 , enum V_155 V_150 )
{
struct V_32 * V_13 = F_62 ( V_62 ) ;
T_5 V_156 = { . V_157 = V_158 } ;
if ( V_150 == V_159 ) {
F_63 ( L_22 ) ;
V_13 -> V_160 = V_161 ;
F_64 ( V_62 , V_162 ) ;
F_65 ( V_13 ) ;
V_13 -> V_160 = V_163 ;
} else {
F_63 ( L_23 ) ;
V_13 -> V_160 = V_161 ;
F_66 ( V_13 , V_156 ) ;
V_13 -> V_160 = V_164 ;
}
}
static bool F_67 ( struct V_33 * V_62 )
{
struct V_32 * V_13 = F_62 ( V_62 ) ;
return V_13 -> V_165 == 0 ;
}
static void F_68 ( struct V_5 * V_6 )
{
F_69 ( & V_6 -> V_12 . V_166 ) ;
F_70 ( & V_6 -> V_12 ) ;
F_71 ( & V_6 -> V_12 ) ;
F_72 ( & V_6 -> V_12 . V_166 ) ;
F_73 () ;
F_74 ( & V_6 -> V_167 . V_168 ) ;
F_21 ( ! F_75 ( & V_6 -> V_169 ) ) ;
}
static int F_76 ( struct V_32 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
struct V_33 * V_62 = V_6 -> V_12 . V_62 ;
int V_26 ;
if ( F_77 () )
return - V_68 ;
V_26 = F_78 ( V_6 ) ;
if ( V_26 )
F_2 ( L_24 ) ;
V_26 = F_79 ( V_62 , V_13 , NULL , F_59 ) ;
if ( V_26 && V_26 != - V_68 )
goto V_170;
F_80 () ;
V_26 = F_81 ( V_62 , & V_171 , false ) ;
if ( V_26 )
goto V_172;
F_82 ( V_6 ) ;
F_83 ( V_6 , false ) ;
F_84 ( V_6 ) ;
V_26 = F_85 ( V_6 ) ;
if ( V_26 )
goto V_173;
F_86 ( V_13 ) ;
V_26 = F_87 ( V_13 ) ;
if ( V_26 )
goto V_174;
F_88 ( V_13 ) ;
V_26 = F_89 ( V_13 ) ;
if ( V_26 )
goto V_174;
F_90 ( V_13 ) ;
if ( F_19 ( V_6 ) -> V_35 == 0 )
return 0 ;
V_26 = F_91 ( V_13 ) ;
if ( V_26 )
goto V_175;
F_92 ( V_6 ) ;
F_93 ( V_13 ) ;
return 0 ;
V_175:
if ( F_94 ( V_13 ) )
F_42 ( L_25 ) ;
F_68 ( V_6 ) ;
V_174:
F_95 ( V_13 ) ;
F_96 ( V_13 ) ;
F_97 ( V_13 ) ;
V_173:
F_98 ( V_6 ) ;
F_99 ( V_6 ) ;
F_100 ( V_62 ) ;
V_172:
F_79 ( V_62 , NULL , NULL , NULL ) ;
V_170:
return V_26 ;
}
static int F_101 ( struct V_5 * V_6 )
{
struct V_176 * V_177 ;
struct V_33 * V_62 = V_6 -> V_12 . V_62 ;
struct V_178 * V_179 = & V_6 -> V_179 ;
bool V_180 ;
int V_26 ;
V_177 = F_102 ( 1 ) ;
if ( ! V_177 )
return - V_181 ;
V_177 -> V_182 [ 0 ] . V_183 = V_179 -> V_184 ;
V_177 -> V_182 [ 0 ] . V_185 = V_179 -> V_186 ;
V_180 =
V_62 -> V_187 [ V_188 ] . V_135 & V_189 ;
V_26 = F_103 ( V_177 , L_26 , V_180 ) ;
F_104 ( V_177 ) ;
return V_26 ;
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
int V_26 = 0 ;
F_2 ( L_27 ) ;
F_106 () ;
if ( F_107 ( & V_190 ) )
V_26 = F_108 ( & V_191 , 0 , V_192 - 1 , 1 ) ;
if ( V_26 == 0 ) {
V_26 = F_109 ( & V_190 ) ;
if ( V_26 == - V_68 )
V_26 = 0 ;
}
F_110 () ;
return V_26 ;
}
static void F_111 ( struct V_5 * V_6 )
{
if ( F_54 ( V_6 ) ) {
F_112 ( V_193 ) = V_194 ;
F_112 ( V_195 ) = V_196 ;
} else if ( F_53 ( V_6 ) ) {
F_112 ( V_193 ) = V_196 ;
}
}
static int F_113 ( struct V_5 * V_6 )
{
V_6 -> V_197 = F_114 ( L_28 , 0 ) ;
if ( V_6 -> V_197 == NULL )
goto V_198;
V_6 -> V_199 . V_200 = F_114 ( L_29 , 0 ) ;
if ( V_6 -> V_199 . V_200 == NULL )
goto V_201;
return 0 ;
V_201:
F_115 ( V_6 -> V_197 ) ;
V_198:
F_42 ( L_30 ) ;
return - V_181 ;
}
static void F_116 ( struct V_5 * V_6 )
{
F_115 ( V_6 -> V_199 . V_200 ) ;
F_115 ( V_6 -> V_197 ) ;
}
static void F_117 ( struct V_5 * V_6 )
{
if ( F_118 ( V_6 ) ||
F_119 ( V_6 , 0 , V_202 ) )
F_42 ( L_31
L_32 ) ;
}
static int F_120 ( struct V_5 * V_6 ,
const struct V_203 * V_204 )
{
const struct V_205 * V_206 =
(struct V_205 * ) V_204 -> V_207 ;
struct V_205 * V_208 ;
int V_26 = 0 ;
if ( F_77 () )
return - V_68 ;
V_208 = F_121 ( V_6 ) ;
memcpy ( V_208 , V_206 , sizeof( * V_208 ) ) ;
V_208 -> V_209 = V_6 -> V_12 . V_62 -> V_10 ;
F_122 ( V_208 -> V_210 > sizeof( V_208 -> V_211 ) * V_212 ) ;
V_208 -> V_211 = F_123 ( V_208 -> V_210 - 1 ) ;
F_124 ( & V_6 -> V_213 ) ;
F_124 ( & V_6 -> V_214 . V_215 ) ;
F_125 ( & V_6 -> V_216 ) ;
F_124 ( & V_6 -> V_217 . V_215 ) ;
F_124 ( & V_6 -> V_167 . V_218 ) ;
F_124 ( & V_6 -> V_219 ) ;
F_125 ( & V_6 -> V_220 ) ;
F_125 ( & V_6 -> V_221 ) ;
F_125 ( & V_6 -> V_222 ) ;
F_125 ( & V_6 -> V_223 . V_224 ) ;
F_125 ( & V_6 -> V_225 ) ;
F_126 ( V_6 ) ;
V_26 = F_113 ( V_6 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_127 ( V_6 ) ;
if ( V_26 < 0 )
goto V_226;
F_17 ( & V_6 -> V_12 ) ;
F_128 ( & V_6 -> V_12 ) ;
F_111 ( V_6 ) ;
F_129 ( V_6 ) ;
F_130 ( V_6 ) ;
F_131 ( V_6 ) ;
F_132 ( V_6 ) ;
F_133 ( V_6 ) ;
F_134 ( V_6 ) ;
V_26 = F_135 ( & V_6 -> V_12 ) ;
if ( V_26 < 0 )
goto V_227;
F_136 ( V_6 ) ;
F_137 ( V_6 ) ;
F_117 ( V_6 ) ;
return 0 ;
V_227:
F_138 ( V_6 ) ;
V_226:
F_116 ( V_6 ) ;
return V_26 ;
}
static void F_139 ( struct V_5 * V_6 )
{
F_140 ( & V_6 -> V_12 ) ;
F_116 ( V_6 ) ;
}
static int F_141 ( struct V_32 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
struct V_33 * V_62 = V_6 -> V_12 . V_62 ;
int V_228 ;
int V_229 ;
V_228 = F_142 ( V_6 ) ? 1 : 0 ;
if ( F_26 ( V_6 ) < 5 )
V_229 = 512 * 1024 ;
else
V_229 = 2 * 1024 * 1024 ;
V_6 -> V_230 = F_143 ( V_62 , V_228 , V_229 ) ;
if ( V_6 -> V_230 == NULL ) {
F_42 ( L_33 ) ;
return - V_231 ;
}
F_52 ( V_13 ) ;
return 0 ;
}
static void F_144 ( struct V_32 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
struct V_33 * V_62 = V_6 -> V_12 . V_62 ;
F_57 ( V_13 ) ;
F_145 ( V_62 , V_6 -> V_230 ) ;
}
static int F_146 ( struct V_5 * V_6 )
{
struct V_32 * V_13 = & V_6 -> V_12 ;
int V_26 ;
if ( F_77 () )
return - V_68 ;
if ( F_39 ( V_13 ) )
return - V_231 ;
V_26 = F_141 ( V_13 ) ;
if ( V_26 < 0 )
goto V_232;
F_147 ( V_6 ) ;
return 0 ;
V_232:
F_24 ( V_6 -> V_125 ) ;
return V_26 ;
}
static void F_148 ( struct V_5 * V_6 )
{
struct V_32 * V_13 = & V_6 -> V_12 ;
F_149 ( V_6 ) ;
F_144 ( V_13 ) ;
F_24 ( V_6 -> V_125 ) ;
}
static void F_150 ( struct V_5 * V_6 )
{
V_3 . V_233 =
F_151 ( V_6 ,
V_3 . V_233 ) ;
V_3 . V_234 =
F_152 ( V_6 , V_3 . V_234 ) ;
F_48 ( L_34 , V_3 . V_234 ) ;
V_3 . V_90 = F_153 ( V_6 , V_3 . V_90 ) ;
F_48 ( L_35 , F_154 ( V_3 . V_90 ) ) ;
}
static int F_155 ( struct V_5 * V_6 )
{
struct V_33 * V_62 = V_6 -> V_12 . V_62 ;
int V_26 ;
if ( F_77 () )
return - V_68 ;
F_156 ( V_6 ) ;
F_150 ( V_6 ) ;
V_26 = F_157 ( V_6 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_101 ( V_6 ) ;
if ( V_26 ) {
F_42 ( L_36 ) ;
goto V_235;
}
V_26 = F_105 ( V_6 ) ;
if ( V_26 ) {
F_42 ( L_37 ) ;
goto V_235;
}
V_26 = F_158 ( V_6 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_159 ( V_6 ) ;
if ( V_26 ) {
F_42 ( L_38 ) ;
goto V_235;
}
F_160 ( V_62 ) ;
if ( F_142 ( V_6 ) ) {
V_26 = F_161 ( & V_62 -> V_13 , F_162 ( 30 ) ) ;
if ( V_26 ) {
F_42 ( L_39 ) ;
goto V_235;
}
}
if ( F_163 ( V_6 ) || F_164 ( V_6 ) ) {
V_26 = F_161 ( & V_62 -> V_13 , F_162 ( 32 ) ) ;
if ( V_26 ) {
F_42 ( L_39 ) ;
goto V_235;
}
}
F_165 ( & V_6 -> V_236 , V_237 ,
V_238 ) ;
F_166 ( V_6 ) ;
F_167 ( V_6 ) ;
F_168 ( V_6 ) ;
if ( ! F_169 ( V_6 ) && ! F_170 ( V_6 ) ) {
if ( F_171 ( V_62 ) < 0 )
F_48 ( L_40 ) ;
}
return 0 ;
V_235:
F_172 ( V_6 ) ;
return V_26 ;
}
static void F_173 ( struct V_5 * V_6 )
{
struct V_33 * V_62 = V_6 -> V_12 . V_62 ;
if ( V_62 -> V_239 )
F_174 ( V_62 ) ;
F_175 ( & V_6 -> V_236 ) ;
F_172 ( V_6 ) ;
}
static void F_176 ( struct V_5 * V_6 )
{
struct V_32 * V_13 = & V_6 -> V_12 ;
F_177 ( V_6 ) ;
if ( F_178 ( V_6 ) )
F_179 ( F_180 ( V_240 ) , V_241 ) ;
if ( F_181 ( V_13 , 0 ) == 0 ) {
F_182 ( V_6 ) ;
F_183 ( V_6 ) ;
F_184 ( V_6 ) ;
} else
F_42 ( L_41 ) ;
if ( F_19 ( V_6 ) -> V_35 ) {
F_185 ( V_6 ) ;
F_186 () ;
}
if ( F_9 ( V_6 ) )
F_187 ( V_6 ) ;
F_188 ( V_6 ) ;
F_189 ( V_13 ) ;
}
static void F_190 ( struct V_5 * V_6 )
{
F_191 ( V_6 ) ;
F_192 () ;
F_193 () ;
F_194 ( V_6 ) ;
F_195 ( V_6 ) ;
F_196 ( V_6 ) ;
F_197 ( V_6 ) ;
F_198 ( & V_6 -> V_12 ) ;
F_199 ( V_6 ) ;
}
int F_200 ( struct V_33 * V_62 , const struct V_203 * V_204 )
{
struct V_5 * V_6 ;
int V_26 ;
if ( V_3 . V_242 )
V_243 . V_244 |= V_245 ;
V_26 = - V_181 ;
V_6 = F_201 ( sizeof( * V_6 ) , V_246 ) ;
if ( V_6 )
V_26 = F_202 ( & V_6 -> V_12 , & V_243 , & V_62 -> V_13 ) ;
if ( V_26 ) {
F_4 ( V_15 , & V_62 -> V_13 ,
L_2 V_23 L_42 , V_247 ) ;
F_104 ( V_6 ) ;
return V_26 ;
}
V_6 -> V_12 . V_62 = V_62 ;
V_6 -> V_12 . V_248 = V_6 ;
V_26 = F_203 ( V_62 ) ;
if ( V_26 )
goto V_249;
F_204 ( V_62 , & V_6 -> V_12 ) ;
V_26 = F_120 ( V_6 , V_204 ) ;
if ( V_26 < 0 )
goto V_250;
F_205 ( V_6 ) ;
V_26 = F_146 ( V_6 ) ;
if ( V_26 < 0 )
goto V_251;
V_26 = F_155 ( V_6 ) ;
if ( V_26 < 0 )
goto V_252;
if ( F_19 ( V_6 ) -> V_35 ) {
V_26 = F_206 ( & V_6 -> V_12 ,
F_19 ( V_6 ) -> V_35 ) ;
if ( V_26 )
goto V_253;
}
V_26 = F_76 ( & V_6 -> V_12 ) ;
if ( V_26 < 0 )
goto V_254;
F_176 ( V_6 ) ;
F_207 ( V_6 ) ;
F_2 ( L_43 ,
V_243 . V_134 , V_243 . V_255 , V_243 . V_256 , V_243 . V_257 ,
V_243 . V_258 , F_208 ( V_62 ) , V_6 -> V_12 . V_180 -> V_259 ) ;
if ( F_209 ( V_260 ) )
F_2 ( L_44 ) ;
if ( F_209 ( V_261 ) )
F_2 ( L_45 ) ;
F_210 ( V_6 ) ;
return 0 ;
V_254:
F_211 ( & V_6 -> V_12 ) ;
V_253:
F_173 ( V_6 ) ;
V_252:
F_148 ( V_6 ) ;
V_251:
F_210 ( V_6 ) ;
F_139 ( V_6 ) ;
V_250:
F_212 ( V_62 ) ;
V_249:
F_213 ( V_6 , L_46 , V_26 ) ;
F_214 ( & V_6 -> V_12 ) ;
return V_26 ;
}
void F_215 ( struct V_32 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
struct V_33 * V_62 = V_6 -> V_12 . V_62 ;
F_216 ( V_13 ) ;
if ( F_94 ( V_13 ) )
F_42 ( L_25 ) ;
F_217 ( V_6 , V_262 ) ;
F_190 ( V_6 ) ;
F_211 ( V_13 ) ;
F_218 ( V_13 ) ;
if ( V_6 -> V_263 . V_264 && V_6 -> V_263 . V_265 ) {
F_104 ( V_6 -> V_263 . V_264 ) ;
V_6 -> V_263 . V_264 = NULL ;
V_6 -> V_263 . V_265 = 0 ;
}
F_104 ( V_6 -> V_263 . V_266 ) ;
V_6 -> V_263 . V_266 = NULL ;
F_104 ( V_6 -> V_263 . V_267 ) ;
V_6 -> V_263 . V_267 = NULL ;
F_100 ( V_62 ) ;
F_79 ( V_62 , NULL , NULL , NULL ) ;
F_98 ( V_6 ) ;
F_219 ( & V_6 -> V_214 . V_268 ) ;
F_220 ( V_13 ) ;
F_221 ( V_6 -> V_197 ) ;
F_95 ( V_13 ) ;
F_68 ( V_6 ) ;
F_222 ( V_6 ) ;
F_99 ( V_6 ) ;
F_173 ( V_6 ) ;
F_148 ( V_6 ) ;
F_223 ( V_6 , V_262 ) ;
F_139 ( V_6 ) ;
}
static int F_224 ( struct V_32 * V_13 , struct V_60 * V_269 )
{
int V_26 ;
V_26 = F_225 ( V_13 , V_269 ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
static void F_226 ( struct V_32 * V_13 )
{
F_227 ( V_13 ) ;
F_228 () ;
}
static void F_229 ( struct V_32 * V_13 , struct V_60 * V_269 )
{
F_69 ( & V_13 -> V_166 ) ;
F_230 ( V_13 , V_269 ) ;
F_231 ( V_13 , V_269 ) ;
F_72 ( & V_13 -> V_166 ) ;
}
static void F_232 ( struct V_32 * V_13 , struct V_60 * V_269 )
{
struct V_270 * V_61 = V_269 -> V_271 ;
F_104 ( V_61 ) ;
}
static void F_233 ( struct V_5 * V_6 )
{
struct V_32 * V_13 = & V_6 -> V_12 ;
struct V_272 * V_273 ;
F_234 ( V_13 ) ;
F_235 (dev, encoder)
if ( V_273 -> V_274 )
V_273 -> V_274 ( V_273 ) ;
F_236 ( V_13 ) ;
}
static bool F_237 ( struct V_5 * V_6 )
{
#if F_209 ( V_275 )
if ( F_238 () < V_276 )
return true ;
#endif
return false ;
}
static int F_239 ( struct V_32 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
struct V_33 * V_62 = V_6 -> V_12 . V_62 ;
T_6 V_277 ;
int error ;
F_69 ( & V_6 -> V_221 ) ;
V_6 -> V_278 = V_279 ;
F_72 ( & V_6 -> V_221 ) ;
F_240 ( V_6 ) ;
F_241 ( V_6 , true ) ;
F_242 ( V_13 ) ;
F_243 ( V_62 ) ;
error = F_94 ( V_13 ) ;
if ( error ) {
F_244 ( & V_62 -> V_13 ,
L_47 ) ;
goto V_170;
}
F_245 ( V_13 ) ;
F_246 ( V_13 ) ;
F_247 ( V_13 ) ;
F_248 ( V_6 ) ;
F_249 ( V_6 ) ;
F_233 ( V_6 ) ;
F_250 ( V_6 ) ;
F_251 ( V_6 ) ;
F_252 ( V_13 ) ;
V_277 = F_237 ( V_6 ) ? V_280 : V_281 ;
F_253 ( V_6 , V_277 ) ;
F_254 ( V_6 , false ) ;
F_194 ( V_6 ) ;
F_255 ( V_13 , V_282 , true ) ;
V_6 -> V_283 ++ ;
F_256 ( V_6 ) ;
V_170:
F_257 ( V_6 ) ;
return error ;
}
static int F_258 ( struct V_32 * V_13 , bool V_284 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
struct V_33 * V_62 = V_6 -> V_12 . V_62 ;
bool V_285 ;
int V_26 ;
F_240 ( V_6 ) ;
F_241 ( V_6 , false ) ;
V_285 = ! F_259 ( V_6 ) &&
F_237 ( V_6 ) && V_6 -> V_286 . V_287 ;
if ( ! V_285 )
F_260 ( V_6 ) ;
V_26 = 0 ;
if ( F_259 ( V_6 ) )
F_261 ( V_6 ) ;
else if ( F_13 ( V_6 ) || F_14 ( V_6 ) )
F_262 ( V_6 ) ;
else if ( F_53 ( V_6 ) || F_54 ( V_6 ) )
V_26 = F_263 ( V_6 ) ;
if ( V_26 ) {
F_42 ( L_48 , V_26 ) ;
if ( ! V_285 )
F_83 ( V_6 , true ) ;
goto V_170;
}
F_212 ( V_62 ) ;
if ( ! ( V_284 && F_26 ( V_6 ) < 6 ) )
F_64 ( V_62 , V_288 ) ;
V_6 -> V_289 = F_237 ( V_6 ) ;
V_170:
F_257 ( V_6 ) ;
return V_26 ;
}
int F_66 ( struct V_32 * V_13 , T_5 V_150 )
{
int error ;
if ( ! V_13 ) {
F_42 ( L_49 , V_13 ) ;
F_42 ( L_50 ) ;
return - V_68 ;
}
if ( F_264 ( V_150 . V_157 != V_158 &&
V_150 . V_157 != V_290 ) )
return - V_123 ;
if ( V_13 -> V_160 == V_164 )
return 0 ;
error = F_239 ( V_13 ) ;
if ( error )
return error ;
return F_258 ( V_13 , false ) ;
}
static int F_265 ( struct V_32 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
int V_26 ;
F_240 ( V_6 ) ;
F_266 ( V_6 ) ;
V_26 = F_159 ( V_6 ) ;
if ( V_26 )
F_42 ( L_51 ) ;
F_267 ( V_6 ) ;
F_268 ( V_13 ) ;
F_269 ( V_13 ) ;
F_270 ( V_6 ) ;
F_167 ( V_6 ) ;
F_271 ( V_13 ) ;
F_272 ( V_13 ) ;
F_273 ( V_6 ) ;
F_69 ( & V_13 -> V_166 ) ;
if ( F_274 ( V_13 ) ) {
F_42 ( L_52 ) ;
F_275 ( V_6 ) ;
}
F_72 ( & V_13 -> V_166 ) ;
F_276 ( V_13 ) ;
F_277 ( V_13 ) ;
F_278 ( & V_6 -> V_213 ) ;
if ( V_6 -> V_291 . V_292 )
V_6 -> V_291 . V_292 ( V_6 ) ;
F_279 ( & V_6 -> V_213 ) ;
F_280 ( V_13 ) ;
F_281 ( V_13 ) ;
F_282 ( V_13 ) ;
F_92 ( V_6 ) ;
F_185 ( V_6 ) ;
F_255 ( V_13 , V_293 , false ) ;
F_69 ( & V_6 -> V_221 ) ;
V_6 -> V_278 = V_294 ;
F_72 ( & V_6 -> V_221 ) ;
F_253 ( V_6 , V_162 ) ;
F_283 ( V_6 ) ;
F_257 ( V_6 ) ;
return 0 ;
}
static int F_284 ( struct V_32 * V_13 )
{
struct V_5 * V_6 = F_18 ( V_13 ) ;
struct V_33 * V_62 = V_6 -> V_12 . V_62 ;
int V_26 ;
V_26 = F_64 ( V_62 , V_162 ) ;
if ( V_26 ) {
F_42 ( L_53 , V_26 ) ;
goto V_170;
}
if ( F_203 ( V_62 ) ) {
V_26 = - V_231 ;
goto V_170;
}
F_160 ( V_62 ) ;
F_240 ( V_6 ) ;
if ( F_53 ( V_6 ) || F_54 ( V_6 ) )
V_26 = F_285 ( V_6 , false ) ;
if ( V_26 )
F_42 ( L_54 ,
V_26 ) ;
F_286 ( V_6 , true ) ;
if ( F_259 ( V_6 ) ) {
if ( ! V_6 -> V_289 )
F_287 ( V_6 ) ;
F_288 ( V_6 ) ;
} else if ( F_13 ( V_6 ) || F_14 ( V_6 ) ) {
F_289 ( V_6 ) ;
}
F_166 ( V_6 ) ;
if ( F_259 ( V_6 ) ||
! ( V_6 -> V_289 && V_6 -> V_286 . V_287 ) )
F_83 ( V_6 , true ) ;
F_257 ( V_6 ) ;
V_170:
V_6 -> V_289 = false ;
return V_26 ;
}
int F_65 ( struct V_32 * V_13 )
{
int V_26 ;
if ( V_13 -> V_160 == V_164 )
return 0 ;
V_26 = F_284 ( V_13 ) ;
if ( V_26 )
return V_26 ;
return F_265 ( V_13 ) ;
}
static void F_290 ( struct V_5 * V_6 )
{
struct V_295 * V_77 ;
enum V_296 V_40 ;
F_291 ( V_6 -> V_12 . V_297 ) ;
F_292 (engine, dev_priv, id)
F_293 ( & V_77 -> V_298 ) ;
}
static void F_294 ( struct V_5 * V_6 )
{
F_295 ( V_6 -> V_12 . V_297 ) ;
}
void F_296 ( struct V_5 * V_6 )
{
struct V_32 * V_13 = & V_6 -> V_12 ;
struct V_299 * error = & V_6 -> V_214 ;
int V_26 ;
F_297 ( & V_13 -> V_166 ) ;
if ( ! F_298 ( V_300 , & error -> V_135 ) )
return;
F_299 ( V_301 , & error -> V_135 ) ;
error -> V_302 ++ ;
F_300 ( L_55 ) ;
F_290 ( V_6 ) ;
V_26 = F_301 ( V_6 , V_303 ) ;
F_294 ( V_6 ) ;
if ( V_26 ) {
if ( V_26 != - V_68 )
F_42 ( L_56 , V_26 ) ;
else
F_48 ( L_57 ) ;
goto error;
}
F_302 ( V_6 ) ;
F_303 ( V_6 ) ;
V_26 = F_274 ( V_13 ) ;
if ( V_26 ) {
F_42 ( L_58 , V_26 ) ;
goto error;
}
V_304:
F_304 ( & error -> V_135 , V_300 ) ;
return;
error:
F_275 ( V_6 ) ;
goto V_304;
}
static int F_305 ( struct V_10 * V_11 )
{
struct V_33 * V_62 = F_306 ( V_11 ) ;
struct V_32 * V_13 = F_62 ( V_62 ) ;
if ( ! V_13 ) {
F_244 ( V_11 , L_50 ) ;
return - V_68 ;
}
if ( V_13 -> V_160 == V_164 )
return 0 ;
return F_239 ( V_13 ) ;
}
static int F_307 ( struct V_10 * V_11 )
{
struct V_32 * V_13 = & F_308 ( V_11 ) -> V_12 ;
if ( V_13 -> V_160 == V_164 )
return 0 ;
return F_258 ( V_13 , false ) ;
}
static int F_309 ( struct V_10 * V_11 )
{
struct V_32 * V_13 = & F_308 ( V_11 ) -> V_12 ;
if ( V_13 -> V_160 == V_164 )
return 0 ;
return F_258 ( V_13 , true ) ;
}
static int F_310 ( struct V_10 * V_11 )
{
struct V_32 * V_13 = & F_308 ( V_11 ) -> V_12 ;
if ( V_13 -> V_160 == V_164 )
return 0 ;
return F_284 ( V_13 ) ;
}
static int F_311 ( struct V_10 * V_11 )
{
struct V_32 * V_13 = & F_308 ( V_11 ) -> V_12 ;
if ( V_13 -> V_160 == V_164 )
return 0 ;
return F_265 ( V_13 ) ;
}
static int F_312 ( struct V_10 * V_11 )
{
int V_26 ;
V_26 = F_305 ( V_11 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_313 ( F_308 ( V_11 ) ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
static int F_314 ( struct V_10 * V_11 )
{
int V_26 ;
V_26 = F_307 ( V_11 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_315 ( F_308 ( V_11 ) ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
static int F_316 ( struct V_10 * V_11 )
{
return F_310 ( V_11 ) ;
}
static int F_317 ( struct V_10 * V_11 )
{
return F_311 ( V_11 ) ;
}
static int F_318 ( struct V_10 * V_11 )
{
return F_310 ( V_11 ) ;
}
static int F_319 ( struct V_10 * V_11 )
{
return F_311 ( V_11 ) ;
}
static void F_320 ( struct V_5 * V_6 )
{
struct V_305 * V_306 = & V_6 -> V_305 ;
int V_307 ;
V_306 -> V_308 = F_321 ( V_309 ) ;
V_306 -> V_310 = F_321 ( V_311 ) ;
V_306 -> V_312 = F_321 ( V_313 ) ;
V_306 -> V_314 = F_321 ( V_315 ) ;
V_306 -> V_316 = F_321 ( V_317 ) ;
for ( V_307 = 0 ; V_307 < F_322 ( V_306 -> V_318 ) ; V_307 ++ )
V_306 -> V_318 [ V_307 ] = F_321 ( F_323 ( V_307 ) ) ;
V_306 -> V_319 = F_321 ( V_320 ) ;
V_306 -> V_321 = F_321 ( V_322 ) ;
V_306 -> V_323 = F_321 ( V_324 ) ;
V_306 -> V_325 = F_321 ( V_326 ) ;
V_306 -> V_327 = F_321 ( V_328 ) ;
V_306 -> V_329 = F_321 ( V_330 ) ;
V_306 -> V_331 = F_321 ( V_332 ) ;
V_306 -> V_333 = F_321 ( V_334 ) ;
V_306 -> V_335 = F_321 ( V_336 ) ;
V_306 -> V_337 = F_321 ( V_338 ) ;
V_306 -> V_339 = F_321 ( V_340 ) ;
V_306 -> V_341 = F_321 ( V_342 ) ;
V_306 -> V_343 = F_321 ( V_344 ) ;
V_306 -> V_345 = F_321 ( V_346 ) ;
V_306 -> V_347 = F_321 ( V_348 ) ;
V_306 -> V_349 = F_321 ( V_350 ) ;
V_306 -> V_351 = F_321 ( V_352 ) ;
V_306 -> V_353 = F_321 ( V_354 ) ;
V_306 -> V_355 = F_321 ( V_356 ) ;
V_306 -> V_357 = F_321 ( V_358 ) ;
V_306 -> V_359 = F_321 ( V_360 ) ;
V_306 -> V_361 = F_321 ( V_362 ) ;
V_306 -> V_363 = F_321 ( V_364 ) ;
V_306 -> V_365 = F_321 ( V_366 ) ;
V_306 -> V_367 = F_321 ( V_368 ) ;
V_306 -> V_369 = F_321 ( V_370 ) ;
V_306 -> V_371 = F_321 ( V_372 ) ;
V_306 -> V_373 = F_321 ( V_374 ) ;
V_306 -> V_375 = F_321 ( V_376 ) ;
V_306 -> V_377 = F_321 ( V_378 ) ;
for ( V_307 = 0 ; V_307 < F_322 ( V_306 -> V_379 ) ; V_307 ++ )
V_306 -> V_379 [ V_307 ] = F_321 ( F_324 ( V_307 ) ) ;
V_306 -> V_380 = F_321 ( V_381 ) ;
V_306 -> V_382 = F_321 ( V_383 ) ;
V_306 -> V_384 = F_321 ( V_385 ) ;
V_306 -> V_386 = F_321 ( V_387 ) ;
V_306 -> V_388 = F_321 ( V_389 ) ;
V_306 -> V_390 = F_321 ( V_391 ) ;
V_306 -> V_392 = F_321 ( V_393 ) ;
V_306 -> V_394 = F_321 ( V_395 ) ;
V_306 -> V_396 = F_321 ( V_397 ) ;
}
static void F_325 ( struct V_5 * V_6 )
{
struct V_305 * V_306 = & V_6 -> V_305 ;
T_3 V_398 ;
int V_307 ;
F_179 ( V_309 , V_306 -> V_308 ) ;
F_179 ( V_311 , V_306 -> V_310 ) ;
F_179 ( V_313 , V_306 -> V_312 | ( 0xffff << 16 ) ) ;
F_179 ( V_315 , V_306 -> V_314 ) ;
F_179 ( V_317 , V_306 -> V_316 ) ;
for ( V_307 = 0 ; V_307 < F_322 ( V_306 -> V_318 ) ; V_307 ++ )
F_179 ( F_323 ( V_307 ) , V_306 -> V_318 [ V_307 ] ) ;
F_179 ( V_320 , V_306 -> V_319 ) ;
F_179 ( V_322 , V_306 -> V_321 ) ;
F_179 ( V_324 , V_306 -> V_323 ) ;
F_179 ( V_326 , V_306 -> V_325 ) ;
F_179 ( V_328 , V_306 -> V_327 ) ;
F_179 ( V_330 , V_306 -> V_329 ) ;
F_179 ( V_332 , V_306 -> V_331 ) ;
F_179 ( V_334 , V_306 -> V_333 ) ;
F_179 ( V_336 , V_306 -> V_335 ) ;
F_179 ( V_338 , V_306 -> V_337 ) ;
F_179 ( V_340 , V_306 -> V_339 ) ;
F_179 ( V_342 , V_306 -> V_341 ) ;
F_179 ( V_344 , V_306 -> V_343 ) ;
F_179 ( V_346 , V_306 -> V_345 ) ;
F_179 ( V_348 , V_306 -> V_347 ) ;
F_179 ( V_350 , V_306 -> V_349 ) ;
F_179 ( V_352 , V_306 -> V_351 ) ;
F_179 ( V_354 , V_306 -> V_353 ) ;
F_179 ( V_356 , V_306 -> V_355 ) ;
F_179 ( V_358 , V_306 -> V_357 ) ;
F_179 ( V_360 , V_306 -> V_359 ) ;
F_179 ( V_362 , V_306 -> V_361 ) ;
F_179 ( V_364 , V_306 -> V_363 ) ;
F_179 ( V_366 , V_306 -> V_365 ) ;
F_179 ( V_368 , V_306 -> V_367 ) ;
F_179 ( V_370 , V_306 -> V_369 ) ;
F_179 ( V_372 , V_306 -> V_371 ) ;
F_179 ( V_374 , V_306 -> V_373 ) ;
F_179 ( V_376 , V_306 -> V_375 ) ;
F_179 ( V_378 , V_306 -> V_377 ) ;
for ( V_307 = 0 ; V_307 < F_322 ( V_306 -> V_379 ) ; V_307 ++ )
F_179 ( F_324 ( V_307 ) , V_306 -> V_379 [ V_307 ] ) ;
F_179 ( V_381 , V_306 -> V_380 ) ;
F_179 ( V_383 , V_306 -> V_382 ) ;
V_398 = F_321 ( V_385 ) ;
V_398 &= V_399 ;
V_398 |= V_306 -> V_384 & ~ V_399 ;
F_179 ( V_385 , V_398 ) ;
V_398 = F_321 ( V_387 ) ;
V_398 &= V_400 ;
V_398 |= V_306 -> V_386 & ~ V_400 ;
F_179 ( V_387 , V_398 ) ;
F_179 ( V_389 , V_306 -> V_388 ) ;
F_179 ( V_391 , V_306 -> V_390 ) ;
F_179 ( V_393 , V_306 -> V_392 ) ;
F_179 ( V_395 , V_306 -> V_394 ) ;
F_179 ( V_397 , V_306 -> V_396 ) ;
}
int F_326 ( struct V_5 * V_6 , bool V_401 )
{
T_3 V_398 ;
int V_402 ;
V_398 = F_321 ( V_387 ) ;
V_398 &= ~ V_400 ;
if ( V_401 )
V_398 |= V_400 ;
F_179 ( V_387 , V_398 ) ;
if ( ! V_401 )
return 0 ;
V_402 = F_327 ( V_6 ,
V_387 ,
V_403 ,
V_403 ,
20 ) ;
if ( V_402 )
F_42 ( L_59 ,
F_321 ( V_387 ) ) ;
return V_402 ;
}
static int F_328 ( struct V_5 * V_6 , bool V_404 )
{
T_3 V_398 ;
int V_402 = 0 ;
V_398 = F_321 ( V_385 ) ;
V_398 &= ~ V_399 ;
if ( V_404 )
V_398 |= V_399 ;
F_179 ( V_385 , V_398 ) ;
F_329 ( V_385 ) ;
V_402 = F_327 ( V_6 ,
V_405 ,
V_406 ,
V_404 ,
1 ) ;
if ( V_402 )
F_42 ( L_60 ) ;
return V_402 ;
}
static int F_330 ( struct V_5 * V_6 ,
bool V_407 )
{
T_3 V_408 ;
T_3 V_398 ;
int V_402 ;
V_408 = V_409 | V_410 ;
V_398 = V_407 ? V_408 : 0 ;
if ( ( F_321 ( V_405 ) & V_408 ) == V_398 )
return 0 ;
F_10 ( L_61 ,
F_331 ( V_407 ) ,
F_321 ( V_405 ) ) ;
V_402 = F_327 ( V_6 ,
V_405 , V_408 , V_398 ,
3 ) ;
if ( V_402 )
F_42 ( L_62 ,
F_331 ( V_407 ) ) ;
return V_402 ;
}
static void F_332 ( struct V_5 * V_6 )
{
if ( ! ( F_321 ( V_405 ) & V_411 ) )
return;
F_48 ( L_63 ) ;
F_179 ( V_405 , V_411 ) ;
}
static int F_263 ( struct V_5 * V_6 )
{
T_3 V_408 ;
int V_402 ;
( void ) F_330 ( V_6 , false ) ;
V_408 = V_412 | V_413 ;
F_21 ( ( F_321 ( V_385 ) & V_408 ) != V_408 ) ;
F_332 ( V_6 ) ;
V_402 = F_326 ( V_6 , true ) ;
if ( V_402 )
goto V_414;
V_402 = F_328 ( V_6 , false ) ;
if ( V_402 )
goto V_415;
if ( ! F_54 ( V_6 ) )
F_320 ( V_6 ) ;
V_402 = F_326 ( V_6 , false ) ;
if ( V_402 )
goto V_415;
return 0 ;
V_415:
F_328 ( V_6 , true ) ;
V_414:
F_326 ( V_6 , false ) ;
return V_402 ;
}
static int F_285 ( struct V_5 * V_6 ,
bool V_416 )
{
int V_402 ;
int V_26 ;
V_26 = F_326 ( V_6 , true ) ;
if ( ! F_54 ( V_6 ) )
F_325 ( V_6 ) ;
V_402 = F_328 ( V_6 , true ) ;
if ( ! V_26 )
V_26 = V_402 ;
V_402 = F_326 ( V_6 , false ) ;
if ( ! V_26 )
V_26 = V_402 ;
F_332 ( V_6 ) ;
if ( V_416 )
F_333 ( V_6 ) ;
return V_26 ;
}
static int F_334 ( struct V_10 * V_11 )
{
struct V_33 * V_62 = F_306 ( V_11 ) ;
struct V_32 * V_13 = F_62 ( V_62 ) ;
struct V_5 * V_6 = F_18 ( V_13 ) ;
int V_26 ;
if ( F_264 ( ! ( V_6 -> V_417 . V_143 && F_335 () ) ) )
return - V_68 ;
if ( F_264 ( ! F_336 ( V_6 ) ) )
return - V_68 ;
F_10 ( L_64 ) ;
F_240 ( V_6 ) ;
F_337 ( V_6 ) ;
F_245 ( V_13 ) ;
F_248 ( V_6 ) ;
V_26 = 0 ;
if ( F_259 ( V_6 ) ) {
F_338 ( V_6 ) ;
F_261 ( V_6 ) ;
} else if ( F_13 ( V_6 ) || F_14 ( V_6 ) ) {
F_262 ( V_6 ) ;
} else if ( F_53 ( V_6 ) || F_54 ( V_6 ) ) {
V_26 = F_263 ( V_6 ) ;
}
if ( V_26 ) {
F_42 ( L_65 , V_26 ) ;
F_273 ( V_6 ) ;
F_257 ( V_6 ) ;
return V_26 ;
}
F_254 ( V_6 , false ) ;
F_257 ( V_6 ) ;
F_264 ( F_339 ( & V_6 -> V_418 . V_419 ) ) ;
if ( F_340 ( V_6 ) )
F_42 ( L_66 ) ;
V_6 -> V_418 . V_420 = true ;
if ( F_14 ( V_6 ) ) {
F_253 ( V_6 , V_288 ) ;
} else {
F_253 ( V_6 , V_280 ) ;
}
F_341 ( V_6 ) ;
if ( ! F_53 ( V_6 ) && ! F_54 ( V_6 ) )
F_342 ( V_6 ) ;
F_10 ( L_67 ) ;
return 0 ;
}
static int F_343 ( struct V_10 * V_11 )
{
struct V_33 * V_62 = F_306 ( V_11 ) ;
struct V_32 * V_13 = F_62 ( V_62 ) ;
struct V_5 * V_6 = F_18 ( V_13 ) ;
int V_26 = 0 ;
if ( F_264 ( ! F_336 ( V_6 ) ) )
return - V_68 ;
F_10 ( L_68 ) ;
F_264 ( F_339 ( & V_6 -> V_418 . V_419 ) ) ;
F_240 ( V_6 ) ;
F_253 ( V_6 , V_162 ) ;
V_6 -> V_418 . V_420 = false ;
if ( F_344 ( V_6 ) )
F_48 ( L_69 ) ;
F_276 ( V_13 ) ;
if ( F_11 ( V_6 ) )
F_271 ( V_13 ) ;
if ( F_259 ( V_6 ) ) {
F_288 ( V_6 ) ;
F_345 ( V_6 , true ) ;
if ( V_6 -> V_286 . V_287 &&
( V_6 -> V_286 . V_421 & V_422 ) )
F_346 ( V_6 ) ;
} else if ( F_13 ( V_6 ) || F_14 ( V_6 ) ) {
F_289 ( V_6 ) ;
} else if ( F_53 ( V_6 ) || F_54 ( V_6 ) ) {
V_26 = F_285 ( V_6 , true ) ;
}
F_347 ( V_6 ) ;
F_348 ( V_6 ) ;
F_273 ( V_6 ) ;
if ( ! F_53 ( V_6 ) && ! F_54 ( V_6 ) )
F_92 ( V_6 ) ;
F_257 ( V_6 ) ;
if ( V_26 )
F_42 ( L_70 , V_26 ) ;
else
F_10 ( L_71 ) ;
return V_26 ;
}
static int
F_349 ( struct V_32 * V_13 , void * V_59 ,
struct V_60 * V_269 )
{
return - V_68 ;
}
