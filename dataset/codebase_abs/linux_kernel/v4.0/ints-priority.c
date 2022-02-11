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
void F_48 ( T_3 V_64 )
{
}
void F_49 ( T_3 V_64 )
{
T_3 V_65 ;
T_3 V_66 ;
V_65 = V_64 & V_67 ;
V_66 = F_50 ( V_65 , V_68 ) ;
if ( V_66 & V_69 ) {
switch ( V_66 & V_70 ) {
case V_71 :
F_51 ( V_72 L_1 ) ;
break;
default:
F_51 ( V_72 L_2 ) ;
}
}
}
void F_52 ( T_3 V_64 )
{
T_3 V_46 ;
T_3 V_73 ;
V_46 = V_64 & V_74 ;
V_73 = F_53 ( V_46 ) ;
}
void F_54 ( T_3 V_75 )
{
if ( V_75 & V_76 ) {
switch ( V_75 & V_77 ) {
case 0 :
F_48 ( V_75 ) ;
break;
case V_78 :
F_49 ( V_75 ) ;
break;
case V_79 :
F_52 ( V_75 ) ;
break;
}
}
}
static T_5 F_55 ( int V_25 , void * V_80 )
{
struct V_81 * V_82 = F_56 () ;
switch ( V_25 ) {
case V_83 :
F_57 ( V_82 ) ;
break;
case V_84 :
F_58 ( V_82 ) ;
F_59 ( V_82 ) ;
F_60 ( V_82 ) ;
F_51 ( V_85 L_3 ) ;
F_61 ( V_86 , NULL ) ;
F_62 () ;
F_63 ( L_4 ) ;
break;
case V_87 :
F_63 ( L_5 ) ;
break;
case V_88 :
F_64 ( L_6 ) ;
F_54 ( F_2 ( V_89 ) ) ;
break;
default:
F_63 ( L_7 , V_25 ) ;
}
return V_90 ;
}
void F_65 ( unsigned V_25 )
{
#ifdef F_66
struct V_81 V_91 ;
F_67 ( V_25 ) ;
F_68 ( V_25 , & V_91 ) ;
F_69 ( V_25 ) ;
#else
F_70 ( V_25 ) ;
#endif
}
static void F_71 ( unsigned int V_25 )
{
switch ( V_25 ) {
case V_92 :
F_72 (
F_73 () &
F_74 () ) ;
F_75 (
F_76 () &
F_77 () ) ;
break;
case V_93 :
F_78 (
F_79 () &
F_80 () ) ;
break;
case V_94 :
F_81 (
F_82 () &
F_83 () ) ;
break;
case V_95 :
F_84 (
F_85 () | V_96 | V_97 ) ;
break;
default:
F_86 ( 1L << ( V_25 - V_98 ) ) ;
break;
}
}
static void F_87 ( struct V_22 * V_23 )
{
unsigned int V_25 = V_23 -> V_25 ;
V_99 &= ~ ( 1L << ( V_25 - V_98 ) ) ;
#ifdef F_88
switch ( V_25 ) {
case V_98 :
F_89 ( F_90 () & ~ V_100 ) ;
break;
default:
break;
}
#else
if ( ! V_99 )
F_9 ( V_101 ) ;
#endif
F_71 ( V_25 ) ;
}
static void F_91 ( struct V_22 * V_23 )
{
unsigned int V_25 = V_23 -> V_25 ;
#ifdef F_88
switch ( V_25 ) {
case V_98 :
F_89 ( F_90 () | V_100 ) ;
break;
default:
break;
}
#else
if ( ! V_99 )
F_22 ( V_101 ) ;
#endif
V_99 |= 1L << ( V_25 - V_98 ) ;
}
int F_92 ( struct V_22 * V_23 , unsigned int V_35 )
{
#ifdef F_88
return F_23 ( V_102 , V_35 ) ;
#else
return F_23 ( V_101 , V_35 ) ;
#endif
}
void F_93 ( unsigned int V_103 ,
struct V_104 * V_105 )
{
int V_58 , V_25 = 0 ;
T_2 V_106 = F_94 () ;
for ( V_58 = 0 ; V_58 <= ( V_107 - V_98 ) ; V_58 ++ )
if ( V_106 & ( 1L << V_58 ) ) {
V_25 = V_98 + V_58 ;
break;
}
if ( V_25 ) {
if ( V_99 & ( 1L << ( V_25 - V_98 ) ) ) {
F_65 ( V_25 ) ;
} else {
F_71 ( V_25 ) ;
F_95 ( L_8
L_9 ,
V_25 ) ;
}
} else
F_51 ( V_108
L_10
L_11
L_12 ,
V_109 , __FILE__ , __LINE__ , V_106 ) ;
}
static inline void F_96 ( unsigned V_25 , T_6 V_110 )
{
#ifdef F_66
V_110 = V_111 ;
#endif
F_97 ( V_25 , V_110 ) ;
}
static void F_98 ( struct V_22 * V_23 )
{
F_99 ( F_100 ( V_23 -> V_25 ) , 0 ) ;
}
static void F_101 ( struct V_22 * V_23 )
{
unsigned int V_25 = V_23 -> V_25 ;
T_2 V_112 = F_100 ( V_25 ) ;
if ( ! F_102 ( V_23 ) )
F_99 ( V_112 , 0 ) ;
F_103 ( V_112 , 0 ) ;
}
static void F_104 ( struct V_22 * V_23 )
{
F_103 ( F_100 ( V_23 -> V_25 ) , 0 ) ;
}
static void F_105 ( struct V_22 * V_23 )
{
F_103 ( F_100 ( V_23 -> V_25 ) , 1 ) ;
}
static unsigned int F_106 ( struct V_22 * V_23 )
{
T_2 V_112 = F_100 ( V_23 -> V_25 ) ;
if ( F_107 ( V_112 , V_113 ) )
F_108 ( V_112 ) ;
F_105 ( V_23 ) ;
return 0 ;
}
static void F_109 ( struct V_22 * V_23 )
{
T_2 V_112 = F_100 ( V_23 -> V_25 ) ;
F_104 ( V_23 ) ;
F_110 ( V_112 , V_113 ) ;
F_111 ( V_112 ) ;
}
static int F_112 ( struct V_22 * V_23 , unsigned int type )
{
unsigned int V_25 = V_23 -> V_25 ;
int V_114 ;
char V_115 [ 16 ] ;
T_2 V_112 = F_100 ( V_25 ) ;
if ( type == V_116 ) {
if ( F_113 ( V_112 , V_113 ) )
return 0 ;
type = V_117 | V_118 ;
}
if ( type & ( V_117 | V_118 |
V_119 | V_120 ) ) {
snprintf ( V_115 , 16 , L_13 , V_25 ) ;
V_114 = F_114 ( V_112 , V_115 ) ;
if ( V_114 )
return V_114 ;
if ( F_107 ( V_112 , V_113 ) )
F_108 ( V_112 ) ;
} else {
F_110 ( V_112 , V_113 ) ;
return 0 ;
}
F_115 ( V_112 , 0 ) ;
F_116 ( V_112 , 0 ) ;
if ( ( type & ( V_117 | V_118 ) )
== ( V_117 | V_118 ) )
F_117 ( V_112 , 1 ) ;
else
F_117 ( V_112 , 0 ) ;
if ( ( type & ( V_118 | V_120 ) ) )
F_118 ( V_112 , 1 ) ;
else
F_118 ( V_112 , 0 ) ;
if ( type & ( V_117 | V_118 ) ) {
F_119 ( V_112 , 1 ) ;
F_115 ( V_112 , 1 ) ;
F_99 ( V_112 , 0 ) ;
} else {
F_119 ( V_112 , 0 ) ;
F_115 ( V_112 , 1 ) ;
}
if ( type & ( V_117 | V_118 ) )
F_96 ( V_25 , V_121 ) ;
else
F_96 ( V_25 , V_111 ) ;
return 0 ;
}
static void F_120 ( unsigned int V_25 )
{
unsigned int V_122 , V_33 ;
V_122 = F_100 ( V_25 ) ;
V_33 = F_121 ( V_122 ) & F_122 ( V_122 ) ;
while ( V_33 ) {
if ( V_33 & 1 )
F_65 ( V_25 ) ;
V_25 ++ ;
V_33 >>= 1 ;
}
}
void F_123 ( unsigned int V_123 ,
struct V_104 * V_124 )
{
unsigned int V_25 ;
switch ( V_123 ) {
#if F_3 ( F_88 )
case V_125 :
F_120 ( V_126 ) ;
V_25 = V_127 ;
break;
case V_128 :
V_25 = V_129 ;
break;
#elif F_3 ( V_130 )
case V_131 :
V_25 = V_126 ;
break;
#elif F_3 ( V_132 )
case V_133 :
V_25 = V_126 ;
break;
#elif F_3 ( V_15 ) || F_3 ( V_14 )
case V_133 :
V_25 = V_126 ;
break;
case V_134 :
V_25 = V_127 ;
break;
case V_135 :
V_25 = V_129 ;
break;
#elif F_3 ( V_136 )
case V_137 :
V_25 = V_126 ;
break;
case V_138 :
V_25 = V_139 ;
break;
case V_140 :
V_25 = V_141 ;
break;
#endif
default:
F_124 () ;
return;
}
F_120 ( V_25 ) ;
}
static int F_125 ( struct V_22 * V_23 , unsigned int V_35 )
{
return F_126 ( F_100 ( V_23 -> V_25 ) , V_35 ) ;
}
static int F_127 ( void )
{
T_2 V_36 ;
for ( V_36 = 0 ; V_36 < V_142 ; V_36 ++ )
V_143 [ V_36 ] = F_36 ( V_36 + F_12 ( V_144 ) ) ;
return 0 ;
}
static void F_128 ( void )
{
T_2 V_36 ;
F_31 ( 0 , V_145 , V_146 ) ;
F_129 ( 100 ) ;
F_130 ( V_147 ) ;
F_31 ( 0 , V_145 , V_148 | V_149 ) ;
for ( V_36 = 0 ; V_36 < V_142 ; V_36 ++ )
F_37 ( V_36 + F_12 ( V_144 ) , V_143 [ V_36 ] ) ;
}
void F_131 ( void )
{
F_132 ( V_150 ) ;
F_133 ( V_151 ) ;
F_134 ( V_152 ) ;
F_135 ( V_153 ) ;
F_136 ( V_154 ) ;
F_137 ( V_155 ) ;
F_138 ( V_156 ) ;
F_139 ( V_157 ) ;
F_140 ( V_158 ) ;
F_141 ( V_159 ) ;
F_142 ( V_160 ) ;
F_143 ( V_161 ) ;
F_144 ( V_162 ) ;
F_145 () ;
}
int T_1 F_146 ( void )
{
int V_25 ;
unsigned long V_163 = 0 ;
#ifdef F_11
F_147 ( V_164 ) ;
F_148 ( V_164 ) ;
# ifdef F_149
F_150 ( V_164 ) ;
# endif
# if F_3 ( V_29 ) || F_3 ( V_30 )
F_151 ( V_164 ) ;
F_152 ( V_164 ) ;
# endif
#else
F_13 ( V_164 ) ;
#endif
F_153 () ;
for ( V_25 = 0 ; V_25 <= V_60 ; V_25 ++ ) {
if ( V_25 <= V_165 )
F_154 ( V_25 , & V_166 ) ;
else
F_154 ( V_25 , & V_167 ) ;
switch ( V_25 ) {
#if ! V_168
#if F_3 ( F_88 )
case V_128 :
case V_125 :
#elif F_3 ( V_130 )
case V_131 :
#elif F_3 ( V_15 ) || F_3 ( V_14 )
case V_133 :
case V_134 :
case V_135 :
#elif F_3 ( V_136 )
case V_137 :
case V_138 :
case V_140 :
#elif F_3 ( V_132 )
case V_133 :
#endif
F_155 ( V_25 , F_123 ) ;
break;
#endif
#if F_3 ( V_169 ) || F_3 ( V_170 )
case V_101 :
F_155 ( V_25 ,
F_93 ) ;
break;
#endif
#if F_3 ( V_29 ) || F_3 ( V_30 )
case V_171 :
case V_172 :
F_156 ( V_25 , V_173 ) ;
break;
#endif
#ifdef F_157
case V_165 :
# ifdef V_29
F_156 ( V_25 , V_173 ) ;
# else
F_156 ( V_25 , V_174 ) ;
# endif
break;
#endif
#ifdef F_158
case V_175 :
F_156 ( V_25 , V_174 ) ;
break;
#endif
default:
#ifdef F_66
F_156 ( V_25 , V_111 ) ;
#else
F_156 ( V_25 , V_174 ) ;
#endif
break;
}
}
F_159 () ;
#if ( F_3 ( V_169 ) || F_3 ( V_170 ) )
for ( V_25 = V_98 ; V_25 <= V_107 ; V_25 ++ )
F_160 ( V_25 , & V_176 ,
V_111 ) ;
#endif
#ifdef F_161
for ( V_25 = V_177 ;
V_25 < ( V_177 + V_178 ) ; V_25 ++ )
F_160 ( V_25 , & V_179 ,
V_111 ) ;
#endif
F_162 ( 0 ) ;
F_145 () ;
V_163 = F_163 () ;
F_145 () ;
F_164 ( V_163 ) ;
F_145 () ;
F_51 ( V_180 L_14 ) ;
F_165 () ;
F_1 () ;
V_24 |= V_181 |
V_182 | V_183 | V_184 | V_185 |
V_186 | V_187 | V_188 | V_189 | V_190 ;
#ifdef F_166
F_167 ( V_191 ) ;
# ifdef F_168
if ( V_192 )
F_169 ( F_170 ( 10 ) | F_170 ( 11 ) ) ;
else
F_169 ( V_191 ) ;
# endif
# ifdef F_171
F_172 ( V_191 ) ;
# endif
#else
F_173 ( V_191 ) ;
#endif
return 0 ;
}
static int F_174 ( int V_193 )
{
struct V_194 * V_1 = V_6 [ V_193 - V_4 ] . V_8 ;
struct V_194 * V_195 = V_6 [ V_193 - V_4 ] . V_7 ;
unsigned long V_196 [ 3 ] ;
if ( F_175 ( V_193 == V_197 ) )
return V_165 ;
#ifdef F_176
V_196 [ 0 ] = F_14 () & F_177 () ;
#else
if ( F_178 () ) {
# ifdef F_179
V_196 [ 0 ] = F_180 () & F_181 () ;
V_196 [ 1 ] = F_182 () & F_183 () ;
# endif
} else {
V_196 [ 0 ] = F_184 () & F_185 () ;
V_196 [ 1 ] = F_186 () & F_187 () ;
}
#endif
#ifdef F_188
V_196 [ 2 ] = F_189 () & F_190 () ;
#endif
for (; ; V_1 ++ ) {
if ( V_1 >= V_195 )
return - 1 ;
#ifdef F_176
if ( V_196 [ 0 ] & V_1 -> V_21 )
#else
if ( V_196 [ ( V_1 -> V_20 - V_4 ) / 32 ] & V_1 -> V_21 )
#endif
return V_1 -> V_20 ;
}
}
int T_1 F_146 ( void )
{
int V_25 ;
unsigned long V_163 = 0 ;
F_130 ( V_198 ) ;
F_153 () ;
for ( V_25 = 0 ; V_25 <= V_60 ; V_25 ++ ) {
if ( V_25 <= V_165 ) {
F_160 ( V_25 , & V_166 ,
V_174 ) ;
#if F_3 ( F_157 ) && F_3 ( V_29 )
if ( V_25 == V_165 )
F_156 ( V_25 , V_173 ) ;
#endif
} else if ( V_25 >= F_45 ( 34 ) && V_25 <= F_45 ( 37 ) ) {
F_160 ( V_25 , & V_199 ,
V_173 ) ;
} else {
F_154 ( V_25 , & V_199 ) ;
F_156 ( V_25 , V_200 ) ;
F_191 ( V_25 , F_30 ) ;
}
}
F_162 ( 0 ) ;
F_145 () ;
V_163 = F_163 () ;
F_145 () ;
F_164 ( V_163 ) ;
F_145 () ;
F_51 ( V_180 L_14 ) ;
F_44 ( V_201 , V_57 ) ;
V_24 |= V_181 |
V_182 | V_183 | V_184 | V_185 |
V_186 | V_187 | V_188 | V_189 | V_190 ;
F_192 ( V_202 | V_203 | V_204 ) ;
F_40 ( F_12 ( V_53 ) ) ;
F_35 ( F_12 ( V_53 ) ) ;
F_31 ( 0 , V_145 , V_146 ) ;
F_129 ( 100 ) ;
F_130 ( V_147 ) ;
F_31 ( 0 , V_145 , V_148 | V_149 ) ;
F_31 ( 1 , V_145 , V_148 | V_149 ) ;
F_47 () ;
#ifdef F_193
F_194 ( & V_205 ) ;
#endif
V_206 . V_207 = F_55 ;
#ifdef F_195
F_196 ( V_87 , & V_206 ) ;
#endif
F_196 ( V_83 , & V_206 ) ;
F_196 ( V_88 , & V_206 ) ;
return 0 ;
}
static int F_174 ( int V_193 )
{
if ( F_175 ( V_193 == V_197 ) )
return V_165 ;
return F_45 ( F_50 ( 0 , V_47 ) ) ;
}
void F_197 ( int V_193 , struct V_81 * V_82 )
{
int V_25 = F_174 ( V_193 ) ;
if ( V_25 == - 1 )
return;
F_198 ( V_25 , V_82 ) ;
}
int F_199 ( unsigned V_25 )
{
int V_208 , V_209 ;
if ( V_25 <= V_165 )
return V_25 ;
#ifdef F_200
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
T_7 int F_201 ( int V_193 , struct V_81 * V_91 )
{
struct V_212 * V_213 = F_202 () ;
struct V_214 * V_215 = V_216 ;
int V_25 , V_217 = 0 ;
V_25 = F_174 ( V_193 ) ;
if ( V_25 == - 1 )
return 0 ;
if ( V_25 == V_218 ) {
#if ! F_3 ( V_219 ) || F_3 ( F_158 )
F_203 ( 1 ) ;
#endif
F_204 ( V_220 . V_221 , V_91 -> V_221 ) ;
F_204 ( V_220 . V_222 , V_91 -> V_222 ) ;
if ( V_215 != V_223 )
F_205 ( V_220 . V_221 , ~ 0x10 ) ;
else
F_206 ( V_220 . V_221 , 0x10 ) ;
}
if ( V_215 == V_223 ) {
V_217 = F_107 ( V_224 , & V_213 -> V_106 ) ;
F_207 () ;
}
F_67 ( V_25 ) ;
F_68 ( V_25 , V_91 ) ;
F_69 ( V_25 ) ;
if ( F_208 ( V_91 ) &&
! F_209 () &&
( V_86 -> V_225 & V_226 ) != 0 ) {
V_86 -> V_225 &= ~ V_226 ;
F_210 ( V_227 , V_91 ) ;
}
if ( V_215 == V_223 ) {
F_211 ( V_228 ) ;
if ( ! V_217 ) {
F_110 ( V_224 , & V_213 -> V_106 ) ;
return ! F_113 ( V_229 , & V_213 -> V_106 ) ;
}
}
return 0 ;
}
