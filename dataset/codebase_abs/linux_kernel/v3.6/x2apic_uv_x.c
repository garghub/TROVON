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
static int T_3 F_15 ( int V_54 , unsigned long V_55 )
{
#ifdef F_16
unsigned long V_2 ;
int V_13 ;
V_13 = F_17 ( V_54 ) ;
V_54 |= V_34 ;
V_2 = ( 1UL << V_56 ) |
( V_54 << V_57 ) |
( ( V_55 << V_58 ) >> 12 ) |
V_59 ;
F_18 ( V_13 , V_60 , V_2 ) ;
V_2 = ( 1UL << V_56 ) |
( V_54 << V_57 ) |
( ( V_55 << V_58 ) >> 12 ) |
V_61 ;
F_18 ( V_13 , V_60 , V_2 ) ;
F_19 ( & V_62 , 1 ) ;
#endif
return 0 ;
}
static void F_20 ( int V_63 , int V_64 )
{
unsigned long V_65 ;
int V_13 ;
V_65 = F_21 ( V_66 , V_63 ) ;
V_13 = F_17 ( V_65 ) ;
F_22 ( V_13 , V_65 , V_64 ) ;
}
static void F_23 ( const struct V_67 * V_68 , int V_64 )
{
unsigned int V_63 ;
F_24 (cpu, mask)
F_20 ( V_63 , V_64 ) ;
}
static void F_25 ( const struct V_67 * V_68 , int V_64 )
{
unsigned int V_69 = F_26 () ;
unsigned int V_63 ;
F_24 (cpu, mask) {
if ( V_63 != V_69 )
F_20 ( V_63 , V_64 ) ;
}
}
static void F_27 ( int V_64 )
{
unsigned int V_69 = F_26 () ;
unsigned int V_63 ;
F_28 (cpu) {
if ( V_63 != V_69 )
F_20 ( V_63 , V_64 ) ;
}
}
static void F_29 ( int V_64 )
{
F_23 ( V_70 , V_64 ) ;
}
static int F_30 ( int V_65 )
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
F_33 ( const struct V_67 * V_67 ,
const struct V_67 * V_71 ,
unsigned int * V_65 )
{
int unsigned V_63 ;
F_34 (cpu, cpumask, andmask) {
if ( F_35 ( V_63 , V_70 ) )
break;
}
if ( F_36 ( V_63 < V_72 ) ) {
* V_65 = F_21 ( V_66 , V_63 ) | V_34 ;
return 0 ;
}
return - V_73 ;
}
static unsigned int F_37 ( unsigned long V_74 )
{
unsigned int V_75 ;
F_38 ( F_39 () && F_40 () > 1 ) ;
V_75 = V_74 | F_41 ( V_51 ) ;
return V_75 ;
}
static unsigned long F_42 ( unsigned int V_75 )
{
unsigned long V_74 ;
V_74 = V_75 ;
return V_74 ;
}
static unsigned int F_43 ( void )
{
return F_37 ( F_44 ( V_76 ) ) ;
}
static int F_45 ( int V_77 , int V_78 )
{
return F_43 () >> V_78 ;
}
static void F_46 ( int V_64 )
{
F_47 ( V_79 , V_64 ) ;
}
static int F_48 ( void )
{
return V_80 == & V_81 ;
}
static T_3 void F_49 ( int V_13 )
{
F_12 ( V_51 , V_13 << V_27 . V_18 . V_29 ) ;
}
static T_1 int F_50 ( int V_13 )
{
int V_82 ;
for ( V_82 = 0 ; V_82 < F_51 () ; V_82 ++ )
if ( V_13 == V_83 [ V_82 ] . V_13 )
return V_82 ;
F_52 () ;
}
static T_1 void F_53 ( unsigned long * V_84 , unsigned long * V_85 )
{
union V_86 V_87 ;
union V_88 V_89 ;
int V_90 ;
for ( V_90 = 0 ; V_90 < F_54 ( V_91 ) ; V_90 ++ ) {
V_87 . V_14 = F_55 ( V_91 [ V_90 ] . V_87 ) ;
if ( V_87 . V_18 . V_92 && V_87 . V_18 . V_84 == 0 ) {
* V_85 = ( 1UL << V_87 . V_18 . V_93 ) ;
V_89 . V_14 = F_55 ( V_91 [ V_90 ] . V_89 ) ;
* V_84 = ( unsigned long ) V_89 . V_18 . V_94 << V_95 ;
return;
}
}
* V_84 = * V_85 = 0 ;
}
static T_1 void F_56 ( char * V_75 , unsigned long V_84 , int V_96 ,
int V_97 , int V_98 , enum V_99 V_99 )
{
unsigned long V_100 , V_101 ;
V_101 = V_84 << V_96 ;
V_100 = ( 1UL << V_97 ) * ( V_98 + 1 ) ;
F_57 ( V_102 L_6 , V_75 , V_101 ,
V_101 + V_100 ) ;
if ( V_99 == V_103 )
F_58 ( V_101 , V_100 ) ;
else
F_59 ( V_101 , V_100 ) ;
}
static T_1 void F_60 ( int V_98 )
{
union V_104 V_105 ;
int V_106 = V_107 ;
V_105 . V_14 = F_55 ( V_108 ) ;
if ( V_105 . V_18 . V_92 ) {
F_56 ( L_7 , V_105 . V_18 . V_84 , V_106 , V_106 , V_98 , V_109 ) ;
V_7 = ( ( T_2 ) V_105 . V_18 . V_84 << V_106 ) ;
V_8 = V_7 + ( 1UL << V_106 ) * ( V_98 + 1 ) ;
}
}
static T_1 void F_61 ( int V_98 )
{
union V_110 V_3 ;
int V_106 = V_111 ;
V_3 . V_14 = F_55 ( V_112 ) ;
if ( V_3 . V_18 . V_92 )
F_56 ( L_8 , V_3 . V_18 . V_84 , V_106 , V_106 , V_98 , V_103 ) ;
}
static T_1 void F_62 ( int V_98 )
{
union V_113 V_114 ;
int V_106 ;
V_114 . V_14 = F_55 ( V_115 ) ;
if ( F_10 () && V_114 . V_35 . V_92 ) {
V_106 = V_116 ;
F_56 ( L_9 , V_114 . V_35 . V_84 , V_106 , V_114 . V_35 . V_117 ,
V_98 , V_103 ) ;
}
if ( F_63 () && V_114 . V_118 . V_92 ) {
V_106 = V_119 ;
F_56 ( L_9 , V_114 . V_118 . V_84 , V_106 , V_114 . V_118 . V_117 ,
V_98 , V_103 ) ;
}
}
static T_1 void F_64 ( void )
{
F_58 ( V_120 , V_121 ) ;
F_58 ( V_4 , V_122 ) ;
}
static T_1 void F_65 ( void )
{
long V_123 ;
T_2 V_124 ;
V_123 = F_66 ( V_125 ,
& V_124 ) ;
if ( V_123 != V_126 || V_124 < 100000 ) {
F_57 ( V_127
L_10
L_11 ) ;
V_128 = 1000000000000UL / 30000UL ;
} else
V_128 = V_124 ;
}
static void F_67 ( unsigned long V_129 )
{
struct V_130 * V_131 = & V_24 -> V_132 . V_131 ;
unsigned char V_133 = V_24 -> V_132 . V_134 ;
V_133 ^= V_135 ;
if ( F_68 ( F_69 () ) )
V_133 &= ~ V_136 ;
else
V_133 |= V_136 ;
F_70 ( V_133 ) ;
F_71 ( V_131 , V_137 + V_138 ) ;
}
static void T_3 F_72 ( int V_63 )
{
while ( ! F_73 ( V_63 ) -> V_132 . V_139 ) {
struct V_130 * V_131 = & F_73 ( V_63 ) -> V_132 . V_131 ;
F_74 ( V_63 , V_135 | V_136 ) ;
F_75 ( V_131 , F_67 , V_63 ) ;
V_131 -> V_140 = V_137 + V_138 ;
F_76 ( V_131 , V_63 ) ;
F_73 ( V_63 ) -> V_132 . V_139 = 1 ;
V_63 = 0 ;
}
}
static void T_3 F_77 ( int V_63 )
{
if ( F_73 ( V_63 ) -> V_132 . V_139 ) {
F_73 ( V_63 ) -> V_132 . V_139 = 0 ;
F_78 ( & F_73 ( V_63 ) -> V_132 . V_131 ) ;
}
F_74 ( V_63 , 0xff ) ;
}
static T_3 int F_79 ( struct V_141 * V_142 ,
unsigned long V_143 , void * V_144 )
{
long V_63 = ( long ) V_144 ;
switch ( V_143 ) {
case V_145 :
F_72 ( V_63 ) ;
break;
case V_146 :
F_77 ( V_63 ) ;
break;
default:
break;
}
return V_147 ;
}
static T_1 void F_80 ( void )
{
F_81 ( F_79 , 0 ) ;
}
static T_1 void F_80 ( void )
{
}
static T_1 int F_82 ( void )
{
int V_63 ;
if ( F_14 () )
F_28 (cpu)
F_72 ( V_63 ) ;
return 0 ;
}
int F_83 ( struct V_148 * V_149 , bool V_150 ,
unsigned int V_151 , T_4 V_152 )
{
int V_153 , V_154 , V_155 ;
F_84 ( L_12 ,
V_149 -> V_156 , V_150 , V_151 , V_152 ) ;
if ( ! ( V_152 & V_157 ) )
return 0 ;
if ( ( V_151 & V_158 ) == 0 )
return 0 ;
V_153 = F_85 ( V_149 -> V_154 ) ;
V_154 = V_149 -> V_154 -> V_159 ;
V_155 = F_86 ( V_150 , V_153 , V_154 ) ;
F_84 ( L_13 , V_150 , V_153 , V_154 , V_155 ) ;
return V_155 ;
}
void T_3 F_87 ( void )
{
if ( ! V_83 )
return;
V_83 [ F_88 () ] . V_160 ++ ;
if ( F_13 () == V_52 )
F_49 ( V_24 -> V_13 ) ;
}
int F_89 ( unsigned int V_161 , struct V_162 * V_163 )
{
unsigned long V_164 ;
int V_165 ;
V_165 = F_88 () ;
V_164 = ( F_55 ( V_166 ) & V_167 ) ;
if ( F_90 ( V_164 ) ) {
F_91 ( & V_83 [ V_165 ] . V_168 ) ;
V_164 = ( F_55 ( V_166 ) & V_167 ) ;
if ( V_164 ) {
V_83 [ V_165 ] . V_169 ++ ;
F_92 ( V_170 , V_167 ) ;
}
F_93 ( & V_83 [ V_165 ] . V_168 ) ;
}
if ( F_36 ( F_94 ( V_171 ) == V_83 [ V_165 ] . V_169 ) )
return V_172 ;
F_94 ( V_171 ) = V_83 [ V_165 ] . V_169 ;
F_91 ( & V_173 ) ;
F_95 ( L_14 , F_26 () ) ;
F_96 () ;
F_93 ( & V_173 ) ;
return V_174 ;
}
void F_97 ( void )
{
if ( F_98 ( V_175 , F_89 , 0 , L_15 ) )
F_57 ( V_127 L_16 ) ;
}
void V_47 ( void )
{
unsigned int V_176 ;
V_176 = F_44 ( V_177 ) | V_178 ;
V_176 &= ~ V_179 ;
F_47 ( V_177 , V_176 ) ;
}
void T_1 F_99 ( void )
{
union V_11 V_12 ;
union V_113 V_114 ;
union V_9 V_10 ;
unsigned long V_180 , V_181 , V_182 ;
int V_100 , V_183 , V_63 , V_184 , V_13 , V_82 , V_90 , V_185 , V_186 , V_187 , V_188 ;
int V_189 , V_98 = 0 ;
unsigned long V_190 , V_191 , V_101 ;
unsigned short V_192 , V_193 ;
F_57 ( V_102 L_17 , F_10 () ? L_18 : L_19 ) ;
F_64 () ;
V_12 . V_14 = F_55 ( V_16 ) ;
V_186 = V_12 . V_18 . V_194 ;
V_187 = V_12 . V_18 . V_26 ;
V_114 . V_14 = F_55 ( V_115 ) ;
V_188 = F_10 () ? V_114 . V_35 . V_188 : V_114 . V_118 . V_188 ;
V_190 =
F_55 ( V_112 ) &
~ V_195 ;
V_192 = ( 1 << V_187 ) - 1 ;
V_193 = ( 1 << V_188 ) - 1 ;
V_10 . V_14 = F_55 ( V_15 ) ;
V_189 = ( V_10 . V_18 . V_10 & ~ ( ( 1 << V_187 ) - 1 ) ) >> 1 ;
V_180 = ( ( unsigned long ) V_189 << V_186 ) ;
F_57 ( V_102 L_20 ,
V_187 , V_186 , V_188 , V_180 , V_189 , V_192 , V_193 ) ;
F_57 ( V_196 L_21 , V_190 ) ;
for( V_90 = 0 ; V_90 < V_197 ; V_90 ++ )
V_198 +=
F_100 ( F_55 ( V_199 + V_90 * 8 ) ) ;
F_57 ( V_102 L_22 ,
F_10 () ? F_51 () :
( F_51 () + 1 ) / 2 ,
F_51 () ) ;
V_100 = sizeof( struct V_83 ) * F_51 () ;
V_83 = F_101 ( V_100 , V_200 ) ;
F_102 ( ! V_83 ) ;
for ( V_82 = 0 ; V_82 < F_51 () ; V_82 ++ )
V_83 [ V_82 ] . V_201 = - 1 ;
F_53 ( & V_181 , & V_182 ) ;
V_100 = sizeof( V_202 [ 0 ] ) * F_103 () ;
V_202 = F_104 ( V_100 , V_200 ) ;
F_102 ( ! V_202 ) ;
memset ( V_202 , 255 , V_100 ) ;
V_100 = sizeof( V_203 [ 0 ] ) * F_105 () ;
V_203 = F_104 ( V_100 , V_200 ) ;
F_102 ( ! V_203 ) ;
memset ( V_203 , 255 , V_100 ) ;
V_82 = 0 ;
for ( V_90 = 0 ; V_90 < V_197 ; V_90 ++ ) {
V_191 = F_55 ( V_199 + V_90 * 8 ) ;
for ( V_185 = 0 ; V_185 < 64 ; V_185 ++ ) {
if ( ! F_106 ( V_185 , & V_191 ) )
continue;
V_13 = ( V_90 * 64 + V_185 ) & V_192 ;
V_83 [ V_82 ] . V_13 = V_13 ;
V_83 [ V_82 ] . V_204 = 0 ;
V_83 [ V_82 ] . V_160 = 0 ;
F_107 ( & V_83 [ V_82 ] . V_168 ) ;
V_98 = F_108 ( V_13 , V_98 ) ;
V_82 ++ ;
}
}
F_109 () ;
F_110 ( 0 , & V_205 , & V_206 , & V_207 ,
& V_208 , & V_209 ) ;
F_65 () ;
F_111 (cpu) {
int V_65 = F_21 ( V_66 , V_63 ) ;
V_183 = F_112 ( V_63 ) ;
F_73 ( V_63 ) -> V_192 = V_192 ;
F_73 ( V_63 ) -> V_210 = V_27 . V_18 . V_29 ;
F_73 ( V_63 ) -> V_25 = V_24 -> V_25 ;
F_73 ( V_63 ) -> V_211 = 64 - V_186 ;
F_73 ( V_63 ) -> V_212 = F_113 () ?
( V_186 == 40 ? 40 : 39 ) : V_186 ;
V_13 = F_17 ( V_65 ) ;
V_82 = F_50 ( V_13 ) ;
V_184 = V_83 [ V_82 ] . V_204 ;
V_83 [ V_82 ] . V_204 ++ ;
V_83 [ V_82 ] . V_201 = V_183 ;
F_73 ( V_63 ) -> V_213 = V_181 ;
F_73 ( V_63 ) -> V_214 = V_182 ;
F_73 ( V_63 ) -> V_186 = V_186 ;
F_73 ( V_63 ) -> V_187 = V_187 ;
F_73 ( V_63 ) -> V_215 = V_82 ;
F_73 ( V_63 ) -> V_216 = V_184 ;
F_73 ( V_63 ) -> V_13 = V_13 ;
F_73 ( V_63 ) -> V_217 = ( 1UL << ( V_186 + V_187 ) ) - 1 ;
F_73 ( V_63 ) -> V_180 = V_180 ;
F_73 ( V_63 ) -> V_189 = V_189 ;
F_73 ( V_63 ) -> V_218 = V_190 ;
F_73 ( V_63 ) -> V_219 = V_207 ;
F_73 ( V_63 ) -> V_132 . V_220 = F_114 ( V_65 ) ;
V_202 [ V_183 ] = V_82 ;
V_203 [ V_63 ] = V_82 ;
}
F_115 (nid) {
if ( V_202 [ V_183 ] >= 0 )
continue;
V_101 = F_116 ( V_183 ) << V_221 ;
V_13 = F_117 ( F_118 ( V_101 ) ) ;
V_82 = F_50 ( V_13 ) ;
V_202 [ V_183 ] = V_82 ;
}
F_60 ( V_98 ) ;
F_61 ( V_98 ) ;
F_62 ( V_98 & V_193 ) ;
F_87 () ;
F_80 () ;
F_97 () ;
F_119 ( L_23 , NULL ) ;
F_120 ( F_83 ) ;
if ( F_121 () )
V_222 = V_223 ;
}
