static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
F_2 ( V_4 -> V_6 != V_7 ,
L_1 ,
V_2 , V_4 -> V_6 , V_2 -> V_8 , V_2 -> type , V_2 -> V_9 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
V_4 -> V_6 = V_7 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
V_4 -> V_6 = 0 ;
}
static inline void F_5 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = ( void * ) V_11 -> V_5 ;
F_6 ( V_13 -> V_6 != V_14 ) ;
}
static inline void F_7 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = ( void * ) V_11 -> V_5 ;
V_13 -> V_6 = V_14 ;
}
static inline void F_8 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = ( void * ) V_11 -> V_5 ;
V_13 -> V_6 = 0 ;
}
static inline void F_9 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = ( void * ) V_16 -> V_5 ;
F_6 ( V_18 -> V_6 != V_19 ) ;
}
static inline void F_10 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = ( void * ) V_16 -> V_5 ;
V_18 -> V_6 = V_19 ;
}
static inline void F_11 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = ( void * ) V_16 -> V_5 ;
V_18 -> V_6 = 0 ;
}
static inline int F_12 ( struct V_20 * V_20 )
{
struct V_21 * V_21 = F_13 ( V_20 , V_22 ) ;
return V_21 -> V_23 ;
}
static inline void F_14 ( struct V_20 * V_20 )
{
struct V_21 * V_21 = F_13 ( V_20 , V_22 ) ;
V_21 -> V_23 = V_24 ++ ;
}
static inline T_1 F_15 ( struct V_20 * V_20 )
{
struct V_21 * V_21 = F_13 ( V_20 , V_22 ) ;
return V_21 -> V_25 ;
}
static inline void F_16 ( struct V_20 * V_20 , T_1 V_26 )
{
struct V_21 * V_21 = F_13 ( V_20 , V_22 ) ;
V_21 -> V_25 = V_26 ;
}
static int F_17 ( struct V_27 * V_27 ,
struct V_28 * V_29 ,
const void * V_30 , int V_31 )
{
struct V_32 * V_33 ;
struct V_34 * V_35 [ V_36 + 1 ] ;
int V_37 ;
T_1 V_38 ;
V_37 = F_18 ( V_35 , V_36 , V_30 , V_31 ,
V_39 , NULL ) ;
if ( V_37 )
return V_37 ;
if ( ! V_35 [ V_40 ] )
return - V_41 ;
V_38 = F_19 ( V_35 [ V_40 ] ) ;
F_20 ( V_27 , L_2 , V_42 , V_38 ) ;
V_33 = F_21 ( V_27 , V_29 , 100 , 0 , V_43 ) ;
if ( V_33 ) {
F_22 ( V_33 , V_40 , V_38 + 1 ) ;
F_23 ( V_33 , V_43 ) ;
}
V_33 = F_24 ( V_27 , 10 ) ;
if ( ! V_33 )
return - V_44 ;
F_22 ( V_33 , V_40 , V_38 + 2 ) ;
return F_25 ( V_33 ) ;
}
static void F_26 ( void * V_45 , T_2 * V_46 , struct V_1 * V_2 )
{
struct V_47 * V_30 = V_45 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_32 * V_33 ;
struct V_48 * V_49 ;
if ( ! V_4 -> V_50 )
return;
F_20 ( V_30 -> V_51 -> V_27 ,
L_3 ,
V_42 , V_4 -> V_52 , V_4 -> V_53 ) ;
V_33 = F_27 ( sizeof( * V_49 ) ) ;
if ( ! V_33 )
return;
V_49 = F_28 ( V_33 , sizeof( * V_49 ) ) ;
V_49 -> V_54 = F_29 ( V_55 |
V_56 |
V_57 ) ;
V_49 -> V_53 = F_29 ( 0xc000 | V_4 -> V_53 ) ;
memcpy ( V_49 -> V_52 , V_4 -> V_52 , V_58 ) ;
memcpy ( V_49 -> V_59 , V_46 , V_58 ) ;
F_30 () ;
F_31 ( V_30 -> V_51 , V_33 ,
F_32 ( V_2 -> V_60 ) -> V_61 . V_62 ) ;
F_33 () ;
}
static void F_34 ( struct V_47 * V_30 , T_2 * V_46 ,
struct V_1 * V_2 , int V_63 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_32 * V_33 ;
struct V_64 * V_65 ;
if ( ! V_4 -> V_50 )
return;
F_20 ( V_30 -> V_51 -> V_27 ,
L_4 ,
V_42 , V_4 -> V_52 , V_63 ) ;
V_33 = F_27 ( sizeof( * V_65 ) ) ;
if ( ! V_33 )
return;
V_65 = F_28 ( V_33 , sizeof( * V_65 ) - V_58 ) ;
V_65 -> V_54 = F_29 ( V_66 |
V_67 |
( V_63 ? V_57 : 0 ) ) ;
V_65 -> V_68 = F_29 ( 0 ) ;
memcpy ( V_65 -> V_69 , V_4 -> V_52 , V_58 ) ;
memcpy ( V_65 -> V_70 , V_46 , V_58 ) ;
memcpy ( V_65 -> V_71 , V_4 -> V_52 , V_58 ) ;
F_30 () ;
F_31 ( V_30 -> V_51 , V_33 ,
F_32 ( V_2 -> V_60 ) -> V_61 . V_62 ) ;
F_33 () ;
}
static void F_35 ( void * V_45 , T_2 * V_46 ,
struct V_1 * V_2 )
{
struct V_47 * V_30 = V_45 ;
F_34 ( V_30 , V_46 , V_2 , 1 ) ;
}
static void F_36 ( void * V_45 , T_2 * V_46 ,
struct V_1 * V_2 )
{
struct V_47 * V_30 = V_45 ;
F_34 ( V_30 , V_46 , V_2 , 0 ) ;
}
static int F_37 ( void * V_45 , T_3 * V_38 )
{
struct V_47 * V_30 = V_45 ;
* V_38 = V_30 -> V_63 ;
return 0 ;
}
static int F_38 ( void * V_45 , T_3 V_38 )
{
struct V_47 * V_30 = V_45 ;
enum V_72 V_73 ;
if ( V_38 != V_74 && V_38 != V_75 && V_38 != V_76 &&
V_38 != V_77 )
return - V_41 ;
V_73 = V_30 -> V_63 ;
V_30 -> V_63 = V_38 ;
F_39 () ;
if ( V_38 == V_77 ) {
F_40 (
V_30 -> V_51 , V_78 ,
F_26 , V_30 ) ;
V_30 -> V_79 = true ;
} else if ( V_73 == V_74 && V_38 != V_74 ) {
F_40 (
V_30 -> V_51 , V_78 ,
F_35 , V_30 ) ;
} else if ( V_73 != V_74 && V_38 == V_74 ) {
F_40 (
V_30 -> V_51 , V_78 ,
F_36 , V_30 ) ;
}
F_41 () ;
return 0 ;
}
static int F_42 ( void * V_45 , T_3 V_38 )
{
struct V_47 * V_30 = V_45 ;
F_43 ( V_30 -> V_51 ) ;
return 0 ;
}
static int F_44 ( void * V_45 , T_3 * V_38 )
{
struct V_47 * V_30 = V_45 ;
* V_38 = V_30 -> V_80 ;
return 0 ;
}
static int F_45 ( void * V_45 , T_3 V_38 )
{
struct V_47 * V_30 = V_45 ;
V_30 -> V_80 = V_38 ;
return 0 ;
}
static T_4 F_46 ( struct V_32 * V_33 ,
struct V_81 * V_82 )
{
F_47 ( V_33 ) ;
return V_83 ;
}
static inline T_3 F_48 ( void )
{
return F_49 ( F_50 () ) ;
}
static T_5 F_51 ( struct V_47 * V_30 )
{
T_3 V_84 = F_48 () ;
return F_52 ( V_84 + V_30 -> V_85 ) ;
}
static T_3 F_53 ( struct V_86 * V_51 ,
struct V_1 * V_2 )
{
struct V_47 * V_30 = V_51 -> V_87 ;
return F_54 ( F_51 ( V_30 ) ) ;
}
static void F_55 ( struct V_86 * V_51 ,
struct V_1 * V_2 , T_3 V_88 )
{
struct V_47 * V_30 = V_51 -> V_87 ;
T_3 V_84 = F_53 ( V_51 , V_2 ) ;
T_1 V_89 = V_30 -> V_90 ;
T_3 V_91 = abs ( V_88 - V_84 ) ;
if ( V_88 > V_84 ) {
V_30 -> V_85 += V_91 ;
V_30 -> V_92 = F_56 ( V_91 , V_89 ) ;
} else {
V_30 -> V_85 -= V_91 ;
V_30 -> V_92 = - ( V_93 ) F_56 ( V_91 , V_89 ) ;
}
}
static void F_57 ( struct V_86 * V_51 ,
struct V_32 * V_94 ,
struct V_95 * V_62 )
{
struct V_47 * V_30 = V_51 -> V_87 ;
struct V_32 * V_33 ;
struct V_96 * V_65 ;
T_6 V_97 ;
struct V_98 * V_99 = F_58 ( V_94 ) ;
struct V_100 * V_101 = F_59 ( V_51 , V_99 ) ;
if ( F_6 ( ! V_101 ) )
return;
if ( ! F_60 ( V_102 ) )
return;
V_33 = F_61 ( V_94 , sizeof( * V_65 ) , 0 , V_103 ) ;
if ( V_33 == NULL )
return;
V_65 = F_62 ( V_33 , sizeof( * V_65 ) ) ;
V_65 -> V_65 . V_104 = V_105 ;
V_65 -> V_65 . V_106 = 0 ;
V_65 -> V_65 . V_107 = F_29 ( sizeof( * V_65 ) ) ;
V_65 -> V_65 . V_108 = F_63 ( ( 1 << V_109 ) |
( 1 << V_110 ) |
( 1 << V_111 ) |
( 1 << V_112 ) ) ;
V_65 -> V_113 = F_51 ( V_30 ) ;
V_65 -> V_114 = 0 ;
V_65 -> V_115 = V_101 -> V_116 / 5 ;
V_65 -> V_117 = F_29 ( V_62 -> V_118 ) ;
V_97 = V_119 ;
if ( V_101 -> V_97 & V_120 )
V_97 |= V_121 ;
else
V_97 |= V_122 ;
V_65 -> V_123 = F_29 ( V_97 ) ;
V_33 -> V_82 = V_102 ;
F_64 ( V_33 ) ;
V_33 -> V_124 = V_125 ;
V_33 -> V_126 = V_127 ;
V_33 -> V_128 = F_65 ( V_129 ) ;
memset ( V_33 -> V_130 , 0 , sizeof( V_33 -> V_130 ) ) ;
F_66 ( V_33 ) ;
}
static void F_67 ( struct V_95 * V_62 ,
const T_2 * V_8 )
{
struct V_32 * V_33 ;
struct V_131 * V_65 ;
T_6 V_97 ;
struct V_64 * V_132 ;
if ( ! F_60 ( V_102 ) )
return;
V_33 = F_27 ( 100 ) ;
if ( V_33 == NULL )
return;
V_65 = F_28 ( V_33 , sizeof( * V_65 ) ) ;
V_65 -> V_65 . V_104 = V_105 ;
V_65 -> V_65 . V_106 = 0 ;
V_65 -> V_65 . V_107 = F_29 ( sizeof( * V_65 ) ) ;
V_65 -> V_65 . V_108 = F_63 ( ( 1 << V_109 ) |
( 1 << V_112 ) ) ;
V_65 -> V_114 = 0 ;
V_65 -> V_133 = 0 ;
V_65 -> V_117 = F_29 ( V_62 -> V_118 ) ;
V_97 = V_119 ;
V_65 -> V_123 = F_29 ( V_97 ) ;
V_132 = F_28 ( V_33 , 10 ) ;
V_132 -> V_54 = F_29 ( V_55 |
V_134 ) ;
V_132 -> V_68 = F_29 ( 0 ) ;
memcpy ( V_132 -> V_69 , V_8 , V_58 ) ;
V_33 -> V_82 = V_102 ;
F_64 ( V_33 ) ;
V_33 -> V_124 = V_125 ;
V_33 -> V_126 = V_127 ;
V_33 -> V_128 = F_65 ( V_129 ) ;
memset ( V_33 -> V_130 , 0 , sizeof( V_33 -> V_130 ) ) ;
F_66 ( V_33 ) ;
}
static void F_68 ( void * V_30 , T_2 * V_46 ,
struct V_1 * V_2 )
{
struct V_135 * V_136 = V_30 ;
if ( memcmp ( V_46 , V_136 -> V_8 , V_58 ) == 0 )
V_136 -> V_137 = true ;
}
static bool F_69 ( struct V_47 * V_30 ,
const T_2 * V_8 )
{
struct V_135 V_136 = {
. V_137 = false ,
} ;
if ( V_30 -> V_138 && memcmp ( V_8 , V_30 -> V_139 , V_58 ) == 0 )
return true ;
memcpy ( V_136 . V_8 , V_8 , V_58 ) ;
F_40 ( V_30 -> V_51 ,
V_78 ,
F_68 ,
& V_136 ) ;
return V_136 . V_137 ;
}
static bool F_70 ( struct V_47 * V_30 ,
struct V_32 * V_33 )
{
switch ( V_30 -> V_63 ) {
case V_74 :
return true ;
case V_75 :
return false ;
case V_76 :
return true ;
case V_77 :
if ( V_30 -> V_79 &&
F_69 ( V_30 , V_33 -> V_30 + 4 ) ) {
V_30 -> V_79 = false ;
return true ;
}
return false ;
}
return true ;
}
static int F_71 ( struct V_47 * V_30 ,
struct V_32 * V_33 , int V_26 )
{
struct V_20 * V_20 ;
bool V_140 = false ;
int V_141 = - V_142 ;
F_30 () ;
F_72 (net) {
if ( V_30 -> V_23 == F_12 ( V_20 ) ) {
V_141 = F_73 ( V_20 , V_33 , V_26 ) ;
V_140 = true ;
break;
}
}
F_33 () ;
if ( ! V_140 )
F_74 ( V_33 ) ;
return V_141 ;
}
static void F_75 ( struct V_86 * V_51 ,
struct V_32 * V_143 ,
int V_144 )
{
struct V_32 * V_33 ;
struct V_47 * V_30 = V_51 -> V_87 ;
struct V_64 * V_65 = (struct V_64 * ) V_143 -> V_30 ;
struct V_98 * V_99 = F_58 ( V_143 ) ;
void * V_145 ;
unsigned int V_146 = 0 ;
int V_147 ;
struct V_148 V_149 [ V_150 ] ;
T_7 V_151 ;
if ( V_30 -> V_63 != V_74 )
V_65 -> V_54 |= F_29 ( V_57 ) ;
if ( F_76 ( & V_30 -> V_152 ) >= V_153 ) {
while ( F_76 ( & V_30 -> V_152 ) >= V_154 ) {
F_77 ( V_51 , F_78 ( & V_30 -> V_152 ) ) ;
V_30 -> V_155 ++ ;
}
}
V_33 = F_79 ( V_156 , V_103 ) ;
if ( V_33 == NULL )
goto V_157;
V_145 = F_80 ( V_33 , 0 , 0 , & V_158 , 0 ,
V_159 ) ;
if ( V_145 == NULL ) {
F_81 ( V_160 L_5 ) ;
goto V_157;
}
if ( F_82 ( V_33 , V_161 ,
V_58 , V_30 -> V_162 [ 1 ] . V_8 ) )
goto V_157;
if ( F_82 ( V_33 , V_163 , V_143 -> V_164 , V_143 -> V_30 ) )
goto V_157;
if ( V_99 -> V_97 & V_165 )
V_146 |= V_166 ;
if ( V_99 -> V_97 & V_167 )
V_146 |= V_168 ;
if ( F_22 ( V_33 , V_169 , V_146 ) )
goto V_157;
if ( F_22 ( V_33 , V_170 , V_30 -> V_171 -> V_118 ) )
goto V_157;
for ( V_147 = 0 ; V_147 < V_150 ; V_147 ++ ) {
V_149 [ V_147 ] . V_172 = V_99 -> V_173 . V_174 [ V_147 ] . V_172 ;
V_149 [ V_147 ] . V_175 = V_99 -> V_173 . V_174 [ V_147 ] . V_175 ;
}
if ( F_82 ( V_33 , V_176 ,
sizeof( struct V_148 ) * V_150 ,
V_149 ) )
goto V_157;
V_30 -> V_177 ++ ;
V_151 = V_30 -> V_177 ;
V_99 -> V_178 [ 0 ] = ( void * ) V_151 ;
if ( F_83 ( V_33 , V_179 , V_151 , V_180 ) )
goto V_157;
F_84 ( V_33 , V_145 ) ;
if ( F_71 ( V_30 , V_33 , V_144 ) )
goto V_181;
F_85 ( & V_30 -> V_152 , V_143 ) ;
V_30 -> V_182 ++ ;
V_30 -> V_183 += V_143 -> V_164 ;
return;
V_157:
F_74 ( V_33 ) ;
V_181:
F_81 ( V_160 L_6 , V_42 ) ;
F_77 ( V_51 , V_143 ) ;
V_30 -> V_184 ++ ;
}
static bool F_86 ( struct V_95 * V_185 ,
struct V_95 * V_186 )
{
if ( ! V_185 || ! V_186 )
return false ;
return V_185 -> V_118 == V_186 -> V_118 ;
}
static void F_87 ( void * V_187 , T_2 * V_8 ,
struct V_1 * V_2 )
{
struct V_188 * V_30 = V_187 ;
if ( ! V_2 -> V_60 )
return;
if ( ! F_86 ( V_30 -> V_171 ,
F_32 ( V_2 -> V_60 ) -> V_61 . V_62 ) )
return;
V_30 -> V_189 = true ;
}
static void F_88 ( struct V_32 * V_33 )
{
#ifdef F_89
struct V_190 * V_191 ;
V_191 = F_62 ( V_33 , sizeof( * V_191 ) + 8 + 4 ) ;
V_191 -> V_192 [ 0 ] = F_89 [ 0 ] ;
V_191 -> V_192 [ 1 ] = F_89 [ 1 ] ;
V_191 -> V_192 [ 2 ] = F_89 [ 2 ] ;
V_191 -> V_193 = 127 ;
V_191 -> V_194 = F_90 ( 0 ) ;
V_191 -> V_164 = 8 ;
V_191 -> V_195 = 8 ;
V_191 -> V_133 = 4 ;
memcpy ( V_191 -> V_30 , L_7 , 8 ) ;
memset ( V_191 -> V_30 + 8 , 0 , 4 ) ;
F_91 ( V_33 ) -> V_196 |= V_197 ;
#endif
}
static bool F_92 ( struct V_86 * V_51 ,
struct V_32 * V_33 ,
struct V_95 * V_62 )
{
struct V_47 * V_30 = V_51 -> V_87 , * V_198 ;
bool V_199 = false ;
struct V_64 * V_65 = (struct V_64 * ) V_33 -> V_30 ;
struct V_98 * V_99 = F_58 ( V_33 ) ;
struct V_200 V_201 ;
T_3 V_84 ;
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
V_201 . V_196 |= V_202 ;
V_201 . V_203 = V_62 -> V_118 ;
V_201 . V_204 = V_62 -> V_204 ;
if ( V_99 -> V_205 . V_174 [ 0 ] . V_97 & V_206 ) {
V_201 . V_207 =
F_93 ( & V_99 -> V_205 . V_174 [ 0 ] ) ;
V_201 . V_208 =
F_94 ( & V_99 -> V_205 . V_174 [ 0 ] ) ;
V_201 . V_209 = V_210 ;
} else {
V_201 . V_207 = V_99 -> V_205 . V_174 [ 0 ] . V_172 ;
if ( V_99 -> V_205 . V_174 [ 0 ] . V_97 & V_211 )
V_201 . V_209 = V_212 ;
}
if ( V_99 -> V_205 . V_174 [ 0 ] . V_97 & V_213 )
V_201 . V_214 = V_215 ;
else if ( V_99 -> V_205 . V_174 [ 0 ] . V_97 & V_216 )
V_201 . V_214 = V_217 ;
else if ( V_99 -> V_205 . V_174 [ 0 ] . V_97 & V_218 )
V_201 . V_214 = V_219 ;
else
V_201 . V_214 = V_220 ;
if ( V_99 -> V_205 . V_174 [ 0 ] . V_97 & V_221 )
V_201 . V_222 |= V_223 ;
V_201 . signal = - 50 ;
if ( V_99 -> V_205 . V_2 )
V_201 . signal += V_99 -> V_205 . V_2 -> V_224 . V_225 ;
if ( V_30 -> V_63 != V_74 )
V_65 -> V_54 |= F_29 ( V_57 ) ;
F_95 ( V_33 ) ;
F_96 ( V_33 ) ;
V_33 -> V_226 = 0 ;
F_97 ( V_33 ) ;
F_98 ( V_33 ) ;
if ( F_99 ( V_65 -> V_54 ) ||
F_100 ( V_65 -> V_54 ) )
V_84 = V_30 -> V_227 ;
else
V_84 = F_48 () ;
F_101 ( & V_228 ) ;
F_102 (data2, &hwsim_radios, list) {
struct V_32 * V_229 ;
struct V_188 V_188 = {
. V_189 = false ,
. V_171 = V_62 ,
} ;
if ( V_30 == V_198 )
continue;
if ( ! V_198 -> V_230 || ( V_198 -> V_231 && ! V_198 -> V_232 ) ||
! F_70 ( V_198 , V_33 ) )
continue;
if ( ! ( V_30 -> V_80 & V_198 -> V_80 ) )
continue;
if ( V_30 -> V_23 != V_198 -> V_23 )
continue;
if ( ! F_86 ( V_62 , V_198 -> V_232 ) &&
! F_86 ( V_62 , V_198 -> V_171 ) ) {
F_40 (
V_198 -> V_51 , V_78 ,
F_87 , & V_188 ) ;
if ( ! V_188 . V_189 )
continue;
}
if ( V_33 -> V_164 < V_233 && V_234 ) {
struct V_235 * V_235 = F_103 ( V_103 ) ;
if ( ! V_235 )
continue;
V_229 = F_27 ( 128 ) ;
if ( ! V_229 ) {
F_104 ( V_235 ) ;
continue;
}
memcpy ( F_105 ( V_235 ) , V_33 -> V_30 , V_33 -> V_164 ) ;
F_106 ( V_229 , 0 , V_235 , 0 , V_33 -> V_164 , V_33 -> V_164 ) ;
} else {
V_229 = F_107 ( V_33 , V_103 ) ;
if ( ! V_229 )
continue;
}
if ( F_69 ( V_198 , V_65 -> V_69 ) )
V_199 = true ;
V_201 . V_236 = V_84 + V_198 -> V_85 ;
memcpy ( F_91 ( V_229 ) , & V_201 , sizeof( V_201 ) ) ;
F_88 ( V_229 ) ;
V_198 -> V_237 ++ ;
V_198 -> V_238 += V_229 -> V_164 ;
F_108 ( V_198 -> V_51 , V_229 ) ;
}
F_109 ( & V_228 ) ;
return V_199 ;
}
static void F_110 ( struct V_86 * V_51 ,
struct V_239 * V_205 ,
struct V_32 * V_33 )
{
struct V_47 * V_30 = V_51 -> V_87 ;
struct V_98 * V_240 = F_58 ( V_33 ) ;
struct V_64 * V_65 = ( void * ) V_33 -> V_30 ;
struct V_15 * V_60 ;
struct V_95 * V_171 ;
bool V_199 ;
T_1 V_241 ;
if ( F_6 ( V_33 -> V_164 < 10 ) ) {
F_77 ( V_51 , V_33 ) ;
return;
}
if ( ! V_30 -> V_242 ) {
V_171 = V_30 -> V_171 ;
} else if ( V_240 -> V_243 == 4 ) {
V_171 = V_30 -> V_232 ;
} else {
V_60 = F_32 ( V_240 -> V_205 . V_2 -> V_60 ) ;
if ( V_60 )
V_171 = V_60 -> V_61 . V_62 ;
else
V_171 = NULL ;
}
if ( F_2 ( ! V_171 , L_8 , V_240 -> V_243 ) ) {
F_77 ( V_51 , V_33 ) ;
return;
}
if ( V_30 -> V_231 && ! V_30 -> V_232 ) {
F_20 ( V_51 -> V_27 , L_9 ) ;
F_77 ( V_51 , V_33 ) ;
return;
}
if ( V_240 -> V_205 . V_2 )
F_1 ( V_240 -> V_205 . V_2 ) ;
if ( V_205 -> V_11 )
F_5 ( V_205 -> V_11 ) ;
if ( F_111 ( V_51 , V_244 ) )
F_112 ( V_240 -> V_205 . V_2 , V_205 -> V_11 , V_33 ,
V_240 -> V_205 . V_174 ,
F_113 ( V_240 -> V_205 . V_174 ) ) ;
V_240 -> V_178 [ 0 ] = V_171 ;
if ( V_33 -> V_164 >= 24 + 8 &&
F_100 ( V_65 -> V_54 ) ) {
struct V_245 * V_246 ;
struct V_100 * V_101 ;
T_3 V_247 ;
V_246 = (struct V_245 * ) V_33 -> V_30 ;
V_101 = F_59 ( V_51 , V_240 ) ;
V_247 = F_48 () ;
V_246 -> V_248 . V_249 . V_250 =
F_52 ( V_247 + V_30 -> V_85 +
24 * 8 * 10 / V_101 -> V_116 ) ;
}
F_57 ( V_51 , V_33 , V_171 ) ;
V_241 = F_114 ( V_30 -> V_25 ) ;
if ( V_241 )
return F_75 ( V_51 , V_33 , V_241 ) ;
V_30 -> V_182 ++ ;
V_30 -> V_183 += V_33 -> V_164 ;
V_199 = F_92 ( V_51 , V_33 , V_171 ) ;
if ( V_199 && V_33 -> V_164 >= 16 )
F_67 ( V_171 , V_65 -> V_70 ) ;
F_115 ( V_240 ) ;
V_240 -> V_205 . V_174 [ 0 ] . V_175 = 1 ;
V_240 -> V_205 . V_174 [ 1 ] . V_172 = - 1 ;
if ( ! ( V_240 -> V_97 & V_167 ) && V_199 )
V_240 -> V_97 |= V_251 ;
F_116 ( V_51 , V_33 ) ;
}
static int F_117 ( struct V_86 * V_51 )
{
struct V_47 * V_30 = V_51 -> V_87 ;
F_20 ( V_51 -> V_27 , L_10 , V_42 ) ;
V_30 -> V_230 = true ;
return 0 ;
}
static void F_118 ( struct V_86 * V_51 )
{
struct V_47 * V_30 = V_51 -> V_87 ;
V_30 -> V_230 = false ;
F_119 ( & V_30 -> V_252 ) ;
F_20 ( V_51 -> V_27 , L_10 , V_42 ) ;
}
static int F_120 ( struct V_86 * V_51 ,
struct V_1 * V_2 )
{
F_20 ( V_51 -> V_27 , L_11 ,
V_42 , F_121 ( V_2 ) ,
V_2 -> V_8 ) ;
F_3 ( V_2 ) ;
V_2 -> V_253 = 0 ;
V_2 -> V_243 [ V_254 ] = 0 ;
V_2 -> V_243 [ V_255 ] = 1 ;
V_2 -> V_243 [ V_256 ] = 2 ;
V_2 -> V_243 [ V_257 ] = 3 ;
return 0 ;
}
static int F_122 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
enum V_258 V_259 ,
bool V_260 )
{
V_259 = F_123 ( V_259 , V_260 ) ;
F_20 ( V_51 -> V_27 ,
L_12 ,
V_42 , F_121 ( V_2 ) ,
V_259 , V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
V_2 -> V_253 = 0 ;
return 0 ;
}
static void F_124 (
struct V_86 * V_51 , struct V_1 * V_2 )
{
F_20 ( V_51 -> V_27 , L_11 ,
V_42 , F_121 ( V_2 ) ,
V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
}
static void F_31 ( struct V_86 * V_51 ,
struct V_32 * V_33 ,
struct V_95 * V_62 )
{
struct V_47 * V_30 = V_51 -> V_87 ;
T_1 V_261 = F_114 ( V_30 -> V_25 ) ;
if ( F_111 ( V_51 , V_244 ) ) {
struct V_98 * V_240 = F_58 ( V_33 ) ;
F_112 ( V_240 -> V_205 . V_2 , NULL , V_33 ,
V_240 -> V_205 . V_174 ,
F_113 ( V_240 -> V_205 . V_174 ) ) ;
}
F_57 ( V_51 , V_33 , V_62 ) ;
if ( V_261 )
return F_75 ( V_51 , V_33 , V_261 ) ;
F_92 ( V_51 , V_33 , V_62 ) ;
F_47 ( V_33 ) ;
}
static void F_125 ( void * V_262 , T_2 * V_46 ,
struct V_1 * V_2 )
{
struct V_47 * V_30 = V_262 ;
struct V_86 * V_51 = V_30 -> V_51 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_245 * V_246 ;
struct V_32 * V_33 ;
F_1 ( V_2 ) ;
if ( V_2 -> type != V_263 &&
V_2 -> type != V_264 &&
V_2 -> type != V_265 )
return;
V_33 = F_126 ( V_51 , V_2 ) ;
if ( V_33 == NULL )
return;
V_99 = F_58 ( V_33 ) ;
if ( F_111 ( V_51 , V_244 ) )
F_112 ( V_2 , NULL , V_33 ,
V_99 -> V_205 . V_174 ,
F_113 ( V_99 -> V_205 . V_174 ) ) ;
V_101 = F_59 ( V_51 , V_99 ) ;
V_246 = (struct V_245 * ) V_33 -> V_30 ;
V_30 -> V_227 = F_48 () ;
V_246 -> V_248 . V_266 . V_250 = F_52 ( V_30 -> V_227 +
V_30 -> V_85 +
24 * 8 * 10 / V_101 -> V_116 ) ;
F_31 ( V_51 , V_33 ,
F_32 ( V_2 -> V_60 ) -> V_61 . V_62 ) ;
if ( V_2 -> V_267 && F_127 ( V_2 ) )
F_128 ( V_2 ) ;
}
static enum V_268
F_129 ( struct V_269 * V_270 )
{
struct V_47 * V_30 =
F_130 ( V_270 , struct V_47 ,
V_252 . V_270 ) ;
struct V_86 * V_51 = V_30 -> V_51 ;
T_3 V_89 = V_30 -> V_90 ;
T_8 V_271 ;
if ( ! V_30 -> V_230 )
goto V_272;
F_40 (
V_51 , V_78 ,
F_125 , V_30 ) ;
if ( V_30 -> V_92 ) {
V_89 -= V_30 -> V_92 ;
V_30 -> V_92 = 0 ;
}
V_271 = F_131 ( F_132 ( V_270 ) ,
F_133 ( V_89 * 1000 ) ) ;
F_134 ( & V_30 -> V_252 , V_271 , V_273 ) ;
V_272:
return V_274 ;
}
static int F_135 ( struct V_86 * V_51 , T_1 V_275 )
{
struct V_47 * V_30 = V_51 -> V_87 ;
struct V_276 * V_277 = & V_51 -> V_277 ;
static const char * V_278 [ V_279 ] = {
[ V_280 ] = L_13 ,
[ V_281 ] = L_14 ,
[ V_282 ] = L_15 ,
[ V_283 ] = L_16 ,
} ;
int V_172 ;
if ( V_277 -> V_284 . V_62 )
F_20 ( V_51 -> V_27 ,
L_17 ,
V_42 ,
V_277 -> V_284 . V_62 -> V_118 ,
V_277 -> V_284 . V_285 ,
V_277 -> V_284 . V_286 ,
V_287 [ V_277 -> V_284 . V_288 ] ,
! ! ( V_277 -> V_97 & V_289 ) ,
! ! ( V_277 -> V_97 & V_290 ) ,
V_278 [ V_277 -> V_291 ] ) ;
else
F_20 ( V_51 -> V_27 ,
L_18 ,
V_42 ,
! ! ( V_277 -> V_97 & V_289 ) ,
! ! ( V_277 -> V_97 & V_290 ) ,
V_278 [ V_277 -> V_291 ] ) ;
V_30 -> V_231 = ! ! ( V_277 -> V_97 & V_289 ) ;
F_6 ( V_277 -> V_284 . V_62 && V_30 -> V_242 ) ;
F_136 ( & V_30 -> V_292 ) ;
if ( V_30 -> V_138 && V_277 -> V_284 . V_62 ) {
for ( V_172 = 0 ; V_172 < F_113 ( V_30 -> V_293 ) ; V_172 ++ ) {
if ( V_30 -> V_293 [ V_172 ] . V_171 == V_30 -> V_171 ) {
V_30 -> V_293 [ V_172 ] . V_294 =
V_30 -> V_293 [ V_172 ] . V_295 ;
V_30 -> V_293 [ V_172 ] . V_296 = V_297 ;
break;
}
}
V_30 -> V_171 = V_277 -> V_284 . V_62 ;
for ( V_172 = 0 ; V_172 < F_113 ( V_30 -> V_293 ) ; V_172 ++ ) {
if ( V_30 -> V_293 [ V_172 ] . V_171 &&
V_30 -> V_293 [ V_172 ] . V_171 != V_30 -> V_171 )
continue;
V_30 -> V_293 [ V_172 ] . V_171 = V_30 -> V_171 ;
V_30 -> V_293 [ V_172 ] . V_295 = V_297 ;
break;
}
} else {
V_30 -> V_171 = V_277 -> V_284 . V_62 ;
}
F_137 ( & V_30 -> V_292 ) ;
if ( ! V_30 -> V_230 || ! V_30 -> V_90 )
F_119 ( & V_30 -> V_252 ) ;
else if ( ! F_138 ( & V_30 -> V_252 . V_270 ) ) {
T_3 V_88 = F_53 ( V_51 , NULL ) ;
T_1 V_89 = V_30 -> V_90 ;
T_3 V_298 = V_89 - F_56 ( V_88 , V_89 ) ;
F_134 ( & V_30 -> V_252 ,
F_133 ( V_298 * 1000 ) ,
V_299 ) ;
}
return 0 ;
}
static void F_139 ( struct V_86 * V_51 ,
unsigned int V_300 ,
unsigned int * V_301 , T_3 V_302 )
{
struct V_47 * V_30 = V_51 -> V_87 ;
F_20 ( V_51 -> V_27 , L_10 , V_42 ) ;
V_30 -> V_303 = 0 ;
if ( * V_301 & V_304 )
V_30 -> V_303 |= V_304 ;
* V_301 = V_30 -> V_303 ;
}
static void F_140 ( void * V_30 , T_2 * V_46 ,
struct V_1 * V_2 )
{
unsigned int * V_175 = V_30 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
if ( V_4 -> V_305 )
( * V_175 ) ++ ;
}
static void F_141 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_306 * V_99 ,
T_1 V_275 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_47 * V_30 = V_51 -> V_87 ;
F_1 ( V_2 ) ;
F_20 ( V_51 -> V_27 , L_19 ,
V_42 , V_275 , V_2 -> V_8 ) ;
if ( V_275 & V_307 ) {
F_20 ( V_51 -> V_27 , L_20 ,
V_42 , V_99 -> V_52 ) ;
memcpy ( V_4 -> V_52 , V_99 -> V_52 , V_58 ) ;
}
if ( V_275 & V_308 ) {
F_20 ( V_51 -> V_27 , L_21 ,
V_99 -> V_50 , V_99 -> V_53 ) ;
V_4 -> V_50 = V_99 -> V_50 ;
V_4 -> V_53 = V_99 -> V_53 ;
}
if ( V_275 & V_309 ) {
F_20 ( V_51 -> V_27 , L_22 ,
V_99 -> V_310 , V_99 -> V_90 ) ;
V_4 -> V_305 = V_99 -> V_310 ;
if ( V_30 -> V_230 &&
! F_138 ( & V_30 -> V_252 . V_270 ) &&
V_99 -> V_310 ) {
T_3 V_88 , V_298 ;
T_1 V_89 ;
V_30 -> V_90 = V_99 -> V_90 * 1024 ;
V_88 = F_53 ( V_51 , V_2 ) ;
V_89 = V_30 -> V_90 ;
V_298 = V_89 - F_56 ( V_88 , V_89 ) ;
F_134 ( & V_30 -> V_252 ,
F_133 ( V_298 * 1000 ) ,
V_299 ) ;
} else if ( ! V_99 -> V_310 ) {
unsigned int V_175 = 0 ;
F_40 (
V_30 -> V_51 , V_78 ,
F_140 , & V_175 ) ;
F_20 ( V_51 -> V_27 , L_23 ,
V_175 ) ;
if ( V_175 == 0 ) {
F_119 ( & V_30 -> V_252 ) ;
V_30 -> V_90 = 0 ;
}
}
}
if ( V_275 & V_311 ) {
F_20 ( V_51 -> V_27 , L_24 ,
V_99 -> V_312 ) ;
}
if ( V_275 & V_313 ) {
F_20 ( V_51 -> V_27 , L_25 ,
V_99 -> V_314 ) ;
}
if ( V_275 & V_315 ) {
F_20 ( V_51 -> V_27 , L_26 , V_99 -> V_316 ) ;
}
if ( V_275 & V_317 ) {
F_20 ( V_51 -> V_27 , L_27 ,
V_99 -> V_318 ) ;
}
if ( V_275 & V_319 ) {
F_20 ( V_51 -> V_27 , L_28 ,
( unsigned long long ) V_99 -> V_320 ) ;
}
if ( V_275 & V_321 )
F_20 ( V_51 -> V_27 , L_29 , V_99 -> V_225 ) ;
}
static int F_142 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_7 ( V_11 ) ;
return 0 ;
}
static int F_143 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static void F_144 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
enum V_322 V_323 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
switch ( V_323 ) {
case V_324 :
case V_325 :
break;
default:
F_2 ( 1 , L_30 , V_323 ) ;
break;
}
}
static int F_145 ( struct V_86 * V_51 ,
struct V_10 * V_11 ,
bool V_326 )
{
F_5 ( V_11 ) ;
return 0 ;
}
static int F_146 (
struct V_86 * V_51 ,
struct V_1 * V_2 , T_6 V_327 ,
const struct V_328 * V_329 )
{
F_20 ( V_51 -> V_27 ,
L_31 ,
V_42 , V_327 ,
V_329 -> V_330 , V_329 -> V_331 ,
V_329 -> V_332 , V_329 -> V_333 ) ;
return 0 ;
}
static int F_147 ( struct V_86 * V_51 , int V_172 ,
struct V_334 * V_335 )
{
struct V_47 * V_336 = V_51 -> V_87 ;
if ( V_172 < 0 || V_172 >= F_113 ( V_336 -> V_293 ) )
return - V_142 ;
F_136 ( & V_336 -> V_292 ) ;
V_335 -> V_171 = V_336 -> V_293 [ V_172 ] . V_171 ;
if ( ! V_335 -> V_171 ) {
F_137 ( & V_336 -> V_292 ) ;
return - V_142 ;
}
V_335 -> V_337 = V_338 |
V_339 |
V_340 ;
V_335 -> V_341 = - 92 ;
V_335 -> time =
F_148 ( V_336 -> V_293 [ V_172 ] . V_296 -
V_336 -> V_293 [ V_172 ] . V_294 ) ;
V_335 -> V_342 = V_335 -> time / 8 ;
F_137 ( & V_336 -> V_292 ) ;
return 0 ;
}
static int F_149 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
void * V_30 , int V_164 )
{
struct V_47 * V_336 = V_51 -> V_87 ;
struct V_34 * V_35 [ V_343 + 1 ] ;
struct V_32 * V_33 ;
int V_37 , V_63 ;
V_37 = F_18 ( V_35 , V_343 , V_30 , V_164 ,
V_344 , NULL ) ;
if ( V_37 )
return V_37 ;
if ( ! V_35 [ V_345 ] )
return - V_41 ;
switch ( F_19 ( V_35 [ V_345 ] ) ) {
case V_346 :
if ( ! V_35 [ V_347 ] )
return - V_41 ;
V_63 = F_19 ( V_35 [ V_347 ] ) ;
return F_38 ( V_336 , V_63 ) ;
case V_348 :
V_33 = F_150 ( V_51 -> V_27 ,
F_151 ( sizeof( T_1 ) ) ) ;
if ( ! V_33 )
return - V_44 ;
if ( F_22 ( V_33 , V_347 , V_336 -> V_63 ) )
goto V_157;
return F_152 ( V_33 ) ;
case V_349 :
F_153 ( V_51 ) ;
return 0 ;
case V_350 :
F_154 ( V_51 ) ;
return 0 ;
default:
return - V_351 ;
}
V_157:
F_155 ( V_33 ) ;
return - V_352 ;
}
static int F_156 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_353 * V_329 )
{
struct V_10 * V_11 = V_329 -> V_11 ;
enum V_354 V_355 = V_329 -> V_355 ;
T_6 V_356 = V_329 -> V_356 ;
switch ( V_355 ) {
case V_357 :
F_157 ( V_2 , V_11 -> V_8 , V_356 ) ;
break;
case V_358 :
case V_359 :
case V_360 :
F_158 ( V_2 , V_11 -> V_8 , V_356 ) ;
break;
case V_361 :
break;
case V_362 :
case V_363 :
break;
default:
return - V_351 ;
}
return 0 ;
}
static void F_159 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
T_1 V_364 , bool V_365 )
{
}
static void F_160 ( struct V_366 * V_367 )
{
struct V_47 * V_336 =
F_130 ( V_367 , struct V_47 , V_368 . V_367 ) ;
struct V_369 * V_370 = V_336 -> V_371 ;
int V_372 , V_147 ;
F_136 ( & V_336 -> V_292 ) ;
if ( V_336 -> V_373 >= V_370 -> V_374 ) {
struct V_375 V_99 = {
. V_376 = false ,
} ;
F_20 ( V_336 -> V_51 -> V_27 , L_32 ) ;
F_161 ( V_336 -> V_51 , & V_99 ) ;
V_336 -> V_371 = NULL ;
V_336 -> V_377 = NULL ;
V_336 -> V_232 = NULL ;
F_137 ( & V_336 -> V_292 ) ;
return;
}
F_20 ( V_336 -> V_51 -> V_27 , L_33 ,
V_370 -> V_378 [ V_336 -> V_373 ] -> V_118 ) ;
V_336 -> V_232 = V_370 -> V_378 [ V_336 -> V_373 ] ;
if ( V_336 -> V_232 -> V_97 & ( V_379 |
V_380 ) ||
! V_370 -> V_381 ) {
V_372 = 120 ;
} else {
V_372 = 30 ;
for ( V_147 = 0 ; V_147 < V_370 -> V_381 ; V_147 ++ ) {
struct V_32 * V_382 ;
struct V_245 * V_246 ;
V_382 = F_162 ( V_336 -> V_51 ,
V_336 -> V_139 ,
V_370 -> V_383 [ V_147 ] . V_384 ,
V_370 -> V_383 [ V_147 ] . V_385 ,
V_370 -> V_386 ) ;
if ( ! V_382 )
continue;
V_246 = (struct V_245 * ) V_382 -> V_30 ;
memcpy ( V_246 -> V_387 , V_370 -> V_52 , V_58 ) ;
memcpy ( V_246 -> V_52 , V_370 -> V_52 , V_58 ) ;
if ( V_370 -> V_386 )
F_163 ( V_382 , V_370 -> V_388 , V_370 -> V_386 ) ;
F_39 () ;
F_31 ( V_336 -> V_51 , V_382 ,
V_336 -> V_232 ) ;
F_41 () ;
}
}
F_164 ( V_336 -> V_51 , & V_336 -> V_368 ,
F_165 ( V_372 ) ) ;
V_336 -> V_293 [ V_336 -> V_373 ] . V_171 = V_336 -> V_232 ;
V_336 -> V_293 [ V_336 -> V_373 ] . V_294 = V_297 ;
V_336 -> V_293 [ V_336 -> V_373 ] . V_296 =
V_297 + F_165 ( V_372 ) ;
V_336 -> V_373 ++ ;
F_137 ( & V_336 -> V_292 ) ;
}
static int F_166 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_389 * V_390 )
{
struct V_47 * V_336 = V_51 -> V_87 ;
struct V_369 * V_370 = & V_390 -> V_370 ;
F_136 ( & V_336 -> V_292 ) ;
if ( F_6 ( V_336 -> V_232 || V_336 -> V_371 ) ) {
F_137 ( & V_336 -> V_292 ) ;
return - V_391 ;
}
V_336 -> V_371 = V_370 ;
V_336 -> V_377 = V_2 ;
V_336 -> V_373 = 0 ;
if ( V_370 -> V_97 & V_392 )
F_167 ( V_336 -> V_139 ,
V_390 -> V_370 . V_393 ,
V_390 -> V_370 . V_394 ) ;
else
memcpy ( V_336 -> V_139 , V_2 -> V_8 , V_58 ) ;
memset ( V_336 -> V_293 , 0 , sizeof( V_336 -> V_293 ) ) ;
F_137 ( & V_336 -> V_292 ) ;
F_20 ( V_51 -> V_27 , L_34 ) ;
F_164 ( V_336 -> V_51 , & V_336 -> V_368 , 0 ) ;
return 0 ;
}
static void F_168 ( struct V_86 * V_51 ,
struct V_1 * V_2 )
{
struct V_47 * V_336 = V_51 -> V_87 ;
struct V_375 V_99 = {
. V_376 = true ,
} ;
F_20 ( V_51 -> V_27 , L_35 ) ;
F_169 ( & V_336 -> V_368 ) ;
F_136 ( & V_336 -> V_292 ) ;
F_161 ( V_336 -> V_51 , & V_99 ) ;
V_336 -> V_232 = NULL ;
V_336 -> V_371 = NULL ;
V_336 -> V_377 = NULL ;
F_137 ( & V_336 -> V_292 ) ;
}
static void F_170 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
const T_2 * V_393 )
{
struct V_47 * V_336 = V_51 -> V_87 ;
F_136 ( & V_336 -> V_292 ) ;
if ( V_336 -> V_138 ) {
F_81 ( V_160 L_36 ) ;
goto V_272;
}
F_81 ( V_160 L_37 ) ;
memcpy ( V_336 -> V_139 , V_393 , V_58 ) ;
V_336 -> V_138 = true ;
memset ( V_336 -> V_293 , 0 , sizeof( V_336 -> V_293 ) ) ;
V_272:
F_137 ( & V_336 -> V_292 ) ;
}
static void F_171 ( struct V_86 * V_51 ,
struct V_1 * V_2 )
{
struct V_47 * V_336 = V_51 -> V_87 ;
F_136 ( & V_336 -> V_292 ) ;
F_81 ( V_160 L_38 ) ;
V_336 -> V_138 = false ;
F_172 ( V_336 -> V_139 ) ;
F_137 ( & V_336 -> V_292 ) ;
}
static void F_173 ( struct V_366 * V_367 )
{
struct V_47 * V_336 =
F_130 ( V_367 , struct V_47 , V_395 . V_367 ) ;
F_136 ( & V_336 -> V_292 ) ;
F_20 ( V_336 -> V_51 -> V_27 , L_39 ) ;
V_336 -> V_232 = V_336 -> V_396 ;
F_174 ( V_336 -> V_51 ) ;
F_164 ( V_336 -> V_51 , & V_336 -> V_397 ,
F_165 ( V_336 -> V_398 ) ) ;
F_137 ( & V_336 -> V_292 ) ;
}
static void F_175 ( struct V_366 * V_367 )
{
struct V_47 * V_336 =
F_130 ( V_367 , struct V_47 , V_397 . V_367 ) ;
F_136 ( & V_336 -> V_292 ) ;
F_176 ( V_336 -> V_51 ) ;
V_336 -> V_232 = NULL ;
F_137 ( & V_336 -> V_292 ) ;
F_20 ( V_336 -> V_51 -> V_27 , L_40 ) ;
}
static int F_177 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_95 * V_62 ,
int V_399 ,
enum V_400 type )
{
struct V_47 * V_336 = V_51 -> V_87 ;
F_136 ( & V_336 -> V_292 ) ;
if ( F_6 ( V_336 -> V_232 || V_336 -> V_371 ) ) {
F_137 ( & V_336 -> V_292 ) ;
return - V_391 ;
}
V_336 -> V_396 = V_62 ;
V_336 -> V_398 = V_399 ;
F_137 ( & V_336 -> V_292 ) ;
F_20 ( V_51 -> V_27 , L_41 ,
V_62 -> V_118 , V_399 ) ;
F_164 ( V_51 , & V_336 -> V_395 , V_401 / 50 ) ;
return 0 ;
}
static int F_178 ( struct V_86 * V_51 )
{
struct V_47 * V_336 = V_51 -> V_87 ;
F_169 ( & V_336 -> V_395 ) ;
F_169 ( & V_336 -> V_397 ) ;
F_136 ( & V_336 -> V_292 ) ;
V_336 -> V_232 = NULL ;
F_137 ( & V_336 -> V_292 ) ;
F_20 ( V_51 -> V_27 , L_42 ) ;
return 0 ;
}
static int F_179 ( struct V_86 * V_51 ,
struct V_15 * V_402 )
{
F_10 ( V_402 ) ;
F_20 ( V_51 -> V_27 ,
L_43 ,
V_402 -> V_61 . V_62 -> V_118 , V_402 -> V_61 . V_288 ,
V_402 -> V_61 . V_285 , V_402 -> V_61 . V_286 ) ;
return 0 ;
}
static void F_180 ( struct V_86 * V_51 ,
struct V_15 * V_402 )
{
F_20 ( V_51 -> V_27 ,
L_44 ,
V_402 -> V_61 . V_62 -> V_118 , V_402 -> V_61 . V_288 ,
V_402 -> V_61 . V_285 , V_402 -> V_61 . V_286 ) ;
F_9 ( V_402 ) ;
F_11 ( V_402 ) ;
}
static void F_181 ( struct V_86 * V_51 ,
struct V_15 * V_402 ,
T_1 V_275 )
{
F_9 ( V_402 ) ;
F_20 ( V_51 -> V_27 ,
L_45 ,
V_402 -> V_61 . V_62 -> V_118 , V_402 -> V_61 . V_288 ,
V_402 -> V_61 . V_285 , V_402 -> V_61 . V_286 ) ;
}
static int F_182 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_15 * V_402 )
{
F_1 ( V_2 ) ;
F_9 ( V_402 ) ;
return 0 ;
}
static void F_183 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_15 * V_402 )
{
F_1 ( V_2 ) ;
F_9 ( V_402 ) ;
}
static void F_184 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
T_1 V_403 , T_2 * V_30 )
{
if ( V_403 == V_404 )
memcpy ( V_30 , * V_405 ,
sizeof( V_405 ) ) ;
}
static int F_185 ( struct V_86 * V_51 ,
struct V_1 * V_2 , int V_403 )
{
if ( V_403 == V_404 )
return V_406 ;
return 0 ;
}
static void F_186 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_407 * V_408 , T_3 * V_30 )
{
struct V_47 * V_409 = V_51 -> V_87 ;
int V_147 = 0 ;
V_30 [ V_147 ++ ] = V_409 -> V_182 ;
V_30 [ V_147 ++ ] = V_409 -> V_183 ;
V_30 [ V_147 ++ ] = V_409 -> V_237 ;
V_30 [ V_147 ++ ] = V_409 -> V_238 ;
V_30 [ V_147 ++ ] = V_409 -> V_155 ;
V_30 [ V_147 ++ ] = V_409 -> V_184 ;
V_30 [ V_147 ++ ] = V_409 -> V_63 ;
V_30 [ V_147 ++ ] = V_409 -> V_80 ;
F_6 ( V_147 != V_406 ) ;
}
static void F_187 ( struct V_32 * V_410 ,
struct V_411 * V_99 )
{
if ( V_99 )
F_188 ( & V_158 , V_410 , V_99 ,
V_412 , V_43 ) ;
else
F_189 ( & V_158 , V_410 , 0 ,
V_412 , V_43 ) ;
}
static int F_190 ( struct V_32 * V_33 , int V_413 ,
struct V_414 * V_415 )
{
int V_137 ;
V_137 = F_22 ( V_33 , V_416 , V_413 ) ;
if ( V_137 < 0 )
return V_137 ;
if ( V_415 -> V_378 ) {
V_137 = F_22 ( V_33 , V_417 , V_415 -> V_378 ) ;
if ( V_137 < 0 )
return V_137 ;
}
if ( V_415 -> V_418 ) {
V_137 = F_82 ( V_33 , V_419 , 2 ,
V_415 -> V_418 ) ;
if ( V_137 < 0 )
return V_137 ;
}
if ( V_415 -> V_420 ) {
int V_147 ;
for ( V_147 = 0 ; V_147 < F_113 ( V_421 ) ; V_147 ++ ) {
if ( V_421 [ V_147 ] != V_415 -> V_420 )
continue;
V_137 = F_22 ( V_33 , V_422 , V_147 ) ;
if ( V_137 < 0 )
return V_137 ;
break;
}
}
if ( V_415 -> V_423 ) {
V_137 = F_191 ( V_33 , V_424 ) ;
if ( V_137 < 0 )
return V_137 ;
}
if ( V_415 -> V_425 ) {
V_137 = F_191 ( V_33 , V_426 ) ;
if ( V_137 < 0 )
return V_137 ;
}
if ( V_415 -> V_242 ) {
V_137 = F_191 ( V_33 , V_427 ) ;
if ( V_137 < 0 )
return V_137 ;
}
if ( V_415 -> V_428 ) {
V_137 = F_82 ( V_33 , V_429 ,
strlen ( V_415 -> V_428 ) , V_415 -> V_428 ) ;
if ( V_137 < 0 )
return V_137 ;
}
return 0 ;
}
static void F_192 ( int V_413 , struct V_411 * V_99 ,
struct V_414 * V_415 )
{
struct V_32 * V_410 ;
void * V_30 ;
V_410 = F_79 ( V_156 , V_43 ) ;
if ( ! V_410 )
return;
V_30 = F_80 ( V_410 , 0 , 0 , & V_158 , 0 ,
V_430 ) ;
if ( ! V_30 )
goto V_431;
if ( F_190 ( V_410 , V_413 , V_415 ) < 0 )
goto V_431;
F_84 ( V_410 , V_30 ) ;
F_187 ( V_410 , V_99 ) ;
return;
V_431:
F_193 ( V_410 , V_30 ) ;
F_74 ( V_410 ) ;
}
static int F_194 ( struct V_411 * V_99 ,
struct V_414 * V_415 )
{
int V_37 ;
T_2 V_8 [ V_58 ] ;
struct V_47 * V_30 ;
struct V_86 * V_51 ;
enum V_432 V_204 ;
const struct V_433 * V_434 = & V_435 ;
struct V_20 * V_20 ;
int V_172 ;
if ( F_6 ( V_415 -> V_378 > 1 && ! V_415 -> V_242 ) )
return - V_41 ;
F_195 ( & V_228 ) ;
V_172 = V_436 ++ ;
F_196 ( & V_228 ) ;
if ( V_415 -> V_242 )
V_434 = & V_437 ;
V_51 = F_197 ( sizeof( * V_30 ) , V_434 , V_415 -> V_428 ) ;
if ( ! V_51 ) {
F_81 ( V_160 L_46 ) ;
V_37 = - V_44 ;
goto V_438;
}
V_415 -> V_428 = F_198 ( V_51 -> V_27 ) ;
if ( V_99 )
V_20 = F_199 ( V_99 ) ;
else
V_20 = & V_439 ;
F_200 ( V_51 -> V_27 , V_20 ) ;
V_30 = V_51 -> V_87 ;
V_30 -> V_51 = V_51 ;
V_30 -> V_82 = F_201 ( V_440 , NULL , 0 , V_51 , L_47 , V_172 ) ;
if ( F_202 ( V_30 -> V_82 ) ) {
F_81 ( V_160
L_48 ,
F_203 ( V_30 -> V_82 ) ) ;
V_37 = - V_44 ;
goto V_441;
}
V_30 -> V_82 -> V_442 = & V_443 . V_442 ;
V_37 = F_204 ( V_30 -> V_82 ) ;
if ( V_37 != 0 ) {
F_81 ( V_160 L_49 ,
V_37 ) ;
goto V_444;
}
F_205 ( & V_30 -> V_152 ) ;
F_206 ( V_51 , V_30 -> V_82 ) ;
F_172 ( V_8 ) ;
V_8 [ 0 ] = 0x02 ;
V_8 [ 3 ] = V_172 >> 8 ;
V_8 [ 4 ] = V_172 ;
memcpy ( V_30 -> V_162 [ 0 ] . V_8 , V_8 , V_58 ) ;
memcpy ( V_30 -> V_162 [ 1 ] . V_8 , V_8 , V_58 ) ;
V_30 -> V_162 [ 1 ] . V_8 [ 0 ] |= 0x40 ;
V_51 -> V_27 -> V_445 = 2 ;
V_51 -> V_27 -> V_162 = V_30 -> V_162 ;
V_30 -> V_378 = V_415 -> V_378 ;
V_30 -> V_242 = V_415 -> V_242 ;
V_30 -> V_172 = V_172 ;
V_30 -> V_446 = V_415 -> V_446 ;
if ( V_99 )
V_30 -> V_26 = V_99 -> V_447 ;
if ( V_30 -> V_242 ) {
V_51 -> V_27 -> V_448 = 255 ;
V_51 -> V_27 -> V_449 = V_450 ;
V_51 -> V_27 -> V_451 = 1000 ;
V_51 -> V_27 -> V_452 = & V_30 -> V_453 ;
if ( V_415 -> V_425 )
V_30 -> V_453 = V_454 [ 0 ] ;
else
V_30 -> V_453 = V_455 [ 0 ] ;
V_51 -> V_27 -> V_456 = 1 ;
V_30 -> V_453 . V_457 = 0 ;
V_30 -> V_453 . V_458 = V_30 -> V_378 ;
} else if ( V_415 -> V_425 ) {
V_51 -> V_27 -> V_452 = V_454 ;
V_51 -> V_27 -> V_456 =
F_113 ( V_454 ) ;
} else {
V_51 -> V_27 -> V_452 = V_455 ;
V_51 -> V_27 -> V_456 = F_113 ( V_455 ) ;
}
F_207 ( & V_30 -> V_395 , F_173 ) ;
F_207 ( & V_30 -> V_397 , F_175 ) ;
F_207 ( & V_30 -> V_368 , F_160 ) ;
V_51 -> V_364 = 5 ;
V_51 -> V_459 = 4 ;
V_51 -> V_27 -> V_460 = F_90 ( V_461 ) |
F_90 ( V_263 ) |
F_90 ( V_462 ) |
F_90 ( V_463 ) |
F_90 ( V_265 ) |
F_90 ( V_264 ) ;
if ( V_415 -> V_425 )
V_51 -> V_27 -> V_460 |= F_90 ( V_464 ) ;
F_208 ( V_51 , V_465 ) ;
F_208 ( V_51 , V_466 ) ;
F_208 ( V_51 , V_467 ) ;
F_208 ( V_51 , V_468 ) ;
F_208 ( V_51 , V_469 ) ;
F_208 ( V_51 , V_470 ) ;
F_208 ( V_51 , V_471 ) ;
F_208 ( V_51 , V_472 ) ;
F_208 ( V_51 , V_473 ) ;
if ( V_474 )
F_208 ( V_51 , V_244 ) ;
V_51 -> V_27 -> V_97 |= V_475 |
V_476 |
V_477 |
V_478 ;
V_51 -> V_27 -> V_479 |= V_480 |
V_481 |
V_482 |
V_483 |
V_484 ;
F_209 ( V_51 -> V_27 , V_485 ) ;
V_51 -> V_486 = sizeof( struct V_3 ) ;
V_51 -> V_487 = sizeof( struct V_12 ) ;
V_51 -> V_488 = sizeof( struct V_17 ) ;
memcpy ( V_30 -> V_489 , V_490 ,
sizeof( V_490 ) ) ;
memcpy ( V_30 -> V_491 , V_492 ,
sizeof( V_492 ) ) ;
memcpy ( V_30 -> V_174 , V_493 , sizeof( V_493 ) ) ;
for ( V_204 = V_494 ; V_204 < V_495 ; V_204 ++ ) {
struct V_496 * V_497 = & V_30 -> V_498 [ V_204 ] ;
switch ( V_204 ) {
case V_494 :
V_497 -> V_378 = V_30 -> V_489 ;
V_497 -> V_374 = F_113 ( V_490 ) ;
V_497 -> V_499 = V_30 -> V_174 ;
V_497 -> V_500 = F_113 ( V_493 ) ;
break;
case V_501 :
V_497 -> V_378 = V_30 -> V_491 ;
V_497 -> V_374 = F_113 ( V_492 ) ;
V_497 -> V_499 = V_30 -> V_174 + 4 ;
V_497 -> V_500 = F_113 ( V_493 ) - 4 ;
V_497 -> V_502 . V_503 = true ;
V_497 -> V_502 . V_504 =
V_505 |
V_506 |
V_507 |
V_508 |
V_509 |
V_510 |
V_511 |
V_512 |
V_513 |
V_514 |
V_515 ;
V_497 -> V_502 . V_516 . V_517 =
F_29 ( V_518 << 0 |
V_518 << 2 |
V_518 << 4 |
V_518 << 6 |
V_518 << 8 |
V_518 << 10 |
V_518 << 12 |
V_518 << 14 ) ;
V_497 -> V_502 . V_516 . V_519 =
V_497 -> V_502 . V_516 . V_517 ;
break;
default:
continue;
}
V_497 -> V_520 . V_521 = true ;
V_497 -> V_520 . V_504 = V_522 |
V_523 |
V_524 |
V_525 |
V_526 ;
V_497 -> V_520 . V_527 = 0x3 ;
V_497 -> V_520 . V_528 = 0x6 ;
memset ( & V_497 -> V_520 . V_529 , 0 ,
sizeof( V_497 -> V_520 . V_529 ) ) ;
V_497 -> V_520 . V_529 . V_530 [ 0 ] = 0xff ;
V_497 -> V_520 . V_529 . V_530 [ 1 ] = 0xff ;
V_497 -> V_520 . V_529 . V_531 = V_532 ;
V_51 -> V_27 -> V_498 [ V_204 ] = V_497 ;
}
V_30 -> V_80 = 1 ;
F_210 ( & V_30 -> V_292 ) ;
V_30 -> V_23 = F_12 ( V_20 ) ;
V_51 -> V_533 = 4 ;
V_51 -> V_534 = 11 ;
V_51 -> V_27 -> V_535 = V_536 ;
V_51 -> V_27 -> V_537 =
F_113 ( V_536 ) ;
V_51 -> V_27 -> V_538 = V_539 ;
V_51 -> V_27 -> V_540 = F_113 ( V_539 ) ;
if ( V_415 -> V_423 )
V_51 -> V_27 -> V_541 |= V_542 ;
if ( V_415 -> V_420 ) {
V_30 -> V_420 = V_415 -> V_420 ;
V_51 -> V_27 -> V_541 |= V_543 ;
F_211 ( V_51 -> V_27 , V_415 -> V_420 ) ;
F_212 ( 1 ) ;
}
if ( V_415 -> V_544 )
F_208 ( V_51 , V_545 ) ;
F_209 ( V_51 -> V_27 , V_546 ) ;
V_37 = F_213 ( V_51 ) ;
if ( V_37 < 0 ) {
F_81 ( V_160 L_50 ,
V_37 ) ;
goto V_547;
}
F_20 ( V_51 -> V_27 , L_51 , V_51 -> V_27 -> V_548 ) ;
if ( V_415 -> V_418 ) {
V_30 -> V_549 [ 0 ] = V_415 -> V_418 [ 0 ] ;
V_30 -> V_549 [ 1 ] = V_415 -> V_418 [ 1 ] ;
F_214 ( V_51 -> V_27 , V_415 -> V_418 ) ;
}
V_30 -> V_550 = F_215 ( L_52 , V_51 -> V_27 -> V_551 ) ;
F_216 ( L_53 , 0666 , V_30 -> V_550 , V_30 , & V_552 ) ;
F_216 ( L_54 , 0666 , V_30 -> V_550 , V_30 ,
& V_553 ) ;
if ( ! V_30 -> V_242 )
F_216 ( L_55 , 0222 ,
V_30 -> V_550 ,
V_30 , & V_554 ) ;
F_217 ( & V_30 -> V_252 ,
F_129 ,
V_555 , V_273 ) ;
F_195 ( & V_228 ) ;
F_218 ( & V_30 -> V_556 , & V_557 ) ;
F_196 ( & V_228 ) ;
if ( V_172 > 0 )
F_192 ( V_172 , V_99 , V_415 ) ;
return V_172 ;
V_547:
F_219 ( V_30 -> V_82 ) ;
V_444:
F_220 ( V_30 -> V_82 ) ;
V_441:
F_221 ( V_51 ) ;
V_438:
return V_37 ;
}
static void F_222 ( int V_413 , const char * V_428 ,
struct V_411 * V_99 )
{
struct V_32 * V_33 ;
void * V_30 ;
int V_137 ;
V_33 = F_79 ( V_156 , V_43 ) ;
if ( ! V_33 )
return;
V_30 = F_80 ( V_33 , 0 , 0 , & V_158 , 0 ,
V_558 ) ;
if ( ! V_30 )
goto error;
V_137 = F_22 ( V_33 , V_416 , V_413 ) ;
if ( V_137 < 0 )
goto error;
V_137 = F_82 ( V_33 , V_429 , strlen ( V_428 ) ,
V_428 ) ;
if ( V_137 < 0 )
goto error;
F_84 ( V_33 , V_30 ) ;
F_187 ( V_33 , V_99 ) ;
return;
error:
F_74 ( V_33 ) ;
}
static void F_223 ( struct V_47 * V_30 ,
const char * V_428 ,
struct V_411 * V_99 )
{
F_222 ( V_30 -> V_172 , V_428 , V_99 ) ;
F_224 ( V_30 -> V_550 ) ;
F_225 ( V_30 -> V_51 ) ;
F_219 ( V_30 -> V_82 ) ;
F_220 ( V_30 -> V_82 ) ;
F_221 ( V_30 -> V_51 ) ;
}
static int F_226 ( struct V_32 * V_33 ,
struct V_47 * V_30 ,
T_1 V_26 , T_1 V_559 ,
struct V_560 * V_130 , int V_97 )
{
void * V_65 ;
struct V_414 V_415 = { } ;
int V_141 = - V_561 ;
V_65 = F_80 ( V_33 , V_26 , V_559 , & V_158 , V_97 ,
V_562 ) ;
if ( ! V_65 )
return - V_561 ;
if ( V_130 )
F_227 ( V_130 , V_65 , & V_158 ) ;
if ( V_30 -> V_549 [ 0 ] && V_30 -> V_549 [ 1 ] )
V_415 . V_418 = V_30 -> V_549 ;
V_415 . V_423 = ! ! ( V_30 -> V_51 -> V_27 -> V_541 &
V_542 ) ;
V_415 . V_425 = ! ! ( V_30 -> V_51 -> V_27 -> V_460 &
F_90 ( V_464 ) ) ;
V_415 . V_242 = V_30 -> V_242 ;
V_415 . V_420 = V_30 -> V_420 ;
V_415 . V_378 = V_30 -> V_378 ;
V_415 . V_428 = F_198 ( V_30 -> V_51 -> V_27 ) ;
V_141 = F_190 ( V_33 , V_30 -> V_172 , & V_415 ) ;
if ( V_141 < 0 )
goto V_431;
F_84 ( V_33 , V_65 ) ;
return 0 ;
V_431:
F_193 ( V_33 , V_65 ) ;
return V_141 ;
}
static void F_228 ( void )
{
struct V_47 * V_30 ;
F_195 ( & V_228 ) ;
while ( ( V_30 = F_229 ( & V_557 ,
struct V_47 ,
V_556 ) ) ) {
F_230 ( & V_30 -> V_556 ) ;
F_196 ( & V_228 ) ;
F_223 ( V_30 , F_198 ( V_30 -> V_51 -> V_27 ) ,
NULL ) ;
F_195 ( & V_228 ) ;
}
F_196 ( & V_228 ) ;
F_231 ( V_440 ) ;
}
static void F_232 ( struct V_81 * V_82 )
{
V_82 -> V_563 = & V_564 ;
V_82 -> V_565 = true ;
F_233 ( V_82 ) ;
V_82 -> V_566 |= V_567 ;
V_82 -> type = V_568 ;
F_172 ( V_82 -> V_569 ) ;
V_82 -> V_569 [ 0 ] = 0x12 ;
}
static struct V_47 * F_234 ( const T_2 * V_8 )
{
struct V_47 * V_30 ;
bool V_570 = false ;
F_195 ( & V_228 ) ;
F_102 (data, &hwsim_radios, list) {
if ( memcmp ( V_30 -> V_162 [ 1 ] . V_8 , V_8 , V_58 ) == 0 ) {
V_570 = true ;
break;
}
}
F_196 ( & V_228 ) ;
if ( ! V_570 )
return NULL ;
return V_30 ;
}
static void F_235 ( struct V_20 * V_20 , T_1 V_26 )
{
struct V_47 * V_30 ;
F_16 ( V_20 , V_26 ) ;
F_195 ( & V_228 ) ;
F_102 (data, &hwsim_radios, list) {
if ( V_30 -> V_23 == F_12 ( V_20 ) )
V_30 -> V_25 = V_26 ;
}
F_196 ( & V_228 ) ;
}
static int F_236 ( struct V_32 * V_571 ,
struct V_411 * V_99 )
{
struct V_64 * V_65 ;
struct V_47 * V_198 ;
struct V_98 * V_240 ;
struct V_148 * V_149 ;
T_3 V_572 ;
struct V_32 * V_33 , * V_573 ;
const T_2 * V_574 ;
unsigned int V_146 ;
int V_147 ;
bool V_140 = false ;
if ( ! V_99 -> V_575 [ V_161 ] ||
! V_99 -> V_575 [ V_169 ] ||
! V_99 -> V_575 [ V_179 ] ||
! V_99 -> V_575 [ V_576 ] ||
! V_99 -> V_575 [ V_176 ] )
goto V_272;
V_574 = ( void * ) F_237 ( V_99 -> V_575 [ V_161 ] ) ;
V_146 = F_19 ( V_99 -> V_575 [ V_169 ] ) ;
V_572 = F_238 ( V_99 -> V_575 [ V_179 ] ) ;
V_198 = F_234 ( V_574 ) ;
if ( ! V_198 )
goto V_272;
if ( F_12 ( F_199 ( V_99 ) ) != V_198 -> V_23 )
goto V_272;
if ( V_99 -> V_447 != V_198 -> V_25 )
goto V_272;
F_239 (&data2->pending, skb, tmp) {
T_3 V_577 ;
V_240 = F_58 ( V_33 ) ;
V_577 = ( T_3 ) ( T_7 ) V_240 -> V_178 [ 0 ] ;
if ( V_577 == V_572 ) {
F_240 ( V_33 , & V_198 -> V_152 ) ;
V_140 = true ;
break;
}
}
if ( ! V_140 )
goto V_272;
V_149 = (struct V_148 * ) F_237 (
V_99 -> V_575 [ V_176 ] ) ;
V_240 = F_58 ( V_33 ) ;
F_115 ( V_240 ) ;
for ( V_147 = 0 ; V_147 < V_150 ; V_147 ++ ) {
V_240 -> V_173 . V_174 [ V_147 ] . V_172 = V_149 [ V_147 ] . V_172 ;
V_240 -> V_173 . V_174 [ V_147 ] . V_175 = V_149 [ V_147 ] . V_175 ;
}
V_240 -> V_173 . V_578 = F_19 ( V_99 -> V_575 [ V_576 ] ) ;
if ( ! ( V_146 & V_168 ) &&
( V_146 & V_579 ) ) {
if ( V_33 -> V_164 >= 16 ) {
V_65 = (struct V_64 * ) V_33 -> V_30 ;
F_67 ( V_198 -> V_171 ,
V_65 -> V_70 ) ;
}
V_240 -> V_97 |= V_251 ;
}
F_116 ( V_198 -> V_51 , V_33 ) ;
return 0 ;
V_272:
return - V_41 ;
}
static int F_241 ( struct V_32 * V_571 ,
struct V_411 * V_99 )
{
struct V_47 * V_198 ;
struct V_200 V_201 ;
const T_2 * V_580 ;
int V_581 ;
void * V_582 ;
struct V_32 * V_33 = NULL ;
if ( ! V_99 -> V_575 [ V_583 ] ||
! V_99 -> V_575 [ V_163 ] ||
! V_99 -> V_575 [ V_584 ] ||
! V_99 -> V_575 [ V_576 ] )
goto V_272;
V_580 = ( void * ) F_237 ( V_99 -> V_575 [ V_583 ] ) ;
V_581 = F_242 ( V_99 -> V_575 [ V_163 ] ) ;
V_582 = ( void * ) F_237 ( V_99 -> V_575 [ V_163 ] ) ;
V_33 = F_243 ( V_581 , V_43 ) ;
if ( V_33 == NULL )
goto V_37;
if ( V_581 > V_450 )
goto V_37;
F_163 ( V_33 , V_582 , V_581 ) ;
V_198 = F_234 ( V_580 ) ;
if ( ! V_198 )
goto V_272;
if ( F_12 ( F_199 ( V_99 ) ) != V_198 -> V_23 )
goto V_272;
if ( V_99 -> V_447 != V_198 -> V_25 )
goto V_272;
if ( V_198 -> V_231 || ! V_198 -> V_230 )
goto V_272;
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
if ( V_99 -> V_575 [ V_170 ] ) {
F_136 ( & V_198 -> V_292 ) ;
V_201 . V_203 = F_19 ( V_99 -> V_575 [ V_170 ] ) ;
if ( V_201 . V_203 != V_198 -> V_171 -> V_118 &&
( ! V_198 -> V_232 ||
V_201 . V_203 != V_198 -> V_232 -> V_118 ) ) {
F_137 ( & V_198 -> V_292 ) ;
goto V_272;
}
F_137 ( & V_198 -> V_292 ) ;
} else {
V_201 . V_203 = V_198 -> V_171 -> V_118 ;
}
V_201 . V_204 = V_198 -> V_171 -> V_204 ;
V_201 . V_207 = F_19 ( V_99 -> V_575 [ V_584 ] ) ;
V_201 . signal = F_19 ( V_99 -> V_575 [ V_576 ] ) ;
memcpy ( F_91 ( V_33 ) , & V_201 , sizeof( V_201 ) ) ;
V_198 -> V_237 ++ ;
V_198 -> V_238 += V_33 -> V_164 ;
F_108 ( V_198 -> V_51 , V_33 ) ;
return 0 ;
V_37:
F_81 ( V_160 L_6 , V_42 ) ;
V_272:
F_47 ( V_33 ) ;
return - V_41 ;
}
static int F_244 ( struct V_32 * V_571 ,
struct V_411 * V_99 )
{
struct V_20 * V_20 = F_199 ( V_99 ) ;
struct V_47 * V_30 ;
int V_585 = 1 ;
F_195 ( & V_228 ) ;
F_102 (data, &hwsim_radios, list)
V_585 = F_245 ( V_585 , V_30 -> V_378 ) ;
F_196 ( & V_228 ) ;
if ( V_585 > 1 )
return - V_351 ;
if ( F_15 ( V_20 ) )
return - V_391 ;
F_235 ( V_20 , V_99 -> V_447 ) ;
F_81 ( V_160 L_56
L_57 , V_99 -> V_447 ) ;
return 0 ;
}
static int F_246 ( struct V_32 * V_586 , struct V_411 * V_99 )
{
struct V_414 V_415 = { 0 } ;
const char * V_428 = NULL ;
V_415 . V_423 = V_99 -> V_575 [ V_424 ] ;
V_415 . V_425 = V_99 -> V_575 [ V_426 ] ;
V_415 . V_378 = V_378 ;
V_415 . V_446 =
V_99 -> V_575 [ V_587 ] ;
if ( V_99 -> V_575 [ V_417 ] )
V_415 . V_378 = F_19 ( V_99 -> V_575 [ V_417 ] ) ;
if ( V_99 -> V_575 [ V_588 ] )
V_415 . V_544 = true ;
if ( V_99 -> V_575 [ V_429 ] ) {
V_428 = F_247 ( V_43 , L_58 ,
F_242 ( V_99 -> V_575 [ V_429 ] ) ,
( char * ) F_237 ( V_99 -> V_575 [ V_429 ] ) ) ;
if ( ! V_428 )
return - V_44 ;
V_415 . V_428 = V_428 ;
}
if ( V_99 -> V_575 [ V_427 ] )
V_415 . V_242 = true ;
else
V_415 . V_242 = ( V_415 . V_378 > 1 ) ;
if ( V_99 -> V_575 [ V_419 ] )
V_415 . V_418 =
F_237 ( V_99 -> V_575 [ V_419 ] ) ;
if ( V_99 -> V_575 [ V_422 ] ) {
T_1 V_172 = F_19 ( V_99 -> V_575 [ V_422 ] ) ;
if ( V_172 >= F_113 ( V_421 ) )
return - V_41 ;
V_415 . V_420 = V_421 [ V_172 ] ;
}
return F_194 ( V_99 , & V_415 ) ;
}
static int F_248 ( struct V_32 * V_586 , struct V_411 * V_99 )
{
struct V_47 * V_30 ;
V_93 V_172 = - 1 ;
const char * V_428 = NULL ;
if ( V_99 -> V_575 [ V_416 ] ) {
V_172 = F_19 ( V_99 -> V_575 [ V_416 ] ) ;
} else if ( V_99 -> V_575 [ V_429 ] ) {
V_428 = F_247 ( V_43 , L_58 ,
F_242 ( V_99 -> V_575 [ V_429 ] ) ,
( char * ) F_237 ( V_99 -> V_575 [ V_429 ] ) ) ;
if ( ! V_428 )
return - V_44 ;
} else
return - V_41 ;
F_195 ( & V_228 ) ;
F_102 (data, &hwsim_radios, list) {
if ( V_172 >= 0 ) {
if ( V_30 -> V_172 != V_172 )
continue;
} else {
if ( ! V_428 ||
strcmp ( V_428 , F_198 ( V_30 -> V_51 -> V_27 ) ) )
continue;
}
if ( ! F_249 ( F_250 ( V_30 -> V_51 -> V_27 ) , F_199 ( V_99 ) ) )
continue;
F_230 ( & V_30 -> V_556 ) ;
F_196 ( & V_228 ) ;
F_223 ( V_30 , F_198 ( V_30 -> V_51 -> V_27 ) ,
V_99 ) ;
F_251 ( V_428 ) ;
return 0 ;
}
F_196 ( & V_228 ) ;
F_251 ( V_428 ) ;
return - V_589 ;
}
static int F_252 ( struct V_32 * V_586 , struct V_411 * V_99 )
{
struct V_47 * V_30 ;
struct V_32 * V_33 ;
int V_172 , V_141 = - V_589 ;
if ( ! V_99 -> V_575 [ V_416 ] )
return - V_41 ;
V_172 = F_19 ( V_99 -> V_575 [ V_416 ] ) ;
F_195 ( & V_228 ) ;
F_102 (data, &hwsim_radios, list) {
if ( V_30 -> V_172 != V_172 )
continue;
if ( ! F_249 ( F_250 ( V_30 -> V_51 -> V_27 ) , F_199 ( V_99 ) ) )
continue;
V_33 = F_253 ( V_590 , V_43 ) ;
if ( ! V_33 ) {
V_141 = - V_44 ;
goto V_431;
}
V_141 = F_226 ( V_33 , V_30 , V_99 -> V_447 ,
V_99 -> V_591 , NULL , 0 ) ;
if ( V_141 < 0 ) {
F_74 ( V_33 ) ;
goto V_431;
}
F_254 ( V_33 , V_99 ) ;
break;
}
V_431:
F_196 ( & V_228 ) ;
return V_141 ;
}
static int F_255 ( struct V_32 * V_33 ,
struct V_560 * V_130 )
{
int V_172 = V_130 -> args [ 0 ] ;
struct V_47 * V_30 = NULL ;
int V_141 ;
F_195 ( & V_228 ) ;
if ( V_172 == V_436 )
goto V_592;
F_102 (data, &hwsim_radios, list) {
if ( V_30 -> V_172 < V_172 )
continue;
if ( ! F_249 ( F_250 ( V_30 -> V_51 -> V_27 ) , F_256 ( V_33 -> V_593 ) ) )
continue;
V_141 = F_226 ( V_33 , V_30 ,
F_257 ( V_130 -> V_33 ) . V_26 ,
V_130 -> V_594 -> V_595 , V_130 ,
V_596 ) ;
if ( V_141 < 0 )
break;
V_172 = V_30 -> V_172 + 1 ;
}
V_130 -> args [ 0 ] = V_172 ;
V_592:
F_196 ( & V_228 ) ;
return V_33 -> V_164 ;
}
static void F_258 ( struct V_366 * V_367 )
{
struct V_47 * V_30 =
F_130 ( V_367 , struct V_47 , V_597 ) ;
F_223 ( V_30 , F_198 ( V_30 -> V_51 -> V_27 ) , NULL ) ;
}
static void F_259 ( T_1 V_26 )
{
struct V_47 * V_598 , * V_573 ;
F_195 ( & V_228 ) ;
F_260 (entry, tmp, &hwsim_radios, list) {
if ( V_598 -> V_446 && V_598 -> V_26 == V_26 ) {
F_230 ( & V_598 -> V_556 ) ;
F_261 ( & V_598 -> V_597 , F_258 ) ;
F_262 ( & V_598 -> V_597 ) ;
}
}
F_196 ( & V_228 ) ;
}
static int F_263 ( struct V_599 * V_600 ,
unsigned long V_601 ,
void * V_602 )
{
struct V_603 * V_604 = V_602 ;
if ( V_601 != V_605 )
return V_606 ;
F_259 ( V_604 -> V_26 ) ;
if ( V_604 -> V_26 == F_15 ( V_604 -> V_20 ) ) {
F_81 ( V_607 L_59
L_60 ) ;
F_235 ( V_604 -> V_20 , 0 ) ;
}
return V_606 ;
}
static int T_9 F_264 ( void )
{
int V_608 ;
F_81 ( V_607 L_61 ) ;
V_608 = F_265 ( & V_158 ) ;
if ( V_608 )
goto V_609;
V_608 = F_266 ( & V_610 ) ;
if ( V_608 ) {
F_267 ( & V_158 ) ;
goto V_609;
}
return 0 ;
V_609:
F_81 ( V_160 L_6 , V_42 ) ;
return - V_41 ;
}
static T_10 int F_268 ( struct V_20 * V_20 )
{
F_14 ( V_20 ) ;
return 0 ;
}
static void T_11 F_269 ( struct V_20 * V_20 )
{
struct V_47 * V_30 , * V_573 ;
F_195 ( & V_228 ) ;
F_260 (data, tmp, &hwsim_radios, list) {
if ( ! F_249 ( F_250 ( V_30 -> V_51 -> V_27 ) , V_20 ) )
continue;
if ( V_30 -> V_23 == F_12 ( & V_439 ) )
continue;
F_230 ( & V_30 -> V_556 ) ;
F_261 ( & V_30 -> V_597 , F_258 ) ;
F_262 ( & V_30 -> V_597 ) ;
}
F_196 ( & V_228 ) ;
}
static void F_270 ( void )
{
F_271 ( & V_610 ) ;
F_267 ( & V_158 ) ;
}
static int T_9 F_272 ( void )
{
int V_147 , V_37 ;
if ( V_611 < 0 || V_611 > 100 )
return - V_41 ;
if ( V_378 < 1 )
return - V_41 ;
F_273 ( & V_228 ) ;
V_37 = F_274 ( & V_612 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_275 ( & V_443 ) ;
if ( V_37 )
goto V_613;
V_440 = F_276 ( V_614 , L_62 ) ;
if ( F_202 ( V_440 ) ) {
V_37 = F_203 ( V_440 ) ;
goto V_615;
}
V_37 = F_264 () ;
if ( V_37 < 0 )
goto V_615;
for ( V_147 = 0 ; V_147 < V_611 ; V_147 ++ ) {
struct V_414 V_415 = { 0 } ;
V_415 . V_378 = V_378 ;
switch ( V_616 ) {
case V_617 :
if ( V_147 < F_113 ( V_618 ) )
V_415 . V_418 = V_618 [ V_147 ] ;
break;
case V_619 :
if ( ! V_147 )
V_415 . V_418 = V_618 [ 0 ] ;
break;
case V_620 :
V_415 . V_423 = true ;
case V_621 :
V_415 . V_418 = V_618 [ 0 ] ;
break;
case V_622 :
if ( V_147 == 0 )
V_415 . V_420 = & V_623 ;
break;
case V_624 :
V_415 . V_420 = & V_623 ;
break;
case V_625 :
if ( V_147 == 0 )
V_415 . V_420 = & V_623 ;
else if ( V_147 == 1 )
V_415 . V_420 = & V_626 ;
break;
case V_627 :
if ( V_147 == 0 ) {
V_415 . V_423 = true ;
V_415 . V_418 = V_618 [ 0 ] ;
}
break;
case V_628 :
if ( V_147 == 0 ) {
V_415 . V_423 = true ;
V_415 . V_418 = V_618 [ 0 ] ;
} else if ( V_147 == 1 ) {
V_415 . V_418 = V_618 [ 1 ] ;
}
break;
case V_629 :
switch ( V_147 ) {
case 0 :
V_415 . V_420 = & V_623 ;
break;
case 1 :
V_415 . V_420 = & V_626 ;
break;
case 2 :
V_415 . V_418 = V_618 [ 0 ] ;
break;
case 3 :
V_415 . V_418 = V_618 [ 1 ] ;
break;
case 4 :
V_415 . V_423 = true ;
V_415 . V_418 = V_618 [ 2 ] ;
break;
}
break;
default:
break;
}
V_415 . V_425 = V_630 ;
V_415 . V_242 = V_378 > 1 ;
V_37 = F_194 ( NULL , & V_415 ) ;
if ( V_37 < 0 )
goto V_631;
}
V_102 = F_277 ( 0 , L_47 , V_632 ,
F_232 ) ;
if ( V_102 == NULL ) {
V_37 = - V_44 ;
goto V_631;
}
F_278 () ;
V_37 = F_279 ( V_102 , V_102 -> V_633 ) ;
if ( V_37 < 0 ) {
F_280 () ;
goto V_631;
}
V_37 = F_281 ( V_102 ) ;
if ( V_37 < 0 ) {
F_280 () ;
goto V_634;
}
F_280 () ;
return 0 ;
V_634:
F_282 ( V_102 ) ;
V_631:
F_228 () ;
V_615:
F_283 ( & V_443 ) ;
V_613:
F_284 ( & V_612 ) ;
return V_37 ;
}
static void T_12 F_285 ( void )
{
F_81 ( V_160 L_63 ) ;
F_270 () ;
F_228 () ;
F_286 ( V_102 ) ;
F_283 ( & V_443 ) ;
F_284 ( & V_612 ) ;
}
