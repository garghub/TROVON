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
default:
F_2 ( L_1 ,
V_16 , - V_1 ) ;
break;
}
return - V_17 ;
}
static void F_3 ( T_1 V_18 , T_2 * V_19 , struct V_20 * V_20 ,
struct V_21 * V_22 )
{
T_2 * V_23 , * V_24 ;
if ( V_18 > 2 ) {
V_22 -> V_18 = V_18 ;
memcpy ( & V_22 -> V_19 , V_19 , sizeof( V_22 -> V_19 ) ) ;
return;
}
V_22 -> V_18 = 0 ;
memset ( & V_22 -> V_19 , 0 , sizeof( V_22 -> V_19 ) ) ;
if ( V_18 == 2 )
return;
V_23 = V_24 = F_4 ( * V_22 -> V_25 ) ;
if ( V_18 == 0 ) {
* V_24 ++ = V_26 ;
* V_24 ++ = V_27 ;
* V_24 ++ = V_26 ;
* V_24 ++ = V_26 ;
memcpy ( V_24 , L_2 , 4 ) ;
V_24 ++ ;
* V_24 ++ = V_26 ;
* V_24 ++ = F_5 ( V_28 ) ;
* V_24 ++ = F_5 ( 8 ) ;
V_24 = F_6 ( V_24 , F_7 ( V_20 -> V_29 ) ) ;
}
* V_24 ++ = V_26 ;
* V_24 ++ = V_27 ;
* V_24 ++ = V_30 ;
* V_24 ++ = V_30 ;
memcpy ( V_24 , L_3 , 4 ) ;
V_24 ++ ;
* V_24 ++ = V_26 ;
* V_24 ++ = F_5 ( V_28 ) ;
* V_24 ++ = F_5 ( 8 ) ;
V_24 = F_6 ( V_24 , F_7 ( V_20 -> V_31 -> V_29 ) ) ;
V_22 -> V_32 = ( char * ) V_24 - ( char * ) V_23 ;
V_22 -> V_33 -= V_22 -> V_32 ;
F_8 ( V_23 ) ;
}
static int F_9 ( struct V_34 * V_35 , long * V_36 )
{
int V_37 = 0 ;
F_10 () ;
if ( * V_36 <= 0 )
* V_36 = V_38 ;
if ( * V_36 > V_39 )
* V_36 = V_39 ;
F_11 ( * V_36 ) ;
if ( F_12 ( V_40 ) )
V_37 = - V_41 ;
* V_36 <<= 1 ;
return V_37 ;
}
static int F_13 ( struct V_42 * V_43 , int V_44 , struct V_45 * V_46 )
{
struct V_47 * V_48 = V_43 -> V_47 ;
struct V_49 * V_50 = V_46 -> V_50 ;
struct V_51 * V_51 = V_46 -> V_51 ;
int V_52 = V_44 ;
V_46 -> V_53 = 0 ;
switch( V_44 ) {
case 0 :
return 0 ;
case - V_54 :
if ( V_51 && F_14 ( V_51 , V_55 ) ) {
F_15 ( V_51 ) ;
V_46 -> V_53 = 1 ;
return 0 ;
}
if ( V_50 == NULL )
break;
F_16 ( V_43 , V_50 ) ;
goto V_56;
case - V_57 :
case - V_58 :
case - V_59 :
if ( V_50 == NULL )
break;
F_17 ( V_50 -> V_51 ) ;
F_16 ( V_43 , V_50 ) ;
goto V_56;
case - V_60 :
if ( V_50 != NULL )
F_16 ( V_43 , V_50 ) ;
case - V_61 :
case - V_62 :
F_18 ( V_48 ) ;
goto V_56;
#if F_19 ( V_63 )
case - V_64 :
case - V_65 :
case - V_66 :
case - V_67 :
case - V_68 :
case - V_69 :
case - V_70 :
F_2 ( L_4 , V_16 ,
V_44 ) ;
F_20 ( V_48 -> V_71 , V_44 ) ;
goto V_56;
#endif
case - V_72 :
if ( V_46 -> V_36 > V_73 ) {
V_52 = - V_74 ;
break;
}
case - V_75 :
case - V_76 :
V_52 = F_9 ( V_43 -> V_77 , & V_46 -> V_36 ) ;
if ( V_52 != 0 )
break;
case - V_78 :
case - V_79 :
V_46 -> V_53 = 1 ;
break;
case - V_8 :
case - V_9 :
if ( V_43 -> V_80 & V_81 ) {
V_43 -> V_80 &= ~ V_81 ;
V_46 -> V_53 = 1 ;
F_21 ( V_82 L_5
L_6
L_7
L_8 ,
V_43 -> V_47 -> V_83 ) ;
}
}
return F_1 ( V_52 ) ;
V_56:
V_52 = F_22 ( V_48 ) ;
if ( V_52 == 0 )
V_46 -> V_53 = 1 ;
return V_52 ;
}
static void F_23 ( struct V_47 * V_48 , unsigned long V_84 )
{
F_24 ( & V_48 -> V_85 ) ;
if ( F_25 ( V_48 -> V_86 , V_84 ) )
V_48 -> V_86 = V_84 ;
F_26 ( & V_48 -> V_85 ) ;
}
static void F_27 ( const struct V_42 * V_43 , unsigned long V_84 )
{
F_23 ( V_43 -> V_47 , V_84 ) ;
}
static void F_28 ( struct V_87 * V_37 )
{
struct V_88 * V_89 ;
struct V_90 * V_91 ;
bool V_92 = false ;
if ( ! V_37 -> V_93 ) {
F_2 ( L_9 , V_16 ) ;
return;
}
V_91 = V_37 -> V_93 -> V_94 ;
V_89 = V_91 -> V_89 ;
F_24 ( & V_91 -> V_95 ) ;
if ( V_91 -> V_96 > V_91 -> V_97 )
V_92 = true ;
if ( F_29 ( V_91 , V_37 -> V_93 ) ) {
V_92 = false ;
goto V_98;
}
F_30 ( V_91 , V_37 -> V_93 ) ;
if ( V_91 -> V_96 != V_99 )
V_92 = false ;
V_98:
F_26 ( & V_91 -> V_95 ) ;
V_37 -> V_93 = NULL ;
if ( V_92 )
F_31 ( V_89 -> V_48 ) ;
}
static int F_32 ( struct V_100 * V_101 , struct V_87 * V_37 )
{
struct V_88 * V_89 ;
struct V_102 * V_103 ;
struct V_47 * V_48 ;
bool V_104 = false ;
int V_52 = 1 ;
if ( ! F_33 ( V_101 ) )
goto V_105;
V_103 = V_37 -> V_93 ;
V_89 = V_103 -> V_94 -> V_89 ;
if ( V_103 -> V_104 ) {
V_103 -> V_104 = 0 ;
V_104 = true ;
}
switch ( V_37 -> V_106 ) {
case 0 :
++ V_103 -> V_107 ;
V_48 = V_89 -> V_48 ;
F_23 ( V_48 , V_37 -> V_108 ) ;
if ( V_37 -> V_109 != 0 )
F_18 ( V_48 ) ;
F_34 ( V_103 -> V_94 , V_103 , V_37 ) ;
break;
case 1 :
V_103 -> V_104 = 1 ;
goto V_105;
case - V_76 :
F_2 ( L_10 ,
V_16 ,
V_103 -> V_110 ,
V_103 -> V_107 ) ;
goto V_111;
case - V_65 :
goto V_112;
case - V_70 :
if ( V_104 ) {
++ V_103 -> V_107 ;
goto V_112;
}
if ( V_103 -> V_107 != 1 ) {
V_103 -> V_107 = 1 ;
goto V_112;
}
break;
case - V_69 :
++ V_103 -> V_107 ;
goto V_112;
default:
++ V_103 -> V_107 ;
}
V_105:
F_2 ( L_11 , V_16 , V_37 -> V_106 ) ;
F_28 ( V_37 ) ;
return V_52 ;
V_112:
if ( F_35 ( V_101 ) ) {
V_101 -> V_113 = 0 ;
V_52 = 0 ;
}
goto V_105;
V_111:
if ( ! F_36 ( V_101 ) )
goto V_105;
F_37 ( V_101 , V_39 ) ;
return 0 ;
}
static int F_38 ( struct V_100 * V_101 ,
struct V_87 * V_37 )
{
if ( V_37 -> V_93 == NULL )
return 1 ;
return F_32 ( V_101 , V_37 ) ;
}
static void F_39 ( struct V_114 * args ,
struct V_87 * V_37 , int V_115 )
{
args -> V_116 = NULL ;
args -> V_117 = 0 ;
args -> V_118 = 0 ;
if ( V_115 )
args -> V_117 = 1 ;
V_37 -> V_93 = NULL ;
}
static void F_40 ( struct V_114 * args )
{
args -> V_118 = 1 ;
}
int F_41 ( struct V_88 * V_89 ,
struct V_114 * args ,
struct V_87 * V_37 ,
struct V_100 * V_101 )
{
struct V_102 * V_103 ;
struct V_90 * V_91 ;
F_2 ( L_12 , V_16 ) ;
if ( V_37 -> V_93 != NULL )
goto V_119;
V_91 = & V_89 -> V_120 ;
V_101 -> V_121 = 0 ;
F_24 ( & V_91 -> V_95 ) ;
if ( F_42 ( V_122 , & V_89 -> V_123 ) &&
! args -> V_118 ) {
F_2 ( L_13 , V_16 ) ;
goto V_124;
}
V_103 = F_43 ( V_91 ) ;
if ( F_44 ( V_103 ) ) {
if ( V_103 == F_45 ( - V_125 ) )
V_101 -> V_121 = V_73 >> 2 ;
F_2 ( L_14 , V_16 ) ;
goto V_124;
}
F_26 ( & V_91 -> V_95 ) ;
args -> V_116 = V_103 ;
F_2 ( L_15 , V_16 ,
V_103 -> V_110 , V_103 -> V_107 ) ;
V_37 -> V_93 = V_103 ;
V_37 -> V_108 = V_126 ;
V_37 -> V_109 = 0 ;
V_37 -> V_106 = 1 ;
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
int F_49 ( const struct V_42 * V_43 ,
struct V_114 * args ,
struct V_87 * V_37 ,
struct V_100 * V_101 )
{
struct V_88 * V_89 = F_50 ( V_43 ) ;
int V_52 = 0 ;
if ( V_89 == NULL ) {
F_46 ( V_101 ) ;
goto V_105;
}
F_2 ( L_16 ,
V_16 , V_89 -> V_48 , V_89 , V_37 -> V_93 ?
V_37 -> V_93 -> V_110 : - 1 ) ;
V_52 = F_41 ( V_89 , args , V_37 , V_101 ) ;
V_105:
F_2 ( L_17 , V_16 , V_52 ) ;
return V_52 ;
}
static void F_51 ( struct V_100 * V_101 , void * V_130 )
{
struct V_131 * V_132 = V_130 ;
struct V_88 * V_89 = F_50 ( V_132 -> V_133 ) ;
F_2 ( L_18 , V_16 , V_132 -> V_133 ) ;
F_41 ( V_89 , V_132 -> V_134 , V_132 -> V_135 , V_101 ) ;
}
static void F_52 ( struct V_100 * V_101 , void * V_130 )
{
struct V_131 * V_132 = V_130 ;
F_32 ( V_101 , V_132 -> V_135 ) ;
}
static int F_53 ( struct V_34 * V_35 ,
struct V_42 * V_43 ,
struct V_136 * V_137 ,
struct V_114 * args ,
struct V_87 * V_37 )
{
int V_52 ;
struct V_100 * V_101 ;
struct V_131 V_132 = {
. V_133 = V_43 ,
. V_134 = args ,
. V_135 = V_37 ,
} ;
struct V_138 V_139 = {
. V_140 = V_35 ,
. V_136 = V_137 ,
. V_141 = & V_142 ,
. V_143 = & V_132
} ;
V_101 = F_54 ( & V_139 ) ;
if ( F_44 ( V_101 ) )
V_52 = F_55 ( V_101 ) ;
else {
V_52 = V_101 -> V_113 ;
F_56 ( V_101 ) ;
}
return V_52 ;
}
static
void F_39 ( struct V_114 * args ,
struct V_87 * V_37 , int V_115 )
{
}
static void F_40 ( struct V_114 * args )
{
}
static int F_38 ( struct V_100 * V_101 ,
struct V_87 * V_37 )
{
return 1 ;
}
static
int F_57 ( struct V_34 * V_35 ,
struct V_42 * V_43 ,
struct V_136 * V_137 ,
struct V_114 * args ,
struct V_87 * V_37 )
{
return F_58 ( V_35 , V_137 , 0 ) ;
}
static
int F_59 ( struct V_34 * V_35 ,
struct V_42 * V_43 ,
struct V_136 * V_137 ,
struct V_114 * args ,
struct V_87 * V_37 ,
int V_115 )
{
F_39 ( args , V_37 , V_115 ) ;
return V_43 -> V_47 -> V_144 -> V_145 ( V_35 , V_43 , V_137 ,
args , V_37 ) ;
}
static void F_60 ( struct V_51 * V_146 , struct V_147 * V_148 )
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
static void F_64 ( struct V_159 * V_24 )
{
V_24 -> V_160 . V_161 = & V_24 -> V_161 ;
V_24 -> V_160 . V_162 = V_24 -> V_163 . V_162 ;
V_24 -> V_164 . V_162 = V_24 -> V_165 . V_162 ;
V_24 -> V_160 . V_43 = V_24 -> V_163 . V_43 ;
V_24 -> V_160 . V_166 = V_24 -> V_163 . V_167 ;
F_65 ( & V_24 -> V_161 ) ;
F_66 ( & V_24 -> V_161 , & V_24 -> V_168 , & V_24 -> V_169 ) ;
}
static struct V_159 * F_67 ( struct V_20 * V_20 ,
struct V_170 * V_171 , T_3 V_172 , int V_173 ,
const struct V_174 * V_175 ,
T_4 V_176 )
{
struct V_20 * V_177 = F_68 ( V_20 ) ;
struct V_51 * V_146 = V_177 -> V_29 ;
struct V_42 * V_43 = F_69 ( V_146 ) ;
struct V_159 * V_24 ;
V_24 = F_70 ( sizeof( * V_24 ) , V_176 ) ;
if ( V_24 == NULL )
goto V_1;
V_24 -> V_163 . V_162 = F_71 ( & V_171 -> V_178 , V_176 ) ;
if ( V_24 -> V_163 . V_162 == NULL )
goto V_179;
F_72 ( V_20 -> V_180 ) ;
V_24 -> V_20 = F_73 ( V_20 ) ;
V_24 -> V_146 = V_177 ;
V_24 -> V_181 = V_171 ;
F_74 ( & V_171 -> V_182 ) ;
V_24 -> V_163 . V_183 = F_75 ( V_146 ) ;
V_24 -> V_163 . V_184 = V_173 ;
V_24 -> V_163 . V_172 = V_172 & ( V_55 | V_185 ) ;
if ( ! ( V_173 & V_186 ) ) {
V_24 -> V_163 . V_167 = V_187 | V_188 |
V_189 | V_190 ;
}
V_24 -> V_163 . V_191 = V_43 -> V_47 -> V_192 ;
V_24 -> V_163 . V_193 . V_194 = F_76 ( V_171 -> V_178 . V_194 ) ;
V_24 -> V_163 . V_193 . V_195 = V_171 -> V_178 . V_196 ;
V_24 -> V_163 . V_197 = & V_20 -> V_198 ;
V_24 -> V_163 . V_43 = V_43 ;
V_24 -> V_163 . V_199 = V_43 -> V_200 ;
V_24 -> V_163 . V_201 = & V_202 [ 0 ] ;
V_24 -> V_163 . V_203 = V_204 ;
if ( V_175 != NULL && V_175 -> V_205 != 0 ) {
T_2 V_206 [ 2 ] ;
V_24 -> V_163 . V_207 . V_175 = & V_24 -> V_175 ;
memcpy ( & V_24 -> V_175 , V_175 , sizeof( V_24 -> V_175 ) ) ;
V_206 [ 0 ] = V_126 ;
V_206 [ 1 ] = V_40 -> V_208 ;
memcpy ( V_24 -> V_163 . V_207 . V_19 . V_132 , V_206 ,
sizeof( V_24 -> V_163 . V_207 . V_19 . V_132 ) ) ;
}
V_24 -> V_165 . V_183 = & V_24 -> V_160 . V_183 ;
V_24 -> V_165 . V_209 = & V_24 -> V_160 . V_209 ;
V_24 -> V_165 . V_162 = V_24 -> V_163 . V_162 ;
F_64 ( V_24 ) ;
F_77 ( & V_24 -> V_210 ) ;
return V_24 ;
V_179:
F_78 ( V_24 ) ;
V_1:
F_79 ( V_177 ) ;
return NULL ;
}
static void F_80 ( struct V_210 * V_210 )
{
struct V_159 * V_24 = F_81 ( V_210 ,
struct V_159 , V_210 ) ;
struct V_211 * V_212 = V_24 -> V_20 -> V_180 ;
F_82 ( V_24 -> V_163 . V_162 ) ;
if ( V_24 -> V_50 != NULL )
F_83 ( V_24 -> V_50 ) ;
F_84 ( V_24 -> V_181 ) ;
F_79 ( V_24 -> V_146 ) ;
F_79 ( V_24 -> V_20 ) ;
F_85 ( V_212 ) ;
F_86 ( & V_24 -> V_161 ) ;
F_78 ( V_24 ) ;
}
static void F_87 ( struct V_159 * V_24 )
{
if ( V_24 != NULL )
F_88 ( & V_24 -> V_210 , F_80 ) ;
}
static int F_89 ( struct V_100 * V_101 )
{
int V_52 ;
V_52 = F_90 ( V_101 ) ;
return V_52 ;
}
static int F_91 ( struct V_49 * V_50 , T_3 V_213 , int V_214 )
{
int V_52 = 0 ;
if ( V_214 & ( V_186 | V_215 ) )
goto V_105;
switch ( V_213 & ( V_55 | V_185 ) ) {
case V_55 :
V_52 |= F_42 ( V_216 , & V_50 -> V_173 ) != 0
&& V_50 -> V_217 != 0 ;
break;
case V_185 :
V_52 |= F_42 ( V_218 , & V_50 -> V_173 ) != 0
&& V_50 -> V_219 != 0 ;
break;
case V_55 | V_185 :
V_52 |= F_42 ( V_220 , & V_50 -> V_173 ) != 0
&& V_50 -> V_221 != 0 ;
}
V_105:
return V_52 ;
}
static int F_92 ( struct V_222 * V_223 , T_3 V_172 )
{
if ( V_223 == NULL )
return 0 ;
if ( ( V_223 -> type & V_172 ) != V_172 )
return 0 ;
if ( F_42 ( V_224 , & V_223 -> V_173 ) )
return 0 ;
if ( F_42 ( V_225 , & V_223 -> V_173 ) )
return 0 ;
F_93 ( V_223 ) ;
return 1 ;
}
static void F_94 ( struct V_49 * V_50 , T_3 V_172 )
{
switch ( V_172 ) {
case V_185 :
V_50 -> V_219 ++ ;
break;
case V_55 :
V_50 -> V_217 ++ ;
break;
case V_55 | V_185 :
V_50 -> V_221 ++ ;
}
F_95 ( V_50 , V_50 -> V_50 | V_172 ) ;
}
static void F_96 ( struct V_49 * V_50 , T_5 * V_209 , T_3 V_172 )
{
if ( F_42 ( V_226 , & V_50 -> V_173 ) == 0 )
F_97 ( & V_50 -> V_209 , V_209 ) ;
F_97 ( & V_50 -> V_227 , V_209 ) ;
switch ( V_172 ) {
case V_55 :
F_98 ( V_216 , & V_50 -> V_173 ) ;
break;
case V_185 :
F_98 ( V_218 , & V_50 -> V_173 ) ;
break;
case V_55 | V_185 :
F_98 ( V_220 , & V_50 -> V_173 ) ;
}
}
static void F_99 ( struct V_49 * V_50 , T_5 * V_209 , T_3 V_172 )
{
F_100 ( & V_50 -> V_228 ) ;
F_96 ( V_50 , V_209 , V_172 ) ;
F_101 ( & V_50 -> V_228 ) ;
}
static void F_102 ( struct V_49 * V_50 , T_5 * V_227 , const T_5 * V_229 , T_3 V_172 )
{
F_100 ( & V_50 -> V_228 ) ;
if ( V_229 != NULL ) {
F_97 ( & V_50 -> V_209 , V_229 ) ;
F_98 ( V_226 , & V_50 -> V_173 ) ;
}
if ( V_227 != NULL )
F_96 ( V_50 , V_227 , V_172 ) ;
F_101 ( & V_50 -> V_228 ) ;
F_24 ( & V_50 -> V_181 -> V_230 ) ;
F_94 ( V_50 , V_172 ) ;
F_26 ( & V_50 -> V_181 -> V_230 ) ;
}
static int F_103 ( struct V_49 * V_50 , T_5 * V_227 , T_5 * V_223 , T_3 V_172 )
{
struct V_149 * V_150 = F_61 ( V_50 -> V_51 ) ;
struct V_222 * V_231 ;
int V_52 = 0 ;
V_172 &= ( V_55 | V_185 ) ;
F_104 () ;
V_231 = F_105 ( V_150 -> V_223 ) ;
if ( V_231 == NULL )
goto V_232;
F_24 ( & V_231 -> V_233 ) ;
if ( V_150 -> V_223 != V_231 ||
F_42 ( V_225 , & V_231 -> V_173 ) ||
( V_231 -> type & V_172 ) != V_172 )
goto V_234;
if ( V_223 == NULL )
V_223 = & V_231 -> V_209 ;
else if ( ! F_106 ( & V_231 -> V_209 , V_223 ) )
goto V_234;
F_93 ( V_231 ) ;
F_102 ( V_50 , V_227 , & V_231 -> V_209 , V_172 ) ;
V_52 = 1 ;
V_234:
F_26 ( & V_231 -> V_233 ) ;
V_232:
F_107 () ;
if ( ! V_52 && V_227 != NULL ) {
F_102 ( V_50 , V_227 , NULL , V_172 ) ;
V_52 = 1 ;
}
return V_52 ;
}
static void F_108 ( struct V_51 * V_51 , T_3 V_172 )
{
struct V_222 * V_223 ;
F_104 () ;
V_223 = F_105 ( F_61 ( V_51 ) -> V_223 ) ;
if ( V_223 == NULL || ( V_223 -> type & V_172 ) == V_172 ) {
F_107 () ;
return;
}
F_107 () ;
F_15 ( V_51 ) ;
}
static struct V_49 * F_109 ( struct V_159 * V_235 )
{
struct V_49 * V_50 = V_235 -> V_50 ;
struct V_149 * V_150 = F_61 ( V_50 -> V_51 ) ;
struct V_222 * V_223 ;
int V_214 = V_235 -> V_163 . V_184 & ( V_186 | V_215 ) ;
T_3 V_172 = V_235 -> V_163 . V_172 ;
T_5 V_209 ;
int V_52 = - V_129 ;
for (; ; ) {
if ( F_91 ( V_50 , V_172 , V_214 ) ) {
F_24 ( & V_50 -> V_181 -> V_230 ) ;
if ( F_91 ( V_50 , V_172 , V_214 ) ) {
F_94 ( V_50 , V_172 ) ;
F_26 ( & V_50 -> V_181 -> V_230 ) ;
goto V_236;
}
F_26 ( & V_50 -> V_181 -> V_230 ) ;
}
F_104 () ;
V_223 = F_105 ( V_150 -> V_223 ) ;
if ( ! F_92 ( V_223 , V_172 ) ) {
F_107 () ;
break;
}
F_97 ( & V_209 , & V_223 -> V_209 ) ;
F_107 () ;
F_110 ( V_235 -> V_163 . V_162 ) ;
V_52 = F_111 ( V_50 -> V_51 , V_50 -> V_181 -> V_237 , V_214 ) ;
if ( V_52 != 0 )
goto V_105;
V_52 = - V_129 ;
if ( F_103 ( V_50 , NULL , & V_209 , V_172 ) )
goto V_236;
}
V_105:
return F_45 ( V_52 ) ;
V_236:
F_74 ( & V_50 -> V_33 ) ;
return V_50 ;
}
static void
F_112 ( struct V_159 * V_132 , struct V_49 * V_50 )
{
struct V_47 * V_48 = F_69 ( V_50 -> V_51 ) -> V_47 ;
struct V_222 * V_223 ;
int V_238 = 0 ;
F_104 () ;
V_223 = F_105 ( F_61 ( V_50 -> V_51 ) -> V_223 ) ;
if ( V_223 )
V_238 = V_223 -> V_173 ;
F_107 () ;
if ( V_132 -> V_163 . V_203 == V_239 ) {
F_113 ( L_19
L_20
L_21 ,
V_48 -> V_83 ) ;
} else if ( ( V_238 & 1UL << V_224 ) == 0 )
F_114 ( V_50 -> V_51 ,
V_132 -> V_181 -> V_237 ,
& V_132 -> V_160 ) ;
else
F_115 ( V_50 -> V_51 ,
V_132 -> V_181 -> V_237 ,
& V_132 -> V_160 ) ;
}
static struct V_49 *
F_116 ( struct V_159 * V_132 )
{
struct V_51 * V_51 = V_132 -> V_50 -> V_51 ;
struct V_49 * V_50 = V_132 -> V_50 ;
int V_52 ;
if ( ! V_132 -> V_240 ) {
V_52 = V_132 -> V_241 ;
goto V_1;
}
V_52 = - V_242 ;
if ( ! ( V_132 -> V_161 . V_243 & V_244 ) ||
! ( V_132 -> V_161 . V_243 & V_245 ) ||
! ( V_132 -> V_161 . V_243 & V_246 ) )
goto V_1;
V_52 = - V_125 ;
V_50 = F_117 ( V_51 , V_132 -> V_181 ) ;
if ( V_50 == NULL )
goto V_1;
V_52 = F_118 ( V_51 , & V_132 -> V_161 ) ;
if ( V_52 )
goto V_1;
if ( V_132 -> V_160 . V_247 != 0 )
F_112 ( V_132 , V_50 ) ;
F_103 ( V_50 , & V_132 -> V_160 . V_209 , NULL ,
V_132 -> V_163 . V_172 ) ;
return V_50 ;
V_1:
return F_45 ( V_52 ) ;
}
static struct V_49 *
F_119 ( struct V_159 * V_132 )
{
struct V_51 * V_51 ;
struct V_49 * V_50 = NULL ;
int V_52 ;
if ( ! V_132 -> V_240 ) {
V_50 = F_109 ( V_132 ) ;
goto V_105;
}
V_52 = - V_129 ;
if ( ! ( V_132 -> V_161 . V_243 & V_248 ) )
goto V_1;
V_51 = F_120 ( V_132 -> V_146 -> V_180 , & V_132 -> V_160 . V_183 , & V_132 -> V_161 ) ;
V_52 = F_55 ( V_51 ) ;
if ( F_44 ( V_51 ) )
goto V_1;
V_52 = - V_125 ;
V_50 = F_117 ( V_51 , V_132 -> V_181 ) ;
if ( V_50 == NULL )
goto V_249;
if ( V_132 -> V_160 . V_247 != 0 )
F_112 ( V_132 , V_50 ) ;
F_103 ( V_50 , & V_132 -> V_160 . V_209 , NULL ,
V_132 -> V_163 . V_172 ) ;
F_121 ( V_51 ) ;
V_105:
F_110 ( V_132 -> V_163 . V_162 ) ;
return V_50 ;
V_249:
F_121 ( V_51 ) ;
V_1:
return F_45 ( V_52 ) ;
}
static struct V_49 *
F_122 ( struct V_159 * V_132 )
{
if ( V_132 -> V_163 . V_203 == V_250 )
return F_116 ( V_132 ) ;
return F_119 ( V_132 ) ;
}
static struct V_251 * F_123 ( struct V_49 * V_50 )
{
struct V_149 * V_150 = F_61 ( V_50 -> V_51 ) ;
struct V_251 * V_252 ;
F_24 ( & V_50 -> V_51 -> V_151 ) ;
F_124 (ctx, &nfsi->open_files, list) {
if ( V_252 -> V_50 != V_50 )
continue;
F_125 ( V_252 ) ;
F_26 ( & V_50 -> V_51 -> V_151 ) ;
return V_252 ;
}
F_26 ( & V_50 -> V_51 -> V_151 ) ;
return F_45 ( - V_253 ) ;
}
static struct V_159 * F_126 ( struct V_251 * V_252 , struct V_49 * V_50 )
{
struct V_159 * V_235 ;
V_235 = F_67 ( V_252 -> V_20 , V_50 -> V_181 , 0 , 0 , NULL , V_254 ) ;
if ( V_235 == NULL )
return F_45 ( - V_125 ) ;
V_235 -> V_50 = V_50 ;
F_74 ( & V_50 -> V_33 ) ;
return V_235 ;
}
static int F_127 ( struct V_159 * V_235 , T_3 V_172 , struct V_49 * * V_37 )
{
struct V_49 * V_255 ;
int V_52 ;
V_235 -> V_163 . V_184 = 0 ;
V_235 -> V_163 . V_172 = V_172 ;
memset ( & V_235 -> V_160 , 0 , sizeof( V_235 -> V_160 ) ) ;
memset ( & V_235 -> V_164 , 0 , sizeof( V_235 -> V_164 ) ) ;
F_64 ( V_235 ) ;
V_52 = F_128 ( V_235 ) ;
if ( V_52 != 0 )
return V_52 ;
V_255 = F_122 ( V_235 ) ;
if ( F_44 ( V_255 ) )
return F_55 ( V_255 ) ;
F_129 ( V_255 , V_172 ) ;
* V_37 = V_255 ;
return 0 ;
}
static int F_130 ( struct V_159 * V_235 , struct V_49 * V_50 )
{
struct V_49 * V_255 ;
int V_52 ;
F_131 ( V_226 , & V_50 -> V_173 ) ;
F_132 () ;
if ( V_50 -> V_221 != 0 ) {
F_131 ( V_220 , & V_50 -> V_173 ) ;
V_52 = F_127 ( V_235 , V_55 | V_185 , & V_255 ) ;
if ( V_52 != 0 )
return V_52 ;
if ( V_255 != V_50 )
return - V_242 ;
}
if ( V_50 -> V_219 != 0 ) {
F_131 ( V_218 , & V_50 -> V_173 ) ;
V_52 = F_127 ( V_235 , V_185 , & V_255 ) ;
if ( V_52 != 0 )
return V_52 ;
if ( V_255 != V_50 )
return - V_242 ;
}
if ( V_50 -> V_217 != 0 ) {
F_131 ( V_216 , & V_50 -> V_173 ) ;
V_52 = F_127 ( V_235 , V_55 , & V_255 ) ;
if ( V_52 != 0 )
return V_52 ;
if ( V_255 != V_50 )
return - V_242 ;
}
if ( F_42 ( V_226 , & V_50 -> V_173 ) == 0 &&
! F_106 ( & V_50 -> V_209 , & V_50 -> V_227 ) ) {
F_100 ( & V_50 -> V_228 ) ;
if ( F_42 ( V_226 , & V_50 -> V_173 ) == 0 )
F_97 ( & V_50 -> V_209 , & V_50 -> V_227 ) ;
F_101 ( & V_50 -> V_228 ) ;
}
return 0 ;
}
static int F_133 ( struct V_251 * V_252 , struct V_49 * V_50 )
{
struct V_222 * V_223 ;
struct V_159 * V_235 ;
T_3 V_247 = 0 ;
int V_256 ;
V_235 = F_126 ( V_252 , V_50 ) ;
if ( F_44 ( V_235 ) )
return F_55 ( V_235 ) ;
V_235 -> V_163 . V_203 = V_250 ;
V_235 -> V_163 . V_183 = F_75 ( V_50 -> V_51 ) ;
F_104 () ;
V_223 = F_105 ( F_61 ( V_50 -> V_51 ) -> V_223 ) ;
if ( V_223 != NULL && F_42 ( V_224 , & V_223 -> V_173 ) != 0 )
V_247 = V_223 -> type ;
F_107 () ;
V_235 -> V_163 . V_207 . V_247 = V_247 ;
V_256 = F_130 ( V_235 , V_50 ) ;
F_87 ( V_235 ) ;
return V_256 ;
}
static int F_134 ( struct V_251 * V_252 , struct V_49 * V_50 )
{
struct V_42 * V_43 = F_69 ( V_50 -> V_51 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_133 ( V_252 , V_50 ) ;
if ( V_1 != - V_76 )
break;
F_13 ( V_43 , V_1 , & V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static int F_135 ( struct V_170 * V_171 , struct V_49 * V_50 )
{
struct V_251 * V_252 ;
int V_52 ;
V_252 = F_123 ( V_50 ) ;
if ( F_44 ( V_252 ) )
return F_55 ( V_252 ) ;
V_52 = F_134 ( V_252 , V_50 ) ;
F_136 ( V_252 ) ;
return V_52 ;
}
static int F_137 ( struct V_251 * V_252 , struct V_49 * V_50 , const T_5 * V_209 )
{
struct V_159 * V_235 ;
int V_52 ;
V_235 = F_126 ( V_252 , V_50 ) ;
if ( F_44 ( V_235 ) )
return F_55 ( V_235 ) ;
V_235 -> V_163 . V_203 = V_239 ;
F_97 ( & V_235 -> V_163 . V_207 . V_223 , V_209 ) ;
V_52 = F_130 ( V_235 , V_50 ) ;
F_87 ( V_235 ) ;
return V_52 ;
}
int F_138 ( struct V_251 * V_252 , struct V_49 * V_50 , const T_5 * V_209 )
{
struct V_45 V_46 = { } ;
struct V_42 * V_43 = F_69 ( V_50 -> V_51 ) ;
int V_1 ;
do {
V_1 = F_137 ( V_252 , V_50 , V_209 ) ;
switch ( V_1 ) {
case 0 :
case - V_253 :
case - V_242 :
goto V_105;
case - V_64 :
case - V_65 :
case - V_66 :
case - V_67 :
case - V_68 :
F_98 ( V_226 , & V_50 -> V_173 ) ;
F_20 ( V_43 -> V_47 -> V_71 , V_1 ) ;
V_1 = - V_129 ;
goto V_105;
case - V_62 :
case - V_61 :
F_98 ( V_226 , & V_50 -> V_173 ) ;
case - V_60 :
F_18 ( V_43 -> V_47 ) ;
V_1 = - V_129 ;
goto V_105;
case - V_57 :
case - V_58 :
case - V_59 :
F_139 ( V_50 -> V_51 ,
V_209 ) ;
F_16 ( V_43 , V_50 ) ;
case - V_125 :
V_1 = 0 ;
goto V_105;
}
F_98 ( V_226 , & V_50 -> V_173 ) ;
V_1 = F_13 ( V_43 , V_1 , & V_46 ) ;
} while ( V_46 . V_53 );
V_105:
return V_1 ;
}
static void F_140 ( struct V_100 * V_101 , void * V_130 )
{
struct V_159 * V_132 = V_130 ;
V_132 -> V_241 = V_101 -> V_113 ;
if ( V_132 -> V_241 == 0 ) {
F_97 ( & V_132 -> V_160 . V_209 , & V_132 -> V_164 . V_209 ) ;
F_141 ( & V_132 -> V_181 -> V_178 , 0 ) ;
F_27 ( V_132 -> V_160 . V_43 , V_132 -> V_84 ) ;
V_132 -> V_240 = 1 ;
}
}
static void F_142 ( void * V_130 )
{
struct V_159 * V_132 = V_130 ;
struct V_49 * V_50 = NULL ;
if ( V_132 -> V_257 == 0 )
goto V_258;
if ( ! V_132 -> V_240 )
goto V_258;
V_50 = F_122 ( V_132 ) ;
if ( ! F_44 ( V_50 ) )
F_129 ( V_50 , V_132 -> V_163 . V_172 ) ;
V_258:
F_87 ( V_132 ) ;
}
static int F_143 ( struct V_159 * V_132 )
{
struct V_42 * V_43 = F_69 ( V_132 -> V_146 -> V_29 ) ;
struct V_100 * V_101 ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_261 ] ,
. V_262 = & V_132 -> V_165 ,
. V_263 = & V_132 -> V_164 ,
. V_264 = V_132 -> V_181 -> V_237 ,
} ;
struct V_138 V_265 = {
. V_140 = V_43 -> V_77 ,
. V_136 = & V_137 ,
. V_141 = & V_266 ,
. V_143 = V_132 ,
. V_267 = V_268 ,
. V_173 = V_269 ,
} ;
int V_256 ;
F_144 ( & V_132 -> V_210 ) ;
V_132 -> V_240 = 0 ;
V_132 -> V_241 = 0 ;
V_132 -> V_84 = V_126 ;
V_101 = F_54 ( & V_265 ) ;
if ( F_44 ( V_101 ) )
return F_55 ( V_101 ) ;
V_256 = F_89 ( V_101 ) ;
if ( V_256 != 0 ) {
V_132 -> V_257 = 1 ;
F_145 () ;
} else
V_256 = V_132 -> V_241 ;
F_56 ( V_101 ) ;
return V_256 ;
}
static void F_146 ( struct V_100 * V_101 , void * V_130 )
{
struct V_159 * V_132 = V_130 ;
struct V_170 * V_171 = V_132 -> V_181 ;
if ( F_147 ( V_132 -> V_163 . V_162 , V_101 ) != 0 )
goto V_270;
if ( V_132 -> V_50 != NULL ) {
struct V_222 * V_223 ;
if ( F_91 ( V_132 -> V_50 , V_132 -> V_163 . V_172 , V_132 -> V_163 . V_184 ) )
goto V_271;
F_104 () ;
V_223 = F_105 ( F_61 ( V_132 -> V_50 -> V_51 ) -> V_223 ) ;
if ( V_132 -> V_163 . V_203 != V_239 &&
F_92 ( V_223 , V_132 -> V_163 . V_172 ) )
goto V_272;
F_107 () ;
}
V_132 -> V_163 . V_191 = V_171 -> V_273 -> V_47 -> V_192 ;
if ( V_132 -> V_163 . V_203 == V_250 ) {
V_101 -> V_274 . V_259 = & V_260 [ V_275 ] ;
V_132 -> V_163 . V_201 = & V_276 [ 0 ] ;
F_148 ( & V_132 -> V_160 . V_183 , V_132 -> V_163 . V_183 ) ;
}
V_132 -> V_84 = V_126 ;
if ( F_49 ( V_132 -> V_163 . V_43 ,
& V_132 -> V_163 . V_134 ,
& V_132 -> V_160 . V_135 ,
V_101 ) != 0 )
F_110 ( V_132 -> V_163 . V_162 ) ;
return;
V_272:
F_107 () ;
V_271:
V_101 -> V_277 = NULL ;
V_270:
F_38 ( V_101 , & V_132 -> V_160 . V_135 ) ;
}
static void F_149 ( struct V_100 * V_101 , void * V_130 )
{
struct V_159 * V_132 = V_130 ;
V_132 -> V_241 = V_101 -> V_113 ;
if ( ! F_38 ( V_101 , & V_132 -> V_160 . V_135 ) )
return;
if ( V_101 -> V_113 == 0 ) {
if ( V_132 -> V_160 . V_161 -> V_243 & V_244 ) {
switch ( V_132 -> V_160 . V_161 -> V_213 & V_278 ) {
case V_279 :
break;
case V_280 :
V_132 -> V_241 = - V_281 ;
break;
case V_282 :
V_132 -> V_241 = - V_283 ;
break;
default:
V_132 -> V_241 = - V_284 ;
}
}
F_27 ( V_132 -> V_160 . V_43 , V_132 -> V_84 ) ;
if ( ! ( V_132 -> V_160 . V_285 & V_286 ) )
F_141 ( & V_132 -> V_181 -> V_178 , 0 ) ;
}
V_132 -> V_240 = 1 ;
}
static void F_150 ( void * V_130 )
{
struct V_159 * V_132 = V_130 ;
struct V_49 * V_50 = NULL ;
if ( V_132 -> V_257 == 0 )
goto V_258;
if ( V_132 -> V_241 != 0 || ! V_132 -> V_240 )
goto V_258;
if ( V_132 -> V_160 . V_285 & V_286 )
goto V_258;
V_50 = F_122 ( V_132 ) ;
if ( ! F_44 ( V_50 ) )
F_129 ( V_50 , V_132 -> V_163 . V_172 ) ;
V_258:
F_87 ( V_132 ) ;
}
static int F_151 ( struct V_159 * V_132 , int V_287 )
{
struct V_51 * V_146 = V_132 -> V_146 -> V_29 ;
struct V_42 * V_43 = F_69 ( V_146 ) ;
struct V_288 * V_163 = & V_132 -> V_163 ;
struct V_289 * V_160 = & V_132 -> V_160 ;
struct V_100 * V_101 ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_290 ] ,
. V_262 = V_163 ,
. V_263 = V_160 ,
. V_264 = V_132 -> V_181 -> V_237 ,
} ;
struct V_138 V_265 = {
. V_140 = V_43 -> V_77 ,
. V_136 = & V_137 ,
. V_141 = & V_291 ,
. V_143 = V_132 ,
. V_267 = V_268 ,
. V_173 = V_269 ,
} ;
int V_256 ;
F_39 ( & V_163 -> V_134 , & V_160 -> V_135 , 1 ) ;
F_144 ( & V_132 -> V_210 ) ;
V_132 -> V_240 = 0 ;
V_132 -> V_241 = 0 ;
V_132 -> V_257 = 0 ;
if ( V_287 )
F_40 ( & V_163 -> V_134 ) ;
V_101 = F_54 ( & V_265 ) ;
if ( F_44 ( V_101 ) )
return F_55 ( V_101 ) ;
V_256 = F_89 ( V_101 ) ;
if ( V_256 != 0 ) {
V_132 -> V_257 = 1 ;
F_145 () ;
} else
V_256 = V_132 -> V_241 ;
F_56 ( V_101 ) ;
return V_256 ;
}
static int F_128 ( struct V_159 * V_132 )
{
struct V_51 * V_146 = V_132 -> V_146 -> V_29 ;
struct V_289 * V_160 = & V_132 -> V_160 ;
int V_256 ;
V_256 = F_151 ( V_132 , 1 ) ;
if ( V_256 != 0 || ! V_132 -> V_240 )
return V_256 ;
F_152 ( F_69 ( V_146 ) , & V_132 -> V_161 ) ;
if ( V_160 -> V_285 & V_286 ) {
V_256 = F_143 ( V_132 ) ;
if ( V_256 != 0 )
return V_256 ;
}
return V_256 ;
}
static int F_153 ( struct V_264 * V_292 ,
struct V_159 * V_235 ,
struct V_49 * V_50 , T_3 V_172 ,
int V_293 )
{
struct V_294 V_295 ;
T_6 V_296 ;
if ( V_235 -> V_160 . V_297 == 0 )
return 0 ;
V_296 = 0 ;
if ( V_293 & V_298 ) {
V_296 = V_299 ;
} else if ( V_172 & V_55 )
V_296 = V_300 ;
V_295 . V_292 = V_292 ;
V_295 . V_126 = V_126 ;
F_154 ( & V_295 , V_235 -> V_160 . V_301 ) ;
F_155 ( V_50 -> V_51 , & V_295 ) ;
if ( ( V_296 & ~ V_295 . V_296 & ( V_300 | V_299 ) ) == 0 )
return 0 ;
F_129 ( V_50 , V_172 ) ;
return - V_12 ;
}
static int F_156 ( struct V_159 * V_132 )
{
struct V_51 * V_146 = V_132 -> V_146 -> V_29 ;
struct V_42 * V_43 = F_69 ( V_146 ) ;
struct V_288 * V_163 = & V_132 -> V_163 ;
struct V_289 * V_160 = & V_132 -> V_160 ;
int V_256 ;
V_256 = F_151 ( V_132 , 0 ) ;
if ( ! V_132 -> V_240 )
return V_256 ;
if ( V_256 != 0 ) {
if ( V_256 == - V_9 &&
! ( V_163 -> V_184 & V_302 ) )
return - V_253 ;
return V_256 ;
}
F_152 ( V_43 , & V_132 -> V_161 ) ;
if ( V_163 -> V_184 & V_302 )
F_60 ( V_146 , & V_160 -> V_148 ) ;
if ( ( V_160 -> V_285 & V_303 ) == 0 )
V_43 -> V_80 &= ~ V_304 ;
if( V_160 -> V_285 & V_286 ) {
V_256 = F_143 ( V_132 ) ;
if ( V_256 != 0 )
return V_256 ;
}
if ( ! ( V_160 -> V_161 -> V_243 & V_248 ) )
F_157 ( V_43 , & V_160 -> V_183 , V_160 -> V_161 ) ;
return 0 ;
}
static int F_158 ( struct V_42 * V_43 )
{
return F_159 ( V_43 -> V_47 ) ;
}
static int F_160 ( struct V_251 * V_252 , struct V_49 * V_50 )
{
struct V_159 * V_235 ;
int V_52 ;
V_235 = F_126 ( V_252 , V_50 ) ;
if ( F_44 ( V_235 ) )
return F_55 ( V_235 ) ;
V_52 = F_130 ( V_235 , V_50 ) ;
if ( V_52 == - V_242 )
F_161 ( V_252 -> V_20 ) ;
F_87 ( V_235 ) ;
return V_52 ;
}
static int F_162 ( struct V_251 * V_252 , struct V_49 * V_50 )
{
struct V_42 * V_43 = F_69 ( V_50 -> V_51 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_160 ( V_252 , V_50 ) ;
switch ( V_1 ) {
default:
goto V_105;
case - V_75 :
case - V_76 :
F_13 ( V_43 , V_1 , & V_46 ) ;
V_1 = 0 ;
}
} while ( V_46 . V_53 );
V_105:
return V_1 ;
}
static int F_163 ( struct V_170 * V_171 , struct V_49 * V_50 )
{
struct V_251 * V_252 ;
int V_52 ;
V_252 = F_123 ( V_50 ) ;
if ( F_44 ( V_252 ) )
return F_55 ( V_252 ) ;
V_52 = F_162 ( V_252 , V_50 ) ;
F_136 ( V_252 ) ;
return V_52 ;
}
static void F_164 ( struct V_49 * V_50 )
{
struct V_42 * V_43 = F_69 ( V_50 -> V_51 ) ;
T_5 * V_209 = & V_50 -> V_209 ;
int V_256 ;
if ( F_42 ( V_226 , & V_50 -> V_173 ) == 0 )
return;
V_256 = F_165 ( V_43 , V_209 ) ;
if ( V_256 != V_305 ) {
if ( V_256 != - V_59 )
F_166 ( V_43 , V_209 ) ;
F_17 ( V_50 -> V_51 ) ;
F_100 ( & V_50 -> V_228 ) ;
F_97 ( & V_50 -> V_209 , & V_50 -> V_227 ) ;
F_101 ( & V_50 -> V_228 ) ;
F_131 ( V_226 , & V_50 -> V_173 ) ;
}
}
static int F_167 ( struct V_49 * V_50 )
{
struct V_42 * V_43 = F_69 ( V_50 -> V_51 ) ;
T_5 * V_209 = & V_50 -> V_227 ;
int V_256 ;
if ( ( F_42 ( V_216 , & V_50 -> V_173 ) == 0 ) &&
( F_42 ( V_218 , & V_50 -> V_173 ) == 0 ) &&
( F_42 ( V_220 , & V_50 -> V_173 ) == 0 ) )
return - V_59 ;
V_256 = F_165 ( V_43 , V_209 ) ;
if ( V_256 != V_305 ) {
if ( V_256 != - V_59 )
F_166 ( V_43 , V_209 ) ;
F_131 ( V_216 , & V_50 -> V_173 ) ;
F_131 ( V_218 , & V_50 -> V_173 ) ;
F_131 ( V_220 , & V_50 -> V_173 ) ;
}
return V_256 ;
}
static int F_168 ( struct V_170 * V_171 , struct V_49 * V_50 )
{
int V_256 ;
F_164 ( V_50 ) ;
V_256 = F_167 ( V_50 ) ;
if ( V_256 != V_305 )
V_256 = F_163 ( V_171 , V_50 ) ;
return V_256 ;
}
static inline void F_169 ( struct V_159 * V_235 , struct V_174 * V_306 )
{
if ( ( V_235 -> V_160 . V_307 [ 1 ] & V_308 ) &&
! ( V_306 -> V_205 & V_309 ) )
V_306 -> V_205 |= V_310 ;
if ( ( V_235 -> V_160 . V_307 [ 1 ] & V_311 ) &&
! ( V_306 -> V_205 & V_312 ) )
V_306 -> V_205 |= V_313 ;
}
static int F_170 ( struct V_159 * V_235 ,
T_3 V_172 ,
int V_173 ,
struct V_49 * * V_37 )
{
struct V_170 * V_171 = V_235 -> V_181 ;
struct V_42 * V_43 = V_171 -> V_273 ;
struct V_49 * V_50 ;
unsigned int V_314 ;
int V_52 ;
V_314 = F_171 ( & V_171 -> V_315 ) ;
V_52 = F_156 ( V_235 ) ;
if ( V_52 != 0 )
goto V_105;
V_50 = F_122 ( V_235 ) ;
V_52 = F_55 ( V_50 ) ;
if ( F_44 ( V_50 ) )
goto V_105;
if ( V_43 -> V_80 & V_304 )
F_98 ( V_316 , & V_50 -> V_173 ) ;
V_52 = F_153 ( V_171 -> V_237 , V_235 , V_50 , V_172 , V_173 ) ;
if ( V_52 != 0 )
goto V_105;
if ( F_172 ( & V_171 -> V_315 , V_314 ) ) {
F_16 ( V_43 , V_50 ) ;
F_22 ( V_43 -> V_47 ) ;
}
* V_37 = V_50 ;
V_105:
return V_52 ;
}
static int F_173 ( struct V_51 * V_146 ,
struct V_20 * V_20 ,
T_3 V_172 ,
int V_173 ,
struct V_174 * V_306 ,
struct V_264 * V_292 ,
struct V_49 * * V_37 ,
struct V_317 * * V_318 )
{
struct V_170 * V_171 ;
struct V_49 * V_50 = NULL ;
struct V_42 * V_43 = F_69 ( V_146 ) ;
struct V_159 * V_235 ;
int V_256 ;
V_256 = - V_125 ;
V_171 = F_174 ( V_43 , V_292 , V_319 ) ;
if ( V_171 == NULL ) {
F_2 ( L_22 ) ;
goto V_320;
}
V_256 = F_158 ( V_43 ) ;
if ( V_256 != 0 )
goto V_321;
if ( V_20 -> V_29 != NULL )
F_108 ( V_20 -> V_29 , V_172 ) ;
V_256 = - V_125 ;
V_235 = F_67 ( V_20 , V_171 , V_172 , V_173 , V_306 , V_319 ) ;
if ( V_235 == NULL )
goto V_321;
if ( V_318 && V_43 -> V_200 [ 2 ] & V_322 ) {
V_235 -> V_161 . V_323 = F_175 () ;
if ( ! V_235 -> V_161 . V_323 )
goto V_324;
V_235 -> V_163 . V_201 = & V_325 [ 0 ] ;
}
if ( V_20 -> V_29 != NULL )
V_235 -> V_50 = F_117 ( V_20 -> V_29 , V_171 ) ;
V_256 = F_170 ( V_235 , V_172 , V_173 , & V_50 ) ;
if ( V_256 != 0 )
goto V_324;
if ( V_235 -> V_163 . V_184 & V_186 ) {
F_169 ( V_235 , V_306 ) ;
F_65 ( V_235 -> V_160 . V_161 ) ;
V_256 = F_176 ( V_50 -> V_51 , V_292 ,
V_235 -> V_160 . V_161 , V_306 ,
V_50 ) ;
if ( V_256 == 0 )
F_177 ( V_50 -> V_51 , V_306 ) ;
F_178 ( V_50 -> V_51 , V_235 -> V_160 . V_161 ) ;
}
if ( F_179 ( V_318 , V_235 -> V_161 . V_323 , V_43 ) )
* V_318 = V_235 -> V_161 . V_323 ;
else
F_78 ( V_235 -> V_161 . V_323 ) ;
V_235 -> V_161 . V_323 = NULL ;
F_87 ( V_235 ) ;
F_84 ( V_171 ) ;
* V_37 = V_50 ;
return 0 ;
V_324:
F_78 ( V_235 -> V_161 . V_323 ) ;
F_87 ( V_235 ) ;
V_321:
F_84 ( V_171 ) ;
V_320:
* V_37 = NULL ;
return V_256 ;
}
static struct V_49 * F_180 ( struct V_51 * V_146 ,
struct V_20 * V_20 ,
T_3 V_172 ,
int V_173 ,
struct V_174 * V_306 ,
struct V_264 * V_292 ,
struct V_317 * * V_318 )
{
struct V_45 V_46 = { } ;
struct V_49 * V_37 ;
int V_256 ;
V_172 &= V_55 | V_185 | V_326 ;
do {
V_256 = F_173 ( V_146 , V_20 , V_172 , V_173 , V_306 , V_292 ,
& V_37 , V_318 ) ;
if ( V_256 == 0 )
break;
if ( V_256 == - V_327 ) {
F_181 ( L_5
L_23 ,
F_69 ( V_146 ) -> V_47 -> V_83 ) ;
V_46 . V_53 = 1 ;
continue;
}
if ( V_256 == - V_59 ) {
V_46 . V_53 = 1 ;
continue;
}
if ( V_256 == - V_129 ) {
V_46 . V_53 = 1 ;
continue;
}
V_37 = F_45 ( F_13 ( F_69 ( V_146 ) ,
V_256 , & V_46 ) ) ;
} while ( V_46 . V_53 );
return V_37 ;
}
static int F_182 ( struct V_51 * V_51 , struct V_264 * V_292 ,
struct V_328 * V_329 , struct V_174 * V_306 ,
struct V_49 * V_50 )
{
struct V_42 * V_43 = F_69 ( V_51 ) ;
struct V_330 V_331 = {
. V_183 = F_75 ( V_51 ) ,
. V_332 = V_306 ,
. V_43 = V_43 ,
. V_199 = V_43 -> V_200 ,
} ;
struct V_333 V_37 = {
. V_329 = V_329 ,
. V_43 = V_43 ,
} ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_334 ] ,
. V_262 = & V_331 ,
. V_263 = & V_37 ,
. V_264 = V_292 ,
} ;
unsigned long V_84 = V_126 ;
int V_256 ;
F_65 ( V_329 ) ;
if ( V_50 != NULL ) {
struct V_335 V_336 = {
. V_337 = V_40 -> V_338 ,
. V_339 = V_40 -> V_340 ,
} ;
F_183 ( & V_331 . V_209 , V_50 , V_185 ,
& V_336 ) ;
} else if ( F_184 ( & V_331 . V_209 , V_51 ,
V_185 ) ) {
} else
F_97 ( & V_331 . V_209 , & V_341 ) ;
V_256 = F_59 ( V_43 -> V_77 , V_43 , & V_137 , & V_331 . V_134 , & V_37 . V_135 , 1 ) ;
if ( V_256 == 0 && V_50 != NULL )
F_27 ( V_43 , V_84 ) ;
return V_256 ;
}
static int F_176 ( struct V_51 * V_51 , struct V_264 * V_292 ,
struct V_328 * V_329 , struct V_174 * V_306 ,
struct V_49 * V_50 )
{
struct V_42 * V_43 = F_69 ( V_51 ) ;
struct V_45 V_46 = {
. V_50 = V_50 ,
. V_51 = V_51 ,
} ;
int V_1 ;
do {
V_1 = F_182 ( V_51 , V_292 , V_329 , V_306 , V_50 ) ;
switch ( V_1 ) {
case - V_54 :
if ( V_50 && ! ( V_50 -> V_50 & V_185 ) ) {
V_1 = - V_342 ;
if ( V_306 -> V_205 & V_343 )
V_1 = - V_12 ;
goto V_105;
}
}
V_1 = F_13 ( V_43 , V_1 , & V_46 ) ;
} while ( V_46 . V_53 );
V_105:
return V_1 ;
}
static void F_185 ( void * V_132 )
{
struct V_344 * V_130 = V_132 ;
struct V_170 * V_171 = V_130 -> V_50 -> V_181 ;
struct V_211 * V_212 = V_130 -> V_50 -> V_51 -> V_345 ;
if ( V_130 -> V_346 )
F_186 ( V_130 -> V_50 -> V_51 ) ;
F_83 ( V_130 -> V_50 ) ;
F_82 ( V_130 -> V_331 . V_162 ) ;
F_84 ( V_171 ) ;
F_85 ( V_212 ) ;
F_78 ( V_130 ) ;
}
static void F_187 ( struct V_49 * V_50 ,
T_3 V_172 )
{
F_24 ( & V_50 -> V_181 -> V_230 ) ;
if ( ! ( V_172 & V_55 ) )
F_131 ( V_216 , & V_50 -> V_173 ) ;
if ( ! ( V_172 & V_185 ) )
F_131 ( V_218 , & V_50 -> V_173 ) ;
F_131 ( V_220 , & V_50 -> V_173 ) ;
F_26 ( & V_50 -> V_181 -> V_230 ) ;
}
static void F_188 ( struct V_100 * V_101 , void * V_132 )
{
struct V_344 * V_130 = V_132 ;
struct V_49 * V_50 = V_130 -> V_50 ;
struct V_42 * V_43 = F_69 ( V_130 -> V_51 ) ;
F_2 ( L_24 , V_16 ) ;
if ( ! F_38 ( V_101 , & V_130 -> V_37 . V_135 ) )
return;
switch ( V_101 -> V_113 ) {
case 0 :
if ( V_130 -> V_346 )
F_189 ( V_50 -> V_51 ,
V_130 -> V_347 ) ;
F_99 ( V_50 , & V_130 -> V_37 . V_209 , 0 ) ;
F_27 ( V_43 , V_130 -> V_84 ) ;
F_187 ( V_50 ,
V_130 -> V_331 . V_172 ) ;
break;
case - V_61 :
case - V_79 :
case - V_59 :
case - V_60 :
if ( V_130 -> V_331 . V_172 == 0 )
break;
default:
if ( F_190 ( V_101 , V_43 , V_50 ) == - V_129 )
F_35 ( V_101 ) ;
}
F_110 ( V_130 -> V_331 . V_162 ) ;
F_118 ( V_130 -> V_51 , V_130 -> V_37 . V_329 ) ;
F_2 ( L_25 , V_16 , V_101 -> V_113 ) ;
}
static void F_191 ( struct V_100 * V_101 , void * V_132 )
{
struct V_344 * V_130 = V_132 ;
struct V_49 * V_50 = V_130 -> V_50 ;
struct V_51 * V_51 = V_130 -> V_51 ;
int V_348 = 0 ;
F_2 ( L_24 , V_16 ) ;
if ( F_147 ( V_130 -> V_331 . V_162 , V_101 ) != 0 )
goto V_270;
V_101 -> V_274 . V_259 = & V_260 [ V_349 ] ;
V_130 -> V_331 . V_172 = V_55 | V_185 ;
F_24 ( & V_50 -> V_181 -> V_230 ) ;
if ( V_50 -> V_221 == 0 ) {
if ( V_50 -> V_217 == 0 ) {
V_348 |= F_42 ( V_216 , & V_50 -> V_173 ) ;
V_348 |= F_42 ( V_220 , & V_50 -> V_173 ) ;
V_130 -> V_331 . V_172 &= ~ V_55 ;
}
if ( V_50 -> V_219 == 0 ) {
V_348 |= F_42 ( V_218 , & V_50 -> V_173 ) ;
V_348 |= F_42 ( V_220 , & V_50 -> V_173 ) ;
V_130 -> V_331 . V_172 &= ~ V_185 ;
}
}
F_26 ( & V_50 -> V_181 -> V_230 ) ;
if ( ! V_348 ) {
goto V_271;
}
if ( V_130 -> V_331 . V_172 == 0 ) {
V_101 -> V_274 . V_259 = & V_260 [ V_350 ] ;
if ( V_130 -> V_346 &&
F_192 ( V_51 , & V_130 -> V_347 , V_101 ) )
goto V_270;
}
F_65 ( V_130 -> V_37 . V_329 ) ;
V_130 -> V_84 = V_126 ;
if ( F_49 ( F_69 ( V_51 ) ,
& V_130 -> V_331 . V_134 ,
& V_130 -> V_37 . V_135 ,
V_101 ) != 0 )
F_110 ( V_130 -> V_331 . V_162 ) ;
F_2 ( L_26 , V_16 ) ;
return;
V_271:
V_101 -> V_277 = NULL ;
V_270:
F_38 ( V_101 , & V_130 -> V_37 . V_135 ) ;
}
int F_193 ( struct V_49 * V_50 , T_4 V_176 , int V_351 )
{
struct V_42 * V_43 = F_69 ( V_50 -> V_51 ) ;
struct V_344 * V_130 ;
struct V_170 * V_171 = V_50 -> V_181 ;
struct V_100 * V_101 ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_350 ] ,
. V_264 = V_50 -> V_181 -> V_237 ,
} ;
struct V_138 V_265 = {
. V_140 = V_43 -> V_77 ,
. V_136 = & V_137 ,
. V_141 = & V_352 ,
. V_267 = V_268 ,
. V_173 = V_269 ,
} ;
int V_256 = - V_125 ;
V_130 = F_70 ( sizeof( * V_130 ) , V_176 ) ;
if ( V_130 == NULL )
goto V_105;
F_39 ( & V_130 -> V_331 . V_134 , & V_130 -> V_37 . V_135 , 1 ) ;
V_130 -> V_51 = V_50 -> V_51 ;
V_130 -> V_50 = V_50 ;
V_130 -> V_331 . V_183 = F_75 ( V_50 -> V_51 ) ;
V_130 -> V_331 . V_209 = & V_50 -> V_227 ;
V_130 -> V_331 . V_162 = F_71 ( & V_50 -> V_181 -> V_178 , V_176 ) ;
if ( V_130 -> V_331 . V_162 == NULL )
goto V_353;
V_130 -> V_331 . V_172 = 0 ;
V_130 -> V_331 . V_199 = V_43 -> V_354 ;
V_130 -> V_37 . V_329 = & V_130 -> V_329 ;
V_130 -> V_37 . V_162 = V_130 -> V_331 . V_162 ;
V_130 -> V_37 . V_43 = V_43 ;
V_130 -> V_346 = F_194 ( V_50 -> V_51 ) ;
F_72 ( V_130 -> V_51 -> V_345 ) ;
V_137 . V_262 = & V_130 -> V_331 ;
V_137 . V_263 = & V_130 -> V_37 ;
V_265 . V_143 = V_130 ;
V_101 = F_54 ( & V_265 ) ;
if ( F_44 ( V_101 ) )
return F_55 ( V_101 ) ;
V_256 = 0 ;
if ( V_351 )
V_256 = F_90 ( V_101 ) ;
F_56 ( V_101 ) ;
return V_256 ;
V_353:
F_78 ( V_130 ) ;
V_105:
F_83 ( V_50 ) ;
F_84 ( V_171 ) ;
return V_256 ;
}
static struct V_51 *
F_195 ( struct V_51 * V_146 , struct V_251 * V_252 , int V_184 , struct V_174 * V_355 )
{
struct V_49 * V_50 ;
V_50 = F_180 ( V_146 , V_252 -> V_20 , V_252 -> V_213 , V_184 , V_355 ,
V_252 -> V_292 , & V_252 -> V_323 ) ;
if ( F_44 ( V_50 ) )
return F_196 ( V_50 ) ;
V_252 -> V_50 = V_50 ;
return F_197 ( V_50 -> V_51 ) ;
}
static void F_198 ( struct V_251 * V_252 , int V_356 )
{
if ( V_252 -> V_50 == NULL )
return;
if ( V_356 )
F_199 ( V_252 -> V_50 , V_252 -> V_213 ) ;
else
F_129 ( V_252 -> V_50 , V_252 -> V_213 ) ;
}
static int F_200 ( struct V_42 * V_43 , struct V_357 * V_358 )
{
struct V_359 args = {
. V_358 = V_358 ,
} ;
struct V_360 V_37 = {} ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_361 ] ,
. V_262 = & args ,
. V_263 = & V_37 ,
} ;
int V_256 ;
V_256 = F_59 ( V_43 -> V_77 , V_43 , & V_137 , & args . V_134 , & V_37 . V_135 , 0 ) ;
if ( V_256 == 0 ) {
memcpy ( V_43 -> V_200 , V_37 . V_200 , sizeof( V_43 -> V_200 ) ) ;
V_43 -> V_80 &= ~ ( V_362 | V_363 |
V_364 | V_365 |
V_366 | V_367 | V_368 |
V_369 | V_370 |
V_371 | V_372 ) ;
if ( V_37 . V_200 [ 0 ] & V_373 )
V_43 -> V_80 |= V_362 ;
if ( V_37 . V_374 != 0 )
V_43 -> V_80 |= V_363 ;
if ( V_37 . V_375 != 0 )
V_43 -> V_80 |= V_364 ;
if ( V_37 . V_200 [ 0 ] & V_28 )
V_43 -> V_80 |= V_365 ;
if ( V_37 . V_200 [ 1 ] & V_376 )
V_43 -> V_80 |= V_366 ;
if ( V_37 . V_200 [ 1 ] & V_377 )
V_43 -> V_80 |= V_367 ;
if ( V_37 . V_200 [ 1 ] & V_378 )
V_43 -> V_80 |= V_368 ;
if ( V_37 . V_200 [ 1 ] & V_379 )
V_43 -> V_80 |= V_369 ;
if ( V_37 . V_200 [ 1 ] & V_308 )
V_43 -> V_80 |= V_370 ;
if ( V_37 . V_200 [ 1 ] & V_380 )
V_43 -> V_80 |= V_371 ;
if ( V_37 . V_200 [ 1 ] & V_311 )
V_43 -> V_80 |= V_372 ;
memcpy ( V_43 -> V_354 , V_37 . V_200 , sizeof( V_43 -> V_354 ) ) ;
V_43 -> V_354 [ 0 ] &= V_381 | V_382 ;
V_43 -> V_354 [ 1 ] &= V_380 | V_311 ;
V_43 -> V_383 = V_37 . V_383 ;
V_43 -> V_384 = V_37 . V_384 ;
}
return V_256 ;
}
int F_201 ( struct V_42 * V_43 , struct V_357 * V_358 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_13 ( V_43 ,
F_200 ( V_43 , V_358 ) ,
& V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static int F_202 ( struct V_42 * V_43 , struct V_357 * V_358 ,
struct V_385 * V_386 )
{
struct V_387 args = {
. V_199 = V_202 ,
} ;
struct V_388 V_37 = {
. V_43 = V_43 ,
. V_329 = V_386 -> V_329 ,
. V_183 = V_358 ,
} ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_389 ] ,
. V_262 = & args ,
. V_263 = & V_37 ,
} ;
F_65 ( V_386 -> V_329 ) ;
return F_59 ( V_43 -> V_77 , V_43 , & V_137 , & args . V_134 , & V_37 . V_135 , 0 ) ;
}
static int F_203 ( struct V_42 * V_43 , struct V_357 * V_358 ,
struct V_385 * V_386 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_202 ( V_43 , V_358 , V_386 ) ;
switch ( V_1 ) {
case 0 :
case - V_6 :
goto V_105;
default:
V_1 = F_13 ( V_43 , V_1 , & V_46 ) ;
}
} while ( V_46 . V_53 );
V_105:
return V_1 ;
}
static int F_204 ( struct V_42 * V_43 , struct V_357 * V_358 ,
struct V_385 * V_386 , T_7 V_390 )
{
struct V_391 * V_392 ;
int V_52 ;
V_392 = F_205 ( V_390 , V_43 -> V_77 ) ;
if ( F_44 ( V_392 ) ) {
V_52 = - V_17 ;
goto V_105;
}
V_52 = F_203 ( V_43 , V_358 , V_386 ) ;
V_105:
return V_52 ;
}
static int F_206 ( struct V_42 * V_43 , struct V_357 * V_358 ,
struct V_385 * V_386 )
{
int V_393 , V_394 , V_256 = 0 ;
T_7 V_395 [ V_396 ] ;
V_394 = F_207 ( V_395 , F_208 ( V_395 ) ) ;
if ( V_394 < 0 )
return V_394 ;
for ( V_393 = 0 ; V_393 < V_394 ; V_393 ++ ) {
if ( V_395 [ V_393 ] == V_397 )
continue;
V_256 = F_204 ( V_43 , V_358 , V_386 , V_395 [ V_393 ] ) ;
if ( V_256 == - V_6 || V_256 == - V_12 )
continue;
break;
}
if ( V_256 == - V_12 )
V_256 = - V_7 ;
return V_256 ;
}
int F_209 ( struct V_42 * V_43 , struct V_357 * V_358 ,
struct V_385 * V_386 )
{
int V_398 = V_43 -> V_47 -> V_399 ;
int V_256 = F_203 ( V_43 , V_358 , V_386 ) ;
if ( ( V_256 == - V_6 ) && ! ( V_43 -> V_173 & V_400 ) )
V_256 = V_401 [ V_398 ] -> F_210 ( V_43 , V_358 , V_386 ) ;
if ( V_256 == 0 )
V_256 = F_201 ( V_43 , V_358 ) ;
if ( V_256 == 0 )
V_256 = F_211 ( V_43 , V_358 , V_386 ) ;
return F_1 ( V_256 ) ;
}
static int F_212 ( struct V_42 * V_43 , struct V_357 * V_402 ,
struct V_385 * V_386 )
{
int error ;
struct V_328 * V_329 = V_386 -> V_329 ;
error = F_201 ( V_43 , V_402 ) ;
if ( error < 0 ) {
F_2 ( L_27 , - error ) ;
return error ;
}
error = F_213 ( V_43 , V_402 , V_329 ) ;
if ( error < 0 ) {
F_2 ( L_28 , - error ) ;
return error ;
}
if ( V_329 -> V_243 & V_403 &&
! F_214 ( & V_43 -> V_404 , & V_329 -> V_404 ) )
memcpy ( & V_43 -> V_404 , & V_329 -> V_404 , sizeof( V_43 -> V_404 ) ) ;
return error ;
}
static int F_215 ( struct V_34 * V_77 , struct V_51 * V_146 ,
const struct V_405 * V_197 , struct V_328 * V_329 ,
struct V_357 * V_358 )
{
int V_256 = - V_125 ;
struct V_406 * V_406 = NULL ;
struct V_407 * V_408 = NULL ;
V_406 = F_216 ( V_319 ) ;
if ( V_406 == NULL )
goto V_105;
V_408 = F_217 ( sizeof( struct V_407 ) , V_319 ) ;
if ( V_408 == NULL )
goto V_105;
V_256 = F_218 ( V_77 , V_146 , V_197 , V_408 , V_406 ) ;
if ( V_256 != 0 )
goto V_105;
if ( F_214 ( & F_69 ( V_146 ) -> V_404 , & V_408 -> V_329 . V_404 ) ) {
F_2 ( L_29
L_30 , V_16 , V_197 -> V_197 ) ;
V_256 = - V_17 ;
goto V_105;
}
F_219 ( & V_408 -> V_329 ) ;
memcpy ( V_329 , & V_408 -> V_329 , sizeof( struct V_328 ) ) ;
memset ( V_358 , 0 , sizeof( struct V_357 ) ) ;
V_105:
if ( V_406 )
F_220 ( V_406 ) ;
F_78 ( V_408 ) ;
return V_256 ;
}
static int F_157 ( struct V_42 * V_43 , struct V_357 * V_358 , struct V_328 * V_329 )
{
struct V_409 args = {
. V_183 = V_358 ,
. V_199 = V_43 -> V_200 ,
} ;
struct V_410 V_37 = {
. V_329 = V_329 ,
. V_43 = V_43 ,
} ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_411 ] ,
. V_262 = & args ,
. V_263 = & V_37 ,
} ;
F_65 ( V_329 ) ;
return F_59 ( V_43 -> V_77 , V_43 , & V_137 , & args . V_134 , & V_37 . V_135 , 0 ) ;
}
static int F_213 ( struct V_42 * V_43 , struct V_357 * V_358 , struct V_328 * V_329 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_13 ( V_43 ,
F_157 ( V_43 , V_358 , V_329 ) ,
& V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static int
F_221 ( struct V_20 * V_20 , struct V_328 * V_329 ,
struct V_174 * V_306 )
{
struct V_51 * V_51 = V_20 -> V_29 ;
struct V_264 * V_292 = NULL ;
struct V_49 * V_50 = NULL ;
int V_256 ;
if ( F_222 ( V_51 ) )
F_223 ( V_51 ) ;
F_65 ( V_329 ) ;
if ( V_306 -> V_205 & V_343 )
V_306 -> V_205 &= ~ ( V_313 | V_412 | V_343 ) ;
if ( ( V_306 -> V_205 & ~ ( V_413 ) ) == 0 )
return 0 ;
if ( V_306 -> V_205 & V_413 ) {
struct V_251 * V_252 ;
V_252 = F_224 ( V_306 -> V_414 ) ;
if ( V_252 ) {
V_292 = V_252 -> V_292 ;
V_50 = V_252 -> V_50 ;
}
}
V_256 = F_176 ( V_51 , V_292 , V_329 , V_306 , V_50 ) ;
if ( V_256 == 0 )
F_177 ( V_51 , V_306 ) ;
return V_256 ;
}
static int F_225 ( struct V_34 * V_35 , struct V_51 * V_146 ,
const struct V_405 * V_197 , struct V_357 * V_358 ,
struct V_328 * V_329 )
{
struct V_42 * V_43 = F_69 ( V_146 ) ;
int V_256 ;
struct V_415 args = {
. V_199 = V_43 -> V_200 ,
. V_416 = F_75 ( V_146 ) ,
. V_197 = V_197 ,
} ;
struct V_388 V_37 = {
. V_43 = V_43 ,
. V_329 = V_329 ,
. V_183 = V_358 ,
} ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_417 ] ,
. V_262 = & args ,
. V_263 = & V_37 ,
} ;
F_65 ( V_329 ) ;
F_2 ( L_31 , V_197 -> V_197 ) ;
V_256 = F_59 ( V_35 , V_43 , & V_137 , & args . V_134 , & V_37 . V_135 , 0 ) ;
F_2 ( L_32 , V_256 ) ;
return V_256 ;
}
static void F_226 ( struct V_328 * V_329 )
{
V_329 -> V_243 |= V_244 | V_418 |
V_419 | V_420 ;
V_329 -> V_213 = V_282 | V_421 | V_422 ;
V_329 -> V_423 = 2 ;
}
static int F_227 ( struct V_34 * * V_35 , struct V_51 * V_146 ,
struct V_405 * V_197 , struct V_357 * V_358 ,
struct V_328 * V_329 )
{
struct V_45 V_46 = { } ;
struct V_34 * V_77 = * V_35 ;
int V_1 ;
do {
V_1 = F_225 ( V_77 , V_146 , V_197 , V_358 , V_329 ) ;
switch ( V_1 ) {
case - V_9 :
V_1 = - V_253 ;
goto V_105;
case - V_424 :
V_1 = F_215 ( V_77 , V_146 , V_197 , V_329 , V_358 ) ;
goto V_105;
case - V_6 :
V_1 = - V_7 ;
if ( V_77 != * V_35 )
goto V_105;
V_77 = F_228 ( V_77 , V_146 , V_197 ) ;
if ( F_44 ( V_77 ) )
return F_55 ( V_77 ) ;
V_46 . V_53 = 1 ;
break;
default:
V_1 = F_13 ( F_69 ( V_146 ) , V_1 , & V_46 ) ;
}
} while ( V_46 . V_53 );
V_105:
if ( V_1 == 0 )
* V_35 = V_77 ;
else if ( V_77 != * V_35 )
F_229 ( V_77 ) ;
return V_1 ;
}
static int F_230 ( struct V_51 * V_146 , struct V_405 * V_197 ,
struct V_357 * V_358 , struct V_328 * V_329 )
{
int V_256 ;
struct V_34 * V_77 = F_231 ( V_146 ) ;
V_256 = F_227 ( & V_77 , V_146 , V_197 , V_358 , V_329 ) ;
if ( V_77 != F_231 ( V_146 ) ) {
F_229 ( V_77 ) ;
F_226 ( V_329 ) ;
}
return V_256 ;
}
struct V_34 *
F_232 ( struct V_51 * V_146 , struct V_405 * V_197 ,
struct V_357 * V_358 , struct V_328 * V_329 )
{
int V_256 ;
struct V_34 * V_77 = F_233 ( F_231 ( V_146 ) ) ;
V_256 = F_227 ( & V_77 , V_146 , V_197 , V_358 , V_329 ) ;
if ( V_256 < 0 ) {
F_229 ( V_77 ) ;
return F_45 ( V_256 ) ;
}
return V_77 ;
}
static int F_234 ( struct V_51 * V_51 , struct V_294 * V_425 )
{
struct V_42 * V_43 = F_69 ( V_51 ) ;
struct V_426 args = {
. V_183 = F_75 ( V_51 ) ,
. V_199 = V_43 -> V_354 ,
} ;
struct V_427 V_37 = {
. V_43 = V_43 ,
} ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_428 ] ,
. V_262 = & args ,
. V_263 = & V_37 ,
. V_264 = V_425 -> V_292 ,
} ;
int V_213 = V_425 -> V_296 ;
int V_256 ;
if ( V_213 & V_300 )
args . V_167 |= V_187 ;
if ( F_235 ( V_51 -> V_429 ) ) {
if ( V_213 & V_430 )
args . V_167 |= V_188 | V_189 | V_431 ;
if ( V_213 & V_299 )
args . V_167 |= V_432 ;
} else {
if ( V_213 & V_430 )
args . V_167 |= V_188 | V_189 ;
if ( V_213 & V_299 )
args . V_167 |= V_190 ;
}
V_37 . V_329 = F_236 () ;
if ( V_37 . V_329 == NULL )
return - V_125 ;
V_256 = F_59 ( V_43 -> V_77 , V_43 , & V_137 , & args . V_134 , & V_37 . V_135 , 0 ) ;
if ( ! V_256 ) {
F_154 ( V_425 , V_37 . V_167 ) ;
F_118 ( V_51 , V_37 . V_329 ) ;
}
F_237 ( V_37 . V_329 ) ;
return V_256 ;
}
static int F_238 ( struct V_51 * V_51 , struct V_294 * V_425 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_69 ( V_51 ) ,
F_234 ( V_51 , V_425 ) ,
& V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static int F_239 ( struct V_51 * V_51 , struct V_406 * V_406 ,
unsigned int V_32 , unsigned int V_433 )
{
struct V_434 args = {
. V_183 = F_75 ( V_51 ) ,
. V_32 = V_32 ,
. V_433 = V_433 ,
. V_25 = & V_406 ,
} ;
struct V_435 V_37 ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_436 ] ,
. V_262 = & args ,
. V_263 = & V_37 ,
} ;
return F_59 ( F_69 ( V_51 ) -> V_77 , F_69 ( V_51 ) , & V_137 , & args . V_134 , & V_37 . V_135 , 0 ) ;
}
static int F_240 ( struct V_51 * V_51 , struct V_406 * V_406 ,
unsigned int V_32 , unsigned int V_433 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_69 ( V_51 ) ,
F_239 ( V_51 , V_406 , V_32 , V_433 ) ,
& V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static int
F_241 ( struct V_51 * V_146 , struct V_20 * V_20 , struct V_174 * V_306 ,
int V_173 )
{
struct V_251 * V_252 ;
struct V_49 * V_50 ;
int V_256 = 0 ;
V_252 = F_242 ( V_20 , V_55 ) ;
if ( F_44 ( V_252 ) )
return F_55 ( V_252 ) ;
V_306 -> V_437 &= ~ F_243 () ;
V_50 = F_180 ( V_146 , V_20 , V_252 -> V_213 ,
V_173 , V_306 , V_252 -> V_292 ,
& V_252 -> V_323 ) ;
F_161 ( V_20 ) ;
if ( F_44 ( V_50 ) ) {
V_256 = F_55 ( V_50 ) ;
goto V_105;
}
F_244 ( V_20 , F_197 ( V_50 -> V_51 ) ) ;
F_245 ( V_20 , F_246 ( V_146 ) ) ;
V_252 -> V_50 = V_50 ;
V_105:
F_136 ( V_252 ) ;
return V_256 ;
}
static int F_247 ( struct V_51 * V_146 , struct V_405 * V_197 )
{
struct V_42 * V_43 = F_69 ( V_146 ) ;
struct V_438 args = {
. V_183 = F_75 ( V_146 ) ,
. V_197 = * V_197 ,
} ;
struct V_439 V_37 = {
. V_43 = V_43 ,
} ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_440 ] ,
. V_262 = & args ,
. V_263 = & V_37 ,
} ;
int V_256 ;
V_256 = F_59 ( V_43 -> V_77 , V_43 , & V_137 , & args . V_134 , & V_37 . V_135 , 1 ) ;
if ( V_256 == 0 )
F_60 ( V_146 , & V_37 . V_148 ) ;
return V_256 ;
}
static int F_248 ( struct V_51 * V_146 , struct V_405 * V_197 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_69 ( V_146 ) ,
F_247 ( V_146 , V_197 ) ,
& V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static void F_249 ( struct V_136 * V_137 , struct V_51 * V_146 )
{
struct V_42 * V_43 = F_69 ( V_146 ) ;
struct V_438 * args = V_137 -> V_262 ;
struct V_439 * V_37 = V_137 -> V_263 ;
V_37 -> V_43 = V_43 ;
V_137 -> V_259 = & V_260 [ V_440 ] ;
F_39 ( & args -> V_134 , & V_37 -> V_135 , 1 ) ;
}
static void F_250 ( struct V_100 * V_101 , struct V_441 * V_132 )
{
F_49 ( F_69 ( V_132 -> V_146 ) ,
& V_132 -> args . V_134 ,
& V_132 -> V_37 . V_135 ,
V_101 ) ;
}
static int F_251 ( struct V_100 * V_101 , struct V_51 * V_146 )
{
struct V_439 * V_37 = V_101 -> V_274 . V_263 ;
if ( ! F_38 ( V_101 , & V_37 -> V_135 ) )
return 0 ;
if ( F_190 ( V_101 , V_37 -> V_43 , NULL ) == - V_129 )
return 0 ;
F_60 ( V_146 , & V_37 -> V_148 ) ;
return 1 ;
}
static void F_252 ( struct V_136 * V_137 , struct V_51 * V_146 )
{
struct V_42 * V_43 = F_69 ( V_146 ) ;
struct V_442 * V_331 = V_137 -> V_262 ;
struct V_443 * V_37 = V_137 -> V_263 ;
V_137 -> V_259 = & V_260 [ V_444 ] ;
V_37 -> V_43 = V_43 ;
F_39 ( & V_331 -> V_134 , & V_37 -> V_135 , 1 ) ;
}
static void F_253 ( struct V_100 * V_101 , struct V_445 * V_132 )
{
F_49 ( F_69 ( V_132 -> V_446 ) ,
& V_132 -> args . V_134 ,
& V_132 -> V_37 . V_135 ,
V_101 ) ;
}
static int F_254 ( struct V_100 * V_101 , struct V_51 * V_446 ,
struct V_51 * V_447 )
{
struct V_443 * V_37 = V_101 -> V_274 . V_263 ;
if ( ! F_38 ( V_101 , & V_37 -> V_135 ) )
return 0 ;
if ( F_190 ( V_101 , V_37 -> V_43 , NULL ) == - V_129 )
return 0 ;
F_60 ( V_446 , & V_37 -> V_448 ) ;
F_60 ( V_447 , & V_37 -> V_449 ) ;
return 1 ;
}
static int F_255 ( struct V_51 * V_446 , struct V_405 * V_450 ,
struct V_51 * V_447 , struct V_405 * V_451 )
{
struct V_42 * V_43 = F_69 ( V_446 ) ;
struct V_442 V_331 = {
. V_446 = F_75 ( V_446 ) ,
. V_447 = F_75 ( V_447 ) ,
. V_450 = V_450 ,
. V_451 = V_451 ,
} ;
struct V_443 V_37 = {
. V_43 = V_43 ,
} ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_444 ] ,
. V_262 = & V_331 ,
. V_263 = & V_37 ,
} ;
int V_256 = - V_125 ;
V_256 = F_59 ( V_43 -> V_77 , V_43 , & V_137 , & V_331 . V_134 , & V_37 . V_135 , 1 ) ;
if ( ! V_256 ) {
F_60 ( V_446 , & V_37 . V_448 ) ;
F_60 ( V_447 , & V_37 . V_449 ) ;
}
return V_256 ;
}
static int F_256 ( struct V_51 * V_446 , struct V_405 * V_450 ,
struct V_51 * V_447 , struct V_405 * V_451 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_69 ( V_446 ) ,
F_255 ( V_446 , V_450 ,
V_447 , V_451 ) ,
& V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static int F_257 ( struct V_51 * V_51 , struct V_51 * V_146 , struct V_405 * V_197 )
{
struct V_42 * V_43 = F_69 ( V_51 ) ;
struct V_452 V_331 = {
. V_183 = F_75 ( V_51 ) ,
. V_416 = F_75 ( V_146 ) ,
. V_197 = V_197 ,
. V_199 = V_43 -> V_200 ,
} ;
struct V_453 V_37 = {
. V_43 = V_43 ,
} ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_454 ] ,
. V_262 = & V_331 ,
. V_263 = & V_37 ,
} ;
int V_256 = - V_125 ;
V_37 . V_329 = F_236 () ;
if ( V_37 . V_329 == NULL )
goto V_105;
V_256 = F_59 ( V_43 -> V_77 , V_43 , & V_137 , & V_331 . V_134 , & V_37 . V_135 , 1 ) ;
if ( ! V_256 ) {
F_60 ( V_146 , & V_37 . V_148 ) ;
F_178 ( V_51 , V_37 . V_329 ) ;
}
V_105:
F_237 ( V_37 . V_329 ) ;
return V_256 ;
}
static int F_258 ( struct V_51 * V_51 , struct V_51 * V_146 , struct V_405 * V_197 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_69 ( V_51 ) ,
F_257 ( V_51 , V_146 , V_197 ) ,
& V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static struct V_455 * F_259 ( struct V_51 * V_146 ,
struct V_405 * V_197 , struct V_174 * V_306 , T_6 V_456 )
{
struct V_455 * V_132 ;
V_132 = F_70 ( sizeof( * V_132 ) , V_319 ) ;
if ( V_132 != NULL ) {
struct V_42 * V_43 = F_69 ( V_146 ) ;
V_132 -> V_137 . V_259 = & V_260 [ V_457 ] ;
V_132 -> V_137 . V_262 = & V_132 -> V_331 ;
V_132 -> V_137 . V_263 = & V_132 -> V_37 ;
V_132 -> V_331 . V_416 = F_75 ( V_146 ) ;
V_132 -> V_331 . V_43 = V_43 ;
V_132 -> V_331 . V_197 = V_197 ;
V_132 -> V_331 . V_175 = V_306 ;
V_132 -> V_331 . V_456 = V_456 ;
V_132 -> V_331 . V_199 = V_43 -> V_200 ;
V_132 -> V_37 . V_43 = V_43 ;
V_132 -> V_37 . V_183 = & V_132 -> V_183 ;
V_132 -> V_37 . V_329 = & V_132 -> V_329 ;
F_65 ( V_132 -> V_37 . V_329 ) ;
}
return V_132 ;
}
static int F_260 ( struct V_51 * V_146 , struct V_20 * V_20 , struct V_455 * V_132 )
{
int V_256 = F_59 ( F_69 ( V_146 ) -> V_77 , F_69 ( V_146 ) , & V_132 -> V_137 ,
& V_132 -> V_331 . V_134 , & V_132 -> V_37 . V_135 , 1 ) ;
if ( V_256 == 0 ) {
F_60 ( V_146 , & V_132 -> V_37 . V_458 ) ;
V_256 = F_261 ( V_20 , V_132 -> V_37 . V_183 , V_132 -> V_37 . V_329 ) ;
}
return V_256 ;
}
static void F_262 ( struct V_455 * V_132 )
{
F_78 ( V_132 ) ;
}
static int F_263 ( struct V_51 * V_146 , struct V_20 * V_20 ,
struct V_406 * V_406 , unsigned int V_394 , struct V_174 * V_306 )
{
struct V_455 * V_132 ;
int V_256 = - V_459 ;
if ( V_394 > V_460 )
goto V_105;
V_256 = - V_125 ;
V_132 = F_259 ( V_146 , & V_20 -> V_198 , V_306 , V_461 ) ;
if ( V_132 == NULL )
goto V_105;
V_132 -> V_137 . V_259 = & V_260 [ V_462 ] ;
V_132 -> V_331 . V_207 . V_463 . V_25 = & V_406 ;
V_132 -> V_331 . V_207 . V_463 . V_394 = V_394 ;
V_256 = F_260 ( V_146 , V_20 , V_132 ) ;
F_262 ( V_132 ) ;
V_105:
return V_256 ;
}
static int F_264 ( struct V_51 * V_146 , struct V_20 * V_20 ,
struct V_406 * V_406 , unsigned int V_394 , struct V_174 * V_306 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_69 ( V_146 ) ,
F_263 ( V_146 , V_20 , V_406 ,
V_394 , V_306 ) ,
& V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static int F_265 ( struct V_51 * V_146 , struct V_20 * V_20 ,
struct V_174 * V_306 )
{
struct V_455 * V_132 ;
int V_256 = - V_125 ;
V_132 = F_259 ( V_146 , & V_20 -> V_198 , V_306 , V_464 ) ;
if ( V_132 == NULL )
goto V_105;
V_256 = F_260 ( V_146 , V_20 , V_132 ) ;
F_262 ( V_132 ) ;
V_105:
return V_256 ;
}
static int F_266 ( struct V_51 * V_146 , struct V_20 * V_20 ,
struct V_174 * V_306 )
{
struct V_45 V_46 = { } ;
int V_1 ;
V_306 -> V_437 &= ~ F_243 () ;
do {
V_1 = F_13 ( F_69 ( V_146 ) ,
F_265 ( V_146 , V_20 , V_306 ) ,
& V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static int F_267 ( struct V_20 * V_20 , struct V_264 * V_292 ,
T_1 V_18 , struct V_406 * * V_25 , unsigned int V_33 , int V_465 )
{
struct V_51 * V_146 = V_20 -> V_29 ;
struct V_21 args = {
. V_183 = F_75 ( V_146 ) ,
. V_25 = V_25 ,
. V_32 = 0 ,
. V_33 = V_33 ,
. V_199 = F_69 ( V_20 -> V_29 ) -> V_200 ,
. V_465 = V_465 ,
} ;
struct V_466 V_37 ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_467 ] ,
. V_262 = & args ,
. V_263 = & V_37 ,
. V_264 = V_292 ,
} ;
int V_256 ;
F_2 ( L_33 , V_16 ,
V_20 -> V_31 -> V_198 . V_197 ,
V_20 -> V_198 . V_197 ,
( unsigned long long ) V_18 ) ;
F_3 ( V_18 , F_61 ( V_146 ) -> V_468 , V_20 , & args ) ;
V_37 . V_32 = args . V_32 ;
V_256 = F_59 ( F_69 ( V_146 ) -> V_77 , F_69 ( V_146 ) , & V_137 , & args . V_134 , & V_37 . V_135 , 0 ) ;
if ( V_256 >= 0 ) {
memcpy ( F_61 ( V_146 ) -> V_468 , V_37 . V_19 . V_132 , V_469 ) ;
V_256 += args . V_32 ;
}
F_268 ( V_146 ) ;
F_2 ( L_34 , V_16 , V_256 ) ;
return V_256 ;
}
static int F_269 ( struct V_20 * V_20 , struct V_264 * V_292 ,
T_1 V_18 , struct V_406 * * V_25 , unsigned int V_33 , int V_465 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_69 ( V_20 -> V_29 ) ,
F_267 ( V_20 , V_292 , V_18 ,
V_25 , V_33 , V_465 ) ,
& V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static int F_270 ( struct V_51 * V_146 , struct V_20 * V_20 ,
struct V_174 * V_306 , T_8 V_470 )
{
struct V_455 * V_132 ;
int V_213 = V_306 -> V_437 ;
int V_256 = - V_125 ;
V_132 = F_259 ( V_146 , & V_20 -> V_198 , V_306 , V_471 ) ;
if ( V_132 == NULL )
goto V_105;
if ( F_271 ( V_213 ) )
V_132 -> V_331 . V_456 = V_472 ;
else if ( F_272 ( V_213 ) ) {
V_132 -> V_331 . V_456 = V_473 ;
V_132 -> V_331 . V_207 . V_474 . V_475 = F_273 ( V_470 ) ;
V_132 -> V_331 . V_207 . V_474 . V_476 = F_274 ( V_470 ) ;
}
else if ( F_275 ( V_213 ) ) {
V_132 -> V_331 . V_456 = V_477 ;
V_132 -> V_331 . V_207 . V_474 . V_475 = F_273 ( V_470 ) ;
V_132 -> V_331 . V_207 . V_474 . V_476 = F_274 ( V_470 ) ;
} else if ( ! F_276 ( V_213 ) ) {
V_256 = - V_10 ;
goto V_258;
}
V_256 = F_260 ( V_146 , V_20 , V_132 ) ;
V_258:
F_262 ( V_132 ) ;
V_105:
return V_256 ;
}
static int F_277 ( struct V_51 * V_146 , struct V_20 * V_20 ,
struct V_174 * V_306 , T_8 V_470 )
{
struct V_45 V_46 = { } ;
int V_1 ;
V_306 -> V_437 &= ~ F_243 () ;
do {
V_1 = F_13 ( F_69 ( V_146 ) ,
F_270 ( V_146 , V_20 , V_306 , V_470 ) ,
& V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static int F_278 ( struct V_42 * V_43 , struct V_357 * V_358 ,
struct V_478 * V_479 )
{
struct V_480 args = {
. V_183 = V_358 ,
. V_199 = V_43 -> V_200 ,
} ;
struct V_481 V_37 = {
. V_479 = V_479 ,
} ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_482 ] ,
. V_262 = & args ,
. V_263 = & V_37 ,
} ;
F_65 ( V_479 -> V_329 ) ;
return F_59 ( V_43 -> V_77 , V_43 , & V_137 , & args . V_134 , & V_37 . V_135 , 0 ) ;
}
static int F_279 ( struct V_42 * V_43 , struct V_357 * V_358 , struct V_478 * V_479 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_13 ( V_43 ,
F_278 ( V_43 , V_358 , V_479 ) ,
& V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static int F_280 ( struct V_42 * V_43 , struct V_357 * V_358 ,
struct V_385 * V_483 )
{
struct V_484 args = {
. V_183 = V_358 ,
. V_199 = V_43 -> V_200 ,
} ;
struct V_485 V_37 = {
. V_483 = V_483 ,
} ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_486 ] ,
. V_262 = & args ,
. V_263 = & V_37 ,
} ;
return F_59 ( V_43 -> V_77 , V_43 , & V_137 , & args . V_134 , & V_37 . V_135 , 0 ) ;
}
static int F_211 ( struct V_42 * V_43 , struct V_357 * V_358 , struct V_385 * V_483 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_13 ( V_43 ,
F_280 ( V_43 , V_358 , V_483 ) ,
& V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static int F_281 ( struct V_42 * V_43 , struct V_357 * V_358 , struct V_385 * V_483 )
{
int error ;
F_65 ( V_483 -> V_329 ) ;
error = F_211 ( V_43 , V_358 , V_483 ) ;
if ( error == 0 ) {
V_43 -> V_487 = V_483 -> V_488 ;
F_282 ( V_43 , V_358 , V_483 -> V_489 ) ;
}
return error ;
}
static int F_283 ( struct V_42 * V_43 , struct V_357 * V_358 ,
struct V_490 * V_491 )
{
struct V_492 args = {
. V_183 = V_358 ,
. V_199 = V_43 -> V_200 ,
} ;
struct V_493 V_37 = {
. V_491 = V_491 ,
} ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_494 ] ,
. V_262 = & args ,
. V_263 = & V_37 ,
} ;
if ( ( args . V_199 [ 0 ] & V_495 [ 0 ] ) == 0 ) {
memset ( V_491 , 0 , sizeof( * V_491 ) ) ;
return 0 ;
}
F_65 ( V_491 -> V_329 ) ;
return F_59 ( V_43 -> V_77 , V_43 , & V_137 , & args . V_134 , & V_37 . V_135 , 0 ) ;
}
static int F_284 ( struct V_42 * V_43 , struct V_357 * V_358 ,
struct V_490 * V_491 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_13 ( V_43 ,
F_283 ( V_43 , V_358 , V_491 ) ,
& V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
void F_285 ( struct V_496 * V_132 )
{
F_268 ( V_132 -> V_497 -> V_51 ) ;
}
static int F_286 ( struct V_100 * V_101 , struct V_496 * V_132 )
{
struct V_42 * V_43 = F_69 ( V_132 -> V_497 -> V_51 ) ;
if ( F_190 ( V_101 , V_43 , V_132 -> args . V_498 -> V_50 ) == - V_129 ) {
F_35 ( V_101 ) ;
return - V_129 ;
}
F_285 ( V_132 ) ;
if ( V_101 -> V_113 > 0 )
F_27 ( V_43 , V_132 -> V_84 ) ;
return 0 ;
}
static int F_287 ( struct V_100 * V_101 , struct V_496 * V_132 )
{
F_2 ( L_12 , V_16 ) ;
if ( ! F_38 ( V_101 , & V_132 -> V_37 . V_135 ) )
return - V_129 ;
return V_132 -> V_499 ? V_132 -> V_499 ( V_101 , V_132 ) :
F_286 ( V_101 , V_132 ) ;
}
static void F_288 ( struct V_496 * V_132 , struct V_136 * V_137 )
{
V_132 -> V_84 = V_126 ;
V_132 -> V_499 = F_286 ;
V_137 -> V_259 = & V_260 [ V_500 ] ;
F_39 ( & V_132 -> args . V_134 , & V_132 -> V_37 . V_135 , 0 ) ;
}
static void F_289 ( struct V_100 * V_101 , struct V_496 * V_132 )
{
F_49 ( F_69 ( V_132 -> V_497 -> V_51 ) ,
& V_132 -> args . V_134 ,
& V_132 -> V_37 . V_135 ,
V_101 ) ;
}
static int F_290 ( struct V_100 * V_101 , struct V_501 * V_132 )
{
struct V_51 * V_51 = V_132 -> V_497 -> V_51 ;
if ( F_190 ( V_101 , F_69 ( V_51 ) , V_132 -> args . V_498 -> V_50 ) == - V_129 ) {
F_35 ( V_101 ) ;
return - V_129 ;
}
if ( V_101 -> V_113 >= 0 ) {
F_27 ( F_69 ( V_51 ) , V_132 -> V_84 ) ;
F_291 ( V_51 , & V_132 -> V_329 ) ;
}
return 0 ;
}
static int F_292 ( struct V_100 * V_101 , struct V_501 * V_132 )
{
if ( ! F_38 ( V_101 , & V_132 -> V_37 . V_135 ) )
return - V_129 ;
return V_132 -> V_502 ? V_132 -> V_502 ( V_101 , V_132 ) :
F_290 ( V_101 , V_132 ) ;
}
static
bool F_293 ( const struct V_501 * V_132 )
{
const struct V_503 * V_504 = V_132 -> V_497 ;
if ( V_132 -> V_505 != NULL || V_504 -> V_506 != NULL )
return false ;
return F_14 ( V_504 -> V_51 , V_55 ) == 0 ;
}
static void F_294 ( struct V_501 * V_132 , struct V_136 * V_137 )
{
struct V_42 * V_43 = F_69 ( V_132 -> V_497 -> V_51 ) ;
if ( ! F_293 ( V_132 ) ) {
V_132 -> args . V_199 = NULL ;
V_132 -> V_37 . V_329 = NULL ;
} else
V_132 -> args . V_199 = V_43 -> V_354 ;
if ( ! V_132 -> V_502 )
V_132 -> V_502 = F_290 ;
V_132 -> V_37 . V_43 = V_43 ;
V_132 -> V_84 = V_126 ;
V_137 -> V_259 = & V_260 [ V_507 ] ;
F_39 ( & V_132 -> args . V_134 , & V_132 -> V_37 . V_135 , 1 ) ;
}
static void F_295 ( struct V_100 * V_101 , struct V_501 * V_132 )
{
F_49 ( F_69 ( V_132 -> V_497 -> V_51 ) ,
& V_132 -> args . V_134 ,
& V_132 -> V_37 . V_135 ,
V_101 ) ;
}
static void F_296 ( struct V_100 * V_101 , struct V_508 * V_132 )
{
F_49 ( F_69 ( V_132 -> V_51 ) ,
& V_132 -> args . V_134 ,
& V_132 -> V_37 . V_135 ,
V_101 ) ;
}
static int F_297 ( struct V_100 * V_101 , struct V_508 * V_132 )
{
struct V_51 * V_51 = V_132 -> V_51 ;
if ( F_190 ( V_101 , F_69 ( V_51 ) , NULL ) == - V_129 ) {
F_35 ( V_101 ) ;
return - V_129 ;
}
return 0 ;
}
static int F_298 ( struct V_100 * V_101 , struct V_508 * V_132 )
{
if ( ! F_38 ( V_101 , & V_132 -> V_37 . V_135 ) )
return - V_129 ;
return V_132 -> V_509 ( V_101 , V_132 ) ;
}
static void F_299 ( struct V_508 * V_132 , struct V_136 * V_137 )
{
struct V_42 * V_43 = F_69 ( V_132 -> V_51 ) ;
if ( V_132 -> V_509 == NULL )
V_132 -> V_509 = F_297 ;
V_132 -> V_37 . V_43 = V_43 ;
V_137 -> V_259 = & V_260 [ V_510 ] ;
F_39 ( & V_132 -> args . V_134 , & V_132 -> V_37 . V_135 , 1 ) ;
}
static void F_300 ( void * V_130 )
{
struct V_511 * V_132 = V_130 ;
struct V_47 * V_48 = V_132 -> V_77 ;
if ( F_301 ( & V_48 -> V_512 ) > 1 )
F_302 ( V_48 ) ;
F_303 ( V_48 ) ;
F_78 ( V_132 ) ;
}
static void F_304 ( struct V_100 * V_101 , void * V_130 )
{
struct V_511 * V_132 = V_130 ;
struct V_47 * V_48 = V_132 -> V_77 ;
unsigned long V_84 = V_132 -> V_84 ;
if ( V_101 -> V_113 < 0 ) {
if ( F_42 ( V_513 , & V_48 -> V_514 ) == 0 )
return;
if ( V_101 -> V_113 != V_515 ) {
F_18 ( V_48 ) ;
return;
}
F_305 ( V_48 ) ;
}
F_23 ( V_48 , V_84 ) ;
}
static int F_306 ( struct V_47 * V_48 , struct V_264 * V_292 , unsigned V_516 )
{
struct V_136 V_137 = {
. V_259 = & V_260 [ V_517 ] ,
. V_262 = V_48 ,
. V_264 = V_292 ,
} ;
struct V_511 * V_132 ;
if ( V_516 == 0 )
return 0 ;
if ( ! F_307 ( & V_48 -> V_512 ) )
return - V_17 ;
V_132 = F_217 ( sizeof( * V_132 ) , V_254 ) ;
if ( V_132 == NULL )
return - V_125 ;
V_132 -> V_77 = V_48 ;
V_132 -> V_84 = V_126 ;
return F_308 ( V_48 -> V_518 , & V_137 , V_519 ,
& V_520 , V_132 ) ;
}
static int F_309 ( struct V_47 * V_48 , struct V_264 * V_292 )
{
struct V_136 V_137 = {
. V_259 = & V_260 [ V_517 ] ,
. V_262 = V_48 ,
. V_264 = V_292 ,
} ;
unsigned long V_521 = V_126 ;
int V_256 ;
V_256 = F_58 ( V_48 -> V_518 , & V_137 , 0 ) ;
if ( V_256 < 0 )
return V_256 ;
F_23 ( V_48 , V_521 ) ;
return 0 ;
}
static inline int F_310 ( struct V_42 * V_43 )
{
return ( V_43 -> V_80 & V_362 )
&& ( V_43 -> V_383 & V_522 )
&& ( V_43 -> V_383 & V_523 ) ;
}
static int F_311 ( const void * V_524 , T_9 V_525 ,
struct V_406 * * V_25 , unsigned int * V_32 )
{
struct V_406 * V_526 , * * V_527 ;
int V_528 = 0 ;
T_9 V_394 ;
V_527 = V_25 ;
do {
V_394 = F_312 ( T_9 , V_529 , V_525 ) ;
V_526 = F_216 ( V_319 ) ;
if ( V_526 == NULL )
goto V_530;
memcpy ( F_313 ( V_526 ) , V_524 , V_394 ) ;
V_524 += V_394 ;
V_525 -= V_394 ;
* V_25 ++ = V_526 ;
V_528 ++ ;
} while ( V_525 != 0 );
return V_528 ;
V_530:
for(; V_528 > 0 ; V_528 -- )
F_220 ( V_527 [ V_528 - 1 ] ) ;
return - V_125 ;
}
static void F_314 ( struct V_51 * V_51 , struct V_531 * V_532 )
{
struct V_149 * V_150 = F_61 ( V_51 ) ;
F_24 ( & V_51 -> V_151 ) ;
F_78 ( V_150 -> V_533 ) ;
V_150 -> V_533 = V_532 ;
F_26 ( & V_51 -> V_151 ) ;
}
static void F_315 ( struct V_51 * V_51 )
{
F_314 ( V_51 , NULL ) ;
}
static inline T_10 F_316 ( struct V_51 * V_51 , char * V_524 , T_9 V_525 )
{
struct V_149 * V_150 = F_61 ( V_51 ) ;
struct V_531 * V_532 ;
int V_52 = - V_253 ;
F_24 ( & V_51 -> V_151 ) ;
V_532 = V_150 -> V_533 ;
if ( V_532 == NULL )
goto V_105;
if ( V_524 == NULL )
goto V_534;
if ( V_532 -> V_535 == 0 )
goto V_105;
V_52 = - V_536 ;
if ( V_532 -> V_394 > V_525 )
goto V_105;
memcpy ( V_524 , V_532 -> V_132 , V_532 -> V_394 ) ;
V_534:
V_52 = V_532 -> V_394 ;
V_105:
F_26 ( & V_51 -> V_151 ) ;
return V_52 ;
}
static void F_317 ( struct V_51 * V_51 , struct V_406 * * V_25 , T_9 V_32 , T_9 V_537 )
{
struct V_531 * V_532 ;
T_9 V_525 = sizeof( * V_532 ) + V_537 ;
if ( V_525 <= V_529 ) {
V_532 = F_217 ( V_525 , V_319 ) ;
if ( V_532 == NULL )
goto V_105;
V_532 -> V_535 = 1 ;
F_318 ( V_532 -> V_132 , V_25 , V_32 , V_537 ) ;
} else {
V_532 = F_217 ( sizeof( * V_532 ) , V_319 ) ;
if ( V_532 == NULL )
goto V_105;
V_532 -> V_535 = 0 ;
}
V_532 -> V_394 = V_537 ;
V_105:
F_314 ( V_51 , V_532 ) ;
}
static T_10 F_319 ( struct V_51 * V_51 , void * V_524 , T_9 V_525 )
{
struct V_406 * V_25 [ V_538 ] = { NULL , } ;
struct V_539 args = {
. V_183 = F_75 ( V_51 ) ,
. V_540 = V_25 ,
. V_537 = V_525 ,
} ;
struct V_541 V_37 = {
. V_537 = V_525 ,
} ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_542 ] ,
. V_262 = & args ,
. V_263 = & V_37 ,
} ;
unsigned int V_543 = F_320 ( V_525 , V_529 ) ;
int V_52 = - V_125 , V_393 ;
if ( V_543 == 0 )
V_543 = 1 ;
if ( V_543 > F_208 ( V_25 ) )
return - V_536 ;
for ( V_393 = 0 ; V_393 < V_543 ; V_393 ++ ) {
V_25 [ V_393 ] = F_216 ( V_319 ) ;
if ( ! V_25 [ V_393 ] )
goto V_258;
}
V_37 . V_544 = F_216 ( V_319 ) ;
if ( ! V_37 . V_544 )
goto V_258;
args . V_537 = V_543 * V_529 ;
args . V_545 = 0 ;
F_2 ( L_35 ,
V_16 , V_524 , V_525 , V_543 , args . V_537 ) ;
V_52 = F_59 ( F_69 ( V_51 ) -> V_77 , F_69 ( V_51 ) ,
& V_137 , & args . V_134 , & V_37 . V_135 , 0 ) ;
if ( V_52 )
goto V_258;
if ( V_37 . V_546 & V_547 ) {
if ( V_524 == NULL )
goto V_548;
V_52 = - V_536 ;
goto V_258;
}
F_317 ( V_51 , V_25 , V_37 . V_549 , V_37 . V_537 ) ;
if ( V_524 ) {
if ( V_37 . V_537 > V_525 ) {
V_52 = - V_536 ;
goto V_258;
}
F_318 ( V_524 , V_25 , V_37 . V_549 , V_37 . V_537 ) ;
}
V_548:
V_52 = V_37 . V_537 ;
V_258:
for ( V_393 = 0 ; V_393 < V_543 ; V_393 ++ )
if ( V_25 [ V_393 ] )
F_220 ( V_25 [ V_393 ] ) ;
if ( V_37 . V_544 )
F_220 ( V_37 . V_544 ) ;
return V_52 ;
}
static T_10 F_321 ( struct V_51 * V_51 , void * V_524 , T_9 V_525 )
{
struct V_45 V_46 = { } ;
T_10 V_52 ;
do {
V_52 = F_319 ( V_51 , V_524 , V_525 ) ;
if ( V_52 >= 0 )
break;
V_52 = F_13 ( F_69 ( V_51 ) , V_52 , & V_46 ) ;
} while ( V_46 . V_53 );
return V_52 ;
}
static T_10 F_322 ( struct V_51 * V_51 , void * V_524 , T_9 V_525 )
{
struct V_42 * V_43 = F_69 ( V_51 ) ;
int V_52 ;
if ( ! F_310 ( V_43 ) )
return - V_550 ;
V_52 = F_323 ( V_43 , V_51 ) ;
if ( V_52 < 0 )
return V_52 ;
if ( F_61 ( V_51 ) -> V_152 & V_551 )
F_324 ( V_51 ) ;
V_52 = F_316 ( V_51 , V_524 , V_525 ) ;
if ( V_52 != - V_253 )
return V_52 ;
return F_321 ( V_51 , V_524 , V_525 ) ;
}
static int F_325 ( struct V_51 * V_51 , const void * V_524 , T_9 V_525 )
{
struct V_42 * V_43 = F_69 ( V_51 ) ;
struct V_406 * V_25 [ V_538 ] ;
struct V_552 V_331 = {
. V_183 = F_75 ( V_51 ) ,
. V_540 = V_25 ,
. V_537 = V_525 ,
} ;
struct V_553 V_37 ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_554 ] ,
. V_262 = & V_331 ,
. V_263 = & V_37 ,
} ;
unsigned int V_543 = F_320 ( V_525 , V_529 ) ;
int V_52 , V_393 ;
if ( ! F_310 ( V_43 ) )
return - V_550 ;
if ( V_543 > F_208 ( V_25 ) )
return - V_536 ;
V_393 = F_311 ( V_524 , V_525 , V_331 . V_540 , & V_331 . V_545 ) ;
if ( V_393 < 0 )
return V_393 ;
F_15 ( V_51 ) ;
V_52 = F_59 ( V_43 -> V_77 , V_43 , & V_137 , & V_331 . V_134 , & V_37 . V_135 , 1 ) ;
for (; V_393 > 0 ; V_393 -- )
F_326 ( V_25 [ V_393 - 1 ] ) ;
F_24 ( & V_51 -> V_151 ) ;
F_61 ( V_51 ) -> V_152 |= V_153 ;
F_26 ( & V_51 -> V_151 ) ;
F_327 ( V_51 ) ;
F_324 ( V_51 ) ;
return V_52 ;
}
static int F_328 ( struct V_51 * V_51 , const void * V_524 , T_9 V_525 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_69 ( V_51 ) ,
F_325 ( V_51 , V_524 , V_525 ) ,
& V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static int
F_190 ( struct V_100 * V_101 , const struct V_42 * V_43 , struct V_49 * V_50 )
{
struct V_47 * V_48 = V_43 -> V_47 ;
if ( V_101 -> V_113 >= 0 )
return 0 ;
switch( V_101 -> V_113 ) {
case - V_57 :
case - V_58 :
case - V_59 :
if ( V_50 == NULL )
break;
F_17 ( V_50 -> V_51 ) ;
case - V_54 :
if ( V_50 == NULL )
break;
F_16 ( V_43 , V_50 ) ;
goto V_56;
case - V_60 :
if ( V_50 != NULL )
F_16 ( V_43 , V_50 ) ;
case - V_61 :
case - V_62 :
F_18 ( V_48 ) ;
goto V_56;
#if F_19 ( V_63 )
case - V_64 :
case - V_65 :
case - V_66 :
case - V_68 :
case - V_67 :
case - V_69 :
case - V_70 :
F_2 ( L_36 , V_16 ,
V_101 -> V_113 ) ;
F_20 ( V_48 -> V_71 , V_101 -> V_113 ) ;
V_101 -> V_113 = 0 ;
return - V_129 ;
#endif
case - V_76 :
F_329 ( V_43 , V_555 ) ;
case - V_75 :
F_37 ( V_101 , V_39 ) ;
V_101 -> V_113 = 0 ;
return - V_129 ;
case - V_78 :
case - V_79 :
V_101 -> V_113 = 0 ;
return - V_129 ;
}
V_101 -> V_113 = F_1 ( V_101 -> V_113 ) ;
return 0 ;
V_56:
F_48 ( & V_48 -> V_556 , V_101 , NULL ) ;
if ( F_42 ( V_557 , & V_48 -> V_558 ) == 0 )
F_330 ( & V_48 -> V_556 , V_101 ) ;
V_101 -> V_113 = 0 ;
return - V_129 ;
}
static void F_331 ( const struct V_47 * V_48 ,
T_11 * V_559 )
{
T_2 V_206 [ 2 ] ;
if ( F_42 ( V_560 , & V_48 -> V_558 ) ) {
V_206 [ 0 ] = 0 ;
V_206 [ 1 ] = ( T_2 ) ( V_561 + 1 ) ;
} else {
struct V_562 * V_563 = F_332 ( V_48 -> V_564 , V_565 ) ;
V_206 [ 0 ] = ( T_2 ) V_563 -> V_566 . V_567 ;
V_206 [ 1 ] = ( T_2 ) V_563 -> V_566 . V_568 ;
}
memcpy ( V_559 -> V_132 , V_206 , sizeof( V_559 -> V_132 ) ) ;
}
static unsigned int
F_333 ( const struct V_47 * V_48 ,
char * V_524 , T_9 V_394 )
{
unsigned int V_569 ;
F_104 () ;
V_569 = F_334 ( V_524 , V_394 , L_37 ,
V_48 -> V_570 ,
F_335 ( V_48 -> V_518 ,
V_571 ) ,
F_335 ( V_48 -> V_518 ,
V_572 ) ) ;
F_107 () ;
return V_569 ;
}
static unsigned int
F_336 ( const struct V_47 * V_48 ,
char * V_524 , T_9 V_394 )
{
char * V_573 = V_48 -> V_518 -> V_574 ;
if ( V_575 [ 0 ] != '\0' )
V_573 = V_575 ;
return F_334 ( V_524 , V_394 , L_38 ,
V_48 -> V_576 -> V_577 , V_48 -> V_399 ,
V_573 ) ;
}
int F_337 ( struct V_47 * V_48 , T_6 V_578 ,
unsigned short V_579 , struct V_264 * V_292 ,
struct V_580 * V_37 )
{
T_11 V_581 ;
struct V_582 V_583 = {
. V_581 = & V_581 ,
. V_584 = V_578 ,
. V_585 = V_48 -> V_586 ,
} ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_587 ] ,
. V_262 = & V_583 ,
. V_263 = V_37 ,
. V_264 = V_292 ,
} ;
int V_256 ;
F_331 ( V_48 , & V_581 ) ;
if ( F_42 ( V_588 , & V_48 -> V_589 ) )
V_583 . V_590 =
F_336 ( V_48 ,
V_583 . V_591 ,
sizeof( V_583 . V_591 ) ) ;
else
V_583 . V_590 =
F_333 ( V_48 ,
V_583 . V_591 ,
sizeof( V_583 . V_591 ) ) ;
F_104 () ;
V_583 . V_592 = F_334 ( V_583 . V_593 ,
sizeof( V_583 . V_593 ) ,
F_335 ( V_48 -> V_518 ,
V_594 ) ) ;
F_107 () ;
V_583 . V_595 = F_334 ( V_583 . V_596 ,
sizeof( V_583 . V_596 ) , L_39 ,
V_48 -> V_570 , V_579 >> 8 , V_579 & 255 ) ;
F_2 ( L_40 ,
V_48 -> V_518 -> V_597 -> V_598 -> V_599 ,
V_583 . V_590 , V_583 . V_591 ) ;
V_256 = F_58 ( V_48 -> V_518 , & V_137 , V_600 ) ;
F_2 ( L_41 , V_256 ) ;
return V_256 ;
}
int F_338 ( struct V_47 * V_48 ,
struct V_580 * V_331 ,
struct V_264 * V_292 )
{
struct V_385 V_483 ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_601 ] ,
. V_262 = V_331 ,
. V_263 = & V_483 ,
. V_264 = V_292 ,
} ;
unsigned long V_521 ;
int V_256 ;
F_2 ( L_42 ,
V_48 -> V_518 -> V_597 -> V_598 -> V_599 ,
V_48 -> V_192 ) ;
V_521 = V_126 ;
V_256 = F_58 ( V_48 -> V_518 , & V_137 , V_600 ) ;
if ( V_256 == 0 ) {
F_24 ( & V_48 -> V_85 ) ;
V_48 -> V_602 = V_483 . V_603 * V_73 ;
V_48 -> V_86 = V_521 ;
F_26 ( & V_48 -> V_85 ) ;
}
F_2 ( L_43 , V_256 ) ;
return V_256 ;
}
static void F_339 ( struct V_100 * V_101 , void * V_130 )
{
struct V_604 * V_132 = V_130 ;
if ( ! F_38 ( V_101 , & V_132 -> V_37 . V_135 ) )
return;
switch ( V_101 -> V_113 ) {
case - V_61 :
case - V_60 :
case 0 :
F_27 ( V_132 -> V_37 . V_43 , V_132 -> V_84 ) ;
break;
default:
if ( F_190 ( V_101 , V_132 -> V_37 . V_43 , NULL ) ==
- V_129 ) {
F_35 ( V_101 ) ;
return;
}
}
V_132 -> V_241 = V_101 -> V_113 ;
}
static void F_340 ( void * V_130 )
{
F_78 ( V_130 ) ;
}
static void F_341 ( struct V_100 * V_101 , void * V_132 )
{
struct V_604 * V_605 ;
V_605 = (struct V_604 * ) V_132 ;
F_49 ( V_605 -> V_37 . V_43 ,
& V_605 -> args . V_134 ,
& V_605 -> V_37 . V_135 ,
V_101 ) ;
}
static int F_342 ( struct V_51 * V_51 , struct V_264 * V_292 , const T_5 * V_209 , int V_606 )
{
struct V_604 * V_132 ;
struct V_42 * V_43 = F_69 ( V_51 ) ;
struct V_100 * V_101 ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_607 ] ,
. V_264 = V_292 ,
} ;
struct V_138 V_265 = {
. V_140 = V_43 -> V_77 ,
. V_136 = & V_137 ,
. V_141 = & V_608 ,
. V_173 = V_269 ,
} ;
int V_256 = 0 ;
V_132 = F_70 ( sizeof( * V_132 ) , V_254 ) ;
if ( V_132 == NULL )
return - V_125 ;
F_39 ( & V_132 -> args . V_134 , & V_132 -> V_37 . V_135 , 1 ) ;
V_132 -> args . V_358 = & V_132 -> V_183 ;
V_132 -> args . V_209 = & V_132 -> V_209 ;
V_132 -> args . V_199 = V_43 -> V_354 ;
F_148 ( & V_132 -> V_183 , F_75 ( V_51 ) ) ;
F_97 ( & V_132 -> V_209 , V_209 ) ;
V_132 -> V_37 . V_329 = & V_132 -> V_329 ;
V_132 -> V_37 . V_43 = V_43 ;
F_65 ( V_132 -> V_37 . V_329 ) ;
V_132 -> V_84 = V_126 ;
V_132 -> V_241 = 0 ;
V_265 . V_143 = V_132 ;
V_137 . V_262 = & V_132 -> args ;
V_137 . V_263 = & V_132 -> V_37 ;
V_101 = F_54 ( & V_265 ) ;
if ( F_44 ( V_101 ) )
return F_55 ( V_101 ) ;
if ( ! V_606 )
goto V_105;
V_256 = F_89 ( V_101 ) ;
if ( V_256 != 0 )
goto V_105;
V_256 = V_132 -> V_241 ;
if ( V_256 == 0 )
F_291 ( V_51 , & V_132 -> V_329 ) ;
else
F_118 ( V_51 , & V_132 -> V_329 ) ;
V_105:
F_56 ( V_101 ) ;
return V_256 ;
}
int F_343 ( struct V_51 * V_51 , struct V_264 * V_292 , const T_5 * V_209 , int V_606 )
{
struct V_42 * V_43 = F_69 ( V_51 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_342 ( V_51 , V_292 , V_209 , V_606 ) ;
switch ( V_1 ) {
case - V_61 :
case - V_60 :
case 0 :
return 0 ;
}
V_1 = F_13 ( V_43 , V_1 , & V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static unsigned long
F_344 ( unsigned long V_36 )
{
F_11 ( V_36 ) ;
V_36 <<= 1 ;
if ( V_36 > V_609 )
return V_609 ;
return V_36 ;
}
static int F_345 ( struct V_49 * V_50 , int V_610 , struct V_611 * V_612 )
{
struct V_51 * V_51 = V_50 -> V_51 ;
struct V_42 * V_43 = F_69 ( V_51 ) ;
struct V_47 * V_48 = V_43 -> V_47 ;
struct V_613 V_331 = {
. V_183 = F_75 ( V_51 ) ,
. V_614 = V_612 ,
} ;
struct V_615 V_37 = {
. V_616 = V_612 ,
} ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_617 ] ,
. V_262 = & V_331 ,
. V_263 = & V_37 ,
. V_264 = V_50 -> V_181 -> V_237 ,
} ;
struct V_618 * V_619 ;
int V_256 ;
V_331 . V_620 . V_191 = V_48 -> V_192 ;
V_256 = F_346 ( V_50 , V_612 ) ;
if ( V_256 != 0 )
goto V_105;
V_619 = V_612 -> V_621 . V_622 . V_181 ;
V_331 . V_620 . V_193 = V_619 -> V_623 . V_196 ;
V_331 . V_620 . V_624 = V_43 -> V_624 ;
V_256 = F_59 ( V_43 -> V_77 , V_43 , & V_137 , & V_331 . V_134 , & V_37 . V_135 , 1 ) ;
switch ( V_256 ) {
case 0 :
V_612 -> V_625 = V_626 ;
break;
case - V_627 :
V_256 = 0 ;
}
V_612 -> V_628 -> V_629 ( V_612 ) ;
V_105:
return V_256 ;
}
static int F_347 ( struct V_49 * V_50 , int V_610 , struct V_611 * V_612 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_69 ( V_50 -> V_51 ) ,
F_345 ( V_50 , V_610 , V_612 ) ,
& V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static int F_348 ( struct V_630 * V_630 , struct V_611 * V_614 )
{
int V_37 = 0 ;
switch ( V_614 -> V_631 & ( V_632 | V_633 ) ) {
case V_632 :
V_37 = F_349 ( V_630 , V_614 ) ;
break;
case V_633 :
V_37 = F_350 ( V_630 , V_614 ) ;
break;
default:
F_351 () ;
}
return V_37 ;
}
static struct V_634 * F_352 ( struct V_611 * V_614 ,
struct V_251 * V_252 ,
struct V_618 * V_619 ,
struct V_635 * V_162 )
{
struct V_634 * V_24 ;
struct V_51 * V_51 = V_619 -> V_636 -> V_51 ;
V_24 = F_70 ( sizeof( * V_24 ) , V_254 ) ;
if ( V_24 == NULL )
return NULL ;
V_24 -> V_331 . V_183 = F_75 ( V_51 ) ;
V_24 -> V_331 . V_614 = & V_24 -> V_614 ;
V_24 -> V_331 . V_162 = V_162 ;
V_24 -> V_37 . V_162 = V_162 ;
V_24 -> V_331 . V_209 = & V_619 -> V_637 ;
V_24 -> V_619 = V_619 ;
F_74 ( & V_619 -> V_638 ) ;
V_24 -> V_252 = F_125 ( V_252 ) ;
memcpy ( & V_24 -> V_614 , V_614 , sizeof( V_24 -> V_614 ) ) ;
V_24 -> V_43 = F_69 ( V_51 ) ;
return V_24 ;
}
static void F_353 ( void * V_132 )
{
struct V_634 * V_130 = V_132 ;
F_82 ( V_130 -> V_331 . V_162 ) ;
F_354 ( V_130 -> V_619 ) ;
F_136 ( V_130 -> V_252 ) ;
F_78 ( V_130 ) ;
}
static void F_355 ( struct V_100 * V_101 , void * V_132 )
{
struct V_634 * V_130 = V_132 ;
if ( ! F_38 ( V_101 , & V_130 -> V_37 . V_135 ) )
return;
switch ( V_101 -> V_113 ) {
case 0 :
F_97 ( & V_130 -> V_619 -> V_637 ,
& V_130 -> V_37 . V_209 ) ;
F_27 ( V_130 -> V_43 , V_130 -> V_84 ) ;
break;
case - V_59 :
case - V_79 :
case - V_61 :
case - V_60 :
break;
default:
if ( F_190 ( V_101 , V_130 -> V_43 , NULL ) == - V_129 )
F_35 ( V_101 ) ;
}
F_110 ( V_130 -> V_331 . V_162 ) ;
}
static void F_356 ( struct V_100 * V_101 , void * V_132 )
{
struct V_634 * V_130 = V_132 ;
if ( F_147 ( V_130 -> V_331 . V_162 , V_101 ) != 0 )
goto V_270;
if ( F_42 ( V_639 , & V_130 -> V_619 -> V_640 ) == 0 ) {
goto V_271;
}
V_130 -> V_84 = V_126 ;
if ( F_49 ( V_130 -> V_43 ,
& V_130 -> V_331 . V_134 ,
& V_130 -> V_37 . V_135 ,
V_101 ) != 0 )
F_110 ( V_130 -> V_331 . V_162 ) ;
return;
V_271:
V_101 -> V_277 = NULL ;
V_270:
F_38 ( V_101 , & V_130 -> V_37 . V_135 ) ;
}
static struct V_100 * F_357 ( struct V_611 * V_614 ,
struct V_251 * V_252 ,
struct V_618 * V_619 ,
struct V_635 * V_162 )
{
struct V_634 * V_132 ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_641 ] ,
. V_264 = V_252 -> V_292 ,
} ;
struct V_138 V_265 = {
. V_140 = F_231 ( V_619 -> V_636 -> V_51 ) ,
. V_136 = & V_137 ,
. V_141 = & V_642 ,
. V_267 = V_268 ,
. V_173 = V_269 ,
} ;
V_614 -> V_625 = V_626 ;
V_132 = F_352 ( V_614 , V_252 , V_619 , V_162 ) ;
if ( V_132 == NULL ) {
F_82 ( V_162 ) ;
return F_45 ( - V_125 ) ;
}
F_39 ( & V_132 -> V_331 . V_134 , & V_132 -> V_37 . V_135 , 1 ) ;
V_137 . V_262 = & V_132 -> V_331 ;
V_137 . V_263 = & V_132 -> V_37 ;
V_265 . V_143 = V_132 ;
return F_54 ( & V_265 ) ;
}
static int F_358 ( struct V_49 * V_50 , int V_610 , struct V_611 * V_612 )
{
struct V_51 * V_51 = V_50 -> V_51 ;
struct V_170 * V_171 = V_50 -> V_181 ;
struct V_149 * V_150 = F_61 ( V_51 ) ;
struct V_635 * V_162 ;
struct V_618 * V_619 ;
struct V_100 * V_101 ;
int V_256 = 0 ;
unsigned char V_631 = V_612 -> V_631 ;
V_256 = F_346 ( V_50 , V_612 ) ;
V_612 -> V_631 |= V_643 ;
F_359 ( & V_171 -> V_644 ) ;
F_360 ( & V_150 -> V_645 ) ;
if ( F_348 ( V_612 -> V_646 , V_612 ) == - V_253 ) {
F_361 ( & V_150 -> V_645 ) ;
F_362 ( & V_171 -> V_644 ) ;
goto V_105;
}
F_361 ( & V_150 -> V_645 ) ;
F_362 ( & V_171 -> V_644 ) ;
if ( V_256 != 0 )
goto V_105;
if ( F_42 ( V_226 , & V_50 -> V_173 ) )
goto V_105;
V_619 = V_612 -> V_621 . V_622 . V_181 ;
V_162 = F_71 ( & V_619 -> V_623 , V_319 ) ;
V_256 = - V_125 ;
if ( V_162 == NULL )
goto V_105;
V_101 = F_357 ( V_612 , F_224 ( V_612 -> V_646 ) , V_619 , V_162 ) ;
V_256 = F_55 ( V_101 ) ;
if ( F_44 ( V_101 ) )
goto V_105;
V_256 = F_89 ( V_101 ) ;
F_56 ( V_101 ) ;
V_105:
V_612 -> V_631 = V_631 ;
return V_256 ;
}
static struct V_647 * F_363 ( struct V_611 * V_614 ,
struct V_251 * V_252 , struct V_618 * V_619 ,
T_4 V_176 )
{
struct V_647 * V_24 ;
struct V_51 * V_51 = V_619 -> V_636 -> V_51 ;
struct V_42 * V_43 = F_69 ( V_51 ) ;
V_24 = F_70 ( sizeof( * V_24 ) , V_176 ) ;
if ( V_24 == NULL )
return NULL ;
V_24 -> V_331 . V_183 = F_75 ( V_51 ) ;
V_24 -> V_331 . V_614 = & V_24 -> V_614 ;
V_24 -> V_331 . V_648 = F_71 ( & V_619 -> V_636 -> V_181 -> V_178 , V_176 ) ;
if ( V_24 -> V_331 . V_648 == NULL )
goto V_258;
V_24 -> V_331 . V_649 = F_71 ( & V_619 -> V_623 , V_176 ) ;
if ( V_24 -> V_331 . V_649 == NULL )
goto V_650;
V_24 -> V_331 . V_651 = & V_619 -> V_637 ;
V_24 -> V_331 . V_620 . V_191 = V_43 -> V_47 -> V_192 ;
V_24 -> V_331 . V_620 . V_193 = V_619 -> V_623 . V_196 ;
V_24 -> V_331 . V_620 . V_624 = V_43 -> V_624 ;
V_24 -> V_37 . V_649 = V_24 -> V_331 . V_649 ;
V_24 -> V_619 = V_619 ;
V_24 -> V_43 = V_43 ;
F_74 ( & V_619 -> V_638 ) ;
V_24 -> V_252 = F_125 ( V_252 ) ;
memcpy ( & V_24 -> V_614 , V_614 , sizeof( V_24 -> V_614 ) ) ;
return V_24 ;
V_650:
F_82 ( V_24 -> V_331 . V_648 ) ;
V_258:
F_78 ( V_24 ) ;
return NULL ;
}
static void F_364 ( struct V_100 * V_101 , void * V_130 )
{
struct V_647 * V_132 = V_130 ;
struct V_49 * V_50 = V_132 -> V_619 -> V_636 ;
F_2 ( L_24 , V_16 ) ;
if ( F_147 ( V_132 -> V_331 . V_649 , V_101 ) != 0 )
goto V_270;
if ( ! ( V_132 -> V_331 . V_649 -> V_652 -> V_173 & V_653 ) ) {
if ( F_147 ( V_132 -> V_331 . V_648 , V_101 ) != 0 ) {
goto V_654;
}
V_132 -> V_331 . V_227 = & V_50 -> V_209 ;
V_132 -> V_331 . V_655 = 1 ;
V_132 -> V_37 . V_648 = V_132 -> V_331 . V_648 ;
} else
V_132 -> V_331 . V_655 = 0 ;
V_132 -> V_84 = V_126 ;
if ( F_49 ( V_132 -> V_43 ,
& V_132 -> V_331 . V_134 ,
& V_132 -> V_37 . V_135 ,
V_101 ) == 0 )
return;
F_110 ( V_132 -> V_331 . V_648 ) ;
V_654:
F_110 ( V_132 -> V_331 . V_649 ) ;
V_270:
F_38 ( V_101 , & V_132 -> V_37 . V_135 ) ;
F_2 ( L_44 , V_16 , V_132 -> V_241 ) ;
}
static void F_365 ( struct V_100 * V_101 , void * V_130 )
{
struct V_647 * V_132 = V_130 ;
F_2 ( L_24 , V_16 ) ;
if ( ! F_38 ( V_101 , & V_132 -> V_37 . V_135 ) )
return;
V_132 -> V_241 = V_101 -> V_113 ;
if ( V_132 -> V_331 . V_655 != 0 ) {
if ( V_132 -> V_241 == 0 )
F_141 ( & V_132 -> V_619 -> V_623 , 0 ) ;
else
goto V_105;
}
if ( V_132 -> V_241 == 0 ) {
F_97 ( & V_132 -> V_619 -> V_637 , & V_132 -> V_37 . V_209 ) ;
F_98 ( V_639 , & V_132 -> V_619 -> V_640 ) ;
F_27 ( F_69 ( V_132 -> V_252 -> V_20 -> V_29 ) , V_132 -> V_84 ) ;
}
V_105:
F_2 ( L_25 , V_16 , V_132 -> V_241 ) ;
}
static void F_366 ( void * V_130 )
{
struct V_647 * V_132 = V_130 ;
F_2 ( L_24 , V_16 ) ;
F_82 ( V_132 -> V_331 . V_648 ) ;
if ( V_132 -> V_257 != 0 ) {
struct V_100 * V_101 ;
V_101 = F_357 ( & V_132 -> V_614 , V_132 -> V_252 , V_132 -> V_619 ,
V_132 -> V_331 . V_649 ) ;
if ( ! F_44 ( V_101 ) )
F_367 ( V_101 ) ;
F_2 ( L_45 , V_16 ) ;
} else
F_82 ( V_132 -> V_331 . V_649 ) ;
F_354 ( V_132 -> V_619 ) ;
F_136 ( V_132 -> V_252 ) ;
F_78 ( V_132 ) ;
F_2 ( L_26 , V_16 ) ;
}
static void F_368 ( struct V_42 * V_43 , struct V_618 * V_619 , int V_655 , int error )
{
switch ( error ) {
case - V_58 :
case - V_59 :
V_619 -> V_623 . V_173 &= ~ V_653 ;
if ( V_655 != 0 ||
F_42 ( V_639 , & V_619 -> V_640 ) != 0 )
F_16 ( V_43 , V_619 -> V_636 ) ;
break;
case - V_61 :
V_619 -> V_623 . V_173 &= ~ V_653 ;
case - V_60 :
F_18 ( V_43 -> V_47 ) ;
} ;
}
static int F_369 ( struct V_49 * V_50 , int V_610 , struct V_611 * V_614 , int V_656 )
{
struct V_647 * V_132 ;
struct V_100 * V_101 ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_657 ] ,
. V_264 = V_50 -> V_181 -> V_237 ,
} ;
struct V_138 V_265 = {
. V_140 = F_231 ( V_50 -> V_51 ) ,
. V_136 = & V_137 ,
. V_141 = & V_658 ,
. V_267 = V_268 ,
. V_173 = V_269 ,
} ;
int V_52 ;
F_2 ( L_24 , V_16 ) ;
V_132 = F_363 ( V_614 , F_224 ( V_614 -> V_646 ) ,
V_614 -> V_621 . V_622 . V_181 ,
V_656 == V_659 ? V_319 : V_254 ) ;
if ( V_132 == NULL )
return - V_125 ;
if ( F_370 ( V_610 ) )
V_132 -> V_331 . V_660 = 1 ;
F_39 ( & V_132 -> V_331 . V_134 , & V_132 -> V_37 . V_135 , 1 ) ;
V_137 . V_262 = & V_132 -> V_331 ;
V_137 . V_263 = & V_132 -> V_37 ;
V_265 . V_143 = V_132 ;
if ( V_656 > V_659 ) {
if ( V_656 == V_661 )
V_132 -> V_331 . V_662 = V_661 ;
F_40 ( & V_132 -> V_331 . V_134 ) ;
}
V_101 = F_54 ( & V_265 ) ;
if ( F_44 ( V_101 ) )
return F_55 ( V_101 ) ;
V_52 = F_89 ( V_101 ) ;
if ( V_52 == 0 ) {
V_52 = V_132 -> V_241 ;
if ( V_52 )
F_368 ( V_132 -> V_43 , V_132 -> V_619 ,
V_132 -> V_331 . V_655 , V_52 ) ;
} else
V_132 -> V_257 = 1 ;
F_56 ( V_101 ) ;
F_2 ( L_25 , V_16 , V_52 ) ;
return V_52 ;
}
static int F_371 ( struct V_49 * V_50 , struct V_611 * V_612 )
{
struct V_42 * V_43 = F_69 ( V_50 -> V_51 ) ;
struct V_45 V_46 = {
. V_51 = V_50 -> V_51 ,
} ;
int V_1 ;
do {
if ( F_42 ( V_226 , & V_50 -> V_173 ) != 0 )
return 0 ;
V_1 = F_369 ( V_50 , V_663 , V_612 , V_661 ) ;
if ( V_1 != - V_76 )
break;
F_13 ( V_43 , V_1 , & V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static int F_372 ( struct V_49 * V_50 , struct V_611 * V_612 )
{
struct V_42 * V_43 = F_69 ( V_50 -> V_51 ) ;
struct V_45 V_46 = {
. V_51 = V_50 -> V_51 ,
} ;
int V_1 ;
V_1 = F_346 ( V_50 , V_612 ) ;
if ( V_1 != 0 )
return V_1 ;
do {
if ( F_42 ( V_226 , & V_50 -> V_173 ) != 0 )
return 0 ;
V_1 = F_369 ( V_50 , V_663 , V_612 , V_664 ) ;
switch ( V_1 ) {
default:
goto V_105;
case - V_75 :
case - V_76 :
F_13 ( V_43 , V_1 , & V_46 ) ;
V_1 = 0 ;
}
} while ( V_46 . V_53 );
V_105:
return V_1 ;
}
static int F_373 ( struct V_49 * V_50 )
{
int V_256 , V_52 = - V_59 ;
struct V_618 * V_619 ;
struct V_42 * V_43 = F_69 ( V_50 -> V_51 ) ;
F_124 (lsp, &state->lock_states, ls_locks) {
if ( F_42 ( V_639 , & V_619 -> V_640 ) ) {
V_256 = F_165 ( V_43 , & V_619 -> V_637 ) ;
if ( V_256 != V_305 ) {
if ( V_256 != - V_59 )
F_166 ( V_43 ,
& V_619 -> V_637 ) ;
F_131 ( V_639 , & V_619 -> V_640 ) ;
V_52 = V_256 ;
}
}
} ;
return V_52 ;
}
static int F_374 ( struct V_49 * V_50 , struct V_611 * V_612 )
{
int V_256 = V_305 ;
if ( F_42 ( V_665 , & V_50 -> V_173 ) )
V_256 = F_373 ( V_50 ) ;
if ( V_256 != V_305 )
V_256 = F_372 ( V_50 , V_612 ) ;
return V_256 ;
}
static int F_375 ( struct V_49 * V_50 , int V_610 , struct V_611 * V_612 )
{
struct V_170 * V_171 = V_50 -> V_181 ;
struct V_149 * V_150 = F_61 ( V_50 -> V_51 ) ;
unsigned char V_631 = V_612 -> V_631 ;
unsigned int V_314 ;
int V_256 = - V_666 ;
if ( ( V_631 & V_632 ) &&
! F_42 ( V_316 , & V_50 -> V_173 ) )
goto V_105;
V_256 = F_346 ( V_50 , V_612 ) ;
if ( V_256 != 0 )
goto V_105;
V_612 -> V_631 |= V_667 ;
V_256 = F_348 ( V_612 -> V_646 , V_612 ) ;
if ( V_256 < 0 )
goto V_105;
F_360 ( & V_150 -> V_645 ) ;
if ( F_42 ( V_226 , & V_50 -> V_173 ) ) {
V_612 -> V_631 = V_631 & ~ V_668 ;
V_256 = F_348 ( V_612 -> V_646 , V_612 ) ;
goto V_98;
}
V_314 = F_171 ( & V_171 -> V_315 ) ;
F_361 ( & V_150 -> V_645 ) ;
V_256 = F_369 ( V_50 , V_610 , V_612 , V_659 ) ;
if ( V_256 != 0 )
goto V_105;
F_360 ( & V_150 -> V_645 ) ;
if ( F_172 ( & V_171 -> V_315 , V_314 ) ) {
V_256 = - V_76 ;
goto V_98;
}
V_612 -> V_631 = V_631 | V_668 ;
if ( F_348 ( V_612 -> V_646 , V_612 ) < 0 )
F_21 ( V_82 L_46
L_47 , V_16 ) ;
V_98:
F_361 ( & V_150 -> V_645 ) ;
V_105:
V_612 -> V_631 = V_631 ;
return V_256 ;
}
static int F_376 ( struct V_49 * V_50 , int V_610 , struct V_611 * V_612 )
{
struct V_45 V_46 = {
. V_50 = V_50 ,
. V_51 = V_50 -> V_51 ,
} ;
int V_1 ;
do {
V_1 = F_375 ( V_50 , V_610 , V_612 ) ;
if ( V_1 == - V_627 )
V_1 = - V_129 ;
V_1 = F_13 ( F_69 ( V_50 -> V_51 ) ,
V_1 , & V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static int
F_377 ( struct V_630 * V_669 , int V_610 , struct V_611 * V_612 )
{
struct V_251 * V_252 ;
struct V_49 * V_50 ;
unsigned long V_36 = V_670 ;
int V_256 ;
V_252 = F_224 ( V_669 ) ;
V_50 = V_252 -> V_50 ;
if ( V_612 -> V_671 < 0 || V_612 -> V_672 < 0 )
return - V_10 ;
if ( F_378 ( V_610 ) ) {
if ( V_50 != NULL )
return F_347 ( V_50 , V_673 , V_612 ) ;
return 0 ;
}
if ( ! ( F_379 ( V_610 ) || F_370 ( V_610 ) ) )
return - V_10 ;
if ( V_612 -> V_625 == V_626 ) {
if ( V_50 != NULL )
return F_358 ( V_50 , V_610 , V_612 ) ;
return 0 ;
}
if ( V_50 == NULL )
return - V_666 ;
switch ( V_612 -> V_625 ) {
case V_674 :
if ( ! ( V_669 -> V_675 & V_55 ) )
return - V_342 ;
break;
case V_676 :
if ( ! ( V_669 -> V_675 & V_185 ) )
return - V_342 ;
}
do {
V_256 = F_376 ( V_50 , V_610 , V_612 ) ;
if ( ( V_256 != - V_129 ) || F_379 ( V_610 ) )
break;
V_36 = F_344 ( V_36 ) ;
V_256 = - V_41 ;
if ( F_380 () )
break;
} while( V_256 < 0 );
return V_256 ;
}
int F_381 ( struct V_49 * V_50 , struct V_611 * V_614 )
{
struct V_42 * V_43 = F_69 ( V_50 -> V_51 ) ;
struct V_45 V_46 = { } ;
int V_1 ;
V_1 = F_346 ( V_50 , V_614 ) ;
if ( V_1 != 0 )
goto V_105;
do {
V_1 = F_369 ( V_50 , V_663 , V_614 , V_659 ) ;
switch ( V_1 ) {
default:
F_21 ( V_677 L_48
L_49 , V_16 , V_1 ) ;
case 0 :
case - V_242 :
goto V_105;
case - V_62 :
case - V_61 :
F_98 ( V_226 , & V_50 -> V_173 ) ;
case - V_60 :
F_18 ( V_43 -> V_47 ) ;
V_1 = - V_129 ;
goto V_105;
case - V_64 :
case - V_65 :
case - V_66 :
case - V_67 :
case - V_68 :
F_98 ( V_226 , & V_50 -> V_173 ) ;
F_20 ( V_43 -> V_47 -> V_71 , V_1 ) ;
V_1 = - V_129 ;
goto V_105;
case - V_57 :
case - V_58 :
case - V_59 :
case - V_54 :
F_16 ( V_43 , V_50 ) ;
V_1 = 0 ;
goto V_105;
case - V_125 :
case - V_627 :
V_1 = 0 ;
goto V_105;
}
F_98 ( V_226 , & V_50 -> V_173 ) ;
V_1 = F_13 ( V_43 , V_1 , & V_46 ) ;
} while ( V_46 . V_53 );
V_105:
return V_1 ;
}
static void F_382 ( void * V_130 )
{
struct V_678 * V_132 = V_130 ;
F_383 ( V_132 -> V_43 , V_132 -> V_619 ) ;
F_78 ( V_130 ) ;
}
int F_384 ( struct V_618 * V_619 )
{
struct V_42 * V_43 = V_619 -> V_636 -> V_181 -> V_273 ;
struct V_678 * V_132 ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_679 ] ,
} ;
if ( V_43 -> V_47 -> V_144 -> V_398 != 0 )
return - V_10 ;
V_132 = F_217 ( sizeof( * V_132 ) , V_254 ) ;
if ( ! V_132 )
return - V_125 ;
V_132 -> V_619 = V_619 ;
V_132 -> V_43 = V_43 ;
V_132 -> args . V_620 . V_191 = V_43 -> V_47 -> V_192 ;
V_132 -> args . V_620 . V_193 = V_619 -> V_623 . V_196 ;
V_132 -> args . V_620 . V_624 = V_43 -> V_624 ;
V_137 . V_262 = & V_132 -> args ;
F_308 ( V_43 -> V_77 , & V_137 , 0 , & V_680 , V_132 ) ;
return 0 ;
}
static int F_385 ( struct V_20 * V_20 , const char * V_681 ,
const void * V_524 , T_9 V_525 ,
int V_173 , int type )
{
if ( strcmp ( V_681 , L_50 ) != 0 )
return - V_10 ;
return F_328 ( V_20 -> V_29 , V_524 , V_525 ) ;
}
static int F_386 ( struct V_20 * V_20 , const char * V_681 ,
void * V_524 , T_9 V_525 , int type )
{
if ( strcmp ( V_681 , L_50 ) != 0 )
return - V_10 ;
return F_322 ( V_20 -> V_29 , V_524 , V_525 ) ;
}
static T_9 F_387 ( struct V_20 * V_20 , char * V_682 ,
T_9 V_683 , const char * V_197 ,
T_9 V_684 , int type )
{
T_9 V_394 = sizeof( V_685 ) ;
if ( ! F_310 ( F_69 ( V_20 -> V_29 ) ) )
return 0 ;
if ( V_682 && V_394 <= V_683 )
memcpy ( V_682 , V_685 , V_394 ) ;
return V_394 ;
}
static void F_219 ( struct V_328 * V_329 )
{
if ( ! ( ( ( V_329 -> V_243 & V_686 ) ||
( V_329 -> V_243 & V_245 ) ) &&
( V_329 -> V_243 & V_403 ) &&
( V_329 -> V_243 & V_687 ) ) )
return;
V_329 -> V_243 |= V_244 | V_418 |
V_419 | V_688 ;
V_329 -> V_213 = V_282 | V_421 | V_422 ;
V_329 -> V_423 = 2 ;
}
static int F_388 ( struct V_34 * V_77 , struct V_51 * V_146 ,
const struct V_405 * V_197 ,
struct V_407 * V_689 ,
struct V_406 * V_406 )
{
struct V_42 * V_43 = F_69 ( V_146 ) ;
T_6 V_199 [ 2 ] = {
[ 0 ] = V_690 | V_691 ,
} ;
struct V_692 args = {
. V_416 = F_75 ( V_146 ) ,
. V_197 = V_197 ,
. V_406 = V_406 ,
. V_199 = V_199 ,
} ;
struct V_693 V_37 = {
. V_689 = V_689 ,
} ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_694 ] ,
. V_262 = & args ,
. V_263 = & V_37 ,
} ;
int V_256 ;
F_2 ( L_51 , V_16 ) ;
if ( F_69 ( V_146 ) -> V_200 [ 1 ] & V_695 )
V_199 [ 1 ] |= V_695 ;
else
V_199 [ 0 ] |= V_28 ;
F_65 ( & V_689 -> V_329 ) ;
V_689 -> V_43 = V_43 ;
V_689 -> V_696 = 0 ;
V_256 = F_59 ( V_77 , V_43 , & V_137 , & args . V_134 , & V_37 . V_135 , 0 ) ;
F_2 ( L_52 , V_16 , V_256 ) ;
return V_256 ;
}
int F_218 ( struct V_34 * V_77 , struct V_51 * V_146 ,
const struct V_405 * V_197 ,
struct V_407 * V_689 ,
struct V_406 * V_406 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_69 ( V_146 ) ,
F_388 ( V_77 , V_146 , V_197 , V_689 , V_406 ) ,
& V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static int F_389 ( struct V_51 * V_146 , const struct V_405 * V_197 , struct V_697 * V_698 )
{
int V_256 ;
struct V_699 args = {
. V_416 = F_75 ( V_146 ) ,
. V_197 = V_197 ,
} ;
struct V_700 V_37 = {
. V_698 = V_698 ,
} ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_701 ] ,
. V_262 = & args ,
. V_263 = & V_37 ,
} ;
F_2 ( L_53 , V_197 -> V_197 ) ;
V_256 = F_59 ( F_69 ( V_146 ) -> V_77 , F_69 ( V_146 ) , & V_137 , & args . V_134 , & V_37 . V_135 , 0 ) ;
F_2 ( L_54 , V_256 ) ;
return V_256 ;
}
int F_390 ( struct V_51 * V_146 , const struct V_405 * V_197 ,
struct V_697 * V_698 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_69 ( V_146 ) ,
F_389 ( V_146 , V_197 , V_698 ) ,
& V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static int F_391 ( T_6 V_173 )
{
if ( V_173 & ~ V_702 )
goto V_703;
if ( ( V_173 & V_704 ) &&
( V_173 & V_705 ) )
goto V_703;
if ( ! ( V_173 & ( V_706 ) ) )
goto V_703;
return V_305 ;
V_703:
return - V_707 ;
}
static bool
F_392 ( struct V_708 * V_709 ,
struct V_708 * V_710 )
{
if ( V_709 -> V_711 == V_710 -> V_711 &&
memcmp ( V_709 -> V_712 , V_710 -> V_712 , V_709 -> V_711 ) == 0 )
return true ;
return false ;
}
int F_393 ( struct V_47 * V_48 , struct V_264 * V_292 )
{
int V_256 ;
struct V_713 V_37 ;
struct V_136 V_137 = {
. V_259 =
& V_260 [ V_714 ] ,
. V_262 = V_48 ,
. V_263 = & V_37 ,
. V_264 = V_292 ,
} ;
F_2 ( L_12 , V_16 ) ;
V_37 . V_89 = F_70 ( sizeof( struct V_88 ) , V_254 ) ;
if ( F_394 ( V_37 . V_89 == NULL ) ) {
V_256 = - V_125 ;
goto V_105;
}
V_256 = F_58 ( V_48 -> V_518 , & V_137 , V_600 ) ;
if ( V_256 == 0 ) {
if ( memcmp ( V_37 . V_89 -> V_715 . V_132 ,
V_48 -> V_71 -> V_715 . V_132 , V_716 ) ) {
F_2 ( L_55 , V_16 ) ;
V_256 = - V_17 ;
goto V_717;
}
if ( V_37 . V_146 != V_718 ) {
F_2 ( L_56 ,
V_16 ) ;
V_256 = - V_17 ;
goto V_717;
}
if ( V_37 . V_719 ) {
F_2 ( L_57 ,
V_16 ) ;
V_256 = - V_17 ;
goto V_717;
}
}
V_717:
F_78 ( V_37 . V_89 ) ;
V_105:
F_2 ( L_58 , V_16 , V_256 ) ;
return V_256 ;
}
int F_395 ( struct V_47 * V_48 , struct V_264 * V_292 )
{
T_11 V_19 ;
struct V_720 args = {
. V_19 = & V_19 ,
. V_77 = V_48 ,
. V_173 = V_721 ,
} ;
struct V_722 V_37 = {
0
} ;
int V_256 ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_723 ] ,
. V_262 = & args ,
. V_263 = & V_37 ,
. V_264 = V_292 ,
} ;
F_331 ( V_48 , & V_19 ) ;
args . V_724 = F_336 ( V_48 , args . V_193 ,
sizeof( args . V_193 ) ) ;
F_2 ( L_59 ,
V_48 -> V_518 -> V_597 -> V_598 -> V_599 ,
args . V_724 , args . V_193 ) ;
V_37 . V_725 = F_70 ( sizeof( struct V_726 ) ,
V_254 ) ;
if ( F_394 ( V_37 . V_725 == NULL ) ) {
V_256 = - V_125 ;
goto V_105;
}
V_37 . V_712 = F_70 ( sizeof( struct V_708 ) ,
V_254 ) ;
if ( F_394 ( V_37 . V_712 == NULL ) ) {
V_256 = - V_125 ;
goto V_727;
}
V_37 . V_728 = F_70 ( sizeof( struct V_729 ) , V_254 ) ;
if ( F_394 ( V_37 . V_728 == NULL ) ) {
V_256 = - V_125 ;
goto V_730;
}
V_256 = F_58 ( V_48 -> V_518 , & V_137 , V_600 ) ;
if ( V_256 == 0 )
V_256 = F_391 ( V_37 . V_173 ) ;
if ( V_256 == 0 ) {
V_48 -> V_192 = V_37 . V_191 ;
V_48 -> V_731 = ( V_37 . V_173 & ~ V_732 ) ;
if ( ! ( V_37 . V_173 & V_732 ) )
V_48 -> V_733 = V_37 . V_162 ;
F_78 ( V_48 -> V_734 ) ;
V_48 -> V_734 = V_37 . V_725 ;
V_37 . V_725 = NULL ;
F_78 ( V_48 -> V_735 ) ;
V_48 -> V_735 = V_37 . V_728 ;
if ( V_48 -> V_736 != NULL &&
! F_392 ( V_48 -> V_736 ,
V_37 . V_712 ) ) {
F_2 ( L_60 ,
V_16 ) ;
F_98 ( V_737 , & V_48 -> V_558 ) ;
F_78 ( V_48 -> V_736 ) ;
V_48 -> V_736 = NULL ;
}
if ( V_48 -> V_736 == NULL ) {
V_48 -> V_736 = V_37 . V_712 ;
goto V_105;
}
} else
F_78 ( V_37 . V_728 ) ;
V_727:
F_78 ( V_37 . V_725 ) ;
V_730:
F_78 ( V_37 . V_712 ) ;
V_105:
if ( V_48 -> V_735 != NULL )
F_2 ( L_61
L_62 ,
V_48 -> V_735 -> V_738 , V_48 -> V_735 -> V_197 ,
V_48 -> V_735 -> V_739 . V_740 ,
V_48 -> V_735 -> V_739 . V_741 ) ;
F_2 ( L_63 , V_256 ) ;
return V_256 ;
}
static int F_396 ( struct V_47 * V_48 ,
struct V_264 * V_292 )
{
struct V_136 V_137 = {
. V_259 = & V_260 [ V_742 ] ,
. V_262 = V_48 ,
. V_264 = V_292 ,
} ;
int V_256 ;
V_256 = F_58 ( V_48 -> V_518 , & V_137 , V_600 ) ;
if ( V_256 )
F_2 ( L_64
L_65 , V_256 , V_48 -> V_83 ) ;
return V_256 ;
}
static int F_397 ( struct V_47 * V_48 ,
struct V_264 * V_292 )
{
unsigned int V_743 ;
int V_52 ;
for ( V_743 = V_744 ; V_743 != 0 ; V_743 -- ) {
V_52 = F_396 ( V_48 , V_292 ) ;
switch ( V_52 ) {
case - V_76 :
case - V_745 :
F_398 ( 1 ) ;
break;
default:
return V_52 ;
}
}
return 0 ;
}
int F_399 ( struct V_47 * V_48 )
{
struct V_264 * V_292 ;
int V_52 = 0 ;
if ( V_48 -> V_144 -> V_398 < 1 )
goto V_105;
if ( V_48 -> V_731 == 0 )
goto V_105;
if ( V_48 -> V_746 )
goto V_105;
V_292 = F_400 ( V_48 ) ;
V_52 = F_397 ( V_48 , V_292 ) ;
if ( V_292 )
F_401 ( V_292 ) ;
switch ( V_52 ) {
case 0 :
case - V_62 :
V_48 -> V_731 = 0 ;
}
V_105:
return V_52 ;
}
static void F_402 ( struct V_100 * V_101 ,
void * V_130 )
{
struct V_747 * V_132 =
(struct V_747 * ) V_130 ;
F_2 ( L_12 , V_16 ) ;
F_41 ( V_132 -> V_48 -> V_71 ,
& V_132 -> args -> V_748 ,
& V_132 -> V_37 -> V_749 ,
V_101 ) ;
F_2 ( L_66 , V_16 ) ;
}
static void F_403 ( struct V_100 * V_101 , void * V_130 )
{
struct V_747 * V_132 =
(struct V_747 * ) V_130 ;
F_2 ( L_12 , V_16 ) ;
if ( ! F_32 ( V_101 , & V_132 -> V_37 -> V_749 ) )
return;
switch ( V_101 -> V_113 ) {
case - V_76 :
case - V_75 :
F_2 ( L_67 , V_16 , V_101 -> V_113 ) ;
F_37 ( V_101 , V_38 ) ;
V_101 -> V_113 = 0 ;
case - V_78 :
F_35 ( V_101 ) ;
return;
}
F_2 ( L_66 , V_16 ) ;
}
int F_404 ( struct V_47 * V_48 , struct V_385 * V_483 )
{
struct V_100 * V_101 ;
struct V_750 args ;
struct V_751 V_37 = {
. V_752 = V_483 ,
} ;
struct V_747 V_132 = {
. args = & args ,
. V_37 = & V_37 ,
. V_48 = V_48 ,
} ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_753 ] ,
. V_262 = & args ,
. V_263 = & V_37 ,
} ;
struct V_138 V_139 = {
. V_140 = V_48 -> V_518 ,
. V_136 = & V_137 ,
. V_141 = & V_754 ,
. V_143 = & V_132 ,
. V_173 = V_600 ,
} ;
int V_256 ;
F_39 ( & args . V_748 , & V_37 . V_749 , 0 ) ;
F_40 ( & args . V_748 ) ;
F_2 ( L_12 , V_16 ) ;
V_101 = F_54 ( & V_139 ) ;
if ( F_44 ( V_101 ) )
V_256 = F_55 ( V_101 ) ;
else {
V_256 = V_101 -> V_113 ;
F_56 ( V_101 ) ;
}
F_2 ( L_68 , V_16 , V_256 ) ;
return V_256 ;
}
static void F_405 ( struct V_755 * args )
{
struct V_88 * V_89 = args -> V_77 -> V_71 ;
unsigned int V_756 = V_89 -> V_757 ,
V_758 = V_89 -> V_759 ;
if ( V_756 == 0 )
V_756 = V_760 ;
if ( V_758 == 0 )
V_758 = V_760 ;
args -> V_761 . V_762 = V_756 ;
args -> V_761 . V_763 = V_758 ;
args -> V_761 . V_764 = V_765 ;
args -> V_761 . V_766 = V_767 ;
F_2 ( L_69
L_70 ,
V_16 ,
args -> V_761 . V_762 , args -> V_761 . V_763 ,
args -> V_761 . V_764 , args -> V_761 . V_766 ) ;
args -> V_768 . V_762 = V_529 ;
args -> V_768 . V_763 = V_529 ;
args -> V_768 . V_769 = 0 ;
args -> V_768 . V_764 = V_770 ;
args -> V_768 . V_766 = 1 ;
F_2 ( L_71
L_72 ,
V_16 ,
args -> V_768 . V_762 , args -> V_768 . V_763 ,
args -> V_768 . V_769 , args -> V_768 . V_764 ,
args -> V_768 . V_766 ) ;
}
static int F_406 ( struct V_755 * args , struct V_88 * V_89 )
{
struct V_771 * V_772 = & args -> V_761 ;
struct V_771 * V_773 = & V_89 -> V_761 ;
if ( V_773 -> V_763 > V_772 -> V_763 )
return - V_10 ;
if ( V_773 -> V_764 < V_772 -> V_764 )
return - V_10 ;
if ( V_773 -> V_766 == 0 )
return - V_10 ;
if ( V_773 -> V_766 > V_774 )
V_773 -> V_766 = V_774 ;
return 0 ;
}
static int F_407 ( struct V_755 * args , struct V_88 * V_89 )
{
struct V_771 * V_772 = & args -> V_768 ;
struct V_771 * V_773 = & V_89 -> V_768 ;
if ( V_773 -> V_762 > V_772 -> V_762 )
return - V_10 ;
if ( V_773 -> V_763 < V_772 -> V_763 )
return - V_10 ;
if ( V_773 -> V_769 > V_772 -> V_769 )
return - V_10 ;
if ( V_773 -> V_764 != V_772 -> V_764 )
return - V_10 ;
if ( V_773 -> V_766 != V_772 -> V_766 )
return - V_10 ;
return 0 ;
}
static int F_408 ( struct V_755 * args ,
struct V_88 * V_89 )
{
int V_52 ;
V_52 = F_406 ( args , V_89 ) ;
if ( V_52 )
return V_52 ;
return F_407 ( args , V_89 ) ;
}
static int F_409 ( struct V_47 * V_48 ,
struct V_264 * V_292 )
{
struct V_88 * V_89 = V_48 -> V_71 ;
struct V_755 args = {
. V_77 = V_48 ,
. V_775 = V_776 ,
} ;
struct V_777 V_37 = {
. V_77 = V_48 ,
} ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_778 ] ,
. V_262 = & args ,
. V_263 = & V_37 ,
. V_264 = V_292 ,
} ;
int V_256 ;
F_405 ( & args ) ;
args . V_173 = ( V_779 | V_780 ) ;
V_256 = F_58 ( V_89 -> V_48 -> V_518 , & V_137 , V_600 ) ;
if ( ! V_256 ) {
V_256 = F_408 ( & args , V_89 ) ;
V_48 -> V_733 ++ ;
}
return V_256 ;
}
int F_410 ( struct V_47 * V_48 , struct V_264 * V_292 )
{
int V_256 ;
unsigned * V_781 ;
struct V_88 * V_89 = V_48 -> V_71 ;
F_2 ( L_73 , V_16 , V_48 , V_89 ) ;
V_256 = F_409 ( V_48 , V_292 ) ;
if ( V_256 )
goto V_105;
V_256 = F_411 ( V_89 ) ;
F_2 ( L_74 , V_256 ) ;
if ( V_256 )
goto V_105;
V_781 = ( unsigned * ) & V_89 -> V_715 . V_132 [ 0 ] ;
F_2 ( L_75 , V_16 ,
V_48 -> V_733 , V_781 [ 0 ] , V_781 [ 1 ] , V_781 [ 2 ] , V_781 [ 3 ] ) ;
V_105:
F_2 ( L_66 , V_16 ) ;
return V_256 ;
}
int F_412 ( struct V_88 * V_89 ,
struct V_264 * V_292 )
{
struct V_136 V_137 = {
. V_259 = & V_260 [ V_782 ] ,
. V_262 = V_89 ,
. V_264 = V_292 ,
} ;
int V_256 = 0 ;
F_2 ( L_76 ) ;
if ( V_89 -> V_48 -> V_783 != V_784 )
return V_256 ;
V_256 = F_58 ( V_89 -> V_48 -> V_518 , & V_137 , V_600 ) ;
if ( V_256 )
F_2 ( L_77
L_78 , V_256 ) ;
F_2 ( L_79 ) ;
return V_256 ;
}
static void F_413 ( void * V_132 )
{
struct V_785 * V_130 = V_132 ;
struct V_47 * V_48 = V_130 -> V_48 ;
if ( F_301 ( & V_48 -> V_512 ) > 1 )
F_302 ( V_48 ) ;
F_303 ( V_48 ) ;
F_78 ( V_130 ) ;
}
static int F_414 ( struct V_100 * V_101 , struct V_47 * V_48 )
{
switch( V_101 -> V_113 ) {
case - V_76 :
F_37 ( V_101 , V_39 ) ;
return - V_129 ;
default:
F_18 ( V_48 ) ;
}
return 0 ;
}
static void F_415 ( struct V_100 * V_101 , void * V_132 )
{
struct V_785 * V_130 = V_132 ;
struct V_47 * V_48 = V_130 -> V_48 ;
if ( ! F_32 ( V_101 , V_101 -> V_274 . V_263 ) )
return;
if ( V_101 -> V_113 < 0 ) {
F_2 ( L_80 , V_16 , V_101 -> V_113 ) ;
if ( F_301 ( & V_48 -> V_512 ) == 1 )
goto V_105;
if ( F_414 ( V_101 , V_48 ) == - V_129 ) {
F_35 ( V_101 ) ;
return;
}
}
F_2 ( L_81 , V_16 , V_101 -> V_274 . V_264 ) ;
V_105:
F_2 ( L_66 , V_16 ) ;
}
static void F_416 ( struct V_100 * V_101 , void * V_132 )
{
struct V_785 * V_130 = V_132 ;
struct V_47 * V_48 = V_130 -> V_48 ;
struct V_114 * args ;
struct V_87 * V_37 ;
args = V_101 -> V_274 . V_262 ;
V_37 = V_101 -> V_274 . V_263 ;
F_41 ( V_48 -> V_71 , args , V_37 , V_101 ) ;
}
static struct V_100 * F_417 ( struct V_47 * V_48 ,
struct V_264 * V_292 ,
bool V_786 )
{
struct V_785 * V_130 ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_787 ] ,
. V_264 = V_292 ,
} ;
struct V_138 V_265 = {
. V_140 = V_48 -> V_518 ,
. V_136 = & V_137 ,
. V_141 = & V_788 ,
. V_173 = V_269 | V_519 ,
} ;
if ( ! F_307 ( & V_48 -> V_512 ) )
return F_45 ( - V_17 ) ;
V_130 = F_70 ( sizeof( * V_130 ) , V_254 ) ;
if ( V_130 == NULL ) {
F_303 ( V_48 ) ;
return F_45 ( - V_125 ) ;
}
F_39 ( & V_130 -> args , & V_130 -> V_37 , 0 ) ;
if ( V_786 )
F_40 ( & V_130 -> args ) ;
V_137 . V_262 = & V_130 -> args ;
V_137 . V_263 = & V_130 -> V_37 ;
V_130 -> V_48 = V_48 ;
V_265 . V_143 = V_130 ;
return F_54 ( & V_265 ) ;
}
static int F_418 ( struct V_47 * V_48 , struct V_264 * V_292 , unsigned V_516 )
{
struct V_100 * V_101 ;
int V_52 = 0 ;
if ( ( V_516 & V_789 ) == 0 )
return 0 ;
V_101 = F_417 ( V_48 , V_292 , false ) ;
if ( F_44 ( V_101 ) )
V_52 = F_55 ( V_101 ) ;
else
F_367 ( V_101 ) ;
F_2 ( L_17 , V_16 , V_52 ) ;
return V_52 ;
}
static int F_419 ( struct V_47 * V_48 , struct V_264 * V_292 )
{
struct V_100 * V_101 ;
int V_52 ;
V_101 = F_417 ( V_48 , V_292 , true ) ;
if ( F_44 ( V_101 ) ) {
V_52 = F_55 ( V_101 ) ;
goto V_105;
}
V_52 = F_90 ( V_101 ) ;
if ( ! V_52 ) {
struct V_87 * V_37 = V_101 -> V_274 . V_263 ;
if ( V_101 -> V_113 == 0 )
F_420 ( V_48 , V_37 -> V_109 ) ;
V_52 = V_101 -> V_113 ;
}
F_56 ( V_101 ) ;
V_105:
F_2 ( L_17 , V_16 , V_52 ) ;
return V_52 ;
}
static void F_421 ( struct V_100 * V_101 , void * V_132 )
{
struct V_790 * V_130 = V_132 ;
F_41 ( V_130 -> V_48 -> V_71 ,
& V_130 -> V_331 . V_134 ,
& V_130 -> V_37 . V_135 ,
V_101 ) ;
}
static int F_422 ( struct V_100 * V_101 , struct V_47 * V_48 )
{
switch( V_101 -> V_113 ) {
case 0 :
case - V_791 :
case - V_792 :
break;
case - V_76 :
F_37 ( V_101 , V_39 ) ;
case - V_78 :
return - V_129 ;
default:
F_18 ( V_48 ) ;
}
return 0 ;
}
static void F_423 ( struct V_100 * V_101 , void * V_132 )
{
struct V_790 * V_130 = V_132 ;
struct V_47 * V_48 = V_130 -> V_48 ;
struct V_87 * V_37 = & V_130 -> V_37 . V_135 ;
F_2 ( L_12 , V_16 ) ;
if ( ! F_32 ( V_101 , V_37 ) )
return;
if ( F_422 ( V_101 , V_48 ) == - V_129 ) {
F_35 ( V_101 ) ;
return;
}
F_2 ( L_66 , V_16 ) ;
}
static void F_424 ( void * V_132 )
{
struct V_790 * V_130 = V_132 ;
F_78 ( V_130 ) ;
}
static int F_425 ( struct V_47 * V_48 )
{
struct V_790 * V_130 ;
struct V_100 * V_101 ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_793 ] ,
} ;
struct V_138 V_265 = {
. V_140 = V_48 -> V_518 ,
. V_136 = & V_137 ,
. V_141 = & V_794 ,
. V_173 = V_269 ,
} ;
int V_256 = - V_125 ;
F_2 ( L_12 , V_16 ) ;
V_130 = F_70 ( sizeof( * V_130 ) , V_254 ) ;
if ( V_130 == NULL )
goto V_105;
V_130 -> V_48 = V_48 ;
V_130 -> V_331 . V_795 = 0 ;
F_39 ( & V_130 -> V_331 . V_134 , & V_130 -> V_37 . V_135 , 0 ) ;
F_40 ( & V_130 -> V_331 . V_134 ) ;
V_137 . V_262 = & V_130 -> V_331 ;
V_137 . V_263 = & V_130 -> V_37 ;
V_265 . V_143 = V_130 ;
V_101 = F_54 ( & V_265 ) ;
if ( F_44 ( V_101 ) ) {
V_256 = F_55 ( V_101 ) ;
goto V_105;
}
V_256 = F_89 ( V_101 ) ;
if ( V_256 == 0 )
V_256 = V_101 -> V_113 ;
F_56 ( V_101 ) ;
return 0 ;
V_105:
F_2 ( L_17 , V_16 , V_256 ) ;
return V_256 ;
}
static void
F_426 ( struct V_100 * V_101 , void * V_130 )
{
struct V_796 * V_797 = V_130 ;
struct V_42 * V_43 = F_69 ( V_797 -> args . V_51 ) ;
struct V_88 * V_89 = F_50 ( V_43 ) ;
F_2 ( L_12 , V_16 ) ;
if ( F_41 ( V_89 , & V_797 -> args . V_134 ,
& V_797 -> V_37 . V_135 , V_101 ) )
return;
if ( F_427 ( & V_797 -> args . V_209 ,
F_61 ( V_797 -> args . V_51 ) -> V_798 ,
V_797 -> args . V_252 -> V_50 ) ) {
F_428 ( V_101 , V_799 ) ;
}
}
static void F_429 ( struct V_100 * V_101 , void * V_130 )
{
struct V_796 * V_797 = V_130 ;
struct V_51 * V_51 = V_797 -> args . V_51 ;
struct V_42 * V_43 = F_69 ( V_51 ) ;
struct V_800 * V_801 ;
struct V_49 * V_50 = NULL ;
unsigned long V_802 , V_803 ;
F_2 ( L_12 , V_16 ) ;
if ( ! F_32 ( V_101 , & V_797 -> V_37 . V_135 ) )
goto V_105;
switch ( V_101 -> V_113 ) {
case 0 :
goto V_105;
case - V_3 :
case - V_4 :
V_802 = F_430 ( V_101 -> V_804 ) ;
V_803 = V_797 -> args . V_84 + V_802 ;
if ( F_431 ( V_803 , V_126 ) )
V_101 -> V_113 = - V_76 ;
break;
case - V_60 :
case - V_59 :
F_24 ( & V_51 -> V_151 ) ;
V_801 = F_61 ( V_51 ) -> V_798 ;
if ( ! V_801 || F_432 ( & V_801 -> V_805 ) ) {
F_26 ( & V_51 -> V_151 ) ;
V_50 = V_797 -> args . V_252 -> V_50 ;
} else {
F_433 ( V_806 ) ;
F_434 ( V_801 , & V_806 , NULL ) ;
F_26 ( & V_51 -> V_151 ) ;
F_435 ( & V_806 ) ;
}
}
if ( F_190 ( V_101 , V_43 , V_50 ) == - V_129 )
F_35 ( V_101 ) ;
V_105:
F_2 ( L_66 , V_16 ) ;
}
static T_9 F_436 ( struct V_42 * V_43 )
{
T_6 V_763 = V_43 -> V_47 -> V_71 -> V_761 . V_763 ;
return F_437 ( 0 , V_763 ) ;
}
static void F_438 ( struct V_406 * * V_25 , T_9 V_807 )
{
int V_393 ;
if ( ! V_25 )
return;
for ( V_393 = 0 ; V_393 < V_807 ; V_393 ++ ) {
if ( ! V_25 [ V_393 ] )
break;
F_220 ( V_25 [ V_393 ] ) ;
}
F_78 ( V_25 ) ;
}
static struct V_406 * * F_439 ( T_9 V_807 , T_4 V_808 )
{
struct V_406 * * V_25 ;
int V_393 ;
V_25 = F_440 ( V_807 , sizeof( struct V_406 * ) , V_808 ) ;
if ( ! V_25 ) {
F_2 ( L_82 , V_16 , V_807 ) ;
return NULL ;
}
for ( V_393 = 0 ; V_393 < V_807 ; V_393 ++ ) {
V_25 [ V_393 ] = F_216 ( V_808 ) ;
if ( ! V_25 [ V_393 ] ) {
F_2 ( L_83 , V_16 ) ;
F_438 ( V_25 , V_807 ) ;
return NULL ;
}
}
return V_25 ;
}
static void F_441 ( void * V_130 )
{
struct V_796 * V_797 = V_130 ;
struct V_51 * V_51 = V_797 -> args . V_51 ;
struct V_42 * V_43 = F_69 ( V_51 ) ;
T_9 V_809 = F_436 ( V_43 ) ;
F_2 ( L_12 , V_16 ) ;
F_438 ( V_797 -> args . V_798 . V_25 , V_809 ) ;
F_442 ( F_61 ( V_51 ) -> V_798 ) ;
F_136 ( V_797 -> args . V_252 ) ;
F_78 ( V_130 ) ;
F_2 ( L_66 , V_16 ) ;
}
struct V_810 *
F_443 ( struct V_796 * V_797 , T_4 V_808 )
{
struct V_51 * V_51 = V_797 -> args . V_51 ;
struct V_42 * V_43 = F_69 ( V_51 ) ;
T_9 V_809 = F_436 ( V_43 ) ;
struct V_100 * V_101 ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_811 ] ,
. V_262 = & V_797 -> args ,
. V_263 = & V_797 -> V_37 ,
} ;
struct V_138 V_265 = {
. V_140 = V_43 -> V_77 ,
. V_136 = & V_137 ,
. V_141 = & V_812 ,
. V_143 = V_797 ,
. V_173 = V_269 ,
} ;
struct V_810 * V_813 = NULL ;
int V_256 = 0 ;
F_2 ( L_12 , V_16 ) ;
V_797 -> args . V_798 . V_25 = F_439 ( V_809 , V_808 ) ;
if ( ! V_797 -> args . V_798 . V_25 ) {
F_441 ( V_797 ) ;
return F_45 ( - V_125 ) ;
}
V_797 -> args . V_798 . V_433 = V_809 * V_529 ;
V_797 -> args . V_84 = V_126 ;
V_797 -> V_37 . V_814 = & V_797 -> args . V_798 ;
V_797 -> V_37 . V_135 . V_93 = NULL ;
F_39 ( & V_797 -> args . V_134 , & V_797 -> V_37 . V_135 , 0 ) ;
F_444 ( F_61 ( V_51 ) -> V_798 ) ;
V_101 = F_54 ( & V_265 ) ;
if ( F_44 ( V_101 ) )
return F_196 ( V_101 ) ;
V_256 = F_89 ( V_101 ) ;
if ( V_256 == 0 )
V_256 = V_101 -> V_113 ;
if ( V_256 == 0 && V_797 -> V_37 . V_814 -> V_394 )
V_813 = F_445 ( V_797 ) ;
F_56 ( V_101 ) ;
F_2 ( L_17 , V_16 , V_256 ) ;
if ( V_256 )
return F_45 ( V_256 ) ;
return V_813 ;
}
static void
F_446 ( struct V_100 * V_101 , void * V_130 )
{
struct V_815 * V_816 = V_130 ;
F_2 ( L_12 , V_16 ) ;
F_41 ( V_816 -> V_48 -> V_71 ,
& V_816 -> args . V_134 ,
& V_816 -> V_37 . V_135 ,
V_101 ) ;
}
static void F_447 ( struct V_100 * V_101 , void * V_130 )
{
struct V_815 * V_816 = V_130 ;
struct V_42 * V_43 ;
F_2 ( L_12 , V_16 ) ;
if ( ! F_32 ( V_101 , & V_816 -> V_37 . V_135 ) )
return;
V_43 = F_69 ( V_816 -> args . V_51 ) ;
if ( F_190 ( V_101 , V_43 , NULL ) == - V_129 ) {
F_35 ( V_101 ) ;
return;
}
F_2 ( L_66 , V_16 ) ;
}
static void F_448 ( void * V_130 )
{
struct V_815 * V_816 = V_130 ;
struct V_800 * V_801 = V_816 -> args . V_798 ;
F_2 ( L_12 , V_16 ) ;
F_24 ( & V_801 -> V_817 -> V_151 ) ;
if ( V_816 -> V_37 . V_818 )
F_449 ( V_801 , & V_816 -> V_37 . V_209 , true ) ;
V_801 -> V_819 -- ;
F_26 ( & V_801 -> V_817 -> V_151 ) ;
F_442 ( V_816 -> args . V_798 ) ;
F_78 ( V_130 ) ;
F_2 ( L_66 , V_16 ) ;
}
int F_450 ( struct V_815 * V_816 )
{
struct V_100 * V_101 ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_820 ] ,
. V_262 = & V_816 -> args ,
. V_263 = & V_816 -> V_37 ,
} ;
struct V_138 V_265 = {
. V_140 = V_816 -> V_48 -> V_518 ,
. V_136 = & V_137 ,
. V_141 = & V_821 ,
. V_143 = V_816 ,
} ;
int V_256 ;
F_2 ( L_12 , V_16 ) ;
F_39 ( & V_816 -> args . V_134 , & V_816 -> V_37 . V_135 , 1 ) ;
V_101 = F_54 ( & V_265 ) ;
if ( F_44 ( V_101 ) )
return F_55 ( V_101 ) ;
V_256 = V_101 -> V_113 ;
F_2 ( L_17 , V_16 , V_256 ) ;
F_56 ( V_101 ) ;
return V_256 ;
}
static int F_451 ( struct V_42 * V_43 ,
const struct V_357 * V_183 ,
struct V_822 * V_823 )
{
struct V_824 args = {
. V_183 = V_183 ,
. V_825 = V_43 -> V_826 -> V_193 ,
} ;
struct V_827 V_37 = {
. V_823 = V_823 ,
} ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_828 ] ,
. V_262 = & args ,
. V_263 = & V_37 ,
} ;
int V_256 ;
F_2 ( L_12 , V_16 ) ;
V_256 = F_59 ( V_43 -> V_77 , V_43 , & V_137 , & args . V_134 ,
& V_37 . V_135 , 0 ) ;
F_2 ( L_17 , V_16 , V_256 ) ;
return V_256 ;
}
int F_452 ( struct V_42 * V_43 ,
const struct V_357 * V_183 ,
struct V_822 * V_823 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_13 ( V_43 ,
F_451 ( V_43 , V_183 , V_823 ) ,
& V_46 ) ;
} while ( V_46 . V_53 );
F_2 ( L_84 , V_16 ,
V_1 , V_823 -> V_829 ) ;
return V_1 ;
}
static int
F_453 ( struct V_42 * V_43 , struct V_830 * V_831 )
{
struct V_832 args = {
. V_831 = V_831 ,
} ;
struct V_833 V_37 = {
. V_831 = V_831 ,
} ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_834 ] ,
. V_262 = & args ,
. V_263 = & V_37 ,
} ;
int V_256 ;
F_2 ( L_12 , V_16 ) ;
V_256 = F_59 ( V_43 -> V_77 , V_43 , & V_137 , & args . V_134 , & V_37 . V_135 , 0 ) ;
F_2 ( L_17 , V_16 , V_256 ) ;
return V_256 ;
}
int F_454 ( struct V_42 * V_43 , struct V_830 * V_831 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_13 ( V_43 ,
F_453 ( V_43 , V_831 ) ,
& V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static void F_455 ( struct V_100 * V_101 , void * V_130 )
{
struct V_835 * V_132 = V_130 ;
struct V_42 * V_43 = F_69 ( V_132 -> args . V_51 ) ;
struct V_88 * V_89 = F_50 ( V_43 ) ;
F_41 ( V_89 ,
& V_132 -> args . V_134 ,
& V_132 -> V_37 . V_135 ,
V_101 ) ;
}
static void
F_456 ( struct V_100 * V_101 , void * V_130 )
{
struct V_835 * V_132 = V_130 ;
struct V_42 * V_43 = F_69 ( V_132 -> args . V_51 ) ;
if ( ! F_32 ( V_101 , & V_132 -> V_37 . V_135 ) )
return;
switch ( V_101 -> V_113 ) {
case - V_57 :
case - V_836 :
case - V_837 :
case - V_75 :
V_101 -> V_113 = 0 ;
break;
case 0 :
F_291 ( V_132 -> args . V_51 ,
V_132 -> V_37 . V_329 ) ;
break;
default:
if ( F_190 ( V_101 , V_43 , NULL ) == - V_129 ) {
F_35 ( V_101 ) ;
return;
}
}
}
static void F_457 ( void * V_130 )
{
struct V_835 * V_132 = V_130 ;
F_458 ( V_132 ) ;
F_401 ( V_132 -> V_292 ) ;
F_78 ( V_132 ) ;
}
int
F_459 ( struct V_835 * V_132 , bool V_838 )
{
struct V_136 V_137 = {
. V_259 = & V_260 [ V_839 ] ,
. V_262 = & V_132 -> args ,
. V_263 = & V_132 -> V_37 ,
. V_264 = V_132 -> V_292 ,
} ;
struct V_138 V_265 = {
. V_101 = & V_132 -> V_101 ,
. V_140 = F_231 ( V_132 -> args . V_51 ) ,
. V_136 = & V_137 ,
. V_141 = & V_840 ,
. V_143 = V_132 ,
. V_173 = V_269 ,
} ;
struct V_100 * V_101 ;
int V_256 = 0 ;
F_2 ( L_85
L_86 ,
V_132 -> V_101 . V_841 , V_838 ,
V_132 -> args . V_842 ,
V_132 -> args . V_51 -> V_843 ) ;
F_39 ( & V_132 -> args . V_134 , & V_132 -> V_37 . V_135 , 1 ) ;
V_101 = F_54 ( & V_265 ) ;
if ( F_44 ( V_101 ) )
return F_55 ( V_101 ) ;
if ( V_838 == false )
goto V_105;
V_256 = F_89 ( V_101 ) ;
if ( V_256 != 0 )
goto V_105;
V_256 = V_101 -> V_113 ;
V_105:
F_2 ( L_87 , V_16 , V_256 ) ;
F_56 ( V_101 ) ;
return V_256 ;
}
static int
F_460 ( struct V_42 * V_43 , struct V_357 * V_358 ,
struct V_385 * V_386 , struct V_697 * V_698 )
{
struct V_844 args = {
. V_845 = V_846 ,
} ;
struct V_700 V_37 = {
. V_698 = V_698 ,
} ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_847 ] ,
. V_262 = & args ,
. V_263 = & V_37 ,
} ;
return F_59 ( V_43 -> V_77 , V_43 , & V_137 , & args . V_134 , & V_37 . V_135 , 0 ) ;
}
static int
F_461 ( struct V_42 * V_43 , struct V_357 * V_358 ,
struct V_385 * V_386 , struct V_697 * V_698 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_460 ( V_43 , V_358 , V_386 , V_698 ) ;
switch ( V_1 ) {
case 0 :
case - V_6 :
case - V_848 :
goto V_105;
default:
V_1 = F_13 ( V_43 , V_1 , & V_46 ) ;
}
} while ( V_46 . V_53 );
V_105:
return V_1 ;
}
static int
F_462 ( struct V_42 * V_43 , struct V_357 * V_358 ,
struct V_385 * V_386 )
{
int V_1 ;
struct V_406 * V_406 ;
T_7 V_390 ;
struct V_697 * V_698 ;
V_406 = F_216 ( V_319 ) ;
if ( ! V_406 ) {
V_1 = - V_125 ;
goto V_105;
}
V_698 = F_313 ( V_406 ) ;
V_1 = F_461 ( V_43 , V_358 , V_386 , V_698 ) ;
if ( V_1 == - V_6 || V_1 == - V_848 ) {
V_1 = F_206 ( V_43 , V_358 , V_386 ) ;
goto V_849;
}
if ( V_1 )
goto V_849;
V_390 = F_463 ( V_698 ) ;
if ( V_1 == 0 )
V_1 = F_204 ( V_43 , V_358 , V_386 , V_390 ) ;
V_849:
F_326 ( V_406 ) ;
if ( V_1 == - V_12 )
return - V_7 ;
V_105:
return V_1 ;
}
static int F_464 ( struct V_42 * V_43 , T_5 * V_209 )
{
int V_256 ;
struct V_850 args = {
. V_209 = V_209 ,
} ;
struct V_851 V_37 ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_852 ] ,
. V_262 = & args ,
. V_263 = & V_37 ,
} ;
F_2 ( L_88 , V_209 ) ;
F_39 ( & args . V_134 , & V_37 . V_135 , 0 ) ;
F_40 ( & args . V_134 ) ;
V_256 = F_53 ( V_43 -> V_77 , V_43 , & V_137 ,
& args . V_134 , & V_37 . V_135 ) ;
if ( V_256 != V_305 ) {
F_2 ( L_89 , V_256 ) ;
return V_256 ;
}
F_2 ( L_90 , - V_37 . V_256 ) ;
return - V_37 . V_256 ;
}
static int F_165 ( struct V_42 * V_43 , T_5 * V_209 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_464 ( V_43 , V_209 ) ;
if ( V_1 != - V_76 )
break;
F_13 ( V_43 , V_1 , & V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static int F_465 ( struct V_42 * V_43 , T_5 * V_209 )
{
struct V_853 args = {
. V_209 = V_209 ,
} ;
struct V_854 V_37 ;
struct V_136 V_137 = {
. V_259 = & V_260 [ V_855 ] ,
. V_262 = & args ,
. V_263 = & V_37 ,
} ;
int V_256 ;
F_2 ( L_91 , V_209 ) ;
F_39 ( & args . V_134 , & V_37 . V_135 , 0 ) ;
F_40 ( & args . V_134 ) ;
V_256 = F_53 ( V_43 -> V_77 , V_43 , & V_137 ,
& args . V_134 , & V_37 . V_135 ) ;
F_2 ( L_92 , V_256 ) ;
return V_256 ;
}
static int F_166 ( struct V_42 * V_43 , T_5 * V_209 )
{
struct V_45 V_46 = { } ;
int V_1 ;
do {
V_1 = F_465 ( V_43 , V_209 ) ;
if ( V_1 != - V_76 )
break;
F_13 ( V_43 , V_1 , & V_46 ) ;
} while ( V_46 . V_53 );
return V_1 ;
}
static bool F_466 ( const T_5 * V_856 ,
const T_5 * V_857 )
{
if ( memcmp ( V_856 -> V_858 , V_857 -> V_858 , sizeof( V_856 -> V_858 ) ) != 0 )
return false ;
if ( V_856 -> V_162 == V_857 -> V_162 )
return true ;
if ( V_856 -> V_162 == 0 || V_857 -> V_162 == 0 )
return true ;
return false ;
}
static bool F_467 ( const T_5 * V_856 ,
const T_5 * V_857 )
{
return F_106 ( V_856 , V_857 ) ;
}
