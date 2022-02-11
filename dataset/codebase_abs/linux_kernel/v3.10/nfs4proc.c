static int F_1 ( int V_1 )
{
if ( V_1 >= - 1000 )
return V_1 ;
switch ( V_1 ) {
case - V_2 :
case - V_3 :
case - V_4 :
return - V_5 ;
case - V_6 :
return - V_7 ;
case - V_8 :
case - V_9 :
return - V_10 ;
case - V_11 :
return - V_12 ;
case - V_13 :
return - V_14 ;
case - V_15 :
return - V_12 ;
case - V_16 :
return - V_17 ;
default:
F_2 ( L_1 ,
V_18 , - V_1 ) ;
break;
}
return - V_19 ;
}
static void F_3 ( T_1 V_20 , T_2 * V_21 , struct V_22 * V_22 ,
struct V_23 * V_24 )
{
T_2 * V_25 , * V_26 ;
if ( V_20 > 2 ) {
V_24 -> V_20 = V_20 ;
memcpy ( & V_24 -> V_21 , V_21 , sizeof( V_24 -> V_21 ) ) ;
return;
}
V_24 -> V_20 = 0 ;
memset ( & V_24 -> V_21 , 0 , sizeof( V_24 -> V_21 ) ) ;
if ( V_20 == 2 )
return;
V_25 = V_26 = F_4 ( * V_24 -> V_27 ) ;
if ( V_20 == 0 ) {
* V_26 ++ = V_28 ;
* V_26 ++ = V_29 ;
* V_26 ++ = V_28 ;
* V_26 ++ = V_28 ;
memcpy ( V_26 , L_2 , 4 ) ;
V_26 ++ ;
* V_26 ++ = V_28 ;
* V_26 ++ = F_5 ( V_30 ) ;
* V_26 ++ = F_5 ( 8 ) ;
V_26 = F_6 ( V_26 , F_7 ( V_22 -> V_31 ) ) ;
}
* V_26 ++ = V_28 ;
* V_26 ++ = V_29 ;
* V_26 ++ = V_32 ;
* V_26 ++ = V_32 ;
memcpy ( V_26 , L_3 , 4 ) ;
V_26 ++ ;
* V_26 ++ = V_28 ;
* V_26 ++ = F_5 ( V_30 ) ;
* V_26 ++ = F_5 ( 8 ) ;
V_26 = F_6 ( V_26 , F_7 ( V_22 -> V_33 -> V_31 ) ) ;
V_24 -> V_34 = ( char * ) V_26 - ( char * ) V_25 ;
V_24 -> V_35 -= V_24 -> V_34 ;
F_8 ( V_25 ) ;
}
static int F_9 ( struct V_36 * V_37 , long * V_38 )
{
int V_39 = 0 ;
F_10 () ;
if ( * V_38 <= 0 )
* V_38 = V_40 ;
if ( * V_38 > V_41 )
* V_38 = V_41 ;
F_11 ( * V_38 ) ;
if ( F_12 ( V_42 ) )
V_39 = - V_43 ;
* V_38 <<= 1 ;
return V_39 ;
}
static int F_13 ( struct V_44 * V_45 , int V_46 , struct V_47 * V_48 )
{
struct V_49 * V_50 = V_45 -> V_49 ;
struct V_51 * V_52 = V_48 -> V_52 ;
struct V_53 * V_53 = V_48 -> V_53 ;
int V_54 = V_46 ;
V_48 -> V_55 = 0 ;
switch( V_46 ) {
case 0 :
return 0 ;
case - V_56 :
if ( V_53 && F_14 ( V_53 , V_57 ) ) {
F_15 ( V_53 ) ;
V_48 -> V_55 = 1 ;
return 0 ;
}
if ( V_52 == NULL )
break;
V_54 = F_16 ( V_45 , V_52 ) ;
if ( V_54 < 0 )
break;
goto V_58;
case - V_59 :
case - V_60 :
case - V_61 :
if ( V_53 != NULL && F_14 ( V_53 , V_57 ) ) {
F_17 ( V_53 ) ;
V_48 -> V_55 = 1 ;
break;
}
if ( V_52 == NULL )
break;
V_54 = F_16 ( V_45 , V_52 ) ;
if ( V_54 < 0 )
break;
goto V_58;
case - V_62 :
if ( V_52 != NULL ) {
V_54 = F_16 ( V_45 , V_52 ) ;
if ( V_54 < 0 )
break;
}
case - V_63 :
case - V_64 :
F_18 ( V_50 ) ;
goto V_58;
#if F_19 ( V_65 )
case - V_66 :
case - V_67 :
case - V_68 :
case - V_69 :
case - V_70 :
case - V_71 :
case - V_72 :
F_2 ( L_4 , V_18 ,
V_46 ) ;
F_20 ( V_50 -> V_73 , V_46 ) ;
goto V_58;
#endif
case - V_16 :
if ( V_48 -> V_38 > V_74 ) {
V_54 = - V_17 ;
break;
}
case - V_75 :
case - V_76 :
V_54 = F_9 ( V_45 -> V_77 , & V_48 -> V_38 ) ;
if ( V_54 != 0 )
break;
case - V_78 :
case - V_79 :
V_48 -> V_55 = 1 ;
break;
case - V_8 :
case - V_9 :
if ( V_45 -> V_80 & V_81 ) {
V_45 -> V_80 &= ~ V_81 ;
V_48 -> V_55 = 1 ;
F_21 ( V_82 L_5
L_6
L_7
L_8 ,
V_45 -> V_49 -> V_83 ) ;
}
}
return F_1 ( V_54 ) ;
V_58:
V_54 = F_22 ( V_50 ) ;
if ( V_54 == 0 )
V_48 -> V_55 = 1 ;
return V_54 ;
}
static void F_23 ( struct V_49 * V_50 , unsigned long V_84 )
{
F_24 ( & V_50 -> V_85 ) ;
if ( F_25 ( V_50 -> V_86 , V_84 ) )
V_50 -> V_86 = V_84 ;
F_26 ( & V_50 -> V_85 ) ;
}
static void F_27 ( const struct V_44 * V_45 , unsigned long V_84 )
{
F_23 ( V_45 -> V_49 , V_84 ) ;
}
static void F_28 ( struct V_87 * V_39 )
{
struct V_88 * V_89 ;
struct V_90 * V_91 ;
bool V_92 = false ;
if ( ! V_39 -> V_93 ) {
F_2 ( L_9 , V_18 ) ;
return;
}
V_91 = V_39 -> V_93 -> V_94 ;
V_89 = V_91 -> V_89 ;
F_24 ( & V_91 -> V_95 ) ;
if ( V_91 -> V_96 > V_91 -> V_97 )
V_92 = true ;
if ( F_29 ( V_91 , V_39 -> V_93 ) ) {
V_92 = false ;
goto V_98;
}
F_30 ( V_91 , V_39 -> V_93 ) ;
if ( V_91 -> V_96 != V_99 )
V_92 = false ;
V_98:
F_26 ( & V_91 -> V_95 ) ;
V_39 -> V_93 = NULL ;
if ( V_92 )
F_31 ( V_89 -> V_50 ) ;
}
static int F_32 ( struct V_100 * V_101 , struct V_87 * V_39 )
{
struct V_88 * V_89 ;
struct V_102 * V_103 ;
struct V_49 * V_50 ;
bool V_104 = false ;
int V_54 = 1 ;
if ( ! F_33 ( V_101 ) )
goto V_105;
V_103 = V_39 -> V_93 ;
V_89 = V_103 -> V_94 -> V_89 ;
if ( V_103 -> V_104 ) {
V_103 -> V_104 = 0 ;
V_104 = true ;
}
switch ( V_39 -> V_106 ) {
case 0 :
++ V_103 -> V_107 ;
V_50 = V_89 -> V_50 ;
F_23 ( V_50 , V_39 -> V_108 ) ;
if ( V_39 -> V_109 != 0 )
F_18 ( V_50 ) ;
F_34 ( V_103 -> V_94 , V_103 , V_39 ) ;
break;
case 1 :
V_103 -> V_104 = 1 ;
goto V_105;
case - V_76 :
F_2 ( L_10 ,
V_18 ,
V_103 -> V_110 ,
V_103 -> V_107 ) ;
goto V_111;
case - V_67 :
goto V_112;
case - V_72 :
if ( V_104 ) {
++ V_103 -> V_107 ;
goto V_112;
}
if ( V_103 -> V_107 != 1 ) {
V_103 -> V_107 = 1 ;
goto V_112;
}
break;
case - V_71 :
++ V_103 -> V_107 ;
goto V_112;
default:
++ V_103 -> V_107 ;
}
V_105:
F_2 ( L_11 , V_18 , V_39 -> V_106 ) ;
F_28 ( V_39 ) ;
return V_54 ;
V_112:
if ( F_35 ( V_101 ) ) {
V_101 -> V_113 = 0 ;
V_54 = 0 ;
}
goto V_105;
V_111:
if ( ! F_36 ( V_101 ) )
goto V_105;
F_37 ( V_101 , V_41 ) ;
return 0 ;
}
static int F_38 ( struct V_100 * V_101 ,
struct V_87 * V_39 )
{
if ( V_39 -> V_93 == NULL )
return 1 ;
return F_32 ( V_101 , V_39 ) ;
}
static void F_39 ( struct V_114 * args ,
struct V_87 * V_39 , int V_115 )
{
args -> V_116 = NULL ;
args -> V_117 = 0 ;
args -> V_118 = 0 ;
if ( V_115 )
args -> V_117 = 1 ;
V_39 -> V_93 = NULL ;
}
static void F_40 ( struct V_114 * args )
{
args -> V_118 = 1 ;
}
int F_41 ( struct V_88 * V_89 ,
struct V_114 * args ,
struct V_87 * V_39 ,
struct V_100 * V_101 )
{
struct V_102 * V_103 ;
struct V_90 * V_91 ;
F_2 ( L_12 , V_18 ) ;
if ( V_39 -> V_93 != NULL )
goto V_119;
V_91 = & V_89 -> V_120 ;
V_101 -> V_121 = 0 ;
F_24 ( & V_91 -> V_95 ) ;
if ( F_42 ( V_122 , & V_91 -> V_123 ) &&
! args -> V_118 ) {
F_2 ( L_13 , V_18 ) ;
goto V_124;
}
V_103 = F_43 ( V_91 ) ;
if ( F_44 ( V_103 ) ) {
if ( V_103 == F_45 ( - V_125 ) )
V_101 -> V_121 = V_74 >> 2 ;
F_2 ( L_14 , V_18 ) ;
goto V_124;
}
F_26 ( & V_91 -> V_95 ) ;
args -> V_116 = V_103 ;
F_2 ( L_15 , V_18 ,
V_103 -> V_110 , V_103 -> V_107 ) ;
V_39 -> V_93 = V_103 ;
V_39 -> V_108 = V_126 ;
V_39 -> V_109 = 0 ;
V_39 -> V_106 = 1 ;
V_119:
F_46 ( V_101 ) ;
return 0 ;
V_124:
if ( args -> V_118 )
F_47 ( & V_91 -> V_127 , V_101 ,
NULL , V_128 ) ;
else
F_48 ( & V_91 -> V_127 , V_101 , NULL ) ;
F_26 ( & V_91 -> V_95 ) ;
return - V_129 ;
}
int F_49 ( const struct V_44 * V_45 ,
struct V_114 * args ,
struct V_87 * V_39 ,
struct V_100 * V_101 )
{
struct V_88 * V_89 = F_50 ( V_45 ) ;
int V_54 = 0 ;
if ( V_89 == NULL ) {
F_46 ( V_101 ) ;
goto V_105;
}
F_2 ( L_16 ,
V_18 , V_89 -> V_50 , V_89 , V_39 -> V_93 ?
V_39 -> V_93 -> V_110 : - 1 ) ;
V_54 = F_41 ( V_89 , args , V_39 , V_101 ) ;
V_105:
F_2 ( L_17 , V_18 , V_54 ) ;
return V_54 ;
}
static void F_51 ( struct V_100 * V_101 , void * V_130 )
{
struct V_131 * V_132 = V_130 ;
struct V_88 * V_89 = F_50 ( V_132 -> V_133 ) ;
F_2 ( L_18 , V_18 , V_132 -> V_133 ) ;
F_41 ( V_89 , V_132 -> V_134 , V_132 -> V_135 , V_101 ) ;
}
static void F_52 ( struct V_100 * V_101 , void * V_130 )
{
struct V_131 * V_132 = V_130 ;
F_32 ( V_101 , V_132 -> V_135 ) ;
}
static int F_53 ( struct V_36 * V_37 ,
struct V_44 * V_45 ,
struct V_136 * V_137 ,
struct V_114 * args ,
struct V_87 * V_39 )
{
int V_54 ;
struct V_100 * V_101 ;
struct V_131 V_132 = {
. V_133 = V_45 ,
. V_134 = args ,
. V_135 = V_39 ,
} ;
struct V_138 V_139 = {
. V_140 = V_37 ,
. V_136 = V_137 ,
. V_141 = & V_142 ,
. V_143 = & V_132
} ;
V_101 = F_54 ( & V_139 ) ;
if ( F_44 ( V_101 ) )
V_54 = F_55 ( V_101 ) ;
else {
V_54 = V_101 -> V_113 ;
F_56 ( V_101 ) ;
}
return V_54 ;
}
static
void F_39 ( struct V_114 * args ,
struct V_87 * V_39 , int V_115 )
{
}
static void F_40 ( struct V_114 * args )
{
}
static int F_38 ( struct V_100 * V_101 ,
struct V_87 * V_39 )
{
return 1 ;
}
static
int F_57 ( struct V_36 * V_37 ,
struct V_44 * V_45 ,
struct V_136 * V_137 ,
struct V_114 * args ,
struct V_87 * V_39 )
{
return F_58 ( V_37 , V_137 , 0 ) ;
}
static
int F_59 ( struct V_36 * V_37 ,
struct V_44 * V_45 ,
struct V_136 * V_137 ,
struct V_114 * args ,
struct V_87 * V_39 ,
int V_115 )
{
F_39 ( args , V_39 , V_115 ) ;
return V_45 -> V_49 -> V_144 -> V_145 ( V_37 , V_45 , V_137 ,
args , V_39 ) ;
}
static void F_60 ( struct V_53 * V_146 , struct V_147 * V_148 )
{
struct V_149 * V_150 = F_61 ( V_146 ) ;
F_24 ( & V_146 -> V_151 ) ;
V_150 -> V_152 |= V_153 | V_154 ;
if ( ! V_148 -> V_155 || V_148 -> V_156 != V_146 -> V_157 )
F_62 ( V_146 ) ;
V_146 -> V_157 = V_148 -> V_158 ;
F_63 ( V_146 ) ;
F_26 ( & V_146 -> V_151 ) ;
}
static bool F_64 ( struct V_44 * V_45 ,
int V_1 , struct V_47 * V_48 )
{
if ( V_1 != - V_10 )
return false ;
if ( ! ( V_45 -> V_80 & V_159 ) )
return false ;
V_45 -> V_80 &= ~ V_159 ;
V_48 -> V_55 = 1 ;
return true ;
}
static enum V_160
F_65 ( struct V_44 * V_45 ,
enum V_160 V_161 )
{
if ( V_45 -> V_80 & V_159 )
return V_161 ;
switch ( V_161 ) {
default:
return V_161 ;
case V_162 :
return V_163 ;
case V_164 :
return V_165 ;
case V_166 :
return V_167 ;
}
}
static void F_66 ( struct V_168 * V_26 )
{
V_26 -> V_169 . V_170 = & V_26 -> V_170 ;
V_26 -> V_169 . V_171 = V_26 -> V_172 . V_171 ;
V_26 -> V_173 . V_171 = V_26 -> V_174 . V_171 ;
V_26 -> V_169 . V_45 = V_26 -> V_172 . V_45 ;
V_26 -> V_169 . V_175 = V_26 -> V_172 . V_176 ;
F_67 ( & V_26 -> V_170 ) ;
F_68 ( & V_26 -> V_170 , & V_26 -> V_177 , & V_26 -> V_178 ) ;
}
static struct V_168 * F_69 ( struct V_22 * V_22 ,
struct V_179 * V_180 , T_3 V_181 , int V_182 ,
const struct V_183 * V_184 ,
enum V_160 V_161 ,
T_4 V_185 )
{
struct V_22 * V_186 = F_70 ( V_22 ) ;
struct V_53 * V_146 = V_186 -> V_31 ;
struct V_44 * V_45 = F_71 ( V_146 ) ;
struct V_168 * V_26 ;
V_26 = F_72 ( sizeof( * V_26 ) , V_185 ) ;
if ( V_26 == NULL )
goto V_1;
V_26 -> V_172 . V_171 = F_73 ( & V_180 -> V_187 , V_185 ) ;
if ( V_26 -> V_172 . V_171 == NULL )
goto V_188;
F_74 ( V_22 -> V_189 ) ;
V_26 -> V_22 = F_75 ( V_22 ) ;
V_26 -> V_146 = V_186 ;
V_26 -> V_190 = V_180 ;
F_76 ( & V_180 -> V_191 ) ;
V_26 -> V_172 . V_192 = V_182 ;
V_26 -> V_172 . V_181 = V_181 & ( V_57 | V_193 ) ;
if ( ! ( V_182 & V_194 ) ) {
V_26 -> V_172 . V_176 = V_195 | V_196 |
V_197 | V_198 ;
}
V_26 -> V_172 . V_199 = V_45 -> V_49 -> V_200 ;
V_26 -> V_172 . V_201 . V_202 = F_77 ( V_180 -> V_187 . V_202 ) ;
V_26 -> V_172 . V_201 . V_203 = V_180 -> V_187 . V_204 ;
V_26 -> V_172 . V_205 = & V_22 -> V_206 ;
V_26 -> V_172 . V_45 = V_45 ;
V_26 -> V_172 . V_207 = V_45 -> V_208 ;
V_26 -> V_172 . V_209 = & V_210 [ 0 ] ;
V_26 -> V_172 . V_161 = F_65 ( V_45 , V_161 ) ;
switch ( V_26 -> V_172 . V_161 ) {
case V_163 :
case V_165 :
case V_167 :
V_26 -> V_172 . V_211 = F_78 ( V_146 ) ;
break;
case V_212 :
case V_162 :
case V_164 :
case V_166 :
V_26 -> V_172 . V_211 = F_78 ( V_22 -> V_31 ) ;
}
if ( V_184 != NULL && V_184 -> V_213 != 0 ) {
T_2 V_214 [ 2 ] ;
V_26 -> V_172 . V_215 . V_184 = & V_26 -> V_184 ;
memcpy ( & V_26 -> V_184 , V_184 , sizeof( V_26 -> V_184 ) ) ;
V_214 [ 0 ] = V_126 ;
V_214 [ 1 ] = V_42 -> V_216 ;
memcpy ( V_26 -> V_172 . V_215 . V_21 . V_132 , V_214 ,
sizeof( V_26 -> V_172 . V_215 . V_21 . V_132 ) ) ;
}
V_26 -> V_174 . V_211 = & V_26 -> V_169 . V_211 ;
V_26 -> V_174 . V_217 = & V_26 -> V_169 . V_217 ;
V_26 -> V_174 . V_171 = V_26 -> V_172 . V_171 ;
F_66 ( V_26 ) ;
F_79 ( & V_26 -> V_218 ) ;
return V_26 ;
V_188:
F_80 ( V_26 ) ;
V_1:
F_81 ( V_186 ) ;
return NULL ;
}
static void F_82 ( struct V_218 * V_218 )
{
struct V_168 * V_26 = F_83 ( V_218 ,
struct V_168 , V_218 ) ;
struct V_219 * V_220 = V_26 -> V_22 -> V_189 ;
F_84 ( V_26 -> V_172 . V_171 ) ;
if ( V_26 -> V_52 != NULL )
F_85 ( V_26 -> V_52 ) ;
F_86 ( V_26 -> V_190 ) ;
F_81 ( V_26 -> V_146 ) ;
F_81 ( V_26 -> V_22 ) ;
F_87 ( V_220 ) ;
F_88 ( & V_26 -> V_170 ) ;
F_80 ( V_26 ) ;
}
static void F_89 ( struct V_168 * V_26 )
{
if ( V_26 != NULL )
F_90 ( & V_26 -> V_218 , F_82 ) ;
}
static int F_91 ( struct V_100 * V_101 )
{
int V_54 ;
V_54 = F_92 ( V_101 ) ;
return V_54 ;
}
static int F_93 ( struct V_51 * V_52 , T_3 V_221 , int V_222 )
{
int V_54 = 0 ;
if ( V_222 & ( V_194 | V_223 ) )
goto V_105;
switch ( V_221 & ( V_57 | V_193 ) ) {
case V_57 :
V_54 |= F_42 ( V_224 , & V_52 -> V_182 ) != 0
&& V_52 -> V_225 != 0 ;
break;
case V_193 :
V_54 |= F_42 ( V_226 , & V_52 -> V_182 ) != 0
&& V_52 -> V_227 != 0 ;
break;
case V_57 | V_193 :
V_54 |= F_42 ( V_228 , & V_52 -> V_182 ) != 0
&& V_52 -> V_229 != 0 ;
}
V_105:
return V_54 ;
}
static int F_94 ( struct V_230 * V_231 , T_3 V_181 )
{
if ( V_231 == NULL )
return 0 ;
if ( ( V_231 -> type & V_181 ) != V_181 )
return 0 ;
if ( F_42 ( V_232 , & V_231 -> V_182 ) )
return 0 ;
if ( F_42 ( V_233 , & V_231 -> V_182 ) )
return 0 ;
F_95 ( V_231 ) ;
return 1 ;
}
static void F_96 ( struct V_51 * V_52 , T_3 V_181 )
{
switch ( V_181 ) {
case V_193 :
V_52 -> V_227 ++ ;
break;
case V_57 :
V_52 -> V_225 ++ ;
break;
case V_57 | V_193 :
V_52 -> V_229 ++ ;
}
F_97 ( V_52 , V_52 -> V_52 | V_181 ) ;
}
static void F_98 ( struct V_51 * V_52 , T_5 * V_217 , T_3 V_181 )
{
if ( F_42 ( V_234 , & V_52 -> V_182 ) == 0 )
F_99 ( & V_52 -> V_217 , V_217 ) ;
F_99 ( & V_52 -> V_235 , V_217 ) ;
F_100 ( V_236 , & V_52 -> V_182 ) ;
switch ( V_181 ) {
case V_57 :
F_100 ( V_224 , & V_52 -> V_182 ) ;
break;
case V_193 :
F_100 ( V_226 , & V_52 -> V_182 ) ;
break;
case V_57 | V_193 :
F_100 ( V_228 , & V_52 -> V_182 ) ;
}
}
static void F_101 ( struct V_51 * V_52 , T_5 * V_217 , T_3 V_181 )
{
F_102 ( & V_52 -> V_237 ) ;
F_98 ( V_52 , V_217 , V_181 ) ;
F_103 ( & V_52 -> V_237 ) ;
}
static void F_104 ( struct V_51 * V_52 , T_5 * V_235 , const T_5 * V_238 , T_3 V_181 )
{
F_102 ( & V_52 -> V_237 ) ;
if ( V_238 != NULL ) {
F_99 ( & V_52 -> V_217 , V_238 ) ;
F_100 ( V_234 , & V_52 -> V_182 ) ;
}
if ( V_235 != NULL )
F_98 ( V_52 , V_235 , V_181 ) ;
F_103 ( & V_52 -> V_237 ) ;
F_24 ( & V_52 -> V_190 -> V_239 ) ;
F_96 ( V_52 , V_181 ) ;
F_26 ( & V_52 -> V_190 -> V_239 ) ;
}
static int F_105 ( struct V_51 * V_52 , T_5 * V_235 , T_5 * V_231 , T_3 V_181 )
{
struct V_149 * V_150 = F_61 ( V_52 -> V_53 ) ;
struct V_230 * V_240 ;
int V_54 = 0 ;
V_181 &= ( V_57 | V_193 ) ;
F_106 () ;
V_240 = F_107 ( V_150 -> V_231 ) ;
if ( V_240 == NULL )
goto V_241;
F_24 ( & V_240 -> V_242 ) ;
if ( V_150 -> V_231 != V_240 ||
F_42 ( V_233 , & V_240 -> V_182 ) ||
( V_240 -> type & V_181 ) != V_181 )
goto V_243;
if ( V_231 == NULL )
V_231 = & V_240 -> V_217 ;
else if ( ! F_108 ( & V_240 -> V_217 , V_231 ) )
goto V_243;
F_95 ( V_240 ) ;
F_104 ( V_52 , V_235 , & V_240 -> V_217 , V_181 ) ;
V_54 = 1 ;
V_243:
F_26 ( & V_240 -> V_242 ) ;
V_241:
F_109 () ;
if ( ! V_54 && V_235 != NULL ) {
F_104 ( V_52 , V_235 , NULL , V_181 ) ;
V_54 = 1 ;
}
return V_54 ;
}
static void F_110 ( struct V_53 * V_53 , T_3 V_181 )
{
struct V_230 * V_231 ;
F_106 () ;
V_231 = F_107 ( F_61 ( V_53 ) -> V_231 ) ;
if ( V_231 == NULL || ( V_231 -> type & V_181 ) == V_181 ) {
F_109 () ;
return;
}
F_109 () ;
F_15 ( V_53 ) ;
}
static struct V_51 * F_111 ( struct V_168 * V_244 )
{
struct V_51 * V_52 = V_244 -> V_52 ;
struct V_149 * V_150 = F_61 ( V_52 -> V_53 ) ;
struct V_230 * V_231 ;
int V_222 = V_244 -> V_172 . V_192 ;
T_3 V_181 = V_244 -> V_172 . V_181 ;
T_5 V_217 ;
int V_54 = - V_129 ;
for (; ; ) {
if ( F_93 ( V_52 , V_181 , V_222 ) ) {
F_24 ( & V_52 -> V_190 -> V_239 ) ;
if ( F_93 ( V_52 , V_181 , V_222 ) ) {
F_96 ( V_52 , V_181 ) ;
F_26 ( & V_52 -> V_190 -> V_239 ) ;
goto V_245;
}
F_26 ( & V_52 -> V_190 -> V_239 ) ;
}
F_106 () ;
V_231 = F_107 ( V_150 -> V_231 ) ;
if ( ! F_94 ( V_231 , V_181 ) ) {
F_109 () ;
break;
}
F_99 ( & V_217 , & V_231 -> V_217 ) ;
F_109 () ;
F_112 ( V_244 -> V_172 . V_171 ) ;
if ( ! V_244 -> V_246 ) {
V_54 = F_113 ( V_52 -> V_53 , V_52 -> V_190 -> V_247 , V_222 ) ;
if ( V_54 != 0 )
goto V_105;
}
V_54 = - V_129 ;
if ( F_105 ( V_52 , NULL , & V_217 , V_181 ) )
goto V_245;
}
V_105:
return F_45 ( V_54 ) ;
V_245:
F_76 ( & V_52 -> V_35 ) ;
return V_52 ;
}
static void
F_114 ( struct V_168 * V_132 , struct V_51 * V_52 )
{
struct V_49 * V_50 = F_71 ( V_52 -> V_53 ) -> V_49 ;
struct V_230 * V_231 ;
int V_248 = 0 ;
F_106 () ;
V_231 = F_107 ( F_61 ( V_52 -> V_53 ) -> V_231 ) ;
if ( V_231 )
V_248 = V_231 -> V_182 ;
F_109 () ;
if ( V_132 -> V_172 . V_161 == V_165 ) {
F_115 ( L_19
L_20
L_21 ,
V_50 -> V_83 ) ;
} else if ( ( V_248 & 1UL << V_232 ) == 0 )
F_116 ( V_52 -> V_53 ,
V_132 -> V_190 -> V_247 ,
& V_132 -> V_169 ) ;
else
F_117 ( V_52 -> V_53 ,
V_132 -> V_190 -> V_247 ,
& V_132 -> V_169 ) ;
}
static struct V_51 *
F_118 ( struct V_168 * V_132 )
{
struct V_53 * V_53 = V_132 -> V_52 -> V_53 ;
struct V_51 * V_52 = V_132 -> V_52 ;
int V_54 ;
if ( ! V_132 -> V_249 ) {
V_54 = V_132 -> V_250 ;
goto V_1;
}
V_54 = - V_251 ;
if ( ! ( V_132 -> V_170 . V_252 & V_253 ) ||
! ( V_132 -> V_170 . V_252 & V_254 ) ||
! ( V_132 -> V_170 . V_252 & V_255 ) )
goto V_1;
V_54 = - V_125 ;
V_52 = F_119 ( V_53 , V_132 -> V_190 ) ;
if ( V_52 == NULL )
goto V_1;
V_54 = F_120 ( V_53 , & V_132 -> V_170 ) ;
if ( V_54 )
goto V_1;
if ( V_132 -> V_169 . V_256 != 0 )
F_114 ( V_132 , V_52 ) ;
F_105 ( V_52 , & V_132 -> V_169 . V_217 , NULL ,
V_132 -> V_172 . V_181 ) ;
return V_52 ;
V_1:
return F_45 ( V_54 ) ;
}
static struct V_51 *
F_121 ( struct V_168 * V_132 )
{
struct V_53 * V_53 ;
struct V_51 * V_52 = NULL ;
int V_54 ;
if ( ! V_132 -> V_249 ) {
V_52 = F_111 ( V_132 ) ;
goto V_105;
}
V_54 = - V_129 ;
if ( ! ( V_132 -> V_170 . V_252 & V_257 ) )
goto V_1;
V_53 = F_122 ( V_132 -> V_146 -> V_189 , & V_132 -> V_169 . V_211 , & V_132 -> V_170 ) ;
V_54 = F_55 ( V_53 ) ;
if ( F_44 ( V_53 ) )
goto V_1;
V_54 = - V_125 ;
V_52 = F_119 ( V_53 , V_132 -> V_190 ) ;
if ( V_52 == NULL )
goto V_258;
if ( V_132 -> V_169 . V_256 != 0 )
F_114 ( V_132 , V_52 ) ;
F_105 ( V_52 , & V_132 -> V_169 . V_217 , NULL ,
V_132 -> V_172 . V_181 ) ;
F_123 ( V_53 ) ;
V_105:
F_112 ( V_132 -> V_172 . V_171 ) ;
return V_52 ;
V_258:
F_123 ( V_53 ) ;
V_1:
return F_45 ( V_54 ) ;
}
static struct V_51 *
F_124 ( struct V_168 * V_132 )
{
if ( V_132 -> V_172 . V_161 == V_212 )
return F_118 ( V_132 ) ;
return F_121 ( V_132 ) ;
}
static struct V_259 * F_125 ( struct V_51 * V_52 )
{
struct V_149 * V_150 = F_61 ( V_52 -> V_53 ) ;
struct V_259 * V_260 ;
F_24 ( & V_52 -> V_53 -> V_151 ) ;
F_126 (ctx, &nfsi->open_files, list) {
if ( V_260 -> V_52 != V_52 )
continue;
F_127 ( V_260 ) ;
F_26 ( & V_52 -> V_53 -> V_151 ) ;
return V_260 ;
}
F_26 ( & V_52 -> V_53 -> V_151 ) ;
return F_45 ( - V_261 ) ;
}
static struct V_168 * F_128 ( struct V_259 * V_260 ,
struct V_51 * V_52 , enum V_160 V_161 )
{
struct V_168 * V_244 ;
V_244 = F_69 ( V_260 -> V_22 , V_52 -> V_190 , 0 , 0 ,
NULL , V_161 , V_262 ) ;
if ( V_244 == NULL )
return F_45 ( - V_125 ) ;
V_244 -> V_52 = V_52 ;
F_76 ( & V_52 -> V_35 ) ;
return V_244 ;
}
static int F_129 ( struct V_168 * V_244 , T_3 V_181 , struct V_51 * * V_39 )
{
struct V_51 * V_263 ;
int V_54 ;
V_244 -> V_172 . V_192 = 0 ;
V_244 -> V_172 . V_181 = V_181 ;
memset ( & V_244 -> V_169 , 0 , sizeof( V_244 -> V_169 ) ) ;
memset ( & V_244 -> V_173 , 0 , sizeof( V_244 -> V_173 ) ) ;
F_66 ( V_244 ) ;
V_54 = F_130 ( V_244 ) ;
if ( V_54 != 0 )
return V_54 ;
V_263 = F_124 ( V_244 ) ;
if ( F_44 ( V_263 ) )
return F_55 ( V_263 ) ;
F_131 ( V_263 , V_181 ) ;
* V_39 = V_263 ;
return 0 ;
}
static int F_132 ( struct V_168 * V_244 , struct V_51 * V_52 )
{
struct V_51 * V_263 ;
int V_54 ;
F_133 ( V_234 , & V_52 -> V_182 ) ;
F_133 ( V_236 , & V_52 -> V_182 ) ;
F_134 () ;
if ( V_52 -> V_229 != 0 ) {
F_133 ( V_228 , & V_52 -> V_182 ) ;
V_54 = F_129 ( V_244 , V_57 | V_193 , & V_263 ) ;
if ( V_54 != 0 )
return V_54 ;
if ( V_263 != V_52 )
return - V_251 ;
}
if ( V_52 -> V_227 != 0 ) {
F_133 ( V_226 , & V_52 -> V_182 ) ;
V_54 = F_129 ( V_244 , V_193 , & V_263 ) ;
if ( V_54 != 0 )
return V_54 ;
if ( V_263 != V_52 )
return - V_251 ;
}
if ( V_52 -> V_225 != 0 ) {
F_133 ( V_224 , & V_52 -> V_182 ) ;
V_54 = F_129 ( V_244 , V_57 , & V_263 ) ;
if ( V_54 != 0 )
return V_54 ;
if ( V_263 != V_52 )
return - V_251 ;
}
if ( F_42 ( V_234 , & V_52 -> V_182 ) == 0 &&
! F_108 ( & V_52 -> V_217 , & V_52 -> V_235 ) ) {
F_102 ( & V_52 -> V_237 ) ;
if ( F_42 ( V_234 , & V_52 -> V_182 ) == 0 )
F_99 ( & V_52 -> V_217 , & V_52 -> V_235 ) ;
F_103 ( & V_52 -> V_237 ) ;
}
return 0 ;
}
static int F_135 ( struct V_259 * V_260 , struct V_51 * V_52 )
{
struct V_230 * V_231 ;
struct V_168 * V_244 ;
T_3 V_256 = 0 ;
int V_264 ;
V_244 = F_128 ( V_260 , V_52 ,
V_212 ) ;
if ( F_44 ( V_244 ) )
return F_55 ( V_244 ) ;
F_106 () ;
V_231 = F_107 ( F_61 ( V_52 -> V_53 ) -> V_231 ) ;
if ( V_231 != NULL && F_42 ( V_232 , & V_231 -> V_182 ) != 0 )
V_256 = V_231 -> type ;
F_109 () ;
V_244 -> V_172 . V_215 . V_256 = V_256 ;
V_264 = F_132 ( V_244 , V_52 ) ;
F_89 ( V_244 ) ;
return V_264 ;
}
static int F_136 ( struct V_259 * V_260 , struct V_51 * V_52 )
{
struct V_44 * V_45 = F_71 ( V_52 -> V_53 ) ;
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_135 ( V_260 , V_52 ) ;
if ( F_64 ( V_45 , V_1 , & V_48 ) )
continue;
if ( V_1 != - V_76 )
break;
F_13 ( V_45 , V_1 , & V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static int F_137 ( struct V_179 * V_180 , struct V_51 * V_52 )
{
struct V_259 * V_260 ;
int V_54 ;
V_260 = F_125 ( V_52 ) ;
if ( F_44 ( V_260 ) )
return - V_129 ;
V_54 = F_136 ( V_260 , V_52 ) ;
F_138 ( V_260 ) ;
return V_54 ;
}
static int F_139 ( struct V_44 * V_45 , struct V_51 * V_52 , const T_5 * V_217 , int V_1 )
{
switch ( V_1 ) {
default:
F_21 ( V_265 L_22
L_23 , V_18 , V_1 ) ;
case 0 :
case - V_261 :
case - V_251 :
break;
case - V_66 :
case - V_67 :
case - V_68 :
case - V_69 :
case - V_70 :
F_100 ( V_234 , & V_52 -> V_182 ) ;
F_20 ( V_45 -> V_49 -> V_73 , V_1 ) ;
return - V_129 ;
case - V_64 :
case - V_63 :
F_100 ( V_234 , & V_52 -> V_182 ) ;
case - V_62 :
F_18 ( V_45 -> V_49 ) ;
return - V_129 ;
case - V_59 :
case - V_60 :
case - V_61 :
case - V_56 :
F_140 ( V_52 -> V_53 ,
V_217 ) ;
F_16 ( V_45 , V_52 ) ;
return 0 ;
case - V_76 :
case - V_75 :
F_100 ( V_234 , & V_52 -> V_182 ) ;
F_141 ( 1 ) ;
return - V_129 ;
case - V_125 :
case - V_266 :
return 0 ;
}
return V_1 ;
}
int F_142 ( struct V_259 * V_260 , struct V_51 * V_52 , const T_5 * V_217 )
{
struct V_44 * V_45 = F_71 ( V_52 -> V_53 ) ;
struct V_168 * V_244 ;
int V_1 ;
V_244 = F_128 ( V_260 , V_52 ,
V_164 ) ;
if ( F_44 ( V_244 ) )
return F_55 ( V_244 ) ;
F_99 ( & V_244 -> V_172 . V_215 . V_231 , V_217 ) ;
V_1 = F_132 ( V_244 , V_52 ) ;
F_89 ( V_244 ) ;
return F_139 ( V_45 , V_52 , V_217 , V_1 ) ;
}
static void F_143 ( struct V_100 * V_101 , void * V_130 )
{
struct V_168 * V_132 = V_130 ;
V_132 -> V_250 = V_101 -> V_113 ;
if ( V_132 -> V_250 == 0 ) {
F_99 ( & V_132 -> V_169 . V_217 , & V_132 -> V_173 . V_217 ) ;
F_144 ( & V_132 -> V_190 -> V_187 , 0 ) ;
F_27 ( V_132 -> V_169 . V_45 , V_132 -> V_84 ) ;
V_132 -> V_249 = 1 ;
}
}
static void F_145 ( void * V_130 )
{
struct V_168 * V_132 = V_130 ;
struct V_51 * V_52 = NULL ;
if ( V_132 -> V_267 == 0 )
goto V_268;
if ( ! V_132 -> V_249 )
goto V_268;
V_52 = F_124 ( V_132 ) ;
if ( ! F_44 ( V_52 ) )
F_131 ( V_52 , V_132 -> V_172 . V_181 ) ;
V_268:
F_89 ( V_132 ) ;
}
static int F_146 ( struct V_168 * V_132 )
{
struct V_44 * V_45 = F_71 ( V_132 -> V_146 -> V_31 ) ;
struct V_100 * V_101 ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_271 ] ,
. V_272 = & V_132 -> V_174 ,
. V_273 = & V_132 -> V_173 ,
. V_274 = V_132 -> V_190 -> V_247 ,
} ;
struct V_138 V_275 = {
. V_140 = V_45 -> V_77 ,
. V_136 = & V_137 ,
. V_141 = & V_276 ,
. V_143 = V_132 ,
. V_277 = V_278 ,
. V_182 = V_279 ,
} ;
int V_264 ;
F_147 ( & V_132 -> V_218 ) ;
V_132 -> V_249 = 0 ;
V_132 -> V_250 = 0 ;
V_132 -> V_84 = V_126 ;
V_101 = F_54 ( & V_275 ) ;
if ( F_44 ( V_101 ) )
return F_55 ( V_101 ) ;
V_264 = F_91 ( V_101 ) ;
if ( V_264 != 0 ) {
V_132 -> V_267 = 1 ;
F_148 () ;
} else
V_264 = V_132 -> V_250 ;
F_56 ( V_101 ) ;
return V_264 ;
}
static void F_149 ( struct V_100 * V_101 , void * V_130 )
{
struct V_168 * V_132 = V_130 ;
struct V_179 * V_180 = V_132 -> V_190 ;
struct V_49 * V_50 = V_180 -> V_280 -> V_49 ;
if ( F_150 ( V_132 -> V_172 . V_171 , V_101 ) != 0 )
goto V_281;
if ( V_132 -> V_52 != NULL ) {
struct V_230 * V_231 ;
if ( F_93 ( V_132 -> V_52 , V_132 -> V_172 . V_181 , V_132 -> V_172 . V_192 ) )
goto V_282;
F_106 () ;
V_231 = F_107 ( F_61 ( V_132 -> V_52 -> V_53 ) -> V_231 ) ;
if ( V_132 -> V_172 . V_161 != V_165 &&
V_132 -> V_172 . V_161 != V_164 &&
F_94 ( V_231 , V_132 -> V_172 . V_181 ) )
goto V_283;
F_109 () ;
}
V_132 -> V_172 . V_199 = V_50 -> V_200 ;
switch ( V_132 -> V_172 . V_161 ) {
case V_212 :
case V_164 :
case V_166 :
V_132 -> V_172 . V_209 = & V_284 [ 0 ] ;
case V_162 :
V_101 -> V_285 . V_269 = & V_270 [ V_286 ] ;
F_151 ( & V_132 -> V_169 . V_211 , V_132 -> V_172 . V_211 ) ;
}
V_132 -> V_84 = V_126 ;
if ( F_49 ( V_132 -> V_172 . V_45 ,
& V_132 -> V_172 . V_134 ,
& V_132 -> V_169 . V_135 ,
V_101 ) != 0 )
F_112 ( V_132 -> V_172 . V_171 ) ;
V_132 -> V_172 . V_287 = V_288 ;
if ( V_132 -> V_172 . V_192 & V_194 ) {
V_132 -> V_172 . V_287 = V_289 ;
if ( F_152 ( V_50 ) )
V_132 -> V_172 . V_287 = V_290 ;
else if ( V_50 -> V_144 -> V_291 > 0 )
V_132 -> V_172 . V_287 = V_292 ;
}
return;
V_283:
F_109 () ;
V_282:
V_101 -> V_293 = NULL ;
V_281:
F_38 ( V_101 , & V_132 -> V_169 . V_135 ) ;
}
static void F_153 ( struct V_100 * V_101 , void * V_130 )
{
struct V_168 * V_132 = V_130 ;
V_132 -> V_250 = V_101 -> V_113 ;
if ( ! F_38 ( V_101 , & V_132 -> V_169 . V_135 ) )
return;
if ( V_101 -> V_113 == 0 ) {
if ( V_132 -> V_169 . V_170 -> V_252 & V_253 ) {
switch ( V_132 -> V_169 . V_170 -> V_221 & V_294 ) {
case V_295 :
break;
case V_296 :
V_132 -> V_250 = - V_297 ;
break;
case V_298 :
V_132 -> V_250 = - V_299 ;
break;
default:
V_132 -> V_250 = - V_300 ;
}
}
F_27 ( V_132 -> V_169 . V_45 , V_132 -> V_84 ) ;
if ( ! ( V_132 -> V_169 . V_301 & V_302 ) )
F_144 ( & V_132 -> V_190 -> V_187 , 0 ) ;
}
V_132 -> V_249 = 1 ;
}
static void F_154 ( void * V_130 )
{
struct V_168 * V_132 = V_130 ;
struct V_51 * V_52 = NULL ;
if ( V_132 -> V_267 == 0 )
goto V_268;
if ( V_132 -> V_250 != 0 || ! V_132 -> V_249 )
goto V_268;
if ( V_132 -> V_169 . V_301 & V_302 )
goto V_268;
V_52 = F_124 ( V_132 ) ;
if ( ! F_44 ( V_52 ) )
F_131 ( V_52 , V_132 -> V_172 . V_181 ) ;
V_268:
F_89 ( V_132 ) ;
}
static int F_155 ( struct V_168 * V_132 , int V_303 )
{
struct V_53 * V_146 = V_132 -> V_146 -> V_31 ;
struct V_44 * V_45 = F_71 ( V_146 ) ;
struct V_304 * V_172 = & V_132 -> V_172 ;
struct V_305 * V_169 = & V_132 -> V_169 ;
struct V_100 * V_101 ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_306 ] ,
. V_272 = V_172 ,
. V_273 = V_169 ,
. V_274 = V_132 -> V_190 -> V_247 ,
} ;
struct V_138 V_275 = {
. V_140 = V_45 -> V_77 ,
. V_136 = & V_137 ,
. V_141 = & V_307 ,
. V_143 = V_132 ,
. V_277 = V_278 ,
. V_182 = V_279 ,
} ;
int V_264 ;
F_39 ( & V_172 -> V_134 , & V_169 -> V_135 , 1 ) ;
F_147 ( & V_132 -> V_218 ) ;
V_132 -> V_249 = 0 ;
V_132 -> V_250 = 0 ;
V_132 -> V_267 = 0 ;
V_132 -> V_246 = 0 ;
if ( V_303 ) {
F_40 ( & V_172 -> V_134 ) ;
V_132 -> V_246 = 1 ;
}
V_101 = F_54 ( & V_275 ) ;
if ( F_44 ( V_101 ) )
return F_55 ( V_101 ) ;
V_264 = F_91 ( V_101 ) ;
if ( V_264 != 0 ) {
V_132 -> V_267 = 1 ;
F_148 () ;
} else
V_264 = V_132 -> V_250 ;
F_56 ( V_101 ) ;
return V_264 ;
}
static int F_130 ( struct V_168 * V_132 )
{
struct V_53 * V_146 = V_132 -> V_146 -> V_31 ;
struct V_305 * V_169 = & V_132 -> V_169 ;
int V_264 ;
V_264 = F_155 ( V_132 , 1 ) ;
if ( V_264 != 0 || ! V_132 -> V_249 )
return V_264 ;
F_156 ( F_71 ( V_146 ) , & V_132 -> V_170 ) ;
if ( V_169 -> V_301 & V_302 ) {
V_264 = F_146 ( V_132 ) ;
if ( V_264 != 0 )
return V_264 ;
}
return V_264 ;
}
static int F_157 ( struct V_274 * V_308 ,
struct V_168 * V_244 ,
struct V_51 * V_52 , T_3 V_181 ,
int V_309 )
{
struct V_310 V_311 ;
T_6 V_312 ;
if ( V_244 -> V_169 . V_313 == 0 )
return 0 ;
V_312 = 0 ;
if ( V_309 & V_314 ) {
V_312 = V_315 ;
} else if ( V_181 & V_57 )
V_312 = V_316 ;
V_311 . V_308 = V_308 ;
V_311 . V_126 = V_126 ;
F_158 ( & V_311 , V_244 -> V_169 . V_317 ) ;
F_159 ( V_52 -> V_53 , & V_311 ) ;
if ( ( V_312 & ~ V_311 . V_312 & ( V_316 | V_315 ) ) == 0 )
return 0 ;
F_131 ( V_52 , V_181 ) ;
return - V_12 ;
}
static int F_160 ( struct V_168 * V_132 )
{
struct V_53 * V_146 = V_132 -> V_146 -> V_31 ;
struct V_44 * V_45 = F_71 ( V_146 ) ;
struct V_304 * V_172 = & V_132 -> V_172 ;
struct V_305 * V_169 = & V_132 -> V_169 ;
int V_264 ;
V_264 = F_155 ( V_132 , 0 ) ;
if ( ! V_132 -> V_249 )
return V_264 ;
if ( V_264 != 0 ) {
if ( V_264 == - V_9 &&
! ( V_172 -> V_192 & V_318 ) )
return - V_261 ;
return V_264 ;
}
F_156 ( V_45 , & V_132 -> V_170 ) ;
if ( V_172 -> V_192 & V_318 )
F_60 ( V_146 , & V_169 -> V_148 ) ;
if ( ( V_169 -> V_301 & V_319 ) == 0 )
V_45 -> V_80 &= ~ V_320 ;
if( V_169 -> V_301 & V_302 ) {
V_264 = F_146 ( V_132 ) ;
if ( V_264 != 0 )
return V_264 ;
}
if ( ! ( V_169 -> V_170 -> V_252 & V_257 ) )
F_161 ( V_45 , & V_169 -> V_211 , V_169 -> V_170 ) ;
return 0 ;
}
static int F_162 ( struct V_44 * V_45 )
{
return F_163 ( V_45 -> V_49 ) ;
}
static int F_164 ( struct V_259 * V_260 , struct V_51 * V_52 )
{
struct V_168 * V_244 ;
int V_54 ;
V_244 = F_128 ( V_260 , V_52 ,
V_162 ) ;
if ( F_44 ( V_244 ) )
return F_55 ( V_244 ) ;
V_54 = F_132 ( V_244 , V_52 ) ;
if ( V_54 == - V_251 )
F_165 ( V_260 -> V_22 ) ;
F_89 ( V_244 ) ;
return V_54 ;
}
static int F_166 ( struct V_259 * V_260 , struct V_51 * V_52 )
{
struct V_44 * V_45 = F_71 ( V_52 -> V_53 ) ;
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_164 ( V_260 , V_52 ) ;
if ( F_64 ( V_45 , V_1 , & V_48 ) )
continue;
switch ( V_1 ) {
default:
goto V_105;
case - V_75 :
case - V_76 :
F_13 ( V_45 , V_1 , & V_48 ) ;
V_1 = 0 ;
}
} while ( V_48 . V_55 );
V_105:
return V_1 ;
}
static int F_167 ( struct V_179 * V_180 , struct V_51 * V_52 )
{
struct V_259 * V_260 ;
int V_54 ;
V_260 = F_125 ( V_52 ) ;
if ( F_44 ( V_260 ) )
return - V_129 ;
V_54 = F_166 ( V_260 , V_52 ) ;
F_138 ( V_260 ) ;
return V_54 ;
}
static void F_168 ( struct V_51 * V_52 )
{
struct V_44 * V_45 = F_71 ( V_52 -> V_53 ) ;
T_5 * V_217 = & V_52 -> V_217 ;
int V_264 ;
if ( F_42 ( V_234 , & V_52 -> V_182 ) == 0 )
return;
V_264 = F_169 ( V_45 , V_217 ) ;
if ( V_264 != V_321 ) {
if ( V_264 != - V_61 )
F_170 ( V_45 , V_217 ) ;
F_17 ( V_52 -> V_53 ) ;
F_102 ( & V_52 -> V_237 ) ;
F_99 ( & V_52 -> V_217 , & V_52 -> V_235 ) ;
F_103 ( & V_52 -> V_237 ) ;
F_133 ( V_234 , & V_52 -> V_182 ) ;
}
}
static int F_171 ( struct V_51 * V_52 )
{
struct V_44 * V_45 = F_71 ( V_52 -> V_53 ) ;
T_5 * V_217 = & V_52 -> V_235 ;
int V_264 ;
if ( ( F_42 ( V_224 , & V_52 -> V_182 ) == 0 ) &&
( F_42 ( V_226 , & V_52 -> V_182 ) == 0 ) &&
( F_42 ( V_228 , & V_52 -> V_182 ) == 0 ) )
return - V_61 ;
V_264 = F_169 ( V_45 , V_217 ) ;
if ( V_264 != V_321 ) {
if ( V_264 != - V_61 )
F_170 ( V_45 , V_217 ) ;
F_133 ( V_224 , & V_52 -> V_182 ) ;
F_133 ( V_226 , & V_52 -> V_182 ) ;
F_133 ( V_228 , & V_52 -> V_182 ) ;
F_133 ( V_236 , & V_52 -> V_182 ) ;
}
return V_264 ;
}
static int F_172 ( struct V_179 * V_180 , struct V_51 * V_52 )
{
int V_264 ;
F_168 ( V_52 ) ;
V_264 = F_171 ( V_52 ) ;
if ( V_264 != V_321 )
V_264 = F_167 ( V_180 , V_52 ) ;
return V_264 ;
}
static inline void F_173 ( struct V_168 * V_244 , struct V_183 * V_322 )
{
if ( ( V_244 -> V_169 . V_323 [ 1 ] & V_324 ) &&
! ( V_322 -> V_213 & V_325 ) )
V_322 -> V_213 |= V_326 ;
if ( ( V_244 -> V_169 . V_323 [ 1 ] & V_327 ) &&
! ( V_322 -> V_213 & V_328 ) )
V_322 -> V_213 |= V_329 ;
}
static int F_174 ( struct V_168 * V_244 ,
T_3 V_181 ,
int V_182 ,
struct V_51 * * V_39 )
{
struct V_179 * V_180 = V_244 -> V_190 ;
struct V_44 * V_45 = V_180 -> V_280 ;
struct V_51 * V_52 ;
unsigned int V_330 ;
int V_54 ;
V_330 = F_175 ( & V_180 -> V_331 ) ;
V_54 = F_160 ( V_244 ) ;
if ( V_54 != 0 )
goto V_105;
V_52 = F_124 ( V_244 ) ;
V_54 = F_55 ( V_52 ) ;
if ( F_44 ( V_52 ) )
goto V_105;
if ( V_45 -> V_80 & V_320 )
F_100 ( V_332 , & V_52 -> V_182 ) ;
V_54 = F_157 ( V_180 -> V_247 , V_244 , V_52 , V_181 , V_182 ) ;
if ( V_54 != 0 )
goto V_105;
if ( F_176 ( & V_180 -> V_331 , V_330 ) )
F_16 ( V_45 , V_52 ) ;
* V_39 = V_52 ;
V_105:
return V_54 ;
}
static int F_177 ( struct V_53 * V_146 ,
struct V_22 * V_22 ,
T_3 V_181 ,
int V_182 ,
struct V_183 * V_322 ,
struct V_274 * V_308 ,
struct V_51 * * V_39 ,
struct V_333 * * V_334 )
{
struct V_179 * V_180 ;
struct V_51 * V_52 = NULL ;
struct V_44 * V_45 = F_71 ( V_146 ) ;
struct V_168 * V_244 ;
enum V_160 V_161 = V_163 ;
int V_264 ;
V_264 = - V_125 ;
V_180 = F_178 ( V_45 , V_308 , V_335 ) ;
if ( V_180 == NULL ) {
F_2 ( L_24 ) ;
goto V_336;
}
V_264 = F_162 ( V_45 ) ;
if ( V_264 != 0 )
goto V_337;
if ( V_22 -> V_31 != NULL )
F_110 ( V_22 -> V_31 , V_181 ) ;
V_264 = - V_125 ;
if ( V_22 -> V_31 )
V_161 = V_162 ;
V_244 = F_69 ( V_22 , V_180 , V_181 , V_182 , V_322 ,
V_161 , V_335 ) ;
if ( V_244 == NULL )
goto V_337;
if ( V_334 && V_45 -> V_208 [ 2 ] & V_338 ) {
V_244 -> V_170 . V_339 = F_179 () ;
if ( ! V_244 -> V_170 . V_339 )
goto V_340;
V_244 -> V_172 . V_209 = & V_341 [ 0 ] ;
}
if ( V_22 -> V_31 != NULL )
V_244 -> V_52 = F_119 ( V_22 -> V_31 , V_180 ) ;
V_264 = F_174 ( V_244 , V_181 , V_182 , & V_52 ) ;
if ( V_264 != 0 )
goto V_340;
if ( ( V_244 -> V_172 . V_192 & V_194 ) &&
( V_244 -> V_172 . V_287 != V_290 ) ) {
F_173 ( V_244 , V_322 ) ;
F_67 ( V_244 -> V_169 . V_170 ) ;
V_264 = F_180 ( V_52 -> V_53 , V_308 ,
V_244 -> V_169 . V_170 , V_322 ,
V_52 ) ;
if ( V_264 == 0 )
F_181 ( V_52 -> V_53 , V_322 ) ;
F_182 ( V_52 -> V_53 , V_244 -> V_169 . V_170 ) ;
}
if ( F_183 ( V_334 , V_244 -> V_170 . V_339 , V_45 ) )
* V_334 = V_244 -> V_170 . V_339 ;
else
F_80 ( V_244 -> V_170 . V_339 ) ;
V_244 -> V_170 . V_339 = NULL ;
F_89 ( V_244 ) ;
F_86 ( V_180 ) ;
* V_39 = V_52 ;
return 0 ;
V_340:
F_80 ( V_244 -> V_170 . V_339 ) ;
F_89 ( V_244 ) ;
V_337:
F_86 ( V_180 ) ;
V_336:
* V_39 = NULL ;
return V_264 ;
}
static struct V_51 * F_184 ( struct V_53 * V_146 ,
struct V_22 * V_22 ,
T_3 V_181 ,
int V_182 ,
struct V_183 * V_322 ,
struct V_274 * V_308 ,
struct V_333 * * V_334 )
{
struct V_44 * V_45 = F_71 ( V_146 ) ;
struct V_47 V_48 = { } ;
struct V_51 * V_39 ;
int V_264 ;
V_181 &= V_57 | V_193 | V_342 ;
do {
V_264 = F_177 ( V_146 , V_22 , V_181 , V_182 , V_322 , V_308 ,
& V_39 , V_334 ) ;
if ( V_264 == 0 )
break;
if ( V_264 == - V_343 ) {
F_185 ( L_5
L_25 ,
F_71 ( V_146 ) -> V_49 -> V_83 ) ;
V_48 . V_55 = 1 ;
continue;
}
if ( V_264 == - V_61 ) {
V_48 . V_55 = 1 ;
continue;
}
if ( V_264 == - V_129 ) {
V_48 . V_55 = 1 ;
continue;
}
if ( F_64 ( V_45 , V_264 , & V_48 ) )
continue;
V_39 = F_45 ( F_13 ( V_45 ,
V_264 , & V_48 ) ) ;
} while ( V_48 . V_55 );
return V_39 ;
}
static int F_186 ( struct V_53 * V_53 , struct V_274 * V_308 ,
struct V_344 * V_345 , struct V_183 * V_322 ,
struct V_51 * V_52 )
{
struct V_44 * V_45 = F_71 ( V_53 ) ;
struct V_346 V_347 = {
. V_211 = F_78 ( V_53 ) ,
. V_348 = V_322 ,
. V_45 = V_45 ,
. V_207 = V_45 -> V_208 ,
} ;
struct V_349 V_39 = {
. V_345 = V_345 ,
. V_45 = V_45 ,
} ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_350 ] ,
. V_272 = & V_347 ,
. V_273 = & V_39 ,
. V_274 = V_308 ,
} ;
unsigned long V_84 = V_126 ;
T_3 V_181 ;
bool V_351 ;
int V_264 ;
F_67 ( V_345 ) ;
V_351 = ( V_322 -> V_213 & V_352 ) ? true : false ;
V_181 = V_351 ? V_193 : V_57 ;
if ( F_187 ( & V_347 . V_217 , V_53 , V_181 ) ) {
} else if ( V_351 && V_52 != NULL && F_188 ( V_52 ) ) {
struct V_353 V_354 = {
. V_355 = V_42 -> V_356 ,
. V_357 = V_42 -> V_358 ,
} ;
F_189 ( & V_347 . V_217 , V_52 , V_193 ,
& V_354 ) ;
} else
F_99 ( & V_347 . V_217 , & V_359 ) ;
V_264 = F_59 ( V_45 -> V_77 , V_45 , & V_137 , & V_347 . V_134 , & V_39 . V_135 , 1 ) ;
if ( V_264 == 0 && V_52 != NULL )
F_27 ( V_45 , V_84 ) ;
return V_264 ;
}
static int F_180 ( struct V_53 * V_53 , struct V_274 * V_308 ,
struct V_344 * V_345 , struct V_183 * V_322 ,
struct V_51 * V_52 )
{
struct V_44 * V_45 = F_71 ( V_53 ) ;
struct V_47 V_48 = {
. V_52 = V_52 ,
. V_53 = V_53 ,
} ;
int V_1 ;
do {
V_1 = F_186 ( V_53 , V_308 , V_345 , V_322 , V_52 ) ;
switch ( V_1 ) {
case - V_56 :
if ( ! ( V_322 -> V_213 & V_352 ) ) {
F_190 ( L_26
L_27
L_28
L_29 ,
V_45 -> V_49 -> V_83 ) ;
}
if ( V_52 && ! ( V_52 -> V_52 & V_193 ) ) {
V_1 = - V_360 ;
if ( V_322 -> V_213 & V_361 )
V_1 = - V_12 ;
goto V_105;
}
}
V_1 = F_13 ( V_45 , V_1 , & V_48 ) ;
} while ( V_48 . V_55 );
V_105:
return V_1 ;
}
static void F_191 ( void * V_132 )
{
struct V_362 * V_130 = V_132 ;
struct V_179 * V_180 = V_130 -> V_52 -> V_190 ;
struct V_219 * V_220 = V_130 -> V_52 -> V_53 -> V_363 ;
if ( V_130 -> V_364 )
F_192 ( V_130 -> V_52 -> V_53 ) ;
F_85 ( V_130 -> V_52 ) ;
F_84 ( V_130 -> V_347 . V_171 ) ;
F_86 ( V_180 ) ;
F_87 ( V_220 ) ;
F_80 ( V_130 ) ;
}
static void F_193 ( struct V_51 * V_52 ,
T_3 V_181 )
{
F_24 ( & V_52 -> V_190 -> V_239 ) ;
F_133 ( V_228 , & V_52 -> V_182 ) ;
switch ( V_181 & ( V_57 | V_193 ) ) {
case V_193 :
F_133 ( V_224 , & V_52 -> V_182 ) ;
break;
case V_57 :
F_133 ( V_226 , & V_52 -> V_182 ) ;
break;
case 0 :
F_133 ( V_224 , & V_52 -> V_182 ) ;
F_133 ( V_226 , & V_52 -> V_182 ) ;
F_133 ( V_236 , & V_52 -> V_182 ) ;
}
F_26 ( & V_52 -> V_190 -> V_239 ) ;
}
static void F_194 ( struct V_100 * V_101 , void * V_132 )
{
struct V_362 * V_130 = V_132 ;
struct V_51 * V_52 = V_130 -> V_52 ;
struct V_44 * V_45 = F_71 ( V_130 -> V_53 ) ;
F_2 ( L_30 , V_18 ) ;
if ( ! F_38 ( V_101 , & V_130 -> V_39 . V_135 ) )
return;
switch ( V_101 -> V_113 ) {
case 0 :
if ( V_130 -> V_364 )
F_195 ( V_52 -> V_53 ,
V_130 -> V_365 ) ;
F_101 ( V_52 , & V_130 -> V_39 . V_217 , 0 ) ;
F_27 ( V_45 , V_130 -> V_84 ) ;
F_193 ( V_52 ,
V_130 -> V_347 . V_181 ) ;
break;
case - V_63 :
case - V_79 :
case - V_61 :
case - V_62 :
if ( V_130 -> V_347 . V_181 == 0 )
break;
default:
if ( F_196 ( V_101 , V_45 , V_52 ) == - V_129 )
F_35 ( V_101 ) ;
}
F_112 ( V_130 -> V_347 . V_171 ) ;
F_120 ( V_130 -> V_53 , V_130 -> V_39 . V_345 ) ;
F_2 ( L_31 , V_18 , V_101 -> V_113 ) ;
}
static void F_197 ( struct V_100 * V_101 , void * V_132 )
{
struct V_362 * V_130 = V_132 ;
struct V_51 * V_52 = V_130 -> V_52 ;
struct V_53 * V_53 = V_130 -> V_53 ;
int V_366 = 0 ;
F_2 ( L_30 , V_18 ) ;
if ( F_150 ( V_130 -> V_347 . V_171 , V_101 ) != 0 )
goto V_281;
V_101 -> V_285 . V_269 = & V_270 [ V_367 ] ;
V_130 -> V_347 . V_181 = V_57 | V_193 ;
F_24 ( & V_52 -> V_190 -> V_239 ) ;
if ( V_52 -> V_229 == 0 ) {
if ( V_52 -> V_225 == 0 ) {
V_366 |= F_42 ( V_224 , & V_52 -> V_182 ) ;
V_366 |= F_42 ( V_228 , & V_52 -> V_182 ) ;
V_130 -> V_347 . V_181 &= ~ V_57 ;
}
if ( V_52 -> V_227 == 0 ) {
V_366 |= F_42 ( V_226 , & V_52 -> V_182 ) ;
V_366 |= F_42 ( V_228 , & V_52 -> V_182 ) ;
V_130 -> V_347 . V_181 &= ~ V_193 ;
}
}
if ( ! F_188 ( V_52 ) )
V_366 = 0 ;
F_26 ( & V_52 -> V_190 -> V_239 ) ;
if ( ! V_366 ) {
goto V_282;
}
if ( V_130 -> V_347 . V_181 == 0 ) {
V_101 -> V_285 . V_269 = & V_270 [ V_368 ] ;
if ( V_130 -> V_364 &&
F_198 ( V_53 , & V_130 -> V_365 , V_101 ) ) {
F_112 ( V_130 -> V_347 . V_171 ) ;
goto V_281;
}
}
F_67 ( V_130 -> V_39 . V_345 ) ;
V_130 -> V_84 = V_126 ;
if ( F_49 ( F_71 ( V_53 ) ,
& V_130 -> V_347 . V_134 ,
& V_130 -> V_39 . V_135 ,
V_101 ) != 0 )
F_112 ( V_130 -> V_347 . V_171 ) ;
F_2 ( L_32 , V_18 ) ;
return;
V_282:
V_101 -> V_293 = NULL ;
V_281:
F_38 ( V_101 , & V_130 -> V_39 . V_135 ) ;
}
int F_199 ( struct V_51 * V_52 , T_4 V_185 , int V_369 )
{
struct V_44 * V_45 = F_71 ( V_52 -> V_53 ) ;
struct V_362 * V_130 ;
struct V_179 * V_180 = V_52 -> V_190 ;
struct V_100 * V_101 ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_368 ] ,
. V_274 = V_52 -> V_190 -> V_247 ,
} ;
struct V_138 V_275 = {
. V_140 = V_45 -> V_77 ,
. V_136 = & V_137 ,
. V_141 = & V_370 ,
. V_277 = V_278 ,
. V_182 = V_279 ,
} ;
int V_264 = - V_125 ;
V_130 = F_72 ( sizeof( * V_130 ) , V_185 ) ;
if ( V_130 == NULL )
goto V_105;
F_39 ( & V_130 -> V_347 . V_134 , & V_130 -> V_39 . V_135 , 1 ) ;
V_130 -> V_53 = V_52 -> V_53 ;
V_130 -> V_52 = V_52 ;
V_130 -> V_347 . V_211 = F_78 ( V_52 -> V_53 ) ;
V_130 -> V_347 . V_217 = & V_52 -> V_235 ;
V_130 -> V_347 . V_171 = F_73 ( & V_52 -> V_190 -> V_187 , V_185 ) ;
if ( V_130 -> V_347 . V_171 == NULL )
goto V_371;
V_130 -> V_347 . V_181 = 0 ;
V_130 -> V_347 . V_207 = V_45 -> V_372 ;
V_130 -> V_39 . V_345 = & V_130 -> V_345 ;
V_130 -> V_39 . V_171 = V_130 -> V_347 . V_171 ;
V_130 -> V_39 . V_45 = V_45 ;
V_130 -> V_364 = F_200 ( V_52 -> V_53 ) ;
F_74 ( V_130 -> V_53 -> V_363 ) ;
V_137 . V_272 = & V_130 -> V_347 ;
V_137 . V_273 = & V_130 -> V_39 ;
V_275 . V_143 = V_130 ;
V_101 = F_54 ( & V_275 ) ;
if ( F_44 ( V_101 ) )
return F_55 ( V_101 ) ;
V_264 = 0 ;
if ( V_369 )
V_264 = F_92 ( V_101 ) ;
F_56 ( V_101 ) ;
return V_264 ;
V_371:
F_80 ( V_130 ) ;
V_105:
F_85 ( V_52 ) ;
F_86 ( V_180 ) ;
return V_264 ;
}
static struct V_53 *
F_201 ( struct V_53 * V_146 , struct V_259 * V_260 , int V_192 , struct V_183 * V_373 )
{
struct V_51 * V_52 ;
V_52 = F_184 ( V_146 , V_260 -> V_22 , V_260 -> V_221 , V_192 , V_373 ,
V_260 -> V_308 , & V_260 -> V_339 ) ;
if ( F_44 ( V_52 ) )
return F_202 ( V_52 ) ;
V_260 -> V_52 = V_52 ;
return F_203 ( V_52 -> V_53 ) ;
}
static void F_204 ( struct V_259 * V_260 , int V_374 )
{
if ( V_260 -> V_52 == NULL )
return;
if ( V_374 )
F_205 ( V_260 -> V_52 , V_260 -> V_221 ) ;
else
F_131 ( V_260 -> V_52 , V_260 -> V_221 ) ;
}
static int F_206 ( struct V_44 * V_45 , struct V_375 * V_376 )
{
struct V_377 args = {
. V_376 = V_376 ,
} ;
struct V_378 V_39 = {} ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_379 ] ,
. V_272 = & args ,
. V_273 = & V_39 ,
} ;
int V_264 ;
V_264 = F_59 ( V_45 -> V_77 , V_45 , & V_137 , & args . V_134 , & V_39 . V_135 , 0 ) ;
if ( V_264 == 0 ) {
memcpy ( V_45 -> V_208 , V_39 . V_208 , sizeof( V_45 -> V_208 ) ) ;
V_45 -> V_80 &= ~ ( V_380 | V_381 |
V_382 | V_383 |
V_384 | V_385 | V_386 |
V_387 | V_388 |
V_389 | V_390 ) ;
if ( V_39 . V_208 [ 0 ] & V_391 )
V_45 -> V_80 |= V_380 ;
if ( V_39 . V_392 != 0 )
V_45 -> V_80 |= V_381 ;
if ( V_39 . V_393 != 0 )
V_45 -> V_80 |= V_382 ;
if ( V_39 . V_208 [ 0 ] & V_30 )
V_45 -> V_80 |= V_383 ;
if ( V_39 . V_208 [ 1 ] & V_394 )
V_45 -> V_80 |= V_384 ;
if ( V_39 . V_208 [ 1 ] & V_395 )
V_45 -> V_80 |= V_385 ;
if ( V_39 . V_208 [ 1 ] & V_396 )
V_45 -> V_80 |= V_386 ;
if ( V_39 . V_208 [ 1 ] & V_397 )
V_45 -> V_80 |= V_387 ;
if ( V_39 . V_208 [ 1 ] & V_324 )
V_45 -> V_80 |= V_388 ;
if ( V_39 . V_208 [ 1 ] & V_398 )
V_45 -> V_80 |= V_389 ;
if ( V_39 . V_208 [ 1 ] & V_327 )
V_45 -> V_80 |= V_390 ;
memcpy ( V_45 -> V_372 , V_39 . V_208 , sizeof( V_45 -> V_372 ) ) ;
V_45 -> V_372 [ 0 ] &= V_399 | V_400 ;
V_45 -> V_372 [ 1 ] &= V_398 | V_327 ;
V_45 -> V_401 = V_39 . V_401 ;
V_45 -> V_402 = V_39 . V_402 ;
}
return V_264 ;
}
int F_207 ( struct V_44 * V_45 , struct V_375 * V_376 )
{
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_13 ( V_45 ,
F_206 ( V_45 , V_376 ) ,
& V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static int F_208 ( struct V_44 * V_45 , struct V_375 * V_376 ,
struct V_403 * V_404 )
{
struct V_405 args = {
. V_207 = V_210 ,
} ;
struct V_406 V_39 = {
. V_45 = V_45 ,
. V_345 = V_404 -> V_345 ,
. V_211 = V_376 ,
} ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_407 ] ,
. V_272 = & args ,
. V_273 = & V_39 ,
} ;
F_67 ( V_404 -> V_345 ) ;
return F_59 ( V_45 -> V_77 , V_45 , & V_137 , & args . V_134 , & V_39 . V_135 , 0 ) ;
}
static int F_209 ( struct V_44 * V_45 , struct V_375 * V_376 ,
struct V_403 * V_404 )
{
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_208 ( V_45 , V_376 , V_404 ) ;
switch ( V_1 ) {
case 0 :
case - V_6 :
goto V_105;
default:
V_1 = F_13 ( V_45 , V_1 , & V_48 ) ;
}
} while ( V_48 . V_55 );
V_105:
return V_1 ;
}
static int F_210 ( struct V_44 * V_45 , struct V_375 * V_376 ,
struct V_403 * V_404 , T_7 V_408 )
{
struct V_409 * V_410 ;
int V_54 ;
V_410 = F_211 ( V_408 , V_45 -> V_77 ) ;
if ( F_44 ( V_410 ) ) {
V_54 = - V_12 ;
goto V_105;
}
V_54 = F_209 ( V_45 , V_376 , V_404 ) ;
V_105:
return V_54 ;
}
static int F_212 ( struct V_44 * V_45 , struct V_375 * V_376 ,
struct V_403 * V_404 )
{
static const T_7 V_411 [] = {
V_412 ,
V_413 ,
V_414 ,
V_415 ,
V_416 ,
} ;
int V_264 = - V_7 ;
T_8 V_417 ;
for ( V_417 = 0 ; V_417 < F_213 ( V_411 ) ; V_417 ++ ) {
V_264 = F_210 ( V_45 , V_376 , V_404 , V_411 [ V_417 ] ) ;
if ( V_264 == - V_6 || V_264 == - V_12 )
continue;
break;
}
if ( V_264 == - V_12 )
V_264 = - V_7 ;
return V_264 ;
}
static int F_214 ( struct V_44 * V_45 ,
struct V_375 * V_376 , struct V_403 * V_404 )
{
int V_418 = V_45 -> V_49 -> V_419 ;
return V_420 [ V_418 ] -> F_215 ( V_45 , V_376 , V_404 ) ;
}
int F_216 ( struct V_44 * V_45 , struct V_375 * V_376 ,
struct V_403 * V_404 )
{
int V_264 ;
V_264 = F_209 ( V_45 , V_376 , V_404 ) ;
if ( ( V_264 == - V_6 ) &&
! ( V_45 -> V_182 & V_421 ) )
V_264 = F_214 ( V_45 , V_376 , V_404 ) ;
if ( V_264 == 0 )
V_264 = F_207 ( V_45 , V_376 ) ;
if ( V_264 == 0 )
V_264 = F_217 ( V_45 , V_376 , V_404 ) ;
return F_1 ( V_264 ) ;
}
static int F_218 ( struct V_44 * V_45 , struct V_375 * V_422 ,
struct V_403 * V_404 )
{
int error ;
struct V_344 * V_345 = V_404 -> V_345 ;
error = F_207 ( V_45 , V_422 ) ;
if ( error < 0 ) {
F_2 ( L_33 , - error ) ;
return error ;
}
error = F_219 ( V_45 , V_422 , V_345 ) ;
if ( error < 0 ) {
F_2 ( L_34 , - error ) ;
return error ;
}
if ( V_345 -> V_252 & V_423 &&
! F_220 ( & V_45 -> V_424 , & V_345 -> V_424 ) )
memcpy ( & V_45 -> V_424 , & V_345 -> V_424 , sizeof( V_45 -> V_424 ) ) ;
return error ;
}
static int F_221 ( struct V_36 * V_77 , struct V_53 * V_146 ,
const struct V_425 * V_205 , struct V_344 * V_345 ,
struct V_375 * V_376 )
{
int V_264 = - V_125 ;
struct V_426 * V_426 = NULL ;
struct V_427 * V_428 = NULL ;
V_426 = F_222 ( V_335 ) ;
if ( V_426 == NULL )
goto V_105;
V_428 = F_223 ( sizeof( struct V_427 ) , V_335 ) ;
if ( V_428 == NULL )
goto V_105;
V_264 = F_224 ( V_77 , V_146 , V_205 , V_428 , V_426 ) ;
if ( V_264 != 0 )
goto V_105;
if ( F_220 ( & F_71 ( V_146 ) -> V_424 , & V_428 -> V_345 . V_424 ) ) {
F_2 ( L_35
L_36 , V_18 , V_205 -> V_205 ) ;
V_264 = - V_19 ;
goto V_105;
}
F_225 ( & V_428 -> V_345 ) ;
memcpy ( V_345 , & V_428 -> V_345 , sizeof( struct V_344 ) ) ;
memset ( V_376 , 0 , sizeof( struct V_375 ) ) ;
V_105:
if ( V_426 )
F_226 ( V_426 ) ;
F_80 ( V_428 ) ;
return V_264 ;
}
static int F_161 ( struct V_44 * V_45 , struct V_375 * V_376 , struct V_344 * V_345 )
{
struct V_429 args = {
. V_211 = V_376 ,
. V_207 = V_45 -> V_208 ,
} ;
struct V_430 V_39 = {
. V_345 = V_345 ,
. V_45 = V_45 ,
} ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_431 ] ,
. V_272 = & args ,
. V_273 = & V_39 ,
} ;
F_67 ( V_345 ) ;
return F_59 ( V_45 -> V_77 , V_45 , & V_137 , & args . V_134 , & V_39 . V_135 , 0 ) ;
}
static int F_219 ( struct V_44 * V_45 , struct V_375 * V_376 , struct V_344 * V_345 )
{
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_13 ( V_45 ,
F_161 ( V_45 , V_376 , V_345 ) ,
& V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static int
F_227 ( struct V_22 * V_22 , struct V_344 * V_345 ,
struct V_183 * V_322 )
{
struct V_53 * V_53 = V_22 -> V_31 ;
struct V_274 * V_308 = NULL ;
struct V_51 * V_52 = NULL ;
int V_264 ;
if ( F_228 ( V_53 ) )
F_229 ( V_53 ) ;
F_67 ( V_345 ) ;
if ( V_322 -> V_213 & V_361 )
V_322 -> V_213 &= ~ ( V_329 | V_432 | V_361 ) ;
if ( ( V_322 -> V_213 & ~ ( V_433 ) ) == 0 )
return 0 ;
if ( V_322 -> V_213 & V_433 ) {
struct V_259 * V_260 ;
V_260 = F_230 ( V_322 -> V_434 ) ;
if ( V_260 ) {
V_308 = V_260 -> V_308 ;
V_52 = V_260 -> V_52 ;
}
}
V_264 = F_180 ( V_53 , V_308 , V_345 , V_322 , V_52 ) ;
if ( V_264 == 0 )
F_181 ( V_53 , V_322 ) ;
return V_264 ;
}
static int F_231 ( struct V_36 * V_37 , struct V_53 * V_146 ,
const struct V_425 * V_205 , struct V_375 * V_376 ,
struct V_344 * V_345 )
{
struct V_44 * V_45 = F_71 ( V_146 ) ;
int V_264 ;
struct V_435 args = {
. V_207 = V_45 -> V_208 ,
. V_436 = F_78 ( V_146 ) ,
. V_205 = V_205 ,
} ;
struct V_406 V_39 = {
. V_45 = V_45 ,
. V_345 = V_345 ,
. V_211 = V_376 ,
} ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_437 ] ,
. V_272 = & args ,
. V_273 = & V_39 ,
} ;
F_67 ( V_345 ) ;
F_2 ( L_37 , V_205 -> V_205 ) ;
V_264 = F_59 ( V_37 , V_45 , & V_137 , & args . V_134 , & V_39 . V_135 , 0 ) ;
F_2 ( L_38 , V_264 ) ;
return V_264 ;
}
static void F_232 ( struct V_344 * V_345 )
{
V_345 -> V_252 |= V_253 | V_438 |
V_439 | V_440 ;
V_345 -> V_221 = V_298 | V_441 | V_442 ;
V_345 -> V_443 = 2 ;
}
static int F_233 ( struct V_36 * * V_37 , struct V_53 * V_146 ,
struct V_425 * V_205 , struct V_375 * V_376 ,
struct V_344 * V_345 )
{
struct V_47 V_48 = { } ;
struct V_36 * V_77 = * V_37 ;
int V_1 ;
do {
V_1 = F_231 ( V_77 , V_146 , V_205 , V_376 , V_345 ) ;
switch ( V_1 ) {
case - V_9 :
V_1 = - V_261 ;
goto V_105;
case - V_444 :
V_1 = F_221 ( V_77 , V_146 , V_205 , V_345 , V_376 ) ;
goto V_105;
case - V_6 :
V_1 = - V_7 ;
if ( V_77 != * V_37 )
goto V_105;
V_77 = F_234 ( V_77 , V_146 , V_205 ) ;
if ( F_44 ( V_77 ) )
return F_55 ( V_77 ) ;
V_48 . V_55 = 1 ;
break;
default:
V_1 = F_13 ( F_71 ( V_146 ) , V_1 , & V_48 ) ;
}
} while ( V_48 . V_55 );
V_105:
if ( V_1 == 0 )
* V_37 = V_77 ;
else if ( V_77 != * V_37 )
F_235 ( V_77 ) ;
return V_1 ;
}
static int F_236 ( struct V_53 * V_146 , struct V_425 * V_205 ,
struct V_375 * V_376 , struct V_344 * V_345 )
{
int V_264 ;
struct V_36 * V_77 = F_237 ( V_146 ) ;
V_264 = F_233 ( & V_77 , V_146 , V_205 , V_376 , V_345 ) ;
if ( V_77 != F_237 ( V_146 ) ) {
F_235 ( V_77 ) ;
F_232 ( V_345 ) ;
}
return V_264 ;
}
struct V_36 *
F_238 ( struct V_53 * V_146 , struct V_425 * V_205 ,
struct V_375 * V_376 , struct V_344 * V_345 )
{
int V_264 ;
struct V_36 * V_77 = F_239 ( F_237 ( V_146 ) ) ;
V_264 = F_233 ( & V_77 , V_146 , V_205 , V_376 , V_345 ) ;
if ( V_264 < 0 ) {
F_235 ( V_77 ) ;
return F_45 ( V_264 ) ;
}
return V_77 ;
}
static int F_240 ( struct V_53 * V_53 , struct V_310 * V_445 )
{
struct V_44 * V_45 = F_71 ( V_53 ) ;
struct V_446 args = {
. V_211 = F_78 ( V_53 ) ,
. V_207 = V_45 -> V_372 ,
} ;
struct V_447 V_39 = {
. V_45 = V_45 ,
} ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_448 ] ,
. V_272 = & args ,
. V_273 = & V_39 ,
. V_274 = V_445 -> V_308 ,
} ;
int V_221 = V_445 -> V_312 ;
int V_264 ;
if ( V_221 & V_316 )
args . V_176 |= V_195 ;
if ( F_241 ( V_53 -> V_449 ) ) {
if ( V_221 & V_450 )
args . V_176 |= V_196 | V_197 | V_451 ;
if ( V_221 & V_315 )
args . V_176 |= V_452 ;
} else {
if ( V_221 & V_450 )
args . V_176 |= V_196 | V_197 ;
if ( V_221 & V_315 )
args . V_176 |= V_198 ;
}
V_39 . V_345 = F_242 () ;
if ( V_39 . V_345 == NULL )
return - V_125 ;
V_264 = F_59 ( V_45 -> V_77 , V_45 , & V_137 , & args . V_134 , & V_39 . V_135 , 0 ) ;
if ( ! V_264 ) {
F_158 ( V_445 , V_39 . V_176 ) ;
F_120 ( V_53 , V_39 . V_345 ) ;
}
F_243 ( V_39 . V_345 ) ;
return V_264 ;
}
static int F_244 ( struct V_53 * V_53 , struct V_310 * V_445 )
{
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_71 ( V_53 ) ,
F_240 ( V_53 , V_445 ) ,
& V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static int F_245 ( struct V_53 * V_53 , struct V_426 * V_426 ,
unsigned int V_34 , unsigned int V_453 )
{
struct V_454 args = {
. V_211 = F_78 ( V_53 ) ,
. V_34 = V_34 ,
. V_453 = V_453 ,
. V_27 = & V_426 ,
} ;
struct V_455 V_39 ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_456 ] ,
. V_272 = & args ,
. V_273 = & V_39 ,
} ;
return F_59 ( F_71 ( V_53 ) -> V_77 , F_71 ( V_53 ) , & V_137 , & args . V_134 , & V_39 . V_135 , 0 ) ;
}
static int F_246 ( struct V_53 * V_53 , struct V_426 * V_426 ,
unsigned int V_34 , unsigned int V_453 )
{
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_71 ( V_53 ) ,
F_245 ( V_53 , V_426 , V_34 , V_453 ) ,
& V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static int
F_247 ( struct V_53 * V_146 , struct V_22 * V_22 , struct V_183 * V_322 ,
int V_182 )
{
struct V_259 * V_260 ;
struct V_51 * V_52 ;
int V_264 = 0 ;
V_260 = F_248 ( V_22 , V_57 ) ;
if ( F_44 ( V_260 ) )
return F_55 ( V_260 ) ;
V_322 -> V_457 &= ~ F_249 () ;
V_52 = F_184 ( V_146 , V_22 , V_260 -> V_221 ,
V_182 , V_322 , V_260 -> V_308 ,
& V_260 -> V_339 ) ;
F_165 ( V_22 ) ;
if ( F_44 ( V_52 ) ) {
V_264 = F_55 ( V_52 ) ;
goto V_105;
}
F_250 ( V_22 , F_203 ( V_52 -> V_53 ) ) ;
F_251 ( V_22 , F_252 ( V_146 ) ) ;
V_260 -> V_52 = V_52 ;
V_105:
F_138 ( V_260 ) ;
return V_264 ;
}
static int F_253 ( struct V_53 * V_146 , struct V_425 * V_205 )
{
struct V_44 * V_45 = F_71 ( V_146 ) ;
struct V_458 args = {
. V_211 = F_78 ( V_146 ) ,
. V_205 = * V_205 ,
} ;
struct V_459 V_39 = {
. V_45 = V_45 ,
} ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_460 ] ,
. V_272 = & args ,
. V_273 = & V_39 ,
} ;
int V_264 ;
V_264 = F_59 ( V_45 -> V_77 , V_45 , & V_137 , & args . V_134 , & V_39 . V_135 , 1 ) ;
if ( V_264 == 0 )
F_60 ( V_146 , & V_39 . V_148 ) ;
return V_264 ;
}
static int F_254 ( struct V_53 * V_146 , struct V_425 * V_205 )
{
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_71 ( V_146 ) ,
F_253 ( V_146 , V_205 ) ,
& V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static void F_255 ( struct V_136 * V_137 , struct V_53 * V_146 )
{
struct V_44 * V_45 = F_71 ( V_146 ) ;
struct V_458 * args = V_137 -> V_272 ;
struct V_459 * V_39 = V_137 -> V_273 ;
V_39 -> V_45 = V_45 ;
V_137 -> V_269 = & V_270 [ V_460 ] ;
F_39 ( & args -> V_134 , & V_39 -> V_135 , 1 ) ;
}
static void F_256 ( struct V_100 * V_101 , struct V_461 * V_132 )
{
F_49 ( F_71 ( V_132 -> V_146 ) ,
& V_132 -> args . V_134 ,
& V_132 -> V_39 . V_135 ,
V_101 ) ;
}
static int F_257 ( struct V_100 * V_101 , struct V_53 * V_146 )
{
struct V_459 * V_39 = V_101 -> V_285 . V_273 ;
if ( ! F_38 ( V_101 , & V_39 -> V_135 ) )
return 0 ;
if ( F_196 ( V_101 , V_39 -> V_45 , NULL ) == - V_129 )
return 0 ;
F_60 ( V_146 , & V_39 -> V_148 ) ;
return 1 ;
}
static void F_258 ( struct V_136 * V_137 , struct V_53 * V_146 )
{
struct V_44 * V_45 = F_71 ( V_146 ) ;
struct V_462 * V_347 = V_137 -> V_272 ;
struct V_463 * V_39 = V_137 -> V_273 ;
V_137 -> V_269 = & V_270 [ V_464 ] ;
V_39 -> V_45 = V_45 ;
F_39 ( & V_347 -> V_134 , & V_39 -> V_135 , 1 ) ;
}
static void F_259 ( struct V_100 * V_101 , struct V_465 * V_132 )
{
F_49 ( F_71 ( V_132 -> V_466 ) ,
& V_132 -> args . V_134 ,
& V_132 -> V_39 . V_135 ,
V_101 ) ;
}
static int F_260 ( struct V_100 * V_101 , struct V_53 * V_466 ,
struct V_53 * V_467 )
{
struct V_463 * V_39 = V_101 -> V_285 . V_273 ;
if ( ! F_38 ( V_101 , & V_39 -> V_135 ) )
return 0 ;
if ( F_196 ( V_101 , V_39 -> V_45 , NULL ) == - V_129 )
return 0 ;
F_60 ( V_466 , & V_39 -> V_468 ) ;
F_60 ( V_467 , & V_39 -> V_469 ) ;
return 1 ;
}
static int F_261 ( struct V_53 * V_466 , struct V_425 * V_470 ,
struct V_53 * V_467 , struct V_425 * V_471 )
{
struct V_44 * V_45 = F_71 ( V_466 ) ;
struct V_462 V_347 = {
. V_466 = F_78 ( V_466 ) ,
. V_467 = F_78 ( V_467 ) ,
. V_470 = V_470 ,
. V_471 = V_471 ,
} ;
struct V_463 V_39 = {
. V_45 = V_45 ,
} ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_464 ] ,
. V_272 = & V_347 ,
. V_273 = & V_39 ,
} ;
int V_264 = - V_125 ;
V_264 = F_59 ( V_45 -> V_77 , V_45 , & V_137 , & V_347 . V_134 , & V_39 . V_135 , 1 ) ;
if ( ! V_264 ) {
F_60 ( V_466 , & V_39 . V_468 ) ;
F_60 ( V_467 , & V_39 . V_469 ) ;
}
return V_264 ;
}
static int F_262 ( struct V_53 * V_466 , struct V_425 * V_470 ,
struct V_53 * V_467 , struct V_425 * V_471 )
{
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_71 ( V_466 ) ,
F_261 ( V_466 , V_470 ,
V_467 , V_471 ) ,
& V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static int F_263 ( struct V_53 * V_53 , struct V_53 * V_146 , struct V_425 * V_205 )
{
struct V_44 * V_45 = F_71 ( V_53 ) ;
struct V_472 V_347 = {
. V_211 = F_78 ( V_53 ) ,
. V_436 = F_78 ( V_146 ) ,
. V_205 = V_205 ,
. V_207 = V_45 -> V_208 ,
} ;
struct V_473 V_39 = {
. V_45 = V_45 ,
} ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_474 ] ,
. V_272 = & V_347 ,
. V_273 = & V_39 ,
} ;
int V_264 = - V_125 ;
V_39 . V_345 = F_242 () ;
if ( V_39 . V_345 == NULL )
goto V_105;
V_264 = F_59 ( V_45 -> V_77 , V_45 , & V_137 , & V_347 . V_134 , & V_39 . V_135 , 1 ) ;
if ( ! V_264 ) {
F_60 ( V_146 , & V_39 . V_148 ) ;
F_182 ( V_53 , V_39 . V_345 ) ;
}
V_105:
F_243 ( V_39 . V_345 ) ;
return V_264 ;
}
static int F_264 ( struct V_53 * V_53 , struct V_53 * V_146 , struct V_425 * V_205 )
{
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_71 ( V_53 ) ,
F_263 ( V_53 , V_146 , V_205 ) ,
& V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static struct V_475 * F_265 ( struct V_53 * V_146 ,
struct V_425 * V_205 , struct V_183 * V_322 , T_6 V_476 )
{
struct V_475 * V_132 ;
V_132 = F_72 ( sizeof( * V_132 ) , V_335 ) ;
if ( V_132 != NULL ) {
struct V_44 * V_45 = F_71 ( V_146 ) ;
V_132 -> V_137 . V_269 = & V_270 [ V_477 ] ;
V_132 -> V_137 . V_272 = & V_132 -> V_347 ;
V_132 -> V_137 . V_273 = & V_132 -> V_39 ;
V_132 -> V_347 . V_436 = F_78 ( V_146 ) ;
V_132 -> V_347 . V_45 = V_45 ;
V_132 -> V_347 . V_205 = V_205 ;
V_132 -> V_347 . V_184 = V_322 ;
V_132 -> V_347 . V_476 = V_476 ;
V_132 -> V_347 . V_207 = V_45 -> V_208 ;
V_132 -> V_39 . V_45 = V_45 ;
V_132 -> V_39 . V_211 = & V_132 -> V_211 ;
V_132 -> V_39 . V_345 = & V_132 -> V_345 ;
F_67 ( V_132 -> V_39 . V_345 ) ;
}
return V_132 ;
}
static int F_266 ( struct V_53 * V_146 , struct V_22 * V_22 , struct V_475 * V_132 )
{
int V_264 = F_59 ( F_71 ( V_146 ) -> V_77 , F_71 ( V_146 ) , & V_132 -> V_137 ,
& V_132 -> V_347 . V_134 , & V_132 -> V_39 . V_135 , 1 ) ;
if ( V_264 == 0 ) {
F_60 ( V_146 , & V_132 -> V_39 . V_478 ) ;
V_264 = F_267 ( V_22 , V_132 -> V_39 . V_211 , V_132 -> V_39 . V_345 ) ;
}
return V_264 ;
}
static void F_268 ( struct V_475 * V_132 )
{
F_80 ( V_132 ) ;
}
static int F_269 ( struct V_53 * V_146 , struct V_22 * V_22 ,
struct V_426 * V_426 , unsigned int V_479 , struct V_183 * V_322 )
{
struct V_475 * V_132 ;
int V_264 = - V_480 ;
if ( V_479 > V_481 )
goto V_105;
V_264 = - V_125 ;
V_132 = F_265 ( V_146 , & V_22 -> V_206 , V_322 , V_482 ) ;
if ( V_132 == NULL )
goto V_105;
V_132 -> V_137 . V_269 = & V_270 [ V_483 ] ;
V_132 -> V_347 . V_215 . V_484 . V_27 = & V_426 ;
V_132 -> V_347 . V_215 . V_484 . V_479 = V_479 ;
V_264 = F_266 ( V_146 , V_22 , V_132 ) ;
F_268 ( V_132 ) ;
V_105:
return V_264 ;
}
static int F_270 ( struct V_53 * V_146 , struct V_22 * V_22 ,
struct V_426 * V_426 , unsigned int V_479 , struct V_183 * V_322 )
{
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_71 ( V_146 ) ,
F_269 ( V_146 , V_22 , V_426 ,
V_479 , V_322 ) ,
& V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static int F_271 ( struct V_53 * V_146 , struct V_22 * V_22 ,
struct V_183 * V_322 )
{
struct V_475 * V_132 ;
int V_264 = - V_125 ;
V_132 = F_265 ( V_146 , & V_22 -> V_206 , V_322 , V_485 ) ;
if ( V_132 == NULL )
goto V_105;
V_264 = F_266 ( V_146 , V_22 , V_132 ) ;
F_268 ( V_132 ) ;
V_105:
return V_264 ;
}
static int F_272 ( struct V_53 * V_146 , struct V_22 * V_22 ,
struct V_183 * V_322 )
{
struct V_47 V_48 = { } ;
int V_1 ;
V_322 -> V_457 &= ~ F_249 () ;
do {
V_1 = F_13 ( F_71 ( V_146 ) ,
F_271 ( V_146 , V_22 , V_322 ) ,
& V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static int F_273 ( struct V_22 * V_22 , struct V_274 * V_308 ,
T_1 V_20 , struct V_426 * * V_27 , unsigned int V_35 , int V_486 )
{
struct V_53 * V_146 = V_22 -> V_31 ;
struct V_23 args = {
. V_211 = F_78 ( V_146 ) ,
. V_27 = V_27 ,
. V_34 = 0 ,
. V_35 = V_35 ,
. V_207 = F_71 ( V_22 -> V_31 ) -> V_208 ,
. V_486 = V_486 ,
} ;
struct V_487 V_39 ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_488 ] ,
. V_272 = & args ,
. V_273 = & V_39 ,
. V_274 = V_308 ,
} ;
int V_264 ;
F_2 ( L_39 , V_18 ,
V_22 -> V_33 -> V_206 . V_205 ,
V_22 -> V_206 . V_205 ,
( unsigned long long ) V_20 ) ;
F_3 ( V_20 , F_61 ( V_146 ) -> V_489 , V_22 , & args ) ;
V_39 . V_34 = args . V_34 ;
V_264 = F_59 ( F_71 ( V_146 ) -> V_77 , F_71 ( V_146 ) , & V_137 , & args . V_134 , & V_39 . V_135 , 0 ) ;
if ( V_264 >= 0 ) {
memcpy ( F_61 ( V_146 ) -> V_489 , V_39 . V_21 . V_132 , V_490 ) ;
V_264 += args . V_34 ;
}
F_274 ( V_146 ) ;
F_2 ( L_40 , V_18 , V_264 ) ;
return V_264 ;
}
static int F_275 ( struct V_22 * V_22 , struct V_274 * V_308 ,
T_1 V_20 , struct V_426 * * V_27 , unsigned int V_35 , int V_486 )
{
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_71 ( V_22 -> V_31 ) ,
F_273 ( V_22 , V_308 , V_20 ,
V_27 , V_35 , V_486 ) ,
& V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static int F_276 ( struct V_53 * V_146 , struct V_22 * V_22 ,
struct V_183 * V_322 , T_9 V_491 )
{
struct V_475 * V_132 ;
int V_221 = V_322 -> V_457 ;
int V_264 = - V_125 ;
V_132 = F_265 ( V_146 , & V_22 -> V_206 , V_322 , V_492 ) ;
if ( V_132 == NULL )
goto V_105;
if ( F_277 ( V_221 ) )
V_132 -> V_347 . V_476 = V_493 ;
else if ( F_278 ( V_221 ) ) {
V_132 -> V_347 . V_476 = V_494 ;
V_132 -> V_347 . V_215 . V_495 . V_496 = F_279 ( V_491 ) ;
V_132 -> V_347 . V_215 . V_495 . V_497 = F_280 ( V_491 ) ;
}
else if ( F_281 ( V_221 ) ) {
V_132 -> V_347 . V_476 = V_498 ;
V_132 -> V_347 . V_215 . V_495 . V_496 = F_279 ( V_491 ) ;
V_132 -> V_347 . V_215 . V_495 . V_497 = F_280 ( V_491 ) ;
} else if ( ! F_282 ( V_221 ) ) {
V_264 = - V_10 ;
goto V_268;
}
V_264 = F_266 ( V_146 , V_22 , V_132 ) ;
V_268:
F_268 ( V_132 ) ;
V_105:
return V_264 ;
}
static int F_283 ( struct V_53 * V_146 , struct V_22 * V_22 ,
struct V_183 * V_322 , T_9 V_491 )
{
struct V_47 V_48 = { } ;
int V_1 ;
V_322 -> V_457 &= ~ F_249 () ;
do {
V_1 = F_13 ( F_71 ( V_146 ) ,
F_276 ( V_146 , V_22 , V_322 , V_491 ) ,
& V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static int F_284 ( struct V_44 * V_45 , struct V_375 * V_376 ,
struct V_499 * V_500 )
{
struct V_501 args = {
. V_211 = V_376 ,
. V_207 = V_45 -> V_208 ,
} ;
struct V_502 V_39 = {
. V_500 = V_500 ,
} ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_503 ] ,
. V_272 = & args ,
. V_273 = & V_39 ,
} ;
F_67 ( V_500 -> V_345 ) ;
return F_59 ( V_45 -> V_77 , V_45 , & V_137 , & args . V_134 , & V_39 . V_135 , 0 ) ;
}
static int F_285 ( struct V_44 * V_45 , struct V_375 * V_376 , struct V_499 * V_500 )
{
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_13 ( V_45 ,
F_284 ( V_45 , V_376 , V_500 ) ,
& V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static int F_286 ( struct V_44 * V_45 , struct V_375 * V_376 ,
struct V_403 * V_504 )
{
struct V_505 args = {
. V_211 = V_376 ,
. V_207 = V_45 -> V_208 ,
} ;
struct V_506 V_39 = {
. V_504 = V_504 ,
} ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_507 ] ,
. V_272 = & args ,
. V_273 = & V_39 ,
} ;
return F_59 ( V_45 -> V_77 , V_45 , & V_137 , & args . V_134 , & V_39 . V_135 , 0 ) ;
}
static int F_217 ( struct V_44 * V_45 , struct V_375 * V_376 , struct V_403 * V_504 )
{
struct V_47 V_48 = { } ;
unsigned long V_508 = V_126 ;
int V_1 ;
do {
V_1 = F_286 ( V_45 , V_376 , V_504 ) ;
if ( V_1 == 0 ) {
struct V_49 * V_50 = V_45 -> V_49 ;
F_24 ( & V_50 -> V_85 ) ;
V_50 -> V_509 = V_504 -> V_510 * V_74 ;
V_50 -> V_86 = V_508 ;
F_26 ( & V_50 -> V_85 ) ;
break;
}
V_1 = F_13 ( V_45 , V_1 , & V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static int F_287 ( struct V_44 * V_45 , struct V_375 * V_376 , struct V_403 * V_504 )
{
int error ;
F_67 ( V_504 -> V_345 ) ;
error = F_217 ( V_45 , V_376 , V_504 ) ;
if ( error == 0 ) {
V_45 -> V_511 = V_504 -> V_512 ;
F_288 ( V_45 , V_376 , V_504 -> V_513 ) ;
}
return error ;
}
static int F_289 ( struct V_44 * V_45 , struct V_375 * V_376 ,
struct V_514 * V_515 )
{
struct V_516 args = {
. V_211 = V_376 ,
. V_207 = V_45 -> V_208 ,
} ;
struct V_517 V_39 = {
. V_515 = V_515 ,
} ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_518 ] ,
. V_272 = & args ,
. V_273 = & V_39 ,
} ;
if ( ( args . V_207 [ 0 ] & V_519 [ 0 ] ) == 0 ) {
memset ( V_515 , 0 , sizeof( * V_515 ) ) ;
return 0 ;
}
F_67 ( V_515 -> V_345 ) ;
return F_59 ( V_45 -> V_77 , V_45 , & V_137 , & args . V_134 , & V_39 . V_135 , 0 ) ;
}
static int F_290 ( struct V_44 * V_45 , struct V_375 * V_376 ,
struct V_514 * V_515 )
{
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_13 ( V_45 ,
F_289 ( V_45 , V_376 , V_515 ) ,
& V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
int F_291 ( T_5 * V_217 ,
const struct V_259 * V_260 ,
const struct V_520 * V_521 ,
T_3 V_181 )
{
const struct V_353 * V_354 = NULL ;
if ( V_521 != NULL )
V_354 = & V_521 -> V_354 ;
return F_189 ( V_217 , V_260 -> V_52 , V_181 , V_354 ) ;
}
static bool F_292 ( T_5 * V_217 ,
const struct V_259 * V_260 ,
const struct V_520 * V_521 ,
T_3 V_181 )
{
T_5 V_522 ;
if ( F_291 ( & V_522 , V_260 , V_521 , V_181 ) )
return false ;
return F_108 ( V_217 , & V_522 ) ;
}
static bool F_293 ( int V_1 )
{
switch ( V_1 ) {
case - V_59 :
case - V_60 :
case - V_61 :
case - V_63 :
case - V_79 :
case - V_56 :
case - V_62 :
return true ;
}
return false ;
}
void F_294 ( struct V_523 * V_132 )
{
F_274 ( V_132 -> V_524 -> V_53 ) ;
}
static int F_295 ( struct V_100 * V_101 , struct V_523 * V_132 )
{
struct V_44 * V_45 = F_71 ( V_132 -> V_524 -> V_53 ) ;
if ( F_196 ( V_101 , V_45 , V_132 -> args . V_525 -> V_52 ) == - V_129 ) {
F_35 ( V_101 ) ;
return - V_129 ;
}
F_294 ( V_132 ) ;
if ( V_101 -> V_113 > 0 )
F_27 ( V_45 , V_132 -> V_84 ) ;
return 0 ;
}
static bool F_296 ( struct V_100 * V_101 ,
struct V_526 * args )
{
if ( ! F_293 ( V_101 -> V_113 ) ||
F_292 ( & args -> V_217 ,
args -> V_525 ,
args -> V_527 ,
V_57 ) )
return false ;
F_35 ( V_101 ) ;
return true ;
}
static int F_297 ( struct V_100 * V_101 , struct V_523 * V_132 )
{
F_2 ( L_12 , V_18 ) ;
if ( ! F_38 ( V_101 , & V_132 -> V_39 . V_135 ) )
return - V_129 ;
if ( F_296 ( V_101 , & V_132 -> args ) )
return - V_129 ;
return V_132 -> V_528 ? V_132 -> V_528 ( V_101 , V_132 ) :
F_295 ( V_101 , V_132 ) ;
}
static void F_298 ( struct V_523 * V_132 , struct V_136 * V_137 )
{
V_132 -> V_84 = V_126 ;
V_132 -> V_528 = F_295 ;
V_137 -> V_269 = & V_270 [ V_529 ] ;
F_39 ( & V_132 -> args . V_134 , & V_132 -> V_39 . V_135 , 0 ) ;
}
static void F_299 ( struct V_100 * V_101 , struct V_523 * V_132 )
{
if ( F_49 ( F_71 ( V_132 -> V_524 -> V_53 ) ,
& V_132 -> args . V_134 ,
& V_132 -> V_39 . V_135 ,
V_101 ) )
return;
F_291 ( & V_132 -> args . V_217 , V_132 -> args . V_525 ,
V_132 -> args . V_527 , V_57 ) ;
}
static int F_300 ( struct V_100 * V_101 , struct V_530 * V_132 )
{
struct V_53 * V_53 = V_132 -> V_524 -> V_53 ;
if ( F_196 ( V_101 , F_71 ( V_53 ) , V_132 -> args . V_525 -> V_52 ) == - V_129 ) {
F_35 ( V_101 ) ;
return - V_129 ;
}
if ( V_101 -> V_113 >= 0 ) {
F_27 ( F_71 ( V_53 ) , V_132 -> V_84 ) ;
F_301 ( V_53 , & V_132 -> V_345 ) ;
}
return 0 ;
}
static bool F_302 ( struct V_100 * V_101 ,
struct V_531 * args )
{
if ( ! F_293 ( V_101 -> V_113 ) ||
F_292 ( & args -> V_217 ,
args -> V_525 ,
args -> V_527 ,
V_193 ) )
return false ;
F_35 ( V_101 ) ;
return true ;
}
static int F_303 ( struct V_100 * V_101 , struct V_530 * V_132 )
{
if ( ! F_38 ( V_101 , & V_132 -> V_39 . V_135 ) )
return - V_129 ;
if ( F_302 ( V_101 , & V_132 -> args ) )
return - V_129 ;
return V_132 -> V_532 ? V_132 -> V_532 ( V_101 , V_132 ) :
F_300 ( V_101 , V_132 ) ;
}
static
bool F_304 ( const struct V_530 * V_132 )
{
const struct V_533 * V_534 = V_132 -> V_524 ;
if ( V_132 -> V_535 != NULL || V_534 -> V_536 != NULL )
return false ;
return F_14 ( V_534 -> V_53 , V_57 ) == 0 ;
}
static void F_305 ( struct V_530 * V_132 , struct V_136 * V_137 )
{
struct V_44 * V_45 = F_71 ( V_132 -> V_524 -> V_53 ) ;
if ( ! F_304 ( V_132 ) ) {
V_132 -> args . V_207 = NULL ;
V_132 -> V_39 . V_345 = NULL ;
} else
V_132 -> args . V_207 = V_45 -> V_372 ;
if ( ! V_132 -> V_532 )
V_132 -> V_532 = F_300 ;
V_132 -> V_39 . V_45 = V_45 ;
V_132 -> V_84 = V_126 ;
V_137 -> V_269 = & V_270 [ V_537 ] ;
F_39 ( & V_132 -> args . V_134 , & V_132 -> V_39 . V_135 , 1 ) ;
}
static void F_306 ( struct V_100 * V_101 , struct V_530 * V_132 )
{
if ( F_49 ( F_71 ( V_132 -> V_524 -> V_53 ) ,
& V_132 -> args . V_134 ,
& V_132 -> V_39 . V_135 ,
V_101 ) )
return;
F_291 ( & V_132 -> args . V_217 , V_132 -> args . V_525 ,
V_132 -> args . V_527 , V_193 ) ;
}
static void F_307 ( struct V_100 * V_101 , struct V_538 * V_132 )
{
F_49 ( F_71 ( V_132 -> V_53 ) ,
& V_132 -> args . V_134 ,
& V_132 -> V_39 . V_135 ,
V_101 ) ;
}
static int F_308 ( struct V_100 * V_101 , struct V_538 * V_132 )
{
struct V_53 * V_53 = V_132 -> V_53 ;
if ( F_196 ( V_101 , F_71 ( V_53 ) , NULL ) == - V_129 ) {
F_35 ( V_101 ) ;
return - V_129 ;
}
return 0 ;
}
static int F_309 ( struct V_100 * V_101 , struct V_538 * V_132 )
{
if ( ! F_38 ( V_101 , & V_132 -> V_39 . V_135 ) )
return - V_129 ;
return V_132 -> V_539 ( V_101 , V_132 ) ;
}
static void F_310 ( struct V_538 * V_132 , struct V_136 * V_137 )
{
struct V_44 * V_45 = F_71 ( V_132 -> V_53 ) ;
if ( V_132 -> V_539 == NULL )
V_132 -> V_539 = F_308 ;
V_132 -> V_39 . V_45 = V_45 ;
V_137 -> V_269 = & V_270 [ V_540 ] ;
F_39 ( & V_132 -> args . V_134 , & V_132 -> V_39 . V_135 , 1 ) ;
}
static void F_311 ( void * V_130 )
{
struct V_541 * V_132 = V_130 ;
struct V_49 * V_50 = V_132 -> V_77 ;
if ( F_312 ( & V_50 -> V_542 ) > 1 )
F_313 ( V_50 ) ;
F_314 ( V_50 ) ;
F_80 ( V_132 ) ;
}
static void F_315 ( struct V_100 * V_101 , void * V_130 )
{
struct V_541 * V_132 = V_130 ;
struct V_49 * V_50 = V_132 -> V_77 ;
unsigned long V_84 = V_132 -> V_84 ;
if ( V_101 -> V_113 < 0 ) {
if ( F_42 ( V_543 , & V_50 -> V_544 ) == 0 )
return;
if ( V_101 -> V_113 != V_545 ) {
F_18 ( V_50 ) ;
return;
}
F_316 ( V_50 ) ;
}
F_23 ( V_50 , V_84 ) ;
}
static int F_317 ( struct V_49 * V_50 , struct V_274 * V_308 , unsigned V_546 )
{
struct V_136 V_137 = {
. V_269 = & V_270 [ V_547 ] ,
. V_272 = V_50 ,
. V_274 = V_308 ,
} ;
struct V_541 * V_132 ;
if ( V_546 == 0 )
return 0 ;
if ( ! F_318 ( & V_50 -> V_542 ) )
return - V_19 ;
V_132 = F_223 ( sizeof( * V_132 ) , V_262 ) ;
if ( V_132 == NULL )
return - V_125 ;
V_132 -> V_77 = V_50 ;
V_132 -> V_84 = V_126 ;
return F_319 ( V_50 -> V_548 , & V_137 , V_549 ,
& V_550 , V_132 ) ;
}
static int F_320 ( struct V_49 * V_50 , struct V_274 * V_308 )
{
struct V_136 V_137 = {
. V_269 = & V_270 [ V_547 ] ,
. V_272 = V_50 ,
. V_274 = V_308 ,
} ;
unsigned long V_508 = V_126 ;
int V_264 ;
V_264 = F_58 ( V_50 -> V_548 , & V_137 , V_549 ) ;
if ( V_264 < 0 )
return V_264 ;
F_23 ( V_50 , V_508 ) ;
return 0 ;
}
static inline int F_321 ( struct V_44 * V_45 )
{
return ( V_45 -> V_80 & V_380 )
&& ( V_45 -> V_401 & V_551 )
&& ( V_45 -> V_401 & V_552 ) ;
}
static int F_322 ( const void * V_553 , T_8 V_554 ,
struct V_426 * * V_27 , unsigned int * V_34 )
{
struct V_426 * V_555 , * * V_556 ;
int V_557 = 0 ;
T_8 V_479 ;
V_556 = V_27 ;
do {
V_479 = F_323 ( T_8 , V_558 , V_554 ) ;
V_555 = F_222 ( V_335 ) ;
if ( V_555 == NULL )
goto V_559;
memcpy ( F_324 ( V_555 ) , V_553 , V_479 ) ;
V_553 += V_479 ;
V_554 -= V_479 ;
* V_27 ++ = V_555 ;
V_557 ++ ;
} while ( V_554 != 0 );
return V_557 ;
V_559:
for(; V_557 > 0 ; V_557 -- )
F_226 ( V_556 [ V_557 - 1 ] ) ;
return - V_125 ;
}
static void F_325 ( struct V_53 * V_53 , struct V_560 * V_561 )
{
struct V_149 * V_150 = F_61 ( V_53 ) ;
F_24 ( & V_53 -> V_151 ) ;
F_80 ( V_150 -> V_562 ) ;
V_150 -> V_562 = V_561 ;
F_26 ( & V_53 -> V_151 ) ;
}
static void F_326 ( struct V_53 * V_53 )
{
F_325 ( V_53 , NULL ) ;
}
static inline T_10 F_327 ( struct V_53 * V_53 , char * V_553 , T_8 V_554 )
{
struct V_149 * V_150 = F_61 ( V_53 ) ;
struct V_560 * V_561 ;
int V_54 = - V_261 ;
F_24 ( & V_53 -> V_151 ) ;
V_561 = V_150 -> V_562 ;
if ( V_561 == NULL )
goto V_105;
if ( V_553 == NULL )
goto V_563;
if ( V_561 -> V_564 == 0 )
goto V_105;
V_54 = - V_565 ;
if ( V_561 -> V_479 > V_554 )
goto V_105;
memcpy ( V_553 , V_561 -> V_132 , V_561 -> V_479 ) ;
V_563:
V_54 = V_561 -> V_479 ;
V_105:
F_26 ( & V_53 -> V_151 ) ;
return V_54 ;
}
static void F_328 ( struct V_53 * V_53 , struct V_426 * * V_27 , T_8 V_34 , T_8 V_566 )
{
struct V_560 * V_561 ;
T_8 V_554 = sizeof( * V_561 ) + V_566 ;
if ( V_554 <= V_558 ) {
V_561 = F_223 ( V_554 , V_335 ) ;
if ( V_561 == NULL )
goto V_105;
V_561 -> V_564 = 1 ;
F_329 ( V_561 -> V_132 , V_27 , V_34 , V_566 ) ;
} else {
V_561 = F_223 ( sizeof( * V_561 ) , V_335 ) ;
if ( V_561 == NULL )
goto V_105;
V_561 -> V_564 = 0 ;
}
V_561 -> V_479 = V_566 ;
V_105:
F_325 ( V_53 , V_561 ) ;
}
static T_10 F_330 ( struct V_53 * V_53 , void * V_553 , T_8 V_554 )
{
struct V_426 * V_27 [ V_567 ] = { NULL , } ;
struct V_568 args = {
. V_211 = F_78 ( V_53 ) ,
. V_569 = V_27 ,
. V_566 = V_554 ,
} ;
struct V_570 V_39 = {
. V_566 = V_554 ,
} ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_571 ] ,
. V_272 = & args ,
. V_273 = & V_39 ,
} ;
unsigned int V_572 = F_331 ( V_554 , V_558 ) ;
int V_54 = - V_125 , V_417 ;
if ( V_572 == 0 )
V_572 = 1 ;
if ( V_572 > F_213 ( V_27 ) )
return - V_565 ;
for ( V_417 = 0 ; V_417 < V_572 ; V_417 ++ ) {
V_27 [ V_417 ] = F_222 ( V_335 ) ;
if ( ! V_27 [ V_417 ] )
goto V_268;
}
V_39 . V_573 = F_222 ( V_335 ) ;
if ( ! V_39 . V_573 )
goto V_268;
args . V_566 = V_572 * V_558 ;
args . V_574 = 0 ;
F_2 ( L_41 ,
V_18 , V_553 , V_554 , V_572 , args . V_566 ) ;
V_54 = F_59 ( F_71 ( V_53 ) -> V_77 , F_71 ( V_53 ) ,
& V_137 , & args . V_134 , & V_39 . V_135 , 0 ) ;
if ( V_54 )
goto V_268;
if ( V_39 . V_575 & V_576 ) {
if ( V_553 == NULL )
goto V_577;
V_54 = - V_565 ;
goto V_268;
}
F_328 ( V_53 , V_27 , V_39 . V_578 , V_39 . V_566 ) ;
if ( V_553 ) {
if ( V_39 . V_566 > V_554 ) {
V_54 = - V_565 ;
goto V_268;
}
F_329 ( V_553 , V_27 , V_39 . V_578 , V_39 . V_566 ) ;
}
V_577:
V_54 = V_39 . V_566 ;
V_268:
for ( V_417 = 0 ; V_417 < V_572 ; V_417 ++ )
if ( V_27 [ V_417 ] )
F_226 ( V_27 [ V_417 ] ) ;
if ( V_39 . V_573 )
F_226 ( V_39 . V_573 ) ;
return V_54 ;
}
static T_10 F_332 ( struct V_53 * V_53 , void * V_553 , T_8 V_554 )
{
struct V_47 V_48 = { } ;
T_10 V_54 ;
do {
V_54 = F_330 ( V_53 , V_553 , V_554 ) ;
if ( V_54 >= 0 )
break;
V_54 = F_13 ( F_71 ( V_53 ) , V_54 , & V_48 ) ;
} while ( V_48 . V_55 );
return V_54 ;
}
static T_10 F_333 ( struct V_53 * V_53 , void * V_553 , T_8 V_554 )
{
struct V_44 * V_45 = F_71 ( V_53 ) ;
int V_54 ;
if ( ! F_321 ( V_45 ) )
return - V_579 ;
V_54 = F_334 ( V_45 , V_53 ) ;
if ( V_54 < 0 )
return V_54 ;
if ( F_61 ( V_53 ) -> V_152 & V_580 )
F_335 ( V_53 ) ;
V_54 = F_327 ( V_53 , V_553 , V_554 ) ;
if ( V_54 != - V_261 )
return V_54 ;
return F_332 ( V_53 , V_553 , V_554 ) ;
}
static int F_336 ( struct V_53 * V_53 , const void * V_553 , T_8 V_554 )
{
struct V_44 * V_45 = F_71 ( V_53 ) ;
struct V_426 * V_27 [ V_567 ] ;
struct V_581 V_347 = {
. V_211 = F_78 ( V_53 ) ,
. V_569 = V_27 ,
. V_566 = V_554 ,
} ;
struct V_582 V_39 ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_583 ] ,
. V_272 = & V_347 ,
. V_273 = & V_39 ,
} ;
unsigned int V_572 = F_331 ( V_554 , V_558 ) ;
int V_54 , V_417 ;
if ( ! F_321 ( V_45 ) )
return - V_579 ;
if ( V_572 > F_213 ( V_27 ) )
return - V_565 ;
V_417 = F_322 ( V_553 , V_554 , V_347 . V_569 , & V_347 . V_574 ) ;
if ( V_417 < 0 )
return V_417 ;
F_15 ( V_53 ) ;
V_54 = F_59 ( V_45 -> V_77 , V_45 , & V_137 , & V_347 . V_134 , & V_39 . V_135 , 1 ) ;
for (; V_417 > 0 ; V_417 -- )
F_337 ( V_27 [ V_417 - 1 ] ) ;
F_24 ( & V_53 -> V_151 ) ;
F_61 ( V_53 ) -> V_152 |= V_153 ;
F_26 ( & V_53 -> V_151 ) ;
F_338 ( V_53 ) ;
F_335 ( V_53 ) ;
return V_54 ;
}
static int F_339 ( struct V_53 * V_53 , const void * V_553 , T_8 V_554 )
{
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_71 ( V_53 ) ,
F_336 ( V_53 , V_553 , V_554 ) ,
& V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static int
F_196 ( struct V_100 * V_101 , const struct V_44 * V_45 , struct V_51 * V_52 )
{
struct V_49 * V_50 = V_45 -> V_49 ;
if ( V_101 -> V_113 >= 0 )
return 0 ;
switch( V_101 -> V_113 ) {
case - V_59 :
case - V_60 :
case - V_61 :
if ( V_52 == NULL )
break;
F_17 ( V_52 -> V_53 ) ;
case - V_56 :
if ( V_52 == NULL )
break;
if ( F_16 ( V_45 , V_52 ) < 0 )
goto V_584;
goto V_58;
case - V_62 :
if ( V_52 != NULL ) {
if ( F_16 ( V_45 , V_52 ) < 0 )
goto V_584;
}
case - V_63 :
case - V_64 :
F_18 ( V_50 ) ;
goto V_58;
#if F_19 ( V_65 )
case - V_66 :
case - V_67 :
case - V_68 :
case - V_70 :
case - V_69 :
case - V_71 :
case - V_72 :
F_2 ( L_42 , V_18 ,
V_101 -> V_113 ) ;
F_20 ( V_50 -> V_73 , V_101 -> V_113 ) ;
V_101 -> V_113 = 0 ;
return - V_129 ;
#endif
case - V_76 :
F_340 ( V_45 , V_585 ) ;
case - V_75 :
F_37 ( V_101 , V_41 ) ;
V_101 -> V_113 = 0 ;
return - V_129 ;
case - V_78 :
case - V_79 :
V_101 -> V_113 = 0 ;
return - V_129 ;
}
V_101 -> V_113 = F_1 ( V_101 -> V_113 ) ;
return 0 ;
V_584:
V_101 -> V_113 = - V_19 ;
return 0 ;
V_58:
F_48 ( & V_50 -> V_586 , V_101 , NULL ) ;
if ( F_42 ( V_587 , & V_50 -> V_588 ) == 0 )
F_341 ( & V_50 -> V_586 , V_101 ) ;
V_101 -> V_113 = 0 ;
return - V_129 ;
}
static void F_342 ( const struct V_49 * V_50 ,
T_11 * V_589 )
{
T_2 V_214 [ 2 ] ;
if ( F_42 ( V_590 , & V_50 -> V_588 ) ) {
V_214 [ 0 ] = 0 ;
V_214 [ 1 ] = ( T_2 ) ( V_591 + 1 ) ;
} else {
struct V_592 * V_593 = F_343 ( V_50 -> V_594 , V_595 ) ;
V_214 [ 0 ] = ( T_2 ) V_593 -> V_596 . V_597 ;
V_214 [ 1 ] = ( T_2 ) V_593 -> V_596 . V_598 ;
}
memcpy ( V_589 -> V_132 , V_214 , sizeof( V_589 -> V_132 ) ) ;
}
static unsigned int
F_344 ( const struct V_49 * V_50 ,
char * V_553 , T_8 V_479 )
{
unsigned int V_599 ;
F_106 () ;
V_599 = F_345 ( V_553 , V_479 , L_43 ,
V_50 -> V_600 ,
F_346 ( V_50 -> V_548 ,
V_601 ) ,
F_346 ( V_50 -> V_548 ,
V_602 ) ) ;
F_109 () ;
return V_599 ;
}
static unsigned int
F_347 ( const struct V_49 * V_50 ,
char * V_553 , T_8 V_479 )
{
char * V_603 = V_50 -> V_548 -> V_604 ;
if ( V_605 [ 0 ] != '\0' )
V_603 = V_605 ;
return F_345 ( V_553 , V_479 , L_44 ,
V_50 -> V_606 -> V_607 , V_50 -> V_419 ,
V_603 ) ;
}
int F_348 ( struct V_49 * V_50 , T_6 V_608 ,
unsigned short V_609 , struct V_274 * V_308 ,
struct V_610 * V_39 )
{
T_11 V_611 ;
struct V_612 V_613 = {
. V_611 = & V_611 ,
. V_614 = V_608 ,
. V_615 = V_50 -> V_616 ,
} ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_617 ] ,
. V_272 = & V_613 ,
. V_273 = V_39 ,
. V_274 = V_308 ,
} ;
int V_264 ;
F_342 ( V_50 , & V_611 ) ;
if ( F_42 ( V_618 , & V_50 -> V_619 ) )
V_613 . V_620 =
F_347 ( V_50 ,
V_613 . V_621 ,
sizeof( V_613 . V_621 ) ) ;
else
V_613 . V_620 =
F_344 ( V_50 ,
V_613 . V_621 ,
sizeof( V_613 . V_621 ) ) ;
F_106 () ;
V_613 . V_622 = F_345 ( V_613 . V_623 ,
sizeof( V_613 . V_623 ) ,
F_346 ( V_50 -> V_548 ,
V_624 ) ) ;
F_109 () ;
V_613 . V_625 = F_345 ( V_613 . V_626 ,
sizeof( V_613 . V_626 ) , L_45 ,
V_50 -> V_600 , V_609 >> 8 , V_609 & 255 ) ;
F_2 ( L_46 ,
V_50 -> V_548 -> V_627 -> V_628 -> V_629 ,
V_613 . V_620 , V_613 . V_621 ) ;
V_264 = F_58 ( V_50 -> V_548 , & V_137 , V_549 ) ;
F_2 ( L_47 , V_264 ) ;
return V_264 ;
}
int F_349 ( struct V_49 * V_50 ,
struct V_610 * V_347 ,
struct V_274 * V_308 )
{
struct V_136 V_137 = {
. V_269 = & V_270 [ V_630 ] ,
. V_272 = V_347 ,
. V_274 = V_308 ,
} ;
int V_264 ;
F_2 ( L_48 ,
V_50 -> V_548 -> V_627 -> V_628 -> V_629 ,
V_50 -> V_200 ) ;
V_264 = F_58 ( V_50 -> V_548 , & V_137 , V_549 ) ;
F_2 ( L_49 , V_264 ) ;
return V_264 ;
}
static void F_350 ( struct V_100 * V_101 , void * V_130 )
{
struct V_631 * V_132 = V_130 ;
if ( ! F_38 ( V_101 , & V_132 -> V_39 . V_135 ) )
return;
switch ( V_101 -> V_113 ) {
case - V_63 :
case - V_62 :
case 0 :
F_27 ( V_132 -> V_39 . V_45 , V_132 -> V_84 ) ;
break;
default:
if ( F_196 ( V_101 , V_132 -> V_39 . V_45 , NULL ) ==
- V_129 ) {
F_35 ( V_101 ) ;
return;
}
}
V_132 -> V_250 = V_101 -> V_113 ;
}
static void F_351 ( void * V_130 )
{
F_80 ( V_130 ) ;
}
static void F_352 ( struct V_100 * V_101 , void * V_132 )
{
struct V_631 * V_632 ;
V_632 = (struct V_631 * ) V_132 ;
F_49 ( V_632 -> V_39 . V_45 ,
& V_632 -> args . V_134 ,
& V_632 -> V_39 . V_135 ,
V_101 ) ;
}
static int F_353 ( struct V_53 * V_53 , struct V_274 * V_308 , const T_5 * V_217 , int V_633 )
{
struct V_631 * V_132 ;
struct V_44 * V_45 = F_71 ( V_53 ) ;
struct V_100 * V_101 ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_634 ] ,
. V_274 = V_308 ,
} ;
struct V_138 V_275 = {
. V_140 = V_45 -> V_77 ,
. V_136 = & V_137 ,
. V_141 = & V_635 ,
. V_182 = V_279 ,
} ;
int V_264 = 0 ;
V_132 = F_72 ( sizeof( * V_132 ) , V_262 ) ;
if ( V_132 == NULL )
return - V_125 ;
F_39 ( & V_132 -> args . V_134 , & V_132 -> V_39 . V_135 , 1 ) ;
V_132 -> args . V_376 = & V_132 -> V_211 ;
V_132 -> args . V_217 = & V_132 -> V_217 ;
V_132 -> args . V_207 = V_45 -> V_372 ;
F_151 ( & V_132 -> V_211 , F_78 ( V_53 ) ) ;
F_99 ( & V_132 -> V_217 , V_217 ) ;
V_132 -> V_39 . V_345 = & V_132 -> V_345 ;
V_132 -> V_39 . V_45 = V_45 ;
F_67 ( V_132 -> V_39 . V_345 ) ;
V_132 -> V_84 = V_126 ;
V_132 -> V_250 = 0 ;
V_275 . V_143 = V_132 ;
V_137 . V_272 = & V_132 -> args ;
V_137 . V_273 = & V_132 -> V_39 ;
V_101 = F_54 ( & V_275 ) ;
if ( F_44 ( V_101 ) )
return F_55 ( V_101 ) ;
if ( ! V_633 )
goto V_105;
V_264 = F_91 ( V_101 ) ;
if ( V_264 != 0 )
goto V_105;
V_264 = V_132 -> V_250 ;
if ( V_264 == 0 )
F_301 ( V_53 , & V_132 -> V_345 ) ;
else
F_120 ( V_53 , & V_132 -> V_345 ) ;
V_105:
F_56 ( V_101 ) ;
return V_264 ;
}
int F_354 ( struct V_53 * V_53 , struct V_274 * V_308 , const T_5 * V_217 , int V_633 )
{
struct V_44 * V_45 = F_71 ( V_53 ) ;
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_353 ( V_53 , V_308 , V_217 , V_633 ) ;
switch ( V_1 ) {
case - V_63 :
case - V_62 :
case 0 :
return 0 ;
}
V_1 = F_13 ( V_45 , V_1 , & V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static unsigned long
F_355 ( unsigned long V_38 )
{
F_11 ( V_38 ) ;
V_38 <<= 1 ;
if ( V_38 > V_636 )
return V_636 ;
return V_38 ;
}
static int F_356 ( struct V_51 * V_52 , int V_637 , struct V_638 * V_639 )
{
struct V_53 * V_53 = V_52 -> V_53 ;
struct V_44 * V_45 = F_71 ( V_53 ) ;
struct V_49 * V_50 = V_45 -> V_49 ;
struct V_640 V_347 = {
. V_211 = F_78 ( V_53 ) ,
. V_641 = V_639 ,
} ;
struct V_642 V_39 = {
. V_643 = V_639 ,
} ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_644 ] ,
. V_272 = & V_347 ,
. V_273 = & V_39 ,
. V_274 = V_52 -> V_190 -> V_247 ,
} ;
struct V_645 * V_646 ;
int V_264 ;
V_347 . V_647 . V_199 = V_50 -> V_200 ;
V_264 = F_357 ( V_52 , V_639 ) ;
if ( V_264 != 0 )
goto V_105;
V_646 = V_639 -> V_648 . V_649 . V_190 ;
V_347 . V_647 . V_201 = V_646 -> V_650 . V_204 ;
V_347 . V_647 . V_651 = V_45 -> V_651 ;
V_264 = F_59 ( V_45 -> V_77 , V_45 , & V_137 , & V_347 . V_134 , & V_39 . V_135 , 1 ) ;
switch ( V_264 ) {
case 0 :
V_639 -> V_652 = V_653 ;
break;
case - V_266 :
V_264 = 0 ;
}
V_639 -> V_654 -> V_655 ( V_639 ) ;
V_105:
return V_264 ;
}
static int F_358 ( struct V_51 * V_52 , int V_637 , struct V_638 * V_639 )
{
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_71 ( V_52 -> V_53 ) ,
F_356 ( V_52 , V_637 , V_639 ) ,
& V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static int F_359 ( struct V_656 * V_656 , struct V_638 * V_641 )
{
int V_39 = 0 ;
switch ( V_641 -> V_657 & ( V_658 | V_659 ) ) {
case V_658 :
V_39 = F_360 ( V_656 , V_641 ) ;
break;
case V_659 :
V_39 = F_361 ( V_656 , V_641 ) ;
break;
default:
F_362 () ;
}
return V_39 ;
}
static struct V_660 * F_363 ( struct V_638 * V_641 ,
struct V_259 * V_260 ,
struct V_645 * V_646 ,
struct V_661 * V_171 )
{
struct V_660 * V_26 ;
struct V_53 * V_53 = V_646 -> V_662 -> V_53 ;
V_26 = F_72 ( sizeof( * V_26 ) , V_262 ) ;
if ( V_26 == NULL )
return NULL ;
V_26 -> V_347 . V_211 = F_78 ( V_53 ) ;
V_26 -> V_347 . V_641 = & V_26 -> V_641 ;
V_26 -> V_347 . V_171 = V_171 ;
V_26 -> V_39 . V_171 = V_171 ;
V_26 -> V_347 . V_217 = & V_646 -> V_663 ;
V_26 -> V_646 = V_646 ;
F_76 ( & V_646 -> V_664 ) ;
V_26 -> V_260 = F_127 ( V_260 ) ;
memcpy ( & V_26 -> V_641 , V_641 , sizeof( V_26 -> V_641 ) ) ;
V_26 -> V_45 = F_71 ( V_53 ) ;
return V_26 ;
}
static void F_364 ( void * V_132 )
{
struct V_660 * V_130 = V_132 ;
F_84 ( V_130 -> V_347 . V_171 ) ;
F_365 ( V_130 -> V_646 ) ;
F_138 ( V_130 -> V_260 ) ;
F_80 ( V_130 ) ;
}
static void F_366 ( struct V_100 * V_101 , void * V_132 )
{
struct V_660 * V_130 = V_132 ;
if ( ! F_38 ( V_101 , & V_130 -> V_39 . V_135 ) )
return;
switch ( V_101 -> V_113 ) {
case 0 :
F_99 ( & V_130 -> V_646 -> V_663 ,
& V_130 -> V_39 . V_217 ) ;
F_27 ( V_130 -> V_45 , V_130 -> V_84 ) ;
break;
case - V_61 :
case - V_79 :
case - V_63 :
case - V_62 :
break;
default:
if ( F_196 ( V_101 , V_130 -> V_45 , NULL ) == - V_129 )
F_35 ( V_101 ) ;
}
F_112 ( V_130 -> V_347 . V_171 ) ;
}
static void F_367 ( struct V_100 * V_101 , void * V_132 )
{
struct V_660 * V_130 = V_132 ;
if ( F_150 ( V_130 -> V_347 . V_171 , V_101 ) != 0 )
goto V_281;
if ( F_42 ( V_665 , & V_130 -> V_646 -> V_666 ) == 0 ) {
goto V_282;
}
V_130 -> V_84 = V_126 ;
if ( F_49 ( V_130 -> V_45 ,
& V_130 -> V_347 . V_134 ,
& V_130 -> V_39 . V_135 ,
V_101 ) != 0 )
F_112 ( V_130 -> V_347 . V_171 ) ;
return;
V_282:
V_101 -> V_293 = NULL ;
V_281:
F_38 ( V_101 , & V_130 -> V_39 . V_135 ) ;
}
static struct V_100 * F_368 ( struct V_638 * V_641 ,
struct V_259 * V_260 ,
struct V_645 * V_646 ,
struct V_661 * V_171 )
{
struct V_660 * V_132 ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_667 ] ,
. V_274 = V_260 -> V_308 ,
} ;
struct V_138 V_275 = {
. V_140 = F_237 ( V_646 -> V_662 -> V_53 ) ,
. V_136 = & V_137 ,
. V_141 = & V_668 ,
. V_277 = V_278 ,
. V_182 = V_279 ,
} ;
V_641 -> V_652 = V_653 ;
V_132 = F_363 ( V_641 , V_260 , V_646 , V_171 ) ;
if ( V_132 == NULL ) {
F_84 ( V_171 ) ;
return F_45 ( - V_125 ) ;
}
F_39 ( & V_132 -> V_347 . V_134 , & V_132 -> V_39 . V_135 , 1 ) ;
V_137 . V_272 = & V_132 -> V_347 ;
V_137 . V_273 = & V_132 -> V_39 ;
V_275 . V_143 = V_132 ;
return F_54 ( & V_275 ) ;
}
static int F_369 ( struct V_51 * V_52 , int V_637 , struct V_638 * V_639 )
{
struct V_53 * V_53 = V_52 -> V_53 ;
struct V_179 * V_180 = V_52 -> V_190 ;
struct V_149 * V_150 = F_61 ( V_53 ) ;
struct V_661 * V_171 ;
struct V_645 * V_646 ;
struct V_100 * V_101 ;
int V_264 = 0 ;
unsigned char V_657 = V_639 -> V_657 ;
V_264 = F_357 ( V_52 , V_639 ) ;
V_639 -> V_657 |= V_669 ;
F_370 ( & V_180 -> V_670 ) ;
F_371 ( & V_150 -> V_671 ) ;
if ( F_359 ( V_639 -> V_672 , V_639 ) == - V_261 ) {
F_372 ( & V_150 -> V_671 ) ;
F_373 ( & V_180 -> V_670 ) ;
goto V_105;
}
F_372 ( & V_150 -> V_671 ) ;
F_373 ( & V_180 -> V_670 ) ;
if ( V_264 != 0 )
goto V_105;
V_646 = V_639 -> V_648 . V_649 . V_190 ;
if ( F_42 ( V_665 , & V_646 -> V_666 ) == 0 )
goto V_105;
V_171 = F_73 ( & V_646 -> V_650 , V_335 ) ;
V_264 = - V_125 ;
if ( V_171 == NULL )
goto V_105;
V_101 = F_368 ( V_639 , F_230 ( V_639 -> V_672 ) , V_646 , V_171 ) ;
V_264 = F_55 ( V_101 ) ;
if ( F_44 ( V_101 ) )
goto V_105;
V_264 = F_91 ( V_101 ) ;
F_56 ( V_101 ) ;
V_105:
V_639 -> V_657 = V_657 ;
return V_264 ;
}
static struct V_673 * F_374 ( struct V_638 * V_641 ,
struct V_259 * V_260 , struct V_645 * V_646 ,
T_4 V_185 )
{
struct V_673 * V_26 ;
struct V_53 * V_53 = V_646 -> V_662 -> V_53 ;
struct V_44 * V_45 = F_71 ( V_53 ) ;
V_26 = F_72 ( sizeof( * V_26 ) , V_185 ) ;
if ( V_26 == NULL )
return NULL ;
V_26 -> V_347 . V_211 = F_78 ( V_53 ) ;
V_26 -> V_347 . V_641 = & V_26 -> V_641 ;
V_26 -> V_347 . V_674 = F_73 ( & V_646 -> V_662 -> V_190 -> V_187 , V_185 ) ;
if ( V_26 -> V_347 . V_674 == NULL )
goto V_268;
V_26 -> V_347 . V_675 = F_73 ( & V_646 -> V_650 , V_185 ) ;
if ( V_26 -> V_347 . V_675 == NULL )
goto V_676;
V_26 -> V_347 . V_677 = & V_646 -> V_663 ;
V_26 -> V_347 . V_647 . V_199 = V_45 -> V_49 -> V_200 ;
V_26 -> V_347 . V_647 . V_201 = V_646 -> V_650 . V_204 ;
V_26 -> V_347 . V_647 . V_651 = V_45 -> V_651 ;
V_26 -> V_39 . V_675 = V_26 -> V_347 . V_675 ;
V_26 -> V_646 = V_646 ;
V_26 -> V_45 = V_45 ;
F_76 ( & V_646 -> V_664 ) ;
V_26 -> V_260 = F_127 ( V_260 ) ;
memcpy ( & V_26 -> V_641 , V_641 , sizeof( V_26 -> V_641 ) ) ;
return V_26 ;
V_676:
F_84 ( V_26 -> V_347 . V_674 ) ;
V_268:
F_80 ( V_26 ) ;
return NULL ;
}
static void F_375 ( struct V_100 * V_101 , void * V_130 )
{
struct V_673 * V_132 = V_130 ;
struct V_51 * V_52 = V_132 -> V_646 -> V_662 ;
F_2 ( L_30 , V_18 ) ;
if ( F_150 ( V_132 -> V_347 . V_675 , V_101 ) != 0 )
goto V_281;
if ( ! ( V_132 -> V_347 . V_675 -> V_678 -> V_182 & V_679 ) ) {
if ( F_150 ( V_132 -> V_347 . V_674 , V_101 ) != 0 ) {
goto V_680;
}
V_132 -> V_347 . V_235 = & V_52 -> V_235 ;
V_132 -> V_347 . V_681 = 1 ;
V_132 -> V_39 . V_674 = V_132 -> V_347 . V_674 ;
} else
V_132 -> V_347 . V_681 = 0 ;
if ( ! F_188 ( V_52 ) ) {
V_132 -> V_250 = - V_360 ;
V_101 -> V_293 = NULL ;
goto V_682;
}
V_132 -> V_84 = V_126 ;
if ( F_49 ( V_132 -> V_45 ,
& V_132 -> V_347 . V_134 ,
& V_132 -> V_39 . V_135 ,
V_101 ) == 0 )
return;
V_682:
F_112 ( V_132 -> V_347 . V_674 ) ;
V_680:
F_112 ( V_132 -> V_347 . V_675 ) ;
V_281:
F_38 ( V_101 , & V_132 -> V_39 . V_135 ) ;
F_2 ( L_50 , V_18 , V_132 -> V_250 ) ;
}
static void F_376 ( struct V_100 * V_101 , void * V_130 )
{
struct V_673 * V_132 = V_130 ;
F_2 ( L_30 , V_18 ) ;
if ( ! F_38 ( V_101 , & V_132 -> V_39 . V_135 ) )
return;
V_132 -> V_250 = V_101 -> V_113 ;
if ( V_132 -> V_347 . V_681 != 0 ) {
if ( V_132 -> V_250 == 0 )
F_144 ( & V_132 -> V_646 -> V_650 , 0 ) ;
else
goto V_105;
}
if ( V_132 -> V_250 == 0 ) {
F_99 ( & V_132 -> V_646 -> V_663 , & V_132 -> V_39 . V_217 ) ;
F_100 ( V_665 , & V_132 -> V_646 -> V_666 ) ;
F_27 ( F_71 ( V_132 -> V_260 -> V_22 -> V_31 ) , V_132 -> V_84 ) ;
}
V_105:
F_2 ( L_31 , V_18 , V_132 -> V_250 ) ;
}
static void F_377 ( void * V_130 )
{
struct V_673 * V_132 = V_130 ;
F_2 ( L_30 , V_18 ) ;
F_84 ( V_132 -> V_347 . V_674 ) ;
if ( V_132 -> V_267 != 0 ) {
struct V_100 * V_101 ;
V_101 = F_368 ( & V_132 -> V_641 , V_132 -> V_260 , V_132 -> V_646 ,
V_132 -> V_347 . V_675 ) ;
if ( ! F_44 ( V_101 ) )
F_378 ( V_101 ) ;
F_2 ( L_51 , V_18 ) ;
} else
F_84 ( V_132 -> V_347 . V_675 ) ;
F_365 ( V_132 -> V_646 ) ;
F_138 ( V_132 -> V_260 ) ;
F_80 ( V_132 ) ;
F_2 ( L_32 , V_18 ) ;
}
static void F_379 ( struct V_44 * V_45 , struct V_645 * V_646 , int V_681 , int error )
{
switch ( error ) {
case - V_60 :
case - V_61 :
V_646 -> V_650 . V_182 &= ~ V_679 ;
if ( V_681 != 0 ||
F_42 ( V_665 , & V_646 -> V_666 ) != 0 )
F_16 ( V_45 , V_646 -> V_662 ) ;
break;
case - V_63 :
V_646 -> V_650 . V_182 &= ~ V_679 ;
case - V_62 :
F_18 ( V_45 -> V_49 ) ;
} ;
}
static int F_380 ( struct V_51 * V_52 , int V_637 , struct V_638 * V_641 , int V_683 )
{
struct V_673 * V_132 ;
struct V_100 * V_101 ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_684 ] ,
. V_274 = V_52 -> V_190 -> V_247 ,
} ;
struct V_138 V_275 = {
. V_140 = F_237 ( V_52 -> V_53 ) ,
. V_136 = & V_137 ,
. V_141 = & V_685 ,
. V_277 = V_278 ,
. V_182 = V_279 ,
} ;
int V_54 ;
F_2 ( L_30 , V_18 ) ;
V_132 = F_374 ( V_641 , F_230 ( V_641 -> V_672 ) ,
V_641 -> V_648 . V_649 . V_190 ,
V_683 == V_686 ? V_335 : V_262 ) ;
if ( V_132 == NULL )
return - V_125 ;
if ( F_381 ( V_637 ) )
V_132 -> V_347 . V_687 = 1 ;
F_39 ( & V_132 -> V_347 . V_134 , & V_132 -> V_39 . V_135 , 1 ) ;
V_137 . V_272 = & V_132 -> V_347 ;
V_137 . V_273 = & V_132 -> V_39 ;
V_275 . V_143 = V_132 ;
if ( V_683 > V_686 ) {
if ( V_683 == V_688 )
V_132 -> V_347 . V_689 = V_688 ;
F_40 ( & V_132 -> V_347 . V_134 ) ;
}
V_101 = F_54 ( & V_275 ) ;
if ( F_44 ( V_101 ) )
return F_55 ( V_101 ) ;
V_54 = F_91 ( V_101 ) ;
if ( V_54 == 0 ) {
V_54 = V_132 -> V_250 ;
if ( V_54 )
F_379 ( V_132 -> V_45 , V_132 -> V_646 ,
V_132 -> V_347 . V_681 , V_54 ) ;
} else
V_132 -> V_267 = 1 ;
F_56 ( V_101 ) ;
F_2 ( L_31 , V_18 , V_54 ) ;
return V_54 ;
}
static int F_382 ( struct V_51 * V_52 , struct V_638 * V_639 )
{
struct V_44 * V_45 = F_71 ( V_52 -> V_53 ) ;
struct V_47 V_48 = {
. V_53 = V_52 -> V_53 ,
} ;
int V_1 ;
do {
if ( F_42 ( V_234 , & V_52 -> V_182 ) != 0 )
return 0 ;
V_1 = F_380 ( V_52 , V_690 , V_639 , V_688 ) ;
if ( V_1 != - V_76 )
break;
F_13 ( V_45 , V_1 , & V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static int F_383 ( struct V_51 * V_52 , struct V_638 * V_639 )
{
struct V_44 * V_45 = F_71 ( V_52 -> V_53 ) ;
struct V_47 V_48 = {
. V_53 = V_52 -> V_53 ,
} ;
int V_1 ;
V_1 = F_357 ( V_52 , V_639 ) ;
if ( V_1 != 0 )
return V_1 ;
do {
if ( F_42 ( V_234 , & V_52 -> V_182 ) != 0 )
return 0 ;
V_1 = F_380 ( V_52 , V_690 , V_639 , V_691 ) ;
switch ( V_1 ) {
default:
goto V_105;
case - V_75 :
case - V_76 :
F_13 ( V_45 , V_1 , & V_48 ) ;
V_1 = 0 ;
}
} while ( V_48 . V_55 );
V_105:
return V_1 ;
}
static int F_384 ( struct V_51 * V_52 )
{
int V_264 , V_54 = - V_61 ;
struct V_645 * V_646 ;
struct V_44 * V_45 = F_71 ( V_52 -> V_53 ) ;
F_126 (lsp, &state->lock_states, ls_locks) {
if ( F_42 ( V_665 , & V_646 -> V_666 ) ) {
V_264 = F_169 ( V_45 , & V_646 -> V_663 ) ;
if ( V_264 != V_321 ) {
if ( V_264 != - V_61 )
F_170 ( V_45 ,
& V_646 -> V_663 ) ;
F_133 ( V_665 , & V_646 -> V_666 ) ;
V_54 = V_264 ;
}
}
} ;
return V_54 ;
}
static int F_385 ( struct V_51 * V_52 , struct V_638 * V_639 )
{
int V_264 = V_321 ;
if ( F_42 ( V_692 , & V_52 -> V_182 ) )
V_264 = F_384 ( V_52 ) ;
if ( V_264 != V_321 )
V_264 = F_383 ( V_52 , V_639 ) ;
return V_264 ;
}
static int F_386 ( struct V_51 * V_52 , int V_637 , struct V_638 * V_639 )
{
struct V_179 * V_180 = V_52 -> V_190 ;
struct V_149 * V_150 = F_61 ( V_52 -> V_53 ) ;
unsigned char V_657 = V_639 -> V_657 ;
unsigned int V_330 ;
int V_264 = - V_693 ;
if ( ( V_657 & V_658 ) &&
! F_42 ( V_332 , & V_52 -> V_182 ) )
goto V_105;
V_264 = F_357 ( V_52 , V_639 ) ;
if ( V_264 != 0 )
goto V_105;
V_639 -> V_657 |= V_694 ;
V_264 = F_359 ( V_639 -> V_672 , V_639 ) ;
if ( V_264 < 0 )
goto V_105;
F_371 ( & V_150 -> V_671 ) ;
if ( F_42 ( V_234 , & V_52 -> V_182 ) ) {
V_639 -> V_657 = V_657 & ~ V_695 ;
V_264 = F_359 ( V_639 -> V_672 , V_639 ) ;
goto V_98;
}
V_330 = F_175 ( & V_180 -> V_331 ) ;
F_372 ( & V_150 -> V_671 ) ;
V_264 = F_380 ( V_52 , V_637 , V_639 , V_686 ) ;
if ( V_264 != 0 )
goto V_105;
F_371 ( & V_150 -> V_671 ) ;
if ( F_176 ( & V_180 -> V_331 , V_330 ) ) {
V_264 = - V_76 ;
goto V_98;
}
V_639 -> V_657 = V_657 | V_695 ;
if ( F_359 ( V_639 -> V_672 , V_639 ) < 0 )
F_21 ( V_82 L_52
L_53 , V_18 ) ;
V_98:
F_372 ( & V_150 -> V_671 ) ;
V_105:
V_639 -> V_657 = V_657 ;
return V_264 ;
}
static int F_387 ( struct V_51 * V_52 , int V_637 , struct V_638 * V_639 )
{
struct V_47 V_48 = {
. V_52 = V_52 ,
. V_53 = V_52 -> V_53 ,
} ;
int V_1 ;
do {
V_1 = F_386 ( V_52 , V_637 , V_639 ) ;
if ( V_1 == - V_266 )
V_1 = - V_129 ;
V_1 = F_13 ( F_71 ( V_52 -> V_53 ) ,
V_1 , & V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static int
F_388 ( struct V_656 * V_696 , int V_637 , struct V_638 * V_639 )
{
struct V_259 * V_260 ;
struct V_51 * V_52 ;
unsigned long V_38 = V_697 ;
int V_264 ;
V_260 = F_230 ( V_696 ) ;
V_52 = V_260 -> V_52 ;
if ( V_639 -> V_698 < 0 || V_639 -> V_699 < 0 )
return - V_10 ;
if ( F_389 ( V_637 ) ) {
if ( V_52 != NULL )
return F_358 ( V_52 , V_700 , V_639 ) ;
return 0 ;
}
if ( ! ( F_390 ( V_637 ) || F_381 ( V_637 ) ) )
return - V_10 ;
if ( V_639 -> V_652 == V_653 ) {
if ( V_52 != NULL )
return F_369 ( V_52 , V_637 , V_639 ) ;
return 0 ;
}
if ( V_52 == NULL )
return - V_693 ;
switch ( V_639 -> V_652 ) {
case V_701 :
if ( ! ( V_696 -> V_702 & V_57 ) )
return - V_360 ;
break;
case V_703 :
if ( ! ( V_696 -> V_702 & V_193 ) )
return - V_360 ;
}
do {
V_264 = F_387 ( V_52 , V_637 , V_639 ) ;
if ( ( V_264 != - V_129 ) || F_390 ( V_637 ) )
break;
V_38 = F_355 ( V_38 ) ;
V_264 = - V_43 ;
if ( F_391 () )
break;
} while( V_264 < 0 );
return V_264 ;
}
int F_392 ( struct V_638 * V_641 , struct V_51 * V_52 , const T_5 * V_217 )
{
struct V_44 * V_45 = F_71 ( V_52 -> V_53 ) ;
int V_1 ;
V_1 = F_357 ( V_52 , V_641 ) ;
if ( V_1 != 0 )
return V_1 ;
V_1 = F_380 ( V_52 , V_690 , V_641 , V_686 ) ;
return F_139 ( V_45 , V_52 , V_217 , V_1 ) ;
}
static void F_393 ( void * V_130 )
{
struct V_704 * V_132 = V_130 ;
F_394 ( V_132 -> V_45 , V_132 -> V_646 ) ;
F_80 ( V_130 ) ;
}
static int F_395 ( struct V_44 * V_45 , struct V_645 * V_646 )
{
struct V_704 * V_132 ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_705 ] ,
} ;
if ( V_45 -> V_49 -> V_144 -> V_291 != 0 )
return - V_10 ;
V_132 = F_223 ( sizeof( * V_132 ) , V_262 ) ;
if ( ! V_132 )
return - V_125 ;
V_132 -> V_646 = V_646 ;
V_132 -> V_45 = V_45 ;
V_132 -> args . V_647 . V_199 = V_45 -> V_49 -> V_200 ;
V_132 -> args . V_647 . V_201 = V_646 -> V_650 . V_204 ;
V_132 -> args . V_647 . V_651 = V_45 -> V_651 ;
V_137 . V_272 = & V_132 -> args ;
F_319 ( V_45 -> V_77 , & V_137 , 0 , & V_706 , V_132 ) ;
return 0 ;
}
static int F_396 ( struct V_22 * V_22 , const char * V_707 ,
const void * V_553 , T_8 V_554 ,
int V_182 , int type )
{
if ( strcmp ( V_707 , L_54 ) != 0 )
return - V_10 ;
return F_339 ( V_22 -> V_31 , V_553 , V_554 ) ;
}
static int F_397 ( struct V_22 * V_22 , const char * V_707 ,
void * V_553 , T_8 V_554 , int type )
{
if ( strcmp ( V_707 , L_54 ) != 0 )
return - V_10 ;
return F_333 ( V_22 -> V_31 , V_553 , V_554 ) ;
}
static T_8 F_398 ( struct V_22 * V_22 , char * V_708 ,
T_8 V_709 , const char * V_205 ,
T_8 V_710 , int type )
{
T_8 V_479 = sizeof( V_711 ) ;
if ( ! F_321 ( F_71 ( V_22 -> V_31 ) ) )
return 0 ;
if ( V_708 && V_479 <= V_709 )
memcpy ( V_708 , V_711 , V_479 ) ;
return V_479 ;
}
static void F_225 ( struct V_344 * V_345 )
{
if ( ! ( ( ( V_345 -> V_252 & V_712 ) ||
( V_345 -> V_252 & V_254 ) ) &&
( V_345 -> V_252 & V_423 ) &&
( V_345 -> V_252 & V_713 ) ) )
return;
V_345 -> V_252 |= V_253 | V_438 |
V_439 | V_714 ;
V_345 -> V_221 = V_298 | V_441 | V_442 ;
V_345 -> V_443 = 2 ;
}
static int F_399 ( struct V_36 * V_77 , struct V_53 * V_146 ,
const struct V_425 * V_205 ,
struct V_427 * V_715 ,
struct V_426 * V_426 )
{
struct V_44 * V_45 = F_71 ( V_146 ) ;
T_6 V_207 [ 2 ] = {
[ 0 ] = V_716 | V_717 ,
} ;
struct V_718 args = {
. V_436 = F_78 ( V_146 ) ,
. V_205 = V_205 ,
. V_426 = V_426 ,
. V_207 = V_207 ,
} ;
struct V_719 V_39 = {
. V_715 = V_715 ,
} ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_720 ] ,
. V_272 = & args ,
. V_273 = & V_39 ,
} ;
int V_264 ;
F_2 ( L_55 , V_18 ) ;
if ( F_71 ( V_146 ) -> V_208 [ 1 ] & V_721 )
V_207 [ 1 ] |= V_721 ;
else
V_207 [ 0 ] |= V_30 ;
F_67 ( & V_715 -> V_345 ) ;
V_715 -> V_45 = V_45 ;
V_715 -> V_722 = 0 ;
V_264 = F_59 ( V_77 , V_45 , & V_137 , & args . V_134 , & V_39 . V_135 , 0 ) ;
F_2 ( L_56 , V_18 , V_264 ) ;
return V_264 ;
}
int F_224 ( struct V_36 * V_77 , struct V_53 * V_146 ,
const struct V_425 * V_205 ,
struct V_427 * V_715 ,
struct V_426 * V_426 )
{
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_71 ( V_146 ) ,
F_399 ( V_77 , V_146 , V_205 , V_715 , V_426 ) ,
& V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static int F_400 ( struct V_53 * V_146 , const struct V_425 * V_205 , struct V_723 * V_724 )
{
int V_264 ;
struct V_725 args = {
. V_436 = F_78 ( V_146 ) ,
. V_205 = V_205 ,
} ;
struct V_726 V_39 = {
. V_724 = V_724 ,
} ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_727 ] ,
. V_272 = & args ,
. V_273 = & V_39 ,
} ;
F_2 ( L_57 , V_205 -> V_205 ) ;
V_264 = F_59 ( F_71 ( V_146 ) -> V_77 , F_71 ( V_146 ) , & V_137 , & args . V_134 , & V_39 . V_135 , 0 ) ;
F_2 ( L_58 , V_264 ) ;
return V_264 ;
}
int F_401 ( struct V_53 * V_146 , const struct V_425 * V_205 ,
struct V_723 * V_724 )
{
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_71 ( V_146 ) ,
F_400 ( V_146 , V_205 , V_724 ) ,
& V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static int F_402 ( T_6 V_182 )
{
if ( V_182 & ~ V_728 )
goto V_729;
if ( ( V_182 & V_730 ) &&
( V_182 & V_731 ) )
goto V_729;
if ( ! ( V_182 & ( V_732 ) ) )
goto V_729;
return V_321 ;
V_729:
return - V_733 ;
}
static bool
F_403 ( struct V_734 * V_735 ,
struct V_734 * V_736 )
{
if ( V_735 -> V_737 == V_736 -> V_737 &&
memcmp ( V_735 -> V_738 , V_736 -> V_738 , V_735 -> V_737 ) == 0 )
return true ;
return false ;
}
int F_404 ( struct V_49 * V_50 , struct V_274 * V_308 )
{
int V_264 ;
struct V_739 V_39 ;
struct V_136 V_137 = {
. V_269 =
& V_270 [ V_740 ] ,
. V_272 = V_50 ,
. V_273 = & V_39 ,
. V_274 = V_308 ,
} ;
F_2 ( L_12 , V_18 ) ;
V_39 . V_89 = F_72 ( sizeof( struct V_88 ) , V_262 ) ;
if ( F_405 ( V_39 . V_89 == NULL ) ) {
V_264 = - V_125 ;
goto V_105;
}
V_264 = F_58 ( V_50 -> V_548 , & V_137 , V_549 ) ;
if ( V_264 == 0 ) {
if ( memcmp ( V_39 . V_89 -> V_741 . V_132 ,
V_50 -> V_73 -> V_741 . V_132 , V_742 ) ) {
F_2 ( L_59 , V_18 ) ;
V_264 = - V_19 ;
goto V_743;
}
if ( V_39 . V_146 != V_744 ) {
F_2 ( L_60 ,
V_18 ) ;
V_264 = - V_19 ;
goto V_743;
}
if ( V_39 . V_745 ) {
F_2 ( L_61 ,
V_18 ) ;
V_264 = - V_19 ;
goto V_743;
}
}
V_743:
F_80 ( V_39 . V_89 ) ;
V_105:
F_2 ( L_62 , V_18 , V_264 ) ;
return V_264 ;
}
int F_406 ( struct V_49 * V_50 , struct V_274 * V_308 )
{
T_11 V_21 ;
struct V_746 args = {
. V_21 = & V_21 ,
. V_77 = V_50 ,
. V_182 = V_747 ,
} ;
struct V_748 V_39 = {
0
} ;
int V_264 ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_749 ] ,
. V_272 = & args ,
. V_273 = & V_39 ,
. V_274 = V_308 ,
} ;
F_342 ( V_50 , & V_21 ) ;
args . V_750 = F_347 ( V_50 , args . V_201 ,
sizeof( args . V_201 ) ) ;
F_2 ( L_63 ,
V_50 -> V_548 -> V_627 -> V_628 -> V_629 ,
args . V_750 , args . V_201 ) ;
V_39 . V_751 = F_72 ( sizeof( struct V_752 ) ,
V_262 ) ;
if ( F_405 ( V_39 . V_751 == NULL ) ) {
V_264 = - V_125 ;
goto V_105;
}
V_39 . V_738 = F_72 ( sizeof( struct V_734 ) ,
V_262 ) ;
if ( F_405 ( V_39 . V_738 == NULL ) ) {
V_264 = - V_125 ;
goto V_753;
}
V_39 . V_754 = F_72 ( sizeof( struct V_755 ) , V_262 ) ;
if ( F_405 ( V_39 . V_754 == NULL ) ) {
V_264 = - V_125 ;
goto V_756;
}
V_264 = F_58 ( V_50 -> V_548 , & V_137 , V_549 ) ;
if ( V_264 == 0 )
V_264 = F_402 ( V_39 . V_182 ) ;
if ( V_264 == 0 ) {
V_50 -> V_200 = V_39 . V_199 ;
V_50 -> V_757 = ( V_39 . V_182 & ~ V_758 ) ;
if ( ! ( V_39 . V_182 & V_758 ) )
V_50 -> V_759 = V_39 . V_171 ;
F_80 ( V_50 -> V_760 ) ;
V_50 -> V_760 = V_39 . V_751 ;
V_39 . V_751 = NULL ;
F_80 ( V_50 -> V_761 ) ;
V_50 -> V_761 = V_39 . V_754 ;
if ( V_50 -> V_762 != NULL &&
! F_403 ( V_50 -> V_762 ,
V_39 . V_738 ) ) {
F_2 ( L_64 ,
V_18 ) ;
F_100 ( V_763 , & V_50 -> V_588 ) ;
F_80 ( V_50 -> V_762 ) ;
V_50 -> V_762 = NULL ;
}
if ( V_50 -> V_762 == NULL ) {
V_50 -> V_762 = V_39 . V_738 ;
goto V_105;
}
} else
F_80 ( V_39 . V_754 ) ;
V_753:
F_80 ( V_39 . V_751 ) ;
V_756:
F_80 ( V_39 . V_738 ) ;
V_105:
if ( V_50 -> V_761 != NULL )
F_2 ( L_65
L_66 ,
V_50 -> V_761 -> V_764 , V_50 -> V_761 -> V_205 ,
V_50 -> V_761 -> V_765 . V_766 ,
V_50 -> V_761 -> V_765 . V_767 ) ;
F_2 ( L_67 , V_264 ) ;
return V_264 ;
}
static int F_407 ( struct V_49 * V_50 ,
struct V_274 * V_308 )
{
struct V_136 V_137 = {
. V_269 = & V_270 [ V_768 ] ,
. V_272 = V_50 ,
. V_274 = V_308 ,
} ;
int V_264 ;
V_264 = F_58 ( V_50 -> V_548 , & V_137 , V_549 ) ;
if ( V_264 )
F_2 ( L_68
L_69 , V_264 , V_50 -> V_83 ) ;
return V_264 ;
}
static int F_408 ( struct V_49 * V_50 ,
struct V_274 * V_308 )
{
unsigned int V_769 ;
int V_54 ;
for ( V_769 = V_770 ; V_769 != 0 ; V_769 -- ) {
V_54 = F_407 ( V_50 , V_308 ) ;
switch ( V_54 ) {
case - V_76 :
case - V_771 :
F_141 ( 1 ) ;
break;
default:
return V_54 ;
}
}
return 0 ;
}
int F_409 ( struct V_49 * V_50 )
{
struct V_274 * V_308 ;
int V_54 = 0 ;
if ( V_50 -> V_144 -> V_291 < 1 )
goto V_105;
if ( V_50 -> V_757 == 0 )
goto V_105;
if ( V_50 -> V_772 )
goto V_105;
V_308 = F_410 ( V_50 ) ;
V_54 = F_408 ( V_50 , V_308 ) ;
if ( V_308 )
F_411 ( V_308 ) ;
switch ( V_54 ) {
case 0 :
case - V_64 :
V_50 -> V_757 = 0 ;
}
V_105:
return V_54 ;
}
static void F_412 ( struct V_100 * V_101 ,
void * V_130 )
{
struct V_773 * V_132 =
(struct V_773 * ) V_130 ;
F_2 ( L_12 , V_18 ) ;
F_41 ( V_132 -> V_50 -> V_73 ,
& V_132 -> args -> V_774 ,
& V_132 -> V_39 -> V_775 ,
V_101 ) ;
F_2 ( L_70 , V_18 ) ;
}
static void F_413 ( struct V_100 * V_101 , void * V_130 )
{
struct V_773 * V_132 =
(struct V_773 * ) V_130 ;
F_2 ( L_12 , V_18 ) ;
if ( ! F_32 ( V_101 , & V_132 -> V_39 -> V_775 ) )
return;
switch ( V_101 -> V_113 ) {
case - V_76 :
case - V_75 :
F_2 ( L_71 , V_18 , V_101 -> V_113 ) ;
F_37 ( V_101 , V_40 ) ;
V_101 -> V_113 = 0 ;
case - V_78 :
F_35 ( V_101 ) ;
return;
}
F_2 ( L_70 , V_18 ) ;
}
int F_414 ( struct V_49 * V_50 , struct V_403 * V_504 )
{
struct V_100 * V_101 ;
struct V_776 args ;
struct V_777 V_39 = {
. V_778 = V_504 ,
} ;
struct V_773 V_132 = {
. args = & args ,
. V_39 = & V_39 ,
. V_50 = V_50 ,
} ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_779 ] ,
. V_272 = & args ,
. V_273 = & V_39 ,
} ;
struct V_138 V_139 = {
. V_140 = V_50 -> V_548 ,
. V_136 = & V_137 ,
. V_141 = & V_780 ,
. V_143 = & V_132 ,
. V_182 = V_549 ,
} ;
int V_264 ;
F_39 ( & args . V_774 , & V_39 . V_775 , 0 ) ;
F_40 ( & args . V_774 ) ;
F_2 ( L_12 , V_18 ) ;
V_101 = F_54 ( & V_139 ) ;
if ( F_44 ( V_101 ) )
V_264 = F_55 ( V_101 ) ;
else {
V_264 = V_101 -> V_113 ;
F_56 ( V_101 ) ;
}
F_2 ( L_72 , V_18 , V_264 ) ;
return V_264 ;
}
static void F_415 ( struct V_781 * args )
{
struct V_88 * V_89 = args -> V_77 -> V_73 ;
unsigned int V_782 = V_89 -> V_783 ,
V_784 = V_89 -> V_785 ;
if ( V_782 == 0 )
V_782 = V_786 ;
if ( V_784 == 0 )
V_784 = V_786 ;
args -> V_787 . V_788 = V_782 ;
args -> V_787 . V_789 = V_784 ;
args -> V_787 . V_790 = V_791 ;
args -> V_787 . V_792 = V_793 ;
F_2 ( L_73
L_74 ,
V_18 ,
args -> V_787 . V_788 , args -> V_787 . V_789 ,
args -> V_787 . V_790 , args -> V_787 . V_792 ) ;
args -> V_794 . V_788 = V_558 ;
args -> V_794 . V_789 = V_558 ;
args -> V_794 . V_795 = 0 ;
args -> V_794 . V_790 = V_796 ;
args -> V_794 . V_792 = 1 ;
F_2 ( L_75
L_76 ,
V_18 ,
args -> V_794 . V_788 , args -> V_794 . V_789 ,
args -> V_794 . V_795 , args -> V_794 . V_790 ,
args -> V_794 . V_792 ) ;
}
static int F_416 ( struct V_781 * args , struct V_88 * V_89 )
{
struct V_797 * V_798 = & args -> V_787 ;
struct V_797 * V_799 = & V_89 -> V_787 ;
if ( V_799 -> V_789 > V_798 -> V_789 )
return - V_10 ;
if ( V_799 -> V_790 < V_798 -> V_790 )
return - V_10 ;
if ( V_799 -> V_792 == 0 )
return - V_10 ;
if ( V_799 -> V_792 > V_800 )
V_799 -> V_792 = V_800 ;
return 0 ;
}
static int F_417 ( struct V_781 * args , struct V_88 * V_89 )
{
struct V_797 * V_798 = & args -> V_794 ;
struct V_797 * V_799 = & V_89 -> V_794 ;
if ( V_799 -> V_788 > V_798 -> V_788 )
return - V_10 ;
if ( V_799 -> V_789 < V_798 -> V_789 )
return - V_10 ;
if ( V_799 -> V_795 > V_798 -> V_795 )
return - V_10 ;
if ( V_799 -> V_790 != V_798 -> V_790 )
return - V_10 ;
if ( V_799 -> V_792 != V_798 -> V_792 )
return - V_10 ;
return 0 ;
}
static int F_418 ( struct V_781 * args ,
struct V_88 * V_89 )
{
int V_54 ;
V_54 = F_416 ( args , V_89 ) ;
if ( V_54 )
return V_54 ;
return F_417 ( args , V_89 ) ;
}
static int F_419 ( struct V_49 * V_50 ,
struct V_274 * V_308 )
{
struct V_88 * V_89 = V_50 -> V_73 ;
struct V_781 args = {
. V_77 = V_50 ,
. V_801 = V_802 ,
} ;
struct V_803 V_39 = {
. V_77 = V_50 ,
} ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_804 ] ,
. V_272 = & args ,
. V_273 = & V_39 ,
. V_274 = V_308 ,
} ;
int V_264 ;
F_415 ( & args ) ;
args . V_182 = ( V_805 | V_806 ) ;
V_264 = F_58 ( V_89 -> V_50 -> V_548 , & V_137 , V_549 ) ;
if ( ! V_264 ) {
V_264 = F_418 ( & args , V_89 ) ;
V_50 -> V_759 ++ ;
}
return V_264 ;
}
int F_420 ( struct V_49 * V_50 , struct V_274 * V_308 )
{
int V_264 ;
unsigned * V_807 ;
struct V_88 * V_89 = V_50 -> V_73 ;
F_2 ( L_77 , V_18 , V_50 , V_89 ) ;
V_264 = F_419 ( V_50 , V_308 ) ;
if ( V_264 )
goto V_105;
V_264 = F_421 ( V_89 ) ;
F_2 ( L_78 , V_264 ) ;
if ( V_264 )
goto V_105;
V_807 = ( unsigned * ) & V_89 -> V_741 . V_132 [ 0 ] ;
F_2 ( L_79 , V_18 ,
V_50 -> V_759 , V_807 [ 0 ] , V_807 [ 1 ] , V_807 [ 2 ] , V_807 [ 3 ] ) ;
V_105:
F_2 ( L_70 , V_18 ) ;
return V_264 ;
}
int F_422 ( struct V_88 * V_89 ,
struct V_274 * V_308 )
{
struct V_136 V_137 = {
. V_269 = & V_270 [ V_808 ] ,
. V_272 = V_89 ,
. V_274 = V_308 ,
} ;
int V_264 = 0 ;
F_2 ( L_80 ) ;
if ( V_89 -> V_50 -> V_809 != V_810 )
return V_264 ;
V_264 = F_58 ( V_89 -> V_50 -> V_548 , & V_137 , V_549 ) ;
if ( V_264 )
F_2 ( L_81
L_82 , V_264 ) ;
F_2 ( L_83 ) ;
return V_264 ;
}
static void F_423 ( void * V_132 )
{
struct V_811 * V_130 = V_132 ;
struct V_49 * V_50 = V_130 -> V_50 ;
if ( F_312 ( & V_50 -> V_542 ) > 1 )
F_313 ( V_50 ) ;
F_314 ( V_50 ) ;
F_80 ( V_130 ) ;
}
static int F_424 ( struct V_100 * V_101 , struct V_49 * V_50 )
{
switch( V_101 -> V_113 ) {
case - V_76 :
F_37 ( V_101 , V_41 ) ;
return - V_129 ;
default:
F_18 ( V_50 ) ;
}
return 0 ;
}
static void F_425 ( struct V_100 * V_101 , void * V_132 )
{
struct V_811 * V_130 = V_132 ;
struct V_49 * V_50 = V_130 -> V_50 ;
if ( ! F_32 ( V_101 , V_101 -> V_285 . V_273 ) )
return;
if ( V_101 -> V_113 < 0 ) {
F_2 ( L_84 , V_18 , V_101 -> V_113 ) ;
if ( F_312 ( & V_50 -> V_542 ) == 1 )
goto V_105;
if ( F_424 ( V_101 , V_50 ) == - V_129 ) {
F_35 ( V_101 ) ;
return;
}
}
F_2 ( L_85 , V_18 , V_101 -> V_285 . V_274 ) ;
V_105:
F_2 ( L_70 , V_18 ) ;
}
static void F_426 ( struct V_100 * V_101 , void * V_132 )
{
struct V_811 * V_130 = V_132 ;
struct V_49 * V_50 = V_130 -> V_50 ;
struct V_114 * args ;
struct V_87 * V_39 ;
args = V_101 -> V_285 . V_272 ;
V_39 = V_101 -> V_285 . V_273 ;
F_41 ( V_50 -> V_73 , args , V_39 , V_101 ) ;
}
static struct V_100 * F_427 ( struct V_49 * V_50 ,
struct V_274 * V_308 ,
bool V_812 )
{
struct V_811 * V_130 ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_813 ] ,
. V_274 = V_308 ,
} ;
struct V_138 V_275 = {
. V_140 = V_50 -> V_548 ,
. V_136 = & V_137 ,
. V_141 = & V_814 ,
. V_182 = V_279 | V_549 ,
} ;
if ( ! F_318 ( & V_50 -> V_542 ) )
return F_45 ( - V_19 ) ;
V_130 = F_72 ( sizeof( * V_130 ) , V_262 ) ;
if ( V_130 == NULL ) {
F_314 ( V_50 ) ;
return F_45 ( - V_125 ) ;
}
F_39 ( & V_130 -> args , & V_130 -> V_39 , 0 ) ;
if ( V_812 )
F_40 ( & V_130 -> args ) ;
V_137 . V_272 = & V_130 -> args ;
V_137 . V_273 = & V_130 -> V_39 ;
V_130 -> V_50 = V_50 ;
V_275 . V_143 = V_130 ;
return F_54 ( & V_275 ) ;
}
static int F_428 ( struct V_49 * V_50 , struct V_274 * V_308 , unsigned V_546 )
{
struct V_100 * V_101 ;
int V_54 = 0 ;
if ( ( V_546 & V_815 ) == 0 )
return 0 ;
V_101 = F_427 ( V_50 , V_308 , false ) ;
if ( F_44 ( V_101 ) )
V_54 = F_55 ( V_101 ) ;
else
F_378 ( V_101 ) ;
F_2 ( L_17 , V_18 , V_54 ) ;
return V_54 ;
}
static int F_429 ( struct V_49 * V_50 , struct V_274 * V_308 )
{
struct V_100 * V_101 ;
int V_54 ;
V_101 = F_427 ( V_50 , V_308 , true ) ;
if ( F_44 ( V_101 ) ) {
V_54 = F_55 ( V_101 ) ;
goto V_105;
}
V_54 = F_92 ( V_101 ) ;
if ( ! V_54 ) {
struct V_87 * V_39 = V_101 -> V_285 . V_273 ;
if ( V_101 -> V_113 == 0 )
F_430 ( V_50 , V_39 -> V_109 ) ;
V_54 = V_101 -> V_113 ;
}
F_56 ( V_101 ) ;
V_105:
F_2 ( L_17 , V_18 , V_54 ) ;
return V_54 ;
}
static void F_431 ( struct V_100 * V_101 , void * V_132 )
{
struct V_816 * V_130 = V_132 ;
F_41 ( V_130 -> V_50 -> V_73 ,
& V_130 -> V_347 . V_134 ,
& V_130 -> V_39 . V_135 ,
V_101 ) ;
}
static int F_432 ( struct V_100 * V_101 , struct V_49 * V_50 )
{
switch( V_101 -> V_113 ) {
case 0 :
case - V_817 :
case - V_818 :
break;
case - V_76 :
F_37 ( V_101 , V_41 ) ;
case - V_78 :
return - V_129 ;
default:
F_18 ( V_50 ) ;
}
return 0 ;
}
static void F_433 ( struct V_100 * V_101 , void * V_132 )
{
struct V_816 * V_130 = V_132 ;
struct V_49 * V_50 = V_130 -> V_50 ;
struct V_87 * V_39 = & V_130 -> V_39 . V_135 ;
F_2 ( L_12 , V_18 ) ;
if ( ! F_32 ( V_101 , V_39 ) )
return;
if ( F_432 ( V_101 , V_50 ) == - V_129 ) {
F_35 ( V_101 ) ;
return;
}
F_2 ( L_70 , V_18 ) ;
}
static void F_434 ( void * V_132 )
{
struct V_816 * V_130 = V_132 ;
F_80 ( V_130 ) ;
}
static int F_435 ( struct V_49 * V_50 )
{
struct V_816 * V_130 ;
struct V_100 * V_101 ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_819 ] ,
} ;
struct V_138 V_275 = {
. V_140 = V_50 -> V_548 ,
. V_136 = & V_137 ,
. V_141 = & V_820 ,
. V_182 = V_279 ,
} ;
int V_264 = - V_125 ;
F_2 ( L_12 , V_18 ) ;
V_130 = F_72 ( sizeof( * V_130 ) , V_262 ) ;
if ( V_130 == NULL )
goto V_105;
V_130 -> V_50 = V_50 ;
V_130 -> V_347 . V_821 = 0 ;
F_39 ( & V_130 -> V_347 . V_134 , & V_130 -> V_39 . V_135 , 0 ) ;
F_40 ( & V_130 -> V_347 . V_134 ) ;
V_137 . V_272 = & V_130 -> V_347 ;
V_137 . V_273 = & V_130 -> V_39 ;
V_275 . V_143 = V_130 ;
V_101 = F_54 ( & V_275 ) ;
if ( F_44 ( V_101 ) ) {
V_264 = F_55 ( V_101 ) ;
goto V_105;
}
V_264 = F_91 ( V_101 ) ;
if ( V_264 == 0 )
V_264 = V_101 -> V_113 ;
F_56 ( V_101 ) ;
return 0 ;
V_105:
F_2 ( L_17 , V_18 , V_264 ) ;
return V_264 ;
}
static void
F_436 ( struct V_100 * V_101 , void * V_130 )
{
struct V_822 * V_823 = V_130 ;
struct V_44 * V_45 = F_71 ( V_823 -> args . V_53 ) ;
struct V_88 * V_89 = F_50 ( V_45 ) ;
F_2 ( L_12 , V_18 ) ;
if ( F_41 ( V_89 , & V_823 -> args . V_134 ,
& V_823 -> V_39 . V_135 , V_101 ) )
return;
if ( F_437 ( & V_823 -> args . V_217 ,
F_61 ( V_823 -> args . V_53 ) -> V_824 ,
V_823 -> args . V_260 -> V_52 ) ) {
F_438 ( V_101 , V_825 ) ;
}
}
static void F_439 ( struct V_100 * V_101 , void * V_130 )
{
struct V_822 * V_823 = V_130 ;
struct V_53 * V_53 = V_823 -> args . V_53 ;
struct V_44 * V_45 = F_71 ( V_53 ) ;
struct V_826 * V_827 ;
struct V_51 * V_52 = NULL ;
unsigned long V_828 , V_829 ;
F_2 ( L_12 , V_18 ) ;
if ( ! F_32 ( V_101 , & V_823 -> V_39 . V_135 ) )
goto V_105;
switch ( V_101 -> V_113 ) {
case 0 :
goto V_105;
case - V_3 :
case - V_4 :
V_828 = F_440 ( V_101 -> V_830 ) ;
V_829 = V_823 -> args . V_84 + V_828 ;
if ( F_441 ( V_829 , V_126 ) )
V_101 -> V_113 = - V_76 ;
break;
case - V_62 :
case - V_61 :
F_24 ( & V_53 -> V_151 ) ;
V_827 = F_61 ( V_53 ) -> V_824 ;
if ( ! V_827 || F_442 ( & V_827 -> V_831 ) ) {
F_26 ( & V_53 -> V_151 ) ;
V_52 = V_823 -> args . V_260 -> V_52 ;
} else {
F_443 ( V_832 ) ;
F_444 ( V_827 , & V_832 , NULL ) ;
F_26 ( & V_53 -> V_151 ) ;
F_445 ( & V_832 ) ;
}
}
if ( F_196 ( V_101 , V_45 , V_52 ) == - V_129 )
F_35 ( V_101 ) ;
V_105:
F_2 ( L_70 , V_18 ) ;
}
static T_8 F_446 ( struct V_44 * V_45 )
{
T_6 V_789 = V_45 -> V_49 -> V_73 -> V_787 . V_789 ;
return F_447 ( 0 , V_789 ) ;
}
static void F_448 ( struct V_426 * * V_27 , T_8 V_833 )
{
int V_417 ;
if ( ! V_27 )
return;
for ( V_417 = 0 ; V_417 < V_833 ; V_417 ++ ) {
if ( ! V_27 [ V_417 ] )
break;
F_226 ( V_27 [ V_417 ] ) ;
}
F_80 ( V_27 ) ;
}
static struct V_426 * * F_449 ( T_8 V_833 , T_4 V_834 )
{
struct V_426 * * V_27 ;
int V_417 ;
V_27 = F_450 ( V_833 , sizeof( struct V_426 * ) , V_834 ) ;
if ( ! V_27 ) {
F_2 ( L_86 , V_18 , V_833 ) ;
return NULL ;
}
for ( V_417 = 0 ; V_417 < V_833 ; V_417 ++ ) {
V_27 [ V_417 ] = F_222 ( V_834 ) ;
if ( ! V_27 [ V_417 ] ) {
F_2 ( L_87 , V_18 ) ;
F_448 ( V_27 , V_833 ) ;
return NULL ;
}
}
return V_27 ;
}
static void F_451 ( void * V_130 )
{
struct V_822 * V_823 = V_130 ;
struct V_53 * V_53 = V_823 -> args . V_53 ;
struct V_44 * V_45 = F_71 ( V_53 ) ;
T_8 V_835 = F_446 ( V_45 ) ;
F_2 ( L_12 , V_18 ) ;
F_448 ( V_823 -> args . V_824 . V_27 , V_835 ) ;
F_452 ( F_61 ( V_53 ) -> V_824 ) ;
F_138 ( V_823 -> args . V_260 ) ;
F_80 ( V_130 ) ;
F_2 ( L_70 , V_18 ) ;
}
struct V_836 *
F_453 ( struct V_822 * V_823 , T_4 V_834 )
{
struct V_53 * V_53 = V_823 -> args . V_53 ;
struct V_44 * V_45 = F_71 ( V_53 ) ;
T_8 V_835 = F_446 ( V_45 ) ;
struct V_100 * V_101 ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_837 ] ,
. V_272 = & V_823 -> args ,
. V_273 = & V_823 -> V_39 ,
} ;
struct V_138 V_275 = {
. V_140 = V_45 -> V_77 ,
. V_136 = & V_137 ,
. V_141 = & V_838 ,
. V_143 = V_823 ,
. V_182 = V_279 ,
} ;
struct V_836 * V_839 = NULL ;
int V_264 = 0 ;
F_2 ( L_12 , V_18 ) ;
V_823 -> args . V_824 . V_27 = F_449 ( V_835 , V_834 ) ;
if ( ! V_823 -> args . V_824 . V_27 ) {
F_451 ( V_823 ) ;
return F_45 ( - V_125 ) ;
}
V_823 -> args . V_824 . V_453 = V_835 * V_558 ;
V_823 -> args . V_84 = V_126 ;
V_823 -> V_39 . V_840 = & V_823 -> args . V_824 ;
V_823 -> V_39 . V_135 . V_93 = NULL ;
F_39 ( & V_823 -> args . V_134 , & V_823 -> V_39 . V_135 , 0 ) ;
F_454 ( F_61 ( V_53 ) -> V_824 ) ;
V_101 = F_54 ( & V_275 ) ;
if ( F_44 ( V_101 ) )
return F_202 ( V_101 ) ;
V_264 = F_91 ( V_101 ) ;
if ( V_264 == 0 )
V_264 = V_101 -> V_113 ;
if ( V_264 == 0 && V_823 -> V_39 . V_840 -> V_479 )
V_839 = F_455 ( V_823 ) ;
F_56 ( V_101 ) ;
F_2 ( L_17 , V_18 , V_264 ) ;
if ( V_264 )
return F_45 ( V_264 ) ;
return V_839 ;
}
static void
F_456 ( struct V_100 * V_101 , void * V_130 )
{
struct V_841 * V_842 = V_130 ;
F_2 ( L_12 , V_18 ) ;
F_41 ( V_842 -> V_50 -> V_73 ,
& V_842 -> args . V_134 ,
& V_842 -> V_39 . V_135 ,
V_101 ) ;
}
static void F_457 ( struct V_100 * V_101 , void * V_130 )
{
struct V_841 * V_842 = V_130 ;
struct V_44 * V_45 ;
F_2 ( L_12 , V_18 ) ;
if ( ! F_32 ( V_101 , & V_842 -> V_39 . V_135 ) )
return;
V_45 = F_71 ( V_842 -> args . V_53 ) ;
if ( F_196 ( V_101 , V_45 , NULL ) == - V_129 ) {
F_35 ( V_101 ) ;
return;
}
F_2 ( L_70 , V_18 ) ;
}
static void F_458 ( void * V_130 )
{
struct V_841 * V_842 = V_130 ;
struct V_826 * V_827 = V_842 -> args . V_824 ;
F_2 ( L_12 , V_18 ) ;
F_24 ( & V_827 -> V_843 -> V_151 ) ;
if ( V_842 -> V_39 . V_844 )
F_459 ( V_827 , & V_842 -> V_39 . V_217 , true ) ;
V_827 -> V_845 -- ;
F_26 ( & V_827 -> V_843 -> V_151 ) ;
F_452 ( V_842 -> args . V_824 ) ;
F_80 ( V_130 ) ;
F_2 ( L_70 , V_18 ) ;
}
int F_460 ( struct V_841 * V_842 )
{
struct V_100 * V_101 ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_846 ] ,
. V_272 = & V_842 -> args ,
. V_273 = & V_842 -> V_39 ,
} ;
struct V_138 V_275 = {
. V_140 = V_842 -> V_50 -> V_548 ,
. V_136 = & V_137 ,
. V_141 = & V_847 ,
. V_143 = V_842 ,
} ;
int V_264 ;
F_2 ( L_12 , V_18 ) ;
F_39 ( & V_842 -> args . V_134 , & V_842 -> V_39 . V_135 , 1 ) ;
V_101 = F_54 ( & V_275 ) ;
if ( F_44 ( V_101 ) )
return F_55 ( V_101 ) ;
V_264 = V_101 -> V_113 ;
F_2 ( L_17 , V_18 , V_264 ) ;
F_56 ( V_101 ) ;
return V_264 ;
}
static int F_461 ( struct V_44 * V_45 ,
const struct V_375 * V_211 ,
struct V_848 * V_849 )
{
struct V_850 args = {
. V_211 = V_211 ,
. V_851 = V_45 -> V_852 -> V_201 ,
} ;
struct V_853 V_39 = {
. V_849 = V_849 ,
} ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_854 ] ,
. V_272 = & args ,
. V_273 = & V_39 ,
} ;
int V_264 ;
F_2 ( L_12 , V_18 ) ;
V_264 = F_59 ( V_45 -> V_77 , V_45 , & V_137 , & args . V_134 ,
& V_39 . V_135 , 0 ) ;
F_2 ( L_17 , V_18 , V_264 ) ;
return V_264 ;
}
int F_462 ( struct V_44 * V_45 ,
const struct V_375 * V_211 ,
struct V_848 * V_849 )
{
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_13 ( V_45 ,
F_461 ( V_45 , V_211 , V_849 ) ,
& V_48 ) ;
} while ( V_48 . V_55 );
F_2 ( L_88 , V_18 ,
V_1 , V_849 -> V_855 ) ;
return V_1 ;
}
static int
F_463 ( struct V_44 * V_45 , struct V_856 * V_857 )
{
struct V_858 args = {
. V_857 = V_857 ,
} ;
struct V_859 V_39 = {
. V_857 = V_857 ,
} ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_860 ] ,
. V_272 = & args ,
. V_273 = & V_39 ,
} ;
int V_264 ;
F_2 ( L_12 , V_18 ) ;
V_264 = F_59 ( V_45 -> V_77 , V_45 , & V_137 , & args . V_134 , & V_39 . V_135 , 0 ) ;
F_2 ( L_17 , V_18 , V_264 ) ;
return V_264 ;
}
int F_464 ( struct V_44 * V_45 , struct V_856 * V_857 )
{
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_13 ( V_45 ,
F_463 ( V_45 , V_857 ) ,
& V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static void F_465 ( struct V_100 * V_101 , void * V_130 )
{
struct V_861 * V_132 = V_130 ;
struct V_44 * V_45 = F_71 ( V_132 -> args . V_53 ) ;
struct V_88 * V_89 = F_50 ( V_45 ) ;
F_41 ( V_89 ,
& V_132 -> args . V_134 ,
& V_132 -> V_39 . V_135 ,
V_101 ) ;
}
static void
F_466 ( struct V_100 * V_101 , void * V_130 )
{
struct V_861 * V_132 = V_130 ;
struct V_44 * V_45 = F_71 ( V_132 -> args . V_53 ) ;
if ( ! F_32 ( V_101 , & V_132 -> V_39 . V_135 ) )
return;
switch ( V_101 -> V_113 ) {
case - V_59 :
case - V_862 :
case - V_863 :
case - V_75 :
V_101 -> V_113 = 0 ;
break;
case 0 :
F_301 ( V_132 -> args . V_53 ,
V_132 -> V_39 . V_345 ) ;
break;
default:
if ( F_196 ( V_101 , V_45 , NULL ) == - V_129 ) {
F_35 ( V_101 ) ;
return;
}
}
}
static void F_467 ( void * V_130 )
{
struct V_861 * V_132 = V_130 ;
F_468 ( V_132 ) ;
F_411 ( V_132 -> V_308 ) ;
F_80 ( V_132 ) ;
}
int
F_469 ( struct V_861 * V_132 , bool V_864 )
{
struct V_136 V_137 = {
. V_269 = & V_270 [ V_865 ] ,
. V_272 = & V_132 -> args ,
. V_273 = & V_132 -> V_39 ,
. V_274 = V_132 -> V_308 ,
} ;
struct V_138 V_275 = {
. V_101 = & V_132 -> V_101 ,
. V_140 = F_237 ( V_132 -> args . V_53 ) ,
. V_136 = & V_137 ,
. V_141 = & V_866 ,
. V_143 = V_132 ,
. V_182 = V_279 ,
} ;
struct V_100 * V_101 ;
int V_264 = 0 ;
F_2 ( L_89
L_90 ,
V_132 -> V_101 . V_867 , V_864 ,
V_132 -> args . V_868 ,
V_132 -> args . V_53 -> V_869 ) ;
F_39 ( & V_132 -> args . V_134 , & V_132 -> V_39 . V_135 , 1 ) ;
V_101 = F_54 ( & V_275 ) ;
if ( F_44 ( V_101 ) )
return F_55 ( V_101 ) ;
if ( V_864 == false )
goto V_105;
V_264 = F_91 ( V_101 ) ;
if ( V_264 != 0 )
goto V_105;
V_264 = V_101 -> V_113 ;
V_105:
F_2 ( L_91 , V_18 , V_264 ) ;
F_56 ( V_101 ) ;
return V_264 ;
}
static int
F_470 ( struct V_44 * V_45 , struct V_375 * V_376 ,
struct V_403 * V_404 , struct V_723 * V_724 )
{
struct V_870 args = {
. V_871 = V_872 ,
} ;
struct V_726 V_39 = {
. V_724 = V_724 ,
} ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_873 ] ,
. V_272 = & args ,
. V_273 = & V_39 ,
} ;
return F_59 ( V_45 -> V_77 , V_45 , & V_137 , & args . V_134 , & V_39 . V_135 , 0 ) ;
}
static int
F_471 ( struct V_44 * V_45 , struct V_375 * V_376 ,
struct V_403 * V_404 , struct V_723 * V_724 )
{
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_470 ( V_45 , V_376 , V_404 , V_724 ) ;
switch ( V_1 ) {
case 0 :
case - V_6 :
case - V_874 :
goto V_105;
default:
V_1 = F_13 ( V_45 , V_1 , & V_48 ) ;
}
} while ( V_48 . V_55 );
V_105:
return V_1 ;
}
static int
F_472 ( struct V_44 * V_45 , struct V_375 * V_376 ,
struct V_403 * V_404 )
{
int V_1 ;
struct V_426 * V_426 ;
T_7 V_408 ;
struct V_723 * V_724 ;
V_426 = F_222 ( V_335 ) ;
if ( ! V_426 ) {
V_1 = - V_125 ;
goto V_105;
}
V_724 = F_324 ( V_426 ) ;
V_1 = F_471 ( V_45 , V_376 , V_404 , V_724 ) ;
if ( V_1 == - V_6 || V_1 == - V_874 ) {
V_1 = F_212 ( V_45 , V_376 , V_404 ) ;
goto V_875;
}
if ( V_1 )
goto V_875;
V_408 = F_473 ( V_724 ) ;
if ( V_1 == 0 )
V_1 = F_210 ( V_45 , V_376 , V_404 , V_408 ) ;
V_875:
F_337 ( V_426 ) ;
if ( V_1 == - V_12 )
return - V_7 ;
V_105:
return V_1 ;
}
static int F_474 ( struct V_44 * V_45 , T_5 * V_217 )
{
int V_264 ;
struct V_876 args = {
. V_217 = V_217 ,
} ;
struct V_877 V_39 ;
struct V_136 V_137 = {
. V_269 = & V_270 [ V_878 ] ,
. V_272 = & args ,
. V_273 = & V_39 ,
} ;
F_2 ( L_92 , V_217 ) ;
F_39 ( & args . V_134 , & V_39 . V_135 , 0 ) ;
F_40 ( & args . V_134 ) ;
V_264 = F_53 ( V_45 -> V_77 , V_45 , & V_137 ,
& args . V_134 , & V_39 . V_135 ) ;
if ( V_264 != V_321 ) {
F_2 ( L_93 , V_264 ) ;
return V_264 ;
}
F_2 ( L_94 , - V_39 . V_264 ) ;
return - V_39 . V_264 ;
}
static int F_169 ( struct V_44 * V_45 , T_5 * V_217 )
{
struct V_47 V_48 = { } ;
int V_1 ;
do {
V_1 = F_474 ( V_45 , V_217 ) ;
if ( V_1 != - V_76 )
break;
F_13 ( V_45 , V_1 , & V_48 ) ;
} while ( V_48 . V_55 );
return V_1 ;
}
static void F_475 ( struct V_100 * V_101 , void * V_130 )
{
struct V_879 * V_132 = V_130 ;
F_41 ( F_50 ( V_132 -> V_45 ) ,
& V_132 -> args . V_134 ,
& V_132 -> V_39 . V_135 ,
V_101 ) ;
}
static void F_476 ( struct V_100 * V_101 , void * V_130 )
{
struct V_879 * V_132 = V_130 ;
F_32 ( V_101 , & V_132 -> V_39 . V_135 ) ;
switch ( V_101 -> V_113 ) {
case - V_76 :
if ( F_196 ( V_101 , V_132 -> V_45 , NULL ) == - V_129 )
F_35 ( V_101 ) ;
}
}
static void F_477 ( void * V_130 )
{
F_80 ( V_130 ) ;
}
static struct V_100 * F_478 ( struct V_44 * V_45 ,
T_5 * V_217 ,
bool V_880 )
{
struct V_136 V_137 = {
. V_269 = & V_270 [ V_881 ] ,
} ;
struct V_138 V_139 = {
. V_140 = V_45 -> V_77 ,
. V_136 = & V_137 ,
. V_141 = & V_882 ,
. V_182 = V_279 ,
} ;
struct V_879 * V_132 ;
F_2 ( L_95 , V_217 ) ;
V_132 = F_223 ( sizeof( * V_132 ) , V_262 ) ;
if ( ! V_132 )
return F_45 ( - V_125 ) ;
V_132 -> V_45 = V_45 ;
F_99 ( & V_132 -> args . V_217 , V_217 ) ;
V_139 . V_143 = V_132 ;
V_137 . V_272 = & V_132 -> args ;
V_137 . V_273 = & V_132 -> V_39 ;
F_39 ( & V_132 -> args . V_134 , & V_132 -> V_39 . V_135 , 0 ) ;
if ( V_880 )
F_40 ( & V_132 -> args . V_134 ) ;
return F_54 ( & V_139 ) ;
}
static int F_170 ( struct V_44 * V_45 , T_5 * V_217 )
{
struct V_100 * V_101 ;
int V_54 ;
V_101 = F_478 ( V_45 , V_217 , true ) ;
if ( F_44 ( V_101 ) )
return F_55 ( V_101 ) ;
V_54 = F_92 ( V_101 ) ;
if ( ! V_54 )
V_54 = V_101 -> V_113 ;
F_56 ( V_101 ) ;
return V_54 ;
}
static int F_479 ( struct V_44 * V_45 , struct V_645 * V_646 )
{
struct V_100 * V_101 ;
V_101 = F_478 ( V_45 , & V_646 -> V_663 , false ) ;
F_394 ( V_45 , V_646 ) ;
if ( F_44 ( V_101 ) )
return F_55 ( V_101 ) ;
F_56 ( V_101 ) ;
return 0 ;
}
static bool F_480 ( const T_5 * V_883 ,
const T_5 * V_884 )
{
if ( memcmp ( V_883 -> V_885 , V_884 -> V_885 , sizeof( V_883 -> V_885 ) ) != 0 )
return false ;
if ( V_883 -> V_171 == V_884 -> V_171 )
return true ;
if ( V_883 -> V_171 == 0 || V_884 -> V_171 == 0 )
return true ;
return false ;
}
static bool F_481 ( const T_5 * V_883 ,
const T_5 * V_884 )
{
return F_108 ( V_883 , V_884 ) ;
}
