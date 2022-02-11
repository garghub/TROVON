static int F_1 ( int V_1 )
{
if ( V_1 >= - 1000 )
return V_1 ;
switch ( V_1 ) {
case - V_2 :
return - V_3 ;
case - V_4 :
return - V_5 ;
case - V_6 :
case - V_7 :
return - V_8 ;
case - V_9 :
return - V_10 ;
case - V_11 :
return - V_12 ;
case - V_13 :
return - V_10 ;
default:
F_2 ( L_1 ,
V_14 , - V_1 ) ;
break;
}
return - V_15 ;
}
static void F_3 ( T_1 V_16 , T_2 * V_17 , struct V_18 * V_18 ,
struct V_19 * V_20 )
{
T_2 * V_21 , * V_22 ;
if ( V_16 > 2 ) {
V_20 -> V_16 = V_16 ;
memcpy ( & V_20 -> V_17 , V_17 , sizeof( V_20 -> V_17 ) ) ;
return;
}
V_20 -> V_16 = 0 ;
memset ( & V_20 -> V_17 , 0 , sizeof( V_20 -> V_17 ) ) ;
if ( V_16 == 2 )
return;
V_21 = V_22 = F_4 ( * V_20 -> V_23 ) ;
if ( V_16 == 0 ) {
* V_22 ++ = V_24 ;
* V_22 ++ = V_25 ;
* V_22 ++ = V_24 ;
* V_22 ++ = V_24 ;
memcpy ( V_22 , L_2 , 4 ) ;
V_22 ++ ;
* V_22 ++ = V_24 ;
* V_22 ++ = F_5 ( V_26 ) ;
* V_22 ++ = F_5 ( 8 ) ;
V_22 = F_6 ( V_22 , F_7 ( V_18 -> V_27 ) ) ;
}
* V_22 ++ = V_24 ;
* V_22 ++ = V_25 ;
* V_22 ++ = V_28 ;
* V_22 ++ = V_28 ;
memcpy ( V_22 , L_3 , 4 ) ;
V_22 ++ ;
* V_22 ++ = V_24 ;
* V_22 ++ = F_5 ( V_26 ) ;
* V_22 ++ = F_5 ( 8 ) ;
V_22 = F_6 ( V_22 , F_7 ( V_18 -> V_29 -> V_27 ) ) ;
V_20 -> V_30 = ( char * ) V_22 - ( char * ) V_21 ;
V_20 -> V_31 -= V_20 -> V_30 ;
F_8 ( V_21 ) ;
}
static int F_9 ( struct V_32 * V_33 , long * V_34 )
{
int V_35 = 0 ;
F_10 () ;
if ( * V_34 <= 0 )
* V_34 = V_36 ;
if ( * V_34 > V_37 )
* V_34 = V_37 ;
F_11 ( * V_34 ) ;
if ( F_12 ( V_38 ) )
V_35 = - V_39 ;
* V_34 <<= 1 ;
return V_35 ;
}
static int F_13 ( struct V_40 * V_41 , int V_42 , struct V_43 * V_44 )
{
struct V_45 * V_46 = V_41 -> V_45 ;
struct V_47 * V_48 = V_44 -> V_48 ;
struct V_49 * V_49 = V_44 -> V_49 ;
int V_50 = V_42 ;
V_44 -> V_51 = 0 ;
switch( V_42 ) {
case 0 :
return 0 ;
case - V_52 :
if ( V_49 && F_14 ( V_49 , V_53 ) ) {
F_15 ( V_49 ) ;
V_44 -> V_51 = 1 ;
return 0 ;
}
if ( V_48 == NULL )
break;
F_16 ( V_41 , V_48 ) ;
goto V_54;
case - V_55 :
case - V_56 :
case - V_57 :
if ( V_48 == NULL )
break;
F_17 ( V_48 -> V_49 ) ;
F_16 ( V_41 , V_48 ) ;
goto V_54;
case - V_58 :
if ( V_48 != NULL )
F_16 ( V_41 , V_48 ) ;
case - V_59 :
case - V_60 :
F_18 ( V_46 ) ;
goto V_54;
#if F_19 ( V_61 )
case - V_62 :
case - V_63 :
case - V_64 :
case - V_65 :
case - V_66 :
case - V_67 :
case - V_68 :
F_2 ( L_4 , V_14 ,
V_42 ) ;
F_20 ( V_46 -> V_69 , V_42 ) ;
goto V_54;
#endif
case - V_70 :
if ( V_44 -> V_34 > V_71 ) {
V_50 = - V_72 ;
break;
}
case - V_73 :
case - V_74 :
V_50 = F_9 ( V_41 -> V_75 , & V_44 -> V_34 ) ;
if ( V_50 != 0 )
break;
case - V_76 :
case - V_77 :
V_44 -> V_51 = 1 ;
break;
case - V_6 :
case - V_7 :
if ( V_41 -> V_78 & V_79 ) {
V_41 -> V_78 &= ~ V_79 ;
V_44 -> V_51 = 1 ;
F_21 ( V_80 L_5
L_6
L_7
L_8 ,
V_41 -> V_45 -> V_81 ) ;
}
}
return F_1 ( V_50 ) ;
V_54:
V_50 = F_22 ( V_46 ) ;
if ( V_50 == 0 )
V_44 -> V_51 = 1 ;
return V_50 ;
}
static void F_23 ( struct V_45 * V_46 , unsigned long V_82 )
{
F_24 ( & V_46 -> V_83 ) ;
if ( F_25 ( V_46 -> V_84 , V_82 ) )
V_46 -> V_84 = V_82 ;
F_26 ( & V_46 -> V_83 ) ;
}
static void F_27 ( const struct V_40 * V_41 , unsigned long V_82 )
{
F_23 ( V_41 -> V_45 , V_82 ) ;
}
static void F_28 ( struct V_85 * V_35 )
{
struct V_86 * V_87 ;
struct V_88 * V_89 ;
bool V_90 = false ;
if ( ! V_35 -> V_91 ) {
F_2 ( L_9 , V_14 ) ;
return;
}
V_89 = V_35 -> V_91 -> V_92 ;
V_87 = V_89 -> V_87 ;
F_24 ( & V_89 -> V_93 ) ;
if ( V_89 -> V_94 > V_89 -> V_95 )
V_90 = true ;
if ( F_29 ( V_89 , V_35 -> V_91 ) ) {
V_90 = false ;
goto V_96;
}
F_30 ( V_89 , V_35 -> V_91 ) ;
if ( V_89 -> V_94 != V_97 )
V_90 = false ;
V_96:
F_26 ( & V_89 -> V_93 ) ;
V_35 -> V_91 = NULL ;
if ( V_90 )
F_31 ( V_87 -> V_46 ) ;
}
static int F_32 ( struct V_98 * V_99 , struct V_85 * V_35 )
{
struct V_86 * V_87 ;
struct V_100 * V_101 ;
struct V_45 * V_46 ;
bool V_102 = false ;
int V_50 = 1 ;
if ( ! F_33 ( V_99 ) )
goto V_103;
V_101 = V_35 -> V_91 ;
V_87 = V_101 -> V_92 -> V_87 ;
if ( V_101 -> V_102 ) {
V_101 -> V_102 = 0 ;
V_102 = true ;
}
switch ( V_35 -> V_104 ) {
case 0 :
++ V_101 -> V_105 ;
V_46 = V_87 -> V_46 ;
F_23 ( V_46 , V_35 -> V_106 ) ;
if ( V_35 -> V_107 != 0 )
F_18 ( V_46 ) ;
F_34 ( V_101 -> V_92 , V_101 , V_35 ) ;
break;
case 1 :
V_101 -> V_102 = 1 ;
goto V_103;
case - V_74 :
F_2 ( L_10 ,
V_14 ,
V_101 -> V_108 ,
V_101 -> V_105 ) ;
goto V_109;
case - V_63 :
goto V_110;
case - V_68 :
if ( V_102 ) {
++ V_101 -> V_105 ;
goto V_110;
}
if ( V_101 -> V_105 != 1 ) {
V_101 -> V_105 = 1 ;
goto V_110;
}
break;
case - V_67 :
++ V_101 -> V_105 ;
goto V_110;
default:
++ V_101 -> V_105 ;
}
V_103:
F_2 ( L_11 , V_14 , V_35 -> V_104 ) ;
F_28 ( V_35 ) ;
return V_50 ;
V_110:
if ( F_35 ( V_99 ) ) {
V_99 -> V_111 = 0 ;
V_50 = 0 ;
}
goto V_103;
V_109:
if ( ! F_36 ( V_99 ) )
goto V_103;
F_37 ( V_99 , V_37 ) ;
return 0 ;
}
static int F_38 ( struct V_98 * V_99 ,
struct V_85 * V_35 )
{
if ( V_35 -> V_91 == NULL )
return 1 ;
return F_32 ( V_99 , V_35 ) ;
}
static void F_39 ( struct V_112 * args ,
struct V_85 * V_35 , int V_113 )
{
args -> V_114 = NULL ;
args -> V_115 = 0 ;
args -> V_116 = 0 ;
if ( V_113 )
args -> V_115 = 1 ;
V_35 -> V_91 = NULL ;
}
static void F_40 ( struct V_112 * args )
{
args -> V_116 = 1 ;
}
int F_41 ( struct V_86 * V_87 ,
struct V_112 * args ,
struct V_85 * V_35 ,
struct V_98 * V_99 )
{
struct V_100 * V_101 ;
struct V_88 * V_89 ;
F_2 ( L_12 , V_14 ) ;
if ( V_35 -> V_91 != NULL )
goto V_117;
V_89 = & V_87 -> V_118 ;
V_99 -> V_119 = 0 ;
F_24 ( & V_89 -> V_93 ) ;
if ( F_42 ( V_120 , & V_87 -> V_121 ) &&
! args -> V_116 ) {
F_2 ( L_13 , V_14 ) ;
goto V_122;
}
V_101 = F_43 ( V_89 ) ;
if ( F_44 ( V_101 ) ) {
if ( V_101 == F_45 ( - V_123 ) )
V_99 -> V_119 = V_71 >> 2 ;
F_2 ( L_14 , V_14 ) ;
goto V_122;
}
F_26 ( & V_89 -> V_93 ) ;
args -> V_114 = V_101 ;
F_2 ( L_15 , V_14 ,
V_101 -> V_108 , V_101 -> V_105 ) ;
V_35 -> V_91 = V_101 ;
V_35 -> V_106 = V_124 ;
V_35 -> V_107 = 0 ;
V_35 -> V_104 = 1 ;
V_117:
F_46 ( V_99 ) ;
return 0 ;
V_122:
if ( args -> V_116 )
F_47 ( & V_89 -> V_125 , V_99 ,
NULL , V_126 ) ;
else
F_48 ( & V_89 -> V_125 , V_99 , NULL ) ;
F_26 ( & V_89 -> V_93 ) ;
return - V_127 ;
}
int F_49 ( const struct V_40 * V_41 ,
struct V_112 * args ,
struct V_85 * V_35 ,
struct V_98 * V_99 )
{
struct V_86 * V_87 = F_50 ( V_41 ) ;
int V_50 = 0 ;
if ( V_87 == NULL ) {
F_46 ( V_99 ) ;
goto V_103;
}
F_2 ( L_16 ,
V_14 , V_87 -> V_46 , V_87 , V_35 -> V_91 ?
V_35 -> V_91 -> V_108 : - 1 ) ;
V_50 = F_41 ( V_87 , args , V_35 , V_99 ) ;
V_103:
F_2 ( L_17 , V_14 , V_50 ) ;
return V_50 ;
}
static void F_51 ( struct V_98 * V_99 , void * V_128 )
{
struct V_129 * V_130 = V_128 ;
struct V_86 * V_87 = F_50 ( V_130 -> V_131 ) ;
F_2 ( L_18 , V_14 , V_130 -> V_131 ) ;
F_41 ( V_87 , V_130 -> V_132 , V_130 -> V_133 , V_99 ) ;
}
static void F_52 ( struct V_98 * V_99 , void * V_128 )
{
struct V_129 * V_130 = V_128 ;
F_32 ( V_99 , V_130 -> V_133 ) ;
}
static int F_53 ( struct V_32 * V_33 ,
struct V_40 * V_41 ,
struct V_134 * V_135 ,
struct V_112 * args ,
struct V_85 * V_35 )
{
int V_50 ;
struct V_98 * V_99 ;
struct V_129 V_130 = {
. V_131 = V_41 ,
. V_132 = args ,
. V_133 = V_35 ,
} ;
struct V_136 V_137 = {
. V_138 = V_33 ,
. V_134 = V_135 ,
. V_139 = & V_140 ,
. V_141 = & V_130
} ;
V_99 = F_54 ( & V_137 ) ;
if ( F_44 ( V_99 ) )
V_50 = F_55 ( V_99 ) ;
else {
V_50 = V_99 -> V_111 ;
F_56 ( V_99 ) ;
}
return V_50 ;
}
static
void F_39 ( struct V_112 * args ,
struct V_85 * V_35 , int V_113 )
{
}
static void F_40 ( struct V_112 * args )
{
}
static int F_38 ( struct V_98 * V_99 ,
struct V_85 * V_35 )
{
return 1 ;
}
static
int F_57 ( struct V_32 * V_33 ,
struct V_40 * V_41 ,
struct V_134 * V_135 ,
struct V_112 * args ,
struct V_85 * V_35 )
{
return F_58 ( V_33 , V_135 , 0 ) ;
}
static
int F_59 ( struct V_32 * V_33 ,
struct V_40 * V_41 ,
struct V_134 * V_135 ,
struct V_112 * args ,
struct V_85 * V_35 ,
int V_113 )
{
F_39 ( args , V_35 , V_113 ) ;
return V_41 -> V_45 -> V_142 -> V_143 ( V_33 , V_41 , V_135 ,
args , V_35 ) ;
}
static void F_60 ( struct V_49 * V_144 , struct V_145 * V_146 )
{
struct V_147 * V_148 = F_61 ( V_144 ) ;
F_24 ( & V_144 -> V_149 ) ;
V_148 -> V_150 |= V_151 | V_152 ;
if ( ! V_146 -> V_153 || V_146 -> V_154 != V_144 -> V_155 )
F_62 ( V_144 ) ;
V_144 -> V_155 = V_146 -> V_156 ;
F_63 ( V_144 ) ;
F_26 ( & V_144 -> V_149 ) ;
}
static void F_64 ( struct V_157 * V_22 )
{
V_22 -> V_158 . V_159 = & V_22 -> V_159 ;
V_22 -> V_158 . V_160 = V_22 -> V_161 . V_160 ;
V_22 -> V_162 . V_160 = V_22 -> V_163 . V_160 ;
V_22 -> V_158 . V_41 = V_22 -> V_161 . V_41 ;
V_22 -> V_158 . V_164 = V_22 -> V_161 . V_165 ;
F_65 ( & V_22 -> V_159 ) ;
F_66 ( & V_22 -> V_159 , & V_22 -> V_166 , & V_22 -> V_167 ) ;
}
static struct V_157 * F_67 ( struct V_18 * V_18 ,
struct V_168 * V_169 , T_3 V_170 , int V_171 ,
const struct V_172 * V_173 ,
T_4 V_174 )
{
struct V_18 * V_175 = F_68 ( V_18 ) ;
struct V_49 * V_144 = V_175 -> V_27 ;
struct V_40 * V_41 = F_69 ( V_144 ) ;
struct V_157 * V_22 ;
V_22 = F_70 ( sizeof( * V_22 ) , V_174 ) ;
if ( V_22 == NULL )
goto V_1;
V_22 -> V_161 . V_160 = F_71 ( & V_169 -> V_176 , V_174 ) ;
if ( V_22 -> V_161 . V_160 == NULL )
goto V_177;
F_72 ( V_18 -> V_178 ) ;
V_22 -> V_18 = F_73 ( V_18 ) ;
V_22 -> V_144 = V_175 ;
V_22 -> V_179 = V_169 ;
F_74 ( & V_169 -> V_180 ) ;
V_22 -> V_161 . V_181 = F_75 ( V_144 ) ;
V_22 -> V_161 . V_182 = V_171 ;
V_22 -> V_161 . V_170 = V_170 & ( V_53 | V_183 ) ;
if ( ! ( V_171 & V_184 ) ) {
V_22 -> V_161 . V_165 = V_185 | V_186 |
V_187 | V_188 ;
}
V_22 -> V_161 . V_189 = V_41 -> V_45 -> V_190 ;
V_22 -> V_161 . V_191 . V_192 = F_76 ( V_169 -> V_176 . V_192 ) ;
V_22 -> V_161 . V_191 . V_193 = V_169 -> V_176 . V_194 ;
V_22 -> V_161 . V_195 = & V_18 -> V_196 ;
V_22 -> V_161 . V_41 = V_41 ;
V_22 -> V_161 . V_197 = V_41 -> V_198 ;
V_22 -> V_161 . V_199 = & V_200 [ 0 ] ;
V_22 -> V_161 . V_201 = V_202 ;
if ( V_173 != NULL && V_173 -> V_203 != 0 ) {
T_2 V_204 [ 2 ] ;
V_22 -> V_161 . V_205 . V_173 = & V_22 -> V_173 ;
memcpy ( & V_22 -> V_173 , V_173 , sizeof( V_22 -> V_173 ) ) ;
V_204 [ 0 ] = V_124 ;
V_204 [ 1 ] = V_38 -> V_206 ;
memcpy ( V_22 -> V_161 . V_205 . V_17 . V_130 , V_204 ,
sizeof( V_22 -> V_161 . V_205 . V_17 . V_130 ) ) ;
}
V_22 -> V_163 . V_181 = & V_22 -> V_158 . V_181 ;
V_22 -> V_163 . V_207 = & V_22 -> V_158 . V_207 ;
V_22 -> V_163 . V_160 = V_22 -> V_161 . V_160 ;
F_64 ( V_22 ) ;
F_77 ( & V_22 -> V_208 ) ;
return V_22 ;
V_177:
F_78 ( V_22 ) ;
V_1:
F_79 ( V_175 ) ;
return NULL ;
}
static void F_80 ( struct V_208 * V_208 )
{
struct V_157 * V_22 = F_81 ( V_208 ,
struct V_157 , V_208 ) ;
struct V_209 * V_210 = V_22 -> V_18 -> V_178 ;
F_82 ( V_22 -> V_161 . V_160 ) ;
if ( V_22 -> V_48 != NULL )
F_83 ( V_22 -> V_48 ) ;
F_84 ( V_22 -> V_179 ) ;
F_79 ( V_22 -> V_144 ) ;
F_79 ( V_22 -> V_18 ) ;
F_85 ( V_210 ) ;
F_86 ( & V_22 -> V_159 ) ;
F_78 ( V_22 ) ;
}
static void F_87 ( struct V_157 * V_22 )
{
if ( V_22 != NULL )
F_88 ( & V_22 -> V_208 , F_80 ) ;
}
static int F_89 ( struct V_98 * V_99 )
{
int V_50 ;
V_50 = F_90 ( V_99 ) ;
return V_50 ;
}
static int F_91 ( struct V_47 * V_48 , T_3 V_211 , int V_212 )
{
int V_50 = 0 ;
if ( V_212 & ( V_184 | V_213 ) )
goto V_103;
switch ( V_211 & ( V_53 | V_183 ) ) {
case V_53 :
V_50 |= F_42 ( V_214 , & V_48 -> V_171 ) != 0
&& V_48 -> V_215 != 0 ;
break;
case V_183 :
V_50 |= F_42 ( V_216 , & V_48 -> V_171 ) != 0
&& V_48 -> V_217 != 0 ;
break;
case V_53 | V_183 :
V_50 |= F_42 ( V_218 , & V_48 -> V_171 ) != 0
&& V_48 -> V_219 != 0 ;
}
V_103:
return V_50 ;
}
static int F_92 ( struct V_220 * V_221 , T_3 V_170 )
{
if ( V_221 == NULL )
return 0 ;
if ( ( V_221 -> type & V_170 ) != V_170 )
return 0 ;
if ( F_42 ( V_222 , & V_221 -> V_171 ) )
return 0 ;
F_93 ( V_221 ) ;
return 1 ;
}
static void F_94 ( struct V_47 * V_48 , T_3 V_170 )
{
switch ( V_170 ) {
case V_183 :
V_48 -> V_217 ++ ;
break;
case V_53 :
V_48 -> V_215 ++ ;
break;
case V_53 | V_183 :
V_48 -> V_219 ++ ;
}
F_95 ( V_48 , V_48 -> V_48 | V_170 ) ;
}
static void F_96 ( struct V_47 * V_48 , T_5 * V_207 , T_3 V_170 )
{
if ( F_42 ( V_223 , & V_48 -> V_171 ) == 0 )
F_97 ( & V_48 -> V_207 , V_207 ) ;
F_97 ( & V_48 -> V_224 , V_207 ) ;
switch ( V_170 ) {
case V_53 :
F_98 ( V_214 , & V_48 -> V_171 ) ;
break;
case V_183 :
F_98 ( V_216 , & V_48 -> V_171 ) ;
break;
case V_53 | V_183 :
F_98 ( V_218 , & V_48 -> V_171 ) ;
}
}
static void F_99 ( struct V_47 * V_48 , T_5 * V_207 , T_3 V_170 )
{
F_100 ( & V_48 -> V_225 ) ;
F_96 ( V_48 , V_207 , V_170 ) ;
F_101 ( & V_48 -> V_225 ) ;
}
static void F_102 ( struct V_47 * V_48 , T_5 * V_224 , const T_5 * V_226 , T_3 V_170 )
{
F_100 ( & V_48 -> V_225 ) ;
if ( V_226 != NULL ) {
F_97 ( & V_48 -> V_207 , V_226 ) ;
F_98 ( V_223 , & V_48 -> V_171 ) ;
}
if ( V_224 != NULL )
F_96 ( V_48 , V_224 , V_170 ) ;
F_101 ( & V_48 -> V_225 ) ;
F_24 ( & V_48 -> V_179 -> V_227 ) ;
F_94 ( V_48 , V_170 ) ;
F_26 ( & V_48 -> V_179 -> V_227 ) ;
}
static int F_103 ( struct V_47 * V_48 , T_5 * V_224 , T_5 * V_221 , T_3 V_170 )
{
struct V_147 * V_148 = F_61 ( V_48 -> V_49 ) ;
struct V_220 * V_228 ;
int V_50 = 0 ;
V_170 &= ( V_53 | V_183 ) ;
F_104 () ;
V_228 = F_105 ( V_148 -> V_221 ) ;
if ( V_228 == NULL )
goto V_229;
F_24 ( & V_228 -> V_230 ) ;
if ( V_148 -> V_221 != V_228 ||
( V_228 -> type & V_170 ) != V_170 )
goto V_231;
if ( V_221 == NULL )
V_221 = & V_228 -> V_207 ;
else if ( ! F_106 ( & V_228 -> V_207 , V_221 ) )
goto V_231;
F_93 ( V_228 ) ;
F_102 ( V_48 , V_224 , & V_228 -> V_207 , V_170 ) ;
V_50 = 1 ;
V_231:
F_26 ( & V_228 -> V_230 ) ;
V_229:
F_107 () ;
if ( ! V_50 && V_224 != NULL ) {
F_102 ( V_48 , V_224 , NULL , V_170 ) ;
V_50 = 1 ;
}
return V_50 ;
}
static void F_108 ( struct V_49 * V_49 , T_3 V_170 )
{
struct V_220 * V_221 ;
F_104 () ;
V_221 = F_105 ( F_61 ( V_49 ) -> V_221 ) ;
if ( V_221 == NULL || ( V_221 -> type & V_170 ) == V_170 ) {
F_107 () ;
return;
}
F_107 () ;
F_15 ( V_49 ) ;
}
static struct V_47 * F_109 ( struct V_157 * V_232 )
{
struct V_47 * V_48 = V_232 -> V_48 ;
struct V_147 * V_148 = F_61 ( V_48 -> V_49 ) ;
struct V_220 * V_221 ;
int V_212 = V_232 -> V_161 . V_182 & ( V_184 | V_213 ) ;
T_3 V_170 = V_232 -> V_161 . V_170 ;
T_5 V_207 ;
int V_50 = - V_127 ;
for (; ; ) {
if ( F_91 ( V_48 , V_170 , V_212 ) ) {
F_24 ( & V_48 -> V_179 -> V_227 ) ;
if ( F_91 ( V_48 , V_170 , V_212 ) ) {
F_94 ( V_48 , V_170 ) ;
F_26 ( & V_48 -> V_179 -> V_227 ) ;
goto V_233;
}
F_26 ( & V_48 -> V_179 -> V_227 ) ;
}
F_104 () ;
V_221 = F_105 ( V_148 -> V_221 ) ;
if ( ! F_92 ( V_221 , V_170 ) ) {
F_107 () ;
break;
}
F_97 ( & V_207 , & V_221 -> V_207 ) ;
F_107 () ;
V_50 = F_110 ( V_48 -> V_49 , V_48 -> V_179 -> V_234 , V_212 ) ;
if ( V_50 != 0 )
goto V_103;
V_50 = - V_127 ;
if ( F_103 ( V_48 , NULL , & V_207 , V_170 ) )
goto V_233;
}
V_103:
return F_45 ( V_50 ) ;
V_233:
F_74 ( & V_48 -> V_31 ) ;
return V_48 ;
}
static void
F_111 ( struct V_157 * V_130 , struct V_47 * V_48 )
{
struct V_45 * V_46 = F_69 ( V_48 -> V_49 ) -> V_45 ;
struct V_220 * V_221 ;
int V_235 = 0 ;
F_104 () ;
V_221 = F_105 ( F_61 ( V_48 -> V_49 ) -> V_221 ) ;
if ( V_221 )
V_235 = V_221 -> V_171 ;
F_107 () ;
if ( V_130 -> V_161 . V_201 == V_236 ) {
F_112 ( L_19
L_20
L_21 ,
V_46 -> V_81 ) ;
} else if ( ( V_235 & 1UL << V_222 ) == 0 )
F_113 ( V_48 -> V_49 ,
V_130 -> V_179 -> V_234 ,
& V_130 -> V_158 ) ;
else
F_114 ( V_48 -> V_49 ,
V_130 -> V_179 -> V_234 ,
& V_130 -> V_158 ) ;
}
static struct V_47 *
F_115 ( struct V_157 * V_130 )
{
struct V_49 * V_49 = V_130 -> V_48 -> V_49 ;
struct V_47 * V_48 = V_130 -> V_48 ;
int V_50 ;
if ( ! V_130 -> V_237 ) {
V_50 = V_130 -> V_238 ;
goto V_1;
}
V_50 = - V_239 ;
if ( ! ( V_130 -> V_159 . V_240 & V_241 ) ||
! ( V_130 -> V_159 . V_240 & V_242 ) ||
! ( V_130 -> V_159 . V_240 & V_243 ) )
goto V_1;
V_50 = - V_123 ;
V_48 = F_116 ( V_49 , V_130 -> V_179 ) ;
if ( V_48 == NULL )
goto V_1;
V_50 = F_117 ( V_49 , & V_130 -> V_159 ) ;
if ( V_50 )
goto V_1;
if ( V_130 -> V_158 . V_244 != 0 )
F_111 ( V_130 , V_48 ) ;
F_103 ( V_48 , & V_130 -> V_158 . V_207 , NULL ,
V_130 -> V_161 . V_170 ) ;
return V_48 ;
V_1:
return F_45 ( V_50 ) ;
}
static struct V_47 *
F_118 ( struct V_157 * V_130 )
{
struct V_49 * V_49 ;
struct V_47 * V_48 = NULL ;
int V_50 ;
if ( ! V_130 -> V_237 ) {
V_48 = F_109 ( V_130 ) ;
goto V_103;
}
V_50 = - V_127 ;
if ( ! ( V_130 -> V_159 . V_240 & V_245 ) )
goto V_1;
V_49 = F_119 ( V_130 -> V_144 -> V_178 , & V_130 -> V_158 . V_181 , & V_130 -> V_159 ) ;
V_50 = F_55 ( V_49 ) ;
if ( F_44 ( V_49 ) )
goto V_1;
V_50 = - V_123 ;
V_48 = F_116 ( V_49 , V_130 -> V_179 ) ;
if ( V_48 == NULL )
goto V_246;
if ( V_130 -> V_158 . V_244 != 0 )
F_111 ( V_130 , V_48 ) ;
F_103 ( V_48 , & V_130 -> V_158 . V_207 , NULL ,
V_130 -> V_161 . V_170 ) ;
F_120 ( V_49 ) ;
V_103:
return V_48 ;
V_246:
F_120 ( V_49 ) ;
V_1:
return F_45 ( V_50 ) ;
}
static struct V_47 *
F_121 ( struct V_157 * V_130 )
{
if ( V_130 -> V_161 . V_201 == V_247 )
return F_115 ( V_130 ) ;
return F_118 ( V_130 ) ;
}
static struct V_248 * F_122 ( struct V_47 * V_48 )
{
struct V_147 * V_148 = F_61 ( V_48 -> V_49 ) ;
struct V_248 * V_249 ;
F_24 ( & V_48 -> V_49 -> V_149 ) ;
F_123 (ctx, &nfsi->open_files, list) {
if ( V_249 -> V_48 != V_48 )
continue;
F_124 ( V_249 ) ;
F_26 ( & V_48 -> V_49 -> V_149 ) ;
return V_249 ;
}
F_26 ( & V_48 -> V_49 -> V_149 ) ;
return F_45 ( - V_250 ) ;
}
static struct V_157 * F_125 ( struct V_248 * V_249 , struct V_47 * V_48 )
{
struct V_157 * V_232 ;
V_232 = F_67 ( V_249 -> V_18 , V_48 -> V_179 , 0 , 0 , NULL , V_251 ) ;
if ( V_232 == NULL )
return F_45 ( - V_123 ) ;
V_232 -> V_48 = V_48 ;
F_74 ( & V_48 -> V_31 ) ;
return V_232 ;
}
static int F_126 ( struct V_157 * V_232 , T_3 V_170 , struct V_47 * * V_35 )
{
struct V_47 * V_252 ;
int V_50 ;
V_232 -> V_161 . V_182 = 0 ;
V_232 -> V_161 . V_170 = V_170 ;
memset ( & V_232 -> V_158 , 0 , sizeof( V_232 -> V_158 ) ) ;
memset ( & V_232 -> V_162 , 0 , sizeof( V_232 -> V_162 ) ) ;
F_64 ( V_232 ) ;
V_50 = F_127 ( V_232 ) ;
if ( V_50 != 0 )
return V_50 ;
V_252 = F_121 ( V_232 ) ;
if ( F_44 ( V_252 ) )
return F_55 ( V_252 ) ;
F_128 ( V_252 , V_170 ) ;
* V_35 = V_252 ;
return 0 ;
}
static int F_129 ( struct V_157 * V_232 , struct V_47 * V_48 )
{
struct V_47 * V_252 ;
int V_50 ;
F_130 ( V_223 , & V_48 -> V_171 ) ;
F_131 () ;
if ( V_48 -> V_219 != 0 ) {
F_130 ( V_218 , & V_48 -> V_171 ) ;
V_50 = F_126 ( V_232 , V_53 | V_183 , & V_252 ) ;
if ( V_50 != 0 )
return V_50 ;
if ( V_252 != V_48 )
return - V_239 ;
}
if ( V_48 -> V_217 != 0 ) {
F_130 ( V_216 , & V_48 -> V_171 ) ;
V_50 = F_126 ( V_232 , V_183 , & V_252 ) ;
if ( V_50 != 0 )
return V_50 ;
if ( V_252 != V_48 )
return - V_239 ;
}
if ( V_48 -> V_215 != 0 ) {
F_130 ( V_214 , & V_48 -> V_171 ) ;
V_50 = F_126 ( V_232 , V_53 , & V_252 ) ;
if ( V_50 != 0 )
return V_50 ;
if ( V_252 != V_48 )
return - V_239 ;
}
if ( F_42 ( V_223 , & V_48 -> V_171 ) == 0 &&
! F_106 ( & V_48 -> V_207 , & V_48 -> V_224 ) ) {
F_100 ( & V_48 -> V_225 ) ;
if ( F_42 ( V_223 , & V_48 -> V_171 ) == 0 )
F_97 ( & V_48 -> V_207 , & V_48 -> V_224 ) ;
F_101 ( & V_48 -> V_225 ) ;
}
return 0 ;
}
static int F_132 ( struct V_248 * V_249 , struct V_47 * V_48 )
{
struct V_220 * V_221 ;
struct V_157 * V_232 ;
T_3 V_244 = 0 ;
int V_253 ;
V_232 = F_125 ( V_249 , V_48 ) ;
if ( F_44 ( V_232 ) )
return F_55 ( V_232 ) ;
V_232 -> V_161 . V_201 = V_247 ;
V_232 -> V_161 . V_181 = F_75 ( V_48 -> V_49 ) ;
F_104 () ;
V_221 = F_105 ( F_61 ( V_48 -> V_49 ) -> V_221 ) ;
if ( V_221 != NULL && F_42 ( V_222 , & V_221 -> V_171 ) != 0 )
V_244 = V_221 -> type ;
F_107 () ;
V_232 -> V_161 . V_205 . V_244 = V_244 ;
V_253 = F_129 ( V_232 , V_48 ) ;
F_87 ( V_232 ) ;
return V_253 ;
}
static int F_133 ( struct V_248 * V_249 , struct V_47 * V_48 )
{
struct V_40 * V_41 = F_69 ( V_48 -> V_49 ) ;
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_132 ( V_249 , V_48 ) ;
if ( V_1 != - V_74 )
break;
F_13 ( V_41 , V_1 , & V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static int F_134 ( struct V_168 * V_169 , struct V_47 * V_48 )
{
struct V_248 * V_249 ;
int V_50 ;
V_249 = F_122 ( V_48 ) ;
if ( F_44 ( V_249 ) )
return F_55 ( V_249 ) ;
V_50 = F_133 ( V_249 , V_48 ) ;
F_135 ( V_249 ) ;
return V_50 ;
}
static int F_136 ( struct V_248 * V_249 , struct V_47 * V_48 , const T_5 * V_207 )
{
struct V_157 * V_232 ;
int V_50 ;
V_232 = F_125 ( V_249 , V_48 ) ;
if ( F_44 ( V_232 ) )
return F_55 ( V_232 ) ;
V_232 -> V_161 . V_201 = V_236 ;
F_97 ( & V_232 -> V_161 . V_205 . V_221 , V_207 ) ;
V_50 = F_129 ( V_232 , V_48 ) ;
F_87 ( V_232 ) ;
return V_50 ;
}
int F_137 ( struct V_248 * V_249 , struct V_47 * V_48 , const T_5 * V_207 )
{
struct V_43 V_44 = { } ;
struct V_40 * V_41 = F_69 ( V_48 -> V_49 ) ;
int V_1 ;
do {
V_1 = F_136 ( V_249 , V_48 , V_207 ) ;
switch ( V_1 ) {
case 0 :
case - V_250 :
case - V_239 :
goto V_103;
case - V_62 :
case - V_63 :
case - V_64 :
case - V_65 :
case - V_66 :
F_20 ( V_41 -> V_45 -> V_69 , V_1 ) ;
goto V_103;
case - V_60 :
case - V_59 :
case - V_58 :
F_18 ( V_41 -> V_45 ) ;
goto V_103;
case - V_39 :
case - V_55 :
case - V_56 :
case - V_57 :
F_138 ( V_48 -> V_49 ,
V_207 ) ;
F_16 ( V_41 , V_48 ) ;
case - V_123 :
V_1 = 0 ;
goto V_103;
}
V_1 = F_13 ( V_41 , V_1 , & V_44 ) ;
} while ( V_44 . V_51 );
V_103:
return V_1 ;
}
static void F_139 ( struct V_98 * V_99 , void * V_128 )
{
struct V_157 * V_130 = V_128 ;
V_130 -> V_238 = V_99 -> V_111 ;
if ( V_130 -> V_238 == 0 ) {
F_97 ( & V_130 -> V_158 . V_207 , & V_130 -> V_162 . V_207 ) ;
F_140 ( & V_130 -> V_179 -> V_176 , 0 ) ;
F_27 ( V_130 -> V_158 . V_41 , V_130 -> V_82 ) ;
V_130 -> V_237 = 1 ;
}
}
static void F_141 ( void * V_128 )
{
struct V_157 * V_130 = V_128 ;
struct V_47 * V_48 = NULL ;
if ( V_130 -> V_254 == 0 )
goto V_255;
if ( ! V_130 -> V_237 )
goto V_255;
V_48 = F_121 ( V_130 ) ;
if ( ! F_44 ( V_48 ) )
F_128 ( V_48 , V_130 -> V_161 . V_170 ) ;
V_255:
F_87 ( V_130 ) ;
}
static int F_142 ( struct V_157 * V_130 )
{
struct V_40 * V_41 = F_69 ( V_130 -> V_144 -> V_27 ) ;
struct V_98 * V_99 ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_258 ] ,
. V_259 = & V_130 -> V_163 ,
. V_260 = & V_130 -> V_162 ,
. V_261 = V_130 -> V_179 -> V_234 ,
} ;
struct V_136 V_262 = {
. V_138 = V_41 -> V_75 ,
. V_134 = & V_135 ,
. V_139 = & V_263 ,
. V_141 = V_130 ,
. V_264 = V_265 ,
. V_171 = V_266 ,
} ;
int V_253 ;
F_143 ( & V_130 -> V_208 ) ;
V_130 -> V_237 = 0 ;
V_130 -> V_238 = 0 ;
V_130 -> V_82 = V_124 ;
V_99 = F_54 ( & V_262 ) ;
if ( F_44 ( V_99 ) )
return F_55 ( V_99 ) ;
V_253 = F_89 ( V_99 ) ;
if ( V_253 != 0 ) {
V_130 -> V_254 = 1 ;
F_144 () ;
} else
V_253 = V_130 -> V_238 ;
F_56 ( V_99 ) ;
return V_253 ;
}
static void F_145 ( struct V_98 * V_99 , void * V_128 )
{
struct V_157 * V_130 = V_128 ;
struct V_168 * V_169 = V_130 -> V_179 ;
if ( F_146 ( V_130 -> V_161 . V_160 , V_99 ) != 0 )
return;
if ( V_130 -> V_48 != NULL ) {
struct V_220 * V_221 ;
if ( F_91 ( V_130 -> V_48 , V_130 -> V_161 . V_170 , V_130 -> V_161 . V_182 ) )
goto V_267;
F_104 () ;
V_221 = F_105 ( F_61 ( V_130 -> V_48 -> V_49 ) -> V_221 ) ;
if ( V_130 -> V_161 . V_201 != V_236 &&
F_92 ( V_221 , V_130 -> V_161 . V_170 ) )
goto V_268;
F_107 () ;
}
V_130 -> V_161 . V_189 = V_169 -> V_269 -> V_45 -> V_190 ;
if ( V_130 -> V_161 . V_201 == V_247 ) {
V_99 -> V_270 . V_256 = & V_257 [ V_271 ] ;
V_130 -> V_161 . V_199 = & V_272 [ 0 ] ;
F_147 ( & V_130 -> V_158 . V_181 , V_130 -> V_161 . V_181 ) ;
}
V_130 -> V_82 = V_124 ;
if ( F_49 ( V_130 -> V_161 . V_41 ,
& V_130 -> V_161 . V_132 ,
& V_130 -> V_158 . V_133 ,
V_99 ) != 0 )
F_148 ( V_130 -> V_161 . V_160 ) ;
return;
V_268:
F_107 () ;
V_267:
V_99 -> V_273 = NULL ;
F_38 ( V_99 , & V_130 -> V_158 . V_133 ) ;
}
static void F_149 ( struct V_98 * V_99 , void * V_128 )
{
struct V_157 * V_130 = V_128 ;
V_130 -> V_238 = V_99 -> V_111 ;
if ( ! F_38 ( V_99 , & V_130 -> V_158 . V_133 ) )
return;
if ( V_99 -> V_111 == 0 ) {
if ( V_130 -> V_158 . V_159 -> V_240 & V_241 ) {
switch ( V_130 -> V_158 . V_159 -> V_211 & V_274 ) {
case V_275 :
break;
case V_276 :
V_130 -> V_238 = - V_277 ;
break;
case V_278 :
V_130 -> V_238 = - V_279 ;
break;
default:
V_130 -> V_238 = - V_280 ;
}
}
F_27 ( V_130 -> V_158 . V_41 , V_130 -> V_82 ) ;
if ( ! ( V_130 -> V_158 . V_281 & V_282 ) )
F_140 ( & V_130 -> V_179 -> V_176 , 0 ) ;
}
V_130 -> V_237 = 1 ;
}
static void F_150 ( void * V_128 )
{
struct V_157 * V_130 = V_128 ;
struct V_47 * V_48 = NULL ;
if ( V_130 -> V_254 == 0 )
goto V_255;
if ( V_130 -> V_238 != 0 || ! V_130 -> V_237 )
goto V_255;
if ( V_130 -> V_158 . V_281 & V_282 )
goto V_255;
V_48 = F_121 ( V_130 ) ;
if ( ! F_44 ( V_48 ) )
F_128 ( V_48 , V_130 -> V_161 . V_170 ) ;
V_255:
F_87 ( V_130 ) ;
}
static int F_151 ( struct V_157 * V_130 , int V_283 )
{
struct V_49 * V_144 = V_130 -> V_144 -> V_27 ;
struct V_40 * V_41 = F_69 ( V_144 ) ;
struct V_284 * V_161 = & V_130 -> V_161 ;
struct V_285 * V_158 = & V_130 -> V_158 ;
struct V_98 * V_99 ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_286 ] ,
. V_259 = V_161 ,
. V_260 = V_158 ,
. V_261 = V_130 -> V_179 -> V_234 ,
} ;
struct V_136 V_262 = {
. V_138 = V_41 -> V_75 ,
. V_134 = & V_135 ,
. V_139 = & V_287 ,
. V_141 = V_130 ,
. V_264 = V_265 ,
. V_171 = V_266 ,
} ;
int V_253 ;
F_39 ( & V_161 -> V_132 , & V_158 -> V_133 , 1 ) ;
F_143 ( & V_130 -> V_208 ) ;
V_130 -> V_237 = 0 ;
V_130 -> V_238 = 0 ;
V_130 -> V_254 = 0 ;
if ( V_283 )
F_40 ( & V_161 -> V_132 ) ;
V_99 = F_54 ( & V_262 ) ;
if ( F_44 ( V_99 ) )
return F_55 ( V_99 ) ;
V_253 = F_89 ( V_99 ) ;
if ( V_253 != 0 ) {
V_130 -> V_254 = 1 ;
F_144 () ;
} else
V_253 = V_130 -> V_238 ;
F_56 ( V_99 ) ;
return V_253 ;
}
static int F_127 ( struct V_157 * V_130 )
{
struct V_49 * V_144 = V_130 -> V_144 -> V_27 ;
struct V_285 * V_158 = & V_130 -> V_158 ;
int V_253 ;
V_253 = F_151 ( V_130 , 1 ) ;
if ( V_253 != 0 || ! V_130 -> V_237 )
return V_253 ;
F_152 ( F_69 ( V_144 ) , & V_130 -> V_159 ) ;
if ( V_158 -> V_281 & V_282 ) {
V_253 = F_142 ( V_130 ) ;
if ( V_253 != 0 )
return V_253 ;
}
return V_253 ;
}
static int F_153 ( struct V_261 * V_288 ,
struct V_157 * V_232 ,
struct V_47 * V_48 , T_3 V_170 ,
int V_289 )
{
struct V_290 V_291 ;
T_6 V_292 ;
if ( V_232 -> V_158 . V_293 == 0 )
return 0 ;
V_292 = 0 ;
if ( V_289 & V_294 ) {
V_292 = V_295 ;
} else if ( V_170 & V_53 )
V_292 = V_296 ;
V_291 . V_288 = V_288 ;
V_291 . V_124 = V_124 ;
F_154 ( & V_291 , V_232 -> V_158 . V_297 ) ;
F_155 ( V_48 -> V_49 , & V_291 ) ;
if ( ( V_292 & ~ V_291 . V_292 & ( V_296 | V_295 ) ) == 0 )
return 0 ;
F_128 ( V_48 , V_170 ) ;
return - V_10 ;
}
static int F_156 ( struct V_157 * V_130 )
{
struct V_49 * V_144 = V_130 -> V_144 -> V_27 ;
struct V_40 * V_41 = F_69 ( V_144 ) ;
struct V_284 * V_161 = & V_130 -> V_161 ;
struct V_285 * V_158 = & V_130 -> V_158 ;
int V_253 ;
V_253 = F_151 ( V_130 , 0 ) ;
if ( ! V_130 -> V_237 )
return V_253 ;
if ( V_253 != 0 ) {
if ( V_253 == - V_7 &&
! ( V_161 -> V_182 & V_298 ) )
return - V_250 ;
return V_253 ;
}
F_152 ( V_41 , & V_130 -> V_159 ) ;
if ( V_161 -> V_182 & V_298 )
F_60 ( V_144 , & V_158 -> V_146 ) ;
if ( ( V_158 -> V_281 & V_299 ) == 0 )
V_41 -> V_78 &= ~ V_300 ;
if( V_158 -> V_281 & V_282 ) {
V_253 = F_142 ( V_130 ) ;
if ( V_253 != 0 )
return V_253 ;
}
if ( ! ( V_158 -> V_159 -> V_240 & V_245 ) )
F_157 ( V_41 , & V_158 -> V_181 , V_158 -> V_159 ) ;
return 0 ;
}
static int F_158 ( struct V_40 * V_41 )
{
return F_159 ( V_41 -> V_45 ) ;
}
static int F_160 ( struct V_248 * V_249 , struct V_47 * V_48 )
{
struct V_157 * V_232 ;
int V_50 ;
V_232 = F_125 ( V_249 , V_48 ) ;
if ( F_44 ( V_232 ) )
return F_55 ( V_232 ) ;
V_50 = F_129 ( V_232 , V_48 ) ;
if ( V_50 == - V_239 )
F_161 ( V_249 -> V_18 ) ;
F_87 ( V_232 ) ;
return V_50 ;
}
static int F_162 ( struct V_248 * V_249 , struct V_47 * V_48 )
{
struct V_40 * V_41 = F_69 ( V_48 -> V_49 ) ;
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_160 ( V_249 , V_48 ) ;
switch ( V_1 ) {
default:
goto V_103;
case - V_73 :
case - V_74 :
F_13 ( V_41 , V_1 , & V_44 ) ;
V_1 = 0 ;
}
} while ( V_44 . V_51 );
V_103:
return V_1 ;
}
static int F_163 ( struct V_168 * V_169 , struct V_47 * V_48 )
{
struct V_248 * V_249 ;
int V_50 ;
V_249 = F_122 ( V_48 ) ;
if ( F_44 ( V_249 ) )
return F_55 ( V_249 ) ;
V_50 = F_162 ( V_249 , V_48 ) ;
F_135 ( V_249 ) ;
return V_50 ;
}
static void F_164 ( struct V_47 * V_48 )
{
struct V_40 * V_41 = F_69 ( V_48 -> V_49 ) ;
T_5 * V_207 = & V_48 -> V_207 ;
int V_253 ;
if ( F_42 ( V_223 , & V_48 -> V_171 ) == 0 )
return;
V_253 = F_165 ( V_41 , V_207 ) ;
if ( V_253 != V_301 ) {
if ( V_253 != - V_57 )
F_166 ( V_41 , V_207 ) ;
F_17 ( V_48 -> V_49 ) ;
F_100 ( & V_48 -> V_225 ) ;
F_97 ( & V_48 -> V_207 , & V_48 -> V_224 ) ;
F_101 ( & V_48 -> V_225 ) ;
F_130 ( V_223 , & V_48 -> V_171 ) ;
}
}
static int F_167 ( struct V_47 * V_48 )
{
struct V_40 * V_41 = F_69 ( V_48 -> V_49 ) ;
T_5 * V_207 = & V_48 -> V_224 ;
int V_253 ;
if ( ( F_42 ( V_214 , & V_48 -> V_171 ) == 0 ) &&
( F_42 ( V_216 , & V_48 -> V_171 ) == 0 ) &&
( F_42 ( V_218 , & V_48 -> V_171 ) == 0 ) )
return - V_57 ;
V_253 = F_165 ( V_41 , V_207 ) ;
if ( V_253 != V_301 ) {
if ( V_253 != - V_57 )
F_166 ( V_41 , V_207 ) ;
F_130 ( V_214 , & V_48 -> V_171 ) ;
F_130 ( V_216 , & V_48 -> V_171 ) ;
F_130 ( V_218 , & V_48 -> V_171 ) ;
}
return V_253 ;
}
static int F_168 ( struct V_168 * V_169 , struct V_47 * V_48 )
{
int V_253 ;
F_164 ( V_48 ) ;
V_253 = F_167 ( V_48 ) ;
if ( V_253 != V_301 )
V_253 = F_163 ( V_169 , V_48 ) ;
return V_253 ;
}
static inline void F_169 ( struct V_157 * V_232 , struct V_172 * V_302 )
{
if ( ( V_232 -> V_158 . V_303 [ 1 ] & V_304 ) &&
! ( V_302 -> V_203 & V_305 ) )
V_302 -> V_203 |= V_306 ;
if ( ( V_232 -> V_158 . V_303 [ 1 ] & V_307 ) &&
! ( V_302 -> V_203 & V_308 ) )
V_302 -> V_203 |= V_309 ;
}
static int F_170 ( struct V_49 * V_144 ,
struct V_18 * V_18 ,
T_3 V_170 ,
int V_171 ,
struct V_172 * V_302 ,
struct V_261 * V_288 ,
struct V_47 * * V_35 ,
struct V_310 * * V_311 )
{
struct V_168 * V_169 ;
struct V_47 * V_48 = NULL ;
struct V_40 * V_41 = F_69 ( V_144 ) ;
struct V_157 * V_232 ;
int V_253 ;
V_253 = - V_123 ;
V_169 = F_171 ( V_41 , V_288 , V_312 ) ;
if ( V_169 == NULL ) {
F_2 ( L_22 ) ;
goto V_313;
}
V_253 = F_158 ( V_41 ) ;
if ( V_253 != 0 )
goto V_314;
if ( V_18 -> V_27 != NULL )
F_108 ( V_18 -> V_27 , V_170 ) ;
V_253 = - V_123 ;
V_232 = F_67 ( V_18 , V_169 , V_170 , V_171 , V_302 , V_312 ) ;
if ( V_232 == NULL )
goto V_314;
if ( V_311 && V_41 -> V_198 [ 2 ] & V_315 ) {
V_232 -> V_159 . V_316 = F_172 () ;
if ( ! V_232 -> V_159 . V_316 )
goto V_317;
V_232 -> V_161 . V_199 = & V_318 [ 0 ] ;
}
if ( V_18 -> V_27 != NULL )
V_232 -> V_48 = F_116 ( V_18 -> V_27 , V_169 ) ;
V_253 = F_156 ( V_232 ) ;
if ( V_253 != 0 )
goto V_317;
V_48 = F_121 ( V_232 ) ;
V_253 = F_55 ( V_48 ) ;
if ( F_44 ( V_48 ) )
goto V_317;
if ( V_41 -> V_78 & V_300 )
F_98 ( V_319 , & V_48 -> V_171 ) ;
V_253 = F_153 ( V_288 , V_232 , V_48 , V_170 , V_171 ) ;
if ( V_253 != 0 )
goto V_317;
if ( V_232 -> V_161 . V_182 & V_184 ) {
F_169 ( V_232 , V_302 ) ;
F_65 ( V_232 -> V_158 . V_159 ) ;
V_253 = F_173 ( V_48 -> V_49 , V_288 ,
V_232 -> V_158 . V_159 , V_302 ,
V_48 ) ;
if ( V_253 == 0 )
F_174 ( V_48 -> V_49 , V_302 ) ;
F_175 ( V_48 -> V_49 , V_232 -> V_158 . V_159 ) ;
}
if ( F_176 ( V_311 , V_232 -> V_159 . V_316 , V_41 ) )
* V_311 = V_232 -> V_159 . V_316 ;
else
F_78 ( V_232 -> V_159 . V_316 ) ;
V_232 -> V_159 . V_316 = NULL ;
F_87 ( V_232 ) ;
F_84 ( V_169 ) ;
* V_35 = V_48 ;
return 0 ;
V_317:
F_78 ( V_232 -> V_159 . V_316 ) ;
F_87 ( V_232 ) ;
V_314:
F_84 ( V_169 ) ;
V_313:
* V_35 = NULL ;
return V_253 ;
}
static struct V_47 * F_177 ( struct V_49 * V_144 ,
struct V_18 * V_18 ,
T_3 V_170 ,
int V_171 ,
struct V_172 * V_302 ,
struct V_261 * V_288 ,
struct V_310 * * V_311 )
{
struct V_43 V_44 = { } ;
struct V_47 * V_35 ;
int V_253 ;
V_170 &= V_53 | V_183 | V_320 ;
do {
V_253 = F_170 ( V_144 , V_18 , V_170 , V_171 , V_302 , V_288 ,
& V_35 , V_311 ) ;
if ( V_253 == 0 )
break;
if ( V_253 == - V_321 ) {
F_178 ( L_5
L_23 ,
F_69 ( V_144 ) -> V_45 -> V_81 ) ;
V_44 . V_51 = 1 ;
continue;
}
if ( V_253 == - V_57 ) {
V_44 . V_51 = 1 ;
continue;
}
if ( V_253 == - V_127 ) {
V_44 . V_51 = 1 ;
continue;
}
V_35 = F_45 ( F_13 ( F_69 ( V_144 ) ,
V_253 , & V_44 ) ) ;
} while ( V_44 . V_51 );
return V_35 ;
}
static int F_179 ( struct V_49 * V_49 , struct V_261 * V_288 ,
struct V_322 * V_323 , struct V_172 * V_302 ,
struct V_47 * V_48 )
{
struct V_40 * V_41 = F_69 ( V_49 ) ;
struct V_324 V_325 = {
. V_181 = F_75 ( V_49 ) ,
. V_326 = V_302 ,
. V_41 = V_41 ,
. V_197 = V_41 -> V_198 ,
} ;
struct V_327 V_35 = {
. V_323 = V_323 ,
. V_41 = V_41 ,
} ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_328 ] ,
. V_259 = & V_325 ,
. V_260 = & V_35 ,
. V_261 = V_288 ,
} ;
unsigned long V_82 = V_124 ;
int V_253 ;
F_65 ( V_323 ) ;
if ( V_48 != NULL ) {
struct V_329 V_330 = {
. V_331 = V_38 -> V_332 ,
. V_333 = V_38 -> V_334 ,
} ;
F_180 ( & V_325 . V_207 , V_48 , V_183 ,
& V_330 ) ;
} else if ( F_181 ( & V_325 . V_207 , V_49 ,
V_183 ) ) {
} else
F_97 ( & V_325 . V_207 , & V_335 ) ;
V_253 = F_59 ( V_41 -> V_75 , V_41 , & V_135 , & V_325 . V_132 , & V_35 . V_133 , 1 ) ;
if ( V_253 == 0 && V_48 != NULL )
F_27 ( V_41 , V_82 ) ;
return V_253 ;
}
static int F_173 ( struct V_49 * V_49 , struct V_261 * V_288 ,
struct V_322 * V_323 , struct V_172 * V_302 ,
struct V_47 * V_48 )
{
struct V_40 * V_41 = F_69 ( V_49 ) ;
struct V_43 V_44 = {
. V_48 = V_48 ,
. V_49 = V_49 ,
} ;
int V_1 ;
do {
V_1 = F_179 ( V_49 , V_288 , V_323 , V_302 , V_48 ) ;
switch ( V_1 ) {
case - V_52 :
if ( V_48 && ! ( V_48 -> V_48 & V_183 ) ) {
V_1 = - V_336 ;
if ( V_302 -> V_203 & V_337 )
V_1 = - V_10 ;
goto V_103;
}
}
V_1 = F_13 ( V_41 , V_1 , & V_44 ) ;
} while ( V_44 . V_51 );
V_103:
return V_1 ;
}
static void F_182 ( void * V_130 )
{
struct V_338 * V_128 = V_130 ;
struct V_168 * V_169 = V_128 -> V_48 -> V_179 ;
struct V_209 * V_210 = V_128 -> V_48 -> V_49 -> V_339 ;
if ( V_128 -> V_340 )
F_183 ( V_128 -> V_48 -> V_49 ) ;
F_83 ( V_128 -> V_48 ) ;
F_82 ( V_128 -> V_325 . V_160 ) ;
F_84 ( V_169 ) ;
F_184 ( V_210 ) ;
F_78 ( V_128 ) ;
}
static void F_185 ( struct V_47 * V_48 ,
T_3 V_170 )
{
F_24 ( & V_48 -> V_179 -> V_227 ) ;
if ( ! ( V_170 & V_53 ) )
F_130 ( V_214 , & V_48 -> V_171 ) ;
if ( ! ( V_170 & V_183 ) )
F_130 ( V_216 , & V_48 -> V_171 ) ;
F_130 ( V_218 , & V_48 -> V_171 ) ;
F_26 ( & V_48 -> V_179 -> V_227 ) ;
}
static void F_186 ( struct V_98 * V_99 , void * V_130 )
{
struct V_338 * V_128 = V_130 ;
struct V_47 * V_48 = V_128 -> V_48 ;
struct V_40 * V_41 = F_69 ( V_128 -> V_49 ) ;
F_2 ( L_24 , V_14 ) ;
if ( ! F_38 ( V_99 , & V_128 -> V_35 . V_133 ) )
return;
switch ( V_99 -> V_111 ) {
case 0 :
if ( V_128 -> V_340 )
F_187 ( V_48 -> V_49 ,
V_128 -> V_341 ) ;
F_99 ( V_48 , & V_128 -> V_35 . V_207 , 0 ) ;
F_27 ( V_41 , V_128 -> V_82 ) ;
F_185 ( V_48 ,
V_128 -> V_325 . V_170 ) ;
break;
case - V_59 :
case - V_77 :
case - V_57 :
case - V_58 :
if ( V_128 -> V_325 . V_170 == 0 )
break;
default:
if ( F_188 ( V_99 , V_41 , V_48 ) == - V_127 )
F_35 ( V_99 ) ;
}
F_148 ( V_128 -> V_325 . V_160 ) ;
F_117 ( V_128 -> V_49 , V_128 -> V_35 . V_323 ) ;
F_2 ( L_25 , V_14 , V_99 -> V_111 ) ;
}
static void F_189 ( struct V_98 * V_99 , void * V_130 )
{
struct V_338 * V_128 = V_130 ;
struct V_47 * V_48 = V_128 -> V_48 ;
struct V_49 * V_49 = V_128 -> V_49 ;
int V_342 = 0 ;
F_2 ( L_24 , V_14 ) ;
if ( F_146 ( V_128 -> V_325 . V_160 , V_99 ) != 0 )
return;
V_99 -> V_270 . V_256 = & V_257 [ V_343 ] ;
V_128 -> V_325 . V_170 = V_53 | V_183 ;
F_24 ( & V_48 -> V_179 -> V_227 ) ;
if ( V_48 -> V_219 == 0 ) {
if ( V_48 -> V_215 == 0 ) {
V_342 |= F_42 ( V_214 , & V_48 -> V_171 ) ;
V_342 |= F_42 ( V_218 , & V_48 -> V_171 ) ;
V_128 -> V_325 . V_170 &= ~ V_53 ;
}
if ( V_48 -> V_217 == 0 ) {
V_342 |= F_42 ( V_216 , & V_48 -> V_171 ) ;
V_342 |= F_42 ( V_218 , & V_48 -> V_171 ) ;
V_128 -> V_325 . V_170 &= ~ V_183 ;
}
}
F_26 ( & V_48 -> V_179 -> V_227 ) ;
if ( ! V_342 ) {
V_99 -> V_273 = NULL ;
F_38 ( V_99 , & V_128 -> V_35 . V_133 ) ;
goto V_103;
}
if ( V_128 -> V_325 . V_170 == 0 ) {
V_99 -> V_270 . V_256 = & V_257 [ V_344 ] ;
if ( V_128 -> V_340 &&
F_190 ( V_49 , & V_128 -> V_341 , V_99 ) )
goto V_103;
}
F_65 ( V_128 -> V_35 . V_323 ) ;
V_128 -> V_82 = V_124 ;
if ( F_49 ( F_69 ( V_49 ) ,
& V_128 -> V_325 . V_132 ,
& V_128 -> V_35 . V_133 ,
V_99 ) != 0 )
F_148 ( V_128 -> V_325 . V_160 ) ;
V_103:
F_2 ( L_26 , V_14 ) ;
}
int F_191 ( struct V_47 * V_48 , T_4 V_174 , int V_345 )
{
struct V_40 * V_41 = F_69 ( V_48 -> V_49 ) ;
struct V_338 * V_128 ;
struct V_168 * V_169 = V_48 -> V_179 ;
struct V_98 * V_99 ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_344 ] ,
. V_261 = V_48 -> V_179 -> V_234 ,
} ;
struct V_136 V_262 = {
. V_138 = V_41 -> V_75 ,
. V_134 = & V_135 ,
. V_139 = & V_346 ,
. V_264 = V_265 ,
. V_171 = V_266 ,
} ;
int V_253 = - V_123 ;
V_128 = F_70 ( sizeof( * V_128 ) , V_174 ) ;
if ( V_128 == NULL )
goto V_103;
F_39 ( & V_128 -> V_325 . V_132 , & V_128 -> V_35 . V_133 , 1 ) ;
V_128 -> V_49 = V_48 -> V_49 ;
V_128 -> V_48 = V_48 ;
V_128 -> V_325 . V_181 = F_75 ( V_48 -> V_49 ) ;
V_128 -> V_325 . V_207 = & V_48 -> V_224 ;
V_128 -> V_325 . V_160 = F_71 ( & V_48 -> V_179 -> V_176 , V_174 ) ;
if ( V_128 -> V_325 . V_160 == NULL )
goto V_347;
V_128 -> V_325 . V_170 = 0 ;
V_128 -> V_325 . V_197 = V_41 -> V_348 ;
V_128 -> V_35 . V_323 = & V_128 -> V_323 ;
V_128 -> V_35 . V_160 = V_128 -> V_325 . V_160 ;
V_128 -> V_35 . V_41 = V_41 ;
V_128 -> V_340 = F_192 ( V_48 -> V_49 ) ;
F_72 ( V_128 -> V_49 -> V_339 ) ;
V_135 . V_259 = & V_128 -> V_325 ;
V_135 . V_260 = & V_128 -> V_35 ;
V_262 . V_141 = V_128 ;
V_99 = F_54 ( & V_262 ) ;
if ( F_44 ( V_99 ) )
return F_55 ( V_99 ) ;
V_253 = 0 ;
if ( V_345 )
V_253 = F_90 ( V_99 ) ;
F_56 ( V_99 ) ;
return V_253 ;
V_347:
F_78 ( V_128 ) ;
V_103:
F_83 ( V_48 ) ;
F_84 ( V_169 ) ;
return V_253 ;
}
static struct V_49 *
F_193 ( struct V_49 * V_144 , struct V_248 * V_249 , int V_182 , struct V_172 * V_349 )
{
struct V_47 * V_48 ;
V_48 = F_177 ( V_144 , V_249 -> V_18 , V_249 -> V_211 , V_182 , V_349 ,
V_249 -> V_288 , & V_249 -> V_316 ) ;
if ( F_44 ( V_48 ) )
return F_194 ( V_48 ) ;
V_249 -> V_48 = V_48 ;
return F_195 ( V_48 -> V_49 ) ;
}
static void F_196 ( struct V_248 * V_249 , int V_350 )
{
if ( V_249 -> V_48 == NULL )
return;
if ( V_350 )
F_197 ( V_249 -> V_48 , V_249 -> V_211 ) ;
else
F_128 ( V_249 -> V_48 , V_249 -> V_211 ) ;
}
static int F_198 ( struct V_40 * V_41 , struct V_351 * V_352 )
{
struct V_353 args = {
. V_352 = V_352 ,
} ;
struct V_354 V_35 = {} ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_355 ] ,
. V_259 = & args ,
. V_260 = & V_35 ,
} ;
int V_253 ;
V_253 = F_59 ( V_41 -> V_75 , V_41 , & V_135 , & args . V_132 , & V_35 . V_133 , 0 ) ;
if ( V_253 == 0 ) {
memcpy ( V_41 -> V_198 , V_35 . V_198 , sizeof( V_41 -> V_198 ) ) ;
V_41 -> V_78 &= ~ ( V_356 | V_357 |
V_358 | V_359 |
V_360 | V_361 | V_362 |
V_363 | V_364 |
V_365 | V_366 ) ;
if ( V_35 . V_198 [ 0 ] & V_367 )
V_41 -> V_78 |= V_356 ;
if ( V_35 . V_368 != 0 )
V_41 -> V_78 |= V_357 ;
if ( V_35 . V_369 != 0 )
V_41 -> V_78 |= V_358 ;
if ( V_35 . V_198 [ 0 ] & V_26 )
V_41 -> V_78 |= V_359 ;
if ( V_35 . V_198 [ 1 ] & V_370 )
V_41 -> V_78 |= V_360 ;
if ( V_35 . V_198 [ 1 ] & V_371 )
V_41 -> V_78 |= V_361 ;
if ( V_35 . V_198 [ 1 ] & V_372 )
V_41 -> V_78 |= V_362 ;
if ( V_35 . V_198 [ 1 ] & V_373 )
V_41 -> V_78 |= V_363 ;
if ( V_35 . V_198 [ 1 ] & V_304 )
V_41 -> V_78 |= V_364 ;
if ( V_35 . V_198 [ 1 ] & V_374 )
V_41 -> V_78 |= V_365 ;
if ( V_35 . V_198 [ 1 ] & V_307 )
V_41 -> V_78 |= V_366 ;
memcpy ( V_41 -> V_348 , V_35 . V_198 , sizeof( V_41 -> V_348 ) ) ;
V_41 -> V_348 [ 0 ] &= V_375 | V_376 ;
V_41 -> V_348 [ 1 ] &= V_374 | V_307 ;
V_41 -> V_377 = V_35 . V_377 ;
V_41 -> V_378 = V_35 . V_378 ;
}
return V_253 ;
}
int F_199 ( struct V_40 * V_41 , struct V_351 * V_352 )
{
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_13 ( V_41 ,
F_198 ( V_41 , V_352 ) ,
& V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static int F_200 ( struct V_40 * V_41 , struct V_351 * V_352 ,
struct V_379 * V_380 )
{
struct V_381 args = {
. V_197 = V_200 ,
} ;
struct V_382 V_35 = {
. V_41 = V_41 ,
. V_323 = V_380 -> V_323 ,
. V_181 = V_352 ,
} ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_383 ] ,
. V_259 = & args ,
. V_260 = & V_35 ,
} ;
F_65 ( V_380 -> V_323 ) ;
return F_59 ( V_41 -> V_75 , V_41 , & V_135 , & args . V_132 , & V_35 . V_133 , 0 ) ;
}
static int F_201 ( struct V_40 * V_41 , struct V_351 * V_352 ,
struct V_379 * V_380 )
{
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_200 ( V_41 , V_352 , V_380 ) ;
switch ( V_1 ) {
case 0 :
case - V_4 :
goto V_103;
default:
V_1 = F_13 ( V_41 , V_1 , & V_44 ) ;
}
} while ( V_44 . V_51 );
V_103:
return V_1 ;
}
static int F_202 ( struct V_40 * V_41 , struct V_351 * V_352 ,
struct V_379 * V_380 , T_7 V_384 )
{
struct V_385 * V_386 ;
int V_50 ;
V_386 = F_203 ( V_384 , V_41 -> V_75 ) ;
if ( F_44 ( V_386 ) ) {
V_50 = - V_15 ;
goto V_103;
}
V_50 = F_201 ( V_41 , V_352 , V_380 ) ;
V_103:
return V_50 ;
}
static int F_204 ( struct V_40 * V_41 , struct V_351 * V_352 ,
struct V_379 * V_380 )
{
int V_387 , V_388 , V_253 = 0 ;
T_7 V_389 [ V_390 ] ;
V_388 = F_205 ( V_389 , F_206 ( V_389 ) ) ;
if ( V_388 < 0 )
return V_388 ;
for ( V_387 = 0 ; V_387 < V_388 ; V_387 ++ ) {
if ( V_389 [ V_387 ] == V_391 )
continue;
V_253 = F_202 ( V_41 , V_352 , V_380 , V_389 [ V_387 ] ) ;
if ( V_253 == - V_4 || V_253 == - V_10 )
continue;
break;
}
if ( V_253 == - V_10 )
V_253 = - V_5 ;
return V_253 ;
}
int F_207 ( struct V_40 * V_41 , struct V_351 * V_352 ,
struct V_379 * V_380 )
{
int V_392 = V_41 -> V_45 -> V_393 ;
int V_253 = F_201 ( V_41 , V_352 , V_380 ) ;
if ( ( V_253 == - V_4 ) && ! ( V_41 -> V_171 & V_394 ) )
V_253 = V_395 [ V_392 ] -> F_208 ( V_41 , V_352 , V_380 ) ;
if ( V_253 == 0 )
V_253 = F_199 ( V_41 , V_352 ) ;
if ( V_253 == 0 )
V_253 = F_209 ( V_41 , V_352 , V_380 ) ;
return F_1 ( V_253 ) ;
}
static int F_210 ( struct V_40 * V_41 , struct V_351 * V_396 ,
struct V_379 * V_380 )
{
int error ;
struct V_322 * V_323 = V_380 -> V_323 ;
error = F_199 ( V_41 , V_396 ) ;
if ( error < 0 ) {
F_2 ( L_27 , - error ) ;
return error ;
}
error = F_211 ( V_41 , V_396 , V_323 ) ;
if ( error < 0 ) {
F_2 ( L_28 , - error ) ;
return error ;
}
if ( V_323 -> V_240 & V_397 &&
! F_212 ( & V_41 -> V_398 , & V_323 -> V_398 ) )
memcpy ( & V_41 -> V_398 , & V_323 -> V_398 , sizeof( V_41 -> V_398 ) ) ;
return error ;
}
static int F_213 ( struct V_32 * V_75 , struct V_49 * V_144 ,
const struct V_399 * V_195 , struct V_322 * V_323 ,
struct V_351 * V_352 )
{
int V_253 = - V_123 ;
struct V_400 * V_400 = NULL ;
struct V_401 * V_402 = NULL ;
V_400 = F_214 ( V_312 ) ;
if ( V_400 == NULL )
goto V_103;
V_402 = F_215 ( sizeof( struct V_401 ) , V_312 ) ;
if ( V_402 == NULL )
goto V_103;
V_253 = F_216 ( V_75 , V_144 , V_195 , V_402 , V_400 ) ;
if ( V_253 != 0 )
goto V_103;
if ( F_212 ( & F_69 ( V_144 ) -> V_398 , & V_402 -> V_323 . V_398 ) ) {
F_2 ( L_29
L_30 , V_14 , V_195 -> V_195 ) ;
V_253 = - V_15 ;
goto V_103;
}
F_217 ( & V_402 -> V_323 ) ;
memcpy ( V_323 , & V_402 -> V_323 , sizeof( struct V_322 ) ) ;
memset ( V_352 , 0 , sizeof( struct V_351 ) ) ;
V_103:
if ( V_400 )
F_218 ( V_400 ) ;
F_78 ( V_402 ) ;
return V_253 ;
}
static int F_157 ( struct V_40 * V_41 , struct V_351 * V_352 , struct V_322 * V_323 )
{
struct V_403 args = {
. V_181 = V_352 ,
. V_197 = V_41 -> V_198 ,
} ;
struct V_404 V_35 = {
. V_323 = V_323 ,
. V_41 = V_41 ,
} ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_405 ] ,
. V_259 = & args ,
. V_260 = & V_35 ,
} ;
F_65 ( V_323 ) ;
return F_59 ( V_41 -> V_75 , V_41 , & V_135 , & args . V_132 , & V_35 . V_133 , 0 ) ;
}
static int F_211 ( struct V_40 * V_41 , struct V_351 * V_352 , struct V_322 * V_323 )
{
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_13 ( V_41 ,
F_157 ( V_41 , V_352 , V_323 ) ,
& V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static int
F_219 ( struct V_18 * V_18 , struct V_322 * V_323 ,
struct V_172 * V_302 )
{
struct V_49 * V_49 = V_18 -> V_27 ;
struct V_261 * V_288 = NULL ;
struct V_47 * V_48 = NULL ;
int V_253 ;
if ( F_220 ( V_49 ) )
F_221 ( V_49 ) ;
F_65 ( V_323 ) ;
if ( V_302 -> V_203 & V_337 )
V_302 -> V_203 &= ~ ( V_309 | V_406 | V_337 ) ;
if ( ( V_302 -> V_203 & ~ ( V_407 ) ) == 0 )
return 0 ;
if ( V_302 -> V_203 & V_407 ) {
struct V_248 * V_249 ;
V_249 = F_222 ( V_302 -> V_408 ) ;
if ( V_249 ) {
V_288 = V_249 -> V_288 ;
V_48 = V_249 -> V_48 ;
}
}
V_253 = F_173 ( V_49 , V_288 , V_323 , V_302 , V_48 ) ;
if ( V_253 == 0 )
F_174 ( V_49 , V_302 ) ;
return V_253 ;
}
static int F_223 ( struct V_32 * V_33 , struct V_49 * V_144 ,
const struct V_399 * V_195 , struct V_351 * V_352 ,
struct V_322 * V_323 )
{
struct V_40 * V_41 = F_69 ( V_144 ) ;
int V_253 ;
struct V_409 args = {
. V_197 = V_41 -> V_198 ,
. V_410 = F_75 ( V_144 ) ,
. V_195 = V_195 ,
} ;
struct V_382 V_35 = {
. V_41 = V_41 ,
. V_323 = V_323 ,
. V_181 = V_352 ,
} ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_411 ] ,
. V_259 = & args ,
. V_260 = & V_35 ,
} ;
F_65 ( V_323 ) ;
F_2 ( L_31 , V_195 -> V_195 ) ;
V_253 = F_59 ( V_33 , V_41 , & V_135 , & args . V_132 , & V_35 . V_133 , 0 ) ;
F_2 ( L_32 , V_253 ) ;
return V_253 ;
}
static void F_224 ( struct V_322 * V_323 )
{
V_323 -> V_240 |= V_241 | V_412 |
V_413 | V_414 ;
V_323 -> V_211 = V_278 | V_415 | V_416 ;
V_323 -> V_417 = 2 ;
}
static int F_225 ( struct V_32 * * V_33 , struct V_49 * V_144 ,
struct V_399 * V_195 , struct V_351 * V_352 ,
struct V_322 * V_323 )
{
struct V_43 V_44 = { } ;
struct V_32 * V_75 = * V_33 ;
int V_1 ;
do {
V_1 = F_223 ( V_75 , V_144 , V_195 , V_352 , V_323 ) ;
switch ( V_1 ) {
case - V_7 :
V_1 = - V_250 ;
goto V_103;
case - V_418 :
V_1 = F_213 ( V_75 , V_144 , V_195 , V_323 , V_352 ) ;
goto V_103;
case - V_4 :
V_1 = - V_5 ;
if ( V_75 != * V_33 )
goto V_103;
V_75 = F_226 ( V_75 , V_144 , V_195 ) ;
if ( F_44 ( V_75 ) )
return F_55 ( V_75 ) ;
V_44 . V_51 = 1 ;
break;
default:
V_1 = F_13 ( F_69 ( V_144 ) , V_1 , & V_44 ) ;
}
} while ( V_44 . V_51 );
V_103:
if ( V_1 == 0 )
* V_33 = V_75 ;
else if ( V_75 != * V_33 )
F_227 ( V_75 ) ;
return V_1 ;
}
static int F_228 ( struct V_49 * V_144 , struct V_399 * V_195 ,
struct V_351 * V_352 , struct V_322 * V_323 )
{
int V_253 ;
struct V_32 * V_75 = F_229 ( V_144 ) ;
V_253 = F_225 ( & V_75 , V_144 , V_195 , V_352 , V_323 ) ;
if ( V_75 != F_229 ( V_144 ) ) {
F_227 ( V_75 ) ;
F_224 ( V_323 ) ;
}
return V_253 ;
}
struct V_32 *
F_230 ( struct V_49 * V_144 , struct V_399 * V_195 ,
struct V_351 * V_352 , struct V_322 * V_323 )
{
int V_253 ;
struct V_32 * V_75 = F_231 ( F_229 ( V_144 ) ) ;
V_253 = F_225 ( & V_75 , V_144 , V_195 , V_352 , V_323 ) ;
if ( V_253 < 0 ) {
F_227 ( V_75 ) ;
return F_45 ( V_253 ) ;
}
return V_75 ;
}
static int F_232 ( struct V_49 * V_49 , struct V_290 * V_419 )
{
struct V_40 * V_41 = F_69 ( V_49 ) ;
struct V_420 args = {
. V_181 = F_75 ( V_49 ) ,
. V_197 = V_41 -> V_348 ,
} ;
struct V_421 V_35 = {
. V_41 = V_41 ,
} ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_422 ] ,
. V_259 = & args ,
. V_260 = & V_35 ,
. V_261 = V_419 -> V_288 ,
} ;
int V_211 = V_419 -> V_292 ;
int V_253 ;
if ( V_211 & V_296 )
args . V_165 |= V_185 ;
if ( F_233 ( V_49 -> V_423 ) ) {
if ( V_211 & V_424 )
args . V_165 |= V_186 | V_187 | V_425 ;
if ( V_211 & V_295 )
args . V_165 |= V_426 ;
} else {
if ( V_211 & V_424 )
args . V_165 |= V_186 | V_187 ;
if ( V_211 & V_295 )
args . V_165 |= V_188 ;
}
V_35 . V_323 = F_234 () ;
if ( V_35 . V_323 == NULL )
return - V_123 ;
V_253 = F_59 ( V_41 -> V_75 , V_41 , & V_135 , & args . V_132 , & V_35 . V_133 , 0 ) ;
if ( ! V_253 ) {
F_154 ( V_419 , V_35 . V_165 ) ;
F_117 ( V_49 , V_35 . V_323 ) ;
}
F_235 ( V_35 . V_323 ) ;
return V_253 ;
}
static int F_236 ( struct V_49 * V_49 , struct V_290 * V_419 )
{
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_69 ( V_49 ) ,
F_232 ( V_49 , V_419 ) ,
& V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static int F_237 ( struct V_49 * V_49 , struct V_400 * V_400 ,
unsigned int V_30 , unsigned int V_427 )
{
struct V_428 args = {
. V_181 = F_75 ( V_49 ) ,
. V_30 = V_30 ,
. V_427 = V_427 ,
. V_23 = & V_400 ,
} ;
struct V_429 V_35 ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_430 ] ,
. V_259 = & args ,
. V_260 = & V_35 ,
} ;
return F_59 ( F_69 ( V_49 ) -> V_75 , F_69 ( V_49 ) , & V_135 , & args . V_132 , & V_35 . V_133 , 0 ) ;
}
static int F_238 ( struct V_49 * V_49 , struct V_400 * V_400 ,
unsigned int V_30 , unsigned int V_427 )
{
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_69 ( V_49 ) ,
F_237 ( V_49 , V_400 , V_30 , V_427 ) ,
& V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static int
F_239 ( struct V_49 * V_144 , struct V_18 * V_18 , struct V_172 * V_302 ,
int V_171 )
{
struct V_248 * V_249 ;
struct V_47 * V_48 ;
int V_253 = 0 ;
V_249 = F_240 ( V_18 , V_53 ) ;
if ( F_44 ( V_249 ) )
return F_55 ( V_249 ) ;
V_302 -> V_431 &= ~ F_241 () ;
V_48 = F_177 ( V_144 , V_18 , V_249 -> V_211 ,
V_171 , V_302 , V_249 -> V_288 ,
& V_249 -> V_316 ) ;
F_161 ( V_18 ) ;
if ( F_44 ( V_48 ) ) {
V_253 = F_55 ( V_48 ) ;
goto V_103;
}
F_242 ( V_18 , F_195 ( V_48 -> V_49 ) ) ;
F_243 ( V_18 , F_244 ( V_144 ) ) ;
V_249 -> V_48 = V_48 ;
V_103:
F_135 ( V_249 ) ;
return V_253 ;
}
static int F_245 ( struct V_49 * V_144 , struct V_399 * V_195 )
{
struct V_40 * V_41 = F_69 ( V_144 ) ;
struct V_432 args = {
. V_181 = F_75 ( V_144 ) ,
. V_195 = * V_195 ,
} ;
struct V_433 V_35 = {
. V_41 = V_41 ,
} ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_434 ] ,
. V_259 = & args ,
. V_260 = & V_35 ,
} ;
int V_253 ;
V_253 = F_59 ( V_41 -> V_75 , V_41 , & V_135 , & args . V_132 , & V_35 . V_133 , 1 ) ;
if ( V_253 == 0 )
F_60 ( V_144 , & V_35 . V_146 ) ;
return V_253 ;
}
static int F_246 ( struct V_49 * V_144 , struct V_399 * V_195 )
{
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_69 ( V_144 ) ,
F_245 ( V_144 , V_195 ) ,
& V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static void F_247 ( struct V_134 * V_135 , struct V_49 * V_144 )
{
struct V_40 * V_41 = F_69 ( V_144 ) ;
struct V_432 * args = V_135 -> V_259 ;
struct V_433 * V_35 = V_135 -> V_260 ;
V_35 -> V_41 = V_41 ;
V_135 -> V_256 = & V_257 [ V_434 ] ;
F_39 ( & args -> V_132 , & V_35 -> V_133 , 1 ) ;
}
static void F_248 ( struct V_98 * V_99 , struct V_435 * V_130 )
{
F_49 ( F_69 ( V_130 -> V_144 ) ,
& V_130 -> args . V_132 ,
& V_130 -> V_35 . V_133 ,
V_99 ) ;
}
static int F_249 ( struct V_98 * V_99 , struct V_49 * V_144 )
{
struct V_433 * V_35 = V_99 -> V_270 . V_260 ;
if ( ! F_38 ( V_99 , & V_35 -> V_133 ) )
return 0 ;
if ( F_188 ( V_99 , V_35 -> V_41 , NULL ) == - V_127 )
return 0 ;
F_60 ( V_144 , & V_35 -> V_146 ) ;
return 1 ;
}
static void F_250 ( struct V_134 * V_135 , struct V_49 * V_144 )
{
struct V_40 * V_41 = F_69 ( V_144 ) ;
struct V_436 * V_325 = V_135 -> V_259 ;
struct V_437 * V_35 = V_135 -> V_260 ;
V_135 -> V_256 = & V_257 [ V_438 ] ;
V_35 -> V_41 = V_41 ;
F_39 ( & V_325 -> V_132 , & V_35 -> V_133 , 1 ) ;
}
static void F_251 ( struct V_98 * V_99 , struct V_439 * V_130 )
{
F_49 ( F_69 ( V_130 -> V_440 ) ,
& V_130 -> args . V_132 ,
& V_130 -> V_35 . V_133 ,
V_99 ) ;
}
static int F_252 ( struct V_98 * V_99 , struct V_49 * V_440 ,
struct V_49 * V_441 )
{
struct V_437 * V_35 = V_99 -> V_270 . V_260 ;
if ( ! F_38 ( V_99 , & V_35 -> V_133 ) )
return 0 ;
if ( F_188 ( V_99 , V_35 -> V_41 , NULL ) == - V_127 )
return 0 ;
F_60 ( V_440 , & V_35 -> V_442 ) ;
F_60 ( V_441 , & V_35 -> V_443 ) ;
return 1 ;
}
static int F_253 ( struct V_49 * V_440 , struct V_399 * V_444 ,
struct V_49 * V_441 , struct V_399 * V_445 )
{
struct V_40 * V_41 = F_69 ( V_440 ) ;
struct V_436 V_325 = {
. V_440 = F_75 ( V_440 ) ,
. V_441 = F_75 ( V_441 ) ,
. V_444 = V_444 ,
. V_445 = V_445 ,
} ;
struct V_437 V_35 = {
. V_41 = V_41 ,
} ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_438 ] ,
. V_259 = & V_325 ,
. V_260 = & V_35 ,
} ;
int V_253 = - V_123 ;
V_253 = F_59 ( V_41 -> V_75 , V_41 , & V_135 , & V_325 . V_132 , & V_35 . V_133 , 1 ) ;
if ( ! V_253 ) {
F_60 ( V_440 , & V_35 . V_442 ) ;
F_60 ( V_441 , & V_35 . V_443 ) ;
}
return V_253 ;
}
static int F_254 ( struct V_49 * V_440 , struct V_399 * V_444 ,
struct V_49 * V_441 , struct V_399 * V_445 )
{
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_69 ( V_440 ) ,
F_253 ( V_440 , V_444 ,
V_441 , V_445 ) ,
& V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static int F_255 ( struct V_49 * V_49 , struct V_49 * V_144 , struct V_399 * V_195 )
{
struct V_40 * V_41 = F_69 ( V_49 ) ;
struct V_446 V_325 = {
. V_181 = F_75 ( V_49 ) ,
. V_410 = F_75 ( V_144 ) ,
. V_195 = V_195 ,
. V_197 = V_41 -> V_198 ,
} ;
struct V_447 V_35 = {
. V_41 = V_41 ,
} ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_448 ] ,
. V_259 = & V_325 ,
. V_260 = & V_35 ,
} ;
int V_253 = - V_123 ;
V_35 . V_323 = F_234 () ;
if ( V_35 . V_323 == NULL )
goto V_103;
V_253 = F_59 ( V_41 -> V_75 , V_41 , & V_135 , & V_325 . V_132 , & V_35 . V_133 , 1 ) ;
if ( ! V_253 ) {
F_60 ( V_144 , & V_35 . V_146 ) ;
F_175 ( V_49 , V_35 . V_323 ) ;
}
V_103:
F_235 ( V_35 . V_323 ) ;
return V_253 ;
}
static int F_256 ( struct V_49 * V_49 , struct V_49 * V_144 , struct V_399 * V_195 )
{
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_69 ( V_49 ) ,
F_255 ( V_49 , V_144 , V_195 ) ,
& V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static struct V_449 * F_257 ( struct V_49 * V_144 ,
struct V_399 * V_195 , struct V_172 * V_302 , T_6 V_450 )
{
struct V_449 * V_130 ;
V_130 = F_70 ( sizeof( * V_130 ) , V_312 ) ;
if ( V_130 != NULL ) {
struct V_40 * V_41 = F_69 ( V_144 ) ;
V_130 -> V_135 . V_256 = & V_257 [ V_451 ] ;
V_130 -> V_135 . V_259 = & V_130 -> V_325 ;
V_130 -> V_135 . V_260 = & V_130 -> V_35 ;
V_130 -> V_325 . V_410 = F_75 ( V_144 ) ;
V_130 -> V_325 . V_41 = V_41 ;
V_130 -> V_325 . V_195 = V_195 ;
V_130 -> V_325 . V_173 = V_302 ;
V_130 -> V_325 . V_450 = V_450 ;
V_130 -> V_325 . V_197 = V_41 -> V_198 ;
V_130 -> V_35 . V_41 = V_41 ;
V_130 -> V_35 . V_181 = & V_130 -> V_181 ;
V_130 -> V_35 . V_323 = & V_130 -> V_323 ;
F_65 ( V_130 -> V_35 . V_323 ) ;
}
return V_130 ;
}
static int F_258 ( struct V_49 * V_144 , struct V_18 * V_18 , struct V_449 * V_130 )
{
int V_253 = F_59 ( F_69 ( V_144 ) -> V_75 , F_69 ( V_144 ) , & V_130 -> V_135 ,
& V_130 -> V_325 . V_132 , & V_130 -> V_35 . V_133 , 1 ) ;
if ( V_253 == 0 ) {
F_60 ( V_144 , & V_130 -> V_35 . V_452 ) ;
V_253 = F_259 ( V_18 , V_130 -> V_35 . V_181 , V_130 -> V_35 . V_323 ) ;
}
return V_253 ;
}
static void F_260 ( struct V_449 * V_130 )
{
F_78 ( V_130 ) ;
}
static int F_261 ( struct V_49 * V_144 , struct V_18 * V_18 ,
struct V_400 * V_400 , unsigned int V_388 , struct V_172 * V_302 )
{
struct V_449 * V_130 ;
int V_253 = - V_453 ;
if ( V_388 > V_454 )
goto V_103;
V_253 = - V_123 ;
V_130 = F_257 ( V_144 , & V_18 -> V_196 , V_302 , V_455 ) ;
if ( V_130 == NULL )
goto V_103;
V_130 -> V_135 . V_256 = & V_257 [ V_456 ] ;
V_130 -> V_325 . V_205 . V_457 . V_23 = & V_400 ;
V_130 -> V_325 . V_205 . V_457 . V_388 = V_388 ;
V_253 = F_258 ( V_144 , V_18 , V_130 ) ;
F_260 ( V_130 ) ;
V_103:
return V_253 ;
}
static int F_262 ( struct V_49 * V_144 , struct V_18 * V_18 ,
struct V_400 * V_400 , unsigned int V_388 , struct V_172 * V_302 )
{
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_69 ( V_144 ) ,
F_261 ( V_144 , V_18 , V_400 ,
V_388 , V_302 ) ,
& V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static int F_263 ( struct V_49 * V_144 , struct V_18 * V_18 ,
struct V_172 * V_302 )
{
struct V_449 * V_130 ;
int V_253 = - V_123 ;
V_130 = F_257 ( V_144 , & V_18 -> V_196 , V_302 , V_458 ) ;
if ( V_130 == NULL )
goto V_103;
V_253 = F_258 ( V_144 , V_18 , V_130 ) ;
F_260 ( V_130 ) ;
V_103:
return V_253 ;
}
static int F_264 ( struct V_49 * V_144 , struct V_18 * V_18 ,
struct V_172 * V_302 )
{
struct V_43 V_44 = { } ;
int V_1 ;
V_302 -> V_431 &= ~ F_241 () ;
do {
V_1 = F_13 ( F_69 ( V_144 ) ,
F_263 ( V_144 , V_18 , V_302 ) ,
& V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static int F_265 ( struct V_18 * V_18 , struct V_261 * V_288 ,
T_1 V_16 , struct V_400 * * V_23 , unsigned int V_31 , int V_459 )
{
struct V_49 * V_144 = V_18 -> V_27 ;
struct V_19 args = {
. V_181 = F_75 ( V_144 ) ,
. V_23 = V_23 ,
. V_30 = 0 ,
. V_31 = V_31 ,
. V_197 = F_69 ( V_18 -> V_27 ) -> V_198 ,
. V_459 = V_459 ,
} ;
struct V_460 V_35 ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_461 ] ,
. V_259 = & args ,
. V_260 = & V_35 ,
. V_261 = V_288 ,
} ;
int V_253 ;
F_2 ( L_33 , V_14 ,
V_18 -> V_29 -> V_196 . V_195 ,
V_18 -> V_196 . V_195 ,
( unsigned long long ) V_16 ) ;
F_3 ( V_16 , F_61 ( V_144 ) -> V_462 , V_18 , & args ) ;
V_35 . V_30 = args . V_30 ;
V_253 = F_59 ( F_69 ( V_144 ) -> V_75 , F_69 ( V_144 ) , & V_135 , & args . V_132 , & V_35 . V_133 , 0 ) ;
if ( V_253 >= 0 ) {
memcpy ( F_61 ( V_144 ) -> V_462 , V_35 . V_17 . V_130 , V_463 ) ;
V_253 += args . V_30 ;
}
F_266 ( V_144 ) ;
F_2 ( L_34 , V_14 , V_253 ) ;
return V_253 ;
}
static int F_267 ( struct V_18 * V_18 , struct V_261 * V_288 ,
T_1 V_16 , struct V_400 * * V_23 , unsigned int V_31 , int V_459 )
{
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_69 ( V_18 -> V_27 ) ,
F_265 ( V_18 , V_288 , V_16 ,
V_23 , V_31 , V_459 ) ,
& V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static int F_268 ( struct V_49 * V_144 , struct V_18 * V_18 ,
struct V_172 * V_302 , T_8 V_464 )
{
struct V_449 * V_130 ;
int V_211 = V_302 -> V_431 ;
int V_253 = - V_123 ;
V_130 = F_257 ( V_144 , & V_18 -> V_196 , V_302 , V_465 ) ;
if ( V_130 == NULL )
goto V_103;
if ( F_269 ( V_211 ) )
V_130 -> V_325 . V_450 = V_466 ;
else if ( F_270 ( V_211 ) ) {
V_130 -> V_325 . V_450 = V_467 ;
V_130 -> V_325 . V_205 . V_468 . V_469 = F_271 ( V_464 ) ;
V_130 -> V_325 . V_205 . V_468 . V_470 = F_272 ( V_464 ) ;
}
else if ( F_273 ( V_211 ) ) {
V_130 -> V_325 . V_450 = V_471 ;
V_130 -> V_325 . V_205 . V_468 . V_469 = F_271 ( V_464 ) ;
V_130 -> V_325 . V_205 . V_468 . V_470 = F_272 ( V_464 ) ;
} else if ( ! F_274 ( V_211 ) ) {
V_253 = - V_8 ;
goto V_255;
}
V_253 = F_258 ( V_144 , V_18 , V_130 ) ;
V_255:
F_260 ( V_130 ) ;
V_103:
return V_253 ;
}
static int F_275 ( struct V_49 * V_144 , struct V_18 * V_18 ,
struct V_172 * V_302 , T_8 V_464 )
{
struct V_43 V_44 = { } ;
int V_1 ;
V_302 -> V_431 &= ~ F_241 () ;
do {
V_1 = F_13 ( F_69 ( V_144 ) ,
F_268 ( V_144 , V_18 , V_302 , V_464 ) ,
& V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static int F_276 ( struct V_40 * V_41 , struct V_351 * V_352 ,
struct V_472 * V_473 )
{
struct V_474 args = {
. V_181 = V_352 ,
. V_197 = V_41 -> V_198 ,
} ;
struct V_475 V_35 = {
. V_473 = V_473 ,
} ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_476 ] ,
. V_259 = & args ,
. V_260 = & V_35 ,
} ;
F_65 ( V_473 -> V_323 ) ;
return F_59 ( V_41 -> V_75 , V_41 , & V_135 , & args . V_132 , & V_35 . V_133 , 0 ) ;
}
static int F_277 ( struct V_40 * V_41 , struct V_351 * V_352 , struct V_472 * V_473 )
{
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_13 ( V_41 ,
F_276 ( V_41 , V_352 , V_473 ) ,
& V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static int F_278 ( struct V_40 * V_41 , struct V_351 * V_352 ,
struct V_379 * V_477 )
{
struct V_478 args = {
. V_181 = V_352 ,
. V_197 = V_41 -> V_198 ,
} ;
struct V_479 V_35 = {
. V_477 = V_477 ,
} ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_480 ] ,
. V_259 = & args ,
. V_260 = & V_35 ,
} ;
return F_59 ( V_41 -> V_75 , V_41 , & V_135 , & args . V_132 , & V_35 . V_133 , 0 ) ;
}
static int F_209 ( struct V_40 * V_41 , struct V_351 * V_352 , struct V_379 * V_477 )
{
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_13 ( V_41 ,
F_278 ( V_41 , V_352 , V_477 ) ,
& V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static int F_279 ( struct V_40 * V_41 , struct V_351 * V_352 , struct V_379 * V_477 )
{
int error ;
F_65 ( V_477 -> V_323 ) ;
error = F_209 ( V_41 , V_352 , V_477 ) ;
if ( error == 0 ) {
V_41 -> V_481 = V_477 -> V_482 ;
F_280 ( V_41 , V_352 , V_477 -> V_483 ) ;
}
return error ;
}
static int F_281 ( struct V_40 * V_41 , struct V_351 * V_352 ,
struct V_484 * V_485 )
{
struct V_486 args = {
. V_181 = V_352 ,
. V_197 = V_41 -> V_198 ,
} ;
struct V_487 V_35 = {
. V_485 = V_485 ,
} ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_488 ] ,
. V_259 = & args ,
. V_260 = & V_35 ,
} ;
if ( ( args . V_197 [ 0 ] & V_489 [ 0 ] ) == 0 ) {
memset ( V_485 , 0 , sizeof( * V_485 ) ) ;
return 0 ;
}
F_65 ( V_485 -> V_323 ) ;
return F_59 ( V_41 -> V_75 , V_41 , & V_135 , & args . V_132 , & V_35 . V_133 , 0 ) ;
}
static int F_282 ( struct V_40 * V_41 , struct V_351 * V_352 ,
struct V_484 * V_485 )
{
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_13 ( V_41 ,
F_281 ( V_41 , V_352 , V_485 ) ,
& V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
void F_283 ( struct V_490 * V_130 )
{
F_266 ( V_130 -> V_491 -> V_49 ) ;
}
static int F_284 ( struct V_98 * V_99 , struct V_490 * V_130 )
{
struct V_40 * V_41 = F_69 ( V_130 -> V_491 -> V_49 ) ;
if ( F_188 ( V_99 , V_41 , V_130 -> args . V_492 -> V_48 ) == - V_127 ) {
F_35 ( V_99 ) ;
return - V_127 ;
}
F_283 ( V_130 ) ;
if ( V_99 -> V_111 > 0 )
F_27 ( V_41 , V_130 -> V_82 ) ;
return 0 ;
}
static int F_285 ( struct V_98 * V_99 , struct V_490 * V_130 )
{
F_2 ( L_12 , V_14 ) ;
if ( ! F_38 ( V_99 , & V_130 -> V_35 . V_133 ) )
return - V_127 ;
return V_130 -> V_493 ? V_130 -> V_493 ( V_99 , V_130 ) :
F_284 ( V_99 , V_130 ) ;
}
static void F_286 ( struct V_490 * V_130 , struct V_134 * V_135 )
{
V_130 -> V_82 = V_124 ;
V_130 -> V_493 = F_284 ;
V_135 -> V_256 = & V_257 [ V_494 ] ;
F_39 ( & V_130 -> args . V_132 , & V_130 -> V_35 . V_133 , 0 ) ;
}
static void F_287 ( struct V_98 * V_99 , struct V_490 * V_130 )
{
F_49 ( F_69 ( V_130 -> V_491 -> V_49 ) ,
& V_130 -> args . V_132 ,
& V_130 -> V_35 . V_133 ,
V_99 ) ;
}
static int F_288 ( struct V_98 * V_99 , struct V_495 * V_130 )
{
struct V_49 * V_49 = V_130 -> V_491 -> V_49 ;
if ( F_188 ( V_99 , F_69 ( V_49 ) , V_130 -> args . V_492 -> V_48 ) == - V_127 ) {
F_35 ( V_99 ) ;
return - V_127 ;
}
if ( V_99 -> V_111 >= 0 ) {
F_27 ( F_69 ( V_49 ) , V_130 -> V_82 ) ;
F_289 ( V_49 , & V_130 -> V_323 ) ;
}
return 0 ;
}
static int F_290 ( struct V_98 * V_99 , struct V_495 * V_130 )
{
if ( ! F_38 ( V_99 , & V_130 -> V_35 . V_133 ) )
return - V_127 ;
return V_130 -> V_496 ? V_130 -> V_496 ( V_99 , V_130 ) :
F_288 ( V_99 , V_130 ) ;
}
static
bool F_291 ( const struct V_495 * V_130 )
{
const struct V_497 * V_498 = V_130 -> V_491 ;
if ( V_130 -> V_499 != NULL || V_498 -> V_500 != NULL )
return false ;
return F_14 ( V_498 -> V_49 , V_53 ) == 0 ;
}
static void F_292 ( struct V_495 * V_130 , struct V_134 * V_135 )
{
struct V_40 * V_41 = F_69 ( V_130 -> V_491 -> V_49 ) ;
if ( ! F_291 ( V_130 ) ) {
V_130 -> args . V_197 = NULL ;
V_130 -> V_35 . V_323 = NULL ;
} else
V_130 -> args . V_197 = V_41 -> V_348 ;
if ( ! V_130 -> V_496 )
V_130 -> V_496 = F_288 ;
V_130 -> V_35 . V_41 = V_41 ;
V_130 -> V_82 = V_124 ;
V_135 -> V_256 = & V_257 [ V_501 ] ;
F_39 ( & V_130 -> args . V_132 , & V_130 -> V_35 . V_133 , 1 ) ;
}
static void F_293 ( struct V_98 * V_99 , struct V_495 * V_130 )
{
F_49 ( F_69 ( V_130 -> V_491 -> V_49 ) ,
& V_130 -> args . V_132 ,
& V_130 -> V_35 . V_133 ,
V_99 ) ;
}
static void F_294 ( struct V_98 * V_99 , struct V_502 * V_130 )
{
F_49 ( F_69 ( V_130 -> V_49 ) ,
& V_130 -> args . V_132 ,
& V_130 -> V_35 . V_133 ,
V_99 ) ;
}
static int F_295 ( struct V_98 * V_99 , struct V_502 * V_130 )
{
struct V_49 * V_49 = V_130 -> V_49 ;
if ( F_188 ( V_99 , F_69 ( V_49 ) , NULL ) == - V_127 ) {
F_35 ( V_99 ) ;
return - V_127 ;
}
return 0 ;
}
static int F_296 ( struct V_98 * V_99 , struct V_502 * V_130 )
{
if ( ! F_38 ( V_99 , & V_130 -> V_35 . V_133 ) )
return - V_127 ;
return V_130 -> V_503 ( V_99 , V_130 ) ;
}
static void F_297 ( struct V_502 * V_130 , struct V_134 * V_135 )
{
struct V_40 * V_41 = F_69 ( V_130 -> V_49 ) ;
if ( V_130 -> V_503 == NULL )
V_130 -> V_503 = F_295 ;
V_130 -> V_35 . V_41 = V_41 ;
V_135 -> V_256 = & V_257 [ V_504 ] ;
F_39 ( & V_130 -> args . V_132 , & V_130 -> V_35 . V_133 , 1 ) ;
}
static void F_298 ( void * V_128 )
{
struct V_505 * V_130 = V_128 ;
struct V_45 * V_46 = V_130 -> V_75 ;
if ( F_299 ( & V_46 -> V_506 ) > 1 )
F_300 ( V_46 ) ;
F_301 ( V_46 ) ;
F_78 ( V_130 ) ;
}
static void F_302 ( struct V_98 * V_99 , void * V_128 )
{
struct V_505 * V_130 = V_128 ;
struct V_45 * V_46 = V_130 -> V_75 ;
unsigned long V_82 = V_130 -> V_82 ;
if ( V_99 -> V_111 < 0 ) {
if ( F_42 ( V_507 , & V_46 -> V_508 ) == 0 )
return;
if ( V_99 -> V_111 != V_509 ) {
F_18 ( V_46 ) ;
return;
}
F_303 ( V_46 ) ;
}
F_23 ( V_46 , V_82 ) ;
}
static int F_304 ( struct V_45 * V_46 , struct V_261 * V_288 , unsigned V_510 )
{
struct V_134 V_135 = {
. V_256 = & V_257 [ V_511 ] ,
. V_259 = V_46 ,
. V_261 = V_288 ,
} ;
struct V_505 * V_130 ;
if ( V_510 == 0 )
return 0 ;
if ( ! F_305 ( & V_46 -> V_506 ) )
return - V_15 ;
V_130 = F_215 ( sizeof( * V_130 ) , V_251 ) ;
if ( V_130 == NULL )
return - V_123 ;
V_130 -> V_75 = V_46 ;
V_130 -> V_82 = V_124 ;
return F_306 ( V_46 -> V_512 , & V_135 , V_513 ,
& V_514 , V_130 ) ;
}
static int F_307 ( struct V_45 * V_46 , struct V_261 * V_288 )
{
struct V_134 V_135 = {
. V_256 = & V_257 [ V_511 ] ,
. V_259 = V_46 ,
. V_261 = V_288 ,
} ;
unsigned long V_515 = V_124 ;
int V_253 ;
V_253 = F_58 ( V_46 -> V_512 , & V_135 , 0 ) ;
if ( V_253 < 0 )
return V_253 ;
F_23 ( V_46 , V_515 ) ;
return 0 ;
}
static inline int F_308 ( struct V_40 * V_41 )
{
return ( V_41 -> V_78 & V_356 )
&& ( V_41 -> V_377 & V_516 )
&& ( V_41 -> V_377 & V_517 ) ;
}
static int F_309 ( const void * V_518 , T_9 V_519 ,
struct V_400 * * V_23 , unsigned int * V_30 )
{
struct V_400 * V_520 , * * V_521 ;
int V_522 = 0 ;
T_9 V_388 ;
V_521 = V_23 ;
do {
V_388 = F_310 ( T_9 , V_523 , V_519 ) ;
V_520 = F_214 ( V_312 ) ;
if ( V_520 == NULL )
goto V_524;
memcpy ( F_311 ( V_520 ) , V_518 , V_388 ) ;
V_518 += V_388 ;
V_519 -= V_388 ;
* V_23 ++ = V_520 ;
V_522 ++ ;
} while ( V_519 != 0 );
return V_522 ;
V_524:
for(; V_522 > 0 ; V_522 -- )
F_218 ( V_521 [ V_522 - 1 ] ) ;
return - V_123 ;
}
static void F_312 ( struct V_49 * V_49 , struct V_525 * V_526 )
{
struct V_147 * V_148 = F_61 ( V_49 ) ;
F_24 ( & V_49 -> V_149 ) ;
F_78 ( V_148 -> V_527 ) ;
V_148 -> V_527 = V_526 ;
F_26 ( & V_49 -> V_149 ) ;
}
static void F_313 ( struct V_49 * V_49 )
{
F_312 ( V_49 , NULL ) ;
}
static inline T_10 F_314 ( struct V_49 * V_49 , char * V_518 , T_9 V_519 )
{
struct V_147 * V_148 = F_61 ( V_49 ) ;
struct V_525 * V_526 ;
int V_50 = - V_250 ;
F_24 ( & V_49 -> V_149 ) ;
V_526 = V_148 -> V_527 ;
if ( V_526 == NULL )
goto V_103;
if ( V_518 == NULL )
goto V_528;
if ( V_526 -> V_529 == 0 )
goto V_103;
V_50 = - V_530 ;
if ( V_526 -> V_388 > V_519 )
goto V_103;
memcpy ( V_518 , V_526 -> V_130 , V_526 -> V_388 ) ;
V_528:
V_50 = V_526 -> V_388 ;
V_103:
F_26 ( & V_49 -> V_149 ) ;
return V_50 ;
}
static void F_315 ( struct V_49 * V_49 , struct V_400 * * V_23 , T_9 V_30 , T_9 V_531 )
{
struct V_525 * V_526 ;
T_9 V_519 = sizeof( * V_526 ) + V_531 ;
if ( V_519 <= V_523 ) {
V_526 = F_215 ( V_519 , V_312 ) ;
if ( V_526 == NULL )
goto V_103;
V_526 -> V_529 = 1 ;
F_316 ( V_526 -> V_130 , V_23 , V_30 , V_531 ) ;
} else {
V_526 = F_215 ( sizeof( * V_526 ) , V_312 ) ;
if ( V_526 == NULL )
goto V_103;
V_526 -> V_529 = 0 ;
}
V_526 -> V_388 = V_531 ;
V_103:
F_312 ( V_49 , V_526 ) ;
}
static T_10 F_317 ( struct V_49 * V_49 , void * V_518 , T_9 V_519 )
{
struct V_400 * V_23 [ V_532 ] = { NULL , } ;
struct V_533 args = {
. V_181 = F_75 ( V_49 ) ,
. V_534 = V_23 ,
. V_531 = V_519 ,
} ;
struct V_535 V_35 = {
. V_531 = V_519 ,
} ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_536 ] ,
. V_259 = & args ,
. V_260 = & V_35 ,
} ;
unsigned int V_537 = F_318 ( V_519 , V_523 ) ;
int V_50 = - V_123 , V_387 ;
if ( V_537 == 0 )
V_537 = 1 ;
if ( V_537 > F_206 ( V_23 ) )
return - V_530 ;
for ( V_387 = 0 ; V_387 < V_537 ; V_387 ++ ) {
V_23 [ V_387 ] = F_214 ( V_312 ) ;
if ( ! V_23 [ V_387 ] )
goto V_255;
}
V_35 . V_538 = F_214 ( V_312 ) ;
if ( ! V_35 . V_538 )
goto V_255;
args . V_531 = V_537 * V_523 ;
args . V_539 = 0 ;
F_2 ( L_35 ,
V_14 , V_518 , V_519 , V_537 , args . V_531 ) ;
V_50 = F_59 ( F_69 ( V_49 ) -> V_75 , F_69 ( V_49 ) ,
& V_135 , & args . V_132 , & V_35 . V_133 , 0 ) ;
if ( V_50 )
goto V_255;
if ( V_35 . V_540 & V_541 ) {
if ( V_518 == NULL )
goto V_542;
V_50 = - V_530 ;
goto V_255;
}
F_315 ( V_49 , V_23 , V_35 . V_543 , V_35 . V_531 ) ;
if ( V_518 ) {
if ( V_35 . V_531 > V_519 ) {
V_50 = - V_530 ;
goto V_255;
}
F_316 ( V_518 , V_23 , V_35 . V_543 , V_35 . V_531 ) ;
}
V_542:
V_50 = V_35 . V_531 ;
V_255:
for ( V_387 = 0 ; V_387 < V_537 ; V_387 ++ )
if ( V_23 [ V_387 ] )
F_218 ( V_23 [ V_387 ] ) ;
if ( V_35 . V_538 )
F_218 ( V_35 . V_538 ) ;
return V_50 ;
}
static T_10 F_319 ( struct V_49 * V_49 , void * V_518 , T_9 V_519 )
{
struct V_43 V_44 = { } ;
T_10 V_50 ;
do {
V_50 = F_317 ( V_49 , V_518 , V_519 ) ;
if ( V_50 >= 0 )
break;
V_50 = F_13 ( F_69 ( V_49 ) , V_50 , & V_44 ) ;
} while ( V_44 . V_51 );
return V_50 ;
}
static T_10 F_320 ( struct V_49 * V_49 , void * V_518 , T_9 V_519 )
{
struct V_40 * V_41 = F_69 ( V_49 ) ;
int V_50 ;
if ( ! F_308 ( V_41 ) )
return - V_544 ;
V_50 = F_321 ( V_41 , V_49 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( F_61 ( V_49 ) -> V_150 & V_545 )
F_322 ( V_49 ) ;
V_50 = F_314 ( V_49 , V_518 , V_519 ) ;
if ( V_50 != - V_250 )
return V_50 ;
return F_319 ( V_49 , V_518 , V_519 ) ;
}
static int F_323 ( struct V_49 * V_49 , const void * V_518 , T_9 V_519 )
{
struct V_40 * V_41 = F_69 ( V_49 ) ;
struct V_400 * V_23 [ V_532 ] ;
struct V_546 V_325 = {
. V_181 = F_75 ( V_49 ) ,
. V_534 = V_23 ,
. V_531 = V_519 ,
} ;
struct V_547 V_35 ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_548 ] ,
. V_259 = & V_325 ,
. V_260 = & V_35 ,
} ;
unsigned int V_537 = F_318 ( V_519 , V_523 ) ;
int V_50 , V_387 ;
if ( ! F_308 ( V_41 ) )
return - V_544 ;
if ( V_537 > F_206 ( V_23 ) )
return - V_530 ;
V_387 = F_309 ( V_518 , V_519 , V_325 . V_534 , & V_325 . V_539 ) ;
if ( V_387 < 0 )
return V_387 ;
F_15 ( V_49 ) ;
V_50 = F_59 ( V_41 -> V_75 , V_41 , & V_135 , & V_325 . V_132 , & V_35 . V_133 , 1 ) ;
for (; V_387 > 0 ; V_387 -- )
F_324 ( V_23 [ V_387 - 1 ] ) ;
F_24 ( & V_49 -> V_149 ) ;
F_61 ( V_49 ) -> V_150 |= V_151 ;
F_26 ( & V_49 -> V_149 ) ;
F_325 ( V_49 ) ;
F_322 ( V_49 ) ;
return V_50 ;
}
static int F_326 ( struct V_49 * V_49 , const void * V_518 , T_9 V_519 )
{
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_69 ( V_49 ) ,
F_323 ( V_49 , V_518 , V_519 ) ,
& V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static int
F_188 ( struct V_98 * V_99 , const struct V_40 * V_41 , struct V_47 * V_48 )
{
struct V_45 * V_46 = V_41 -> V_45 ;
if ( V_99 -> V_111 >= 0 )
return 0 ;
switch( V_99 -> V_111 ) {
case - V_55 :
case - V_56 :
case - V_57 :
if ( V_48 == NULL )
break;
F_17 ( V_48 -> V_49 ) ;
case - V_52 :
if ( V_48 == NULL )
break;
F_16 ( V_41 , V_48 ) ;
goto V_54;
case - V_58 :
if ( V_48 != NULL )
F_16 ( V_41 , V_48 ) ;
case - V_59 :
case - V_60 :
F_18 ( V_46 ) ;
goto V_54;
#if F_19 ( V_61 )
case - V_62 :
case - V_63 :
case - V_64 :
case - V_66 :
case - V_65 :
case - V_67 :
case - V_68 :
F_2 ( L_36 , V_14 ,
V_99 -> V_111 ) ;
F_20 ( V_46 -> V_69 , V_99 -> V_111 ) ;
V_99 -> V_111 = 0 ;
return - V_127 ;
#endif
case - V_74 :
F_327 ( V_41 , V_549 ) ;
case - V_73 :
F_37 ( V_99 , V_37 ) ;
V_99 -> V_111 = 0 ;
return - V_127 ;
case - V_76 :
case - V_77 :
V_99 -> V_111 = 0 ;
return - V_127 ;
}
V_99 -> V_111 = F_1 ( V_99 -> V_111 ) ;
return 0 ;
V_54:
F_48 ( & V_46 -> V_550 , V_99 , NULL ) ;
if ( F_42 ( V_551 , & V_46 -> V_552 ) == 0 )
F_328 ( & V_46 -> V_550 , V_99 ) ;
V_99 -> V_111 = 0 ;
return - V_127 ;
}
static void F_329 ( const struct V_45 * V_46 ,
T_11 * V_553 )
{
T_2 V_204 [ 2 ] ;
if ( F_42 ( V_554 , & V_46 -> V_552 ) ) {
V_204 [ 0 ] = 0 ;
V_204 [ 1 ] = ( T_2 ) ( V_555 + 1 ) ;
} else {
struct V_556 * V_557 = F_330 ( V_46 -> V_558 , V_559 ) ;
V_204 [ 0 ] = ( T_2 ) V_557 -> V_560 . V_561 ;
V_204 [ 1 ] = ( T_2 ) V_557 -> V_560 . V_562 ;
}
memcpy ( V_553 -> V_130 , V_204 , sizeof( V_553 -> V_130 ) ) ;
}
static unsigned int
F_331 ( const struct V_45 * V_46 ,
char * V_518 , T_9 V_388 )
{
unsigned int V_563 ;
F_104 () ;
V_563 = F_332 ( V_518 , V_388 , L_37 ,
V_46 -> V_564 ,
F_333 ( V_46 -> V_512 ,
V_565 ) ,
F_333 ( V_46 -> V_512 ,
V_566 ) ) ;
F_107 () ;
return V_563 ;
}
static unsigned int
F_334 ( const struct V_45 * V_46 ,
char * V_518 , T_9 V_388 )
{
char * V_567 = V_46 -> V_512 -> V_568 ;
if ( V_569 [ 0 ] != '\0' )
V_567 = V_569 ;
return F_332 ( V_518 , V_388 , L_38 ,
V_46 -> V_570 -> V_571 , V_46 -> V_393 ,
V_567 ) ;
}
int F_335 ( struct V_45 * V_46 , T_6 V_572 ,
unsigned short V_573 , struct V_261 * V_288 ,
struct V_574 * V_35 )
{
T_11 V_575 ;
struct V_576 V_577 = {
. V_575 = & V_575 ,
. V_578 = V_572 ,
. V_579 = V_46 -> V_580 ,
} ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_581 ] ,
. V_259 = & V_577 ,
. V_260 = V_35 ,
. V_261 = V_288 ,
} ;
int V_253 ;
F_329 ( V_46 , & V_575 ) ;
if ( F_42 ( V_582 , & V_46 -> V_583 ) )
V_577 . V_584 =
F_334 ( V_46 ,
V_577 . V_585 ,
sizeof( V_577 . V_585 ) ) ;
else
V_577 . V_584 =
F_331 ( V_46 ,
V_577 . V_585 ,
sizeof( V_577 . V_585 ) ) ;
F_104 () ;
V_577 . V_586 = F_332 ( V_577 . V_587 ,
sizeof( V_577 . V_587 ) ,
F_333 ( V_46 -> V_512 ,
V_588 ) ) ;
F_107 () ;
V_577 . V_589 = F_332 ( V_577 . V_590 ,
sizeof( V_577 . V_590 ) , L_39 ,
V_46 -> V_564 , V_573 >> 8 , V_573 & 255 ) ;
F_2 ( L_40 ,
V_46 -> V_512 -> V_591 -> V_592 -> V_593 ,
V_577 . V_584 , V_577 . V_585 ) ;
V_253 = F_58 ( V_46 -> V_512 , & V_135 , V_594 ) ;
F_2 ( L_41 , V_253 ) ;
return V_253 ;
}
int F_336 ( struct V_45 * V_46 ,
struct V_574 * V_325 ,
struct V_261 * V_288 )
{
struct V_379 V_477 ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_595 ] ,
. V_259 = V_325 ,
. V_260 = & V_477 ,
. V_261 = V_288 ,
} ;
unsigned long V_515 ;
int V_253 ;
F_2 ( L_42 ,
V_46 -> V_512 -> V_591 -> V_592 -> V_593 ,
V_46 -> V_190 ) ;
V_515 = V_124 ;
V_253 = F_58 ( V_46 -> V_512 , & V_135 , V_594 ) ;
if ( V_253 == 0 ) {
F_24 ( & V_46 -> V_83 ) ;
V_46 -> V_596 = V_477 . V_597 * V_71 ;
V_46 -> V_84 = V_515 ;
F_26 ( & V_46 -> V_83 ) ;
}
F_2 ( L_43 , V_253 ) ;
return V_253 ;
}
static void F_337 ( struct V_98 * V_99 , void * V_128 )
{
struct V_598 * V_130 = V_128 ;
if ( ! F_38 ( V_99 , & V_130 -> V_35 . V_133 ) )
return;
switch ( V_99 -> V_111 ) {
case - V_59 :
case - V_58 :
case 0 :
F_27 ( V_130 -> V_35 . V_41 , V_130 -> V_82 ) ;
break;
default:
if ( F_188 ( V_99 , V_130 -> V_35 . V_41 , NULL ) ==
- V_127 ) {
F_35 ( V_99 ) ;
return;
}
}
V_130 -> V_238 = V_99 -> V_111 ;
}
static void F_338 ( void * V_128 )
{
F_78 ( V_128 ) ;
}
static void F_339 ( struct V_98 * V_99 , void * V_130 )
{
struct V_598 * V_599 ;
V_599 = (struct V_598 * ) V_130 ;
F_49 ( V_599 -> V_35 . V_41 ,
& V_599 -> args . V_132 ,
& V_599 -> V_35 . V_133 ,
V_99 ) ;
}
static int F_340 ( struct V_49 * V_49 , struct V_261 * V_288 , const T_5 * V_207 , int V_600 )
{
struct V_598 * V_130 ;
struct V_40 * V_41 = F_69 ( V_49 ) ;
struct V_98 * V_99 ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_601 ] ,
. V_261 = V_288 ,
} ;
struct V_136 V_262 = {
. V_138 = V_41 -> V_75 ,
. V_134 = & V_135 ,
. V_139 = & V_602 ,
. V_171 = V_266 ,
} ;
int V_253 = 0 ;
V_130 = F_70 ( sizeof( * V_130 ) , V_251 ) ;
if ( V_130 == NULL )
return - V_123 ;
F_39 ( & V_130 -> args . V_132 , & V_130 -> V_35 . V_133 , 1 ) ;
V_130 -> args . V_352 = & V_130 -> V_181 ;
V_130 -> args . V_207 = & V_130 -> V_207 ;
V_130 -> args . V_197 = V_41 -> V_348 ;
F_147 ( & V_130 -> V_181 , F_75 ( V_49 ) ) ;
F_97 ( & V_130 -> V_207 , V_207 ) ;
V_130 -> V_35 . V_323 = & V_130 -> V_323 ;
V_130 -> V_35 . V_41 = V_41 ;
F_65 ( V_130 -> V_35 . V_323 ) ;
V_130 -> V_82 = V_124 ;
V_130 -> V_238 = 0 ;
V_262 . V_141 = V_130 ;
V_135 . V_259 = & V_130 -> args ;
V_135 . V_260 = & V_130 -> V_35 ;
V_99 = F_54 ( & V_262 ) ;
if ( F_44 ( V_99 ) )
return F_55 ( V_99 ) ;
if ( ! V_600 )
goto V_103;
V_253 = F_89 ( V_99 ) ;
if ( V_253 != 0 )
goto V_103;
V_253 = V_130 -> V_238 ;
if ( V_253 == 0 )
F_289 ( V_49 , & V_130 -> V_323 ) ;
else
F_117 ( V_49 , & V_130 -> V_323 ) ;
V_103:
F_56 ( V_99 ) ;
return V_253 ;
}
int F_341 ( struct V_49 * V_49 , struct V_261 * V_288 , const T_5 * V_207 , int V_600 )
{
struct V_40 * V_41 = F_69 ( V_49 ) ;
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_340 ( V_49 , V_288 , V_207 , V_600 ) ;
switch ( V_1 ) {
case - V_59 :
case - V_58 :
case 0 :
return 0 ;
}
V_1 = F_13 ( V_41 , V_1 , & V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static unsigned long
F_342 ( unsigned long V_34 )
{
F_11 ( V_34 ) ;
V_34 <<= 1 ;
if ( V_34 > V_603 )
return V_603 ;
return V_34 ;
}
static int F_343 ( struct V_47 * V_48 , int V_604 , struct V_605 * V_606 )
{
struct V_49 * V_49 = V_48 -> V_49 ;
struct V_40 * V_41 = F_69 ( V_49 ) ;
struct V_45 * V_46 = V_41 -> V_45 ;
struct V_607 V_325 = {
. V_181 = F_75 ( V_49 ) ,
. V_608 = V_606 ,
} ;
struct V_609 V_35 = {
. V_610 = V_606 ,
} ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_611 ] ,
. V_259 = & V_325 ,
. V_260 = & V_35 ,
. V_261 = V_48 -> V_179 -> V_234 ,
} ;
struct V_612 * V_613 ;
int V_253 ;
V_325 . V_614 . V_189 = V_46 -> V_190 ;
V_253 = F_344 ( V_48 , V_606 ) ;
if ( V_253 != 0 )
goto V_103;
V_613 = V_606 -> V_615 . V_616 . V_179 ;
V_325 . V_614 . V_191 = V_613 -> V_617 . V_194 ;
V_325 . V_614 . V_618 = V_41 -> V_618 ;
V_253 = F_59 ( V_41 -> V_75 , V_41 , & V_135 , & V_325 . V_132 , & V_35 . V_133 , 1 ) ;
switch ( V_253 ) {
case 0 :
V_606 -> V_619 = V_620 ;
break;
case - V_621 :
V_253 = 0 ;
}
V_606 -> V_622 -> V_623 ( V_606 ) ;
V_103:
return V_253 ;
}
static int F_345 ( struct V_47 * V_48 , int V_604 , struct V_605 * V_606 )
{
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_69 ( V_48 -> V_49 ) ,
F_343 ( V_48 , V_604 , V_606 ) ,
& V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static int F_346 ( struct V_624 * V_624 , struct V_605 * V_608 )
{
int V_35 = 0 ;
switch ( V_608 -> V_625 & ( V_626 | V_627 ) ) {
case V_626 :
V_35 = F_347 ( V_624 , V_608 ) ;
break;
case V_627 :
V_35 = F_348 ( V_624 , V_608 ) ;
break;
default:
F_349 () ;
}
return V_35 ;
}
static struct V_628 * F_350 ( struct V_605 * V_608 ,
struct V_248 * V_249 ,
struct V_612 * V_613 ,
struct V_629 * V_160 )
{
struct V_628 * V_22 ;
struct V_49 * V_49 = V_613 -> V_630 -> V_49 ;
V_22 = F_70 ( sizeof( * V_22 ) , V_251 ) ;
if ( V_22 == NULL )
return NULL ;
V_22 -> V_325 . V_181 = F_75 ( V_49 ) ;
V_22 -> V_325 . V_608 = & V_22 -> V_608 ;
V_22 -> V_325 . V_160 = V_160 ;
V_22 -> V_35 . V_160 = V_160 ;
V_22 -> V_325 . V_207 = & V_613 -> V_631 ;
V_22 -> V_613 = V_613 ;
F_74 ( & V_613 -> V_632 ) ;
V_22 -> V_249 = F_124 ( V_249 ) ;
memcpy ( & V_22 -> V_608 , V_608 , sizeof( V_22 -> V_608 ) ) ;
V_22 -> V_41 = F_69 ( V_49 ) ;
return V_22 ;
}
static void F_351 ( void * V_130 )
{
struct V_628 * V_128 = V_130 ;
F_82 ( V_128 -> V_325 . V_160 ) ;
F_352 ( V_128 -> V_613 ) ;
F_135 ( V_128 -> V_249 ) ;
F_78 ( V_128 ) ;
}
static void F_353 ( struct V_98 * V_99 , void * V_130 )
{
struct V_628 * V_128 = V_130 ;
if ( ! F_38 ( V_99 , & V_128 -> V_35 . V_133 ) )
return;
switch ( V_99 -> V_111 ) {
case 0 :
F_97 ( & V_128 -> V_613 -> V_631 ,
& V_128 -> V_35 . V_207 ) ;
F_27 ( V_128 -> V_41 , V_128 -> V_82 ) ;
break;
case - V_57 :
case - V_77 :
case - V_59 :
case - V_58 :
break;
default:
if ( F_188 ( V_99 , V_128 -> V_41 , NULL ) == - V_127 )
F_35 ( V_99 ) ;
}
F_148 ( V_128 -> V_325 . V_160 ) ;
}
static void F_354 ( struct V_98 * V_99 , void * V_130 )
{
struct V_628 * V_128 = V_130 ;
if ( F_146 ( V_128 -> V_325 . V_160 , V_99 ) != 0 )
return;
if ( F_42 ( V_633 , & V_128 -> V_613 -> V_634 ) == 0 ) {
V_99 -> V_273 = NULL ;
F_38 ( V_99 , & V_128 -> V_35 . V_133 ) ;
return;
}
V_128 -> V_82 = V_124 ;
if ( F_49 ( V_128 -> V_41 ,
& V_128 -> V_325 . V_132 ,
& V_128 -> V_35 . V_133 ,
V_99 ) != 0 )
F_148 ( V_128 -> V_325 . V_160 ) ;
}
static struct V_98 * F_355 ( struct V_605 * V_608 ,
struct V_248 * V_249 ,
struct V_612 * V_613 ,
struct V_629 * V_160 )
{
struct V_628 * V_130 ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_635 ] ,
. V_261 = V_249 -> V_288 ,
} ;
struct V_136 V_262 = {
. V_138 = F_229 ( V_613 -> V_630 -> V_49 ) ,
. V_134 = & V_135 ,
. V_139 = & V_636 ,
. V_264 = V_265 ,
. V_171 = V_266 ,
} ;
V_608 -> V_619 = V_620 ;
V_130 = F_350 ( V_608 , V_249 , V_613 , V_160 ) ;
if ( V_130 == NULL ) {
F_82 ( V_160 ) ;
return F_45 ( - V_123 ) ;
}
F_39 ( & V_130 -> V_325 . V_132 , & V_130 -> V_35 . V_133 , 1 ) ;
V_135 . V_259 = & V_130 -> V_325 ;
V_135 . V_260 = & V_130 -> V_35 ;
V_262 . V_141 = V_130 ;
return F_54 ( & V_262 ) ;
}
static int F_356 ( struct V_47 * V_48 , int V_604 , struct V_605 * V_606 )
{
struct V_147 * V_148 = F_61 ( V_48 -> V_49 ) ;
struct V_629 * V_160 ;
struct V_612 * V_613 ;
struct V_98 * V_99 ;
int V_253 = 0 ;
unsigned char V_625 = V_606 -> V_625 ;
V_253 = F_344 ( V_48 , V_606 ) ;
V_606 -> V_625 |= V_637 ;
F_357 ( & V_148 -> V_638 ) ;
if ( F_346 ( V_606 -> V_639 , V_606 ) == - V_250 ) {
F_358 ( & V_148 -> V_638 ) ;
goto V_103;
}
F_358 ( & V_148 -> V_638 ) ;
if ( V_253 != 0 )
goto V_103;
if ( F_42 ( V_223 , & V_48 -> V_171 ) )
goto V_103;
V_613 = V_606 -> V_615 . V_616 . V_179 ;
V_160 = F_71 ( & V_613 -> V_617 , V_312 ) ;
V_253 = - V_123 ;
if ( V_160 == NULL )
goto V_103;
V_99 = F_355 ( V_606 , F_222 ( V_606 -> V_639 ) , V_613 , V_160 ) ;
V_253 = F_55 ( V_99 ) ;
if ( F_44 ( V_99 ) )
goto V_103;
V_253 = F_89 ( V_99 ) ;
F_56 ( V_99 ) ;
V_103:
V_606 -> V_625 = V_625 ;
return V_253 ;
}
static struct V_640 * F_359 ( struct V_605 * V_608 ,
struct V_248 * V_249 , struct V_612 * V_613 ,
T_4 V_174 )
{
struct V_640 * V_22 ;
struct V_49 * V_49 = V_613 -> V_630 -> V_49 ;
struct V_40 * V_41 = F_69 ( V_49 ) ;
V_22 = F_70 ( sizeof( * V_22 ) , V_174 ) ;
if ( V_22 == NULL )
return NULL ;
V_22 -> V_325 . V_181 = F_75 ( V_49 ) ;
V_22 -> V_325 . V_608 = & V_22 -> V_608 ;
V_22 -> V_325 . V_641 = F_71 ( & V_613 -> V_630 -> V_179 -> V_176 , V_174 ) ;
if ( V_22 -> V_325 . V_641 == NULL )
goto V_255;
V_22 -> V_325 . V_642 = F_71 ( & V_613 -> V_617 , V_174 ) ;
if ( V_22 -> V_325 . V_642 == NULL )
goto V_643;
V_22 -> V_325 . V_644 = & V_613 -> V_631 ;
V_22 -> V_325 . V_614 . V_189 = V_41 -> V_45 -> V_190 ;
V_22 -> V_325 . V_614 . V_191 = V_613 -> V_617 . V_194 ;
V_22 -> V_325 . V_614 . V_618 = V_41 -> V_618 ;
V_22 -> V_35 . V_642 = V_22 -> V_325 . V_642 ;
V_22 -> V_613 = V_613 ;
V_22 -> V_41 = V_41 ;
F_74 ( & V_613 -> V_632 ) ;
V_22 -> V_249 = F_124 ( V_249 ) ;
memcpy ( & V_22 -> V_608 , V_608 , sizeof( V_22 -> V_608 ) ) ;
return V_22 ;
V_643:
F_82 ( V_22 -> V_325 . V_641 ) ;
V_255:
F_78 ( V_22 ) ;
return NULL ;
}
static void F_360 ( struct V_98 * V_99 , void * V_128 )
{
struct V_640 * V_130 = V_128 ;
struct V_47 * V_48 = V_130 -> V_613 -> V_630 ;
F_2 ( L_24 , V_14 ) ;
if ( F_146 ( V_130 -> V_325 . V_642 , V_99 ) != 0 )
return;
if ( ! ( V_130 -> V_325 . V_642 -> V_645 -> V_171 & V_646 ) ) {
if ( F_146 ( V_130 -> V_325 . V_641 , V_99 ) != 0 ) {
goto V_647;
}
V_130 -> V_325 . V_224 = & V_48 -> V_207 ;
V_130 -> V_325 . V_648 = 1 ;
V_130 -> V_35 . V_641 = V_130 -> V_325 . V_641 ;
} else
V_130 -> V_325 . V_648 = 0 ;
V_130 -> V_82 = V_124 ;
if ( F_49 ( V_130 -> V_41 ,
& V_130 -> V_325 . V_132 ,
& V_130 -> V_35 . V_133 ,
V_99 ) == 0 )
return;
F_148 ( V_130 -> V_325 . V_641 ) ;
V_647:
F_148 ( V_130 -> V_325 . V_642 ) ;
F_2 ( L_44 , V_14 , V_130 -> V_238 ) ;
}
static void F_361 ( struct V_98 * V_99 , void * V_128 )
{
struct V_640 * V_130 = V_128 ;
F_2 ( L_24 , V_14 ) ;
if ( ! F_38 ( V_99 , & V_130 -> V_35 . V_133 ) )
return;
V_130 -> V_238 = V_99 -> V_111 ;
if ( V_130 -> V_325 . V_648 != 0 ) {
if ( V_130 -> V_238 == 0 )
F_140 ( & V_130 -> V_613 -> V_617 , 0 ) ;
else
goto V_103;
}
if ( V_130 -> V_238 == 0 ) {
F_97 ( & V_130 -> V_613 -> V_631 , & V_130 -> V_35 . V_207 ) ;
F_98 ( V_633 , & V_130 -> V_613 -> V_634 ) ;
F_27 ( F_69 ( V_130 -> V_249 -> V_18 -> V_27 ) , V_130 -> V_82 ) ;
}
V_103:
F_2 ( L_25 , V_14 , V_130 -> V_238 ) ;
}
static void F_362 ( void * V_128 )
{
struct V_640 * V_130 = V_128 ;
F_2 ( L_24 , V_14 ) ;
F_82 ( V_130 -> V_325 . V_641 ) ;
if ( V_130 -> V_254 != 0 ) {
struct V_98 * V_99 ;
V_99 = F_355 ( & V_130 -> V_608 , V_130 -> V_249 , V_130 -> V_613 ,
V_130 -> V_325 . V_642 ) ;
if ( ! F_44 ( V_99 ) )
F_363 ( V_99 ) ;
F_2 ( L_45 , V_14 ) ;
} else
F_82 ( V_130 -> V_325 . V_642 ) ;
F_352 ( V_130 -> V_613 ) ;
F_135 ( V_130 -> V_249 ) ;
F_78 ( V_130 ) ;
F_2 ( L_26 , V_14 ) ;
}
static void F_364 ( struct V_40 * V_41 , struct V_612 * V_613 , int V_648 , int error )
{
switch ( error ) {
case - V_56 :
case - V_57 :
V_613 -> V_617 . V_171 &= ~ V_646 ;
if ( V_648 != 0 ||
F_42 ( V_633 , & V_613 -> V_634 ) != 0 )
F_16 ( V_41 , V_613 -> V_630 ) ;
break;
case - V_59 :
V_613 -> V_617 . V_171 &= ~ V_646 ;
case - V_58 :
F_18 ( V_41 -> V_45 ) ;
} ;
}
static int F_365 ( struct V_47 * V_48 , int V_604 , struct V_605 * V_608 , int V_649 )
{
struct V_640 * V_130 ;
struct V_98 * V_99 ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_650 ] ,
. V_261 = V_48 -> V_179 -> V_234 ,
} ;
struct V_136 V_262 = {
. V_138 = F_229 ( V_48 -> V_49 ) ,
. V_134 = & V_135 ,
. V_139 = & V_651 ,
. V_264 = V_265 ,
. V_171 = V_266 ,
} ;
int V_50 ;
F_2 ( L_24 , V_14 ) ;
V_130 = F_359 ( V_608 , F_222 ( V_608 -> V_639 ) ,
V_608 -> V_615 . V_616 . V_179 ,
V_649 == V_652 ? V_312 : V_251 ) ;
if ( V_130 == NULL )
return - V_123 ;
if ( F_366 ( V_604 ) )
V_130 -> V_325 . V_653 = 1 ;
F_39 ( & V_130 -> V_325 . V_132 , & V_130 -> V_35 . V_133 , 1 ) ;
V_135 . V_259 = & V_130 -> V_325 ;
V_135 . V_260 = & V_130 -> V_35 ;
V_262 . V_141 = V_130 ;
if ( V_649 > V_652 ) {
if ( V_649 == V_654 )
V_130 -> V_325 . V_655 = V_654 ;
F_40 ( & V_130 -> V_325 . V_132 ) ;
}
V_99 = F_54 ( & V_262 ) ;
if ( F_44 ( V_99 ) )
return F_55 ( V_99 ) ;
V_50 = F_89 ( V_99 ) ;
if ( V_50 == 0 ) {
V_50 = V_130 -> V_238 ;
if ( V_50 )
F_364 ( V_130 -> V_41 , V_130 -> V_613 ,
V_130 -> V_325 . V_648 , V_50 ) ;
} else
V_130 -> V_254 = 1 ;
F_56 ( V_99 ) ;
F_2 ( L_25 , V_14 , V_50 ) ;
return V_50 ;
}
static int F_367 ( struct V_47 * V_48 , struct V_605 * V_606 )
{
struct V_40 * V_41 = F_69 ( V_48 -> V_49 ) ;
struct V_43 V_44 = {
. V_49 = V_48 -> V_49 ,
} ;
int V_1 ;
do {
if ( F_42 ( V_223 , & V_48 -> V_171 ) != 0 )
return 0 ;
V_1 = F_365 ( V_48 , V_656 , V_606 , V_654 ) ;
if ( V_1 != - V_74 )
break;
F_13 ( V_41 , V_1 , & V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static int F_368 ( struct V_47 * V_48 , struct V_605 * V_606 )
{
struct V_40 * V_41 = F_69 ( V_48 -> V_49 ) ;
struct V_43 V_44 = {
. V_49 = V_48 -> V_49 ,
} ;
int V_1 ;
V_1 = F_344 ( V_48 , V_606 ) ;
if ( V_1 != 0 )
return V_1 ;
do {
if ( F_42 ( V_223 , & V_48 -> V_171 ) != 0 )
return 0 ;
V_1 = F_365 ( V_48 , V_656 , V_606 , V_657 ) ;
switch ( V_1 ) {
default:
goto V_103;
case - V_73 :
case - V_74 :
F_13 ( V_41 , V_1 , & V_44 ) ;
V_1 = 0 ;
}
} while ( V_44 . V_51 );
V_103:
return V_1 ;
}
static int F_369 ( struct V_47 * V_48 )
{
int V_253 , V_50 = - V_57 ;
struct V_612 * V_613 ;
struct V_40 * V_41 = F_69 ( V_48 -> V_49 ) ;
F_123 (lsp, &state->lock_states, ls_locks) {
if ( F_42 ( V_633 , & V_613 -> V_634 ) ) {
V_253 = F_165 ( V_41 , & V_613 -> V_631 ) ;
if ( V_253 != V_301 ) {
if ( V_253 != - V_57 )
F_166 ( V_41 ,
& V_613 -> V_631 ) ;
F_130 ( V_633 , & V_613 -> V_634 ) ;
V_50 = V_253 ;
}
}
} ;
return V_50 ;
}
static int F_370 ( struct V_47 * V_48 , struct V_605 * V_606 )
{
int V_253 = V_301 ;
if ( F_42 ( V_658 , & V_48 -> V_171 ) )
V_253 = F_369 ( V_48 ) ;
if ( V_253 != V_301 )
V_253 = F_368 ( V_48 , V_606 ) ;
return V_253 ;
}
static int F_371 ( struct V_47 * V_48 , int V_604 , struct V_605 * V_606 )
{
struct V_147 * V_148 = F_61 ( V_48 -> V_49 ) ;
unsigned char V_625 = V_606 -> V_625 ;
int V_253 = - V_659 ;
if ( ( V_625 & V_626 ) &&
! F_42 ( V_319 , & V_48 -> V_171 ) )
goto V_103;
V_253 = F_344 ( V_48 , V_606 ) ;
if ( V_253 != 0 )
goto V_103;
V_606 -> V_625 |= V_660 ;
V_253 = F_346 ( V_606 -> V_639 , V_606 ) ;
if ( V_253 < 0 )
goto V_103;
F_357 ( & V_148 -> V_638 ) ;
if ( F_42 ( V_223 , & V_48 -> V_171 ) ) {
V_606 -> V_625 = V_625 & ~ V_661 ;
V_253 = F_346 ( V_606 -> V_639 , V_606 ) ;
goto V_96;
}
V_253 = F_365 ( V_48 , V_604 , V_606 , V_652 ) ;
if ( V_253 != 0 )
goto V_96;
V_606 -> V_625 = V_625 | V_661 ;
if ( F_346 ( V_606 -> V_639 , V_606 ) < 0 )
F_21 ( V_80 L_46
L_47 , V_14 ) ;
V_96:
F_358 ( & V_148 -> V_638 ) ;
V_103:
V_606 -> V_625 = V_625 ;
return V_253 ;
}
static int F_372 ( struct V_47 * V_48 , int V_604 , struct V_605 * V_606 )
{
struct V_43 V_44 = {
. V_48 = V_48 ,
. V_49 = V_48 -> V_49 ,
} ;
int V_1 ;
do {
V_1 = F_371 ( V_48 , V_604 , V_606 ) ;
if ( V_1 == - V_621 )
V_1 = - V_127 ;
V_1 = F_13 ( F_69 ( V_48 -> V_49 ) ,
V_1 , & V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static int
F_373 ( struct V_624 * V_662 , int V_604 , struct V_605 * V_606 )
{
struct V_248 * V_249 ;
struct V_47 * V_48 ;
unsigned long V_34 = V_663 ;
int V_253 ;
V_249 = F_222 ( V_662 ) ;
V_48 = V_249 -> V_48 ;
if ( V_606 -> V_664 < 0 || V_606 -> V_665 < 0 )
return - V_8 ;
if ( F_374 ( V_604 ) ) {
if ( V_48 != NULL )
return F_345 ( V_48 , V_666 , V_606 ) ;
return 0 ;
}
if ( ! ( F_375 ( V_604 ) || F_366 ( V_604 ) ) )
return - V_8 ;
if ( V_606 -> V_619 == V_620 ) {
if ( V_48 != NULL )
return F_356 ( V_48 , V_604 , V_606 ) ;
return 0 ;
}
if ( V_48 == NULL )
return - V_659 ;
switch ( V_606 -> V_619 ) {
case V_667 :
if ( ! ( V_662 -> V_668 & V_53 ) )
return - V_336 ;
break;
case V_669 :
if ( ! ( V_662 -> V_668 & V_183 ) )
return - V_336 ;
}
do {
V_253 = F_372 ( V_48 , V_604 , V_606 ) ;
if ( ( V_253 != - V_127 ) || F_375 ( V_604 ) )
break;
V_34 = F_342 ( V_34 ) ;
V_253 = - V_39 ;
if ( F_376 () )
break;
} while( V_253 < 0 );
return V_253 ;
}
int F_377 ( struct V_47 * V_48 , struct V_605 * V_608 )
{
struct V_40 * V_41 = F_69 ( V_48 -> V_49 ) ;
struct V_43 V_44 = { } ;
int V_1 ;
V_1 = F_344 ( V_48 , V_608 ) ;
if ( V_1 != 0 )
goto V_103;
do {
V_1 = F_365 ( V_48 , V_656 , V_608 , V_652 ) ;
switch ( V_1 ) {
default:
F_21 ( V_670 L_48
L_49 , V_14 , V_1 ) ;
case 0 :
case - V_239 :
goto V_103;
case - V_58 :
F_16 ( V_41 , V_48 ) ;
case - V_60 :
case - V_59 :
F_18 ( V_41 -> V_45 ) ;
goto V_103;
case - V_62 :
case - V_63 :
case - V_64 :
case - V_65 :
case - V_66 :
F_20 ( V_41 -> V_45 -> V_69 , V_1 ) ;
goto V_103;
case - V_39 :
case - V_55 :
case - V_56 :
case - V_57 :
case - V_52 :
F_16 ( V_41 , V_48 ) ;
V_1 = 0 ;
goto V_103;
case - V_123 :
case - V_621 :
V_1 = 0 ;
goto V_103;
case - V_74 :
break;
}
V_1 = F_13 ( V_41 , V_1 , & V_44 ) ;
} while ( V_44 . V_51 );
V_103:
return V_1 ;
}
static void F_378 ( void * V_128 )
{
struct V_671 * V_130 = V_128 ;
F_379 ( V_130 -> V_41 , V_130 -> V_613 ) ;
F_78 ( V_128 ) ;
}
int F_380 ( struct V_612 * V_613 )
{
struct V_40 * V_41 = V_613 -> V_630 -> V_179 -> V_269 ;
struct V_671 * V_130 ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_672 ] ,
} ;
if ( V_41 -> V_45 -> V_142 -> V_392 != 0 )
return - V_8 ;
V_130 = F_215 ( sizeof( * V_130 ) , V_251 ) ;
if ( ! V_130 )
return - V_123 ;
V_130 -> V_613 = V_613 ;
V_130 -> V_41 = V_41 ;
V_130 -> args . V_614 . V_189 = V_41 -> V_45 -> V_190 ;
V_130 -> args . V_614 . V_191 = V_613 -> V_617 . V_194 ;
V_130 -> args . V_614 . V_618 = V_41 -> V_618 ;
V_135 . V_259 = & V_130 -> args ;
F_306 ( V_41 -> V_75 , & V_135 , 0 , & V_673 , V_130 ) ;
return 0 ;
}
static int F_381 ( struct V_18 * V_18 , const char * V_674 ,
const void * V_518 , T_9 V_519 ,
int V_171 , int type )
{
if ( strcmp ( V_674 , L_50 ) != 0 )
return - V_8 ;
return F_326 ( V_18 -> V_27 , V_518 , V_519 ) ;
}
static int F_382 ( struct V_18 * V_18 , const char * V_674 ,
void * V_518 , T_9 V_519 , int type )
{
if ( strcmp ( V_674 , L_50 ) != 0 )
return - V_8 ;
return F_320 ( V_18 -> V_27 , V_518 , V_519 ) ;
}
static T_9 F_383 ( struct V_18 * V_18 , char * V_675 ,
T_9 V_676 , const char * V_195 ,
T_9 V_677 , int type )
{
T_9 V_388 = sizeof( V_678 ) ;
if ( ! F_308 ( F_69 ( V_18 -> V_27 ) ) )
return 0 ;
if ( V_675 && V_388 <= V_676 )
memcpy ( V_675 , V_678 , V_388 ) ;
return V_388 ;
}
static void F_217 ( struct V_322 * V_323 )
{
if ( ! ( ( ( V_323 -> V_240 & V_679 ) ||
( V_323 -> V_240 & V_242 ) ) &&
( V_323 -> V_240 & V_397 ) &&
( V_323 -> V_240 & V_680 ) ) )
return;
V_323 -> V_240 |= V_241 | V_412 |
V_413 | V_681 ;
V_323 -> V_211 = V_278 | V_415 | V_416 ;
V_323 -> V_417 = 2 ;
}
static int F_384 ( struct V_32 * V_75 , struct V_49 * V_144 ,
const struct V_399 * V_195 ,
struct V_401 * V_682 ,
struct V_400 * V_400 )
{
struct V_40 * V_41 = F_69 ( V_144 ) ;
T_6 V_197 [ 2 ] = {
[ 0 ] = V_683 | V_684 ,
} ;
struct V_685 args = {
. V_410 = F_75 ( V_144 ) ,
. V_195 = V_195 ,
. V_400 = V_400 ,
. V_197 = V_197 ,
} ;
struct V_686 V_35 = {
. V_682 = V_682 ,
} ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_687 ] ,
. V_259 = & args ,
. V_260 = & V_35 ,
} ;
int V_253 ;
F_2 ( L_51 , V_14 ) ;
if ( F_69 ( V_144 ) -> V_198 [ 1 ] & V_688 )
V_197 [ 1 ] |= V_688 ;
else
V_197 [ 0 ] |= V_26 ;
F_65 ( & V_682 -> V_323 ) ;
V_682 -> V_41 = V_41 ;
V_682 -> V_689 = 0 ;
V_253 = F_59 ( V_75 , V_41 , & V_135 , & args . V_132 , & V_35 . V_133 , 0 ) ;
F_2 ( L_52 , V_14 , V_253 ) ;
return V_253 ;
}
int F_216 ( struct V_32 * V_75 , struct V_49 * V_144 ,
const struct V_399 * V_195 ,
struct V_401 * V_682 ,
struct V_400 * V_400 )
{
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_69 ( V_144 ) ,
F_384 ( V_75 , V_144 , V_195 , V_682 , V_400 ) ,
& V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static int F_385 ( struct V_49 * V_144 , const struct V_399 * V_195 , struct V_690 * V_691 )
{
int V_253 ;
struct V_692 args = {
. V_410 = F_75 ( V_144 ) ,
. V_195 = V_195 ,
} ;
struct V_693 V_35 = {
. V_691 = V_691 ,
} ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_694 ] ,
. V_259 = & args ,
. V_260 = & V_35 ,
} ;
F_2 ( L_53 , V_195 -> V_195 ) ;
V_253 = F_59 ( F_69 ( V_144 ) -> V_75 , F_69 ( V_144 ) , & V_135 , & args . V_132 , & V_35 . V_133 , 0 ) ;
F_2 ( L_54 , V_253 ) ;
return V_253 ;
}
int F_386 ( struct V_49 * V_144 , const struct V_399 * V_195 ,
struct V_690 * V_691 )
{
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_13 ( F_69 ( V_144 ) ,
F_385 ( V_144 , V_195 , V_691 ) ,
& V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static int F_387 ( T_6 V_171 )
{
if ( V_171 & ~ V_695 )
goto V_696;
if ( ( V_171 & V_697 ) &&
( V_171 & V_698 ) )
goto V_696;
if ( ! ( V_171 & ( V_699 ) ) )
goto V_696;
return V_301 ;
V_696:
return - V_700 ;
}
static bool
F_388 ( struct V_701 * V_702 ,
struct V_701 * V_703 )
{
if ( V_702 -> V_704 == V_703 -> V_704 &&
memcmp ( V_702 -> V_705 , V_703 -> V_705 , V_702 -> V_704 ) == 0 )
return true ;
return false ;
}
int F_389 ( struct V_45 * V_46 , struct V_261 * V_288 )
{
int V_253 ;
struct V_706 V_35 ;
struct V_134 V_135 = {
. V_256 =
& V_257 [ V_707 ] ,
. V_259 = V_46 ,
. V_260 = & V_35 ,
. V_261 = V_288 ,
} ;
F_2 ( L_12 , V_14 ) ;
V_35 . V_87 = F_70 ( sizeof( struct V_86 ) , V_251 ) ;
if ( F_390 ( V_35 . V_87 == NULL ) ) {
V_253 = - V_123 ;
goto V_103;
}
V_253 = F_58 ( V_46 -> V_512 , & V_135 , V_594 ) ;
if ( V_253 == 0 ) {
if ( memcmp ( V_35 . V_87 -> V_708 . V_130 ,
V_46 -> V_69 -> V_708 . V_130 , V_709 ) ) {
F_2 ( L_55 , V_14 ) ;
V_253 = - V_15 ;
goto V_710;
}
if ( V_35 . V_144 != V_711 ) {
F_2 ( L_56 ,
V_14 ) ;
V_253 = - V_15 ;
goto V_710;
}
if ( V_35 . V_712 ) {
F_2 ( L_57 ,
V_14 ) ;
V_253 = - V_15 ;
goto V_710;
}
}
V_710:
F_78 ( V_35 . V_87 ) ;
V_103:
F_2 ( L_58 , V_14 , V_253 ) ;
return V_253 ;
}
int F_391 ( struct V_45 * V_46 , struct V_261 * V_288 )
{
T_11 V_17 ;
struct V_713 args = {
. V_17 = & V_17 ,
. V_75 = V_46 ,
. V_171 = V_714 ,
} ;
struct V_715 V_35 = {
0
} ;
int V_253 ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_716 ] ,
. V_259 = & args ,
. V_260 = & V_35 ,
. V_261 = V_288 ,
} ;
F_329 ( V_46 , & V_17 ) ;
args . V_717 = F_334 ( V_46 , args . V_191 ,
sizeof( args . V_191 ) ) ;
F_2 ( L_59 ,
V_46 -> V_512 -> V_591 -> V_592 -> V_593 ,
args . V_717 , args . V_191 ) ;
V_35 . V_718 = F_70 ( sizeof( struct V_719 ) ,
V_251 ) ;
if ( F_390 ( V_35 . V_718 == NULL ) ) {
V_253 = - V_123 ;
goto V_103;
}
V_35 . V_705 = F_70 ( sizeof( struct V_701 ) ,
V_251 ) ;
if ( F_390 ( V_35 . V_705 == NULL ) ) {
V_253 = - V_123 ;
goto V_720;
}
V_35 . V_721 = F_70 ( sizeof( struct V_722 ) , V_251 ) ;
if ( F_390 ( V_35 . V_721 == NULL ) ) {
V_253 = - V_123 ;
goto V_723;
}
V_253 = F_58 ( V_46 -> V_512 , & V_135 , V_594 ) ;
if ( V_253 == 0 )
V_253 = F_387 ( V_35 . V_171 ) ;
if ( V_253 == 0 ) {
V_46 -> V_190 = V_35 . V_189 ;
V_46 -> V_724 = ( V_35 . V_171 & ~ V_725 ) ;
if ( ! ( V_35 . V_171 & V_725 ) )
V_46 -> V_726 = V_35 . V_160 ;
F_78 ( V_46 -> V_727 ) ;
V_46 -> V_727 = V_35 . V_718 ;
V_35 . V_718 = NULL ;
F_78 ( V_46 -> V_728 ) ;
V_46 -> V_728 = V_35 . V_721 ;
if ( V_46 -> V_729 != NULL &&
! F_388 ( V_46 -> V_729 ,
V_35 . V_705 ) ) {
F_2 ( L_60 ,
V_14 ) ;
F_98 ( V_730 , & V_46 -> V_552 ) ;
F_78 ( V_46 -> V_729 ) ;
V_46 -> V_729 = NULL ;
}
if ( V_46 -> V_729 == NULL ) {
V_46 -> V_729 = V_35 . V_705 ;
goto V_103;
}
} else
F_78 ( V_35 . V_721 ) ;
V_720:
F_78 ( V_35 . V_718 ) ;
V_723:
F_78 ( V_35 . V_705 ) ;
V_103:
if ( V_46 -> V_728 != NULL )
F_2 ( L_61
L_62 ,
V_46 -> V_728 -> V_731 , V_46 -> V_728 -> V_195 ,
V_46 -> V_728 -> V_732 . V_733 ,
V_46 -> V_728 -> V_732 . V_734 ) ;
F_2 ( L_63 , V_253 ) ;
return V_253 ;
}
static int F_392 ( struct V_45 * V_46 ,
struct V_261 * V_288 )
{
struct V_134 V_135 = {
. V_256 = & V_257 [ V_735 ] ,
. V_259 = V_46 ,
. V_261 = V_288 ,
} ;
int V_253 ;
V_253 = F_58 ( V_46 -> V_512 , & V_135 , V_594 ) ;
if ( V_253 )
F_2 ( L_64
L_65 , V_253 , V_46 -> V_81 ) ;
return V_253 ;
}
static int F_393 ( struct V_45 * V_46 ,
struct V_261 * V_288 )
{
unsigned int V_736 ;
int V_50 ;
for ( V_736 = V_737 ; V_736 != 0 ; V_736 -- ) {
V_50 = F_392 ( V_46 , V_288 ) ;
switch ( V_50 ) {
case - V_74 :
case - V_738 :
F_394 ( 1 ) ;
break;
default:
return V_50 ;
}
}
return 0 ;
}
int F_395 ( struct V_45 * V_46 )
{
struct V_261 * V_288 ;
int V_50 = 0 ;
if ( V_46 -> V_142 -> V_392 < 1 )
goto V_103;
if ( V_46 -> V_724 == 0 )
goto V_103;
if ( V_46 -> V_739 )
goto V_103;
V_288 = F_396 ( V_46 ) ;
V_50 = F_393 ( V_46 , V_288 ) ;
if ( V_288 )
F_397 ( V_288 ) ;
switch ( V_50 ) {
case 0 :
case - V_60 :
V_46 -> V_724 = 0 ;
}
V_103:
return V_50 ;
}
static void F_398 ( struct V_98 * V_99 ,
void * V_128 )
{
struct V_740 * V_130 =
(struct V_740 * ) V_128 ;
F_2 ( L_12 , V_14 ) ;
F_41 ( V_130 -> V_46 -> V_69 ,
& V_130 -> args -> V_741 ,
& V_130 -> V_35 -> V_742 ,
V_99 ) ;
F_2 ( L_66 , V_14 ) ;
}
static void F_399 ( struct V_98 * V_99 , void * V_128 )
{
struct V_740 * V_130 =
(struct V_740 * ) V_128 ;
F_2 ( L_12 , V_14 ) ;
if ( ! F_32 ( V_99 , & V_130 -> V_35 -> V_742 ) )
return;
switch ( V_99 -> V_111 ) {
case - V_74 :
case - V_73 :
F_2 ( L_67 , V_14 , V_99 -> V_111 ) ;
F_37 ( V_99 , V_36 ) ;
V_99 -> V_111 = 0 ;
case - V_76 :
F_35 ( V_99 ) ;
return;
}
F_2 ( L_66 , V_14 ) ;
}
int F_400 ( struct V_45 * V_46 , struct V_379 * V_477 )
{
struct V_98 * V_99 ;
struct V_743 args ;
struct V_744 V_35 = {
. V_745 = V_477 ,
} ;
struct V_740 V_130 = {
. args = & args ,
. V_35 = & V_35 ,
. V_46 = V_46 ,
} ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_746 ] ,
. V_259 = & args ,
. V_260 = & V_35 ,
} ;
struct V_136 V_137 = {
. V_138 = V_46 -> V_512 ,
. V_134 = & V_135 ,
. V_139 = & V_747 ,
. V_141 = & V_130 ,
. V_171 = V_594 ,
} ;
int V_253 ;
F_39 ( & args . V_741 , & V_35 . V_742 , 0 ) ;
F_40 ( & args . V_741 ) ;
F_2 ( L_12 , V_14 ) ;
V_99 = F_54 ( & V_137 ) ;
if ( F_44 ( V_99 ) )
V_253 = F_55 ( V_99 ) ;
else {
V_253 = V_99 -> V_111 ;
F_56 ( V_99 ) ;
}
F_2 ( L_68 , V_14 , V_253 ) ;
return V_253 ;
}
static void F_401 ( struct V_748 * args )
{
struct V_86 * V_87 = args -> V_75 -> V_69 ;
unsigned int V_749 = V_87 -> V_750 ,
V_751 = V_87 -> V_752 ;
if ( V_749 == 0 )
V_749 = V_753 ;
if ( V_751 == 0 )
V_751 = V_753 ;
args -> V_754 . V_755 = V_749 ;
args -> V_754 . V_756 = V_751 ;
args -> V_754 . V_757 = V_758 ;
args -> V_754 . V_759 = V_760 ;
F_2 ( L_69
L_70 ,
V_14 ,
args -> V_754 . V_755 , args -> V_754 . V_756 ,
args -> V_754 . V_757 , args -> V_754 . V_759 ) ;
args -> V_761 . V_755 = V_523 ;
args -> V_761 . V_756 = V_523 ;
args -> V_761 . V_762 = 0 ;
args -> V_761 . V_757 = V_763 ;
args -> V_761 . V_759 = 1 ;
F_2 ( L_71
L_72 ,
V_14 ,
args -> V_761 . V_755 , args -> V_761 . V_756 ,
args -> V_761 . V_762 , args -> V_761 . V_757 ,
args -> V_761 . V_759 ) ;
}
static int F_402 ( struct V_748 * args , struct V_86 * V_87 )
{
struct V_764 * V_765 = & args -> V_754 ;
struct V_764 * V_766 = & V_87 -> V_754 ;
if ( V_766 -> V_756 > V_765 -> V_756 )
return - V_8 ;
if ( V_766 -> V_757 < V_765 -> V_757 )
return - V_8 ;
if ( V_766 -> V_759 == 0 )
return - V_8 ;
if ( V_766 -> V_759 > V_767 )
V_766 -> V_759 = V_767 ;
return 0 ;
}
static int F_403 ( struct V_748 * args , struct V_86 * V_87 )
{
struct V_764 * V_765 = & args -> V_761 ;
struct V_764 * V_766 = & V_87 -> V_761 ;
if ( V_766 -> V_755 > V_765 -> V_755 )
return - V_8 ;
if ( V_766 -> V_756 < V_765 -> V_756 )
return - V_8 ;
if ( V_766 -> V_762 > V_765 -> V_762 )
return - V_8 ;
if ( V_766 -> V_757 != V_765 -> V_757 )
return - V_8 ;
if ( V_766 -> V_759 != V_765 -> V_759 )
return - V_8 ;
return 0 ;
}
static int F_404 ( struct V_748 * args ,
struct V_86 * V_87 )
{
int V_50 ;
V_50 = F_402 ( args , V_87 ) ;
if ( V_50 )
return V_50 ;
return F_403 ( args , V_87 ) ;
}
static int F_405 ( struct V_45 * V_46 ,
struct V_261 * V_288 )
{
struct V_86 * V_87 = V_46 -> V_69 ;
struct V_748 args = {
. V_75 = V_46 ,
. V_768 = V_769 ,
} ;
struct V_770 V_35 = {
. V_75 = V_46 ,
} ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_771 ] ,
. V_259 = & args ,
. V_260 = & V_35 ,
. V_261 = V_288 ,
} ;
int V_253 ;
F_401 ( & args ) ;
args . V_171 = ( V_772 | V_773 ) ;
V_253 = F_58 ( V_87 -> V_46 -> V_512 , & V_135 , V_594 ) ;
if ( ! V_253 ) {
V_253 = F_404 ( & args , V_87 ) ;
V_46 -> V_726 ++ ;
}
return V_253 ;
}
int F_406 ( struct V_45 * V_46 , struct V_261 * V_288 )
{
int V_253 ;
unsigned * V_774 ;
struct V_86 * V_87 = V_46 -> V_69 ;
F_2 ( L_73 , V_14 , V_46 , V_87 ) ;
V_253 = F_405 ( V_46 , V_288 ) ;
if ( V_253 )
goto V_103;
V_253 = F_407 ( V_87 ) ;
F_2 ( L_74 , V_253 ) ;
if ( V_253 )
goto V_103;
V_774 = ( unsigned * ) & V_87 -> V_708 . V_130 [ 0 ] ;
F_2 ( L_75 , V_14 ,
V_46 -> V_726 , V_774 [ 0 ] , V_774 [ 1 ] , V_774 [ 2 ] , V_774 [ 3 ] ) ;
V_103:
F_2 ( L_66 , V_14 ) ;
return V_253 ;
}
int F_408 ( struct V_86 * V_87 ,
struct V_261 * V_288 )
{
struct V_134 V_135 = {
. V_256 = & V_257 [ V_775 ] ,
. V_259 = V_87 ,
. V_261 = V_288 ,
} ;
int V_253 = 0 ;
F_2 ( L_76 ) ;
if ( V_87 -> V_46 -> V_776 != V_777 )
return V_253 ;
V_253 = F_58 ( V_87 -> V_46 -> V_512 , & V_135 , V_594 ) ;
if ( V_253 )
F_2 ( L_77
L_78 , V_253 ) ;
F_2 ( L_79 ) ;
return V_253 ;
}
static void F_409 ( void * V_130 )
{
struct V_778 * V_128 = V_130 ;
struct V_45 * V_46 = V_128 -> V_46 ;
if ( F_299 ( & V_46 -> V_506 ) > 1 )
F_300 ( V_46 ) ;
F_301 ( V_46 ) ;
F_78 ( V_128 ) ;
}
static int F_410 ( struct V_98 * V_99 , struct V_45 * V_46 )
{
switch( V_99 -> V_111 ) {
case - V_74 :
F_37 ( V_99 , V_37 ) ;
return - V_127 ;
default:
F_18 ( V_46 ) ;
}
return 0 ;
}
static void F_411 ( struct V_98 * V_99 , void * V_130 )
{
struct V_778 * V_128 = V_130 ;
struct V_45 * V_46 = V_128 -> V_46 ;
if ( ! F_32 ( V_99 , V_99 -> V_270 . V_260 ) )
return;
if ( V_99 -> V_111 < 0 ) {
F_2 ( L_80 , V_14 , V_99 -> V_111 ) ;
if ( F_299 ( & V_46 -> V_506 ) == 1 )
goto V_103;
if ( F_410 ( V_99 , V_46 ) == - V_127 ) {
F_35 ( V_99 ) ;
return;
}
}
F_2 ( L_81 , V_14 , V_99 -> V_270 . V_261 ) ;
V_103:
F_2 ( L_66 , V_14 ) ;
}
static void F_412 ( struct V_98 * V_99 , void * V_130 )
{
struct V_778 * V_128 = V_130 ;
struct V_45 * V_46 = V_128 -> V_46 ;
struct V_112 * args ;
struct V_85 * V_35 ;
args = V_99 -> V_270 . V_259 ;
V_35 = V_99 -> V_270 . V_260 ;
F_41 ( V_46 -> V_69 , args , V_35 , V_99 ) ;
}
static struct V_98 * F_413 ( struct V_45 * V_46 ,
struct V_261 * V_288 ,
bool V_779 )
{
struct V_778 * V_128 ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_780 ] ,
. V_261 = V_288 ,
} ;
struct V_136 V_262 = {
. V_138 = V_46 -> V_512 ,
. V_134 = & V_135 ,
. V_139 = & V_781 ,
. V_171 = V_266 | V_513 ,
} ;
if ( ! F_305 ( & V_46 -> V_506 ) )
return F_45 ( - V_15 ) ;
V_128 = F_70 ( sizeof( * V_128 ) , V_251 ) ;
if ( V_128 == NULL ) {
F_301 ( V_46 ) ;
return F_45 ( - V_123 ) ;
}
F_39 ( & V_128 -> args , & V_128 -> V_35 , 0 ) ;
if ( V_779 )
F_40 ( & V_128 -> args ) ;
V_135 . V_259 = & V_128 -> args ;
V_135 . V_260 = & V_128 -> V_35 ;
V_128 -> V_46 = V_46 ;
V_262 . V_141 = V_128 ;
return F_54 ( & V_262 ) ;
}
static int F_414 ( struct V_45 * V_46 , struct V_261 * V_288 , unsigned V_510 )
{
struct V_98 * V_99 ;
int V_50 = 0 ;
if ( ( V_510 & V_782 ) == 0 )
return 0 ;
V_99 = F_413 ( V_46 , V_288 , false ) ;
if ( F_44 ( V_99 ) )
V_50 = F_55 ( V_99 ) ;
else
F_363 ( V_99 ) ;
F_2 ( L_17 , V_14 , V_50 ) ;
return V_50 ;
}
static int F_415 ( struct V_45 * V_46 , struct V_261 * V_288 )
{
struct V_98 * V_99 ;
int V_50 ;
V_99 = F_413 ( V_46 , V_288 , true ) ;
if ( F_44 ( V_99 ) ) {
V_50 = F_55 ( V_99 ) ;
goto V_103;
}
V_50 = F_90 ( V_99 ) ;
if ( ! V_50 ) {
struct V_85 * V_35 = V_99 -> V_270 . V_260 ;
if ( V_99 -> V_111 == 0 )
F_416 ( V_46 , V_35 -> V_107 ) ;
V_50 = V_99 -> V_111 ;
}
F_56 ( V_99 ) ;
V_103:
F_2 ( L_17 , V_14 , V_50 ) ;
return V_50 ;
}
static void F_417 ( struct V_98 * V_99 , void * V_130 )
{
struct V_783 * V_128 = V_130 ;
F_41 ( V_128 -> V_46 -> V_69 ,
& V_128 -> V_325 . V_132 ,
& V_128 -> V_35 . V_133 ,
V_99 ) ;
}
static int F_418 ( struct V_98 * V_99 , struct V_45 * V_46 )
{
switch( V_99 -> V_111 ) {
case 0 :
case - V_784 :
case - V_785 :
break;
case - V_74 :
F_37 ( V_99 , V_37 ) ;
case - V_76 :
return - V_127 ;
default:
F_18 ( V_46 ) ;
}
return 0 ;
}
static void F_419 ( struct V_98 * V_99 , void * V_130 )
{
struct V_783 * V_128 = V_130 ;
struct V_45 * V_46 = V_128 -> V_46 ;
struct V_85 * V_35 = & V_128 -> V_35 . V_133 ;
F_2 ( L_12 , V_14 ) ;
if ( ! F_32 ( V_99 , V_35 ) )
return;
if ( F_418 ( V_99 , V_46 ) == - V_127 ) {
F_35 ( V_99 ) ;
return;
}
F_2 ( L_66 , V_14 ) ;
}
static void F_420 ( void * V_130 )
{
struct V_783 * V_128 = V_130 ;
F_78 ( V_128 ) ;
}
static int F_421 ( struct V_45 * V_46 )
{
struct V_783 * V_128 ;
struct V_98 * V_99 ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_786 ] ,
} ;
struct V_136 V_262 = {
. V_138 = V_46 -> V_512 ,
. V_134 = & V_135 ,
. V_139 = & V_787 ,
. V_171 = V_266 ,
} ;
int V_253 = - V_123 ;
F_2 ( L_12 , V_14 ) ;
V_128 = F_70 ( sizeof( * V_128 ) , V_251 ) ;
if ( V_128 == NULL )
goto V_103;
V_128 -> V_46 = V_46 ;
V_128 -> V_325 . V_788 = 0 ;
F_39 ( & V_128 -> V_325 . V_132 , & V_128 -> V_35 . V_133 , 0 ) ;
F_40 ( & V_128 -> V_325 . V_132 ) ;
V_135 . V_259 = & V_128 -> V_325 ;
V_135 . V_260 = & V_128 -> V_35 ;
V_262 . V_141 = V_128 ;
V_99 = F_54 ( & V_262 ) ;
if ( F_44 ( V_99 ) ) {
V_253 = F_55 ( V_99 ) ;
goto V_103;
}
V_253 = F_89 ( V_99 ) ;
if ( V_253 == 0 )
V_253 = V_99 -> V_111 ;
F_56 ( V_99 ) ;
return 0 ;
V_103:
F_2 ( L_17 , V_14 , V_253 ) ;
return V_253 ;
}
static void
F_422 ( struct V_98 * V_99 , void * V_128 )
{
struct V_789 * V_790 = V_128 ;
struct V_40 * V_41 = F_69 ( V_790 -> args . V_49 ) ;
struct V_86 * V_87 = F_50 ( V_41 ) ;
F_2 ( L_12 , V_14 ) ;
if ( F_41 ( V_87 , & V_790 -> args . V_132 ,
& V_790 -> V_35 . V_133 , V_99 ) )
return;
if ( F_423 ( & V_790 -> args . V_207 ,
F_61 ( V_790 -> args . V_49 ) -> V_791 ,
V_790 -> args . V_249 -> V_48 ) ) {
F_424 ( V_99 , V_792 ) ;
}
}
static void F_425 ( struct V_98 * V_99 , void * V_128 )
{
struct V_789 * V_790 = V_128 ;
struct V_49 * V_49 = V_790 -> args . V_49 ;
struct V_40 * V_41 = F_69 ( V_49 ) ;
struct V_793 * V_794 ;
struct V_47 * V_48 = NULL ;
F_2 ( L_12 , V_14 ) ;
if ( ! F_32 ( V_99 , & V_790 -> V_35 . V_133 ) )
goto V_103;
switch ( V_99 -> V_111 ) {
case 0 :
goto V_103;
case - V_795 :
case - V_796 :
V_99 -> V_111 = - V_74 ;
break;
case - V_58 :
case - V_57 :
F_24 ( & V_49 -> V_149 ) ;
V_794 = F_61 ( V_49 ) -> V_791 ;
if ( ! V_794 || F_426 ( & V_794 -> V_797 ) ) {
F_26 ( & V_49 -> V_149 ) ;
V_48 = V_790 -> args . V_249 -> V_48 ;
} else {
F_427 ( V_798 ) ;
F_428 ( V_794 , & V_798 , NULL ) ;
F_26 ( & V_49 -> V_149 ) ;
F_429 ( & V_798 ) ;
}
}
if ( F_188 ( V_99 , V_41 , V_48 ) == - V_127 )
F_35 ( V_99 ) ;
V_103:
F_2 ( L_66 , V_14 ) ;
}
static T_9 F_430 ( struct V_40 * V_41 )
{
T_6 V_756 = V_41 -> V_45 -> V_69 -> V_754 . V_756 ;
return F_431 ( 0 , V_756 ) ;
}
static void F_432 ( struct V_400 * * V_23 , T_9 V_799 )
{
int V_387 ;
if ( ! V_23 )
return;
for ( V_387 = 0 ; V_387 < V_799 ; V_387 ++ ) {
if ( ! V_23 [ V_387 ] )
break;
F_218 ( V_23 [ V_387 ] ) ;
}
F_78 ( V_23 ) ;
}
static struct V_400 * * F_433 ( T_9 V_799 , T_4 V_800 )
{
struct V_400 * * V_23 ;
int V_387 ;
V_23 = F_434 ( V_799 , sizeof( struct V_400 * ) , V_800 ) ;
if ( ! V_23 ) {
F_2 ( L_82 , V_14 , V_799 ) ;
return NULL ;
}
for ( V_387 = 0 ; V_387 < V_799 ; V_387 ++ ) {
V_23 [ V_387 ] = F_214 ( V_800 ) ;
if ( ! V_23 [ V_387 ] ) {
F_2 ( L_83 , V_14 ) ;
F_432 ( V_23 , V_799 ) ;
return NULL ;
}
}
return V_23 ;
}
static void F_435 ( void * V_128 )
{
struct V_789 * V_790 = V_128 ;
struct V_40 * V_41 = F_69 ( V_790 -> args . V_49 ) ;
T_9 V_801 = F_430 ( V_41 ) ;
F_2 ( L_12 , V_14 ) ;
F_432 ( V_790 -> args . V_791 . V_23 , V_801 ) ;
F_135 ( V_790 -> args . V_249 ) ;
F_78 ( V_128 ) ;
F_2 ( L_66 , V_14 ) ;
}
struct V_802 *
F_436 ( struct V_789 * V_790 , T_4 V_800 )
{
struct V_40 * V_41 = F_69 ( V_790 -> args . V_49 ) ;
T_9 V_801 = F_430 ( V_41 ) ;
struct V_98 * V_99 ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_803 ] ,
. V_259 = & V_790 -> args ,
. V_260 = & V_790 -> V_35 ,
} ;
struct V_136 V_262 = {
. V_138 = V_41 -> V_75 ,
. V_134 = & V_135 ,
. V_139 = & V_804 ,
. V_141 = V_790 ,
. V_171 = V_266 ,
} ;
struct V_802 * V_805 = NULL ;
int V_253 = 0 ;
F_2 ( L_12 , V_14 ) ;
V_790 -> args . V_791 . V_23 = F_433 ( V_801 , V_800 ) ;
if ( ! V_790 -> args . V_791 . V_23 ) {
F_435 ( V_790 ) ;
return F_45 ( - V_123 ) ;
}
V_790 -> args . V_791 . V_427 = V_801 * V_523 ;
V_790 -> V_35 . V_806 = & V_790 -> args . V_791 ;
V_790 -> V_35 . V_133 . V_91 = NULL ;
F_39 ( & V_790 -> args . V_132 , & V_790 -> V_35 . V_133 , 0 ) ;
V_99 = F_54 ( & V_262 ) ;
if ( F_44 ( V_99 ) )
return F_194 ( V_99 ) ;
V_253 = F_89 ( V_99 ) ;
if ( V_253 == 0 )
V_253 = V_99 -> V_111 ;
if ( V_253 == 0 )
V_805 = F_437 ( V_790 ) ;
F_56 ( V_99 ) ;
F_2 ( L_17 , V_14 , V_253 ) ;
if ( V_253 )
return F_45 ( V_253 ) ;
return V_805 ;
}
static void
F_438 ( struct V_98 * V_99 , void * V_128 )
{
struct V_807 * V_808 = V_128 ;
F_2 ( L_12 , V_14 ) ;
F_41 ( V_808 -> V_46 -> V_69 ,
& V_808 -> args . V_132 ,
& V_808 -> V_35 . V_133 ,
V_99 ) ;
}
static void F_439 ( struct V_98 * V_99 , void * V_128 )
{
struct V_807 * V_808 = V_128 ;
struct V_40 * V_41 ;
F_2 ( L_12 , V_14 ) ;
if ( ! F_32 ( V_99 , & V_808 -> V_35 . V_133 ) )
return;
V_41 = F_69 ( V_808 -> args . V_49 ) ;
if ( F_188 ( V_99 , V_41 , NULL ) == - V_127 ) {
F_35 ( V_99 ) ;
return;
}
F_2 ( L_66 , V_14 ) ;
}
static void F_440 ( void * V_128 )
{
struct V_807 * V_808 = V_128 ;
struct V_793 * V_794 = V_808 -> args . V_791 ;
F_2 ( L_12 , V_14 ) ;
F_24 ( & V_794 -> V_809 -> V_149 ) ;
if ( V_808 -> V_35 . V_810 )
F_441 ( V_794 , & V_808 -> V_35 . V_207 , true ) ;
V_794 -> V_811 -- ;
F_26 ( & V_794 -> V_809 -> V_149 ) ;
F_442 ( V_808 -> args . V_791 ) ;
F_78 ( V_128 ) ;
F_2 ( L_66 , V_14 ) ;
}
int F_443 ( struct V_807 * V_808 )
{
struct V_98 * V_99 ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_812 ] ,
. V_259 = & V_808 -> args ,
. V_260 = & V_808 -> V_35 ,
} ;
struct V_136 V_262 = {
. V_138 = V_808 -> V_46 -> V_512 ,
. V_134 = & V_135 ,
. V_139 = & V_813 ,
. V_141 = V_808 ,
} ;
int V_253 ;
F_2 ( L_12 , V_14 ) ;
F_39 ( & V_808 -> args . V_132 , & V_808 -> V_35 . V_133 , 1 ) ;
V_99 = F_54 ( & V_262 ) ;
if ( F_44 ( V_99 ) )
return F_55 ( V_99 ) ;
V_253 = V_99 -> V_111 ;
F_2 ( L_17 , V_14 , V_253 ) ;
F_56 ( V_99 ) ;
return V_253 ;
}
static int F_444 ( struct V_40 * V_41 ,
const struct V_351 * V_181 ,
struct V_814 * V_815 )
{
struct V_816 args = {
. V_181 = V_181 ,
. V_817 = V_41 -> V_818 -> V_191 ,
} ;
struct V_819 V_35 = {
. V_815 = V_815 ,
} ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_820 ] ,
. V_259 = & args ,
. V_260 = & V_35 ,
} ;
int V_253 ;
F_2 ( L_12 , V_14 ) ;
V_253 = F_59 ( V_41 -> V_75 , V_41 , & V_135 , & args . V_132 ,
& V_35 . V_133 , 0 ) ;
F_2 ( L_17 , V_14 , V_253 ) ;
return V_253 ;
}
int F_445 ( struct V_40 * V_41 ,
const struct V_351 * V_181 ,
struct V_814 * V_815 )
{
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_13 ( V_41 ,
F_444 ( V_41 , V_181 , V_815 ) ,
& V_44 ) ;
} while ( V_44 . V_51 );
F_2 ( L_84 , V_14 ,
V_1 , V_815 -> V_821 ) ;
return V_1 ;
}
static int
F_446 ( struct V_40 * V_41 , struct V_822 * V_823 )
{
struct V_824 args = {
. V_823 = V_823 ,
} ;
struct V_825 V_35 = {
. V_823 = V_823 ,
} ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_826 ] ,
. V_259 = & args ,
. V_260 = & V_35 ,
} ;
int V_253 ;
F_2 ( L_12 , V_14 ) ;
V_253 = F_59 ( V_41 -> V_75 , V_41 , & V_135 , & args . V_132 , & V_35 . V_133 , 0 ) ;
F_2 ( L_17 , V_14 , V_253 ) ;
return V_253 ;
}
int F_447 ( struct V_40 * V_41 , struct V_822 * V_823 )
{
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_13 ( V_41 ,
F_446 ( V_41 , V_823 ) ,
& V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static void F_448 ( struct V_98 * V_99 , void * V_128 )
{
struct V_827 * V_130 = V_128 ;
struct V_40 * V_41 = F_69 ( V_130 -> args . V_49 ) ;
struct V_86 * V_87 = F_50 ( V_41 ) ;
F_41 ( V_87 ,
& V_130 -> args . V_132 ,
& V_130 -> V_35 . V_133 ,
V_99 ) ;
}
static void
F_449 ( struct V_98 * V_99 , void * V_128 )
{
struct V_827 * V_130 = V_128 ;
struct V_40 * V_41 = F_69 ( V_130 -> args . V_49 ) ;
if ( ! F_32 ( V_99 , & V_130 -> V_35 . V_133 ) )
return;
switch ( V_99 -> V_111 ) {
case - V_55 :
case - V_828 :
case - V_829 :
case - V_73 :
V_99 -> V_111 = 0 ;
break;
case 0 :
F_289 ( V_130 -> args . V_49 ,
V_130 -> V_35 . V_323 ) ;
break;
default:
if ( F_188 ( V_99 , V_41 , NULL ) == - V_127 ) {
F_35 ( V_99 ) ;
return;
}
}
}
static void F_450 ( void * V_128 )
{
struct V_827 * V_130 = V_128 ;
struct V_802 * V_805 , * V_830 ;
unsigned long * V_831 = & F_61 ( V_130 -> args . V_49 ) -> V_171 ;
F_451 ( V_130 ) ;
F_452 (lseg, tmp, &data->lseg_list, pls_lc_list) {
F_453 ( & V_805 -> V_832 ) ;
if ( F_454 ( V_833 ,
& V_805 -> V_834 ) )
F_455 ( V_805 ) ;
}
F_456 ( V_835 , V_831 ) ;
F_457 () ;
F_458 ( V_831 , V_835 ) ;
F_397 ( V_130 -> V_288 ) ;
F_78 ( V_130 ) ;
}
int
F_459 ( struct V_827 * V_130 , bool V_836 )
{
struct V_134 V_135 = {
. V_256 = & V_257 [ V_837 ] ,
. V_259 = & V_130 -> args ,
. V_260 = & V_130 -> V_35 ,
. V_261 = V_130 -> V_288 ,
} ;
struct V_136 V_262 = {
. V_99 = & V_130 -> V_99 ,
. V_138 = F_229 ( V_130 -> args . V_49 ) ,
. V_134 = & V_135 ,
. V_139 = & V_838 ,
. V_141 = V_130 ,
. V_171 = V_266 ,
} ;
struct V_98 * V_99 ;
int V_253 = 0 ;
F_2 ( L_85
L_86 ,
V_130 -> V_99 . V_839 , V_836 ,
V_130 -> args . V_840 ,
V_130 -> args . V_49 -> V_841 ) ;
F_39 ( & V_130 -> args . V_132 , & V_130 -> V_35 . V_133 , 1 ) ;
V_99 = F_54 ( & V_262 ) ;
if ( F_44 ( V_99 ) )
return F_55 ( V_99 ) ;
if ( V_836 == false )
goto V_103;
V_253 = F_89 ( V_99 ) ;
if ( V_253 != 0 )
goto V_103;
V_253 = V_99 -> V_111 ;
V_103:
F_2 ( L_87 , V_14 , V_253 ) ;
F_56 ( V_99 ) ;
return V_253 ;
}
static int
F_460 ( struct V_40 * V_41 , struct V_351 * V_352 ,
struct V_379 * V_380 , struct V_690 * V_691 )
{
struct V_842 args = {
. V_843 = V_844 ,
} ;
struct V_693 V_35 = {
. V_691 = V_691 ,
} ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_845 ] ,
. V_259 = & args ,
. V_260 = & V_35 ,
} ;
return F_59 ( V_41 -> V_75 , V_41 , & V_135 , & args . V_132 , & V_35 . V_133 , 0 ) ;
}
static int
F_461 ( struct V_40 * V_41 , struct V_351 * V_352 ,
struct V_379 * V_380 , struct V_690 * V_691 )
{
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_460 ( V_41 , V_352 , V_380 , V_691 ) ;
switch ( V_1 ) {
case 0 :
case - V_4 :
case - V_846 :
goto V_103;
default:
V_1 = F_13 ( V_41 , V_1 , & V_44 ) ;
}
} while ( V_44 . V_51 );
V_103:
return V_1 ;
}
static int
F_462 ( struct V_40 * V_41 , struct V_351 * V_352 ,
struct V_379 * V_380 )
{
int V_1 ;
struct V_400 * V_400 ;
T_7 V_384 ;
struct V_690 * V_691 ;
V_400 = F_214 ( V_312 ) ;
if ( ! V_400 ) {
V_1 = - V_123 ;
goto V_103;
}
V_691 = F_311 ( V_400 ) ;
V_1 = F_461 ( V_41 , V_352 , V_380 , V_691 ) ;
if ( V_1 == - V_4 || V_1 == - V_846 ) {
V_1 = F_204 ( V_41 , V_352 , V_380 ) ;
goto V_847;
}
if ( V_1 )
goto V_847;
V_384 = F_463 ( V_691 ) ;
if ( V_1 == 0 )
V_1 = F_202 ( V_41 , V_352 , V_380 , V_384 ) ;
V_847:
F_324 ( V_400 ) ;
if ( V_1 == - V_10 )
return - V_5 ;
V_103:
return V_1 ;
}
static int F_464 ( struct V_40 * V_41 , T_5 * V_207 )
{
int V_253 ;
struct V_848 args = {
. V_207 = V_207 ,
} ;
struct V_849 V_35 ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_850 ] ,
. V_259 = & args ,
. V_260 = & V_35 ,
} ;
F_2 ( L_88 , V_207 ) ;
F_39 ( & args . V_132 , & V_35 . V_133 , 0 ) ;
F_40 ( & args . V_132 ) ;
V_253 = F_53 ( V_41 -> V_75 , V_41 , & V_135 ,
& args . V_132 , & V_35 . V_133 ) ;
if ( V_253 != V_301 ) {
F_2 ( L_89 , V_253 ) ;
return V_253 ;
}
F_2 ( L_90 , - V_35 . V_253 ) ;
return - V_35 . V_253 ;
}
static int F_165 ( struct V_40 * V_41 , T_5 * V_207 )
{
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_464 ( V_41 , V_207 ) ;
if ( V_1 != - V_74 )
break;
F_13 ( V_41 , V_1 , & V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static int F_465 ( struct V_40 * V_41 , T_5 * V_207 )
{
struct V_851 args = {
. V_207 = V_207 ,
} ;
struct V_852 V_35 ;
struct V_134 V_135 = {
. V_256 = & V_257 [ V_853 ] ,
. V_259 = & args ,
. V_260 = & V_35 ,
} ;
int V_253 ;
F_2 ( L_91 , V_207 ) ;
F_39 ( & args . V_132 , & V_35 . V_133 , 0 ) ;
F_40 ( & args . V_132 ) ;
V_253 = F_53 ( V_41 -> V_75 , V_41 , & V_135 ,
& args . V_132 , & V_35 . V_133 ) ;
F_2 ( L_92 , V_253 ) ;
return V_253 ;
}
static int F_166 ( struct V_40 * V_41 , T_5 * V_207 )
{
struct V_43 V_44 = { } ;
int V_1 ;
do {
V_1 = F_465 ( V_41 , V_207 ) ;
if ( V_1 != - V_74 )
break;
F_13 ( V_41 , V_1 , & V_44 ) ;
} while ( V_44 . V_51 );
return V_1 ;
}
static bool F_466 ( const T_5 * V_854 ,
const T_5 * V_855 )
{
if ( memcmp ( V_854 -> V_856 , V_855 -> V_856 , sizeof( V_854 -> V_856 ) ) != 0 )
return false ;
if ( V_854 -> V_160 == V_855 -> V_160 )
return true ;
if ( V_854 -> V_160 == 0 || V_855 -> V_160 == 0 )
return true ;
return false ;
}
static bool F_467 ( const T_5 * V_854 ,
const T_5 * V_855 )
{
return F_106 ( V_854 , V_855 ) ;
}
