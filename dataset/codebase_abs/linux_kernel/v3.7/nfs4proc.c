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
F_4 ( V_20 -> V_23 < 80 ) ;
if ( V_16 > 2 ) {
V_20 -> V_16 = V_16 ;
memcpy ( & V_20 -> V_17 , V_17 , sizeof( V_20 -> V_17 ) ) ;
return;
}
V_20 -> V_16 = 0 ;
memset ( & V_20 -> V_17 , 0 , sizeof( V_20 -> V_17 ) ) ;
if ( V_16 == 2 )
return;
V_21 = V_22 = F_5 ( * V_20 -> V_24 ) ;
if ( V_16 == 0 ) {
* V_22 ++ = V_25 ;
* V_22 ++ = V_26 ;
* V_22 ++ = V_25 ;
* V_22 ++ = V_25 ;
memcpy ( V_22 , L_2 , 4 ) ;
V_22 ++ ;
* V_22 ++ = V_25 ;
* V_22 ++ = F_6 ( V_27 ) ;
* V_22 ++ = F_6 ( 8 ) ;
V_22 = F_7 ( V_22 , F_8 ( V_18 -> V_28 ) ) ;
}
* V_22 ++ = V_25 ;
* V_22 ++ = V_26 ;
* V_22 ++ = V_29 ;
* V_22 ++ = V_29 ;
memcpy ( V_22 , L_3 , 4 ) ;
V_22 ++ ;
* V_22 ++ = V_25 ;
* V_22 ++ = F_6 ( V_27 ) ;
* V_22 ++ = F_6 ( 8 ) ;
V_22 = F_7 ( V_22 , F_8 ( V_18 -> V_30 -> V_28 ) ) ;
V_20 -> V_31 = ( char * ) V_22 - ( char * ) V_21 ;
V_20 -> V_23 -= V_20 -> V_31 ;
F_9 ( V_21 ) ;
}
static int F_10 ( struct V_32 * V_33 )
{
int V_34 ;
F_11 () ;
V_34 = F_12 ( & V_33 -> V_35 , V_36 ,
V_37 , V_38 ) ;
if ( V_34 )
return V_34 ;
if ( V_33 -> V_39 < 0 )
return V_33 -> V_39 ;
return 0 ;
}
static int F_13 ( struct V_40 * V_41 , long * V_42 )
{
int V_34 = 0 ;
F_11 () ;
if ( * V_42 <= 0 )
* V_42 = V_43 ;
if ( * V_42 > V_44 )
* V_42 = V_44 ;
F_14 ( * V_42 ) ;
if ( F_15 ( V_45 ) )
V_34 = - V_46 ;
* V_42 <<= 1 ;
return V_34 ;
}
static int F_16 ( struct V_47 * V_48 , int V_49 , struct V_50 * V_51 )
{
struct V_32 * V_33 = V_48 -> V_32 ;
struct V_52 * V_53 = V_51 -> V_53 ;
struct V_54 * V_54 = V_51 -> V_54 ;
int V_55 = V_49 ;
V_51 -> V_56 = 0 ;
switch( V_49 ) {
case 0 :
return 0 ;
case - V_57 :
if ( V_54 && F_17 ( V_54 , V_58 ) ) {
F_18 ( V_54 ) ;
V_51 -> V_56 = 1 ;
return 0 ;
}
if ( V_53 == NULL )
break;
F_19 ( V_48 , V_53 ) ;
goto V_59;
case - V_60 :
case - V_61 :
case - V_62 :
if ( V_53 == NULL )
break;
F_20 ( V_53 -> V_54 ) ;
F_19 ( V_48 , V_53 ) ;
goto V_59;
case - V_63 :
if ( V_53 != NULL )
F_19 ( V_48 , V_53 ) ;
case - V_64 :
case - V_65 :
F_21 ( V_33 ) ;
goto V_59;
#if F_22 ( V_66 )
case - V_67 :
case - V_68 :
case - V_69 :
case - V_70 :
case - V_71 :
case - V_72 :
case - V_73 :
F_2 ( L_4 , V_14 ,
V_49 ) ;
F_23 ( V_33 -> V_74 , V_49 ) ;
goto V_59;
#endif
case - V_75 :
if ( V_51 -> V_42 > V_76 ) {
V_55 = - V_77 ;
break;
}
case - V_78 :
case - V_79 :
case - V_80 :
V_55 = F_13 ( V_48 -> V_81 , & V_51 -> V_42 ) ;
if ( V_55 != 0 )
break;
case - V_82 :
case - V_83 :
V_51 -> V_56 = 1 ;
break;
case - V_6 :
case - V_7 :
if ( V_48 -> V_84 & V_85 ) {
V_48 -> V_84 &= ~ V_85 ;
V_51 -> V_56 = 1 ;
F_24 ( V_86 L_5
L_6
L_7
L_8 ,
V_48 -> V_32 -> V_87 ) ;
}
}
return F_1 ( V_55 ) ;
V_59:
V_55 = F_10 ( V_33 ) ;
if ( V_55 == 0 )
V_51 -> V_56 = 1 ;
return V_55 ;
}
static void F_25 ( struct V_32 * V_33 , unsigned long V_88 )
{
F_26 ( & V_33 -> V_89 ) ;
if ( F_27 ( V_33 -> V_90 , V_88 ) )
V_33 -> V_90 = V_88 ;
F_28 ( & V_33 -> V_89 ) ;
}
static void F_29 ( const struct V_47 * V_48 , unsigned long V_88 )
{
F_25 ( V_48 -> V_32 , V_88 ) ;
}
static void
F_30 ( struct V_91 * V_92 , T_3 V_93 )
{
F_4 ( V_93 >= V_94 ) ;
F_31 ( V_93 , V_92 -> V_95 ) ;
if ( V_93 == V_92 -> V_96 ) {
V_93 = F_32 ( V_92 -> V_95 , V_92 -> V_97 ) ;
if ( V_93 < V_92 -> V_97 )
V_92 -> V_96 = V_93 ;
else
V_92 -> V_96 = V_98 ;
}
F_2 ( L_9 , V_14 ,
V_93 , V_92 -> V_96 ) ;
}
bool F_33 ( struct V_99 * V_100 , void * V_101 )
{
F_34 ( V_100 , V_102 ) ;
return true ;
}
static void F_35 ( struct V_103 * V_104 )
{
if ( ! F_36 ( V_105 , & V_104 -> V_106 ) ) {
F_37 ( & V_104 -> V_107 . V_108 ,
F_33 , NULL ) ;
return;
}
if ( V_104 -> V_107 . V_96 != V_98 )
return;
F_2 ( L_10 , V_14 ) ;
F_38 ( & V_104 -> V_107 . F_38 ) ;
}
void F_39 ( struct V_103 * V_104 )
{
if ( ! F_36 ( V_105 , & V_104 -> V_106 ) ||
V_104 -> V_109 . V_96 != V_98 )
return;
F_2 ( L_11 , V_14 ) ;
F_38 ( & V_104 -> V_109 . F_38 ) ;
}
static void F_40 ( struct V_110 * V_34 )
{
struct V_91 * V_92 ;
V_92 = & V_34 -> V_111 -> V_107 ;
if ( ! V_34 -> V_112 ) {
F_2 ( L_12 , V_14 ) ;
return;
}
F_26 ( & V_92 -> V_113 ) ;
F_30 ( V_92 , V_34 -> V_112 - V_92 -> V_114 ) ;
F_35 ( V_34 -> V_111 ) ;
F_28 ( & V_92 -> V_113 ) ;
V_34 -> V_112 = NULL ;
}
static int F_41 ( struct V_99 * V_100 , struct V_110 * V_34 )
{
unsigned long V_88 ;
struct V_32 * V_33 ;
if ( V_34 -> V_115 == 1 )
V_34 -> V_115 = V_116 ;
if ( ! F_42 ( V_100 ) )
goto V_117;
switch ( V_34 -> V_115 ) {
case 0 :
++ V_34 -> V_112 -> V_118 ;
V_88 = V_34 -> V_119 ;
V_33 = V_34 -> V_111 -> V_33 ;
F_25 ( V_33 , V_88 ) ;
if ( V_34 -> V_120 != 0 )
F_21 ( V_33 ) ;
break;
case - V_79 :
F_2 ( L_13 ,
V_14 ,
V_34 -> V_112 - V_34 -> V_111 -> V_107 . V_114 ,
V_34 -> V_112 -> V_118 ) ;
goto V_121;
default:
++ V_34 -> V_112 -> V_118 ;
}
V_117:
F_2 ( L_14 , V_14 , V_34 -> V_115 ) ;
F_40 ( V_34 ) ;
return 1 ;
V_121:
if ( ! F_43 ( V_100 ) )
goto V_117;
F_44 ( V_100 , V_44 ) ;
return 0 ;
}
static int F_45 ( struct V_99 * V_100 ,
struct V_110 * V_34 )
{
if ( V_34 -> V_111 == NULL )
return 1 ;
return F_41 ( V_100 , V_34 ) ;
}
static T_3
F_46 ( struct V_91 * V_92 )
{
T_3 V_93 ;
T_3 V_122 = V_98 ;
F_2 ( L_15 ,
V_14 , V_92 -> V_95 [ 0 ] , V_92 -> V_96 ,
V_92 -> V_97 ) ;
V_93 = F_47 ( V_92 -> V_95 , V_92 -> V_97 ) ;
if ( V_93 >= V_92 -> V_97 )
goto V_117;
F_48 ( V_93 , V_92 -> V_95 ) ;
if ( V_93 > V_92 -> V_96 ||
V_92 -> V_96 == V_98 )
V_92 -> V_96 = V_93 ;
V_122 = V_93 ;
V_117:
F_2 ( L_16 ,
V_14 , V_92 -> V_95 [ 0 ] , V_92 -> V_96 , V_122 ) ;
return V_122 ;
}
static void F_49 ( struct V_123 * args ,
struct V_110 * V_34 , int V_124 )
{
args -> V_125 = NULL ;
args -> V_126 = 0 ;
if ( V_124 )
args -> V_126 = 1 ;
V_34 -> V_111 = NULL ;
V_34 -> V_112 = NULL ;
}
int F_50 ( struct V_103 * V_127 ,
struct V_123 * args ,
struct V_110 * V_34 ,
struct V_99 * V_100 )
{
struct V_128 * V_129 ;
struct V_91 * V_92 ;
T_3 V_93 ;
F_2 ( L_17 , V_14 ) ;
if ( V_34 -> V_112 != NULL )
return 0 ;
V_92 = & V_127 -> V_107 ;
F_26 ( & V_92 -> V_113 ) ;
if ( F_36 ( V_105 , & V_127 -> V_106 ) &&
! F_51 ( V_100 , V_102 ) ) {
F_52 ( & V_92 -> V_108 , V_100 , NULL ) ;
F_28 ( & V_92 -> V_113 ) ;
F_2 ( L_18 , V_14 ) ;
return - V_130 ;
}
if ( ! F_53 ( & V_92 -> V_108 ) &&
! F_51 ( V_100 , V_102 ) ) {
F_52 ( & V_92 -> V_108 , V_100 , NULL ) ;
F_28 ( & V_92 -> V_113 ) ;
F_2 ( L_19 , V_14 ) ;
return - V_130 ;
}
V_93 = F_46 ( V_92 ) ;
if ( V_93 == V_98 ) {
F_52 ( & V_92 -> V_108 , V_100 , NULL ) ;
F_28 ( & V_92 -> V_113 ) ;
F_2 ( L_20 , V_14 ) ;
return - V_130 ;
}
F_28 ( & V_92 -> V_113 ) ;
F_34 ( V_100 , V_131 ) ;
V_129 = V_92 -> V_114 + V_93 ;
args -> V_125 = V_127 ;
args -> V_132 = V_93 ;
F_2 ( L_21 , V_14 , V_93 , V_129 -> V_118 ) ;
V_34 -> V_111 = V_127 ;
V_34 -> V_112 = V_129 ;
V_34 -> V_119 = V_133 ;
V_34 -> V_120 = 0 ;
V_34 -> V_115 = 1 ;
return 0 ;
}
int F_54 ( const struct V_47 * V_48 ,
struct V_123 * args ,
struct V_110 * V_34 ,
struct V_99 * V_100 )
{
struct V_103 * V_127 = F_55 ( V_48 ) ;
int V_55 = 0 ;
if ( V_127 == NULL )
goto V_117;
F_2 ( L_22 ,
V_14 , V_127 -> V_33 , V_127 , V_34 -> V_112 ?
V_34 -> V_112 - V_127 -> V_107 . V_114 : - 1 ) ;
V_55 = F_50 ( V_127 , args , V_34 , V_100 ) ;
V_117:
F_2 ( L_23 , V_14 , V_55 ) ;
return V_55 ;
}
static void F_56 ( struct V_99 * V_100 , void * V_134 )
{
struct V_135 * V_136 = V_134 ;
F_2 ( L_24 , V_14 , V_136 -> V_137 ) ;
if ( F_54 ( V_136 -> V_137 , V_136 -> V_138 ,
V_136 -> V_139 , V_100 ) )
return;
F_57 ( V_100 ) ;
}
static void F_58 ( struct V_99 * V_100 , void * V_134 )
{
F_34 ( V_100 , V_102 ) ;
F_56 ( V_100 , V_134 ) ;
}
static void F_59 ( struct V_99 * V_100 , void * V_134 )
{
struct V_135 * V_136 = V_134 ;
F_41 ( V_100 , V_136 -> V_139 ) ;
}
static int F_60 ( struct V_40 * V_41 ,
struct V_47 * V_48 ,
struct V_140 * V_141 ,
struct V_123 * args ,
struct V_110 * V_34 ,
int V_142 )
{
int V_55 ;
struct V_99 * V_100 ;
struct V_135 V_136 = {
. V_137 = V_48 ,
. V_138 = args ,
. V_139 = V_34 ,
} ;
struct V_143 V_144 = {
. V_145 = V_41 ,
. V_140 = V_141 ,
. V_146 = & V_147 ,
. V_148 = & V_136
} ;
if ( V_142 )
V_144 . V_146 = & V_149 ;
V_100 = F_61 ( & V_144 ) ;
if ( F_62 ( V_100 ) )
V_55 = F_63 ( V_100 ) ;
else {
V_55 = V_100 -> V_150 ;
F_64 ( V_100 ) ;
}
return V_55 ;
}
int F_65 ( struct V_40 * V_41 ,
struct V_47 * V_48 ,
struct V_140 * V_141 ,
struct V_123 * args ,
struct V_110 * V_34 ,
int V_124 )
{
F_49 ( args , V_34 , V_124 ) ;
return F_60 ( V_41 , V_48 , V_141 , args , V_34 , 0 ) ;
}
static inline
void F_49 ( struct V_123 * args ,
struct V_110 * V_34 , int V_124 )
{
}
static int F_45 ( struct V_99 * V_100 ,
struct V_110 * V_34 )
{
return 1 ;
}
int F_66 ( struct V_40 * V_41 ,
struct V_47 * V_48 ,
struct V_140 * V_141 ,
struct V_123 * args ,
struct V_110 * V_34 ,
int V_124 )
{
F_49 ( args , V_34 , V_124 ) ;
return F_67 ( V_41 , V_141 , 0 ) ;
}
static inline
int F_68 ( struct V_40 * V_41 ,
struct V_47 * V_48 ,
struct V_140 * V_141 ,
struct V_123 * args ,
struct V_110 * V_34 ,
int V_124 )
{
return V_48 -> V_32 -> V_151 -> V_152 ( V_41 , V_48 , V_141 ,
args , V_34 , V_124 ) ;
}
static void F_69 ( struct V_54 * V_153 , struct V_154 * V_155 )
{
struct V_156 * V_157 = F_70 ( V_153 ) ;
F_26 ( & V_153 -> V_158 ) ;
V_157 -> V_159 |= V_160 | V_161 ;
if ( ! V_155 -> V_162 || V_155 -> V_163 != V_153 -> V_164 )
F_71 ( V_153 ) ;
V_153 -> V_164 = V_155 -> V_165 ;
F_28 ( & V_153 -> V_158 ) ;
}
static void F_72 ( struct V_166 * V_22 )
{
V_22 -> V_167 . V_168 = & V_22 -> V_168 ;
V_22 -> V_167 . V_169 = V_22 -> V_170 . V_169 ;
V_22 -> V_171 . V_169 = V_22 -> V_172 . V_169 ;
V_22 -> V_167 . V_48 = V_22 -> V_170 . V_48 ;
V_22 -> V_167 . V_173 = V_22 -> V_170 . V_174 ;
F_73 ( & V_22 -> V_168 ) ;
F_74 ( & V_22 -> V_168 , & V_22 -> V_175 , & V_22 -> V_176 ) ;
}
static struct V_166 * F_75 ( struct V_18 * V_18 ,
struct V_177 * V_178 , T_4 V_179 , int V_180 ,
const struct V_181 * V_182 ,
T_5 V_183 )
{
struct V_18 * V_184 = F_76 ( V_18 ) ;
struct V_54 * V_153 = V_184 -> V_28 ;
struct V_47 * V_48 = F_77 ( V_153 ) ;
struct V_166 * V_22 ;
V_22 = F_78 ( sizeof( * V_22 ) , V_183 ) ;
if ( V_22 == NULL )
goto V_1;
V_22 -> V_170 . V_169 = F_79 ( & V_178 -> V_185 , V_183 ) ;
if ( V_22 -> V_170 . V_169 == NULL )
goto V_186;
F_80 ( V_18 -> V_187 ) ;
V_22 -> V_18 = F_81 ( V_18 ) ;
V_22 -> V_153 = V_184 ;
V_22 -> V_188 = V_178 ;
F_82 ( & V_178 -> V_189 ) ;
V_22 -> V_170 . V_190 = F_83 ( V_153 ) ;
V_22 -> V_170 . V_191 = V_180 ;
V_22 -> V_170 . V_179 = V_179 & ( V_58 | V_192 ) ;
if ( ! ( V_180 & V_193 ) ) {
V_22 -> V_170 . V_174 = V_194 | V_195 |
V_196 | V_197 ;
}
V_22 -> V_170 . V_198 = V_48 -> V_32 -> V_199 ;
V_22 -> V_170 . V_200 . V_201 = F_84 ( V_178 -> V_185 . V_201 ) ;
V_22 -> V_170 . V_200 . V_202 = V_178 -> V_185 . V_203 ;
V_22 -> V_170 . V_204 = & V_18 -> V_205 ;
V_22 -> V_170 . V_48 = V_48 ;
V_22 -> V_170 . V_206 = V_48 -> V_207 ;
V_22 -> V_170 . V_208 = & V_209 [ 0 ] ;
V_22 -> V_170 . V_210 = V_211 ;
if ( V_182 != NULL && V_182 -> V_212 != 0 ) {
T_2 V_213 [ 2 ] ;
V_22 -> V_170 . V_214 . V_182 = & V_22 -> V_182 ;
memcpy ( & V_22 -> V_182 , V_182 , sizeof( V_22 -> V_182 ) ) ;
V_213 [ 0 ] = V_133 ;
V_213 [ 1 ] = V_45 -> V_215 ;
memcpy ( V_22 -> V_170 . V_214 . V_17 . V_136 , V_213 ,
sizeof( V_22 -> V_170 . V_214 . V_17 . V_136 ) ) ;
}
V_22 -> V_172 . V_190 = & V_22 -> V_167 . V_190 ;
V_22 -> V_172 . V_216 = & V_22 -> V_167 . V_216 ;
V_22 -> V_172 . V_169 = V_22 -> V_170 . V_169 ;
F_72 ( V_22 ) ;
F_85 ( & V_22 -> V_217 ) ;
return V_22 ;
V_186:
F_86 ( V_22 ) ;
V_1:
F_87 ( V_184 ) ;
return NULL ;
}
static void F_88 ( struct V_217 * V_217 )
{
struct V_166 * V_22 = F_89 ( V_217 ,
struct V_166 , V_217 ) ;
struct V_218 * V_219 = V_22 -> V_18 -> V_187 ;
F_90 ( V_22 -> V_170 . V_169 ) ;
if ( V_22 -> V_53 != NULL )
F_91 ( V_22 -> V_53 ) ;
F_92 ( V_22 -> V_188 ) ;
F_87 ( V_22 -> V_153 ) ;
F_87 ( V_22 -> V_18 ) ;
F_93 ( V_219 ) ;
F_94 ( & V_22 -> V_168 ) ;
F_86 ( V_22 ) ;
}
static void F_95 ( struct V_166 * V_22 )
{
if ( V_22 != NULL )
F_96 ( & V_22 -> V_217 , F_88 ) ;
}
static int F_97 ( struct V_99 * V_100 )
{
int V_55 ;
V_55 = F_98 ( V_100 ) ;
return V_55 ;
}
static int F_99 ( struct V_52 * V_53 , T_4 V_220 , int V_221 )
{
int V_55 = 0 ;
if ( V_221 & ( V_193 | V_222 ) )
goto V_117;
switch ( V_220 & ( V_58 | V_192 ) ) {
case V_58 :
V_55 |= F_36 ( V_223 , & V_53 -> V_180 ) != 0
&& V_53 -> V_224 != 0 ;
break;
case V_192 :
V_55 |= F_36 ( V_225 , & V_53 -> V_180 ) != 0
&& V_53 -> V_226 != 0 ;
break;
case V_58 | V_192 :
V_55 |= F_36 ( V_227 , & V_53 -> V_180 ) != 0
&& V_53 -> V_228 != 0 ;
}
V_117:
return V_55 ;
}
static int F_100 ( struct V_229 * V_230 , T_4 V_179 )
{
if ( V_230 == NULL )
return 0 ;
if ( ( V_230 -> type & V_179 ) != V_179 )
return 0 ;
if ( F_36 ( V_231 , & V_230 -> V_180 ) )
return 0 ;
F_101 ( V_230 ) ;
return 1 ;
}
static void F_102 ( struct V_52 * V_53 , T_4 V_179 )
{
switch ( V_179 ) {
case V_192 :
V_53 -> V_226 ++ ;
break;
case V_58 :
V_53 -> V_224 ++ ;
break;
case V_58 | V_192 :
V_53 -> V_228 ++ ;
}
F_103 ( V_53 , V_53 -> V_53 | V_179 ) ;
}
static void F_104 ( struct V_52 * V_53 , T_6 * V_216 , T_4 V_179 )
{
if ( F_36 ( V_232 , & V_53 -> V_180 ) == 0 )
F_105 ( & V_53 -> V_216 , V_216 ) ;
F_105 ( & V_53 -> V_233 , V_216 ) ;
switch ( V_179 ) {
case V_58 :
F_106 ( V_223 , & V_53 -> V_180 ) ;
break;
case V_192 :
F_106 ( V_225 , & V_53 -> V_180 ) ;
break;
case V_58 | V_192 :
F_106 ( V_227 , & V_53 -> V_180 ) ;
}
}
static void F_107 ( struct V_52 * V_53 , T_6 * V_216 , T_4 V_179 )
{
F_108 ( & V_53 -> V_234 ) ;
F_104 ( V_53 , V_216 , V_179 ) ;
F_109 ( & V_53 -> V_234 ) ;
}
static void F_110 ( struct V_52 * V_53 , T_6 * V_233 , const T_6 * V_235 , T_4 V_179 )
{
F_108 ( & V_53 -> V_234 ) ;
if ( V_235 != NULL ) {
F_105 ( & V_53 -> V_216 , V_235 ) ;
F_106 ( V_232 , & V_53 -> V_180 ) ;
}
if ( V_233 != NULL )
F_104 ( V_53 , V_233 , V_179 ) ;
F_109 ( & V_53 -> V_234 ) ;
F_26 ( & V_53 -> V_188 -> V_236 ) ;
F_102 ( V_53 , V_179 ) ;
F_28 ( & V_53 -> V_188 -> V_236 ) ;
}
static int F_111 ( struct V_52 * V_53 , T_6 * V_233 , T_6 * V_230 , T_4 V_179 )
{
struct V_156 * V_157 = F_70 ( V_53 -> V_54 ) ;
struct V_229 * V_237 ;
int V_55 = 0 ;
V_179 &= ( V_58 | V_192 ) ;
F_112 () ;
V_237 = F_113 ( V_157 -> V_230 ) ;
if ( V_237 == NULL )
goto V_238;
F_26 ( & V_237 -> V_239 ) ;
if ( V_157 -> V_230 != V_237 ||
( V_237 -> type & V_179 ) != V_179 )
goto V_240;
if ( V_230 == NULL )
V_230 = & V_237 -> V_216 ;
else if ( ! F_114 ( & V_237 -> V_216 , V_230 ) )
goto V_240;
F_101 ( V_237 ) ;
F_110 ( V_53 , V_233 , & V_237 -> V_216 , V_179 ) ;
V_55 = 1 ;
V_240:
F_28 ( & V_237 -> V_239 ) ;
V_238:
F_115 () ;
if ( ! V_55 && V_233 != NULL ) {
F_110 ( V_53 , V_233 , NULL , V_179 ) ;
V_55 = 1 ;
}
return V_55 ;
}
static void F_116 ( struct V_54 * V_54 , T_4 V_179 )
{
struct V_229 * V_230 ;
F_112 () ;
V_230 = F_113 ( F_70 ( V_54 ) -> V_230 ) ;
if ( V_230 == NULL || ( V_230 -> type & V_179 ) == V_179 ) {
F_115 () ;
return;
}
F_115 () ;
F_18 ( V_54 ) ;
}
static struct V_52 * F_117 ( struct V_166 * V_241 )
{
struct V_52 * V_53 = V_241 -> V_53 ;
struct V_156 * V_157 = F_70 ( V_53 -> V_54 ) ;
struct V_229 * V_230 ;
int V_221 = V_241 -> V_170 . V_191 & ( V_193 | V_222 ) ;
T_4 V_179 = V_241 -> V_170 . V_179 ;
T_6 V_216 ;
int V_55 = - V_130 ;
for (; ; ) {
if ( F_99 ( V_53 , V_179 , V_221 ) ) {
F_26 ( & V_53 -> V_188 -> V_236 ) ;
if ( F_99 ( V_53 , V_179 , V_221 ) ) {
F_102 ( V_53 , V_179 ) ;
F_28 ( & V_53 -> V_188 -> V_236 ) ;
goto V_242;
}
F_28 ( & V_53 -> V_188 -> V_236 ) ;
}
F_112 () ;
V_230 = F_113 ( V_157 -> V_230 ) ;
if ( ! F_100 ( V_230 , V_179 ) ) {
F_115 () ;
break;
}
F_105 ( & V_216 , & V_230 -> V_216 ) ;
F_115 () ;
V_55 = F_118 ( V_53 -> V_54 , V_53 -> V_188 -> V_243 , V_221 ) ;
if ( V_55 != 0 )
goto V_117;
V_55 = - V_130 ;
if ( F_111 ( V_53 , NULL , & V_216 , V_179 ) )
goto V_242;
}
V_117:
return F_119 ( V_55 ) ;
V_242:
F_82 ( & V_53 -> V_23 ) ;
return V_53 ;
}
static void
F_120 ( struct V_166 * V_136 , struct V_52 * V_53 )
{
struct V_32 * V_33 = F_77 ( V_53 -> V_54 ) -> V_32 ;
struct V_229 * V_230 ;
int V_244 = 0 ;
F_112 () ;
V_230 = F_113 ( F_70 ( V_53 -> V_54 ) -> V_230 ) ;
if ( V_230 )
V_244 = V_230 -> V_180 ;
F_115 () ;
if ( V_136 -> V_170 . V_210 == V_245 ) {
F_121 ( L_25
L_26
L_27 ,
V_33 -> V_87 ) ;
} else if ( ( V_244 & 1UL << V_231 ) == 0 )
F_122 ( V_53 -> V_54 ,
V_136 -> V_188 -> V_243 ,
& V_136 -> V_167 ) ;
else
F_123 ( V_53 -> V_54 ,
V_136 -> V_188 -> V_243 ,
& V_136 -> V_167 ) ;
}
static struct V_52 *
F_124 ( struct V_166 * V_136 )
{
struct V_54 * V_54 = V_136 -> V_53 -> V_54 ;
struct V_52 * V_53 = V_136 -> V_53 ;
int V_55 ;
if ( ! V_136 -> V_246 ) {
V_55 = V_136 -> V_247 ;
goto V_1;
}
V_55 = - V_248 ;
if ( ! ( V_136 -> V_168 . V_249 & V_250 ) ||
! ( V_136 -> V_168 . V_249 & V_251 ) ||
! ( V_136 -> V_168 . V_249 & V_252 ) )
goto V_1;
V_55 = - V_253 ;
V_53 = F_125 ( V_54 , V_136 -> V_188 ) ;
if ( V_53 == NULL )
goto V_1;
V_55 = F_126 ( V_54 , & V_136 -> V_168 ) ;
if ( V_55 )
goto V_1;
if ( V_136 -> V_167 . V_254 != 0 )
F_120 ( V_136 , V_53 ) ;
F_111 ( V_53 , & V_136 -> V_167 . V_216 , NULL ,
V_136 -> V_170 . V_179 ) ;
return V_53 ;
V_1:
return F_119 ( V_55 ) ;
}
static struct V_52 *
F_127 ( struct V_166 * V_136 )
{
struct V_54 * V_54 ;
struct V_52 * V_53 = NULL ;
int V_55 ;
if ( ! V_136 -> V_246 ) {
V_53 = F_117 ( V_136 ) ;
goto V_117;
}
V_55 = - V_130 ;
if ( ! ( V_136 -> V_168 . V_249 & V_255 ) )
goto V_1;
V_54 = F_128 ( V_136 -> V_153 -> V_187 , & V_136 -> V_167 . V_190 , & V_136 -> V_168 ) ;
V_55 = F_63 ( V_54 ) ;
if ( F_62 ( V_54 ) )
goto V_1;
V_55 = - V_253 ;
V_53 = F_125 ( V_54 , V_136 -> V_188 ) ;
if ( V_53 == NULL )
goto V_256;
if ( V_136 -> V_167 . V_254 != 0 )
F_120 ( V_136 , V_53 ) ;
F_111 ( V_53 , & V_136 -> V_167 . V_216 , NULL ,
V_136 -> V_170 . V_179 ) ;
F_129 ( V_54 ) ;
V_117:
return V_53 ;
V_256:
F_129 ( V_54 ) ;
V_1:
return F_119 ( V_55 ) ;
}
static struct V_52 *
F_130 ( struct V_166 * V_136 )
{
if ( V_136 -> V_170 . V_210 == V_257 )
return F_124 ( V_136 ) ;
return F_127 ( V_136 ) ;
}
static struct V_258 * F_131 ( struct V_52 * V_53 )
{
struct V_156 * V_157 = F_70 ( V_53 -> V_54 ) ;
struct V_258 * V_259 ;
F_26 ( & V_53 -> V_54 -> V_158 ) ;
F_132 (ctx, &nfsi->open_files, list) {
if ( V_259 -> V_53 != V_53 )
continue;
F_133 ( V_259 ) ;
F_28 ( & V_53 -> V_54 -> V_158 ) ;
return V_259 ;
}
F_28 ( & V_53 -> V_54 -> V_158 ) ;
return F_119 ( - V_260 ) ;
}
static struct V_166 * F_134 ( struct V_258 * V_259 , struct V_52 * V_53 )
{
struct V_166 * V_241 ;
V_241 = F_75 ( V_259 -> V_18 , V_53 -> V_188 , 0 , 0 , NULL , V_261 ) ;
if ( V_241 == NULL )
return F_119 ( - V_253 ) ;
V_241 -> V_53 = V_53 ;
F_82 ( & V_53 -> V_23 ) ;
return V_241 ;
}
static int F_135 ( struct V_166 * V_241 , T_4 V_179 , struct V_52 * * V_34 )
{
struct V_52 * V_262 ;
int V_55 ;
V_241 -> V_170 . V_191 = 0 ;
V_241 -> V_170 . V_179 = V_179 ;
memset ( & V_241 -> V_167 , 0 , sizeof( V_241 -> V_167 ) ) ;
memset ( & V_241 -> V_171 , 0 , sizeof( V_241 -> V_171 ) ) ;
F_72 ( V_241 ) ;
V_55 = F_136 ( V_241 ) ;
if ( V_55 != 0 )
return V_55 ;
V_262 = F_130 ( V_241 ) ;
if ( F_62 ( V_262 ) )
return F_63 ( V_262 ) ;
F_137 ( V_262 , V_179 ) ;
* V_34 = V_262 ;
return 0 ;
}
static int F_138 ( struct V_166 * V_241 , struct V_52 * V_53 )
{
struct V_52 * V_262 ;
int V_55 ;
F_139 ( V_232 , & V_53 -> V_180 ) ;
F_140 () ;
if ( V_53 -> V_228 != 0 ) {
F_139 ( V_227 , & V_53 -> V_180 ) ;
V_55 = F_135 ( V_241 , V_58 | V_192 , & V_262 ) ;
if ( V_55 != 0 )
return V_55 ;
if ( V_262 != V_53 )
return - V_248 ;
}
if ( V_53 -> V_226 != 0 ) {
F_139 ( V_225 , & V_53 -> V_180 ) ;
V_55 = F_135 ( V_241 , V_192 , & V_262 ) ;
if ( V_55 != 0 )
return V_55 ;
if ( V_262 != V_53 )
return - V_248 ;
}
if ( V_53 -> V_224 != 0 ) {
F_139 ( V_223 , & V_53 -> V_180 ) ;
V_55 = F_135 ( V_241 , V_58 , & V_262 ) ;
if ( V_55 != 0 )
return V_55 ;
if ( V_262 != V_53 )
return - V_248 ;
}
if ( F_36 ( V_232 , & V_53 -> V_180 ) == 0 &&
! F_114 ( & V_53 -> V_216 , & V_53 -> V_233 ) ) {
F_108 ( & V_53 -> V_234 ) ;
if ( F_36 ( V_232 , & V_53 -> V_180 ) == 0 )
F_105 ( & V_53 -> V_216 , & V_53 -> V_233 ) ;
F_109 ( & V_53 -> V_234 ) ;
}
return 0 ;
}
static int F_141 ( struct V_258 * V_259 , struct V_52 * V_53 )
{
struct V_229 * V_230 ;
struct V_166 * V_241 ;
T_4 V_254 = 0 ;
int V_263 ;
V_241 = F_134 ( V_259 , V_53 ) ;
if ( F_62 ( V_241 ) )
return F_63 ( V_241 ) ;
V_241 -> V_170 . V_210 = V_257 ;
V_241 -> V_170 . V_190 = F_83 ( V_53 -> V_54 ) ;
F_112 () ;
V_230 = F_113 ( F_70 ( V_53 -> V_54 ) -> V_230 ) ;
if ( V_230 != NULL && F_36 ( V_231 , & V_230 -> V_180 ) != 0 )
V_254 = V_230 -> type ;
F_115 () ;
V_241 -> V_170 . V_214 . V_254 = V_254 ;
V_263 = F_138 ( V_241 , V_53 ) ;
F_95 ( V_241 ) ;
return V_263 ;
}
static int F_142 ( struct V_258 * V_259 , struct V_52 * V_53 )
{
struct V_47 * V_48 = F_77 ( V_53 -> V_54 ) ;
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_141 ( V_259 , V_53 ) ;
if ( V_1 != - V_79 )
break;
F_16 ( V_48 , V_1 , & V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static int F_143 ( struct V_177 * V_178 , struct V_52 * V_53 )
{
struct V_258 * V_259 ;
int V_55 ;
V_259 = F_131 ( V_53 ) ;
if ( F_62 ( V_259 ) )
return F_63 ( V_259 ) ;
V_55 = F_142 ( V_259 , V_53 ) ;
F_144 ( V_259 ) ;
return V_55 ;
}
static int F_145 ( struct V_258 * V_259 , struct V_52 * V_53 , const T_6 * V_216 )
{
struct V_166 * V_241 ;
int V_55 ;
V_241 = F_134 ( V_259 , V_53 ) ;
if ( F_62 ( V_241 ) )
return F_63 ( V_241 ) ;
V_241 -> V_170 . V_210 = V_245 ;
F_105 ( & V_241 -> V_170 . V_214 . V_230 , V_216 ) ;
V_55 = F_138 ( V_241 , V_53 ) ;
F_95 ( V_241 ) ;
return V_55 ;
}
int F_146 ( struct V_258 * V_259 , struct V_52 * V_53 , const T_6 * V_216 )
{
struct V_50 V_51 = { } ;
struct V_47 * V_48 = F_77 ( V_53 -> V_54 ) ;
int V_1 ;
do {
V_1 = F_145 ( V_259 , V_53 , V_216 ) ;
switch ( V_1 ) {
case 0 :
case - V_260 :
case - V_248 :
goto V_117;
case - V_67 :
case - V_68 :
case - V_69 :
case - V_70 :
case - V_71 :
F_23 ( V_48 -> V_32 -> V_74 , V_1 ) ;
goto V_117;
case - V_65 :
case - V_64 :
case - V_63 :
F_21 ( V_48 -> V_32 ) ;
goto V_117;
case - V_46 :
case - V_60 :
case - V_61 :
case - V_62 :
F_147 ( V_53 -> V_54 ,
V_216 ) ;
F_19 ( V_48 , V_53 ) ;
case - V_80 :
case - V_253 :
V_1 = 0 ;
goto V_117;
}
V_1 = F_16 ( V_48 , V_1 , & V_51 ) ;
} while ( V_51 . V_56 );
V_117:
return V_1 ;
}
static void F_148 ( struct V_99 * V_100 , void * V_134 )
{
struct V_166 * V_136 = V_134 ;
V_136 -> V_247 = V_100 -> V_150 ;
if ( V_136 -> V_247 == 0 ) {
F_105 ( & V_136 -> V_167 . V_216 , & V_136 -> V_171 . V_216 ) ;
F_149 ( & V_136 -> V_188 -> V_185 , 0 ) ;
F_29 ( V_136 -> V_167 . V_48 , V_136 -> V_88 ) ;
V_136 -> V_246 = 1 ;
}
}
static void F_150 ( void * V_134 )
{
struct V_166 * V_136 = V_134 ;
struct V_52 * V_53 = NULL ;
if ( V_136 -> V_264 == 0 )
goto V_265;
if ( ! V_136 -> V_246 )
goto V_265;
V_53 = F_130 ( V_136 ) ;
if ( ! F_62 ( V_53 ) )
F_137 ( V_53 , V_136 -> V_170 . V_179 ) ;
V_265:
F_95 ( V_136 ) ;
}
static int F_151 ( struct V_166 * V_136 )
{
struct V_47 * V_48 = F_77 ( V_136 -> V_153 -> V_28 ) ;
struct V_99 * V_100 ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_268 ] ,
. V_269 = & V_136 -> V_172 ,
. V_270 = & V_136 -> V_171 ,
. V_271 = V_136 -> V_188 -> V_243 ,
} ;
struct V_143 V_272 = {
. V_145 = V_48 -> V_81 ,
. V_140 = & V_141 ,
. V_146 = & V_273 ,
. V_148 = V_136 ,
. V_274 = V_275 ,
. V_180 = V_276 ,
} ;
int V_263 ;
F_152 ( & V_136 -> V_217 ) ;
V_136 -> V_246 = 0 ;
V_136 -> V_247 = 0 ;
V_136 -> V_88 = V_133 ;
V_100 = F_61 ( & V_272 ) ;
if ( F_62 ( V_100 ) )
return F_63 ( V_100 ) ;
V_263 = F_97 ( V_100 ) ;
if ( V_263 != 0 ) {
V_136 -> V_264 = 1 ;
F_153 () ;
} else
V_263 = V_136 -> V_247 ;
F_64 ( V_100 ) ;
return V_263 ;
}
static void F_154 ( struct V_99 * V_100 , void * V_134 )
{
struct V_166 * V_136 = V_134 ;
struct V_177 * V_178 = V_136 -> V_188 ;
if ( F_155 ( V_136 -> V_170 . V_169 , V_100 ) != 0 )
return;
if ( V_136 -> V_53 != NULL ) {
struct V_229 * V_230 ;
if ( F_99 ( V_136 -> V_53 , V_136 -> V_170 . V_179 , V_136 -> V_170 . V_191 ) )
goto V_277;
F_112 () ;
V_230 = F_113 ( F_70 ( V_136 -> V_53 -> V_54 ) -> V_230 ) ;
if ( V_136 -> V_170 . V_210 != V_245 &&
F_100 ( V_230 , V_136 -> V_170 . V_179 ) )
goto V_278;
F_115 () ;
}
V_136 -> V_170 . V_198 = V_178 -> V_279 -> V_32 -> V_199 ;
if ( V_136 -> V_170 . V_210 == V_257 ) {
V_100 -> V_280 . V_266 = & V_267 [ V_281 ] ;
V_136 -> V_170 . V_208 = & V_282 [ 0 ] ;
F_156 ( & V_136 -> V_167 . V_190 , V_136 -> V_170 . V_190 ) ;
}
V_136 -> V_88 = V_133 ;
if ( F_54 ( V_136 -> V_170 . V_48 ,
& V_136 -> V_170 . V_138 ,
& V_136 -> V_167 . V_139 ,
V_100 ) != 0 )
F_157 ( V_136 -> V_170 . V_169 ) ;
else
F_57 ( V_100 ) ;
return;
V_278:
F_115 () ;
V_277:
V_100 -> V_283 = NULL ;
}
static void F_158 ( struct V_99 * V_100 , void * V_134 )
{
F_34 ( V_100 , V_102 ) ;
F_154 ( V_100 , V_134 ) ;
}
static void F_159 ( struct V_99 * V_100 , void * V_134 )
{
struct V_166 * V_136 = V_134 ;
V_136 -> V_247 = V_100 -> V_150 ;
if ( ! F_45 ( V_100 , & V_136 -> V_167 . V_139 ) )
return;
if ( V_100 -> V_150 == 0 ) {
if ( V_136 -> V_167 . V_168 -> V_249 & V_250 ) {
switch ( V_136 -> V_167 . V_168 -> V_220 & V_284 ) {
case V_285 :
break;
case V_286 :
V_136 -> V_247 = - V_287 ;
break;
case V_288 :
V_136 -> V_247 = - V_289 ;
break;
default:
V_136 -> V_247 = - V_290 ;
}
}
F_29 ( V_136 -> V_167 . V_48 , V_136 -> V_88 ) ;
if ( ! ( V_136 -> V_167 . V_291 & V_292 ) )
F_149 ( & V_136 -> V_188 -> V_185 , 0 ) ;
}
V_136 -> V_246 = 1 ;
}
static void F_160 ( void * V_134 )
{
struct V_166 * V_136 = V_134 ;
struct V_52 * V_53 = NULL ;
if ( V_136 -> V_264 == 0 )
goto V_265;
if ( V_136 -> V_247 != 0 || ! V_136 -> V_246 )
goto V_265;
if ( V_136 -> V_167 . V_291 & V_292 )
goto V_265;
V_53 = F_130 ( V_136 ) ;
if ( ! F_62 ( V_53 ) )
F_137 ( V_53 , V_136 -> V_170 . V_179 ) ;
V_265:
F_95 ( V_136 ) ;
}
static int F_161 ( struct V_166 * V_136 , int V_293 )
{
struct V_54 * V_153 = V_136 -> V_153 -> V_28 ;
struct V_47 * V_48 = F_77 ( V_153 ) ;
struct V_294 * V_170 = & V_136 -> V_170 ;
struct V_295 * V_167 = & V_136 -> V_167 ;
struct V_99 * V_100 ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_296 ] ,
. V_269 = V_170 ,
. V_270 = V_167 ,
. V_271 = V_136 -> V_188 -> V_243 ,
} ;
struct V_143 V_272 = {
. V_145 = V_48 -> V_81 ,
. V_140 = & V_141 ,
. V_146 = & V_297 ,
. V_148 = V_136 ,
. V_274 = V_275 ,
. V_180 = V_276 ,
} ;
int V_263 ;
F_49 ( & V_170 -> V_138 , & V_167 -> V_139 , 1 ) ;
F_152 ( & V_136 -> V_217 ) ;
V_136 -> V_246 = 0 ;
V_136 -> V_247 = 0 ;
V_136 -> V_264 = 0 ;
if ( V_293 )
V_272 . V_146 = & V_298 ;
V_100 = F_61 ( & V_272 ) ;
if ( F_62 ( V_100 ) )
return F_63 ( V_100 ) ;
V_263 = F_97 ( V_100 ) ;
if ( V_263 != 0 ) {
V_136 -> V_264 = 1 ;
F_153 () ;
} else
V_263 = V_136 -> V_247 ;
F_64 ( V_100 ) ;
return V_263 ;
}
static int F_136 ( struct V_166 * V_136 )
{
struct V_54 * V_153 = V_136 -> V_153 -> V_28 ;
struct V_295 * V_167 = & V_136 -> V_167 ;
int V_263 ;
V_263 = F_161 ( V_136 , 1 ) ;
if ( V_263 != 0 || ! V_136 -> V_246 )
return V_263 ;
F_162 ( F_77 ( V_153 ) , & V_136 -> V_168 ) ;
if ( V_167 -> V_291 & V_292 ) {
V_263 = F_151 ( V_136 ) ;
if ( V_263 != 0 )
return V_263 ;
}
return V_263 ;
}
static int F_163 ( struct V_271 * V_299 ,
struct V_166 * V_241 ,
struct V_52 * V_53 , T_4 V_179 )
{
struct V_300 V_301 ;
T_3 V_302 ;
if ( V_241 -> V_167 . V_303 == 0 )
return 0 ;
V_302 = 0 ;
if ( V_179 & V_58 )
V_302 |= V_304 ;
if ( V_179 & V_305 )
V_302 |= V_306 ;
V_301 . V_299 = V_299 ;
V_301 . V_133 = V_133 ;
F_164 ( & V_301 , V_241 -> V_167 . V_307 ) ;
F_165 ( V_53 -> V_54 , & V_301 ) ;
if ( ( V_302 & ~ V_301 . V_302 & ( V_304 | V_306 ) ) == 0 )
return 0 ;
F_137 ( V_53 , V_179 ) ;
return - V_10 ;
}
static int F_166 ( struct V_166 * V_136 )
{
struct V_54 * V_153 = V_136 -> V_153 -> V_28 ;
struct V_47 * V_48 = F_77 ( V_153 ) ;
struct V_294 * V_170 = & V_136 -> V_170 ;
struct V_295 * V_167 = & V_136 -> V_167 ;
int V_263 ;
V_263 = F_161 ( V_136 , 0 ) ;
if ( ! V_136 -> V_246 )
return V_263 ;
if ( V_263 != 0 ) {
if ( V_263 == - V_7 &&
! ( V_170 -> V_191 & V_308 ) )
return - V_260 ;
return V_263 ;
}
F_162 ( V_48 , & V_136 -> V_168 ) ;
if ( V_170 -> V_191 & V_308 )
F_69 ( V_153 , & V_167 -> V_155 ) ;
if ( ( V_167 -> V_291 & V_309 ) == 0 )
V_48 -> V_84 &= ~ V_310 ;
if( V_167 -> V_291 & V_292 ) {
V_263 = F_151 ( V_136 ) ;
if ( V_263 != 0 )
return V_263 ;
}
if ( ! ( V_167 -> V_168 -> V_249 & V_255 ) )
F_167 ( V_48 , & V_167 -> V_190 , V_167 -> V_168 ) ;
return 0 ;
}
static int F_168 ( struct V_32 * V_33 )
{
unsigned int V_311 ;
int V_55 ;
for ( V_311 = V_312 ; V_311 != 0 ; V_311 -- ) {
V_55 = F_10 ( V_33 ) ;
if ( V_55 != 0 )
break;
if ( ! F_36 ( V_313 , & V_33 -> V_35 ) &&
! F_36 ( V_314 , & V_33 -> V_35 ) )
break;
F_169 ( V_33 ) ;
V_55 = - V_15 ;
}
return V_55 ;
}
static int F_170 ( struct V_47 * V_48 )
{
return F_168 ( V_48 -> V_32 ) ;
}
static int F_171 ( struct V_258 * V_259 , struct V_52 * V_53 )
{
struct V_166 * V_241 ;
int V_55 ;
V_241 = F_134 ( V_259 , V_53 ) ;
if ( F_62 ( V_241 ) )
return F_63 ( V_241 ) ;
V_55 = F_138 ( V_241 , V_53 ) ;
if ( V_55 == - V_248 )
F_172 ( V_259 -> V_18 ) ;
F_95 ( V_241 ) ;
return V_55 ;
}
static int F_173 ( struct V_258 * V_259 , struct V_52 * V_53 )
{
struct V_47 * V_48 = F_77 ( V_53 -> V_54 ) ;
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_171 ( V_259 , V_53 ) ;
switch ( V_1 ) {
default:
goto V_117;
case - V_78 :
case - V_79 :
F_16 ( V_48 , V_1 , & V_51 ) ;
V_1 = 0 ;
}
} while ( V_51 . V_56 );
V_117:
return V_1 ;
}
static int F_174 ( struct V_177 * V_178 , struct V_52 * V_53 )
{
struct V_258 * V_259 ;
int V_55 ;
V_259 = F_131 ( V_53 ) ;
if ( F_62 ( V_259 ) )
return F_63 ( V_259 ) ;
V_55 = F_173 ( V_259 , V_53 ) ;
F_144 ( V_259 ) ;
return V_55 ;
}
static void F_175 ( struct V_52 * V_53 )
{
struct V_47 * V_48 = F_77 ( V_53 -> V_54 ) ;
T_6 * V_216 = & V_53 -> V_216 ;
int V_263 ;
if ( F_36 ( V_232 , & V_53 -> V_180 ) == 0 )
return;
V_263 = F_176 ( V_48 , V_216 ) ;
if ( V_263 != V_116 ) {
if ( V_263 != - V_62 )
F_177 ( V_48 , V_216 ) ;
F_20 ( V_53 -> V_54 ) ;
F_108 ( & V_53 -> V_234 ) ;
F_105 ( & V_53 -> V_216 , & V_53 -> V_233 ) ;
F_109 ( & V_53 -> V_234 ) ;
F_139 ( V_232 , & V_53 -> V_180 ) ;
}
}
static int F_178 ( struct V_52 * V_53 )
{
struct V_47 * V_48 = F_77 ( V_53 -> V_54 ) ;
T_6 * V_216 = & V_53 -> V_233 ;
int V_263 ;
if ( ( F_36 ( V_223 , & V_53 -> V_180 ) == 0 ) &&
( F_36 ( V_225 , & V_53 -> V_180 ) == 0 ) &&
( F_36 ( V_227 , & V_53 -> V_180 ) == 0 ) )
return - V_62 ;
V_263 = F_176 ( V_48 , V_216 ) ;
if ( V_263 != V_116 ) {
if ( V_263 != - V_62 )
F_177 ( V_48 , V_216 ) ;
F_139 ( V_223 , & V_53 -> V_180 ) ;
F_139 ( V_225 , & V_53 -> V_180 ) ;
F_139 ( V_227 , & V_53 -> V_180 ) ;
}
return V_263 ;
}
static int F_179 ( struct V_177 * V_178 , struct V_52 * V_53 )
{
int V_263 ;
F_175 ( V_53 ) ;
V_263 = F_178 ( V_53 ) ;
if ( V_263 != V_116 )
V_263 = F_174 ( V_178 , V_53 ) ;
return V_263 ;
}
static inline void F_180 ( struct V_166 * V_241 , struct V_181 * V_315 )
{
if ( ( V_241 -> V_167 . V_316 [ 1 ] & V_317 ) &&
! ( V_315 -> V_212 & V_318 ) )
V_315 -> V_212 |= V_319 ;
if ( ( V_241 -> V_167 . V_316 [ 1 ] & V_320 ) &&
! ( V_315 -> V_212 & V_321 ) )
V_315 -> V_212 |= V_322 ;
}
static int F_181 ( struct V_54 * V_153 ,
struct V_18 * V_18 ,
T_4 V_179 ,
int V_180 ,
struct V_181 * V_315 ,
struct V_271 * V_299 ,
struct V_52 * * V_34 ,
struct V_323 * * V_324 )
{
struct V_177 * V_178 ;
struct V_52 * V_53 = NULL ;
struct V_47 * V_48 = F_77 ( V_153 ) ;
struct V_166 * V_241 ;
int V_263 ;
V_263 = - V_253 ;
V_178 = F_182 ( V_48 , V_299 , V_325 ) ;
if ( V_178 == NULL ) {
F_2 ( L_28 ) ;
goto V_326;
}
V_263 = F_170 ( V_48 ) ;
if ( V_263 != 0 )
goto V_327;
if ( V_18 -> V_28 != NULL )
F_116 ( V_18 -> V_28 , V_179 ) ;
V_263 = - V_253 ;
V_241 = F_75 ( V_18 , V_178 , V_179 , V_180 , V_315 , V_325 ) ;
if ( V_241 == NULL )
goto V_327;
if ( V_324 && V_48 -> V_207 [ 2 ] & V_328 ) {
V_241 -> V_168 . V_329 = F_183 () ;
if ( ! V_241 -> V_168 . V_329 )
goto V_330;
V_241 -> V_170 . V_208 = & V_331 [ 0 ] ;
}
if ( V_18 -> V_28 != NULL )
V_241 -> V_53 = F_125 ( V_18 -> V_28 , V_178 ) ;
V_263 = F_166 ( V_241 ) ;
if ( V_263 != 0 )
goto V_330;
V_53 = F_130 ( V_241 ) ;
V_263 = F_63 ( V_53 ) ;
if ( F_62 ( V_53 ) )
goto V_330;
if ( V_48 -> V_84 & V_310 )
F_106 ( V_332 , & V_53 -> V_180 ) ;
V_263 = F_163 ( V_299 , V_241 , V_53 , V_179 ) ;
if ( V_263 != 0 )
goto V_330;
if ( V_241 -> V_170 . V_191 & V_193 ) {
F_180 ( V_241 , V_315 ) ;
F_73 ( V_241 -> V_167 . V_168 ) ;
V_263 = F_184 ( V_53 -> V_54 , V_299 ,
V_241 -> V_167 . V_168 , V_315 ,
V_53 ) ;
if ( V_263 == 0 )
F_185 ( V_53 -> V_54 , V_315 ) ;
F_186 ( V_53 -> V_54 , V_241 -> V_167 . V_168 ) ;
}
if ( F_187 ( V_324 , V_241 -> V_168 . V_329 , V_48 ) )
* V_324 = V_241 -> V_168 . V_329 ;
else
F_86 ( V_241 -> V_168 . V_329 ) ;
V_241 -> V_168 . V_329 = NULL ;
F_95 ( V_241 ) ;
F_92 ( V_178 ) ;
* V_34 = V_53 ;
return 0 ;
V_330:
F_86 ( V_241 -> V_168 . V_329 ) ;
F_95 ( V_241 ) ;
V_327:
F_92 ( V_178 ) ;
V_326:
* V_34 = NULL ;
return V_263 ;
}
static struct V_52 * F_188 ( struct V_54 * V_153 ,
struct V_18 * V_18 ,
T_4 V_179 ,
int V_180 ,
struct V_181 * V_315 ,
struct V_271 * V_299 ,
struct V_323 * * V_324 )
{
struct V_50 V_51 = { } ;
struct V_52 * V_34 ;
int V_263 ;
V_179 &= V_58 | V_192 | V_305 ;
do {
V_263 = F_181 ( V_153 , V_18 , V_179 , V_180 , V_315 , V_299 ,
& V_34 , V_324 ) ;
if ( V_263 == 0 )
break;
if ( V_263 == - V_333 ) {
F_189 ( L_5
L_29 ,
F_77 ( V_153 ) -> V_32 -> V_87 ) ;
V_51 . V_56 = 1 ;
continue;
}
if ( V_263 == - V_62 ) {
V_51 . V_56 = 1 ;
continue;
}
if ( V_263 == - V_130 ) {
V_51 . V_56 = 1 ;
continue;
}
V_34 = F_119 ( F_16 ( F_77 ( V_153 ) ,
V_263 , & V_51 ) ) ;
} while ( V_51 . V_56 );
return V_34 ;
}
static int F_190 ( struct V_54 * V_54 , struct V_271 * V_299 ,
struct V_334 * V_335 , struct V_181 * V_315 ,
struct V_52 * V_53 )
{
struct V_47 * V_48 = F_77 ( V_54 ) ;
struct V_336 V_337 = {
. V_190 = F_83 ( V_54 ) ,
. V_338 = V_315 ,
. V_48 = V_48 ,
. V_206 = V_48 -> V_207 ,
} ;
struct V_339 V_34 = {
. V_335 = V_335 ,
. V_48 = V_48 ,
} ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_340 ] ,
. V_269 = & V_337 ,
. V_270 = & V_34 ,
. V_271 = V_299 ,
} ;
unsigned long V_88 = V_133 ;
int V_263 ;
F_73 ( V_335 ) ;
if ( V_53 != NULL ) {
struct V_341 V_342 = {
. V_343 = V_45 -> V_344 ,
. V_345 = V_45 -> V_346 ,
} ;
F_191 ( & V_337 . V_216 , V_53 , V_192 ,
& V_342 ) ;
} else if ( F_192 ( & V_337 . V_216 , V_54 ,
V_192 ) ) {
} else
F_105 ( & V_337 . V_216 , & V_347 ) ;
V_263 = F_68 ( V_48 -> V_81 , V_48 , & V_141 , & V_337 . V_138 , & V_34 . V_139 , 1 ) ;
if ( V_263 == 0 && V_53 != NULL )
F_29 ( V_48 , V_88 ) ;
return V_263 ;
}
static int F_184 ( struct V_54 * V_54 , struct V_271 * V_299 ,
struct V_334 * V_335 , struct V_181 * V_315 ,
struct V_52 * V_53 )
{
struct V_47 * V_48 = F_77 ( V_54 ) ;
struct V_50 V_51 = {
. V_53 = V_53 ,
. V_54 = V_54 ,
} ;
int V_1 ;
do {
V_1 = F_190 ( V_54 , V_299 , V_335 , V_315 , V_53 ) ;
switch ( V_1 ) {
case - V_57 :
if ( V_53 && ! ( V_53 -> V_53 & V_192 ) ) {
V_1 = - V_348 ;
if ( V_315 -> V_212 & V_349 )
V_1 = - V_10 ;
goto V_117;
}
}
V_1 = F_16 ( V_48 , V_1 , & V_51 ) ;
} while ( V_51 . V_56 );
V_117:
return V_1 ;
}
static void F_193 ( void * V_136 )
{
struct V_350 * V_134 = V_136 ;
struct V_177 * V_178 = V_134 -> V_53 -> V_188 ;
struct V_218 * V_219 = V_134 -> V_53 -> V_54 -> V_351 ;
if ( V_134 -> V_352 )
F_194 ( V_134 -> V_53 -> V_54 ) ;
F_91 ( V_134 -> V_53 ) ;
F_90 ( V_134 -> V_337 . V_169 ) ;
F_92 ( V_178 ) ;
F_195 ( V_219 ) ;
F_86 ( V_134 ) ;
}
static void F_196 ( struct V_52 * V_53 ,
T_4 V_179 )
{
F_26 ( & V_53 -> V_188 -> V_236 ) ;
if ( ! ( V_179 & V_58 ) )
F_139 ( V_223 , & V_53 -> V_180 ) ;
if ( ! ( V_179 & V_192 ) )
F_139 ( V_225 , & V_53 -> V_180 ) ;
F_139 ( V_227 , & V_53 -> V_180 ) ;
F_28 ( & V_53 -> V_188 -> V_236 ) ;
}
static void F_197 ( struct V_99 * V_100 , void * V_136 )
{
struct V_350 * V_134 = V_136 ;
struct V_52 * V_53 = V_134 -> V_53 ;
struct V_47 * V_48 = F_77 ( V_134 -> V_54 ) ;
F_2 ( L_30 , V_14 ) ;
if ( ! F_45 ( V_100 , & V_134 -> V_34 . V_139 ) )
return;
switch ( V_100 -> V_150 ) {
case 0 :
if ( V_134 -> V_352 )
F_198 ( V_53 -> V_54 ,
V_134 -> V_353 ) ;
F_107 ( V_53 , & V_134 -> V_34 . V_216 , 0 ) ;
F_29 ( V_48 , V_134 -> V_88 ) ;
F_196 ( V_53 ,
V_134 -> V_337 . V_179 ) ;
break;
case - V_64 :
case - V_83 :
case - V_62 :
case - V_63 :
if ( V_134 -> V_337 . V_179 == 0 )
break;
default:
if ( F_199 ( V_100 , V_48 , V_53 ) == - V_130 )
F_200 ( V_100 ) ;
}
F_157 ( V_134 -> V_337 . V_169 ) ;
F_126 ( V_134 -> V_54 , V_134 -> V_34 . V_335 ) ;
F_2 ( L_31 , V_14 , V_100 -> V_150 ) ;
}
static void F_201 ( struct V_99 * V_100 , void * V_136 )
{
struct V_350 * V_134 = V_136 ;
struct V_52 * V_53 = V_134 -> V_53 ;
struct V_54 * V_54 = V_134 -> V_54 ;
int V_354 = 0 ;
F_2 ( L_30 , V_14 ) ;
if ( F_155 ( V_134 -> V_337 . V_169 , V_100 ) != 0 )
return;
V_100 -> V_280 . V_266 = & V_267 [ V_355 ] ;
V_134 -> V_337 . V_179 = V_58 | V_192 ;
F_26 ( & V_53 -> V_188 -> V_236 ) ;
if ( V_53 -> V_228 == 0 ) {
if ( V_53 -> V_224 == 0 ) {
V_354 |= F_36 ( V_223 , & V_53 -> V_180 ) ;
V_354 |= F_36 ( V_227 , & V_53 -> V_180 ) ;
V_134 -> V_337 . V_179 &= ~ V_58 ;
}
if ( V_53 -> V_226 == 0 ) {
V_354 |= F_36 ( V_225 , & V_53 -> V_180 ) ;
V_354 |= F_36 ( V_227 , & V_53 -> V_180 ) ;
V_134 -> V_337 . V_179 &= ~ V_192 ;
}
}
F_28 ( & V_53 -> V_188 -> V_236 ) ;
if ( ! V_354 ) {
V_100 -> V_283 = NULL ;
goto V_117;
}
if ( V_134 -> V_337 . V_179 == 0 ) {
V_100 -> V_280 . V_266 = & V_267 [ V_356 ] ;
if ( V_134 -> V_352 &&
F_202 ( V_54 , & V_134 -> V_353 , V_100 ) )
goto V_117;
}
F_73 ( V_134 -> V_34 . V_335 ) ;
V_134 -> V_88 = V_133 ;
if ( F_54 ( F_77 ( V_54 ) ,
& V_134 -> V_337 . V_138 ,
& V_134 -> V_34 . V_139 ,
V_100 ) != 0 )
F_157 ( V_134 -> V_337 . V_169 ) ;
else
F_57 ( V_100 ) ;
V_117:
F_2 ( L_32 , V_14 ) ;
}
int F_203 ( struct V_52 * V_53 , T_5 V_183 , int V_357 )
{
struct V_47 * V_48 = F_77 ( V_53 -> V_54 ) ;
struct V_350 * V_134 ;
struct V_177 * V_178 = V_53 -> V_188 ;
struct V_99 * V_100 ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_356 ] ,
. V_271 = V_53 -> V_188 -> V_243 ,
} ;
struct V_143 V_272 = {
. V_145 = V_48 -> V_81 ,
. V_140 = & V_141 ,
. V_146 = & V_358 ,
. V_274 = V_275 ,
. V_180 = V_276 ,
} ;
int V_263 = - V_253 ;
V_134 = F_78 ( sizeof( * V_134 ) , V_183 ) ;
if ( V_134 == NULL )
goto V_117;
F_49 ( & V_134 -> V_337 . V_138 , & V_134 -> V_34 . V_139 , 1 ) ;
V_134 -> V_54 = V_53 -> V_54 ;
V_134 -> V_53 = V_53 ;
V_134 -> V_337 . V_190 = F_83 ( V_53 -> V_54 ) ;
V_134 -> V_337 . V_216 = & V_53 -> V_233 ;
V_134 -> V_337 . V_169 = F_79 ( & V_53 -> V_188 -> V_185 , V_183 ) ;
if ( V_134 -> V_337 . V_169 == NULL )
goto V_359;
V_134 -> V_337 . V_179 = 0 ;
V_134 -> V_337 . V_206 = V_48 -> V_360 ;
V_134 -> V_34 . V_335 = & V_134 -> V_335 ;
V_134 -> V_34 . V_169 = V_134 -> V_337 . V_169 ;
V_134 -> V_34 . V_48 = V_48 ;
V_134 -> V_352 = F_204 ( V_53 -> V_54 ) ;
F_80 ( V_134 -> V_54 -> V_351 ) ;
V_141 . V_269 = & V_134 -> V_337 ;
V_141 . V_270 = & V_134 -> V_34 ;
V_272 . V_148 = V_134 ;
V_100 = F_61 ( & V_272 ) ;
if ( F_62 ( V_100 ) )
return F_63 ( V_100 ) ;
V_263 = 0 ;
if ( V_357 )
V_263 = F_98 ( V_100 ) ;
F_64 ( V_100 ) ;
return V_263 ;
V_359:
F_86 ( V_134 ) ;
V_117:
F_91 ( V_53 ) ;
F_92 ( V_178 ) ;
return V_263 ;
}
static struct V_54 *
F_205 ( struct V_54 * V_153 , struct V_258 * V_259 , int V_191 , struct V_181 * V_361 )
{
struct V_52 * V_53 ;
V_53 = F_188 ( V_153 , V_259 -> V_18 , V_259 -> V_220 , V_191 , V_361 ,
V_259 -> V_299 , & V_259 -> V_329 ) ;
if ( F_62 ( V_53 ) )
return F_206 ( V_53 ) ;
V_259 -> V_53 = V_53 ;
return F_207 ( V_53 -> V_54 ) ;
}
static void F_208 ( struct V_258 * V_259 , int V_362 )
{
if ( V_259 -> V_53 == NULL )
return;
if ( V_362 )
F_209 ( V_259 -> V_53 , V_259 -> V_220 ) ;
else
F_137 ( V_259 -> V_53 , V_259 -> V_220 ) ;
}
static int F_210 ( struct V_47 * V_48 , struct V_363 * V_364 )
{
struct V_365 args = {
. V_364 = V_364 ,
} ;
struct V_366 V_34 = {} ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_367 ] ,
. V_269 = & args ,
. V_270 = & V_34 ,
} ;
int V_263 ;
V_263 = F_68 ( V_48 -> V_81 , V_48 , & V_141 , & args . V_138 , & V_34 . V_139 , 0 ) ;
if ( V_263 == 0 ) {
memcpy ( V_48 -> V_207 , V_34 . V_207 , sizeof( V_48 -> V_207 ) ) ;
V_48 -> V_84 &= ~ ( V_368 | V_369 |
V_370 | V_371 |
V_372 | V_373 | V_374 |
V_375 | V_376 |
V_377 | V_378 ) ;
if ( V_34 . V_207 [ 0 ] & V_379 )
V_48 -> V_84 |= V_368 ;
if ( V_34 . V_380 != 0 )
V_48 -> V_84 |= V_369 ;
if ( V_34 . V_381 != 0 )
V_48 -> V_84 |= V_370 ;
if ( V_34 . V_207 [ 0 ] & V_27 )
V_48 -> V_84 |= V_371 ;
if ( V_34 . V_207 [ 1 ] & V_382 )
V_48 -> V_84 |= V_372 ;
if ( V_34 . V_207 [ 1 ] & V_383 )
V_48 -> V_84 |= V_373 ;
if ( V_34 . V_207 [ 1 ] & V_384 )
V_48 -> V_84 |= V_374 ;
if ( V_34 . V_207 [ 1 ] & V_385 )
V_48 -> V_84 |= V_375 ;
if ( V_34 . V_207 [ 1 ] & V_317 )
V_48 -> V_84 |= V_376 ;
if ( V_34 . V_207 [ 1 ] & V_386 )
V_48 -> V_84 |= V_377 ;
if ( V_34 . V_207 [ 1 ] & V_320 )
V_48 -> V_84 |= V_378 ;
memcpy ( V_48 -> V_360 , V_34 . V_207 , sizeof( V_48 -> V_360 ) ) ;
V_48 -> V_360 [ 0 ] &= V_387 | V_388 ;
V_48 -> V_360 [ 1 ] &= V_386 | V_320 ;
V_48 -> V_389 = V_34 . V_389 ;
V_48 -> V_390 = V_34 . V_390 ;
}
return V_263 ;
}
int F_211 ( struct V_47 * V_48 , struct V_363 * V_364 )
{
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_48 ,
F_210 ( V_48 , V_364 ) ,
& V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static int F_212 ( struct V_47 * V_48 , struct V_363 * V_364 ,
struct V_391 * V_392 )
{
struct V_393 args = {
. V_206 = V_209 ,
} ;
struct V_394 V_34 = {
. V_48 = V_48 ,
. V_335 = V_392 -> V_335 ,
. V_190 = V_364 ,
} ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_395 ] ,
. V_269 = & args ,
. V_270 = & V_34 ,
} ;
F_73 ( V_392 -> V_335 ) ;
return F_68 ( V_48 -> V_81 , V_48 , & V_141 , & args . V_138 , & V_34 . V_139 , 0 ) ;
}
static int F_213 ( struct V_47 * V_48 , struct V_363 * V_364 ,
struct V_391 * V_392 )
{
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_212 ( V_48 , V_364 , V_392 ) ;
switch ( V_1 ) {
case 0 :
case - V_4 :
goto V_117;
default:
V_1 = F_16 ( V_48 , V_1 , & V_51 ) ;
}
} while ( V_51 . V_56 );
V_117:
return V_1 ;
}
static int F_214 ( struct V_47 * V_48 , struct V_363 * V_364 ,
struct V_391 * V_392 , T_7 V_396 )
{
struct V_397 * V_398 ;
int V_55 ;
V_398 = F_215 ( V_396 , V_48 -> V_81 ) ;
if ( F_62 ( V_398 ) ) {
V_55 = - V_15 ;
goto V_117;
}
V_55 = F_213 ( V_48 , V_364 , V_392 ) ;
V_117:
return V_55 ;
}
static int F_216 ( struct V_47 * V_48 , struct V_363 * V_364 ,
struct V_391 * V_392 )
{
int V_399 , V_400 , V_263 = 0 ;
T_7 V_401 [ V_402 ] ;
V_400 = F_217 ( V_401 , F_218 ( V_401 ) ) ;
F_4 ( V_400 < 0 ) ;
for ( V_399 = 0 ; V_399 < V_400 ; V_399 ++ ) {
if ( V_401 [ V_399 ] == V_403 )
continue;
V_263 = F_214 ( V_48 , V_364 , V_392 , V_401 [ V_399 ] ) ;
if ( V_263 == - V_4 || V_263 == - V_10 )
continue;
break;
}
if ( V_263 == - V_10 )
V_263 = - V_5 ;
return V_263 ;
}
int F_219 ( struct V_47 * V_48 , struct V_363 * V_364 ,
struct V_391 * V_392 )
{
int V_404 = V_48 -> V_32 -> V_405 ;
int V_263 = F_213 ( V_48 , V_364 , V_392 ) ;
if ( ( V_263 == - V_4 ) && ! ( V_48 -> V_180 & V_406 ) )
V_263 = V_407 [ V_404 ] -> F_220 ( V_48 , V_364 , V_392 ) ;
if ( V_263 == 0 )
V_263 = F_211 ( V_48 , V_364 ) ;
if ( V_263 == 0 )
V_263 = F_221 ( V_48 , V_364 , V_392 ) ;
return F_1 ( V_263 ) ;
}
static int F_222 ( struct V_47 * V_48 , struct V_363 * V_408 ,
struct V_391 * V_392 )
{
int error ;
struct V_334 * V_335 = V_392 -> V_335 ;
error = F_211 ( V_48 , V_408 ) ;
if ( error < 0 ) {
F_2 ( L_33 , - error ) ;
return error ;
}
error = F_223 ( V_48 , V_408 , V_335 ) ;
if ( error < 0 ) {
F_2 ( L_34 , - error ) ;
return error ;
}
if ( V_335 -> V_249 & V_409 &&
! F_224 ( & V_48 -> V_410 , & V_335 -> V_410 ) )
memcpy ( & V_48 -> V_410 , & V_335 -> V_410 , sizeof( V_48 -> V_410 ) ) ;
return error ;
}
static int F_225 ( struct V_40 * V_81 , struct V_54 * V_153 ,
const struct V_411 * V_204 , struct V_334 * V_335 ,
struct V_363 * V_364 )
{
int V_263 = - V_253 ;
struct V_412 * V_412 = NULL ;
struct V_413 * V_414 = NULL ;
V_412 = F_226 ( V_325 ) ;
if ( V_412 == NULL )
goto V_117;
V_414 = F_227 ( sizeof( struct V_413 ) , V_325 ) ;
if ( V_414 == NULL )
goto V_117;
V_263 = F_228 ( V_81 , V_153 , V_204 , V_414 , V_412 ) ;
if ( V_263 != 0 )
goto V_117;
if ( F_224 ( & F_77 ( V_153 ) -> V_410 , & V_414 -> V_335 . V_410 ) ) {
F_2 ( L_35
L_36 , V_14 , V_204 -> V_204 ) ;
V_263 = - V_15 ;
goto V_117;
}
F_229 ( & V_414 -> V_335 ) ;
memcpy ( V_335 , & V_414 -> V_335 , sizeof( struct V_334 ) ) ;
memset ( V_364 , 0 , sizeof( struct V_363 ) ) ;
V_117:
if ( V_412 )
F_230 ( V_412 ) ;
F_86 ( V_414 ) ;
return V_263 ;
}
static int F_167 ( struct V_47 * V_48 , struct V_363 * V_364 , struct V_334 * V_335 )
{
struct V_415 args = {
. V_190 = V_364 ,
. V_206 = V_48 -> V_207 ,
} ;
struct V_416 V_34 = {
. V_335 = V_335 ,
. V_48 = V_48 ,
} ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_417 ] ,
. V_269 = & args ,
. V_270 = & V_34 ,
} ;
F_73 ( V_335 ) ;
return F_68 ( V_48 -> V_81 , V_48 , & V_141 , & args . V_138 , & V_34 . V_139 , 0 ) ;
}
static int F_223 ( struct V_47 * V_48 , struct V_363 * V_364 , struct V_334 * V_335 )
{
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_48 ,
F_167 ( V_48 , V_364 , V_335 ) ,
& V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static int
F_231 ( struct V_18 * V_18 , struct V_334 * V_335 ,
struct V_181 * V_315 )
{
struct V_54 * V_54 = V_18 -> V_28 ;
struct V_271 * V_299 = NULL ;
struct V_52 * V_53 = NULL ;
int V_263 ;
if ( F_232 ( V_54 ) )
F_233 ( V_54 ) ;
F_73 ( V_335 ) ;
if ( V_315 -> V_212 & V_349 )
V_315 -> V_212 &= ~ ( V_322 | V_418 | V_349 ) ;
if ( ( V_315 -> V_212 & ~ ( V_419 ) ) == 0 )
return 0 ;
if ( V_315 -> V_212 & V_419 ) {
struct V_258 * V_259 ;
V_259 = F_234 ( V_315 -> V_420 ) ;
if ( V_259 ) {
V_299 = V_259 -> V_299 ;
V_53 = V_259 -> V_53 ;
}
}
V_263 = F_184 ( V_54 , V_299 , V_335 , V_315 , V_53 ) ;
if ( V_263 == 0 )
F_185 ( V_54 , V_315 ) ;
return V_263 ;
}
static int F_235 ( struct V_40 * V_41 , struct V_54 * V_153 ,
const struct V_411 * V_204 , struct V_363 * V_364 ,
struct V_334 * V_335 )
{
struct V_47 * V_48 = F_77 ( V_153 ) ;
int V_263 ;
struct V_421 args = {
. V_206 = V_48 -> V_207 ,
. V_422 = F_83 ( V_153 ) ,
. V_204 = V_204 ,
} ;
struct V_394 V_34 = {
. V_48 = V_48 ,
. V_335 = V_335 ,
. V_190 = V_364 ,
} ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_423 ] ,
. V_269 = & args ,
. V_270 = & V_34 ,
} ;
F_73 ( V_335 ) ;
F_2 ( L_37 , V_204 -> V_204 ) ;
V_263 = F_68 ( V_41 , V_48 , & V_141 , & args . V_138 , & V_34 . V_139 , 0 ) ;
F_2 ( L_38 , V_263 ) ;
return V_263 ;
}
static void F_236 ( struct V_334 * V_335 )
{
V_335 -> V_249 |= V_250 | V_424 |
V_425 | V_426 ;
V_335 -> V_220 = V_288 | V_427 | V_428 ;
V_335 -> V_429 = 2 ;
}
static int F_237 ( struct V_40 * * V_41 , struct V_54 * V_153 ,
struct V_411 * V_204 , struct V_363 * V_364 ,
struct V_334 * V_335 )
{
struct V_50 V_51 = { } ;
struct V_40 * V_81 = * V_41 ;
int V_1 ;
do {
V_1 = F_235 ( V_81 , V_153 , V_204 , V_364 , V_335 ) ;
switch ( V_1 ) {
case - V_7 :
V_1 = - V_260 ;
goto V_117;
case - V_430 :
V_1 = F_225 ( V_81 , V_153 , V_204 , V_335 , V_364 ) ;
goto V_117;
case - V_4 :
V_1 = - V_5 ;
if ( V_81 != * V_41 )
goto V_117;
V_81 = F_238 ( V_81 , V_153 , V_204 ) ;
if ( F_62 ( V_81 ) )
return F_63 ( V_81 ) ;
V_51 . V_56 = 1 ;
break;
default:
V_1 = F_16 ( F_77 ( V_153 ) , V_1 , & V_51 ) ;
}
} while ( V_51 . V_56 );
V_117:
if ( V_1 == 0 )
* V_41 = V_81 ;
else if ( V_81 != * V_41 )
F_239 ( V_81 ) ;
return V_1 ;
}
static int F_240 ( struct V_54 * V_153 , struct V_411 * V_204 ,
struct V_363 * V_364 , struct V_334 * V_335 )
{
int V_263 ;
struct V_40 * V_81 = F_241 ( V_153 ) ;
V_263 = F_237 ( & V_81 , V_153 , V_204 , V_364 , V_335 ) ;
if ( V_81 != F_241 ( V_153 ) ) {
F_239 ( V_81 ) ;
F_236 ( V_335 ) ;
}
return V_263 ;
}
struct V_40 *
F_242 ( struct V_54 * V_153 , struct V_411 * V_204 ,
struct V_363 * V_364 , struct V_334 * V_335 )
{
int V_263 ;
struct V_40 * V_81 = F_243 ( F_241 ( V_153 ) ) ;
V_263 = F_237 ( & V_81 , V_153 , V_204 , V_364 , V_335 ) ;
if ( V_263 < 0 ) {
F_239 ( V_81 ) ;
return F_119 ( V_263 ) ;
}
return V_81 ;
}
static int F_244 ( struct V_54 * V_54 , struct V_300 * V_431 )
{
struct V_47 * V_48 = F_77 ( V_54 ) ;
struct V_432 args = {
. V_190 = F_83 ( V_54 ) ,
. V_206 = V_48 -> V_360 ,
} ;
struct V_433 V_34 = {
. V_48 = V_48 ,
} ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_434 ] ,
. V_269 = & args ,
. V_270 = & V_34 ,
. V_271 = V_431 -> V_299 ,
} ;
int V_220 = V_431 -> V_302 ;
int V_263 ;
if ( V_220 & V_304 )
args . V_174 |= V_194 ;
if ( F_245 ( V_54 -> V_435 ) ) {
if ( V_220 & V_436 )
args . V_174 |= V_195 | V_196 | V_437 ;
if ( V_220 & V_306 )
args . V_174 |= V_438 ;
} else {
if ( V_220 & V_436 )
args . V_174 |= V_195 | V_196 ;
if ( V_220 & V_306 )
args . V_174 |= V_197 ;
}
V_34 . V_335 = F_246 () ;
if ( V_34 . V_335 == NULL )
return - V_253 ;
V_263 = F_68 ( V_48 -> V_81 , V_48 , & V_141 , & args . V_138 , & V_34 . V_139 , 0 ) ;
if ( ! V_263 ) {
F_164 ( V_431 , V_34 . V_174 ) ;
F_126 ( V_54 , V_34 . V_335 ) ;
}
F_247 ( V_34 . V_335 ) ;
return V_263 ;
}
static int F_248 ( struct V_54 * V_54 , struct V_300 * V_431 )
{
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_54 ) ,
F_244 ( V_54 , V_431 ) ,
& V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static int F_249 ( struct V_54 * V_54 , struct V_412 * V_412 ,
unsigned int V_31 , unsigned int V_439 )
{
struct V_440 args = {
. V_190 = F_83 ( V_54 ) ,
. V_31 = V_31 ,
. V_439 = V_439 ,
. V_24 = & V_412 ,
} ;
struct V_441 V_34 ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_442 ] ,
. V_269 = & args ,
. V_270 = & V_34 ,
} ;
return F_68 ( F_77 ( V_54 ) -> V_81 , F_77 ( V_54 ) , & V_141 , & args . V_138 , & V_34 . V_139 , 0 ) ;
}
static int F_250 ( struct V_54 * V_54 , struct V_412 * V_412 ,
unsigned int V_31 , unsigned int V_439 )
{
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_54 ) ,
F_249 ( V_54 , V_412 , V_31 , V_439 ) ,
& V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static int
F_251 ( struct V_54 * V_153 , struct V_18 * V_18 , struct V_181 * V_315 ,
int V_180 )
{
struct V_258 * V_259 ;
struct V_52 * V_53 ;
int V_263 = 0 ;
V_259 = F_252 ( V_18 , V_58 ) ;
if ( F_62 ( V_259 ) )
return F_63 ( V_259 ) ;
V_315 -> V_443 &= ~ F_253 () ;
V_53 = F_188 ( V_153 , V_18 , V_259 -> V_220 ,
V_180 , V_315 , V_259 -> V_299 ,
& V_259 -> V_329 ) ;
F_172 ( V_18 ) ;
if ( F_62 ( V_53 ) ) {
V_263 = F_63 ( V_53 ) ;
goto V_117;
}
F_254 ( V_18 , F_207 ( V_53 -> V_54 ) ) ;
F_255 ( V_18 , F_256 ( V_153 ) ) ;
V_259 -> V_53 = V_53 ;
V_117:
F_144 ( V_259 ) ;
return V_263 ;
}
static int F_257 ( struct V_54 * V_153 , struct V_411 * V_204 )
{
struct V_47 * V_48 = F_77 ( V_153 ) ;
struct V_444 args = {
. V_190 = F_83 ( V_153 ) ,
. V_204 = * V_204 ,
} ;
struct V_445 V_34 = {
. V_48 = V_48 ,
} ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_446 ] ,
. V_269 = & args ,
. V_270 = & V_34 ,
} ;
int V_263 ;
V_263 = F_68 ( V_48 -> V_81 , V_48 , & V_141 , & args . V_138 , & V_34 . V_139 , 1 ) ;
if ( V_263 == 0 )
F_69 ( V_153 , & V_34 . V_155 ) ;
return V_263 ;
}
static int F_258 ( struct V_54 * V_153 , struct V_411 * V_204 )
{
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_153 ) ,
F_257 ( V_153 , V_204 ) ,
& V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static void F_259 ( struct V_140 * V_141 , struct V_54 * V_153 )
{
struct V_47 * V_48 = F_77 ( V_153 ) ;
struct V_444 * args = V_141 -> V_269 ;
struct V_445 * V_34 = V_141 -> V_270 ;
V_34 -> V_48 = V_48 ;
V_141 -> V_266 = & V_267 [ V_446 ] ;
F_49 ( & args -> V_138 , & V_34 -> V_139 , 1 ) ;
}
static void F_260 ( struct V_99 * V_100 , struct V_447 * V_136 )
{
if ( F_54 ( F_77 ( V_136 -> V_153 ) ,
& V_136 -> args . V_138 ,
& V_136 -> V_34 . V_139 ,
V_100 ) )
return;
F_57 ( V_100 ) ;
}
static int F_261 ( struct V_99 * V_100 , struct V_54 * V_153 )
{
struct V_445 * V_34 = V_100 -> V_280 . V_270 ;
if ( ! F_45 ( V_100 , & V_34 -> V_139 ) )
return 0 ;
if ( F_199 ( V_100 , V_34 -> V_48 , NULL ) == - V_130 )
return 0 ;
F_69 ( V_153 , & V_34 -> V_155 ) ;
return 1 ;
}
static void F_262 ( struct V_140 * V_141 , struct V_54 * V_153 )
{
struct V_47 * V_48 = F_77 ( V_153 ) ;
struct V_448 * V_337 = V_141 -> V_269 ;
struct V_449 * V_34 = V_141 -> V_270 ;
V_141 -> V_266 = & V_267 [ V_450 ] ;
V_34 -> V_48 = V_48 ;
F_49 ( & V_337 -> V_138 , & V_34 -> V_139 , 1 ) ;
}
static void F_263 ( struct V_99 * V_100 , struct V_451 * V_136 )
{
if ( F_54 ( F_77 ( V_136 -> V_452 ) ,
& V_136 -> args . V_138 ,
& V_136 -> V_34 . V_139 ,
V_100 ) )
return;
F_57 ( V_100 ) ;
}
static int F_264 ( struct V_99 * V_100 , struct V_54 * V_452 ,
struct V_54 * V_453 )
{
struct V_449 * V_34 = V_100 -> V_280 . V_270 ;
if ( ! F_45 ( V_100 , & V_34 -> V_139 ) )
return 0 ;
if ( F_199 ( V_100 , V_34 -> V_48 , NULL ) == - V_130 )
return 0 ;
F_69 ( V_452 , & V_34 -> V_454 ) ;
F_69 ( V_453 , & V_34 -> V_455 ) ;
return 1 ;
}
static int F_265 ( struct V_54 * V_452 , struct V_411 * V_456 ,
struct V_54 * V_453 , struct V_411 * V_457 )
{
struct V_47 * V_48 = F_77 ( V_452 ) ;
struct V_448 V_337 = {
. V_452 = F_83 ( V_452 ) ,
. V_453 = F_83 ( V_453 ) ,
. V_456 = V_456 ,
. V_457 = V_457 ,
} ;
struct V_449 V_34 = {
. V_48 = V_48 ,
} ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_450 ] ,
. V_269 = & V_337 ,
. V_270 = & V_34 ,
} ;
int V_263 = - V_253 ;
V_263 = F_68 ( V_48 -> V_81 , V_48 , & V_141 , & V_337 . V_138 , & V_34 . V_139 , 1 ) ;
if ( ! V_263 ) {
F_69 ( V_452 , & V_34 . V_454 ) ;
F_69 ( V_453 , & V_34 . V_455 ) ;
}
return V_263 ;
}
static int F_266 ( struct V_54 * V_452 , struct V_411 * V_456 ,
struct V_54 * V_453 , struct V_411 * V_457 )
{
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_452 ) ,
F_265 ( V_452 , V_456 ,
V_453 , V_457 ) ,
& V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static int F_267 ( struct V_54 * V_54 , struct V_54 * V_153 , struct V_411 * V_204 )
{
struct V_47 * V_48 = F_77 ( V_54 ) ;
struct V_458 V_337 = {
. V_190 = F_83 ( V_54 ) ,
. V_422 = F_83 ( V_153 ) ,
. V_204 = V_204 ,
. V_206 = V_48 -> V_207 ,
} ;
struct V_459 V_34 = {
. V_48 = V_48 ,
} ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_460 ] ,
. V_269 = & V_337 ,
. V_270 = & V_34 ,
} ;
int V_263 = - V_253 ;
V_34 . V_335 = F_246 () ;
if ( V_34 . V_335 == NULL )
goto V_117;
V_263 = F_68 ( V_48 -> V_81 , V_48 , & V_141 , & V_337 . V_138 , & V_34 . V_139 , 1 ) ;
if ( ! V_263 ) {
F_69 ( V_153 , & V_34 . V_155 ) ;
F_186 ( V_54 , V_34 . V_335 ) ;
}
V_117:
F_247 ( V_34 . V_335 ) ;
return V_263 ;
}
static int F_268 ( struct V_54 * V_54 , struct V_54 * V_153 , struct V_411 * V_204 )
{
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_54 ) ,
F_267 ( V_54 , V_153 , V_204 ) ,
& V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static struct V_461 * F_269 ( struct V_54 * V_153 ,
struct V_411 * V_204 , struct V_181 * V_315 , T_3 V_462 )
{
struct V_461 * V_136 ;
V_136 = F_78 ( sizeof( * V_136 ) , V_325 ) ;
if ( V_136 != NULL ) {
struct V_47 * V_48 = F_77 ( V_153 ) ;
V_136 -> V_141 . V_266 = & V_267 [ V_463 ] ;
V_136 -> V_141 . V_269 = & V_136 -> V_337 ;
V_136 -> V_141 . V_270 = & V_136 -> V_34 ;
V_136 -> V_337 . V_422 = F_83 ( V_153 ) ;
V_136 -> V_337 . V_48 = V_48 ;
V_136 -> V_337 . V_204 = V_204 ;
V_136 -> V_337 . V_182 = V_315 ;
V_136 -> V_337 . V_462 = V_462 ;
V_136 -> V_337 . V_206 = V_48 -> V_207 ;
V_136 -> V_34 . V_48 = V_48 ;
V_136 -> V_34 . V_190 = & V_136 -> V_190 ;
V_136 -> V_34 . V_335 = & V_136 -> V_335 ;
F_73 ( V_136 -> V_34 . V_335 ) ;
}
return V_136 ;
}
static int F_270 ( struct V_54 * V_153 , struct V_18 * V_18 , struct V_461 * V_136 )
{
int V_263 = F_68 ( F_77 ( V_153 ) -> V_81 , F_77 ( V_153 ) , & V_136 -> V_141 ,
& V_136 -> V_337 . V_138 , & V_136 -> V_34 . V_139 , 1 ) ;
if ( V_263 == 0 ) {
F_69 ( V_153 , & V_136 -> V_34 . V_464 ) ;
V_263 = F_271 ( V_18 , V_136 -> V_34 . V_190 , V_136 -> V_34 . V_335 ) ;
}
return V_263 ;
}
static void F_272 ( struct V_461 * V_136 )
{
F_86 ( V_136 ) ;
}
static int F_273 ( struct V_54 * V_153 , struct V_18 * V_18 ,
struct V_412 * V_412 , unsigned int V_400 , struct V_181 * V_315 )
{
struct V_461 * V_136 ;
int V_263 = - V_465 ;
if ( V_400 > V_466 )
goto V_117;
V_263 = - V_253 ;
V_136 = F_269 ( V_153 , & V_18 -> V_205 , V_315 , V_467 ) ;
if ( V_136 == NULL )
goto V_117;
V_136 -> V_141 . V_266 = & V_267 [ V_468 ] ;
V_136 -> V_337 . V_214 . V_469 . V_24 = & V_412 ;
V_136 -> V_337 . V_214 . V_469 . V_400 = V_400 ;
V_263 = F_270 ( V_153 , V_18 , V_136 ) ;
F_272 ( V_136 ) ;
V_117:
return V_263 ;
}
static int F_274 ( struct V_54 * V_153 , struct V_18 * V_18 ,
struct V_412 * V_412 , unsigned int V_400 , struct V_181 * V_315 )
{
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_153 ) ,
F_273 ( V_153 , V_18 , V_412 ,
V_400 , V_315 ) ,
& V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static int F_275 ( struct V_54 * V_153 , struct V_18 * V_18 ,
struct V_181 * V_315 )
{
struct V_461 * V_136 ;
int V_263 = - V_253 ;
V_136 = F_269 ( V_153 , & V_18 -> V_205 , V_315 , V_470 ) ;
if ( V_136 == NULL )
goto V_117;
V_263 = F_270 ( V_153 , V_18 , V_136 ) ;
F_272 ( V_136 ) ;
V_117:
return V_263 ;
}
static int F_276 ( struct V_54 * V_153 , struct V_18 * V_18 ,
struct V_181 * V_315 )
{
struct V_50 V_51 = { } ;
int V_1 ;
V_315 -> V_443 &= ~ F_253 () ;
do {
V_1 = F_16 ( F_77 ( V_153 ) ,
F_275 ( V_153 , V_18 , V_315 ) ,
& V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static int F_277 ( struct V_18 * V_18 , struct V_271 * V_299 ,
T_1 V_16 , struct V_412 * * V_24 , unsigned int V_23 , int V_471 )
{
struct V_54 * V_153 = V_18 -> V_28 ;
struct V_19 args = {
. V_190 = F_83 ( V_153 ) ,
. V_24 = V_24 ,
. V_31 = 0 ,
. V_23 = V_23 ,
. V_206 = F_77 ( V_18 -> V_28 ) -> V_207 ,
. V_471 = V_471 ,
} ;
struct V_472 V_34 ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_473 ] ,
. V_269 = & args ,
. V_270 = & V_34 ,
. V_271 = V_299 ,
} ;
int V_263 ;
F_2 ( L_39 , V_14 ,
V_18 -> V_30 -> V_205 . V_204 ,
V_18 -> V_205 . V_204 ,
( unsigned long long ) V_16 ) ;
F_3 ( V_16 , F_70 ( V_153 ) -> V_474 , V_18 , & args ) ;
V_34 . V_31 = args . V_31 ;
V_263 = F_68 ( F_77 ( V_153 ) -> V_81 , F_77 ( V_153 ) , & V_141 , & args . V_138 , & V_34 . V_139 , 0 ) ;
if ( V_263 >= 0 ) {
memcpy ( F_70 ( V_153 ) -> V_474 , V_34 . V_17 . V_136 , V_475 ) ;
V_263 += args . V_31 ;
}
F_278 ( V_153 ) ;
F_2 ( L_40 , V_14 , V_263 ) ;
return V_263 ;
}
static int F_279 ( struct V_18 * V_18 , struct V_271 * V_299 ,
T_1 V_16 , struct V_412 * * V_24 , unsigned int V_23 , int V_471 )
{
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_18 -> V_28 ) ,
F_277 ( V_18 , V_299 , V_16 ,
V_24 , V_23 , V_471 ) ,
& V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static int F_280 ( struct V_54 * V_153 , struct V_18 * V_18 ,
struct V_181 * V_315 , T_8 V_476 )
{
struct V_461 * V_136 ;
int V_220 = V_315 -> V_443 ;
int V_263 = - V_253 ;
F_4 ( ! ( V_315 -> V_212 & V_477 ) ) ;
F_4 ( ! F_281 ( V_220 ) && ! F_282 ( V_220 ) && ! F_283 ( V_220 ) && ! F_284 ( V_220 ) ) ;
V_136 = F_269 ( V_153 , & V_18 -> V_205 , V_315 , V_478 ) ;
if ( V_136 == NULL )
goto V_117;
if ( F_281 ( V_220 ) )
V_136 -> V_337 . V_462 = V_479 ;
else if ( F_282 ( V_220 ) ) {
V_136 -> V_337 . V_462 = V_480 ;
V_136 -> V_337 . V_214 . V_481 . V_482 = F_285 ( V_476 ) ;
V_136 -> V_337 . V_214 . V_481 . V_483 = F_286 ( V_476 ) ;
}
else if ( F_283 ( V_220 ) ) {
V_136 -> V_337 . V_462 = V_484 ;
V_136 -> V_337 . V_214 . V_481 . V_482 = F_285 ( V_476 ) ;
V_136 -> V_337 . V_214 . V_481 . V_483 = F_286 ( V_476 ) ;
}
V_263 = F_270 ( V_153 , V_18 , V_136 ) ;
F_272 ( V_136 ) ;
V_117:
return V_263 ;
}
static int F_287 ( struct V_54 * V_153 , struct V_18 * V_18 ,
struct V_181 * V_315 , T_8 V_476 )
{
struct V_50 V_51 = { } ;
int V_1 ;
V_315 -> V_443 &= ~ F_253 () ;
do {
V_1 = F_16 ( F_77 ( V_153 ) ,
F_280 ( V_153 , V_18 , V_315 , V_476 ) ,
& V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static int F_288 ( struct V_47 * V_48 , struct V_363 * V_364 ,
struct V_485 * V_486 )
{
struct V_487 args = {
. V_190 = V_364 ,
. V_206 = V_48 -> V_207 ,
} ;
struct V_488 V_34 = {
. V_486 = V_486 ,
} ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_489 ] ,
. V_269 = & args ,
. V_270 = & V_34 ,
} ;
F_73 ( V_486 -> V_335 ) ;
return F_68 ( V_48 -> V_81 , V_48 , & V_141 , & args . V_138 , & V_34 . V_139 , 0 ) ;
}
static int F_289 ( struct V_47 * V_48 , struct V_363 * V_364 , struct V_485 * V_486 )
{
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_48 ,
F_288 ( V_48 , V_364 , V_486 ) ,
& V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static int F_290 ( struct V_47 * V_48 , struct V_363 * V_364 ,
struct V_391 * V_490 )
{
struct V_491 args = {
. V_190 = V_364 ,
. V_206 = V_48 -> V_207 ,
} ;
struct V_492 V_34 = {
. V_490 = V_490 ,
} ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_493 ] ,
. V_269 = & args ,
. V_270 = & V_34 ,
} ;
return F_68 ( V_48 -> V_81 , V_48 , & V_141 , & args . V_138 , & V_34 . V_139 , 0 ) ;
}
static int F_221 ( struct V_47 * V_48 , struct V_363 * V_364 , struct V_391 * V_490 )
{
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_48 ,
F_290 ( V_48 , V_364 , V_490 ) ,
& V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static int F_291 ( struct V_47 * V_48 , struct V_363 * V_364 , struct V_391 * V_490 )
{
int error ;
F_73 ( V_490 -> V_335 ) ;
error = F_221 ( V_48 , V_364 , V_490 ) ;
if ( error == 0 ) {
V_48 -> V_494 = V_490 -> V_495 ;
F_292 ( V_48 , V_364 , V_490 -> V_496 ) ;
}
return error ;
}
static int F_293 ( struct V_47 * V_48 , struct V_363 * V_364 ,
struct V_497 * V_498 )
{
struct V_499 args = {
. V_190 = V_364 ,
. V_206 = V_48 -> V_207 ,
} ;
struct V_500 V_34 = {
. V_498 = V_498 ,
} ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_501 ] ,
. V_269 = & args ,
. V_270 = & V_34 ,
} ;
if ( ( args . V_206 [ 0 ] & V_502 [ 0 ] ) == 0 ) {
memset ( V_498 , 0 , sizeof( * V_498 ) ) ;
return 0 ;
}
F_73 ( V_498 -> V_335 ) ;
return F_68 ( V_48 -> V_81 , V_48 , & V_141 , & args . V_138 , & V_34 . V_139 , 0 ) ;
}
static int F_294 ( struct V_47 * V_48 , struct V_363 * V_364 ,
struct V_497 * V_498 )
{
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_48 ,
F_293 ( V_48 , V_364 , V_498 ) ,
& V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
void F_295 ( struct V_503 * V_136 )
{
F_278 ( V_136 -> V_504 -> V_54 ) ;
}
static int F_296 ( struct V_99 * V_100 , struct V_503 * V_136 )
{
struct V_47 * V_48 = F_77 ( V_136 -> V_504 -> V_54 ) ;
if ( F_199 ( V_100 , V_48 , V_136 -> args . V_505 -> V_53 ) == - V_130 ) {
F_200 ( V_100 ) ;
return - V_130 ;
}
F_295 ( V_136 ) ;
if ( V_100 -> V_150 > 0 )
F_29 ( V_48 , V_136 -> V_88 ) ;
return 0 ;
}
static int F_297 ( struct V_99 * V_100 , struct V_503 * V_136 )
{
F_2 ( L_17 , V_14 ) ;
if ( ! F_45 ( V_100 , & V_136 -> V_34 . V_139 ) )
return - V_130 ;
return V_136 -> V_506 ? V_136 -> V_506 ( V_100 , V_136 ) :
F_296 ( V_100 , V_136 ) ;
}
static void F_298 ( struct V_503 * V_136 , struct V_140 * V_141 )
{
V_136 -> V_88 = V_133 ;
V_136 -> V_506 = F_296 ;
V_141 -> V_266 = & V_267 [ V_507 ] ;
F_49 ( & V_136 -> args . V_138 , & V_136 -> V_34 . V_139 , 0 ) ;
}
static void F_299 ( struct V_99 * V_100 , struct V_503 * V_136 )
{
if ( F_54 ( F_77 ( V_136 -> V_504 -> V_54 ) ,
& V_136 -> args . V_138 ,
& V_136 -> V_34 . V_139 ,
V_100 ) )
return;
F_57 ( V_100 ) ;
}
static int F_300 ( struct V_99 * V_100 , struct V_508 * V_136 )
{
struct V_54 * V_54 = V_136 -> V_504 -> V_54 ;
if ( F_199 ( V_100 , F_77 ( V_54 ) , V_136 -> args . V_505 -> V_53 ) == - V_130 ) {
F_200 ( V_100 ) ;
return - V_130 ;
}
if ( V_100 -> V_150 >= 0 ) {
F_29 ( F_77 ( V_54 ) , V_136 -> V_88 ) ;
F_301 ( V_54 , & V_136 -> V_335 ) ;
}
return 0 ;
}
static int F_302 ( struct V_99 * V_100 , struct V_508 * V_136 )
{
if ( ! F_45 ( V_100 , & V_136 -> V_34 . V_139 ) )
return - V_130 ;
return V_136 -> V_509 ? V_136 -> V_509 ( V_100 , V_136 ) :
F_300 ( V_100 , V_136 ) ;
}
static
bool F_303 ( const struct V_508 * V_136 )
{
const struct V_510 * V_511 = V_136 -> V_504 ;
if ( V_136 -> V_512 != NULL || V_511 -> V_513 != NULL )
return false ;
return F_17 ( V_511 -> V_54 , V_58 ) == 0 ;
}
static void F_304 ( struct V_508 * V_136 , struct V_140 * V_141 )
{
struct V_47 * V_48 = F_77 ( V_136 -> V_504 -> V_54 ) ;
if ( ! F_303 ( V_136 ) ) {
V_136 -> args . V_206 = NULL ;
V_136 -> V_34 . V_335 = NULL ;
} else
V_136 -> args . V_206 = V_48 -> V_360 ;
if ( ! V_136 -> V_509 )
V_136 -> V_509 = F_300 ;
V_136 -> V_34 . V_48 = V_48 ;
V_136 -> V_88 = V_133 ;
V_141 -> V_266 = & V_267 [ V_514 ] ;
F_49 ( & V_136 -> args . V_138 , & V_136 -> V_34 . V_139 , 1 ) ;
}
static void F_305 ( struct V_99 * V_100 , struct V_508 * V_136 )
{
if ( F_54 ( F_77 ( V_136 -> V_504 -> V_54 ) ,
& V_136 -> args . V_138 ,
& V_136 -> V_34 . V_139 ,
V_100 ) )
return;
F_57 ( V_100 ) ;
}
static void F_306 ( struct V_99 * V_100 , struct V_515 * V_136 )
{
if ( F_54 ( F_77 ( V_136 -> V_54 ) ,
& V_136 -> args . V_138 ,
& V_136 -> V_34 . V_139 ,
V_100 ) )
return;
F_57 ( V_100 ) ;
}
static int F_307 ( struct V_99 * V_100 , struct V_515 * V_136 )
{
struct V_54 * V_54 = V_136 -> V_54 ;
if ( F_199 ( V_100 , F_77 ( V_54 ) , NULL ) == - V_130 ) {
F_200 ( V_100 ) ;
return - V_130 ;
}
return 0 ;
}
static int F_308 ( struct V_99 * V_100 , struct V_515 * V_136 )
{
if ( ! F_45 ( V_100 , & V_136 -> V_34 . V_139 ) )
return - V_130 ;
return V_136 -> V_516 ( V_100 , V_136 ) ;
}
static void F_309 ( struct V_515 * V_136 , struct V_140 * V_141 )
{
struct V_47 * V_48 = F_77 ( V_136 -> V_54 ) ;
if ( V_136 -> V_516 == NULL )
V_136 -> V_516 = F_307 ;
V_136 -> V_34 . V_48 = V_48 ;
V_141 -> V_266 = & V_267 [ V_517 ] ;
F_49 ( & V_136 -> args . V_138 , & V_136 -> V_34 . V_139 , 1 ) ;
}
static void F_310 ( void * V_134 )
{
struct V_518 * V_136 = V_134 ;
struct V_32 * V_33 = V_136 -> V_81 ;
if ( F_311 ( & V_33 -> V_519 ) > 1 )
F_312 ( V_33 ) ;
F_313 ( V_33 ) ;
F_86 ( V_136 ) ;
}
static void F_314 ( struct V_99 * V_100 , void * V_134 )
{
struct V_518 * V_136 = V_134 ;
struct V_32 * V_33 = V_136 -> V_81 ;
unsigned long V_88 = V_136 -> V_88 ;
if ( V_100 -> V_150 < 0 ) {
if ( F_36 ( V_520 , & V_33 -> V_521 ) == 0 )
return;
if ( V_100 -> V_150 != V_522 ) {
F_21 ( V_33 ) ;
return;
}
F_315 ( V_33 ) ;
}
F_25 ( V_33 , V_88 ) ;
}
static int F_316 ( struct V_32 * V_33 , struct V_271 * V_299 , unsigned V_523 )
{
struct V_140 V_141 = {
. V_266 = & V_267 [ V_524 ] ,
. V_269 = V_33 ,
. V_271 = V_299 ,
} ;
struct V_518 * V_136 ;
if ( V_523 == 0 )
return 0 ;
if ( ! F_317 ( & V_33 -> V_519 ) )
return - V_15 ;
V_136 = F_227 ( sizeof( * V_136 ) , V_261 ) ;
if ( V_136 == NULL )
return - V_253 ;
V_136 -> V_81 = V_33 ;
V_136 -> V_88 = V_133 ;
return F_318 ( V_33 -> V_525 , & V_141 , V_526 ,
& V_527 , V_136 ) ;
}
static int F_319 ( struct V_32 * V_33 , struct V_271 * V_299 )
{
struct V_140 V_141 = {
. V_266 = & V_267 [ V_524 ] ,
. V_269 = V_33 ,
. V_271 = V_299 ,
} ;
unsigned long V_528 = V_133 ;
int V_263 ;
V_263 = F_67 ( V_33 -> V_525 , & V_141 , 0 ) ;
if ( V_263 < 0 )
return V_263 ;
F_25 ( V_33 , V_528 ) ;
return 0 ;
}
static inline int F_320 ( struct V_47 * V_48 )
{
return ( V_48 -> V_84 & V_368 )
&& ( V_48 -> V_389 & V_529 )
&& ( V_48 -> V_389 & V_530 ) ;
}
static int F_321 ( const void * V_531 , T_9 V_532 ,
struct V_412 * * V_24 , unsigned int * V_31 )
{
struct V_412 * V_533 , * * V_534 ;
int V_535 = 0 ;
T_9 V_400 ;
V_534 = V_24 ;
do {
V_400 = F_322 ( T_9 , V_536 , V_532 ) ;
V_533 = F_226 ( V_325 ) ;
if ( V_533 == NULL )
goto V_537;
memcpy ( F_323 ( V_533 ) , V_531 , V_400 ) ;
V_531 += V_400 ;
V_532 -= V_400 ;
* V_24 ++ = V_533 ;
V_535 ++ ;
} while ( V_532 != 0 );
return V_535 ;
V_537:
for(; V_535 > 0 ; V_535 -- )
F_230 ( V_534 [ V_535 - 1 ] ) ;
return - V_253 ;
}
static void F_324 ( struct V_54 * V_54 , struct V_538 * V_539 )
{
struct V_156 * V_157 = F_70 ( V_54 ) ;
F_26 ( & V_54 -> V_158 ) ;
F_86 ( V_157 -> V_540 ) ;
V_157 -> V_540 = V_539 ;
F_28 ( & V_54 -> V_158 ) ;
}
static void F_325 ( struct V_54 * V_54 )
{
F_324 ( V_54 , NULL ) ;
}
static inline T_10 F_326 ( struct V_54 * V_54 , char * V_531 , T_9 V_532 )
{
struct V_156 * V_157 = F_70 ( V_54 ) ;
struct V_538 * V_539 ;
int V_55 = - V_260 ;
F_26 ( & V_54 -> V_158 ) ;
V_539 = V_157 -> V_540 ;
if ( V_539 == NULL )
goto V_117;
if ( V_531 == NULL )
goto V_541;
if ( V_539 -> V_542 == 0 )
goto V_117;
V_55 = - V_543 ;
if ( V_539 -> V_400 > V_532 )
goto V_117;
memcpy ( V_531 , V_539 -> V_136 , V_539 -> V_400 ) ;
V_541:
V_55 = V_539 -> V_400 ;
V_117:
F_28 ( & V_54 -> V_158 ) ;
return V_55 ;
}
static void F_327 ( struct V_54 * V_54 , struct V_412 * * V_24 , T_9 V_31 , T_9 V_544 )
{
struct V_538 * V_539 ;
T_9 V_532 = sizeof( * V_539 ) + V_544 ;
if ( V_532 <= V_536 ) {
V_539 = F_227 ( V_532 , V_325 ) ;
if ( V_539 == NULL )
goto V_117;
V_539 -> V_542 = 1 ;
F_328 ( V_539 -> V_136 , V_24 , V_31 , V_544 ) ;
} else {
V_539 = F_227 ( sizeof( * V_539 ) , V_325 ) ;
if ( V_539 == NULL )
goto V_117;
V_539 -> V_542 = 0 ;
}
V_539 -> V_400 = V_544 ;
V_117:
F_324 ( V_54 , V_539 ) ;
}
static T_10 F_329 ( struct V_54 * V_54 , void * V_531 , T_9 V_532 )
{
struct V_412 * V_24 [ V_545 ] = { NULL , } ;
struct V_546 args = {
. V_190 = F_83 ( V_54 ) ,
. V_547 = V_24 ,
. V_544 = V_532 ,
} ;
struct V_548 V_34 = {
. V_544 = V_532 ,
} ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_549 ] ,
. V_269 = & args ,
. V_270 = & V_34 ,
} ;
unsigned int V_550 = F_330 ( V_532 , V_536 ) ;
int V_55 = - V_253 , V_399 ;
if ( V_550 == 0 )
V_550 = 1 ;
if ( V_550 > F_218 ( V_24 ) )
return - V_543 ;
for ( V_399 = 0 ; V_399 < V_550 ; V_399 ++ ) {
V_24 [ V_399 ] = F_226 ( V_325 ) ;
if ( ! V_24 [ V_399 ] )
goto V_265;
}
V_34 . V_551 = F_226 ( V_325 ) ;
if ( ! V_34 . V_551 )
goto V_265;
args . V_544 = V_550 * V_536 ;
args . V_552 = 0 ;
F_2 ( L_41 ,
V_14 , V_531 , V_532 , V_550 , args . V_544 ) ;
V_55 = F_68 ( F_77 ( V_54 ) -> V_81 , F_77 ( V_54 ) ,
& V_141 , & args . V_138 , & V_34 . V_139 , 0 ) ;
if ( V_55 )
goto V_265;
if ( V_34 . V_553 & V_554 ) {
if ( V_531 == NULL )
goto V_555;
V_55 = - V_543 ;
goto V_265;
}
F_327 ( V_54 , V_24 , V_34 . V_556 , V_34 . V_544 ) ;
if ( V_531 )
F_328 ( V_531 , V_24 , V_34 . V_556 , V_34 . V_544 ) ;
V_555:
V_55 = V_34 . V_544 ;
V_265:
for ( V_399 = 0 ; V_399 < V_550 ; V_399 ++ )
if ( V_24 [ V_399 ] )
F_230 ( V_24 [ V_399 ] ) ;
if ( V_34 . V_551 )
F_230 ( V_34 . V_551 ) ;
return V_55 ;
}
static T_10 F_331 ( struct V_54 * V_54 , void * V_531 , T_9 V_532 )
{
struct V_50 V_51 = { } ;
T_10 V_55 ;
do {
V_55 = F_329 ( V_54 , V_531 , V_532 ) ;
if ( V_55 >= 0 )
break;
V_55 = F_16 ( F_77 ( V_54 ) , V_55 , & V_51 ) ;
} while ( V_51 . V_56 );
return V_55 ;
}
static T_10 F_332 ( struct V_54 * V_54 , void * V_531 , T_9 V_532 )
{
struct V_47 * V_48 = F_77 ( V_54 ) ;
int V_55 ;
if ( ! F_320 ( V_48 ) )
return - V_557 ;
V_55 = F_333 ( V_48 , V_54 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( F_70 ( V_54 ) -> V_159 & V_558 )
F_334 ( V_54 ) ;
V_55 = F_326 ( V_54 , V_531 , V_532 ) ;
if ( V_55 != - V_260 )
return V_55 ;
return F_331 ( V_54 , V_531 , V_532 ) ;
}
static int F_335 ( struct V_54 * V_54 , const void * V_531 , T_9 V_532 )
{
struct V_47 * V_48 = F_77 ( V_54 ) ;
struct V_412 * V_24 [ V_545 ] ;
struct V_559 V_337 = {
. V_190 = F_83 ( V_54 ) ,
. V_547 = V_24 ,
. V_544 = V_532 ,
} ;
struct V_560 V_34 ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_561 ] ,
. V_269 = & V_337 ,
. V_270 = & V_34 ,
} ;
unsigned int V_550 = F_330 ( V_532 , V_536 ) ;
int V_55 , V_399 ;
if ( ! F_320 ( V_48 ) )
return - V_557 ;
if ( V_550 > F_218 ( V_24 ) )
return - V_543 ;
V_399 = F_321 ( V_531 , V_532 , V_337 . V_547 , & V_337 . V_552 ) ;
if ( V_399 < 0 )
return V_399 ;
F_18 ( V_54 ) ;
V_55 = F_68 ( V_48 -> V_81 , V_48 , & V_141 , & V_337 . V_138 , & V_34 . V_139 , 1 ) ;
for (; V_399 > 0 ; V_399 -- )
F_336 ( V_24 [ V_399 - 1 ] ) ;
F_26 ( & V_54 -> V_158 ) ;
F_70 ( V_54 ) -> V_159 |= V_160 ;
F_28 ( & V_54 -> V_158 ) ;
F_337 ( V_54 ) ;
F_334 ( V_54 ) ;
return V_55 ;
}
static int F_338 ( struct V_54 * V_54 , const void * V_531 , T_9 V_532 )
{
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_54 ) ,
F_335 ( V_54 , V_531 , V_532 ) ,
& V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static int
F_199 ( struct V_99 * V_100 , const struct V_47 * V_48 , struct V_52 * V_53 )
{
struct V_32 * V_33 = V_48 -> V_32 ;
if ( V_100 -> V_150 >= 0 )
return 0 ;
switch( V_100 -> V_150 ) {
case - V_60 :
case - V_61 :
case - V_62 :
if ( V_53 == NULL )
break;
F_20 ( V_53 -> V_54 ) ;
case - V_57 :
if ( V_53 == NULL )
break;
F_19 ( V_48 , V_53 ) ;
goto V_59;
case - V_63 :
if ( V_53 != NULL )
F_19 ( V_48 , V_53 ) ;
case - V_64 :
case - V_65 :
F_21 ( V_33 ) ;
goto V_59;
#if F_22 ( V_66 )
case - V_67 :
case - V_68 :
case - V_69 :
case - V_71 :
case - V_70 :
case - V_72 :
case - V_73 :
F_2 ( L_42 , V_14 ,
V_100 -> V_150 ) ;
F_23 ( V_33 -> V_74 , V_100 -> V_150 ) ;
V_100 -> V_150 = 0 ;
return - V_130 ;
#endif
case - V_79 :
F_339 ( V_48 , V_562 ) ;
case - V_78 :
case - V_80 :
F_44 ( V_100 , V_44 ) ;
V_100 -> V_150 = 0 ;
return - V_130 ;
case - V_82 :
case - V_83 :
V_100 -> V_150 = 0 ;
return - V_130 ;
}
V_100 -> V_150 = F_1 ( V_100 -> V_150 ) ;
return 0 ;
V_59:
F_52 ( & V_33 -> V_563 , V_100 , NULL ) ;
if ( F_36 ( V_36 , & V_33 -> V_35 ) == 0 )
F_340 ( & V_33 -> V_563 , V_100 ) ;
V_100 -> V_150 = 0 ;
return - V_130 ;
}
static void F_341 ( const struct V_32 * V_33 ,
T_11 * V_564 )
{
T_2 V_213 [ 2 ] ;
if ( F_36 ( V_565 , & V_33 -> V_35 ) ) {
V_213 [ 0 ] = 0 ;
V_213 [ 1 ] = ( T_2 ) ( V_566 + 1 ) ;
} else {
struct V_567 * V_568 = F_342 ( V_33 -> V_569 , V_570 ) ;
V_213 [ 0 ] = ( T_2 ) V_568 -> V_571 . V_572 ;
V_213 [ 1 ] = ( T_2 ) V_568 -> V_571 . V_573 ;
}
memcpy ( V_564 -> V_136 , V_213 , sizeof( V_564 -> V_136 ) ) ;
}
static unsigned int
F_343 ( const struct V_32 * V_33 ,
char * V_531 , T_9 V_400 )
{
unsigned int V_574 ;
F_112 () ;
V_574 = F_344 ( V_531 , V_400 , L_43 ,
V_33 -> V_575 ,
F_345 ( V_33 -> V_525 ,
V_576 ) ,
F_345 ( V_33 -> V_525 ,
V_577 ) ) ;
F_115 () ;
return V_574 ;
}
static unsigned int
F_346 ( const struct V_32 * V_33 ,
char * V_531 , T_9 V_400 )
{
char * V_578 = V_33 -> V_525 -> V_579 ;
if ( V_580 [ 0 ] != '\0' )
V_578 = V_580 ;
return F_344 ( V_531 , V_400 , L_44 ,
V_33 -> V_581 -> V_582 , V_33 -> V_405 ,
V_578 ) ;
}
int F_347 ( struct V_32 * V_33 , T_3 V_583 ,
unsigned short V_584 , struct V_271 * V_299 ,
struct V_585 * V_34 )
{
T_11 V_586 ;
struct V_587 V_588 = {
. V_586 = & V_586 ,
. V_589 = V_583 ,
. V_590 = V_33 -> V_591 ,
} ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_592 ] ,
. V_269 = & V_588 ,
. V_270 = V_34 ,
. V_271 = V_299 ,
} ;
int V_263 ;
F_341 ( V_33 , & V_586 ) ;
if ( F_36 ( V_593 , & V_33 -> V_594 ) )
V_588 . V_595 =
F_346 ( V_33 ,
V_588 . V_596 ,
sizeof( V_588 . V_596 ) ) ;
else
V_588 . V_595 =
F_343 ( V_33 ,
V_588 . V_596 ,
sizeof( V_588 . V_596 ) ) ;
F_112 () ;
V_588 . V_597 = F_344 ( V_588 . V_598 ,
sizeof( V_588 . V_598 ) ,
F_345 ( V_33 -> V_525 ,
V_599 ) ) ;
F_115 () ;
V_588 . V_600 = F_344 ( V_588 . V_601 ,
sizeof( V_588 . V_601 ) , L_45 ,
V_33 -> V_575 , V_584 >> 8 , V_584 & 255 ) ;
F_2 ( L_46 ,
V_33 -> V_525 -> V_602 -> V_603 -> V_604 ,
V_588 . V_595 , V_588 . V_596 ) ;
V_263 = F_67 ( V_33 -> V_525 , & V_141 , V_605 ) ;
F_2 ( L_47 , V_263 ) ;
return V_263 ;
}
int F_348 ( struct V_32 * V_33 ,
struct V_585 * V_337 ,
struct V_271 * V_299 )
{
struct V_391 V_490 ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_606 ] ,
. V_269 = V_337 ,
. V_270 = & V_490 ,
. V_271 = V_299 ,
} ;
unsigned long V_528 ;
int V_263 ;
F_2 ( L_48 ,
V_33 -> V_525 -> V_602 -> V_603 -> V_604 ,
V_33 -> V_199 ) ;
V_528 = V_133 ;
V_263 = F_67 ( V_33 -> V_525 , & V_141 , V_605 ) ;
if ( V_263 == 0 ) {
F_26 ( & V_33 -> V_89 ) ;
V_33 -> V_607 = V_490 . V_608 * V_76 ;
V_33 -> V_90 = V_528 ;
F_28 ( & V_33 -> V_89 ) ;
}
F_2 ( L_49 , V_263 ) ;
return V_263 ;
}
static void F_349 ( struct V_99 * V_100 , void * V_134 )
{
struct V_609 * V_136 = V_134 ;
if ( ! F_45 ( V_100 , & V_136 -> V_34 . V_139 ) )
return;
switch ( V_100 -> V_150 ) {
case - V_64 :
case - V_63 :
case 0 :
F_29 ( V_136 -> V_34 . V_48 , V_136 -> V_88 ) ;
break;
default:
if ( F_199 ( V_100 , V_136 -> V_34 . V_48 , NULL ) ==
- V_130 ) {
F_200 ( V_100 ) ;
return;
}
}
V_136 -> V_247 = V_100 -> V_150 ;
}
static void F_350 ( void * V_134 )
{
F_86 ( V_134 ) ;
}
static void F_351 ( struct V_99 * V_100 , void * V_136 )
{
struct V_609 * V_610 ;
V_610 = (struct V_609 * ) V_136 ;
if ( F_54 ( V_610 -> V_34 . V_48 ,
& V_610 -> args . V_138 ,
& V_610 -> V_34 . V_139 , V_100 ) )
return;
F_57 ( V_100 ) ;
}
static int F_352 ( struct V_54 * V_54 , struct V_271 * V_299 , const T_6 * V_216 , int V_611 )
{
struct V_609 * V_136 ;
struct V_47 * V_48 = F_77 ( V_54 ) ;
struct V_99 * V_100 ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_612 ] ,
. V_271 = V_299 ,
} ;
struct V_143 V_272 = {
. V_145 = V_48 -> V_81 ,
. V_140 = & V_141 ,
. V_146 = & V_613 ,
. V_180 = V_276 ,
} ;
int V_263 = 0 ;
V_136 = F_78 ( sizeof( * V_136 ) , V_261 ) ;
if ( V_136 == NULL )
return - V_253 ;
F_49 ( & V_136 -> args . V_138 , & V_136 -> V_34 . V_139 , 1 ) ;
V_136 -> args . V_364 = & V_136 -> V_190 ;
V_136 -> args . V_216 = & V_136 -> V_216 ;
V_136 -> args . V_206 = V_48 -> V_360 ;
F_156 ( & V_136 -> V_190 , F_83 ( V_54 ) ) ;
F_105 ( & V_136 -> V_216 , V_216 ) ;
V_136 -> V_34 . V_335 = & V_136 -> V_335 ;
V_136 -> V_34 . V_48 = V_48 ;
F_73 ( V_136 -> V_34 . V_335 ) ;
V_136 -> V_88 = V_133 ;
V_136 -> V_247 = 0 ;
V_272 . V_148 = V_136 ;
V_141 . V_269 = & V_136 -> args ;
V_141 . V_270 = & V_136 -> V_34 ;
V_100 = F_61 ( & V_272 ) ;
if ( F_62 ( V_100 ) )
return F_63 ( V_100 ) ;
if ( ! V_611 )
goto V_117;
V_263 = F_97 ( V_100 ) ;
if ( V_263 != 0 )
goto V_117;
V_263 = V_136 -> V_247 ;
if ( V_263 == 0 )
F_301 ( V_54 , & V_136 -> V_335 ) ;
else
F_126 ( V_54 , & V_136 -> V_335 ) ;
V_117:
F_64 ( V_100 ) ;
return V_263 ;
}
int F_353 ( struct V_54 * V_54 , struct V_271 * V_299 , const T_6 * V_216 , int V_611 )
{
struct V_47 * V_48 = F_77 ( V_54 ) ;
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_352 ( V_54 , V_299 , V_216 , V_611 ) ;
switch ( V_1 ) {
case - V_64 :
case - V_63 :
case 0 :
return 0 ;
}
V_1 = F_16 ( V_48 , V_1 , & V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static unsigned long
F_354 ( unsigned long V_42 )
{
F_14 ( V_42 ) ;
V_42 <<= 1 ;
if ( V_42 > V_614 )
return V_614 ;
return V_42 ;
}
static int F_355 ( struct V_52 * V_53 , int V_615 , struct V_616 * V_617 )
{
struct V_54 * V_54 = V_53 -> V_54 ;
struct V_47 * V_48 = F_77 ( V_54 ) ;
struct V_32 * V_33 = V_48 -> V_32 ;
struct V_618 V_337 = {
. V_190 = F_83 ( V_54 ) ,
. V_619 = V_617 ,
} ;
struct V_620 V_34 = {
. V_621 = V_617 ,
} ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_622 ] ,
. V_269 = & V_337 ,
. V_270 = & V_34 ,
. V_271 = V_53 -> V_188 -> V_243 ,
} ;
struct V_623 * V_624 ;
int V_263 ;
V_337 . V_625 . V_198 = V_33 -> V_199 ;
V_263 = F_356 ( V_53 , V_617 ) ;
if ( V_263 != 0 )
goto V_117;
V_624 = V_617 -> V_626 . V_627 . V_188 ;
V_337 . V_625 . V_200 = V_624 -> V_628 . V_203 ;
V_337 . V_625 . V_629 = V_48 -> V_629 ;
V_263 = F_68 ( V_48 -> V_81 , V_48 , & V_141 , & V_337 . V_138 , & V_34 . V_139 , 1 ) ;
switch ( V_263 ) {
case 0 :
V_617 -> V_630 = V_631 ;
break;
case - V_632 :
V_263 = 0 ;
}
V_617 -> V_633 -> V_634 ( V_617 ) ;
V_117:
return V_263 ;
}
static int F_357 ( struct V_52 * V_53 , int V_615 , struct V_616 * V_617 )
{
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_53 -> V_54 ) ,
F_355 ( V_53 , V_615 , V_617 ) ,
& V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static int F_358 ( struct V_635 * V_635 , struct V_616 * V_619 )
{
int V_34 = 0 ;
switch ( V_619 -> V_636 & ( V_637 | V_638 ) ) {
case V_637 :
V_34 = F_359 ( V_635 , V_619 ) ;
break;
case V_638 :
V_34 = F_360 ( V_635 , V_619 ) ;
break;
default:
F_361 () ;
}
return V_34 ;
}
static struct V_639 * F_362 ( struct V_616 * V_619 ,
struct V_258 * V_259 ,
struct V_623 * V_624 ,
struct V_640 * V_169 )
{
struct V_639 * V_22 ;
struct V_54 * V_54 = V_624 -> V_641 -> V_54 ;
V_22 = F_78 ( sizeof( * V_22 ) , V_261 ) ;
if ( V_22 == NULL )
return NULL ;
V_22 -> V_337 . V_190 = F_83 ( V_54 ) ;
V_22 -> V_337 . V_619 = & V_22 -> V_619 ;
V_22 -> V_337 . V_169 = V_169 ;
V_22 -> V_34 . V_169 = V_169 ;
V_22 -> V_337 . V_216 = & V_624 -> V_642 ;
V_22 -> V_624 = V_624 ;
F_82 ( & V_624 -> V_643 ) ;
V_22 -> V_259 = F_133 ( V_259 ) ;
memcpy ( & V_22 -> V_619 , V_619 , sizeof( V_22 -> V_619 ) ) ;
V_22 -> V_48 = F_77 ( V_54 ) ;
return V_22 ;
}
static void F_363 ( void * V_136 )
{
struct V_639 * V_134 = V_136 ;
F_90 ( V_134 -> V_337 . V_169 ) ;
F_364 ( V_134 -> V_624 ) ;
F_144 ( V_134 -> V_259 ) ;
F_86 ( V_134 ) ;
}
static void F_365 ( struct V_99 * V_100 , void * V_136 )
{
struct V_639 * V_134 = V_136 ;
if ( ! F_45 ( V_100 , & V_134 -> V_34 . V_139 ) )
return;
switch ( V_100 -> V_150 ) {
case 0 :
F_105 ( & V_134 -> V_624 -> V_642 ,
& V_134 -> V_34 . V_216 ) ;
F_29 ( V_134 -> V_48 , V_134 -> V_88 ) ;
break;
case - V_62 :
case - V_83 :
case - V_64 :
case - V_63 :
break;
default:
if ( F_199 ( V_100 , V_134 -> V_48 , NULL ) == - V_130 )
F_200 ( V_100 ) ;
}
F_157 ( V_134 -> V_337 . V_169 ) ;
}
static void F_366 ( struct V_99 * V_100 , void * V_136 )
{
struct V_639 * V_134 = V_136 ;
if ( F_155 ( V_134 -> V_337 . V_169 , V_100 ) != 0 )
return;
if ( F_36 ( V_644 , & V_134 -> V_624 -> V_645 ) == 0 ) {
V_100 -> V_283 = NULL ;
return;
}
V_134 -> V_88 = V_133 ;
if ( F_54 ( V_134 -> V_48 ,
& V_134 -> V_337 . V_138 ,
& V_134 -> V_34 . V_139 ,
V_100 ) != 0 )
F_157 ( V_134 -> V_337 . V_169 ) ;
else
F_57 ( V_100 ) ;
}
static struct V_99 * F_367 ( struct V_616 * V_619 ,
struct V_258 * V_259 ,
struct V_623 * V_624 ,
struct V_640 * V_169 )
{
struct V_639 * V_136 ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_646 ] ,
. V_271 = V_259 -> V_299 ,
} ;
struct V_143 V_272 = {
. V_145 = F_241 ( V_624 -> V_641 -> V_54 ) ,
. V_140 = & V_141 ,
. V_146 = & V_647 ,
. V_274 = V_275 ,
. V_180 = V_276 ,
} ;
V_619 -> V_630 = V_631 ;
V_136 = F_362 ( V_619 , V_259 , V_624 , V_169 ) ;
if ( V_136 == NULL ) {
F_90 ( V_169 ) ;
return F_119 ( - V_253 ) ;
}
F_49 ( & V_136 -> V_337 . V_138 , & V_136 -> V_34 . V_139 , 1 ) ;
V_141 . V_269 = & V_136 -> V_337 ;
V_141 . V_270 = & V_136 -> V_34 ;
V_272 . V_148 = V_136 ;
return F_61 ( & V_272 ) ;
}
static int F_368 ( struct V_52 * V_53 , int V_615 , struct V_616 * V_617 )
{
struct V_156 * V_157 = F_70 ( V_53 -> V_54 ) ;
struct V_640 * V_169 ;
struct V_623 * V_624 ;
struct V_99 * V_100 ;
int V_263 = 0 ;
unsigned char V_636 = V_617 -> V_636 ;
V_263 = F_356 ( V_53 , V_617 ) ;
V_617 -> V_636 |= V_648 ;
F_369 ( & V_157 -> V_649 ) ;
if ( F_358 ( V_617 -> V_650 , V_617 ) == - V_260 ) {
F_370 ( & V_157 -> V_649 ) ;
goto V_117;
}
F_370 ( & V_157 -> V_649 ) ;
if ( V_263 != 0 )
goto V_117;
if ( F_36 ( V_232 , & V_53 -> V_180 ) )
goto V_117;
V_624 = V_617 -> V_626 . V_627 . V_188 ;
V_169 = F_79 ( & V_624 -> V_628 , V_325 ) ;
V_263 = - V_253 ;
if ( V_169 == NULL )
goto V_117;
V_100 = F_367 ( V_617 , F_234 ( V_617 -> V_650 ) , V_624 , V_169 ) ;
V_263 = F_63 ( V_100 ) ;
if ( F_62 ( V_100 ) )
goto V_117;
V_263 = F_97 ( V_100 ) ;
F_64 ( V_100 ) ;
V_117:
V_617 -> V_636 = V_636 ;
return V_263 ;
}
static struct V_651 * F_371 ( struct V_616 * V_619 ,
struct V_258 * V_259 , struct V_623 * V_624 ,
T_5 V_183 )
{
struct V_651 * V_22 ;
struct V_54 * V_54 = V_624 -> V_641 -> V_54 ;
struct V_47 * V_48 = F_77 ( V_54 ) ;
V_22 = F_78 ( sizeof( * V_22 ) , V_183 ) ;
if ( V_22 == NULL )
return NULL ;
V_22 -> V_337 . V_190 = F_83 ( V_54 ) ;
V_22 -> V_337 . V_619 = & V_22 -> V_619 ;
V_22 -> V_337 . V_652 = F_79 ( & V_624 -> V_641 -> V_188 -> V_185 , V_183 ) ;
if ( V_22 -> V_337 . V_652 == NULL )
goto V_265;
V_22 -> V_337 . V_653 = F_79 ( & V_624 -> V_628 , V_183 ) ;
if ( V_22 -> V_337 . V_653 == NULL )
goto V_654;
V_22 -> V_337 . V_655 = & V_624 -> V_642 ;
V_22 -> V_337 . V_625 . V_198 = V_48 -> V_32 -> V_199 ;
V_22 -> V_337 . V_625 . V_200 = V_624 -> V_628 . V_203 ;
V_22 -> V_337 . V_625 . V_629 = V_48 -> V_629 ;
V_22 -> V_34 . V_653 = V_22 -> V_337 . V_653 ;
V_22 -> V_624 = V_624 ;
V_22 -> V_48 = V_48 ;
F_82 ( & V_624 -> V_643 ) ;
V_22 -> V_259 = F_133 ( V_259 ) ;
memcpy ( & V_22 -> V_619 , V_619 , sizeof( V_22 -> V_619 ) ) ;
return V_22 ;
V_654:
F_90 ( V_22 -> V_337 . V_652 ) ;
V_265:
F_86 ( V_22 ) ;
return NULL ;
}
static void F_372 ( struct V_99 * V_100 , void * V_134 )
{
struct V_651 * V_136 = V_134 ;
struct V_52 * V_53 = V_136 -> V_624 -> V_641 ;
F_2 ( L_30 , V_14 ) ;
if ( F_155 ( V_136 -> V_337 . V_653 , V_100 ) != 0 )
return;
if ( ! ( V_136 -> V_337 . V_653 -> V_656 -> V_180 & V_657 ) ) {
if ( F_155 ( V_136 -> V_337 . V_652 , V_100 ) != 0 )
goto V_658;
V_136 -> V_337 . V_233 = & V_53 -> V_216 ;
V_136 -> V_337 . V_659 = 1 ;
V_136 -> V_34 . V_652 = V_136 -> V_337 . V_652 ;
} else
V_136 -> V_337 . V_659 = 0 ;
V_136 -> V_88 = V_133 ;
if ( F_54 ( V_136 -> V_48 ,
& V_136 -> V_337 . V_138 ,
& V_136 -> V_34 . V_139 ,
V_100 ) == 0 ) {
F_57 ( V_100 ) ;
return;
}
F_157 ( V_136 -> V_337 . V_652 ) ;
V_658:
F_157 ( V_136 -> V_337 . V_653 ) ;
F_2 ( L_50 , V_14 , V_100 -> V_150 ) ;
}
static void F_373 ( struct V_99 * V_100 , void * V_134 )
{
F_34 ( V_100 , V_102 ) ;
F_372 ( V_100 , V_134 ) ;
}
static void F_374 ( struct V_99 * V_100 , void * V_134 )
{
struct V_651 * V_136 = V_134 ;
F_2 ( L_30 , V_14 ) ;
if ( ! F_45 ( V_100 , & V_136 -> V_34 . V_139 ) )
return;
V_136 -> V_247 = V_100 -> V_150 ;
if ( V_136 -> V_337 . V_659 != 0 ) {
if ( V_136 -> V_247 == 0 )
F_149 ( & V_136 -> V_624 -> V_628 , 0 ) ;
else
goto V_117;
}
if ( V_136 -> V_247 == 0 ) {
F_105 ( & V_136 -> V_624 -> V_642 , & V_136 -> V_34 . V_216 ) ;
F_106 ( V_644 , & V_136 -> V_624 -> V_645 ) ;
F_29 ( F_77 ( V_136 -> V_259 -> V_18 -> V_28 ) , V_136 -> V_88 ) ;
}
V_117:
F_2 ( L_31 , V_14 , V_136 -> V_247 ) ;
}
static void F_375 ( void * V_134 )
{
struct V_651 * V_136 = V_134 ;
F_2 ( L_30 , V_14 ) ;
F_90 ( V_136 -> V_337 . V_652 ) ;
if ( V_136 -> V_264 != 0 ) {
struct V_99 * V_100 ;
V_100 = F_367 ( & V_136 -> V_619 , V_136 -> V_259 , V_136 -> V_624 ,
V_136 -> V_337 . V_653 ) ;
if ( ! F_62 ( V_100 ) )
F_376 ( V_100 ) ;
F_2 ( L_51 , V_14 ) ;
} else
F_90 ( V_136 -> V_337 . V_653 ) ;
F_364 ( V_136 -> V_624 ) ;
F_144 ( V_136 -> V_259 ) ;
F_86 ( V_136 ) ;
F_2 ( L_32 , V_14 ) ;
}
static void F_377 ( struct V_47 * V_48 , struct V_623 * V_624 , int V_659 , int error )
{
switch ( error ) {
case - V_61 :
case - V_62 :
V_624 -> V_628 . V_180 &= ~ V_657 ;
if ( V_659 != 0 ||
F_36 ( V_644 , & V_624 -> V_645 ) != 0 )
F_19 ( V_48 , V_624 -> V_641 ) ;
break;
case - V_64 :
V_624 -> V_628 . V_180 &= ~ V_657 ;
case - V_63 :
F_21 ( V_48 -> V_32 ) ;
} ;
}
static int F_378 ( struct V_52 * V_53 , int V_615 , struct V_616 * V_619 , int V_660 )
{
struct V_651 * V_136 ;
struct V_99 * V_100 ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_661 ] ,
. V_271 = V_53 -> V_188 -> V_243 ,
} ;
struct V_143 V_272 = {
. V_145 = F_241 ( V_53 -> V_54 ) ,
. V_140 = & V_141 ,
. V_146 = & V_662 ,
. V_274 = V_275 ,
. V_180 = V_276 ,
} ;
int V_55 ;
F_2 ( L_30 , V_14 ) ;
V_136 = F_371 ( V_619 , F_234 ( V_619 -> V_650 ) ,
V_619 -> V_626 . V_627 . V_188 ,
V_660 == V_663 ? V_325 : V_261 ) ;
if ( V_136 == NULL )
return - V_253 ;
if ( F_379 ( V_615 ) )
V_136 -> V_337 . V_664 = 1 ;
if ( V_660 > V_663 ) {
if ( V_660 == V_665 )
V_136 -> V_337 . V_666 = V_665 ;
V_272 . V_146 = & V_667 ;
}
F_49 ( & V_136 -> V_337 . V_138 , & V_136 -> V_34 . V_139 , 1 ) ;
V_141 . V_269 = & V_136 -> V_337 ;
V_141 . V_270 = & V_136 -> V_34 ;
V_272 . V_148 = V_136 ;
V_100 = F_61 ( & V_272 ) ;
if ( F_62 ( V_100 ) )
return F_63 ( V_100 ) ;
V_55 = F_97 ( V_100 ) ;
if ( V_55 == 0 ) {
V_55 = V_136 -> V_247 ;
if ( V_55 )
F_377 ( V_136 -> V_48 , V_136 -> V_624 ,
V_136 -> V_337 . V_659 , V_55 ) ;
} else
V_136 -> V_264 = 1 ;
F_64 ( V_100 ) ;
F_2 ( L_31 , V_14 , V_55 ) ;
return V_55 ;
}
static int F_380 ( struct V_52 * V_53 , struct V_616 * V_617 )
{
struct V_47 * V_48 = F_77 ( V_53 -> V_54 ) ;
struct V_50 V_51 = {
. V_54 = V_53 -> V_54 ,
} ;
int V_1 ;
do {
if ( F_36 ( V_232 , & V_53 -> V_180 ) != 0 )
return 0 ;
V_1 = F_378 ( V_53 , V_668 , V_617 , V_665 ) ;
if ( V_1 != - V_79 )
break;
F_16 ( V_48 , V_1 , & V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static int F_381 ( struct V_52 * V_53 , struct V_616 * V_617 )
{
struct V_47 * V_48 = F_77 ( V_53 -> V_54 ) ;
struct V_50 V_51 = {
. V_54 = V_53 -> V_54 ,
} ;
int V_1 ;
V_1 = F_356 ( V_53 , V_617 ) ;
if ( V_1 != 0 )
return V_1 ;
do {
if ( F_36 ( V_232 , & V_53 -> V_180 ) != 0 )
return 0 ;
V_1 = F_378 ( V_53 , V_668 , V_617 , V_669 ) ;
switch ( V_1 ) {
default:
goto V_117;
case - V_78 :
case - V_79 :
F_16 ( V_48 , V_1 , & V_51 ) ;
V_1 = 0 ;
}
} while ( V_51 . V_56 );
V_117:
return V_1 ;
}
static int F_382 ( struct V_52 * V_53 )
{
int V_263 , V_55 = - V_62 ;
struct V_623 * V_624 ;
struct V_47 * V_48 = F_77 ( V_53 -> V_54 ) ;
F_132 (lsp, &state->lock_states, ls_locks) {
if ( F_36 ( V_644 , & V_624 -> V_645 ) ) {
V_263 = F_176 ( V_48 , & V_624 -> V_642 ) ;
if ( V_263 != V_116 ) {
if ( V_263 != - V_62 )
F_177 ( V_48 ,
& V_624 -> V_642 ) ;
F_139 ( V_644 , & V_624 -> V_645 ) ;
V_55 = V_263 ;
}
}
} ;
return V_55 ;
}
static int F_383 ( struct V_52 * V_53 , struct V_616 * V_617 )
{
int V_263 = V_116 ;
if ( F_36 ( V_670 , & V_53 -> V_180 ) )
V_263 = F_382 ( V_53 ) ;
if ( V_263 != V_116 )
V_263 = F_381 ( V_53 , V_617 ) ;
return V_263 ;
}
static int F_384 ( struct V_52 * V_53 , int V_615 , struct V_616 * V_617 )
{
struct V_156 * V_157 = F_70 ( V_53 -> V_54 ) ;
unsigned char V_636 = V_617 -> V_636 ;
int V_263 = - V_671 ;
if ( ( V_636 & V_637 ) &&
! F_36 ( V_332 , & V_53 -> V_180 ) )
goto V_117;
V_263 = F_356 ( V_53 , V_617 ) ;
if ( V_263 != 0 )
goto V_117;
V_617 -> V_636 |= V_672 ;
V_263 = F_358 ( V_617 -> V_650 , V_617 ) ;
if ( V_263 < 0 )
goto V_117;
F_369 ( & V_157 -> V_649 ) ;
if ( F_36 ( V_232 , & V_53 -> V_180 ) ) {
V_617 -> V_636 = V_636 & ~ V_673 ;
V_263 = F_358 ( V_617 -> V_650 , V_617 ) ;
goto V_674;
}
V_263 = F_378 ( V_53 , V_615 , V_617 , V_663 ) ;
if ( V_263 != 0 )
goto V_674;
V_617 -> V_636 = V_636 | V_673 ;
if ( F_358 ( V_617 -> V_650 , V_617 ) < 0 )
F_24 ( V_86 L_52
L_53 , V_14 ) ;
V_674:
F_370 ( & V_157 -> V_649 ) ;
V_117:
V_617 -> V_636 = V_636 ;
return V_263 ;
}
static int F_385 ( struct V_52 * V_53 , int V_615 , struct V_616 * V_617 )
{
struct V_50 V_51 = {
. V_53 = V_53 ,
. V_54 = V_53 -> V_54 ,
} ;
int V_1 ;
do {
V_1 = F_384 ( V_53 , V_615 , V_617 ) ;
if ( V_1 == - V_632 )
V_1 = - V_130 ;
V_1 = F_16 ( F_77 ( V_53 -> V_54 ) ,
V_1 , & V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static int
F_386 ( struct V_635 * V_675 , int V_615 , struct V_616 * V_617 )
{
struct V_258 * V_259 ;
struct V_52 * V_53 ;
unsigned long V_42 = V_676 ;
int V_263 ;
V_259 = F_234 ( V_675 ) ;
V_53 = V_259 -> V_53 ;
if ( V_617 -> V_677 < 0 || V_617 -> V_678 < 0 )
return - V_8 ;
if ( F_387 ( V_615 ) ) {
if ( V_53 != NULL )
return F_357 ( V_53 , V_679 , V_617 ) ;
return 0 ;
}
if ( ! ( F_388 ( V_615 ) || F_379 ( V_615 ) ) )
return - V_8 ;
if ( V_617 -> V_630 == V_631 ) {
if ( V_53 != NULL )
return F_368 ( V_53 , V_615 , V_617 ) ;
return 0 ;
}
if ( V_53 == NULL )
return - V_671 ;
switch ( V_617 -> V_630 ) {
case V_680 :
if ( ! ( V_675 -> V_681 & V_58 ) )
return - V_348 ;
break;
case V_682 :
if ( ! ( V_675 -> V_681 & V_192 ) )
return - V_348 ;
}
do {
V_263 = F_385 ( V_53 , V_615 , V_617 ) ;
if ( ( V_263 != - V_130 ) || F_388 ( V_615 ) )
break;
V_42 = F_354 ( V_42 ) ;
V_263 = - V_46 ;
if ( F_389 () )
break;
} while( V_263 < 0 );
return V_263 ;
}
int F_390 ( struct V_52 * V_53 , struct V_616 * V_619 )
{
struct V_47 * V_48 = F_77 ( V_53 -> V_54 ) ;
struct V_50 V_51 = { } ;
int V_1 ;
V_1 = F_356 ( V_53 , V_619 ) ;
if ( V_1 != 0 )
goto V_117;
do {
V_1 = F_378 ( V_53 , V_668 , V_619 , V_663 ) ;
switch ( V_1 ) {
default:
F_24 ( V_683 L_54
L_55 , V_14 , V_1 ) ;
case 0 :
case - V_248 :
goto V_117;
case - V_63 :
F_19 ( V_48 , V_53 ) ;
case - V_65 :
case - V_64 :
F_21 ( V_48 -> V_32 ) ;
goto V_117;
case - V_67 :
case - V_68 :
case - V_69 :
case - V_70 :
case - V_71 :
F_23 ( V_48 -> V_32 -> V_74 , V_1 ) ;
goto V_117;
case - V_46 :
case - V_60 :
case - V_61 :
case - V_62 :
case - V_57 :
F_19 ( V_48 , V_53 ) ;
V_1 = 0 ;
goto V_117;
case - V_80 :
V_1 = 0 ;
goto V_117;
case - V_253 :
case - V_632 :
V_1 = 0 ;
goto V_117;
case - V_79 :
break;
}
V_1 = F_16 ( V_48 , V_1 , & V_51 ) ;
} while ( V_51 . V_56 );
V_117:
return V_1 ;
}
static void F_391 ( void * V_134 )
{
struct V_684 * V_136 = V_134 ;
F_392 ( V_136 -> V_48 , V_136 -> V_624 ) ;
F_86 ( V_134 ) ;
}
int F_393 ( struct V_623 * V_624 )
{
struct V_47 * V_48 = V_624 -> V_641 -> V_188 -> V_279 ;
struct V_684 * V_136 ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_685 ] ,
} ;
if ( V_48 -> V_32 -> V_151 -> V_404 != 0 )
return - V_8 ;
V_136 = F_227 ( sizeof( * V_136 ) , V_261 ) ;
if ( ! V_136 )
return - V_253 ;
V_136 -> V_624 = V_624 ;
V_136 -> V_48 = V_48 ;
V_136 -> args . V_625 . V_198 = V_48 -> V_32 -> V_199 ;
V_136 -> args . V_625 . V_200 = V_624 -> V_628 . V_203 ;
V_136 -> args . V_625 . V_629 = V_48 -> V_629 ;
V_141 . V_269 = & V_136 -> args ;
F_318 ( V_48 -> V_81 , & V_141 , 0 , & V_686 , V_136 ) ;
return 0 ;
}
static int F_394 ( struct V_18 * V_18 , const char * V_687 ,
const void * V_531 , T_9 V_532 ,
int V_180 , int type )
{
if ( strcmp ( V_687 , L_56 ) != 0 )
return - V_8 ;
return F_338 ( V_18 -> V_28 , V_531 , V_532 ) ;
}
static int F_395 ( struct V_18 * V_18 , const char * V_687 ,
void * V_531 , T_9 V_532 , int type )
{
if ( strcmp ( V_687 , L_56 ) != 0 )
return - V_8 ;
return F_332 ( V_18 -> V_28 , V_531 , V_532 ) ;
}
static T_9 F_396 ( struct V_18 * V_18 , char * V_688 ,
T_9 V_689 , const char * V_204 ,
T_9 V_690 , int type )
{
T_9 V_400 = sizeof( V_691 ) ;
if ( ! F_320 ( F_77 ( V_18 -> V_28 ) ) )
return 0 ;
if ( V_688 && V_400 <= V_689 )
memcpy ( V_688 , V_691 , V_400 ) ;
return V_400 ;
}
static void F_229 ( struct V_334 * V_335 )
{
if ( ! ( ( ( V_335 -> V_249 & V_692 ) ||
( V_335 -> V_249 & V_251 ) ) &&
( V_335 -> V_249 & V_409 ) &&
( V_335 -> V_249 & V_693 ) ) )
return;
V_335 -> V_249 |= V_250 | V_424 |
V_425 | V_694 ;
V_335 -> V_220 = V_288 | V_427 | V_428 ;
V_335 -> V_429 = 2 ;
}
static int F_397 ( struct V_40 * V_81 , struct V_54 * V_153 ,
const struct V_411 * V_204 ,
struct V_413 * V_695 ,
struct V_412 * V_412 )
{
struct V_47 * V_48 = F_77 ( V_153 ) ;
T_3 V_206 [ 2 ] = {
[ 0 ] = V_696 | V_697 ,
} ;
struct V_698 args = {
. V_422 = F_83 ( V_153 ) ,
. V_204 = V_204 ,
. V_412 = V_412 ,
. V_206 = V_206 ,
} ;
struct V_699 V_34 = {
. V_695 = V_695 ,
} ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_700 ] ,
. V_269 = & args ,
. V_270 = & V_34 ,
} ;
int V_263 ;
F_2 ( L_57 , V_14 ) ;
if ( F_77 ( V_153 ) -> V_207 [ 1 ] & V_701 )
V_206 [ 1 ] |= V_701 ;
else
V_206 [ 0 ] |= V_27 ;
F_73 ( & V_695 -> V_335 ) ;
V_695 -> V_48 = V_48 ;
V_695 -> V_702 = 0 ;
V_263 = F_68 ( V_81 , V_48 , & V_141 , & args . V_138 , & V_34 . V_139 , 0 ) ;
F_2 ( L_58 , V_14 , V_263 ) ;
return V_263 ;
}
int F_228 ( struct V_40 * V_81 , struct V_54 * V_153 ,
const struct V_411 * V_204 ,
struct V_413 * V_695 ,
struct V_412 * V_412 )
{
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_153 ) ,
F_397 ( V_81 , V_153 , V_204 , V_695 , V_412 ) ,
& V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static int F_398 ( struct V_54 * V_153 , const struct V_411 * V_204 , struct V_703 * V_704 )
{
int V_263 ;
struct V_705 args = {
. V_422 = F_83 ( V_153 ) ,
. V_204 = V_204 ,
} ;
struct V_706 V_34 = {
. V_704 = V_704 ,
} ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_707 ] ,
. V_269 = & args ,
. V_270 = & V_34 ,
} ;
F_2 ( L_59 , V_204 -> V_204 ) ;
V_263 = F_68 ( F_77 ( V_153 ) -> V_81 , F_77 ( V_153 ) , & V_141 , & args . V_138 , & V_34 . V_139 , 0 ) ;
F_2 ( L_60 , V_263 ) ;
return V_263 ;
}
int F_399 ( struct V_54 * V_153 , const struct V_411 * V_204 ,
struct V_703 * V_704 )
{
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_16 ( F_77 ( V_153 ) ,
F_398 ( V_153 , V_204 , V_704 ) ,
& V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static int F_400 ( T_3 V_180 )
{
if ( V_180 & ~ V_708 )
goto V_709;
if ( ( V_180 & V_710 ) &&
( V_180 & V_711 ) )
goto V_709;
if ( ! ( V_180 & ( V_712 ) ) )
goto V_709;
return V_116 ;
V_709:
return - V_713 ;
}
static bool
F_401 ( struct V_714 * V_715 ,
struct V_714 * V_716 )
{
if ( V_715 -> V_717 == V_716 -> V_717 &&
memcmp ( V_715 -> V_718 , V_716 -> V_718 , V_715 -> V_717 ) == 0 )
return true ;
return false ;
}
int F_402 ( struct V_32 * V_33 , struct V_271 * V_299 )
{
int V_263 ;
struct V_719 V_34 ;
struct V_140 V_141 = {
. V_266 =
& V_267 [ V_720 ] ,
. V_269 = V_33 ,
. V_270 = & V_34 ,
. V_271 = V_299 ,
} ;
F_2 ( L_17 , V_14 ) ;
F_4 ( V_33 == NULL ) ;
V_34 . V_127 = F_78 ( sizeof( struct V_103 ) , V_261 ) ;
if ( F_403 ( V_34 . V_127 == NULL ) ) {
V_263 = - V_253 ;
goto V_117;
}
V_263 = F_67 ( V_33 -> V_525 , & V_141 , V_605 ) ;
if ( V_263 == 0 ) {
if ( memcmp ( V_34 . V_127 -> V_721 . V_136 ,
V_33 -> V_74 -> V_721 . V_136 , V_722 ) ) {
F_2 ( L_61 , V_14 ) ;
V_263 = - V_15 ;
goto V_723;
}
if ( V_34 . V_153 != V_724 ) {
F_2 ( L_62 ,
V_14 ) ;
V_263 = - V_15 ;
goto V_723;
}
if ( V_34 . V_725 ) {
F_2 ( L_63 ,
V_14 ) ;
V_263 = - V_15 ;
goto V_723;
}
}
V_723:
F_86 ( V_34 . V_127 ) ;
V_117:
F_2 ( L_64 , V_14 , V_263 ) ;
return V_263 ;
}
int F_404 ( struct V_32 * V_33 , struct V_271 * V_299 )
{
T_11 V_17 ;
struct V_726 args = {
. V_17 = & V_17 ,
. V_81 = V_33 ,
. V_180 = V_727 ,
} ;
struct V_728 V_34 = {
0
} ;
int V_263 ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_729 ] ,
. V_269 = & args ,
. V_270 = & V_34 ,
. V_271 = V_299 ,
} ;
F_341 ( V_33 , & V_17 ) ;
args . V_730 = F_346 ( V_33 , args . V_200 ,
sizeof( args . V_200 ) ) ;
F_2 ( L_65 ,
V_33 -> V_525 -> V_602 -> V_603 -> V_604 ,
args . V_730 , args . V_200 ) ;
V_34 . V_731 = F_78 ( sizeof( struct V_732 ) ,
V_261 ) ;
if ( F_403 ( V_34 . V_731 == NULL ) ) {
V_263 = - V_253 ;
goto V_117;
}
V_34 . V_718 = F_78 ( sizeof( struct V_714 ) ,
V_261 ) ;
if ( F_403 ( V_34 . V_718 == NULL ) ) {
V_263 = - V_253 ;
goto V_733;
}
V_34 . V_734 = F_78 ( sizeof( struct V_735 ) , V_261 ) ;
if ( F_403 ( V_34 . V_734 == NULL ) ) {
V_263 = - V_253 ;
goto V_736;
}
V_263 = F_67 ( V_33 -> V_525 , & V_141 , V_605 ) ;
if ( V_263 == 0 )
V_263 = F_400 ( V_34 . V_180 ) ;
if ( V_263 == 0 ) {
V_33 -> V_199 = V_34 . V_198 ;
V_33 -> V_737 = ( V_34 . V_180 & ~ V_738 ) ;
if ( ! ( V_34 . V_180 & V_738 ) )
V_33 -> V_739 = V_34 . V_169 ;
F_86 ( V_33 -> V_740 ) ;
V_33 -> V_740 = V_34 . V_731 ;
V_34 . V_731 = NULL ;
F_86 ( V_33 -> V_741 ) ;
V_33 -> V_741 = V_34 . V_734 ;
if ( V_33 -> V_742 != NULL &&
! F_401 ( V_33 -> V_742 ,
V_34 . V_718 ) ) {
F_2 ( L_66 ,
V_14 ) ;
F_106 ( V_743 , & V_33 -> V_35 ) ;
F_86 ( V_33 -> V_742 ) ;
V_33 -> V_742 = NULL ;
}
if ( V_33 -> V_742 == NULL ) {
V_33 -> V_742 = V_34 . V_718 ;
goto V_117;
}
} else
F_86 ( V_34 . V_734 ) ;
V_733:
F_86 ( V_34 . V_731 ) ;
V_736:
F_86 ( V_34 . V_718 ) ;
V_117:
if ( V_33 -> V_741 != NULL )
F_2 ( L_67
L_68 ,
V_33 -> V_741 -> V_744 , V_33 -> V_741 -> V_204 ,
V_33 -> V_741 -> V_745 . V_746 ,
V_33 -> V_741 -> V_745 . V_747 ) ;
F_2 ( L_69 , V_263 ) ;
return V_263 ;
}
static int F_405 ( struct V_32 * V_33 ,
struct V_271 * V_299 )
{
struct V_140 V_141 = {
. V_266 = & V_267 [ V_748 ] ,
. V_269 = V_33 ,
. V_271 = V_299 ,
} ;
int V_263 ;
V_263 = F_67 ( V_33 -> V_525 , & V_141 , V_605 ) ;
if ( V_263 )
F_2 ( L_70
L_71 , V_263 , V_33 -> V_87 ) ;
return V_263 ;
}
static int F_406 ( struct V_32 * V_33 ,
struct V_271 * V_299 )
{
unsigned int V_311 ;
int V_55 ;
for ( V_311 = V_312 ; V_311 != 0 ; V_311 -- ) {
V_55 = F_405 ( V_33 , V_299 ) ;
switch ( V_55 ) {
case - V_79 :
case - V_749 :
F_407 ( 1 ) ;
break;
default:
return V_55 ;
}
}
return 0 ;
}
int F_408 ( struct V_32 * V_33 )
{
struct V_271 * V_299 ;
int V_55 = 0 ;
if ( V_33 -> V_151 -> V_404 < 1 )
goto V_117;
if ( V_33 -> V_737 == 0 )
goto V_117;
if ( V_33 -> V_750 )
goto V_117;
V_299 = F_409 ( V_33 ) ;
V_55 = F_406 ( V_33 , V_299 ) ;
if ( V_299 )
F_410 ( V_299 ) ;
switch ( V_55 ) {
case 0 :
case - V_65 :
V_33 -> V_737 = 0 ;
}
V_117:
return V_55 ;
}
static void F_411 ( struct V_99 * V_100 ,
void * V_134 )
{
int V_55 ;
struct V_751 * V_136 =
(struct V_751 * ) V_134 ;
F_2 ( L_17 , V_14 ) ;
F_34 ( V_100 , V_102 ) ;
V_55 = F_50 ( V_136 -> V_33 -> V_74 ,
& V_136 -> args -> V_752 ,
& V_136 -> V_34 -> V_753 , V_100 ) ;
F_4 ( V_55 == - V_130 ) ;
F_57 ( V_100 ) ;
F_2 ( L_72 , V_14 ) ;
}
static void F_412 ( struct V_99 * V_100 , void * V_134 )
{
struct V_751 * V_136 =
(struct V_751 * ) V_134 ;
F_2 ( L_17 , V_14 ) ;
if ( ! F_41 ( V_100 , & V_136 -> V_34 -> V_753 ) )
return;
switch ( V_100 -> V_150 ) {
case - V_79 :
case - V_78 :
F_2 ( L_73 , V_14 , V_100 -> V_150 ) ;
F_44 ( V_100 , V_43 ) ;
V_100 -> V_150 = 0 ;
case - V_82 :
F_200 ( V_100 ) ;
return;
}
F_2 ( L_72 , V_14 ) ;
}
int F_413 ( struct V_32 * V_33 , struct V_391 * V_490 )
{
struct V_99 * V_100 ;
struct V_754 args ;
struct V_755 V_34 = {
. V_756 = V_490 ,
} ;
struct V_751 V_136 = {
. args = & args ,
. V_34 = & V_34 ,
. V_33 = V_33 ,
} ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_757 ] ,
. V_269 = & args ,
. V_270 = & V_34 ,
} ;
struct V_143 V_144 = {
. V_145 = V_33 -> V_525 ,
. V_140 = & V_141 ,
. V_146 = & V_758 ,
. V_148 = & V_136 ,
. V_180 = V_605 ,
} ;
int V_263 ;
F_49 ( & args . V_752 , & V_34 . V_753 , 0 ) ;
F_2 ( L_17 , V_14 ) ;
V_100 = F_61 ( & V_144 ) ;
if ( F_62 ( V_100 ) )
V_263 = F_63 ( V_100 ) ;
else {
V_263 = V_100 -> V_150 ;
F_64 ( V_100 ) ;
}
F_2 ( L_74 , V_14 , V_263 ) ;
return V_263 ;
}
static struct V_128 * F_414 ( T_3 V_97 , T_5 V_759 )
{
return F_415 ( V_97 , sizeof( struct V_128 ) , V_759 ) ;
}
static void F_416 ( struct V_91 * V_92 ,
struct V_128 * V_760 ,
T_3 V_97 ,
T_3 V_761 )
{
struct V_128 * V_762 = NULL ;
T_3 V_399 ;
F_26 ( & V_92 -> V_113 ) ;
if ( V_760 ) {
V_762 = V_92 -> V_114 ;
V_92 -> V_114 = V_760 ;
V_92 -> V_97 = V_97 ;
}
V_92 -> V_96 = V_98 ;
for ( V_399 = 0 ; V_399 < V_92 -> V_97 ; V_399 ++ )
V_92 -> V_114 [ V_399 ] . V_118 = V_761 ;
F_28 ( & V_92 -> V_113 ) ;
F_86 ( V_762 ) ;
}
static int F_417 ( struct V_91 * V_92 , T_3 V_763 ,
T_3 V_761 )
{
struct V_128 * V_760 = NULL ;
int V_55 = - V_253 ;
F_2 ( L_75 , V_14 ,
V_763 , V_92 -> V_97 ) ;
if ( V_763 != V_92 -> V_97 ) {
V_760 = F_414 ( V_763 , V_261 ) ;
if ( ! V_760 )
goto V_117;
}
V_55 = 0 ;
F_416 ( V_92 , V_760 , V_763 , V_761 ) ;
F_2 ( L_76 , V_14 ,
V_92 , V_92 -> V_114 , V_92 -> V_97 ) ;
V_117:
F_2 ( L_77 , V_14 , V_55 ) ;
return V_55 ;
}
static void F_418 ( struct V_103 * V_127 )
{
if ( V_127 -> V_107 . V_114 != NULL ) {
F_86 ( V_127 -> V_107 . V_114 ) ;
V_127 -> V_107 . V_114 = NULL ;
}
if ( V_127 -> V_109 . V_114 != NULL ) {
F_86 ( V_127 -> V_109 . V_114 ) ;
V_127 -> V_109 . V_114 = NULL ;
}
return;
}
static int F_419 ( struct V_103 * V_104 )
{
struct V_91 * V_92 ;
int V_263 ;
F_2 ( L_17 , V_14 ) ;
V_92 = & V_104 -> V_107 ;
V_263 = F_417 ( V_92 , V_104 -> V_764 . V_763 , 1 ) ;
if ( V_263 )
return V_263 ;
V_92 = & V_104 -> V_109 ;
V_263 = F_417 ( V_92 , V_104 -> V_765 . V_763 , 0 ) ;
if ( V_263 && V_92 -> V_114 == NULL )
F_418 ( V_104 ) ;
return V_263 ;
}
struct V_103 * F_420 ( struct V_32 * V_33 )
{
struct V_103 * V_127 ;
struct V_91 * V_92 ;
V_127 = F_78 ( sizeof( struct V_103 ) , V_261 ) ;
if ( ! V_127 )
return NULL ;
V_92 = & V_127 -> V_107 ;
V_92 -> V_96 = V_98 ;
F_421 ( & V_92 -> V_113 ) ;
F_422 ( & V_92 -> V_108 , L_78 ) ;
F_423 ( & V_92 -> F_38 ) ;
V_92 = & V_127 -> V_109 ;
V_92 -> V_96 = V_98 ;
F_421 ( & V_92 -> V_113 ) ;
F_424 ( & V_92 -> V_108 , L_79 ) ;
F_423 ( & V_92 -> F_38 ) ;
V_127 -> V_106 = 1 << V_766 ;
V_127 -> V_33 = V_33 ;
return V_127 ;
}
void F_425 ( struct V_103 * V_127 )
{
struct V_767 * V_768 ;
struct V_271 * V_299 ;
V_299 = F_409 ( V_127 -> V_33 ) ;
F_426 ( V_127 , V_299 ) ;
if ( V_299 )
F_410 ( V_299 ) ;
F_112 () ;
V_768 = F_113 ( V_127 -> V_33 -> V_525 -> V_769 ) ;
F_115 () ;
F_2 ( L_80 ,
V_14 , V_768 ) ;
F_427 ( V_768 , V_770 ) ;
F_418 ( V_127 ) ;
F_86 ( V_127 ) ;
}
static void F_428 ( struct V_771 * args )
{
struct V_103 * V_127 = args -> V_81 -> V_74 ;
unsigned int V_772 = V_127 -> V_764 . V_773 ,
V_774 = V_127 -> V_764 . V_775 ;
if ( V_772 == 0 )
V_772 = V_776 ;
if ( V_774 == 0 )
V_774 = V_776 ;
args -> V_764 . V_773 = V_772 ;
args -> V_764 . V_775 = V_774 ;
args -> V_764 . V_777 = V_778 ;
args -> V_764 . V_763 = V_779 ;
F_2 ( L_81
L_82 ,
V_14 ,
args -> V_764 . V_773 , args -> V_764 . V_775 ,
args -> V_764 . V_777 , args -> V_764 . V_763 ) ;
args -> V_765 . V_773 = V_536 ;
args -> V_765 . V_775 = V_536 ;
args -> V_765 . V_780 = 0 ;
args -> V_765 . V_777 = V_781 ;
args -> V_765 . V_763 = 1 ;
F_2 ( L_83
L_84 ,
V_14 ,
args -> V_765 . V_773 , args -> V_765 . V_775 ,
args -> V_765 . V_780 , args -> V_765 . V_777 ,
args -> V_765 . V_763 ) ;
}
static int F_429 ( struct V_771 * args , struct V_103 * V_127 )
{
struct V_782 * V_783 = & args -> V_764 ;
struct V_782 * V_784 = & V_127 -> V_764 ;
if ( V_784 -> V_775 > V_783 -> V_775 )
return - V_8 ;
if ( V_784 -> V_777 < V_783 -> V_777 )
return - V_8 ;
if ( V_784 -> V_763 == 0 )
return - V_8 ;
if ( V_784 -> V_763 > V_94 )
V_784 -> V_763 = V_94 ;
return 0 ;
}
static int F_430 ( struct V_771 * args , struct V_103 * V_127 )
{
struct V_782 * V_783 = & args -> V_765 ;
struct V_782 * V_784 = & V_127 -> V_765 ;
if ( V_784 -> V_773 > V_783 -> V_773 )
return - V_8 ;
if ( V_784 -> V_775 < V_783 -> V_775 )
return - V_8 ;
if ( V_784 -> V_780 > V_783 -> V_780 )
return - V_8 ;
if ( V_784 -> V_777 != V_783 -> V_777 )
return - V_8 ;
if ( V_784 -> V_763 != V_783 -> V_763 )
return - V_8 ;
return 0 ;
}
static int F_431 ( struct V_771 * args ,
struct V_103 * V_127 )
{
int V_55 ;
V_55 = F_429 ( args , V_127 ) ;
if ( V_55 )
return V_55 ;
return F_430 ( args , V_127 ) ;
}
static int F_432 ( struct V_32 * V_33 ,
struct V_271 * V_299 )
{
struct V_103 * V_127 = V_33 -> V_74 ;
struct V_771 args = {
. V_81 = V_33 ,
. V_785 = V_786 ,
} ;
struct V_787 V_34 = {
. V_81 = V_33 ,
} ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_788 ] ,
. V_269 = & args ,
. V_270 = & V_34 ,
. V_271 = V_299 ,
} ;
int V_263 ;
F_428 ( & args ) ;
args . V_180 = ( V_789 | V_790 ) ;
V_263 = F_67 ( V_127 -> V_33 -> V_525 , & V_141 , V_605 ) ;
if ( ! V_263 )
V_263 = F_431 ( & args , V_127 ) ;
if ( ! V_263 ) {
V_33 -> V_739 ++ ;
}
return V_263 ;
}
int F_433 ( struct V_32 * V_33 , struct V_271 * V_299 )
{
int V_263 ;
unsigned * V_791 ;
struct V_103 * V_127 = V_33 -> V_74 ;
F_2 ( L_85 , V_14 , V_33 , V_127 ) ;
V_263 = F_432 ( V_33 , V_299 ) ;
if ( V_263 )
goto V_117;
V_263 = F_419 ( V_127 ) ;
F_2 ( L_86 , V_263 ) ;
if ( V_263 )
goto V_117;
V_791 = ( unsigned * ) & V_127 -> V_721 . V_136 [ 0 ] ;
F_2 ( L_87 , V_14 ,
V_33 -> V_739 , V_791 [ 0 ] , V_791 [ 1 ] , V_791 [ 2 ] , V_791 [ 3 ] ) ;
V_117:
F_2 ( L_72 , V_14 ) ;
return V_263 ;
}
int F_426 ( struct V_103 * V_127 ,
struct V_271 * V_299 )
{
struct V_140 V_141 = {
. V_266 = & V_267 [ V_792 ] ,
. V_269 = V_127 ,
. V_271 = V_299 ,
} ;
int V_263 = 0 ;
F_2 ( L_88 ) ;
if ( V_127 -> V_33 -> V_39 != V_793 )
return V_263 ;
V_263 = F_67 ( V_127 -> V_33 -> V_525 , & V_141 , V_605 ) ;
if ( V_263 )
F_2 ( L_89
L_90 , V_263 ) ;
F_2 ( L_91 ) ;
return V_263 ;
}
static int F_434 ( struct V_32 * V_33 )
{
int V_55 ;
if ( V_33 -> V_39 == V_794 ) {
V_55 = F_168 ( V_33 ) ;
if ( V_55 )
return V_55 ;
}
if ( V_33 -> V_39 < V_793 )
return - V_12 ;
F_140 () ;
return 0 ;
}
int F_435 ( struct V_47 * V_48 )
{
struct V_32 * V_33 = V_48 -> V_32 ;
struct V_103 * V_127 ;
unsigned int V_795 , V_796 ;
if ( ! F_436 ( V_33 ) )
return 0 ;
V_127 = V_33 -> V_74 ;
F_26 ( & V_33 -> V_89 ) ;
if ( F_437 ( V_766 , & V_127 -> V_106 ) ) {
V_795 = V_48 -> V_795 ;
if ( V_795 == 0 )
V_795 = V_776 ;
V_796 = V_48 -> V_796 ;
if ( V_796 == 0 )
V_796 = V_776 ;
V_127 -> V_764 . V_773 = V_796 + V_797 ;
V_127 -> V_764 . V_775 = V_795 + V_798 ;
}
F_28 ( & V_33 -> V_89 ) ;
return F_434 ( V_33 ) ;
}
int F_438 ( struct V_32 * V_33 , unsigned long V_608 )
{
struct V_103 * V_127 = V_33 -> V_74 ;
int V_55 ;
F_26 ( & V_33 -> V_89 ) ;
if ( F_437 ( V_766 , & V_127 -> V_106 ) ) {
V_33 -> V_607 = V_608 ;
V_33 -> V_90 = V_133 ;
}
F_28 ( & V_33 -> V_89 ) ;
V_55 = F_434 ( V_33 ) ;
if ( V_55 )
return V_55 ;
if ( ! F_439 ( V_33 ) )
return - V_799 ;
return 0 ;
}
static void F_440 ( void * V_136 )
{
struct V_800 * V_134 = V_136 ;
struct V_32 * V_33 = V_134 -> V_33 ;
if ( F_311 ( & V_33 -> V_519 ) > 1 )
F_312 ( V_33 ) ;
F_313 ( V_33 ) ;
F_86 ( V_134 ) ;
}
static int F_441 ( struct V_99 * V_100 , struct V_32 * V_33 )
{
switch( V_100 -> V_150 ) {
case - V_79 :
F_44 ( V_100 , V_44 ) ;
return - V_130 ;
default:
F_21 ( V_33 ) ;
}
return 0 ;
}
static void F_442 ( struct V_99 * V_100 , void * V_136 )
{
struct V_800 * V_134 = V_136 ;
struct V_32 * V_33 = V_134 -> V_33 ;
if ( ! F_41 ( V_100 , V_100 -> V_280 . V_270 ) )
return;
if ( V_100 -> V_150 < 0 ) {
F_2 ( L_92 , V_14 , V_100 -> V_150 ) ;
if ( F_311 ( & V_33 -> V_519 ) == 1 )
goto V_117;
if ( F_441 ( V_100 , V_33 ) == - V_130 ) {
F_200 ( V_100 ) ;
return;
}
}
F_2 ( L_93 , V_14 , V_100 -> V_280 . V_271 ) ;
V_117:
F_2 ( L_72 , V_14 ) ;
}
static void F_443 ( struct V_99 * V_100 , void * V_136 )
{
struct V_800 * V_134 = V_136 ;
struct V_32 * V_33 = V_134 -> V_33 ;
struct V_123 * args ;
struct V_110 * V_34 ;
args = V_100 -> V_280 . V_269 ;
V_34 = V_100 -> V_280 . V_270 ;
if ( F_50 ( V_33 -> V_74 , args , V_34 , V_100 ) )
return;
F_57 ( V_100 ) ;
}
static struct V_99 * F_444 ( struct V_32 * V_33 , struct V_271 * V_299 )
{
struct V_800 * V_134 ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_801 ] ,
. V_271 = V_299 ,
} ;
struct V_143 V_272 = {
. V_145 = V_33 -> V_525 ,
. V_140 = & V_141 ,
. V_146 = & V_802 ,
. V_180 = V_276 | V_526 ,
} ;
if ( ! F_317 ( & V_33 -> V_519 ) )
return F_119 ( - V_15 ) ;
V_134 = F_78 ( sizeof( * V_134 ) , V_261 ) ;
if ( V_134 == NULL ) {
F_313 ( V_33 ) ;
return F_119 ( - V_253 ) ;
}
F_49 ( & V_134 -> args , & V_134 -> V_34 , 0 ) ;
V_141 . V_269 = & V_134 -> args ;
V_141 . V_270 = & V_134 -> V_34 ;
V_134 -> V_33 = V_33 ;
V_272 . V_148 = V_134 ;
return F_61 ( & V_272 ) ;
}
static int F_445 ( struct V_32 * V_33 , struct V_271 * V_299 , unsigned V_523 )
{
struct V_99 * V_100 ;
int V_55 = 0 ;
if ( ( V_523 & V_803 ) == 0 )
return 0 ;
V_100 = F_444 ( V_33 , V_299 ) ;
if ( F_62 ( V_100 ) )
V_55 = F_63 ( V_100 ) ;
else
F_376 ( V_100 ) ;
F_2 ( L_23 , V_14 , V_55 ) ;
return V_55 ;
}
static int F_446 ( struct V_32 * V_33 , struct V_271 * V_299 )
{
struct V_99 * V_100 ;
int V_55 ;
V_100 = F_444 ( V_33 , V_299 ) ;
if ( F_62 ( V_100 ) ) {
V_55 = F_63 ( V_100 ) ;
goto V_117;
}
V_55 = F_98 ( V_100 ) ;
if ( ! V_55 ) {
struct V_110 * V_34 = V_100 -> V_280 . V_270 ;
if ( V_100 -> V_150 == 0 )
F_447 ( V_33 , V_34 -> V_120 ) ;
V_55 = V_100 -> V_150 ;
}
F_64 ( V_100 ) ;
V_117:
F_2 ( L_23 , V_14 , V_55 ) ;
return V_55 ;
}
static void F_448 ( struct V_99 * V_100 , void * V_136 )
{
struct V_804 * V_134 = V_136 ;
F_34 ( V_100 , V_102 ) ;
if ( F_50 ( V_134 -> V_33 -> V_74 ,
& V_134 -> V_337 . V_138 ,
& V_134 -> V_34 . V_139 , V_100 ) )
return;
F_57 ( V_100 ) ;
}
static int F_449 ( struct V_99 * V_100 , struct V_32 * V_33 )
{
switch( V_100 -> V_150 ) {
case 0 :
case - V_805 :
case - V_806 :
break;
case - V_79 :
F_44 ( V_100 , V_44 ) ;
case - V_82 :
return - V_130 ;
default:
F_21 ( V_33 ) ;
}
return 0 ;
}
static void F_450 ( struct V_99 * V_100 , void * V_136 )
{
struct V_804 * V_134 = V_136 ;
struct V_32 * V_33 = V_134 -> V_33 ;
struct V_110 * V_34 = & V_134 -> V_34 . V_139 ;
F_2 ( L_17 , V_14 ) ;
if ( ! F_41 ( V_100 , V_34 ) )
return;
if ( F_449 ( V_100 , V_33 ) == - V_130 ) {
F_200 ( V_100 ) ;
return;
}
F_2 ( L_72 , V_14 ) ;
}
static void F_451 ( void * V_136 )
{
struct V_804 * V_134 = V_136 ;
F_86 ( V_134 ) ;
}
static int F_452 ( struct V_32 * V_33 )
{
struct V_804 * V_134 ;
struct V_99 * V_100 ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_807 ] ,
} ;
struct V_143 V_272 = {
. V_145 = V_33 -> V_525 ,
. V_140 = & V_141 ,
. V_146 = & V_808 ,
. V_180 = V_276 ,
} ;
int V_263 = - V_253 ;
F_2 ( L_17 , V_14 ) ;
V_134 = F_78 ( sizeof( * V_134 ) , V_261 ) ;
if ( V_134 == NULL )
goto V_117;
V_134 -> V_33 = V_33 ;
V_134 -> V_337 . V_809 = 0 ;
F_49 ( & V_134 -> V_337 . V_138 , & V_134 -> V_34 . V_139 , 0 ) ;
V_141 . V_269 = & V_134 -> V_337 ;
V_141 . V_270 = & V_134 -> V_34 ;
V_272 . V_148 = V_134 ;
V_100 = F_61 ( & V_272 ) ;
if ( F_62 ( V_100 ) ) {
V_263 = F_63 ( V_100 ) ;
goto V_117;
}
V_263 = F_97 ( V_100 ) ;
if ( V_263 == 0 )
V_263 = V_100 -> V_150 ;
F_64 ( V_100 ) ;
return 0 ;
V_117:
F_2 ( L_23 , V_14 , V_263 ) ;
return V_263 ;
}
static void
F_453 ( struct V_99 * V_100 , void * V_134 )
{
struct V_810 * V_811 = V_134 ;
struct V_47 * V_48 = F_77 ( V_811 -> args . V_54 ) ;
F_2 ( L_17 , V_14 ) ;
if ( F_54 ( V_48 , & V_811 -> args . V_138 ,
& V_811 -> V_34 . V_139 , V_100 ) )
return;
if ( F_454 ( & V_811 -> args . V_216 ,
F_70 ( V_811 -> args . V_54 ) -> V_812 ,
V_811 -> args . V_259 -> V_53 ) ) {
F_455 ( V_100 , V_813 ) ;
return;
}
F_57 ( V_100 ) ;
}
static void F_456 ( struct V_99 * V_100 , void * V_134 )
{
struct V_810 * V_811 = V_134 ;
struct V_54 * V_54 = V_811 -> args . V_54 ;
struct V_47 * V_48 = F_77 ( V_54 ) ;
struct V_814 * V_815 ;
struct V_52 * V_53 = NULL ;
F_2 ( L_17 , V_14 ) ;
if ( ! F_45 ( V_100 , & V_811 -> V_34 . V_139 ) )
goto V_117;
switch ( V_100 -> V_150 ) {
case 0 :
goto V_117;
case - V_816 :
case - V_817 :
V_100 -> V_150 = - V_79 ;
break;
case - V_63 :
case - V_62 :
F_26 ( & V_54 -> V_158 ) ;
V_815 = F_70 ( V_54 ) -> V_812 ;
if ( ! V_815 || F_457 ( & V_815 -> V_818 ) ) {
F_28 ( & V_54 -> V_158 ) ;
V_53 = V_811 -> args . V_259 -> V_53 ;
} else {
F_458 ( V_819 ) ;
F_459 ( V_815 , & V_819 , NULL ) ;
F_28 ( & V_54 -> V_158 ) ;
F_460 ( & V_819 ) ;
}
}
if ( F_199 ( V_100 , V_48 , V_53 ) == - V_130 )
F_200 ( V_100 ) ;
V_117:
F_2 ( L_72 , V_14 ) ;
}
static T_9 F_461 ( struct V_47 * V_48 )
{
T_3 V_775 = V_48 -> V_32 -> V_74 -> V_764 . V_775 ;
return F_462 ( 0 , V_775 ) ;
}
static void F_463 ( struct V_412 * * V_24 , T_9 V_820 )
{
int V_399 ;
if ( ! V_24 )
return;
for ( V_399 = 0 ; V_399 < V_820 ; V_399 ++ ) {
if ( ! V_24 [ V_399 ] )
break;
F_230 ( V_24 [ V_399 ] ) ;
}
F_86 ( V_24 ) ;
}
static struct V_412 * * F_464 ( T_9 V_820 , T_5 V_759 )
{
struct V_412 * * V_24 ;
int V_399 ;
V_24 = F_415 ( V_820 , sizeof( struct V_412 * ) , V_759 ) ;
if ( ! V_24 ) {
F_2 ( L_94 , V_14 , V_820 ) ;
return NULL ;
}
for ( V_399 = 0 ; V_399 < V_820 ; V_399 ++ ) {
V_24 [ V_399 ] = F_226 ( V_759 ) ;
if ( ! V_24 [ V_399 ] ) {
F_2 ( L_95 , V_14 ) ;
F_463 ( V_24 , V_820 ) ;
return NULL ;
}
}
return V_24 ;
}
static void F_465 ( void * V_134 )
{
struct V_810 * V_811 = V_134 ;
struct V_47 * V_48 = F_77 ( V_811 -> args . V_54 ) ;
T_9 V_821 = F_461 ( V_48 ) ;
F_2 ( L_17 , V_14 ) ;
F_463 ( V_811 -> args . V_812 . V_24 , V_821 ) ;
F_144 ( V_811 -> args . V_259 ) ;
F_86 ( V_134 ) ;
F_2 ( L_72 , V_14 ) ;
}
struct V_822 *
F_466 ( struct V_810 * V_811 , T_5 V_759 )
{
struct V_47 * V_48 = F_77 ( V_811 -> args . V_54 ) ;
T_9 V_821 = F_461 ( V_48 ) ;
struct V_99 * V_100 ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_823 ] ,
. V_269 = & V_811 -> args ,
. V_270 = & V_811 -> V_34 ,
} ;
struct V_143 V_272 = {
. V_145 = V_48 -> V_81 ,
. V_140 = & V_141 ,
. V_146 = & V_824 ,
. V_148 = V_811 ,
. V_180 = V_276 ,
} ;
struct V_822 * V_825 = NULL ;
int V_263 = 0 ;
F_2 ( L_17 , V_14 ) ;
V_811 -> args . V_812 . V_24 = F_464 ( V_821 , V_759 ) ;
if ( ! V_811 -> args . V_812 . V_24 ) {
F_465 ( V_811 ) ;
return F_119 ( - V_253 ) ;
}
V_811 -> args . V_812 . V_439 = V_821 * V_536 ;
V_811 -> V_34 . V_826 = & V_811 -> args . V_812 ;
V_811 -> V_34 . V_139 . V_112 = NULL ;
F_49 ( & V_811 -> args . V_138 , & V_811 -> V_34 . V_139 , 0 ) ;
V_100 = F_61 ( & V_272 ) ;
if ( F_62 ( V_100 ) )
return F_206 ( V_100 ) ;
V_263 = F_97 ( V_100 ) ;
if ( V_263 == 0 )
V_263 = V_100 -> V_150 ;
if ( V_263 == 0 )
V_825 = F_467 ( V_811 ) ;
F_64 ( V_100 ) ;
F_2 ( L_23 , V_14 , V_263 ) ;
if ( V_263 )
return F_119 ( V_263 ) ;
return V_825 ;
}
static void
F_468 ( struct V_99 * V_100 , void * V_134 )
{
struct V_827 * V_828 = V_134 ;
F_2 ( L_17 , V_14 ) ;
if ( F_50 ( V_828 -> V_33 -> V_74 , & V_828 -> args . V_138 ,
& V_828 -> V_34 . V_139 , V_100 ) )
return;
F_57 ( V_100 ) ;
}
static void F_469 ( struct V_99 * V_100 , void * V_134 )
{
struct V_827 * V_828 = V_134 ;
struct V_47 * V_48 ;
F_2 ( L_17 , V_14 ) ;
if ( ! F_45 ( V_100 , & V_828 -> V_34 . V_139 ) )
return;
V_48 = F_77 ( V_828 -> args . V_54 ) ;
if ( F_199 ( V_100 , V_48 , NULL ) == - V_130 ) {
F_200 ( V_100 ) ;
return;
}
F_2 ( L_72 , V_14 ) ;
}
static void F_470 ( void * V_134 )
{
struct V_827 * V_828 = V_134 ;
struct V_814 * V_815 = V_828 -> args . V_812 ;
F_2 ( L_17 , V_14 ) ;
F_26 ( & V_815 -> V_829 -> V_158 ) ;
if ( V_828 -> V_34 . V_830 )
F_471 ( V_815 , & V_828 -> V_34 . V_216 , true ) ;
V_815 -> V_831 -- ;
F_28 ( & V_815 -> V_829 -> V_158 ) ;
F_472 ( V_828 -> args . V_812 ) ;
F_86 ( V_134 ) ;
F_2 ( L_72 , V_14 ) ;
}
int F_473 ( struct V_827 * V_828 )
{
struct V_99 * V_100 ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_832 ] ,
. V_269 = & V_828 -> args ,
. V_270 = & V_828 -> V_34 ,
} ;
struct V_143 V_272 = {
. V_145 = V_828 -> V_33 -> V_525 ,
. V_140 = & V_141 ,
. V_146 = & V_833 ,
. V_148 = V_828 ,
} ;
int V_263 ;
F_2 ( L_17 , V_14 ) ;
F_49 ( & V_828 -> args . V_138 , & V_828 -> V_34 . V_139 , 1 ) ;
V_100 = F_61 ( & V_272 ) ;
if ( F_62 ( V_100 ) )
return F_63 ( V_100 ) ;
V_263 = V_100 -> V_150 ;
F_2 ( L_23 , V_14 , V_263 ) ;
F_64 ( V_100 ) ;
return V_263 ;
}
static int F_474 ( struct V_47 * V_48 ,
const struct V_363 * V_190 ,
struct V_834 * V_835 )
{
struct V_836 args = {
. V_190 = V_190 ,
. V_837 = V_48 -> V_838 -> V_200 ,
} ;
struct V_839 V_34 = {
. V_835 = V_835 ,
} ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_840 ] ,
. V_269 = & args ,
. V_270 = & V_34 ,
} ;
int V_263 ;
F_2 ( L_17 , V_14 ) ;
V_263 = F_68 ( V_48 -> V_81 , V_48 , & V_141 , & args . V_138 ,
& V_34 . V_139 , 0 ) ;
F_2 ( L_23 , V_14 , V_263 ) ;
return V_263 ;
}
int F_475 ( struct V_47 * V_48 ,
const struct V_363 * V_190 ,
struct V_834 * V_835 )
{
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_48 ,
F_474 ( V_48 , V_190 , V_835 ) ,
& V_51 ) ;
} while ( V_51 . V_56 );
F_2 ( L_96 , V_14 ,
V_1 , V_835 -> V_841 ) ;
return V_1 ;
}
static int
F_476 ( struct V_47 * V_48 , struct V_842 * V_843 )
{
struct V_844 args = {
. V_843 = V_843 ,
} ;
struct V_845 V_34 = {
. V_843 = V_843 ,
} ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_846 ] ,
. V_269 = & args ,
. V_270 = & V_34 ,
} ;
int V_263 ;
F_2 ( L_17 , V_14 ) ;
V_263 = F_68 ( V_48 -> V_81 , V_48 , & V_141 , & args . V_138 , & V_34 . V_139 , 0 ) ;
F_2 ( L_23 , V_14 , V_263 ) ;
return V_263 ;
}
int F_477 ( struct V_47 * V_48 , struct V_842 * V_843 )
{
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_16 ( V_48 ,
F_476 ( V_48 , V_843 ) ,
& V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static void F_478 ( struct V_99 * V_100 , void * V_134 )
{
struct V_847 * V_136 = V_134 ;
struct V_47 * V_48 = F_77 ( V_136 -> args . V_54 ) ;
if ( F_54 ( V_48 , & V_136 -> args . V_138 ,
& V_136 -> V_34 . V_139 , V_100 ) )
return;
F_57 ( V_100 ) ;
}
static void
F_479 ( struct V_99 * V_100 , void * V_134 )
{
struct V_847 * V_136 = V_134 ;
struct V_47 * V_48 = F_77 ( V_136 -> args . V_54 ) ;
if ( ! F_45 ( V_100 , & V_136 -> V_34 . V_139 ) )
return;
switch ( V_100 -> V_150 ) {
case - V_60 :
case - V_848 :
case - V_849 :
case - V_78 :
V_100 -> V_150 = 0 ;
break;
case 0 :
F_301 ( V_136 -> args . V_54 ,
V_136 -> V_34 . V_335 ) ;
break;
default:
if ( F_199 ( V_100 , V_48 , NULL ) == - V_130 ) {
F_200 ( V_100 ) ;
return;
}
}
}
static void F_480 ( void * V_134 )
{
struct V_847 * V_136 = V_134 ;
struct V_822 * V_825 , * V_850 ;
unsigned long * V_851 = & F_70 ( V_136 -> args . V_54 ) -> V_180 ;
F_481 ( V_136 ) ;
F_482 (lseg, tmp, &data->lseg_list, pls_lc_list) {
F_483 ( & V_825 -> V_852 ) ;
if ( F_437 ( V_853 ,
& V_825 -> V_854 ) )
F_484 ( V_825 ) ;
}
F_485 ( V_855 , V_851 ) ;
F_486 () ;
F_487 ( V_851 , V_855 ) ;
F_410 ( V_136 -> V_299 ) ;
F_86 ( V_136 ) ;
}
int
F_488 ( struct V_847 * V_136 , bool V_856 )
{
struct V_140 V_141 = {
. V_266 = & V_267 [ V_857 ] ,
. V_269 = & V_136 -> args ,
. V_270 = & V_136 -> V_34 ,
. V_271 = V_136 -> V_299 ,
} ;
struct V_143 V_272 = {
. V_100 = & V_136 -> V_100 ,
. V_145 = F_241 ( V_136 -> args . V_54 ) ,
. V_140 = & V_141 ,
. V_146 = & V_858 ,
. V_148 = V_136 ,
. V_180 = V_276 ,
} ;
struct V_99 * V_100 ;
int V_263 = 0 ;
F_2 ( L_97
L_98 ,
V_136 -> V_100 . V_859 , V_856 ,
V_136 -> args . V_860 ,
V_136 -> args . V_54 -> V_861 ) ;
F_49 ( & V_136 -> args . V_138 , & V_136 -> V_34 . V_139 , 1 ) ;
V_100 = F_61 ( & V_272 ) ;
if ( F_62 ( V_100 ) )
return F_63 ( V_100 ) ;
if ( V_856 == false )
goto V_117;
V_263 = F_97 ( V_100 ) ;
if ( V_263 != 0 )
goto V_117;
V_263 = V_100 -> V_150 ;
V_117:
F_2 ( L_99 , V_14 , V_263 ) ;
F_64 ( V_100 ) ;
return V_263 ;
}
static int
F_489 ( struct V_47 * V_48 , struct V_363 * V_364 ,
struct V_391 * V_392 , struct V_703 * V_704 )
{
struct V_862 args = {
. V_863 = V_864 ,
} ;
struct V_706 V_34 = {
. V_704 = V_704 ,
} ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_865 ] ,
. V_269 = & args ,
. V_270 = & V_34 ,
} ;
return F_68 ( V_48 -> V_81 , V_48 , & V_141 , & args . V_138 , & V_34 . V_139 , 0 ) ;
}
static int
F_490 ( struct V_47 * V_48 , struct V_363 * V_364 ,
struct V_391 * V_392 , struct V_703 * V_704 )
{
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_489 ( V_48 , V_364 , V_392 , V_704 ) ;
switch ( V_1 ) {
case 0 :
case - V_4 :
case - V_866 :
goto V_117;
default:
V_1 = F_16 ( V_48 , V_1 , & V_51 ) ;
}
} while ( V_51 . V_56 );
V_117:
return V_1 ;
}
static int
F_491 ( struct V_47 * V_48 , struct V_363 * V_364 ,
struct V_391 * V_392 )
{
int V_1 ;
struct V_412 * V_412 ;
T_7 V_396 ;
struct V_703 * V_704 ;
V_412 = F_226 ( V_325 ) ;
if ( ! V_412 ) {
V_1 = - V_253 ;
goto V_117;
}
V_704 = F_323 ( V_412 ) ;
V_1 = F_490 ( V_48 , V_364 , V_392 , V_704 ) ;
if ( V_1 == - V_4 || V_1 == - V_866 ) {
V_1 = F_216 ( V_48 , V_364 , V_392 ) ;
goto V_867;
}
if ( V_1 )
goto V_867;
V_396 = F_492 ( V_704 ) ;
if ( V_1 == 0 )
V_1 = F_214 ( V_48 , V_364 , V_392 , V_396 ) ;
V_867:
F_336 ( V_412 ) ;
if ( V_1 == - V_10 )
return - V_5 ;
V_117:
return V_1 ;
}
static int F_493 ( struct V_47 * V_48 , T_6 * V_216 )
{
int V_263 ;
struct V_868 args = {
. V_216 = V_216 ,
} ;
struct V_869 V_34 ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_870 ] ,
. V_269 = & args ,
. V_270 = & V_34 ,
} ;
F_2 ( L_100 , V_216 ) ;
F_49 ( & args . V_138 , & V_34 . V_139 , 0 ) ;
V_263 = F_60 ( V_48 -> V_81 , V_48 , & V_141 , & args . V_138 , & V_34 . V_139 , 1 ) ;
if ( V_263 != V_116 ) {
F_2 ( L_101 , V_263 ) ;
return V_263 ;
}
F_2 ( L_102 , - V_34 . V_263 ) ;
return - V_34 . V_263 ;
}
static int F_176 ( struct V_47 * V_48 , T_6 * V_216 )
{
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_493 ( V_48 , V_216 ) ;
if ( V_1 != - V_79 )
break;
F_16 ( V_48 , V_1 , & V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static int F_494 ( struct V_47 * V_48 , T_6 * V_216 )
{
struct V_871 args = {
. V_216 = V_216 ,
} ;
struct V_872 V_34 ;
struct V_140 V_141 = {
. V_266 = & V_267 [ V_873 ] ,
. V_269 = & args ,
. V_270 = & V_34 ,
} ;
int V_263 ;
F_2 ( L_103 , V_216 ) ;
F_49 ( & args . V_138 , & V_34 . V_139 , 0 ) ;
V_263 = F_60 ( V_48 -> V_81 , V_48 , & V_141 ,
& args . V_138 , & V_34 . V_139 , 1 ) ;
F_2 ( L_104 , V_263 ) ;
return V_263 ;
}
static int F_177 ( struct V_47 * V_48 , T_6 * V_216 )
{
struct V_50 V_51 = { } ;
int V_1 ;
do {
V_1 = F_494 ( V_48 , V_216 ) ;
if ( V_1 != - V_79 )
break;
F_16 ( V_48 , V_1 , & V_51 ) ;
} while ( V_51 . V_56 );
return V_1 ;
}
static bool F_495 ( const T_6 * V_874 ,
const T_6 * V_875 )
{
if ( memcmp ( V_874 -> V_876 , V_875 -> V_876 , sizeof( V_874 -> V_876 ) ) != 0 )
return false ;
if ( V_874 -> V_169 == V_875 -> V_169 )
return true ;
if ( V_874 -> V_169 == 0 || V_875 -> V_169 == 0 )
return true ;
return false ;
}
static bool F_496 ( const T_6 * V_874 ,
const T_6 * V_875 )
{
return F_114 ( V_874 , V_875 ) ;
}
