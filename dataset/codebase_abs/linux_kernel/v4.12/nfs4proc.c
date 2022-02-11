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
static void F_16 ( struct V_13 * V_14 ,
T_4 * V_50 ,
struct V_51 * V_52 )
{
const struct V_53 * V_54 = V_14 -> V_55 -> V_56 ;
V_54 -> V_57 ( V_14 , V_50 , V_52 ) ;
}
static void F_17 ( struct V_13 * V_14 ,
T_4 * V_50 ,
struct V_51 * V_52 )
{
V_50 -> type = V_58 ;
F_16 ( V_14 , V_50 , V_52 ) ;
}
static void F_18 ( struct V_13 * V_14 ,
const T_4 * V_50 ,
struct V_51 * V_52 )
{
T_4 V_59 ;
F_19 ( & V_59 , V_50 ) ;
F_17 ( V_14 , & V_59 , V_52 ) ;
}
static long F_20 ( long * V_60 )
{
long V_61 ;
if ( ! V_60 )
return V_62 ;
if ( * V_60 <= 0 )
* V_60 = V_63 ;
if ( * V_60 > V_62 )
* V_60 = V_62 ;
V_61 = * V_60 ;
* V_60 <<= 1 ;
return V_61 ;
}
static int F_21 ( struct V_64 * V_65 , long * V_60 )
{
int V_66 = 0 ;
F_22 () ;
F_23 (
F_20 ( V_60 ) ) ;
if ( F_24 ( V_67 ) )
V_66 = - V_68 ;
return V_66 ;
}
static int F_25 ( struct V_13 * V_14 ,
int V_69 , struct V_70 * V_71 )
{
struct V_55 * V_72 = V_14 -> V_55 ;
struct V_73 * V_74 = V_71 -> V_74 ;
const T_4 * V_50 = V_71 -> V_50 ;
struct V_2 * V_2 = V_71 -> V_2 ;
int V_61 = V_69 ;
V_71 -> V_75 = 0 ;
V_71 -> V_76 = 0 ;
V_71 -> V_77 = 0 ;
if ( V_50 == NULL && V_74 != NULL )
V_50 = & V_74 -> V_50 ;
switch( V_69 ) {
case 0 :
return 0 ;
case - V_78 :
case - V_79 :
case - V_80 :
case - V_81 :
if ( V_2 != NULL && V_50 != NULL ) {
F_26 ( V_2 ,
V_50 ) ;
goto V_82;
}
case - V_83 :
if ( V_2 ) {
int V_8 ;
V_8 = F_27 ( V_2 ,
V_50 ) ;
if ( V_8 == 0 )
goto V_82;
if ( V_50 != NULL && V_50 -> type == V_84 ) {
V_71 -> V_77 = 1 ;
break;
}
}
if ( V_74 == NULL )
break;
V_61 = F_28 ( V_14 , V_74 ) ;
if ( V_61 < 0 )
break;
goto V_82;
case - V_85 :
case - V_86 :
F_29 ( V_72 ) ;
goto V_82;
case - V_87 :
V_61 = F_30 ( V_14 ) ;
if ( V_61 < 0 )
break;
goto V_82;
case - V_88 :
F_31 ( V_72 ) ;
goto V_82;
#if F_32 ( V_89 )
case - V_90 :
case - V_91 :
case - V_92 :
case - V_93 :
case - V_94 :
case - V_95 :
case - V_96 :
F_8 ( L_4 , V_34 ,
V_69 ) ;
F_33 ( V_72 -> V_97 , V_69 ) ;
goto V_82;
#endif
case - V_32 :
if ( V_71 -> V_60 > V_98 ) {
V_61 = - V_33 ;
break;
}
case - V_99 :
F_34 ( V_14 , V_100 ) ;
case - V_101 :
case - V_19 :
case - V_20 :
V_71 -> V_75 = 1 ;
return 0 ;
case - V_102 :
case - V_103 :
V_71 -> V_77 = 1 ;
break;
case - V_25 :
case - V_26 :
if ( V_14 -> V_104 & V_105 ) {
V_14 -> V_104 &= ~ V_105 ;
V_71 -> V_77 = 1 ;
F_35 ( V_106 L_5
L_6
L_7
L_8 ,
V_14 -> V_55 -> V_107 ) ;
}
}
return F_7 ( V_61 ) ;
V_82:
V_71 -> V_76 = 1 ;
return 0 ;
}
int F_36 ( struct V_13 * V_14 , int V_69 , struct V_70 * V_71 )
{
struct V_55 * V_72 = V_14 -> V_55 ;
int V_61 ;
V_61 = F_25 ( V_14 , V_69 , V_71 ) ;
if ( V_71 -> V_75 ) {
V_61 = F_21 ( V_14 -> V_108 , & V_71 -> V_60 ) ;
goto V_109;
}
if ( V_71 -> V_76 ) {
V_61 = F_37 ( V_72 ) ;
if ( F_38 ( V_110 , & V_14 -> V_111 ) )
return - V_35 ;
goto V_109;
}
return V_61 ;
V_109:
if ( V_61 == 0 )
V_71 -> V_77 = 1 ;
return V_61 ;
}
static int
F_39 ( struct V_112 * V_113 , struct V_13 * V_14 ,
int V_69 , struct V_70 * V_71 )
{
struct V_55 * V_72 = V_14 -> V_55 ;
int V_61 ;
V_61 = F_25 ( V_14 , V_69 , V_71 ) ;
if ( V_71 -> V_75 ) {
F_40 ( V_113 , F_20 ( & V_71 -> V_60 ) ) ;
goto V_109;
}
if ( V_71 -> V_76 ) {
F_41 ( & V_72 -> V_114 , V_113 , NULL ) ;
if ( F_38 ( V_115 , & V_72 -> V_116 ) == 0 )
F_42 ( & V_72 -> V_114 , V_113 ) ;
goto V_109;
}
if ( F_38 ( V_110 , & V_14 -> V_111 ) )
V_61 = - V_35 ;
return V_61 ;
V_109:
if ( V_61 == 0 )
V_71 -> V_77 = 1 ;
return V_61 ;
}
static int
F_43 ( struct V_112 * V_113 , struct V_13 * V_14 ,
struct V_73 * V_74 , long * V_60 )
{
struct V_70 V_71 = {
. V_74 = V_74 ,
} ;
if ( V_113 -> V_117 >= 0 )
return 0 ;
if ( V_60 )
V_71 . V_60 = * V_60 ;
V_113 -> V_117 = F_39 ( V_113 , V_14 ,
V_113 -> V_117 ,
& V_71 ) ;
if ( V_71 . V_75 && V_60 )
* V_60 = V_71 . V_60 ;
if ( V_71 . V_77 )
return - V_118 ;
return 0 ;
}
static bool F_44 ( struct V_55 * V_72 )
{
T_5 V_119 = V_72 -> V_120 -> V_121 -> V_122 ;
return ( V_119 == V_123 ) || ( V_119 == V_124 ) ;
}
static void F_45 ( struct V_55 * V_72 , unsigned long V_125 )
{
F_46 ( & V_72 -> V_126 ) ;
if ( F_47 ( V_72 -> V_127 , V_125 ) )
V_72 -> V_127 = V_125 ;
F_48 ( & V_72 -> V_126 ) ;
}
static void F_49 ( const struct V_13 * V_14 , unsigned long V_125 )
{
struct V_55 * V_72 = V_14 -> V_55 ;
if ( ! F_50 ( V_72 ) )
F_45 ( V_72 , V_125 ) ;
}
void F_51 ( struct V_128 * args ,
struct V_129 * V_66 , int V_130 )
{
args -> V_131 = NULL ;
args -> V_132 = V_130 ;
args -> V_133 = 0 ;
V_66 -> V_134 = NULL ;
}
static void F_52 ( struct V_128 * args )
{
args -> V_133 = 1 ;
}
static void F_53 ( struct V_129 * V_66 )
{
struct V_135 * V_136 = V_66 -> V_134 ;
struct V_137 * V_138 ;
V_138 = V_136 -> V_139 ;
F_46 ( & V_138 -> V_140 ) ;
if ( ! F_54 ( V_138 , V_136 ) )
F_55 ( V_138 , V_136 ) ;
F_48 ( & V_138 -> V_140 ) ;
V_66 -> V_134 = NULL ;
}
static int F_56 ( struct V_112 * V_113 ,
struct V_129 * V_66 )
{
if ( V_66 -> V_134 != NULL )
F_53 ( V_66 ) ;
return 1 ;
}
static void F_57 ( struct V_129 * V_66 )
{
struct V_141 * V_142 ;
struct V_137 * V_138 ;
struct V_135 * V_136 = V_66 -> V_134 ;
bool V_143 = false ;
V_138 = V_136 -> V_139 ;
V_142 = V_138 -> V_142 ;
if ( V_136 -> V_144 )
V_136 -> V_145 ++ ;
V_136 -> V_144 = 0 ;
F_46 ( & V_138 -> V_140 ) ;
if ( V_138 -> V_146 > V_138 -> V_147 )
V_143 = true ;
if ( F_54 ( V_138 , V_136 ) ) {
V_143 = false ;
goto V_148;
}
F_55 ( V_138 , V_136 ) ;
if ( V_138 -> V_146 != V_149 )
V_143 = false ;
V_148:
F_48 ( & V_138 -> V_140 ) ;
V_66 -> V_134 = NULL ;
if ( V_143 )
F_58 ( V_142 -> V_72 ) ;
if ( F_59 ( & V_138 -> V_150 ) )
F_60 ( & V_138 -> V_150 ) ;
}
static int F_61 ( struct V_112 * V_113 ,
struct V_129 * V_66 )
{
struct V_141 * V_142 ;
struct V_135 * V_136 = V_66 -> V_134 ;
struct V_55 * V_72 ;
bool V_151 = false ;
int V_61 = 1 ;
if ( V_136 == NULL )
goto V_152;
if ( ! F_62 ( V_113 ) )
goto V_153;
V_142 = V_136 -> V_139 -> V_142 ;
if ( V_136 -> V_151 ) {
if ( V_66 -> V_154 != - V_99 )
V_136 -> V_151 = 0 ;
V_151 = true ;
}
F_63 ( V_142 , V_66 ) ;
switch ( V_66 -> V_154 ) {
case 0 :
if ( V_113 -> V_117 == - V_21 && V_151 ) {
++ V_136 -> V_145 ;
goto V_155;
}
V_136 -> V_144 = 1 ;
V_72 = V_142 -> V_72 ;
F_45 ( V_72 , V_66 -> V_156 ) ;
F_64 ( V_72 , V_66 -> V_157 ,
! ! V_136 -> V_158 ) ;
F_65 ( V_136 -> V_139 , V_136 , V_66 ) ;
break;
case 1 :
V_136 -> V_151 = 1 ;
goto V_153;
case - V_99 :
F_8 ( L_9 ,
V_34 ,
V_136 -> V_159 ,
V_136 -> V_145 ) ;
goto V_109;
case - V_91 :
goto V_155;
case - V_96 :
if ( V_151 ) {
++ V_136 -> V_145 ;
goto V_155;
}
if ( V_136 -> V_145 != 1 ) {
V_136 -> V_145 = 1 ;
goto V_155;
}
break;
case - V_95 :
++ V_136 -> V_145 ;
goto V_155;
default:
V_136 -> V_144 = 1 ;
}
V_153:
F_8 ( L_10 , V_34 , V_66 -> V_154 ) ;
V_152:
return V_61 ;
V_155:
if ( F_66 ( V_113 ) ) {
F_57 ( V_66 ) ;
V_113 -> V_117 = 0 ;
V_61 = 0 ;
}
goto V_153;
V_109:
if ( ! F_67 ( V_113 ) )
goto V_153;
F_40 ( V_113 , V_62 ) ;
return 0 ;
}
int F_68 ( struct V_112 * V_113 , struct V_129 * V_66 )
{
if ( ! F_61 ( V_113 , V_66 ) )
return 0 ;
if ( V_66 -> V_134 != NULL )
F_57 ( V_66 ) ;
return 1 ;
}
static int F_69 ( struct V_112 * V_113 , struct V_129 * V_66 )
{
if ( V_66 -> V_134 == NULL )
return 1 ;
if ( V_66 -> V_134 -> V_139 -> V_142 != NULL )
return F_61 ( V_113 , V_66 ) ;
return F_56 ( V_113 , V_66 ) ;
}
static void F_70 ( struct V_129 * V_66 )
{
if ( V_66 -> V_134 != NULL ) {
if ( V_66 -> V_134 -> V_139 -> V_142 != NULL )
F_57 ( V_66 ) ;
else
F_53 ( V_66 ) ;
}
}
int F_71 ( struct V_112 * V_113 , struct V_129 * V_66 )
{
if ( V_66 -> V_134 == NULL )
return 1 ;
if ( ! V_66 -> V_134 -> V_139 -> V_142 )
return F_56 ( V_113 , V_66 ) ;
return F_68 ( V_113 , V_66 ) ;
}
static void F_72 ( struct V_112 * V_113 , void * V_160 )
{
struct V_161 * V_162 = V_160 ;
F_8 ( L_11 , V_34 , V_162 -> V_163 ) ;
F_73 ( V_162 -> V_163 -> V_55 ,
V_162 -> V_164 , V_162 -> V_165 , V_113 ) ;
}
static void F_74 ( struct V_112 * V_113 , void * V_160 )
{
struct V_161 * V_162 = V_160 ;
F_68 ( V_113 , V_162 -> V_165 ) ;
}
static int F_69 ( struct V_112 * V_113 , struct V_129 * V_66 )
{
return F_56 ( V_113 , V_66 ) ;
}
static void F_70 ( struct V_129 * V_66 )
{
if ( V_66 -> V_134 != NULL )
F_53 ( V_66 ) ;
}
int F_71 ( struct V_112 * V_113 ,
struct V_129 * V_66 )
{
return F_56 ( V_113 , V_66 ) ;
}
int F_73 ( const struct V_55 * V_108 ,
struct V_128 * args ,
struct V_129 * V_66 ,
struct V_112 * V_113 )
{
struct V_141 * V_142 = F_75 ( V_108 ) ;
struct V_137 * V_138 = V_108 -> V_166 ;
struct V_135 * V_136 ;
if ( V_66 -> V_134 != NULL )
goto V_167;
if ( V_142 ) {
V_138 = & V_142 -> V_168 ;
V_113 -> V_169 = 0 ;
}
F_46 ( & V_138 -> V_140 ) ;
if ( F_76 ( V_138 ) && ! args -> V_133 )
goto V_170;
V_136 = F_77 ( V_138 ) ;
if ( F_78 ( V_136 ) ) {
if ( V_136 == F_79 ( - V_171 ) )
V_113 -> V_169 = V_98 >> 2 ;
goto V_170;
}
F_48 ( & V_138 -> V_140 ) ;
V_136 -> V_158 = args -> V_133 ? 1 : 0 ;
args -> V_131 = V_136 ;
V_66 -> V_134 = V_136 ;
if ( V_142 ) {
V_66 -> V_156 = V_172 ;
V_66 -> V_157 = 0 ;
V_66 -> V_154 = 1 ;
}
F_80 ( V_142 , args ) ;
V_167:
F_81 ( V_113 ) ;
return 0 ;
V_170:
if ( args -> V_133 )
F_82 ( & V_138 -> V_173 , V_113 ,
NULL , V_174 ) ;
else
F_41 ( & V_138 -> V_173 , V_113 , NULL ) ;
F_48 ( & V_138 -> V_140 ) ;
return - V_118 ;
}
static void F_83 ( struct V_112 * V_113 , void * V_160 )
{
struct V_161 * V_162 = V_160 ;
F_73 ( V_162 -> V_163 -> V_55 ,
V_162 -> V_164 , V_162 -> V_165 , V_113 ) ;
}
static void F_84 ( struct V_112 * V_113 , void * V_160 )
{
struct V_161 * V_162 = V_160 ;
F_71 ( V_113 , V_162 -> V_165 ) ;
}
static int F_85 ( struct V_64 * V_65 ,
struct V_13 * V_14 ,
struct V_175 * V_176 ,
struct V_128 * args ,
struct V_129 * V_66 )
{
int V_61 ;
struct V_112 * V_113 ;
struct V_55 * V_72 = V_14 -> V_55 ;
struct V_161 V_162 = {
. V_163 = V_14 ,
. V_164 = args ,
. V_165 = V_66 ,
} ;
struct V_177 V_178 = {
. V_179 = V_65 ,
. V_175 = V_176 ,
. V_180 = V_72 -> V_56 -> V_181 ,
. V_182 = & V_162
} ;
V_113 = F_86 ( & V_178 ) ;
if ( F_78 ( V_113 ) )
V_61 = F_87 ( V_113 ) ;
else {
V_61 = V_113 -> V_117 ;
F_88 ( V_113 ) ;
}
return V_61 ;
}
int F_89 ( struct V_64 * V_65 ,
struct V_13 * V_14 ,
struct V_175 * V_176 ,
struct V_128 * args ,
struct V_129 * V_66 ,
int V_130 )
{
F_51 ( args , V_66 , V_130 ) ;
return F_85 ( V_65 , V_14 , V_176 , args , V_66 ) ;
}
static void F_90 ( struct V_2 * V_3 , struct V_183 * V_184 ,
unsigned long V_125 )
{
struct V_185 * V_186 = F_91 ( V_3 ) ;
F_46 ( & V_3 -> V_187 ) ;
V_186 -> V_188 |= V_189 | V_190 ;
if ( V_184 -> V_191 && V_184 -> V_192 == V_3 -> V_193 ) {
V_186 -> V_188 &= ~ V_194 ;
V_186 -> V_195 = V_172 ;
} else {
F_92 ( V_3 ) ;
if ( V_184 -> V_192 != V_3 -> V_193 )
V_186 -> V_188 |= V_196 |
V_197 ;
}
V_3 -> V_193 = V_184 -> V_198 ;
V_186 -> V_199 = V_125 ;
V_186 -> V_200 = F_93 () ;
F_94 ( V_3 ) ;
F_48 ( & V_3 -> V_187 ) ;
}
static bool F_95 ( struct V_13 * V_14 ,
int V_8 , struct V_70 * V_71 )
{
if ( V_8 != - V_27 )
return false ;
if ( ! ( V_14 -> V_104 & V_201 ) )
return false ;
V_14 -> V_104 &= ~ V_201 ;
V_71 -> V_77 = 1 ;
return true ;
}
static T_1
F_96 ( struct V_13 * V_14 ,
T_6 V_202 , int V_203 )
{
T_1 V_66 = 0 ;
switch ( V_202 & ( V_204 | V_205 ) ) {
case V_204 :
V_66 = V_206 ;
break;
case V_205 :
V_66 = V_207 ;
break;
case V_204 | V_205 :
V_66 = V_208 ;
}
if ( ! ( V_14 -> V_104 & V_201 ) )
goto V_153;
if ( V_203 & V_209 )
V_66 |= V_210 ;
V_153:
return V_66 ;
}
static enum V_211
F_97 ( struct V_13 * V_14 ,
enum V_211 V_212 )
{
if ( V_14 -> V_104 & V_201 )
return V_212 ;
switch ( V_212 ) {
default:
return V_212 ;
case V_213 :
return V_214 ;
case V_215 :
return V_216 ;
case V_217 :
return V_218 ;
}
}
static void F_98 ( struct V_219 * V_41 )
{
V_41 -> V_220 . V_221 = & V_41 -> V_221 ;
V_41 -> V_220 . V_222 = V_41 -> V_222 ;
V_41 -> V_220 . V_223 = V_41 -> V_224 . V_223 ;
V_41 -> V_225 . V_223 = V_41 -> V_226 . V_223 ;
V_41 -> V_220 . V_14 = V_41 -> V_224 . V_14 ;
V_41 -> V_220 . V_227 = V_41 -> V_224 . V_228 ;
F_99 ( & V_41 -> V_221 ) ;
F_100 ( & V_41 -> V_221 , & V_41 -> V_229 , & V_41 -> V_230 ) ;
}
static struct V_219 * F_101 ( struct V_4 * V_4 ,
struct V_231 * V_232 , T_6 V_202 , int V_233 ,
const struct V_5 * V_234 ,
struct V_1 * V_7 ,
enum V_211 V_212 ,
T_7 V_235 )
{
struct V_4 * V_236 = F_102 ( V_4 ) ;
struct V_2 * V_3 = F_14 ( V_236 ) ;
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_237 * ( * V_238 ) ( struct V_239 * , T_7 ) ;
struct V_219 * V_41 ;
V_41 = F_104 ( sizeof( * V_41 ) , V_235 ) ;
if ( V_41 == NULL )
goto V_8;
V_41 -> V_222 = F_105 ( V_14 , V_235 ) ;
if ( F_78 ( V_41 -> V_222 ) )
goto V_240;
V_41 -> V_241 = F_105 ( V_14 , V_235 ) ;
if ( F_78 ( V_41 -> V_241 ) )
goto V_242;
V_238 = V_14 -> V_55 -> V_56 -> V_238 ;
V_41 -> V_224 . V_223 = V_238 ( & V_232 -> V_243 , V_235 ) ;
if ( F_78 ( V_41 -> V_224 . V_223 ) )
goto V_244;
F_106 ( V_4 -> V_245 ) ;
V_41 -> V_4 = F_107 ( V_4 ) ;
V_41 -> V_3 = V_236 ;
V_41 -> V_246 = V_232 ;
F_108 ( & V_232 -> V_247 ) ;
V_41 -> V_224 . V_248 = V_233 ;
V_41 -> V_224 . V_202 = V_202 & ( V_204 | V_205 ) ;
V_41 -> V_224 . V_249 = F_109 () ;
V_41 -> V_224 . V_212 = F_97 ( V_14 , V_212 ) ;
V_41 -> V_224 . V_250 = F_96 ( V_14 ,
V_202 , V_233 ) ;
if ( ! ( V_233 & V_251 ) ) {
switch ( V_41 -> V_224 . V_212 ) {
default:
break;
case V_214 :
case V_213 :
V_41 -> V_224 . V_228 = V_252 |
V_253 |
V_254 |
V_255 ;
}
}
V_41 -> V_224 . V_256 = V_14 -> V_55 -> V_257 ;
V_41 -> V_224 . V_258 . V_259 = F_110 ( V_232 -> V_243 . V_259 ) ;
V_41 -> V_224 . V_258 . V_260 = V_232 -> V_243 . V_261 ;
V_41 -> V_224 . V_262 = & V_4 -> V_11 ;
V_41 -> V_224 . V_14 = V_14 ;
V_41 -> V_224 . V_263 = F_6 ( V_14 , V_7 ) ;
V_41 -> V_224 . V_264 = & V_265 [ 0 ] ;
V_41 -> V_224 . V_7 = F_111 ( V_41 -> V_241 , V_7 ) ;
switch ( V_41 -> V_224 . V_212 ) {
case V_214 :
case V_216 :
case V_218 :
V_41 -> V_224 . V_266 = F_112 ( V_3 ) ;
break;
case V_267 :
case V_213 :
case V_215 :
case V_217 :
V_41 -> V_224 . V_266 = F_112 ( F_14 ( V_4 ) ) ;
}
if ( V_234 != NULL && V_234 -> V_268 != 0 ) {
T_8 V_269 [ 2 ] ;
V_41 -> V_224 . V_270 . V_234 = & V_41 -> V_234 ;
memcpy ( & V_41 -> V_234 , V_234 , sizeof( V_41 -> V_234 ) ) ;
V_269 [ 0 ] = V_172 ;
V_269 [ 1 ] = V_67 -> V_271 ;
memcpy ( V_41 -> V_224 . V_270 . V_37 . V_162 , V_269 ,
sizeof( V_41 -> V_224 . V_270 . V_37 . V_162 ) ) ;
}
V_41 -> V_226 . V_266 = & V_41 -> V_220 . V_266 ;
V_41 -> V_226 . V_50 = & V_41 -> V_220 . V_50 ;
V_41 -> V_226 . V_223 = V_41 -> V_224 . V_223 ;
F_98 ( V_41 ) ;
F_113 ( & V_41 -> V_272 ) ;
return V_41 ;
V_244:
F_114 ( V_41 -> V_241 ) ;
V_242:
F_114 ( V_41 -> V_222 ) ;
V_240:
F_115 ( V_41 ) ;
V_8:
F_116 ( V_236 ) ;
return NULL ;
}
static void F_117 ( struct V_272 * V_272 )
{
struct V_219 * V_41 = F_118 ( V_272 ,
struct V_219 , V_272 ) ;
struct V_273 * V_274 = V_41 -> V_4 -> V_245 ;
F_119 ( V_41 -> V_224 . V_223 ) ;
F_70 ( & V_41 -> V_220 . V_165 ) ;
if ( V_41 -> V_74 != NULL )
F_120 ( V_41 -> V_74 ) ;
F_121 ( V_41 -> V_246 ) ;
F_114 ( V_41 -> V_241 ) ;
F_114 ( V_41 -> V_222 ) ;
F_116 ( V_41 -> V_3 ) ;
F_116 ( V_41 -> V_4 ) ;
F_122 ( V_274 ) ;
F_123 ( & V_41 -> V_221 ) ;
F_115 ( V_41 -> V_221 . V_275 ) ;
F_115 ( V_41 ) ;
}
static void F_124 ( struct V_219 * V_41 )
{
if ( V_41 != NULL )
F_125 ( & V_41 -> V_272 , F_117 ) ;
}
static bool F_126 ( struct V_73 * V_74 ,
T_6 V_202 )
{
switch( V_202 & ( V_204 | V_205 ) ) {
case V_204 | V_205 :
return V_74 -> V_276 != 0 ;
case V_205 :
return V_74 -> V_277 != 0 ;
case V_204 :
return V_74 -> V_278 != 0 ;
}
F_127 ( 1 ) ;
return false ;
}
static int F_128 ( struct V_73 * V_74 , T_6 V_279 , int V_280 )
{
int V_61 = 0 ;
if ( V_280 & ( V_251 | V_281 ) )
goto V_153;
switch ( V_279 & ( V_204 | V_205 ) ) {
case V_204 :
V_61 |= F_38 ( V_282 , & V_74 -> V_233 ) != 0
&& V_74 -> V_278 != 0 ;
break;
case V_205 :
V_61 |= F_38 ( V_283 , & V_74 -> V_233 ) != 0
&& V_74 -> V_277 != 0 ;
break;
case V_204 | V_205 :
V_61 |= F_38 ( V_284 , & V_74 -> V_233 ) != 0
&& V_74 -> V_276 != 0 ;
}
V_153:
return V_61 ;
}
static int F_129 ( struct V_285 * V_286 , T_6 V_202 ,
enum V_211 V_212 )
{
if ( V_286 == NULL )
return 0 ;
if ( ( V_286 -> type & V_202 ) != V_202 )
return 0 ;
if ( F_38 ( V_287 , & V_286 -> V_233 ) )
return 0 ;
switch ( V_212 ) {
case V_214 :
case V_213 :
break;
case V_267 :
if ( ! F_38 ( V_288 , & V_286 -> V_233 ) )
break;
default:
return 0 ;
}
F_130 ( V_286 ) ;
return 1 ;
}
static void F_131 ( struct V_73 * V_74 , T_6 V_202 )
{
switch ( V_202 ) {
case V_205 :
V_74 -> V_277 ++ ;
break;
case V_204 :
V_74 -> V_278 ++ ;
break;
case V_204 | V_205 :
V_74 -> V_276 ++ ;
}
F_132 ( V_74 , V_74 -> V_74 | V_202 ) ;
}
static bool F_133 ( struct V_73 * V_74 )
{
if ( V_74 -> V_278 && ! F_38 ( V_282 , & V_74 -> V_233 ) )
return true ;
if ( V_74 -> V_277 && ! F_38 ( V_283 , & V_74 -> V_233 ) )
return true ;
if ( V_74 -> V_276 && ! F_38 ( V_284 , & V_74 -> V_233 ) )
return true ;
return false ;
}
static void F_134 ( struct V_73 * V_74 )
{
struct V_55 * V_72 = V_74 -> V_246 -> V_289 -> V_55 ;
bool V_290 = false ;
if ( F_135 ( V_282 , & V_74 -> V_233 ) && V_74 -> V_278 )
V_290 = true ;
if ( F_135 ( V_283 , & V_74 -> V_233 ) && V_74 -> V_277 )
V_290 = true ;
if ( F_135 ( V_284 , & V_74 -> V_233 ) && V_74 -> V_276 )
V_290 = true ;
if ( V_290 )
F_136 ( V_72 , V_74 ) ;
}
static bool F_137 ( struct V_73 * V_74 ,
const T_4 * V_50 , T_4 * V_291 )
{
if ( F_138 ( V_292 , & V_74 -> V_233 ) == 0 )
return true ;
if ( ! F_139 ( V_50 , & V_74 -> V_293 ) ) {
F_19 ( V_291 , & V_74 -> V_293 ) ;
F_134 ( V_74 ) ;
return true ;
}
if ( F_140 ( V_50 , & V_74 -> V_293 ) )
return true ;
return false ;
}
static void F_141 ( struct V_73 * V_74 )
{
if ( ! ( V_74 -> V_277 || V_74 -> V_278 || V_74 -> V_276 ) )
return;
if ( V_74 -> V_277 )
F_142 ( V_283 , & V_74 -> V_233 ) ;
if ( V_74 -> V_278 )
F_142 ( V_282 , & V_74 -> V_233 ) ;
if ( V_74 -> V_276 )
F_142 ( V_284 , & V_74 -> V_233 ) ;
F_142 ( V_292 , & V_74 -> V_233 ) ;
}
static void F_143 ( struct V_73 * V_74 ,
T_4 * V_50 , T_6 V_202 )
{
F_144 ( V_284 , & V_74 -> V_233 ) ;
switch ( V_202 & ( V_204 | V_205 ) ) {
case V_205 :
F_144 ( V_282 , & V_74 -> V_233 ) ;
break;
case V_204 :
F_144 ( V_283 , & V_74 -> V_233 ) ;
break;
case 0 :
F_144 ( V_282 , & V_74 -> V_233 ) ;
F_144 ( V_283 , & V_74 -> V_233 ) ;
F_144 ( V_292 , & V_74 -> V_233 ) ;
}
if ( V_50 == NULL )
return;
if ( F_139 ( V_50 , & V_74 -> V_293 ) &&
! F_140 ( V_50 , & V_74 -> V_293 ) ) {
F_141 ( V_74 ) ;
return;
}
if ( F_38 ( V_294 , & V_74 -> V_233 ) == 0 )
F_19 ( & V_74 -> V_50 , V_50 ) ;
F_19 ( & V_74 -> V_293 , V_50 ) ;
}
static void F_145 ( struct V_73 * V_74 ,
T_4 * V_295 ,
T_4 * V_50 , T_6 V_202 )
{
F_146 ( & V_74 -> V_296 ) ;
if ( F_147 ( V_74 , V_295 ) )
F_143 ( V_74 , V_50 , V_202 ) ;
F_148 ( & V_74 -> V_296 ) ;
if ( F_38 ( V_297 , & V_74 -> V_233 ) )
F_149 ( V_74 -> V_246 -> V_289 -> V_55 ) ;
}
static void F_150 ( struct V_73 * V_74 ,
const T_4 * V_50 , T_6 V_202 ,
T_4 * V_291 )
{
switch ( V_202 ) {
case V_204 :
F_142 ( V_282 , & V_74 -> V_233 ) ;
break;
case V_205 :
F_142 ( V_283 , & V_74 -> V_233 ) ;
break;
case V_204 | V_205 :
F_142 ( V_284 , & V_74 -> V_233 ) ;
}
if ( ! F_137 ( V_74 , V_50 , V_291 ) )
return;
if ( F_38 ( V_294 , & V_74 -> V_233 ) == 0 )
F_19 ( & V_74 -> V_50 , V_50 ) ;
F_19 ( & V_74 -> V_293 , V_50 ) ;
}
static void F_151 ( struct V_73 * V_74 ,
const T_4 * V_293 ,
const T_4 * V_298 ,
T_6 V_202 ,
T_4 * V_291 )
{
F_46 ( & V_74 -> V_246 -> V_299 ) ;
F_146 ( & V_74 -> V_296 ) ;
if ( V_298 != NULL ) {
F_19 ( & V_74 -> V_50 , V_298 ) ;
F_142 ( V_294 , & V_74 -> V_233 ) ;
}
if ( V_293 != NULL )
F_150 ( V_74 , V_293 , V_202 , V_291 ) ;
F_148 ( & V_74 -> V_296 ) ;
F_131 ( V_74 , V_202 ) ;
F_48 ( & V_74 -> V_246 -> V_299 ) ;
}
static int F_152 ( struct V_73 * V_74 ,
const T_4 * V_293 ,
const T_4 * V_286 ,
T_6 V_202 )
{
struct V_13 * V_14 = F_103 ( V_74 -> V_2 ) ;
struct V_55 * V_72 = V_14 -> V_55 ;
struct V_185 * V_186 = F_91 ( V_74 -> V_2 ) ;
struct V_285 * V_300 ;
T_4 V_291 = { } ;
int V_61 = 0 ;
V_202 &= ( V_204 | V_205 ) ;
F_153 () ;
V_300 = F_154 ( V_186 -> V_286 ) ;
if ( V_300 == NULL )
goto V_301;
F_46 ( & V_300 -> V_302 ) ;
if ( F_154 ( V_186 -> V_286 ) != V_300 ||
F_38 ( V_287 , & V_300 -> V_233 ) ||
( V_300 -> type & V_202 ) != V_202 )
goto V_303;
if ( V_286 == NULL )
V_286 = & V_300 -> V_50 ;
else if ( ! F_155 ( & V_300 -> V_50 , V_286 ) )
goto V_303;
F_130 ( V_300 ) ;
F_151 ( V_74 , V_293 , & V_300 -> V_50 ,
V_202 , & V_291 ) ;
V_61 = 1 ;
V_303:
F_48 ( & V_300 -> V_302 ) ;
V_301:
F_156 () ;
if ( ! V_61 && V_293 != NULL ) {
F_151 ( V_74 , V_293 , NULL , V_202 , & V_291 ) ;
V_61 = 1 ;
}
if ( F_38 ( V_297 , & V_74 -> V_233 ) )
F_149 ( V_72 ) ;
if ( V_291 . type != 0 )
F_16 ( V_14 , & V_291 ,
V_74 -> V_246 -> V_304 ) ;
return V_61 ;
}
static bool F_157 ( struct V_305 * V_306 ,
const T_4 * V_50 )
{
struct V_73 * V_74 = V_306 -> V_307 ;
bool V_61 = false ;
F_46 ( & V_74 -> V_308 ) ;
if ( ! F_139 ( V_50 , & V_306 -> V_309 ) )
goto V_310;
if ( ! F_140 ( V_50 , & V_306 -> V_309 ) )
goto V_310;
F_19 ( & V_306 -> V_309 , V_50 ) ;
V_61 = true ;
V_310:
F_48 ( & V_74 -> V_308 ) ;
return V_61 ;
}
static void F_158 ( struct V_2 * V_2 , T_6 V_202 )
{
struct V_285 * V_286 ;
F_153 () ;
V_286 = F_154 ( F_91 ( V_2 ) -> V_286 ) ;
if ( V_286 == NULL || ( V_286 -> type & V_202 ) == V_202 ) {
F_156 () ;
return;
}
F_156 () ;
F_159 ( V_2 ) ;
}
static struct V_73 * F_160 ( struct V_219 * V_311 )
{
struct V_73 * V_74 = V_311 -> V_74 ;
struct V_185 * V_186 = F_91 ( V_74 -> V_2 ) ;
struct V_285 * V_286 ;
int V_280 = V_311 -> V_224 . V_248 ;
T_6 V_202 = V_311 -> V_224 . V_202 ;
enum V_211 V_212 = V_311 -> V_224 . V_212 ;
T_4 V_50 ;
int V_61 = - V_118 ;
for (; ; ) {
F_46 ( & V_74 -> V_246 -> V_299 ) ;
if ( F_128 ( V_74 , V_202 , V_280 ) ) {
F_131 ( V_74 , V_202 ) ;
F_48 ( & V_74 -> V_246 -> V_299 ) ;
goto V_312;
}
F_48 ( & V_74 -> V_246 -> V_299 ) ;
F_153 () ;
V_286 = F_154 ( V_186 -> V_286 ) ;
if ( ! F_129 ( V_286 , V_202 , V_212 ) ) {
F_156 () ;
break;
}
F_19 ( & V_50 , & V_286 -> V_50 ) ;
F_156 () ;
F_161 ( V_311 -> V_224 . V_223 ) ;
if ( ! V_311 -> V_313 ) {
V_61 = F_162 ( V_74 -> V_2 , V_74 -> V_246 -> V_304 , V_280 ) ;
if ( V_61 != 0 )
goto V_153;
}
V_61 = - V_118 ;
if ( F_152 ( V_74 , NULL , & V_50 , V_202 ) )
goto V_312;
}
V_153:
return F_79 ( V_61 ) ;
V_312:
F_108 ( & V_74 -> V_49 ) ;
return V_74 ;
}
static void
F_163 ( struct V_219 * V_162 , struct V_73 * V_74 )
{
struct V_55 * V_72 = F_103 ( V_74 -> V_2 ) -> V_55 ;
struct V_285 * V_286 ;
int V_314 = 0 ;
F_153 () ;
V_286 = F_154 ( F_91 ( V_74 -> V_2 ) -> V_286 ) ;
if ( V_286 )
V_314 = V_286 -> V_233 ;
F_156 () ;
switch ( V_162 -> V_224 . V_212 ) {
default:
break;
case V_216 :
case V_215 :
F_164 ( L_12
L_13
L_14 ,
V_72 -> V_107 ) ;
return;
}
if ( ( V_314 & 1UL << V_288 ) == 0 )
F_165 ( V_74 -> V_2 ,
V_162 -> V_246 -> V_304 ,
& V_162 -> V_220 ) ;
else
F_166 ( V_74 -> V_2 ,
V_162 -> V_246 -> V_304 ,
& V_162 -> V_220 ) ;
}
static struct V_73 *
F_167 ( struct V_219 * V_162 )
{
struct V_2 * V_2 = V_162 -> V_74 -> V_2 ;
struct V_73 * V_74 = V_162 -> V_74 ;
int V_61 ;
if ( ! V_162 -> V_315 ) {
if ( V_162 -> V_316 )
return F_79 ( V_162 -> V_316 ) ;
goto V_317;
}
V_61 = F_168 ( V_2 , & V_162 -> V_221 ) ;
if ( V_61 )
return F_79 ( V_61 ) ;
if ( V_162 -> V_220 . V_318 != 0 )
F_163 ( V_162 , V_74 ) ;
V_317:
F_152 ( V_74 , & V_162 -> V_220 . V_50 , NULL ,
V_162 -> V_224 . V_202 ) ;
F_108 ( & V_74 -> V_49 ) ;
return V_74 ;
}
static struct V_73 *
F_169 ( struct V_219 * V_162 )
{
struct V_2 * V_2 ;
struct V_73 * V_74 = NULL ;
int V_61 ;
if ( ! V_162 -> V_315 ) {
V_74 = F_160 ( V_162 ) ;
F_170 ( V_162 -> V_74 ) ;
goto V_153;
}
V_61 = - V_118 ;
if ( ! ( V_162 -> V_221 . V_319 & V_320 ) )
goto V_8;
V_2 = F_171 ( V_162 -> V_3 -> V_245 , & V_162 -> V_220 . V_266 , & V_162 -> V_221 , V_162 -> V_222 ) ;
V_61 = F_87 ( V_2 ) ;
if ( F_78 ( V_2 ) )
goto V_8;
V_61 = - V_171 ;
V_74 = F_172 ( V_2 , V_162 -> V_246 ) ;
if ( V_74 == NULL )
goto V_321;
if ( V_162 -> V_220 . V_318 != 0 )
F_163 ( V_162 , V_74 ) ;
F_152 ( V_74 , & V_162 -> V_220 . V_50 , NULL ,
V_162 -> V_224 . V_202 ) ;
F_173 ( V_2 ) ;
V_153:
F_161 ( V_162 -> V_224 . V_223 ) ;
return V_74 ;
V_321:
F_173 ( V_2 ) ;
V_8:
return F_79 ( V_61 ) ;
}
static struct V_73 *
F_174 ( struct V_219 * V_162 )
{
struct V_73 * V_61 ;
if ( V_162 -> V_224 . V_212 == V_267 )
V_61 = F_167 ( V_162 ) ;
else
V_61 = F_169 ( V_162 ) ;
F_70 ( & V_162 -> V_220 . V_165 ) ;
return V_61 ;
}
static struct V_322 * F_175 ( struct V_73 * V_74 )
{
struct V_185 * V_186 = F_91 ( V_74 -> V_2 ) ;
struct V_322 * V_323 ;
F_46 ( & V_74 -> V_2 -> V_187 ) ;
F_176 (ctx, &nfsi->open_files, list) {
if ( V_323 -> V_74 != V_74 )
continue;
F_177 ( V_323 ) ;
F_48 ( & V_74 -> V_2 -> V_187 ) ;
return V_323 ;
}
F_48 ( & V_74 -> V_2 -> V_187 ) ;
return F_79 ( - V_324 ) ;
}
static struct V_219 * F_178 ( struct V_322 * V_323 ,
struct V_73 * V_74 , enum V_211 V_212 )
{
struct V_219 * V_311 ;
V_311 = F_101 ( V_323 -> V_4 , V_74 -> V_246 , 0 , 0 ,
NULL , NULL , V_212 , V_325 ) ;
if ( V_311 == NULL )
return F_79 ( - V_171 ) ;
V_311 -> V_74 = V_74 ;
F_108 ( & V_74 -> V_49 ) ;
return V_311 ;
}
static int F_179 ( struct V_219 * V_311 ,
T_6 V_202 )
{
struct V_73 * V_326 ;
int V_61 ;
if ( ! F_126 ( V_311 -> V_74 , V_202 ) )
return 0 ;
V_311 -> V_224 . V_248 = 0 ;
V_311 -> V_224 . V_202 = V_202 ;
V_311 -> V_224 . V_250 = F_96 (
F_180 ( V_311 -> V_4 -> V_245 ) ,
V_202 , 0 ) ;
memset ( & V_311 -> V_220 , 0 , sizeof( V_311 -> V_220 ) ) ;
memset ( & V_311 -> V_225 , 0 , sizeof( V_311 -> V_225 ) ) ;
F_98 ( V_311 ) ;
V_61 = F_181 ( V_311 ) ;
if ( V_61 != 0 )
return V_61 ;
V_326 = F_174 ( V_311 ) ;
if ( F_78 ( V_326 ) )
return F_87 ( V_326 ) ;
if ( V_326 != V_311 -> V_74 )
V_61 = - V_327 ;
F_182 ( V_326 , V_202 ) ;
return V_61 ;
}
static int F_183 ( struct V_219 * V_311 , struct V_73 * V_74 )
{
int V_61 ;
F_144 ( V_284 , & V_74 -> V_233 ) ;
F_144 ( V_283 , & V_74 -> V_233 ) ;
F_144 ( V_282 , & V_74 -> V_233 ) ;
F_144 ( V_294 , & V_74 -> V_233 ) ;
F_144 ( V_292 , & V_74 -> V_233 ) ;
F_184 () ;
V_61 = F_179 ( V_311 , V_204 | V_205 ) ;
if ( V_61 != 0 )
return V_61 ;
V_61 = F_179 ( V_311 , V_205 ) ;
if ( V_61 != 0 )
return V_61 ;
V_61 = F_179 ( V_311 , V_204 ) ;
if ( V_61 != 0 )
return V_61 ;
if ( F_38 ( V_294 , & V_74 -> V_233 ) == 0 &&
! F_155 ( & V_74 -> V_50 , & V_74 -> V_293 ) ) {
F_146 ( & V_74 -> V_296 ) ;
if ( F_38 ( V_294 , & V_74 -> V_233 ) == 0 )
F_19 ( & V_74 -> V_50 , & V_74 -> V_293 ) ;
F_148 ( & V_74 -> V_296 ) ;
}
return 0 ;
}
static int F_185 ( struct V_322 * V_323 , struct V_73 * V_74 )
{
struct V_285 * V_286 ;
struct V_219 * V_311 ;
T_6 V_318 = 0 ;
int V_328 ;
V_311 = F_178 ( V_323 , V_74 ,
V_267 ) ;
if ( F_78 ( V_311 ) )
return F_87 ( V_311 ) ;
F_153 () ;
V_286 = F_154 ( F_91 ( V_74 -> V_2 ) -> V_286 ) ;
if ( V_286 != NULL && F_38 ( V_288 , & V_286 -> V_233 ) != 0 )
V_318 = V_286 -> type ;
F_156 () ;
V_311 -> V_224 . V_270 . V_318 = V_318 ;
V_328 = F_183 ( V_311 , V_74 ) ;
F_124 ( V_311 ) ;
return V_328 ;
}
static int F_186 ( struct V_322 * V_323 , struct V_73 * V_74 )
{
struct V_13 * V_14 = F_103 ( V_74 -> V_2 ) ;
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_185 ( V_323 , V_74 ) ;
F_187 ( V_323 , 0 , V_8 ) ;
if ( F_95 ( V_14 , V_8 , & V_71 ) )
continue;
if ( V_8 != - V_99 )
break;
F_36 ( V_14 , V_8 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_188 ( struct V_231 * V_232 , struct V_73 * V_74 )
{
struct V_322 * V_323 ;
int V_61 ;
V_323 = F_175 ( V_74 ) ;
if ( F_78 ( V_323 ) )
return - V_118 ;
V_61 = F_186 ( V_323 , V_74 ) ;
F_189 ( V_323 ) ;
return V_61 ;
}
static int F_190 ( struct V_13 * V_14 , struct V_73 * V_74 , const T_4 * V_50 , int V_8 )
{
switch ( V_8 ) {
default:
F_35 ( V_329 L_15
L_16 , V_34 , V_8 ) ;
case 0 :
case - V_324 :
case - V_118 :
case - V_327 :
break;
case - V_90 :
case - V_91 :
case - V_92 :
case - V_93 :
case - V_94 :
F_142 ( V_294 , & V_74 -> V_233 ) ;
F_33 ( V_14 -> V_55 -> V_97 , V_8 ) ;
return - V_118 ;
case - V_86 :
case - V_85 :
F_142 ( V_294 , & V_74 -> V_233 ) ;
F_29 ( V_14 -> V_55 ) ;
return - V_118 ;
case - V_87 :
F_30 ( V_14 ) ;
return - V_118 ;
case - V_88 :
F_31 ( V_14 -> V_55 ) ;
return - V_118 ;
case - V_78 :
case - V_79 :
case - V_80 :
case - V_81 :
case - V_83 :
F_26 ( V_74 -> V_2 ,
V_50 ) ;
F_28 ( V_14 , V_74 ) ;
return - V_118 ;
case - V_99 :
case - V_101 :
F_142 ( V_294 , & V_74 -> V_233 ) ;
F_191 ( 1 ) ;
return - V_118 ;
case - V_171 :
case - V_330 :
return 0 ;
}
return V_8 ;
}
int F_192 ( struct V_322 * V_323 ,
struct V_73 * V_74 , const T_4 * V_50 ,
T_6 type )
{
struct V_13 * V_14 = F_103 ( V_74 -> V_2 ) ;
struct V_219 * V_311 ;
int V_8 = 0 ;
V_311 = F_178 ( V_323 , V_74 ,
V_215 ) ;
if ( F_78 ( V_311 ) )
return F_87 ( V_311 ) ;
F_19 ( & V_311 -> V_224 . V_270 . V_286 , V_50 ) ;
F_146 ( & V_74 -> V_296 ) ;
F_19 ( & V_74 -> V_50 , & V_74 -> V_293 ) ;
F_148 ( & V_74 -> V_296 ) ;
F_144 ( V_294 , & V_74 -> V_233 ) ;
switch ( type & ( V_204 | V_205 ) ) {
case V_204 | V_205 :
case V_205 :
V_8 = F_179 ( V_311 , V_204 | V_205 ) ;
if ( V_8 )
break;
V_8 = F_179 ( V_311 , V_205 ) ;
if ( V_8 )
break;
case V_204 :
V_8 = F_179 ( V_311 , V_204 ) ;
}
F_124 ( V_311 ) ;
return F_190 ( V_14 , V_74 , V_50 , V_8 ) ;
}
static void F_193 ( struct V_112 * V_113 , void * V_160 )
{
struct V_219 * V_162 = V_160 ;
F_73 ( V_162 -> V_224 . V_14 -> V_55 ,
& V_162 -> V_226 . V_164 , & V_162 -> V_225 . V_165 , V_113 ) ;
}
static void F_194 ( struct V_112 * V_113 , void * V_160 )
{
struct V_219 * V_162 = V_160 ;
F_56 ( V_113 , & V_162 -> V_225 . V_165 ) ;
V_162 -> V_316 = V_113 -> V_117 ;
if ( V_162 -> V_316 == 0 ) {
F_19 ( & V_162 -> V_220 . V_50 , & V_162 -> V_225 . V_50 ) ;
F_195 ( & V_162 -> V_246 -> V_243 , 0 ) ;
F_49 ( V_162 -> V_220 . V_14 , V_162 -> V_125 ) ;
V_162 -> V_315 = 1 ;
}
}
static void F_196 ( void * V_160 )
{
struct V_219 * V_162 = V_160 ;
struct V_73 * V_74 = NULL ;
if ( V_162 -> V_331 == 0 )
goto V_332;
if ( ! V_162 -> V_315 )
goto V_332;
V_74 = F_174 ( V_162 ) ;
if ( ! F_78 ( V_74 ) )
F_182 ( V_74 , V_162 -> V_224 . V_202 ) ;
V_332:
F_124 ( V_162 ) ;
}
static int F_197 ( struct V_219 * V_162 )
{
struct V_13 * V_14 = F_103 ( F_14 ( V_162 -> V_3 ) ) ;
struct V_112 * V_113 ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_335 ] ,
. V_336 = & V_162 -> V_226 ,
. V_337 = & V_162 -> V_225 ,
. V_51 = V_162 -> V_246 -> V_304 ,
} ;
struct V_177 V_338 = {
. V_179 = V_14 -> V_108 ,
. V_175 = & V_176 ,
. V_180 = & V_339 ,
. V_182 = V_162 ,
. V_340 = V_341 ,
. V_233 = V_342 ,
} ;
int V_328 ;
F_51 ( & V_162 -> V_226 . V_164 , & V_162 -> V_225 . V_165 , 1 ) ;
F_198 ( & V_162 -> V_272 ) ;
V_162 -> V_315 = 0 ;
V_162 -> V_316 = 0 ;
V_162 -> V_125 = V_172 ;
if ( V_162 -> V_313 )
F_52 ( & V_162 -> V_226 . V_164 ) ;
V_113 = F_86 ( & V_338 ) ;
if ( F_78 ( V_113 ) )
return F_87 ( V_113 ) ;
V_328 = F_199 ( V_113 ) ;
if ( V_328 != 0 ) {
V_162 -> V_331 = 1 ;
F_200 () ;
} else
V_328 = V_162 -> V_316 ;
F_88 ( V_113 ) ;
return V_328 ;
}
static void F_201 ( struct V_112 * V_113 , void * V_160 )
{
struct V_219 * V_162 = V_160 ;
struct V_231 * V_232 = V_162 -> V_246 ;
struct V_55 * V_72 = V_232 -> V_289 -> V_55 ;
enum V_211 V_212 = V_162 -> V_224 . V_212 ;
if ( F_202 ( V_162 -> V_224 . V_223 , V_113 ) != 0 )
goto V_343;
if ( V_162 -> V_74 != NULL ) {
struct V_285 * V_286 ;
if ( F_128 ( V_162 -> V_74 , V_162 -> V_224 . V_202 , V_162 -> V_224 . V_248 ) )
goto V_344;
F_153 () ;
V_286 = F_154 ( F_91 ( V_162 -> V_74 -> V_2 ) -> V_286 ) ;
if ( F_129 ( V_286 , V_162 -> V_224 . V_202 , V_212 ) )
goto V_345;
F_156 () ;
}
V_162 -> V_224 . V_256 = V_72 -> V_257 ;
switch ( V_212 ) {
default:
break;
case V_267 :
case V_215 :
case V_217 :
V_162 -> V_224 . V_264 = & V_346 [ 0 ] ;
case V_213 :
V_113 -> V_347 . V_333 = & V_334 [ V_348 ] ;
F_203 ( & V_162 -> V_220 . V_266 , V_162 -> V_224 . V_266 ) ;
}
V_162 -> V_125 = V_172 ;
if ( F_73 ( V_162 -> V_224 . V_14 -> V_55 ,
& V_162 -> V_224 . V_164 ,
& V_162 -> V_220 . V_165 ,
V_113 ) != 0 )
F_161 ( V_162 -> V_224 . V_223 ) ;
V_162 -> V_224 . V_349 = V_350 ;
if ( V_162 -> V_224 . V_248 & V_251 ) {
V_162 -> V_224 . V_349 = V_351 ;
if ( F_204 ( V_72 ) )
V_162 -> V_224 . V_349 = V_352 ;
else if ( V_72 -> V_56 -> V_353 > 0 )
V_162 -> V_224 . V_349 = V_354 ;
}
return;
V_345:
F_170 ( V_162 -> V_74 ) ;
F_156 () ;
V_344:
V_113 -> V_355 = NULL ;
V_343:
F_71 ( V_113 , & V_162 -> V_220 . V_165 ) ;
}
static void F_205 ( struct V_112 * V_113 , void * V_160 )
{
struct V_219 * V_162 = V_160 ;
V_162 -> V_316 = V_113 -> V_117 ;
if ( ! F_69 ( V_113 , & V_162 -> V_220 . V_165 ) )
return;
if ( V_113 -> V_117 == 0 ) {
if ( V_162 -> V_220 . V_221 -> V_319 & V_356 ) {
switch ( V_162 -> V_220 . V_221 -> V_279 & V_357 ) {
case V_358 :
break;
case V_359 :
V_162 -> V_316 = - V_360 ;
break;
case V_361 :
V_162 -> V_316 = - V_362 ;
break;
default:
V_162 -> V_316 = - V_363 ;
}
}
F_49 ( V_162 -> V_220 . V_14 , V_162 -> V_125 ) ;
if ( ! ( V_162 -> V_220 . V_364 & V_365 ) )
F_195 ( & V_162 -> V_246 -> V_243 , 0 ) ;
}
V_162 -> V_315 = 1 ;
}
static void F_206 ( void * V_160 )
{
struct V_219 * V_162 = V_160 ;
struct V_73 * V_74 = NULL ;
if ( V_162 -> V_331 == 0 )
goto V_332;
if ( V_162 -> V_316 != 0 || ! V_162 -> V_315 )
goto V_332;
if ( V_162 -> V_220 . V_364 & V_365 )
goto V_332;
V_74 = F_174 ( V_162 ) ;
if ( ! F_78 ( V_74 ) )
F_182 ( V_74 , V_162 -> V_224 . V_202 ) ;
V_332:
F_124 ( V_162 ) ;
}
static int F_207 ( struct V_219 * V_162 , int V_366 )
{
struct V_2 * V_3 = F_14 ( V_162 -> V_3 ) ;
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_367 * V_224 = & V_162 -> V_224 ;
struct V_368 * V_220 = & V_162 -> V_220 ;
struct V_112 * V_113 ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_369 ] ,
. V_336 = V_224 ,
. V_337 = V_220 ,
. V_51 = V_162 -> V_246 -> V_304 ,
} ;
struct V_177 V_338 = {
. V_179 = V_14 -> V_108 ,
. V_175 = & V_176 ,
. V_180 = & V_370 ,
. V_182 = V_162 ,
. V_340 = V_341 ,
. V_233 = V_342 ,
} ;
int V_328 ;
F_51 ( & V_224 -> V_164 , & V_220 -> V_165 , 1 ) ;
F_198 ( & V_162 -> V_272 ) ;
V_162 -> V_315 = 0 ;
V_162 -> V_316 = 0 ;
V_162 -> V_331 = 0 ;
V_162 -> V_313 = 0 ;
if ( V_366 ) {
F_52 ( & V_224 -> V_164 ) ;
V_162 -> V_313 = 1 ;
}
V_113 = F_86 ( & V_338 ) ;
if ( F_78 ( V_113 ) )
return F_87 ( V_113 ) ;
V_328 = F_199 ( V_113 ) ;
if ( V_328 != 0 ) {
V_162 -> V_331 = 1 ;
F_200 () ;
} else
V_328 = V_162 -> V_316 ;
F_88 ( V_113 ) ;
return V_328 ;
}
static int F_181 ( struct V_219 * V_162 )
{
struct V_2 * V_3 = F_14 ( V_162 -> V_3 ) ;
struct V_368 * V_220 = & V_162 -> V_220 ;
int V_328 ;
V_328 = F_207 ( V_162 , 1 ) ;
if ( V_328 != 0 || ! V_162 -> V_315 )
return V_328 ;
F_208 ( F_103 ( V_3 ) , & V_162 -> V_221 ) ;
if ( V_220 -> V_364 & V_365 )
V_328 = F_197 ( V_162 ) ;
return V_328 ;
}
static int F_209 ( struct V_51 * V_52 ,
struct V_219 * V_311 ,
struct V_73 * V_74 , T_6 V_202 ,
int V_203 )
{
struct V_371 V_372 ;
T_1 V_373 ;
if ( V_311 -> V_220 . V_374 == 0 )
return 0 ;
V_373 = 0 ;
if ( V_203 & V_375 ) {
V_373 = V_376 ;
} else if ( ( V_202 & V_204 ) && ! V_311 -> V_377 )
V_373 = V_378 ;
V_372 . V_52 = V_52 ;
V_372 . V_172 = V_172 ;
F_210 ( & V_372 , V_311 -> V_220 . V_379 ) ;
F_211 ( V_74 -> V_2 , & V_372 ) ;
if ( ( V_373 & ~ V_372 . V_373 & ( V_378 | V_376 ) ) == 0 )
return 0 ;
return - V_29 ;
}
static int F_212 ( struct V_219 * V_162 )
{
struct V_2 * V_3 = F_14 ( V_162 -> V_3 ) ;
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_367 * V_224 = & V_162 -> V_224 ;
struct V_368 * V_220 = & V_162 -> V_220 ;
int V_328 ;
V_328 = F_207 ( V_162 , 0 ) ;
if ( ! V_162 -> V_315 )
return V_328 ;
if ( V_328 != 0 ) {
if ( V_328 == - V_26 &&
! ( V_224 -> V_248 & V_380 ) )
return - V_324 ;
return V_328 ;
}
F_208 ( V_14 , & V_162 -> V_221 ) ;
if ( V_224 -> V_248 & V_380 ) {
if ( V_224 -> V_248 & V_251 )
V_162 -> V_377 = 1 ;
else if ( V_220 -> V_184 . V_192 != V_220 -> V_184 . V_198 )
V_162 -> V_377 = 1 ;
if ( V_162 -> V_377 || V_3 -> V_193 != V_220 -> V_184 . V_198 )
F_90 ( V_3 , & V_220 -> V_184 ,
V_220 -> V_221 -> V_381 ) ;
}
if ( ( V_220 -> V_364 & V_382 ) == 0 )
V_14 -> V_104 &= ~ V_383 ;
if( V_220 -> V_364 & V_365 ) {
V_328 = F_197 ( V_162 ) ;
if ( V_328 != 0 )
return V_328 ;
}
if ( ! ( V_220 -> V_221 -> V_319 & V_320 ) ) {
F_70 ( & V_220 -> V_165 ) ;
F_213 ( V_14 , & V_220 -> V_266 , V_220 -> V_221 , V_220 -> V_222 ) ;
}
return 0 ;
}
static int F_214 ( struct V_322 * V_323 , struct V_73 * V_74 )
{
struct V_219 * V_311 ;
int V_61 ;
V_311 = F_178 ( V_323 , V_74 ,
V_213 ) ;
if ( F_78 ( V_311 ) )
return F_87 ( V_311 ) ;
V_61 = F_183 ( V_311 , V_74 ) ;
if ( V_61 == - V_327 )
F_215 ( V_323 -> V_4 ) ;
F_124 ( V_311 ) ;
return V_61 ;
}
static int F_216 ( struct V_322 * V_323 , struct V_73 * V_74 )
{
struct V_13 * V_14 = F_103 ( V_74 -> V_2 ) ;
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_214 ( V_323 , V_74 ) ;
F_217 ( V_323 , 0 , V_8 ) ;
if ( F_95 ( V_14 , V_8 , & V_71 ) )
continue;
switch ( V_8 ) {
default:
goto V_153;
case - V_101 :
case - V_99 :
F_36 ( V_14 , V_8 , & V_71 ) ;
V_8 = 0 ;
}
} while ( V_71 . V_77 );
V_153:
return V_8 ;
}
static int F_218 ( struct V_231 * V_232 , struct V_73 * V_74 )
{
struct V_322 * V_323 ;
int V_61 ;
V_323 = F_175 ( V_74 ) ;
if ( F_78 ( V_323 ) )
return - V_118 ;
V_61 = F_216 ( V_323 , V_74 ) ;
F_189 ( V_323 ) ;
return V_61 ;
}
static void F_219 ( struct V_73 * V_74 ,
const T_4 * V_50 )
{
F_220 ( V_74 -> V_2 , V_50 ) ;
F_146 ( & V_74 -> V_296 ) ;
F_19 ( & V_74 -> V_50 , & V_74 -> V_293 ) ;
F_148 ( & V_74 -> V_296 ) ;
F_144 ( V_294 , & V_74 -> V_233 ) ;
}
static void F_221 ( struct V_73 * V_74 )
{
if ( F_222 ( F_91 ( V_74 -> V_2 ) -> V_286 ) != NULL )
F_219 ( V_74 , NULL ) ;
}
static int F_223 ( struct V_231 * V_232 , struct V_73 * V_74 )
{
F_221 ( V_74 ) ;
return F_218 ( V_232 , V_74 ) ;
}
static int F_224 ( struct V_13 * V_14 ,
T_4 * V_50 ,
struct V_51 * V_52 )
{
return - V_81 ;
}
static int F_225 ( struct V_13 * V_14 ,
T_4 * V_50 ,
struct V_51 * V_52 )
{
int V_328 ;
switch ( V_50 -> type ) {
default:
break;
case V_384 :
case V_385 :
return - V_81 ;
case V_58 :
goto V_332;
}
V_328 = F_226 ( V_14 , V_50 , V_52 ) ;
switch ( V_328 ) {
case - V_80 :
case - V_79 :
case - V_78 :
break;
default:
return V_328 ;
}
V_332:
F_227 ( V_14 , V_50 , V_52 , true ) ;
return - V_80 ;
}
static void F_228 ( struct V_73 * V_74 )
{
struct V_13 * V_14 = F_103 ( V_74 -> V_2 ) ;
T_4 V_50 ;
struct V_285 * V_286 ;
struct V_51 * V_52 ;
int V_328 ;
F_153 () ;
V_286 = F_154 ( F_91 ( V_74 -> V_2 ) -> V_286 ) ;
if ( V_286 == NULL ) {
F_156 () ;
return;
}
F_19 ( & V_50 , & V_286 -> V_50 ) ;
if ( F_38 ( V_386 , & V_286 -> V_233 ) ||
! F_135 ( V_387 ,
& V_286 -> V_233 ) ) {
F_156 () ;
F_219 ( V_74 , & V_50 ) ;
return;
}
V_52 = F_229 ( V_286 -> V_52 ) ;
F_156 () ;
V_328 = F_225 ( V_14 , & V_50 , V_52 ) ;
F_230 ( V_74 , NULL , V_328 ) ;
if ( V_328 == - V_80 || V_328 == - V_81 )
F_219 ( V_74 , & V_50 ) ;
F_231 ( V_52 ) ;
}
static int F_232 ( struct V_73 * V_74 )
{
int V_328 , V_61 = V_388 ;
struct V_305 * V_306 , * V_389 = NULL ;
struct V_13 * V_14 = F_103 ( V_74 -> V_2 ) ;
if ( ! F_38 ( V_390 , & V_74 -> V_233 ) )
goto V_153;
F_46 ( & V_74 -> V_308 ) ;
F_176 (lsp, &state->lock_states, ls_locks) {
if ( F_38 ( V_391 , & V_306 -> V_392 ) ) {
struct V_51 * V_52 = V_306 -> V_307 -> V_246 -> V_304 ;
F_108 ( & V_306 -> V_393 ) ;
F_48 ( & V_74 -> V_308 ) ;
F_233 ( V_389 ) ;
V_389 = V_306 ;
V_328 = F_225 ( V_14 ,
& V_306 -> V_309 ,
V_52 ) ;
F_234 ( V_74 , V_306 , V_328 ) ;
if ( V_328 == - V_80 ||
V_328 == - V_81 ) {
F_144 ( V_391 , & V_306 -> V_392 ) ;
V_306 -> V_309 . type = V_384 ;
if ( ! V_394 )
F_142 ( V_395 , & V_306 -> V_392 ) ;
} else if ( V_328 != V_388 ) {
V_61 = V_328 ;
F_233 ( V_389 ) ;
goto V_153;
}
F_46 ( & V_74 -> V_308 ) ;
}
}
F_48 ( & V_74 -> V_308 ) ;
F_233 ( V_389 ) ;
V_153:
return V_61 ;
}
static int F_235 ( struct V_73 * V_74 )
{
struct V_13 * V_14 = F_103 ( V_74 -> V_2 ) ;
T_4 * V_50 = & V_74 -> V_293 ;
struct V_51 * V_52 = V_74 -> V_246 -> V_304 ;
int V_328 ;
if ( F_38 ( V_292 , & V_74 -> V_233 ) == 0 ) {
if ( F_38 ( V_294 , & V_74 -> V_233 ) == 0 ) {
if ( F_236 ( V_74 -> V_2 , V_74 -> V_74 ) )
return V_388 ;
return - V_83 ;
}
return - V_81 ;
}
V_328 = F_225 ( V_14 , V_50 , V_52 ) ;
F_237 ( V_74 , NULL , V_328 ) ;
if ( V_328 == - V_80 || V_328 == - V_81 ) {
F_144 ( V_282 , & V_74 -> V_233 ) ;
F_144 ( V_283 , & V_74 -> V_233 ) ;
F_144 ( V_284 , & V_74 -> V_233 ) ;
F_144 ( V_292 , & V_74 -> V_233 ) ;
V_50 -> type = V_384 ;
}
if ( V_328 != V_388 )
return V_328 ;
if ( F_133 ( V_74 ) )
return - V_83 ;
return V_388 ;
}
static int F_238 ( struct V_231 * V_232 , struct V_73 * V_74 )
{
int V_328 ;
F_228 ( V_74 ) ;
V_328 = F_232 ( V_74 ) ;
if ( V_328 != V_388 )
return V_328 ;
V_328 = F_235 ( V_74 ) ;
if ( V_328 != V_388 )
V_328 = F_218 ( V_232 , V_74 ) ;
return V_328 ;
}
static inline void F_239 ( struct V_219 * V_311 ,
struct V_5 * V_6 , struct V_1 * * V_7 )
{
const T_1 * V_396 = V_311 -> V_220 . V_396 ;
if ( ( V_396 [ 1 ] & V_397 ) &&
! ( V_6 -> V_268 & V_398 ) )
V_6 -> V_268 |= V_399 ;
if ( ( V_396 [ 1 ] & V_400 ) &&
! ( V_6 -> V_268 & V_401 ) )
V_6 -> V_268 |= V_402 ;
if ( V_311 -> V_224 . V_349 != V_351 &&
( V_396 [ 1 ] & V_403 ||
V_396 [ 2 ] & V_404 ) )
V_6 -> V_268 &= ~ V_405 ;
if ( V_396 [ 2 ] & V_406 )
* V_7 = NULL ;
}
static int F_240 ( struct V_219 * V_311 ,
T_6 V_202 ,
int V_233 ,
struct V_322 * V_323 )
{
struct V_231 * V_232 = V_311 -> V_246 ;
struct V_13 * V_14 = V_232 -> V_289 ;
struct V_4 * V_4 ;
struct V_73 * V_74 ;
unsigned int V_407 ;
int V_61 ;
V_407 = F_241 ( & V_232 -> V_408 ) ;
V_61 = F_212 ( V_311 ) ;
if ( V_61 != 0 )
goto V_153;
V_74 = F_174 ( V_311 ) ;
V_61 = F_87 ( V_74 ) ;
if ( F_78 ( V_74 ) )
goto V_153;
V_323 -> V_74 = V_74 ;
if ( V_14 -> V_104 & V_383 )
F_142 ( V_409 , & V_74 -> V_233 ) ;
if ( V_311 -> V_220 . V_364 & V_410 )
F_142 ( V_411 , & V_74 -> V_233 ) ;
V_4 = V_311 -> V_4 ;
if ( F_242 ( V_4 ) ) {
struct V_4 * V_412 ;
F_215 ( V_4 ) ;
V_412 = F_243 ( V_4 , V_74 -> V_2 ) ;
if ( ! V_412 )
V_412 = F_244 ( F_245 ( V_74 -> V_2 ) , V_4 ) ;
if ( V_412 ) {
F_116 ( V_323 -> V_4 ) ;
V_323 -> V_4 = V_4 = V_412 ;
}
F_246 ( V_4 ,
F_247 ( F_14 ( V_311 -> V_3 ) ) ) ;
}
V_61 = F_209 ( V_232 -> V_304 , V_311 , V_74 , V_202 , V_233 ) ;
if ( V_61 != 0 )
goto V_153;
if ( F_14 ( V_4 ) == V_74 -> V_2 ) {
F_248 ( V_323 ) ;
if ( F_249 ( & V_232 -> V_408 , V_407 ) )
F_28 ( V_14 , V_74 ) ;
}
V_153:
return V_61 ;
}
static int F_250 ( struct V_2 * V_3 ,
struct V_322 * V_323 ,
int V_233 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_413 )
{
struct V_231 * V_232 ;
struct V_73 * V_74 = NULL ;
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_219 * V_311 ;
struct V_4 * V_4 = V_323 -> V_4 ;
struct V_51 * V_52 = V_323 -> V_52 ;
struct V_414 * * V_415 = & V_323 -> V_275 ;
T_6 V_202 = V_323 -> V_279 & ( V_204 | V_205 | V_416 ) ;
enum V_211 V_212 = V_214 ;
struct V_1 * V_417 = NULL ;
int V_328 ;
V_328 = - V_171 ;
V_232 = F_251 ( V_14 , V_52 , V_418 ) ;
if ( V_232 == NULL ) {
F_8 ( L_17 ) ;
goto V_419;
}
V_328 = F_252 ( V_14 -> V_55 ) ;
if ( V_328 != 0 )
goto V_420;
if ( F_253 ( V_4 ) )
F_158 ( F_14 ( V_4 ) , V_202 ) ;
V_328 = - V_171 ;
if ( F_253 ( V_4 ) )
V_212 = V_213 ;
V_311 = F_101 ( V_4 , V_232 , V_202 , V_233 , V_6 ,
V_7 , V_212 , V_418 ) ;
if ( V_311 == NULL )
goto V_420;
if ( V_7 ) {
V_417 = F_105 ( V_14 , V_418 ) ;
if ( F_78 ( V_417 ) ) {
V_328 = F_87 ( V_417 ) ;
goto V_421;
}
}
if ( V_14 -> V_15 [ 2 ] & V_422 ) {
if ( ! V_311 -> V_221 . V_275 ) {
V_311 -> V_221 . V_275 = F_254 () ;
if ( ! V_311 -> V_221 . V_275 )
goto V_244;
}
V_311 -> V_224 . V_264 = & V_423 [ 0 ] ;
}
if ( F_253 ( V_4 ) )
V_311 -> V_74 = F_172 ( F_14 ( V_4 ) , V_232 ) ;
V_328 = F_240 ( V_311 , V_202 , V_233 , V_323 ) ;
if ( V_328 != 0 )
goto V_244;
V_74 = V_323 -> V_74 ;
if ( ( V_311 -> V_224 . V_248 & ( V_380 | V_251 ) ) == ( V_380 | V_251 ) &&
( V_311 -> V_224 . V_349 != V_352 ) ) {
F_239 ( V_311 , V_6 , & V_7 ) ;
if ( V_6 -> V_268 & V_424 ) {
F_99 ( V_311 -> V_220 . V_221 ) ;
V_328 = F_255 ( V_74 -> V_2 , V_52 ,
V_311 -> V_220 . V_221 , V_6 ,
V_323 , V_7 , V_417 ) ;
if ( V_328 == 0 ) {
F_256 ( V_74 -> V_2 , V_6 ,
V_311 -> V_220 . V_221 ) ;
F_257 ( V_74 -> V_2 , V_311 -> V_220 . V_221 , V_417 ) ;
}
}
}
if ( V_413 && V_311 -> V_377 )
* V_413 |= V_425 ;
if ( F_258 ( V_415 , V_311 -> V_221 . V_275 , V_14 ) ) {
* V_415 = V_311 -> V_221 . V_275 ;
V_311 -> V_221 . V_275 = NULL ;
}
F_114 ( V_417 ) ;
F_124 ( V_311 ) ;
F_121 ( V_232 ) ;
return 0 ;
V_244:
F_114 ( V_417 ) ;
V_421:
F_124 ( V_311 ) ;
V_420:
F_121 ( V_232 ) ;
V_419:
return V_328 ;
}
static struct V_73 * F_259 ( struct V_2 * V_3 ,
struct V_322 * V_323 ,
int V_233 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_413 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_70 V_71 = { } ;
struct V_73 * V_66 ;
int V_328 ;
do {
V_328 = F_250 ( V_3 , V_323 , V_233 , V_6 , V_7 , V_413 ) ;
V_66 = V_323 -> V_74 ;
F_260 ( V_323 , V_233 , V_328 ) ;
if ( V_328 == 0 )
break;
if ( V_328 == - V_426 ) {
F_261 ( L_5
L_18 ,
F_103 ( V_3 ) -> V_55 -> V_107 ) ;
V_71 . V_77 = 1 ;
continue;
}
if ( V_328 == - V_81 ) {
V_71 . V_77 = 1 ;
continue;
}
if ( V_328 == - V_118 ) {
V_71 . V_77 = 1 ;
continue;
}
if ( F_95 ( V_14 , V_328 , & V_71 ) )
continue;
V_66 = F_79 ( F_36 ( V_14 ,
V_328 , & V_71 ) ) ;
} while ( V_71 . V_77 );
return V_66 ;
}
static int F_262 ( struct V_2 * V_2 ,
struct V_427 * V_428 ,
struct V_429 * V_66 ,
struct V_51 * V_52 ,
struct V_322 * V_323 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_430 ] ,
. V_336 = V_428 ,
. V_337 = V_66 ,
. V_51 = V_52 ,
} ;
struct V_51 * V_431 = NULL ;
unsigned long V_125 = V_172 ;
T_6 V_202 ;
bool V_432 ;
int V_328 ;
F_99 ( V_66 -> V_433 ) ;
V_432 = ( V_428 -> V_434 -> V_268 & V_435 ) ? true : false ;
V_202 = V_432 ? V_205 : V_204 ;
if ( F_263 ( V_2 , V_202 , & V_428 -> V_50 , & V_431 ) ) {
} else if ( V_432 && V_323 != NULL ) {
struct V_436 * V_437 ;
if ( ! F_264 ( V_323 -> V_74 ) )
return - V_438 ;
V_437 = F_265 ( V_323 ) ;
if ( F_78 ( V_437 ) )
return F_87 ( V_437 ) ;
V_328 = F_266 ( V_323 -> V_74 , V_205 , V_437 ,
& V_428 -> V_50 , & V_431 ) ;
F_267 ( V_437 ) ;
if ( V_328 == - V_35 )
return - V_438 ;
} else
F_19 ( & V_428 -> V_50 , & V_439 ) ;
if ( V_431 )
V_176 . V_51 = V_431 ;
V_328 = F_89 ( V_14 -> V_108 , V_14 , & V_176 , & V_428 -> V_164 , & V_66 -> V_165 , 1 ) ;
F_231 ( V_431 ) ;
if ( V_328 == 0 && V_323 != NULL )
F_49 ( V_14 , V_125 ) ;
F_268 ( V_2 , & V_428 -> V_50 , V_328 ) ;
return V_328 ;
}
static int F_255 ( struct V_2 * V_2 , struct V_51 * V_52 ,
struct V_440 * V_433 , struct V_5 * V_6 ,
struct V_322 * V_323 , struct V_1 * V_441 ,
struct V_1 * V_417 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_73 * V_74 = V_323 ? V_323 -> V_74 : NULL ;
struct V_427 V_428 = {
. V_266 = F_112 ( V_2 ) ,
. V_434 = V_6 ,
. V_14 = V_14 ,
. V_263 = V_14 -> V_15 ,
. V_7 = V_441 ,
} ;
struct V_429 V_66 = {
. V_433 = V_433 ,
. V_7 = V_417 ,
. V_14 = V_14 ,
} ;
struct V_70 V_71 = {
. V_74 = V_74 ,
. V_2 = V_2 ,
. V_50 = & V_428 . V_50 ,
} ;
int V_8 ;
V_428 . V_263 = F_6 ( V_14 , V_441 ) ;
if ( V_441 )
V_428 . V_263 = F_6 ( V_14 , V_417 ) ;
do {
V_8 = F_262 ( V_2 , & V_428 , & V_66 , V_52 , V_323 ) ;
switch ( V_8 ) {
case - V_83 :
if ( ! ( V_6 -> V_268 & V_435 ) ) {
F_269 ( L_19
L_20
L_21
L_22 ,
V_14 -> V_55 -> V_107 ) ;
}
if ( V_74 && ! ( V_74 -> V_74 & V_205 ) ) {
V_8 = - V_438 ;
if ( V_6 -> V_268 & V_442 )
V_8 = - V_29 ;
goto V_153;
}
}
V_8 = F_36 ( V_14 , V_8 , & V_71 ) ;
} while ( V_71 . V_77 );
V_153:
return V_8 ;
}
static bool
F_270 ( struct V_2 * V_2 , struct V_112 * V_113 )
{
if ( V_2 == NULL || ! F_271 ( V_2 ) )
return false ;
return F_272 ( V_2 , V_113 ) ;
}
static void F_273 ( void * V_162 )
{
struct V_443 * V_160 = V_162 ;
struct V_231 * V_232 = V_160 -> V_74 -> V_246 ;
struct V_273 * V_274 = V_160 -> V_74 -> V_2 -> V_444 ;
if ( V_160 -> V_445 . V_446 )
F_274 ( & V_160 -> V_445 . V_428 , & V_160 -> V_445 . V_66 ,
V_160 -> V_66 . V_447 ) ;
F_120 ( V_160 -> V_74 ) ;
F_119 ( V_160 -> V_428 . V_223 ) ;
F_121 ( V_232 ) ;
F_122 ( V_274 ) ;
F_115 ( V_160 ) ;
}
static void F_275 ( struct V_112 * V_113 , void * V_162 )
{
struct V_443 * V_160 = V_162 ;
struct V_73 * V_74 = V_160 -> V_74 ;
struct V_13 * V_14 = F_103 ( V_160 -> V_2 ) ;
T_4 * V_448 = NULL ;
F_8 ( L_23 , V_34 ) ;
if ( ! F_71 ( V_113 , & V_160 -> V_66 . V_165 ) )
return;
F_276 ( V_74 , & V_160 -> V_428 , & V_160 -> V_66 , V_113 -> V_117 ) ;
if ( V_160 -> V_428 . V_449 && V_113 -> V_117 != 0 ) {
switch ( V_160 -> V_66 . V_447 ) {
default:
V_160 -> V_66 . V_447 = - V_450 ;
break;
case 0 :
V_160 -> V_428 . V_449 = NULL ;
V_160 -> V_66 . V_451 = NULL ;
break;
case - V_79 :
case - V_78 :
case - V_80 :
case - V_81 :
case - V_103 :
case - V_452 :
case - V_23 :
V_160 -> V_428 . V_449 = NULL ;
V_160 -> V_66 . V_451 = NULL ;
V_160 -> V_66 . V_447 = 0 ;
F_66 ( V_113 ) ;
return;
}
}
switch ( V_113 -> V_117 ) {
case 0 :
V_448 = & V_160 -> V_66 . V_50 ;
F_49 ( V_14 , V_160 -> V_125 ) ;
break;
case - V_453 :
if ( V_160 -> V_428 . V_263 != NULL ) {
V_160 -> V_428 . V_263 = NULL ;
V_160 -> V_66 . V_433 = NULL ;
V_113 -> V_117 = 0 ;
F_66 ( V_113 ) ;
goto V_454;
}
break;
case - V_79 :
case - V_85 :
case - V_80 :
F_18 ( V_14 ,
& V_160 -> V_428 . V_50 ,
V_113 -> V_347 . V_51 ) ;
case - V_103 :
case - V_81 :
if ( ! F_155 ( & V_160 -> V_428 . V_50 ,
& V_74 -> V_293 ) ) {
F_66 ( V_113 ) ;
goto V_454;
}
if ( V_160 -> V_428 . V_202 == 0 )
break;
default:
if ( F_43 ( V_113 , V_14 , V_74 , NULL ) == - V_118 ) {
F_66 ( V_113 ) ;
goto V_454;
}
}
F_145 ( V_74 , & V_160 -> V_428 . V_50 ,
V_448 , V_160 -> V_428 . V_202 ) ;
V_454:
F_161 ( V_160 -> V_428 . V_223 ) ;
F_168 ( V_160 -> V_2 , & V_160 -> V_433 ) ;
F_8 ( L_24 , V_34 , V_113 -> V_117 ) ;
}
static void F_277 ( struct V_112 * V_113 , void * V_162 )
{
struct V_443 * V_160 = V_162 ;
struct V_73 * V_74 = V_160 -> V_74 ;
struct V_2 * V_2 = V_160 -> V_2 ;
bool V_455 , V_456 , V_457 ;
int V_458 = 0 ;
F_8 ( L_23 , V_34 ) ;
if ( F_202 ( V_160 -> V_428 . V_223 , V_113 ) != 0 )
goto V_343;
V_113 -> V_347 . V_333 = & V_334 [ V_459 ] ;
F_46 ( & V_74 -> V_246 -> V_299 ) ;
V_457 = F_38 ( V_284 , & V_74 -> V_233 ) ;
V_455 = F_38 ( V_282 , & V_74 -> V_233 ) ;
V_456 = F_38 ( V_283 , & V_74 -> V_233 ) ;
F_19 ( & V_160 -> V_428 . V_50 , & V_74 -> V_293 ) ;
V_160 -> V_428 . V_202 = 0 ;
if ( V_74 -> V_276 == 0 ) {
if ( V_74 -> V_278 == 0 )
V_458 |= V_455 ;
else if ( V_455 )
V_160 -> V_428 . V_202 |= V_204 ;
if ( V_74 -> V_277 == 0 )
V_458 |= V_456 ;
else if ( V_456 )
V_160 -> V_428 . V_202 |= V_205 ;
if ( V_160 -> V_428 . V_202 != ( V_204 | V_205 ) )
V_458 |= V_457 ;
} else if ( V_457 )
V_160 -> V_428 . V_202 |= V_204 | V_205 ;
if ( ! F_264 ( V_74 ) ||
F_38 ( V_292 , & V_74 -> V_233 ) == 0 )
V_458 = 0 ;
F_48 ( & V_74 -> V_246 -> V_299 ) ;
if ( ! V_458 ) {
goto V_344;
}
if ( ! V_160 -> V_445 . V_446 && F_270 ( V_2 , V_113 ) ) {
F_161 ( V_160 -> V_428 . V_223 ) ;
goto V_343;
}
if ( V_160 -> V_428 . V_202 == 0 )
V_113 -> V_347 . V_333 = & V_334 [ V_460 ] ;
if ( V_160 -> V_428 . V_202 == 0 || V_160 -> V_428 . V_202 == V_204 ) {
if ( ! F_236 ( V_2 , V_204 ) )
V_160 -> V_428 . V_263 = F_103 ( V_2 ) -> V_461 ;
else
V_160 -> V_428 . V_263 = NULL ;
}
V_160 -> V_428 . V_250 =
F_96 ( F_103 ( V_2 ) ,
V_160 -> V_428 . V_202 , 0 ) ;
if ( V_160 -> V_66 . V_433 == NULL )
V_160 -> V_428 . V_263 = NULL ;
else if ( V_160 -> V_428 . V_263 == NULL )
V_160 -> V_66 . V_433 = NULL ;
V_160 -> V_125 = V_172 ;
if ( F_73 ( F_103 ( V_2 ) -> V_55 ,
& V_160 -> V_428 . V_164 ,
& V_160 -> V_66 . V_165 ,
V_113 ) != 0 )
F_161 ( V_160 -> V_428 . V_223 ) ;
F_8 ( L_25 , V_34 ) ;
return;
V_344:
V_113 -> V_355 = NULL ;
V_343:
F_71 ( V_113 , & V_160 -> V_66 . V_165 ) ;
}
int F_278 ( struct V_73 * V_74 , T_7 V_235 , int V_462 )
{
struct V_13 * V_14 = F_103 ( V_74 -> V_2 ) ;
struct V_237 * ( * V_238 ) ( struct V_239 * , T_7 ) ;
struct V_443 * V_160 ;
struct V_231 * V_232 = V_74 -> V_246 ;
struct V_112 * V_113 ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_460 ] ,
. V_51 = V_74 -> V_246 -> V_304 ,
} ;
struct V_177 V_338 = {
. V_179 = V_14 -> V_108 ,
. V_175 = & V_176 ,
. V_180 = & V_463 ,
. V_340 = V_341 ,
. V_233 = V_342 ,
} ;
int V_328 = - V_171 ;
F_279 ( V_14 -> V_55 , V_464 ,
& V_338 . V_179 , & V_176 ) ;
V_160 = F_104 ( sizeof( * V_160 ) , V_235 ) ;
if ( V_160 == NULL )
goto V_153;
F_51 ( & V_160 -> V_428 . V_164 , & V_160 -> V_66 . V_165 , 1 ) ;
V_160 -> V_2 = V_74 -> V_2 ;
V_160 -> V_74 = V_74 ;
V_160 -> V_428 . V_266 = F_112 ( V_74 -> V_2 ) ;
V_238 = V_14 -> V_55 -> V_56 -> V_238 ;
V_160 -> V_428 . V_223 = V_238 ( & V_74 -> V_246 -> V_243 , V_235 ) ;
if ( F_78 ( V_160 -> V_428 . V_223 ) )
goto V_465;
F_99 ( & V_160 -> V_433 ) ;
V_160 -> V_428 . V_202 = 0 ;
V_160 -> V_445 . V_428 . V_466 = & V_160 -> V_445 . V_466 ;
V_160 -> V_66 . V_433 = & V_160 -> V_433 ;
V_160 -> V_66 . V_223 = V_160 -> V_428 . V_223 ;
V_160 -> V_66 . V_14 = V_14 ;
V_160 -> V_66 . V_447 = - V_450 ;
V_160 -> V_445 . V_446 = F_280 ( V_74 -> V_2 ,
& V_160 -> V_445 . V_428 , & V_160 -> V_445 . V_66 , V_176 . V_51 ) ;
if ( V_160 -> V_445 . V_446 ) {
V_160 -> V_428 . V_449 = & V_160 -> V_445 . V_428 ;
V_160 -> V_66 . V_451 = & V_160 -> V_445 . V_66 ;
}
F_106 ( V_160 -> V_2 -> V_444 ) ;
V_176 . V_336 = & V_160 -> V_428 ;
V_176 . V_337 = & V_160 -> V_66 ;
V_338 . V_182 = V_160 ;
V_113 = F_86 ( & V_338 ) ;
if ( F_78 ( V_113 ) )
return F_87 ( V_113 ) ;
V_328 = 0 ;
if ( V_462 )
V_328 = F_199 ( V_113 ) ;
F_88 ( V_113 ) ;
return V_328 ;
V_465:
F_115 ( V_160 ) ;
V_153:
F_120 ( V_74 ) ;
F_121 ( V_232 ) ;
return V_328 ;
}
static struct V_2 *
F_281 ( struct V_2 * V_3 , struct V_322 * V_323 ,
int V_248 , struct V_5 * V_467 , int * V_413 )
{
struct V_73 * V_74 ;
struct V_1 V_17 = { 0 , 0 , 0 , NULL } , * V_7 = NULL ;
V_7 = F_1 ( V_3 , V_323 -> V_4 , V_467 , & V_17 ) ;
V_74 = F_259 ( V_3 , V_323 , V_248 , V_467 , V_7 , V_413 ) ;
F_4 ( V_7 ) ;
if ( F_78 ( V_74 ) )
return F_282 ( V_74 ) ;
return V_74 -> V_2 ;
}
static void F_283 ( struct V_322 * V_323 , int V_468 )
{
if ( V_323 -> V_74 == NULL )
return;
if ( V_468 )
F_284 ( V_323 -> V_74 , V_323 -> V_279 ) ;
else
F_182 ( V_323 -> V_74 , V_323 -> V_279 ) ;
}
static int F_285 ( struct V_13 * V_14 , struct V_469 * V_470 )
{
T_1 V_263 [ 3 ] = {} , V_471 = V_14 -> V_55 -> V_472 ;
struct V_473 args = {
. V_470 = V_470 ,
. V_263 = V_263 ,
} ;
struct V_474 V_66 = {} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_475 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
} ;
int V_328 ;
int V_476 ;
V_263 [ 0 ] = V_477 |
V_478 |
V_479 |
V_480 |
V_481 ;
if ( V_471 )
V_263 [ 2 ] = V_482 ;
V_328 = F_89 ( V_14 -> V_108 , V_14 , & V_176 , & args . V_164 , & V_66 . V_165 , 0 ) ;
if ( V_328 == 0 ) {
switch ( V_471 ) {
case 0 :
V_66 . V_15 [ 1 ] &= V_483 ;
V_66 . V_15 [ 2 ] = 0 ;
break;
case 1 :
V_66 . V_15 [ 2 ] &= V_484 ;
break;
case 2 :
V_66 . V_15 [ 2 ] &= V_485 ;
}
memcpy ( V_14 -> V_15 , V_66 . V_15 , sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_104 &= ~ ( V_486 | V_487 |
V_488 | V_489 |
V_490 | V_491 | V_492 |
V_493 | V_494 |
V_495 | V_496 |
V_9 ) ;
if ( V_66 . V_15 [ 0 ] & V_497 &&
V_66 . V_498 & V_499 )
V_14 -> V_104 |= V_486 ;
if ( V_66 . V_500 != 0 )
V_14 -> V_104 |= V_487 ;
if ( V_66 . V_501 != 0 )
V_14 -> V_104 |= V_488 ;
if ( V_66 . V_15 [ 0 ] & V_45 )
V_14 -> V_104 |= V_489 ;
if ( V_66 . V_15 [ 1 ] & V_403 )
V_14 -> V_104 |= V_490 ;
if ( V_66 . V_15 [ 1 ] & V_502 )
V_14 -> V_104 |= V_491 ;
if ( V_66 . V_15 [ 1 ] & V_503 )
V_14 -> V_104 |= V_492 ;
if ( V_66 . V_15 [ 1 ] & V_504 )
V_14 -> V_104 |= V_493 ;
if ( V_66 . V_15 [ 1 ] & V_397 )
V_14 -> V_104 |= V_494 ;
if ( V_66 . V_15 [ 1 ] & V_505 )
V_14 -> V_104 |= V_495 ;
if ( V_66 . V_15 [ 1 ] & V_400 )
V_14 -> V_104 |= V_496 ;
#ifdef F_286
if ( V_66 . V_15 [ 2 ] & V_406 )
V_14 -> V_104 |= V_9 ;
#endif
memcpy ( V_14 -> V_16 , V_66 . V_15 ,
sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_16 [ 2 ] &= ~ V_406 ;
memcpy ( V_14 -> V_461 , V_66 . V_15 , sizeof( V_14 -> V_461 ) ) ;
V_14 -> V_461 [ 0 ] &= V_506 | V_507 ;
V_14 -> V_461 [ 1 ] &= V_505 | V_400 ;
V_14 -> V_461 [ 2 ] = 0 ;
for ( V_476 = 0 ; V_476 < F_287 ( V_66 . V_508 ) ; V_476 ++ )
V_66 . V_508 [ V_476 ] &= V_66 . V_15 [ V_476 ] ;
memcpy ( V_14 -> V_508 , V_66 . V_508 ,
sizeof( V_14 -> V_508 ) ) ;
V_14 -> V_498 = V_66 . V_498 ;
V_14 -> V_509 = V_66 . V_509 ;
}
return V_328 ;
}
int F_288 ( struct V_13 * V_14 , struct V_469 * V_470 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_36 ( V_14 ,
F_285 ( V_14 , V_470 ) ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_289 ( struct V_13 * V_14 , struct V_469 * V_470 ,
struct V_510 * V_511 )
{
T_1 V_263 [ 3 ] ;
struct V_512 args = {
. V_263 = V_263 ,
} ;
struct V_513 V_66 = {
. V_14 = V_14 ,
. V_433 = V_511 -> V_433 ,
. V_266 = V_470 ,
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_514 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
} ;
V_263 [ 0 ] = V_265 [ 0 ] ;
V_263 [ 1 ] = V_265 [ 1 ] ;
V_263 [ 2 ] = V_265 [ 2 ] & ~ V_406 ;
F_99 ( V_511 -> V_433 ) ;
return F_89 ( V_14 -> V_108 , V_14 , & V_176 , & args . V_164 , & V_66 . V_165 , 0 ) ;
}
static int F_290 ( struct V_13 * V_14 , struct V_469 * V_470 ,
struct V_510 * V_511 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_289 ( V_14 , V_470 , V_511 ) ;
F_291 ( V_14 , V_470 , V_511 -> V_433 , V_8 ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
goto V_153;
default:
V_8 = F_36 ( V_14 , V_8 , & V_71 ) ;
}
} while ( V_71 . V_77 );
V_153:
return V_8 ;
}
static int F_292 ( struct V_13 * V_14 , struct V_469 * V_470 ,
struct V_510 * V_511 , T_5 V_119 )
{
struct V_515 V_516 = {
. V_517 = V_119 ,
} ;
struct V_518 * V_519 ;
V_519 = F_293 ( & V_516 , V_14 -> V_108 ) ;
if ( F_78 ( V_519 ) )
return - V_29 ;
return F_290 ( V_14 , V_470 , V_511 ) ;
}
static int F_294 ( struct V_13 * V_14 , struct V_469 * V_470 ,
struct V_510 * V_511 )
{
static const T_5 V_520 [] = {
V_124 ,
V_123 ,
V_521 ,
V_522 ,
V_523 ,
} ;
int V_328 = - V_24 ;
T_9 V_476 ;
if ( V_14 -> V_524 . V_525 > 0 ) {
for ( V_476 = 0 ; V_476 < V_14 -> V_524 . V_525 ; V_476 ++ ) {
V_328 = F_292 ( V_14 , V_470 , V_511 ,
V_14 -> V_524 . V_526 [ V_476 ] ) ;
if ( V_328 == - V_22 || V_328 == - V_29 )
continue;
break;
}
} else {
for ( V_476 = 0 ; V_476 < F_287 ( V_520 ) ; V_476 ++ ) {
V_328 = F_292 ( V_14 , V_470 , V_511 ,
V_520 [ V_476 ] ) ;
if ( V_328 == - V_22 || V_328 == - V_29 )
continue;
break;
}
}
if ( V_328 == - V_29 )
V_328 = - V_24 ;
return V_328 ;
}
int F_295 ( struct V_13 * V_14 , struct V_469 * V_470 ,
struct V_510 * V_511 ,
bool V_527 )
{
int V_328 = 0 ;
if ( ! V_527 )
V_328 = F_290 ( V_14 , V_470 , V_511 ) ;
if ( V_527 || V_328 == V_22 )
V_328 = V_14 -> V_55 -> V_56 -> V_528 ( V_14 ,
V_470 , V_511 ) ;
if ( V_328 == 0 )
V_328 = F_288 ( V_14 , V_470 ) ;
if ( V_328 == 0 )
V_328 = F_296 ( V_14 , V_470 , V_511 ) ;
return F_7 ( V_328 ) ;
}
static int F_297 ( struct V_13 * V_14 , struct V_469 * V_529 ,
struct V_510 * V_511 )
{
int error ;
struct V_440 * V_433 = V_511 -> V_433 ;
struct V_1 * V_7 = NULL ;
error = F_288 ( V_14 , V_529 ) ;
if ( error < 0 ) {
F_8 ( L_26 , - error ) ;
return error ;
}
V_7 = F_105 ( V_14 , V_418 ) ;
if ( F_78 ( V_7 ) )
return F_87 ( V_7 ) ;
error = F_213 ( V_14 , V_529 , V_433 , V_7 ) ;
if ( error < 0 ) {
F_8 ( L_27 , - error ) ;
goto V_244;
}
if ( V_433 -> V_319 & V_530 &&
! F_298 ( & V_14 -> V_531 , & V_433 -> V_531 ) )
memcpy ( & V_14 -> V_531 , & V_433 -> V_531 , sizeof( V_14 -> V_531 ) ) ;
V_244:
F_114 ( V_7 ) ;
return error ;
}
static int F_299 ( struct V_64 * V_108 , struct V_2 * V_3 ,
const struct V_532 * V_262 , struct V_440 * V_433 ,
struct V_469 * V_470 )
{
int V_328 = - V_171 ;
struct V_533 * V_533 = NULL ;
struct V_534 * V_535 = NULL ;
V_533 = F_300 ( V_418 ) ;
if ( V_533 == NULL )
goto V_153;
V_535 = F_301 ( sizeof( struct V_534 ) , V_418 ) ;
if ( V_535 == NULL )
goto V_153;
V_328 = F_302 ( V_108 , V_3 , V_262 , V_535 , V_533 ) ;
if ( V_328 != 0 )
goto V_153;
if ( F_298 ( & F_103 ( V_3 ) -> V_531 , & V_535 -> V_433 . V_531 ) ) {
F_8 ( L_28
L_29 , V_34 , V_262 -> V_262 ) ;
V_328 = - V_87 ;
goto V_153;
}
F_303 ( & V_535 -> V_433 ) ;
memcpy ( V_433 , & V_535 -> V_433 , sizeof( struct V_440 ) ) ;
memset ( V_470 , 0 , sizeof( struct V_469 ) ) ;
V_153:
if ( V_533 )
F_304 ( V_533 ) ;
F_115 ( V_535 ) ;
return V_328 ;
}
static int F_305 ( struct V_13 * V_14 , struct V_469 * V_470 ,
struct V_440 * V_433 , struct V_1 * V_7 )
{
struct V_536 args = {
. V_266 = V_470 ,
. V_263 = V_14 -> V_15 ,
} ;
struct V_537 V_66 = {
. V_433 = V_433 ,
. V_7 = V_7 ,
. V_14 = V_14 ,
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_538 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
} ;
args . V_263 = F_6 ( V_14 , V_7 ) ;
F_99 ( V_433 ) ;
return F_89 ( V_14 -> V_108 , V_14 , & V_176 , & args . V_164 , & V_66 . V_165 , 0 ) ;
}
static int F_213 ( struct V_13 * V_14 , struct V_469 * V_470 ,
struct V_440 * V_433 , struct V_1 * V_7 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_305 ( V_14 , V_470 , V_433 , V_7 ) ;
F_306 ( V_14 , V_470 , V_433 , V_8 ) ;
V_8 = F_36 ( V_14 , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int
F_307 ( struct V_4 * V_4 , struct V_440 * V_433 ,
struct V_5 * V_6 )
{
struct V_2 * V_2 = F_14 ( V_4 ) ;
struct V_51 * V_52 = NULL ;
struct V_322 * V_323 = NULL ;
struct V_1 * V_7 = NULL ;
int V_328 ;
if ( F_308 ( V_2 ) &&
V_6 -> V_268 & V_435 &&
V_6 -> V_539 < F_309 ( V_2 ) )
F_310 ( V_2 ) ;
F_99 ( V_433 ) ;
if ( V_6 -> V_268 & V_442 )
V_6 -> V_268 &= ~ ( V_402 | V_540 ) ;
if ( ( V_6 -> V_268 & ~ ( V_541 | V_442 ) ) == 0 )
return 0 ;
if ( V_6 -> V_268 & V_541 ) {
V_323 = F_311 ( V_6 -> V_542 ) ;
if ( V_323 )
V_52 = V_323 -> V_52 ;
}
V_7 = F_105 ( F_103 ( V_2 ) , V_418 ) ;
if ( F_78 ( V_7 ) )
return F_87 ( V_7 ) ;
V_328 = F_255 ( V_2 , V_52 , V_433 , V_6 , V_323 , NULL , V_7 ) ;
if ( V_328 == 0 ) {
F_256 ( V_2 , V_6 , V_433 ) ;
F_257 ( V_2 , V_433 , V_7 ) ;
}
F_114 ( V_7 ) ;
return V_328 ;
}
static int F_312 ( struct V_64 * V_65 , struct V_2 * V_3 ,
const struct V_532 * V_262 , struct V_469 * V_470 ,
struct V_440 * V_433 , struct V_1 * V_7 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
int V_328 ;
struct V_543 args = {
. V_263 = V_14 -> V_15 ,
. V_544 = F_112 ( V_3 ) ,
. V_262 = V_262 ,
} ;
struct V_513 V_66 = {
. V_14 = V_14 ,
. V_433 = V_433 ,
. V_7 = V_7 ,
. V_266 = V_470 ,
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_545 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
} ;
args . V_263 = F_6 ( V_14 , V_7 ) ;
F_99 ( V_433 ) ;
F_8 ( L_30 , V_262 -> V_262 ) ;
V_328 = F_89 ( V_65 , V_14 , & V_176 , & args . V_164 , & V_66 . V_165 , 0 ) ;
F_8 ( L_31 , V_328 ) ;
return V_328 ;
}
static void F_313 ( struct V_440 * V_433 )
{
V_433 -> V_319 |= V_356 | V_546 |
V_547 | V_548 ;
V_433 -> V_279 = V_361 | V_549 | V_550 ;
V_433 -> V_551 = 2 ;
}
static int F_314 ( struct V_64 * * V_65 , struct V_2 * V_3 ,
const struct V_532 * V_262 , struct V_469 * V_470 ,
struct V_440 * V_433 , struct V_1 * V_7 )
{
struct V_70 V_71 = { } ;
struct V_64 * V_108 = * V_65 ;
int V_8 ;
do {
V_8 = F_312 ( V_108 , V_3 , V_262 , V_470 , V_433 , V_7 ) ;
F_315 ( V_3 , V_262 , V_8 ) ;
switch ( V_8 ) {
case - V_26 :
V_8 = - V_324 ;
goto V_153;
case - V_87 :
V_8 = F_299 ( V_108 , V_3 , V_262 , V_433 , V_470 ) ;
if ( V_8 == - V_87 )
V_8 = F_36 ( F_103 ( V_3 ) , V_8 , & V_71 ) ;
goto V_153;
case - V_22 :
V_8 = - V_24 ;
if ( V_108 != * V_65 )
goto V_153;
V_108 = F_316 ( V_108 , V_3 , V_262 ) ;
if ( F_78 ( V_108 ) )
return F_87 ( V_108 ) ;
V_71 . V_77 = 1 ;
break;
default:
V_8 = F_36 ( F_103 ( V_3 ) , V_8 , & V_71 ) ;
}
} while ( V_71 . V_77 );
V_153:
if ( V_8 == 0 )
* V_65 = V_108 ;
else if ( V_108 != * V_65 )
F_317 ( V_108 ) ;
return V_8 ;
}
static int F_318 ( struct V_2 * V_3 , const struct V_532 * V_262 ,
struct V_469 * V_470 , struct V_440 * V_433 ,
struct V_1 * V_7 )
{
int V_328 ;
struct V_64 * V_108 = F_319 ( V_3 ) ;
V_328 = F_314 ( & V_108 , V_3 , V_262 , V_470 , V_433 , V_7 ) ;
if ( V_108 != F_319 ( V_3 ) ) {
F_317 ( V_108 ) ;
F_313 ( V_433 ) ;
}
return V_328 ;
}
struct V_64 *
F_320 ( struct V_2 * V_3 , const struct V_532 * V_262 ,
struct V_469 * V_470 , struct V_440 * V_433 )
{
struct V_64 * V_108 = F_319 ( V_3 ) ;
int V_328 ;
V_328 = F_314 ( & V_108 , V_3 , V_262 , V_470 , V_433 , NULL ) ;
if ( V_328 < 0 )
return F_79 ( V_328 ) ;
return ( V_108 == F_319 ( V_3 ) ) ? F_321 ( V_108 ) : V_108 ;
}
static int F_322 ( struct V_2 * V_2 , struct V_371 * V_552 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_553 args = {
. V_266 = F_112 ( V_2 ) ,
. V_263 = V_14 -> V_461 ,
} ;
struct V_554 V_66 = {
. V_14 = V_14 ,
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_555 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
. V_51 = V_552 -> V_52 ,
} ;
int V_279 = V_552 -> V_373 ;
int V_328 = 0 ;
if ( V_279 & V_378 )
args . V_228 |= V_252 ;
if ( F_323 ( V_2 -> V_556 ) ) {
if ( V_279 & V_557 )
args . V_228 |= V_253 | V_254 | V_558 ;
if ( V_279 & V_376 )
args . V_228 |= V_559 ;
} else {
if ( V_279 & V_557 )
args . V_228 |= V_253 | V_254 ;
if ( V_279 & V_376 )
args . V_228 |= V_255 ;
}
V_66 . V_433 = F_324 () ;
if ( V_66 . V_433 == NULL )
return - V_171 ;
V_328 = F_89 ( V_14 -> V_108 , V_14 , & V_176 , & args . V_164 , & V_66 . V_165 , 0 ) ;
if ( ! V_328 ) {
F_210 ( V_552 , V_66 . V_228 ) ;
F_168 ( V_2 , V_66 . V_433 ) ;
}
F_325 ( V_66 . V_433 ) ;
return V_328 ;
}
static int F_326 ( struct V_2 * V_2 , struct V_371 * V_552 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_322 ( V_2 , V_552 ) ;
F_327 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_2 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_328 ( struct V_2 * V_2 , struct V_533 * V_533 ,
unsigned int V_48 , unsigned int V_560 )
{
struct V_561 args = {
. V_266 = F_112 ( V_2 ) ,
. V_48 = V_48 ,
. V_560 = V_560 ,
. V_42 = & V_533 ,
} ;
struct V_562 V_66 ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_563 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
} ;
return F_89 ( F_103 ( V_2 ) -> V_108 , F_103 ( V_2 ) , & V_176 , & args . V_164 , & V_66 . V_165 , 0 ) ;
}
static int F_329 ( struct V_2 * V_2 , struct V_533 * V_533 ,
unsigned int V_48 , unsigned int V_560 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_328 ( V_2 , V_533 , V_48 , V_560 ) ;
F_330 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_2 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int
F_331 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_5 * V_6 ,
int V_233 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_1 V_17 , * V_441 = NULL ;
struct V_322 * V_323 ;
struct V_73 * V_74 ;
int V_328 = 0 ;
V_323 = F_332 ( V_4 , V_204 , NULL ) ;
if ( F_78 ( V_323 ) )
return F_87 ( V_323 ) ;
V_441 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
if ( ! ( V_14 -> V_15 [ 2 ] & V_404 ) )
V_6 -> V_10 &= ~ F_109 () ;
V_74 = F_259 ( V_3 , V_323 , V_233 , V_6 , V_441 , NULL ) ;
if ( F_78 ( V_74 ) ) {
V_328 = F_87 ( V_74 ) ;
goto V_153;
}
V_153:
F_4 ( V_441 ) ;
F_189 ( V_323 ) ;
return V_328 ;
}
static int F_333 ( struct V_2 * V_3 , const struct V_532 * V_262 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_564 args = {
. V_266 = F_112 ( V_3 ) ,
. V_262 = * V_262 ,
} ;
struct V_565 V_66 = {
. V_14 = V_14 ,
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_566 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
} ;
unsigned long V_125 = V_172 ;
int V_328 ;
V_328 = F_89 ( V_14 -> V_108 , V_14 , & V_176 , & args . V_164 , & V_66 . V_165 , 1 ) ;
if ( V_328 == 0 )
F_90 ( V_3 , & V_66 . V_184 , V_125 ) ;
return V_328 ;
}
static int F_334 ( struct V_2 * V_3 , const struct V_532 * V_262 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_333 ( V_3 , V_262 ) ;
F_335 ( V_3 , V_262 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_3 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static void F_336 ( struct V_175 * V_176 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_564 * args = V_176 -> V_336 ;
struct V_565 * V_66 = V_176 -> V_337 ;
V_66 -> V_14 = V_14 ;
V_176 -> V_333 = & V_334 [ V_566 ] ;
F_51 ( & args -> V_164 , & V_66 -> V_165 , 1 ) ;
F_99 ( V_66 -> V_567 ) ;
}
static void F_337 ( struct V_112 * V_113 , struct V_568 * V_162 )
{
F_73 ( F_180 ( V_162 -> V_4 -> V_245 ) -> V_55 ,
& V_162 -> args . V_164 ,
& V_162 -> V_66 . V_165 ,
V_113 ) ;
}
static int F_338 ( struct V_112 * V_113 , struct V_2 * V_3 )
{
struct V_568 * V_162 = V_113 -> V_569 ;
struct V_565 * V_66 = & V_162 -> V_66 ;
if ( ! F_71 ( V_113 , & V_66 -> V_165 ) )
return 0 ;
if ( F_43 ( V_113 , V_66 -> V_14 , NULL ,
& V_162 -> V_60 ) == - V_118 )
return 0 ;
if ( V_113 -> V_117 == 0 )
F_90 ( V_3 , & V_66 -> V_184 , V_66 -> V_567 -> V_381 ) ;
return 1 ;
}
static void F_339 ( struct V_175 * V_176 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_570 * V_428 = V_176 -> V_336 ;
struct V_571 * V_66 = V_176 -> V_337 ;
V_176 -> V_333 = & V_334 [ V_572 ] ;
V_66 -> V_14 = V_14 ;
F_51 ( & V_428 -> V_164 , & V_66 -> V_165 , 1 ) ;
}
static void F_340 ( struct V_112 * V_113 , struct V_573 * V_162 )
{
F_73 ( F_103 ( V_162 -> V_574 ) -> V_55 ,
& V_162 -> args . V_164 ,
& V_162 -> V_66 . V_165 ,
V_113 ) ;
}
static int F_341 ( struct V_112 * V_113 , struct V_2 * V_574 ,
struct V_2 * V_575 )
{
struct V_573 * V_162 = V_113 -> V_569 ;
struct V_571 * V_66 = & V_162 -> V_66 ;
if ( ! F_71 ( V_113 , & V_66 -> V_165 ) )
return 0 ;
if ( F_43 ( V_113 , V_66 -> V_14 , NULL , & V_162 -> V_60 ) == - V_118 )
return 0 ;
if ( V_113 -> V_117 == 0 ) {
F_90 ( V_574 , & V_66 -> V_576 , V_66 -> V_577 -> V_381 ) ;
if ( V_575 != V_574 )
F_90 ( V_575 , & V_66 -> V_578 , V_66 -> V_579 -> V_381 ) ;
}
return 1 ;
}
static int F_342 ( struct V_2 * V_2 , struct V_2 * V_3 , const struct V_532 * V_262 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_580 V_428 = {
. V_266 = F_112 ( V_2 ) ,
. V_544 = F_112 ( V_3 ) ,
. V_262 = V_262 ,
. V_263 = V_14 -> V_15 ,
} ;
struct V_581 V_66 = {
. V_14 = V_14 ,
. V_7 = NULL ,
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_582 ] ,
. V_336 = & V_428 ,
. V_337 = & V_66 ,
} ;
int V_328 = - V_171 ;
V_66 . V_433 = F_324 () ;
if ( V_66 . V_433 == NULL )
goto V_153;
V_66 . V_7 = F_105 ( V_14 , V_418 ) ;
if ( F_78 ( V_66 . V_7 ) ) {
V_328 = F_87 ( V_66 . V_7 ) ;
goto V_153;
}
V_428 . V_263 = F_6 ( V_14 , V_66 . V_7 ) ;
V_328 = F_89 ( V_14 -> V_108 , V_14 , & V_176 , & V_428 . V_164 , & V_66 . V_165 , 1 ) ;
if ( ! V_328 ) {
F_90 ( V_3 , & V_66 . V_184 , V_66 . V_433 -> V_381 ) ;
V_328 = F_343 ( V_2 , V_66 . V_433 ) ;
if ( ! V_328 )
F_257 ( V_2 , V_66 . V_433 , V_66 . V_7 ) ;
}
F_114 ( V_66 . V_7 ) ;
V_153:
F_325 ( V_66 . V_433 ) ;
return V_328 ;
}
static int F_344 ( struct V_2 * V_2 , struct V_2 * V_3 , const struct V_532 * V_262 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_36 ( F_103 ( V_2 ) ,
F_342 ( V_2 , V_3 , V_262 ) ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static struct V_583 * F_345 ( struct V_2 * V_3 ,
const struct V_532 * V_262 , struct V_5 * V_6 , T_1 V_584 )
{
struct V_583 * V_162 ;
V_162 = F_104 ( sizeof( * V_162 ) , V_418 ) ;
if ( V_162 != NULL ) {
struct V_13 * V_14 = F_103 ( V_3 ) ;
V_162 -> V_7 = F_105 ( V_14 , V_418 ) ;
if ( F_78 ( V_162 -> V_7 ) )
goto V_332;
V_162 -> V_176 . V_333 = & V_334 [ V_585 ] ;
V_162 -> V_176 . V_336 = & V_162 -> V_428 ;
V_162 -> V_176 . V_337 = & V_162 -> V_66 ;
V_162 -> V_428 . V_544 = F_112 ( V_3 ) ;
V_162 -> V_428 . V_14 = V_14 ;
V_162 -> V_428 . V_262 = V_262 ;
V_162 -> V_428 . V_234 = V_6 ;
V_162 -> V_428 . V_584 = V_584 ;
V_162 -> V_428 . V_263 = F_6 ( V_14 , V_162 -> V_7 ) ;
V_162 -> V_428 . V_249 = F_109 () ;
V_162 -> V_66 . V_14 = V_14 ;
V_162 -> V_66 . V_266 = & V_162 -> V_266 ;
V_162 -> V_66 . V_433 = & V_162 -> V_433 ;
V_162 -> V_66 . V_7 = V_162 -> V_7 ;
F_99 ( V_162 -> V_66 . V_433 ) ;
}
return V_162 ;
V_332:
F_115 ( V_162 ) ;
return NULL ;
}
static int F_346 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_583 * V_162 )
{
int V_328 = F_89 ( F_103 ( V_3 ) -> V_108 , F_103 ( V_3 ) , & V_162 -> V_176 ,
& V_162 -> V_428 . V_164 , & V_162 -> V_66 . V_165 , 1 ) ;
if ( V_328 == 0 ) {
F_90 ( V_3 , & V_162 -> V_66 . V_586 ,
V_162 -> V_66 . V_433 -> V_381 ) ;
V_328 = F_347 ( V_4 , V_162 -> V_66 . V_266 , V_162 -> V_66 . V_433 , V_162 -> V_66 . V_7 ) ;
}
return V_328 ;
}
static void F_348 ( struct V_583 * V_162 )
{
F_114 ( V_162 -> V_7 ) ;
F_115 ( V_162 ) ;
}
static int F_349 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_533 * V_533 , unsigned int V_12 , struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_583 * V_162 ;
int V_328 = - V_587 ;
if ( V_12 > V_588 )
goto V_153;
V_328 = - V_171 ;
V_162 = F_345 ( V_3 , & V_4 -> V_11 , V_6 , V_589 ) ;
if ( V_162 == NULL )
goto V_153;
V_162 -> V_176 . V_333 = & V_334 [ V_590 ] ;
V_162 -> V_428 . V_270 . V_591 . V_42 = & V_533 ;
V_162 -> V_428 . V_270 . V_591 . V_12 = V_12 ;
V_162 -> V_428 . V_7 = V_7 ;
V_328 = F_346 ( V_3 , V_4 , V_162 ) ;
F_348 ( V_162 ) ;
V_153:
return V_328 ;
}
static int F_350 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_533 * V_533 , unsigned int V_12 , struct V_5 * V_6 )
{
struct V_70 V_71 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
do {
V_8 = F_349 ( V_3 , V_4 , V_533 , V_12 , V_6 , V_7 ) ;
F_351 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_3 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_352 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_583 * V_162 ;
int V_328 = - V_171 ;
V_162 = F_345 ( V_3 , & V_4 -> V_11 , V_6 , V_592 ) ;
if ( V_162 == NULL )
goto V_153;
V_162 -> V_428 . V_7 = V_7 ;
V_328 = F_346 ( V_3 , V_4 , V_162 ) ;
F_348 ( V_162 ) ;
V_153:
return V_328 ;
}
static int F_353 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_70 V_71 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
if ( ! ( V_14 -> V_15 [ 2 ] & V_404 ) )
V_6 -> V_10 &= ~ F_109 () ;
do {
V_8 = F_352 ( V_3 , V_4 , V_6 , V_7 ) ;
F_354 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_3 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_355 ( struct V_4 * V_4 , struct V_51 * V_52 ,
T_2 V_36 , struct V_533 * * V_42 , unsigned int V_49 , int V_593 )
{
struct V_2 * V_3 = F_14 ( V_4 ) ;
struct V_38 args = {
. V_266 = F_112 ( V_3 ) ,
. V_42 = V_42 ,
. V_48 = 0 ,
. V_49 = V_49 ,
. V_263 = F_103 ( F_14 ( V_4 ) ) -> V_15 ,
. V_593 = V_593 ,
} ;
struct V_594 V_66 ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_595 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
. V_51 = V_52 ,
} ;
int V_328 ;
F_8 ( L_32 , V_34 ,
V_4 ,
( unsigned long long ) V_36 ) ;
F_9 ( V_36 , F_91 ( V_3 ) -> V_596 , V_4 , & args ) ;
V_66 . V_48 = args . V_48 ;
V_328 = F_89 ( F_103 ( V_3 ) -> V_108 , F_103 ( V_3 ) , & V_176 , & args . V_164 , & V_66 . V_165 , 0 ) ;
if ( V_328 >= 0 ) {
memcpy ( F_91 ( V_3 ) -> V_596 , V_66 . V_37 . V_162 , V_597 ) ;
V_328 += args . V_48 ;
}
F_356 ( V_3 ) ;
F_8 ( L_33 , V_34 , V_328 ) ;
return V_328 ;
}
static int F_357 ( struct V_4 * V_4 , struct V_51 * V_52 ,
T_2 V_36 , struct V_533 * * V_42 , unsigned int V_49 , int V_593 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_355 ( V_4 , V_52 , V_36 ,
V_42 , V_49 , V_593 ) ;
F_358 ( F_14 ( V_4 ) , V_8 ) ;
V_8 = F_36 ( F_103 ( F_14 ( V_4 ) ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_359 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 , T_10 V_598 )
{
struct V_583 * V_162 ;
int V_279 = V_6 -> V_10 ;
int V_328 = - V_171 ;
V_162 = F_345 ( V_3 , & V_4 -> V_11 , V_6 , V_599 ) ;
if ( V_162 == NULL )
goto V_153;
if ( F_360 ( V_279 ) )
V_162 -> V_428 . V_584 = V_600 ;
else if ( F_361 ( V_279 ) ) {
V_162 -> V_428 . V_584 = V_601 ;
V_162 -> V_428 . V_270 . V_602 . V_603 = F_362 ( V_598 ) ;
V_162 -> V_428 . V_270 . V_602 . V_604 = F_363 ( V_598 ) ;
}
else if ( F_364 ( V_279 ) ) {
V_162 -> V_428 . V_584 = V_605 ;
V_162 -> V_428 . V_270 . V_602 . V_603 = F_362 ( V_598 ) ;
V_162 -> V_428 . V_270 . V_602 . V_604 = F_363 ( V_598 ) ;
} else if ( ! F_365 ( V_279 ) ) {
V_328 = - V_27 ;
goto V_332;
}
V_162 -> V_428 . V_7 = V_7 ;
V_328 = F_346 ( V_3 , V_4 , V_162 ) ;
V_332:
F_348 ( V_162 ) ;
V_153:
return V_328 ;
}
static int F_366 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , T_10 V_598 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_70 V_71 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
if ( ! ( V_14 -> V_15 [ 2 ] & V_404 ) )
V_6 -> V_10 &= ~ F_109 () ;
do {
V_8 = F_359 ( V_3 , V_4 , V_6 , V_7 , V_598 ) ;
F_367 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_3 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_368 ( struct V_13 * V_14 , struct V_469 * V_470 ,
struct V_606 * V_607 )
{
struct V_608 args = {
. V_266 = V_470 ,
. V_263 = V_14 -> V_15 ,
} ;
struct V_609 V_66 = {
. V_607 = V_607 ,
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_610 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
} ;
F_99 ( V_607 -> V_433 ) ;
return F_89 ( V_14 -> V_108 , V_14 , & V_176 , & args . V_164 , & V_66 . V_165 , 0 ) ;
}
static int F_369 ( struct V_13 * V_14 , struct V_469 * V_470 , struct V_606 * V_607 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_36 ( V_14 ,
F_368 ( V_14 , V_470 , V_607 ) ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_370 ( struct V_13 * V_14 , struct V_469 * V_470 ,
struct V_510 * V_611 )
{
struct V_612 args = {
. V_266 = V_470 ,
. V_263 = V_14 -> V_15 ,
} ;
struct V_613 V_66 = {
. V_611 = V_611 ,
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_614 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
} ;
return F_89 ( V_14 -> V_108 , V_14 , & V_176 , & args . V_164 , & V_66 . V_165 , 0 ) ;
}
static int F_296 ( struct V_13 * V_14 , struct V_469 * V_470 , struct V_510 * V_611 )
{
struct V_70 V_71 = { } ;
unsigned long V_615 = V_172 ;
int V_8 ;
do {
V_8 = F_370 ( V_14 , V_470 , V_611 ) ;
F_371 ( V_14 , V_470 , V_611 -> V_433 , V_8 ) ;
if ( V_8 == 0 ) {
F_372 ( V_14 -> V_55 ,
V_611 -> V_616 * V_98 ,
V_615 ) ;
break;
}
V_8 = F_36 ( V_14 , V_8 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_373 ( struct V_13 * V_14 , struct V_469 * V_470 , struct V_510 * V_611 )
{
int error ;
F_99 ( V_611 -> V_433 ) ;
error = F_296 ( V_14 , V_470 , V_611 ) ;
if ( error == 0 ) {
V_14 -> V_617 = V_611 -> V_618 ;
F_374 ( V_14 , V_470 , V_611 ) ;
}
return error ;
}
static int F_375 ( struct V_13 * V_14 , struct V_469 * V_470 ,
struct V_619 * V_620 )
{
struct V_621 args = {
. V_266 = V_470 ,
. V_263 = V_14 -> V_15 ,
} ;
struct V_622 V_66 = {
. V_620 = V_620 ,
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_623 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
} ;
if ( ( args . V_263 [ 0 ] & V_624 [ 0 ] ) == 0 ) {
memset ( V_620 , 0 , sizeof( * V_620 ) ) ;
return 0 ;
}
F_99 ( V_620 -> V_433 ) ;
return F_89 ( V_14 -> V_108 , V_14 , & V_176 , & args . V_164 , & V_66 . V_165 , 0 ) ;
}
static int F_376 ( struct V_13 * V_14 , struct V_469 * V_470 ,
struct V_619 * V_620 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_36 ( V_14 ,
F_375 ( V_14 , V_470 , V_620 ) ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
int F_377 ( T_4 * V_50 ,
const struct V_322 * V_323 ,
const struct V_436 * V_437 ,
T_6 V_202 )
{
return F_266 ( V_323 -> V_74 , V_202 , V_437 , V_50 , NULL ) ;
}
static bool F_378 ( T_4 * V_50 ,
const struct V_322 * V_323 ,
const struct V_436 * V_437 ,
T_6 V_202 )
{
T_4 V_625 ;
if ( F_377 ( & V_625 , V_323 , V_437 , V_202 ) == - V_35 )
return true ;
return F_155 ( V_50 , & V_625 ) ;
}
static bool F_379 ( int V_8 )
{
switch ( V_8 ) {
case - V_78 :
case - V_79 :
case - V_81 :
case - V_85 :
case - V_103 :
case - V_83 :
case - V_80 :
return true ;
}
return false ;
}
static int F_380 ( struct V_112 * V_113 , struct V_626 * V_627 )
{
struct V_13 * V_14 = F_103 ( V_627 -> V_2 ) ;
F_381 ( V_627 , V_113 -> V_117 ) ;
if ( V_113 -> V_117 < 0 ) {
struct V_70 V_71 = {
. V_2 = V_627 -> V_2 ,
. V_74 = V_627 -> args . V_628 -> V_74 ,
. V_50 = & V_627 -> args . V_50 ,
} ;
V_113 -> V_117 = F_39 ( V_113 ,
V_14 , V_113 -> V_117 , & V_71 ) ;
if ( V_71 . V_77 ) {
F_66 ( V_113 ) ;
return - V_118 ;
}
}
if ( V_113 -> V_117 > 0 )
F_49 ( V_14 , V_627 -> V_125 ) ;
return 0 ;
}
static bool F_382 ( struct V_112 * V_113 ,
struct V_629 * args )
{
if ( ! F_379 ( V_113 -> V_117 ) ||
F_378 ( & args -> V_50 ,
args -> V_628 ,
args -> V_630 ,
V_204 ) )
return false ;
F_66 ( V_113 ) ;
return true ;
}
static int F_383 ( struct V_112 * V_113 , struct V_626 * V_627 )
{
F_8 ( L_34 , V_34 ) ;
if ( ! F_71 ( V_113 , & V_627 -> V_66 . V_165 ) )
return - V_118 ;
if ( F_382 ( V_113 , & V_627 -> args ) )
return - V_118 ;
if ( V_113 -> V_117 > 0 )
F_356 ( V_627 -> V_2 ) ;
return V_627 -> V_631 ? V_627 -> V_631 ( V_113 , V_627 ) :
F_380 ( V_113 , V_627 ) ;
}
static void F_384 ( struct V_626 * V_627 ,
struct V_175 * V_176 )
{
V_627 -> V_125 = V_172 ;
if ( ! V_627 -> V_631 )
V_627 -> V_631 = F_380 ;
V_176 -> V_333 = & V_334 [ V_632 ] ;
F_51 ( & V_627 -> args . V_164 , & V_627 -> V_66 . V_165 , 0 ) ;
}
static int F_385 ( struct V_112 * V_113 ,
struct V_626 * V_627 )
{
if ( F_73 ( F_103 ( V_627 -> V_2 ) -> V_55 ,
& V_627 -> args . V_164 ,
& V_627 -> V_66 . V_165 ,
V_113 ) )
return 0 ;
if ( F_377 ( & V_627 -> args . V_50 , V_627 -> args . V_628 ,
V_627 -> args . V_630 ,
V_627 -> V_633 ) == - V_35 )
return - V_35 ;
if ( F_386 ( F_38 ( V_634 , & V_627 -> args . V_628 -> V_233 ) ) )
return - V_35 ;
return 0 ;
}
static int F_387 ( struct V_112 * V_113 ,
struct V_626 * V_627 )
{
struct V_2 * V_2 = V_627 -> V_2 ;
F_388 ( V_627 , V_113 -> V_117 ) ;
if ( V_113 -> V_117 < 0 ) {
struct V_70 V_71 = {
. V_2 = V_627 -> V_2 ,
. V_74 = V_627 -> args . V_628 -> V_74 ,
. V_50 = & V_627 -> args . V_50 ,
} ;
V_113 -> V_117 = F_39 ( V_113 ,
F_103 ( V_2 ) , V_113 -> V_117 ,
& V_71 ) ;
if ( V_71 . V_77 ) {
F_66 ( V_113 ) ;
return - V_118 ;
}
}
if ( V_113 -> V_117 >= 0 ) {
F_49 ( F_103 ( V_2 ) , V_627 -> V_125 ) ;
F_389 ( V_627 ) ;
}
return 0 ;
}
static bool F_390 ( struct V_112 * V_113 ,
struct V_629 * args )
{
if ( ! F_379 ( V_113 -> V_117 ) ||
F_378 ( & args -> V_50 ,
args -> V_628 ,
args -> V_630 ,
V_205 ) )
return false ;
F_66 ( V_113 ) ;
return true ;
}
static int F_391 ( struct V_112 * V_113 , struct V_626 * V_627 )
{
if ( ! F_71 ( V_113 , & V_627 -> V_66 . V_165 ) )
return - V_118 ;
if ( F_390 ( V_113 , & V_627 -> args ) )
return - V_118 ;
return V_627 -> V_631 ? V_627 -> V_631 ( V_113 , V_627 ) :
F_387 ( V_113 , V_627 ) ;
}
static
bool F_392 ( struct V_626 * V_627 )
{
if ( V_627 -> V_635 != NULL || V_627 -> V_636 != NULL )
return false ;
return F_236 ( V_627 -> V_2 , V_204 ) == 0 ;
}
static void F_393 ( struct V_626 * V_627 ,
struct V_175 * V_176 )
{
struct V_13 * V_14 = F_103 ( V_627 -> V_2 ) ;
if ( ! F_392 ( V_627 ) ) {
V_627 -> args . V_263 = NULL ;
V_627 -> V_66 . V_433 = NULL ;
} else
V_627 -> args . V_263 = V_14 -> V_461 ;
if ( ! V_627 -> V_631 )
V_627 -> V_631 = F_387 ;
V_627 -> V_66 . V_14 = V_14 ;
V_627 -> V_125 = V_172 ;
V_176 -> V_333 = & V_334 [ V_637 ] ;
F_51 ( & V_627 -> args . V_164 , & V_627 -> V_66 . V_165 , 1 ) ;
}
static void F_394 ( struct V_112 * V_113 , struct V_638 * V_162 )
{
F_73 ( F_103 ( V_162 -> V_2 ) -> V_55 ,
& V_162 -> args . V_164 ,
& V_162 -> V_66 . V_165 ,
V_113 ) ;
}
static int F_395 ( struct V_112 * V_113 , struct V_638 * V_162 )
{
struct V_2 * V_2 = V_162 -> V_2 ;
F_396 ( V_162 , V_113 -> V_117 ) ;
if ( F_43 ( V_113 , F_103 ( V_2 ) ,
NULL , NULL ) == - V_118 ) {
F_66 ( V_113 ) ;
return - V_118 ;
}
return 0 ;
}
static int F_397 ( struct V_112 * V_113 , struct V_638 * V_162 )
{
if ( ! F_71 ( V_113 , & V_162 -> V_66 . V_165 ) )
return - V_118 ;
return V_162 -> V_639 ( V_113 , V_162 ) ;
}
static void F_398 ( struct V_638 * V_162 , struct V_175 * V_176 )
{
struct V_13 * V_14 = F_103 ( V_162 -> V_2 ) ;
if ( V_162 -> V_639 == NULL )
V_162 -> V_639 = F_395 ;
V_162 -> V_66 . V_14 = V_14 ;
V_176 -> V_333 = & V_334 [ V_640 ] ;
F_51 ( & V_162 -> args . V_164 , & V_162 -> V_66 . V_165 , 1 ) ;
}
static void F_399 ( void * V_160 )
{
struct V_641 * V_162 = V_160 ;
struct V_55 * V_72 = V_162 -> V_108 ;
if ( F_400 ( & V_72 -> V_642 ) > 1 )
F_401 ( V_72 ) ;
F_402 ( V_72 ) ;
F_115 ( V_162 ) ;
}
static void F_403 ( struct V_112 * V_113 , void * V_160 )
{
struct V_641 * V_162 = V_160 ;
struct V_55 * V_72 = V_162 -> V_108 ;
unsigned long V_125 = V_162 -> V_125 ;
F_404 ( V_72 , V_113 -> V_117 ) ;
switch ( V_113 -> V_117 ) {
case 0 :
break;
case - V_88 :
F_31 ( V_72 ) ;
break;
default:
if ( F_38 ( V_643 , & V_72 -> V_644 ) == 0 )
return;
if ( V_113 -> V_117 != V_645 ) {
F_29 ( V_72 ) ;
return;
}
F_405 ( V_72 ) ;
}
F_45 ( V_72 , V_125 ) ;
}
static int F_406 ( struct V_55 * V_72 , struct V_51 * V_52 , unsigned V_646 )
{
struct V_175 V_176 = {
. V_333 = & V_334 [ V_647 ] ,
. V_336 = V_72 ,
. V_51 = V_52 ,
} ;
struct V_641 * V_162 ;
if ( V_646 == 0 )
return 0 ;
if ( ! F_407 ( & V_72 -> V_642 ) )
return - V_35 ;
V_162 = F_301 ( sizeof( * V_162 ) , V_325 ) ;
if ( V_162 == NULL ) {
F_402 ( V_72 ) ;
return - V_171 ;
}
V_162 -> V_108 = V_72 ;
V_162 -> V_125 = V_172 ;
return F_408 ( V_72 -> V_120 , & V_176 , V_648 ,
& V_649 , V_162 ) ;
}
static int F_409 ( struct V_55 * V_72 , struct V_51 * V_52 )
{
struct V_175 V_176 = {
. V_333 = & V_334 [ V_647 ] ,
. V_336 = V_72 ,
. V_51 = V_52 ,
} ;
unsigned long V_615 = V_172 ;
int V_328 ;
V_328 = F_410 ( V_72 -> V_120 , & V_176 , V_648 ) ;
if ( V_328 < 0 )
return V_328 ;
F_45 ( V_72 , V_615 ) ;
return 0 ;
}
static inline int F_411 ( struct V_13 * V_14 )
{
return V_14 -> V_104 & V_486 ;
}
static int F_412 ( const void * V_650 , T_9 V_651 ,
struct V_533 * * V_42 )
{
struct V_533 * V_652 , * * V_653 ;
int V_654 = 0 ;
T_9 V_12 ;
V_653 = V_42 ;
do {
V_12 = F_413 ( T_9 , V_655 , V_651 ) ;
V_652 = F_300 ( V_418 ) ;
if ( V_652 == NULL )
goto V_656;
memcpy ( F_414 ( V_652 ) , V_650 , V_12 ) ;
V_650 += V_12 ;
V_651 -= V_12 ;
* V_42 ++ = V_652 ;
V_654 ++ ;
} while ( V_651 != 0 );
return V_654 ;
V_656:
for(; V_654 > 0 ; V_654 -- )
F_304 ( V_653 [ V_654 - 1 ] ) ;
return - V_171 ;
}
static void F_415 ( struct V_2 * V_2 , struct V_657 * V_658 )
{
struct V_185 * V_186 = F_91 ( V_2 ) ;
F_46 ( & V_2 -> V_187 ) ;
F_115 ( V_186 -> V_659 ) ;
V_186 -> V_659 = V_658 ;
F_48 ( & V_2 -> V_187 ) ;
}
static void F_416 ( struct V_2 * V_2 )
{
F_415 ( V_2 , NULL ) ;
}
static inline T_11 F_417 ( struct V_2 * V_2 , char * V_650 , T_9 V_651 )
{
struct V_185 * V_186 = F_91 ( V_2 ) ;
struct V_657 * V_658 ;
int V_61 = - V_324 ;
F_46 ( & V_2 -> V_187 ) ;
V_658 = V_186 -> V_659 ;
if ( V_658 == NULL )
goto V_153;
if ( V_650 == NULL )
goto V_660;
if ( V_658 -> V_661 == 0 )
goto V_153;
V_61 = - V_662 ;
if ( V_658 -> V_12 > V_651 )
goto V_153;
memcpy ( V_650 , V_658 -> V_162 , V_658 -> V_12 ) ;
V_660:
V_61 = V_658 -> V_12 ;
V_153:
F_48 ( & V_2 -> V_187 ) ;
return V_61 ;
}
static void F_418 ( struct V_2 * V_2 , struct V_533 * * V_42 , T_9 V_48 , T_9 V_663 )
{
struct V_657 * V_658 ;
T_9 V_651 = sizeof( * V_658 ) + V_663 ;
if ( V_651 <= V_655 ) {
V_658 = F_301 ( V_651 , V_418 ) ;
if ( V_658 == NULL )
goto V_153;
V_658 -> V_661 = 1 ;
F_419 ( V_658 -> V_162 , V_42 , V_48 , V_663 ) ;
} else {
V_658 = F_301 ( sizeof( * V_658 ) , V_418 ) ;
if ( V_658 == NULL )
goto V_153;
V_658 -> V_661 = 0 ;
}
V_658 -> V_12 = V_663 ;
V_153:
F_415 ( V_2 , V_658 ) ;
}
static T_11 F_420 ( struct V_2 * V_2 , void * V_650 , T_9 V_651 )
{
struct V_533 * V_42 [ V_664 + 1 ] = { NULL , } ;
struct V_665 args = {
. V_266 = F_112 ( V_2 ) ,
. V_666 = V_42 ,
. V_663 = V_651 ,
} ;
struct V_667 V_66 = {
. V_663 = V_651 ,
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_668 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
} ;
unsigned int V_669 = F_421 ( V_651 , V_655 ) + 1 ;
int V_61 = - V_171 , V_476 ;
if ( V_669 > F_287 ( V_42 ) )
return - V_662 ;
for ( V_476 = 0 ; V_476 < V_669 ; V_476 ++ ) {
V_42 [ V_476 ] = F_300 ( V_418 ) ;
if ( ! V_42 [ V_476 ] )
goto V_332;
}
V_66 . V_670 = F_300 ( V_418 ) ;
if ( ! V_66 . V_670 )
goto V_332;
args . V_663 = V_669 * V_655 ;
F_8 ( L_35 ,
V_34 , V_650 , V_651 , V_669 , args . V_663 ) ;
V_61 = F_89 ( F_103 ( V_2 ) -> V_108 , F_103 ( V_2 ) ,
& V_176 , & args . V_164 , & V_66 . V_165 , 0 ) ;
if ( V_61 )
goto V_332;
if ( V_66 . V_671 & V_672 ) {
if ( V_650 == NULL )
goto V_673;
V_61 = - V_662 ;
goto V_332;
}
F_418 ( V_2 , V_42 , V_66 . V_674 , V_66 . V_663 ) ;
if ( V_650 ) {
if ( V_66 . V_663 > V_651 ) {
V_61 = - V_662 ;
goto V_332;
}
F_419 ( V_650 , V_42 , V_66 . V_674 , V_66 . V_663 ) ;
}
V_673:
V_61 = V_66 . V_663 ;
V_332:
for ( V_476 = 0 ; V_476 < V_669 ; V_476 ++ )
if ( V_42 [ V_476 ] )
F_304 ( V_42 [ V_476 ] ) ;
if ( V_66 . V_670 )
F_304 ( V_66 . V_670 ) ;
return V_61 ;
}
static T_11 F_422 ( struct V_2 * V_2 , void * V_650 , T_9 V_651 )
{
struct V_70 V_71 = { } ;
T_11 V_61 ;
do {
V_61 = F_420 ( V_2 , V_650 , V_651 ) ;
F_423 ( V_2 , V_61 ) ;
if ( V_61 >= 0 )
break;
V_61 = F_36 ( F_103 ( V_2 ) , V_61 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_61 ;
}
static T_11 F_424 ( struct V_2 * V_2 , void * V_650 , T_9 V_651 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
int V_61 ;
if ( ! F_411 ( V_14 ) )
return - V_675 ;
V_61 = F_425 ( V_14 , V_2 ) ;
if ( V_61 < 0 )
return V_61 ;
if ( F_91 ( V_2 ) -> V_188 & V_197 )
F_426 ( V_2 ) ;
V_61 = F_417 ( V_2 , V_650 , V_651 ) ;
if ( V_61 != - V_324 )
return V_61 ;
return F_422 ( V_2 , V_650 , V_651 ) ;
}
static int F_427 ( struct V_2 * V_2 , const void * V_650 , T_9 V_651 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_533 * V_42 [ V_664 ] ;
struct V_676 V_428 = {
. V_266 = F_112 ( V_2 ) ,
. V_666 = V_42 ,
. V_663 = V_651 ,
} ;
struct V_677 V_66 ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_678 ] ,
. V_336 = & V_428 ,
. V_337 = & V_66 ,
} ;
unsigned int V_669 = F_421 ( V_651 , V_655 ) ;
int V_61 , V_476 ;
if ( ! F_411 ( V_14 ) )
return - V_675 ;
if ( V_669 > F_287 ( V_42 ) )
return - V_662 ;
V_476 = F_412 ( V_650 , V_651 , V_428 . V_666 ) ;
if ( V_476 < 0 )
return V_476 ;
F_159 ( V_2 ) ;
V_61 = F_89 ( V_14 -> V_108 , V_14 , & V_176 , & V_428 . V_164 , & V_66 . V_165 , 1 ) ;
for (; V_476 > 0 ; V_476 -- )
F_428 ( V_42 [ V_476 - 1 ] ) ;
F_46 ( & V_2 -> V_187 ) ;
F_91 ( V_2 ) -> V_188 |= V_189 ;
F_48 ( & V_2 -> V_187 ) ;
F_429 ( V_2 ) ;
F_426 ( V_2 ) ;
return V_61 ;
}
static int F_430 ( struct V_2 * V_2 , const void * V_650 , T_9 V_651 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_427 ( V_2 , V_650 , V_651 ) ;
F_431 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_2 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_432 ( struct V_2 * V_2 , void * V_650 ,
T_9 V_651 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_440 V_433 ;
struct V_1 V_7 = { 0 , 0 , V_651 , V_650 } ;
T_1 V_263 [ 3 ] = { 0 , 0 , V_406 } ;
struct V_536 V_428 = {
. V_266 = F_112 ( V_2 ) ,
. V_263 = V_263 ,
} ;
struct V_537 V_66 = {
. V_433 = & V_433 ,
. V_7 = & V_7 ,
. V_14 = V_14 ,
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_538 ] ,
. V_336 = & V_428 ,
. V_337 = & V_66 ,
} ;
int V_61 ;
F_99 ( & V_433 ) ;
V_61 = F_89 ( V_14 -> V_108 , V_14 , & V_176 , & V_428 . V_164 , & V_66 . V_165 , 0 ) ;
if ( V_61 )
return V_61 ;
if ( ! ( V_433 . V_319 & V_679 ) )
return - V_324 ;
if ( V_651 < V_7 . V_12 )
return - V_662 ;
return 0 ;
}
static int F_433 ( struct V_2 * V_2 , void * V_650 ,
T_9 V_651 )
{
struct V_70 V_71 = { } ;
int V_8 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_675 ;
do {
V_8 = F_432 ( V_2 , V_650 , V_651 ) ;
F_434 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_2 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_435 ( struct V_2 * V_2 ,
struct V_1 * V_441 ,
struct V_440 * V_433 ,
struct V_1 * V_417 )
{
struct V_5 V_6 = { 0 } ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
const T_1 V_263 [ 3 ] = { 0 , 0 , V_406 } ;
struct V_427 V_428 = {
. V_266 = F_112 ( V_2 ) ,
. V_434 = & V_6 ,
. V_14 = V_14 ,
. V_263 = V_263 ,
. V_7 = V_441 ,
} ;
struct V_429 V_66 = {
. V_433 = V_433 ,
. V_7 = V_417 ,
. V_14 = V_14 ,
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_430 ] ,
. V_336 = & V_428 ,
. V_337 = & V_66 ,
} ;
int V_328 ;
F_19 ( & V_428 . V_50 , & V_439 ) ;
V_328 = F_89 ( V_14 -> V_108 , V_14 , & V_176 , & V_428 . V_164 , & V_66 . V_165 , 1 ) ;
if ( V_328 )
F_8 ( L_36 , V_34 , V_328 ) ;
return V_328 ;
}
static int F_436 ( struct V_2 * V_2 ,
struct V_1 * V_441 ,
struct V_440 * V_433 ,
struct V_1 * V_417 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_435 ( V_2 , V_441 ,
V_433 , V_417 ) ;
F_437 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_2 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int
F_438 ( struct V_2 * V_2 , const void * V_650 , T_9 V_651 )
{
struct V_1 V_441 , * V_417 = NULL ;
struct V_440 V_433 ;
struct V_51 * V_52 ;
int V_328 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_675 ;
F_99 ( & V_433 ) ;
V_441 . V_680 = 0 ;
V_441 . V_681 = 0 ;
V_441 . V_7 = ( char * ) V_650 ;
V_441 . V_12 = V_651 ;
V_52 = F_439 () ;
if ( F_78 ( V_52 ) )
return F_87 ( V_52 ) ;
V_417 = F_105 ( F_103 ( V_2 ) , V_418 ) ;
if ( F_78 ( V_417 ) ) {
V_328 = - F_87 ( V_417 ) ;
goto V_153;
}
V_328 = F_436 ( V_2 , & V_441 , & V_433 , V_417 ) ;
if ( V_328 == 0 )
F_257 ( V_2 , & V_433 , V_417 ) ;
F_114 ( V_417 ) ;
V_153:
F_231 ( V_52 ) ;
return V_328 ;
}
static void F_440 ( const struct V_55 * V_72 ,
T_12 * V_682 )
{
T_3 V_269 [ 2 ] ;
if ( F_38 ( V_683 , & V_72 -> V_116 ) ) {
V_269 [ 0 ] = F_441 ( V_684 ) ;
V_269 [ 1 ] = F_441 ( V_684 ) ;
} else {
struct V_685 * V_686 = F_442 ( V_72 -> V_687 , V_688 ) ;
T_2 V_689 = F_110 ( V_686 -> V_690 ) ;
V_269 [ 0 ] = F_441 ( V_689 >> 32 ) ;
V_269 [ 1 ] = F_441 ( V_689 ) ;
}
memcpy ( V_682 -> V_162 , V_269 , sizeof( V_682 -> V_162 ) ) ;
}
static int
F_443 ( struct V_55 * V_72 )
{
T_9 V_12 ;
char * V_691 ;
if ( V_72 -> V_692 != NULL )
return 0 ;
F_153 () ;
V_12 = 14 + strlen ( V_72 -> V_693 ) + 1 +
strlen ( F_444 ( V_72 -> V_120 , V_694 ) ) +
1 +
strlen ( F_444 ( V_72 -> V_120 , V_695 ) ) +
1 ;
F_156 () ;
if ( V_12 > V_696 + 1 )
return - V_27 ;
V_691 = F_301 ( V_12 , V_418 ) ;
if ( ! V_691 )
return - V_171 ;
F_153 () ;
F_445 ( V_691 , V_12 , L_37 ,
V_72 -> V_693 ,
F_444 ( V_72 -> V_120 , V_694 ) ,
F_444 ( V_72 -> V_120 , V_695 ) ) ;
F_156 () ;
V_72 -> V_692 = V_691 ;
return 0 ;
}
static int
F_446 ( struct V_55 * V_72 )
{
T_9 V_12 ;
char * V_691 ;
V_12 = 10 + 10 + 1 + 10 + 1 +
strlen ( V_697 ) + 1 +
strlen ( V_72 -> V_120 -> V_698 ) + 1 ;
if ( V_12 > V_696 + 1 )
return - V_27 ;
V_691 = F_301 ( V_12 , V_418 ) ;
if ( ! V_691 )
return - V_171 ;
F_445 ( V_691 , V_12 , L_38 ,
V_72 -> V_699 -> V_700 , V_72 -> V_472 ,
V_697 ,
V_72 -> V_120 -> V_698 ) ;
V_72 -> V_692 = V_691 ;
return 0 ;
}
static int
F_447 ( struct V_55 * V_72 )
{
T_9 V_12 ;
char * V_691 ;
if ( V_72 -> V_692 != NULL )
return 0 ;
if ( V_697 [ 0 ] != '\0' )
return F_446 ( V_72 ) ;
V_12 = 10 + 10 + 1 + 10 + 1 +
strlen ( V_72 -> V_120 -> V_698 ) + 1 ;
if ( V_12 > V_696 + 1 )
return - V_27 ;
V_691 = F_301 ( V_12 , V_418 ) ;
if ( ! V_691 )
return - V_171 ;
F_445 ( V_691 , V_12 , L_39 ,
V_72 -> V_699 -> V_700 , V_72 -> V_472 ,
V_72 -> V_120 -> V_698 ) ;
V_72 -> V_692 = V_691 ;
return 0 ;
}
static unsigned int
F_448 ( const struct V_55 * V_72 , char * V_650 , T_9 V_12 )
{
if ( strchr ( V_72 -> V_693 , ':' ) != NULL )
return F_445 ( V_650 , V_12 , L_40 ) ;
else
return F_445 ( V_650 , V_12 , L_41 ) ;
}
static void F_449 ( struct V_112 * V_113 , void * V_160 )
{
struct V_701 * V_702 = V_160 ;
if ( V_113 -> V_117 == 0 )
V_702 -> V_703 = F_229 ( V_113 -> V_704 -> V_705 ) ;
}
int F_450 ( struct V_55 * V_72 , T_1 V_706 ,
unsigned short V_707 , struct V_51 * V_52 ,
struct V_708 * V_66 )
{
T_12 V_709 ;
struct V_701 V_710 = {
. V_709 = & V_709 ,
. V_711 = V_706 ,
. V_712 = V_72 ,
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_713 ] ,
. V_336 = & V_710 ,
. V_337 = V_66 ,
. V_51 = V_52 ,
} ;
struct V_112 * V_113 ;
struct V_177 V_338 = {
. V_179 = V_72 -> V_120 ,
. V_175 = & V_176 ,
. V_180 = & V_714 ,
. V_182 = & V_710 ,
. V_233 = V_648 ,
} ;
int V_328 ;
F_440 ( V_72 , & V_709 ) ;
if ( F_38 ( V_715 , & V_72 -> V_716 ) )
V_328 = F_447 ( V_72 ) ;
else
V_328 = F_443 ( V_72 ) ;
if ( V_328 )
goto V_153;
V_710 . V_717 =
F_448 ( V_72 ,
V_710 . V_718 ,
sizeof( V_710 . V_718 ) ) ;
V_710 . V_719 = F_445 ( V_710 . V_720 ,
sizeof( V_710 . V_720 ) , L_42 ,
V_72 -> V_693 , V_707 >> 8 , V_707 & 255 ) ;
F_8 ( L_43 ,
V_72 -> V_120 -> V_121 -> V_721 -> V_722 ,
V_72 -> V_692 ) ;
V_113 = F_86 ( & V_338 ) ;
if ( F_78 ( V_113 ) ) {
V_328 = F_87 ( V_113 ) ;
goto V_153;
}
V_328 = V_113 -> V_117 ;
if ( V_710 . V_703 ) {
V_72 -> V_723 = F_451 ( V_710 . V_703 ) ;
F_231 ( V_710 . V_703 ) ;
}
F_88 ( V_113 ) ;
V_153:
F_452 ( V_72 , V_328 ) ;
F_8 ( L_44 , V_328 ) ;
return V_328 ;
}
int F_453 ( struct V_55 * V_72 ,
struct V_708 * V_428 ,
struct V_51 * V_52 )
{
struct V_175 V_176 = {
. V_333 = & V_334 [ V_724 ] ,
. V_336 = V_428 ,
. V_51 = V_52 ,
} ;
int V_328 ;
F_8 ( L_45 ,
V_72 -> V_120 -> V_121 -> V_721 -> V_722 ,
V_72 -> V_257 ) ;
V_328 = F_410 ( V_72 -> V_120 , & V_176 , V_648 ) ;
F_454 ( V_72 , V_328 ) ;
F_8 ( L_46 , V_328 ) ;
return V_328 ;
}
static void F_455 ( struct V_112 * V_113 , void * V_160 )
{
struct V_725 * V_162 = V_160 ;
if ( ! F_71 ( V_113 , & V_162 -> V_66 . V_165 ) )
return;
F_456 ( & V_162 -> args , & V_162 -> V_66 , V_113 -> V_117 ) ;
if ( V_162 -> args . V_449 && V_113 -> V_117 != 0 ) {
switch( V_162 -> V_66 . V_447 ) {
default:
V_162 -> V_66 . V_447 = - V_450 ;
break;
case 0 :
V_162 -> args . V_449 = NULL ;
V_162 -> V_66 . V_451 = NULL ;
break;
case - V_79 :
case - V_78 :
case - V_80 :
case - V_81 :
case - V_103 :
case - V_452 :
case - V_23 :
V_162 -> args . V_449 = NULL ;
V_162 -> V_66 . V_451 = NULL ;
V_162 -> V_66 . V_447 = 0 ;
F_66 ( V_113 ) ;
return;
}
}
switch ( V_113 -> V_117 ) {
case 0 :
F_49 ( V_162 -> V_66 . V_14 , V_162 -> V_125 ) ;
break;
case - V_79 :
case - V_78 :
case - V_80 :
F_18 ( V_162 -> V_66 . V_14 ,
V_162 -> args . V_50 ,
V_113 -> V_347 . V_51 ) ;
case - V_81 :
case - V_103 :
case - V_85 :
V_113 -> V_117 = 0 ;
break;
case - V_453 :
if ( V_162 -> args . V_263 ) {
V_162 -> args . V_263 = NULL ;
V_162 -> V_66 . V_433 = NULL ;
V_113 -> V_117 = 0 ;
F_66 ( V_113 ) ;
return;
}
default:
if ( F_43 ( V_113 , V_162 -> V_66 . V_14 ,
NULL , NULL ) == - V_118 ) {
F_66 ( V_113 ) ;
return;
}
}
V_162 -> V_316 = V_113 -> V_117 ;
}
static void F_457 ( void * V_160 )
{
struct V_725 * V_162 = V_160 ;
struct V_2 * V_2 = V_162 -> V_2 ;
if ( V_2 ) {
if ( V_162 -> V_445 . V_446 )
F_274 ( & V_162 -> V_445 . V_428 , & V_162 -> V_445 . V_66 ,
V_162 -> V_66 . V_447 ) ;
F_458 ( V_2 , & V_162 -> V_433 ) ;
F_459 ( V_2 ) ;
}
F_115 ( V_160 ) ;
}
static void F_460 ( struct V_112 * V_113 , void * V_162 )
{
struct V_725 * V_726 ;
V_726 = (struct V_725 * ) V_162 ;
if ( ! V_726 -> V_445 . V_446 && F_270 ( V_726 -> V_2 , V_113 ) )
return;
F_73 ( V_726 -> V_66 . V_14 -> V_55 ,
& V_726 -> args . V_164 ,
& V_726 -> V_66 . V_165 ,
V_113 ) ;
}
static int F_461 ( struct V_2 * V_2 , struct V_51 * V_52 , const T_4 * V_50 , int V_727 )
{
struct V_725 * V_162 ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_112 * V_113 ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_728 ] ,
. V_51 = V_52 ,
} ;
struct V_177 V_338 = {
. V_179 = V_14 -> V_108 ,
. V_175 = & V_176 ,
. V_180 = & V_729 ,
. V_233 = V_342 ,
} ;
int V_328 = 0 ;
V_162 = F_104 ( sizeof( * V_162 ) , V_325 ) ;
if ( V_162 == NULL )
return - V_171 ;
F_51 ( & V_162 -> args . V_164 , & V_162 -> V_66 . V_165 , 1 ) ;
F_279 ( V_14 -> V_55 ,
V_464 ,
& V_338 . V_179 , & V_176 ) ;
V_162 -> args . V_470 = & V_162 -> V_266 ;
V_162 -> args . V_50 = & V_162 -> V_50 ;
V_162 -> args . V_263 = V_14 -> V_461 ;
F_203 ( & V_162 -> V_266 , F_112 ( V_2 ) ) ;
F_19 ( & V_162 -> V_50 , V_50 ) ;
V_162 -> V_66 . V_433 = & V_162 -> V_433 ;
V_162 -> V_66 . V_14 = V_14 ;
V_162 -> V_66 . V_447 = - V_450 ;
V_162 -> V_445 . V_428 . V_466 = & V_162 -> V_445 . V_466 ;
F_99 ( V_162 -> V_66 . V_433 ) ;
V_162 -> V_125 = V_172 ;
V_162 -> V_316 = 0 ;
V_162 -> V_445 . V_446 = F_280 ( V_2 , & V_162 -> V_445 . V_428 , & V_162 -> V_445 . V_66 , V_52 ) ;
V_162 -> V_2 = F_462 ( V_2 ) ;
if ( V_162 -> V_2 ) {
if ( V_162 -> V_445 . V_446 ) {
V_162 -> args . V_449 = & V_162 -> V_445 . V_428 ;
V_162 -> V_66 . V_451 = & V_162 -> V_445 . V_66 ;
}
} else if ( V_162 -> V_445 . V_446 ) {
F_274 ( & V_162 -> V_445 . V_428 , & V_162 -> V_445 . V_66 , 0 ) ;
V_162 -> V_445 . V_446 = false ;
}
V_338 . V_182 = V_162 ;
V_176 . V_336 = & V_162 -> args ;
V_176 . V_337 = & V_162 -> V_66 ;
V_113 = F_86 ( & V_338 ) ;
if ( F_78 ( V_113 ) )
return F_87 ( V_113 ) ;
if ( ! V_727 )
goto V_153;
V_328 = F_199 ( V_113 ) ;
if ( V_328 != 0 )
goto V_153;
V_328 = V_162 -> V_316 ;
V_153:
F_88 ( V_113 ) ;
return V_328 ;
}
int F_463 ( struct V_2 * V_2 , struct V_51 * V_52 , const T_4 * V_50 , int V_727 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_461 ( V_2 , V_52 , V_50 , V_727 ) ;
F_464 ( V_2 , V_50 , V_8 ) ;
switch ( V_8 ) {
case - V_85 :
case - V_80 :
case 0 :
return 0 ;
}
V_8 = F_36 ( V_14 , V_8 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_465 ( struct V_73 * V_74 , int V_730 , struct V_731 * V_732 )
{
struct V_2 * V_2 = V_74 -> V_2 ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_55 * V_72 = V_14 -> V_55 ;
struct V_733 V_428 = {
. V_266 = F_112 ( V_2 ) ,
. V_734 = V_732 ,
} ;
struct V_735 V_66 = {
. V_736 = V_732 ,
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_737 ] ,
. V_336 = & V_428 ,
. V_337 = & V_66 ,
. V_51 = V_74 -> V_246 -> V_304 ,
} ;
struct V_305 * V_306 ;
int V_328 ;
V_428 . V_738 . V_256 = V_72 -> V_257 ;
V_328 = F_466 ( V_74 , V_732 ) ;
if ( V_328 != 0 )
goto V_153;
V_306 = V_732 -> V_739 . V_740 . V_246 ;
V_428 . V_738 . V_258 = V_306 -> V_741 . V_261 ;
V_428 . V_738 . V_742 = V_14 -> V_742 ;
V_328 = F_89 ( V_14 -> V_108 , V_14 , & V_176 , & V_428 . V_164 , & V_66 . V_165 , 1 ) ;
switch ( V_328 ) {
case 0 :
V_732 -> V_743 = V_744 ;
break;
case - V_330 :
V_328 = 0 ;
}
V_732 -> V_745 -> V_746 ( V_732 ) ;
V_732 -> V_745 = NULL ;
V_153:
return V_328 ;
}
static int F_467 ( struct V_73 * V_74 , int V_730 , struct V_731 * V_732 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_465 ( V_74 , V_730 , V_732 ) ;
F_468 ( V_732 , V_74 , V_730 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_74 -> V_2 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static struct V_747 * F_469 ( struct V_731 * V_734 ,
struct V_322 * V_323 ,
struct V_305 * V_306 ,
struct V_237 * V_223 )
{
struct V_747 * V_41 ;
struct V_2 * V_2 = V_306 -> V_307 -> V_2 ;
V_41 = F_104 ( sizeof( * V_41 ) , V_325 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_428 . V_266 = F_112 ( V_2 ) ;
V_41 -> V_428 . V_734 = & V_41 -> V_734 ;
V_41 -> V_428 . V_223 = V_223 ;
V_41 -> V_66 . V_223 = V_223 ;
V_41 -> V_306 = V_306 ;
F_108 ( & V_306 -> V_393 ) ;
V_41 -> V_323 = F_177 ( V_323 ) ;
V_41 -> V_437 = F_265 ( V_323 ) ;
memcpy ( & V_41 -> V_734 , V_734 , sizeof( V_41 -> V_734 ) ) ;
V_41 -> V_14 = F_103 ( V_2 ) ;
return V_41 ;
}
static void F_470 ( void * V_162 )
{
struct V_747 * V_160 = V_162 ;
F_119 ( V_160 -> V_428 . V_223 ) ;
F_233 ( V_160 -> V_306 ) ;
F_267 ( V_160 -> V_437 ) ;
F_189 ( V_160 -> V_323 ) ;
F_115 ( V_160 ) ;
}
static void F_471 ( struct V_112 * V_113 , void * V_162 )
{
struct V_747 * V_160 = V_162 ;
if ( ! F_71 ( V_113 , & V_160 -> V_66 . V_165 ) )
return;
switch ( V_113 -> V_117 ) {
case 0 :
F_49 ( V_160 -> V_14 , V_160 -> V_125 ) ;
F_472 ( V_160 -> V_306 -> V_307 -> V_2 , & V_160 -> V_734 ) ;
if ( F_157 ( V_160 -> V_306 ,
& V_160 -> V_66 . V_50 ) )
break;
case - V_79 :
case - V_80 :
F_18 ( V_160 -> V_14 ,
& V_160 -> V_428 . V_50 ,
V_113 -> V_347 . V_51 ) ;
case - V_81 :
case - V_103 :
case - V_85 :
if ( ! F_155 ( & V_160 -> V_428 . V_50 ,
& V_160 -> V_306 -> V_309 ) )
F_66 ( V_113 ) ;
break;
default:
if ( F_43 ( V_113 , V_160 -> V_14 ,
NULL , NULL ) == - V_118 )
F_66 ( V_113 ) ;
}
F_161 ( V_160 -> V_428 . V_223 ) ;
}
static void F_473 ( struct V_112 * V_113 , void * V_162 )
{
struct V_747 * V_160 = V_162 ;
if ( F_38 ( V_748 , & V_160 -> V_437 -> V_749 -> V_233 ) &&
F_474 ( V_113 , V_160 -> V_437 ) )
return;
if ( F_202 ( V_160 -> V_428 . V_223 , V_113 ) != 0 )
goto V_343;
F_19 ( & V_160 -> V_428 . V_50 , & V_160 -> V_306 -> V_309 ) ;
if ( F_38 ( V_391 , & V_160 -> V_306 -> V_392 ) == 0 ) {
goto V_344;
}
V_160 -> V_125 = V_172 ;
if ( F_73 ( V_160 -> V_14 -> V_55 ,
& V_160 -> V_428 . V_164 ,
& V_160 -> V_66 . V_165 ,
V_113 ) != 0 )
F_161 ( V_160 -> V_428 . V_223 ) ;
return;
V_344:
V_113 -> V_355 = NULL ;
V_343:
F_71 ( V_113 , & V_160 -> V_66 . V_165 ) ;
}
static struct V_112 * F_475 ( struct V_731 * V_734 ,
struct V_322 * V_323 ,
struct V_305 * V_306 ,
struct V_237 * V_223 )
{
struct V_747 * V_162 ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_750 ] ,
. V_51 = V_323 -> V_52 ,
} ;
struct V_177 V_338 = {
. V_179 = F_319 ( V_306 -> V_307 -> V_2 ) ,
. V_175 = & V_176 ,
. V_180 = & V_751 ,
. V_340 = V_341 ,
. V_233 = V_342 ,
} ;
F_279 ( F_103 ( V_306 -> V_307 -> V_2 ) -> V_55 ,
V_464 , & V_338 . V_179 , & V_176 ) ;
V_734 -> V_743 = V_744 ;
if ( V_734 -> V_752 & V_753 )
F_142 ( V_748 , & V_323 -> V_233 ) ;
V_162 = F_469 ( V_734 , V_323 , V_306 , V_223 ) ;
if ( V_162 == NULL ) {
F_119 ( V_223 ) ;
return F_79 ( - V_171 ) ;
}
F_51 ( & V_162 -> V_428 . V_164 , & V_162 -> V_66 . V_165 , 1 ) ;
V_176 . V_336 = & V_162 -> V_428 ;
V_176 . V_337 = & V_162 -> V_66 ;
V_338 . V_182 = V_162 ;
return F_86 ( & V_338 ) ;
}
static int F_476 ( struct V_73 * V_74 , int V_730 , struct V_731 * V_732 )
{
struct V_2 * V_2 = V_74 -> V_2 ;
struct V_231 * V_232 = V_74 -> V_246 ;
struct V_185 * V_186 = F_91 ( V_2 ) ;
struct V_237 * V_223 ;
struct V_305 * V_306 ;
struct V_112 * V_113 ;
struct V_237 * ( * V_238 ) ( struct V_239 * , T_7 ) ;
int V_328 = 0 ;
unsigned char V_752 = V_732 -> V_752 ;
V_328 = F_466 ( V_74 , V_732 ) ;
V_732 -> V_752 |= V_754 ;
F_477 ( & V_232 -> V_755 ) ;
F_478 ( & V_186 -> V_756 ) ;
if ( F_472 ( V_2 , V_732 ) == - V_324 ) {
F_479 ( & V_186 -> V_756 ) ;
F_480 ( & V_232 -> V_755 ) ;
goto V_153;
}
F_479 ( & V_186 -> V_756 ) ;
F_480 ( & V_232 -> V_755 ) ;
if ( V_328 != 0 )
goto V_153;
V_306 = V_732 -> V_739 . V_740 . V_246 ;
if ( F_38 ( V_391 , & V_306 -> V_392 ) == 0 )
goto V_153;
V_238 = F_103 ( V_2 ) -> V_55 -> V_56 -> V_238 ;
V_223 = V_238 ( & V_306 -> V_741 , V_418 ) ;
V_328 = - V_171 ;
if ( F_78 ( V_223 ) )
goto V_153;
V_113 = F_475 ( V_732 , F_311 ( V_732 -> V_757 ) , V_306 , V_223 ) ;
V_328 = F_87 ( V_113 ) ;
if ( F_78 ( V_113 ) )
goto V_153;
V_328 = F_199 ( V_113 ) ;
F_88 ( V_113 ) ;
V_153:
V_732 -> V_752 = V_752 ;
F_481 ( V_732 , V_74 , V_758 , V_328 ) ;
return V_328 ;
}
static struct V_759 * F_482 ( struct V_731 * V_734 ,
struct V_322 * V_323 , struct V_305 * V_306 ,
T_7 V_235 )
{
struct V_759 * V_41 ;
struct V_2 * V_2 = V_306 -> V_307 -> V_2 ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_237 * ( * V_238 ) ( struct V_239 * , T_7 ) ;
V_41 = F_104 ( sizeof( * V_41 ) , V_235 ) ;
if ( V_41 == NULL )
return NULL ;
V_41 -> V_428 . V_266 = F_112 ( V_2 ) ;
V_41 -> V_428 . V_734 = & V_41 -> V_734 ;
V_41 -> V_428 . V_760 = F_483 ( & V_306 -> V_307 -> V_246 -> V_243 , V_235 ) ;
if ( F_78 ( V_41 -> V_428 . V_760 ) )
goto V_332;
V_238 = V_14 -> V_55 -> V_56 -> V_238 ;
V_41 -> V_428 . V_761 = V_238 ( & V_306 -> V_741 , V_235 ) ;
if ( F_78 ( V_41 -> V_428 . V_761 ) )
goto V_762;
V_41 -> V_428 . V_738 . V_256 = V_14 -> V_55 -> V_257 ;
V_41 -> V_428 . V_738 . V_258 = V_306 -> V_741 . V_261 ;
V_41 -> V_428 . V_738 . V_742 = V_14 -> V_742 ;
V_41 -> V_66 . V_761 = V_41 -> V_428 . V_761 ;
V_41 -> V_306 = V_306 ;
V_41 -> V_14 = V_14 ;
F_108 ( & V_306 -> V_393 ) ;
V_41 -> V_323 = F_177 ( V_323 ) ;
memcpy ( & V_41 -> V_734 , V_734 , sizeof( V_41 -> V_734 ) ) ;
return V_41 ;
V_762:
F_119 ( V_41 -> V_428 . V_760 ) ;
V_332:
F_115 ( V_41 ) ;
return NULL ;
}
static void F_484 ( struct V_112 * V_113 , void * V_160 )
{
struct V_759 * V_162 = V_160 ;
struct V_73 * V_74 = V_162 -> V_306 -> V_307 ;
F_8 ( L_23 , V_34 ) ;
if ( F_202 ( V_162 -> V_428 . V_761 , V_113 ) != 0 )
goto V_343;
if ( ! F_38 ( V_391 , & V_162 -> V_306 -> V_392 ) ) {
if ( F_202 ( V_162 -> V_428 . V_760 , V_113 ) != 0 ) {
goto V_763;
}
F_19 ( & V_162 -> V_428 . V_293 ,
& V_74 -> V_293 ) ;
V_162 -> V_428 . V_764 = 1 ;
V_162 -> V_66 . V_760 = V_162 -> V_428 . V_760 ;
} else {
V_162 -> V_428 . V_764 = 0 ;
F_19 ( & V_162 -> V_428 . V_765 ,
& V_162 -> V_306 -> V_309 ) ;
}
if ( ! F_264 ( V_74 ) ) {
V_162 -> V_316 = - V_438 ;
V_113 -> V_355 = NULL ;
goto V_766;
}
V_162 -> V_125 = V_172 ;
if ( F_73 ( V_162 -> V_14 -> V_55 ,
& V_162 -> V_428 . V_164 ,
& V_162 -> V_66 . V_165 ,
V_113 ) == 0 )
return;
V_766:
F_161 ( V_162 -> V_428 . V_760 ) ;
V_763:
F_161 ( V_162 -> V_428 . V_761 ) ;
V_343:
F_71 ( V_113 , & V_162 -> V_66 . V_165 ) ;
F_8 ( L_47 , V_34 , V_162 -> V_316 ) ;
}
static void F_485 ( struct V_112 * V_113 , void * V_160 )
{
struct V_759 * V_162 = V_160 ;
struct V_305 * V_306 = V_162 -> V_306 ;
F_8 ( L_23 , V_34 ) ;
if ( ! F_71 ( V_113 , & V_162 -> V_66 . V_165 ) )
return;
V_162 -> V_316 = V_113 -> V_117 ;
switch ( V_113 -> V_117 ) {
case 0 :
F_49 ( F_103 ( F_14 ( V_162 -> V_323 -> V_4 ) ) ,
V_162 -> V_125 ) ;
if ( V_162 -> V_428 . V_767 ) {
V_162 -> V_734 . V_752 &= ~ ( V_768 | V_769 ) ;
if ( F_472 ( V_306 -> V_307 -> V_2 , & V_162 -> V_734 ) < 0 ) {
F_66 ( V_113 ) ;
break;
}
}
if ( V_162 -> V_428 . V_764 != 0 ) {
F_195 ( & V_306 -> V_741 , 0 ) ;
F_19 ( & V_306 -> V_309 , & V_162 -> V_66 . V_50 ) ;
F_142 ( V_391 , & V_306 -> V_392 ) ;
} else if ( ! F_157 ( V_306 , & V_162 -> V_66 . V_50 ) )
F_66 ( V_113 ) ;
break;
case - V_81 :
case - V_103 :
case - V_85 :
case - V_80 :
if ( V_162 -> V_428 . V_764 != 0 ) {
if ( ! F_155 ( & V_162 -> V_428 . V_293 ,
& V_306 -> V_307 -> V_293 ) )
F_66 ( V_113 ) ;
} else if ( ! F_155 ( & V_162 -> V_428 . V_765 ,
& V_306 -> V_309 ) )
F_66 ( V_113 ) ;
}
F_8 ( L_24 , V_34 , V_162 -> V_316 ) ;
}
static void F_486 ( void * V_160 )
{
struct V_759 * V_162 = V_160 ;
F_8 ( L_23 , V_34 ) ;
F_119 ( V_162 -> V_428 . V_760 ) ;
if ( V_162 -> V_331 != 0 ) {
struct V_112 * V_113 ;
V_113 = F_475 ( & V_162 -> V_734 , V_162 -> V_323 , V_162 -> V_306 ,
V_162 -> V_428 . V_761 ) ;
if ( ! F_78 ( V_113 ) )
F_487 ( V_113 ) ;
F_8 ( L_48 , V_34 ) ;
} else
F_119 ( V_162 -> V_428 . V_761 ) ;
F_233 ( V_162 -> V_306 ) ;
F_189 ( V_162 -> V_323 ) ;
F_115 ( V_162 ) ;
F_8 ( L_25 , V_34 ) ;
}
static void F_488 ( struct V_13 * V_14 , struct V_305 * V_306 , int V_764 , int error )
{
switch ( error ) {
case - V_79 :
case - V_80 :
case - V_81 :
V_306 -> V_741 . V_233 &= ~ V_770 ;
if ( V_764 != 0 ||
F_38 ( V_391 , & V_306 -> V_392 ) != 0 )
F_28 ( V_14 , V_306 -> V_307 ) ;
break;
case - V_85 :
V_306 -> V_741 . V_233 &= ~ V_770 ;
F_29 ( V_14 -> V_55 ) ;
} ;
}
static int F_489 ( struct V_73 * V_74 , int V_730 , struct V_731 * V_734 , int V_771 )
{
struct V_759 * V_162 ;
struct V_112 * V_113 ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_772 ] ,
. V_51 = V_74 -> V_246 -> V_304 ,
} ;
struct V_177 V_338 = {
. V_179 = F_319 ( V_74 -> V_2 ) ,
. V_175 = & V_176 ,
. V_180 = & V_773 ,
. V_340 = V_341 ,
. V_233 = V_342 ,
} ;
int V_61 ;
F_8 ( L_23 , V_34 ) ;
V_162 = F_482 ( V_734 , F_311 ( V_734 -> V_757 ) ,
V_734 -> V_739 . V_740 . V_246 ,
V_771 == V_774 ? V_418 : V_325 ) ;
if ( V_162 == NULL )
return - V_171 ;
if ( F_490 ( V_730 ) )
V_162 -> V_428 . V_775 = 1 ;
F_51 ( & V_162 -> V_428 . V_164 , & V_162 -> V_66 . V_165 , 1 ) ;
V_176 . V_336 = & V_162 -> V_428 ;
V_176 . V_337 = & V_162 -> V_66 ;
V_338 . V_182 = V_162 ;
if ( V_771 > V_774 ) {
if ( V_771 == V_776 )
V_162 -> V_428 . V_777 = V_776 ;
F_52 ( & V_162 -> V_428 . V_164 ) ;
} else
V_162 -> V_428 . V_767 = 1 ;
V_113 = F_86 ( & V_338 ) ;
if ( F_78 ( V_113 ) )
return F_87 ( V_113 ) ;
V_61 = F_199 ( V_113 ) ;
if ( V_61 == 0 ) {
V_61 = V_162 -> V_316 ;
if ( V_61 )
F_488 ( V_162 -> V_14 , V_162 -> V_306 ,
V_162 -> V_428 . V_764 , V_61 ) ;
} else
V_162 -> V_331 = 1 ;
F_88 ( V_113 ) ;
F_8 ( L_24 , V_34 , V_61 ) ;
F_491 ( V_734 , V_74 , & V_162 -> V_66 . V_50 , V_730 , V_61 ) ;
return V_61 ;
}
static int F_492 ( struct V_73 * V_74 , struct V_731 * V_732 )
{
struct V_13 * V_14 = F_103 ( V_74 -> V_2 ) ;
struct V_70 V_71 = {
. V_2 = V_74 -> V_2 ,
} ;
int V_8 ;
do {
if ( F_38 ( V_294 , & V_74 -> V_233 ) != 0 )
return 0 ;
V_8 = F_489 ( V_74 , V_758 , V_732 , V_776 ) ;
if ( V_8 != - V_99 )
break;
F_36 ( V_14 , V_8 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_493 ( struct V_73 * V_74 , struct V_731 * V_732 )
{
struct V_13 * V_14 = F_103 ( V_74 -> V_2 ) ;
struct V_70 V_71 = {
. V_2 = V_74 -> V_2 ,
} ;
int V_8 ;
V_8 = F_466 ( V_74 , V_732 ) ;
if ( V_8 != 0 )
return V_8 ;
if ( ! V_394 ) {
F_142 ( V_395 , & V_732 -> V_739 . V_740 . V_246 -> V_392 ) ;
return 0 ;
}
do {
if ( F_38 ( V_294 , & V_74 -> V_233 ) != 0 )
return 0 ;
V_8 = F_489 ( V_74 , V_758 , V_732 , V_778 ) ;
switch ( V_8 ) {
default:
goto V_153;
case - V_101 :
case - V_99 :
F_36 ( V_14 , V_8 , & V_71 ) ;
V_8 = 0 ;
}
} while ( V_71 . V_77 );
V_153:
return V_8 ;
}
static int F_494 ( struct V_73 * V_74 , struct V_731 * V_732 )
{
struct V_305 * V_306 ;
int V_328 ;
V_328 = F_466 ( V_74 , V_732 ) ;
if ( V_328 != 0 )
return V_328 ;
V_306 = V_732 -> V_739 . V_740 . V_246 ;
if ( F_38 ( V_391 , & V_306 -> V_392 ) ||
F_38 ( V_395 , & V_306 -> V_392 ) )
return 0 ;
return F_493 ( V_74 , V_732 ) ;
}
static int F_495 ( struct V_73 * V_74 , int V_730 , struct V_731 * V_732 )
{
struct V_185 * V_186 = F_91 ( V_74 -> V_2 ) ;
struct V_231 * V_232 = V_74 -> V_246 ;
unsigned char V_752 = V_732 -> V_752 ;
int V_328 ;
V_732 -> V_752 |= V_769 ;
V_328 = F_472 ( V_74 -> V_2 , V_732 ) ;
if ( V_328 < 0 )
goto V_153;
F_477 ( & V_232 -> V_755 ) ;
F_478 ( & V_186 -> V_756 ) ;
if ( F_38 ( V_294 , & V_74 -> V_233 ) ) {
V_732 -> V_752 = V_752 & ~ V_768 ;
V_328 = F_472 ( V_74 -> V_2 , V_732 ) ;
F_479 ( & V_186 -> V_756 ) ;
F_480 ( & V_232 -> V_755 ) ;
goto V_153;
}
F_479 ( & V_186 -> V_756 ) ;
F_480 ( & V_232 -> V_755 ) ;
V_328 = F_489 ( V_74 , V_730 , V_732 , V_774 ) ;
V_153:
V_732 -> V_752 = V_752 ;
return V_328 ;
}
static int F_496 ( struct V_73 * V_74 , int V_730 , struct V_731 * V_732 )
{
struct V_70 V_71 = {
. V_74 = V_74 ,
. V_2 = V_74 -> V_2 ,
} ;
int V_8 ;
do {
V_8 = F_495 ( V_74 , V_730 , V_732 ) ;
if ( V_8 == - V_330 )
V_8 = - V_118 ;
V_8 = F_36 ( F_103 ( V_74 -> V_2 ) ,
V_8 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int
F_497 ( struct V_73 * V_74 , int V_730 ,
struct V_731 * V_732 )
{
int V_328 = - V_68 ;
unsigned long V_60 = V_779 ;
while( ! F_498 () ) {
V_328 = F_496 ( V_74 , V_730 , V_732 ) ;
if ( ( V_328 != - V_118 ) || F_499 ( V_730 ) )
break;
F_500 ( V_60 ) ;
V_60 *= 2 ;
V_60 = F_413 (unsigned long, NFS4_LOCK_MAXTIMEOUT, timeout) ;
V_328 = - V_68 ;
}
return V_328 ;
}
static int
F_501 ( T_13 * V_462 , unsigned int V_279 , int V_233 , void * V_780 )
{
int V_61 ;
struct V_781 * V_782 = V_780 ;
struct V_783 * V_784 = V_462 -> V_785 ;
struct V_786 * V_787 = & V_782 -> V_788 ,
* V_789 = V_784 -> V_246 ;
if ( V_787 -> V_256 != V_789 -> V_256 ||
V_787 -> V_258 != V_789 -> V_258 ||
V_787 -> V_742 != V_789 -> V_742 )
return 0 ;
if ( F_502 ( F_112 ( V_784 -> V_2 ) , & V_782 -> V_790 ) )
return 0 ;
V_784 -> V_791 = true ;
V_462 -> V_785 = V_784 -> V_113 ;
V_61 = F_503 ( V_462 , V_279 , V_233 , V_780 ) ;
V_462 -> V_785 = V_784 ;
return V_61 ;
}
static int
F_504 ( struct V_73 * V_74 , int V_730 , struct V_731 * V_732 )
{
int V_328 = - V_68 ;
unsigned long V_233 ;
struct V_305 * V_306 = V_732 -> V_739 . V_740 . V_246 ;
struct V_13 * V_14 = F_103 ( V_74 -> V_2 ) ;
struct V_55 * V_72 = V_14 -> V_55 ;
T_14 * V_792 = & V_72 -> V_793 ;
struct V_786 V_246 = { . V_256 = V_72 -> V_257 ,
. V_258 = V_306 -> V_741 . V_261 ,
. V_742 = V_14 -> V_742 } ;
struct V_783 V_784 = { . V_113 = V_67 ,
. V_2 = V_74 -> V_2 ,
. V_246 = & V_246 ,
. V_791 = false } ;
T_13 V_462 ;
if ( ! F_38 ( V_411 , & V_74 -> V_233 ) )
return F_497 ( V_74 , V_730 , V_732 ) ;
F_505 ( & V_462 ) ;
V_462 . V_785 = & V_784 ;
V_462 . V_794 = F_501 ;
F_506 ( V_792 , & V_462 ) ;
while( ! F_498 () ) {
V_328 = F_496 ( V_74 , V_730 , V_732 ) ;
if ( ( V_328 != - V_118 ) || F_499 ( V_730 ) )
break;
V_328 = - V_68 ;
F_507 ( & V_792 -> V_302 , V_233 ) ;
if ( V_784 . V_791 ) {
F_508 ( & V_792 -> V_302 , V_233 ) ;
continue;
}
F_509 ( V_795 ) ;
F_508 ( & V_792 -> V_302 , V_233 ) ;
F_500 ( V_796 ) ;
}
F_510 ( V_792 , & V_462 ) ;
return V_328 ;
}
static inline int
F_504 ( struct V_73 * V_74 , int V_730 , struct V_731 * V_732 )
{
return F_497 ( V_74 , V_730 , V_732 ) ;
}
static int
F_511 ( struct V_797 * V_798 , int V_730 , struct V_731 * V_732 )
{
struct V_322 * V_323 ;
struct V_73 * V_74 ;
int V_328 ;
V_323 = F_311 ( V_798 ) ;
V_74 = V_323 -> V_74 ;
if ( F_512 ( V_730 ) ) {
if ( V_74 != NULL )
return F_467 ( V_74 , V_799 , V_732 ) ;
return 0 ;
}
if ( ! ( F_499 ( V_730 ) || F_490 ( V_730 ) ) )
return - V_27 ;
if ( V_732 -> V_743 == V_744 ) {
if ( V_74 != NULL )
return F_476 ( V_74 , V_730 , V_732 ) ;
return 0 ;
}
if ( V_74 == NULL )
return - V_800 ;
if ( ( V_732 -> V_752 & V_801 ) &&
! F_38 ( V_409 , & V_74 -> V_233 ) )
return - V_800 ;
V_328 = F_466 ( V_74 , V_732 ) ;
if ( V_328 != 0 )
return V_328 ;
return F_504 ( V_74 , V_730 , V_732 ) ;
}
int F_513 ( struct V_731 * V_734 , struct V_73 * V_74 , const T_4 * V_50 )
{
struct V_13 * V_14 = F_103 ( V_74 -> V_2 ) ;
int V_8 ;
V_8 = F_466 ( V_74 , V_734 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_489 ( V_74 , V_758 , V_734 , V_774 ) ;
return F_190 ( V_14 , V_74 , V_50 , V_8 ) ;
}
static void F_514 ( struct V_112 * V_113 , void * V_160 )
{
struct V_802 * V_162 = V_160 ;
struct V_13 * V_14 = V_162 -> V_14 ;
F_73 ( V_14 -> V_55 , & V_162 -> args . V_164 ,
& V_162 -> V_66 . V_165 , V_113 ) ;
V_162 -> args . V_738 . V_256 = V_14 -> V_55 -> V_257 ;
V_162 -> V_125 = V_172 ;
}
static void F_515 ( struct V_112 * V_113 , void * V_160 )
{
struct V_802 * V_162 = V_160 ;
struct V_13 * V_14 = V_162 -> V_14 ;
F_56 ( V_113 , & V_162 -> V_66 . V_165 ) ;
switch ( V_113 -> V_117 ) {
case 0 :
F_49 ( V_14 , V_162 -> V_125 ) ;
break;
case - V_86 :
case - V_80 :
F_29 ( V_14 -> V_55 ) ;
break;
case - V_88 :
case - V_99 :
if ( F_43 ( V_113 , V_14 ,
NULL , NULL ) == - V_118 )
F_66 ( V_113 ) ;
}
}
static void F_516 ( void * V_160 )
{
struct V_802 * V_162 = V_160 ;
F_517 ( V_162 -> V_14 , V_162 -> V_306 ) ;
F_115 ( V_160 ) ;
}
static void
F_518 ( struct V_13 * V_14 , struct V_305 * V_306 )
{
struct V_802 * V_162 ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_803 ] ,
} ;
if ( V_14 -> V_55 -> V_56 -> V_353 != 0 )
return;
V_162 = F_301 ( sizeof( * V_162 ) , V_325 ) ;
if ( ! V_162 )
return;
V_162 -> V_306 = V_306 ;
V_162 -> V_14 = V_14 ;
V_162 -> args . V_738 . V_256 = V_14 -> V_55 -> V_257 ;
V_162 -> args . V_738 . V_258 = V_306 -> V_741 . V_261 ;
V_162 -> args . V_738 . V_742 = V_14 -> V_742 ;
V_176 . V_336 = & V_162 -> args ;
V_176 . V_337 = & V_162 -> V_66 ;
F_51 ( & V_162 -> args . V_164 , & V_162 -> V_66 . V_165 , 0 ) ;
F_408 ( V_14 -> V_108 , & V_176 , 0 , & V_804 , V_162 ) ;
}
static int F_519 ( const struct V_805 * V_806 ,
struct V_4 * V_807 , struct V_2 * V_2 ,
const char * V_780 , const void * V_650 ,
T_9 V_651 , int V_233 )
{
return F_430 ( V_2 , V_650 , V_651 ) ;
}
static int F_520 ( const struct V_805 * V_806 ,
struct V_4 * V_807 , struct V_2 * V_2 ,
const char * V_780 , void * V_650 , T_9 V_651 )
{
return F_424 ( V_2 , V_650 , V_651 ) ;
}
static bool F_521 ( struct V_4 * V_4 )
{
return F_411 ( F_103 ( F_14 ( V_4 ) ) ) ;
}
static int F_522 ( const struct V_805 * V_806 ,
struct V_4 * V_807 , struct V_2 * V_2 ,
const char * V_780 , const void * V_650 ,
T_9 V_651 , int V_233 )
{
if ( F_523 ( V_780 ) )
return F_438 ( V_2 , V_650 , V_651 ) ;
return - V_675 ;
}
static int F_524 ( const struct V_805 * V_806 ,
struct V_4 * V_807 , struct V_2 * V_2 ,
const char * V_780 , void * V_650 , T_9 V_651 )
{
if ( F_523 ( V_780 ) )
return F_433 ( V_2 , V_650 , V_651 ) ;
return - V_675 ;
}
static T_11
F_525 ( struct V_2 * V_2 , char * V_808 , T_9 V_809 )
{
int V_12 = 0 ;
if ( F_2 ( V_2 , V_9 ) ) {
V_12 = F_526 ( V_2 , V_808 , V_809 ) ;
if ( V_809 && V_12 > V_809 )
return - V_662 ;
}
return V_12 ;
}
static T_11
F_525 ( struct V_2 * V_2 , char * V_808 , T_9 V_809 )
{
return 0 ;
}
static void F_303 ( struct V_440 * V_433 )
{
if ( ! ( ( ( V_433 -> V_319 & V_810 ) ||
( V_433 -> V_319 & V_811 ) ) &&
( V_433 -> V_319 & V_530 ) &&
( V_433 -> V_319 & V_812 ) ) )
return;
V_433 -> V_319 |= V_356 | V_546 |
V_547 | V_813 ;
V_433 -> V_279 = V_361 | V_549 | V_550 ;
V_433 -> V_551 = 2 ;
}
static int F_527 ( struct V_64 * V_108 , struct V_2 * V_3 ,
const struct V_532 * V_262 ,
struct V_534 * V_814 ,
struct V_533 * V_533 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
T_1 V_263 [ 3 ] = {
[ 0 ] = V_815 | V_816 ,
} ;
struct V_817 args = {
. V_544 = F_112 ( V_3 ) ,
. V_262 = V_262 ,
. V_533 = V_533 ,
. V_263 = V_263 ,
} ;
struct V_818 V_66 = {
. V_814 = V_814 ,
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_819 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
} ;
int V_328 ;
F_8 ( L_49 , V_34 ) ;
if ( F_103 ( V_3 ) -> V_15 [ 1 ] & V_820 )
V_263 [ 1 ] |= V_820 ;
else
V_263 [ 0 ] |= V_45 ;
F_99 ( & V_814 -> V_433 ) ;
V_814 -> V_14 = V_14 ;
V_814 -> V_821 = 0 ;
V_328 = F_89 ( V_108 , V_14 , & V_176 , & args . V_164 , & V_66 . V_165 , 0 ) ;
F_8 ( L_50 , V_34 , V_328 ) ;
return V_328 ;
}
int F_302 ( struct V_64 * V_108 , struct V_2 * V_3 ,
const struct V_532 * V_262 ,
struct V_534 * V_814 ,
struct V_533 * V_533 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_527 ( V_108 , V_3 , V_262 ,
V_814 , V_533 ) ;
F_528 ( V_3 , V_262 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_3 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_529 ( struct V_2 * V_2 ,
struct V_534 * V_535 ,
struct V_533 * V_533 , struct V_51 * V_52 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_64 * V_65 = V_14 -> V_108 ;
T_1 V_263 [ 2 ] = {
[ 0 ] = V_815 | V_816 ,
} ;
struct V_817 args = {
. V_256 = V_14 -> V_55 -> V_257 ,
. V_266 = F_112 ( V_2 ) ,
. V_533 = V_533 ,
. V_263 = V_263 ,
. V_822 = 1 ,
. V_823 = 1 ,
} ;
struct V_818 V_66 = {
. V_814 = V_535 ,
. V_822 = 1 ,
. V_823 = 1 ,
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_819 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
. V_51 = V_52 ,
} ;
unsigned long V_615 = V_172 ;
int V_328 ;
F_99 ( & V_535 -> V_433 ) ;
V_535 -> V_14 = V_14 ;
V_535 -> V_821 = 0 ;
F_51 ( & args . V_164 , & V_66 . V_165 , 0 ) ;
F_52 ( & args . V_164 ) ;
V_328 = F_85 ( V_65 , V_14 , & V_176 ,
& args . V_164 , & V_66 . V_165 ) ;
if ( V_328 )
return V_328 ;
F_49 ( V_14 , V_615 ) ;
return 0 ;
}
static int F_530 ( struct V_2 * V_2 ,
struct V_534 * V_535 ,
struct V_533 * V_533 , struct V_51 * V_52 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_64 * V_65 = V_14 -> V_108 ;
T_1 V_263 [ 2 ] = {
[ 0 ] = V_815 | V_816 ,
} ;
struct V_817 args = {
. V_266 = F_112 ( V_2 ) ,
. V_533 = V_533 ,
. V_263 = V_263 ,
. V_822 = 1 ,
} ;
struct V_818 V_66 = {
. V_814 = V_535 ,
. V_822 = 1 ,
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_819 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
. V_51 = V_52 ,
} ;
int V_328 ;
F_99 ( & V_535 -> V_433 ) ;
V_535 -> V_14 = V_14 ;
V_535 -> V_821 = 0 ;
F_51 ( & args . V_164 , & V_66 . V_165 , 0 ) ;
F_52 ( & args . V_164 ) ;
V_328 = F_85 ( V_65 , V_14 , & V_176 ,
& args . V_164 , & V_66 . V_165 ) ;
if ( V_328 == V_824 &&
V_66 . V_165 . V_157 & V_825 )
V_328 = - V_88 ;
return V_328 ;
}
int F_531 ( struct V_2 * V_2 ,
struct V_534 * V_535 ,
struct V_533 * V_533 , struct V_51 * V_52 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_55 * V_72 = V_14 -> V_55 ;
const struct V_826 * V_54 =
V_72 -> V_56 -> V_827 ;
struct V_70 V_71 = { } ;
int V_328 ;
F_8 ( L_51 , V_34 ,
( unsigned long long ) V_14 -> V_531 . V_828 ,
( unsigned long long ) V_14 -> V_531 . V_829 ,
V_72 -> V_107 ) ;
F_532 ( F_112 ( V_2 ) , V_34 ) ;
do {
V_328 = V_54 -> V_830 ( V_2 , V_535 , V_533 , V_52 ) ;
if ( V_328 != - V_99 )
break;
F_36 ( V_14 , V_328 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_328 ;
}
static int F_533 ( struct V_2 * V_2 , struct V_51 * V_52 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_55 * V_72 = F_103 ( V_2 ) -> V_55 ;
struct V_64 * V_65 = V_14 -> V_108 ;
struct V_831 args = {
. V_266 = F_112 ( V_2 ) ,
. V_256 = V_72 -> V_257 ,
. V_823 = 1 ,
} ;
struct V_832 V_66 = {
. V_823 = 1 ,
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_833 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
. V_51 = V_52 ,
} ;
unsigned long V_615 = V_172 ;
int V_328 ;
V_66 . V_266 = F_534 () ;
if ( V_66 . V_266 == NULL )
return - V_171 ;
F_51 ( & args . V_164 , & V_66 . V_165 , 0 ) ;
F_52 ( & args . V_164 ) ;
V_328 = F_85 ( V_65 , V_14 , & V_176 ,
& args . V_164 , & V_66 . V_165 ) ;
F_535 ( V_66 . V_266 ) ;
if ( V_328 )
return V_328 ;
F_45 ( V_72 , V_615 ) ;
return 0 ;
}
static int F_536 ( struct V_2 * V_2 , struct V_51 * V_52 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_64 * V_65 = V_14 -> V_108 ;
struct V_831 args = {
. V_266 = F_112 ( V_2 ) ,
} ;
struct V_832 V_66 = {
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_833 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
. V_51 = V_52 ,
} ;
int V_328 ;
V_66 . V_266 = F_534 () ;
if ( V_66 . V_266 == NULL )
return - V_171 ;
F_51 ( & args . V_164 , & V_66 . V_165 , 0 ) ;
F_52 ( & args . V_164 ) ;
V_328 = F_85 ( V_65 , V_14 , & V_176 ,
& args . V_164 , & V_66 . V_165 ) ;
F_535 ( V_66 . V_266 ) ;
if ( V_328 == V_824 &&
V_66 . V_165 . V_157 & V_825 )
V_328 = - V_88 ;
return V_328 ;
}
int F_537 ( struct V_2 * V_2 , struct V_51 * V_52 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_55 * V_72 = V_14 -> V_55 ;
const struct V_826 * V_54 =
V_72 -> V_56 -> V_827 ;
struct V_70 V_71 = { } ;
int V_328 ;
F_8 ( L_51 , V_34 ,
( unsigned long long ) V_14 -> V_531 . V_828 ,
( unsigned long long ) V_14 -> V_531 . V_829 ,
V_72 -> V_107 ) ;
F_532 ( F_112 ( V_2 ) , V_34 ) ;
do {
V_328 = V_54 -> V_834 ( V_2 , V_52 ) ;
if ( V_328 != - V_99 )
break;
F_36 ( V_14 , V_328 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_328 ;
}
static int F_538 ( struct V_2 * V_3 , const struct V_532 * V_262 , struct V_835 * V_526 , bool V_836 )
{
int V_328 ;
struct V_837 args = {
. V_544 = F_112 ( V_3 ) ,
. V_262 = V_262 ,
} ;
struct V_838 V_66 = {
. V_526 = V_526 ,
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_839 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
} ;
struct V_64 * V_65 = F_103 ( V_3 ) -> V_108 ;
struct V_51 * V_52 = NULL ;
if ( V_836 ) {
V_65 = F_103 ( V_3 ) -> V_55 -> V_120 ;
V_52 = F_539 ( F_103 ( V_3 ) -> V_55 ) ;
V_176 . V_51 = V_52 ;
}
F_8 ( L_52 , V_262 -> V_262 ) ;
F_279 ( F_103 ( V_3 ) -> V_55 ,
V_840 , & V_65 , & V_176 ) ;
V_328 = F_89 ( V_65 , F_103 ( V_3 ) , & V_176 , & args . V_164 ,
& V_66 . V_165 , 0 ) ;
F_8 ( L_53 , V_328 ) ;
if ( V_52 )
F_231 ( V_52 ) ;
return V_328 ;
}
int F_540 ( struct V_2 * V_3 , const struct V_532 * V_262 ,
struct V_835 * V_526 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_44 ( F_103 ( V_3 ) -> V_55 ) )
V_8 = F_538 ( V_3 , V_262 , V_526 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_538 ( V_3 , V_262 , V_526 , false ) ;
F_541 ( V_3 , V_262 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_3 ) , V_8 ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static int F_542 ( T_1 V_233 )
{
if ( V_233 & ~ V_841 )
goto V_842;
if ( ( V_233 & V_843 ) &&
( V_233 & V_844 ) )
goto V_842;
if ( ! ( V_233 & ( V_845 ) ) )
goto V_842;
return V_388 ;
V_842:
return - V_846 ;
}
static bool
F_543 ( struct V_847 * V_848 ,
struct V_847 * V_849 )
{
if ( V_848 -> V_850 != V_849 -> V_850 )
return false ;
return memcmp ( V_848 -> V_851 , V_849 -> V_851 , V_848 -> V_850 ) == 0 ;
}
static void
F_544 ( struct V_112 * V_113 , void * V_160 )
{
}
static
int F_545 ( struct V_64 * V_65 ,
struct V_852 * V_853 ,
struct V_55 * V_72 ,
struct V_51 * V_52 )
{
int V_328 ;
struct V_854 args = {
. V_108 = V_72 ,
. V_3 = V_855 ,
} ;
struct V_856 V_66 ;
struct V_175 V_176 = {
. V_333 =
& V_334 [ V_857 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
. V_51 = V_52 ,
} ;
struct V_177 V_338 = {
. V_179 = V_65 ,
. V_852 = V_853 ,
. V_180 = & V_858 ,
. V_175 = & V_176 ,
. V_233 = V_648 ,
} ;
struct V_112 * V_113 ;
F_546 ( & args . V_859 , & V_72 -> V_97 -> V_860 ) ;
if ( ! ( V_72 -> V_97 -> V_233 & V_861 ) )
args . V_3 = V_862 ;
if ( V_853 != F_222 ( V_65 -> V_863 ) )
args . V_3 = V_862 ;
V_113 = F_86 ( & V_338 ) ;
if ( ! F_78 ( V_113 ) ) {
V_328 = V_113 -> V_117 ;
F_88 ( V_113 ) ;
} else
V_328 = F_87 ( V_113 ) ;
F_547 ( V_72 , V_328 ) ;
if ( V_328 == 0 ) {
if ( memcmp ( V_66 . V_859 . V_162 ,
V_72 -> V_97 -> V_860 . V_162 , V_864 ) ) {
F_8 ( L_54 , V_34 ) ;
return - V_35 ;
}
if ( ( V_66 . V_3 & args . V_3 ) != V_66 . V_3 || V_66 . V_3 == 0 ) {
F_8 ( L_55 ,
V_34 ) ;
return - V_35 ;
}
if ( V_66 . V_865 != args . V_865 ) {
F_8 ( L_56 ,
V_34 ) ;
return - V_35 ;
}
}
return V_328 ;
}
static int
F_548 ( struct V_64 * V_65 ,
struct V_852 * V_853 ,
void * V_160 )
{
struct V_866 * V_41 = V_160 ;
return F_545 ( V_65 , V_853 , V_41 -> V_72 , V_41 -> V_52 ) ;
}
int F_549 ( struct V_55 * V_72 , struct V_51 * V_52 )
{
struct V_866 V_162 = {
. V_72 = V_72 ,
. V_52 = V_52 ,
} ;
return F_550 ( V_72 -> V_120 ,
F_548 , & V_162 ) ;
}
static int F_551 ( struct V_55 * V_72 ,
struct V_867 * V_232 )
{
static const T_1 V_868 [ V_869 ] = {
[ 1 ] = 1 << ( V_870 - 32 ) |
1 << ( V_871 - 32 ) |
1 << ( V_872 - 32 ) |
1 << ( V_873 - 32 ) |
1 << ( V_874 - 32 )
} ;
unsigned int V_476 ;
if ( V_232 -> V_875 == V_876 ) {
F_552 ( V_877 , L_57 ) ;
for ( V_476 = 0 ; V_476 <= V_878 ; V_476 ++ ) {
if ( F_38 ( V_476 , V_232 -> V_879 . V_270 . V_880 ) )
F_552 ( V_877 , L_58 , V_476 ) ;
if ( F_38 ( V_476 , V_232 -> V_881 . V_270 . V_880 ) )
F_552 ( V_877 , L_59 , V_476 ) ;
}
for ( V_476 = 0 ; V_476 < V_869 ; V_476 ++ ) {
if ( V_232 -> V_879 . V_270 . V_882 [ V_476 ] & ~ V_868 [ V_476 ] ) {
F_552 ( V_877 , L_60 ) ;
return - V_27 ;
}
}
if ( F_38 ( V_870 , V_232 -> V_879 . V_270 . V_880 ) &&
F_38 ( V_872 , V_232 -> V_879 . V_270 . V_880 ) &&
F_38 ( V_873 , V_232 -> V_879 . V_270 . V_880 ) &&
F_38 ( V_874 , V_232 -> V_879 . V_270 . V_880 ) ) {
F_552 ( V_877 , L_61 ) ;
F_552 ( V_877 , L_62 ) ;
F_142 ( V_883 , & V_72 -> V_884 ) ;
} else {
F_552 ( V_877 , L_60 ) ;
return - V_27 ;
}
if ( F_38 ( V_885 , V_232 -> V_881 . V_270 . V_880 ) &&
F_38 ( V_886 , V_232 -> V_881 . V_270 . V_880 ) &&
F_38 ( V_887 , V_232 -> V_881 . V_270 . V_880 ) &&
F_38 ( V_888 , V_232 -> V_881 . V_270 . V_880 ) ) {
F_552 ( V_877 , L_63 ) ;
F_142 ( V_464 , & V_72 -> V_884 ) ;
}
if ( F_38 ( V_889 , V_232 -> V_881 . V_270 . V_880 ) ) {
F_552 ( V_877 , L_64 ) ;
F_142 ( V_890 ,
& V_72 -> V_884 ) ;
}
if ( F_38 ( V_891 , V_232 -> V_881 . V_270 . V_880 ) &&
F_38 ( V_892 , V_232 -> V_881 . V_270 . V_880 ) ) {
F_552 ( V_877 , L_65 ) ;
F_142 ( V_840 , & V_72 -> V_884 ) ;
}
if ( F_38 ( V_893 , V_232 -> V_881 . V_270 . V_880 ) &&
F_38 ( V_894 , V_232 -> V_881 . V_270 . V_880 ) ) {
F_552 ( V_877 , L_66 ) ;
F_142 ( V_895 , & V_72 -> V_884 ) ;
}
if ( F_38 ( V_896 , V_232 -> V_881 . V_270 . V_880 ) ) {
F_552 ( V_877 , L_67 ) ;
F_142 ( V_897 , & V_72 -> V_884 ) ;
}
if ( F_38 ( V_898 , V_232 -> V_881 . V_270 . V_880 ) ) {
F_552 ( V_877 , L_68 ) ;
F_142 ( V_899 , & V_72 -> V_884 ) ;
}
}
return 0 ;
}
static void F_553 ( struct V_112 * V_113 , void * V_162 )
{
struct V_900 * V_901 =
(struct V_900 * ) V_162 ;
struct V_55 * V_72 = V_901 -> args . V_108 ;
int V_328 = V_113 -> V_117 ;
F_554 ( V_72 , V_328 ) ;
if ( V_328 == 0 )
V_328 = F_542 ( V_901 -> V_66 . V_233 ) ;
if ( V_901 -> V_853 && V_328 == 0 ) {
V_328 = F_555 ( V_72 , & V_901 -> V_66 ,
V_901 -> V_853 ) ;
goto V_153;
}
if ( V_328 == 0 )
V_328 = F_551 ( V_72 , & V_901 -> V_66 . V_902 ) ;
if ( V_328 == 0 ) {
V_72 -> V_257 = V_901 -> V_66 . V_256 ;
V_72 -> V_903 = V_901 -> V_66 . V_233 ;
if ( ! ( V_901 -> V_66 . V_233 & V_904 ) ) {
F_144 ( V_905 ,
& V_72 -> V_97 -> V_906 ) ;
V_72 -> V_907 = V_901 -> V_66 . V_223 ;
}
F_115 ( V_72 -> V_908 ) ;
V_72 -> V_908 = V_901 -> V_66 . V_909 ;
V_901 -> V_66 . V_909 = NULL ;
F_115 ( V_72 -> V_910 ) ;
V_72 -> V_910 = V_901 -> V_66 . V_911 ;
V_901 -> V_66 . V_911 = NULL ;
if ( V_72 -> V_912 != NULL &&
! F_543 ( V_72 -> V_912 ,
V_901 -> V_66 . V_851 ) ) {
F_8 ( L_69 ,
V_34 ) ;
F_142 ( V_913 , & V_72 -> V_116 ) ;
F_115 ( V_72 -> V_912 ) ;
V_72 -> V_912 = NULL ;
}
if ( V_72 -> V_912 == NULL ) {
V_72 -> V_912 = V_901 -> V_66 . V_851 ;
V_901 -> V_66 . V_851 = NULL ;
}
memcpy ( V_72 -> V_914 . V_162 , V_901 -> args . V_37 -> V_162 ,
sizeof( V_72 -> V_914 . V_162 ) ) ;
}
V_153:
V_901 -> V_316 = V_328 ;
return;
}
static void F_556 ( void * V_162 )
{
struct V_900 * V_901 =
(struct V_900 * ) V_162 ;
if ( V_901 -> V_853 ) {
F_557 ( V_901 -> V_853 ) ;
F_558 ( V_901 -> args . V_108 -> V_120 ) ;
}
F_402 ( V_901 -> args . V_108 ) ;
F_115 ( V_901 -> V_66 . V_911 ) ;
F_115 ( V_901 -> V_66 . V_851 ) ;
F_115 ( V_901 -> V_66 . V_909 ) ;
F_115 ( V_901 ) ;
}
static int F_559 ( struct V_55 * V_72 , struct V_51 * V_52 ,
T_1 V_915 , struct V_852 * V_853 )
{
T_12 V_37 ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_916 ] ,
. V_51 = V_52 ,
} ;
struct V_177 V_338 = {
. V_179 = V_72 -> V_120 ,
. V_180 = & V_917 ,
. V_175 = & V_176 ,
. V_233 = V_342 | V_648 ,
} ;
struct V_900 * V_160 ;
struct V_112 * V_113 ;
int V_328 ;
if ( ! F_407 ( & V_72 -> V_642 ) )
return - V_35 ;
V_160 = F_104 ( sizeof( * V_160 ) , V_325 ) ;
if ( ! V_160 ) {
F_402 ( V_72 ) ;
return - V_171 ;
}
if ( ! V_853 )
F_440 ( V_72 , & V_37 ) ;
V_328 = F_447 ( V_72 ) ;
if ( V_328 )
goto V_918;
V_160 -> V_66 . V_909 = F_104 ( sizeof( struct V_919 ) ,
V_325 ) ;
V_328 = - V_171 ;
if ( F_386 ( V_160 -> V_66 . V_909 == NULL ) )
goto V_918;
V_160 -> V_66 . V_851 = F_104 ( sizeof( struct V_847 ) ,
V_325 ) ;
if ( F_386 ( V_160 -> V_66 . V_851 == NULL ) )
goto V_920;
V_160 -> V_66 . V_911 = F_104 ( sizeof( struct V_921 ) , V_325 ) ;
if ( F_386 ( V_160 -> V_66 . V_911 == NULL ) )
goto V_922;
switch ( V_915 ) {
case V_923 :
V_160 -> args . V_902 . V_875 = V_923 ;
break;
case V_876 :
V_160 -> args . V_902 = V_924 ;
break;
default:
F_127 ( 1 ) ;
V_328 = - V_27 ;
goto V_925;
}
if ( V_853 ) {
V_160 -> V_853 = V_853 ;
V_338 . V_852 = V_853 ;
V_338 . V_233 =
V_926 | V_927 | V_342 ;
V_160 -> args . V_37 = & V_72 -> V_914 ;
} else {
V_160 -> args . V_37 = & V_37 ;
}
V_160 -> args . V_108 = V_72 ;
#ifdef F_560
V_160 -> args . V_233 = V_928 |
V_929 |
V_930 ,
#else
V_160 -> args . V_233 = V_928 |
V_929 ,
#endif
V_176 . V_336 = & V_160 -> args ;
V_176 . V_337 = & V_160 -> V_66 ;
V_338 . V_182 = V_160 ;
V_113 = F_86 ( & V_338 ) ;
if ( F_78 ( V_113 ) )
return F_87 ( V_113 ) ;
if ( ! V_853 ) {
V_328 = F_199 ( V_113 ) ;
if ( ! V_328 )
V_328 = V_160 -> V_316 ;
} else
V_328 = V_160 -> V_316 ;
F_88 ( V_113 ) ;
V_153:
return V_328 ;
V_925:
F_115 ( V_160 -> V_66 . V_911 ) ;
V_922:
F_115 ( V_160 -> V_66 . V_851 ) ;
V_920:
F_115 ( V_160 -> V_66 . V_909 ) ;
V_918:
F_115 ( V_160 ) ;
F_402 ( V_72 ) ;
goto V_153;
}
int F_561 ( struct V_55 * V_72 , struct V_51 * V_52 )
{
T_5 V_931 = V_72 -> V_120 -> V_121 -> V_122 ;
int V_328 ;
if ( V_931 == V_123 ||
V_931 == V_124 ) {
V_328 = F_559 ( V_72 , V_52 , V_876 , NULL ) ;
if ( ! V_328 )
return 0 ;
}
return F_559 ( V_72 , V_52 , V_923 , NULL ) ;
}
int F_562 ( struct V_64 * V_65 , struct V_852 * V_853 ,
void * V_162 )
{
struct V_932 * V_933 = (struct V_932 * ) V_162 ;
T_1 V_915 ;
F_8 ( L_70 , V_34 ,
V_853 -> V_934 [ V_694 ] ) ;
V_915 = ( V_933 -> V_72 -> V_884 == 0 ? V_923 : V_876 ) ;
return F_559 ( V_933 -> V_72 , V_933 -> V_52 , V_915 , V_853 ) ;
}
static int F_563 ( struct V_55 * V_72 ,
struct V_51 * V_52 )
{
struct V_175 V_176 = {
. V_333 = & V_334 [ V_935 ] ,
. V_336 = V_72 ,
. V_51 = V_52 ,
} ;
int V_328 ;
V_328 = F_410 ( V_72 -> V_120 , & V_176 , V_648 ) ;
F_564 ( V_72 , V_328 ) ;
if ( V_328 )
F_8 ( L_71
L_72 , V_328 , V_72 -> V_107 ) ;
return V_328 ;
}
static int F_565 ( struct V_55 * V_72 ,
struct V_51 * V_52 )
{
unsigned int V_936 ;
int V_61 ;
for ( V_936 = V_937 ; V_936 != 0 ; V_936 -- ) {
V_61 = F_563 ( V_72 , V_52 ) ;
switch ( V_61 ) {
case - V_99 :
case - V_938 :
F_191 ( 1 ) ;
break;
default:
return V_61 ;
}
}
return 0 ;
}
int F_566 ( struct V_55 * V_72 )
{
struct V_51 * V_52 ;
int V_61 = 0 ;
if ( V_72 -> V_56 -> V_353 < 1 )
goto V_153;
if ( V_72 -> V_903 == 0 )
goto V_153;
if ( V_72 -> V_939 )
goto V_153;
V_52 = F_539 ( V_72 ) ;
V_61 = F_565 ( V_72 , V_52 ) ;
if ( V_52 )
F_231 ( V_52 ) ;
switch ( V_61 ) {
case 0 :
case - V_86 :
V_72 -> V_903 = 0 ;
}
V_153:
return V_61 ;
}
static void F_567 ( struct V_112 * V_113 ,
void * V_160 )
{
struct V_940 * V_162 =
(struct V_940 * ) V_160 ;
F_8 ( L_34 , V_34 ) ;
F_73 ( V_162 -> V_72 ,
& V_162 -> args -> V_941 ,
& V_162 -> V_66 -> V_942 ,
V_113 ) ;
F_8 ( L_73 , V_34 ) ;
}
static void F_568 ( struct V_112 * V_113 , void * V_160 )
{
struct V_940 * V_162 =
(struct V_940 * ) V_160 ;
F_8 ( L_34 , V_34 ) ;
if ( ! F_68 ( V_113 , & V_162 -> V_66 -> V_942 ) )
return;
switch ( V_113 -> V_117 ) {
case - V_99 :
case - V_101 :
F_8 ( L_74 , V_34 , V_113 -> V_117 ) ;
F_40 ( V_113 , V_63 ) ;
V_113 -> V_117 = 0 ;
case - V_102 :
F_66 ( V_113 ) ;
return;
}
F_8 ( L_73 , V_34 ) ;
}
int F_569 ( struct V_55 * V_72 , struct V_510 * V_611 )
{
struct V_112 * V_113 ;
struct V_943 args ;
struct V_944 V_66 = {
. V_945 = V_611 ,
} ;
struct V_940 V_162 = {
. args = & args ,
. V_66 = & V_66 ,
. V_72 = V_72 ,
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_946 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
} ;
struct V_177 V_178 = {
. V_179 = V_72 -> V_120 ,
. V_175 = & V_176 ,
. V_180 = & V_947 ,
. V_182 = & V_162 ,
. V_233 = V_648 ,
} ;
int V_328 ;
F_51 ( & args . V_941 , & V_66 . V_942 , 0 ) ;
F_52 ( & args . V_941 ) ;
V_113 = F_86 ( & V_178 ) ;
if ( F_78 ( V_113 ) )
return F_87 ( V_113 ) ;
V_328 = V_113 -> V_117 ;
F_88 ( V_113 ) ;
return V_328 ;
}
static void F_570 ( struct V_948 * args ,
struct V_64 * V_65 )
{
unsigned int V_949 , V_950 ;
unsigned int V_951 = F_571 ( V_65 ) ;
V_949 = V_952 + V_953 ;
V_950 = V_952 + V_954 ;
args -> V_955 . V_949 = V_949 ;
args -> V_955 . V_950 = V_950 ;
args -> V_955 . V_956 = V_957 ;
args -> V_955 . V_958 = V_959 ;
F_8 ( L_75
L_76 ,
V_34 ,
args -> V_955 . V_949 , args -> V_955 . V_950 ,
args -> V_955 . V_956 , args -> V_955 . V_958 ) ;
args -> V_960 . V_949 = V_951 ;
args -> V_960 . V_950 = V_951 ;
args -> V_960 . V_961 = 0 ;
args -> V_960 . V_956 = V_962 ;
args -> V_960 . V_958 = F_413 (unsigned short, max_session_cb_slots, 1 ) ;
F_8 ( L_77
L_78 ,
V_34 ,
args -> V_960 . V_949 , args -> V_960 . V_950 ,
args -> V_960 . V_961 , args -> V_960 . V_956 ,
args -> V_960 . V_958 ) ;
}
static int F_572 ( struct V_948 * args ,
struct V_963 * V_66 )
{
struct V_964 * V_965 = & args -> V_955 ;
struct V_964 * V_966 = & V_66 -> V_955 ;
if ( V_966 -> V_950 > V_965 -> V_950 )
return - V_27 ;
if ( V_966 -> V_956 < V_965 -> V_956 )
return - V_27 ;
if ( V_966 -> V_958 == 0 )
return - V_27 ;
if ( V_966 -> V_958 > V_967 )
V_966 -> V_958 = V_967 ;
return 0 ;
}
static int F_573 ( struct V_948 * args ,
struct V_963 * V_66 )
{
struct V_964 * V_965 = & args -> V_960 ;
struct V_964 * V_966 = & V_66 -> V_960 ;
if ( ! ( V_66 -> V_233 & V_861 ) )
goto V_153;
if ( V_966 -> V_949 > V_965 -> V_949 )
return - V_27 ;
if ( V_966 -> V_950 < V_965 -> V_950 )
return - V_27 ;
if ( V_966 -> V_961 > V_965 -> V_961 )
return - V_27 ;
if ( V_966 -> V_956 > V_965 -> V_956 )
return - V_27 ;
if ( V_966 -> V_958 > V_965 -> V_958 )
return - V_27 ;
V_153:
return 0 ;
}
static int F_574 ( struct V_948 * args ,
struct V_963 * V_66 )
{
int V_61 ;
V_61 = F_572 ( args , V_66 ) ;
if ( V_61 )
return V_61 ;
return F_573 ( args , V_66 ) ;
}
static void F_575 ( struct V_141 * V_142 ,
struct V_963 * V_66 )
{
F_546 ( & V_142 -> V_860 , & V_66 -> V_859 ) ;
V_142 -> V_72 -> V_903 |= V_904 ;
F_142 ( V_905 , & V_142 -> V_906 ) ;
V_142 -> V_233 = V_66 -> V_233 ;
memcpy ( & V_142 -> V_955 , & V_66 -> V_955 , sizeof( V_142 -> V_955 ) ) ;
if ( V_66 -> V_233 & V_861 )
memcpy ( & V_142 -> V_960 , & V_66 -> V_960 ,
sizeof( V_142 -> V_960 ) ) ;
}
static int F_576 ( struct V_55 * V_72 ,
struct V_51 * V_52 )
{
struct V_141 * V_142 = V_72 -> V_97 ;
struct V_948 args = {
. V_108 = V_72 ,
. V_256 = V_72 -> V_257 ,
. V_223 = V_72 -> V_907 ,
. V_968 = V_969 ,
} ;
struct V_963 V_66 ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_970 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
. V_51 = V_52 ,
} ;
int V_328 ;
F_570 ( & args , V_72 -> V_120 ) ;
args . V_233 = ( V_971 | V_861 ) ;
V_328 = F_410 ( V_142 -> V_72 -> V_120 , & V_176 , V_648 ) ;
F_577 ( V_72 , V_328 ) ;
switch ( V_328 ) {
case - V_86 :
case - V_99 :
case - V_972 :
case - V_29 :
case - V_118 :
goto V_153;
} ;
V_72 -> V_907 ++ ;
if ( ! V_328 ) {
V_328 = F_574 ( & args , & V_66 ) ;
if ( V_328 )
goto V_153;
F_575 ( V_142 , & V_66 ) ;
}
V_153:
return V_328 ;
}
int F_578 ( struct V_55 * V_72 , struct V_51 * V_52 )
{
int V_328 ;
unsigned * V_973 ;
struct V_141 * V_142 = V_72 -> V_97 ;
F_8 ( L_79 , V_34 , V_72 , V_142 ) ;
V_328 = F_576 ( V_72 , V_52 ) ;
if ( V_328 )
goto V_153;
V_328 = F_579 ( V_142 ) ;
F_8 ( L_80 , V_328 ) ;
if ( V_328 )
goto V_153;
V_973 = ( unsigned * ) & V_142 -> V_860 . V_162 [ 0 ] ;
F_8 ( L_81 , V_34 ,
V_72 -> V_907 , V_973 [ 0 ] , V_973 [ 1 ] , V_973 [ 2 ] , V_973 [ 3 ] ) ;
V_153:
F_8 ( L_73 , V_34 ) ;
return V_328 ;
}
int F_580 ( struct V_141 * V_142 ,
struct V_51 * V_52 )
{
struct V_175 V_176 = {
. V_333 = & V_334 [ V_974 ] ,
. V_336 = V_142 ,
. V_51 = V_52 ,
} ;
int V_328 = 0 ;
F_8 ( L_82 ) ;
if ( ! F_135 ( V_905 , & V_142 -> V_906 ) )
return 0 ;
V_328 = F_410 ( V_142 -> V_72 -> V_120 , & V_176 , V_648 ) ;
F_581 ( V_142 -> V_72 , V_328 ) ;
if ( V_328 )
F_8 ( L_83
L_84 , V_328 ) ;
F_8 ( L_85 ) ;
return V_328 ;
}
static void F_582 ( void * V_162 )
{
struct V_975 * V_160 = V_162 ;
struct V_55 * V_72 = V_160 -> V_72 ;
if ( F_400 ( & V_72 -> V_642 ) > 1 )
F_401 ( V_72 ) ;
F_402 ( V_72 ) ;
F_115 ( V_160 ) ;
}
static int F_583 ( struct V_112 * V_113 , struct V_55 * V_72 )
{
switch( V_113 -> V_117 ) {
case - V_99 :
F_40 ( V_113 , V_62 ) ;
return - V_118 ;
default:
F_29 ( V_72 ) ;
}
return 0 ;
}
static void F_584 ( struct V_112 * V_113 , void * V_162 )
{
struct V_975 * V_160 = V_162 ;
struct V_55 * V_72 = V_160 -> V_72 ;
if ( ! F_68 ( V_113 , V_113 -> V_347 . V_337 ) )
return;
F_585 ( V_72 , V_113 -> V_117 ) ;
if ( V_113 -> V_117 < 0 ) {
F_8 ( L_86 , V_34 , V_113 -> V_117 ) ;
if ( F_400 ( & V_72 -> V_642 ) == 1 )
goto V_153;
if ( F_583 ( V_113 , V_72 ) == - V_118 ) {
F_66 ( V_113 ) ;
return;
}
}
F_8 ( L_87 , V_34 , V_113 -> V_347 . V_51 ) ;
V_153:
F_8 ( L_73 , V_34 ) ;
}
static void F_586 ( struct V_112 * V_113 , void * V_162 )
{
struct V_975 * V_160 = V_162 ;
struct V_55 * V_72 = V_160 -> V_72 ;
struct V_128 * args ;
struct V_129 * V_66 ;
args = V_113 -> V_347 . V_336 ;
V_66 = V_113 -> V_347 . V_337 ;
F_73 ( V_72 , args , V_66 , V_113 ) ;
}
static struct V_112 * F_587 ( struct V_55 * V_72 ,
struct V_51 * V_52 ,
bool V_976 )
{
struct V_975 * V_160 ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_977 ] ,
. V_51 = V_52 ,
} ;
struct V_177 V_338 = {
. V_179 = V_72 -> V_120 ,
. V_175 = & V_176 ,
. V_180 = & V_978 ,
. V_233 = V_342 | V_648 ,
} ;
if ( ! F_407 ( & V_72 -> V_642 ) )
return F_79 ( - V_35 ) ;
V_160 = F_104 ( sizeof( * V_160 ) , V_325 ) ;
if ( V_160 == NULL ) {
F_402 ( V_72 ) ;
return F_79 ( - V_171 ) ;
}
F_51 ( & V_160 -> args , & V_160 -> V_66 , 0 ) ;
if ( V_976 )
F_52 ( & V_160 -> args ) ;
V_176 . V_336 = & V_160 -> args ;
V_176 . V_337 = & V_160 -> V_66 ;
V_160 -> V_72 = V_72 ;
V_338 . V_182 = V_160 ;
return F_86 ( & V_338 ) ;
}
static int F_588 ( struct V_55 * V_72 , struct V_51 * V_52 , unsigned V_646 )
{
struct V_112 * V_113 ;
int V_61 = 0 ;
if ( ( V_646 & V_979 ) == 0 )
return - V_118 ;
V_113 = F_587 ( V_72 , V_52 , false ) ;
if ( F_78 ( V_113 ) )
V_61 = F_87 ( V_113 ) ;
else
F_487 ( V_113 ) ;
F_8 ( L_88 , V_34 , V_61 ) ;
return V_61 ;
}
static int F_589 ( struct V_55 * V_72 , struct V_51 * V_52 )
{
struct V_112 * V_113 ;
int V_61 ;
V_113 = F_587 ( V_72 , V_52 , true ) ;
if ( F_78 ( V_113 ) ) {
V_61 = F_87 ( V_113 ) ;
goto V_153;
}
V_61 = F_199 ( V_113 ) ;
if ( ! V_61 )
V_61 = V_113 -> V_117 ;
F_88 ( V_113 ) ;
V_153:
F_8 ( L_88 , V_34 , V_61 ) ;
return V_61 ;
}
static void F_590 ( struct V_112 * V_113 , void * V_162 )
{
struct V_980 * V_160 = V_162 ;
F_73 ( V_160 -> V_72 ,
& V_160 -> V_428 . V_164 ,
& V_160 -> V_66 . V_165 ,
V_113 ) ;
}
static int F_591 ( struct V_112 * V_113 , struct V_55 * V_72 )
{
switch( V_113 -> V_117 ) {
case 0 :
case - V_981 :
case - V_23 :
break;
case - V_99 :
F_40 ( V_113 , V_62 ) ;
case - V_102 :
return - V_118 ;
case - V_90 :
case - V_94 :
case - V_93 :
F_33 ( V_72 -> V_97 ,
V_113 -> V_117 ) ;
break;
default:
F_29 ( V_72 ) ;
}
return 0 ;
}
static void F_592 ( struct V_112 * V_113 , void * V_162 )
{
struct V_980 * V_160 = V_162 ;
struct V_55 * V_72 = V_160 -> V_72 ;
struct V_129 * V_66 = & V_160 -> V_66 . V_165 ;
F_8 ( L_34 , V_34 ) ;
if ( ! F_68 ( V_113 , V_66 ) )
return;
F_593 ( V_72 , V_113 -> V_117 ) ;
if ( F_591 ( V_113 , V_72 ) == - V_118 ) {
F_66 ( V_113 ) ;
return;
}
F_8 ( L_73 , V_34 ) ;
}
static void F_594 ( void * V_162 )
{
struct V_980 * V_160 = V_162 ;
F_115 ( V_160 ) ;
}
static int F_595 ( struct V_55 * V_72 ,
struct V_51 * V_52 )
{
struct V_980 * V_160 ;
struct V_112 * V_113 ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_982 ] ,
. V_51 = V_52 ,
} ;
struct V_177 V_338 = {
. V_179 = V_72 -> V_120 ,
. V_175 = & V_176 ,
. V_180 = & V_983 ,
. V_233 = V_342 ,
} ;
int V_328 = - V_171 ;
F_8 ( L_34 , V_34 ) ;
V_160 = F_104 ( sizeof( * V_160 ) , V_325 ) ;
if ( V_160 == NULL )
goto V_153;
V_160 -> V_72 = V_72 ;
V_160 -> V_428 . V_984 = 0 ;
F_51 ( & V_160 -> V_428 . V_164 , & V_160 -> V_66 . V_165 , 0 ) ;
F_52 ( & V_160 -> V_428 . V_164 ) ;
V_176 . V_336 = & V_160 -> V_428 ;
V_176 . V_337 = & V_160 -> V_66 ;
V_338 . V_182 = V_160 ;
V_113 = F_86 ( & V_338 ) ;
if ( F_78 ( V_113 ) ) {
V_328 = F_87 ( V_113 ) ;
goto V_153;
}
V_328 = F_199 ( V_113 ) ;
if ( V_328 == 0 )
V_328 = V_113 -> V_117 ;
F_88 ( V_113 ) ;
V_153:
F_8 ( L_88 , V_34 , V_328 ) ;
return V_328 ;
}
static void
F_596 ( struct V_112 * V_113 , void * V_160 )
{
struct V_985 * V_986 = V_160 ;
struct V_13 * V_14 = F_103 ( V_986 -> args . V_2 ) ;
F_8 ( L_34 , V_34 ) ;
F_73 ( V_14 -> V_55 , & V_986 -> args . V_164 ,
& V_986 -> V_66 . V_165 , V_113 ) ;
F_8 ( L_73 , V_34 ) ;
}
static void F_597 ( struct V_112 * V_113 , void * V_160 )
{
struct V_985 * V_986 = V_160 ;
F_8 ( L_34 , V_34 ) ;
F_61 ( V_113 , & V_986 -> V_66 . V_165 ) ;
F_8 ( L_73 , V_34 ) ;
}
static int
F_598 ( struct V_112 * V_113 ,
struct V_985 * V_986 , struct V_70 * V_71 )
{
struct V_2 * V_2 = V_986 -> args . V_2 ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_987 * V_988 ;
int V_989 = V_113 -> V_117 ;
int V_8 , V_328 = 0 ;
F_599 ( V_990 ) ;
F_8 ( L_89 , V_34 , - V_113 -> V_117 ) ;
switch ( V_989 ) {
case 0 :
goto V_153;
case - V_991 :
V_328 = - V_992 ;
goto V_153;
case - V_993 :
V_328 = - V_994 ;
goto V_153;
case - V_19 :
if ( V_986 -> args . V_995 == 0 ) {
V_328 = - V_994 ;
goto V_153;
}
V_328 = - V_33 ;
break;
case - V_20 :
V_328 = - V_996 ;
break;
case - V_78 :
case - V_79 :
case - V_80 :
case - V_81 :
V_71 -> V_60 = 0 ;
F_46 ( & V_2 -> V_187 ) ;
V_988 = F_91 ( V_2 ) -> V_997 ;
if ( ! V_988 || F_38 ( V_998 , & V_988 -> V_999 ) ||
F_139 ( & V_986 -> args . V_50 ,
& V_986 -> args . V_323 -> V_74 -> V_50 ) ) {
F_48 ( & V_2 -> V_187 ) ;
V_71 -> V_74 = V_986 -> args . V_323 -> V_74 ;
V_71 -> V_50 = & V_986 -> args . V_50 ;
break;
}
F_600 ( V_988 , & V_990 ) ;
F_48 ( & V_2 -> V_187 ) ;
F_601 ( V_2 , 0 ) ;
F_602 ( & V_990 ) ;
V_328 = - V_118 ;
goto V_153;
}
F_70 ( & V_986 -> V_66 . V_165 ) ;
V_8 = F_36 ( V_14 , V_989 , V_71 ) ;
if ( ! V_328 ) {
if ( V_71 -> V_77 )
V_328 = - V_118 ;
else
V_328 = V_8 ;
}
V_153:
F_8 ( L_73 , V_34 ) ;
return V_328 ;
}
static T_9 F_603 ( struct V_13 * V_14 )
{
T_1 V_950 = V_14 -> V_55 -> V_97 -> V_955 . V_950 ;
return F_604 ( 0 , V_950 ) ;
}
static void F_605 ( struct V_533 * * V_42 , T_9 V_1000 )
{
int V_476 ;
if ( ! V_42 )
return;
for ( V_476 = 0 ; V_476 < V_1000 ; V_476 ++ ) {
if ( ! V_42 [ V_476 ] )
break;
F_304 ( V_42 [ V_476 ] ) ;
}
F_115 ( V_42 ) ;
}
static struct V_533 * * F_606 ( T_9 V_1000 , T_7 V_1001 )
{
struct V_533 * * V_42 ;
int V_476 ;
V_42 = F_607 ( V_1000 , sizeof( struct V_533 * ) , V_1001 ) ;
if ( ! V_42 ) {
F_8 ( L_90 , V_34 , V_1000 ) ;
return NULL ;
}
for ( V_476 = 0 ; V_476 < V_1000 ; V_476 ++ ) {
V_42 [ V_476 ] = F_300 ( V_1001 ) ;
if ( ! V_42 [ V_476 ] ) {
F_8 ( L_91 , V_34 ) ;
F_605 ( V_42 , V_1000 ) ;
return NULL ;
}
}
return V_42 ;
}
static void F_608 ( void * V_160 )
{
struct V_985 * V_986 = V_160 ;
struct V_2 * V_2 = V_986 -> args . V_2 ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
T_9 V_1002 = F_603 ( V_14 ) ;
F_8 ( L_34 , V_34 ) ;
F_70 ( & V_986 -> V_66 . V_165 ) ;
F_605 ( V_986 -> args . V_997 . V_42 , V_1002 ) ;
F_609 ( F_91 ( V_2 ) -> V_997 ) ;
F_189 ( V_986 -> args . V_323 ) ;
F_115 ( V_160 ) ;
F_8 ( L_73 , V_34 ) ;
}
struct V_1003 *
F_610 ( struct V_985 * V_986 , long * V_60 , T_7 V_1001 )
{
struct V_2 * V_2 = V_986 -> args . V_2 ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
T_9 V_1002 = F_603 ( V_14 ) ;
struct V_112 * V_113 ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_1004 ] ,
. V_336 = & V_986 -> args ,
. V_337 = & V_986 -> V_66 ,
. V_51 = V_986 -> V_52 ,
} ;
struct V_177 V_338 = {
. V_179 = V_14 -> V_108 ,
. V_175 = & V_176 ,
. V_180 = & V_1005 ,
. V_182 = V_986 ,
. V_233 = V_342 ,
} ;
struct V_1003 * V_1006 = NULL ;
struct V_70 V_71 = {
. V_2 = V_2 ,
. V_60 = * V_60 ,
} ;
int V_328 = 0 ;
F_8 ( L_34 , V_34 ) ;
F_611 ( F_91 ( V_2 ) -> V_997 ) ;
V_986 -> args . V_997 . V_42 = F_606 ( V_1002 , V_1001 ) ;
if ( ! V_986 -> args . V_997 . V_42 ) {
F_608 ( V_986 ) ;
return F_79 ( - V_171 ) ;
}
V_986 -> args . V_997 . V_560 = V_1002 * V_655 ;
V_986 -> V_66 . V_1007 = & V_986 -> args . V_997 ;
V_986 -> V_66 . V_165 . V_134 = NULL ;
F_51 ( & V_986 -> args . V_164 , & V_986 -> V_66 . V_165 , 0 ) ;
V_113 = F_86 ( & V_338 ) ;
if ( F_78 ( V_113 ) )
return F_282 ( V_113 ) ;
V_328 = F_199 ( V_113 ) ;
if ( V_328 == 0 ) {
V_328 = F_598 ( V_113 , V_986 , & V_71 ) ;
* V_60 = V_71 . V_60 ;
}
F_612 ( V_986 -> args . V_323 ,
& V_986 -> args . V_1008 ,
& V_986 -> V_66 . V_1008 ,
& V_986 -> V_66 . V_50 ,
V_328 ) ;
if ( V_328 == 0 && V_986 -> V_66 . V_1007 -> V_12 )
V_1006 = F_613 ( V_986 ) ;
F_88 ( V_113 ) ;
F_8 ( L_88 , V_34 , V_328 ) ;
if ( V_328 )
return F_79 ( V_328 ) ;
return V_1006 ;
}
static void
F_614 ( struct V_112 * V_113 , void * V_160 )
{
struct V_1009 * V_1010 = V_160 ;
F_8 ( L_34 , V_34 ) ;
F_73 ( V_1010 -> V_72 ,
& V_1010 -> args . V_164 ,
& V_1010 -> V_66 . V_165 ,
V_113 ) ;
}
static void F_615 ( struct V_112 * V_113 , void * V_160 )
{
struct V_1009 * V_1010 = V_160 ;
struct V_13 * V_14 ;
F_8 ( L_34 , V_34 ) ;
if ( ! F_61 ( V_113 , & V_1010 -> V_66 . V_165 ) )
return;
V_14 = F_103 ( V_1010 -> args . V_2 ) ;
switch ( V_113 -> V_117 ) {
default:
V_113 -> V_117 = 0 ;
case 0 :
break;
case - V_99 :
if ( F_43 ( V_113 , V_14 , NULL , NULL ) != - V_118 )
break;
F_70 ( & V_1010 -> V_66 . V_165 ) ;
F_66 ( V_113 ) ;
return;
}
F_8 ( L_73 , V_34 ) ;
}
static void F_616 ( void * V_160 )
{
struct V_1009 * V_1010 = V_160 ;
struct V_987 * V_988 = V_1010 -> args . V_997 ;
F_8 ( L_34 , V_34 ) ;
F_617 ( V_988 , & V_1010 -> args . V_50 , & V_1010 -> args . V_1008 ,
V_1010 -> V_66 . V_1011 ? & V_1010 -> V_66 . V_50 : NULL ) ;
F_70 ( & V_1010 -> V_66 . V_165 ) ;
if ( V_1010 -> V_466 . V_54 && V_1010 -> V_466 . V_54 -> free )
V_1010 -> V_466 . V_54 -> free ( & V_1010 -> V_466 ) ;
F_609 ( V_1010 -> args . V_997 ) ;
F_459 ( V_1010 -> V_2 ) ;
F_115 ( V_160 ) ;
F_8 ( L_73 , V_34 ) ;
}
int F_618 ( struct V_1009 * V_1010 , bool V_1012 )
{
struct V_112 * V_113 ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_1013 ] ,
. V_336 = & V_1010 -> args ,
. V_337 = & V_1010 -> V_66 ,
. V_51 = V_1010 -> V_52 ,
} ;
struct V_177 V_338 = {
. V_179 = F_103 ( V_1010 -> args . V_2 ) -> V_108 ,
. V_175 = & V_176 ,
. V_180 = & V_1014 ,
. V_182 = V_1010 ,
} ;
int V_328 = 0 ;
F_279 ( F_103 ( V_1010 -> args . V_2 ) -> V_55 ,
V_890 ,
& V_338 . V_179 , & V_176 ) ;
F_8 ( L_34 , V_34 ) ;
if ( ! V_1012 ) {
V_1010 -> V_2 = F_462 ( V_1010 -> args . V_2 ) ;
if ( ! V_1010 -> V_2 ) {
F_616 ( V_1010 ) ;
return - V_118 ;
}
V_338 . V_233 |= V_342 ;
}
F_51 ( & V_1010 -> args . V_164 , & V_1010 -> V_66 . V_165 , 1 ) ;
V_113 = F_86 ( & V_338 ) ;
if ( F_78 ( V_113 ) )
return F_87 ( V_113 ) ;
if ( V_1012 )
V_328 = V_113 -> V_117 ;
F_619 ( V_1010 -> args . V_2 , & V_1010 -> args . V_50 , V_328 ) ;
F_8 ( L_88 , V_34 , V_328 ) ;
F_88 ( V_113 ) ;
return V_328 ;
}
static int
F_620 ( struct V_13 * V_14 ,
struct V_1015 * V_1016 ,
struct V_51 * V_52 )
{
struct V_1017 args = {
. V_1016 = V_1016 ,
. V_1018 = V_1019 |
V_1020 ,
} ;
struct V_1021 V_66 = {
. V_1016 = V_1016 ,
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_1022 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
. V_51 = V_52 ,
} ;
int V_328 ;
F_8 ( L_34 , V_34 ) ;
V_328 = F_89 ( V_14 -> V_108 , V_14 , & V_176 , & args . V_164 , & V_66 . V_165 , 0 ) ;
if ( V_66 . V_1023 & ~ args . V_1018 )
F_8 ( L_92 , V_34 ) ;
if ( V_66 . V_1023 != args . V_1018 )
V_1016 -> V_1024 = 1 ;
F_8 ( L_88 , V_34 , V_328 ) ;
return V_328 ;
}
int F_621 ( struct V_13 * V_14 ,
struct V_1015 * V_1016 ,
struct V_51 * V_52 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_36 ( V_14 ,
F_620 ( V_14 , V_1016 , V_52 ) ,
& V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static void F_622 ( struct V_112 * V_113 , void * V_160 )
{
struct V_1025 * V_162 = V_160 ;
struct V_13 * V_14 = F_103 ( V_162 -> args . V_2 ) ;
F_73 ( V_14 -> V_55 ,
& V_162 -> args . V_164 ,
& V_162 -> V_66 . V_165 ,
V_113 ) ;
}
static void
F_623 ( struct V_112 * V_113 , void * V_160 )
{
struct V_1025 * V_162 = V_160 ;
struct V_13 * V_14 = F_103 ( V_162 -> args . V_2 ) ;
if ( ! F_68 ( V_113 , & V_162 -> V_66 . V_165 ) )
return;
switch ( V_113 -> V_117 ) {
case - V_78 :
case - V_1026 :
case - V_993 :
case - V_101 :
V_113 -> V_117 = 0 ;
case 0 :
break;
default:
if ( F_43 ( V_113 , V_14 , NULL , NULL ) == - V_118 ) {
F_66 ( V_113 ) ;
return;
}
}
}
static void F_624 ( void * V_160 )
{
struct V_1025 * V_162 = V_160 ;
F_625 ( V_162 ) ;
F_458 ( V_162 -> args . V_2 ,
V_162 -> V_66 . V_433 ) ;
F_231 ( V_162 -> V_52 ) ;
F_459 ( V_162 -> V_2 ) ;
F_115 ( V_162 ) ;
}
int
F_626 ( struct V_1025 * V_162 , bool V_1012 )
{
struct V_175 V_176 = {
. V_333 = & V_334 [ V_1027 ] ,
. V_336 = & V_162 -> args ,
. V_337 = & V_162 -> V_66 ,
. V_51 = V_162 -> V_52 ,
} ;
struct V_177 V_338 = {
. V_113 = & V_162 -> V_113 ,
. V_179 = F_319 ( V_162 -> args . V_2 ) ,
. V_175 = & V_176 ,
. V_180 = & V_1028 ,
. V_182 = V_162 ,
} ;
struct V_112 * V_113 ;
int V_328 = 0 ;
F_8 ( L_93
L_94 , V_1012 ,
V_162 -> args . V_1029 ,
V_162 -> args . V_2 -> V_1030 ) ;
if ( ! V_1012 ) {
V_162 -> V_2 = F_462 ( V_162 -> args . V_2 ) ;
if ( V_162 -> V_2 == NULL ) {
F_624 ( V_162 ) ;
return - V_118 ;
}
V_338 . V_233 = V_342 ;
}
F_51 ( & V_162 -> args . V_164 , & V_162 -> V_66 . V_165 , 1 ) ;
V_113 = F_86 ( & V_338 ) ;
if ( F_78 ( V_113 ) )
return F_87 ( V_113 ) ;
if ( V_1012 )
V_328 = V_113 -> V_117 ;
F_627 ( V_162 -> args . V_2 , & V_162 -> args . V_50 , V_328 ) ;
F_8 ( L_95 , V_34 , V_328 ) ;
F_88 ( V_113 ) ;
return V_328 ;
}
static int
F_628 ( struct V_13 * V_14 , struct V_469 * V_470 ,
struct V_510 * V_511 ,
struct V_835 * V_526 , bool V_836 )
{
struct V_1031 args = {
. V_1032 = V_1033 ,
} ;
struct V_838 V_66 = {
. V_526 = V_526 ,
} ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_1034 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
} ;
struct V_64 * V_65 = V_14 -> V_108 ;
struct V_51 * V_52 = NULL ;
int V_328 ;
if ( V_836 ) {
V_65 = V_14 -> V_55 -> V_120 ;
V_52 = F_539 ( V_14 -> V_55 ) ;
V_176 . V_51 = V_52 ;
}
F_8 ( L_34 , V_34 ) ;
V_328 = F_89 ( V_65 , V_14 , & V_176 , & args . V_164 ,
& V_66 . V_165 , 0 ) ;
F_8 ( L_88 , V_34 , V_328 ) ;
if ( V_52 )
F_231 ( V_52 ) ;
return V_328 ;
}
static int
F_629 ( struct V_13 * V_14 , struct V_469 * V_470 ,
struct V_510 * V_511 , struct V_835 * V_526 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_44 ( V_14 -> V_55 ) )
V_8 = F_628 ( V_14 , V_470 , V_511 ,
V_526 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_628 ( V_14 , V_470 , V_511 ,
V_526 , false ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
case - V_1035 :
goto V_153;
default:
V_8 = F_36 ( V_14 , V_8 , & V_71 ) ;
}
} while ( V_71 . V_77 );
V_153:
return V_8 ;
}
static int
F_630 ( struct V_13 * V_14 , struct V_469 * V_470 ,
struct V_510 * V_511 )
{
int V_8 ;
struct V_533 * V_533 ;
T_5 V_119 = V_1036 ;
struct V_835 * V_526 ;
struct V_1037 * V_1038 ;
int V_476 ;
V_533 = F_300 ( V_418 ) ;
if ( ! V_533 ) {
V_8 = - V_171 ;
goto V_153;
}
V_526 = F_414 ( V_533 ) ;
V_8 = F_629 ( V_14 , V_470 , V_511 , V_526 ) ;
if ( V_8 == - V_22 || V_8 == - V_1035 ) {
V_8 = F_294 ( V_14 , V_470 , V_511 ) ;
goto V_1039;
}
if ( V_8 )
goto V_1039;
for ( V_476 = 0 ; V_476 < V_526 -> V_1040 ; V_476 ++ ) {
V_1038 = & V_526 -> V_526 [ V_476 ] ;
switch ( V_1038 -> V_119 ) {
case V_523 :
case V_522 :
case V_1041 :
V_119 = F_631 ( V_1038 -> V_119 ,
& V_1038 -> V_1042 ) ;
break;
default:
V_119 = V_1036 ;
break;
}
if ( ! F_632 ( & V_14 -> V_524 , V_119 ) )
V_119 = V_1036 ;
if ( V_119 != V_1036 ) {
V_8 = F_292 ( V_14 , V_470 ,
V_511 , V_119 ) ;
if ( ! V_8 )
break;
}
}
if ( V_119 == V_1036 )
V_8 = - V_24 ;
V_1039:
F_428 ( V_533 ) ;
if ( V_8 == - V_29 )
return - V_24 ;
V_153:
return V_8 ;
}
static int F_633 ( struct V_13 * V_14 ,
T_4 * V_50 ,
struct V_51 * V_52 )
{
int V_328 ;
struct V_1043 args = {
. V_50 = V_50 ,
} ;
struct V_1044 V_66 ;
struct V_175 V_176 = {
. V_333 = & V_334 [ V_1045 ] ,
. V_336 = & args ,
. V_337 = & V_66 ,
. V_51 = V_52 ,
} ;
struct V_64 * V_179 = V_14 -> V_108 ;
F_279 ( V_14 -> V_55 , V_895 ,
& V_179 , & V_176 ) ;
F_8 ( L_96 , V_50 ) ;
F_51 ( & args . V_164 , & V_66 . V_165 , 0 ) ;
F_52 ( & args . V_164 ) ;
V_328 = F_85 ( V_179 , V_14 , & V_176 ,
& args . V_164 , & V_66 . V_165 ) ;
if ( V_328 != V_388 ) {
F_8 ( L_97 , V_328 ) ;
return V_328 ;
}
F_8 ( L_98 , - V_66 . V_328 ) ;
return - V_66 . V_328 ;
}
static void F_634 ( struct V_13 * V_14 ,
int V_8 , struct V_70 * V_71 )
{
V_71 -> V_77 = 0 ;
switch( V_8 ) {
case - V_99 :
case - V_102 :
F_36 ( V_14 , V_8 , V_71 ) ;
break;
case - V_90 :
case - V_91 :
case - V_92 :
case - V_93 :
case - V_94 :
F_25 ( V_14 , V_8 , V_71 ) ;
}
}
static int F_226 ( struct V_13 * V_14 ,
T_4 * V_50 ,
struct V_51 * V_52 )
{
struct V_70 V_71 = { } ;
int V_8 ;
do {
V_8 = F_633 ( V_14 , V_50 , V_52 ) ;
F_634 ( V_14 , V_8 , & V_71 ) ;
} while ( V_71 . V_77 );
return V_8 ;
}
static void F_635 ( struct V_112 * V_113 , void * V_160 )
{
struct V_1046 * V_162 = V_160 ;
F_73 ( V_162 -> V_14 -> V_55 ,
& V_162 -> args . V_164 ,
& V_162 -> V_66 . V_165 ,
V_113 ) ;
}
static void F_636 ( struct V_112 * V_113 , void * V_160 )
{
struct V_1046 * V_162 = V_160 ;
F_68 ( V_113 , & V_162 -> V_66 . V_165 ) ;
switch ( V_113 -> V_117 ) {
case - V_99 :
if ( F_43 ( V_113 , V_162 -> V_14 , NULL , NULL ) == - V_118 )
F_66 ( V_113 ) ;
}
}
static void F_637 ( void * V_160 )
{
F_115 ( V_160 ) ;
}
static struct V_112 * F_638 ( struct V_13 * V_14 ,
const T_4 * V_50 ,
struct V_51 * V_52 ,
bool V_158 )
{
struct V_175 V_176 = {
. V_333 = & V_334 [ V_1047 ] ,
. V_51 = V_52 ,
} ;
struct V_177 V_178 = {
. V_179 = V_14 -> V_108 ,
. V_175 = & V_176 ,
. V_180 = & V_1048 ,
. V_233 = V_342 ,
} ;
struct V_1046 * V_162 ;
F_279 ( V_14 -> V_55 , V_895 ,
& V_178 . V_179 , & V_176 ) ;
F_8 ( L_99 , V_50 ) ;
V_162 = F_301 ( sizeof( * V_162 ) , V_325 ) ;
if ( ! V_162 )
return F_79 ( - V_171 ) ;
V_162 -> V_14 = V_14 ;
F_19 ( & V_162 -> args . V_50 , V_50 ) ;
V_178 . V_182 = V_162 ;
V_176 . V_336 = & V_162 -> args ;
V_176 . V_337 = & V_162 -> V_66 ;
F_51 ( & V_162 -> args . V_164 , & V_162 -> V_66 . V_165 , 1 ) ;
if ( V_158 )
F_52 ( & V_162 -> args . V_164 ) ;
return F_86 ( & V_178 ) ;
}
static int F_227 ( struct V_13 * V_14 ,
const T_4 * V_50 ,
struct V_51 * V_52 ,
bool V_1049 )
{
struct V_112 * V_113 ;
V_113 = F_638 ( V_14 , V_50 , V_52 , V_1049 ) ;
if ( F_78 ( V_113 ) )
return F_87 ( V_113 ) ;
F_88 ( V_113 ) ;
return 0 ;
}
static void
F_639 ( struct V_13 * V_14 , struct V_305 * V_306 )
{
struct V_51 * V_52 = V_306 -> V_307 -> V_246 -> V_304 ;
F_227 ( V_14 , & V_306 -> V_309 , V_52 , false ) ;
F_517 ( V_14 , V_306 ) ;
}
static bool F_640 ( const T_4 * V_1050 ,
const T_4 * V_1051 )
{
if ( V_1050 -> type != V_1051 -> type )
return false ;
if ( memcmp ( V_1050 -> V_1052 , V_1051 -> V_1052 , sizeof( V_1050 -> V_1052 ) ) != 0 )
return false ;
if ( V_1050 -> V_223 == V_1051 -> V_223 )
return true ;
return V_1050 -> V_223 == 0 || V_1051 -> V_223 == 0 ;
}
static bool F_641 ( const T_4 * V_1050 ,
const T_4 * V_1051 )
{
return F_155 ( V_1050 , V_1051 ) ;
}
static struct V_237 *
F_642 ( struct V_239 * V_1053 , T_7 V_1054 )
{
return NULL ;
}
static T_11 F_643 ( struct V_4 * V_4 , char * V_808 , T_9 V_1000 )
{
T_11 error , V_1055 ;
error = F_644 ( V_4 , V_808 , V_1000 ) ;
if ( error < 0 )
return error ;
if ( V_808 ) {
V_808 += error ;
V_1000 -= error ;
}
V_1055 = F_525 ( F_14 ( V_4 ) , V_808 , V_1000 ) ;
if ( V_1055 < 0 )
return V_1055 ;
return error + V_1055 ;
}
