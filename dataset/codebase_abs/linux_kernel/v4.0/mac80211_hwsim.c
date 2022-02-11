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
F_26 () ;
if ( V_52 == V_58 ) {
F_27 (
V_23 -> V_29 , V_60 ,
F_12 , V_23 ) ;
V_23 -> V_61 = true ;
} else if ( V_54 == V_55 && V_52 != V_55 ) {
F_27 (
V_23 -> V_29 , V_60 ,
F_22 , V_23 ) ;
} else if ( V_54 != V_55 && V_52 == V_55 ) {
F_27 (
V_23 -> V_29 , V_60 ,
F_23 , V_23 ) ;
}
F_28 () ;
return 0 ;
}
static int F_29 ( void * V_20 , T_2 V_52 )
{
struct V_22 * V_23 = V_20 ;
F_30 ( V_23 -> V_29 ) ;
return 0 ;
}
static int F_31 ( void * V_20 , T_2 * V_52 )
{
struct V_22 * V_23 = V_20 ;
* V_52 = V_23 -> V_62 ;
return 0 ;
}
static int F_32 ( void * V_20 , T_2 V_52 )
{
struct V_22 * V_23 = V_20 ;
V_23 -> V_62 = V_52 ;
return 0 ;
}
static T_3 F_33 ( struct V_24 * V_25 ,
struct V_63 * V_64 )
{
F_34 ( V_25 ) ;
return V_65 ;
}
static inline T_2 F_35 ( void )
{
return F_36 ( F_37 () ) ;
}
static T_4 F_38 ( struct V_22 * V_23 )
{
T_2 V_66 = F_35 () ;
return F_39 ( V_66 + V_23 -> V_67 ) ;
}
static T_2 F_40 ( struct V_68 * V_29 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
return F_41 ( F_38 ( V_23 ) ) ;
}
static void F_42 ( struct V_68 * V_29 ,
struct V_1 * V_2 , T_2 V_70 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
T_2 V_66 = F_40 ( V_29 , V_2 ) ;
T_5 V_71 = V_23 -> V_72 ;
T_2 V_73 = F_43 ( V_70 - V_66 ) ;
if ( V_70 > V_66 ) {
V_23 -> V_67 += V_73 ;
V_23 -> V_74 = F_44 ( V_73 , V_71 ) ;
} else {
V_23 -> V_67 -= V_73 ;
V_23 -> V_74 = - F_44 ( V_73 , V_71 ) ;
}
}
static void F_45 ( struct V_68 * V_29 ,
struct V_24 * V_75 ,
struct V_76 * V_42 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
struct V_24 * V_25 ;
struct V_77 * V_45 ;
T_6 V_78 ;
struct V_79 * V_80 = F_46 ( V_75 ) ;
struct V_81 * V_82 = F_47 ( V_29 , V_80 ) ;
if ( ! F_48 ( V_83 ) )
return;
V_25 = F_49 ( V_75 , sizeof( * V_45 ) , 0 , V_84 ) ;
if ( V_25 == NULL )
return;
V_45 = (struct V_77 * ) F_50 ( V_25 , sizeof( * V_45 ) ) ;
V_45 -> V_45 . V_85 = V_86 ;
V_45 -> V_45 . V_87 = 0 ;
V_45 -> V_45 . V_88 = F_16 ( sizeof( * V_45 ) ) ;
V_45 -> V_45 . V_89 = F_51 ( ( 1 << V_90 ) |
( 1 << V_91 ) |
( 1 << V_92 ) |
( 1 << V_93 ) ) ;
V_45 -> V_94 = F_38 ( V_23 ) ;
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
F_52 ( V_25 , 0 ) ;
V_25 -> V_105 = V_106 ;
V_25 -> V_107 = V_108 ;
V_25 -> V_109 = F_53 ( V_110 ) ;
memset ( V_25 -> V_111 , 0 , sizeof( V_25 -> V_111 ) ) ;
F_54 ( V_25 ) ;
}
static void F_55 ( struct V_76 * V_42 ,
const T_1 * V_8 )
{
struct V_24 * V_25 ;
struct V_112 * V_45 ;
T_6 V_78 ;
struct V_44 * V_113 ;
if ( ! F_48 ( V_83 ) )
return;
V_25 = F_14 ( 100 ) ;
if ( V_25 == NULL )
return;
V_45 = (struct V_112 * ) F_15 ( V_25 , sizeof( * V_45 ) ) ;
V_45 -> V_45 . V_85 = V_86 ;
V_45 -> V_45 . V_87 = 0 ;
V_45 -> V_45 . V_88 = F_16 ( sizeof( * V_45 ) ) ;
V_45 -> V_45 . V_89 = F_51 ( ( 1 << V_90 ) |
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
F_52 ( V_25 , 0 ) ;
V_25 -> V_105 = V_106 ;
V_25 -> V_107 = V_108 ;
V_25 -> V_109 = F_53 ( V_110 ) ;
memset ( V_25 -> V_111 , 0 , sizeof( V_25 -> V_111 ) ) ;
F_54 ( V_25 ) ;
}
static void F_56 ( void * V_23 , T_1 * V_21 ,
struct V_1 * V_2 )
{
struct V_116 * V_117 = V_23 ;
if ( memcmp ( V_21 , V_117 -> V_8 , V_38 ) == 0 )
V_117 -> V_118 = true ;
}
static bool F_57 ( struct V_22 * V_23 ,
const T_1 * V_8 )
{
struct V_116 V_117 = {
. V_118 = false ,
} ;
if ( V_23 -> V_119 && memcmp ( V_8 , V_23 -> V_120 , V_38 ) == 0 )
return true ;
memcpy ( V_117 . V_8 , V_8 , V_38 ) ;
F_27 ( V_23 -> V_29 ,
V_60 ,
F_56 ,
& V_117 ) ;
return V_117 . V_118 ;
}
static bool F_58 ( struct V_22 * V_23 ,
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
F_57 ( V_23 , V_25 -> V_23 + 4 ) ) {
V_23 -> V_61 = false ;
return true ;
}
return false ;
}
return true ;
}
static void F_59 ( struct V_68 * V_29 ,
struct V_24 * V_121 ,
int V_122 )
{
struct V_24 * V_25 ;
struct V_22 * V_23 = V_29 -> V_69 ;
struct V_44 * V_45 = (struct V_44 * ) V_121 -> V_23 ;
struct V_79 * V_80 = F_46 ( V_121 ) ;
void * V_123 ;
unsigned int V_124 = 0 ;
int V_125 ;
struct V_126 V_127 [ V_128 ] ;
if ( V_23 -> V_43 != V_55 )
V_45 -> V_34 |= F_16 ( V_37 ) ;
if ( F_60 ( & V_23 -> V_129 ) >= V_130 ) {
while ( F_60 ( & V_23 -> V_129 ) >= V_131 ) {
F_61 ( V_29 , F_62 ( & V_23 -> V_129 ) ) ;
V_23 -> V_132 ++ ;
}
}
V_25 = F_63 ( V_133 , V_84 ) ;
if ( V_25 == NULL )
goto V_134;
V_123 = F_64 ( V_25 , 0 , 0 , & V_135 , 0 ,
V_136 ) ;
if ( V_123 == NULL ) {
F_65 ( V_137 L_4 ) ;
goto V_134;
}
if ( F_66 ( V_25 , V_138 ,
V_38 , V_23 -> V_139 [ 1 ] . V_8 ) )
goto V_134;
if ( F_66 ( V_25 , V_140 , V_121 -> V_141 , V_121 -> V_23 ) )
goto V_134;
if ( V_80 -> V_78 & V_142 )
V_124 |= V_143 ;
if ( V_80 -> V_78 & V_144 )
V_124 |= V_145 ;
if ( F_67 ( V_25 , V_146 , V_124 ) )
goto V_134;
if ( F_67 ( V_25 , V_147 , V_23 -> V_148 -> V_99 ) )
goto V_134;
for ( V_125 = 0 ; V_125 < V_128 ; V_125 ++ ) {
V_127 [ V_125 ] . V_149 = V_80 -> V_150 . V_151 [ V_125 ] . V_149 ;
V_127 [ V_125 ] . V_152 = V_80 -> V_150 . V_151 [ V_125 ] . V_152 ;
}
if ( F_66 ( V_25 , V_153 ,
sizeof( struct V_126 ) * V_128 ,
V_127 ) )
goto V_134;
if ( F_68 ( V_25 , V_154 , ( unsigned long ) V_121 ) )
goto V_134;
F_69 ( V_25 , V_123 ) ;
if ( F_70 ( & V_155 , V_25 , V_122 ) )
goto V_156;
F_71 ( & V_23 -> V_129 , V_121 ) ;
V_23 -> V_157 ++ ;
V_23 -> V_158 += V_121 -> V_141 ;
return;
V_134:
F_72 ( V_25 ) ;
V_156:
F_65 ( V_137 L_5 , V_31 ) ;
F_61 ( V_29 , V_121 ) ;
V_23 -> V_159 ++ ;
}
static bool F_73 ( struct V_76 * V_160 ,
struct V_76 * V_161 )
{
if ( ! V_160 || ! V_161 )
return false ;
return V_160 -> V_99 == V_161 -> V_99 ;
}
static void F_74 ( void * V_162 , T_1 * V_8 ,
struct V_1 * V_2 )
{
struct V_163 * V_23 = V_162 ;
if ( ! V_2 -> V_40 )
return;
if ( ! F_73 ( V_23 -> V_148 ,
F_19 ( V_2 -> V_40 ) -> V_41 . V_42 ) )
return;
V_23 -> V_164 = true ;
}
static void F_75 ( struct V_24 * V_25 )
{
#ifdef F_76
struct V_165 * V_166 ;
V_166 = ( void * ) F_50 ( V_25 , sizeof( * V_166 ) + 8 + 4 ) ;
V_166 -> V_167 [ 0 ] = F_76 [ 0 ] ;
V_166 -> V_167 [ 1 ] = F_76 [ 1 ] ;
V_166 -> V_167 [ 2 ] = F_76 [ 2 ] ;
V_166 -> V_168 = 127 ;
V_166 -> V_169 = F_77 ( 0 ) ;
V_166 -> V_141 = 8 ;
V_166 -> V_170 = 8 ;
V_166 -> V_114 = 4 ;
memcpy ( V_166 -> V_23 , L_6 , 8 ) ;
memset ( V_166 -> V_23 + 8 , 0 , 4 ) ;
F_78 ( V_25 ) -> V_171 |= V_172 ;
#endif
}
static bool F_79 ( struct V_68 * V_29 ,
struct V_24 * V_25 ,
struct V_76 * V_42 )
{
struct V_22 * V_23 = V_29 -> V_69 , * V_173 ;
bool V_174 = false ;
struct V_44 * V_45 = (struct V_44 * ) V_25 -> V_23 ;
struct V_79 * V_80 = F_46 ( V_25 ) ;
struct V_175 V_176 ;
T_2 V_66 ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_176 . V_171 |= V_177 ;
V_176 . V_178 = V_42 -> V_99 ;
V_176 . V_179 = V_42 -> V_179 ;
if ( V_80 -> V_180 . V_151 [ 0 ] . V_78 & V_181 ) {
V_176 . V_182 =
F_80 ( & V_80 -> V_180 . V_151 [ 0 ] ) ;
V_176 . V_183 =
F_81 ( & V_80 -> V_180 . V_151 [ 0 ] ) ;
V_176 . V_171 |= V_184 ;
} else {
V_176 . V_182 = V_80 -> V_180 . V_151 [ 0 ] . V_149 ;
if ( V_80 -> V_180 . V_151 [ 0 ] . V_78 & V_185 )
V_176 . V_171 |= V_186 ;
}
if ( V_80 -> V_180 . V_151 [ 0 ] . V_78 & V_187 )
V_176 . V_171 |= V_188 ;
if ( V_80 -> V_180 . V_151 [ 0 ] . V_78 & V_189 )
V_176 . V_171 |= V_190 ;
V_176 . signal = V_23 -> V_191 - 50 ;
if ( V_23 -> V_43 != V_55 )
V_45 -> V_34 |= F_16 ( V_37 ) ;
F_82 ( V_25 ) ;
F_83 ( V_25 ) ;
V_25 -> V_192 = 0 ;
F_84 ( V_25 ) ;
F_85 ( V_25 ) ;
if ( F_86 ( V_45 -> V_34 ) ||
F_87 ( V_45 -> V_34 ) )
V_66 = V_23 -> V_193 ;
else
V_66 = F_35 () ;
F_88 ( & V_194 ) ;
F_89 (data2, &hwsim_radios, list) {
struct V_24 * V_195 ;
struct V_163 V_163 = {
. V_164 = false ,
. V_148 = V_42 ,
} ;
if ( V_23 == V_173 )
continue;
if ( ! V_173 -> V_196 || ( V_173 -> V_197 && ! V_173 -> V_198 ) ||
! F_58 ( V_173 , V_25 ) )
continue;
if ( ! ( V_23 -> V_62 & V_173 -> V_62 ) )
continue;
if ( ! F_73 ( V_42 , V_173 -> V_198 ) &&
! F_73 ( V_42 , V_173 -> V_148 ) ) {
F_27 (
V_173 -> V_29 , V_60 ,
F_74 , & V_163 ) ;
if ( ! V_163 . V_164 )
continue;
}
if ( V_25 -> V_141 < V_199 && V_200 ) {
struct V_201 * V_201 = F_90 ( V_84 ) ;
if ( ! V_201 )
continue;
V_195 = F_14 ( 128 ) ;
if ( ! V_195 ) {
F_91 ( V_201 ) ;
continue;
}
memcpy ( F_92 ( V_201 ) , V_25 -> V_23 , V_25 -> V_141 ) ;
F_93 ( V_195 , 0 , V_201 , 0 , V_25 -> V_141 , V_25 -> V_141 ) ;
} else {
V_195 = F_94 ( V_25 , V_84 ) ;
if ( ! V_195 )
continue;
}
if ( F_57 ( V_173 , V_45 -> V_49 ) )
V_174 = true ;
V_176 . V_202 = V_66 + V_173 -> V_67 ;
memcpy ( F_78 ( V_195 ) , & V_176 , sizeof( V_176 ) ) ;
F_75 ( V_195 ) ;
V_173 -> V_203 ++ ;
V_173 -> V_204 += V_195 -> V_141 ;
F_95 ( V_173 -> V_29 , V_195 ) ;
}
F_96 ( & V_194 ) ;
return V_174 ;
}
static void F_97 ( struct V_68 * V_29 ,
struct V_205 * V_180 ,
struct V_24 * V_25 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
struct V_79 * V_206 = F_46 ( V_25 ) ;
struct V_15 * V_40 ;
struct V_76 * V_148 ;
bool V_174 ;
T_5 V_207 ;
if ( F_6 ( V_25 -> V_141 < 10 ) ) {
F_61 ( V_29 , V_25 ) ;
return;
}
if ( ! V_23 -> V_208 ) {
V_148 = V_23 -> V_148 ;
} else if ( V_206 -> V_209 == 4 ) {
V_148 = V_23 -> V_198 ;
} else {
V_40 = F_19 ( V_206 -> V_180 . V_2 -> V_40 ) ;
if ( V_40 )
V_148 = V_40 -> V_41 . V_42 ;
else
V_148 = NULL ;
}
if ( F_2 ( ! V_148 , L_7 , V_206 -> V_209 ) ) {
F_61 ( V_29 , V_25 ) ;
return;
}
if ( V_23 -> V_197 && ! V_23 -> V_198 ) {
F_13 ( V_29 -> V_30 , L_8 ) ;
F_61 ( V_29 , V_25 ) ;
return;
}
if ( V_206 -> V_180 . V_2 )
F_1 ( V_206 -> V_180 . V_2 ) ;
if ( V_180 -> V_11 )
F_5 ( V_180 -> V_11 ) ;
if ( V_29 -> V_78 & V_210 )
F_98 ( V_206 -> V_180 . V_2 , V_180 -> V_11 , V_25 ,
V_206 -> V_180 . V_151 ,
F_99 ( V_206 -> V_180 . V_151 ) ) ;
V_206 -> V_211 [ 0 ] = V_148 ;
F_45 ( V_29 , V_25 , V_148 ) ;
V_207 = F_100 ( V_212 ) ;
if ( V_207 )
return F_59 ( V_29 , V_25 , V_207 ) ;
V_23 -> V_157 ++ ;
V_23 -> V_158 += V_25 -> V_141 ;
V_174 = F_79 ( V_29 , V_25 , V_148 ) ;
if ( V_174 && V_25 -> V_141 >= 16 ) {
struct V_44 * V_45 = (struct V_44 * ) V_25 -> V_23 ;
F_55 ( V_148 , V_45 -> V_50 ) ;
}
F_101 ( V_206 ) ;
V_206 -> V_180 . V_151 [ 0 ] . V_152 = 1 ;
V_206 -> V_180 . V_151 [ 1 ] . V_149 = - 1 ;
if ( ! ( V_206 -> V_78 & V_144 ) && V_174 )
V_206 -> V_78 |= V_213 ;
F_102 ( V_29 , V_25 ) ;
}
static int F_103 ( struct V_68 * V_29 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
F_13 ( V_29 -> V_30 , L_9 , V_31 ) ;
V_23 -> V_196 = true ;
return 0 ;
}
static void F_104 ( struct V_68 * V_29 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
V_23 -> V_196 = false ;
F_105 ( & V_23 -> V_214 ) ;
F_13 ( V_29 -> V_30 , L_9 , V_31 ) ;
}
static int F_106 ( struct V_68 * V_29 ,
struct V_1 * V_2 )
{
F_13 ( V_29 -> V_30 , L_10 ,
V_31 , F_107 ( V_2 ) ,
V_2 -> V_8 ) ;
F_3 ( V_2 ) ;
V_2 -> V_215 = 0 ;
V_2 -> V_209 [ V_216 ] = 0 ;
V_2 -> V_209 [ V_217 ] = 1 ;
V_2 -> V_209 [ V_218 ] = 2 ;
V_2 -> V_209 [ V_219 ] = 3 ;
return 0 ;
}
static int F_108 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
enum V_220 V_221 ,
bool V_222 )
{
V_221 = F_109 ( V_221 , V_222 ) ;
F_13 ( V_29 -> V_30 ,
L_11 ,
V_31 , F_107 ( V_2 ) ,
V_221 , V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
V_2 -> V_215 = 0 ;
return 0 ;
}
static void F_110 (
struct V_68 * V_29 , struct V_1 * V_2 )
{
F_13 ( V_29 -> V_30 , L_10 ,
V_31 , F_107 ( V_2 ) ,
V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
}
static void F_18 ( struct V_68 * V_29 ,
struct V_24 * V_25 ,
struct V_76 * V_42 )
{
T_5 V_223 = F_100 ( V_212 ) ;
if ( V_29 -> V_78 & V_210 ) {
struct V_79 * V_206 = F_46 ( V_25 ) ;
F_98 ( V_206 -> V_180 . V_2 , NULL , V_25 ,
V_206 -> V_180 . V_151 ,
F_99 ( V_206 -> V_180 . V_151 ) ) ;
}
F_45 ( V_29 , V_25 , V_42 ) ;
if ( V_223 )
return F_59 ( V_29 , V_25 , V_223 ) ;
F_79 ( V_29 , V_25 , V_42 ) ;
F_34 ( V_25 ) ;
}
static void F_111 ( void * V_224 , T_1 * V_21 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = V_224 ;
struct V_68 * V_29 = V_23 -> V_29 ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
struct V_225 * V_226 ;
struct V_24 * V_25 ;
F_1 ( V_2 ) ;
if ( V_2 -> type != V_227 &&
V_2 -> type != V_228 &&
V_2 -> type != V_229 )
return;
V_25 = F_112 ( V_29 , V_2 ) ;
if ( V_25 == NULL )
return;
V_80 = F_46 ( V_25 ) ;
if ( V_29 -> V_78 & V_210 )
F_98 ( V_2 , NULL , V_25 ,
V_80 -> V_180 . V_151 ,
F_99 ( V_80 -> V_180 . V_151 ) ) ;
V_82 = F_47 ( V_29 , V_80 ) ;
V_226 = (struct V_225 * ) V_25 -> V_23 ;
V_23 -> V_193 = F_35 () ;
V_226 -> V_230 . V_231 . V_232 = F_39 ( V_23 -> V_193 +
V_23 -> V_67 +
24 * 8 * 10 / V_82 -> V_97 ) ;
F_18 ( V_29 , V_25 ,
F_19 ( V_2 -> V_40 ) -> V_41 . V_42 ) ;
if ( V_2 -> V_233 && F_113 ( V_2 ) )
F_114 ( V_2 ) ;
}
static enum V_234
F_115 ( struct V_235 * V_236 )
{
struct V_22 * V_23 =
F_116 ( V_236 , struct V_22 ,
V_214 . V_236 ) ;
struct V_68 * V_29 = V_23 -> V_29 ;
T_2 V_71 = V_23 -> V_72 ;
T_7 V_237 ;
if ( ! V_23 -> V_196 )
goto V_238;
F_27 (
V_29 , V_60 ,
F_111 , V_23 ) ;
if ( V_23 -> V_74 ) {
V_71 -= V_23 -> V_74 ;
V_23 -> V_74 = 0 ;
}
V_237 = F_117 ( F_118 ( V_236 ) ,
F_119 ( V_71 * 1000 ) ) ;
F_120 ( & V_23 -> V_214 , V_237 , V_239 ) ;
V_238:
return V_240 ;
}
static int F_121 ( struct V_68 * V_29 , T_5 V_241 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
struct V_242 * V_243 = & V_29 -> V_243 ;
static const char * V_244 [ V_245 ] = {
[ V_246 ] = L_12 ,
[ V_247 ] = L_13 ,
[ V_248 ] = L_14 ,
[ V_249 ] = L_15 ,
} ;
if ( V_243 -> V_250 . V_42 )
F_13 ( V_29 -> V_30 ,
L_16 ,
V_31 ,
V_243 -> V_250 . V_42 -> V_99 ,
V_243 -> V_250 . V_251 ,
V_243 -> V_250 . V_252 ,
V_253 [ V_243 -> V_250 . V_254 ] ,
! ! ( V_243 -> V_78 & V_255 ) ,
! ! ( V_243 -> V_78 & V_256 ) ,
V_244 [ V_243 -> V_257 ] ) ;
else
F_13 ( V_29 -> V_30 ,
L_17 ,
V_31 ,
! ! ( V_243 -> V_78 & V_255 ) ,
! ! ( V_243 -> V_78 & V_256 ) ,
V_244 [ V_243 -> V_257 ] ) ;
V_23 -> V_197 = ! ! ( V_243 -> V_78 & V_255 ) ;
V_23 -> V_148 = V_243 -> V_250 . V_42 ;
F_6 ( V_23 -> V_148 && V_23 -> V_208 ) ;
V_23 -> V_191 = V_243 -> V_191 ;
if ( ! V_23 -> V_196 || ! V_23 -> V_72 )
F_105 ( & V_23 -> V_214 ) ;
else if ( ! F_122 ( & V_23 -> V_214 . V_236 ) ) {
T_2 V_70 = F_40 ( V_29 , NULL ) ;
T_5 V_71 = V_23 -> V_72 ;
T_2 V_258 = V_71 - F_44 ( V_70 , V_71 ) ;
F_120 ( & V_23 -> V_214 ,
F_119 ( V_258 * 1000 ) ,
V_259 ) ;
}
return 0 ;
}
static void F_123 ( struct V_68 * V_29 ,
unsigned int V_260 ,
unsigned int * V_261 , T_2 V_262 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
F_13 ( V_29 -> V_30 , L_9 , V_31 ) ;
V_23 -> V_263 = 0 ;
if ( * V_261 & V_264 )
V_23 -> V_263 |= V_264 ;
if ( * V_261 & V_265 )
V_23 -> V_263 |= V_265 ;
* V_261 = V_23 -> V_263 ;
}
static void F_124 ( void * V_23 , T_1 * V_21 ,
struct V_1 * V_2 )
{
unsigned int * V_152 = V_23 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
if ( V_4 -> V_266 )
( * V_152 ) ++ ;
}
static void F_125 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_267 * V_80 ,
T_5 V_241 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_22 * V_23 = V_29 -> V_69 ;
F_1 ( V_2 ) ;
F_13 ( V_29 -> V_30 , L_18 ,
V_31 , V_241 , V_2 -> V_8 ) ;
if ( V_241 & V_268 ) {
F_13 ( V_29 -> V_30 , L_19 ,
V_31 , V_80 -> V_32 ) ;
memcpy ( V_4 -> V_32 , V_80 -> V_32 , V_38 ) ;
}
if ( V_241 & V_269 ) {
F_13 ( V_29 -> V_30 , L_20 ,
V_80 -> V_28 , V_80 -> V_33 ) ;
V_4 -> V_28 = V_80 -> V_28 ;
V_4 -> V_33 = V_80 -> V_33 ;
}
if ( V_241 & V_270 ) {
F_13 ( V_29 -> V_30 , L_21 , V_80 -> V_72 ) ;
V_23 -> V_72 = V_80 -> V_72 * 1024 ;
}
if ( V_241 & V_271 ) {
F_13 ( V_29 -> V_30 , L_22 , V_80 -> V_272 ) ;
V_4 -> V_266 = V_80 -> V_272 ;
if ( V_23 -> V_196 &&
! F_122 ( & V_23 -> V_214 . V_236 ) &&
V_80 -> V_272 ) {
T_2 V_70 , V_258 ;
T_5 V_71 ;
if ( F_6 ( ! V_23 -> V_72 ) )
V_23 -> V_72 = 1000 * 1024 ;
V_70 = F_40 ( V_29 , V_2 ) ;
V_71 = V_23 -> V_72 ;
V_258 = V_71 - F_44 ( V_70 , V_71 ) ;
F_120 ( & V_23 -> V_214 ,
F_119 ( V_258 * 1000 ) ,
V_259 ) ;
} else if ( ! V_80 -> V_272 ) {
unsigned int V_152 = 0 ;
F_27 (
V_23 -> V_29 , V_60 ,
F_124 , & V_152 ) ;
F_13 ( V_29 -> V_30 , L_23 ,
V_152 ) ;
if ( V_152 == 0 )
F_105 ( & V_23 -> V_214 ) ;
}
}
if ( V_241 & V_273 ) {
F_13 ( V_29 -> V_30 , L_24 ,
V_80 -> V_274 ) ;
}
if ( V_241 & V_275 ) {
F_13 ( V_29 -> V_30 , L_25 ,
V_80 -> V_276 ) ;
}
if ( V_241 & V_277 ) {
F_13 ( V_29 -> V_30 , L_26 , V_80 -> V_278 ) ;
}
if ( V_241 & V_279 ) {
F_13 ( V_29 -> V_30 , L_27 ,
V_80 -> V_280 ) ;
}
if ( V_241 & V_281 ) {
F_13 ( V_29 -> V_30 , L_28 ,
( unsigned long long ) V_80 -> V_282 ) ;
}
if ( V_241 & V_283 )
F_13 ( V_29 -> V_30 , L_29 , V_80 -> V_284 ) ;
}
static int F_126 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_7 ( V_11 ) ;
return 0 ;
}
static int F_127 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static void F_128 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
enum V_285 V_286 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
switch ( V_286 ) {
case V_287 :
case V_288 :
break;
default:
F_2 ( 1 , L_30 , V_286 ) ;
break;
}
}
static int F_129 ( struct V_68 * V_29 ,
struct V_10 * V_11 ,
bool V_289 )
{
F_5 ( V_11 ) ;
return 0 ;
}
static int F_130 (
struct V_68 * V_29 ,
struct V_1 * V_2 , T_6 V_290 ,
const struct V_291 * V_292 )
{
F_13 ( V_29 -> V_30 ,
L_31 ,
V_31 , V_290 ,
V_292 -> V_293 , V_292 -> V_294 ,
V_292 -> V_295 , V_292 -> V_296 ) ;
return 0 ;
}
static int F_131 (
struct V_68 * V_29 , int V_149 ,
struct V_297 * V_298 )
{
struct V_242 * V_243 = & V_29 -> V_243 ;
F_13 ( V_29 -> V_30 , L_32 , V_31 , V_149 ) ;
if ( V_149 != 0 )
return - V_299 ;
V_298 -> V_148 = V_243 -> V_250 . V_42 ;
V_298 -> V_300 = V_301 ;
V_298 -> V_302 = - 92 ;
return 0 ;
}
static int F_132 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
void * V_23 , int V_141 )
{
struct V_22 * V_303 = V_29 -> V_69 ;
struct V_304 * V_305 [ V_306 + 1 ] ;
struct V_24 * V_25 ;
int V_307 , V_43 ;
V_307 = F_133 ( V_305 , V_306 , V_23 , V_141 ,
V_308 ) ;
if ( V_307 )
return V_307 ;
if ( ! V_305 [ V_309 ] )
return - V_59 ;
switch ( F_134 ( V_305 [ V_309 ] ) ) {
case V_310 :
if ( ! V_305 [ V_311 ] )
return - V_59 ;
V_43 = F_134 ( V_305 [ V_311 ] ) ;
return F_25 ( V_303 , V_43 ) ;
case V_312 :
V_25 = F_135 ( V_29 -> V_30 ,
F_136 ( sizeof( T_5 ) ) ) ;
if ( ! V_25 )
return - V_313 ;
if ( F_67 ( V_25 , V_311 , V_303 -> V_43 ) )
goto V_134;
return F_137 ( V_25 ) ;
case V_314 :
F_138 ( V_29 ) ;
return 0 ;
case V_315 :
F_139 ( V_29 ) ;
return 0 ;
default:
return - V_316 ;
}
V_134:
F_140 ( V_25 ) ;
return - V_317 ;
}
static int F_141 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
enum V_318 V_319 ,
struct V_10 * V_11 , T_6 V_320 , T_6 * V_321 ,
T_1 V_322 )
{
switch ( V_319 ) {
case V_323 :
F_142 ( V_2 , V_11 -> V_8 , V_320 ) ;
break;
case V_324 :
case V_325 :
case V_326 :
F_143 ( V_2 , V_11 -> V_8 , V_320 ) ;
break;
case V_327 :
break;
case V_328 :
case V_329 :
break;
default:
return - V_316 ;
}
return 0 ;
}
static void F_144 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
T_5 V_330 , bool V_331 )
{
}
static void F_145 ( struct V_332 * V_333 )
{
struct V_22 * V_303 =
F_116 ( V_333 , struct V_22 , V_334 . V_333 ) ;
struct V_335 * V_336 = V_303 -> V_337 ;
int V_338 , V_125 ;
F_146 ( & V_303 -> V_339 ) ;
if ( V_303 -> V_340 >= V_336 -> V_341 ) {
F_13 ( V_303 -> V_29 -> V_30 , L_33 ) ;
F_147 ( V_303 -> V_29 , false ) ;
V_303 -> V_337 = NULL ;
V_303 -> V_342 = NULL ;
V_303 -> V_198 = NULL ;
F_148 ( & V_303 -> V_339 ) ;
return;
}
F_13 ( V_303 -> V_29 -> V_30 , L_34 ,
V_336 -> V_343 [ V_303 -> V_340 ] -> V_99 ) ;
V_303 -> V_198 = V_336 -> V_343 [ V_303 -> V_340 ] ;
if ( V_303 -> V_198 -> V_78 & V_344 ||
! V_336 -> V_345 ) {
V_338 = 120 ;
} else {
V_338 = 30 ;
for ( V_125 = 0 ; V_125 < V_336 -> V_345 ; V_125 ++ ) {
struct V_24 * V_346 ;
V_346 = F_149 ( V_303 -> V_29 ,
V_303 -> V_120 ,
V_336 -> V_347 [ V_125 ] . V_348 ,
V_336 -> V_347 [ V_125 ] . V_349 ,
V_336 -> V_350 ) ;
if ( ! V_346 )
continue;
if ( V_336 -> V_350 )
memcpy ( F_15 ( V_346 , V_336 -> V_350 ) , V_336 -> V_351 ,
V_336 -> V_350 ) ;
F_26 () ;
F_18 ( V_303 -> V_29 , V_346 ,
V_303 -> V_198 ) ;
F_28 () ;
}
}
F_150 ( V_303 -> V_29 , & V_303 -> V_334 ,
F_151 ( V_338 ) ) ;
V_303 -> V_340 ++ ;
F_148 ( & V_303 -> V_339 ) ;
}
static int F_152 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_352 * V_353 )
{
struct V_22 * V_303 = V_29 -> V_69 ;
struct V_335 * V_336 = & V_353 -> V_336 ;
F_146 ( & V_303 -> V_339 ) ;
if ( F_6 ( V_303 -> V_198 || V_303 -> V_337 ) ) {
F_148 ( & V_303 -> V_339 ) ;
return - V_354 ;
}
V_303 -> V_337 = V_336 ;
V_303 -> V_342 = V_2 ;
V_303 -> V_340 = 0 ;
if ( V_336 -> V_78 & V_355 )
F_153 ( V_303 -> V_120 ,
V_353 -> V_336 . V_356 ,
V_353 -> V_336 . V_357 ) ;
else
memcpy ( V_303 -> V_120 , V_2 -> V_8 , V_38 ) ;
F_148 ( & V_303 -> V_339 ) ;
F_13 ( V_29 -> V_30 , L_35 ) ;
F_150 ( V_303 -> V_29 , & V_303 -> V_334 , 0 ) ;
return 0 ;
}
static void F_154 ( struct V_68 * V_29 ,
struct V_1 * V_2 )
{
struct V_22 * V_303 = V_29 -> V_69 ;
F_13 ( V_29 -> V_30 , L_36 ) ;
F_155 ( & V_303 -> V_334 ) ;
F_146 ( & V_303 -> V_339 ) ;
F_147 ( V_303 -> V_29 , true ) ;
V_303 -> V_198 = NULL ;
V_303 -> V_337 = NULL ;
V_303 -> V_342 = NULL ;
F_148 ( & V_303 -> V_339 ) ;
}
static void F_156 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
const T_1 * V_356 )
{
struct V_22 * V_303 = V_29 -> V_69 ;
F_146 ( & V_303 -> V_339 ) ;
if ( V_303 -> V_119 ) {
F_65 ( V_137 L_37 ) ;
goto V_238;
}
F_65 ( V_137 L_38 ) ;
memcpy ( V_303 -> V_120 , V_356 , V_38 ) ;
V_303 -> V_119 = true ;
V_238:
F_148 ( & V_303 -> V_339 ) ;
}
static void F_157 ( struct V_68 * V_29 ,
struct V_1 * V_2 )
{
struct V_22 * V_303 = V_29 -> V_69 ;
F_146 ( & V_303 -> V_339 ) ;
F_65 ( V_137 L_39 ) ;
V_303 -> V_119 = false ;
memset ( V_303 -> V_120 , 0 , V_38 ) ;
F_148 ( & V_303 -> V_339 ) ;
}
static void F_158 ( struct V_332 * V_333 )
{
struct V_22 * V_303 =
F_116 ( V_333 , struct V_22 , V_358 . V_333 ) ;
F_146 ( & V_303 -> V_339 ) ;
F_159 ( V_303 -> V_29 ) ;
V_303 -> V_198 = NULL ;
F_148 ( & V_303 -> V_339 ) ;
F_13 ( V_303 -> V_29 -> V_30 , L_40 ) ;
}
static int F_160 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_76 * V_42 ,
int V_359 ,
enum V_360 type )
{
struct V_22 * V_303 = V_29 -> V_69 ;
F_146 ( & V_303 -> V_339 ) ;
if ( F_6 ( V_303 -> V_198 || V_303 -> V_337 ) ) {
F_148 ( & V_303 -> V_339 ) ;
return - V_354 ;
}
V_303 -> V_198 = V_42 ;
F_148 ( & V_303 -> V_339 ) ;
F_13 ( V_29 -> V_30 , L_41 ,
V_42 -> V_99 , V_359 ) ;
F_161 ( V_29 ) ;
F_150 ( V_29 , & V_303 -> V_358 ,
F_151 ( V_359 ) ) ;
return 0 ;
}
static int F_162 ( struct V_68 * V_29 )
{
struct V_22 * V_303 = V_29 -> V_69 ;
F_155 ( & V_303 -> V_358 ) ;
F_146 ( & V_303 -> V_339 ) ;
V_303 -> V_198 = NULL ;
F_148 ( & V_303 -> V_339 ) ;
F_13 ( V_29 -> V_30 , L_42 ) ;
return 0 ;
}
static int F_163 ( struct V_68 * V_29 ,
struct V_15 * V_361 )
{
F_10 ( V_361 ) ;
F_13 ( V_29 -> V_30 ,
L_43 ,
V_361 -> V_41 . V_42 -> V_99 , V_361 -> V_41 . V_254 ,
V_361 -> V_41 . V_251 , V_361 -> V_41 . V_252 ) ;
return 0 ;
}
static void F_164 ( struct V_68 * V_29 ,
struct V_15 * V_361 )
{
F_13 ( V_29 -> V_30 ,
L_44 ,
V_361 -> V_41 . V_42 -> V_99 , V_361 -> V_41 . V_254 ,
V_361 -> V_41 . V_251 , V_361 -> V_41 . V_252 ) ;
F_9 ( V_361 ) ;
F_11 ( V_361 ) ;
}
static void F_165 ( struct V_68 * V_29 ,
struct V_15 * V_361 ,
T_5 V_241 )
{
F_9 ( V_361 ) ;
F_13 ( V_29 -> V_30 ,
L_45 ,
V_361 -> V_41 . V_42 -> V_99 , V_361 -> V_41 . V_254 ,
V_361 -> V_41 . V_251 , V_361 -> V_41 . V_252 ) ;
}
static int F_166 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_15 * V_361 )
{
F_1 ( V_2 ) ;
F_9 ( V_361 ) ;
return 0 ;
}
static void F_167 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_15 * V_361 )
{
F_1 ( V_2 ) ;
F_9 ( V_361 ) ;
}
static void F_168 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
T_5 V_362 , T_1 * V_23 )
{
if ( V_362 == V_363 )
memcpy ( V_23 , * V_364 ,
sizeof( V_364 ) ) ;
}
static int F_169 ( struct V_68 * V_29 ,
struct V_1 * V_2 , int V_362 )
{
if ( V_362 == V_363 )
return V_365 ;
return 0 ;
}
static void F_170 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_366 * V_367 , T_2 * V_23 )
{
struct V_22 * V_368 = V_29 -> V_69 ;
int V_125 = 0 ;
V_23 [ V_125 ++ ] = V_368 -> V_157 ;
V_23 [ V_125 ++ ] = V_368 -> V_158 ;
V_23 [ V_125 ++ ] = V_368 -> V_203 ;
V_23 [ V_125 ++ ] = V_368 -> V_204 ;
V_23 [ V_125 ++ ] = V_368 -> V_132 ;
V_23 [ V_125 ++ ] = V_368 -> V_159 ;
V_23 [ V_125 ++ ] = V_368 -> V_43 ;
V_23 [ V_125 ++ ] = V_368 -> V_62 ;
V_23 [ V_125 ++ ] = V_368 -> V_191 ;
F_6 ( V_125 != V_365 ) ;
}
static void F_171 ( struct V_24 * V_369 ,
struct V_370 * V_80 )
{
if ( V_80 )
F_172 ( & V_135 , V_369 ,
F_173 ( V_80 ) , V_80 -> V_371 ,
V_372 , V_80 -> V_373 , V_374 ) ;
else
F_174 ( & V_135 , V_369 , 0 ,
V_372 , V_374 ) ;
}
static int F_175 ( struct V_24 * V_25 , int V_375 ,
struct V_376 * V_377 )
{
int V_118 ;
V_118 = F_67 ( V_25 , V_378 , V_375 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( V_377 -> V_343 ) {
V_118 = F_67 ( V_25 , V_379 , V_377 -> V_343 ) ;
if ( V_118 < 0 )
return V_118 ;
}
if ( V_377 -> V_380 ) {
V_118 = F_66 ( V_25 , V_381 , 2 ,
V_377 -> V_380 ) ;
if ( V_118 < 0 )
return V_118 ;
}
if ( V_377 -> V_382 ) {
int V_125 ;
for ( V_125 = 0 ; V_125 < F_99 ( V_383 ) ; V_125 ++ ) {
if ( V_383 [ V_125 ] != V_377 -> V_382 )
continue;
V_118 = F_67 ( V_25 , V_384 , V_125 ) ;
if ( V_118 < 0 )
return V_118 ;
break;
}
}
if ( V_377 -> V_385 ) {
V_118 = F_176 ( V_25 , V_386 ) ;
if ( V_118 < 0 )
return V_118 ;
}
if ( V_377 -> V_387 ) {
V_118 = F_176 ( V_25 , V_388 ) ;
if ( V_118 < 0 )
return V_118 ;
}
if ( V_377 -> V_208 ) {
V_118 = F_176 ( V_25 , V_389 ) ;
if ( V_118 < 0 )
return V_118 ;
}
if ( V_377 -> V_390 ) {
V_118 = F_66 ( V_25 , V_391 ,
strlen ( V_377 -> V_390 ) , V_377 -> V_390 ) ;
if ( V_118 < 0 )
return V_118 ;
}
return 0 ;
}
static void F_177 ( int V_375 , struct V_370 * V_80 ,
struct V_376 * V_377 )
{
struct V_24 * V_369 ;
void * V_23 ;
V_369 = F_63 ( V_133 , V_374 ) ;
if ( ! V_369 )
return;
V_23 = F_64 ( V_369 , 0 , 0 , & V_135 , 0 ,
V_392 ) ;
if ( ! V_23 )
goto V_393;
if ( F_175 ( V_369 , V_375 , V_377 ) < 0 )
goto V_393;
F_69 ( V_369 , V_23 ) ;
F_171 ( V_369 , V_80 ) ;
return;
V_393:
F_178 ( V_369 , V_23 ) ;
F_72 ( V_369 ) ;
}
static int F_179 ( struct V_370 * V_80 ,
struct V_376 * V_377 )
{
int V_307 ;
T_1 V_8 [ V_38 ] ;
struct V_22 * V_23 ;
struct V_68 * V_29 ;
enum V_394 V_179 ;
const struct V_395 * V_396 = & V_397 ;
int V_149 ;
if ( F_6 ( V_377 -> V_343 > 1 && ! V_377 -> V_208 ) )
return - V_59 ;
F_180 ( & V_194 ) ;
V_149 = V_398 ++ ;
F_181 ( & V_194 ) ;
if ( V_377 -> V_208 )
V_396 = & V_399 ;
V_29 = F_182 ( sizeof( * V_23 ) , V_396 , V_377 -> V_390 ) ;
if ( ! V_29 ) {
F_65 ( V_137 L_46 ) ;
V_307 = - V_313 ;
goto V_400;
}
V_23 = V_29 -> V_69 ;
V_23 -> V_29 = V_29 ;
V_23 -> V_64 = F_183 ( V_401 , NULL , 0 , V_29 , L_47 , V_149 ) ;
if ( F_184 ( V_23 -> V_64 ) ) {
F_65 ( V_137
L_48 ,
F_185 ( V_23 -> V_64 ) ) ;
V_307 = - V_313 ;
goto V_402;
}
V_23 -> V_64 -> V_403 = & V_404 . V_403 ;
V_307 = F_186 ( V_23 -> V_64 ) ;
if ( V_307 != 0 ) {
F_65 ( V_137 L_49 ,
V_307 ) ;
goto V_405;
}
F_187 ( & V_23 -> V_129 ) ;
F_188 ( V_29 , V_23 -> V_64 ) ;
memset ( V_8 , 0 , V_38 ) ;
V_8 [ 0 ] = 0x02 ;
V_8 [ 3 ] = V_149 >> 8 ;
V_8 [ 4 ] = V_149 ;
memcpy ( V_23 -> V_139 [ 0 ] . V_8 , V_8 , V_38 ) ;
memcpy ( V_23 -> V_139 [ 1 ] . V_8 , V_8 , V_38 ) ;
V_23 -> V_139 [ 1 ] . V_8 [ 0 ] |= 0x40 ;
V_29 -> V_30 -> V_406 = 2 ;
V_29 -> V_30 -> V_139 = V_23 -> V_139 ;
V_23 -> V_343 = V_377 -> V_343 ;
V_23 -> V_208 = V_377 -> V_208 ;
V_23 -> V_149 = V_149 ;
V_23 -> V_407 = V_377 -> V_407 ;
if ( V_80 )
V_23 -> V_408 = V_80 -> V_371 ;
if ( V_23 -> V_208 ) {
V_29 -> V_30 -> V_409 = 255 ;
V_29 -> V_30 -> V_410 = V_411 ;
V_29 -> V_30 -> V_412 = 1000 ;
V_29 -> V_30 -> V_413 = 1 ;
V_29 -> V_30 -> V_414 = & V_23 -> V_415 ;
if ( V_377 -> V_387 )
V_23 -> V_415 = V_416 [ 0 ] ;
else
V_23 -> V_415 = V_417 [ 0 ] ;
V_23 -> V_415 . V_418 = V_23 -> V_343 ;
} else if ( V_377 -> V_387 ) {
V_29 -> V_30 -> V_414 = V_416 ;
V_29 -> V_30 -> V_413 =
F_99 ( V_416 ) ;
} else {
V_29 -> V_30 -> V_414 = V_417 ;
V_29 -> V_30 -> V_413 = F_99 ( V_417 ) ;
}
F_189 ( & V_23 -> V_358 , F_158 ) ;
F_189 ( & V_23 -> V_334 , F_145 ) ;
V_29 -> V_330 = 5 ;
V_29 -> V_419 = 4 ;
V_29 -> V_30 -> V_420 = F_77 ( V_421 ) |
F_77 ( V_227 ) |
F_77 ( V_422 ) |
F_77 ( V_423 ) |
F_77 ( V_229 ) |
F_77 ( V_228 ) ;
if ( V_377 -> V_387 )
V_29 -> V_30 -> V_420 |= F_77 ( V_424 ) ;
V_29 -> V_78 = V_425 |
V_426 |
V_427 |
V_428 |
V_429 |
V_430 |
V_431 ;
if ( V_432 )
V_29 -> V_78 |= V_210 ;
V_29 -> V_30 -> V_78 |= V_433 |
V_434 |
V_435 |
V_436 ;
V_29 -> V_30 -> V_437 |= V_438 |
V_439 |
V_440 |
V_441 |
V_442 ;
V_29 -> V_443 = sizeof( struct V_3 ) ;
V_29 -> V_444 = sizeof( struct V_12 ) ;
V_29 -> V_445 = sizeof( struct V_17 ) ;
memcpy ( V_23 -> V_446 , V_447 ,
sizeof( V_447 ) ) ;
memcpy ( V_23 -> V_448 , V_449 ,
sizeof( V_449 ) ) ;
memcpy ( V_23 -> V_151 , V_450 , sizeof( V_450 ) ) ;
for ( V_179 = V_451 ; V_179 < V_452 ; V_179 ++ ) {
struct V_453 * V_454 = & V_23 -> V_455 [ V_179 ] ;
switch ( V_179 ) {
case V_451 :
V_454 -> V_343 = V_23 -> V_446 ;
V_454 -> V_341 = F_99 ( V_447 ) ;
V_454 -> V_456 = V_23 -> V_151 ;
V_454 -> V_457 = F_99 ( V_450 ) ;
break;
case V_458 :
V_454 -> V_343 = V_23 -> V_448 ;
V_454 -> V_341 = F_99 ( V_449 ) ;
V_454 -> V_456 = V_23 -> V_151 + 4 ;
V_454 -> V_457 = F_99 ( V_450 ) - 4 ;
break;
default:
continue;
}
V_454 -> V_459 . V_460 = true ;
V_454 -> V_459 . V_461 = V_462 |
V_463 |
V_464 |
V_465 |
V_466 ;
V_454 -> V_459 . V_467 = 0x3 ;
V_454 -> V_459 . V_468 = 0x6 ;
memset ( & V_454 -> V_459 . V_469 , 0 ,
sizeof( V_454 -> V_459 . V_469 ) ) ;
V_454 -> V_459 . V_469 . V_470 [ 0 ] = 0xff ;
V_454 -> V_459 . V_469 . V_470 [ 1 ] = 0xff ;
V_454 -> V_459 . V_469 . V_471 = V_472 ;
V_29 -> V_30 -> V_455 [ V_179 ] = V_454 ;
V_454 -> V_473 . V_474 = true ;
V_454 -> V_473 . V_461 =
V_475 |
V_476 |
V_477 |
V_478 |
V_479 |
V_480 |
V_481 |
V_482 |
V_483 |
V_484 |
V_485 ;
V_454 -> V_473 . V_486 . V_487 =
F_16 ( V_488 << 0 |
V_488 << 2 |
V_489 << 4 |
V_488 << 6 |
V_488 << 8 |
V_489 << 10 |
V_489 << 12 |
V_488 << 14 ) ;
V_454 -> V_473 . V_486 . V_490 =
V_454 -> V_473 . V_486 . V_487 ;
}
V_23 -> V_62 = 1 ;
F_190 ( & V_23 -> V_339 ) ;
V_29 -> V_491 = 4 ;
V_29 -> V_492 = 11 ;
if ( V_377 -> V_385 )
V_29 -> V_30 -> V_493 |= V_494 ;
if ( V_377 -> V_382 ) {
V_23 -> V_382 = V_377 -> V_382 ;
V_29 -> V_30 -> V_493 |= V_495 ;
F_191 ( V_29 -> V_30 , V_377 -> V_382 ) ;
F_192 ( 1 ) ;
}
if ( V_377 -> V_496 )
V_29 -> V_78 |= V_497 ;
V_307 = F_193 ( V_29 ) ;
if ( V_307 < 0 ) {
F_65 ( V_137 L_50 ,
V_307 ) ;
goto V_498;
}
F_13 ( V_29 -> V_30 , L_51 , V_29 -> V_30 -> V_499 ) ;
if ( V_377 -> V_380 ) {
V_23 -> V_500 [ 0 ] = V_377 -> V_380 [ 0 ] ;
V_23 -> V_500 [ 1 ] = V_377 -> V_380 [ 1 ] ;
F_194 ( V_29 -> V_30 , V_377 -> V_380 ) ;
}
V_23 -> V_501 = F_195 ( L_52 , V_29 -> V_30 -> V_502 ) ;
F_196 ( L_53 , 0666 , V_23 -> V_501 , V_23 , & V_503 ) ;
F_196 ( L_54 , 0666 , V_23 -> V_501 , V_23 ,
& V_504 ) ;
if ( ! V_23 -> V_208 )
F_196 ( L_55 , 0222 ,
V_23 -> V_501 ,
V_23 , & V_505 ) ;
F_197 ( & V_23 -> V_214 ,
F_115 ,
V_506 , V_239 ) ;
F_180 ( & V_194 ) ;
F_198 ( & V_23 -> V_507 , & V_508 ) ;
F_181 ( & V_194 ) ;
if ( V_149 > 0 )
F_177 ( V_149 , V_80 , V_377 ) ;
return V_149 ;
V_498:
F_199 ( V_23 -> V_64 ) ;
V_405:
F_200 ( V_23 -> V_64 ) ;
V_402:
F_201 ( V_29 ) ;
V_400:
return V_307 ;
}
static void F_202 ( int V_375 , const char * V_390 ,
struct V_370 * V_80 )
{
struct V_24 * V_25 ;
void * V_23 ;
int V_118 ;
V_25 = F_63 ( V_133 , V_374 ) ;
if ( ! V_25 )
return;
V_23 = F_64 ( V_25 , 0 , 0 , & V_135 , 0 ,
V_509 ) ;
if ( ! V_23 )
goto error;
V_118 = F_67 ( V_25 , V_378 , V_375 ) ;
if ( V_118 < 0 )
goto error;
V_118 = F_66 ( V_25 , V_391 , strlen ( V_390 ) ,
V_390 ) ;
if ( V_118 < 0 )
goto error;
F_69 ( V_25 , V_23 ) ;
F_171 ( V_25 , V_80 ) ;
return;
error:
F_72 ( V_25 ) ;
}
static void F_203 ( struct V_22 * V_23 ,
const char * V_390 ,
struct V_370 * V_80 )
{
F_202 ( V_23 -> V_149 , V_390 , V_80 ) ;
F_204 ( V_23 -> V_501 ) ;
F_205 ( V_23 -> V_29 ) ;
F_199 ( V_23 -> V_64 ) ;
F_200 ( V_23 -> V_64 ) ;
F_201 ( V_23 -> V_29 ) ;
}
static int F_206 ( struct V_24 * V_25 ,
struct V_22 * V_23 ,
T_5 V_408 , T_5 V_510 ,
struct V_511 * V_111 , int V_78 )
{
void * V_45 ;
struct V_376 V_377 = { } ;
int V_512 = - V_513 ;
V_45 = F_64 ( V_25 , V_408 , V_510 , & V_135 , V_78 ,
V_514 ) ;
if ( ! V_45 )
return - V_513 ;
if ( V_111 )
F_207 ( V_111 , V_45 , & V_135 ) ;
if ( V_23 -> V_500 [ 0 ] && V_23 -> V_500 [ 1 ] )
V_377 . V_380 = V_23 -> V_500 ;
V_377 . V_385 = ! ! ( V_23 -> V_29 -> V_30 -> V_493 &
V_494 ) ;
V_377 . V_387 = ! ! ( V_23 -> V_29 -> V_30 -> V_420 &
F_77 ( V_424 ) ) ;
V_377 . V_208 = V_23 -> V_208 ;
V_377 . V_382 = V_23 -> V_382 ;
V_377 . V_343 = V_23 -> V_343 ;
V_377 . V_390 = F_208 ( V_23 -> V_29 -> V_30 ) ;
V_512 = F_175 ( V_25 , V_23 -> V_149 , & V_377 ) ;
if ( V_512 < 0 )
goto V_393;
F_69 ( V_25 , V_45 ) ;
return 0 ;
V_393:
F_178 ( V_25 , V_45 ) ;
return V_512 ;
}
static void F_209 ( void )
{
struct V_22 * V_23 ;
F_180 ( & V_194 ) ;
while ( ( V_23 = F_210 ( & V_508 ,
struct V_22 ,
V_507 ) ) ) {
F_211 ( & V_23 -> V_507 ) ;
F_181 ( & V_194 ) ;
F_203 ( V_23 , F_208 ( V_23 -> V_29 -> V_30 ) ,
NULL ) ;
F_180 ( & V_194 ) ;
}
F_181 ( & V_194 ) ;
F_212 ( V_401 ) ;
}
static void F_213 ( struct V_63 * V_64 )
{
V_64 -> V_515 = & V_516 ;
V_64 -> V_517 = V_518 ;
F_214 ( V_64 ) ;
V_64 -> V_519 = 0 ;
V_64 -> type = V_520 ;
memset ( V_64 -> V_521 , 0 , V_38 ) ;
V_64 -> V_521 [ 0 ] = 0x12 ;
}
static struct V_22 * F_215 ( const T_1 * V_8 )
{
struct V_22 * V_23 ;
bool V_522 = false ;
F_180 ( & V_194 ) ;
F_89 (data, &hwsim_radios, list) {
if ( memcmp ( V_23 -> V_139 [ 1 ] . V_8 , V_8 , V_38 ) == 0 ) {
V_522 = true ;
break;
}
}
F_181 ( & V_194 ) ;
if ( ! V_522 )
return NULL ;
return V_23 ;
}
static int F_216 ( struct V_24 * V_523 ,
struct V_370 * V_80 )
{
struct V_44 * V_45 ;
struct V_22 * V_173 ;
struct V_79 * V_206 ;
struct V_126 * V_127 ;
unsigned long V_524 ;
struct V_24 * V_25 , * V_525 ;
const T_1 * V_526 ;
unsigned int V_124 ;
int V_125 ;
bool V_527 = false ;
if ( V_80 -> V_371 != V_212 )
return - V_59 ;
if ( ! V_80 -> V_528 [ V_138 ] ||
! V_80 -> V_528 [ V_146 ] ||
! V_80 -> V_528 [ V_154 ] ||
! V_80 -> V_528 [ V_153 ] )
goto V_238;
V_526 = ( void * ) F_217 ( V_80 -> V_528 [ V_138 ] ) ;
V_124 = F_134 ( V_80 -> V_528 [ V_146 ] ) ;
V_524 = F_218 ( V_80 -> V_528 [ V_154 ] ) ;
V_173 = F_215 ( V_526 ) ;
if ( ! V_173 )
goto V_238;
F_219 (&data2->pending, skb, tmp) {
if ( ( unsigned long ) V_25 == V_524 ) {
F_220 ( V_25 , & V_173 -> V_129 ) ;
V_527 = true ;
break;
}
}
if ( ! V_527 )
goto V_238;
V_127 = (struct V_126 * ) F_217 (
V_80 -> V_528 [ V_153 ] ) ;
V_206 = F_46 ( V_25 ) ;
F_101 ( V_206 ) ;
for ( V_125 = 0 ; V_125 < V_128 ; V_125 ++ ) {
V_206 -> V_150 . V_151 [ V_125 ] . V_149 = V_127 [ V_125 ] . V_149 ;
V_206 -> V_150 . V_151 [ V_125 ] . V_152 = V_127 [ V_125 ] . V_152 ;
}
V_206 -> V_150 . V_529 = F_134 ( V_80 -> V_528 [ V_530 ] ) ;
if ( ! ( V_124 & V_145 ) &&
( V_124 & V_531 ) ) {
if ( V_25 -> V_141 >= 16 ) {
V_45 = (struct V_44 * ) V_25 -> V_23 ;
F_55 ( V_173 -> V_148 ,
V_45 -> V_50 ) ;
}
V_206 -> V_78 |= V_213 ;
}
F_102 ( V_173 -> V_29 , V_25 ) ;
return 0 ;
V_238:
return - V_59 ;
}
static int F_221 ( struct V_24 * V_523 ,
struct V_370 * V_80 )
{
struct V_22 * V_173 ;
struct V_175 V_176 ;
const T_1 * V_532 ;
int V_533 ;
void * V_534 ;
struct V_24 * V_25 = NULL ;
if ( V_80 -> V_371 != V_212 )
return - V_59 ;
if ( ! V_80 -> V_528 [ V_535 ] ||
! V_80 -> V_528 [ V_140 ] ||
! V_80 -> V_528 [ V_536 ] ||
! V_80 -> V_528 [ V_530 ] )
goto V_238;
V_532 = ( void * ) F_217 ( V_80 -> V_528 [ V_535 ] ) ;
V_533 = F_222 ( V_80 -> V_528 [ V_140 ] ) ;
V_534 = ( void * ) F_217 ( V_80 -> V_528 [ V_140 ] ) ;
V_25 = F_223 ( V_533 , V_374 ) ;
if ( V_25 == NULL )
goto V_307;
if ( V_533 > V_411 )
goto V_307;
memcpy ( F_15 ( V_25 , V_533 ) , V_534 , V_533 ) ;
V_173 = F_215 ( V_532 ) ;
if ( ! V_173 )
goto V_238;
if ( V_173 -> V_197 || ! V_173 -> V_196 )
goto V_238;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_176 . V_178 = V_173 -> V_148 -> V_99 ;
V_176 . V_179 = V_173 -> V_148 -> V_179 ;
V_176 . V_182 = F_134 ( V_80 -> V_528 [ V_536 ] ) ;
V_176 . signal = F_134 ( V_80 -> V_528 [ V_530 ] ) ;
memcpy ( F_78 ( V_25 ) , & V_176 , sizeof( V_176 ) ) ;
V_173 -> V_203 ++ ;
V_173 -> V_204 += V_25 -> V_141 ;
F_95 ( V_173 -> V_29 , V_25 ) ;
return 0 ;
V_307:
F_65 ( V_137 L_5 , V_31 ) ;
V_238:
F_34 ( V_25 ) ;
return - V_59 ;
}
static int F_224 ( struct V_24 * V_523 ,
struct V_370 * V_80 )
{
struct V_22 * V_23 ;
int V_537 = 1 ;
F_180 ( & V_194 ) ;
F_89 (data, &hwsim_radios, list)
V_537 = F_225 ( V_537 , V_23 -> V_343 ) ;
F_181 ( & V_194 ) ;
if ( V_537 > 1 )
return - V_316 ;
if ( V_212 )
return - V_354 ;
V_212 = V_80 -> V_371 ;
F_65 ( V_137 L_56
L_57 , V_80 -> V_371 ) ;
return 0 ;
}
static int F_226 ( struct V_24 * V_538 , struct V_370 * V_80 )
{
struct V_376 V_377 = { 0 } ;
V_377 . V_385 = V_80 -> V_528 [ V_386 ] ;
V_377 . V_387 = V_80 -> V_528 [ V_388 ] ;
V_377 . V_343 = V_343 ;
V_377 . V_407 =
V_80 -> V_528 [ V_539 ] ;
if ( V_80 -> V_528 [ V_379 ] )
V_377 . V_343 = F_134 ( V_80 -> V_528 [ V_379 ] ) ;
if ( V_80 -> V_528 [ V_540 ] )
V_377 . V_496 = true ;
if ( V_80 -> V_528 [ V_391 ] )
V_377 . V_390 = F_217 ( V_80 -> V_528 [ V_391 ] ) ;
if ( V_80 -> V_528 [ V_389 ] )
V_377 . V_208 = true ;
else
V_377 . V_208 = ( V_377 . V_343 > 1 ) ;
if ( V_80 -> V_528 [ V_381 ] )
V_377 . V_380 =
F_217 ( V_80 -> V_528 [ V_381 ] ) ;
if ( V_80 -> V_528 [ V_384 ] ) {
T_5 V_149 = F_134 ( V_80 -> V_528 [ V_384 ] ) ;
if ( V_149 >= F_99 ( V_383 ) )
return - V_59 ;
V_377 . V_382 = V_383 [ V_149 ] ;
}
return F_179 ( V_80 , & V_377 ) ;
}
static int F_227 ( struct V_24 * V_538 , struct V_370 * V_80 )
{
struct V_22 * V_23 ;
T_8 V_149 = - 1 ;
const char * V_390 = NULL ;
if ( V_80 -> V_528 [ V_378 ] )
V_149 = F_134 ( V_80 -> V_528 [ V_378 ] ) ;
else if ( V_80 -> V_528 [ V_391 ] )
V_390 = ( void * ) F_217 ( V_80 -> V_528 [ V_391 ] ) ;
else
return - V_59 ;
F_180 ( & V_194 ) ;
F_89 (data, &hwsim_radios, list) {
if ( V_149 >= 0 ) {
if ( V_23 -> V_149 != V_149 )
continue;
} else {
if ( strcmp ( V_390 , F_208 ( V_23 -> V_29 -> V_30 ) ) )
continue;
}
F_211 ( & V_23 -> V_507 ) ;
F_181 ( & V_194 ) ;
F_203 ( V_23 , F_208 ( V_23 -> V_29 -> V_30 ) ,
V_80 ) ;
return 0 ;
}
F_181 ( & V_194 ) ;
return - V_541 ;
}
static int F_228 ( struct V_24 * V_538 , struct V_370 * V_80 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
int V_149 , V_512 = - V_541 ;
if ( ! V_80 -> V_528 [ V_378 ] )
return - V_59 ;
V_149 = F_134 ( V_80 -> V_528 [ V_378 ] ) ;
F_180 ( & V_194 ) ;
F_89 (data, &hwsim_radios, list) {
if ( V_23 -> V_149 != V_149 )
continue;
V_25 = F_229 ( V_542 , V_374 ) ;
if ( ! V_25 ) {
V_512 = - V_313 ;
goto V_393;
}
V_512 = F_206 ( V_25 , V_23 , V_80 -> V_371 ,
V_80 -> V_543 , NULL , 0 ) ;
if ( V_512 < 0 ) {
F_72 ( V_25 ) ;
goto V_393;
}
F_230 ( V_25 , V_80 ) ;
break;
}
V_393:
F_181 ( & V_194 ) ;
return V_512 ;
}
static int F_231 ( struct V_24 * V_25 ,
struct V_511 * V_111 )
{
int V_149 = V_111 -> args [ 0 ] ;
struct V_22 * V_23 = NULL ;
int V_512 ;
F_180 ( & V_194 ) ;
if ( V_149 == V_398 )
goto V_544;
F_89 (data, &hwsim_radios, list) {
if ( V_23 -> V_149 < V_149 )
continue;
V_512 = F_206 ( V_25 , V_23 ,
F_232 ( V_111 -> V_25 ) . V_408 ,
V_111 -> V_545 -> V_546 , V_111 ,
V_547 ) ;
if ( V_512 < 0 )
break;
V_149 = V_23 -> V_149 + 1 ;
}
V_111 -> args [ 0 ] = V_149 ;
V_544:
F_181 ( & V_194 ) ;
return V_25 -> V_141 ;
}
static void F_233 ( struct V_332 * V_333 )
{
struct V_22 * V_23 =
F_116 ( V_333 , struct V_22 , V_548 ) ;
F_203 ( V_23 , F_208 ( V_23 -> V_29 -> V_30 ) , NULL ) ;
}
static void F_234 ( T_5 V_408 )
{
struct V_22 * V_549 , * V_525 ;
F_180 ( & V_194 ) ;
F_235 (entry, tmp, &hwsim_radios, list) {
if ( V_549 -> V_407 && V_549 -> V_408 == V_408 ) {
F_211 ( & V_549 -> V_507 ) ;
F_236 ( & V_549 -> V_548 , F_233 ) ;
F_237 ( & V_549 -> V_548 ) ;
}
}
F_181 ( & V_194 ) ;
}
static int F_238 ( struct V_550 * V_551 ,
unsigned long V_552 ,
void * V_553 )
{
struct V_554 * V_555 = V_553 ;
if ( V_552 != V_556 )
return V_557 ;
F_234 ( V_555 -> V_408 ) ;
if ( V_555 -> V_408 == V_212 ) {
F_65 ( V_558 L_58
L_59 ) ;
V_212 = 0 ;
}
return V_557 ;
}
static int F_239 ( void )
{
int V_559 ;
F_65 ( V_558 L_60 ) ;
V_559 = F_240 ( & V_135 ,
V_560 ,
V_561 ) ;
if ( V_559 )
goto V_562;
V_559 = F_241 ( & V_563 ) ;
if ( V_559 )
goto V_562;
return 0 ;
V_562:
F_65 ( V_137 L_5 , V_31 ) ;
return - V_59 ;
}
static void F_242 ( void )
{
F_243 ( & V_563 ) ;
F_244 ( & V_135 ) ;
}
static int T_9 F_245 ( void )
{
int V_125 , V_307 ;
if ( V_564 < 0 || V_564 > 100 )
return - V_59 ;
if ( V_343 < 1 )
return - V_59 ;
V_399 = V_397 ;
V_399 . V_334 = F_152 ;
V_399 . V_565 = F_154 ;
V_399 . V_566 = NULL ;
V_399 . V_567 = NULL ;
V_399 . V_568 = F_160 ;
V_399 . V_569 = F_162 ;
V_399 . V_570 = F_163 ;
V_399 . V_571 = F_164 ;
V_399 . V_572 = F_165 ;
V_399 . V_573 =
F_166 ;
V_399 . V_574 =
F_167 ;
F_246 ( & V_194 ) ;
F_247 ( & V_508 ) ;
V_307 = F_248 ( & V_404 ) ;
if ( V_307 )
return V_307 ;
V_401 = F_249 ( V_575 , L_61 ) ;
if ( F_184 ( V_401 ) ) {
V_307 = F_185 ( V_401 ) ;
goto V_576;
}
V_307 = F_239 () ;
if ( V_307 < 0 )
goto V_576;
for ( V_125 = 0 ; V_125 < V_564 ; V_125 ++ ) {
struct V_376 V_377 = { 0 } ;
V_377 . V_343 = V_343 ;
switch ( V_577 ) {
case V_578 :
if ( V_125 < F_99 ( V_579 ) )
V_377 . V_380 = V_579 [ V_125 ] ;
break;
case V_580 :
if ( ! V_125 )
V_377 . V_380 = V_579 [ 0 ] ;
break;
case V_581 :
V_377 . V_385 = true ;
case V_582 :
V_377 . V_380 = V_579 [ 0 ] ;
break;
case V_583 :
if ( V_125 == 0 )
V_377 . V_382 = & V_584 ;
break;
case V_585 :
V_377 . V_382 = & V_584 ;
break;
case V_586 :
if ( V_125 == 0 )
V_377 . V_382 = & V_584 ;
else if ( V_125 == 1 )
V_377 . V_382 = & V_587 ;
break;
case V_588 :
if ( V_125 == 0 ) {
V_377 . V_385 = true ;
V_377 . V_380 = V_579 [ 0 ] ;
}
break;
case V_589 :
if ( V_125 == 0 ) {
V_377 . V_385 = true ;
V_377 . V_380 = V_579 [ 0 ] ;
} else if ( V_125 == 1 ) {
V_377 . V_380 = V_579 [ 1 ] ;
}
break;
case V_590 :
switch ( V_125 ) {
case 0 :
V_377 . V_382 = & V_584 ;
break;
case 1 :
V_377 . V_382 = & V_587 ;
break;
case 2 :
V_377 . V_380 = V_579 [ 0 ] ;
break;
case 3 :
V_377 . V_380 = V_579 [ 1 ] ;
break;
case 4 :
V_377 . V_385 = true ;
V_377 . V_380 = V_579 [ 2 ] ;
break;
}
break;
default:
break;
}
V_377 . V_387 = V_591 ;
V_377 . V_208 = V_343 > 1 ;
V_307 = F_179 ( NULL , & V_377 ) ;
if ( V_307 < 0 )
goto V_592;
}
V_83 = F_250 ( 0 , L_47 , V_593 ,
F_213 ) ;
if ( V_83 == NULL ) {
V_307 = - V_313 ;
goto V_592;
}
F_251 () ;
V_307 = F_252 ( V_83 , V_83 -> V_594 ) ;
if ( V_307 < 0 ) {
F_253 () ;
goto V_592;
}
V_307 = F_254 ( V_83 ) ;
if ( V_307 < 0 ) {
F_253 () ;
goto V_595;
}
F_253 () ;
return 0 ;
V_595:
V_518 ( V_83 ) ;
V_592:
F_209 () ;
V_576:
F_255 ( & V_404 ) ;
return V_307 ;
}
static void T_10 F_256 ( void )
{
F_65 ( V_137 L_62 ) ;
F_242 () ;
F_209 () ;
F_257 ( V_83 ) ;
F_255 ( & V_404 ) ;
}
