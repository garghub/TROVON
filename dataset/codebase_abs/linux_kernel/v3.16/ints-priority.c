static void T_1 F_1 ( void )
{
unsigned V_1 , V_2 = 0 ;
for ( V_1 = 0 ; V_1 <= V_3 - V_4 ; V_1 ++ ) {
int V_5 ;
V_6 [ V_1 ] . V_7 = V_6 [ V_1 ] . V_8 = & V_9 [ V_2 ] ;
for ( V_5 = 0 ; V_5 < V_10 ; V_5 += 4 ) {
int V_11 ;
T_2 V_12 =
F_2 ( ( unsigned long * ) V_13 +
#if F_3 ( V_14 ) || F_3 ( V_15 ) || \
F_3 ( V_16 ) || F_3 ( V_17 )
( ( V_5 % 32 ) >> 3 ) + ( ( V_5 / 32 ) * ( ( V_18 - V_13 ) / 4 ) )
#else
( V_5 >> 3 )
#endif
) ;
for ( V_11 = V_5 ; V_11 < V_5 + 4 ; ++ V_11 ) {
int V_19 = ( V_11 & 7 ) * 4 ;
if ( V_1 == ( 0xf & ( V_12 >> V_19 ) ) ) {
V_9 [ V_2 ] . V_20 = V_4 + V_11 ;
V_9 [ V_2 ] . V_21 = 1 << ( V_11 % 32 ) ;
V_6 [ V_1 ] . V_7 ++ ;
V_2 ++ ;
}
}
}
}
}
void F_4 ( struct V_22 * V_23 )
{
}
static void F_5 ( struct V_22 * V_23 )
{
V_24 &= ~ ( 1 << V_23 -> V_25 ) ;
if ( ! F_6 () )
F_7 () ;
}
static void F_8 ( struct V_22 * V_23 )
{
V_24 |= 1 << V_23 -> V_25 ;
if ( ! F_6 () )
F_7 () ;
return;
}
void F_9 ( unsigned int V_25 )
{
unsigned long V_26 = F_10 () ;
#ifdef F_11
unsigned V_27 = F_12 ( V_25 ) / 32 ;
unsigned V_28 = F_12 ( V_25 ) % 32 ;
F_13 ( V_27 , F_14 ( V_27 ) &
~ ( 1 << V_28 ) ) ;
# if F_3 ( V_29 ) || F_3 ( V_30 )
F_15 ( V_27 , F_16 ( V_27 ) &
~ ( 1 << V_28 ) ) ;
# endif
#else
F_13 ( F_14 () &
~ ( 1 << F_12 ( V_25 ) ) ) ;
#endif
F_17 ( V_26 ) ;
}
static void F_18 ( struct V_22 * V_23 )
{
F_9 ( V_23 -> V_25 ) ;
}
static void F_19 ( struct V_22 * V_23 )
{
F_20 ( V_23 -> V_25 , V_23 -> V_31 ) ;
}
static int F_21 ( struct V_22 * V_23 ,
const struct V_32 * V_33 , bool V_34 )
{
F_9 ( V_23 -> V_25 ) ;
F_20 ( V_23 -> V_25 , V_33 ) ;
return 0 ;
}
static void F_19 ( struct V_22 * V_23 )
{
F_22 ( V_23 -> V_25 ) ;
}
int F_23 ( unsigned int V_25 , unsigned int V_35 )
{
T_2 V_36 , V_37 , V_38 = 0 ;
unsigned long V_26 ;
V_36 = F_12 ( V_25 ) / 32 ;
V_37 = F_12 ( V_25 ) % 32 ;
switch ( V_25 ) {
#ifdef F_24
case F_24 :
V_38 |= V_39 ;
break;
#endif
#ifdef F_25
case F_25 :
V_38 |= V_40 ;
break;
#endif
#ifdef F_26
case F_26 :
V_38 |= V_40 ;
break;
#endif
#ifdef F_27
case F_27 :
V_38 |= V_41 ;
break;
#endif
#ifdef F_28
case V_42 :
V_38 |= V_43 ;
break;
#endif
default:
break;
}
V_26 = F_10 () ;
if ( V_35 ) {
V_44 [ V_36 ] |= ( 1 << V_37 ) ;
V_45 |= V_38 ;
} else {
V_44 [ V_36 ] &= ~ ( 1 << V_37 ) ;
V_45 &= ~ V_38 ;
}
F_17 ( V_26 ) ;
return 0 ;
}
static int F_29 ( struct V_22 * V_23 , unsigned int V_35 )
{
return F_23 ( V_23 -> V_25 , V_35 ) ;
}
inline int F_23 ( unsigned int V_25 , unsigned int V_35 )
{
return 0 ;
}
static void F_30 ( struct V_22 * V_23 )
{
unsigned long V_26 = F_10 () ;
unsigned int V_46 = F_12 ( V_23 -> V_25 ) ;
F_31 ( 0 , V_47 , V_46 ) ;
F_17 ( V_26 ) ;
}
static void F_32 ( struct V_22 * V_23 )
{
unsigned long V_26 = F_10 () ;
unsigned int V_46 = F_12 ( V_23 -> V_25 ) ;
F_31 ( 0 , V_47 , V_46 ) ;
F_17 ( V_26 ) ;
}
static void F_33 ( struct V_22 * V_23 )
{
unsigned long V_26 = F_10 () ;
unsigned int V_46 = F_12 ( V_23 -> V_25 ) ;
F_34 ( V_48 , V_46 ) ;
F_17 ( V_26 ) ;
}
static void F_35 ( unsigned int V_46 )
{
unsigned long V_26 = F_10 () ;
T_3 V_49 = F_36 ( V_46 ) ;
V_49 |= V_50 ;
F_37 ( V_46 , V_49 ) ;
F_17 ( V_26 ) ;
}
static void F_38 ( unsigned int V_46 )
{
unsigned long V_26 = F_10 () ;
T_3 V_49 = F_36 ( V_46 ) ;
V_49 &= ( ( T_3 ) ~ V_50 ) ;
F_37 ( V_46 , V_49 ) ;
F_17 ( V_26 ) ;
}
static void F_39 ( unsigned int V_46 , unsigned int V_51 )
{
unsigned long V_26 = F_10 () ;
T_3 V_49 = F_36 ( V_46 ) ;
V_49 &= ( ( T_3 ) ~ V_52 ) ;
F_37 ( V_46 , V_49 | ( ( V_51 << 20 ) & V_52 ) ) ;
F_17 ( V_26 ) ;
}
static void F_40 ( unsigned int V_46 )
{
unsigned long V_26 = F_10 () ;
T_3 V_49 = F_36 ( V_46 ) ;
if ( V_46 == F_12 ( V_53 ) )
V_49 |= V_54 ;
else
V_49 |= V_55 ;
F_37 ( V_46 , V_49 ) ;
F_17 ( V_26 ) ;
}
static void F_41 ( unsigned int V_46 )
{
unsigned long V_26 = F_10 () ;
T_3 V_49 = F_36 ( V_46 ) ;
V_49 &= ( ( T_3 ) ~ V_55 ) ;
F_37 ( V_46 , V_49 ) ;
F_17 ( V_26 ) ;
}
static void F_42 ( struct V_22 * V_23 )
{
unsigned long V_26 = F_10 () ;
unsigned int V_46 = F_12 ( V_23 -> V_25 ) ;
F_40 ( V_46 ) ;
F_35 ( V_46 ) ;
F_17 ( V_26 ) ;
}
static void F_43 ( struct V_22 * V_23 )
{
unsigned long V_26 = F_10 () ;
unsigned int V_46 = F_12 ( V_23 -> V_25 ) ;
F_41 ( V_46 ) ;
F_38 ( V_46 ) ;
F_17 ( V_26 ) ;
}
static void F_44 ( unsigned int V_56 , T_4 * V_57 )
{
unsigned long V_26 = F_10 () ;
T_3 V_49 ;
int V_58 ;
F_31 ( 0 , V_59 , V_56 ) ;
for ( V_58 = 0 ; V_58 < V_60 - F_45 ( 0 ) ; V_58 ++ ) {
V_49 = F_36 ( V_58 ) & ~ V_61 ;
V_49 |= V_57 [ V_58 ] << V_62 ;
F_37 ( V_58 , V_49 ) ;
}
F_17 ( V_26 ) ;
}
void F_46 ( unsigned int V_25 )
{
unsigned long V_26 = F_10 () ;
unsigned int V_46 = F_12 ( V_25 ) ;
F_34 ( V_63 , V_46 ) ;
F_17 ( V_26 ) ;
}
static void F_47 ( void )
{
F_39 ( 34 , 0 ) ;
F_39 ( 35 , 1 ) ;
F_40 ( 35 ) ;
F_35 ( 35 ) ;
F_39 ( 36 , 0 ) ;
F_39 ( 37 , 1 ) ;
F_40 ( 37 ) ;
F_35 ( 37 ) ;
}
void F_48 ( void )
{
F_31 ( 0 , V_64 , V_65 ) ;
F_49 ( 100 ) ;
F_50 ( V_66 ) ;
F_31 ( 0 , V_64 , V_67 | V_68 ) ;
}
void F_51 ( T_3 V_69 )
{
}
void F_52 ( T_3 V_69 )
{
T_3 V_70 ;
T_3 V_71 ;
V_70 = V_69 & V_72 ;
V_71 = F_53 ( V_70 , V_73 ) ;
if ( V_71 & V_74 ) {
switch ( V_71 & V_75 ) {
case V_76 :
F_54 ( V_77 L_1 ) ;
break;
default:
F_54 ( V_77 L_2 ) ;
}
}
}
void F_55 ( T_3 V_69 )
{
T_3 V_46 ;
T_3 V_78 ;
V_46 = V_69 & V_79 ;
V_78 = F_56 ( V_46 ) ;
}
void F_57 ( T_3 V_80 )
{
if ( V_80 & V_81 ) {
switch ( V_80 & V_82 ) {
case 0 :
F_51 ( V_80 ) ;
break;
case V_83 :
F_52 ( V_80 ) ;
break;
case V_84 :
F_55 ( V_80 ) ;
break;
}
}
}
static T_5 F_58 ( int V_25 , void * V_85 )
{
struct V_86 * V_87 = F_59 () ;
switch ( V_25 ) {
case V_88 :
F_60 ( V_87 ) ;
break;
case V_89 :
F_61 ( V_87 ) ;
F_62 ( V_87 ) ;
F_63 ( V_87 ) ;
F_54 ( V_90 L_3 ) ;
F_64 ( V_91 , NULL ) ;
F_65 () ;
F_66 ( L_4 ) ;
break;
case V_92 :
F_66 ( L_5 ) ;
break;
case V_93 :
F_67 ( L_6 ) ;
F_57 ( F_2 ( V_94 ) ) ;
break;
default:
F_66 ( L_7 , V_25 ) ;
}
return V_95 ;
}
void F_68 ( unsigned V_25 )
{
#ifdef F_69
struct V_86 V_96 ;
F_70 ( V_25 ) ;
F_71 ( V_25 , & V_96 ) ;
F_72 ( V_25 ) ;
#else
F_73 ( V_25 ) ;
#endif
}
static void F_74 ( unsigned int V_25 )
{
switch ( V_25 ) {
case V_97 :
F_75 (
F_76 () &
F_77 () ) ;
F_78 (
F_79 () &
F_80 () ) ;
break;
case V_98 :
F_81 (
F_82 () &
F_83 () ) ;
break;
case V_99 :
F_84 (
F_85 () &
F_86 () ) ;
break;
case V_100 :
F_87 (
F_88 () | V_101 | V_102 ) ;
break;
default:
F_89 ( 1L << ( V_25 - V_103 ) ) ;
break;
}
}
static void F_90 ( struct V_22 * V_23 )
{
unsigned int V_25 = V_23 -> V_25 ;
V_104 &= ~ ( 1L << ( V_25 - V_103 ) ) ;
#ifdef F_91
switch ( V_25 ) {
case V_103 :
F_92 ( F_93 () & ~ V_105 ) ;
break;
default:
break;
}
#else
if ( ! V_104 )
F_9 ( V_106 ) ;
#endif
F_74 ( V_25 ) ;
}
static void F_94 ( struct V_22 * V_23 )
{
unsigned int V_25 = V_23 -> V_25 ;
#ifdef F_91
switch ( V_25 ) {
case V_103 :
F_92 ( F_93 () | V_105 ) ;
break;
default:
break;
}
#else
if ( ! V_104 )
F_22 ( V_106 ) ;
#endif
V_104 |= 1L << ( V_25 - V_103 ) ;
}
int F_95 ( struct V_22 * V_23 , unsigned int V_35 )
{
#ifdef F_91
return F_23 ( V_107 , V_35 ) ;
#else
return F_23 ( V_106 , V_35 ) ;
#endif
}
void F_96 ( unsigned int V_108 ,
struct V_109 * V_110 )
{
int V_58 , V_25 = 0 ;
T_2 V_111 = F_97 () ;
for ( V_58 = 0 ; V_58 <= ( V_112 - V_103 ) ; V_58 ++ )
if ( V_111 & ( 1L << V_58 ) ) {
V_25 = V_103 + V_58 ;
break;
}
if ( V_25 ) {
if ( V_104 & ( 1L << ( V_25 - V_103 ) ) ) {
F_68 ( V_25 ) ;
} else {
F_74 ( V_25 ) ;
F_98 ( L_8
L_9 ,
V_25 ) ;
}
} else
F_54 ( V_113
L_10
L_11
L_12 ,
V_114 , __FILE__ , __LINE__ , V_111 ) ;
}
static inline void F_99 ( unsigned V_25 , T_6 V_115 )
{
#ifdef F_69
V_115 = V_116 ;
#endif
F_100 ( V_25 , V_115 ) ;
}
static void F_101 ( struct V_22 * V_23 )
{
F_102 ( F_103 ( V_23 -> V_25 ) , 0 ) ;
}
static void F_104 ( struct V_22 * V_23 )
{
unsigned int V_25 = V_23 -> V_25 ;
T_2 V_117 = F_103 ( V_25 ) ;
if ( ! F_105 ( V_23 ) )
F_102 ( V_117 , 0 ) ;
F_106 ( V_117 , 0 ) ;
}
static void F_107 ( struct V_22 * V_23 )
{
F_106 ( F_103 ( V_23 -> V_25 ) , 0 ) ;
}
static void F_108 ( struct V_22 * V_23 )
{
F_106 ( F_103 ( V_23 -> V_25 ) , 1 ) ;
}
static unsigned int F_109 ( struct V_22 * V_23 )
{
T_2 V_117 = F_103 ( V_23 -> V_25 ) ;
if ( F_110 ( V_117 , V_118 ) )
F_111 ( V_117 ) ;
F_108 ( V_23 ) ;
return 0 ;
}
static void F_112 ( struct V_22 * V_23 )
{
T_2 V_117 = F_103 ( V_23 -> V_25 ) ;
F_107 ( V_23 ) ;
F_113 ( V_117 , V_118 ) ;
F_114 ( V_117 ) ;
}
static int F_115 ( struct V_22 * V_23 , unsigned int type )
{
unsigned int V_25 = V_23 -> V_25 ;
int V_119 ;
char V_120 [ 16 ] ;
T_2 V_117 = F_103 ( V_25 ) ;
if ( type == V_121 ) {
if ( F_116 ( V_117 , V_118 ) )
return 0 ;
type = V_122 | V_123 ;
}
if ( type & ( V_122 | V_123 |
V_124 | V_125 ) ) {
snprintf ( V_120 , 16 , L_13 , V_25 ) ;
V_119 = F_117 ( V_117 , V_120 ) ;
if ( V_119 )
return V_119 ;
if ( F_110 ( V_117 , V_118 ) )
F_111 ( V_117 ) ;
} else {
F_113 ( V_117 , V_118 ) ;
return 0 ;
}
F_118 ( V_117 , 0 ) ;
F_119 ( V_117 , 0 ) ;
if ( ( type & ( V_122 | V_123 ) )
== ( V_122 | V_123 ) )
F_120 ( V_117 , 1 ) ;
else
F_120 ( V_117 , 0 ) ;
if ( ( type & ( V_123 | V_125 ) ) )
F_121 ( V_117 , 1 ) ;
else
F_121 ( V_117 , 0 ) ;
if ( type & ( V_122 | V_123 ) ) {
F_122 ( V_117 , 1 ) ;
F_118 ( V_117 , 1 ) ;
F_102 ( V_117 , 0 ) ;
} else {
F_122 ( V_117 , 0 ) ;
F_118 ( V_117 , 1 ) ;
}
if ( type & ( V_122 | V_123 ) )
F_99 ( V_25 , V_126 ) ;
else
F_99 ( V_25 , V_116 ) ;
return 0 ;
}
static void F_123 ( unsigned int V_25 )
{
unsigned int V_127 , V_33 ;
V_127 = F_103 ( V_25 ) ;
V_33 = F_124 ( V_127 ) & F_125 ( V_127 ) ;
while ( V_33 ) {
if ( V_33 & 1 )
F_68 ( V_25 ) ;
V_25 ++ ;
V_33 >>= 1 ;
}
}
void F_126 ( unsigned int V_128 ,
struct V_109 * V_129 )
{
unsigned int V_25 ;
switch ( V_128 ) {
#if F_3 ( F_91 )
case V_130 :
F_123 ( V_131 ) ;
V_25 = V_132 ;
break;
case V_133 :
V_25 = V_134 ;
break;
#elif F_3 ( V_135 )
case V_136 :
V_25 = V_131 ;
break;
#elif F_3 ( V_137 )
case V_138 :
V_25 = V_131 ;
break;
#elif F_3 ( V_15 ) || F_3 ( V_14 )
case V_138 :
V_25 = V_131 ;
break;
case V_139 :
V_25 = V_132 ;
break;
case V_140 :
V_25 = V_134 ;
break;
#elif F_3 ( V_141 )
case V_142 :
V_25 = V_131 ;
break;
case V_143 :
V_25 = V_144 ;
break;
case V_145 :
V_25 = V_146 ;
break;
#endif
default:
F_127 () ;
return;
}
F_123 ( V_25 ) ;
}
static int F_128 ( struct V_22 * V_23 , unsigned int V_35 )
{
return F_129 ( F_103 ( V_23 -> V_25 ) , V_35 ) ;
}
static int F_130 ( void )
{
T_2 V_36 ;
for ( V_36 = 0 ; V_36 < V_147 ; V_36 ++ )
V_148 [ V_36 ] = F_36 ( V_36 + F_12 ( V_149 ) ) ;
return 0 ;
}
static void F_131 ( void )
{
T_2 V_36 ;
F_31 ( 0 , V_64 , V_65 ) ;
F_49 ( 100 ) ;
F_50 ( V_66 ) ;
F_31 ( 0 , V_64 , V_67 | V_68 ) ;
for ( V_36 = 0 ; V_36 < V_147 ; V_36 ++ )
F_37 ( V_36 + F_12 ( V_149 ) , V_148 [ V_36 ] ) ;
}
void F_132 ( void )
{
F_133 ( V_150 ) ;
F_134 ( V_151 ) ;
F_135 ( V_152 ) ;
F_136 ( V_153 ) ;
F_137 ( V_154 ) ;
F_138 ( V_155 ) ;
F_139 ( V_156 ) ;
F_140 ( V_157 ) ;
F_141 ( V_158 ) ;
F_142 ( V_159 ) ;
F_143 ( V_160 ) ;
F_144 ( V_161 ) ;
F_145 ( V_162 ) ;
F_146 () ;
}
int T_1 F_147 ( void )
{
int V_25 ;
unsigned long V_163 = 0 ;
#ifdef F_11
F_148 ( V_164 ) ;
F_149 ( V_164 ) ;
# ifdef F_150
F_151 ( V_164 ) ;
# endif
# if F_3 ( V_29 ) || F_3 ( V_30 )
F_152 ( V_164 ) ;
F_153 ( V_164 ) ;
# endif
#else
F_13 ( V_164 ) ;
#endif
F_154 () ;
for ( V_25 = 0 ; V_25 <= V_60 ; V_25 ++ ) {
if ( V_25 <= V_165 )
F_155 ( V_25 , & V_166 ) ;
else
F_155 ( V_25 , & V_167 ) ;
switch ( V_25 ) {
#if ! V_168
#if F_3 ( F_91 )
case V_133 :
case V_130 :
#elif F_3 ( V_135 )
case V_136 :
#elif F_3 ( V_15 ) || F_3 ( V_14 )
case V_138 :
case V_139 :
case V_140 :
#elif F_3 ( V_141 )
case V_142 :
case V_143 :
case V_145 :
#elif F_3 ( V_137 )
case V_138 :
#endif
F_156 ( V_25 , F_126 ) ;
break;
#endif
#if F_3 ( V_169 ) || F_3 ( V_170 )
case V_106 :
F_156 ( V_25 ,
F_96 ) ;
break;
#endif
#if F_3 ( V_29 ) || F_3 ( V_30 )
case V_171 :
case V_172 :
F_157 ( V_25 , V_173 ) ;
break;
#endif
#ifdef F_158
case V_165 :
# ifdef V_29
F_157 ( V_25 , V_173 ) ;
# else
F_157 ( V_25 , V_174 ) ;
# endif
break;
#endif
#ifdef F_159
case V_175 :
F_157 ( V_25 , V_174 ) ;
break;
#endif
default:
#ifdef F_69
F_157 ( V_25 , V_116 ) ;
#else
F_157 ( V_25 , V_174 ) ;
#endif
break;
}
}
F_160 () ;
#if ( F_3 ( V_169 ) || F_3 ( V_170 ) )
for ( V_25 = V_103 ; V_25 <= V_112 ; V_25 ++ )
F_161 ( V_25 , & V_176 ,
V_116 ) ;
#endif
#ifdef F_162
for ( V_25 = V_177 ;
V_25 < ( V_177 + V_178 ) ; V_25 ++ )
F_161 ( V_25 , & V_179 ,
V_116 ) ;
#endif
F_163 ( 0 ) ;
F_146 () ;
V_163 = F_164 () ;
F_146 () ;
F_165 ( V_163 ) ;
F_146 () ;
F_54 ( V_180 L_14 ) ;
F_166 () ;
F_1 () ;
V_24 |= V_181 |
V_182 | V_183 | V_184 | V_185 |
V_186 | V_187 | V_188 | V_189 | V_190 ;
#ifdef F_167
F_168 ( V_191 ) ;
# ifdef F_169
if ( V_192 )
F_170 ( F_171 ( 10 ) | F_171 ( 11 ) ) ;
else
F_170 ( V_191 ) ;
# endif
# ifdef F_172
F_173 ( V_191 ) ;
# endif
#else
F_174 ( V_191 ) ;
#endif
return 0 ;
}
static int F_175 ( int V_193 )
{
struct V_194 * V_1 = V_6 [ V_193 - V_4 ] . V_8 ;
struct V_194 * V_195 = V_6 [ V_193 - V_4 ] . V_7 ;
unsigned long V_196 [ 3 ] ;
if ( F_176 ( V_193 == V_197 ) )
return V_165 ;
#ifdef F_177
V_196 [ 0 ] = F_14 () & F_178 () ;
#else
if ( F_179 () ) {
# ifdef F_180
V_196 [ 0 ] = F_181 () & F_182 () ;
V_196 [ 1 ] = F_183 () & F_184 () ;
# endif
} else {
V_196 [ 0 ] = F_185 () & F_186 () ;
V_196 [ 1 ] = F_187 () & F_188 () ;
}
#endif
#ifdef F_189
V_196 [ 2 ] = F_190 () & F_191 () ;
#endif
for (; ; V_1 ++ ) {
if ( V_1 >= V_195 )
return - 1 ;
#ifdef F_177
if ( V_196 [ 0 ] & V_1 -> V_21 )
#else
if ( V_196 [ ( V_1 -> V_20 - V_4 ) / 32 ] & V_1 -> V_21 )
#endif
return V_1 -> V_20 ;
}
}
int T_1 F_147 ( void )
{
int V_25 ;
unsigned long V_163 = 0 ;
F_50 ( V_198 ) ;
F_154 () ;
for ( V_25 = 0 ; V_25 <= V_60 ; V_25 ++ ) {
if ( V_25 <= V_165 ) {
F_161 ( V_25 , & V_166 ,
V_174 ) ;
#if F_3 ( F_158 ) && F_3 ( V_29 )
if ( V_25 == V_165 )
F_157 ( V_25 , V_173 ) ;
#endif
} else if ( V_25 >= F_45 ( 34 ) && V_25 <= F_45 ( 37 ) ) {
F_161 ( V_25 , & V_199 ,
V_173 ) ;
} else {
F_155 ( V_25 , & V_199 ) ;
F_157 ( V_25 , V_200 ) ;
F_192 ( V_25 , F_30 ) ;
}
}
F_163 ( 0 ) ;
F_146 () ;
V_163 = F_164 () ;
F_146 () ;
F_165 ( V_163 ) ;
F_146 () ;
F_54 ( V_180 L_14 ) ;
F_44 ( V_201 , V_57 ) ;
V_24 |= V_181 |
V_182 | V_183 | V_184 | V_185 |
V_186 | V_187 | V_188 | V_189 | V_190 ;
F_193 ( V_202 | V_203 | V_204 ) ;
F_40 ( F_12 ( V_53 ) ) ;
F_35 ( F_12 ( V_53 ) ) ;
F_31 ( 0 , V_64 , V_65 ) ;
F_49 ( 100 ) ;
F_50 ( V_66 ) ;
F_31 ( 0 , V_64 , V_67 | V_68 ) ;
F_31 ( 1 , V_64 , V_67 | V_68 ) ;
F_47 () ;
#ifdef F_194
F_195 ( & V_205 ) ;
#endif
V_206 . V_207 = F_58 ;
#ifdef F_196
F_197 ( V_92 , & V_206 ) ;
#endif
F_197 ( V_88 , & V_206 ) ;
F_197 ( V_93 , & V_206 ) ;
return 0 ;
}
static int F_175 ( int V_193 )
{
if ( F_176 ( V_193 == V_197 ) )
return V_165 ;
return F_45 ( F_53 ( 0 , V_47 ) ) ;
}
void F_198 ( int V_193 , struct V_86 * V_87 )
{
int V_25 = F_175 ( V_193 ) ;
if ( V_25 == - 1 )
return;
F_199 ( V_25 , V_87 ) ;
}
int F_200 ( unsigned V_25 )
{
int V_208 , V_209 ;
if ( V_25 <= V_165 )
return V_25 ;
#ifdef F_201
if ( V_25 >= F_45 ( 0 ) )
return V_210 ;
#else
for ( V_208 = 0 ; V_208 < V_10 ; V_208 ++ ) {
struct V_194 * V_1 = V_9 + V_208 ;
if ( V_1 -> V_20 == V_25 ) {
for ( V_209 = 0 ; V_209 <= V_3 - V_4 ; V_209 ++ ) {
if ( V_6 [ V_209 ] . V_8 <= V_1 &&
V_6 [ V_209 ] . V_7 > V_1 )
return V_4 + V_209 ;
}
}
}
#endif
return V_211 ;
}
T_7 int F_202 ( int V_193 , struct V_86 * V_96 )
{
struct V_212 * V_213 = F_203 () ;
struct V_214 * V_215 = V_216 ;
int V_25 , V_217 = 0 ;
V_25 = F_175 ( V_193 ) ;
if ( V_25 == - 1 )
return 0 ;
if ( V_25 == V_218 ) {
#if ! F_3 ( V_219 ) || F_3 ( F_159 )
F_204 ( 1 ) ;
#endif
F_205 ( V_220 ) . V_221 = V_96 -> V_221 ;
F_205 ( V_220 ) . V_222 = V_96 -> V_222 ;
if ( V_215 != V_223 )
F_205 ( V_220 ) . V_221 &= ~ 0x10 ;
else
F_205 ( V_220 ) . V_221 |= 0x10 ;
}
if ( V_215 == V_223 ) {
V_217 = F_110 ( V_224 , & V_213 -> V_111 ) ;
F_206 () ;
}
F_70 ( V_25 ) ;
F_71 ( V_25 , V_96 ) ;
F_72 ( V_25 ) ;
if ( F_207 ( V_96 ) &&
! F_208 () &&
( V_91 -> V_225 & V_226 ) != 0 ) {
V_91 -> V_225 &= ~ V_226 ;
F_209 ( V_227 , V_96 ) ;
}
if ( V_215 == V_223 ) {
F_210 ( V_228 ) ;
if ( ! V_217 ) {
F_113 ( V_224 , & V_213 -> V_111 ) ;
return ! F_116 ( V_229 , & V_213 -> V_111 ) ;
}
}
return 0 ;
}
