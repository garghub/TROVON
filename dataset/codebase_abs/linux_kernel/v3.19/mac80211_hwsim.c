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
static void F_12 ( void * V_20 , T_1 * V_21 , struct V_1 * V_2 )
{
struct V_22 * V_23 = V_20 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
if ( ! V_4 -> V_28 )
return;
F_13 ( V_23 -> V_29 -> V_30 ,
L_2 ,
V_31 , V_4 -> V_32 , V_4 -> V_33 ) ;
V_25 = F_14 ( sizeof( * V_27 ) ) ;
if ( ! V_25 )
return;
V_27 = ( void * ) F_15 ( V_25 , sizeof( * V_27 ) ) ;
V_27 -> V_34 = F_16 ( V_35 |
V_36 |
V_37 ) ;
V_27 -> V_33 = F_16 ( 0xc000 | V_4 -> V_33 ) ;
memcpy ( V_27 -> V_32 , V_4 -> V_32 , V_38 ) ;
memcpy ( V_27 -> V_39 , V_21 , V_38 ) ;
F_17 () ;
F_18 ( V_23 -> V_29 , V_25 ,
F_19 ( V_2 -> V_40 ) -> V_41 . V_42 ) ;
F_20 () ;
}
static void F_21 ( struct V_22 * V_23 , T_1 * V_21 ,
struct V_1 * V_2 , int V_43 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_24 * V_25 ;
struct V_44 * V_45 ;
if ( ! V_4 -> V_28 )
return;
F_13 ( V_23 -> V_29 -> V_30 ,
L_3 ,
V_31 , V_4 -> V_32 , V_43 ) ;
V_25 = F_14 ( sizeof( * V_45 ) ) ;
if ( ! V_25 )
return;
V_45 = ( void * ) F_15 ( V_25 , sizeof( * V_45 ) - V_38 ) ;
V_45 -> V_34 = F_16 ( V_46 |
V_47 |
( V_43 ? V_37 : 0 ) ) ;
V_45 -> V_48 = F_16 ( 0 ) ;
memcpy ( V_45 -> V_49 , V_4 -> V_32 , V_38 ) ;
memcpy ( V_45 -> V_50 , V_21 , V_38 ) ;
memcpy ( V_45 -> V_51 , V_4 -> V_32 , V_38 ) ;
F_17 () ;
F_18 ( V_23 -> V_29 , V_25 ,
F_19 ( V_2 -> V_40 ) -> V_41 . V_42 ) ;
F_20 () ;
}
static void F_22 ( void * V_20 , T_1 * V_21 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = V_20 ;
F_21 ( V_23 , V_21 , V_2 , 1 ) ;
}
static void F_23 ( void * V_20 , T_1 * V_21 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = V_20 ;
F_21 ( V_23 , V_21 , V_2 , 0 ) ;
}
static int F_24 ( void * V_20 , T_2 * V_52 )
{
struct V_22 * V_23 = V_20 ;
* V_52 = V_23 -> V_43 ;
return 0 ;
}
static int F_25 ( void * V_20 , T_2 V_52 )
{
struct V_22 * V_23 = V_20 ;
enum V_53 V_54 ;
if ( V_52 != V_55 && V_52 != V_56 && V_52 != V_57 &&
V_52 != V_58 )
return - V_59 ;
V_54 = V_23 -> V_43 ;
V_23 -> V_43 = V_52 ;
if ( V_52 == V_58 ) {
F_26 ( V_23 -> V_29 ,
V_60 ,
F_12 , V_23 ) ;
V_23 -> V_61 = true ;
} else if ( V_54 == V_55 && V_52 != V_55 ) {
F_26 ( V_23 -> V_29 ,
V_60 ,
F_22 ,
V_23 ) ;
} else if ( V_54 != V_55 && V_52 == V_55 ) {
F_26 ( V_23 -> V_29 ,
V_60 ,
F_23 ,
V_23 ) ;
}
return 0 ;
}
static int F_27 ( void * V_20 , T_2 V_52 )
{
struct V_22 * V_23 = V_20 ;
F_28 ( V_23 -> V_29 ) ;
return 0 ;
}
static int F_29 ( void * V_20 , T_2 * V_52 )
{
struct V_22 * V_23 = V_20 ;
* V_52 = V_23 -> V_62 ;
return 0 ;
}
static int F_30 ( void * V_20 , T_2 V_52 )
{
struct V_22 * V_23 = V_20 ;
V_23 -> V_62 = V_52 ;
return 0 ;
}
static T_3 F_31 ( struct V_24 * V_25 ,
struct V_63 * V_64 )
{
F_32 ( V_25 ) ;
return V_65 ;
}
static inline T_2 F_33 ( void )
{
return F_34 ( F_35 () ) ;
}
static T_4 F_36 ( struct V_22 * V_23 )
{
T_2 V_66 = F_33 () ;
return F_37 ( V_66 + V_23 -> V_67 ) ;
}
static T_2 F_38 ( struct V_68 * V_29 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
return F_39 ( F_36 ( V_23 ) ) ;
}
static void F_40 ( struct V_68 * V_29 ,
struct V_1 * V_2 , T_2 V_70 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
T_2 V_66 = F_38 ( V_29 , V_2 ) ;
T_5 V_71 = V_23 -> V_72 ;
T_2 V_73 = F_41 ( V_70 - V_66 ) ;
if ( V_70 > V_66 ) {
V_23 -> V_67 += V_73 ;
V_23 -> V_74 = F_42 ( V_73 , V_71 ) ;
} else {
V_23 -> V_67 -= V_73 ;
V_23 -> V_74 = - F_42 ( V_73 , V_71 ) ;
}
}
static void F_43 ( struct V_68 * V_29 ,
struct V_24 * V_75 ,
struct V_76 * V_42 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
struct V_24 * V_25 ;
struct V_77 * V_45 ;
T_6 V_78 ;
struct V_79 * V_80 = F_44 ( V_75 ) ;
struct V_81 * V_82 = F_45 ( V_29 , V_80 ) ;
if ( ! F_46 ( V_83 ) )
return;
V_25 = F_47 ( V_75 , sizeof( * V_45 ) , 0 , V_84 ) ;
if ( V_25 == NULL )
return;
V_45 = (struct V_77 * ) F_48 ( V_25 , sizeof( * V_45 ) ) ;
V_45 -> V_45 . V_85 = V_86 ;
V_45 -> V_45 . V_87 = 0 ;
V_45 -> V_45 . V_88 = F_16 ( sizeof( * V_45 ) ) ;
V_45 -> V_45 . V_89 = F_49 ( ( 1 << V_90 ) |
( 1 << V_91 ) |
( 1 << V_92 ) |
( 1 << V_93 ) ) ;
V_45 -> V_94 = F_36 ( V_23 ) ;
V_45 -> V_95 = 0 ;
V_45 -> V_96 = V_82 -> V_97 / 5 ;
V_45 -> V_98 = F_16 ( V_42 -> V_99 ) ;
V_78 = V_100 ;
if ( V_82 -> V_78 & V_101 )
V_78 |= V_102 ;
else
V_78 |= V_103 ;
V_45 -> V_104 = F_16 ( V_78 ) ;
V_25 -> V_64 = V_83 ;
F_50 ( V_25 , 0 ) ;
V_25 -> V_105 = V_106 ;
V_25 -> V_107 = V_108 ;
V_25 -> V_109 = F_51 ( V_110 ) ;
memset ( V_25 -> V_111 , 0 , sizeof( V_25 -> V_111 ) ) ;
F_52 ( V_25 ) ;
}
static void F_53 ( struct V_76 * V_42 ,
const T_1 * V_8 )
{
struct V_24 * V_25 ;
struct V_112 * V_45 ;
T_6 V_78 ;
struct V_44 * V_113 ;
if ( ! F_46 ( V_83 ) )
return;
V_25 = F_14 ( 100 ) ;
if ( V_25 == NULL )
return;
V_45 = (struct V_112 * ) F_15 ( V_25 , sizeof( * V_45 ) ) ;
V_45 -> V_45 . V_85 = V_86 ;
V_45 -> V_45 . V_87 = 0 ;
V_45 -> V_45 . V_88 = F_16 ( sizeof( * V_45 ) ) ;
V_45 -> V_45 . V_89 = F_49 ( ( 1 << V_90 ) |
( 1 << V_93 ) ) ;
V_45 -> V_95 = 0 ;
V_45 -> V_114 = 0 ;
V_45 -> V_98 = F_16 ( V_42 -> V_99 ) ;
V_78 = V_100 ;
V_45 -> V_104 = F_16 ( V_78 ) ;
V_113 = (struct V_44 * ) F_15 ( V_25 , 10 ) ;
V_113 -> V_34 = F_16 ( V_35 |
V_115 ) ;
V_113 -> V_48 = F_16 ( 0 ) ;
memcpy ( V_113 -> V_49 , V_8 , V_38 ) ;
V_25 -> V_64 = V_83 ;
F_50 ( V_25 , 0 ) ;
V_25 -> V_105 = V_106 ;
V_25 -> V_107 = V_108 ;
V_25 -> V_109 = F_51 ( V_110 ) ;
memset ( V_25 -> V_111 , 0 , sizeof( V_25 -> V_111 ) ) ;
F_52 ( V_25 ) ;
}
static void F_54 ( void * V_23 , T_1 * V_21 ,
struct V_1 * V_2 )
{
struct V_116 * V_117 = V_23 ;
if ( memcmp ( V_21 , V_117 -> V_8 , V_38 ) == 0 )
V_117 -> V_118 = true ;
}
static bool F_55 ( struct V_22 * V_23 ,
const T_1 * V_8 )
{
struct V_116 V_117 = {
. V_118 = false ,
} ;
if ( V_23 -> V_119 && memcmp ( V_8 , V_23 -> V_120 , V_38 ) == 0 )
return true ;
memcpy ( V_117 . V_8 , V_8 , V_38 ) ;
F_56 ( V_23 -> V_29 ,
V_60 ,
F_54 ,
& V_117 ) ;
return V_117 . V_118 ;
}
static bool F_57 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
switch ( V_23 -> V_43 ) {
case V_55 :
return true ;
case V_56 :
return false ;
case V_57 :
return true ;
case V_58 :
if ( V_23 -> V_61 &&
F_55 ( V_23 , V_25 -> V_23 + 4 ) ) {
V_23 -> V_61 = false ;
return true ;
}
return false ;
}
return true ;
}
static void F_58 ( struct V_68 * V_29 ,
struct V_24 * V_121 ,
int V_122 )
{
struct V_24 * V_25 ;
struct V_22 * V_23 = V_29 -> V_69 ;
struct V_44 * V_45 = (struct V_44 * ) V_121 -> V_23 ;
struct V_79 * V_80 = F_44 ( V_121 ) ;
void * V_123 ;
unsigned int V_124 = 0 ;
int V_125 ;
struct V_126 V_127 [ V_128 ] ;
if ( V_23 -> V_43 != V_55 )
V_45 -> V_34 |= F_16 ( V_37 ) ;
if ( F_59 ( & V_23 -> V_129 ) >= V_130 ) {
while ( F_59 ( & V_23 -> V_129 ) >= V_131 ) {
F_60 ( V_29 , F_61 ( & V_23 -> V_129 ) ) ;
V_23 -> V_132 ++ ;
}
}
V_25 = F_62 ( V_133 , V_84 ) ;
if ( V_25 == NULL )
goto V_134;
V_123 = F_63 ( V_25 , 0 , 0 , & V_135 , 0 ,
V_136 ) ;
if ( V_123 == NULL ) {
F_64 ( V_137 L_4 ) ;
goto V_134;
}
if ( F_65 ( V_25 , V_138 ,
V_38 , V_23 -> V_139 [ 1 ] . V_8 ) )
goto V_134;
if ( F_65 ( V_25 , V_140 , V_121 -> V_141 , V_121 -> V_23 ) )
goto V_134;
if ( V_80 -> V_78 & V_142 )
V_124 |= V_143 ;
if ( V_80 -> V_78 & V_144 )
V_124 |= V_145 ;
if ( F_66 ( V_25 , V_146 , V_124 ) )
goto V_134;
if ( F_66 ( V_25 , V_147 , V_23 -> V_148 -> V_99 ) )
goto V_134;
for ( V_125 = 0 ; V_125 < V_128 ; V_125 ++ ) {
V_127 [ V_125 ] . V_149 = V_80 -> V_150 . V_151 [ V_125 ] . V_149 ;
V_127 [ V_125 ] . V_152 = V_80 -> V_150 . V_151 [ V_125 ] . V_152 ;
}
if ( F_65 ( V_25 , V_153 ,
sizeof( struct V_126 ) * V_128 ,
V_127 ) )
goto V_134;
if ( F_67 ( V_25 , V_154 , ( unsigned long ) V_121 ) )
goto V_134;
F_68 ( V_25 , V_123 ) ;
F_69 ( & V_155 , V_25 , V_122 ) ;
F_70 ( & V_23 -> V_129 , V_121 ) ;
V_23 -> V_156 ++ ;
V_23 -> V_157 += V_121 -> V_141 ;
return;
V_134:
F_64 ( V_137 L_5 , V_31 ) ;
F_60 ( V_29 , V_121 ) ;
V_23 -> V_158 ++ ;
}
static bool F_71 ( struct V_76 * V_159 ,
struct V_76 * V_160 )
{
if ( ! V_159 || ! V_160 )
return false ;
return V_159 -> V_99 == V_160 -> V_99 ;
}
static void F_72 ( void * V_161 , T_1 * V_8 ,
struct V_1 * V_2 )
{
struct V_162 * V_23 = V_161 ;
if ( ! V_2 -> V_40 )
return;
if ( ! F_71 ( V_23 -> V_148 ,
F_19 ( V_2 -> V_40 ) -> V_41 . V_42 ) )
return;
V_23 -> V_163 = true ;
}
static void F_73 ( struct V_24 * V_25 )
{
#ifdef F_74
struct V_164 * V_165 ;
V_165 = ( void * ) F_48 ( V_25 , sizeof( * V_165 ) + 8 + 4 ) ;
V_165 -> V_166 [ 0 ] = F_74 [ 0 ] ;
V_165 -> V_166 [ 1 ] = F_74 [ 1 ] ;
V_165 -> V_166 [ 2 ] = F_74 [ 2 ] ;
V_165 -> V_167 = 127 ;
V_165 -> V_168 = F_75 ( 0 ) ;
V_165 -> V_141 = 8 ;
V_165 -> V_169 = 8 ;
V_165 -> V_114 = 4 ;
memcpy ( V_165 -> V_23 , L_6 , 8 ) ;
memset ( V_165 -> V_23 + 8 , 0 , 4 ) ;
F_76 ( V_25 ) -> V_170 |= V_171 ;
#endif
}
static bool F_77 ( struct V_68 * V_29 ,
struct V_24 * V_25 ,
struct V_76 * V_42 )
{
struct V_22 * V_23 = V_29 -> V_69 , * V_172 ;
bool V_173 = false ;
struct V_44 * V_45 = (struct V_44 * ) V_25 -> V_23 ;
struct V_79 * V_80 = F_44 ( V_25 ) ;
struct V_174 V_175 ;
T_2 V_66 ;
memset ( & V_175 , 0 , sizeof( V_175 ) ) ;
V_175 . V_170 |= V_176 ;
V_175 . V_177 = V_42 -> V_99 ;
V_175 . V_178 = V_42 -> V_178 ;
if ( V_80 -> V_179 . V_151 [ 0 ] . V_78 & V_180 ) {
V_175 . V_181 =
F_78 ( & V_80 -> V_179 . V_151 [ 0 ] ) ;
V_175 . V_182 =
F_79 ( & V_80 -> V_179 . V_151 [ 0 ] ) ;
V_175 . V_170 |= V_183 ;
} else {
V_175 . V_181 = V_80 -> V_179 . V_151 [ 0 ] . V_149 ;
if ( V_80 -> V_179 . V_151 [ 0 ] . V_78 & V_184 )
V_175 . V_170 |= V_185 ;
}
if ( V_80 -> V_179 . V_151 [ 0 ] . V_78 & V_186 )
V_175 . V_170 |= V_187 ;
if ( V_80 -> V_179 . V_151 [ 0 ] . V_78 & V_188 )
V_175 . V_170 |= V_189 ;
V_175 . signal = V_23 -> V_190 - 50 ;
if ( V_23 -> V_43 != V_55 )
V_45 -> V_34 |= F_16 ( V_37 ) ;
F_80 ( V_25 ) ;
F_81 ( V_25 ) ;
V_25 -> V_191 = 0 ;
F_82 ( V_25 ) ;
F_83 ( V_25 ) ;
if ( F_84 ( V_45 -> V_34 ) ||
F_85 ( V_45 -> V_34 ) )
V_66 = V_23 -> V_192 ;
else
V_66 = F_33 () ;
F_86 ( & V_193 ) ;
F_87 (data2, &hwsim_radios, list) {
struct V_24 * V_194 ;
struct V_162 V_162 = {
. V_163 = false ,
. V_148 = V_42 ,
} ;
if ( V_23 == V_172 )
continue;
if ( ! V_172 -> V_195 || ( V_172 -> V_196 && ! V_172 -> V_197 ) ||
! F_57 ( V_172 , V_25 ) )
continue;
if ( ! ( V_23 -> V_62 & V_172 -> V_62 ) )
continue;
if ( ! F_71 ( V_42 , V_172 -> V_197 ) &&
! F_71 ( V_42 , V_172 -> V_148 ) ) {
F_56 (
V_172 -> V_29 , V_60 ,
F_72 , & V_162 ) ;
if ( ! V_162 . V_163 )
continue;
}
if ( V_25 -> V_141 < V_198 && V_199 ) {
struct V_200 * V_200 = F_88 ( V_84 ) ;
if ( ! V_200 )
continue;
V_194 = F_14 ( 128 ) ;
if ( ! V_194 ) {
F_89 ( V_200 ) ;
continue;
}
memcpy ( F_90 ( V_200 ) , V_25 -> V_23 , V_25 -> V_141 ) ;
F_91 ( V_194 , 0 , V_200 , 0 , V_25 -> V_141 , V_25 -> V_141 ) ;
} else {
V_194 = F_92 ( V_25 , V_84 ) ;
if ( ! V_194 )
continue;
}
if ( F_55 ( V_172 , V_45 -> V_49 ) )
V_173 = true ;
V_175 . V_201 = V_66 + V_172 -> V_67 ;
memcpy ( F_76 ( V_194 ) , & V_175 , sizeof( V_175 ) ) ;
F_73 ( V_194 ) ;
V_172 -> V_202 ++ ;
V_172 -> V_203 += V_194 -> V_141 ;
F_93 ( V_172 -> V_29 , V_194 ) ;
}
F_94 ( & V_193 ) ;
return V_173 ;
}
static void F_95 ( struct V_68 * V_29 ,
struct V_204 * V_179 ,
struct V_24 * V_25 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
struct V_79 * V_205 = F_44 ( V_25 ) ;
struct V_15 * V_40 ;
struct V_76 * V_148 ;
bool V_173 ;
T_5 V_206 ;
if ( F_6 ( V_25 -> V_141 < 10 ) ) {
F_60 ( V_29 , V_25 ) ;
return;
}
if ( ! V_23 -> V_207 ) {
V_148 = V_23 -> V_148 ;
} else if ( V_205 -> V_208 == 4 ) {
V_148 = V_23 -> V_197 ;
} else {
V_40 = F_19 ( V_205 -> V_179 . V_2 -> V_40 ) ;
if ( V_40 )
V_148 = V_40 -> V_41 . V_42 ;
else
V_148 = NULL ;
}
if ( F_2 ( ! V_148 , L_7 , V_205 -> V_208 ) ) {
F_60 ( V_29 , V_25 ) ;
return;
}
if ( V_23 -> V_196 && ! V_23 -> V_197 ) {
F_13 ( V_29 -> V_30 , L_8 ) ;
F_60 ( V_29 , V_25 ) ;
return;
}
if ( V_205 -> V_179 . V_2 )
F_1 ( V_205 -> V_179 . V_2 ) ;
if ( V_179 -> V_11 )
F_5 ( V_179 -> V_11 ) ;
if ( V_29 -> V_78 & V_209 )
F_96 ( V_205 -> V_179 . V_2 , V_179 -> V_11 , V_25 ,
V_205 -> V_179 . V_151 ,
F_97 ( V_205 -> V_179 . V_151 ) ) ;
V_205 -> V_210 [ 0 ] = V_148 ;
F_43 ( V_29 , V_25 , V_148 ) ;
V_206 = F_98 ( V_211 ) ;
if ( V_206 )
return F_58 ( V_29 , V_25 , V_206 ) ;
V_23 -> V_156 ++ ;
V_23 -> V_157 += V_25 -> V_141 ;
V_173 = F_77 ( V_29 , V_25 , V_148 ) ;
if ( V_173 && V_25 -> V_141 >= 16 ) {
struct V_44 * V_45 = (struct V_44 * ) V_25 -> V_23 ;
F_53 ( V_148 , V_45 -> V_50 ) ;
}
F_99 ( V_205 ) ;
V_205 -> V_179 . V_151 [ 0 ] . V_152 = 1 ;
V_205 -> V_179 . V_151 [ 1 ] . V_149 = - 1 ;
if ( ! ( V_205 -> V_78 & V_144 ) && V_173 )
V_205 -> V_78 |= V_212 ;
F_100 ( V_29 , V_25 ) ;
}
static int F_101 ( struct V_68 * V_29 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
F_13 ( V_29 -> V_30 , L_9 , V_31 ) ;
V_23 -> V_195 = true ;
return 0 ;
}
static void F_102 ( struct V_68 * V_29 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
V_23 -> V_195 = false ;
F_103 ( & V_23 -> V_213 ) ;
F_13 ( V_29 -> V_30 , L_9 , V_31 ) ;
}
static int F_104 ( struct V_68 * V_29 ,
struct V_1 * V_2 )
{
F_13 ( V_29 -> V_30 , L_10 ,
V_31 , F_105 ( V_2 ) ,
V_2 -> V_8 ) ;
F_3 ( V_2 ) ;
V_2 -> V_214 = 0 ;
V_2 -> V_208 [ V_215 ] = 0 ;
V_2 -> V_208 [ V_216 ] = 1 ;
V_2 -> V_208 [ V_217 ] = 2 ;
V_2 -> V_208 [ V_218 ] = 3 ;
return 0 ;
}
static int F_106 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
enum V_219 V_220 ,
bool V_221 )
{
V_220 = F_107 ( V_220 , V_221 ) ;
F_13 ( V_29 -> V_30 ,
L_11 ,
V_31 , F_105 ( V_2 ) ,
V_220 , V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
V_2 -> V_214 = 0 ;
return 0 ;
}
static void F_108 (
struct V_68 * V_29 , struct V_1 * V_2 )
{
F_13 ( V_29 -> V_30 , L_10 ,
V_31 , F_105 ( V_2 ) ,
V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
}
static void F_18 ( struct V_68 * V_29 ,
struct V_24 * V_25 ,
struct V_76 * V_42 )
{
T_5 V_222 = F_98 ( V_211 ) ;
if ( V_29 -> V_78 & V_209 ) {
struct V_79 * V_205 = F_44 ( V_25 ) ;
F_96 ( V_205 -> V_179 . V_2 , NULL , V_25 ,
V_205 -> V_179 . V_151 ,
F_97 ( V_205 -> V_179 . V_151 ) ) ;
}
F_43 ( V_29 , V_25 , V_42 ) ;
if ( V_222 )
return F_58 ( V_29 , V_25 , V_222 ) ;
F_77 ( V_29 , V_25 , V_42 ) ;
F_32 ( V_25 ) ;
}
static void F_109 ( void * V_223 , T_1 * V_21 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = V_223 ;
struct V_68 * V_29 = V_23 -> V_29 ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
struct V_224 * V_225 ;
struct V_24 * V_25 ;
F_1 ( V_2 ) ;
if ( V_2 -> type != V_226 &&
V_2 -> type != V_227 &&
V_2 -> type != V_228 )
return;
V_25 = F_110 ( V_29 , V_2 ) ;
if ( V_25 == NULL )
return;
V_80 = F_44 ( V_25 ) ;
if ( V_29 -> V_78 & V_209 )
F_96 ( V_2 , NULL , V_25 ,
V_80 -> V_179 . V_151 ,
F_97 ( V_80 -> V_179 . V_151 ) ) ;
V_82 = F_45 ( V_29 , V_80 ) ;
V_225 = (struct V_224 * ) V_25 -> V_23 ;
V_23 -> V_192 = F_33 () ;
V_225 -> V_229 . V_230 . V_231 = F_37 ( V_23 -> V_192 +
V_23 -> V_67 +
24 * 8 * 10 / V_82 -> V_97 ) ;
F_18 ( V_29 , V_25 ,
F_19 ( V_2 -> V_40 ) -> V_41 . V_42 ) ;
if ( V_2 -> V_232 && F_111 ( V_2 ) )
F_112 ( V_2 ) ;
}
static enum V_233
F_113 ( struct V_234 * V_235 )
{
struct V_22 * V_23 =
F_114 ( V_235 , struct V_22 ,
V_213 . V_235 ) ;
struct V_68 * V_29 = V_23 -> V_29 ;
T_2 V_71 = V_23 -> V_72 ;
T_7 V_236 ;
if ( ! V_23 -> V_195 )
goto V_237;
F_56 (
V_29 , V_60 ,
F_109 , V_23 ) ;
if ( V_23 -> V_74 ) {
V_71 -= V_23 -> V_74 ;
V_23 -> V_74 = 0 ;
}
V_236 = F_115 ( F_116 ( V_235 ) ,
F_117 ( V_71 * 1000 ) ) ;
F_118 ( & V_23 -> V_213 , V_236 , V_238 ) ;
V_237:
return V_239 ;
}
static int F_119 ( struct V_68 * V_29 , T_5 V_240 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
struct V_241 * V_242 = & V_29 -> V_242 ;
static const char * V_243 [ V_244 ] = {
[ V_245 ] = L_12 ,
[ V_246 ] = L_13 ,
[ V_247 ] = L_14 ,
[ V_248 ] = L_15 ,
} ;
if ( V_242 -> V_249 . V_42 )
F_13 ( V_29 -> V_30 ,
L_16 ,
V_31 ,
V_242 -> V_249 . V_42 -> V_99 ,
V_242 -> V_249 . V_250 ,
V_242 -> V_249 . V_251 ,
V_252 [ V_242 -> V_249 . V_253 ] ,
! ! ( V_242 -> V_78 & V_254 ) ,
! ! ( V_242 -> V_78 & V_255 ) ,
V_243 [ V_242 -> V_256 ] ) ;
else
F_13 ( V_29 -> V_30 ,
L_17 ,
V_31 ,
! ! ( V_242 -> V_78 & V_254 ) ,
! ! ( V_242 -> V_78 & V_255 ) ,
V_243 [ V_242 -> V_256 ] ) ;
V_23 -> V_196 = ! ! ( V_242 -> V_78 & V_254 ) ;
V_23 -> V_148 = V_242 -> V_249 . V_42 ;
F_6 ( V_23 -> V_148 && V_23 -> V_207 ) ;
V_23 -> V_190 = V_242 -> V_190 ;
if ( ! V_23 -> V_195 || ! V_23 -> V_72 )
F_103 ( & V_23 -> V_213 ) ;
else if ( ! F_120 ( & V_23 -> V_213 . V_235 ) ) {
T_2 V_70 = F_38 ( V_29 , NULL ) ;
T_5 V_71 = V_23 -> V_72 ;
T_2 V_257 = V_71 - F_42 ( V_70 , V_71 ) ;
F_118 ( & V_23 -> V_213 ,
F_117 ( V_257 * 1000 ) ,
V_258 ) ;
}
return 0 ;
}
static void F_121 ( struct V_68 * V_29 ,
unsigned int V_259 ,
unsigned int * V_260 , T_2 V_261 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
F_13 ( V_29 -> V_30 , L_9 , V_31 ) ;
V_23 -> V_262 = 0 ;
if ( * V_260 & V_263 )
V_23 -> V_262 |= V_263 ;
if ( * V_260 & V_264 )
V_23 -> V_262 |= V_264 ;
* V_260 = V_23 -> V_262 ;
}
static void F_122 ( void * V_23 , T_1 * V_21 ,
struct V_1 * V_2 )
{
unsigned int * V_152 = V_23 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
if ( V_4 -> V_265 )
( * V_152 ) ++ ;
}
static void F_123 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_266 * V_80 ,
T_5 V_240 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_22 * V_23 = V_29 -> V_69 ;
F_1 ( V_2 ) ;
F_13 ( V_29 -> V_30 , L_18 ,
V_31 , V_240 , V_2 -> V_8 ) ;
if ( V_240 & V_267 ) {
F_13 ( V_29 -> V_30 , L_19 ,
V_31 , V_80 -> V_32 ) ;
memcpy ( V_4 -> V_32 , V_80 -> V_32 , V_38 ) ;
}
if ( V_240 & V_268 ) {
F_13 ( V_29 -> V_30 , L_20 ,
V_80 -> V_28 , V_80 -> V_33 ) ;
V_4 -> V_28 = V_80 -> V_28 ;
V_4 -> V_33 = V_80 -> V_33 ;
}
if ( V_240 & V_269 ) {
F_13 ( V_29 -> V_30 , L_21 , V_80 -> V_72 ) ;
V_23 -> V_72 = V_80 -> V_72 * 1024 ;
}
if ( V_240 & V_270 ) {
F_13 ( V_29 -> V_30 , L_22 , V_80 -> V_271 ) ;
V_4 -> V_265 = V_80 -> V_271 ;
if ( V_23 -> V_195 &&
! F_120 ( & V_23 -> V_213 . V_235 ) &&
V_80 -> V_271 ) {
T_2 V_70 , V_257 ;
T_5 V_71 ;
if ( F_6 ( ! V_23 -> V_72 ) )
V_23 -> V_72 = 1000 * 1024 ;
V_70 = F_38 ( V_29 , V_2 ) ;
V_71 = V_23 -> V_72 ;
V_257 = V_71 - F_42 ( V_70 , V_71 ) ;
F_118 ( & V_23 -> V_213 ,
F_117 ( V_257 * 1000 ) ,
V_258 ) ;
} else if ( ! V_80 -> V_271 ) {
unsigned int V_152 = 0 ;
F_56 (
V_23 -> V_29 , V_60 ,
F_122 , & V_152 ) ;
F_13 ( V_29 -> V_30 , L_23 ,
V_152 ) ;
if ( V_152 == 0 )
F_103 ( & V_23 -> V_213 ) ;
}
}
if ( V_240 & V_272 ) {
F_13 ( V_29 -> V_30 , L_24 ,
V_80 -> V_273 ) ;
}
if ( V_240 & V_274 ) {
F_13 ( V_29 -> V_30 , L_25 ,
V_80 -> V_275 ) ;
}
if ( V_240 & V_276 ) {
F_13 ( V_29 -> V_30 , L_26 , V_80 -> V_277 ) ;
}
if ( V_240 & V_278 ) {
F_13 ( V_29 -> V_30 , L_27 ,
V_80 -> V_279 ) ;
}
if ( V_240 & V_280 ) {
F_13 ( V_29 -> V_30 , L_28 ,
( unsigned long long ) V_80 -> V_281 ) ;
}
if ( V_240 & V_282 )
F_13 ( V_29 -> V_30 , L_29 , V_80 -> V_283 ) ;
}
static int F_124 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_7 ( V_11 ) ;
return 0 ;
}
static int F_125 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static void F_126 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
enum V_284 V_285 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
switch ( V_285 ) {
case V_286 :
case V_287 :
break;
default:
F_2 ( 1 , L_30 , V_285 ) ;
break;
}
}
static int F_127 ( struct V_68 * V_29 ,
struct V_10 * V_11 ,
bool V_288 )
{
F_5 ( V_11 ) ;
return 0 ;
}
static int F_128 (
struct V_68 * V_29 ,
struct V_1 * V_2 , T_6 V_289 ,
const struct V_290 * V_291 )
{
F_13 ( V_29 -> V_30 ,
L_31 ,
V_31 , V_289 ,
V_291 -> V_292 , V_291 -> V_293 ,
V_291 -> V_294 , V_291 -> V_295 ) ;
return 0 ;
}
static int F_129 (
struct V_68 * V_29 , int V_149 ,
struct V_296 * V_297 )
{
struct V_241 * V_242 = & V_29 -> V_242 ;
F_13 ( V_29 -> V_30 , L_32 , V_31 , V_149 ) ;
if ( V_149 != 0 )
return - V_298 ;
V_297 -> V_148 = V_242 -> V_249 . V_42 ;
V_297 -> V_299 = V_300 ;
V_297 -> V_301 = - 92 ;
return 0 ;
}
static int F_130 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
void * V_23 , int V_141 )
{
struct V_22 * V_302 = V_29 -> V_69 ;
struct V_303 * V_304 [ V_305 + 1 ] ;
struct V_24 * V_25 ;
int V_306 , V_43 ;
V_306 = F_131 ( V_304 , V_305 , V_23 , V_141 ,
V_307 ) ;
if ( V_306 )
return V_306 ;
if ( ! V_304 [ V_308 ] )
return - V_59 ;
switch ( F_132 ( V_304 [ V_308 ] ) ) {
case V_309 :
if ( ! V_304 [ V_310 ] )
return - V_59 ;
V_43 = F_132 ( V_304 [ V_310 ] ) ;
return F_25 ( V_302 , V_43 ) ;
case V_311 :
V_25 = F_133 ( V_29 -> V_30 ,
F_134 ( sizeof( T_5 ) ) ) ;
if ( ! V_25 )
return - V_312 ;
if ( F_66 ( V_25 , V_310 , V_302 -> V_43 ) )
goto V_134;
return F_135 ( V_25 ) ;
case V_313 :
F_136 ( V_29 ) ;
return 0 ;
case V_314 :
F_137 ( V_29 ) ;
return 0 ;
default:
return - V_315 ;
}
V_134:
F_138 ( V_25 ) ;
return - V_316 ;
}
static int F_139 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
enum V_317 V_318 ,
struct V_10 * V_11 , T_6 V_319 , T_6 * V_320 ,
T_1 V_321 )
{
switch ( V_318 ) {
case V_322 :
F_140 ( V_2 , V_11 -> V_8 , V_319 ) ;
break;
case V_323 :
case V_324 :
case V_325 :
F_141 ( V_2 , V_11 -> V_8 , V_319 ) ;
break;
case V_326 :
break;
case V_327 :
case V_328 :
break;
default:
return - V_315 ;
}
return 0 ;
}
static void F_142 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
T_5 V_329 , bool V_330 )
{
}
static void F_143 ( struct V_331 * V_332 )
{
struct V_22 * V_302 =
F_114 ( V_332 , struct V_22 , V_333 . V_332 ) ;
struct V_334 * V_335 = V_302 -> V_336 ;
int V_337 , V_125 ;
F_144 ( & V_302 -> V_338 ) ;
if ( V_302 -> V_339 >= V_335 -> V_340 ) {
F_13 ( V_302 -> V_29 -> V_30 , L_33 ) ;
F_145 ( V_302 -> V_29 , false ) ;
V_302 -> V_336 = NULL ;
V_302 -> V_341 = NULL ;
V_302 -> V_197 = NULL ;
F_146 ( & V_302 -> V_338 ) ;
return;
}
F_13 ( V_302 -> V_29 -> V_30 , L_34 ,
V_335 -> V_342 [ V_302 -> V_339 ] -> V_99 ) ;
V_302 -> V_197 = V_335 -> V_342 [ V_302 -> V_339 ] ;
if ( V_302 -> V_197 -> V_78 & V_343 ||
! V_335 -> V_344 ) {
V_337 = 120 ;
} else {
V_337 = 30 ;
for ( V_125 = 0 ; V_125 < V_335 -> V_344 ; V_125 ++ ) {
struct V_24 * V_345 ;
V_345 = F_147 ( V_302 -> V_29 ,
V_302 -> V_120 ,
V_335 -> V_346 [ V_125 ] . V_347 ,
V_335 -> V_346 [ V_125 ] . V_348 ,
V_335 -> V_349 ) ;
if ( ! V_345 )
continue;
if ( V_335 -> V_349 )
memcpy ( F_15 ( V_345 , V_335 -> V_349 ) , V_335 -> V_350 ,
V_335 -> V_349 ) ;
F_148 () ;
F_18 ( V_302 -> V_29 , V_345 ,
V_302 -> V_197 ) ;
F_149 () ;
}
}
F_150 ( V_302 -> V_29 , & V_302 -> V_333 ,
F_151 ( V_337 ) ) ;
V_302 -> V_339 ++ ;
F_146 ( & V_302 -> V_338 ) ;
}
static int F_152 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_351 * V_352 )
{
struct V_22 * V_302 = V_29 -> V_69 ;
struct V_334 * V_335 = & V_352 -> V_335 ;
F_144 ( & V_302 -> V_338 ) ;
if ( F_6 ( V_302 -> V_197 || V_302 -> V_336 ) ) {
F_146 ( & V_302 -> V_338 ) ;
return - V_353 ;
}
V_302 -> V_336 = V_335 ;
V_302 -> V_341 = V_2 ;
V_302 -> V_339 = 0 ;
if ( V_335 -> V_78 & V_354 )
F_153 ( V_302 -> V_120 ,
V_352 -> V_335 . V_355 ,
V_352 -> V_335 . V_356 ) ;
else
memcpy ( V_302 -> V_120 , V_2 -> V_8 , V_38 ) ;
F_146 ( & V_302 -> V_338 ) ;
F_13 ( V_29 -> V_30 , L_35 ) ;
F_150 ( V_302 -> V_29 , & V_302 -> V_333 , 0 ) ;
return 0 ;
}
static void F_154 ( struct V_68 * V_29 ,
struct V_1 * V_2 )
{
struct V_22 * V_302 = V_29 -> V_69 ;
F_13 ( V_29 -> V_30 , L_36 ) ;
F_155 ( & V_302 -> V_333 ) ;
F_144 ( & V_302 -> V_338 ) ;
F_145 ( V_302 -> V_29 , true ) ;
V_302 -> V_197 = NULL ;
V_302 -> V_336 = NULL ;
V_302 -> V_341 = NULL ;
F_146 ( & V_302 -> V_338 ) ;
}
static void F_156 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
const T_1 * V_355 )
{
struct V_22 * V_302 = V_29 -> V_69 ;
F_144 ( & V_302 -> V_338 ) ;
if ( V_302 -> V_119 ) {
F_64 ( V_137 L_37 ) ;
goto V_237;
}
F_64 ( V_137 L_38 ) ;
memcpy ( V_302 -> V_120 , V_355 , V_38 ) ;
V_302 -> V_119 = true ;
V_237:
F_146 ( & V_302 -> V_338 ) ;
}
static void F_157 ( struct V_68 * V_29 ,
struct V_1 * V_2 )
{
struct V_22 * V_302 = V_29 -> V_69 ;
F_144 ( & V_302 -> V_338 ) ;
F_64 ( V_137 L_39 ) ;
V_302 -> V_119 = false ;
memset ( V_302 -> V_120 , 0 , V_38 ) ;
F_146 ( & V_302 -> V_338 ) ;
}
static void F_158 ( struct V_331 * V_332 )
{
struct V_22 * V_302 =
F_114 ( V_332 , struct V_22 , V_357 . V_332 ) ;
F_144 ( & V_302 -> V_338 ) ;
F_159 ( V_302 -> V_29 ) ;
V_302 -> V_197 = NULL ;
F_146 ( & V_302 -> V_338 ) ;
F_13 ( V_302 -> V_29 -> V_30 , L_40 ) ;
}
static int F_160 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_76 * V_42 ,
int V_358 ,
enum V_359 type )
{
struct V_22 * V_302 = V_29 -> V_69 ;
F_144 ( & V_302 -> V_338 ) ;
if ( F_6 ( V_302 -> V_197 || V_302 -> V_336 ) ) {
F_146 ( & V_302 -> V_338 ) ;
return - V_353 ;
}
V_302 -> V_197 = V_42 ;
F_146 ( & V_302 -> V_338 ) ;
F_13 ( V_29 -> V_30 , L_41 ,
V_42 -> V_99 , V_358 ) ;
F_161 ( V_29 ) ;
F_150 ( V_29 , & V_302 -> V_357 ,
F_151 ( V_358 ) ) ;
return 0 ;
}
static int F_162 ( struct V_68 * V_29 )
{
struct V_22 * V_302 = V_29 -> V_69 ;
F_155 ( & V_302 -> V_357 ) ;
F_144 ( & V_302 -> V_338 ) ;
V_302 -> V_197 = NULL ;
F_146 ( & V_302 -> V_338 ) ;
F_13 ( V_29 -> V_30 , L_42 ) ;
return 0 ;
}
static int F_163 ( struct V_68 * V_29 ,
struct V_15 * V_360 )
{
F_10 ( V_360 ) ;
F_13 ( V_29 -> V_30 ,
L_43 ,
V_360 -> V_41 . V_42 -> V_99 , V_360 -> V_41 . V_253 ,
V_360 -> V_41 . V_250 , V_360 -> V_41 . V_251 ) ;
return 0 ;
}
static void F_164 ( struct V_68 * V_29 ,
struct V_15 * V_360 )
{
F_13 ( V_29 -> V_30 ,
L_44 ,
V_360 -> V_41 . V_42 -> V_99 , V_360 -> V_41 . V_253 ,
V_360 -> V_41 . V_250 , V_360 -> V_41 . V_251 ) ;
F_9 ( V_360 ) ;
F_11 ( V_360 ) ;
}
static void F_165 ( struct V_68 * V_29 ,
struct V_15 * V_360 ,
T_5 V_240 )
{
F_9 ( V_360 ) ;
F_13 ( V_29 -> V_30 ,
L_45 ,
V_360 -> V_41 . V_42 -> V_99 , V_360 -> V_41 . V_253 ,
V_360 -> V_41 . V_250 , V_360 -> V_41 . V_251 ) ;
}
static int F_166 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_15 * V_360 )
{
F_1 ( V_2 ) ;
F_9 ( V_360 ) ;
return 0 ;
}
static void F_167 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_15 * V_360 )
{
F_1 ( V_2 ) ;
F_9 ( V_360 ) ;
}
static void F_168 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
T_5 V_361 , T_1 * V_23 )
{
if ( V_361 == V_362 )
memcpy ( V_23 , * V_363 ,
sizeof( V_363 ) ) ;
}
static int F_169 ( struct V_68 * V_29 ,
struct V_1 * V_2 , int V_361 )
{
if ( V_361 == V_362 )
return V_364 ;
return 0 ;
}
static void F_170 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_365 * V_366 , T_2 * V_23 )
{
struct V_22 * V_367 = V_29 -> V_69 ;
int V_125 = 0 ;
V_23 [ V_125 ++ ] = V_367 -> V_156 ;
V_23 [ V_125 ++ ] = V_367 -> V_157 ;
V_23 [ V_125 ++ ] = V_367 -> V_202 ;
V_23 [ V_125 ++ ] = V_367 -> V_203 ;
V_23 [ V_125 ++ ] = V_367 -> V_132 ;
V_23 [ V_125 ++ ] = V_367 -> V_158 ;
V_23 [ V_125 ++ ] = V_367 -> V_43 ;
V_23 [ V_125 ++ ] = V_367 -> V_62 ;
V_23 [ V_125 ++ ] = V_367 -> V_190 ;
F_6 ( V_125 != V_364 ) ;
}
static void F_171 ( struct V_24 * V_368 ,
struct V_369 * V_80 )
{
if ( V_80 )
F_172 ( & V_135 , V_368 ,
F_173 ( V_80 ) , V_80 -> V_370 ,
V_371 , V_80 -> V_372 , V_373 ) ;
else
F_174 ( & V_135 , V_368 , 0 ,
V_371 , V_373 ) ;
}
static int F_175 ( struct V_24 * V_25 , int V_374 ,
struct V_375 * V_376 )
{
int V_118 ;
V_118 = F_66 ( V_25 , V_377 , V_374 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( V_376 -> V_342 ) {
V_118 = F_66 ( V_25 , V_378 , V_376 -> V_342 ) ;
if ( V_118 < 0 )
return V_118 ;
}
if ( V_376 -> V_379 ) {
V_118 = F_65 ( V_25 , V_380 , 2 ,
V_376 -> V_379 ) ;
if ( V_118 < 0 )
return V_118 ;
}
if ( V_376 -> V_381 ) {
int V_125 ;
for ( V_125 = 0 ; V_382 [ V_125 ] != V_376 -> V_381 &&
V_125 < F_97 ( V_382 ) ; V_125 ++ )
;
if ( V_125 < F_97 ( V_382 ) ) {
V_118 = F_66 ( V_25 , V_383 , V_125 ) ;
if ( V_118 < 0 )
return V_118 ;
}
}
if ( V_376 -> V_384 ) {
V_118 = F_176 ( V_25 , V_385 ) ;
if ( V_118 < 0 )
return V_118 ;
}
if ( V_376 -> V_386 ) {
V_118 = F_176 ( V_25 , V_387 ) ;
if ( V_118 < 0 )
return V_118 ;
}
if ( V_376 -> V_207 ) {
V_118 = F_176 ( V_25 , V_388 ) ;
if ( V_118 < 0 )
return V_118 ;
}
if ( V_376 -> V_389 ) {
V_118 = F_65 ( V_25 , V_390 ,
strlen ( V_376 -> V_389 ) , V_376 -> V_389 ) ;
if ( V_118 < 0 )
return V_118 ;
}
return 0 ;
}
static void F_177 ( int V_374 , struct V_369 * V_80 ,
struct V_375 * V_376 )
{
struct V_24 * V_368 ;
void * V_23 ;
V_368 = F_62 ( V_133 , V_373 ) ;
if ( ! V_368 )
return;
V_23 = F_63 ( V_368 , 0 , 0 , & V_135 , 0 ,
V_391 ) ;
if ( ! V_23 )
goto V_392;
if ( F_175 ( V_368 , V_374 , V_376 ) < 0 )
goto V_392;
F_68 ( V_368 , V_23 ) ;
F_171 ( V_368 , V_80 ) ;
return;
V_392:
F_178 ( V_368 , V_23 ) ;
F_179 ( V_368 ) ;
}
static int F_180 ( struct V_369 * V_80 ,
struct V_375 * V_376 )
{
int V_306 ;
T_1 V_8 [ V_38 ] ;
struct V_22 * V_23 ;
struct V_68 * V_29 ;
enum V_393 V_178 ;
const struct V_394 * V_395 = & V_396 ;
int V_149 ;
if ( F_6 ( V_376 -> V_342 > 1 && ! V_376 -> V_207 ) )
return - V_59 ;
F_181 ( & V_193 ) ;
V_149 = V_397 ++ ;
F_182 ( & V_193 ) ;
if ( V_376 -> V_207 )
V_395 = & V_398 ;
V_29 = F_183 ( sizeof( * V_23 ) , V_395 , V_376 -> V_389 ) ;
if ( ! V_29 ) {
F_64 ( V_137 L_46 ) ;
V_306 = - V_312 ;
goto V_399;
}
V_23 = V_29 -> V_69 ;
V_23 -> V_29 = V_29 ;
V_23 -> V_64 = F_184 ( V_400 , NULL , 0 , V_29 , L_47 , V_149 ) ;
if ( F_185 ( V_23 -> V_64 ) ) {
F_64 ( V_137
L_48 ,
F_186 ( V_23 -> V_64 ) ) ;
V_306 = - V_312 ;
goto V_401;
}
V_23 -> V_64 -> V_402 = & V_403 . V_402 ;
V_306 = F_187 ( V_23 -> V_64 ) ;
if ( V_306 != 0 ) {
F_64 ( V_137 L_49 ,
V_306 ) ;
goto V_404;
}
F_188 ( & V_23 -> V_129 ) ;
F_189 ( V_29 , V_23 -> V_64 ) ;
memset ( V_8 , 0 , V_38 ) ;
V_8 [ 0 ] = 0x02 ;
V_8 [ 3 ] = V_149 >> 8 ;
V_8 [ 4 ] = V_149 ;
memcpy ( V_23 -> V_139 [ 0 ] . V_8 , V_8 , V_38 ) ;
memcpy ( V_23 -> V_139 [ 1 ] . V_8 , V_8 , V_38 ) ;
V_23 -> V_139 [ 1 ] . V_8 [ 0 ] |= 0x40 ;
V_29 -> V_30 -> V_405 = 2 ;
V_29 -> V_30 -> V_139 = V_23 -> V_139 ;
V_23 -> V_342 = V_376 -> V_342 ;
V_23 -> V_207 = V_376 -> V_207 ;
V_23 -> V_149 = V_149 ;
V_23 -> V_406 = V_376 -> V_406 ;
if ( V_80 )
V_23 -> V_407 = V_80 -> V_370 ;
if ( V_23 -> V_207 ) {
V_29 -> V_30 -> V_408 = 255 ;
V_29 -> V_30 -> V_409 = V_410 ;
V_29 -> V_30 -> V_411 = 1000 ;
V_29 -> V_30 -> V_412 = 1 ;
V_29 -> V_30 -> V_413 = & V_23 -> V_414 ;
if ( V_376 -> V_386 )
V_23 -> V_414 = V_415 [ 0 ] ;
else
V_23 -> V_414 = V_416 [ 0 ] ;
V_23 -> V_414 . V_417 = V_23 -> V_342 ;
} else if ( V_376 -> V_386 ) {
V_29 -> V_30 -> V_413 = V_415 ;
V_29 -> V_30 -> V_412 =
F_97 ( V_415 ) ;
} else {
V_29 -> V_30 -> V_413 = V_416 ;
V_29 -> V_30 -> V_412 = F_97 ( V_416 ) ;
}
F_190 ( & V_23 -> V_357 , F_158 ) ;
F_190 ( & V_23 -> V_333 , F_143 ) ;
V_29 -> V_329 = 5 ;
V_29 -> V_418 = 4 ;
V_29 -> V_30 -> V_419 = F_75 ( V_420 ) |
F_75 ( V_226 ) |
F_75 ( V_421 ) |
F_75 ( V_422 ) |
F_75 ( V_228 ) |
F_75 ( V_227 ) ;
if ( V_376 -> V_386 )
V_29 -> V_30 -> V_419 |= F_75 ( V_423 ) ;
V_29 -> V_78 = V_424 |
V_425 |
V_426 |
V_427 |
V_428 |
V_429 |
V_430 ;
if ( V_431 )
V_29 -> V_78 |= V_209 ;
V_29 -> V_30 -> V_78 |= V_432 |
V_433 |
V_434 |
V_435 ;
V_29 -> V_30 -> V_436 |= V_437 |
V_438 |
V_439 |
V_440 |
V_441 ;
V_29 -> V_442 = sizeof( struct V_3 ) ;
V_29 -> V_443 = sizeof( struct V_12 ) ;
V_29 -> V_444 = sizeof( struct V_17 ) ;
memcpy ( V_23 -> V_445 , V_446 ,
sizeof( V_446 ) ) ;
memcpy ( V_23 -> V_447 , V_448 ,
sizeof( V_448 ) ) ;
memcpy ( V_23 -> V_151 , V_449 , sizeof( V_449 ) ) ;
for ( V_178 = V_450 ; V_178 < V_451 ; V_178 ++ ) {
struct V_452 * V_453 = & V_23 -> V_454 [ V_178 ] ;
switch ( V_178 ) {
case V_450 :
V_453 -> V_342 = V_23 -> V_445 ;
V_453 -> V_340 = F_97 ( V_446 ) ;
V_453 -> V_455 = V_23 -> V_151 ;
V_453 -> V_456 = F_97 ( V_449 ) ;
break;
case V_457 :
V_453 -> V_342 = V_23 -> V_447 ;
V_453 -> V_340 = F_97 ( V_448 ) ;
V_453 -> V_455 = V_23 -> V_151 + 4 ;
V_453 -> V_456 = F_97 ( V_449 ) - 4 ;
break;
default:
continue;
}
V_453 -> V_458 . V_459 = true ;
V_453 -> V_458 . V_460 = V_461 |
V_462 |
V_463 |
V_464 |
V_465 ;
V_453 -> V_458 . V_466 = 0x3 ;
V_453 -> V_458 . V_467 = 0x6 ;
memset ( & V_453 -> V_458 . V_468 , 0 ,
sizeof( V_453 -> V_458 . V_468 ) ) ;
V_453 -> V_458 . V_468 . V_469 [ 0 ] = 0xff ;
V_453 -> V_458 . V_468 . V_469 [ 1 ] = 0xff ;
V_453 -> V_458 . V_468 . V_470 = V_471 ;
V_29 -> V_30 -> V_454 [ V_178 ] = V_453 ;
V_453 -> V_472 . V_473 = true ;
V_453 -> V_472 . V_460 =
V_474 |
V_475 |
V_476 |
V_477 |
V_478 |
V_479 |
V_480 |
V_481 |
V_482 |
V_483 |
V_484 ;
V_453 -> V_472 . V_485 . V_486 =
F_16 ( V_487 << 0 |
V_487 << 2 |
V_488 << 4 |
V_487 << 6 |
V_487 << 8 |
V_488 << 10 |
V_488 << 12 |
V_487 << 14 ) ;
V_453 -> V_472 . V_485 . V_489 =
V_453 -> V_472 . V_485 . V_486 ;
}
V_23 -> V_62 = 1 ;
F_191 ( & V_23 -> V_338 ) ;
V_29 -> V_490 = 4 ;
V_29 -> V_491 = 11 ;
if ( V_376 -> V_384 )
V_29 -> V_30 -> V_492 |= V_493 ;
if ( V_376 -> V_381 ) {
V_23 -> V_381 = V_376 -> V_381 ;
V_29 -> V_30 -> V_492 |= V_494 ;
F_192 ( V_29 -> V_30 , V_376 -> V_381 ) ;
F_193 ( 1 ) ;
}
if ( V_376 -> V_495 )
V_29 -> V_78 |= V_496 ;
V_306 = F_194 ( V_29 ) ;
if ( V_306 < 0 ) {
F_64 ( V_137 L_50 ,
V_306 ) ;
goto V_497;
}
F_13 ( V_29 -> V_30 , L_51 , V_29 -> V_30 -> V_498 ) ;
if ( V_376 -> V_379 ) {
V_23 -> V_499 [ 0 ] = V_376 -> V_379 [ 0 ] ;
V_23 -> V_499 [ 1 ] = V_376 -> V_379 [ 1 ] ;
F_195 ( V_29 -> V_30 , V_376 -> V_379 ) ;
}
V_23 -> V_500 = F_196 ( L_52 , V_29 -> V_30 -> V_501 ) ;
F_197 ( L_53 , 0666 , V_23 -> V_500 , V_23 , & V_502 ) ;
F_197 ( L_54 , 0666 , V_23 -> V_500 , V_23 ,
& V_503 ) ;
if ( ! V_23 -> V_207 )
F_197 ( L_55 , 0222 ,
V_23 -> V_500 ,
V_23 , & V_504 ) ;
F_198 ( & V_23 -> V_213 ,
F_113 ,
V_505 , V_238 ) ;
F_181 ( & V_193 ) ;
F_199 ( & V_23 -> V_506 , & V_507 ) ;
F_182 ( & V_193 ) ;
if ( V_149 > 0 )
F_177 ( V_149 , V_80 , V_376 ) ;
return V_149 ;
V_497:
F_200 ( V_23 -> V_64 ) ;
V_404:
F_201 ( V_23 -> V_64 ) ;
V_401:
F_202 ( V_29 ) ;
V_399:
return V_306 ;
}
static void F_203 ( int V_374 , const char * V_389 ,
struct V_369 * V_80 )
{
struct V_24 * V_25 ;
void * V_23 ;
int V_118 ;
V_25 = F_62 ( V_133 , V_373 ) ;
if ( ! V_25 )
return;
V_23 = F_63 ( V_25 , 0 , 0 , & V_135 , 0 ,
V_508 ) ;
if ( ! V_23 )
goto error;
V_118 = F_66 ( V_25 , V_377 , V_374 ) ;
if ( V_118 < 0 )
goto error;
V_118 = F_65 ( V_25 , V_390 , strlen ( V_389 ) ,
V_389 ) ;
if ( V_118 < 0 )
goto error;
F_68 ( V_25 , V_23 ) ;
F_171 ( V_25 , V_80 ) ;
return;
error:
F_179 ( V_25 ) ;
}
static void F_204 ( struct V_22 * V_23 ,
const char * V_389 ,
struct V_369 * V_80 )
{
F_203 ( V_23 -> V_149 , V_389 , V_80 ) ;
F_205 ( V_23 -> V_500 ) ;
F_206 ( V_23 -> V_29 ) ;
F_200 ( V_23 -> V_64 ) ;
F_201 ( V_23 -> V_64 ) ;
F_202 ( V_23 -> V_29 ) ;
}
static int F_207 ( struct V_24 * V_25 ,
struct V_22 * V_23 ,
T_5 V_407 , T_5 V_509 ,
struct V_510 * V_111 , int V_78 )
{
void * V_45 ;
struct V_375 V_376 = { } ;
int V_511 = - V_512 ;
V_45 = F_63 ( V_25 , V_407 , V_509 , & V_135 , V_78 ,
V_513 ) ;
if ( ! V_45 )
return - V_512 ;
if ( V_111 )
F_208 ( V_111 , V_45 , & V_135 ) ;
if ( V_23 -> V_499 [ 0 ] && V_23 -> V_499 [ 1 ] )
V_376 . V_379 = V_23 -> V_499 ;
V_376 . V_384 = ! ! ( V_23 -> V_29 -> V_30 -> V_492 &
V_493 ) ;
V_376 . V_386 = ! ! ( V_23 -> V_29 -> V_30 -> V_419 &
F_75 ( V_423 ) ) ;
V_376 . V_207 = V_23 -> V_207 ;
V_376 . V_381 = V_23 -> V_381 ;
V_376 . V_342 = V_23 -> V_342 ;
V_376 . V_389 = F_209 ( V_23 -> V_29 -> V_30 ) ;
V_511 = F_175 ( V_25 , V_23 -> V_149 , & V_376 ) ;
if ( V_511 < 0 )
goto V_392;
return F_68 ( V_25 , V_45 ) ;
V_392:
F_178 ( V_25 , V_45 ) ;
return V_511 ;
}
static void F_210 ( void )
{
struct V_22 * V_23 ;
F_181 ( & V_193 ) ;
while ( ( V_23 = F_211 ( & V_507 ,
struct V_22 ,
V_506 ) ) ) {
F_212 ( & V_23 -> V_506 ) ;
F_182 ( & V_193 ) ;
F_204 ( V_23 , F_209 ( V_23 -> V_29 -> V_30 ) ,
NULL ) ;
F_181 ( & V_193 ) ;
}
F_182 ( & V_193 ) ;
F_213 ( V_400 ) ;
}
static void F_214 ( struct V_63 * V_64 )
{
V_64 -> V_514 = & V_515 ;
V_64 -> V_516 = V_517 ;
F_215 ( V_64 ) ;
V_64 -> V_518 = 0 ;
V_64 -> type = V_519 ;
memset ( V_64 -> V_520 , 0 , V_38 ) ;
V_64 -> V_520 [ 0 ] = 0x12 ;
}
static struct V_22 * F_216 ( const T_1 * V_8 )
{
struct V_22 * V_23 ;
bool V_521 = false ;
F_181 ( & V_193 ) ;
F_87 (data, &hwsim_radios, list) {
if ( memcmp ( V_23 -> V_139 [ 1 ] . V_8 , V_8 , V_38 ) == 0 ) {
V_521 = true ;
break;
}
}
F_182 ( & V_193 ) ;
if ( ! V_521 )
return NULL ;
return V_23 ;
}
static int F_217 ( struct V_24 * V_522 ,
struct V_369 * V_80 )
{
struct V_44 * V_45 ;
struct V_22 * V_172 ;
struct V_79 * V_205 ;
struct V_126 * V_127 ;
unsigned long V_523 ;
struct V_24 * V_25 , * V_524 ;
const T_1 * V_525 ;
unsigned int V_124 ;
int V_125 ;
bool V_526 = false ;
if ( V_80 -> V_370 != V_211 )
return - V_59 ;
if ( ! V_80 -> V_527 [ V_138 ] ||
! V_80 -> V_527 [ V_146 ] ||
! V_80 -> V_527 [ V_154 ] ||
! V_80 -> V_527 [ V_153 ] )
goto V_237;
V_525 = ( void * ) F_218 ( V_80 -> V_527 [ V_138 ] ) ;
V_124 = F_132 ( V_80 -> V_527 [ V_146 ] ) ;
V_523 = F_219 ( V_80 -> V_527 [ V_154 ] ) ;
V_172 = F_216 ( V_525 ) ;
if ( ! V_172 )
goto V_237;
F_220 (&data2->pending, skb, tmp) {
if ( ( unsigned long ) V_25 == V_523 ) {
F_221 ( V_25 , & V_172 -> V_129 ) ;
V_526 = true ;
break;
}
}
if ( ! V_526 )
goto V_237;
V_127 = (struct V_126 * ) F_218 (
V_80 -> V_527 [ V_153 ] ) ;
V_205 = F_44 ( V_25 ) ;
F_99 ( V_205 ) ;
for ( V_125 = 0 ; V_125 < V_128 ; V_125 ++ ) {
V_205 -> V_150 . V_151 [ V_125 ] . V_149 = V_127 [ V_125 ] . V_149 ;
V_205 -> V_150 . V_151 [ V_125 ] . V_152 = V_127 [ V_125 ] . V_152 ;
}
V_205 -> V_150 . V_528 = F_132 ( V_80 -> V_527 [ V_529 ] ) ;
if ( ! ( V_124 & V_145 ) &&
( V_124 & V_530 ) ) {
if ( V_25 -> V_141 >= 16 ) {
V_45 = (struct V_44 * ) V_25 -> V_23 ;
F_53 ( V_172 -> V_148 ,
V_45 -> V_50 ) ;
}
V_205 -> V_78 |= V_212 ;
}
F_100 ( V_172 -> V_29 , V_25 ) ;
return 0 ;
V_237:
return - V_59 ;
}
static int F_222 ( struct V_24 * V_522 ,
struct V_369 * V_80 )
{
struct V_22 * V_172 ;
struct V_174 V_175 ;
const T_1 * V_531 ;
int V_532 ;
void * V_533 ;
struct V_24 * V_25 = NULL ;
if ( V_80 -> V_370 != V_211 )
return - V_59 ;
if ( ! V_80 -> V_527 [ V_534 ] ||
! V_80 -> V_527 [ V_140 ] ||
! V_80 -> V_527 [ V_535 ] ||
! V_80 -> V_527 [ V_529 ] )
goto V_237;
V_531 = ( void * ) F_218 ( V_80 -> V_527 [ V_534 ] ) ;
V_532 = F_223 ( V_80 -> V_527 [ V_140 ] ) ;
V_533 = ( void * ) F_218 ( V_80 -> V_527 [ V_140 ] ) ;
V_25 = F_224 ( V_532 , V_373 ) ;
if ( V_25 == NULL )
goto V_306;
if ( V_532 > V_410 )
goto V_306;
memcpy ( F_15 ( V_25 , V_532 ) , V_533 , V_532 ) ;
V_172 = F_216 ( V_531 ) ;
if ( ! V_172 )
goto V_237;
if ( V_172 -> V_196 || ! V_172 -> V_195 )
goto V_237;
memset ( & V_175 , 0 , sizeof( V_175 ) ) ;
V_175 . V_177 = V_172 -> V_148 -> V_99 ;
V_175 . V_178 = V_172 -> V_148 -> V_178 ;
V_175 . V_181 = F_132 ( V_80 -> V_527 [ V_535 ] ) ;
V_175 . signal = F_132 ( V_80 -> V_527 [ V_529 ] ) ;
memcpy ( F_76 ( V_25 ) , & V_175 , sizeof( V_175 ) ) ;
V_172 -> V_202 ++ ;
V_172 -> V_203 += V_25 -> V_141 ;
F_93 ( V_172 -> V_29 , V_25 ) ;
return 0 ;
V_306:
F_64 ( V_137 L_5 , V_31 ) ;
V_237:
F_32 ( V_25 ) ;
return - V_59 ;
}
static int F_225 ( struct V_24 * V_522 ,
struct V_369 * V_80 )
{
struct V_22 * V_23 ;
int V_536 = 1 ;
F_181 ( & V_193 ) ;
F_87 (data, &hwsim_radios, list)
V_536 = F_226 ( V_536 , V_23 -> V_342 ) ;
F_182 ( & V_193 ) ;
if ( V_536 > 1 )
return - V_315 ;
if ( V_211 )
return - V_353 ;
V_211 = V_80 -> V_370 ;
F_64 ( V_137 L_56
L_57 , V_80 -> V_370 ) ;
return 0 ;
}
static int F_227 ( struct V_24 * V_537 , struct V_369 * V_80 )
{
struct V_375 V_376 = { 0 } ;
V_376 . V_384 = V_80 -> V_527 [ V_385 ] ;
V_376 . V_386 = V_80 -> V_527 [ V_387 ] ;
V_376 . V_342 = V_342 ;
V_376 . V_406 =
V_80 -> V_527 [ V_538 ] ;
if ( V_80 -> V_527 [ V_378 ] )
V_376 . V_342 = F_132 ( V_80 -> V_527 [ V_378 ] ) ;
if ( V_80 -> V_527 [ V_539 ] )
V_376 . V_495 = true ;
if ( V_80 -> V_527 [ V_390 ] )
V_376 . V_389 = F_218 ( V_80 -> V_527 [ V_390 ] ) ;
if ( V_80 -> V_527 [ V_388 ] )
V_376 . V_207 = true ;
else
V_376 . V_207 = ( V_376 . V_342 > 1 ) ;
if ( V_80 -> V_527 [ V_380 ] )
V_376 . V_379 =
F_218 ( V_80 -> V_527 [ V_380 ] ) ;
if ( V_80 -> V_527 [ V_383 ] ) {
T_5 V_149 = F_132 ( V_80 -> V_527 [ V_383 ] ) ;
if ( V_149 >= F_97 ( V_382 ) )
return - V_59 ;
V_376 . V_381 = V_382 [ V_149 ] ;
}
return F_180 ( V_80 , & V_376 ) ;
}
static int F_228 ( struct V_24 * V_537 , struct V_369 * V_80 )
{
struct V_22 * V_23 ;
T_8 V_149 = - 1 ;
const char * V_389 = NULL ;
if ( V_80 -> V_527 [ V_377 ] )
V_149 = F_132 ( V_80 -> V_527 [ V_377 ] ) ;
else if ( V_80 -> V_527 [ V_390 ] )
V_389 = ( void * ) F_218 ( V_80 -> V_527 [ V_390 ] ) ;
else
return - V_59 ;
F_181 ( & V_193 ) ;
F_87 (data, &hwsim_radios, list) {
if ( V_149 >= 0 ) {
if ( V_23 -> V_149 != V_149 )
continue;
} else {
if ( strcmp ( V_389 , F_209 ( V_23 -> V_29 -> V_30 ) ) )
continue;
}
F_212 ( & V_23 -> V_506 ) ;
F_182 ( & V_193 ) ;
F_204 ( V_23 , F_209 ( V_23 -> V_29 -> V_30 ) ,
V_80 ) ;
return 0 ;
}
F_182 ( & V_193 ) ;
return - V_540 ;
}
static int F_229 ( struct V_24 * V_537 , struct V_369 * V_80 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
int V_149 , V_511 = - V_540 ;
if ( ! V_80 -> V_527 [ V_377 ] )
return - V_59 ;
V_149 = F_132 ( V_80 -> V_527 [ V_377 ] ) ;
F_181 ( & V_193 ) ;
F_87 (data, &hwsim_radios, list) {
if ( V_23 -> V_149 != V_149 )
continue;
V_25 = F_230 ( V_541 , V_373 ) ;
if ( ! V_25 ) {
V_511 = - V_312 ;
goto V_392;
}
V_511 = F_207 ( V_25 , V_23 , V_80 -> V_370 ,
V_80 -> V_542 , NULL , 0 ) ;
if ( V_511 < 0 ) {
F_179 ( V_25 ) ;
goto V_392;
}
F_231 ( V_25 , V_80 ) ;
break;
}
V_392:
F_182 ( & V_193 ) ;
return V_511 ;
}
static int F_232 ( struct V_24 * V_25 ,
struct V_510 * V_111 )
{
int V_149 = V_111 -> args [ 0 ] ;
struct V_22 * V_23 = NULL ;
int V_511 ;
F_181 ( & V_193 ) ;
if ( V_149 == V_397 )
goto V_543;
F_87 (data, &hwsim_radios, list) {
if ( V_23 -> V_149 < V_149 )
continue;
V_511 = F_207 ( V_25 , V_23 ,
F_233 ( V_111 -> V_25 ) . V_407 ,
V_111 -> V_544 -> V_545 , V_111 ,
V_546 ) ;
if ( V_511 < 0 )
break;
V_149 = V_23 -> V_149 + 1 ;
}
V_111 -> args [ 0 ] = V_149 ;
V_543:
F_182 ( & V_193 ) ;
return V_25 -> V_141 ;
}
static void F_234 ( struct V_331 * V_332 )
{
struct V_22 * V_23 =
F_114 ( V_332 , struct V_22 , V_547 ) ;
F_204 ( V_23 , F_209 ( V_23 -> V_29 -> V_30 ) , NULL ) ;
}
static void F_235 ( T_5 V_407 )
{
struct V_22 * V_548 , * V_524 ;
F_181 ( & V_193 ) ;
F_236 (entry, tmp, &hwsim_radios, list) {
if ( V_548 -> V_406 && V_548 -> V_407 == V_407 ) {
F_212 ( & V_548 -> V_506 ) ;
F_237 ( & V_548 -> V_547 , F_234 ) ;
F_238 ( & V_548 -> V_547 ) ;
}
}
F_182 ( & V_193 ) ;
}
static int F_239 ( struct V_549 * V_550 ,
unsigned long V_551 ,
void * V_552 )
{
struct V_553 * V_554 = V_552 ;
if ( V_551 != V_555 )
return V_556 ;
F_235 ( V_554 -> V_407 ) ;
if ( V_554 -> V_407 == V_211 ) {
F_64 ( V_557 L_58
L_59 ) ;
V_211 = 0 ;
}
return V_556 ;
}
static int F_240 ( void )
{
int V_558 ;
F_64 ( V_557 L_60 ) ;
V_558 = F_241 ( & V_135 ,
V_559 ,
V_560 ) ;
if ( V_558 )
goto V_561;
V_558 = F_242 ( & V_562 ) ;
if ( V_558 )
goto V_561;
return 0 ;
V_561:
F_64 ( V_137 L_5 , V_31 ) ;
return - V_59 ;
}
static void F_243 ( void )
{
F_244 ( & V_562 ) ;
F_245 ( & V_135 ) ;
}
static int T_9 F_246 ( void )
{
int V_125 , V_306 ;
if ( V_563 < 0 || V_563 > 100 )
return - V_59 ;
if ( V_342 < 1 )
return - V_59 ;
V_398 = V_396 ;
V_398 . V_333 = F_152 ;
V_398 . V_564 = F_154 ;
V_398 . V_565 = NULL ;
V_398 . V_566 = NULL ;
V_398 . V_567 = F_160 ;
V_398 . V_568 = F_162 ;
V_398 . V_569 = F_163 ;
V_398 . V_570 = F_164 ;
V_398 . V_571 = F_165 ;
V_398 . V_572 =
F_166 ;
V_398 . V_573 =
F_167 ;
F_247 ( & V_193 ) ;
F_248 ( & V_507 ) ;
V_306 = F_249 ( & V_403 ) ;
if ( V_306 )
return V_306 ;
V_400 = F_250 ( V_574 , L_61 ) ;
if ( F_185 ( V_400 ) ) {
V_306 = F_186 ( V_400 ) ;
goto V_575;
}
V_306 = F_240 () ;
if ( V_306 < 0 )
goto V_575;
for ( V_125 = 0 ; V_125 < V_563 ; V_125 ++ ) {
struct V_375 V_376 = { 0 } ;
V_376 . V_342 = V_342 ;
switch ( V_576 ) {
case V_577 :
if ( V_125 < F_97 ( V_578 ) )
V_376 . V_379 = V_578 [ V_125 ] ;
break;
case V_579 :
if ( ! V_125 )
V_376 . V_379 = V_578 [ 0 ] ;
break;
case V_580 :
V_376 . V_384 = true ;
case V_581 :
V_376 . V_379 = V_578 [ 0 ] ;
break;
case V_582 :
if ( V_125 == 0 )
V_376 . V_381 = & V_583 ;
break;
case V_584 :
V_376 . V_381 = & V_583 ;
break;
case V_585 :
if ( V_125 == 0 )
V_376 . V_381 = & V_583 ;
else if ( V_125 == 1 )
V_376 . V_381 = & V_586 ;
break;
case V_587 :
if ( V_125 == 0 ) {
V_376 . V_384 = true ;
V_376 . V_379 = V_578 [ 0 ] ;
}
break;
case V_588 :
if ( V_125 == 0 ) {
V_376 . V_384 = true ;
V_376 . V_379 = V_578 [ 0 ] ;
} else if ( V_125 == 1 ) {
V_376 . V_379 = V_578 [ 1 ] ;
}
break;
case V_589 :
switch ( V_125 ) {
case 0 :
V_376 . V_381 = & V_583 ;
break;
case 1 :
V_376 . V_381 = & V_586 ;
break;
case 2 :
V_376 . V_379 = V_578 [ 0 ] ;
break;
case 3 :
V_376 . V_379 = V_578 [ 1 ] ;
break;
case 4 :
V_376 . V_384 = true ;
V_376 . V_379 = V_578 [ 2 ] ;
break;
}
break;
default:
break;
}
V_376 . V_386 = V_590 ;
V_376 . V_207 = V_342 > 1 ;
V_306 = F_180 ( NULL , & V_376 ) ;
if ( V_306 < 0 )
goto V_591;
}
V_83 = F_251 ( 0 , L_47 , V_592 ,
F_214 ) ;
if ( V_83 == NULL ) {
V_306 = - V_312 ;
goto V_591;
}
F_252 () ;
V_306 = F_253 ( V_83 , V_83 -> V_593 ) ;
if ( V_306 < 0 ) {
F_254 () ;
goto V_591;
}
V_306 = F_255 ( V_83 ) ;
if ( V_306 < 0 ) {
F_254 () ;
goto V_594;
}
F_254 () ;
return 0 ;
V_594:
V_517 ( V_83 ) ;
V_591:
F_210 () ;
V_575:
F_256 ( & V_403 ) ;
return V_306 ;
}
static void T_10 F_257 ( void )
{
F_64 ( V_137 L_62 ) ;
F_243 () ;
F_210 () ;
F_258 ( V_83 ) ;
F_256 ( & V_403 ) ;
}
