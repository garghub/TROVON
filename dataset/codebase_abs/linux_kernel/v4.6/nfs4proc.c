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
F_41 ( & V_65 -> V_232 -> V_284 ) ;
F_138 ( & V_65 -> V_281 ) ;
if ( V_283 != NULL ) {
F_136 ( & V_65 -> V_257 , V_283 ) ;
F_133 ( V_280 , & V_65 -> V_219 ) ;
}
if ( V_278 != NULL )
F_141 ( V_65 , V_278 , V_188 ) ;
F_139 ( & V_65 -> V_281 ) ;
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
F_161 ( V_161 -> V_65 ) ;
goto V_136;
}
V_51 = - V_108 ;
if ( ! ( V_161 -> V_207 . V_304 & V_305 ) )
goto V_8;
V_2 = F_162 ( V_161 -> V_3 -> V_231 , & V_161 -> V_206 . V_251 , & V_161 -> V_207 , V_161 -> V_208 ) ;
V_51 = F_78 ( V_2 ) ;
if ( F_51 ( V_2 ) )
goto V_8;
V_51 = - V_132 ;
V_65 = F_163 ( V_2 , V_161 -> V_232 ) ;
if ( V_65 == NULL )
goto V_306;
if ( V_161 -> V_206 . V_303 != 0 )
F_154 ( V_161 , V_65 ) ;
F_143 ( V_65 , & V_161 -> V_206 . V_257 , NULL ,
V_161 -> V_210 . V_188 ) ;
F_164 ( V_2 ) ;
V_136:
F_152 ( V_161 -> V_210 . V_209 ) ;
return V_65 ;
V_306:
F_164 ( V_2 ) ;
V_8:
return F_52 ( V_51 ) ;
}
static struct V_64 *
F_165 ( struct V_205 * V_161 )
{
if ( V_161 -> V_210 . V_198 == V_252 )
return F_158 ( V_161 ) ;
return F_160 ( V_161 ) ;
}
static struct V_307 * F_166 ( struct V_64 * V_65 )
{
struct V_176 * V_177 = F_82 ( V_65 -> V_2 ) ;
struct V_307 * V_308 ;
F_41 ( & V_65 -> V_2 -> V_178 ) ;
F_167 (ctx, &nfsi->open_files, list) {
if ( V_308 -> V_65 != V_65 )
continue;
F_168 ( V_308 ) ;
F_43 ( & V_65 -> V_2 -> V_178 ) ;
return V_308 ;
}
F_43 ( & V_65 -> V_2 -> V_178 ) ;
return F_52 ( - V_309 ) ;
}
static struct V_205 * F_169 ( struct V_307 * V_308 ,
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
static int F_170 ( struct V_205 * V_295 ,
T_5 V_188 )
{
struct V_64 * V_311 ;
int V_51 ;
if ( ! F_118 ( V_295 -> V_65 , V_188 ) )
return 0 ;
V_295 -> V_210 . V_234 = 0 ;
V_295 -> V_210 . V_188 = V_188 ;
V_295 -> V_210 . V_235 = F_87 (
F_171 ( V_295 -> V_4 -> V_231 ) ,
V_188 , 0 ) ;
memset ( & V_295 -> V_206 , 0 , sizeof( V_295 -> V_206 ) ) ;
memset ( & V_295 -> V_211 , 0 , sizeof( V_295 -> V_211 ) ) ;
F_89 ( V_295 ) ;
V_51 = F_172 ( V_295 ) ;
if ( V_51 != 0 )
return V_51 ;
V_311 = F_165 ( V_295 ) ;
if ( F_51 ( V_311 ) )
return F_78 ( V_311 ) ;
if ( V_311 != V_295 -> V_65 )
V_51 = - V_312 ;
F_173 ( V_311 , V_188 ) ;
return V_51 ;
}
static int F_174 ( struct V_205 * V_295 , struct V_64 * V_65 )
{
int V_51 ;
F_135 ( V_270 , & V_65 -> V_219 ) ;
F_135 ( V_269 , & V_65 -> V_219 ) ;
F_135 ( V_268 , & V_65 -> V_219 ) ;
F_135 ( V_280 , & V_65 -> V_219 ) ;
F_135 ( V_277 , & V_65 -> V_219 ) ;
F_175 () ;
V_51 = F_170 ( V_295 , V_190 | V_191 ) ;
if ( V_51 != 0 )
return V_51 ;
V_51 = F_170 ( V_295 , V_191 ) ;
if ( V_51 != 0 )
return V_51 ;
V_51 = F_170 ( V_295 , V_190 ) ;
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
static int F_176 ( struct V_307 * V_308 , struct V_64 * V_65 )
{
struct V_271 * V_272 ;
struct V_205 * V_295 ;
T_5 V_303 = 0 ;
int V_313 ;
V_295 = F_169 ( V_308 , V_65 ,
V_252 ) ;
if ( F_51 ( V_295 ) )
return F_78 ( V_295 ) ;
F_144 () ;
V_272 = F_145 ( F_82 ( V_65 -> V_2 ) -> V_272 ) ;
if ( V_272 != NULL && F_33 ( V_274 , & V_272 -> V_219 ) != 0 )
V_303 = V_272 -> type ;
F_147 () ;
V_295 -> V_210 . V_255 . V_303 = V_303 ;
V_313 = F_174 ( V_295 , V_65 ) ;
F_114 ( V_295 ) ;
return V_313 ;
}
static int F_177 ( struct V_307 * V_308 , struct V_64 * V_65 )
{
struct V_13 * V_14 = F_94 ( V_65 -> V_2 ) ;
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_176 ( V_308 , V_65 ) ;
F_178 ( V_308 , 0 , V_8 ) ;
if ( F_86 ( V_14 , V_8 , & V_61 ) )
continue;
if ( V_8 != - V_89 )
break;
F_31 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_179 ( struct V_217 * V_218 , struct V_64 * V_65 )
{
struct V_307 * V_308 ;
int V_51 ;
V_308 = F_166 ( V_65 ) ;
if ( F_51 ( V_308 ) )
return - V_108 ;
V_51 = F_177 ( V_308 , V_65 ) ;
F_180 ( V_308 ) ;
return V_51 ;
}
static int F_181 ( struct V_13 * V_14 , struct V_64 * V_65 , const T_8 * V_257 , int V_8 )
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
F_182 ( V_65 -> V_2 ,
V_257 ) ;
F_23 ( V_14 , V_65 ) ;
return - V_108 ;
case - V_89 :
case - V_91 :
F_133 ( V_280 , & V_65 -> V_219 ) ;
F_183 ( 1 ) ;
return - V_108 ;
case - V_132 :
case - V_315 :
return 0 ;
}
return V_8 ;
}
int F_184 ( struct V_307 * V_308 ,
struct V_64 * V_65 , const T_8 * V_257 ,
T_5 type )
{
struct V_13 * V_14 = F_94 ( V_65 -> V_2 ) ;
struct V_205 * V_295 ;
int V_8 = 0 ;
V_295 = F_169 ( V_308 , V_65 ,
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
V_8 = F_170 ( V_295 , V_190 | V_191 ) ;
if ( V_8 )
break;
V_8 = F_170 ( V_295 , V_191 ) ;
if ( V_8 )
break;
case V_190 :
V_8 = F_170 ( V_295 , V_190 ) ;
}
F_114 ( V_295 ) ;
return F_181 ( V_14 , V_65 , V_257 , V_8 ) ;
}
static void F_185 ( struct V_102 * V_103 , void * V_159 )
{
struct V_205 * V_161 = V_159 ;
F_48 ( V_161 -> V_210 . V_14 -> V_62 -> V_158 ,
& V_161 -> V_212 . V_163 , & V_161 -> V_211 . V_164 , V_103 ) ;
}
static void F_186 ( struct V_102 * V_103 , void * V_159 )
{
struct V_205 * V_161 = V_159 ;
F_55 ( V_103 , & V_161 -> V_211 . V_164 ) ;
V_161 -> V_301 = V_103 -> V_107 ;
if ( V_161 -> V_301 == 0 ) {
F_136 ( & V_161 -> V_206 . V_257 , & V_161 -> V_211 . V_257 ) ;
F_187 ( & V_161 -> V_232 -> V_229 , 0 ) ;
F_44 ( V_161 -> V_206 . V_14 , V_161 -> V_115 ) ;
V_161 -> V_300 = 1 ;
}
}
static void F_188 ( void * V_159 )
{
struct V_205 * V_161 = V_159 ;
struct V_64 * V_65 = NULL ;
if ( V_161 -> V_316 == 0 )
goto V_317;
if ( ! V_161 -> V_300 )
goto V_317;
V_65 = F_165 ( V_161 ) ;
if ( ! F_51 ( V_65 ) )
F_173 ( V_65 , V_161 -> V_210 . V_188 ) ;
V_317:
F_114 ( V_161 ) ;
}
static int F_189 ( struct V_205 * V_161 )
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
F_190 ( & V_161 -> V_258 ) ;
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
F_191 () ;
} else
V_313 = V_161 -> V_301 ;
F_79 ( V_103 ) ;
return V_313 ;
}
static void F_192 ( struct V_102 * V_103 , void * V_159 )
{
struct V_205 * V_161 = V_159 ;
struct V_217 * V_218 = V_161 -> V_232 ;
struct V_62 * V_63 = V_218 -> V_275 -> V_62 ;
enum V_197 V_198 = V_161 -> V_210 . V_198 ;
if ( F_193 ( V_161 -> V_210 . V_209 , V_103 ) != 0 )
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
F_194 ( & V_161 -> V_206 . V_251 , V_161 -> V_210 . V_251 ) ;
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
if ( F_195 ( V_63 ) )
V_161 -> V_210 . V_335 = V_338 ;
else if ( V_63 -> V_171 -> V_339 > 0 )
V_161 -> V_210 . V_335 = V_340 ;
}
return;
V_331:
F_161 ( V_161 -> V_65 ) ;
F_147 () ;
V_330:
V_103 -> V_341 = NULL ;
V_329:
F_67 ( V_103 , & V_161 -> V_206 . V_164 ) ;
}
static void F_196 ( struct V_102 * V_103 , void * V_159 )
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
F_187 ( & V_161 -> V_232 -> V_229 , 0 ) ;
}
V_161 -> V_300 = 1 ;
}
static void F_197 ( void * V_159 )
{
struct V_205 * V_161 = V_159 ;
struct V_64 * V_65 = NULL ;
if ( V_161 -> V_316 == 0 )
goto V_317;
if ( V_161 -> V_301 != 0 || ! V_161 -> V_300 )
goto V_317;
if ( V_161 -> V_206 . V_350 & V_351 )
goto V_317;
V_65 = F_165 ( V_161 ) ;
if ( ! F_51 ( V_65 ) )
F_173 ( V_65 , V_161 -> V_210 . V_188 ) ;
V_317:
F_114 ( V_161 ) ;
}
static int F_198 ( struct V_205 * V_161 , int V_352 )
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
F_190 ( & V_161 -> V_258 ) ;
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
F_191 () ;
} else
V_313 = V_161 -> V_301 ;
F_79 ( V_103 ) ;
return V_313 ;
}
static int F_172 ( struct V_205 * V_161 )
{
struct V_2 * V_3 = F_14 ( V_161 -> V_3 ) ;
struct V_354 * V_206 = & V_161 -> V_206 ;
int V_313 ;
V_313 = F_198 ( V_161 , 1 ) ;
if ( V_313 != 0 || ! V_161 -> V_300 )
return V_313 ;
F_199 ( F_94 ( V_3 ) , & V_161 -> V_207 ) ;
if ( V_206 -> V_350 & V_351 ) {
V_313 = F_189 ( V_161 ) ;
if ( V_313 != 0 )
return V_313 ;
}
return V_313 ;
}
static int F_200 ( struct V_323 * V_357 ,
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
F_201 ( & V_359 , V_295 -> V_206 . V_366 ) ;
F_202 ( V_65 -> V_2 , & V_359 ) ;
if ( ( V_360 & ~ V_359 . V_360 & ( V_365 | V_363 ) ) == 0 )
return 0 ;
F_173 ( V_65 , V_188 ) ;
return - V_29 ;
}
static int F_203 ( struct V_205 * V_161 )
{
struct V_2 * V_3 = F_14 ( V_161 -> V_3 ) ;
struct V_13 * V_14 = F_94 ( V_3 ) ;
struct V_353 * V_210 = & V_161 -> V_210 ;
struct V_354 * V_206 = & V_161 -> V_206 ;
int V_313 ;
V_313 = F_198 ( V_161 , 0 ) ;
if ( ! V_161 -> V_300 )
return V_313 ;
if ( V_313 != 0 ) {
if ( V_313 == - V_26 &&
! ( V_210 -> V_234 & V_367 ) )
return - V_309 ;
return V_313 ;
}
F_199 ( V_14 , & V_161 -> V_207 ) ;
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
V_313 = F_189 ( V_161 ) ;
if ( V_313 != 0 )
return V_313 ;
}
if ( ! ( V_206 -> V_207 -> V_304 & V_305 ) )
F_204 ( V_14 , & V_206 -> V_251 , V_206 -> V_207 , V_206 -> V_208 ) ;
return 0 ;
}
static int F_205 ( struct V_13 * V_14 )
{
return F_206 ( V_14 -> V_62 ) ;
}
static int F_207 ( struct V_307 * V_308 , struct V_64 * V_65 )
{
struct V_205 * V_295 ;
int V_51 ;
V_295 = F_169 ( V_308 , V_65 ,
V_199 ) ;
if ( F_51 ( V_295 ) )
return F_78 ( V_295 ) ;
V_51 = F_174 ( V_295 , V_65 ) ;
if ( V_51 == - V_312 )
F_208 ( V_308 -> V_4 ) ;
F_114 ( V_295 ) ;
return V_51 ;
}
static int F_209 ( struct V_307 * V_308 , struct V_64 * V_65 )
{
struct V_13 * V_14 = F_94 ( V_65 -> V_2 ) ;
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_207 ( V_308 , V_65 ) ;
F_210 ( V_308 , 0 , V_8 ) ;
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
static int F_211 ( struct V_217 * V_218 , struct V_64 * V_65 )
{
struct V_307 * V_308 ;
int V_51 ;
V_308 = F_166 ( V_65 ) ;
if ( F_51 ( V_308 ) )
return - V_108 ;
V_51 = F_209 ( V_308 , V_65 ) ;
F_180 ( V_308 ) ;
return V_51 ;
}
static void F_212 ( struct V_64 * V_65 )
{
F_213 ( V_65 -> V_2 ) ;
F_138 ( & V_65 -> V_281 ) ;
F_136 ( & V_65 -> V_257 , & V_65 -> V_278 ) ;
F_139 ( & V_65 -> V_281 ) ;
F_135 ( V_280 , & V_65 -> V_219 ) ;
}
static void F_214 ( struct V_64 * V_65 )
{
if ( F_215 ( F_82 ( V_65 -> V_2 ) -> V_272 ) != NULL )
F_212 ( V_65 ) ;
}
static int F_216 ( struct V_217 * V_218 , struct V_64 * V_65 )
{
F_214 ( V_65 ) ;
return F_211 ( V_218 , V_65 ) ;
}
static void F_217 ( struct V_64 * V_65 )
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
V_357 = F_218 ( V_272 -> V_357 ) ;
F_147 () ;
V_313 = F_219 ( V_14 , & V_257 , V_357 ) ;
F_220 ( V_65 , NULL , V_313 ) ;
if ( V_313 != V_370 ) {
if ( V_313 != - V_72 )
F_221 ( V_14 , & V_257 , V_357 ) ;
F_212 ( V_65 ) ;
}
F_222 ( V_357 ) ;
}
static int F_223 ( struct V_64 * V_65 )
{
struct V_13 * V_14 = F_94 ( V_65 -> V_2 ) ;
T_8 * V_257 = & V_65 -> V_278 ;
struct V_323 * V_357 = V_65 -> V_232 -> V_298 ;
int V_313 ;
if ( ( F_33 ( V_268 , & V_65 -> V_219 ) == 0 ) &&
( F_33 ( V_269 , & V_65 -> V_219 ) == 0 ) &&
( F_33 ( V_270 , & V_65 -> V_219 ) == 0 ) )
return - V_72 ;
V_313 = F_219 ( V_14 , V_257 , V_357 ) ;
F_224 ( V_65 , NULL , V_313 ) ;
if ( V_313 != V_370 ) {
if ( V_313 != - V_72 )
F_221 ( V_14 , V_257 , V_357 ) ;
F_135 ( V_268 , & V_65 -> V_219 ) ;
F_135 ( V_269 , & V_65 -> V_219 ) ;
F_135 ( V_270 , & V_65 -> V_219 ) ;
F_135 ( V_277 , & V_65 -> V_219 ) ;
}
return V_313 ;
}
static int F_225 ( struct V_217 * V_218 , struct V_64 * V_65 )
{
int V_313 ;
F_217 ( V_65 ) ;
V_313 = F_223 ( V_65 ) ;
if ( V_313 != V_370 )
V_313 = F_211 ( V_218 , V_65 ) ;
return V_313 ;
}
static inline void F_226 ( struct V_205 * V_295 ,
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
static int F_227 ( struct V_205 * V_295 ,
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
V_381 = F_228 ( & V_218 -> V_382 ) ;
V_51 = F_203 ( V_295 ) ;
if ( V_51 != 0 )
goto V_136;
V_65 = F_165 ( V_295 ) ;
V_51 = F_78 ( V_65 ) ;
if ( F_51 ( V_65 ) )
goto V_136;
if ( V_14 -> V_94 & V_369 )
F_133 ( V_383 , & V_65 -> V_219 ) ;
V_4 = V_295 -> V_4 ;
if ( F_229 ( V_4 ) ) {
struct V_4 * V_384 ;
F_208 ( V_4 ) ;
V_384 = F_230 ( V_4 , V_65 -> V_2 ) ;
if ( ! V_384 )
V_384 = F_231 ( F_232 ( V_65 -> V_2 ) , V_4 ) ;
if ( V_384 ) {
F_106 ( V_308 -> V_4 ) ;
V_308 -> V_4 = V_4 = V_384 ;
}
F_233 ( V_4 ,
F_234 ( F_14 ( V_295 -> V_3 ) ) ) ;
}
V_51 = F_200 ( V_218 -> V_298 , V_295 , V_65 , V_188 , V_219 ) ;
if ( V_51 != 0 )
goto V_136;
V_308 -> V_65 = V_65 ;
if ( F_14 ( V_4 ) == V_65 -> V_2 ) {
F_235 ( V_308 ) ;
if ( F_236 ( & V_218 -> V_382 , V_381 ) )
F_23 ( V_14 , V_65 ) ;
}
V_136:
return V_51 ;
}
static int F_237 ( struct V_2 * V_3 ,
struct V_307 * V_308 ,
int V_219 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_385 )
{
struct V_217 * V_218 ;
struct V_64 * V_65 = NULL ;
struct V_13 * V_14 = F_94 ( V_3 ) ;
struct V_205 * V_295 ;
struct V_4 * V_4 = V_308 -> V_4 ;
struct V_323 * V_357 = V_308 -> V_357 ;
struct V_386 * * V_387 = & V_308 -> V_261 ;
T_5 V_188 = V_308 -> V_265 & ( V_190 | V_191 | V_388 ) ;
enum V_197 V_198 = V_200 ;
struct V_1 * V_389 = NULL ;
int V_313 ;
V_313 = - V_132 ;
V_218 = F_238 ( V_14 , V_357 , V_390 ) ;
if ( V_218 == NULL ) {
F_8 ( L_23 ) ;
goto V_391;
}
V_313 = F_205 ( V_14 ) ;
if ( V_313 != 0 )
goto V_392;
if ( F_239 ( V_4 ) )
F_149 ( F_14 ( V_4 ) , V_188 ) ;
V_313 = - V_132 ;
if ( F_239 ( V_4 ) )
V_198 = V_199 ;
V_295 = F_92 ( V_4 , V_218 , V_188 , V_219 , V_6 ,
V_7 , V_198 , V_390 ) ;
if ( V_295 == NULL )
goto V_392;
if ( V_7 ) {
V_389 = F_96 ( V_14 , V_390 ) ;
if ( F_51 ( V_389 ) ) {
V_313 = F_78 ( V_389 ) ;
goto V_393;
}
}
if ( V_14 -> V_15 [ 2 ] & V_394 ) {
if ( ! V_295 -> V_207 . V_261 ) {
V_295 -> V_207 . V_261 = F_240 () ;
if ( ! V_295 -> V_207 . V_261 )
goto V_230;
}
V_295 -> V_210 . V_249 = & V_395 [ 0 ] ;
}
if ( F_239 ( V_4 ) )
V_295 -> V_65 = F_163 ( F_14 ( V_4 ) , V_218 ) ;
V_313 = F_227 ( V_295 , V_188 , V_219 , V_308 ) ;
if ( V_313 != 0 )
goto V_230;
V_65 = V_308 -> V_65 ;
if ( ( V_295 -> V_210 . V_234 & ( V_367 | V_236 ) ) == ( V_367 | V_236 ) &&
( V_295 -> V_210 . V_335 != V_338 ) ) {
F_226 ( V_295 , V_6 , & V_7 ) ;
F_90 ( V_295 -> V_206 . V_207 ) ;
V_313 = F_241 ( V_65 -> V_2 , V_357 ,
V_295 -> V_206 . V_207 , V_6 ,
V_65 , V_7 , V_389 ) ;
if ( V_313 == 0 ) {
F_242 ( V_65 -> V_2 , V_6 ,
V_295 -> V_206 . V_207 ) ;
F_243 ( V_65 -> V_2 , V_295 -> V_206 . V_207 , V_389 ) ;
}
}
if ( V_385 && V_295 -> V_364 )
* V_385 |= V_396 ;
if ( F_244 ( V_387 , V_295 -> V_207 . V_261 , V_14 ) ) {
* V_387 = V_295 -> V_207 . V_261 ;
V_295 -> V_207 . V_261 = NULL ;
}
F_104 ( V_389 ) ;
F_114 ( V_295 ) ;
F_111 ( V_218 ) ;
return 0 ;
V_230:
F_104 ( V_389 ) ;
V_393:
F_114 ( V_295 ) ;
V_392:
F_111 ( V_218 ) ;
V_391:
return V_313 ;
}
static struct V_64 * F_245 ( struct V_2 * V_3 ,
struct V_307 * V_308 ,
int V_219 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_385 )
{
struct V_13 * V_14 = F_94 ( V_3 ) ;
struct V_60 V_61 = { } ;
struct V_64 * V_56 ;
int V_313 ;
do {
V_313 = F_237 ( V_3 , V_308 , V_219 , V_6 , V_7 , V_385 ) ;
V_56 = V_308 -> V_65 ;
F_246 ( V_308 , V_219 , V_313 ) ;
if ( V_313 == 0 )
break;
if ( V_313 == - V_397 ) {
F_247 ( L_5
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
static int F_248 ( struct V_2 * V_2 , struct V_323 * V_357 ,
struct V_398 * V_399 , struct V_5 * V_6 ,
struct V_64 * V_65 , struct V_1 * V_400 ,
struct V_1 * V_389 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_401 V_402 = {
. V_251 = F_102 ( V_2 ) ,
. V_403 = V_6 ,
. V_14 = V_14 ,
. V_248 = V_14 -> V_15 ,
. V_7 = V_400 ,
} ;
struct V_404 V_56 = {
. V_399 = V_399 ,
. V_7 = V_389 ,
. V_14 = V_14 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_405 ] ,
. V_321 = & V_402 ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
unsigned long V_115 = V_157 ;
T_5 V_188 ;
bool V_406 ;
int V_313 ;
V_402 . V_248 = F_6 ( V_14 , V_400 ) ;
if ( V_400 )
V_402 . V_248 = F_6 ( V_14 , V_389 ) ;
F_90 ( V_399 ) ;
V_406 = ( V_6 -> V_253 & V_407 ) ? true : false ;
V_188 = V_406 ? V_191 : V_190 ;
if ( F_249 ( & V_402 . V_257 , V_2 , V_188 ) ) {
} else if ( V_406 && V_65 != NULL ) {
struct V_408 V_409 = {
. V_410 = V_57 -> V_411 ,
. V_412 = V_57 -> V_413 ,
} ;
if ( ! F_250 ( V_65 ) )
return - V_414 ;
if ( F_251 ( & V_402 . V_257 , V_65 , V_191 ,
& V_409 ) == - V_35 )
return - V_414 ;
} else
F_136 ( & V_402 . V_257 , & V_415 ) ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & V_402 . V_163 , & V_56 . V_164 , 1 ) ;
if ( V_313 == 0 && V_65 != NULL )
F_44 ( V_14 , V_115 ) ;
F_252 ( V_2 , & V_402 . V_257 , V_313 ) ;
return V_313 ;
}
static int F_241 ( struct V_2 * V_2 , struct V_323 * V_357 ,
struct V_398 * V_399 , struct V_5 * V_6 ,
struct V_64 * V_65 , struct V_1 * V_400 ,
struct V_1 * V_389 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_60 V_61 = {
. V_65 = V_65 ,
. V_2 = V_2 ,
} ;
int V_8 ;
do {
V_8 = F_248 ( V_2 , V_357 , V_399 , V_6 , V_65 , V_400 , V_389 ) ;
switch ( V_8 ) {
case - V_69 :
if ( ! ( V_6 -> V_253 & V_407 ) ) {
F_253 ( L_25
L_26
L_27
L_28 ,
V_14 -> V_62 -> V_97 ) ;
}
if ( V_65 && ! ( V_65 -> V_65 & V_191 ) ) {
V_8 = - V_414 ;
if ( V_6 -> V_253 & V_416 )
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
F_254 ( struct V_2 * V_2 , struct V_102 * V_103 )
{
if ( V_2 == NULL || ! F_255 ( V_2 ) )
return false ;
return F_256 ( V_2 , V_103 ) ;
}
static void F_257 ( void * V_161 )
{
struct V_417 * V_159 = V_161 ;
struct V_217 * V_218 = V_159 -> V_65 -> V_232 ;
struct V_259 * V_260 = V_159 -> V_65 -> V_2 -> V_418 ;
if ( V_159 -> V_419 )
F_258 ( V_159 -> V_65 -> V_2 ) ;
F_110 ( V_159 -> V_65 ) ;
F_109 ( V_159 -> V_402 . V_209 ) ;
F_111 ( V_218 ) ;
F_112 ( V_260 ) ;
F_105 ( V_159 ) ;
}
static void F_259 ( struct V_102 * V_103 , void * V_161 )
{
struct V_417 * V_159 = V_161 ;
struct V_64 * V_65 = V_159 -> V_65 ;
struct V_13 * V_14 = F_94 ( V_159 -> V_2 ) ;
T_8 * V_420 = NULL ;
F_8 ( L_29 , V_34 ) ;
if ( ! F_67 ( V_103 , & V_159 -> V_56 . V_164 ) )
return;
F_260 ( V_65 , & V_159 -> V_402 , & V_159 -> V_56 , V_103 -> V_107 ) ;
switch ( V_103 -> V_107 ) {
case 0 :
V_420 = & V_159 -> V_56 . V_257 ;
if ( V_159 -> V_419 )
F_261 ( V_65 -> V_2 ,
V_159 -> V_421 ) ;
F_44 ( V_14 , V_159 -> V_115 ) ;
break;
case - V_71 :
case - V_75 :
case - V_93 :
case - V_72 :
case - V_74 :
if ( ! F_146 ( & V_159 -> V_402 . V_257 ,
& V_65 -> V_278 ) ) {
F_65 ( V_103 ) ;
goto V_422;
}
if ( V_159 -> V_402 . V_188 == 0 )
break;
default:
if ( F_38 ( V_103 , V_14 , V_65 , NULL ) == - V_108 ) {
F_65 ( V_103 ) ;
goto V_422;
}
}
F_137 ( V_65 , & V_159 -> V_402 . V_257 ,
V_420 , V_159 -> V_402 . V_188 ) ;
V_422:
F_152 ( V_159 -> V_402 . V_209 ) ;
F_159 ( V_159 -> V_2 , V_159 -> V_56 . V_399 ) ;
F_8 ( L_30 , V_34 , V_103 -> V_107 ) ;
}
static void F_262 ( struct V_102 * V_103 , void * V_161 )
{
struct V_417 * V_159 = V_161 ;
struct V_64 * V_65 = V_159 -> V_65 ;
struct V_2 * V_2 = V_159 -> V_2 ;
bool V_423 , V_424 , V_425 ;
int V_426 = 0 ;
F_8 ( L_29 , V_34 ) ;
if ( F_193 ( V_159 -> V_402 . V_209 , V_103 ) != 0 )
goto V_329;
V_103 -> V_333 . V_318 = & V_319 [ V_427 ] ;
F_41 ( & V_65 -> V_232 -> V_284 ) ;
V_425 = F_33 ( V_270 , & V_65 -> V_219 ) ;
V_423 = F_33 ( V_268 , & V_65 -> V_219 ) ;
V_424 = F_33 ( V_269 , & V_65 -> V_219 ) ;
F_136 ( & V_159 -> V_402 . V_257 , & V_65 -> V_278 ) ;
V_159 -> V_402 . V_188 = 0 ;
if ( V_65 -> V_262 == 0 ) {
if ( V_65 -> V_264 == 0 )
V_426 |= V_423 ;
else if ( V_423 )
V_159 -> V_402 . V_188 |= V_190 ;
if ( V_65 -> V_263 == 0 )
V_426 |= V_424 ;
else if ( V_424 )
V_159 -> V_402 . V_188 |= V_191 ;
} else if ( V_425 )
V_159 -> V_402 . V_188 |= V_190 | V_191 ;
if ( V_159 -> V_402 . V_188 == 0 )
V_426 |= V_425 ;
if ( ! F_250 ( V_65 ) )
V_426 = 0 ;
F_43 ( & V_65 -> V_232 -> V_284 ) ;
if ( ! V_426 ) {
goto V_330;
}
if ( F_254 ( V_2 , V_103 ) ) {
F_152 ( V_159 -> V_402 . V_209 ) ;
goto V_329;
}
if ( V_159 -> V_402 . V_188 == 0 )
V_103 -> V_333 . V_318 = & V_319 [ V_428 ] ;
if ( V_159 -> V_419 )
F_263 ( V_2 , & V_159 -> V_421 ) ;
V_159 -> V_402 . V_235 =
F_87 ( F_94 ( V_2 ) ,
V_159 -> V_402 . V_188 , 0 ) ;
F_90 ( V_159 -> V_56 . V_399 ) ;
V_159 -> V_115 = V_157 ;
if ( F_70 ( F_94 ( V_2 ) ,
& V_159 -> V_402 . V_163 ,
& V_159 -> V_56 . V_164 ,
V_103 ) != 0 )
F_152 ( V_159 -> V_402 . V_209 ) ;
F_8 ( L_31 , V_34 ) ;
return;
V_330:
V_103 -> V_341 = NULL ;
V_329:
F_67 ( V_103 , & V_159 -> V_56 . V_164 ) ;
}
static bool F_264 ( struct V_2 * V_2 )
{
if ( ! F_255 ( V_2 ) )
return false ;
return F_265 ( V_2 ) ;
}
int F_266 ( struct V_64 * V_65 , T_6 V_221 , int V_429 )
{
struct V_13 * V_14 = F_94 ( V_65 -> V_2 ) ;
struct V_223 * ( * V_224 ) ( struct V_225 * , T_6 ) ;
struct V_417 * V_159 ;
struct V_217 * V_218 = V_65 -> V_232 ;
struct V_102 * V_103 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_428 ] ,
. V_323 = V_65 -> V_232 -> V_298 ,
} ;
struct V_167 V_324 = {
. V_169 = V_14 -> V_98 ,
. V_165 = & V_166 ,
. V_170 = & V_430 ,
. V_326 = V_327 ,
. V_219 = V_328 ,
} ;
int V_313 = - V_132 ;
F_267 ( V_14 -> V_62 , V_431 ,
& V_324 . V_169 , & V_166 ) ;
V_159 = F_95 ( sizeof( * V_159 ) , V_221 ) ;
if ( V_159 == NULL )
goto V_136;
F_46 ( & V_159 -> V_402 . V_163 , & V_159 -> V_56 . V_164 , 1 ) ;
V_159 -> V_2 = V_65 -> V_2 ;
V_159 -> V_65 = V_65 ;
V_159 -> V_402 . V_251 = F_102 ( V_65 -> V_2 ) ;
V_224 = V_14 -> V_62 -> V_171 -> V_224 ;
V_159 -> V_402 . V_209 = V_224 ( & V_65 -> V_232 -> V_229 , V_221 ) ;
if ( F_51 ( V_159 -> V_402 . V_209 ) )
goto V_432;
V_159 -> V_402 . V_188 = 0 ;
V_159 -> V_402 . V_248 = V_14 -> V_433 ;
V_159 -> V_56 . V_399 = & V_159 -> V_399 ;
V_159 -> V_56 . V_209 = V_159 -> V_402 . V_209 ;
V_159 -> V_56 . V_14 = V_14 ;
V_159 -> V_419 = F_264 ( V_65 -> V_2 ) ;
F_97 ( V_159 -> V_2 -> V_418 ) ;
V_166 . V_321 = & V_159 -> V_402 ;
V_166 . V_322 = & V_159 -> V_56 ;
V_324 . V_173 = V_159 ;
V_103 = F_77 ( & V_324 ) ;
if ( F_51 ( V_103 ) )
return F_78 ( V_103 ) ;
V_313 = 0 ;
if ( V_429 )
V_313 = F_117 ( V_103 ) ;
F_79 ( V_103 ) ;
return V_313 ;
V_432:
F_105 ( V_159 ) ;
V_136:
F_110 ( V_65 ) ;
F_111 ( V_218 ) ;
return V_313 ;
}
static struct V_2 *
F_268 ( struct V_2 * V_3 , struct V_307 * V_308 ,
int V_234 , struct V_5 * V_434 , int * V_385 )
{
struct V_64 * V_65 ;
struct V_1 V_17 = { 0 , 0 , 0 , NULL } , * V_7 = NULL ;
V_7 = F_1 ( V_3 , V_308 -> V_4 , V_434 , & V_17 ) ;
V_65 = F_245 ( V_3 , V_308 , V_234 , V_434 , V_7 , V_385 ) ;
F_4 ( V_7 ) ;
if ( F_51 ( V_65 ) )
return F_269 ( V_65 ) ;
return V_65 -> V_2 ;
}
static void F_270 ( struct V_307 * V_308 , int V_435 )
{
if ( V_308 -> V_65 == NULL )
return;
if ( V_435 )
F_271 ( V_308 -> V_65 , V_308 -> V_265 ) ;
else
F_173 ( V_308 -> V_65 , V_308 -> V_265 ) ;
}
static int F_272 ( struct V_13 * V_14 , struct V_436 * V_437 )
{
T_1 V_248 [ 3 ] = {} , V_438 = V_14 -> V_62 -> V_439 ;
struct V_440 args = {
. V_437 = V_437 ,
. V_248 = V_248 ,
} ;
struct V_441 V_56 = {} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_442 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
int V_313 ;
V_248 [ 0 ] = V_443 |
V_444 |
V_445 |
V_446 |
V_447 ;
if ( V_438 )
V_248 [ 2 ] = V_448 ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
if ( V_313 == 0 ) {
switch ( V_438 ) {
case 0 :
V_56 . V_15 [ 1 ] &= V_449 ;
V_56 . V_15 [ 2 ] = 0 ;
break;
case 1 :
V_56 . V_15 [ 2 ] &= V_450 ;
break;
case 2 :
V_56 . V_15 [ 2 ] &= V_451 ;
}
memcpy ( V_14 -> V_15 , V_56 . V_15 , sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_94 &= ~ ( V_452 | V_453 |
V_454 | V_455 |
V_456 | V_457 | V_458 |
V_459 | V_460 |
V_461 | V_462 |
V_9 ) ;
if ( V_56 . V_15 [ 0 ] & V_463 &&
V_56 . V_464 & V_465 )
V_14 -> V_94 |= V_452 ;
if ( V_56 . V_466 != 0 )
V_14 -> V_94 |= V_453 ;
if ( V_56 . V_467 != 0 )
V_14 -> V_94 |= V_454 ;
if ( V_56 . V_15 [ 0 ] & V_45 )
V_14 -> V_94 |= V_455 ;
if ( V_56 . V_15 [ 1 ] & V_378 )
V_14 -> V_94 |= V_456 ;
if ( V_56 . V_15 [ 1 ] & V_468 )
V_14 -> V_94 |= V_457 ;
if ( V_56 . V_15 [ 1 ] & V_469 )
V_14 -> V_94 |= V_458 ;
if ( V_56 . V_15 [ 1 ] & V_470 )
V_14 -> V_94 |= V_459 ;
if ( V_56 . V_15 [ 1 ] & V_372 )
V_14 -> V_94 |= V_460 ;
if ( V_56 . V_15 [ 1 ] & V_471 )
V_14 -> V_94 |= V_461 ;
if ( V_56 . V_15 [ 1 ] & V_375 )
V_14 -> V_94 |= V_462 ;
#ifdef F_273
if ( V_56 . V_15 [ 2 ] & V_380 )
V_14 -> V_94 |= V_9 ;
#endif
memcpy ( V_14 -> V_16 , V_56 . V_15 ,
sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_16 [ 2 ] &= ~ V_380 ;
memcpy ( V_14 -> V_433 , V_56 . V_15 , sizeof( V_14 -> V_433 ) ) ;
V_14 -> V_433 [ 0 ] &= V_472 | V_473 ;
V_14 -> V_433 [ 1 ] &= V_471 | V_375 ;
V_14 -> V_433 [ 2 ] = 0 ;
memcpy ( V_14 -> V_474 , V_56 . V_474 ,
sizeof( V_14 -> V_474 ) ) ;
V_14 -> V_464 = V_56 . V_464 ;
V_14 -> V_475 = V_56 . V_475 ;
}
return V_313 ;
}
int F_274 ( struct V_13 * V_14 , struct V_436 * V_437 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_31 ( V_14 ,
F_272 ( V_14 , V_437 ) ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_275 ( struct V_13 * V_14 , struct V_436 * V_437 ,
struct V_476 * V_477 )
{
T_1 V_248 [ 3 ] ;
struct V_478 args = {
. V_248 = V_248 ,
} ;
struct V_479 V_56 = {
. V_14 = V_14 ,
. V_399 = V_477 -> V_399 ,
. V_251 = V_437 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_480 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
V_248 [ 0 ] = V_250 [ 0 ] ;
V_248 [ 1 ] = V_250 [ 1 ] ;
V_248 [ 2 ] = V_250 [ 2 ] & ~ V_380 ;
F_90 ( V_477 -> V_399 ) ;
return F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
}
static int F_276 ( struct V_13 * V_14 , struct V_436 * V_437 ,
struct V_476 * V_477 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_275 ( V_14 , V_437 , V_477 ) ;
F_277 ( V_14 , V_437 , V_477 -> V_399 , V_8 ) ;
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
static int F_278 ( struct V_13 * V_14 , struct V_436 * V_437 ,
struct V_476 * V_477 , T_4 V_109 )
{
struct V_481 V_482 = {
. V_483 = V_109 ,
} ;
struct V_484 * V_485 ;
int V_51 ;
V_485 = F_279 ( & V_482 , V_14 -> V_98 ) ;
if ( F_51 ( V_485 ) ) {
V_51 = - V_29 ;
goto V_136;
}
V_51 = F_276 ( V_14 , V_437 , V_477 ) ;
V_136:
return V_51 ;
}
static int F_280 ( struct V_13 * V_14 , struct V_436 * V_437 ,
struct V_476 * V_477 )
{
static const T_4 V_486 [] = {
V_114 ,
V_113 ,
V_487 ,
V_488 ,
V_489 ,
} ;
int V_313 = - V_24 ;
T_9 V_490 ;
if ( V_14 -> V_491 . V_492 > 0 ) {
for ( V_490 = 0 ; V_490 < V_14 -> V_491 . V_492 ; V_490 ++ ) {
V_313 = F_278 ( V_14 , V_437 , V_477 ,
V_14 -> V_491 . V_493 [ V_490 ] ) ;
if ( V_313 == - V_22 || V_313 == - V_29 )
continue;
break;
}
} else {
for ( V_490 = 0 ; V_490 < F_281 ( V_486 ) ; V_490 ++ ) {
V_313 = F_278 ( V_14 , V_437 , V_477 ,
V_486 [ V_490 ] ) ;
if ( V_313 == - V_22 || V_313 == - V_29 )
continue;
break;
}
}
if ( V_313 == - V_29 )
V_313 = - V_24 ;
return V_313 ;
}
static int F_282 ( struct V_13 * V_14 ,
struct V_436 * V_437 , struct V_476 * V_477 )
{
int V_494 = V_14 -> V_62 -> V_439 ;
return V_495 [ V_494 ] -> F_283 ( V_14 , V_437 , V_477 ) ;
}
int F_284 ( struct V_13 * V_14 , struct V_436 * V_437 ,
struct V_476 * V_477 ,
bool V_496 )
{
int V_313 = 0 ;
if ( ! V_496 )
V_313 = F_276 ( V_14 , V_437 , V_477 ) ;
if ( V_496 || V_313 == V_22 )
V_313 = F_282 ( V_14 , V_437 , V_477 ) ;
if ( V_313 == 0 )
V_313 = F_274 ( V_14 , V_437 ) ;
if ( V_313 == 0 )
V_313 = F_285 ( V_14 , V_437 , V_477 ) ;
return F_7 ( V_313 ) ;
}
static int F_286 ( struct V_13 * V_14 , struct V_436 * V_497 ,
struct V_476 * V_477 )
{
int error ;
struct V_398 * V_399 = V_477 -> V_399 ;
struct V_1 * V_7 = NULL ;
error = F_274 ( V_14 , V_497 ) ;
if ( error < 0 ) {
F_8 ( L_32 , - error ) ;
return error ;
}
V_7 = F_96 ( V_14 , V_390 ) ;
if ( F_51 ( V_7 ) )
return F_78 ( V_7 ) ;
error = F_204 ( V_14 , V_497 , V_399 , V_7 ) ;
if ( error < 0 ) {
F_8 ( L_33 , - error ) ;
goto V_230;
}
if ( V_399 -> V_304 & V_498 &&
! F_287 ( & V_14 -> V_499 , & V_399 -> V_499 ) )
memcpy ( & V_14 -> V_499 , & V_399 -> V_499 , sizeof( V_14 -> V_499 ) ) ;
V_230:
F_104 ( V_7 ) ;
return error ;
}
static int F_288 ( struct V_54 * V_98 , struct V_2 * V_3 ,
const struct V_500 * V_247 , struct V_398 * V_399 ,
struct V_436 * V_437 )
{
int V_313 = - V_132 ;
struct V_501 * V_501 = NULL ;
struct V_502 * V_503 = NULL ;
V_501 = F_289 ( V_390 ) ;
if ( V_501 == NULL )
goto V_136;
V_503 = F_290 ( sizeof( struct V_502 ) , V_390 ) ;
if ( V_503 == NULL )
goto V_136;
V_313 = F_291 ( V_98 , V_3 , V_247 , V_503 , V_501 ) ;
if ( V_313 != 0 )
goto V_136;
if ( F_287 ( & F_94 ( V_3 ) -> V_499 , & V_503 -> V_399 . V_499 ) ) {
F_8 ( L_34
L_35 , V_34 , V_247 -> V_247 ) ;
V_313 = - V_77 ;
goto V_136;
}
F_292 ( & V_503 -> V_399 ) ;
memcpy ( V_399 , & V_503 -> V_399 , sizeof( struct V_398 ) ) ;
memset ( V_437 , 0 , sizeof( struct V_436 ) ) ;
V_136:
if ( V_501 )
F_293 ( V_501 ) ;
F_105 ( V_503 ) ;
return V_313 ;
}
static int F_294 ( struct V_13 * V_14 , struct V_436 * V_437 ,
struct V_398 * V_399 , struct V_1 * V_7 )
{
struct V_504 args = {
. V_251 = V_437 ,
. V_248 = V_14 -> V_15 ,
} ;
struct V_505 V_56 = {
. V_399 = V_399 ,
. V_7 = V_7 ,
. V_14 = V_14 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_506 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
args . V_248 = F_6 ( V_14 , V_7 ) ;
F_90 ( V_399 ) ;
return F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
}
static int F_204 ( struct V_13 * V_14 , struct V_436 * V_437 ,
struct V_398 * V_399 , struct V_1 * V_7 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_294 ( V_14 , V_437 , V_399 , V_7 ) ;
F_295 ( V_14 , V_437 , V_399 , V_8 ) ;
V_8 = F_31 ( V_14 , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int
F_296 ( struct V_4 * V_4 , struct V_398 * V_399 ,
struct V_5 * V_6 )
{
struct V_2 * V_2 = F_14 ( V_4 ) ;
struct V_323 * V_357 = NULL ;
struct V_64 * V_65 = NULL ;
struct V_1 * V_7 = NULL ;
int V_313 ;
if ( F_297 ( V_2 ) &&
V_6 -> V_253 & V_407 &&
V_6 -> V_507 < F_298 ( V_2 ) )
F_299 ( V_2 ) ;
F_90 ( V_399 ) ;
if ( V_6 -> V_253 & V_416 )
V_6 -> V_253 &= ~ ( V_377 | V_508 ) ;
if ( ( V_6 -> V_253 & ~ ( V_509 | V_416 ) ) == 0 )
return 0 ;
if ( V_6 -> V_253 & V_509 ) {
struct V_307 * V_308 ;
V_308 = F_300 ( V_6 -> V_510 ) ;
if ( V_308 ) {
V_357 = V_308 -> V_357 ;
V_65 = V_308 -> V_65 ;
}
}
V_7 = F_96 ( F_94 ( V_2 ) , V_390 ) ;
if ( F_51 ( V_7 ) )
return F_78 ( V_7 ) ;
V_313 = F_241 ( V_2 , V_357 , V_399 , V_6 , V_65 , NULL , V_7 ) ;
if ( V_313 == 0 ) {
F_242 ( V_2 , V_6 , V_399 ) ;
F_243 ( V_2 , V_399 , V_7 ) ;
}
F_104 ( V_7 ) ;
return V_313 ;
}
static int F_301 ( struct V_54 * V_55 , struct V_2 * V_3 ,
const struct V_500 * V_247 , struct V_436 * V_437 ,
struct V_398 * V_399 , struct V_1 * V_7 )
{
struct V_13 * V_14 = F_94 ( V_3 ) ;
int V_313 ;
struct V_511 args = {
. V_248 = V_14 -> V_15 ,
. V_512 = F_102 ( V_3 ) ,
. V_247 = V_247 ,
} ;
struct V_479 V_56 = {
. V_14 = V_14 ,
. V_399 = V_399 ,
. V_7 = V_7 ,
. V_251 = V_437 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_513 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
args . V_248 = F_6 ( V_14 , V_7 ) ;
F_90 ( V_399 ) ;
F_8 ( L_36 , V_247 -> V_247 ) ;
V_313 = F_80 ( V_55 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
F_8 ( L_37 , V_313 ) ;
return V_313 ;
}
static void F_302 ( struct V_398 * V_399 )
{
V_399 -> V_304 |= V_342 | V_514 |
V_515 | V_516 ;
V_399 -> V_265 = V_347 | V_517 | V_518 ;
V_399 -> V_519 = 2 ;
}
static int F_303 ( struct V_54 * * V_55 , struct V_2 * V_3 ,
struct V_500 * V_247 , struct V_436 * V_437 ,
struct V_398 * V_399 , struct V_1 * V_7 )
{
struct V_60 V_61 = { } ;
struct V_54 * V_98 = * V_55 ;
int V_8 ;
do {
V_8 = F_301 ( V_98 , V_3 , V_247 , V_437 , V_399 , V_7 ) ;
F_304 ( V_3 , V_247 , V_8 ) ;
switch ( V_8 ) {
case - V_26 :
V_8 = - V_309 ;
goto V_136;
case - V_77 :
V_8 = F_288 ( V_98 , V_3 , V_247 , V_399 , V_437 ) ;
if ( V_8 == - V_77 )
V_8 = F_31 ( F_94 ( V_3 ) , V_8 , & V_61 ) ;
goto V_136;
case - V_22 :
V_8 = - V_24 ;
if ( V_98 != * V_55 )
goto V_136;
V_98 = F_305 ( V_98 , V_3 , V_247 ) ;
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
F_306 ( V_98 ) ;
return V_8 ;
}
static int F_307 ( struct V_2 * V_3 , struct V_500 * V_247 ,
struct V_436 * V_437 , struct V_398 * V_399 ,
struct V_1 * V_7 )
{
int V_313 ;
struct V_54 * V_98 = F_308 ( V_3 ) ;
V_313 = F_303 ( & V_98 , V_3 , V_247 , V_437 , V_399 , V_7 ) ;
if ( V_98 != F_308 ( V_3 ) ) {
F_306 ( V_98 ) ;
F_302 ( V_399 ) ;
}
return V_313 ;
}
struct V_54 *
F_309 ( struct V_2 * V_3 , struct V_500 * V_247 ,
struct V_436 * V_437 , struct V_398 * V_399 )
{
struct V_54 * V_98 = F_308 ( V_3 ) ;
int V_313 ;
V_313 = F_303 ( & V_98 , V_3 , V_247 , V_437 , V_399 , NULL ) ;
if ( V_313 < 0 )
return F_52 ( V_313 ) ;
return ( V_98 == F_308 ( V_3 ) ) ? F_310 ( V_98 ) : V_98 ;
}
static int F_311 ( struct V_2 * V_2 , struct V_358 * V_520 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_521 args = {
. V_251 = F_102 ( V_2 ) ,
. V_248 = V_14 -> V_433 ,
} ;
struct V_522 V_56 = {
. V_14 = V_14 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_523 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_520 -> V_357 ,
} ;
int V_265 = V_520 -> V_360 ;
int V_313 = 0 ;
if ( V_265 & V_365 )
args . V_214 |= V_237 ;
if ( F_312 ( V_2 -> V_524 ) ) {
if ( V_265 & V_525 )
args . V_214 |= V_238 | V_239 | V_526 ;
if ( V_265 & V_363 )
args . V_214 |= V_527 ;
} else {
if ( V_265 & V_525 )
args . V_214 |= V_238 | V_239 ;
if ( V_265 & V_363 )
args . V_214 |= V_240 ;
}
V_56 . V_399 = F_313 () ;
if ( V_56 . V_399 == NULL )
return - V_132 ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
if ( ! V_313 ) {
F_201 ( V_520 , V_56 . V_214 ) ;
F_159 ( V_2 , V_56 . V_399 ) ;
}
F_314 ( V_56 . V_399 ) ;
return V_313 ;
}
static int F_315 ( struct V_2 * V_2 , struct V_358 * V_520 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_311 ( V_2 , V_520 ) ;
F_316 ( V_2 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_317 ( struct V_2 * V_2 , struct V_501 * V_501 ,
unsigned int V_48 , unsigned int V_528 )
{
struct V_529 args = {
. V_251 = F_102 ( V_2 ) ,
. V_48 = V_48 ,
. V_528 = V_528 ,
. V_42 = & V_501 ,
} ;
struct V_530 V_56 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_531 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
return F_80 ( F_94 ( V_2 ) -> V_98 , F_94 ( V_2 ) , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
}
static int F_318 ( struct V_2 * V_2 , struct V_501 * V_501 ,
unsigned int V_48 , unsigned int V_528 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_317 ( V_2 , V_501 , V_48 , V_528 ) ;
F_319 ( V_2 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int
F_320 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_5 * V_6 ,
int V_219 )
{
struct V_1 V_17 , * V_400 = NULL ;
struct V_307 * V_308 ;
struct V_64 * V_65 ;
int V_313 = 0 ;
V_308 = F_321 ( V_4 , V_190 ) ;
if ( F_51 ( V_308 ) )
return F_78 ( V_308 ) ;
V_400 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_322 () ;
V_65 = F_245 ( V_3 , V_308 , V_219 , V_6 , V_400 , NULL ) ;
if ( F_51 ( V_65 ) ) {
V_313 = F_78 ( V_65 ) ;
goto V_136;
}
V_136:
F_4 ( V_400 ) ;
F_180 ( V_308 ) ;
return V_313 ;
}
static int F_323 ( struct V_2 * V_3 , struct V_500 * V_247 )
{
struct V_13 * V_14 = F_94 ( V_3 ) ;
struct V_532 args = {
. V_251 = F_102 ( V_3 ) ,
. V_247 = * V_247 ,
} ;
struct V_533 V_56 = {
. V_14 = V_14 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_534 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
int V_313 ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 1 ) ;
if ( V_313 == 0 )
F_81 ( V_3 , & V_56 . V_175 ) ;
return V_313 ;
}
static int F_324 ( struct V_2 * V_3 , struct V_500 * V_247 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_323 ( V_3 , V_247 ) ;
F_325 ( V_3 , V_247 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static void F_326 ( struct V_165 * V_166 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_94 ( V_3 ) ;
struct V_532 * args = V_166 -> V_321 ;
struct V_533 * V_56 = V_166 -> V_322 ;
V_56 -> V_14 = V_14 ;
V_166 -> V_318 = & V_319 [ V_534 ] ;
F_46 ( & args -> V_163 , & V_56 -> V_164 , 1 ) ;
F_90 ( V_56 -> V_535 ) ;
}
static void F_327 ( struct V_102 * V_103 , struct V_536 * V_161 )
{
F_70 ( F_94 ( V_161 -> V_3 ) ,
& V_161 -> args . V_163 ,
& V_161 -> V_56 . V_164 ,
V_103 ) ;
}
static int F_328 ( struct V_102 * V_103 , struct V_2 * V_3 )
{
struct V_536 * V_161 = V_103 -> V_537 ;
struct V_533 * V_56 = & V_161 -> V_56 ;
if ( ! F_67 ( V_103 , & V_56 -> V_164 ) )
return 0 ;
if ( F_38 ( V_103 , V_56 -> V_14 , NULL ,
& V_161 -> V_50 ) == - V_108 )
return 0 ;
F_81 ( V_3 , & V_56 -> V_175 ) ;
return 1 ;
}
static void F_329 ( struct V_165 * V_166 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_94 ( V_3 ) ;
struct V_538 * V_402 = V_166 -> V_321 ;
struct V_539 * V_56 = V_166 -> V_322 ;
V_166 -> V_318 = & V_319 [ V_540 ] ;
V_56 -> V_14 = V_14 ;
F_46 ( & V_402 -> V_163 , & V_56 -> V_164 , 1 ) ;
}
static void F_330 ( struct V_102 * V_103 , struct V_541 * V_161 )
{
F_70 ( F_94 ( V_161 -> V_542 ) ,
& V_161 -> args . V_163 ,
& V_161 -> V_56 . V_164 ,
V_103 ) ;
}
static int F_331 ( struct V_102 * V_103 , struct V_2 * V_542 ,
struct V_2 * V_543 )
{
struct V_541 * V_161 = V_103 -> V_537 ;
struct V_539 * V_56 = & V_161 -> V_56 ;
if ( ! F_67 ( V_103 , & V_56 -> V_164 ) )
return 0 ;
if ( F_38 ( V_103 , V_56 -> V_14 , NULL , & V_161 -> V_50 ) == - V_108 )
return 0 ;
F_81 ( V_542 , & V_56 -> V_544 ) ;
F_81 ( V_543 , & V_56 -> V_545 ) ;
return 1 ;
}
static int F_332 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_500 * V_247 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_546 V_402 = {
. V_251 = F_102 ( V_2 ) ,
. V_512 = F_102 ( V_3 ) ,
. V_247 = V_247 ,
. V_248 = V_14 -> V_15 ,
} ;
struct V_547 V_56 = {
. V_14 = V_14 ,
. V_7 = NULL ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_548 ] ,
. V_321 = & V_402 ,
. V_322 = & V_56 ,
} ;
int V_313 = - V_132 ;
V_56 . V_399 = F_313 () ;
if ( V_56 . V_399 == NULL )
goto V_136;
V_56 . V_7 = F_96 ( V_14 , V_390 ) ;
if ( F_51 ( V_56 . V_7 ) ) {
V_313 = F_78 ( V_56 . V_7 ) ;
goto V_136;
}
V_402 . V_248 = F_6 ( V_14 , V_56 . V_7 ) ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & V_402 . V_163 , & V_56 . V_164 , 1 ) ;
if ( ! V_313 ) {
F_81 ( V_3 , & V_56 . V_175 ) ;
V_313 = F_333 ( V_2 , V_56 . V_399 ) ;
if ( ! V_313 )
F_243 ( V_2 , V_56 . V_399 , V_56 . V_7 ) ;
}
F_104 ( V_56 . V_7 ) ;
V_136:
F_314 ( V_56 . V_399 ) ;
return V_313 ;
}
static int F_334 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_500 * V_247 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_31 ( F_94 ( V_2 ) ,
F_332 ( V_2 , V_3 , V_247 ) ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static struct V_549 * F_335 ( struct V_2 * V_3 ,
struct V_500 * V_247 , struct V_5 * V_6 , T_1 V_550 )
{
struct V_549 * V_161 ;
V_161 = F_95 ( sizeof( * V_161 ) , V_390 ) ;
if ( V_161 != NULL ) {
struct V_13 * V_14 = F_94 ( V_3 ) ;
V_161 -> V_7 = F_96 ( V_14 , V_390 ) ;
if ( F_51 ( V_161 -> V_7 ) )
goto V_317;
V_161 -> V_166 . V_318 = & V_319 [ V_551 ] ;
V_161 -> V_166 . V_321 = & V_161 -> V_402 ;
V_161 -> V_166 . V_322 = & V_161 -> V_56 ;
V_161 -> V_402 . V_512 = F_102 ( V_3 ) ;
V_161 -> V_402 . V_14 = V_14 ;
V_161 -> V_402 . V_247 = V_247 ;
V_161 -> V_402 . V_220 = V_6 ;
V_161 -> V_402 . V_550 = V_550 ;
V_161 -> V_402 . V_248 = F_6 ( V_14 , V_161 -> V_7 ) ;
V_161 -> V_56 . V_14 = V_14 ;
V_161 -> V_56 . V_251 = & V_161 -> V_251 ;
V_161 -> V_56 . V_399 = & V_161 -> V_399 ;
V_161 -> V_56 . V_7 = V_161 -> V_7 ;
F_90 ( V_161 -> V_56 . V_399 ) ;
}
return V_161 ;
V_317:
F_105 ( V_161 ) ;
return NULL ;
}
static int F_336 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_549 * V_161 )
{
int V_313 = F_80 ( F_94 ( V_3 ) -> V_98 , F_94 ( V_3 ) , & V_161 -> V_166 ,
& V_161 -> V_402 . V_163 , & V_161 -> V_56 . V_164 , 1 ) ;
if ( V_313 == 0 ) {
F_81 ( V_3 , & V_161 -> V_56 . V_552 ) ;
V_313 = F_337 ( V_4 , V_161 -> V_56 . V_251 , V_161 -> V_56 . V_399 , V_161 -> V_56 . V_7 ) ;
}
return V_313 ;
}
static void F_338 ( struct V_549 * V_161 )
{
F_104 ( V_161 -> V_7 ) ;
F_105 ( V_161 ) ;
}
static int F_339 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_501 * V_501 , unsigned int V_12 , struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_549 * V_161 ;
int V_313 = - V_553 ;
if ( V_12 > V_554 )
goto V_136;
V_313 = - V_132 ;
V_161 = F_335 ( V_3 , & V_4 -> V_11 , V_6 , V_555 ) ;
if ( V_161 == NULL )
goto V_136;
V_161 -> V_166 . V_318 = & V_319 [ V_556 ] ;
V_161 -> V_402 . V_255 . V_557 . V_42 = & V_501 ;
V_161 -> V_402 . V_255 . V_557 . V_12 = V_12 ;
V_161 -> V_402 . V_7 = V_7 ;
V_313 = F_336 ( V_3 , V_4 , V_161 ) ;
F_338 ( V_161 ) ;
V_136:
return V_313 ;
}
static int F_340 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_501 * V_501 , unsigned int V_12 , struct V_5 * V_6 )
{
struct V_60 V_61 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
do {
V_8 = F_339 ( V_3 , V_4 , V_501 , V_12 , V_6 , V_7 ) ;
F_341 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_342 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_549 * V_161 ;
int V_313 = - V_132 ;
V_161 = F_335 ( V_3 , & V_4 -> V_11 , V_6 , V_558 ) ;
if ( V_161 == NULL )
goto V_136;
V_161 -> V_402 . V_7 = V_7 ;
V_313 = F_336 ( V_3 , V_4 , V_161 ) ;
F_338 ( V_161 ) ;
V_136:
return V_313 ;
}
static int F_343 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 )
{
struct V_60 V_61 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_322 () ;
do {
V_8 = F_342 ( V_3 , V_4 , V_6 , V_7 ) ;
F_344 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_345 ( struct V_4 * V_4 , struct V_323 * V_357 ,
T_2 V_36 , struct V_501 * * V_42 , unsigned int V_49 , int V_559 )
{
struct V_2 * V_3 = F_14 ( V_4 ) ;
struct V_38 args = {
. V_251 = F_102 ( V_3 ) ,
. V_42 = V_42 ,
. V_48 = 0 ,
. V_49 = V_49 ,
. V_248 = F_94 ( F_14 ( V_4 ) ) -> V_15 ,
. V_559 = V_559 ,
} ;
struct V_560 V_56 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_561 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
int V_313 ;
F_8 ( L_38 , V_34 ,
V_4 ,
( unsigned long long ) V_36 ) ;
F_9 ( V_36 , F_82 ( V_3 ) -> V_562 , V_4 , & args ) ;
V_56 . V_48 = args . V_48 ;
V_313 = F_80 ( F_94 ( V_3 ) -> V_98 , F_94 ( V_3 ) , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
if ( V_313 >= 0 ) {
memcpy ( F_82 ( V_3 ) -> V_562 , V_56 . V_37 . V_161 , V_563 ) ;
V_313 += args . V_48 ;
}
F_346 ( V_3 ) ;
F_8 ( L_39 , V_34 , V_313 ) ;
return V_313 ;
}
static int F_347 ( struct V_4 * V_4 , struct V_323 * V_357 ,
T_2 V_36 , struct V_501 * * V_42 , unsigned int V_49 , int V_559 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_345 ( V_4 , V_357 , V_36 ,
V_42 , V_49 , V_559 ) ;
F_348 ( F_14 ( V_4 ) , V_8 ) ;
V_8 = F_31 ( F_94 ( F_14 ( V_4 ) ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_349 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 , T_10 V_564 )
{
struct V_549 * V_161 ;
int V_265 = V_6 -> V_10 ;
int V_313 = - V_132 ;
V_161 = F_335 ( V_3 , & V_4 -> V_11 , V_6 , V_565 ) ;
if ( V_161 == NULL )
goto V_136;
if ( F_350 ( V_265 ) )
V_161 -> V_402 . V_550 = V_566 ;
else if ( F_351 ( V_265 ) ) {
V_161 -> V_402 . V_550 = V_567 ;
V_161 -> V_402 . V_255 . V_568 . V_569 = F_352 ( V_564 ) ;
V_161 -> V_402 . V_255 . V_568 . V_570 = F_353 ( V_564 ) ;
}
else if ( F_354 ( V_265 ) ) {
V_161 -> V_402 . V_550 = V_571 ;
V_161 -> V_402 . V_255 . V_568 . V_569 = F_352 ( V_564 ) ;
V_161 -> V_402 . V_255 . V_568 . V_570 = F_353 ( V_564 ) ;
} else if ( ! F_355 ( V_265 ) ) {
V_313 = - V_27 ;
goto V_317;
}
V_161 -> V_402 . V_7 = V_7 ;
V_313 = F_336 ( V_3 , V_4 , V_161 ) ;
V_317:
F_338 ( V_161 ) ;
V_136:
return V_313 ;
}
static int F_356 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , T_10 V_564 )
{
struct V_60 V_61 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_322 () ;
do {
V_8 = F_349 ( V_3 , V_4 , V_6 , V_7 , V_564 ) ;
F_357 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_358 ( struct V_13 * V_14 , struct V_436 * V_437 ,
struct V_572 * V_573 )
{
struct V_574 args = {
. V_251 = V_437 ,
. V_248 = V_14 -> V_15 ,
} ;
struct V_575 V_56 = {
. V_573 = V_573 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_576 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
F_90 ( V_573 -> V_399 ) ;
return F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
}
static int F_359 ( struct V_13 * V_14 , struct V_436 * V_437 , struct V_572 * V_573 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_31 ( V_14 ,
F_358 ( V_14 , V_437 , V_573 ) ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_360 ( struct V_13 * V_14 , struct V_436 * V_437 ,
struct V_476 * V_577 )
{
struct V_578 args = {
. V_251 = V_437 ,
. V_248 = V_14 -> V_15 ,
} ;
struct V_579 V_56 = {
. V_577 = V_577 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_580 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
return F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
}
static int F_285 ( struct V_13 * V_14 , struct V_436 * V_437 , struct V_476 * V_577 )
{
struct V_60 V_61 = { } ;
unsigned long V_581 = V_157 ;
int V_8 ;
do {
V_8 = F_360 ( V_14 , V_437 , V_577 ) ;
F_361 ( V_14 , V_437 , V_577 -> V_399 , V_8 ) ;
if ( V_8 == 0 ) {
struct V_62 * V_63 = V_14 -> V_62 ;
F_41 ( & V_63 -> V_116 ) ;
V_63 -> V_582 = V_577 -> V_583 * V_88 ;
V_63 -> V_117 = V_581 ;
F_43 ( & V_63 -> V_116 ) ;
break;
}
V_8 = F_31 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_362 ( struct V_13 * V_14 , struct V_436 * V_437 , struct V_476 * V_577 )
{
int error ;
F_90 ( V_577 -> V_399 ) ;
error = F_285 ( V_14 , V_437 , V_577 ) ;
if ( error == 0 ) {
V_14 -> V_584 = V_577 -> V_585 ;
F_363 ( V_14 , V_437 , V_577 -> V_586 ) ;
}
return error ;
}
static int F_364 ( struct V_13 * V_14 , struct V_436 * V_437 ,
struct V_587 * V_588 )
{
struct V_589 args = {
. V_251 = V_437 ,
. V_248 = V_14 -> V_15 ,
} ;
struct V_590 V_56 = {
. V_588 = V_588 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_591 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
if ( ( args . V_248 [ 0 ] & V_592 [ 0 ] ) == 0 ) {
memset ( V_588 , 0 , sizeof( * V_588 ) ) ;
return 0 ;
}
F_90 ( V_588 -> V_399 ) ;
return F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
}
static int F_365 ( struct V_13 * V_14 , struct V_436 * V_437 ,
struct V_587 * V_588 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_31 ( V_14 ,
F_364 ( V_14 , V_437 , V_588 ) ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
int F_366 ( T_8 * V_257 ,
const struct V_307 * V_308 ,
const struct V_593 * V_594 ,
T_5 V_188 )
{
const struct V_408 * V_409 = NULL ;
if ( V_594 != NULL )
V_409 = & V_594 -> V_409 ;
return F_251 ( V_257 , V_308 -> V_65 , V_188 , V_409 ) ;
}
static bool F_367 ( T_8 * V_257 ,
const struct V_307 * V_308 ,
const struct V_593 * V_594 ,
T_5 V_188 )
{
T_8 V_595 ;
if ( F_366 ( & V_595 , V_308 , V_594 , V_188 ) == - V_35 )
return true ;
return F_146 ( V_257 , & V_595 ) ;
}
static bool F_368 ( int V_8 )
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
void F_369 ( struct V_596 * V_597 )
{
F_346 ( V_597 -> V_2 ) ;
}
static int F_370 ( struct V_102 * V_103 , struct V_596 * V_597 )
{
struct V_13 * V_14 = F_94 ( V_597 -> V_2 ) ;
F_371 ( V_597 , V_103 -> V_107 ) ;
if ( F_38 ( V_103 , V_14 ,
V_597 -> args . V_598 -> V_65 ,
NULL ) == - V_108 ) {
F_65 ( V_103 ) ;
return - V_108 ;
}
F_369 ( V_597 ) ;
if ( V_103 -> V_107 > 0 )
F_44 ( V_14 , V_597 -> V_115 ) ;
return 0 ;
}
static bool F_372 ( struct V_102 * V_103 ,
struct V_599 * args )
{
if ( ! F_368 ( V_103 -> V_107 ) ||
F_367 ( & args -> V_257 ,
args -> V_598 ,
args -> V_600 ,
V_190 ) )
return false ;
F_65 ( V_103 ) ;
return true ;
}
static int F_373 ( struct V_102 * V_103 , struct V_596 * V_597 )
{
F_8 ( L_11 , V_34 ) ;
if ( ! F_67 ( V_103 , & V_597 -> V_56 . V_164 ) )
return - V_108 ;
if ( F_372 ( V_103 , & V_597 -> args ) )
return - V_108 ;
return V_597 -> V_601 ? V_597 -> V_601 ( V_103 , V_597 ) :
F_370 ( V_103 , V_597 ) ;
}
static void F_374 ( struct V_596 * V_597 ,
struct V_165 * V_166 )
{
V_597 -> V_115 = V_157 ;
V_597 -> V_601 = F_370 ;
V_166 -> V_318 = & V_319 [ V_602 ] ;
F_46 ( & V_597 -> args . V_163 , & V_597 -> V_56 . V_164 , 0 ) ;
}
static int F_375 ( struct V_102 * V_103 ,
struct V_596 * V_597 )
{
if ( F_70 ( F_94 ( V_597 -> V_2 ) ,
& V_597 -> args . V_163 ,
& V_597 -> V_56 . V_164 ,
V_103 ) )
return 0 ;
if ( F_366 ( & V_597 -> args . V_257 , V_597 -> args . V_598 ,
V_597 -> args . V_600 ,
V_597 -> V_603 -> V_604 ) == - V_35 )
return - V_35 ;
if ( F_376 ( F_33 ( V_605 , & V_597 -> args . V_598 -> V_219 ) ) )
return - V_35 ;
return 0 ;
}
static int F_377 ( struct V_102 * V_103 ,
struct V_596 * V_597 )
{
struct V_2 * V_2 = V_597 -> V_2 ;
F_378 ( V_597 , V_103 -> V_107 ) ;
if ( F_38 ( V_103 , F_94 ( V_2 ) ,
V_597 -> args . V_598 -> V_65 ,
NULL ) == - V_108 ) {
F_65 ( V_103 ) ;
return - V_108 ;
}
if ( V_103 -> V_107 >= 0 ) {
F_44 ( F_94 ( V_2 ) , V_597 -> V_115 ) ;
F_379 ( V_597 ) ;
}
return 0 ;
}
static bool F_380 ( struct V_102 * V_103 ,
struct V_599 * args )
{
if ( ! F_368 ( V_103 -> V_107 ) ||
F_367 ( & args -> V_257 ,
args -> V_598 ,
args -> V_600 ,
V_191 ) )
return false ;
F_65 ( V_103 ) ;
return true ;
}
static int F_381 ( struct V_102 * V_103 , struct V_596 * V_597 )
{
if ( ! F_67 ( V_103 , & V_597 -> V_56 . V_164 ) )
return - V_108 ;
if ( F_380 ( V_103 , & V_597 -> args ) )
return - V_108 ;
return V_597 -> V_601 ? V_597 -> V_601 ( V_103 , V_597 ) :
F_377 ( V_103 , V_597 ) ;
}
static
bool F_382 ( struct V_596 * V_597 )
{
if ( V_597 -> V_606 != NULL || V_597 -> V_607 != NULL )
return false ;
return F_383 ( V_597 -> V_2 , V_190 ) == 0 ;
}
static void F_384 ( struct V_596 * V_597 ,
struct V_165 * V_166 )
{
struct V_13 * V_14 = F_94 ( V_597 -> V_2 ) ;
if ( ! F_382 ( V_597 ) ) {
V_597 -> args . V_248 = NULL ;
V_597 -> V_56 . V_399 = NULL ;
} else
V_597 -> args . V_248 = V_14 -> V_433 ;
if ( ! V_597 -> V_601 )
V_597 -> V_601 = F_377 ;
V_597 -> V_56 . V_14 = V_14 ;
V_597 -> V_115 = V_157 ;
V_166 -> V_318 = & V_319 [ V_608 ] ;
F_46 ( & V_597 -> args . V_163 , & V_597 -> V_56 . V_164 , 1 ) ;
}
static void F_385 ( struct V_102 * V_103 , struct V_609 * V_161 )
{
F_70 ( F_94 ( V_161 -> V_2 ) ,
& V_161 -> args . V_163 ,
& V_161 -> V_56 . V_164 ,
V_103 ) ;
}
static int F_386 ( struct V_102 * V_103 , struct V_609 * V_161 )
{
struct V_2 * V_2 = V_161 -> V_2 ;
F_387 ( V_161 , V_103 -> V_107 ) ;
if ( F_38 ( V_103 , F_94 ( V_2 ) ,
NULL , NULL ) == - V_108 ) {
F_65 ( V_103 ) ;
return - V_108 ;
}
return 0 ;
}
static int F_388 ( struct V_102 * V_103 , struct V_609 * V_161 )
{
if ( ! F_67 ( V_103 , & V_161 -> V_56 . V_164 ) )
return - V_108 ;
return V_161 -> V_610 ( V_103 , V_161 ) ;
}
static void F_389 ( struct V_609 * V_161 , struct V_165 * V_166 )
{
struct V_13 * V_14 = F_94 ( V_161 -> V_2 ) ;
if ( V_161 -> V_610 == NULL )
V_161 -> V_610 = F_386 ;
V_161 -> V_56 . V_14 = V_14 ;
V_166 -> V_318 = & V_319 [ V_611 ] ;
F_46 ( & V_161 -> args . V_163 , & V_161 -> V_56 . V_164 , 1 ) ;
}
static void F_390 ( void * V_159 )
{
struct V_612 * V_161 = V_159 ;
struct V_62 * V_63 = V_161 -> V_98 ;
if ( F_391 ( & V_63 -> V_613 ) > 1 )
F_392 ( V_63 ) ;
F_393 ( V_63 ) ;
F_105 ( V_161 ) ;
}
static void F_394 ( struct V_102 * V_103 , void * V_159 )
{
struct V_612 * V_161 = V_159 ;
struct V_62 * V_63 = V_161 -> V_98 ;
unsigned long V_115 = V_161 -> V_115 ;
F_395 ( V_63 , V_103 -> V_107 ) ;
switch ( V_103 -> V_107 ) {
case 0 :
break;
case - V_78 :
F_26 ( V_63 ) ;
break;
default:
if ( F_33 ( V_614 , & V_63 -> V_615 ) == 0 )
return;
if ( V_103 -> V_107 != V_616 ) {
F_24 ( V_63 ) ;
return;
}
F_396 ( V_63 ) ;
}
F_40 ( V_63 , V_115 ) ;
}
static int F_397 ( struct V_62 * V_63 , struct V_323 * V_357 , unsigned V_617 )
{
struct V_165 V_166 = {
. V_318 = & V_319 [ V_618 ] ,
. V_321 = V_63 ,
. V_323 = V_357 ,
} ;
struct V_612 * V_161 ;
if ( V_617 == 0 )
return 0 ;
if ( ! F_398 ( & V_63 -> V_613 ) )
return - V_35 ;
V_161 = F_290 ( sizeof( * V_161 ) , V_310 ) ;
if ( V_161 == NULL )
return - V_132 ;
V_161 -> V_98 = V_63 ;
V_161 -> V_115 = V_157 ;
return F_399 ( V_63 -> V_110 , & V_166 , V_619 ,
& V_620 , V_161 ) ;
}
static int F_400 ( struct V_62 * V_63 , struct V_323 * V_357 )
{
struct V_165 V_166 = {
. V_318 = & V_319 [ V_618 ] ,
. V_321 = V_63 ,
. V_323 = V_357 ,
} ;
unsigned long V_581 = V_157 ;
int V_313 ;
V_313 = F_401 ( V_63 -> V_110 , & V_166 , V_619 ) ;
if ( V_313 < 0 )
return V_313 ;
F_40 ( V_63 , V_581 ) ;
return 0 ;
}
static inline int F_402 ( struct V_13 * V_14 )
{
return V_14 -> V_94 & V_452 ;
}
static int F_403 ( const void * V_621 , T_9 V_622 ,
struct V_501 * * V_42 )
{
struct V_501 * V_623 , * * V_624 ;
int V_625 = 0 ;
T_9 V_12 ;
V_624 = V_42 ;
do {
V_12 = F_404 ( T_9 , V_626 , V_622 ) ;
V_623 = F_289 ( V_390 ) ;
if ( V_623 == NULL )
goto V_627;
memcpy ( F_405 ( V_623 ) , V_621 , V_12 ) ;
V_621 += V_12 ;
V_622 -= V_12 ;
* V_42 ++ = V_623 ;
V_625 ++ ;
} while ( V_622 != 0 );
return V_625 ;
V_627:
for(; V_625 > 0 ; V_625 -- )
F_293 ( V_624 [ V_625 - 1 ] ) ;
return - V_132 ;
}
static void F_406 ( struct V_2 * V_2 , struct V_628 * V_629 )
{
struct V_176 * V_177 = F_82 ( V_2 ) ;
F_41 ( & V_2 -> V_178 ) ;
F_105 ( V_177 -> V_630 ) ;
V_177 -> V_630 = V_629 ;
F_43 ( & V_2 -> V_178 ) ;
}
static void F_407 ( struct V_2 * V_2 )
{
F_406 ( V_2 , NULL ) ;
}
static inline T_11 F_408 ( struct V_2 * V_2 , char * V_621 , T_9 V_622 )
{
struct V_176 * V_177 = F_82 ( V_2 ) ;
struct V_628 * V_629 ;
int V_51 = - V_309 ;
F_41 ( & V_2 -> V_178 ) ;
V_629 = V_177 -> V_630 ;
if ( V_629 == NULL )
goto V_136;
if ( V_621 == NULL )
goto V_631;
if ( V_629 -> V_632 == 0 )
goto V_136;
V_51 = - V_633 ;
if ( V_629 -> V_12 > V_622 )
goto V_136;
memcpy ( V_621 , V_629 -> V_161 , V_629 -> V_12 ) ;
V_631:
V_51 = V_629 -> V_12 ;
V_136:
F_43 ( & V_2 -> V_178 ) ;
return V_51 ;
}
static void F_409 ( struct V_2 * V_2 , struct V_501 * * V_42 , T_9 V_48 , T_9 V_634 )
{
struct V_628 * V_629 ;
T_9 V_622 = sizeof( * V_629 ) + V_634 ;
if ( V_622 <= V_626 ) {
V_629 = F_290 ( V_622 , V_390 ) ;
if ( V_629 == NULL )
goto V_136;
V_629 -> V_632 = 1 ;
F_410 ( V_629 -> V_161 , V_42 , V_48 , V_634 ) ;
} else {
V_629 = F_290 ( sizeof( * V_629 ) , V_390 ) ;
if ( V_629 == NULL )
goto V_136;
V_629 -> V_632 = 0 ;
}
V_629 -> V_12 = V_634 ;
V_136:
F_406 ( V_2 , V_629 ) ;
}
static T_11 F_411 ( struct V_2 * V_2 , void * V_621 , T_9 V_622 )
{
struct V_501 * V_42 [ V_635 ] = { NULL , } ;
struct V_636 args = {
. V_251 = F_102 ( V_2 ) ,
. V_637 = V_42 ,
. V_634 = V_622 ,
} ;
struct V_638 V_56 = {
. V_634 = V_622 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_639 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
unsigned int V_640 = F_412 ( V_622 , V_626 ) ;
int V_51 = - V_132 , V_490 ;
if ( V_640 == 0 )
V_640 = 1 ;
if ( V_640 > F_281 ( V_42 ) )
return - V_633 ;
for ( V_490 = 0 ; V_490 < V_640 ; V_490 ++ ) {
V_42 [ V_490 ] = F_289 ( V_390 ) ;
if ( ! V_42 [ V_490 ] )
goto V_317;
}
V_56 . V_641 = F_289 ( V_390 ) ;
if ( ! V_56 . V_641 )
goto V_317;
args . V_634 = V_640 * V_626 ;
F_8 ( L_40 ,
V_34 , V_621 , V_622 , V_640 , args . V_634 ) ;
V_51 = F_80 ( F_94 ( V_2 ) -> V_98 , F_94 ( V_2 ) ,
& V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
if ( V_51 )
goto V_317;
if ( V_56 . V_642 & V_643 ) {
if ( V_621 == NULL )
goto V_644;
V_51 = - V_633 ;
goto V_317;
}
F_409 ( V_2 , V_42 , V_56 . V_645 , V_56 . V_634 ) ;
if ( V_621 ) {
if ( V_56 . V_634 > V_622 ) {
V_51 = - V_633 ;
goto V_317;
}
F_410 ( V_621 , V_42 , V_56 . V_645 , V_56 . V_634 ) ;
}
V_644:
V_51 = V_56 . V_634 ;
V_317:
for ( V_490 = 0 ; V_490 < V_640 ; V_490 ++ )
if ( V_42 [ V_490 ] )
F_293 ( V_42 [ V_490 ] ) ;
if ( V_56 . V_641 )
F_293 ( V_56 . V_641 ) ;
return V_51 ;
}
static T_11 F_413 ( struct V_2 * V_2 , void * V_621 , T_9 V_622 )
{
struct V_60 V_61 = { } ;
T_11 V_51 ;
do {
V_51 = F_411 ( V_2 , V_621 , V_622 ) ;
F_414 ( V_2 , V_51 ) ;
if ( V_51 >= 0 )
break;
V_51 = F_31 ( F_94 ( V_2 ) , V_51 , & V_61 ) ;
} while ( V_61 . V_68 );
return V_51 ;
}
static T_11 F_415 ( struct V_2 * V_2 , void * V_621 , T_9 V_622 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
int V_51 ;
if ( ! F_402 ( V_14 ) )
return - V_646 ;
V_51 = F_416 ( V_14 , V_2 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( F_82 ( V_2 ) -> V_179 & V_647 )
F_417 ( V_2 ) ;
V_51 = F_408 ( V_2 , V_621 , V_622 ) ;
if ( V_51 != - V_309 )
return V_51 ;
return F_413 ( V_2 , V_621 , V_622 ) ;
}
static int F_418 ( struct V_2 * V_2 , const void * V_621 , T_9 V_622 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_501 * V_42 [ V_635 ] ;
struct V_648 V_402 = {
. V_251 = F_102 ( V_2 ) ,
. V_637 = V_42 ,
. V_634 = V_622 ,
} ;
struct V_649 V_56 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_650 ] ,
. V_321 = & V_402 ,
. V_322 = & V_56 ,
} ;
unsigned int V_640 = F_412 ( V_622 , V_626 ) ;
int V_51 , V_490 ;
if ( ! F_402 ( V_14 ) )
return - V_646 ;
if ( V_640 > F_281 ( V_42 ) )
return - V_633 ;
V_490 = F_403 ( V_621 , V_622 , V_402 . V_637 ) ;
if ( V_490 < 0 )
return V_490 ;
F_150 ( V_2 ) ;
V_51 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & V_402 . V_163 , & V_56 . V_164 , 1 ) ;
for (; V_490 > 0 ; V_490 -- )
F_419 ( V_42 [ V_490 - 1 ] ) ;
F_41 ( & V_2 -> V_178 ) ;
F_82 ( V_2 ) -> V_179 |= V_180 ;
F_43 ( & V_2 -> V_178 ) ;
F_420 ( V_2 ) ;
F_417 ( V_2 ) ;
return V_51 ;
}
static int F_421 ( struct V_2 * V_2 , const void * V_621 , T_9 V_622 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_418 ( V_2 , V_621 , V_622 ) ;
F_422 ( V_2 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_423 ( struct V_2 * V_2 , void * V_621 ,
T_9 V_622 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_398 V_399 ;
struct V_1 V_7 = { 0 , 0 , V_622 , V_621 } ;
T_1 V_248 [ 3 ] = { 0 , 0 , V_380 } ;
struct V_504 V_402 = {
. V_251 = F_102 ( V_2 ) ,
. V_248 = V_248 ,
} ;
struct V_505 V_56 = {
. V_399 = & V_399 ,
. V_7 = & V_7 ,
. V_14 = V_14 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_506 ] ,
. V_321 = & V_402 ,
. V_322 = & V_56 ,
} ;
int V_51 ;
F_90 ( & V_399 ) ;
V_51 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & V_402 . V_163 , & V_56 . V_164 , 0 ) ;
if ( V_51 )
return V_51 ;
if ( ! ( V_399 . V_304 & V_651 ) )
return - V_309 ;
if ( V_622 < V_7 . V_12 )
return - V_633 ;
return 0 ;
}
static int F_424 ( struct V_2 * V_2 , void * V_621 ,
T_9 V_622 )
{
struct V_60 V_61 = { } ;
int V_8 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_646 ;
do {
V_8 = F_423 ( V_2 , V_621 , V_622 ) ;
F_425 ( V_2 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_426 ( struct V_2 * V_2 ,
struct V_1 * V_400 ,
struct V_398 * V_399 ,
struct V_1 * V_389 )
{
struct V_5 V_6 = { 0 } ;
struct V_13 * V_14 = F_94 ( V_2 ) ;
const T_1 V_248 [ 3 ] = { 0 , 0 , V_380 } ;
struct V_401 V_402 = {
. V_251 = F_102 ( V_2 ) ,
. V_403 = & V_6 ,
. V_14 = V_14 ,
. V_248 = V_248 ,
. V_7 = V_400 ,
} ;
struct V_404 V_56 = {
. V_399 = V_399 ,
. V_7 = V_389 ,
. V_14 = V_14 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_405 ] ,
. V_321 = & V_402 ,
. V_322 = & V_56 ,
} ;
int V_313 ;
F_136 ( & V_402 . V_257 , & V_415 ) ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & V_402 . V_163 , & V_56 . V_164 , 1 ) ;
if ( V_313 )
F_8 ( L_41 , V_34 , V_313 ) ;
return V_313 ;
}
static int F_427 ( struct V_2 * V_2 ,
struct V_1 * V_400 ,
struct V_398 * V_399 ,
struct V_1 * V_389 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_426 ( V_2 , V_400 ,
V_399 , V_389 ) ;
F_428 ( V_2 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int
F_429 ( struct V_4 * V_4 , const void * V_621 , T_9 V_622 )
{
struct V_1 V_400 , * V_389 = NULL ;
struct V_398 V_399 ;
struct V_323 * V_357 ;
struct V_2 * V_2 = F_14 ( V_4 ) ;
int V_313 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_646 ;
F_90 ( & V_399 ) ;
V_400 . V_652 = 0 ;
V_400 . V_653 = 0 ;
V_400 . V_7 = ( char * ) V_621 ;
V_400 . V_12 = V_622 ;
V_357 = F_430 () ;
if ( F_51 ( V_357 ) )
return F_78 ( V_357 ) ;
V_389 = F_96 ( F_94 ( V_2 ) , V_390 ) ;
if ( F_51 ( V_389 ) ) {
V_313 = - F_78 ( V_389 ) ;
goto V_136;
}
V_313 = F_427 ( V_2 , & V_400 , & V_399 , V_389 ) ;
if ( V_313 == 0 )
F_243 ( V_2 , & V_399 , V_389 ) ;
F_104 ( V_389 ) ;
V_136:
F_222 ( V_357 ) ;
return V_313 ;
}
static void F_431 ( const struct V_62 * V_63 ,
T_12 * V_654 )
{
T_3 V_254 [ 2 ] ;
if ( F_33 ( V_655 , & V_63 -> V_106 ) ) {
V_254 [ 0 ] = 0 ;
V_254 [ 1 ] = F_432 ( V_656 + 1 ) ;
} else {
struct V_657 * V_658 = F_433 ( V_63 -> V_659 , V_660 ) ;
V_254 [ 0 ] = F_432 ( V_658 -> V_661 . V_662 ) ;
V_254 [ 1 ] = F_432 ( V_658 -> V_661 . V_663 ) ;
}
memcpy ( V_654 -> V_161 , V_254 , sizeof( V_654 -> V_161 ) ) ;
}
static int
F_434 ( struct V_62 * V_63 )
{
T_9 V_12 ;
char * V_664 ;
if ( V_63 -> V_665 != NULL )
return 0 ;
F_144 () ;
V_12 = 14 + strlen ( V_63 -> V_666 ) + 1 +
strlen ( F_435 ( V_63 -> V_110 , V_667 ) ) +
1 +
strlen ( F_435 ( V_63 -> V_110 , V_668 ) ) +
1 ;
F_147 () ;
if ( V_12 > V_669 + 1 )
return - V_27 ;
V_664 = F_290 ( V_12 , V_390 ) ;
if ( ! V_664 )
return - V_132 ;
F_144 () ;
F_436 ( V_664 , V_12 , L_42 ,
V_63 -> V_666 ,
F_435 ( V_63 -> V_110 , V_667 ) ,
F_435 ( V_63 -> V_110 , V_668 ) ) ;
F_147 () ;
V_63 -> V_665 = V_664 ;
return 0 ;
}
static int
F_437 ( struct V_62 * V_63 )
{
T_9 V_12 ;
char * V_664 ;
V_12 = 10 + 10 + 1 + 10 + 1 +
strlen ( V_670 ) + 1 +
strlen ( V_63 -> V_110 -> V_671 ) + 1 ;
if ( V_12 > V_669 + 1 )
return - V_27 ;
V_664 = F_290 ( V_12 , V_390 ) ;
if ( ! V_664 )
return - V_132 ;
F_436 ( V_664 , V_12 , L_43 ,
V_63 -> V_672 -> V_673 , V_63 -> V_439 ,
V_670 ,
V_63 -> V_110 -> V_671 ) ;
V_63 -> V_665 = V_664 ;
return 0 ;
}
static int
F_438 ( struct V_62 * V_63 )
{
T_9 V_12 ;
char * V_664 ;
if ( V_63 -> V_665 != NULL )
return 0 ;
if ( V_670 [ 0 ] != '\0' )
return F_437 ( V_63 ) ;
V_12 = 10 + 10 + 1 + 10 + 1 +
strlen ( V_63 -> V_110 -> V_671 ) + 1 ;
if ( V_12 > V_669 + 1 )
return - V_27 ;
V_664 = F_290 ( V_12 , V_390 ) ;
if ( ! V_664 )
return - V_132 ;
F_436 ( V_664 , V_12 , L_44 ,
V_63 -> V_672 -> V_673 , V_63 -> V_439 ,
V_63 -> V_110 -> V_671 ) ;
V_63 -> V_665 = V_664 ;
return 0 ;
}
static unsigned int
F_439 ( const struct V_62 * V_63 , char * V_621 , T_9 V_12 )
{
if ( strchr ( V_63 -> V_666 , ':' ) != NULL )
return F_436 ( V_621 , V_12 , L_45 ) ;
else
return F_436 ( V_621 , V_12 , L_46 ) ;
}
static void F_440 ( struct V_102 * V_103 , void * V_159 )
{
struct V_674 * V_675 = V_159 ;
if ( V_103 -> V_107 == 0 )
V_675 -> V_676 = F_218 ( V_103 -> V_677 -> V_678 ) ;
}
int F_441 ( struct V_62 * V_63 , T_1 V_679 ,
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
. V_219 = V_619 ,
} ;
int V_313 ;
F_431 ( V_63 , & V_682 ) ;
if ( F_33 ( V_688 , & V_63 -> V_689 ) )
V_313 = F_438 ( V_63 ) ;
else
V_313 = F_434 ( V_63 ) ;
if ( V_313 )
goto V_136;
V_683 . V_690 =
F_439 ( V_63 ,
V_683 . V_691 ,
sizeof( V_683 . V_691 ) ) ;
V_683 . V_692 = F_436 ( V_683 . V_693 ,
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
V_63 -> V_696 = F_442 ( V_683 . V_676 ) ;
F_222 ( V_683 . V_676 ) ;
}
F_79 ( V_103 ) ;
V_136:
F_443 ( V_63 , V_313 ) ;
F_8 ( L_49 , V_313 ) ;
return V_313 ;
}
int F_444 ( struct V_62 * V_63 ,
struct V_681 * V_402 ,
struct V_323 * V_357 )
{
struct V_165 V_166 = {
. V_318 = & V_319 [ V_697 ] ,
. V_321 = V_402 ,
. V_323 = V_357 ,
} ;
int V_313 ;
F_8 ( L_50 ,
V_63 -> V_110 -> V_111 -> V_694 -> V_695 ,
V_63 -> V_242 ) ;
V_313 = F_401 ( V_63 -> V_110 , & V_166 , V_619 ) ;
F_445 ( V_63 , V_313 ) ;
F_8 ( L_51 , V_313 ) ;
return V_313 ;
}
static void F_446 ( struct V_102 * V_103 , void * V_159 )
{
struct V_698 * V_161 = V_159 ;
if ( ! F_67 ( V_103 , & V_161 -> V_56 . V_164 ) )
return;
F_447 ( & V_161 -> args , & V_161 -> V_56 , V_103 -> V_107 ) ;
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
if ( V_161 -> V_419 )
F_261 ( V_161 -> V_2 , V_161 -> V_421 ) ;
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
static void F_448 ( void * V_159 )
{
struct V_698 * V_161 = V_159 ;
struct V_2 * V_2 = V_161 -> V_2 ;
if ( V_2 ) {
if ( V_161 -> V_419 )
F_258 ( V_2 ) ;
F_449 ( V_2 ) ;
}
F_105 ( V_159 ) ;
}
static void F_450 ( struct V_102 * V_103 , void * V_161 )
{
struct V_698 * V_699 ;
V_699 = (struct V_698 * ) V_161 ;
if ( F_254 ( V_699 -> V_2 , V_103 ) )
return;
if ( V_699 -> V_419 )
F_263 ( V_699 -> V_2 , & V_699 -> V_421 ) ;
F_70 ( V_699 -> V_56 . V_14 ,
& V_699 -> args . V_163 ,
& V_699 -> V_56 . V_164 ,
V_103 ) ;
}
static int F_451 ( struct V_2 * V_2 , struct V_323 * V_357 , const T_8 * V_257 , int V_700 )
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
F_267 ( V_14 -> V_62 ,
V_431 ,
& V_324 . V_169 , & V_166 ) ;
V_161 -> args . V_437 = & V_161 -> V_251 ;
V_161 -> args . V_257 = & V_161 -> V_257 ;
V_161 -> args . V_248 = V_14 -> V_433 ;
F_194 ( & V_161 -> V_251 , F_102 ( V_2 ) ) ;
F_136 ( & V_161 -> V_257 , V_257 ) ;
V_161 -> V_56 . V_399 = & V_161 -> V_399 ;
V_161 -> V_56 . V_14 = V_14 ;
F_90 ( V_161 -> V_56 . V_399 ) ;
V_161 -> V_115 = V_157 ;
V_161 -> V_301 = 0 ;
V_161 -> V_2 = F_452 ( V_2 ) ;
if ( V_161 -> V_2 )
V_161 -> V_419 = F_264 ( V_2 ) ;
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
F_453 ( V_2 , & V_161 -> V_399 ) ;
else
F_159 ( V_2 , & V_161 -> V_399 ) ;
V_136:
F_79 ( V_103 ) ;
return V_313 ;
}
int F_454 ( struct V_2 * V_2 , struct V_323 * V_357 , const T_8 * V_257 , int V_700 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_451 ( V_2 , V_357 , V_257 , V_700 ) ;
F_455 ( V_2 , V_257 , V_8 ) ;
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
F_456 ( unsigned long V_50 )
{
F_19 ( V_50 ) ;
V_50 <<= 1 ;
if ( V_50 > V_703 )
return V_703 ;
return V_50 ;
}
static int F_457 ( struct V_64 * V_65 , int V_704 , struct V_705 * V_706 )
{
struct V_2 * V_2 = V_65 -> V_2 ;
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_62 * V_63 = V_14 -> V_62 ;
struct V_707 V_402 = {
. V_251 = F_102 ( V_2 ) ,
. V_708 = V_706 ,
} ;
struct V_709 V_56 = {
. V_710 = V_706 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_711 ] ,
. V_321 = & V_402 ,
. V_322 = & V_56 ,
. V_323 = V_65 -> V_232 -> V_298 ,
} ;
struct V_289 * V_290 ;
int V_313 ;
V_402 . V_712 . V_241 = V_63 -> V_242 ;
V_313 = F_458 ( V_65 , V_706 ) ;
if ( V_313 != 0 )
goto V_136;
V_290 = V_706 -> V_713 . V_714 . V_232 ;
V_402 . V_712 . V_243 = V_290 -> V_715 . V_246 ;
V_402 . V_712 . V_716 = V_14 -> V_716 ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & V_402 . V_163 , & V_56 . V_164 , 1 ) ;
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
static int F_459 ( struct V_64 * V_65 , int V_704 , struct V_705 * V_706 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_457 ( V_65 , V_704 , V_706 ) ;
F_460 ( V_706 , V_65 , V_704 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_65 -> V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_461 ( struct V_2 * V_2 , struct V_705 * V_708 )
{
return F_462 ( V_2 , V_708 ) ;
}
static struct V_721 * F_463 ( struct V_705 * V_708 ,
struct V_307 * V_308 ,
struct V_289 * V_290 ,
struct V_223 * V_209 )
{
struct V_721 * V_41 ;
struct V_2 * V_2 = V_290 -> V_291 -> V_2 ;
V_41 = F_95 ( sizeof( * V_41 ) , V_310 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_402 . V_251 = F_102 ( V_2 ) ;
V_41 -> V_402 . V_708 = & V_41 -> V_708 ;
V_41 -> V_402 . V_209 = V_209 ;
V_41 -> V_56 . V_209 = V_209 ;
V_41 -> V_290 = V_290 ;
F_99 ( & V_290 -> V_722 ) ;
V_41 -> V_308 = F_168 ( V_308 ) ;
memcpy ( & V_41 -> V_708 , V_708 , sizeof( V_41 -> V_708 ) ) ;
V_41 -> V_14 = F_94 ( V_2 ) ;
return V_41 ;
}
static void F_464 ( void * V_161 )
{
struct V_721 * V_159 = V_161 ;
F_109 ( V_159 -> V_402 . V_209 ) ;
F_465 ( V_159 -> V_290 ) ;
F_180 ( V_159 -> V_308 ) ;
F_105 ( V_159 ) ;
}
static void F_466 ( struct V_102 * V_103 , void * V_161 )
{
struct V_721 * V_159 = V_161 ;
if ( ! F_67 ( V_103 , & V_159 -> V_56 . V_164 ) )
return;
switch ( V_103 -> V_107 ) {
case 0 :
F_44 ( V_159 -> V_14 , V_159 -> V_115 ) ;
F_461 ( V_159 -> V_290 -> V_291 -> V_2 , & V_159 -> V_708 ) ;
if ( F_148 ( V_159 -> V_290 ,
& V_159 -> V_56 . V_257 ) )
break;
case - V_72 :
case - V_93 :
case - V_75 :
case - V_74 :
if ( ! F_146 ( & V_159 -> V_402 . V_257 ,
& V_159 -> V_290 -> V_293 ) )
F_65 ( V_103 ) ;
break;
default:
if ( F_38 ( V_103 , V_159 -> V_14 ,
NULL , NULL ) == - V_108 )
F_65 ( V_103 ) ;
}
F_152 ( V_159 -> V_402 . V_209 ) ;
}
static void F_467 ( struct V_102 * V_103 , void * V_161 )
{
struct V_721 * V_159 = V_161 ;
if ( F_193 ( V_159 -> V_402 . V_209 , V_103 ) != 0 )
goto V_329;
F_136 ( & V_159 -> V_402 . V_257 , & V_159 -> V_290 -> V_293 ) ;
if ( F_33 ( V_723 , & V_159 -> V_290 -> V_724 ) == 0 ) {
goto V_330;
}
V_159 -> V_115 = V_157 ;
if ( F_70 ( V_159 -> V_14 ,
& V_159 -> V_402 . V_163 ,
& V_159 -> V_56 . V_164 ,
V_103 ) != 0 )
F_152 ( V_159 -> V_402 . V_209 ) ;
return;
V_330:
V_103 -> V_341 = NULL ;
V_329:
F_67 ( V_103 , & V_159 -> V_56 . V_164 ) ;
}
static struct V_102 * F_468 ( struct V_705 * V_708 ,
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
. V_169 = F_308 ( V_290 -> V_291 -> V_2 ) ,
. V_165 = & V_166 ,
. V_170 = & V_726 ,
. V_326 = V_327 ,
. V_219 = V_328 ,
} ;
F_267 ( F_94 ( V_290 -> V_291 -> V_2 ) -> V_62 ,
V_431 , & V_324 . V_169 , & V_166 ) ;
V_708 -> V_717 = V_718 ;
V_161 = F_463 ( V_708 , V_308 , V_290 , V_209 ) ;
if ( V_161 == NULL ) {
F_109 ( V_209 ) ;
return F_52 ( - V_132 ) ;
}
F_46 ( & V_161 -> V_402 . V_163 , & V_161 -> V_56 . V_164 , 1 ) ;
V_166 . V_321 = & V_161 -> V_402 ;
V_166 . V_322 = & V_161 -> V_56 ;
V_324 . V_173 = V_161 ;
return F_77 ( & V_324 ) ;
}
static int F_469 ( struct V_64 * V_65 , int V_704 , struct V_705 * V_706 )
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
V_313 = F_458 ( V_65 , V_706 ) ;
V_706 -> V_727 |= V_728 ;
F_470 ( & V_218 -> V_729 ) ;
F_471 ( & V_177 -> V_730 ) ;
if ( F_461 ( V_2 , V_706 ) == - V_309 ) {
F_472 ( & V_177 -> V_730 ) ;
F_473 ( & V_218 -> V_729 ) ;
goto V_136;
}
F_472 ( & V_177 -> V_730 ) ;
F_473 ( & V_218 -> V_729 ) ;
if ( V_313 != 0 )
goto V_136;
V_290 = V_706 -> V_713 . V_714 . V_232 ;
if ( F_33 ( V_723 , & V_290 -> V_724 ) == 0 )
goto V_136;
V_224 = F_94 ( V_2 ) -> V_62 -> V_171 -> V_224 ;
V_209 = V_224 ( & V_290 -> V_715 , V_390 ) ;
V_313 = - V_132 ;
if ( F_51 ( V_209 ) )
goto V_136;
V_103 = F_468 ( V_706 , F_300 ( V_706 -> V_731 ) , V_290 , V_209 ) ;
V_313 = F_78 ( V_103 ) ;
if ( F_51 ( V_103 ) )
goto V_136;
V_313 = F_116 ( V_103 ) ;
F_79 ( V_103 ) ;
V_136:
V_706 -> V_727 = V_727 ;
F_474 ( V_706 , V_65 , V_732 , V_313 ) ;
return V_313 ;
}
static struct V_733 * F_475 ( struct V_705 * V_708 ,
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
V_41 -> V_402 . V_251 = F_102 ( V_2 ) ;
V_41 -> V_402 . V_708 = & V_41 -> V_708 ;
V_41 -> V_402 . V_734 = F_476 ( & V_290 -> V_291 -> V_232 -> V_229 , V_221 ) ;
if ( F_51 ( V_41 -> V_402 . V_734 ) )
goto V_317;
V_224 = V_14 -> V_62 -> V_171 -> V_224 ;
V_41 -> V_402 . V_735 = V_224 ( & V_290 -> V_715 , V_221 ) ;
if ( F_51 ( V_41 -> V_402 . V_735 ) )
goto V_736;
V_41 -> V_402 . V_712 . V_241 = V_14 -> V_62 -> V_242 ;
V_41 -> V_402 . V_712 . V_243 = V_290 -> V_715 . V_246 ;
V_41 -> V_402 . V_712 . V_716 = V_14 -> V_716 ;
V_41 -> V_56 . V_735 = V_41 -> V_402 . V_735 ;
V_41 -> V_290 = V_290 ;
V_41 -> V_14 = V_14 ;
F_99 ( & V_290 -> V_722 ) ;
V_41 -> V_308 = F_168 ( V_308 ) ;
F_477 ( V_708 -> V_731 ) ;
memcpy ( & V_41 -> V_708 , V_708 , sizeof( V_41 -> V_708 ) ) ;
return V_41 ;
V_736:
F_109 ( V_41 -> V_402 . V_734 ) ;
V_317:
F_105 ( V_41 ) ;
return NULL ;
}
static void F_478 ( struct V_102 * V_103 , void * V_159 )
{
struct V_733 * V_161 = V_159 ;
struct V_64 * V_65 = V_161 -> V_290 -> V_291 ;
F_8 ( L_29 , V_34 ) ;
if ( F_193 ( V_161 -> V_402 . V_735 , V_103 ) != 0 )
goto V_329;
if ( ! F_33 ( V_723 , & V_161 -> V_290 -> V_724 ) ) {
if ( F_193 ( V_161 -> V_402 . V_734 , V_103 ) != 0 ) {
goto V_737;
}
F_136 ( & V_161 -> V_402 . V_278 ,
& V_65 -> V_278 ) ;
V_161 -> V_402 . V_738 = 1 ;
V_161 -> V_56 . V_734 = V_161 -> V_402 . V_734 ;
} else {
V_161 -> V_402 . V_738 = 0 ;
F_136 ( & V_161 -> V_402 . V_739 ,
& V_161 -> V_290 -> V_293 ) ;
}
if ( ! F_250 ( V_65 ) ) {
V_161 -> V_301 = - V_414 ;
V_103 -> V_341 = NULL ;
goto V_740;
}
V_161 -> V_115 = V_157 ;
if ( F_70 ( V_161 -> V_14 ,
& V_161 -> V_402 . V_163 ,
& V_161 -> V_56 . V_164 ,
V_103 ) == 0 )
return;
V_740:
F_152 ( V_161 -> V_402 . V_734 ) ;
V_737:
F_152 ( V_161 -> V_402 . V_735 ) ;
V_329:
F_67 ( V_103 , & V_161 -> V_56 . V_164 ) ;
F_8 ( L_52 , V_34 , V_161 -> V_301 ) ;
}
static void F_479 ( struct V_102 * V_103 , void * V_159 )
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
if ( V_161 -> V_402 . V_741 ) {
V_161 -> V_708 . V_727 &= ~ ( V_742 | V_743 ) ;
if ( F_461 ( V_290 -> V_291 -> V_2 , & V_161 -> V_708 ) < 0 ) {
F_65 ( V_103 ) ;
break;
}
}
if ( V_161 -> V_402 . V_738 != 0 ) {
F_187 ( & V_290 -> V_715 , 0 ) ;
F_136 ( & V_290 -> V_293 , & V_161 -> V_56 . V_257 ) ;
F_133 ( V_723 , & V_290 -> V_724 ) ;
} else if ( ! F_148 ( V_290 , & V_161 -> V_56 . V_257 ) )
F_65 ( V_103 ) ;
break;
case - V_72 :
case - V_93 :
case - V_75 :
case - V_74 :
if ( V_161 -> V_402 . V_738 != 0 ) {
if ( ! F_146 ( & V_161 -> V_402 . V_278 ,
& V_290 -> V_291 -> V_278 ) )
F_65 ( V_103 ) ;
} else if ( ! F_146 ( & V_161 -> V_402 . V_739 ,
& V_290 -> V_293 ) )
F_65 ( V_103 ) ;
}
F_8 ( L_30 , V_34 , V_161 -> V_301 ) ;
}
static void F_480 ( void * V_159 )
{
struct V_733 * V_161 = V_159 ;
F_8 ( L_29 , V_34 ) ;
F_109 ( V_161 -> V_402 . V_734 ) ;
if ( V_161 -> V_316 != 0 ) {
struct V_102 * V_103 ;
V_103 = F_468 ( & V_161 -> V_708 , V_161 -> V_308 , V_161 -> V_290 ,
V_161 -> V_402 . V_735 ) ;
if ( ! F_51 ( V_103 ) )
F_481 ( V_103 ) ;
F_8 ( L_53 , V_34 ) ;
} else
F_109 ( V_161 -> V_402 . V_735 ) ;
F_465 ( V_161 -> V_290 ) ;
F_180 ( V_161 -> V_308 ) ;
F_482 ( V_161 -> V_708 . V_731 ) ;
F_105 ( V_161 ) ;
F_8 ( L_31 , V_34 ) ;
}
static void F_483 ( struct V_13 * V_14 , struct V_289 * V_290 , int V_738 , int error )
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
static int F_484 ( struct V_64 * V_65 , int V_704 , struct V_705 * V_708 , int V_745 )
{
struct V_733 * V_161 ;
struct V_102 * V_103 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_746 ] ,
. V_323 = V_65 -> V_232 -> V_298 ,
} ;
struct V_167 V_324 = {
. V_169 = F_308 ( V_65 -> V_2 ) ,
. V_165 = & V_166 ,
. V_170 = & V_747 ,
. V_326 = V_327 ,
. V_219 = V_328 ,
} ;
int V_51 ;
F_8 ( L_29 , V_34 ) ;
V_161 = F_475 ( V_708 , F_300 ( V_708 -> V_731 ) ,
V_708 -> V_713 . V_714 . V_232 ,
V_745 == V_748 ? V_390 : V_310 ) ;
if ( V_161 == NULL )
return - V_132 ;
if ( F_485 ( V_704 ) )
V_161 -> V_402 . V_749 = 1 ;
F_46 ( & V_161 -> V_402 . V_163 , & V_161 -> V_56 . V_164 , 1 ) ;
V_166 . V_321 = & V_161 -> V_402 ;
V_166 . V_322 = & V_161 -> V_56 ;
V_324 . V_173 = V_161 ;
if ( V_745 > V_748 ) {
if ( V_745 == V_750 )
V_161 -> V_402 . V_751 = V_750 ;
F_47 ( & V_161 -> V_402 . V_163 ) ;
} else
V_161 -> V_402 . V_741 = 1 ;
V_103 = F_77 ( & V_324 ) ;
if ( F_51 ( V_103 ) )
return F_78 ( V_103 ) ;
V_51 = F_116 ( V_103 ) ;
if ( V_51 == 0 ) {
V_51 = V_161 -> V_301 ;
if ( V_51 )
F_483 ( V_161 -> V_14 , V_161 -> V_290 ,
V_161 -> V_402 . V_738 , V_51 ) ;
} else
V_161 -> V_316 = 1 ;
F_79 ( V_103 ) ;
F_8 ( L_30 , V_34 , V_51 ) ;
F_486 ( V_708 , V_65 , & V_161 -> V_56 . V_257 , V_704 , V_51 ) ;
return V_51 ;
}
static int F_487 ( struct V_64 * V_65 , struct V_705 * V_706 )
{
struct V_13 * V_14 = F_94 ( V_65 -> V_2 ) ;
struct V_60 V_61 = {
. V_2 = V_65 -> V_2 ,
} ;
int V_8 ;
do {
if ( F_33 ( V_280 , & V_65 -> V_219 ) != 0 )
return 0 ;
V_8 = F_484 ( V_65 , V_732 , V_706 , V_750 ) ;
if ( V_8 != - V_89 )
break;
F_31 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_488 ( struct V_64 * V_65 , struct V_705 * V_706 )
{
struct V_13 * V_14 = F_94 ( V_65 -> V_2 ) ;
struct V_60 V_61 = {
. V_2 = V_65 -> V_2 ,
} ;
int V_8 ;
V_8 = F_458 ( V_65 , V_706 ) ;
if ( V_8 != 0 )
return V_8 ;
if ( ! V_752 ) {
F_133 ( V_753 , & V_706 -> V_713 . V_714 . V_232 -> V_724 ) ;
return 0 ;
}
do {
if ( F_33 ( V_280 , & V_65 -> V_219 ) != 0 )
return 0 ;
V_8 = F_484 ( V_65 , V_732 , V_706 , V_754 ) ;
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
static int F_489 ( struct V_64 * V_65 )
{
int V_313 , V_51 = - V_72 ;
struct V_289 * V_290 ;
struct V_13 * V_14 = F_94 ( V_65 -> V_2 ) ;
F_167 (lsp, &state->lock_states, ls_locks) {
if ( F_33 ( V_723 , & V_290 -> V_724 ) ) {
struct V_323 * V_357 = V_290 -> V_291 -> V_232 -> V_298 ;
V_313 = F_219 ( V_14 ,
& V_290 -> V_293 ,
V_357 ) ;
F_490 ( V_65 , V_290 , V_313 ) ;
if ( V_313 != V_370 ) {
if ( V_313 != - V_72 )
F_221 ( V_14 ,
& V_290 -> V_293 ,
V_357 ) ;
F_135 ( V_723 , & V_290 -> V_724 ) ;
V_51 = V_313 ;
}
}
} ;
return V_51 ;
}
static int F_491 ( struct V_64 * V_65 , struct V_705 * V_706 )
{
int V_313 = V_370 ;
if ( F_33 ( V_755 , & V_65 -> V_219 ) )
V_313 = F_489 ( V_65 ) ;
if ( V_313 != V_370 )
V_313 = F_488 ( V_65 , V_706 ) ;
return V_313 ;
}
static int F_492 ( struct V_64 * V_65 , int V_704 , struct V_705 * V_706 )
{
struct V_176 * V_177 = F_82 ( V_65 -> V_2 ) ;
unsigned char V_727 = V_706 -> V_727 ;
int V_313 = - V_756 ;
if ( ( V_727 & V_757 ) &&
! F_33 ( V_383 , & V_65 -> V_219 ) )
goto V_136;
V_313 = F_458 ( V_65 , V_706 ) ;
if ( V_313 != 0 )
goto V_136;
V_706 -> V_727 |= V_743 ;
V_313 = F_461 ( V_65 -> V_2 , V_706 ) ;
if ( V_313 < 0 )
goto V_136;
F_471 ( & V_177 -> V_730 ) ;
if ( F_33 ( V_280 , & V_65 -> V_219 ) ) {
V_706 -> V_727 = V_727 & ~ V_742 ;
V_313 = F_461 ( V_65 -> V_2 , V_706 ) ;
F_472 ( & V_177 -> V_730 ) ;
goto V_136;
}
F_472 ( & V_177 -> V_730 ) ;
V_313 = F_484 ( V_65 , V_704 , V_706 , V_748 ) ;
V_136:
V_706 -> V_727 = V_727 ;
return V_313 ;
}
static int F_493 ( struct V_64 * V_65 , int V_704 , struct V_705 * V_706 )
{
struct V_60 V_61 = {
. V_65 = V_65 ,
. V_2 = V_65 -> V_2 ,
} ;
int V_8 ;
do {
V_8 = F_492 ( V_65 , V_704 , V_706 ) ;
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
V_308 = F_300 ( V_759 ) ;
V_65 = V_308 -> V_65 ;
if ( V_706 -> V_761 < 0 || V_706 -> V_762 < 0 )
return - V_27 ;
if ( F_495 ( V_704 ) ) {
if ( V_65 != NULL )
return F_459 ( V_65 , V_763 , V_706 ) ;
return 0 ;
}
if ( ! ( F_496 ( V_704 ) || F_485 ( V_704 ) ) )
return - V_27 ;
if ( V_706 -> V_717 == V_718 ) {
if ( V_65 != NULL )
return F_469 ( V_65 , V_704 , V_706 ) ;
return 0 ;
}
if ( V_65 == NULL )
return - V_756 ;
switch ( V_706 -> V_717 ) {
case V_764 :
if ( ! ( V_759 -> V_765 & V_190 ) )
return - V_414 ;
break;
case V_766 :
if ( ! ( V_759 -> V_765 & V_191 ) )
return - V_414 ;
}
do {
V_313 = F_493 ( V_65 , V_704 , V_706 ) ;
if ( ( V_313 != - V_108 ) || F_496 ( V_704 ) )
break;
V_50 = F_456 ( V_50 ) ;
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
V_8 = F_458 ( V_65 , V_708 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_484 ( V_65 , V_732 , V_708 , V_748 ) ;
return F_181 ( V_14 , V_65 , V_257 , V_8 ) ;
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
V_161 = F_290 ( sizeof( * V_161 ) , V_310 ) ;
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
F_399 ( V_14 -> V_98 , & V_166 , 0 , & V_769 , V_161 ) ;
}
static int F_504 ( const struct V_770 * V_771 ,
struct V_4 * V_4 , const char * V_772 ,
const void * V_621 , T_9 V_622 ,
int V_219 )
{
return F_421 ( F_14 ( V_4 ) , V_621 , V_622 ) ;
}
static int F_505 ( const struct V_770 * V_771 ,
struct V_4 * V_4 , const char * V_772 ,
void * V_621 , T_9 V_622 )
{
return F_415 ( F_14 ( V_4 ) , V_621 , V_622 ) ;
}
static bool F_506 ( struct V_4 * V_4 )
{
return F_402 ( F_94 ( F_14 ( V_4 ) ) ) ;
}
static int F_507 ( const struct V_770 * V_771 ,
struct V_4 * V_4 , const char * V_772 ,
const void * V_621 , T_9 V_622 ,
int V_219 )
{
if ( F_508 ( V_772 ) )
return F_429 ( V_4 , V_621 , V_622 ) ;
return - V_646 ;
}
static int F_509 ( const struct V_770 * V_771 ,
struct V_4 * V_4 , const char * V_772 ,
void * V_621 , T_9 V_622 )
{
if ( F_508 ( V_772 ) )
return F_424 ( F_14 ( V_4 ) , V_621 , V_622 ) ;
return - V_646 ;
}
static T_11
F_510 ( struct V_2 * V_2 , char * V_773 , T_9 V_774 )
{
int V_12 = 0 ;
if ( F_2 ( V_2 , V_9 ) ) {
V_12 = F_511 ( V_2 , V_773 , V_774 ) ;
if ( V_774 && V_12 > V_774 )
return - V_633 ;
}
return V_12 ;
}
static T_11
F_510 ( struct V_2 * V_2 , char * V_773 , T_9 V_774 )
{
return 0 ;
}
static void F_292 ( struct V_398 * V_399 )
{
if ( ! ( ( ( V_399 -> V_304 & V_775 ) ||
( V_399 -> V_304 & V_776 ) ) &&
( V_399 -> V_304 & V_498 ) &&
( V_399 -> V_304 & V_777 ) ) )
return;
V_399 -> V_304 |= V_342 | V_514 |
V_515 | V_778 ;
V_399 -> V_265 = V_347 | V_517 | V_518 ;
V_399 -> V_519 = 2 ;
}
static int F_512 ( struct V_54 * V_98 , struct V_2 * V_3 ,
const struct V_500 * V_247 ,
struct V_502 * V_779 ,
struct V_501 * V_501 )
{
struct V_13 * V_14 = F_94 ( V_3 ) ;
T_1 V_248 [ 3 ] = {
[ 0 ] = V_780 | V_781 ,
} ;
struct V_782 args = {
. V_512 = F_102 ( V_3 ) ,
. V_247 = V_247 ,
. V_501 = V_501 ,
. V_248 = V_248 ,
} ;
struct V_783 V_56 = {
. V_779 = V_779 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_784 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
int V_313 ;
F_8 ( L_54 , V_34 ) ;
if ( F_94 ( V_3 ) -> V_15 [ 1 ] & V_785 )
V_248 [ 1 ] |= V_785 ;
else
V_248 [ 0 ] |= V_45 ;
F_90 ( & V_779 -> V_399 ) ;
V_779 -> V_14 = V_14 ;
V_779 -> V_786 = 0 ;
V_313 = F_80 ( V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
F_8 ( L_55 , V_34 , V_313 ) ;
return V_313 ;
}
int F_291 ( struct V_54 * V_98 , struct V_2 * V_3 ,
const struct V_500 * V_247 ,
struct V_502 * V_779 ,
struct V_501 * V_501 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_512 ( V_98 , V_3 , V_247 ,
V_779 , V_501 ) ;
F_513 ( V_3 , V_247 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_514 ( struct V_2 * V_2 ,
struct V_502 * V_503 ,
struct V_501 * V_501 , struct V_323 * V_357 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_54 * V_55 = V_14 -> V_98 ;
T_1 V_248 [ 2 ] = {
[ 0 ] = V_780 | V_781 ,
} ;
struct V_782 args = {
. V_241 = V_14 -> V_62 -> V_242 ,
. V_251 = F_102 ( V_2 ) ,
. V_501 = V_501 ,
. V_248 = V_248 ,
. V_787 = 1 ,
. V_788 = 1 ,
} ;
struct V_783 V_56 = {
. V_779 = V_503 ,
. V_787 = 1 ,
. V_788 = 1 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_784 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
unsigned long V_581 = V_157 ;
int V_313 ;
F_90 ( & V_503 -> V_399 ) ;
V_503 -> V_14 = V_14 ;
V_503 -> V_786 = 0 ;
F_46 ( & args . V_163 , & V_56 . V_164 , 0 ) ;
F_47 ( & args . V_163 ) ;
V_313 = F_76 ( V_55 , V_14 , & V_166 ,
& args . V_163 , & V_56 . V_164 ) ;
if ( V_313 )
return V_313 ;
F_44 ( V_14 , V_581 ) ;
return 0 ;
}
static int F_515 ( struct V_2 * V_2 ,
struct V_502 * V_503 ,
struct V_501 * V_501 , struct V_323 * V_357 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_54 * V_55 = V_14 -> V_98 ;
T_1 V_248 [ 2 ] = {
[ 0 ] = V_780 | V_781 ,
} ;
struct V_782 args = {
. V_251 = F_102 ( V_2 ) ,
. V_501 = V_501 ,
. V_248 = V_248 ,
. V_787 = 1 ,
} ;
struct V_783 V_56 = {
. V_779 = V_503 ,
. V_787 = 1 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_784 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
int V_313 ;
F_90 ( & V_503 -> V_399 ) ;
V_503 -> V_14 = V_14 ;
V_503 -> V_786 = 0 ;
F_46 ( & args . V_163 , & V_56 . V_164 , 0 ) ;
F_47 ( & args . V_163 ) ;
V_313 = F_76 ( V_55 , V_14 , & V_166 ,
& args . V_163 , & V_56 . V_164 ) ;
if ( V_313 == V_789 &&
V_56 . V_164 . V_150 & V_790 )
V_313 = - V_78 ;
return V_313 ;
}
int F_516 ( struct V_2 * V_2 ,
struct V_502 * V_503 ,
struct V_501 * V_501 , struct V_323 * V_357 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_62 * V_63 = V_14 -> V_62 ;
const struct V_791 * V_792 =
V_63 -> V_171 -> V_793 ;
struct V_60 V_61 = { } ;
int V_313 ;
F_8 ( L_56 , V_34 ,
( unsigned long long ) V_14 -> V_499 . V_794 ,
( unsigned long long ) V_14 -> V_499 . V_795 ,
V_63 -> V_97 ) ;
F_517 ( F_102 ( V_2 ) , V_34 ) ;
do {
V_313 = V_792 -> V_796 ( V_2 , V_503 , V_501 , V_357 ) ;
if ( V_313 != - V_89 )
break;
F_31 ( V_14 , V_313 , & V_61 ) ;
} while ( V_61 . V_68 );
return V_313 ;
}
static int F_518 ( struct V_2 * V_2 , struct V_323 * V_357 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_62 * V_63 = F_94 ( V_2 ) -> V_62 ;
struct V_54 * V_55 = V_14 -> V_98 ;
struct V_797 args = {
. V_251 = F_102 ( V_2 ) ,
. V_241 = V_63 -> V_242 ,
. V_788 = 1 ,
} ;
struct V_798 V_56 = {
. V_788 = 1 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_799 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
unsigned long V_581 = V_157 ;
int V_313 ;
V_56 . V_251 = F_519 () ;
if ( V_56 . V_251 == NULL )
return - V_132 ;
F_46 ( & args . V_163 , & V_56 . V_164 , 0 ) ;
F_47 ( & args . V_163 ) ;
V_313 = F_76 ( V_55 , V_14 , & V_166 ,
& args . V_163 , & V_56 . V_164 ) ;
F_520 ( V_56 . V_251 ) ;
if ( V_313 )
return V_313 ;
F_40 ( V_63 , V_581 ) ;
return 0 ;
}
static int F_521 ( struct V_2 * V_2 , struct V_323 * V_357 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_54 * V_55 = V_14 -> V_98 ;
struct V_797 args = {
. V_251 = F_102 ( V_2 ) ,
} ;
struct V_798 V_56 = {
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_799 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
int V_313 ;
V_56 . V_251 = F_519 () ;
if ( V_56 . V_251 == NULL )
return - V_132 ;
F_46 ( & args . V_163 , & V_56 . V_164 , 0 ) ;
F_47 ( & args . V_163 ) ;
V_313 = F_76 ( V_55 , V_14 , & V_166 ,
& args . V_163 , & V_56 . V_164 ) ;
F_520 ( V_56 . V_251 ) ;
if ( V_313 == V_789 &&
V_56 . V_164 . V_150 & V_790 )
V_313 = - V_78 ;
return V_313 ;
}
int F_522 ( struct V_2 * V_2 , struct V_323 * V_357 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_62 * V_63 = V_14 -> V_62 ;
const struct V_791 * V_792 =
V_63 -> V_171 -> V_793 ;
struct V_60 V_61 = { } ;
int V_313 ;
F_8 ( L_56 , V_34 ,
( unsigned long long ) V_14 -> V_499 . V_794 ,
( unsigned long long ) V_14 -> V_499 . V_795 ,
V_63 -> V_97 ) ;
F_517 ( F_102 ( V_2 ) , V_34 ) ;
do {
V_313 = V_792 -> V_800 ( V_2 , V_357 ) ;
if ( V_313 != - V_89 )
break;
F_31 ( V_14 , V_313 , & V_61 ) ;
} while ( V_61 . V_68 );
return V_313 ;
}
static int F_523 ( struct V_2 * V_3 , const struct V_500 * V_247 , struct V_801 * V_493 , bool V_802 )
{
int V_313 ;
struct V_803 args = {
. V_512 = F_102 ( V_3 ) ,
. V_247 = V_247 ,
} ;
struct V_804 V_56 = {
. V_493 = V_493 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_805 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
struct V_54 * V_55 = F_94 ( V_3 ) -> V_98 ;
struct V_323 * V_357 = NULL ;
if ( V_802 ) {
V_55 = F_94 ( V_3 ) -> V_62 -> V_110 ;
V_357 = F_524 ( F_94 ( V_3 ) -> V_62 ) ;
V_166 . V_323 = V_357 ;
}
F_8 ( L_57 , V_247 -> V_247 ) ;
F_267 ( F_94 ( V_3 ) -> V_62 ,
V_806 , & V_55 , & V_166 ) ;
V_313 = F_80 ( V_55 , F_94 ( V_3 ) , & V_166 , & args . V_163 ,
& V_56 . V_164 , 0 ) ;
F_8 ( L_58 , V_313 ) ;
if ( V_357 )
F_222 ( V_357 ) ;
return V_313 ;
}
int F_525 ( struct V_2 * V_3 , const struct V_500 * V_247 ,
struct V_801 * V_493 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_39 ( F_94 ( V_3 ) -> V_62 ) )
V_8 = F_523 ( V_3 , V_247 , V_493 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_523 ( V_3 , V_247 , V_493 , false ) ;
F_526 ( V_3 , V_247 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_527 ( T_1 V_219 )
{
if ( V_219 & ~ V_807 )
goto V_808;
if ( ( V_219 & V_809 ) &&
( V_219 & V_810 ) )
goto V_808;
if ( ! ( V_219 & ( V_811 ) ) )
goto V_808;
return V_370 ;
V_808:
return - V_812 ;
}
static bool
F_528 ( struct V_813 * V_814 ,
struct V_813 * V_815 )
{
if ( V_814 -> V_816 == V_815 -> V_816 &&
memcmp ( V_814 -> V_817 , V_815 -> V_817 , V_814 -> V_816 ) == 0 )
return true ;
return false ;
}
static void
F_529 ( struct V_102 * V_103 , void * V_159 )
{
}
static
int F_530 ( struct V_54 * V_55 ,
struct V_818 * V_819 ,
struct V_62 * V_63 ,
struct V_323 * V_357 )
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
struct V_167 V_324 = {
. V_169 = V_55 ,
. V_818 = V_819 ,
. V_170 = & V_824 ,
. V_165 = & V_166 ,
. V_219 = V_619 ,
} ;
struct V_102 * V_103 ;
F_8 ( L_11 , V_34 ) ;
F_531 ( & args . V_825 , & V_63 -> V_87 -> V_826 ) ;
if ( ! ( V_63 -> V_87 -> V_219 & V_827 ) )
args . V_3 = V_828 ;
if ( V_819 != F_215 ( V_55 -> V_829 ) )
args . V_3 = V_828 ;
V_103 = F_77 ( & V_324 ) ;
if ( ! F_51 ( V_103 ) ) {
V_313 = V_103 -> V_107 ;
F_79 ( V_103 ) ;
} else
V_313 = F_78 ( V_103 ) ;
F_532 ( V_63 , V_313 ) ;
if ( V_313 == 0 ) {
if ( memcmp ( V_56 . V_825 . V_161 ,
V_63 -> V_87 -> V_826 . V_161 , V_830 ) ) {
F_8 ( L_59 , V_34 ) ;
V_313 = - V_35 ;
goto V_136;
}
if ( ( V_56 . V_3 & args . V_3 ) != V_56 . V_3 || V_56 . V_3 == 0 ) {
F_8 ( L_60 ,
V_34 ) ;
V_313 = - V_35 ;
goto V_136;
}
if ( V_56 . V_831 != args . V_831 ) {
F_8 ( L_61 ,
V_34 ) ;
V_313 = - V_35 ;
goto V_136;
}
}
V_136:
F_8 ( L_62 , V_34 , V_313 ) ;
return V_313 ;
}
static int
F_533 ( struct V_54 * V_55 ,
struct V_818 * V_819 ,
void * V_159 )
{
struct V_832 * V_41 = V_159 ;
return F_530 ( V_55 , V_819 , V_41 -> V_63 , V_41 -> V_357 ) ;
}
int F_534 ( struct V_62 * V_63 , struct V_323 * V_357 )
{
struct V_832 V_161 = {
. V_63 = V_63 ,
. V_357 = V_357 ,
} ;
return F_535 ( V_63 -> V_110 ,
F_533 , & V_161 ) ;
}
static int F_536 ( struct V_62 * V_63 ,
struct V_833 * V_218 )
{
static const T_1 V_834 [ V_835 ] = {
[ 1 ] = 1 << ( V_836 - 32 ) |
1 << ( V_837 - 32 ) |
1 << ( V_838 - 32 ) |
1 << ( V_839 - 32 ) |
1 << ( V_840 - 32 )
} ;
unsigned int V_490 ;
if ( V_218 -> V_841 == V_842 ) {
F_537 ( V_843 , L_63 ) ;
for ( V_490 = 0 ; V_490 <= V_844 ; V_490 ++ ) {
if ( F_33 ( V_490 , V_218 -> V_845 . V_255 . V_846 ) )
F_537 ( V_843 , L_64 , V_490 ) ;
if ( F_33 ( V_490 , V_218 -> V_847 . V_255 . V_846 ) )
F_537 ( V_843 , L_65 , V_490 ) ;
}
for ( V_490 = 0 ; V_490 < V_835 ; V_490 ++ ) {
if ( V_218 -> V_845 . V_255 . V_848 [ V_490 ] & ~ V_834 [ V_490 ] ) {
F_537 ( V_843 , L_66 ) ;
return - V_27 ;
}
}
if ( F_33 ( V_836 , V_218 -> V_845 . V_255 . V_846 ) &&
F_33 ( V_838 , V_218 -> V_845 . V_255 . V_846 ) &&
F_33 ( V_839 , V_218 -> V_845 . V_255 . V_846 ) &&
F_33 ( V_840 , V_218 -> V_845 . V_255 . V_846 ) ) {
F_537 ( V_843 , L_67 ) ;
F_537 ( V_843 , L_68 ) ;
F_133 ( V_849 , & V_63 -> V_850 ) ;
} else {
F_537 ( V_843 , L_66 ) ;
return - V_27 ;
}
if ( F_33 ( V_851 , V_218 -> V_847 . V_255 . V_846 ) &&
F_33 ( V_852 , V_218 -> V_847 . V_255 . V_846 ) &&
F_33 ( V_853 , V_218 -> V_847 . V_255 . V_846 ) &&
F_33 ( V_854 , V_218 -> V_847 . V_255 . V_846 ) ) {
F_537 ( V_843 , L_69 ) ;
F_133 ( V_431 , & V_63 -> V_850 ) ;
}
if ( F_33 ( V_855 , V_218 -> V_847 . V_255 . V_846 ) ) {
F_537 ( V_843 , L_70 ) ;
F_133 ( V_856 ,
& V_63 -> V_850 ) ;
}
if ( F_33 ( V_857 , V_218 -> V_847 . V_255 . V_846 ) &&
F_33 ( V_858 , V_218 -> V_847 . V_255 . V_846 ) ) {
F_537 ( V_843 , L_71 ) ;
F_133 ( V_806 , & V_63 -> V_850 ) ;
}
if ( F_33 ( V_859 , V_218 -> V_847 . V_255 . V_846 ) &&
F_33 ( V_860 , V_218 -> V_847 . V_255 . V_846 ) ) {
F_537 ( V_843 , L_72 ) ;
F_133 ( V_861 , & V_63 -> V_850 ) ;
}
if ( F_33 ( V_862 , V_218 -> V_847 . V_255 . V_846 ) ) {
F_537 ( V_843 , L_73 ) ;
F_133 ( V_863 , & V_63 -> V_850 ) ;
}
if ( F_33 ( V_864 , V_218 -> V_847 . V_255 . V_846 ) ) {
F_537 ( V_843 , L_74 ) ;
F_133 ( V_865 , & V_63 -> V_850 ) ;
}
}
return 0 ;
}
static int F_538 ( struct V_62 * V_63 , struct V_323 * V_357 ,
T_1 V_866 )
{
T_12 V_37 ;
struct V_867 args = {
. V_37 = & V_37 ,
. V_98 = V_63 ,
#ifdef F_539
. V_219 = V_868 |
V_869 |
V_870 ,
#else
. V_219 = V_868 |
V_869 ,
#endif
} ;
struct V_871 V_56 = {
0
} ;
int V_313 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_872 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
F_431 ( V_63 , & V_37 ) ;
V_313 = F_438 ( V_63 ) ;
if ( V_313 )
goto V_136;
F_8 ( L_75 ,
V_63 -> V_110 -> V_111 -> V_694 -> V_695 ,
V_63 -> V_665 ) ;
V_56 . V_873 = F_95 ( sizeof( struct V_874 ) ,
V_310 ) ;
if ( F_376 ( V_56 . V_873 == NULL ) ) {
V_313 = - V_132 ;
goto V_136;
}
V_56 . V_817 = F_95 ( sizeof( struct V_813 ) ,
V_310 ) ;
if ( F_376 ( V_56 . V_817 == NULL ) ) {
V_313 = - V_132 ;
goto V_875;
}
V_56 . V_876 = F_95 ( sizeof( struct V_877 ) , V_310 ) ;
if ( F_376 ( V_56 . V_876 == NULL ) ) {
V_313 = - V_132 ;
goto V_878;
}
switch ( V_866 ) {
case V_879 :
args . V_880 . V_841 = V_879 ;
break;
case V_842 :
args . V_880 = V_881 ;
break;
default:
F_119 ( 1 ) ;
V_313 = - V_27 ;
goto V_882;
}
V_313 = F_401 ( V_63 -> V_110 , & V_166 , V_619 ) ;
F_540 ( V_63 , V_313 ) ;
if ( V_313 == 0 )
V_313 = F_527 ( V_56 . V_219 ) ;
if ( V_313 == 0 )
V_313 = F_536 ( V_63 , & V_56 . V_880 ) ;
if ( V_313 == 0 ) {
V_63 -> V_242 = V_56 . V_241 ;
V_63 -> V_883 = V_56 . V_219 ;
if ( ! ( V_56 . V_219 & V_884 ) ) {
F_135 ( V_885 ,
& V_63 -> V_87 -> V_886 ) ;
V_63 -> V_887 = V_56 . V_209 ;
}
F_105 ( V_63 -> V_888 ) ;
V_63 -> V_888 = V_56 . V_873 ;
V_56 . V_873 = NULL ;
F_105 ( V_63 -> V_889 ) ;
V_63 -> V_889 = V_56 . V_876 ;
V_56 . V_876 = NULL ;
if ( V_63 -> V_890 != NULL &&
! F_528 ( V_63 -> V_890 ,
V_56 . V_817 ) ) {
F_8 ( L_76 ,
V_34 ) ;
F_133 ( V_891 , & V_63 -> V_106 ) ;
F_105 ( V_63 -> V_890 ) ;
V_63 -> V_890 = NULL ;
}
if ( V_63 -> V_890 == NULL ) {
V_63 -> V_890 = V_56 . V_817 ;
V_56 . V_817 = NULL ;
}
}
V_882:
F_105 ( V_56 . V_876 ) ;
V_878:
F_105 ( V_56 . V_817 ) ;
V_875:
F_105 ( V_56 . V_873 ) ;
V_136:
if ( V_63 -> V_889 != NULL )
F_8 ( L_77
L_78 ,
V_63 -> V_889 -> V_892 , V_63 -> V_889 -> V_247 ,
V_63 -> V_889 -> V_893 . V_894 ,
V_63 -> V_889 -> V_893 . V_895 ) ;
F_8 ( L_79 , V_313 ) ;
return V_313 ;
}
int F_541 ( struct V_62 * V_63 , struct V_323 * V_357 )
{
T_4 V_896 = V_63 -> V_110 -> V_111 -> V_112 ;
int V_313 ;
if ( V_896 == V_113 ||
V_896 == V_114 ) {
V_313 = F_538 ( V_63 , V_357 , V_842 ) ;
if ( ! V_313 )
return 0 ;
}
return F_538 ( V_63 , V_357 , V_879 ) ;
}
static int F_542 ( struct V_62 * V_63 ,
struct V_323 * V_357 )
{
struct V_165 V_166 = {
. V_318 = & V_319 [ V_897 ] ,
. V_321 = V_63 ,
. V_323 = V_357 ,
} ;
int V_313 ;
V_313 = F_401 ( V_63 -> V_110 , & V_166 , V_619 ) ;
F_543 ( V_63 , V_313 ) ;
if ( V_313 )
F_8 ( L_80
L_81 , V_313 , V_63 -> V_97 ) ;
return V_313 ;
}
static int F_544 ( struct V_62 * V_63 ,
struct V_323 * V_357 )
{
unsigned int V_898 ;
int V_51 ;
for ( V_898 = V_899 ; V_898 != 0 ; V_898 -- ) {
V_51 = F_542 ( V_63 , V_357 ) ;
switch ( V_51 ) {
case - V_89 :
case - V_900 :
F_183 ( 1 ) ;
break;
default:
return V_51 ;
}
}
return 0 ;
}
int F_545 ( struct V_62 * V_63 )
{
struct V_323 * V_357 ;
int V_51 = 0 ;
if ( V_63 -> V_171 -> V_339 < 1 )
goto V_136;
if ( V_63 -> V_883 == 0 )
goto V_136;
if ( V_63 -> V_901 )
goto V_136;
V_357 = F_524 ( V_63 ) ;
V_51 = F_544 ( V_63 , V_357 ) ;
if ( V_357 )
F_222 ( V_357 ) ;
switch ( V_51 ) {
case 0 :
case - V_76 :
V_63 -> V_883 = 0 ;
}
V_136:
return V_51 ;
}
static void F_546 ( struct V_102 * V_103 ,
void * V_159 )
{
struct V_902 * V_161 =
(struct V_902 * ) V_159 ;
F_8 ( L_11 , V_34 ) ;
F_68 ( V_161 -> V_63 -> V_87 ,
& V_161 -> args -> V_903 ,
& V_161 -> V_56 -> V_904 ,
V_103 ) ;
F_8 ( L_82 , V_34 ) ;
}
static void F_547 ( struct V_102 * V_103 , void * V_159 )
{
struct V_902 * V_161 =
(struct V_902 * ) V_159 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_60 ( V_103 , & V_161 -> V_56 -> V_904 ) )
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
int F_548 ( struct V_62 * V_63 , struct V_476 * V_577 )
{
struct V_102 * V_103 ;
struct V_905 args ;
struct V_906 V_56 = {
. V_907 = V_577 ,
} ;
struct V_902 V_161 = {
. args = & args ,
. V_56 = & V_56 ,
. V_63 = V_63 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_908 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
struct V_167 V_168 = {
. V_169 = V_63 -> V_110 ,
. V_165 = & V_166 ,
. V_170 = & V_909 ,
. V_173 = & V_161 ,
. V_219 = V_619 ,
} ;
int V_313 ;
F_46 ( & args . V_903 , & V_56 . V_904 , 0 ) ;
F_47 ( & args . V_903 ) ;
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
static void F_549 ( struct V_910 * args )
{
unsigned int V_911 , V_912 ;
V_911 = V_913 + V_914 ;
V_912 = V_913 + V_915 ;
args -> V_916 . V_911 = V_911 ;
args -> V_916 . V_912 = V_912 ;
args -> V_916 . V_917 = V_918 ;
args -> V_916 . V_919 = V_920 ;
F_8 ( L_85
L_86 ,
V_34 ,
args -> V_916 . V_911 , args -> V_916 . V_912 ,
args -> V_916 . V_917 , args -> V_916 . V_919 ) ;
args -> V_921 . V_911 = V_626 ;
args -> V_921 . V_912 = V_626 ;
args -> V_921 . V_922 = 0 ;
args -> V_921 . V_917 = V_923 ;
args -> V_921 . V_919 = V_924 ;
F_8 ( L_87
L_88 ,
V_34 ,
args -> V_921 . V_911 , args -> V_921 . V_912 ,
args -> V_921 . V_922 , args -> V_921 . V_917 ,
args -> V_921 . V_919 ) ;
}
static int F_550 ( struct V_910 * args ,
struct V_925 * V_56 )
{
struct V_926 * V_927 = & args -> V_916 ;
struct V_926 * V_928 = & V_56 -> V_916 ;
if ( V_928 -> V_912 > V_927 -> V_912 )
return - V_27 ;
if ( V_928 -> V_917 < V_927 -> V_917 )
return - V_27 ;
if ( V_928 -> V_919 == 0 )
return - V_27 ;
if ( V_928 -> V_919 > V_929 )
V_928 -> V_919 = V_929 ;
return 0 ;
}
static int F_551 ( struct V_910 * args ,
struct V_925 * V_56 )
{
struct V_926 * V_927 = & args -> V_921 ;
struct V_926 * V_928 = & V_56 -> V_921 ;
if ( ! ( V_56 -> V_219 & V_827 ) )
goto V_136;
if ( V_928 -> V_911 > V_927 -> V_911 )
return - V_27 ;
if ( V_928 -> V_912 < V_927 -> V_912 )
return - V_27 ;
if ( V_928 -> V_922 > V_927 -> V_922 )
return - V_27 ;
if ( V_928 -> V_917 != V_927 -> V_917 )
return - V_27 ;
if ( V_928 -> V_919 != V_927 -> V_919 )
return - V_27 ;
V_136:
return 0 ;
}
static int F_552 ( struct V_910 * args ,
struct V_925 * V_56 )
{
int V_51 ;
V_51 = F_550 ( args , V_56 ) ;
if ( V_51 )
return V_51 ;
return F_551 ( args , V_56 ) ;
}
static void F_553 ( struct V_138 * V_139 ,
struct V_925 * V_56 )
{
F_531 ( & V_139 -> V_826 , & V_56 -> V_825 ) ;
V_139 -> V_63 -> V_883 |= V_884 ;
F_133 ( V_885 , & V_139 -> V_886 ) ;
V_139 -> V_219 = V_56 -> V_219 ;
memcpy ( & V_139 -> V_916 , & V_56 -> V_916 , sizeof( V_139 -> V_916 ) ) ;
if ( V_56 -> V_219 & V_827 )
memcpy ( & V_139 -> V_921 , & V_56 -> V_921 ,
sizeof( V_139 -> V_921 ) ) ;
}
static int F_554 ( struct V_62 * V_63 ,
struct V_323 * V_357 )
{
struct V_138 * V_139 = V_63 -> V_87 ;
struct V_910 args = {
. V_98 = V_63 ,
. V_241 = V_63 -> V_242 ,
. V_209 = V_63 -> V_887 ,
. V_930 = V_931 ,
} ;
struct V_925 V_56 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_932 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
int V_313 ;
F_549 ( & args ) ;
args . V_219 = ( V_933 | V_827 ) ;
V_313 = F_401 ( V_139 -> V_63 -> V_110 , & V_166 , V_619 ) ;
F_555 ( V_63 , V_313 ) ;
if ( ! V_313 ) {
V_313 = F_552 ( & args , & V_56 ) ;
if ( V_63 -> V_887 == V_56 . V_209 )
V_63 -> V_887 ++ ;
if ( V_313 )
goto V_136;
F_553 ( V_139 , & V_56 ) ;
}
V_136:
return V_313 ;
}
int F_556 ( struct V_62 * V_63 , struct V_323 * V_357 )
{
int V_313 ;
unsigned * V_934 ;
struct V_138 * V_139 = V_63 -> V_87 ;
F_8 ( L_89 , V_34 , V_63 , V_139 ) ;
V_313 = F_554 ( V_63 , V_357 ) ;
if ( V_313 )
goto V_136;
V_313 = F_557 ( V_139 ) ;
F_8 ( L_90 , V_313 ) ;
if ( V_313 )
goto V_136;
V_934 = ( unsigned * ) & V_139 -> V_826 . V_161 [ 0 ] ;
F_8 ( L_91 , V_34 ,
V_63 -> V_887 , V_934 [ 0 ] , V_934 [ 1 ] , V_934 [ 2 ] , V_934 [ 3 ] ) ;
V_136:
F_8 ( L_82 , V_34 ) ;
return V_313 ;
}
int F_558 ( struct V_138 * V_139 ,
struct V_323 * V_357 )
{
struct V_165 V_166 = {
. V_318 = & V_319 [ V_935 ] ,
. V_321 = V_139 ,
. V_323 = V_357 ,
} ;
int V_313 = 0 ;
F_8 ( L_92 ) ;
if ( ! F_126 ( V_885 , & V_139 -> V_886 ) )
return 0 ;
V_313 = F_401 ( V_139 -> V_63 -> V_110 , & V_166 , V_619 ) ;
F_559 ( V_139 -> V_63 , V_313 ) ;
if ( V_313 )
F_8 ( L_93
L_94 , V_313 ) ;
F_8 ( L_95 ) ;
return V_313 ;
}
static void F_560 ( void * V_161 )
{
struct V_936 * V_159 = V_161 ;
struct V_62 * V_63 = V_159 -> V_63 ;
if ( F_391 ( & V_63 -> V_613 ) > 1 )
F_392 ( V_63 ) ;
F_393 ( V_63 ) ;
F_105 ( V_159 ) ;
}
static int F_561 ( struct V_102 * V_103 , struct V_62 * V_63 )
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
static void F_562 ( struct V_102 * V_103 , void * V_161 )
{
struct V_936 * V_159 = V_161 ;
struct V_62 * V_63 = V_159 -> V_63 ;
if ( ! F_60 ( V_103 , V_103 -> V_333 . V_322 ) )
return;
F_563 ( V_63 , V_103 -> V_107 ) ;
if ( V_103 -> V_107 < 0 ) {
F_8 ( L_96 , V_34 , V_103 -> V_107 ) ;
if ( F_391 ( & V_63 -> V_613 ) == 1 )
goto V_136;
if ( F_561 ( V_103 , V_63 ) == - V_108 ) {
F_65 ( V_103 ) ;
return;
}
}
F_8 ( L_97 , V_34 , V_103 -> V_333 . V_323 ) ;
V_136:
F_8 ( L_82 , V_34 ) ;
}
static void F_564 ( struct V_102 * V_103 , void * V_161 )
{
struct V_936 * V_159 = V_161 ;
struct V_62 * V_63 = V_159 -> V_63 ;
struct V_118 * args ;
struct V_119 * V_56 ;
args = V_103 -> V_333 . V_321 ;
V_56 = V_103 -> V_333 . V_322 ;
F_68 ( V_63 -> V_87 , args , V_56 , V_103 ) ;
}
static struct V_102 * F_565 ( struct V_62 * V_63 ,
struct V_323 * V_357 ,
bool V_937 )
{
struct V_936 * V_159 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_938 ] ,
. V_323 = V_357 ,
} ;
struct V_167 V_324 = {
. V_169 = V_63 -> V_110 ,
. V_165 = & V_166 ,
. V_170 = & V_939 ,
. V_219 = V_328 | V_619 ,
} ;
if ( ! F_398 ( & V_63 -> V_613 ) )
return F_52 ( - V_35 ) ;
V_159 = F_95 ( sizeof( * V_159 ) , V_310 ) ;
if ( V_159 == NULL ) {
F_393 ( V_63 ) ;
return F_52 ( - V_132 ) ;
}
F_46 ( & V_159 -> args , & V_159 -> V_56 , 0 ) ;
if ( V_937 )
F_47 ( & V_159 -> args ) ;
V_166 . V_321 = & V_159 -> args ;
V_166 . V_322 = & V_159 -> V_56 ;
V_159 -> V_63 = V_63 ;
V_324 . V_173 = V_159 ;
return F_77 ( & V_324 ) ;
}
static int F_566 ( struct V_62 * V_63 , struct V_323 * V_357 , unsigned V_617 )
{
struct V_102 * V_103 ;
int V_51 = 0 ;
if ( ( V_617 & V_940 ) == 0 )
return - V_108 ;
V_103 = F_565 ( V_63 , V_357 , false ) ;
if ( F_51 ( V_103 ) )
V_51 = F_78 ( V_103 ) ;
else
F_481 ( V_103 ) ;
F_8 ( L_16 , V_34 , V_51 ) ;
return V_51 ;
}
static int F_567 ( struct V_62 * V_63 , struct V_323 * V_357 )
{
struct V_102 * V_103 ;
int V_51 ;
V_103 = F_565 ( V_63 , V_357 , true ) ;
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
static void F_568 ( struct V_102 * V_103 , void * V_161 )
{
struct V_941 * V_159 = V_161 ;
F_68 ( V_159 -> V_63 -> V_87 ,
& V_159 -> V_402 . V_163 ,
& V_159 -> V_56 . V_164 ,
V_103 ) ;
}
static int F_569 ( struct V_102 * V_103 , struct V_62 * V_63 )
{
switch( V_103 -> V_107 ) {
case 0 :
case - V_942 :
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
static void F_570 ( struct V_102 * V_103 , void * V_161 )
{
struct V_941 * V_159 = V_161 ;
struct V_62 * V_63 = V_159 -> V_63 ;
struct V_119 * V_56 = & V_159 -> V_56 . V_164 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_60 ( V_103 , V_56 ) )
return;
F_571 ( V_63 , V_103 -> V_107 ) ;
if ( F_569 ( V_103 , V_63 ) == - V_108 ) {
F_65 ( V_103 ) ;
return;
}
F_8 ( L_82 , V_34 ) ;
}
static void F_572 ( void * V_161 )
{
struct V_941 * V_159 = V_161 ;
F_105 ( V_159 ) ;
}
static int F_573 ( struct V_62 * V_63 ,
struct V_323 * V_357 )
{
struct V_941 * V_159 ;
struct V_102 * V_103 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_943 ] ,
. V_323 = V_357 ,
} ;
struct V_167 V_324 = {
. V_169 = V_63 -> V_110 ,
. V_165 = & V_166 ,
. V_170 = & V_944 ,
. V_219 = V_328 ,
} ;
int V_313 = - V_132 ;
F_8 ( L_11 , V_34 ) ;
V_159 = F_95 ( sizeof( * V_159 ) , V_310 ) ;
if ( V_159 == NULL )
goto V_136;
V_159 -> V_63 = V_63 ;
V_159 -> V_402 . V_945 = 0 ;
F_46 ( & V_159 -> V_402 . V_163 , & V_159 -> V_56 . V_164 , 0 ) ;
F_47 ( & V_159 -> V_402 . V_163 ) ;
V_166 . V_321 = & V_159 -> V_402 ;
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
F_574 ( struct V_102 * V_103 , void * V_159 )
{
struct V_946 * V_947 = V_159 ;
struct V_13 * V_14 = F_94 ( V_947 -> args . V_2 ) ;
struct V_138 * V_139 = F_71 ( V_14 ) ;
int V_51 ;
F_8 ( L_11 , V_34 ) ;
if ( F_68 ( V_139 , & V_947 -> args . V_163 ,
& V_947 -> V_56 . V_164 , V_103 ) )
return;
V_51 = F_575 ( & V_947 -> args . V_257 ,
F_82 ( V_947 -> args . V_2 ) -> V_948 ,
& V_947 -> args . V_949 ,
V_947 -> args . V_308 -> V_65 ) ;
if ( V_51 < 0 )
F_576 ( V_103 , V_51 ) ;
}
static void F_577 ( struct V_102 * V_103 , void * V_159 )
{
struct V_946 * V_947 = V_159 ;
struct V_2 * V_2 = V_947 -> args . V_2 ;
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_950 * V_951 ;
struct V_64 * V_65 = NULL ;
unsigned long V_952 , V_581 , V_953 ;
F_8 ( L_98 , V_34 , - V_103 -> V_107 ) ;
if ( ! F_60 ( V_103 , & V_947 -> V_56 . V_164 ) )
goto V_136;
switch ( V_103 -> V_107 ) {
case 0 :
goto V_136;
case - V_954 :
V_103 -> V_107 = - V_955 ;
goto V_136;
case - V_956 :
goto V_957;
case - V_19 :
if ( V_947 -> args . V_958 == 0 )
goto V_957;
case - V_20 :
V_952 = F_578 ( V_103 -> V_959 ) ;
V_953 = V_947 -> args . V_115 + V_952 ;
V_581 = V_157 ;
if ( F_579 ( V_953 , V_581 ) ) {
unsigned long V_66 ;
V_66 = F_580 (unsigned long, NFS4_POLL_RETRY_MIN,
min((giveup - now - 1),
now - lgp->args.timestamp)) ;
F_8 ( L_99 ,
V_34 , V_66 ) ;
F_35 ( V_103 , V_66 ) ;
goto V_960;
}
break;
case - V_74 :
case - V_72 :
F_41 ( & V_2 -> V_178 ) ;
if ( F_146 ( & V_947 -> args . V_257 ,
& V_947 -> args . V_308 -> V_65 -> V_257 ) ) {
F_43 ( & V_2 -> V_178 ) ;
V_65 = V_947 -> args . V_308 -> V_65 ;
break;
}
V_951 = F_82 ( V_2 ) -> V_948 ;
if ( V_951 && F_146 ( & V_947 -> args . V_257 ,
& V_951 -> V_961 ) ) {
F_581 ( V_962 ) ;
F_133 ( V_963 , & V_951 -> V_964 ) ;
F_582 ( V_951 , & V_962 , NULL ) ;
F_43 ( & V_2 -> V_178 ) ;
F_583 ( & V_962 ) ;
} else
F_43 ( & V_2 -> V_178 ) ;
goto V_960;
}
if ( F_38 ( V_103 , V_14 , V_65 , & V_947 -> V_50 ) == - V_108 )
goto V_960;
V_136:
F_8 ( L_82 , V_34 ) ;
return;
V_960:
V_103 -> V_107 = 0 ;
F_65 ( V_103 ) ;
return;
V_957:
V_103 -> V_107 = - V_965 ;
goto V_136;
}
static T_9 F_584 ( struct V_13 * V_14 )
{
T_1 V_912 = V_14 -> V_62 -> V_87 -> V_916 . V_912 ;
return F_585 ( 0 , V_912 ) ;
}
static void F_586 ( struct V_501 * * V_42 , T_9 V_966 )
{
int V_490 ;
if ( ! V_42 )
return;
for ( V_490 = 0 ; V_490 < V_966 ; V_490 ++ ) {
if ( ! V_42 [ V_490 ] )
break;
F_293 ( V_42 [ V_490 ] ) ;
}
F_105 ( V_42 ) ;
}
static struct V_501 * * F_587 ( T_9 V_966 , T_6 V_967 )
{
struct V_501 * * V_42 ;
int V_490 ;
V_42 = F_588 ( V_966 , sizeof( struct V_501 * ) , V_967 ) ;
if ( ! V_42 ) {
F_8 ( L_100 , V_34 , V_966 ) ;
return NULL ;
}
for ( V_490 = 0 ; V_490 < V_966 ; V_490 ++ ) {
V_42 [ V_490 ] = F_289 ( V_967 ) ;
if ( ! V_42 [ V_490 ] ) {
F_8 ( L_101 , V_34 ) ;
F_586 ( V_42 , V_966 ) ;
return NULL ;
}
}
return V_42 ;
}
static void F_589 ( void * V_159 )
{
struct V_946 * V_947 = V_159 ;
struct V_2 * V_2 = V_947 -> args . V_2 ;
struct V_13 * V_14 = F_94 ( V_2 ) ;
T_9 V_968 = F_584 ( V_14 ) ;
F_8 ( L_11 , V_34 ) ;
F_586 ( V_947 -> args . V_948 . V_42 , V_968 ) ;
F_590 ( F_82 ( V_2 ) -> V_948 ) ;
F_180 ( V_947 -> args . V_308 ) ;
F_105 ( V_159 ) ;
F_8 ( L_82 , V_34 ) ;
}
struct V_969 *
F_591 ( struct V_946 * V_947 , T_6 V_967 )
{
struct V_2 * V_2 = V_947 -> args . V_2 ;
struct V_13 * V_14 = F_94 ( V_2 ) ;
T_9 V_968 = F_584 ( V_14 ) ;
struct V_102 * V_103 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_970 ] ,
. V_321 = & V_947 -> args ,
. V_322 = & V_947 -> V_56 ,
. V_323 = V_947 -> V_357 ,
} ;
struct V_167 V_324 = {
. V_169 = V_14 -> V_98 ,
. V_165 = & V_166 ,
. V_170 = & V_971 ,
. V_173 = V_947 ,
. V_219 = V_328 ,
} ;
struct V_969 * V_972 = NULL ;
int V_313 = 0 ;
F_8 ( L_11 , V_34 ) ;
F_592 ( F_82 ( V_2 ) -> V_948 ) ;
V_947 -> args . V_948 . V_42 = F_587 ( V_968 , V_967 ) ;
if ( ! V_947 -> args . V_948 . V_42 ) {
F_589 ( V_947 ) ;
return F_52 ( - V_132 ) ;
}
V_947 -> args . V_948 . V_528 = V_968 * V_626 ;
V_947 -> args . V_115 = V_157 ;
V_947 -> V_56 . V_973 = & V_947 -> args . V_948 ;
V_947 -> V_56 . V_164 . V_124 = NULL ;
F_46 ( & V_947 -> args . V_163 , & V_947 -> V_56 . V_164 , 0 ) ;
V_103 = F_77 ( & V_324 ) ;
if ( F_51 ( V_103 ) )
return F_269 ( V_103 ) ;
V_313 = F_116 ( V_103 ) ;
if ( V_313 == 0 )
V_313 = V_103 -> V_107 ;
F_593 ( V_947 -> args . V_308 ,
& V_947 -> args . V_949 ,
& V_947 -> V_56 . V_949 ,
& V_947 -> V_56 . V_257 ,
V_313 ) ;
if ( V_313 == 0 && V_947 -> V_56 . V_973 -> V_12 )
V_972 = F_594 ( V_947 ) ;
F_79 ( V_103 ) ;
F_8 ( L_16 , V_34 , V_313 ) ;
if ( V_313 )
return F_52 ( V_313 ) ;
return V_972 ;
}
static void
F_595 ( struct V_102 * V_103 , void * V_159 )
{
struct V_974 * V_975 = V_159 ;
F_8 ( L_11 , V_34 ) ;
F_68 ( V_975 -> V_63 -> V_87 ,
& V_975 -> args . V_163 ,
& V_975 -> V_56 . V_164 ,
V_103 ) ;
}
static void F_596 ( struct V_102 * V_103 , void * V_159 )
{
struct V_974 * V_975 = V_159 ;
struct V_13 * V_14 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_60 ( V_103 , & V_975 -> V_56 . V_164 ) )
return;
V_14 = F_94 ( V_975 -> args . V_2 ) ;
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
static void F_597 ( void * V_159 )
{
struct V_974 * V_975 = V_159 ;
struct V_950 * V_951 = V_975 -> args . V_948 ;
F_581 ( V_976 ) ;
F_8 ( L_11 , V_34 ) ;
F_41 ( & V_951 -> V_977 -> V_178 ) ;
F_582 ( V_951 , & V_976 , & V_975 -> args . V_949 ) ;
F_598 ( V_951 ) ;
if ( V_975 -> V_56 . V_978 )
F_599 ( V_951 , & V_975 -> V_56 . V_257 , true ) ;
F_600 ( V_951 ) ;
F_43 ( & V_951 -> V_977 -> V_178 ) ;
F_583 ( & V_976 ) ;
F_590 ( V_975 -> args . V_948 ) ;
F_449 ( V_975 -> V_2 ) ;
F_105 ( V_159 ) ;
F_8 ( L_82 , V_34 ) ;
}
int F_601 ( struct V_974 * V_975 , bool V_979 )
{
struct V_102 * V_103 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_980 ] ,
. V_321 = & V_975 -> args ,
. V_322 = & V_975 -> V_56 ,
. V_323 = V_975 -> V_357 ,
} ;
struct V_167 V_324 = {
. V_169 = F_94 ( V_975 -> args . V_2 ) -> V_98 ,
. V_165 = & V_166 ,
. V_170 = & V_981 ,
. V_173 = V_975 ,
} ;
int V_313 = 0 ;
F_267 ( F_94 ( V_975 -> args . V_2 ) -> V_62 ,
V_856 ,
& V_324 . V_169 , & V_166 ) ;
F_8 ( L_11 , V_34 ) ;
if ( ! V_979 ) {
V_975 -> V_2 = F_452 ( V_975 -> args . V_2 ) ;
if ( ! V_975 -> V_2 ) {
F_597 ( V_975 ) ;
return - V_108 ;
}
V_324 . V_219 |= V_328 ;
}
F_46 ( & V_975 -> args . V_163 , & V_975 -> V_56 . V_164 , 1 ) ;
V_103 = F_77 ( & V_324 ) ;
if ( F_51 ( V_103 ) )
return F_78 ( V_103 ) ;
if ( V_979 )
V_313 = V_103 -> V_107 ;
F_602 ( V_975 -> args . V_2 , & V_975 -> args . V_257 , V_313 ) ;
F_8 ( L_16 , V_34 , V_313 ) ;
F_79 ( V_103 ) ;
return V_313 ;
}
static int
F_603 ( struct V_13 * V_14 ,
struct V_982 * V_983 ,
struct V_323 * V_357 )
{
struct V_984 args = {
. V_983 = V_983 ,
. V_985 = V_986 |
V_987 ,
} ;
struct V_988 V_56 = {
. V_983 = V_983 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_989 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
int V_313 ;
F_8 ( L_11 , V_34 ) ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
if ( V_56 . V_990 & ~ args . V_985 )
F_8 ( L_102 , V_34 ) ;
if ( V_56 . V_990 != args . V_985 )
V_983 -> V_991 = 1 ;
F_8 ( L_16 , V_34 , V_313 ) ;
return V_313 ;
}
int F_604 ( struct V_13 * V_14 ,
struct V_982 * V_983 ,
struct V_323 * V_357 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_31 ( V_14 ,
F_603 ( V_14 , V_983 , V_357 ) ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static void F_605 ( struct V_102 * V_103 , void * V_159 )
{
struct V_992 * V_161 = V_159 ;
struct V_13 * V_14 = F_94 ( V_161 -> args . V_2 ) ;
struct V_138 * V_139 = F_71 ( V_14 ) ;
F_68 ( V_139 ,
& V_161 -> args . V_163 ,
& V_161 -> V_56 . V_164 ,
V_103 ) ;
}
static void
F_606 ( struct V_102 * V_103 , void * V_159 )
{
struct V_992 * V_161 = V_159 ;
struct V_13 * V_14 = F_94 ( V_161 -> args . V_2 ) ;
if ( ! F_60 ( V_103 , & V_161 -> V_56 . V_164 ) )
return;
switch ( V_103 -> V_107 ) {
case - V_70 :
case - V_993 :
case - V_956 :
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
static void F_607 ( void * V_159 )
{
struct V_992 * V_161 = V_159 ;
F_608 ( V_161 ) ;
F_453 ( V_161 -> args . V_2 ,
V_161 -> V_56 . V_399 ) ;
F_222 ( V_161 -> V_357 ) ;
F_449 ( V_161 -> V_2 ) ;
F_105 ( V_161 ) ;
}
int
F_609 ( struct V_992 * V_161 , bool V_979 )
{
struct V_165 V_166 = {
. V_318 = & V_319 [ V_994 ] ,
. V_321 = & V_161 -> args ,
. V_322 = & V_161 -> V_56 ,
. V_323 = V_161 -> V_357 ,
} ;
struct V_167 V_324 = {
. V_103 = & V_161 -> V_103 ,
. V_169 = F_308 ( V_161 -> args . V_2 ) ,
. V_165 = & V_166 ,
. V_170 = & V_995 ,
. V_173 = V_161 ,
} ;
struct V_102 * V_103 ;
int V_313 = 0 ;
F_8 ( L_103
L_104 , V_979 ,
V_161 -> args . V_996 ,
V_161 -> args . V_2 -> V_997 ) ;
if ( ! V_979 ) {
V_161 -> V_2 = F_452 ( V_161 -> args . V_2 ) ;
if ( V_161 -> V_2 == NULL ) {
F_607 ( V_161 ) ;
return - V_108 ;
}
V_324 . V_219 = V_328 ;
}
F_46 ( & V_161 -> args . V_163 , & V_161 -> V_56 . V_164 , 1 ) ;
V_103 = F_77 ( & V_324 ) ;
if ( F_51 ( V_103 ) )
return F_78 ( V_103 ) ;
if ( V_979 )
V_313 = V_103 -> V_107 ;
F_610 ( V_161 -> args . V_2 , & V_161 -> args . V_257 , V_313 ) ;
F_8 ( L_105 , V_34 , V_313 ) ;
F_79 ( V_103 ) ;
return V_313 ;
}
static int
F_611 ( struct V_13 * V_14 , struct V_436 * V_437 ,
struct V_476 * V_477 ,
struct V_801 * V_493 , bool V_802 )
{
struct V_998 args = {
. V_999 = V_1000 ,
} ;
struct V_804 V_56 = {
. V_493 = V_493 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_1001 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
struct V_54 * V_55 = V_14 -> V_98 ;
struct V_323 * V_357 = NULL ;
int V_313 ;
if ( V_802 ) {
V_55 = V_14 -> V_62 -> V_110 ;
V_357 = F_524 ( V_14 -> V_62 ) ;
V_166 . V_323 = V_357 ;
}
F_8 ( L_11 , V_34 ) ;
V_313 = F_80 ( V_55 , V_14 , & V_166 , & args . V_163 ,
& V_56 . V_164 , 0 ) ;
F_8 ( L_16 , V_34 , V_313 ) ;
if ( V_357 )
F_222 ( V_357 ) ;
return V_313 ;
}
static int
F_612 ( struct V_13 * V_14 , struct V_436 * V_437 ,
struct V_476 * V_477 , struct V_801 * V_493 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_39 ( V_14 -> V_62 ) )
V_8 = F_611 ( V_14 , V_437 , V_477 ,
V_493 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_611 ( V_14 , V_437 , V_477 ,
V_493 , false ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
case - V_1002 :
goto V_136;
default:
V_8 = F_31 ( V_14 , V_8 , & V_61 ) ;
}
} while ( V_61 . V_68 );
V_136:
return V_8 ;
}
static int
F_613 ( struct V_13 * V_14 , struct V_436 * V_437 ,
struct V_476 * V_477 )
{
int V_8 ;
struct V_501 * V_501 ;
T_4 V_109 = V_1003 ;
struct V_801 * V_493 ;
struct V_1004 * V_1005 ;
int V_490 ;
V_501 = F_289 ( V_390 ) ;
if ( ! V_501 ) {
V_8 = - V_132 ;
goto V_136;
}
V_493 = F_405 ( V_501 ) ;
V_8 = F_612 ( V_14 , V_437 , V_477 , V_493 ) ;
if ( V_8 == - V_22 || V_8 == - V_1002 ) {
V_8 = F_280 ( V_14 , V_437 , V_477 ) ;
goto V_1006;
}
if ( V_8 )
goto V_1006;
for ( V_490 = 0 ; V_490 < V_493 -> V_1007 ; V_490 ++ ) {
V_1005 = & V_493 -> V_493 [ V_490 ] ;
switch ( V_1005 -> V_109 ) {
case V_489 :
case V_488 :
case V_1008 :
V_109 = F_614 ( V_1005 -> V_109 ,
& V_1005 -> V_1009 ) ;
break;
default:
V_109 = V_1003 ;
break;
}
if ( ! F_615 ( & V_14 -> V_491 , V_109 ) )
V_109 = V_1003 ;
if ( V_109 != V_1003 ) {
V_8 = F_278 ( V_14 , V_437 ,
V_477 , V_109 ) ;
if ( ! V_8 )
break;
}
}
if ( V_109 == V_1003 )
V_8 = - V_24 ;
V_1006:
F_419 ( V_501 ) ;
if ( V_8 == - V_29 )
return - V_24 ;
V_136:
return V_8 ;
}
static int F_616 ( struct V_13 * V_14 ,
T_8 * V_257 ,
struct V_323 * V_357 )
{
int V_313 ;
struct V_1010 args = {
. V_257 = V_257 ,
} ;
struct V_1011 V_56 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_1012 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
struct V_54 * V_169 = V_14 -> V_98 ;
F_267 ( V_14 -> V_62 , V_861 ,
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
static int F_219 ( struct V_13 * V_14 ,
T_8 * V_257 ,
struct V_323 * V_357 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_616 ( V_14 , V_257 , V_357 ) ;
if ( V_8 != - V_89 )
break;
F_31 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static void F_617 ( struct V_102 * V_103 , void * V_159 )
{
struct V_1013 * V_161 = V_159 ;
F_68 ( F_71 ( V_161 -> V_14 ) ,
& V_161 -> args . V_163 ,
& V_161 -> V_56 . V_164 ,
V_103 ) ;
}
static void F_618 ( struct V_102 * V_103 , void * V_159 )
{
struct V_1013 * V_161 = V_159 ;
F_60 ( V_103 , & V_161 -> V_56 . V_164 ) ;
switch ( V_103 -> V_107 ) {
case - V_89 :
if ( F_38 ( V_103 , V_161 -> V_14 , NULL , NULL ) == - V_108 )
F_65 ( V_103 ) ;
}
}
static void F_619 ( void * V_159 )
{
F_105 ( V_159 ) ;
}
static struct V_102 * F_620 ( struct V_13 * V_14 ,
T_8 * V_257 ,
struct V_323 * V_357 ,
bool V_1014 )
{
struct V_165 V_166 = {
. V_318 = & V_319 [ V_1015 ] ,
. V_323 = V_357 ,
} ;
struct V_167 V_168 = {
. V_169 = V_14 -> V_98 ,
. V_165 = & V_166 ,
. V_170 = & V_1016 ,
. V_219 = V_328 ,
} ;
struct V_1013 * V_161 ;
F_267 ( V_14 -> V_62 , V_861 ,
& V_168 . V_169 , & V_166 ) ;
F_8 ( L_109 , V_257 ) ;
V_161 = F_290 ( sizeof( * V_161 ) , V_310 ) ;
if ( ! V_161 )
return F_52 ( - V_132 ) ;
V_161 -> V_14 = V_14 ;
F_136 ( & V_161 -> args . V_257 , V_257 ) ;
V_168 . V_173 = V_161 ;
V_166 . V_321 = & V_161 -> args ;
V_166 . V_322 = & V_161 -> V_56 ;
F_46 ( & V_161 -> args . V_163 , & V_161 -> V_56 . V_164 , 0 ) ;
if ( V_1014 )
F_47 ( & V_161 -> args . V_163 ) ;
return F_77 ( & V_168 ) ;
}
static int F_221 ( struct V_13 * V_14 ,
T_8 * V_257 ,
struct V_323 * V_357 )
{
struct V_102 * V_103 ;
int V_51 ;
V_103 = F_620 ( V_14 , V_257 , V_357 , true ) ;
if ( F_51 ( V_103 ) )
return F_78 ( V_103 ) ;
V_51 = F_117 ( V_103 ) ;
if ( ! V_51 )
V_51 = V_103 -> V_107 ;
F_79 ( V_103 ) ;
return V_51 ;
}
static void
F_621 ( struct V_13 * V_14 , struct V_289 * V_290 )
{
struct V_102 * V_103 ;
struct V_323 * V_357 = V_290 -> V_291 -> V_232 -> V_298 ;
V_103 = F_620 ( V_14 , & V_290 -> V_293 , V_357 , false ) ;
F_502 ( V_14 , V_290 ) ;
if ( F_51 ( V_103 ) )
return;
F_79 ( V_103 ) ;
}
static bool F_622 ( const T_8 * V_1017 ,
const T_8 * V_1018 )
{
if ( memcmp ( V_1017 -> V_1019 , V_1018 -> V_1019 , sizeof( V_1017 -> V_1019 ) ) != 0 )
return false ;
if ( V_1017 -> V_209 == V_1018 -> V_209 )
return true ;
if ( V_1017 -> V_209 == 0 || V_1018 -> V_209 == 0 )
return true ;
return false ;
}
static bool F_623 ( const T_8 * V_1017 ,
const T_8 * V_1018 )
{
return F_146 ( V_1017 , V_1018 ) ;
}
static struct V_223 *
F_624 ( struct V_225 * V_1020 , T_6 V_1021 )
{
return NULL ;
}
T_11 F_625 ( struct V_4 * V_4 , char * V_773 , T_9 V_966 )
{
T_11 error , V_1022 ;
error = F_626 ( V_4 , V_773 , V_966 ) ;
if ( error < 0 )
return error ;
if ( V_773 ) {
V_773 += error ;
V_966 -= error ;
}
V_1022 = F_510 ( F_14 ( V_4 ) , V_773 , V_966 ) ;
if ( V_1022 < 0 )
return V_1022 ;
return error + V_1022 ;
}
