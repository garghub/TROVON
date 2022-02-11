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
F_20 ( V_23 -> V_25 ,
F_21 ( V_23 ) ) ;
}
static int F_22 ( struct V_22 * V_23 ,
const struct V_31 * V_32 , bool V_33 )
{
F_9 ( V_23 -> V_25 ) ;
F_20 ( V_23 -> V_25 , V_32 ) ;
return 0 ;
}
static void F_19 ( struct V_22 * V_23 )
{
F_23 ( V_23 -> V_25 ) ;
}
int F_24 ( unsigned int V_25 , unsigned int V_34 )
{
T_2 V_35 , V_36 , V_37 = 0 ;
unsigned long V_26 ;
V_35 = F_12 ( V_25 ) / 32 ;
V_36 = F_12 ( V_25 ) % 32 ;
switch ( V_25 ) {
#ifdef F_25
case F_25 :
V_37 |= V_38 ;
break;
#endif
#ifdef F_26
case F_26 :
V_37 |= V_39 ;
break;
#endif
#ifdef F_27
case F_27 :
V_37 |= V_39 ;
break;
#endif
#ifdef F_28
case F_28 :
V_37 |= V_40 ;
break;
#endif
#ifdef F_29
case V_41 :
V_37 |= V_42 ;
break;
#endif
default:
break;
}
V_26 = F_10 () ;
if ( V_34 ) {
V_43 [ V_35 ] |= ( 1 << V_36 ) ;
V_44 |= V_37 ;
} else {
V_43 [ V_35 ] &= ~ ( 1 << V_36 ) ;
V_44 &= ~ V_37 ;
}
F_17 ( V_26 ) ;
return 0 ;
}
static int F_30 ( struct V_22 * V_23 , unsigned int V_34 )
{
return F_24 ( V_23 -> V_25 , V_34 ) ;
}
inline int F_24 ( unsigned int V_25 , unsigned int V_34 )
{
return 0 ;
}
static void F_31 ( struct V_22 * V_23 )
{
unsigned long V_26 = F_10 () ;
unsigned int V_45 = F_12 ( V_23 -> V_25 ) ;
F_32 ( 0 , V_46 , V_45 ) ;
F_17 ( V_26 ) ;
}
static void F_33 ( struct V_22 * V_23 )
{
unsigned long V_26 = F_10 () ;
unsigned int V_45 = F_12 ( V_23 -> V_25 ) ;
F_32 ( 0 , V_46 , V_45 ) ;
F_17 ( V_26 ) ;
}
static void F_34 ( struct V_22 * V_23 )
{
unsigned long V_26 = F_10 () ;
unsigned int V_45 = F_12 ( V_23 -> V_25 ) ;
F_35 ( V_47 , V_45 ) ;
F_17 ( V_26 ) ;
}
static void F_36 ( unsigned int V_45 )
{
unsigned long V_26 = F_10 () ;
T_3 V_48 = F_37 ( V_45 ) ;
V_48 |= V_49 ;
F_38 ( V_45 , V_48 ) ;
F_17 ( V_26 ) ;
}
static void F_39 ( unsigned int V_45 )
{
unsigned long V_26 = F_10 () ;
T_3 V_48 = F_37 ( V_45 ) ;
V_48 &= ( ( T_3 ) ~ V_49 ) ;
F_38 ( V_45 , V_48 ) ;
F_17 ( V_26 ) ;
}
static void F_40 ( unsigned int V_45 , unsigned int V_50 )
{
unsigned long V_26 = F_10 () ;
T_3 V_48 = F_37 ( V_45 ) ;
V_48 &= ( ( T_3 ) ~ V_51 ) ;
F_38 ( V_45 , V_48 | ( ( V_50 << 20 ) & V_51 ) ) ;
F_17 ( V_26 ) ;
}
static void F_41 ( unsigned int V_45 )
{
unsigned long V_26 = F_10 () ;
T_3 V_48 = F_37 ( V_45 ) ;
if ( V_45 == F_12 ( V_52 ) )
V_48 |= V_53 ;
else
V_48 |= V_54 ;
F_38 ( V_45 , V_48 ) ;
F_17 ( V_26 ) ;
}
static void F_42 ( unsigned int V_45 )
{
unsigned long V_26 = F_10 () ;
T_3 V_48 = F_37 ( V_45 ) ;
V_48 &= ( ( T_3 ) ~ V_54 ) ;
F_38 ( V_45 , V_48 ) ;
F_17 ( V_26 ) ;
}
static void F_43 ( struct V_22 * V_23 )
{
unsigned long V_26 = F_10 () ;
unsigned int V_45 = F_12 ( V_23 -> V_25 ) ;
F_41 ( V_45 ) ;
F_36 ( V_45 ) ;
F_17 ( V_26 ) ;
}
static void F_44 ( struct V_22 * V_23 )
{
unsigned long V_26 = F_10 () ;
unsigned int V_45 = F_12 ( V_23 -> V_25 ) ;
F_42 ( V_45 ) ;
F_39 ( V_45 ) ;
F_17 ( V_26 ) ;
}
static void F_45 ( unsigned int V_55 , T_4 * V_56 )
{
unsigned long V_26 = F_10 () ;
T_3 V_48 ;
int V_57 ;
F_32 ( 0 , V_58 , V_55 ) ;
for ( V_57 = 0 ; V_57 < V_59 - F_46 ( 0 ) ; V_57 ++ ) {
V_48 = F_37 ( V_57 ) & ~ V_60 ;
V_48 |= V_56 [ V_57 ] << V_61 ;
F_38 ( V_57 , V_48 ) ;
}
F_17 ( V_26 ) ;
}
void F_47 ( unsigned int V_25 )
{
unsigned long V_26 = F_10 () ;
unsigned int V_45 = F_12 ( V_25 ) ;
F_35 ( V_62 , V_45 ) ;
F_17 ( V_26 ) ;
}
static void F_48 ( void )
{
F_40 ( 34 , 0 ) ;
F_40 ( 35 , 1 ) ;
F_41 ( 35 ) ;
F_36 ( 35 ) ;
F_40 ( 36 , 0 ) ;
F_40 ( 37 , 1 ) ;
F_41 ( 37 ) ;
F_36 ( 37 ) ;
}
void F_49 ( T_3 V_63 )
{
}
void F_50 ( T_3 V_63 )
{
T_3 V_64 ;
T_3 V_65 ;
V_64 = V_63 & V_66 ;
V_65 = F_51 ( V_64 , V_67 ) ;
if ( V_65 & V_68 ) {
switch ( V_65 & V_69 ) {
case V_70 :
F_52 ( V_71 L_1 ) ;
break;
default:
F_52 ( V_71 L_2 ) ;
}
}
}
void F_53 ( T_3 V_63 )
{
T_3 V_45 ;
T_3 V_72 ;
V_45 = V_63 & V_73 ;
V_72 = F_54 ( V_45 ) ;
}
void F_55 ( T_3 V_74 )
{
if ( V_74 & V_75 ) {
switch ( V_74 & V_76 ) {
case 0 :
F_49 ( V_74 ) ;
break;
case V_77 :
F_50 ( V_74 ) ;
break;
case V_78 :
F_53 ( V_74 ) ;
break;
}
}
}
static T_5 F_56 ( int V_25 , void * V_79 )
{
struct V_80 * V_81 = F_57 () ;
switch ( V_25 ) {
case V_82 :
F_58 ( V_81 ) ;
break;
case V_83 :
F_59 ( V_81 ) ;
F_60 ( V_81 ) ;
F_61 ( V_81 ) ;
F_52 ( V_84 L_3 ) ;
F_62 ( V_85 , NULL ) ;
F_63 () ;
F_64 ( L_4 ) ;
break;
case V_86 :
F_64 ( L_5 ) ;
break;
case V_87 :
F_65 ( L_6 ) ;
F_55 ( F_2 ( V_88 ) ) ;
break;
default:
F_64 ( L_7 , V_25 ) ;
}
return V_89 ;
}
void F_66 ( unsigned V_25 )
{
#ifdef F_67
struct V_80 V_90 ;
F_68 ( V_25 ) ;
F_69 ( V_25 , & V_90 ) ;
F_70 ( V_25 ) ;
#else
F_71 ( V_25 ) ;
#endif
}
static void F_72 ( unsigned int V_25 )
{
switch ( V_25 ) {
case V_91 :
F_73 (
F_74 () &
F_75 () ) ;
F_76 (
F_77 () &
F_78 () ) ;
break;
case V_92 :
F_79 (
F_80 () &
F_81 () ) ;
break;
case V_93 :
F_82 (
F_83 () &
F_84 () ) ;
break;
case V_94 :
F_85 (
F_86 () | V_95 | V_96 ) ;
break;
default:
F_87 ( 1L << ( V_25 - V_97 ) ) ;
break;
}
}
static void F_88 ( struct V_22 * V_23 )
{
unsigned int V_25 = V_23 -> V_25 ;
V_98 &= ~ ( 1L << ( V_25 - V_97 ) ) ;
#ifdef F_89
switch ( V_25 ) {
case V_97 :
F_90 ( F_91 () & ~ V_99 ) ;
break;
default:
break;
}
#else
if ( ! V_98 )
F_9 ( V_100 ) ;
#endif
F_72 ( V_25 ) ;
}
static void F_92 ( struct V_22 * V_23 )
{
unsigned int V_25 = V_23 -> V_25 ;
#ifdef F_89
switch ( V_25 ) {
case V_97 :
F_90 ( F_91 () | V_99 ) ;
break;
default:
break;
}
#else
if ( ! V_98 )
F_23 ( V_100 ) ;
#endif
V_98 |= 1L << ( V_25 - V_97 ) ;
}
int F_93 ( struct V_22 * V_23 , unsigned int V_34 )
{
#ifdef F_89
return F_24 ( V_101 , V_34 ) ;
#else
return F_24 ( V_100 , V_34 ) ;
#endif
}
void F_94 ( struct V_102 * V_103 )
{
int V_57 , V_25 = 0 ;
T_2 V_104 = F_95 () ;
for ( V_57 = 0 ; V_57 <= ( V_105 - V_97 ) ; V_57 ++ )
if ( V_104 & ( 1L << V_57 ) ) {
V_25 = V_97 + V_57 ;
break;
}
if ( V_25 ) {
if ( V_98 & ( 1L << ( V_25 - V_97 ) ) ) {
F_66 ( V_25 ) ;
} else {
F_72 ( V_25 ) ;
F_96 ( L_8
L_9 ,
V_25 ) ;
}
} else
F_52 ( V_106
L_10
L_11
L_12 ,
V_107 , __FILE__ , __LINE__ , V_104 ) ;
}
static inline void F_97 ( struct V_22 * V_23 , T_6 V_108 )
{
#ifdef F_67
V_108 = V_109 ;
#endif
F_98 ( V_23 , V_108 ) ;
}
static void F_99 ( struct V_22 * V_23 )
{
F_100 ( F_101 ( V_23 -> V_25 ) , 0 ) ;
}
static void F_102 ( struct V_22 * V_23 )
{
unsigned int V_25 = V_23 -> V_25 ;
T_2 V_110 = F_101 ( V_25 ) ;
if ( ! F_103 ( V_23 ) )
F_100 ( V_110 , 0 ) ;
F_104 ( V_110 , 0 ) ;
}
static void F_105 ( struct V_22 * V_23 )
{
F_104 ( F_101 ( V_23 -> V_25 ) , 0 ) ;
}
static void F_106 ( struct V_22 * V_23 )
{
F_104 ( F_101 ( V_23 -> V_25 ) , 1 ) ;
}
static unsigned int F_107 ( struct V_22 * V_23 )
{
T_2 V_110 = F_101 ( V_23 -> V_25 ) ;
if ( F_108 ( V_110 , V_111 ) )
F_109 ( V_110 ) ;
F_106 ( V_23 ) ;
return 0 ;
}
static void F_110 ( struct V_22 * V_23 )
{
T_2 V_110 = F_101 ( V_23 -> V_25 ) ;
F_105 ( V_23 ) ;
F_111 ( V_110 , V_111 ) ;
F_112 ( V_110 ) ;
}
static int F_113 ( struct V_22 * V_23 , unsigned int type )
{
unsigned int V_25 = V_23 -> V_25 ;
int V_112 ;
char V_113 [ 16 ] ;
T_2 V_110 = F_101 ( V_25 ) ;
if ( type == V_114 ) {
if ( F_114 ( V_110 , V_111 ) )
return 0 ;
type = V_115 | V_116 ;
}
if ( type & ( V_115 | V_116 |
V_117 | V_118 ) ) {
snprintf ( V_113 , 16 , L_13 , V_25 ) ;
V_112 = F_115 ( V_110 , V_113 ) ;
if ( V_112 )
return V_112 ;
if ( F_108 ( V_110 , V_111 ) )
F_109 ( V_110 ) ;
} else {
F_111 ( V_110 , V_111 ) ;
return 0 ;
}
F_116 ( V_110 , 0 ) ;
F_117 ( V_110 , 0 ) ;
if ( ( type & ( V_115 | V_116 ) )
== ( V_115 | V_116 ) )
F_118 ( V_110 , 1 ) ;
else
F_118 ( V_110 , 0 ) ;
if ( ( type & ( V_116 | V_118 ) ) )
F_119 ( V_110 , 1 ) ;
else
F_119 ( V_110 , 0 ) ;
if ( type & ( V_115 | V_116 ) ) {
F_120 ( V_110 , 1 ) ;
F_116 ( V_110 , 1 ) ;
F_100 ( V_110 , 0 ) ;
} else {
F_120 ( V_110 , 0 ) ;
F_116 ( V_110 , 1 ) ;
}
if ( type & ( V_115 | V_116 ) )
F_97 ( V_23 , V_119 ) ;
else
F_97 ( V_23 , V_109 ) ;
return 0 ;
}
static void F_121 ( unsigned int V_25 )
{
unsigned int V_120 , V_32 ;
V_120 = F_101 ( V_25 ) ;
V_32 = F_122 ( V_120 ) & F_123 ( V_120 ) ;
while ( V_32 ) {
if ( V_32 & 1 )
F_66 ( V_25 ) ;
V_25 ++ ;
V_32 >>= 1 ;
}
}
void F_124 ( struct V_102 * V_121 )
{
unsigned int V_122 = F_125 ( V_121 ) ;
unsigned int V_25 ;
switch ( V_122 ) {
#if F_3 ( F_89 )
case V_123 :
F_121 ( V_124 ) ;
V_25 = V_125 ;
break;
case V_126 :
V_25 = V_127 ;
break;
#elif F_3 ( V_128 )
case V_129 :
V_25 = V_124 ;
break;
#elif F_3 ( V_130 )
case V_131 :
V_25 = V_124 ;
break;
#elif F_3 ( V_15 ) || F_3 ( V_14 )
case V_131 :
V_25 = V_124 ;
break;
case V_132 :
V_25 = V_125 ;
break;
case V_133 :
V_25 = V_127 ;
break;
#elif F_3 ( V_134 )
case V_135 :
V_25 = V_124 ;
break;
case V_136 :
V_25 = V_137 ;
break;
case V_138 :
V_25 = V_139 ;
break;
#endif
default:
F_126 () ;
return;
}
F_121 ( V_25 ) ;
}
static int F_127 ( struct V_22 * V_23 , unsigned int V_34 )
{
return F_128 ( F_101 ( V_23 -> V_25 ) , V_34 ) ;
}
static int F_129 ( void )
{
T_2 V_35 ;
for ( V_35 = 0 ; V_35 < V_140 ; V_35 ++ )
V_141 [ V_35 ] = F_37 ( V_35 + F_12 ( V_142 ) ) ;
return 0 ;
}
static void F_130 ( void )
{
T_2 V_35 ;
F_32 ( 0 , V_143 , V_144 ) ;
F_131 ( 100 ) ;
F_132 ( V_145 ) ;
F_32 ( 0 , V_143 , V_146 | V_147 ) ;
for ( V_35 = 0 ; V_35 < V_140 ; V_35 ++ )
F_38 ( V_35 + F_12 ( V_142 ) , V_141 [ V_35 ] ) ;
}
void F_133 ( void )
{
F_134 ( V_148 ) ;
F_135 ( V_149 ) ;
F_136 ( V_150 ) ;
F_137 ( V_151 ) ;
F_138 ( V_152 ) ;
F_139 ( V_153 ) ;
F_140 ( V_154 ) ;
F_141 ( V_155 ) ;
F_142 ( V_156 ) ;
F_143 ( V_157 ) ;
F_144 ( V_158 ) ;
F_145 ( V_159 ) ;
F_146 ( V_160 ) ;
F_147 () ;
}
int T_1 F_148 ( void )
{
int V_25 ;
unsigned long V_161 = 0 ;
#ifdef F_11
F_149 ( V_162 ) ;
F_150 ( V_162 ) ;
# ifdef F_151
F_152 ( V_162 ) ;
# endif
# if F_3 ( V_29 ) || F_3 ( V_30 )
F_153 ( V_162 ) ;
F_154 ( V_162 ) ;
# endif
#else
F_13 ( V_162 ) ;
#endif
F_155 () ;
for ( V_25 = 0 ; V_25 <= V_59 ; V_25 ++ ) {
if ( V_25 <= V_163 )
F_156 ( V_25 , & V_164 ) ;
else
F_156 ( V_25 , & V_165 ) ;
switch ( V_25 ) {
#if ! V_166
#if F_3 ( F_89 )
case V_126 :
case V_123 :
#elif F_3 ( V_128 )
case V_129 :
#elif F_3 ( V_15 ) || F_3 ( V_14 )
case V_131 :
case V_132 :
case V_133 :
#elif F_3 ( V_134 )
case V_135 :
case V_136 :
case V_138 :
#elif F_3 ( V_130 )
case V_131 :
#endif
F_157 ( V_25 , F_124 ) ;
break;
#endif
#if F_3 ( V_167 ) || F_3 ( V_168 )
case V_100 :
F_157 ( V_25 ,
F_94 ) ;
break;
#endif
#if F_3 ( V_29 ) || F_3 ( V_30 )
case V_169 :
case V_170 :
F_158 ( V_25 , V_171 ) ;
break;
#endif
#ifdef F_159
case V_163 :
# ifdef V_29
F_158 ( V_25 , V_171 ) ;
# else
F_158 ( V_25 , V_172 ) ;
# endif
break;
#endif
#ifdef F_160
case V_173 :
F_158 ( V_25 , V_172 ) ;
break;
#endif
default:
#ifdef F_67
F_158 ( V_25 , V_109 ) ;
#else
F_158 ( V_25 , V_172 ) ;
#endif
break;
}
}
F_161 () ;
#if ( F_3 ( V_167 ) || F_3 ( V_168 ) )
for ( V_25 = V_97 ; V_25 <= V_105 ; V_25 ++ )
F_162 ( V_25 , & V_174 ,
V_109 ) ;
#endif
#ifdef F_163
for ( V_25 = V_175 ;
V_25 < ( V_175 + V_176 ) ; V_25 ++ )
F_162 ( V_25 , & V_177 ,
V_109 ) ;
#endif
F_164 ( 0 ) ;
F_147 () ;
V_161 = F_165 () ;
F_147 () ;
F_166 ( V_161 ) ;
F_147 () ;
F_52 ( V_178 L_14 ) ;
F_167 () ;
F_1 () ;
V_24 |= V_179 |
V_180 | V_181 | V_182 | V_183 |
V_184 | V_185 | V_186 | V_187 | V_188 ;
#ifdef F_168
F_169 ( V_189 ) ;
# ifdef F_170
if ( V_190 )
F_171 ( F_172 ( 10 ) | F_172 ( 11 ) ) ;
else
F_171 ( V_189 ) ;
# endif
# ifdef F_173
F_174 ( V_189 ) ;
# endif
#else
F_175 ( V_189 ) ;
#endif
return 0 ;
}
static int F_176 ( int V_191 )
{
struct V_192 * V_1 = V_6 [ V_191 - V_4 ] . V_8 ;
struct V_192 * V_193 = V_6 [ V_191 - V_4 ] . V_7 ;
unsigned long V_194 [ 3 ] ;
if ( F_177 ( V_191 == V_195 ) )
return V_163 ;
#ifdef F_178
V_194 [ 0 ] = F_14 () & F_179 () ;
#else
if ( F_180 () ) {
# ifdef F_181
V_194 [ 0 ] = F_182 () & F_183 () ;
V_194 [ 1 ] = F_184 () & F_185 () ;
# endif
} else {
V_194 [ 0 ] = F_186 () & F_187 () ;
V_194 [ 1 ] = F_188 () & F_189 () ;
}
#endif
#ifdef F_190
V_194 [ 2 ] = F_191 () & F_192 () ;
#endif
for (; ; V_1 ++ ) {
if ( V_1 >= V_193 )
return - 1 ;
#ifdef F_178
if ( V_194 [ 0 ] & V_1 -> V_21 )
#else
if ( V_194 [ ( V_1 -> V_20 - V_4 ) / 32 ] & V_1 -> V_21 )
#endif
return V_1 -> V_20 ;
}
}
int T_1 F_148 ( void )
{
int V_25 ;
unsigned long V_161 = 0 ;
F_132 ( V_196 ) ;
F_155 () ;
for ( V_25 = 0 ; V_25 <= V_59 ; V_25 ++ ) {
if ( V_25 <= V_163 ) {
F_162 ( V_25 , & V_164 ,
V_172 ) ;
#if F_3 ( F_159 ) && F_3 ( V_29 )
if ( V_25 == V_163 )
F_158 ( V_25 , V_171 ) ;
#endif
} else if ( V_25 >= F_46 ( 34 ) && V_25 <= F_46 ( 37 ) ) {
F_162 ( V_25 , & V_197 ,
V_171 ) ;
} else {
F_156 ( V_25 , & V_197 ) ;
F_158 ( V_25 , V_198 ) ;
F_193 ( V_25 , F_31 ) ;
}
}
F_164 ( 0 ) ;
F_147 () ;
V_161 = F_165 () ;
F_147 () ;
F_166 ( V_161 ) ;
F_147 () ;
F_52 ( V_178 L_14 ) ;
F_45 ( V_199 , V_56 ) ;
V_24 |= V_179 |
V_180 | V_181 | V_182 | V_183 |
V_184 | V_185 | V_186 | V_187 | V_188 ;
F_194 ( V_200 | V_201 | V_202 ) ;
F_41 ( F_12 ( V_52 ) ) ;
F_36 ( F_12 ( V_52 ) ) ;
F_32 ( 0 , V_143 , V_144 ) ;
F_131 ( 100 ) ;
F_132 ( V_145 ) ;
F_32 ( 0 , V_143 , V_146 | V_147 ) ;
F_32 ( 1 , V_143 , V_146 | V_147 ) ;
F_48 () ;
#ifdef F_195
F_196 ( & V_203 ) ;
#endif
V_204 . V_205 = F_56 ;
#ifdef F_197
F_198 ( V_86 , & V_204 ) ;
#endif
F_198 ( V_82 , & V_204 ) ;
F_198 ( V_87 , & V_204 ) ;
return 0 ;
}
static int F_176 ( int V_191 )
{
if ( F_177 ( V_191 == V_195 ) )
return V_163 ;
return F_46 ( F_51 ( 0 , V_46 ) ) ;
}
void F_199 ( int V_191 , struct V_80 * V_81 )
{
int V_25 = F_176 ( V_191 ) ;
if ( V_25 == - 1 )
return;
F_200 ( V_25 , V_81 ) ;
}
int F_201 ( unsigned V_25 )
{
int V_206 , V_207 ;
if ( V_25 <= V_163 )
return V_25 ;
#ifdef F_202
if ( V_25 >= F_46 ( 0 ) )
return V_208 ;
#else
for ( V_206 = 0 ; V_206 < V_10 ; V_206 ++ ) {
struct V_192 * V_1 = V_9 + V_206 ;
if ( V_1 -> V_20 == V_25 ) {
for ( V_207 = 0 ; V_207 <= V_3 - V_4 ; V_207 ++ ) {
if ( V_6 [ V_207 ] . V_8 <= V_1 &&
V_6 [ V_207 ] . V_7 > V_1 )
return V_4 + V_207 ;
}
}
}
#endif
return V_209 ;
}
T_7 int F_203 ( int V_191 , struct V_80 * V_90 )
{
struct V_210 * V_211 = F_204 () ;
struct V_212 * V_213 = V_214 ;
int V_25 , V_215 = 0 ;
V_25 = F_176 ( V_191 ) ;
if ( V_25 == - 1 )
return 0 ;
if ( V_25 == V_216 ) {
#if ! F_3 ( V_217 ) || F_3 ( F_160 )
F_205 ( 1 ) ;
#endif
F_206 ( V_218 . V_219 , V_90 -> V_219 ) ;
F_206 ( V_218 . V_220 , V_90 -> V_220 ) ;
if ( V_213 != V_221 )
F_207 ( V_218 . V_219 , ~ 0x10 ) ;
else
F_208 ( V_218 . V_219 , 0x10 ) ;
}
if ( V_213 == V_221 ) {
V_215 = F_108 ( V_222 , & V_211 -> V_104 ) ;
F_209 () ;
}
F_68 ( V_25 ) ;
F_69 ( V_25 , V_90 ) ;
F_70 ( V_25 ) ;
if ( F_210 ( V_90 ) &&
! F_211 () &&
( V_85 -> V_223 & V_224 ) != 0 ) {
V_85 -> V_223 &= ~ V_224 ;
F_212 ( V_225 , V_90 ) ;
}
if ( V_213 == V_221 ) {
F_213 ( V_226 ) ;
if ( ! V_215 ) {
F_111 ( V_222 , & V_211 -> V_104 ) ;
return ! F_114 ( V_227 , & V_211 -> V_104 ) ;
}
}
return 0 ;
}
