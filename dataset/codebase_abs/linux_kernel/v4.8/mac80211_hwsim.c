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
V_30 -> V_92 = - F_56 ( V_91 , V_89 ) ;
}
}
static void F_57 ( struct V_86 * V_51 ,
struct V_32 * V_93 ,
struct V_94 * V_62 )
{
struct V_47 * V_30 = V_51 -> V_87 ;
struct V_32 * V_33 ;
struct V_95 * V_65 ;
T_6 V_96 ;
struct V_97 * V_98 = F_58 ( V_93 ) ;
struct V_99 * V_100 = F_59 ( V_51 , V_98 ) ;
if ( F_6 ( ! V_100 ) )
return;
if ( ! F_60 ( V_101 ) )
return;
V_33 = F_61 ( V_93 , sizeof( * V_65 ) , 0 , V_102 ) ;
if ( V_33 == NULL )
return;
V_65 = (struct V_95 * ) F_62 ( V_33 , sizeof( * V_65 ) ) ;
V_65 -> V_65 . V_103 = V_104 ;
V_65 -> V_65 . V_105 = 0 ;
V_65 -> V_65 . V_106 = F_29 ( sizeof( * V_65 ) ) ;
V_65 -> V_65 . V_107 = F_63 ( ( 1 << V_108 ) |
( 1 << V_109 ) |
( 1 << V_110 ) |
( 1 << V_111 ) ) ;
V_65 -> V_112 = F_51 ( V_30 ) ;
V_65 -> V_113 = 0 ;
V_65 -> V_114 = V_100 -> V_115 / 5 ;
V_65 -> V_116 = F_29 ( V_62 -> V_117 ) ;
V_96 = V_118 ;
if ( V_100 -> V_96 & V_119 )
V_96 |= V_120 ;
else
V_96 |= V_121 ;
V_65 -> V_122 = F_29 ( V_96 ) ;
V_33 -> V_82 = V_101 ;
F_64 ( V_33 ) ;
V_33 -> V_123 = V_124 ;
V_33 -> V_125 = V_126 ;
V_33 -> V_127 = F_65 ( V_128 ) ;
memset ( V_33 -> V_129 , 0 , sizeof( V_33 -> V_129 ) ) ;
F_66 ( V_33 ) ;
}
static void F_67 ( struct V_94 * V_62 ,
const T_2 * V_8 )
{
struct V_32 * V_33 ;
struct V_130 * V_65 ;
T_6 V_96 ;
struct V_64 * V_131 ;
if ( ! F_60 ( V_101 ) )
return;
V_33 = F_27 ( 100 ) ;
if ( V_33 == NULL )
return;
V_65 = (struct V_130 * ) F_28 ( V_33 , sizeof( * V_65 ) ) ;
V_65 -> V_65 . V_103 = V_104 ;
V_65 -> V_65 . V_105 = 0 ;
V_65 -> V_65 . V_106 = F_29 ( sizeof( * V_65 ) ) ;
V_65 -> V_65 . V_107 = F_63 ( ( 1 << V_108 ) |
( 1 << V_111 ) ) ;
V_65 -> V_113 = 0 ;
V_65 -> V_132 = 0 ;
V_65 -> V_116 = F_29 ( V_62 -> V_117 ) ;
V_96 = V_118 ;
V_65 -> V_122 = F_29 ( V_96 ) ;
V_131 = (struct V_64 * ) F_28 ( V_33 , 10 ) ;
V_131 -> V_54 = F_29 ( V_55 |
V_133 ) ;
V_131 -> V_68 = F_29 ( 0 ) ;
memcpy ( V_131 -> V_69 , V_8 , V_58 ) ;
V_33 -> V_82 = V_101 ;
F_64 ( V_33 ) ;
V_33 -> V_123 = V_124 ;
V_33 -> V_125 = V_126 ;
V_33 -> V_127 = F_65 ( V_128 ) ;
memset ( V_33 -> V_129 , 0 , sizeof( V_33 -> V_129 ) ) ;
F_66 ( V_33 ) ;
}
static void F_68 ( void * V_30 , T_2 * V_46 ,
struct V_1 * V_2 )
{
struct V_134 * V_135 = V_30 ;
if ( memcmp ( V_46 , V_135 -> V_8 , V_58 ) == 0 )
V_135 -> V_136 = true ;
}
static bool F_69 ( struct V_47 * V_30 ,
const T_2 * V_8 )
{
struct V_134 V_135 = {
. V_136 = false ,
} ;
if ( V_30 -> V_137 && memcmp ( V_8 , V_30 -> V_138 , V_58 ) == 0 )
return true ;
memcpy ( V_135 . V_8 , V_8 , V_58 ) ;
F_40 ( V_30 -> V_51 ,
V_78 ,
F_68 ,
& V_135 ) ;
return V_135 . V_136 ;
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
bool V_139 = false ;
int V_140 = - V_141 ;
F_30 () ;
F_72 (net) {
if ( V_30 -> V_23 == F_12 ( V_20 ) ) {
V_140 = F_73 ( V_20 , V_33 , V_26 ) ;
V_139 = true ;
break;
}
}
F_33 () ;
if ( ! V_139 )
F_74 ( V_33 ) ;
return V_140 ;
}
static void F_75 ( struct V_86 * V_51 ,
struct V_32 * V_142 ,
int V_143 )
{
struct V_32 * V_33 ;
struct V_47 * V_30 = V_51 -> V_87 ;
struct V_64 * V_65 = (struct V_64 * ) V_142 -> V_30 ;
struct V_97 * V_98 = F_58 ( V_142 ) ;
void * V_144 ;
unsigned int V_145 = 0 ;
int V_146 ;
struct V_147 V_148 [ V_149 ] ;
T_7 V_150 ;
if ( V_30 -> V_63 != V_74 )
V_65 -> V_54 |= F_29 ( V_57 ) ;
if ( F_76 ( & V_30 -> V_151 ) >= V_152 ) {
while ( F_76 ( & V_30 -> V_151 ) >= V_153 ) {
F_77 ( V_51 , F_78 ( & V_30 -> V_151 ) ) ;
V_30 -> V_154 ++ ;
}
}
V_33 = F_79 ( V_155 , V_102 ) ;
if ( V_33 == NULL )
goto V_156;
V_144 = F_80 ( V_33 , 0 , 0 , & V_157 , 0 ,
V_158 ) ;
if ( V_144 == NULL ) {
F_81 ( V_159 L_5 ) ;
goto V_156;
}
if ( F_82 ( V_33 , V_160 ,
V_58 , V_30 -> V_161 [ 1 ] . V_8 ) )
goto V_156;
if ( F_82 ( V_33 , V_162 , V_142 -> V_163 , V_142 -> V_30 ) )
goto V_156;
if ( V_98 -> V_96 & V_164 )
V_145 |= V_165 ;
if ( V_98 -> V_96 & V_166 )
V_145 |= V_167 ;
if ( F_22 ( V_33 , V_168 , V_145 ) )
goto V_156;
if ( F_22 ( V_33 , V_169 , V_30 -> V_170 -> V_117 ) )
goto V_156;
for ( V_146 = 0 ; V_146 < V_149 ; V_146 ++ ) {
V_148 [ V_146 ] . V_171 = V_98 -> V_172 . V_173 [ V_146 ] . V_171 ;
V_148 [ V_146 ] . V_174 = V_98 -> V_172 . V_173 [ V_146 ] . V_174 ;
}
if ( F_82 ( V_33 , V_175 ,
sizeof( struct V_147 ) * V_149 ,
V_148 ) )
goto V_156;
V_30 -> V_176 ++ ;
V_150 = V_30 -> V_176 ;
V_98 -> V_177 [ 0 ] = ( void * ) V_150 ;
if ( F_83 ( V_33 , V_178 , V_150 , V_179 ) )
goto V_156;
F_84 ( V_33 , V_144 ) ;
if ( F_71 ( V_30 , V_33 , V_143 ) )
goto V_180;
F_85 ( & V_30 -> V_151 , V_142 ) ;
V_30 -> V_181 ++ ;
V_30 -> V_182 += V_142 -> V_163 ;
return;
V_156:
F_74 ( V_33 ) ;
V_180:
F_81 ( V_159 L_6 , V_42 ) ;
F_77 ( V_51 , V_142 ) ;
V_30 -> V_183 ++ ;
}
static bool F_86 ( struct V_94 * V_184 ,
struct V_94 * V_185 )
{
if ( ! V_184 || ! V_185 )
return false ;
return V_184 -> V_117 == V_185 -> V_117 ;
}
static void F_87 ( void * V_186 , T_2 * V_8 ,
struct V_1 * V_2 )
{
struct V_187 * V_30 = V_186 ;
if ( ! V_2 -> V_60 )
return;
if ( ! F_86 ( V_30 -> V_170 ,
F_32 ( V_2 -> V_60 ) -> V_61 . V_62 ) )
return;
V_30 -> V_188 = true ;
}
static void F_88 ( struct V_32 * V_33 )
{
#ifdef F_89
struct V_189 * V_190 ;
V_190 = ( void * ) F_62 ( V_33 , sizeof( * V_190 ) + 8 + 4 ) ;
V_190 -> V_191 [ 0 ] = F_89 [ 0 ] ;
V_190 -> V_191 [ 1 ] = F_89 [ 1 ] ;
V_190 -> V_191 [ 2 ] = F_89 [ 2 ] ;
V_190 -> V_192 = 127 ;
V_190 -> V_193 = F_90 ( 0 ) ;
V_190 -> V_163 = 8 ;
V_190 -> V_194 = 8 ;
V_190 -> V_132 = 4 ;
memcpy ( V_190 -> V_30 , L_7 , 8 ) ;
memset ( V_190 -> V_30 + 8 , 0 , 4 ) ;
F_91 ( V_33 ) -> V_195 |= V_196 ;
#endif
}
static bool F_92 ( struct V_86 * V_51 ,
struct V_32 * V_33 ,
struct V_94 * V_62 )
{
struct V_47 * V_30 = V_51 -> V_87 , * V_197 ;
bool V_198 = false ;
struct V_64 * V_65 = (struct V_64 * ) V_33 -> V_30 ;
struct V_97 * V_98 = F_58 ( V_33 ) ;
struct V_199 V_200 ;
T_3 V_84 ;
memset ( & V_200 , 0 , sizeof( V_200 ) ) ;
V_200 . V_195 |= V_201 ;
V_200 . V_202 = V_62 -> V_117 ;
V_200 . V_203 = V_62 -> V_203 ;
if ( V_98 -> V_204 . V_173 [ 0 ] . V_96 & V_205 ) {
V_200 . V_206 =
F_93 ( & V_98 -> V_204 . V_173 [ 0 ] ) ;
V_200 . V_207 =
F_94 ( & V_98 -> V_204 . V_173 [ 0 ] ) ;
V_200 . V_195 |= V_208 ;
} else {
V_200 . V_206 = V_98 -> V_204 . V_173 [ 0 ] . V_171 ;
if ( V_98 -> V_204 . V_173 [ 0 ] . V_96 & V_209 )
V_200 . V_195 |= V_210 ;
}
if ( V_98 -> V_204 . V_173 [ 0 ] . V_96 & V_211 )
V_200 . V_195 |= V_212 ;
if ( V_98 -> V_204 . V_173 [ 0 ] . V_96 & V_213 )
V_200 . V_195 |= V_214 ;
V_200 . signal = V_30 -> V_215 - 50 ;
if ( V_30 -> V_63 != V_74 )
V_65 -> V_54 |= F_29 ( V_57 ) ;
F_95 ( V_33 ) ;
F_96 ( V_33 ) ;
V_33 -> V_216 = 0 ;
F_97 ( V_33 ) ;
F_98 ( V_33 ) ;
if ( F_99 ( V_65 -> V_54 ) ||
F_100 ( V_65 -> V_54 ) )
V_84 = V_30 -> V_217 ;
else
V_84 = F_48 () ;
F_101 ( & V_218 ) ;
F_102 (data2, &hwsim_radios, list) {
struct V_32 * V_219 ;
struct V_187 V_187 = {
. V_188 = false ,
. V_170 = V_62 ,
} ;
if ( V_30 == V_197 )
continue;
if ( ! V_197 -> V_220 || ( V_197 -> V_221 && ! V_197 -> V_222 ) ||
! F_70 ( V_197 , V_33 ) )
continue;
if ( ! ( V_30 -> V_80 & V_197 -> V_80 ) )
continue;
if ( V_30 -> V_23 != V_197 -> V_23 )
continue;
if ( ! F_86 ( V_62 , V_197 -> V_222 ) &&
! F_86 ( V_62 , V_197 -> V_170 ) ) {
F_40 (
V_197 -> V_51 , V_78 ,
F_87 , & V_187 ) ;
if ( ! V_187 . V_188 )
continue;
}
if ( V_33 -> V_163 < V_223 && V_224 ) {
struct V_225 * V_225 = F_103 ( V_102 ) ;
if ( ! V_225 )
continue;
V_219 = F_27 ( 128 ) ;
if ( ! V_219 ) {
F_104 ( V_225 ) ;
continue;
}
memcpy ( F_105 ( V_225 ) , V_33 -> V_30 , V_33 -> V_163 ) ;
F_106 ( V_219 , 0 , V_225 , 0 , V_33 -> V_163 , V_33 -> V_163 ) ;
} else {
V_219 = F_107 ( V_33 , V_102 ) ;
if ( ! V_219 )
continue;
}
if ( F_69 ( V_197 , V_65 -> V_69 ) )
V_198 = true ;
V_200 . V_226 = V_84 + V_197 -> V_85 ;
memcpy ( F_91 ( V_219 ) , & V_200 , sizeof( V_200 ) ) ;
F_88 ( V_219 ) ;
V_197 -> V_227 ++ ;
V_197 -> V_228 += V_219 -> V_163 ;
F_108 ( V_197 -> V_51 , V_219 ) ;
}
F_109 ( & V_218 ) ;
return V_198 ;
}
static void F_110 ( struct V_86 * V_51 ,
struct V_229 * V_204 ,
struct V_32 * V_33 )
{
struct V_47 * V_30 = V_51 -> V_87 ;
struct V_97 * V_230 = F_58 ( V_33 ) ;
struct V_64 * V_65 = ( void * ) V_33 -> V_30 ;
struct V_15 * V_60 ;
struct V_94 * V_170 ;
bool V_198 ;
T_1 V_231 ;
if ( F_6 ( V_33 -> V_163 < 10 ) ) {
F_77 ( V_51 , V_33 ) ;
return;
}
if ( ! V_30 -> V_232 ) {
V_170 = V_30 -> V_170 ;
} else if ( V_230 -> V_233 == 4 ) {
V_170 = V_30 -> V_222 ;
} else {
V_60 = F_32 ( V_230 -> V_204 . V_2 -> V_60 ) ;
if ( V_60 )
V_170 = V_60 -> V_61 . V_62 ;
else
V_170 = NULL ;
}
if ( F_2 ( ! V_170 , L_8 , V_230 -> V_233 ) ) {
F_77 ( V_51 , V_33 ) ;
return;
}
if ( V_30 -> V_221 && ! V_30 -> V_222 ) {
F_20 ( V_51 -> V_27 , L_9 ) ;
F_77 ( V_51 , V_33 ) ;
return;
}
if ( V_230 -> V_204 . V_2 )
F_1 ( V_230 -> V_204 . V_2 ) ;
if ( V_204 -> V_11 )
F_5 ( V_204 -> V_11 ) ;
if ( F_111 ( V_51 , V_234 ) )
F_112 ( V_230 -> V_204 . V_2 , V_204 -> V_11 , V_33 ,
V_230 -> V_204 . V_173 ,
F_113 ( V_230 -> V_204 . V_173 ) ) ;
V_230 -> V_177 [ 0 ] = V_170 ;
if ( V_33 -> V_163 >= 24 + 8 &&
F_100 ( V_65 -> V_54 ) ) {
struct V_235 * V_236 ;
struct V_99 * V_100 ;
T_3 V_237 ;
V_236 = (struct V_235 * ) V_33 -> V_30 ;
V_100 = F_59 ( V_51 , V_230 ) ;
V_237 = F_48 () ;
V_236 -> V_238 . V_239 . V_240 =
F_52 ( V_237 + V_30 -> V_85 +
24 * 8 * 10 / V_100 -> V_115 ) ;
}
F_57 ( V_51 , V_33 , V_170 ) ;
V_231 = F_114 ( V_30 -> V_25 ) ;
if ( V_231 )
return F_75 ( V_51 , V_33 , V_231 ) ;
V_30 -> V_181 ++ ;
V_30 -> V_182 += V_33 -> V_163 ;
V_198 = F_92 ( V_51 , V_33 , V_170 ) ;
if ( V_198 && V_33 -> V_163 >= 16 )
F_67 ( V_170 , V_65 -> V_70 ) ;
F_115 ( V_230 ) ;
V_230 -> V_204 . V_173 [ 0 ] . V_174 = 1 ;
V_230 -> V_204 . V_173 [ 1 ] . V_171 = - 1 ;
if ( ! ( V_230 -> V_96 & V_166 ) && V_198 )
V_230 -> V_96 |= V_241 ;
F_116 ( V_51 , V_33 ) ;
}
static int F_117 ( struct V_86 * V_51 )
{
struct V_47 * V_30 = V_51 -> V_87 ;
F_20 ( V_51 -> V_27 , L_10 , V_42 ) ;
V_30 -> V_220 = true ;
return 0 ;
}
static void F_118 ( struct V_86 * V_51 )
{
struct V_47 * V_30 = V_51 -> V_87 ;
V_30 -> V_220 = false ;
F_119 ( & V_30 -> V_242 ) ;
F_20 ( V_51 -> V_27 , L_10 , V_42 ) ;
}
static int F_120 ( struct V_86 * V_51 ,
struct V_1 * V_2 )
{
F_20 ( V_51 -> V_27 , L_11 ,
V_42 , F_121 ( V_2 ) ,
V_2 -> V_8 ) ;
F_3 ( V_2 ) ;
V_2 -> V_243 = 0 ;
V_2 -> V_233 [ V_244 ] = 0 ;
V_2 -> V_233 [ V_245 ] = 1 ;
V_2 -> V_233 [ V_246 ] = 2 ;
V_2 -> V_233 [ V_247 ] = 3 ;
return 0 ;
}
static int F_122 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
enum V_248 V_249 ,
bool V_250 )
{
V_249 = F_123 ( V_249 , V_250 ) ;
F_20 ( V_51 -> V_27 ,
L_12 ,
V_42 , F_121 ( V_2 ) ,
V_249 , V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
V_2 -> V_243 = 0 ;
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
struct V_94 * V_62 )
{
struct V_47 * V_30 = V_51 -> V_87 ;
T_1 V_251 = F_114 ( V_30 -> V_25 ) ;
if ( F_111 ( V_51 , V_234 ) ) {
struct V_97 * V_230 = F_58 ( V_33 ) ;
F_112 ( V_230 -> V_204 . V_2 , NULL , V_33 ,
V_230 -> V_204 . V_173 ,
F_113 ( V_230 -> V_204 . V_173 ) ) ;
}
F_57 ( V_51 , V_33 , V_62 ) ;
if ( V_251 )
return F_75 ( V_51 , V_33 , V_251 ) ;
F_92 ( V_51 , V_33 , V_62 ) ;
F_47 ( V_33 ) ;
}
static void F_125 ( void * V_252 , T_2 * V_46 ,
struct V_1 * V_2 )
{
struct V_47 * V_30 = V_252 ;
struct V_86 * V_51 = V_30 -> V_51 ;
struct V_97 * V_98 ;
struct V_99 * V_100 ;
struct V_235 * V_236 ;
struct V_32 * V_33 ;
F_1 ( V_2 ) ;
if ( V_2 -> type != V_253 &&
V_2 -> type != V_254 &&
V_2 -> type != V_255 )
return;
V_33 = F_126 ( V_51 , V_2 ) ;
if ( V_33 == NULL )
return;
V_98 = F_58 ( V_33 ) ;
if ( F_111 ( V_51 , V_234 ) )
F_112 ( V_2 , NULL , V_33 ,
V_98 -> V_204 . V_173 ,
F_113 ( V_98 -> V_204 . V_173 ) ) ;
V_100 = F_59 ( V_51 , V_98 ) ;
V_236 = (struct V_235 * ) V_33 -> V_30 ;
V_30 -> V_217 = F_48 () ;
V_236 -> V_238 . V_256 . V_240 = F_52 ( V_30 -> V_217 +
V_30 -> V_85 +
24 * 8 * 10 / V_100 -> V_115 ) ;
F_31 ( V_51 , V_33 ,
F_32 ( V_2 -> V_60 ) -> V_61 . V_62 ) ;
if ( V_2 -> V_257 && F_127 ( V_2 ) )
F_128 ( V_2 ) ;
}
static enum V_258
F_129 ( struct V_259 * V_260 )
{
struct V_47 * V_30 =
F_130 ( V_260 , struct V_47 ,
V_242 . V_260 ) ;
struct V_86 * V_51 = V_30 -> V_51 ;
T_3 V_89 = V_30 -> V_90 ;
T_8 V_261 ;
if ( ! V_30 -> V_220 )
goto V_262;
F_40 (
V_51 , V_78 ,
F_125 , V_30 ) ;
if ( V_30 -> V_92 ) {
V_89 -= V_30 -> V_92 ;
V_30 -> V_92 = 0 ;
}
V_261 = F_131 ( F_132 ( V_260 ) ,
F_133 ( V_89 * 1000 ) ) ;
F_134 ( & V_30 -> V_242 , V_261 , V_263 ) ;
V_262:
return V_264 ;
}
static int F_135 ( struct V_86 * V_51 , T_1 V_265 )
{
struct V_47 * V_30 = V_51 -> V_87 ;
struct V_266 * V_267 = & V_51 -> V_267 ;
static const char * V_268 [ V_269 ] = {
[ V_270 ] = L_13 ,
[ V_271 ] = L_14 ,
[ V_272 ] = L_15 ,
[ V_273 ] = L_16 ,
} ;
if ( V_267 -> V_274 . V_62 )
F_20 ( V_51 -> V_27 ,
L_17 ,
V_42 ,
V_267 -> V_274 . V_62 -> V_117 ,
V_267 -> V_274 . V_275 ,
V_267 -> V_274 . V_276 ,
V_277 [ V_267 -> V_274 . V_278 ] ,
! ! ( V_267 -> V_96 & V_279 ) ,
! ! ( V_267 -> V_96 & V_280 ) ,
V_268 [ V_267 -> V_281 ] ) ;
else
F_20 ( V_51 -> V_27 ,
L_18 ,
V_42 ,
! ! ( V_267 -> V_96 & V_279 ) ,
! ! ( V_267 -> V_96 & V_280 ) ,
V_268 [ V_267 -> V_281 ] ) ;
V_30 -> V_221 = ! ! ( V_267 -> V_96 & V_279 ) ;
V_30 -> V_170 = V_267 -> V_274 . V_62 ;
F_6 ( V_30 -> V_170 && V_30 -> V_232 ) ;
V_30 -> V_215 = V_267 -> V_215 ;
if ( ! V_30 -> V_220 || ! V_30 -> V_90 )
F_119 ( & V_30 -> V_242 ) ;
else if ( ! F_136 ( & V_30 -> V_242 . V_260 ) ) {
T_3 V_88 = F_53 ( V_51 , NULL ) ;
T_1 V_89 = V_30 -> V_90 ;
T_3 V_282 = V_89 - F_56 ( V_88 , V_89 ) ;
F_134 ( & V_30 -> V_242 ,
F_133 ( V_282 * 1000 ) ,
V_283 ) ;
}
return 0 ;
}
static void F_137 ( struct V_86 * V_51 ,
unsigned int V_284 ,
unsigned int * V_285 , T_3 V_286 )
{
struct V_47 * V_30 = V_51 -> V_87 ;
F_20 ( V_51 -> V_27 , L_10 , V_42 ) ;
V_30 -> V_287 = 0 ;
if ( * V_285 & V_288 )
V_30 -> V_287 |= V_288 ;
* V_285 = V_30 -> V_287 ;
}
static void F_138 ( void * V_30 , T_2 * V_46 ,
struct V_1 * V_2 )
{
unsigned int * V_174 = V_30 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
if ( V_4 -> V_289 )
( * V_174 ) ++ ;
}
static void F_139 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_290 * V_98 ,
T_1 V_265 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_47 * V_30 = V_51 -> V_87 ;
F_1 ( V_2 ) ;
F_20 ( V_51 -> V_27 , L_19 ,
V_42 , V_265 , V_2 -> V_8 ) ;
if ( V_265 & V_291 ) {
F_20 ( V_51 -> V_27 , L_20 ,
V_42 , V_98 -> V_52 ) ;
memcpy ( V_4 -> V_52 , V_98 -> V_52 , V_58 ) ;
}
if ( V_265 & V_292 ) {
F_20 ( V_51 -> V_27 , L_21 ,
V_98 -> V_50 , V_98 -> V_53 ) ;
V_4 -> V_50 = V_98 -> V_50 ;
V_4 -> V_53 = V_98 -> V_53 ;
}
if ( V_265 & V_293 ) {
F_20 ( V_51 -> V_27 , L_22 ,
V_98 -> V_294 , V_98 -> V_90 ) ;
V_4 -> V_289 = V_98 -> V_294 ;
if ( V_30 -> V_220 &&
! F_136 ( & V_30 -> V_242 . V_260 ) &&
V_98 -> V_294 ) {
T_3 V_88 , V_282 ;
T_1 V_89 ;
V_30 -> V_90 = V_98 -> V_90 * 1024 ;
V_88 = F_53 ( V_51 , V_2 ) ;
V_89 = V_30 -> V_90 ;
V_282 = V_89 - F_56 ( V_88 , V_89 ) ;
F_134 ( & V_30 -> V_242 ,
F_133 ( V_282 * 1000 ) ,
V_283 ) ;
} else if ( ! V_98 -> V_294 ) {
unsigned int V_174 = 0 ;
F_40 (
V_30 -> V_51 , V_78 ,
F_138 , & V_174 ) ;
F_20 ( V_51 -> V_27 , L_23 ,
V_174 ) ;
if ( V_174 == 0 ) {
F_119 ( & V_30 -> V_242 ) ;
V_30 -> V_90 = 0 ;
}
}
}
if ( V_265 & V_295 ) {
F_20 ( V_51 -> V_27 , L_24 ,
V_98 -> V_296 ) ;
}
if ( V_265 & V_297 ) {
F_20 ( V_51 -> V_27 , L_25 ,
V_98 -> V_298 ) ;
}
if ( V_265 & V_299 ) {
F_20 ( V_51 -> V_27 , L_26 , V_98 -> V_300 ) ;
}
if ( V_265 & V_301 ) {
F_20 ( V_51 -> V_27 , L_27 ,
V_98 -> V_302 ) ;
}
if ( V_265 & V_303 ) {
F_20 ( V_51 -> V_27 , L_28 ,
( unsigned long long ) V_98 -> V_304 ) ;
}
if ( V_265 & V_305 )
F_20 ( V_51 -> V_27 , L_29 , V_98 -> V_306 ) ;
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
enum V_307 V_308 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
switch ( V_308 ) {
case V_309 :
case V_310 :
break;
default:
F_2 ( 1 , L_30 , V_308 ) ;
break;
}
}
static int F_143 ( struct V_86 * V_51 ,
struct V_10 * V_11 ,
bool V_311 )
{
F_5 ( V_11 ) ;
return 0 ;
}
static int F_144 (
struct V_86 * V_51 ,
struct V_1 * V_2 , T_6 V_312 ,
const struct V_313 * V_314 )
{
F_20 ( V_51 -> V_27 ,
L_31 ,
V_42 , V_312 ,
V_314 -> V_315 , V_314 -> V_316 ,
V_314 -> V_317 , V_314 -> V_318 ) ;
return 0 ;
}
static int F_145 (
struct V_86 * V_51 , int V_171 ,
struct V_319 * V_320 )
{
struct V_266 * V_267 = & V_51 -> V_267 ;
F_20 ( V_51 -> V_27 , L_32 , V_42 , V_171 ) ;
if ( V_171 != 0 )
return - V_141 ;
V_320 -> V_170 = V_267 -> V_274 . V_62 ;
V_320 -> V_321 = V_322 ;
V_320 -> V_323 = - 92 ;
return 0 ;
}
static int F_146 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
void * V_30 , int V_163 )
{
struct V_47 * V_324 = V_51 -> V_87 ;
struct V_34 * V_35 [ V_325 + 1 ] ;
struct V_32 * V_33 ;
int V_37 , V_63 ;
V_37 = F_18 ( V_35 , V_325 , V_30 , V_163 ,
V_326 ) ;
if ( V_37 )
return V_37 ;
if ( ! V_35 [ V_327 ] )
return - V_41 ;
switch ( F_19 ( V_35 [ V_327 ] ) ) {
case V_328 :
if ( ! V_35 [ V_329 ] )
return - V_41 ;
V_63 = F_19 ( V_35 [ V_329 ] ) ;
return F_38 ( V_324 , V_63 ) ;
case V_330 :
V_33 = F_147 ( V_51 -> V_27 ,
F_148 ( sizeof( T_1 ) ) ) ;
if ( ! V_33 )
return - V_44 ;
if ( F_22 ( V_33 , V_329 , V_324 -> V_63 ) )
goto V_156;
return F_149 ( V_33 ) ;
case V_331 :
F_150 ( V_51 ) ;
return 0 ;
case V_332 :
F_151 ( V_51 ) ;
return 0 ;
default:
return - V_333 ;
}
V_156:
F_152 ( V_33 ) ;
return - V_334 ;
}
static int F_153 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_335 * V_314 )
{
struct V_10 * V_11 = V_314 -> V_11 ;
enum V_336 V_337 = V_314 -> V_337 ;
T_6 V_338 = V_314 -> V_338 ;
switch ( V_337 ) {
case V_339 :
F_154 ( V_2 , V_11 -> V_8 , V_338 ) ;
break;
case V_340 :
case V_341 :
case V_342 :
F_155 ( V_2 , V_11 -> V_8 , V_338 ) ;
break;
case V_343 :
break;
case V_344 :
case V_345 :
break;
default:
return - V_333 ;
}
return 0 ;
}
static void F_156 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
T_1 V_346 , bool V_347 )
{
}
static void F_157 ( struct V_348 * V_349 )
{
struct V_47 * V_324 =
F_130 ( V_349 , struct V_47 , V_350 . V_349 ) ;
struct V_351 * V_352 = V_324 -> V_353 ;
int V_354 , V_146 ;
F_158 ( & V_324 -> V_355 ) ;
if ( V_324 -> V_356 >= V_352 -> V_357 ) {
struct V_358 V_98 = {
. V_359 = false ,
} ;
F_20 ( V_324 -> V_51 -> V_27 , L_33 ) ;
F_159 ( V_324 -> V_51 , & V_98 ) ;
V_324 -> V_353 = NULL ;
V_324 -> V_360 = NULL ;
V_324 -> V_222 = NULL ;
F_160 ( & V_324 -> V_355 ) ;
return;
}
F_20 ( V_324 -> V_51 -> V_27 , L_34 ,
V_352 -> V_361 [ V_324 -> V_356 ] -> V_117 ) ;
V_324 -> V_222 = V_352 -> V_361 [ V_324 -> V_356 ] ;
if ( V_324 -> V_222 -> V_96 & ( V_362 |
V_363 ) ||
! V_352 -> V_364 ) {
V_354 = 120 ;
} else {
V_354 = 30 ;
for ( V_146 = 0 ; V_146 < V_352 -> V_364 ; V_146 ++ ) {
struct V_32 * V_365 ;
struct V_235 * V_236 ;
V_365 = F_161 ( V_324 -> V_51 ,
V_324 -> V_138 ,
V_352 -> V_366 [ V_146 ] . V_367 ,
V_352 -> V_366 [ V_146 ] . V_368 ,
V_352 -> V_369 ) ;
if ( ! V_365 )
continue;
V_236 = (struct V_235 * ) V_365 -> V_30 ;
memcpy ( V_236 -> V_370 , V_352 -> V_52 , V_58 ) ;
memcpy ( V_236 -> V_52 , V_352 -> V_52 , V_58 ) ;
if ( V_352 -> V_369 )
memcpy ( F_28 ( V_365 , V_352 -> V_369 ) , V_352 -> V_371 ,
V_352 -> V_369 ) ;
F_39 () ;
F_31 ( V_324 -> V_51 , V_365 ,
V_324 -> V_222 ) ;
F_41 () ;
}
}
F_162 ( V_324 -> V_51 , & V_324 -> V_350 ,
F_163 ( V_354 ) ) ;
V_324 -> V_356 ++ ;
F_160 ( & V_324 -> V_355 ) ;
}
static int F_164 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_372 * V_373 )
{
struct V_47 * V_324 = V_51 -> V_87 ;
struct V_351 * V_352 = & V_373 -> V_352 ;
F_158 ( & V_324 -> V_355 ) ;
if ( F_6 ( V_324 -> V_222 || V_324 -> V_353 ) ) {
F_160 ( & V_324 -> V_355 ) ;
return - V_374 ;
}
V_324 -> V_353 = V_352 ;
V_324 -> V_360 = V_2 ;
V_324 -> V_356 = 0 ;
if ( V_352 -> V_96 & V_375 )
F_165 ( V_324 -> V_138 ,
V_373 -> V_352 . V_376 ,
V_373 -> V_352 . V_377 ) ;
else
memcpy ( V_324 -> V_138 , V_2 -> V_8 , V_58 ) ;
F_160 ( & V_324 -> V_355 ) ;
F_20 ( V_51 -> V_27 , L_35 ) ;
F_162 ( V_324 -> V_51 , & V_324 -> V_350 , 0 ) ;
return 0 ;
}
static void F_166 ( struct V_86 * V_51 ,
struct V_1 * V_2 )
{
struct V_47 * V_324 = V_51 -> V_87 ;
struct V_358 V_98 = {
. V_359 = true ,
} ;
F_20 ( V_51 -> V_27 , L_36 ) ;
F_167 ( & V_324 -> V_350 ) ;
F_158 ( & V_324 -> V_355 ) ;
F_159 ( V_324 -> V_51 , & V_98 ) ;
V_324 -> V_222 = NULL ;
V_324 -> V_353 = NULL ;
V_324 -> V_360 = NULL ;
F_160 ( & V_324 -> V_355 ) ;
}
static void F_168 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
const T_2 * V_376 )
{
struct V_47 * V_324 = V_51 -> V_87 ;
F_158 ( & V_324 -> V_355 ) ;
if ( V_324 -> V_137 ) {
F_81 ( V_159 L_37 ) ;
goto V_262;
}
F_81 ( V_159 L_38 ) ;
memcpy ( V_324 -> V_138 , V_376 , V_58 ) ;
V_324 -> V_137 = true ;
V_262:
F_160 ( & V_324 -> V_355 ) ;
}
static void F_169 ( struct V_86 * V_51 ,
struct V_1 * V_2 )
{
struct V_47 * V_324 = V_51 -> V_87 ;
F_158 ( & V_324 -> V_355 ) ;
F_81 ( V_159 L_39 ) ;
V_324 -> V_137 = false ;
F_170 ( V_324 -> V_138 ) ;
F_160 ( & V_324 -> V_355 ) ;
}
static void F_171 ( struct V_348 * V_349 )
{
struct V_47 * V_324 =
F_130 ( V_349 , struct V_47 , V_378 . V_349 ) ;
F_158 ( & V_324 -> V_355 ) ;
F_20 ( V_324 -> V_51 -> V_27 , L_40 ) ;
V_324 -> V_222 = V_324 -> V_379 ;
F_172 ( V_324 -> V_51 ) ;
F_162 ( V_324 -> V_51 , & V_324 -> V_380 ,
F_163 ( V_324 -> V_381 ) ) ;
F_160 ( & V_324 -> V_355 ) ;
}
static void F_173 ( struct V_348 * V_349 )
{
struct V_47 * V_324 =
F_130 ( V_349 , struct V_47 , V_380 . V_349 ) ;
F_158 ( & V_324 -> V_355 ) ;
F_174 ( V_324 -> V_51 ) ;
V_324 -> V_222 = NULL ;
F_160 ( & V_324 -> V_355 ) ;
F_20 ( V_324 -> V_51 -> V_27 , L_41 ) ;
}
static int F_175 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_94 * V_62 ,
int V_382 ,
enum V_383 type )
{
struct V_47 * V_324 = V_51 -> V_87 ;
F_158 ( & V_324 -> V_355 ) ;
if ( F_6 ( V_324 -> V_222 || V_324 -> V_353 ) ) {
F_160 ( & V_324 -> V_355 ) ;
return - V_374 ;
}
V_324 -> V_379 = V_62 ;
V_324 -> V_381 = V_382 ;
F_160 ( & V_324 -> V_355 ) ;
F_20 ( V_51 -> V_27 , L_42 ,
V_62 -> V_117 , V_382 ) ;
F_162 ( V_51 , & V_324 -> V_378 , V_384 / 50 ) ;
return 0 ;
}
static int F_176 ( struct V_86 * V_51 )
{
struct V_47 * V_324 = V_51 -> V_87 ;
F_167 ( & V_324 -> V_378 ) ;
F_167 ( & V_324 -> V_380 ) ;
F_158 ( & V_324 -> V_355 ) ;
V_324 -> V_222 = NULL ;
F_160 ( & V_324 -> V_355 ) ;
F_20 ( V_51 -> V_27 , L_43 ) ;
return 0 ;
}
static int F_177 ( struct V_86 * V_51 ,
struct V_15 * V_385 )
{
F_10 ( V_385 ) ;
F_20 ( V_51 -> V_27 ,
L_44 ,
V_385 -> V_61 . V_62 -> V_117 , V_385 -> V_61 . V_278 ,
V_385 -> V_61 . V_275 , V_385 -> V_61 . V_276 ) ;
return 0 ;
}
static void F_178 ( struct V_86 * V_51 ,
struct V_15 * V_385 )
{
F_20 ( V_51 -> V_27 ,
L_45 ,
V_385 -> V_61 . V_62 -> V_117 , V_385 -> V_61 . V_278 ,
V_385 -> V_61 . V_275 , V_385 -> V_61 . V_276 ) ;
F_9 ( V_385 ) ;
F_11 ( V_385 ) ;
}
static void F_179 ( struct V_86 * V_51 ,
struct V_15 * V_385 ,
T_1 V_265 )
{
F_9 ( V_385 ) ;
F_20 ( V_51 -> V_27 ,
L_46 ,
V_385 -> V_61 . V_62 -> V_117 , V_385 -> V_61 . V_278 ,
V_385 -> V_61 . V_275 , V_385 -> V_61 . V_276 ) ;
}
static int F_180 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_15 * V_385 )
{
F_1 ( V_2 ) ;
F_9 ( V_385 ) ;
return 0 ;
}
static void F_181 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_15 * V_385 )
{
F_1 ( V_2 ) ;
F_9 ( V_385 ) ;
}
static void F_182 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
T_1 V_386 , T_2 * V_30 )
{
if ( V_386 == V_387 )
memcpy ( V_30 , * V_388 ,
sizeof( V_388 ) ) ;
}
static int F_183 ( struct V_86 * V_51 ,
struct V_1 * V_2 , int V_386 )
{
if ( V_386 == V_387 )
return V_389 ;
return 0 ;
}
static void F_184 ( struct V_86 * V_51 ,
struct V_1 * V_2 ,
struct V_390 * V_391 , T_3 * V_30 )
{
struct V_47 * V_392 = V_51 -> V_87 ;
int V_146 = 0 ;
V_30 [ V_146 ++ ] = V_392 -> V_181 ;
V_30 [ V_146 ++ ] = V_392 -> V_182 ;
V_30 [ V_146 ++ ] = V_392 -> V_227 ;
V_30 [ V_146 ++ ] = V_392 -> V_228 ;
V_30 [ V_146 ++ ] = V_392 -> V_154 ;
V_30 [ V_146 ++ ] = V_392 -> V_183 ;
V_30 [ V_146 ++ ] = V_392 -> V_63 ;
V_30 [ V_146 ++ ] = V_392 -> V_80 ;
V_30 [ V_146 ++ ] = V_392 -> V_215 ;
F_6 ( V_146 != V_389 ) ;
}
static void F_185 ( struct V_32 * V_393 ,
struct V_394 * V_98 )
{
if ( V_98 )
F_186 ( & V_157 , V_393 , V_98 ,
V_395 , V_43 ) ;
else
F_187 ( & V_157 , V_393 , 0 ,
V_395 , V_43 ) ;
}
static int F_188 ( struct V_32 * V_33 , int V_396 ,
struct V_397 * V_398 )
{
int V_136 ;
V_136 = F_22 ( V_33 , V_399 , V_396 ) ;
if ( V_136 < 0 )
return V_136 ;
if ( V_398 -> V_361 ) {
V_136 = F_22 ( V_33 , V_400 , V_398 -> V_361 ) ;
if ( V_136 < 0 )
return V_136 ;
}
if ( V_398 -> V_401 ) {
V_136 = F_82 ( V_33 , V_402 , 2 ,
V_398 -> V_401 ) ;
if ( V_136 < 0 )
return V_136 ;
}
if ( V_398 -> V_403 ) {
int V_146 ;
for ( V_146 = 0 ; V_146 < F_113 ( V_404 ) ; V_146 ++ ) {
if ( V_404 [ V_146 ] != V_398 -> V_403 )
continue;
V_136 = F_22 ( V_33 , V_405 , V_146 ) ;
if ( V_136 < 0 )
return V_136 ;
break;
}
}
if ( V_398 -> V_406 ) {
V_136 = F_189 ( V_33 , V_407 ) ;
if ( V_136 < 0 )
return V_136 ;
}
if ( V_398 -> V_408 ) {
V_136 = F_189 ( V_33 , V_409 ) ;
if ( V_136 < 0 )
return V_136 ;
}
if ( V_398 -> V_232 ) {
V_136 = F_189 ( V_33 , V_410 ) ;
if ( V_136 < 0 )
return V_136 ;
}
if ( V_398 -> V_411 ) {
V_136 = F_82 ( V_33 , V_412 ,
strlen ( V_398 -> V_411 ) , V_398 -> V_411 ) ;
if ( V_136 < 0 )
return V_136 ;
}
return 0 ;
}
static void F_190 ( int V_396 , struct V_394 * V_98 ,
struct V_397 * V_398 )
{
struct V_32 * V_393 ;
void * V_30 ;
V_393 = F_79 ( V_155 , V_43 ) ;
if ( ! V_393 )
return;
V_30 = F_80 ( V_393 , 0 , 0 , & V_157 , 0 ,
V_413 ) ;
if ( ! V_30 )
goto V_414;
if ( F_188 ( V_393 , V_396 , V_398 ) < 0 )
goto V_414;
F_84 ( V_393 , V_30 ) ;
F_185 ( V_393 , V_98 ) ;
return;
V_414:
F_191 ( V_393 , V_30 ) ;
F_74 ( V_393 ) ;
}
static int F_192 ( struct V_394 * V_98 ,
struct V_397 * V_398 )
{
int V_37 ;
T_2 V_8 [ V_58 ] ;
struct V_47 * V_30 ;
struct V_86 * V_51 ;
enum V_415 V_203 ;
const struct V_416 * V_417 = & V_418 ;
struct V_20 * V_20 ;
int V_171 ;
if ( F_6 ( V_398 -> V_361 > 1 && ! V_398 -> V_232 ) )
return - V_41 ;
F_193 ( & V_218 ) ;
V_171 = V_419 ++ ;
F_194 ( & V_218 ) ;
if ( V_398 -> V_232 )
V_417 = & V_420 ;
V_51 = F_195 ( sizeof( * V_30 ) , V_417 , V_398 -> V_411 ) ;
if ( ! V_51 ) {
F_81 ( V_159 L_47 ) ;
V_37 = - V_44 ;
goto V_421;
}
if ( V_98 )
V_20 = F_196 ( V_98 ) ;
else
V_20 = & V_422 ;
F_197 ( V_51 -> V_27 , V_20 ) ;
V_30 = V_51 -> V_87 ;
V_30 -> V_51 = V_51 ;
V_30 -> V_82 = F_198 ( V_423 , NULL , 0 , V_51 , L_48 , V_171 ) ;
if ( F_199 ( V_30 -> V_82 ) ) {
F_81 ( V_159
L_49 ,
F_200 ( V_30 -> V_82 ) ) ;
V_37 = - V_44 ;
goto V_424;
}
V_30 -> V_82 -> V_425 = & V_426 . V_425 ;
V_37 = F_201 ( V_30 -> V_82 ) ;
if ( V_37 != 0 ) {
F_81 ( V_159 L_50 ,
V_37 ) ;
goto V_427;
}
F_202 ( & V_30 -> V_151 ) ;
F_203 ( V_51 , V_30 -> V_82 ) ;
F_170 ( V_8 ) ;
V_8 [ 0 ] = 0x02 ;
V_8 [ 3 ] = V_171 >> 8 ;
V_8 [ 4 ] = V_171 ;
memcpy ( V_30 -> V_161 [ 0 ] . V_8 , V_8 , V_58 ) ;
memcpy ( V_30 -> V_161 [ 1 ] . V_8 , V_8 , V_58 ) ;
V_30 -> V_161 [ 1 ] . V_8 [ 0 ] |= 0x40 ;
V_51 -> V_27 -> V_428 = 2 ;
V_51 -> V_27 -> V_161 = V_30 -> V_161 ;
V_30 -> V_361 = V_398 -> V_361 ;
V_30 -> V_232 = V_398 -> V_232 ;
V_30 -> V_171 = V_171 ;
V_30 -> V_429 = V_398 -> V_429 ;
if ( V_98 )
V_30 -> V_26 = V_98 -> V_430 ;
if ( V_30 -> V_232 ) {
V_51 -> V_27 -> V_431 = 255 ;
V_51 -> V_27 -> V_432 = V_433 ;
V_51 -> V_27 -> V_434 = 1000 ;
V_51 -> V_27 -> V_435 = & V_30 -> V_436 ;
if ( V_398 -> V_408 )
V_30 -> V_436 = V_437 [ 0 ] ;
else
V_30 -> V_436 = V_438 [ 0 ] ;
V_51 -> V_27 -> V_439 = 1 ;
V_30 -> V_436 . V_440 = 0 ;
V_30 -> V_436 . V_441 = V_30 -> V_361 ;
} else if ( V_398 -> V_408 ) {
V_51 -> V_27 -> V_435 = V_437 ;
V_51 -> V_27 -> V_439 =
F_113 ( V_437 ) ;
} else {
V_51 -> V_27 -> V_435 = V_438 ;
V_51 -> V_27 -> V_439 = F_113 ( V_438 ) ;
}
F_204 ( & V_30 -> V_378 , F_171 ) ;
F_204 ( & V_30 -> V_380 , F_173 ) ;
F_204 ( & V_30 -> V_350 , F_157 ) ;
V_51 -> V_346 = 5 ;
V_51 -> V_442 = 4 ;
V_51 -> V_27 -> V_443 = F_90 ( V_444 ) |
F_90 ( V_253 ) |
F_90 ( V_445 ) |
F_90 ( V_446 ) |
F_90 ( V_255 ) |
F_90 ( V_254 ) ;
if ( V_398 -> V_408 )
V_51 -> V_27 -> V_443 |= F_90 ( V_447 ) ;
F_205 ( V_51 , V_448 ) ;
F_205 ( V_51 , V_449 ) ;
F_205 ( V_51 , V_450 ) ;
F_205 ( V_51 , V_451 ) ;
F_205 ( V_51 , V_452 ) ;
F_205 ( V_51 , V_453 ) ;
F_205 ( V_51 , V_454 ) ;
F_205 ( V_51 , V_455 ) ;
F_205 ( V_51 , V_456 ) ;
if ( V_457 )
F_205 ( V_51 , V_234 ) ;
V_51 -> V_27 -> V_96 |= V_458 |
V_459 |
V_460 |
V_461 ;
V_51 -> V_27 -> V_462 |= V_463 |
V_464 |
V_465 |
V_466 |
V_467 ;
F_206 ( V_51 -> V_27 , V_468 ) ;
V_51 -> V_469 = sizeof( struct V_3 ) ;
V_51 -> V_470 = sizeof( struct V_12 ) ;
V_51 -> V_471 = sizeof( struct V_17 ) ;
memcpy ( V_30 -> V_472 , V_473 ,
sizeof( V_473 ) ) ;
memcpy ( V_30 -> V_474 , V_475 ,
sizeof( V_475 ) ) ;
memcpy ( V_30 -> V_173 , V_476 , sizeof( V_476 ) ) ;
for ( V_203 = V_477 ; V_203 < V_478 ; V_203 ++ ) {
struct V_479 * V_480 = & V_30 -> V_481 [ V_203 ] ;
switch ( V_203 ) {
case V_477 :
V_480 -> V_361 = V_30 -> V_472 ;
V_480 -> V_357 = F_113 ( V_473 ) ;
V_480 -> V_482 = V_30 -> V_173 ;
V_480 -> V_483 = F_113 ( V_476 ) ;
break;
case V_484 :
V_480 -> V_361 = V_30 -> V_474 ;
V_480 -> V_357 = F_113 ( V_475 ) ;
V_480 -> V_482 = V_30 -> V_173 + 4 ;
V_480 -> V_483 = F_113 ( V_476 ) - 4 ;
V_480 -> V_485 . V_486 = true ;
V_480 -> V_485 . V_487 =
V_488 |
V_489 |
V_490 |
V_491 |
V_492 |
V_493 |
V_494 |
V_495 |
V_496 |
V_497 |
V_498 ;
V_480 -> V_485 . V_499 . V_500 =
F_29 ( V_501 << 0 |
V_501 << 2 |
V_501 << 4 |
V_501 << 6 |
V_501 << 8 |
V_501 << 10 |
V_501 << 12 |
V_501 << 14 ) ;
V_480 -> V_485 . V_499 . V_502 =
V_480 -> V_485 . V_499 . V_500 ;
break;
default:
continue;
}
V_480 -> V_503 . V_504 = true ;
V_480 -> V_503 . V_487 = V_505 |
V_506 |
V_507 |
V_508 |
V_509 ;
V_480 -> V_503 . V_510 = 0x3 ;
V_480 -> V_503 . V_511 = 0x6 ;
memset ( & V_480 -> V_503 . V_512 , 0 ,
sizeof( V_480 -> V_503 . V_512 ) ) ;
V_480 -> V_503 . V_512 . V_513 [ 0 ] = 0xff ;
V_480 -> V_503 . V_512 . V_513 [ 1 ] = 0xff ;
V_480 -> V_503 . V_512 . V_514 = V_515 ;
V_51 -> V_27 -> V_481 [ V_203 ] = V_480 ;
}
V_30 -> V_80 = 1 ;
F_207 ( & V_30 -> V_355 ) ;
V_30 -> V_23 = F_12 ( V_20 ) ;
V_51 -> V_516 = 4 ;
V_51 -> V_517 = 11 ;
V_51 -> V_27 -> V_518 = V_519 ;
V_51 -> V_27 -> V_520 =
F_113 ( V_519 ) ;
V_51 -> V_27 -> V_521 = V_522 ;
V_51 -> V_27 -> V_523 = F_113 ( V_522 ) ;
if ( V_398 -> V_406 )
V_51 -> V_27 -> V_524 |= V_525 ;
if ( V_398 -> V_403 ) {
V_30 -> V_403 = V_398 -> V_403 ;
V_51 -> V_27 -> V_524 |= V_526 ;
F_208 ( V_51 -> V_27 , V_398 -> V_403 ) ;
F_209 ( 1 ) ;
}
if ( V_398 -> V_527 )
F_205 ( V_51 , V_528 ) ;
V_37 = F_210 ( V_51 ) ;
if ( V_37 < 0 ) {
F_81 ( V_159 L_51 ,
V_37 ) ;
goto V_529;
}
F_20 ( V_51 -> V_27 , L_52 , V_51 -> V_27 -> V_530 ) ;
if ( V_398 -> V_401 ) {
V_30 -> V_531 [ 0 ] = V_398 -> V_401 [ 0 ] ;
V_30 -> V_531 [ 1 ] = V_398 -> V_401 [ 1 ] ;
F_211 ( V_51 -> V_27 , V_398 -> V_401 ) ;
}
V_30 -> V_532 = F_212 ( L_53 , V_51 -> V_27 -> V_533 ) ;
F_213 ( L_54 , 0666 , V_30 -> V_532 , V_30 , & V_534 ) ;
F_213 ( L_55 , 0666 , V_30 -> V_532 , V_30 ,
& V_535 ) ;
if ( ! V_30 -> V_232 )
F_213 ( L_56 , 0222 ,
V_30 -> V_532 ,
V_30 , & V_536 ) ;
F_214 ( & V_30 -> V_242 ,
F_129 ,
V_537 , V_263 ) ;
F_193 ( & V_218 ) ;
F_215 ( & V_30 -> V_538 , & V_539 ) ;
F_194 ( & V_218 ) ;
if ( V_171 > 0 )
F_190 ( V_171 , V_98 , V_398 ) ;
return V_171 ;
V_529:
F_216 ( V_30 -> V_82 ) ;
V_427:
F_217 ( V_30 -> V_82 ) ;
V_424:
F_218 ( V_51 ) ;
V_421:
return V_37 ;
}
static void F_219 ( int V_396 , const char * V_411 ,
struct V_394 * V_98 )
{
struct V_32 * V_33 ;
void * V_30 ;
int V_136 ;
V_33 = F_79 ( V_155 , V_43 ) ;
if ( ! V_33 )
return;
V_30 = F_80 ( V_33 , 0 , 0 , & V_157 , 0 ,
V_540 ) ;
if ( ! V_30 )
goto error;
V_136 = F_22 ( V_33 , V_399 , V_396 ) ;
if ( V_136 < 0 )
goto error;
V_136 = F_82 ( V_33 , V_412 , strlen ( V_411 ) ,
V_411 ) ;
if ( V_136 < 0 )
goto error;
F_84 ( V_33 , V_30 ) ;
F_185 ( V_33 , V_98 ) ;
return;
error:
F_74 ( V_33 ) ;
}
static void F_220 ( struct V_47 * V_30 ,
const char * V_411 ,
struct V_394 * V_98 )
{
F_219 ( V_30 -> V_171 , V_411 , V_98 ) ;
F_221 ( V_30 -> V_532 ) ;
F_222 ( V_30 -> V_51 ) ;
F_216 ( V_30 -> V_82 ) ;
F_217 ( V_30 -> V_82 ) ;
F_218 ( V_30 -> V_51 ) ;
}
static int F_223 ( struct V_32 * V_33 ,
struct V_47 * V_30 ,
T_1 V_26 , T_1 V_541 ,
struct V_542 * V_129 , int V_96 )
{
void * V_65 ;
struct V_397 V_398 = { } ;
int V_140 = - V_543 ;
V_65 = F_80 ( V_33 , V_26 , V_541 , & V_157 , V_96 ,
V_544 ) ;
if ( ! V_65 )
return - V_543 ;
if ( V_129 )
F_224 ( V_129 , V_65 , & V_157 ) ;
if ( V_30 -> V_531 [ 0 ] && V_30 -> V_531 [ 1 ] )
V_398 . V_401 = V_30 -> V_531 ;
V_398 . V_406 = ! ! ( V_30 -> V_51 -> V_27 -> V_524 &
V_525 ) ;
V_398 . V_408 = ! ! ( V_30 -> V_51 -> V_27 -> V_443 &
F_90 ( V_447 ) ) ;
V_398 . V_232 = V_30 -> V_232 ;
V_398 . V_403 = V_30 -> V_403 ;
V_398 . V_361 = V_30 -> V_361 ;
V_398 . V_411 = F_225 ( V_30 -> V_51 -> V_27 ) ;
V_140 = F_188 ( V_33 , V_30 -> V_171 , & V_398 ) ;
if ( V_140 < 0 )
goto V_414;
F_84 ( V_33 , V_65 ) ;
return 0 ;
V_414:
F_191 ( V_33 , V_65 ) ;
return V_140 ;
}
static void F_226 ( void )
{
struct V_47 * V_30 ;
F_193 ( & V_218 ) ;
while ( ( V_30 = F_227 ( & V_539 ,
struct V_47 ,
V_538 ) ) ) {
F_228 ( & V_30 -> V_538 ) ;
F_194 ( & V_218 ) ;
F_220 ( V_30 , F_225 ( V_30 -> V_51 -> V_27 ) ,
NULL ) ;
F_193 ( & V_218 ) ;
}
F_194 ( & V_218 ) ;
F_229 ( V_423 ) ;
}
static void F_230 ( struct V_81 * V_82 )
{
V_82 -> V_545 = & V_546 ;
V_82 -> V_547 = V_548 ;
F_231 ( V_82 ) ;
V_82 -> V_549 |= V_550 ;
V_82 -> type = V_551 ;
F_170 ( V_82 -> V_552 ) ;
V_82 -> V_552 [ 0 ] = 0x12 ;
}
static struct V_47 * F_232 ( const T_2 * V_8 )
{
struct V_47 * V_30 ;
bool V_553 = false ;
F_193 ( & V_218 ) ;
F_102 (data, &hwsim_radios, list) {
if ( memcmp ( V_30 -> V_161 [ 1 ] . V_8 , V_8 , V_58 ) == 0 ) {
V_553 = true ;
break;
}
}
F_194 ( & V_218 ) ;
if ( ! V_553 )
return NULL ;
return V_30 ;
}
static void F_233 ( struct V_20 * V_20 , T_1 V_26 )
{
struct V_47 * V_30 ;
F_16 ( V_20 , V_26 ) ;
F_193 ( & V_218 ) ;
F_102 (data, &hwsim_radios, list) {
if ( V_30 -> V_23 == F_12 ( V_20 ) )
V_30 -> V_25 = V_26 ;
}
F_194 ( & V_218 ) ;
}
static int F_234 ( struct V_32 * V_554 ,
struct V_394 * V_98 )
{
struct V_64 * V_65 ;
struct V_47 * V_197 ;
struct V_97 * V_230 ;
struct V_147 * V_148 ;
T_3 V_555 ;
struct V_32 * V_33 , * V_556 ;
const T_2 * V_557 ;
unsigned int V_145 ;
int V_146 ;
bool V_139 = false ;
if ( ! V_98 -> V_558 [ V_160 ] ||
! V_98 -> V_558 [ V_168 ] ||
! V_98 -> V_558 [ V_178 ] ||
! V_98 -> V_558 [ V_559 ] ||
! V_98 -> V_558 [ V_175 ] )
goto V_262;
V_557 = ( void * ) F_235 ( V_98 -> V_558 [ V_160 ] ) ;
V_145 = F_19 ( V_98 -> V_558 [ V_168 ] ) ;
V_555 = F_236 ( V_98 -> V_558 [ V_178 ] ) ;
V_197 = F_232 ( V_557 ) ;
if ( ! V_197 )
goto V_262;
if ( F_12 ( F_196 ( V_98 ) ) != V_197 -> V_23 )
goto V_262;
if ( V_98 -> V_430 != V_197 -> V_25 )
goto V_262;
F_237 (&data2->pending, skb, tmp) {
T_3 V_560 ;
V_230 = F_58 ( V_33 ) ;
V_560 = ( T_3 ) ( T_7 ) V_230 -> V_177 [ 0 ] ;
if ( V_560 == V_555 ) {
F_238 ( V_33 , & V_197 -> V_151 ) ;
V_139 = true ;
break;
}
}
if ( ! V_139 )
goto V_262;
V_148 = (struct V_147 * ) F_235 (
V_98 -> V_558 [ V_175 ] ) ;
V_230 = F_58 ( V_33 ) ;
F_115 ( V_230 ) ;
for ( V_146 = 0 ; V_146 < V_149 ; V_146 ++ ) {
V_230 -> V_172 . V_173 [ V_146 ] . V_171 = V_148 [ V_146 ] . V_171 ;
V_230 -> V_172 . V_173 [ V_146 ] . V_174 = V_148 [ V_146 ] . V_174 ;
}
V_230 -> V_172 . V_561 = F_19 ( V_98 -> V_558 [ V_559 ] ) ;
if ( ! ( V_145 & V_167 ) &&
( V_145 & V_562 ) ) {
if ( V_33 -> V_163 >= 16 ) {
V_65 = (struct V_64 * ) V_33 -> V_30 ;
F_67 ( V_197 -> V_170 ,
V_65 -> V_70 ) ;
}
V_230 -> V_96 |= V_241 ;
}
F_116 ( V_197 -> V_51 , V_33 ) ;
return 0 ;
V_262:
return - V_41 ;
}
static int F_239 ( struct V_32 * V_554 ,
struct V_394 * V_98 )
{
struct V_47 * V_197 ;
struct V_199 V_200 ;
const T_2 * V_563 ;
int V_564 ;
void * V_565 ;
struct V_32 * V_33 = NULL ;
if ( ! V_98 -> V_558 [ V_566 ] ||
! V_98 -> V_558 [ V_162 ] ||
! V_98 -> V_558 [ V_567 ] ||
! V_98 -> V_558 [ V_559 ] )
goto V_262;
V_563 = ( void * ) F_235 ( V_98 -> V_558 [ V_566 ] ) ;
V_564 = F_240 ( V_98 -> V_558 [ V_162 ] ) ;
V_565 = ( void * ) F_235 ( V_98 -> V_558 [ V_162 ] ) ;
V_33 = F_241 ( V_564 , V_43 ) ;
if ( V_33 == NULL )
goto V_37;
if ( V_564 > V_433 )
goto V_37;
memcpy ( F_28 ( V_33 , V_564 ) , V_565 , V_564 ) ;
V_197 = F_232 ( V_563 ) ;
if ( ! V_197 )
goto V_262;
if ( F_12 ( F_196 ( V_98 ) ) != V_197 -> V_23 )
goto V_262;
if ( V_98 -> V_430 != V_197 -> V_25 )
goto V_262;
if ( V_197 -> V_221 || ! V_197 -> V_220 )
goto V_262;
memset ( & V_200 , 0 , sizeof( V_200 ) ) ;
if ( V_98 -> V_558 [ V_169 ] ) {
F_158 ( & V_197 -> V_355 ) ;
V_200 . V_202 = F_19 ( V_98 -> V_558 [ V_169 ] ) ;
if ( V_200 . V_202 != V_197 -> V_170 -> V_117 &&
( ! V_197 -> V_222 ||
V_200 . V_202 != V_197 -> V_222 -> V_117 ) ) {
F_160 ( & V_197 -> V_355 ) ;
goto V_262;
}
F_160 ( & V_197 -> V_355 ) ;
} else {
V_200 . V_202 = V_197 -> V_170 -> V_117 ;
}
V_200 . V_203 = V_197 -> V_170 -> V_203 ;
V_200 . V_206 = F_19 ( V_98 -> V_558 [ V_567 ] ) ;
V_200 . signal = F_19 ( V_98 -> V_558 [ V_559 ] ) ;
memcpy ( F_91 ( V_33 ) , & V_200 , sizeof( V_200 ) ) ;
V_197 -> V_227 ++ ;
V_197 -> V_228 += V_33 -> V_163 ;
F_108 ( V_197 -> V_51 , V_33 ) ;
return 0 ;
V_37:
F_81 ( V_159 L_6 , V_42 ) ;
V_262:
F_47 ( V_33 ) ;
return - V_41 ;
}
static int F_242 ( struct V_32 * V_554 ,
struct V_394 * V_98 )
{
struct V_20 * V_20 = F_196 ( V_98 ) ;
struct V_47 * V_30 ;
int V_568 = 1 ;
F_193 ( & V_218 ) ;
F_102 (data, &hwsim_radios, list)
V_568 = F_243 ( V_568 , V_30 -> V_361 ) ;
F_194 ( & V_218 ) ;
if ( V_568 > 1 )
return - V_333 ;
if ( F_15 ( V_20 ) )
return - V_374 ;
F_233 ( V_20 , V_98 -> V_430 ) ;
F_81 ( V_159 L_57
L_58 , V_98 -> V_430 ) ;
return 0 ;
}
static int F_244 ( struct V_32 * V_569 , struct V_394 * V_98 )
{
struct V_397 V_398 = { 0 } ;
V_398 . V_406 = V_98 -> V_558 [ V_407 ] ;
V_398 . V_408 = V_98 -> V_558 [ V_409 ] ;
V_398 . V_361 = V_361 ;
V_398 . V_429 =
V_98 -> V_558 [ V_570 ] ;
if ( V_98 -> V_558 [ V_400 ] )
V_398 . V_361 = F_19 ( V_98 -> V_558 [ V_400 ] ) ;
if ( V_98 -> V_558 [ V_571 ] )
V_398 . V_527 = true ;
if ( V_98 -> V_558 [ V_412 ] )
V_398 . V_411 = F_235 ( V_98 -> V_558 [ V_412 ] ) ;
if ( V_98 -> V_558 [ V_410 ] )
V_398 . V_232 = true ;
else
V_398 . V_232 = ( V_398 . V_361 > 1 ) ;
if ( V_98 -> V_558 [ V_402 ] )
V_398 . V_401 =
F_235 ( V_98 -> V_558 [ V_402 ] ) ;
if ( V_98 -> V_558 [ V_405 ] ) {
T_1 V_171 = F_19 ( V_98 -> V_558 [ V_405 ] ) ;
if ( V_171 >= F_113 ( V_404 ) )
return - V_41 ;
V_398 . V_403 = V_404 [ V_171 ] ;
}
return F_192 ( V_98 , & V_398 ) ;
}
static int F_245 ( struct V_32 * V_569 , struct V_394 * V_98 )
{
struct V_47 * V_30 ;
T_9 V_171 = - 1 ;
const char * V_411 = NULL ;
if ( V_98 -> V_558 [ V_399 ] )
V_171 = F_19 ( V_98 -> V_558 [ V_399 ] ) ;
else if ( V_98 -> V_558 [ V_412 ] )
V_411 = ( void * ) F_235 ( V_98 -> V_558 [ V_412 ] ) ;
else
return - V_41 ;
F_193 ( & V_218 ) ;
F_102 (data, &hwsim_radios, list) {
if ( V_171 >= 0 ) {
if ( V_30 -> V_171 != V_171 )
continue;
} else {
if ( strcmp ( V_411 , F_225 ( V_30 -> V_51 -> V_27 ) ) )
continue;
}
if ( ! F_246 ( F_247 ( V_30 -> V_51 -> V_27 ) , F_196 ( V_98 ) ) )
continue;
F_228 ( & V_30 -> V_538 ) ;
F_194 ( & V_218 ) ;
F_220 ( V_30 , F_225 ( V_30 -> V_51 -> V_27 ) ,
V_98 ) ;
return 0 ;
}
F_194 ( & V_218 ) ;
return - V_572 ;
}
static int F_248 ( struct V_32 * V_569 , struct V_394 * V_98 )
{
struct V_47 * V_30 ;
struct V_32 * V_33 ;
int V_171 , V_140 = - V_572 ;
if ( ! V_98 -> V_558 [ V_399 ] )
return - V_41 ;
V_171 = F_19 ( V_98 -> V_558 [ V_399 ] ) ;
F_193 ( & V_218 ) ;
F_102 (data, &hwsim_radios, list) {
if ( V_30 -> V_171 != V_171 )
continue;
if ( ! F_246 ( F_247 ( V_30 -> V_51 -> V_27 ) , F_196 ( V_98 ) ) )
continue;
V_33 = F_249 ( V_573 , V_43 ) ;
if ( ! V_33 ) {
V_140 = - V_44 ;
goto V_414;
}
V_140 = F_223 ( V_33 , V_30 , V_98 -> V_430 ,
V_98 -> V_574 , NULL , 0 ) ;
if ( V_140 < 0 ) {
F_74 ( V_33 ) ;
goto V_414;
}
F_250 ( V_33 , V_98 ) ;
break;
}
V_414:
F_194 ( & V_218 ) ;
return V_140 ;
}
static int F_251 ( struct V_32 * V_33 ,
struct V_542 * V_129 )
{
int V_171 = V_129 -> args [ 0 ] ;
struct V_47 * V_30 = NULL ;
int V_140 ;
F_193 ( & V_218 ) ;
if ( V_171 == V_419 )
goto V_575;
F_102 (data, &hwsim_radios, list) {
if ( V_30 -> V_171 < V_171 )
continue;
if ( ! F_246 ( F_247 ( V_30 -> V_51 -> V_27 ) , F_252 ( V_33 -> V_576 ) ) )
continue;
V_140 = F_223 ( V_33 , V_30 ,
F_253 ( V_129 -> V_33 ) . V_26 ,
V_129 -> V_577 -> V_578 , V_129 ,
V_579 ) ;
if ( V_140 < 0 )
break;
V_171 = V_30 -> V_171 + 1 ;
}
V_129 -> args [ 0 ] = V_171 ;
V_575:
F_194 ( & V_218 ) ;
return V_33 -> V_163 ;
}
static void F_254 ( struct V_348 * V_349 )
{
struct V_47 * V_30 =
F_130 ( V_349 , struct V_47 , V_580 ) ;
F_220 ( V_30 , F_225 ( V_30 -> V_51 -> V_27 ) , NULL ) ;
}
static void F_255 ( T_1 V_26 )
{
struct V_47 * V_581 , * V_556 ;
F_193 ( & V_218 ) ;
F_256 (entry, tmp, &hwsim_radios, list) {
if ( V_581 -> V_429 && V_581 -> V_26 == V_26 ) {
F_228 ( & V_581 -> V_538 ) ;
F_257 ( & V_581 -> V_580 , F_254 ) ;
F_258 ( & V_581 -> V_580 ) ;
}
}
F_194 ( & V_218 ) ;
}
static int F_259 ( struct V_582 * V_583 ,
unsigned long V_584 ,
void * V_585 )
{
struct V_586 * V_587 = V_585 ;
if ( V_584 != V_588 )
return V_589 ;
F_255 ( V_587 -> V_26 ) ;
if ( V_587 -> V_26 == F_15 ( V_587 -> V_20 ) ) {
F_81 ( V_590 L_59
L_60 ) ;
F_233 ( V_587 -> V_20 , 0 ) ;
}
return V_589 ;
}
static int F_260 ( void )
{
int V_591 ;
F_81 ( V_590 L_61 ) ;
V_591 = F_261 ( & V_157 ,
V_592 ,
V_593 ) ;
if ( V_591 )
goto V_594;
V_591 = F_262 ( & V_595 ) ;
if ( V_591 ) {
F_263 ( & V_157 ) ;
goto V_594;
}
return 0 ;
V_594:
F_81 ( V_159 L_6 , V_42 ) ;
return - V_41 ;
}
static T_10 int F_264 ( struct V_20 * V_20 )
{
F_14 ( V_20 ) ;
return 0 ;
}
static void T_11 F_265 ( struct V_20 * V_20 )
{
struct V_47 * V_30 , * V_556 ;
F_193 ( & V_218 ) ;
F_256 (data, tmp, &hwsim_radios, list) {
if ( ! F_246 ( F_247 ( V_30 -> V_51 -> V_27 ) , V_20 ) )
continue;
if ( V_30 -> V_23 == F_12 ( & V_422 ) )
continue;
F_228 ( & V_30 -> V_538 ) ;
F_257 ( & V_30 -> V_580 , F_254 ) ;
F_258 ( & V_30 -> V_580 ) ;
}
F_194 ( & V_218 ) ;
}
static void F_266 ( void )
{
F_267 ( & V_595 ) ;
F_263 ( & V_157 ) ;
}
static int T_12 F_268 ( void )
{
int V_146 , V_37 ;
if ( V_596 < 0 || V_596 > 100 )
return - V_41 ;
if ( V_361 < 1 )
return - V_41 ;
V_420 = V_418 ;
V_420 . V_350 = F_164 ;
V_420 . V_597 = F_166 ;
V_420 . V_598 = NULL ;
V_420 . V_599 = NULL ;
V_420 . V_600 = F_175 ;
V_420 . V_601 = F_176 ;
V_420 . V_602 = F_177 ;
V_420 . V_603 = F_178 ;
V_420 . V_604 = F_179 ;
V_420 . V_605 =
F_180 ;
V_420 . V_606 =
F_181 ;
F_269 ( & V_218 ) ;
F_270 ( & V_539 ) ;
V_37 = F_271 ( & V_607 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_272 ( & V_426 ) ;
if ( V_37 )
goto V_608;
V_423 = F_273 ( V_609 , L_62 ) ;
if ( F_199 ( V_423 ) ) {
V_37 = F_200 ( V_423 ) ;
goto V_610;
}
V_37 = F_260 () ;
if ( V_37 < 0 )
goto V_610;
for ( V_146 = 0 ; V_146 < V_596 ; V_146 ++ ) {
struct V_397 V_398 = { 0 } ;
V_398 . V_361 = V_361 ;
switch ( V_611 ) {
case V_612 :
if ( V_146 < F_113 ( V_613 ) )
V_398 . V_401 = V_613 [ V_146 ] ;
break;
case V_614 :
if ( ! V_146 )
V_398 . V_401 = V_613 [ 0 ] ;
break;
case V_615 :
V_398 . V_406 = true ;
case V_616 :
V_398 . V_401 = V_613 [ 0 ] ;
break;
case V_617 :
if ( V_146 == 0 )
V_398 . V_403 = & V_618 ;
break;
case V_619 :
V_398 . V_403 = & V_618 ;
break;
case V_620 :
if ( V_146 == 0 )
V_398 . V_403 = & V_618 ;
else if ( V_146 == 1 )
V_398 . V_403 = & V_621 ;
break;
case V_622 :
if ( V_146 == 0 ) {
V_398 . V_406 = true ;
V_398 . V_401 = V_613 [ 0 ] ;
}
break;
case V_623 :
if ( V_146 == 0 ) {
V_398 . V_406 = true ;
V_398 . V_401 = V_613 [ 0 ] ;
} else if ( V_146 == 1 ) {
V_398 . V_401 = V_613 [ 1 ] ;
}
break;
case V_624 :
switch ( V_146 ) {
case 0 :
V_398 . V_403 = & V_618 ;
break;
case 1 :
V_398 . V_403 = & V_621 ;
break;
case 2 :
V_398 . V_401 = V_613 [ 0 ] ;
break;
case 3 :
V_398 . V_401 = V_613 [ 1 ] ;
break;
case 4 :
V_398 . V_406 = true ;
V_398 . V_401 = V_613 [ 2 ] ;
break;
}
break;
default:
break;
}
V_398 . V_408 = V_625 ;
V_398 . V_232 = V_361 > 1 ;
V_37 = F_192 ( NULL , & V_398 ) ;
if ( V_37 < 0 )
goto V_626;
}
V_101 = F_274 ( 0 , L_48 , V_627 ,
F_230 ) ;
if ( V_101 == NULL ) {
V_37 = - V_44 ;
goto V_626;
}
F_275 () ;
V_37 = F_276 ( V_101 , V_101 -> V_628 ) ;
if ( V_37 < 0 ) {
F_277 () ;
goto V_626;
}
V_37 = F_278 ( V_101 ) ;
if ( V_37 < 0 ) {
F_277 () ;
goto V_629;
}
F_277 () ;
return 0 ;
V_629:
V_548 ( V_101 ) ;
V_626:
F_226 () ;
V_610:
F_279 ( & V_426 ) ;
V_608:
F_280 ( & V_607 ) ;
return V_37 ;
}
static void T_13 F_281 ( void )
{
F_81 ( V_159 L_63 ) ;
F_266 () ;
F_226 () ;
F_282 ( V_101 ) ;
F_279 ( & V_426 ) ;
F_280 ( & V_607 ) ;
}
