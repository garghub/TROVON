static void T_1 F_1 ( void )
{
unsigned V_1 , V_2 = 0 ;
for ( V_1 = 0 ; V_1 <= V_3 - V_4 ; V_1 ++ ) {
int V_5 ;
V_6 [ V_1 ] . V_7 = V_6 [ V_1 ] . V_8 = & V_9 [ V_2 ] ;
for ( V_5 = 0 ; V_5 < V_10 ; V_5 += 4 ) {
int V_11 ;
T_2 V_12 = F_2 ( ( unsigned long * ) V_13 +
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
# ifdef F_15
F_16 ( V_27 , F_17 ( V_27 ) &
~ ( 1 << V_28 ) ) ;
# endif
#else
F_13 ( F_14 () &
~ ( 1 << F_12 ( V_25 ) ) ) ;
#endif
F_18 ( V_26 ) ;
}
static void F_19 ( struct V_22 * V_23 )
{
F_9 ( V_23 -> V_25 ) ;
}
static void F_20 ( struct V_22 * V_23 )
{
F_21 ( V_23 -> V_25 , V_23 -> V_29 ) ;
}
static int F_22 ( struct V_22 * V_23 ,
const struct V_30 * V_31 , bool V_32 )
{
F_9 ( V_23 -> V_25 ) ;
F_21 ( V_23 -> V_25 , V_31 ) ;
return 0 ;
}
static void F_20 ( struct V_22 * V_23 )
{
F_23 ( V_23 -> V_25 ) ;
}
int F_24 ( unsigned int V_25 , unsigned int V_33 )
{
T_2 V_34 , V_35 , V_36 = 0 ;
unsigned long V_26 ;
V_34 = F_12 ( V_25 ) / 32 ;
V_35 = F_12 ( V_25 ) % 32 ;
switch ( V_25 ) {
#ifdef F_25
case F_25 :
V_36 |= V_37 ;
break;
#endif
#ifdef F_26
case F_26 :
V_36 |= V_38 ;
break;
#endif
#ifdef F_27
case F_27 :
V_36 |= V_38 ;
break;
#endif
#ifdef F_28
case F_28 :
V_36 |= V_39 ;
break;
#endif
#ifdef F_29
case V_40 :
V_36 |= V_41 ;
break;
#endif
default:
break;
}
V_26 = F_10 () ;
if ( V_33 ) {
V_42 [ V_34 ] |= ( 1 << V_35 ) ;
V_43 |= V_36 ;
} else {
V_42 [ V_34 ] &= ~ ( 1 << V_35 ) ;
V_43 &= ~ V_36 ;
}
F_18 ( V_26 ) ;
return 0 ;
}
static int F_30 ( struct V_22 * V_23 , unsigned int V_33 )
{
return F_24 ( V_23 -> V_25 , V_33 ) ;
}
void F_31 ( unsigned V_25 )
{
#ifdef F_32
struct V_44 V_45 ;
F_33 ( V_25 ) ;
F_34 ( V_25 , & V_45 ) ;
F_35 ( V_25 ) ;
#else
F_36 ( V_25 ) ;
#endif
}
static void F_37 ( unsigned int V_25 )
{
switch ( V_25 ) {
case V_46 :
F_38 (
F_39 () &
F_40 () ) ;
F_41 (
F_42 () &
F_43 () ) ;
break;
case V_47 :
F_44 (
F_45 () &
F_46 () ) ;
break;
case V_48 :
F_47 (
F_48 () &
F_49 () ) ;
break;
case V_49 :
F_50 (
F_51 () | V_50 | V_51 ) ;
break;
default:
F_52 ( 1L << ( V_25 - V_52 ) ) ;
break;
}
}
static void F_53 ( struct V_22 * V_23 )
{
unsigned int V_25 = V_23 -> V_25 ;
V_53 &= ~ ( 1L << ( V_25 - V_52 ) ) ;
#ifdef F_54
switch ( V_25 ) {
case V_52 :
F_55 ( F_56 () & ~ V_54 ) ;
break;
default:
break;
}
#else
if ( ! V_53 )
F_9 ( V_55 ) ;
#endif
F_37 ( V_25 ) ;
}
static void F_57 ( struct V_22 * V_23 )
{
unsigned int V_25 = V_23 -> V_25 ;
#ifdef F_54
switch ( V_25 ) {
case V_52 :
F_55 ( F_56 () | V_54 ) ;
break;
default:
break;
}
#else
if ( ! V_53 )
F_23 ( V_55 ) ;
#endif
V_53 |= 1L << ( V_25 - V_52 ) ;
}
int F_58 ( struct V_22 * V_23 , unsigned int V_33 )
{
#ifdef F_54
return F_24 ( V_56 , V_33 ) ;
#else
return F_24 ( V_55 , V_33 ) ;
#endif
}
void F_59 ( unsigned int V_57 ,
struct V_58 * V_59 )
{
int V_60 , V_25 = 0 ;
T_2 V_61 = F_60 () ;
for ( V_60 = 0 ; V_60 <= ( V_62 - V_52 ) ; V_60 ++ )
if ( V_61 & ( 1L << V_60 ) ) {
V_25 = V_52 + V_60 ;
break;
}
if ( V_25 ) {
if ( V_53 & ( 1L << ( V_25 - V_52 ) ) ) {
F_31 ( V_25 ) ;
} else {
F_37 ( V_25 ) ;
F_61 ( L_1
L_2 ,
V_25 ) ;
}
} else
F_62 ( V_63
L_3
L_4
L_5 ,
V_64 , __FILE__ , __LINE__ , V_61 ) ;
}
static inline void F_63 ( unsigned V_25 , T_3 V_65 )
{
#ifdef F_32
V_65 = V_66 ;
#endif
F_64 ( V_25 , V_65 ) ;
}
static void F_65 ( struct V_22 * V_23 )
{
F_66 ( F_67 ( V_23 -> V_25 ) , 0 ) ;
}
static void F_68 ( struct V_22 * V_23 )
{
unsigned int V_25 = V_23 -> V_25 ;
T_2 V_67 = F_67 ( V_25 ) ;
if ( ! F_69 ( V_23 ) )
F_66 ( V_67 , 0 ) ;
F_70 ( V_67 , 0 ) ;
}
static void F_71 ( struct V_22 * V_23 )
{
F_70 ( F_67 ( V_23 -> V_25 ) , 0 ) ;
}
static void F_72 ( struct V_22 * V_23 )
{
F_70 ( F_67 ( V_23 -> V_25 ) , 1 ) ;
}
static unsigned int F_73 ( struct V_22 * V_23 )
{
T_2 V_67 = F_67 ( V_23 -> V_25 ) ;
if ( F_74 ( V_67 , V_68 ) )
F_75 ( V_67 ) ;
F_72 ( V_23 ) ;
return 0 ;
}
static void F_76 ( struct V_22 * V_23 )
{
T_2 V_67 = F_67 ( V_23 -> V_25 ) ;
F_71 ( V_23 ) ;
F_77 ( V_67 , V_68 ) ;
F_78 ( V_67 ) ;
}
static int F_79 ( struct V_22 * V_23 , unsigned int type )
{
unsigned int V_25 = V_23 -> V_25 ;
int V_69 ;
char V_70 [ 16 ] ;
T_2 V_67 = F_67 ( V_25 ) ;
if ( type == V_71 ) {
if ( F_80 ( V_67 , V_68 ) )
return 0 ;
type = V_72 | V_73 ;
}
if ( type & ( V_72 | V_73 |
V_74 | V_75 ) ) {
snprintf ( V_70 , 16 , L_6 , V_25 ) ;
V_69 = F_81 ( V_67 , V_70 ) ;
if ( V_69 )
return V_69 ;
if ( F_74 ( V_67 , V_68 ) )
F_75 ( V_67 ) ;
} else {
F_77 ( V_67 , V_68 ) ;
return 0 ;
}
F_82 ( V_67 , 0 ) ;
F_83 ( V_67 , 0 ) ;
if ( ( type & ( V_72 | V_73 ) )
== ( V_72 | V_73 ) )
F_84 ( V_67 , 1 ) ;
else
F_84 ( V_67 , 0 ) ;
if ( ( type & ( V_73 | V_75 ) ) )
F_85 ( V_67 , 1 ) ;
else
F_85 ( V_67 , 0 ) ;
if ( type & ( V_72 | V_73 ) ) {
F_86 ( V_67 , 1 ) ;
F_82 ( V_67 , 1 ) ;
F_66 ( V_67 , 0 ) ;
} else {
F_86 ( V_67 , 0 ) ;
F_82 ( V_67 , 1 ) ;
}
if ( type & ( V_72 | V_73 ) )
F_63 ( V_25 , V_76 ) ;
else
F_63 ( V_25 , V_66 ) ;
return 0 ;
}
static int F_87 ( struct V_22 * V_23 , unsigned int V_33 )
{
return F_88 ( F_67 ( V_23 -> V_25 ) , V_33 ) ;
}
static void F_89 ( unsigned int V_25 )
{
unsigned int V_77 , V_31 ;
V_77 = F_67 ( V_25 ) ;
V_31 = F_90 ( V_77 ) & F_91 ( V_77 ) ;
while ( V_31 ) {
if ( V_31 & 1 )
F_31 ( V_25 ) ;
V_25 ++ ;
V_31 >>= 1 ;
}
}
void F_92 ( unsigned int V_78 ,
struct V_58 * V_79 )
{
unsigned int V_25 ;
switch ( V_78 ) {
#if F_3 ( F_54 )
case V_80 :
F_89 ( V_81 ) ;
V_25 = V_82 ;
break;
case V_83 :
V_25 = V_84 ;
break;
#elif F_3 ( V_85 )
case V_86 :
V_25 = V_81 ;
break;
#elif F_3 ( V_87 )
case V_88 :
V_25 = V_81 ;
break;
#elif F_3 ( V_15 ) || F_3 ( V_14 )
case V_88 :
V_25 = V_81 ;
break;
case V_89 :
V_25 = V_82 ;
break;
case V_90 :
V_25 = V_84 ;
break;
#elif F_3 ( V_91 )
case V_92 :
V_25 = V_81 ;
break;
case V_93 :
V_25 = V_94 ;
break;
case V_95 :
V_25 = V_96 ;
break;
#endif
default:
F_93 () ;
return;
}
F_89 ( V_25 ) ;
}
inline unsigned int F_94 ( T_2 V_34 , T_4 V_97 )
{
unsigned int V_98 ;
if ( V_34 < 2 ) {
V_98 = V_99 + V_97 * 16 ;
} else {
V_98 = V_100 + V_97 * 16 ;
}
return V_98 ;
}
void F_95 ( void )
{
T_5 V_34 , V_35 , V_98 , V_101 ;
T_2 V_102 ;
T_4 V_97 ;
memset ( V_103 , V_104 , sizeof( V_103 ) ) ;
for ( V_34 = 0 ; V_34 < V_105 ; V_34 ++ ) {
V_102 = V_106 [ V_34 ] -> V_107 ;
for ( V_35 = 0 ; V_35 < V_108 ; V_35 ++ ) {
V_97 = ( V_102 >> ( ( V_35 / 8 ) * 8 ) ) & 0xFF ;
V_98 = F_94 ( V_34 , V_97 ) ;
V_98 += ( V_35 % 8 ) + ( ( V_35 / 8 ) & 1 ? 8 : 0 ) ;
V_101 = V_35 + V_34 * V_108 ;
V_109 [ V_101 ] = V_98 - V_110 ;
V_103 [ V_98 - V_110 ] = V_101 ;
}
}
}
static void F_65 ( struct V_22 * V_23 )
{
T_2 V_111 = V_103 [ V_23 -> V_25 - V_110 ] ;
T_2 V_112 = F_96 ( V_111 ) ;
T_2 V_34 = F_97 ( V_111 ) ;
if ( F_98 ( V_23 ) == V_113 ) {
if ( V_106 [ V_34 ] -> V_114 & V_112 )
V_106 [ V_34 ] -> V_115 = V_112 ;
else
V_106 [ V_34 ] -> V_114 = V_112 ;
}
V_106 [ V_34 ] -> V_116 = V_112 ;
}
static void F_68 ( struct V_22 * V_23 )
{
T_2 V_111 = V_103 [ V_23 -> V_25 - V_110 ] ;
T_2 V_112 = F_96 ( V_111 ) ;
T_2 V_34 = F_97 ( V_111 ) ;
if ( F_98 ( V_23 ) == V_113 ) {
if ( V_106 [ V_34 ] -> V_114 & V_112 )
V_106 [ V_34 ] -> V_115 = V_112 ;
else
V_106 [ V_34 ] -> V_114 = V_112 ;
}
V_106 [ V_34 ] -> V_116 = V_112 ;
V_106 [ V_34 ] -> V_117 = V_112 ;
}
static void F_71 ( struct V_22 * V_23 )
{
T_2 V_111 = V_103 [ V_23 -> V_25 - V_110 ] ;
V_106 [ F_97 ( V_111 ) ] -> V_117 = F_96 ( V_111 ) ;
}
static void F_72 ( struct V_22 * V_23 )
{
T_2 V_111 = V_103 [ V_23 -> V_25 - V_110 ] ;
T_2 V_112 = F_96 ( V_111 ) ;
T_2 V_34 = F_97 ( V_111 ) ;
V_106 [ V_34 ] -> V_118 = V_112 ;
}
static unsigned int F_73 ( struct V_22 * V_23 )
{
unsigned int V_25 = V_23 -> V_25 ;
T_2 V_67 = F_67 ( V_25 ) ;
T_2 V_111 = V_103 [ V_25 - V_110 ] ;
if ( V_111 == V_104 ) {
F_62 ( V_63
L_7
L_8 , V_25 ) ;
return - V_119 ;
}
if ( F_74 ( V_67 , V_68 ) )
F_75 ( V_67 ) ;
F_72 ( V_23 ) ;
return 0 ;
}
static void F_76 ( struct V_22 * V_23 )
{
T_2 V_67 = F_67 ( V_23 -> V_25 ) ;
F_71 ( V_23 ) ;
F_77 ( V_67 , V_68 ) ;
F_78 ( V_67 ) ;
}
static int F_79 ( struct V_22 * V_23 , unsigned int type )
{
unsigned int V_25 = V_23 -> V_25 ;
int V_69 ;
char V_70 [ 16 ] ;
T_2 V_67 = F_67 ( V_25 ) ;
T_2 V_111 = V_103 [ V_25 - V_110 ] ;
T_2 V_112 = F_96 ( V_111 ) ;
T_2 V_34 = F_97 ( V_111 ) ;
if ( V_111 == V_104 )
return - V_119 ;
if ( type == V_71 ) {
if ( F_80 ( V_67 , V_68 ) )
return 0 ;
type = V_72 | V_73 ;
}
if ( type & ( V_72 | V_73 |
V_74 | V_75 ) ) {
snprintf ( V_70 , 16 , L_6 , V_25 ) ;
V_69 = F_81 ( V_67 , V_70 ) ;
if ( V_69 )
return V_69 ;
if ( F_74 ( V_67 , V_68 ) )
F_75 ( V_67 ) ;
} else {
F_77 ( V_67 , V_68 ) ;
return 0 ;
}
if ( ( type & ( V_73 | V_75 ) ) )
V_106 [ V_34 ] -> V_114 = V_112 ;
else
V_106 [ V_34 ] -> V_115 = V_112 ;
if ( ( type & ( V_72 | V_73 ) )
== ( V_72 | V_73 ) ) {
if ( F_99 ( V_67 ) )
V_106 [ V_34 ] -> V_114 = V_112 ;
else
V_106 [ V_34 ] -> V_115 = V_112 ;
}
if ( type & ( V_72 | V_73 ) ) {
V_106 [ V_34 ] -> V_120 = V_112 ;
F_63 ( V_25 , V_76 ) ;
} else {
V_106 [ V_34 ] -> V_121 = V_112 ;
F_63 ( V_25 , V_66 ) ;
}
return 0 ;
}
static int F_87 ( struct V_22 * V_23 , unsigned int V_33 )
{
T_2 V_122 ;
T_2 V_111 = V_103 [ V_23 -> V_25 - V_110 ] ;
T_2 V_34 = F_97 ( V_111 ) ;
switch ( V_34 ) {
case 0 :
V_122 = V_123 ;
break;
case 2 :
V_122 = V_124 ;
break;
case 3 :
V_122 = V_125 ;
break;
case 1 :
V_122 = V_126 ;
break;
default:
return - V_127 ;
}
F_24 ( V_122 , V_33 ) ;
return 0 ;
}
void F_92 ( unsigned int V_78 ,
struct V_58 * V_79 )
{
T_2 V_34 , V_111 ;
T_2 V_116 , V_25 ;
switch ( V_78 ) {
case V_123 :
V_34 = 0 ;
break;
case V_124 :
V_34 = 2 ;
break;
case V_125 :
V_34 = 3 ;
break;
case V_126 :
V_34 = 1 ;
break;
default:
return;
}
V_111 = V_34 * V_108 ;
V_116 = V_106 [ V_34 ] -> V_116 ;
while ( V_116 ) {
if ( V_116 & 1 ) {
V_25 = V_109 [ V_111 ] + V_110 ;
F_31 ( V_25 ) ;
}
V_111 ++ ;
V_116 >>= 1 ;
}
}
void T_6 F_100 ( void )
{
F_101 ( V_128 ) ;
F_102 ( V_129 ) ;
F_103 ( V_130 ) ;
F_104 ( V_131 ) ;
F_105 ( V_132 ) ;
F_106 ( V_133 ) ;
F_107 ( V_134 ) ;
F_108 ( V_135 ) ;
F_109 ( V_136 ) ;
F_110 ( V_137 ) ;
F_111 ( V_138 ) ;
F_112 ( V_139 ) ;
F_113 ( V_140 ) ;
F_114 () ;
}
int T_1 F_115 ( void )
{
int V_25 ;
unsigned long V_141 = 0 ;
#ifdef F_11
F_116 ( V_142 ) ;
F_117 ( V_142 ) ;
# ifdef F_118
F_119 ( V_142 ) ;
# endif
# ifdef F_15
F_120 ( V_142 ) ;
F_121 ( V_142 ) ;
# endif
#else
F_13 ( V_142 ) ;
#endif
F_122 () ;
#ifdef F_29
# ifdef F_123
V_106 [ 0 ] -> V_107 = V_143 ;
V_106 [ 1 ] -> V_107 = V_144 ;
V_106 [ 2 ] -> V_107 = V_145 ;
V_106 [ 3 ] -> V_107 = V_146 ;
# endif
F_95 () ;
#endif
for ( V_25 = 0 ; V_25 <= V_110 ; V_25 ++ ) {
if ( V_25 <= V_147 )
F_124 ( V_25 , & V_148 ) ;
else
F_124 ( V_25 , & V_149 ) ;
switch ( V_25 ) {
#if F_3 ( F_54 )
case V_83 :
case V_80 :
#elif F_3 ( V_85 )
case V_86 :
#elif F_3 ( F_29 )
case V_123 :
case V_126 :
case V_124 :
case V_125 :
#elif F_3 ( V_15 ) || F_3 ( V_14 )
case V_88 :
case V_89 :
case V_90 :
#elif F_3 ( V_91 )
case V_92 :
case V_93 :
case V_95 :
#elif F_3 ( V_87 )
case V_88 :
#endif
F_125 ( V_25 , F_92 ) ;
break;
#if F_3 ( V_150 ) || F_3 ( V_151 )
case V_55 :
F_125 ( V_25 ,
F_59 ) ;
break;
#endif
#ifdef F_15
case V_152 :
case V_153 :
F_126 ( V_25 , V_154 ) ;
break;
#endif
#ifdef F_127
case V_147 :
# ifdef F_15
F_126 ( V_25 , V_154 ) ;
# else
F_126 ( V_25 , V_155 ) ;
# endif
break;
#endif
#ifdef F_128
case V_156 :
F_126 ( V_25 , V_155 ) ;
break;
#endif
default:
#ifdef F_32
F_126 ( V_25 , V_66 ) ;
#else
F_126 ( V_25 , V_155 ) ;
#endif
break;
}
}
F_129 () ;
#if F_3 ( V_150 ) || F_3 ( V_151 )
for ( V_25 = V_52 ; V_25 <= V_62 ; V_25 ++ )
F_130 ( V_25 , & V_157 ,
V_66 ) ;
#endif
for ( V_25 = V_158 ;
V_25 < ( V_158 + V_159 ) ; V_25 ++ )
F_130 ( V_25 , & V_160 ,
V_66 ) ;
F_131 ( 0 ) ;
F_114 () ;
V_141 = F_132 () ;
F_114 () ;
F_133 ( V_141 ) ;
F_114 () ;
F_62 ( V_161 L_9 ) ;
F_134 () ;
F_1 () ;
V_24 |= V_162 |
V_163 | V_164 | V_165 | V_166 |
V_167 | V_168 | V_169 | V_170 | V_171 ;
#ifdef F_135
F_136 ( V_172 ) ;
# ifdef F_137
if ( V_173 )
F_138 ( F_139 ( 10 ) | F_139 ( 11 ) ) ;
else
F_138 ( V_172 ) ;
# endif
# ifdef F_140
F_141 ( V_172 ) ;
# endif
#else
F_142 ( V_172 ) ;
#endif
return 0 ;
}
static int F_143 ( int V_174 )
{
struct V_175 * V_1 = V_6 [ V_174 - V_4 ] . V_8 ;
struct V_175 * V_176 = V_6 [ V_174 - V_4 ] . V_7 ;
unsigned long V_177 [ 3 ] ;
if ( F_144 ( V_174 == V_178 ) )
return V_147 ;
#ifdef F_145
V_177 [ 0 ] = F_14 () & F_146 () ;
#else
if ( F_147 () ) {
# ifdef F_148
V_177 [ 0 ] = F_149 () & F_150 () ;
V_177 [ 1 ] = F_151 () & F_152 () ;
# endif
} else {
V_177 [ 0 ] = F_153 () & F_154 () ;
V_177 [ 1 ] = F_155 () & F_156 () ;
}
#endif
#ifdef F_157
V_177 [ 2 ] = F_158 () & F_159 () ;
#endif
for (; ; V_1 ++ ) {
if ( V_1 >= V_176 )
return - 1 ;
#ifdef F_145
if ( V_177 [ 0 ] & V_1 -> V_21 )
#else
if ( V_177 [ ( V_1 -> V_20 - V_4 ) / 32 ] & V_1 -> V_21 )
#endif
return V_1 -> V_20 ;
}
}
void F_160 ( int V_174 , struct V_44 * V_179 )
{
int V_25 = F_143 ( V_174 ) ;
if ( V_25 == - 1 )
return;
F_161 ( V_25 , V_179 ) ;
}
int F_162 ( unsigned V_25 )
{
int V_180 , V_181 ;
if ( V_25 <= V_147 )
return V_25 ;
for ( V_180 = 0 ; V_180 < V_10 ; V_180 ++ ) {
struct V_175 * V_1 = V_9 + V_180 ;
if ( V_1 -> V_20 == V_25 ) {
for ( V_181 = 0 ; V_181 <= V_3 - V_4 ; V_181 ++ ) {
if ( V_6 [ V_181 ] . V_8 <= V_1 &&
V_6 [ V_181 ] . V_7 > V_1 )
return V_4 + V_181 ;
}
}
}
return V_182 ;
}
T_7 int F_163 ( int V_174 , struct V_44 * V_45 )
{
struct V_183 * V_184 = F_164 () ;
struct V_185 * V_186 = V_187 ;
struct V_175 * V_176 = V_6 [ V_174 - V_4 ] . V_7 ;
struct V_175 * V_1 = V_6 [ V_174 - V_4 ] . V_8 ;
int V_25 , V_188 = 0 ;
V_25 = F_143 ( V_174 ) ;
if ( V_25 == - 1 )
return 0 ;
if ( V_25 == V_189 ) {
#if ! F_3 ( V_190 ) || F_3 ( F_128 )
F_165 ( 1 ) ;
#endif
F_166 ( V_191 ) . V_192 = V_45 -> V_192 ;
F_166 ( V_191 ) . V_193 = V_45 -> V_193 ;
if ( V_186 != V_194 )
F_166 ( V_191 ) . V_192 &= ~ 0x10 ;
else
F_166 ( V_191 ) . V_192 |= 0x10 ;
}
if ( V_186 == V_194 ) {
V_188 = F_74 ( V_195 , & V_184 -> V_61 ) ;
F_167 () ;
}
F_33 ( V_25 ) ;
F_34 ( V_25 , V_45 ) ;
F_35 ( V_25 ) ;
if ( F_168 ( V_45 ) &&
! F_169 () &&
( V_196 -> V_197 & V_198 ) != 0 ) {
V_196 -> V_197 &= ~ V_198 ;
F_170 ( V_199 , V_45 ) ;
}
if ( V_186 == V_194 ) {
F_171 ( V_200 ) ;
if ( ! V_188 ) {
F_77 ( V_195 , & V_184 -> V_61 ) ;
return ! F_80 ( V_201 , & V_184 -> V_61 ) ;
}
}
return 0 ;
}
