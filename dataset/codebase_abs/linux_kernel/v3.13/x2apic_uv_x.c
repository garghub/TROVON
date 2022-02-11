static unsigned long T_1 F_1 ( unsigned long V_1 )
{
unsigned long V_2 , * V_3 ;
V_3 = F_2 ( V_4 | V_1 , sizeof( * V_3 ) ) ;
V_2 = * V_3 ;
F_3 ( V_3 , sizeof( * V_3 ) ) ;
return V_2 ;
}
static inline bool F_4 ( T_2 V_5 , T_2 V_6 )
{
if ( V_7 ) {
T_2 V_8 = V_5 & V_9 ;
T_2 V_10 = V_5 & V_11 ;
T_2 V_12 = V_6 & V_9 ;
T_2 V_13 = V_6 & V_11 ;
return ( V_10 == V_7 && V_13 == V_7 &&
V_8 >= V_14 &&
V_8 <= V_15 &&
V_12 == V_8 ) ;
} else {
return V_5 >= V_16 && V_6 <= V_17 ;
}
}
static bool F_5 ( T_2 V_5 , T_2 V_6 )
{
return F_6 ( V_5 , V_6 ) || F_4 ( V_5 , V_6 ) ;
}
static int T_1 F_7 ( void )
{
union V_18 V_19 ;
union V_20 V_21 ;
int V_22 ;
V_19 . V_23 = F_1 ( V_24 ) ;
V_21 . V_23 = F_1 ( V_25 ) ;
V_26 = V_19 . V_27 . V_28 ;
switch ( V_19 . V_27 . V_29 ) {
case V_30 :
case V_31 :
V_26 += V_32 - 1 ;
break;
case V_33 :
case V_34 :
V_26 += V_35 ;
break;
}
V_36 -> V_37 = V_26 ;
V_22 = ( V_19 . V_27 . V_19 >> 1 ) & ( ( 1 << V_21 . V_27 . V_38 ) - 1 ) ;
return V_22 ;
}
static void T_1 F_8 ( void )
{
V_39 . V_23 = F_1 ( V_40 ) ;
if ( ! V_39 . V_23 )
V_39 . V_27 . V_41 = V_42 ;
}
static void T_1 F_9 ( void )
{
union V_43 V_44 ;
if ( F_10 () ) {
V_44 . V_23 =
F_1 ( V_45 ) ;
V_46 =
V_44 . V_47 . V_48 & V_49 ;
}
}
static int T_1 F_11 ( char * V_50 , char * V_51 )
{
int V_52 , V_53 , V_54 , V_55 ;
V_53 = ! strcmp ( V_50 , L_1 ) ;
V_54 = ! strcmp ( V_50 , L_2 ) ;
V_55 = ! strncmp ( V_50 , L_3 , 4 ) ;
if ( V_53 || V_54 || V_55 ) {
V_36 -> V_37 =
( V_53 ? V_56 :
( V_54 ? V_32 :
V_35 ) ) ;
V_52 = F_7 () ;
F_8 () ;
V_57 . V_58 = F_5 ;
V_57 . V_59 = V_60 ;
if ( ! strcmp ( V_51 , L_4 ) )
V_61 = V_62 ;
else if ( ! strcmp ( V_51 , L_5 ) )
V_61 = V_63 ;
else if ( ! strcmp ( V_51 , L_6 ) ) {
F_12 ( V_64 ,
V_52 << V_39 . V_27 . V_41 ) ;
V_61 = V_65 ;
F_9 () ;
return 1 ;
}
}
return 0 ;
}
enum V_61 F_13 ( void )
{
return V_61 ;
}
int F_14 ( void )
{
return V_61 != V_66 ;
}
static int F_15 ( int V_67 , unsigned long V_68 )
{
#ifdef F_16
unsigned long V_2 ;
int V_22 ;
V_22 = F_17 ( V_67 ) ;
V_67 |= V_46 ;
V_2 = ( 1UL << V_69 ) |
( V_67 << V_70 ) |
( ( V_68 << V_71 ) >> 12 ) |
V_72 ;
F_18 ( V_22 , V_73 , V_2 ) ;
V_2 = ( 1UL << V_69 ) |
( V_67 << V_70 ) |
( ( V_68 << V_71 ) >> 12 ) |
V_74 ;
F_18 ( V_22 , V_73 , V_2 ) ;
F_19 ( & V_75 , 1 ) ;
#endif
return 0 ;
}
static void F_20 ( int V_76 , int V_77 )
{
unsigned long V_78 ;
int V_22 ;
V_78 = F_21 ( V_79 , V_76 ) ;
V_22 = F_17 ( V_78 ) ;
F_22 ( V_22 , V_78 , V_77 ) ;
}
static void F_23 ( const struct V_80 * V_81 , int V_77 )
{
unsigned int V_76 ;
F_24 (cpu, mask)
F_20 ( V_76 , V_77 ) ;
}
static void F_25 ( const struct V_80 * V_81 , int V_77 )
{
unsigned int V_82 = F_26 () ;
unsigned int V_76 ;
F_24 (cpu, mask) {
if ( V_76 != V_82 )
F_20 ( V_76 , V_77 ) ;
}
}
static void F_27 ( int V_77 )
{
unsigned int V_82 = F_26 () ;
unsigned int V_76 ;
F_28 (cpu) {
if ( V_76 != V_82 )
F_20 ( V_76 , V_77 ) ;
}
}
static void F_29 ( int V_77 )
{
F_23 ( V_83 , V_77 ) ;
}
static int F_30 ( int V_78 )
{
return 1 ;
}
static int F_31 ( void )
{
return 1 ;
}
static void F_32 ( void )
{
}
static int
F_33 ( const struct V_80 * V_80 ,
const struct V_80 * V_84 ,
unsigned int * V_78 )
{
int unsigned V_76 ;
F_34 (cpu, cpumask, andmask) {
if ( F_35 ( V_76 , V_83 ) )
break;
}
if ( F_36 ( V_76 < V_85 ) ) {
* V_78 = F_21 ( V_79 , V_76 ) | V_46 ;
return 0 ;
}
return - V_86 ;
}
static unsigned int F_37 ( unsigned long V_87 )
{
unsigned int V_88 ;
F_38 ( F_39 () && F_40 () > 1 ) ;
V_88 = V_87 | F_41 ( V_64 ) ;
return V_88 ;
}
static unsigned long F_42 ( unsigned int V_88 )
{
unsigned long V_87 ;
V_87 = V_88 ;
return V_87 ;
}
static unsigned int F_43 ( void )
{
return F_37 ( F_44 ( V_89 ) ) ;
}
static int F_45 ( int V_90 , int V_91 )
{
return F_43 () >> V_91 ;
}
static void F_46 ( int V_77 )
{
F_47 ( V_92 , V_77 ) ;
}
static int F_48 ( void )
{
return V_93 == & V_94 ;
}
static void F_49 ( int V_22 )
{
F_12 ( V_64 , V_22 << V_39 . V_27 . V_41 ) ;
}
static T_1 int F_50 ( int V_22 )
{
int V_95 ;
for ( V_95 = 0 ; V_95 < F_51 () ; V_95 ++ )
if ( V_22 == V_96 [ V_95 ] . V_22 )
return V_95 ;
F_52 () ;
}
static T_1 void F_53 ( unsigned long * V_97 , unsigned long * V_98 )
{
union V_99 V_100 ;
union V_101 V_102 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < F_54 ( V_104 ) ; V_103 ++ ) {
V_100 . V_23 = F_55 ( V_104 [ V_103 ] . V_100 ) ;
if ( V_100 . V_27 . V_105 && V_100 . V_27 . V_97 == 0 ) {
* V_98 = ( 1UL << V_100 . V_27 . V_106 ) ;
V_102 . V_23 = F_55 ( V_104 [ V_103 ] . V_102 ) ;
* V_97 = ( unsigned long ) V_102 . V_27 . V_107 << V_108 ;
return;
}
}
* V_97 = * V_98 = 0 ;
}
static T_1 void F_56 ( char * V_88 , unsigned long V_97 , int V_109 ,
int V_110 , int V_111 , enum V_112 V_112 )
{
unsigned long V_113 , V_114 ;
V_114 = V_97 << V_109 ;
V_113 = ( 1UL << V_110 ) * ( V_111 + 1 ) ;
if ( ! V_114 ) {
F_57 ( L_7 , V_88 ) ;
return;
}
F_58 ( L_8 , V_88 , V_114 , V_114 + V_113 ) ;
if ( V_112 == V_115 )
F_59 ( V_114 , V_113 ) ;
else
F_60 ( V_114 , V_113 ) ;
}
static T_1 void F_61 ( unsigned long V_116 )
{
union V_117 V_118 ;
T_2 V_114 ;
unsigned long V_113 ;
int V_119 ;
V_118 . V_23 = V_116 ;
V_7 = V_118 . V_23 & 0x000007fff0000000UL ;
if ( ! V_7 ) {
F_57 ( L_9 ) ;
return;
}
V_113 = 1UL << V_120 ;
V_11 = ( ( 1UL << V_36 -> V_121 ) - 1 ) & ~ ( V_113 - 1 ) ;
V_9 = ~ ( ( 1UL << V_36 -> V_121 ) - 1 ) ;
V_7 &= V_11 ;
F_62 (nid) {
V_114 = ( ( T_2 ) F_63 ( V_119 ) << V_36 -> V_121 ) |
V_7 ;
F_60 ( V_114 , V_113 ) ;
V_14 = F_64 ( V_114 , V_14 ) ;
V_15 = F_65 ( V_114 , V_15 ) ;
}
V_14 &= V_9 ;
V_15 &= V_9 ;
F_58 ( L_10 ,
V_7 , V_14 , V_15 ) ;
}
static T_1 void F_66 ( int V_111 )
{
union V_117 V_118 ;
int V_122 = V_120 ;
V_118 . V_23 = F_55 ( V_123 ) ;
if ( ! V_118 . V_27 . V_105 ) {
F_57 ( L_11 ) ;
return;
}
if ( F_67 () && V_118 . V_124 . V_125 ) {
F_61 ( V_118 . V_23 ) ;
return;
}
F_56 ( L_12 , V_118 . V_27 . V_97 , V_122 , V_122 , V_111 , V_126 ) ;
V_16 = ( ( T_2 ) V_118 . V_27 . V_97 << V_122 ) ;
V_17 = V_16 + ( 1UL << V_122 ) * ( V_111 + 1 ) ;
}
static T_1 void F_68 ( int V_111 )
{
union V_127 V_3 ;
int V_122 = V_128 ;
V_3 . V_23 = F_55 ( V_129 ) ;
if ( V_3 . V_27 . V_105 )
F_56 ( L_13 , V_3 . V_27 . V_97 , V_122 , V_122 , V_111 , V_115 ) ;
else
F_57 ( L_14 ) ;
}
static T_1 void F_69 ( int V_130 , int V_131 , int V_111 )
{
union V_132 V_133 ;
unsigned long V_3 ;
unsigned long V_97 ;
int V_103 , V_134 , V_122 , V_135 , V_136 ;
int V_137 , V_138 , V_139 , V_140 ;
char * V_88 ;
V_88 = V_141 [ V_130 ] . V_88 ;
V_133 . V_23 = F_55 ( V_141 [ V_130 ] . V_133 ) ;
F_57 ( L_15 ,
V_88 , V_133 . V_23 , V_133 . V_124 . V_97 , V_133 . V_124 . V_135 ) ;
if ( ! V_133 . V_124 . V_105 ) {
F_57 ( L_16 , V_88 ) ;
return;
}
V_122 = V_142 ;
V_97 = ( unsigned long ) V_133 . V_124 . V_97 ;
V_135 = V_133 . V_124 . V_135 ;
V_3 = V_141 [ V_130 ] . V_102 ;
V_134 = V_143 ;
V_131 *= 2 ;
V_111 *= 2 ;
V_136 = V_138 = V_139 = V_140 = - 1 ;
for ( V_103 = 0 ; V_103 < V_134 ; V_103 ++ ) {
union V_144 V_102 ;
V_102 . V_23 = F_55 ( V_3 + V_103 * 8 ) ;
V_137 = V_102 . V_124 . V_137 ;
if ( V_137 < V_131 || V_111 < V_137 )
V_137 = - 1 ;
if ( V_137 == V_138 ) {
V_140 = V_103 ;
if ( V_103 != V_134 - 1 )
continue;
}
if ( V_138 != - 1 || ( V_103 == V_134 - 1 && V_137 != - 1 ) ) {
unsigned long V_145 , V_146 ;
int V_147 , V_148 ;
if ( V_138 == - 1 ) {
V_147 = V_148 = V_103 ;
V_138 = V_137 ;
} else {
V_147 = V_139 ;
V_148 = V_140 ;
}
V_145 = ( V_97 << V_122 ) +
V_147 * ( unsigned long ) ( 1 << V_135 ) ;
V_146 = ( V_97 << V_122 ) +
( V_148 + 1 ) * ( unsigned long ) ( 1 << V_135 ) ;
F_57 ( L_17 ,
V_88 , V_139 , V_140 , V_138 , V_145 , V_146 ) ;
if ( V_136 < V_148 )
V_136 = V_148 ;
}
V_139 = V_140 = V_103 ;
V_138 = V_137 ;
}
F_57 ( L_18 ,
V_88 , V_97 , V_122 , V_135 , V_136 ) ;
if ( V_136 >= 0 )
F_56 ( V_88 , V_97 , V_122 , V_135 , V_136 , V_115 ) ;
}
static T_1 void F_70 ( int V_131 , int V_111 )
{
union V_149 V_150 ;
unsigned long V_3 , V_97 ;
int V_122 , V_105 , V_135 , V_151 ;
if ( F_67 () ) {
F_69 ( 0 , V_131 , V_111 ) ;
F_69 ( 1 , V_131 , V_111 ) ;
return;
}
if ( F_10 () ) {
V_3 = V_152 ;
V_122 = V_153 ;
V_150 . V_23 = F_55 ( V_3 ) ;
V_105 = ! ! V_150 . V_47 . V_105 ;
V_97 = V_150 . V_47 . V_97 ;
V_135 = V_150 . V_47 . V_135 ;
V_151 = V_150 . V_47 . V_151 ;
} else if ( F_71 () ) {
V_3 = V_154 ;
V_122 = V_155 ;
V_150 . V_23 = F_55 ( V_3 ) ;
V_105 = ! ! V_150 . V_156 . V_105 ;
V_97 = V_150 . V_156 . V_97 ;
V_135 = V_150 . V_156 . V_135 ;
V_151 = V_150 . V_156 . V_151 ;
} else
return;
if ( V_105 ) {
V_111 &= ( 1 << V_151 ) - 1 ;
F_57 (
L_19 ,
V_97 , V_122 , V_135 , V_151 , V_111 ) ;
F_56 ( L_20 , V_97 , V_122 , V_135 , V_111 , V_115 ) ;
} else {
F_57 ( L_21 ) ;
}
}
static T_1 void F_72 ( void )
{
F_59 ( V_157 , V_158 ) ;
F_59 ( V_4 , V_159 ) ;
}
static T_1 void F_73 ( void )
{
long V_160 ;
T_2 V_161 ;
V_160 = F_74 ( V_162 ,
& V_161 ) ;
if ( V_160 != V_163 || V_161 < 100000 ) {
F_75 ( V_164
L_22
L_23 ) ;
V_165 = 1000000000000UL / 30000UL ;
} else
V_165 = V_161 ;
}
static void F_76 ( unsigned long V_166 )
{
struct V_167 * V_168 = & V_36 -> V_169 . V_168 ;
unsigned char V_170 = V_36 -> V_169 . V_171 ;
V_170 ^= V_172 ;
if ( F_77 ( F_78 () ) )
V_170 &= ~ V_173 ;
else
V_170 |= V_173 ;
F_79 ( V_170 ) ;
F_80 ( V_168 , V_174 + V_175 ) ;
}
static void F_81 ( int V_76 )
{
while ( ! F_82 ( V_76 ) -> V_169 . V_176 ) {
struct V_167 * V_168 = & F_82 ( V_76 ) -> V_169 . V_168 ;
F_83 ( V_76 , V_172 | V_173 ) ;
F_84 ( V_168 , F_76 , V_76 ) ;
V_168 -> V_177 = V_174 + V_175 ;
F_85 ( V_168 , V_76 ) ;
F_82 ( V_76 ) -> V_169 . V_176 = 1 ;
V_76 = 0 ;
}
}
static void F_86 ( int V_76 )
{
if ( F_82 ( V_76 ) -> V_169 . V_176 ) {
F_82 ( V_76 ) -> V_169 . V_176 = 0 ;
F_87 ( & F_82 ( V_76 ) -> V_169 . V_168 ) ;
}
F_83 ( V_76 , 0xff ) ;
}
static int F_88 ( struct V_178 * V_179 , unsigned long V_180 ,
void * V_181 )
{
long V_76 = ( long ) V_181 ;
switch ( V_180 ) {
case V_182 :
F_81 ( V_76 ) ;
break;
case V_183 :
F_86 ( V_76 ) ;
break;
default:
break;
}
return V_184 ;
}
static T_1 void F_89 ( void )
{
F_90 ( F_88 , 0 ) ;
}
static T_1 void F_89 ( void )
{
}
static T_1 int F_91 ( void )
{
int V_76 ;
if ( F_14 () )
F_28 (cpu)
F_81 ( V_76 ) ;
return 0 ;
}
int F_92 ( struct V_185 * V_186 , bool V_187 ,
unsigned int V_188 , T_3 V_189 )
{
int V_190 , V_191 , V_192 ;
F_93 ( L_24 ,
V_186 -> V_193 , V_187 , V_188 , V_189 ) ;
if ( ! ( V_189 & V_194 ) )
return 0 ;
if ( ( V_188 & V_195 ) == 0 )
return 0 ;
V_190 = F_94 ( V_186 -> V_191 ) ;
V_191 = V_186 -> V_191 -> V_196 ;
V_192 = F_95 ( V_187 , V_190 , V_191 ) ;
F_93 ( L_25 , V_187 , V_190 , V_191 , V_192 ) ;
return V_192 ;
}
void F_96 ( void )
{
if ( ! V_96 )
return;
V_96 [ F_97 () ] . V_197 ++ ;
if ( F_13 () == V_65 )
F_49 ( V_36 -> V_22 ) ;
}
void T_1 F_98 ( void )
{
union V_20 V_21 ;
union V_18 V_19 ;
unsigned long V_198 , V_199 , V_200 ;
int V_113 , V_119 , V_76 , V_201 , V_22 , V_95 , V_103 , V_202 , V_121 , V_203 ;
int V_204 , V_131 = 999999 , V_111 = - 1 ;
unsigned long V_205 , V_206 , V_114 ;
unsigned short V_207 ;
char * V_208 = ( F_10 () ? L_26 :
( F_71 () ? L_27 :
L_28 ) ) ;
F_57 ( L_29 , V_208 ) ;
F_72 () ;
V_21 . V_23 = F_55 ( V_25 ) ;
V_121 = V_21 . V_27 . V_209 ;
V_203 = V_21 . V_27 . V_38 ;
V_207 = ( 1 << V_203 ) - 1 ;
V_205 =
F_55 ( V_129 ) &
~ V_210 ;
V_19 . V_23 = F_55 ( V_24 ) ;
V_204 = ( V_19 . V_27 . V_19 & ~ ( ( 1 << V_203 ) - 1 ) ) >> 1 ;
V_198 = ( ( unsigned long ) V_204 << V_121 ) ;
F_57 ( L_30 ,
V_203 , V_121 , V_207 , V_198 , V_204 ) ;
F_57 ( L_31 , V_205 ) ;
for( V_103 = 0 ; V_103 < V_211 ; V_103 ++ )
V_212 +=
F_99 ( F_55 ( V_213 + V_103 * 8 ) ) ;
F_57 ( L_32 ,
F_10 () ? F_51 () :
( F_51 () + 1 ) / 2 ,
F_51 () ) ;
V_113 = sizeof( struct V_96 ) * F_51 () ;
V_96 = F_100 ( V_113 , V_214 ) ;
F_101 ( ! V_96 ) ;
for ( V_95 = 0 ; V_95 < F_51 () ; V_95 ++ )
V_96 [ V_95 ] . V_215 = - 1 ;
F_53 ( & V_199 , & V_200 ) ;
V_113 = sizeof( V_216 [ 0 ] ) * F_102 () ;
V_216 = F_103 ( V_113 , V_214 ) ;
F_101 ( ! V_216 ) ;
memset ( V_216 , 255 , V_113 ) ;
V_113 = sizeof( V_217 [ 0 ] ) * F_104 () ;
V_217 = F_103 ( V_113 , V_214 ) ;
F_101 ( ! V_217 ) ;
memset ( V_217 , 255 , V_113 ) ;
V_95 = 0 ;
for ( V_103 = 0 ; V_103 < V_211 ; V_103 ++ ) {
V_206 = F_55 ( V_213 + V_103 * 8 ) ;
for ( V_202 = 0 ; V_202 < 64 ; V_202 ++ ) {
if ( ! F_105 ( V_202 , & V_206 ) )
continue;
V_22 = ( V_103 * 64 + V_202 ) & V_207 ;
V_96 [ V_95 ] . V_22 = V_22 ;
V_96 [ V_95 ] . V_218 = 0 ;
V_96 [ V_95 ] . V_197 = 0 ;
F_106 ( & V_96 [ V_95 ] . V_219 ) ;
V_131 = F_64 ( V_22 , V_131 ) ;
V_111 = F_65 ( V_22 , V_111 ) ;
V_95 ++ ;
}
}
F_107 () ;
F_108 ( 0 , & V_220 , & V_221 , & V_222 ,
& V_223 , & V_224 ) ;
F_73 () ;
F_109 (cpu) {
int V_78 = F_21 ( V_79 , V_76 ) ;
V_119 = F_110 ( V_76 ) ;
F_82 ( V_76 ) -> V_207 = V_207 ;
F_82 ( V_76 ) -> V_225 = V_39 . V_27 . V_41 ;
F_82 ( V_76 ) -> V_37 = V_36 -> V_37 ;
F_82 ( V_76 ) -> V_226 = 64 - V_121 ;
F_82 ( V_76 ) -> V_227 = F_111 () ?
( V_121 == 40 ? 40 : 39 ) : V_121 ;
V_22 = F_17 ( V_78 ) ;
V_95 = F_50 ( V_22 ) ;
V_201 = V_96 [ V_95 ] . V_218 ;
V_96 [ V_95 ] . V_218 ++ ;
V_96 [ V_95 ] . V_215 = V_119 ;
F_82 ( V_76 ) -> V_228 = V_199 ;
F_82 ( V_76 ) -> V_229 = V_200 ;
F_82 ( V_76 ) -> V_121 = V_121 ;
F_82 ( V_76 ) -> V_203 = V_203 ;
F_82 ( V_76 ) -> V_230 = V_95 ;
F_82 ( V_76 ) -> V_231 = V_201 ;
F_82 ( V_76 ) -> V_22 = V_22 ;
F_82 ( V_76 ) -> V_232 = ( 1UL << ( V_121 + V_203 ) ) - 1 ;
F_82 ( V_76 ) -> V_198 = V_198 ;
F_82 ( V_76 ) -> V_204 = V_204 ;
F_82 ( V_76 ) -> V_233 = V_205 ;
F_82 ( V_76 ) -> V_234 = V_222 ;
F_82 ( V_76 ) -> V_169 . V_235 = F_112 ( V_78 ) ;
V_216 [ V_119 ] = V_95 ;
V_217 [ V_76 ] = V_95 ;
}
F_62 (nid) {
if ( V_216 [ V_119 ] >= 0 )
continue;
V_114 = F_113 ( V_119 ) << V_236 ;
V_22 = F_114 ( F_115 ( V_114 ) ) ;
V_95 = F_50 ( V_22 ) ;
V_216 [ V_119 ] = V_95 ;
}
F_66 ( V_111 ) ;
F_68 ( V_111 ) ;
F_70 ( V_131 , V_111 ) ;
F_116 () ;
F_96 () ;
F_89 () ;
F_117 () ;
F_118 ( L_33 , NULL ) ;
F_119 ( F_92 ) ;
if ( F_120 () )
V_237 = V_238 ;
}
