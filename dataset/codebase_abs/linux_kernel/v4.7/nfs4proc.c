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
case - V_20 :
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
if ( V_6 -> V_253 & V_396 ) {
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
}
if ( V_385 && V_295 -> V_364 )
* V_385 |= V_397 ;
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
if ( V_313 == - V_398 ) {
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
struct V_399 * V_400 , struct V_5 * V_6 ,
struct V_64 * V_65 , struct V_1 * V_401 ,
struct V_1 * V_389 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_402 V_403 = {
. V_251 = F_102 ( V_2 ) ,
. V_404 = V_6 ,
. V_14 = V_14 ,
. V_248 = V_14 -> V_15 ,
. V_7 = V_401 ,
} ;
struct V_405 V_56 = {
. V_400 = V_400 ,
. V_7 = V_389 ,
. V_14 = V_14 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_406 ] ,
. V_321 = & V_403 ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
struct V_323 * V_407 = NULL ;
unsigned long V_115 = V_157 ;
T_5 V_188 ;
bool V_408 ;
int V_313 ;
V_403 . V_248 = F_6 ( V_14 , V_401 ) ;
if ( V_401 )
V_403 . V_248 = F_6 ( V_14 , V_389 ) ;
F_90 ( V_400 ) ;
V_408 = ( V_6 -> V_253 & V_409 ) ? true : false ;
V_188 = V_408 ? V_191 : V_190 ;
if ( F_249 ( V_2 , V_188 , & V_403 . V_257 , & V_407 ) ) {
} else if ( V_408 && V_65 != NULL ) {
struct V_410 V_411 = {
. V_412 = V_57 -> V_413 ,
. V_414 = V_57 -> V_415 ,
} ;
if ( ! F_250 ( V_65 ) )
return - V_416 ;
if ( F_251 ( V_65 , V_191 , & V_411 ,
& V_403 . V_257 , & V_407 ) == - V_35 )
return - V_416 ;
} else
F_136 ( & V_403 . V_257 , & V_417 ) ;
if ( V_407 )
V_166 . V_323 = V_407 ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & V_403 . V_163 , & V_56 . V_164 , 1 ) ;
F_222 ( V_407 ) ;
if ( V_313 == 0 && V_65 != NULL )
F_44 ( V_14 , V_115 ) ;
F_252 ( V_2 , & V_403 . V_257 , V_313 ) ;
return V_313 ;
}
static int F_241 ( struct V_2 * V_2 , struct V_323 * V_357 ,
struct V_399 * V_400 , struct V_5 * V_6 ,
struct V_64 * V_65 , struct V_1 * V_401 ,
struct V_1 * V_389 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_60 V_61 = {
. V_65 = V_65 ,
. V_2 = V_2 ,
} ;
int V_8 ;
do {
V_8 = F_248 ( V_2 , V_357 , V_400 , V_6 , V_65 , V_401 , V_389 ) ;
switch ( V_8 ) {
case - V_69 :
if ( ! ( V_6 -> V_253 & V_409 ) ) {
F_253 ( L_25
L_26
L_27
L_28 ,
V_14 -> V_62 -> V_97 ) ;
}
if ( V_65 && ! ( V_65 -> V_65 & V_191 ) ) {
V_8 = - V_416 ;
if ( V_6 -> V_253 & V_418 )
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
struct V_419 * V_159 = V_161 ;
struct V_217 * V_218 = V_159 -> V_65 -> V_232 ;
struct V_259 * V_260 = V_159 -> V_65 -> V_2 -> V_420 ;
if ( V_159 -> V_421 )
F_258 ( V_159 -> V_65 -> V_2 ) ;
F_110 ( V_159 -> V_65 ) ;
F_109 ( V_159 -> V_403 . V_209 ) ;
F_111 ( V_218 ) ;
F_112 ( V_260 ) ;
F_105 ( V_159 ) ;
}
static void F_259 ( struct V_102 * V_103 , void * V_161 )
{
struct V_419 * V_159 = V_161 ;
struct V_64 * V_65 = V_159 -> V_65 ;
struct V_13 * V_14 = F_94 ( V_159 -> V_2 ) ;
T_8 * V_422 = NULL ;
F_8 ( L_29 , V_34 ) ;
if ( ! F_67 ( V_103 , & V_159 -> V_56 . V_164 ) )
return;
F_260 ( V_65 , & V_159 -> V_403 , & V_159 -> V_56 , V_103 -> V_107 ) ;
switch ( V_103 -> V_107 ) {
case 0 :
V_422 = & V_159 -> V_56 . V_257 ;
if ( V_159 -> V_421 )
F_261 ( V_65 -> V_2 ,
V_159 -> V_423 ) ;
F_44 ( V_14 , V_159 -> V_115 ) ;
break;
case - V_71 :
case - V_75 :
case - V_93 :
case - V_72 :
case - V_74 :
if ( ! F_146 ( & V_159 -> V_403 . V_257 ,
& V_65 -> V_278 ) ) {
F_65 ( V_103 ) ;
goto V_424;
}
if ( V_159 -> V_403 . V_188 == 0 )
break;
default:
if ( F_38 ( V_103 , V_14 , V_65 , NULL ) == - V_108 ) {
F_65 ( V_103 ) ;
goto V_424;
}
}
F_137 ( V_65 , & V_159 -> V_403 . V_257 ,
V_422 , V_159 -> V_403 . V_188 ) ;
V_424:
F_152 ( V_159 -> V_403 . V_209 ) ;
F_159 ( V_159 -> V_2 , V_159 -> V_56 . V_400 ) ;
F_8 ( L_30 , V_34 , V_103 -> V_107 ) ;
}
static void F_262 ( struct V_102 * V_103 , void * V_161 )
{
struct V_419 * V_159 = V_161 ;
struct V_64 * V_65 = V_159 -> V_65 ;
struct V_2 * V_2 = V_159 -> V_2 ;
bool V_425 , V_426 , V_427 ;
int V_428 = 0 ;
F_8 ( L_29 , V_34 ) ;
if ( F_193 ( V_159 -> V_403 . V_209 , V_103 ) != 0 )
goto V_329;
V_103 -> V_333 . V_318 = & V_319 [ V_429 ] ;
F_41 ( & V_65 -> V_232 -> V_284 ) ;
V_427 = F_33 ( V_270 , & V_65 -> V_219 ) ;
V_425 = F_33 ( V_268 , & V_65 -> V_219 ) ;
V_426 = F_33 ( V_269 , & V_65 -> V_219 ) ;
F_136 ( & V_159 -> V_403 . V_257 , & V_65 -> V_278 ) ;
V_159 -> V_403 . V_188 = 0 ;
if ( V_65 -> V_262 == 0 ) {
if ( V_65 -> V_264 == 0 )
V_428 |= V_425 ;
else if ( V_425 )
V_159 -> V_403 . V_188 |= V_190 ;
if ( V_65 -> V_263 == 0 )
V_428 |= V_426 ;
else if ( V_426 )
V_159 -> V_403 . V_188 |= V_191 ;
if ( V_159 -> V_403 . V_188 != ( V_190 | V_191 ) )
V_428 |= V_427 ;
} else if ( V_427 )
V_159 -> V_403 . V_188 |= V_190 | V_191 ;
if ( ! F_250 ( V_65 ) )
V_428 = 0 ;
F_43 ( & V_65 -> V_232 -> V_284 ) ;
if ( ! V_428 ) {
goto V_330;
}
if ( F_254 ( V_2 , V_103 ) ) {
F_152 ( V_159 -> V_403 . V_209 ) ;
goto V_329;
}
if ( V_159 -> V_403 . V_188 == 0 )
V_103 -> V_333 . V_318 = & V_319 [ V_430 ] ;
if ( V_159 -> V_421 )
F_263 ( V_2 , & V_159 -> V_423 ) ;
V_159 -> V_403 . V_235 =
F_87 ( F_94 ( V_2 ) ,
V_159 -> V_403 . V_188 , 0 ) ;
F_90 ( V_159 -> V_56 . V_400 ) ;
V_159 -> V_115 = V_157 ;
if ( F_70 ( F_94 ( V_2 ) ,
& V_159 -> V_403 . V_163 ,
& V_159 -> V_56 . V_164 ,
V_103 ) != 0 )
F_152 ( V_159 -> V_403 . V_209 ) ;
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
int F_266 ( struct V_64 * V_65 , T_6 V_221 , int V_431 )
{
struct V_13 * V_14 = F_94 ( V_65 -> V_2 ) ;
struct V_223 * ( * V_224 ) ( struct V_225 * , T_6 ) ;
struct V_419 * V_159 ;
struct V_217 * V_218 = V_65 -> V_232 ;
struct V_102 * V_103 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_430 ] ,
. V_323 = V_65 -> V_232 -> V_298 ,
} ;
struct V_167 V_324 = {
. V_169 = V_14 -> V_98 ,
. V_165 = & V_166 ,
. V_170 = & V_432 ,
. V_326 = V_327 ,
. V_219 = V_328 ,
} ;
int V_313 = - V_132 ;
F_267 ( V_14 -> V_62 , V_433 ,
& V_324 . V_169 , & V_166 ) ;
V_159 = F_95 ( sizeof( * V_159 ) , V_221 ) ;
if ( V_159 == NULL )
goto V_136;
F_46 ( & V_159 -> V_403 . V_163 , & V_159 -> V_56 . V_164 , 1 ) ;
V_159 -> V_2 = V_65 -> V_2 ;
V_159 -> V_65 = V_65 ;
V_159 -> V_403 . V_251 = F_102 ( V_65 -> V_2 ) ;
V_224 = V_14 -> V_62 -> V_171 -> V_224 ;
V_159 -> V_403 . V_209 = V_224 ( & V_65 -> V_232 -> V_229 , V_221 ) ;
if ( F_51 ( V_159 -> V_403 . V_209 ) )
goto V_434;
V_159 -> V_403 . V_188 = 0 ;
V_159 -> V_403 . V_248 = V_14 -> V_435 ;
V_159 -> V_56 . V_400 = & V_159 -> V_400 ;
V_159 -> V_56 . V_209 = V_159 -> V_403 . V_209 ;
V_159 -> V_56 . V_14 = V_14 ;
V_159 -> V_421 = F_264 ( V_65 -> V_2 ) ;
F_97 ( V_159 -> V_2 -> V_420 ) ;
V_166 . V_321 = & V_159 -> V_403 ;
V_166 . V_322 = & V_159 -> V_56 ;
V_324 . V_173 = V_159 ;
V_103 = F_77 ( & V_324 ) ;
if ( F_51 ( V_103 ) )
return F_78 ( V_103 ) ;
V_313 = 0 ;
if ( V_431 )
V_313 = F_117 ( V_103 ) ;
F_79 ( V_103 ) ;
return V_313 ;
V_434:
F_105 ( V_159 ) ;
V_136:
F_110 ( V_65 ) ;
F_111 ( V_218 ) ;
return V_313 ;
}
static struct V_2 *
F_268 ( struct V_2 * V_3 , struct V_307 * V_308 ,
int V_234 , struct V_5 * V_436 , int * V_385 )
{
struct V_64 * V_65 ;
struct V_1 V_17 = { 0 , 0 , 0 , NULL } , * V_7 = NULL ;
V_7 = F_1 ( V_3 , V_308 -> V_4 , V_436 , & V_17 ) ;
V_65 = F_245 ( V_3 , V_308 , V_234 , V_436 , V_7 , V_385 ) ;
F_4 ( V_7 ) ;
if ( F_51 ( V_65 ) )
return F_269 ( V_65 ) ;
return V_65 -> V_2 ;
}
static void F_270 ( struct V_307 * V_308 , int V_437 )
{
if ( V_308 -> V_65 == NULL )
return;
if ( V_437 )
F_271 ( V_308 -> V_65 , V_308 -> V_265 ) ;
else
F_173 ( V_308 -> V_65 , V_308 -> V_265 ) ;
}
static int F_272 ( struct V_13 * V_14 , struct V_438 * V_439 )
{
T_1 V_248 [ 3 ] = {} , V_440 = V_14 -> V_62 -> V_441 ;
struct V_442 args = {
. V_439 = V_439 ,
. V_248 = V_248 ,
} ;
struct V_443 V_56 = {} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_444 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
int V_313 ;
V_248 [ 0 ] = V_445 |
V_446 |
V_447 |
V_448 |
V_449 ;
if ( V_440 )
V_248 [ 2 ] = V_450 ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
if ( V_313 == 0 ) {
switch ( V_440 ) {
case 0 :
V_56 . V_15 [ 1 ] &= V_451 ;
V_56 . V_15 [ 2 ] = 0 ;
break;
case 1 :
V_56 . V_15 [ 2 ] &= V_452 ;
break;
case 2 :
V_56 . V_15 [ 2 ] &= V_453 ;
}
memcpy ( V_14 -> V_15 , V_56 . V_15 , sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_94 &= ~ ( V_454 | V_455 |
V_456 | V_457 |
V_458 | V_459 | V_460 |
V_461 | V_462 |
V_463 | V_464 |
V_9 ) ;
if ( V_56 . V_15 [ 0 ] & V_465 &&
V_56 . V_466 & V_467 )
V_14 -> V_94 |= V_454 ;
if ( V_56 . V_468 != 0 )
V_14 -> V_94 |= V_455 ;
if ( V_56 . V_469 != 0 )
V_14 -> V_94 |= V_456 ;
if ( V_56 . V_15 [ 0 ] & V_45 )
V_14 -> V_94 |= V_457 ;
if ( V_56 . V_15 [ 1 ] & V_378 )
V_14 -> V_94 |= V_458 ;
if ( V_56 . V_15 [ 1 ] & V_470 )
V_14 -> V_94 |= V_459 ;
if ( V_56 . V_15 [ 1 ] & V_471 )
V_14 -> V_94 |= V_460 ;
if ( V_56 . V_15 [ 1 ] & V_472 )
V_14 -> V_94 |= V_461 ;
if ( V_56 . V_15 [ 1 ] & V_372 )
V_14 -> V_94 |= V_462 ;
if ( V_56 . V_15 [ 1 ] & V_473 )
V_14 -> V_94 |= V_463 ;
if ( V_56 . V_15 [ 1 ] & V_375 )
V_14 -> V_94 |= V_464 ;
#ifdef F_273
if ( V_56 . V_15 [ 2 ] & V_380 )
V_14 -> V_94 |= V_9 ;
#endif
memcpy ( V_14 -> V_16 , V_56 . V_15 ,
sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_16 [ 2 ] &= ~ V_380 ;
memcpy ( V_14 -> V_435 , V_56 . V_15 , sizeof( V_14 -> V_435 ) ) ;
V_14 -> V_435 [ 0 ] &= V_474 | V_475 ;
V_14 -> V_435 [ 1 ] &= V_473 | V_375 ;
V_14 -> V_435 [ 2 ] = 0 ;
memcpy ( V_14 -> V_476 , V_56 . V_476 ,
sizeof( V_14 -> V_476 ) ) ;
V_14 -> V_466 = V_56 . V_466 ;
V_14 -> V_477 = V_56 . V_477 ;
}
return V_313 ;
}
int F_274 ( struct V_13 * V_14 , struct V_438 * V_439 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_31 ( V_14 ,
F_272 ( V_14 , V_439 ) ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_275 ( struct V_13 * V_14 , struct V_438 * V_439 ,
struct V_478 * V_479 )
{
T_1 V_248 [ 3 ] ;
struct V_480 args = {
. V_248 = V_248 ,
} ;
struct V_481 V_56 = {
. V_14 = V_14 ,
. V_400 = V_479 -> V_400 ,
. V_251 = V_439 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_482 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
V_248 [ 0 ] = V_250 [ 0 ] ;
V_248 [ 1 ] = V_250 [ 1 ] ;
V_248 [ 2 ] = V_250 [ 2 ] & ~ V_380 ;
F_90 ( V_479 -> V_400 ) ;
return F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
}
static int F_276 ( struct V_13 * V_14 , struct V_438 * V_439 ,
struct V_478 * V_479 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_275 ( V_14 , V_439 , V_479 ) ;
F_277 ( V_14 , V_439 , V_479 -> V_400 , V_8 ) ;
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
static int F_278 ( struct V_13 * V_14 , struct V_438 * V_439 ,
struct V_478 * V_479 , T_4 V_109 )
{
struct V_483 V_484 = {
. V_485 = V_109 ,
} ;
struct V_486 * V_487 ;
int V_51 ;
V_487 = F_279 ( & V_484 , V_14 -> V_98 ) ;
if ( F_51 ( V_487 ) ) {
V_51 = - V_29 ;
goto V_136;
}
V_51 = F_276 ( V_14 , V_439 , V_479 ) ;
V_136:
return V_51 ;
}
static int F_280 ( struct V_13 * V_14 , struct V_438 * V_439 ,
struct V_478 * V_479 )
{
static const T_4 V_488 [] = {
V_114 ,
V_113 ,
V_489 ,
V_490 ,
V_491 ,
} ;
int V_313 = - V_24 ;
T_9 V_492 ;
if ( V_14 -> V_493 . V_494 > 0 ) {
for ( V_492 = 0 ; V_492 < V_14 -> V_493 . V_494 ; V_492 ++ ) {
V_313 = F_278 ( V_14 , V_439 , V_479 ,
V_14 -> V_493 . V_495 [ V_492 ] ) ;
if ( V_313 == - V_22 || V_313 == - V_29 )
continue;
break;
}
} else {
for ( V_492 = 0 ; V_492 < F_281 ( V_488 ) ; V_492 ++ ) {
V_313 = F_278 ( V_14 , V_439 , V_479 ,
V_488 [ V_492 ] ) ;
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
struct V_438 * V_439 , struct V_478 * V_479 )
{
int V_496 = V_14 -> V_62 -> V_441 ;
return V_497 [ V_496 ] -> F_283 ( V_14 , V_439 , V_479 ) ;
}
int F_284 ( struct V_13 * V_14 , struct V_438 * V_439 ,
struct V_478 * V_479 ,
bool V_498 )
{
int V_313 = 0 ;
if ( ! V_498 )
V_313 = F_276 ( V_14 , V_439 , V_479 ) ;
if ( V_498 || V_313 == V_22 )
V_313 = F_282 ( V_14 , V_439 , V_479 ) ;
if ( V_313 == 0 )
V_313 = F_274 ( V_14 , V_439 ) ;
if ( V_313 == 0 )
V_313 = F_285 ( V_14 , V_439 , V_479 ) ;
return F_7 ( V_313 ) ;
}
static int F_286 ( struct V_13 * V_14 , struct V_438 * V_499 ,
struct V_478 * V_479 )
{
int error ;
struct V_399 * V_400 = V_479 -> V_400 ;
struct V_1 * V_7 = NULL ;
error = F_274 ( V_14 , V_499 ) ;
if ( error < 0 ) {
F_8 ( L_32 , - error ) ;
return error ;
}
V_7 = F_96 ( V_14 , V_390 ) ;
if ( F_51 ( V_7 ) )
return F_78 ( V_7 ) ;
error = F_204 ( V_14 , V_499 , V_400 , V_7 ) ;
if ( error < 0 ) {
F_8 ( L_33 , - error ) ;
goto V_230;
}
if ( V_400 -> V_304 & V_500 &&
! F_287 ( & V_14 -> V_501 , & V_400 -> V_501 ) )
memcpy ( & V_14 -> V_501 , & V_400 -> V_501 , sizeof( V_14 -> V_501 ) ) ;
V_230:
F_104 ( V_7 ) ;
return error ;
}
static int F_288 ( struct V_54 * V_98 , struct V_2 * V_3 ,
const struct V_502 * V_247 , struct V_399 * V_400 ,
struct V_438 * V_439 )
{
int V_313 = - V_132 ;
struct V_503 * V_503 = NULL ;
struct V_504 * V_505 = NULL ;
V_503 = F_289 ( V_390 ) ;
if ( V_503 == NULL )
goto V_136;
V_505 = F_290 ( sizeof( struct V_504 ) , V_390 ) ;
if ( V_505 == NULL )
goto V_136;
V_313 = F_291 ( V_98 , V_3 , V_247 , V_505 , V_503 ) ;
if ( V_313 != 0 )
goto V_136;
if ( F_287 ( & F_94 ( V_3 ) -> V_501 , & V_505 -> V_400 . V_501 ) ) {
F_8 ( L_34
L_35 , V_34 , V_247 -> V_247 ) ;
V_313 = - V_77 ;
goto V_136;
}
F_292 ( & V_505 -> V_400 ) ;
memcpy ( V_400 , & V_505 -> V_400 , sizeof( struct V_399 ) ) ;
memset ( V_439 , 0 , sizeof( struct V_438 ) ) ;
V_136:
if ( V_503 )
F_293 ( V_503 ) ;
F_105 ( V_505 ) ;
return V_313 ;
}
static int F_294 ( struct V_13 * V_14 , struct V_438 * V_439 ,
struct V_399 * V_400 , struct V_1 * V_7 )
{
struct V_506 args = {
. V_251 = V_439 ,
. V_248 = V_14 -> V_15 ,
} ;
struct V_507 V_56 = {
. V_400 = V_400 ,
. V_7 = V_7 ,
. V_14 = V_14 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_508 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
args . V_248 = F_6 ( V_14 , V_7 ) ;
F_90 ( V_400 ) ;
return F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
}
static int F_204 ( struct V_13 * V_14 , struct V_438 * V_439 ,
struct V_399 * V_400 , struct V_1 * V_7 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_294 ( V_14 , V_439 , V_400 , V_7 ) ;
F_295 ( V_14 , V_439 , V_400 , V_8 ) ;
V_8 = F_31 ( V_14 , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int
F_296 ( struct V_4 * V_4 , struct V_399 * V_400 ,
struct V_5 * V_6 )
{
struct V_2 * V_2 = F_14 ( V_4 ) ;
struct V_323 * V_357 = NULL ;
struct V_64 * V_65 = NULL ;
struct V_1 * V_7 = NULL ;
int V_313 ;
if ( F_297 ( V_2 ) &&
V_6 -> V_253 & V_409 &&
V_6 -> V_509 < F_298 ( V_2 ) )
F_299 ( V_2 ) ;
F_90 ( V_400 ) ;
if ( V_6 -> V_253 & V_418 )
V_6 -> V_253 &= ~ ( V_377 | V_510 ) ;
if ( ( V_6 -> V_253 & ~ ( V_511 | V_418 ) ) == 0 )
return 0 ;
if ( V_6 -> V_253 & V_511 ) {
struct V_307 * V_308 ;
V_308 = F_300 ( V_6 -> V_512 ) ;
if ( V_308 ) {
V_357 = V_308 -> V_357 ;
V_65 = V_308 -> V_65 ;
}
}
V_7 = F_96 ( F_94 ( V_2 ) , V_390 ) ;
if ( F_51 ( V_7 ) )
return F_78 ( V_7 ) ;
V_313 = F_241 ( V_2 , V_357 , V_400 , V_6 , V_65 , NULL , V_7 ) ;
if ( V_313 == 0 ) {
F_242 ( V_2 , V_6 , V_400 ) ;
F_243 ( V_2 , V_400 , V_7 ) ;
}
F_104 ( V_7 ) ;
return V_313 ;
}
static int F_301 ( struct V_54 * V_55 , struct V_2 * V_3 ,
const struct V_502 * V_247 , struct V_438 * V_439 ,
struct V_399 * V_400 , struct V_1 * V_7 )
{
struct V_13 * V_14 = F_94 ( V_3 ) ;
int V_313 ;
struct V_513 args = {
. V_248 = V_14 -> V_15 ,
. V_514 = F_102 ( V_3 ) ,
. V_247 = V_247 ,
} ;
struct V_481 V_56 = {
. V_14 = V_14 ,
. V_400 = V_400 ,
. V_7 = V_7 ,
. V_251 = V_439 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_515 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
args . V_248 = F_6 ( V_14 , V_7 ) ;
F_90 ( V_400 ) ;
F_8 ( L_36 , V_247 -> V_247 ) ;
V_313 = F_80 ( V_55 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
F_8 ( L_37 , V_313 ) ;
return V_313 ;
}
static void F_302 ( struct V_399 * V_400 )
{
V_400 -> V_304 |= V_342 | V_516 |
V_517 | V_518 ;
V_400 -> V_265 = V_347 | V_519 | V_520 ;
V_400 -> V_521 = 2 ;
}
static int F_303 ( struct V_54 * * V_55 , struct V_2 * V_3 ,
struct V_502 * V_247 , struct V_438 * V_439 ,
struct V_399 * V_400 , struct V_1 * V_7 )
{
struct V_60 V_61 = { } ;
struct V_54 * V_98 = * V_55 ;
int V_8 ;
do {
V_8 = F_301 ( V_98 , V_3 , V_247 , V_439 , V_400 , V_7 ) ;
F_304 ( V_3 , V_247 , V_8 ) ;
switch ( V_8 ) {
case - V_26 :
V_8 = - V_309 ;
goto V_136;
case - V_77 :
V_8 = F_288 ( V_98 , V_3 , V_247 , V_400 , V_439 ) ;
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
static int F_307 ( struct V_2 * V_3 , struct V_502 * V_247 ,
struct V_438 * V_439 , struct V_399 * V_400 ,
struct V_1 * V_7 )
{
int V_313 ;
struct V_54 * V_98 = F_308 ( V_3 ) ;
V_313 = F_303 ( & V_98 , V_3 , V_247 , V_439 , V_400 , V_7 ) ;
if ( V_98 != F_308 ( V_3 ) ) {
F_306 ( V_98 ) ;
F_302 ( V_400 ) ;
}
return V_313 ;
}
struct V_54 *
F_309 ( struct V_2 * V_3 , struct V_502 * V_247 ,
struct V_438 * V_439 , struct V_399 * V_400 )
{
struct V_54 * V_98 = F_308 ( V_3 ) ;
int V_313 ;
V_313 = F_303 ( & V_98 , V_3 , V_247 , V_439 , V_400 , NULL ) ;
if ( V_313 < 0 )
return F_52 ( V_313 ) ;
return ( V_98 == F_308 ( V_3 ) ) ? F_310 ( V_98 ) : V_98 ;
}
static int F_311 ( struct V_2 * V_2 , struct V_358 * V_522 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_523 args = {
. V_251 = F_102 ( V_2 ) ,
. V_248 = V_14 -> V_435 ,
} ;
struct V_524 V_56 = {
. V_14 = V_14 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_525 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_522 -> V_357 ,
} ;
int V_265 = V_522 -> V_360 ;
int V_313 = 0 ;
if ( V_265 & V_365 )
args . V_214 |= V_237 ;
if ( F_312 ( V_2 -> V_526 ) ) {
if ( V_265 & V_527 )
args . V_214 |= V_238 | V_239 | V_528 ;
if ( V_265 & V_363 )
args . V_214 |= V_529 ;
} else {
if ( V_265 & V_527 )
args . V_214 |= V_238 | V_239 ;
if ( V_265 & V_363 )
args . V_214 |= V_240 ;
}
V_56 . V_400 = F_313 () ;
if ( V_56 . V_400 == NULL )
return - V_132 ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
if ( ! V_313 ) {
F_201 ( V_522 , V_56 . V_214 ) ;
F_159 ( V_2 , V_56 . V_400 ) ;
}
F_314 ( V_56 . V_400 ) ;
return V_313 ;
}
static int F_315 ( struct V_2 * V_2 , struct V_358 * V_522 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_311 ( V_2 , V_522 ) ;
F_316 ( V_2 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_317 ( struct V_2 * V_2 , struct V_503 * V_503 ,
unsigned int V_48 , unsigned int V_530 )
{
struct V_531 args = {
. V_251 = F_102 ( V_2 ) ,
. V_48 = V_48 ,
. V_530 = V_530 ,
. V_42 = & V_503 ,
} ;
struct V_532 V_56 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_533 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
return F_80 ( F_94 ( V_2 ) -> V_98 , F_94 ( V_2 ) , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
}
static int F_318 ( struct V_2 * V_2 , struct V_503 * V_503 ,
unsigned int V_48 , unsigned int V_530 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_317 ( V_2 , V_503 , V_48 , V_530 ) ;
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
struct V_1 V_17 , * V_401 = NULL ;
struct V_307 * V_308 ;
struct V_64 * V_65 ;
int V_313 = 0 ;
V_308 = F_321 ( V_4 , V_190 ) ;
if ( F_51 ( V_308 ) )
return F_78 ( V_308 ) ;
V_401 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_322 () ;
V_65 = F_245 ( V_3 , V_308 , V_219 , V_6 , V_401 , NULL ) ;
if ( F_51 ( V_65 ) ) {
V_313 = F_78 ( V_65 ) ;
goto V_136;
}
V_136:
F_4 ( V_401 ) ;
F_180 ( V_308 ) ;
return V_313 ;
}
static int F_323 ( struct V_2 * V_3 , struct V_502 * V_247 )
{
struct V_13 * V_14 = F_94 ( V_3 ) ;
struct V_534 args = {
. V_251 = F_102 ( V_3 ) ,
. V_247 = * V_247 ,
} ;
struct V_535 V_56 = {
. V_14 = V_14 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_536 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
int V_313 ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 1 ) ;
if ( V_313 == 0 )
F_81 ( V_3 , & V_56 . V_175 ) ;
return V_313 ;
}
static int F_324 ( struct V_2 * V_3 , struct V_502 * V_247 )
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
struct V_534 * args = V_166 -> V_321 ;
struct V_535 * V_56 = V_166 -> V_322 ;
V_56 -> V_14 = V_14 ;
V_166 -> V_318 = & V_319 [ V_536 ] ;
F_46 ( & args -> V_163 , & V_56 -> V_164 , 1 ) ;
F_90 ( V_56 -> V_537 ) ;
}
static void F_327 ( struct V_102 * V_103 , struct V_538 * V_161 )
{
F_70 ( F_171 ( V_161 -> V_4 -> V_231 ) ,
& V_161 -> args . V_163 ,
& V_161 -> V_56 . V_164 ,
V_103 ) ;
}
static int F_328 ( struct V_102 * V_103 , struct V_2 * V_3 )
{
struct V_538 * V_161 = V_103 -> V_539 ;
struct V_535 * V_56 = & V_161 -> V_56 ;
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
struct V_540 * V_403 = V_166 -> V_321 ;
struct V_541 * V_56 = V_166 -> V_322 ;
V_166 -> V_318 = & V_319 [ V_542 ] ;
V_56 -> V_14 = V_14 ;
F_46 ( & V_403 -> V_163 , & V_56 -> V_164 , 1 ) ;
}
static void F_330 ( struct V_102 * V_103 , struct V_543 * V_161 )
{
F_70 ( F_94 ( V_161 -> V_544 ) ,
& V_161 -> args . V_163 ,
& V_161 -> V_56 . V_164 ,
V_103 ) ;
}
static int F_331 ( struct V_102 * V_103 , struct V_2 * V_544 ,
struct V_2 * V_545 )
{
struct V_543 * V_161 = V_103 -> V_539 ;
struct V_541 * V_56 = & V_161 -> V_56 ;
if ( ! F_67 ( V_103 , & V_56 -> V_164 ) )
return 0 ;
if ( F_38 ( V_103 , V_56 -> V_14 , NULL , & V_161 -> V_50 ) == - V_108 )
return 0 ;
F_81 ( V_544 , & V_56 -> V_546 ) ;
F_81 ( V_545 , & V_56 -> V_547 ) ;
return 1 ;
}
static int F_332 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_502 * V_247 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_548 V_403 = {
. V_251 = F_102 ( V_2 ) ,
. V_514 = F_102 ( V_3 ) ,
. V_247 = V_247 ,
. V_248 = V_14 -> V_15 ,
} ;
struct V_549 V_56 = {
. V_14 = V_14 ,
. V_7 = NULL ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_550 ] ,
. V_321 = & V_403 ,
. V_322 = & V_56 ,
} ;
int V_313 = - V_132 ;
V_56 . V_400 = F_313 () ;
if ( V_56 . V_400 == NULL )
goto V_136;
V_56 . V_7 = F_96 ( V_14 , V_390 ) ;
if ( F_51 ( V_56 . V_7 ) ) {
V_313 = F_78 ( V_56 . V_7 ) ;
goto V_136;
}
V_403 . V_248 = F_6 ( V_14 , V_56 . V_7 ) ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & V_403 . V_163 , & V_56 . V_164 , 1 ) ;
if ( ! V_313 ) {
F_81 ( V_3 , & V_56 . V_175 ) ;
V_313 = F_333 ( V_2 , V_56 . V_400 ) ;
if ( ! V_313 )
F_243 ( V_2 , V_56 . V_400 , V_56 . V_7 ) ;
}
F_104 ( V_56 . V_7 ) ;
V_136:
F_314 ( V_56 . V_400 ) ;
return V_313 ;
}
static int F_334 ( struct V_2 * V_2 , struct V_2 * V_3 , struct V_502 * V_247 )
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
static struct V_551 * F_335 ( struct V_2 * V_3 ,
struct V_502 * V_247 , struct V_5 * V_6 , T_1 V_552 )
{
struct V_551 * V_161 ;
V_161 = F_95 ( sizeof( * V_161 ) , V_390 ) ;
if ( V_161 != NULL ) {
struct V_13 * V_14 = F_94 ( V_3 ) ;
V_161 -> V_7 = F_96 ( V_14 , V_390 ) ;
if ( F_51 ( V_161 -> V_7 ) )
goto V_317;
V_161 -> V_166 . V_318 = & V_319 [ V_553 ] ;
V_161 -> V_166 . V_321 = & V_161 -> V_403 ;
V_161 -> V_166 . V_322 = & V_161 -> V_56 ;
V_161 -> V_403 . V_514 = F_102 ( V_3 ) ;
V_161 -> V_403 . V_14 = V_14 ;
V_161 -> V_403 . V_247 = V_247 ;
V_161 -> V_403 . V_220 = V_6 ;
V_161 -> V_403 . V_552 = V_552 ;
V_161 -> V_403 . V_248 = F_6 ( V_14 , V_161 -> V_7 ) ;
V_161 -> V_56 . V_14 = V_14 ;
V_161 -> V_56 . V_251 = & V_161 -> V_251 ;
V_161 -> V_56 . V_400 = & V_161 -> V_400 ;
V_161 -> V_56 . V_7 = V_161 -> V_7 ;
F_90 ( V_161 -> V_56 . V_400 ) ;
}
return V_161 ;
V_317:
F_105 ( V_161 ) ;
return NULL ;
}
static int F_336 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_551 * V_161 )
{
int V_313 = F_80 ( F_94 ( V_3 ) -> V_98 , F_94 ( V_3 ) , & V_161 -> V_166 ,
& V_161 -> V_403 . V_163 , & V_161 -> V_56 . V_164 , 1 ) ;
if ( V_313 == 0 ) {
F_81 ( V_3 , & V_161 -> V_56 . V_554 ) ;
V_313 = F_337 ( V_4 , V_161 -> V_56 . V_251 , V_161 -> V_56 . V_400 , V_161 -> V_56 . V_7 ) ;
}
return V_313 ;
}
static void F_338 ( struct V_551 * V_161 )
{
F_104 ( V_161 -> V_7 ) ;
F_105 ( V_161 ) ;
}
static int F_339 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_503 * V_503 , unsigned int V_12 , struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_551 * V_161 ;
int V_313 = - V_555 ;
if ( V_12 > V_556 )
goto V_136;
V_313 = - V_132 ;
V_161 = F_335 ( V_3 , & V_4 -> V_11 , V_6 , V_557 ) ;
if ( V_161 == NULL )
goto V_136;
V_161 -> V_166 . V_318 = & V_319 [ V_558 ] ;
V_161 -> V_403 . V_255 . V_559 . V_42 = & V_503 ;
V_161 -> V_403 . V_255 . V_559 . V_12 = V_12 ;
V_161 -> V_403 . V_7 = V_7 ;
V_313 = F_336 ( V_3 , V_4 , V_161 ) ;
F_338 ( V_161 ) ;
V_136:
return V_313 ;
}
static int F_340 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_503 * V_503 , unsigned int V_12 , struct V_5 * V_6 )
{
struct V_60 V_61 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
do {
V_8 = F_339 ( V_3 , V_4 , V_503 , V_12 , V_6 , V_7 ) ;
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
struct V_551 * V_161 ;
int V_313 = - V_132 ;
V_161 = F_335 ( V_3 , & V_4 -> V_11 , V_6 , V_560 ) ;
if ( V_161 == NULL )
goto V_136;
V_161 -> V_403 . V_7 = V_7 ;
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
T_2 V_36 , struct V_503 * * V_42 , unsigned int V_49 , int V_561 )
{
struct V_2 * V_3 = F_14 ( V_4 ) ;
struct V_38 args = {
. V_251 = F_102 ( V_3 ) ,
. V_42 = V_42 ,
. V_48 = 0 ,
. V_49 = V_49 ,
. V_248 = F_94 ( F_14 ( V_4 ) ) -> V_15 ,
. V_561 = V_561 ,
} ;
struct V_562 V_56 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_563 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
int V_313 ;
F_8 ( L_38 , V_34 ,
V_4 ,
( unsigned long long ) V_36 ) ;
F_9 ( V_36 , F_82 ( V_3 ) -> V_564 , V_4 , & args ) ;
V_56 . V_48 = args . V_48 ;
V_313 = F_80 ( F_94 ( V_3 ) -> V_98 , F_94 ( V_3 ) , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
if ( V_313 >= 0 ) {
memcpy ( F_82 ( V_3 ) -> V_564 , V_56 . V_37 . V_161 , V_565 ) ;
V_313 += args . V_48 ;
}
F_346 ( V_3 ) ;
F_8 ( L_39 , V_34 , V_313 ) ;
return V_313 ;
}
static int F_347 ( struct V_4 * V_4 , struct V_323 * V_357 ,
T_2 V_36 , struct V_503 * * V_42 , unsigned int V_49 , int V_561 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_345 ( V_4 , V_357 , V_36 ,
V_42 , V_49 , V_561 ) ;
F_348 ( F_14 ( V_4 ) , V_8 ) ;
V_8 = F_31 ( F_94 ( F_14 ( V_4 ) ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_349 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 , T_10 V_566 )
{
struct V_551 * V_161 ;
int V_265 = V_6 -> V_10 ;
int V_313 = - V_132 ;
V_161 = F_335 ( V_3 , & V_4 -> V_11 , V_6 , V_567 ) ;
if ( V_161 == NULL )
goto V_136;
if ( F_350 ( V_265 ) )
V_161 -> V_403 . V_552 = V_568 ;
else if ( F_351 ( V_265 ) ) {
V_161 -> V_403 . V_552 = V_569 ;
V_161 -> V_403 . V_255 . V_570 . V_571 = F_352 ( V_566 ) ;
V_161 -> V_403 . V_255 . V_570 . V_572 = F_353 ( V_566 ) ;
}
else if ( F_354 ( V_265 ) ) {
V_161 -> V_403 . V_552 = V_573 ;
V_161 -> V_403 . V_255 . V_570 . V_571 = F_352 ( V_566 ) ;
V_161 -> V_403 . V_255 . V_570 . V_572 = F_353 ( V_566 ) ;
} else if ( ! F_355 ( V_265 ) ) {
V_313 = - V_27 ;
goto V_317;
}
V_161 -> V_403 . V_7 = V_7 ;
V_313 = F_336 ( V_3 , V_4 , V_161 ) ;
V_317:
F_338 ( V_161 ) ;
V_136:
return V_313 ;
}
static int F_356 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , T_10 V_566 )
{
struct V_60 V_61 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
V_6 -> V_10 &= ~ F_322 () ;
do {
V_8 = F_349 ( V_3 , V_4 , V_6 , V_7 , V_566 ) ;
F_357 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_358 ( struct V_13 * V_14 , struct V_438 * V_439 ,
struct V_574 * V_575 )
{
struct V_576 args = {
. V_251 = V_439 ,
. V_248 = V_14 -> V_15 ,
} ;
struct V_577 V_56 = {
. V_575 = V_575 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_578 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
F_90 ( V_575 -> V_400 ) ;
return F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
}
static int F_359 ( struct V_13 * V_14 , struct V_438 * V_439 , struct V_574 * V_575 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_31 ( V_14 ,
F_358 ( V_14 , V_439 , V_575 ) ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_360 ( struct V_13 * V_14 , struct V_438 * V_439 ,
struct V_478 * V_579 )
{
struct V_580 args = {
. V_251 = V_439 ,
. V_248 = V_14 -> V_15 ,
} ;
struct V_581 V_56 = {
. V_579 = V_579 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_582 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
return F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
}
static int F_285 ( struct V_13 * V_14 , struct V_438 * V_439 , struct V_478 * V_579 )
{
struct V_60 V_61 = { } ;
unsigned long V_583 = V_157 ;
int V_8 ;
do {
V_8 = F_360 ( V_14 , V_439 , V_579 ) ;
F_361 ( V_14 , V_439 , V_579 -> V_400 , V_8 ) ;
if ( V_8 == 0 ) {
struct V_62 * V_63 = V_14 -> V_62 ;
F_41 ( & V_63 -> V_116 ) ;
V_63 -> V_584 = V_579 -> V_585 * V_88 ;
V_63 -> V_117 = V_583 ;
F_43 ( & V_63 -> V_116 ) ;
break;
}
V_8 = F_31 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_362 ( struct V_13 * V_14 , struct V_438 * V_439 , struct V_478 * V_579 )
{
int error ;
F_90 ( V_579 -> V_400 ) ;
error = F_285 ( V_14 , V_439 , V_579 ) ;
if ( error == 0 ) {
V_14 -> V_586 = V_579 -> V_587 ;
F_363 ( V_14 , V_439 , V_579 -> V_588 ) ;
}
return error ;
}
static int F_364 ( struct V_13 * V_14 , struct V_438 * V_439 ,
struct V_589 * V_590 )
{
struct V_591 args = {
. V_251 = V_439 ,
. V_248 = V_14 -> V_15 ,
} ;
struct V_592 V_56 = {
. V_590 = V_590 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_593 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
if ( ( args . V_248 [ 0 ] & V_594 [ 0 ] ) == 0 ) {
memset ( V_590 , 0 , sizeof( * V_590 ) ) ;
return 0 ;
}
F_90 ( V_590 -> V_400 ) ;
return F_80 ( V_14 -> V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
}
static int F_365 ( struct V_13 * V_14 , struct V_438 * V_439 ,
struct V_589 * V_590 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_31 ( V_14 ,
F_364 ( V_14 , V_439 , V_590 ) ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
int F_366 ( T_8 * V_257 ,
const struct V_307 * V_308 ,
const struct V_595 * V_596 ,
T_5 V_188 )
{
const struct V_410 * V_411 = NULL ;
if ( V_596 != NULL )
V_411 = & V_596 -> V_411 ;
return F_251 ( V_308 -> V_65 , V_188 , V_411 , V_257 , NULL ) ;
}
static bool F_367 ( T_8 * V_257 ,
const struct V_307 * V_308 ,
const struct V_595 * V_596 ,
T_5 V_188 )
{
T_8 V_597 ;
if ( F_366 ( & V_597 , V_308 , V_596 , V_188 ) == - V_35 )
return true ;
return F_146 ( V_257 , & V_597 ) ;
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
void F_369 ( struct V_598 * V_599 )
{
F_346 ( V_599 -> V_2 ) ;
}
static int F_370 ( struct V_102 * V_103 , struct V_598 * V_599 )
{
struct V_13 * V_14 = F_94 ( V_599 -> V_2 ) ;
F_371 ( V_599 , V_103 -> V_107 ) ;
if ( F_38 ( V_103 , V_14 ,
V_599 -> args . V_600 -> V_65 ,
NULL ) == - V_108 ) {
F_65 ( V_103 ) ;
return - V_108 ;
}
F_369 ( V_599 ) ;
if ( V_103 -> V_107 > 0 )
F_44 ( V_14 , V_599 -> V_115 ) ;
return 0 ;
}
static bool F_372 ( struct V_102 * V_103 ,
struct V_601 * args )
{
if ( ! F_368 ( V_103 -> V_107 ) ||
F_367 ( & args -> V_257 ,
args -> V_600 ,
args -> V_602 ,
V_190 ) )
return false ;
F_65 ( V_103 ) ;
return true ;
}
static int F_373 ( struct V_102 * V_103 , struct V_598 * V_599 )
{
F_8 ( L_11 , V_34 ) ;
if ( ! F_67 ( V_103 , & V_599 -> V_56 . V_164 ) )
return - V_108 ;
if ( F_372 ( V_103 , & V_599 -> args ) )
return - V_108 ;
return V_599 -> V_603 ? V_599 -> V_603 ( V_103 , V_599 ) :
F_370 ( V_103 , V_599 ) ;
}
static void F_374 ( struct V_598 * V_599 ,
struct V_165 * V_166 )
{
V_599 -> V_115 = V_157 ;
V_599 -> V_603 = F_370 ;
V_166 -> V_318 = & V_319 [ V_604 ] ;
F_46 ( & V_599 -> args . V_163 , & V_599 -> V_56 . V_164 , 0 ) ;
}
static int F_375 ( struct V_102 * V_103 ,
struct V_598 * V_599 )
{
if ( F_70 ( F_94 ( V_599 -> V_2 ) ,
& V_599 -> args . V_163 ,
& V_599 -> V_56 . V_164 ,
V_103 ) )
return 0 ;
if ( F_366 ( & V_599 -> args . V_257 , V_599 -> args . V_600 ,
V_599 -> args . V_602 ,
V_599 -> V_605 -> V_606 ) == - V_35 )
return - V_35 ;
if ( F_376 ( F_33 ( V_607 , & V_599 -> args . V_600 -> V_219 ) ) )
return - V_35 ;
return 0 ;
}
static int F_377 ( struct V_102 * V_103 ,
struct V_598 * V_599 )
{
struct V_2 * V_2 = V_599 -> V_2 ;
F_378 ( V_599 , V_103 -> V_107 ) ;
if ( F_38 ( V_103 , F_94 ( V_2 ) ,
V_599 -> args . V_600 -> V_65 ,
NULL ) == - V_108 ) {
F_65 ( V_103 ) ;
return - V_108 ;
}
if ( V_103 -> V_107 >= 0 ) {
F_44 ( F_94 ( V_2 ) , V_599 -> V_115 ) ;
F_379 ( V_599 ) ;
}
return 0 ;
}
static bool F_380 ( struct V_102 * V_103 ,
struct V_601 * args )
{
if ( ! F_368 ( V_103 -> V_107 ) ||
F_367 ( & args -> V_257 ,
args -> V_600 ,
args -> V_602 ,
V_191 ) )
return false ;
F_65 ( V_103 ) ;
return true ;
}
static int F_381 ( struct V_102 * V_103 , struct V_598 * V_599 )
{
if ( ! F_67 ( V_103 , & V_599 -> V_56 . V_164 ) )
return - V_108 ;
if ( F_380 ( V_103 , & V_599 -> args ) )
return - V_108 ;
return V_599 -> V_603 ? V_599 -> V_603 ( V_103 , V_599 ) :
F_377 ( V_103 , V_599 ) ;
}
static
bool F_382 ( struct V_598 * V_599 )
{
if ( V_599 -> V_608 != NULL || V_599 -> V_609 != NULL )
return false ;
return F_383 ( V_599 -> V_2 , V_190 ) == 0 ;
}
static void F_384 ( struct V_598 * V_599 ,
struct V_165 * V_166 )
{
struct V_13 * V_14 = F_94 ( V_599 -> V_2 ) ;
if ( ! F_382 ( V_599 ) ) {
V_599 -> args . V_248 = NULL ;
V_599 -> V_56 . V_400 = NULL ;
} else
V_599 -> args . V_248 = V_14 -> V_435 ;
if ( ! V_599 -> V_603 )
V_599 -> V_603 = F_377 ;
V_599 -> V_56 . V_14 = V_14 ;
V_599 -> V_115 = V_157 ;
V_166 -> V_318 = & V_319 [ V_610 ] ;
F_46 ( & V_599 -> args . V_163 , & V_599 -> V_56 . V_164 , 1 ) ;
}
static void F_385 ( struct V_102 * V_103 , struct V_611 * V_161 )
{
F_70 ( F_94 ( V_161 -> V_2 ) ,
& V_161 -> args . V_163 ,
& V_161 -> V_56 . V_164 ,
V_103 ) ;
}
static int F_386 ( struct V_102 * V_103 , struct V_611 * V_161 )
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
static int F_388 ( struct V_102 * V_103 , struct V_611 * V_161 )
{
if ( ! F_67 ( V_103 , & V_161 -> V_56 . V_164 ) )
return - V_108 ;
return V_161 -> V_612 ( V_103 , V_161 ) ;
}
static void F_389 ( struct V_611 * V_161 , struct V_165 * V_166 )
{
struct V_13 * V_14 = F_94 ( V_161 -> V_2 ) ;
if ( V_161 -> V_612 == NULL )
V_161 -> V_612 = F_386 ;
V_161 -> V_56 . V_14 = V_14 ;
V_166 -> V_318 = & V_319 [ V_613 ] ;
F_46 ( & V_161 -> args . V_163 , & V_161 -> V_56 . V_164 , 1 ) ;
}
static void F_390 ( void * V_159 )
{
struct V_614 * V_161 = V_159 ;
struct V_62 * V_63 = V_161 -> V_98 ;
if ( F_391 ( & V_63 -> V_615 ) > 1 )
F_392 ( V_63 ) ;
F_393 ( V_63 ) ;
F_105 ( V_161 ) ;
}
static void F_394 ( struct V_102 * V_103 , void * V_159 )
{
struct V_614 * V_161 = V_159 ;
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
if ( F_33 ( V_616 , & V_63 -> V_617 ) == 0 )
return;
if ( V_103 -> V_107 != V_618 ) {
F_24 ( V_63 ) ;
return;
}
F_396 ( V_63 ) ;
}
F_40 ( V_63 , V_115 ) ;
}
static int F_397 ( struct V_62 * V_63 , struct V_323 * V_357 , unsigned V_619 )
{
struct V_165 V_166 = {
. V_318 = & V_319 [ V_620 ] ,
. V_321 = V_63 ,
. V_323 = V_357 ,
} ;
struct V_614 * V_161 ;
if ( V_619 == 0 )
return 0 ;
if ( ! F_398 ( & V_63 -> V_615 ) )
return - V_35 ;
V_161 = F_290 ( sizeof( * V_161 ) , V_310 ) ;
if ( V_161 == NULL )
return - V_132 ;
V_161 -> V_98 = V_63 ;
V_161 -> V_115 = V_157 ;
return F_399 ( V_63 -> V_110 , & V_166 , V_621 ,
& V_622 , V_161 ) ;
}
static int F_400 ( struct V_62 * V_63 , struct V_323 * V_357 )
{
struct V_165 V_166 = {
. V_318 = & V_319 [ V_620 ] ,
. V_321 = V_63 ,
. V_323 = V_357 ,
} ;
unsigned long V_583 = V_157 ;
int V_313 ;
V_313 = F_401 ( V_63 -> V_110 , & V_166 , V_621 ) ;
if ( V_313 < 0 )
return V_313 ;
F_40 ( V_63 , V_583 ) ;
return 0 ;
}
static inline int F_402 ( struct V_13 * V_14 )
{
return V_14 -> V_94 & V_454 ;
}
static int F_403 ( const void * V_623 , T_9 V_624 ,
struct V_503 * * V_42 )
{
struct V_503 * V_625 , * * V_626 ;
int V_627 = 0 ;
T_9 V_12 ;
V_626 = V_42 ;
do {
V_12 = F_404 ( T_9 , V_628 , V_624 ) ;
V_625 = F_289 ( V_390 ) ;
if ( V_625 == NULL )
goto V_629;
memcpy ( F_405 ( V_625 ) , V_623 , V_12 ) ;
V_623 += V_12 ;
V_624 -= V_12 ;
* V_42 ++ = V_625 ;
V_627 ++ ;
} while ( V_624 != 0 );
return V_627 ;
V_629:
for(; V_627 > 0 ; V_627 -- )
F_293 ( V_626 [ V_627 - 1 ] ) ;
return - V_132 ;
}
static void F_406 ( struct V_2 * V_2 , struct V_630 * V_631 )
{
struct V_176 * V_177 = F_82 ( V_2 ) ;
F_41 ( & V_2 -> V_178 ) ;
F_105 ( V_177 -> V_632 ) ;
V_177 -> V_632 = V_631 ;
F_43 ( & V_2 -> V_178 ) ;
}
static void F_407 ( struct V_2 * V_2 )
{
F_406 ( V_2 , NULL ) ;
}
static inline T_11 F_408 ( struct V_2 * V_2 , char * V_623 , T_9 V_624 )
{
struct V_176 * V_177 = F_82 ( V_2 ) ;
struct V_630 * V_631 ;
int V_51 = - V_309 ;
F_41 ( & V_2 -> V_178 ) ;
V_631 = V_177 -> V_632 ;
if ( V_631 == NULL )
goto V_136;
if ( V_623 == NULL )
goto V_633;
if ( V_631 -> V_634 == 0 )
goto V_136;
V_51 = - V_635 ;
if ( V_631 -> V_12 > V_624 )
goto V_136;
memcpy ( V_623 , V_631 -> V_161 , V_631 -> V_12 ) ;
V_633:
V_51 = V_631 -> V_12 ;
V_136:
F_43 ( & V_2 -> V_178 ) ;
return V_51 ;
}
static void F_409 ( struct V_2 * V_2 , struct V_503 * * V_42 , T_9 V_48 , T_9 V_636 )
{
struct V_630 * V_631 ;
T_9 V_624 = sizeof( * V_631 ) + V_636 ;
if ( V_624 <= V_628 ) {
V_631 = F_290 ( V_624 , V_390 ) ;
if ( V_631 == NULL )
goto V_136;
V_631 -> V_634 = 1 ;
F_410 ( V_631 -> V_161 , V_42 , V_48 , V_636 ) ;
} else {
V_631 = F_290 ( sizeof( * V_631 ) , V_390 ) ;
if ( V_631 == NULL )
goto V_136;
V_631 -> V_634 = 0 ;
}
V_631 -> V_12 = V_636 ;
V_136:
F_406 ( V_2 , V_631 ) ;
}
static T_11 F_411 ( struct V_2 * V_2 , void * V_623 , T_9 V_624 )
{
struct V_503 * V_42 [ V_637 ] = { NULL , } ;
struct V_638 args = {
. V_251 = F_102 ( V_2 ) ,
. V_639 = V_42 ,
. V_636 = V_624 ,
} ;
struct V_640 V_56 = {
. V_636 = V_624 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_641 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
unsigned int V_642 = F_412 ( V_624 , V_628 ) ;
int V_51 = - V_132 , V_492 ;
if ( V_642 == 0 )
V_642 = 1 ;
if ( V_642 > F_281 ( V_42 ) )
return - V_635 ;
for ( V_492 = 0 ; V_492 < V_642 ; V_492 ++ ) {
V_42 [ V_492 ] = F_289 ( V_390 ) ;
if ( ! V_42 [ V_492 ] )
goto V_317;
}
V_56 . V_643 = F_289 ( V_390 ) ;
if ( ! V_56 . V_643 )
goto V_317;
args . V_636 = V_642 * V_628 ;
F_8 ( L_40 ,
V_34 , V_623 , V_624 , V_642 , args . V_636 ) ;
V_51 = F_80 ( F_94 ( V_2 ) -> V_98 , F_94 ( V_2 ) ,
& V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
if ( V_51 )
goto V_317;
if ( V_56 . V_644 & V_645 ) {
if ( V_623 == NULL )
goto V_646;
V_51 = - V_635 ;
goto V_317;
}
F_409 ( V_2 , V_42 , V_56 . V_647 , V_56 . V_636 ) ;
if ( V_623 ) {
if ( V_56 . V_636 > V_624 ) {
V_51 = - V_635 ;
goto V_317;
}
F_410 ( V_623 , V_42 , V_56 . V_647 , V_56 . V_636 ) ;
}
V_646:
V_51 = V_56 . V_636 ;
V_317:
for ( V_492 = 0 ; V_492 < V_642 ; V_492 ++ )
if ( V_42 [ V_492 ] )
F_293 ( V_42 [ V_492 ] ) ;
if ( V_56 . V_643 )
F_293 ( V_56 . V_643 ) ;
return V_51 ;
}
static T_11 F_413 ( struct V_2 * V_2 , void * V_623 , T_9 V_624 )
{
struct V_60 V_61 = { } ;
T_11 V_51 ;
do {
V_51 = F_411 ( V_2 , V_623 , V_624 ) ;
F_414 ( V_2 , V_51 ) ;
if ( V_51 >= 0 )
break;
V_51 = F_31 ( F_94 ( V_2 ) , V_51 , & V_61 ) ;
} while ( V_61 . V_68 );
return V_51 ;
}
static T_11 F_415 ( struct V_2 * V_2 , void * V_623 , T_9 V_624 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
int V_51 ;
if ( ! F_402 ( V_14 ) )
return - V_648 ;
V_51 = F_416 ( V_14 , V_2 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( F_82 ( V_2 ) -> V_179 & V_649 )
F_417 ( V_2 ) ;
V_51 = F_408 ( V_2 , V_623 , V_624 ) ;
if ( V_51 != - V_309 )
return V_51 ;
return F_413 ( V_2 , V_623 , V_624 ) ;
}
static int F_418 ( struct V_2 * V_2 , const void * V_623 , T_9 V_624 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_503 * V_42 [ V_637 ] ;
struct V_650 V_403 = {
. V_251 = F_102 ( V_2 ) ,
. V_639 = V_42 ,
. V_636 = V_624 ,
} ;
struct V_651 V_56 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_652 ] ,
. V_321 = & V_403 ,
. V_322 = & V_56 ,
} ;
unsigned int V_642 = F_412 ( V_624 , V_628 ) ;
int V_51 , V_492 ;
if ( ! F_402 ( V_14 ) )
return - V_648 ;
if ( V_642 > F_281 ( V_42 ) )
return - V_635 ;
V_492 = F_403 ( V_623 , V_624 , V_403 . V_639 ) ;
if ( V_492 < 0 )
return V_492 ;
F_150 ( V_2 ) ;
V_51 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & V_403 . V_163 , & V_56 . V_164 , 1 ) ;
for (; V_492 > 0 ; V_492 -- )
F_419 ( V_42 [ V_492 - 1 ] ) ;
F_41 ( & V_2 -> V_178 ) ;
F_82 ( V_2 ) -> V_179 |= V_180 ;
F_43 ( & V_2 -> V_178 ) ;
F_420 ( V_2 ) ;
F_417 ( V_2 ) ;
return V_51 ;
}
static int F_421 ( struct V_2 * V_2 , const void * V_623 , T_9 V_624 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_418 ( V_2 , V_623 , V_624 ) ;
F_422 ( V_2 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_423 ( struct V_2 * V_2 , void * V_623 ,
T_9 V_624 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_399 V_400 ;
struct V_1 V_7 = { 0 , 0 , V_624 , V_623 } ;
T_1 V_248 [ 3 ] = { 0 , 0 , V_380 } ;
struct V_506 V_403 = {
. V_251 = F_102 ( V_2 ) ,
. V_248 = V_248 ,
} ;
struct V_507 V_56 = {
. V_400 = & V_400 ,
. V_7 = & V_7 ,
. V_14 = V_14 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_508 ] ,
. V_321 = & V_403 ,
. V_322 = & V_56 ,
} ;
int V_51 ;
F_90 ( & V_400 ) ;
V_51 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & V_403 . V_163 , & V_56 . V_164 , 0 ) ;
if ( V_51 )
return V_51 ;
if ( ! ( V_400 . V_304 & V_653 ) )
return - V_309 ;
if ( V_624 < V_7 . V_12 )
return - V_635 ;
return 0 ;
}
static int F_424 ( struct V_2 * V_2 , void * V_623 ,
T_9 V_624 )
{
struct V_60 V_61 = { } ;
int V_8 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_648 ;
do {
V_8 = F_423 ( V_2 , V_623 , V_624 ) ;
F_425 ( V_2 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_426 ( struct V_2 * V_2 ,
struct V_1 * V_401 ,
struct V_399 * V_400 ,
struct V_1 * V_389 )
{
struct V_5 V_6 = { 0 } ;
struct V_13 * V_14 = F_94 ( V_2 ) ;
const T_1 V_248 [ 3 ] = { 0 , 0 , V_380 } ;
struct V_402 V_403 = {
. V_251 = F_102 ( V_2 ) ,
. V_404 = & V_6 ,
. V_14 = V_14 ,
. V_248 = V_248 ,
. V_7 = V_401 ,
} ;
struct V_405 V_56 = {
. V_400 = V_400 ,
. V_7 = V_389 ,
. V_14 = V_14 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_406 ] ,
. V_321 = & V_403 ,
. V_322 = & V_56 ,
} ;
int V_313 ;
F_136 ( & V_403 . V_257 , & V_417 ) ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & V_403 . V_163 , & V_56 . V_164 , 1 ) ;
if ( V_313 )
F_8 ( L_41 , V_34 , V_313 ) ;
return V_313 ;
}
static int F_427 ( struct V_2 * V_2 ,
struct V_1 * V_401 ,
struct V_399 * V_400 ,
struct V_1 * V_389 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_426 ( V_2 , V_401 ,
V_400 , V_389 ) ;
F_428 ( V_2 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int
F_429 ( struct V_2 * V_2 , const void * V_623 , T_9 V_624 )
{
struct V_1 V_401 , * V_389 = NULL ;
struct V_399 V_400 ;
struct V_323 * V_357 ;
int V_313 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_648 ;
F_90 ( & V_400 ) ;
V_401 . V_654 = 0 ;
V_401 . V_655 = 0 ;
V_401 . V_7 = ( char * ) V_623 ;
V_401 . V_12 = V_624 ;
V_357 = F_430 () ;
if ( F_51 ( V_357 ) )
return F_78 ( V_357 ) ;
V_389 = F_96 ( F_94 ( V_2 ) , V_390 ) ;
if ( F_51 ( V_389 ) ) {
V_313 = - F_78 ( V_389 ) ;
goto V_136;
}
V_313 = F_427 ( V_2 , & V_401 , & V_400 , V_389 ) ;
if ( V_313 == 0 )
F_243 ( V_2 , & V_400 , V_389 ) ;
F_104 ( V_389 ) ;
V_136:
F_222 ( V_357 ) ;
return V_313 ;
}
static void F_431 ( const struct V_62 * V_63 ,
T_12 * V_656 )
{
T_3 V_254 [ 2 ] ;
if ( F_33 ( V_657 , & V_63 -> V_106 ) ) {
V_254 [ 0 ] = 0 ;
V_254 [ 1 ] = F_432 ( V_658 + 1 ) ;
} else {
struct V_659 * V_660 = F_433 ( V_63 -> V_661 , V_662 ) ;
V_254 [ 0 ] = F_432 ( V_660 -> V_663 . V_664 ) ;
V_254 [ 1 ] = F_432 ( V_660 -> V_663 . V_665 ) ;
}
memcpy ( V_656 -> V_161 , V_254 , sizeof( V_656 -> V_161 ) ) ;
}
static int
F_434 ( struct V_62 * V_63 )
{
T_9 V_12 ;
char * V_666 ;
if ( V_63 -> V_667 != NULL )
return 0 ;
F_144 () ;
V_12 = 14 + strlen ( V_63 -> V_668 ) + 1 +
strlen ( F_435 ( V_63 -> V_110 , V_669 ) ) +
1 +
strlen ( F_435 ( V_63 -> V_110 , V_670 ) ) +
1 ;
F_147 () ;
if ( V_12 > V_671 + 1 )
return - V_27 ;
V_666 = F_290 ( V_12 , V_390 ) ;
if ( ! V_666 )
return - V_132 ;
F_144 () ;
F_436 ( V_666 , V_12 , L_42 ,
V_63 -> V_668 ,
F_435 ( V_63 -> V_110 , V_669 ) ,
F_435 ( V_63 -> V_110 , V_670 ) ) ;
F_147 () ;
V_63 -> V_667 = V_666 ;
return 0 ;
}
static int
F_437 ( struct V_62 * V_63 )
{
T_9 V_12 ;
char * V_666 ;
V_12 = 10 + 10 + 1 + 10 + 1 +
strlen ( V_672 ) + 1 +
strlen ( V_63 -> V_110 -> V_673 ) + 1 ;
if ( V_12 > V_671 + 1 )
return - V_27 ;
V_666 = F_290 ( V_12 , V_390 ) ;
if ( ! V_666 )
return - V_132 ;
F_436 ( V_666 , V_12 , L_43 ,
V_63 -> V_674 -> V_675 , V_63 -> V_441 ,
V_672 ,
V_63 -> V_110 -> V_673 ) ;
V_63 -> V_667 = V_666 ;
return 0 ;
}
static int
F_438 ( struct V_62 * V_63 )
{
T_9 V_12 ;
char * V_666 ;
if ( V_63 -> V_667 != NULL )
return 0 ;
if ( V_672 [ 0 ] != '\0' )
return F_437 ( V_63 ) ;
V_12 = 10 + 10 + 1 + 10 + 1 +
strlen ( V_63 -> V_110 -> V_673 ) + 1 ;
if ( V_12 > V_671 + 1 )
return - V_27 ;
V_666 = F_290 ( V_12 , V_390 ) ;
if ( ! V_666 )
return - V_132 ;
F_436 ( V_666 , V_12 , L_44 ,
V_63 -> V_674 -> V_675 , V_63 -> V_441 ,
V_63 -> V_110 -> V_673 ) ;
V_63 -> V_667 = V_666 ;
return 0 ;
}
static unsigned int
F_439 ( const struct V_62 * V_63 , char * V_623 , T_9 V_12 )
{
if ( strchr ( V_63 -> V_668 , ':' ) != NULL )
return F_436 ( V_623 , V_12 , L_45 ) ;
else
return F_436 ( V_623 , V_12 , L_46 ) ;
}
static void F_440 ( struct V_102 * V_103 , void * V_159 )
{
struct V_676 * V_677 = V_159 ;
if ( V_103 -> V_107 == 0 )
V_677 -> V_678 = F_218 ( V_103 -> V_679 -> V_680 ) ;
}
int F_441 ( struct V_62 * V_63 , T_1 V_681 ,
unsigned short V_682 , struct V_323 * V_357 ,
struct V_683 * V_56 )
{
T_12 V_684 ;
struct V_676 V_685 = {
. V_684 = & V_684 ,
. V_686 = V_681 ,
. V_687 = V_63 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_688 ] ,
. V_321 = & V_685 ,
. V_322 = V_56 ,
. V_323 = V_357 ,
} ;
struct V_102 * V_103 ;
struct V_167 V_324 = {
. V_169 = V_63 -> V_110 ,
. V_165 = & V_166 ,
. V_170 = & V_689 ,
. V_173 = & V_685 ,
. V_219 = V_621 ,
} ;
int V_313 ;
F_431 ( V_63 , & V_684 ) ;
if ( F_33 ( V_690 , & V_63 -> V_691 ) )
V_313 = F_438 ( V_63 ) ;
else
V_313 = F_434 ( V_63 ) ;
if ( V_313 )
goto V_136;
V_685 . V_692 =
F_439 ( V_63 ,
V_685 . V_693 ,
sizeof( V_685 . V_693 ) ) ;
V_685 . V_694 = F_436 ( V_685 . V_695 ,
sizeof( V_685 . V_695 ) , L_47 ,
V_63 -> V_668 , V_682 >> 8 , V_682 & 255 ) ;
F_8 ( L_48 ,
V_63 -> V_110 -> V_111 -> V_696 -> V_697 ,
V_63 -> V_667 ) ;
V_103 = F_77 ( & V_324 ) ;
if ( F_51 ( V_103 ) ) {
V_313 = F_78 ( V_103 ) ;
goto V_136;
}
V_313 = V_103 -> V_107 ;
if ( V_685 . V_678 ) {
V_63 -> V_698 = F_442 ( V_685 . V_678 ) ;
F_222 ( V_685 . V_678 ) ;
}
F_79 ( V_103 ) ;
V_136:
F_443 ( V_63 , V_313 ) ;
F_8 ( L_49 , V_313 ) ;
return V_313 ;
}
int F_444 ( struct V_62 * V_63 ,
struct V_683 * V_403 ,
struct V_323 * V_357 )
{
struct V_165 V_166 = {
. V_318 = & V_319 [ V_699 ] ,
. V_321 = V_403 ,
. V_323 = V_357 ,
} ;
int V_313 ;
F_8 ( L_50 ,
V_63 -> V_110 -> V_111 -> V_696 -> V_697 ,
V_63 -> V_242 ) ;
V_313 = F_401 ( V_63 -> V_110 , & V_166 , V_621 ) ;
F_445 ( V_63 , V_313 ) ;
F_8 ( L_51 , V_313 ) ;
return V_313 ;
}
static void F_446 ( struct V_102 * V_103 , void * V_159 )
{
struct V_700 * V_161 = V_159 ;
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
if ( V_161 -> V_421 )
F_261 ( V_161 -> V_2 , V_161 -> V_423 ) ;
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
struct V_700 * V_161 = V_159 ;
struct V_2 * V_2 = V_161 -> V_2 ;
if ( V_2 ) {
if ( V_161 -> V_421 )
F_258 ( V_2 ) ;
F_449 ( V_2 ) ;
}
F_105 ( V_159 ) ;
}
static void F_450 ( struct V_102 * V_103 , void * V_161 )
{
struct V_700 * V_701 ;
V_701 = (struct V_700 * ) V_161 ;
if ( F_254 ( V_701 -> V_2 , V_103 ) )
return;
if ( V_701 -> V_421 )
F_263 ( V_701 -> V_2 , & V_701 -> V_423 ) ;
F_70 ( V_701 -> V_56 . V_14 ,
& V_701 -> args . V_163 ,
& V_701 -> V_56 . V_164 ,
V_103 ) ;
}
static int F_451 ( struct V_2 * V_2 , struct V_323 * V_357 , const T_8 * V_257 , int V_702 )
{
struct V_700 * V_161 ;
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_102 * V_103 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_703 ] ,
. V_323 = V_357 ,
} ;
struct V_167 V_324 = {
. V_169 = V_14 -> V_98 ,
. V_165 = & V_166 ,
. V_170 = & V_704 ,
. V_219 = V_328 ,
} ;
int V_313 = 0 ;
V_161 = F_95 ( sizeof( * V_161 ) , V_310 ) ;
if ( V_161 == NULL )
return - V_132 ;
F_46 ( & V_161 -> args . V_163 , & V_161 -> V_56 . V_164 , 1 ) ;
F_267 ( V_14 -> V_62 ,
V_433 ,
& V_324 . V_169 , & V_166 ) ;
V_161 -> args . V_439 = & V_161 -> V_251 ;
V_161 -> args . V_257 = & V_161 -> V_257 ;
V_161 -> args . V_248 = V_14 -> V_435 ;
F_194 ( & V_161 -> V_251 , F_102 ( V_2 ) ) ;
F_136 ( & V_161 -> V_257 , V_257 ) ;
V_161 -> V_56 . V_400 = & V_161 -> V_400 ;
V_161 -> V_56 . V_14 = V_14 ;
F_90 ( V_161 -> V_56 . V_400 ) ;
V_161 -> V_115 = V_157 ;
V_161 -> V_301 = 0 ;
V_161 -> V_2 = F_452 ( V_2 ) ;
if ( V_161 -> V_2 )
V_161 -> V_421 = F_264 ( V_2 ) ;
V_324 . V_173 = V_161 ;
V_166 . V_321 = & V_161 -> args ;
V_166 . V_322 = & V_161 -> V_56 ;
V_103 = F_77 ( & V_324 ) ;
if ( F_51 ( V_103 ) )
return F_78 ( V_103 ) ;
if ( ! V_702 )
goto V_136;
V_313 = F_116 ( V_103 ) ;
if ( V_313 != 0 )
goto V_136;
V_313 = V_161 -> V_301 ;
if ( V_313 == 0 )
F_453 ( V_2 , & V_161 -> V_400 ) ;
else
F_159 ( V_2 , & V_161 -> V_400 ) ;
V_136:
F_79 ( V_103 ) ;
return V_313 ;
}
int F_454 ( struct V_2 * V_2 , struct V_323 * V_357 , const T_8 * V_257 , int V_702 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_451 ( V_2 , V_357 , V_257 , V_702 ) ;
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
if ( V_50 > V_705 )
return V_705 ;
return V_50 ;
}
static int F_457 ( struct V_64 * V_65 , int V_706 , struct V_707 * V_708 )
{
struct V_2 * V_2 = V_65 -> V_2 ;
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_62 * V_63 = V_14 -> V_62 ;
struct V_709 V_403 = {
. V_251 = F_102 ( V_2 ) ,
. V_710 = V_708 ,
} ;
struct V_711 V_56 = {
. V_712 = V_708 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_713 ] ,
. V_321 = & V_403 ,
. V_322 = & V_56 ,
. V_323 = V_65 -> V_232 -> V_298 ,
} ;
struct V_289 * V_290 ;
int V_313 ;
V_403 . V_714 . V_241 = V_63 -> V_242 ;
V_313 = F_458 ( V_65 , V_708 ) ;
if ( V_313 != 0 )
goto V_136;
V_290 = V_708 -> V_715 . V_716 . V_232 ;
V_403 . V_714 . V_243 = V_290 -> V_717 . V_246 ;
V_403 . V_714 . V_718 = V_14 -> V_718 ;
V_313 = F_80 ( V_14 -> V_98 , V_14 , & V_166 , & V_403 . V_163 , & V_56 . V_164 , 1 ) ;
switch ( V_313 ) {
case 0 :
V_708 -> V_719 = V_720 ;
break;
case - V_315 :
V_313 = 0 ;
}
V_708 -> V_721 -> V_722 ( V_708 ) ;
V_708 -> V_721 = NULL ;
V_136:
return V_313 ;
}
static int F_459 ( struct V_64 * V_65 , int V_706 , struct V_707 * V_708 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_457 ( V_65 , V_706 , V_708 ) ;
F_460 ( V_708 , V_65 , V_706 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_65 -> V_2 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_461 ( struct V_2 * V_2 , struct V_707 * V_710 )
{
return F_462 ( V_2 , V_710 ) ;
}
static struct V_723 * F_463 ( struct V_707 * V_710 ,
struct V_307 * V_308 ,
struct V_289 * V_290 ,
struct V_223 * V_209 )
{
struct V_723 * V_41 ;
struct V_2 * V_2 = V_290 -> V_291 -> V_2 ;
V_41 = F_95 ( sizeof( * V_41 ) , V_310 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_403 . V_251 = F_102 ( V_2 ) ;
V_41 -> V_403 . V_710 = & V_41 -> V_710 ;
V_41 -> V_403 . V_209 = V_209 ;
V_41 -> V_56 . V_209 = V_209 ;
V_41 -> V_290 = V_290 ;
F_99 ( & V_290 -> V_724 ) ;
V_41 -> V_308 = F_168 ( V_308 ) ;
memcpy ( & V_41 -> V_710 , V_710 , sizeof( V_41 -> V_710 ) ) ;
V_41 -> V_14 = F_94 ( V_2 ) ;
return V_41 ;
}
static void F_464 ( void * V_161 )
{
struct V_723 * V_159 = V_161 ;
F_109 ( V_159 -> V_403 . V_209 ) ;
F_465 ( V_159 -> V_290 ) ;
F_180 ( V_159 -> V_308 ) ;
F_105 ( V_159 ) ;
}
static void F_466 ( struct V_102 * V_103 , void * V_161 )
{
struct V_723 * V_159 = V_161 ;
if ( ! F_67 ( V_103 , & V_159 -> V_56 . V_164 ) )
return;
switch ( V_103 -> V_107 ) {
case 0 :
F_44 ( V_159 -> V_14 , V_159 -> V_115 ) ;
F_461 ( V_159 -> V_290 -> V_291 -> V_2 , & V_159 -> V_710 ) ;
if ( F_148 ( V_159 -> V_290 ,
& V_159 -> V_56 . V_257 ) )
break;
case - V_72 :
case - V_93 :
case - V_75 :
case - V_74 :
if ( ! F_146 ( & V_159 -> V_403 . V_257 ,
& V_159 -> V_290 -> V_293 ) )
F_65 ( V_103 ) ;
break;
default:
if ( F_38 ( V_103 , V_159 -> V_14 ,
NULL , NULL ) == - V_108 )
F_65 ( V_103 ) ;
}
F_152 ( V_159 -> V_403 . V_209 ) ;
}
static void F_467 ( struct V_102 * V_103 , void * V_161 )
{
struct V_723 * V_159 = V_161 ;
if ( F_193 ( V_159 -> V_403 . V_209 , V_103 ) != 0 )
goto V_329;
F_136 ( & V_159 -> V_403 . V_257 , & V_159 -> V_290 -> V_293 ) ;
if ( F_33 ( V_725 , & V_159 -> V_290 -> V_726 ) == 0 ) {
goto V_330;
}
V_159 -> V_115 = V_157 ;
if ( F_70 ( V_159 -> V_14 ,
& V_159 -> V_403 . V_163 ,
& V_159 -> V_56 . V_164 ,
V_103 ) != 0 )
F_152 ( V_159 -> V_403 . V_209 ) ;
return;
V_330:
V_103 -> V_341 = NULL ;
V_329:
F_67 ( V_103 , & V_159 -> V_56 . V_164 ) ;
}
static struct V_102 * F_468 ( struct V_707 * V_710 ,
struct V_307 * V_308 ,
struct V_289 * V_290 ,
struct V_223 * V_209 )
{
struct V_723 * V_161 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_727 ] ,
. V_323 = V_308 -> V_357 ,
} ;
struct V_167 V_324 = {
. V_169 = F_308 ( V_290 -> V_291 -> V_2 ) ,
. V_165 = & V_166 ,
. V_170 = & V_728 ,
. V_326 = V_327 ,
. V_219 = V_328 ,
} ;
F_267 ( F_94 ( V_290 -> V_291 -> V_2 ) -> V_62 ,
V_433 , & V_324 . V_169 , & V_166 ) ;
V_710 -> V_719 = V_720 ;
V_161 = F_463 ( V_710 , V_308 , V_290 , V_209 ) ;
if ( V_161 == NULL ) {
F_109 ( V_209 ) ;
return F_52 ( - V_132 ) ;
}
F_46 ( & V_161 -> V_403 . V_163 , & V_161 -> V_56 . V_164 , 1 ) ;
V_166 . V_321 = & V_161 -> V_403 ;
V_166 . V_322 = & V_161 -> V_56 ;
V_324 . V_173 = V_161 ;
return F_77 ( & V_324 ) ;
}
static int F_469 ( struct V_64 * V_65 , int V_706 , struct V_707 * V_708 )
{
struct V_2 * V_2 = V_65 -> V_2 ;
struct V_217 * V_218 = V_65 -> V_232 ;
struct V_176 * V_177 = F_82 ( V_2 ) ;
struct V_223 * V_209 ;
struct V_289 * V_290 ;
struct V_102 * V_103 ;
struct V_223 * ( * V_224 ) ( struct V_225 * , T_6 ) ;
int V_313 = 0 ;
unsigned char V_729 = V_708 -> V_729 ;
V_313 = F_458 ( V_65 , V_708 ) ;
V_708 -> V_729 |= V_730 ;
F_470 ( & V_218 -> V_731 ) ;
F_471 ( & V_177 -> V_732 ) ;
if ( F_461 ( V_2 , V_708 ) == - V_309 ) {
F_472 ( & V_177 -> V_732 ) ;
F_473 ( & V_218 -> V_731 ) ;
goto V_136;
}
F_472 ( & V_177 -> V_732 ) ;
F_473 ( & V_218 -> V_731 ) ;
if ( V_313 != 0 )
goto V_136;
V_290 = V_708 -> V_715 . V_716 . V_232 ;
if ( F_33 ( V_725 , & V_290 -> V_726 ) == 0 )
goto V_136;
V_224 = F_94 ( V_2 ) -> V_62 -> V_171 -> V_224 ;
V_209 = V_224 ( & V_290 -> V_717 , V_390 ) ;
V_313 = - V_132 ;
if ( F_51 ( V_209 ) )
goto V_136;
V_103 = F_468 ( V_708 , F_300 ( V_708 -> V_733 ) , V_290 , V_209 ) ;
V_313 = F_78 ( V_103 ) ;
if ( F_51 ( V_103 ) )
goto V_136;
V_313 = F_116 ( V_103 ) ;
F_79 ( V_103 ) ;
V_136:
V_708 -> V_729 = V_729 ;
F_474 ( V_708 , V_65 , V_734 , V_313 ) ;
return V_313 ;
}
static struct V_735 * F_475 ( struct V_707 * V_710 ,
struct V_307 * V_308 , struct V_289 * V_290 ,
T_6 V_221 )
{
struct V_735 * V_41 ;
struct V_2 * V_2 = V_290 -> V_291 -> V_2 ;
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_223 * ( * V_224 ) ( struct V_225 * , T_6 ) ;
V_41 = F_95 ( sizeof( * V_41 ) , V_221 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_403 . V_251 = F_102 ( V_2 ) ;
V_41 -> V_403 . V_710 = & V_41 -> V_710 ;
V_41 -> V_403 . V_736 = F_476 ( & V_290 -> V_291 -> V_232 -> V_229 , V_221 ) ;
if ( F_51 ( V_41 -> V_403 . V_736 ) )
goto V_317;
V_224 = V_14 -> V_62 -> V_171 -> V_224 ;
V_41 -> V_403 . V_737 = V_224 ( & V_290 -> V_717 , V_221 ) ;
if ( F_51 ( V_41 -> V_403 . V_737 ) )
goto V_738;
V_41 -> V_403 . V_714 . V_241 = V_14 -> V_62 -> V_242 ;
V_41 -> V_403 . V_714 . V_243 = V_290 -> V_717 . V_246 ;
V_41 -> V_403 . V_714 . V_718 = V_14 -> V_718 ;
V_41 -> V_56 . V_737 = V_41 -> V_403 . V_737 ;
V_41 -> V_290 = V_290 ;
V_41 -> V_14 = V_14 ;
F_99 ( & V_290 -> V_724 ) ;
V_41 -> V_308 = F_168 ( V_308 ) ;
F_477 ( V_710 -> V_733 ) ;
memcpy ( & V_41 -> V_710 , V_710 , sizeof( V_41 -> V_710 ) ) ;
return V_41 ;
V_738:
F_109 ( V_41 -> V_403 . V_736 ) ;
V_317:
F_105 ( V_41 ) ;
return NULL ;
}
static void F_478 ( struct V_102 * V_103 , void * V_159 )
{
struct V_735 * V_161 = V_159 ;
struct V_64 * V_65 = V_161 -> V_290 -> V_291 ;
F_8 ( L_29 , V_34 ) ;
if ( F_193 ( V_161 -> V_403 . V_737 , V_103 ) != 0 )
goto V_329;
if ( ! F_33 ( V_725 , & V_161 -> V_290 -> V_726 ) ) {
if ( F_193 ( V_161 -> V_403 . V_736 , V_103 ) != 0 ) {
goto V_739;
}
F_136 ( & V_161 -> V_403 . V_278 ,
& V_65 -> V_278 ) ;
V_161 -> V_403 . V_740 = 1 ;
V_161 -> V_56 . V_736 = V_161 -> V_403 . V_736 ;
} else {
V_161 -> V_403 . V_740 = 0 ;
F_136 ( & V_161 -> V_403 . V_741 ,
& V_161 -> V_290 -> V_293 ) ;
}
if ( ! F_250 ( V_65 ) ) {
V_161 -> V_301 = - V_416 ;
V_103 -> V_341 = NULL ;
goto V_742;
}
V_161 -> V_115 = V_157 ;
if ( F_70 ( V_161 -> V_14 ,
& V_161 -> V_403 . V_163 ,
& V_161 -> V_56 . V_164 ,
V_103 ) == 0 )
return;
V_742:
F_152 ( V_161 -> V_403 . V_736 ) ;
V_739:
F_152 ( V_161 -> V_403 . V_737 ) ;
V_329:
F_67 ( V_103 , & V_161 -> V_56 . V_164 ) ;
F_8 ( L_52 , V_34 , V_161 -> V_301 ) ;
}
static void F_479 ( struct V_102 * V_103 , void * V_159 )
{
struct V_735 * V_161 = V_159 ;
struct V_289 * V_290 = V_161 -> V_290 ;
F_8 ( L_29 , V_34 ) ;
if ( ! F_67 ( V_103 , & V_161 -> V_56 . V_164 ) )
return;
V_161 -> V_301 = V_103 -> V_107 ;
switch ( V_103 -> V_107 ) {
case 0 :
F_44 ( F_94 ( F_14 ( V_161 -> V_308 -> V_4 ) ) ,
V_161 -> V_115 ) ;
if ( V_161 -> V_403 . V_743 ) {
V_161 -> V_710 . V_729 &= ~ ( V_744 | V_745 ) ;
if ( F_461 ( V_290 -> V_291 -> V_2 , & V_161 -> V_710 ) < 0 ) {
F_65 ( V_103 ) ;
break;
}
}
if ( V_161 -> V_403 . V_740 != 0 ) {
F_187 ( & V_290 -> V_717 , 0 ) ;
F_136 ( & V_290 -> V_293 , & V_161 -> V_56 . V_257 ) ;
F_133 ( V_725 , & V_290 -> V_726 ) ;
} else if ( ! F_148 ( V_290 , & V_161 -> V_56 . V_257 ) )
F_65 ( V_103 ) ;
break;
case - V_72 :
case - V_93 :
case - V_75 :
case - V_74 :
if ( V_161 -> V_403 . V_740 != 0 ) {
if ( ! F_146 ( & V_161 -> V_403 . V_278 ,
& V_290 -> V_291 -> V_278 ) )
F_65 ( V_103 ) ;
} else if ( ! F_146 ( & V_161 -> V_403 . V_741 ,
& V_290 -> V_293 ) )
F_65 ( V_103 ) ;
}
F_8 ( L_30 , V_34 , V_161 -> V_301 ) ;
}
static void F_480 ( void * V_159 )
{
struct V_735 * V_161 = V_159 ;
F_8 ( L_29 , V_34 ) ;
F_109 ( V_161 -> V_403 . V_736 ) ;
if ( V_161 -> V_316 != 0 ) {
struct V_102 * V_103 ;
V_103 = F_468 ( & V_161 -> V_710 , V_161 -> V_308 , V_161 -> V_290 ,
V_161 -> V_403 . V_737 ) ;
if ( ! F_51 ( V_103 ) )
F_481 ( V_103 ) ;
F_8 ( L_53 , V_34 ) ;
} else
F_109 ( V_161 -> V_403 . V_737 ) ;
F_465 ( V_161 -> V_290 ) ;
F_180 ( V_161 -> V_308 ) ;
F_482 ( V_161 -> V_710 . V_733 ) ;
F_105 ( V_161 ) ;
F_8 ( L_31 , V_34 ) ;
}
static void F_483 ( struct V_13 * V_14 , struct V_289 * V_290 , int V_740 , int error )
{
switch ( error ) {
case - V_71 :
case - V_72 :
V_290 -> V_717 . V_219 &= ~ V_746 ;
if ( V_740 != 0 ||
F_33 ( V_725 , & V_290 -> V_726 ) != 0 )
F_23 ( V_14 , V_290 -> V_291 ) ;
break;
case - V_75 :
V_290 -> V_717 . V_219 &= ~ V_746 ;
case - V_74 :
F_24 ( V_14 -> V_62 ) ;
} ;
}
static int F_484 ( struct V_64 * V_65 , int V_706 , struct V_707 * V_710 , int V_747 )
{
struct V_735 * V_161 ;
struct V_102 * V_103 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_748 ] ,
. V_323 = V_65 -> V_232 -> V_298 ,
} ;
struct V_167 V_324 = {
. V_169 = F_308 ( V_65 -> V_2 ) ,
. V_165 = & V_166 ,
. V_170 = & V_749 ,
. V_326 = V_327 ,
. V_219 = V_328 ,
} ;
int V_51 ;
F_8 ( L_29 , V_34 ) ;
V_161 = F_475 ( V_710 , F_300 ( V_710 -> V_733 ) ,
V_710 -> V_715 . V_716 . V_232 ,
V_747 == V_750 ? V_390 : V_310 ) ;
if ( V_161 == NULL )
return - V_132 ;
if ( F_485 ( V_706 ) )
V_161 -> V_403 . V_751 = 1 ;
F_46 ( & V_161 -> V_403 . V_163 , & V_161 -> V_56 . V_164 , 1 ) ;
V_166 . V_321 = & V_161 -> V_403 ;
V_166 . V_322 = & V_161 -> V_56 ;
V_324 . V_173 = V_161 ;
if ( V_747 > V_750 ) {
if ( V_747 == V_752 )
V_161 -> V_403 . V_753 = V_752 ;
F_47 ( & V_161 -> V_403 . V_163 ) ;
} else
V_161 -> V_403 . V_743 = 1 ;
V_103 = F_77 ( & V_324 ) ;
if ( F_51 ( V_103 ) )
return F_78 ( V_103 ) ;
V_51 = F_116 ( V_103 ) ;
if ( V_51 == 0 ) {
V_51 = V_161 -> V_301 ;
if ( V_51 )
F_483 ( V_161 -> V_14 , V_161 -> V_290 ,
V_161 -> V_403 . V_740 , V_51 ) ;
} else
V_161 -> V_316 = 1 ;
F_79 ( V_103 ) ;
F_8 ( L_30 , V_34 , V_51 ) ;
F_486 ( V_710 , V_65 , & V_161 -> V_56 . V_257 , V_706 , V_51 ) ;
return V_51 ;
}
static int F_487 ( struct V_64 * V_65 , struct V_707 * V_708 )
{
struct V_13 * V_14 = F_94 ( V_65 -> V_2 ) ;
struct V_60 V_61 = {
. V_2 = V_65 -> V_2 ,
} ;
int V_8 ;
do {
if ( F_33 ( V_280 , & V_65 -> V_219 ) != 0 )
return 0 ;
V_8 = F_484 ( V_65 , V_734 , V_708 , V_752 ) ;
if ( V_8 != - V_89 )
break;
F_31 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_488 ( struct V_64 * V_65 , struct V_707 * V_708 )
{
struct V_13 * V_14 = F_94 ( V_65 -> V_2 ) ;
struct V_60 V_61 = {
. V_2 = V_65 -> V_2 ,
} ;
int V_8 ;
V_8 = F_458 ( V_65 , V_708 ) ;
if ( V_8 != 0 )
return V_8 ;
if ( ! V_754 ) {
F_133 ( V_755 , & V_708 -> V_715 . V_716 . V_232 -> V_726 ) ;
return 0 ;
}
do {
if ( F_33 ( V_280 , & V_65 -> V_219 ) != 0 )
return 0 ;
V_8 = F_484 ( V_65 , V_734 , V_708 , V_756 ) ;
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
if ( F_33 ( V_725 , & V_290 -> V_726 ) ) {
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
F_135 ( V_725 , & V_290 -> V_726 ) ;
V_51 = V_313 ;
}
}
} ;
return V_51 ;
}
static int F_491 ( struct V_64 * V_65 , struct V_707 * V_708 )
{
int V_313 = V_370 ;
if ( F_33 ( V_757 , & V_65 -> V_219 ) )
V_313 = F_489 ( V_65 ) ;
if ( V_313 != V_370 )
V_313 = F_488 ( V_65 , V_708 ) ;
return V_313 ;
}
static int F_492 ( struct V_64 * V_65 , int V_706 , struct V_707 * V_708 )
{
struct V_176 * V_177 = F_82 ( V_65 -> V_2 ) ;
struct V_217 * V_218 = V_65 -> V_232 ;
unsigned char V_729 = V_708 -> V_729 ;
int V_313 = - V_758 ;
if ( ( V_729 & V_759 ) &&
! F_33 ( V_383 , & V_65 -> V_219 ) )
goto V_136;
V_313 = F_458 ( V_65 , V_708 ) ;
if ( V_313 != 0 )
goto V_136;
V_708 -> V_729 |= V_745 ;
V_313 = F_461 ( V_65 -> V_2 , V_708 ) ;
if ( V_313 < 0 )
goto V_136;
F_470 ( & V_218 -> V_731 ) ;
F_471 ( & V_177 -> V_732 ) ;
if ( F_33 ( V_280 , & V_65 -> V_219 ) ) {
V_708 -> V_729 = V_729 & ~ V_744 ;
V_313 = F_461 ( V_65 -> V_2 , V_708 ) ;
F_472 ( & V_177 -> V_732 ) ;
F_473 ( & V_218 -> V_731 ) ;
goto V_136;
}
F_472 ( & V_177 -> V_732 ) ;
F_473 ( & V_218 -> V_731 ) ;
V_313 = F_484 ( V_65 , V_706 , V_708 , V_750 ) ;
V_136:
V_708 -> V_729 = V_729 ;
return V_313 ;
}
static int F_493 ( struct V_64 * V_65 , int V_706 , struct V_707 * V_708 )
{
struct V_60 V_61 = {
. V_65 = V_65 ,
. V_2 = V_65 -> V_2 ,
} ;
int V_8 ;
do {
V_8 = F_492 ( V_65 , V_706 , V_708 ) ;
if ( V_8 == - V_315 )
V_8 = - V_108 ;
V_8 = F_31 ( F_94 ( V_65 -> V_2 ) ,
V_8 , & V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int
F_494 ( struct V_760 * V_761 , int V_706 , struct V_707 * V_708 )
{
struct V_307 * V_308 ;
struct V_64 * V_65 ;
unsigned long V_50 = V_762 ;
int V_313 ;
V_308 = F_300 ( V_761 ) ;
V_65 = V_308 -> V_65 ;
if ( V_708 -> V_763 < 0 || V_708 -> V_764 < 0 )
return - V_27 ;
if ( F_495 ( V_706 ) ) {
if ( V_65 != NULL )
return F_459 ( V_65 , V_765 , V_708 ) ;
return 0 ;
}
if ( ! ( F_496 ( V_706 ) || F_485 ( V_706 ) ) )
return - V_27 ;
if ( V_708 -> V_719 == V_720 ) {
if ( V_65 != NULL )
return F_469 ( V_65 , V_706 , V_708 ) ;
return 0 ;
}
if ( V_65 == NULL )
return - V_758 ;
switch ( V_708 -> V_719 ) {
case V_766 :
if ( ! ( V_761 -> V_767 & V_190 ) )
return - V_416 ;
break;
case V_768 :
if ( ! ( V_761 -> V_767 & V_191 ) )
return - V_416 ;
}
do {
V_313 = F_493 ( V_65 , V_706 , V_708 ) ;
if ( ( V_313 != - V_108 ) || F_496 ( V_706 ) )
break;
V_50 = F_456 ( V_50 ) ;
V_313 = - V_58 ;
if ( F_497 () )
break;
} while( V_313 < 0 );
return V_313 ;
}
int F_498 ( struct V_707 * V_710 , struct V_64 * V_65 , const T_8 * V_257 )
{
struct V_13 * V_14 = F_94 ( V_65 -> V_2 ) ;
int V_8 ;
V_8 = F_458 ( V_65 , V_710 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_484 ( V_65 , V_734 , V_710 , V_750 ) ;
return F_181 ( V_14 , V_65 , V_257 , V_8 ) ;
}
static void F_499 ( struct V_102 * V_103 , void * V_159 )
{
struct V_769 * V_161 = V_159 ;
struct V_13 * V_14 = V_161 -> V_14 ;
F_48 ( V_14 -> V_62 -> V_158 ,
& V_161 -> args . V_163 , & V_161 -> V_56 . V_164 , V_103 ) ;
V_161 -> args . V_714 . V_241 = V_14 -> V_62 -> V_242 ;
V_161 -> V_115 = V_157 ;
}
static void F_500 ( struct V_102 * V_103 , void * V_159 )
{
struct V_769 * V_161 = V_159 ;
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
struct V_769 * V_161 = V_159 ;
F_502 ( V_161 -> V_14 , V_161 -> V_290 ) ;
F_105 ( V_159 ) ;
}
static void
F_503 ( struct V_13 * V_14 , struct V_289 * V_290 )
{
struct V_769 * V_161 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_770 ] ,
} ;
if ( V_14 -> V_62 -> V_171 -> V_339 != 0 )
return;
V_161 = F_290 ( sizeof( * V_161 ) , V_310 ) ;
if ( ! V_161 )
return;
V_161 -> V_290 = V_290 ;
V_161 -> V_14 = V_14 ;
V_161 -> args . V_714 . V_241 = V_14 -> V_62 -> V_242 ;
V_161 -> args . V_714 . V_243 = V_290 -> V_717 . V_246 ;
V_161 -> args . V_714 . V_718 = V_14 -> V_718 ;
V_166 . V_321 = & V_161 -> args ;
V_166 . V_322 = & V_161 -> V_56 ;
F_46 ( & V_161 -> args . V_163 , & V_161 -> V_56 . V_164 , 0 ) ;
F_399 ( V_14 -> V_98 , & V_166 , 0 , & V_771 , V_161 ) ;
}
static int F_504 ( const struct V_772 * V_773 ,
struct V_4 * V_774 , struct V_2 * V_2 ,
const char * V_775 , const void * V_623 ,
T_9 V_624 , int V_219 )
{
return F_421 ( V_2 , V_623 , V_624 ) ;
}
static int F_505 ( const struct V_772 * V_773 ,
struct V_4 * V_774 , struct V_2 * V_2 ,
const char * V_775 , void * V_623 , T_9 V_624 )
{
return F_415 ( V_2 , V_623 , V_624 ) ;
}
static bool F_506 ( struct V_4 * V_4 )
{
return F_402 ( F_94 ( F_14 ( V_4 ) ) ) ;
}
static int F_507 ( const struct V_772 * V_773 ,
struct V_4 * V_774 , struct V_2 * V_2 ,
const char * V_775 , const void * V_623 ,
T_9 V_624 , int V_219 )
{
if ( F_508 ( V_775 ) )
return F_429 ( V_2 , V_623 , V_624 ) ;
return - V_648 ;
}
static int F_509 ( const struct V_772 * V_773 ,
struct V_4 * V_774 , struct V_2 * V_2 ,
const char * V_775 , void * V_623 , T_9 V_624 )
{
if ( F_508 ( V_775 ) )
return F_424 ( V_2 , V_623 , V_624 ) ;
return - V_648 ;
}
static T_11
F_510 ( struct V_2 * V_2 , char * V_776 , T_9 V_777 )
{
int V_12 = 0 ;
if ( F_2 ( V_2 , V_9 ) ) {
V_12 = F_511 ( V_2 , V_776 , V_777 ) ;
if ( V_777 && V_12 > V_777 )
return - V_635 ;
}
return V_12 ;
}
static T_11
F_510 ( struct V_2 * V_2 , char * V_776 , T_9 V_777 )
{
return 0 ;
}
static void F_292 ( struct V_399 * V_400 )
{
if ( ! ( ( ( V_400 -> V_304 & V_778 ) ||
( V_400 -> V_304 & V_779 ) ) &&
( V_400 -> V_304 & V_500 ) &&
( V_400 -> V_304 & V_780 ) ) )
return;
V_400 -> V_304 |= V_342 | V_516 |
V_517 | V_781 ;
V_400 -> V_265 = V_347 | V_519 | V_520 ;
V_400 -> V_521 = 2 ;
}
static int F_512 ( struct V_54 * V_98 , struct V_2 * V_3 ,
const struct V_502 * V_247 ,
struct V_504 * V_782 ,
struct V_503 * V_503 )
{
struct V_13 * V_14 = F_94 ( V_3 ) ;
T_1 V_248 [ 3 ] = {
[ 0 ] = V_783 | V_784 ,
} ;
struct V_785 args = {
. V_514 = F_102 ( V_3 ) ,
. V_247 = V_247 ,
. V_503 = V_503 ,
. V_248 = V_248 ,
} ;
struct V_786 V_56 = {
. V_782 = V_782 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_787 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
int V_313 ;
F_8 ( L_54 , V_34 ) ;
if ( F_94 ( V_3 ) -> V_15 [ 1 ] & V_788 )
V_248 [ 1 ] |= V_788 ;
else
V_248 [ 0 ] |= V_45 ;
F_90 ( & V_782 -> V_400 ) ;
V_782 -> V_14 = V_14 ;
V_782 -> V_789 = 0 ;
V_313 = F_80 ( V_98 , V_14 , & V_166 , & args . V_163 , & V_56 . V_164 , 0 ) ;
F_8 ( L_55 , V_34 , V_313 ) ;
return V_313 ;
}
int F_291 ( struct V_54 * V_98 , struct V_2 * V_3 ,
const struct V_502 * V_247 ,
struct V_504 * V_782 ,
struct V_503 * V_503 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_512 ( V_98 , V_3 , V_247 ,
V_782 , V_503 ) ;
F_513 ( V_3 , V_247 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_514 ( struct V_2 * V_2 ,
struct V_504 * V_505 ,
struct V_503 * V_503 , struct V_323 * V_357 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_54 * V_55 = V_14 -> V_98 ;
T_1 V_248 [ 2 ] = {
[ 0 ] = V_783 | V_784 ,
} ;
struct V_785 args = {
. V_241 = V_14 -> V_62 -> V_242 ,
. V_251 = F_102 ( V_2 ) ,
. V_503 = V_503 ,
. V_248 = V_248 ,
. V_790 = 1 ,
. V_791 = 1 ,
} ;
struct V_786 V_56 = {
. V_782 = V_505 ,
. V_790 = 1 ,
. V_791 = 1 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_787 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
unsigned long V_583 = V_157 ;
int V_313 ;
F_90 ( & V_505 -> V_400 ) ;
V_505 -> V_14 = V_14 ;
V_505 -> V_789 = 0 ;
F_46 ( & args . V_163 , & V_56 . V_164 , 0 ) ;
F_47 ( & args . V_163 ) ;
V_313 = F_76 ( V_55 , V_14 , & V_166 ,
& args . V_163 , & V_56 . V_164 ) ;
if ( V_313 )
return V_313 ;
F_44 ( V_14 , V_583 ) ;
return 0 ;
}
static int F_515 ( struct V_2 * V_2 ,
struct V_504 * V_505 ,
struct V_503 * V_503 , struct V_323 * V_357 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_54 * V_55 = V_14 -> V_98 ;
T_1 V_248 [ 2 ] = {
[ 0 ] = V_783 | V_784 ,
} ;
struct V_785 args = {
. V_251 = F_102 ( V_2 ) ,
. V_503 = V_503 ,
. V_248 = V_248 ,
. V_790 = 1 ,
} ;
struct V_786 V_56 = {
. V_782 = V_505 ,
. V_790 = 1 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_787 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
int V_313 ;
F_90 ( & V_505 -> V_400 ) ;
V_505 -> V_14 = V_14 ;
V_505 -> V_789 = 0 ;
F_46 ( & args . V_163 , & V_56 . V_164 , 0 ) ;
F_47 ( & args . V_163 ) ;
V_313 = F_76 ( V_55 , V_14 , & V_166 ,
& args . V_163 , & V_56 . V_164 ) ;
if ( V_313 == V_792 &&
V_56 . V_164 . V_150 & V_793 )
V_313 = - V_78 ;
return V_313 ;
}
int F_516 ( struct V_2 * V_2 ,
struct V_504 * V_505 ,
struct V_503 * V_503 , struct V_323 * V_357 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_62 * V_63 = V_14 -> V_62 ;
const struct V_794 * V_795 =
V_63 -> V_171 -> V_796 ;
struct V_60 V_61 = { } ;
int V_313 ;
F_8 ( L_56 , V_34 ,
( unsigned long long ) V_14 -> V_501 . V_797 ,
( unsigned long long ) V_14 -> V_501 . V_798 ,
V_63 -> V_97 ) ;
F_517 ( F_102 ( V_2 ) , V_34 ) ;
do {
V_313 = V_795 -> V_799 ( V_2 , V_505 , V_503 , V_357 ) ;
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
struct V_800 args = {
. V_251 = F_102 ( V_2 ) ,
. V_241 = V_63 -> V_242 ,
. V_791 = 1 ,
} ;
struct V_801 V_56 = {
. V_791 = 1 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_802 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
unsigned long V_583 = V_157 ;
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
F_40 ( V_63 , V_583 ) ;
return 0 ;
}
static int F_521 ( struct V_2 * V_2 , struct V_323 * V_357 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_54 * V_55 = V_14 -> V_98 ;
struct V_800 args = {
. V_251 = F_102 ( V_2 ) ,
} ;
struct V_801 V_56 = {
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_802 ] ,
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
if ( V_313 == V_792 &&
V_56 . V_164 . V_150 & V_793 )
V_313 = - V_78 ;
return V_313 ;
}
int F_522 ( struct V_2 * V_2 , struct V_323 * V_357 )
{
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_62 * V_63 = V_14 -> V_62 ;
const struct V_794 * V_795 =
V_63 -> V_171 -> V_796 ;
struct V_60 V_61 = { } ;
int V_313 ;
F_8 ( L_56 , V_34 ,
( unsigned long long ) V_14 -> V_501 . V_797 ,
( unsigned long long ) V_14 -> V_501 . V_798 ,
V_63 -> V_97 ) ;
F_517 ( F_102 ( V_2 ) , V_34 ) ;
do {
V_313 = V_795 -> V_803 ( V_2 , V_357 ) ;
if ( V_313 != - V_89 )
break;
F_31 ( V_14 , V_313 , & V_61 ) ;
} while ( V_61 . V_68 );
return V_313 ;
}
static int F_523 ( struct V_2 * V_3 , const struct V_502 * V_247 , struct V_804 * V_495 , bool V_805 )
{
int V_313 ;
struct V_806 args = {
. V_514 = F_102 ( V_3 ) ,
. V_247 = V_247 ,
} ;
struct V_807 V_56 = {
. V_495 = V_495 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_808 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
struct V_54 * V_55 = F_94 ( V_3 ) -> V_98 ;
struct V_323 * V_357 = NULL ;
if ( V_805 ) {
V_55 = F_94 ( V_3 ) -> V_62 -> V_110 ;
V_357 = F_524 ( F_94 ( V_3 ) -> V_62 ) ;
V_166 . V_323 = V_357 ;
}
F_8 ( L_57 , V_247 -> V_247 ) ;
F_267 ( F_94 ( V_3 ) -> V_62 ,
V_809 , & V_55 , & V_166 ) ;
V_313 = F_80 ( V_55 , F_94 ( V_3 ) , & V_166 , & args . V_163 ,
& V_56 . V_164 , 0 ) ;
F_8 ( L_58 , V_313 ) ;
if ( V_357 )
F_222 ( V_357 ) ;
return V_313 ;
}
int F_525 ( struct V_2 * V_3 , const struct V_502 * V_247 ,
struct V_804 * V_495 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_39 ( F_94 ( V_3 ) -> V_62 ) )
V_8 = F_523 ( V_3 , V_247 , V_495 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_523 ( V_3 , V_247 , V_495 , false ) ;
F_526 ( V_3 , V_247 , V_8 ) ;
V_8 = F_31 ( F_94 ( V_3 ) , V_8 ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static int F_527 ( T_1 V_219 )
{
if ( V_219 & ~ V_810 )
goto V_811;
if ( ( V_219 & V_812 ) &&
( V_219 & V_813 ) )
goto V_811;
if ( ! ( V_219 & ( V_814 ) ) )
goto V_811;
return V_370 ;
V_811:
return - V_815 ;
}
static bool
F_528 ( struct V_816 * V_817 ,
struct V_816 * V_818 )
{
if ( V_817 -> V_819 == V_818 -> V_819 &&
memcmp ( V_817 -> V_820 , V_818 -> V_820 , V_817 -> V_819 ) == 0 )
return true ;
return false ;
}
static void
F_529 ( struct V_102 * V_103 , void * V_159 )
{
}
static
int F_530 ( struct V_54 * V_55 ,
struct V_821 * V_822 ,
struct V_62 * V_63 ,
struct V_323 * V_357 )
{
int V_313 ;
struct V_823 args = {
. V_98 = V_63 ,
. V_3 = V_824 ,
} ;
struct V_825 V_56 ;
struct V_165 V_166 = {
. V_318 =
& V_319 [ V_826 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
struct V_167 V_324 = {
. V_169 = V_55 ,
. V_821 = V_822 ,
. V_170 = & V_827 ,
. V_165 = & V_166 ,
. V_219 = V_621 ,
} ;
struct V_102 * V_103 ;
F_8 ( L_11 , V_34 ) ;
F_531 ( & args . V_828 , & V_63 -> V_87 -> V_829 ) ;
if ( ! ( V_63 -> V_87 -> V_219 & V_830 ) )
args . V_3 = V_831 ;
if ( V_822 != F_215 ( V_55 -> V_832 ) )
args . V_3 = V_831 ;
V_103 = F_77 ( & V_324 ) ;
if ( ! F_51 ( V_103 ) ) {
V_313 = V_103 -> V_107 ;
F_79 ( V_103 ) ;
} else
V_313 = F_78 ( V_103 ) ;
F_532 ( V_63 , V_313 ) ;
if ( V_313 == 0 ) {
if ( memcmp ( V_56 . V_828 . V_161 ,
V_63 -> V_87 -> V_829 . V_161 , V_833 ) ) {
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
if ( V_56 . V_834 != args . V_834 ) {
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
struct V_821 * V_822 ,
void * V_159 )
{
struct V_835 * V_41 = V_159 ;
return F_530 ( V_55 , V_822 , V_41 -> V_63 , V_41 -> V_357 ) ;
}
int F_534 ( struct V_62 * V_63 , struct V_323 * V_357 )
{
struct V_835 V_161 = {
. V_63 = V_63 ,
. V_357 = V_357 ,
} ;
return F_535 ( V_63 -> V_110 ,
F_533 , & V_161 ) ;
}
static int F_536 ( struct V_62 * V_63 ,
struct V_836 * V_218 )
{
static const T_1 V_837 [ V_838 ] = {
[ 1 ] = 1 << ( V_839 - 32 ) |
1 << ( V_840 - 32 ) |
1 << ( V_841 - 32 ) |
1 << ( V_842 - 32 ) |
1 << ( V_843 - 32 )
} ;
unsigned int V_492 ;
if ( V_218 -> V_844 == V_845 ) {
F_537 ( V_846 , L_63 ) ;
for ( V_492 = 0 ; V_492 <= V_847 ; V_492 ++ ) {
if ( F_33 ( V_492 , V_218 -> V_848 . V_255 . V_849 ) )
F_537 ( V_846 , L_64 , V_492 ) ;
if ( F_33 ( V_492 , V_218 -> V_850 . V_255 . V_849 ) )
F_537 ( V_846 , L_65 , V_492 ) ;
}
for ( V_492 = 0 ; V_492 < V_838 ; V_492 ++ ) {
if ( V_218 -> V_848 . V_255 . V_851 [ V_492 ] & ~ V_837 [ V_492 ] ) {
F_537 ( V_846 , L_66 ) ;
return - V_27 ;
}
}
if ( F_33 ( V_839 , V_218 -> V_848 . V_255 . V_849 ) &&
F_33 ( V_841 , V_218 -> V_848 . V_255 . V_849 ) &&
F_33 ( V_842 , V_218 -> V_848 . V_255 . V_849 ) &&
F_33 ( V_843 , V_218 -> V_848 . V_255 . V_849 ) ) {
F_537 ( V_846 , L_67 ) ;
F_537 ( V_846 , L_68 ) ;
F_133 ( V_852 , & V_63 -> V_853 ) ;
} else {
F_537 ( V_846 , L_66 ) ;
return - V_27 ;
}
if ( F_33 ( V_854 , V_218 -> V_850 . V_255 . V_849 ) &&
F_33 ( V_855 , V_218 -> V_850 . V_255 . V_849 ) &&
F_33 ( V_856 , V_218 -> V_850 . V_255 . V_849 ) &&
F_33 ( V_857 , V_218 -> V_850 . V_255 . V_849 ) ) {
F_537 ( V_846 , L_69 ) ;
F_133 ( V_433 , & V_63 -> V_853 ) ;
}
if ( F_33 ( V_858 , V_218 -> V_850 . V_255 . V_849 ) ) {
F_537 ( V_846 , L_70 ) ;
F_133 ( V_859 ,
& V_63 -> V_853 ) ;
}
if ( F_33 ( V_860 , V_218 -> V_850 . V_255 . V_849 ) &&
F_33 ( V_861 , V_218 -> V_850 . V_255 . V_849 ) ) {
F_537 ( V_846 , L_71 ) ;
F_133 ( V_809 , & V_63 -> V_853 ) ;
}
if ( F_33 ( V_862 , V_218 -> V_850 . V_255 . V_849 ) &&
F_33 ( V_863 , V_218 -> V_850 . V_255 . V_849 ) ) {
F_537 ( V_846 , L_72 ) ;
F_133 ( V_864 , & V_63 -> V_853 ) ;
}
if ( F_33 ( V_865 , V_218 -> V_850 . V_255 . V_849 ) ) {
F_537 ( V_846 , L_73 ) ;
F_133 ( V_866 , & V_63 -> V_853 ) ;
}
if ( F_33 ( V_867 , V_218 -> V_850 . V_255 . V_849 ) ) {
F_537 ( V_846 , L_74 ) ;
F_133 ( V_868 , & V_63 -> V_853 ) ;
}
}
return 0 ;
}
static int F_538 ( struct V_62 * V_63 , struct V_323 * V_357 ,
T_1 V_869 )
{
T_12 V_37 ;
struct V_870 args = {
. V_37 = & V_37 ,
. V_98 = V_63 ,
#ifdef F_539
. V_219 = V_871 |
V_872 |
V_873 ,
#else
. V_219 = V_871 |
V_872 ,
#endif
} ;
struct V_874 V_56 = {
0
} ;
int V_313 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_875 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
F_431 ( V_63 , & V_37 ) ;
V_313 = F_438 ( V_63 ) ;
if ( V_313 )
goto V_136;
F_8 ( L_75 ,
V_63 -> V_110 -> V_111 -> V_696 -> V_697 ,
V_63 -> V_667 ) ;
V_56 . V_876 = F_95 ( sizeof( struct V_877 ) ,
V_310 ) ;
if ( F_376 ( V_56 . V_876 == NULL ) ) {
V_313 = - V_132 ;
goto V_136;
}
V_56 . V_820 = F_95 ( sizeof( struct V_816 ) ,
V_310 ) ;
if ( F_376 ( V_56 . V_820 == NULL ) ) {
V_313 = - V_132 ;
goto V_878;
}
V_56 . V_879 = F_95 ( sizeof( struct V_880 ) , V_310 ) ;
if ( F_376 ( V_56 . V_879 == NULL ) ) {
V_313 = - V_132 ;
goto V_881;
}
switch ( V_869 ) {
case V_882 :
args . V_883 . V_844 = V_882 ;
break;
case V_845 :
args . V_883 = V_884 ;
break;
default:
F_119 ( 1 ) ;
V_313 = - V_27 ;
goto V_885;
}
V_313 = F_401 ( V_63 -> V_110 , & V_166 , V_621 ) ;
F_540 ( V_63 , V_313 ) ;
if ( V_313 == 0 )
V_313 = F_527 ( V_56 . V_219 ) ;
if ( V_313 == 0 )
V_313 = F_536 ( V_63 , & V_56 . V_883 ) ;
if ( V_313 == 0 ) {
V_63 -> V_242 = V_56 . V_241 ;
V_63 -> V_886 = V_56 . V_219 ;
if ( ! ( V_56 . V_219 & V_887 ) ) {
F_135 ( V_888 ,
& V_63 -> V_87 -> V_889 ) ;
V_63 -> V_890 = V_56 . V_209 ;
}
F_105 ( V_63 -> V_891 ) ;
V_63 -> V_891 = V_56 . V_876 ;
V_56 . V_876 = NULL ;
F_105 ( V_63 -> V_892 ) ;
V_63 -> V_892 = V_56 . V_879 ;
V_56 . V_879 = NULL ;
if ( V_63 -> V_893 != NULL &&
! F_528 ( V_63 -> V_893 ,
V_56 . V_820 ) ) {
F_8 ( L_76 ,
V_34 ) ;
F_133 ( V_894 , & V_63 -> V_106 ) ;
F_105 ( V_63 -> V_893 ) ;
V_63 -> V_893 = NULL ;
}
if ( V_63 -> V_893 == NULL ) {
V_63 -> V_893 = V_56 . V_820 ;
V_56 . V_820 = NULL ;
}
}
V_885:
F_105 ( V_56 . V_879 ) ;
V_881:
F_105 ( V_56 . V_820 ) ;
V_878:
F_105 ( V_56 . V_876 ) ;
V_136:
if ( V_63 -> V_892 != NULL )
F_8 ( L_77
L_78 ,
V_63 -> V_892 -> V_895 , V_63 -> V_892 -> V_247 ,
V_63 -> V_892 -> V_896 . V_897 ,
V_63 -> V_892 -> V_896 . V_898 ) ;
F_8 ( L_79 , V_313 ) ;
return V_313 ;
}
int F_541 ( struct V_62 * V_63 , struct V_323 * V_357 )
{
T_4 V_899 = V_63 -> V_110 -> V_111 -> V_112 ;
int V_313 ;
if ( V_899 == V_113 ||
V_899 == V_114 ) {
V_313 = F_538 ( V_63 , V_357 , V_845 ) ;
if ( ! V_313 )
return 0 ;
}
return F_538 ( V_63 , V_357 , V_882 ) ;
}
static int F_542 ( struct V_62 * V_63 ,
struct V_323 * V_357 )
{
struct V_165 V_166 = {
. V_318 = & V_319 [ V_900 ] ,
. V_321 = V_63 ,
. V_323 = V_357 ,
} ;
int V_313 ;
V_313 = F_401 ( V_63 -> V_110 , & V_166 , V_621 ) ;
F_543 ( V_63 , V_313 ) ;
if ( V_313 )
F_8 ( L_80
L_81 , V_313 , V_63 -> V_97 ) ;
return V_313 ;
}
static int F_544 ( struct V_62 * V_63 ,
struct V_323 * V_357 )
{
unsigned int V_901 ;
int V_51 ;
for ( V_901 = V_902 ; V_901 != 0 ; V_901 -- ) {
V_51 = F_542 ( V_63 , V_357 ) ;
switch ( V_51 ) {
case - V_89 :
case - V_903 :
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
if ( V_63 -> V_886 == 0 )
goto V_136;
if ( V_63 -> V_904 )
goto V_136;
V_357 = F_524 ( V_63 ) ;
V_51 = F_544 ( V_63 , V_357 ) ;
if ( V_357 )
F_222 ( V_357 ) ;
switch ( V_51 ) {
case 0 :
case - V_76 :
V_63 -> V_886 = 0 ;
}
V_136:
return V_51 ;
}
static void F_546 ( struct V_102 * V_103 ,
void * V_159 )
{
struct V_905 * V_161 =
(struct V_905 * ) V_159 ;
F_8 ( L_11 , V_34 ) ;
F_68 ( V_161 -> V_63 -> V_87 ,
& V_161 -> args -> V_906 ,
& V_161 -> V_56 -> V_907 ,
V_103 ) ;
F_8 ( L_82 , V_34 ) ;
}
static void F_547 ( struct V_102 * V_103 , void * V_159 )
{
struct V_905 * V_161 =
(struct V_905 * ) V_159 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_60 ( V_103 , & V_161 -> V_56 -> V_907 ) )
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
int F_548 ( struct V_62 * V_63 , struct V_478 * V_579 )
{
struct V_102 * V_103 ;
struct V_908 args ;
struct V_909 V_56 = {
. V_910 = V_579 ,
} ;
struct V_905 V_161 = {
. args = & args ,
. V_56 = & V_56 ,
. V_63 = V_63 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_911 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
struct V_167 V_168 = {
. V_169 = V_63 -> V_110 ,
. V_165 = & V_166 ,
. V_170 = & V_912 ,
. V_173 = & V_161 ,
. V_219 = V_621 ,
} ;
int V_313 ;
F_46 ( & args . V_906 , & V_56 . V_907 , 0 ) ;
F_47 ( & args . V_906 ) ;
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
static void F_549 ( struct V_913 * args ,
struct V_54 * V_55 )
{
unsigned int V_914 , V_915 ;
unsigned int V_916 = F_550 ( V_55 ) ;
V_914 = V_917 + V_918 ;
V_915 = V_917 + V_919 ;
args -> V_920 . V_914 = V_914 ;
args -> V_920 . V_915 = V_915 ;
args -> V_920 . V_921 = V_922 ;
args -> V_920 . V_923 = V_924 ;
F_8 ( L_85
L_86 ,
V_34 ,
args -> V_920 . V_914 , args -> V_920 . V_915 ,
args -> V_920 . V_921 , args -> V_920 . V_923 ) ;
args -> V_925 . V_914 = V_916 ;
args -> V_925 . V_915 = V_916 ;
args -> V_925 . V_926 = 0 ;
args -> V_925 . V_921 = V_927 ;
args -> V_925 . V_923 = V_928 ;
F_8 ( L_87
L_88 ,
V_34 ,
args -> V_925 . V_914 , args -> V_925 . V_915 ,
args -> V_925 . V_926 , args -> V_925 . V_921 ,
args -> V_925 . V_923 ) ;
}
static int F_551 ( struct V_913 * args ,
struct V_929 * V_56 )
{
struct V_930 * V_931 = & args -> V_920 ;
struct V_930 * V_932 = & V_56 -> V_920 ;
if ( V_932 -> V_915 > V_931 -> V_915 )
return - V_27 ;
if ( V_932 -> V_921 < V_931 -> V_921 )
return - V_27 ;
if ( V_932 -> V_923 == 0 )
return - V_27 ;
if ( V_932 -> V_923 > V_933 )
V_932 -> V_923 = V_933 ;
return 0 ;
}
static int F_552 ( struct V_913 * args ,
struct V_929 * V_56 )
{
struct V_930 * V_931 = & args -> V_925 ;
struct V_930 * V_932 = & V_56 -> V_925 ;
if ( ! ( V_56 -> V_219 & V_830 ) )
goto V_136;
if ( V_932 -> V_914 > V_931 -> V_914 )
return - V_27 ;
if ( V_932 -> V_915 < V_931 -> V_915 )
return - V_27 ;
if ( V_932 -> V_926 > V_931 -> V_926 )
return - V_27 ;
if ( V_932 -> V_921 != V_931 -> V_921 )
return - V_27 ;
if ( V_932 -> V_923 != V_931 -> V_923 )
return - V_27 ;
V_136:
return 0 ;
}
static int F_553 ( struct V_913 * args ,
struct V_929 * V_56 )
{
int V_51 ;
V_51 = F_551 ( args , V_56 ) ;
if ( V_51 )
return V_51 ;
return F_552 ( args , V_56 ) ;
}
static void F_554 ( struct V_138 * V_139 ,
struct V_929 * V_56 )
{
F_531 ( & V_139 -> V_829 , & V_56 -> V_828 ) ;
V_139 -> V_63 -> V_886 |= V_887 ;
F_133 ( V_888 , & V_139 -> V_889 ) ;
V_139 -> V_219 = V_56 -> V_219 ;
memcpy ( & V_139 -> V_920 , & V_56 -> V_920 , sizeof( V_139 -> V_920 ) ) ;
if ( V_56 -> V_219 & V_830 )
memcpy ( & V_139 -> V_925 , & V_56 -> V_925 ,
sizeof( V_139 -> V_925 ) ) ;
}
static int F_555 ( struct V_62 * V_63 ,
struct V_323 * V_357 )
{
struct V_138 * V_139 = V_63 -> V_87 ;
struct V_913 args = {
. V_98 = V_63 ,
. V_241 = V_63 -> V_242 ,
. V_209 = V_63 -> V_890 ,
. V_934 = V_935 ,
} ;
struct V_929 V_56 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_936 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
. V_323 = V_357 ,
} ;
int V_313 ;
F_549 ( & args , V_63 -> V_110 ) ;
args . V_219 = ( V_937 | V_830 ) ;
V_313 = F_401 ( V_139 -> V_63 -> V_110 , & V_166 , V_621 ) ;
F_556 ( V_63 , V_313 ) ;
if ( ! V_313 ) {
V_313 = F_553 ( & args , & V_56 ) ;
if ( V_63 -> V_890 == V_56 . V_209 )
V_63 -> V_890 ++ ;
if ( V_313 )
goto V_136;
F_554 ( V_139 , & V_56 ) ;
}
V_136:
return V_313 ;
}
int F_557 ( struct V_62 * V_63 , struct V_323 * V_357 )
{
int V_313 ;
unsigned * V_938 ;
struct V_138 * V_139 = V_63 -> V_87 ;
F_8 ( L_89 , V_34 , V_63 , V_139 ) ;
V_313 = F_555 ( V_63 , V_357 ) ;
if ( V_313 )
goto V_136;
V_313 = F_558 ( V_139 ) ;
F_8 ( L_90 , V_313 ) ;
if ( V_313 )
goto V_136;
V_938 = ( unsigned * ) & V_139 -> V_829 . V_161 [ 0 ] ;
F_8 ( L_91 , V_34 ,
V_63 -> V_890 , V_938 [ 0 ] , V_938 [ 1 ] , V_938 [ 2 ] , V_938 [ 3 ] ) ;
V_136:
F_8 ( L_82 , V_34 ) ;
return V_313 ;
}
int F_559 ( struct V_138 * V_139 ,
struct V_323 * V_357 )
{
struct V_165 V_166 = {
. V_318 = & V_319 [ V_939 ] ,
. V_321 = V_139 ,
. V_323 = V_357 ,
} ;
int V_313 = 0 ;
F_8 ( L_92 ) ;
if ( ! F_126 ( V_888 , & V_139 -> V_889 ) )
return 0 ;
V_313 = F_401 ( V_139 -> V_63 -> V_110 , & V_166 , V_621 ) ;
F_560 ( V_139 -> V_63 , V_313 ) ;
if ( V_313 )
F_8 ( L_93
L_94 , V_313 ) ;
F_8 ( L_95 ) ;
return V_313 ;
}
static void F_561 ( void * V_161 )
{
struct V_940 * V_159 = V_161 ;
struct V_62 * V_63 = V_159 -> V_63 ;
if ( F_391 ( & V_63 -> V_615 ) > 1 )
F_392 ( V_63 ) ;
F_393 ( V_63 ) ;
F_105 ( V_159 ) ;
}
static int F_562 ( struct V_102 * V_103 , struct V_62 * V_63 )
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
static void F_563 ( struct V_102 * V_103 , void * V_161 )
{
struct V_940 * V_159 = V_161 ;
struct V_62 * V_63 = V_159 -> V_63 ;
if ( ! F_60 ( V_103 , V_103 -> V_333 . V_322 ) )
return;
F_564 ( V_63 , V_103 -> V_107 ) ;
if ( V_103 -> V_107 < 0 ) {
F_8 ( L_96 , V_34 , V_103 -> V_107 ) ;
if ( F_391 ( & V_63 -> V_615 ) == 1 )
goto V_136;
if ( F_562 ( V_103 , V_63 ) == - V_108 ) {
F_65 ( V_103 ) ;
return;
}
}
F_8 ( L_97 , V_34 , V_103 -> V_333 . V_323 ) ;
V_136:
F_8 ( L_82 , V_34 ) ;
}
static void F_565 ( struct V_102 * V_103 , void * V_161 )
{
struct V_940 * V_159 = V_161 ;
struct V_62 * V_63 = V_159 -> V_63 ;
struct V_118 * args ;
struct V_119 * V_56 ;
args = V_103 -> V_333 . V_321 ;
V_56 = V_103 -> V_333 . V_322 ;
F_68 ( V_63 -> V_87 , args , V_56 , V_103 ) ;
}
static struct V_102 * F_566 ( struct V_62 * V_63 ,
struct V_323 * V_357 ,
bool V_941 )
{
struct V_940 * V_159 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_942 ] ,
. V_323 = V_357 ,
} ;
struct V_167 V_324 = {
. V_169 = V_63 -> V_110 ,
. V_165 = & V_166 ,
. V_170 = & V_943 ,
. V_219 = V_328 | V_621 ,
} ;
if ( ! F_398 ( & V_63 -> V_615 ) )
return F_52 ( - V_35 ) ;
V_159 = F_95 ( sizeof( * V_159 ) , V_310 ) ;
if ( V_159 == NULL ) {
F_393 ( V_63 ) ;
return F_52 ( - V_132 ) ;
}
F_46 ( & V_159 -> args , & V_159 -> V_56 , 0 ) ;
if ( V_941 )
F_47 ( & V_159 -> args ) ;
V_166 . V_321 = & V_159 -> args ;
V_166 . V_322 = & V_159 -> V_56 ;
V_159 -> V_63 = V_63 ;
V_324 . V_173 = V_159 ;
return F_77 ( & V_324 ) ;
}
static int F_567 ( struct V_62 * V_63 , struct V_323 * V_357 , unsigned V_619 )
{
struct V_102 * V_103 ;
int V_51 = 0 ;
if ( ( V_619 & V_944 ) == 0 )
return - V_108 ;
V_103 = F_566 ( V_63 , V_357 , false ) ;
if ( F_51 ( V_103 ) )
V_51 = F_78 ( V_103 ) ;
else
F_481 ( V_103 ) ;
F_8 ( L_16 , V_34 , V_51 ) ;
return V_51 ;
}
static int F_568 ( struct V_62 * V_63 , struct V_323 * V_357 )
{
struct V_102 * V_103 ;
int V_51 ;
V_103 = F_566 ( V_63 , V_357 , true ) ;
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
static void F_569 ( struct V_102 * V_103 , void * V_161 )
{
struct V_945 * V_159 = V_161 ;
F_68 ( V_159 -> V_63 -> V_87 ,
& V_159 -> V_403 . V_163 ,
& V_159 -> V_56 . V_164 ,
V_103 ) ;
}
static int F_570 ( struct V_102 * V_103 , struct V_62 * V_63 )
{
switch( V_103 -> V_107 ) {
case 0 :
case - V_946 :
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
static void F_571 ( struct V_102 * V_103 , void * V_161 )
{
struct V_945 * V_159 = V_161 ;
struct V_62 * V_63 = V_159 -> V_63 ;
struct V_119 * V_56 = & V_159 -> V_56 . V_164 ;
F_8 ( L_11 , V_34 ) ;
if ( ! F_60 ( V_103 , V_56 ) )
return;
F_572 ( V_63 , V_103 -> V_107 ) ;
if ( F_570 ( V_103 , V_63 ) == - V_108 ) {
F_65 ( V_103 ) ;
return;
}
F_8 ( L_82 , V_34 ) ;
}
static void F_573 ( void * V_161 )
{
struct V_945 * V_159 = V_161 ;
F_105 ( V_159 ) ;
}
static int F_574 ( struct V_62 * V_63 ,
struct V_323 * V_357 )
{
struct V_945 * V_159 ;
struct V_102 * V_103 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_947 ] ,
. V_323 = V_357 ,
} ;
struct V_167 V_324 = {
. V_169 = V_63 -> V_110 ,
. V_165 = & V_166 ,
. V_170 = & V_948 ,
. V_219 = V_328 ,
} ;
int V_313 = - V_132 ;
F_8 ( L_11 , V_34 ) ;
V_159 = F_95 ( sizeof( * V_159 ) , V_310 ) ;
if ( V_159 == NULL )
goto V_136;
V_159 -> V_63 = V_63 ;
V_159 -> V_403 . V_949 = 0 ;
F_46 ( & V_159 -> V_403 . V_163 , & V_159 -> V_56 . V_164 , 0 ) ;
F_47 ( & V_159 -> V_403 . V_163 ) ;
V_166 . V_321 = & V_159 -> V_403 ;
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
F_575 ( struct V_102 * V_103 , void * V_159 )
{
struct V_950 * V_951 = V_159 ;
struct V_13 * V_14 = F_94 ( V_951 -> args . V_2 ) ;
struct V_138 * V_139 = F_71 ( V_14 ) ;
F_8 ( L_11 , V_34 ) ;
F_68 ( V_139 , & V_951 -> args . V_163 ,
& V_951 -> V_56 . V_164 , V_103 ) ;
F_8 ( L_82 , V_34 ) ;
}
static void F_576 ( struct V_102 * V_103 , void * V_159 )
{
struct V_950 * V_951 = V_159 ;
F_8 ( L_11 , V_34 ) ;
F_60 ( V_103 , & V_951 -> V_56 . V_164 ) ;
F_8 ( L_82 , V_34 ) ;
}
static int
F_577 ( struct V_102 * V_103 ,
struct V_950 * V_951 , struct V_60 * V_61 )
{
struct V_2 * V_2 = V_951 -> args . V_2 ;
struct V_13 * V_14 = F_94 ( V_2 ) ;
struct V_952 * V_953 ;
int V_313 = V_103 -> V_107 ;
F_8 ( L_98 , V_34 , - V_103 -> V_107 ) ;
switch ( V_313 ) {
case 0 :
goto V_136;
case - V_954 :
V_313 = - V_955 ;
goto V_136;
case - V_956 :
V_313 = - V_957 ;
goto V_136;
case - V_19 :
if ( V_951 -> args . V_958 == 0 ) {
V_313 = - V_957 ;
goto V_136;
}
case - V_20 :
F_31 ( V_14 , - V_20 ,
V_61 ) ;
V_313 = - V_959 ;
goto V_136;
case - V_74 :
case - V_72 :
V_61 -> V_50 = 0 ;
F_41 ( & V_2 -> V_178 ) ;
if ( F_146 ( & V_951 -> args . V_257 ,
& V_951 -> args . V_308 -> V_65 -> V_257 ) ) {
F_43 ( & V_2 -> V_178 ) ;
V_61 -> V_65 = V_951 -> args . V_308 -> V_65 ;
break;
}
V_953 = F_82 ( V_2 ) -> V_960 ;
if ( V_953 && ! F_33 ( V_961 , & V_953 -> V_962 ) &&
F_130 ( & V_951 -> args . V_257 , & V_953 -> V_963 ) ) {
F_578 ( V_964 ) ;
F_133 ( V_961 , & V_953 -> V_962 ) ;
F_579 ( V_953 , & V_964 , NULL , 0 ) ;
F_43 ( & V_2 -> V_178 ) ;
F_580 ( & V_964 ) ;
V_313 = - V_108 ;
goto V_136;
} else
F_43 ( & V_2 -> V_178 ) ;
}
V_313 = F_31 ( V_14 , V_313 , V_61 ) ;
if ( V_61 -> V_68 )
V_313 = - V_108 ;
V_136:
F_8 ( L_82 , V_34 ) ;
return V_313 ;
}
static T_9 F_581 ( struct V_13 * V_14 )
{
T_1 V_915 = V_14 -> V_62 -> V_87 -> V_920 . V_915 ;
return F_582 ( 0 , V_915 ) ;
}
static void F_583 ( struct V_503 * * V_42 , T_9 V_965 )
{
int V_492 ;
if ( ! V_42 )
return;
for ( V_492 = 0 ; V_492 < V_965 ; V_492 ++ ) {
if ( ! V_42 [ V_492 ] )
break;
F_293 ( V_42 [ V_492 ] ) ;
}
F_105 ( V_42 ) ;
}
static struct V_503 * * F_584 ( T_9 V_965 , T_6 V_966 )
{
struct V_503 * * V_42 ;
int V_492 ;
V_42 = F_585 ( V_965 , sizeof( struct V_503 * ) , V_966 ) ;
if ( ! V_42 ) {
F_8 ( L_99 , V_34 , V_965 ) ;
return NULL ;
}
for ( V_492 = 0 ; V_492 < V_965 ; V_492 ++ ) {
V_42 [ V_492 ] = F_289 ( V_966 ) ;
if ( ! V_42 [ V_492 ] ) {
F_8 ( L_100 , V_34 ) ;
F_583 ( V_42 , V_965 ) ;
return NULL ;
}
}
return V_42 ;
}
static void F_586 ( void * V_159 )
{
struct V_950 * V_951 = V_159 ;
struct V_2 * V_2 = V_951 -> args . V_2 ;
struct V_13 * V_14 = F_94 ( V_2 ) ;
T_9 V_967 = F_581 ( V_14 ) ;
F_8 ( L_11 , V_34 ) ;
F_583 ( V_951 -> args . V_960 . V_42 , V_967 ) ;
F_587 ( F_82 ( V_2 ) -> V_960 ) ;
F_180 ( V_951 -> args . V_308 ) ;
F_105 ( V_159 ) ;
F_8 ( L_82 , V_34 ) ;
}
struct V_968 *
F_588 ( struct V_950 * V_951 , long * V_50 , T_6 V_966 )
{
struct V_2 * V_2 = V_951 -> args . V_2 ;
struct V_13 * V_14 = F_94 ( V_2 ) ;
T_9 V_967 = F_581 ( V_14 ) ;
struct V_102 * V_103 ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_969 ] ,
. V_321 = & V_951 -> args ,
. V_322 = & V_951 -> V_56 ,
. V_323 = V_951 -> V_357 ,
} ;
struct V_167 V_324 = {
. V_169 = V_14 -> V_98 ,
. V_165 = & V_166 ,
. V_170 = & V_970 ,
. V_173 = V_951 ,
. V_219 = V_328 ,
} ;
struct V_968 * V_971 = NULL ;
struct V_60 V_61 = {
. V_2 = V_2 ,
. V_50 = * V_50 ,
} ;
int V_313 = 0 ;
F_8 ( L_11 , V_34 ) ;
F_589 ( F_82 ( V_2 ) -> V_960 ) ;
V_951 -> args . V_960 . V_42 = F_584 ( V_967 , V_966 ) ;
if ( ! V_951 -> args . V_960 . V_42 ) {
F_586 ( V_951 ) ;
return F_52 ( - V_132 ) ;
}
V_951 -> args . V_960 . V_530 = V_967 * V_628 ;
V_951 -> V_56 . V_972 = & V_951 -> args . V_960 ;
V_951 -> V_56 . V_164 . V_124 = NULL ;
F_46 ( & V_951 -> args . V_163 , & V_951 -> V_56 . V_164 , 0 ) ;
V_103 = F_77 ( & V_324 ) ;
if ( F_51 ( V_103 ) )
return F_269 ( V_103 ) ;
V_313 = F_116 ( V_103 ) ;
if ( V_313 == 0 ) {
V_313 = F_577 ( V_103 , V_951 , & V_61 ) ;
* V_50 = V_61 . V_50 ;
}
F_590 ( V_951 -> args . V_308 ,
& V_951 -> args . V_973 ,
& V_951 -> V_56 . V_973 ,
& V_951 -> V_56 . V_257 ,
V_313 ) ;
if ( V_313 == 0 && V_951 -> V_56 . V_972 -> V_12 )
V_971 = F_591 ( V_951 ) ;
F_79 ( V_103 ) ;
F_8 ( L_16 , V_34 , V_313 ) ;
if ( V_313 )
return F_52 ( V_313 ) ;
return V_971 ;
}
static void
F_592 ( struct V_102 * V_103 , void * V_159 )
{
struct V_974 * V_975 = V_159 ;
F_8 ( L_11 , V_34 ) ;
F_68 ( V_975 -> V_63 -> V_87 ,
& V_975 -> args . V_163 ,
& V_975 -> V_56 . V_164 ,
V_103 ) ;
}
static void F_593 ( struct V_102 * V_103 , void * V_159 )
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
static void F_594 ( void * V_159 )
{
struct V_974 * V_975 = V_159 ;
struct V_952 * V_953 = V_975 -> args . V_960 ;
F_578 ( V_976 ) ;
F_8 ( L_11 , V_34 ) ;
F_41 ( & V_953 -> V_977 -> V_178 ) ;
F_579 ( V_953 , & V_976 , & V_975 -> args . V_973 ,
F_595 ( V_975 -> args . V_257 . V_209 ) ) ;
F_596 ( V_953 ) ;
if ( V_975 -> V_56 . V_978 )
F_597 ( V_953 , & V_975 -> V_56 . V_257 , true ) ;
F_598 ( V_953 ) ;
F_43 ( & V_953 -> V_977 -> V_178 ) ;
F_580 ( & V_976 ) ;
F_587 ( V_975 -> args . V_960 ) ;
F_449 ( V_975 -> V_2 ) ;
F_105 ( V_159 ) ;
F_8 ( L_82 , V_34 ) ;
}
int F_599 ( struct V_974 * V_975 , bool V_979 )
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
V_859 ,
& V_324 . V_169 , & V_166 ) ;
F_8 ( L_11 , V_34 ) ;
if ( ! V_979 ) {
V_975 -> V_2 = F_452 ( V_975 -> args . V_2 ) ;
if ( ! V_975 -> V_2 ) {
F_594 ( V_975 ) ;
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
F_600 ( V_975 -> args . V_2 , & V_975 -> args . V_257 , V_313 ) ;
F_8 ( L_16 , V_34 , V_313 ) ;
F_79 ( V_103 ) ;
return V_313 ;
}
static int
F_601 ( struct V_13 * V_14 ,
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
F_8 ( L_101 , V_34 ) ;
if ( V_56 . V_990 != args . V_985 )
V_983 -> V_991 = 1 ;
F_8 ( L_16 , V_34 , V_313 ) ;
return V_313 ;
}
int F_602 ( struct V_13 * V_14 ,
struct V_982 * V_983 ,
struct V_323 * V_357 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_31 ( V_14 ,
F_601 ( V_14 , V_983 , V_357 ) ,
& V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static void F_603 ( struct V_102 * V_103 , void * V_159 )
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
F_604 ( struct V_102 * V_103 , void * V_159 )
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
static void F_605 ( void * V_159 )
{
struct V_992 * V_161 = V_159 ;
F_606 ( V_161 ) ;
F_453 ( V_161 -> args . V_2 ,
V_161 -> V_56 . V_400 ) ;
F_222 ( V_161 -> V_357 ) ;
F_449 ( V_161 -> V_2 ) ;
F_105 ( V_161 ) ;
}
int
F_607 ( struct V_992 * V_161 , bool V_979 )
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
F_8 ( L_102
L_103 , V_979 ,
V_161 -> args . V_996 ,
V_161 -> args . V_2 -> V_997 ) ;
if ( ! V_979 ) {
V_161 -> V_2 = F_452 ( V_161 -> args . V_2 ) ;
if ( V_161 -> V_2 == NULL ) {
F_605 ( V_161 ) ;
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
F_608 ( V_161 -> args . V_2 , & V_161 -> args . V_257 , V_313 ) ;
F_8 ( L_104 , V_34 , V_313 ) ;
F_79 ( V_103 ) ;
return V_313 ;
}
static int
F_609 ( struct V_13 * V_14 , struct V_438 * V_439 ,
struct V_478 * V_479 ,
struct V_804 * V_495 , bool V_805 )
{
struct V_998 args = {
. V_999 = V_1000 ,
} ;
struct V_807 V_56 = {
. V_495 = V_495 ,
} ;
struct V_165 V_166 = {
. V_318 = & V_319 [ V_1001 ] ,
. V_321 = & args ,
. V_322 = & V_56 ,
} ;
struct V_54 * V_55 = V_14 -> V_98 ;
struct V_323 * V_357 = NULL ;
int V_313 ;
if ( V_805 ) {
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
F_610 ( struct V_13 * V_14 , struct V_438 * V_439 ,
struct V_478 * V_479 , struct V_804 * V_495 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_39 ( V_14 -> V_62 ) )
V_8 = F_609 ( V_14 , V_439 , V_479 ,
V_495 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_609 ( V_14 , V_439 , V_479 ,
V_495 , false ) ;
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
F_611 ( struct V_13 * V_14 , struct V_438 * V_439 ,
struct V_478 * V_479 )
{
int V_8 ;
struct V_503 * V_503 ;
T_4 V_109 = V_1003 ;
struct V_804 * V_495 ;
struct V_1004 * V_1005 ;
int V_492 ;
V_503 = F_289 ( V_390 ) ;
if ( ! V_503 ) {
V_8 = - V_132 ;
goto V_136;
}
V_495 = F_405 ( V_503 ) ;
V_8 = F_610 ( V_14 , V_439 , V_479 , V_495 ) ;
if ( V_8 == - V_22 || V_8 == - V_1002 ) {
V_8 = F_280 ( V_14 , V_439 , V_479 ) ;
goto V_1006;
}
if ( V_8 )
goto V_1006;
for ( V_492 = 0 ; V_492 < V_495 -> V_1007 ; V_492 ++ ) {
V_1005 = & V_495 -> V_495 [ V_492 ] ;
switch ( V_1005 -> V_109 ) {
case V_491 :
case V_490 :
case V_1008 :
V_109 = F_612 ( V_1005 -> V_109 ,
& V_1005 -> V_1009 ) ;
break;
default:
V_109 = V_1003 ;
break;
}
if ( ! F_613 ( & V_14 -> V_493 , V_109 ) )
V_109 = V_1003 ;
if ( V_109 != V_1003 ) {
V_8 = F_278 ( V_14 , V_439 ,
V_479 , V_109 ) ;
if ( ! V_8 )
break;
}
}
if ( V_109 == V_1003 )
V_8 = - V_24 ;
V_1006:
F_419 ( V_503 ) ;
if ( V_8 == - V_29 )
return - V_24 ;
V_136:
return V_8 ;
}
static int F_614 ( struct V_13 * V_14 ,
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
F_267 ( V_14 -> V_62 , V_864 ,
& V_169 , & V_166 ) ;
F_8 ( L_105 , V_257 ) ;
F_46 ( & args . V_163 , & V_56 . V_164 , 0 ) ;
F_47 ( & args . V_163 ) ;
V_313 = F_76 ( V_169 , V_14 , & V_166 ,
& args . V_163 , & V_56 . V_164 ) ;
if ( V_313 != V_370 ) {
F_8 ( L_106 , V_313 ) ;
return V_313 ;
}
F_8 ( L_107 , - V_56 . V_313 ) ;
return - V_56 . V_313 ;
}
static int F_219 ( struct V_13 * V_14 ,
T_8 * V_257 ,
struct V_323 * V_357 )
{
struct V_60 V_61 = { } ;
int V_8 ;
do {
V_8 = F_614 ( V_14 , V_257 , V_357 ) ;
if ( V_8 != - V_89 )
break;
F_31 ( V_14 , V_8 , & V_61 ) ;
} while ( V_61 . V_68 );
return V_8 ;
}
static void F_615 ( struct V_102 * V_103 , void * V_159 )
{
struct V_1013 * V_161 = V_159 ;
F_68 ( F_71 ( V_161 -> V_14 ) ,
& V_161 -> args . V_163 ,
& V_161 -> V_56 . V_164 ,
V_103 ) ;
}
static void F_616 ( struct V_102 * V_103 , void * V_159 )
{
struct V_1013 * V_161 = V_159 ;
F_60 ( V_103 , & V_161 -> V_56 . V_164 ) ;
switch ( V_103 -> V_107 ) {
case - V_89 :
if ( F_38 ( V_103 , V_161 -> V_14 , NULL , NULL ) == - V_108 )
F_65 ( V_103 ) ;
}
}
static void F_617 ( void * V_159 )
{
F_105 ( V_159 ) ;
}
static struct V_102 * F_618 ( struct V_13 * V_14 ,
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
F_267 ( V_14 -> V_62 , V_864 ,
& V_168 . V_169 , & V_166 ) ;
F_8 ( L_108 , V_257 ) ;
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
V_103 = F_618 ( V_14 , V_257 , V_357 , true ) ;
if ( F_51 ( V_103 ) )
return F_78 ( V_103 ) ;
V_51 = F_117 ( V_103 ) ;
if ( ! V_51 )
V_51 = V_103 -> V_107 ;
F_79 ( V_103 ) ;
return V_51 ;
}
static void
F_619 ( struct V_13 * V_14 , struct V_289 * V_290 )
{
struct V_102 * V_103 ;
struct V_323 * V_357 = V_290 -> V_291 -> V_232 -> V_298 ;
V_103 = F_618 ( V_14 , & V_290 -> V_293 , V_357 , false ) ;
F_502 ( V_14 , V_290 ) ;
if ( F_51 ( V_103 ) )
return;
F_79 ( V_103 ) ;
}
static bool F_620 ( const T_8 * V_1017 ,
const T_8 * V_1018 )
{
if ( V_1017 -> type != V_1018 -> type )
return false ;
if ( memcmp ( V_1017 -> V_1019 , V_1018 -> V_1019 , sizeof( V_1017 -> V_1019 ) ) != 0 )
return false ;
if ( V_1017 -> V_209 == V_1018 -> V_209 )
return true ;
if ( V_1017 -> V_209 == 0 || V_1018 -> V_209 == 0 )
return true ;
return false ;
}
static bool F_621 ( const T_8 * V_1017 ,
const T_8 * V_1018 )
{
return F_146 ( V_1017 , V_1018 ) ;
}
static struct V_223 *
F_622 ( struct V_225 * V_1020 , T_6 V_1021 )
{
return NULL ;
}
T_11 F_623 ( struct V_4 * V_4 , char * V_776 , T_9 V_965 )
{
T_11 error , V_1022 ;
error = F_624 ( V_4 , V_776 , V_965 ) ;
if ( error < 0 )
return error ;
if ( V_776 ) {
V_776 += error ;
V_965 -= error ;
}
V_1022 = F_510 ( F_14 ( V_4 ) , V_776 , V_965 ) ;
if ( V_1022 < 0 )
return V_1022 ;
return error + V_1022 ;
}
