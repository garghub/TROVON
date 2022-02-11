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
if ( F_105 ( V_44 , V_220 ) )
F_106 ( V_216 -> V_190 . V_2 , V_190 -> V_11 , V_26 ,
V_216 -> V_190 . V_161 ,
F_107 ( V_216 -> V_190 . V_161 ) ) ;
V_216 -> V_221 [ 0 ] = V_158 ;
F_53 ( V_44 , V_26 , V_158 ) ;
V_217 = F_108 ( V_222 ) ;
if ( V_217 )
return F_67 ( V_44 , V_26 , V_217 ) ;
V_23 -> V_167 ++ ;
V_23 -> V_168 += V_26 -> V_151 ;
V_184 = F_86 ( V_44 , V_26 , V_158 ) ;
if ( V_184 && V_26 -> V_151 >= 16 ) {
struct V_57 * V_58 = (struct V_57 * ) V_26 -> V_23 ;
F_63 ( V_158 , V_58 -> V_63 ) ;
}
F_109 ( V_216 ) ;
V_216 -> V_190 . V_161 [ 0 ] . V_162 = 1 ;
V_216 -> V_190 . V_161 [ 1 ] . V_159 = - 1 ;
if ( ! ( V_216 -> V_89 & V_154 ) && V_184 )
V_216 -> V_89 |= V_223 ;
F_110 ( V_44 , V_26 ) ;
}
static int F_111 ( struct V_79 * V_44 )
{
struct V_40 * V_23 = V_44 -> V_80 ;
F_15 ( V_44 -> V_20 , L_10 , V_35 ) ;
V_23 -> V_206 = true ;
return 0 ;
}
static void F_112 ( struct V_79 * V_44 )
{
struct V_40 * V_23 = V_44 -> V_80 ;
V_23 -> V_206 = false ;
F_113 ( & V_23 -> V_224 ) ;
F_15 ( V_44 -> V_20 , L_10 , V_35 ) ;
}
static int F_114 ( struct V_79 * V_44 ,
struct V_1 * V_2 )
{
F_15 ( V_44 -> V_20 , L_11 ,
V_35 , F_115 ( V_2 ) ,
V_2 -> V_8 ) ;
F_3 ( V_2 ) ;
V_2 -> V_225 = 0 ;
V_2 -> V_219 [ V_226 ] = 0 ;
V_2 -> V_219 [ V_227 ] = 1 ;
V_2 -> V_219 [ V_228 ] = 2 ;
V_2 -> V_219 [ V_229 ] = 3 ;
return 0 ;
}
static int F_116 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
enum V_230 V_231 ,
bool V_232 )
{
V_231 = F_117 ( V_231 , V_232 ) ;
F_15 ( V_44 -> V_20 ,
L_12 ,
V_35 , F_115 ( V_2 ) ,
V_231 , V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
V_2 -> V_225 = 0 ;
return 0 ;
}
static void F_118 (
struct V_79 * V_44 , struct V_1 * V_2 )
{
F_15 ( V_44 -> V_20 , L_11 ,
V_35 , F_115 ( V_2 ) ,
V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
}
static void F_26 ( struct V_79 * V_44 ,
struct V_25 * V_26 ,
struct V_87 * V_55 )
{
T_1 V_233 = F_108 ( V_222 ) ;
if ( F_105 ( V_44 , V_220 ) ) {
struct V_90 * V_216 = F_54 ( V_26 ) ;
F_106 ( V_216 -> V_190 . V_2 , NULL , V_26 ,
V_216 -> V_190 . V_161 ,
F_107 ( V_216 -> V_190 . V_161 ) ) ;
}
F_53 ( V_44 , V_26 , V_55 ) ;
if ( V_233 )
return F_67 ( V_44 , V_26 , V_233 ) ;
F_86 ( V_44 , V_26 , V_55 ) ;
F_42 ( V_26 ) ;
}
static void F_119 ( void * V_234 , T_2 * V_39 ,
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
V_26 = F_120 ( V_44 , V_2 ) ;
if ( V_26 == NULL )
return;
V_91 = F_54 ( V_26 ) ;
if ( F_105 ( V_44 , V_220 ) )
F_106 ( V_2 , NULL , V_26 ,
V_91 -> V_190 . V_161 ,
F_107 ( V_91 -> V_190 . V_161 ) ) ;
V_93 = F_55 ( V_44 , V_91 ) ;
V_236 = (struct V_235 * ) V_26 -> V_23 ;
V_23 -> V_203 = F_43 () ;
V_236 -> V_240 . V_241 . V_242 = F_47 ( V_23 -> V_203 +
V_23 -> V_78 +
24 * 8 * 10 / V_93 -> V_108 ) ;
F_26 ( V_44 , V_26 ,
F_27 ( V_2 -> V_53 ) -> V_54 . V_55 ) ;
if ( V_2 -> V_243 && F_121 ( V_2 ) )
F_122 ( V_2 ) ;
}
static enum V_244
F_123 ( struct V_245 * V_246 )
{
struct V_40 * V_23 =
F_124 ( V_246 , struct V_40 ,
V_224 . V_246 ) ;
struct V_79 * V_44 = V_23 -> V_44 ;
T_3 V_82 = V_23 -> V_83 ;
T_7 V_247 ;
if ( ! V_23 -> V_206 )
goto V_248;
F_35 (
V_44 , V_71 ,
F_119 , V_23 ) ;
if ( V_23 -> V_85 ) {
V_82 -= V_23 -> V_85 ;
V_23 -> V_85 = 0 ;
}
V_247 = F_125 ( F_126 ( V_246 ) ,
F_127 ( V_82 * 1000 ) ) ;
F_128 ( & V_23 -> V_224 , V_247 , V_249 ) ;
V_248:
return V_250 ;
}
static int F_129 ( struct V_79 * V_44 , T_1 V_251 )
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
F_113 ( & V_23 -> V_224 ) ;
else if ( ! F_130 ( & V_23 -> V_224 . V_246 ) ) {
T_3 V_81 = F_48 ( V_44 , NULL ) ;
T_1 V_82 = V_23 -> V_83 ;
T_3 V_268 = V_82 - F_52 ( V_81 , V_82 ) ;
F_128 ( & V_23 -> V_224 ,
F_127 ( V_268 * 1000 ) ,
V_269 ) ;
}
return 0 ;
}
static void F_131 ( struct V_79 * V_44 ,
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
static void F_132 ( void * V_23 , T_2 * V_39 ,
struct V_1 * V_2 )
{
unsigned int * V_162 = V_23 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
if ( V_4 -> V_275 )
( * V_162 ) ++ ;
}
static void F_133 ( struct V_79 * V_44 ,
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
! F_130 ( & V_23 -> V_224 . V_246 ) &&
V_91 -> V_280 ) {
T_3 V_81 , V_268 ;
T_1 V_82 ;
V_23 -> V_83 = V_91 -> V_83 * 1024 ;
V_81 = F_48 ( V_44 , V_2 ) ;
V_82 = V_23 -> V_83 ;
V_268 = V_82 - F_52 ( V_81 , V_82 ) ;
F_128 ( & V_23 -> V_224 ,
F_127 ( V_268 * 1000 ) ,
V_269 ) ;
} else if ( ! V_91 -> V_280 ) {
unsigned int V_162 = 0 ;
F_35 (
V_23 -> V_44 , V_71 ,
F_132 , & V_162 ) ;
F_15 ( V_44 -> V_20 , L_23 ,
V_162 ) ;
if ( V_162 == 0 ) {
F_113 ( & V_23 -> V_224 ) ;
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
static int F_134 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_7 ( V_11 ) ;
return 0 ;
}
static int F_135 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static void F_136 ( struct V_79 * V_44 ,
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
static int F_137 ( struct V_79 * V_44 ,
struct V_10 * V_11 ,
bool V_297 )
{
F_5 ( V_11 ) ;
return 0 ;
}
static int F_138 (
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
static int F_139 (
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
static int F_140 ( struct V_79 * V_44 ,
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
V_26 = F_141 ( V_44 -> V_20 ,
F_142 ( sizeof( T_1 ) ) ) ;
if ( ! V_26 )
return - V_37 ;
if ( F_17 ( V_26 , V_316 , V_311 -> V_56 ) )
goto V_145;
return F_143 ( V_26 ) ;
case V_318 :
F_144 ( V_44 ) ;
return 0 ;
case V_319 :
F_145 ( V_44 ) ;
return 0 ;
default:
return - V_320 ;
}
V_145:
F_146 ( V_26 ) ;
return - V_321 ;
}
static int F_147 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
enum V_322 V_323 ,
struct V_10 * V_11 , T_6 V_324 , T_6 * V_325 ,
T_2 V_326 )
{
switch ( V_323 ) {
case V_327 :
F_148 ( V_2 , V_11 -> V_8 , V_324 ) ;
break;
case V_328 :
case V_329 :
case V_330 :
F_149 ( V_2 , V_11 -> V_8 , V_324 ) ;
break;
case V_331 :
break;
case V_332 :
case V_333 :
break;
default:
return - V_320 ;
}
return 0 ;
}
static void F_150 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
T_1 V_334 , bool V_335 )
{
}
static void F_151 ( struct V_336 * V_337 )
{
struct V_40 * V_311 =
F_124 ( V_337 , struct V_40 , V_338 . V_337 ) ;
struct V_339 * V_340 = V_311 -> V_341 ;
int V_342 , V_136 ;
F_152 ( & V_311 -> V_343 ) ;
if ( V_311 -> V_344 >= V_340 -> V_345 ) {
F_15 ( V_311 -> V_44 -> V_20 , L_33 ) ;
F_153 ( V_311 -> V_44 , false ) ;
V_311 -> V_341 = NULL ;
V_311 -> V_346 = NULL ;
V_311 -> V_208 = NULL ;
F_154 ( & V_311 -> V_343 ) ;
return;
}
F_15 ( V_311 -> V_44 -> V_20 , L_34 ,
V_340 -> V_347 [ V_311 -> V_344 ] -> V_110 ) ;
V_311 -> V_208 = V_340 -> V_347 [ V_311 -> V_344 ] ;
if ( V_311 -> V_208 -> V_89 & V_348 ||
! V_340 -> V_349 ) {
V_342 = 120 ;
} else {
V_342 = 30 ;
for ( V_136 = 0 ; V_136 < V_340 -> V_349 ; V_136 ++ ) {
struct V_25 * V_350 ;
V_350 = F_155 ( V_311 -> V_44 ,
V_311 -> V_131 ,
V_340 -> V_351 [ V_136 ] . V_352 ,
V_340 -> V_351 [ V_136 ] . V_353 ,
V_340 -> V_354 ) ;
if ( ! V_350 )
continue;
if ( V_340 -> V_354 )
memcpy ( F_23 ( V_350 , V_340 -> V_354 ) , V_340 -> V_355 ,
V_340 -> V_354 ) ;
F_34 () ;
F_26 ( V_311 -> V_44 , V_350 ,
V_311 -> V_208 ) ;
F_36 () ;
}
}
F_156 ( V_311 -> V_44 , & V_311 -> V_338 ,
F_157 ( V_342 ) ) ;
V_311 -> V_344 ++ ;
F_154 ( & V_311 -> V_343 ) ;
}
static int F_158 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_356 * V_357 )
{
struct V_40 * V_311 = V_44 -> V_80 ;
struct V_339 * V_340 = & V_357 -> V_340 ;
F_152 ( & V_311 -> V_343 ) ;
if ( F_6 ( V_311 -> V_208 || V_311 -> V_341 ) ) {
F_154 ( & V_311 -> V_343 ) ;
return - V_358 ;
}
V_311 -> V_341 = V_340 ;
V_311 -> V_346 = V_2 ;
V_311 -> V_344 = 0 ;
if ( V_340 -> V_89 & V_359 )
F_159 ( V_311 -> V_131 ,
V_357 -> V_340 . V_360 ,
V_357 -> V_340 . V_361 ) ;
else
memcpy ( V_311 -> V_131 , V_2 -> V_8 , V_51 ) ;
F_154 ( & V_311 -> V_343 ) ;
F_15 ( V_44 -> V_20 , L_35 ) ;
F_156 ( V_311 -> V_44 , & V_311 -> V_338 , 0 ) ;
return 0 ;
}
static void F_160 ( struct V_79 * V_44 ,
struct V_1 * V_2 )
{
struct V_40 * V_311 = V_44 -> V_80 ;
F_15 ( V_44 -> V_20 , L_36 ) ;
F_161 ( & V_311 -> V_338 ) ;
F_152 ( & V_311 -> V_343 ) ;
F_153 ( V_311 -> V_44 , true ) ;
V_311 -> V_208 = NULL ;
V_311 -> V_341 = NULL ;
V_311 -> V_346 = NULL ;
F_154 ( & V_311 -> V_343 ) ;
}
static void F_162 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
const T_2 * V_360 )
{
struct V_40 * V_311 = V_44 -> V_80 ;
F_152 ( & V_311 -> V_343 ) ;
if ( V_311 -> V_130 ) {
F_73 ( V_148 L_37 ) ;
goto V_248;
}
F_73 ( V_148 L_38 ) ;
memcpy ( V_311 -> V_131 , V_360 , V_51 ) ;
V_311 -> V_130 = true ;
V_248:
F_154 ( & V_311 -> V_343 ) ;
}
static void F_163 ( struct V_79 * V_44 ,
struct V_1 * V_2 )
{
struct V_40 * V_311 = V_44 -> V_80 ;
F_152 ( & V_311 -> V_343 ) ;
F_73 ( V_148 L_39 ) ;
V_311 -> V_130 = false ;
F_164 ( V_311 -> V_131 ) ;
F_154 ( & V_311 -> V_343 ) ;
}
static void F_165 ( struct V_336 * V_337 )
{
struct V_40 * V_311 =
F_124 ( V_337 , struct V_40 , V_362 . V_337 ) ;
F_152 ( & V_311 -> V_343 ) ;
F_166 ( V_311 -> V_44 ) ;
V_311 -> V_208 = NULL ;
F_154 ( & V_311 -> V_343 ) ;
F_15 ( V_311 -> V_44 -> V_20 , L_40 ) ;
}
static int F_167 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_87 * V_55 ,
int V_363 ,
enum V_364 type )
{
struct V_40 * V_311 = V_44 -> V_80 ;
F_152 ( & V_311 -> V_343 ) ;
if ( F_6 ( V_311 -> V_208 || V_311 -> V_341 ) ) {
F_154 ( & V_311 -> V_343 ) ;
return - V_358 ;
}
V_311 -> V_208 = V_55 ;
F_154 ( & V_311 -> V_343 ) ;
F_15 ( V_44 -> V_20 , L_41 ,
V_55 -> V_110 , V_363 ) ;
F_168 ( V_44 ) ;
F_156 ( V_44 , & V_311 -> V_362 ,
F_157 ( V_363 ) ) ;
return 0 ;
}
static int F_169 ( struct V_79 * V_44 )
{
struct V_40 * V_311 = V_44 -> V_80 ;
F_161 ( & V_311 -> V_362 ) ;
F_152 ( & V_311 -> V_343 ) ;
V_311 -> V_208 = NULL ;
F_154 ( & V_311 -> V_343 ) ;
F_15 ( V_44 -> V_20 , L_42 ) ;
return 0 ;
}
static int F_170 ( struct V_79 * V_44 ,
struct V_15 * V_365 )
{
F_10 ( V_365 ) ;
F_15 ( V_44 -> V_20 ,
L_43 ,
V_365 -> V_54 . V_55 -> V_110 , V_365 -> V_54 . V_264 ,
V_365 -> V_54 . V_261 , V_365 -> V_54 . V_262 ) ;
return 0 ;
}
static void F_171 ( struct V_79 * V_44 ,
struct V_15 * V_365 )
{
F_15 ( V_44 -> V_20 ,
L_44 ,
V_365 -> V_54 . V_55 -> V_110 , V_365 -> V_54 . V_264 ,
V_365 -> V_54 . V_261 , V_365 -> V_54 . V_262 ) ;
F_9 ( V_365 ) ;
F_11 ( V_365 ) ;
}
static void F_172 ( struct V_79 * V_44 ,
struct V_15 * V_365 ,
T_1 V_251 )
{
F_9 ( V_365 ) ;
F_15 ( V_44 -> V_20 ,
L_45 ,
V_365 -> V_54 . V_55 -> V_110 , V_365 -> V_54 . V_264 ,
V_365 -> V_54 . V_261 , V_365 -> V_54 . V_262 ) ;
}
static int F_173 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_15 * V_365 )
{
F_1 ( V_2 ) ;
F_9 ( V_365 ) ;
return 0 ;
}
static void F_174 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_15 * V_365 )
{
F_1 ( V_2 ) ;
F_9 ( V_365 ) ;
}
static void F_175 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
T_1 V_366 , T_2 * V_23 )
{
if ( V_366 == V_367 )
memcpy ( V_23 , * V_368 ,
sizeof( V_368 ) ) ;
}
static int F_176 ( struct V_79 * V_44 ,
struct V_1 * V_2 , int V_366 )
{
if ( V_366 == V_367 )
return V_369 ;
return 0 ;
}
static void F_177 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_370 * V_371 , T_3 * V_23 )
{
struct V_40 * V_372 = V_44 -> V_80 ;
int V_136 = 0 ;
V_23 [ V_136 ++ ] = V_372 -> V_167 ;
V_23 [ V_136 ++ ] = V_372 -> V_168 ;
V_23 [ V_136 ++ ] = V_372 -> V_213 ;
V_23 [ V_136 ++ ] = V_372 -> V_214 ;
V_23 [ V_136 ++ ] = V_372 -> V_143 ;
V_23 [ V_136 ++ ] = V_372 -> V_169 ;
V_23 [ V_136 ++ ] = V_372 -> V_56 ;
V_23 [ V_136 ++ ] = V_372 -> V_73 ;
V_23 [ V_136 ++ ] = V_372 -> V_201 ;
F_6 ( V_136 != V_369 ) ;
}
static void F_178 ( struct V_25 * V_373 ,
struct V_374 * V_91 )
{
if ( V_91 )
F_179 ( & V_146 , V_373 ,
F_180 ( V_91 ) , V_91 -> V_375 ,
V_376 , V_91 -> V_377 , V_36 ) ;
else
F_181 ( & V_146 , V_373 , 0 ,
V_376 , V_36 ) ;
}
static int F_182 ( struct V_25 * V_26 , int V_378 ,
struct V_379 * V_380 )
{
int V_129 ;
V_129 = F_17 ( V_26 , V_381 , V_378 ) ;
if ( V_129 < 0 )
return V_129 ;
if ( V_380 -> V_347 ) {
V_129 = F_17 ( V_26 , V_382 , V_380 -> V_347 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_380 -> V_383 ) {
V_129 = F_74 ( V_26 , V_384 , 2 ,
V_380 -> V_383 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_380 -> V_385 ) {
int V_136 ;
for ( V_136 = 0 ; V_136 < F_107 ( V_386 ) ; V_136 ++ ) {
if ( V_386 [ V_136 ] != V_380 -> V_385 )
continue;
V_129 = F_17 ( V_26 , V_387 , V_136 ) ;
if ( V_129 < 0 )
return V_129 ;
break;
}
}
if ( V_380 -> V_388 ) {
V_129 = F_183 ( V_26 , V_389 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_380 -> V_390 ) {
V_129 = F_183 ( V_26 , V_391 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_380 -> V_218 ) {
V_129 = F_183 ( V_26 , V_392 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_380 -> V_393 ) {
V_129 = F_74 ( V_26 , V_394 ,
strlen ( V_380 -> V_393 ) , V_380 -> V_393 ) ;
if ( V_129 < 0 )
return V_129 ;
}
return 0 ;
}
static void F_184 ( int V_378 , struct V_374 * V_91 ,
struct V_379 * V_380 )
{
struct V_25 * V_373 ;
void * V_23 ;
V_373 = F_71 ( V_144 , V_36 ) ;
if ( ! V_373 )
return;
V_23 = F_72 ( V_373 , 0 , 0 , & V_146 , 0 ,
V_395 ) ;
if ( ! V_23 )
goto V_396;
if ( F_182 ( V_373 , V_378 , V_380 ) < 0 )
goto V_396;
F_76 ( V_373 , V_23 ) ;
F_178 ( V_373 , V_91 ) ;
return;
V_396:
F_185 ( V_373 , V_23 ) ;
F_79 ( V_373 ) ;
}
static int F_186 ( struct V_374 * V_91 ,
struct V_379 * V_380 )
{
int V_30 ;
T_2 V_8 [ V_51 ] ;
struct V_40 * V_23 ;
struct V_79 * V_44 ;
enum V_397 V_189 ;
const struct V_398 * V_399 = & V_400 ;
int V_159 ;
if ( F_6 ( V_380 -> V_347 > 1 && ! V_380 -> V_218 ) )
return - V_34 ;
F_187 ( & V_204 ) ;
V_159 = V_401 ++ ;
F_188 ( & V_204 ) ;
if ( V_380 -> V_218 )
V_399 = & V_402 ;
V_44 = F_189 ( sizeof( * V_23 ) , V_399 , V_380 -> V_393 ) ;
if ( ! V_44 ) {
F_73 ( V_148 L_46 ) ;
V_30 = - V_37 ;
goto V_403;
}
V_23 = V_44 -> V_80 ;
V_23 -> V_44 = V_44 ;
V_23 -> V_75 = F_190 ( V_404 , NULL , 0 , V_44 , L_47 , V_159 ) ;
if ( F_191 ( V_23 -> V_75 ) ) {
F_73 ( V_148
L_48 ,
F_192 ( V_23 -> V_75 ) ) ;
V_30 = - V_37 ;
goto V_405;
}
V_23 -> V_75 -> V_406 = & V_407 . V_406 ;
V_30 = F_193 ( V_23 -> V_75 ) ;
if ( V_30 != 0 ) {
F_73 ( V_148 L_49 ,
V_30 ) ;
goto V_408;
}
F_194 ( & V_23 -> V_140 ) ;
F_195 ( V_44 , V_23 -> V_75 ) ;
F_164 ( V_8 ) ;
V_8 [ 0 ] = 0x02 ;
V_8 [ 3 ] = V_159 >> 8 ;
V_8 [ 4 ] = V_159 ;
memcpy ( V_23 -> V_409 [ 0 ] . V_8 , V_8 , V_51 ) ;
memcpy ( V_23 -> V_409 [ 1 ] . V_8 , V_8 , V_51 ) ;
V_23 -> V_409 [ 1 ] . V_8 [ 0 ] |= 0x40 ;
V_44 -> V_20 -> V_410 = 2 ;
V_44 -> V_20 -> V_409 = V_23 -> V_409 ;
V_23 -> V_347 = V_380 -> V_347 ;
V_23 -> V_218 = V_380 -> V_218 ;
V_23 -> V_159 = V_159 ;
V_23 -> V_411 = V_380 -> V_411 ;
if ( V_91 )
V_23 -> V_412 = V_91 -> V_375 ;
if ( V_23 -> V_218 ) {
V_44 -> V_20 -> V_413 = 255 ;
V_44 -> V_20 -> V_414 = V_415 ;
V_44 -> V_20 -> V_416 = 1000 ;
V_44 -> V_20 -> V_417 = 1 ;
V_44 -> V_20 -> V_418 = & V_23 -> V_419 ;
if ( V_380 -> V_390 )
V_23 -> V_419 = V_420 [ 0 ] ;
else
V_23 -> V_419 = V_421 [ 0 ] ;
V_23 -> V_419 . V_422 = V_23 -> V_347 ;
} else if ( V_380 -> V_390 ) {
V_44 -> V_20 -> V_418 = V_420 ;
V_44 -> V_20 -> V_417 =
F_107 ( V_420 ) ;
} else {
V_44 -> V_20 -> V_418 = V_421 ;
V_44 -> V_20 -> V_417 = F_107 ( V_421 ) ;
}
F_196 ( & V_23 -> V_362 , F_165 ) ;
F_196 ( & V_23 -> V_338 , F_151 ) ;
V_44 -> V_334 = 5 ;
V_44 -> V_423 = 4 ;
V_44 -> V_20 -> V_424 = F_84 ( V_425 ) |
F_84 ( V_237 ) |
F_84 ( V_426 ) |
F_84 ( V_427 ) |
F_84 ( V_239 ) |
F_84 ( V_238 ) ;
if ( V_380 -> V_390 )
V_44 -> V_20 -> V_424 |= F_84 ( V_428 ) ;
F_197 ( V_44 , V_429 ) ;
F_197 ( V_44 , V_430 ) ;
F_197 ( V_44 , V_431 ) ;
F_197 ( V_44 , V_432 ) ;
F_197 ( V_44 , V_433 ) ;
F_197 ( V_44 , V_434 ) ;
F_197 ( V_44 , V_435 ) ;
F_197 ( V_44 , V_436 ) ;
F_197 ( V_44 , V_437 ) ;
if ( V_438 )
F_197 ( V_44 , V_220 ) ;
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
V_460 -> V_347 = V_23 -> V_452 ;
V_460 -> V_345 = F_107 ( V_453 ) ;
V_460 -> V_462 = V_23 -> V_161 ;
V_460 -> V_463 = F_107 ( V_456 ) ;
break;
case V_464 :
V_460 -> V_347 = V_23 -> V_454 ;
V_460 -> V_345 = F_107 ( V_455 ) ;
V_460 -> V_462 = V_23 -> V_161 + 4 ;
V_460 -> V_463 = F_107 ( V_456 ) - 4 ;
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
F_198 ( & V_23 -> V_343 ) ;
V_44 -> V_496 = 4 ;
V_44 -> V_497 = 11 ;
V_44 -> V_20 -> V_498 = V_499 ;
V_44 -> V_20 -> V_500 =
F_107 ( V_499 ) ;
V_44 -> V_20 -> V_501 = V_502 ;
V_44 -> V_20 -> V_503 = F_107 ( V_502 ) ;
if ( V_380 -> V_388 )
V_44 -> V_20 -> V_504 |= V_505 ;
if ( V_380 -> V_385 ) {
V_23 -> V_385 = V_380 -> V_385 ;
V_44 -> V_20 -> V_504 |= V_506 ;
F_199 ( V_44 -> V_20 , V_380 -> V_385 ) ;
F_200 ( 1 ) ;
}
if ( V_380 -> V_507 )
F_197 ( V_44 , V_508 ) ;
V_30 = F_201 ( V_44 ) ;
if ( V_30 < 0 ) {
F_73 ( V_148 L_50 ,
V_30 ) ;
goto V_509;
}
F_15 ( V_44 -> V_20 , L_51 , V_44 -> V_20 -> V_510 ) ;
if ( V_380 -> V_383 ) {
V_23 -> V_511 [ 0 ] = V_380 -> V_383 [ 0 ] ;
V_23 -> V_511 [ 1 ] = V_380 -> V_383 [ 1 ] ;
F_202 ( V_44 -> V_20 , V_380 -> V_383 ) ;
}
V_23 -> V_512 = F_203 ( L_52 , V_44 -> V_20 -> V_513 ) ;
F_204 ( L_53 , 0666 , V_23 -> V_512 , V_23 , & V_514 ) ;
F_204 ( L_54 , 0666 , V_23 -> V_512 , V_23 ,
& V_515 ) ;
if ( ! V_23 -> V_218 )
F_204 ( L_55 , 0222 ,
V_23 -> V_512 ,
V_23 , & V_516 ) ;
F_205 ( & V_23 -> V_224 ,
F_123 ,
V_517 , V_249 ) ;
F_187 ( & V_204 ) ;
F_206 ( & V_23 -> V_518 , & V_519 ) ;
F_188 ( & V_204 ) ;
if ( V_159 > 0 )
F_184 ( V_159 , V_91 , V_380 ) ;
return V_159 ;
V_509:
F_207 ( V_23 -> V_75 ) ;
V_408:
F_208 ( V_23 -> V_75 ) ;
V_405:
F_209 ( V_44 ) ;
V_403:
return V_30 ;
}
static void F_210 ( int V_378 , const char * V_393 ,
struct V_374 * V_91 )
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
V_129 = F_17 ( V_26 , V_381 , V_378 ) ;
if ( V_129 < 0 )
goto error;
V_129 = F_74 ( V_26 , V_394 , strlen ( V_393 ) ,
V_393 ) ;
if ( V_129 < 0 )
goto error;
F_76 ( V_26 , V_23 ) ;
F_178 ( V_26 , V_91 ) ;
return;
error:
F_79 ( V_26 ) ;
}
static void F_211 ( struct V_40 * V_23 ,
const char * V_393 ,
struct V_374 * V_91 )
{
F_210 ( V_23 -> V_159 , V_393 , V_91 ) ;
F_212 ( V_23 -> V_512 ) ;
F_213 ( V_23 -> V_44 ) ;
F_207 ( V_23 -> V_75 ) ;
F_208 ( V_23 -> V_75 ) ;
F_209 ( V_23 -> V_44 ) ;
}
static int F_214 ( struct V_25 * V_26 ,
struct V_40 * V_23 ,
T_1 V_412 , T_1 V_521 ,
struct V_522 * V_122 , int V_89 )
{
void * V_58 ;
struct V_379 V_380 = { } ;
int V_523 = - V_524 ;
V_58 = F_72 ( V_26 , V_412 , V_521 , & V_146 , V_89 ,
V_525 ) ;
if ( ! V_58 )
return - V_524 ;
if ( V_122 )
F_215 ( V_122 , V_58 , & V_146 ) ;
if ( V_23 -> V_511 [ 0 ] && V_23 -> V_511 [ 1 ] )
V_380 . V_383 = V_23 -> V_511 ;
V_380 . V_388 = ! ! ( V_23 -> V_44 -> V_20 -> V_504 &
V_505 ) ;
V_380 . V_390 = ! ! ( V_23 -> V_44 -> V_20 -> V_424 &
F_84 ( V_428 ) ) ;
V_380 . V_218 = V_23 -> V_218 ;
V_380 . V_385 = V_23 -> V_385 ;
V_380 . V_347 = V_23 -> V_347 ;
V_380 . V_393 = F_216 ( V_23 -> V_44 -> V_20 ) ;
V_523 = F_182 ( V_26 , V_23 -> V_159 , & V_380 ) ;
if ( V_523 < 0 )
goto V_396;
F_76 ( V_26 , V_58 ) ;
return 0 ;
V_396:
F_185 ( V_26 , V_58 ) ;
return V_523 ;
}
static void F_217 ( void )
{
struct V_40 * V_23 ;
F_187 ( & V_204 ) ;
while ( ( V_23 = F_218 ( & V_519 ,
struct V_40 ,
V_518 ) ) ) {
F_219 ( & V_23 -> V_518 ) ;
F_188 ( & V_204 ) ;
F_211 ( V_23 , F_216 ( V_23 -> V_44 -> V_20 ) ,
NULL ) ;
F_187 ( & V_204 ) ;
}
F_188 ( & V_204 ) ;
F_220 ( V_404 ) ;
}
static void F_221 ( struct V_74 * V_75 )
{
V_75 -> V_526 = & V_527 ;
V_75 -> V_528 = V_529 ;
F_222 ( V_75 ) ;
V_75 -> V_530 |= V_531 ;
V_75 -> type = V_532 ;
F_164 ( V_75 -> V_533 ) ;
V_75 -> V_533 [ 0 ] = 0x12 ;
}
static struct V_40 * F_223 ( const T_2 * V_8 )
{
struct V_40 * V_23 ;
bool V_534 = false ;
F_187 ( & V_204 ) ;
F_96 (data, &hwsim_radios, list) {
if ( F_65 ( V_23 , V_8 ) ) {
V_534 = true ;
break;
}
}
F_188 ( & V_204 ) ;
if ( ! V_534 )
return NULL ;
return V_23 ;
}
static int F_224 ( struct V_25 * V_535 ,
struct V_374 * V_91 )
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
if ( V_91 -> V_375 != V_222 )
return - V_34 ;
if ( ! V_91 -> V_540 [ V_149 ] ||
! V_91 -> V_540 [ V_156 ] ||
! V_91 -> V_540 [ V_164 ] ||
! V_91 -> V_540 [ V_163 ] )
goto V_248;
V_538 = ( void * ) F_225 ( V_91 -> V_540 [ V_149 ] ) ;
V_135 = F_14 ( V_91 -> V_540 [ V_156 ] ) ;
V_536 = F_226 ( V_91 -> V_540 [ V_164 ] ) ;
V_183 = F_223 ( V_538 ) ;
if ( ! V_183 )
goto V_248;
F_227 (&data2->pending, skb, tmp) {
if ( ( unsigned long ) V_26 == V_536 ) {
F_228 ( V_26 , & V_183 -> V_140 ) ;
V_539 = true ;
break;
}
}
if ( ! V_539 )
goto V_248;
V_138 = (struct V_137 * ) F_225 (
V_91 -> V_540 [ V_163 ] ) ;
V_216 = F_54 ( V_26 ) ;
F_109 ( V_216 ) ;
for ( V_136 = 0 ; V_136 < V_139 ; V_136 ++ ) {
V_216 -> V_160 . V_161 [ V_136 ] . V_159 = V_138 [ V_136 ] . V_159 ;
V_216 -> V_160 . V_161 [ V_136 ] . V_162 = V_138 [ V_136 ] . V_162 ;
}
V_216 -> V_160 . V_541 = F_14 ( V_91 -> V_540 [ V_542 ] ) ;
if ( ! ( V_135 & V_155 ) &&
( V_135 & V_543 ) ) {
if ( V_26 -> V_151 >= 16 ) {
V_58 = (struct V_57 * ) V_26 -> V_23 ;
F_63 ( V_183 -> V_158 ,
V_58 -> V_63 ) ;
}
V_216 -> V_89 |= V_223 ;
}
F_110 ( V_183 -> V_44 , V_26 ) ;
return 0 ;
V_248:
return - V_34 ;
}
static int F_229 ( struct V_25 * V_535 ,
struct V_374 * V_91 )
{
struct V_40 * V_183 ;
struct V_185 V_186 ;
const T_2 * V_544 ;
int V_545 ;
void * V_546 ;
struct V_25 * V_26 = NULL ;
if ( V_91 -> V_375 != V_222 )
return - V_34 ;
if ( ! V_91 -> V_540 [ V_547 ] ||
! V_91 -> V_540 [ V_150 ] ||
! V_91 -> V_540 [ V_548 ] ||
! V_91 -> V_540 [ V_542 ] )
goto V_248;
V_544 = ( void * ) F_225 ( V_91 -> V_540 [ V_547 ] ) ;
V_545 = F_230 ( V_91 -> V_540 [ V_150 ] ) ;
V_546 = ( void * ) F_225 ( V_91 -> V_540 [ V_150 ] ) ;
V_26 = F_231 ( V_545 , V_36 ) ;
if ( V_26 == NULL )
goto V_30;
if ( V_545 > V_415 )
goto V_30;
memcpy ( F_23 ( V_26 , V_545 ) , V_546 , V_545 ) ;
V_183 = F_223 ( V_544 ) ;
if ( ! V_183 )
goto V_248;
if ( V_183 -> V_207 || ! V_183 -> V_206 )
goto V_248;
memset ( & V_186 , 0 , sizeof( V_186 ) ) ;
V_186 . V_188 = V_183 -> V_158 -> V_110 ;
V_186 . V_189 = V_183 -> V_158 -> V_189 ;
V_186 . V_192 = F_14 ( V_91 -> V_540 [ V_548 ] ) ;
V_186 . signal = F_14 ( V_91 -> V_540 [ V_542 ] ) ;
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
static int F_232 ( struct V_25 * V_535 ,
struct V_374 * V_91 )
{
struct V_40 * V_23 ;
int V_549 = 1 ;
F_187 ( & V_204 ) ;
F_96 (data, &hwsim_radios, list)
V_549 = F_233 ( V_549 , V_23 -> V_347 ) ;
F_188 ( & V_204 ) ;
if ( V_549 > 1 )
return - V_320 ;
if ( V_222 )
return - V_358 ;
V_222 = V_91 -> V_375 ;
F_73 ( V_148 L_56
L_57 , V_91 -> V_375 ) ;
return 0 ;
}
static int F_234 ( struct V_25 * V_550 , struct V_374 * V_91 )
{
struct V_379 V_380 = { 0 } ;
V_380 . V_388 = V_91 -> V_540 [ V_389 ] ;
V_380 . V_390 = V_91 -> V_540 [ V_391 ] ;
V_380 . V_347 = V_347 ;
V_380 . V_411 =
V_91 -> V_540 [ V_551 ] ;
if ( V_91 -> V_540 [ V_382 ] )
V_380 . V_347 = F_14 ( V_91 -> V_540 [ V_382 ] ) ;
if ( V_91 -> V_540 [ V_552 ] )
V_380 . V_507 = true ;
if ( V_91 -> V_540 [ V_394 ] )
V_380 . V_393 = F_225 ( V_91 -> V_540 [ V_394 ] ) ;
if ( V_91 -> V_540 [ V_392 ] )
V_380 . V_218 = true ;
else
V_380 . V_218 = ( V_380 . V_347 > 1 ) ;
if ( V_91 -> V_540 [ V_384 ] )
V_380 . V_383 =
F_225 ( V_91 -> V_540 [ V_384 ] ) ;
if ( V_91 -> V_540 [ V_387 ] ) {
T_1 V_159 = F_14 ( V_91 -> V_540 [ V_387 ] ) ;
if ( V_159 >= F_107 ( V_386 ) )
return - V_34 ;
V_380 . V_385 = V_386 [ V_159 ] ;
}
return F_186 ( V_91 , & V_380 ) ;
}
static int F_235 ( struct V_25 * V_550 , struct V_374 * V_91 )
{
struct V_40 * V_23 ;
T_8 V_159 = - 1 ;
const char * V_393 = NULL ;
if ( V_91 -> V_540 [ V_381 ] )
V_159 = F_14 ( V_91 -> V_540 [ V_381 ] ) ;
else if ( V_91 -> V_540 [ V_394 ] )
V_393 = ( void * ) F_225 ( V_91 -> V_540 [ V_394 ] ) ;
else
return - V_34 ;
F_187 ( & V_204 ) ;
F_96 (data, &hwsim_radios, list) {
if ( V_159 >= 0 ) {
if ( V_23 -> V_159 != V_159 )
continue;
} else {
if ( strcmp ( V_393 , F_216 ( V_23 -> V_44 -> V_20 ) ) )
continue;
}
F_219 ( & V_23 -> V_518 ) ;
F_188 ( & V_204 ) ;
F_211 ( V_23 , F_216 ( V_23 -> V_44 -> V_20 ) ,
V_91 ) ;
return 0 ;
}
F_188 ( & V_204 ) ;
return - V_553 ;
}
static int F_236 ( struct V_25 * V_550 , struct V_374 * V_91 )
{
struct V_40 * V_23 ;
struct V_25 * V_26 ;
int V_159 , V_523 = - V_553 ;
if ( ! V_91 -> V_540 [ V_381 ] )
return - V_34 ;
V_159 = F_14 ( V_91 -> V_540 [ V_381 ] ) ;
F_187 ( & V_204 ) ;
F_96 (data, &hwsim_radios, list) {
if ( V_23 -> V_159 != V_159 )
continue;
V_26 = F_237 ( V_554 , V_36 ) ;
if ( ! V_26 ) {
V_523 = - V_37 ;
goto V_396;
}
V_523 = F_214 ( V_26 , V_23 , V_91 -> V_375 ,
V_91 -> V_555 , NULL , 0 ) ;
if ( V_523 < 0 ) {
F_79 ( V_26 ) ;
goto V_396;
}
F_238 ( V_26 , V_91 ) ;
break;
}
V_396:
F_188 ( & V_204 ) ;
return V_523 ;
}
static int F_239 ( struct V_25 * V_26 ,
struct V_522 * V_122 )
{
int V_159 = V_122 -> args [ 0 ] ;
struct V_40 * V_23 = NULL ;
int V_523 ;
F_187 ( & V_204 ) ;
if ( V_159 == V_401 )
goto V_556;
F_96 (data, &hwsim_radios, list) {
if ( V_23 -> V_159 < V_159 )
continue;
V_523 = F_214 ( V_26 , V_23 ,
F_240 ( V_122 -> V_26 ) . V_412 ,
V_122 -> V_557 -> V_558 , V_122 ,
V_559 ) ;
if ( V_523 < 0 )
break;
V_159 = V_23 -> V_159 + 1 ;
}
V_122 -> args [ 0 ] = V_159 ;
V_556:
F_188 ( & V_204 ) ;
return V_26 -> V_151 ;
}
static void F_241 ( struct V_336 * V_337 )
{
struct V_40 * V_23 =
F_124 ( V_337 , struct V_40 , V_560 ) ;
F_211 ( V_23 , F_216 ( V_23 -> V_44 -> V_20 ) , NULL ) ;
}
static void F_242 ( T_1 V_412 )
{
struct V_40 * V_561 , * V_537 ;
F_187 ( & V_204 ) ;
F_243 (entry, tmp, &hwsim_radios, list) {
if ( V_561 -> V_411 && V_561 -> V_412 == V_412 ) {
F_219 ( & V_561 -> V_518 ) ;
F_244 ( & V_561 -> V_560 , F_241 ) ;
F_245 ( & V_561 -> V_560 ) ;
}
}
F_188 ( & V_204 ) ;
}
static int F_246 ( struct V_562 * V_563 ,
unsigned long V_564 ,
void * V_565 )
{
struct V_566 * V_567 = V_565 ;
if ( V_564 != V_568 )
return V_569 ;
F_242 ( V_567 -> V_412 ) ;
if ( V_567 -> V_412 == V_222 ) {
F_73 ( V_570 L_58
L_59 ) ;
V_222 = 0 ;
}
return V_569 ;
}
static int F_247 ( void )
{
int V_571 ;
F_73 ( V_570 L_60 ) ;
V_571 = F_248 ( & V_146 ,
V_572 ,
V_573 ) ;
if ( V_571 )
goto V_574;
V_571 = F_249 ( & V_575 ) ;
if ( V_571 ) {
F_250 ( & V_146 ) ;
goto V_574;
}
return 0 ;
V_574:
F_73 ( V_148 L_6 , V_35 ) ;
return - V_34 ;
}
static void F_251 ( void )
{
F_252 ( & V_575 ) ;
F_250 ( & V_146 ) ;
}
static int T_9 F_253 ( void )
{
int V_136 , V_30 ;
if ( V_576 < 0 || V_576 > 100 )
return - V_34 ;
if ( V_347 < 1 )
return - V_34 ;
V_402 = V_400 ;
V_402 . V_338 = F_158 ;
V_402 . V_577 = F_160 ;
V_402 . V_578 = NULL ;
V_402 . V_579 = NULL ;
V_402 . V_580 = F_167 ;
V_402 . V_581 = F_169 ;
V_402 . V_582 = F_170 ;
V_402 . V_583 = F_171 ;
V_402 . V_584 = F_172 ;
V_402 . V_585 =
F_173 ;
V_402 . V_586 =
F_174 ;
F_254 ( & V_204 ) ;
F_255 ( & V_519 ) ;
V_30 = F_256 ( & V_407 ) ;
if ( V_30 )
return V_30 ;
V_404 = F_257 ( V_587 , L_61 ) ;
if ( F_191 ( V_404 ) ) {
V_30 = F_192 ( V_404 ) ;
goto V_588;
}
V_30 = F_247 () ;
if ( V_30 < 0 )
goto V_588;
for ( V_136 = 0 ; V_136 < V_576 ; V_136 ++ ) {
struct V_379 V_380 = { 0 } ;
V_380 . V_347 = V_347 ;
switch ( V_589 ) {
case V_590 :
if ( V_136 < F_107 ( V_591 ) )
V_380 . V_383 = V_591 [ V_136 ] ;
break;
case V_592 :
if ( ! V_136 )
V_380 . V_383 = V_591 [ 0 ] ;
break;
case V_593 :
V_380 . V_388 = true ;
case V_594 :
V_380 . V_383 = V_591 [ 0 ] ;
break;
case V_595 :
if ( V_136 == 0 )
V_380 . V_385 = & V_596 ;
break;
case V_597 :
V_380 . V_385 = & V_596 ;
break;
case V_598 :
if ( V_136 == 0 )
V_380 . V_385 = & V_596 ;
else if ( V_136 == 1 )
V_380 . V_385 = & V_599 ;
break;
case V_600 :
if ( V_136 == 0 ) {
V_380 . V_388 = true ;
V_380 . V_383 = V_591 [ 0 ] ;
}
break;
case V_601 :
if ( V_136 == 0 ) {
V_380 . V_388 = true ;
V_380 . V_383 = V_591 [ 0 ] ;
} else if ( V_136 == 1 ) {
V_380 . V_383 = V_591 [ 1 ] ;
}
break;
case V_602 :
switch ( V_136 ) {
case 0 :
V_380 . V_385 = & V_596 ;
break;
case 1 :
V_380 . V_385 = & V_599 ;
break;
case 2 :
V_380 . V_383 = V_591 [ 0 ] ;
break;
case 3 :
V_380 . V_383 = V_591 [ 1 ] ;
break;
case 4 :
V_380 . V_388 = true ;
V_380 . V_383 = V_591 [ 2 ] ;
break;
}
break;
default:
break;
}
V_380 . V_390 = V_603 ;
V_380 . V_218 = V_347 > 1 ;
V_30 = F_186 ( NULL , & V_380 ) ;
if ( V_30 < 0 )
goto V_604;
}
V_94 = F_258 ( 0 , L_47 , V_605 ,
F_221 ) ;
if ( V_94 == NULL ) {
V_30 = - V_37 ;
goto V_604;
}
F_259 () ;
V_30 = F_260 ( V_94 , V_94 -> V_606 ) ;
if ( V_30 < 0 ) {
F_261 () ;
goto V_604;
}
V_30 = F_262 ( V_94 ) ;
if ( V_30 < 0 ) {
F_261 () ;
goto V_607;
}
F_261 () ;
return 0 ;
V_607:
V_529 ( V_94 ) ;
V_604:
F_217 () ;
V_588:
F_263 ( & V_407 ) ;
return V_30 ;
}
static void T_10 F_264 ( void )
{
F_73 ( V_148 L_62 ) ;
F_251 () ;
F_217 () ;
F_265 ( V_94 ) ;
F_263 ( & V_407 ) ;
}
