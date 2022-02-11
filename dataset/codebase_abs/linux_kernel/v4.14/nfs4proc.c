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
static struct V_2 *
F_169 ( struct V_222 * V_165 )
{
struct V_2 * V_2 ;
switch ( V_165 -> V_227 . V_215 ) {
case V_217 :
case V_219 :
case V_221 :
if ( ! ( V_165 -> V_224 . V_321 & V_322 ) )
return F_79 ( - V_121 ) ;
V_2 = F_170 ( V_165 -> V_3 -> V_247 , & V_165 -> V_223 . V_268 ,
& V_165 -> V_224 , V_165 -> V_225 ) ;
break;
default:
V_2 = F_14 ( V_165 -> V_4 ) ;
F_171 ( V_2 ) ;
F_168 ( V_2 , & V_165 -> V_224 ) ;
}
return V_2 ;
}
static struct V_76 *
F_172 ( struct V_222 * V_165 )
{
struct V_76 * V_77 ;
struct V_2 * V_2 ;
V_2 = F_169 ( V_165 ) ;
if ( F_78 ( V_2 ) )
return F_173 ( V_2 ) ;
if ( V_165 -> V_77 != NULL && V_165 -> V_77 -> V_2 == V_2 ) {
V_77 = V_165 -> V_77 ;
F_108 ( & V_77 -> V_52 ) ;
} else
V_77 = F_174 ( V_2 , V_165 -> V_248 ) ;
F_175 ( V_2 ) ;
if ( V_77 == NULL )
V_77 = F_79 ( - V_174 ) ;
return V_77 ;
}
static struct V_76 *
F_176 ( struct V_222 * V_165 )
{
struct V_76 * V_77 ;
if ( ! V_165 -> V_317 ) {
V_77 = F_160 ( V_165 ) ;
F_177 ( V_165 -> V_77 ) ;
goto V_156;
}
V_77 = F_172 ( V_165 ) ;
if ( F_78 ( V_77 ) )
goto V_156;
if ( V_165 -> V_223 . V_320 != 0 )
F_163 ( V_165 , V_77 ) ;
F_152 ( V_77 , & V_165 -> V_223 . V_53 , NULL ,
V_165 -> V_227 . V_205 ) ;
V_156:
F_161 ( V_165 -> V_227 . V_226 ) ;
return V_77 ;
}
static struct V_76 *
F_178 ( struct V_222 * V_165 )
{
struct V_76 * V_64 ;
if ( V_165 -> V_227 . V_215 == V_269 )
V_64 = F_167 ( V_165 ) ;
else
V_64 = F_176 ( V_165 ) ;
F_70 ( & V_165 -> V_223 . V_168 ) ;
return V_64 ;
}
static struct V_323 * F_179 ( struct V_76 * V_77 )
{
struct V_188 * V_189 = F_91 ( V_77 -> V_2 ) ;
struct V_323 * V_324 ;
F_46 ( & V_77 -> V_2 -> V_190 ) ;
F_180 (ctx, &nfsi->open_files, list) {
if ( V_324 -> V_77 != V_77 )
continue;
F_181 ( V_324 ) ;
F_48 ( & V_77 -> V_2 -> V_190 ) ;
return V_324 ;
}
F_48 ( & V_77 -> V_2 -> V_190 ) ;
return F_79 ( - V_325 ) ;
}
static struct V_222 * F_182 ( struct V_323 * V_324 ,
struct V_76 * V_77 , enum V_214 V_215 )
{
struct V_222 * V_313 ;
V_313 = F_101 ( V_324 -> V_4 , V_77 -> V_248 , 0 , 0 ,
NULL , NULL , V_215 , V_326 ) ;
if ( V_313 == NULL )
return F_79 ( - V_174 ) ;
V_313 -> V_77 = V_77 ;
F_108 ( & V_77 -> V_52 ) ;
return V_313 ;
}
static int F_183 ( struct V_222 * V_313 ,
T_6 V_205 )
{
struct V_76 * V_327 ;
int V_64 ;
if ( ! F_126 ( V_313 -> V_77 , V_205 ) )
return 0 ;
V_313 -> V_227 . V_250 = 0 ;
V_313 -> V_227 . V_205 = V_205 ;
V_313 -> V_227 . V_252 = F_96 (
F_184 ( V_313 -> V_4 -> V_247 ) ,
V_205 , 0 ) ;
memset ( & V_313 -> V_223 , 0 , sizeof( V_313 -> V_223 ) ) ;
memset ( & V_313 -> V_228 , 0 , sizeof( V_313 -> V_228 ) ) ;
F_98 ( V_313 ) ;
V_64 = F_185 ( V_313 ) ;
if ( V_64 != 0 )
return V_64 ;
V_327 = F_178 ( V_313 ) ;
if ( F_78 ( V_327 ) )
return F_87 ( V_327 ) ;
if ( V_327 != V_313 -> V_77 )
V_64 = - V_328 ;
F_186 ( V_327 , V_205 ) ;
return V_64 ;
}
static int F_187 ( struct V_222 * V_313 , struct V_76 * V_77 )
{
int V_64 ;
F_144 ( V_286 , & V_77 -> V_236 ) ;
F_144 ( V_285 , & V_77 -> V_236 ) ;
F_144 ( V_284 , & V_77 -> V_236 ) ;
F_144 ( V_296 , & V_77 -> V_236 ) ;
F_144 ( V_294 , & V_77 -> V_236 ) ;
F_188 () ;
V_64 = F_183 ( V_313 , V_207 | V_208 ) ;
if ( V_64 != 0 )
return V_64 ;
V_64 = F_183 ( V_313 , V_208 ) ;
if ( V_64 != 0 )
return V_64 ;
V_64 = F_183 ( V_313 , V_207 ) ;
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
static int F_189 ( struct V_323 * V_324 , struct V_76 * V_77 )
{
struct V_287 * V_288 ;
struct V_222 * V_313 ;
T_6 V_320 = 0 ;
int V_329 ;
V_313 = F_182 ( V_324 , V_77 ,
V_269 ) ;
if ( F_78 ( V_313 ) )
return F_87 ( V_313 ) ;
F_153 () ;
V_288 = F_154 ( F_91 ( V_77 -> V_2 ) -> V_288 ) ;
if ( V_288 != NULL && F_38 ( V_290 , & V_288 -> V_236 ) != 0 )
V_320 = V_288 -> type ;
F_156 () ;
V_313 -> V_227 . V_272 . V_320 = V_320 ;
V_329 = F_187 ( V_313 , V_77 ) ;
F_124 ( V_313 ) ;
return V_329 ;
}
static int F_190 ( struct V_323 * V_324 , struct V_76 * V_77 )
{
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_189 ( V_324 , V_77 ) ;
F_191 ( V_324 , 0 , V_8 ) ;
if ( F_95 ( V_14 , V_8 , & V_74 ) )
continue;
if ( V_8 != - V_102 )
break;
F_36 ( V_14 , V_8 , & V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_192 ( struct V_234 * V_235 , struct V_76 * V_77 )
{
struct V_323 * V_324 ;
int V_64 ;
V_324 = F_179 ( V_77 ) ;
if ( F_78 ( V_324 ) )
return - V_121 ;
V_64 = F_190 ( V_324 , V_77 ) ;
F_193 ( V_324 ) ;
return V_64 ;
}
static int F_194 ( struct V_13 * V_14 , struct V_76 * V_77 , const T_4 * V_53 , int V_8 )
{
switch ( V_8 ) {
default:
F_35 ( V_330 L_15
L_16 , V_34 , V_8 ) ;
case 0 :
case - V_325 :
case - V_121 :
case - V_328 :
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
F_195 ( 1 ) ;
return - V_121 ;
case - V_174 :
case - V_331 :
return 0 ;
}
return V_8 ;
}
int F_196 ( struct V_323 * V_324 ,
struct V_76 * V_77 , const T_4 * V_53 ,
T_6 type )
{
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
struct V_222 * V_313 ;
int V_8 = 0 ;
V_313 = F_182 ( V_324 , V_77 ,
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
V_8 = F_183 ( V_313 , V_207 | V_208 ) ;
if ( V_8 )
break;
V_8 = F_183 ( V_313 , V_208 ) ;
if ( V_8 )
break;
case V_207 :
V_8 = F_183 ( V_313 , V_207 ) ;
}
F_124 ( V_313 ) ;
return F_194 ( V_14 , V_77 , V_53 , V_8 ) ;
}
static void F_197 ( struct V_115 * V_116 , void * V_163 )
{
struct V_222 * V_165 = V_163 ;
F_73 ( V_165 -> V_227 . V_14 -> V_58 ,
& V_165 -> V_229 . V_167 , & V_165 -> V_228 . V_168 , V_116 ) ;
}
static void F_198 ( struct V_115 * V_116 , void * V_163 )
{
struct V_222 * V_165 = V_163 ;
F_56 ( V_116 , & V_165 -> V_228 . V_168 ) ;
V_165 -> V_318 = V_116 -> V_120 ;
if ( V_165 -> V_318 == 0 ) {
F_19 ( & V_165 -> V_223 . V_53 , & V_165 -> V_228 . V_53 ) ;
F_199 ( & V_165 -> V_248 -> V_245 , 0 ) ;
F_49 ( V_165 -> V_223 . V_14 , V_165 -> V_128 ) ;
V_165 -> V_317 = true ;
}
}
static void F_200 ( void * V_163 )
{
struct V_222 * V_165 = V_163 ;
struct V_76 * V_77 = NULL ;
if ( ! V_165 -> V_332 )
goto V_333;
if ( ! V_165 -> V_317 )
goto V_333;
V_77 = F_178 ( V_165 ) ;
if ( ! F_78 ( V_77 ) )
F_186 ( V_77 , V_165 -> V_227 . V_205 ) ;
V_333:
F_124 ( V_165 ) ;
}
static int F_201 ( struct V_222 * V_165 )
{
struct V_13 * V_14 = F_103 ( F_14 ( V_165 -> V_3 ) ) ;
struct V_115 * V_116 ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_336 ] ,
. V_337 = & V_165 -> V_229 ,
. V_338 = & V_165 -> V_228 ,
. V_54 = V_165 -> V_248 -> V_306 ,
} ;
struct V_180 V_339 = {
. V_182 = V_14 -> V_111 ,
. V_178 = & V_179 ,
. V_183 = & V_340 ,
. V_185 = V_165 ,
. V_341 = V_342 ,
. V_236 = V_343 ,
} ;
int V_329 ;
F_51 ( & V_165 -> V_229 . V_167 , & V_165 -> V_228 . V_168 , 1 ) ;
F_202 ( & V_165 -> V_274 ) ;
V_165 -> V_317 = false ;
V_165 -> V_318 = 0 ;
V_165 -> V_128 = V_175 ;
if ( V_165 -> V_315 )
F_52 ( & V_165 -> V_229 . V_167 ) ;
V_116 = F_86 ( & V_339 ) ;
if ( F_78 ( V_116 ) )
return F_87 ( V_116 ) ;
V_329 = F_203 ( V_116 ) ;
if ( V_329 != 0 ) {
V_165 -> V_332 = true ;
F_204 () ;
} else
V_329 = V_165 -> V_318 ;
F_88 ( V_116 ) ;
return V_329 ;
}
static void F_205 ( struct V_115 * V_116 , void * V_163 )
{
struct V_222 * V_165 = V_163 ;
struct V_234 * V_235 = V_165 -> V_248 ;
struct V_58 * V_75 = V_235 -> V_291 -> V_58 ;
enum V_214 V_215 = V_165 -> V_227 . V_215 ;
if ( F_206 ( V_165 -> V_227 . V_226 , V_116 ) != 0 )
goto V_344;
if ( V_165 -> V_77 != NULL ) {
struct V_287 * V_288 ;
if ( F_128 ( V_165 -> V_77 , V_165 -> V_227 . V_205 , V_165 -> V_227 . V_250 ) )
goto V_345;
F_153 () ;
V_288 = F_154 ( F_91 ( V_165 -> V_77 -> V_2 ) -> V_288 ) ;
if ( F_129 ( V_288 , V_165 -> V_227 . V_205 , V_215 ) )
goto V_346;
F_156 () ;
}
V_165 -> V_227 . V_258 = V_75 -> V_259 ;
switch ( V_215 ) {
default:
break;
case V_269 :
case V_218 :
case V_220 :
V_165 -> V_227 . V_266 = & V_347 [ 0 ] ;
case V_216 :
V_116 -> V_348 . V_334 = & V_335 [ V_349 ] ;
}
V_165 -> V_128 = V_175 ;
if ( F_73 ( V_165 -> V_227 . V_14 -> V_58 ,
& V_165 -> V_227 . V_167 ,
& V_165 -> V_223 . V_168 ,
V_116 ) != 0 )
F_161 ( V_165 -> V_227 . V_226 ) ;
V_165 -> V_227 . V_350 = V_351 ;
if ( V_165 -> V_227 . V_250 & V_253 ) {
V_165 -> V_227 . V_350 = V_352 ;
if ( F_207 ( V_75 ) )
V_165 -> V_227 . V_350 = V_353 ;
else if ( V_75 -> V_59 -> V_354 > 0 )
V_165 -> V_227 . V_350 = V_355 ;
}
return;
V_346:
F_177 ( V_165 -> V_77 ) ;
F_156 () ;
V_345:
V_116 -> V_356 = NULL ;
V_344:
F_71 ( V_116 , & V_165 -> V_223 . V_168 ) ;
}
static void F_208 ( struct V_115 * V_116 , void * V_163 )
{
struct V_222 * V_165 = V_163 ;
V_165 -> V_318 = V_116 -> V_120 ;
if ( ! F_69 ( V_116 , & V_165 -> V_223 . V_168 ) )
return;
if ( V_116 -> V_120 == 0 ) {
if ( V_165 -> V_223 . V_224 -> V_321 & V_357 ) {
switch ( V_165 -> V_223 . V_224 -> V_281 & V_358 ) {
case V_359 :
break;
case V_360 :
V_165 -> V_318 = - V_361 ;
break;
case V_362 :
V_165 -> V_318 = - V_363 ;
break;
default:
V_165 -> V_318 = - V_364 ;
}
}
F_49 ( V_165 -> V_223 . V_14 , V_165 -> V_128 ) ;
if ( ! ( V_165 -> V_223 . V_365 & V_366 ) )
F_199 ( & V_165 -> V_248 -> V_245 , 0 ) ;
}
V_165 -> V_317 = true ;
}
static void F_209 ( void * V_163 )
{
struct V_222 * V_165 = V_163 ;
struct V_76 * V_77 = NULL ;
if ( ! V_165 -> V_332 )
goto V_333;
if ( V_165 -> V_318 != 0 || ! V_165 -> V_317 )
goto V_333;
if ( V_165 -> V_223 . V_365 & V_366 )
goto V_333;
V_77 = F_178 ( V_165 ) ;
if ( ! F_78 ( V_77 ) )
F_186 ( V_77 , V_165 -> V_227 . V_205 ) ;
V_333:
F_124 ( V_165 ) ;
}
static int F_210 ( struct V_222 * V_165 , int V_367 )
{
struct V_2 * V_3 = F_14 ( V_165 -> V_3 ) ;
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_368 * V_227 = & V_165 -> V_227 ;
struct V_369 * V_223 = & V_165 -> V_223 ;
struct V_115 * V_116 ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_370 ] ,
. V_337 = V_227 ,
. V_338 = V_223 ,
. V_54 = V_165 -> V_248 -> V_306 ,
} ;
struct V_180 V_339 = {
. V_182 = V_14 -> V_111 ,
. V_178 = & V_179 ,
. V_183 = & V_371 ,
. V_185 = V_165 ,
. V_341 = V_342 ,
. V_236 = V_343 ,
} ;
int V_329 ;
F_51 ( & V_227 -> V_167 , & V_223 -> V_168 , 1 ) ;
F_202 ( & V_165 -> V_274 ) ;
V_165 -> V_317 = false ;
V_165 -> V_318 = 0 ;
V_165 -> V_332 = false ;
V_165 -> V_315 = false ;
if ( V_367 ) {
F_52 ( & V_227 -> V_167 ) ;
V_165 -> V_315 = true ;
}
V_116 = F_86 ( & V_339 ) ;
if ( F_78 ( V_116 ) )
return F_87 ( V_116 ) ;
V_329 = F_203 ( V_116 ) ;
if ( V_329 != 0 ) {
V_165 -> V_332 = true ;
F_204 () ;
} else
V_329 = V_165 -> V_318 ;
F_88 ( V_116 ) ;
return V_329 ;
}
static int F_185 ( struct V_222 * V_165 )
{
struct V_2 * V_3 = F_14 ( V_165 -> V_3 ) ;
struct V_369 * V_223 = & V_165 -> V_223 ;
int V_329 ;
V_329 = F_210 ( V_165 , 1 ) ;
if ( V_329 != 0 || ! V_165 -> V_317 )
return V_329 ;
F_211 ( F_103 ( V_3 ) , & V_165 -> V_224 ) ;
if ( V_223 -> V_365 & V_366 )
V_329 = F_201 ( V_165 ) ;
return V_329 ;
}
static int F_212 ( struct V_54 * V_55 ,
struct V_222 * V_313 ,
struct V_76 * V_77 , T_6 V_205 ,
int V_206 )
{
struct V_372 V_373 ;
T_1 V_374 , V_236 ;
if ( V_313 -> V_223 . V_375 == 0 )
return 0 ;
V_374 = 0 ;
if ( V_206 & V_376 ) {
if ( F_213 ( V_77 -> V_2 -> V_377 ) )
V_374 = V_378 ;
else
V_374 = V_257 ;
} else if ( ( V_205 & V_207 ) && ! V_313 -> V_379 )
V_374 = V_254 ;
V_373 . V_55 = V_55 ;
F_214 ( & V_373 , V_313 -> V_223 . V_380 ) ;
F_215 ( V_77 -> V_2 , & V_373 ) ;
V_236 = V_254 | V_257 | V_378 ;
if ( ( V_374 & ~ V_373 . V_374 & V_236 ) == 0 )
return 0 ;
return - V_29 ;
}
static int F_216 ( struct V_222 * V_165 )
{
struct V_2 * V_3 = F_14 ( V_165 -> V_3 ) ;
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_368 * V_227 = & V_165 -> V_227 ;
struct V_369 * V_223 = & V_165 -> V_223 ;
int V_329 ;
V_329 = F_210 ( V_165 , 0 ) ;
if ( ! V_165 -> V_317 )
return V_329 ;
if ( V_329 != 0 ) {
if ( V_329 == - V_26 &&
! ( V_227 -> V_250 & V_381 ) )
return - V_325 ;
return V_329 ;
}
F_211 ( V_14 , & V_165 -> V_224 ) ;
if ( V_227 -> V_250 & V_381 ) {
if ( V_227 -> V_250 & V_253 )
V_165 -> V_379 = true ;
else if ( V_223 -> V_187 . V_195 != V_223 -> V_187 . V_201 )
V_165 -> V_379 = true ;
if ( V_165 -> V_379 || V_3 -> V_196 != V_223 -> V_187 . V_201 )
F_90 ( V_3 , & V_223 -> V_187 ,
V_223 -> V_224 -> V_382 ) ;
}
if ( ( V_223 -> V_365 & V_383 ) == 0 )
V_14 -> V_107 &= ~ V_384 ;
if( V_223 -> V_365 & V_366 ) {
V_329 = F_201 ( V_165 ) ;
if ( V_329 != 0 )
return V_329 ;
}
if ( ! ( V_223 -> V_224 -> V_321 & V_322 ) ) {
F_70 ( & V_223 -> V_168 ) ;
F_217 ( V_14 , & V_223 -> V_268 , V_223 -> V_224 , V_223 -> V_225 ) ;
}
return 0 ;
}
static int F_218 ( struct V_323 * V_324 , struct V_76 * V_77 )
{
struct V_222 * V_313 ;
int V_64 ;
V_313 = F_182 ( V_324 , V_77 ,
V_216 ) ;
if ( F_78 ( V_313 ) )
return F_87 ( V_313 ) ;
V_64 = F_187 ( V_313 , V_77 ) ;
if ( V_64 == - V_328 )
F_219 ( V_324 -> V_4 ) ;
F_124 ( V_313 ) ;
return V_64 ;
}
static int F_220 ( struct V_323 * V_324 , struct V_76 * V_77 )
{
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_218 ( V_324 , V_77 ) ;
F_221 ( V_324 , 0 , V_8 ) ;
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
static int F_222 ( struct V_234 * V_235 , struct V_76 * V_77 )
{
struct V_323 * V_324 ;
int V_64 ;
V_324 = F_179 ( V_77 ) ;
if ( F_78 ( V_324 ) )
return - V_121 ;
V_64 = F_220 ( V_324 , V_77 ) ;
F_193 ( V_324 ) ;
return V_64 ;
}
static void F_223 ( struct V_76 * V_77 ,
const T_4 * V_53 )
{
F_224 ( V_77 -> V_2 , V_53 ) ;
F_146 ( & V_77 -> V_298 ) ;
F_19 ( & V_77 -> V_53 , & V_77 -> V_295 ) ;
F_148 ( & V_77 -> V_298 ) ;
F_144 ( V_296 , & V_77 -> V_236 ) ;
}
static void F_225 ( struct V_76 * V_77 )
{
if ( F_226 ( F_91 ( V_77 -> V_2 ) -> V_288 ) != NULL )
F_223 ( V_77 , NULL ) ;
}
static int F_227 ( struct V_234 * V_235 , struct V_76 * V_77 )
{
F_225 ( V_77 ) ;
return F_222 ( V_235 , V_77 ) ;
}
static int F_228 ( struct V_13 * V_14 ,
T_4 * V_53 ,
struct V_54 * V_55 )
{
return - V_84 ;
}
static int F_229 ( struct V_13 * V_14 ,
T_4 * V_53 ,
struct V_54 * V_55 )
{
int V_329 ;
switch ( V_53 -> type ) {
default:
break;
case V_385 :
case V_386 :
return - V_84 ;
case V_61 :
goto V_333;
}
V_329 = F_230 ( V_14 , V_53 , V_55 ) ;
switch ( V_329 ) {
case - V_83 :
case - V_82 :
case - V_81 :
break;
default:
return V_329 ;
}
V_333:
F_231 ( V_14 , V_53 , V_55 , true ) ;
return - V_83 ;
}
static void F_232 ( struct V_76 * V_77 )
{
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
T_4 V_53 ;
struct V_287 * V_288 ;
struct V_54 * V_55 ;
int V_329 ;
F_153 () ;
V_288 = F_154 ( F_91 ( V_77 -> V_2 ) -> V_288 ) ;
if ( V_288 == NULL ) {
F_156 () ;
return;
}
F_19 ( & V_53 , & V_288 -> V_53 ) ;
if ( F_38 ( V_387 , & V_288 -> V_236 ) ||
! F_135 ( V_388 ,
& V_288 -> V_236 ) ) {
F_156 () ;
F_223 ( V_77 , & V_53 ) ;
return;
}
V_55 = F_233 ( V_288 -> V_55 ) ;
F_156 () ;
V_329 = F_229 ( V_14 , & V_53 , V_55 ) ;
F_234 ( V_77 , NULL , V_329 ) ;
if ( V_329 == - V_83 || V_329 == - V_84 )
F_223 ( V_77 , & V_53 ) ;
F_235 ( V_55 ) ;
}
static int F_236 ( struct V_76 * V_77 )
{
int V_329 , V_64 = V_389 ;
struct V_307 * V_308 , * V_390 = NULL ;
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
if ( ! F_38 ( V_391 , & V_77 -> V_236 ) )
goto V_156;
F_46 ( & V_77 -> V_310 ) ;
F_180 (lsp, &state->lock_states, ls_locks) {
if ( F_38 ( V_392 , & V_308 -> V_393 ) ) {
struct V_54 * V_55 = V_308 -> V_309 -> V_248 -> V_306 ;
F_108 ( & V_308 -> V_394 ) ;
F_48 ( & V_77 -> V_310 ) ;
F_237 ( V_390 ) ;
V_390 = V_308 ;
V_329 = F_229 ( V_14 ,
& V_308 -> V_311 ,
V_55 ) ;
F_238 ( V_77 , V_308 , V_329 ) ;
if ( V_329 == - V_83 ||
V_329 == - V_84 ) {
F_144 ( V_392 , & V_308 -> V_393 ) ;
V_308 -> V_311 . type = V_385 ;
if ( ! V_395 )
F_142 ( V_396 , & V_308 -> V_393 ) ;
} else if ( V_329 != V_389 ) {
V_64 = V_329 ;
F_237 ( V_390 ) ;
goto V_156;
}
F_46 ( & V_77 -> V_310 ) ;
}
}
F_48 ( & V_77 -> V_310 ) ;
F_237 ( V_390 ) ;
V_156:
return V_64 ;
}
static int F_239 ( struct V_76 * V_77 )
{
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
T_4 * V_53 = & V_77 -> V_295 ;
struct V_54 * V_55 = V_77 -> V_248 -> V_306 ;
int V_329 ;
if ( F_38 ( V_294 , & V_77 -> V_236 ) == 0 ) {
if ( F_38 ( V_296 , & V_77 -> V_236 ) == 0 ) {
if ( F_240 ( V_77 -> V_2 , V_77 -> V_77 ) )
return V_389 ;
return - V_86 ;
}
return - V_84 ;
}
V_329 = F_229 ( V_14 , V_53 , V_55 ) ;
F_241 ( V_77 , NULL , V_329 ) ;
if ( V_329 == - V_83 || V_329 == - V_84 ) {
F_144 ( V_284 , & V_77 -> V_236 ) ;
F_144 ( V_285 , & V_77 -> V_236 ) ;
F_144 ( V_286 , & V_77 -> V_236 ) ;
F_144 ( V_294 , & V_77 -> V_236 ) ;
V_53 -> type = V_385 ;
return V_329 ;
}
if ( F_133 ( V_77 ) )
return - V_86 ;
return V_389 ;
}
static int F_242 ( struct V_234 * V_235 , struct V_76 * V_77 )
{
int V_329 ;
F_232 ( V_77 ) ;
V_329 = F_236 ( V_77 ) ;
if ( V_329 != V_389 )
return V_329 ;
V_329 = F_239 ( V_77 ) ;
if ( V_329 != V_389 )
V_329 = F_222 ( V_235 , V_77 ) ;
return V_329 ;
}
static inline void F_243 ( struct V_222 * V_313 ,
struct V_5 * V_6 , struct V_1 * * V_7 )
{
const T_1 * V_397 = V_313 -> V_223 . V_397 ;
if ( ( V_397 [ 1 ] & V_398 ) &&
! ( V_6 -> V_270 & V_399 ) )
V_6 -> V_270 |= V_400 ;
if ( ( V_397 [ 1 ] & V_401 ) &&
! ( V_6 -> V_270 & V_402 ) )
V_6 -> V_270 |= V_403 ;
if ( V_313 -> V_227 . V_350 != V_352 &&
( V_397 [ 1 ] & V_404 ||
V_397 [ 2 ] & V_405 ) )
V_6 -> V_270 &= ~ V_406 ;
if ( V_397 [ 2 ] & V_407 )
* V_7 = NULL ;
}
static int F_244 ( struct V_222 * V_313 ,
T_6 V_205 ,
int V_236 ,
struct V_323 * V_324 )
{
struct V_234 * V_235 = V_313 -> V_248 ;
struct V_13 * V_14 = V_235 -> V_291 ;
struct V_4 * V_4 ;
struct V_76 * V_77 ;
unsigned int V_408 ;
int V_64 ;
V_408 = F_245 ( & V_235 -> V_409 ) ;
V_64 = F_216 ( V_313 ) ;
if ( V_64 != 0 )
goto V_156;
V_77 = F_178 ( V_313 ) ;
V_64 = F_87 ( V_77 ) ;
if ( F_78 ( V_77 ) )
goto V_156;
V_324 -> V_77 = V_77 ;
if ( V_14 -> V_107 & V_384 )
F_142 ( V_410 , & V_77 -> V_236 ) ;
if ( V_313 -> V_223 . V_365 & V_411 )
F_142 ( V_412 , & V_77 -> V_236 ) ;
V_4 = V_313 -> V_4 ;
if ( F_246 ( V_4 ) ) {
struct V_4 * V_413 ;
F_219 ( V_4 ) ;
V_413 = F_247 ( V_4 , V_77 -> V_2 ) ;
if ( ! V_413 )
V_413 = F_248 ( F_249 ( V_77 -> V_2 ) , V_4 ) ;
if ( V_413 ) {
F_116 ( V_324 -> V_4 ) ;
V_324 -> V_4 = V_4 = V_413 ;
}
F_250 ( V_4 ,
F_251 ( F_14 ( V_313 -> V_3 ) ) ) ;
}
V_64 = F_212 ( V_235 -> V_306 , V_313 , V_77 , V_205 , V_236 ) ;
if ( V_64 != 0 )
goto V_156;
if ( F_14 ( V_4 ) == V_77 -> V_2 ) {
F_252 ( V_324 ) ;
if ( F_253 ( & V_235 -> V_409 , V_408 ) )
F_28 ( V_14 , V_77 ) ;
}
V_156:
return V_64 ;
}
static int F_254 ( struct V_2 * V_3 ,
struct V_323 * V_324 ,
int V_236 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_414 )
{
struct V_234 * V_235 ;
struct V_76 * V_77 = NULL ;
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_222 * V_313 ;
struct V_4 * V_4 = V_324 -> V_4 ;
struct V_54 * V_55 = V_324 -> V_55 ;
struct V_415 * * V_416 = & V_324 -> V_277 ;
T_6 V_205 = V_324 -> V_281 & ( V_207 | V_208 | V_417 ) ;
enum V_214 V_215 = V_217 ;
struct V_1 * V_418 = NULL ;
int V_329 ;
V_329 = - V_174 ;
V_235 = F_255 ( V_14 , V_55 , V_419 ) ;
if ( V_235 == NULL ) {
F_8 ( L_17 ) ;
goto V_420;
}
V_329 = F_256 ( V_14 -> V_58 ) ;
if ( V_329 != 0 )
goto V_421;
if ( F_257 ( V_4 ) )
F_158 ( F_14 ( V_4 ) , V_205 ) ;
V_329 = - V_174 ;
if ( F_257 ( V_4 ) )
V_215 = V_216 ;
V_313 = F_101 ( V_4 , V_235 , V_205 , V_236 , V_6 ,
V_7 , V_215 , V_419 ) ;
if ( V_313 == NULL )
goto V_421;
if ( V_7 ) {
V_418 = F_105 ( V_14 , V_419 ) ;
if ( F_78 ( V_418 ) ) {
V_329 = F_87 ( V_418 ) ;
goto V_422;
}
}
if ( V_14 -> V_15 [ 2 ] & V_423 ) {
if ( ! V_313 -> V_224 . V_277 ) {
V_313 -> V_224 . V_277 = F_258 () ;
if ( ! V_313 -> V_224 . V_277 )
goto V_246;
}
V_313 -> V_227 . V_266 = & V_424 [ 0 ] ;
}
if ( F_257 ( V_4 ) )
V_313 -> V_77 = F_174 ( F_14 ( V_4 ) , V_235 ) ;
V_329 = F_244 ( V_313 , V_205 , V_236 , V_324 ) ;
if ( V_329 != 0 )
goto V_246;
V_77 = V_324 -> V_77 ;
if ( ( V_313 -> V_227 . V_250 & ( V_381 | V_253 ) ) == ( V_381 | V_253 ) &&
( V_313 -> V_227 . V_350 != V_353 ) ) {
F_243 ( V_313 , V_6 , & V_7 ) ;
if ( V_6 -> V_270 & V_425 ) {
F_99 ( V_313 -> V_223 . V_224 ) ;
V_329 = F_259 ( V_77 -> V_2 , V_55 ,
V_313 -> V_223 . V_224 , V_6 ,
V_324 , V_7 , V_418 ) ;
if ( V_329 == 0 ) {
F_260 ( V_77 -> V_2 , V_6 ,
V_313 -> V_223 . V_224 ) ;
F_261 ( V_77 -> V_2 , V_313 -> V_223 . V_224 , V_418 ) ;
}
}
}
if ( V_414 && V_313 -> V_379 )
* V_414 |= V_426 ;
if ( F_262 ( V_416 , V_313 -> V_224 . V_277 , V_14 ) ) {
* V_416 = V_313 -> V_224 . V_277 ;
V_313 -> V_224 . V_277 = NULL ;
}
F_114 ( V_418 ) ;
F_124 ( V_313 ) ;
F_121 ( V_235 ) ;
return 0 ;
V_246:
F_114 ( V_418 ) ;
V_422:
F_124 ( V_313 ) ;
V_421:
F_121 ( V_235 ) ;
V_420:
return V_329 ;
}
static struct V_76 * F_263 ( struct V_2 * V_3 ,
struct V_323 * V_324 ,
int V_236 ,
struct V_5 * V_6 ,
struct V_1 * V_7 ,
int * V_414 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_73 V_74 = { } ;
struct V_76 * V_69 ;
int V_329 ;
do {
V_329 = F_254 ( V_3 , V_324 , V_236 , V_6 , V_7 , V_414 ) ;
V_69 = V_324 -> V_77 ;
F_264 ( V_324 , V_236 , V_329 ) ;
if ( V_329 == 0 )
break;
if ( V_329 == - V_427 ) {
F_265 ( L_5
L_18 ,
F_103 ( V_3 ) -> V_58 -> V_110 ) ;
V_74 . V_80 = 1 ;
continue;
}
if ( V_329 == - V_84 ) {
V_74 . V_80 = 1 ;
continue;
}
if ( V_329 == - V_121 ) {
V_74 . V_80 = 1 ;
continue;
}
if ( F_95 ( V_14 , V_329 , & V_74 ) )
continue;
V_69 = F_79 ( F_36 ( V_14 ,
V_329 , & V_74 ) ) ;
} while ( V_74 . V_80 );
return V_69 ;
}
static int F_266 ( struct V_2 * V_2 ,
struct V_428 * V_429 ,
struct V_430 * V_69 ,
struct V_54 * V_55 ,
struct V_323 * V_324 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_431 ] ,
. V_337 = V_429 ,
. V_338 = V_69 ,
. V_54 = V_55 ,
} ;
struct V_54 * V_432 = NULL ;
unsigned long V_128 = V_175 ;
T_6 V_205 ;
bool V_433 ;
int V_329 ;
F_99 ( V_69 -> V_434 ) ;
V_433 = ( V_429 -> V_435 -> V_270 & V_436 ) ? true : false ;
V_205 = V_433 ? V_208 : V_207 ;
if ( F_267 ( V_2 , V_205 , & V_429 -> V_53 , & V_432 ) ) {
} else if ( V_433 && V_324 != NULL ) {
struct V_437 * V_438 ;
if ( ! F_268 ( V_324 -> V_77 ) )
return - V_439 ;
V_438 = F_269 ( V_324 ) ;
if ( F_78 ( V_438 ) )
return F_87 ( V_438 ) ;
V_329 = F_270 ( V_324 -> V_77 , V_208 , V_438 ,
& V_429 -> V_53 , & V_432 ) ;
F_271 ( V_438 ) ;
if ( V_329 == - V_35 )
return - V_439 ;
} else
F_19 ( & V_429 -> V_53 , & V_440 ) ;
if ( V_432 )
V_179 . V_54 = V_432 ;
V_329 = F_89 ( V_14 -> V_111 , V_14 , & V_179 , & V_429 -> V_167 , & V_69 -> V_168 , 1 ) ;
F_235 ( V_432 ) ;
if ( V_329 == 0 && V_324 != NULL )
F_49 ( V_14 , V_128 ) ;
F_272 ( V_2 , & V_429 -> V_53 , V_329 ) ;
return V_329 ;
}
static int F_259 ( struct V_2 * V_2 , struct V_54 * V_55 ,
struct V_441 * V_434 , struct V_5 * V_6 ,
struct V_323 * V_324 , struct V_1 * V_442 ,
struct V_1 * V_418 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_76 * V_77 = V_324 ? V_324 -> V_77 : NULL ;
struct V_428 V_429 = {
. V_268 = F_112 ( V_2 ) ,
. V_435 = V_6 ,
. V_14 = V_14 ,
. V_265 = V_14 -> V_15 ,
. V_7 = V_442 ,
} ;
struct V_430 V_69 = {
. V_434 = V_434 ,
. V_7 = V_418 ,
. V_14 = V_14 ,
} ;
struct V_73 V_74 = {
. V_77 = V_77 ,
. V_2 = V_2 ,
. V_53 = & V_429 . V_53 ,
} ;
int V_8 ;
V_429 . V_265 = F_6 ( V_14 , V_442 ) ;
if ( V_442 )
V_429 . V_265 = F_6 ( V_14 , V_418 ) ;
do {
V_8 = F_266 ( V_2 , & V_429 , & V_69 , V_55 , V_324 ) ;
switch ( V_8 ) {
case - V_86 :
if ( ! ( V_6 -> V_270 & V_436 ) ) {
F_273 ( L_19
L_20
L_21
L_22 ,
V_14 -> V_58 -> V_110 ) ;
}
if ( V_77 && ! ( V_77 -> V_77 & V_208 ) ) {
V_8 = - V_439 ;
if ( V_6 -> V_270 & V_443 )
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
F_274 ( struct V_2 * V_2 , struct V_115 * V_116 )
{
if ( V_2 == NULL || ! F_275 ( V_2 ) )
return false ;
return F_276 ( V_2 , V_116 ) ;
}
static void F_277 ( void * V_165 )
{
struct V_444 * V_163 = V_165 ;
struct V_234 * V_235 = V_163 -> V_77 -> V_248 ;
struct V_275 * V_276 = V_163 -> V_77 -> V_2 -> V_445 ;
if ( V_163 -> V_446 . V_447 )
F_278 ( & V_163 -> V_446 . V_429 , & V_163 -> V_446 . V_69 ,
V_163 -> V_69 . V_448 ) ;
F_120 ( V_163 -> V_77 ) ;
F_119 ( V_163 -> V_429 . V_226 ) ;
F_121 ( V_235 ) ;
F_122 ( V_276 ) ;
F_115 ( V_163 ) ;
}
static void F_279 ( struct V_115 * V_116 , void * V_165 )
{
struct V_444 * V_163 = V_165 ;
struct V_76 * V_77 = V_163 -> V_77 ;
struct V_13 * V_14 = F_103 ( V_163 -> V_2 ) ;
T_4 * V_449 = NULL ;
F_8 ( L_23 , V_34 ) ;
if ( ! F_71 ( V_116 , & V_163 -> V_69 . V_168 ) )
return;
F_280 ( V_77 , & V_163 -> V_429 , & V_163 -> V_69 , V_116 -> V_120 ) ;
if ( V_163 -> V_429 . V_450 && V_116 -> V_120 != 0 ) {
switch ( V_163 -> V_69 . V_448 ) {
default:
V_163 -> V_69 . V_448 = - V_451 ;
break;
case 0 :
V_163 -> V_429 . V_450 = NULL ;
V_163 -> V_69 . V_452 = NULL ;
break;
case - V_82 :
case - V_81 :
case - V_83 :
case - V_84 :
case - V_106 :
case - V_453 :
case - V_23 :
V_163 -> V_429 . V_450 = NULL ;
V_163 -> V_69 . V_452 = NULL ;
V_163 -> V_69 . V_448 = 0 ;
F_66 ( V_116 ) ;
return;
}
}
switch ( V_116 -> V_120 ) {
case 0 :
V_449 = & V_163 -> V_69 . V_53 ;
F_49 ( V_14 , V_163 -> V_128 ) ;
break;
case - V_454 :
if ( V_163 -> V_429 . V_265 != NULL ) {
V_163 -> V_429 . V_265 = NULL ;
V_163 -> V_69 . V_434 = NULL ;
V_116 -> V_120 = 0 ;
F_66 ( V_116 ) ;
goto V_455;
}
break;
case - V_82 :
case - V_88 :
case - V_83 :
F_18 ( V_14 ,
& V_163 -> V_429 . V_53 ,
V_116 -> V_348 . V_54 ) ;
case - V_106 :
case - V_84 :
if ( ! F_155 ( & V_163 -> V_429 . V_53 ,
& V_77 -> V_295 ) ) {
F_66 ( V_116 ) ;
goto V_455;
}
if ( V_163 -> V_429 . V_205 == 0 )
break;
default:
if ( F_43 ( V_116 , V_14 , V_77 , NULL ) == - V_121 ) {
F_66 ( V_116 ) ;
goto V_455;
}
}
F_145 ( V_77 , & V_163 -> V_429 . V_53 ,
V_449 , V_163 -> V_429 . V_205 ) ;
V_455:
F_161 ( V_163 -> V_429 . V_226 ) ;
F_168 ( V_163 -> V_2 , & V_163 -> V_434 ) ;
F_8 ( L_24 , V_34 , V_116 -> V_120 ) ;
}
static void F_281 ( struct V_115 * V_116 , void * V_165 )
{
struct V_444 * V_163 = V_165 ;
struct V_76 * V_77 = V_163 -> V_77 ;
struct V_2 * V_2 = V_163 -> V_2 ;
bool V_456 , V_457 , V_458 ;
int V_459 = 0 ;
F_8 ( L_23 , V_34 ) ;
if ( F_206 ( V_163 -> V_429 . V_226 , V_116 ) != 0 )
goto V_344;
V_116 -> V_348 . V_334 = & V_335 [ V_460 ] ;
F_46 ( & V_77 -> V_248 -> V_301 ) ;
V_458 = F_38 ( V_286 , & V_77 -> V_236 ) ;
V_456 = F_38 ( V_284 , & V_77 -> V_236 ) ;
V_457 = F_38 ( V_285 , & V_77 -> V_236 ) ;
F_19 ( & V_163 -> V_429 . V_53 , & V_77 -> V_295 ) ;
V_163 -> V_429 . V_205 = 0 ;
if ( V_77 -> V_278 == 0 ) {
if ( V_77 -> V_280 == 0 )
V_459 |= V_456 ;
else if ( V_456 )
V_163 -> V_429 . V_205 |= V_207 ;
if ( V_77 -> V_279 == 0 )
V_459 |= V_457 ;
else if ( V_457 )
V_163 -> V_429 . V_205 |= V_208 ;
if ( V_163 -> V_429 . V_205 != ( V_207 | V_208 ) )
V_459 |= V_458 ;
} else if ( V_458 )
V_163 -> V_429 . V_205 |= V_207 | V_208 ;
if ( ! F_268 ( V_77 ) ||
F_38 ( V_294 , & V_77 -> V_236 ) == 0 )
V_459 = 0 ;
F_48 ( & V_77 -> V_248 -> V_301 ) ;
if ( ! V_459 ) {
goto V_345;
}
if ( ! V_163 -> V_446 . V_447 && F_274 ( V_2 , V_116 ) ) {
F_161 ( V_163 -> V_429 . V_226 ) ;
goto V_344;
}
if ( V_163 -> V_429 . V_205 == 0 )
V_116 -> V_348 . V_334 = & V_335 [ V_461 ] ;
if ( V_163 -> V_429 . V_205 == 0 || V_163 -> V_429 . V_205 == V_207 ) {
if ( ! F_240 ( V_2 , V_207 ) )
V_163 -> V_429 . V_265 = F_103 ( V_2 ) -> V_462 ;
else
V_163 -> V_429 . V_265 = NULL ;
}
V_163 -> V_429 . V_252 =
F_96 ( F_103 ( V_2 ) ,
V_163 -> V_429 . V_205 , 0 ) ;
if ( V_163 -> V_69 . V_434 == NULL )
V_163 -> V_429 . V_265 = NULL ;
else if ( V_163 -> V_429 . V_265 == NULL )
V_163 -> V_69 . V_434 = NULL ;
V_163 -> V_128 = V_175 ;
if ( F_73 ( F_103 ( V_2 ) -> V_58 ,
& V_163 -> V_429 . V_167 ,
& V_163 -> V_69 . V_168 ,
V_116 ) != 0 )
F_161 ( V_163 -> V_429 . V_226 ) ;
F_8 ( L_25 , V_34 ) ;
return;
V_345:
V_116 -> V_356 = NULL ;
V_344:
F_71 ( V_116 , & V_163 -> V_69 . V_168 ) ;
}
int F_282 ( struct V_76 * V_77 , T_7 V_237 , int V_463 )
{
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
struct V_239 * ( * V_240 ) ( struct V_241 * , T_7 ) ;
struct V_444 * V_163 ;
struct V_234 * V_235 = V_77 -> V_248 ;
struct V_115 * V_116 ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_461 ] ,
. V_54 = V_77 -> V_248 -> V_306 ,
} ;
struct V_180 V_339 = {
. V_182 = V_14 -> V_111 ,
. V_178 = & V_179 ,
. V_183 = & V_464 ,
. V_341 = V_342 ,
. V_236 = V_343 ,
} ;
int V_329 = - V_174 ;
F_283 ( V_14 -> V_58 , V_465 ,
& V_339 . V_182 , & V_179 ) ;
V_163 = F_104 ( sizeof( * V_163 ) , V_237 ) ;
if ( V_163 == NULL )
goto V_156;
F_51 ( & V_163 -> V_429 . V_167 , & V_163 -> V_69 . V_168 , 1 ) ;
V_163 -> V_2 = V_77 -> V_2 ;
V_163 -> V_77 = V_77 ;
V_163 -> V_429 . V_268 = F_112 ( V_77 -> V_2 ) ;
V_240 = V_14 -> V_58 -> V_59 -> V_240 ;
V_163 -> V_429 . V_226 = V_240 ( & V_77 -> V_248 -> V_245 , V_237 ) ;
if ( F_78 ( V_163 -> V_429 . V_226 ) )
goto V_466;
F_99 ( & V_163 -> V_434 ) ;
V_163 -> V_429 . V_205 = 0 ;
V_163 -> V_446 . V_429 . V_467 = & V_163 -> V_446 . V_467 ;
V_163 -> V_69 . V_434 = & V_163 -> V_434 ;
V_163 -> V_69 . V_226 = V_163 -> V_429 . V_226 ;
V_163 -> V_69 . V_14 = V_14 ;
V_163 -> V_69 . V_448 = - V_451 ;
V_163 -> V_446 . V_447 = F_284 ( V_77 -> V_2 ,
& V_163 -> V_446 . V_429 , & V_163 -> V_446 . V_69 , V_179 . V_54 ) ;
if ( V_163 -> V_446 . V_447 ) {
V_163 -> V_429 . V_450 = & V_163 -> V_446 . V_429 ;
V_163 -> V_69 . V_452 = & V_163 -> V_446 . V_69 ;
}
F_106 ( V_163 -> V_2 -> V_445 ) ;
V_179 . V_337 = & V_163 -> V_429 ;
V_179 . V_338 = & V_163 -> V_69 ;
V_339 . V_185 = V_163 ;
V_116 = F_86 ( & V_339 ) ;
if ( F_78 ( V_116 ) )
return F_87 ( V_116 ) ;
V_329 = 0 ;
if ( V_463 )
V_329 = F_203 ( V_116 ) ;
F_88 ( V_116 ) ;
return V_329 ;
V_466:
F_115 ( V_163 ) ;
V_156:
F_120 ( V_77 ) ;
F_121 ( V_235 ) ;
return V_329 ;
}
static struct V_2 *
F_285 ( struct V_2 * V_3 , struct V_323 * V_324 ,
int V_250 , struct V_5 * V_468 , int * V_414 )
{
struct V_76 * V_77 ;
struct V_1 V_17 = { 0 , 0 , 0 , NULL } , * V_7 = NULL ;
V_7 = F_1 ( V_3 , V_324 -> V_4 , V_468 , & V_17 ) ;
V_77 = F_263 ( V_3 , V_324 , V_250 , V_468 , V_7 , V_414 ) ;
F_4 ( V_7 ) ;
if ( F_78 ( V_77 ) )
return F_173 ( V_77 ) ;
return V_77 -> V_2 ;
}
static void F_286 ( struct V_323 * V_324 , int V_469 )
{
if ( V_324 -> V_77 == NULL )
return;
if ( V_469 )
F_287 ( V_324 -> V_77 , V_324 -> V_281 ) ;
else
F_186 ( V_324 -> V_77 , V_324 -> V_281 ) ;
}
static int F_288 ( struct V_13 * V_14 , struct V_470 * V_471 )
{
T_1 V_265 [ 3 ] = {} , V_472 = V_14 -> V_58 -> V_473 ;
struct V_474 args = {
. V_471 = V_471 ,
. V_265 = V_265 ,
} ;
struct V_475 V_69 = {} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_476 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
} ;
int V_329 ;
int V_477 ;
V_265 [ 0 ] = V_478 |
V_479 |
V_480 |
V_481 |
V_482 ;
if ( V_472 )
V_265 [ 2 ] = V_483 ;
V_329 = F_89 ( V_14 -> V_111 , V_14 , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
if ( V_329 == 0 ) {
switch ( V_472 ) {
case 0 :
V_69 . V_15 [ 1 ] &= V_484 ;
V_69 . V_15 [ 2 ] = 0 ;
break;
case 1 :
V_69 . V_15 [ 2 ] &= V_485 ;
break;
case 2 :
V_69 . V_15 [ 2 ] &= V_486 ;
}
memcpy ( V_14 -> V_15 , V_69 . V_15 , sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_107 &= ~ ( V_487 | V_488 |
V_489 | V_490 |
V_491 | V_492 | V_493 |
V_494 | V_495 |
V_496 | V_497 |
V_9 ) ;
if ( V_69 . V_15 [ 0 ] & V_498 &&
V_69 . V_499 & V_500 )
V_14 -> V_107 |= V_487 ;
if ( V_69 . V_501 != 0 )
V_14 -> V_107 |= V_488 ;
if ( V_69 . V_502 != 0 )
V_14 -> V_107 |= V_489 ;
if ( V_69 . V_15 [ 0 ] & V_41 )
V_14 -> V_107 |= V_490 ;
if ( V_69 . V_15 [ 1 ] & V_404 )
V_14 -> V_107 |= V_491 ;
if ( V_69 . V_15 [ 1 ] & V_503 )
V_14 -> V_107 |= V_492 ;
if ( V_69 . V_15 [ 1 ] & V_504 )
V_14 -> V_107 |= V_493 ;
if ( V_69 . V_15 [ 1 ] & V_505 )
V_14 -> V_107 |= V_494 ;
if ( V_69 . V_15 [ 1 ] & V_398 )
V_14 -> V_107 |= V_495 ;
if ( V_69 . V_15 [ 1 ] & V_506 )
V_14 -> V_107 |= V_496 ;
if ( V_69 . V_15 [ 1 ] & V_401 )
V_14 -> V_107 |= V_497 ;
#ifdef F_289
if ( V_69 . V_15 [ 2 ] & V_407 )
V_14 -> V_107 |= V_9 ;
#endif
memcpy ( V_14 -> V_16 , V_69 . V_15 ,
sizeof( V_14 -> V_15 ) ) ;
V_14 -> V_16 [ 2 ] &= ~ V_407 ;
memcpy ( V_14 -> V_462 , V_69 . V_15 , sizeof( V_14 -> V_462 ) ) ;
V_14 -> V_462 [ 0 ] &= V_507 | V_508 ;
V_14 -> V_462 [ 1 ] &= V_506 | V_401 ;
V_14 -> V_462 [ 2 ] = 0 ;
for ( V_477 = 0 ; V_477 < F_290 ( V_69 . V_509 ) ; V_477 ++ )
V_69 . V_509 [ V_477 ] &= V_69 . V_15 [ V_477 ] ;
memcpy ( V_14 -> V_509 , V_69 . V_509 ,
sizeof( V_14 -> V_509 ) ) ;
V_14 -> V_499 = V_69 . V_499 ;
V_14 -> V_510 = V_69 . V_510 ;
}
return V_329 ;
}
int F_291 ( struct V_13 * V_14 , struct V_470 * V_471 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_36 ( V_14 ,
F_288 ( V_14 , V_471 ) ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_292 ( struct V_13 * V_14 , struct V_470 * V_471 ,
struct V_511 * V_512 )
{
T_1 V_265 [ 3 ] ;
struct V_513 args = {
. V_265 = V_265 ,
} ;
struct V_514 V_69 = {
. V_14 = V_14 ,
. V_434 = V_512 -> V_434 ,
. V_268 = V_471 ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_515 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
} ;
V_265 [ 0 ] = V_267 [ 0 ] ;
V_265 [ 1 ] = V_267 [ 1 ] ;
V_265 [ 2 ] = V_267 [ 2 ] & ~ V_407 ;
F_99 ( V_512 -> V_434 ) ;
return F_89 ( V_14 -> V_111 , V_14 , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
}
static int F_293 ( struct V_13 * V_14 , struct V_470 * V_471 ,
struct V_511 * V_512 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_292 ( V_14 , V_471 , V_512 ) ;
F_294 ( V_14 , V_471 , V_512 -> V_434 , V_8 ) ;
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
static int F_295 ( struct V_13 * V_14 , struct V_470 * V_471 ,
struct V_511 * V_512 , T_5 V_122 )
{
struct V_516 V_517 = {
. V_518 = V_122 ,
} ;
struct V_519 * V_520 ;
V_520 = F_296 ( & V_517 , V_14 -> V_111 ) ;
if ( F_78 ( V_520 ) )
return - V_29 ;
return F_293 ( V_14 , V_471 , V_512 ) ;
}
static int F_297 ( struct V_13 * V_14 , struct V_470 * V_471 ,
struct V_511 * V_512 )
{
static const T_5 V_521 [] = {
V_127 ,
V_126 ,
V_522 ,
V_523 ,
V_524 ,
} ;
int V_329 = - V_24 ;
T_9 V_477 ;
if ( V_14 -> V_525 . V_526 > 0 ) {
for ( V_477 = 0 ; V_477 < V_14 -> V_525 . V_526 ; V_477 ++ ) {
V_329 = F_295 ( V_14 , V_471 , V_512 ,
V_14 -> V_525 . V_527 [ V_477 ] ) ;
if ( V_329 == - V_22 || V_329 == - V_29 )
continue;
break;
}
} else {
for ( V_477 = 0 ; V_477 < F_290 ( V_521 ) ; V_477 ++ ) {
V_329 = F_295 ( V_14 , V_471 , V_512 ,
V_521 [ V_477 ] ) ;
if ( V_329 == - V_22 || V_329 == - V_29 )
continue;
break;
}
}
if ( V_329 == - V_29 )
V_329 = - V_24 ;
return V_329 ;
}
int F_298 ( struct V_13 * V_14 , struct V_470 * V_471 ,
struct V_511 * V_512 ,
bool V_528 )
{
int V_329 = 0 ;
if ( ! V_528 )
V_329 = F_293 ( V_14 , V_471 , V_512 ) ;
if ( V_528 || V_329 == V_22 )
V_329 = V_14 -> V_58 -> V_59 -> V_529 ( V_14 ,
V_471 , V_512 ) ;
if ( V_329 == 0 )
V_329 = F_291 ( V_14 , V_471 ) ;
if ( V_329 == 0 )
V_329 = F_299 ( V_14 , V_471 , V_512 ) ;
return F_7 ( V_329 ) ;
}
static int F_300 ( struct V_13 * V_14 , struct V_470 * V_530 ,
struct V_511 * V_512 )
{
int error ;
struct V_441 * V_434 = V_512 -> V_434 ;
struct V_1 * V_7 = NULL ;
error = F_291 ( V_14 , V_530 ) ;
if ( error < 0 ) {
F_8 ( L_26 , - error ) ;
return error ;
}
V_7 = F_105 ( V_14 , V_419 ) ;
if ( F_78 ( V_7 ) )
return F_87 ( V_7 ) ;
error = F_217 ( V_14 , V_530 , V_434 , V_7 ) ;
if ( error < 0 ) {
F_8 ( L_27 , - error ) ;
goto V_246;
}
if ( V_434 -> V_321 & V_531 &&
! F_301 ( & V_14 -> V_532 , & V_434 -> V_532 ) )
memcpy ( & V_14 -> V_532 , & V_434 -> V_532 , sizeof( V_14 -> V_532 ) ) ;
V_246:
F_114 ( V_7 ) ;
return error ;
}
static int F_302 ( struct V_67 * V_111 , struct V_2 * V_3 ,
const struct V_533 * V_264 , struct V_441 * V_434 ,
struct V_470 * V_471 )
{
int V_329 = - V_174 ;
struct V_534 * V_534 = NULL ;
struct V_535 * V_536 = NULL ;
V_534 = F_303 ( V_419 ) ;
if ( V_534 == NULL )
goto V_156;
V_536 = F_304 ( sizeof( struct V_535 ) , V_419 ) ;
if ( V_536 == NULL )
goto V_156;
V_329 = F_305 ( V_111 , V_3 , V_264 , V_536 , V_534 ) ;
if ( V_329 != 0 )
goto V_156;
if ( F_301 ( & F_103 ( V_3 ) -> V_532 , & V_536 -> V_434 . V_532 ) ) {
F_8 ( L_28
L_29 , V_34 , V_264 -> V_264 ) ;
V_329 = - V_90 ;
goto V_156;
}
F_306 ( & V_536 -> V_434 ) ;
memcpy ( V_434 , & V_536 -> V_434 , sizeof( struct V_441 ) ) ;
memset ( V_471 , 0 , sizeof( struct V_470 ) ) ;
V_156:
if ( V_534 )
F_307 ( V_534 ) ;
F_115 ( V_536 ) ;
return V_329 ;
}
static int F_308 ( struct V_13 * V_14 , struct V_470 * V_471 ,
struct V_441 * V_434 , struct V_1 * V_7 )
{
struct V_537 args = {
. V_268 = V_471 ,
. V_265 = V_14 -> V_15 ,
} ;
struct V_538 V_69 = {
. V_434 = V_434 ,
. V_7 = V_7 ,
. V_14 = V_14 ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_539 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
} ;
args . V_265 = F_6 ( V_14 , V_7 ) ;
F_99 ( V_434 ) ;
return F_89 ( V_14 -> V_111 , V_14 , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
}
static int F_217 ( struct V_13 * V_14 , struct V_470 * V_471 ,
struct V_441 * V_434 , struct V_1 * V_7 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_308 ( V_14 , V_471 , V_434 , V_7 ) ;
F_309 ( V_14 , V_471 , V_434 , V_8 ) ;
V_8 = F_36 ( V_14 , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int
F_310 ( struct V_4 * V_4 , struct V_441 * V_434 ,
struct V_5 * V_6 )
{
struct V_2 * V_2 = F_14 ( V_4 ) ;
struct V_54 * V_55 = NULL ;
struct V_323 * V_324 = NULL ;
struct V_1 * V_7 = NULL ;
int V_329 ;
if ( F_311 ( V_2 ) &&
V_6 -> V_270 & V_436 &&
V_6 -> V_540 < F_312 ( V_2 ) )
F_313 ( V_2 ) ;
F_99 ( V_434 ) ;
if ( V_6 -> V_270 & V_443 )
V_6 -> V_270 &= ~ ( V_403 | V_541 ) ;
if ( ( V_6 -> V_270 & ~ ( V_542 | V_443 ) ) == 0 )
return 0 ;
if ( V_6 -> V_270 & V_542 ) {
V_324 = F_314 ( V_6 -> V_543 ) ;
if ( V_324 )
V_55 = V_324 -> V_55 ;
}
V_7 = F_105 ( F_103 ( V_2 ) , V_419 ) ;
if ( F_78 ( V_7 ) )
return F_87 ( V_7 ) ;
V_329 = F_259 ( V_2 , V_55 , V_434 , V_6 , V_324 , NULL , V_7 ) ;
if ( V_329 == 0 ) {
F_260 ( V_2 , V_6 , V_434 ) ;
F_261 ( V_2 , V_434 , V_7 ) ;
}
F_114 ( V_7 ) ;
return V_329 ;
}
static int F_315 ( struct V_67 * V_68 , struct V_2 * V_3 ,
const struct V_533 * V_264 , struct V_470 * V_471 ,
struct V_441 * V_434 , struct V_1 * V_7 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
int V_329 ;
struct V_544 args = {
. V_265 = V_14 -> V_15 ,
. V_545 = F_112 ( V_3 ) ,
. V_264 = V_264 ,
} ;
struct V_514 V_69 = {
. V_14 = V_14 ,
. V_434 = V_434 ,
. V_7 = V_7 ,
. V_268 = V_471 ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_546 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
} ;
args . V_265 = F_6 ( V_14 , V_7 ) ;
F_99 ( V_434 ) ;
F_8 ( L_30 , V_264 -> V_264 ) ;
V_329 = F_89 ( V_68 , V_14 , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
F_8 ( L_31 , V_329 ) ;
return V_329 ;
}
static void F_316 ( struct V_441 * V_434 )
{
V_434 -> V_321 |= V_357 | V_547 |
V_548 | V_549 ;
V_434 -> V_281 = V_362 | V_550 | V_551 ;
V_434 -> V_552 = 2 ;
}
static int F_317 ( struct V_67 * * V_68 , struct V_2 * V_3 ,
const struct V_533 * V_264 , struct V_470 * V_471 ,
struct V_441 * V_434 , struct V_1 * V_7 )
{
struct V_73 V_74 = { } ;
struct V_67 * V_111 = * V_68 ;
int V_8 ;
do {
V_8 = F_315 ( V_111 , V_3 , V_264 , V_471 , V_434 , V_7 ) ;
F_318 ( V_3 , V_264 , V_8 ) ;
switch ( V_8 ) {
case - V_26 :
V_8 = - V_325 ;
goto V_156;
case - V_90 :
V_8 = F_302 ( V_111 , V_3 , V_264 , V_434 , V_471 ) ;
if ( V_8 == - V_90 )
V_8 = F_36 ( F_103 ( V_3 ) , V_8 , & V_74 ) ;
goto V_156;
case - V_22 :
V_8 = - V_24 ;
if ( V_111 != * V_68 )
goto V_156;
V_111 = F_319 ( V_111 , V_3 , V_264 ) ;
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
F_320 ( V_111 ) ;
return V_8 ;
}
static int F_321 ( struct V_2 * V_3 , const struct V_533 * V_264 ,
struct V_470 * V_471 , struct V_441 * V_434 ,
struct V_1 * V_7 )
{
int V_329 ;
struct V_67 * V_111 = F_322 ( V_3 ) ;
V_329 = F_317 ( & V_111 , V_3 , V_264 , V_471 , V_434 , V_7 ) ;
if ( V_111 != F_322 ( V_3 ) ) {
F_320 ( V_111 ) ;
F_316 ( V_434 ) ;
}
return V_329 ;
}
struct V_67 *
F_323 ( struct V_2 * V_3 , const struct V_533 * V_264 ,
struct V_470 * V_471 , struct V_441 * V_434 )
{
struct V_67 * V_111 = F_322 ( V_3 ) ;
int V_329 ;
V_329 = F_317 ( & V_111 , V_3 , V_264 , V_471 , V_434 , NULL ) ;
if ( V_329 < 0 )
return F_79 ( V_329 ) ;
return ( V_111 == F_322 ( V_3 ) ) ? F_324 ( V_111 ) : V_111 ;
}
static int F_325 ( struct V_2 * V_2 ,
struct V_470 * V_471 , struct V_441 * V_434 ,
struct V_1 * V_7 )
{
struct V_67 * V_68 = F_322 ( V_2 ) ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
int V_329 ;
struct V_553 args = {
. V_265 = V_14 -> V_15 ,
. V_268 = F_112 ( V_2 ) ,
} ;
struct V_554 V_69 = {
. V_14 = V_14 ,
. V_434 = V_434 ,
. V_7 = V_7 ,
. V_268 = V_471 ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_555 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
} ;
args . V_265 = F_6 ( V_14 , V_7 ) ;
F_99 ( V_434 ) ;
F_8 ( L_32 , V_2 -> V_556 ) ;
V_329 = F_89 ( V_68 , V_14 , & V_179 , & args . V_167 ,
& V_69 . V_168 , 0 ) ;
F_8 ( L_33 , V_329 ) ;
return V_329 ;
}
static int F_326 ( struct V_2 * V_2 , struct V_470 * V_471 ,
struct V_441 * V_434 , struct V_1 * V_7 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_325 ( V_2 , V_471 , V_434 , V_7 ) ;
F_327 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_2 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_328 ( struct V_2 * V_2 , struct V_372 * V_557 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_558 args = {
. V_268 = F_112 ( V_2 ) ,
. V_265 = V_14 -> V_462 ,
} ;
struct V_559 V_69 = {
. V_14 = V_14 ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_560 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
. V_54 = V_557 -> V_55 ,
} ;
int V_281 = V_557 -> V_374 ;
int V_329 = 0 ;
if ( V_281 & V_561 )
args . V_231 |= V_254 ;
if ( F_213 ( V_2 -> V_377 ) ) {
if ( V_281 & V_562 )
args . V_231 |= V_255 | V_256 | V_563 ;
if ( V_281 & V_564 )
args . V_231 |= V_378 ;
} else {
if ( V_281 & V_562 )
args . V_231 |= V_255 | V_256 ;
if ( V_281 & V_564 )
args . V_231 |= V_257 ;
}
V_69 . V_434 = F_329 () ;
if ( V_69 . V_434 == NULL )
return - V_174 ;
V_329 = F_89 ( V_14 -> V_111 , V_14 , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
if ( ! V_329 ) {
F_214 ( V_557 , V_69 . V_231 ) ;
F_168 ( V_2 , V_69 . V_434 ) ;
}
F_330 ( V_69 . V_434 ) ;
return V_329 ;
}
static int F_331 ( struct V_2 * V_2 , struct V_372 * V_557 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_328 ( V_2 , V_557 ) ;
F_332 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_2 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_333 ( struct V_2 * V_2 , struct V_534 * V_534 ,
unsigned int V_51 , unsigned int V_565 )
{
struct V_566 args = {
. V_268 = F_112 ( V_2 ) ,
. V_51 = V_51 ,
. V_565 = V_565 ,
. V_45 = & V_534 ,
} ;
struct V_567 V_69 ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_568 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
} ;
return F_89 ( F_103 ( V_2 ) -> V_111 , F_103 ( V_2 ) , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
}
static int F_334 ( struct V_2 * V_2 , struct V_534 * V_534 ,
unsigned int V_51 , unsigned int V_565 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_333 ( V_2 , V_534 , V_51 , V_565 ) ;
F_335 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_2 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int
F_336 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_5 * V_6 ,
int V_236 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_1 V_17 , * V_442 = NULL ;
struct V_323 * V_324 ;
struct V_76 * V_77 ;
int V_329 = 0 ;
V_324 = F_337 ( V_4 , V_207 , NULL ) ;
if ( F_78 ( V_324 ) )
return F_87 ( V_324 ) ;
V_442 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
if ( ! ( V_14 -> V_15 [ 2 ] & V_405 ) )
V_6 -> V_10 &= ~ F_109 () ;
V_77 = F_263 ( V_3 , V_324 , V_236 , V_6 , V_442 , NULL ) ;
if ( F_78 ( V_77 ) ) {
V_329 = F_87 ( V_77 ) ;
goto V_156;
}
V_156:
F_4 ( V_442 ) ;
F_193 ( V_324 ) ;
return V_329 ;
}
static int F_338 ( struct V_2 * V_3 , const struct V_533 * V_264 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_569 args = {
. V_268 = F_112 ( V_3 ) ,
. V_264 = * V_264 ,
} ;
struct V_570 V_69 = {
. V_14 = V_14 ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_571 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
} ;
unsigned long V_128 = V_175 ;
int V_329 ;
V_329 = F_89 ( V_14 -> V_111 , V_14 , & V_179 , & args . V_167 , & V_69 . V_168 , 1 ) ;
if ( V_329 == 0 )
F_90 ( V_3 , & V_69 . V_187 , V_128 ) ;
return V_329 ;
}
static int F_339 ( struct V_2 * V_3 , const struct V_533 * V_264 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_338 ( V_3 , V_264 ) ;
F_340 ( V_3 , V_264 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_3 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static void F_341 ( struct V_178 * V_179 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_569 * args = V_179 -> V_337 ;
struct V_570 * V_69 = V_179 -> V_338 ;
V_69 -> V_14 = V_14 ;
V_179 -> V_334 = & V_335 [ V_571 ] ;
F_51 ( & args -> V_167 , & V_69 -> V_168 , 1 ) ;
F_99 ( V_69 -> V_572 ) ;
}
static void F_342 ( struct V_115 * V_116 , struct V_573 * V_165 )
{
F_73 ( F_184 ( V_165 -> V_4 -> V_247 ) -> V_58 ,
& V_165 -> args . V_167 ,
& V_165 -> V_69 . V_168 ,
V_116 ) ;
}
static int F_343 ( struct V_115 * V_116 , struct V_2 * V_3 )
{
struct V_573 * V_165 = V_116 -> V_574 ;
struct V_570 * V_69 = & V_165 -> V_69 ;
if ( ! F_71 ( V_116 , & V_69 -> V_168 ) )
return 0 ;
if ( F_43 ( V_116 , V_69 -> V_14 , NULL ,
& V_165 -> V_63 ) == - V_121 )
return 0 ;
if ( V_116 -> V_120 == 0 )
F_90 ( V_3 , & V_69 -> V_187 , V_69 -> V_572 -> V_382 ) ;
return 1 ;
}
static void F_344 ( struct V_178 * V_179 , struct V_2 * V_3 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_575 * V_429 = V_179 -> V_337 ;
struct V_576 * V_69 = V_179 -> V_338 ;
V_179 -> V_334 = & V_335 [ V_577 ] ;
V_69 -> V_14 = V_14 ;
F_51 ( & V_429 -> V_167 , & V_69 -> V_168 , 1 ) ;
}
static void F_345 ( struct V_115 * V_116 , struct V_578 * V_165 )
{
F_73 ( F_103 ( V_165 -> V_579 ) -> V_58 ,
& V_165 -> args . V_167 ,
& V_165 -> V_69 . V_168 ,
V_116 ) ;
}
static int F_346 ( struct V_115 * V_116 , struct V_2 * V_579 ,
struct V_2 * V_580 )
{
struct V_578 * V_165 = V_116 -> V_574 ;
struct V_576 * V_69 = & V_165 -> V_69 ;
if ( ! F_71 ( V_116 , & V_69 -> V_168 ) )
return 0 ;
if ( F_43 ( V_116 , V_69 -> V_14 , NULL , & V_165 -> V_63 ) == - V_121 )
return 0 ;
if ( V_116 -> V_120 == 0 ) {
F_90 ( V_579 , & V_69 -> V_581 , V_69 -> V_582 -> V_382 ) ;
if ( V_580 != V_579 )
F_90 ( V_580 , & V_69 -> V_583 , V_69 -> V_584 -> V_382 ) ;
}
return 1 ;
}
static int F_347 ( struct V_2 * V_2 , struct V_2 * V_3 , const struct V_533 * V_264 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_585 V_429 = {
. V_268 = F_112 ( V_2 ) ,
. V_545 = F_112 ( V_3 ) ,
. V_264 = V_264 ,
. V_265 = V_14 -> V_15 ,
} ;
struct V_586 V_69 = {
. V_14 = V_14 ,
. V_7 = NULL ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_587 ] ,
. V_337 = & V_429 ,
. V_338 = & V_69 ,
} ;
int V_329 = - V_174 ;
V_69 . V_434 = F_329 () ;
if ( V_69 . V_434 == NULL )
goto V_156;
V_69 . V_7 = F_105 ( V_14 , V_419 ) ;
if ( F_78 ( V_69 . V_7 ) ) {
V_329 = F_87 ( V_69 . V_7 ) ;
goto V_156;
}
V_429 . V_265 = F_6 ( V_14 , V_69 . V_7 ) ;
V_329 = F_89 ( V_14 -> V_111 , V_14 , & V_179 , & V_429 . V_167 , & V_69 . V_168 , 1 ) ;
if ( ! V_329 ) {
F_90 ( V_3 , & V_69 . V_187 , V_69 . V_434 -> V_382 ) ;
V_329 = F_348 ( V_2 , V_69 . V_434 ) ;
if ( ! V_329 )
F_261 ( V_2 , V_69 . V_434 , V_69 . V_7 ) ;
}
F_114 ( V_69 . V_7 ) ;
V_156:
F_330 ( V_69 . V_434 ) ;
return V_329 ;
}
static int F_349 ( struct V_2 * V_2 , struct V_2 * V_3 , const struct V_533 * V_264 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_36 ( F_103 ( V_2 ) ,
F_347 ( V_2 , V_3 , V_264 ) ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static struct V_588 * F_350 ( struct V_2 * V_3 ,
const struct V_533 * V_264 , struct V_5 * V_6 , T_1 V_589 )
{
struct V_588 * V_165 ;
V_165 = F_104 ( sizeof( * V_165 ) , V_419 ) ;
if ( V_165 != NULL ) {
struct V_13 * V_14 = F_103 ( V_3 ) ;
V_165 -> V_7 = F_105 ( V_14 , V_419 ) ;
if ( F_78 ( V_165 -> V_7 ) )
goto V_333;
V_165 -> V_179 . V_334 = & V_335 [ V_590 ] ;
V_165 -> V_179 . V_337 = & V_165 -> V_429 ;
V_165 -> V_179 . V_338 = & V_165 -> V_69 ;
V_165 -> V_429 . V_545 = F_112 ( V_3 ) ;
V_165 -> V_429 . V_14 = V_14 ;
V_165 -> V_429 . V_264 = V_264 ;
V_165 -> V_429 . V_40 = V_6 ;
V_165 -> V_429 . V_589 = V_589 ;
V_165 -> V_429 . V_265 = F_6 ( V_14 , V_165 -> V_7 ) ;
V_165 -> V_429 . V_251 = F_109 () ;
V_165 -> V_69 . V_14 = V_14 ;
V_165 -> V_69 . V_268 = & V_165 -> V_268 ;
V_165 -> V_69 . V_434 = & V_165 -> V_434 ;
V_165 -> V_69 . V_7 = V_165 -> V_7 ;
F_99 ( V_165 -> V_69 . V_434 ) ;
}
return V_165 ;
V_333:
F_115 ( V_165 ) ;
return NULL ;
}
static int F_351 ( struct V_2 * V_3 , struct V_4 * V_4 , struct V_588 * V_165 )
{
int V_329 = F_89 ( F_103 ( V_3 ) -> V_111 , F_103 ( V_3 ) , & V_165 -> V_179 ,
& V_165 -> V_429 . V_167 , & V_165 -> V_69 . V_168 , 1 ) ;
if ( V_329 == 0 ) {
F_90 ( V_3 , & V_165 -> V_69 . V_591 ,
V_165 -> V_69 . V_434 -> V_382 ) ;
V_329 = F_352 ( V_4 , V_165 -> V_69 . V_268 , V_165 -> V_69 . V_434 , V_165 -> V_69 . V_7 ) ;
}
return V_329 ;
}
static void F_353 ( struct V_588 * V_165 )
{
F_114 ( V_165 -> V_7 ) ;
F_115 ( V_165 ) ;
}
static int F_354 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_534 * V_534 , unsigned int V_12 , struct V_5 * V_6 ,
struct V_1 * V_7 )
{
struct V_588 * V_165 ;
int V_329 = - V_592 ;
if ( V_12 > V_593 )
goto V_156;
V_329 = - V_174 ;
V_165 = F_350 ( V_3 , & V_4 -> V_11 , V_6 , V_594 ) ;
if ( V_165 == NULL )
goto V_156;
V_165 -> V_179 . V_334 = & V_335 [ V_595 ] ;
V_165 -> V_429 . V_272 . V_596 . V_45 = & V_534 ;
V_165 -> V_429 . V_272 . V_596 . V_12 = V_12 ;
V_165 -> V_429 . V_7 = V_7 ;
V_329 = F_351 ( V_3 , V_4 , V_165 ) ;
F_353 ( V_165 ) ;
V_156:
return V_329 ;
}
static int F_355 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_534 * V_534 , unsigned int V_12 , struct V_5 * V_6 )
{
struct V_73 V_74 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
do {
V_8 = F_354 ( V_3 , V_4 , V_534 , V_12 , V_6 , V_7 ) ;
F_356 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_3 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_357 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 )
{
struct V_588 * V_165 ;
int V_329 = - V_174 ;
V_165 = F_350 ( V_3 , & V_4 -> V_11 , V_6 , V_48 ) ;
if ( V_165 == NULL )
goto V_156;
V_165 -> V_429 . V_7 = V_7 ;
V_329 = F_351 ( V_3 , V_4 , V_165 ) ;
F_353 ( V_165 ) ;
V_156:
return V_329 ;
}
static int F_358 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_73 V_74 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
if ( ! ( V_14 -> V_15 [ 2 ] & V_405 ) )
V_6 -> V_10 &= ~ F_109 () ;
do {
V_8 = F_357 ( V_3 , V_4 , V_6 , V_7 ) ;
F_359 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_3 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_360 ( struct V_4 * V_4 , struct V_54 * V_55 ,
T_2 V_36 , struct V_534 * * V_45 , unsigned int V_52 , bool V_597 )
{
struct V_2 * V_3 = F_14 ( V_4 ) ;
struct V_38 args = {
. V_268 = F_112 ( V_3 ) ,
. V_45 = V_45 ,
. V_51 = 0 ,
. V_52 = V_52 ,
. V_265 = F_103 ( F_14 ( V_4 ) ) -> V_15 ,
. V_597 = V_597 ,
} ;
struct V_598 V_69 ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_599 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
. V_54 = V_55 ,
} ;
int V_329 ;
F_8 ( L_34 , V_34 ,
V_4 ,
( unsigned long long ) V_36 ) ;
F_9 ( V_36 , F_91 ( V_3 ) -> V_600 , V_4 , & args ) ;
V_69 . V_51 = args . V_51 ;
V_329 = F_89 ( F_103 ( V_3 ) -> V_111 , F_103 ( V_3 ) , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
if ( V_329 >= 0 ) {
memcpy ( F_91 ( V_3 ) -> V_600 , V_69 . V_37 . V_165 , V_601 ) ;
V_329 += args . V_51 ;
}
F_361 ( V_3 ) ;
F_8 ( L_35 , V_34 , V_329 ) ;
return V_329 ;
}
static int F_362 ( struct V_4 * V_4 , struct V_54 * V_55 ,
T_2 V_36 , struct V_534 * * V_45 , unsigned int V_52 , bool V_597 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_360 ( V_4 , V_55 , V_36 ,
V_45 , V_52 , V_597 ) ;
F_363 ( F_14 ( V_4 ) , V_8 ) ;
V_8 = F_36 ( F_103 ( F_14 ( V_4 ) ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_364 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , struct V_1 * V_7 , T_10 V_602 )
{
struct V_588 * V_165 ;
int V_281 = V_6 -> V_10 ;
int V_329 = - V_174 ;
V_165 = F_350 ( V_3 , & V_4 -> V_11 , V_6 , V_603 ) ;
if ( V_165 == NULL )
goto V_156;
if ( F_365 ( V_281 ) )
V_165 -> V_429 . V_589 = V_604 ;
else if ( F_366 ( V_281 ) ) {
V_165 -> V_429 . V_589 = V_605 ;
V_165 -> V_429 . V_272 . V_606 . V_607 = F_367 ( V_602 ) ;
V_165 -> V_429 . V_272 . V_606 . V_608 = F_368 ( V_602 ) ;
}
else if ( F_369 ( V_281 ) ) {
V_165 -> V_429 . V_589 = V_609 ;
V_165 -> V_429 . V_272 . V_606 . V_607 = F_367 ( V_602 ) ;
V_165 -> V_429 . V_272 . V_606 . V_608 = F_368 ( V_602 ) ;
} else if ( ! F_370 ( V_281 ) ) {
V_329 = - V_27 ;
goto V_333;
}
V_165 -> V_429 . V_7 = V_7 ;
V_329 = F_351 ( V_3 , V_4 , V_165 ) ;
V_333:
F_353 ( V_165 ) ;
V_156:
return V_329 ;
}
static int F_371 ( struct V_2 * V_3 , struct V_4 * V_4 ,
struct V_5 * V_6 , T_10 V_602 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
struct V_73 V_74 = { } ;
struct V_1 V_17 , * V_7 = NULL ;
int V_8 ;
V_7 = F_1 ( V_3 , V_4 , V_6 , & V_17 ) ;
if ( ! ( V_14 -> V_15 [ 2 ] & V_405 ) )
V_6 -> V_10 &= ~ F_109 () ;
do {
V_8 = F_364 ( V_3 , V_4 , V_6 , V_7 , V_602 ) ;
F_372 ( V_3 , & V_4 -> V_11 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_3 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
F_4 ( V_7 ) ;
return V_8 ;
}
static int F_373 ( struct V_13 * V_14 , struct V_470 * V_471 ,
struct V_610 * V_611 )
{
struct V_612 args = {
. V_268 = V_471 ,
. V_265 = V_14 -> V_15 ,
} ;
struct V_613 V_69 = {
. V_611 = V_611 ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_614 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
} ;
F_99 ( V_611 -> V_434 ) ;
return F_89 ( V_14 -> V_111 , V_14 , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
}
static int F_374 ( struct V_13 * V_14 , struct V_470 * V_471 , struct V_610 * V_611 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_36 ( V_14 ,
F_373 ( V_14 , V_471 , V_611 ) ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_375 ( struct V_13 * V_14 , struct V_470 * V_471 ,
struct V_511 * V_615 )
{
struct V_616 args = {
. V_268 = V_471 ,
. V_265 = V_14 -> V_15 ,
} ;
struct V_617 V_69 = {
. V_615 = V_615 ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_618 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
} ;
return F_89 ( V_14 -> V_111 , V_14 , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
}
static int F_299 ( struct V_13 * V_14 , struct V_470 * V_471 , struct V_511 * V_615 )
{
struct V_73 V_74 = { } ;
unsigned long V_619 = V_175 ;
int V_8 ;
do {
V_8 = F_375 ( V_14 , V_471 , V_615 ) ;
F_376 ( V_14 , V_471 , V_615 -> V_434 , V_8 ) ;
if ( V_8 == 0 ) {
F_377 ( V_14 -> V_58 ,
V_615 -> V_620 * V_101 ,
V_619 ) ;
break;
}
V_8 = F_36 ( V_14 , V_8 , & V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_378 ( struct V_13 * V_14 , struct V_470 * V_471 , struct V_511 * V_615 )
{
int error ;
F_99 ( V_615 -> V_434 ) ;
error = F_299 ( V_14 , V_471 , V_615 ) ;
if ( error == 0 ) {
V_14 -> V_621 = V_615 -> V_622 ;
F_379 ( V_14 , V_471 , V_615 ) ;
}
return error ;
}
static int F_380 ( struct V_13 * V_14 , struct V_470 * V_471 ,
struct V_623 * V_624 )
{
struct V_625 args = {
. V_268 = V_471 ,
. V_265 = V_14 -> V_15 ,
} ;
struct V_626 V_69 = {
. V_624 = V_624 ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_627 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
} ;
if ( ( args . V_265 [ 0 ] & V_628 [ 0 ] ) == 0 ) {
memset ( V_624 , 0 , sizeof( * V_624 ) ) ;
return 0 ;
}
F_99 ( V_624 -> V_434 ) ;
return F_89 ( V_14 -> V_111 , V_14 , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
}
static int F_381 ( struct V_13 * V_14 , struct V_470 * V_471 ,
struct V_623 * V_624 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_36 ( V_14 ,
F_380 ( V_14 , V_471 , V_624 ) ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
int F_382 ( T_4 * V_53 ,
const struct V_323 * V_324 ,
const struct V_437 * V_438 ,
T_6 V_205 )
{
return F_270 ( V_324 -> V_77 , V_205 , V_438 , V_53 , NULL ) ;
}
static bool F_383 ( T_4 * V_53 ,
const struct V_323 * V_324 ,
const struct V_437 * V_438 ,
T_6 V_205 )
{
T_4 V_629 ;
if ( F_382 ( & V_629 , V_324 , V_438 , V_205 ) == - V_35 )
return true ;
return F_155 ( V_53 , & V_629 ) ;
}
static bool F_384 ( int V_8 )
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
static int F_385 ( struct V_115 * V_116 , struct V_630 * V_631 )
{
struct V_13 * V_14 = F_103 ( V_631 -> V_2 ) ;
F_386 ( V_631 , V_116 -> V_120 ) ;
if ( V_116 -> V_120 < 0 ) {
struct V_73 V_74 = {
. V_2 = V_631 -> V_2 ,
. V_77 = V_631 -> args . V_632 -> V_77 ,
. V_53 = & V_631 -> args . V_53 ,
} ;
V_116 -> V_120 = F_39 ( V_116 ,
V_14 , V_116 -> V_120 , & V_74 ) ;
if ( V_74 . V_80 ) {
F_66 ( V_116 ) ;
return - V_121 ;
}
}
if ( V_116 -> V_120 > 0 )
F_49 ( V_14 , V_631 -> V_128 ) ;
return 0 ;
}
static bool F_387 ( struct V_115 * V_116 ,
struct V_633 * args )
{
if ( ! F_384 ( V_116 -> V_120 ) ||
F_383 ( & args -> V_53 ,
args -> V_632 ,
args -> V_634 ,
V_207 ) )
return false ;
F_66 ( V_116 ) ;
return true ;
}
static int F_388 ( struct V_115 * V_116 , struct V_630 * V_631 )
{
F_8 ( L_36 , V_34 ) ;
if ( ! F_71 ( V_116 , & V_631 -> V_69 . V_168 ) )
return - V_121 ;
if ( F_387 ( V_116 , & V_631 -> args ) )
return - V_121 ;
if ( V_116 -> V_120 > 0 )
F_361 ( V_631 -> V_2 ) ;
return V_631 -> V_635 ? V_631 -> V_635 ( V_116 , V_631 ) :
F_385 ( V_116 , V_631 ) ;
}
static void F_389 ( struct V_630 * V_631 ,
struct V_178 * V_179 )
{
V_631 -> V_128 = V_175 ;
if ( ! V_631 -> V_635 )
V_631 -> V_635 = F_385 ;
V_179 -> V_334 = & V_335 [ V_636 ] ;
F_51 ( & V_631 -> args . V_167 , & V_631 -> V_69 . V_168 , 0 ) ;
}
static int F_390 ( struct V_115 * V_116 ,
struct V_630 * V_631 )
{
if ( F_73 ( F_103 ( V_631 -> V_2 ) -> V_58 ,
& V_631 -> args . V_167 ,
& V_631 -> V_69 . V_168 ,
V_116 ) )
return 0 ;
if ( F_382 ( & V_631 -> args . V_53 , V_631 -> args . V_632 ,
V_631 -> args . V_634 ,
V_631 -> V_637 ) == - V_35 )
return - V_35 ;
if ( F_391 ( F_38 ( V_638 , & V_631 -> args . V_632 -> V_236 ) ) )
return - V_35 ;
return 0 ;
}
static int F_392 ( struct V_115 * V_116 ,
struct V_630 * V_631 )
{
struct V_2 * V_2 = V_631 -> V_2 ;
F_393 ( V_631 , V_116 -> V_120 ) ;
if ( V_116 -> V_120 < 0 ) {
struct V_73 V_74 = {
. V_2 = V_631 -> V_2 ,
. V_77 = V_631 -> args . V_632 -> V_77 ,
. V_53 = & V_631 -> args . V_53 ,
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
F_49 ( F_103 ( V_2 ) , V_631 -> V_128 ) ;
F_394 ( V_631 ) ;
}
return 0 ;
}
static bool F_395 ( struct V_115 * V_116 ,
struct V_633 * args )
{
if ( ! F_384 ( V_116 -> V_120 ) ||
F_383 ( & args -> V_53 ,
args -> V_632 ,
args -> V_634 ,
V_208 ) )
return false ;
F_66 ( V_116 ) ;
return true ;
}
static int F_396 ( struct V_115 * V_116 , struct V_630 * V_631 )
{
if ( ! F_71 ( V_116 , & V_631 -> V_69 . V_168 ) )
return - V_121 ;
if ( F_395 ( V_116 , & V_631 -> args ) )
return - V_121 ;
return V_631 -> V_635 ? V_631 -> V_635 ( V_116 , V_631 ) :
F_392 ( V_116 , V_631 ) ;
}
static
bool F_397 ( struct V_630 * V_631 )
{
if ( V_631 -> V_639 != NULL || V_631 -> V_640 != NULL )
return false ;
return F_240 ( V_631 -> V_2 , V_207 ) == 0 ;
}
static void F_398 ( struct V_630 * V_631 ,
struct V_178 * V_179 )
{
struct V_13 * V_14 = F_103 ( V_631 -> V_2 ) ;
if ( ! F_397 ( V_631 ) ) {
V_631 -> args . V_265 = NULL ;
V_631 -> V_69 . V_434 = NULL ;
} else
V_631 -> args . V_265 = V_14 -> V_462 ;
if ( ! V_631 -> V_635 )
V_631 -> V_635 = F_392 ;
V_631 -> V_69 . V_14 = V_14 ;
V_631 -> V_128 = V_175 ;
V_179 -> V_334 = & V_335 [ V_641 ] ;
F_51 ( & V_631 -> args . V_167 , & V_631 -> V_69 . V_168 , 1 ) ;
}
static void F_399 ( struct V_115 * V_116 , struct V_642 * V_165 )
{
F_73 ( F_103 ( V_165 -> V_2 ) -> V_58 ,
& V_165 -> args . V_167 ,
& V_165 -> V_69 . V_168 ,
V_116 ) ;
}
static int F_400 ( struct V_115 * V_116 , struct V_642 * V_165 )
{
struct V_2 * V_2 = V_165 -> V_2 ;
F_401 ( V_165 , V_116 -> V_120 ) ;
if ( F_43 ( V_116 , F_103 ( V_2 ) ,
NULL , NULL ) == - V_121 ) {
F_66 ( V_116 ) ;
return - V_121 ;
}
return 0 ;
}
static int F_402 ( struct V_115 * V_116 , struct V_642 * V_165 )
{
if ( ! F_71 ( V_116 , & V_165 -> V_69 . V_168 ) )
return - V_121 ;
return V_165 -> V_643 ( V_116 , V_165 ) ;
}
static void F_403 ( struct V_642 * V_165 , struct V_178 * V_179 )
{
struct V_13 * V_14 = F_103 ( V_165 -> V_2 ) ;
if ( V_165 -> V_643 == NULL )
V_165 -> V_643 = F_400 ;
V_165 -> V_69 . V_14 = V_14 ;
V_179 -> V_334 = & V_335 [ V_644 ] ;
F_51 ( & V_165 -> args . V_167 , & V_165 -> V_69 . V_168 , 1 ) ;
}
static void F_404 ( void * V_163 )
{
struct V_645 * V_165 = V_163 ;
struct V_58 * V_75 = V_165 -> V_111 ;
if ( F_405 ( & V_75 -> V_646 ) > 1 )
F_406 ( V_75 ) ;
F_407 ( V_75 ) ;
F_115 ( V_165 ) ;
}
static void F_408 ( struct V_115 * V_116 , void * V_163 )
{
struct V_645 * V_165 = V_163 ;
struct V_58 * V_75 = V_165 -> V_111 ;
unsigned long V_128 = V_165 -> V_128 ;
F_409 ( V_75 , V_116 -> V_120 ) ;
switch ( V_116 -> V_120 ) {
case 0 :
break;
case - V_91 :
F_31 ( V_75 ) ;
break;
default:
if ( F_38 ( V_647 , & V_75 -> V_648 ) == 0 )
return;
if ( V_116 -> V_120 != V_649 ) {
F_29 ( V_75 ) ;
return;
}
F_410 ( V_75 ) ;
}
F_45 ( V_75 , V_128 ) ;
}
static int F_411 ( struct V_58 * V_75 , struct V_54 * V_55 , unsigned V_650 )
{
struct V_178 V_179 = {
. V_334 = & V_335 [ V_651 ] ,
. V_337 = V_75 ,
. V_54 = V_55 ,
} ;
struct V_645 * V_165 ;
if ( V_650 == 0 )
return 0 ;
if ( ! F_412 ( & V_75 -> V_646 ) )
return - V_35 ;
V_165 = F_304 ( sizeof( * V_165 ) , V_326 ) ;
if ( V_165 == NULL ) {
F_407 ( V_75 ) ;
return - V_174 ;
}
V_165 -> V_111 = V_75 ;
V_165 -> V_128 = V_175 ;
return F_413 ( V_75 -> V_123 , & V_179 , V_652 ,
& V_653 , V_165 ) ;
}
static int F_414 ( struct V_58 * V_75 , struct V_54 * V_55 )
{
struct V_178 V_179 = {
. V_334 = & V_335 [ V_651 ] ,
. V_337 = V_75 ,
. V_54 = V_55 ,
} ;
unsigned long V_619 = V_175 ;
int V_329 ;
V_329 = F_415 ( V_75 -> V_123 , & V_179 , V_652 ) ;
if ( V_329 < 0 )
return V_329 ;
F_45 ( V_75 , V_619 ) ;
return 0 ;
}
static inline int F_416 ( struct V_13 * V_14 )
{
return V_14 -> V_107 & V_487 ;
}
static int F_417 ( const void * V_654 , T_9 V_655 ,
struct V_534 * * V_45 )
{
struct V_534 * V_656 , * * V_657 ;
int V_658 = 0 ;
T_9 V_12 ;
V_657 = V_45 ;
do {
V_12 = F_418 ( T_9 , V_659 , V_655 ) ;
V_656 = F_303 ( V_419 ) ;
if ( V_656 == NULL )
goto V_660;
memcpy ( F_419 ( V_656 ) , V_654 , V_12 ) ;
V_654 += V_12 ;
V_655 -= V_12 ;
* V_45 ++ = V_656 ;
V_658 ++ ;
} while ( V_655 != 0 );
return V_658 ;
V_660:
for(; V_658 > 0 ; V_658 -- )
F_307 ( V_657 [ V_658 - 1 ] ) ;
return - V_174 ;
}
static void F_420 ( struct V_2 * V_2 , struct V_661 * V_662 )
{
struct V_188 * V_189 = F_91 ( V_2 ) ;
F_46 ( & V_2 -> V_190 ) ;
F_115 ( V_189 -> V_663 ) ;
V_189 -> V_663 = V_662 ;
F_48 ( & V_2 -> V_190 ) ;
}
static void F_421 ( struct V_2 * V_2 )
{
F_420 ( V_2 , NULL ) ;
}
static inline T_11 F_422 ( struct V_2 * V_2 , char * V_654 , T_9 V_655 )
{
struct V_188 * V_189 = F_91 ( V_2 ) ;
struct V_661 * V_662 ;
int V_64 = - V_325 ;
F_46 ( & V_2 -> V_190 ) ;
V_662 = V_189 -> V_663 ;
if ( V_662 == NULL )
goto V_156;
if ( V_654 == NULL )
goto V_664;
if ( V_662 -> V_665 == 0 )
goto V_156;
V_64 = - V_666 ;
if ( V_662 -> V_12 > V_655 )
goto V_156;
memcpy ( V_654 , V_662 -> V_165 , V_662 -> V_12 ) ;
V_664:
V_64 = V_662 -> V_12 ;
V_156:
F_48 ( & V_2 -> V_190 ) ;
return V_64 ;
}
static void F_423 ( struct V_2 * V_2 , struct V_534 * * V_45 , T_9 V_51 , T_9 V_667 )
{
struct V_661 * V_662 ;
T_9 V_655 = sizeof( * V_662 ) + V_667 ;
if ( V_655 <= V_659 ) {
V_662 = F_304 ( V_655 , V_419 ) ;
if ( V_662 == NULL )
goto V_156;
V_662 -> V_665 = 1 ;
F_424 ( V_662 -> V_165 , V_45 , V_51 , V_667 ) ;
} else {
V_662 = F_304 ( sizeof( * V_662 ) , V_419 ) ;
if ( V_662 == NULL )
goto V_156;
V_662 -> V_665 = 0 ;
}
V_662 -> V_12 = V_667 ;
V_156:
F_420 ( V_2 , V_662 ) ;
}
static T_11 F_425 ( struct V_2 * V_2 , void * V_654 , T_9 V_655 )
{
struct V_534 * V_45 [ V_668 + 1 ] = { NULL , } ;
struct V_669 args = {
. V_268 = F_112 ( V_2 ) ,
. V_670 = V_45 ,
. V_667 = V_655 ,
} ;
struct V_671 V_69 = {
. V_667 = V_655 ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_672 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
} ;
unsigned int V_673 = F_426 ( V_655 , V_659 ) + 1 ;
int V_64 = - V_174 , V_477 ;
if ( V_673 > F_290 ( V_45 ) )
return - V_666 ;
for ( V_477 = 0 ; V_477 < V_673 ; V_477 ++ ) {
V_45 [ V_477 ] = F_303 ( V_419 ) ;
if ( ! V_45 [ V_477 ] )
goto V_333;
}
V_69 . V_674 = F_303 ( V_419 ) ;
if ( ! V_69 . V_674 )
goto V_333;
args . V_667 = V_673 * V_659 ;
F_8 ( L_37 ,
V_34 , V_654 , V_655 , V_673 , args . V_667 ) ;
V_64 = F_89 ( F_103 ( V_2 ) -> V_111 , F_103 ( V_2 ) ,
& V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
if ( V_64 )
goto V_333;
if ( V_69 . V_675 & V_676 ) {
if ( V_654 == NULL )
goto V_677;
V_64 = - V_666 ;
goto V_333;
}
F_423 ( V_2 , V_45 , V_69 . V_678 , V_69 . V_667 ) ;
if ( V_654 ) {
if ( V_69 . V_667 > V_655 ) {
V_64 = - V_666 ;
goto V_333;
}
F_424 ( V_654 , V_45 , V_69 . V_678 , V_69 . V_667 ) ;
}
V_677:
V_64 = V_69 . V_667 ;
V_333:
for ( V_477 = 0 ; V_477 < V_673 ; V_477 ++ )
if ( V_45 [ V_477 ] )
F_307 ( V_45 [ V_477 ] ) ;
if ( V_69 . V_674 )
F_307 ( V_69 . V_674 ) ;
return V_64 ;
}
static T_11 F_427 ( struct V_2 * V_2 , void * V_654 , T_9 V_655 )
{
struct V_73 V_74 = { } ;
T_11 V_64 ;
do {
V_64 = F_425 ( V_2 , V_654 , V_655 ) ;
F_428 ( V_2 , V_64 ) ;
if ( V_64 >= 0 )
break;
V_64 = F_36 ( F_103 ( V_2 ) , V_64 , & V_74 ) ;
} while ( V_74 . V_80 );
return V_64 ;
}
static T_11 F_429 ( struct V_2 * V_2 , void * V_654 , T_9 V_655 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
int V_64 ;
if ( ! F_416 ( V_14 ) )
return - V_679 ;
V_64 = F_430 ( V_14 , V_2 ) ;
if ( V_64 < 0 )
return V_64 ;
if ( F_91 ( V_2 ) -> V_191 & V_200 )
F_431 ( V_2 ) ;
V_64 = F_422 ( V_2 , V_654 , V_655 ) ;
if ( V_64 != - V_325 )
return V_64 ;
return F_427 ( V_2 , V_654 , V_655 ) ;
}
static int F_432 ( struct V_2 * V_2 , const void * V_654 , T_9 V_655 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_534 * V_45 [ V_668 ] ;
struct V_680 V_429 = {
. V_268 = F_112 ( V_2 ) ,
. V_670 = V_45 ,
. V_667 = V_655 ,
} ;
struct V_681 V_69 ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_682 ] ,
. V_337 = & V_429 ,
. V_338 = & V_69 ,
} ;
unsigned int V_673 = F_426 ( V_655 , V_659 ) ;
int V_64 , V_477 ;
if ( ! F_416 ( V_14 ) )
return - V_679 ;
if ( V_673 > F_290 ( V_45 ) )
return - V_666 ;
V_477 = F_417 ( V_654 , V_655 , V_429 . V_670 ) ;
if ( V_477 < 0 )
return V_477 ;
F_159 ( V_2 ) ;
V_64 = F_89 ( V_14 -> V_111 , V_14 , & V_179 , & V_429 . V_167 , & V_69 . V_168 , 1 ) ;
for (; V_477 > 0 ; V_477 -- )
F_433 ( V_45 [ V_477 - 1 ] ) ;
F_46 ( & V_2 -> V_190 ) ;
F_91 ( V_2 ) -> V_191 |= V_192 ;
F_48 ( & V_2 -> V_190 ) ;
F_434 ( V_2 ) ;
F_431 ( V_2 ) ;
return V_64 ;
}
static int F_435 ( struct V_2 * V_2 , const void * V_654 , T_9 V_655 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_432 ( V_2 , V_654 , V_655 ) ;
F_436 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_2 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_437 ( struct V_2 * V_2 , void * V_654 ,
T_9 V_655 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_441 V_434 ;
struct V_1 V_7 = { 0 , 0 , V_655 , V_654 } ;
T_1 V_265 [ 3 ] = { 0 , 0 , V_407 } ;
struct V_537 V_429 = {
. V_268 = F_112 ( V_2 ) ,
. V_265 = V_265 ,
} ;
struct V_538 V_69 = {
. V_434 = & V_434 ,
. V_7 = & V_7 ,
. V_14 = V_14 ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_539 ] ,
. V_337 = & V_429 ,
. V_338 = & V_69 ,
} ;
int V_64 ;
F_99 ( & V_434 ) ;
V_64 = F_89 ( V_14 -> V_111 , V_14 , & V_179 , & V_429 . V_167 , & V_69 . V_168 , 0 ) ;
if ( V_64 )
return V_64 ;
if ( ! ( V_434 . V_321 & V_683 ) )
return - V_325 ;
if ( V_655 < V_7 . V_12 )
return - V_666 ;
return 0 ;
}
static int F_438 ( struct V_2 * V_2 , void * V_654 ,
T_9 V_655 )
{
struct V_73 V_74 = { } ;
int V_8 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_679 ;
do {
V_8 = F_437 ( V_2 , V_654 , V_655 ) ;
F_439 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_2 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_440 ( struct V_2 * V_2 ,
struct V_1 * V_442 ,
struct V_441 * V_434 ,
struct V_1 * V_418 )
{
struct V_5 V_6 = { 0 } ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
const T_1 V_265 [ 3 ] = { 0 , 0 , V_407 } ;
struct V_428 V_429 = {
. V_268 = F_112 ( V_2 ) ,
. V_435 = & V_6 ,
. V_14 = V_14 ,
. V_265 = V_265 ,
. V_7 = V_442 ,
} ;
struct V_430 V_69 = {
. V_434 = V_434 ,
. V_7 = V_418 ,
. V_14 = V_14 ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_431 ] ,
. V_337 = & V_429 ,
. V_338 = & V_69 ,
} ;
int V_329 ;
F_19 ( & V_429 . V_53 , & V_440 ) ;
V_329 = F_89 ( V_14 -> V_111 , V_14 , & V_179 , & V_429 . V_167 , & V_69 . V_168 , 1 ) ;
if ( V_329 )
F_8 ( L_38 , V_34 , V_329 ) ;
return V_329 ;
}
static int F_441 ( struct V_2 * V_2 ,
struct V_1 * V_442 ,
struct V_441 * V_434 ,
struct V_1 * V_418 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_440 ( V_2 , V_442 ,
V_434 , V_418 ) ;
F_442 ( V_2 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_2 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int
F_443 ( struct V_2 * V_2 , const void * V_654 , T_9 V_655 )
{
struct V_1 V_442 , * V_418 = NULL ;
struct V_441 V_434 ;
struct V_54 * V_55 ;
int V_329 ;
if ( ! F_2 ( V_2 , V_9 ) )
return - V_679 ;
F_99 ( & V_434 ) ;
V_442 . V_684 = 0 ;
V_442 . V_685 = 0 ;
V_442 . V_7 = ( char * ) V_654 ;
V_442 . V_12 = V_655 ;
V_55 = F_444 () ;
if ( F_78 ( V_55 ) )
return F_87 ( V_55 ) ;
V_418 = F_105 ( F_103 ( V_2 ) , V_419 ) ;
if ( F_78 ( V_418 ) ) {
V_329 = - F_87 ( V_418 ) ;
goto V_156;
}
V_329 = F_441 ( V_2 , & V_442 , & V_434 , V_418 ) ;
if ( V_329 == 0 )
F_261 ( V_2 , & V_434 , V_418 ) ;
F_114 ( V_418 ) ;
V_156:
F_235 ( V_55 ) ;
return V_329 ;
}
static void F_445 ( const struct V_58 * V_75 ,
T_12 * V_686 )
{
T_3 V_271 [ 2 ] ;
if ( F_38 ( V_687 , & V_75 -> V_119 ) ) {
V_271 [ 0 ] = F_446 ( V_688 ) ;
V_271 [ 1 ] = F_446 ( V_688 ) ;
} else {
struct V_689 * V_690 = F_447 ( V_75 -> V_691 , V_692 ) ;
T_2 V_693 = F_110 ( V_690 -> V_694 ) ;
V_271 [ 0 ] = F_446 ( V_693 >> 32 ) ;
V_271 [ 1 ] = F_446 ( V_693 ) ;
}
memcpy ( V_686 -> V_165 , V_271 , sizeof( V_686 -> V_165 ) ) ;
}
static int
F_448 ( struct V_58 * V_75 )
{
T_9 V_12 ;
char * V_695 ;
if ( V_75 -> V_696 != NULL )
return 0 ;
F_153 () ;
V_12 = 14 + strlen ( V_75 -> V_697 ) + 1 +
strlen ( F_449 ( V_75 -> V_123 , V_698 ) ) +
1 +
strlen ( F_449 ( V_75 -> V_123 , V_699 ) ) +
1 ;
F_156 () ;
if ( V_12 > V_700 + 1 )
return - V_27 ;
V_695 = F_304 ( V_12 , V_419 ) ;
if ( ! V_695 )
return - V_174 ;
F_153 () ;
F_450 ( V_695 , V_12 , L_39 ,
V_75 -> V_697 ,
F_449 ( V_75 -> V_123 , V_698 ) ,
F_449 ( V_75 -> V_123 , V_699 ) ) ;
F_156 () ;
V_75 -> V_696 = V_695 ;
return 0 ;
}
static int
F_451 ( struct V_58 * V_75 )
{
T_9 V_12 ;
char * V_695 ;
V_12 = 10 + 10 + 1 + 10 + 1 +
strlen ( V_701 ) + 1 +
strlen ( V_75 -> V_123 -> V_702 ) + 1 ;
if ( V_12 > V_700 + 1 )
return - V_27 ;
V_695 = F_304 ( V_12 , V_419 ) ;
if ( ! V_695 )
return - V_174 ;
F_450 ( V_695 , V_12 , L_40 ,
V_75 -> V_703 -> V_704 , V_75 -> V_473 ,
V_701 ,
V_75 -> V_123 -> V_702 ) ;
V_75 -> V_696 = V_695 ;
return 0 ;
}
static int
F_452 ( struct V_58 * V_75 )
{
T_9 V_12 ;
char * V_695 ;
if ( V_75 -> V_696 != NULL )
return 0 ;
if ( V_701 [ 0 ] != '\0' )
return F_451 ( V_75 ) ;
V_12 = 10 + 10 + 1 + 10 + 1 +
strlen ( V_75 -> V_123 -> V_702 ) + 1 ;
if ( V_12 > V_700 + 1 )
return - V_27 ;
V_695 = F_304 ( V_12 , V_419 ) ;
if ( ! V_695 )
return - V_174 ;
F_450 ( V_695 , V_12 , L_41 ,
V_75 -> V_703 -> V_704 , V_75 -> V_473 ,
V_75 -> V_123 -> V_702 ) ;
V_75 -> V_696 = V_695 ;
return 0 ;
}
static unsigned int
F_453 ( const struct V_58 * V_75 , char * V_654 , T_9 V_12 )
{
if ( strchr ( V_75 -> V_697 , ':' ) != NULL )
return F_450 ( V_654 , V_12 , L_42 ) ;
else
return F_450 ( V_654 , V_12 , L_43 ) ;
}
static void F_454 ( struct V_115 * V_116 , void * V_163 )
{
struct V_705 * V_706 = V_163 ;
if ( V_116 -> V_120 == 0 )
V_706 -> V_707 = F_233 ( V_116 -> V_708 -> V_709 ) ;
}
int F_455 ( struct V_58 * V_75 , T_1 V_710 ,
unsigned short V_711 , struct V_54 * V_55 ,
struct V_712 * V_69 )
{
T_12 V_713 ;
struct V_705 V_714 = {
. V_713 = & V_713 ,
. V_715 = V_710 ,
. V_716 = V_75 ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_717 ] ,
. V_337 = & V_714 ,
. V_338 = V_69 ,
. V_54 = V_55 ,
} ;
struct V_115 * V_116 ;
struct V_180 V_339 = {
. V_182 = V_75 -> V_123 ,
. V_178 = & V_179 ,
. V_183 = & V_718 ,
. V_185 = & V_714 ,
. V_236 = V_652 ,
} ;
int V_329 ;
F_445 ( V_75 , & V_713 ) ;
if ( F_38 ( V_719 , & V_75 -> V_720 ) )
V_329 = F_452 ( V_75 ) ;
else
V_329 = F_448 ( V_75 ) ;
if ( V_329 )
goto V_156;
V_714 . V_721 =
F_453 ( V_75 ,
V_714 . V_722 ,
sizeof( V_714 . V_722 ) ) ;
V_714 . V_723 = F_450 ( V_714 . V_724 ,
sizeof( V_714 . V_724 ) , L_44 ,
V_75 -> V_697 , V_711 >> 8 , V_711 & 255 ) ;
F_8 ( L_45 ,
V_75 -> V_123 -> V_124 -> V_725 -> V_726 ,
V_75 -> V_696 ) ;
V_116 = F_86 ( & V_339 ) ;
if ( F_78 ( V_116 ) ) {
V_329 = F_87 ( V_116 ) ;
goto V_156;
}
V_329 = V_116 -> V_120 ;
if ( V_714 . V_707 ) {
V_75 -> V_727 = F_456 ( V_714 . V_707 ) ;
F_235 ( V_714 . V_707 ) ;
}
F_88 ( V_116 ) ;
V_156:
F_457 ( V_75 , V_329 ) ;
F_8 ( L_46 , V_329 ) ;
return V_329 ;
}
int F_458 ( struct V_58 * V_75 ,
struct V_712 * V_429 ,
struct V_54 * V_55 )
{
struct V_178 V_179 = {
. V_334 = & V_335 [ V_728 ] ,
. V_337 = V_429 ,
. V_54 = V_55 ,
} ;
int V_329 ;
F_8 ( L_47 ,
V_75 -> V_123 -> V_124 -> V_725 -> V_726 ,
V_75 -> V_259 ) ;
V_329 = F_415 ( V_75 -> V_123 , & V_179 , V_652 ) ;
F_459 ( V_75 , V_329 ) ;
F_8 ( L_48 , V_329 ) ;
return V_329 ;
}
static void F_460 ( struct V_115 * V_116 , void * V_163 )
{
struct V_729 * V_165 = V_163 ;
if ( ! F_71 ( V_116 , & V_165 -> V_69 . V_168 ) )
return;
F_461 ( & V_165 -> args , & V_165 -> V_69 , V_116 -> V_120 ) ;
if ( V_165 -> args . V_450 && V_116 -> V_120 != 0 ) {
switch( V_165 -> V_69 . V_448 ) {
default:
V_165 -> V_69 . V_448 = - V_451 ;
break;
case 0 :
V_165 -> args . V_450 = NULL ;
V_165 -> V_69 . V_452 = NULL ;
break;
case - V_82 :
case - V_81 :
case - V_83 :
case - V_84 :
case - V_106 :
case - V_453 :
case - V_23 :
V_165 -> args . V_450 = NULL ;
V_165 -> V_69 . V_452 = NULL ;
V_165 -> V_69 . V_448 = 0 ;
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
V_116 -> V_348 . V_54 ) ;
case - V_84 :
case - V_106 :
case - V_88 :
V_116 -> V_120 = 0 ;
break;
case - V_454 :
if ( V_165 -> args . V_265 ) {
V_165 -> args . V_265 = NULL ;
V_165 -> V_69 . V_434 = NULL ;
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
static void F_462 ( void * V_163 )
{
struct V_729 * V_165 = V_163 ;
struct V_2 * V_2 = V_165 -> V_2 ;
if ( V_2 ) {
if ( V_165 -> V_446 . V_447 )
F_278 ( & V_165 -> V_446 . V_429 , & V_165 -> V_446 . V_69 ,
V_165 -> V_69 . V_448 ) ;
F_463 ( V_2 , & V_165 -> V_434 ) ;
F_464 ( V_2 ) ;
}
F_115 ( V_163 ) ;
}
static void F_465 ( struct V_115 * V_116 , void * V_165 )
{
struct V_729 * V_730 ;
V_730 = (struct V_729 * ) V_165 ;
if ( ! V_730 -> V_446 . V_447 && F_274 ( V_730 -> V_2 , V_116 ) )
return;
F_73 ( V_730 -> V_69 . V_14 -> V_58 ,
& V_730 -> args . V_167 ,
& V_730 -> V_69 . V_168 ,
V_116 ) ;
}
static int F_466 ( struct V_2 * V_2 , struct V_54 * V_55 , const T_4 * V_53 , int V_731 )
{
struct V_729 * V_165 ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_115 * V_116 ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_732 ] ,
. V_54 = V_55 ,
} ;
struct V_180 V_339 = {
. V_182 = V_14 -> V_111 ,
. V_178 = & V_179 ,
. V_183 = & V_733 ,
. V_236 = V_343 ,
} ;
int V_329 = 0 ;
V_165 = F_104 ( sizeof( * V_165 ) , V_326 ) ;
if ( V_165 == NULL )
return - V_174 ;
F_51 ( & V_165 -> args . V_167 , & V_165 -> V_69 . V_168 , 1 ) ;
F_283 ( V_14 -> V_58 ,
V_465 ,
& V_339 . V_182 , & V_179 ) ;
V_165 -> args . V_471 = & V_165 -> V_268 ;
V_165 -> args . V_53 = & V_165 -> V_53 ;
V_165 -> args . V_265 = V_14 -> V_462 ;
F_467 ( & V_165 -> V_268 , F_112 ( V_2 ) ) ;
F_19 ( & V_165 -> V_53 , V_53 ) ;
V_165 -> V_69 . V_434 = & V_165 -> V_434 ;
V_165 -> V_69 . V_14 = V_14 ;
V_165 -> V_69 . V_448 = - V_451 ;
V_165 -> V_446 . V_429 . V_467 = & V_165 -> V_446 . V_467 ;
F_99 ( V_165 -> V_69 . V_434 ) ;
V_165 -> V_128 = V_175 ;
V_165 -> V_318 = 0 ;
V_165 -> V_446 . V_447 = F_284 ( V_2 , & V_165 -> V_446 . V_429 , & V_165 -> V_446 . V_69 , V_55 ) ;
V_165 -> V_2 = F_468 ( V_2 ) ;
if ( V_165 -> V_2 ) {
if ( V_165 -> V_446 . V_447 ) {
V_165 -> args . V_450 = & V_165 -> V_446 . V_429 ;
V_165 -> V_69 . V_452 = & V_165 -> V_446 . V_69 ;
}
} else if ( V_165 -> V_446 . V_447 ) {
F_278 ( & V_165 -> V_446 . V_429 , & V_165 -> V_446 . V_69 , 0 ) ;
V_165 -> V_446 . V_447 = false ;
}
V_339 . V_185 = V_165 ;
V_179 . V_337 = & V_165 -> args ;
V_179 . V_338 = & V_165 -> V_69 ;
V_116 = F_86 ( & V_339 ) ;
if ( F_78 ( V_116 ) )
return F_87 ( V_116 ) ;
if ( ! V_731 )
goto V_156;
V_329 = F_203 ( V_116 ) ;
if ( V_329 != 0 )
goto V_156;
V_329 = V_165 -> V_318 ;
V_156:
F_88 ( V_116 ) ;
return V_329 ;
}
int F_469 ( struct V_2 * V_2 , struct V_54 * V_55 , const T_4 * V_53 , int V_731 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_466 ( V_2 , V_55 , V_53 , V_731 ) ;
F_470 ( V_2 , V_53 , V_8 ) ;
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
static int F_471 ( struct V_76 * V_77 , int V_734 , struct V_735 * V_736 )
{
struct V_2 * V_2 = V_77 -> V_2 ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_58 * V_75 = V_14 -> V_58 ;
struct V_737 V_429 = {
. V_268 = F_112 ( V_2 ) ,
. V_738 = V_736 ,
} ;
struct V_739 V_69 = {
. V_740 = V_736 ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_741 ] ,
. V_337 = & V_429 ,
. V_338 = & V_69 ,
. V_54 = V_77 -> V_248 -> V_306 ,
} ;
struct V_307 * V_308 ;
int V_329 ;
V_429 . V_742 . V_258 = V_75 -> V_259 ;
V_329 = F_472 ( V_77 , V_736 ) ;
if ( V_329 != 0 )
goto V_156;
V_308 = V_736 -> V_743 . V_744 . V_248 ;
V_429 . V_742 . V_260 = V_308 -> V_745 . V_263 ;
V_429 . V_742 . V_746 = V_14 -> V_746 ;
V_329 = F_89 ( V_14 -> V_111 , V_14 , & V_179 , & V_429 . V_167 , & V_69 . V_168 , 1 ) ;
switch ( V_329 ) {
case 0 :
V_736 -> V_747 = V_748 ;
break;
case - V_331 :
V_329 = 0 ;
}
V_736 -> V_749 -> V_750 ( V_736 ) ;
V_736 -> V_749 = NULL ;
V_156:
return V_329 ;
}
static int F_473 ( struct V_76 * V_77 , int V_734 , struct V_735 * V_736 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_471 ( V_77 , V_734 , V_736 ) ;
F_474 ( V_736 , V_77 , V_734 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_77 -> V_2 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static struct V_751 * F_475 ( struct V_735 * V_738 ,
struct V_323 * V_324 ,
struct V_307 * V_308 ,
struct V_239 * V_226 )
{
struct V_751 * V_44 ;
struct V_2 * V_2 = V_308 -> V_309 -> V_2 ;
V_44 = F_104 ( sizeof( * V_44 ) , V_326 ) ;
if ( V_44 == NULL )
return NULL ;
V_44 -> V_429 . V_268 = F_112 ( V_2 ) ;
V_44 -> V_429 . V_738 = & V_44 -> V_738 ;
V_44 -> V_429 . V_226 = V_226 ;
V_44 -> V_69 . V_226 = V_226 ;
V_44 -> V_308 = V_308 ;
F_108 ( & V_308 -> V_394 ) ;
V_44 -> V_324 = F_181 ( V_324 ) ;
V_44 -> V_438 = F_269 ( V_324 ) ;
memcpy ( & V_44 -> V_738 , V_738 , sizeof( V_44 -> V_738 ) ) ;
V_44 -> V_14 = F_103 ( V_2 ) ;
return V_44 ;
}
static void F_476 ( void * V_165 )
{
struct V_751 * V_163 = V_165 ;
F_119 ( V_163 -> V_429 . V_226 ) ;
F_237 ( V_163 -> V_308 ) ;
F_271 ( V_163 -> V_438 ) ;
F_193 ( V_163 -> V_324 ) ;
F_115 ( V_163 ) ;
}
static void F_477 ( struct V_115 * V_116 , void * V_165 )
{
struct V_751 * V_163 = V_165 ;
if ( ! F_71 ( V_116 , & V_163 -> V_69 . V_168 ) )
return;
switch ( V_116 -> V_120 ) {
case 0 :
F_49 ( V_163 -> V_14 , V_163 -> V_128 ) ;
F_478 ( V_163 -> V_308 -> V_309 -> V_2 , & V_163 -> V_738 ) ;
if ( F_157 ( V_163 -> V_308 ,
& V_163 -> V_69 . V_53 ) )
break;
case - V_82 :
case - V_83 :
F_18 ( V_163 -> V_14 ,
& V_163 -> V_429 . V_53 ,
V_116 -> V_348 . V_54 ) ;
case - V_84 :
case - V_106 :
case - V_88 :
if ( ! F_155 ( & V_163 -> V_429 . V_53 ,
& V_163 -> V_308 -> V_311 ) )
F_66 ( V_116 ) ;
break;
default:
if ( F_43 ( V_116 , V_163 -> V_14 ,
NULL , NULL ) == - V_121 )
F_66 ( V_116 ) ;
}
F_161 ( V_163 -> V_429 . V_226 ) ;
}
static void F_479 ( struct V_115 * V_116 , void * V_165 )
{
struct V_751 * V_163 = V_165 ;
if ( F_38 ( V_752 , & V_163 -> V_438 -> V_753 -> V_236 ) &&
F_480 ( V_116 , V_163 -> V_438 ) )
return;
if ( F_206 ( V_163 -> V_429 . V_226 , V_116 ) != 0 )
goto V_344;
F_19 ( & V_163 -> V_429 . V_53 , & V_163 -> V_308 -> V_311 ) ;
if ( F_38 ( V_392 , & V_163 -> V_308 -> V_393 ) == 0 ) {
goto V_345;
}
V_163 -> V_128 = V_175 ;
if ( F_73 ( V_163 -> V_14 -> V_58 ,
& V_163 -> V_429 . V_167 ,
& V_163 -> V_69 . V_168 ,
V_116 ) != 0 )
F_161 ( V_163 -> V_429 . V_226 ) ;
return;
V_345:
V_116 -> V_356 = NULL ;
V_344:
F_71 ( V_116 , & V_163 -> V_69 . V_168 ) ;
}
static struct V_115 * F_481 ( struct V_735 * V_738 ,
struct V_323 * V_324 ,
struct V_307 * V_308 ,
struct V_239 * V_226 )
{
struct V_751 * V_165 ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_754 ] ,
. V_54 = V_324 -> V_55 ,
} ;
struct V_180 V_339 = {
. V_182 = F_322 ( V_308 -> V_309 -> V_2 ) ,
. V_178 = & V_179 ,
. V_183 = & V_755 ,
. V_341 = V_342 ,
. V_236 = V_343 ,
} ;
F_283 ( F_103 ( V_308 -> V_309 -> V_2 ) -> V_58 ,
V_465 , & V_339 . V_182 , & V_179 ) ;
V_738 -> V_747 = V_748 ;
if ( V_738 -> V_756 & V_757 )
F_142 ( V_752 , & V_324 -> V_236 ) ;
V_165 = F_475 ( V_738 , V_324 , V_308 , V_226 ) ;
if ( V_165 == NULL ) {
F_119 ( V_226 ) ;
return F_79 ( - V_174 ) ;
}
F_51 ( & V_165 -> V_429 . V_167 , & V_165 -> V_69 . V_168 , 1 ) ;
V_179 . V_337 = & V_165 -> V_429 ;
V_179 . V_338 = & V_165 -> V_69 ;
V_339 . V_185 = V_165 ;
return F_86 ( & V_339 ) ;
}
static int F_482 ( struct V_76 * V_77 , int V_734 , struct V_735 * V_736 )
{
struct V_2 * V_2 = V_77 -> V_2 ;
struct V_234 * V_235 = V_77 -> V_248 ;
struct V_188 * V_189 = F_91 ( V_2 ) ;
struct V_239 * V_226 ;
struct V_307 * V_308 ;
struct V_115 * V_116 ;
struct V_239 * ( * V_240 ) ( struct V_241 * , T_7 ) ;
int V_329 = 0 ;
unsigned char V_756 = V_736 -> V_756 ;
V_329 = F_472 ( V_77 , V_736 ) ;
V_736 -> V_756 |= V_758 ;
F_483 ( & V_235 -> V_759 ) ;
F_484 ( & V_189 -> V_760 ) ;
if ( F_478 ( V_2 , V_736 ) == - V_325 ) {
F_485 ( & V_189 -> V_760 ) ;
F_486 ( & V_235 -> V_759 ) ;
goto V_156;
}
F_485 ( & V_189 -> V_760 ) ;
F_486 ( & V_235 -> V_759 ) ;
if ( V_329 != 0 )
goto V_156;
V_308 = V_736 -> V_743 . V_744 . V_248 ;
if ( F_38 ( V_392 , & V_308 -> V_393 ) == 0 )
goto V_156;
V_240 = F_103 ( V_2 ) -> V_58 -> V_59 -> V_240 ;
V_226 = V_240 ( & V_308 -> V_745 , V_419 ) ;
V_329 = - V_174 ;
if ( F_78 ( V_226 ) )
goto V_156;
V_116 = F_481 ( V_736 , F_314 ( V_736 -> V_761 ) , V_308 , V_226 ) ;
V_329 = F_87 ( V_116 ) ;
if ( F_78 ( V_116 ) )
goto V_156;
V_329 = F_203 ( V_116 ) ;
F_88 ( V_116 ) ;
V_156:
V_736 -> V_756 = V_756 ;
F_487 ( V_736 , V_77 , V_762 , V_329 ) ;
return V_329 ;
}
static struct V_763 * F_488 ( struct V_735 * V_738 ,
struct V_323 * V_324 , struct V_307 * V_308 ,
T_7 V_237 )
{
struct V_763 * V_44 ;
struct V_2 * V_2 = V_308 -> V_309 -> V_2 ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_239 * ( * V_240 ) ( struct V_241 * , T_7 ) ;
V_44 = F_104 ( sizeof( * V_44 ) , V_237 ) ;
if ( V_44 == NULL )
return NULL ;
V_44 -> V_429 . V_268 = F_112 ( V_2 ) ;
V_44 -> V_429 . V_738 = & V_44 -> V_738 ;
V_44 -> V_429 . V_764 = F_489 ( & V_308 -> V_309 -> V_248 -> V_245 , V_237 ) ;
if ( F_78 ( V_44 -> V_429 . V_764 ) )
goto V_333;
V_240 = V_14 -> V_58 -> V_59 -> V_240 ;
V_44 -> V_429 . V_765 = V_240 ( & V_308 -> V_745 , V_237 ) ;
if ( F_78 ( V_44 -> V_429 . V_765 ) )
goto V_766;
V_44 -> V_429 . V_742 . V_258 = V_14 -> V_58 -> V_259 ;
V_44 -> V_429 . V_742 . V_260 = V_308 -> V_745 . V_263 ;
V_44 -> V_429 . V_742 . V_746 = V_14 -> V_746 ;
V_44 -> V_69 . V_765 = V_44 -> V_429 . V_765 ;
V_44 -> V_308 = V_308 ;
V_44 -> V_14 = V_14 ;
F_108 ( & V_308 -> V_394 ) ;
V_44 -> V_324 = F_181 ( V_324 ) ;
memcpy ( & V_44 -> V_738 , V_738 , sizeof( V_44 -> V_738 ) ) ;
return V_44 ;
V_766:
F_119 ( V_44 -> V_429 . V_764 ) ;
V_333:
F_115 ( V_44 ) ;
return NULL ;
}
static void F_490 ( struct V_115 * V_116 , void * V_163 )
{
struct V_763 * V_165 = V_163 ;
struct V_76 * V_77 = V_165 -> V_308 -> V_309 ;
F_8 ( L_23 , V_34 ) ;
if ( F_206 ( V_165 -> V_429 . V_765 , V_116 ) != 0 )
goto V_344;
if ( ! F_38 ( V_392 , & V_165 -> V_308 -> V_393 ) ) {
if ( F_206 ( V_165 -> V_429 . V_764 , V_116 ) != 0 ) {
goto V_767;
}
F_19 ( & V_165 -> V_429 . V_295 ,
& V_77 -> V_295 ) ;
V_165 -> V_429 . V_768 = 1 ;
V_165 -> V_69 . V_764 = V_165 -> V_429 . V_764 ;
} else {
V_165 -> V_429 . V_768 = 0 ;
F_19 ( & V_165 -> V_429 . V_769 ,
& V_165 -> V_308 -> V_311 ) ;
}
if ( ! F_268 ( V_77 ) ) {
V_165 -> V_318 = - V_439 ;
V_116 -> V_356 = NULL ;
goto V_770;
}
V_165 -> V_128 = V_175 ;
if ( F_73 ( V_165 -> V_14 -> V_58 ,
& V_165 -> V_429 . V_167 ,
& V_165 -> V_69 . V_168 ,
V_116 ) == 0 )
return;
V_770:
F_161 ( V_165 -> V_429 . V_764 ) ;
V_767:
F_161 ( V_165 -> V_429 . V_765 ) ;
V_344:
F_71 ( V_116 , & V_165 -> V_69 . V_168 ) ;
F_8 ( L_49 , V_34 , V_165 -> V_318 ) ;
}
static void F_491 ( struct V_115 * V_116 , void * V_163 )
{
struct V_763 * V_165 = V_163 ;
struct V_307 * V_308 = V_165 -> V_308 ;
F_8 ( L_23 , V_34 ) ;
if ( ! F_71 ( V_116 , & V_165 -> V_69 . V_168 ) )
return;
V_165 -> V_318 = V_116 -> V_120 ;
switch ( V_116 -> V_120 ) {
case 0 :
F_49 ( F_103 ( F_14 ( V_165 -> V_324 -> V_4 ) ) ,
V_165 -> V_128 ) ;
if ( V_165 -> V_429 . V_771 ) {
V_165 -> V_738 . V_756 &= ~ ( V_772 | V_773 ) ;
if ( F_478 ( V_308 -> V_309 -> V_2 , & V_165 -> V_738 ) < 0 ) {
F_66 ( V_116 ) ;
break;
}
}
if ( V_165 -> V_429 . V_768 != 0 ) {
F_199 ( & V_308 -> V_745 , 0 ) ;
F_19 ( & V_308 -> V_311 , & V_165 -> V_69 . V_53 ) ;
F_142 ( V_392 , & V_308 -> V_393 ) ;
} else if ( ! F_157 ( V_308 , & V_165 -> V_69 . V_53 ) )
F_66 ( V_116 ) ;
break;
case - V_84 :
case - V_106 :
case - V_88 :
case - V_83 :
if ( V_165 -> V_429 . V_768 != 0 ) {
if ( ! F_155 ( & V_165 -> V_429 . V_295 ,
& V_308 -> V_309 -> V_295 ) )
F_66 ( V_116 ) ;
} else if ( ! F_155 ( & V_165 -> V_429 . V_769 ,
& V_308 -> V_311 ) )
F_66 ( V_116 ) ;
}
F_8 ( L_24 , V_34 , V_165 -> V_318 ) ;
}
static void F_492 ( void * V_163 )
{
struct V_763 * V_165 = V_163 ;
F_8 ( L_23 , V_34 ) ;
F_119 ( V_165 -> V_429 . V_764 ) ;
if ( V_165 -> V_332 ) {
struct V_115 * V_116 ;
V_116 = F_481 ( & V_165 -> V_738 , V_165 -> V_324 , V_165 -> V_308 ,
V_165 -> V_429 . V_765 ) ;
if ( ! F_78 ( V_116 ) )
F_493 ( V_116 ) ;
F_8 ( L_50 , V_34 ) ;
} else
F_119 ( V_165 -> V_429 . V_765 ) ;
F_237 ( V_165 -> V_308 ) ;
F_193 ( V_165 -> V_324 ) ;
F_115 ( V_165 ) ;
F_8 ( L_25 , V_34 ) ;
}
static void F_494 ( struct V_13 * V_14 , struct V_307 * V_308 , int V_768 , int error )
{
switch ( error ) {
case - V_82 :
case - V_83 :
case - V_84 :
V_308 -> V_745 . V_236 &= ~ V_774 ;
if ( V_768 != 0 ||
F_38 ( V_392 , & V_308 -> V_393 ) != 0 )
F_28 ( V_14 , V_308 -> V_309 ) ;
break;
case - V_88 :
V_308 -> V_745 . V_236 &= ~ V_774 ;
F_29 ( V_14 -> V_58 ) ;
} ;
}
static int F_495 ( struct V_76 * V_77 , int V_734 , struct V_735 * V_738 , int V_775 )
{
struct V_763 * V_165 ;
struct V_115 * V_116 ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_776 ] ,
. V_54 = V_77 -> V_248 -> V_306 ,
} ;
struct V_180 V_339 = {
. V_182 = F_322 ( V_77 -> V_2 ) ,
. V_178 = & V_179 ,
. V_183 = & V_777 ,
. V_341 = V_342 ,
. V_236 = V_343 ,
} ;
int V_64 ;
F_8 ( L_23 , V_34 ) ;
V_165 = F_488 ( V_738 , F_314 ( V_738 -> V_761 ) ,
V_738 -> V_743 . V_744 . V_248 ,
V_775 == V_778 ? V_419 : V_326 ) ;
if ( V_165 == NULL )
return - V_174 ;
if ( F_496 ( V_734 ) )
V_165 -> V_429 . V_779 = 1 ;
F_51 ( & V_165 -> V_429 . V_167 , & V_165 -> V_69 . V_168 , 1 ) ;
V_179 . V_337 = & V_165 -> V_429 ;
V_179 . V_338 = & V_165 -> V_69 ;
V_339 . V_185 = V_165 ;
if ( V_775 > V_778 ) {
if ( V_775 == V_780 )
V_165 -> V_429 . V_781 = V_780 ;
F_52 ( & V_165 -> V_429 . V_167 ) ;
} else
V_165 -> V_429 . V_771 = 1 ;
V_116 = F_86 ( & V_339 ) ;
if ( F_78 ( V_116 ) )
return F_87 ( V_116 ) ;
V_64 = F_203 ( V_116 ) ;
if ( V_64 == 0 ) {
V_64 = V_165 -> V_318 ;
if ( V_64 )
F_494 ( V_165 -> V_14 , V_165 -> V_308 ,
V_165 -> V_429 . V_768 , V_64 ) ;
} else
V_165 -> V_332 = true ;
F_88 ( V_116 ) ;
F_8 ( L_24 , V_34 , V_64 ) ;
F_497 ( V_738 , V_77 , & V_165 -> V_69 . V_53 , V_734 , V_64 ) ;
return V_64 ;
}
static int F_498 ( struct V_76 * V_77 , struct V_735 * V_736 )
{
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
struct V_73 V_74 = {
. V_2 = V_77 -> V_2 ,
} ;
int V_8 ;
do {
if ( F_38 ( V_296 , & V_77 -> V_236 ) != 0 )
return 0 ;
V_8 = F_495 ( V_77 , V_762 , V_736 , V_780 ) ;
if ( V_8 != - V_102 )
break;
F_36 ( V_14 , V_8 , & V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_499 ( struct V_76 * V_77 , struct V_735 * V_736 )
{
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
struct V_73 V_74 = {
. V_2 = V_77 -> V_2 ,
} ;
int V_8 ;
V_8 = F_472 ( V_77 , V_736 ) ;
if ( V_8 != 0 )
return V_8 ;
if ( ! V_395 ) {
F_142 ( V_396 , & V_736 -> V_743 . V_744 . V_248 -> V_393 ) ;
return 0 ;
}
do {
if ( F_38 ( V_296 , & V_77 -> V_236 ) != 0 )
return 0 ;
V_8 = F_495 ( V_77 , V_762 , V_736 , V_782 ) ;
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
static int F_500 ( struct V_76 * V_77 , struct V_735 * V_736 )
{
struct V_307 * V_308 ;
int V_329 ;
V_329 = F_472 ( V_77 , V_736 ) ;
if ( V_329 != 0 )
return V_329 ;
V_308 = V_736 -> V_743 . V_744 . V_248 ;
if ( F_38 ( V_392 , & V_308 -> V_393 ) ||
F_38 ( V_396 , & V_308 -> V_393 ) )
return 0 ;
return F_499 ( V_77 , V_736 ) ;
}
static int F_501 ( struct V_76 * V_77 , int V_734 , struct V_735 * V_736 )
{
struct V_188 * V_189 = F_91 ( V_77 -> V_2 ) ;
struct V_234 * V_235 = V_77 -> V_248 ;
unsigned char V_756 = V_736 -> V_756 ;
int V_329 ;
V_736 -> V_756 |= V_773 ;
V_329 = F_478 ( V_77 -> V_2 , V_736 ) ;
if ( V_329 < 0 )
goto V_156;
F_483 ( & V_235 -> V_759 ) ;
F_484 ( & V_189 -> V_760 ) ;
if ( F_38 ( V_296 , & V_77 -> V_236 ) ) {
V_736 -> V_756 = V_756 & ~ V_772 ;
V_329 = F_478 ( V_77 -> V_2 , V_736 ) ;
F_485 ( & V_189 -> V_760 ) ;
F_486 ( & V_235 -> V_759 ) ;
goto V_156;
}
F_485 ( & V_189 -> V_760 ) ;
F_486 ( & V_235 -> V_759 ) ;
V_329 = F_495 ( V_77 , V_734 , V_736 , V_778 ) ;
V_156:
V_736 -> V_756 = V_756 ;
return V_329 ;
}
static int F_502 ( struct V_76 * V_77 , int V_734 , struct V_735 * V_736 )
{
struct V_73 V_74 = {
. V_77 = V_77 ,
. V_2 = V_77 -> V_2 ,
} ;
int V_8 ;
do {
V_8 = F_501 ( V_77 , V_734 , V_736 ) ;
if ( V_8 == - V_331 )
V_8 = - V_121 ;
V_8 = F_36 ( F_103 ( V_77 -> V_2 ) ,
V_8 , & V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int
F_503 ( struct V_76 * V_77 , int V_734 ,
struct V_735 * V_736 )
{
int V_329 = - V_71 ;
unsigned long V_63 = V_783 ;
while( ! F_504 () ) {
V_329 = F_502 ( V_77 , V_734 , V_736 ) ;
if ( ( V_329 != - V_121 ) || F_505 ( V_734 ) )
break;
F_506 ( V_63 ) ;
V_63 *= 2 ;
V_63 = F_418 (unsigned long, NFS4_LOCK_MAXTIMEOUT, timeout) ;
V_329 = - V_71 ;
}
return V_329 ;
}
static int
F_507 ( T_13 * V_463 , unsigned int V_281 , int V_236 , void * V_784 )
{
int V_64 ;
struct V_785 * V_786 = V_784 ;
struct V_787 * V_788 = V_463 -> V_789 ;
struct V_790 * V_791 = & V_786 -> V_792 ,
* V_793 = V_788 -> V_248 ;
if ( V_791 -> V_258 != V_793 -> V_258 ||
V_791 -> V_260 != V_793 -> V_260 ||
V_791 -> V_746 != V_793 -> V_746 )
return 0 ;
if ( F_508 ( F_112 ( V_788 -> V_2 ) , & V_786 -> V_794 ) )
return 0 ;
V_788 -> V_795 = true ;
V_463 -> V_789 = V_788 -> V_116 ;
V_64 = F_509 ( V_463 , V_281 , V_236 , V_784 ) ;
V_463 -> V_789 = V_788 ;
return V_64 ;
}
static int
F_510 ( struct V_76 * V_77 , int V_734 , struct V_735 * V_736 )
{
int V_329 = - V_71 ;
unsigned long V_236 ;
struct V_307 * V_308 = V_736 -> V_743 . V_744 . V_248 ;
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
struct V_58 * V_75 = V_14 -> V_58 ;
T_14 * V_796 = & V_75 -> V_797 ;
struct V_790 V_248 = { . V_258 = V_75 -> V_259 ,
. V_260 = V_308 -> V_745 . V_263 ,
. V_746 = V_14 -> V_746 } ;
struct V_787 V_788 = { . V_116 = V_70 ,
. V_2 = V_77 -> V_2 ,
. V_248 = & V_248 ,
. V_795 = false } ;
T_13 V_463 ;
if ( ! F_38 ( V_412 , & V_77 -> V_236 ) )
return F_503 ( V_77 , V_734 , V_736 ) ;
F_511 ( & V_463 ) ;
V_463 . V_789 = & V_788 ;
V_463 . V_798 = F_507 ;
F_512 ( V_796 , & V_463 ) ;
while( ! F_504 () ) {
V_329 = F_502 ( V_77 , V_734 , V_736 ) ;
if ( ( V_329 != - V_121 ) || F_505 ( V_734 ) )
break;
V_329 = - V_71 ;
F_513 ( & V_796 -> V_304 , V_236 ) ;
if ( V_788 . V_795 ) {
F_514 ( & V_796 -> V_304 , V_236 ) ;
continue;
}
F_515 ( V_799 ) ;
F_514 ( & V_796 -> V_304 , V_236 ) ;
F_516 ( V_800 ) ;
}
F_517 ( V_796 , & V_463 ) ;
return V_329 ;
}
static inline int
F_510 ( struct V_76 * V_77 , int V_734 , struct V_735 * V_736 )
{
return F_503 ( V_77 , V_734 , V_736 ) ;
}
static int
F_518 ( struct V_801 * V_802 , int V_734 , struct V_735 * V_736 )
{
struct V_323 * V_324 ;
struct V_76 * V_77 ;
int V_329 ;
V_324 = F_314 ( V_802 ) ;
V_77 = V_324 -> V_77 ;
if ( F_519 ( V_734 ) ) {
if ( V_77 != NULL )
return F_473 ( V_77 , V_803 , V_736 ) ;
return 0 ;
}
if ( ! ( F_505 ( V_734 ) || F_496 ( V_734 ) ) )
return - V_27 ;
if ( V_736 -> V_747 == V_748 ) {
if ( V_77 != NULL )
return F_482 ( V_77 , V_734 , V_736 ) ;
return 0 ;
}
if ( V_77 == NULL )
return - V_804 ;
if ( ( V_736 -> V_756 & V_805 ) &&
! F_38 ( V_410 , & V_77 -> V_236 ) )
return - V_804 ;
V_329 = F_472 ( V_77 , V_736 ) ;
if ( V_329 != 0 )
return V_329 ;
return F_510 ( V_77 , V_734 , V_736 ) ;
}
int F_520 ( struct V_735 * V_738 , struct V_76 * V_77 , const T_4 * V_53 )
{
struct V_13 * V_14 = F_103 ( V_77 -> V_2 ) ;
int V_8 ;
V_8 = F_472 ( V_77 , V_738 ) ;
if ( V_8 != 0 )
return V_8 ;
V_8 = F_495 ( V_77 , V_762 , V_738 , V_778 ) ;
return F_194 ( V_14 , V_77 , V_53 , V_8 ) ;
}
static void F_521 ( struct V_115 * V_116 , void * V_163 )
{
struct V_806 * V_165 = V_163 ;
struct V_13 * V_14 = V_165 -> V_14 ;
F_73 ( V_14 -> V_58 , & V_165 -> args . V_167 ,
& V_165 -> V_69 . V_168 , V_116 ) ;
V_165 -> args . V_742 . V_258 = V_14 -> V_58 -> V_259 ;
V_165 -> V_128 = V_175 ;
}
static void F_522 ( struct V_115 * V_116 , void * V_163 )
{
struct V_806 * V_165 = V_163 ;
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
static void F_523 ( void * V_163 )
{
struct V_806 * V_165 = V_163 ;
F_524 ( V_165 -> V_14 , V_165 -> V_308 ) ;
F_115 ( V_163 ) ;
}
static void
F_525 ( struct V_13 * V_14 , struct V_307 * V_308 )
{
struct V_806 * V_165 ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_807 ] ,
} ;
if ( V_14 -> V_58 -> V_59 -> V_354 != 0 )
return;
V_165 = F_304 ( sizeof( * V_165 ) , V_326 ) ;
if ( ! V_165 )
return;
V_165 -> V_308 = V_308 ;
V_165 -> V_14 = V_14 ;
V_165 -> args . V_742 . V_258 = V_14 -> V_58 -> V_259 ;
V_165 -> args . V_742 . V_260 = V_308 -> V_745 . V_263 ;
V_165 -> args . V_742 . V_746 = V_14 -> V_746 ;
V_179 . V_337 = & V_165 -> args ;
V_179 . V_338 = & V_165 -> V_69 ;
F_51 ( & V_165 -> args . V_167 , & V_165 -> V_69 . V_168 , 0 ) ;
F_413 ( V_14 -> V_111 , & V_179 , 0 , & V_808 , V_165 ) ;
}
static int F_526 ( const struct V_809 * V_810 ,
struct V_4 * V_811 , struct V_2 * V_2 ,
const char * V_784 , const void * V_654 ,
T_9 V_655 , int V_236 )
{
return F_435 ( V_2 , V_654 , V_655 ) ;
}
static int F_527 ( const struct V_809 * V_810 ,
struct V_4 * V_811 , struct V_2 * V_2 ,
const char * V_784 , void * V_654 , T_9 V_655 )
{
return F_429 ( V_2 , V_654 , V_655 ) ;
}
static bool F_528 ( struct V_4 * V_4 )
{
return F_416 ( F_103 ( F_14 ( V_4 ) ) ) ;
}
static int F_529 ( const struct V_809 * V_810 ,
struct V_4 * V_811 , struct V_2 * V_2 ,
const char * V_784 , const void * V_654 ,
T_9 V_655 , int V_236 )
{
if ( F_530 ( V_784 ) )
return F_443 ( V_2 , V_654 , V_655 ) ;
return - V_679 ;
}
static int F_531 ( const struct V_809 * V_810 ,
struct V_4 * V_811 , struct V_2 * V_2 ,
const char * V_784 , void * V_654 , T_9 V_655 )
{
if ( F_530 ( V_784 ) )
return F_438 ( V_2 , V_654 , V_655 ) ;
return - V_679 ;
}
static T_11
F_532 ( struct V_2 * V_2 , char * V_812 , T_9 V_813 )
{
int V_12 = 0 ;
if ( F_2 ( V_2 , V_9 ) ) {
V_12 = F_533 ( V_2 , V_812 , V_813 ) ;
if ( V_813 && V_12 > V_813 )
return - V_666 ;
}
return V_12 ;
}
static T_11
F_532 ( struct V_2 * V_2 , char * V_812 , T_9 V_813 )
{
return 0 ;
}
static void F_306 ( struct V_441 * V_434 )
{
if ( ! ( ( ( V_434 -> V_321 & V_814 ) ||
( V_434 -> V_321 & V_815 ) ) &&
( V_434 -> V_321 & V_531 ) &&
( V_434 -> V_321 & V_816 ) ) )
return;
V_434 -> V_321 |= V_357 | V_547 |
V_548 | V_817 ;
V_434 -> V_281 = V_362 | V_550 | V_551 ;
V_434 -> V_552 = 2 ;
}
static int F_534 ( struct V_67 * V_111 , struct V_2 * V_3 ,
const struct V_533 * V_264 ,
struct V_535 * V_818 ,
struct V_534 * V_534 )
{
struct V_13 * V_14 = F_103 ( V_3 ) ;
T_1 V_265 [ 3 ] = {
[ 0 ] = V_819 | V_820 ,
} ;
struct V_821 args = {
. V_545 = F_112 ( V_3 ) ,
. V_264 = V_264 ,
. V_534 = V_534 ,
. V_265 = V_265 ,
} ;
struct V_822 V_69 = {
. V_818 = V_818 ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_823 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
} ;
int V_329 ;
F_8 ( L_51 , V_34 ) ;
if ( F_103 ( V_3 ) -> V_15 [ 1 ] & V_824 )
V_265 [ 1 ] |= V_824 ;
else
V_265 [ 0 ] |= V_41 ;
F_99 ( & V_818 -> V_434 ) ;
V_818 -> V_14 = V_14 ;
V_818 -> V_825 = 0 ;
V_329 = F_89 ( V_111 , V_14 , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
F_8 ( L_52 , V_34 , V_329 ) ;
return V_329 ;
}
int F_305 ( struct V_67 * V_111 , struct V_2 * V_3 ,
const struct V_533 * V_264 ,
struct V_535 * V_818 ,
struct V_534 * V_534 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_534 ( V_111 , V_3 , V_264 ,
V_818 , V_534 ) ;
F_535 ( V_3 , V_264 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_3 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_536 ( struct V_2 * V_2 ,
struct V_535 * V_536 ,
struct V_534 * V_534 , struct V_54 * V_55 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_67 * V_68 = V_14 -> V_111 ;
T_1 V_265 [ 2 ] = {
[ 0 ] = V_819 | V_820 ,
} ;
struct V_821 args = {
. V_258 = V_14 -> V_58 -> V_259 ,
. V_268 = F_112 ( V_2 ) ,
. V_534 = V_534 ,
. V_265 = V_265 ,
. V_826 = 1 ,
. V_827 = 1 ,
} ;
struct V_822 V_69 = {
. V_818 = V_536 ,
. V_826 = 1 ,
. V_827 = 1 ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_823 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
. V_54 = V_55 ,
} ;
unsigned long V_619 = V_175 ;
int V_329 ;
F_99 ( & V_536 -> V_434 ) ;
V_536 -> V_14 = V_14 ;
V_536 -> V_825 = 0 ;
F_51 ( & args . V_167 , & V_69 . V_168 , 0 ) ;
F_52 ( & args . V_167 ) ;
V_329 = F_85 ( V_68 , V_14 , & V_179 ,
& args . V_167 , & V_69 . V_168 ) ;
if ( V_329 )
return V_329 ;
F_49 ( V_14 , V_619 ) ;
return 0 ;
}
static int F_537 ( struct V_2 * V_2 ,
struct V_535 * V_536 ,
struct V_534 * V_534 , struct V_54 * V_55 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_67 * V_68 = V_14 -> V_111 ;
T_1 V_265 [ 2 ] = {
[ 0 ] = V_819 | V_820 ,
} ;
struct V_821 args = {
. V_268 = F_112 ( V_2 ) ,
. V_534 = V_534 ,
. V_265 = V_265 ,
. V_826 = 1 ,
} ;
struct V_822 V_69 = {
. V_818 = V_536 ,
. V_826 = 1 ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_823 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
. V_54 = V_55 ,
} ;
int V_329 ;
F_99 ( & V_536 -> V_434 ) ;
V_536 -> V_14 = V_14 ;
V_536 -> V_825 = 0 ;
F_51 ( & args . V_167 , & V_69 . V_168 , 0 ) ;
F_52 ( & args . V_167 ) ;
V_329 = F_85 ( V_68 , V_14 , & V_179 ,
& args . V_167 , & V_69 . V_168 ) ;
if ( V_329 == V_828 &&
V_69 . V_168 . V_160 & V_829 )
V_329 = - V_91 ;
return V_329 ;
}
int F_538 ( struct V_2 * V_2 ,
struct V_535 * V_536 ,
struct V_534 * V_534 , struct V_54 * V_55 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_58 * V_75 = V_14 -> V_58 ;
const struct V_830 * V_57 =
V_75 -> V_59 -> V_831 ;
struct V_73 V_74 = { } ;
int V_329 ;
F_8 ( L_53 , V_34 ,
( unsigned long long ) V_14 -> V_532 . V_832 ,
( unsigned long long ) V_14 -> V_532 . V_833 ,
V_75 -> V_110 ) ;
F_539 ( F_112 ( V_2 ) , V_34 ) ;
do {
V_329 = V_57 -> V_834 ( V_2 , V_536 , V_534 , V_55 ) ;
if ( V_329 != - V_102 )
break;
F_36 ( V_14 , V_329 , & V_74 ) ;
} while ( V_74 . V_80 );
return V_329 ;
}
static int F_540 ( struct V_2 * V_2 , struct V_54 * V_55 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_58 * V_75 = F_103 ( V_2 ) -> V_58 ;
struct V_67 * V_68 = V_14 -> V_111 ;
struct V_835 args = {
. V_268 = F_112 ( V_2 ) ,
. V_258 = V_75 -> V_259 ,
. V_827 = 1 ,
} ;
struct V_836 V_69 = {
. V_827 = 1 ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_837 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
. V_54 = V_55 ,
} ;
unsigned long V_619 = V_175 ;
int V_329 ;
V_69 . V_268 = F_541 () ;
if ( V_69 . V_268 == NULL )
return - V_174 ;
F_51 ( & args . V_167 , & V_69 . V_168 , 0 ) ;
F_52 ( & args . V_167 ) ;
V_329 = F_85 ( V_68 , V_14 , & V_179 ,
& args . V_167 , & V_69 . V_168 ) ;
F_542 ( V_69 . V_268 ) ;
if ( V_329 )
return V_329 ;
F_45 ( V_75 , V_619 ) ;
return 0 ;
}
static int F_543 ( struct V_2 * V_2 , struct V_54 * V_55 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_67 * V_68 = V_14 -> V_111 ;
struct V_835 args = {
. V_268 = F_112 ( V_2 ) ,
} ;
struct V_836 V_69 = {
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_837 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
. V_54 = V_55 ,
} ;
int V_329 ;
V_69 . V_268 = F_541 () ;
if ( V_69 . V_268 == NULL )
return - V_174 ;
F_51 ( & args . V_167 , & V_69 . V_168 , 0 ) ;
F_52 ( & args . V_167 ) ;
V_329 = F_85 ( V_68 , V_14 , & V_179 ,
& args . V_167 , & V_69 . V_168 ) ;
F_542 ( V_69 . V_268 ) ;
if ( V_329 == V_828 &&
V_69 . V_168 . V_160 & V_829 )
V_329 = - V_91 ;
return V_329 ;
}
int F_544 ( struct V_2 * V_2 , struct V_54 * V_55 )
{
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_58 * V_75 = V_14 -> V_58 ;
const struct V_830 * V_57 =
V_75 -> V_59 -> V_831 ;
struct V_73 V_74 = { } ;
int V_329 ;
F_8 ( L_53 , V_34 ,
( unsigned long long ) V_14 -> V_532 . V_832 ,
( unsigned long long ) V_14 -> V_532 . V_833 ,
V_75 -> V_110 ) ;
F_539 ( F_112 ( V_2 ) , V_34 ) ;
do {
V_329 = V_57 -> V_838 ( V_2 , V_55 ) ;
if ( V_329 != - V_102 )
break;
F_36 ( V_14 , V_329 , & V_74 ) ;
} while ( V_74 . V_80 );
return V_329 ;
}
static int F_545 ( struct V_2 * V_3 , const struct V_533 * V_264 , struct V_839 * V_527 , bool V_840 )
{
int V_329 ;
struct V_841 args = {
. V_545 = F_112 ( V_3 ) ,
. V_264 = V_264 ,
} ;
struct V_842 V_69 = {
. V_527 = V_527 ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_843 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
} ;
struct V_67 * V_68 = F_103 ( V_3 ) -> V_111 ;
struct V_54 * V_55 = NULL ;
if ( V_840 ) {
V_68 = F_103 ( V_3 ) -> V_58 -> V_123 ;
V_55 = F_546 ( F_103 ( V_3 ) -> V_58 ) ;
V_179 . V_54 = V_55 ;
}
F_8 ( L_54 , V_264 -> V_264 ) ;
F_283 ( F_103 ( V_3 ) -> V_58 ,
V_844 , & V_68 , & V_179 ) ;
V_329 = F_89 ( V_68 , F_103 ( V_3 ) , & V_179 , & args . V_167 ,
& V_69 . V_168 , 0 ) ;
F_8 ( L_55 , V_329 ) ;
if ( V_55 )
F_235 ( V_55 ) ;
return V_329 ;
}
int F_547 ( struct V_2 * V_3 , const struct V_533 * V_264 ,
struct V_839 * V_527 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_44 ( F_103 ( V_3 ) -> V_58 ) )
V_8 = F_545 ( V_3 , V_264 , V_527 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_545 ( V_3 , V_264 , V_527 , false ) ;
F_548 ( V_3 , V_264 , V_8 ) ;
V_8 = F_36 ( F_103 ( V_3 ) , V_8 ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static int F_549 ( T_1 V_236 )
{
if ( V_236 & ~ V_845 )
goto V_846;
if ( ( V_236 & V_847 ) &&
( V_236 & V_848 ) )
goto V_846;
if ( ! ( V_236 & ( V_849 ) ) )
goto V_846;
return V_389 ;
V_846:
return - V_850 ;
}
static bool
F_550 ( struct V_851 * V_852 ,
struct V_851 * V_853 )
{
if ( V_852 -> V_854 != V_853 -> V_854 )
return false ;
return memcmp ( V_852 -> V_855 , V_853 -> V_855 , V_852 -> V_854 ) == 0 ;
}
static void
F_551 ( struct V_115 * V_116 , void * V_163 )
{
}
static
int F_552 ( struct V_67 * V_68 ,
struct V_856 * V_857 ,
struct V_58 * V_75 ,
struct V_54 * V_55 )
{
int V_329 ;
struct V_858 args = {
. V_111 = V_75 ,
. V_3 = V_859 ,
} ;
struct V_860 V_69 ;
struct V_178 V_179 = {
. V_334 =
& V_335 [ V_861 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
. V_54 = V_55 ,
} ;
struct V_180 V_339 = {
. V_182 = V_68 ,
. V_856 = V_857 ,
. V_183 = & V_862 ,
. V_178 = & V_179 ,
. V_236 = V_652 ,
} ;
struct V_115 * V_116 ;
F_553 ( & args . V_863 , & V_75 -> V_100 -> V_864 ) ;
if ( ! ( V_75 -> V_100 -> V_236 & V_865 ) )
args . V_3 = V_866 ;
if ( V_857 != F_226 ( V_68 -> V_867 ) )
args . V_3 = V_866 ;
V_116 = F_86 ( & V_339 ) ;
if ( ! F_78 ( V_116 ) ) {
V_329 = V_116 -> V_120 ;
F_88 ( V_116 ) ;
} else
V_329 = F_87 ( V_116 ) ;
F_554 ( V_75 , V_329 ) ;
if ( V_329 == 0 ) {
if ( memcmp ( V_69 . V_863 . V_165 ,
V_75 -> V_100 -> V_864 . V_165 , V_868 ) ) {
F_8 ( L_56 , V_34 ) ;
return - V_35 ;
}
if ( ( V_69 . V_3 & args . V_3 ) != V_69 . V_3 || V_69 . V_3 == 0 ) {
F_8 ( L_57 ,
V_34 ) ;
return - V_35 ;
}
if ( V_69 . V_869 != args . V_869 ) {
F_8 ( L_58 ,
V_34 ) ;
return - V_35 ;
}
}
return V_329 ;
}
static int
F_555 ( struct V_67 * V_68 ,
struct V_856 * V_857 ,
void * V_163 )
{
struct V_870 * V_44 = V_163 ;
return F_552 ( V_68 , V_857 , V_44 -> V_75 , V_44 -> V_55 ) ;
}
int F_556 ( struct V_58 * V_75 , struct V_54 * V_55 )
{
struct V_870 V_165 = {
. V_75 = V_75 ,
. V_55 = V_55 ,
} ;
return F_557 ( V_75 -> V_123 ,
F_555 , & V_165 ) ;
}
static int F_558 ( struct V_58 * V_75 ,
struct V_871 * V_235 )
{
static const T_1 V_872 [ V_873 ] = {
[ 1 ] = 1 << ( V_874 - 32 ) |
1 << ( V_875 - 32 ) |
1 << ( V_876 - 32 ) |
1 << ( V_877 - 32 ) |
1 << ( V_878 - 32 )
} ;
unsigned long V_236 = 0 ;
unsigned int V_477 ;
int V_64 = 0 ;
if ( V_235 -> V_879 == V_880 ) {
F_559 ( V_881 , L_59 ) ;
for ( V_477 = 0 ; V_477 <= V_882 ; V_477 ++ ) {
if ( F_38 ( V_477 , V_235 -> V_883 . V_272 . V_884 ) )
F_559 ( V_881 , L_60 , V_477 ) ;
if ( F_38 ( V_477 , V_235 -> V_885 . V_272 . V_884 ) )
F_559 ( V_881 , L_61 , V_477 ) ;
}
for ( V_477 = 0 ; V_477 < V_873 ; V_477 ++ ) {
if ( V_235 -> V_883 . V_272 . V_886 [ V_477 ] & ~ V_872 [ V_477 ] ) {
F_559 ( V_881 , L_62 ) ;
V_64 = - V_27 ;
goto V_156;
}
}
if ( F_38 ( V_874 , V_235 -> V_883 . V_272 . V_884 ) &&
F_38 ( V_876 , V_235 -> V_883 . V_272 . V_884 ) &&
F_38 ( V_877 , V_235 -> V_883 . V_272 . V_884 ) &&
F_38 ( V_878 , V_235 -> V_883 . V_272 . V_884 ) ) {
F_559 ( V_881 , L_63 ) ;
F_559 ( V_881 , L_64 ) ;
F_560 ( V_887 , & V_236 ) ;
} else {
F_559 ( V_881 , L_62 ) ;
V_64 = - V_27 ;
goto V_156;
}
if ( F_38 ( V_888 , V_235 -> V_885 . V_272 . V_884 ) &&
F_38 ( V_889 , V_235 -> V_885 . V_272 . V_884 ) &&
F_38 ( V_890 , V_235 -> V_885 . V_272 . V_884 ) &&
F_38 ( V_891 , V_235 -> V_885 . V_272 . V_884 ) ) {
F_559 ( V_881 , L_65 ) ;
F_560 ( V_465 , & V_236 ) ;
}
if ( F_38 ( V_892 , V_235 -> V_885 . V_272 . V_884 ) ) {
F_559 ( V_881 , L_66 ) ;
F_560 ( V_893 , & V_236 ) ;
}
if ( F_38 ( V_894 , V_235 -> V_885 . V_272 . V_884 ) &&
F_38 ( V_895 , V_235 -> V_885 . V_272 . V_884 ) ) {
F_559 ( V_881 , L_67 ) ;
F_560 ( V_844 , & V_236 ) ;
}
if ( F_38 ( V_896 , V_235 -> V_885 . V_272 . V_884 ) &&
F_38 ( V_897 , V_235 -> V_885 . V_272 . V_884 ) ) {
F_559 ( V_881 , L_68 ) ;
F_560 ( V_898 , & V_236 ) ;
}
if ( F_38 ( V_899 , V_235 -> V_885 . V_272 . V_884 ) ) {
F_559 ( V_881 , L_69 ) ;
F_560 ( V_900 , & V_236 ) ;
}
if ( F_38 ( V_901 , V_235 -> V_885 . V_272 . V_884 ) ) {
F_559 ( V_881 , L_70 ) ;
F_560 ( V_902 , & V_236 ) ;
}
}
V_156:
V_75 -> V_903 = V_236 ;
return 0 ;
}
static void F_561 ( void * V_165 )
{
struct V_904 * V_905 =
(struct V_904 * ) V_165 ;
F_407 ( V_905 -> args . V_111 ) ;
F_115 ( V_905 -> V_69 . V_906 ) ;
F_115 ( V_905 -> V_69 . V_855 ) ;
F_115 ( V_905 -> V_69 . V_907 ) ;
F_115 ( V_905 ) ;
}
static struct V_115 *
F_562 ( struct V_58 * V_75 , struct V_54 * V_55 ,
T_1 V_908 , struct V_856 * V_857 )
{
struct V_178 V_179 = {
. V_334 = & V_335 [ V_909 ] ,
. V_54 = V_55 ,
} ;
struct V_180 V_339 = {
. V_182 = V_75 -> V_123 ,
. V_183 = & V_910 ,
. V_178 = & V_179 ,
. V_236 = V_652 ,
} ;
struct V_904 * V_163 ;
int V_329 ;
if ( ! F_412 ( & V_75 -> V_646 ) )
return F_79 ( - V_35 ) ;
V_329 = - V_174 ;
V_163 = F_104 ( sizeof( * V_163 ) , V_326 ) ;
if ( ! V_163 )
goto V_156;
F_445 ( V_75 , & V_163 -> args . V_37 ) ;
V_329 = F_452 ( V_75 ) ;
if ( V_329 )
goto V_911;
V_163 -> V_69 . V_907 = F_104 ( sizeof( struct V_912 ) ,
V_326 ) ;
V_329 = - V_174 ;
if ( F_391 ( V_163 -> V_69 . V_907 == NULL ) )
goto V_911;
V_163 -> V_69 . V_855 = F_104 ( sizeof( struct V_851 ) ,
V_326 ) ;
if ( F_391 ( V_163 -> V_69 . V_855 == NULL ) )
goto V_913;
V_163 -> V_69 . V_906 = F_104 ( sizeof( struct V_914 ) , V_326 ) ;
if ( F_391 ( V_163 -> V_69 . V_906 == NULL ) )
goto V_915;
switch ( V_908 ) {
case V_916 :
V_163 -> args . V_917 . V_879 = V_916 ;
break;
case V_880 :
V_163 -> args . V_917 = V_918 ;
break;
default:
F_127 ( 1 ) ;
V_329 = - V_27 ;
goto V_919;
}
if ( V_857 ) {
V_339 . V_856 = V_857 ;
V_339 . V_236 |= V_920 ;
memcpy ( V_163 -> args . V_37 . V_165 , V_75 -> V_921 . V_165 ,
sizeof( V_163 -> args . V_37 . V_165 ) ) ;
}
V_163 -> args . V_111 = V_75 ;
V_163 -> args . V_236 = V_922 |
V_923 ;
#ifdef F_563
V_163 -> args . V_236 |= V_924 ;
#endif
V_179 . V_337 = & V_163 -> args ;
V_179 . V_338 = & V_163 -> V_69 ;
V_339 . V_185 = V_163 ;
return F_86 ( & V_339 ) ;
V_919:
F_115 ( V_163 -> V_69 . V_906 ) ;
V_915:
F_115 ( V_163 -> V_69 . V_855 ) ;
V_913:
F_115 ( V_163 -> V_69 . V_907 ) ;
V_911:
F_115 ( V_163 ) ;
V_156:
F_407 ( V_75 ) ;
return F_79 ( V_329 ) ;
}
static int F_564 ( struct V_58 * V_75 , struct V_54 * V_55 ,
T_1 V_908 )
{
struct V_115 * V_116 ;
struct V_925 * V_926 ;
struct V_927 * V_928 ;
int V_329 ;
V_116 = F_562 ( V_75 , V_55 , V_908 , NULL ) ;
if ( F_78 ( V_116 ) )
return F_87 ( V_116 ) ;
V_926 = V_116 -> V_348 . V_337 ;
V_928 = V_116 -> V_348 . V_338 ;
V_329 = V_116 -> V_120 ;
if ( V_329 != 0 )
goto V_156;
V_329 = F_549 ( V_928 -> V_236 ) ;
if ( V_329 != 0 )
goto V_156;
V_329 = F_558 ( V_75 , & V_928 -> V_917 ) ;
if ( V_329 != 0 )
goto V_156;
V_75 -> V_259 = V_928 -> V_258 ;
V_75 -> V_929 = V_928 -> V_236 ;
V_75 -> V_930 = V_928 -> V_226 ;
if ( ! ( V_928 -> V_236 & V_931 ) )
F_144 ( V_932 ,
& V_75 -> V_100 -> V_933 ) ;
if ( V_75 -> V_934 != NULL &&
! F_550 ( V_75 -> V_934 ,
V_928 -> V_855 ) ) {
F_8 ( L_71 ,
V_34 ) ;
F_142 ( V_935 , & V_75 -> V_119 ) ;
}
F_565 ( V_75 -> V_936 , V_928 -> V_907 ) ;
F_565 ( V_75 -> V_934 , V_928 -> V_855 ) ;
F_565 ( V_75 -> V_937 , V_928 -> V_906 ) ;
memcpy ( V_75 -> V_921 . V_165 , V_926 -> V_37 . V_165 ,
sizeof( V_75 -> V_921 . V_165 ) ) ;
V_156:
F_566 ( V_75 , V_329 ) ;
F_88 ( V_116 ) ;
return V_329 ;
}
int F_567 ( struct V_58 * V_75 , struct V_54 * V_55 )
{
T_5 V_938 = V_75 -> V_123 -> V_124 -> V_125 ;
int V_329 ;
if ( V_938 == V_126 ||
V_938 == V_127 ) {
V_329 = F_564 ( V_75 , V_55 , V_880 ) ;
if ( ! V_329 )
return 0 ;
}
return F_564 ( V_75 , V_55 , V_916 ) ;
}
int F_568 ( struct V_67 * V_68 , struct V_856 * V_857 ,
void * V_165 )
{
struct V_939 * V_940 = (struct V_939 * ) V_165 ;
struct V_115 * V_116 ;
int V_329 ;
T_1 V_908 ;
F_8 ( L_72 , V_34 ,
V_857 -> V_941 [ V_698 ] ) ;
V_908 = ( V_940 -> V_75 -> V_903 == 0 ? V_916 : V_880 ) ;
V_116 = F_562 ( V_940 -> V_75 , V_940 -> V_55 , V_908 , V_857 ) ;
if ( F_78 ( V_116 ) )
return F_87 ( V_116 ) ;
V_329 = V_116 -> V_120 ;
if ( V_329 == 0 )
V_329 = F_569 ( V_940 -> V_75 ,
V_116 -> V_348 . V_338 , V_857 ) ;
F_88 ( V_116 ) ;
return V_329 ;
}
static int F_570 ( struct V_58 * V_75 ,
struct V_54 * V_55 )
{
struct V_178 V_179 = {
. V_334 = & V_335 [ V_942 ] ,
. V_337 = V_75 ,
. V_54 = V_55 ,
} ;
int V_329 ;
V_329 = F_415 ( V_75 -> V_123 , & V_179 , V_652 ) ;
F_571 ( V_75 , V_329 ) ;
if ( V_329 )
F_8 ( L_73
L_74 , V_329 , V_75 -> V_110 ) ;
return V_329 ;
}
static int F_572 ( struct V_58 * V_75 ,
struct V_54 * V_55 )
{
unsigned int V_943 ;
int V_64 ;
for ( V_943 = V_944 ; V_943 != 0 ; V_943 -- ) {
V_64 = F_570 ( V_75 , V_55 ) ;
switch ( V_64 ) {
case - V_102 :
case - V_945 :
F_195 ( 1 ) ;
break;
default:
return V_64 ;
}
}
return 0 ;
}
int F_573 ( struct V_58 * V_75 )
{
struct V_54 * V_55 ;
int V_64 = 0 ;
if ( V_75 -> V_59 -> V_354 < 1 )
goto V_156;
if ( V_75 -> V_929 == 0 )
goto V_156;
if ( V_75 -> V_946 )
goto V_156;
V_55 = F_546 ( V_75 ) ;
V_64 = F_572 ( V_75 , V_55 ) ;
if ( V_55 )
F_235 ( V_55 ) ;
switch ( V_64 ) {
case 0 :
case - V_89 :
V_75 -> V_929 = 0 ;
}
V_156:
return V_64 ;
}
static void F_574 ( struct V_115 * V_116 ,
void * V_163 )
{
struct V_947 * V_165 =
(struct V_947 * ) V_163 ;
F_8 ( L_36 , V_34 ) ;
F_73 ( V_165 -> V_75 ,
& V_165 -> args -> V_948 ,
& V_165 -> V_69 -> V_949 ,
V_116 ) ;
F_8 ( L_75 , V_34 ) ;
}
static void F_575 ( struct V_115 * V_116 , void * V_163 )
{
struct V_947 * V_165 =
(struct V_947 * ) V_163 ;
F_8 ( L_36 , V_34 ) ;
if ( ! F_68 ( V_116 , & V_165 -> V_69 -> V_949 ) )
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
int F_576 ( struct V_58 * V_75 , struct V_511 * V_615 )
{
struct V_115 * V_116 ;
struct V_950 args ;
struct V_951 V_69 = {
. V_952 = V_615 ,
} ;
struct V_947 V_165 = {
. args = & args ,
. V_69 = & V_69 ,
. V_75 = V_75 ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_953 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
} ;
struct V_180 V_181 = {
. V_182 = V_75 -> V_123 ,
. V_178 = & V_179 ,
. V_183 = & V_954 ,
. V_185 = & V_165 ,
. V_236 = V_652 ,
} ;
int V_329 ;
F_51 ( & args . V_948 , & V_69 . V_949 , 0 ) ;
F_52 ( & args . V_948 ) ;
V_116 = F_86 ( & V_181 ) ;
if ( F_78 ( V_116 ) )
return F_87 ( V_116 ) ;
V_329 = V_116 -> V_120 ;
F_88 ( V_116 ) ;
return V_329 ;
}
static void F_577 ( struct V_955 * args ,
struct V_67 * V_68 )
{
unsigned int V_956 , V_957 ;
unsigned int V_958 = F_578 ( V_68 ) ;
V_956 = V_959 + V_960 ;
V_957 = V_959 + V_961 ;
args -> V_962 . V_956 = V_956 ;
args -> V_962 . V_957 = V_957 ;
args -> V_962 . V_963 = V_964 ;
args -> V_962 . V_965 = V_966 ;
F_8 ( L_77
L_78 ,
V_34 ,
args -> V_962 . V_956 , args -> V_962 . V_957 ,
args -> V_962 . V_963 , args -> V_962 . V_965 ) ;
args -> V_967 . V_956 = V_958 ;
args -> V_967 . V_957 = V_958 ;
args -> V_967 . V_968 = 0 ;
args -> V_967 . V_963 = V_969 ;
args -> V_967 . V_965 = F_418 (unsigned short, max_session_cb_slots, 1 ) ;
F_8 ( L_79
L_80 ,
V_34 ,
args -> V_967 . V_956 , args -> V_967 . V_957 ,
args -> V_967 . V_968 , args -> V_967 . V_963 ,
args -> V_967 . V_965 ) ;
}
static int F_579 ( struct V_955 * args ,
struct V_970 * V_69 )
{
struct V_971 * V_972 = & args -> V_962 ;
struct V_971 * V_973 = & V_69 -> V_962 ;
if ( V_973 -> V_957 > V_972 -> V_957 )
return - V_27 ;
if ( V_973 -> V_963 < V_972 -> V_963 )
return - V_27 ;
if ( V_973 -> V_965 == 0 )
return - V_27 ;
if ( V_973 -> V_965 > V_974 )
V_973 -> V_965 = V_974 ;
return 0 ;
}
static int F_580 ( struct V_955 * args ,
struct V_970 * V_69 )
{
struct V_971 * V_972 = & args -> V_967 ;
struct V_971 * V_973 = & V_69 -> V_967 ;
if ( ! ( V_69 -> V_236 & V_865 ) )
goto V_156;
if ( V_973 -> V_956 > V_972 -> V_956 )
return - V_27 ;
if ( V_973 -> V_957 < V_972 -> V_957 )
return - V_27 ;
if ( V_973 -> V_968 > V_972 -> V_968 )
return - V_27 ;
if ( V_973 -> V_963 > V_972 -> V_963 )
return - V_27 ;
if ( V_973 -> V_965 > V_972 -> V_965 )
return - V_27 ;
V_156:
return 0 ;
}
static int F_581 ( struct V_955 * args ,
struct V_970 * V_69 )
{
int V_64 ;
V_64 = F_579 ( args , V_69 ) ;
if ( V_64 )
return V_64 ;
return F_580 ( args , V_69 ) ;
}
static void F_582 ( struct V_144 * V_145 ,
struct V_970 * V_69 )
{
F_553 ( & V_145 -> V_864 , & V_69 -> V_863 ) ;
V_145 -> V_75 -> V_929 |= V_931 ;
F_142 ( V_932 , & V_145 -> V_933 ) ;
V_145 -> V_236 = V_69 -> V_236 ;
memcpy ( & V_145 -> V_962 , & V_69 -> V_962 , sizeof( V_145 -> V_962 ) ) ;
if ( V_69 -> V_236 & V_865 )
memcpy ( & V_145 -> V_967 , & V_69 -> V_967 ,
sizeof( V_145 -> V_967 ) ) ;
}
static int F_583 ( struct V_58 * V_75 ,
struct V_54 * V_55 )
{
struct V_144 * V_145 = V_75 -> V_100 ;
struct V_955 args = {
. V_111 = V_75 ,
. V_258 = V_75 -> V_259 ,
. V_226 = V_75 -> V_930 ,
. V_975 = V_976 ,
} ;
struct V_970 V_69 ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_977 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
. V_54 = V_55 ,
} ;
int V_329 ;
F_577 ( & args , V_75 -> V_123 ) ;
args . V_236 = ( V_978 | V_865 ) ;
V_329 = F_415 ( V_145 -> V_75 -> V_123 , & V_179 , V_652 ) ;
F_584 ( V_75 , V_329 ) ;
switch ( V_329 ) {
case - V_89 :
case - V_102 :
case - V_979 :
case - V_29 :
case - V_121 :
goto V_156;
} ;
V_75 -> V_930 ++ ;
if ( ! V_329 ) {
V_329 = F_581 ( & args , & V_69 ) ;
if ( V_329 )
goto V_156;
F_582 ( V_145 , & V_69 ) ;
}
V_156:
return V_329 ;
}
int F_585 ( struct V_58 * V_75 , struct V_54 * V_55 )
{
int V_329 ;
unsigned * V_980 ;
struct V_144 * V_145 = V_75 -> V_100 ;
F_8 ( L_81 , V_34 , V_75 , V_145 ) ;
V_329 = F_583 ( V_75 , V_55 ) ;
if ( V_329 )
goto V_156;
V_329 = F_586 ( V_145 ) ;
F_8 ( L_82 , V_329 ) ;
if ( V_329 )
goto V_156;
V_980 = ( unsigned * ) & V_145 -> V_864 . V_165 [ 0 ] ;
F_8 ( L_83 , V_34 ,
V_75 -> V_930 , V_980 [ 0 ] , V_980 [ 1 ] , V_980 [ 2 ] , V_980 [ 3 ] ) ;
V_156:
F_8 ( L_75 , V_34 ) ;
return V_329 ;
}
int F_587 ( struct V_144 * V_145 ,
struct V_54 * V_55 )
{
struct V_178 V_179 = {
. V_334 = & V_335 [ V_981 ] ,
. V_337 = V_145 ,
. V_54 = V_55 ,
} ;
int V_329 = 0 ;
F_8 ( L_84 ) ;
if ( ! F_135 ( V_932 , & V_145 -> V_933 ) )
return 0 ;
V_329 = F_415 ( V_145 -> V_75 -> V_123 , & V_179 , V_652 ) ;
F_588 ( V_145 -> V_75 , V_329 ) ;
if ( V_329 )
F_8 ( L_85
L_86 , V_329 ) ;
F_8 ( L_87 ) ;
return V_329 ;
}
static void F_589 ( void * V_165 )
{
struct V_982 * V_163 = V_165 ;
struct V_58 * V_75 = V_163 -> V_75 ;
if ( F_405 ( & V_75 -> V_646 ) > 1 )
F_406 ( V_75 ) ;
F_407 ( V_75 ) ;
F_115 ( V_163 ) ;
}
static int F_590 ( struct V_115 * V_116 , struct V_58 * V_75 )
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
static void F_591 ( struct V_115 * V_116 , void * V_165 )
{
struct V_982 * V_163 = V_165 ;
struct V_58 * V_75 = V_163 -> V_75 ;
if ( ! F_68 ( V_116 , V_116 -> V_348 . V_338 ) )
return;
F_592 ( V_75 , V_116 -> V_120 ) ;
if ( V_116 -> V_120 < 0 ) {
F_8 ( L_88 , V_34 , V_116 -> V_120 ) ;
if ( F_405 ( & V_75 -> V_646 ) == 1 )
goto V_156;
if ( F_590 ( V_116 , V_75 ) == - V_121 ) {
F_66 ( V_116 ) ;
return;
}
}
F_8 ( L_89 , V_34 , V_116 -> V_348 . V_54 ) ;
V_156:
F_8 ( L_75 , V_34 ) ;
}
static void F_593 ( struct V_115 * V_116 , void * V_165 )
{
struct V_982 * V_163 = V_165 ;
struct V_58 * V_75 = V_163 -> V_75 ;
struct V_131 * args ;
struct V_132 * V_69 ;
args = V_116 -> V_348 . V_337 ;
V_69 = V_116 -> V_348 . V_338 ;
F_73 ( V_75 , args , V_69 , V_116 ) ;
}
static struct V_115 * F_594 ( struct V_58 * V_75 ,
struct V_54 * V_55 ,
bool V_983 )
{
struct V_982 * V_163 ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_984 ] ,
. V_54 = V_55 ,
} ;
struct V_180 V_339 = {
. V_182 = V_75 -> V_123 ,
. V_178 = & V_179 ,
. V_183 = & V_985 ,
. V_236 = V_343 | V_652 ,
} ;
if ( ! F_412 ( & V_75 -> V_646 ) )
return F_79 ( - V_35 ) ;
V_163 = F_104 ( sizeof( * V_163 ) , V_326 ) ;
if ( V_163 == NULL ) {
F_407 ( V_75 ) ;
return F_79 ( - V_174 ) ;
}
F_51 ( & V_163 -> args , & V_163 -> V_69 , 0 ) ;
if ( V_983 )
F_52 ( & V_163 -> args ) ;
V_179 . V_337 = & V_163 -> args ;
V_179 . V_338 = & V_163 -> V_69 ;
V_163 -> V_75 = V_75 ;
V_339 . V_185 = V_163 ;
return F_86 ( & V_339 ) ;
}
static int F_595 ( struct V_58 * V_75 , struct V_54 * V_55 , unsigned V_650 )
{
struct V_115 * V_116 ;
int V_64 = 0 ;
if ( ( V_650 & V_986 ) == 0 )
return - V_121 ;
V_116 = F_594 ( V_75 , V_55 , false ) ;
if ( F_78 ( V_116 ) )
V_64 = F_87 ( V_116 ) ;
else
F_493 ( V_116 ) ;
F_8 ( L_90 , V_34 , V_64 ) ;
return V_64 ;
}
static int F_596 ( struct V_58 * V_75 , struct V_54 * V_55 )
{
struct V_115 * V_116 ;
int V_64 ;
V_116 = F_594 ( V_75 , V_55 , true ) ;
if ( F_78 ( V_116 ) ) {
V_64 = F_87 ( V_116 ) ;
goto V_156;
}
V_64 = F_203 ( V_116 ) ;
if ( ! V_64 )
V_64 = V_116 -> V_120 ;
F_88 ( V_116 ) ;
V_156:
F_8 ( L_90 , V_34 , V_64 ) ;
return V_64 ;
}
static void F_597 ( struct V_115 * V_116 , void * V_165 )
{
struct V_987 * V_163 = V_165 ;
F_73 ( V_163 -> V_75 ,
& V_163 -> V_429 . V_167 ,
& V_163 -> V_69 . V_168 ,
V_116 ) ;
}
static int F_598 ( struct V_115 * V_116 , struct V_58 * V_75 )
{
switch( V_116 -> V_120 ) {
case 0 :
case - V_988 :
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
static void F_599 ( struct V_115 * V_116 , void * V_165 )
{
struct V_987 * V_163 = V_165 ;
struct V_58 * V_75 = V_163 -> V_75 ;
struct V_132 * V_69 = & V_163 -> V_69 . V_168 ;
F_8 ( L_36 , V_34 ) ;
if ( ! F_68 ( V_116 , V_69 ) )
return;
F_600 ( V_75 , V_116 -> V_120 ) ;
if ( F_598 ( V_116 , V_75 ) == - V_121 ) {
F_66 ( V_116 ) ;
return;
}
F_8 ( L_75 , V_34 ) ;
}
static void F_601 ( void * V_165 )
{
struct V_987 * V_163 = V_165 ;
F_115 ( V_163 ) ;
}
static int F_602 ( struct V_58 * V_75 ,
struct V_54 * V_55 )
{
struct V_987 * V_163 ;
struct V_115 * V_116 ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_989 ] ,
. V_54 = V_55 ,
} ;
struct V_180 V_339 = {
. V_182 = V_75 -> V_123 ,
. V_178 = & V_179 ,
. V_183 = & V_990 ,
. V_236 = V_343 ,
} ;
int V_329 = - V_174 ;
F_8 ( L_36 , V_34 ) ;
V_163 = F_104 ( sizeof( * V_163 ) , V_326 ) ;
if ( V_163 == NULL )
goto V_156;
V_163 -> V_75 = V_75 ;
V_163 -> V_429 . V_991 = 0 ;
F_51 ( & V_163 -> V_429 . V_167 , & V_163 -> V_69 . V_168 , 0 ) ;
F_52 ( & V_163 -> V_429 . V_167 ) ;
V_179 . V_337 = & V_163 -> V_429 ;
V_179 . V_338 = & V_163 -> V_69 ;
V_339 . V_185 = V_163 ;
V_116 = F_86 ( & V_339 ) ;
if ( F_78 ( V_116 ) ) {
V_329 = F_87 ( V_116 ) ;
goto V_156;
}
V_329 = F_203 ( V_116 ) ;
if ( V_329 == 0 )
V_329 = V_116 -> V_120 ;
F_88 ( V_116 ) ;
V_156:
F_8 ( L_90 , V_34 , V_329 ) ;
return V_329 ;
}
static void
F_603 ( struct V_115 * V_116 , void * V_163 )
{
struct V_992 * V_993 = V_163 ;
struct V_13 * V_14 = F_103 ( V_993 -> args . V_2 ) ;
F_8 ( L_36 , V_34 ) ;
F_73 ( V_14 -> V_58 , & V_993 -> args . V_167 ,
& V_993 -> V_69 . V_168 , V_116 ) ;
F_8 ( L_75 , V_34 ) ;
}
static void F_604 ( struct V_115 * V_116 , void * V_163 )
{
struct V_992 * V_993 = V_163 ;
F_8 ( L_36 , V_34 ) ;
F_61 ( V_116 , & V_993 -> V_69 . V_168 ) ;
F_8 ( L_75 , V_34 ) ;
}
static int
F_605 ( struct V_115 * V_116 ,
struct V_992 * V_993 , struct V_73 * V_74 )
{
struct V_2 * V_2 = V_993 -> args . V_2 ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
struct V_994 * V_995 ;
int V_996 = V_116 -> V_120 ;
int V_8 , V_329 = 0 ;
F_606 ( V_997 ) ;
F_8 ( L_91 , V_34 , - V_116 -> V_120 ) ;
switch ( V_996 ) {
case 0 :
goto V_156;
case - V_998 :
V_329 = - V_999 ;
goto V_156;
case - V_1000 :
V_329 = - V_1001 ;
goto V_156;
case - V_19 :
if ( V_993 -> args . V_1002 == 0 ) {
V_329 = - V_1001 ;
goto V_156;
}
V_329 = - V_33 ;
break;
case - V_20 :
V_329 = - V_1003 ;
break;
case - V_81 :
case - V_82 :
case - V_83 :
case - V_84 :
V_74 -> V_63 = 0 ;
F_46 ( & V_2 -> V_190 ) ;
V_995 = F_91 ( V_2 ) -> V_1004 ;
if ( ! V_995 || F_38 ( V_1005 , & V_995 -> V_1006 ) ||
! F_139 ( & V_993 -> args . V_53 , & V_995 -> V_1007 ) ) {
F_48 ( & V_2 -> V_190 ) ;
V_74 -> V_77 = V_993 -> args . V_324 -> V_77 ;
V_74 -> V_53 = & V_993 -> args . V_53 ;
break;
}
F_607 ( V_995 , & V_997 ) ;
F_48 ( & V_2 -> V_190 ) ;
F_608 ( V_2 , 0 ) ;
F_609 ( & V_997 ) ;
V_329 = - V_121 ;
goto V_156;
}
F_70 ( & V_993 -> V_69 . V_168 ) ;
V_8 = F_36 ( V_14 , V_996 , V_74 ) ;
if ( ! V_329 ) {
if ( V_74 -> V_80 )
V_329 = - V_121 ;
else
V_329 = V_8 ;
}
V_156:
F_8 ( L_75 , V_34 ) ;
return V_329 ;
}
static T_9 F_610 ( struct V_13 * V_14 )
{
T_1 V_957 = V_14 -> V_58 -> V_100 -> V_962 . V_957 ;
return F_611 ( 0 , V_957 ) ;
}
static void F_612 ( struct V_534 * * V_45 , T_9 V_1008 )
{
int V_477 ;
if ( ! V_45 )
return;
for ( V_477 = 0 ; V_477 < V_1008 ; V_477 ++ ) {
if ( ! V_45 [ V_477 ] )
break;
F_307 ( V_45 [ V_477 ] ) ;
}
F_115 ( V_45 ) ;
}
static struct V_534 * * F_613 ( T_9 V_1008 , T_7 V_1009 )
{
struct V_534 * * V_45 ;
int V_477 ;
V_45 = F_614 ( V_1008 , sizeof( struct V_534 * ) , V_1009 ) ;
if ( ! V_45 ) {
F_8 ( L_92 , V_34 , V_1008 ) ;
return NULL ;
}
for ( V_477 = 0 ; V_477 < V_1008 ; V_477 ++ ) {
V_45 [ V_477 ] = F_303 ( V_1009 ) ;
if ( ! V_45 [ V_477 ] ) {
F_8 ( L_93 , V_34 ) ;
F_612 ( V_45 , V_1008 ) ;
return NULL ;
}
}
return V_45 ;
}
static void F_615 ( void * V_163 )
{
struct V_992 * V_993 = V_163 ;
struct V_2 * V_2 = V_993 -> args . V_2 ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
T_9 V_1010 = F_610 ( V_14 ) ;
F_8 ( L_36 , V_34 ) ;
F_70 ( & V_993 -> V_69 . V_168 ) ;
F_612 ( V_993 -> args . V_1004 . V_45 , V_1010 ) ;
F_616 ( F_91 ( V_2 ) -> V_1004 ) ;
F_193 ( V_993 -> args . V_324 ) ;
F_115 ( V_163 ) ;
F_8 ( L_75 , V_34 ) ;
}
struct V_1011 *
F_617 ( struct V_992 * V_993 , long * V_63 , T_7 V_1009 )
{
struct V_2 * V_2 = V_993 -> args . V_2 ;
struct V_13 * V_14 = F_103 ( V_2 ) ;
T_9 V_1010 = F_610 ( V_14 ) ;
struct V_115 * V_116 ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_1012 ] ,
. V_337 = & V_993 -> args ,
. V_338 = & V_993 -> V_69 ,
. V_54 = V_993 -> V_55 ,
} ;
struct V_180 V_339 = {
. V_182 = V_14 -> V_111 ,
. V_178 = & V_179 ,
. V_183 = & V_1013 ,
. V_185 = V_993 ,
. V_236 = V_343 ,
} ;
struct V_1011 * V_1014 = NULL ;
struct V_73 V_74 = {
. V_2 = V_2 ,
. V_63 = * V_63 ,
} ;
int V_329 = 0 ;
F_8 ( L_36 , V_34 ) ;
F_618 ( F_91 ( V_2 ) -> V_1004 ) ;
V_993 -> args . V_1004 . V_45 = F_613 ( V_1010 , V_1009 ) ;
if ( ! V_993 -> args . V_1004 . V_45 ) {
F_615 ( V_993 ) ;
return F_79 ( - V_174 ) ;
}
V_993 -> args . V_1004 . V_565 = V_1010 * V_659 ;
V_993 -> V_69 . V_1015 = & V_993 -> args . V_1004 ;
V_993 -> V_69 . V_168 . V_137 = NULL ;
F_51 ( & V_993 -> args . V_167 , & V_993 -> V_69 . V_168 , 0 ) ;
V_116 = F_86 ( & V_339 ) ;
if ( F_78 ( V_116 ) )
return F_173 ( V_116 ) ;
V_329 = F_203 ( V_116 ) ;
if ( V_329 == 0 ) {
V_329 = F_605 ( V_116 , V_993 , & V_74 ) ;
* V_63 = V_74 . V_63 ;
}
F_619 ( V_993 -> args . V_324 ,
& V_993 -> args . V_1016 ,
& V_993 -> V_69 . V_1016 ,
& V_993 -> V_69 . V_53 ,
V_329 ) ;
if ( V_329 == 0 && V_993 -> V_69 . V_1015 -> V_12 )
V_1014 = F_620 ( V_993 ) ;
F_88 ( V_116 ) ;
F_8 ( L_90 , V_34 , V_329 ) ;
if ( V_329 )
return F_79 ( V_329 ) ;
return V_1014 ;
}
static void
F_621 ( struct V_115 * V_116 , void * V_163 )
{
struct V_1017 * V_1018 = V_163 ;
F_8 ( L_36 , V_34 ) ;
F_73 ( V_1018 -> V_75 ,
& V_1018 -> args . V_167 ,
& V_1018 -> V_69 . V_168 ,
V_116 ) ;
}
static void F_622 ( struct V_115 * V_116 , void * V_163 )
{
struct V_1017 * V_1018 = V_163 ;
struct V_13 * V_14 ;
F_8 ( L_36 , V_34 ) ;
if ( ! F_61 ( V_116 , & V_1018 -> V_69 . V_168 ) )
return;
V_14 = F_103 ( V_1018 -> args . V_2 ) ;
switch ( V_116 -> V_120 ) {
default:
V_116 -> V_120 = 0 ;
case 0 :
break;
case - V_102 :
if ( F_43 ( V_116 , V_14 , NULL , NULL ) != - V_121 )
break;
F_70 ( & V_1018 -> V_69 . V_168 ) ;
F_66 ( V_116 ) ;
return;
}
F_8 ( L_75 , V_34 ) ;
}
static void F_623 ( void * V_163 )
{
struct V_1017 * V_1018 = V_163 ;
struct V_994 * V_995 = V_1018 -> args . V_1004 ;
F_8 ( L_36 , V_34 ) ;
F_624 ( V_995 , & V_1018 -> args . V_53 , & V_1018 -> args . V_1016 ,
V_1018 -> V_69 . V_1019 ? & V_1018 -> V_69 . V_53 : NULL ) ;
F_70 ( & V_1018 -> V_69 . V_168 ) ;
if ( V_1018 -> V_467 . V_57 && V_1018 -> V_467 . V_57 -> free )
V_1018 -> V_467 . V_57 -> free ( & V_1018 -> V_467 ) ;
F_616 ( V_1018 -> args . V_1004 ) ;
F_464 ( V_1018 -> V_2 ) ;
F_115 ( V_163 ) ;
F_8 ( L_75 , V_34 ) ;
}
int F_625 ( struct V_1017 * V_1018 , bool V_1020 )
{
struct V_115 * V_116 ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_1021 ] ,
. V_337 = & V_1018 -> args ,
. V_338 = & V_1018 -> V_69 ,
. V_54 = V_1018 -> V_55 ,
} ;
struct V_180 V_339 = {
. V_182 = F_103 ( V_1018 -> args . V_2 ) -> V_111 ,
. V_178 = & V_179 ,
. V_183 = & V_1022 ,
. V_185 = V_1018 ,
} ;
int V_329 = 0 ;
F_283 ( F_103 ( V_1018 -> args . V_2 ) -> V_58 ,
V_893 ,
& V_339 . V_182 , & V_179 ) ;
F_8 ( L_36 , V_34 ) ;
if ( ! V_1020 ) {
V_1018 -> V_2 = F_468 ( V_1018 -> args . V_2 ) ;
if ( ! V_1018 -> V_2 ) {
F_623 ( V_1018 ) ;
return - V_121 ;
}
V_339 . V_236 |= V_343 ;
}
F_51 ( & V_1018 -> args . V_167 , & V_1018 -> V_69 . V_168 , 1 ) ;
V_116 = F_86 ( & V_339 ) ;
if ( F_78 ( V_116 ) )
return F_87 ( V_116 ) ;
if ( V_1020 )
V_329 = V_116 -> V_120 ;
F_626 ( V_1018 -> args . V_2 , & V_1018 -> args . V_53 , V_329 ) ;
F_8 ( L_90 , V_34 , V_329 ) ;
F_88 ( V_116 ) ;
return V_329 ;
}
static int
F_627 ( struct V_13 * V_14 ,
struct V_1023 * V_1024 ,
struct V_54 * V_55 )
{
struct V_1025 args = {
. V_1024 = V_1024 ,
. V_1026 = V_1027 |
V_1028 ,
} ;
struct V_1029 V_69 = {
. V_1024 = V_1024 ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_1030 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
. V_54 = V_55 ,
} ;
int V_329 ;
F_8 ( L_36 , V_34 ) ;
V_329 = F_89 ( V_14 -> V_111 , V_14 , & V_179 , & args . V_167 , & V_69 . V_168 , 0 ) ;
if ( V_69 . V_1031 & ~ args . V_1026 )
F_8 ( L_94 , V_34 ) ;
if ( V_69 . V_1031 != args . V_1026 )
V_1024 -> V_1032 = 1 ;
F_8 ( L_90 , V_34 , V_329 ) ;
return V_329 ;
}
int F_628 ( struct V_13 * V_14 ,
struct V_1023 * V_1024 ,
struct V_54 * V_55 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_36 ( V_14 ,
F_627 ( V_14 , V_1024 , V_55 ) ,
& V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static void F_629 ( struct V_115 * V_116 , void * V_163 )
{
struct V_1033 * V_165 = V_163 ;
struct V_13 * V_14 = F_103 ( V_165 -> args . V_2 ) ;
F_73 ( V_14 -> V_58 ,
& V_165 -> args . V_167 ,
& V_165 -> V_69 . V_168 ,
V_116 ) ;
}
static void
F_630 ( struct V_115 * V_116 , void * V_163 )
{
struct V_1033 * V_165 = V_163 ;
struct V_13 * V_14 = F_103 ( V_165 -> args . V_2 ) ;
if ( ! F_68 ( V_116 , & V_165 -> V_69 . V_168 ) )
return;
switch ( V_116 -> V_120 ) {
case - V_81 :
case - V_1034 :
case - V_1000 :
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
static void F_631 ( void * V_163 )
{
struct V_1033 * V_165 = V_163 ;
F_632 ( V_165 ) ;
F_463 ( V_165 -> args . V_2 ,
V_165 -> V_69 . V_434 ) ;
F_235 ( V_165 -> V_55 ) ;
F_464 ( V_165 -> V_2 ) ;
F_115 ( V_165 ) ;
}
int
F_633 ( struct V_1033 * V_165 , bool V_1020 )
{
struct V_178 V_179 = {
. V_334 = & V_335 [ V_1035 ] ,
. V_337 = & V_165 -> args ,
. V_338 = & V_165 -> V_69 ,
. V_54 = V_165 -> V_55 ,
} ;
struct V_180 V_339 = {
. V_116 = & V_165 -> V_116 ,
. V_182 = F_322 ( V_165 -> args . V_2 ) ,
. V_178 = & V_179 ,
. V_183 = & V_1036 ,
. V_185 = V_165 ,
} ;
struct V_115 * V_116 ;
int V_329 = 0 ;
F_8 ( L_95
L_96 , V_1020 ,
V_165 -> args . V_1037 ,
V_165 -> args . V_2 -> V_556 ) ;
if ( ! V_1020 ) {
V_165 -> V_2 = F_468 ( V_165 -> args . V_2 ) ;
if ( V_165 -> V_2 == NULL ) {
F_631 ( V_165 ) ;
return - V_121 ;
}
V_339 . V_236 = V_343 ;
}
F_51 ( & V_165 -> args . V_167 , & V_165 -> V_69 . V_168 , 1 ) ;
V_116 = F_86 ( & V_339 ) ;
if ( F_78 ( V_116 ) )
return F_87 ( V_116 ) ;
if ( V_1020 )
V_329 = V_116 -> V_120 ;
F_634 ( V_165 -> args . V_2 , & V_165 -> args . V_53 , V_329 ) ;
F_8 ( L_97 , V_34 , V_329 ) ;
F_88 ( V_116 ) ;
return V_329 ;
}
static int
F_635 ( struct V_13 * V_14 , struct V_470 * V_471 ,
struct V_511 * V_512 ,
struct V_839 * V_527 , bool V_840 )
{
struct V_1038 args = {
. V_1039 = V_1040 ,
} ;
struct V_842 V_69 = {
. V_527 = V_527 ,
} ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_1041 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
} ;
struct V_67 * V_68 = V_14 -> V_111 ;
struct V_54 * V_55 = NULL ;
int V_329 ;
if ( V_840 ) {
V_68 = V_14 -> V_58 -> V_123 ;
V_55 = F_546 ( V_14 -> V_58 ) ;
V_179 . V_54 = V_55 ;
}
F_8 ( L_36 , V_34 ) ;
V_329 = F_89 ( V_68 , V_14 , & V_179 , & args . V_167 ,
& V_69 . V_168 , 0 ) ;
F_8 ( L_90 , V_34 , V_329 ) ;
if ( V_55 )
F_235 ( V_55 ) ;
return V_329 ;
}
static int
F_636 ( struct V_13 * V_14 , struct V_470 * V_471 ,
struct V_511 * V_512 , struct V_839 * V_527 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = - V_22 ;
if ( F_44 ( V_14 -> V_58 ) )
V_8 = F_635 ( V_14 , V_471 , V_512 ,
V_527 , true ) ;
if ( V_8 == - V_22 )
V_8 = F_635 ( V_14 , V_471 , V_512 ,
V_527 , false ) ;
switch ( V_8 ) {
case 0 :
case - V_22 :
case - V_1042 :
goto V_156;
default:
V_8 = F_36 ( V_14 , V_8 , & V_74 ) ;
}
} while ( V_74 . V_80 );
V_156:
return V_8 ;
}
static int
F_637 ( struct V_13 * V_14 , struct V_470 * V_471 ,
struct V_511 * V_512 )
{
int V_8 ;
struct V_534 * V_534 ;
T_5 V_122 = V_1043 ;
struct V_839 * V_527 ;
struct V_1044 * V_1045 ;
int V_477 ;
V_534 = F_303 ( V_419 ) ;
if ( ! V_534 ) {
V_8 = - V_174 ;
goto V_156;
}
V_527 = F_419 ( V_534 ) ;
V_8 = F_636 ( V_14 , V_471 , V_512 , V_527 ) ;
if ( V_8 == - V_22 || V_8 == - V_1042 ) {
V_8 = F_297 ( V_14 , V_471 , V_512 ) ;
goto V_1046;
}
if ( V_8 )
goto V_1046;
for ( V_477 = 0 ; V_477 < V_527 -> V_1047 ; V_477 ++ ) {
V_1045 = & V_527 -> V_527 [ V_477 ] ;
switch ( V_1045 -> V_122 ) {
case V_524 :
case V_523 :
case V_1048 :
V_122 = F_638 ( V_1045 -> V_122 ,
& V_1045 -> V_1049 ) ;
break;
default:
V_122 = V_1043 ;
break;
}
if ( ! F_639 ( & V_14 -> V_525 , V_122 ) )
V_122 = V_1043 ;
if ( V_122 != V_1043 ) {
V_8 = F_295 ( V_14 , V_471 ,
V_512 , V_122 ) ;
if ( ! V_8 )
break;
}
}
if ( V_122 == V_1043 )
V_8 = - V_24 ;
V_1046:
F_433 ( V_534 ) ;
if ( V_8 == - V_29 )
return - V_24 ;
V_156:
return V_8 ;
}
static int F_640 ( struct V_13 * V_14 ,
T_4 * V_53 ,
struct V_54 * V_55 )
{
int V_329 ;
struct V_1050 args = {
. V_53 = V_53 ,
} ;
struct V_1051 V_69 ;
struct V_178 V_179 = {
. V_334 = & V_335 [ V_1052 ] ,
. V_337 = & args ,
. V_338 = & V_69 ,
. V_54 = V_55 ,
} ;
struct V_67 * V_182 = V_14 -> V_111 ;
F_283 ( V_14 -> V_58 , V_898 ,
& V_182 , & V_179 ) ;
F_8 ( L_98 , V_53 ) ;
F_51 ( & args . V_167 , & V_69 . V_168 , 0 ) ;
F_52 ( & args . V_167 ) ;
V_329 = F_85 ( V_182 , V_14 , & V_179 ,
& args . V_167 , & V_69 . V_168 ) ;
if ( V_329 != V_389 ) {
F_8 ( L_99 , V_329 ) ;
return V_329 ;
}
F_8 ( L_100 , - V_69 . V_329 ) ;
return - V_69 . V_329 ;
}
static void F_641 ( struct V_13 * V_14 ,
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
static int F_230 ( struct V_13 * V_14 ,
T_4 * V_53 ,
struct V_54 * V_55 )
{
struct V_73 V_74 = { } ;
int V_8 ;
do {
V_8 = F_640 ( V_14 , V_53 , V_55 ) ;
F_641 ( V_14 , V_8 , & V_74 ) ;
} while ( V_74 . V_80 );
return V_8 ;
}
static void F_642 ( struct V_115 * V_116 , void * V_163 )
{
struct V_1053 * V_165 = V_163 ;
F_73 ( V_165 -> V_14 -> V_58 ,
& V_165 -> args . V_167 ,
& V_165 -> V_69 . V_168 ,
V_116 ) ;
}
static void F_643 ( struct V_115 * V_116 , void * V_163 )
{
struct V_1053 * V_165 = V_163 ;
F_68 ( V_116 , & V_165 -> V_69 . V_168 ) ;
switch ( V_116 -> V_120 ) {
case - V_102 :
if ( F_43 ( V_116 , V_165 -> V_14 , NULL , NULL ) == - V_121 )
F_66 ( V_116 ) ;
}
}
static void F_644 ( void * V_163 )
{
F_115 ( V_163 ) ;
}
static struct V_115 * F_645 ( struct V_13 * V_14 ,
const T_4 * V_53 ,
struct V_54 * V_55 ,
bool V_161 )
{
struct V_178 V_179 = {
. V_334 = & V_335 [ V_1054 ] ,
. V_54 = V_55 ,
} ;
struct V_180 V_181 = {
. V_182 = V_14 -> V_111 ,
. V_178 = & V_179 ,
. V_183 = & V_1055 ,
. V_236 = V_343 ,
} ;
struct V_1053 * V_165 ;
F_283 ( V_14 -> V_58 , V_898 ,
& V_181 . V_182 , & V_179 ) ;
F_8 ( L_101 , V_53 ) ;
V_165 = F_304 ( sizeof( * V_165 ) , V_326 ) ;
if ( ! V_165 )
return F_79 ( - V_174 ) ;
V_165 -> V_14 = V_14 ;
F_19 ( & V_165 -> args . V_53 , V_53 ) ;
V_181 . V_185 = V_165 ;
V_179 . V_337 = & V_165 -> args ;
V_179 . V_338 = & V_165 -> V_69 ;
F_51 ( & V_165 -> args . V_167 , & V_165 -> V_69 . V_168 , 1 ) ;
if ( V_161 )
F_52 ( & V_165 -> args . V_167 ) ;
return F_86 ( & V_181 ) ;
}
static int F_231 ( struct V_13 * V_14 ,
const T_4 * V_53 ,
struct V_54 * V_55 ,
bool V_1056 )
{
struct V_115 * V_116 ;
V_116 = F_645 ( V_14 , V_53 , V_55 , V_1056 ) ;
if ( F_78 ( V_116 ) )
return F_87 ( V_116 ) ;
F_88 ( V_116 ) ;
return 0 ;
}
static void
F_646 ( struct V_13 * V_14 , struct V_307 * V_308 )
{
struct V_54 * V_55 = V_308 -> V_309 -> V_248 -> V_306 ;
F_231 ( V_14 , & V_308 -> V_311 , V_55 , false ) ;
F_524 ( V_14 , V_308 ) ;
}
static bool F_647 ( const T_4 * V_1057 ,
const T_4 * V_1058 )
{
if ( V_1057 -> type != V_1058 -> type )
return false ;
if ( memcmp ( V_1057 -> V_1059 , V_1058 -> V_1059 , sizeof( V_1057 -> V_1059 ) ) != 0 )
return false ;
if ( V_1057 -> V_226 == V_1058 -> V_226 )
return true ;
return V_1057 -> V_226 == 0 || V_1058 -> V_226 == 0 ;
}
static bool F_648 ( const T_4 * V_1057 ,
const T_4 * V_1058 )
{
return F_155 ( V_1057 , V_1058 ) ;
}
static struct V_239 *
F_649 ( struct V_241 * V_1060 , T_7 V_1061 )
{
return NULL ;
}
static T_11 F_650 ( struct V_4 * V_4 , char * V_812 , T_9 V_1008 )
{
T_11 error , V_1062 ;
error = F_651 ( V_4 , V_812 , V_1008 ) ;
if ( error < 0 )
return error ;
if ( V_812 ) {
V_812 += error ;
V_1008 -= error ;
}
V_1062 = F_532 ( F_14 ( V_4 ) , V_812 , V_1008 ) ;
if ( V_1062 < 0 )
return V_1062 ;
return error + V_1062 ;
}
