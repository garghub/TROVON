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
V_23 -> V_24 = V_17 ;
V_13 = ( V_10 . V_18 . V_10 >> 1 ) & ( ( 1 << V_12 . V_18 . V_25 ) - 1 ) ;
return V_13 ;
}
static void T_1 F_8 ( void )
{
V_26 . V_14 = F_1 ( V_27 ) ;
if ( ! V_26 . V_14 )
V_26 . V_18 . V_28 = V_29 ;
}
static void T_1 F_9 ( void )
{
union V_30 V_31 ;
if ( F_10 () ) {
V_31 . V_14 =
F_1 ( V_32 ) ;
V_33 =
V_31 . V_34 . V_35 & V_36 ;
}
}
static int T_1 F_11 ( char * V_37 , char * V_38 )
{
int V_39 , V_40 , V_41 ;
V_40 = ! strcmp ( V_37 , L_1 ) ;
V_41 = ! strcmp ( V_37 , L_2 ) ;
if ( V_40 || V_41 ) {
V_23 -> V_24 =
V_40 ? V_42 : V_22 ;
V_39 = F_7 () ;
F_8 () ;
V_43 . V_44 = F_5 ;
V_43 . V_45 = V_46 ;
if ( ! strcmp ( V_38 , L_3 ) )
V_47 = V_48 ;
else if ( ! strcmp ( V_38 , L_4 ) )
V_47 = V_49 ;
else if ( ! strcmp ( V_38 , L_5 ) ) {
F_12 ( V_50 ,
V_39 << V_26 . V_18 . V_28 ) ;
V_47 = V_51 ;
F_9 () ;
return 1 ;
}
}
return 0 ;
}
enum V_47 F_13 ( void )
{
return V_47 ;
}
int F_14 ( void )
{
return V_47 != V_52 ;
}
static const struct V_53 * F_15 ( void )
{
return V_54 ;
}
static void F_16 ( int V_55 , struct V_53 * V_56 )
{
F_17 ( V_56 ) ;
F_18 ( V_55 , V_56 ) ;
}
static int T_3 F_19 ( int V_57 , unsigned long V_58 )
{
#ifdef F_20
unsigned long V_2 ;
int V_13 ;
V_13 = F_21 ( V_57 ) ;
V_57 |= V_33 ;
V_2 = ( 1UL << V_59 ) |
( V_57 << V_60 ) |
( ( V_58 << V_61 ) >> 12 ) |
V_62 ;
F_22 ( V_13 , V_63 , V_2 ) ;
F_23 ( 10 ) ;
V_2 = ( 1UL << V_59 ) |
( V_57 << V_60 ) |
( ( V_58 << V_61 ) >> 12 ) |
V_64 ;
F_22 ( V_13 , V_63 , V_2 ) ;
F_24 ( & V_65 , 1 ) ;
#endif
return 0 ;
}
static void F_25 ( int V_55 , int V_66 )
{
unsigned long V_67 ;
int V_13 ;
V_67 = F_26 ( V_68 , V_55 ) ;
V_13 = F_21 ( V_67 ) ;
F_27 ( V_13 , V_67 , V_66 ) ;
}
static void F_28 ( const struct V_53 * V_69 , int V_66 )
{
unsigned int V_55 ;
F_29 (cpu, mask)
F_25 ( V_55 , V_66 ) ;
}
static void F_30 ( const struct V_53 * V_69 , int V_66 )
{
unsigned int V_70 = F_31 () ;
unsigned int V_55 ;
F_29 (cpu, mask) {
if ( V_55 != V_70 )
F_25 ( V_55 , V_66 ) ;
}
}
static void F_32 ( int V_66 )
{
unsigned int V_70 = F_31 () ;
unsigned int V_55 ;
F_33 (cpu) {
if ( V_55 != V_70 )
F_25 ( V_55 , V_66 ) ;
}
}
static void F_34 ( int V_66 )
{
F_28 ( V_54 , V_66 ) ;
}
static int F_35 ( void )
{
return 1 ;
}
static void F_36 ( void )
{
}
static unsigned int F_37 ( const struct V_53 * V_53 )
{
int V_55 = F_38 ( V_53 ) ;
if ( ( unsigned ) V_55 < V_71 )
return F_26 ( V_68 , V_55 ) | V_33 ;
else
return V_72 ;
}
static unsigned int
F_39 ( const struct V_53 * V_53 ,
const struct V_53 * V_73 )
{
int V_55 ;
F_40 (cpu, cpumask, andmask) {
if ( F_41 ( V_55 , V_54 ) )
break;
}
return F_26 ( V_68 , V_55 ) | V_33 ;
}
static unsigned int F_42 ( unsigned long V_74 )
{
unsigned int V_75 ;
F_43 ( F_44 () && F_45 () > 1 ) ;
V_75 = V_74 | F_46 ( V_50 ) ;
return V_75 ;
}
static unsigned long F_47 ( unsigned int V_75 )
{
unsigned long V_74 ;
V_74 = V_75 ;
return V_74 ;
}
static unsigned int F_48 ( void )
{
return F_42 ( F_49 ( V_76 ) ) ;
}
static int F_50 ( int V_77 , int V_78 )
{
return F_48 () >> V_78 ;
}
static void F_51 ( int V_66 )
{
F_52 ( V_79 , V_66 ) ;
}
static int F_53 ( void )
{
return V_80 == & V_81 ;
}
static T_3 void F_54 ( int V_13 )
{
F_12 ( V_50 , V_13 << V_26 . V_18 . V_28 ) ;
}
static T_1 int F_55 ( int V_13 )
{
int V_82 ;
for ( V_82 = 0 ; V_82 < F_56 () ; V_82 ++ )
if ( V_13 == V_83 [ V_82 ] . V_13 )
return V_82 ;
F_57 () ;
}
static T_1 void F_58 ( unsigned long * V_84 , unsigned long * V_85 )
{
union V_86 V_87 ;
union V_88 V_89 ;
int V_90 ;
for ( V_90 = 0 ; V_90 < F_59 ( V_91 ) ; V_90 ++ ) {
V_87 . V_14 = F_60 ( V_91 [ V_90 ] . V_87 ) ;
if ( V_87 . V_18 . V_92 && V_87 . V_18 . V_84 == 0 ) {
* V_85 = ( 1UL << V_87 . V_18 . V_93 ) ;
V_89 . V_14 = F_60 ( V_91 [ V_90 ] . V_89 ) ;
* V_84 = ( unsigned long ) V_89 . V_18 . V_94 << V_95 ;
return;
}
}
* V_84 = * V_85 = 0 ;
}
static T_1 void F_61 ( char * V_75 , unsigned long V_84 , int V_96 ,
int V_97 , int V_98 , enum V_99 V_99 )
{
unsigned long V_100 , V_101 ;
V_101 = V_84 << V_96 ;
V_100 = ( 1UL << V_97 ) * ( V_98 + 1 ) ;
F_62 ( V_102 L_6 , V_75 , V_101 ,
V_101 + V_100 ) ;
if ( V_99 == V_103 )
F_63 ( V_101 , V_100 ) ;
else
F_64 ( V_101 , V_100 ) ;
}
static T_1 void F_65 ( int V_98 )
{
union V_104 V_105 ;
int V_106 = V_107 ;
V_105 . V_14 = F_60 ( V_108 ) ;
if ( V_105 . V_18 . V_92 ) {
F_61 ( L_7 , V_105 . V_18 . V_84 , V_106 , V_106 , V_98 , V_109 ) ;
V_7 = ( ( T_2 ) V_105 . V_18 . V_84 << V_106 ) ;
V_8 = V_7 + ( 1UL << V_106 ) * ( V_98 + 1 ) ;
}
}
static T_1 void F_66 ( int V_98 )
{
union V_110 V_3 ;
int V_106 = V_111 ;
V_3 . V_14 = F_60 ( V_112 ) ;
if ( V_3 . V_18 . V_92 )
F_61 ( L_8 , V_3 . V_18 . V_84 , V_106 , V_106 , V_98 , V_103 ) ;
}
static T_1 void F_67 ( int V_98 )
{
union V_113 V_114 ;
int V_106 ;
V_114 . V_14 = F_60 ( V_115 ) ;
if ( F_10 () && V_114 . V_34 . V_92 ) {
V_106 = V_116 ;
F_61 ( L_9 , V_114 . V_34 . V_84 , V_106 , V_114 . V_34 . V_117 ,
V_98 , V_103 ) ;
}
if ( F_68 () && V_114 . V_118 . V_92 ) {
V_106 = V_119 ;
F_61 ( L_9 , V_114 . V_118 . V_84 , V_106 , V_114 . V_118 . V_117 ,
V_98 , V_103 ) ;
}
}
static T_1 void F_69 ( void )
{
F_63 ( V_120 , V_121 ) ;
F_63 ( V_4 , V_122 ) ;
}
static T_1 void F_70 ( void )
{
long V_123 ;
T_2 V_124 ;
V_123 = F_71 ( V_125 ,
& V_124 ) ;
if ( V_123 != V_126 || V_124 < 100000 ) {
F_62 ( V_127
L_10
L_11 ) ;
V_128 = 1000000000000UL / 30000UL ;
} else
V_128 = V_124 ;
}
static void F_72 ( unsigned long V_129 )
{
struct V_130 * V_131 = & V_23 -> V_132 . V_131 ;
unsigned char V_133 = V_23 -> V_132 . V_134 ;
V_133 ^= V_135 ;
if ( F_73 ( F_74 () ) )
V_133 &= ~ V_136 ;
else
V_133 |= V_136 ;
F_75 ( V_133 ) ;
F_76 ( V_131 , V_137 + V_138 ) ;
}
static void T_3 F_77 ( int V_55 )
{
while ( ! F_78 ( V_55 ) -> V_132 . V_139 ) {
struct V_130 * V_131 = & F_78 ( V_55 ) -> V_132 . V_131 ;
F_79 ( V_55 , V_135 | V_136 ) ;
F_80 ( V_131 , F_72 , V_55 ) ;
V_131 -> V_140 = V_137 + V_138 ;
F_81 ( V_131 , V_55 ) ;
F_78 ( V_55 ) -> V_132 . V_139 = 1 ;
V_55 = 0 ;
}
}
static void T_3 F_82 ( int V_55 )
{
if ( F_78 ( V_55 ) -> V_132 . V_139 ) {
F_78 ( V_55 ) -> V_132 . V_139 = 0 ;
F_83 ( & F_78 ( V_55 ) -> V_132 . V_131 ) ;
}
F_79 ( V_55 , 0xff ) ;
}
static T_3 int F_84 ( struct V_141 * V_142 ,
unsigned long V_143 , void * V_144 )
{
long V_55 = ( long ) V_144 ;
switch ( V_143 ) {
case V_145 :
F_77 ( V_55 ) ;
break;
case V_146 :
F_82 ( V_55 ) ;
break;
default:
break;
}
return V_147 ;
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
int V_55 ;
if ( F_14 () )
F_33 (cpu)
F_77 ( V_55 ) ;
return 0 ;
}
int F_88 ( struct V_148 * V_149 , bool V_150 ,
unsigned int V_151 , T_4 V_152 )
{
int V_153 , V_154 , V_155 ;
F_89 ( L_12 ,
V_149 -> V_156 , V_150 , V_151 , V_152 ) ;
if ( ! ( V_152 & V_157 ) )
return 0 ;
if ( ( V_151 & V_158 ) == 0 )
return 0 ;
V_153 = F_90 ( V_149 -> V_154 ) ;
V_154 = V_149 -> V_154 -> V_159 ;
V_155 = F_91 ( V_150 , V_153 , V_154 ) ;
F_89 ( L_13 , V_150 , V_153 , V_154 , V_155 ) ;
return V_155 ;
}
void T_3 F_92 ( void )
{
if ( ! V_83 )
return;
V_83 [ F_93 () ] . V_160 ++ ;
if ( F_13 () == V_51 )
F_54 ( V_23 -> V_13 ) ;
}
int F_94 ( struct V_141 * V_142 , unsigned long V_161 , void * V_162 )
{
unsigned long V_163 ;
int V_164 ;
if ( V_161 != V_165 )
return V_147 ;
if ( V_166 )
return V_147 ;
V_164 = F_93 () ;
V_163 = ( F_60 ( V_167 ) & V_168 ) ;
if ( F_95 ( V_163 ) ) {
F_96 ( & V_83 [ V_164 ] . V_169 ) ;
V_163 = ( F_60 ( V_167 ) & V_168 ) ;
if ( V_163 ) {
V_83 [ V_164 ] . V_170 ++ ;
F_97 ( V_171 , V_168 ) ;
}
F_98 ( & V_83 [ V_164 ] . V_169 ) ;
}
if ( F_99 ( F_100 ( V_172 ) == V_83 [ V_164 ] . V_170 ) )
return V_173 ;
F_100 ( V_172 ) = V_83 [ V_164 ] . V_170 ;
F_96 ( & V_174 ) ;
F_101 ( L_14 , F_31 () ) ;
F_102 () ;
F_98 ( & V_174 ) ;
return V_175 ;
}
void F_103 ( void )
{
if ( F_104 ( & V_176 ) )
F_62 ( V_127 L_15 ) ;
}
void V_46 ( void )
{
unsigned int V_177 ;
V_177 = F_49 ( V_178 ) | V_179 ;
V_177 &= ~ V_180 ;
F_52 ( V_178 , V_177 ) ;
}
void T_1 F_105 ( void )
{
union V_11 V_12 ;
union V_113 V_114 ;
union V_9 V_10 ;
unsigned long V_181 , V_182 , V_183 ;
int V_100 , V_184 , V_55 , V_185 , V_13 , V_82 , V_90 , V_186 , V_187 , V_188 , V_189 ;
int V_190 , V_98 = 0 ;
unsigned long V_191 , V_192 , V_101 ;
unsigned short V_193 , V_194 ;
F_62 ( V_102 L_16 , F_10 () ? L_17 : L_18 ) ;
F_69 () ;
V_12 . V_14 = F_60 ( V_16 ) ;
V_187 = V_12 . V_18 . V_195 ;
V_188 = V_12 . V_18 . V_25 ;
V_114 . V_14 = F_60 ( V_115 ) ;
V_189 = F_10 () ? V_114 . V_34 . V_189 : V_114 . V_118 . V_189 ;
V_191 =
F_60 ( V_112 ) &
~ V_196 ;
V_193 = ( 1 << V_188 ) - 1 ;
V_194 = ( 1 << V_189 ) - 1 ;
V_10 . V_14 = F_60 ( V_15 ) ;
V_190 = ( V_10 . V_18 . V_10 & ~ ( ( 1 << V_188 ) - 1 ) ) >> 1 ;
V_181 = ( ( unsigned long ) V_190 << V_187 ) ;
F_62 ( V_102 L_19 ,
V_188 , V_187 , V_189 , V_181 , V_190 , V_193 , V_194 ) ;
F_62 ( V_197 L_20 , V_191 ) ;
for( V_90 = 0 ; V_90 < V_198 ; V_90 ++ )
V_199 +=
F_106 ( F_60 ( V_200 + V_90 * 8 ) ) ;
F_62 ( V_197 L_21 , F_56 () ) ;
V_100 = sizeof( struct V_83 ) * F_56 () ;
V_83 = F_107 ( V_100 , V_201 ) ;
F_108 ( ! V_83 ) ;
for ( V_82 = 0 ; V_82 < F_56 () ; V_82 ++ )
V_83 [ V_82 ] . V_202 = - 1 ;
F_58 ( & V_182 , & V_183 ) ;
V_100 = sizeof( V_203 [ 0 ] ) * F_109 () ;
V_203 = F_110 ( V_100 , V_201 ) ;
F_108 ( ! V_203 ) ;
memset ( V_203 , 255 , V_100 ) ;
V_100 = sizeof( V_204 [ 0 ] ) * F_111 () ;
V_204 = F_110 ( V_100 , V_201 ) ;
F_108 ( ! V_204 ) ;
memset ( V_204 , 255 , V_100 ) ;
V_82 = 0 ;
for ( V_90 = 0 ; V_90 < V_198 ; V_90 ++ ) {
V_192 = F_60 ( V_200 + V_90 * 8 ) ;
for ( V_186 = 0 ; V_186 < 64 ; V_186 ++ ) {
if ( ! F_112 ( V_186 , & V_192 ) )
continue;
V_13 = ( V_90 * 64 + V_186 ) & V_193 ;
V_83 [ V_82 ] . V_13 = V_13 ;
V_83 [ V_82 ] . V_205 = 0 ;
V_83 [ V_82 ] . V_160 = 0 ;
F_113 ( & V_83 [ V_82 ] . V_169 ) ;
V_98 = F_114 ( V_13 , V_98 ) ;
V_82 ++ ;
}
}
F_115 () ;
F_116 ( 0 , & V_206 , & V_207 , & V_208 ,
& V_209 , & V_210 ) ;
F_70 () ;
F_117 (cpu) {
int V_67 = F_26 ( V_68 , V_55 ) ;
V_184 = F_118 ( V_55 ) ;
F_78 ( V_55 ) -> V_193 = V_193 ;
F_78 ( V_55 ) -> V_211 = V_26 . V_18 . V_28 ;
F_78 ( V_55 ) -> V_24 = V_23 -> V_24 ;
V_13 = F_21 ( V_67 ) ;
V_82 = F_55 ( V_13 ) ;
V_185 = V_83 [ V_82 ] . V_205 ;
V_83 [ V_82 ] . V_205 ++ ;
V_83 [ V_82 ] . V_202 = V_184 ;
F_78 ( V_55 ) -> V_212 = V_182 ;
F_78 ( V_55 ) -> V_213 = V_183 ;
F_78 ( V_55 ) -> V_187 = V_187 ;
F_78 ( V_55 ) -> V_188 = V_188 ;
F_78 ( V_55 ) -> V_214 = V_82 ;
F_78 ( V_55 ) -> V_215 = V_185 ;
F_78 ( V_55 ) -> V_13 = V_13 ;
F_78 ( V_55 ) -> V_216 = ( 1UL << ( V_187 + V_188 ) ) - 1 ;
F_78 ( V_55 ) -> V_181 = V_181 ;
F_78 ( V_55 ) -> V_190 = V_190 ;
F_78 ( V_55 ) -> V_217 = V_191 ;
F_78 ( V_55 ) -> V_218 = V_208 ;
F_78 ( V_55 ) -> V_132 . V_219 = F_119 ( V_67 ) ;
V_203 [ V_184 ] = V_82 ;
V_204 [ V_55 ] = V_82 ;
}
F_120 (nid) {
if ( V_203 [ V_184 ] >= 0 )
continue;
V_101 = F_121 ( V_184 ) << V_220 ;
V_101 = F_122 ( V_101 ) ;
V_13 = ( V_101 >> V_187 ) & V_193 ;
V_82 = F_55 ( V_13 ) ;
V_203 [ V_184 ] = V_82 ;
}
F_65 ( V_98 ) ;
F_66 ( V_98 ) ;
F_67 ( V_98 & V_194 ) ;
F_92 () ;
F_85 () ;
F_103 () ;
F_123 ( L_22 , NULL ) ;
F_124 ( F_88 ) ;
if ( F_125 () )
V_221 = V_222 ;
}
