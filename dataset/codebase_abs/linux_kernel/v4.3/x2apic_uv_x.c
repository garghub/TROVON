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
int V_52 ;
int V_53 ;
if ( strncmp ( V_50 , L_1 , 3 ) != 0 )
return 0 ;
V_36 -> V_37 =
! strncmp ( V_50 , L_2 , 4 ) ? V_35 :
! strcmp ( V_50 , L_3 ) ? V_32 :
! strcmp ( V_50 , L_1 ) ? V_54 : 0 ;
if ( V_36 -> V_37 == 0 )
goto V_55;
V_52 = F_7 () ;
F_8 () ;
V_56 . V_57 = F_5 ;
V_56 . V_58 = V_59 ;
if ( ! strcmp ( V_51 , L_4 ) ) {
V_60 = V_61 ;
V_53 = 0 ;
} else if ( ! strcmp ( V_51 , L_5 ) ) {
V_60 = V_62 ;
F_12 ( V_63 ,
V_52 << V_39 . V_27 . V_41 ) ;
F_9 () ;
V_53 = 1 ;
} else if ( ! strcmp ( V_51 , L_6 ) ) {
V_60 = V_64 ;
V_53 = 0 ;
} else {
goto V_55;
}
F_13 ( L_7 ,
V_50 , V_51 , V_60 ,
V_26 , V_53 ) ;
return V_53 ;
V_55:
F_14 ( L_8 , V_50 , V_51 ) ;
F_14 ( L_9 ) ;
F_15 () ;
}
enum V_60 F_16 ( void )
{
return V_60 ;
}
int F_17 ( void )
{
return V_60 != V_65 ;
}
static int F_18 ( int V_66 , unsigned long V_67 )
{
unsigned long V_2 ;
int V_22 ;
V_22 = F_19 ( V_66 ) ;
V_66 |= V_46 ;
V_2 = ( 1UL << V_68 ) |
( V_66 << V_69 ) |
( ( V_67 << V_70 ) >> 12 ) |
V_71 ;
F_20 ( V_22 , V_72 , V_2 ) ;
V_2 = ( 1UL << V_68 ) |
( V_66 << V_69 ) |
( ( V_67 << V_70 ) >> 12 ) |
V_73 ;
F_20 ( V_22 , V_72 , V_2 ) ;
return 0 ;
}
static void F_21 ( int V_74 , int V_75 )
{
unsigned long V_76 ;
int V_22 ;
V_76 = F_22 ( V_77 , V_74 ) ;
V_22 = F_19 ( V_76 ) ;
F_23 ( V_22 , V_76 , V_75 ) ;
}
static void F_24 ( const struct V_78 * V_79 , int V_75 )
{
unsigned int V_74 ;
F_25 (cpu, mask)
F_21 ( V_74 , V_75 ) ;
}
static void F_26 ( const struct V_78 * V_79 , int V_75 )
{
unsigned int V_80 = F_27 () ;
unsigned int V_74 ;
F_25 (cpu, mask) {
if ( V_74 != V_80 )
F_21 ( V_74 , V_75 ) ;
}
}
static void F_28 ( int V_75 )
{
unsigned int V_80 = F_27 () ;
unsigned int V_74 ;
F_29 (cpu) {
if ( V_74 != V_80 )
F_21 ( V_74 , V_75 ) ;
}
}
static void F_30 ( int V_75 )
{
F_24 ( V_81 , V_75 ) ;
}
static int F_31 ( int V_76 )
{
return 1 ;
}
static int F_32 ( void )
{
return 1 ;
}
static void F_33 ( void )
{
}
static int
F_34 ( const struct V_78 * V_78 ,
const struct V_78 * V_82 ,
unsigned int * V_76 )
{
int unsigned V_74 ;
F_35 (cpu, cpumask, andmask) {
if ( F_36 ( V_74 , V_81 ) )
break;
}
if ( F_37 ( V_74 < V_83 ) ) {
* V_76 = F_22 ( V_77 , V_74 ) | V_46 ;
return 0 ;
}
return - V_84 ;
}
static unsigned int F_38 ( unsigned long V_85 )
{
unsigned int V_86 ;
F_39 ( F_40 () && F_41 () > 1 ) ;
V_86 = V_85 | F_42 ( V_63 ) ;
return V_86 ;
}
static unsigned long F_43 ( unsigned int V_86 )
{
unsigned long V_85 ;
V_85 = V_86 ;
return V_85 ;
}
static unsigned int F_44 ( void )
{
return F_38 ( F_45 ( V_87 ) ) ;
}
static int F_46 ( int V_88 , int V_89 )
{
return F_44 () >> V_89 ;
}
static void F_47 ( int V_75 )
{
F_48 ( V_90 , V_75 ) ;
}
static int F_49 ( void )
{
return V_91 == & V_92 ;
}
static void F_50 ( int V_22 )
{
F_12 ( V_63 , V_22 << V_39 . V_27 . V_41 ) ;
}
static T_1 int F_51 ( int V_22 )
{
int V_93 ;
for ( V_93 = 0 ; V_93 < F_52 () ; V_93 ++ )
if ( V_22 == V_94 [ V_93 ] . V_22 )
return V_93 ;
F_15 () ;
}
static unsigned char F_53 ( int V_95 )
{
union V_96 V_97 ;
if ( F_10 () )
return V_95 ;
if ( F_54 () )
return V_95 == 40 ? 40 : 39 ;
V_97 . V_23 = F_55 ( V_98 ) ;
return V_97 . V_99 . V_100 ;
}
static T_1 void F_56 ( unsigned long * V_101 , unsigned long * V_102 )
{
union V_103 V_104 ;
union V_105 V_106 ;
int V_107 ;
for ( V_107 = 0 ; V_107 < F_57 ( V_108 ) ; V_107 ++ ) {
V_104 . V_23 = F_55 ( V_108 [ V_107 ] . V_104 ) ;
if ( V_104 . V_27 . V_109 && V_104 . V_27 . V_101 == 0 ) {
* V_102 = ( 1UL << V_104 . V_27 . V_110 ) ;
V_106 . V_23 = F_55 ( V_108 [ V_107 ] . V_106 ) ;
* V_101 = ( unsigned long ) V_106 . V_27 . V_111 << V_112 ;
return;
}
}
* V_101 = * V_102 = 0 ;
}
static T_1 void F_58 ( char * V_86 , unsigned long V_101 , int V_113 ,
int V_114 , int V_115 , enum V_116 V_116 )
{
unsigned long V_117 , V_118 ;
V_118 = V_101 << V_113 ;
V_117 = ( 1UL << V_114 ) * ( V_115 + 1 ) ;
if ( ! V_118 ) {
F_13 ( L_10 , V_86 ) ;
return;
}
F_59 ( L_11 , V_86 , V_118 , V_118 + V_117 ) ;
if ( V_116 == V_119 )
F_60 ( V_118 , V_117 ) ;
else
F_61 ( V_118 , V_117 ) ;
}
static T_1 void F_62 ( unsigned long V_120 )
{
union V_121 V_122 ;
T_2 V_118 ;
unsigned long V_117 ;
int V_123 ;
V_122 . V_23 = V_120 ;
V_7 = V_122 . V_23 & 0x000007fff0000000UL ;
if ( ! V_7 ) {
F_13 ( L_12 ) ;
return;
}
V_117 = 1UL << V_124 ;
V_11 = ( ( 1UL << V_36 -> V_95 ) - 1 ) & ~ ( V_117 - 1 ) ;
V_9 = ~ ( ( 1UL << V_36 -> V_95 ) - 1 ) ;
V_7 &= V_11 ;
F_63 (nid) {
V_118 = ( ( T_2 ) F_64 ( V_123 ) << V_36 -> V_95 ) |
V_7 ;
F_61 ( V_118 , V_117 ) ;
V_14 = F_65 ( V_118 , V_14 ) ;
V_15 = F_66 ( V_118 , V_15 ) ;
}
V_14 &= V_9 ;
V_15 &= V_9 ;
F_59 ( L_13 ,
V_7 , V_14 , V_15 ) ;
}
static T_1 void F_67 ( int V_115 )
{
union V_121 V_122 ;
int V_125 = V_124 ;
V_122 . V_23 = F_55 ( V_126 ) ;
if ( ! V_122 . V_27 . V_109 ) {
F_13 ( L_14 ) ;
return;
}
if ( F_68 () && V_122 . V_99 . V_127 ) {
F_62 ( V_122 . V_23 ) ;
return;
}
F_58 ( L_15 , V_122 . V_27 . V_101 , V_125 , V_125 , V_115 , V_128 ) ;
V_16 = ( ( T_2 ) V_122 . V_27 . V_101 << V_125 ) ;
V_17 = V_16 + ( 1UL << V_125 ) * ( V_115 + 1 ) ;
}
static T_1 void F_69 ( int V_115 )
{
union V_129 V_3 ;
int V_125 = V_130 ;
V_3 . V_23 = F_55 ( V_131 ) ;
if ( V_3 . V_27 . V_109 )
F_58 ( L_16 , V_3 . V_27 . V_101 , V_125 , V_125 , V_115 , V_119 ) ;
else
F_13 ( L_17 ) ;
}
static T_1 void F_70 ( int V_132 , int V_133 , int V_115 )
{
union V_134 V_135 ;
unsigned long V_3 ;
unsigned long V_101 ;
int V_107 , V_136 , V_125 , V_137 , V_138 ;
int V_139 , V_140 , V_141 , V_142 ;
char * V_86 ;
V_86 = V_143 [ V_132 ] . V_86 ;
V_135 . V_23 = F_55 ( V_143 [ V_132 ] . V_135 ) ;
F_13 ( L_18 ,
V_86 , V_135 . V_23 , V_135 . V_99 . V_101 , V_135 . V_99 . V_137 ) ;
if ( ! V_135 . V_99 . V_109 ) {
F_13 ( L_19 , V_86 ) ;
return;
}
V_125 = V_144 ;
V_101 = ( unsigned long ) V_135 . V_99 . V_101 ;
V_137 = V_135 . V_99 . V_137 ;
V_3 = V_143 [ V_132 ] . V_106 ;
V_136 = V_145 ;
V_133 *= 2 ;
V_115 *= 2 ;
V_138 = V_140 = V_141 = V_142 = - 1 ;
for ( V_107 = 0 ; V_107 < V_136 ; V_107 ++ ) {
union V_146 V_106 ;
V_106 . V_23 = F_55 ( V_3 + V_107 * 8 ) ;
V_139 = V_106 . V_99 . V_139 ;
if ( V_139 < V_133 || V_115 < V_139 )
V_139 = - 1 ;
if ( V_139 == V_140 ) {
V_142 = V_107 ;
if ( V_107 != V_136 - 1 )
continue;
}
if ( V_140 != - 1 || ( V_107 == V_136 - 1 && V_139 != - 1 ) ) {
unsigned long V_147 , V_148 ;
int V_149 , V_150 ;
if ( V_140 == - 1 ) {
V_149 = V_150 = V_107 ;
V_140 = V_139 ;
} else {
V_149 = V_141 ;
V_150 = V_142 ;
}
V_147 = ( V_101 << V_125 ) +
V_149 * ( unsigned long ) ( 1 << V_137 ) ;
V_148 = ( V_101 << V_125 ) +
( V_150 + 1 ) * ( unsigned long ) ( 1 << V_137 ) ;
F_13 ( L_20 ,
V_86 , V_141 , V_142 , V_140 , V_147 , V_148 ) ;
if ( V_138 < V_150 )
V_138 = V_150 ;
}
V_141 = V_142 = V_107 ;
V_140 = V_139 ;
}
F_13 ( L_21 ,
V_86 , V_101 , V_125 , V_137 , V_138 ) ;
if ( V_138 >= 0 )
F_58 ( V_86 , V_101 , V_125 , V_137 , V_138 , V_119 ) ;
}
static T_1 void F_71 ( int V_133 , int V_115 )
{
union V_151 V_152 ;
unsigned long V_3 , V_101 ;
int V_125 , V_109 , V_137 , V_153 ;
if ( F_68 () ) {
F_70 ( 0 , V_133 , V_115 ) ;
F_70 ( 1 , V_133 , V_115 ) ;
return;
}
if ( F_10 () ) {
V_3 = V_154 ;
V_125 = V_155 ;
V_152 . V_23 = F_55 ( V_3 ) ;
V_109 = ! ! V_152 . V_47 . V_109 ;
V_101 = V_152 . V_47 . V_101 ;
V_137 = V_152 . V_47 . V_137 ;
V_153 = V_152 . V_47 . V_153 ;
} else if ( F_54 () ) {
V_3 = V_156 ;
V_125 = V_157 ;
V_152 . V_23 = F_55 ( V_3 ) ;
V_109 = ! ! V_152 . V_158 . V_109 ;
V_101 = V_152 . V_158 . V_101 ;
V_137 = V_152 . V_158 . V_137 ;
V_153 = V_152 . V_158 . V_153 ;
} else
return;
if ( V_109 ) {
V_115 &= ( 1 << V_153 ) - 1 ;
F_13 (
L_22 ,
V_101 , V_125 , V_137 , V_153 , V_115 ) ;
F_58 ( L_23 , V_101 , V_125 , V_137 , V_115 , V_119 ) ;
} else {
F_13 ( L_24 ) ;
}
}
static T_1 void F_72 ( void )
{
F_60 ( V_159 , V_160 ) ;
F_60 ( V_4 , V_161 ) ;
}
static T_1 void F_73 ( void )
{
long V_162 ;
T_2 V_163 ;
V_162 = F_74 ( V_164 ,
& V_163 ) ;
if ( V_162 != V_165 || V_163 < 100000 ) {
F_75 ( V_166
L_25
L_26 ) ;
V_167 = 1000000000000UL / 30000UL ;
} else
V_167 = V_163 ;
}
static void F_76 ( unsigned long V_168 )
{
struct V_169 * V_170 = & V_36 -> V_171 . V_170 ;
unsigned char V_172 = V_36 -> V_171 . V_173 ;
V_172 ^= V_174 ;
if ( F_77 ( F_78 () ) )
V_172 &= ~ V_175 ;
else
V_172 |= V_175 ;
F_79 ( V_172 ) ;
F_80 ( V_170 , V_176 + V_177 ) ;
}
static void F_81 ( int V_74 )
{
while ( ! F_82 ( V_74 ) -> V_171 . V_178 ) {
struct V_169 * V_170 = & F_82 ( V_74 ) -> V_171 . V_170 ;
F_83 ( V_74 , V_174 | V_175 ) ;
F_84 ( V_170 , F_76 , V_74 ) ;
V_170 -> V_179 = V_176 + V_177 ;
F_85 ( V_170 , V_74 ) ;
F_82 ( V_74 ) -> V_171 . V_178 = 1 ;
V_74 = 0 ;
}
}
static void F_86 ( int V_74 )
{
if ( F_82 ( V_74 ) -> V_171 . V_178 ) {
F_82 ( V_74 ) -> V_171 . V_178 = 0 ;
F_87 ( & F_82 ( V_74 ) -> V_171 . V_170 ) ;
}
F_83 ( V_74 , 0xff ) ;
}
static int F_88 ( struct V_180 * V_181 , unsigned long V_182 ,
void * V_183 )
{
long V_74 = ( long ) V_183 ;
switch ( V_182 ) {
case V_184 :
F_81 ( V_74 ) ;
break;
case V_185 :
F_86 ( V_74 ) ;
break;
default:
break;
}
return V_186 ;
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
int V_74 ;
if ( F_17 () )
F_29 (cpu)
F_81 ( V_74 ) ;
return 0 ;
}
int F_92 ( struct V_187 * V_188 , bool V_189 ,
unsigned int V_190 , T_3 V_191 )
{
int V_192 , V_193 , V_194 ;
F_93 ( L_27 ,
V_188 -> V_195 , V_189 , V_190 , V_191 ) ;
if ( ! ( V_191 & V_196 ) )
return 0 ;
if ( ( V_190 & V_197 ) == 0 )
return 0 ;
V_192 = F_94 ( V_188 -> V_193 ) ;
V_193 = V_188 -> V_193 -> V_198 ;
V_194 = F_95 ( V_189 , V_192 , V_193 ) ;
F_93 ( L_28 , V_189 , V_192 , V_193 , V_194 ) ;
return V_194 ;
}
void F_96 ( void )
{
if ( ! V_94 )
return;
V_94 [ F_97 () ] . V_199 ++ ;
if ( F_16 () == V_62 )
F_50 ( V_36 -> V_22 ) ;
}
void T_1 F_98 ( void )
{
union V_20 V_21 ;
union V_18 V_19 ;
unsigned long V_200 , V_201 , V_202 ;
int V_117 , V_123 , V_74 , V_203 , V_22 , V_93 , V_107 , V_204 , V_95 , V_205 ;
int V_206 , V_133 = 999999 , V_115 = - 1 ;
unsigned long V_207 , V_208 , V_118 ;
unsigned short V_209 ;
unsigned char V_210 ;
char * V_211 = ( F_10 () ? L_29 :
( F_54 () ? L_30 :
( F_68 () ? L_31 : NULL ) ) ) ;
if ( ! V_211 ) {
F_14 ( L_32 ) ;
return;
}
F_13 ( L_33 , V_211 ) ;
F_72 () ;
V_21 . V_23 = F_55 ( V_25 ) ;
V_95 = V_21 . V_27 . V_100 ;
V_205 = V_21 . V_27 . V_38 ;
V_209 = ( 1 << V_205 ) - 1 ;
V_210 = F_53 ( V_95 ) ;
V_207 =
F_55 ( V_131 ) &
~ V_212 ;
V_19 . V_23 = F_55 ( V_24 ) ;
V_206 = ( V_19 . V_27 . V_19 & ~ ( ( 1 << V_205 ) - 1 ) ) >> 1 ;
V_200 = ( ( unsigned long ) V_206 << V_95 ) ;
F_13 ( L_34 ,
V_205 , V_95 , V_209 , V_200 , V_206 ,
V_210 ) ;
F_13 ( L_35 , V_207 ) ;
for( V_107 = 0 ; V_107 < V_213 ; V_107 ++ )
V_214 +=
F_99 ( F_55 ( V_215 + V_107 * 8 ) ) ;
F_13 ( L_36 ,
F_10 () ? F_52 () :
( F_52 () + 1 ) / 2 ,
F_52 () ) ;
V_117 = sizeof( struct V_94 ) * F_52 () ;
V_94 = F_100 ( V_117 , V_216 ) ;
F_101 ( ! V_94 ) ;
for ( V_93 = 0 ; V_93 < F_52 () ; V_93 ++ )
V_94 [ V_93 ] . V_217 = - 1 ;
F_56 ( & V_201 , & V_202 ) ;
V_117 = sizeof( V_218 [ 0 ] ) * F_102 () ;
V_218 = F_103 ( V_117 , V_216 ) ;
F_101 ( ! V_218 ) ;
memset ( V_218 , 255 , V_117 ) ;
V_117 = sizeof( V_219 [ 0 ] ) * F_104 () ;
V_219 = F_103 ( V_117 , V_216 ) ;
F_101 ( ! V_219 ) ;
memset ( V_219 , 255 , V_117 ) ;
V_93 = 0 ;
for ( V_107 = 0 ; V_107 < V_213 ; V_107 ++ ) {
V_208 = F_55 ( V_215 + V_107 * 8 ) ;
for ( V_204 = 0 ; V_204 < 64 ; V_204 ++ ) {
if ( ! F_105 ( V_204 , & V_208 ) )
continue;
V_22 = ( V_107 * 64 + V_204 ) & V_209 ;
V_94 [ V_93 ] . V_22 = V_22 ;
V_94 [ V_93 ] . V_220 = 0 ;
V_94 [ V_93 ] . V_199 = 0 ;
F_106 ( & V_94 [ V_93 ] . V_221 ) ;
V_133 = F_65 ( V_22 , V_133 ) ;
V_115 = F_66 ( V_22 , V_115 ) ;
V_93 ++ ;
}
}
F_107 () ;
F_108 ( 0 , & V_222 , & V_223 , & V_224 ,
& V_225 , & V_226 ) ;
F_73 () ;
F_109 (cpu) {
int V_76 = F_22 ( V_77 , V_74 ) ;
V_123 = F_110 ( V_74 ) ;
F_82 ( V_74 ) -> V_209 = V_209 ;
F_82 ( V_74 ) -> V_227 = V_39 . V_27 . V_41 ;
F_82 ( V_74 ) -> V_37 = V_36 -> V_37 ;
F_82 ( V_74 ) -> V_228 = 64 - V_95 ;
F_82 ( V_74 ) -> V_210 = V_210 ;
V_22 = F_19 ( V_76 ) ;
V_93 = F_51 ( V_22 ) ;
V_203 = V_94 [ V_93 ] . V_220 ;
V_94 [ V_93 ] . V_220 ++ ;
V_94 [ V_93 ] . V_217 = V_123 ;
F_82 ( V_74 ) -> V_229 = V_201 ;
F_82 ( V_74 ) -> V_230 = V_202 ;
F_82 ( V_74 ) -> V_95 = V_95 ;
F_82 ( V_74 ) -> V_205 = V_205 ;
F_82 ( V_74 ) -> V_231 = V_93 ;
F_82 ( V_74 ) -> V_232 = V_203 ;
F_82 ( V_74 ) -> V_22 = V_22 ;
F_82 ( V_74 ) -> V_233 = ( 1UL << ( V_95 + V_205 ) ) - 1 ;
F_82 ( V_74 ) -> V_200 = V_200 ;
F_82 ( V_74 ) -> V_206 = V_206 ;
F_82 ( V_74 ) -> V_234 = V_207 ;
F_82 ( V_74 ) -> V_235 = V_224 ;
F_82 ( V_74 ) -> V_171 . V_236 = F_111 ( V_76 ) ;
V_218 [ V_123 ] = V_93 ;
V_219 [ V_74 ] = V_93 ;
}
F_63 (nid) {
if ( V_218 [ V_123 ] >= 0 )
continue;
V_118 = F_112 ( V_123 ) << V_237 ;
V_22 = F_113 ( F_114 ( V_118 ) ) ;
V_93 = F_51 ( V_22 ) ;
V_218 [ V_123 ] = V_93 ;
}
F_67 ( V_115 ) ;
F_69 ( V_115 ) ;
F_71 ( V_133 , V_115 ) ;
F_115 () ;
F_96 () ;
F_89 () ;
F_116 ( L_37 , NULL ) ;
F_117 ( F_92 ) ;
if ( F_118 () )
V_238 = V_239 ;
}
