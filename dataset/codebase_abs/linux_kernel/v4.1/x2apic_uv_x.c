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
F_21 ( & V_74 , 1 ) ;
return 0 ;
}
static void F_22 ( int V_75 , int V_76 )
{
unsigned long V_77 ;
int V_22 ;
V_77 = F_23 ( V_78 , V_75 ) ;
V_22 = F_19 ( V_77 ) ;
F_24 ( V_22 , V_77 , V_76 ) ;
}
static void F_25 ( const struct V_79 * V_80 , int V_76 )
{
unsigned int V_75 ;
F_26 (cpu, mask)
F_22 ( V_75 , V_76 ) ;
}
static void F_27 ( const struct V_79 * V_80 , int V_76 )
{
unsigned int V_81 = F_28 () ;
unsigned int V_75 ;
F_26 (cpu, mask) {
if ( V_75 != V_81 )
F_22 ( V_75 , V_76 ) ;
}
}
static void F_29 ( int V_76 )
{
unsigned int V_81 = F_28 () ;
unsigned int V_75 ;
F_30 (cpu) {
if ( V_75 != V_81 )
F_22 ( V_75 , V_76 ) ;
}
}
static void F_31 ( int V_76 )
{
F_25 ( V_82 , V_76 ) ;
}
static int F_32 ( int V_77 )
{
return 1 ;
}
static int F_33 ( void )
{
return 1 ;
}
static void F_34 ( void )
{
}
static int
F_35 ( const struct V_79 * V_79 ,
const struct V_79 * V_83 ,
unsigned int * V_77 )
{
int unsigned V_75 ;
F_36 (cpu, cpumask, andmask) {
if ( F_37 ( V_75 , V_82 ) )
break;
}
if ( F_38 ( V_75 < V_84 ) ) {
* V_77 = F_23 ( V_78 , V_75 ) | V_46 ;
return 0 ;
}
return - V_85 ;
}
static unsigned int F_39 ( unsigned long V_86 )
{
unsigned int V_87 ;
F_40 ( F_41 () && F_42 () > 1 ) ;
V_87 = V_86 | F_43 ( V_63 ) ;
return V_87 ;
}
static unsigned long F_44 ( unsigned int V_87 )
{
unsigned long V_86 ;
V_86 = V_87 ;
return V_86 ;
}
static unsigned int F_45 ( void )
{
return F_39 ( F_46 ( V_88 ) ) ;
}
static int F_47 ( int V_89 , int V_90 )
{
return F_45 () >> V_90 ;
}
static void F_48 ( int V_76 )
{
F_49 ( V_91 , V_76 ) ;
}
static int F_50 ( void )
{
return V_92 == & V_93 ;
}
static void F_51 ( int V_22 )
{
F_12 ( V_63 , V_22 << V_39 . V_27 . V_41 ) ;
}
static T_1 int F_52 ( int V_22 )
{
int V_94 ;
for ( V_94 = 0 ; V_94 < F_53 () ; V_94 ++ )
if ( V_22 == V_95 [ V_94 ] . V_22 )
return V_94 ;
F_15 () ;
}
static unsigned char F_54 ( int V_96 )
{
union V_97 V_98 ;
if ( F_10 () )
return V_96 ;
if ( F_55 () )
return V_96 == 40 ? 40 : 39 ;
V_98 . V_23 = F_56 ( V_99 ) ;
return V_98 . V_100 . V_101 ;
}
static T_1 void F_57 ( unsigned long * V_102 , unsigned long * V_103 )
{
union V_104 V_105 ;
union V_106 V_107 ;
int V_108 ;
for ( V_108 = 0 ; V_108 < F_58 ( V_109 ) ; V_108 ++ ) {
V_105 . V_23 = F_56 ( V_109 [ V_108 ] . V_105 ) ;
if ( V_105 . V_27 . V_110 && V_105 . V_27 . V_102 == 0 ) {
* V_103 = ( 1UL << V_105 . V_27 . V_111 ) ;
V_107 . V_23 = F_56 ( V_109 [ V_108 ] . V_107 ) ;
* V_102 = ( unsigned long ) V_107 . V_27 . V_112 << V_113 ;
return;
}
}
* V_102 = * V_103 = 0 ;
}
static T_1 void F_59 ( char * V_87 , unsigned long V_102 , int V_114 ,
int V_115 , int V_116 , enum V_117 V_117 )
{
unsigned long V_118 , V_119 ;
V_119 = V_102 << V_114 ;
V_118 = ( 1UL << V_115 ) * ( V_116 + 1 ) ;
if ( ! V_119 ) {
F_13 ( L_10 , V_87 ) ;
return;
}
F_60 ( L_11 , V_87 , V_119 , V_119 + V_118 ) ;
if ( V_117 == V_120 )
F_61 ( V_119 , V_118 ) ;
else
F_62 ( V_119 , V_118 ) ;
}
static T_1 void F_63 ( unsigned long V_121 )
{
union V_122 V_123 ;
T_2 V_119 ;
unsigned long V_118 ;
int V_124 ;
V_123 . V_23 = V_121 ;
V_7 = V_123 . V_23 & 0x000007fff0000000UL ;
if ( ! V_7 ) {
F_13 ( L_12 ) ;
return;
}
V_118 = 1UL << V_125 ;
V_11 = ( ( 1UL << V_36 -> V_96 ) - 1 ) & ~ ( V_118 - 1 ) ;
V_9 = ~ ( ( 1UL << V_36 -> V_96 ) - 1 ) ;
V_7 &= V_11 ;
F_64 (nid) {
V_119 = ( ( T_2 ) F_65 ( V_124 ) << V_36 -> V_96 ) |
V_7 ;
F_62 ( V_119 , V_118 ) ;
V_14 = F_66 ( V_119 , V_14 ) ;
V_15 = F_67 ( V_119 , V_15 ) ;
}
V_14 &= V_9 ;
V_15 &= V_9 ;
F_60 ( L_13 ,
V_7 , V_14 , V_15 ) ;
}
static T_1 void F_68 ( int V_116 )
{
union V_122 V_123 ;
int V_126 = V_125 ;
V_123 . V_23 = F_56 ( V_127 ) ;
if ( ! V_123 . V_27 . V_110 ) {
F_13 ( L_14 ) ;
return;
}
if ( F_69 () && V_123 . V_100 . V_128 ) {
F_63 ( V_123 . V_23 ) ;
return;
}
F_59 ( L_15 , V_123 . V_27 . V_102 , V_126 , V_126 , V_116 , V_129 ) ;
V_16 = ( ( T_2 ) V_123 . V_27 . V_102 << V_126 ) ;
V_17 = V_16 + ( 1UL << V_126 ) * ( V_116 + 1 ) ;
}
static T_1 void F_70 ( int V_116 )
{
union V_130 V_3 ;
int V_126 = V_131 ;
V_3 . V_23 = F_56 ( V_132 ) ;
if ( V_3 . V_27 . V_110 )
F_59 ( L_16 , V_3 . V_27 . V_102 , V_126 , V_126 , V_116 , V_120 ) ;
else
F_13 ( L_17 ) ;
}
static T_1 void F_71 ( int V_133 , int V_134 , int V_116 )
{
union V_135 V_136 ;
unsigned long V_3 ;
unsigned long V_102 ;
int V_108 , V_137 , V_126 , V_138 , V_139 ;
int V_140 , V_141 , V_142 , V_143 ;
char * V_87 ;
V_87 = V_144 [ V_133 ] . V_87 ;
V_136 . V_23 = F_56 ( V_144 [ V_133 ] . V_136 ) ;
F_13 ( L_18 ,
V_87 , V_136 . V_23 , V_136 . V_100 . V_102 , V_136 . V_100 . V_138 ) ;
if ( ! V_136 . V_100 . V_110 ) {
F_13 ( L_19 , V_87 ) ;
return;
}
V_126 = V_145 ;
V_102 = ( unsigned long ) V_136 . V_100 . V_102 ;
V_138 = V_136 . V_100 . V_138 ;
V_3 = V_144 [ V_133 ] . V_107 ;
V_137 = V_146 ;
V_134 *= 2 ;
V_116 *= 2 ;
V_139 = V_141 = V_142 = V_143 = - 1 ;
for ( V_108 = 0 ; V_108 < V_137 ; V_108 ++ ) {
union V_147 V_107 ;
V_107 . V_23 = F_56 ( V_3 + V_108 * 8 ) ;
V_140 = V_107 . V_100 . V_140 ;
if ( V_140 < V_134 || V_116 < V_140 )
V_140 = - 1 ;
if ( V_140 == V_141 ) {
V_143 = V_108 ;
if ( V_108 != V_137 - 1 )
continue;
}
if ( V_141 != - 1 || ( V_108 == V_137 - 1 && V_140 != - 1 ) ) {
unsigned long V_148 , V_149 ;
int V_150 , V_151 ;
if ( V_141 == - 1 ) {
V_150 = V_151 = V_108 ;
V_141 = V_140 ;
} else {
V_150 = V_142 ;
V_151 = V_143 ;
}
V_148 = ( V_102 << V_126 ) +
V_150 * ( unsigned long ) ( 1 << V_138 ) ;
V_149 = ( V_102 << V_126 ) +
( V_151 + 1 ) * ( unsigned long ) ( 1 << V_138 ) ;
F_13 ( L_20 ,
V_87 , V_142 , V_143 , V_141 , V_148 , V_149 ) ;
if ( V_139 < V_151 )
V_139 = V_151 ;
}
V_142 = V_143 = V_108 ;
V_141 = V_140 ;
}
F_13 ( L_21 ,
V_87 , V_102 , V_126 , V_138 , V_139 ) ;
if ( V_139 >= 0 )
F_59 ( V_87 , V_102 , V_126 , V_138 , V_139 , V_120 ) ;
}
static T_1 void F_72 ( int V_134 , int V_116 )
{
union V_152 V_153 ;
unsigned long V_3 , V_102 ;
int V_126 , V_110 , V_138 , V_154 ;
if ( F_69 () ) {
F_71 ( 0 , V_134 , V_116 ) ;
F_71 ( 1 , V_134 , V_116 ) ;
return;
}
if ( F_10 () ) {
V_3 = V_155 ;
V_126 = V_156 ;
V_153 . V_23 = F_56 ( V_3 ) ;
V_110 = ! ! V_153 . V_47 . V_110 ;
V_102 = V_153 . V_47 . V_102 ;
V_138 = V_153 . V_47 . V_138 ;
V_154 = V_153 . V_47 . V_154 ;
} else if ( F_55 () ) {
V_3 = V_157 ;
V_126 = V_158 ;
V_153 . V_23 = F_56 ( V_3 ) ;
V_110 = ! ! V_153 . V_159 . V_110 ;
V_102 = V_153 . V_159 . V_102 ;
V_138 = V_153 . V_159 . V_138 ;
V_154 = V_153 . V_159 . V_154 ;
} else
return;
if ( V_110 ) {
V_116 &= ( 1 << V_154 ) - 1 ;
F_13 (
L_22 ,
V_102 , V_126 , V_138 , V_154 , V_116 ) ;
F_59 ( L_23 , V_102 , V_126 , V_138 , V_116 , V_120 ) ;
} else {
F_13 ( L_24 ) ;
}
}
static T_1 void F_73 ( void )
{
F_61 ( V_160 , V_161 ) ;
F_61 ( V_4 , V_162 ) ;
}
static T_1 void F_74 ( void )
{
long V_163 ;
T_2 V_164 ;
V_163 = F_75 ( V_165 ,
& V_164 ) ;
if ( V_163 != V_166 || V_164 < 100000 ) {
F_76 ( V_167
L_25
L_26 ) ;
V_168 = 1000000000000UL / 30000UL ;
} else
V_168 = V_164 ;
}
static void F_77 ( unsigned long V_169 )
{
struct V_170 * V_171 = & V_36 -> V_172 . V_171 ;
unsigned char V_173 = V_36 -> V_172 . V_174 ;
V_173 ^= V_175 ;
if ( F_78 ( F_79 () ) )
V_173 &= ~ V_176 ;
else
V_173 |= V_176 ;
F_80 ( V_173 ) ;
F_81 ( V_171 , V_177 + V_178 ) ;
}
static void F_82 ( int V_75 )
{
while ( ! F_83 ( V_75 ) -> V_172 . V_179 ) {
struct V_170 * V_171 = & F_83 ( V_75 ) -> V_172 . V_171 ;
F_84 ( V_75 , V_175 | V_176 ) ;
F_85 ( V_171 , F_77 , V_75 ) ;
V_171 -> V_180 = V_177 + V_178 ;
F_86 ( V_171 , V_75 ) ;
F_83 ( V_75 ) -> V_172 . V_179 = 1 ;
V_75 = 0 ;
}
}
static void F_87 ( int V_75 )
{
if ( F_83 ( V_75 ) -> V_172 . V_179 ) {
F_83 ( V_75 ) -> V_172 . V_179 = 0 ;
F_88 ( & F_83 ( V_75 ) -> V_172 . V_171 ) ;
}
F_84 ( V_75 , 0xff ) ;
}
static int F_89 ( struct V_181 * V_182 , unsigned long V_183 ,
void * V_184 )
{
long V_75 = ( long ) V_184 ;
switch ( V_183 ) {
case V_185 :
F_82 ( V_75 ) ;
break;
case V_186 :
F_87 ( V_75 ) ;
break;
default:
break;
}
return V_187 ;
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
int V_75 ;
if ( F_17 () )
F_30 (cpu)
F_82 ( V_75 ) ;
return 0 ;
}
int F_93 ( struct V_188 * V_189 , bool V_190 ,
unsigned int V_191 , T_3 V_192 )
{
int V_193 , V_194 , V_195 ;
F_94 ( L_27 ,
V_189 -> V_196 , V_190 , V_191 , V_192 ) ;
if ( ! ( V_192 & V_197 ) )
return 0 ;
if ( ( V_191 & V_198 ) == 0 )
return 0 ;
V_193 = F_95 ( V_189 -> V_194 ) ;
V_194 = V_189 -> V_194 -> V_199 ;
V_195 = F_96 ( V_190 , V_193 , V_194 ) ;
F_94 ( L_28 , V_190 , V_193 , V_194 , V_195 ) ;
return V_195 ;
}
void F_97 ( void )
{
if ( ! V_95 )
return;
V_95 [ F_98 () ] . V_200 ++ ;
if ( F_16 () == V_62 )
F_51 ( V_36 -> V_22 ) ;
}
void T_1 F_99 ( void )
{
union V_20 V_21 ;
union V_18 V_19 ;
unsigned long V_201 , V_202 , V_203 ;
int V_118 , V_124 , V_75 , V_204 , V_22 , V_94 , V_108 , V_205 , V_96 , V_206 ;
int V_207 , V_134 = 999999 , V_116 = - 1 ;
unsigned long V_208 , V_209 , V_119 ;
unsigned short V_210 ;
unsigned char V_211 ;
char * V_212 = ( F_10 () ? L_29 :
( F_55 () ? L_30 :
( F_69 () ? L_31 : NULL ) ) ) ;
if ( ! V_212 ) {
F_14 ( L_32 ) ;
return;
}
F_13 ( L_33 , V_212 ) ;
F_73 () ;
V_21 . V_23 = F_56 ( V_25 ) ;
V_96 = V_21 . V_27 . V_101 ;
V_206 = V_21 . V_27 . V_38 ;
V_210 = ( 1 << V_206 ) - 1 ;
V_211 = F_54 ( V_96 ) ;
V_208 =
F_56 ( V_132 ) &
~ V_213 ;
V_19 . V_23 = F_56 ( V_24 ) ;
V_207 = ( V_19 . V_27 . V_19 & ~ ( ( 1 << V_206 ) - 1 ) ) >> 1 ;
V_201 = ( ( unsigned long ) V_207 << V_96 ) ;
F_13 ( L_34 ,
V_206 , V_96 , V_210 , V_201 , V_207 ,
V_211 ) ;
F_13 ( L_35 , V_208 ) ;
for( V_108 = 0 ; V_108 < V_214 ; V_108 ++ )
V_215 +=
F_100 ( F_56 ( V_216 + V_108 * 8 ) ) ;
F_13 ( L_36 ,
F_10 () ? F_53 () :
( F_53 () + 1 ) / 2 ,
F_53 () ) ;
V_118 = sizeof( struct V_95 ) * F_53 () ;
V_95 = F_101 ( V_118 , V_217 ) ;
F_102 ( ! V_95 ) ;
for ( V_94 = 0 ; V_94 < F_53 () ; V_94 ++ )
V_95 [ V_94 ] . V_218 = - 1 ;
F_57 ( & V_202 , & V_203 ) ;
V_118 = sizeof( V_219 [ 0 ] ) * F_103 () ;
V_219 = F_104 ( V_118 , V_217 ) ;
F_102 ( ! V_219 ) ;
memset ( V_219 , 255 , V_118 ) ;
V_118 = sizeof( V_220 [ 0 ] ) * F_105 () ;
V_220 = F_104 ( V_118 , V_217 ) ;
F_102 ( ! V_220 ) ;
memset ( V_220 , 255 , V_118 ) ;
V_94 = 0 ;
for ( V_108 = 0 ; V_108 < V_214 ; V_108 ++ ) {
V_209 = F_56 ( V_216 + V_108 * 8 ) ;
for ( V_205 = 0 ; V_205 < 64 ; V_205 ++ ) {
if ( ! F_106 ( V_205 , & V_209 ) )
continue;
V_22 = ( V_108 * 64 + V_205 ) & V_210 ;
V_95 [ V_94 ] . V_22 = V_22 ;
V_95 [ V_94 ] . V_221 = 0 ;
V_95 [ V_94 ] . V_200 = 0 ;
F_107 ( & V_95 [ V_94 ] . V_222 ) ;
V_134 = F_66 ( V_22 , V_134 ) ;
V_116 = F_67 ( V_22 , V_116 ) ;
V_94 ++ ;
}
}
F_108 () ;
F_109 ( 0 , & V_223 , & V_224 , & V_225 ,
& V_226 , & V_227 ) ;
F_74 () ;
F_110 (cpu) {
int V_77 = F_23 ( V_78 , V_75 ) ;
V_124 = F_111 ( V_75 ) ;
F_83 ( V_75 ) -> V_210 = V_210 ;
F_83 ( V_75 ) -> V_228 = V_39 . V_27 . V_41 ;
F_83 ( V_75 ) -> V_37 = V_36 -> V_37 ;
F_83 ( V_75 ) -> V_229 = 64 - V_96 ;
F_83 ( V_75 ) -> V_211 = V_211 ;
V_22 = F_19 ( V_77 ) ;
V_94 = F_52 ( V_22 ) ;
V_204 = V_95 [ V_94 ] . V_221 ;
V_95 [ V_94 ] . V_221 ++ ;
V_95 [ V_94 ] . V_218 = V_124 ;
F_83 ( V_75 ) -> V_230 = V_202 ;
F_83 ( V_75 ) -> V_231 = V_203 ;
F_83 ( V_75 ) -> V_96 = V_96 ;
F_83 ( V_75 ) -> V_206 = V_206 ;
F_83 ( V_75 ) -> V_232 = V_94 ;
F_83 ( V_75 ) -> V_233 = V_204 ;
F_83 ( V_75 ) -> V_22 = V_22 ;
F_83 ( V_75 ) -> V_234 = ( 1UL << ( V_96 + V_206 ) ) - 1 ;
F_83 ( V_75 ) -> V_201 = V_201 ;
F_83 ( V_75 ) -> V_207 = V_207 ;
F_83 ( V_75 ) -> V_235 = V_208 ;
F_83 ( V_75 ) -> V_236 = V_225 ;
F_83 ( V_75 ) -> V_172 . V_237 = F_112 ( V_77 ) ;
V_219 [ V_124 ] = V_94 ;
V_220 [ V_75 ] = V_94 ;
}
F_64 (nid) {
if ( V_219 [ V_124 ] >= 0 )
continue;
V_119 = F_113 ( V_124 ) << V_238 ;
V_22 = F_114 ( F_115 ( V_119 ) ) ;
V_94 = F_52 ( V_22 ) ;
V_219 [ V_124 ] = V_94 ;
}
F_68 ( V_116 ) ;
F_70 ( V_116 ) ;
F_72 ( V_134 , V_116 ) ;
F_116 () ;
F_97 () ;
F_90 () ;
F_117 ( L_37 , NULL ) ;
F_118 ( F_93 ) ;
if ( F_119 () )
V_239 = V_240 ;
}
