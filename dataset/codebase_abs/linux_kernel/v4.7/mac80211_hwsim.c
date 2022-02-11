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
if ( F_6 ( ! V_93 ) )
return;
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
F_59 ( V_26 ) ;
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
F_59 ( V_26 ) ;
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
T_7 V_140 ;
if ( V_23 -> V_56 != V_67 )
V_58 -> V_47 |= F_24 ( V_50 ) ;
if ( F_67 ( & V_23 -> V_141 ) >= V_142 ) {
while ( F_67 ( & V_23 -> V_141 ) >= V_143 ) {
F_68 ( V_44 , F_69 ( & V_23 -> V_141 ) ) ;
V_23 -> V_144 ++ ;
}
}
V_26 = F_70 ( V_145 , V_95 ) ;
if ( V_26 == NULL )
goto V_146;
V_134 = F_71 ( V_26 , 0 , 0 , & V_147 , 0 ,
V_148 ) ;
if ( V_134 == NULL ) {
F_72 ( V_149 L_5 ) ;
goto V_146;
}
if ( F_73 ( V_26 , V_150 ,
V_51 , V_23 -> V_151 [ 1 ] . V_8 ) )
goto V_146;
if ( F_73 ( V_26 , V_152 , V_132 -> V_153 , V_132 -> V_23 ) )
goto V_146;
if ( V_91 -> V_89 & V_154 )
V_135 |= V_155 ;
if ( V_91 -> V_89 & V_156 )
V_135 |= V_157 ;
if ( F_17 ( V_26 , V_158 , V_135 ) )
goto V_146;
if ( F_17 ( V_26 , V_159 , V_23 -> V_160 -> V_110 ) )
goto V_146;
for ( V_136 = 0 ; V_136 < V_139 ; V_136 ++ ) {
V_138 [ V_136 ] . V_161 = V_91 -> V_162 . V_163 [ V_136 ] . V_161 ;
V_138 [ V_136 ] . V_164 = V_91 -> V_162 . V_163 [ V_136 ] . V_164 ;
}
if ( F_73 ( V_26 , V_165 ,
sizeof( struct V_137 ) * V_139 ,
V_138 ) )
goto V_146;
V_23 -> V_166 ++ ;
V_140 = V_23 -> V_166 ;
V_91 -> V_167 [ 0 ] = ( void * ) V_140 ;
if ( F_74 ( V_26 , V_168 , V_140 , V_169 ) )
goto V_146;
F_75 ( V_26 , V_134 ) ;
if ( F_76 ( & V_170 , V_26 , V_133 ) )
goto V_171;
F_77 ( & V_23 -> V_141 , V_132 ) ;
V_23 -> V_172 ++ ;
V_23 -> V_173 += V_132 -> V_153 ;
return;
V_146:
F_78 ( V_26 ) ;
V_171:
F_72 ( V_149 L_6 , V_35 ) ;
F_68 ( V_44 , V_132 ) ;
V_23 -> V_174 ++ ;
}
static bool F_79 ( struct V_87 * V_175 ,
struct V_87 * V_176 )
{
if ( ! V_175 || ! V_176 )
return false ;
return V_175 -> V_110 == V_176 -> V_110 ;
}
static void F_80 ( void * V_177 , T_2 * V_8 ,
struct V_1 * V_2 )
{
struct V_178 * V_23 = V_177 ;
if ( ! V_2 -> V_53 )
return;
if ( ! F_79 ( V_23 -> V_160 ,
F_27 ( V_2 -> V_53 ) -> V_54 . V_55 ) )
return;
V_23 -> V_179 = true ;
}
static void F_81 ( struct V_25 * V_26 )
{
#ifdef F_82
struct V_180 * V_181 ;
V_181 = ( void * ) F_57 ( V_26 , sizeof( * V_181 ) + 8 + 4 ) ;
V_181 -> V_182 [ 0 ] = F_82 [ 0 ] ;
V_181 -> V_182 [ 1 ] = F_82 [ 1 ] ;
V_181 -> V_182 [ 2 ] = F_82 [ 2 ] ;
V_181 -> V_183 = 127 ;
V_181 -> V_184 = F_83 ( 0 ) ;
V_181 -> V_153 = 8 ;
V_181 -> V_185 = 8 ;
V_181 -> V_125 = 4 ;
memcpy ( V_181 -> V_23 , L_7 , 8 ) ;
memset ( V_181 -> V_23 + 8 , 0 , 4 ) ;
F_84 ( V_26 ) -> V_186 |= V_187 ;
#endif
}
static bool F_85 ( struct V_79 * V_44 ,
struct V_25 * V_26 ,
struct V_87 * V_55 )
{
struct V_40 * V_23 = V_44 -> V_80 , * V_188 ;
bool V_189 = false ;
struct V_57 * V_58 = (struct V_57 * ) V_26 -> V_23 ;
struct V_90 * V_91 = F_53 ( V_26 ) ;
struct V_190 V_191 ;
T_3 V_77 ;
memset ( & V_191 , 0 , sizeof( V_191 ) ) ;
V_191 . V_186 |= V_192 ;
V_191 . V_193 = V_55 -> V_110 ;
V_191 . V_194 = V_55 -> V_194 ;
if ( V_91 -> V_195 . V_163 [ 0 ] . V_89 & V_196 ) {
V_191 . V_197 =
F_86 ( & V_91 -> V_195 . V_163 [ 0 ] ) ;
V_191 . V_198 =
F_87 ( & V_91 -> V_195 . V_163 [ 0 ] ) ;
V_191 . V_186 |= V_199 ;
} else {
V_191 . V_197 = V_91 -> V_195 . V_163 [ 0 ] . V_161 ;
if ( V_91 -> V_195 . V_163 [ 0 ] . V_89 & V_200 )
V_191 . V_186 |= V_201 ;
}
if ( V_91 -> V_195 . V_163 [ 0 ] . V_89 & V_202 )
V_191 . V_186 |= V_203 ;
if ( V_91 -> V_195 . V_163 [ 0 ] . V_89 & V_204 )
V_191 . V_186 |= V_205 ;
V_191 . signal = V_23 -> V_206 - 50 ;
if ( V_23 -> V_56 != V_67 )
V_58 -> V_47 |= F_24 ( V_50 ) ;
F_88 ( V_26 ) ;
F_89 ( V_26 ) ;
V_26 -> V_207 = 0 ;
F_90 ( V_26 ) ;
F_91 ( V_26 ) ;
if ( F_92 ( V_58 -> V_47 ) ||
F_93 ( V_58 -> V_47 ) )
V_77 = V_23 -> V_208 ;
else
V_77 = F_43 () ;
F_94 ( & V_209 ) ;
F_95 (data2, &hwsim_radios, list) {
struct V_25 * V_210 ;
struct V_178 V_178 = {
. V_179 = false ,
. V_160 = V_55 ,
} ;
if ( V_23 == V_188 )
continue;
if ( ! V_188 -> V_211 || ( V_188 -> V_212 && ! V_188 -> V_213 ) ||
! F_65 ( V_188 , V_26 ) )
continue;
if ( ! ( V_23 -> V_73 & V_188 -> V_73 ) )
continue;
if ( ! F_79 ( V_55 , V_188 -> V_213 ) &&
! F_79 ( V_55 , V_188 -> V_160 ) ) {
F_35 (
V_188 -> V_44 , V_71 ,
F_80 , & V_178 ) ;
if ( ! V_178 . V_179 )
continue;
}
if ( V_26 -> V_153 < V_214 && V_215 ) {
struct V_216 * V_216 = F_96 ( V_95 ) ;
if ( ! V_216 )
continue;
V_210 = F_22 ( 128 ) ;
if ( ! V_210 ) {
F_97 ( V_216 ) ;
continue;
}
memcpy ( F_98 ( V_216 ) , V_26 -> V_23 , V_26 -> V_153 ) ;
F_99 ( V_210 , 0 , V_216 , 0 , V_26 -> V_153 , V_26 -> V_153 ) ;
} else {
V_210 = F_100 ( V_26 , V_95 ) ;
if ( ! V_210 )
continue;
}
if ( F_64 ( V_188 , V_58 -> V_62 ) )
V_189 = true ;
V_191 . V_217 = V_77 + V_188 -> V_78 ;
memcpy ( F_84 ( V_210 ) , & V_191 , sizeof( V_191 ) ) ;
F_81 ( V_210 ) ;
V_188 -> V_218 ++ ;
V_188 -> V_219 += V_210 -> V_153 ;
F_101 ( V_188 -> V_44 , V_210 ) ;
}
F_102 ( & V_209 ) ;
return V_189 ;
}
static void F_103 ( struct V_79 * V_44 ,
struct V_220 * V_195 ,
struct V_25 * V_26 )
{
struct V_40 * V_23 = V_44 -> V_80 ;
struct V_90 * V_221 = F_53 ( V_26 ) ;
struct V_57 * V_58 = ( void * ) V_26 -> V_23 ;
struct V_15 * V_53 ;
struct V_87 * V_160 ;
bool V_189 ;
T_1 V_222 ;
if ( F_6 ( V_26 -> V_153 < 10 ) ) {
F_68 ( V_44 , V_26 ) ;
return;
}
if ( ! V_23 -> V_223 ) {
V_160 = V_23 -> V_160 ;
} else if ( V_221 -> V_224 == 4 ) {
V_160 = V_23 -> V_213 ;
} else {
V_53 = F_27 ( V_221 -> V_195 . V_2 -> V_53 ) ;
if ( V_53 )
V_160 = V_53 -> V_54 . V_55 ;
else
V_160 = NULL ;
}
if ( F_2 ( ! V_160 , L_8 , V_221 -> V_224 ) ) {
F_68 ( V_44 , V_26 ) ;
return;
}
if ( V_23 -> V_212 && ! V_23 -> V_213 ) {
F_15 ( V_44 -> V_20 , L_9 ) ;
F_68 ( V_44 , V_26 ) ;
return;
}
if ( V_221 -> V_195 . V_2 )
F_1 ( V_221 -> V_195 . V_2 ) ;
if ( V_195 -> V_11 )
F_5 ( V_195 -> V_11 ) ;
if ( F_104 ( V_44 , V_225 ) )
F_105 ( V_221 -> V_195 . V_2 , V_195 -> V_11 , V_26 ,
V_221 -> V_195 . V_163 ,
F_106 ( V_221 -> V_195 . V_163 ) ) ;
V_221 -> V_167 [ 0 ] = V_160 ;
if ( V_26 -> V_153 >= 24 + 8 &&
F_93 ( V_58 -> V_47 ) ) {
struct V_226 * V_227 ;
struct V_92 * V_93 ;
T_3 V_228 ;
V_227 = (struct V_226 * ) V_26 -> V_23 ;
V_93 = F_54 ( V_44 , V_221 ) ;
V_228 = F_43 () ;
V_227 -> V_229 . V_230 . V_231 =
F_47 ( V_228 + V_23 -> V_78 +
24 * 8 * 10 / V_93 -> V_108 ) ;
}
F_52 ( V_44 , V_26 , V_160 ) ;
V_222 = F_107 ( V_232 ) ;
if ( V_222 )
return F_66 ( V_44 , V_26 , V_222 ) ;
V_23 -> V_172 ++ ;
V_23 -> V_173 += V_26 -> V_153 ;
V_189 = F_85 ( V_44 , V_26 , V_160 ) ;
if ( V_189 && V_26 -> V_153 >= 16 )
F_62 ( V_160 , V_58 -> V_63 ) ;
F_108 ( V_221 ) ;
V_221 -> V_195 . V_163 [ 0 ] . V_164 = 1 ;
V_221 -> V_195 . V_163 [ 1 ] . V_161 = - 1 ;
if ( ! ( V_221 -> V_89 & V_156 ) && V_189 )
V_221 -> V_89 |= V_233 ;
F_109 ( V_44 , V_26 ) ;
}
static int F_110 ( struct V_79 * V_44 )
{
struct V_40 * V_23 = V_44 -> V_80 ;
F_15 ( V_44 -> V_20 , L_10 , V_35 ) ;
V_23 -> V_211 = true ;
return 0 ;
}
static void F_111 ( struct V_79 * V_44 )
{
struct V_40 * V_23 = V_44 -> V_80 ;
V_23 -> V_211 = false ;
F_112 ( & V_23 -> V_234 ) ;
F_15 ( V_44 -> V_20 , L_10 , V_35 ) ;
}
static int F_113 ( struct V_79 * V_44 ,
struct V_1 * V_2 )
{
F_15 ( V_44 -> V_20 , L_11 ,
V_35 , F_114 ( V_2 ) ,
V_2 -> V_8 ) ;
F_3 ( V_2 ) ;
V_2 -> V_235 = 0 ;
V_2 -> V_224 [ V_236 ] = 0 ;
V_2 -> V_224 [ V_237 ] = 1 ;
V_2 -> V_224 [ V_238 ] = 2 ;
V_2 -> V_224 [ V_239 ] = 3 ;
return 0 ;
}
static int F_115 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
enum V_240 V_241 ,
bool V_242 )
{
V_241 = F_116 ( V_241 , V_242 ) ;
F_15 ( V_44 -> V_20 ,
L_12 ,
V_35 , F_114 ( V_2 ) ,
V_241 , V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
V_2 -> V_235 = 0 ;
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
T_1 V_243 = F_107 ( V_232 ) ;
if ( F_104 ( V_44 , V_225 ) ) {
struct V_90 * V_221 = F_53 ( V_26 ) ;
F_105 ( V_221 -> V_195 . V_2 , NULL , V_26 ,
V_221 -> V_195 . V_163 ,
F_106 ( V_221 -> V_195 . V_163 ) ) ;
}
F_52 ( V_44 , V_26 , V_55 ) ;
if ( V_243 )
return F_66 ( V_44 , V_26 , V_243 ) ;
F_85 ( V_44 , V_26 , V_55 ) ;
F_42 ( V_26 ) ;
}
static void F_118 ( void * V_244 , T_2 * V_39 ,
struct V_1 * V_2 )
{
struct V_40 * V_23 = V_244 ;
struct V_79 * V_44 = V_23 -> V_44 ;
struct V_90 * V_91 ;
struct V_92 * V_93 ;
struct V_226 * V_227 ;
struct V_25 * V_26 ;
F_1 ( V_2 ) ;
if ( V_2 -> type != V_245 &&
V_2 -> type != V_246 &&
V_2 -> type != V_247 )
return;
V_26 = F_119 ( V_44 , V_2 ) ;
if ( V_26 == NULL )
return;
V_91 = F_53 ( V_26 ) ;
if ( F_104 ( V_44 , V_225 ) )
F_105 ( V_2 , NULL , V_26 ,
V_91 -> V_195 . V_163 ,
F_106 ( V_91 -> V_195 . V_163 ) ) ;
V_93 = F_54 ( V_44 , V_91 ) ;
V_227 = (struct V_226 * ) V_26 -> V_23 ;
V_23 -> V_208 = F_43 () ;
V_227 -> V_229 . V_248 . V_231 = F_47 ( V_23 -> V_208 +
V_23 -> V_78 +
24 * 8 * 10 / V_93 -> V_108 ) ;
F_26 ( V_44 , V_26 ,
F_27 ( V_2 -> V_53 ) -> V_54 . V_55 ) ;
if ( V_2 -> V_249 && F_120 ( V_2 ) )
F_121 ( V_2 ) ;
}
static enum V_250
F_122 ( struct V_251 * V_252 )
{
struct V_40 * V_23 =
F_123 ( V_252 , struct V_40 ,
V_234 . V_252 ) ;
struct V_79 * V_44 = V_23 -> V_44 ;
T_3 V_82 = V_23 -> V_83 ;
T_8 V_253 ;
if ( ! V_23 -> V_211 )
goto V_254;
F_35 (
V_44 , V_71 ,
F_118 , V_23 ) ;
if ( V_23 -> V_85 ) {
V_82 -= V_23 -> V_85 ;
V_23 -> V_85 = 0 ;
}
V_253 = F_124 ( F_125 ( V_252 ) ,
F_126 ( V_82 * 1000 ) ) ;
F_127 ( & V_23 -> V_234 , V_253 , V_255 ) ;
V_254:
return V_256 ;
}
static int F_128 ( struct V_79 * V_44 , T_1 V_257 )
{
struct V_40 * V_23 = V_44 -> V_80 ;
struct V_258 * V_259 = & V_44 -> V_259 ;
static const char * V_260 [ V_261 ] = {
[ V_262 ] = L_13 ,
[ V_263 ] = L_14 ,
[ V_264 ] = L_15 ,
[ V_265 ] = L_16 ,
} ;
if ( V_259 -> V_266 . V_55 )
F_15 ( V_44 -> V_20 ,
L_17 ,
V_35 ,
V_259 -> V_266 . V_55 -> V_110 ,
V_259 -> V_266 . V_267 ,
V_259 -> V_266 . V_268 ,
V_269 [ V_259 -> V_266 . V_270 ] ,
! ! ( V_259 -> V_89 & V_271 ) ,
! ! ( V_259 -> V_89 & V_272 ) ,
V_260 [ V_259 -> V_273 ] ) ;
else
F_15 ( V_44 -> V_20 ,
L_18 ,
V_35 ,
! ! ( V_259 -> V_89 & V_271 ) ,
! ! ( V_259 -> V_89 & V_272 ) ,
V_260 [ V_259 -> V_273 ] ) ;
V_23 -> V_212 = ! ! ( V_259 -> V_89 & V_271 ) ;
V_23 -> V_160 = V_259 -> V_266 . V_55 ;
F_6 ( V_23 -> V_160 && V_23 -> V_223 ) ;
V_23 -> V_206 = V_259 -> V_206 ;
if ( ! V_23 -> V_211 || ! V_23 -> V_83 )
F_112 ( & V_23 -> V_234 ) ;
else if ( ! F_129 ( & V_23 -> V_234 . V_252 ) ) {
T_3 V_81 = F_48 ( V_44 , NULL ) ;
T_1 V_82 = V_23 -> V_83 ;
T_3 V_274 = V_82 - F_51 ( V_81 , V_82 ) ;
F_127 ( & V_23 -> V_234 ,
F_126 ( V_274 * 1000 ) ,
V_275 ) ;
}
return 0 ;
}
static void F_130 ( struct V_79 * V_44 ,
unsigned int V_276 ,
unsigned int * V_277 , T_3 V_278 )
{
struct V_40 * V_23 = V_44 -> V_80 ;
F_15 ( V_44 -> V_20 , L_10 , V_35 ) ;
V_23 -> V_279 = 0 ;
if ( * V_277 & V_280 )
V_23 -> V_279 |= V_280 ;
* V_277 = V_23 -> V_279 ;
}
static void F_131 ( void * V_23 , T_2 * V_39 ,
struct V_1 * V_2 )
{
unsigned int * V_164 = V_23 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
if ( V_4 -> V_281 )
( * V_164 ) ++ ;
}
static void F_132 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_282 * V_91 ,
T_1 V_257 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_40 * V_23 = V_44 -> V_80 ;
F_1 ( V_2 ) ;
F_15 ( V_44 -> V_20 , L_19 ,
V_35 , V_257 , V_2 -> V_8 ) ;
if ( V_257 & V_283 ) {
F_15 ( V_44 -> V_20 , L_20 ,
V_35 , V_91 -> V_45 ) ;
memcpy ( V_4 -> V_45 , V_91 -> V_45 , V_51 ) ;
}
if ( V_257 & V_284 ) {
F_15 ( V_44 -> V_20 , L_21 ,
V_91 -> V_43 , V_91 -> V_46 ) ;
V_4 -> V_43 = V_91 -> V_43 ;
V_4 -> V_46 = V_91 -> V_46 ;
}
if ( V_257 & V_285 ) {
F_15 ( V_44 -> V_20 , L_22 ,
V_91 -> V_286 , V_91 -> V_83 ) ;
V_4 -> V_281 = V_91 -> V_286 ;
if ( V_23 -> V_211 &&
! F_129 ( & V_23 -> V_234 . V_252 ) &&
V_91 -> V_286 ) {
T_3 V_81 , V_274 ;
T_1 V_82 ;
V_23 -> V_83 = V_91 -> V_83 * 1024 ;
V_81 = F_48 ( V_44 , V_2 ) ;
V_82 = V_23 -> V_83 ;
V_274 = V_82 - F_51 ( V_81 , V_82 ) ;
F_127 ( & V_23 -> V_234 ,
F_126 ( V_274 * 1000 ) ,
V_275 ) ;
} else if ( ! V_91 -> V_286 ) {
unsigned int V_164 = 0 ;
F_35 (
V_23 -> V_44 , V_71 ,
F_131 , & V_164 ) ;
F_15 ( V_44 -> V_20 , L_23 ,
V_164 ) ;
if ( V_164 == 0 ) {
F_112 ( & V_23 -> V_234 ) ;
V_23 -> V_83 = 0 ;
}
}
}
if ( V_257 & V_287 ) {
F_15 ( V_44 -> V_20 , L_24 ,
V_91 -> V_288 ) ;
}
if ( V_257 & V_289 ) {
F_15 ( V_44 -> V_20 , L_25 ,
V_91 -> V_290 ) ;
}
if ( V_257 & V_291 ) {
F_15 ( V_44 -> V_20 , L_26 , V_91 -> V_292 ) ;
}
if ( V_257 & V_293 ) {
F_15 ( V_44 -> V_20 , L_27 ,
V_91 -> V_294 ) ;
}
if ( V_257 & V_295 ) {
F_15 ( V_44 -> V_20 , L_28 ,
( unsigned long long ) V_91 -> V_296 ) ;
}
if ( V_257 & V_297 )
F_15 ( V_44 -> V_20 , L_29 , V_91 -> V_298 ) ;
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
enum V_299 V_300 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
switch ( V_300 ) {
case V_301 :
case V_302 :
break;
default:
F_2 ( 1 , L_30 , V_300 ) ;
break;
}
}
static int F_136 ( struct V_79 * V_44 ,
struct V_10 * V_11 ,
bool V_303 )
{
F_5 ( V_11 ) ;
return 0 ;
}
static int F_137 (
struct V_79 * V_44 ,
struct V_1 * V_2 , T_6 V_304 ,
const struct V_305 * V_306 )
{
F_15 ( V_44 -> V_20 ,
L_31 ,
V_35 , V_304 ,
V_306 -> V_307 , V_306 -> V_308 ,
V_306 -> V_309 , V_306 -> V_310 ) ;
return 0 ;
}
static int F_138 (
struct V_79 * V_44 , int V_161 ,
struct V_311 * V_312 )
{
struct V_258 * V_259 = & V_44 -> V_259 ;
F_15 ( V_44 -> V_20 , L_32 , V_35 , V_161 ) ;
if ( V_161 != 0 )
return - V_313 ;
V_312 -> V_160 = V_259 -> V_266 . V_55 ;
V_312 -> V_314 = V_315 ;
V_312 -> V_316 = - 92 ;
return 0 ;
}
static int F_139 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
void * V_23 , int V_153 )
{
struct V_40 * V_317 = V_44 -> V_80 ;
struct V_27 * V_28 [ V_318 + 1 ] ;
struct V_25 * V_26 ;
int V_30 , V_56 ;
V_30 = F_13 ( V_28 , V_318 , V_23 , V_153 ,
V_319 ) ;
if ( V_30 )
return V_30 ;
if ( ! V_28 [ V_320 ] )
return - V_34 ;
switch ( F_14 ( V_28 [ V_320 ] ) ) {
case V_321 :
if ( ! V_28 [ V_322 ] )
return - V_34 ;
V_56 = F_14 ( V_28 [ V_322 ] ) ;
return F_33 ( V_317 , V_56 ) ;
case V_323 :
V_26 = F_140 ( V_44 -> V_20 ,
F_141 ( sizeof( T_1 ) ) ) ;
if ( ! V_26 )
return - V_37 ;
if ( F_17 ( V_26 , V_322 , V_317 -> V_56 ) )
goto V_146;
return F_142 ( V_26 ) ;
case V_324 :
F_143 ( V_44 ) ;
return 0 ;
case V_325 :
F_144 ( V_44 ) ;
return 0 ;
default:
return - V_326 ;
}
V_146:
F_145 ( V_26 ) ;
return - V_327 ;
}
static int F_146 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_328 * V_306 )
{
struct V_10 * V_11 = V_306 -> V_11 ;
enum V_329 V_330 = V_306 -> V_330 ;
T_6 V_331 = V_306 -> V_331 ;
switch ( V_330 ) {
case V_332 :
F_147 ( V_2 , V_11 -> V_8 , V_331 ) ;
break;
case V_333 :
case V_334 :
case V_335 :
F_148 ( V_2 , V_11 -> V_8 , V_331 ) ;
break;
case V_336 :
break;
case V_337 :
case V_338 :
break;
default:
return - V_326 ;
}
return 0 ;
}
static void F_149 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
T_1 V_339 , bool V_340 )
{
}
static void F_150 ( struct V_341 * V_342 )
{
struct V_40 * V_317 =
F_123 ( V_342 , struct V_40 , V_343 . V_342 ) ;
struct V_344 * V_345 = V_317 -> V_346 ;
int V_347 , V_136 ;
F_151 ( & V_317 -> V_348 ) ;
if ( V_317 -> V_349 >= V_345 -> V_350 ) {
F_15 ( V_317 -> V_44 -> V_20 , L_33 ) ;
F_152 ( V_317 -> V_44 , false ) ;
V_317 -> V_346 = NULL ;
V_317 -> V_351 = NULL ;
V_317 -> V_213 = NULL ;
F_153 ( & V_317 -> V_348 ) ;
return;
}
F_15 ( V_317 -> V_44 -> V_20 , L_34 ,
V_345 -> V_352 [ V_317 -> V_349 ] -> V_110 ) ;
V_317 -> V_213 = V_345 -> V_352 [ V_317 -> V_349 ] ;
if ( V_317 -> V_213 -> V_89 & ( V_353 |
V_354 ) ||
! V_345 -> V_355 ) {
V_347 = 120 ;
} else {
V_347 = 30 ;
for ( V_136 = 0 ; V_136 < V_345 -> V_355 ; V_136 ++ ) {
struct V_25 * V_356 ;
struct V_226 * V_227 ;
V_356 = F_154 ( V_317 -> V_44 ,
V_317 -> V_131 ,
V_345 -> V_357 [ V_136 ] . V_358 ,
V_345 -> V_357 [ V_136 ] . V_359 ,
V_345 -> V_360 ) ;
if ( ! V_356 )
continue;
V_227 = (struct V_226 * ) V_356 -> V_23 ;
memcpy ( V_227 -> V_361 , V_345 -> V_45 , V_51 ) ;
memcpy ( V_227 -> V_45 , V_345 -> V_45 , V_51 ) ;
if ( V_345 -> V_360 )
memcpy ( F_23 ( V_356 , V_345 -> V_360 ) , V_345 -> V_362 ,
V_345 -> V_360 ) ;
F_34 () ;
F_26 ( V_317 -> V_44 , V_356 ,
V_317 -> V_213 ) ;
F_36 () ;
}
}
F_155 ( V_317 -> V_44 , & V_317 -> V_343 ,
F_156 ( V_347 ) ) ;
V_317 -> V_349 ++ ;
F_153 ( & V_317 -> V_348 ) ;
}
static int F_157 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_363 * V_364 )
{
struct V_40 * V_317 = V_44 -> V_80 ;
struct V_344 * V_345 = & V_364 -> V_345 ;
F_151 ( & V_317 -> V_348 ) ;
if ( F_6 ( V_317 -> V_213 || V_317 -> V_346 ) ) {
F_153 ( & V_317 -> V_348 ) ;
return - V_365 ;
}
V_317 -> V_346 = V_345 ;
V_317 -> V_351 = V_2 ;
V_317 -> V_349 = 0 ;
if ( V_345 -> V_89 & V_366 )
F_158 ( V_317 -> V_131 ,
V_364 -> V_345 . V_367 ,
V_364 -> V_345 . V_368 ) ;
else
memcpy ( V_317 -> V_131 , V_2 -> V_8 , V_51 ) ;
F_153 ( & V_317 -> V_348 ) ;
F_15 ( V_44 -> V_20 , L_35 ) ;
F_155 ( V_317 -> V_44 , & V_317 -> V_343 , 0 ) ;
return 0 ;
}
static void F_159 ( struct V_79 * V_44 ,
struct V_1 * V_2 )
{
struct V_40 * V_317 = V_44 -> V_80 ;
F_15 ( V_44 -> V_20 , L_36 ) ;
F_160 ( & V_317 -> V_343 ) ;
F_151 ( & V_317 -> V_348 ) ;
F_152 ( V_317 -> V_44 , true ) ;
V_317 -> V_213 = NULL ;
V_317 -> V_346 = NULL ;
V_317 -> V_351 = NULL ;
F_153 ( & V_317 -> V_348 ) ;
}
static void F_161 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
const T_2 * V_367 )
{
struct V_40 * V_317 = V_44 -> V_80 ;
F_151 ( & V_317 -> V_348 ) ;
if ( V_317 -> V_130 ) {
F_72 ( V_149 L_37 ) ;
goto V_254;
}
F_72 ( V_149 L_38 ) ;
memcpy ( V_317 -> V_131 , V_367 , V_51 ) ;
V_317 -> V_130 = true ;
V_254:
F_153 ( & V_317 -> V_348 ) ;
}
static void F_162 ( struct V_79 * V_44 ,
struct V_1 * V_2 )
{
struct V_40 * V_317 = V_44 -> V_80 ;
F_151 ( & V_317 -> V_348 ) ;
F_72 ( V_149 L_39 ) ;
V_317 -> V_130 = false ;
F_163 ( V_317 -> V_131 ) ;
F_153 ( & V_317 -> V_348 ) ;
}
static void F_164 ( struct V_341 * V_342 )
{
struct V_40 * V_317 =
F_123 ( V_342 , struct V_40 , V_369 . V_342 ) ;
F_151 ( & V_317 -> V_348 ) ;
F_15 ( V_317 -> V_44 -> V_20 , L_40 ) ;
V_317 -> V_213 = V_317 -> V_370 ;
F_165 ( V_317 -> V_44 ) ;
F_155 ( V_317 -> V_44 , & V_317 -> V_371 ,
F_156 ( V_317 -> V_372 ) ) ;
F_153 ( & V_317 -> V_348 ) ;
}
static void F_166 ( struct V_341 * V_342 )
{
struct V_40 * V_317 =
F_123 ( V_342 , struct V_40 , V_371 . V_342 ) ;
F_151 ( & V_317 -> V_348 ) ;
F_167 ( V_317 -> V_44 ) ;
V_317 -> V_213 = NULL ;
F_153 ( & V_317 -> V_348 ) ;
F_15 ( V_317 -> V_44 -> V_20 , L_41 ) ;
}
static int F_168 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_87 * V_55 ,
int V_373 ,
enum V_374 type )
{
struct V_40 * V_317 = V_44 -> V_80 ;
F_151 ( & V_317 -> V_348 ) ;
if ( F_6 ( V_317 -> V_213 || V_317 -> V_346 ) ) {
F_153 ( & V_317 -> V_348 ) ;
return - V_365 ;
}
V_317 -> V_370 = V_55 ;
V_317 -> V_372 = V_373 ;
F_153 ( & V_317 -> V_348 ) ;
F_15 ( V_44 -> V_20 , L_42 ,
V_55 -> V_110 , V_373 ) ;
F_155 ( V_44 , & V_317 -> V_369 , V_375 / 50 ) ;
return 0 ;
}
static int F_169 ( struct V_79 * V_44 )
{
struct V_40 * V_317 = V_44 -> V_80 ;
F_160 ( & V_317 -> V_369 ) ;
F_160 ( & V_317 -> V_371 ) ;
F_151 ( & V_317 -> V_348 ) ;
V_317 -> V_213 = NULL ;
F_153 ( & V_317 -> V_348 ) ;
F_15 ( V_44 -> V_20 , L_43 ) ;
return 0 ;
}
static int F_170 ( struct V_79 * V_44 ,
struct V_15 * V_376 )
{
F_10 ( V_376 ) ;
F_15 ( V_44 -> V_20 ,
L_44 ,
V_376 -> V_54 . V_55 -> V_110 , V_376 -> V_54 . V_270 ,
V_376 -> V_54 . V_267 , V_376 -> V_54 . V_268 ) ;
return 0 ;
}
static void F_171 ( struct V_79 * V_44 ,
struct V_15 * V_376 )
{
F_15 ( V_44 -> V_20 ,
L_45 ,
V_376 -> V_54 . V_55 -> V_110 , V_376 -> V_54 . V_270 ,
V_376 -> V_54 . V_267 , V_376 -> V_54 . V_268 ) ;
F_9 ( V_376 ) ;
F_11 ( V_376 ) ;
}
static void F_172 ( struct V_79 * V_44 ,
struct V_15 * V_376 ,
T_1 V_257 )
{
F_9 ( V_376 ) ;
F_15 ( V_44 -> V_20 ,
L_46 ,
V_376 -> V_54 . V_55 -> V_110 , V_376 -> V_54 . V_270 ,
V_376 -> V_54 . V_267 , V_376 -> V_54 . V_268 ) ;
}
static int F_173 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_15 * V_376 )
{
F_1 ( V_2 ) ;
F_9 ( V_376 ) ;
return 0 ;
}
static void F_174 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_15 * V_376 )
{
F_1 ( V_2 ) ;
F_9 ( V_376 ) ;
}
static void F_175 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
T_1 V_377 , T_2 * V_23 )
{
if ( V_377 == V_378 )
memcpy ( V_23 , * V_379 ,
sizeof( V_379 ) ) ;
}
static int F_176 ( struct V_79 * V_44 ,
struct V_1 * V_2 , int V_377 )
{
if ( V_377 == V_378 )
return V_380 ;
return 0 ;
}
static void F_177 ( struct V_79 * V_44 ,
struct V_1 * V_2 ,
struct V_381 * V_382 , T_3 * V_23 )
{
struct V_40 * V_383 = V_44 -> V_80 ;
int V_136 = 0 ;
V_23 [ V_136 ++ ] = V_383 -> V_172 ;
V_23 [ V_136 ++ ] = V_383 -> V_173 ;
V_23 [ V_136 ++ ] = V_383 -> V_218 ;
V_23 [ V_136 ++ ] = V_383 -> V_219 ;
V_23 [ V_136 ++ ] = V_383 -> V_144 ;
V_23 [ V_136 ++ ] = V_383 -> V_174 ;
V_23 [ V_136 ++ ] = V_383 -> V_56 ;
V_23 [ V_136 ++ ] = V_383 -> V_73 ;
V_23 [ V_136 ++ ] = V_383 -> V_206 ;
F_6 ( V_136 != V_380 ) ;
}
static void F_178 ( struct V_25 * V_384 ,
struct V_385 * V_91 )
{
if ( V_91 )
F_179 ( & V_147 , V_384 , V_91 ,
V_386 , V_36 ) ;
else
F_180 ( & V_147 , V_384 , 0 ,
V_386 , V_36 ) ;
}
static int F_181 ( struct V_25 * V_26 , int V_387 ,
struct V_388 * V_389 )
{
int V_129 ;
V_129 = F_17 ( V_26 , V_390 , V_387 ) ;
if ( V_129 < 0 )
return V_129 ;
if ( V_389 -> V_352 ) {
V_129 = F_17 ( V_26 , V_391 , V_389 -> V_352 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_389 -> V_392 ) {
V_129 = F_73 ( V_26 , V_393 , 2 ,
V_389 -> V_392 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_389 -> V_394 ) {
int V_136 ;
for ( V_136 = 0 ; V_136 < F_106 ( V_395 ) ; V_136 ++ ) {
if ( V_395 [ V_136 ] != V_389 -> V_394 )
continue;
V_129 = F_17 ( V_26 , V_396 , V_136 ) ;
if ( V_129 < 0 )
return V_129 ;
break;
}
}
if ( V_389 -> V_397 ) {
V_129 = F_182 ( V_26 , V_398 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_389 -> V_399 ) {
V_129 = F_182 ( V_26 , V_400 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_389 -> V_223 ) {
V_129 = F_182 ( V_26 , V_401 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_389 -> V_402 ) {
V_129 = F_73 ( V_26 , V_403 ,
strlen ( V_389 -> V_402 ) , V_389 -> V_402 ) ;
if ( V_129 < 0 )
return V_129 ;
}
return 0 ;
}
static void F_183 ( int V_387 , struct V_385 * V_91 ,
struct V_388 * V_389 )
{
struct V_25 * V_384 ;
void * V_23 ;
V_384 = F_70 ( V_145 , V_36 ) ;
if ( ! V_384 )
return;
V_23 = F_71 ( V_384 , 0 , 0 , & V_147 , 0 ,
V_404 ) ;
if ( ! V_23 )
goto V_405;
if ( F_181 ( V_384 , V_387 , V_389 ) < 0 )
goto V_405;
F_75 ( V_384 , V_23 ) ;
F_178 ( V_384 , V_91 ) ;
return;
V_405:
F_184 ( V_384 , V_23 ) ;
F_78 ( V_384 ) ;
}
static int F_185 ( struct V_385 * V_91 ,
struct V_388 * V_389 )
{
int V_30 ;
T_2 V_8 [ V_51 ] ;
struct V_40 * V_23 ;
struct V_79 * V_44 ;
enum V_406 V_194 ;
const struct V_407 * V_408 = & V_409 ;
int V_161 ;
if ( F_6 ( V_389 -> V_352 > 1 && ! V_389 -> V_223 ) )
return - V_34 ;
F_186 ( & V_209 ) ;
V_161 = V_410 ++ ;
F_187 ( & V_209 ) ;
if ( V_389 -> V_223 )
V_408 = & V_411 ;
V_44 = F_188 ( sizeof( * V_23 ) , V_408 , V_389 -> V_402 ) ;
if ( ! V_44 ) {
F_72 ( V_149 L_47 ) ;
V_30 = - V_37 ;
goto V_412;
}
V_23 = V_44 -> V_80 ;
V_23 -> V_44 = V_44 ;
V_23 -> V_75 = F_189 ( V_413 , NULL , 0 , V_44 , L_48 , V_161 ) ;
if ( F_190 ( V_23 -> V_75 ) ) {
F_72 ( V_149
L_49 ,
F_191 ( V_23 -> V_75 ) ) ;
V_30 = - V_37 ;
goto V_414;
}
V_23 -> V_75 -> V_415 = & V_416 . V_415 ;
V_30 = F_192 ( V_23 -> V_75 ) ;
if ( V_30 != 0 ) {
F_72 ( V_149 L_50 ,
V_30 ) ;
goto V_417;
}
F_193 ( & V_23 -> V_141 ) ;
F_194 ( V_44 , V_23 -> V_75 ) ;
F_163 ( V_8 ) ;
V_8 [ 0 ] = 0x02 ;
V_8 [ 3 ] = V_161 >> 8 ;
V_8 [ 4 ] = V_161 ;
memcpy ( V_23 -> V_151 [ 0 ] . V_8 , V_8 , V_51 ) ;
memcpy ( V_23 -> V_151 [ 1 ] . V_8 , V_8 , V_51 ) ;
V_23 -> V_151 [ 1 ] . V_8 [ 0 ] |= 0x40 ;
V_44 -> V_20 -> V_418 = 2 ;
V_44 -> V_20 -> V_151 = V_23 -> V_151 ;
V_23 -> V_352 = V_389 -> V_352 ;
V_23 -> V_223 = V_389 -> V_223 ;
V_23 -> V_161 = V_161 ;
V_23 -> V_419 = V_389 -> V_419 ;
if ( V_91 )
V_23 -> V_420 = V_91 -> V_421 ;
if ( V_23 -> V_223 ) {
V_44 -> V_20 -> V_422 = 255 ;
V_44 -> V_20 -> V_423 = V_424 ;
V_44 -> V_20 -> V_425 = 1000 ;
V_44 -> V_20 -> V_426 = 1 ;
V_44 -> V_20 -> V_427 = & V_23 -> V_428 ;
if ( V_389 -> V_399 )
V_23 -> V_428 = V_429 [ 0 ] ;
else
V_23 -> V_428 = V_430 [ 0 ] ;
V_23 -> V_428 . V_431 = V_23 -> V_352 ;
} else if ( V_389 -> V_399 ) {
V_44 -> V_20 -> V_427 = V_429 ;
V_44 -> V_20 -> V_426 =
F_106 ( V_429 ) ;
} else {
V_44 -> V_20 -> V_427 = V_430 ;
V_44 -> V_20 -> V_426 = F_106 ( V_430 ) ;
}
F_195 ( & V_23 -> V_369 , F_164 ) ;
F_195 ( & V_23 -> V_371 , F_166 ) ;
F_195 ( & V_23 -> V_343 , F_150 ) ;
V_44 -> V_339 = 5 ;
V_44 -> V_432 = 4 ;
V_44 -> V_20 -> V_433 = F_83 ( V_434 ) |
F_83 ( V_245 ) |
F_83 ( V_435 ) |
F_83 ( V_436 ) |
F_83 ( V_247 ) |
F_83 ( V_246 ) ;
if ( V_389 -> V_399 )
V_44 -> V_20 -> V_433 |= F_83 ( V_437 ) ;
F_196 ( V_44 , V_438 ) ;
F_196 ( V_44 , V_439 ) ;
F_196 ( V_44 , V_440 ) ;
F_196 ( V_44 , V_441 ) ;
F_196 ( V_44 , V_442 ) ;
F_196 ( V_44 , V_443 ) ;
F_196 ( V_44 , V_444 ) ;
F_196 ( V_44 , V_445 ) ;
F_196 ( V_44 , V_446 ) ;
if ( V_447 )
F_196 ( V_44 , V_225 ) ;
V_44 -> V_20 -> V_89 |= V_448 |
V_449 |
V_450 |
V_451 ;
V_44 -> V_20 -> V_452 |= V_453 |
V_454 |
V_455 |
V_456 |
V_457 ;
F_197 ( V_44 -> V_20 , V_458 ) ;
V_44 -> V_459 = sizeof( struct V_3 ) ;
V_44 -> V_460 = sizeof( struct V_12 ) ;
V_44 -> V_461 = sizeof( struct V_17 ) ;
memcpy ( V_23 -> V_462 , V_463 ,
sizeof( V_463 ) ) ;
memcpy ( V_23 -> V_464 , V_465 ,
sizeof( V_465 ) ) ;
memcpy ( V_23 -> V_163 , V_466 , sizeof( V_466 ) ) ;
for ( V_194 = V_467 ; V_194 < V_468 ; V_194 ++ ) {
struct V_469 * V_470 = & V_23 -> V_471 [ V_194 ] ;
switch ( V_194 ) {
case V_467 :
V_470 -> V_352 = V_23 -> V_462 ;
V_470 -> V_350 = F_106 ( V_463 ) ;
V_470 -> V_472 = V_23 -> V_163 ;
V_470 -> V_473 = F_106 ( V_466 ) ;
break;
case V_474 :
V_470 -> V_352 = V_23 -> V_464 ;
V_470 -> V_350 = F_106 ( V_465 ) ;
V_470 -> V_472 = V_23 -> V_163 + 4 ;
V_470 -> V_473 = F_106 ( V_466 ) - 4 ;
V_470 -> V_475 . V_476 = true ;
V_470 -> V_475 . V_477 =
V_478 |
V_479 |
V_480 |
V_481 |
V_482 |
V_483 |
V_484 |
V_485 |
V_486 |
V_487 |
V_488 ;
V_470 -> V_475 . V_489 . V_490 =
F_24 ( V_491 << 0 |
V_491 << 2 |
V_491 << 4 |
V_491 << 6 |
V_491 << 8 |
V_491 << 10 |
V_491 << 12 |
V_491 << 14 ) ;
V_470 -> V_475 . V_489 . V_492 =
V_470 -> V_475 . V_489 . V_490 ;
break;
default:
continue;
}
V_470 -> V_493 . V_494 = true ;
V_470 -> V_493 . V_477 = V_495 |
V_496 |
V_497 |
V_498 |
V_499 ;
V_470 -> V_493 . V_500 = 0x3 ;
V_470 -> V_493 . V_501 = 0x6 ;
memset ( & V_470 -> V_493 . V_502 , 0 ,
sizeof( V_470 -> V_493 . V_502 ) ) ;
V_470 -> V_493 . V_502 . V_503 [ 0 ] = 0xff ;
V_470 -> V_493 . V_502 . V_503 [ 1 ] = 0xff ;
V_470 -> V_493 . V_502 . V_504 = V_505 ;
V_44 -> V_20 -> V_471 [ V_194 ] = V_470 ;
}
V_23 -> V_73 = 1 ;
F_198 ( & V_23 -> V_348 ) ;
V_44 -> V_506 = 4 ;
V_44 -> V_507 = 11 ;
V_44 -> V_20 -> V_508 = V_509 ;
V_44 -> V_20 -> V_510 =
F_106 ( V_509 ) ;
V_44 -> V_20 -> V_511 = V_512 ;
V_44 -> V_20 -> V_513 = F_106 ( V_512 ) ;
if ( V_389 -> V_397 )
V_44 -> V_20 -> V_514 |= V_515 ;
if ( V_389 -> V_394 ) {
V_23 -> V_394 = V_389 -> V_394 ;
V_44 -> V_20 -> V_514 |= V_516 ;
F_199 ( V_44 -> V_20 , V_389 -> V_394 ) ;
F_200 ( 1 ) ;
}
if ( V_389 -> V_517 )
F_196 ( V_44 , V_518 ) ;
V_30 = F_201 ( V_44 ) ;
if ( V_30 < 0 ) {
F_72 ( V_149 L_51 ,
V_30 ) ;
goto V_519;
}
F_15 ( V_44 -> V_20 , L_52 , V_44 -> V_20 -> V_520 ) ;
if ( V_389 -> V_392 ) {
V_23 -> V_521 [ 0 ] = V_389 -> V_392 [ 0 ] ;
V_23 -> V_521 [ 1 ] = V_389 -> V_392 [ 1 ] ;
F_202 ( V_44 -> V_20 , V_389 -> V_392 ) ;
}
V_23 -> V_522 = F_203 ( L_53 , V_44 -> V_20 -> V_523 ) ;
F_204 ( L_54 , 0666 , V_23 -> V_522 , V_23 , & V_524 ) ;
F_204 ( L_55 , 0666 , V_23 -> V_522 , V_23 ,
& V_525 ) ;
if ( ! V_23 -> V_223 )
F_204 ( L_56 , 0222 ,
V_23 -> V_522 ,
V_23 , & V_526 ) ;
F_205 ( & V_23 -> V_234 ,
F_122 ,
V_527 , V_255 ) ;
F_186 ( & V_209 ) ;
F_206 ( & V_23 -> V_528 , & V_529 ) ;
F_187 ( & V_209 ) ;
if ( V_161 > 0 )
F_183 ( V_161 , V_91 , V_389 ) ;
return V_161 ;
V_519:
F_207 ( V_23 -> V_75 ) ;
V_417:
F_208 ( V_23 -> V_75 ) ;
V_414:
F_209 ( V_44 ) ;
V_412:
return V_30 ;
}
static void F_210 ( int V_387 , const char * V_402 ,
struct V_385 * V_91 )
{
struct V_25 * V_26 ;
void * V_23 ;
int V_129 ;
V_26 = F_70 ( V_145 , V_36 ) ;
if ( ! V_26 )
return;
V_23 = F_71 ( V_26 , 0 , 0 , & V_147 , 0 ,
V_530 ) ;
if ( ! V_23 )
goto error;
V_129 = F_17 ( V_26 , V_390 , V_387 ) ;
if ( V_129 < 0 )
goto error;
V_129 = F_73 ( V_26 , V_403 , strlen ( V_402 ) ,
V_402 ) ;
if ( V_129 < 0 )
goto error;
F_75 ( V_26 , V_23 ) ;
F_178 ( V_26 , V_91 ) ;
return;
error:
F_78 ( V_26 ) ;
}
static void F_211 ( struct V_40 * V_23 ,
const char * V_402 ,
struct V_385 * V_91 )
{
F_210 ( V_23 -> V_161 , V_402 , V_91 ) ;
F_212 ( V_23 -> V_522 ) ;
F_213 ( V_23 -> V_44 ) ;
F_207 ( V_23 -> V_75 ) ;
F_208 ( V_23 -> V_75 ) ;
F_209 ( V_23 -> V_44 ) ;
}
static int F_214 ( struct V_25 * V_26 ,
struct V_40 * V_23 ,
T_1 V_420 , T_1 V_531 ,
struct V_532 * V_122 , int V_89 )
{
void * V_58 ;
struct V_388 V_389 = { } ;
int V_533 = - V_534 ;
V_58 = F_71 ( V_26 , V_420 , V_531 , & V_147 , V_89 ,
V_535 ) ;
if ( ! V_58 )
return - V_534 ;
if ( V_122 )
F_215 ( V_122 , V_58 , & V_147 ) ;
if ( V_23 -> V_521 [ 0 ] && V_23 -> V_521 [ 1 ] )
V_389 . V_392 = V_23 -> V_521 ;
V_389 . V_397 = ! ! ( V_23 -> V_44 -> V_20 -> V_514 &
V_515 ) ;
V_389 . V_399 = ! ! ( V_23 -> V_44 -> V_20 -> V_433 &
F_83 ( V_437 ) ) ;
V_389 . V_223 = V_23 -> V_223 ;
V_389 . V_394 = V_23 -> V_394 ;
V_389 . V_352 = V_23 -> V_352 ;
V_389 . V_402 = F_216 ( V_23 -> V_44 -> V_20 ) ;
V_533 = F_181 ( V_26 , V_23 -> V_161 , & V_389 ) ;
if ( V_533 < 0 )
goto V_405;
F_75 ( V_26 , V_58 ) ;
return 0 ;
V_405:
F_184 ( V_26 , V_58 ) ;
return V_533 ;
}
static void F_217 ( void )
{
struct V_40 * V_23 ;
F_186 ( & V_209 ) ;
while ( ( V_23 = F_218 ( & V_529 ,
struct V_40 ,
V_528 ) ) ) {
F_219 ( & V_23 -> V_528 ) ;
F_187 ( & V_209 ) ;
F_211 ( V_23 , F_216 ( V_23 -> V_44 -> V_20 ) ,
NULL ) ;
F_186 ( & V_209 ) ;
}
F_187 ( & V_209 ) ;
F_220 ( V_413 ) ;
}
static void F_221 ( struct V_74 * V_75 )
{
V_75 -> V_536 = & V_537 ;
V_75 -> V_538 = V_539 ;
F_222 ( V_75 ) ;
V_75 -> V_540 |= V_541 ;
V_75 -> type = V_542 ;
F_163 ( V_75 -> V_543 ) ;
V_75 -> V_543 [ 0 ] = 0x12 ;
}
static struct V_40 * F_223 ( const T_2 * V_8 )
{
struct V_40 * V_23 ;
bool V_544 = false ;
F_186 ( & V_209 ) ;
F_95 (data, &hwsim_radios, list) {
if ( memcmp ( V_23 -> V_151 [ 1 ] . V_8 , V_8 , V_51 ) == 0 ) {
V_544 = true ;
break;
}
}
F_187 ( & V_209 ) ;
if ( ! V_544 )
return NULL ;
return V_23 ;
}
static int F_224 ( struct V_25 * V_545 ,
struct V_385 * V_91 )
{
struct V_57 * V_58 ;
struct V_40 * V_188 ;
struct V_90 * V_221 ;
struct V_137 * V_138 ;
T_3 V_546 ;
struct V_25 * V_26 , * V_547 ;
const T_2 * V_548 ;
unsigned int V_135 ;
int V_136 ;
bool V_549 = false ;
if ( V_91 -> V_421 != V_232 )
return - V_34 ;
if ( ! V_91 -> V_550 [ V_150 ] ||
! V_91 -> V_550 [ V_158 ] ||
! V_91 -> V_550 [ V_168 ] ||
! V_91 -> V_550 [ V_551 ] ||
! V_91 -> V_550 [ V_165 ] )
goto V_254;
V_548 = ( void * ) F_225 ( V_91 -> V_550 [ V_150 ] ) ;
V_135 = F_14 ( V_91 -> V_550 [ V_158 ] ) ;
V_546 = F_226 ( V_91 -> V_550 [ V_168 ] ) ;
V_188 = F_223 ( V_548 ) ;
if ( ! V_188 )
goto V_254;
F_227 (&data2->pending, skb, tmp) {
T_3 V_552 ;
V_221 = F_53 ( V_26 ) ;
V_552 = ( T_3 ) ( T_7 ) V_221 -> V_167 [ 0 ] ;
if ( V_552 == V_546 ) {
F_228 ( V_26 , & V_188 -> V_141 ) ;
V_549 = true ;
break;
}
}
if ( ! V_549 )
goto V_254;
V_138 = (struct V_137 * ) F_225 (
V_91 -> V_550 [ V_165 ] ) ;
V_221 = F_53 ( V_26 ) ;
F_108 ( V_221 ) ;
for ( V_136 = 0 ; V_136 < V_139 ; V_136 ++ ) {
V_221 -> V_162 . V_163 [ V_136 ] . V_161 = V_138 [ V_136 ] . V_161 ;
V_221 -> V_162 . V_163 [ V_136 ] . V_164 = V_138 [ V_136 ] . V_164 ;
}
V_221 -> V_162 . V_553 = F_14 ( V_91 -> V_550 [ V_551 ] ) ;
if ( ! ( V_135 & V_157 ) &&
( V_135 & V_554 ) ) {
if ( V_26 -> V_153 >= 16 ) {
V_58 = (struct V_57 * ) V_26 -> V_23 ;
F_62 ( V_188 -> V_160 ,
V_58 -> V_63 ) ;
}
V_221 -> V_89 |= V_233 ;
}
F_109 ( V_188 -> V_44 , V_26 ) ;
return 0 ;
V_254:
return - V_34 ;
}
static int F_229 ( struct V_25 * V_545 ,
struct V_385 * V_91 )
{
struct V_40 * V_188 ;
struct V_190 V_191 ;
const T_2 * V_555 ;
int V_556 ;
void * V_557 ;
struct V_25 * V_26 = NULL ;
if ( V_91 -> V_421 != V_232 )
return - V_34 ;
if ( ! V_91 -> V_550 [ V_558 ] ||
! V_91 -> V_550 [ V_152 ] ||
! V_91 -> V_550 [ V_559 ] ||
! V_91 -> V_550 [ V_551 ] )
goto V_254;
V_555 = ( void * ) F_225 ( V_91 -> V_550 [ V_558 ] ) ;
V_556 = F_230 ( V_91 -> V_550 [ V_152 ] ) ;
V_557 = ( void * ) F_225 ( V_91 -> V_550 [ V_152 ] ) ;
V_26 = F_231 ( V_556 , V_36 ) ;
if ( V_26 == NULL )
goto V_30;
if ( V_556 > V_424 )
goto V_30;
memcpy ( F_23 ( V_26 , V_556 ) , V_557 , V_556 ) ;
V_188 = F_223 ( V_555 ) ;
if ( ! V_188 )
goto V_254;
if ( V_188 -> V_212 || ! V_188 -> V_211 )
goto V_254;
memset ( & V_191 , 0 , sizeof( V_191 ) ) ;
if ( V_91 -> V_550 [ V_159 ] ) {
F_151 ( & V_188 -> V_348 ) ;
V_191 . V_193 = F_14 ( V_91 -> V_550 [ V_159 ] ) ;
if ( V_191 . V_193 != V_188 -> V_160 -> V_110 &&
( ! V_188 -> V_213 ||
V_191 . V_193 != V_188 -> V_213 -> V_110 ) ) {
F_153 ( & V_188 -> V_348 ) ;
goto V_254;
}
F_153 ( & V_188 -> V_348 ) ;
} else {
V_191 . V_193 = V_188 -> V_160 -> V_110 ;
}
V_191 . V_194 = V_188 -> V_160 -> V_194 ;
V_191 . V_197 = F_14 ( V_91 -> V_550 [ V_559 ] ) ;
V_191 . signal = F_14 ( V_91 -> V_550 [ V_551 ] ) ;
memcpy ( F_84 ( V_26 ) , & V_191 , sizeof( V_191 ) ) ;
V_188 -> V_218 ++ ;
V_188 -> V_219 += V_26 -> V_153 ;
F_101 ( V_188 -> V_44 , V_26 ) ;
return 0 ;
V_30:
F_72 ( V_149 L_6 , V_35 ) ;
V_254:
F_42 ( V_26 ) ;
return - V_34 ;
}
static int F_232 ( struct V_25 * V_545 ,
struct V_385 * V_91 )
{
struct V_40 * V_23 ;
int V_560 = 1 ;
F_186 ( & V_209 ) ;
F_95 (data, &hwsim_radios, list)
V_560 = F_233 ( V_560 , V_23 -> V_352 ) ;
F_187 ( & V_209 ) ;
if ( V_560 > 1 )
return - V_326 ;
if ( V_232 )
return - V_365 ;
V_232 = V_91 -> V_421 ;
F_72 ( V_149 L_57
L_58 , V_91 -> V_421 ) ;
return 0 ;
}
static int F_234 ( struct V_25 * V_561 , struct V_385 * V_91 )
{
struct V_388 V_389 = { 0 } ;
V_389 . V_397 = V_91 -> V_550 [ V_398 ] ;
V_389 . V_399 = V_91 -> V_550 [ V_400 ] ;
V_389 . V_352 = V_352 ;
V_389 . V_419 =
V_91 -> V_550 [ V_562 ] ;
if ( V_91 -> V_550 [ V_391 ] )
V_389 . V_352 = F_14 ( V_91 -> V_550 [ V_391 ] ) ;
if ( V_91 -> V_550 [ V_563 ] )
V_389 . V_517 = true ;
if ( V_91 -> V_550 [ V_403 ] )
V_389 . V_402 = F_225 ( V_91 -> V_550 [ V_403 ] ) ;
if ( V_91 -> V_550 [ V_401 ] )
V_389 . V_223 = true ;
else
V_389 . V_223 = ( V_389 . V_352 > 1 ) ;
if ( V_91 -> V_550 [ V_393 ] )
V_389 . V_392 =
F_225 ( V_91 -> V_550 [ V_393 ] ) ;
if ( V_91 -> V_550 [ V_396 ] ) {
T_1 V_161 = F_14 ( V_91 -> V_550 [ V_396 ] ) ;
if ( V_161 >= F_106 ( V_395 ) )
return - V_34 ;
V_389 . V_394 = V_395 [ V_161 ] ;
}
return F_185 ( V_91 , & V_389 ) ;
}
static int F_235 ( struct V_25 * V_561 , struct V_385 * V_91 )
{
struct V_40 * V_23 ;
T_9 V_161 = - 1 ;
const char * V_402 = NULL ;
if ( V_91 -> V_550 [ V_390 ] )
V_161 = F_14 ( V_91 -> V_550 [ V_390 ] ) ;
else if ( V_91 -> V_550 [ V_403 ] )
V_402 = ( void * ) F_225 ( V_91 -> V_550 [ V_403 ] ) ;
else
return - V_34 ;
F_186 ( & V_209 ) ;
F_95 (data, &hwsim_radios, list) {
if ( V_161 >= 0 ) {
if ( V_23 -> V_161 != V_161 )
continue;
} else {
if ( strcmp ( V_402 , F_216 ( V_23 -> V_44 -> V_20 ) ) )
continue;
}
F_219 ( & V_23 -> V_528 ) ;
F_187 ( & V_209 ) ;
F_211 ( V_23 , F_216 ( V_23 -> V_44 -> V_20 ) ,
V_91 ) ;
return 0 ;
}
F_187 ( & V_209 ) ;
return - V_564 ;
}
static int F_236 ( struct V_25 * V_561 , struct V_385 * V_91 )
{
struct V_40 * V_23 ;
struct V_25 * V_26 ;
int V_161 , V_533 = - V_564 ;
if ( ! V_91 -> V_550 [ V_390 ] )
return - V_34 ;
V_161 = F_14 ( V_91 -> V_550 [ V_390 ] ) ;
F_186 ( & V_209 ) ;
F_95 (data, &hwsim_radios, list) {
if ( V_23 -> V_161 != V_161 )
continue;
V_26 = F_237 ( V_565 , V_36 ) ;
if ( ! V_26 ) {
V_533 = - V_37 ;
goto V_405;
}
V_533 = F_214 ( V_26 , V_23 , V_91 -> V_421 ,
V_91 -> V_566 , NULL , 0 ) ;
if ( V_533 < 0 ) {
F_78 ( V_26 ) ;
goto V_405;
}
F_238 ( V_26 , V_91 ) ;
break;
}
V_405:
F_187 ( & V_209 ) ;
return V_533 ;
}
static int F_239 ( struct V_25 * V_26 ,
struct V_532 * V_122 )
{
int V_161 = V_122 -> args [ 0 ] ;
struct V_40 * V_23 = NULL ;
int V_533 ;
F_186 ( & V_209 ) ;
if ( V_161 == V_410 )
goto V_567;
F_95 (data, &hwsim_radios, list) {
if ( V_23 -> V_161 < V_161 )
continue;
V_533 = F_214 ( V_26 , V_23 ,
F_240 ( V_122 -> V_26 ) . V_420 ,
V_122 -> V_568 -> V_569 , V_122 ,
V_570 ) ;
if ( V_533 < 0 )
break;
V_161 = V_23 -> V_161 + 1 ;
}
V_122 -> args [ 0 ] = V_161 ;
V_567:
F_187 ( & V_209 ) ;
return V_26 -> V_153 ;
}
static void F_241 ( struct V_341 * V_342 )
{
struct V_40 * V_23 =
F_123 ( V_342 , struct V_40 , V_571 ) ;
F_211 ( V_23 , F_216 ( V_23 -> V_44 -> V_20 ) , NULL ) ;
}
static void F_242 ( T_1 V_420 )
{
struct V_40 * V_572 , * V_547 ;
F_186 ( & V_209 ) ;
F_243 (entry, tmp, &hwsim_radios, list) {
if ( V_572 -> V_419 && V_572 -> V_420 == V_420 ) {
F_219 ( & V_572 -> V_528 ) ;
F_244 ( & V_572 -> V_571 , F_241 ) ;
F_245 ( & V_572 -> V_571 ) ;
}
}
F_187 ( & V_209 ) ;
}
static int F_246 ( struct V_573 * V_574 ,
unsigned long V_575 ,
void * V_576 )
{
struct V_577 * V_578 = V_576 ;
if ( V_575 != V_579 )
return V_580 ;
F_242 ( V_578 -> V_420 ) ;
if ( V_578 -> V_420 == V_232 ) {
F_72 ( V_581 L_59
L_60 ) ;
V_232 = 0 ;
}
return V_580 ;
}
static int F_247 ( void )
{
int V_582 ;
F_72 ( V_581 L_61 ) ;
V_582 = F_248 ( & V_147 ,
V_583 ,
V_584 ) ;
if ( V_582 )
goto V_585;
V_582 = F_249 ( & V_586 ) ;
if ( V_582 ) {
F_250 ( & V_147 ) ;
goto V_585;
}
return 0 ;
V_585:
F_72 ( V_149 L_6 , V_35 ) ;
return - V_34 ;
}
static void F_251 ( void )
{
F_252 ( & V_586 ) ;
F_250 ( & V_147 ) ;
}
static int T_10 F_253 ( void )
{
int V_136 , V_30 ;
if ( V_587 < 0 || V_587 > 100 )
return - V_34 ;
if ( V_352 < 1 )
return - V_34 ;
V_411 = V_409 ;
V_411 . V_343 = F_157 ;
V_411 . V_588 = F_159 ;
V_411 . V_589 = NULL ;
V_411 . V_590 = NULL ;
V_411 . V_591 = F_168 ;
V_411 . V_592 = F_169 ;
V_411 . V_593 = F_170 ;
V_411 . V_594 = F_171 ;
V_411 . V_595 = F_172 ;
V_411 . V_596 =
F_173 ;
V_411 . V_597 =
F_174 ;
F_254 ( & V_209 ) ;
F_255 ( & V_529 ) ;
V_30 = F_256 ( & V_416 ) ;
if ( V_30 )
return V_30 ;
V_413 = F_257 ( V_598 , L_62 ) ;
if ( F_190 ( V_413 ) ) {
V_30 = F_191 ( V_413 ) ;
goto V_599;
}
V_30 = F_247 () ;
if ( V_30 < 0 )
goto V_599;
for ( V_136 = 0 ; V_136 < V_587 ; V_136 ++ ) {
struct V_388 V_389 = { 0 } ;
V_389 . V_352 = V_352 ;
switch ( V_600 ) {
case V_601 :
if ( V_136 < F_106 ( V_602 ) )
V_389 . V_392 = V_602 [ V_136 ] ;
break;
case V_603 :
if ( ! V_136 )
V_389 . V_392 = V_602 [ 0 ] ;
break;
case V_604 :
V_389 . V_397 = true ;
case V_605 :
V_389 . V_392 = V_602 [ 0 ] ;
break;
case V_606 :
if ( V_136 == 0 )
V_389 . V_394 = & V_607 ;
break;
case V_608 :
V_389 . V_394 = & V_607 ;
break;
case V_609 :
if ( V_136 == 0 )
V_389 . V_394 = & V_607 ;
else if ( V_136 == 1 )
V_389 . V_394 = & V_610 ;
break;
case V_611 :
if ( V_136 == 0 ) {
V_389 . V_397 = true ;
V_389 . V_392 = V_602 [ 0 ] ;
}
break;
case V_612 :
if ( V_136 == 0 ) {
V_389 . V_397 = true ;
V_389 . V_392 = V_602 [ 0 ] ;
} else if ( V_136 == 1 ) {
V_389 . V_392 = V_602 [ 1 ] ;
}
break;
case V_613 :
switch ( V_136 ) {
case 0 :
V_389 . V_394 = & V_607 ;
break;
case 1 :
V_389 . V_394 = & V_610 ;
break;
case 2 :
V_389 . V_392 = V_602 [ 0 ] ;
break;
case 3 :
V_389 . V_392 = V_602 [ 1 ] ;
break;
case 4 :
V_389 . V_397 = true ;
V_389 . V_392 = V_602 [ 2 ] ;
break;
}
break;
default:
break;
}
V_389 . V_399 = V_614 ;
V_389 . V_223 = V_352 > 1 ;
V_30 = F_185 ( NULL , & V_389 ) ;
if ( V_30 < 0 )
goto V_615;
}
V_94 = F_258 ( 0 , L_48 , V_616 ,
F_221 ) ;
if ( V_94 == NULL ) {
V_30 = - V_37 ;
goto V_615;
}
F_259 () ;
V_30 = F_260 ( V_94 , V_94 -> V_617 ) ;
if ( V_30 < 0 ) {
F_261 () ;
goto V_615;
}
V_30 = F_262 ( V_94 ) ;
if ( V_30 < 0 ) {
F_261 () ;
goto V_618;
}
F_261 () ;
return 0 ;
V_618:
V_539 ( V_94 ) ;
V_615:
F_217 () ;
V_599:
F_263 ( & V_416 ) ;
return V_30 ;
}
static void T_11 F_264 ( void )
{
F_72 ( V_149 L_63 ) ;
F_251 () ;
F_217 () ;
F_265 ( V_94 ) ;
F_263 ( & V_416 ) ;
}
