static inline struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
int V_8 ;
if ( V_7 == NULL )
return NULL ;
if ( F_2 ( V_3 , V_9 ) == 0 )
return NULL ;
V_8 = F_3 ( V_4 , V_6 -> V_10 ,
& V_4 -> V_11 , ( void * * ) & V_7 -> V_7 , & V_7 -> V_12 ) ;
if ( V_8 == 0 )
return V_7 ;
return NULL ;
}
static inline void
F_4 ( struct V_1 * V_7 )
{
if ( V_7 )
F_5 ( V_7 -> V_7 , V_7 -> V_12 ) ;
}
static inline T_1 * F_6 ( struct V_13 * V_14 , struct V_1 * V_7 )
{
if ( V_7 )
return V_14 -> V_15 ;
return V_14 -> V_16 ;
}
static inline struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_17 )
{ return NULL ; }
static inline void
F_4 ( struct V_1 * V_7 )
{ return; }
static inline T_1 *
F_6 ( struct V_13 * V_14 , struct V_1 * V_7 )
{ return V_14 -> V_15 ; }
static int F_7 ( int V_8 )
{
if ( V_8 >= - 1000 )
return V_8 ;
switch ( V_8 ) {
case - V_18 :
case - V_19 :
case - V_20 :
return - V_21 ;
case - V_22 :
case - V_23 :
return - V_24 ;
case - V_25 :
case - V_26 :
return - V_27 ;
case - V_28 :
return - V_29 ;
case - V_30 :
return - V_31 ;
case - V_32 :
return - V_33 ;
default:
F_8 ( L_1 ,
V_34 , - V_8 ) ;
break;
}
return - V_35 ;
}
static void F_9 ( T_2 V_36 , T_3 * V_37 , struct V_4 * V_4 ,
struct V_38 * V_39 )
{
T_3 * V_40 , * V_41 ;
if ( V_36 > 2 ) {
V_39 -> V_36 = V_36 ;
memcpy ( & V_39 -> V_37 , V_37 , sizeof( V_39 -> V_37 ) ) ;
return;
}
V_39 -> V_36 = 0 ;
memset ( & V_39 -> V_37 , 0 , sizeof( V_39 -> V_37 ) ) ;
if ( V_36 == 2 )
return;
V_40 = V_41 = F_10 ( * V_39 -> V_42 ) ;
if ( V_36 == 0 ) {
* V_41 ++ = V_43 ;
* V_41 ++ = V_44 ;
* V_41 ++ = V_43 ;
* V_41 ++ = V_43 ;
memcpy ( V_41 , L_2 , 4 ) ;
V_41 ++ ;
* V_41 ++ = V_43 ;
* V_41 ++ = F_11 ( V_45 ) ;
* V_41 ++ = F_11 ( 8 ) ;
V_41 = F_12 ( V_41 , F_13 ( F_14 ( V_4 ) ) ) ;
}
* V_41 ++ = V_43 ;
* V_41 ++ = V_44 ;
* V_41 ++ = V_46 ;
* V_41 ++ = V_46 ;
memcpy ( V_41 , L_3 , 4 ) ;
V_41 ++ ;
* V_41 ++ = V_43 ;
* V_41 ++ = F_11 ( V_45 ) ;
* V_41 ++ = F_11 ( 8 ) ;
V_41 = F_12 ( V_41 , F_13 ( F_14 ( V_4 -> V_47 ) ) ) ;
V_39 -> V_48 = ( char * ) V_41 - ( char * ) V_40 ;
V_39 -> V_49 -= V_39 -> V_48 ;
F_15 ( V_40 ) ;
}
static long F_16 ( long * V_50 )
{
long V_51 ;
if ( ! V_50 )
return V_52 ;
if ( * V_50 <= 0 )
* V_50 = V_53 ;
if ( * V_50 > V_52 )
* V_50 = V_52 ;
V_51 = * V_50 ;
* V_50 <<= 1 ;
return V_51 ;
}
static int F_17 ( struct V_54 * V_55 , long * V_50 )
{
int V_56 = 0 ;
F_18 () ;
F_19 (
F_16 ( V_50 ) ) ;
if ( F_20 ( V_57 ) )
V_56 = - V_58 ;
return V_56 ;
}
static int F_21 ( struct V_13 * V_14 ,
int V_59 , struct V_60 * V_61 )
{
struct V_62 * V_63 = V_14 -> V_62 ;
struct V_64 * V_65 = V_61 -> V_65 ;
struct V_2 * V_2 = V_61 -> V_2 ;
int V_51 = V_59 ;
V_61 -> V_66 = 0 ;
V_61 -> V_67 = 0 ;
V_61 -> V_68 = 0 ;
switch( V_59 ) {
case 0 :
return 0 ;
case - V_69 :
case - V_70 :
case - V_71 :
case - V_72 :
if ( V_2 && F_22 ( V_2 ,
NULL ) == 0 )
goto V_73;
if ( V_65 == NULL )
break;
V_51 = F_23 ( V_14 , V_65 ) ;
if ( V_51 < 0 )
break;
goto V_73;
case - V_74 :
if ( V_65 != NULL ) {
V_51 = F_23 ( V_14 , V_65 ) ;
if ( V_51 < 0 )
break;
}
case - V_75 :
case - V_76 :
F_24 ( V_63 ) ;
goto V_73;
case - V_77 :
V_51 = F_25 ( V_14 ) ;
if ( V_51 < 0 )
break;
goto V_73;
case - V_78 :
F_26 ( V_63 ) ;
goto V_73;
#if F_27 ( V_79 )
case - V_80 :
case - V_81 :
case - V_82 :
case - V_83 :
case - V_84 :
case - V_85 :
case - V_86 :
F_8 ( L_4 , V_34 ,
V_59 ) ;
F_28 ( V_63 -> V_87 , V_59 ) ;
goto V_73;
#endif
case - V_32 :
if ( V_61 -> V_50 > V_88 ) {
V_51 = - V_33 ;
break;
}
case - V_89 :
F_29 ( V_14 , V_90 ) ;
case - V_91 :
V_61 -> V_66 = 1 ;
return 0 ;
case - V_92 :
case - V_93 :
V_61 -> V_68 = 1 ;
break;
case - V_25 :
case - V_26 :
if ( V_14 -> V_94 & V_95 ) {
V_14 -> V_94 &= ~ V_95 ;
V_61 -> V_68 = 1 ;
F_30 ( V_96 L_5
L_6
L_7
L_8 ,
V_14 -> V_62 -> V_97 ) ;
}
}
return F_7 ( V_51 ) ;
V_73:
V_61 -> V_67 = 1 ;
return 0 ;
}
int F_31 ( struct V_13 * V_14 , int V_59 , struct V_60 * V_61 )
{
struct V_62 * V_63 = V_14 -> V_62 ;
int V_51 ;
V_51 = F_21 ( V_14 , V_59 , V_61 ) ;
if ( V_61 -> V_66 ) {
V_51 = F_17 ( V_14 -> V_98 , & V_61 -> V_50 ) ;
goto V_99;
}
if ( V_61 -> V_67 ) {
V_51 = F_32 ( V_63 ) ;
if ( F_33 ( V_100 , & V_14 -> V_101 ) )
return - V_35 ;
goto V_99;
}
return V_51 ;
V_99:
if ( V_51 == 0 )
V_61 -> V_68 = 1 ;
return V_51 ;
}
static int
F_34 ( struct V_102 * V_103 , struct V_13 * V_14 ,
int V_59 , struct V_60 * V_61 )
{
struct V_62 * V_63 = V_14 -> V_62 ;
int V_51 ;
V_51 = F_21 ( V_14 , V_59 , V_61 ) ;
if ( V_61 -> V_66 ) {
F_35 ( V_103 , F_16 ( & V_61 -> V_50 ) ) ;
goto V_99;
}
if ( V_61 -> V_67 ) {
F_36 ( & V_63 -> V_104 , V_103 , NULL ) ;
if ( F_33 ( V_105 , & V_63 -> V_106 ) == 0 )
F_37 ( & V_63 -> V_104 , V_103 ) ;
goto V_99;
}
if ( F_33 ( V_100 , & V_14 -> V_101 ) )
V_51 = - V_35 ;
return V_51 ;
V_99:
if ( V_51 == 0 )
V_61 -> V_68 = 1 ;
return V_51 ;
}
static int
F_38 ( struct V_102 * V_103 , struct V_13 * V_14 ,
struct V_64 * V_65 , long * V_50 )
{
struct V_60 V_61 = {
. V_65 = V_65 ,
} ;
if ( V_103 -> V_107 >= 0 )
return 0 ;
if ( V_50 )
V_61 . V_50 = * V_50 ;
V_103 -> V_107 = F_34 ( V_103 , V_14 ,
V_103 -> V_107 ,
& V_61 ) ;
if ( V_61 . V_66 && V_50 )
* V_50 = V_61 . V_50 ;
if ( V_61 . V_68 )
return - V_108 ;
return 0 ;
}
static bool F_39 ( struct V_62 * V_63 )
{
T_4 V_109 = V_63 -> V_110 -> V_111 -> V_112 ;
if ( V_109 == V_113 ||
V_109 == V_114 )
return true ;
return false ;
}
static void F_40 ( struct V_62 * V_63 , unsigned long V_115 )
{
F_41 ( & V_63 -> V_116 ) ;
if ( F_42 ( V_63 -> V_117 , V_115 ) )
V_63 -> V_117 = V_115 ;
F_43 ( & V_63 -> V_116 ) ;
}
static void F_44 ( const struct V_13 * V_14 , unsigned long V_115 )
{
struct V_62 * V_63 = V_14 -> V_62 ;
if ( ! F_45 ( V_63 ) )
F_40 ( V_63 , V_115 ) ;
}
void F_46 ( struct V_118 * args ,
struct V_119 * V_56 , int V_120 )
{
args -> V_121 = NULL ;
args -> V_122 = V_120 ;
args -> V_123 = 0 ;
V_56 -> V_124 = NULL ;
}
static void F_47 ( struct V_118 * args )
{
args -> V_123 = 1 ;
}
int F_48 ( struct V_125 * V_126 ,
struct V_118 * args ,
struct V_119 * V_56 ,
struct V_102 * V_103 )
{
struct V_127 * V_128 ;
if ( V_56 -> V_124 != NULL )
goto V_129;
F_41 ( & V_126 -> V_130 ) ;
if ( F_49 ( V_126 ) && ! args -> V_123 )
goto V_131;
V_128 = F_50 ( V_126 ) ;
if ( F_51 ( V_128 ) ) {
if ( V_128 == F_52 ( - V_132 ) )
V_103 -> V_133 = V_88 >> 2 ;
goto V_131;
}
F_43 ( & V_126 -> V_130 ) ;
args -> V_121 = V_128 ;
V_56 -> V_124 = V_128 ;
V_129:
F_53 ( V_103 ) ;
return 0 ;
V_131:
if ( args -> V_123 )
F_54 ( & V_126 -> V_134 , V_103 ,
NULL , V_135 ) ;
else
F_36 ( & V_126 -> V_134 , V_103 , NULL ) ;
F_43 ( & V_126 -> V_130 ) ;
return - V_108 ;
}
static int F_55 ( struct V_102 * V_103 ,
struct V_119 * V_56 )
{
struct V_127 * V_128 = V_56 -> V_124 ;
struct V_125 * V_126 ;
if ( V_128 == NULL )
goto V_136;
V_126 = V_128 -> V_137 ;
F_41 ( & V_126 -> V_130 ) ;
if ( ! F_56 ( V_126 , V_128 ) )
F_57 ( V_126 , V_128 ) ;
F_43 ( & V_126 -> V_130 ) ;
V_56 -> V_124 = NULL ;
V_136:
return 1 ;
}
static void F_58 ( struct V_119 * V_56 )
{
struct V_138 * V_139 ;
struct V_125 * V_126 ;
struct V_127 * V_128 = V_56 -> V_124 ;
bool V_140 = false ;
V_126 = V_128 -> V_137 ;
V_139 = V_126 -> V_139 ;
F_41 ( & V_126 -> V_130 ) ;
if ( V_126 -> V_141 > V_126 -> V_142 )
V_140 = true ;
if ( F_56 ( V_126 , V_128 ) ) {
V_140 = false ;
goto V_143;
}
F_57 ( V_126 , V_128 ) ;
if ( V_126 -> V_141 != V_144 )
V_140 = false ;
V_143:
F_43 ( & V_126 -> V_130 ) ;
V_56 -> V_124 = NULL ;
if ( V_140 )
F_59 ( V_139 -> V_63 ) ;
}
int F_60 ( struct V_102 * V_103 , struct V_119 * V_56 )
{
struct V_138 * V_139 ;
struct V_127 * V_128 = V_56 -> V_124 ;
struct V_62 * V_63 ;
bool V_145 = false ;
int V_51 = 1 ;
if ( V_128 == NULL )
goto V_146;
if ( ! F_61 ( V_103 ) )
goto V_136;
V_139 = V_128 -> V_137 -> V_139 ;
if ( V_128 -> V_145 ) {
V_128 -> V_145 = 0 ;
V_145 = true ;
}
F_62 ( V_139 , V_56 ) ;
switch ( V_56 -> V_147 ) {
case 0 :
++ V_128 -> V_148 ;
V_63 = V_139 -> V_63 ;
F_40 ( V_63 , V_56 -> V_149 ) ;
F_63 ( V_63 , V_56 -> V_150 ) ;
F_64 ( V_128 -> V_137 , V_128 , V_56 ) ;
break;
case 1 :
V_128 -> V_145 = 1 ;
goto V_136;
case - V_89 :
F_8 ( L_9 ,
V_34 ,
V_128 -> V_151 ,
V_128 -> V_148 ) ;
goto V_99;
case - V_81 :
goto V_152;
case - V_86 :
if ( V_145 ) {
++ V_128 -> V_148 ;
goto V_152;
}
if ( V_128 -> V_148 != 1 ) {
V_128 -> V_148 = 1 ;
goto V_152;
}
break;
case - V_85 :
++ V_128 -> V_148 ;
goto V_152;
default:
++ V_128 -> V_148 ;
}
V_136:
F_8 ( L_10 , V_34 , V_56 -> V_147 ) ;
F_58 ( V_56 ) ;
V_146:
return V_51 ;
V_152:
if ( F_65 ( V_103 ) ) {
V_103 -> V_107 = 0 ;
V_51 = 0 ;
}
goto V_136;
V_99:
if ( ! F_66 ( V_103 ) )
goto V_136;
F_35 ( V_103 , V_52 ) ;
return 0 ;
}
int F_67 ( struct V_102 * V_103 , struct V_119 * V_56 )
{
if ( V_56 -> V_124 == NULL )
return 1 ;
if ( ! V_56 -> V_124 -> V_137 -> V_139 )
return F_55 ( V_103 , V_56 ) ;
return F_60 ( V_103 , V_56 ) ;
}
int F_68 ( struct V_138 * V_139 ,
struct V_118 * args ,
struct V_119 * V_56 ,
struct V_102 * V_103 )
{
struct V_127 * V_128 ;
struct V_125 * V_126 ;
F_8 ( L_11 , V_34 ) ;
if ( V_56 -> V_124 != NULL )
goto V_153;
V_126 = & V_139 -> V_154 ;
V_103 -> V_133 = 0 ;
F_41 ( & V_126 -> V_130 ) ;
if ( F_33 ( V_155 , & V_126 -> V_156 ) &&
! args -> V_123 ) {
F_8 ( L_12 , V_34 ) ;
goto V_131;
}
V_128 = F_50 ( V_126 ) ;
if ( F_51 ( V_128 ) ) {
if ( V_128 == F_52 ( - V_132 ) )
V_103 -> V_133 = V_88 >> 2 ;
F_8 ( L_13 , V_34 ) ;
goto V_131;
}
F_43 ( & V_126 -> V_130 ) ;
args -> V_121 = V_128 ;
F_8 ( L_14 , V_34 ,
V_128 -> V_151 , V_128 -> V_148 ) ;
V_56 -> V_124 = V_128 ;
V_56 -> V_149 = V_157 ;
V_56 -> V_150 = 0 ;
V_56 -> V_147 = 1 ;
F_69 ( V_139 , args ) ;
V_153:
F_53 ( V_103 ) ;
return 0 ;
V_131:
if ( args -> V_123 )
F_54 ( & V_126 -> V_134 , V_103 ,
NULL , V_135 ) ;
else
F_36 ( & V_126 -> V_134 , V_103 , NULL ) ;
F_43 ( & V_126 -> V_130 ) ;
return - V_108 ;
}
static int F_70 ( const struct V_13 * V_14 ,
struct V_118 * args ,
struct V_119 * V_56 ,
struct V_102 * V_103 )
{
struct V_138 * V_139 = F_71 ( V_14 ) ;
int V_51 = 0 ;
if ( ! V_139 )
return F_48 ( V_14 -> V_62 -> V_158 ,
args , V_56 , V_103 ) ;
F_8 ( L_15 ,
V_34 , V_139 -> V_63 , V_139 , V_56 -> V_124 ?
V_56 -> V_124 -> V_151 : V_144 ) ;
V_51 = F_68 ( V_139 , args , V_56 , V_103 ) ;
F_8 ( L_16 , V_34 , V_51 ) ;
return V_51 ;
}
static void F_72 ( struct V_102 * V_103 , void * V_159 )
{
struct V_160 * V_161 = V_159 ;
struct V_138 * V_139 = F_71 ( V_161 -> V_162 ) ;
F_8 ( L_17 , V_34 , V_161 -> V_162 ) ;
F_68 ( V_139 , V_161 -> V_163 , V_161 -> V_164 , V_103 ) ;
}
static void F_73 ( struct V_102 * V_103 , void * V_159 )
{
struct V_160 * V_161 = V_159 ;
F_60 ( V_103 , V_161 -> V_164 ) ;
}
static int F_70 ( const struct V_13 * V_14 ,
struct V_118 * args ,
struct V_119 * V_56 ,
struct V_102 * V_103 )
{
return F_48 ( V_14 -> V_62 -> V_158 ,
args , V_56 , V_103 ) ;
}
int F_67 ( struct V_102 * V_103 ,
struct V_119 * V_56 )
{
return F_55 ( V_103 , V_56 ) ;
}
static void F_74 ( struct V_102 * V_103 , void * V_159 )
{
struct V_160 * V_161 = V_159 ;
F_70 ( V_161 -> V_162 ,
V_161 -> V_163 , V_161 -> V_164 , V_103 ) ;
}
static void F_75 ( struct V_102 * V_103 , void * V_159 )
{
struct V_160 * V_161 = V_159 ;
F_67 ( V_103 , V_161 -> V_164 ) ;
}
static int F_76 ( struct V_54 * V_55 ,
struct V_13 * V_14 ,
struct V_165 * V_166 ,
struct V_118 * args ,
struct V_119 * V_56 )
{
int V_51 ;
struct V_102 * V_103 ;
struct V_62 * V_63 = V_14 -> V_62 ;
struct V_160 V_161 = {
. V_162 = V_14 ,
. V_163 = args ,
. V_164 = V_56 ,
} ;
struct V_167 V_168 = {
. V_169 = V_55 ,
. V_165 = V_166 ,
. V_170 = V_63 -> V_171 -> V_172 ,
. V_173 = & V_161
} ;
V_103 = F_77 ( & V_168 ) ;
if ( F_51 ( V_103 ) )
V_51 = F_78 ( V_103 ) ;
else {
V_51 = V_103 -> V_107 ;
F_79 ( V_103 ) ;
}
return V_51 ;
}
int F_80 ( struct V_54 * V_55 ,
struct V_13 * V_14 ,
struct V_165 * V_166 ,
struct V_118 * args ,
struct V_119 * V_56 ,
int V_120 )
{
F_46 ( args , V_56 , V_120 ) ;
return F_76 ( V_55 , V_14 , V_166 , args , V_56 ) ;
}
static void F_81 ( struct V_2 * V_3 , struct V_174 * V_175 )
{
struct V_176 * V_177 = F_82 ( V_3 ) ;
F_41 ( & V_3 -> V_178 ) ;
V_177 -> V_179 |= V_180 | V_181 ;
if ( ! V_175 -> V_182 || V_175 -> V_183 != V_3 -> V_184 )
F_83 ( V_3 ) ;
V_3 -> V_184 = V_175 -> V_185 ;
V_177 -> V_186 = F_84 () ;
F_85 ( V_3 ) ;
F_43 ( & V_3 -> V_178 ) ;
}
static bool F_86 ( struct V_13 * V_14 ,
int V_8 , struct V_60 * V_61 )
{
if ( V_8 != - V_27 )
return false ;
if ( ! ( V_14 -> V_94 & V_187 ) )
return false ;
V_14 -> V_94 &= ~ V_187 ;
V_61 -> V_68 = 1 ;
return true ;
}
static T_1
F_87 ( struct V_13 * V_14 ,
T_5 V_188 , int V_189 )
{
T_1 V_56 = 0 ;
switch ( V_188 & ( V_190 | V_191 ) ) {
case V_190 :
V_56 = V_192 ;
break;
case V_191 :
V_56 = V_193 ;
break;
case V_190 | V_191 :
V_56 = V_194 ;
}
if ( ! ( V_14 -> V_94 & V_187 ) )
goto V_136;
if ( V_189 & V_195 )
V_56 |= V_196 ;
V_136:
return V_56 ;
}
static enum V_197
F_88 ( struct V_13 * V_14 ,
enum V_197 V_198 )
{
if ( V_14 -> V_94 & V_187 )
return V_198 ;
switch ( V_198 ) {
default:
return V_198 ;
case V_199 :
return V_200 ;
case V_201 :
return V_202 ;
case V_203 :
return V_204 ;
}
}
static void F_89 ( struct V_205 * V_41 )
{
V_41 -> V_206 . V_207 = & V_41 -> V_207 ;
V_41 -> V_206 . V_208 = V_41 -> V_208 ;
V_41 -> V_206 . V_209 = V_41 -> V_210 . V_209 ;
V_41 -> V_211 . V_209 = V_41 -> V_212 . V_209 ;
V_41 -> V_206 . V_14 = V_41 -> V_210 . V_14 ;
V_41 -> V_206 . V_213 = V_41 -> V_210 . V_214 ;
F_90 ( & V_41 -> V_207 ) ;
F_91 ( & V_41 -> V_207 , & V_41 -> V_215 , & V_41 -> V_216 ) ;
}
static struct V_205 * F_92 ( struct V_4 * V_4 ,
struct V_217 * V_218 , T_5 V_188 , int V_219 ,
const struct V_5 * V_220 ,
struct V_1 * V_7 ,
enum V_197 V_198 ,
T_6 V_221 )
{
struct V_4 * V_222 = F_93 ( V_4 ) ;
struct V_2 * V_3 = F_14 ( V_222 ) ;
struct V_13 * V_14 = F_94 ( V_3 ) ;
struct V_223 * ( * V_224 ) ( struct V_225 * , T_6 ) ;
struct V_205 * V_41 ;
V_41 = F_95 ( sizeof( * V_41 ) , V_221 ) ;
if ( V_41 == NULL )
goto V_8;
V_41 -> V_208 = F_96 ( V_14 , V_221 ) ;
if ( F_51 ( V_41 -> V_208 ) )
goto V_226;
V_41 -> V_227 = F_96 ( V_14 , V_221 ) ;
if ( F_51 ( V_41 -> V_227 ) )
goto V_228;
V_224 = V_14 -> V_62 -> V_171 -> V_224 ;
V_41 -> V_210 . V_209 = V_224 ( & V_218 -> V_229 , V_221 ) ;
if ( F_51 ( V_41 -> V_210 . V_209 ) )
goto V_230;
F_97 ( V_4 -> V_231 ) ;
V_41 -> V_4 = F_98 ( V_4 ) ;
V_41 -> V_3 = V_222 ;
V_41 -> V_232 = V_218 ;
F_99 ( & V_218 -> V_233 ) ;
V_41 -> V_210 . V_234 = V_219 ;
V_41 -> V_210 . V_188 = V_188 & ( V_190 | V_191 ) ;
V_41 -> V_210 . V_235 = F_87 ( V_14 ,
V_188 , V_219 ) ;
if ( ! ( V_219 & V_236 ) ) {
V_41 -> V_210 . V_214 = V_237 | V_238 |
V_239 | V_240 ;
}
V_41 -> V_210 . V_241 = V_14 -> V_62 -> V_242 ;
V_41 -> V_210 . V_243 . V_244 = F_100 ( V_218 -> V_229 . V_244 ) ;
V_41 -> V_210 . V_243 . V_245 = V_218 -> V_229 . V_246 ;
V_41 -> V_210 . V_247 = & V_4 -> V_11 ;
V_41 -> V_210 . V_14 = V_14 ;
V_41 -> V_210 . V_248 = F_6 ( V_14 , V_7 ) ;
V_41 -> V_210 . V_249 = & V_250 [ 0 ] ;
V_41 -> V_210 . V_7 = F_101 ( V_41 -> V_227 , V_7 ) ;
V_41 -> V_210 . V_198 = F_88 ( V_14 , V_198 ) ;
switch ( V_41 -> V_210 . V_198 ) {
case V_200 :
case V_202 :
case V_204 :
V_41 -> V_210 . V_251 = F_102 ( V_3 ) ;
break;
case V_252 :
case V_199 :
case V_201 :
case V_203 :
V_41 -> V_210 . V_251 = F_102 ( F_14 ( V_4 ) ) ;
}
if ( V_220 != NULL && V_220 -> V_253 != 0 ) {
T_7 V_254 [ 2 ] ;
V_41 -> V_210 . V_255 . V_220 = & V_41 -> V_220 ;
memcpy ( & V_41 -> V_220 , V_220 , sizeof( V_41 -> V_220 ) ) ;
V_254 [ 0 ] = V_157 ;
V_254 [ 1 ] = V_57 -> V_256 ;
memcpy ( V_41 -> V_210 . V_255 . V_37 . V_161 , V_254 ,
sizeof( V_41 -> V_210 . V_255 . V_37 . V_161 ) ) ;
}
V_41 -> V_212 . V_251 = & V_41 -> V_206 . V_251 ;
V_41 -> V_212 . V_257 = & V_41 -> V_206 . V_257 ;
V_41 -> V_212 . V_209 = V_41 -> V_210 . V_209 ;
F_89 ( V_41 ) ;
F_103 ( & V_41 -> V_258 ) ;
return V_41 ;
V_230:
F_104 ( V_41 -> V_227 ) ;
V_228:
F_104 ( V_41 -> V_208 ) ;
V_226:
F_105 ( V_41 ) ;
V_8:
F_106 ( V_222 ) ;
return NULL ;
}
static void F_107 ( struct V_258 * V_258 )
{
struct V_205 * V_41 = F_108 ( V_258 ,
struct V_205 , V_258 ) ;
struct V_259 * V_260 = V_41 -> V_4 -> V_231 ;
F_109 ( V_41 -> V_210 . V_209 ) ;
if ( V_41 -> V_65 != NULL )
F_110 ( V_41 -> V_65 ) ;
F_111 ( V_41 -> V_232 ) ;
F_104 ( V_41 -> V_227 ) ;
F_104 ( V_41 -> V_208 ) ;
F_106 ( V_41 -> V_3 ) ;
F_106 ( V_41 -> V_4 ) ;
F_112 ( V_260 ) ;
F_113 ( & V_41 -> V_207 ) ;
F_105 ( V_41 -> V_207 . V_261 ) ;
F_105 ( V_41 ) ;
}
static void F_114 ( struct V_205 * V_41 )
{
if ( V_41 != NULL )
F_115 ( & V_41 -> V_258 , F_107 ) ;
}
static int F_116 ( struct V_102 * V_103 )
{
int V_51 ;
V_51 = F_117 ( V_103 ) ;
return V_51 ;
}
static bool F_118 ( struct V_64 * V_65 ,
T_5 V_188 )
{
switch( V_188 & ( V_190 | V_191 ) ) {
case V_190 | V_191 :
return V_65 -> V_262 != 0 ;
case V_191 :
return V_65 -> V_263 != 0 ;
case V_190 :
return V_65 -> V_264 != 0 ;
}
F_119 ( 1 ) ;
return false ;
}
static int F_120 ( struct V_64 * V_65 , T_5 V_265 , int V_266 )
{
int V_51 = 0 ;
if ( V_266 & ( V_236 | V_267 ) )
goto V_136;
switch ( V_265 & ( V_190 | V_191 ) ) {
case V_190 :
V_51 |= F_33 ( V_268 , & V_65 -> V_219 ) != 0
&& V_65 -> V_264 != 0 ;
break;
case V_191 :
V_51 |= F_33 ( V_269 , & V_65 -> V_219 ) != 0
&& V_65 -> V_263 != 0 ;
break;
case V_190 | V_191 :
V_51 |= F_33 ( V_270 , & V_65 -> V_219 ) != 0
&& V_65 -> V_262 != 0 ;
}
V_136:
return V_51 ;
}
static int F_121 ( struct V_271 * V_272 , T_5 V_188 ,
enum V_197 V_198 )
{
if ( V_272 == NULL )
return 0 ;
if ( ( V_272 -> type & V_188 ) != V_188 )
return 0 ;
if ( F_33 ( V_273 , & V_272 -> V_219 ) )
return 0 ;
switch ( V_198 ) {
case V_200 :
case V_199 :
break;
case V_252 :
if ( ! F_33 ( V_274 , & V_272 -> V_219 ) )
break;
default:
return 0 ;
}
F_122 ( V_272 ) ;
return 1 ;
}
static void F_123 ( struct V_64 * V_65 , T_5 V_188 )
{
switch ( V_188 ) {
case V_191 :
V_65 -> V_263 ++ ;
break;
case V_190 :
V_65 -> V_264 ++ ;
break;
case V_190 | V_191 :
V_65 -> V_262 ++ ;
}
F_124 ( V_65 , V_65 -> V_65 | V_188 ) ;
}
static void F_125 ( struct V_64 * V_65 )
{
struct V_62 * V_63 = V_65 -> V_232 -> V_275 -> V_62 ;
bool V_276 = false ;
if ( F_126 ( V_268 , & V_65 -> V_219 ) && V_65 -> V_264 )
V_276 = true ;
if ( F_126 ( V_269 , & V_65 -> V_219 ) && V_65 -> V_263 )
V_276 = true ;
if ( F_126 ( V_270 , & V_65 -> V_219 ) && V_65 -> V_262 )
V_276 = true ;
if ( V_276 )
F_127 ( V_63 , V_65 ) ;
}
static bool F_128 ( struct V_64 * V_65 ,
T_8 * V_257 )
{
if ( F_129 ( V_277 , & V_65 -> V_219 ) == 0 )
return true ;
if ( ! F_130 ( V_257 , & V_65 -> V_278 ) ) {
F_125 ( V_65 ) ;
return true ;
}
if ( F_131 ( V_257 , & V_65 -> V_278 ) )
return true ;
return false ;
}
static void F_132 ( struct V_64 * V_65 )
{
if ( ! ( V_65 -> V_263 || V_65 -> V_264 || V_65 -> V_262 ) )
return;
if ( V_65 -> V_263 )
F_133 ( V_269 , & V_65 -> V_219 ) ;
if ( V_65 -> V_264 )
F_133 ( V_268 , & V_65 -> V_219 ) ;
if ( V_65 -> V_262 )
F_133 ( V_270 , & V_65 -> V_219 ) ;
F_133 ( V_277 , & V_65 -> V_219 ) ;
}
static void F_134 ( struct V_64 * V_65 ,
T_8 * V_279 ,
T_8 * V_257 , T_5 V_188 )
{
F_135 ( V_270 , & V_65 -> V_219 ) ;
switch ( V_188 & ( V_190 | V_191 ) ) {
case V_191 :
F_135 ( V_268 , & V_65 -> V_219 ) ;
break;
case V_190 :
F_135 ( V_269 , & V_65 -> V_219 ) ;
break;
case 0 :
F_135 ( V_268 , & V_65 -> V_219 ) ;
F_135 ( V_269 , & V_65 -> V_219 ) ;
F_135 ( V_277 , & V_65 -> V_219 ) ;
}
if ( V_257 == NULL )
return;
if ( ! F_130 ( V_279 , & V_65 -> V_278 ) ||
( F_130 ( V_257 , & V_65 -> V_278 ) &&
! F_131 ( V_257 , & V_65 -> V_278 ) ) ) {
F_132 ( V_65 ) ;
return;
}
if ( F_33 ( V_280 , & V_65 -> V_219 ) == 0 )
F_136 ( & V_65 -> V_257 , V_257 ) ;
F_136 ( & V_65 -> V_278 , V_257 ) ;
}
static void F_137 ( struct V_64 * V_65 ,
T_8 * V_279 ,
T_8 * V_257 , T_5 V_188 )
{
F_138 ( & V_65 -> V_281 ) ;
F_134 ( V_65 , V_279 , V_257 , V_188 ) ;
F_139 ( & V_65 -> V_281 ) ;
if ( F_33 ( V_282 , & V_65 -> V_219 ) )
F_140 ( V_65 -> V_232 -> V_275 -> V_62 ) ;
}
static void F_141 ( struct V_64 * V_65 , T_8 * V_257 , T_5 V_188 )
{
switch ( V_188 ) {
case V_190 :
F_133 ( V_268 , & V_65 -> V_219 ) ;
break;
case V_191 :
F_133 ( V_269 , & V_65 -> V_219 ) ;
break;
case V_190 | V_191 :
F_133 ( V_270 , & V_65 -> V_219 ) ;
}
if ( ! F_128 ( V_65 , V_257 ) )
return;
if ( F_33 ( V_280 , & V_65 -> V_219 ) == 0 )
F_136 ( & V_65 -> V_257 , V_257 ) ;
F_136 ( & V_65 -> V_278 , V_257 ) ;
}
static void F_142 ( struct V_64 * V_65 , T_8 * V_278 , const T_8 * V_283 , T_5 V_188 )
{
F_138 ( & V_65 -> V_281 ) ;
if ( V_283 != NULL ) {
F_136 ( & V_65 -> V_257 , V_283 ) ;
F_133 ( V_280 , & V_65 -> V_219 ) ;
}
if ( V_278 != NULL )
F_141 ( V_65 , V_278 , V_188 ) ;
F_139 ( & V_65 -> V_281 ) ;
F_41 ( & V_65 -> V_232 -> V_284 ) ;
F_123 ( V_65 , V_188 ) ;
F_43 ( & V_65 -> V_232 -> V_284 ) ;
}
static int F_143 ( struct V_64 * V_65 , T_8 * V_278 , T_8 * V_272 , T_5 V_188 )
{
struct V_176 * V_177 = F_82 ( V_65 -> V_2 ) ;
struct V_271 * V_285 ;
int V_51 = 0 ;
V_188 &= ( V_190 | V_191 ) ;
F_144 () ;
V_285 = F_145 ( V_177 -> V_272 ) ;
if ( V_285 == NULL )
goto V_286;
F_41 ( & V_285 -> V_287 ) ;
if ( F_145 ( V_177 -> V_272 ) != V_285 ||
F_33 ( V_273 , & V_285 -> V_219 ) ||
( V_285 -> type & V_188 ) != V_188 )
goto V_288;
if ( V_272 == NULL )
V_272 = & V_285 -> V_257 ;
else if ( ! F_146 ( & V_285 -> V_257 , V_272 ) )
goto V_288;
F_122 ( V_285 ) ;
F_142 ( V_65 , V_278 , & V_285 -> V_257 , V_188 ) ;
V_51 = 1 ;
V_288:
F_43 ( & V_285 -> V_287 ) ;
V_286:
F_147 () ;
if ( ! V_51 && V_278 != NULL ) {
F_142 ( V_65 , V_278 , NULL , V_188 ) ;
V_51 = 1 ;
}
if ( F_33 ( V_282 , & V_65 -> V_219 ) )
F_140 ( V_65 -> V_232 -> V_275 -> V_62 ) ;
return V_51 ;
}
static bool F_148 ( struct V_289 * V_290 ,
const T_8 * V_257 )
{
struct V_64 * V_65 = V_290 -> V_291 ;
bool V_51 = false ;
F_41 ( & V_65 -> V_292 ) ;
if ( ! F_130 ( V_257 , & V_290 -> V_293 ) )
goto V_294;
if ( ! F_131 ( V_257 , & V_290 -> V_293 ) )
goto V_294;
F_136 ( & V_290 -> V_293 , V_257 ) ;
V_51 = true ;
V_294:
F_43 ( & V_65 -> V_292 ) ;
return V_51 ;
}
static void F_149 ( struct V_2 * V_2 , T_5 V_188 )
{
struct V_271 * V_272 ;
F_144 () ;
V_272 = F_145 ( F_82 ( V_2 ) -> V_272 ) ;
if ( V_272 == NULL || ( V_272 -> type & V_188 ) == V_188 ) {
F_147 () ;
return;
}
F_147 () ;
F_150 ( V_2 ) ;
}
static struct V_64 * F_151 ( struct V_205 * V_295 )
{
struct V_64 * V_65 = V_295 -> V_65 ;
struct V_176 * V_177 = F_82 ( V_65 -> V_2 ) ;
struct V_271 * V_272 ;
int V_266 = V_295 -> V_210 . V_234 ;
T_5 V_188 = V_295 -> V_210 . V_188 ;
enum V_197 V_198 = V_295 -> V_210 . V_198 ;
T_8 V_257 ;
int V_51 = - V_108 ;
for (; ; ) {
F_41 ( & V_65 -> V_232 -> V_284 ) ;
if ( F_120 ( V_65 , V_188 , V_266 ) ) {
F_123 ( V_65 , V_188 ) ;
F_43 ( & V_65 -> V_232 -> V_284 ) ;
goto V_296;
}
F_43 ( & V_65 -> V_232 -> V_284 ) ;
F_144 () ;
V_272 = F_145 ( V_177 -> V_272 ) ;
if ( ! F_121 ( V_272 , V_188 , V_198 ) ) {
F_147 () ;
break;
}
F_136 ( & V_257 , & V_272 -> V_257 ) ;
F_147 () ;
F_152 ( V_295 -> V_210 . V_209 ) ;
if ( ! V_295 -> V_297 ) {
V_51 = F_153 ( V_65 -> V_2 , V_65 -> V_232 -> V_298 , V_266 ) ;
if ( V_51 != 0 )
goto V_136;
}
V_51 = - V_108 ;
if ( F_143 ( V_65 , NULL , & V_257 , V_188 ) )
goto V_296;
}
V_136:
return F_52 ( V_51 ) ;
V_296:
F_99 ( & V_65 -> V_49 ) ;
return V_65 ;
}
static void
F_154 ( struct V_205 * V_161 , struct V_64 * V_65 )
{
struct V_62 * V_63 = F_94 ( V_65 -> V_2 ) -> V_62 ;
struct V_271 * V_272 ;
int V_299 = 0 ;
F_144 () ;
V_272 = F_145 ( F_82 ( V_65 -> V_2 ) -> V_272 ) ;
if ( V_272 )
V_299 = V_272 -> V_219 ;
F_147 () ;
switch ( V_161 -> V_210 . V_198 ) {
default:
break;
case V_202 :
case V_201 :
F_155 ( L_18
L_19
L_20 ,
V_63 -> V_97 ) ;
return;
}
if ( ( V_299 & 1UL << V_274 ) == 0 )
F_156 ( V_65 -> V_2 ,
V_161 -> V_232 -> V_298 ,
& V_161 -> V_206 ) ;
else
F_157 ( V_65 -> V_2 ,
V_161 -> V_232 -> V_298 ,
& V_161 -> V_206 ) ;
}
static struct V_64 *
F_158 ( struct V_205 * V_161 )
{
struct V_2 * V_2 = V_161 -> V_65 -> V_2 ;
struct V_64 * V_65 = V_161 -> V_65 ;
int V_51 ;
if ( ! V_161 -> V_300 ) {
if ( V_161 -> V_301 ) {
V_51 = V_161 -> V_301 ;
goto V_8;
}
goto V_302;
}
V_51 = F_159 ( V_2 , & V_161 -> V_207 ) ;
if ( V_51 )
goto V_8;
if ( V_161 -> V_206 . V_303 != 0 )
F_154 ( V_161 , V_65 ) ;
V_302:
F_143 ( V_65 , & V_161 -> V_206 . V_257 , NULL ,
V_161 -> V_210 . V_188 ) ;
F_99 ( & V_65 -> V_49 ) ;
return V_65 ;
V_8:
return F_52 ( V_51 ) ;
}
static struct V_64 *
F_160 ( struct V_205 * V_161 )
{
struct V_2 * V_2 ;
struct V_64 * V_65 = NULL ;
int V_51 ;
if ( ! V_161 -> V_300 ) {
V_65 = F_151 ( V_161 ) ;
goto V_136;
}
V_51 = - V_108 ;
if ( ! ( V_161 -> V_207 . V_304 & V_305 ) )
goto V_8;
V_2 = F_161 ( V_161 -> V_3 -> V_231 , & V_161 -> V_206 . V_251 , & V_161 -> V_207 , V_161 -> V_208 ) ;
V_51 = F_78 ( V_2 ) ;
if ( F_51 ( V_2 ) )
goto V_8;
V_51 = - V_132 ;
V_65 = F_162 ( V_2 , V_161 -> V_232 ) ;
if ( V_65 == NULL )
goto V_306;
if ( V_161 -> V_206 . V_303 != 0 )
F_154 ( V_161 , V_65 ) ;
F_143 ( V_65 , & V_161 -> V_206 . V_257 , NULL ,
V_161 -> V_210 . V_188 ) ;
F_163 ( V_2 ) ;
V_136:
F_152 ( V_161 -> V_210 . V_209 ) ;
return V_65 ;
V_306:
F_163 ( V_2 ) ;
V_8:
return F_52 ( V_51 ) ;
}
static struct V_64 *
F_164 ( struct V_205 * V_161 )
{
if ( V_161 -> V_210 . V_198 == V_252 )
return F_158 ( V_161 ) ;
return F_160 ( V_161 ) ;
}
static struct V_307 * F_165 ( struct V_64 * V_65 )
{
struct V_176 * V_177 = F_82 ( V_65 -> V_2 ) ;
struct V_307 * V_308 ;
F_41 ( & V_65 -> V_2 -> V_178 ) ;
F_166 (ctx, &nfsi->open_files, list) {
if ( V_308 -> V_65 != V_65 )
continue;
F_167 ( V_308 ) ;
F_43 ( & V_65 -> V_2 -> V_178 ) ;
return V_308 ;
}
F_43 ( & V_65 -> V_2 -> V_178 ) ;
return F_52 ( - V_309 ) ;
}
static struct V_205 * F_168 ( struct V_307 * V_308 ,
struct V_64 * V_65 , enum V_197 V_198 )
{
struct V_205 * V_295 ;
V_295 = F_92 ( V_308 -> V_4 , V_65 -> V_232 , 0 , 0 ,
NULL , NULL , V_198 , V_310 ) ;
if ( V_295 == NULL )
return F_52 ( - V_132 ) ;
V_295 -> V_65 = V_65 ;
F_99 ( & V_65 -> V_49 ) ;
return V_295 ;
}
static int F_169 ( struct V_205 * V_295 ,
T_5 V_188 )
{
struct V_64 * V_311 ;
int V_51 ;
if ( ! F_118 ( V_295 -> V_65 , V_188 ) )
return 0 ;
V_295 -> V_210 . V_234 = 0 ;
V_295 -> V_210 . V_188 = V_188 ;
V_295 -> V_210 . V_235 = F_87 (
F_170 ( V_295 -> V_4 -> V_231 ) ,
V_188 , 0 ) ;
memset ( & V_295 -> V_206 , 0 , sizeof( V_295 -> V_206 ) ) ;
memset ( & V_295 -> V_211 , 0 , sizeof( V_295 -> V_211 ) ) ;
F_89 ( V_295 ) ;
V_51 = F_171 ( V_295 ) ;
if ( V_51 != 0 )
return V_51 ;
V_311 = F_164 ( V_295 ) ;
if ( F_51 ( V_311 ) )
return F_78 ( V_311 ) ;
if ( V_311 != V_295 -> V_65 )
V_51 = - V_312 ;
F_172 ( V_311 , V_188 ) ;
return V_51 ;
}
static int F_173 ( struct V_205 * V_295 , struct V_64 * V_65 )
{
int V_51 ;
F_135 ( V_270 , & V_65 -> V_219 ) ;
F_135 ( V_269 , & V_65 -> V_219 ) ;
F_135 ( V_268 , & V_65 -> V_219 ) ;
F_135 ( V_280 , & V_65 -> V_219 ) ;
F_135 ( V_277 , & V_65 -> V_219 ) ;
F_174 () ;
V_51 = F_169 ( V_295 , V_190 | V_191 ) ;
if ( V_51 != 0 )
return V_51 ;
V_51 = F_169 ( V_295 , V_191 ) ;
if ( V_51 != 0 )
return V_51 ;
V_51 = F_169 ( V_295 , V_190 ) ;
if ( V_51 != 0 )
return V_51 ;
if ( F_33 ( V_280 , & V_65 -> V_219 ) == 0 &&
! F_146 ( & V_65 -> V_257 , & V_65 -> V_278 ) ) {
F_138 ( & V_65 -> V_281 ) ;
if ( F_33 ( V_280 , & V_65 -> V_219 ) == 0 )
F_136 ( & V_65 -> V_257 , & V_65 -> V_278 ) ;
F_139 ( & V_65 -> V_281 ) ;
}
return 0 ;
}
static int F_175 ( struct V_307 * V_308 , struct V_64 * V_65 )
{
struct V_271 * V_272 ;
struct V_205 * V_295 ;
T_5 V_303 = 0 ;
int V_313 ;
V_295 = F_168 ( V_308 , V_65 ,
V_252 ) ;
if ( F_51 ( V_295 ) )
return F_78 ( V_295 ) ;
F_144 () ;
V_272 = F_145 ( F_82 ( V_65 -> V_2 ) -> V_272 ) ;
if ( V_272 != NULL && F_33 ( V_274 , & V_272 -> V_219 ) != 0 )
V_303 = V_272 -> type ;
F_147 () ;
V_295 -> V_210 . V_255 . V_303 = V_303 ;
V_313 = F_173 ( V_295 , V_65 ) ;
F_114 ( V_295 ) ;
return V_313 ;
}
static int F_176 ( struct V_307 * V_308 , struct V_64 * V_65 )
{
struct V_13 * V_14 = F_94 ( V_65 -> V_2 ) ;
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_175 ( V_308 , V_65 ) ;
F_177 ( V_308 , 0 , V_8 ) ;
if ( F_86 ( V_14 , V_8 , & V_61 ) )
continue;
if ( V_8 != - V_89 )
break;
F_31 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_178 ( struct V_217 * V_218 , struct V_64 * V_65 )
{
struct V_307 * V_308 ;
int V_51 ;
V_308 = F_165 ( V_65 ) ;
if ( F_51 ( V_308 ) )
return - V_108 ;
V_51 = F_176 ( V_308 , V_65 ) ;
F_179 ( V_308 ) ;
return V_51 ;
}
static int F_180 ( struct V_13 * V_14 , struct V_64 * V_65 , const T_8 * V_257 , int V_8 )
{
switch ( V_8 ) {
default:
F_30 ( V_314 L_21
L_22 , V_34 , V_8 ) ;
case 0 :
case - V_309 :
case - V_108 :
case - V_312 :
break;
case - V_80 :
case - V_81 :
case - V_82 :
case - V_83 :
case - V_84 :
F_133 ( V_280 , & V_65 -> V_219 ) ;
F_28 ( V_14 -> V_62 -> V_87 , V_8 ) ;
return - V_108 ;
case - V_76 :
case - V_75 :
F_133 ( V_280 , & V_65 -> V_219 ) ;
case - V_74 :
F_24 ( V_14 -> V_62 ) ;
return - V_108 ;
case - V_77 :
F_25 ( V_14 ) ;
return - V_108 ;
case - V_78 :
F_26 ( V_14 -> V_62 ) ;
return - V_108 ;
case - V_70 :
case - V_71 :
case - V_72 :
case - V_69 :
F_181 ( V_65 -> V_2 ,
V_257 ) ;
F_23 ( V_14 , V_65 ) ;
return - V_108 ;
case - V_89 :
case - V_91 :
F_133 ( V_280 , & V_65 -> V_219 ) ;
F_182 ( 1 ) ;
return - V_108 ;
case - V_132 :
case - V_315 :
return 0 ;
}
return V_8 ;
}
int F_183 ( struct V_307 * V_308 ,
struct V_64 * V_65 , const T_8 * V_257 ,
T_5 type )
{
struct V_13 * V_14 = F_94 ( V_65 -> V_2 ) ;
struct V_205 * V_295 ;
int V_8 = 0 ;
V_295 = F_168 ( V_308 , V_65 ,
V_201 ) ;
if ( F_51 ( V_295 ) )
return F_78 ( V_295 ) ;
F_136 ( & V_295 -> V_210 . V_255 . V_272 , V_257 ) ;
F_138 ( & V_65 -> V_281 ) ;
F_136 ( & V_65 -> V_257 , & V_65 -> V_278 ) ;
F_139 ( & V_65 -> V_281 ) ;
F_135 ( V_280 , & V_65 -> V_219 ) ;
switch ( type & ( V_190 | V_191 ) ) {
case V_190 | V_191 :
case V_191 :
V_8 = F_169 ( V_295 , V_190 | V_191 ) ;
if ( V_8 )
break;
V_8 = F_169 ( V_295 , V_191 ) ;
if ( V_8 )
break;
case V_190 :
V_8 = F_169 ( V_295 , V_190 ) ;
}
F_114 ( V_295 ) ;
return F_180 ( V_14 , V_65 , V_257 , V_8 ) ;
}
static void F_184 ( struct V_102 * V_103 , void * V_159 )
{
struct V_205 * V_161 = V_159 ;
F_48 ( V_161 -> V_210 . V_14 -> V_62 -> V_158 ,
& V_161 -> V_212 . V_163 , & V_161 -> V_211 . V_164 , V_103 ) ;
}
static void F_185 ( struct V_102 * V_103 , void * V_159 )
{
struct V_205 * V_161 = V_159 ;
F_55 ( V_103 , & V_161 -> V_211 . V_164 ) ;
V_161 -> V_301 = V_103 -> V_107 ;
if ( V_161 -> V_301 == 0 ) {
F_136 ( & V_161 -> V_206 . V_257 , & V_161 -> V_211 . V_257 ) ;
F_186 ( & V_161 -> V_232 -> V_229 , 0 ) ;
F_44 ( V_161 -> V_206 . V_14 , V_161 -> V_115 ) ;
V_161 -> V_300 = 1 ;
}
}
static void F_187 ( void * V_159 )
{
struct V_205 * V_161 = V_159 ;
struct V_64 * V_65 = NULL ;
if ( V_161 -> V_316 == 0 )
goto V_317;
if ( ! V_161 -> V_300 )
goto V_317;
V_65 = F_164 ( V_161 ) ;
if ( ! F_51 ( V_65 ) )
F_172 ( V_65 , V_161 -> V_210 . V_188 ) ;
V_317:
F_114 ( V_161 ) ;
}
static int F_188 ( struct V_205 * V_161 )
{
struct V_13 * V_14 = F_94 ( F_14 ( V_161 -> V_3 ) ) ;
struct V_102 * V_103 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_320 ] ,
. V_321 = & V_161 -> V_212 ,
. V_322 = & V_161 -> V_211 ,
. V_323 = V_161 -> V_232 -> V_298 ,
} ;
struct V_167 V_324 = {
. V_169 = V_14 -> V_98 ,
. V_165 = & V_166 ,
. V_170 = & V_325 ,
. V_173 = V_161 ,
. V_326 = V_327 ,
. V_219 = V_328 ,
} ;
int V_313 ;
F_46 ( & V_161 -> V_212 . V_163 , & V_161 -> V_211 . V_164 , 1 ) ;
F_189 ( & V_161 -> V_258 ) ;
V_161 -> V_300 = 0 ;
V_161 -> V_301 = 0 ;
V_161 -> V_115 = V_157 ;
if ( V_161 -> V_297 )
F_47 ( & V_161 -> V_212 . V_163 ) ;
V_103 = F_77 ( & V_324 ) ;
if ( F_51 ( V_103 ) )
return F_78 ( V_103 ) ;
V_313 = F_116 ( V_103 ) ;
if ( V_313 != 0 ) {
V_161 -> V_316 = 1 ;
F_190 () ;
} else
V_313 = V_161 -> V_301 ;
F_79 ( V_103 ) ;
return V_313 ;
}
static void F_191 ( struct V_102 * V_103 , void * V_159 )
{
struct V_205 * V_161 = V_159 ;
struct V_217 * V_218 = V_161 -> V_232 ;
struct V_62 * V_63 = V_218 -> V_275 -> V_62 ;
enum V_197 V_198 = V_161 -> V_210 . V_198 ;
if ( F_192 ( V_161 -> V_210 . V_209 , V_103 ) != 0 )
goto V_329;
if ( V_161 -> V_65 != NULL ) {
struct V_271 * V_272 ;
if ( F_120 ( V_161 -> V_65 , V_161 -> V_210 . V_188 , V_161 -> V_210 . V_234 ) )
goto V_330;
F_144 () ;
V_272 = F_145 ( F_82 ( V_161 -> V_65 -> V_2 ) -> V_272 ) ;
if ( F_121 ( V_272 , V_161 -> V_210 . V_188 , V_198 ) )
goto V_331;
F_147 () ;
}
V_161 -> V_210 . V_241 = V_63 -> V_242 ;
switch ( V_198 ) {
default:
break;
case V_252 :
case V_201 :
case V_203 :
V_161 -> V_210 . V_249 = & V_332 [ 0 ] ;
case V_199 :
V_103 -> V_333 . V_318 = & V_319 [ V_334 ] ;
F_193 ( & V_161 -> V_206 . V_251 , V_161 -> V_210 . V_251 ) ;
}
V_161 -> V_115 = V_157 ;
if ( F_70 ( V_161 -> V_210 . V_14 ,
& V_161 -> V_210 . V_163 ,
& V_161 -> V_206 . V_164 ,
V_103 ) != 0 )
F_152 ( V_161 -> V_210 . V_209 ) ;
V_161 -> V_210 . V_335 = V_336 ;
if ( V_161 -> V_210 . V_234 & V_236 ) {
V_161 -> V_210 . V_335 = V_337 ;
if ( F_194 ( V_63 ) )
V_161 -> V_210 . V_335 = V_338 ;
else if ( V_63 -> V_171 -> V_339 > 0 )
V_161 -> V_210 . V_335 = V_340 ;
}
return;
V_331:
F_147 () ;
V_330:
V_103 -> V_341 = NULL ;
V_329:
F_67 ( V_103 , & V_161 -> V_206 . V_164 ) ;
}
static void F_195 ( struct V_102 * V_103 , void * V_159 )
{
struct V_205 * V_161 = V_159 ;
V_161 -> V_301 = V_103 -> V_107 ;
if ( ! F_67 ( V_103 , & V_161 -> V_206 . V_164 ) )
return;
if ( V_103 -> V_107 == 0 ) {
if ( V_161 -> V_206 . V_207 -> V_304 & V_342 ) {
switch ( V_161 -> V_206 . V_207 -> V_265 & V_343 ) {
case V_344 :
break;
case V_345 :
V_161 -> V_301 = - V_346 ;
break;
case V_347 :
V_161 -> V_301 = - V_348 ;
break;
default:
V_161 -> V_301 = - V_349 ;
}
}
F_44 ( V_161 -> V_206 . V_14 , V_161 -> V_115 ) ;
if ( ! ( V_161 -> V_206 . V_350 & V_351 ) )
F_186 ( & V_161 -> V_232 -> V_229 , 0 ) ;
}
V_161 -> V_300 = 1 ;
}
static void F_196 ( void * V_159 )
{
struct V_205 * V_161 = V_159 ;
struct V_64 * V_65 = NULL ;
if ( V_161 -> V_316 == 0 )
goto V_317;
if ( V_161 -> V_301 != 0 || ! V_161 -> V_300 )
goto V_317;
if ( V_161 -> V_206 . V_350 & V_351 )
goto V_317;
V_65 = F_164 ( V_161 ) ;
if ( ! F_51 ( V_65 ) )
F_172 ( V_65 , V_161 -> V_210 . V_188 ) ;
V_317:
F_114 ( V_161 ) ;
}
static int F_197 ( struct V_205 * V_161 , int V_352 )
{
struct V_2 * V_3 = F_14 ( V_161 -> V_3 ) ;
struct V_13 * V_14 = F_94 ( V_3 ) ;
struct V_353 * V_210 = & V_161 -> V_210 ;
struct V_354 * V_206 = & V_161 -> V_206 ;
struct V_102 * V_103 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_355 ] ,
. V_321 = V_210 ,
. V_322 = V_206 ,
. V_323 = V_161 -> V_232 -> V_298 ,
} ;
struct V_167 V_324 = {
. V_169 = V_14 -> V_98 ,
. V_165 = & V_166 ,
. V_170 = & V_356 ,
. V_173 = V_161 ,
. V_326 = V_327 ,
. V_219 = V_328 ,
} ;
int V_313 ;
F_46 ( & V_210 -> V_163 , & V_206 -> V_164 , 1 ) ;
F_189 ( & V_161 -> V_258 ) ;
V_161 -> V_300 = 0 ;
V_161 -> V_301 = 0 ;
V_161 -> V_316 = 0 ;
V_161 -> V_297 = 0 ;
if ( V_352 ) {
F_47 ( & V_210 -> V_163 ) ;
V_161 -> V_297 = 1 ;
}
V_103 = F_77 ( & V_324 ) ;
if ( F_51 ( V_103 ) )
return F_78 ( V_103 ) ;
V_313 = F_116 ( V_103 ) ;
if ( V_313 != 0 ) {
V_161 -> V_316 = 1 ;
F_190 () ;
} else
V_313 = V_161 -> V_301 ;
F_79 ( V_103 ) ;
return V_313 ;
}
static int F_171 ( struct V_205 * V_161 )
{
struct V_2 * V_3 = F_14 ( V_161 -> V_3 ) ;
struct V_354 * V_206 = & V_161 -> V_206 ;
int V_313 ;
V_313 = F_197 ( V_161 , 1 ) ;
if ( V_313 != 0 || ! V_161 -> V_300 )
return V_313 ;
F_198 ( F_94 ( V_3 ) , & V_161 -> V_207 ) ;
if ( V_206 -> V_350 & V_351 ) {
V_313 = F_188 ( V_161 ) ;
if ( V_313 != 0 )
return V_313 ;
}
return V_313 ;
}
static int F_199 ( struct V_323 * V_357 ,
struct V_205 * V_295 ,
struct V_64 * V_65 , T_5 V_188 ,
int V_189 )
{
struct V_358 V_359 ;
T_1 V_360 ;
if ( V_295 -> V_206 . V_361 == 0 )
return 0 ;
V_360 = 0 ;
if ( V_189 & V_362 ) {
V_360 = V_363 ;
} else if ( ( V_188 & V_190 ) && ! V_295 -> V_364 )
V_360 = V_365 ;
V_359 . V_357 = V_357 ;
V_359 . V_157 = V_157 ;
F_200 ( & V_359 , V_295 -> V_206 . V_366 ) ;
F_201 ( V_65 -> V_2 , & V_359 ) ;
if ( ( V_360 & ~ V_359 . V_360 & ( V_365 | V_363 ) ) == 0 )
return 0 ;
F_172 ( V_65 , V_188 ) ;
return - V_29 ;
}
static int F_202 ( struct V_205 * V_161 )
{
struct V_2 * V_3 = F_14 ( V_161 -> V_3 ) ;
struct V_13 * V_14 = F_94 ( V_3 ) ;
struct V_353 * V_210 = & V_161 -> V_210 ;
struct V_354 * V_206 = & V_161 -> V_206 ;
int V_313 ;
V_313 = F_197 ( V_161 , 0 ) ;
if ( ! V_161 -> V_300 )
return V_313 ;
if ( V_313 != 0 ) {
if ( V_313 == - V_26 &&
! ( V_210 -> V_234 & V_367 ) )
return - V_309 ;
return V_313 ;
}
F_198 ( V_14 , & V_161 -> V_207 ) ;
if ( V_210 -> V_234 & V_367 ) {
F_81 ( V_3 , & V_206 -> V_175 ) ;
if ( V_210 -> V_234 & V_236 )
V_161 -> V_364 = 1 ;
else if ( V_206 -> V_175 . V_183 != V_206 -> V_175 . V_185 )
V_161 -> V_364 = 1 ;
}
if ( ( V_206 -> V_350 & V_368 ) == 0 )
V_14 -> V_94 &= ~ V_369 ;
if( V_206 -> V_350 & V_351 ) {
V_313 = F_188 ( V_161 ) ;
if ( V_313 != 0 )
return V_313 ;
}
if ( ! ( V_206 -> V_207 -> V_304 & V_305 ) )
F_203 ( V_14 , & V_206 -> V_251 , V_206 -> V_207 , V_206 -> V_208 ) ;
return 0 ;
}
static int F_204 ( struct V_13 * V_14 )
{
return F_205 ( V_14 -> V_62 ) ;
}
static int F_206 ( struct V_307 * V_308 , struct V_64 * V_65 )
{
struct V_205 * V_295 ;
int V_51 ;
V_295 = F_168 ( V_308 , V_65 ,
V_199 ) ;
if ( F_51 ( V_295 ) )
return F_78 ( V_295 ) ;
V_51 = F_173 ( V_295 , V_65 ) ;
if ( V_51 == - V_312 )
F_207 ( V_308 -> V_4 ) ;
F_114 ( V_295 ) ;
return V_51 ;
}
static int F_208 ( struct V_307 * V_308 , struct V_64 * V_65 )
{
struct V_13 * V_14 = F_94 ( V_65 -> V_2 ) ;
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_206 ( V_308 , V_65 ) ;
F_209 ( V_308 , 0 , V_8 ) ;
if ( F_86 ( V_14 , V_8 , & V_61 ) )
continue;
switch ( V_8 ) {
default:
goto V_136;
case - V_91 :
case - V_89 :
F_31 ( V_14 , V_8 , & V_61 ) ;
V_8 = 0 ;
}
} while ( V_61 . V_68 );
V_136:
return V_8 ;
}
static int F_210 ( struct V_217 * V_218 , struct V_64 * V_65 )
{
struct V_307 * V_308 ;
int V_51 ;
V_308 = F_165 ( V_65 ) ;
if ( F_51 ( V_308 ) )
return - V_108 ;
V_51 = F_208 ( V_308 , V_65 ) ;
F_179 ( V_308 ) ;
return V_51 ;
}
static void F_211 ( struct V_64 * V_65 )
{
F_212 ( V_65 -> V_2 ) ;
F_138 ( & V_65 -> V_281 ) ;
F_136 ( & V_65 -> V_257 , & V_65 -> V_278 ) ;
F_139 ( & V_65 -> V_281 ) ;
F_135 ( V_280 , & V_65 -> V_219 ) ;
}
static void F_213 ( struct V_64 * V_65 )
{
if ( F_214 ( F_82 ( V_65 -> V_2 ) -> V_272 ) != NULL )
F_211 ( V_65 ) ;
}
static int F_215 ( struct V_217 * V_218 , struct V_64 * V_65 )
{
F_213 ( V_65 ) ;
return F_210 ( V_218 , V_65 ) ;
}
static void F_216 ( struct V_64 * V_65 )
{
struct V_13 * V_14 = F_94 ( V_65 -> V_2 ) ;
T_8 V_257 ;
struct V_271 * V_272 ;
struct V_323 * V_357 ;
int V_313 ;
F_144 () ;
V_272 = F_145 ( F_82 ( V_65 -> V_2 ) -> V_272 ) ;
if ( V_272 == NULL ) {
F_147 () ;
return;
}
F_136 ( & V_257 , & V_272 -> V_257 ) ;
V_357 = F_217 ( V_272 -> V_357 ) ;
F_147 () ;
V_313 = F_218 ( V_14 , & V_257 , V_357 ) ;
F_219 ( V_65 , NULL , V_313 ) ;
if ( V_313 != V_370 ) {
if ( V_313 != - V_72 )
F_220 ( V_14 , & V_257 , V_357 ) ;
F_211 ( V_65 ) ;
}
F_221 ( V_357 ) ;
}
static int F_222 ( struct V_64 * V_65 )
{
struct V_13 * V_14 = F_94 ( V_65 -> V_2 ) ;
T_8 * V_257 = & V_65 -> V_278 ;
struct V_323 * V_357 = V_65 -> V_232 -> V_298 ;
int V_313 ;
if ( ( F_33 ( V_268 , & V_65 -> V_219 ) == 0 ) &&
( F_33 ( V_269 , & V_65 -> V_219 ) == 0 ) &&
( F_33 ( V_270 , & V_65 -> V_219 ) == 0 ) )
return - V_72 ;
V_313 = F_218 ( V_14 , V_257 , V_357 ) ;
F_223 ( V_65 , NULL , V_313 ) ;
if ( V_313 != V_370 ) {
if ( V_313 != - V_72 )
F_220 ( V_14 , V_257 , V_357 ) ;
F_135 ( V_268 , & V_65 -> V_219 ) ;
F_135 ( V_269 , & V_65 -> V_219 ) ;
F_135 ( V_270 , & V_65 -> V_219 ) ;
F_135 ( V_277 , & V_65 -> V_219 ) ;
}
return V_313 ;
}
static int F_224 ( struct V_217 * V_218 , struct V_64 * V_65 )
{
int V_313 ;
F_216 ( V_65 ) ;
V_313 = F_222 ( V_65 ) ;
if ( V_313 != V_370 )
V_313 = F_210 ( V_218 , V_65 ) ;
return V_313 ;
}
static inline void F_225 ( struct V_205 * V_295 ,
struct V_5 * V_6 , struct V_1 * * V_7 )
{
const T_1 * V_371 = V_295 -> V_206 . V_371 ;
if ( ( V_371 [ 1 ] & V_372 ) &&
! ( V_6 -> V_253 & V_373 ) )
V_6 -> V_253 |= V_374 ;
if ( ( V_371 [ 1 ] & V_375 ) &&
! ( V_6 -> V_253 & V_376 ) )
V_6 -> V_253 |= V_377 ;
if ( ( V_371 [ 1 ] & V_378 ) )
V_6 -> V_253 &= ~ V_379 ;
if ( V_371 [ 2 ] & V_380 )
* V_7 = NULL ;
}
static int F_226 ( struct V_205 * V_295 ,
T_5 V_188 ,
int V_219 ,
struct V_307 * V_308 )
{
struct V_217 * V_218 = V_295 -> V_232 ;
struct V_13 * V_14 = V_218 -> V_275 ;
struct V_4 * V_4 ;
struct V_64 * V_65 ;
unsigned int V_381 ;
int V_51 ;
V_381 = F_227 ( & V_218 -> V_382 ) ;
V_51 = F_202 ( V_295 ) ;
if ( V_51 != 0 )
goto V_136;
V_65 = F_164 ( V_295 ) ;
V_51 = F_78 ( V_65 ) ;
if ( F_51 ( V_65 ) )
goto V_136;
if ( V_14 -> V_94 & V_369 )
F_133 ( V_383 , & V_65 -> V_219 ) ;
V_4 = V_295 -> V_4 ;
if ( F_228 ( V_4 ) ) {
F_207 ( V_4 ) ;
V_4 = F_229 ( V_4 , F_230 ( V_65 -> V_2 ) ) ;
if ( V_4 == NULL ) {
V_4 = V_295 -> V_4 ;
} else if ( V_4 != V_308 -> V_4 ) {
F_106 ( V_308 -> V_4 ) ;
V_308 -> V_4 = F_98 ( V_4 ) ;
}
F_231 ( V_4 ,
F_232 ( F_14 ( V_295 -> V_3 ) ) ) ;
}
V_51 = F_199 ( V_218 -> V_298 , V_295 , V_65 , V_188 , V_219 ) ;
if ( V_51 != 0 )
goto V_136;
V_308 -> V_65 = V_65 ;
if ( F_14 ( V_4 ) == V_65 -> V_2 ) {
F_233 ( V_308 ) ;
if ( F_234 ( & V_218 -> V_382 , V_381 ) )
F_23 ( V_14 , V_65 ) ;
}
V_136:
return V_51 ;
}
static int F_235 ( struct V_2 * V_3 ,
struct V_307 * V_308 ,
int V_219 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_384 )
{
struct V_217 * V_218 ;
struct V_64 * V_65 = NULL ;
struct V_13 * V_14 = F_94 ( V_3 ) ;
struct V_205 * V_295 ;
struct V_4 * V_4 = V_308 -> V_4 ;
struct V_323 * V_357 = V_308 -> V_357 ;
struct V_385 * * V_386 = & V_308 -> V_261 ;
T_5 V_188 = V_308 -> V_265 & ( V_190 | V_191 | V_387 ) ;
enum V_197 V_198 = V_200 ;
struct V_1 * V_388 = NULL ;
int V_313 ;
V_313 = - V_132 ;
V_218 = F_236 ( V_14 , V_357 , V_389 ) ;
if ( V_218 == NULL ) {
F_8 ( L_23 ) ;
goto V_390;
}
V_313 = F_204 ( V_14 ) ;
if ( V_313 != 0 )
goto V_391;
if ( F_237 ( V_4 ) )
F_149 ( F_14 ( V_4 ) , V_188 ) ;
V_313 = - V_132 ;
if ( F_237 ( V_4 ) )
V_198 = V_199 ;
V_295 = F_92 ( V_4 , V_218 , V_188 , V_219 , V_6 ,
V_7 , V_198 , V_389 ) ;
if ( V_295 == NULL )
goto V_391;
if ( V_7 ) {
V_388 = F_96 ( V_14 , V_389 ) ;
if ( F_51 ( V_388 ) ) {
V_313 = F_78 ( V_388 ) ;
goto V_392;
}
}
if ( V_14 -> V_15 [ 2 ] & V_393 ) {
if ( ! V_295 -> V_207 . V_261 ) {
V_295 -> V_207 . V_261 = F_238 () ;
if ( ! V_295 -> V_207 . V_261 )
goto V_230;
}
V_295 -> V_210 . V_249 = & V_394 [ 0 ] ;
}
if ( F_237 ( V_4 ) )
V_295 -> V_65 = F_162 ( F_14 ( V_4 ) , V_218 ) ;
V_313 = F_226 ( V_295 , V_188 , V_219 , V_308 ) ;
if ( V_313 != 0 )
goto V_230;
V_65 = V_308 -> V_65 ;
if ( ( V_295 -> V_210 . V_234 & ( V_367 | V_236 ) ) == ( V_367 | V_236 ) &&
( V_295 -> V_210 . V_335 != V_338 ) ) {
F_225 ( V_295 , V_6 , & V_7 ) ;
F_90 ( V_295 -> V_206 . V_207 ) ;
V_313 = F_239 ( V_65 -> V_2 , V_357 ,
V_295 -> V_206 . V_207 , V_6 ,
V_65 , V_7 , V_388 ) ;
if ( V_313 == 0 ) {
F_240 ( V_65 -> V_2 , V_6 ,
V_295 -> V_206 . V_207 ) ;
F_241 ( V_65 -> V_2 , V_295 -> V_206 . V_207 , V_388 ) ;
}
}
if ( V_384 && V_295 -> V_364 )
* V_384 |= V_395 ;
if ( F_242 ( V_386 , V_295 -> V_207 . V_261 , V_14 ) ) {
* V_386 = V_295 -> V_207 . V_261 ;
V_295 -> V_207 . V_261 = NULL ;
}
F_104 ( V_388 ) ;
F_114 ( V_295 ) ;
F_111 ( V_218 ) ;
return 0 ;
V_230:
F_104 ( V_388 ) ;
V_392:
F_114 ( V_295 ) ;
V_391:
F_111 ( V_218 ) ;
V_390:
return V_313 ;
}
static struct V_64 * F_243 ( struct V_2 * V_3 ,
struct V_307 * V_308 ,
int V_219 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_384 )
{
struct V_13 * V_14 = F_94 ( V_3 ) ;
struct V_60 V_61 = { } ;
struct V_64 * V_56 ;
int V_313 ;
do {
V_313 = F_235 ( V_3 , V_308 , V_219 , V_6 , V_7 , V_384 ) ;
V_56 = V_308 -> V_65 ;
F_244 ( V_308 , V_219 , V_313 ) ;
if ( V_313 == 0 )
break;
if ( V_313 == - V_396 ) {
F_245 ( L_5
L_24 ,
F_94 ( V_3 ) -> V_62 -> V_97 ) ;
V_61 . V_68 = 1 ;
continue;
}
if ( V_313 == - V_72 ) {
V_61 . V_68 = 1 ;
continue;
}
if ( V_313 == - V_108 ) {
V_61 . V_68 = 1 ;
continue;
}
if ( F_86 ( V_14 , V_313 , & V_61 ) )
continue;
V_56 = F_52 ( F_31 ( V_14 ,
V_313 , & V_61 ) ) ;
} while ( V_61 . V_68 );
return V_56 ;
}
static int F_246 ( struct V_2 * V_2 , struct V_323 * V_357 ,
struct V_397 * V_398 , struct V_5 * V_6 ,
struct V_64 * V_65 , struct V_1 * V_399 ,
struct V_1 * V_388 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_400 V_401 = {
. V_251 = F_102 ( V_2 ) ,
. V_402 = V_6 ,
. V_14 = V_14 ,
. V_248 = V_14 -> V_15 ,
. V_7 = V_399 ,
} ;
struct V_403 V_56 = {
. V_398 = V_398 ,
. V_7 = V_388 ,
. V_14 = V_14 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_404 ] ,
. V_321 = & V_401 ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
unsigned long V_115 = V_157 ;
T_5 V_188 ;
bool V_405 ;
int V_313 ;
V_401 . V_248 = F_6 ( V_14 , V_399 ) ;
if ( V_399 )
V_401 . V_248 = F_6 ( V_14 , V_388 ) ;
F_90 ( V_398 ) ;
V_405 = ( V_6 -> V_253 & V_406 ) ? true : false ;
V_188 = V_405 ? V_191 : V_190 ;
if ( F_247 ( & V_401 . V_257 , V_2 , V_188 ) ) {
} else if ( V_405 && V_65 != NULL ) {
struct V_407 V_408 = {
. V_409 = V_57 -> V_410 ,
. V_411 = V_57 -> V_412 ,
} ;
if ( ! F_248 ( V_65 ) )
return - V_413 ;
if ( F_249 ( & V_401 . V_257 , V_65 , V_191 ,
& V_408 ) == - V_35 )
return - V_413 ;
} else
F_136 ( & V_401 . V_257 , & V_414 ) ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & V_401 . V_163 , & V_56 . V_164 , 1 ) ;
if ( V_313 == 0 && V_65 != NULL )
F_44 ( V_14 , V_115 ) ;
return V_313 ;
}
static int F_239 ( struct V_2 * V_2 , struct V_323 * V_357 ,
struct V_397 * V_398 , struct V_5 * V_6 ,
struct V_64 * V_65 , struct V_1 * V_399 ,
struct V_1 * V_388 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_60 V_61 = {
. V_65 = V_65 ,
. V_2 = V_2 ,
} ;
int V_8 ;
do {
V_8 = F_246 ( V_2 , V_357 , V_398 , V_6 , V_65 , V_399 , V_388 ) ;
F_250 ( V_2 , V_8 ) ;
switch ( V_8 ) {
case - V_69 :
if ( ! ( V_6 -> V_253 & V_406 ) ) {
F_251 ( L_25
L_26
L_27
L_28 ,
V_14 -> V_62 -> V_97 ) ;
}
if ( V_65 && ! ( V_65 -> V_65 & V_191 ) ) {
V_8 = - V_413 ;
if ( V_6 -> V_253 & V_415 )
V_8 = - V_29 ;
goto V_136;
}
}
V_8 = F_31 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_68 );
V_136:
return V_8 ;
}
static bool
F_252 ( struct V_2 * V_2 , struct V_102 * V_103 )
{
if ( V_2 == NULL || ! F_253 ( V_2 ) )
return false ;
return F_254 ( V_2 , V_103 ) ;
}
static void F_255 ( void * V_161 )
{
struct V_416 * V_159 = V_161 ;
struct V_217 * V_218 = V_159 -> V_65 -> V_232 ;
struct V_259 * V_260 = V_159 -> V_65 -> V_2 -> V_417 ;
if ( V_159 -> V_418 )
F_256 ( V_159 -> V_65 -> V_2 ) ;
F_110 ( V_159 -> V_65 ) ;
F_109 ( V_159 -> V_401 . V_209 ) ;
F_111 ( V_218 ) ;
F_112 ( V_260 ) ;
F_105 ( V_159 ) ;
}
static void F_257 ( struct V_102 * V_103 , void * V_161 )
{
struct V_416 * V_159 = V_161 ;
struct V_64 * V_65 = V_159 -> V_65 ;
struct V_13 * V_14 = F_94 ( V_159 -> V_2 ) ;
T_8 * V_419 = NULL ;
F_8 ( L_29 , V_34 ) ;
if ( ! F_67 ( V_103 , & V_159 -> V_56 . V_164 ) )
return;
F_258 ( V_65 , & V_159 -> V_401 , & V_159 -> V_56 , V_103 -> V_107 ) ;
switch ( V_103 -> V_107 ) {
case 0 :
V_419 = & V_159 -> V_56 . V_257 ;
if ( V_159 -> V_418 )
F_259 ( V_65 -> V_2 ,
V_159 -> V_420 ) ;
F_44 ( V_14 , V_159 -> V_115 ) ;
break;
case - V_71 :
case - V_75 :
case - V_93 :
case - V_72 :
case - V_74 :
if ( ! F_146 ( & V_159 -> V_401 . V_257 ,
& V_65 -> V_278 ) ) {
F_65 ( V_103 ) ;
goto V_421;
}
if ( V_159 -> V_401 . V_188 == 0 )
break;
default:
if ( F_38 ( V_103 , V_14 , V_65 , NULL ) == - V_108 ) {
F_65 ( V_103 ) ;
goto V_421;
}
}
F_137 ( V_65 , & V_159 -> V_401 . V_257 ,
V_419 , V_159 -> V_401 . V_188 ) ;
V_421:
F_152 ( V_159 -> V_401 . V_209 ) ;
F_159 ( V_159 -> V_2 , V_159 -> V_56 . V_398 ) ;
F_8 ( L_30 , V_34 , V_103 -> V_107 ) ;
}
static void F_260 ( struct V_102 * V_103 , void * V_161 )
{
struct V_416 * V_159 = V_161 ;
struct V_64 * V_65 = V_159 -> V_65 ;
struct V_2 * V_2 = V_159 -> V_2 ;
bool V_422 , V_423 , V_424 ;
int V_425 = 0 ;
F_8 ( L_29 , V_34 ) ;
if ( F_192 ( V_159 -> V_401 . V_209 , V_103 ) != 0 )
goto V_329;
V_103 -> V_333 . V_318 = & V_319 [ V_426 ] ;
F_41 ( & V_65 -> V_232 -> V_284 ) ;
V_424 = F_33 ( V_270 , & V_65 -> V_219 ) ;
V_422 = F_33 ( V_268 , & V_65 -> V_219 ) ;
V_423 = F_33 ( V_269 , & V_65 -> V_219 ) ;
F_136 ( & V_159 -> V_401 . V_257 , & V_65 -> V_278 ) ;
V_159 -> V_401 . V_188 = 0 ;
if ( V_65 -> V_262 == 0 ) {
if ( V_65 -> V_264 == 0 )
V_425 |= V_422 ;
else if ( V_422 )
V_159 -> V_401 . V_188 |= V_190 ;
if ( V_65 -> V_263 == 0 )
V_425 |= V_423 ;
else if ( V_423 )
V_159 -> V_401 . V_188 |= V_191 ;
} else if ( V_424 )
V_159 -> V_401 . V_188 |= V_190 | V_191 ;
if ( V_159 -> V_401 . V_188 == 0 )
V_425 |= V_424 ;
if ( ! F_248 ( V_65 ) )
V_425 = 0 ;
F_43 ( & V_65 -> V_232 -> V_284 ) ;
if ( ! V_425 ) {
goto V_330;
}
if ( F_252 ( V_2 , V_103 ) ) {
F_152 ( V_159 -> V_401 . V_209 ) ;
goto V_329;
}
if ( V_159 -> V_401 . V_188 == 0 )
V_103 -> V_333 . V_318 = & V_319 [ V_427 ] ;
if ( V_159 -> V_418 )
F_261 ( V_2 , & V_159 -> V_420 ) ;
V_159 -> V_401 . V_235 =
F_87 ( F_94 ( V_2 ) ,
V_159 -> V_401 . V_188 , 0 ) ;
F_90 ( V_159 -> V_56 . V_398 ) ;
V_159 -> V_115 = V_157 ;
if ( F_70 ( F_94 ( V_2 ) ,
& V_159 -> V_401 . V_163 ,
& V_159 -> V_56 . V_164 ,
V_103 ) != 0 )
F_152 ( V_159 -> V_401 . V_209 ) ;
F_8 ( L_31 , V_34 ) ;
return;
V_330:
V_103 -> V_341 = NULL ;
V_329:
F_67 ( V_103 , & V_159 -> V_56 . V_164 ) ;
}
static bool F_262 ( struct V_2 * V_2 )
{
if ( ! F_253 ( V_2 ) )
return false ;
return F_263 ( V_2 ) ;
}
int F_264 ( struct V_64 * V_65 , T_6 V_221 , int V_428 )
{
struct V_13 * V_14 = F_94 ( V_65 -> V_2 ) ;
struct V_223 * ( * V_224 ) ( struct V_225 * , T_6 ) ;
struct V_416 * V_159 ;
struct V_217 * V_218 = V_65 -> V_232 ;
struct V_102 * V_103 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_427 ] ,
. V_323 = V_65 -> V_232 -> V_298 ,
} ;
struct V_167 V_324 = {
. V_169 = V_14 -> V_98 ,
. V_165 = & V_166 ,
. V_170 = & V_429 ,
. V_326 = V_327 ,
. V_219 = V_328 ,
} ;
int V_313 = - V_132 ;
F_265 ( V_14 -> V_62 , V_430 ,
& V_324 . V_169 , & V_166 ) ;
V_159 = F_95 ( sizeof( * V_159 ) , V_221 ) ;
if ( V_159 == NULL )
goto V_136;
F_46 ( & V_159 -> V_401 . V_163 , & V_159 -> V_56 . V_164 , 1 ) ;
V_159 -> V_2 = V_65 -> V_2 ;
V_159 -> V_65 = V_65 ;
V_159 -> V_401 . V_251 = F_102 ( V_65 -> V_2 ) ;
V_224 = V_14 -> V_62 -> V_171 -> V_224 ;
V_159 -> V_401 . V_209 = V_224 ( & V_65 -> V_232 -> V_229 , V_221 ) ;
if ( F_51 ( V_159 -> V_401 . V_209 ) )
goto V_431;
V_159 -> V_401 . V_188 = 0 ;
V_159 -> V_401 . V_248 = V_14 -> V_432 ;
V_159 -> V_56 . V_398 = & V_159 -> V_398 ;
V_159 -> V_56 . V_209 = V_159 -> V_401 . V_209 ;
V_159 -> V_56 . V_14 = V_14 ;
V_159 -> V_418 = F_262 ( V_65 -> V_2 ) ;
F_97 ( V_159 -> V_2 -> V_417 ) ;
V_166 . V_321 = & V_159 -> V_401 ;
V_166 . V_322 = & V_159 -> V_56 ;
V_324 . V_173 = V_159 ;
V_103 = F_77 ( & V_324 ) ;
if ( F_51 ( V_103 ) )
return F_78 ( V_103 ) ;
V_313 = 0 ;
if ( V_428 )
V_313 = F_117 ( V_103 ) ;
F_79 ( V_103 ) ;
return V_313 ;
V_431:
F_105 ( V_159 ) ;
V_136:
F_110 ( V_65 ) ;
F_111 ( V_218 ) ;
return V_313 ;
}
static struct V_2 *
F_266 ( struct V_2 * V_3 , struct V_307 * V_308 ,
int V_234 , struct V_5 * V_433 , int * V_384 )
{
struct V_64 * V_65 ;
struct V_1 V_17 = { 0 , 0 , 0 , NULL } , * V_7 = NULL ;
V_7 = F_1 ( V_3 , V_308 -> V_4 , V_433 , & V_17 ) ;
V_65 = F_243 ( V_3 , V_308 , V_234 , V_433 , V_7 , V_384 ) ;
F_4 ( V_7 ) ;
if ( F_51 ( V_65 ) )
return F_267 ( V_65 ) ;
return V_65 -> V_2 ;
}
static void F_268 ( struct V_307 * V_308 , int V_434 )
{
if ( V_308 -> V_65 == NULL )
return;
if ( V_434 )
F_269 ( V_308 -> V_65 , V_308 -> V_265 ) ;
else
F_172 ( V_308 -> V_65 , V_308 -> V_265 ) ;
}
static int F_270 ( struct V_13 * V_14 , struct V_435 * V_436 )
{
T_1 V_248 [ 3 ] = {} , V_437 = V_14 -> V_62 -> V_438 ;
struct V_439 args = {
. V_436 = V_436 ,
. V_248 = V_248 ,
} ;
struct V_440 V_56 = {} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_441 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
int V_313 ;
V_248 [ 0 ] = V_442 |
V_443 |
V_444 |
V_445 |
V_446 ;
if ( V_437 )
V_248 [ 2 ] = V_447 ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
if ( V_313 == 0 ) {
switch ( V_437 ) {
case 0 :
V_56 . V_15 [ 1 ] &= V_448 ;
V_56 . V_15 [ 2 ] = 0 ;
break;
case 1 :
V_56 . V_15 [ 2 ] &= V_449 ;
break;
case 2 :
V_56 . V_15 [ 2 ] &= V_450 ;
}
memcpy ( V_14 -> V_15 , V_56 . V_15 , sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_94 &= ~ ( V_451 | V_452 |
V_453 | V_454 |
V_455 | V_456 | V_457 |
V_458 | V_459 |
V_460 | V_461 |
V_9 ) ;
if ( V_56 . V_15 [ 0 ] & V_462 &&
V_56 . V_463 & V_464 )
V_14 -> V_94 |= V_451 ;
if ( V_56 . V_465 != 0 )
V_14 -> V_94 |= V_452 ;
if ( V_56 . V_466 != 0 )
V_14 -> V_94 |= V_453 ;
if ( V_56 . V_15 [ 0 ] & V_45 )
V_14 -> V_94 |= V_454 ;
if ( V_56 . V_15 [ 1 ] & V_378 )
V_14 -> V_94 |= V_455 ;
if ( V_56 . V_15 [ 1 ] & V_467 )
V_14 -> V_94 |= V_456 ;
if ( V_56 . V_15 [ 1 ] & V_468 )
V_14 -> V_94 |= V_457 ;
if ( V_56 . V_15 [ 1 ] & V_469 )
V_14 -> V_94 |= V_458 ;
if ( V_56 . V_15 [ 1 ] & V_372 )
V_14 -> V_94 |= V_459 ;
if ( V_56 . V_15 [ 1 ] & V_470 )
V_14 -> V_94 |= V_460 ;
if ( V_56 . V_15 [ 1 ] & V_375 )
V_14 -> V_94 |= V_461 ;
#ifdef F_271
if ( V_56 . V_15 [ 2 ] & V_380 )
V_14 -> V_94 |= V_9 ;
#endif
memcpy ( V_14 -> V_16 , V_56 . V_15 ,
sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_16 [ 2 ] &= ~ V_380 ;
memcpy ( V_14 -> V_432 , V_56 . V_15 , sizeof( V_14 -> V_432 ) ) ;
V_14 -> V_432 [ 0 ] &= V_471 | V_472 ;
V_14 -> V_432 [ 1 ] &= V_470 | V_375 ;
V_14 -> V_432 [ 2 ] = 0 ;
memcpy ( V_14 -> V_473 , V_56 . V_473 ,
sizeof( V_14 -> V_473 ) ) ;
V_14 -> V_463 = V_56 . V_463 ;
V_14 -> V_474 = V_56 . V_474 ;
}
return V_313 ;
}
int F_272 ( struct V_13 * V_14 , struct V_435 * V_436 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_31 ( V_14 ,
F_270 ( V_14 , V_436 ) ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_273 ( struct V_13 * V_14 , struct V_435 * V_436 ,
struct V_475 * V_476 )
{
T_1 V_248 [ 3 ] ;
struct V_477 args = {
. V_248 = V_248 ,
} ;
struct V_478 V_56 = {
. V_14 = V_14 ,
. V_398 = V_476 -> V_398 ,
. V_251 = V_436 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_479 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
V_248 [ 0 ] = V_250 [ 0 ] ;
V_248 [ 1 ] = V_250 [ 1 ] ;
V_248 [ 2 ] = V_250 [ 2 ] & ~ V_380 ;
F_90 ( V_476 -> V_398 ) ;
return F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
}
static int F_274 ( struct V_13 * V_14 , struct V_435 * V_436 ,
struct V_475 * V_476 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_273 ( V_14 , V_436 , V_476 ) ;
F_275 ( V_14 , V_436 , V_476 -> V_398 , V_8 ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
goto V_136;
default:
V_8 = F_31 ( V_14 , V_8 , & V_61 ) ;
}
} while ( V_61 . V_68 );
V_136:
return V_8 ;
}
static int F_276 ( struct V_13 * V_14 , struct V_435 * V_436 ,
struct V_475 * V_476 , T_4 V_109 )
{
struct V_480 V_481 = {
. V_482 = V_109 ,
} ;
struct V_483 * V_484 ;
int V_51 ;
V_484 = F_277 ( & V_481 , V_14 -> V_98 ) ;
if ( F_51 ( V_484 ) ) {
V_51 = - V_29 ;
goto V_136;
}
V_51 = F_274 ( V_14 , V_436 , V_476 ) ;
V_136:
return V_51 ;
}
static int F_278 ( struct V_13 * V_14 , struct V_435 * V_436 ,
struct V_475 * V_476 )
{
static const T_4 V_485 [] = {
V_114 ,
V_113 ,
V_486 ,
V_487 ,
V_488 ,
} ;
int V_313 = - V_24 ;
T_9 V_489 ;
if ( V_14 -> V_490 . V_491 > 0 ) {
for ( V_489 = 0 ; V_489 < V_14 -> V_490 . V_491 ; V_489 ++ ) {
V_313 = F_276 ( V_14 , V_436 , V_476 ,
V_14 -> V_490 . V_492 [ V_489 ] ) ;
if ( V_313 == - V_22 || V_313 == - V_29 )
continue;
break;
}
} else {
for ( V_489 = 0 ; V_489 < F_279 ( V_485 ) ; V_489 ++ ) {
V_313 = F_276 ( V_14 , V_436 , V_476 ,
V_485 [ V_489 ] ) ;
if ( V_313 == - V_22 || V_313 == - V_29 )
continue;
break;
}
}
if ( V_313 == - V_29 )
V_313 = - V_24 ;
return V_313 ;
}
static int F_280 ( struct V_13 * V_14 ,
struct V_435 * V_436 , struct V_475 * V_476 )
{
int V_493 = V_14 -> V_62 -> V_438 ;
return V_494 [ V_493 ] -> F_281 ( V_14 , V_436 , V_476 ) ;
}
int F_282 ( struct V_13 * V_14 , struct V_435 * V_436 ,
struct V_475 * V_476 ,
bool V_495 )
{
int V_313 = 0 ;
if ( ! V_495 )
V_313 = F_274 ( V_14 , V_436 , V_476 ) ;
if ( V_495 || V_313 == V_22 )
V_313 = F_280 ( V_14 , V_436 , V_476 ) ;
if ( V_313 == 0 )
V_313 = F_272 ( V_14 , V_436 ) ;
if ( V_313 == 0 )
V_313 = F_283 ( V_14 , V_436 , V_476 ) ;
return F_7 ( V_313 ) ;
}
static int F_284 ( struct V_13 * V_14 , struct V_435 * V_496 ,
struct V_475 * V_476 )
{
int error ;
struct V_397 * V_398 = V_476 -> V_398 ;
struct V_1 * V_7 = NULL ;
error = F_272 ( V_14 , V_496 ) ;
if ( error < 0 ) {
F_8 ( L_32 , - error ) ;
return error ;
}
V_7 = F_96 ( V_14 , V_389 ) ;
if ( F_51 ( V_7 ) )
return F_78 ( V_7 ) ;
error = F_203 ( V_14 , V_496 , V_398 , V_7 ) ;
if ( error < 0 ) {
F_8 ( L_33 , - error ) ;
goto V_230;
}
if ( V_398 -> V_304 & V_497 &&
! F_285 ( & V_14 -> V_498 , & V_398 -> V_498 ) )
memcpy ( & V_14 -> V_498 , & V_398 -> V_498 , sizeof( V_14 -> V_498 ) ) ;
V_230:
F_104 ( V_7 ) ;
return error ;
}
static int F_286 ( struct V_54 * V_98 , struct V_2 * V_3 ,
const struct V_499 * V_247 , struct V_397 * V_398 ,
struct V_435 * V_436 )
{
int V_313 = - V_132 ;
struct V_500 * V_500 = NULL ;
struct V_501 * V_502 = NULL ;
V_500 = F_287 ( V_389 ) ;
if ( V_500 == NULL )
goto V_136;
V_502 = F_288 ( sizeof( struct V_501 ) , V_389 ) ;
if ( V_502 == NULL )
goto V_136;
V_313 = F_289 ( V_98 , V_3 , V_247 , V_502 , V_500 ) ;
if ( V_313 != 0 )
goto V_136;
if ( F_285 ( & F_94 ( V_3 ) -> V_498 , & V_502 -> V_398 . V_498 ) ) {
F_8 ( L_34
L_35 , V_34 , V_247 -> V_247 ) ;
V_313 = - V_77 ;
goto V_136;
}
F_290 ( & V_502 -> V_398 ) ;
memcpy ( V_398 , & V_502 -> V_398 , sizeof( struct V_397 ) ) ;
memset ( V_436 , 0 , sizeof( struct V_435 ) ) ;
V_136:
if ( V_500 )
F_291 ( V_500 ) ;
F_105 ( V_502 ) ;
return V_313 ;
}
static int F_292 ( struct V_13 * V_14 , struct V_435 * V_436 ,
struct V_397 * V_398 , struct V_1 * V_7 )
{
struct V_503 args = {
. V_251 = V_436 ,
. V_248 = V_14 -> V_15 ,
} ;
struct V_504 V_56 = {
. V_398 = V_398 ,
. V_7 = V_7 ,
. V_14 = V_14 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_505 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
args . V_248 = F_6 ( V_14 , V_7 ) ;
F_90 ( V_398 ) ;
return F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
}
static int F_203 ( struct V_13 * V_14 , struct V_435 * V_436 ,
struct V_397 * V_398 , struct V_1 * V_7 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_292 ( V_14 , V_436 , V_398 , V_7 ) ;
F_293 ( V_14 , V_436 , V_398 , V_8 ) ;
V_8 = F_31 ( V_14 , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int
F_294 ( struct V_4 * V_4 , struct V_397 * V_398 ,
struct V_5 * V_6 )
{
struct V_2 * V_2 = F_14 ( V_4 ) ;
struct V_323 * V_357 = NULL ;
struct V_64 * V_65 = NULL ;
struct V_1 * V_7 = NULL ;
int V_313 ;
if ( F_295 ( V_2 ) &&
V_6 -> V_253 & V_406 &&
V_6 -> V_506 < F_296 ( V_2 ) )
F_297 ( V_2 ) ;
F_90 ( V_398 ) ;
if ( V_6 -> V_253 & V_415 )
V_6 -> V_253 &= ~ ( V_377 | V_507 ) ;
if ( ( V_6 -> V_253 & ~ ( V_508 | V_415 ) ) == 0 )
return 0 ;
if ( V_6 -> V_253 & V_508 ) {
struct V_307 * V_308 ;
V_308 = F_298 ( V_6 -> V_509 ) ;
if ( V_308 ) {
V_357 = V_308 -> V_357 ;
V_65 = V_308 -> V_65 ;
}
}
V_7 = F_96 ( F_94 ( V_2 ) , V_389 ) ;
if ( F_51 ( V_7 ) )
return F_78 ( V_7 ) ;
V_313 = F_239 ( V_2 , V_357 , V_398 , V_6 , V_65 , NULL , V_7 ) ;
if ( V_313 == 0 ) {
F_240 ( V_2 , V_6 , V_398 ) ;
F_241 ( V_2 , V_398 , V_7 ) ;
}
F_104 ( V_7 ) ;
return V_313 ;
}
static int F_299 ( struct V_54 * V_55 , struct V_2 * V_3 ,
const struct V_499 * V_247 , struct V_435 * V_436 ,
struct V_397 * V_398 , struct V_1 * V_7 )
{
struct V_13 * V_14 = F_94 ( V_3 ) ;
int V_313 ;
struct V_510 args = {
. V_248 = V_14 -> V_15 ,
. V_511 = F_102 ( V_3 ) ,
. V_247 = V_247 ,
} ;
struct V_478 V_56 = {
. V_14 = V_14 ,
. V_398 = V_398 ,
. V_7 = V_7 ,
. V_251 = V_436 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_512 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
args . V_248 = F_6 ( V_14 , V_7 ) ;
F_90 ( V_398 ) ;
F_8 ( L_36 , V_247 -> V_247 ) ;
V_313 = F_80 ( V_55 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
F_8 ( L_37 , V_313 ) ;
return V_313 ;
}
static void F_300 ( struct V_397 * V_398 )
{
V_398 -> V_304 |= V_342 | V_513 |
V_514 | V_515 ;
V_398 -> V_265 = V_347 | V_516 | V_517 ;
V_398 -> V_518 = 2 ;
}
static int F_301 ( struct V_54 * * V_55 , struct V_2 * V_3 ,
struct V_499 * V_247 , struct V_435 * V_436 ,
struct V_397 * V_398 , struct V_1 * V_7 )
{
struct V_60 V_61 = { } ;
struct V_54 * V_98 = * V_55 ;
int V_8 ;
do {
V_8 = F_299 ( V_98 , V_3 , V_247 , V_436 , V_398 , V_7 ) ;
F_302 ( V_3 , V_247 , V_8 ) ;
switch ( V_8 ) {
case - V_26 :
V_8 = - V_309 ;
goto V_136;
case - V_77 :
V_8 = F_286 ( V_98 , V_3 , V_247 , V_398 , V_436 ) ;
if ( V_8 == - V_77 )
V_8 = F_31 ( F_94 ( V_3 ) , V_8 , & V_61 ) ;
goto V_136;
case - V_22 :
V_8 = - V_24 ;
if ( V_98 != * V_55 )
goto V_136;
V_98 = F_303 ( V_98 , V_3 , V_247 ) ;
if ( F_51 ( V_98 ) )
return F_78 ( V_98 ) ;
V_61 . V_68 = 1 ;
break;
default:
V_8 = F_31 ( F_94 ( V_3 ) , V_8 , & V_61 ) ;
}
} while ( V_61 . V_68 );
V_136:
if ( V_8 == 0 )
* V_55 = V_98 ;
else if ( V_98 != * V_55 )
F_304 ( V_98 ) ;
return V_8 ;
}
static int F_305 ( struct V_2 * V_3 , struct V_499 * V_247 ,
struct V_435 * V_436 , struct V_397 * V_398 ,
struct V_1 * V_7 )
{
int V_313 ;
struct V_54 * V_98 = F_306 ( V_3 ) ;
V_313 = F_301 ( & V_98 , V_3 , V_247 , V_436 , V_398 , V_7 ) ;
if ( V_98 != F_306 ( V_3 ) ) {
F_304 ( V_98 ) ;
F_300 ( V_398 ) ;
}
return V_313 ;
}
struct V_54 *
F_307 ( struct V_2 * V_3 , struct V_499 * V_247 ,
struct V_435 * V_436 , struct V_397 * V_398 )
{
struct V_54 * V_98 = F_306 ( V_3 ) ;
int V_313 ;
V_313 = F_301 ( & V_98 , V_3 , V_247 , V_436 , V_398 , NULL ) ;
if ( V_313 < 0 )
return F_52 ( V_313 ) ;
return ( V_98 == F_306 ( V_3 ) ) ? F_308 ( V_98 ) : V_98 ;
}
static int F_309 ( struct V_2 * V_2 , struct V_358 * V_519 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_520 args = {
. V_251 = F_102 ( V_2 ) ,
. V_248 = V_14 -> V_432 ,
} ;
struct V_521 V_56 = {
. V_14 = V_14 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_522 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_519 -> V_357 ,
} ;
int V_265 = V_519 -> V_360 ;
int V_313 = 0 ;
if ( V_265 & V_365 )
args . V_214 |= V_237 ;
if ( F_310 ( V_2 -> V_523 ) ) {
if ( V_265 & V_524 )
args . V_214 |= V_238 | V_239 | V_525 ;
if ( V_265 & V_363 )
args . V_214 |= V_526 ;
} else {
if ( V_265 & V_524 )
args . V_214 |= V_238 | V_239 ;
if ( V_265 & V_363 )
args . V_214 |= V_240 ;
}
V_56 . V_398 = F_311 () ;
if ( V_56 . V_398 == NULL )
return - V_132 ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
if ( ! V_313 ) {
F_200 ( V_519 , V_56 . V_214 ) ;
F_159 ( V_2 , V_56 . V_398 ) ;
}
F_312 ( V_56 . V_398 ) ;
return V_313 ;
}
static int F_313 ( struct V_2 * V_2 , struct V_358 * V_519 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_309 ( V_2 , V_519 ) ;
F_314 ( V_2 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_315 ( struct V_2 * V_2 , struct V_500 * V_500 ,
unsigned int V_48 , unsigned int V_527 )
{
struct V_528 args = {
. V_251 = F_102 ( V_2 ) ,
. V_48 = V_48 ,
. V_527 = V_527 ,
. V_42 = & V_500 ,
} ;
struct V_529 V_56 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_530 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
return F_80 ( F_94 ( V_2 ) -> V_98 , F_94 ( V_2 ) , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
}
static int F_316 ( struct V_2 * V_2 , struct V_500 * V_500 ,
unsigned int V_48 , unsigned int V_527 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_315 ( V_2 , V_500 , V_48 , V_527 ) ;
F_317 ( V_2 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int
F_318 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_5 * V_6 ,
int V_219 )
{
struct V_1 V_17 , * V_399 = NULL ;
struct V_307 * V_308 ;
struct V_64 * V_65 ;
int V_313 = 0 ;
V_308 = F_319 ( V_4 , V_190 ) ;
if ( F_51 ( V_308 ) )
return F_78 ( V_308 ) ;
V_399 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_320 () ;
V_65 = F_243 ( V_3 , V_308 , V_219 , V_6 , V_399 , NULL ) ;
if ( F_51 ( V_65 ) ) {
V_313 = F_78 ( V_65 ) ;
goto V_136;
}
V_136:
F_4 ( V_399 ) ;
F_179 ( V_308 ) ;
return V_313 ;
}
static int F_321 ( struct V_2 * V_3 , struct V_499 * V_247 )
{
struct V_13 * V_14 = F_94 ( V_3 ) ;
struct V_531 args = {
. V_251 = F_102 ( V_3 ) ,
. V_247 = * V_247 ,
} ;
struct V_532 V_56 = {
. V_14 = V_14 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_533 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
int V_313 ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 1 ) ;
if ( V_313 == 0 )
F_81 ( V_3 , & V_56 . V_175 ) ;
return V_313 ;
}
static int F_322 ( struct V_2 * V_3 , struct V_499 * V_247 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_321 ( V_3 , V_247 ) ;
F_323 ( V_3 , V_247 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static void F_324 ( struct V_165 * V_166 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_94 ( V_3 ) ;
struct V_531 * args = V_166 -> V_321 ;
struct V_532 * V_56 = V_166 -> V_322 ;
V_56 -> V_14 = V_14 ;
V_166 -> V_318 = & V_319 [ V_533 ] ;
F_46 ( & args -> V_163 , & V_56 -> V_164 , 1 ) ;
F_90 ( V_56 -> V_534 ) ;
}
static void F_325 ( struct V_102 * V_103 , struct V_535 * V_161 )
{
F_70 ( F_94 ( V_161 -> V_3 ) ,
& V_161 -> args . V_163 ,
& V_161 -> V_56 . V_164 ,
V_103 ) ;
}
static int F_326 ( struct V_102 * V_103 , struct V_2 * V_3 )
{
struct V_535 * V_161 = V_103 -> V_536 ;
struct V_532 * V_56 = & V_161 -> V_56 ;
if ( ! F_67 ( V_103 , & V_56 -> V_164 ) )
return 0 ;
if ( F_38 ( V_103 , V_56 -> V_14 , NULL ,
& V_161 -> V_50 ) == - V_108 )
return 0 ;
F_81 ( V_3 , & V_56 -> V_175 ) ;
return 1 ;
}
static void F_327 ( struct V_165 * V_166 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_94 ( V_3 ) ;
struct V_537 * V_401 = V_166 -> V_321 ;
struct V_538 * V_56 = V_166 -> V_322 ;
V_166 -> V_318 = & V_319 [ V_539 ] ;
V_56 -> V_14 = V_14 ;
F_46 ( & V_401 -> V_163 , & V_56 -> V_164 , 1 ) ;
}
static void F_328 ( struct V_102 * V_103 , struct V_540 * V_161 )
{
F_70 ( F_94 ( V_161 -> V_541 ) ,
& V_161 -> args . V_163 ,
& V_161 -> V_56 . V_164 ,
V_103 ) ;
}
static int F_329 ( struct V_102 * V_103 , struct V_2 * V_541 ,
struct V_2 * V_542 )
{
struct V_540 * V_161 = V_103 -> V_536 ;
struct V_538 * V_56 = & V_161 -> V_56 ;
if ( ! F_67 ( V_103 , & V_56 -> V_164 ) )
return 0 ;
if ( F_38 ( V_103 , V_56 -> V_14 , NULL , & V_161 -> V_50 ) == - V_108 )
return 0 ;
F_81 ( V_541 , & V_56 -> V_543 ) ;
F_81 ( V_542 , & V_56 -> V_544 ) ;
return 1 ;
}
static int F_330 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_499 * V_247 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_545 V_401 = {
. V_251 = F_102 ( V_2 ) ,
. V_511 = F_102 ( V_3 ) ,
. V_247 = V_247 ,
. V_248 = V_14 -> V_15 ,
} ;
struct V_546 V_56 = {
. V_14 = V_14 ,
. V_7 = NULL ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_547 ] ,
. V_321 = & V_401 ,
. V_322 = & V_56 ,
} ;
int V_313 = - V_132 ;
V_56 . V_398 = F_311 () ;
if ( V_56 . V_398 == NULL )
goto V_136;
V_56 . V_7 = F_96 ( V_14 , V_389 ) ;
if ( F_51 ( V_56 . V_7 ) ) {
V_313 = F_78 ( V_56 . V_7 ) ;
goto V_136;
}
V_401 . V_248 = F_6 ( V_14 , V_56 . V_7 ) ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & V_401 . V_163 , & V_56 . V_164 , 1 ) ;
if ( ! V_313 ) {
F_81 ( V_3 , & V_56 . V_175 ) ;
V_313 = F_331 ( V_2 , V_56 . V_398 ) ;
if ( ! V_313 )
F_241 ( V_2 , V_56 . V_398 , V_56 . V_7 ) ;
}
F_104 ( V_56 . V_7 ) ;
V_136:
F_312 ( V_56 . V_398 ) ;
return V_313 ;
}
static int F_332 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_499 * V_247 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_31 ( F_94 ( V_2 ) ,
F_330 ( V_2 , V_3 , V_247 ) ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static struct V_548 * F_333 ( struct V_2 * V_3 ,
struct V_499 * V_247 , struct V_5 * V_6 , T_1 V_549 )
{
struct V_548 * V_161 ;
V_161 = F_95 ( sizeof( * V_161 ) , V_389 ) ;
if ( V_161 != NULL ) {
struct V_13 * V_14 = F_94 ( V_3 ) ;
V_161 -> V_7 = F_96 ( V_14 , V_389 ) ;
if ( F_51 ( V_161 -> V_7 ) )
goto V_317;
V_161 -> V_166 . V_318 = & V_319 [ V_550 ] ;
V_161 -> V_166 . V_321 = & V_161 -> V_401 ;
V_161 -> V_166 . V_322 = & V_161 -> V_56 ;
V_161 -> V_401 . V_511 = F_102 ( V_3 ) ;
V_161 -> V_401 . V_14 = V_14 ;
V_161 -> V_401 . V_247 = V_247 ;
V_161 -> V_401 . V_220 = V_6 ;
V_161 -> V_401 . V_549 = V_549 ;
V_161 -> V_401 . V_248 = F_6 ( V_14 , V_161 -> V_7 ) ;
V_161 -> V_56 . V_14 = V_14 ;
V_161 -> V_56 . V_251 = & V_161 -> V_251 ;
V_161 -> V_56 . V_398 = & V_161 -> V_398 ;
V_161 -> V_56 . V_7 = V_161 -> V_7 ;
F_90 ( V_161 -> V_56 . V_398 ) ;
}
return V_161 ;
V_317:
F_105 ( V_161 ) ;
return NULL ;
}
static int F_334 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_548 * V_161 )
{
int V_313 = F_80 ( F_94 ( V_3 ) -> V_98 , F_94 ( V_3 ) , & V_161 -> V_166 ,
& V_161 -> V_401 . V_163 , & V_161 -> V_56 . V_164 , 1 ) ;
if ( V_313 == 0 ) {
F_81 ( V_3 , & V_161 -> V_56 . V_551 ) ;
V_313 = F_335 ( V_4 , V_161 -> V_56 . V_251 , V_161 -> V_56 . V_398 , V_161 -> V_56 . V_7 ) ;
}
return V_313 ;
}
static void F_336 ( struct V_548 * V_161 )
{
F_104 ( V_161 -> V_7 ) ;
F_105 ( V_161 ) ;
}
static int F_337 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_500 * V_500 , unsigned int V_12 , struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_548 * V_161 ;
int V_313 = - V_552 ;
if ( V_12 > V_553 )
goto V_136;
V_313 = - V_132 ;
V_161 = F_333 ( V_3 , & V_4 -> V_11 , V_6 , V_554 ) ;
if ( V_161 == NULL )
goto V_136;
V_161 -> V_166 . V_318 = & V_319 [ V_555 ] ;
V_161 -> V_401 . V_255 . V_556 . V_42 = & V_500 ;
V_161 -> V_401 . V_255 . V_556 . V_12 = V_12 ;
V_161 -> V_401 . V_7 = V_7 ;
V_313 = F_334 ( V_3 , V_4 , V_161 ) ;
F_336 ( V_161 ) ;
V_136:
return V_313 ;
}
static int F_338 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_500 * V_500 , unsigned int V_12 , struct V_5 * V_6 )
{
struct V_60 V_61 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
do {
V_8 = F_337 ( V_3 , V_4 , V_500 , V_12 , V_6 , V_7 ) ;
F_339 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_340 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_548 * V_161 ;
int V_313 = - V_132 ;
V_161 = F_333 ( V_3 , & V_4 -> V_11 , V_6 , V_557 ) ;
if ( V_161 == NULL )
goto V_136;
V_161 -> V_401 . V_7 = V_7 ;
V_313 = F_334 ( V_3 , V_4 , V_161 ) ;
F_336 ( V_161 ) ;
V_136:
return V_313 ;
}
static int F_341 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 )
{
struct V_60 V_61 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_320 () ;
do {
V_8 = F_340 ( V_3 , V_4 , V_6 , V_7 ) ;
F_342 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_343 ( struct V_4 * V_4 , struct V_323 * V_357 ,
T_2 V_36 , struct V_500 * * V_42 , unsigned int V_49 , int V_558 )
{
struct V_2 * V_3 = F_14 ( V_4 ) ;
struct V_38 args = {
. V_251 = F_102 ( V_3 ) ,
. V_42 = V_42 ,
. V_48 = 0 ,
. V_49 = V_49 ,
. V_248 = F_94 ( F_14 ( V_4 ) ) -> V_15 ,
. V_558 = V_558 ,
} ;
struct V_559 V_56 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_560 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
int V_313 ;
F_8 ( L_38 , V_34 ,
V_4 ,
( unsigned long long ) V_36 ) ;
F_9 ( V_36 , F_82 ( V_3 ) -> V_561 , V_4 , & args ) ;
V_56 . V_48 = args . V_48 ;
V_313 = F_80 ( F_94 ( V_3 ) -> V_98 , F_94 ( V_3 ) , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
if ( V_313 >= 0 ) {
memcpy ( F_82 ( V_3 ) -> V_561 , V_56 . V_37 . V_161 , V_562 ) ;
V_313 += args . V_48 ;
}
F_344 ( V_3 ) ;
F_8 ( L_39 , V_34 , V_313 ) ;
return V_313 ;
}
static int F_345 ( struct V_4 * V_4 , struct V_323 * V_357 ,
T_2 V_36 , struct V_500 * * V_42 , unsigned int V_49 , int V_558 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_343 ( V_4 , V_357 , V_36 ,
V_42 , V_49 , V_558 ) ;
F_346 ( F_14 ( V_4 ) , V_8 ) ;
V_8 = F_31 ( F_94 ( F_14 ( V_4 ) ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_347 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 , T_10 V_563 )
{
struct V_548 * V_161 ;
int V_265 = V_6 -> V_10 ;
int V_313 = - V_132 ;
V_161 = F_333 ( V_3 , & V_4 -> V_11 , V_6 , V_564 ) ;
if ( V_161 == NULL )
goto V_136;
if ( F_348 ( V_265 ) )
V_161 -> V_401 . V_549 = V_565 ;
else if ( F_349 ( V_265 ) ) {
V_161 -> V_401 . V_549 = V_566 ;
V_161 -> V_401 . V_255 . V_567 . V_568 = F_350 ( V_563 ) ;
V_161 -> V_401 . V_255 . V_567 . V_569 = F_351 ( V_563 ) ;
}
else if ( F_352 ( V_265 ) ) {
V_161 -> V_401 . V_549 = V_570 ;
V_161 -> V_401 . V_255 . V_567 . V_568 = F_350 ( V_563 ) ;
V_161 -> V_401 . V_255 . V_567 . V_569 = F_351 ( V_563 ) ;
} else if ( ! F_353 ( V_265 ) ) {
V_313 = - V_27 ;
goto V_317;
}
V_161 -> V_401 . V_7 = V_7 ;
V_313 = F_334 ( V_3 , V_4 , V_161 ) ;
V_317:
F_336 ( V_161 ) ;
V_136:
return V_313 ;
}
static int F_354 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , T_10 V_563 )
{
struct V_60 V_61 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_320 () ;
do {
V_8 = F_347 ( V_3 , V_4 , V_6 , V_7 , V_563 ) ;
F_355 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_356 ( struct V_13 * V_14 , struct V_435 * V_436 ,
struct V_571 * V_572 )
{
struct V_573 args = {
. V_251 = V_436 ,
. V_248 = V_14 -> V_15 ,
} ;
struct V_574 V_56 = {
. V_572 = V_572 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_575 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
F_90 ( V_572 -> V_398 ) ;
return F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
}
static int F_357 ( struct V_13 * V_14 , struct V_435 * V_436 , struct V_571 * V_572 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_31 ( V_14 ,
F_356 ( V_14 , V_436 , V_572 ) ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_358 ( struct V_13 * V_14 , struct V_435 * V_436 ,
struct V_475 * V_576 )
{
struct V_577 args = {
. V_251 = V_436 ,
. V_248 = V_14 -> V_15 ,
} ;
struct V_578 V_56 = {
. V_576 = V_576 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_579 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
return F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
}
static int F_283 ( struct V_13 * V_14 , struct V_435 * V_436 , struct V_475 * V_576 )
{
struct V_60 V_61 = { } ;
unsigned long V_580 = V_157 ;
int V_8 ;
do {
V_8 = F_358 ( V_14 , V_436 , V_576 ) ;
F_359 ( V_14 , V_436 , V_576 -> V_398 , V_8 ) ;
if ( V_8 == 0 ) {
struct V_62 * V_63 = V_14 -> V_62 ;
F_41 ( & V_63 -> V_116 ) ;
V_63 -> V_581 = V_576 -> V_582 * V_88 ;
V_63 -> V_117 = V_580 ;
F_43 ( & V_63 -> V_116 ) ;
break;
}
V_8 = F_31 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_360 ( struct V_13 * V_14 , struct V_435 * V_436 , struct V_475 * V_576 )
{
int error ;
F_90 ( V_576 -> V_398 ) ;
error = F_283 ( V_14 , V_436 , V_576 ) ;
if ( error == 0 ) {
V_14 -> V_583 = V_576 -> V_584 ;
F_361 ( V_14 , V_436 , V_576 -> V_585 ) ;
}
return error ;
}
static int F_362 ( struct V_13 * V_14 , struct V_435 * V_436 ,
struct V_586 * V_587 )
{
struct V_588 args = {
. V_251 = V_436 ,
. V_248 = V_14 -> V_15 ,
} ;
struct V_589 V_56 = {
. V_587 = V_587 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_590 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
if ( ( args . V_248 [ 0 ] & V_591 [ 0 ] ) == 0 ) {
memset ( V_587 , 0 , sizeof( * V_587 ) ) ;
return 0 ;
}
F_90 ( V_587 -> V_398 ) ;
return F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
}
static int F_363 ( struct V_13 * V_14 , struct V_435 * V_436 ,
struct V_586 * V_587 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_31 ( V_14 ,
F_362 ( V_14 , V_436 , V_587 ) ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
int F_364 ( T_8 * V_257 ,
const struct V_307 * V_308 ,
const struct V_592 * V_593 ,
T_5 V_188 )
{
const struct V_407 * V_408 = NULL ;
if ( V_593 != NULL )
V_408 = & V_593 -> V_408 ;
return F_249 ( V_257 , V_308 -> V_65 , V_188 , V_408 ) ;
}
static bool F_365 ( T_8 * V_257 ,
const struct V_307 * V_308 ,
const struct V_592 * V_593 ,
T_5 V_188 )
{
T_8 V_594 ;
if ( F_364 ( & V_594 , V_308 , V_593 , V_188 ) == - V_35 )
return true ;
return F_146 ( V_257 , & V_594 ) ;
}
static bool F_366 ( int V_8 )
{
switch ( V_8 ) {
case - V_70 :
case - V_71 :
case - V_72 :
case - V_75 :
case - V_93 :
case - V_69 :
case - V_74 :
return true ;
}
return false ;
}
void F_367 ( struct V_595 * V_596 )
{
F_344 ( V_596 -> V_2 ) ;
}
static int F_368 ( struct V_102 * V_103 , struct V_595 * V_596 )
{
struct V_13 * V_14 = F_94 ( V_596 -> V_2 ) ;
F_369 ( V_596 , V_103 -> V_107 ) ;
if ( F_38 ( V_103 , V_14 ,
V_596 -> args . V_597 -> V_65 ,
NULL ) == - V_108 ) {
F_65 ( V_103 ) ;
return - V_108 ;
}
F_367 ( V_596 ) ;
if ( V_103 -> V_107 > 0 )
F_44 ( V_14 , V_596 -> V_115 ) ;
return 0 ;
}
static bool F_370 ( struct V_102 * V_103 ,
struct V_598 * args )
{
if ( ! F_366 ( V_103 -> V_107 ) ||
F_365 ( & args -> V_257 ,
args -> V_597 ,
args -> V_599 ,
V_190 ) )
return false ;
F_65 ( V_103 ) ;
return true ;
}
static int F_371 ( struct V_102 * V_103 , struct V_595 * V_596 )
{
F_8 ( L_11 , V_34 ) ;
if ( ! F_67 ( V_103 , & V_596 -> V_56 . V_164 ) )
return - V_108 ;
if ( F_370 ( V_103 , & V_596 -> args ) )
return - V_108 ;
return V_596 -> V_600 ? V_596 -> V_600 ( V_103 , V_596 ) :
F_368 ( V_103 , V_596 ) ;
}
static void F_372 ( struct V_595 * V_596 ,
struct V_165 * V_166 )
{
V_596 -> V_115 = V_157 ;
V_596 -> V_600 = F_368 ;
V_166 -> V_318 = & V_319 [ V_601 ] ;
F_46 ( & V_596 -> args . V_163 , & V_596 -> V_56 . V_164 , 0 ) ;
}
static int F_373 ( struct V_102 * V_103 ,
struct V_595 * V_596 )
{
if ( F_70 ( F_94 ( V_596 -> V_2 ) ,
& V_596 -> args . V_163 ,
& V_596 -> V_56 . V_164 ,
V_103 ) )
return 0 ;
if ( F_364 ( & V_596 -> args . V_257 , V_596 -> args . V_597 ,
V_596 -> args . V_599 ,
V_596 -> V_602 -> V_603 ) == - V_35 )
return - V_35 ;
if ( F_374 ( F_33 ( V_604 , & V_596 -> args . V_597 -> V_219 ) ) )
return - V_35 ;
return 0 ;
}
static int F_375 ( struct V_102 * V_103 ,
struct V_595 * V_596 )
{
struct V_2 * V_2 = V_596 -> V_2 ;
F_376 ( V_596 , V_103 -> V_107 ) ;
if ( F_38 ( V_103 , F_94 ( V_2 ) ,
V_596 -> args . V_597 -> V_65 ,
NULL ) == - V_108 ) {
F_65 ( V_103 ) ;
return - V_108 ;
}
if ( V_103 -> V_107 >= 0 ) {
F_44 ( F_94 ( V_2 ) , V_596 -> V_115 ) ;
F_377 ( V_596 ) ;
}
return 0 ;
}
static bool F_378 ( struct V_102 * V_103 ,
struct V_598 * args )
{
if ( ! F_366 ( V_103 -> V_107 ) ||
F_365 ( & args -> V_257 ,
args -> V_597 ,
args -> V_599 ,
V_191 ) )
return false ;
F_65 ( V_103 ) ;
return true ;
}
static int F_379 ( struct V_102 * V_103 , struct V_595 * V_596 )
{
if ( ! F_67 ( V_103 , & V_596 -> V_56 . V_164 ) )
return - V_108 ;
if ( F_378 ( V_103 , & V_596 -> args ) )
return - V_108 ;
return V_596 -> V_600 ? V_596 -> V_600 ( V_103 , V_596 ) :
F_375 ( V_103 , V_596 ) ;
}
static
bool F_380 ( struct V_595 * V_596 )
{
if ( V_596 -> V_605 != NULL || V_596 -> V_606 != NULL )
return false ;
return F_381 ( V_596 -> V_2 , V_190 ) == 0 ;
}
static void F_382 ( struct V_595 * V_596 ,
struct V_165 * V_166 )
{
struct V_13 * V_14 = F_94 ( V_596 -> V_2 ) ;
if ( ! F_380 ( V_596 ) ) {
V_596 -> args . V_248 = NULL ;
V_596 -> V_56 . V_398 = NULL ;
} else
V_596 -> args . V_248 = V_14 -> V_432 ;
if ( ! V_596 -> V_600 )
V_596 -> V_600 = F_375 ;
V_596 -> V_56 . V_14 = V_14 ;
V_596 -> V_115 = V_157 ;
V_166 -> V_318 = & V_319 [ V_607 ] ;
F_46 ( & V_596 -> args . V_163 , & V_596 -> V_56 . V_164 , 1 ) ;
}
static void F_383 ( struct V_102 * V_103 , struct V_608 * V_161 )
{
F_70 ( F_94 ( V_161 -> V_2 ) ,
& V_161 -> args . V_163 ,
& V_161 -> V_56 . V_164 ,
V_103 ) ;
}
static int F_384 ( struct V_102 * V_103 , struct V_608 * V_161 )
{
struct V_2 * V_2 = V_161 -> V_2 ;
F_385 ( V_161 , V_103 -> V_107 ) ;
if ( F_38 ( V_103 , F_94 ( V_2 ) ,
NULL , NULL ) == - V_108 ) {
F_65 ( V_103 ) ;
return - V_108 ;
}
return 0 ;
}
static int F_386 ( struct V_102 * V_103 , struct V_608 * V_161 )
{
if ( ! F_67 ( V_103 , & V_161 -> V_56 . V_164 ) )
return - V_108 ;
return V_161 -> V_609 ( V_103 , V_161 ) ;
}
static void F_387 ( struct V_608 * V_161 , struct V_165 * V_166 )
{
struct V_13 * V_14 = F_94 ( V_161 -> V_2 ) ;
if ( V_161 -> V_609 == NULL )
V_161 -> V_609 = F_384 ;
V_161 -> V_56 . V_14 = V_14 ;
V_166 -> V_318 = & V_319 [ V_610 ] ;
F_46 ( & V_161 -> args . V_163 , & V_161 -> V_56 . V_164 , 1 ) ;
}
static void F_388 ( void * V_159 )
{
struct V_611 * V_161 = V_159 ;
struct V_62 * V_63 = V_161 -> V_98 ;
if ( F_389 ( & V_63 -> V_612 ) > 1 )
F_390 ( V_63 ) ;
F_391 ( V_63 ) ;
F_105 ( V_161 ) ;
}
static void F_392 ( struct V_102 * V_103 , void * V_159 )
{
struct V_611 * V_161 = V_159 ;
struct V_62 * V_63 = V_161 -> V_98 ;
unsigned long V_115 = V_161 -> V_115 ;
F_393 ( V_63 , V_103 -> V_107 ) ;
switch ( V_103 -> V_107 ) {
case 0 :
break;
case - V_78 :
F_26 ( V_63 ) ;
break;
default:
if ( F_33 ( V_613 , & V_63 -> V_614 ) == 0 )
return;
if ( V_103 -> V_107 != V_615 ) {
F_24 ( V_63 ) ;
return;
}
F_394 ( V_63 ) ;
}
F_40 ( V_63 , V_115 ) ;
}
static int F_395 ( struct V_62 * V_63 , struct V_323 * V_357 , unsigned V_616 )
{
struct V_165 V_166 = {
. V_318 = & V_319 [ V_617 ] ,
. V_321 = V_63 ,
. V_323 = V_357 ,
} ;
struct V_611 * V_161 ;
if ( V_616 == 0 )
return 0 ;
if ( ! F_396 ( & V_63 -> V_612 ) )
return - V_35 ;
V_161 = F_288 ( sizeof( * V_161 ) , V_310 ) ;
if ( V_161 == NULL )
return - V_132 ;
V_161 -> V_98 = V_63 ;
V_161 -> V_115 = V_157 ;
return F_397 ( V_63 -> V_110 , & V_166 , V_618 ,
& V_619 , V_161 ) ;
}
static int F_398 ( struct V_62 * V_63 , struct V_323 * V_357 )
{
struct V_165 V_166 = {
. V_318 = & V_319 [ V_617 ] ,
. V_321 = V_63 ,
. V_323 = V_357 ,
} ;
unsigned long V_580 = V_157 ;
int V_313 ;
V_313 = F_399 ( V_63 -> V_110 , & V_166 , V_618 ) ;
if ( V_313 < 0 )
return V_313 ;
F_40 ( V_63 , V_580 ) ;
return 0 ;
}
static inline int F_400 ( struct V_13 * V_14 )
{
return V_14 -> V_94 & V_451 ;
}
static int F_401 ( const void * V_620 , T_9 V_621 ,
struct V_500 * * V_42 )
{
struct V_500 * V_622 , * * V_623 ;
int V_624 = 0 ;
T_9 V_12 ;
V_623 = V_42 ;
do {
V_12 = F_402 ( T_9 , V_625 , V_621 ) ;
V_622 = F_287 ( V_389 ) ;
if ( V_622 == NULL )
goto V_626;
memcpy ( F_403 ( V_622 ) , V_620 , V_12 ) ;
V_620 += V_12 ;
V_621 -= V_12 ;
* V_42 ++ = V_622 ;
V_624 ++ ;
} while ( V_621 != 0 );
return V_624 ;
V_626:
for(; V_624 > 0 ; V_624 -- )
F_291 ( V_623 [ V_624 - 1 ] ) ;
return - V_132 ;
}
static void F_404 ( struct V_2 * V_2 , struct V_627 * V_628 )
{
struct V_176 * V_177 = F_82 ( V_2 ) ;
F_41 ( & V_2 -> V_178 ) ;
F_105 ( V_177 -> V_629 ) ;
V_177 -> V_629 = V_628 ;
F_43 ( & V_2 -> V_178 ) ;
}
static void F_405 ( struct V_2 * V_2 )
{
F_404 ( V_2 , NULL ) ;
}
static inline T_11 F_406 ( struct V_2 * V_2 , char * V_620 , T_9 V_621 )
{
struct V_176 * V_177 = F_82 ( V_2 ) ;
struct V_627 * V_628 ;
int V_51 = - V_309 ;
F_41 ( & V_2 -> V_178 ) ;
V_628 = V_177 -> V_629 ;
if ( V_628 == NULL )
goto V_136;
if ( V_620 == NULL )
goto V_630;
if ( V_628 -> V_631 == 0 )
goto V_136;
V_51 = - V_632 ;
if ( V_628 -> V_12 > V_621 )
goto V_136;
memcpy ( V_620 , V_628 -> V_161 , V_628 -> V_12 ) ;
V_630:
V_51 = V_628 -> V_12 ;
V_136:
F_43 ( & V_2 -> V_178 ) ;
return V_51 ;
}
static void F_407 ( struct V_2 * V_2 , struct V_500 * * V_42 , T_9 V_48 , T_9 V_633 )
{
struct V_627 * V_628 ;
T_9 V_621 = sizeof( * V_628 ) + V_633 ;
if ( V_621 <= V_625 ) {
V_628 = F_288 ( V_621 , V_389 ) ;
if ( V_628 == NULL )
goto V_136;
V_628 -> V_631 = 1 ;
F_408 ( V_628 -> V_161 , V_42 , V_48 , V_633 ) ;
} else {
V_628 = F_288 ( sizeof( * V_628 ) , V_389 ) ;
if ( V_628 == NULL )
goto V_136;
V_628 -> V_631 = 0 ;
}
V_628 -> V_12 = V_633 ;
V_136:
F_404 ( V_2 , V_628 ) ;
}
static T_11 F_409 ( struct V_2 * V_2 , void * V_620 , T_9 V_621 )
{
struct V_500 * V_42 [ V_634 ] = { NULL , } ;
struct V_635 args = {
. V_251 = F_102 ( V_2 ) ,
. V_636 = V_42 ,
. V_633 = V_621 ,
} ;
struct V_637 V_56 = {
. V_633 = V_621 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_638 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
unsigned int V_639 = F_410 ( V_621 , V_625 ) ;
int V_51 = - V_132 , V_489 ;
if ( V_639 == 0 )
V_639 = 1 ;
if ( V_639 > F_279 ( V_42 ) )
return - V_632 ;
for ( V_489 = 0 ; V_489 < V_639 ; V_489 ++ ) {
V_42 [ V_489 ] = F_287 ( V_389 ) ;
if ( ! V_42 [ V_489 ] )
goto V_317;
}
V_56 . V_640 = F_287 ( V_389 ) ;
if ( ! V_56 . V_640 )
goto V_317;
args . V_633 = V_639 * V_625 ;
F_8 ( L_40 ,
V_34 , V_620 , V_621 , V_639 , args . V_633 ) ;
V_51 = F_80 ( F_94 ( V_2 ) -> V_98 , F_94 ( V_2 ) ,
& V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
if ( V_51 )
goto V_317;
if ( V_56 . V_641 & V_642 ) {
if ( V_620 == NULL )
goto V_643;
V_51 = - V_632 ;
goto V_317;
}
F_407 ( V_2 , V_42 , V_56 . V_644 , V_56 . V_633 ) ;
if ( V_620 ) {
if ( V_56 . V_633 > V_621 ) {
V_51 = - V_632 ;
goto V_317;
}
F_408 ( V_620 , V_42 , V_56 . V_644 , V_56 . V_633 ) ;
}
V_643:
V_51 = V_56 . V_633 ;
V_317:
for ( V_489 = 0 ; V_489 < V_639 ; V_489 ++ )
if ( V_42 [ V_489 ] )
F_291 ( V_42 [ V_489 ] ) ;
if ( V_56 . V_640 )
F_291 ( V_56 . V_640 ) ;
return V_51 ;
}
static T_11 F_411 ( struct V_2 * V_2 , void * V_620 , T_9 V_621 )
{
struct V_60 V_61 = { } ;
T_11 V_51 ;
do {
V_51 = F_409 ( V_2 , V_620 , V_621 ) ;
F_412 ( V_2 , V_51 ) ;
if ( V_51 >= 0 )
break;
V_51 = F_31 ( F_94 ( V_2 ) , V_51 , & V_61 ) ;
} while ( V_61 . V_68 );
return V_51 ;
}
static T_11 F_413 ( struct V_2 * V_2 , void * V_620 , T_9 V_621 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
int V_51 ;
if ( ! F_400 ( V_14 ) )
return - V_645 ;
V_51 = F_414 ( V_14 , V_2 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( F_82 ( V_2 ) -> V_179 & V_646 )
F_415 ( V_2 ) ;
V_51 = F_406 ( V_2 , V_620 , V_621 ) ;
if ( V_51 != - V_309 )
return V_51 ;
return F_411 ( V_2 , V_620 , V_621 ) ;
}
static int F_416 ( struct V_2 * V_2 , const void * V_620 , T_9 V_621 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_500 * V_42 [ V_634 ] ;
struct V_647 V_401 = {
. V_251 = F_102 ( V_2 ) ,
. V_636 = V_42 ,
. V_633 = V_621 ,
} ;
struct V_648 V_56 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_649 ] ,
. V_321 = & V_401 ,
. V_322 = & V_56 ,
} ;
unsigned int V_639 = F_410 ( V_621 , V_625 ) ;
int V_51 , V_489 ;
if ( ! F_400 ( V_14 ) )
return - V_645 ;
if ( V_639 > F_279 ( V_42 ) )
return - V_632 ;
V_489 = F_401 ( V_620 , V_621 , V_401 . V_636 ) ;
if ( V_489 < 0 )
return V_489 ;
F_150 ( V_2 ) ;
V_51 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & V_401 . V_163 , & V_56 . V_164 , 1 ) ;
for (; V_489 > 0 ; V_489 -- )
F_417 ( V_42 [ V_489 - 1 ] ) ;
F_41 ( & V_2 -> V_178 ) ;
F_82 ( V_2 ) -> V_179 |= V_180 ;
F_43 ( & V_2 -> V_178 ) ;
F_418 ( V_2 ) ;
F_415 ( V_2 ) ;
return V_51 ;
}
static int F_419 ( struct V_2 * V_2 , const void * V_620 , T_9 V_621 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_416 ( V_2 , V_620 , V_621 ) ;
F_420 ( V_2 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_421 ( struct V_2 * V_2 , void * V_620 ,
T_9 V_621 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_397 V_398 ;
struct V_1 V_7 = { 0 , 0 , V_621 , V_620 } ;
T_1 V_248 [ 3 ] = { 0 , 0 , V_380 } ;
struct V_503 V_401 = {
. V_251 = F_102 ( V_2 ) ,
. V_248 = V_248 ,
} ;
struct V_504 V_56 = {
. V_398 = & V_398 ,
. V_7 = & V_7 ,
. V_14 = V_14 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_505 ] ,
. V_321 = & V_401 ,
. V_322 = & V_56 ,
} ;
int V_51 ;
F_90 ( & V_398 ) ;
V_51 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & V_401 . V_163 , & V_56 . V_164 , 0 ) ;
if ( V_51 )
return V_51 ;
if ( ! ( V_398 . V_304 & V_650 ) )
return - V_309 ;
if ( V_621 < V_7 . V_12 )
return - V_632 ;
return 0 ;
}
static int F_422 ( struct V_2 * V_2 , void * V_620 ,
T_9 V_621 )
{
struct V_60 V_61 = { } ;
int V_8 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_645 ;
do {
V_8 = F_421 ( V_2 , V_620 , V_621 ) ;
F_423 ( V_2 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_424 ( struct V_2 * V_2 ,
struct V_1 * V_399 ,
struct V_397 * V_398 ,
struct V_1 * V_388 )
{
struct V_5 V_6 = { 0 } ;
struct V_13 * V_14 = F_94 ( V_2 ) ;
const T_1 V_248 [ 3 ] = { 0 , 0 , V_380 } ;
struct V_400 V_401 = {
. V_251 = F_102 ( V_2 ) ,
. V_402 = & V_6 ,
. V_14 = V_14 ,
. V_248 = V_248 ,
. V_7 = V_399 ,
} ;
struct V_403 V_56 = {
. V_398 = V_398 ,
. V_7 = V_388 ,
. V_14 = V_14 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_404 ] ,
. V_321 = & V_401 ,
. V_322 = & V_56 ,
} ;
int V_313 ;
F_136 ( & V_401 . V_257 , & V_414 ) ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & V_401 . V_163 , & V_56 . V_164 , 1 ) ;
if ( V_313 )
F_8 ( L_41 , V_34 , V_313 ) ;
return V_313 ;
}
static int F_425 ( struct V_2 * V_2 ,
struct V_1 * V_399 ,
struct V_397 * V_398 ,
struct V_1 * V_388 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_424 ( V_2 , V_399 ,
V_398 , V_388 ) ;
F_426 ( V_2 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int
F_427 ( struct V_4 * V_4 , const void * V_620 , T_9 V_621 )
{
struct V_1 V_399 , * V_388 = NULL ;
struct V_397 V_398 ;
struct V_323 * V_357 ;
struct V_2 * V_2 = F_14 ( V_4 ) ;
int V_313 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_645 ;
F_90 ( & V_398 ) ;
V_399 . V_651 = 0 ;
V_399 . V_652 = 0 ;
V_399 . V_7 = ( char * ) V_620 ;
V_399 . V_12 = V_621 ;
V_357 = F_428 () ;
if ( F_51 ( V_357 ) )
return F_78 ( V_357 ) ;
V_388 = F_96 ( F_94 ( V_2 ) , V_389 ) ;
if ( F_51 ( V_388 ) ) {
V_313 = - F_78 ( V_388 ) ;
goto V_136;
}
V_313 = F_425 ( V_2 , & V_399 , & V_398 , V_388 ) ;
if ( V_313 == 0 )
F_241 ( V_2 , & V_398 , V_388 ) ;
F_104 ( V_388 ) ;
V_136:
F_221 ( V_357 ) ;
return V_313 ;
}
static void F_429 ( const struct V_62 * V_63 ,
T_12 * V_653 )
{
T_3 V_254 [ 2 ] ;
if ( F_33 ( V_654 , & V_63 -> V_106 ) ) {
V_254 [ 0 ] = 0 ;
V_254 [ 1 ] = F_430 ( V_655 + 1 ) ;
} else {
struct V_656 * V_657 = F_431 ( V_63 -> V_658 , V_659 ) ;
V_254 [ 0 ] = F_430 ( V_657 -> V_660 . V_661 ) ;
V_254 [ 1 ] = F_430 ( V_657 -> V_660 . V_662 ) ;
}
memcpy ( V_653 -> V_161 , V_254 , sizeof( V_653 -> V_161 ) ) ;
}
static int
F_432 ( struct V_62 * V_63 )
{
int V_663 ;
T_9 V_12 ;
char * V_664 ;
if ( V_63 -> V_665 != NULL )
return 0 ;
F_144 () ;
V_12 = 14 + strlen ( V_63 -> V_666 ) + 1 +
strlen ( F_433 ( V_63 -> V_110 , V_667 ) ) +
1 +
strlen ( F_433 ( V_63 -> V_110 , V_668 ) ) +
1 ;
F_147 () ;
if ( V_12 > V_669 + 1 )
return - V_27 ;
V_664 = F_288 ( V_12 , V_389 ) ;
if ( ! V_664 )
return - V_132 ;
F_144 () ;
V_663 = F_434 ( V_664 , V_12 , L_42 ,
V_63 -> V_666 ,
F_433 ( V_63 -> V_110 , V_667 ) ,
F_433 ( V_63 -> V_110 , V_668 ) ) ;
F_147 () ;
V_63 -> V_665 = V_664 ;
return 0 ;
}
static int
F_435 ( struct V_62 * V_63 )
{
int V_663 ;
T_9 V_12 ;
char * V_664 ;
V_12 = 10 + 10 + 1 + 10 + 1 +
strlen ( V_670 ) + 1 +
strlen ( V_63 -> V_110 -> V_671 ) + 1 ;
if ( V_12 > V_669 + 1 )
return - V_27 ;
V_664 = F_288 ( V_12 , V_389 ) ;
if ( ! V_664 )
return - V_132 ;
V_663 = F_434 ( V_664 , V_12 , L_43 ,
V_63 -> V_672 -> V_673 , V_63 -> V_438 ,
V_670 ,
V_63 -> V_110 -> V_671 ) ;
V_63 -> V_665 = V_664 ;
return 0 ;
}
static int
F_436 ( struct V_62 * V_63 )
{
int V_663 ;
T_9 V_12 ;
char * V_664 ;
if ( V_63 -> V_665 != NULL )
return 0 ;
if ( V_670 [ 0 ] != '\0' )
return F_435 ( V_63 ) ;
V_12 = 10 + 10 + 1 + 10 + 1 +
strlen ( V_63 -> V_110 -> V_671 ) + 1 ;
if ( V_12 > V_669 + 1 )
return - V_27 ;
V_664 = F_288 ( V_12 , V_389 ) ;
if ( ! V_664 )
return - V_132 ;
V_663 = F_434 ( V_664 , V_12 , L_44 ,
V_63 -> V_672 -> V_673 , V_63 -> V_438 ,
V_63 -> V_110 -> V_671 ) ;
V_63 -> V_665 = V_664 ;
return 0 ;
}
static unsigned int
F_437 ( const struct V_62 * V_63 , char * V_620 , T_9 V_12 )
{
if ( strchr ( V_63 -> V_666 , ':' ) != NULL )
return F_434 ( V_620 , V_12 , L_45 ) ;
else
return F_434 ( V_620 , V_12 , L_46 ) ;
}
static void F_438 ( struct V_102 * V_103 , void * V_159 )
{
struct V_674 * V_675 = V_159 ;
if ( V_103 -> V_107 == 0 )
V_675 -> V_676 = F_217 ( V_103 -> V_677 -> V_678 ) ;
}
int F_439 ( struct V_62 * V_63 , T_1 V_679 ,
unsigned short V_680 , struct V_323 * V_357 ,
struct V_681 * V_56 )
{
T_12 V_682 ;
struct V_674 V_683 = {
. V_682 = & V_682 ,
. V_684 = V_679 ,
. V_685 = V_63 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_686 ] ,
. V_321 = & V_683 ,
. V_322 = V_56 ,
. V_323 = V_357 ,
} ;
struct V_102 * V_103 ;
struct V_167 V_324 = {
. V_169 = V_63 -> V_110 ,
. V_165 = & V_166 ,
. V_170 = & V_687 ,
. V_173 = & V_683 ,
. V_219 = V_618 ,
} ;
int V_313 ;
F_429 ( V_63 , & V_682 ) ;
if ( F_33 ( V_688 , & V_63 -> V_689 ) )
V_313 = F_436 ( V_63 ) ;
else
V_313 = F_432 ( V_63 ) ;
if ( V_313 )
goto V_136;
V_683 . V_690 =
F_437 ( V_63 ,
V_683 . V_691 ,
sizeof( V_683 . V_691 ) ) ;
V_683 . V_692 = F_434 ( V_683 . V_693 ,
sizeof( V_683 . V_693 ) , L_47 ,
V_63 -> V_666 , V_680 >> 8 , V_680 & 255 ) ;
F_8 ( L_48 ,
V_63 -> V_110 -> V_111 -> V_694 -> V_695 ,
V_63 -> V_665 ) ;
V_103 = F_77 ( & V_324 ) ;
if ( F_51 ( V_103 ) ) {
V_313 = F_78 ( V_103 ) ;
goto V_136;
}
V_313 = V_103 -> V_107 ;
if ( V_683 . V_676 ) {
V_63 -> V_696 = F_440 ( V_683 . V_676 ) ;
F_221 ( V_683 . V_676 ) ;
}
F_79 ( V_103 ) ;
V_136:
F_441 ( V_63 , V_313 ) ;
F_8 ( L_49 , V_313 ) ;
return V_313 ;
}
int F_442 ( struct V_62 * V_63 ,
struct V_681 * V_401 ,
struct V_323 * V_357 )
{
struct V_165 V_166 = {
. V_318 = & V_319 [ V_697 ] ,
. V_321 = V_401 ,
. V_323 = V_357 ,
} ;
int V_313 ;
F_8 ( L_50 ,
V_63 -> V_110 -> V_111 -> V_694 -> V_695 ,
V_63 -> V_242 ) ;
V_313 = F_399 ( V_63 -> V_110 , & V_166 , V_618 ) ;
F_443 ( V_63 , V_313 ) ;
F_8 ( L_51 , V_313 ) ;
return V_313 ;
}
static void F_444 ( struct V_102 * V_103 , void * V_159 )
{
struct V_698 * V_161 = V_159 ;
if ( ! F_67 ( V_103 , & V_161 -> V_56 . V_164 ) )
return;
F_445 ( & V_161 -> args , & V_161 -> V_56 , V_103 -> V_107 ) ;
switch ( V_103 -> V_107 ) {
case 0 :
F_44 ( V_161 -> V_56 . V_14 , V_161 -> V_115 ) ;
case - V_71 :
case - V_70 :
case - V_72 :
case - V_93 :
case - V_75 :
case - V_74 :
V_103 -> V_107 = 0 ;
if ( V_161 -> V_418 )
F_259 ( V_161 -> V_2 , V_161 -> V_420 ) ;
break;
default:
if ( F_38 ( V_103 , V_161 -> V_56 . V_14 ,
NULL , NULL ) == - V_108 ) {
F_65 ( V_103 ) ;
return;
}
}
V_161 -> V_301 = V_103 -> V_107 ;
}
static void F_446 ( void * V_159 )
{
struct V_698 * V_161 = V_159 ;
struct V_2 * V_2 = V_161 -> V_2 ;
if ( V_2 ) {
if ( V_161 -> V_418 )
F_256 ( V_2 ) ;
F_447 ( V_2 ) ;
}
F_105 ( V_159 ) ;
}
static void F_448 ( struct V_102 * V_103 , void * V_161 )
{
struct V_698 * V_699 ;
V_699 = (struct V_698 * ) V_161 ;
if ( F_252 ( V_699 -> V_2 , V_103 ) )
return;
if ( V_699 -> V_418 )
F_261 ( V_699 -> V_2 , & V_699 -> V_420 ) ;
F_70 ( V_699 -> V_56 . V_14 ,
& V_699 -> args . V_163 ,
& V_699 -> V_56 . V_164 ,
V_103 ) ;
}
static int F_449 ( struct V_2 * V_2 , struct V_323 * V_357 , const T_8 * V_257 , int V_700 )
{
struct V_698 * V_161 ;
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_102 * V_103 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_701 ] ,
. V_323 = V_357 ,
} ;
struct V_167 V_324 = {
. V_169 = V_14 -> V_98 ,
. V_165 = & V_166 ,
. V_170 = & V_702 ,
. V_219 = V_328 ,
} ;
int V_313 = 0 ;
V_161 = F_95 ( sizeof( * V_161 ) , V_310 ) ;
if ( V_161 == NULL )
return - V_132 ;
F_46 ( & V_161 -> args . V_163 , & V_161 -> V_56 . V_164 , 1 ) ;
V_161 -> args . V_436 = & V_161 -> V_251 ;
V_161 -> args . V_257 = & V_161 -> V_257 ;
V_161 -> args . V_248 = V_14 -> V_432 ;
F_193 ( & V_161 -> V_251 , F_102 ( V_2 ) ) ;
F_136 ( & V_161 -> V_257 , V_257 ) ;
V_161 -> V_56 . V_398 = & V_161 -> V_398 ;
V_161 -> V_56 . V_14 = V_14 ;
F_90 ( V_161 -> V_56 . V_398 ) ;
V_161 -> V_115 = V_157 ;
V_161 -> V_301 = 0 ;
V_161 -> V_2 = F_450 ( V_2 ) ;
if ( V_161 -> V_2 )
V_161 -> V_418 = F_262 ( V_2 ) ;
V_324 . V_173 = V_161 ;
V_166 . V_321 = & V_161 -> args ;
V_166 . V_322 = & V_161 -> V_56 ;
V_103 = F_77 ( & V_324 ) ;
if ( F_51 ( V_103 ) )
return F_78 ( V_103 ) ;
if ( ! V_700 )
goto V_136;
V_313 = F_116 ( V_103 ) ;
if ( V_313 != 0 )
goto V_136;
V_313 = V_161 -> V_301 ;
if ( V_313 == 0 )
F_451 ( V_2 , & V_161 -> V_398 ) ;
else
F_159 ( V_2 , & V_161 -> V_398 ) ;
V_136:
F_79 ( V_103 ) ;
return V_313 ;
}
int F_452 ( struct V_2 * V_2 , struct V_323 * V_357 , const T_8 * V_257 , int V_700 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_449 ( V_2 , V_357 , V_257 , V_700 ) ;
F_453 ( V_2 , V_8 ) ;
switch ( V_8 ) {
case - V_75 :
case - V_74 :
case 0 :
return 0 ;
}
V_8 = F_31 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static unsigned long
F_454 ( unsigned long V_50 )
{
F_19 ( V_50 ) ;
V_50 <<= 1 ;
if ( V_50 > V_703 )
return V_703 ;
return V_50 ;
}
static int F_455 ( struct V_64 * V_65 , int V_704 , struct V_705 * V_706 )
{
struct V_2 * V_2 = V_65 -> V_2 ;
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_62 * V_63 = V_14 -> V_62 ;
struct V_707 V_401 = {
. V_251 = F_102 ( V_2 ) ,
. V_708 = V_706 ,
} ;
struct V_709 V_56 = {
. V_710 = V_706 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_711 ] ,
. V_321 = & V_401 ,
. V_322 = & V_56 ,
. V_323 = V_65 -> V_232 -> V_298 ,
} ;
struct V_289 * V_290 ;
int V_313 ;
V_401 . V_712 . V_241 = V_63 -> V_242 ;
V_313 = F_456 ( V_65 , V_706 ) ;
if ( V_313 != 0 )
goto V_136;
V_290 = V_706 -> V_713 . V_714 . V_232 ;
V_401 . V_712 . V_243 = V_290 -> V_715 . V_246 ;
V_401 . V_712 . V_716 = V_14 -> V_716 ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & V_401 . V_163 , & V_56 . V_164 , 1 ) ;
switch ( V_313 ) {
case 0 :
V_706 -> V_717 = V_718 ;
break;
case - V_315 :
V_313 = 0 ;
}
V_706 -> V_719 -> V_720 ( V_706 ) ;
V_706 -> V_719 = NULL ;
V_136:
return V_313 ;
}
static int F_457 ( struct V_64 * V_65 , int V_704 , struct V_705 * V_706 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_455 ( V_65 , V_704 , V_706 ) ;
F_458 ( V_706 , V_65 , V_704 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_65 -> V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_459 ( struct V_2 * V_2 , struct V_705 * V_708 )
{
return F_460 ( V_2 , V_708 ) ;
}
static struct V_721 * F_461 ( struct V_705 * V_708 ,
struct V_307 * V_308 ,
struct V_289 * V_290 ,
struct V_223 * V_209 )
{
struct V_721 * V_41 ;
struct V_2 * V_2 = V_290 -> V_291 -> V_2 ;
V_41 = F_95 ( sizeof( * V_41 ) , V_310 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_401 . V_251 = F_102 ( V_2 ) ;
V_41 -> V_401 . V_708 = & V_41 -> V_708 ;
V_41 -> V_401 . V_209 = V_209 ;
V_41 -> V_56 . V_209 = V_209 ;
V_41 -> V_290 = V_290 ;
F_99 ( & V_290 -> V_722 ) ;
V_41 -> V_308 = F_167 ( V_308 ) ;
memcpy ( & V_41 -> V_708 , V_708 , sizeof( V_41 -> V_708 ) ) ;
V_41 -> V_14 = F_94 ( V_2 ) ;
return V_41 ;
}
static void F_462 ( void * V_161 )
{
struct V_721 * V_159 = V_161 ;
F_109 ( V_159 -> V_401 . V_209 ) ;
F_463 ( V_159 -> V_290 ) ;
F_179 ( V_159 -> V_308 ) ;
F_105 ( V_159 ) ;
}
static void F_464 ( struct V_102 * V_103 , void * V_161 )
{
struct V_721 * V_159 = V_161 ;
if ( ! F_67 ( V_103 , & V_159 -> V_56 . V_164 ) )
return;
switch ( V_103 -> V_107 ) {
case 0 :
F_44 ( V_159 -> V_14 , V_159 -> V_115 ) ;
F_459 ( V_159 -> V_290 -> V_291 -> V_2 , & V_159 -> V_708 ) ;
if ( F_148 ( V_159 -> V_290 ,
& V_159 -> V_56 . V_257 ) )
break;
case - V_72 :
case - V_93 :
case - V_75 :
case - V_74 :
if ( ! F_146 ( & V_159 -> V_401 . V_257 ,
& V_159 -> V_290 -> V_293 ) )
F_65 ( V_103 ) ;
break;
default:
if ( F_38 ( V_103 , V_159 -> V_14 ,
NULL , NULL ) == - V_108 )
F_65 ( V_103 ) ;
}
F_152 ( V_159 -> V_401 . V_209 ) ;
}
static void F_465 ( struct V_102 * V_103 , void * V_161 )
{
struct V_721 * V_159 = V_161 ;
if ( F_192 ( V_159 -> V_401 . V_209 , V_103 ) != 0 )
goto V_329;
F_136 ( & V_159 -> V_401 . V_257 , & V_159 -> V_290 -> V_293 ) ;
if ( F_33 ( V_723 , & V_159 -> V_290 -> V_724 ) == 0 ) {
goto V_330;
}
V_159 -> V_115 = V_157 ;
if ( F_70 ( V_159 -> V_14 ,
& V_159 -> V_401 . V_163 ,
& V_159 -> V_56 . V_164 ,
V_103 ) != 0 )
F_152 ( V_159 -> V_401 . V_209 ) ;
return;
V_330:
V_103 -> V_341 = NULL ;
V_329:
F_67 ( V_103 , & V_159 -> V_56 . V_164 ) ;
}
static struct V_102 * F_466 ( struct V_705 * V_708 ,
struct V_307 * V_308 ,
struct V_289 * V_290 ,
struct V_223 * V_209 )
{
struct V_721 * V_161 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_725 ] ,
. V_323 = V_308 -> V_357 ,
} ;
struct V_167 V_324 = {
. V_169 = F_306 ( V_290 -> V_291 -> V_2 ) ,
. V_165 = & V_166 ,
. V_170 = & V_726 ,
. V_326 = V_327 ,
. V_219 = V_328 ,
} ;
F_265 ( F_94 ( V_290 -> V_291 -> V_2 ) -> V_62 ,
V_430 , & V_324 . V_169 , & V_166 ) ;
V_708 -> V_717 = V_718 ;
V_161 = F_461 ( V_708 , V_308 , V_290 , V_209 ) ;
if ( V_161 == NULL ) {
F_109 ( V_209 ) ;
return F_52 ( - V_132 ) ;
}
F_46 ( & V_161 -> V_401 . V_163 , & V_161 -> V_56 . V_164 , 1 ) ;
V_166 . V_321 = & V_161 -> V_401 ;
V_166 . V_322 = & V_161 -> V_56 ;
V_324 . V_173 = V_161 ;
return F_77 ( & V_324 ) ;
}
static int F_467 ( struct V_64 * V_65 , int V_704 , struct V_705 * V_706 )
{
struct V_2 * V_2 = V_65 -> V_2 ;
struct V_217 * V_218 = V_65 -> V_232 ;
struct V_176 * V_177 = F_82 ( V_2 ) ;
struct V_223 * V_209 ;
struct V_289 * V_290 ;
struct V_102 * V_103 ;
struct V_223 * ( * V_224 ) ( struct V_225 * , T_6 ) ;
int V_313 = 0 ;
unsigned char V_727 = V_706 -> V_727 ;
V_313 = F_456 ( V_65 , V_706 ) ;
V_706 -> V_727 |= V_728 ;
F_468 ( & V_218 -> V_729 ) ;
F_469 ( & V_177 -> V_730 ) ;
if ( F_459 ( V_2 , V_706 ) == - V_309 ) {
F_470 ( & V_177 -> V_730 ) ;
F_471 ( & V_218 -> V_729 ) ;
goto V_136;
}
F_470 ( & V_177 -> V_730 ) ;
F_471 ( & V_218 -> V_729 ) ;
if ( V_313 != 0 )
goto V_136;
V_290 = V_706 -> V_713 . V_714 . V_232 ;
if ( F_33 ( V_723 , & V_290 -> V_724 ) == 0 )
goto V_136;
V_224 = F_94 ( V_2 ) -> V_62 -> V_171 -> V_224 ;
V_209 = V_224 ( & V_290 -> V_715 , V_389 ) ;
V_313 = - V_132 ;
if ( F_51 ( V_209 ) )
goto V_136;
V_103 = F_466 ( V_706 , F_298 ( V_706 -> V_731 ) , V_290 , V_209 ) ;
V_313 = F_78 ( V_103 ) ;
if ( F_51 ( V_103 ) )
goto V_136;
V_313 = F_116 ( V_103 ) ;
F_79 ( V_103 ) ;
V_136:
V_706 -> V_727 = V_727 ;
F_472 ( V_706 , V_65 , V_732 , V_313 ) ;
return V_313 ;
}
static struct V_733 * F_473 ( struct V_705 * V_708 ,
struct V_307 * V_308 , struct V_289 * V_290 ,
T_6 V_221 )
{
struct V_733 * V_41 ;
struct V_2 * V_2 = V_290 -> V_291 -> V_2 ;
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_223 * ( * V_224 ) ( struct V_225 * , T_6 ) ;
V_41 = F_95 ( sizeof( * V_41 ) , V_221 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_401 . V_251 = F_102 ( V_2 ) ;
V_41 -> V_401 . V_708 = & V_41 -> V_708 ;
V_41 -> V_401 . V_734 = F_474 ( & V_290 -> V_291 -> V_232 -> V_229 , V_221 ) ;
if ( F_51 ( V_41 -> V_401 . V_734 ) )
goto V_317;
V_224 = V_14 -> V_62 -> V_171 -> V_224 ;
V_41 -> V_401 . V_735 = V_224 ( & V_290 -> V_715 , V_221 ) ;
if ( F_51 ( V_41 -> V_401 . V_735 ) )
goto V_736;
V_41 -> V_401 . V_712 . V_241 = V_14 -> V_62 -> V_242 ;
V_41 -> V_401 . V_712 . V_243 = V_290 -> V_715 . V_246 ;
V_41 -> V_401 . V_712 . V_716 = V_14 -> V_716 ;
V_41 -> V_56 . V_735 = V_41 -> V_401 . V_735 ;
V_41 -> V_290 = V_290 ;
V_41 -> V_14 = V_14 ;
F_99 ( & V_290 -> V_722 ) ;
V_41 -> V_308 = F_167 ( V_308 ) ;
F_475 ( V_708 -> V_731 ) ;
memcpy ( & V_41 -> V_708 , V_708 , sizeof( V_41 -> V_708 ) ) ;
return V_41 ;
V_736:
F_109 ( V_41 -> V_401 . V_734 ) ;
V_317:
F_105 ( V_41 ) ;
return NULL ;
}
static void F_476 ( struct V_102 * V_103 , void * V_159 )
{
struct V_733 * V_161 = V_159 ;
struct V_64 * V_65 = V_161 -> V_290 -> V_291 ;
F_8 ( L_29 , V_34 ) ;
if ( F_192 ( V_161 -> V_401 . V_735 , V_103 ) != 0 )
goto V_329;
if ( ! F_33 ( V_723 , & V_161 -> V_290 -> V_724 ) ) {
if ( F_192 ( V_161 -> V_401 . V_734 , V_103 ) != 0 ) {
goto V_737;
}
F_136 ( & V_161 -> V_401 . V_278 ,
& V_65 -> V_278 ) ;
V_161 -> V_401 . V_738 = 1 ;
V_161 -> V_56 . V_734 = V_161 -> V_401 . V_734 ;
} else {
V_161 -> V_401 . V_738 = 0 ;
F_136 ( & V_161 -> V_401 . V_739 ,
& V_161 -> V_290 -> V_293 ) ;
}
if ( ! F_248 ( V_65 ) ) {
V_161 -> V_301 = - V_413 ;
V_103 -> V_341 = NULL ;
goto V_740;
}
V_161 -> V_115 = V_157 ;
if ( F_70 ( V_161 -> V_14 ,
& V_161 -> V_401 . V_163 ,
& V_161 -> V_56 . V_164 ,
V_103 ) == 0 )
return;
V_740:
F_152 ( V_161 -> V_401 . V_734 ) ;
V_737:
F_152 ( V_161 -> V_401 . V_735 ) ;
V_329:
F_67 ( V_103 , & V_161 -> V_56 . V_164 ) ;
F_8 ( L_52 , V_34 , V_161 -> V_301 ) ;
}
static void F_477 ( struct V_102 * V_103 , void * V_159 )
{
struct V_733 * V_161 = V_159 ;
struct V_289 * V_290 = V_161 -> V_290 ;
F_8 ( L_29 , V_34 ) ;
if ( ! F_67 ( V_103 , & V_161 -> V_56 . V_164 ) )
return;
V_161 -> V_301 = V_103 -> V_107 ;
switch ( V_103 -> V_107 ) {
case 0 :
F_44 ( F_94 ( F_14 ( V_161 -> V_308 -> V_4 ) ) ,
V_161 -> V_115 ) ;
if ( V_161 -> V_401 . V_741 ) {
V_161 -> V_708 . V_727 &= ~ ( V_742 | V_743 ) ;
if ( F_459 ( V_290 -> V_291 -> V_2 , & V_161 -> V_708 ) < 0 ) {
F_65 ( V_103 ) ;
break;
}
}
if ( V_161 -> V_401 . V_738 != 0 ) {
F_186 ( & V_290 -> V_715 , 0 ) ;
F_136 ( & V_290 -> V_293 , & V_161 -> V_56 . V_257 ) ;
F_133 ( V_723 , & V_290 -> V_724 ) ;
} else if ( ! F_148 ( V_290 , & V_161 -> V_56 . V_257 ) )
F_65 ( V_103 ) ;
break;
case - V_72 :
case - V_93 :
case - V_75 :
case - V_74 :
if ( V_161 -> V_401 . V_738 != 0 ) {
if ( ! F_146 ( & V_161 -> V_401 . V_278 ,
& V_290 -> V_291 -> V_278 ) )
F_65 ( V_103 ) ;
} else if ( ! F_146 ( & V_161 -> V_401 . V_739 ,
& V_290 -> V_293 ) )
F_65 ( V_103 ) ;
}
F_8 ( L_30 , V_34 , V_161 -> V_301 ) ;
}
static void F_478 ( void * V_159 )
{
struct V_733 * V_161 = V_159 ;
F_8 ( L_29 , V_34 ) ;
F_109 ( V_161 -> V_401 . V_734 ) ;
if ( V_161 -> V_316 != 0 ) {
struct V_102 * V_103 ;
V_103 = F_466 ( & V_161 -> V_708 , V_161 -> V_308 , V_161 -> V_290 ,
V_161 -> V_401 . V_735 ) ;
if ( ! F_51 ( V_103 ) )
F_479 ( V_103 ) ;
F_8 ( L_53 , V_34 ) ;
} else
F_109 ( V_161 -> V_401 . V_735 ) ;
F_463 ( V_161 -> V_290 ) ;
F_179 ( V_161 -> V_308 ) ;
F_480 ( V_161 -> V_708 . V_731 ) ;
F_105 ( V_161 ) ;
F_8 ( L_31 , V_34 ) ;
}
static void F_481 ( struct V_13 * V_14 , struct V_289 * V_290 , int V_738 , int error )
{
switch ( error ) {
case - V_71 :
case - V_72 :
V_290 -> V_715 . V_219 &= ~ V_744 ;
if ( V_738 != 0 ||
F_33 ( V_723 , & V_290 -> V_724 ) != 0 )
F_23 ( V_14 , V_290 -> V_291 ) ;
break;
case - V_75 :
V_290 -> V_715 . V_219 &= ~ V_744 ;
case - V_74 :
F_24 ( V_14 -> V_62 ) ;
} ;
}
static int F_482 ( struct V_64 * V_65 , int V_704 , struct V_705 * V_708 , int V_745 )
{
struct V_733 * V_161 ;
struct V_102 * V_103 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_746 ] ,
. V_323 = V_65 -> V_232 -> V_298 ,
} ;
struct V_167 V_324 = {
. V_169 = F_306 ( V_65 -> V_2 ) ,
. V_165 = & V_166 ,
. V_170 = & V_747 ,
. V_326 = V_327 ,
. V_219 = V_328 ,
} ;
int V_51 ;
F_8 ( L_29 , V_34 ) ;
V_161 = F_473 ( V_708 , F_298 ( V_708 -> V_731 ) ,
V_708 -> V_713 . V_714 . V_232 ,
V_745 == V_748 ? V_389 : V_310 ) ;
if ( V_161 == NULL )
return - V_132 ;
if ( F_483 ( V_704 ) )
V_161 -> V_401 . V_749 = 1 ;
F_46 ( & V_161 -> V_401 . V_163 , & V_161 -> V_56 . V_164 , 1 ) ;
V_166 . V_321 = & V_161 -> V_401 ;
V_166 . V_322 = & V_161 -> V_56 ;
V_324 . V_173 = V_161 ;
if ( V_745 > V_748 ) {
if ( V_745 == V_750 )
V_161 -> V_401 . V_751 = V_750 ;
F_47 ( & V_161 -> V_401 . V_163 ) ;
} else
V_161 -> V_401 . V_741 = 1 ;
V_103 = F_77 ( & V_324 ) ;
if ( F_51 ( V_103 ) )
return F_78 ( V_103 ) ;
V_51 = F_116 ( V_103 ) ;
if ( V_51 == 0 ) {
V_51 = V_161 -> V_301 ;
if ( V_51 )
F_481 ( V_161 -> V_14 , V_161 -> V_290 ,
V_161 -> V_401 . V_738 , V_51 ) ;
} else
V_161 -> V_316 = 1 ;
F_79 ( V_103 ) ;
F_8 ( L_30 , V_34 , V_51 ) ;
return V_51 ;
}
static int F_484 ( struct V_64 * V_65 , struct V_705 * V_706 )
{
struct V_13 * V_14 = F_94 ( V_65 -> V_2 ) ;
struct V_60 V_61 = {
. V_2 = V_65 -> V_2 ,
} ;
int V_8 ;
do {
if ( F_33 ( V_280 , & V_65 -> V_219 ) != 0 )
return 0 ;
V_8 = F_482 ( V_65 , V_732 , V_706 , V_750 ) ;
F_485 ( V_706 , V_65 , V_732 , V_8 ) ;
if ( V_8 != - V_89 )
break;
F_31 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_486 ( struct V_64 * V_65 , struct V_705 * V_706 )
{
struct V_13 * V_14 = F_94 ( V_65 -> V_2 ) ;
struct V_60 V_61 = {
. V_2 = V_65 -> V_2 ,
} ;
int V_8 ;
V_8 = F_456 ( V_65 , V_706 ) ;
if ( V_8 != 0 )
return V_8 ;
if ( ! V_752 ) {
F_133 ( V_753 , & V_706 -> V_713 . V_714 . V_232 -> V_724 ) ;
return 0 ;
}
do {
if ( F_33 ( V_280 , & V_65 -> V_219 ) != 0 )
return 0 ;
V_8 = F_482 ( V_65 , V_732 , V_706 , V_754 ) ;
F_487 ( V_706 , V_65 , V_732 , V_8 ) ;
switch ( V_8 ) {
default:
goto V_136;
case - V_91 :
case - V_89 :
F_31 ( V_14 , V_8 , & V_61 ) ;
V_8 = 0 ;
}
} while ( V_61 . V_68 );
V_136:
return V_8 ;
}
static int F_488 ( struct V_64 * V_65 )
{
int V_313 , V_51 = - V_72 ;
struct V_289 * V_290 ;
struct V_13 * V_14 = F_94 ( V_65 -> V_2 ) ;
F_166 (lsp, &state->lock_states, ls_locks) {
if ( F_33 ( V_723 , & V_290 -> V_724 ) ) {
struct V_323 * V_357 = V_290 -> V_291 -> V_232 -> V_298 ;
V_313 = F_218 ( V_14 ,
& V_290 -> V_293 ,
V_357 ) ;
F_489 ( V_65 , V_290 , V_313 ) ;
if ( V_313 != V_370 ) {
if ( V_313 != - V_72 )
F_220 ( V_14 ,
& V_290 -> V_293 ,
V_357 ) ;
F_135 ( V_723 , & V_290 -> V_724 ) ;
V_51 = V_313 ;
}
}
} ;
return V_51 ;
}
static int F_490 ( struct V_64 * V_65 , struct V_705 * V_706 )
{
int V_313 = V_370 ;
if ( F_33 ( V_755 , & V_65 -> V_219 ) )
V_313 = F_488 ( V_65 ) ;
if ( V_313 != V_370 )
V_313 = F_486 ( V_65 , V_706 ) ;
return V_313 ;
}
static int F_491 ( struct V_64 * V_65 , int V_704 , struct V_705 * V_706 )
{
struct V_176 * V_177 = F_82 ( V_65 -> V_2 ) ;
unsigned char V_727 = V_706 -> V_727 ;
int V_313 = - V_756 ;
if ( ( V_727 & V_757 ) &&
! F_33 ( V_383 , & V_65 -> V_219 ) )
goto V_136;
V_313 = F_456 ( V_65 , V_706 ) ;
if ( V_313 != 0 )
goto V_136;
V_706 -> V_727 |= V_743 ;
V_313 = F_459 ( V_65 -> V_2 , V_706 ) ;
if ( V_313 < 0 )
goto V_136;
F_469 ( & V_177 -> V_730 ) ;
if ( F_33 ( V_280 , & V_65 -> V_219 ) ) {
V_706 -> V_727 = V_727 & ~ V_742 ;
V_313 = F_459 ( V_65 -> V_2 , V_706 ) ;
F_470 ( & V_177 -> V_730 ) ;
goto V_136;
}
F_470 ( & V_177 -> V_730 ) ;
V_313 = F_482 ( V_65 , V_704 , V_706 , V_748 ) ;
V_136:
V_706 -> V_727 = V_727 ;
return V_313 ;
}
static int F_492 ( struct V_64 * V_65 , int V_704 , struct V_705 * V_706 )
{
struct V_60 V_61 = {
. V_65 = V_65 ,
. V_2 = V_65 -> V_2 ,
} ;
int V_8 ;
do {
V_8 = F_491 ( V_65 , V_704 , V_706 ) ;
F_493 ( V_706 , V_65 , V_704 , V_8 ) ;
if ( V_8 == - V_315 )
V_8 = - V_108 ;
V_8 = F_31 ( F_94 ( V_65 -> V_2 ) ,
V_8 , & V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int
F_494 ( struct V_758 * V_759 , int V_704 , struct V_705 * V_706 )
{
struct V_307 * V_308 ;
struct V_64 * V_65 ;
unsigned long V_50 = V_760 ;
int V_313 ;
V_308 = F_298 ( V_759 ) ;
V_65 = V_308 -> V_65 ;
if ( V_706 -> V_761 < 0 || V_706 -> V_762 < 0 )
return - V_27 ;
if ( F_495 ( V_704 ) ) {
if ( V_65 != NULL )
return F_457 ( V_65 , V_763 , V_706 ) ;
return 0 ;
}
if ( ! ( F_496 ( V_704 ) || F_483 ( V_704 ) ) )
return - V_27 ;
if ( V_706 -> V_717 == V_718 ) {
if ( V_65 != NULL )
return F_467 ( V_65 , V_704 , V_706 ) ;
return 0 ;
}
if ( V_65 == NULL )
return - V_756 ;
switch ( V_706 -> V_717 ) {
case V_764 :
if ( ! ( V_759 -> V_765 & V_190 ) )
return - V_413 ;
break;
case V_766 :
if ( ! ( V_759 -> V_765 & V_191 ) )
return - V_413 ;
}
do {
V_313 = F_492 ( V_65 , V_704 , V_706 ) ;
if ( ( V_313 != - V_108 ) || F_496 ( V_704 ) )
break;
V_50 = F_454 ( V_50 ) ;
V_313 = - V_58 ;
if ( F_497 () )
break;
} while( V_313 < 0 );
return V_313 ;
}
int F_498 ( struct V_705 * V_708 , struct V_64 * V_65 , const T_8 * V_257 )
{
struct V_13 * V_14 = F_94 ( V_65 -> V_2 ) ;
int V_8 ;
V_8 = F_456 ( V_65 , V_708 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_482 ( V_65 , V_732 , V_708 , V_748 ) ;
return F_180 ( V_14 , V_65 , V_257 , V_8 ) ;
}
static void F_499 ( struct V_102 * V_103 , void * V_159 )
{
struct V_767 * V_161 = V_159 ;
struct V_13 * V_14 = V_161 -> V_14 ;
F_48 ( V_14 -> V_62 -> V_158 ,
& V_161 -> args . V_163 , & V_161 -> V_56 . V_164 , V_103 ) ;
V_161 -> args . V_712 . V_241 = V_14 -> V_62 -> V_242 ;
V_161 -> V_115 = V_157 ;
}
static void F_500 ( struct V_102 * V_103 , void * V_159 )
{
struct V_767 * V_161 = V_159 ;
struct V_13 * V_14 = V_161 -> V_14 ;
F_55 ( V_103 , & V_161 -> V_56 . V_164 ) ;
switch ( V_103 -> V_107 ) {
case 0 :
F_44 ( V_14 , V_161 -> V_115 ) ;
break;
case - V_76 :
case - V_74 :
F_24 ( V_14 -> V_62 ) ;
break;
case - V_78 :
case - V_89 :
if ( F_38 ( V_103 , V_14 ,
NULL , NULL ) == - V_108 )
F_65 ( V_103 ) ;
}
}
static void F_501 ( void * V_159 )
{
struct V_767 * V_161 = V_159 ;
F_502 ( V_161 -> V_14 , V_161 -> V_290 ) ;
F_105 ( V_159 ) ;
}
static void
F_503 ( struct V_13 * V_14 , struct V_289 * V_290 )
{
struct V_767 * V_161 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_768 ] ,
} ;
if ( V_14 -> V_62 -> V_171 -> V_339 != 0 )
return;
V_161 = F_288 ( sizeof( * V_161 ) , V_310 ) ;
if ( ! V_161 )
return;
V_161 -> V_290 = V_290 ;
V_161 -> V_14 = V_14 ;
V_161 -> args . V_712 . V_241 = V_14 -> V_62 -> V_242 ;
V_161 -> args . V_712 . V_243 = V_290 -> V_715 . V_246 ;
V_161 -> args . V_712 . V_716 = V_14 -> V_716 ;
V_166 . V_321 = & V_161 -> args ;
V_166 . V_322 = & V_161 -> V_56 ;
F_46 ( & V_161 -> args . V_163 , & V_161 -> V_56 . V_164 , 0 ) ;
F_397 ( V_14 -> V_98 , & V_166 , 0 , & V_769 , V_161 ) ;
}
static int F_504 ( const struct V_770 * V_771 ,
struct V_4 * V_4 , const char * V_772 ,
const void * V_620 , T_9 V_621 ,
int V_219 )
{
if ( strcmp ( V_772 , L_54 ) != 0 )
return - V_27 ;
return F_419 ( F_14 ( V_4 ) , V_620 , V_621 ) ;
}
static int F_505 ( const struct V_770 * V_771 ,
struct V_4 * V_4 , const char * V_772 ,
void * V_620 , T_9 V_621 )
{
if ( strcmp ( V_772 , L_54 ) != 0 )
return - V_27 ;
return F_413 ( F_14 ( V_4 ) , V_620 , V_621 ) ;
}
static T_9 F_506 ( const struct V_770 * V_771 ,
struct V_4 * V_4 , char * V_773 ,
T_9 V_774 , const char * V_247 ,
T_9 V_775 )
{
T_9 V_12 = sizeof( V_776 ) ;
if ( ! F_400 ( F_94 ( F_14 ( V_4 ) ) ) )
return 0 ;
if ( V_773 && V_12 <= V_774 )
memcpy ( V_773 , V_776 , V_12 ) ;
return V_12 ;
}
static inline int F_507 ( struct V_13 * V_14 )
{
return V_14 -> V_94 & V_9 ;
}
static int F_508 ( const struct V_770 * V_771 ,
struct V_4 * V_4 , const char * V_772 ,
const void * V_620 , T_9 V_621 ,
int V_219 )
{
if ( F_509 ( V_772 ) )
return F_427 ( V_4 , V_620 , V_621 ) ;
return - V_645 ;
}
static int F_510 ( const struct V_770 * V_771 ,
struct V_4 * V_4 , const char * V_772 ,
void * V_620 , T_9 V_621 )
{
if ( F_509 ( V_772 ) )
return F_422 ( F_14 ( V_4 ) , V_620 , V_621 ) ;
return - V_645 ;
}
static T_9 F_511 ( const struct V_770 * V_771 ,
struct V_4 * V_4 , char * V_773 ,
T_9 V_774 , const char * V_247 ,
T_9 V_775 )
{
T_9 V_12 = 0 ;
if ( F_2 ( F_14 ( V_4 ) , V_9 ) ) {
V_12 = F_512 ( F_14 ( V_4 ) , NULL , 0 ) ;
if ( V_773 && V_12 <= V_774 )
F_512 ( F_14 ( V_4 ) , V_773 , V_12 ) ;
}
return V_12 ;
}
static void F_290 ( struct V_397 * V_398 )
{
if ( ! ( ( ( V_398 -> V_304 & V_777 ) ||
( V_398 -> V_304 & V_778 ) ) &&
( V_398 -> V_304 & V_497 ) &&
( V_398 -> V_304 & V_779 ) ) )
return;
V_398 -> V_304 |= V_342 | V_513 |
V_514 | V_780 ;
V_398 -> V_265 = V_347 | V_516 | V_517 ;
V_398 -> V_518 = 2 ;
}
static int F_513 ( struct V_54 * V_98 , struct V_2 * V_3 ,
const struct V_499 * V_247 ,
struct V_501 * V_781 ,
struct V_500 * V_500 )
{
struct V_13 * V_14 = F_94 ( V_3 ) ;
T_1 V_248 [ 3 ] = {
[ 0 ] = V_782 | V_783 ,
} ;
struct V_784 args = {
. V_511 = F_102 ( V_3 ) ,
. V_247 = V_247 ,
. V_500 = V_500 ,
. V_248 = V_248 ,
} ;
struct V_785 V_56 = {
. V_781 = V_781 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_786 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
int V_313 ;
F_8 ( L_55 , V_34 ) ;
if ( F_94 ( V_3 ) -> V_15 [ 1 ] & V_787 )
V_248 [ 1 ] |= V_787 ;
else
V_248 [ 0 ] |= V_45 ;
F_90 ( & V_781 -> V_398 ) ;
V_781 -> V_14 = V_14 ;
V_781 -> V_788 = 0 ;
V_313 = F_80 ( V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
F_8 ( L_56 , V_34 , V_313 ) ;
return V_313 ;
}
int F_289 ( struct V_54 * V_98 , struct V_2 * V_3 ,
const struct V_499 * V_247 ,
struct V_501 * V_781 ,
struct V_500 * V_500 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_513 ( V_98 , V_3 , V_247 ,
V_781 , V_500 ) ;
F_514 ( V_3 , V_247 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_515 ( struct V_2 * V_2 ,
struct V_501 * V_502 ,
struct V_500 * V_500 , struct V_323 * V_357 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_54 * V_55 = V_14 -> V_98 ;
T_1 V_248 [ 2 ] = {
[ 0 ] = V_782 | V_783 ,
} ;
struct V_784 args = {
. V_241 = V_14 -> V_62 -> V_242 ,
. V_251 = F_102 ( V_2 ) ,
. V_500 = V_500 ,
. V_248 = V_248 ,
. V_789 = 1 ,
. V_790 = 1 ,
} ;
struct V_785 V_56 = {
. V_781 = V_502 ,
. V_789 = 1 ,
. V_790 = 1 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_786 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
unsigned long V_580 = V_157 ;
int V_313 ;
F_90 ( & V_502 -> V_398 ) ;
V_502 -> V_14 = V_14 ;
V_502 -> V_788 = 0 ;
F_46 ( & args . V_163 , & V_56 . V_164 , 0 ) ;
F_47 ( & args . V_163 ) ;
V_313 = F_76 ( V_55 , V_14 , & V_166 ,
& args . V_163 , & V_56 . V_164 ) ;
if ( V_313 )
return V_313 ;
F_44 ( V_14 , V_580 ) ;
return 0 ;
}
static int F_516 ( struct V_2 * V_2 ,
struct V_501 * V_502 ,
struct V_500 * V_500 , struct V_323 * V_357 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_54 * V_55 = V_14 -> V_98 ;
T_1 V_248 [ 2 ] = {
[ 0 ] = V_782 | V_783 ,
} ;
struct V_784 args = {
. V_251 = F_102 ( V_2 ) ,
. V_500 = V_500 ,
. V_248 = V_248 ,
. V_789 = 1 ,
} ;
struct V_785 V_56 = {
. V_781 = V_502 ,
. V_789 = 1 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_786 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
int V_313 ;
F_90 ( & V_502 -> V_398 ) ;
V_502 -> V_14 = V_14 ;
V_502 -> V_788 = 0 ;
F_46 ( & args . V_163 , & V_56 . V_164 , 0 ) ;
F_47 ( & args . V_163 ) ;
V_313 = F_76 ( V_55 , V_14 , & V_166 ,
& args . V_163 , & V_56 . V_164 ) ;
if ( V_313 == V_791 &&
V_56 . V_164 . V_150 & V_792 )
V_313 = - V_78 ;
return V_313 ;
}
int F_517 ( struct V_2 * V_2 ,
struct V_501 * V_502 ,
struct V_500 * V_500 , struct V_323 * V_357 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_62 * V_63 = V_14 -> V_62 ;
const struct V_793 * V_794 =
V_63 -> V_171 -> V_795 ;
struct V_60 V_61 = { } ;
int V_313 ;
F_8 ( L_57 , V_34 ,
( unsigned long long ) V_14 -> V_498 . V_796 ,
( unsigned long long ) V_14 -> V_498 . V_797 ,
V_63 -> V_97 ) ;
F_518 ( F_102 ( V_2 ) , V_34 ) ;
do {
V_313 = V_794 -> V_798 ( V_2 , V_502 , V_500 , V_357 ) ;
if ( V_313 != - V_89 )
break;
F_31 ( V_14 , V_313 , & V_61 ) ;
} while ( V_61 . V_68 );
return V_313 ;
}
static int F_519 ( struct V_2 * V_2 , struct V_323 * V_357 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_62 * V_63 = F_94 ( V_2 ) -> V_62 ;
struct V_54 * V_55 = V_14 -> V_98 ;
struct V_799 args = {
. V_251 = F_102 ( V_2 ) ,
. V_241 = V_63 -> V_242 ,
. V_790 = 1 ,
} ;
struct V_800 V_56 = {
. V_790 = 1 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_801 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
unsigned long V_580 = V_157 ;
int V_313 ;
V_56 . V_251 = F_520 () ;
if ( V_56 . V_251 == NULL )
return - V_132 ;
F_46 ( & args . V_163 , & V_56 . V_164 , 0 ) ;
F_47 ( & args . V_163 ) ;
V_313 = F_76 ( V_55 , V_14 , & V_166 ,
& args . V_163 , & V_56 . V_164 ) ;
F_521 ( V_56 . V_251 ) ;
if ( V_313 )
return V_313 ;
F_40 ( V_63 , V_580 ) ;
return 0 ;
}
static int F_522 ( struct V_2 * V_2 , struct V_323 * V_357 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_54 * V_55 = V_14 -> V_98 ;
struct V_799 args = {
. V_251 = F_102 ( V_2 ) ,
} ;
struct V_800 V_56 = {
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_801 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
int V_313 ;
V_56 . V_251 = F_520 () ;
if ( V_56 . V_251 == NULL )
return - V_132 ;
F_46 ( & args . V_163 , & V_56 . V_164 , 0 ) ;
F_47 ( & args . V_163 ) ;
V_313 = F_76 ( V_55 , V_14 , & V_166 ,
& args . V_163 , & V_56 . V_164 ) ;
F_521 ( V_56 . V_251 ) ;
if ( V_313 == V_791 &&
V_56 . V_164 . V_150 & V_792 )
V_313 = - V_78 ;
return V_313 ;
}
int F_523 ( struct V_2 * V_2 , struct V_323 * V_357 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_62 * V_63 = V_14 -> V_62 ;
const struct V_793 * V_794 =
V_63 -> V_171 -> V_795 ;
struct V_60 V_61 = { } ;
int V_313 ;
F_8 ( L_57 , V_34 ,
( unsigned long long ) V_14 -> V_498 . V_796 ,
( unsigned long long ) V_14 -> V_498 . V_797 ,
V_63 -> V_97 ) ;
F_518 ( F_102 ( V_2 ) , V_34 ) ;
do {
V_313 = V_794 -> V_802 ( V_2 , V_357 ) ;
if ( V_313 != - V_89 )
break;
F_31 ( V_14 , V_313 , & V_61 ) ;
} while ( V_61 . V_68 );
return V_313 ;
}
static int F_524 ( struct V_2 * V_3 , const struct V_499 * V_247 , struct V_803 * V_492 , bool V_804 )
{
int V_313 ;
struct V_805 args = {
. V_511 = F_102 ( V_3 ) ,
. V_247 = V_247 ,
} ;
struct V_806 V_56 = {
. V_492 = V_492 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_807 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
struct V_54 * V_55 = F_94 ( V_3 ) -> V_98 ;
struct V_323 * V_357 = NULL ;
if ( V_804 ) {
V_55 = F_94 ( V_3 ) -> V_62 -> V_110 ;
V_357 = F_525 ( F_94 ( V_3 ) -> V_62 ) ;
V_166 . V_323 = V_357 ;
}
F_8 ( L_58 , V_247 -> V_247 ) ;
F_265 ( F_94 ( V_3 ) -> V_62 ,
V_808 , & V_55 , & V_166 ) ;
V_313 = F_80 ( V_55 , F_94 ( V_3 ) , & V_166 , & args . V_163 ,
& V_56 . V_164 , 0 ) ;
F_8 ( L_59 , V_313 ) ;
if ( V_357 )
F_221 ( V_357 ) ;
return V_313 ;
}
int F_526 ( struct V_2 * V_3 , const struct V_499 * V_247 ,
struct V_803 * V_492 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_39 ( F_94 ( V_3 ) -> V_62 ) )
V_8 = F_524 ( V_3 , V_247 , V_492 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_524 ( V_3 , V_247 , V_492 , false ) ;
F_527 ( V_3 , V_247 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_528 ( T_1 V_219 )
{
if ( V_219 & ~ V_809 )
goto V_810;
if ( ( V_219 & V_811 ) &&
( V_219 & V_812 ) )
goto V_810;
if ( ! ( V_219 & ( V_813 ) ) )
goto V_810;
return V_370 ;
V_810:
return - V_814 ;
}
static bool
F_529 ( struct V_815 * V_816 ,
struct V_815 * V_817 )
{
if ( V_816 -> V_818 == V_817 -> V_818 &&
memcmp ( V_816 -> V_819 , V_817 -> V_819 , V_816 -> V_818 ) == 0 )
return true ;
return false ;
}
int F_530 ( struct V_62 * V_63 , struct V_323 * V_357 )
{
int V_313 ;
struct V_820 args = {
. V_98 = V_63 ,
. V_3 = V_821 ,
} ;
struct V_822 V_56 ;
struct V_165 V_166 = {
. V_318 =
& V_319 [ V_823 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
F_8 ( L_11 , V_34 ) ;
F_531 ( & args . V_824 , & V_63 -> V_87 -> V_825 ) ;
if ( ! ( V_63 -> V_87 -> V_219 & V_826 ) )
args . V_3 = V_827 ;
V_313 = F_399 ( V_63 -> V_110 , & V_166 , V_618 ) ;
F_532 ( V_63 , V_313 ) ;
if ( V_313 == 0 ) {
if ( memcmp ( V_56 . V_824 . V_161 ,
V_63 -> V_87 -> V_825 . V_161 , V_828 ) ) {
F_8 ( L_60 , V_34 ) ;
V_313 = - V_35 ;
goto V_136;
}
if ( ( V_56 . V_3 & args . V_3 ) != V_56 . V_3 || V_56 . V_3 == 0 ) {
F_8 ( L_61 ,
V_34 ) ;
V_313 = - V_35 ;
goto V_136;
}
if ( V_56 . V_829 != args . V_829 ) {
F_8 ( L_62 ,
V_34 ) ;
V_313 = - V_35 ;
goto V_136;
}
}
V_136:
F_8 ( L_63 , V_34 , V_313 ) ;
return V_313 ;
}
static int F_533 ( struct V_62 * V_63 ,
struct V_830 * V_218 )
{
static const T_1 V_831 [ V_832 ] = {
[ 1 ] = 1 << ( V_833 - 32 ) |
1 << ( V_834 - 32 ) |
1 << ( V_835 - 32 ) |
1 << ( V_836 - 32 ) |
1 << ( V_837 - 32 )
} ;
unsigned int V_489 ;
if ( V_218 -> V_838 == V_839 ) {
F_534 ( V_840 , L_64 ) ;
for ( V_489 = 0 ; V_489 <= V_841 ; V_489 ++ ) {
if ( F_33 ( V_489 , V_218 -> V_842 . V_255 . V_843 ) )
F_534 ( V_840 , L_65 , V_489 ) ;
if ( F_33 ( V_489 , V_218 -> V_844 . V_255 . V_843 ) )
F_534 ( V_840 , L_66 , V_489 ) ;
}
for ( V_489 = 0 ; V_489 < V_832 ; V_489 ++ ) {
if ( V_218 -> V_842 . V_255 . V_845 [ V_489 ] & ~ V_831 [ V_489 ] ) {
F_534 ( V_840 , L_67 ) ;
return - V_27 ;
}
}
if ( F_33 ( V_833 , V_218 -> V_842 . V_255 . V_843 ) &&
F_33 ( V_835 , V_218 -> V_842 . V_255 . V_843 ) &&
F_33 ( V_836 , V_218 -> V_842 . V_255 . V_843 ) &&
F_33 ( V_837 , V_218 -> V_842 . V_255 . V_843 ) ) {
F_534 ( V_840 , L_68 ) ;
F_534 ( V_840 , L_69 ) ;
F_133 ( V_846 , & V_63 -> V_847 ) ;
} else {
F_534 ( V_840 , L_67 ) ;
return - V_27 ;
}
if ( F_33 ( V_848 , V_218 -> V_844 . V_255 . V_843 ) &&
F_33 ( V_849 , V_218 -> V_844 . V_255 . V_843 ) ) {
F_534 ( V_840 , L_70 ) ;
F_133 ( V_430 , & V_63 -> V_847 ) ;
}
if ( F_33 ( V_850 , V_218 -> V_844 . V_255 . V_843 ) &&
F_33 ( V_851 , V_218 -> V_844 . V_255 . V_843 ) ) {
F_534 ( V_840 , L_71 ) ;
F_133 ( V_808 , & V_63 -> V_847 ) ;
}
if ( F_33 ( V_852 , V_218 -> V_844 . V_255 . V_843 ) &&
F_33 ( V_853 , V_218 -> V_844 . V_255 . V_843 ) ) {
F_534 ( V_840 , L_72 ) ;
F_133 ( V_854 , & V_63 -> V_847 ) ;
}
if ( F_33 ( V_855 , V_218 -> V_844 . V_255 . V_843 ) ) {
F_534 ( V_840 , L_73 ) ;
F_133 ( V_856 , & V_63 -> V_847 ) ;
}
if ( F_33 ( V_857 , V_218 -> V_844 . V_255 . V_843 ) ) {
F_534 ( V_840 , L_74 ) ;
F_133 ( V_858 , & V_63 -> V_847 ) ;
}
}
return 0 ;
}
static int F_535 ( struct V_62 * V_63 , struct V_323 * V_357 ,
T_1 V_859 )
{
T_12 V_37 ;
struct V_860 args = {
. V_37 = & V_37 ,
. V_98 = V_63 ,
#ifdef F_536
. V_219 = V_861 |
V_862 |
V_863 ,
#else
. V_219 = V_861 |
V_862 ,
#endif
} ;
struct V_864 V_56 = {
0
} ;
int V_313 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_865 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
F_429 ( V_63 , & V_37 ) ;
V_313 = F_436 ( V_63 ) ;
if ( V_313 )
goto V_136;
F_8 ( L_75 ,
V_63 -> V_110 -> V_111 -> V_694 -> V_695 ,
V_63 -> V_665 ) ;
V_56 . V_866 = F_95 ( sizeof( struct V_867 ) ,
V_310 ) ;
if ( F_374 ( V_56 . V_866 == NULL ) ) {
V_313 = - V_132 ;
goto V_136;
}
V_56 . V_819 = F_95 ( sizeof( struct V_815 ) ,
V_310 ) ;
if ( F_374 ( V_56 . V_819 == NULL ) ) {
V_313 = - V_132 ;
goto V_868;
}
V_56 . V_869 = F_95 ( sizeof( struct V_870 ) , V_310 ) ;
if ( F_374 ( V_56 . V_869 == NULL ) ) {
V_313 = - V_132 ;
goto V_871;
}
switch ( V_859 ) {
case V_872 :
args . V_873 . V_838 = V_872 ;
break;
case V_839 :
args . V_873 = V_874 ;
break;
default:
F_119 ( 1 ) ;
V_313 = - V_27 ;
goto V_875;
}
V_313 = F_399 ( V_63 -> V_110 , & V_166 , V_618 ) ;
F_537 ( V_63 , V_313 ) ;
if ( V_313 == 0 )
V_313 = F_528 ( V_56 . V_219 ) ;
if ( V_313 == 0 )
V_313 = F_533 ( V_63 , & V_56 . V_873 ) ;
if ( V_313 == 0 ) {
V_63 -> V_242 = V_56 . V_241 ;
V_63 -> V_876 = V_56 . V_219 ;
if ( ! ( V_56 . V_219 & V_877 ) ) {
F_135 ( V_878 ,
& V_63 -> V_87 -> V_879 ) ;
V_63 -> V_880 = V_56 . V_209 ;
}
F_105 ( V_63 -> V_881 ) ;
V_63 -> V_881 = V_56 . V_866 ;
V_56 . V_866 = NULL ;
F_105 ( V_63 -> V_882 ) ;
V_63 -> V_882 = V_56 . V_869 ;
V_56 . V_869 = NULL ;
if ( V_63 -> V_883 != NULL &&
! F_529 ( V_63 -> V_883 ,
V_56 . V_819 ) ) {
F_8 ( L_76 ,
V_34 ) ;
F_133 ( V_884 , & V_63 -> V_106 ) ;
F_105 ( V_63 -> V_883 ) ;
V_63 -> V_883 = NULL ;
}
if ( V_63 -> V_883 == NULL ) {
V_63 -> V_883 = V_56 . V_819 ;
V_56 . V_819 = NULL ;
}
}
V_875:
F_105 ( V_56 . V_869 ) ;
V_871:
F_105 ( V_56 . V_819 ) ;
V_868:
F_105 ( V_56 . V_866 ) ;
V_136:
if ( V_63 -> V_882 != NULL )
F_8 ( L_77
L_78 ,
V_63 -> V_882 -> V_885 , V_63 -> V_882 -> V_247 ,
V_63 -> V_882 -> V_886 . V_887 ,
V_63 -> V_882 -> V_886 . V_888 ) ;
F_8 ( L_79 , V_313 ) ;
return V_313 ;
}
int F_538 ( struct V_62 * V_63 , struct V_323 * V_357 )
{
T_4 V_889 = V_63 -> V_110 -> V_111 -> V_112 ;
int V_313 ;
if ( V_889 == V_113 ||
V_889 == V_114 ) {
V_313 = F_535 ( V_63 , V_357 , V_839 ) ;
if ( ! V_313 )
return 0 ;
}
return F_535 ( V_63 , V_357 , V_872 ) ;
}
static int F_539 ( struct V_62 * V_63 ,
struct V_323 * V_357 )
{
struct V_165 V_166 = {
. V_318 = & V_319 [ V_890 ] ,
. V_321 = V_63 ,
. V_323 = V_357 ,
} ;
int V_313 ;
V_313 = F_399 ( V_63 -> V_110 , & V_166 , V_618 ) ;
F_540 ( V_63 , V_313 ) ;
if ( V_313 )
F_8 ( L_80
L_81 , V_313 , V_63 -> V_97 ) ;
return V_313 ;
}
static int F_541 ( struct V_62 * V_63 ,
struct V_323 * V_357 )
{
unsigned int V_891 ;
int V_51 ;
for ( V_891 = V_892 ; V_891 != 0 ; V_891 -- ) {
V_51 = F_539 ( V_63 , V_357 ) ;
switch ( V_51 ) {
case - V_89 :
case - V_893 :
F_182 ( 1 ) ;
break;
default:
return V_51 ;
}
}
return 0 ;
}
int F_542 ( struct V_62 * V_63 )
{
struct V_323 * V_357 ;
int V_51 = 0 ;
if ( V_63 -> V_171 -> V_339 < 1 )
goto V_136;
if ( V_63 -> V_876 == 0 )
goto V_136;
if ( V_63 -> V_894 )
goto V_136;
V_357 = F_525 ( V_63 ) ;
V_51 = F_541 ( V_63 , V_357 ) ;
if ( V_357 )
F_221 ( V_357 ) ;
switch ( V_51 ) {
case 0 :
case - V_76 :
V_63 -> V_876 = 0 ;
}
V_136:
return V_51 ;
}
static void F_543 ( struct V_102 * V_103 ,
void * V_159 )
{
struct V_895 * V_161 =
(struct V_895 * ) V_159 ;
F_8 ( L_11 , V_34 ) ;
F_68 ( V_161 -> V_63 -> V_87 ,
& V_161 -> args -> V_896 ,
& V_161 -> V_56 -> V_897 ,
V_103 ) ;
F_8 ( L_82 , V_34 ) ;
}
static void F_544 ( struct V_102 * V_103 , void * V_159 )
{
struct V_895 * V_161 =
(struct V_895 * ) V_159 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_60 ( V_103 , & V_161 -> V_56 -> V_897 ) )
return;
switch ( V_103 -> V_107 ) {
case - V_89 :
case - V_91 :
F_8 ( L_83 , V_34 , V_103 -> V_107 ) ;
F_35 ( V_103 , V_53 ) ;
V_103 -> V_107 = 0 ;
case - V_92 :
F_65 ( V_103 ) ;
return;
}
F_8 ( L_82 , V_34 ) ;
}
int F_545 ( struct V_62 * V_63 , struct V_475 * V_576 )
{
struct V_102 * V_103 ;
struct V_898 args ;
struct V_899 V_56 = {
. V_900 = V_576 ,
} ;
struct V_895 V_161 = {
. args = & args ,
. V_56 = & V_56 ,
. V_63 = V_63 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_901 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
struct V_167 V_168 = {
. V_169 = V_63 -> V_110 ,
. V_165 = & V_166 ,
. V_170 = & V_902 ,
. V_173 = & V_161 ,
. V_219 = V_618 ,
} ;
int V_313 ;
F_46 ( & args . V_896 , & V_56 . V_897 , 0 ) ;
F_47 ( & args . V_896 ) ;
F_8 ( L_11 , V_34 ) ;
V_103 = F_77 ( & V_168 ) ;
if ( F_51 ( V_103 ) )
V_313 = F_78 ( V_103 ) ;
else {
V_313 = V_103 -> V_107 ;
F_79 ( V_103 ) ;
}
F_8 ( L_84 , V_34 , V_313 ) ;
return V_313 ;
}
static void F_546 ( struct V_903 * args )
{
unsigned int V_904 , V_905 ;
V_904 = V_906 + V_907 ;
V_905 = V_906 + V_908 ;
args -> V_909 . V_904 = V_904 ;
args -> V_909 . V_905 = V_905 ;
args -> V_909 . V_910 = V_911 ;
args -> V_909 . V_912 = V_913 ;
F_8 ( L_85
L_86 ,
V_34 ,
args -> V_909 . V_904 , args -> V_909 . V_905 ,
args -> V_909 . V_910 , args -> V_909 . V_912 ) ;
args -> V_914 . V_904 = V_625 ;
args -> V_914 . V_905 = V_625 ;
args -> V_914 . V_915 = 0 ;
args -> V_914 . V_910 = V_916 ;
args -> V_914 . V_912 = 1 ;
F_8 ( L_87
L_88 ,
V_34 ,
args -> V_914 . V_904 , args -> V_914 . V_905 ,
args -> V_914 . V_915 , args -> V_914 . V_910 ,
args -> V_914 . V_912 ) ;
}
static int F_547 ( struct V_903 * args ,
struct V_917 * V_56 )
{
struct V_918 * V_919 = & args -> V_909 ;
struct V_918 * V_920 = & V_56 -> V_909 ;
if ( V_920 -> V_905 > V_919 -> V_905 )
return - V_27 ;
if ( V_920 -> V_910 < V_919 -> V_910 )
return - V_27 ;
if ( V_920 -> V_912 == 0 )
return - V_27 ;
if ( V_920 -> V_912 > V_921 )
V_920 -> V_912 = V_921 ;
return 0 ;
}
static int F_548 ( struct V_903 * args ,
struct V_917 * V_56 )
{
struct V_918 * V_919 = & args -> V_914 ;
struct V_918 * V_920 = & V_56 -> V_914 ;
if ( ! ( V_56 -> V_219 & V_826 ) )
goto V_136;
if ( V_920 -> V_904 > V_919 -> V_904 )
return - V_27 ;
if ( V_920 -> V_905 < V_919 -> V_905 )
return - V_27 ;
if ( V_920 -> V_915 > V_919 -> V_915 )
return - V_27 ;
if ( V_920 -> V_910 != V_919 -> V_910 )
return - V_27 ;
if ( V_920 -> V_912 != V_919 -> V_912 )
return - V_27 ;
V_136:
return 0 ;
}
static int F_549 ( struct V_903 * args ,
struct V_917 * V_56 )
{
int V_51 ;
V_51 = F_547 ( args , V_56 ) ;
if ( V_51 )
return V_51 ;
return F_548 ( args , V_56 ) ;
}
static void F_550 ( struct V_138 * V_139 ,
struct V_917 * V_56 )
{
F_531 ( & V_139 -> V_825 , & V_56 -> V_824 ) ;
V_139 -> V_63 -> V_876 |= V_877 ;
F_133 ( V_878 , & V_139 -> V_879 ) ;
V_139 -> V_219 = V_56 -> V_219 ;
memcpy ( & V_139 -> V_909 , & V_56 -> V_909 , sizeof( V_139 -> V_909 ) ) ;
if ( V_56 -> V_219 & V_826 )
memcpy ( & V_139 -> V_914 , & V_56 -> V_914 ,
sizeof( V_139 -> V_914 ) ) ;
}
static int F_551 ( struct V_62 * V_63 ,
struct V_323 * V_357 )
{
struct V_138 * V_139 = V_63 -> V_87 ;
struct V_903 args = {
. V_98 = V_63 ,
. V_241 = V_63 -> V_242 ,
. V_209 = V_63 -> V_880 ,
. V_922 = V_923 ,
} ;
struct V_917 V_56 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_924 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
int V_313 ;
F_546 ( & args ) ;
args . V_219 = ( V_925 | V_826 ) ;
V_313 = F_399 ( V_139 -> V_63 -> V_110 , & V_166 , V_618 ) ;
F_552 ( V_63 , V_313 ) ;
if ( ! V_313 ) {
V_313 = F_549 ( & args , & V_56 ) ;
if ( V_63 -> V_880 == V_56 . V_209 )
V_63 -> V_880 ++ ;
if ( V_313 )
goto V_136;
F_550 ( V_139 , & V_56 ) ;
}
V_136:
return V_313 ;
}
int F_553 ( struct V_62 * V_63 , struct V_323 * V_357 )
{
int V_313 ;
unsigned * V_926 ;
struct V_138 * V_139 = V_63 -> V_87 ;
F_8 ( L_89 , V_34 , V_63 , V_139 ) ;
V_313 = F_551 ( V_63 , V_357 ) ;
if ( V_313 )
goto V_136;
V_313 = F_554 ( V_139 ) ;
F_8 ( L_90 , V_313 ) ;
if ( V_313 )
goto V_136;
V_926 = ( unsigned * ) & V_139 -> V_825 . V_161 [ 0 ] ;
F_8 ( L_91 , V_34 ,
V_63 -> V_880 , V_926 [ 0 ] , V_926 [ 1 ] , V_926 [ 2 ] , V_926 [ 3 ] ) ;
V_136:
F_8 ( L_82 , V_34 ) ;
return V_313 ;
}
int F_555 ( struct V_138 * V_139 ,
struct V_323 * V_357 )
{
struct V_165 V_166 = {
. V_318 = & V_319 [ V_927 ] ,
. V_321 = V_139 ,
. V_323 = V_357 ,
} ;
int V_313 = 0 ;
F_8 ( L_92 ) ;
if ( ! F_126 ( V_878 , & V_139 -> V_879 ) )
return 0 ;
V_313 = F_399 ( V_139 -> V_63 -> V_110 , & V_166 , V_618 ) ;
F_556 ( V_139 -> V_63 , V_313 ) ;
if ( V_313 )
F_8 ( L_93
L_94 , V_313 ) ;
F_8 ( L_95 ) ;
return V_313 ;
}
static void F_557 ( void * V_161 )
{
struct V_928 * V_159 = V_161 ;
struct V_62 * V_63 = V_159 -> V_63 ;
if ( F_389 ( & V_63 -> V_612 ) > 1 )
F_390 ( V_63 ) ;
F_391 ( V_63 ) ;
F_105 ( V_159 ) ;
}
static int F_558 ( struct V_102 * V_103 , struct V_62 * V_63 )
{
switch( V_103 -> V_107 ) {
case - V_89 :
F_35 ( V_103 , V_52 ) ;
return - V_108 ;
default:
F_24 ( V_63 ) ;
}
return 0 ;
}
static void F_559 ( struct V_102 * V_103 , void * V_161 )
{
struct V_928 * V_159 = V_161 ;
struct V_62 * V_63 = V_159 -> V_63 ;
if ( ! F_60 ( V_103 , V_103 -> V_333 . V_322 ) )
return;
F_560 ( V_63 , V_103 -> V_107 ) ;
if ( V_103 -> V_107 < 0 ) {
F_8 ( L_96 , V_34 , V_103 -> V_107 ) ;
if ( F_389 ( & V_63 -> V_612 ) == 1 )
goto V_136;
if ( F_558 ( V_103 , V_63 ) == - V_108 ) {
F_65 ( V_103 ) ;
return;
}
}
F_8 ( L_97 , V_34 , V_103 -> V_333 . V_323 ) ;
V_136:
F_8 ( L_82 , V_34 ) ;
}
static void F_561 ( struct V_102 * V_103 , void * V_161 )
{
struct V_928 * V_159 = V_161 ;
struct V_62 * V_63 = V_159 -> V_63 ;
struct V_118 * args ;
struct V_119 * V_56 ;
args = V_103 -> V_333 . V_321 ;
V_56 = V_103 -> V_333 . V_322 ;
F_68 ( V_63 -> V_87 , args , V_56 , V_103 ) ;
}
static struct V_102 * F_562 ( struct V_62 * V_63 ,
struct V_323 * V_357 ,
bool V_929 )
{
struct V_928 * V_159 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_930 ] ,
. V_323 = V_357 ,
} ;
struct V_167 V_324 = {
. V_169 = V_63 -> V_110 ,
. V_165 = & V_166 ,
. V_170 = & V_931 ,
. V_219 = V_328 | V_618 ,
} ;
if ( ! F_396 ( & V_63 -> V_612 ) )
return F_52 ( - V_35 ) ;
V_159 = F_95 ( sizeof( * V_159 ) , V_310 ) ;
if ( V_159 == NULL ) {
F_391 ( V_63 ) ;
return F_52 ( - V_132 ) ;
}
F_46 ( & V_159 -> args , & V_159 -> V_56 , 0 ) ;
if ( V_929 )
F_47 ( & V_159 -> args ) ;
V_166 . V_321 = & V_159 -> args ;
V_166 . V_322 = & V_159 -> V_56 ;
V_159 -> V_63 = V_63 ;
V_324 . V_173 = V_159 ;
return F_77 ( & V_324 ) ;
}
static int F_563 ( struct V_62 * V_63 , struct V_323 * V_357 , unsigned V_616 )
{
struct V_102 * V_103 ;
int V_51 = 0 ;
if ( ( V_616 & V_932 ) == 0 )
return - V_108 ;
V_103 = F_562 ( V_63 , V_357 , false ) ;
if ( F_51 ( V_103 ) )
V_51 = F_78 ( V_103 ) ;
else
F_479 ( V_103 ) ;
F_8 ( L_16 , V_34 , V_51 ) ;
return V_51 ;
}
static int F_564 ( struct V_62 * V_63 , struct V_323 * V_357 )
{
struct V_102 * V_103 ;
int V_51 ;
V_103 = F_562 ( V_63 , V_357 , true ) ;
if ( F_51 ( V_103 ) ) {
V_51 = F_78 ( V_103 ) ;
goto V_136;
}
V_51 = F_117 ( V_103 ) ;
if ( ! V_51 )
V_51 = V_103 -> V_107 ;
F_79 ( V_103 ) ;
V_136:
F_8 ( L_16 , V_34 , V_51 ) ;
return V_51 ;
}
static void F_565 ( struct V_102 * V_103 , void * V_161 )
{
struct V_933 * V_159 = V_161 ;
F_68 ( V_159 -> V_63 -> V_87 ,
& V_159 -> V_401 . V_163 ,
& V_159 -> V_56 . V_164 ,
V_103 ) ;
}
static int F_566 ( struct V_102 * V_103 , struct V_62 * V_63 )
{
switch( V_103 -> V_107 ) {
case 0 :
case - V_934 :
case - V_23 :
break;
case - V_89 :
F_35 ( V_103 , V_52 ) ;
case - V_92 :
return - V_108 ;
default:
F_24 ( V_63 ) ;
}
return 0 ;
}
static void F_567 ( struct V_102 * V_103 , void * V_161 )
{
struct V_933 * V_159 = V_161 ;
struct V_62 * V_63 = V_159 -> V_63 ;
struct V_119 * V_56 = & V_159 -> V_56 . V_164 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_60 ( V_103 , V_56 ) )
return;
F_568 ( V_63 , V_103 -> V_107 ) ;
if ( F_566 ( V_103 , V_63 ) == - V_108 ) {
F_65 ( V_103 ) ;
return;
}
F_8 ( L_82 , V_34 ) ;
}
static void F_569 ( void * V_161 )
{
struct V_933 * V_159 = V_161 ;
F_105 ( V_159 ) ;
}
static int F_570 ( struct V_62 * V_63 ,
struct V_323 * V_357 )
{
struct V_933 * V_159 ;
struct V_102 * V_103 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_935 ] ,
. V_323 = V_357 ,
} ;
struct V_167 V_324 = {
. V_169 = V_63 -> V_110 ,
. V_165 = & V_166 ,
. V_170 = & V_936 ,
. V_219 = V_328 ,
} ;
int V_313 = - V_132 ;
F_8 ( L_11 , V_34 ) ;
V_159 = F_95 ( sizeof( * V_159 ) , V_310 ) ;
if ( V_159 == NULL )
goto V_136;
V_159 -> V_63 = V_63 ;
V_159 -> V_401 . V_937 = 0 ;
F_46 ( & V_159 -> V_401 . V_163 , & V_159 -> V_56 . V_164 , 0 ) ;
F_47 ( & V_159 -> V_401 . V_163 ) ;
V_166 . V_321 = & V_159 -> V_401 ;
V_166 . V_322 = & V_159 -> V_56 ;
V_324 . V_173 = V_159 ;
V_103 = F_77 ( & V_324 ) ;
if ( F_51 ( V_103 ) ) {
V_313 = F_78 ( V_103 ) ;
goto V_136;
}
V_313 = F_116 ( V_103 ) ;
if ( V_313 == 0 )
V_313 = V_103 -> V_107 ;
F_79 ( V_103 ) ;
return 0 ;
V_136:
F_8 ( L_16 , V_34 , V_313 ) ;
return V_313 ;
}
static void
F_571 ( struct V_102 * V_103 , void * V_159 )
{
struct V_938 * V_939 = V_159 ;
struct V_13 * V_14 = F_94 ( V_939 -> args . V_2 ) ;
struct V_138 * V_139 = F_71 ( V_14 ) ;
F_8 ( L_11 , V_34 ) ;
if ( F_68 ( V_139 , & V_939 -> args . V_163 ,
& V_939 -> V_56 . V_164 , V_103 ) )
return;
if ( F_572 ( & V_939 -> args . V_257 ,
F_82 ( V_939 -> args . V_2 ) -> V_940 ,
& V_939 -> args . V_941 ,
V_939 -> args . V_308 -> V_65 ) ) {
F_573 ( V_103 , V_791 ) ;
}
}
static void F_574 ( struct V_102 * V_103 , void * V_159 )
{
struct V_938 * V_939 = V_159 ;
struct V_2 * V_2 = V_939 -> args . V_2 ;
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_942 * V_943 ;
struct V_64 * V_65 = NULL ;
unsigned long V_944 , V_580 , V_945 ;
F_8 ( L_98 , V_34 , - V_103 -> V_107 ) ;
if ( ! F_60 ( V_103 , & V_939 -> V_56 . V_164 ) )
goto V_136;
switch ( V_103 -> V_107 ) {
case 0 :
goto V_136;
case - V_946 :
goto V_947;
case - V_19 :
if ( V_939 -> args . V_948 == 0 )
goto V_947;
case - V_20 :
V_944 = F_575 ( V_103 -> V_949 ) ;
V_945 = V_939 -> args . V_115 + V_944 ;
V_580 = V_157 ;
if ( F_576 ( V_945 , V_580 ) ) {
unsigned long V_66 ;
V_66 = F_577 (unsigned long, NFS4_POLL_RETRY_MIN,
min((giveup - now - 1),
now - lgp->args.timestamp)) ;
F_8 ( L_99 ,
V_34 , V_66 ) ;
F_35 ( V_103 , V_66 ) ;
goto V_950;
}
break;
case - V_74 :
case - V_72 :
F_41 ( & V_2 -> V_178 ) ;
if ( F_146 ( & V_939 -> args . V_257 ,
& V_939 -> args . V_308 -> V_65 -> V_257 ) ) {
F_43 ( & V_2 -> V_178 ) ;
V_65 = V_939 -> args . V_308 -> V_65 ;
break;
}
V_943 = F_82 ( V_2 ) -> V_940 ;
if ( V_943 && F_146 ( & V_939 -> args . V_257 ,
& V_943 -> V_951 ) ) {
F_578 ( V_952 ) ;
F_133 ( V_953 , & V_943 -> V_954 ) ;
F_579 ( V_943 , & V_952 , NULL ) ;
F_43 ( & V_2 -> V_178 ) ;
F_580 ( & V_952 ) ;
} else
F_43 ( & V_2 -> V_178 ) ;
goto V_950;
}
if ( F_38 ( V_103 , V_14 , V_65 , & V_939 -> V_50 ) == - V_108 )
goto V_950;
V_136:
F_8 ( L_82 , V_34 ) ;
return;
V_950:
V_103 -> V_107 = 0 ;
F_65 ( V_103 ) ;
return;
V_947:
V_103 -> V_107 = - V_955 ;
goto V_136;
}
static T_9 F_581 ( struct V_13 * V_14 )
{
T_1 V_905 = V_14 -> V_62 -> V_87 -> V_909 . V_905 ;
return F_582 ( 0 , V_905 ) ;
}
static void F_583 ( struct V_500 * * V_42 , T_9 V_956 )
{
int V_489 ;
if ( ! V_42 )
return;
for ( V_489 = 0 ; V_489 < V_956 ; V_489 ++ ) {
if ( ! V_42 [ V_489 ] )
break;
F_291 ( V_42 [ V_489 ] ) ;
}
F_105 ( V_42 ) ;
}
static struct V_500 * * F_584 ( T_9 V_956 , T_6 V_957 )
{
struct V_500 * * V_42 ;
int V_489 ;
V_42 = F_585 ( V_956 , sizeof( struct V_500 * ) , V_957 ) ;
if ( ! V_42 ) {
F_8 ( L_100 , V_34 , V_956 ) ;
return NULL ;
}
for ( V_489 = 0 ; V_489 < V_956 ; V_489 ++ ) {
V_42 [ V_489 ] = F_287 ( V_957 ) ;
if ( ! V_42 [ V_489 ] ) {
F_8 ( L_101 , V_34 ) ;
F_583 ( V_42 , V_956 ) ;
return NULL ;
}
}
return V_42 ;
}
static void F_586 ( void * V_159 )
{
struct V_938 * V_939 = V_159 ;
struct V_2 * V_2 = V_939 -> args . V_2 ;
struct V_13 * V_14 = F_94 ( V_2 ) ;
T_9 V_958 = F_581 ( V_14 ) ;
F_8 ( L_11 , V_34 ) ;
F_583 ( V_939 -> args . V_940 . V_42 , V_958 ) ;
F_587 ( F_82 ( V_2 ) -> V_940 ) ;
F_179 ( V_939 -> args . V_308 ) ;
F_105 ( V_159 ) ;
F_8 ( L_82 , V_34 ) ;
}
struct V_959 *
F_588 ( struct V_938 * V_939 , T_6 V_957 )
{
struct V_2 * V_2 = V_939 -> args . V_2 ;
struct V_13 * V_14 = F_94 ( V_2 ) ;
T_9 V_958 = F_581 ( V_14 ) ;
struct V_102 * V_103 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_960 ] ,
. V_321 = & V_939 -> args ,
. V_322 = & V_939 -> V_56 ,
. V_323 = V_939 -> V_357 ,
} ;
struct V_167 V_324 = {
. V_169 = V_14 -> V_98 ,
. V_165 = & V_166 ,
. V_170 = & V_961 ,
. V_173 = V_939 ,
. V_219 = V_328 ,
} ;
struct V_959 * V_962 = NULL ;
int V_313 = 0 ;
F_8 ( L_11 , V_34 ) ;
F_589 ( F_82 ( V_2 ) -> V_940 ) ;
V_939 -> args . V_940 . V_42 = F_584 ( V_958 , V_957 ) ;
if ( ! V_939 -> args . V_940 . V_42 ) {
F_586 ( V_939 ) ;
return F_52 ( - V_132 ) ;
}
V_939 -> args . V_940 . V_527 = V_958 * V_625 ;
V_939 -> args . V_115 = V_157 ;
V_939 -> V_56 . V_963 = & V_939 -> args . V_940 ;
V_939 -> V_56 . V_164 . V_124 = NULL ;
F_46 ( & V_939 -> args . V_163 , & V_939 -> V_56 . V_164 , 0 ) ;
V_103 = F_77 ( & V_324 ) ;
if ( F_51 ( V_103 ) )
return F_267 ( V_103 ) ;
V_313 = F_116 ( V_103 ) ;
if ( V_313 == 0 )
V_313 = V_103 -> V_107 ;
F_590 ( V_939 -> args . V_308 ,
& V_939 -> args . V_941 ,
& V_939 -> V_56 . V_941 ,
V_313 ) ;
if ( V_313 == 0 && V_939 -> V_56 . V_963 -> V_12 )
V_962 = F_591 ( V_939 ) ;
F_79 ( V_103 ) ;
F_8 ( L_16 , V_34 , V_313 ) ;
if ( V_313 )
return F_52 ( V_313 ) ;
return V_962 ;
}
static void
F_592 ( struct V_102 * V_103 , void * V_159 )
{
struct V_964 * V_965 = V_159 ;
F_8 ( L_11 , V_34 ) ;
F_68 ( V_965 -> V_63 -> V_87 ,
& V_965 -> args . V_163 ,
& V_965 -> V_56 . V_164 ,
V_103 ) ;
}
static void F_593 ( struct V_102 * V_103 , void * V_159 )
{
struct V_964 * V_965 = V_159 ;
struct V_13 * V_14 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_60 ( V_103 , & V_965 -> V_56 . V_164 ) )
return;
V_14 = F_94 ( V_965 -> args . V_2 ) ;
switch ( V_103 -> V_107 ) {
default:
V_103 -> V_107 = 0 ;
case 0 :
break;
case - V_89 :
if ( F_38 ( V_103 , V_14 , NULL , NULL ) != - V_108 )
break;
F_65 ( V_103 ) ;
return;
}
F_8 ( L_82 , V_34 ) ;
}
static void F_594 ( void * V_159 )
{
struct V_964 * V_965 = V_159 ;
struct V_942 * V_943 = V_965 -> args . V_940 ;
F_578 ( V_966 ) ;
F_8 ( L_11 , V_34 ) ;
F_41 ( & V_943 -> V_967 -> V_178 ) ;
if ( V_965 -> V_56 . V_968 )
F_595 ( V_943 , & V_965 -> V_56 . V_257 , true ) ;
F_579 ( V_943 , & V_966 , & V_965 -> args . V_941 ) ;
F_596 ( V_943 ) ;
V_943 -> V_969 -- ;
F_43 ( & V_943 -> V_967 -> V_178 ) ;
F_580 ( & V_966 ) ;
F_587 ( V_965 -> args . V_940 ) ;
F_447 ( V_965 -> V_2 ) ;
F_105 ( V_159 ) ;
F_8 ( L_82 , V_34 ) ;
}
int F_597 ( struct V_964 * V_965 , bool V_970 )
{
struct V_102 * V_103 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_971 ] ,
. V_321 = & V_965 -> args ,
. V_322 = & V_965 -> V_56 ,
. V_323 = V_965 -> V_357 ,
} ;
struct V_167 V_324 = {
. V_169 = F_94 ( V_965 -> args . V_2 ) -> V_98 ,
. V_165 = & V_166 ,
. V_170 = & V_972 ,
. V_173 = V_965 ,
} ;
int V_313 = 0 ;
F_8 ( L_11 , V_34 ) ;
if ( ! V_970 ) {
V_965 -> V_2 = F_450 ( V_965 -> args . V_2 ) ;
if ( ! V_965 -> V_2 ) {
F_594 ( V_965 ) ;
return - V_108 ;
}
V_324 . V_219 |= V_328 ;
}
F_46 ( & V_965 -> args . V_163 , & V_965 -> V_56 . V_164 , 1 ) ;
V_103 = F_77 ( & V_324 ) ;
if ( F_51 ( V_103 ) )
return F_78 ( V_103 ) ;
if ( V_970 )
V_313 = V_103 -> V_107 ;
F_598 ( V_965 -> args . V_2 , V_313 ) ;
F_8 ( L_16 , V_34 , V_313 ) ;
F_79 ( V_103 ) ;
return V_313 ;
}
static int
F_599 ( struct V_13 * V_14 ,
struct V_973 * V_974 ,
struct V_323 * V_357 )
{
struct V_975 args = {
. V_974 = V_974 ,
. V_976 = V_977 |
V_978 ,
} ;
struct V_979 V_56 = {
. V_974 = V_974 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_980 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
int V_313 ;
F_8 ( L_11 , V_34 ) ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
if ( V_56 . V_981 & ~ args . V_976 )
F_8 ( L_102 , V_34 ) ;
if ( V_56 . V_981 != args . V_976 )
V_974 -> V_982 = 1 ;
F_8 ( L_16 , V_34 , V_313 ) ;
return V_313 ;
}
int F_600 ( struct V_13 * V_14 ,
struct V_973 * V_974 ,
struct V_323 * V_357 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_31 ( V_14 ,
F_599 ( V_14 , V_974 , V_357 ) ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static void F_601 ( struct V_102 * V_103 , void * V_159 )
{
struct V_983 * V_161 = V_159 ;
struct V_13 * V_14 = F_94 ( V_161 -> args . V_2 ) ;
struct V_138 * V_139 = F_71 ( V_14 ) ;
F_68 ( V_139 ,
& V_161 -> args . V_163 ,
& V_161 -> V_56 . V_164 ,
V_103 ) ;
}
static void
F_602 ( struct V_102 * V_103 , void * V_159 )
{
struct V_983 * V_161 = V_159 ;
struct V_13 * V_14 = F_94 ( V_161 -> args . V_2 ) ;
if ( ! F_60 ( V_103 , & V_161 -> V_56 . V_164 ) )
return;
switch ( V_103 -> V_107 ) {
case - V_70 :
case - V_984 :
case - V_946 :
case - V_91 :
V_103 -> V_107 = 0 ;
case 0 :
break;
default:
if ( F_38 ( V_103 , V_14 , NULL , NULL ) == - V_108 ) {
F_65 ( V_103 ) ;
return;
}
}
}
static void F_603 ( void * V_159 )
{
struct V_983 * V_161 = V_159 ;
F_604 ( V_161 ) ;
F_451 ( V_161 -> args . V_2 ,
V_161 -> V_56 . V_398 ) ;
F_221 ( V_161 -> V_357 ) ;
F_447 ( V_161 -> V_2 ) ;
F_105 ( V_161 ) ;
}
int
F_605 ( struct V_983 * V_161 , bool V_970 )
{
struct V_165 V_166 = {
. V_318 = & V_319 [ V_985 ] ,
. V_321 = & V_161 -> args ,
. V_322 = & V_161 -> V_56 ,
. V_323 = V_161 -> V_357 ,
} ;
struct V_167 V_324 = {
. V_103 = & V_161 -> V_103 ,
. V_169 = F_306 ( V_161 -> args . V_2 ) ,
. V_165 = & V_166 ,
. V_170 = & V_986 ,
. V_173 = V_161 ,
} ;
struct V_102 * V_103 ;
int V_313 = 0 ;
F_8 ( L_103
L_104 , V_970 ,
V_161 -> args . V_987 ,
V_161 -> args . V_2 -> V_988 ) ;
if ( ! V_970 ) {
V_161 -> V_2 = F_450 ( V_161 -> args . V_2 ) ;
if ( V_161 -> V_2 == NULL ) {
F_603 ( V_161 ) ;
return - V_108 ;
}
V_324 . V_219 = V_328 ;
}
F_46 ( & V_161 -> args . V_163 , & V_161 -> V_56 . V_164 , 1 ) ;
V_103 = F_77 ( & V_324 ) ;
if ( F_51 ( V_103 ) )
return F_78 ( V_103 ) ;
if ( V_970 )
V_313 = V_103 -> V_107 ;
F_606 ( V_161 -> args . V_2 , V_313 ) ;
F_8 ( L_105 , V_34 , V_313 ) ;
F_79 ( V_103 ) ;
return V_313 ;
}
static int
F_607 ( struct V_13 * V_14 , struct V_435 * V_436 ,
struct V_475 * V_476 ,
struct V_803 * V_492 , bool V_804 )
{
struct V_989 args = {
. V_990 = V_991 ,
} ;
struct V_806 V_56 = {
. V_492 = V_492 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_992 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
struct V_54 * V_55 = V_14 -> V_98 ;
struct V_323 * V_357 = NULL ;
int V_313 ;
if ( V_804 ) {
V_55 = V_14 -> V_62 -> V_110 ;
V_357 = F_525 ( V_14 -> V_62 ) ;
V_166 . V_323 = V_357 ;
}
F_8 ( L_11 , V_34 ) ;
V_313 = F_80 ( V_55 , V_14 , & V_166 , & args . V_163 ,
& V_56 . V_164 , 0 ) ;
F_8 ( L_16 , V_34 , V_313 ) ;
if ( V_357 )
F_221 ( V_357 ) ;
return V_313 ;
}
static int
F_608 ( struct V_13 * V_14 , struct V_435 * V_436 ,
struct V_475 * V_476 , struct V_803 * V_492 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_39 ( V_14 -> V_62 ) )
V_8 = F_607 ( V_14 , V_436 , V_476 ,
V_492 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_607 ( V_14 , V_436 , V_476 ,
V_492 , false ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
case - V_993 :
goto V_136;
default:
V_8 = F_31 ( V_14 , V_8 , & V_61 ) ;
}
} while ( V_61 . V_68 );
V_136:
return V_8 ;
}
static int
F_609 ( struct V_13 * V_14 , struct V_435 * V_436 ,
struct V_475 * V_476 )
{
int V_8 ;
struct V_500 * V_500 ;
T_4 V_109 = V_994 ;
struct V_803 * V_492 ;
struct V_995 * V_996 ;
int V_489 ;
V_500 = F_287 ( V_389 ) ;
if ( ! V_500 ) {
V_8 = - V_132 ;
goto V_136;
}
V_492 = F_403 ( V_500 ) ;
V_8 = F_608 ( V_14 , V_436 , V_476 , V_492 ) ;
if ( V_8 == - V_22 || V_8 == - V_993 ) {
V_8 = F_278 ( V_14 , V_436 , V_476 ) ;
goto V_997;
}
if ( V_8 )
goto V_997;
for ( V_489 = 0 ; V_489 < V_492 -> V_998 ; V_489 ++ ) {
V_996 = & V_492 -> V_492 [ V_489 ] ;
switch ( V_996 -> V_109 ) {
case V_488 :
case V_487 :
case V_999 :
V_109 = F_610 ( V_996 -> V_109 ,
& V_996 -> V_1000 ) ;
break;
default:
V_109 = V_994 ;
break;
}
if ( ! F_611 ( & V_14 -> V_490 , V_109 ) )
V_109 = V_994 ;
if ( V_109 != V_994 ) {
V_8 = F_276 ( V_14 , V_436 ,
V_476 , V_109 ) ;
if ( ! V_8 )
break;
}
}
if ( V_109 == V_994 )
V_8 = - V_24 ;
V_997:
F_417 ( V_500 ) ;
if ( V_8 == - V_29 )
return - V_24 ;
V_136:
return V_8 ;
}
static int F_612 ( struct V_13 * V_14 ,
T_8 * V_257 ,
struct V_323 * V_357 )
{
int V_313 ;
struct V_1001 args = {
. V_257 = V_257 ,
} ;
struct V_1002 V_56 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_1003 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
struct V_54 * V_169 = V_14 -> V_98 ;
F_265 ( V_14 -> V_62 , V_854 ,
& V_169 , & V_166 ) ;
F_8 ( L_106 , V_257 ) ;
F_46 ( & args . V_163 , & V_56 . V_164 , 0 ) ;
F_47 ( & args . V_163 ) ;
V_313 = F_76 ( V_169 , V_14 , & V_166 ,
& args . V_163 , & V_56 . V_164 ) ;
if ( V_313 != V_370 ) {
F_8 ( L_107 , V_313 ) ;
return V_313 ;
}
F_8 ( L_108 , - V_56 . V_313 ) ;
return - V_56 . V_313 ;
}
static int F_218 ( struct V_13 * V_14 ,
T_8 * V_257 ,
struct V_323 * V_357 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_612 ( V_14 , V_257 , V_357 ) ;
if ( V_8 != - V_89 )
break;
F_31 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static void F_613 ( struct V_102 * V_103 , void * V_159 )
{
struct V_1004 * V_161 = V_159 ;
F_68 ( F_71 ( V_161 -> V_14 ) ,
& V_161 -> args . V_163 ,
& V_161 -> V_56 . V_164 ,
V_103 ) ;
}
static void F_614 ( struct V_102 * V_103 , void * V_159 )
{
struct V_1004 * V_161 = V_159 ;
F_60 ( V_103 , & V_161 -> V_56 . V_164 ) ;
switch ( V_103 -> V_107 ) {
case - V_89 :
if ( F_38 ( V_103 , V_161 -> V_14 , NULL , NULL ) == - V_108 )
F_65 ( V_103 ) ;
}
}
static void F_615 ( void * V_159 )
{
F_105 ( V_159 ) ;
}
static struct V_102 * F_616 ( struct V_13 * V_14 ,
T_8 * V_257 ,
struct V_323 * V_357 ,
bool V_1005 )
{
struct V_165 V_166 = {
. V_318 = & V_319 [ V_1006 ] ,
. V_323 = V_357 ,
} ;
struct V_167 V_168 = {
. V_169 = V_14 -> V_98 ,
. V_165 = & V_166 ,
. V_170 = & V_1007 ,
. V_219 = V_328 ,
} ;
struct V_1004 * V_161 ;
F_265 ( V_14 -> V_62 , V_854 ,
& V_168 . V_169 , & V_166 ) ;
F_8 ( L_109 , V_257 ) ;
V_161 = F_288 ( sizeof( * V_161 ) , V_310 ) ;
if ( ! V_161 )
return F_52 ( - V_132 ) ;
V_161 -> V_14 = V_14 ;
F_136 ( & V_161 -> args . V_257 , V_257 ) ;
V_168 . V_173 = V_161 ;
V_166 . V_321 = & V_161 -> args ;
V_166 . V_322 = & V_161 -> V_56 ;
F_46 ( & V_161 -> args . V_163 , & V_161 -> V_56 . V_164 , 0 ) ;
if ( V_1005 )
F_47 ( & V_161 -> args . V_163 ) ;
return F_77 ( & V_168 ) ;
}
static int F_220 ( struct V_13 * V_14 ,
T_8 * V_257 ,
struct V_323 * V_357 )
{
struct V_102 * V_103 ;
int V_51 ;
V_103 = F_616 ( V_14 , V_257 , V_357 , true ) ;
if ( F_51 ( V_103 ) )
return F_78 ( V_103 ) ;
V_51 = F_117 ( V_103 ) ;
if ( ! V_51 )
V_51 = V_103 -> V_107 ;
F_79 ( V_103 ) ;
return V_51 ;
}
static void
F_617 ( struct V_13 * V_14 , struct V_289 * V_290 )
{
struct V_102 * V_103 ;
struct V_323 * V_357 = V_290 -> V_291 -> V_232 -> V_298 ;
V_103 = F_616 ( V_14 , & V_290 -> V_293 , V_357 , false ) ;
F_502 ( V_14 , V_290 ) ;
if ( F_51 ( V_103 ) )
return;
F_79 ( V_103 ) ;
}
static bool F_618 ( const T_8 * V_1008 ,
const T_8 * V_1009 )
{
if ( memcmp ( V_1008 -> V_1010 , V_1009 -> V_1010 , sizeof( V_1008 -> V_1010 ) ) != 0 )
return false ;
if ( V_1008 -> V_209 == V_1009 -> V_209 )
return true ;
if ( V_1008 -> V_209 == 0 || V_1009 -> V_209 == 0 )
return true ;
return false ;
}
static bool F_619 ( const T_8 * V_1008 ,
const T_8 * V_1009 )
{
return F_146 ( V_1008 , V_1009 ) ;
}
static struct V_223 *
F_620 ( struct V_225 * V_1011 , T_6 V_1012 )
{
return NULL ;
}
