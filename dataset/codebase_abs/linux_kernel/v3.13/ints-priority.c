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
void F_57 ( unsigned int V_25 , struct V_80 * V_81 )
{
T_3 V_82 ;
F_58 ( & V_81 -> V_83 ) ;
V_82 = F_2 ( V_84 ) ;
if ( V_82 & V_85 ) {
switch ( V_82 & V_86 ) {
case 0 :
F_51 ( V_82 ) ;
break;
case V_87 :
F_52 ( V_82 ) ;
break;
case V_88 :
F_55 ( V_82 ) ;
break;
}
}
F_59 ( & V_81 -> V_83 ) ;
F_60 ( V_25 , V_81 ) ;
}
void F_61 ( unsigned int V_25 , struct V_80 * V_81 )
{
struct V_89 * V_90 = F_62 () ;
F_58 ( & V_81 -> V_83 ) ;
switch ( V_25 ) {
case V_91 :
F_63 ( V_90 ) ;
break;
case V_92 :
F_64 ( V_90 ) ;
F_65 ( V_90 ) ;
F_66 ( V_90 ) ;
F_54 ( V_93 L_3 ) ;
F_67 ( V_94 , NULL ) ;
F_68 () ;
F_69 ( L_4 ) ;
break;
case V_95 :
F_69 ( L_5 ) ;
break;
default:
F_69 ( L_6 , V_25 ) ;
}
F_59 ( & V_81 -> V_83 ) ;
}
void F_70 ( unsigned V_25 )
{
#ifdef F_71
struct V_89 V_96 ;
F_72 ( V_25 ) ;
F_73 ( V_25 , & V_96 ) ;
F_74 ( V_25 ) ;
#else
F_75 ( V_25 ) ;
#endif
}
static void F_76 ( unsigned int V_25 )
{
switch ( V_25 ) {
case V_97 :
F_77 (
F_78 () &
F_79 () ) ;
F_80 (
F_81 () &
F_82 () ) ;
break;
case V_98 :
F_83 (
F_84 () &
F_85 () ) ;
break;
case V_99 :
F_86 (
F_87 () &
F_88 () ) ;
break;
case V_100 :
F_89 (
F_90 () | V_101 | V_102 ) ;
break;
default:
F_91 ( 1L << ( V_25 - V_103 ) ) ;
break;
}
}
static void F_92 ( struct V_22 * V_23 )
{
unsigned int V_25 = V_23 -> V_25 ;
V_104 &= ~ ( 1L << ( V_25 - V_103 ) ) ;
#ifdef F_93
switch ( V_25 ) {
case V_103 :
F_94 ( F_95 () & ~ V_105 ) ;
break;
default:
break;
}
#else
if ( ! V_104 )
F_9 ( V_106 ) ;
#endif
F_76 ( V_25 ) ;
}
static void F_96 ( struct V_22 * V_23 )
{
unsigned int V_25 = V_23 -> V_25 ;
#ifdef F_93
switch ( V_25 ) {
case V_103 :
F_94 ( F_95 () | V_105 ) ;
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
int F_97 ( struct V_22 * V_23 , unsigned int V_35 )
{
#ifdef F_93
return F_23 ( V_107 , V_35 ) ;
#else
return F_23 ( V_106 , V_35 ) ;
#endif
}
void F_98 ( unsigned int V_108 ,
struct V_80 * V_109 )
{
int V_58 , V_25 = 0 ;
T_2 V_110 = F_99 () ;
for ( V_58 = 0 ; V_58 <= ( V_111 - V_103 ) ; V_58 ++ )
if ( V_110 & ( 1L << V_58 ) ) {
V_25 = V_103 + V_58 ;
break;
}
if ( V_25 ) {
if ( V_104 & ( 1L << ( V_25 - V_103 ) ) ) {
F_70 ( V_25 ) ;
} else {
F_76 ( V_25 ) ;
F_100 ( L_7
L_8 ,
V_25 ) ;
}
} else
F_54 ( V_112
L_9
L_10
L_11 ,
V_113 , __FILE__ , __LINE__ , V_110 ) ;
}
static inline void F_101 ( unsigned V_25 , T_5 V_114 )
{
#ifdef F_71
V_114 = V_115 ;
#endif
F_102 ( V_25 , V_114 ) ;
}
static void F_103 ( struct V_22 * V_23 )
{
F_104 ( F_105 ( V_23 -> V_25 ) , 0 ) ;
}
static void F_106 ( struct V_22 * V_23 )
{
unsigned int V_25 = V_23 -> V_25 ;
T_2 V_116 = F_105 ( V_25 ) ;
if ( ! F_107 ( V_23 ) )
F_104 ( V_116 , 0 ) ;
F_108 ( V_116 , 0 ) ;
}
static void F_109 ( struct V_22 * V_23 )
{
F_108 ( F_105 ( V_23 -> V_25 ) , 0 ) ;
}
static void F_110 ( struct V_22 * V_23 )
{
F_108 ( F_105 ( V_23 -> V_25 ) , 1 ) ;
}
static unsigned int F_111 ( struct V_22 * V_23 )
{
T_2 V_116 = F_105 ( V_23 -> V_25 ) ;
if ( F_112 ( V_116 , V_117 ) )
F_113 ( V_116 ) ;
F_110 ( V_23 ) ;
return 0 ;
}
static void F_114 ( struct V_22 * V_23 )
{
T_2 V_116 = F_105 ( V_23 -> V_25 ) ;
F_109 ( V_23 ) ;
F_115 ( V_116 , V_117 ) ;
F_116 ( V_116 ) ;
}
static int F_117 ( struct V_22 * V_23 , unsigned int type )
{
unsigned int V_25 = V_23 -> V_25 ;
int V_118 ;
char V_119 [ 16 ] ;
T_2 V_116 = F_105 ( V_25 ) ;
if ( type == V_120 ) {
if ( F_118 ( V_116 , V_117 ) )
return 0 ;
type = V_121 | V_122 ;
}
if ( type & ( V_121 | V_122 |
V_123 | V_124 ) ) {
snprintf ( V_119 , 16 , L_12 , V_25 ) ;
V_118 = F_119 ( V_116 , V_119 ) ;
if ( V_118 )
return V_118 ;
if ( F_112 ( V_116 , V_117 ) )
F_113 ( V_116 ) ;
} else {
F_115 ( V_116 , V_117 ) ;
return 0 ;
}
F_120 ( V_116 , 0 ) ;
F_121 ( V_116 , 0 ) ;
if ( ( type & ( V_121 | V_122 ) )
== ( V_121 | V_122 ) )
F_122 ( V_116 , 1 ) ;
else
F_122 ( V_116 , 0 ) ;
if ( ( type & ( V_122 | V_124 ) ) )
F_123 ( V_116 , 1 ) ;
else
F_123 ( V_116 , 0 ) ;
if ( type & ( V_121 | V_122 ) ) {
F_124 ( V_116 , 1 ) ;
F_120 ( V_116 , 1 ) ;
F_104 ( V_116 , 0 ) ;
} else {
F_124 ( V_116 , 0 ) ;
F_120 ( V_116 , 1 ) ;
}
if ( type & ( V_121 | V_122 ) )
F_101 ( V_25 , V_125 ) ;
else
F_101 ( V_25 , V_115 ) ;
return 0 ;
}
static void F_125 ( unsigned int V_25 )
{
unsigned int V_126 , V_33 ;
V_126 = F_105 ( V_25 ) ;
V_33 = F_126 ( V_126 ) & F_127 ( V_126 ) ;
while ( V_33 ) {
if ( V_33 & 1 )
F_70 ( V_25 ) ;
V_25 ++ ;
V_33 >>= 1 ;
}
}
void F_128 ( unsigned int V_127 ,
struct V_80 * V_81 )
{
unsigned int V_25 ;
switch ( V_127 ) {
#if F_3 ( F_93 )
case V_128 :
F_125 ( V_129 ) ;
V_25 = V_130 ;
break;
case V_131 :
V_25 = V_132 ;
break;
#elif F_3 ( V_133 )
case V_134 :
V_25 = V_129 ;
break;
#elif F_3 ( V_135 )
case V_136 :
V_25 = V_129 ;
break;
#elif F_3 ( V_15 ) || F_3 ( V_14 )
case V_136 :
V_25 = V_129 ;
break;
case V_137 :
V_25 = V_130 ;
break;
case V_138 :
V_25 = V_132 ;
break;
#elif F_3 ( V_139 )
case V_140 :
V_25 = V_129 ;
break;
case V_141 :
V_25 = V_142 ;
break;
case V_143 :
V_25 = V_144 ;
break;
#endif
default:
F_129 () ;
return;
}
F_125 ( V_25 ) ;
}
static int F_130 ( struct V_22 * V_23 , unsigned int V_35 )
{
return F_131 ( F_105 ( V_23 -> V_25 ) , V_35 ) ;
}
static int F_132 ( void )
{
T_2 V_36 ;
for ( V_36 = 0 ; V_36 < V_145 ; V_36 ++ )
V_146 [ V_36 ] = F_36 ( V_36 + F_12 ( V_147 ) ) ;
return 0 ;
}
static void F_133 ( void )
{
T_2 V_36 ;
F_31 ( 0 , V_64 , V_65 ) ;
F_49 ( 100 ) ;
F_50 ( V_66 ) ;
F_31 ( 0 , V_64 , V_67 | V_68 ) ;
for ( V_36 = 0 ; V_36 < V_145 ; V_36 ++ )
F_37 ( V_36 + F_12 ( V_147 ) , V_146 [ V_36 ] ) ;
}
void F_134 ( void )
{
F_135 ( V_148 ) ;
F_136 ( V_149 ) ;
F_137 ( V_150 ) ;
F_138 ( V_151 ) ;
F_139 ( V_152 ) ;
F_140 ( V_153 ) ;
F_141 ( V_154 ) ;
F_142 ( V_155 ) ;
F_143 ( V_156 ) ;
F_144 ( V_157 ) ;
F_145 ( V_158 ) ;
F_146 ( V_159 ) ;
F_147 ( V_160 ) ;
F_148 () ;
}
int T_1 F_149 ( void )
{
int V_25 ;
unsigned long V_161 = 0 ;
#ifdef F_11
F_150 ( V_162 ) ;
F_151 ( V_162 ) ;
# ifdef F_152
F_153 ( V_162 ) ;
# endif
# if F_3 ( V_29 ) || F_3 ( V_30 )
F_154 ( V_162 ) ;
F_155 ( V_162 ) ;
# endif
#else
F_13 ( V_162 ) ;
#endif
F_156 () ;
for ( V_25 = 0 ; V_25 <= V_60 ; V_25 ++ ) {
if ( V_25 <= V_163 )
F_157 ( V_25 , & V_164 ) ;
else
F_157 ( V_25 , & V_165 ) ;
switch ( V_25 ) {
#if ! V_166
#if F_3 ( F_93 )
case V_131 :
case V_128 :
#elif F_3 ( V_133 )
case V_134 :
#elif F_3 ( V_15 ) || F_3 ( V_14 )
case V_136 :
case V_137 :
case V_138 :
#elif F_3 ( V_139 )
case V_140 :
case V_141 :
case V_143 :
#elif F_3 ( V_135 )
case V_136 :
#endif
F_158 ( V_25 , F_128 ) ;
break;
#endif
#if F_3 ( V_167 ) || F_3 ( V_168 )
case V_106 :
F_158 ( V_25 ,
F_98 ) ;
break;
#endif
#if F_3 ( V_29 ) || F_3 ( V_30 )
case V_169 :
case V_170 :
F_159 ( V_25 , V_171 ) ;
break;
#endif
#ifdef F_160
case V_163 :
# ifdef V_29
F_159 ( V_25 , V_171 ) ;
# else
F_159 ( V_25 , V_172 ) ;
# endif
break;
#endif
#ifdef F_161
case V_173 :
F_159 ( V_25 , V_172 ) ;
break;
#endif
default:
#ifdef F_71
F_159 ( V_25 , V_115 ) ;
#else
F_159 ( V_25 , V_172 ) ;
#endif
break;
}
}
F_162 () ;
#if ( F_3 ( V_167 ) || F_3 ( V_168 ) )
for ( V_25 = V_103 ; V_25 <= V_111 ; V_25 ++ )
F_163 ( V_25 , & V_174 ,
V_115 ) ;
#endif
#ifdef F_164
for ( V_25 = V_175 ;
V_25 < ( V_175 + V_176 ) ; V_25 ++ )
F_163 ( V_25 , & V_177 ,
V_115 ) ;
#endif
F_165 ( 0 ) ;
F_148 () ;
V_161 = F_166 () ;
F_148 () ;
F_167 ( V_161 ) ;
F_148 () ;
F_54 ( V_178 L_13 ) ;
F_168 () ;
F_1 () ;
V_24 |= V_179 |
V_180 | V_181 | V_182 | V_183 |
V_184 | V_185 | V_186 | V_187 | V_188 ;
#ifdef F_169
F_170 ( V_189 ) ;
# ifdef F_171
if ( V_190 )
F_172 ( F_173 ( 10 ) | F_173 ( 11 ) ) ;
else
F_172 ( V_189 ) ;
# endif
# ifdef F_174
F_175 ( V_189 ) ;
# endif
#else
F_176 ( V_189 ) ;
#endif
return 0 ;
}
static int F_177 ( int V_191 )
{
struct V_192 * V_1 = V_6 [ V_191 - V_4 ] . V_8 ;
struct V_192 * V_193 = V_6 [ V_191 - V_4 ] . V_7 ;
unsigned long V_194 [ 3 ] ;
if ( F_178 ( V_191 == V_195 ) )
return V_163 ;
#ifdef F_179
V_194 [ 0 ] = F_14 () & F_180 () ;
#else
if ( F_181 () ) {
# ifdef F_182
V_194 [ 0 ] = F_183 () & F_184 () ;
V_194 [ 1 ] = F_185 () & F_186 () ;
# endif
} else {
V_194 [ 0 ] = F_187 () & F_188 () ;
V_194 [ 1 ] = F_189 () & F_190 () ;
}
#endif
#ifdef F_191
V_194 [ 2 ] = F_192 () & F_193 () ;
#endif
for (; ; V_1 ++ ) {
if ( V_1 >= V_193 )
return - 1 ;
#ifdef F_179
if ( V_194 [ 0 ] & V_1 -> V_21 )
#else
if ( V_194 [ ( V_1 -> V_20 - V_4 ) / 32 ] & V_1 -> V_21 )
#endif
return V_1 -> V_20 ;
}
}
int T_1 F_149 ( void )
{
int V_25 ;
unsigned long V_161 = 0 ;
F_50 ( V_196 ) ;
F_156 () ;
for ( V_25 = 0 ; V_25 <= V_60 ; V_25 ++ ) {
if ( V_25 <= V_163 ) {
F_163 ( V_25 , & V_164 ,
V_172 ) ;
#if F_3 ( F_160 ) && F_3 ( V_29 )
if ( V_25 == V_163 )
F_159 ( V_25 , V_171 ) ;
#endif
} else if ( V_25 >= F_45 ( 34 ) && V_25 <= F_45 ( 37 ) ) {
F_163 ( V_25 , & V_197 ,
V_171 ) ;
} else {
F_157 ( V_25 , & V_197 ) ;
if ( V_25 == V_198 )
F_159 ( V_25 , F_57 ) ;
else if ( V_25 >= V_91 && V_25 < V_199 )
F_159 ( V_25 , F_61 ) ;
else
F_159 ( V_25 , F_60 ) ;
F_194 ( V_25 , F_30 ) ;
}
}
F_165 ( 0 ) ;
F_148 () ;
V_161 = F_166 () ;
F_148 () ;
F_167 ( V_161 ) ;
F_148 () ;
F_54 ( V_178 L_13 ) ;
F_44 ( V_200 , V_57 ) ;
F_44 ( V_200 , V_57 ) ;
V_24 |= V_179 |
V_180 | V_181 | V_182 | V_183 |
V_184 | V_185 | V_186 | V_187 | V_188 ;
F_195 ( V_201 | V_202 | V_203 ) ;
F_40 ( F_12 ( V_53 ) ) ;
F_35 ( F_12 ( V_53 ) ) ;
F_31 ( 0 , V_64 , V_65 ) ;
F_49 ( 100 ) ;
F_50 ( V_66 ) ;
F_31 ( 0 , V_64 , V_67 | V_68 ) ;
F_31 ( 1 , V_64 , V_67 | V_68 ) ;
F_47 () ;
#ifdef F_196
F_197 ( & V_204 ) ;
#endif
return 0 ;
}
static int F_177 ( int V_191 )
{
if ( F_178 ( V_191 == V_195 ) )
return V_163 ;
return F_45 ( F_53 ( 0 , V_47 ) ) ;
}
void F_198 ( int V_191 , struct V_89 * V_90 )
{
int V_25 = F_177 ( V_191 ) ;
if ( V_25 == - 1 )
return;
F_199 ( V_25 , V_90 ) ;
}
int F_200 ( unsigned V_25 )
{
int V_205 , V_206 ;
if ( V_25 <= V_163 )
return V_25 ;
#ifdef F_201
if ( V_25 >= F_45 ( 0 ) )
return V_207 ;
#else
for ( V_205 = 0 ; V_205 < V_10 ; V_205 ++ ) {
struct V_192 * V_1 = V_9 + V_205 ;
if ( V_1 -> V_20 == V_25 ) {
for ( V_206 = 0 ; V_206 <= V_3 - V_4 ; V_206 ++ ) {
if ( V_6 [ V_206 ] . V_8 <= V_1 &&
V_6 [ V_206 ] . V_7 > V_1 )
return V_4 + V_206 ;
}
}
}
#endif
return V_208 ;
}
T_6 int F_202 ( int V_191 , struct V_89 * V_96 )
{
struct V_209 * V_210 = F_203 () ;
struct V_211 * V_212 = V_213 ;
int V_25 , V_214 = 0 ;
V_25 = F_177 ( V_191 ) ;
if ( V_25 == - 1 )
return 0 ;
if ( V_25 == V_215 ) {
#if ! F_3 ( V_216 ) || F_3 ( F_161 )
F_204 ( 1 ) ;
#endif
F_205 ( V_217 ) . V_218 = V_96 -> V_218 ;
F_205 ( V_217 ) . V_219 = V_96 -> V_219 ;
if ( V_212 != V_220 )
F_205 ( V_217 ) . V_218 &= ~ 0x10 ;
else
F_205 ( V_217 ) . V_218 |= 0x10 ;
}
if ( V_212 == V_220 ) {
V_214 = F_112 ( V_221 , & V_210 -> V_110 ) ;
F_206 () ;
}
F_72 ( V_25 ) ;
F_73 ( V_25 , V_96 ) ;
F_74 ( V_25 ) ;
if ( F_207 ( V_96 ) &&
! F_208 () &&
( V_94 -> V_222 & V_223 ) != 0 ) {
V_94 -> V_222 &= ~ V_223 ;
F_209 ( V_224 , V_96 ) ;
}
if ( V_212 == V_220 ) {
F_210 ( V_225 ) ;
if ( ! V_214 ) {
F_115 ( V_221 , & V_210 -> V_110 ) ;
return ! F_118 ( V_226 , & V_210 -> V_110 ) ;
}
}
return 0 ;
}
