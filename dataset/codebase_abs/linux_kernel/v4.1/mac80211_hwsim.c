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
T_3 V_84 = F_51 ( V_81 - V_77 ) ;
if ( V_81 > V_77 ) {
V_23 -> V_78 += V_84 ;
V_23 -> V_85 = F_52 ( V_84 , V_82 ) ;
} else {
V_23 -> V_78 -= V_84 ;
V_23 -> V_85 = - F_52 ( V_84 , V_82 ) ;
}
}
static void F_53 ( struct V_79 * V_44 ,
struct V_25 * V_86 ,
struct V_87 * V_55 )
{
struct V_40 * V_23 = V_44 -> V_80 ;
struct V_25 * V_26 ;
struct V_88 * V_58 ;
T_6 V_89 ;
struct V_90 * V_91 = F_54 ( V_86 ) ;
struct V_92 * V_93 = F_55 ( V_44 , V_91 ) ;
if ( ! F_56 ( V_94 ) )
return;
V_26 = F_57 ( V_86 , sizeof( * V_58 ) , 0 , V_95 ) ;
if ( V_26 == NULL )
return;
V_58 = (struct V_88 * ) F_58 ( V_26 , sizeof( * V_58 ) ) ;
V_58 -> V_58 . V_96 = V_97 ;
V_58 -> V_58 . V_98 = 0 ;
V_58 -> V_58 . V_99 = F_24 ( sizeof( * V_58 ) ) ;
V_58 -> V_58 . V_100 = F_59 ( ( 1 << V_101 ) |
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
F_60 ( V_26 , 0 ) ;
V_26 -> V_116 = V_117 ;
V_26 -> V_118 = V_119 ;
V_26 -> V_120 = F_61 ( V_121 ) ;
memset ( V_26 -> V_122 , 0 , sizeof( V_26 -> V_122 ) ) ;
F_62 ( V_26 ) ;
}
static void F_63 ( struct V_87 * V_55 ,
const T_2 * V_8 )
{
struct V_25 * V_26 ;
struct V_123 * V_58 ;
T_6 V_89 ;
struct V_57 * V_124 ;
if ( ! F_56 ( V_94 ) )
return;
V_26 = F_22 ( 100 ) ;
if ( V_26 == NULL )
return;
V_58 = (struct V_123 * ) F_23 ( V_26 , sizeof( * V_58 ) ) ;
V_58 -> V_58 . V_96 = V_97 ;
V_58 -> V_58 . V_98 = 0 ;
V_58 -> V_58 . V_99 = F_24 ( sizeof( * V_58 ) ) ;
V_58 -> V_58 . V_100 = F_59 ( ( 1 << V_101 ) |
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
F_60 ( V_26 , 0 ) ;
V_26 -> V_116 = V_117 ;
V_26 -> V_118 = V_119 ;
V_26 -> V_120 = F_61 ( V_121 ) ;
memset ( V_26 -> V_122 , 0 , sizeof( V_26 -> V_122 ) ) ;
F_62 ( V_26 ) ;
}
static void F_64 ( void * V_23 , T_2 * V_39 ,
struct V_1 * V_2 )
{
struct V_127 * V_128 = V_23 ;
if ( memcmp ( V_39 , V_128 -> V_8 , V_51 ) == 0 )
V_128 -> V_129 = true ;
}
static bool F_65 ( struct V_40 * V_23 ,
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
F_64 ,
& V_128 ) ;
return V_128 . V_129 ;
}
static bool F_66 ( struct V_40 * V_23 ,
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
F_65 ( V_23 , V_26 -> V_23 + 4 ) ) {
V_23 -> V_72 = false ;
return true ;
}
return false ;
}
return true ;
}
static void F_67 ( struct V_79 * V_44 ,
struct V_25 * V_132 ,
int V_133 )
{
struct V_25 * V_26 ;
struct V_40 * V_23 = V_44 -> V_80 ;
struct V_57 * V_58 = (struct V_57 * ) V_132 -> V_23 ;
struct V_90 * V_91 = F_54 ( V_132 ) ;
void * V_134 ;
unsigned int V_135 = 0 ;
int V_136 ;
struct V_137 V_138 [ V_139 ] ;
if ( V_23 -> V_56 != V_67 )
V_58 -> V_47 |= F_24 ( V_50 ) ;
if ( F_68 ( & V_23 -> V_140 ) >= V_141 ) {
while ( F_68 ( & V_23 -> V_140 ) >= V_142 ) {
F_69 ( V_44 , F_70 ( & V_23 -> V_140 ) ) ;
V_23 -> V_143 ++ ;
}
}
V_26 = F_71 ( V_144 , V_95 ) ;
if ( V_26 == NULL )
goto V_145;
V_134 = F_72 ( V_26 , 0 , 0 , & V_146 , 0 ,
V_147 ) ;
if ( V_134 == NULL ) {
F_73 ( V_148 L_5 ) ;
goto V_145;
}
if ( F_74 ( V_26 , V_149 , V_51 , V_58 -> V_63 ) )
goto V_145;
if ( F_74 ( V_26 , V_150 , V_132 -> V_151 , V_132 -> V_23 ) )
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
if ( F_74 ( V_26 , V_163 ,
sizeof( struct V_137 ) * V_139 ,
V_138 ) )
goto V_145;
if ( F_75 ( V_26 , V_164 , ( unsigned long ) V_132 ) )
goto V_145;
F_76 ( V_26 , V_134 ) ;
if ( F_77 ( & V_165 , V_26 , V_133 ) )
goto V_166;
F_78 ( & V_23 -> V_140 , V_132 ) ;
V_23 -> V_167 ++ ;
V_23 -> V_168 += V_132 -> V_151 ;
return;
V_145:
F_79 ( V_26 ) ;
V_166:
F_73 ( V_148 L_6 , V_35 ) ;
F_69 ( V_44 , V_132 ) ;
V_23 -> V_169 ++ ;
}
static bool F_80 ( struct V_87 * V_170 ,
struct V_87 * V_171 )
{
if ( ! V_170 || ! V_171 )
return false ;
return V_170 -> V_110 == V_171 -> V_110 ;
}
static void F_81 ( void * V_172 , T_2 * V_8 ,
struct V_1 * V_2 )
{
struct V_173 * V_23 = V_172 ;
if ( ! V_2 -> V_53 )
return;
if ( ! F_80 ( V_23 -> V_158 ,
F_27 ( V_2 -> V_53 ) -> V_54 . V_55 ) )
return;
V_23 -> V_174 = true ;
}
static void F_82 ( struct V_25 * V_26 )
{
#ifdef F_83
struct V_175 * V_176 ;
V_176 = ( void * ) F_58 ( V_26 , sizeof( * V_176 ) + 8 + 4 ) ;
V_176 -> V_177 [ 0 ] = F_83 [ 0 ] ;
V_176 -> V_177 [ 1 ] = F_83 [ 1 ] ;
V_176 -> V_177 [ 2 ] = F_83 [ 2 ] ;
V_176 -> V_178 = 127 ;
V_176 -> V_179 = F_84 ( 0 ) ;
V_176 -> V_151 = 8 ;
V_176 -> V_180 = 8 ;
V_176 -> V_125 = 4 ;
memcpy ( V_176 -> V_23 , L_7 , 8 ) ;
memset ( V_176 -> V_23 + 8 , 0 , 4 ) ;
F_85 ( V_26 ) -> V_181 |= V_182 ;
#endif
}
static bool F_86 ( struct V_79 * V_44 ,
struct V_25 * V_26 ,
struct V_87 * V_55 )
{
struct V_40 * V_23 = V_44 -> V_80 , * V_183 ;
bool V_184 = false ;
struct V_57 * V_58 = (struct V_57 * ) V_26 -> V_23 ;
struct V_90 * V_91 = F_54 ( V_26 ) ;
struct V_185 V_186 ;
T_3 V_77 ;
memset ( & V_186 , 0 , sizeof( V_186 ) ) ;
V_186 . V_181 |= V_187 ;
V_186 . V_188 = V_55 -> V_110 ;
V_186 . V_189 = V_55 -> V_189 ;
if ( V_91 -> V_190 . V_161 [ 0 ] . V_89 & V_191 ) {
V_186 . V_192 =
F_87 ( & V_91 -> V_190 . V_161 [ 0 ] ) ;
V_186 . V_193 =
F_88 ( & V_91 -> V_190 . V_161 [ 0 ] ) ;
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
F_89 ( V_26 ) ;
F_90 ( V_26 ) ;
V_26 -> V_202 = 0 ;
F_91 ( V_26 ) ;
F_92 ( V_26 ) ;
if ( F_93 ( V_58 -> V_47 ) ||
F_94 ( V_58 -> V_47 ) )
V_77 = V_23 -> V_203 ;
else
V_77 = F_43 () ;
F_95 ( & V_204 ) ;
F_96 (data2, &hwsim_radios, list) {
struct V_25 * V_205 ;
struct V_173 V_173 = {
. V_174 = false ,
. V_158 = V_55 ,
} ;
if ( V_23 == V_183 )
continue;
if ( ! V_183 -> V_206 || ( V_183 -> V_207 && ! V_183 -> V_208 ) ||
! F_66 ( V_183 , V_26 ) )
continue;
if ( ! ( V_23 -> V_73 & V_183 -> V_73 ) )
continue;
if ( ! F_80 ( V_55 , V_183 -> V_208 ) &&
! F_80 ( V_55 , V_183 -> V_158 ) ) {
F_35 (
V_183 -> V_44 , V_71 ,
F_81 , & V_173 ) ;
if ( ! V_173 . V_174 )
continue;
}
if ( V_26 -> V_151 < V_209 && V_210 ) {
struct V_211 * V_211 = F_97 ( V_95 ) ;
if ( ! V_211 )
continue;
V_205 = F_22 ( 128 ) ;
if ( ! V_205 ) {
F_98 ( V_211 ) ;
continue;
}
memcpy ( F_99 ( V_211 ) , V_26 -> V_23 , V_26 -> V_151 ) ;
F_100 ( V_205 , 0 , V_211 , 0 , V_26 -> V_151 , V_26 -> V_151 ) ;
} else {
V_205 = F_101 ( V_26 , V_95 ) ;
if ( ! V_205 )
continue;
}
if ( F_65 ( V_183 , V_58 -> V_62 ) )
V_184 = true ;
V_186 . V_212 = V_77 + V_183 -> V_78 ;
memcpy ( F_85 ( V_205 ) , & V_186 , sizeof( V_186 ) ) ;
F_82 ( V_205 ) ;
V_183 -> V_213 ++ ;
V_183 -> V_214 += V_205 -> V_151 ;
F_102 ( V_183 -> V_44 , V_205 ) ;
}
F_103 ( & V_204 ) ;
return V_184 ;
}
static void F_104 ( struct V_79 * V_44 ,
struct V_215 * V_190 ,
struct V_25 * V_26 )
{
struct V_40 * V_23 = V_44 -> V_80 ;
struct V_90 * V_216 = F_54 ( V_26 ) ;
struct V_15 * V_53 ;
struct V_87 * V_158 ;
bool V_184 ;
T_1 V_217 ;
if ( F_6 ( V_26 -> V_151 < 10 ) ) {
F_69 ( V_44 , V_26 ) ;
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
F_69 ( V_44 , V_26 ) ;
return;
}
if ( V_23 -> V_207 && ! V_23 -> V_208 ) {
F_15 ( V_44 -> V_20 , L_9 ) ;
F_69 ( V_44 , V_26 ) ;
return;
}
if ( V_216 -> V_190 . V_2 )
F_1 ( V_216 -> V_190 . V_2 ) ;
if ( V_190 -> V_11 )
F_5 ( V_190 -> V_11 ) ;
if ( V_44 -> V_89 & V_220 )
F_105 ( V_216 -> V_190 . V_2 , V_190 -> V_11 , V_26 ,
V_216 -> V_190 . V_161 ,
F_106 ( V_216 -> V_190 . V_161 ) ) ;
V_216 -> V_221 [ 0 ] = V_158 ;
F_53 ( V_44 , V_26 , V_158 ) ;
V_217 = F_107 ( V_222 ) ;
if ( V_217 )
return F_67 ( V_44 , V_26 , V_217 ) ;
V_23 -> V_167 ++ ;
V_23 -> V_168 += V_26 -> V_151 ;
V_184 = F_86 ( V_44 , V_26 , V_158 ) ;
if ( V_184 && V_26 -> V_151 >= 16 ) {
struct V_57 * V_58 = (struct V_57 * ) V_26 -> V_23 ;
F_63 ( V_158 , V_58 -> V_63 ) ;
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
if ( V_44 -> V_89 & V_220 ) {
struct V_90 * V_216 = F_54 ( V_26 ) ;
F_105 ( V_216 -> V_190 . V_2 , NULL , V_26 ,
V_216 -> V_190 . V_161 ,
F_106 ( V_216 -> V_190 . V_161 ) ) ;
}
F_53 ( V_44 , V_26 , V_55 ) ;
if ( V_233 )
return F_67 ( V_44 , V_26 , V_233 ) ;
F_86 ( V_44 , V_26 , V_55 ) ;
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
V_91 = F_54 ( V_26 ) ;
if ( V_44 -> V_89 & V_220 )
F_105 ( V_2 , NULL , V_26 ,
V_91 -> V_190 . V_161 ,
F_106 ( V_91 -> V_190 . V_161 ) ) ;
V_93 = F_55 ( V_44 , V_91 ) ;
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
T_3 V_268 = V_82 - F_52 ( V_81 , V_82 ) ;
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
if ( * V_271 & V_275 )
V_23 -> V_273 |= V_275 ;
* V_271 = V_23 -> V_273 ;
}
static void F_131 ( void * V_23 , T_2 * V_39 ,
struct V_1 * V_2 )
{
unsigned int * V_162 = V_23 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
if ( V_4 -> V_276 )
( * V_162 ) ++ ;
}
static void F_132 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_277 * V_91 ,
T_1 V_251 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_40 * V_23 = V_44 -> V_80 ;
F_1 ( V_2 ) ;
F_15 ( V_44 -> V_20 , L_19 ,
V_35 , V_251 , V_2 -> V_8 ) ;
if ( V_251 & V_278 ) {
F_15 ( V_44 -> V_20 , L_20 ,
V_35 , V_91 -> V_45 ) ;
memcpy ( V_4 -> V_45 , V_91 -> V_45 , V_51 ) ;
}
if ( V_251 & V_279 ) {
F_15 ( V_44 -> V_20 , L_21 ,
V_91 -> V_43 , V_91 -> V_46 ) ;
V_4 -> V_43 = V_91 -> V_43 ;
V_4 -> V_46 = V_91 -> V_46 ;
}
if ( V_251 & V_280 ) {
F_15 ( V_44 -> V_20 , L_22 ,
V_91 -> V_281 , V_91 -> V_83 ) ;
V_4 -> V_276 = V_91 -> V_281 ;
if ( V_23 -> V_206 &&
! F_129 ( & V_23 -> V_224 . V_246 ) &&
V_91 -> V_281 ) {
T_3 V_81 , V_268 ;
T_1 V_82 ;
V_23 -> V_83 = V_91 -> V_83 * 1024 ;
V_81 = F_48 ( V_44 , V_2 ) ;
V_82 = V_23 -> V_83 ;
V_268 = V_82 - F_52 ( V_81 , V_82 ) ;
F_127 ( & V_23 -> V_224 ,
F_126 ( V_268 * 1000 ) ,
V_269 ) ;
} else if ( ! V_91 -> V_281 ) {
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
if ( V_251 & V_282 ) {
F_15 ( V_44 -> V_20 , L_24 ,
V_91 -> V_283 ) ;
}
if ( V_251 & V_284 ) {
F_15 ( V_44 -> V_20 , L_25 ,
V_91 -> V_285 ) ;
}
if ( V_251 & V_286 ) {
F_15 ( V_44 -> V_20 , L_26 , V_91 -> V_287 ) ;
}
if ( V_251 & V_288 ) {
F_15 ( V_44 -> V_20 , L_27 ,
V_91 -> V_289 ) ;
}
if ( V_251 & V_290 ) {
F_15 ( V_44 -> V_20 , L_28 ,
( unsigned long long ) V_91 -> V_291 ) ;
}
if ( V_251 & V_292 )
F_15 ( V_44 -> V_20 , L_29 , V_91 -> V_293 ) ;
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
enum V_294 V_295 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
switch ( V_295 ) {
case V_296 :
case V_297 :
break;
default:
F_2 ( 1 , L_30 , V_295 ) ;
break;
}
}
static int F_136 ( struct V_79 * V_44 ,
struct V_10 * V_11 ,
bool V_298 )
{
F_5 ( V_11 ) ;
return 0 ;
}
static int F_137 (
struct V_79 * V_44 ,
struct V_1 * V_2 , T_6 V_299 ,
const struct V_300 * V_301 )
{
F_15 ( V_44 -> V_20 ,
L_31 ,
V_35 , V_299 ,
V_301 -> V_302 , V_301 -> V_303 ,
V_301 -> V_304 , V_301 -> V_305 ) ;
return 0 ;
}
static int F_138 (
struct V_79 * V_44 , int V_159 ,
struct V_306 * V_307 )
{
struct V_252 * V_253 = & V_44 -> V_253 ;
F_15 ( V_44 -> V_20 , L_32 , V_35 , V_159 ) ;
if ( V_159 != 0 )
return - V_308 ;
V_307 -> V_158 = V_253 -> V_260 . V_55 ;
V_307 -> V_309 = V_310 ;
V_307 -> V_311 = - 92 ;
return 0 ;
}
static int F_139 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
void * V_23 , int V_151 )
{
struct V_40 * V_312 = V_44 -> V_80 ;
struct V_27 * V_28 [ V_313 + 1 ] ;
struct V_25 * V_26 ;
int V_30 , V_56 ;
V_30 = F_13 ( V_28 , V_313 , V_23 , V_151 ,
V_314 ) ;
if ( V_30 )
return V_30 ;
if ( ! V_28 [ V_315 ] )
return - V_34 ;
switch ( F_14 ( V_28 [ V_315 ] ) ) {
case V_316 :
if ( ! V_28 [ V_317 ] )
return - V_34 ;
V_56 = F_14 ( V_28 [ V_317 ] ) ;
return F_33 ( V_312 , V_56 ) ;
case V_318 :
V_26 = F_140 ( V_44 -> V_20 ,
F_141 ( sizeof( T_1 ) ) ) ;
if ( ! V_26 )
return - V_37 ;
if ( F_17 ( V_26 , V_317 , V_312 -> V_56 ) )
goto V_145;
return F_142 ( V_26 ) ;
case V_319 :
F_143 ( V_44 ) ;
return 0 ;
case V_320 :
F_144 ( V_44 ) ;
return 0 ;
default:
return - V_321 ;
}
V_145:
F_145 ( V_26 ) ;
return - V_322 ;
}
static int F_146 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
enum V_323 V_324 ,
struct V_10 * V_11 , T_6 V_325 , T_6 * V_326 ,
T_2 V_327 )
{
switch ( V_324 ) {
case V_328 :
F_147 ( V_2 , V_11 -> V_8 , V_325 ) ;
break;
case V_329 :
case V_330 :
case V_331 :
F_148 ( V_2 , V_11 -> V_8 , V_325 ) ;
break;
case V_332 :
break;
case V_333 :
case V_334 :
break;
default:
return - V_321 ;
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
struct V_40 * V_312 =
F_123 ( V_338 , struct V_40 , V_339 . V_338 ) ;
struct V_340 * V_341 = V_312 -> V_342 ;
int V_343 , V_136 ;
F_151 ( & V_312 -> V_344 ) ;
if ( V_312 -> V_345 >= V_341 -> V_346 ) {
F_15 ( V_312 -> V_44 -> V_20 , L_33 ) ;
F_152 ( V_312 -> V_44 , false ) ;
V_312 -> V_342 = NULL ;
V_312 -> V_347 = NULL ;
V_312 -> V_208 = NULL ;
F_153 ( & V_312 -> V_344 ) ;
return;
}
F_15 ( V_312 -> V_44 -> V_20 , L_34 ,
V_341 -> V_348 [ V_312 -> V_345 ] -> V_110 ) ;
V_312 -> V_208 = V_341 -> V_348 [ V_312 -> V_345 ] ;
if ( V_312 -> V_208 -> V_89 & V_349 ||
! V_341 -> V_350 ) {
V_343 = 120 ;
} else {
V_343 = 30 ;
for ( V_136 = 0 ; V_136 < V_341 -> V_350 ; V_136 ++ ) {
struct V_25 * V_351 ;
V_351 = F_154 ( V_312 -> V_44 ,
V_312 -> V_131 ,
V_341 -> V_352 [ V_136 ] . V_353 ,
V_341 -> V_352 [ V_136 ] . V_354 ,
V_341 -> V_355 ) ;
if ( ! V_351 )
continue;
if ( V_341 -> V_355 )
memcpy ( F_23 ( V_351 , V_341 -> V_355 ) , V_341 -> V_356 ,
V_341 -> V_355 ) ;
F_34 () ;
F_26 ( V_312 -> V_44 , V_351 ,
V_312 -> V_208 ) ;
F_36 () ;
}
}
F_155 ( V_312 -> V_44 , & V_312 -> V_339 ,
F_156 ( V_343 ) ) ;
V_312 -> V_345 ++ ;
F_153 ( & V_312 -> V_344 ) ;
}
static int F_157 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_357 * V_358 )
{
struct V_40 * V_312 = V_44 -> V_80 ;
struct V_340 * V_341 = & V_358 -> V_341 ;
F_151 ( & V_312 -> V_344 ) ;
if ( F_6 ( V_312 -> V_208 || V_312 -> V_342 ) ) {
F_153 ( & V_312 -> V_344 ) ;
return - V_359 ;
}
V_312 -> V_342 = V_341 ;
V_312 -> V_347 = V_2 ;
V_312 -> V_345 = 0 ;
if ( V_341 -> V_89 & V_360 )
F_158 ( V_312 -> V_131 ,
V_358 -> V_341 . V_361 ,
V_358 -> V_341 . V_362 ) ;
else
memcpy ( V_312 -> V_131 , V_2 -> V_8 , V_51 ) ;
F_153 ( & V_312 -> V_344 ) ;
F_15 ( V_44 -> V_20 , L_35 ) ;
F_155 ( V_312 -> V_44 , & V_312 -> V_339 , 0 ) ;
return 0 ;
}
static void F_159 ( struct V_79 * V_44 ,
struct V_1 * V_2 )
{
struct V_40 * V_312 = V_44 -> V_80 ;
F_15 ( V_44 -> V_20 , L_36 ) ;
F_160 ( & V_312 -> V_339 ) ;
F_151 ( & V_312 -> V_344 ) ;
F_152 ( V_312 -> V_44 , true ) ;
V_312 -> V_208 = NULL ;
V_312 -> V_342 = NULL ;
V_312 -> V_347 = NULL ;
F_153 ( & V_312 -> V_344 ) ;
}
static void F_161 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
const T_2 * V_361 )
{
struct V_40 * V_312 = V_44 -> V_80 ;
F_151 ( & V_312 -> V_344 ) ;
if ( V_312 -> V_130 ) {
F_73 ( V_148 L_37 ) ;
goto V_248;
}
F_73 ( V_148 L_38 ) ;
memcpy ( V_312 -> V_131 , V_361 , V_51 ) ;
V_312 -> V_130 = true ;
V_248:
F_153 ( & V_312 -> V_344 ) ;
}
static void F_162 ( struct V_79 * V_44 ,
struct V_1 * V_2 )
{
struct V_40 * V_312 = V_44 -> V_80 ;
F_151 ( & V_312 -> V_344 ) ;
F_73 ( V_148 L_39 ) ;
V_312 -> V_130 = false ;
F_163 ( V_312 -> V_131 ) ;
F_153 ( & V_312 -> V_344 ) ;
}
static void F_164 ( struct V_337 * V_338 )
{
struct V_40 * V_312 =
F_123 ( V_338 , struct V_40 , V_363 . V_338 ) ;
F_151 ( & V_312 -> V_344 ) ;
F_165 ( V_312 -> V_44 ) ;
V_312 -> V_208 = NULL ;
F_153 ( & V_312 -> V_344 ) ;
F_15 ( V_312 -> V_44 -> V_20 , L_40 ) ;
}
static int F_166 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_87 * V_55 ,
int V_364 ,
enum V_365 type )
{
struct V_40 * V_312 = V_44 -> V_80 ;
F_151 ( & V_312 -> V_344 ) ;
if ( F_6 ( V_312 -> V_208 || V_312 -> V_342 ) ) {
F_153 ( & V_312 -> V_344 ) ;
return - V_359 ;
}
V_312 -> V_208 = V_55 ;
F_153 ( & V_312 -> V_344 ) ;
F_15 ( V_44 -> V_20 , L_41 ,
V_55 -> V_110 , V_364 ) ;
F_167 ( V_44 ) ;
F_155 ( V_44 , & V_312 -> V_363 ,
F_156 ( V_364 ) ) ;
return 0 ;
}
static int F_168 ( struct V_79 * V_44 )
{
struct V_40 * V_312 = V_44 -> V_80 ;
F_160 ( & V_312 -> V_363 ) ;
F_151 ( & V_312 -> V_344 ) ;
V_312 -> V_208 = NULL ;
F_153 ( & V_312 -> V_344 ) ;
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
F_178 ( & V_146 , V_374 ,
F_179 ( V_91 ) , V_91 -> V_376 ,
V_377 , V_91 -> V_378 , V_36 ) ;
else
F_180 ( & V_146 , V_374 , 0 ,
V_377 , V_36 ) ;
}
static int F_181 ( struct V_25 * V_26 , int V_379 ,
struct V_380 * V_381 )
{
int V_129 ;
V_129 = F_17 ( V_26 , V_382 , V_379 ) ;
if ( V_129 < 0 )
return V_129 ;
if ( V_381 -> V_348 ) {
V_129 = F_17 ( V_26 , V_383 , V_381 -> V_348 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_381 -> V_384 ) {
V_129 = F_74 ( V_26 , V_385 , 2 ,
V_381 -> V_384 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_381 -> V_386 ) {
int V_136 ;
for ( V_136 = 0 ; V_136 < F_106 ( V_387 ) ; V_136 ++ ) {
if ( V_387 [ V_136 ] != V_381 -> V_386 )
continue;
V_129 = F_17 ( V_26 , V_388 , V_136 ) ;
if ( V_129 < 0 )
return V_129 ;
break;
}
}
if ( V_381 -> V_389 ) {
V_129 = F_182 ( V_26 , V_390 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_381 -> V_391 ) {
V_129 = F_182 ( V_26 , V_392 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_381 -> V_218 ) {
V_129 = F_182 ( V_26 , V_393 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_381 -> V_394 ) {
V_129 = F_74 ( V_26 , V_395 ,
strlen ( V_381 -> V_394 ) , V_381 -> V_394 ) ;
if ( V_129 < 0 )
return V_129 ;
}
return 0 ;
}
static void F_183 ( int V_379 , struct V_375 * V_91 ,
struct V_380 * V_381 )
{
struct V_25 * V_374 ;
void * V_23 ;
V_374 = F_71 ( V_144 , V_36 ) ;
if ( ! V_374 )
return;
V_23 = F_72 ( V_374 , 0 , 0 , & V_146 , 0 ,
V_396 ) ;
if ( ! V_23 )
goto V_397;
if ( F_181 ( V_374 , V_379 , V_381 ) < 0 )
goto V_397;
F_76 ( V_374 , V_23 ) ;
F_177 ( V_374 , V_91 ) ;
return;
V_397:
F_184 ( V_374 , V_23 ) ;
F_79 ( V_374 ) ;
}
static int F_185 ( struct V_375 * V_91 ,
struct V_380 * V_381 )
{
int V_30 ;
T_2 V_8 [ V_51 ] ;
struct V_40 * V_23 ;
struct V_79 * V_44 ;
enum V_398 V_189 ;
const struct V_399 * V_400 = & V_401 ;
int V_159 ;
if ( F_6 ( V_381 -> V_348 > 1 && ! V_381 -> V_218 ) )
return - V_34 ;
F_186 ( & V_204 ) ;
V_159 = V_402 ++ ;
F_187 ( & V_204 ) ;
if ( V_381 -> V_218 )
V_400 = & V_403 ;
V_44 = F_188 ( sizeof( * V_23 ) , V_400 , V_381 -> V_394 ) ;
if ( ! V_44 ) {
F_73 ( V_148 L_46 ) ;
V_30 = - V_37 ;
goto V_404;
}
V_23 = V_44 -> V_80 ;
V_23 -> V_44 = V_44 ;
V_23 -> V_75 = F_189 ( V_405 , NULL , 0 , V_44 , L_47 , V_159 ) ;
if ( F_190 ( V_23 -> V_75 ) ) {
F_73 ( V_148
L_48 ,
F_191 ( V_23 -> V_75 ) ) ;
V_30 = - V_37 ;
goto V_406;
}
V_23 -> V_75 -> V_407 = & V_408 . V_407 ;
V_30 = F_192 ( V_23 -> V_75 ) ;
if ( V_30 != 0 ) {
F_73 ( V_148 L_49 ,
V_30 ) ;
goto V_409;
}
F_193 ( & V_23 -> V_140 ) ;
F_194 ( V_44 , V_23 -> V_75 ) ;
F_163 ( V_8 ) ;
V_8 [ 0 ] = 0x02 ;
V_8 [ 3 ] = V_159 >> 8 ;
V_8 [ 4 ] = V_159 ;
memcpy ( V_23 -> V_410 [ 0 ] . V_8 , V_8 , V_51 ) ;
memcpy ( V_23 -> V_410 [ 1 ] . V_8 , V_8 , V_51 ) ;
V_23 -> V_410 [ 1 ] . V_8 [ 0 ] |= 0x40 ;
V_44 -> V_20 -> V_411 = 2 ;
V_44 -> V_20 -> V_410 = V_23 -> V_410 ;
V_23 -> V_348 = V_381 -> V_348 ;
V_23 -> V_218 = V_381 -> V_218 ;
V_23 -> V_159 = V_159 ;
V_23 -> V_412 = V_381 -> V_412 ;
if ( V_91 )
V_23 -> V_413 = V_91 -> V_376 ;
if ( V_23 -> V_218 ) {
V_44 -> V_20 -> V_414 = 255 ;
V_44 -> V_20 -> V_415 = V_416 ;
V_44 -> V_20 -> V_417 = 1000 ;
V_44 -> V_20 -> V_418 = 1 ;
V_44 -> V_20 -> V_419 = & V_23 -> V_420 ;
if ( V_381 -> V_391 )
V_23 -> V_420 = V_421 [ 0 ] ;
else
V_23 -> V_420 = V_422 [ 0 ] ;
V_23 -> V_420 . V_423 = V_23 -> V_348 ;
} else if ( V_381 -> V_391 ) {
V_44 -> V_20 -> V_419 = V_421 ;
V_44 -> V_20 -> V_418 =
F_106 ( V_421 ) ;
} else {
V_44 -> V_20 -> V_419 = V_422 ;
V_44 -> V_20 -> V_418 = F_106 ( V_422 ) ;
}
F_195 ( & V_23 -> V_363 , F_164 ) ;
F_195 ( & V_23 -> V_339 , F_150 ) ;
V_44 -> V_335 = 5 ;
V_44 -> V_424 = 4 ;
V_44 -> V_20 -> V_425 = F_84 ( V_426 ) |
F_84 ( V_237 ) |
F_84 ( V_427 ) |
F_84 ( V_428 ) |
F_84 ( V_239 ) |
F_84 ( V_238 ) ;
if ( V_381 -> V_391 )
V_44 -> V_20 -> V_425 |= F_84 ( V_429 ) ;
V_44 -> V_89 = V_430 |
V_431 |
V_432 |
V_433 |
V_434 |
V_435 |
V_436 ;
if ( V_437 )
V_44 -> V_89 |= V_220 ;
V_44 -> V_20 -> V_89 |= V_438 |
V_439 |
V_440 |
V_441 ;
V_44 -> V_20 -> V_442 |= V_443 |
V_444 |
V_445 |
V_446 |
V_447 ;
V_44 -> V_448 = sizeof( struct V_3 ) ;
V_44 -> V_449 = sizeof( struct V_12 ) ;
V_44 -> V_450 = sizeof( struct V_17 ) ;
memcpy ( V_23 -> V_451 , V_452 ,
sizeof( V_452 ) ) ;
memcpy ( V_23 -> V_453 , V_454 ,
sizeof( V_454 ) ) ;
memcpy ( V_23 -> V_161 , V_455 , sizeof( V_455 ) ) ;
for ( V_189 = V_456 ; V_189 < V_457 ; V_189 ++ ) {
struct V_458 * V_459 = & V_23 -> V_460 [ V_189 ] ;
switch ( V_189 ) {
case V_456 :
V_459 -> V_348 = V_23 -> V_451 ;
V_459 -> V_346 = F_106 ( V_452 ) ;
V_459 -> V_461 = V_23 -> V_161 ;
V_459 -> V_462 = F_106 ( V_455 ) ;
break;
case V_463 :
V_459 -> V_348 = V_23 -> V_453 ;
V_459 -> V_346 = F_106 ( V_454 ) ;
V_459 -> V_461 = V_23 -> V_161 + 4 ;
V_459 -> V_462 = F_106 ( V_455 ) - 4 ;
break;
default:
continue;
}
V_459 -> V_464 . V_465 = true ;
V_459 -> V_464 . V_466 = V_467 |
V_468 |
V_469 |
V_470 |
V_471 ;
V_459 -> V_464 . V_472 = 0x3 ;
V_459 -> V_464 . V_473 = 0x6 ;
memset ( & V_459 -> V_464 . V_474 , 0 ,
sizeof( V_459 -> V_464 . V_474 ) ) ;
V_459 -> V_464 . V_474 . V_475 [ 0 ] = 0xff ;
V_459 -> V_464 . V_474 . V_475 [ 1 ] = 0xff ;
V_459 -> V_464 . V_474 . V_476 = V_477 ;
V_44 -> V_20 -> V_460 [ V_189 ] = V_459 ;
V_459 -> V_478 . V_479 = true ;
V_459 -> V_478 . V_466 =
V_480 |
V_481 |
V_482 |
V_483 |
V_484 |
V_485 |
V_486 |
V_487 |
V_488 |
V_489 |
V_490 ;
V_459 -> V_478 . V_491 . V_492 =
F_24 ( V_493 << 0 |
V_493 << 2 |
V_494 << 4 |
V_493 << 6 |
V_493 << 8 |
V_494 << 10 |
V_494 << 12 |
V_493 << 14 ) ;
V_459 -> V_478 . V_491 . V_495 =
V_459 -> V_478 . V_491 . V_492 ;
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
if ( V_381 -> V_389 )
V_44 -> V_20 -> V_504 |= V_505 ;
if ( V_381 -> V_386 ) {
V_23 -> V_386 = V_381 -> V_386 ;
V_44 -> V_20 -> V_504 |= V_506 ;
F_197 ( V_44 -> V_20 , V_381 -> V_386 ) ;
F_198 ( 1 ) ;
}
if ( V_381 -> V_507 )
V_44 -> V_89 |= V_508 ;
V_30 = F_199 ( V_44 ) ;
if ( V_30 < 0 ) {
F_73 ( V_148 L_50 ,
V_30 ) ;
goto V_509;
}
F_15 ( V_44 -> V_20 , L_51 , V_44 -> V_20 -> V_510 ) ;
if ( V_381 -> V_384 ) {
V_23 -> V_511 [ 0 ] = V_381 -> V_384 [ 0 ] ;
V_23 -> V_511 [ 1 ] = V_381 -> V_384 [ 1 ] ;
F_200 ( V_44 -> V_20 , V_381 -> V_384 ) ;
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
F_186 ( & V_204 ) ;
F_204 ( & V_23 -> V_518 , & V_519 ) ;
F_187 ( & V_204 ) ;
if ( V_159 > 0 )
F_183 ( V_159 , V_91 , V_381 ) ;
return V_159 ;
V_509:
F_205 ( V_23 -> V_75 ) ;
V_409:
F_206 ( V_23 -> V_75 ) ;
V_406:
F_207 ( V_44 ) ;
V_404:
return V_30 ;
}
static void F_208 ( int V_379 , const char * V_394 ,
struct V_375 * V_91 )
{
struct V_25 * V_26 ;
void * V_23 ;
int V_129 ;
V_26 = F_71 ( V_144 , V_36 ) ;
if ( ! V_26 )
return;
V_23 = F_72 ( V_26 , 0 , 0 , & V_146 , 0 ,
V_520 ) ;
if ( ! V_23 )
goto error;
V_129 = F_17 ( V_26 , V_382 , V_379 ) ;
if ( V_129 < 0 )
goto error;
V_129 = F_74 ( V_26 , V_395 , strlen ( V_394 ) ,
V_394 ) ;
if ( V_129 < 0 )
goto error;
F_76 ( V_26 , V_23 ) ;
F_177 ( V_26 , V_91 ) ;
return;
error:
F_79 ( V_26 ) ;
}
static void F_209 ( struct V_40 * V_23 ,
const char * V_394 ,
struct V_375 * V_91 )
{
F_208 ( V_23 -> V_159 , V_394 , V_91 ) ;
F_210 ( V_23 -> V_512 ) ;
F_211 ( V_23 -> V_44 ) ;
F_205 ( V_23 -> V_75 ) ;
F_206 ( V_23 -> V_75 ) ;
F_207 ( V_23 -> V_44 ) ;
}
static int F_212 ( struct V_25 * V_26 ,
struct V_40 * V_23 ,
T_1 V_413 , T_1 V_521 ,
struct V_522 * V_122 , int V_89 )
{
void * V_58 ;
struct V_380 V_381 = { } ;
int V_523 = - V_524 ;
V_58 = F_72 ( V_26 , V_413 , V_521 , & V_146 , V_89 ,
V_525 ) ;
if ( ! V_58 )
return - V_524 ;
if ( V_122 )
F_213 ( V_122 , V_58 , & V_146 ) ;
if ( V_23 -> V_511 [ 0 ] && V_23 -> V_511 [ 1 ] )
V_381 . V_384 = V_23 -> V_511 ;
V_381 . V_389 = ! ! ( V_23 -> V_44 -> V_20 -> V_504 &
V_505 ) ;
V_381 . V_391 = ! ! ( V_23 -> V_44 -> V_20 -> V_425 &
F_84 ( V_429 ) ) ;
V_381 . V_218 = V_23 -> V_218 ;
V_381 . V_386 = V_23 -> V_386 ;
V_381 . V_348 = V_23 -> V_348 ;
V_381 . V_394 = F_214 ( V_23 -> V_44 -> V_20 ) ;
V_523 = F_181 ( V_26 , V_23 -> V_159 , & V_381 ) ;
if ( V_523 < 0 )
goto V_397;
F_76 ( V_26 , V_58 ) ;
return 0 ;
V_397:
F_184 ( V_26 , V_58 ) ;
return V_523 ;
}
static void F_215 ( void )
{
struct V_40 * V_23 ;
F_186 ( & V_204 ) ;
while ( ( V_23 = F_216 ( & V_519 ,
struct V_40 ,
V_518 ) ) ) {
F_217 ( & V_23 -> V_518 ) ;
F_187 ( & V_204 ) ;
F_209 ( V_23 , F_214 ( V_23 -> V_44 -> V_20 ) ,
NULL ) ;
F_186 ( & V_204 ) ;
}
F_187 ( & V_204 ) ;
F_218 ( V_405 ) ;
}
static void F_219 ( struct V_74 * V_75 )
{
V_75 -> V_526 = & V_527 ;
V_75 -> V_528 = V_529 ;
F_220 ( V_75 ) ;
V_75 -> V_530 = 0 ;
V_75 -> type = V_531 ;
F_163 ( V_75 -> V_532 ) ;
V_75 -> V_532 [ 0 ] = 0x12 ;
}
static struct V_40 * F_221 ( const T_2 * V_8 )
{
struct V_40 * V_23 ;
bool V_533 = false ;
F_186 ( & V_204 ) ;
F_96 (data, &hwsim_radios, list) {
if ( F_65 ( V_23 , V_8 ) ) {
V_533 = true ;
break;
}
}
F_187 ( & V_204 ) ;
if ( ! V_533 )
return NULL ;
return V_23 ;
}
static int F_222 ( struct V_25 * V_534 ,
struct V_375 * V_91 )
{
struct V_57 * V_58 ;
struct V_40 * V_183 ;
struct V_90 * V_216 ;
struct V_137 * V_138 ;
unsigned long V_535 ;
struct V_25 * V_26 , * V_536 ;
const T_2 * V_537 ;
unsigned int V_135 ;
int V_136 ;
bool V_538 = false ;
if ( V_91 -> V_376 != V_222 )
return - V_34 ;
if ( ! V_91 -> V_539 [ V_149 ] ||
! V_91 -> V_539 [ V_156 ] ||
! V_91 -> V_539 [ V_164 ] ||
! V_91 -> V_539 [ V_163 ] )
goto V_248;
V_537 = ( void * ) F_223 ( V_91 -> V_539 [ V_149 ] ) ;
V_135 = F_14 ( V_91 -> V_539 [ V_156 ] ) ;
V_535 = F_224 ( V_91 -> V_539 [ V_164 ] ) ;
V_183 = F_221 ( V_537 ) ;
if ( ! V_183 )
goto V_248;
F_225 (&data2->pending, skb, tmp) {
if ( ( unsigned long ) V_26 == V_535 ) {
F_226 ( V_26 , & V_183 -> V_140 ) ;
V_538 = true ;
break;
}
}
if ( ! V_538 )
goto V_248;
V_138 = (struct V_137 * ) F_223 (
V_91 -> V_539 [ V_163 ] ) ;
V_216 = F_54 ( V_26 ) ;
F_108 ( V_216 ) ;
for ( V_136 = 0 ; V_136 < V_139 ; V_136 ++ ) {
V_216 -> V_160 . V_161 [ V_136 ] . V_159 = V_138 [ V_136 ] . V_159 ;
V_216 -> V_160 . V_161 [ V_136 ] . V_162 = V_138 [ V_136 ] . V_162 ;
}
V_216 -> V_160 . V_540 = F_14 ( V_91 -> V_539 [ V_541 ] ) ;
if ( ! ( V_135 & V_155 ) &&
( V_135 & V_542 ) ) {
if ( V_26 -> V_151 >= 16 ) {
V_58 = (struct V_57 * ) V_26 -> V_23 ;
F_63 ( V_183 -> V_158 ,
V_58 -> V_63 ) ;
}
V_216 -> V_89 |= V_223 ;
}
F_109 ( V_183 -> V_44 , V_26 ) ;
return 0 ;
V_248:
return - V_34 ;
}
static int F_227 ( struct V_25 * V_534 ,
struct V_375 * V_91 )
{
struct V_40 * V_183 ;
struct V_185 V_186 ;
const T_2 * V_543 ;
int V_544 ;
void * V_545 ;
struct V_25 * V_26 = NULL ;
if ( V_91 -> V_376 != V_222 )
return - V_34 ;
if ( ! V_91 -> V_539 [ V_546 ] ||
! V_91 -> V_539 [ V_150 ] ||
! V_91 -> V_539 [ V_547 ] ||
! V_91 -> V_539 [ V_541 ] )
goto V_248;
V_543 = ( void * ) F_223 ( V_91 -> V_539 [ V_546 ] ) ;
V_544 = F_228 ( V_91 -> V_539 [ V_150 ] ) ;
V_545 = ( void * ) F_223 ( V_91 -> V_539 [ V_150 ] ) ;
V_26 = F_229 ( V_544 , V_36 ) ;
if ( V_26 == NULL )
goto V_30;
if ( V_544 > V_416 )
goto V_30;
memcpy ( F_23 ( V_26 , V_544 ) , V_545 , V_544 ) ;
V_183 = F_221 ( V_543 ) ;
if ( ! V_183 )
goto V_248;
if ( V_183 -> V_207 || ! V_183 -> V_206 )
goto V_248;
memset ( & V_186 , 0 , sizeof( V_186 ) ) ;
V_186 . V_188 = V_183 -> V_158 -> V_110 ;
V_186 . V_189 = V_183 -> V_158 -> V_189 ;
V_186 . V_192 = F_14 ( V_91 -> V_539 [ V_547 ] ) ;
V_186 . signal = F_14 ( V_91 -> V_539 [ V_541 ] ) ;
memcpy ( F_85 ( V_26 ) , & V_186 , sizeof( V_186 ) ) ;
V_183 -> V_213 ++ ;
V_183 -> V_214 += V_26 -> V_151 ;
F_102 ( V_183 -> V_44 , V_26 ) ;
return 0 ;
V_30:
F_73 ( V_148 L_6 , V_35 ) ;
V_248:
F_42 ( V_26 ) ;
return - V_34 ;
}
static int F_230 ( struct V_25 * V_534 ,
struct V_375 * V_91 )
{
struct V_40 * V_23 ;
int V_548 = 1 ;
F_186 ( & V_204 ) ;
F_96 (data, &hwsim_radios, list)
V_548 = F_231 ( V_548 , V_23 -> V_348 ) ;
F_187 ( & V_204 ) ;
if ( V_548 > 1 )
return - V_321 ;
if ( V_222 )
return - V_359 ;
V_222 = V_91 -> V_376 ;
F_73 ( V_148 L_56
L_57 , V_91 -> V_376 ) ;
return 0 ;
}
static int F_232 ( struct V_25 * V_549 , struct V_375 * V_91 )
{
struct V_380 V_381 = { 0 } ;
V_381 . V_389 = V_91 -> V_539 [ V_390 ] ;
V_381 . V_391 = V_91 -> V_539 [ V_392 ] ;
V_381 . V_348 = V_348 ;
V_381 . V_412 =
V_91 -> V_539 [ V_550 ] ;
if ( V_91 -> V_539 [ V_383 ] )
V_381 . V_348 = F_14 ( V_91 -> V_539 [ V_383 ] ) ;
if ( V_91 -> V_539 [ V_551 ] )
V_381 . V_507 = true ;
if ( V_91 -> V_539 [ V_395 ] )
V_381 . V_394 = F_223 ( V_91 -> V_539 [ V_395 ] ) ;
if ( V_91 -> V_539 [ V_393 ] )
V_381 . V_218 = true ;
else
V_381 . V_218 = ( V_381 . V_348 > 1 ) ;
if ( V_91 -> V_539 [ V_385 ] )
V_381 . V_384 =
F_223 ( V_91 -> V_539 [ V_385 ] ) ;
if ( V_91 -> V_539 [ V_388 ] ) {
T_1 V_159 = F_14 ( V_91 -> V_539 [ V_388 ] ) ;
if ( V_159 >= F_106 ( V_387 ) )
return - V_34 ;
V_381 . V_386 = V_387 [ V_159 ] ;
}
return F_185 ( V_91 , & V_381 ) ;
}
static int F_233 ( struct V_25 * V_549 , struct V_375 * V_91 )
{
struct V_40 * V_23 ;
T_8 V_159 = - 1 ;
const char * V_394 = NULL ;
if ( V_91 -> V_539 [ V_382 ] )
V_159 = F_14 ( V_91 -> V_539 [ V_382 ] ) ;
else if ( V_91 -> V_539 [ V_395 ] )
V_394 = ( void * ) F_223 ( V_91 -> V_539 [ V_395 ] ) ;
else
return - V_34 ;
F_186 ( & V_204 ) ;
F_96 (data, &hwsim_radios, list) {
if ( V_159 >= 0 ) {
if ( V_23 -> V_159 != V_159 )
continue;
} else {
if ( strcmp ( V_394 , F_214 ( V_23 -> V_44 -> V_20 ) ) )
continue;
}
F_217 ( & V_23 -> V_518 ) ;
F_187 ( & V_204 ) ;
F_209 ( V_23 , F_214 ( V_23 -> V_44 -> V_20 ) ,
V_91 ) ;
return 0 ;
}
F_187 ( & V_204 ) ;
return - V_552 ;
}
static int F_234 ( struct V_25 * V_549 , struct V_375 * V_91 )
{
struct V_40 * V_23 ;
struct V_25 * V_26 ;
int V_159 , V_523 = - V_552 ;
if ( ! V_91 -> V_539 [ V_382 ] )
return - V_34 ;
V_159 = F_14 ( V_91 -> V_539 [ V_382 ] ) ;
F_186 ( & V_204 ) ;
F_96 (data, &hwsim_radios, list) {
if ( V_23 -> V_159 != V_159 )
continue;
V_26 = F_235 ( V_553 , V_36 ) ;
if ( ! V_26 ) {
V_523 = - V_37 ;
goto V_397;
}
V_523 = F_212 ( V_26 , V_23 , V_91 -> V_376 ,
V_91 -> V_554 , NULL , 0 ) ;
if ( V_523 < 0 ) {
F_79 ( V_26 ) ;
goto V_397;
}
F_236 ( V_26 , V_91 ) ;
break;
}
V_397:
F_187 ( & V_204 ) ;
return V_523 ;
}
static int F_237 ( struct V_25 * V_26 ,
struct V_522 * V_122 )
{
int V_159 = V_122 -> args [ 0 ] ;
struct V_40 * V_23 = NULL ;
int V_523 ;
F_186 ( & V_204 ) ;
if ( V_159 == V_402 )
goto V_555;
F_96 (data, &hwsim_radios, list) {
if ( V_23 -> V_159 < V_159 )
continue;
V_523 = F_212 ( V_26 , V_23 ,
F_238 ( V_122 -> V_26 ) . V_413 ,
V_122 -> V_556 -> V_557 , V_122 ,
V_558 ) ;
if ( V_523 < 0 )
break;
V_159 = V_23 -> V_159 + 1 ;
}
V_122 -> args [ 0 ] = V_159 ;
V_555:
F_187 ( & V_204 ) ;
return V_26 -> V_151 ;
}
static void F_239 ( struct V_337 * V_338 )
{
struct V_40 * V_23 =
F_123 ( V_338 , struct V_40 , V_559 ) ;
F_209 ( V_23 , F_214 ( V_23 -> V_44 -> V_20 ) , NULL ) ;
}
static void F_240 ( T_1 V_413 )
{
struct V_40 * V_560 , * V_536 ;
F_186 ( & V_204 ) ;
F_241 (entry, tmp, &hwsim_radios, list) {
if ( V_560 -> V_412 && V_560 -> V_413 == V_413 ) {
F_217 ( & V_560 -> V_518 ) ;
F_242 ( & V_560 -> V_559 , F_239 ) ;
F_243 ( & V_560 -> V_559 ) ;
}
}
F_187 ( & V_204 ) ;
}
static int F_244 ( struct V_561 * V_562 ,
unsigned long V_563 ,
void * V_564 )
{
struct V_565 * V_566 = V_564 ;
if ( V_563 != V_567 )
return V_568 ;
F_240 ( V_566 -> V_413 ) ;
if ( V_566 -> V_413 == V_222 ) {
F_73 ( V_569 L_58
L_59 ) ;
V_222 = 0 ;
}
return V_568 ;
}
static int F_245 ( void )
{
int V_570 ;
F_73 ( V_569 L_60 ) ;
V_570 = F_246 ( & V_146 ,
V_571 ,
V_572 ) ;
if ( V_570 )
goto V_573;
V_570 = F_247 ( & V_574 ) ;
if ( V_570 )
goto V_573;
return 0 ;
V_573:
F_73 ( V_148 L_6 , V_35 ) ;
return - V_34 ;
}
static void F_248 ( void )
{
F_249 ( & V_574 ) ;
F_250 ( & V_146 ) ;
}
static int T_9 F_251 ( void )
{
int V_136 , V_30 ;
if ( V_575 < 0 || V_575 > 100 )
return - V_34 ;
if ( V_348 < 1 )
return - V_34 ;
V_403 = V_401 ;
V_403 . V_339 = F_157 ;
V_403 . V_576 = F_159 ;
V_403 . V_577 = NULL ;
V_403 . V_578 = NULL ;
V_403 . V_579 = F_166 ;
V_403 . V_580 = F_168 ;
V_403 . V_581 = F_169 ;
V_403 . V_582 = F_170 ;
V_403 . V_583 = F_171 ;
V_403 . V_584 =
F_172 ;
V_403 . V_585 =
F_173 ;
F_252 ( & V_204 ) ;
F_253 ( & V_519 ) ;
V_30 = F_254 ( & V_408 ) ;
if ( V_30 )
return V_30 ;
V_405 = F_255 ( V_586 , L_61 ) ;
if ( F_190 ( V_405 ) ) {
V_30 = F_191 ( V_405 ) ;
goto V_587;
}
V_30 = F_245 () ;
if ( V_30 < 0 )
goto V_587;
for ( V_136 = 0 ; V_136 < V_575 ; V_136 ++ ) {
struct V_380 V_381 = { 0 } ;
V_381 . V_348 = V_348 ;
switch ( V_588 ) {
case V_589 :
if ( V_136 < F_106 ( V_590 ) )
V_381 . V_384 = V_590 [ V_136 ] ;
break;
case V_591 :
if ( ! V_136 )
V_381 . V_384 = V_590 [ 0 ] ;
break;
case V_592 :
V_381 . V_389 = true ;
case V_593 :
V_381 . V_384 = V_590 [ 0 ] ;
break;
case V_594 :
if ( V_136 == 0 )
V_381 . V_386 = & V_595 ;
break;
case V_596 :
V_381 . V_386 = & V_595 ;
break;
case V_597 :
if ( V_136 == 0 )
V_381 . V_386 = & V_595 ;
else if ( V_136 == 1 )
V_381 . V_386 = & V_598 ;
break;
case V_599 :
if ( V_136 == 0 ) {
V_381 . V_389 = true ;
V_381 . V_384 = V_590 [ 0 ] ;
}
break;
case V_600 :
if ( V_136 == 0 ) {
V_381 . V_389 = true ;
V_381 . V_384 = V_590 [ 0 ] ;
} else if ( V_136 == 1 ) {
V_381 . V_384 = V_590 [ 1 ] ;
}
break;
case V_601 :
switch ( V_136 ) {
case 0 :
V_381 . V_386 = & V_595 ;
break;
case 1 :
V_381 . V_386 = & V_598 ;
break;
case 2 :
V_381 . V_384 = V_590 [ 0 ] ;
break;
case 3 :
V_381 . V_384 = V_590 [ 1 ] ;
break;
case 4 :
V_381 . V_389 = true ;
V_381 . V_384 = V_590 [ 2 ] ;
break;
}
break;
default:
break;
}
V_381 . V_391 = V_602 ;
V_381 . V_218 = V_348 > 1 ;
V_30 = F_185 ( NULL , & V_381 ) ;
if ( V_30 < 0 )
goto V_603;
}
V_94 = F_256 ( 0 , L_47 , V_604 ,
F_219 ) ;
if ( V_94 == NULL ) {
V_30 = - V_37 ;
goto V_603;
}
F_257 () ;
V_30 = F_258 ( V_94 , V_94 -> V_605 ) ;
if ( V_30 < 0 ) {
F_259 () ;
goto V_603;
}
V_30 = F_260 ( V_94 ) ;
if ( V_30 < 0 ) {
F_259 () ;
goto V_606;
}
F_259 () ;
return 0 ;
V_606:
V_529 ( V_94 ) ;
V_603:
F_215 () ;
V_587:
F_261 ( & V_408 ) ;
return V_30 ;
}
static void T_10 F_262 ( void )
{
F_73 ( V_148 L_62 ) ;
F_248 () ;
F_215 () ;
F_263 ( V_94 ) ;
F_261 ( & V_408 ) ;
}
