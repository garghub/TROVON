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
return V_5 >= V_7 && V_6 <= V_8 ;
}
static bool F_5 ( T_2 V_5 , T_2 V_6 )
{
return F_6 ( V_5 , V_6 ) || F_4 ( V_5 , V_6 ) ;
}
static int T_1 F_7 ( void )
{
union V_9 V_10 ;
union V_11 V_12 ;
int V_13 ;
V_10 . V_14 = F_1 ( V_15 ) ;
V_12 . V_14 = F_1 ( V_16 ) ;
V_17 = V_10 . V_18 . V_19 ;
if ( V_10 . V_18 . V_20 == V_21 )
V_17 += V_22 - 1 ;
if ( V_10 . V_18 . V_20 == V_23 )
V_17 += V_22 - 1 ;
V_24 -> V_25 = V_17 ;
V_13 = ( V_10 . V_18 . V_10 >> 1 ) & ( ( 1 << V_12 . V_18 . V_26 ) - 1 ) ;
return V_13 ;
}
static void T_1 F_8 ( void )
{
V_27 . V_14 = F_1 ( V_28 ) ;
if ( ! V_27 . V_14 )
V_27 . V_18 . V_29 = V_30 ;
}
static void T_1 F_9 ( void )
{
union V_31 V_32 ;
if ( F_10 () ) {
V_32 . V_14 =
F_1 ( V_33 ) ;
V_34 =
V_32 . V_35 . V_36 & V_37 ;
}
}
static int T_1 F_11 ( char * V_38 , char * V_39 )
{
int V_40 , V_41 , V_42 ;
V_41 = ! strcmp ( V_38 , L_1 ) ;
V_42 = ! strcmp ( V_38 , L_2 ) ;
if ( V_41 || V_42 ) {
V_24 -> V_25 =
V_41 ? V_43 : V_22 ;
V_40 = F_7 () ;
F_8 () ;
V_44 . V_45 = F_5 ;
V_44 . V_46 = V_47 ;
if ( ! strcmp ( V_39 , L_3 ) )
V_48 = V_49 ;
else if ( ! strcmp ( V_39 , L_4 ) )
V_48 = V_50 ;
else if ( ! strcmp ( V_39 , L_5 ) ) {
F_12 ( V_51 ,
V_40 << V_27 . V_18 . V_29 ) ;
V_48 = V_52 ;
F_9 () ;
return 1 ;
}
}
return 0 ;
}
enum V_48 F_13 ( void )
{
return V_48 ;
}
int F_14 ( void )
{
return V_48 != V_53 ;
}
static const struct V_54 * F_15 ( void )
{
return V_55 ;
}
static void F_16 ( int V_56 , struct V_54 * V_57 )
{
F_17 ( V_57 ) ;
F_18 ( V_56 , V_57 ) ;
}
static int T_3 F_19 ( int V_58 , unsigned long V_59 )
{
#ifdef F_20
unsigned long V_2 ;
int V_13 ;
V_13 = F_21 ( V_58 ) ;
V_58 |= V_34 ;
V_2 = ( 1UL << V_60 ) |
( V_58 << V_61 ) |
( ( V_59 << V_62 ) >> 12 ) |
V_63 ;
F_22 ( V_13 , V_64 , V_2 ) ;
V_2 = ( 1UL << V_60 ) |
( V_58 << V_61 ) |
( ( V_59 << V_62 ) >> 12 ) |
V_65 ;
F_22 ( V_13 , V_64 , V_2 ) ;
F_23 ( & V_66 , 1 ) ;
#endif
return 0 ;
}
static void F_24 ( int V_56 , int V_67 )
{
unsigned long V_68 ;
int V_13 ;
V_68 = F_25 ( V_69 , V_56 ) ;
V_13 = F_21 ( V_68 ) ;
F_26 ( V_13 , V_68 , V_67 ) ;
}
static void F_27 ( const struct V_54 * V_70 , int V_67 )
{
unsigned int V_56 ;
F_28 (cpu, mask)
F_24 ( V_56 , V_67 ) ;
}
static void F_29 ( const struct V_54 * V_70 , int V_67 )
{
unsigned int V_71 = F_30 () ;
unsigned int V_56 ;
F_28 (cpu, mask) {
if ( V_56 != V_71 )
F_24 ( V_56 , V_67 ) ;
}
}
static void F_31 ( int V_67 )
{
unsigned int V_71 = F_30 () ;
unsigned int V_56 ;
F_32 (cpu) {
if ( V_56 != V_71 )
F_24 ( V_56 , V_67 ) ;
}
}
static void F_33 ( int V_67 )
{
F_27 ( V_55 , V_67 ) ;
}
static int F_34 ( int V_68 )
{
return 1 ;
}
static int F_35 ( void )
{
return 1 ;
}
static void F_36 ( void )
{
}
static unsigned int F_37 ( const struct V_54 * V_54 )
{
int V_56 = F_38 ( V_54 ) ;
if ( ( unsigned ) V_56 < V_72 )
return F_25 ( V_69 , V_56 ) | V_34 ;
else
return V_73 ;
}
static unsigned int
F_39 ( const struct V_54 * V_54 ,
const struct V_54 * V_74 )
{
int V_56 ;
F_40 (cpu, cpumask, andmask) {
if ( F_41 ( V_56 , V_55 ) )
break;
}
return F_25 ( V_69 , V_56 ) | V_34 ;
}
static unsigned int F_42 ( unsigned long V_75 )
{
unsigned int V_76 ;
F_43 ( F_44 () && F_45 () > 1 ) ;
V_76 = V_75 | F_46 ( V_51 ) ;
return V_76 ;
}
static unsigned long F_47 ( unsigned int V_76 )
{
unsigned long V_75 ;
V_75 = V_76 ;
return V_75 ;
}
static unsigned int F_48 ( void )
{
return F_42 ( F_49 ( V_77 ) ) ;
}
static int F_50 ( int V_78 , int V_79 )
{
return F_48 () >> V_79 ;
}
static void F_51 ( int V_67 )
{
F_52 ( V_80 , V_67 ) ;
}
static int F_53 ( void )
{
return V_81 == & V_82 ;
}
static T_3 void F_54 ( int V_13 )
{
F_12 ( V_51 , V_13 << V_27 . V_18 . V_29 ) ;
}
static T_1 int F_55 ( int V_13 )
{
int V_83 ;
for ( V_83 = 0 ; V_83 < F_56 () ; V_83 ++ )
if ( V_13 == V_84 [ V_83 ] . V_13 )
return V_83 ;
F_57 () ;
}
static T_1 void F_58 ( unsigned long * V_85 , unsigned long * V_86 )
{
union V_87 V_88 ;
union V_89 V_90 ;
int V_91 ;
for ( V_91 = 0 ; V_91 < F_59 ( V_92 ) ; V_91 ++ ) {
V_88 . V_14 = F_60 ( V_92 [ V_91 ] . V_88 ) ;
if ( V_88 . V_18 . V_93 && V_88 . V_18 . V_85 == 0 ) {
* V_86 = ( 1UL << V_88 . V_18 . V_94 ) ;
V_90 . V_14 = F_60 ( V_92 [ V_91 ] . V_90 ) ;
* V_85 = ( unsigned long ) V_90 . V_18 . V_95 << V_96 ;
return;
}
}
* V_85 = * V_86 = 0 ;
}
static T_1 void F_61 ( char * V_76 , unsigned long V_85 , int V_97 ,
int V_98 , int V_99 , enum V_100 V_100 )
{
unsigned long V_101 , V_102 ;
V_102 = V_85 << V_97 ;
V_101 = ( 1UL << V_98 ) * ( V_99 + 1 ) ;
F_62 ( V_103 L_6 , V_76 , V_102 ,
V_102 + V_101 ) ;
if ( V_100 == V_104 )
F_63 ( V_102 , V_101 ) ;
else
F_64 ( V_102 , V_101 ) ;
}
static T_1 void F_65 ( int V_99 )
{
union V_105 V_106 ;
int V_107 = V_108 ;
V_106 . V_14 = F_60 ( V_109 ) ;
if ( V_106 . V_18 . V_93 ) {
F_61 ( L_7 , V_106 . V_18 . V_85 , V_107 , V_107 , V_99 , V_110 ) ;
V_7 = ( ( T_2 ) V_106 . V_18 . V_85 << V_107 ) ;
V_8 = V_7 + ( 1UL << V_107 ) * ( V_99 + 1 ) ;
}
}
static T_1 void F_66 ( int V_99 )
{
union V_111 V_3 ;
int V_107 = V_112 ;
V_3 . V_14 = F_60 ( V_113 ) ;
if ( V_3 . V_18 . V_93 )
F_61 ( L_8 , V_3 . V_18 . V_85 , V_107 , V_107 , V_99 , V_104 ) ;
}
static T_1 void F_67 ( int V_99 )
{
union V_114 V_115 ;
int V_107 ;
V_115 . V_14 = F_60 ( V_116 ) ;
if ( F_10 () && V_115 . V_35 . V_93 ) {
V_107 = V_117 ;
F_61 ( L_9 , V_115 . V_35 . V_85 , V_107 , V_115 . V_35 . V_118 ,
V_99 , V_104 ) ;
}
if ( F_68 () && V_115 . V_119 . V_93 ) {
V_107 = V_120 ;
F_61 ( L_9 , V_115 . V_119 . V_85 , V_107 , V_115 . V_119 . V_118 ,
V_99 , V_104 ) ;
}
}
static T_1 void F_69 ( void )
{
F_63 ( V_121 , V_122 ) ;
F_63 ( V_4 , V_123 ) ;
}
static T_1 void F_70 ( void )
{
long V_124 ;
T_2 V_125 ;
V_124 = F_71 ( V_126 ,
& V_125 ) ;
if ( V_124 != V_127 || V_125 < 100000 ) {
F_62 ( V_128
L_10
L_11 ) ;
V_129 = 1000000000000UL / 30000UL ;
} else
V_129 = V_125 ;
}
static void F_72 ( unsigned long V_130 )
{
struct V_131 * V_132 = & V_24 -> V_133 . V_132 ;
unsigned char V_134 = V_24 -> V_133 . V_135 ;
V_134 ^= V_136 ;
if ( F_73 ( F_74 () ) )
V_134 &= ~ V_137 ;
else
V_134 |= V_137 ;
F_75 ( V_134 ) ;
F_76 ( V_132 , V_138 + V_139 ) ;
}
static void T_3 F_77 ( int V_56 )
{
while ( ! F_78 ( V_56 ) -> V_133 . V_140 ) {
struct V_131 * V_132 = & F_78 ( V_56 ) -> V_133 . V_132 ;
F_79 ( V_56 , V_136 | V_137 ) ;
F_80 ( V_132 , F_72 , V_56 ) ;
V_132 -> V_141 = V_138 + V_139 ;
F_81 ( V_132 , V_56 ) ;
F_78 ( V_56 ) -> V_133 . V_140 = 1 ;
V_56 = 0 ;
}
}
static void T_3 F_82 ( int V_56 )
{
if ( F_78 ( V_56 ) -> V_133 . V_140 ) {
F_78 ( V_56 ) -> V_133 . V_140 = 0 ;
F_83 ( & F_78 ( V_56 ) -> V_133 . V_132 ) ;
}
F_79 ( V_56 , 0xff ) ;
}
static T_3 int F_84 ( struct V_142 * V_143 ,
unsigned long V_144 , void * V_145 )
{
long V_56 = ( long ) V_145 ;
switch ( V_144 ) {
case V_146 :
F_77 ( V_56 ) ;
break;
case V_147 :
F_82 ( V_56 ) ;
break;
default:
break;
}
return V_148 ;
}
static T_1 void F_85 ( void )
{
F_86 ( F_84 , 0 ) ;
}
static T_1 void F_85 ( void )
{
}
static T_1 int F_87 ( void )
{
int V_56 ;
if ( F_14 () )
F_32 (cpu)
F_77 ( V_56 ) ;
return 0 ;
}
int F_88 ( struct V_149 * V_150 , bool V_151 ,
unsigned int V_152 , T_4 V_153 )
{
int V_154 , V_155 , V_156 ;
F_89 ( L_12 ,
V_150 -> V_157 , V_151 , V_152 , V_153 ) ;
if ( ! ( V_153 & V_158 ) )
return 0 ;
if ( ( V_152 & V_159 ) == 0 )
return 0 ;
V_154 = F_90 ( V_150 -> V_155 ) ;
V_155 = V_150 -> V_155 -> V_160 ;
V_156 = F_91 ( V_151 , V_154 , V_155 ) ;
F_89 ( L_13 , V_151 , V_154 , V_155 , V_156 ) ;
return V_156 ;
}
void T_3 F_92 ( void )
{
if ( ! V_84 )
return;
V_84 [ F_93 () ] . V_161 ++ ;
if ( F_13 () == V_52 )
F_54 ( V_24 -> V_13 ) ;
}
int F_94 ( unsigned int V_162 , struct V_163 * V_164 )
{
unsigned long V_165 ;
int V_166 ;
V_166 = F_93 () ;
V_165 = ( F_60 ( V_167 ) & V_168 ) ;
if ( F_95 ( V_165 ) ) {
F_96 ( & V_84 [ V_166 ] . V_169 ) ;
V_165 = ( F_60 ( V_167 ) & V_168 ) ;
if ( V_165 ) {
V_84 [ V_166 ] . V_170 ++ ;
F_97 ( V_171 , V_168 ) ;
}
F_98 ( & V_84 [ V_166 ] . V_169 ) ;
}
if ( F_99 ( F_100 ( V_172 ) == V_84 [ V_166 ] . V_170 ) )
return V_173 ;
F_100 ( V_172 ) = V_84 [ V_166 ] . V_170 ;
F_96 ( & V_174 ) ;
F_101 ( L_14 , F_30 () ) ;
F_102 () ;
F_98 ( & V_174 ) ;
return V_175 ;
}
void F_103 ( void )
{
if ( F_104 ( V_176 , F_94 , 0 , L_15 ) )
F_62 ( V_128 L_16 ) ;
}
void V_47 ( void )
{
unsigned int V_177 ;
V_177 = F_49 ( V_178 ) | V_179 ;
V_177 &= ~ V_180 ;
F_52 ( V_178 , V_177 ) ;
}
void T_1 F_105 ( void )
{
union V_11 V_12 ;
union V_114 V_115 ;
union V_9 V_10 ;
unsigned long V_181 , V_182 , V_183 ;
int V_101 , V_184 , V_56 , V_185 , V_13 , V_83 , V_91 , V_186 , V_187 , V_188 , V_189 ;
int V_190 , V_99 = 0 ;
unsigned long V_191 , V_192 , V_102 ;
unsigned short V_193 , V_194 ;
F_62 ( V_103 L_17 , F_10 () ? L_18 : L_19 ) ;
F_69 () ;
V_12 . V_14 = F_60 ( V_16 ) ;
V_187 = V_12 . V_18 . V_195 ;
V_188 = V_12 . V_18 . V_26 ;
V_115 . V_14 = F_60 ( V_116 ) ;
V_189 = F_10 () ? V_115 . V_35 . V_189 : V_115 . V_119 . V_189 ;
V_191 =
F_60 ( V_113 ) &
~ V_196 ;
V_193 = ( 1 << V_188 ) - 1 ;
V_194 = ( 1 << V_189 ) - 1 ;
V_10 . V_14 = F_60 ( V_15 ) ;
V_190 = ( V_10 . V_18 . V_10 & ~ ( ( 1 << V_188 ) - 1 ) ) >> 1 ;
V_181 = ( ( unsigned long ) V_190 << V_187 ) ;
F_62 ( V_103 L_20 ,
V_188 , V_187 , V_189 , V_181 , V_190 , V_193 , V_194 ) ;
F_62 ( V_197 L_21 , V_191 ) ;
for( V_91 = 0 ; V_91 < V_198 ; V_91 ++ )
V_199 +=
F_106 ( F_60 ( V_200 + V_91 * 8 ) ) ;
F_62 ( V_103 L_22 ,
F_10 () ? F_56 () :
( F_56 () + 1 ) / 2 ,
F_56 () ) ;
V_101 = sizeof( struct V_84 ) * F_56 () ;
V_84 = F_107 ( V_101 , V_201 ) ;
F_108 ( ! V_84 ) ;
for ( V_83 = 0 ; V_83 < F_56 () ; V_83 ++ )
V_84 [ V_83 ] . V_202 = - 1 ;
F_58 ( & V_182 , & V_183 ) ;
V_101 = sizeof( V_203 [ 0 ] ) * F_109 () ;
V_203 = F_110 ( V_101 , V_201 ) ;
F_108 ( ! V_203 ) ;
memset ( V_203 , 255 , V_101 ) ;
V_101 = sizeof( V_204 [ 0 ] ) * F_111 () ;
V_204 = F_110 ( V_101 , V_201 ) ;
F_108 ( ! V_204 ) ;
memset ( V_204 , 255 , V_101 ) ;
V_83 = 0 ;
for ( V_91 = 0 ; V_91 < V_198 ; V_91 ++ ) {
V_192 = F_60 ( V_200 + V_91 * 8 ) ;
for ( V_186 = 0 ; V_186 < 64 ; V_186 ++ ) {
if ( ! F_112 ( V_186 , & V_192 ) )
continue;
V_13 = ( V_91 * 64 + V_186 ) & V_193 ;
V_84 [ V_83 ] . V_13 = V_13 ;
V_84 [ V_83 ] . V_205 = 0 ;
V_84 [ V_83 ] . V_161 = 0 ;
F_113 ( & V_84 [ V_83 ] . V_169 ) ;
V_99 = F_114 ( V_13 , V_99 ) ;
V_83 ++ ;
}
}
F_115 () ;
F_116 ( 0 , & V_206 , & V_207 , & V_208 ,
& V_209 , & V_210 ) ;
F_70 () ;
F_117 (cpu) {
int V_68 = F_25 ( V_69 , V_56 ) ;
V_184 = F_118 ( V_56 ) ;
F_78 ( V_56 ) -> V_193 = V_193 ;
F_78 ( V_56 ) -> V_211 = V_27 . V_18 . V_29 ;
F_78 ( V_56 ) -> V_25 = V_24 -> V_25 ;
F_78 ( V_56 ) -> V_212 = 64 - V_187 ;
F_78 ( V_56 ) -> V_213 = F_119 () ?
( V_187 == 40 ? 40 : 39 ) : V_187 ;
V_13 = F_21 ( V_68 ) ;
V_83 = F_55 ( V_13 ) ;
V_185 = V_84 [ V_83 ] . V_205 ;
V_84 [ V_83 ] . V_205 ++ ;
V_84 [ V_83 ] . V_202 = V_184 ;
F_78 ( V_56 ) -> V_214 = V_182 ;
F_78 ( V_56 ) -> V_215 = V_183 ;
F_78 ( V_56 ) -> V_187 = V_187 ;
F_78 ( V_56 ) -> V_188 = V_188 ;
F_78 ( V_56 ) -> V_216 = V_83 ;
F_78 ( V_56 ) -> V_217 = V_185 ;
F_78 ( V_56 ) -> V_13 = V_13 ;
F_78 ( V_56 ) -> V_218 = ( 1UL << ( V_187 + V_188 ) ) - 1 ;
F_78 ( V_56 ) -> V_181 = V_181 ;
F_78 ( V_56 ) -> V_190 = V_190 ;
F_78 ( V_56 ) -> V_219 = V_191 ;
F_78 ( V_56 ) -> V_220 = V_208 ;
F_78 ( V_56 ) -> V_133 . V_221 = F_120 ( V_68 ) ;
V_203 [ V_184 ] = V_83 ;
V_204 [ V_56 ] = V_83 ;
}
F_121 (nid) {
if ( V_203 [ V_184 ] >= 0 )
continue;
V_102 = F_122 ( V_184 ) << V_222 ;
V_13 = F_123 ( F_124 ( V_102 ) ) ;
V_83 = F_55 ( V_13 ) ;
V_203 [ V_184 ] = V_83 ;
}
F_65 ( V_99 ) ;
F_66 ( V_99 ) ;
F_67 ( V_99 & V_194 ) ;
F_92 () ;
F_85 () ;
F_103 () ;
F_125 ( L_23 , NULL ) ;
F_126 ( F_88 ) ;
if ( F_127 () )
V_223 = V_224 ;
}
