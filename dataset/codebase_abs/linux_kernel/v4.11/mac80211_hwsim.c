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
V_39 ) ;
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
V_49 = ( void * ) F_28 ( V_33 , sizeof( * V_49 ) ) ;
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
V_65 = ( void * ) F_28 ( V_33 , sizeof( * V_65 ) - V_58 ) ;
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
V_65 = (struct V_96 * ) F_62 ( V_33 , sizeof( * V_65 ) ) ;
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
V_65 = (struct V_131 * ) F_28 ( V_33 , sizeof( * V_65 ) ) ;
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
V_132 = (struct V_64 * ) F_28 ( V_33 , 10 ) ;
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
V_191 = ( void * ) F_62 ( V_33 , sizeof( * V_191 ) + 8 + 4 ) ;
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
V_201 . V_196 |= V_209 ;
} else {
V_201 . V_207 = V_99 -> V_205 . V_174 [ 0 ] . V_172 ;
if ( V_99 -> V_205 . V_174 [ 0 ] . V_97 & V_210 )
V_201 . V_196 |= V_211 ;
}
if ( V_99 -> V_205 . V_174 [ 0 ] . V_97 & V_212 )
V_201 . V_196 |= V_213 ;
if ( V_99 -> V_205 . V_174 [ 0 ] . V_97 & V_214 )
V_201 . V_196 |= V_215 ;
V_201 . signal = V_30 -> V_216 - 50 ;
if ( V_30 -> V_63 != V_74 )
V_65 -> V_54 |= F_29 ( V_57 ) ;
F_95 ( V_33 ) ;
F_96 ( V_33 ) ;
V_33 -> V_217 = 0 ;
F_97 ( V_33 ) ;
F_98 ( V_33 ) ;
if ( F_99 ( V_65 -> V_54 ) ||
F_100 ( V_65 -> V_54 ) )
V_84 = V_30 -> V_218 ;
else
V_84 = F_48 () ;
F_101 ( & V_219 ) ;
F_102 (data2, &hwsim_radios, list) {
struct V_32 * V_220 ;
struct V_188 V_188 = {
. V_189 = false ,
. V_171 = V_62 ,
} ;
if ( V_30 == V_198 )
continue;
if ( ! V_198 -> V_221 || ( V_198 -> V_222 && ! V_198 -> V_223 ) ||
! F_70 ( V_198 , V_33 ) )
continue;
if ( ! ( V_30 -> V_80 & V_198 -> V_80 ) )
continue;
if ( V_30 -> V_23 != V_198 -> V_23 )
continue;
if ( ! F_86 ( V_62 , V_198 -> V_223 ) &&
! F_86 ( V_62 , V_198 -> V_171 ) ) {
F_40 (
V_198 -> V_51 , V_78 ,
F_87 , & V_188 ) ;
if ( ! V_188 . V_189 )
continue;
}
if ( V_33 -> V_164 < V_224 && V_225 ) {
struct V_226 * V_226 = F_103 ( V_103 ) ;
if ( ! V_226 )
continue;
V_220 = F_27 ( 128 ) ;
if ( ! V_220 ) {
F_104 ( V_226 ) ;
continue;
}
memcpy ( F_105 ( V_226 ) , V_33 -> V_30 , V_33 -> V_164 ) ;
F_106 ( V_220 , 0 , V_226 , 0 , V_33 -> V_164 , V_33 -> V_164 ) ;
} else {
V_220 = F_107 ( V_33 , V_103 ) ;
if ( ! V_220 )
continue;
}
if ( F_69 ( V_198 , V_65 -> V_69 ) )
V_199 = true ;
V_201 . V_227 = V_84 + V_198 -> V_85 ;
memcpy ( F_91 ( V_220 ) , & V_201 , sizeof( V_201 ) ) ;
F_88 ( V_220 ) ;
V_198 -> V_228 ++ ;
V_198 -> V_229 += V_220 -> V_164 ;
F_108 ( V_198 -> V_51 , V_220 ) ;
}
F_109 ( & V_219 ) ;
return V_199 ;
}
static void F_110 ( struct V_86 * V_51 ,
struct V_230 * V_205 ,
struct V_32 * V_33 )
{
struct V_47 * V_30 = V_51 -> V_87 ;
struct V_98 * V_231 = F_58 ( V_33 ) ;
struct V_64 * V_65 = ( void * ) V_33 -> V_30 ;
struct V_15 * V_60 ;
struct V_95 * V_171 ;
bool V_199 ;
T_1 V_232 ;
if ( F_6 ( V_33 -> V_164 < 10 ) ) {
F_77 ( V_51 , V_33 ) ;
return;
}
if ( ! V_30 -> V_233 ) {
V_171 = V_30 -> V_171 ;
} else if ( V_231 -> V_234 == 4 ) {
V_171 = V_30 -> V_223 ;
} else {
V_60 = F_32 ( V_231 -> V_205 . V_2 -> V_60 ) ;
if ( V_60 )
V_171 = V_60 -> V_61 . V_62 ;
else
V_171 = NULL ;
}
if ( F_2 ( ! V_171 , L_8 , V_231 -> V_234 ) ) {
F_77 ( V_51 , V_33 ) ;
return;
}
if ( V_30 -> V_222 && ! V_30 -> V_223 ) {
F_20 ( V_51 -> V_27 , L_9 ) ;
F_77 ( V_51 , V_33 ) ;
return;
}
if ( V_231 -> V_205 . V_2 )
F_1 ( V_231 -> V_205 . V_2 ) ;
if ( V_205 -> V_11 )
F_5 ( V_205 -> V_11 ) ;
if ( F_111 ( V_51 , V_235 ) )
F_112 ( V_231 -> V_205 . V_2 , V_205 -> V_11 , V_33 ,
V_231 -> V_205 . V_174 ,
F_113 ( V_231 -> V_205 . V_174 ) ) ;
V_231 -> V_178 [ 0 ] = V_171 ;
if ( V_33 -> V_164 >= 24 + 8 &&
F_100 ( V_65 -> V_54 ) ) {
struct V_236 * V_237 ;
struct V_100 * V_101 ;
T_3 V_238 ;
V_237 = (struct V_236 * ) V_33 -> V_30 ;
V_101 = F_59 ( V_51 , V_231 ) ;
V_238 = F_48 () ;
V_237 -> V_239 . V_240 . V_241 =
F_52 ( V_238 + V_30 -> V_85 +
24 * 8 * 10 / V_101 -> V_116 ) ;
}
F_57 ( V_51 , V_33 , V_171 ) ;
V_232 = F_114 ( V_30 -> V_25 ) ;
if ( V_232 )
return F_75 ( V_51 , V_33 , V_232 ) ;
V_30 -> V_182 ++ ;
V_30 -> V_183 += V_33 -> V_164 ;
V_199 = F_92 ( V_51 , V_33 , V_171 ) ;
if ( V_199 && V_33 -> V_164 >= 16 )
F_67 ( V_171 , V_65 -> V_70 ) ;
F_115 ( V_231 ) ;
V_231 -> V_205 . V_174 [ 0 ] . V_175 = 1 ;
V_231 -> V_205 . V_174 [ 1 ] . V_172 = - 1 ;
if ( ! ( V_231 -> V_97 & V_167 ) && V_199 )
V_231 -> V_97 |= V_242 ;
F_116 ( V_51 , V_33 ) ;
}
static int F_117 ( struct V_86 * V_51 )
{
struct V_47 * V_30 = V_51 -> V_87 ;
F_20 ( V_51 -> V_27 , L_10 , V_42 ) ;
V_30 -> V_221 = true ;
return 0 ;
}
static void F_118 ( struct V_86 * V_51 )
{
struct V_47 * V_30 = V_51 -> V_87 ;
V_30 -> V_221 = false ;
F_119 ( & V_30 -> V_243 ) ;
F_20 ( V_51 -> V_27 , L_10 , V_42 ) ;
}
static int F_120 ( struct V_86 * V_51 ,
struct V_1 * V_2 )
{
F_20 ( V_51 -> V_27 , L_11 ,
V_42 , F_121 ( V_2 ) ,
V_2 -> V_8 ) ;
F_3 ( V_2 ) ;
V_2 -> V_244 = 0 ;
V_2 -> V_234 [ V_245 ] = 0 ;
V_2 -> V_234 [ V_246 ] = 1 ;
V_2 -> V_234 [ V_247 ] = 2 ;
V_2 -> V_234 [ V_248 ] = 3 ;
return 0 ;
}
static int F_122 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
enum V_249 V_250 ,
bool V_251 )
{
V_250 = F_123 ( V_250 , V_251 ) ;
F_20 ( V_51 -> V_27 ,
L_12 ,
V_42 , F_121 ( V_2 ) ,
V_250 , V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
V_2 -> V_244 = 0 ;
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
T_1 V_252 = F_114 ( V_30 -> V_25 ) ;
if ( F_111 ( V_51 , V_235 ) ) {
struct V_98 * V_231 = F_58 ( V_33 ) ;
F_112 ( V_231 -> V_205 . V_2 , NULL , V_33 ,
V_231 -> V_205 . V_174 ,
F_113 ( V_231 -> V_205 . V_174 ) ) ;
}
F_57 ( V_51 , V_33 , V_62 ) ;
if ( V_252 )
return F_75 ( V_51 , V_33 , V_252 ) ;
F_92 ( V_51 , V_33 , V_62 ) ;
F_47 ( V_33 ) ;
}
static void F_125 ( void * V_253 , T_2 * V_46 ,
struct V_1 * V_2 )
{
struct V_47 * V_30 = V_253 ;
struct V_86 * V_51 = V_30 -> V_51 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_236 * V_237 ;
struct V_32 * V_33 ;
F_1 ( V_2 ) ;
if ( V_2 -> type != V_254 &&
V_2 -> type != V_255 &&
V_2 -> type != V_256 )
return;
V_33 = F_126 ( V_51 , V_2 ) ;
if ( V_33 == NULL )
return;
V_99 = F_58 ( V_33 ) ;
if ( F_111 ( V_51 , V_235 ) )
F_112 ( V_2 , NULL , V_33 ,
V_99 -> V_205 . V_174 ,
F_113 ( V_99 -> V_205 . V_174 ) ) ;
V_101 = F_59 ( V_51 , V_99 ) ;
V_237 = (struct V_236 * ) V_33 -> V_30 ;
V_30 -> V_218 = F_48 () ;
V_237 -> V_239 . V_257 . V_241 = F_52 ( V_30 -> V_218 +
V_30 -> V_85 +
24 * 8 * 10 / V_101 -> V_116 ) ;
F_31 ( V_51 , V_33 ,
F_32 ( V_2 -> V_60 ) -> V_61 . V_62 ) ;
if ( V_2 -> V_258 && F_127 ( V_2 ) )
F_128 ( V_2 ) ;
}
static enum V_259
F_129 ( struct V_260 * V_261 )
{
struct V_47 * V_30 =
F_130 ( V_261 , struct V_47 ,
V_243 . V_261 ) ;
struct V_86 * V_51 = V_30 -> V_51 ;
T_3 V_89 = V_30 -> V_90 ;
T_8 V_262 ;
if ( ! V_30 -> V_221 )
goto V_263;
F_40 (
V_51 , V_78 ,
F_125 , V_30 ) ;
if ( V_30 -> V_92 ) {
V_89 -= V_30 -> V_92 ;
V_30 -> V_92 = 0 ;
}
V_262 = F_131 ( F_132 ( V_261 ) ,
F_133 ( V_89 * 1000 ) ) ;
F_134 ( & V_30 -> V_243 , V_262 , V_264 ) ;
V_263:
return V_265 ;
}
static int F_135 ( struct V_86 * V_51 , T_1 V_266 )
{
struct V_47 * V_30 = V_51 -> V_87 ;
struct V_267 * V_268 = & V_51 -> V_268 ;
static const char * V_269 [ V_270 ] = {
[ V_271 ] = L_13 ,
[ V_272 ] = L_14 ,
[ V_273 ] = L_15 ,
[ V_274 ] = L_16 ,
} ;
if ( V_268 -> V_275 . V_62 )
F_20 ( V_51 -> V_27 ,
L_17 ,
V_42 ,
V_268 -> V_275 . V_62 -> V_118 ,
V_268 -> V_275 . V_276 ,
V_268 -> V_275 . V_277 ,
V_278 [ V_268 -> V_275 . V_279 ] ,
! ! ( V_268 -> V_97 & V_280 ) ,
! ! ( V_268 -> V_97 & V_281 ) ,
V_269 [ V_268 -> V_282 ] ) ;
else
F_20 ( V_51 -> V_27 ,
L_18 ,
V_42 ,
! ! ( V_268 -> V_97 & V_280 ) ,
! ! ( V_268 -> V_97 & V_281 ) ,
V_269 [ V_268 -> V_282 ] ) ;
V_30 -> V_222 = ! ! ( V_268 -> V_97 & V_280 ) ;
V_30 -> V_171 = V_268 -> V_275 . V_62 ;
F_6 ( V_30 -> V_171 && V_30 -> V_233 ) ;
V_30 -> V_216 = V_268 -> V_216 ;
if ( ! V_30 -> V_221 || ! V_30 -> V_90 )
F_119 ( & V_30 -> V_243 ) ;
else if ( ! F_136 ( & V_30 -> V_243 . V_261 ) ) {
T_3 V_88 = F_53 ( V_51 , NULL ) ;
T_1 V_89 = V_30 -> V_90 ;
T_3 V_283 = V_89 - F_56 ( V_88 , V_89 ) ;
F_134 ( & V_30 -> V_243 ,
F_133 ( V_283 * 1000 ) ,
V_284 ) ;
}
return 0 ;
}
static void F_137 ( struct V_86 * V_51 ,
unsigned int V_285 ,
unsigned int * V_286 , T_3 V_287 )
{
struct V_47 * V_30 = V_51 -> V_87 ;
F_20 ( V_51 -> V_27 , L_10 , V_42 ) ;
V_30 -> V_288 = 0 ;
if ( * V_286 & V_289 )
V_30 -> V_288 |= V_289 ;
* V_286 = V_30 -> V_288 ;
}
static void F_138 ( void * V_30 , T_2 * V_46 ,
struct V_1 * V_2 )
{
unsigned int * V_175 = V_30 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
if ( V_4 -> V_290 )
( * V_175 ) ++ ;
}
static void F_139 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_291 * V_99 ,
T_1 V_266 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_47 * V_30 = V_51 -> V_87 ;
F_1 ( V_2 ) ;
F_20 ( V_51 -> V_27 , L_19 ,
V_42 , V_266 , V_2 -> V_8 ) ;
if ( V_266 & V_292 ) {
F_20 ( V_51 -> V_27 , L_20 ,
V_42 , V_99 -> V_52 ) ;
memcpy ( V_4 -> V_52 , V_99 -> V_52 , V_58 ) ;
}
if ( V_266 & V_293 ) {
F_20 ( V_51 -> V_27 , L_21 ,
V_99 -> V_50 , V_99 -> V_53 ) ;
V_4 -> V_50 = V_99 -> V_50 ;
V_4 -> V_53 = V_99 -> V_53 ;
}
if ( V_266 & V_294 ) {
F_20 ( V_51 -> V_27 , L_22 ,
V_99 -> V_295 , V_99 -> V_90 ) ;
V_4 -> V_290 = V_99 -> V_295 ;
if ( V_30 -> V_221 &&
! F_136 ( & V_30 -> V_243 . V_261 ) &&
V_99 -> V_295 ) {
T_3 V_88 , V_283 ;
T_1 V_89 ;
V_30 -> V_90 = V_99 -> V_90 * 1024 ;
V_88 = F_53 ( V_51 , V_2 ) ;
V_89 = V_30 -> V_90 ;
V_283 = V_89 - F_56 ( V_88 , V_89 ) ;
F_134 ( & V_30 -> V_243 ,
F_133 ( V_283 * 1000 ) ,
V_284 ) ;
} else if ( ! V_99 -> V_295 ) {
unsigned int V_175 = 0 ;
F_40 (
V_30 -> V_51 , V_78 ,
F_138 , & V_175 ) ;
F_20 ( V_51 -> V_27 , L_23 ,
V_175 ) ;
if ( V_175 == 0 ) {
F_119 ( & V_30 -> V_243 ) ;
V_30 -> V_90 = 0 ;
}
}
}
if ( V_266 & V_296 ) {
F_20 ( V_51 -> V_27 , L_24 ,
V_99 -> V_297 ) ;
}
if ( V_266 & V_298 ) {
F_20 ( V_51 -> V_27 , L_25 ,
V_99 -> V_299 ) ;
}
if ( V_266 & V_300 ) {
F_20 ( V_51 -> V_27 , L_26 , V_99 -> V_301 ) ;
}
if ( V_266 & V_302 ) {
F_20 ( V_51 -> V_27 , L_27 ,
V_99 -> V_303 ) ;
}
if ( V_266 & V_304 ) {
F_20 ( V_51 -> V_27 , L_28 ,
( unsigned long long ) V_99 -> V_305 ) ;
}
if ( V_266 & V_306 )
F_20 ( V_51 -> V_27 , L_29 , V_99 -> V_307 ) ;
}
static int F_140 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_7 ( V_11 ) ;
return 0 ;
}
static int F_141 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static void F_142 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
enum V_308 V_309 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
switch ( V_309 ) {
case V_310 :
case V_311 :
break;
default:
F_2 ( 1 , L_30 , V_309 ) ;
break;
}
}
static int F_143 ( struct V_86 * V_51 ,
struct V_10 * V_11 ,
bool V_312 )
{
F_5 ( V_11 ) ;
return 0 ;
}
static int F_144 (
struct V_86 * V_51 ,
struct V_1 * V_2 , T_6 V_313 ,
const struct V_314 * V_315 )
{
F_20 ( V_51 -> V_27 ,
L_31 ,
V_42 , V_313 ,
V_315 -> V_316 , V_315 -> V_317 ,
V_315 -> V_318 , V_315 -> V_319 ) ;
return 0 ;
}
static int F_145 (
struct V_86 * V_51 , int V_172 ,
struct V_320 * V_321 )
{
struct V_267 * V_268 = & V_51 -> V_268 ;
F_20 ( V_51 -> V_27 , L_32 , V_42 , V_172 ) ;
if ( V_172 != 0 )
return - V_142 ;
V_321 -> V_171 = V_268 -> V_275 . V_62 ;
V_321 -> V_322 = V_323 ;
V_321 -> V_324 = - 92 ;
return 0 ;
}
static int F_146 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
void * V_30 , int V_164 )
{
struct V_47 * V_325 = V_51 -> V_87 ;
struct V_34 * V_35 [ V_326 + 1 ] ;
struct V_32 * V_33 ;
int V_37 , V_63 ;
V_37 = F_18 ( V_35 , V_326 , V_30 , V_164 ,
V_327 ) ;
if ( V_37 )
return V_37 ;
if ( ! V_35 [ V_328 ] )
return - V_41 ;
switch ( F_19 ( V_35 [ V_328 ] ) ) {
case V_329 :
if ( ! V_35 [ V_330 ] )
return - V_41 ;
V_63 = F_19 ( V_35 [ V_330 ] ) ;
return F_38 ( V_325 , V_63 ) ;
case V_331 :
V_33 = F_147 ( V_51 -> V_27 ,
F_148 ( sizeof( T_1 ) ) ) ;
if ( ! V_33 )
return - V_44 ;
if ( F_22 ( V_33 , V_330 , V_325 -> V_63 ) )
goto V_157;
return F_149 ( V_33 ) ;
case V_332 :
F_150 ( V_51 ) ;
return 0 ;
case V_333 :
F_151 ( V_51 ) ;
return 0 ;
default:
return - V_334 ;
}
V_157:
F_152 ( V_33 ) ;
return - V_335 ;
}
static int F_153 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_336 * V_315 )
{
struct V_10 * V_11 = V_315 -> V_11 ;
enum V_337 V_338 = V_315 -> V_338 ;
T_6 V_339 = V_315 -> V_339 ;
switch ( V_338 ) {
case V_340 :
F_154 ( V_2 , V_11 -> V_8 , V_339 ) ;
break;
case V_341 :
case V_342 :
case V_343 :
F_155 ( V_2 , V_11 -> V_8 , V_339 ) ;
break;
case V_344 :
break;
case V_345 :
case V_346 :
break;
default:
return - V_334 ;
}
return 0 ;
}
static void F_156 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
T_1 V_347 , bool V_348 )
{
}
static void F_157 ( struct V_349 * V_350 )
{
struct V_47 * V_325 =
F_130 ( V_350 , struct V_47 , V_351 . V_350 ) ;
struct V_352 * V_353 = V_325 -> V_354 ;
int V_355 , V_147 ;
F_158 ( & V_325 -> V_356 ) ;
if ( V_325 -> V_357 >= V_353 -> V_358 ) {
struct V_359 V_99 = {
. V_360 = false ,
} ;
F_20 ( V_325 -> V_51 -> V_27 , L_33 ) ;
F_159 ( V_325 -> V_51 , & V_99 ) ;
V_325 -> V_354 = NULL ;
V_325 -> V_361 = NULL ;
V_325 -> V_223 = NULL ;
F_160 ( & V_325 -> V_356 ) ;
return;
}
F_20 ( V_325 -> V_51 -> V_27 , L_34 ,
V_353 -> V_362 [ V_325 -> V_357 ] -> V_118 ) ;
V_325 -> V_223 = V_353 -> V_362 [ V_325 -> V_357 ] ;
if ( V_325 -> V_223 -> V_97 & ( V_363 |
V_364 ) ||
! V_353 -> V_365 ) {
V_355 = 120 ;
} else {
V_355 = 30 ;
for ( V_147 = 0 ; V_147 < V_353 -> V_365 ; V_147 ++ ) {
struct V_32 * V_366 ;
struct V_236 * V_237 ;
V_366 = F_161 ( V_325 -> V_51 ,
V_325 -> V_139 ,
V_353 -> V_367 [ V_147 ] . V_368 ,
V_353 -> V_367 [ V_147 ] . V_369 ,
V_353 -> V_370 ) ;
if ( ! V_366 )
continue;
V_237 = (struct V_236 * ) V_366 -> V_30 ;
memcpy ( V_237 -> V_371 , V_353 -> V_52 , V_58 ) ;
memcpy ( V_237 -> V_52 , V_353 -> V_52 , V_58 ) ;
if ( V_353 -> V_370 )
memcpy ( F_28 ( V_366 , V_353 -> V_370 ) , V_353 -> V_372 ,
V_353 -> V_370 ) ;
F_39 () ;
F_31 ( V_325 -> V_51 , V_366 ,
V_325 -> V_223 ) ;
F_41 () ;
}
}
F_162 ( V_325 -> V_51 , & V_325 -> V_351 ,
F_163 ( V_355 ) ) ;
V_325 -> V_357 ++ ;
F_160 ( & V_325 -> V_356 ) ;
}
static int F_164 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_373 * V_374 )
{
struct V_47 * V_325 = V_51 -> V_87 ;
struct V_352 * V_353 = & V_374 -> V_353 ;
F_158 ( & V_325 -> V_356 ) ;
if ( F_6 ( V_325 -> V_223 || V_325 -> V_354 ) ) {
F_160 ( & V_325 -> V_356 ) ;
return - V_375 ;
}
V_325 -> V_354 = V_353 ;
V_325 -> V_361 = V_2 ;
V_325 -> V_357 = 0 ;
if ( V_353 -> V_97 & V_376 )
F_165 ( V_325 -> V_139 ,
V_374 -> V_353 . V_377 ,
V_374 -> V_353 . V_378 ) ;
else
memcpy ( V_325 -> V_139 , V_2 -> V_8 , V_58 ) ;
F_160 ( & V_325 -> V_356 ) ;
F_20 ( V_51 -> V_27 , L_35 ) ;
F_162 ( V_325 -> V_51 , & V_325 -> V_351 , 0 ) ;
return 0 ;
}
static void F_166 ( struct V_86 * V_51 ,
struct V_1 * V_2 )
{
struct V_47 * V_325 = V_51 -> V_87 ;
struct V_359 V_99 = {
. V_360 = true ,
} ;
F_20 ( V_51 -> V_27 , L_36 ) ;
F_167 ( & V_325 -> V_351 ) ;
F_158 ( & V_325 -> V_356 ) ;
F_159 ( V_325 -> V_51 , & V_99 ) ;
V_325 -> V_223 = NULL ;
V_325 -> V_354 = NULL ;
V_325 -> V_361 = NULL ;
F_160 ( & V_325 -> V_356 ) ;
}
static void F_168 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
const T_2 * V_377 )
{
struct V_47 * V_325 = V_51 -> V_87 ;
F_158 ( & V_325 -> V_356 ) ;
if ( V_325 -> V_138 ) {
F_81 ( V_160 L_37 ) ;
goto V_263;
}
F_81 ( V_160 L_38 ) ;
memcpy ( V_325 -> V_139 , V_377 , V_58 ) ;
V_325 -> V_138 = true ;
V_263:
F_160 ( & V_325 -> V_356 ) ;
}
static void F_169 ( struct V_86 * V_51 ,
struct V_1 * V_2 )
{
struct V_47 * V_325 = V_51 -> V_87 ;
F_158 ( & V_325 -> V_356 ) ;
F_81 ( V_160 L_39 ) ;
V_325 -> V_138 = false ;
F_170 ( V_325 -> V_139 ) ;
F_160 ( & V_325 -> V_356 ) ;
}
static void F_171 ( struct V_349 * V_350 )
{
struct V_47 * V_325 =
F_130 ( V_350 , struct V_47 , V_379 . V_350 ) ;
F_158 ( & V_325 -> V_356 ) ;
F_20 ( V_325 -> V_51 -> V_27 , L_40 ) ;
V_325 -> V_223 = V_325 -> V_380 ;
F_172 ( V_325 -> V_51 ) ;
F_162 ( V_325 -> V_51 , & V_325 -> V_381 ,
F_163 ( V_325 -> V_382 ) ) ;
F_160 ( & V_325 -> V_356 ) ;
}
static void F_173 ( struct V_349 * V_350 )
{
struct V_47 * V_325 =
F_130 ( V_350 , struct V_47 , V_381 . V_350 ) ;
F_158 ( & V_325 -> V_356 ) ;
F_174 ( V_325 -> V_51 ) ;
V_325 -> V_223 = NULL ;
F_160 ( & V_325 -> V_356 ) ;
F_20 ( V_325 -> V_51 -> V_27 , L_41 ) ;
}
static int F_175 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_95 * V_62 ,
int V_383 ,
enum V_384 type )
{
struct V_47 * V_325 = V_51 -> V_87 ;
F_158 ( & V_325 -> V_356 ) ;
if ( F_6 ( V_325 -> V_223 || V_325 -> V_354 ) ) {
F_160 ( & V_325 -> V_356 ) ;
return - V_375 ;
}
V_325 -> V_380 = V_62 ;
V_325 -> V_382 = V_383 ;
F_160 ( & V_325 -> V_356 ) ;
F_20 ( V_51 -> V_27 , L_42 ,
V_62 -> V_118 , V_383 ) ;
F_162 ( V_51 , & V_325 -> V_379 , V_385 / 50 ) ;
return 0 ;
}
static int F_176 ( struct V_86 * V_51 )
{
struct V_47 * V_325 = V_51 -> V_87 ;
F_167 ( & V_325 -> V_379 ) ;
F_167 ( & V_325 -> V_381 ) ;
F_158 ( & V_325 -> V_356 ) ;
V_325 -> V_223 = NULL ;
F_160 ( & V_325 -> V_356 ) ;
F_20 ( V_51 -> V_27 , L_43 ) ;
return 0 ;
}
static int F_177 ( struct V_86 * V_51 ,
struct V_15 * V_386 )
{
F_10 ( V_386 ) ;
F_20 ( V_51 -> V_27 ,
L_44 ,
V_386 -> V_61 . V_62 -> V_118 , V_386 -> V_61 . V_279 ,
V_386 -> V_61 . V_276 , V_386 -> V_61 . V_277 ) ;
return 0 ;
}
static void F_178 ( struct V_86 * V_51 ,
struct V_15 * V_386 )
{
F_20 ( V_51 -> V_27 ,
L_45 ,
V_386 -> V_61 . V_62 -> V_118 , V_386 -> V_61 . V_279 ,
V_386 -> V_61 . V_276 , V_386 -> V_61 . V_277 ) ;
F_9 ( V_386 ) ;
F_11 ( V_386 ) ;
}
static void F_179 ( struct V_86 * V_51 ,
struct V_15 * V_386 ,
T_1 V_266 )
{
F_9 ( V_386 ) ;
F_20 ( V_51 -> V_27 ,
L_46 ,
V_386 -> V_61 . V_62 -> V_118 , V_386 -> V_61 . V_279 ,
V_386 -> V_61 . V_276 , V_386 -> V_61 . V_277 ) ;
}
static int F_180 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_15 * V_386 )
{
F_1 ( V_2 ) ;
F_9 ( V_386 ) ;
return 0 ;
}
static void F_181 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_15 * V_386 )
{
F_1 ( V_2 ) ;
F_9 ( V_386 ) ;
}
static void F_182 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
T_1 V_387 , T_2 * V_30 )
{
if ( V_387 == V_388 )
memcpy ( V_30 , * V_389 ,
sizeof( V_389 ) ) ;
}
static int F_183 ( struct V_86 * V_51 ,
struct V_1 * V_2 , int V_387 )
{
if ( V_387 == V_388 )
return V_390 ;
return 0 ;
}
static void F_184 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_391 * V_392 , T_3 * V_30 )
{
struct V_47 * V_393 = V_51 -> V_87 ;
int V_147 = 0 ;
V_30 [ V_147 ++ ] = V_393 -> V_182 ;
V_30 [ V_147 ++ ] = V_393 -> V_183 ;
V_30 [ V_147 ++ ] = V_393 -> V_228 ;
V_30 [ V_147 ++ ] = V_393 -> V_229 ;
V_30 [ V_147 ++ ] = V_393 -> V_155 ;
V_30 [ V_147 ++ ] = V_393 -> V_184 ;
V_30 [ V_147 ++ ] = V_393 -> V_63 ;
V_30 [ V_147 ++ ] = V_393 -> V_80 ;
V_30 [ V_147 ++ ] = V_393 -> V_216 ;
F_6 ( V_147 != V_390 ) ;
}
static void F_185 ( struct V_32 * V_394 ,
struct V_395 * V_99 )
{
if ( V_99 )
F_186 ( & V_158 , V_394 , V_99 ,
V_396 , V_43 ) ;
else
F_187 ( & V_158 , V_394 , 0 ,
V_396 , V_43 ) ;
}
static int F_188 ( struct V_32 * V_33 , int V_397 ,
struct V_398 * V_399 )
{
int V_137 ;
V_137 = F_22 ( V_33 , V_400 , V_397 ) ;
if ( V_137 < 0 )
return V_137 ;
if ( V_399 -> V_362 ) {
V_137 = F_22 ( V_33 , V_401 , V_399 -> V_362 ) ;
if ( V_137 < 0 )
return V_137 ;
}
if ( V_399 -> V_402 ) {
V_137 = F_82 ( V_33 , V_403 , 2 ,
V_399 -> V_402 ) ;
if ( V_137 < 0 )
return V_137 ;
}
if ( V_399 -> V_404 ) {
int V_147 ;
for ( V_147 = 0 ; V_147 < F_113 ( V_405 ) ; V_147 ++ ) {
if ( V_405 [ V_147 ] != V_399 -> V_404 )
continue;
V_137 = F_22 ( V_33 , V_406 , V_147 ) ;
if ( V_137 < 0 )
return V_137 ;
break;
}
}
if ( V_399 -> V_407 ) {
V_137 = F_189 ( V_33 , V_408 ) ;
if ( V_137 < 0 )
return V_137 ;
}
if ( V_399 -> V_409 ) {
V_137 = F_189 ( V_33 , V_410 ) ;
if ( V_137 < 0 )
return V_137 ;
}
if ( V_399 -> V_233 ) {
V_137 = F_189 ( V_33 , V_411 ) ;
if ( V_137 < 0 )
return V_137 ;
}
if ( V_399 -> V_412 ) {
V_137 = F_82 ( V_33 , V_413 ,
strlen ( V_399 -> V_412 ) , V_399 -> V_412 ) ;
if ( V_137 < 0 )
return V_137 ;
}
return 0 ;
}
static void F_190 ( int V_397 , struct V_395 * V_99 ,
struct V_398 * V_399 )
{
struct V_32 * V_394 ;
void * V_30 ;
V_394 = F_79 ( V_156 , V_43 ) ;
if ( ! V_394 )
return;
V_30 = F_80 ( V_394 , 0 , 0 , & V_158 , 0 ,
V_414 ) ;
if ( ! V_30 )
goto V_415;
if ( F_188 ( V_394 , V_397 , V_399 ) < 0 )
goto V_415;
F_84 ( V_394 , V_30 ) ;
F_185 ( V_394 , V_99 ) ;
return;
V_415:
F_191 ( V_394 , V_30 ) ;
F_74 ( V_394 ) ;
}
static int F_192 ( struct V_395 * V_99 ,
struct V_398 * V_399 )
{
int V_37 ;
T_2 V_8 [ V_58 ] ;
struct V_47 * V_30 ;
struct V_86 * V_51 ;
enum V_416 V_204 ;
const struct V_417 * V_418 = & V_419 ;
struct V_20 * V_20 ;
int V_172 ;
if ( F_6 ( V_399 -> V_362 > 1 && ! V_399 -> V_233 ) )
return - V_41 ;
F_193 ( & V_219 ) ;
V_172 = V_420 ++ ;
F_194 ( & V_219 ) ;
if ( V_399 -> V_233 )
V_418 = & V_421 ;
V_51 = F_195 ( sizeof( * V_30 ) , V_418 , V_399 -> V_412 ) ;
if ( ! V_51 ) {
F_81 ( V_160 L_47 ) ;
V_37 = - V_44 ;
goto V_422;
}
if ( V_99 )
V_20 = F_196 ( V_99 ) ;
else
V_20 = & V_423 ;
F_197 ( V_51 -> V_27 , V_20 ) ;
V_30 = V_51 -> V_87 ;
V_30 -> V_51 = V_51 ;
V_30 -> V_82 = F_198 ( V_424 , NULL , 0 , V_51 , L_48 , V_172 ) ;
if ( F_199 ( V_30 -> V_82 ) ) {
F_81 ( V_160
L_49 ,
F_200 ( V_30 -> V_82 ) ) ;
V_37 = - V_44 ;
goto V_425;
}
V_30 -> V_82 -> V_426 = & V_427 . V_426 ;
V_37 = F_201 ( V_30 -> V_82 ) ;
if ( V_37 != 0 ) {
F_81 ( V_160 L_50 ,
V_37 ) ;
goto V_428;
}
F_202 ( & V_30 -> V_152 ) ;
F_203 ( V_51 , V_30 -> V_82 ) ;
F_170 ( V_8 ) ;
V_8 [ 0 ] = 0x02 ;
V_8 [ 3 ] = V_172 >> 8 ;
V_8 [ 4 ] = V_172 ;
memcpy ( V_30 -> V_162 [ 0 ] . V_8 , V_8 , V_58 ) ;
memcpy ( V_30 -> V_162 [ 1 ] . V_8 , V_8 , V_58 ) ;
V_30 -> V_162 [ 1 ] . V_8 [ 0 ] |= 0x40 ;
V_51 -> V_27 -> V_429 = 2 ;
V_51 -> V_27 -> V_162 = V_30 -> V_162 ;
V_30 -> V_362 = V_399 -> V_362 ;
V_30 -> V_233 = V_399 -> V_233 ;
V_30 -> V_172 = V_172 ;
V_30 -> V_430 = V_399 -> V_430 ;
if ( V_99 )
V_30 -> V_26 = V_99 -> V_431 ;
if ( V_30 -> V_233 ) {
V_51 -> V_27 -> V_432 = 255 ;
V_51 -> V_27 -> V_433 = V_434 ;
V_51 -> V_27 -> V_435 = 1000 ;
V_51 -> V_27 -> V_436 = & V_30 -> V_437 ;
if ( V_399 -> V_409 )
V_30 -> V_437 = V_438 [ 0 ] ;
else
V_30 -> V_437 = V_439 [ 0 ] ;
V_51 -> V_27 -> V_440 = 1 ;
V_30 -> V_437 . V_441 = 0 ;
V_30 -> V_437 . V_442 = V_30 -> V_362 ;
} else if ( V_399 -> V_409 ) {
V_51 -> V_27 -> V_436 = V_438 ;
V_51 -> V_27 -> V_440 =
F_113 ( V_438 ) ;
} else {
V_51 -> V_27 -> V_436 = V_439 ;
V_51 -> V_27 -> V_440 = F_113 ( V_439 ) ;
}
F_204 ( & V_30 -> V_379 , F_171 ) ;
F_204 ( & V_30 -> V_381 , F_173 ) ;
F_204 ( & V_30 -> V_351 , F_157 ) ;
V_51 -> V_347 = 5 ;
V_51 -> V_443 = 4 ;
V_51 -> V_27 -> V_444 = F_90 ( V_445 ) |
F_90 ( V_254 ) |
F_90 ( V_446 ) |
F_90 ( V_447 ) |
F_90 ( V_256 ) |
F_90 ( V_255 ) ;
if ( V_399 -> V_409 )
V_51 -> V_27 -> V_444 |= F_90 ( V_448 ) ;
F_205 ( V_51 , V_449 ) ;
F_205 ( V_51 , V_450 ) ;
F_205 ( V_51 , V_451 ) ;
F_205 ( V_51 , V_452 ) ;
F_205 ( V_51 , V_453 ) ;
F_205 ( V_51 , V_454 ) ;
F_205 ( V_51 , V_455 ) ;
F_205 ( V_51 , V_456 ) ;
F_205 ( V_51 , V_457 ) ;
if ( V_458 )
F_205 ( V_51 , V_235 ) ;
V_51 -> V_27 -> V_97 |= V_459 |
V_460 |
V_461 |
V_462 ;
V_51 -> V_27 -> V_463 |= V_464 |
V_465 |
V_466 |
V_467 |
V_468 ;
F_206 ( V_51 -> V_27 , V_469 ) ;
V_51 -> V_470 = sizeof( struct V_3 ) ;
V_51 -> V_471 = sizeof( struct V_12 ) ;
V_51 -> V_472 = sizeof( struct V_17 ) ;
memcpy ( V_30 -> V_473 , V_474 ,
sizeof( V_474 ) ) ;
memcpy ( V_30 -> V_475 , V_476 ,
sizeof( V_476 ) ) ;
memcpy ( V_30 -> V_174 , V_477 , sizeof( V_477 ) ) ;
for ( V_204 = V_478 ; V_204 < V_479 ; V_204 ++ ) {
struct V_480 * V_481 = & V_30 -> V_482 [ V_204 ] ;
switch ( V_204 ) {
case V_478 :
V_481 -> V_362 = V_30 -> V_473 ;
V_481 -> V_358 = F_113 ( V_474 ) ;
V_481 -> V_483 = V_30 -> V_174 ;
V_481 -> V_484 = F_113 ( V_477 ) ;
break;
case V_485 :
V_481 -> V_362 = V_30 -> V_475 ;
V_481 -> V_358 = F_113 ( V_476 ) ;
V_481 -> V_483 = V_30 -> V_174 + 4 ;
V_481 -> V_484 = F_113 ( V_477 ) - 4 ;
V_481 -> V_486 . V_487 = true ;
V_481 -> V_486 . V_488 =
V_489 |
V_490 |
V_491 |
V_492 |
V_493 |
V_494 |
V_495 |
V_496 |
V_497 |
V_498 |
V_499 ;
V_481 -> V_486 . V_500 . V_501 =
F_29 ( V_502 << 0 |
V_502 << 2 |
V_502 << 4 |
V_502 << 6 |
V_502 << 8 |
V_502 << 10 |
V_502 << 12 |
V_502 << 14 ) ;
V_481 -> V_486 . V_500 . V_503 =
V_481 -> V_486 . V_500 . V_501 ;
break;
default:
continue;
}
V_481 -> V_504 . V_505 = true ;
V_481 -> V_504 . V_488 = V_506 |
V_507 |
V_508 |
V_509 |
V_510 ;
V_481 -> V_504 . V_511 = 0x3 ;
V_481 -> V_504 . V_512 = 0x6 ;
memset ( & V_481 -> V_504 . V_513 , 0 ,
sizeof( V_481 -> V_504 . V_513 ) ) ;
V_481 -> V_504 . V_513 . V_514 [ 0 ] = 0xff ;
V_481 -> V_504 . V_513 . V_514 [ 1 ] = 0xff ;
V_481 -> V_504 . V_513 . V_515 = V_516 ;
V_51 -> V_27 -> V_482 [ V_204 ] = V_481 ;
}
V_30 -> V_80 = 1 ;
F_207 ( & V_30 -> V_356 ) ;
V_30 -> V_23 = F_12 ( V_20 ) ;
V_51 -> V_517 = 4 ;
V_51 -> V_518 = 11 ;
V_51 -> V_27 -> V_519 = V_520 ;
V_51 -> V_27 -> V_521 =
F_113 ( V_520 ) ;
V_51 -> V_27 -> V_522 = V_523 ;
V_51 -> V_27 -> V_524 = F_113 ( V_523 ) ;
if ( V_399 -> V_407 )
V_51 -> V_27 -> V_525 |= V_526 ;
if ( V_399 -> V_404 ) {
V_30 -> V_404 = V_399 -> V_404 ;
V_51 -> V_27 -> V_525 |= V_527 ;
F_208 ( V_51 -> V_27 , V_399 -> V_404 ) ;
F_209 ( 1 ) ;
}
if ( V_399 -> V_528 )
F_205 ( V_51 , V_529 ) ;
V_37 = F_210 ( V_51 ) ;
if ( V_37 < 0 ) {
F_81 ( V_160 L_51 ,
V_37 ) ;
goto V_530;
}
F_20 ( V_51 -> V_27 , L_52 , V_51 -> V_27 -> V_531 ) ;
if ( V_399 -> V_402 ) {
V_30 -> V_532 [ 0 ] = V_399 -> V_402 [ 0 ] ;
V_30 -> V_532 [ 1 ] = V_399 -> V_402 [ 1 ] ;
F_211 ( V_51 -> V_27 , V_399 -> V_402 ) ;
}
V_30 -> V_533 = F_212 ( L_53 , V_51 -> V_27 -> V_534 ) ;
F_213 ( L_54 , 0666 , V_30 -> V_533 , V_30 , & V_535 ) ;
F_213 ( L_55 , 0666 , V_30 -> V_533 , V_30 ,
& V_536 ) ;
if ( ! V_30 -> V_233 )
F_213 ( L_56 , 0222 ,
V_30 -> V_533 ,
V_30 , & V_537 ) ;
F_214 ( & V_30 -> V_243 ,
F_129 ,
V_538 , V_264 ) ;
F_193 ( & V_219 ) ;
F_215 ( & V_30 -> V_539 , & V_540 ) ;
F_194 ( & V_219 ) ;
if ( V_172 > 0 )
F_190 ( V_172 , V_99 , V_399 ) ;
return V_172 ;
V_530:
F_216 ( V_30 -> V_82 ) ;
V_428:
F_217 ( V_30 -> V_82 ) ;
V_425:
F_218 ( V_51 ) ;
V_422:
return V_37 ;
}
static void F_219 ( int V_397 , const char * V_412 ,
struct V_395 * V_99 )
{
struct V_32 * V_33 ;
void * V_30 ;
int V_137 ;
V_33 = F_79 ( V_156 , V_43 ) ;
if ( ! V_33 )
return;
V_30 = F_80 ( V_33 , 0 , 0 , & V_158 , 0 ,
V_541 ) ;
if ( ! V_30 )
goto error;
V_137 = F_22 ( V_33 , V_400 , V_397 ) ;
if ( V_137 < 0 )
goto error;
V_137 = F_82 ( V_33 , V_413 , strlen ( V_412 ) ,
V_412 ) ;
if ( V_137 < 0 )
goto error;
F_84 ( V_33 , V_30 ) ;
F_185 ( V_33 , V_99 ) ;
return;
error:
F_74 ( V_33 ) ;
}
static void F_220 ( struct V_47 * V_30 ,
const char * V_412 ,
struct V_395 * V_99 )
{
F_219 ( V_30 -> V_172 , V_412 , V_99 ) ;
F_221 ( V_30 -> V_533 ) ;
F_222 ( V_30 -> V_51 ) ;
F_216 ( V_30 -> V_82 ) ;
F_217 ( V_30 -> V_82 ) ;
F_218 ( V_30 -> V_51 ) ;
}
static int F_223 ( struct V_32 * V_33 ,
struct V_47 * V_30 ,
T_1 V_26 , T_1 V_542 ,
struct V_543 * V_130 , int V_97 )
{
void * V_65 ;
struct V_398 V_399 = { } ;
int V_141 = - V_544 ;
V_65 = F_80 ( V_33 , V_26 , V_542 , & V_158 , V_97 ,
V_545 ) ;
if ( ! V_65 )
return - V_544 ;
if ( V_130 )
F_224 ( V_130 , V_65 , & V_158 ) ;
if ( V_30 -> V_532 [ 0 ] && V_30 -> V_532 [ 1 ] )
V_399 . V_402 = V_30 -> V_532 ;
V_399 . V_407 = ! ! ( V_30 -> V_51 -> V_27 -> V_525 &
V_526 ) ;
V_399 . V_409 = ! ! ( V_30 -> V_51 -> V_27 -> V_444 &
F_90 ( V_448 ) ) ;
V_399 . V_233 = V_30 -> V_233 ;
V_399 . V_404 = V_30 -> V_404 ;
V_399 . V_362 = V_30 -> V_362 ;
V_399 . V_412 = F_225 ( V_30 -> V_51 -> V_27 ) ;
V_141 = F_188 ( V_33 , V_30 -> V_172 , & V_399 ) ;
if ( V_141 < 0 )
goto V_415;
F_84 ( V_33 , V_65 ) ;
return 0 ;
V_415:
F_191 ( V_33 , V_65 ) ;
return V_141 ;
}
static void F_226 ( void )
{
struct V_47 * V_30 ;
F_193 ( & V_219 ) ;
while ( ( V_30 = F_227 ( & V_540 ,
struct V_47 ,
V_539 ) ) ) {
F_228 ( & V_30 -> V_539 ) ;
F_194 ( & V_219 ) ;
F_220 ( V_30 , F_225 ( V_30 -> V_51 -> V_27 ) ,
NULL ) ;
F_193 ( & V_219 ) ;
}
F_194 ( & V_219 ) ;
F_229 ( V_424 ) ;
}
static void F_230 ( struct V_81 * V_82 )
{
V_82 -> V_546 = & V_547 ;
V_82 -> V_548 = V_549 ;
F_231 ( V_82 ) ;
V_82 -> V_550 |= V_551 ;
V_82 -> type = V_552 ;
F_170 ( V_82 -> V_553 ) ;
V_82 -> V_553 [ 0 ] = 0x12 ;
}
static struct V_47 * F_232 ( const T_2 * V_8 )
{
struct V_47 * V_30 ;
bool V_554 = false ;
F_193 ( & V_219 ) ;
F_102 (data, &hwsim_radios, list) {
if ( memcmp ( V_30 -> V_162 [ 1 ] . V_8 , V_8 , V_58 ) == 0 ) {
V_554 = true ;
break;
}
}
F_194 ( & V_219 ) ;
if ( ! V_554 )
return NULL ;
return V_30 ;
}
static void F_233 ( struct V_20 * V_20 , T_1 V_26 )
{
struct V_47 * V_30 ;
F_16 ( V_20 , V_26 ) ;
F_193 ( & V_219 ) ;
F_102 (data, &hwsim_radios, list) {
if ( V_30 -> V_23 == F_12 ( V_20 ) )
V_30 -> V_25 = V_26 ;
}
F_194 ( & V_219 ) ;
}
static int F_234 ( struct V_32 * V_555 ,
struct V_395 * V_99 )
{
struct V_64 * V_65 ;
struct V_47 * V_198 ;
struct V_98 * V_231 ;
struct V_148 * V_149 ;
T_3 V_556 ;
struct V_32 * V_33 , * V_557 ;
const T_2 * V_558 ;
unsigned int V_146 ;
int V_147 ;
bool V_140 = false ;
if ( ! V_99 -> V_559 [ V_161 ] ||
! V_99 -> V_559 [ V_169 ] ||
! V_99 -> V_559 [ V_179 ] ||
! V_99 -> V_559 [ V_560 ] ||
! V_99 -> V_559 [ V_176 ] )
goto V_263;
V_558 = ( void * ) F_235 ( V_99 -> V_559 [ V_161 ] ) ;
V_146 = F_19 ( V_99 -> V_559 [ V_169 ] ) ;
V_556 = F_236 ( V_99 -> V_559 [ V_179 ] ) ;
V_198 = F_232 ( V_558 ) ;
if ( ! V_198 )
goto V_263;
if ( F_12 ( F_196 ( V_99 ) ) != V_198 -> V_23 )
goto V_263;
if ( V_99 -> V_431 != V_198 -> V_25 )
goto V_263;
F_237 (&data2->pending, skb, tmp) {
T_3 V_561 ;
V_231 = F_58 ( V_33 ) ;
V_561 = ( T_3 ) ( T_7 ) V_231 -> V_178 [ 0 ] ;
if ( V_561 == V_556 ) {
F_238 ( V_33 , & V_198 -> V_152 ) ;
V_140 = true ;
break;
}
}
if ( ! V_140 )
goto V_263;
V_149 = (struct V_148 * ) F_235 (
V_99 -> V_559 [ V_176 ] ) ;
V_231 = F_58 ( V_33 ) ;
F_115 ( V_231 ) ;
for ( V_147 = 0 ; V_147 < V_150 ; V_147 ++ ) {
V_231 -> V_173 . V_174 [ V_147 ] . V_172 = V_149 [ V_147 ] . V_172 ;
V_231 -> V_173 . V_174 [ V_147 ] . V_175 = V_149 [ V_147 ] . V_175 ;
}
V_231 -> V_173 . V_562 = F_19 ( V_99 -> V_559 [ V_560 ] ) ;
if ( ! ( V_146 & V_168 ) &&
( V_146 & V_563 ) ) {
if ( V_33 -> V_164 >= 16 ) {
V_65 = (struct V_64 * ) V_33 -> V_30 ;
F_67 ( V_198 -> V_171 ,
V_65 -> V_70 ) ;
}
V_231 -> V_97 |= V_242 ;
}
F_116 ( V_198 -> V_51 , V_33 ) ;
return 0 ;
V_263:
return - V_41 ;
}
static int F_239 ( struct V_32 * V_555 ,
struct V_395 * V_99 )
{
struct V_47 * V_198 ;
struct V_200 V_201 ;
const T_2 * V_564 ;
int V_565 ;
void * V_566 ;
struct V_32 * V_33 = NULL ;
if ( ! V_99 -> V_559 [ V_567 ] ||
! V_99 -> V_559 [ V_163 ] ||
! V_99 -> V_559 [ V_568 ] ||
! V_99 -> V_559 [ V_560 ] )
goto V_263;
V_564 = ( void * ) F_235 ( V_99 -> V_559 [ V_567 ] ) ;
V_565 = F_240 ( V_99 -> V_559 [ V_163 ] ) ;
V_566 = ( void * ) F_235 ( V_99 -> V_559 [ V_163 ] ) ;
V_33 = F_241 ( V_565 , V_43 ) ;
if ( V_33 == NULL )
goto V_37;
if ( V_565 > V_434 )
goto V_37;
memcpy ( F_28 ( V_33 , V_565 ) , V_566 , V_565 ) ;
V_198 = F_232 ( V_564 ) ;
if ( ! V_198 )
goto V_263;
if ( F_12 ( F_196 ( V_99 ) ) != V_198 -> V_23 )
goto V_263;
if ( V_99 -> V_431 != V_198 -> V_25 )
goto V_263;
if ( V_198 -> V_222 || ! V_198 -> V_221 )
goto V_263;
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
if ( V_99 -> V_559 [ V_170 ] ) {
F_158 ( & V_198 -> V_356 ) ;
V_201 . V_203 = F_19 ( V_99 -> V_559 [ V_170 ] ) ;
if ( V_201 . V_203 != V_198 -> V_171 -> V_118 &&
( ! V_198 -> V_223 ||
V_201 . V_203 != V_198 -> V_223 -> V_118 ) ) {
F_160 ( & V_198 -> V_356 ) ;
goto V_263;
}
F_160 ( & V_198 -> V_356 ) ;
} else {
V_201 . V_203 = V_198 -> V_171 -> V_118 ;
}
V_201 . V_204 = V_198 -> V_171 -> V_204 ;
V_201 . V_207 = F_19 ( V_99 -> V_559 [ V_568 ] ) ;
V_201 . signal = F_19 ( V_99 -> V_559 [ V_560 ] ) ;
memcpy ( F_91 ( V_33 ) , & V_201 , sizeof( V_201 ) ) ;
V_198 -> V_228 ++ ;
V_198 -> V_229 += V_33 -> V_164 ;
F_108 ( V_198 -> V_51 , V_33 ) ;
return 0 ;
V_37:
F_81 ( V_160 L_6 , V_42 ) ;
V_263:
F_47 ( V_33 ) ;
return - V_41 ;
}
static int F_242 ( struct V_32 * V_555 ,
struct V_395 * V_99 )
{
struct V_20 * V_20 = F_196 ( V_99 ) ;
struct V_47 * V_30 ;
int V_569 = 1 ;
F_193 ( & V_219 ) ;
F_102 (data, &hwsim_radios, list)
V_569 = F_243 ( V_569 , V_30 -> V_362 ) ;
F_194 ( & V_219 ) ;
if ( V_569 > 1 )
return - V_334 ;
if ( F_15 ( V_20 ) )
return - V_375 ;
F_233 ( V_20 , V_99 -> V_431 ) ;
F_81 ( V_160 L_57
L_58 , V_99 -> V_431 ) ;
return 0 ;
}
static int F_244 ( struct V_32 * V_570 , struct V_395 * V_99 )
{
struct V_398 V_399 = { 0 } ;
const char * V_412 = NULL ;
V_399 . V_407 = V_99 -> V_559 [ V_408 ] ;
V_399 . V_409 = V_99 -> V_559 [ V_410 ] ;
V_399 . V_362 = V_362 ;
V_399 . V_430 =
V_99 -> V_559 [ V_571 ] ;
if ( V_99 -> V_559 [ V_401 ] )
V_399 . V_362 = F_19 ( V_99 -> V_559 [ V_401 ] ) ;
if ( V_99 -> V_559 [ V_572 ] )
V_399 . V_528 = true ;
if ( V_99 -> V_559 [ V_413 ] ) {
V_412 = F_245 ( V_43 , L_59 ,
F_240 ( V_99 -> V_559 [ V_413 ] ) ,
( char * ) F_235 ( V_99 -> V_559 [ V_413 ] ) ) ;
if ( ! V_412 )
return - V_44 ;
V_399 . V_412 = V_412 ;
}
if ( V_99 -> V_559 [ V_411 ] )
V_399 . V_233 = true ;
else
V_399 . V_233 = ( V_399 . V_362 > 1 ) ;
if ( V_99 -> V_559 [ V_403 ] )
V_399 . V_402 =
F_235 ( V_99 -> V_559 [ V_403 ] ) ;
if ( V_99 -> V_559 [ V_406 ] ) {
T_1 V_172 = F_19 ( V_99 -> V_559 [ V_406 ] ) ;
if ( V_172 >= F_113 ( V_405 ) )
return - V_41 ;
V_399 . V_404 = V_405 [ V_172 ] ;
}
return F_192 ( V_99 , & V_399 ) ;
}
static int F_246 ( struct V_32 * V_570 , struct V_395 * V_99 )
{
struct V_47 * V_30 ;
V_93 V_172 = - 1 ;
const char * V_412 = NULL ;
if ( V_99 -> V_559 [ V_400 ] ) {
V_172 = F_19 ( V_99 -> V_559 [ V_400 ] ) ;
} else if ( V_99 -> V_559 [ V_413 ] ) {
V_412 = F_245 ( V_43 , L_59 ,
F_240 ( V_99 -> V_559 [ V_413 ] ) ,
( char * ) F_235 ( V_99 -> V_559 [ V_413 ] ) ) ;
if ( ! V_412 )
return - V_44 ;
} else
return - V_41 ;
F_193 ( & V_219 ) ;
F_102 (data, &hwsim_radios, list) {
if ( V_172 >= 0 ) {
if ( V_30 -> V_172 != V_172 )
continue;
} else {
if ( ! V_412 ||
strcmp ( V_412 , F_225 ( V_30 -> V_51 -> V_27 ) ) )
continue;
}
if ( ! F_247 ( F_248 ( V_30 -> V_51 -> V_27 ) , F_196 ( V_99 ) ) )
continue;
F_228 ( & V_30 -> V_539 ) ;
F_194 ( & V_219 ) ;
F_220 ( V_30 , F_225 ( V_30 -> V_51 -> V_27 ) ,
V_99 ) ;
F_249 ( V_412 ) ;
return 0 ;
}
F_194 ( & V_219 ) ;
F_249 ( V_412 ) ;
return - V_573 ;
}
static int F_250 ( struct V_32 * V_570 , struct V_395 * V_99 )
{
struct V_47 * V_30 ;
struct V_32 * V_33 ;
int V_172 , V_141 = - V_573 ;
if ( ! V_99 -> V_559 [ V_400 ] )
return - V_41 ;
V_172 = F_19 ( V_99 -> V_559 [ V_400 ] ) ;
F_193 ( & V_219 ) ;
F_102 (data, &hwsim_radios, list) {
if ( V_30 -> V_172 != V_172 )
continue;
if ( ! F_247 ( F_248 ( V_30 -> V_51 -> V_27 ) , F_196 ( V_99 ) ) )
continue;
V_33 = F_251 ( V_574 , V_43 ) ;
if ( ! V_33 ) {
V_141 = - V_44 ;
goto V_415;
}
V_141 = F_223 ( V_33 , V_30 , V_99 -> V_431 ,
V_99 -> V_575 , NULL , 0 ) ;
if ( V_141 < 0 ) {
F_74 ( V_33 ) ;
goto V_415;
}
F_252 ( V_33 , V_99 ) ;
break;
}
V_415:
F_194 ( & V_219 ) ;
return V_141 ;
}
static int F_253 ( struct V_32 * V_33 ,
struct V_543 * V_130 )
{
int V_172 = V_130 -> args [ 0 ] ;
struct V_47 * V_30 = NULL ;
int V_141 ;
F_193 ( & V_219 ) ;
if ( V_172 == V_420 )
goto V_576;
F_102 (data, &hwsim_radios, list) {
if ( V_30 -> V_172 < V_172 )
continue;
if ( ! F_247 ( F_248 ( V_30 -> V_51 -> V_27 ) , F_254 ( V_33 -> V_577 ) ) )
continue;
V_141 = F_223 ( V_33 , V_30 ,
F_255 ( V_130 -> V_33 ) . V_26 ,
V_130 -> V_578 -> V_579 , V_130 ,
V_580 ) ;
if ( V_141 < 0 )
break;
V_172 = V_30 -> V_172 + 1 ;
}
V_130 -> args [ 0 ] = V_172 ;
V_576:
F_194 ( & V_219 ) ;
return V_33 -> V_164 ;
}
static void F_256 ( struct V_349 * V_350 )
{
struct V_47 * V_30 =
F_130 ( V_350 , struct V_47 , V_581 ) ;
F_220 ( V_30 , F_225 ( V_30 -> V_51 -> V_27 ) , NULL ) ;
}
static void F_257 ( T_1 V_26 )
{
struct V_47 * V_582 , * V_557 ;
F_193 ( & V_219 ) ;
F_258 (entry, tmp, &hwsim_radios, list) {
if ( V_582 -> V_430 && V_582 -> V_26 == V_26 ) {
F_228 ( & V_582 -> V_539 ) ;
F_259 ( & V_582 -> V_581 , F_256 ) ;
F_260 ( & V_582 -> V_581 ) ;
}
}
F_194 ( & V_219 ) ;
}
static int F_261 ( struct V_583 * V_584 ,
unsigned long V_585 ,
void * V_586 )
{
struct V_587 * V_588 = V_586 ;
if ( V_585 != V_589 )
return V_590 ;
F_257 ( V_588 -> V_26 ) ;
if ( V_588 -> V_26 == F_15 ( V_588 -> V_20 ) ) {
F_81 ( V_591 L_60
L_61 ) ;
F_233 ( V_588 -> V_20 , 0 ) ;
}
return V_590 ;
}
static int T_9 F_262 ( void )
{
int V_592 ;
F_81 ( V_591 L_62 ) ;
V_592 = F_263 ( & V_158 ) ;
if ( V_592 )
goto V_593;
V_592 = F_264 ( & V_594 ) ;
if ( V_592 ) {
F_265 ( & V_158 ) ;
goto V_593;
}
return 0 ;
V_593:
F_81 ( V_160 L_6 , V_42 ) ;
return - V_41 ;
}
static T_10 int F_266 ( struct V_20 * V_20 )
{
F_14 ( V_20 ) ;
return 0 ;
}
static void T_11 F_267 ( struct V_20 * V_20 )
{
struct V_47 * V_30 , * V_557 ;
F_193 ( & V_219 ) ;
F_258 (data, tmp, &hwsim_radios, list) {
if ( ! F_247 ( F_248 ( V_30 -> V_51 -> V_27 ) , V_20 ) )
continue;
if ( V_30 -> V_23 == F_12 ( & V_423 ) )
continue;
F_228 ( & V_30 -> V_539 ) ;
F_259 ( & V_30 -> V_581 , F_256 ) ;
F_260 ( & V_30 -> V_581 ) ;
}
F_194 ( & V_219 ) ;
}
static void F_268 ( void )
{
F_269 ( & V_594 ) ;
F_265 ( & V_158 ) ;
}
static int T_9 F_270 ( void )
{
int V_147 , V_37 ;
if ( V_595 < 0 || V_595 > 100 )
return - V_41 ;
if ( V_362 < 1 )
return - V_41 ;
F_271 ( & V_219 ) ;
V_37 = F_272 ( & V_596 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_273 ( & V_427 ) ;
if ( V_37 )
goto V_597;
V_424 = F_274 ( V_598 , L_63 ) ;
if ( F_199 ( V_424 ) ) {
V_37 = F_200 ( V_424 ) ;
goto V_599;
}
V_37 = F_262 () ;
if ( V_37 < 0 )
goto V_599;
for ( V_147 = 0 ; V_147 < V_595 ; V_147 ++ ) {
struct V_398 V_399 = { 0 } ;
V_399 . V_362 = V_362 ;
switch ( V_600 ) {
case V_601 :
if ( V_147 < F_113 ( V_602 ) )
V_399 . V_402 = V_602 [ V_147 ] ;
break;
case V_603 :
if ( ! V_147 )
V_399 . V_402 = V_602 [ 0 ] ;
break;
case V_604 :
V_399 . V_407 = true ;
case V_605 :
V_399 . V_402 = V_602 [ 0 ] ;
break;
case V_606 :
if ( V_147 == 0 )
V_399 . V_404 = & V_607 ;
break;
case V_608 :
V_399 . V_404 = & V_607 ;
break;
case V_609 :
if ( V_147 == 0 )
V_399 . V_404 = & V_607 ;
else if ( V_147 == 1 )
V_399 . V_404 = & V_610 ;
break;
case V_611 :
if ( V_147 == 0 ) {
V_399 . V_407 = true ;
V_399 . V_402 = V_602 [ 0 ] ;
}
break;
case V_612 :
if ( V_147 == 0 ) {
V_399 . V_407 = true ;
V_399 . V_402 = V_602 [ 0 ] ;
} else if ( V_147 == 1 ) {
V_399 . V_402 = V_602 [ 1 ] ;
}
break;
case V_613 :
switch ( V_147 ) {
case 0 :
V_399 . V_404 = & V_607 ;
break;
case 1 :
V_399 . V_404 = & V_610 ;
break;
case 2 :
V_399 . V_402 = V_602 [ 0 ] ;
break;
case 3 :
V_399 . V_402 = V_602 [ 1 ] ;
break;
case 4 :
V_399 . V_407 = true ;
V_399 . V_402 = V_602 [ 2 ] ;
break;
}
break;
default:
break;
}
V_399 . V_409 = V_614 ;
V_399 . V_233 = V_362 > 1 ;
V_37 = F_192 ( NULL , & V_399 ) ;
if ( V_37 < 0 )
goto V_615;
}
V_102 = F_275 ( 0 , L_48 , V_616 ,
F_230 ) ;
if ( V_102 == NULL ) {
V_37 = - V_44 ;
goto V_615;
}
F_276 () ;
V_37 = F_277 ( V_102 , V_102 -> V_617 ) ;
if ( V_37 < 0 ) {
F_278 () ;
goto V_615;
}
V_37 = F_279 ( V_102 ) ;
if ( V_37 < 0 ) {
F_278 () ;
goto V_618;
}
F_278 () ;
return 0 ;
V_618:
V_549 ( V_102 ) ;
V_615:
F_226 () ;
V_599:
F_280 ( & V_427 ) ;
V_597:
F_281 ( & V_596 ) ;
return V_37 ;
}
static void T_12 F_282 ( void )
{
F_81 ( V_160 L_64 ) ;
F_268 () ;
F_226 () ;
F_283 ( V_102 ) ;
F_280 ( & V_427 ) ;
F_281 ( & V_596 ) ;
}
