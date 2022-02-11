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
static int F_12 ( struct V_20 * V_20 ,
struct V_21 * V_22 ,
const void * V_23 , int V_24 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 [ V_29 + 1 ] ;
int V_30 ;
T_1 V_31 ;
V_30 = F_13 ( V_28 , V_29 , V_23 , V_24 ,
V_32 ) ;
if ( V_30 )
return V_30 ;
if ( ! V_28 [ V_33 ] )
return - V_34 ;
V_31 = F_14 ( V_28 [ V_33 ] ) ;
F_15 ( V_20 , L_2 , V_35 , V_31 ) ;
V_26 = F_16 ( V_20 , V_22 , 100 , 0 , V_36 ) ;
if ( V_26 ) {
F_17 ( V_26 , V_33 , V_31 + 1 ) ;
F_18 ( V_26 , V_36 ) ;
}
V_26 = F_19 ( V_20 , 10 ) ;
if ( ! V_26 )
return - V_37 ;
F_17 ( V_26 , V_33 , V_31 + 2 ) ;
return F_20 ( V_26 ) ;
}
static void F_21 ( void * V_38 , T_2 * V_39 , struct V_1 * V_2 )
{
struct V_40 * V_23 = V_38 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_25 * V_26 ;
struct V_41 * V_42 ;
if ( ! V_4 -> V_43 )
return;
F_15 ( V_23 -> V_44 -> V_20 ,
L_3 ,
V_35 , V_4 -> V_45 , V_4 -> V_46 ) ;
V_26 = F_22 ( sizeof( * V_42 ) ) ;
if ( ! V_26 )
return;
V_42 = ( void * ) F_23 ( V_26 , sizeof( * V_42 ) ) ;
V_42 -> V_47 = F_24 ( V_48 |
V_49 |
V_50 ) ;
V_42 -> V_46 = F_24 ( 0xc000 | V_4 -> V_46 ) ;
memcpy ( V_42 -> V_45 , V_4 -> V_45 , V_51 ) ;
memcpy ( V_42 -> V_52 , V_39 , V_51 ) ;
F_25 () ;
F_26 ( V_23 -> V_44 , V_26 ,
F_27 ( V_2 -> V_53 ) -> V_54 . V_55 ) ;
F_28 () ;
}
static void F_29 ( struct V_40 * V_23 , T_2 * V_39 ,
struct V_1 * V_2 , int V_56 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_25 * V_26 ;
struct V_57 * V_58 ;
if ( ! V_4 -> V_43 )
return;
F_15 ( V_23 -> V_44 -> V_20 ,
L_4 ,
V_35 , V_4 -> V_45 , V_56 ) ;
V_26 = F_22 ( sizeof( * V_58 ) ) ;
if ( ! V_26 )
return;
V_58 = ( void * ) F_23 ( V_26 , sizeof( * V_58 ) - V_51 ) ;
V_58 -> V_47 = F_24 ( V_59 |
V_60 |
( V_56 ? V_50 : 0 ) ) ;
V_58 -> V_61 = F_24 ( 0 ) ;
memcpy ( V_58 -> V_62 , V_4 -> V_45 , V_51 ) ;
memcpy ( V_58 -> V_63 , V_39 , V_51 ) ;
memcpy ( V_58 -> V_64 , V_4 -> V_45 , V_51 ) ;
F_25 () ;
F_26 ( V_23 -> V_44 , V_26 ,
F_27 ( V_2 -> V_53 ) -> V_54 . V_55 ) ;
F_28 () ;
}
static void F_30 ( void * V_38 , T_2 * V_39 ,
struct V_1 * V_2 )
{
struct V_40 * V_23 = V_38 ;
F_29 ( V_23 , V_39 , V_2 , 1 ) ;
}
static void F_31 ( void * V_38 , T_2 * V_39 ,
struct V_1 * V_2 )
{
struct V_40 * V_23 = V_38 ;
F_29 ( V_23 , V_39 , V_2 , 0 ) ;
}
static int F_32 ( void * V_38 , T_3 * V_31 )
{
struct V_40 * V_23 = V_38 ;
* V_31 = V_23 -> V_56 ;
return 0 ;
}
static int F_33 ( void * V_38 , T_3 V_31 )
{
struct V_40 * V_23 = V_38 ;
enum V_65 V_66 ;
if ( V_31 != V_67 && V_31 != V_68 && V_31 != V_69 &&
V_31 != V_70 )
return - V_34 ;
V_66 = V_23 -> V_56 ;
V_23 -> V_56 = V_31 ;
F_34 () ;
if ( V_31 == V_70 ) {
F_35 (
V_23 -> V_44 , V_71 ,
F_21 , V_23 ) ;
V_23 -> V_72 = true ;
} else if ( V_66 == V_67 && V_31 != V_67 ) {
F_35 (
V_23 -> V_44 , V_71 ,
F_30 , V_23 ) ;
} else if ( V_66 != V_67 && V_31 == V_67 ) {
F_35 (
V_23 -> V_44 , V_71 ,
F_31 , V_23 ) ;
}
F_36 () ;
return 0 ;
}
static int F_37 ( void * V_38 , T_3 V_31 )
{
struct V_40 * V_23 = V_38 ;
F_38 ( V_23 -> V_44 ) ;
return 0 ;
}
static int F_39 ( void * V_38 , T_3 * V_31 )
{
struct V_40 * V_23 = V_38 ;
* V_31 = V_23 -> V_73 ;
return 0 ;
}
static int F_40 ( void * V_38 , T_3 V_31 )
{
struct V_40 * V_23 = V_38 ;
V_23 -> V_73 = V_31 ;
return 0 ;
}
static T_4 F_41 ( struct V_25 * V_26 ,
struct V_74 * V_75 )
{
F_42 ( V_26 ) ;
return V_76 ;
}
static inline T_3 F_43 ( void )
{
return F_44 ( F_45 () ) ;
}
static T_5 F_46 ( struct V_40 * V_23 )
{
T_3 V_77 = F_43 () ;
return F_47 ( V_77 + V_23 -> V_78 ) ;
}
static T_3 F_48 ( struct V_79 * V_44 ,
struct V_1 * V_2 )
{
struct V_40 * V_23 = V_44 -> V_80 ;
return F_49 ( F_46 ( V_23 ) ) ;
}
static void F_50 ( struct V_79 * V_44 ,
struct V_1 * V_2 , T_3 V_81 )
{
struct V_40 * V_23 = V_44 -> V_80 ;
T_3 V_77 = F_48 ( V_44 , V_2 ) ;
T_1 V_82 = V_23 -> V_83 ;
T_3 V_84 = abs ( V_81 - V_77 ) ;
if ( V_81 > V_77 ) {
V_23 -> V_78 += V_84 ;
V_23 -> V_85 = F_51 ( V_84 , V_82 ) ;
} else {
V_23 -> V_78 -= V_84 ;
V_23 -> V_85 = - F_51 ( V_84 , V_82 ) ;
}
}
static void F_52 ( struct V_79 * V_44 ,
struct V_25 * V_86 ,
struct V_87 * V_55 )
{
struct V_40 * V_23 = V_44 -> V_80 ;
struct V_25 * V_26 ;
struct V_88 * V_58 ;
T_6 V_89 ;
struct V_90 * V_91 = F_53 ( V_86 ) ;
struct V_92 * V_93 = F_54 ( V_44 , V_91 ) ;
if ( ! F_55 ( V_94 ) )
return;
V_26 = F_56 ( V_86 , sizeof( * V_58 ) , 0 , V_95 ) ;
if ( V_26 == NULL )
return;
V_58 = (struct V_88 * ) F_57 ( V_26 , sizeof( * V_58 ) ) ;
V_58 -> V_58 . V_96 = V_97 ;
V_58 -> V_58 . V_98 = 0 ;
V_58 -> V_58 . V_99 = F_24 ( sizeof( * V_58 ) ) ;
V_58 -> V_58 . V_100 = F_58 ( ( 1 << V_101 ) |
( 1 << V_102 ) |
( 1 << V_103 ) |
( 1 << V_104 ) ) ;
V_58 -> V_105 = F_46 ( V_23 ) ;
V_58 -> V_106 = 0 ;
V_58 -> V_107 = V_93 -> V_108 / 5 ;
V_58 -> V_109 = F_24 ( V_55 -> V_110 ) ;
V_89 = V_111 ;
if ( V_93 -> V_89 & V_112 )
V_89 |= V_113 ;
else
V_89 |= V_114 ;
V_58 -> V_115 = F_24 ( V_89 ) ;
V_26 -> V_75 = V_94 ;
F_59 ( V_26 , 0 ) ;
V_26 -> V_116 = V_117 ;
V_26 -> V_118 = V_119 ;
V_26 -> V_120 = F_60 ( V_121 ) ;
memset ( V_26 -> V_122 , 0 , sizeof( V_26 -> V_122 ) ) ;
F_61 ( V_26 ) ;
}
static void F_62 ( struct V_87 * V_55 ,
const T_2 * V_8 )
{
struct V_25 * V_26 ;
struct V_123 * V_58 ;
T_6 V_89 ;
struct V_57 * V_124 ;
if ( ! F_55 ( V_94 ) )
return;
V_26 = F_22 ( 100 ) ;
if ( V_26 == NULL )
return;
V_58 = (struct V_123 * ) F_23 ( V_26 , sizeof( * V_58 ) ) ;
V_58 -> V_58 . V_96 = V_97 ;
V_58 -> V_58 . V_98 = 0 ;
V_58 -> V_58 . V_99 = F_24 ( sizeof( * V_58 ) ) ;
V_58 -> V_58 . V_100 = F_58 ( ( 1 << V_101 ) |
( 1 << V_104 ) ) ;
V_58 -> V_106 = 0 ;
V_58 -> V_125 = 0 ;
V_58 -> V_109 = F_24 ( V_55 -> V_110 ) ;
V_89 = V_111 ;
V_58 -> V_115 = F_24 ( V_89 ) ;
V_124 = (struct V_57 * ) F_23 ( V_26 , 10 ) ;
V_124 -> V_47 = F_24 ( V_48 |
V_126 ) ;
V_124 -> V_61 = F_24 ( 0 ) ;
memcpy ( V_124 -> V_62 , V_8 , V_51 ) ;
V_26 -> V_75 = V_94 ;
F_59 ( V_26 , 0 ) ;
V_26 -> V_116 = V_117 ;
V_26 -> V_118 = V_119 ;
V_26 -> V_120 = F_60 ( V_121 ) ;
memset ( V_26 -> V_122 , 0 , sizeof( V_26 -> V_122 ) ) ;
F_61 ( V_26 ) ;
}
static void F_63 ( void * V_23 , T_2 * V_39 ,
struct V_1 * V_2 )
{
struct V_127 * V_128 = V_23 ;
if ( memcmp ( V_39 , V_128 -> V_8 , V_51 ) == 0 )
V_128 -> V_129 = true ;
}
static bool F_64 ( struct V_40 * V_23 ,
const T_2 * V_8 )
{
struct V_127 V_128 = {
. V_129 = false ,
} ;
if ( V_23 -> V_130 && memcmp ( V_8 , V_23 -> V_131 , V_51 ) == 0 )
return true ;
memcpy ( V_128 . V_8 , V_8 , V_51 ) ;
F_35 ( V_23 -> V_44 ,
V_71 ,
F_63 ,
& V_128 ) ;
return V_128 . V_129 ;
}
static bool F_65 ( struct V_40 * V_23 ,
struct V_25 * V_26 )
{
switch ( V_23 -> V_56 ) {
case V_67 :
return true ;
case V_68 :
return false ;
case V_69 :
return true ;
case V_70 :
if ( V_23 -> V_72 &&
F_64 ( V_23 , V_26 -> V_23 + 4 ) ) {
V_23 -> V_72 = false ;
return true ;
}
return false ;
}
return true ;
}
static void F_66 ( struct V_79 * V_44 ,
struct V_25 * V_132 ,
int V_133 )
{
struct V_25 * V_26 ;
struct V_40 * V_23 = V_44 -> V_80 ;
struct V_57 * V_58 = (struct V_57 * ) V_132 -> V_23 ;
struct V_90 * V_91 = F_53 ( V_132 ) ;
void * V_134 ;
unsigned int V_135 = 0 ;
int V_136 ;
struct V_137 V_138 [ V_139 ] ;
if ( V_23 -> V_56 != V_67 )
V_58 -> V_47 |= F_24 ( V_50 ) ;
if ( F_67 ( & V_23 -> V_140 ) >= V_141 ) {
while ( F_67 ( & V_23 -> V_140 ) >= V_142 ) {
F_68 ( V_44 , F_69 ( & V_23 -> V_140 ) ) ;
V_23 -> V_143 ++ ;
}
}
V_26 = F_70 ( V_144 , V_95 ) ;
if ( V_26 == NULL )
goto V_145;
V_134 = F_71 ( V_26 , 0 , 0 , & V_146 , 0 ,
V_147 ) ;
if ( V_134 == NULL ) {
F_72 ( V_148 L_5 ) ;
goto V_145;
}
if ( F_73 ( V_26 , V_149 , V_51 , V_58 -> V_63 ) )
goto V_145;
if ( F_73 ( V_26 , V_150 , V_132 -> V_151 , V_132 -> V_23 ) )
goto V_145;
if ( V_91 -> V_89 & V_152 )
V_135 |= V_153 ;
if ( V_91 -> V_89 & V_154 )
V_135 |= V_155 ;
if ( F_17 ( V_26 , V_156 , V_135 ) )
goto V_145;
if ( F_17 ( V_26 , V_157 , V_23 -> V_158 -> V_110 ) )
goto V_145;
for ( V_136 = 0 ; V_136 < V_139 ; V_136 ++ ) {
V_138 [ V_136 ] . V_159 = V_91 -> V_160 . V_161 [ V_136 ] . V_159 ;
V_138 [ V_136 ] . V_162 = V_91 -> V_160 . V_161 [ V_136 ] . V_162 ;
}
if ( F_73 ( V_26 , V_163 ,
sizeof( struct V_137 ) * V_139 ,
V_138 ) )
goto V_145;
if ( F_74 ( V_26 , V_164 , ( unsigned long ) V_132 ) )
goto V_145;
F_75 ( V_26 , V_134 ) ;
if ( F_76 ( & V_165 , V_26 , V_133 ) )
goto V_166;
F_77 ( & V_23 -> V_140 , V_132 ) ;
V_23 -> V_167 ++ ;
V_23 -> V_168 += V_132 -> V_151 ;
return;
V_145:
F_78 ( V_26 ) ;
V_166:
F_72 ( V_148 L_6 , V_35 ) ;
F_68 ( V_44 , V_132 ) ;
V_23 -> V_169 ++ ;
}
static bool F_79 ( struct V_87 * V_170 ,
struct V_87 * V_171 )
{
if ( ! V_170 || ! V_171 )
return false ;
return V_170 -> V_110 == V_171 -> V_110 ;
}
static void F_80 ( void * V_172 , T_2 * V_8 ,
struct V_1 * V_2 )
{
struct V_173 * V_23 = V_172 ;
if ( ! V_2 -> V_53 )
return;
if ( ! F_79 ( V_23 -> V_158 ,
F_27 ( V_2 -> V_53 ) -> V_54 . V_55 ) )
return;
V_23 -> V_174 = true ;
}
static void F_81 ( struct V_25 * V_26 )
{
#ifdef F_82
struct V_175 * V_176 ;
V_176 = ( void * ) F_57 ( V_26 , sizeof( * V_176 ) + 8 + 4 ) ;
V_176 -> V_177 [ 0 ] = F_82 [ 0 ] ;
V_176 -> V_177 [ 1 ] = F_82 [ 1 ] ;
V_176 -> V_177 [ 2 ] = F_82 [ 2 ] ;
V_176 -> V_178 = 127 ;
V_176 -> V_179 = F_83 ( 0 ) ;
V_176 -> V_151 = 8 ;
V_176 -> V_180 = 8 ;
V_176 -> V_125 = 4 ;
memcpy ( V_176 -> V_23 , L_7 , 8 ) ;
memset ( V_176 -> V_23 + 8 , 0 , 4 ) ;
F_84 ( V_26 ) -> V_181 |= V_182 ;
#endif
}
static bool F_85 ( struct V_79 * V_44 ,
struct V_25 * V_26 ,
struct V_87 * V_55 )
{
struct V_40 * V_23 = V_44 -> V_80 , * V_183 ;
bool V_184 = false ;
struct V_57 * V_58 = (struct V_57 * ) V_26 -> V_23 ;
struct V_90 * V_91 = F_53 ( V_26 ) ;
struct V_185 V_186 ;
T_3 V_77 ;
memset ( & V_186 , 0 , sizeof( V_186 ) ) ;
V_186 . V_181 |= V_187 ;
V_186 . V_188 = V_55 -> V_110 ;
V_186 . V_189 = V_55 -> V_189 ;
if ( V_91 -> V_190 . V_161 [ 0 ] . V_89 & V_191 ) {
V_186 . V_192 =
F_86 ( & V_91 -> V_190 . V_161 [ 0 ] ) ;
V_186 . V_193 =
F_87 ( & V_91 -> V_190 . V_161 [ 0 ] ) ;
V_186 . V_181 |= V_194 ;
} else {
V_186 . V_192 = V_91 -> V_190 . V_161 [ 0 ] . V_159 ;
if ( V_91 -> V_190 . V_161 [ 0 ] . V_89 & V_195 )
V_186 . V_181 |= V_196 ;
}
if ( V_91 -> V_190 . V_161 [ 0 ] . V_89 & V_197 )
V_186 . V_181 |= V_198 ;
if ( V_91 -> V_190 . V_161 [ 0 ] . V_89 & V_199 )
V_186 . V_181 |= V_200 ;
V_186 . signal = V_23 -> V_201 - 50 ;
if ( V_23 -> V_56 != V_67 )
V_58 -> V_47 |= F_24 ( V_50 ) ;
F_88 ( V_26 ) ;
F_89 ( V_26 ) ;
V_26 -> V_202 = 0 ;
F_90 ( V_26 ) ;
F_91 ( V_26 ) ;
if ( F_92 ( V_58 -> V_47 ) ||
F_93 ( V_58 -> V_47 ) )
V_77 = V_23 -> V_203 ;
else
V_77 = F_43 () ;
F_94 ( & V_204 ) ;
F_95 (data2, &hwsim_radios, list) {
struct V_25 * V_205 ;
struct V_173 V_173 = {
. V_174 = false ,
. V_158 = V_55 ,
} ;
if ( V_23 == V_183 )
continue;
if ( ! V_183 -> V_206 || ( V_183 -> V_207 && ! V_183 -> V_208 ) ||
! F_65 ( V_183 , V_26 ) )
continue;
if ( ! ( V_23 -> V_73 & V_183 -> V_73 ) )
continue;
if ( ! F_79 ( V_55 , V_183 -> V_208 ) &&
! F_79 ( V_55 , V_183 -> V_158 ) ) {
F_35 (
V_183 -> V_44 , V_71 ,
F_80 , & V_173 ) ;
if ( ! V_173 . V_174 )
continue;
}
if ( V_26 -> V_151 < V_209 && V_210 ) {
struct V_211 * V_211 = F_96 ( V_95 ) ;
if ( ! V_211 )
continue;
V_205 = F_22 ( 128 ) ;
if ( ! V_205 ) {
F_97 ( V_211 ) ;
continue;
}
memcpy ( F_98 ( V_211 ) , V_26 -> V_23 , V_26 -> V_151 ) ;
F_99 ( V_205 , 0 , V_211 , 0 , V_26 -> V_151 , V_26 -> V_151 ) ;
} else {
V_205 = F_100 ( V_26 , V_95 ) ;
if ( ! V_205 )
continue;
}
if ( F_64 ( V_183 , V_58 -> V_62 ) )
V_184 = true ;
V_186 . V_212 = V_77 + V_183 -> V_78 ;
memcpy ( F_84 ( V_205 ) , & V_186 , sizeof( V_186 ) ) ;
F_81 ( V_205 ) ;
V_183 -> V_213 ++ ;
V_183 -> V_214 += V_205 -> V_151 ;
F_101 ( V_183 -> V_44 , V_205 ) ;
}
F_102 ( & V_204 ) ;
return V_184 ;
}
static void F_103 ( struct V_79 * V_44 ,
struct V_215 * V_190 ,
struct V_25 * V_26 )
{
struct V_40 * V_23 = V_44 -> V_80 ;
struct V_90 * V_216 = F_53 ( V_26 ) ;
struct V_15 * V_53 ;
struct V_87 * V_158 ;
bool V_184 ;
T_1 V_217 ;
if ( F_6 ( V_26 -> V_151 < 10 ) ) {
F_68 ( V_44 , V_26 ) ;
return;
}
if ( ! V_23 -> V_218 ) {
V_158 = V_23 -> V_158 ;
} else if ( V_216 -> V_219 == 4 ) {
V_158 = V_23 -> V_208 ;
} else {
V_53 = F_27 ( V_216 -> V_190 . V_2 -> V_53 ) ;
if ( V_53 )
V_158 = V_53 -> V_54 . V_55 ;
else
V_158 = NULL ;
}
if ( F_2 ( ! V_158 , L_8 , V_216 -> V_219 ) ) {
F_68 ( V_44 , V_26 ) ;
return;
}
if ( V_23 -> V_207 && ! V_23 -> V_208 ) {
F_15 ( V_44 -> V_20 , L_9 ) ;
F_68 ( V_44 , V_26 ) ;
return;
}
if ( V_216 -> V_190 . V_2 )
F_1 ( V_216 -> V_190 . V_2 ) ;
if ( V_190 -> V_11 )
F_5 ( V_190 -> V_11 ) ;
if ( F_104 ( V_44 , V_220 ) )
F_105 ( V_216 -> V_190 . V_2 , V_190 -> V_11 , V_26 ,
V_216 -> V_190 . V_161 ,
F_106 ( V_216 -> V_190 . V_161 ) ) ;
V_216 -> V_221 [ 0 ] = V_158 ;
F_52 ( V_44 , V_26 , V_158 ) ;
V_217 = F_107 ( V_222 ) ;
if ( V_217 )
return F_66 ( V_44 , V_26 , V_217 ) ;
V_23 -> V_167 ++ ;
V_23 -> V_168 += V_26 -> V_151 ;
V_184 = F_85 ( V_44 , V_26 , V_158 ) ;
if ( V_184 && V_26 -> V_151 >= 16 ) {
struct V_57 * V_58 = (struct V_57 * ) V_26 -> V_23 ;
F_62 ( V_158 , V_58 -> V_63 ) ;
}
F_108 ( V_216 ) ;
V_216 -> V_190 . V_161 [ 0 ] . V_162 = 1 ;
V_216 -> V_190 . V_161 [ 1 ] . V_159 = - 1 ;
if ( ! ( V_216 -> V_89 & V_154 ) && V_184 )
V_216 -> V_89 |= V_223 ;
F_109 ( V_44 , V_26 ) ;
}
static int F_110 ( struct V_79 * V_44 )
{
struct V_40 * V_23 = V_44 -> V_80 ;
F_15 ( V_44 -> V_20 , L_10 , V_35 ) ;
V_23 -> V_206 = true ;
return 0 ;
}
static void F_111 ( struct V_79 * V_44 )
{
struct V_40 * V_23 = V_44 -> V_80 ;
V_23 -> V_206 = false ;
F_112 ( & V_23 -> V_224 ) ;
F_15 ( V_44 -> V_20 , L_10 , V_35 ) ;
}
static int F_113 ( struct V_79 * V_44 ,
struct V_1 * V_2 )
{
F_15 ( V_44 -> V_20 , L_11 ,
V_35 , F_114 ( V_2 ) ,
V_2 -> V_8 ) ;
F_3 ( V_2 ) ;
V_2 -> V_225 = 0 ;
V_2 -> V_219 [ V_226 ] = 0 ;
V_2 -> V_219 [ V_227 ] = 1 ;
V_2 -> V_219 [ V_228 ] = 2 ;
V_2 -> V_219 [ V_229 ] = 3 ;
return 0 ;
}
static int F_115 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
enum V_230 V_231 ,
bool V_232 )
{
V_231 = F_116 ( V_231 , V_232 ) ;
F_15 ( V_44 -> V_20 ,
L_12 ,
V_35 , F_114 ( V_2 ) ,
V_231 , V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
V_2 -> V_225 = 0 ;
return 0 ;
}
static void F_117 (
struct V_79 * V_44 , struct V_1 * V_2 )
{
F_15 ( V_44 -> V_20 , L_11 ,
V_35 , F_114 ( V_2 ) ,
V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
}
static void F_26 ( struct V_79 * V_44 ,
struct V_25 * V_26 ,
struct V_87 * V_55 )
{
T_1 V_233 = F_107 ( V_222 ) ;
if ( F_104 ( V_44 , V_220 ) ) {
struct V_90 * V_216 = F_53 ( V_26 ) ;
F_105 ( V_216 -> V_190 . V_2 , NULL , V_26 ,
V_216 -> V_190 . V_161 ,
F_106 ( V_216 -> V_190 . V_161 ) ) ;
}
F_52 ( V_44 , V_26 , V_55 ) ;
if ( V_233 )
return F_66 ( V_44 , V_26 , V_233 ) ;
F_85 ( V_44 , V_26 , V_55 ) ;
F_42 ( V_26 ) ;
}
static void F_118 ( void * V_234 , T_2 * V_39 ,
struct V_1 * V_2 )
{
struct V_40 * V_23 = V_234 ;
struct V_79 * V_44 = V_23 -> V_44 ;
struct V_90 * V_91 ;
struct V_92 * V_93 ;
struct V_235 * V_236 ;
struct V_25 * V_26 ;
F_1 ( V_2 ) ;
if ( V_2 -> type != V_237 &&
V_2 -> type != V_238 &&
V_2 -> type != V_239 )
return;
V_26 = F_119 ( V_44 , V_2 ) ;
if ( V_26 == NULL )
return;
V_91 = F_53 ( V_26 ) ;
if ( F_104 ( V_44 , V_220 ) )
F_105 ( V_2 , NULL , V_26 ,
V_91 -> V_190 . V_161 ,
F_106 ( V_91 -> V_190 . V_161 ) ) ;
V_93 = F_54 ( V_44 , V_91 ) ;
V_236 = (struct V_235 * ) V_26 -> V_23 ;
V_23 -> V_203 = F_43 () ;
V_236 -> V_240 . V_241 . V_242 = F_47 ( V_23 -> V_203 +
V_23 -> V_78 +
24 * 8 * 10 / V_93 -> V_108 ) ;
F_26 ( V_44 , V_26 ,
F_27 ( V_2 -> V_53 ) -> V_54 . V_55 ) ;
if ( V_2 -> V_243 && F_120 ( V_2 ) )
F_121 ( V_2 ) ;
}
static enum V_244
F_122 ( struct V_245 * V_246 )
{
struct V_40 * V_23 =
F_123 ( V_246 , struct V_40 ,
V_224 . V_246 ) ;
struct V_79 * V_44 = V_23 -> V_44 ;
T_3 V_82 = V_23 -> V_83 ;
T_7 V_247 ;
if ( ! V_23 -> V_206 )
goto V_248;
F_35 (
V_44 , V_71 ,
F_118 , V_23 ) ;
if ( V_23 -> V_85 ) {
V_82 -= V_23 -> V_85 ;
V_23 -> V_85 = 0 ;
}
V_247 = F_124 ( F_125 ( V_246 ) ,
F_126 ( V_82 * 1000 ) ) ;
F_127 ( & V_23 -> V_224 , V_247 , V_249 ) ;
V_248:
return V_250 ;
}
static int F_128 ( struct V_79 * V_44 , T_1 V_251 )
{
struct V_40 * V_23 = V_44 -> V_80 ;
struct V_252 * V_253 = & V_44 -> V_253 ;
static const char * V_254 [ V_255 ] = {
[ V_256 ] = L_13 ,
[ V_257 ] = L_14 ,
[ V_258 ] = L_15 ,
[ V_259 ] = L_16 ,
} ;
if ( V_253 -> V_260 . V_55 )
F_15 ( V_44 -> V_20 ,
L_17 ,
V_35 ,
V_253 -> V_260 . V_55 -> V_110 ,
V_253 -> V_260 . V_261 ,
V_253 -> V_260 . V_262 ,
V_263 [ V_253 -> V_260 . V_264 ] ,
! ! ( V_253 -> V_89 & V_265 ) ,
! ! ( V_253 -> V_89 & V_266 ) ,
V_254 [ V_253 -> V_267 ] ) ;
else
F_15 ( V_44 -> V_20 ,
L_18 ,
V_35 ,
! ! ( V_253 -> V_89 & V_265 ) ,
! ! ( V_253 -> V_89 & V_266 ) ,
V_254 [ V_253 -> V_267 ] ) ;
V_23 -> V_207 = ! ! ( V_253 -> V_89 & V_265 ) ;
V_23 -> V_158 = V_253 -> V_260 . V_55 ;
F_6 ( V_23 -> V_158 && V_23 -> V_218 ) ;
V_23 -> V_201 = V_253 -> V_201 ;
if ( ! V_23 -> V_206 || ! V_23 -> V_83 )
F_112 ( & V_23 -> V_224 ) ;
else if ( ! F_129 ( & V_23 -> V_224 . V_246 ) ) {
T_3 V_81 = F_48 ( V_44 , NULL ) ;
T_1 V_82 = V_23 -> V_83 ;
T_3 V_268 = V_82 - F_51 ( V_81 , V_82 ) ;
F_127 ( & V_23 -> V_224 ,
F_126 ( V_268 * 1000 ) ,
V_269 ) ;
}
return 0 ;
}
static void F_130 ( struct V_79 * V_44 ,
unsigned int V_270 ,
unsigned int * V_271 , T_3 V_272 )
{
struct V_40 * V_23 = V_44 -> V_80 ;
F_15 ( V_44 -> V_20 , L_10 , V_35 ) ;
V_23 -> V_273 = 0 ;
if ( * V_271 & V_274 )
V_23 -> V_273 |= V_274 ;
* V_271 = V_23 -> V_273 ;
}
static void F_131 ( void * V_23 , T_2 * V_39 ,
struct V_1 * V_2 )
{
unsigned int * V_162 = V_23 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
if ( V_4 -> V_275 )
( * V_162 ) ++ ;
}
static void F_132 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_276 * V_91 ,
T_1 V_251 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_40 * V_23 = V_44 -> V_80 ;
F_1 ( V_2 ) ;
F_15 ( V_44 -> V_20 , L_19 ,
V_35 , V_251 , V_2 -> V_8 ) ;
if ( V_251 & V_277 ) {
F_15 ( V_44 -> V_20 , L_20 ,
V_35 , V_91 -> V_45 ) ;
memcpy ( V_4 -> V_45 , V_91 -> V_45 , V_51 ) ;
}
if ( V_251 & V_278 ) {
F_15 ( V_44 -> V_20 , L_21 ,
V_91 -> V_43 , V_91 -> V_46 ) ;
V_4 -> V_43 = V_91 -> V_43 ;
V_4 -> V_46 = V_91 -> V_46 ;
}
if ( V_251 & V_279 ) {
F_15 ( V_44 -> V_20 , L_22 ,
V_91 -> V_280 , V_91 -> V_83 ) ;
V_4 -> V_275 = V_91 -> V_280 ;
if ( V_23 -> V_206 &&
! F_129 ( & V_23 -> V_224 . V_246 ) &&
V_91 -> V_280 ) {
T_3 V_81 , V_268 ;
T_1 V_82 ;
V_23 -> V_83 = V_91 -> V_83 * 1024 ;
V_81 = F_48 ( V_44 , V_2 ) ;
V_82 = V_23 -> V_83 ;
V_268 = V_82 - F_51 ( V_81 , V_82 ) ;
F_127 ( & V_23 -> V_224 ,
F_126 ( V_268 * 1000 ) ,
V_269 ) ;
} else if ( ! V_91 -> V_280 ) {
unsigned int V_162 = 0 ;
F_35 (
V_23 -> V_44 , V_71 ,
F_131 , & V_162 ) ;
F_15 ( V_44 -> V_20 , L_23 ,
V_162 ) ;
if ( V_162 == 0 ) {
F_112 ( & V_23 -> V_224 ) ;
V_23 -> V_83 = 0 ;
}
}
}
if ( V_251 & V_281 ) {
F_15 ( V_44 -> V_20 , L_24 ,
V_91 -> V_282 ) ;
}
if ( V_251 & V_283 ) {
F_15 ( V_44 -> V_20 , L_25 ,
V_91 -> V_284 ) ;
}
if ( V_251 & V_285 ) {
F_15 ( V_44 -> V_20 , L_26 , V_91 -> V_286 ) ;
}
if ( V_251 & V_287 ) {
F_15 ( V_44 -> V_20 , L_27 ,
V_91 -> V_288 ) ;
}
if ( V_251 & V_289 ) {
F_15 ( V_44 -> V_20 , L_28 ,
( unsigned long long ) V_91 -> V_290 ) ;
}
if ( V_251 & V_291 )
F_15 ( V_44 -> V_20 , L_29 , V_91 -> V_292 ) ;
}
static int F_133 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_7 ( V_11 ) ;
return 0 ;
}
static int F_134 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static void F_135 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
enum V_293 V_294 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
switch ( V_294 ) {
case V_295 :
case V_296 :
break;
default:
F_2 ( 1 , L_30 , V_294 ) ;
break;
}
}
static int F_136 ( struct V_79 * V_44 ,
struct V_10 * V_11 ,
bool V_297 )
{
F_5 ( V_11 ) ;
return 0 ;
}
static int F_137 (
struct V_79 * V_44 ,
struct V_1 * V_2 , T_6 V_298 ,
const struct V_299 * V_300 )
{
F_15 ( V_44 -> V_20 ,
L_31 ,
V_35 , V_298 ,
V_300 -> V_301 , V_300 -> V_302 ,
V_300 -> V_303 , V_300 -> V_304 ) ;
return 0 ;
}
static int F_138 (
struct V_79 * V_44 , int V_159 ,
struct V_305 * V_306 )
{
struct V_252 * V_253 = & V_44 -> V_253 ;
F_15 ( V_44 -> V_20 , L_32 , V_35 , V_159 ) ;
if ( V_159 != 0 )
return - V_307 ;
V_306 -> V_158 = V_253 -> V_260 . V_55 ;
V_306 -> V_308 = V_309 ;
V_306 -> V_310 = - 92 ;
return 0 ;
}
static int F_139 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
void * V_23 , int V_151 )
{
struct V_40 * V_311 = V_44 -> V_80 ;
struct V_27 * V_28 [ V_312 + 1 ] ;
struct V_25 * V_26 ;
int V_30 , V_56 ;
V_30 = F_13 ( V_28 , V_312 , V_23 , V_151 ,
V_313 ) ;
if ( V_30 )
return V_30 ;
if ( ! V_28 [ V_314 ] )
return - V_34 ;
switch ( F_14 ( V_28 [ V_314 ] ) ) {
case V_315 :
if ( ! V_28 [ V_316 ] )
return - V_34 ;
V_56 = F_14 ( V_28 [ V_316 ] ) ;
return F_33 ( V_311 , V_56 ) ;
case V_317 :
V_26 = F_140 ( V_44 -> V_20 ,
F_141 ( sizeof( T_1 ) ) ) ;
if ( ! V_26 )
return - V_37 ;
if ( F_17 ( V_26 , V_316 , V_311 -> V_56 ) )
goto V_145;
return F_142 ( V_26 ) ;
case V_318 :
F_143 ( V_44 ) ;
return 0 ;
case V_319 :
F_144 ( V_44 ) ;
return 0 ;
default:
return - V_320 ;
}
V_145:
F_145 ( V_26 ) ;
return - V_321 ;
}
static int F_146 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
enum V_322 V_323 ,
struct V_10 * V_11 , T_6 V_324 , T_6 * V_325 ,
T_2 V_326 , bool V_327 )
{
switch ( V_323 ) {
case V_328 :
F_147 ( V_2 , V_11 -> V_8 , V_324 ) ;
break;
case V_329 :
case V_330 :
case V_331 :
F_148 ( V_2 , V_11 -> V_8 , V_324 ) ;
break;
case V_332 :
break;
case V_333 :
case V_334 :
break;
default:
return - V_320 ;
}
return 0 ;
}
static void F_149 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
T_1 V_335 , bool V_336 )
{
}
static void F_150 ( struct V_337 * V_338 )
{
struct V_40 * V_311 =
F_123 ( V_338 , struct V_40 , V_339 . V_338 ) ;
struct V_340 * V_341 = V_311 -> V_342 ;
int V_343 , V_136 ;
F_151 ( & V_311 -> V_344 ) ;
if ( V_311 -> V_345 >= V_341 -> V_346 ) {
F_15 ( V_311 -> V_44 -> V_20 , L_33 ) ;
F_152 ( V_311 -> V_44 , false ) ;
V_311 -> V_342 = NULL ;
V_311 -> V_347 = NULL ;
V_311 -> V_208 = NULL ;
F_153 ( & V_311 -> V_344 ) ;
return;
}
F_15 ( V_311 -> V_44 -> V_20 , L_34 ,
V_341 -> V_348 [ V_311 -> V_345 ] -> V_110 ) ;
V_311 -> V_208 = V_341 -> V_348 [ V_311 -> V_345 ] ;
if ( V_311 -> V_208 -> V_89 & V_349 ||
! V_341 -> V_350 ) {
V_343 = 120 ;
} else {
V_343 = 30 ;
for ( V_136 = 0 ; V_136 < V_341 -> V_350 ; V_136 ++ ) {
struct V_25 * V_351 ;
V_351 = F_154 ( V_311 -> V_44 ,
V_311 -> V_131 ,
V_341 -> V_352 [ V_136 ] . V_353 ,
V_341 -> V_352 [ V_136 ] . V_354 ,
V_341 -> V_355 ) ;
if ( ! V_351 )
continue;
if ( V_341 -> V_355 )
memcpy ( F_23 ( V_351 , V_341 -> V_355 ) , V_341 -> V_356 ,
V_341 -> V_355 ) ;
F_34 () ;
F_26 ( V_311 -> V_44 , V_351 ,
V_311 -> V_208 ) ;
F_36 () ;
}
}
F_155 ( V_311 -> V_44 , & V_311 -> V_339 ,
F_156 ( V_343 ) ) ;
V_311 -> V_345 ++ ;
F_153 ( & V_311 -> V_344 ) ;
}
static int F_157 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_357 * V_358 )
{
struct V_40 * V_311 = V_44 -> V_80 ;
struct V_340 * V_341 = & V_358 -> V_341 ;
F_151 ( & V_311 -> V_344 ) ;
if ( F_6 ( V_311 -> V_208 || V_311 -> V_342 ) ) {
F_153 ( & V_311 -> V_344 ) ;
return - V_359 ;
}
V_311 -> V_342 = V_341 ;
V_311 -> V_347 = V_2 ;
V_311 -> V_345 = 0 ;
if ( V_341 -> V_89 & V_360 )
F_158 ( V_311 -> V_131 ,
V_358 -> V_341 . V_361 ,
V_358 -> V_341 . V_362 ) ;
else
memcpy ( V_311 -> V_131 , V_2 -> V_8 , V_51 ) ;
F_153 ( & V_311 -> V_344 ) ;
F_15 ( V_44 -> V_20 , L_35 ) ;
F_155 ( V_311 -> V_44 , & V_311 -> V_339 , 0 ) ;
return 0 ;
}
static void F_159 ( struct V_79 * V_44 ,
struct V_1 * V_2 )
{
struct V_40 * V_311 = V_44 -> V_80 ;
F_15 ( V_44 -> V_20 , L_36 ) ;
F_160 ( & V_311 -> V_339 ) ;
F_151 ( & V_311 -> V_344 ) ;
F_152 ( V_311 -> V_44 , true ) ;
V_311 -> V_208 = NULL ;
V_311 -> V_342 = NULL ;
V_311 -> V_347 = NULL ;
F_153 ( & V_311 -> V_344 ) ;
}
static void F_161 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
const T_2 * V_361 )
{
struct V_40 * V_311 = V_44 -> V_80 ;
F_151 ( & V_311 -> V_344 ) ;
if ( V_311 -> V_130 ) {
F_72 ( V_148 L_37 ) ;
goto V_248;
}
F_72 ( V_148 L_38 ) ;
memcpy ( V_311 -> V_131 , V_361 , V_51 ) ;
V_311 -> V_130 = true ;
V_248:
F_153 ( & V_311 -> V_344 ) ;
}
static void F_162 ( struct V_79 * V_44 ,
struct V_1 * V_2 )
{
struct V_40 * V_311 = V_44 -> V_80 ;
F_151 ( & V_311 -> V_344 ) ;
F_72 ( V_148 L_39 ) ;
V_311 -> V_130 = false ;
F_163 ( V_311 -> V_131 ) ;
F_153 ( & V_311 -> V_344 ) ;
}
static void F_164 ( struct V_337 * V_338 )
{
struct V_40 * V_311 =
F_123 ( V_338 , struct V_40 , V_363 . V_338 ) ;
F_151 ( & V_311 -> V_344 ) ;
F_165 ( V_311 -> V_44 ) ;
V_311 -> V_208 = NULL ;
F_153 ( & V_311 -> V_344 ) ;
F_15 ( V_311 -> V_44 -> V_20 , L_40 ) ;
}
static int F_166 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_87 * V_55 ,
int V_364 ,
enum V_365 type )
{
struct V_40 * V_311 = V_44 -> V_80 ;
F_151 ( & V_311 -> V_344 ) ;
if ( F_6 ( V_311 -> V_208 || V_311 -> V_342 ) ) {
F_153 ( & V_311 -> V_344 ) ;
return - V_359 ;
}
V_311 -> V_208 = V_55 ;
F_153 ( & V_311 -> V_344 ) ;
F_15 ( V_44 -> V_20 , L_41 ,
V_55 -> V_110 , V_364 ) ;
F_167 ( V_44 ) ;
F_155 ( V_44 , & V_311 -> V_363 ,
F_156 ( V_364 ) ) ;
return 0 ;
}
static int F_168 ( struct V_79 * V_44 )
{
struct V_40 * V_311 = V_44 -> V_80 ;
F_160 ( & V_311 -> V_363 ) ;
F_151 ( & V_311 -> V_344 ) ;
V_311 -> V_208 = NULL ;
F_153 ( & V_311 -> V_344 ) ;
F_15 ( V_44 -> V_20 , L_42 ) ;
return 0 ;
}
static int F_169 ( struct V_79 * V_44 ,
struct V_15 * V_366 )
{
F_10 ( V_366 ) ;
F_15 ( V_44 -> V_20 ,
L_43 ,
V_366 -> V_54 . V_55 -> V_110 , V_366 -> V_54 . V_264 ,
V_366 -> V_54 . V_261 , V_366 -> V_54 . V_262 ) ;
return 0 ;
}
static void F_170 ( struct V_79 * V_44 ,
struct V_15 * V_366 )
{
F_15 ( V_44 -> V_20 ,
L_44 ,
V_366 -> V_54 . V_55 -> V_110 , V_366 -> V_54 . V_264 ,
V_366 -> V_54 . V_261 , V_366 -> V_54 . V_262 ) ;
F_9 ( V_366 ) ;
F_11 ( V_366 ) ;
}
static void F_171 ( struct V_79 * V_44 ,
struct V_15 * V_366 ,
T_1 V_251 )
{
F_9 ( V_366 ) ;
F_15 ( V_44 -> V_20 ,
L_45 ,
V_366 -> V_54 . V_55 -> V_110 , V_366 -> V_54 . V_264 ,
V_366 -> V_54 . V_261 , V_366 -> V_54 . V_262 ) ;
}
static int F_172 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_15 * V_366 )
{
F_1 ( V_2 ) ;
F_9 ( V_366 ) ;
return 0 ;
}
static void F_173 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_15 * V_366 )
{
F_1 ( V_2 ) ;
F_9 ( V_366 ) ;
}
static void F_174 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
T_1 V_367 , T_2 * V_23 )
{
if ( V_367 == V_368 )
memcpy ( V_23 , * V_369 ,
sizeof( V_369 ) ) ;
}
static int F_175 ( struct V_79 * V_44 ,
struct V_1 * V_2 , int V_367 )
{
if ( V_367 == V_368 )
return V_370 ;
return 0 ;
}
static void F_176 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_371 * V_372 , T_3 * V_23 )
{
struct V_40 * V_373 = V_44 -> V_80 ;
int V_136 = 0 ;
V_23 [ V_136 ++ ] = V_373 -> V_167 ;
V_23 [ V_136 ++ ] = V_373 -> V_168 ;
V_23 [ V_136 ++ ] = V_373 -> V_213 ;
V_23 [ V_136 ++ ] = V_373 -> V_214 ;
V_23 [ V_136 ++ ] = V_373 -> V_143 ;
V_23 [ V_136 ++ ] = V_373 -> V_169 ;
V_23 [ V_136 ++ ] = V_373 -> V_56 ;
V_23 [ V_136 ++ ] = V_373 -> V_73 ;
V_23 [ V_136 ++ ] = V_373 -> V_201 ;
F_6 ( V_136 != V_370 ) ;
}
static void F_177 ( struct V_25 * V_374 ,
struct V_375 * V_91 )
{
if ( V_91 )
F_178 ( & V_146 , V_374 , V_91 ,
V_376 , V_36 ) ;
else
F_179 ( & V_146 , V_374 , 0 ,
V_376 , V_36 ) ;
}
static int F_180 ( struct V_25 * V_26 , int V_377 ,
struct V_378 * V_379 )
{
int V_129 ;
V_129 = F_17 ( V_26 , V_380 , V_377 ) ;
if ( V_129 < 0 )
return V_129 ;
if ( V_379 -> V_348 ) {
V_129 = F_17 ( V_26 , V_381 , V_379 -> V_348 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_379 -> V_382 ) {
V_129 = F_73 ( V_26 , V_383 , 2 ,
V_379 -> V_382 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_379 -> V_384 ) {
int V_136 ;
for ( V_136 = 0 ; V_136 < F_106 ( V_385 ) ; V_136 ++ ) {
if ( V_385 [ V_136 ] != V_379 -> V_384 )
continue;
V_129 = F_17 ( V_26 , V_386 , V_136 ) ;
if ( V_129 < 0 )
return V_129 ;
break;
}
}
if ( V_379 -> V_387 ) {
V_129 = F_181 ( V_26 , V_388 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_379 -> V_389 ) {
V_129 = F_181 ( V_26 , V_390 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_379 -> V_218 ) {
V_129 = F_181 ( V_26 , V_391 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_379 -> V_392 ) {
V_129 = F_73 ( V_26 , V_393 ,
strlen ( V_379 -> V_392 ) , V_379 -> V_392 ) ;
if ( V_129 < 0 )
return V_129 ;
}
return 0 ;
}
static void F_182 ( int V_377 , struct V_375 * V_91 ,
struct V_378 * V_379 )
{
struct V_25 * V_374 ;
void * V_23 ;
V_374 = F_70 ( V_144 , V_36 ) ;
if ( ! V_374 )
return;
V_23 = F_71 ( V_374 , 0 , 0 , & V_146 , 0 ,
V_394 ) ;
if ( ! V_23 )
goto V_395;
if ( F_180 ( V_374 , V_377 , V_379 ) < 0 )
goto V_395;
F_75 ( V_374 , V_23 ) ;
F_177 ( V_374 , V_91 ) ;
return;
V_395:
F_183 ( V_374 , V_23 ) ;
F_78 ( V_374 ) ;
}
static int F_184 ( struct V_375 * V_91 ,
struct V_378 * V_379 )
{
int V_30 ;
T_2 V_8 [ V_51 ] ;
struct V_40 * V_23 ;
struct V_79 * V_44 ;
enum V_396 V_189 ;
const struct V_397 * V_398 = & V_399 ;
int V_159 ;
if ( F_6 ( V_379 -> V_348 > 1 && ! V_379 -> V_218 ) )
return - V_34 ;
F_185 ( & V_204 ) ;
V_159 = V_400 ++ ;
F_186 ( & V_204 ) ;
if ( V_379 -> V_218 )
V_398 = & V_401 ;
V_44 = F_187 ( sizeof( * V_23 ) , V_398 , V_379 -> V_392 ) ;
if ( ! V_44 ) {
F_72 ( V_148 L_46 ) ;
V_30 = - V_37 ;
goto V_402;
}
V_23 = V_44 -> V_80 ;
V_23 -> V_44 = V_44 ;
V_23 -> V_75 = F_188 ( V_403 , NULL , 0 , V_44 , L_47 , V_159 ) ;
if ( F_189 ( V_23 -> V_75 ) ) {
F_72 ( V_148
L_48 ,
F_190 ( V_23 -> V_75 ) ) ;
V_30 = - V_37 ;
goto V_404;
}
V_23 -> V_75 -> V_405 = & V_406 . V_405 ;
V_30 = F_191 ( V_23 -> V_75 ) ;
if ( V_30 != 0 ) {
F_72 ( V_148 L_49 ,
V_30 ) ;
goto V_407;
}
F_192 ( & V_23 -> V_140 ) ;
F_193 ( V_44 , V_23 -> V_75 ) ;
F_163 ( V_8 ) ;
V_8 [ 0 ] = 0x02 ;
V_8 [ 3 ] = V_159 >> 8 ;
V_8 [ 4 ] = V_159 ;
memcpy ( V_23 -> V_408 [ 0 ] . V_8 , V_8 , V_51 ) ;
memcpy ( V_23 -> V_408 [ 1 ] . V_8 , V_8 , V_51 ) ;
V_23 -> V_408 [ 1 ] . V_8 [ 0 ] |= 0x40 ;
V_44 -> V_20 -> V_409 = 2 ;
V_44 -> V_20 -> V_408 = V_23 -> V_408 ;
V_23 -> V_348 = V_379 -> V_348 ;
V_23 -> V_218 = V_379 -> V_218 ;
V_23 -> V_159 = V_159 ;
V_23 -> V_410 = V_379 -> V_410 ;
if ( V_91 )
V_23 -> V_411 = V_91 -> V_412 ;
if ( V_23 -> V_218 ) {
V_44 -> V_20 -> V_413 = 255 ;
V_44 -> V_20 -> V_414 = V_415 ;
V_44 -> V_20 -> V_416 = 1000 ;
V_44 -> V_20 -> V_417 = 1 ;
V_44 -> V_20 -> V_418 = & V_23 -> V_419 ;
if ( V_379 -> V_389 )
V_23 -> V_419 = V_420 [ 0 ] ;
else
V_23 -> V_419 = V_421 [ 0 ] ;
V_23 -> V_419 . V_422 = V_23 -> V_348 ;
} else if ( V_379 -> V_389 ) {
V_44 -> V_20 -> V_418 = V_420 ;
V_44 -> V_20 -> V_417 =
F_106 ( V_420 ) ;
} else {
V_44 -> V_20 -> V_418 = V_421 ;
V_44 -> V_20 -> V_417 = F_106 ( V_421 ) ;
}
F_194 ( & V_23 -> V_363 , F_164 ) ;
F_194 ( & V_23 -> V_339 , F_150 ) ;
V_44 -> V_335 = 5 ;
V_44 -> V_423 = 4 ;
V_44 -> V_20 -> V_424 = F_83 ( V_425 ) |
F_83 ( V_237 ) |
F_83 ( V_426 ) |
F_83 ( V_427 ) |
F_83 ( V_239 ) |
F_83 ( V_238 ) ;
if ( V_379 -> V_389 )
V_44 -> V_20 -> V_424 |= F_83 ( V_428 ) ;
F_195 ( V_44 , V_429 ) ;
F_195 ( V_44 , V_430 ) ;
F_195 ( V_44 , V_431 ) ;
F_195 ( V_44 , V_432 ) ;
F_195 ( V_44 , V_433 ) ;
F_195 ( V_44 , V_434 ) ;
F_195 ( V_44 , V_435 ) ;
F_195 ( V_44 , V_436 ) ;
F_195 ( V_44 , V_437 ) ;
if ( V_438 )
F_195 ( V_44 , V_220 ) ;
V_44 -> V_20 -> V_89 |= V_439 |
V_440 |
V_441 |
V_442 ;
V_44 -> V_20 -> V_443 |= V_444 |
V_445 |
V_446 |
V_447 |
V_448 ;
V_44 -> V_449 = sizeof( struct V_3 ) ;
V_44 -> V_450 = sizeof( struct V_12 ) ;
V_44 -> V_451 = sizeof( struct V_17 ) ;
memcpy ( V_23 -> V_452 , V_453 ,
sizeof( V_453 ) ) ;
memcpy ( V_23 -> V_454 , V_455 ,
sizeof( V_455 ) ) ;
memcpy ( V_23 -> V_161 , V_456 , sizeof( V_456 ) ) ;
for ( V_189 = V_457 ; V_189 < V_458 ; V_189 ++ ) {
struct V_459 * V_460 = & V_23 -> V_461 [ V_189 ] ;
switch ( V_189 ) {
case V_457 :
V_460 -> V_348 = V_23 -> V_452 ;
V_460 -> V_346 = F_106 ( V_453 ) ;
V_460 -> V_462 = V_23 -> V_161 ;
V_460 -> V_463 = F_106 ( V_456 ) ;
break;
case V_464 :
V_460 -> V_348 = V_23 -> V_454 ;
V_460 -> V_346 = F_106 ( V_455 ) ;
V_460 -> V_462 = V_23 -> V_161 + 4 ;
V_460 -> V_463 = F_106 ( V_456 ) - 4 ;
V_460 -> V_465 . V_466 = true ;
V_460 -> V_465 . V_467 =
V_468 |
V_469 |
V_470 |
V_471 |
V_472 |
V_473 |
V_474 |
V_475 |
V_476 |
V_477 |
V_478 ;
V_460 -> V_465 . V_479 . V_480 =
F_24 ( V_481 << 0 |
V_481 << 2 |
V_481 << 4 |
V_481 << 6 |
V_481 << 8 |
V_481 << 10 |
V_481 << 12 |
V_481 << 14 ) ;
V_460 -> V_465 . V_479 . V_482 =
V_460 -> V_465 . V_479 . V_480 ;
break;
default:
continue;
}
V_460 -> V_483 . V_484 = true ;
V_460 -> V_483 . V_467 = V_485 |
V_486 |
V_487 |
V_488 |
V_489 ;
V_460 -> V_483 . V_490 = 0x3 ;
V_460 -> V_483 . V_491 = 0x6 ;
memset ( & V_460 -> V_483 . V_492 , 0 ,
sizeof( V_460 -> V_483 . V_492 ) ) ;
V_460 -> V_483 . V_492 . V_493 [ 0 ] = 0xff ;
V_460 -> V_483 . V_492 . V_493 [ 1 ] = 0xff ;
V_460 -> V_483 . V_492 . V_494 = V_495 ;
V_44 -> V_20 -> V_461 [ V_189 ] = V_460 ;
}
V_23 -> V_73 = 1 ;
F_196 ( & V_23 -> V_344 ) ;
V_44 -> V_496 = 4 ;
V_44 -> V_497 = 11 ;
V_44 -> V_20 -> V_498 = V_499 ;
V_44 -> V_20 -> V_500 =
F_106 ( V_499 ) ;
V_44 -> V_20 -> V_501 = V_502 ;
V_44 -> V_20 -> V_503 = F_106 ( V_502 ) ;
if ( V_379 -> V_387 )
V_44 -> V_20 -> V_504 |= V_505 ;
if ( V_379 -> V_384 ) {
V_23 -> V_384 = V_379 -> V_384 ;
V_44 -> V_20 -> V_504 |= V_506 ;
F_197 ( V_44 -> V_20 , V_379 -> V_384 ) ;
F_198 ( 1 ) ;
}
if ( V_379 -> V_507 )
F_195 ( V_44 , V_508 ) ;
V_30 = F_199 ( V_44 ) ;
if ( V_30 < 0 ) {
F_72 ( V_148 L_50 ,
V_30 ) ;
goto V_509;
}
F_15 ( V_44 -> V_20 , L_51 , V_44 -> V_20 -> V_510 ) ;
if ( V_379 -> V_382 ) {
V_23 -> V_511 [ 0 ] = V_379 -> V_382 [ 0 ] ;
V_23 -> V_511 [ 1 ] = V_379 -> V_382 [ 1 ] ;
F_200 ( V_44 -> V_20 , V_379 -> V_382 ) ;
}
V_23 -> V_512 = F_201 ( L_52 , V_44 -> V_20 -> V_513 ) ;
F_202 ( L_53 , 0666 , V_23 -> V_512 , V_23 , & V_514 ) ;
F_202 ( L_54 , 0666 , V_23 -> V_512 , V_23 ,
& V_515 ) ;
if ( ! V_23 -> V_218 )
F_202 ( L_55 , 0222 ,
V_23 -> V_512 ,
V_23 , & V_516 ) ;
F_203 ( & V_23 -> V_224 ,
F_122 ,
V_517 , V_249 ) ;
F_185 ( & V_204 ) ;
F_204 ( & V_23 -> V_518 , & V_519 ) ;
F_186 ( & V_204 ) ;
if ( V_159 > 0 )
F_182 ( V_159 , V_91 , V_379 ) ;
return V_159 ;
V_509:
F_205 ( V_23 -> V_75 ) ;
V_407:
F_206 ( V_23 -> V_75 ) ;
V_404:
F_207 ( V_44 ) ;
V_402:
return V_30 ;
}
static void F_208 ( int V_377 , const char * V_392 ,
struct V_375 * V_91 )
{
struct V_25 * V_26 ;
void * V_23 ;
int V_129 ;
V_26 = F_70 ( V_144 , V_36 ) ;
if ( ! V_26 )
return;
V_23 = F_71 ( V_26 , 0 , 0 , & V_146 , 0 ,
V_520 ) ;
if ( ! V_23 )
goto error;
V_129 = F_17 ( V_26 , V_380 , V_377 ) ;
if ( V_129 < 0 )
goto error;
V_129 = F_73 ( V_26 , V_393 , strlen ( V_392 ) ,
V_392 ) ;
if ( V_129 < 0 )
goto error;
F_75 ( V_26 , V_23 ) ;
F_177 ( V_26 , V_91 ) ;
return;
error:
F_78 ( V_26 ) ;
}
static void F_209 ( struct V_40 * V_23 ,
const char * V_392 ,
struct V_375 * V_91 )
{
F_208 ( V_23 -> V_159 , V_392 , V_91 ) ;
F_210 ( V_23 -> V_512 ) ;
F_211 ( V_23 -> V_44 ) ;
F_205 ( V_23 -> V_75 ) ;
F_206 ( V_23 -> V_75 ) ;
F_207 ( V_23 -> V_44 ) ;
}
static int F_212 ( struct V_25 * V_26 ,
struct V_40 * V_23 ,
T_1 V_411 , T_1 V_521 ,
struct V_522 * V_122 , int V_89 )
{
void * V_58 ;
struct V_378 V_379 = { } ;
int V_523 = - V_524 ;
V_58 = F_71 ( V_26 , V_411 , V_521 , & V_146 , V_89 ,
V_525 ) ;
if ( ! V_58 )
return - V_524 ;
if ( V_122 )
F_213 ( V_122 , V_58 , & V_146 ) ;
if ( V_23 -> V_511 [ 0 ] && V_23 -> V_511 [ 1 ] )
V_379 . V_382 = V_23 -> V_511 ;
V_379 . V_387 = ! ! ( V_23 -> V_44 -> V_20 -> V_504 &
V_505 ) ;
V_379 . V_389 = ! ! ( V_23 -> V_44 -> V_20 -> V_424 &
F_83 ( V_428 ) ) ;
V_379 . V_218 = V_23 -> V_218 ;
V_379 . V_384 = V_23 -> V_384 ;
V_379 . V_348 = V_23 -> V_348 ;
V_379 . V_392 = F_214 ( V_23 -> V_44 -> V_20 ) ;
V_523 = F_180 ( V_26 , V_23 -> V_159 , & V_379 ) ;
if ( V_523 < 0 )
goto V_395;
F_75 ( V_26 , V_58 ) ;
return 0 ;
V_395:
F_183 ( V_26 , V_58 ) ;
return V_523 ;
}
static void F_215 ( void )
{
struct V_40 * V_23 ;
F_185 ( & V_204 ) ;
while ( ( V_23 = F_216 ( & V_519 ,
struct V_40 ,
V_518 ) ) ) {
F_217 ( & V_23 -> V_518 ) ;
F_186 ( & V_204 ) ;
F_209 ( V_23 , F_214 ( V_23 -> V_44 -> V_20 ) ,
NULL ) ;
F_185 ( & V_204 ) ;
}
F_186 ( & V_204 ) ;
F_218 ( V_403 ) ;
}
static void F_219 ( struct V_74 * V_75 )
{
V_75 -> V_526 = & V_527 ;
V_75 -> V_528 = V_529 ;
F_220 ( V_75 ) ;
V_75 -> V_530 |= V_531 ;
V_75 -> type = V_532 ;
F_163 ( V_75 -> V_533 ) ;
V_75 -> V_533 [ 0 ] = 0x12 ;
}
static struct V_40 * F_221 ( const T_2 * V_8 )
{
struct V_40 * V_23 ;
bool V_534 = false ;
F_185 ( & V_204 ) ;
F_95 (data, &hwsim_radios, list) {
if ( F_64 ( V_23 , V_8 ) ) {
V_534 = true ;
break;
}
}
F_186 ( & V_204 ) ;
if ( ! V_534 )
return NULL ;
return V_23 ;
}
static int F_222 ( struct V_25 * V_535 ,
struct V_375 * V_91 )
{
struct V_57 * V_58 ;
struct V_40 * V_183 ;
struct V_90 * V_216 ;
struct V_137 * V_138 ;
unsigned long V_536 ;
struct V_25 * V_26 , * V_537 ;
const T_2 * V_538 ;
unsigned int V_135 ;
int V_136 ;
bool V_539 = false ;
if ( V_91 -> V_412 != V_222 )
return - V_34 ;
if ( ! V_91 -> V_540 [ V_149 ] ||
! V_91 -> V_540 [ V_156 ] ||
! V_91 -> V_540 [ V_164 ] ||
! V_91 -> V_540 [ V_163 ] )
goto V_248;
V_538 = ( void * ) F_223 ( V_91 -> V_540 [ V_149 ] ) ;
V_135 = F_14 ( V_91 -> V_540 [ V_156 ] ) ;
V_536 = F_224 ( V_91 -> V_540 [ V_164 ] ) ;
V_183 = F_221 ( V_538 ) ;
if ( ! V_183 )
goto V_248;
F_225 (&data2->pending, skb, tmp) {
if ( ( unsigned long ) V_26 == V_536 ) {
F_226 ( V_26 , & V_183 -> V_140 ) ;
V_539 = true ;
break;
}
}
if ( ! V_539 )
goto V_248;
V_138 = (struct V_137 * ) F_223 (
V_91 -> V_540 [ V_163 ] ) ;
V_216 = F_53 ( V_26 ) ;
F_108 ( V_216 ) ;
for ( V_136 = 0 ; V_136 < V_139 ; V_136 ++ ) {
V_216 -> V_160 . V_161 [ V_136 ] . V_159 = V_138 [ V_136 ] . V_159 ;
V_216 -> V_160 . V_161 [ V_136 ] . V_162 = V_138 [ V_136 ] . V_162 ;
}
V_216 -> V_160 . V_541 = F_14 ( V_91 -> V_540 [ V_542 ] ) ;
if ( ! ( V_135 & V_155 ) &&
( V_135 & V_543 ) ) {
if ( V_26 -> V_151 >= 16 ) {
V_58 = (struct V_57 * ) V_26 -> V_23 ;
F_62 ( V_183 -> V_158 ,
V_58 -> V_63 ) ;
}
V_216 -> V_89 |= V_223 ;
}
F_109 ( V_183 -> V_44 , V_26 ) ;
return 0 ;
V_248:
return - V_34 ;
}
static int F_227 ( struct V_25 * V_535 ,
struct V_375 * V_91 )
{
struct V_40 * V_183 ;
struct V_185 V_186 ;
const T_2 * V_544 ;
int V_545 ;
void * V_546 ;
struct V_25 * V_26 = NULL ;
if ( V_91 -> V_412 != V_222 )
return - V_34 ;
if ( ! V_91 -> V_540 [ V_547 ] ||
! V_91 -> V_540 [ V_150 ] ||
! V_91 -> V_540 [ V_548 ] ||
! V_91 -> V_540 [ V_542 ] )
goto V_248;
V_544 = ( void * ) F_223 ( V_91 -> V_540 [ V_547 ] ) ;
V_545 = F_228 ( V_91 -> V_540 [ V_150 ] ) ;
V_546 = ( void * ) F_223 ( V_91 -> V_540 [ V_150 ] ) ;
V_26 = F_229 ( V_545 , V_36 ) ;
if ( V_26 == NULL )
goto V_30;
if ( V_545 > V_415 )
goto V_30;
memcpy ( F_23 ( V_26 , V_545 ) , V_546 , V_545 ) ;
V_183 = F_221 ( V_544 ) ;
if ( ! V_183 )
goto V_248;
if ( V_183 -> V_207 || ! V_183 -> V_206 )
goto V_248;
memset ( & V_186 , 0 , sizeof( V_186 ) ) ;
V_186 . V_188 = V_183 -> V_158 -> V_110 ;
V_186 . V_189 = V_183 -> V_158 -> V_189 ;
V_186 . V_192 = F_14 ( V_91 -> V_540 [ V_548 ] ) ;
V_186 . signal = F_14 ( V_91 -> V_540 [ V_542 ] ) ;
memcpy ( F_84 ( V_26 ) , & V_186 , sizeof( V_186 ) ) ;
V_183 -> V_213 ++ ;
V_183 -> V_214 += V_26 -> V_151 ;
F_101 ( V_183 -> V_44 , V_26 ) ;
return 0 ;
V_30:
F_72 ( V_148 L_6 , V_35 ) ;
V_248:
F_42 ( V_26 ) ;
return - V_34 ;
}
static int F_230 ( struct V_25 * V_535 ,
struct V_375 * V_91 )
{
struct V_40 * V_23 ;
int V_549 = 1 ;
F_185 ( & V_204 ) ;
F_95 (data, &hwsim_radios, list)
V_549 = F_231 ( V_549 , V_23 -> V_348 ) ;
F_186 ( & V_204 ) ;
if ( V_549 > 1 )
return - V_320 ;
if ( V_222 )
return - V_359 ;
V_222 = V_91 -> V_412 ;
F_72 ( V_148 L_56
L_57 , V_91 -> V_412 ) ;
return 0 ;
}
static int F_232 ( struct V_25 * V_550 , struct V_375 * V_91 )
{
struct V_378 V_379 = { 0 } ;
V_379 . V_387 = V_91 -> V_540 [ V_388 ] ;
V_379 . V_389 = V_91 -> V_540 [ V_390 ] ;
V_379 . V_348 = V_348 ;
V_379 . V_410 =
V_91 -> V_540 [ V_551 ] ;
if ( V_91 -> V_540 [ V_381 ] )
V_379 . V_348 = F_14 ( V_91 -> V_540 [ V_381 ] ) ;
if ( V_91 -> V_540 [ V_552 ] )
V_379 . V_507 = true ;
if ( V_91 -> V_540 [ V_393 ] )
V_379 . V_392 = F_223 ( V_91 -> V_540 [ V_393 ] ) ;
if ( V_91 -> V_540 [ V_391 ] )
V_379 . V_218 = true ;
else
V_379 . V_218 = ( V_379 . V_348 > 1 ) ;
if ( V_91 -> V_540 [ V_383 ] )
V_379 . V_382 =
F_223 ( V_91 -> V_540 [ V_383 ] ) ;
if ( V_91 -> V_540 [ V_386 ] ) {
T_1 V_159 = F_14 ( V_91 -> V_540 [ V_386 ] ) ;
if ( V_159 >= F_106 ( V_385 ) )
return - V_34 ;
V_379 . V_384 = V_385 [ V_159 ] ;
}
return F_184 ( V_91 , & V_379 ) ;
}
static int F_233 ( struct V_25 * V_550 , struct V_375 * V_91 )
{
struct V_40 * V_23 ;
T_8 V_159 = - 1 ;
const char * V_392 = NULL ;
if ( V_91 -> V_540 [ V_380 ] )
V_159 = F_14 ( V_91 -> V_540 [ V_380 ] ) ;
else if ( V_91 -> V_540 [ V_393 ] )
V_392 = ( void * ) F_223 ( V_91 -> V_540 [ V_393 ] ) ;
else
return - V_34 ;
F_185 ( & V_204 ) ;
F_95 (data, &hwsim_radios, list) {
if ( V_159 >= 0 ) {
if ( V_23 -> V_159 != V_159 )
continue;
} else {
if ( strcmp ( V_392 , F_214 ( V_23 -> V_44 -> V_20 ) ) )
continue;
}
F_217 ( & V_23 -> V_518 ) ;
F_186 ( & V_204 ) ;
F_209 ( V_23 , F_214 ( V_23 -> V_44 -> V_20 ) ,
V_91 ) ;
return 0 ;
}
F_186 ( & V_204 ) ;
return - V_553 ;
}
static int F_234 ( struct V_25 * V_550 , struct V_375 * V_91 )
{
struct V_40 * V_23 ;
struct V_25 * V_26 ;
int V_159 , V_523 = - V_553 ;
if ( ! V_91 -> V_540 [ V_380 ] )
return - V_34 ;
V_159 = F_14 ( V_91 -> V_540 [ V_380 ] ) ;
F_185 ( & V_204 ) ;
F_95 (data, &hwsim_radios, list) {
if ( V_23 -> V_159 != V_159 )
continue;
V_26 = F_235 ( V_554 , V_36 ) ;
if ( ! V_26 ) {
V_523 = - V_37 ;
goto V_395;
}
V_523 = F_212 ( V_26 , V_23 , V_91 -> V_412 ,
V_91 -> V_555 , NULL , 0 ) ;
if ( V_523 < 0 ) {
F_78 ( V_26 ) ;
goto V_395;
}
F_236 ( V_26 , V_91 ) ;
break;
}
V_395:
F_186 ( & V_204 ) ;
return V_523 ;
}
static int F_237 ( struct V_25 * V_26 ,
struct V_522 * V_122 )
{
int V_159 = V_122 -> args [ 0 ] ;
struct V_40 * V_23 = NULL ;
int V_523 ;
F_185 ( & V_204 ) ;
if ( V_159 == V_400 )
goto V_556;
F_95 (data, &hwsim_radios, list) {
if ( V_23 -> V_159 < V_159 )
continue;
V_523 = F_212 ( V_26 , V_23 ,
F_238 ( V_122 -> V_26 ) . V_411 ,
V_122 -> V_557 -> V_558 , V_122 ,
V_559 ) ;
if ( V_523 < 0 )
break;
V_159 = V_23 -> V_159 + 1 ;
}
V_122 -> args [ 0 ] = V_159 ;
V_556:
F_186 ( & V_204 ) ;
return V_26 -> V_151 ;
}
static void F_239 ( struct V_337 * V_338 )
{
struct V_40 * V_23 =
F_123 ( V_338 , struct V_40 , V_560 ) ;
F_209 ( V_23 , F_214 ( V_23 -> V_44 -> V_20 ) , NULL ) ;
}
static void F_240 ( T_1 V_411 )
{
struct V_40 * V_561 , * V_537 ;
F_185 ( & V_204 ) ;
F_241 (entry, tmp, &hwsim_radios, list) {
if ( V_561 -> V_410 && V_561 -> V_411 == V_411 ) {
F_217 ( & V_561 -> V_518 ) ;
F_242 ( & V_561 -> V_560 , F_239 ) ;
F_243 ( & V_561 -> V_560 ) ;
}
}
F_186 ( & V_204 ) ;
}
static int F_244 ( struct V_562 * V_563 ,
unsigned long V_564 ,
void * V_565 )
{
struct V_566 * V_567 = V_565 ;
if ( V_564 != V_568 )
return V_569 ;
F_240 ( V_567 -> V_411 ) ;
if ( V_567 -> V_411 == V_222 ) {
F_72 ( V_570 L_58
L_59 ) ;
V_222 = 0 ;
}
return V_569 ;
}
static int F_245 ( void )
{
int V_571 ;
F_72 ( V_570 L_60 ) ;
V_571 = F_246 ( & V_146 ,
V_572 ,
V_573 ) ;
if ( V_571 )
goto V_574;
V_571 = F_247 ( & V_575 ) ;
if ( V_571 ) {
F_248 ( & V_146 ) ;
goto V_574;
}
return 0 ;
V_574:
F_72 ( V_148 L_6 , V_35 ) ;
return - V_34 ;
}
static void F_249 ( void )
{
F_250 ( & V_575 ) ;
F_248 ( & V_146 ) ;
}
static int T_9 F_251 ( void )
{
int V_136 , V_30 ;
if ( V_576 < 0 || V_576 > 100 )
return - V_34 ;
if ( V_348 < 1 )
return - V_34 ;
V_401 = V_399 ;
V_401 . V_339 = F_157 ;
V_401 . V_577 = F_159 ;
V_401 . V_578 = NULL ;
V_401 . V_579 = NULL ;
V_401 . V_580 = F_166 ;
V_401 . V_581 = F_168 ;
V_401 . V_582 = F_169 ;
V_401 . V_583 = F_170 ;
V_401 . V_584 = F_171 ;
V_401 . V_585 =
F_172 ;
V_401 . V_586 =
F_173 ;
F_252 ( & V_204 ) ;
F_253 ( & V_519 ) ;
V_30 = F_254 ( & V_406 ) ;
if ( V_30 )
return V_30 ;
V_403 = F_255 ( V_587 , L_61 ) ;
if ( F_189 ( V_403 ) ) {
V_30 = F_190 ( V_403 ) ;
goto V_588;
}
V_30 = F_245 () ;
if ( V_30 < 0 )
goto V_588;
for ( V_136 = 0 ; V_136 < V_576 ; V_136 ++ ) {
struct V_378 V_379 = { 0 } ;
V_379 . V_348 = V_348 ;
switch ( V_589 ) {
case V_590 :
if ( V_136 < F_106 ( V_591 ) )
V_379 . V_382 = V_591 [ V_136 ] ;
break;
case V_592 :
if ( ! V_136 )
V_379 . V_382 = V_591 [ 0 ] ;
break;
case V_593 :
V_379 . V_387 = true ;
case V_594 :
V_379 . V_382 = V_591 [ 0 ] ;
break;
case V_595 :
if ( V_136 == 0 )
V_379 . V_384 = & V_596 ;
break;
case V_597 :
V_379 . V_384 = & V_596 ;
break;
case V_598 :
if ( V_136 == 0 )
V_379 . V_384 = & V_596 ;
else if ( V_136 == 1 )
V_379 . V_384 = & V_599 ;
break;
case V_600 :
if ( V_136 == 0 ) {
V_379 . V_387 = true ;
V_379 . V_382 = V_591 [ 0 ] ;
}
break;
case V_601 :
if ( V_136 == 0 ) {
V_379 . V_387 = true ;
V_379 . V_382 = V_591 [ 0 ] ;
} else if ( V_136 == 1 ) {
V_379 . V_382 = V_591 [ 1 ] ;
}
break;
case V_602 :
switch ( V_136 ) {
case 0 :
V_379 . V_384 = & V_596 ;
break;
case 1 :
V_379 . V_384 = & V_599 ;
break;
case 2 :
V_379 . V_382 = V_591 [ 0 ] ;
break;
case 3 :
V_379 . V_382 = V_591 [ 1 ] ;
break;
case 4 :
V_379 . V_387 = true ;
V_379 . V_382 = V_591 [ 2 ] ;
break;
}
break;
default:
break;
}
V_379 . V_389 = V_603 ;
V_379 . V_218 = V_348 > 1 ;
V_30 = F_184 ( NULL , & V_379 ) ;
if ( V_30 < 0 )
goto V_604;
}
V_94 = F_256 ( 0 , L_47 , V_605 ,
F_219 ) ;
if ( V_94 == NULL ) {
V_30 = - V_37 ;
goto V_604;
}
F_257 () ;
V_30 = F_258 ( V_94 , V_94 -> V_606 ) ;
if ( V_30 < 0 ) {
F_259 () ;
goto V_604;
}
V_30 = F_260 ( V_94 ) ;
if ( V_30 < 0 ) {
F_259 () ;
goto V_607;
}
F_259 () ;
return 0 ;
V_607:
V_529 ( V_94 ) ;
V_604:
F_215 () ;
V_588:
F_261 ( & V_406 ) ;
return V_30 ;
}
static void T_10 F_262 ( void )
{
F_72 ( V_148 L_62 ) ;
F_249 () ;
F_215 () ;
F_263 ( V_94 ) ;
F_261 ( & V_406 ) ;
}
