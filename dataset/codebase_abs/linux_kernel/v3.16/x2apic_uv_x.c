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
static unsigned char F_53 ( int V_97 )
{
union V_98 V_99 ;
if ( F_10 () )
return V_97 ;
if ( F_54 () )
return V_97 == 40 ? 40 : 39 ;
V_99 . V_23 = F_55 ( V_100 ) ;
return V_99 . V_101 . V_102 ;
}
static T_1 void F_56 ( unsigned long * V_103 , unsigned long * V_104 )
{
union V_105 V_106 ;
union V_107 V_108 ;
int V_109 ;
for ( V_109 = 0 ; V_109 < F_57 ( V_110 ) ; V_109 ++ ) {
V_106 . V_23 = F_55 ( V_110 [ V_109 ] . V_106 ) ;
if ( V_106 . V_27 . V_111 && V_106 . V_27 . V_103 == 0 ) {
* V_104 = ( 1UL << V_106 . V_27 . V_112 ) ;
V_108 . V_23 = F_55 ( V_110 [ V_109 ] . V_108 ) ;
* V_103 = ( unsigned long ) V_108 . V_27 . V_113 << V_114 ;
return;
}
}
* V_103 = * V_104 = 0 ;
}
static T_1 void F_58 ( char * V_88 , unsigned long V_103 , int V_115 ,
int V_116 , int V_117 , enum V_118 V_118 )
{
unsigned long V_119 , V_120 ;
V_120 = V_103 << V_115 ;
V_119 = ( 1UL << V_116 ) * ( V_117 + 1 ) ;
if ( ! V_120 ) {
F_59 ( L_7 , V_88 ) ;
return;
}
F_60 ( L_8 , V_88 , V_120 , V_120 + V_119 ) ;
if ( V_118 == V_121 )
F_61 ( V_120 , V_119 ) ;
else
F_62 ( V_120 , V_119 ) ;
}
static T_1 void F_63 ( unsigned long V_122 )
{
union V_123 V_124 ;
T_2 V_120 ;
unsigned long V_119 ;
int V_125 ;
V_124 . V_23 = V_122 ;
V_7 = V_124 . V_23 & 0x000007fff0000000UL ;
if ( ! V_7 ) {
F_59 ( L_9 ) ;
return;
}
V_119 = 1UL << V_126 ;
V_11 = ( ( 1UL << V_36 -> V_97 ) - 1 ) & ~ ( V_119 - 1 ) ;
V_9 = ~ ( ( 1UL << V_36 -> V_97 ) - 1 ) ;
V_7 &= V_11 ;
F_64 (nid) {
V_120 = ( ( T_2 ) F_65 ( V_125 ) << V_36 -> V_97 ) |
V_7 ;
F_62 ( V_120 , V_119 ) ;
V_14 = F_66 ( V_120 , V_14 ) ;
V_15 = F_67 ( V_120 , V_15 ) ;
}
V_14 &= V_9 ;
V_15 &= V_9 ;
F_60 ( L_10 ,
V_7 , V_14 , V_15 ) ;
}
static T_1 void F_68 ( int V_117 )
{
union V_123 V_124 ;
int V_127 = V_126 ;
V_124 . V_23 = F_55 ( V_128 ) ;
if ( ! V_124 . V_27 . V_111 ) {
F_59 ( L_11 ) ;
return;
}
if ( F_69 () && V_124 . V_101 . V_129 ) {
F_63 ( V_124 . V_23 ) ;
return;
}
F_58 ( L_12 , V_124 . V_27 . V_103 , V_127 , V_127 , V_117 , V_130 ) ;
V_16 = ( ( T_2 ) V_124 . V_27 . V_103 << V_127 ) ;
V_17 = V_16 + ( 1UL << V_127 ) * ( V_117 + 1 ) ;
}
static T_1 void F_70 ( int V_117 )
{
union V_131 V_3 ;
int V_127 = V_132 ;
V_3 . V_23 = F_55 ( V_133 ) ;
if ( V_3 . V_27 . V_111 )
F_58 ( L_13 , V_3 . V_27 . V_103 , V_127 , V_127 , V_117 , V_121 ) ;
else
F_59 ( L_14 ) ;
}
static T_1 void F_71 ( int V_134 , int V_135 , int V_117 )
{
union V_136 V_137 ;
unsigned long V_3 ;
unsigned long V_103 ;
int V_109 , V_138 , V_127 , V_139 , V_140 ;
int V_141 , V_142 , V_143 , V_144 ;
char * V_88 ;
V_88 = V_145 [ V_134 ] . V_88 ;
V_137 . V_23 = F_55 ( V_145 [ V_134 ] . V_137 ) ;
F_59 ( L_15 ,
V_88 , V_137 . V_23 , V_137 . V_101 . V_103 , V_137 . V_101 . V_139 ) ;
if ( ! V_137 . V_101 . V_111 ) {
F_59 ( L_16 , V_88 ) ;
return;
}
V_127 = V_146 ;
V_103 = ( unsigned long ) V_137 . V_101 . V_103 ;
V_139 = V_137 . V_101 . V_139 ;
V_3 = V_145 [ V_134 ] . V_108 ;
V_138 = V_147 ;
V_135 *= 2 ;
V_117 *= 2 ;
V_140 = V_142 = V_143 = V_144 = - 1 ;
for ( V_109 = 0 ; V_109 < V_138 ; V_109 ++ ) {
union V_148 V_108 ;
V_108 . V_23 = F_55 ( V_3 + V_109 * 8 ) ;
V_141 = V_108 . V_101 . V_141 ;
if ( V_141 < V_135 || V_117 < V_141 )
V_141 = - 1 ;
if ( V_141 == V_142 ) {
V_144 = V_109 ;
if ( V_109 != V_138 - 1 )
continue;
}
if ( V_142 != - 1 || ( V_109 == V_138 - 1 && V_141 != - 1 ) ) {
unsigned long V_149 , V_150 ;
int V_151 , V_152 ;
if ( V_142 == - 1 ) {
V_151 = V_152 = V_109 ;
V_142 = V_141 ;
} else {
V_151 = V_143 ;
V_152 = V_144 ;
}
V_149 = ( V_103 << V_127 ) +
V_151 * ( unsigned long ) ( 1 << V_139 ) ;
V_150 = ( V_103 << V_127 ) +
( V_152 + 1 ) * ( unsigned long ) ( 1 << V_139 ) ;
F_59 ( L_17 ,
V_88 , V_143 , V_144 , V_142 , V_149 , V_150 ) ;
if ( V_140 < V_152 )
V_140 = V_152 ;
}
V_143 = V_144 = V_109 ;
V_142 = V_141 ;
}
F_59 ( L_18 ,
V_88 , V_103 , V_127 , V_139 , V_140 ) ;
if ( V_140 >= 0 )
F_58 ( V_88 , V_103 , V_127 , V_139 , V_140 , V_121 ) ;
}
static T_1 void F_72 ( int V_135 , int V_117 )
{
union V_153 V_154 ;
unsigned long V_3 , V_103 ;
int V_127 , V_111 , V_139 , V_155 ;
if ( F_69 () ) {
F_71 ( 0 , V_135 , V_117 ) ;
F_71 ( 1 , V_135 , V_117 ) ;
return;
}
if ( F_10 () ) {
V_3 = V_156 ;
V_127 = V_157 ;
V_154 . V_23 = F_55 ( V_3 ) ;
V_111 = ! ! V_154 . V_47 . V_111 ;
V_103 = V_154 . V_47 . V_103 ;
V_139 = V_154 . V_47 . V_139 ;
V_155 = V_154 . V_47 . V_155 ;
} else if ( F_54 () ) {
V_3 = V_158 ;
V_127 = V_159 ;
V_154 . V_23 = F_55 ( V_3 ) ;
V_111 = ! ! V_154 . V_160 . V_111 ;
V_103 = V_154 . V_160 . V_103 ;
V_139 = V_154 . V_160 . V_139 ;
V_155 = V_154 . V_160 . V_155 ;
} else
return;
if ( V_111 ) {
V_117 &= ( 1 << V_155 ) - 1 ;
F_59 (
L_19 ,
V_103 , V_127 , V_139 , V_155 , V_117 ) ;
F_58 ( L_20 , V_103 , V_127 , V_139 , V_117 , V_121 ) ;
} else {
F_59 ( L_21 ) ;
}
}
static T_1 void F_73 ( void )
{
F_61 ( V_161 , V_162 ) ;
F_61 ( V_4 , V_163 ) ;
}
static T_1 void F_74 ( void )
{
long V_164 ;
T_2 V_165 ;
V_164 = F_75 ( V_166 ,
& V_165 ) ;
if ( V_164 != V_167 || V_165 < 100000 ) {
F_76 ( V_168
L_22
L_23 ) ;
V_169 = 1000000000000UL / 30000UL ;
} else
V_169 = V_165 ;
}
static void F_77 ( unsigned long V_170 )
{
struct V_171 * V_172 = & V_36 -> V_173 . V_172 ;
unsigned char V_174 = V_36 -> V_173 . V_175 ;
V_174 ^= V_176 ;
if ( F_78 ( F_79 () ) )
V_174 &= ~ V_177 ;
else
V_174 |= V_177 ;
F_80 ( V_174 ) ;
F_81 ( V_172 , V_178 + V_179 ) ;
}
static void F_82 ( int V_76 )
{
while ( ! F_83 ( V_76 ) -> V_173 . V_180 ) {
struct V_171 * V_172 = & F_83 ( V_76 ) -> V_173 . V_172 ;
F_84 ( V_76 , V_176 | V_177 ) ;
F_85 ( V_172 , F_77 , V_76 ) ;
V_172 -> V_181 = V_178 + V_179 ;
F_86 ( V_172 , V_76 ) ;
F_83 ( V_76 ) -> V_173 . V_180 = 1 ;
V_76 = 0 ;
}
}
static void F_87 ( int V_76 )
{
if ( F_83 ( V_76 ) -> V_173 . V_180 ) {
F_83 ( V_76 ) -> V_173 . V_180 = 0 ;
F_88 ( & F_83 ( V_76 ) -> V_173 . V_172 ) ;
}
F_84 ( V_76 , 0xff ) ;
}
static int F_89 ( struct V_182 * V_183 , unsigned long V_184 ,
void * V_185 )
{
long V_76 = ( long ) V_185 ;
switch ( V_184 ) {
case V_186 :
F_82 ( V_76 ) ;
break;
case V_187 :
F_87 ( V_76 ) ;
break;
default:
break;
}
return V_188 ;
}
static T_1 void F_90 ( void )
{
F_91 ( F_89 , 0 ) ;
}
static T_1 void F_90 ( void )
{
}
static T_1 int F_92 ( void )
{
int V_76 ;
if ( F_14 () )
F_28 (cpu)
F_82 ( V_76 ) ;
return 0 ;
}
int F_93 ( struct V_189 * V_190 , bool V_191 ,
unsigned int V_192 , T_3 V_193 )
{
int V_194 , V_195 , V_196 ;
F_94 ( L_24 ,
V_190 -> V_197 , V_191 , V_192 , V_193 ) ;
if ( ! ( V_193 & V_198 ) )
return 0 ;
if ( ( V_192 & V_199 ) == 0 )
return 0 ;
V_194 = F_95 ( V_190 -> V_195 ) ;
V_195 = V_190 -> V_195 -> V_200 ;
V_196 = F_96 ( V_191 , V_194 , V_195 ) ;
F_94 ( L_25 , V_191 , V_194 , V_195 , V_196 ) ;
return V_196 ;
}
void F_97 ( void )
{
if ( ! V_96 )
return;
V_96 [ F_98 () ] . V_201 ++ ;
if ( F_13 () == V_65 )
F_49 ( V_36 -> V_22 ) ;
}
void T_1 F_99 ( void )
{
union V_20 V_21 ;
union V_18 V_19 ;
unsigned long V_202 , V_203 , V_204 ;
int V_119 , V_125 , V_76 , V_205 , V_22 , V_95 , V_109 , V_206 , V_97 , V_207 ;
int V_208 , V_135 = 999999 , V_117 = - 1 ;
unsigned long V_209 , V_210 , V_120 ;
unsigned short V_211 ;
unsigned char V_212 ;
char * V_213 = ( F_10 () ? L_26 :
( F_54 () ? L_27 :
L_28 ) ) ;
F_59 ( L_29 , V_213 ) ;
F_73 () ;
V_21 . V_23 = F_55 ( V_25 ) ;
V_97 = V_21 . V_27 . V_102 ;
V_207 = V_21 . V_27 . V_38 ;
V_211 = ( 1 << V_207 ) - 1 ;
V_212 = F_53 ( V_97 ) ;
V_209 =
F_55 ( V_133 ) &
~ V_214 ;
V_19 . V_23 = F_55 ( V_24 ) ;
V_208 = ( V_19 . V_27 . V_19 & ~ ( ( 1 << V_207 ) - 1 ) ) >> 1 ;
V_202 = ( ( unsigned long ) V_208 << V_97 ) ;
F_59 ( L_30 ,
V_207 , V_97 , V_211 , V_202 , V_208 ,
V_212 ) ;
F_59 ( L_31 , V_209 ) ;
for( V_109 = 0 ; V_109 < V_215 ; V_109 ++ )
V_216 +=
F_100 ( F_55 ( V_217 + V_109 * 8 ) ) ;
F_59 ( L_32 ,
F_10 () ? F_51 () :
( F_51 () + 1 ) / 2 ,
F_51 () ) ;
V_119 = sizeof( struct V_96 ) * F_51 () ;
V_96 = F_101 ( V_119 , V_218 ) ;
F_102 ( ! V_96 ) ;
for ( V_95 = 0 ; V_95 < F_51 () ; V_95 ++ )
V_96 [ V_95 ] . V_219 = - 1 ;
F_56 ( & V_203 , & V_204 ) ;
V_119 = sizeof( V_220 [ 0 ] ) * F_103 () ;
V_220 = F_104 ( V_119 , V_218 ) ;
F_102 ( ! V_220 ) ;
memset ( V_220 , 255 , V_119 ) ;
V_119 = sizeof( V_221 [ 0 ] ) * F_105 () ;
V_221 = F_104 ( V_119 , V_218 ) ;
F_102 ( ! V_221 ) ;
memset ( V_221 , 255 , V_119 ) ;
V_95 = 0 ;
for ( V_109 = 0 ; V_109 < V_215 ; V_109 ++ ) {
V_210 = F_55 ( V_217 + V_109 * 8 ) ;
for ( V_206 = 0 ; V_206 < 64 ; V_206 ++ ) {
if ( ! F_106 ( V_206 , & V_210 ) )
continue;
V_22 = ( V_109 * 64 + V_206 ) & V_211 ;
V_96 [ V_95 ] . V_22 = V_22 ;
V_96 [ V_95 ] . V_222 = 0 ;
V_96 [ V_95 ] . V_201 = 0 ;
F_107 ( & V_96 [ V_95 ] . V_223 ) ;
V_135 = F_66 ( V_22 , V_135 ) ;
V_117 = F_67 ( V_22 , V_117 ) ;
V_95 ++ ;
}
}
F_108 () ;
F_109 ( 0 , & V_224 , & V_225 , & V_226 ,
& V_227 , & V_228 ) ;
F_74 () ;
F_110 (cpu) {
int V_78 = F_21 ( V_79 , V_76 ) ;
V_125 = F_111 ( V_76 ) ;
F_83 ( V_76 ) -> V_211 = V_211 ;
F_83 ( V_76 ) -> V_229 = V_39 . V_27 . V_41 ;
F_83 ( V_76 ) -> V_37 = V_36 -> V_37 ;
F_83 ( V_76 ) -> V_230 = 64 - V_97 ;
F_83 ( V_76 ) -> V_212 = V_212 ;
V_22 = F_17 ( V_78 ) ;
V_95 = F_50 ( V_22 ) ;
V_205 = V_96 [ V_95 ] . V_222 ;
V_96 [ V_95 ] . V_222 ++ ;
V_96 [ V_95 ] . V_219 = V_125 ;
F_83 ( V_76 ) -> V_231 = V_203 ;
F_83 ( V_76 ) -> V_232 = V_204 ;
F_83 ( V_76 ) -> V_97 = V_97 ;
F_83 ( V_76 ) -> V_207 = V_207 ;
F_83 ( V_76 ) -> V_233 = V_95 ;
F_83 ( V_76 ) -> V_234 = V_205 ;
F_83 ( V_76 ) -> V_22 = V_22 ;
F_83 ( V_76 ) -> V_235 = ( 1UL << ( V_97 + V_207 ) ) - 1 ;
F_83 ( V_76 ) -> V_202 = V_202 ;
F_83 ( V_76 ) -> V_208 = V_208 ;
F_83 ( V_76 ) -> V_236 = V_209 ;
F_83 ( V_76 ) -> V_237 = V_226 ;
F_83 ( V_76 ) -> V_173 . V_238 = F_112 ( V_78 ) ;
V_220 [ V_125 ] = V_95 ;
V_221 [ V_76 ] = V_95 ;
}
F_64 (nid) {
if ( V_220 [ V_125 ] >= 0 )
continue;
V_120 = F_113 ( V_125 ) << V_239 ;
V_22 = F_114 ( F_115 ( V_120 ) ) ;
V_95 = F_50 ( V_22 ) ;
V_220 [ V_125 ] = V_95 ;
}
F_68 ( V_117 ) ;
F_70 ( V_117 ) ;
F_72 ( V_135 , V_117 ) ;
F_116 () ;
F_97 () ;
F_90 () ;
F_117 ( L_33 , NULL ) ;
F_118 ( F_93 ) ;
if ( F_119 () )
V_240 = V_241 ;
}
