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
unsigned int V_40 = V_41 | V_42 ;
T_3 * V_43 , * V_44 ;
if ( V_36 > 2 ) {
V_39 -> V_36 = V_36 ;
memcpy ( & V_39 -> V_37 , V_37 , sizeof( V_39 -> V_37 ) ) ;
return;
}
V_39 -> V_36 = 0 ;
memset ( & V_39 -> V_37 , 0 , sizeof( V_39 -> V_37 ) ) ;
if ( V_36 == 2 )
return;
V_43 = V_44 = F_10 ( * V_39 -> V_45 ) ;
if ( V_36 == 0 ) {
* V_44 ++ = V_46 ;
* V_44 ++ = V_47 ;
* V_44 ++ = V_46 ;
* V_44 ++ = V_46 ;
memcpy ( V_44 , L_2 , 4 ) ;
V_44 ++ ;
* V_44 ++ = V_46 ;
* V_44 ++ = F_11 ( V_40 ) ;
* V_44 ++ = F_11 ( 12 ) ;
* V_44 ++ = F_11 ( V_48 ) ;
V_44 = F_12 ( V_44 , F_13 ( F_14 ( V_4 ) ) ) ;
}
* V_44 ++ = V_46 ;
* V_44 ++ = V_47 ;
* V_44 ++ = V_49 ;
* V_44 ++ = V_49 ;
memcpy ( V_44 , L_3 , 4 ) ;
V_44 ++ ;
* V_44 ++ = V_46 ;
* V_44 ++ = F_11 ( V_40 ) ;
* V_44 ++ = F_11 ( 12 ) ;
* V_44 ++ = F_11 ( V_48 ) ;
V_44 = F_12 ( V_44 , F_13 ( F_14 ( V_4 -> V_50 ) ) ) ;
V_39 -> V_51 = ( char * ) V_44 - ( char * ) V_43 ;
V_39 -> V_52 -= V_39 -> V_51 ;
F_15 ( V_43 ) ;
}
static void F_16 ( struct V_13 * V_14 ,
T_4 * V_53 ,
struct V_54 * V_55 )
{
const struct V_56 * V_57 = V_14 -> V_58 -> V_59 ;
V_57 -> V_60 ( V_14 , V_53 , V_55 ) ;
}
static void F_17 ( struct V_13 * V_14 ,
T_4 * V_53 ,
struct V_54 * V_55 )
{
V_53 -> type = V_61 ;
F_16 ( V_14 , V_53 , V_55 ) ;
}
static void F_18 ( struct V_13 * V_14 ,
const T_4 * V_53 ,
struct V_54 * V_55 )
{
T_4 V_62 ;
F_19 ( & V_62 , V_53 ) ;
F_17 ( V_14 , & V_62 , V_55 ) ;
}
static long F_20 ( long * V_63 )
{
long V_64 ;
if ( ! V_63 )
return V_65 ;
if ( * V_63 <= 0 )
* V_63 = V_66 ;
if ( * V_63 > V_65 )
* V_63 = V_65 ;
V_64 = * V_63 ;
* V_63 <<= 1 ;
return V_64 ;
}
static int F_21 ( struct V_67 * V_68 , long * V_63 )
{
int V_69 = 0 ;
F_22 () ;
F_23 (
F_20 ( V_63 ) ) ;
if ( F_24 ( V_70 ) )
V_69 = - V_71 ;
return V_69 ;
}
static int F_25 ( struct V_13 * V_14 ,
int V_72 , struct V_73 * V_74 )
{
struct V_58 * V_75 = V_14 -> V_58 ;
struct V_76 * V_77 = V_74 -> V_77 ;
const T_4 * V_53 = V_74 -> V_53 ;
struct V_2 * V_2 = V_74 -> V_2 ;
int V_64 = V_72 ;
V_74 -> V_78 = 0 ;
V_74 -> V_79 = 0 ;
V_74 -> V_80 = 0 ;
if ( V_53 == NULL && V_77 != NULL )
V_53 = & V_77 -> V_53 ;
switch( V_72 ) {
case 0 :
return 0 ;
case - V_81 :
case - V_82 :
case - V_83 :
case - V_84 :
if ( V_2 != NULL && V_53 != NULL ) {
F_26 ( V_2 ,
V_53 ) ;
goto V_85;
}
case - V_86 :
if ( V_2 ) {
int V_8 ;
V_8 = F_27 ( V_2 ,
V_53 ) ;
if ( V_8 == 0 )
goto V_85;
if ( V_53 != NULL && V_53 -> type == V_87 ) {
V_74 -> V_80 = 1 ;
break;
}
}
if ( V_77 == NULL )
break;
V_64 = F_28 ( V_14 , V_77 ) ;
if ( V_64 < 0 )
break;
goto V_85;
case - V_88 :
case - V_89 :
F_29 ( V_75 ) ;
goto V_85;
case - V_90 :
V_64 = F_30 ( V_14 ) ;
if ( V_64 < 0 )
break;
goto V_85;
case - V_91 :
F_31 ( V_75 ) ;
goto V_85;
#if F_32 ( V_92 )
case - V_93 :
case - V_94 :
case - V_95 :
case - V_96 :
case - V_97 :
case - V_98 :
case - V_99 :
F_8 ( L_4 , V_34 ,
V_72 ) ;
F_33 ( V_75 -> V_100 , V_72 ) ;
goto V_85;
#endif
case - V_32 :
if ( V_74 -> V_63 > V_101 ) {
V_64 = - V_33 ;
break;
}
case - V_102 :
F_34 ( V_14 , V_103 ) ;
case - V_104 :
case - V_19 :
case - V_20 :
V_74 -> V_78 = 1 ;
return 0 ;
case - V_105 :
case - V_106 :
V_74 -> V_80 = 1 ;
break;
case - V_25 :
case - V_26 :
if ( V_14 -> V_107 & V_108 ) {
V_14 -> V_107 &= ~ V_108 ;
V_74 -> V_80 = 1 ;
F_35 ( V_109 L_5
L_6
L_7
L_8 ,
V_14 -> V_58 -> V_110 ) ;
}
}
return F_7 ( V_64 ) ;
V_85:
V_74 -> V_79 = 1 ;
return 0 ;
}
int F_36 ( struct V_13 * V_14 , int V_72 , struct V_73 * V_74 )
{
struct V_58 * V_75 = V_14 -> V_58 ;
int V_64 ;
V_64 = F_25 ( V_14 , V_72 , V_74 ) ;
if ( V_74 -> V_78 ) {
V_64 = F_21 ( V_14 -> V_111 , & V_74 -> V_63 ) ;
goto V_112;
}
if ( V_74 -> V_79 ) {
V_64 = F_37 ( V_75 ) ;
if ( F_38 ( V_113 , & V_14 -> V_114 ) )
return - V_35 ;
goto V_112;
}
return V_64 ;
V_112:
if ( V_64 == 0 )
V_74 -> V_80 = 1 ;
return V_64 ;
}
static int
F_39 ( struct V_115 * V_116 , struct V_13 * V_14 ,
int V_72 , struct V_73 * V_74 )
{
struct V_58 * V_75 = V_14 -> V_58 ;
int V_64 ;
V_64 = F_25 ( V_14 , V_72 , V_74 ) ;
if ( V_74 -> V_78 ) {
F_40 ( V_116 , F_20 ( & V_74 -> V_63 ) ) ;
goto V_112;
}
if ( V_74 -> V_79 ) {
F_41 ( & V_75 -> V_117 , V_116 , NULL ) ;
if ( F_38 ( V_118 , & V_75 -> V_119 ) == 0 )
F_42 ( & V_75 -> V_117 , V_116 ) ;
goto V_112;
}
if ( F_38 ( V_113 , & V_14 -> V_114 ) )
V_64 = - V_35 ;
return V_64 ;
V_112:
if ( V_64 == 0 )
V_74 -> V_80 = 1 ;
return V_64 ;
}
static int
F_43 ( struct V_115 * V_116 , struct V_13 * V_14 ,
struct V_76 * V_77 , long * V_63 )
{
struct V_73 V_74 = {
. V_77 = V_77 ,
} ;
if ( V_116 -> V_120 >= 0 )
return 0 ;
if ( V_63 )
V_74 . V_63 = * V_63 ;
V_116 -> V_120 = F_39 ( V_116 , V_14 ,
V_116 -> V_120 ,
& V_74 ) ;
if ( V_74 . V_78 && V_63 )
* V_63 = V_74 . V_63 ;
if ( V_74 . V_80 )
return - V_121 ;
return 0 ;
}
static bool F_44 ( struct V_58 * V_75 )
{
T_5 V_122 = V_75 -> V_123 -> V_124 -> V_125 ;
return ( V_122 == V_126 ) || ( V_122 == V_127 ) ;
}
static void F_45 ( struct V_58 * V_75 , unsigned long V_128 )
{
F_46 ( & V_75 -> V_129 ) ;
if ( F_47 ( V_75 -> V_130 , V_128 ) )
V_75 -> V_130 = V_128 ;
F_48 ( & V_75 -> V_129 ) ;
}
static void F_49 ( const struct V_13 * V_14 , unsigned long V_128 )
{
struct V_58 * V_75 = V_14 -> V_58 ;
if ( ! F_50 ( V_75 ) )
F_45 ( V_75 , V_128 ) ;
}
void F_51 ( struct V_131 * args ,
struct V_132 * V_69 , int V_133 )
{
args -> V_134 = NULL ;
args -> V_135 = V_133 ;
args -> V_136 = 0 ;
V_69 -> V_137 = NULL ;
}
static void F_52 ( struct V_131 * args )
{
args -> V_136 = 1 ;
}
static void F_53 ( struct V_132 * V_69 )
{
struct V_138 * V_139 = V_69 -> V_137 ;
struct V_140 * V_141 ;
V_141 = V_139 -> V_142 ;
F_46 ( & V_141 -> V_143 ) ;
if ( ! F_54 ( V_141 , V_139 ) )
F_55 ( V_141 , V_139 ) ;
F_48 ( & V_141 -> V_143 ) ;
V_69 -> V_137 = NULL ;
}
static int F_56 ( struct V_115 * V_116 ,
struct V_132 * V_69 )
{
if ( V_69 -> V_137 != NULL )
F_53 ( V_69 ) ;
return 1 ;
}
static void F_57 ( struct V_132 * V_69 )
{
struct V_144 * V_145 ;
struct V_140 * V_141 ;
struct V_138 * V_139 = V_69 -> V_137 ;
bool V_146 = false ;
V_141 = V_139 -> V_142 ;
V_145 = V_141 -> V_145 ;
if ( V_139 -> V_147 )
V_139 -> V_148 ++ ;
V_139 -> V_147 = 0 ;
F_46 ( & V_141 -> V_143 ) ;
if ( V_141 -> V_149 > V_141 -> V_150 )
V_146 = true ;
if ( F_54 ( V_141 , V_139 ) ) {
V_146 = false ;
goto V_151;
}
F_55 ( V_141 , V_139 ) ;
if ( V_141 -> V_149 != V_152 )
V_146 = false ;
V_151:
F_48 ( & V_141 -> V_143 ) ;
V_69 -> V_137 = NULL ;
if ( V_146 )
F_58 ( V_145 -> V_75 ) ;
if ( F_59 ( & V_141 -> V_153 ) )
F_60 ( & V_141 -> V_153 ) ;
}
static int F_61 ( struct V_115 * V_116 ,
struct V_132 * V_69 )
{
struct V_144 * V_145 ;
struct V_138 * V_139 = V_69 -> V_137 ;
struct V_58 * V_75 ;
bool V_154 = false ;
int V_64 = 1 ;
if ( V_139 == NULL )
goto V_155;
if ( ! F_62 ( V_116 ) )
goto V_156;
V_145 = V_139 -> V_142 -> V_145 ;
if ( V_139 -> V_154 ) {
if ( V_69 -> V_157 != - V_102 )
V_139 -> V_154 = 0 ;
V_154 = true ;
}
F_63 ( V_145 , V_69 ) ;
switch ( V_69 -> V_157 ) {
case 0 :
if ( V_116 -> V_120 == - V_21 && V_154 ) {
++ V_139 -> V_148 ;
goto V_158;
}
V_139 -> V_147 = 1 ;
V_75 = V_145 -> V_75 ;
F_45 ( V_75 , V_69 -> V_159 ) ;
F_64 ( V_75 , V_69 -> V_160 ,
! ! V_139 -> V_161 ) ;
F_65 ( V_139 -> V_142 , V_139 , V_69 ) ;
break;
case 1 :
V_139 -> V_154 = 1 ;
goto V_156;
case - V_102 :
F_8 ( L_9 ,
V_34 ,
V_139 -> V_162 ,
V_139 -> V_148 ) ;
goto V_112;
case - V_94 :
goto V_158;
case - V_99 :
if ( V_154 ) {
++ V_139 -> V_148 ;
goto V_158;
}
if ( V_139 -> V_148 != 1 ) {
V_139 -> V_148 = 1 ;
goto V_158;
}
break;
case - V_98 :
++ V_139 -> V_148 ;
goto V_158;
default:
V_139 -> V_147 = 1 ;
}
V_156:
F_8 ( L_10 , V_34 , V_69 -> V_157 ) ;
V_155:
return V_64 ;
V_158:
if ( F_66 ( V_116 ) ) {
F_57 ( V_69 ) ;
V_116 -> V_120 = 0 ;
V_64 = 0 ;
}
goto V_156;
V_112:
if ( ! F_67 ( V_116 ) )
goto V_156;
F_40 ( V_116 , V_65 ) ;
return 0 ;
}
int F_68 ( struct V_115 * V_116 , struct V_132 * V_69 )
{
if ( ! F_61 ( V_116 , V_69 ) )
return 0 ;
if ( V_69 -> V_137 != NULL )
F_57 ( V_69 ) ;
return 1 ;
}
static int F_69 ( struct V_115 * V_116 , struct V_132 * V_69 )
{
if ( V_69 -> V_137 == NULL )
return 1 ;
if ( V_69 -> V_137 -> V_142 -> V_145 != NULL )
return F_61 ( V_116 , V_69 ) ;
return F_56 ( V_116 , V_69 ) ;
}
static void F_70 ( struct V_132 * V_69 )
{
if ( V_69 -> V_137 != NULL ) {
if ( V_69 -> V_137 -> V_142 -> V_145 != NULL )
F_57 ( V_69 ) ;
else
F_53 ( V_69 ) ;
}
}
int F_71 ( struct V_115 * V_116 , struct V_132 * V_69 )
{
if ( V_69 -> V_137 == NULL )
return 1 ;
if ( ! V_69 -> V_137 -> V_142 -> V_145 )
return F_56 ( V_116 , V_69 ) ;
return F_68 ( V_116 , V_69 ) ;
}
static void F_72 ( struct V_115 * V_116 , void * V_163 )
{
struct V_164 * V_165 = V_163 ;
F_8 ( L_11 , V_34 , V_165 -> V_166 ) ;
F_73 ( V_165 -> V_166 -> V_58 ,
V_165 -> V_167 , V_165 -> V_168 , V_116 ) ;
}
static void F_74 ( struct V_115 * V_116 , void * V_163 )
{
struct V_164 * V_165 = V_163 ;
F_68 ( V_116 , V_165 -> V_168 ) ;
}
static int F_69 ( struct V_115 * V_116 , struct V_132 * V_69 )
{
return F_56 ( V_116 , V_69 ) ;
}
static void F_70 ( struct V_132 * V_69 )
{
if ( V_69 -> V_137 != NULL )
F_53 ( V_69 ) ;
}
int F_71 ( struct V_115 * V_116 ,
struct V_132 * V_69 )
{
return F_56 ( V_116 , V_69 ) ;
}
int F_73 ( const struct V_58 * V_111 ,
struct V_131 * args ,
struct V_132 * V_69 ,
struct V_115 * V_116 )
{
struct V_144 * V_145 = F_75 ( V_111 ) ;
struct V_140 * V_141 = V_111 -> V_169 ;
struct V_138 * V_139 ;
if ( V_69 -> V_137 != NULL )
goto V_170;
if ( V_145 ) {
V_141 = & V_145 -> V_171 ;
V_116 -> V_172 = 0 ;
}
F_46 ( & V_141 -> V_143 ) ;
if ( F_76 ( V_141 ) && ! args -> V_136 )
goto V_173;
V_139 = F_77 ( V_141 ) ;
if ( F_78 ( V_139 ) ) {
if ( V_139 == F_79 ( - V_174 ) )
V_116 -> V_172 = V_101 >> 2 ;
goto V_173;
}
F_48 ( & V_141 -> V_143 ) ;
V_139 -> V_161 = args -> V_136 ? 1 : 0 ;
args -> V_134 = V_139 ;
V_69 -> V_137 = V_139 ;
if ( V_145 ) {
V_69 -> V_159 = V_175 ;
V_69 -> V_160 = 0 ;
V_69 -> V_157 = 1 ;
}
F_80 ( V_145 , args ) ;
V_170:
F_81 ( V_116 ) ;
return 0 ;
V_173:
if ( args -> V_136 )
F_82 ( & V_141 -> V_176 , V_116 ,
NULL , V_177 ) ;
else
F_41 ( & V_141 -> V_176 , V_116 , NULL ) ;
F_48 ( & V_141 -> V_143 ) ;
return - V_121 ;
}
static void F_83 ( struct V_115 * V_116 , void * V_163 )
{
struct V_164 * V_165 = V_163 ;
F_73 ( V_165 -> V_166 -> V_58 ,
V_165 -> V_167 , V_165 -> V_168 , V_116 ) ;
}
static void F_84 ( struct V_115 * V_116 , void * V_163 )
{
struct V_164 * V_165 = V_163 ;
F_71 ( V_116 , V_165 -> V_168 ) ;
}
static int F_85 ( struct V_67 * V_68 ,
struct V_13 * V_14 ,
struct V_178 * V_179 ,
struct V_131 * args ,
struct V_132 * V_69 )
{
int V_64 ;
struct V_115 * V_116 ;
struct V_58 * V_75 = V_14 -> V_58 ;
struct V_164 V_165 = {
. V_166 = V_14 ,
. V_167 = args ,
. V_168 = V_69 ,
} ;
struct V_180 V_181 = {
. V_182 = V_68 ,
. V_178 = V_179 ,
. V_183 = V_75 -> V_59 -> V_184 ,
. V_185 = & V_165
} ;
V_116 = F_86 ( & V_181 ) ;
if ( F_78 ( V_116 ) )
V_64 = F_87 ( V_116 ) ;
else {
V_64 = V_116 -> V_120 ;
F_88 ( V_116 ) ;
}
return V_64 ;
}
int F_89 ( struct V_67 * V_68 ,
struct V_13 * V_14 ,
struct V_178 * V_179 ,
struct V_131 * args ,
struct V_132 * V_69 ,
int V_133 )
{
F_51 ( args , V_69 , V_133 ) ;
return F_85 ( V_68 , V_14 , V_179 , args , V_69 ) ;
}
static void F_90 ( struct V_2 * V_3 , struct V_186 * V_187 ,
unsigned long V_128 )
{
struct V_188 * V_189 = F_91 ( V_3 ) ;
F_46 ( & V_3 -> V_190 ) ;
V_189 -> V_191 |= V_192 | V_193 ;
if ( V_187 -> V_194 && V_187 -> V_195 == V_3 -> V_196 ) {
V_189 -> V_191 &= ~ V_197 ;
V_189 -> V_198 = V_175 ;
} else {
F_92 ( V_3 ) ;
if ( V_187 -> V_195 != V_3 -> V_196 )
V_189 -> V_191 |= V_199 |
V_200 ;
}
V_3 -> V_196 = V_187 -> V_201 ;
V_189 -> V_202 = V_128 ;
V_189 -> V_203 = F_93 () ;
F_94 ( V_3 ) ;
F_48 ( & V_3 -> V_190 ) ;
}
static bool F_95 ( struct V_13 * V_14 ,
int V_8 , struct V_73 * V_74 )
{
if ( V_8 != - V_27 )
return false ;
if ( ! ( V_14 -> V_107 & V_204 ) )
return false ;
V_14 -> V_107 &= ~ V_204 ;
V_74 -> V_80 = 1 ;
return true ;
}
static T_1
F_96 ( struct V_13 * V_14 ,
T_6 V_205 , int V_206 )
{
T_1 V_69 = 0 ;
switch ( V_205 & ( V_207 | V_208 ) ) {
case V_207 :
V_69 = V_209 ;
break;
case V_208 :
V_69 = V_210 ;
break;
case V_207 | V_208 :
V_69 = V_211 ;
}
if ( ! ( V_14 -> V_107 & V_204 ) )
goto V_156;
if ( V_206 & V_212 )
V_69 |= V_213 ;
V_156:
return V_69 ;
}
static enum V_214
F_97 ( struct V_13 * V_14 ,
enum V_214 V_215 )
{
if ( V_14 -> V_107 & V_204 )
return V_215 ;
switch ( V_215 ) {
default:
return V_215 ;
case V_216 :
return V_217 ;
case V_218 :
return V_219 ;
case V_220 :
return V_221 ;
}
}
static void F_98 ( struct V_222 * V_44 )
{
V_44 -> V_223 . V_224 = & V_44 -> V_224 ;
V_44 -> V_223 . V_225 = V_44 -> V_225 ;
V_44 -> V_223 . V_226 = V_44 -> V_227 . V_226 ;
V_44 -> V_228 . V_226 = V_44 -> V_229 . V_226 ;
V_44 -> V_223 . V_14 = V_44 -> V_227 . V_14 ;
V_44 -> V_223 . V_230 = V_44 -> V_227 . V_231 ;
F_99 ( & V_44 -> V_224 ) ;
F_100 ( & V_44 -> V_224 , & V_44 -> V_232 , & V_44 -> V_233 ) ;
}
static struct V_222 * F_101 ( struct V_4 * V_4 ,
struct V_234 * V_235 , T_6 V_205 , int V_236 ,
const struct V_5 * V_40 ,
struct V_1 * V_7 ,
enum V_214 V_215 ,
T_7 V_237 )
{
struct V_4 * V_238 = F_102 ( V_4 ) ;
struct V_2 * V_3 = F_14 ( V_238 ) ;
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_239 * ( * V_240 ) ( struct V_241 * , T_7 ) ;
struct V_222 * V_44 ;
V_44 = F_104 ( sizeof( * V_44 ) , V_237 ) ;
if ( V_44 == NULL )
goto V_8;
V_44 -> V_225 = F_105 ( V_14 , V_237 ) ;
if ( F_78 ( V_44 -> V_225 ) )
goto V_242;
V_44 -> V_243 = F_105 ( V_14 , V_237 ) ;
if ( F_78 ( V_44 -> V_243 ) )
goto V_244;
V_240 = V_14 -> V_58 -> V_59 -> V_240 ;
V_44 -> V_227 . V_226 = V_240 ( & V_235 -> V_245 , V_237 ) ;
if ( F_78 ( V_44 -> V_227 . V_226 ) )
goto V_246;
F_106 ( V_4 -> V_247 ) ;
V_44 -> V_4 = F_107 ( V_4 ) ;
V_44 -> V_3 = V_238 ;
V_44 -> V_248 = V_235 ;
F_108 ( & V_235 -> V_249 ) ;
V_44 -> V_227 . V_250 = V_236 ;
V_44 -> V_227 . V_205 = V_205 & ( V_207 | V_208 ) ;
V_44 -> V_227 . V_251 = F_109 () ;
V_44 -> V_227 . V_215 = F_97 ( V_14 , V_215 ) ;
V_44 -> V_227 . V_252 = F_96 ( V_14 ,
V_205 , V_236 ) ;
if ( ! ( V_236 & V_253 ) ) {
switch ( V_44 -> V_227 . V_215 ) {
default:
break;
case V_217 :
case V_216 :
V_44 -> V_227 . V_231 = V_254 |
V_255 |
V_256 |
V_257 ;
}
}
V_44 -> V_227 . V_258 = V_14 -> V_58 -> V_259 ;
V_44 -> V_227 . V_260 . V_261 = F_110 ( V_235 -> V_245 . V_261 ) ;
V_44 -> V_227 . V_260 . V_262 = V_235 -> V_245 . V_263 ;
V_44 -> V_227 . V_264 = & V_4 -> V_11 ;
V_44 -> V_227 . V_14 = V_14 ;
V_44 -> V_227 . V_265 = F_6 ( V_14 , V_7 ) ;
V_44 -> V_227 . V_266 = & V_267 [ 0 ] ;
V_44 -> V_227 . V_7 = F_111 ( V_44 -> V_243 , V_7 ) ;
switch ( V_44 -> V_227 . V_215 ) {
case V_217 :
case V_219 :
case V_221 :
V_44 -> V_227 . V_268 = F_112 ( V_3 ) ;
break;
case V_269 :
case V_216 :
case V_218 :
case V_220 :
V_44 -> V_227 . V_268 = F_112 ( F_14 ( V_4 ) ) ;
}
if ( V_40 != NULL && V_40 -> V_270 != 0 ) {
T_8 V_271 [ 2 ] ;
V_44 -> V_227 . V_272 . V_40 = & V_44 -> V_40 ;
memcpy ( & V_44 -> V_40 , V_40 , sizeof( V_44 -> V_40 ) ) ;
V_271 [ 0 ] = V_175 ;
V_271 [ 1 ] = V_70 -> V_273 ;
memcpy ( V_44 -> V_227 . V_272 . V_37 . V_165 , V_271 ,
sizeof( V_44 -> V_227 . V_272 . V_37 . V_165 ) ) ;
}
V_44 -> V_229 . V_268 = & V_44 -> V_223 . V_268 ;
V_44 -> V_229 . V_53 = & V_44 -> V_223 . V_53 ;
V_44 -> V_229 . V_226 = V_44 -> V_227 . V_226 ;
F_98 ( V_44 ) ;
F_113 ( & V_44 -> V_274 ) ;
return V_44 ;
V_246:
F_114 ( V_44 -> V_243 ) ;
V_244:
F_114 ( V_44 -> V_225 ) ;
V_242:
F_115 ( V_44 ) ;
V_8:
F_116 ( V_238 ) ;
return NULL ;
}
static void F_117 ( struct V_274 * V_274 )
{
struct V_222 * V_44 = F_118 ( V_274 ,
struct V_222 , V_274 ) ;
struct V_275 * V_276 = V_44 -> V_4 -> V_247 ;
F_119 ( V_44 -> V_227 . V_226 ) ;
F_70 ( & V_44 -> V_223 . V_168 ) ;
if ( V_44 -> V_77 != NULL )
F_120 ( V_44 -> V_77 ) ;
F_121 ( V_44 -> V_248 ) ;
F_114 ( V_44 -> V_243 ) ;
F_114 ( V_44 -> V_225 ) ;
F_116 ( V_44 -> V_3 ) ;
F_116 ( V_44 -> V_4 ) ;
F_122 ( V_276 ) ;
F_123 ( & V_44 -> V_224 ) ;
F_115 ( V_44 -> V_224 . V_277 ) ;
F_115 ( V_44 ) ;
}
static void F_124 ( struct V_222 * V_44 )
{
if ( V_44 != NULL )
F_125 ( & V_44 -> V_274 , F_117 ) ;
}
static bool F_126 ( struct V_76 * V_77 ,
T_6 V_205 )
{
switch( V_205 & ( V_207 | V_208 ) ) {
case V_207 | V_208 :
return V_77 -> V_278 != 0 ;
case V_208 :
return V_77 -> V_279 != 0 ;
case V_207 :
return V_77 -> V_280 != 0 ;
}
F_127 ( 1 ) ;
return false ;
}
static int F_128 ( struct V_76 * V_77 , T_6 V_281 , int V_282 )
{
int V_64 = 0 ;
if ( V_282 & ( V_253 | V_283 ) )
goto V_156;
switch ( V_281 & ( V_207 | V_208 ) ) {
case V_207 :
V_64 |= F_38 ( V_284 , & V_77 -> V_236 ) != 0
&& V_77 -> V_280 != 0 ;
break;
case V_208 :
V_64 |= F_38 ( V_285 , & V_77 -> V_236 ) != 0
&& V_77 -> V_279 != 0 ;
break;
case V_207 | V_208 :
V_64 |= F_38 ( V_286 , & V_77 -> V_236 ) != 0
&& V_77 -> V_278 != 0 ;
}
V_156:
return V_64 ;
}
static int F_129 ( struct V_287 * V_288 , T_6 V_205 ,
enum V_214 V_215 )
{
if ( V_288 == NULL )
return 0 ;
if ( ( V_288 -> type & V_205 ) != V_205 )
return 0 ;
if ( F_38 ( V_289 , & V_288 -> V_236 ) )
return 0 ;
switch ( V_215 ) {
case V_217 :
case V_216 :
break;
case V_269 :
if ( ! F_38 ( V_290 , & V_288 -> V_236 ) )
break;
default:
return 0 ;
}
F_130 ( V_288 ) ;
return 1 ;
}
static void F_131 ( struct V_76 * V_77 , T_6 V_205 )
{
switch ( V_205 ) {
case V_208 :
V_77 -> V_279 ++ ;
break;
case V_207 :
V_77 -> V_280 ++ ;
break;
case V_207 | V_208 :
V_77 -> V_278 ++ ;
}
F_132 ( V_77 , V_77 -> V_77 | V_205 ) ;
}
static bool F_133 ( struct V_76 * V_77 )
{
if ( V_77 -> V_280 && ! F_38 ( V_284 , & V_77 -> V_236 ) )
return true ;
if ( V_77 -> V_279 && ! F_38 ( V_285 , & V_77 -> V_236 ) )
return true ;
if ( V_77 -> V_278 && ! F_38 ( V_286 , & V_77 -> V_236 ) )
return true ;
return false ;
}
static void F_134 ( struct V_76 * V_77 )
{
struct V_58 * V_75 = V_77 -> V_248 -> V_291 -> V_58 ;
bool V_292 = false ;
if ( F_135 ( V_284 , & V_77 -> V_236 ) && V_77 -> V_280 )
V_292 = true ;
if ( F_135 ( V_285 , & V_77 -> V_236 ) && V_77 -> V_279 )
V_292 = true ;
if ( F_135 ( V_286 , & V_77 -> V_236 ) && V_77 -> V_278 )
V_292 = true ;
if ( V_292 )
F_136 ( V_75 , V_77 ) ;
}
static bool F_137 ( struct V_76 * V_77 ,
const T_4 * V_53 , T_4 * V_293 )
{
if ( F_138 ( V_294 , & V_77 -> V_236 ) == 0 )
return true ;
if ( ! F_139 ( V_53 , & V_77 -> V_295 ) ) {
F_19 ( V_293 , & V_77 -> V_295 ) ;
F_134 ( V_77 ) ;
return true ;
}
if ( F_140 ( V_53 , & V_77 -> V_295 ) )
return true ;
return false ;
}
static void F_141 ( struct V_76 * V_77 )
{
if ( ! ( V_77 -> V_279 || V_77 -> V_280 || V_77 -> V_278 ) )
return;
if ( V_77 -> V_279 )
F_142 ( V_285 , & V_77 -> V_236 ) ;
if ( V_77 -> V_280 )
F_142 ( V_284 , & V_77 -> V_236 ) ;
if ( V_77 -> V_278 )
F_142 ( V_286 , & V_77 -> V_236 ) ;
F_142 ( V_294 , & V_77 -> V_236 ) ;
}
static void F_143 ( struct V_76 * V_77 ,
T_4 * V_53 , T_6 V_205 )
{
F_144 ( V_286 , & V_77 -> V_236 ) ;
switch ( V_205 & ( V_207 | V_208 ) ) {
case V_208 :
F_144 ( V_284 , & V_77 -> V_236 ) ;
break;
case V_207 :
F_144 ( V_285 , & V_77 -> V_236 ) ;
break;
case 0 :
F_144 ( V_284 , & V_77 -> V_236 ) ;
F_144 ( V_285 , & V_77 -> V_236 ) ;
F_144 ( V_294 , & V_77 -> V_236 ) ;
}
if ( V_53 == NULL )
return;
if ( F_139 ( V_53 , & V_77 -> V_295 ) &&
! F_140 ( V_53 , & V_77 -> V_295 ) ) {
F_141 ( V_77 ) ;
return;
}
if ( F_38 ( V_296 , & V_77 -> V_236 ) == 0 )
F_19 ( & V_77 -> V_53 , V_53 ) ;
F_19 ( & V_77 -> V_295 , V_53 ) ;
}
static void F_145 ( struct V_76 * V_77 ,
T_4 * V_297 ,
T_4 * V_53 , T_6 V_205 )
{
F_146 ( & V_77 -> V_298 ) ;
if ( F_147 ( V_77 , V_297 ) )
F_143 ( V_77 , V_53 , V_205 ) ;
F_148 ( & V_77 -> V_298 ) ;
if ( F_38 ( V_299 , & V_77 -> V_236 ) )
F_149 ( V_77 -> V_248 -> V_291 -> V_58 ) ;
}
static void F_150 ( struct V_76 * V_77 ,
const T_4 * V_53 , T_6 V_205 ,
T_4 * V_293 )
{
switch ( V_205 ) {
case V_207 :
F_142 ( V_284 , & V_77 -> V_236 ) ;
break;
case V_208 :
F_142 ( V_285 , & V_77 -> V_236 ) ;
break;
case V_207 | V_208 :
F_142 ( V_286 , & V_77 -> V_236 ) ;
}
if ( ! F_137 ( V_77 , V_53 , V_293 ) )
return;
if ( F_38 ( V_296 , & V_77 -> V_236 ) == 0 )
F_19 ( & V_77 -> V_53 , V_53 ) ;
F_19 ( & V_77 -> V_295 , V_53 ) ;
}
static void F_151 ( struct V_76 * V_77 ,
const T_4 * V_295 ,
const T_4 * V_300 ,
T_6 V_205 ,
T_4 * V_293 )
{
F_46 ( & V_77 -> V_248 -> V_301 ) ;
F_146 ( & V_77 -> V_298 ) ;
if ( V_300 != NULL ) {
F_19 ( & V_77 -> V_53 , V_300 ) ;
F_142 ( V_296 , & V_77 -> V_236 ) ;
}
if ( V_295 != NULL )
F_150 ( V_77 , V_295 , V_205 , V_293 ) ;
F_148 ( & V_77 -> V_298 ) ;
F_131 ( V_77 , V_205 ) ;
F_48 ( & V_77 -> V_248 -> V_301 ) ;
}
static int F_152 ( struct V_76 * V_77 ,
const T_4 * V_295 ,
const T_4 * V_288 ,
T_6 V_205 )
{
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
struct V_58 * V_75 = V_14 -> V_58 ;
struct V_188 * V_189 = F_91 ( V_77 -> V_2 ) ;
struct V_287 * V_302 ;
T_4 V_293 = { } ;
int V_64 = 0 ;
V_205 &= ( V_207 | V_208 ) ;
F_153 () ;
V_302 = F_154 ( V_189 -> V_288 ) ;
if ( V_302 == NULL )
goto V_303;
F_46 ( & V_302 -> V_304 ) ;
if ( F_154 ( V_189 -> V_288 ) != V_302 ||
F_38 ( V_289 , & V_302 -> V_236 ) ||
( V_302 -> type & V_205 ) != V_205 )
goto V_305;
if ( V_288 == NULL )
V_288 = & V_302 -> V_53 ;
else if ( ! F_155 ( & V_302 -> V_53 , V_288 ) )
goto V_305;
F_130 ( V_302 ) ;
F_151 ( V_77 , V_295 , & V_302 -> V_53 ,
V_205 , & V_293 ) ;
V_64 = 1 ;
V_305:
F_48 ( & V_302 -> V_304 ) ;
V_303:
F_156 () ;
if ( ! V_64 && V_295 != NULL ) {
F_151 ( V_77 , V_295 , NULL , V_205 , & V_293 ) ;
V_64 = 1 ;
}
if ( F_38 ( V_299 , & V_77 -> V_236 ) )
F_149 ( V_75 ) ;
if ( V_293 . type != 0 )
F_16 ( V_14 , & V_293 ,
V_77 -> V_248 -> V_306 ) ;
return V_64 ;
}
static bool F_157 ( struct V_307 * V_308 ,
const T_4 * V_53 )
{
struct V_76 * V_77 = V_308 -> V_309 ;
bool V_64 = false ;
F_46 ( & V_77 -> V_310 ) ;
if ( ! F_139 ( V_53 , & V_308 -> V_311 ) )
goto V_312;
if ( ! F_140 ( V_53 , & V_308 -> V_311 ) )
goto V_312;
F_19 ( & V_308 -> V_311 , V_53 ) ;
V_64 = true ;
V_312:
F_48 ( & V_77 -> V_310 ) ;
return V_64 ;
}
static void F_158 ( struct V_2 * V_2 , T_6 V_205 )
{
struct V_287 * V_288 ;
F_153 () ;
V_288 = F_154 ( F_91 ( V_2 ) -> V_288 ) ;
if ( V_288 == NULL || ( V_288 -> type & V_205 ) == V_205 ) {
F_156 () ;
return;
}
F_156 () ;
F_159 ( V_2 ) ;
}
static struct V_76 * F_160 ( struct V_222 * V_313 )
{
struct V_76 * V_77 = V_313 -> V_77 ;
struct V_188 * V_189 = F_91 ( V_77 -> V_2 ) ;
struct V_287 * V_288 ;
int V_282 = V_313 -> V_227 . V_250 ;
T_6 V_205 = V_313 -> V_227 . V_205 ;
enum V_214 V_215 = V_313 -> V_227 . V_215 ;
T_4 V_53 ;
int V_64 = - V_121 ;
for (; ; ) {
F_46 ( & V_77 -> V_248 -> V_301 ) ;
if ( F_128 ( V_77 , V_205 , V_282 ) ) {
F_131 ( V_77 , V_205 ) ;
F_48 ( & V_77 -> V_248 -> V_301 ) ;
goto V_314;
}
F_48 ( & V_77 -> V_248 -> V_301 ) ;
F_153 () ;
V_288 = F_154 ( V_189 -> V_288 ) ;
if ( ! F_129 ( V_288 , V_205 , V_215 ) ) {
F_156 () ;
break;
}
F_19 ( & V_53 , & V_288 -> V_53 ) ;
F_156 () ;
F_161 ( V_313 -> V_227 . V_226 ) ;
if ( ! V_313 -> V_315 ) {
V_64 = F_162 ( V_77 -> V_2 , V_77 -> V_248 -> V_306 , V_282 ) ;
if ( V_64 != 0 )
goto V_156;
}
V_64 = - V_121 ;
if ( F_152 ( V_77 , NULL , & V_53 , V_205 ) )
goto V_314;
}
V_156:
return F_79 ( V_64 ) ;
V_314:
F_108 ( & V_77 -> V_52 ) ;
return V_77 ;
}
static void
F_163 ( struct V_222 * V_165 , struct V_76 * V_77 )
{
struct V_58 * V_75 = F_103 ( V_77 -> V_2 ) -> V_58 ;
struct V_287 * V_288 ;
int V_316 = 0 ;
F_153 () ;
V_288 = F_154 ( F_91 ( V_77 -> V_2 ) -> V_288 ) ;
if ( V_288 )
V_316 = V_288 -> V_236 ;
F_156 () ;
switch ( V_165 -> V_227 . V_215 ) {
default:
break;
case V_219 :
case V_218 :
F_164 ( L_12
L_13
L_14 ,
V_75 -> V_110 ) ;
return;
}
if ( ( V_316 & 1UL << V_290 ) == 0 )
F_165 ( V_77 -> V_2 ,
V_165 -> V_248 -> V_306 ,
& V_165 -> V_223 ) ;
else
F_166 ( V_77 -> V_2 ,
V_165 -> V_248 -> V_306 ,
& V_165 -> V_223 ) ;
}
static struct V_76 *
F_167 ( struct V_222 * V_165 )
{
struct V_2 * V_2 = V_165 -> V_77 -> V_2 ;
struct V_76 * V_77 = V_165 -> V_77 ;
int V_64 ;
if ( ! V_165 -> V_317 ) {
if ( V_165 -> V_318 )
return F_79 ( V_165 -> V_318 ) ;
goto V_319;
}
V_64 = F_168 ( V_2 , & V_165 -> V_224 ) ;
if ( V_64 )
return F_79 ( V_64 ) ;
if ( V_165 -> V_223 . V_320 != 0 )
F_163 ( V_165 , V_77 ) ;
V_319:
F_152 ( V_77 , & V_165 -> V_223 . V_53 , NULL ,
V_165 -> V_227 . V_205 ) ;
F_108 ( & V_77 -> V_52 ) ;
return V_77 ;
}
static struct V_76 *
F_169 ( struct V_222 * V_165 )
{
struct V_2 * V_2 ;
struct V_76 * V_77 = NULL ;
int V_64 ;
if ( ! V_165 -> V_317 ) {
V_77 = F_160 ( V_165 ) ;
F_170 ( V_165 -> V_77 ) ;
goto V_156;
}
V_64 = - V_121 ;
if ( ! ( V_165 -> V_224 . V_321 & V_322 ) )
goto V_8;
V_2 = F_171 ( V_165 -> V_3 -> V_247 , & V_165 -> V_223 . V_268 , & V_165 -> V_224 , V_165 -> V_225 ) ;
V_64 = F_87 ( V_2 ) ;
if ( F_78 ( V_2 ) )
goto V_8;
V_64 = - V_174 ;
V_77 = F_172 ( V_2 , V_165 -> V_248 ) ;
if ( V_77 == NULL )
goto V_323;
if ( V_165 -> V_223 . V_320 != 0 )
F_163 ( V_165 , V_77 ) ;
F_152 ( V_77 , & V_165 -> V_223 . V_53 , NULL ,
V_165 -> V_227 . V_205 ) ;
F_173 ( V_2 ) ;
V_156:
F_161 ( V_165 -> V_227 . V_226 ) ;
return V_77 ;
V_323:
F_173 ( V_2 ) ;
V_8:
return F_79 ( V_64 ) ;
}
static struct V_76 *
F_174 ( struct V_222 * V_165 )
{
struct V_76 * V_64 ;
if ( V_165 -> V_227 . V_215 == V_269 )
V_64 = F_167 ( V_165 ) ;
else
V_64 = F_169 ( V_165 ) ;
F_70 ( & V_165 -> V_223 . V_168 ) ;
return V_64 ;
}
static struct V_324 * F_175 ( struct V_76 * V_77 )
{
struct V_188 * V_189 = F_91 ( V_77 -> V_2 ) ;
struct V_324 * V_325 ;
F_46 ( & V_77 -> V_2 -> V_190 ) ;
F_176 (ctx, &nfsi->open_files, list) {
if ( V_325 -> V_77 != V_77 )
continue;
F_177 ( V_325 ) ;
F_48 ( & V_77 -> V_2 -> V_190 ) ;
return V_325 ;
}
F_48 ( & V_77 -> V_2 -> V_190 ) ;
return F_79 ( - V_326 ) ;
}
static struct V_222 * F_178 ( struct V_324 * V_325 ,
struct V_76 * V_77 , enum V_214 V_215 )
{
struct V_222 * V_313 ;
V_313 = F_101 ( V_325 -> V_4 , V_77 -> V_248 , 0 , 0 ,
NULL , NULL , V_215 , V_327 ) ;
if ( V_313 == NULL )
return F_79 ( - V_174 ) ;
V_313 -> V_77 = V_77 ;
F_108 ( & V_77 -> V_52 ) ;
return V_313 ;
}
static int F_179 ( struct V_222 * V_313 ,
T_6 V_205 )
{
struct V_76 * V_328 ;
int V_64 ;
if ( ! F_126 ( V_313 -> V_77 , V_205 ) )
return 0 ;
V_313 -> V_227 . V_250 = 0 ;
V_313 -> V_227 . V_205 = V_205 ;
V_313 -> V_227 . V_252 = F_96 (
F_180 ( V_313 -> V_4 -> V_247 ) ,
V_205 , 0 ) ;
memset ( & V_313 -> V_223 , 0 , sizeof( V_313 -> V_223 ) ) ;
memset ( & V_313 -> V_228 , 0 , sizeof( V_313 -> V_228 ) ) ;
F_98 ( V_313 ) ;
V_64 = F_181 ( V_313 ) ;
if ( V_64 != 0 )
return V_64 ;
V_328 = F_174 ( V_313 ) ;
if ( F_78 ( V_328 ) )
return F_87 ( V_328 ) ;
if ( V_328 != V_313 -> V_77 )
V_64 = - V_329 ;
F_182 ( V_328 , V_205 ) ;
return V_64 ;
}
static int F_183 ( struct V_222 * V_313 , struct V_76 * V_77 )
{
int V_64 ;
F_144 ( V_286 , & V_77 -> V_236 ) ;
F_144 ( V_285 , & V_77 -> V_236 ) ;
F_144 ( V_284 , & V_77 -> V_236 ) ;
F_144 ( V_296 , & V_77 -> V_236 ) ;
F_144 ( V_294 , & V_77 -> V_236 ) ;
F_184 () ;
V_64 = F_179 ( V_313 , V_207 | V_208 ) ;
if ( V_64 != 0 )
return V_64 ;
V_64 = F_179 ( V_313 , V_208 ) ;
if ( V_64 != 0 )
return V_64 ;
V_64 = F_179 ( V_313 , V_207 ) ;
if ( V_64 != 0 )
return V_64 ;
if ( F_38 ( V_296 , & V_77 -> V_236 ) == 0 &&
! F_155 ( & V_77 -> V_53 , & V_77 -> V_295 ) ) {
F_146 ( & V_77 -> V_298 ) ;
if ( F_38 ( V_296 , & V_77 -> V_236 ) == 0 )
F_19 ( & V_77 -> V_53 , & V_77 -> V_295 ) ;
F_148 ( & V_77 -> V_298 ) ;
}
return 0 ;
}
static int F_185 ( struct V_324 * V_325 , struct V_76 * V_77 )
{
struct V_287 * V_288 ;
struct V_222 * V_313 ;
T_6 V_320 = 0 ;
int V_330 ;
V_313 = F_178 ( V_325 , V_77 ,
V_269 ) ;
if ( F_78 ( V_313 ) )
return F_87 ( V_313 ) ;
F_153 () ;
V_288 = F_154 ( F_91 ( V_77 -> V_2 ) -> V_288 ) ;
if ( V_288 != NULL && F_38 ( V_290 , & V_288 -> V_236 ) != 0 )
V_320 = V_288 -> type ;
F_156 () ;
V_313 -> V_227 . V_272 . V_320 = V_320 ;
V_330 = F_183 ( V_313 , V_77 ) ;
F_124 ( V_313 ) ;
return V_330 ;
}
static int F_186 ( struct V_324 * V_325 , struct V_76 * V_77 )
{
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_185 ( V_325 , V_77 ) ;
F_187 ( V_325 , 0 , V_8 ) ;
if ( F_95 ( V_14 , V_8 , & V_74 ) )
continue;
if ( V_8 != - V_102 )
break;
F_36 ( V_14 , V_8 , & V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_188 ( struct V_234 * V_235 , struct V_76 * V_77 )
{
struct V_324 * V_325 ;
int V_64 ;
V_325 = F_175 ( V_77 ) ;
if ( F_78 ( V_325 ) )
return - V_121 ;
V_64 = F_186 ( V_325 , V_77 ) ;
F_189 ( V_325 ) ;
return V_64 ;
}
static int F_190 ( struct V_13 * V_14 , struct V_76 * V_77 , const T_4 * V_53 , int V_8 )
{
switch ( V_8 ) {
default:
F_35 ( V_331 L_15
L_16 , V_34 , V_8 ) ;
case 0 :
case - V_326 :
case - V_121 :
case - V_329 :
break;
case - V_93 :
case - V_94 :
case - V_95 :
case - V_96 :
case - V_97 :
F_142 ( V_296 , & V_77 -> V_236 ) ;
F_33 ( V_14 -> V_58 -> V_100 , V_8 ) ;
return - V_121 ;
case - V_89 :
case - V_88 :
F_142 ( V_296 , & V_77 -> V_236 ) ;
F_29 ( V_14 -> V_58 ) ;
return - V_121 ;
case - V_90 :
F_30 ( V_14 ) ;
return - V_121 ;
case - V_91 :
F_31 ( V_14 -> V_58 ) ;
return - V_121 ;
case - V_81 :
case - V_82 :
case - V_83 :
case - V_84 :
case - V_86 :
F_26 ( V_77 -> V_2 ,
V_53 ) ;
F_28 ( V_14 , V_77 ) ;
return - V_121 ;
case - V_102 :
case - V_104 :
F_142 ( V_296 , & V_77 -> V_236 ) ;
F_191 ( 1 ) ;
return - V_121 ;
case - V_174 :
case - V_332 :
return 0 ;
}
return V_8 ;
}
int F_192 ( struct V_324 * V_325 ,
struct V_76 * V_77 , const T_4 * V_53 ,
T_6 type )
{
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
struct V_222 * V_313 ;
int V_8 = 0 ;
V_313 = F_178 ( V_325 , V_77 ,
V_218 ) ;
if ( F_78 ( V_313 ) )
return F_87 ( V_313 ) ;
F_19 ( & V_313 -> V_227 . V_272 . V_288 , V_53 ) ;
F_146 ( & V_77 -> V_298 ) ;
F_19 ( & V_77 -> V_53 , & V_77 -> V_295 ) ;
F_148 ( & V_77 -> V_298 ) ;
F_144 ( V_296 , & V_77 -> V_236 ) ;
switch ( type & ( V_207 | V_208 ) ) {
case V_207 | V_208 :
case V_208 :
V_8 = F_179 ( V_313 , V_207 | V_208 ) ;
if ( V_8 )
break;
V_8 = F_179 ( V_313 , V_208 ) ;
if ( V_8 )
break;
case V_207 :
V_8 = F_179 ( V_313 , V_207 ) ;
}
F_124 ( V_313 ) ;
return F_190 ( V_14 , V_77 , V_53 , V_8 ) ;
}
static void F_193 ( struct V_115 * V_116 , void * V_163 )
{
struct V_222 * V_165 = V_163 ;
F_73 ( V_165 -> V_227 . V_14 -> V_58 ,
& V_165 -> V_229 . V_167 , & V_165 -> V_228 . V_168 , V_116 ) ;
}
static void F_194 ( struct V_115 * V_116 , void * V_163 )
{
struct V_222 * V_165 = V_163 ;
F_56 ( V_116 , & V_165 -> V_228 . V_168 ) ;
V_165 -> V_318 = V_116 -> V_120 ;
if ( V_165 -> V_318 == 0 ) {
F_19 ( & V_165 -> V_223 . V_53 , & V_165 -> V_228 . V_53 ) ;
F_195 ( & V_165 -> V_248 -> V_245 , 0 ) ;
F_49 ( V_165 -> V_223 . V_14 , V_165 -> V_128 ) ;
V_165 -> V_317 = true ;
}
}
static void F_196 ( void * V_163 )
{
struct V_222 * V_165 = V_163 ;
struct V_76 * V_77 = NULL ;
if ( ! V_165 -> V_333 )
goto V_334;
if ( ! V_165 -> V_317 )
goto V_334;
V_77 = F_174 ( V_165 ) ;
if ( ! F_78 ( V_77 ) )
F_182 ( V_77 , V_165 -> V_227 . V_205 ) ;
V_334:
F_124 ( V_165 ) ;
}
static int F_197 ( struct V_222 * V_165 )
{
struct V_13 * V_14 = F_103 ( F_14 ( V_165 -> V_3 ) ) ;
struct V_115 * V_116 ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_337 ] ,
. V_338 = & V_165 -> V_229 ,
. V_339 = & V_165 -> V_228 ,
. V_54 = V_165 -> V_248 -> V_306 ,
} ;
struct V_180 V_340 = {
. V_182 = V_14 -> V_111 ,
. V_178 = & V_179 ,
. V_183 = & V_341 ,
. V_185 = V_165 ,
. V_342 = V_343 ,
. V_236 = V_344 ,
} ;
int V_330 ;
F_51 ( & V_165 -> V_229 . V_167 , & V_165 -> V_228 . V_168 , 1 ) ;
F_198 ( & V_165 -> V_274 ) ;
V_165 -> V_317 = false ;
V_165 -> V_318 = 0 ;
V_165 -> V_128 = V_175 ;
if ( V_165 -> V_315 )
F_52 ( & V_165 -> V_229 . V_167 ) ;
V_116 = F_86 ( & V_340 ) ;
if ( F_78 ( V_116 ) )
return F_87 ( V_116 ) ;
V_330 = F_199 ( V_116 ) ;
if ( V_330 != 0 ) {
V_165 -> V_333 = true ;
F_200 () ;
} else
V_330 = V_165 -> V_318 ;
F_88 ( V_116 ) ;
return V_330 ;
}
static void F_201 ( struct V_115 * V_116 , void * V_163 )
{
struct V_222 * V_165 = V_163 ;
struct V_234 * V_235 = V_165 -> V_248 ;
struct V_58 * V_75 = V_235 -> V_291 -> V_58 ;
enum V_214 V_215 = V_165 -> V_227 . V_215 ;
if ( F_202 ( V_165 -> V_227 . V_226 , V_116 ) != 0 )
goto V_345;
if ( V_165 -> V_77 != NULL ) {
struct V_287 * V_288 ;
if ( F_128 ( V_165 -> V_77 , V_165 -> V_227 . V_205 , V_165 -> V_227 . V_250 ) )
goto V_346;
F_153 () ;
V_288 = F_154 ( F_91 ( V_165 -> V_77 -> V_2 ) -> V_288 ) ;
if ( F_129 ( V_288 , V_165 -> V_227 . V_205 , V_215 ) )
goto V_347;
F_156 () ;
}
V_165 -> V_227 . V_258 = V_75 -> V_259 ;
switch ( V_215 ) {
default:
break;
case V_269 :
case V_218 :
case V_220 :
V_165 -> V_227 . V_266 = & V_348 [ 0 ] ;
case V_216 :
V_116 -> V_349 . V_335 = & V_336 [ V_350 ] ;
F_203 ( & V_165 -> V_223 . V_268 , V_165 -> V_227 . V_268 ) ;
}
V_165 -> V_128 = V_175 ;
if ( F_73 ( V_165 -> V_227 . V_14 -> V_58 ,
& V_165 -> V_227 . V_167 ,
& V_165 -> V_223 . V_168 ,
V_116 ) != 0 )
F_161 ( V_165 -> V_227 . V_226 ) ;
V_165 -> V_227 . V_351 = V_352 ;
if ( V_165 -> V_227 . V_250 & V_253 ) {
V_165 -> V_227 . V_351 = V_353 ;
if ( F_204 ( V_75 ) )
V_165 -> V_227 . V_351 = V_354 ;
else if ( V_75 -> V_59 -> V_355 > 0 )
V_165 -> V_227 . V_351 = V_356 ;
}
return;
V_347:
F_170 ( V_165 -> V_77 ) ;
F_156 () ;
V_346:
V_116 -> V_357 = NULL ;
V_345:
F_71 ( V_116 , & V_165 -> V_223 . V_168 ) ;
}
static void F_205 ( struct V_115 * V_116 , void * V_163 )
{
struct V_222 * V_165 = V_163 ;
V_165 -> V_318 = V_116 -> V_120 ;
if ( ! F_69 ( V_116 , & V_165 -> V_223 . V_168 ) )
return;
if ( V_116 -> V_120 == 0 ) {
if ( V_165 -> V_223 . V_224 -> V_321 & V_358 ) {
switch ( V_165 -> V_223 . V_224 -> V_281 & V_359 ) {
case V_360 :
break;
case V_361 :
V_165 -> V_318 = - V_362 ;
break;
case V_363 :
V_165 -> V_318 = - V_364 ;
break;
default:
V_165 -> V_318 = - V_365 ;
}
}
F_49 ( V_165 -> V_223 . V_14 , V_165 -> V_128 ) ;
if ( ! ( V_165 -> V_223 . V_366 & V_367 ) )
F_195 ( & V_165 -> V_248 -> V_245 , 0 ) ;
}
V_165 -> V_317 = true ;
}
static void F_206 ( void * V_163 )
{
struct V_222 * V_165 = V_163 ;
struct V_76 * V_77 = NULL ;
if ( ! V_165 -> V_333 )
goto V_334;
if ( V_165 -> V_318 != 0 || ! V_165 -> V_317 )
goto V_334;
if ( V_165 -> V_223 . V_366 & V_367 )
goto V_334;
V_77 = F_174 ( V_165 ) ;
if ( ! F_78 ( V_77 ) )
F_182 ( V_77 , V_165 -> V_227 . V_205 ) ;
V_334:
F_124 ( V_165 ) ;
}
static int F_207 ( struct V_222 * V_165 , int V_368 )
{
struct V_2 * V_3 = F_14 ( V_165 -> V_3 ) ;
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_369 * V_227 = & V_165 -> V_227 ;
struct V_370 * V_223 = & V_165 -> V_223 ;
struct V_115 * V_116 ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_371 ] ,
. V_338 = V_227 ,
. V_339 = V_223 ,
. V_54 = V_165 -> V_248 -> V_306 ,
} ;
struct V_180 V_340 = {
. V_182 = V_14 -> V_111 ,
. V_178 = & V_179 ,
. V_183 = & V_372 ,
. V_185 = V_165 ,
. V_342 = V_343 ,
. V_236 = V_344 ,
} ;
int V_330 ;
F_51 ( & V_227 -> V_167 , & V_223 -> V_168 , 1 ) ;
F_198 ( & V_165 -> V_274 ) ;
V_165 -> V_317 = false ;
V_165 -> V_318 = 0 ;
V_165 -> V_333 = false ;
V_165 -> V_315 = false ;
if ( V_368 ) {
F_52 ( & V_227 -> V_167 ) ;
V_165 -> V_315 = true ;
}
V_116 = F_86 ( & V_340 ) ;
if ( F_78 ( V_116 ) )
return F_87 ( V_116 ) ;
V_330 = F_199 ( V_116 ) ;
if ( V_330 != 0 ) {
V_165 -> V_333 = true ;
F_200 () ;
} else
V_330 = V_165 -> V_318 ;
F_88 ( V_116 ) ;
return V_330 ;
}
static int F_181 ( struct V_222 * V_165 )
{
struct V_2 * V_3 = F_14 ( V_165 -> V_3 ) ;
struct V_370 * V_223 = & V_165 -> V_223 ;
int V_330 ;
V_330 = F_207 ( V_165 , 1 ) ;
if ( V_330 != 0 || ! V_165 -> V_317 )
return V_330 ;
F_208 ( F_103 ( V_3 ) , & V_165 -> V_224 ) ;
if ( V_223 -> V_366 & V_367 )
V_330 = F_197 ( V_165 ) ;
return V_330 ;
}
static int F_209 ( struct V_54 * V_55 ,
struct V_222 * V_313 ,
struct V_76 * V_77 , T_6 V_205 ,
int V_206 )
{
struct V_373 V_374 ;
T_1 V_375 , V_236 ;
if ( V_313 -> V_223 . V_376 == 0 )
return 0 ;
V_375 = 0 ;
if ( V_206 & V_377 ) {
if ( F_210 ( V_77 -> V_2 -> V_378 ) )
V_375 = V_379 ;
else
V_375 = V_257 ;
} else if ( ( V_205 & V_207 ) && ! V_313 -> V_380 )
V_375 = V_254 ;
V_374 . V_55 = V_55 ;
V_374 . V_175 = V_175 ;
F_211 ( & V_374 , V_313 -> V_223 . V_381 ) ;
F_212 ( V_77 -> V_2 , & V_374 ) ;
V_236 = V_254 | V_257 | V_379 ;
if ( ( V_375 & ~ V_374 . V_375 & V_236 ) == 0 )
return 0 ;
return - V_29 ;
}
static int F_213 ( struct V_222 * V_165 )
{
struct V_2 * V_3 = F_14 ( V_165 -> V_3 ) ;
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_369 * V_227 = & V_165 -> V_227 ;
struct V_370 * V_223 = & V_165 -> V_223 ;
int V_330 ;
V_330 = F_207 ( V_165 , 0 ) ;
if ( ! V_165 -> V_317 )
return V_330 ;
if ( V_330 != 0 ) {
if ( V_330 == - V_26 &&
! ( V_227 -> V_250 & V_382 ) )
return - V_326 ;
return V_330 ;
}
F_208 ( V_14 , & V_165 -> V_224 ) ;
if ( V_227 -> V_250 & V_382 ) {
if ( V_227 -> V_250 & V_253 )
V_165 -> V_380 = true ;
else if ( V_223 -> V_187 . V_195 != V_223 -> V_187 . V_201 )
V_165 -> V_380 = true ;
if ( V_165 -> V_380 || V_3 -> V_196 != V_223 -> V_187 . V_201 )
F_90 ( V_3 , & V_223 -> V_187 ,
V_223 -> V_224 -> V_383 ) ;
}
if ( ( V_223 -> V_366 & V_384 ) == 0 )
V_14 -> V_107 &= ~ V_385 ;
if( V_223 -> V_366 & V_367 ) {
V_330 = F_197 ( V_165 ) ;
if ( V_330 != 0 )
return V_330 ;
}
if ( ! ( V_223 -> V_224 -> V_321 & V_322 ) ) {
F_70 ( & V_223 -> V_168 ) ;
F_214 ( V_14 , & V_223 -> V_268 , V_223 -> V_224 , V_223 -> V_225 ) ;
}
return 0 ;
}
static int F_215 ( struct V_324 * V_325 , struct V_76 * V_77 )
{
struct V_222 * V_313 ;
int V_64 ;
V_313 = F_178 ( V_325 , V_77 ,
V_216 ) ;
if ( F_78 ( V_313 ) )
return F_87 ( V_313 ) ;
V_64 = F_183 ( V_313 , V_77 ) ;
if ( V_64 == - V_329 )
F_216 ( V_325 -> V_4 ) ;
F_124 ( V_313 ) ;
return V_64 ;
}
static int F_217 ( struct V_324 * V_325 , struct V_76 * V_77 )
{
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_215 ( V_325 , V_77 ) ;
F_218 ( V_325 , 0 , V_8 ) ;
if ( F_95 ( V_14 , V_8 , & V_74 ) )
continue;
switch ( V_8 ) {
default:
goto V_156;
case - V_104 :
case - V_102 :
F_36 ( V_14 , V_8 , & V_74 ) ;
V_8 = 0 ;
}
} while ( V_74 . V_80 );
V_156:
return V_8 ;
}
static int F_219 ( struct V_234 * V_235 , struct V_76 * V_77 )
{
struct V_324 * V_325 ;
int V_64 ;
V_325 = F_175 ( V_77 ) ;
if ( F_78 ( V_325 ) )
return - V_121 ;
V_64 = F_217 ( V_325 , V_77 ) ;
F_189 ( V_325 ) ;
return V_64 ;
}
static void F_220 ( struct V_76 * V_77 ,
const T_4 * V_53 )
{
F_221 ( V_77 -> V_2 , V_53 ) ;
F_146 ( & V_77 -> V_298 ) ;
F_19 ( & V_77 -> V_53 , & V_77 -> V_295 ) ;
F_148 ( & V_77 -> V_298 ) ;
F_144 ( V_296 , & V_77 -> V_236 ) ;
}
static void F_222 ( struct V_76 * V_77 )
{
if ( F_223 ( F_91 ( V_77 -> V_2 ) -> V_288 ) != NULL )
F_220 ( V_77 , NULL ) ;
}
static int F_224 ( struct V_234 * V_235 , struct V_76 * V_77 )
{
F_222 ( V_77 ) ;
return F_219 ( V_235 , V_77 ) ;
}
static int F_225 ( struct V_13 * V_14 ,
T_4 * V_53 ,
struct V_54 * V_55 )
{
return - V_84 ;
}
static int F_226 ( struct V_13 * V_14 ,
T_4 * V_53 ,
struct V_54 * V_55 )
{
int V_330 ;
switch ( V_53 -> type ) {
default:
break;
case V_386 :
case V_387 :
return - V_84 ;
case V_61 :
goto V_334;
}
V_330 = F_227 ( V_14 , V_53 , V_55 ) ;
switch ( V_330 ) {
case - V_83 :
case - V_82 :
case - V_81 :
break;
default:
return V_330 ;
}
V_334:
F_228 ( V_14 , V_53 , V_55 , true ) ;
return - V_83 ;
}
static void F_229 ( struct V_76 * V_77 )
{
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
T_4 V_53 ;
struct V_287 * V_288 ;
struct V_54 * V_55 ;
int V_330 ;
F_153 () ;
V_288 = F_154 ( F_91 ( V_77 -> V_2 ) -> V_288 ) ;
if ( V_288 == NULL ) {
F_156 () ;
return;
}
F_19 ( & V_53 , & V_288 -> V_53 ) ;
if ( F_38 ( V_388 , & V_288 -> V_236 ) ||
! F_135 ( V_389 ,
& V_288 -> V_236 ) ) {
F_156 () ;
F_220 ( V_77 , & V_53 ) ;
return;
}
V_55 = F_230 ( V_288 -> V_55 ) ;
F_156 () ;
V_330 = F_226 ( V_14 , & V_53 , V_55 ) ;
F_231 ( V_77 , NULL , V_330 ) ;
if ( V_330 == - V_83 || V_330 == - V_84 )
F_220 ( V_77 , & V_53 ) ;
F_232 ( V_55 ) ;
}
static int F_233 ( struct V_76 * V_77 )
{
int V_330 , V_64 = V_390 ;
struct V_307 * V_308 , * V_391 = NULL ;
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
if ( ! F_38 ( V_392 , & V_77 -> V_236 ) )
goto V_156;
F_46 ( & V_77 -> V_310 ) ;
F_176 (lsp, &state->lock_states, ls_locks) {
if ( F_38 ( V_393 , & V_308 -> V_394 ) ) {
struct V_54 * V_55 = V_308 -> V_309 -> V_248 -> V_306 ;
F_108 ( & V_308 -> V_395 ) ;
F_48 ( & V_77 -> V_310 ) ;
F_234 ( V_391 ) ;
V_391 = V_308 ;
V_330 = F_226 ( V_14 ,
& V_308 -> V_311 ,
V_55 ) ;
F_235 ( V_77 , V_308 , V_330 ) ;
if ( V_330 == - V_83 ||
V_330 == - V_84 ) {
F_144 ( V_393 , & V_308 -> V_394 ) ;
V_308 -> V_311 . type = V_386 ;
if ( ! V_396 )
F_142 ( V_397 , & V_308 -> V_394 ) ;
} else if ( V_330 != V_390 ) {
V_64 = V_330 ;
F_234 ( V_391 ) ;
goto V_156;
}
F_46 ( & V_77 -> V_310 ) ;
}
}
F_48 ( & V_77 -> V_310 ) ;
F_234 ( V_391 ) ;
V_156:
return V_64 ;
}
static int F_236 ( struct V_76 * V_77 )
{
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
T_4 * V_53 = & V_77 -> V_295 ;
struct V_54 * V_55 = V_77 -> V_248 -> V_306 ;
int V_330 ;
if ( F_38 ( V_294 , & V_77 -> V_236 ) == 0 ) {
if ( F_38 ( V_296 , & V_77 -> V_236 ) == 0 ) {
if ( F_237 ( V_77 -> V_2 , V_77 -> V_77 ) )
return V_390 ;
return - V_86 ;
}
return - V_84 ;
}
V_330 = F_226 ( V_14 , V_53 , V_55 ) ;
F_238 ( V_77 , NULL , V_330 ) ;
if ( V_330 == - V_83 || V_330 == - V_84 ) {
F_144 ( V_284 , & V_77 -> V_236 ) ;
F_144 ( V_285 , & V_77 -> V_236 ) ;
F_144 ( V_286 , & V_77 -> V_236 ) ;
F_144 ( V_294 , & V_77 -> V_236 ) ;
V_53 -> type = V_386 ;
return V_330 ;
}
if ( F_133 ( V_77 ) )
return - V_86 ;
return V_390 ;
}
static int F_239 ( struct V_234 * V_235 , struct V_76 * V_77 )
{
int V_330 ;
F_229 ( V_77 ) ;
V_330 = F_233 ( V_77 ) ;
if ( V_330 != V_390 )
return V_330 ;
V_330 = F_236 ( V_77 ) ;
if ( V_330 != V_390 )
V_330 = F_219 ( V_235 , V_77 ) ;
return V_330 ;
}
static inline void F_240 ( struct V_222 * V_313 ,
struct V_5 * V_6 , struct V_1 * * V_7 )
{
const T_1 * V_398 = V_313 -> V_223 . V_398 ;
if ( ( V_398 [ 1 ] & V_399 ) &&
! ( V_6 -> V_270 & V_400 ) )
V_6 -> V_270 |= V_401 ;
if ( ( V_398 [ 1 ] & V_402 ) &&
! ( V_6 -> V_270 & V_403 ) )
V_6 -> V_270 |= V_404 ;
if ( V_313 -> V_227 . V_351 != V_353 &&
( V_398 [ 1 ] & V_405 ||
V_398 [ 2 ] & V_406 ) )
V_6 -> V_270 &= ~ V_407 ;
if ( V_398 [ 2 ] & V_408 )
* V_7 = NULL ;
}
static int F_241 ( struct V_222 * V_313 ,
T_6 V_205 ,
int V_236 ,
struct V_324 * V_325 )
{
struct V_234 * V_235 = V_313 -> V_248 ;
struct V_13 * V_14 = V_235 -> V_291 ;
struct V_4 * V_4 ;
struct V_76 * V_77 ;
unsigned int V_409 ;
int V_64 ;
V_409 = F_242 ( & V_235 -> V_410 ) ;
V_64 = F_213 ( V_313 ) ;
if ( V_64 != 0 )
goto V_156;
V_77 = F_174 ( V_313 ) ;
V_64 = F_87 ( V_77 ) ;
if ( F_78 ( V_77 ) )
goto V_156;
V_325 -> V_77 = V_77 ;
if ( V_14 -> V_107 & V_385 )
F_142 ( V_411 , & V_77 -> V_236 ) ;
if ( V_313 -> V_223 . V_366 & V_412 )
F_142 ( V_413 , & V_77 -> V_236 ) ;
V_4 = V_313 -> V_4 ;
if ( F_243 ( V_4 ) ) {
struct V_4 * V_414 ;
F_216 ( V_4 ) ;
V_414 = F_244 ( V_4 , V_77 -> V_2 ) ;
if ( ! V_414 )
V_414 = F_245 ( F_246 ( V_77 -> V_2 ) , V_4 ) ;
if ( V_414 ) {
F_116 ( V_325 -> V_4 ) ;
V_325 -> V_4 = V_4 = V_414 ;
}
F_247 ( V_4 ,
F_248 ( F_14 ( V_313 -> V_3 ) ) ) ;
}
V_64 = F_209 ( V_235 -> V_306 , V_313 , V_77 , V_205 , V_236 ) ;
if ( V_64 != 0 )
goto V_156;
if ( F_14 ( V_4 ) == V_77 -> V_2 ) {
F_249 ( V_325 ) ;
if ( F_250 ( & V_235 -> V_410 , V_409 ) )
F_28 ( V_14 , V_77 ) ;
}
V_156:
return V_64 ;
}
static int F_251 ( struct V_2 * V_3 ,
struct V_324 * V_325 ,
int V_236 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_415 )
{
struct V_234 * V_235 ;
struct V_76 * V_77 = NULL ;
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_222 * V_313 ;
struct V_4 * V_4 = V_325 -> V_4 ;
struct V_54 * V_55 = V_325 -> V_55 ;
struct V_416 * * V_417 = & V_325 -> V_277 ;
T_6 V_205 = V_325 -> V_281 & ( V_207 | V_208 | V_418 ) ;
enum V_214 V_215 = V_217 ;
struct V_1 * V_419 = NULL ;
int V_330 ;
V_330 = - V_174 ;
V_235 = F_252 ( V_14 , V_55 , V_420 ) ;
if ( V_235 == NULL ) {
F_8 ( L_17 ) ;
goto V_421;
}
V_330 = F_253 ( V_14 -> V_58 ) ;
if ( V_330 != 0 )
goto V_422;
if ( F_254 ( V_4 ) )
F_158 ( F_14 ( V_4 ) , V_205 ) ;
V_330 = - V_174 ;
if ( F_254 ( V_4 ) )
V_215 = V_216 ;
V_313 = F_101 ( V_4 , V_235 , V_205 , V_236 , V_6 ,
V_7 , V_215 , V_420 ) ;
if ( V_313 == NULL )
goto V_422;
if ( V_7 ) {
V_419 = F_105 ( V_14 , V_420 ) ;
if ( F_78 ( V_419 ) ) {
V_330 = F_87 ( V_419 ) ;
goto V_423;
}
}
if ( V_14 -> V_15 [ 2 ] & V_424 ) {
if ( ! V_313 -> V_224 . V_277 ) {
V_313 -> V_224 . V_277 = F_255 () ;
if ( ! V_313 -> V_224 . V_277 )
goto V_246;
}
V_313 -> V_227 . V_266 = & V_425 [ 0 ] ;
}
if ( F_254 ( V_4 ) )
V_313 -> V_77 = F_172 ( F_14 ( V_4 ) , V_235 ) ;
V_330 = F_241 ( V_313 , V_205 , V_236 , V_325 ) ;
if ( V_330 != 0 )
goto V_246;
V_77 = V_325 -> V_77 ;
if ( ( V_313 -> V_227 . V_250 & ( V_382 | V_253 ) ) == ( V_382 | V_253 ) &&
( V_313 -> V_227 . V_351 != V_354 ) ) {
F_240 ( V_313 , V_6 , & V_7 ) ;
if ( V_6 -> V_270 & V_426 ) {
F_99 ( V_313 -> V_223 . V_224 ) ;
V_330 = F_256 ( V_77 -> V_2 , V_55 ,
V_313 -> V_223 . V_224 , V_6 ,
V_325 , V_7 , V_419 ) ;
if ( V_330 == 0 ) {
F_257 ( V_77 -> V_2 , V_6 ,
V_313 -> V_223 . V_224 ) ;
F_258 ( V_77 -> V_2 , V_313 -> V_223 . V_224 , V_419 ) ;
}
}
}
if ( V_415 && V_313 -> V_380 )
* V_415 |= V_427 ;
if ( F_259 ( V_417 , V_313 -> V_224 . V_277 , V_14 ) ) {
* V_417 = V_313 -> V_224 . V_277 ;
V_313 -> V_224 . V_277 = NULL ;
}
F_114 ( V_419 ) ;
F_124 ( V_313 ) ;
F_121 ( V_235 ) ;
return 0 ;
V_246:
F_114 ( V_419 ) ;
V_423:
F_124 ( V_313 ) ;
V_422:
F_121 ( V_235 ) ;
V_421:
return V_330 ;
}
static struct V_76 * F_260 ( struct V_2 * V_3 ,
struct V_324 * V_325 ,
int V_236 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_415 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_73 V_74 = { } ;
struct V_76 * V_69 ;
int V_330 ;
do {
V_330 = F_251 ( V_3 , V_325 , V_236 , V_6 , V_7 , V_415 ) ;
V_69 = V_325 -> V_77 ;
F_261 ( V_325 , V_236 , V_330 ) ;
if ( V_330 == 0 )
break;
if ( V_330 == - V_428 ) {
F_262 ( L_5
L_18 ,
F_103 ( V_3 ) -> V_58 -> V_110 ) ;
V_74 . V_80 = 1 ;
continue;
}
if ( V_330 == - V_84 ) {
V_74 . V_80 = 1 ;
continue;
}
if ( V_330 == - V_121 ) {
V_74 . V_80 = 1 ;
continue;
}
if ( F_95 ( V_14 , V_330 , & V_74 ) )
continue;
V_69 = F_79 ( F_36 ( V_14 ,
V_330 , & V_74 ) ) ;
} while ( V_74 . V_80 );
return V_69 ;
}
static int F_263 ( struct V_2 * V_2 ,
struct V_429 * V_430 ,
struct V_431 * V_69 ,
struct V_54 * V_55 ,
struct V_324 * V_325 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_432 ] ,
. V_338 = V_430 ,
. V_339 = V_69 ,
. V_54 = V_55 ,
} ;
struct V_54 * V_433 = NULL ;
unsigned long V_128 = V_175 ;
T_6 V_205 ;
bool V_434 ;
int V_330 ;
F_99 ( V_69 -> V_435 ) ;
V_434 = ( V_430 -> V_436 -> V_270 & V_437 ) ? true : false ;
V_205 = V_434 ? V_208 : V_207 ;
if ( F_264 ( V_2 , V_205 , & V_430 -> V_53 , & V_433 ) ) {
} else if ( V_434 && V_325 != NULL ) {
struct V_438 * V_439 ;
if ( ! F_265 ( V_325 -> V_77 ) )
return - V_440 ;
V_439 = F_266 ( V_325 ) ;
if ( F_78 ( V_439 ) )
return F_87 ( V_439 ) ;
V_330 = F_267 ( V_325 -> V_77 , V_208 , V_439 ,
& V_430 -> V_53 , & V_433 ) ;
F_268 ( V_439 ) ;
if ( V_330 == - V_35 )
return - V_440 ;
} else
F_19 ( & V_430 -> V_53 , & V_441 ) ;
if ( V_433 )
V_179 . V_54 = V_433 ;
V_330 = F_89 ( V_14 -> V_111 , V_14 , & V_179 , & V_430 -> V_167 , & V_69 -> V_168 , 1 ) ;
F_232 ( V_433 ) ;
if ( V_330 == 0 && V_325 != NULL )
F_49 ( V_14 , V_128 ) ;
F_269 ( V_2 , & V_430 -> V_53 , V_330 ) ;
return V_330 ;
}
static int F_256 ( struct V_2 * V_2 , struct V_54 * V_55 ,
struct V_442 * V_435 , struct V_5 * V_6 ,
struct V_324 * V_325 , struct V_1 * V_443 ,
struct V_1 * V_419 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_76 * V_77 = V_325 ? V_325 -> V_77 : NULL ;
struct V_429 V_430 = {
. V_268 = F_112 ( V_2 ) ,
. V_436 = V_6 ,
. V_14 = V_14 ,
. V_265 = V_14 -> V_15 ,
. V_7 = V_443 ,
} ;
struct V_431 V_69 = {
. V_435 = V_435 ,
. V_7 = V_419 ,
. V_14 = V_14 ,
} ;
struct V_73 V_74 = {
. V_77 = V_77 ,
. V_2 = V_2 ,
. V_53 = & V_430 . V_53 ,
} ;
int V_8 ;
V_430 . V_265 = F_6 ( V_14 , V_443 ) ;
if ( V_443 )
V_430 . V_265 = F_6 ( V_14 , V_419 ) ;
do {
V_8 = F_263 ( V_2 , & V_430 , & V_69 , V_55 , V_325 ) ;
switch ( V_8 ) {
case - V_86 :
if ( ! ( V_6 -> V_270 & V_437 ) ) {
F_270 ( L_19
L_20
L_21
L_22 ,
V_14 -> V_58 -> V_110 ) ;
}
if ( V_77 && ! ( V_77 -> V_77 & V_208 ) ) {
V_8 = - V_440 ;
if ( V_6 -> V_270 & V_444 )
V_8 = - V_29 ;
goto V_156;
}
}
V_8 = F_36 ( V_14 , V_8 , & V_74 ) ;
} while ( V_74 . V_80 );
V_156:
return V_8 ;
}
static bool
F_271 ( struct V_2 * V_2 , struct V_115 * V_116 )
{
if ( V_2 == NULL || ! F_272 ( V_2 ) )
return false ;
return F_273 ( V_2 , V_116 ) ;
}
static void F_274 ( void * V_165 )
{
struct V_445 * V_163 = V_165 ;
struct V_234 * V_235 = V_163 -> V_77 -> V_248 ;
struct V_275 * V_276 = V_163 -> V_77 -> V_2 -> V_446 ;
if ( V_163 -> V_447 . V_448 )
F_275 ( & V_163 -> V_447 . V_430 , & V_163 -> V_447 . V_69 ,
V_163 -> V_69 . V_449 ) ;
F_120 ( V_163 -> V_77 ) ;
F_119 ( V_163 -> V_430 . V_226 ) ;
F_121 ( V_235 ) ;
F_122 ( V_276 ) ;
F_115 ( V_163 ) ;
}
static void F_276 ( struct V_115 * V_116 , void * V_165 )
{
struct V_445 * V_163 = V_165 ;
struct V_76 * V_77 = V_163 -> V_77 ;
struct V_13 * V_14 = F_103 ( V_163 -> V_2 ) ;
T_4 * V_450 = NULL ;
F_8 ( L_23 , V_34 ) ;
if ( ! F_71 ( V_116 , & V_163 -> V_69 . V_168 ) )
return;
F_277 ( V_77 , & V_163 -> V_430 , & V_163 -> V_69 , V_116 -> V_120 ) ;
if ( V_163 -> V_430 . V_451 && V_116 -> V_120 != 0 ) {
switch ( V_163 -> V_69 . V_449 ) {
default:
V_163 -> V_69 . V_449 = - V_452 ;
break;
case 0 :
V_163 -> V_430 . V_451 = NULL ;
V_163 -> V_69 . V_453 = NULL ;
break;
case - V_82 :
case - V_81 :
case - V_83 :
case - V_84 :
case - V_106 :
case - V_454 :
case - V_23 :
V_163 -> V_430 . V_451 = NULL ;
V_163 -> V_69 . V_453 = NULL ;
V_163 -> V_69 . V_449 = 0 ;
F_66 ( V_116 ) ;
return;
}
}
switch ( V_116 -> V_120 ) {
case 0 :
V_450 = & V_163 -> V_69 . V_53 ;
F_49 ( V_14 , V_163 -> V_128 ) ;
break;
case - V_455 :
if ( V_163 -> V_430 . V_265 != NULL ) {
V_163 -> V_430 . V_265 = NULL ;
V_163 -> V_69 . V_435 = NULL ;
V_116 -> V_120 = 0 ;
F_66 ( V_116 ) ;
goto V_456;
}
break;
case - V_82 :
case - V_88 :
case - V_83 :
F_18 ( V_14 ,
& V_163 -> V_430 . V_53 ,
V_116 -> V_349 . V_54 ) ;
case - V_106 :
case - V_84 :
if ( ! F_155 ( & V_163 -> V_430 . V_53 ,
& V_77 -> V_295 ) ) {
F_66 ( V_116 ) ;
goto V_456;
}
if ( V_163 -> V_430 . V_205 == 0 )
break;
default:
if ( F_43 ( V_116 , V_14 , V_77 , NULL ) == - V_121 ) {
F_66 ( V_116 ) ;
goto V_456;
}
}
F_145 ( V_77 , & V_163 -> V_430 . V_53 ,
V_450 , V_163 -> V_430 . V_205 ) ;
V_456:
F_161 ( V_163 -> V_430 . V_226 ) ;
F_168 ( V_163 -> V_2 , & V_163 -> V_435 ) ;
F_8 ( L_24 , V_34 , V_116 -> V_120 ) ;
}
static void F_278 ( struct V_115 * V_116 , void * V_165 )
{
struct V_445 * V_163 = V_165 ;
struct V_76 * V_77 = V_163 -> V_77 ;
struct V_2 * V_2 = V_163 -> V_2 ;
bool V_457 , V_458 , V_459 ;
int V_460 = 0 ;
F_8 ( L_23 , V_34 ) ;
if ( F_202 ( V_163 -> V_430 . V_226 , V_116 ) != 0 )
goto V_345;
V_116 -> V_349 . V_335 = & V_336 [ V_461 ] ;
F_46 ( & V_77 -> V_248 -> V_301 ) ;
V_459 = F_38 ( V_286 , & V_77 -> V_236 ) ;
V_457 = F_38 ( V_284 , & V_77 -> V_236 ) ;
V_458 = F_38 ( V_285 , & V_77 -> V_236 ) ;
F_19 ( & V_163 -> V_430 . V_53 , & V_77 -> V_295 ) ;
V_163 -> V_430 . V_205 = 0 ;
if ( V_77 -> V_278 == 0 ) {
if ( V_77 -> V_280 == 0 )
V_460 |= V_457 ;
else if ( V_457 )
V_163 -> V_430 . V_205 |= V_207 ;
if ( V_77 -> V_279 == 0 )
V_460 |= V_458 ;
else if ( V_458 )
V_163 -> V_430 . V_205 |= V_208 ;
if ( V_163 -> V_430 . V_205 != ( V_207 | V_208 ) )
V_460 |= V_459 ;
} else if ( V_459 )
V_163 -> V_430 . V_205 |= V_207 | V_208 ;
if ( ! F_265 ( V_77 ) ||
F_38 ( V_294 , & V_77 -> V_236 ) == 0 )
V_460 = 0 ;
F_48 ( & V_77 -> V_248 -> V_301 ) ;
if ( ! V_460 ) {
goto V_346;
}
if ( ! V_163 -> V_447 . V_448 && F_271 ( V_2 , V_116 ) ) {
F_161 ( V_163 -> V_430 . V_226 ) ;
goto V_345;
}
if ( V_163 -> V_430 . V_205 == 0 )
V_116 -> V_349 . V_335 = & V_336 [ V_462 ] ;
if ( V_163 -> V_430 . V_205 == 0 || V_163 -> V_430 . V_205 == V_207 ) {
if ( ! F_237 ( V_2 , V_207 ) )
V_163 -> V_430 . V_265 = F_103 ( V_2 ) -> V_463 ;
else
V_163 -> V_430 . V_265 = NULL ;
}
V_163 -> V_430 . V_252 =
F_96 ( F_103 ( V_2 ) ,
V_163 -> V_430 . V_205 , 0 ) ;
if ( V_163 -> V_69 . V_435 == NULL )
V_163 -> V_430 . V_265 = NULL ;
else if ( V_163 -> V_430 . V_265 == NULL )
V_163 -> V_69 . V_435 = NULL ;
V_163 -> V_128 = V_175 ;
if ( F_73 ( F_103 ( V_2 ) -> V_58 ,
& V_163 -> V_430 . V_167 ,
& V_163 -> V_69 . V_168 ,
V_116 ) != 0 )
F_161 ( V_163 -> V_430 . V_226 ) ;
F_8 ( L_25 , V_34 ) ;
return;
V_346:
V_116 -> V_357 = NULL ;
V_345:
F_71 ( V_116 , & V_163 -> V_69 . V_168 ) ;
}
int F_279 ( struct V_76 * V_77 , T_7 V_237 , int V_464 )
{
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
struct V_239 * ( * V_240 ) ( struct V_241 * , T_7 ) ;
struct V_445 * V_163 ;
struct V_234 * V_235 = V_77 -> V_248 ;
struct V_115 * V_116 ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_462 ] ,
. V_54 = V_77 -> V_248 -> V_306 ,
} ;
struct V_180 V_340 = {
. V_182 = V_14 -> V_111 ,
. V_178 = & V_179 ,
. V_183 = & V_465 ,
. V_342 = V_343 ,
. V_236 = V_344 ,
} ;
int V_330 = - V_174 ;
F_280 ( V_14 -> V_58 , V_466 ,
& V_340 . V_182 , & V_179 ) ;
V_163 = F_104 ( sizeof( * V_163 ) , V_237 ) ;
if ( V_163 == NULL )
goto V_156;
F_51 ( & V_163 -> V_430 . V_167 , & V_163 -> V_69 . V_168 , 1 ) ;
V_163 -> V_2 = V_77 -> V_2 ;
V_163 -> V_77 = V_77 ;
V_163 -> V_430 . V_268 = F_112 ( V_77 -> V_2 ) ;
V_240 = V_14 -> V_58 -> V_59 -> V_240 ;
V_163 -> V_430 . V_226 = V_240 ( & V_77 -> V_248 -> V_245 , V_237 ) ;
if ( F_78 ( V_163 -> V_430 . V_226 ) )
goto V_467;
F_99 ( & V_163 -> V_435 ) ;
V_163 -> V_430 . V_205 = 0 ;
V_163 -> V_447 . V_430 . V_468 = & V_163 -> V_447 . V_468 ;
V_163 -> V_69 . V_435 = & V_163 -> V_435 ;
V_163 -> V_69 . V_226 = V_163 -> V_430 . V_226 ;
V_163 -> V_69 . V_14 = V_14 ;
V_163 -> V_69 . V_449 = - V_452 ;
V_163 -> V_447 . V_448 = F_281 ( V_77 -> V_2 ,
& V_163 -> V_447 . V_430 , & V_163 -> V_447 . V_69 , V_179 . V_54 ) ;
if ( V_163 -> V_447 . V_448 ) {
V_163 -> V_430 . V_451 = & V_163 -> V_447 . V_430 ;
V_163 -> V_69 . V_453 = & V_163 -> V_447 . V_69 ;
}
F_106 ( V_163 -> V_2 -> V_446 ) ;
V_179 . V_338 = & V_163 -> V_430 ;
V_179 . V_339 = & V_163 -> V_69 ;
V_340 . V_185 = V_163 ;
V_116 = F_86 ( & V_340 ) ;
if ( F_78 ( V_116 ) )
return F_87 ( V_116 ) ;
V_330 = 0 ;
if ( V_464 )
V_330 = F_199 ( V_116 ) ;
F_88 ( V_116 ) ;
return V_330 ;
V_467:
F_115 ( V_163 ) ;
V_156:
F_120 ( V_77 ) ;
F_121 ( V_235 ) ;
return V_330 ;
}
static struct V_2 *
F_282 ( struct V_2 * V_3 , struct V_324 * V_325 ,
int V_250 , struct V_5 * V_469 , int * V_415 )
{
struct V_76 * V_77 ;
struct V_1 V_17 = { 0 , 0 , 0 , NULL } , * V_7 = NULL ;
V_7 = F_1 ( V_3 , V_325 -> V_4 , V_469 , & V_17 ) ;
V_77 = F_260 ( V_3 , V_325 , V_250 , V_469 , V_7 , V_415 ) ;
F_4 ( V_7 ) ;
if ( F_78 ( V_77 ) )
return F_283 ( V_77 ) ;
return V_77 -> V_2 ;
}
static void F_284 ( struct V_324 * V_325 , int V_470 )
{
if ( V_325 -> V_77 == NULL )
return;
if ( V_470 )
F_285 ( V_325 -> V_77 , V_325 -> V_281 ) ;
else
F_182 ( V_325 -> V_77 , V_325 -> V_281 ) ;
}
static int F_286 ( struct V_13 * V_14 , struct V_471 * V_472 )
{
T_1 V_265 [ 3 ] = {} , V_473 = V_14 -> V_58 -> V_474 ;
struct V_475 args = {
. V_472 = V_472 ,
. V_265 = V_265 ,
} ;
struct V_476 V_69 = {} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_477 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
} ;
int V_330 ;
int V_478 ;
V_265 [ 0 ] = V_479 |
V_480 |
V_481 |
V_482 |
V_483 ;
if ( V_473 )
V_265 [ 2 ] = V_484 ;
V_330 = F_89 ( V_14 -> V_111 , V_14 , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
if ( V_330 == 0 ) {
switch ( V_473 ) {
case 0 :
V_69 . V_15 [ 1 ] &= V_485 ;
V_69 . V_15 [ 2 ] = 0 ;
break;
case 1 :
V_69 . V_15 [ 2 ] &= V_486 ;
break;
case 2 :
V_69 . V_15 [ 2 ] &= V_487 ;
}
memcpy ( V_14 -> V_15 , V_69 . V_15 , sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_107 &= ~ ( V_488 | V_489 |
V_490 | V_491 |
V_492 | V_493 | V_494 |
V_495 | V_496 |
V_497 | V_498 |
V_9 ) ;
if ( V_69 . V_15 [ 0 ] & V_499 &&
V_69 . V_500 & V_501 )
V_14 -> V_107 |= V_488 ;
if ( V_69 . V_502 != 0 )
V_14 -> V_107 |= V_489 ;
if ( V_69 . V_503 != 0 )
V_14 -> V_107 |= V_490 ;
if ( V_69 . V_15 [ 0 ] & V_41 )
V_14 -> V_107 |= V_491 ;
if ( V_69 . V_15 [ 1 ] & V_405 )
V_14 -> V_107 |= V_492 ;
if ( V_69 . V_15 [ 1 ] & V_504 )
V_14 -> V_107 |= V_493 ;
if ( V_69 . V_15 [ 1 ] & V_505 )
V_14 -> V_107 |= V_494 ;
if ( V_69 . V_15 [ 1 ] & V_506 )
V_14 -> V_107 |= V_495 ;
if ( V_69 . V_15 [ 1 ] & V_399 )
V_14 -> V_107 |= V_496 ;
if ( V_69 . V_15 [ 1 ] & V_507 )
V_14 -> V_107 |= V_497 ;
if ( V_69 . V_15 [ 1 ] & V_402 )
V_14 -> V_107 |= V_498 ;
#ifdef F_287
if ( V_69 . V_15 [ 2 ] & V_408 )
V_14 -> V_107 |= V_9 ;
#endif
memcpy ( V_14 -> V_16 , V_69 . V_15 ,
sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_16 [ 2 ] &= ~ V_408 ;
memcpy ( V_14 -> V_463 , V_69 . V_15 , sizeof( V_14 -> V_463 ) ) ;
V_14 -> V_463 [ 0 ] &= V_508 | V_509 ;
V_14 -> V_463 [ 1 ] &= V_507 | V_402 ;
V_14 -> V_463 [ 2 ] = 0 ;
for ( V_478 = 0 ; V_478 < F_288 ( V_69 . V_510 ) ; V_478 ++ )
V_69 . V_510 [ V_478 ] &= V_69 . V_15 [ V_478 ] ;
memcpy ( V_14 -> V_510 , V_69 . V_510 ,
sizeof( V_14 -> V_510 ) ) ;
V_14 -> V_500 = V_69 . V_500 ;
V_14 -> V_511 = V_69 . V_511 ;
}
return V_330 ;
}
int F_289 ( struct V_13 * V_14 , struct V_471 * V_472 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_36 ( V_14 ,
F_286 ( V_14 , V_472 ) ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_290 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_512 * V_513 )
{
T_1 V_265 [ 3 ] ;
struct V_514 args = {
. V_265 = V_265 ,
} ;
struct V_515 V_69 = {
. V_14 = V_14 ,
. V_435 = V_513 -> V_435 ,
. V_268 = V_472 ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_516 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
} ;
V_265 [ 0 ] = V_267 [ 0 ] ;
V_265 [ 1 ] = V_267 [ 1 ] ;
V_265 [ 2 ] = V_267 [ 2 ] & ~ V_408 ;
F_99 ( V_513 -> V_435 ) ;
return F_89 ( V_14 -> V_111 , V_14 , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
}
static int F_291 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_512 * V_513 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_290 ( V_14 , V_472 , V_513 ) ;
F_292 ( V_14 , V_472 , V_513 -> V_435 , V_8 ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
goto V_156;
default:
V_8 = F_36 ( V_14 , V_8 , & V_74 ) ;
}
} while ( V_74 . V_80 );
V_156:
return V_8 ;
}
static int F_293 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_512 * V_513 , T_5 V_122 )
{
struct V_517 V_518 = {
. V_519 = V_122 ,
} ;
struct V_520 * V_521 ;
V_521 = F_294 ( & V_518 , V_14 -> V_111 ) ;
if ( F_78 ( V_521 ) )
return - V_29 ;
return F_291 ( V_14 , V_472 , V_513 ) ;
}
static int F_295 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_512 * V_513 )
{
static const T_5 V_522 [] = {
V_127 ,
V_126 ,
V_523 ,
V_524 ,
V_525 ,
} ;
int V_330 = - V_24 ;
T_9 V_478 ;
if ( V_14 -> V_526 . V_527 > 0 ) {
for ( V_478 = 0 ; V_478 < V_14 -> V_526 . V_527 ; V_478 ++ ) {
V_330 = F_293 ( V_14 , V_472 , V_513 ,
V_14 -> V_526 . V_528 [ V_478 ] ) ;
if ( V_330 == - V_22 || V_330 == - V_29 )
continue;
break;
}
} else {
for ( V_478 = 0 ; V_478 < F_288 ( V_522 ) ; V_478 ++ ) {
V_330 = F_293 ( V_14 , V_472 , V_513 ,
V_522 [ V_478 ] ) ;
if ( V_330 == - V_22 || V_330 == - V_29 )
continue;
break;
}
}
if ( V_330 == - V_29 )
V_330 = - V_24 ;
return V_330 ;
}
int F_296 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_512 * V_513 ,
bool V_529 )
{
int V_330 = 0 ;
if ( ! V_529 )
V_330 = F_291 ( V_14 , V_472 , V_513 ) ;
if ( V_529 || V_330 == V_22 )
V_330 = V_14 -> V_58 -> V_59 -> V_530 ( V_14 ,
V_472 , V_513 ) ;
if ( V_330 == 0 )
V_330 = F_289 ( V_14 , V_472 ) ;
if ( V_330 == 0 )
V_330 = F_297 ( V_14 , V_472 , V_513 ) ;
return F_7 ( V_330 ) ;
}
static int F_298 ( struct V_13 * V_14 , struct V_471 * V_531 ,
struct V_512 * V_513 )
{
int error ;
struct V_442 * V_435 = V_513 -> V_435 ;
struct V_1 * V_7 = NULL ;
error = F_289 ( V_14 , V_531 ) ;
if ( error < 0 ) {
F_8 ( L_26 , - error ) ;
return error ;
}
V_7 = F_105 ( V_14 , V_420 ) ;
if ( F_78 ( V_7 ) )
return F_87 ( V_7 ) ;
error = F_214 ( V_14 , V_531 , V_435 , V_7 ) ;
if ( error < 0 ) {
F_8 ( L_27 , - error ) ;
goto V_246;
}
if ( V_435 -> V_321 & V_532 &&
! F_299 ( & V_14 -> V_533 , & V_435 -> V_533 ) )
memcpy ( & V_14 -> V_533 , & V_435 -> V_533 , sizeof( V_14 -> V_533 ) ) ;
V_246:
F_114 ( V_7 ) ;
return error ;
}
static int F_300 ( struct V_67 * V_111 , struct V_2 * V_3 ,
const struct V_534 * V_264 , struct V_442 * V_435 ,
struct V_471 * V_472 )
{
int V_330 = - V_174 ;
struct V_535 * V_535 = NULL ;
struct V_536 * V_537 = NULL ;
V_535 = F_301 ( V_420 ) ;
if ( V_535 == NULL )
goto V_156;
V_537 = F_302 ( sizeof( struct V_536 ) , V_420 ) ;
if ( V_537 == NULL )
goto V_156;
V_330 = F_303 ( V_111 , V_3 , V_264 , V_537 , V_535 ) ;
if ( V_330 != 0 )
goto V_156;
if ( F_299 ( & F_103 ( V_3 ) -> V_533 , & V_537 -> V_435 . V_533 ) ) {
F_8 ( L_28
L_29 , V_34 , V_264 -> V_264 ) ;
V_330 = - V_90 ;
goto V_156;
}
F_304 ( & V_537 -> V_435 ) ;
memcpy ( V_435 , & V_537 -> V_435 , sizeof( struct V_442 ) ) ;
memset ( V_472 , 0 , sizeof( struct V_471 ) ) ;
V_156:
if ( V_535 )
F_305 ( V_535 ) ;
F_115 ( V_537 ) ;
return V_330 ;
}
static int F_306 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_442 * V_435 , struct V_1 * V_7 )
{
struct V_538 args = {
. V_268 = V_472 ,
. V_265 = V_14 -> V_15 ,
} ;
struct V_539 V_69 = {
. V_435 = V_435 ,
. V_7 = V_7 ,
. V_14 = V_14 ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_540 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
} ;
args . V_265 = F_6 ( V_14 , V_7 ) ;
F_99 ( V_435 ) ;
return F_89 ( V_14 -> V_111 , V_14 , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
}
static int F_214 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_442 * V_435 , struct V_1 * V_7 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_306 ( V_14 , V_472 , V_435 , V_7 ) ;
F_307 ( V_14 , V_472 , V_435 , V_8 ) ;
V_8 = F_36 ( V_14 , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int
F_308 ( struct V_4 * V_4 , struct V_442 * V_435 ,
struct V_5 * V_6 )
{
struct V_2 * V_2 = F_14 ( V_4 ) ;
struct V_54 * V_55 = NULL ;
struct V_324 * V_325 = NULL ;
struct V_1 * V_7 = NULL ;
int V_330 ;
if ( F_309 ( V_2 ) &&
V_6 -> V_270 & V_437 &&
V_6 -> V_541 < F_310 ( V_2 ) )
F_311 ( V_2 ) ;
F_99 ( V_435 ) ;
if ( V_6 -> V_270 & V_444 )
V_6 -> V_270 &= ~ ( V_404 | V_542 ) ;
if ( ( V_6 -> V_270 & ~ ( V_543 | V_444 ) ) == 0 )
return 0 ;
if ( V_6 -> V_270 & V_543 ) {
V_325 = F_312 ( V_6 -> V_544 ) ;
if ( V_325 )
V_55 = V_325 -> V_55 ;
}
V_7 = F_105 ( F_103 ( V_2 ) , V_420 ) ;
if ( F_78 ( V_7 ) )
return F_87 ( V_7 ) ;
V_330 = F_256 ( V_2 , V_55 , V_435 , V_6 , V_325 , NULL , V_7 ) ;
if ( V_330 == 0 ) {
F_257 ( V_2 , V_6 , V_435 ) ;
F_258 ( V_2 , V_435 , V_7 ) ;
}
F_114 ( V_7 ) ;
return V_330 ;
}
static int F_313 ( struct V_67 * V_68 , struct V_2 * V_3 ,
const struct V_534 * V_264 , struct V_471 * V_472 ,
struct V_442 * V_435 , struct V_1 * V_7 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
int V_330 ;
struct V_545 args = {
. V_265 = V_14 -> V_15 ,
. V_546 = F_112 ( V_3 ) ,
. V_264 = V_264 ,
} ;
struct V_515 V_69 = {
. V_14 = V_14 ,
. V_435 = V_435 ,
. V_7 = V_7 ,
. V_268 = V_472 ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_547 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
} ;
args . V_265 = F_6 ( V_14 , V_7 ) ;
F_99 ( V_435 ) ;
F_8 ( L_30 , V_264 -> V_264 ) ;
V_330 = F_89 ( V_68 , V_14 , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
F_8 ( L_31 , V_330 ) ;
return V_330 ;
}
static void F_314 ( struct V_442 * V_435 )
{
V_435 -> V_321 |= V_358 | V_548 |
V_549 | V_550 ;
V_435 -> V_281 = V_363 | V_551 | V_552 ;
V_435 -> V_553 = 2 ;
}
static int F_315 ( struct V_67 * * V_68 , struct V_2 * V_3 ,
const struct V_534 * V_264 , struct V_471 * V_472 ,
struct V_442 * V_435 , struct V_1 * V_7 )
{
struct V_73 V_74 = { } ;
struct V_67 * V_111 = * V_68 ;
int V_8 ;
do {
V_8 = F_313 ( V_111 , V_3 , V_264 , V_472 , V_435 , V_7 ) ;
F_316 ( V_3 , V_264 , V_8 ) ;
switch ( V_8 ) {
case - V_26 :
V_8 = - V_326 ;
goto V_156;
case - V_90 :
V_8 = F_300 ( V_111 , V_3 , V_264 , V_435 , V_472 ) ;
if ( V_8 == - V_90 )
V_8 = F_36 ( F_103 ( V_3 ) , V_8 , & V_74 ) ;
goto V_156;
case - V_22 :
V_8 = - V_24 ;
if ( V_111 != * V_68 )
goto V_156;
V_111 = F_317 ( V_111 , V_3 , V_264 ) ;
if ( F_78 ( V_111 ) )
return F_87 ( V_111 ) ;
V_74 . V_80 = 1 ;
break;
default:
V_8 = F_36 ( F_103 ( V_3 ) , V_8 , & V_74 ) ;
}
} while ( V_74 . V_80 );
V_156:
if ( V_8 == 0 )
* V_68 = V_111 ;
else if ( V_111 != * V_68 )
F_318 ( V_111 ) ;
return V_8 ;
}
static int F_319 ( struct V_2 * V_3 , const struct V_534 * V_264 ,
struct V_471 * V_472 , struct V_442 * V_435 ,
struct V_1 * V_7 )
{
int V_330 ;
struct V_67 * V_111 = F_320 ( V_3 ) ;
V_330 = F_315 ( & V_111 , V_3 , V_264 , V_472 , V_435 , V_7 ) ;
if ( V_111 != F_320 ( V_3 ) ) {
F_318 ( V_111 ) ;
F_314 ( V_435 ) ;
}
return V_330 ;
}
struct V_67 *
F_321 ( struct V_2 * V_3 , const struct V_534 * V_264 ,
struct V_471 * V_472 , struct V_442 * V_435 )
{
struct V_67 * V_111 = F_320 ( V_3 ) ;
int V_330 ;
V_330 = F_315 ( & V_111 , V_3 , V_264 , V_472 , V_435 , NULL ) ;
if ( V_330 < 0 )
return F_79 ( V_330 ) ;
return ( V_111 == F_320 ( V_3 ) ) ? F_322 ( V_111 ) : V_111 ;
}
static int F_323 ( struct V_2 * V_2 ,
struct V_471 * V_472 , struct V_442 * V_435 ,
struct V_1 * V_7 )
{
struct V_67 * V_68 = F_320 ( V_2 ) ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
int V_330 ;
struct V_554 args = {
. V_265 = V_14 -> V_15 ,
. V_268 = F_112 ( V_2 ) ,
} ;
struct V_555 V_69 = {
. V_14 = V_14 ,
. V_435 = V_435 ,
. V_7 = V_7 ,
. V_268 = V_472 ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_556 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
} ;
args . V_265 = F_6 ( V_14 , V_7 ) ;
F_99 ( V_435 ) ;
F_8 ( L_32 , V_2 -> V_557 ) ;
V_330 = F_89 ( V_68 , V_14 , & V_179 , & args . V_167 ,
& V_69 . V_168 , 0 ) ;
F_8 ( L_33 , V_330 ) ;
return V_330 ;
}
static int F_324 ( struct V_2 * V_2 , struct V_471 * V_472 ,
struct V_442 * V_435 , struct V_1 * V_7 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_323 ( V_2 , V_472 , V_435 , V_7 ) ;
F_325 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_2 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_326 ( struct V_2 * V_2 , struct V_373 * V_558 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_559 args = {
. V_268 = F_112 ( V_2 ) ,
. V_265 = V_14 -> V_463 ,
} ;
struct V_560 V_69 = {
. V_14 = V_14 ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_561 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
. V_54 = V_558 -> V_55 ,
} ;
int V_281 = V_558 -> V_375 ;
int V_330 = 0 ;
if ( V_281 & V_562 )
args . V_231 |= V_254 ;
if ( F_210 ( V_2 -> V_378 ) ) {
if ( V_281 & V_563 )
args . V_231 |= V_255 | V_256 | V_564 ;
if ( V_281 & V_565 )
args . V_231 |= V_379 ;
} else {
if ( V_281 & V_563 )
args . V_231 |= V_255 | V_256 ;
if ( V_281 & V_565 )
args . V_231 |= V_257 ;
}
V_69 . V_435 = F_327 () ;
if ( V_69 . V_435 == NULL )
return - V_174 ;
V_330 = F_89 ( V_14 -> V_111 , V_14 , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
if ( ! V_330 ) {
F_211 ( V_558 , V_69 . V_231 ) ;
F_168 ( V_2 , V_69 . V_435 ) ;
}
F_328 ( V_69 . V_435 ) ;
return V_330 ;
}
static int F_329 ( struct V_2 * V_2 , struct V_373 * V_558 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_326 ( V_2 , V_558 ) ;
F_330 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_2 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_331 ( struct V_2 * V_2 , struct V_535 * V_535 ,
unsigned int V_51 , unsigned int V_566 )
{
struct V_567 args = {
. V_268 = F_112 ( V_2 ) ,
. V_51 = V_51 ,
. V_566 = V_566 ,
. V_45 = & V_535 ,
} ;
struct V_568 V_69 ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_569 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
} ;
return F_89 ( F_103 ( V_2 ) -> V_111 , F_103 ( V_2 ) , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
}
static int F_332 ( struct V_2 * V_2 , struct V_535 * V_535 ,
unsigned int V_51 , unsigned int V_566 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_331 ( V_2 , V_535 , V_51 , V_566 ) ;
F_333 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_2 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int
F_334 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_5 * V_6 ,
int V_236 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_1 V_17 , * V_443 = NULL ;
struct V_324 * V_325 ;
struct V_76 * V_77 ;
int V_330 = 0 ;
V_325 = F_335 ( V_4 , V_207 , NULL ) ;
if ( F_78 ( V_325 ) )
return F_87 ( V_325 ) ;
V_443 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
if ( ! ( V_14 -> V_15 [ 2 ] & V_406 ) )
V_6 -> V_10 &= ~ F_109 () ;
V_77 = F_260 ( V_3 , V_325 , V_236 , V_6 , V_443 , NULL ) ;
if ( F_78 ( V_77 ) ) {
V_330 = F_87 ( V_77 ) ;
goto V_156;
}
V_156:
F_4 ( V_443 ) ;
F_189 ( V_325 ) ;
return V_330 ;
}
static int F_336 ( struct V_2 * V_3 , const struct V_534 * V_264 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_570 args = {
. V_268 = F_112 ( V_3 ) ,
. V_264 = * V_264 ,
} ;
struct V_571 V_69 = {
. V_14 = V_14 ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_572 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
} ;
unsigned long V_128 = V_175 ;
int V_330 ;
V_330 = F_89 ( V_14 -> V_111 , V_14 , & V_179 , & args . V_167 , & V_69 . V_168 , 1 ) ;
if ( V_330 == 0 )
F_90 ( V_3 , & V_69 . V_187 , V_128 ) ;
return V_330 ;
}
static int F_337 ( struct V_2 * V_3 , const struct V_534 * V_264 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_336 ( V_3 , V_264 ) ;
F_338 ( V_3 , V_264 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_3 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static void F_339 ( struct V_178 * V_179 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_570 * args = V_179 -> V_338 ;
struct V_571 * V_69 = V_179 -> V_339 ;
V_69 -> V_14 = V_14 ;
V_179 -> V_335 = & V_336 [ V_572 ] ;
F_51 ( & args -> V_167 , & V_69 -> V_168 , 1 ) ;
F_99 ( V_69 -> V_573 ) ;
}
static void F_340 ( struct V_115 * V_116 , struct V_574 * V_165 )
{
F_73 ( F_180 ( V_165 -> V_4 -> V_247 ) -> V_58 ,
& V_165 -> args . V_167 ,
& V_165 -> V_69 . V_168 ,
V_116 ) ;
}
static int F_341 ( struct V_115 * V_116 , struct V_2 * V_3 )
{
struct V_574 * V_165 = V_116 -> V_575 ;
struct V_571 * V_69 = & V_165 -> V_69 ;
if ( ! F_71 ( V_116 , & V_69 -> V_168 ) )
return 0 ;
if ( F_43 ( V_116 , V_69 -> V_14 , NULL ,
& V_165 -> V_63 ) == - V_121 )
return 0 ;
if ( V_116 -> V_120 == 0 )
F_90 ( V_3 , & V_69 -> V_187 , V_69 -> V_573 -> V_383 ) ;
return 1 ;
}
static void F_342 ( struct V_178 * V_179 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_576 * V_430 = V_179 -> V_338 ;
struct V_577 * V_69 = V_179 -> V_339 ;
V_179 -> V_335 = & V_336 [ V_578 ] ;
V_69 -> V_14 = V_14 ;
F_51 ( & V_430 -> V_167 , & V_69 -> V_168 , 1 ) ;
}
static void F_343 ( struct V_115 * V_116 , struct V_579 * V_165 )
{
F_73 ( F_103 ( V_165 -> V_580 ) -> V_58 ,
& V_165 -> args . V_167 ,
& V_165 -> V_69 . V_168 ,
V_116 ) ;
}
static int F_344 ( struct V_115 * V_116 , struct V_2 * V_580 ,
struct V_2 * V_581 )
{
struct V_579 * V_165 = V_116 -> V_575 ;
struct V_577 * V_69 = & V_165 -> V_69 ;
if ( ! F_71 ( V_116 , & V_69 -> V_168 ) )
return 0 ;
if ( F_43 ( V_116 , V_69 -> V_14 , NULL , & V_165 -> V_63 ) == - V_121 )
return 0 ;
if ( V_116 -> V_120 == 0 ) {
F_90 ( V_580 , & V_69 -> V_582 , V_69 -> V_583 -> V_383 ) ;
if ( V_581 != V_580 )
F_90 ( V_581 , & V_69 -> V_584 , V_69 -> V_585 -> V_383 ) ;
}
return 1 ;
}
static int F_345 ( struct V_2 * V_2 , struct V_2 * V_3 , const struct V_534 * V_264 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_586 V_430 = {
. V_268 = F_112 ( V_2 ) ,
. V_546 = F_112 ( V_3 ) ,
. V_264 = V_264 ,
. V_265 = V_14 -> V_15 ,
} ;
struct V_587 V_69 = {
. V_14 = V_14 ,
. V_7 = NULL ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_588 ] ,
. V_338 = & V_430 ,
. V_339 = & V_69 ,
} ;
int V_330 = - V_174 ;
V_69 . V_435 = F_327 () ;
if ( V_69 . V_435 == NULL )
goto V_156;
V_69 . V_7 = F_105 ( V_14 , V_420 ) ;
if ( F_78 ( V_69 . V_7 ) ) {
V_330 = F_87 ( V_69 . V_7 ) ;
goto V_156;
}
V_430 . V_265 = F_6 ( V_14 , V_69 . V_7 ) ;
V_330 = F_89 ( V_14 -> V_111 , V_14 , & V_179 , & V_430 . V_167 , & V_69 . V_168 , 1 ) ;
if ( ! V_330 ) {
F_90 ( V_3 , & V_69 . V_187 , V_69 . V_435 -> V_383 ) ;
V_330 = F_346 ( V_2 , V_69 . V_435 ) ;
if ( ! V_330 )
F_258 ( V_2 , V_69 . V_435 , V_69 . V_7 ) ;
}
F_114 ( V_69 . V_7 ) ;
V_156:
F_328 ( V_69 . V_435 ) ;
return V_330 ;
}
static int F_347 ( struct V_2 * V_2 , struct V_2 * V_3 , const struct V_534 * V_264 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_36 ( F_103 ( V_2 ) ,
F_345 ( V_2 , V_3 , V_264 ) ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static struct V_589 * F_348 ( struct V_2 * V_3 ,
const struct V_534 * V_264 , struct V_5 * V_6 , T_1 V_590 )
{
struct V_589 * V_165 ;
V_165 = F_104 ( sizeof( * V_165 ) , V_420 ) ;
if ( V_165 != NULL ) {
struct V_13 * V_14 = F_103 ( V_3 ) ;
V_165 -> V_7 = F_105 ( V_14 , V_420 ) ;
if ( F_78 ( V_165 -> V_7 ) )
goto V_334;
V_165 -> V_179 . V_335 = & V_336 [ V_591 ] ;
V_165 -> V_179 . V_338 = & V_165 -> V_430 ;
V_165 -> V_179 . V_339 = & V_165 -> V_69 ;
V_165 -> V_430 . V_546 = F_112 ( V_3 ) ;
V_165 -> V_430 . V_14 = V_14 ;
V_165 -> V_430 . V_264 = V_264 ;
V_165 -> V_430 . V_40 = V_6 ;
V_165 -> V_430 . V_590 = V_590 ;
V_165 -> V_430 . V_265 = F_6 ( V_14 , V_165 -> V_7 ) ;
V_165 -> V_430 . V_251 = F_109 () ;
V_165 -> V_69 . V_14 = V_14 ;
V_165 -> V_69 . V_268 = & V_165 -> V_268 ;
V_165 -> V_69 . V_435 = & V_165 -> V_435 ;
V_165 -> V_69 . V_7 = V_165 -> V_7 ;
F_99 ( V_165 -> V_69 . V_435 ) ;
}
return V_165 ;
V_334:
F_115 ( V_165 ) ;
return NULL ;
}
static int F_349 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_589 * V_165 )
{
int V_330 = F_89 ( F_103 ( V_3 ) -> V_111 , F_103 ( V_3 ) , & V_165 -> V_179 ,
& V_165 -> V_430 . V_167 , & V_165 -> V_69 . V_168 , 1 ) ;
if ( V_330 == 0 ) {
F_90 ( V_3 , & V_165 -> V_69 . V_592 ,
V_165 -> V_69 . V_435 -> V_383 ) ;
V_330 = F_350 ( V_4 , V_165 -> V_69 . V_268 , V_165 -> V_69 . V_435 , V_165 -> V_69 . V_7 ) ;
}
return V_330 ;
}
static void F_351 ( struct V_589 * V_165 )
{
F_114 ( V_165 -> V_7 ) ;
F_115 ( V_165 ) ;
}
static int F_352 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_535 * V_535 , unsigned int V_12 , struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_589 * V_165 ;
int V_330 = - V_593 ;
if ( V_12 > V_594 )
goto V_156;
V_330 = - V_174 ;
V_165 = F_348 ( V_3 , & V_4 -> V_11 , V_6 , V_595 ) ;
if ( V_165 == NULL )
goto V_156;
V_165 -> V_179 . V_335 = & V_336 [ V_596 ] ;
V_165 -> V_430 . V_272 . V_597 . V_45 = & V_535 ;
V_165 -> V_430 . V_272 . V_597 . V_12 = V_12 ;
V_165 -> V_430 . V_7 = V_7 ;
V_330 = F_349 ( V_3 , V_4 , V_165 ) ;
F_351 ( V_165 ) ;
V_156:
return V_330 ;
}
static int F_353 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_535 * V_535 , unsigned int V_12 , struct V_5 * V_6 )
{
struct V_73 V_74 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
do {
V_8 = F_352 ( V_3 , V_4 , V_535 , V_12 , V_6 , V_7 ) ;
F_354 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_3 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_355 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_589 * V_165 ;
int V_330 = - V_174 ;
V_165 = F_348 ( V_3 , & V_4 -> V_11 , V_6 , V_48 ) ;
if ( V_165 == NULL )
goto V_156;
V_165 -> V_430 . V_7 = V_7 ;
V_330 = F_349 ( V_3 , V_4 , V_165 ) ;
F_351 ( V_165 ) ;
V_156:
return V_330 ;
}
static int F_356 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_73 V_74 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
if ( ! ( V_14 -> V_15 [ 2 ] & V_406 ) )
V_6 -> V_10 &= ~ F_109 () ;
do {
V_8 = F_355 ( V_3 , V_4 , V_6 , V_7 ) ;
F_357 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_3 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_358 ( struct V_4 * V_4 , struct V_54 * V_55 ,
T_2 V_36 , struct V_535 * * V_45 , unsigned int V_52 , bool V_598 )
{
struct V_2 * V_3 = F_14 ( V_4 ) ;
struct V_38 args = {
. V_268 = F_112 ( V_3 ) ,
. V_45 = V_45 ,
. V_51 = 0 ,
. V_52 = V_52 ,
. V_265 = F_103 ( F_14 ( V_4 ) ) -> V_15 ,
. V_598 = V_598 ,
} ;
struct V_599 V_69 ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_600 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
. V_54 = V_55 ,
} ;
int V_330 ;
F_8 ( L_34 , V_34 ,
V_4 ,
( unsigned long long ) V_36 ) ;
F_9 ( V_36 , F_91 ( V_3 ) -> V_601 , V_4 , & args ) ;
V_69 . V_51 = args . V_51 ;
V_330 = F_89 ( F_103 ( V_3 ) -> V_111 , F_103 ( V_3 ) , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
if ( V_330 >= 0 ) {
memcpy ( F_91 ( V_3 ) -> V_601 , V_69 . V_37 . V_165 , V_602 ) ;
V_330 += args . V_51 ;
}
F_359 ( V_3 ) ;
F_8 ( L_35 , V_34 , V_330 ) ;
return V_330 ;
}
static int F_360 ( struct V_4 * V_4 , struct V_54 * V_55 ,
T_2 V_36 , struct V_535 * * V_45 , unsigned int V_52 , bool V_598 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_358 ( V_4 , V_55 , V_36 ,
V_45 , V_52 , V_598 ) ;
F_361 ( F_14 ( V_4 ) , V_8 ) ;
V_8 = F_36 ( F_103 ( F_14 ( V_4 ) ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_362 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 , T_10 V_603 )
{
struct V_589 * V_165 ;
int V_281 = V_6 -> V_10 ;
int V_330 = - V_174 ;
V_165 = F_348 ( V_3 , & V_4 -> V_11 , V_6 , V_604 ) ;
if ( V_165 == NULL )
goto V_156;
if ( F_363 ( V_281 ) )
V_165 -> V_430 . V_590 = V_605 ;
else if ( F_364 ( V_281 ) ) {
V_165 -> V_430 . V_590 = V_606 ;
V_165 -> V_430 . V_272 . V_607 . V_608 = F_365 ( V_603 ) ;
V_165 -> V_430 . V_272 . V_607 . V_609 = F_366 ( V_603 ) ;
}
else if ( F_367 ( V_281 ) ) {
V_165 -> V_430 . V_590 = V_610 ;
V_165 -> V_430 . V_272 . V_607 . V_608 = F_365 ( V_603 ) ;
V_165 -> V_430 . V_272 . V_607 . V_609 = F_366 ( V_603 ) ;
} else if ( ! F_368 ( V_281 ) ) {
V_330 = - V_27 ;
goto V_334;
}
V_165 -> V_430 . V_7 = V_7 ;
V_330 = F_349 ( V_3 , V_4 , V_165 ) ;
V_334:
F_351 ( V_165 ) ;
V_156:
return V_330 ;
}
static int F_369 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , T_10 V_603 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_73 V_74 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
if ( ! ( V_14 -> V_15 [ 2 ] & V_406 ) )
V_6 -> V_10 &= ~ F_109 () ;
do {
V_8 = F_362 ( V_3 , V_4 , V_6 , V_7 , V_603 ) ;
F_370 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_3 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_371 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_611 * V_612 )
{
struct V_613 args = {
. V_268 = V_472 ,
. V_265 = V_14 -> V_15 ,
} ;
struct V_614 V_69 = {
. V_612 = V_612 ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_615 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
} ;
F_99 ( V_612 -> V_435 ) ;
return F_89 ( V_14 -> V_111 , V_14 , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
}
static int F_372 ( struct V_13 * V_14 , struct V_471 * V_472 , struct V_611 * V_612 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_36 ( V_14 ,
F_371 ( V_14 , V_472 , V_612 ) ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_373 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_512 * V_616 )
{
struct V_617 args = {
. V_268 = V_472 ,
. V_265 = V_14 -> V_15 ,
} ;
struct V_618 V_69 = {
. V_616 = V_616 ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_619 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
} ;
return F_89 ( V_14 -> V_111 , V_14 , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
}
static int F_297 ( struct V_13 * V_14 , struct V_471 * V_472 , struct V_512 * V_616 )
{
struct V_73 V_74 = { } ;
unsigned long V_620 = V_175 ;
int V_8 ;
do {
V_8 = F_373 ( V_14 , V_472 , V_616 ) ;
F_374 ( V_14 , V_472 , V_616 -> V_435 , V_8 ) ;
if ( V_8 == 0 ) {
F_375 ( V_14 -> V_58 ,
V_616 -> V_621 * V_101 ,
V_620 ) ;
break;
}
V_8 = F_36 ( V_14 , V_8 , & V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_376 ( struct V_13 * V_14 , struct V_471 * V_472 , struct V_512 * V_616 )
{
int error ;
F_99 ( V_616 -> V_435 ) ;
error = F_297 ( V_14 , V_472 , V_616 ) ;
if ( error == 0 ) {
V_14 -> V_622 = V_616 -> V_623 ;
F_377 ( V_14 , V_472 , V_616 ) ;
}
return error ;
}
static int F_378 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_624 * V_625 )
{
struct V_626 args = {
. V_268 = V_472 ,
. V_265 = V_14 -> V_15 ,
} ;
struct V_627 V_69 = {
. V_625 = V_625 ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_628 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
} ;
if ( ( args . V_265 [ 0 ] & V_629 [ 0 ] ) == 0 ) {
memset ( V_625 , 0 , sizeof( * V_625 ) ) ;
return 0 ;
}
F_99 ( V_625 -> V_435 ) ;
return F_89 ( V_14 -> V_111 , V_14 , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
}
static int F_379 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_624 * V_625 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_36 ( V_14 ,
F_378 ( V_14 , V_472 , V_625 ) ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
int F_380 ( T_4 * V_53 ,
const struct V_324 * V_325 ,
const struct V_438 * V_439 ,
T_6 V_205 )
{
return F_267 ( V_325 -> V_77 , V_205 , V_439 , V_53 , NULL ) ;
}
static bool F_381 ( T_4 * V_53 ,
const struct V_324 * V_325 ,
const struct V_438 * V_439 ,
T_6 V_205 )
{
T_4 V_630 ;
if ( F_380 ( & V_630 , V_325 , V_439 , V_205 ) == - V_35 )
return true ;
return F_155 ( V_53 , & V_630 ) ;
}
static bool F_382 ( int V_8 )
{
switch ( V_8 ) {
case - V_81 :
case - V_82 :
case - V_84 :
case - V_88 :
case - V_106 :
case - V_86 :
case - V_83 :
return true ;
}
return false ;
}
static int F_383 ( struct V_115 * V_116 , struct V_631 * V_632 )
{
struct V_13 * V_14 = F_103 ( V_632 -> V_2 ) ;
F_384 ( V_632 , V_116 -> V_120 ) ;
if ( V_116 -> V_120 < 0 ) {
struct V_73 V_74 = {
. V_2 = V_632 -> V_2 ,
. V_77 = V_632 -> args . V_633 -> V_77 ,
. V_53 = & V_632 -> args . V_53 ,
} ;
V_116 -> V_120 = F_39 ( V_116 ,
V_14 , V_116 -> V_120 , & V_74 ) ;
if ( V_74 . V_80 ) {
F_66 ( V_116 ) ;
return - V_121 ;
}
}
if ( V_116 -> V_120 > 0 )
F_49 ( V_14 , V_632 -> V_128 ) ;
return 0 ;
}
static bool F_385 ( struct V_115 * V_116 ,
struct V_634 * args )
{
if ( ! F_382 ( V_116 -> V_120 ) ||
F_381 ( & args -> V_53 ,
args -> V_633 ,
args -> V_635 ,
V_207 ) )
return false ;
F_66 ( V_116 ) ;
return true ;
}
static int F_386 ( struct V_115 * V_116 , struct V_631 * V_632 )
{
F_8 ( L_36 , V_34 ) ;
if ( ! F_71 ( V_116 , & V_632 -> V_69 . V_168 ) )
return - V_121 ;
if ( F_385 ( V_116 , & V_632 -> args ) )
return - V_121 ;
if ( V_116 -> V_120 > 0 )
F_359 ( V_632 -> V_2 ) ;
return V_632 -> V_636 ? V_632 -> V_636 ( V_116 , V_632 ) :
F_383 ( V_116 , V_632 ) ;
}
static void F_387 ( struct V_631 * V_632 ,
struct V_178 * V_179 )
{
V_632 -> V_128 = V_175 ;
if ( ! V_632 -> V_636 )
V_632 -> V_636 = F_383 ;
V_179 -> V_335 = & V_336 [ V_637 ] ;
F_51 ( & V_632 -> args . V_167 , & V_632 -> V_69 . V_168 , 0 ) ;
}
static int F_388 ( struct V_115 * V_116 ,
struct V_631 * V_632 )
{
if ( F_73 ( F_103 ( V_632 -> V_2 ) -> V_58 ,
& V_632 -> args . V_167 ,
& V_632 -> V_69 . V_168 ,
V_116 ) )
return 0 ;
if ( F_380 ( & V_632 -> args . V_53 , V_632 -> args . V_633 ,
V_632 -> args . V_635 ,
V_632 -> V_638 ) == - V_35 )
return - V_35 ;
if ( F_389 ( F_38 ( V_639 , & V_632 -> args . V_633 -> V_236 ) ) )
return - V_35 ;
return 0 ;
}
static int F_390 ( struct V_115 * V_116 ,
struct V_631 * V_632 )
{
struct V_2 * V_2 = V_632 -> V_2 ;
F_391 ( V_632 , V_116 -> V_120 ) ;
if ( V_116 -> V_120 < 0 ) {
struct V_73 V_74 = {
. V_2 = V_632 -> V_2 ,
. V_77 = V_632 -> args . V_633 -> V_77 ,
. V_53 = & V_632 -> args . V_53 ,
} ;
V_116 -> V_120 = F_39 ( V_116 ,
F_103 ( V_2 ) , V_116 -> V_120 ,
& V_74 ) ;
if ( V_74 . V_80 ) {
F_66 ( V_116 ) ;
return - V_121 ;
}
}
if ( V_116 -> V_120 >= 0 ) {
F_49 ( F_103 ( V_2 ) , V_632 -> V_128 ) ;
F_392 ( V_632 ) ;
}
return 0 ;
}
static bool F_393 ( struct V_115 * V_116 ,
struct V_634 * args )
{
if ( ! F_382 ( V_116 -> V_120 ) ||
F_381 ( & args -> V_53 ,
args -> V_633 ,
args -> V_635 ,
V_208 ) )
return false ;
F_66 ( V_116 ) ;
return true ;
}
static int F_394 ( struct V_115 * V_116 , struct V_631 * V_632 )
{
if ( ! F_71 ( V_116 , & V_632 -> V_69 . V_168 ) )
return - V_121 ;
if ( F_393 ( V_116 , & V_632 -> args ) )
return - V_121 ;
return V_632 -> V_636 ? V_632 -> V_636 ( V_116 , V_632 ) :
F_390 ( V_116 , V_632 ) ;
}
static
bool F_395 ( struct V_631 * V_632 )
{
if ( V_632 -> V_640 != NULL || V_632 -> V_641 != NULL )
return false ;
return F_237 ( V_632 -> V_2 , V_207 ) == 0 ;
}
static void F_396 ( struct V_631 * V_632 ,
struct V_178 * V_179 )
{
struct V_13 * V_14 = F_103 ( V_632 -> V_2 ) ;
if ( ! F_395 ( V_632 ) ) {
V_632 -> args . V_265 = NULL ;
V_632 -> V_69 . V_435 = NULL ;
} else
V_632 -> args . V_265 = V_14 -> V_463 ;
if ( ! V_632 -> V_636 )
V_632 -> V_636 = F_390 ;
V_632 -> V_69 . V_14 = V_14 ;
V_632 -> V_128 = V_175 ;
V_179 -> V_335 = & V_336 [ V_642 ] ;
F_51 ( & V_632 -> args . V_167 , & V_632 -> V_69 . V_168 , 1 ) ;
}
static void F_397 ( struct V_115 * V_116 , struct V_643 * V_165 )
{
F_73 ( F_103 ( V_165 -> V_2 ) -> V_58 ,
& V_165 -> args . V_167 ,
& V_165 -> V_69 . V_168 ,
V_116 ) ;
}
static int F_398 ( struct V_115 * V_116 , struct V_643 * V_165 )
{
struct V_2 * V_2 = V_165 -> V_2 ;
F_399 ( V_165 , V_116 -> V_120 ) ;
if ( F_43 ( V_116 , F_103 ( V_2 ) ,
NULL , NULL ) == - V_121 ) {
F_66 ( V_116 ) ;
return - V_121 ;
}
return 0 ;
}
static int F_400 ( struct V_115 * V_116 , struct V_643 * V_165 )
{
if ( ! F_71 ( V_116 , & V_165 -> V_69 . V_168 ) )
return - V_121 ;
return V_165 -> V_644 ( V_116 , V_165 ) ;
}
static void F_401 ( struct V_643 * V_165 , struct V_178 * V_179 )
{
struct V_13 * V_14 = F_103 ( V_165 -> V_2 ) ;
if ( V_165 -> V_644 == NULL )
V_165 -> V_644 = F_398 ;
V_165 -> V_69 . V_14 = V_14 ;
V_179 -> V_335 = & V_336 [ V_645 ] ;
F_51 ( & V_165 -> args . V_167 , & V_165 -> V_69 . V_168 , 1 ) ;
}
static void F_402 ( void * V_163 )
{
struct V_646 * V_165 = V_163 ;
struct V_58 * V_75 = V_165 -> V_111 ;
if ( F_403 ( & V_75 -> V_647 ) > 1 )
F_404 ( V_75 ) ;
F_405 ( V_75 ) ;
F_115 ( V_165 ) ;
}
static void F_406 ( struct V_115 * V_116 , void * V_163 )
{
struct V_646 * V_165 = V_163 ;
struct V_58 * V_75 = V_165 -> V_111 ;
unsigned long V_128 = V_165 -> V_128 ;
F_407 ( V_75 , V_116 -> V_120 ) ;
switch ( V_116 -> V_120 ) {
case 0 :
break;
case - V_91 :
F_31 ( V_75 ) ;
break;
default:
if ( F_38 ( V_648 , & V_75 -> V_649 ) == 0 )
return;
if ( V_116 -> V_120 != V_650 ) {
F_29 ( V_75 ) ;
return;
}
F_408 ( V_75 ) ;
}
F_45 ( V_75 , V_128 ) ;
}
static int F_409 ( struct V_58 * V_75 , struct V_54 * V_55 , unsigned V_651 )
{
struct V_178 V_179 = {
. V_335 = & V_336 [ V_652 ] ,
. V_338 = V_75 ,
. V_54 = V_55 ,
} ;
struct V_646 * V_165 ;
if ( V_651 == 0 )
return 0 ;
if ( ! F_410 ( & V_75 -> V_647 ) )
return - V_35 ;
V_165 = F_302 ( sizeof( * V_165 ) , V_327 ) ;
if ( V_165 == NULL ) {
F_405 ( V_75 ) ;
return - V_174 ;
}
V_165 -> V_111 = V_75 ;
V_165 -> V_128 = V_175 ;
return F_411 ( V_75 -> V_123 , & V_179 , V_653 ,
& V_654 , V_165 ) ;
}
static int F_412 ( struct V_58 * V_75 , struct V_54 * V_55 )
{
struct V_178 V_179 = {
. V_335 = & V_336 [ V_652 ] ,
. V_338 = V_75 ,
. V_54 = V_55 ,
} ;
unsigned long V_620 = V_175 ;
int V_330 ;
V_330 = F_413 ( V_75 -> V_123 , & V_179 , V_653 ) ;
if ( V_330 < 0 )
return V_330 ;
F_45 ( V_75 , V_620 ) ;
return 0 ;
}
static inline int F_414 ( struct V_13 * V_14 )
{
return V_14 -> V_107 & V_488 ;
}
static int F_415 ( const void * V_655 , T_9 V_656 ,
struct V_535 * * V_45 )
{
struct V_535 * V_657 , * * V_658 ;
int V_659 = 0 ;
T_9 V_12 ;
V_658 = V_45 ;
do {
V_12 = F_416 ( T_9 , V_660 , V_656 ) ;
V_657 = F_301 ( V_420 ) ;
if ( V_657 == NULL )
goto V_661;
memcpy ( F_417 ( V_657 ) , V_655 , V_12 ) ;
V_655 += V_12 ;
V_656 -= V_12 ;
* V_45 ++ = V_657 ;
V_659 ++ ;
} while ( V_656 != 0 );
return V_659 ;
V_661:
for(; V_659 > 0 ; V_659 -- )
F_305 ( V_658 [ V_659 - 1 ] ) ;
return - V_174 ;
}
static void F_418 ( struct V_2 * V_2 , struct V_662 * V_663 )
{
struct V_188 * V_189 = F_91 ( V_2 ) ;
F_46 ( & V_2 -> V_190 ) ;
F_115 ( V_189 -> V_664 ) ;
V_189 -> V_664 = V_663 ;
F_48 ( & V_2 -> V_190 ) ;
}
static void F_419 ( struct V_2 * V_2 )
{
F_418 ( V_2 , NULL ) ;
}
static inline T_11 F_420 ( struct V_2 * V_2 , char * V_655 , T_9 V_656 )
{
struct V_188 * V_189 = F_91 ( V_2 ) ;
struct V_662 * V_663 ;
int V_64 = - V_326 ;
F_46 ( & V_2 -> V_190 ) ;
V_663 = V_189 -> V_664 ;
if ( V_663 == NULL )
goto V_156;
if ( V_655 == NULL )
goto V_665;
if ( V_663 -> V_666 == 0 )
goto V_156;
V_64 = - V_667 ;
if ( V_663 -> V_12 > V_656 )
goto V_156;
memcpy ( V_655 , V_663 -> V_165 , V_663 -> V_12 ) ;
V_665:
V_64 = V_663 -> V_12 ;
V_156:
F_48 ( & V_2 -> V_190 ) ;
return V_64 ;
}
static void F_421 ( struct V_2 * V_2 , struct V_535 * * V_45 , T_9 V_51 , T_9 V_668 )
{
struct V_662 * V_663 ;
T_9 V_656 = sizeof( * V_663 ) + V_668 ;
if ( V_656 <= V_660 ) {
V_663 = F_302 ( V_656 , V_420 ) ;
if ( V_663 == NULL )
goto V_156;
V_663 -> V_666 = 1 ;
F_422 ( V_663 -> V_165 , V_45 , V_51 , V_668 ) ;
} else {
V_663 = F_302 ( sizeof( * V_663 ) , V_420 ) ;
if ( V_663 == NULL )
goto V_156;
V_663 -> V_666 = 0 ;
}
V_663 -> V_12 = V_668 ;
V_156:
F_418 ( V_2 , V_663 ) ;
}
static T_11 F_423 ( struct V_2 * V_2 , void * V_655 , T_9 V_656 )
{
struct V_535 * V_45 [ V_669 + 1 ] = { NULL , } ;
struct V_670 args = {
. V_268 = F_112 ( V_2 ) ,
. V_671 = V_45 ,
. V_668 = V_656 ,
} ;
struct V_672 V_69 = {
. V_668 = V_656 ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_673 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
} ;
unsigned int V_674 = F_424 ( V_656 , V_660 ) + 1 ;
int V_64 = - V_174 , V_478 ;
if ( V_674 > F_288 ( V_45 ) )
return - V_667 ;
for ( V_478 = 0 ; V_478 < V_674 ; V_478 ++ ) {
V_45 [ V_478 ] = F_301 ( V_420 ) ;
if ( ! V_45 [ V_478 ] )
goto V_334;
}
V_69 . V_675 = F_301 ( V_420 ) ;
if ( ! V_69 . V_675 )
goto V_334;
args . V_668 = V_674 * V_660 ;
F_8 ( L_37 ,
V_34 , V_655 , V_656 , V_674 , args . V_668 ) ;
V_64 = F_89 ( F_103 ( V_2 ) -> V_111 , F_103 ( V_2 ) ,
& V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
if ( V_64 )
goto V_334;
if ( V_69 . V_676 & V_677 ) {
if ( V_655 == NULL )
goto V_678;
V_64 = - V_667 ;
goto V_334;
}
F_421 ( V_2 , V_45 , V_69 . V_679 , V_69 . V_668 ) ;
if ( V_655 ) {
if ( V_69 . V_668 > V_656 ) {
V_64 = - V_667 ;
goto V_334;
}
F_422 ( V_655 , V_45 , V_69 . V_679 , V_69 . V_668 ) ;
}
V_678:
V_64 = V_69 . V_668 ;
V_334:
for ( V_478 = 0 ; V_478 < V_674 ; V_478 ++ )
if ( V_45 [ V_478 ] )
F_305 ( V_45 [ V_478 ] ) ;
if ( V_69 . V_675 )
F_305 ( V_69 . V_675 ) ;
return V_64 ;
}
static T_11 F_425 ( struct V_2 * V_2 , void * V_655 , T_9 V_656 )
{
struct V_73 V_74 = { } ;
T_11 V_64 ;
do {
V_64 = F_423 ( V_2 , V_655 , V_656 ) ;
F_426 ( V_2 , V_64 ) ;
if ( V_64 >= 0 )
break;
V_64 = F_36 ( F_103 ( V_2 ) , V_64 , & V_74 ) ;
} while ( V_74 . V_80 );
return V_64 ;
}
static T_11 F_427 ( struct V_2 * V_2 , void * V_655 , T_9 V_656 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
int V_64 ;
if ( ! F_414 ( V_14 ) )
return - V_680 ;
V_64 = F_428 ( V_14 , V_2 ) ;
if ( V_64 < 0 )
return V_64 ;
if ( F_91 ( V_2 ) -> V_191 & V_200 )
F_429 ( V_2 ) ;
V_64 = F_420 ( V_2 , V_655 , V_656 ) ;
if ( V_64 != - V_326 )
return V_64 ;
return F_425 ( V_2 , V_655 , V_656 ) ;
}
static int F_430 ( struct V_2 * V_2 , const void * V_655 , T_9 V_656 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_535 * V_45 [ V_669 ] ;
struct V_681 V_430 = {
. V_268 = F_112 ( V_2 ) ,
. V_671 = V_45 ,
. V_668 = V_656 ,
} ;
struct V_682 V_69 ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_683 ] ,
. V_338 = & V_430 ,
. V_339 = & V_69 ,
} ;
unsigned int V_674 = F_424 ( V_656 , V_660 ) ;
int V_64 , V_478 ;
if ( ! F_414 ( V_14 ) )
return - V_680 ;
if ( V_674 > F_288 ( V_45 ) )
return - V_667 ;
V_478 = F_415 ( V_655 , V_656 , V_430 . V_671 ) ;
if ( V_478 < 0 )
return V_478 ;
F_159 ( V_2 ) ;
V_64 = F_89 ( V_14 -> V_111 , V_14 , & V_179 , & V_430 . V_167 , & V_69 . V_168 , 1 ) ;
for (; V_478 > 0 ; V_478 -- )
F_431 ( V_45 [ V_478 - 1 ] ) ;
F_46 ( & V_2 -> V_190 ) ;
F_91 ( V_2 ) -> V_191 |= V_192 ;
F_48 ( & V_2 -> V_190 ) ;
F_432 ( V_2 ) ;
F_429 ( V_2 ) ;
return V_64 ;
}
static int F_433 ( struct V_2 * V_2 , const void * V_655 , T_9 V_656 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_430 ( V_2 , V_655 , V_656 ) ;
F_434 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_2 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_435 ( struct V_2 * V_2 , void * V_655 ,
T_9 V_656 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_442 V_435 ;
struct V_1 V_7 = { 0 , 0 , V_656 , V_655 } ;
T_1 V_265 [ 3 ] = { 0 , 0 , V_408 } ;
struct V_538 V_430 = {
. V_268 = F_112 ( V_2 ) ,
. V_265 = V_265 ,
} ;
struct V_539 V_69 = {
. V_435 = & V_435 ,
. V_7 = & V_7 ,
. V_14 = V_14 ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_540 ] ,
. V_338 = & V_430 ,
. V_339 = & V_69 ,
} ;
int V_64 ;
F_99 ( & V_435 ) ;
V_64 = F_89 ( V_14 -> V_111 , V_14 , & V_179 , & V_430 . V_167 , & V_69 . V_168 , 0 ) ;
if ( V_64 )
return V_64 ;
if ( ! ( V_435 . V_321 & V_684 ) )
return - V_326 ;
if ( V_656 < V_7 . V_12 )
return - V_667 ;
return 0 ;
}
static int F_436 ( struct V_2 * V_2 , void * V_655 ,
T_9 V_656 )
{
struct V_73 V_74 = { } ;
int V_8 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_680 ;
do {
V_8 = F_435 ( V_2 , V_655 , V_656 ) ;
F_437 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_2 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_438 ( struct V_2 * V_2 ,
struct V_1 * V_443 ,
struct V_442 * V_435 ,
struct V_1 * V_419 )
{
struct V_5 V_6 = { 0 } ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
const T_1 V_265 [ 3 ] = { 0 , 0 , V_408 } ;
struct V_429 V_430 = {
. V_268 = F_112 ( V_2 ) ,
. V_436 = & V_6 ,
. V_14 = V_14 ,
. V_265 = V_265 ,
. V_7 = V_443 ,
} ;
struct V_431 V_69 = {
. V_435 = V_435 ,
. V_7 = V_419 ,
. V_14 = V_14 ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_432 ] ,
. V_338 = & V_430 ,
. V_339 = & V_69 ,
} ;
int V_330 ;
F_19 ( & V_430 . V_53 , & V_441 ) ;
V_330 = F_89 ( V_14 -> V_111 , V_14 , & V_179 , & V_430 . V_167 , & V_69 . V_168 , 1 ) ;
if ( V_330 )
F_8 ( L_38 , V_34 , V_330 ) ;
return V_330 ;
}
static int F_439 ( struct V_2 * V_2 ,
struct V_1 * V_443 ,
struct V_442 * V_435 ,
struct V_1 * V_419 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_438 ( V_2 , V_443 ,
V_435 , V_419 ) ;
F_440 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_2 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int
F_441 ( struct V_2 * V_2 , const void * V_655 , T_9 V_656 )
{
struct V_1 V_443 , * V_419 = NULL ;
struct V_442 V_435 ;
struct V_54 * V_55 ;
int V_330 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_680 ;
F_99 ( & V_435 ) ;
V_443 . V_685 = 0 ;
V_443 . V_686 = 0 ;
V_443 . V_7 = ( char * ) V_655 ;
V_443 . V_12 = V_656 ;
V_55 = F_442 () ;
if ( F_78 ( V_55 ) )
return F_87 ( V_55 ) ;
V_419 = F_105 ( F_103 ( V_2 ) , V_420 ) ;
if ( F_78 ( V_419 ) ) {
V_330 = - F_87 ( V_419 ) ;
goto V_156;
}
V_330 = F_439 ( V_2 , & V_443 , & V_435 , V_419 ) ;
if ( V_330 == 0 )
F_258 ( V_2 , & V_435 , V_419 ) ;
F_114 ( V_419 ) ;
V_156:
F_232 ( V_55 ) ;
return V_330 ;
}
static void F_443 ( const struct V_58 * V_75 ,
T_12 * V_687 )
{
T_3 V_271 [ 2 ] ;
if ( F_38 ( V_688 , & V_75 -> V_119 ) ) {
V_271 [ 0 ] = F_444 ( V_689 ) ;
V_271 [ 1 ] = F_444 ( V_689 ) ;
} else {
struct V_690 * V_691 = F_445 ( V_75 -> V_692 , V_693 ) ;
T_2 V_694 = F_110 ( V_691 -> V_695 ) ;
V_271 [ 0 ] = F_444 ( V_694 >> 32 ) ;
V_271 [ 1 ] = F_444 ( V_694 ) ;
}
memcpy ( V_687 -> V_165 , V_271 , sizeof( V_687 -> V_165 ) ) ;
}
static int
F_446 ( struct V_58 * V_75 )
{
T_9 V_12 ;
char * V_696 ;
if ( V_75 -> V_697 != NULL )
return 0 ;
F_153 () ;
V_12 = 14 + strlen ( V_75 -> V_698 ) + 1 +
strlen ( F_447 ( V_75 -> V_123 , V_699 ) ) +
1 +
strlen ( F_447 ( V_75 -> V_123 , V_700 ) ) +
1 ;
F_156 () ;
if ( V_12 > V_701 + 1 )
return - V_27 ;
V_696 = F_302 ( V_12 , V_420 ) ;
if ( ! V_696 )
return - V_174 ;
F_153 () ;
F_448 ( V_696 , V_12 , L_39 ,
V_75 -> V_698 ,
F_447 ( V_75 -> V_123 , V_699 ) ,
F_447 ( V_75 -> V_123 , V_700 ) ) ;
F_156 () ;
V_75 -> V_697 = V_696 ;
return 0 ;
}
static int
F_449 ( struct V_58 * V_75 )
{
T_9 V_12 ;
char * V_696 ;
V_12 = 10 + 10 + 1 + 10 + 1 +
strlen ( V_702 ) + 1 +
strlen ( V_75 -> V_123 -> V_703 ) + 1 ;
if ( V_12 > V_701 + 1 )
return - V_27 ;
V_696 = F_302 ( V_12 , V_420 ) ;
if ( ! V_696 )
return - V_174 ;
F_448 ( V_696 , V_12 , L_40 ,
V_75 -> V_704 -> V_705 , V_75 -> V_474 ,
V_702 ,
V_75 -> V_123 -> V_703 ) ;
V_75 -> V_697 = V_696 ;
return 0 ;
}
static int
F_450 ( struct V_58 * V_75 )
{
T_9 V_12 ;
char * V_696 ;
if ( V_75 -> V_697 != NULL )
return 0 ;
if ( V_702 [ 0 ] != '\0' )
return F_449 ( V_75 ) ;
V_12 = 10 + 10 + 1 + 10 + 1 +
strlen ( V_75 -> V_123 -> V_703 ) + 1 ;
if ( V_12 > V_701 + 1 )
return - V_27 ;
V_696 = F_302 ( V_12 , V_420 ) ;
if ( ! V_696 )
return - V_174 ;
F_448 ( V_696 , V_12 , L_41 ,
V_75 -> V_704 -> V_705 , V_75 -> V_474 ,
V_75 -> V_123 -> V_703 ) ;
V_75 -> V_697 = V_696 ;
return 0 ;
}
static unsigned int
F_451 ( const struct V_58 * V_75 , char * V_655 , T_9 V_12 )
{
if ( strchr ( V_75 -> V_698 , ':' ) != NULL )
return F_448 ( V_655 , V_12 , L_42 ) ;
else
return F_448 ( V_655 , V_12 , L_43 ) ;
}
static void F_452 ( struct V_115 * V_116 , void * V_163 )
{
struct V_706 * V_707 = V_163 ;
if ( V_116 -> V_120 == 0 )
V_707 -> V_708 = F_230 ( V_116 -> V_709 -> V_710 ) ;
}
int F_453 ( struct V_58 * V_75 , T_1 V_711 ,
unsigned short V_712 , struct V_54 * V_55 ,
struct V_713 * V_69 )
{
T_12 V_714 ;
struct V_706 V_715 = {
. V_714 = & V_714 ,
. V_716 = V_711 ,
. V_717 = V_75 ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_718 ] ,
. V_338 = & V_715 ,
. V_339 = V_69 ,
. V_54 = V_55 ,
} ;
struct V_115 * V_116 ;
struct V_180 V_340 = {
. V_182 = V_75 -> V_123 ,
. V_178 = & V_179 ,
. V_183 = & V_719 ,
. V_185 = & V_715 ,
. V_236 = V_653 ,
} ;
int V_330 ;
F_443 ( V_75 , & V_714 ) ;
if ( F_38 ( V_720 , & V_75 -> V_721 ) )
V_330 = F_450 ( V_75 ) ;
else
V_330 = F_446 ( V_75 ) ;
if ( V_330 )
goto V_156;
V_715 . V_722 =
F_451 ( V_75 ,
V_715 . V_723 ,
sizeof( V_715 . V_723 ) ) ;
V_715 . V_724 = F_448 ( V_715 . V_725 ,
sizeof( V_715 . V_725 ) , L_44 ,
V_75 -> V_698 , V_712 >> 8 , V_712 & 255 ) ;
F_8 ( L_45 ,
V_75 -> V_123 -> V_124 -> V_726 -> V_727 ,
V_75 -> V_697 ) ;
V_116 = F_86 ( & V_340 ) ;
if ( F_78 ( V_116 ) ) {
V_330 = F_87 ( V_116 ) ;
goto V_156;
}
V_330 = V_116 -> V_120 ;
if ( V_715 . V_708 ) {
V_75 -> V_728 = F_454 ( V_715 . V_708 ) ;
F_232 ( V_715 . V_708 ) ;
}
F_88 ( V_116 ) ;
V_156:
F_455 ( V_75 , V_330 ) ;
F_8 ( L_46 , V_330 ) ;
return V_330 ;
}
int F_456 ( struct V_58 * V_75 ,
struct V_713 * V_430 ,
struct V_54 * V_55 )
{
struct V_178 V_179 = {
. V_335 = & V_336 [ V_729 ] ,
. V_338 = V_430 ,
. V_54 = V_55 ,
} ;
int V_330 ;
F_8 ( L_47 ,
V_75 -> V_123 -> V_124 -> V_726 -> V_727 ,
V_75 -> V_259 ) ;
V_330 = F_413 ( V_75 -> V_123 , & V_179 , V_653 ) ;
F_457 ( V_75 , V_330 ) ;
F_8 ( L_48 , V_330 ) ;
return V_330 ;
}
static void F_458 ( struct V_115 * V_116 , void * V_163 )
{
struct V_730 * V_165 = V_163 ;
if ( ! F_71 ( V_116 , & V_165 -> V_69 . V_168 ) )
return;
F_459 ( & V_165 -> args , & V_165 -> V_69 , V_116 -> V_120 ) ;
if ( V_165 -> args . V_451 && V_116 -> V_120 != 0 ) {
switch( V_165 -> V_69 . V_449 ) {
default:
V_165 -> V_69 . V_449 = - V_452 ;
break;
case 0 :
V_165 -> args . V_451 = NULL ;
V_165 -> V_69 . V_453 = NULL ;
break;
case - V_82 :
case - V_81 :
case - V_83 :
case - V_84 :
case - V_106 :
case - V_454 :
case - V_23 :
V_165 -> args . V_451 = NULL ;
V_165 -> V_69 . V_453 = NULL ;
V_165 -> V_69 . V_449 = 0 ;
F_66 ( V_116 ) ;
return;
}
}
switch ( V_116 -> V_120 ) {
case 0 :
F_49 ( V_165 -> V_69 . V_14 , V_165 -> V_128 ) ;
break;
case - V_82 :
case - V_81 :
case - V_83 :
F_18 ( V_165 -> V_69 . V_14 ,
V_165 -> args . V_53 ,
V_116 -> V_349 . V_54 ) ;
case - V_84 :
case - V_106 :
case - V_88 :
V_116 -> V_120 = 0 ;
break;
case - V_455 :
if ( V_165 -> args . V_265 ) {
V_165 -> args . V_265 = NULL ;
V_165 -> V_69 . V_435 = NULL ;
V_116 -> V_120 = 0 ;
F_66 ( V_116 ) ;
return;
}
default:
if ( F_43 ( V_116 , V_165 -> V_69 . V_14 ,
NULL , NULL ) == - V_121 ) {
F_66 ( V_116 ) ;
return;
}
}
V_165 -> V_318 = V_116 -> V_120 ;
}
static void F_460 ( void * V_163 )
{
struct V_730 * V_165 = V_163 ;
struct V_2 * V_2 = V_165 -> V_2 ;
if ( V_2 ) {
if ( V_165 -> V_447 . V_448 )
F_275 ( & V_165 -> V_447 . V_430 , & V_165 -> V_447 . V_69 ,
V_165 -> V_69 . V_449 ) ;
F_461 ( V_2 , & V_165 -> V_435 ) ;
F_462 ( V_2 ) ;
}
F_115 ( V_163 ) ;
}
static void F_463 ( struct V_115 * V_116 , void * V_165 )
{
struct V_730 * V_731 ;
V_731 = (struct V_730 * ) V_165 ;
if ( ! V_731 -> V_447 . V_448 && F_271 ( V_731 -> V_2 , V_116 ) )
return;
F_73 ( V_731 -> V_69 . V_14 -> V_58 ,
& V_731 -> args . V_167 ,
& V_731 -> V_69 . V_168 ,
V_116 ) ;
}
static int F_464 ( struct V_2 * V_2 , struct V_54 * V_55 , const T_4 * V_53 , int V_732 )
{
struct V_730 * V_165 ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_115 * V_116 ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_733 ] ,
. V_54 = V_55 ,
} ;
struct V_180 V_340 = {
. V_182 = V_14 -> V_111 ,
. V_178 = & V_179 ,
. V_183 = & V_734 ,
. V_236 = V_344 ,
} ;
int V_330 = 0 ;
V_165 = F_104 ( sizeof( * V_165 ) , V_327 ) ;
if ( V_165 == NULL )
return - V_174 ;
F_51 ( & V_165 -> args . V_167 , & V_165 -> V_69 . V_168 , 1 ) ;
F_280 ( V_14 -> V_58 ,
V_466 ,
& V_340 . V_182 , & V_179 ) ;
V_165 -> args . V_472 = & V_165 -> V_268 ;
V_165 -> args . V_53 = & V_165 -> V_53 ;
V_165 -> args . V_265 = V_14 -> V_463 ;
F_203 ( & V_165 -> V_268 , F_112 ( V_2 ) ) ;
F_19 ( & V_165 -> V_53 , V_53 ) ;
V_165 -> V_69 . V_435 = & V_165 -> V_435 ;
V_165 -> V_69 . V_14 = V_14 ;
V_165 -> V_69 . V_449 = - V_452 ;
V_165 -> V_447 . V_430 . V_468 = & V_165 -> V_447 . V_468 ;
F_99 ( V_165 -> V_69 . V_435 ) ;
V_165 -> V_128 = V_175 ;
V_165 -> V_318 = 0 ;
V_165 -> V_447 . V_448 = F_281 ( V_2 , & V_165 -> V_447 . V_430 , & V_165 -> V_447 . V_69 , V_55 ) ;
V_165 -> V_2 = F_465 ( V_2 ) ;
if ( V_165 -> V_2 ) {
if ( V_165 -> V_447 . V_448 ) {
V_165 -> args . V_451 = & V_165 -> V_447 . V_430 ;
V_165 -> V_69 . V_453 = & V_165 -> V_447 . V_69 ;
}
} else if ( V_165 -> V_447 . V_448 ) {
F_275 ( & V_165 -> V_447 . V_430 , & V_165 -> V_447 . V_69 , 0 ) ;
V_165 -> V_447 . V_448 = false ;
}
V_340 . V_185 = V_165 ;
V_179 . V_338 = & V_165 -> args ;
V_179 . V_339 = & V_165 -> V_69 ;
V_116 = F_86 ( & V_340 ) ;
if ( F_78 ( V_116 ) )
return F_87 ( V_116 ) ;
if ( ! V_732 )
goto V_156;
V_330 = F_199 ( V_116 ) ;
if ( V_330 != 0 )
goto V_156;
V_330 = V_165 -> V_318 ;
V_156:
F_88 ( V_116 ) ;
return V_330 ;
}
int F_466 ( struct V_2 * V_2 , struct V_54 * V_55 , const T_4 * V_53 , int V_732 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_464 ( V_2 , V_55 , V_53 , V_732 ) ;
F_467 ( V_2 , V_53 , V_8 ) ;
switch ( V_8 ) {
case - V_88 :
case - V_83 :
case 0 :
return 0 ;
}
V_8 = F_36 ( V_14 , V_8 , & V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_468 ( struct V_76 * V_77 , int V_735 , struct V_736 * V_737 )
{
struct V_2 * V_2 = V_77 -> V_2 ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_58 * V_75 = V_14 -> V_58 ;
struct V_738 V_430 = {
. V_268 = F_112 ( V_2 ) ,
. V_739 = V_737 ,
} ;
struct V_740 V_69 = {
. V_741 = V_737 ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_742 ] ,
. V_338 = & V_430 ,
. V_339 = & V_69 ,
. V_54 = V_77 -> V_248 -> V_306 ,
} ;
struct V_307 * V_308 ;
int V_330 ;
V_430 . V_743 . V_258 = V_75 -> V_259 ;
V_330 = F_469 ( V_77 , V_737 ) ;
if ( V_330 != 0 )
goto V_156;
V_308 = V_737 -> V_744 . V_745 . V_248 ;
V_430 . V_743 . V_260 = V_308 -> V_746 . V_263 ;
V_430 . V_743 . V_747 = V_14 -> V_747 ;
V_330 = F_89 ( V_14 -> V_111 , V_14 , & V_179 , & V_430 . V_167 , & V_69 . V_168 , 1 ) ;
switch ( V_330 ) {
case 0 :
V_737 -> V_748 = V_749 ;
break;
case - V_332 :
V_330 = 0 ;
}
V_737 -> V_750 -> V_751 ( V_737 ) ;
V_737 -> V_750 = NULL ;
V_156:
return V_330 ;
}
static int F_470 ( struct V_76 * V_77 , int V_735 , struct V_736 * V_737 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_468 ( V_77 , V_735 , V_737 ) ;
F_471 ( V_737 , V_77 , V_735 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_77 -> V_2 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static struct V_752 * F_472 ( struct V_736 * V_739 ,
struct V_324 * V_325 ,
struct V_307 * V_308 ,
struct V_239 * V_226 )
{
struct V_752 * V_44 ;
struct V_2 * V_2 = V_308 -> V_309 -> V_2 ;
V_44 = F_104 ( sizeof( * V_44 ) , V_327 ) ;
if ( V_44 == NULL )
return NULL ;
V_44 -> V_430 . V_268 = F_112 ( V_2 ) ;
V_44 -> V_430 . V_739 = & V_44 -> V_739 ;
V_44 -> V_430 . V_226 = V_226 ;
V_44 -> V_69 . V_226 = V_226 ;
V_44 -> V_308 = V_308 ;
F_108 ( & V_308 -> V_395 ) ;
V_44 -> V_325 = F_177 ( V_325 ) ;
V_44 -> V_439 = F_266 ( V_325 ) ;
memcpy ( & V_44 -> V_739 , V_739 , sizeof( V_44 -> V_739 ) ) ;
V_44 -> V_14 = F_103 ( V_2 ) ;
return V_44 ;
}
static void F_473 ( void * V_165 )
{
struct V_752 * V_163 = V_165 ;
F_119 ( V_163 -> V_430 . V_226 ) ;
F_234 ( V_163 -> V_308 ) ;
F_268 ( V_163 -> V_439 ) ;
F_189 ( V_163 -> V_325 ) ;
F_115 ( V_163 ) ;
}
static void F_474 ( struct V_115 * V_116 , void * V_165 )
{
struct V_752 * V_163 = V_165 ;
if ( ! F_71 ( V_116 , & V_163 -> V_69 . V_168 ) )
return;
switch ( V_116 -> V_120 ) {
case 0 :
F_49 ( V_163 -> V_14 , V_163 -> V_128 ) ;
F_475 ( V_163 -> V_308 -> V_309 -> V_2 , & V_163 -> V_739 ) ;
if ( F_157 ( V_163 -> V_308 ,
& V_163 -> V_69 . V_53 ) )
break;
case - V_82 :
case - V_83 :
F_18 ( V_163 -> V_14 ,
& V_163 -> V_430 . V_53 ,
V_116 -> V_349 . V_54 ) ;
case - V_84 :
case - V_106 :
case - V_88 :
if ( ! F_155 ( & V_163 -> V_430 . V_53 ,
& V_163 -> V_308 -> V_311 ) )
F_66 ( V_116 ) ;
break;
default:
if ( F_43 ( V_116 , V_163 -> V_14 ,
NULL , NULL ) == - V_121 )
F_66 ( V_116 ) ;
}
F_161 ( V_163 -> V_430 . V_226 ) ;
}
static void F_476 ( struct V_115 * V_116 , void * V_165 )
{
struct V_752 * V_163 = V_165 ;
if ( F_38 ( V_753 , & V_163 -> V_439 -> V_754 -> V_236 ) &&
F_477 ( V_116 , V_163 -> V_439 ) )
return;
if ( F_202 ( V_163 -> V_430 . V_226 , V_116 ) != 0 )
goto V_345;
F_19 ( & V_163 -> V_430 . V_53 , & V_163 -> V_308 -> V_311 ) ;
if ( F_38 ( V_393 , & V_163 -> V_308 -> V_394 ) == 0 ) {
goto V_346;
}
V_163 -> V_128 = V_175 ;
if ( F_73 ( V_163 -> V_14 -> V_58 ,
& V_163 -> V_430 . V_167 ,
& V_163 -> V_69 . V_168 ,
V_116 ) != 0 )
F_161 ( V_163 -> V_430 . V_226 ) ;
return;
V_346:
V_116 -> V_357 = NULL ;
V_345:
F_71 ( V_116 , & V_163 -> V_69 . V_168 ) ;
}
static struct V_115 * F_478 ( struct V_736 * V_739 ,
struct V_324 * V_325 ,
struct V_307 * V_308 ,
struct V_239 * V_226 )
{
struct V_752 * V_165 ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_755 ] ,
. V_54 = V_325 -> V_55 ,
} ;
struct V_180 V_340 = {
. V_182 = F_320 ( V_308 -> V_309 -> V_2 ) ,
. V_178 = & V_179 ,
. V_183 = & V_756 ,
. V_342 = V_343 ,
. V_236 = V_344 ,
} ;
F_280 ( F_103 ( V_308 -> V_309 -> V_2 ) -> V_58 ,
V_466 , & V_340 . V_182 , & V_179 ) ;
V_739 -> V_748 = V_749 ;
if ( V_739 -> V_757 & V_758 )
F_142 ( V_753 , & V_325 -> V_236 ) ;
V_165 = F_472 ( V_739 , V_325 , V_308 , V_226 ) ;
if ( V_165 == NULL ) {
F_119 ( V_226 ) ;
return F_79 ( - V_174 ) ;
}
F_51 ( & V_165 -> V_430 . V_167 , & V_165 -> V_69 . V_168 , 1 ) ;
V_179 . V_338 = & V_165 -> V_430 ;
V_179 . V_339 = & V_165 -> V_69 ;
V_340 . V_185 = V_165 ;
return F_86 ( & V_340 ) ;
}
static int F_479 ( struct V_76 * V_77 , int V_735 , struct V_736 * V_737 )
{
struct V_2 * V_2 = V_77 -> V_2 ;
struct V_234 * V_235 = V_77 -> V_248 ;
struct V_188 * V_189 = F_91 ( V_2 ) ;
struct V_239 * V_226 ;
struct V_307 * V_308 ;
struct V_115 * V_116 ;
struct V_239 * ( * V_240 ) ( struct V_241 * , T_7 ) ;
int V_330 = 0 ;
unsigned char V_757 = V_737 -> V_757 ;
V_330 = F_469 ( V_77 , V_737 ) ;
V_737 -> V_757 |= V_759 ;
F_480 ( & V_235 -> V_760 ) ;
F_481 ( & V_189 -> V_761 ) ;
if ( F_475 ( V_2 , V_737 ) == - V_326 ) {
F_482 ( & V_189 -> V_761 ) ;
F_483 ( & V_235 -> V_760 ) ;
goto V_156;
}
F_482 ( & V_189 -> V_761 ) ;
F_483 ( & V_235 -> V_760 ) ;
if ( V_330 != 0 )
goto V_156;
V_308 = V_737 -> V_744 . V_745 . V_248 ;
if ( F_38 ( V_393 , & V_308 -> V_394 ) == 0 )
goto V_156;
V_240 = F_103 ( V_2 ) -> V_58 -> V_59 -> V_240 ;
V_226 = V_240 ( & V_308 -> V_746 , V_420 ) ;
V_330 = - V_174 ;
if ( F_78 ( V_226 ) )
goto V_156;
V_116 = F_478 ( V_737 , F_312 ( V_737 -> V_762 ) , V_308 , V_226 ) ;
V_330 = F_87 ( V_116 ) ;
if ( F_78 ( V_116 ) )
goto V_156;
V_330 = F_199 ( V_116 ) ;
F_88 ( V_116 ) ;
V_156:
V_737 -> V_757 = V_757 ;
F_484 ( V_737 , V_77 , V_763 , V_330 ) ;
return V_330 ;
}
static struct V_764 * F_485 ( struct V_736 * V_739 ,
struct V_324 * V_325 , struct V_307 * V_308 ,
T_7 V_237 )
{
struct V_764 * V_44 ;
struct V_2 * V_2 = V_308 -> V_309 -> V_2 ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_239 * ( * V_240 ) ( struct V_241 * , T_7 ) ;
V_44 = F_104 ( sizeof( * V_44 ) , V_237 ) ;
if ( V_44 == NULL )
return NULL ;
V_44 -> V_430 . V_268 = F_112 ( V_2 ) ;
V_44 -> V_430 . V_739 = & V_44 -> V_739 ;
V_44 -> V_430 . V_765 = F_486 ( & V_308 -> V_309 -> V_248 -> V_245 , V_237 ) ;
if ( F_78 ( V_44 -> V_430 . V_765 ) )
goto V_334;
V_240 = V_14 -> V_58 -> V_59 -> V_240 ;
V_44 -> V_430 . V_766 = V_240 ( & V_308 -> V_746 , V_237 ) ;
if ( F_78 ( V_44 -> V_430 . V_766 ) )
goto V_767;
V_44 -> V_430 . V_743 . V_258 = V_14 -> V_58 -> V_259 ;
V_44 -> V_430 . V_743 . V_260 = V_308 -> V_746 . V_263 ;
V_44 -> V_430 . V_743 . V_747 = V_14 -> V_747 ;
V_44 -> V_69 . V_766 = V_44 -> V_430 . V_766 ;
V_44 -> V_308 = V_308 ;
V_44 -> V_14 = V_14 ;
F_108 ( & V_308 -> V_395 ) ;
V_44 -> V_325 = F_177 ( V_325 ) ;
memcpy ( & V_44 -> V_739 , V_739 , sizeof( V_44 -> V_739 ) ) ;
return V_44 ;
V_767:
F_119 ( V_44 -> V_430 . V_765 ) ;
V_334:
F_115 ( V_44 ) ;
return NULL ;
}
static void F_487 ( struct V_115 * V_116 , void * V_163 )
{
struct V_764 * V_165 = V_163 ;
struct V_76 * V_77 = V_165 -> V_308 -> V_309 ;
F_8 ( L_23 , V_34 ) ;
if ( F_202 ( V_165 -> V_430 . V_766 , V_116 ) != 0 )
goto V_345;
if ( ! F_38 ( V_393 , & V_165 -> V_308 -> V_394 ) ) {
if ( F_202 ( V_165 -> V_430 . V_765 , V_116 ) != 0 ) {
goto V_768;
}
F_19 ( & V_165 -> V_430 . V_295 ,
& V_77 -> V_295 ) ;
V_165 -> V_430 . V_769 = 1 ;
V_165 -> V_69 . V_765 = V_165 -> V_430 . V_765 ;
} else {
V_165 -> V_430 . V_769 = 0 ;
F_19 ( & V_165 -> V_430 . V_770 ,
& V_165 -> V_308 -> V_311 ) ;
}
if ( ! F_265 ( V_77 ) ) {
V_165 -> V_318 = - V_440 ;
V_116 -> V_357 = NULL ;
goto V_771;
}
V_165 -> V_128 = V_175 ;
if ( F_73 ( V_165 -> V_14 -> V_58 ,
& V_165 -> V_430 . V_167 ,
& V_165 -> V_69 . V_168 ,
V_116 ) == 0 )
return;
V_771:
F_161 ( V_165 -> V_430 . V_765 ) ;
V_768:
F_161 ( V_165 -> V_430 . V_766 ) ;
V_345:
F_71 ( V_116 , & V_165 -> V_69 . V_168 ) ;
F_8 ( L_49 , V_34 , V_165 -> V_318 ) ;
}
static void F_488 ( struct V_115 * V_116 , void * V_163 )
{
struct V_764 * V_165 = V_163 ;
struct V_307 * V_308 = V_165 -> V_308 ;
F_8 ( L_23 , V_34 ) ;
if ( ! F_71 ( V_116 , & V_165 -> V_69 . V_168 ) )
return;
V_165 -> V_318 = V_116 -> V_120 ;
switch ( V_116 -> V_120 ) {
case 0 :
F_49 ( F_103 ( F_14 ( V_165 -> V_325 -> V_4 ) ) ,
V_165 -> V_128 ) ;
if ( V_165 -> V_430 . V_772 ) {
V_165 -> V_739 . V_757 &= ~ ( V_773 | V_774 ) ;
if ( F_475 ( V_308 -> V_309 -> V_2 , & V_165 -> V_739 ) < 0 ) {
F_66 ( V_116 ) ;
break;
}
}
if ( V_165 -> V_430 . V_769 != 0 ) {
F_195 ( & V_308 -> V_746 , 0 ) ;
F_19 ( & V_308 -> V_311 , & V_165 -> V_69 . V_53 ) ;
F_142 ( V_393 , & V_308 -> V_394 ) ;
} else if ( ! F_157 ( V_308 , & V_165 -> V_69 . V_53 ) )
F_66 ( V_116 ) ;
break;
case - V_84 :
case - V_106 :
case - V_88 :
case - V_83 :
if ( V_165 -> V_430 . V_769 != 0 ) {
if ( ! F_155 ( & V_165 -> V_430 . V_295 ,
& V_308 -> V_309 -> V_295 ) )
F_66 ( V_116 ) ;
} else if ( ! F_155 ( & V_165 -> V_430 . V_770 ,
& V_308 -> V_311 ) )
F_66 ( V_116 ) ;
}
F_8 ( L_24 , V_34 , V_165 -> V_318 ) ;
}
static void F_489 ( void * V_163 )
{
struct V_764 * V_165 = V_163 ;
F_8 ( L_23 , V_34 ) ;
F_119 ( V_165 -> V_430 . V_765 ) ;
if ( V_165 -> V_333 ) {
struct V_115 * V_116 ;
V_116 = F_478 ( & V_165 -> V_739 , V_165 -> V_325 , V_165 -> V_308 ,
V_165 -> V_430 . V_766 ) ;
if ( ! F_78 ( V_116 ) )
F_490 ( V_116 ) ;
F_8 ( L_50 , V_34 ) ;
} else
F_119 ( V_165 -> V_430 . V_766 ) ;
F_234 ( V_165 -> V_308 ) ;
F_189 ( V_165 -> V_325 ) ;
F_115 ( V_165 ) ;
F_8 ( L_25 , V_34 ) ;
}
static void F_491 ( struct V_13 * V_14 , struct V_307 * V_308 , int V_769 , int error )
{
switch ( error ) {
case - V_82 :
case - V_83 :
case - V_84 :
V_308 -> V_746 . V_236 &= ~ V_775 ;
if ( V_769 != 0 ||
F_38 ( V_393 , & V_308 -> V_394 ) != 0 )
F_28 ( V_14 , V_308 -> V_309 ) ;
break;
case - V_88 :
V_308 -> V_746 . V_236 &= ~ V_775 ;
F_29 ( V_14 -> V_58 ) ;
} ;
}
static int F_492 ( struct V_76 * V_77 , int V_735 , struct V_736 * V_739 , int V_776 )
{
struct V_764 * V_165 ;
struct V_115 * V_116 ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_777 ] ,
. V_54 = V_77 -> V_248 -> V_306 ,
} ;
struct V_180 V_340 = {
. V_182 = F_320 ( V_77 -> V_2 ) ,
. V_178 = & V_179 ,
. V_183 = & V_778 ,
. V_342 = V_343 ,
. V_236 = V_344 ,
} ;
int V_64 ;
F_8 ( L_23 , V_34 ) ;
V_165 = F_485 ( V_739 , F_312 ( V_739 -> V_762 ) ,
V_739 -> V_744 . V_745 . V_248 ,
V_776 == V_779 ? V_420 : V_327 ) ;
if ( V_165 == NULL )
return - V_174 ;
if ( F_493 ( V_735 ) )
V_165 -> V_430 . V_780 = 1 ;
F_51 ( & V_165 -> V_430 . V_167 , & V_165 -> V_69 . V_168 , 1 ) ;
V_179 . V_338 = & V_165 -> V_430 ;
V_179 . V_339 = & V_165 -> V_69 ;
V_340 . V_185 = V_165 ;
if ( V_776 > V_779 ) {
if ( V_776 == V_781 )
V_165 -> V_430 . V_782 = V_781 ;
F_52 ( & V_165 -> V_430 . V_167 ) ;
} else
V_165 -> V_430 . V_772 = 1 ;
V_116 = F_86 ( & V_340 ) ;
if ( F_78 ( V_116 ) )
return F_87 ( V_116 ) ;
V_64 = F_199 ( V_116 ) ;
if ( V_64 == 0 ) {
V_64 = V_165 -> V_318 ;
if ( V_64 )
F_491 ( V_165 -> V_14 , V_165 -> V_308 ,
V_165 -> V_430 . V_769 , V_64 ) ;
} else
V_165 -> V_333 = true ;
F_88 ( V_116 ) ;
F_8 ( L_24 , V_34 , V_64 ) ;
F_494 ( V_739 , V_77 , & V_165 -> V_69 . V_53 , V_735 , V_64 ) ;
return V_64 ;
}
static int F_495 ( struct V_76 * V_77 , struct V_736 * V_737 )
{
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
struct V_73 V_74 = {
. V_2 = V_77 -> V_2 ,
} ;
int V_8 ;
do {
if ( F_38 ( V_296 , & V_77 -> V_236 ) != 0 )
return 0 ;
V_8 = F_492 ( V_77 , V_763 , V_737 , V_781 ) ;
if ( V_8 != - V_102 )
break;
F_36 ( V_14 , V_8 , & V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_496 ( struct V_76 * V_77 , struct V_736 * V_737 )
{
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
struct V_73 V_74 = {
. V_2 = V_77 -> V_2 ,
} ;
int V_8 ;
V_8 = F_469 ( V_77 , V_737 ) ;
if ( V_8 != 0 )
return V_8 ;
if ( ! V_396 ) {
F_142 ( V_397 , & V_737 -> V_744 . V_745 . V_248 -> V_394 ) ;
return 0 ;
}
do {
if ( F_38 ( V_296 , & V_77 -> V_236 ) != 0 )
return 0 ;
V_8 = F_492 ( V_77 , V_763 , V_737 , V_783 ) ;
switch ( V_8 ) {
default:
goto V_156;
case - V_104 :
case - V_102 :
F_36 ( V_14 , V_8 , & V_74 ) ;
V_8 = 0 ;
}
} while ( V_74 . V_80 );
V_156:
return V_8 ;
}
static int F_497 ( struct V_76 * V_77 , struct V_736 * V_737 )
{
struct V_307 * V_308 ;
int V_330 ;
V_330 = F_469 ( V_77 , V_737 ) ;
if ( V_330 != 0 )
return V_330 ;
V_308 = V_737 -> V_744 . V_745 . V_248 ;
if ( F_38 ( V_393 , & V_308 -> V_394 ) ||
F_38 ( V_397 , & V_308 -> V_394 ) )
return 0 ;
return F_496 ( V_77 , V_737 ) ;
}
static int F_498 ( struct V_76 * V_77 , int V_735 , struct V_736 * V_737 )
{
struct V_188 * V_189 = F_91 ( V_77 -> V_2 ) ;
struct V_234 * V_235 = V_77 -> V_248 ;
unsigned char V_757 = V_737 -> V_757 ;
int V_330 ;
V_737 -> V_757 |= V_774 ;
V_330 = F_475 ( V_77 -> V_2 , V_737 ) ;
if ( V_330 < 0 )
goto V_156;
F_480 ( & V_235 -> V_760 ) ;
F_481 ( & V_189 -> V_761 ) ;
if ( F_38 ( V_296 , & V_77 -> V_236 ) ) {
V_737 -> V_757 = V_757 & ~ V_773 ;
V_330 = F_475 ( V_77 -> V_2 , V_737 ) ;
F_482 ( & V_189 -> V_761 ) ;
F_483 ( & V_235 -> V_760 ) ;
goto V_156;
}
F_482 ( & V_189 -> V_761 ) ;
F_483 ( & V_235 -> V_760 ) ;
V_330 = F_492 ( V_77 , V_735 , V_737 , V_779 ) ;
V_156:
V_737 -> V_757 = V_757 ;
return V_330 ;
}
static int F_499 ( struct V_76 * V_77 , int V_735 , struct V_736 * V_737 )
{
struct V_73 V_74 = {
. V_77 = V_77 ,
. V_2 = V_77 -> V_2 ,
} ;
int V_8 ;
do {
V_8 = F_498 ( V_77 , V_735 , V_737 ) ;
if ( V_8 == - V_332 )
V_8 = - V_121 ;
V_8 = F_36 ( F_103 ( V_77 -> V_2 ) ,
V_8 , & V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int
F_500 ( struct V_76 * V_77 , int V_735 ,
struct V_736 * V_737 )
{
int V_330 = - V_71 ;
unsigned long V_63 = V_784 ;
while( ! F_501 () ) {
V_330 = F_499 ( V_77 , V_735 , V_737 ) ;
if ( ( V_330 != - V_121 ) || F_502 ( V_735 ) )
break;
F_503 ( V_63 ) ;
V_63 *= 2 ;
V_63 = F_416 (unsigned long, NFS4_LOCK_MAXTIMEOUT, timeout) ;
V_330 = - V_71 ;
}
return V_330 ;
}
static int
F_504 ( T_13 * V_464 , unsigned int V_281 , int V_236 , void * V_785 )
{
int V_64 ;
struct V_786 * V_787 = V_785 ;
struct V_788 * V_789 = V_464 -> V_790 ;
struct V_791 * V_792 = & V_787 -> V_793 ,
* V_794 = V_789 -> V_248 ;
if ( V_792 -> V_258 != V_794 -> V_258 ||
V_792 -> V_260 != V_794 -> V_260 ||
V_792 -> V_747 != V_794 -> V_747 )
return 0 ;
if ( F_505 ( F_112 ( V_789 -> V_2 ) , & V_787 -> V_795 ) )
return 0 ;
V_789 -> V_796 = true ;
V_464 -> V_790 = V_789 -> V_116 ;
V_64 = F_506 ( V_464 , V_281 , V_236 , V_785 ) ;
V_464 -> V_790 = V_789 ;
return V_64 ;
}
static int
F_507 ( struct V_76 * V_77 , int V_735 , struct V_736 * V_737 )
{
int V_330 = - V_71 ;
unsigned long V_236 ;
struct V_307 * V_308 = V_737 -> V_744 . V_745 . V_248 ;
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
struct V_58 * V_75 = V_14 -> V_58 ;
T_14 * V_797 = & V_75 -> V_798 ;
struct V_791 V_248 = { . V_258 = V_75 -> V_259 ,
. V_260 = V_308 -> V_746 . V_263 ,
. V_747 = V_14 -> V_747 } ;
struct V_788 V_789 = { . V_116 = V_70 ,
. V_2 = V_77 -> V_2 ,
. V_248 = & V_248 ,
. V_796 = false } ;
T_13 V_464 ;
if ( ! F_38 ( V_413 , & V_77 -> V_236 ) )
return F_500 ( V_77 , V_735 , V_737 ) ;
F_508 ( & V_464 ) ;
V_464 . V_790 = & V_789 ;
V_464 . V_799 = F_504 ;
F_509 ( V_797 , & V_464 ) ;
while( ! F_501 () ) {
V_330 = F_499 ( V_77 , V_735 , V_737 ) ;
if ( ( V_330 != - V_121 ) || F_502 ( V_735 ) )
break;
V_330 = - V_71 ;
F_510 ( & V_797 -> V_304 , V_236 ) ;
if ( V_789 . V_796 ) {
F_511 ( & V_797 -> V_304 , V_236 ) ;
continue;
}
F_512 ( V_800 ) ;
F_511 ( & V_797 -> V_304 , V_236 ) ;
F_513 ( V_801 ) ;
}
F_514 ( V_797 , & V_464 ) ;
return V_330 ;
}
static inline int
F_507 ( struct V_76 * V_77 , int V_735 , struct V_736 * V_737 )
{
return F_500 ( V_77 , V_735 , V_737 ) ;
}
static int
F_515 ( struct V_802 * V_803 , int V_735 , struct V_736 * V_737 )
{
struct V_324 * V_325 ;
struct V_76 * V_77 ;
int V_330 ;
V_325 = F_312 ( V_803 ) ;
V_77 = V_325 -> V_77 ;
if ( F_516 ( V_735 ) ) {
if ( V_77 != NULL )
return F_470 ( V_77 , V_804 , V_737 ) ;
return 0 ;
}
if ( ! ( F_502 ( V_735 ) || F_493 ( V_735 ) ) )
return - V_27 ;
if ( V_737 -> V_748 == V_749 ) {
if ( V_77 != NULL )
return F_479 ( V_77 , V_735 , V_737 ) ;
return 0 ;
}
if ( V_77 == NULL )
return - V_805 ;
if ( ( V_737 -> V_757 & V_806 ) &&
! F_38 ( V_411 , & V_77 -> V_236 ) )
return - V_805 ;
V_330 = F_469 ( V_77 , V_737 ) ;
if ( V_330 != 0 )
return V_330 ;
return F_507 ( V_77 , V_735 , V_737 ) ;
}
int F_517 ( struct V_736 * V_739 , struct V_76 * V_77 , const T_4 * V_53 )
{
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
int V_8 ;
V_8 = F_469 ( V_77 , V_739 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_492 ( V_77 , V_763 , V_739 , V_779 ) ;
return F_190 ( V_14 , V_77 , V_53 , V_8 ) ;
}
static void F_518 ( struct V_115 * V_116 , void * V_163 )
{
struct V_807 * V_165 = V_163 ;
struct V_13 * V_14 = V_165 -> V_14 ;
F_73 ( V_14 -> V_58 , & V_165 -> args . V_167 ,
& V_165 -> V_69 . V_168 , V_116 ) ;
V_165 -> args . V_743 . V_258 = V_14 -> V_58 -> V_259 ;
V_165 -> V_128 = V_175 ;
}
static void F_519 ( struct V_115 * V_116 , void * V_163 )
{
struct V_807 * V_165 = V_163 ;
struct V_13 * V_14 = V_165 -> V_14 ;
F_56 ( V_116 , & V_165 -> V_69 . V_168 ) ;
switch ( V_116 -> V_120 ) {
case 0 :
F_49 ( V_14 , V_165 -> V_128 ) ;
break;
case - V_89 :
case - V_83 :
F_29 ( V_14 -> V_58 ) ;
break;
case - V_91 :
case - V_102 :
if ( F_43 ( V_116 , V_14 ,
NULL , NULL ) == - V_121 )
F_66 ( V_116 ) ;
}
}
static void F_520 ( void * V_163 )
{
struct V_807 * V_165 = V_163 ;
F_521 ( V_165 -> V_14 , V_165 -> V_308 ) ;
F_115 ( V_163 ) ;
}
static void
F_522 ( struct V_13 * V_14 , struct V_307 * V_308 )
{
struct V_807 * V_165 ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_808 ] ,
} ;
if ( V_14 -> V_58 -> V_59 -> V_355 != 0 )
return;
V_165 = F_302 ( sizeof( * V_165 ) , V_327 ) ;
if ( ! V_165 )
return;
V_165 -> V_308 = V_308 ;
V_165 -> V_14 = V_14 ;
V_165 -> args . V_743 . V_258 = V_14 -> V_58 -> V_259 ;
V_165 -> args . V_743 . V_260 = V_308 -> V_746 . V_263 ;
V_165 -> args . V_743 . V_747 = V_14 -> V_747 ;
V_179 . V_338 = & V_165 -> args ;
V_179 . V_339 = & V_165 -> V_69 ;
F_51 ( & V_165 -> args . V_167 , & V_165 -> V_69 . V_168 , 0 ) ;
F_411 ( V_14 -> V_111 , & V_179 , 0 , & V_809 , V_165 ) ;
}
static int F_523 ( const struct V_810 * V_811 ,
struct V_4 * V_812 , struct V_2 * V_2 ,
const char * V_785 , const void * V_655 ,
T_9 V_656 , int V_236 )
{
return F_433 ( V_2 , V_655 , V_656 ) ;
}
static int F_524 ( const struct V_810 * V_811 ,
struct V_4 * V_812 , struct V_2 * V_2 ,
const char * V_785 , void * V_655 , T_9 V_656 )
{
return F_427 ( V_2 , V_655 , V_656 ) ;
}
static bool F_525 ( struct V_4 * V_4 )
{
return F_414 ( F_103 ( F_14 ( V_4 ) ) ) ;
}
static int F_526 ( const struct V_810 * V_811 ,
struct V_4 * V_812 , struct V_2 * V_2 ,
const char * V_785 , const void * V_655 ,
T_9 V_656 , int V_236 )
{
if ( F_527 ( V_785 ) )
return F_441 ( V_2 , V_655 , V_656 ) ;
return - V_680 ;
}
static int F_528 ( const struct V_810 * V_811 ,
struct V_4 * V_812 , struct V_2 * V_2 ,
const char * V_785 , void * V_655 , T_9 V_656 )
{
if ( F_527 ( V_785 ) )
return F_436 ( V_2 , V_655 , V_656 ) ;
return - V_680 ;
}
static T_11
F_529 ( struct V_2 * V_2 , char * V_813 , T_9 V_814 )
{
int V_12 = 0 ;
if ( F_2 ( V_2 , V_9 ) ) {
V_12 = F_530 ( V_2 , V_813 , V_814 ) ;
if ( V_814 && V_12 > V_814 )
return - V_667 ;
}
return V_12 ;
}
static T_11
F_529 ( struct V_2 * V_2 , char * V_813 , T_9 V_814 )
{
return 0 ;
}
static void F_304 ( struct V_442 * V_435 )
{
if ( ! ( ( ( V_435 -> V_321 & V_815 ) ||
( V_435 -> V_321 & V_816 ) ) &&
( V_435 -> V_321 & V_532 ) &&
( V_435 -> V_321 & V_817 ) ) )
return;
V_435 -> V_321 |= V_358 | V_548 |
V_549 | V_818 ;
V_435 -> V_281 = V_363 | V_551 | V_552 ;
V_435 -> V_553 = 2 ;
}
static int F_531 ( struct V_67 * V_111 , struct V_2 * V_3 ,
const struct V_534 * V_264 ,
struct V_536 * V_819 ,
struct V_535 * V_535 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
T_1 V_265 [ 3 ] = {
[ 0 ] = V_820 | V_821 ,
} ;
struct V_822 args = {
. V_546 = F_112 ( V_3 ) ,
. V_264 = V_264 ,
. V_535 = V_535 ,
. V_265 = V_265 ,
} ;
struct V_823 V_69 = {
. V_819 = V_819 ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_824 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
} ;
int V_330 ;
F_8 ( L_51 , V_34 ) ;
if ( F_103 ( V_3 ) -> V_15 [ 1 ] & V_825 )
V_265 [ 1 ] |= V_825 ;
else
V_265 [ 0 ] |= V_41 ;
F_99 ( & V_819 -> V_435 ) ;
V_819 -> V_14 = V_14 ;
V_819 -> V_826 = 0 ;
V_330 = F_89 ( V_111 , V_14 , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
F_8 ( L_52 , V_34 , V_330 ) ;
return V_330 ;
}
int F_303 ( struct V_67 * V_111 , struct V_2 * V_3 ,
const struct V_534 * V_264 ,
struct V_536 * V_819 ,
struct V_535 * V_535 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_531 ( V_111 , V_3 , V_264 ,
V_819 , V_535 ) ;
F_532 ( V_3 , V_264 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_3 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_533 ( struct V_2 * V_2 ,
struct V_536 * V_537 ,
struct V_535 * V_535 , struct V_54 * V_55 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_67 * V_68 = V_14 -> V_111 ;
T_1 V_265 [ 2 ] = {
[ 0 ] = V_820 | V_821 ,
} ;
struct V_822 args = {
. V_258 = V_14 -> V_58 -> V_259 ,
. V_268 = F_112 ( V_2 ) ,
. V_535 = V_535 ,
. V_265 = V_265 ,
. V_827 = 1 ,
. V_828 = 1 ,
} ;
struct V_823 V_69 = {
. V_819 = V_537 ,
. V_827 = 1 ,
. V_828 = 1 ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_824 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
. V_54 = V_55 ,
} ;
unsigned long V_620 = V_175 ;
int V_330 ;
F_99 ( & V_537 -> V_435 ) ;
V_537 -> V_14 = V_14 ;
V_537 -> V_826 = 0 ;
F_51 ( & args . V_167 , & V_69 . V_168 , 0 ) ;
F_52 ( & args . V_167 ) ;
V_330 = F_85 ( V_68 , V_14 , & V_179 ,
& args . V_167 , & V_69 . V_168 ) ;
if ( V_330 )
return V_330 ;
F_49 ( V_14 , V_620 ) ;
return 0 ;
}
static int F_534 ( struct V_2 * V_2 ,
struct V_536 * V_537 ,
struct V_535 * V_535 , struct V_54 * V_55 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_67 * V_68 = V_14 -> V_111 ;
T_1 V_265 [ 2 ] = {
[ 0 ] = V_820 | V_821 ,
} ;
struct V_822 args = {
. V_268 = F_112 ( V_2 ) ,
. V_535 = V_535 ,
. V_265 = V_265 ,
. V_827 = 1 ,
} ;
struct V_823 V_69 = {
. V_819 = V_537 ,
. V_827 = 1 ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_824 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
. V_54 = V_55 ,
} ;
int V_330 ;
F_99 ( & V_537 -> V_435 ) ;
V_537 -> V_14 = V_14 ;
V_537 -> V_826 = 0 ;
F_51 ( & args . V_167 , & V_69 . V_168 , 0 ) ;
F_52 ( & args . V_167 ) ;
V_330 = F_85 ( V_68 , V_14 , & V_179 ,
& args . V_167 , & V_69 . V_168 ) ;
if ( V_330 == V_829 &&
V_69 . V_168 . V_160 & V_830 )
V_330 = - V_91 ;
return V_330 ;
}
int F_535 ( struct V_2 * V_2 ,
struct V_536 * V_537 ,
struct V_535 * V_535 , struct V_54 * V_55 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_58 * V_75 = V_14 -> V_58 ;
const struct V_831 * V_57 =
V_75 -> V_59 -> V_832 ;
struct V_73 V_74 = { } ;
int V_330 ;
F_8 ( L_53 , V_34 ,
( unsigned long long ) V_14 -> V_533 . V_833 ,
( unsigned long long ) V_14 -> V_533 . V_834 ,
V_75 -> V_110 ) ;
F_536 ( F_112 ( V_2 ) , V_34 ) ;
do {
V_330 = V_57 -> V_835 ( V_2 , V_537 , V_535 , V_55 ) ;
if ( V_330 != - V_102 )
break;
F_36 ( V_14 , V_330 , & V_74 ) ;
} while ( V_74 . V_80 );
return V_330 ;
}
static int F_537 ( struct V_2 * V_2 , struct V_54 * V_55 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_58 * V_75 = F_103 ( V_2 ) -> V_58 ;
struct V_67 * V_68 = V_14 -> V_111 ;
struct V_836 args = {
. V_268 = F_112 ( V_2 ) ,
. V_258 = V_75 -> V_259 ,
. V_828 = 1 ,
} ;
struct V_837 V_69 = {
. V_828 = 1 ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_838 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
. V_54 = V_55 ,
} ;
unsigned long V_620 = V_175 ;
int V_330 ;
V_69 . V_268 = F_538 () ;
if ( V_69 . V_268 == NULL )
return - V_174 ;
F_51 ( & args . V_167 , & V_69 . V_168 , 0 ) ;
F_52 ( & args . V_167 ) ;
V_330 = F_85 ( V_68 , V_14 , & V_179 ,
& args . V_167 , & V_69 . V_168 ) ;
F_539 ( V_69 . V_268 ) ;
if ( V_330 )
return V_330 ;
F_45 ( V_75 , V_620 ) ;
return 0 ;
}
static int F_540 ( struct V_2 * V_2 , struct V_54 * V_55 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_67 * V_68 = V_14 -> V_111 ;
struct V_836 args = {
. V_268 = F_112 ( V_2 ) ,
} ;
struct V_837 V_69 = {
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_838 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
. V_54 = V_55 ,
} ;
int V_330 ;
V_69 . V_268 = F_538 () ;
if ( V_69 . V_268 == NULL )
return - V_174 ;
F_51 ( & args . V_167 , & V_69 . V_168 , 0 ) ;
F_52 ( & args . V_167 ) ;
V_330 = F_85 ( V_68 , V_14 , & V_179 ,
& args . V_167 , & V_69 . V_168 ) ;
F_539 ( V_69 . V_268 ) ;
if ( V_330 == V_829 &&
V_69 . V_168 . V_160 & V_830 )
V_330 = - V_91 ;
return V_330 ;
}
int F_541 ( struct V_2 * V_2 , struct V_54 * V_55 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_58 * V_75 = V_14 -> V_58 ;
const struct V_831 * V_57 =
V_75 -> V_59 -> V_832 ;
struct V_73 V_74 = { } ;
int V_330 ;
F_8 ( L_53 , V_34 ,
( unsigned long long ) V_14 -> V_533 . V_833 ,
( unsigned long long ) V_14 -> V_533 . V_834 ,
V_75 -> V_110 ) ;
F_536 ( F_112 ( V_2 ) , V_34 ) ;
do {
V_330 = V_57 -> V_839 ( V_2 , V_55 ) ;
if ( V_330 != - V_102 )
break;
F_36 ( V_14 , V_330 , & V_74 ) ;
} while ( V_74 . V_80 );
return V_330 ;
}
static int F_542 ( struct V_2 * V_3 , const struct V_534 * V_264 , struct V_840 * V_528 , bool V_841 )
{
int V_330 ;
struct V_842 args = {
. V_546 = F_112 ( V_3 ) ,
. V_264 = V_264 ,
} ;
struct V_843 V_69 = {
. V_528 = V_528 ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_844 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
} ;
struct V_67 * V_68 = F_103 ( V_3 ) -> V_111 ;
struct V_54 * V_55 = NULL ;
if ( V_841 ) {
V_68 = F_103 ( V_3 ) -> V_58 -> V_123 ;
V_55 = F_543 ( F_103 ( V_3 ) -> V_58 ) ;
V_179 . V_54 = V_55 ;
}
F_8 ( L_54 , V_264 -> V_264 ) ;
F_280 ( F_103 ( V_3 ) -> V_58 ,
V_845 , & V_68 , & V_179 ) ;
V_330 = F_89 ( V_68 , F_103 ( V_3 ) , & V_179 , & args . V_167 ,
& V_69 . V_168 , 0 ) ;
F_8 ( L_55 , V_330 ) ;
if ( V_55 )
F_232 ( V_55 ) ;
return V_330 ;
}
int F_544 ( struct V_2 * V_3 , const struct V_534 * V_264 ,
struct V_840 * V_528 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_44 ( F_103 ( V_3 ) -> V_58 ) )
V_8 = F_542 ( V_3 , V_264 , V_528 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_542 ( V_3 , V_264 , V_528 , false ) ;
F_545 ( V_3 , V_264 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_3 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_546 ( T_1 V_236 )
{
if ( V_236 & ~ V_846 )
goto V_847;
if ( ( V_236 & V_848 ) &&
( V_236 & V_849 ) )
goto V_847;
if ( ! ( V_236 & ( V_850 ) ) )
goto V_847;
return V_390 ;
V_847:
return - V_851 ;
}
static bool
F_547 ( struct V_852 * V_853 ,
struct V_852 * V_854 )
{
if ( V_853 -> V_855 != V_854 -> V_855 )
return false ;
return memcmp ( V_853 -> V_856 , V_854 -> V_856 , V_853 -> V_855 ) == 0 ;
}
static void
F_548 ( struct V_115 * V_116 , void * V_163 )
{
}
static
int F_549 ( struct V_67 * V_68 ,
struct V_857 * V_858 ,
struct V_58 * V_75 ,
struct V_54 * V_55 )
{
int V_330 ;
struct V_859 args = {
. V_111 = V_75 ,
. V_3 = V_860 ,
} ;
struct V_861 V_69 ;
struct V_178 V_179 = {
. V_335 =
& V_336 [ V_862 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
. V_54 = V_55 ,
} ;
struct V_180 V_340 = {
. V_182 = V_68 ,
. V_857 = V_858 ,
. V_183 = & V_863 ,
. V_178 = & V_179 ,
. V_236 = V_653 ,
} ;
struct V_115 * V_116 ;
F_550 ( & args . V_864 , & V_75 -> V_100 -> V_865 ) ;
if ( ! ( V_75 -> V_100 -> V_236 & V_866 ) )
args . V_3 = V_867 ;
if ( V_858 != F_223 ( V_68 -> V_868 ) )
args . V_3 = V_867 ;
V_116 = F_86 ( & V_340 ) ;
if ( ! F_78 ( V_116 ) ) {
V_330 = V_116 -> V_120 ;
F_88 ( V_116 ) ;
} else
V_330 = F_87 ( V_116 ) ;
F_551 ( V_75 , V_330 ) ;
if ( V_330 == 0 ) {
if ( memcmp ( V_69 . V_864 . V_165 ,
V_75 -> V_100 -> V_865 . V_165 , V_869 ) ) {
F_8 ( L_56 , V_34 ) ;
return - V_35 ;
}
if ( ( V_69 . V_3 & args . V_3 ) != V_69 . V_3 || V_69 . V_3 == 0 ) {
F_8 ( L_57 ,
V_34 ) ;
return - V_35 ;
}
if ( V_69 . V_870 != args . V_870 ) {
F_8 ( L_58 ,
V_34 ) ;
return - V_35 ;
}
}
return V_330 ;
}
static int
F_552 ( struct V_67 * V_68 ,
struct V_857 * V_858 ,
void * V_163 )
{
struct V_871 * V_44 = V_163 ;
return F_549 ( V_68 , V_858 , V_44 -> V_75 , V_44 -> V_55 ) ;
}
int F_553 ( struct V_58 * V_75 , struct V_54 * V_55 )
{
struct V_871 V_165 = {
. V_75 = V_75 ,
. V_55 = V_55 ,
} ;
return F_554 ( V_75 -> V_123 ,
F_552 , & V_165 ) ;
}
static int F_555 ( struct V_58 * V_75 ,
struct V_872 * V_235 )
{
static const T_1 V_873 [ V_874 ] = {
[ 1 ] = 1 << ( V_875 - 32 ) |
1 << ( V_876 - 32 ) |
1 << ( V_877 - 32 ) |
1 << ( V_878 - 32 ) |
1 << ( V_879 - 32 )
} ;
unsigned int V_478 ;
if ( V_235 -> V_880 == V_881 ) {
F_556 ( V_882 , L_59 ) ;
for ( V_478 = 0 ; V_478 <= V_883 ; V_478 ++ ) {
if ( F_38 ( V_478 , V_235 -> V_884 . V_272 . V_885 ) )
F_556 ( V_882 , L_60 , V_478 ) ;
if ( F_38 ( V_478 , V_235 -> V_886 . V_272 . V_885 ) )
F_556 ( V_882 , L_61 , V_478 ) ;
}
for ( V_478 = 0 ; V_478 < V_874 ; V_478 ++ ) {
if ( V_235 -> V_884 . V_272 . V_887 [ V_478 ] & ~ V_873 [ V_478 ] ) {
F_556 ( V_882 , L_62 ) ;
return - V_27 ;
}
}
if ( F_38 ( V_875 , V_235 -> V_884 . V_272 . V_885 ) &&
F_38 ( V_877 , V_235 -> V_884 . V_272 . V_885 ) &&
F_38 ( V_878 , V_235 -> V_884 . V_272 . V_885 ) &&
F_38 ( V_879 , V_235 -> V_884 . V_272 . V_885 ) ) {
F_556 ( V_882 , L_63 ) ;
F_556 ( V_882 , L_64 ) ;
F_142 ( V_888 , & V_75 -> V_889 ) ;
} else {
F_556 ( V_882 , L_62 ) ;
return - V_27 ;
}
if ( F_38 ( V_890 , V_235 -> V_886 . V_272 . V_885 ) &&
F_38 ( V_891 , V_235 -> V_886 . V_272 . V_885 ) &&
F_38 ( V_892 , V_235 -> V_886 . V_272 . V_885 ) &&
F_38 ( V_893 , V_235 -> V_886 . V_272 . V_885 ) ) {
F_556 ( V_882 , L_65 ) ;
F_142 ( V_466 , & V_75 -> V_889 ) ;
}
if ( F_38 ( V_894 , V_235 -> V_886 . V_272 . V_885 ) ) {
F_556 ( V_882 , L_66 ) ;
F_142 ( V_895 ,
& V_75 -> V_889 ) ;
}
if ( F_38 ( V_896 , V_235 -> V_886 . V_272 . V_885 ) &&
F_38 ( V_897 , V_235 -> V_886 . V_272 . V_885 ) ) {
F_556 ( V_882 , L_67 ) ;
F_142 ( V_845 , & V_75 -> V_889 ) ;
}
if ( F_38 ( V_898 , V_235 -> V_886 . V_272 . V_885 ) &&
F_38 ( V_899 , V_235 -> V_886 . V_272 . V_885 ) ) {
F_556 ( V_882 , L_68 ) ;
F_142 ( V_900 , & V_75 -> V_889 ) ;
}
if ( F_38 ( V_901 , V_235 -> V_886 . V_272 . V_885 ) ) {
F_556 ( V_882 , L_69 ) ;
F_142 ( V_902 , & V_75 -> V_889 ) ;
}
if ( F_38 ( V_903 , V_235 -> V_886 . V_272 . V_885 ) ) {
F_556 ( V_882 , L_70 ) ;
F_142 ( V_904 , & V_75 -> V_889 ) ;
}
}
return 0 ;
}
static void F_557 ( struct V_115 * V_116 , void * V_165 )
{
struct V_905 * V_906 =
(struct V_905 * ) V_165 ;
struct V_58 * V_75 = V_906 -> args . V_111 ;
int V_330 = V_116 -> V_120 ;
F_558 ( V_75 , V_330 ) ;
if ( V_330 == 0 )
V_330 = F_546 ( V_906 -> V_69 . V_236 ) ;
if ( V_906 -> V_858 && V_330 == 0 ) {
V_330 = F_559 ( V_75 , & V_906 -> V_69 ,
V_906 -> V_858 ) ;
goto V_156;
}
if ( V_330 == 0 )
V_330 = F_555 ( V_75 , & V_906 -> V_69 . V_907 ) ;
if ( V_330 == 0 ) {
V_75 -> V_259 = V_906 -> V_69 . V_258 ;
V_75 -> V_908 = V_906 -> V_69 . V_236 ;
V_75 -> V_909 = V_906 -> V_69 . V_226 ;
if ( ! ( V_906 -> V_69 . V_236 & V_910 ) )
F_144 ( V_911 ,
& V_75 -> V_100 -> V_912 ) ;
F_115 ( V_75 -> V_913 ) ;
V_75 -> V_913 = V_906 -> V_69 . V_914 ;
V_906 -> V_69 . V_914 = NULL ;
F_115 ( V_75 -> V_915 ) ;
V_75 -> V_915 = V_906 -> V_69 . V_916 ;
V_906 -> V_69 . V_916 = NULL ;
if ( V_75 -> V_917 != NULL &&
! F_547 ( V_75 -> V_917 ,
V_906 -> V_69 . V_856 ) ) {
F_8 ( L_71 ,
V_34 ) ;
F_142 ( V_918 , & V_75 -> V_119 ) ;
F_115 ( V_75 -> V_917 ) ;
V_75 -> V_917 = NULL ;
}
if ( V_75 -> V_917 == NULL ) {
V_75 -> V_917 = V_906 -> V_69 . V_856 ;
V_906 -> V_69 . V_856 = NULL ;
}
memcpy ( V_75 -> V_919 . V_165 , V_906 -> args . V_37 . V_165 ,
sizeof( V_75 -> V_919 . V_165 ) ) ;
}
V_156:
V_906 -> V_318 = V_330 ;
return;
}
static void F_560 ( void * V_165 )
{
struct V_905 * V_906 =
(struct V_905 * ) V_165 ;
F_405 ( V_906 -> args . V_111 ) ;
F_115 ( V_906 -> V_69 . V_916 ) ;
F_115 ( V_906 -> V_69 . V_856 ) ;
F_115 ( V_906 -> V_69 . V_914 ) ;
F_115 ( V_906 ) ;
}
static int F_561 ( struct V_58 * V_75 , struct V_54 * V_55 ,
T_1 V_920 , struct V_857 * V_858 )
{
struct V_178 V_179 = {
. V_335 = & V_336 [ V_921 ] ,
. V_54 = V_55 ,
} ;
struct V_180 V_340 = {
. V_182 = V_75 -> V_123 ,
. V_183 = & V_922 ,
. V_178 = & V_179 ,
. V_236 = V_653 ,
} ;
struct V_905 * V_163 ;
struct V_115 * V_116 ;
int V_330 ;
if ( ! F_410 ( & V_75 -> V_647 ) )
return - V_35 ;
V_163 = F_104 ( sizeof( * V_163 ) , V_327 ) ;
if ( ! V_163 ) {
F_405 ( V_75 ) ;
return - V_174 ;
}
F_443 ( V_75 , & V_163 -> args . V_37 ) ;
V_330 = F_450 ( V_75 ) ;
if ( V_330 )
goto V_923;
V_163 -> V_69 . V_914 = F_104 ( sizeof( struct V_924 ) ,
V_327 ) ;
V_330 = - V_174 ;
if ( F_389 ( V_163 -> V_69 . V_914 == NULL ) )
goto V_923;
V_163 -> V_69 . V_856 = F_104 ( sizeof( struct V_852 ) ,
V_327 ) ;
if ( F_389 ( V_163 -> V_69 . V_856 == NULL ) )
goto V_925;
V_163 -> V_69 . V_916 = F_104 ( sizeof( struct V_926 ) , V_327 ) ;
if ( F_389 ( V_163 -> V_69 . V_916 == NULL ) )
goto V_927;
switch ( V_920 ) {
case V_928 :
V_163 -> args . V_907 . V_880 = V_928 ;
break;
case V_881 :
V_163 -> args . V_907 = V_929 ;
break;
default:
F_127 ( 1 ) ;
V_330 = - V_27 ;
goto V_930;
}
if ( V_858 ) {
V_163 -> V_858 = V_858 ;
V_340 . V_857 = V_858 ;
V_340 . V_236 |= V_931 ;
memcpy ( V_163 -> args . V_37 . V_165 , V_75 -> V_919 . V_165 ,
sizeof( V_163 -> args . V_37 . V_165 ) ) ;
}
V_163 -> args . V_111 = V_75 ;
#ifdef F_562
V_163 -> args . V_236 = V_932 |
V_933 |
V_934 ,
#else
V_163 -> args . V_236 = V_932 |
V_933 ,
#endif
V_179 . V_338 = & V_163 -> args ;
V_179 . V_339 = & V_163 -> V_69 ;
V_340 . V_185 = V_163 ;
V_116 = F_86 ( & V_340 ) ;
if ( F_78 ( V_116 ) )
return F_87 ( V_116 ) ;
V_330 = V_163 -> V_318 ;
F_88 ( V_116 ) ;
V_156:
return V_330 ;
V_930:
F_115 ( V_163 -> V_69 . V_916 ) ;
V_927:
F_115 ( V_163 -> V_69 . V_856 ) ;
V_925:
F_115 ( V_163 -> V_69 . V_914 ) ;
V_923:
F_115 ( V_163 ) ;
F_405 ( V_75 ) ;
goto V_156;
}
int F_563 ( struct V_58 * V_75 , struct V_54 * V_55 )
{
T_5 V_935 = V_75 -> V_123 -> V_124 -> V_125 ;
int V_330 ;
if ( V_935 == V_126 ||
V_935 == V_127 ) {
V_330 = F_561 ( V_75 , V_55 , V_881 , NULL ) ;
if ( ! V_330 )
return 0 ;
}
return F_561 ( V_75 , V_55 , V_928 , NULL ) ;
}
int F_564 ( struct V_67 * V_68 , struct V_857 * V_858 ,
void * V_165 )
{
struct V_936 * V_937 = (struct V_936 * ) V_165 ;
T_1 V_920 ;
F_8 ( L_72 , V_34 ,
V_858 -> V_938 [ V_699 ] ) ;
V_920 = ( V_937 -> V_75 -> V_889 == 0 ? V_928 : V_881 ) ;
return F_561 ( V_937 -> V_75 , V_937 -> V_55 , V_920 , V_858 ) ;
}
static int F_565 ( struct V_58 * V_75 ,
struct V_54 * V_55 )
{
struct V_178 V_179 = {
. V_335 = & V_336 [ V_939 ] ,
. V_338 = V_75 ,
. V_54 = V_55 ,
} ;
int V_330 ;
V_330 = F_413 ( V_75 -> V_123 , & V_179 , V_653 ) ;
F_566 ( V_75 , V_330 ) ;
if ( V_330 )
F_8 ( L_73
L_74 , V_330 , V_75 -> V_110 ) ;
return V_330 ;
}
static int F_567 ( struct V_58 * V_75 ,
struct V_54 * V_55 )
{
unsigned int V_940 ;
int V_64 ;
for ( V_940 = V_941 ; V_940 != 0 ; V_940 -- ) {
V_64 = F_565 ( V_75 , V_55 ) ;
switch ( V_64 ) {
case - V_102 :
case - V_942 :
F_191 ( 1 ) ;
break;
default:
return V_64 ;
}
}
return 0 ;
}
int F_568 ( struct V_58 * V_75 )
{
struct V_54 * V_55 ;
int V_64 = 0 ;
if ( V_75 -> V_59 -> V_355 < 1 )
goto V_156;
if ( V_75 -> V_908 == 0 )
goto V_156;
if ( V_75 -> V_943 )
goto V_156;
V_55 = F_543 ( V_75 ) ;
V_64 = F_567 ( V_75 , V_55 ) ;
if ( V_55 )
F_232 ( V_55 ) ;
switch ( V_64 ) {
case 0 :
case - V_89 :
V_75 -> V_908 = 0 ;
}
V_156:
return V_64 ;
}
static void F_569 ( struct V_115 * V_116 ,
void * V_163 )
{
struct V_944 * V_165 =
(struct V_944 * ) V_163 ;
F_8 ( L_36 , V_34 ) ;
F_73 ( V_165 -> V_75 ,
& V_165 -> args -> V_945 ,
& V_165 -> V_69 -> V_946 ,
V_116 ) ;
F_8 ( L_75 , V_34 ) ;
}
static void F_570 ( struct V_115 * V_116 , void * V_163 )
{
struct V_944 * V_165 =
(struct V_944 * ) V_163 ;
F_8 ( L_36 , V_34 ) ;
if ( ! F_68 ( V_116 , & V_165 -> V_69 -> V_946 ) )
return;
switch ( V_116 -> V_120 ) {
case - V_102 :
case - V_104 :
F_8 ( L_76 , V_34 , V_116 -> V_120 ) ;
F_40 ( V_116 , V_66 ) ;
V_116 -> V_120 = 0 ;
case - V_105 :
F_66 ( V_116 ) ;
return;
}
F_8 ( L_75 , V_34 ) ;
}
int F_571 ( struct V_58 * V_75 , struct V_512 * V_616 )
{
struct V_115 * V_116 ;
struct V_947 args ;
struct V_948 V_69 = {
. V_949 = V_616 ,
} ;
struct V_944 V_165 = {
. args = & args ,
. V_69 = & V_69 ,
. V_75 = V_75 ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_950 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
} ;
struct V_180 V_181 = {
. V_182 = V_75 -> V_123 ,
. V_178 = & V_179 ,
. V_183 = & V_951 ,
. V_185 = & V_165 ,
. V_236 = V_653 ,
} ;
int V_330 ;
F_51 ( & args . V_945 , & V_69 . V_946 , 0 ) ;
F_52 ( & args . V_945 ) ;
V_116 = F_86 ( & V_181 ) ;
if ( F_78 ( V_116 ) )
return F_87 ( V_116 ) ;
V_330 = V_116 -> V_120 ;
F_88 ( V_116 ) ;
return V_330 ;
}
static void F_572 ( struct V_952 * args ,
struct V_67 * V_68 )
{
unsigned int V_953 , V_954 ;
unsigned int V_955 = F_573 ( V_68 ) ;
V_953 = V_956 + V_957 ;
V_954 = V_956 + V_958 ;
args -> V_959 . V_953 = V_953 ;
args -> V_959 . V_954 = V_954 ;
args -> V_959 . V_960 = V_961 ;
args -> V_959 . V_962 = V_963 ;
F_8 ( L_77
L_78 ,
V_34 ,
args -> V_959 . V_953 , args -> V_959 . V_954 ,
args -> V_959 . V_960 , args -> V_959 . V_962 ) ;
args -> V_964 . V_953 = V_955 ;
args -> V_964 . V_954 = V_955 ;
args -> V_964 . V_965 = 0 ;
args -> V_964 . V_960 = V_966 ;
args -> V_964 . V_962 = F_416 (unsigned short, max_session_cb_slots, 1 ) ;
F_8 ( L_79
L_80 ,
V_34 ,
args -> V_964 . V_953 , args -> V_964 . V_954 ,
args -> V_964 . V_965 , args -> V_964 . V_960 ,
args -> V_964 . V_962 ) ;
}
static int F_574 ( struct V_952 * args ,
struct V_967 * V_69 )
{
struct V_968 * V_969 = & args -> V_959 ;
struct V_968 * V_970 = & V_69 -> V_959 ;
if ( V_970 -> V_954 > V_969 -> V_954 )
return - V_27 ;
if ( V_970 -> V_960 < V_969 -> V_960 )
return - V_27 ;
if ( V_970 -> V_962 == 0 )
return - V_27 ;
if ( V_970 -> V_962 > V_971 )
V_970 -> V_962 = V_971 ;
return 0 ;
}
static int F_575 ( struct V_952 * args ,
struct V_967 * V_69 )
{
struct V_968 * V_969 = & args -> V_964 ;
struct V_968 * V_970 = & V_69 -> V_964 ;
if ( ! ( V_69 -> V_236 & V_866 ) )
goto V_156;
if ( V_970 -> V_953 > V_969 -> V_953 )
return - V_27 ;
if ( V_970 -> V_954 < V_969 -> V_954 )
return - V_27 ;
if ( V_970 -> V_965 > V_969 -> V_965 )
return - V_27 ;
if ( V_970 -> V_960 > V_969 -> V_960 )
return - V_27 ;
if ( V_970 -> V_962 > V_969 -> V_962 )
return - V_27 ;
V_156:
return 0 ;
}
static int F_576 ( struct V_952 * args ,
struct V_967 * V_69 )
{
int V_64 ;
V_64 = F_574 ( args , V_69 ) ;
if ( V_64 )
return V_64 ;
return F_575 ( args , V_69 ) ;
}
static void F_577 ( struct V_144 * V_145 ,
struct V_967 * V_69 )
{
F_550 ( & V_145 -> V_865 , & V_69 -> V_864 ) ;
V_145 -> V_75 -> V_908 |= V_910 ;
F_142 ( V_911 , & V_145 -> V_912 ) ;
V_145 -> V_236 = V_69 -> V_236 ;
memcpy ( & V_145 -> V_959 , & V_69 -> V_959 , sizeof( V_145 -> V_959 ) ) ;
if ( V_69 -> V_236 & V_866 )
memcpy ( & V_145 -> V_964 , & V_69 -> V_964 ,
sizeof( V_145 -> V_964 ) ) ;
}
static int F_578 ( struct V_58 * V_75 ,
struct V_54 * V_55 )
{
struct V_144 * V_145 = V_75 -> V_100 ;
struct V_952 args = {
. V_111 = V_75 ,
. V_258 = V_75 -> V_259 ,
. V_226 = V_75 -> V_909 ,
. V_972 = V_973 ,
} ;
struct V_967 V_69 ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_974 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
. V_54 = V_55 ,
} ;
int V_330 ;
F_572 ( & args , V_75 -> V_123 ) ;
args . V_236 = ( V_975 | V_866 ) ;
V_330 = F_413 ( V_145 -> V_75 -> V_123 , & V_179 , V_653 ) ;
F_579 ( V_75 , V_330 ) ;
switch ( V_330 ) {
case - V_89 :
case - V_102 :
case - V_976 :
case - V_29 :
case - V_121 :
goto V_156;
} ;
V_75 -> V_909 ++ ;
if ( ! V_330 ) {
V_330 = F_576 ( & args , & V_69 ) ;
if ( V_330 )
goto V_156;
F_577 ( V_145 , & V_69 ) ;
}
V_156:
return V_330 ;
}
int F_580 ( struct V_58 * V_75 , struct V_54 * V_55 )
{
int V_330 ;
unsigned * V_977 ;
struct V_144 * V_145 = V_75 -> V_100 ;
F_8 ( L_81 , V_34 , V_75 , V_145 ) ;
V_330 = F_578 ( V_75 , V_55 ) ;
if ( V_330 )
goto V_156;
V_330 = F_581 ( V_145 ) ;
F_8 ( L_82 , V_330 ) ;
if ( V_330 )
goto V_156;
V_977 = ( unsigned * ) & V_145 -> V_865 . V_165 [ 0 ] ;
F_8 ( L_83 , V_34 ,
V_75 -> V_909 , V_977 [ 0 ] , V_977 [ 1 ] , V_977 [ 2 ] , V_977 [ 3 ] ) ;
V_156:
F_8 ( L_75 , V_34 ) ;
return V_330 ;
}
int F_582 ( struct V_144 * V_145 ,
struct V_54 * V_55 )
{
struct V_178 V_179 = {
. V_335 = & V_336 [ V_978 ] ,
. V_338 = V_145 ,
. V_54 = V_55 ,
} ;
int V_330 = 0 ;
F_8 ( L_84 ) ;
if ( ! F_135 ( V_911 , & V_145 -> V_912 ) )
return 0 ;
V_330 = F_413 ( V_145 -> V_75 -> V_123 , & V_179 , V_653 ) ;
F_583 ( V_145 -> V_75 , V_330 ) ;
if ( V_330 )
F_8 ( L_85
L_86 , V_330 ) ;
F_8 ( L_87 ) ;
return V_330 ;
}
static void F_584 ( void * V_165 )
{
struct V_979 * V_163 = V_165 ;
struct V_58 * V_75 = V_163 -> V_75 ;
if ( F_403 ( & V_75 -> V_647 ) > 1 )
F_404 ( V_75 ) ;
F_405 ( V_75 ) ;
F_115 ( V_163 ) ;
}
static int F_585 ( struct V_115 * V_116 , struct V_58 * V_75 )
{
switch( V_116 -> V_120 ) {
case - V_102 :
F_40 ( V_116 , V_65 ) ;
return - V_121 ;
default:
F_29 ( V_75 ) ;
}
return 0 ;
}
static void F_586 ( struct V_115 * V_116 , void * V_165 )
{
struct V_979 * V_163 = V_165 ;
struct V_58 * V_75 = V_163 -> V_75 ;
if ( ! F_68 ( V_116 , V_116 -> V_349 . V_339 ) )
return;
F_587 ( V_75 , V_116 -> V_120 ) ;
if ( V_116 -> V_120 < 0 ) {
F_8 ( L_88 , V_34 , V_116 -> V_120 ) ;
if ( F_403 ( & V_75 -> V_647 ) == 1 )
goto V_156;
if ( F_585 ( V_116 , V_75 ) == - V_121 ) {
F_66 ( V_116 ) ;
return;
}
}
F_8 ( L_89 , V_34 , V_116 -> V_349 . V_54 ) ;
V_156:
F_8 ( L_75 , V_34 ) ;
}
static void F_588 ( struct V_115 * V_116 , void * V_165 )
{
struct V_979 * V_163 = V_165 ;
struct V_58 * V_75 = V_163 -> V_75 ;
struct V_131 * args ;
struct V_132 * V_69 ;
args = V_116 -> V_349 . V_338 ;
V_69 = V_116 -> V_349 . V_339 ;
F_73 ( V_75 , args , V_69 , V_116 ) ;
}
static struct V_115 * F_589 ( struct V_58 * V_75 ,
struct V_54 * V_55 ,
bool V_980 )
{
struct V_979 * V_163 ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_981 ] ,
. V_54 = V_55 ,
} ;
struct V_180 V_340 = {
. V_182 = V_75 -> V_123 ,
. V_178 = & V_179 ,
. V_183 = & V_982 ,
. V_236 = V_344 | V_653 ,
} ;
if ( ! F_410 ( & V_75 -> V_647 ) )
return F_79 ( - V_35 ) ;
V_163 = F_104 ( sizeof( * V_163 ) , V_327 ) ;
if ( V_163 == NULL ) {
F_405 ( V_75 ) ;
return F_79 ( - V_174 ) ;
}
F_51 ( & V_163 -> args , & V_163 -> V_69 , 0 ) ;
if ( V_980 )
F_52 ( & V_163 -> args ) ;
V_179 . V_338 = & V_163 -> args ;
V_179 . V_339 = & V_163 -> V_69 ;
V_163 -> V_75 = V_75 ;
V_340 . V_185 = V_163 ;
return F_86 ( & V_340 ) ;
}
static int F_590 ( struct V_58 * V_75 , struct V_54 * V_55 , unsigned V_651 )
{
struct V_115 * V_116 ;
int V_64 = 0 ;
if ( ( V_651 & V_983 ) == 0 )
return - V_121 ;
V_116 = F_589 ( V_75 , V_55 , false ) ;
if ( F_78 ( V_116 ) )
V_64 = F_87 ( V_116 ) ;
else
F_490 ( V_116 ) ;
F_8 ( L_90 , V_34 , V_64 ) ;
return V_64 ;
}
static int F_591 ( struct V_58 * V_75 , struct V_54 * V_55 )
{
struct V_115 * V_116 ;
int V_64 ;
V_116 = F_589 ( V_75 , V_55 , true ) ;
if ( F_78 ( V_116 ) ) {
V_64 = F_87 ( V_116 ) ;
goto V_156;
}
V_64 = F_199 ( V_116 ) ;
if ( ! V_64 )
V_64 = V_116 -> V_120 ;
F_88 ( V_116 ) ;
V_156:
F_8 ( L_90 , V_34 , V_64 ) ;
return V_64 ;
}
static void F_592 ( struct V_115 * V_116 , void * V_165 )
{
struct V_984 * V_163 = V_165 ;
F_73 ( V_163 -> V_75 ,
& V_163 -> V_430 . V_167 ,
& V_163 -> V_69 . V_168 ,
V_116 ) ;
}
static int F_593 ( struct V_115 * V_116 , struct V_58 * V_75 )
{
switch( V_116 -> V_120 ) {
case 0 :
case - V_985 :
case - V_23 :
break;
case - V_102 :
F_40 ( V_116 , V_65 ) ;
case - V_105 :
return - V_121 ;
case - V_93 :
case - V_97 :
case - V_96 :
F_33 ( V_75 -> V_100 ,
V_116 -> V_120 ) ;
break;
default:
F_29 ( V_75 ) ;
}
return 0 ;
}
static void F_594 ( struct V_115 * V_116 , void * V_165 )
{
struct V_984 * V_163 = V_165 ;
struct V_58 * V_75 = V_163 -> V_75 ;
struct V_132 * V_69 = & V_163 -> V_69 . V_168 ;
F_8 ( L_36 , V_34 ) ;
if ( ! F_68 ( V_116 , V_69 ) )
return;
F_595 ( V_75 , V_116 -> V_120 ) ;
if ( F_593 ( V_116 , V_75 ) == - V_121 ) {
F_66 ( V_116 ) ;
return;
}
F_8 ( L_75 , V_34 ) ;
}
static void F_596 ( void * V_165 )
{
struct V_984 * V_163 = V_165 ;
F_115 ( V_163 ) ;
}
static int F_597 ( struct V_58 * V_75 ,
struct V_54 * V_55 )
{
struct V_984 * V_163 ;
struct V_115 * V_116 ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_986 ] ,
. V_54 = V_55 ,
} ;
struct V_180 V_340 = {
. V_182 = V_75 -> V_123 ,
. V_178 = & V_179 ,
. V_183 = & V_987 ,
. V_236 = V_344 ,
} ;
int V_330 = - V_174 ;
F_8 ( L_36 , V_34 ) ;
V_163 = F_104 ( sizeof( * V_163 ) , V_327 ) ;
if ( V_163 == NULL )
goto V_156;
V_163 -> V_75 = V_75 ;
V_163 -> V_430 . V_988 = 0 ;
F_51 ( & V_163 -> V_430 . V_167 , & V_163 -> V_69 . V_168 , 0 ) ;
F_52 ( & V_163 -> V_430 . V_167 ) ;
V_179 . V_338 = & V_163 -> V_430 ;
V_179 . V_339 = & V_163 -> V_69 ;
V_340 . V_185 = V_163 ;
V_116 = F_86 ( & V_340 ) ;
if ( F_78 ( V_116 ) ) {
V_330 = F_87 ( V_116 ) ;
goto V_156;
}
V_330 = F_199 ( V_116 ) ;
if ( V_330 == 0 )
V_330 = V_116 -> V_120 ;
F_88 ( V_116 ) ;
V_156:
F_8 ( L_90 , V_34 , V_330 ) ;
return V_330 ;
}
static void
F_598 ( struct V_115 * V_116 , void * V_163 )
{
struct V_989 * V_990 = V_163 ;
struct V_13 * V_14 = F_103 ( V_990 -> args . V_2 ) ;
F_8 ( L_36 , V_34 ) ;
F_73 ( V_14 -> V_58 , & V_990 -> args . V_167 ,
& V_990 -> V_69 . V_168 , V_116 ) ;
F_8 ( L_75 , V_34 ) ;
}
static void F_599 ( struct V_115 * V_116 , void * V_163 )
{
struct V_989 * V_990 = V_163 ;
F_8 ( L_36 , V_34 ) ;
F_61 ( V_116 , & V_990 -> V_69 . V_168 ) ;
F_8 ( L_75 , V_34 ) ;
}
static int
F_600 ( struct V_115 * V_116 ,
struct V_989 * V_990 , struct V_73 * V_74 )
{
struct V_2 * V_2 = V_990 -> args . V_2 ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_991 * V_992 ;
int V_993 = V_116 -> V_120 ;
int V_8 , V_330 = 0 ;
F_601 ( V_994 ) ;
F_8 ( L_91 , V_34 , - V_116 -> V_120 ) ;
switch ( V_993 ) {
case 0 :
goto V_156;
case - V_995 :
V_330 = - V_996 ;
goto V_156;
case - V_997 :
V_330 = - V_998 ;
goto V_156;
case - V_19 :
if ( V_990 -> args . V_999 == 0 ) {
V_330 = - V_998 ;
goto V_156;
}
V_330 = - V_33 ;
break;
case - V_20 :
V_330 = - V_1000 ;
break;
case - V_81 :
case - V_82 :
case - V_83 :
case - V_84 :
V_74 -> V_63 = 0 ;
F_46 ( & V_2 -> V_190 ) ;
V_992 = F_91 ( V_2 ) -> V_1001 ;
if ( ! V_992 || F_38 ( V_1002 , & V_992 -> V_1003 ) ||
F_139 ( & V_990 -> args . V_53 ,
& V_990 -> args . V_325 -> V_77 -> V_53 ) ) {
F_48 ( & V_2 -> V_190 ) ;
V_74 -> V_77 = V_990 -> args . V_325 -> V_77 ;
V_74 -> V_53 = & V_990 -> args . V_53 ;
break;
}
F_602 ( V_992 , & V_994 ) ;
F_48 ( & V_2 -> V_190 ) ;
F_603 ( V_2 , 0 ) ;
F_604 ( & V_994 ) ;
V_330 = - V_121 ;
goto V_156;
}
F_70 ( & V_990 -> V_69 . V_168 ) ;
V_8 = F_36 ( V_14 , V_993 , V_74 ) ;
if ( ! V_330 ) {
if ( V_74 -> V_80 )
V_330 = - V_121 ;
else
V_330 = V_8 ;
}
V_156:
F_8 ( L_75 , V_34 ) ;
return V_330 ;
}
static T_9 F_605 ( struct V_13 * V_14 )
{
T_1 V_954 = V_14 -> V_58 -> V_100 -> V_959 . V_954 ;
return F_606 ( 0 , V_954 ) ;
}
static void F_607 ( struct V_535 * * V_45 , T_9 V_1004 )
{
int V_478 ;
if ( ! V_45 )
return;
for ( V_478 = 0 ; V_478 < V_1004 ; V_478 ++ ) {
if ( ! V_45 [ V_478 ] )
break;
F_305 ( V_45 [ V_478 ] ) ;
}
F_115 ( V_45 ) ;
}
static struct V_535 * * F_608 ( T_9 V_1004 , T_7 V_1005 )
{
struct V_535 * * V_45 ;
int V_478 ;
V_45 = F_609 ( V_1004 , sizeof( struct V_535 * ) , V_1005 ) ;
if ( ! V_45 ) {
F_8 ( L_92 , V_34 , V_1004 ) ;
return NULL ;
}
for ( V_478 = 0 ; V_478 < V_1004 ; V_478 ++ ) {
V_45 [ V_478 ] = F_301 ( V_1005 ) ;
if ( ! V_45 [ V_478 ] ) {
F_8 ( L_93 , V_34 ) ;
F_607 ( V_45 , V_1004 ) ;
return NULL ;
}
}
return V_45 ;
}
static void F_610 ( void * V_163 )
{
struct V_989 * V_990 = V_163 ;
struct V_2 * V_2 = V_990 -> args . V_2 ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
T_9 V_1006 = F_605 ( V_14 ) ;
F_8 ( L_36 , V_34 ) ;
F_70 ( & V_990 -> V_69 . V_168 ) ;
F_607 ( V_990 -> args . V_1001 . V_45 , V_1006 ) ;
F_611 ( F_91 ( V_2 ) -> V_1001 ) ;
F_189 ( V_990 -> args . V_325 ) ;
F_115 ( V_163 ) ;
F_8 ( L_75 , V_34 ) ;
}
struct V_1007 *
F_612 ( struct V_989 * V_990 , long * V_63 , T_7 V_1005 )
{
struct V_2 * V_2 = V_990 -> args . V_2 ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
T_9 V_1006 = F_605 ( V_14 ) ;
struct V_115 * V_116 ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_1008 ] ,
. V_338 = & V_990 -> args ,
. V_339 = & V_990 -> V_69 ,
. V_54 = V_990 -> V_55 ,
} ;
struct V_180 V_340 = {
. V_182 = V_14 -> V_111 ,
. V_178 = & V_179 ,
. V_183 = & V_1009 ,
. V_185 = V_990 ,
. V_236 = V_344 ,
} ;
struct V_1007 * V_1010 = NULL ;
struct V_73 V_74 = {
. V_2 = V_2 ,
. V_63 = * V_63 ,
} ;
int V_330 = 0 ;
F_8 ( L_36 , V_34 ) ;
F_613 ( F_91 ( V_2 ) -> V_1001 ) ;
V_990 -> args . V_1001 . V_45 = F_608 ( V_1006 , V_1005 ) ;
if ( ! V_990 -> args . V_1001 . V_45 ) {
F_610 ( V_990 ) ;
return F_79 ( - V_174 ) ;
}
V_990 -> args . V_1001 . V_566 = V_1006 * V_660 ;
V_990 -> V_69 . V_1011 = & V_990 -> args . V_1001 ;
V_990 -> V_69 . V_168 . V_137 = NULL ;
F_51 ( & V_990 -> args . V_167 , & V_990 -> V_69 . V_168 , 0 ) ;
V_116 = F_86 ( & V_340 ) ;
if ( F_78 ( V_116 ) )
return F_283 ( V_116 ) ;
V_330 = F_199 ( V_116 ) ;
if ( V_330 == 0 ) {
V_330 = F_600 ( V_116 , V_990 , & V_74 ) ;
* V_63 = V_74 . V_63 ;
}
F_614 ( V_990 -> args . V_325 ,
& V_990 -> args . V_1012 ,
& V_990 -> V_69 . V_1012 ,
& V_990 -> V_69 . V_53 ,
V_330 ) ;
if ( V_330 == 0 && V_990 -> V_69 . V_1011 -> V_12 )
V_1010 = F_615 ( V_990 ) ;
F_88 ( V_116 ) ;
F_8 ( L_90 , V_34 , V_330 ) ;
if ( V_330 )
return F_79 ( V_330 ) ;
return V_1010 ;
}
static void
F_616 ( struct V_115 * V_116 , void * V_163 )
{
struct V_1013 * V_1014 = V_163 ;
F_8 ( L_36 , V_34 ) ;
F_73 ( V_1014 -> V_75 ,
& V_1014 -> args . V_167 ,
& V_1014 -> V_69 . V_168 ,
V_116 ) ;
}
static void F_617 ( struct V_115 * V_116 , void * V_163 )
{
struct V_1013 * V_1014 = V_163 ;
struct V_13 * V_14 ;
F_8 ( L_36 , V_34 ) ;
if ( ! F_61 ( V_116 , & V_1014 -> V_69 . V_168 ) )
return;
V_14 = F_103 ( V_1014 -> args . V_2 ) ;
switch ( V_116 -> V_120 ) {
default:
V_116 -> V_120 = 0 ;
case 0 :
break;
case - V_102 :
if ( F_43 ( V_116 , V_14 , NULL , NULL ) != - V_121 )
break;
F_70 ( & V_1014 -> V_69 . V_168 ) ;
F_66 ( V_116 ) ;
return;
}
F_8 ( L_75 , V_34 ) ;
}
static void F_618 ( void * V_163 )
{
struct V_1013 * V_1014 = V_163 ;
struct V_991 * V_992 = V_1014 -> args . V_1001 ;
F_8 ( L_36 , V_34 ) ;
F_619 ( V_992 , & V_1014 -> args . V_53 , & V_1014 -> args . V_1012 ,
V_1014 -> V_69 . V_1015 ? & V_1014 -> V_69 . V_53 : NULL ) ;
F_70 ( & V_1014 -> V_69 . V_168 ) ;
if ( V_1014 -> V_468 . V_57 && V_1014 -> V_468 . V_57 -> free )
V_1014 -> V_468 . V_57 -> free ( & V_1014 -> V_468 ) ;
F_611 ( V_1014 -> args . V_1001 ) ;
F_462 ( V_1014 -> V_2 ) ;
F_115 ( V_163 ) ;
F_8 ( L_75 , V_34 ) ;
}
int F_620 ( struct V_1013 * V_1014 , bool V_1016 )
{
struct V_115 * V_116 ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_1017 ] ,
. V_338 = & V_1014 -> args ,
. V_339 = & V_1014 -> V_69 ,
. V_54 = V_1014 -> V_55 ,
} ;
struct V_180 V_340 = {
. V_182 = F_103 ( V_1014 -> args . V_2 ) -> V_111 ,
. V_178 = & V_179 ,
. V_183 = & V_1018 ,
. V_185 = V_1014 ,
} ;
int V_330 = 0 ;
F_280 ( F_103 ( V_1014 -> args . V_2 ) -> V_58 ,
V_895 ,
& V_340 . V_182 , & V_179 ) ;
F_8 ( L_36 , V_34 ) ;
if ( ! V_1016 ) {
V_1014 -> V_2 = F_465 ( V_1014 -> args . V_2 ) ;
if ( ! V_1014 -> V_2 ) {
F_618 ( V_1014 ) ;
return - V_121 ;
}
V_340 . V_236 |= V_344 ;
}
F_51 ( & V_1014 -> args . V_167 , & V_1014 -> V_69 . V_168 , 1 ) ;
V_116 = F_86 ( & V_340 ) ;
if ( F_78 ( V_116 ) )
return F_87 ( V_116 ) ;
if ( V_1016 )
V_330 = V_116 -> V_120 ;
F_621 ( V_1014 -> args . V_2 , & V_1014 -> args . V_53 , V_330 ) ;
F_8 ( L_90 , V_34 , V_330 ) ;
F_88 ( V_116 ) ;
return V_330 ;
}
static int
F_622 ( struct V_13 * V_14 ,
struct V_1019 * V_1020 ,
struct V_54 * V_55 )
{
struct V_1021 args = {
. V_1020 = V_1020 ,
. V_1022 = V_1023 |
V_1024 ,
} ;
struct V_1025 V_69 = {
. V_1020 = V_1020 ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_1026 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
. V_54 = V_55 ,
} ;
int V_330 ;
F_8 ( L_36 , V_34 ) ;
V_330 = F_89 ( V_14 -> V_111 , V_14 , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
if ( V_69 . V_1027 & ~ args . V_1022 )
F_8 ( L_94 , V_34 ) ;
if ( V_69 . V_1027 != args . V_1022 )
V_1020 -> V_1028 = 1 ;
F_8 ( L_90 , V_34 , V_330 ) ;
return V_330 ;
}
int F_623 ( struct V_13 * V_14 ,
struct V_1019 * V_1020 ,
struct V_54 * V_55 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_36 ( V_14 ,
F_622 ( V_14 , V_1020 , V_55 ) ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static void F_624 ( struct V_115 * V_116 , void * V_163 )
{
struct V_1029 * V_165 = V_163 ;
struct V_13 * V_14 = F_103 ( V_165 -> args . V_2 ) ;
F_73 ( V_14 -> V_58 ,
& V_165 -> args . V_167 ,
& V_165 -> V_69 . V_168 ,
V_116 ) ;
}
static void
F_625 ( struct V_115 * V_116 , void * V_163 )
{
struct V_1029 * V_165 = V_163 ;
struct V_13 * V_14 = F_103 ( V_165 -> args . V_2 ) ;
if ( ! F_68 ( V_116 , & V_165 -> V_69 . V_168 ) )
return;
switch ( V_116 -> V_120 ) {
case - V_81 :
case - V_1030 :
case - V_997 :
case - V_104 :
V_116 -> V_120 = 0 ;
case 0 :
break;
default:
if ( F_43 ( V_116 , V_14 , NULL , NULL ) == - V_121 ) {
F_66 ( V_116 ) ;
return;
}
}
}
static void F_626 ( void * V_163 )
{
struct V_1029 * V_165 = V_163 ;
F_627 ( V_165 ) ;
F_461 ( V_165 -> args . V_2 ,
V_165 -> V_69 . V_435 ) ;
F_232 ( V_165 -> V_55 ) ;
F_462 ( V_165 -> V_2 ) ;
F_115 ( V_165 ) ;
}
int
F_628 ( struct V_1029 * V_165 , bool V_1016 )
{
struct V_178 V_179 = {
. V_335 = & V_336 [ V_1031 ] ,
. V_338 = & V_165 -> args ,
. V_339 = & V_165 -> V_69 ,
. V_54 = V_165 -> V_55 ,
} ;
struct V_180 V_340 = {
. V_116 = & V_165 -> V_116 ,
. V_182 = F_320 ( V_165 -> args . V_2 ) ,
. V_178 = & V_179 ,
. V_183 = & V_1032 ,
. V_185 = V_165 ,
} ;
struct V_115 * V_116 ;
int V_330 = 0 ;
F_8 ( L_95
L_96 , V_1016 ,
V_165 -> args . V_1033 ,
V_165 -> args . V_2 -> V_557 ) ;
if ( ! V_1016 ) {
V_165 -> V_2 = F_465 ( V_165 -> args . V_2 ) ;
if ( V_165 -> V_2 == NULL ) {
F_626 ( V_165 ) ;
return - V_121 ;
}
V_340 . V_236 = V_344 ;
}
F_51 ( & V_165 -> args . V_167 , & V_165 -> V_69 . V_168 , 1 ) ;
V_116 = F_86 ( & V_340 ) ;
if ( F_78 ( V_116 ) )
return F_87 ( V_116 ) ;
if ( V_1016 )
V_330 = V_116 -> V_120 ;
F_629 ( V_165 -> args . V_2 , & V_165 -> args . V_53 , V_330 ) ;
F_8 ( L_97 , V_34 , V_330 ) ;
F_88 ( V_116 ) ;
return V_330 ;
}
static int
F_630 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_512 * V_513 ,
struct V_840 * V_528 , bool V_841 )
{
struct V_1034 args = {
. V_1035 = V_1036 ,
} ;
struct V_843 V_69 = {
. V_528 = V_528 ,
} ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_1037 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
} ;
struct V_67 * V_68 = V_14 -> V_111 ;
struct V_54 * V_55 = NULL ;
int V_330 ;
if ( V_841 ) {
V_68 = V_14 -> V_58 -> V_123 ;
V_55 = F_543 ( V_14 -> V_58 ) ;
V_179 . V_54 = V_55 ;
}
F_8 ( L_36 , V_34 ) ;
V_330 = F_89 ( V_68 , V_14 , & V_179 , & args . V_167 ,
& V_69 . V_168 , 0 ) ;
F_8 ( L_90 , V_34 , V_330 ) ;
if ( V_55 )
F_232 ( V_55 ) ;
return V_330 ;
}
static int
F_631 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_512 * V_513 , struct V_840 * V_528 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_44 ( V_14 -> V_58 ) )
V_8 = F_630 ( V_14 , V_472 , V_513 ,
V_528 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_630 ( V_14 , V_472 , V_513 ,
V_528 , false ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
case - V_1038 :
goto V_156;
default:
V_8 = F_36 ( V_14 , V_8 , & V_74 ) ;
}
} while ( V_74 . V_80 );
V_156:
return V_8 ;
}
static int
F_632 ( struct V_13 * V_14 , struct V_471 * V_472 ,
struct V_512 * V_513 )
{
int V_8 ;
struct V_535 * V_535 ;
T_5 V_122 = V_1039 ;
struct V_840 * V_528 ;
struct V_1040 * V_1041 ;
int V_478 ;
V_535 = F_301 ( V_420 ) ;
if ( ! V_535 ) {
V_8 = - V_174 ;
goto V_156;
}
V_528 = F_417 ( V_535 ) ;
V_8 = F_631 ( V_14 , V_472 , V_513 , V_528 ) ;
if ( V_8 == - V_22 || V_8 == - V_1038 ) {
V_8 = F_295 ( V_14 , V_472 , V_513 ) ;
goto V_1042;
}
if ( V_8 )
goto V_1042;
for ( V_478 = 0 ; V_478 < V_528 -> V_1043 ; V_478 ++ ) {
V_1041 = & V_528 -> V_528 [ V_478 ] ;
switch ( V_1041 -> V_122 ) {
case V_525 :
case V_524 :
case V_1044 :
V_122 = F_633 ( V_1041 -> V_122 ,
& V_1041 -> V_1045 ) ;
break;
default:
V_122 = V_1039 ;
break;
}
if ( ! F_634 ( & V_14 -> V_526 , V_122 ) )
V_122 = V_1039 ;
if ( V_122 != V_1039 ) {
V_8 = F_293 ( V_14 , V_472 ,
V_513 , V_122 ) ;
if ( ! V_8 )
break;
}
}
if ( V_122 == V_1039 )
V_8 = - V_24 ;
V_1042:
F_431 ( V_535 ) ;
if ( V_8 == - V_29 )
return - V_24 ;
V_156:
return V_8 ;
}
static int F_635 ( struct V_13 * V_14 ,
T_4 * V_53 ,
struct V_54 * V_55 )
{
int V_330 ;
struct V_1046 args = {
. V_53 = V_53 ,
} ;
struct V_1047 V_69 ;
struct V_178 V_179 = {
. V_335 = & V_336 [ V_1048 ] ,
. V_338 = & args ,
. V_339 = & V_69 ,
. V_54 = V_55 ,
} ;
struct V_67 * V_182 = V_14 -> V_111 ;
F_280 ( V_14 -> V_58 , V_900 ,
& V_182 , & V_179 ) ;
F_8 ( L_98 , V_53 ) ;
F_51 ( & args . V_167 , & V_69 . V_168 , 0 ) ;
F_52 ( & args . V_167 ) ;
V_330 = F_85 ( V_182 , V_14 , & V_179 ,
& args . V_167 , & V_69 . V_168 ) ;
if ( V_330 != V_390 ) {
F_8 ( L_99 , V_330 ) ;
return V_330 ;
}
F_8 ( L_100 , - V_69 . V_330 ) ;
return - V_69 . V_330 ;
}
static void F_636 ( struct V_13 * V_14 ,
int V_8 , struct V_73 * V_74 )
{
V_74 -> V_80 = 0 ;
switch( V_8 ) {
case - V_102 :
case - V_105 :
F_36 ( V_14 , V_8 , V_74 ) ;
break;
case - V_93 :
case - V_94 :
case - V_95 :
case - V_96 :
case - V_97 :
F_25 ( V_14 , V_8 , V_74 ) ;
}
}
static int F_227 ( struct V_13 * V_14 ,
T_4 * V_53 ,
struct V_54 * V_55 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_635 ( V_14 , V_53 , V_55 ) ;
F_636 ( V_14 , V_8 , & V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static void F_637 ( struct V_115 * V_116 , void * V_163 )
{
struct V_1049 * V_165 = V_163 ;
F_73 ( V_165 -> V_14 -> V_58 ,
& V_165 -> args . V_167 ,
& V_165 -> V_69 . V_168 ,
V_116 ) ;
}
static void F_638 ( struct V_115 * V_116 , void * V_163 )
{
struct V_1049 * V_165 = V_163 ;
F_68 ( V_116 , & V_165 -> V_69 . V_168 ) ;
switch ( V_116 -> V_120 ) {
case - V_102 :
if ( F_43 ( V_116 , V_165 -> V_14 , NULL , NULL ) == - V_121 )
F_66 ( V_116 ) ;
}
}
static void F_639 ( void * V_163 )
{
F_115 ( V_163 ) ;
}
static struct V_115 * F_640 ( struct V_13 * V_14 ,
const T_4 * V_53 ,
struct V_54 * V_55 ,
bool V_161 )
{
struct V_178 V_179 = {
. V_335 = & V_336 [ V_1050 ] ,
. V_54 = V_55 ,
} ;
struct V_180 V_181 = {
. V_182 = V_14 -> V_111 ,
. V_178 = & V_179 ,
. V_183 = & V_1051 ,
. V_236 = V_344 ,
} ;
struct V_1049 * V_165 ;
F_280 ( V_14 -> V_58 , V_900 ,
& V_181 . V_182 , & V_179 ) ;
F_8 ( L_101 , V_53 ) ;
V_165 = F_302 ( sizeof( * V_165 ) , V_327 ) ;
if ( ! V_165 )
return F_79 ( - V_174 ) ;
V_165 -> V_14 = V_14 ;
F_19 ( & V_165 -> args . V_53 , V_53 ) ;
V_181 . V_185 = V_165 ;
V_179 . V_338 = & V_165 -> args ;
V_179 . V_339 = & V_165 -> V_69 ;
F_51 ( & V_165 -> args . V_167 , & V_165 -> V_69 . V_168 , 1 ) ;
if ( V_161 )
F_52 ( & V_165 -> args . V_167 ) ;
return F_86 ( & V_181 ) ;
}
static int F_228 ( struct V_13 * V_14 ,
const T_4 * V_53 ,
struct V_54 * V_55 ,
bool V_1052 )
{
struct V_115 * V_116 ;
V_116 = F_640 ( V_14 , V_53 , V_55 , V_1052 ) ;
if ( F_78 ( V_116 ) )
return F_87 ( V_116 ) ;
F_88 ( V_116 ) ;
return 0 ;
}
static void
F_641 ( struct V_13 * V_14 , struct V_307 * V_308 )
{
struct V_54 * V_55 = V_308 -> V_309 -> V_248 -> V_306 ;
F_228 ( V_14 , & V_308 -> V_311 , V_55 , false ) ;
F_521 ( V_14 , V_308 ) ;
}
static bool F_642 ( const T_4 * V_1053 ,
const T_4 * V_1054 )
{
if ( V_1053 -> type != V_1054 -> type )
return false ;
if ( memcmp ( V_1053 -> V_1055 , V_1054 -> V_1055 , sizeof( V_1053 -> V_1055 ) ) != 0 )
return false ;
if ( V_1053 -> V_226 == V_1054 -> V_226 )
return true ;
return V_1053 -> V_226 == 0 || V_1054 -> V_226 == 0 ;
}
static bool F_643 ( const T_4 * V_1053 ,
const T_4 * V_1054 )
{
return F_155 ( V_1053 , V_1054 ) ;
}
static struct V_239 *
F_644 ( struct V_241 * V_1056 , T_7 V_1057 )
{
return NULL ;
}
static T_11 F_645 ( struct V_4 * V_4 , char * V_813 , T_9 V_1004 )
{
T_11 error , V_1058 ;
error = F_646 ( V_4 , V_813 , V_1004 ) ;
if ( error < 0 )
return error ;
if ( V_813 ) {
V_813 += error ;
V_1004 -= error ;
}
V_1058 = F_529 ( F_14 ( V_4 ) , V_813 , V_1004 ) ;
if ( V_1058 < 0 )
return V_1058 ;
return error + V_1058 ;
}
