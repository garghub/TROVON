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
#ifndef F_11
#ifdef F_12
unsigned V_27 = F_13 ( V_25 ) / 32 ;
unsigned V_28 = F_13 ( V_25 ) % 32 ;
F_14 ( V_27 , F_15 ( V_27 ) &
~ ( 1 << V_28 ) ) ;
# if F_3 ( V_29 ) || F_3 ( V_30 )
F_16 ( V_27 , F_17 ( V_27 ) &
~ ( 1 << V_28 ) ) ;
# endif
#else
F_14 ( F_15 () &
~ ( 1 << F_13 ( V_25 ) ) ) ;
#endif
#endif
F_18 ( V_26 ) ;
}
static void F_19 ( struct V_22 * V_23 )
{
F_9 ( V_23 -> V_25 ) ;
}
static void F_20 ( struct V_22 * V_23 )
{
unsigned long V_26 = F_10 () ;
unsigned int V_31 = F_13 ( V_23 -> V_25 ) ;
F_21 ( 0 , V_32 , V_31 ) ;
F_18 ( V_26 ) ;
}
static void F_22 ( struct V_22 * V_23 )
{
unsigned long V_26 = F_10 () ;
unsigned int V_31 = F_13 ( V_23 -> V_25 ) ;
F_21 ( 0 , V_32 , V_31 ) ;
F_18 ( V_26 ) ;
}
static void F_23 ( struct V_22 * V_23 )
{
unsigned long V_26 = F_10 () ;
unsigned int V_31 = F_13 ( V_23 -> V_25 ) ;
F_24 ( V_33 , V_31 ) ;
F_18 ( V_26 ) ;
}
static void F_25 ( unsigned int V_31 )
{
unsigned long V_26 = F_10 () ;
T_3 V_34 = F_26 ( V_31 ) ;
V_34 |= V_35 ;
F_27 ( V_31 , V_34 ) ;
F_18 ( V_26 ) ;
}
static void F_28 ( unsigned int V_31 )
{
unsigned long V_26 = F_10 () ;
T_3 V_34 = F_26 ( V_31 ) ;
V_34 &= ( ( T_3 ) ~ V_35 ) ;
F_27 ( V_31 , V_34 ) ;
F_18 ( V_26 ) ;
}
static void F_29 ( unsigned int V_31 , unsigned int V_36 )
{
unsigned long V_26 = F_10 () ;
T_3 V_34 = F_26 ( V_31 ) ;
V_34 &= ( ( T_3 ) ~ V_37 ) ;
F_27 ( V_31 , V_34 | ( ( V_36 << 20 ) & V_37 ) ) ;
F_18 ( V_26 ) ;
}
static void F_30 ( unsigned int V_31 )
{
unsigned long V_26 = F_10 () ;
T_3 V_34 = F_26 ( V_31 ) ;
if ( V_31 == F_13 ( V_38 ) )
V_34 |= V_39 ;
else
V_34 |= V_40 ;
F_27 ( V_31 , V_34 ) ;
F_18 ( V_26 ) ;
}
static void F_31 ( unsigned int V_31 )
{
unsigned long V_26 = F_10 () ;
T_3 V_34 = F_26 ( V_31 ) ;
V_34 &= ( ( T_3 ) ~ V_40 ) ;
F_27 ( V_31 , V_34 ) ;
F_18 ( V_26 ) ;
}
static void F_32 ( struct V_22 * V_23 )
{
unsigned long V_26 = F_10 () ;
unsigned int V_31 = F_13 ( V_23 -> V_25 ) ;
F_30 ( V_31 ) ;
F_25 ( V_31 ) ;
F_18 ( V_26 ) ;
}
static void F_33 ( struct V_22 * V_23 )
{
unsigned long V_26 = F_10 () ;
unsigned int V_31 = F_13 ( V_23 -> V_25 ) ;
F_31 ( V_31 ) ;
F_28 ( V_31 ) ;
F_18 ( V_26 ) ;
}
static void F_34 ( unsigned int V_41 , T_4 * V_42 )
{
unsigned long V_26 = F_10 () ;
T_3 V_34 ;
int V_43 ;
F_21 ( 0 , V_44 , V_41 ) ;
for ( V_43 = 0 ; V_43 < V_45 - F_35 ( 0 ) ; V_43 ++ ) {
V_34 = F_26 ( V_43 ) & ~ V_46 ;
V_34 |= V_42 [ V_43 ] << V_47 ;
F_27 ( V_43 , V_34 ) ;
}
F_18 ( V_26 ) ;
}
void F_36 ( unsigned int V_31 )
{
unsigned long V_26 = F_10 () ;
F_24 ( V_48 , V_31 ) ;
F_18 ( V_26 ) ;
}
static void F_37 ( void )
{
F_29 ( 34 , 0 ) ;
F_29 ( 35 , 1 ) ;
F_29 ( 36 , 0 ) ;
F_29 ( 37 , 1 ) ;
}
void F_38 ( void )
{
F_21 ( 0 , V_49 , V_50 ) ;
F_39 ( 100 ) ;
F_40 ( V_51 ) ;
F_21 ( 0 , V_49 , V_52 | V_53 ) ;
}
void F_41 ( T_3 V_54 )
{
}
void F_42 ( T_3 V_54 )
{
T_3 V_55 ;
T_3 V_56 ;
V_55 = V_54 & V_57 ;
V_56 = F_43 ( V_55 , V_58 ) ;
if ( V_56 & V_59 ) {
switch ( V_56 & V_60 ) {
case V_61 :
F_44 ( V_62 L_1 ) ;
break;
default:
F_44 ( V_62 L_2 ) ;
}
}
}
void F_45 ( T_3 V_54 )
{
T_3 V_31 ;
T_3 V_63 ;
V_31 = V_54 & V_64 ;
V_63 = F_46 ( V_31 ) ;
}
void F_47 ( unsigned int V_25 , struct V_65 * V_66 )
{
T_3 V_67 ;
F_48 ( & V_66 -> V_68 ) ;
V_67 = F_2 ( V_69 ) ;
if ( V_67 & V_70 ) {
switch ( V_67 & V_71 ) {
case 0 :
F_41 ( V_67 ) ;
break;
case V_72 :
F_42 ( V_67 ) ;
break;
case V_73 :
F_45 ( V_67 ) ;
break;
}
}
F_49 ( & V_66 -> V_68 ) ;
}
void F_50 ( unsigned int V_25 , struct V_65 * V_66 )
{
struct V_74 * V_75 = F_51 () ;
F_48 ( & V_66 -> V_68 ) ;
switch ( V_25 ) {
case V_76 :
F_52 ( V_75 ) ;
break;
case V_77 :
F_53 ( V_75 ) ;
F_54 ( V_75 ) ;
F_55 ( V_75 ) ;
F_44 ( V_78 L_3 ) ;
F_56 ( V_79 , NULL ) ;
F_57 () ;
F_58 ( L_4 ) ;
break;
case V_80 :
F_58 ( L_5 ) ;
break;
default:
F_58 ( L_6 ) ;
}
F_49 ( & V_66 -> V_68 ) ;
}
static void F_59 ( struct V_22 * V_23 )
{
F_60 ( V_23 -> V_25 , V_23 -> V_81 ) ;
}
static int F_61 ( struct V_22 * V_23 ,
const struct V_82 * V_83 , bool V_84 )
{
F_9 ( V_23 -> V_25 ) ;
F_60 ( V_23 -> V_25 , V_83 ) ;
return 0 ;
}
static void F_59 ( struct V_22 * V_23 )
{
F_62 ( V_23 -> V_25 ) ;
}
int F_63 ( unsigned int V_25 , unsigned int V_85 )
{
T_2 V_86 , V_87 , V_88 = 0 ;
unsigned long V_26 ;
V_86 = F_13 ( V_25 ) / 32 ;
V_87 = F_13 ( V_25 ) % 32 ;
switch ( V_25 ) {
#ifdef F_64
case F_64 :
V_88 |= V_89 ;
break;
#endif
#ifdef F_65
case F_65 :
V_88 |= V_90 ;
break;
#endif
#ifdef F_66
case F_66 :
V_88 |= V_90 ;
break;
#endif
#ifdef F_67
case F_67 :
V_88 |= V_91 ;
break;
#endif
#ifdef F_68
case V_92 :
V_88 |= V_93 ;
break;
#endif
default:
break;
}
V_26 = F_10 () ;
if ( V_85 ) {
V_94 [ V_86 ] |= ( 1 << V_87 ) ;
V_95 |= V_88 ;
} else {
V_94 [ V_86 ] &= ~ ( 1 << V_87 ) ;
V_95 &= ~ V_88 ;
}
F_18 ( V_26 ) ;
return 0 ;
}
static int F_69 ( struct V_22 * V_23 , unsigned int V_85 )
{
return F_63 ( V_23 -> V_25 , V_85 ) ;
}
inline int F_63 ( unsigned int V_25 , unsigned int V_85 )
{
return 0 ;
}
void F_70 ( unsigned V_25 )
{
#ifdef F_71
struct V_74 V_96 ;
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
F_62 ( V_106 ) ;
#endif
V_104 |= 1L << ( V_25 - V_103 ) ;
}
int F_97 ( struct V_22 * V_23 , unsigned int V_85 )
{
#ifdef F_93
return F_63 ( V_107 , V_85 ) ;
#else
return F_63 ( V_106 , V_85 ) ;
#endif
}
void F_98 ( unsigned int V_108 ,
struct V_65 * V_109 )
{
int V_43 , V_25 = 0 ;
T_2 V_110 = F_99 () ;
for ( V_43 = 0 ; V_43 <= ( V_111 - V_103 ) ; V_43 ++ )
if ( V_110 & ( 1L << V_43 ) ) {
V_25 = V_103 + V_43 ;
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
F_44 ( V_112
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
static int F_125 ( struct V_22 * V_23 , unsigned int V_85 )
{
return F_126 ( F_105 ( V_23 -> V_25 ) , V_85 ) ;
}
static void F_127 ( unsigned int V_25 )
{
unsigned int V_126 , V_83 ;
V_126 = F_105 ( V_25 ) ;
V_83 = F_128 ( V_126 ) & F_129 ( V_126 ) ;
while ( V_83 ) {
if ( V_83 & 1 )
F_70 ( V_25 ) ;
V_25 ++ ;
V_83 >>= 1 ;
}
}
void F_130 ( unsigned int V_127 ,
struct V_65 * V_66 )
{
unsigned int V_25 ;
switch ( V_127 ) {
#if F_3 ( F_93 )
case V_128 :
F_127 ( V_129 ) ;
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
F_131 () ;
return;
}
F_127 ( V_25 ) ;
}
inline unsigned int F_132 ( T_2 V_86 , T_4 V_145 )
{
unsigned int V_146 ;
#ifndef F_133
if ( V_86 < 2 ) {
V_146 = V_147 + V_145 * 16 ;
} else {
V_146 = V_148 + V_145 * 16 ;
}
#else
V_146 = V_147 + V_86 * 16 + V_145 * 16 ;
#endif
return V_146 ;
}
void F_134 ( void )
{
T_6 V_86 , V_87 , V_146 , V_149 ;
T_2 V_150 ;
T_4 V_145 ;
memset ( V_151 , V_152 , sizeof( V_151 ) ) ;
for ( V_86 = 0 ; V_86 < V_153 ; V_86 ++ ) {
V_150 = V_154 [ V_86 ] -> V_155 ;
for ( V_87 = 0 ; V_87 < V_156 ; V_87 ++ ) {
V_145 = ( V_150 >> ( ( V_87 / 8 ) * 8 ) ) & 0xFF ;
V_146 = F_132 ( V_86 , V_145 ) ;
V_146 += ( V_87 % 8 ) + ( ( V_87 / 8 ) & 1 ? 8 : 0 ) ;
V_149 = V_87 + V_86 * V_156 ;
V_157 [ V_149 ] = V_146 - V_45 ;
V_151 [ V_146 - V_45 ] = V_149 ;
}
}
}
static void F_103 ( struct V_22 * V_23 )
{
T_2 V_158 = V_151 [ V_23 -> V_25 - V_45 ] ;
T_2 V_159 = F_135 ( V_158 ) ;
T_2 V_86 = F_136 ( V_158 ) ;
if ( F_137 ( V_23 ) == V_160 ) {
if ( V_154 [ V_86 ] -> V_161 & V_159 )
V_154 [ V_86 ] -> V_162 = V_159 ;
else
V_154 [ V_86 ] -> V_161 = V_159 ;
}
V_154 [ V_86 ] -> V_163 = V_159 ;
}
static void F_106 ( struct V_22 * V_23 )
{
T_2 V_158 = V_151 [ V_23 -> V_25 - V_45 ] ;
T_2 V_159 = F_135 ( V_158 ) ;
T_2 V_86 = F_136 ( V_158 ) ;
if ( F_137 ( V_23 ) == V_160 ) {
if ( V_154 [ V_86 ] -> V_161 & V_159 )
V_154 [ V_86 ] -> V_162 = V_159 ;
else
V_154 [ V_86 ] -> V_161 = V_159 ;
}
V_154 [ V_86 ] -> V_163 = V_159 ;
V_154 [ V_86 ] -> V_164 = V_159 ;
}
static void F_109 ( struct V_22 * V_23 )
{
T_2 V_158 = V_151 [ V_23 -> V_25 - V_45 ] ;
V_154 [ F_136 ( V_158 ) ] -> V_164 = F_135 ( V_158 ) ;
}
static void F_110 ( struct V_22 * V_23 )
{
T_2 V_158 = V_151 [ V_23 -> V_25 - V_45 ] ;
T_2 V_159 = F_135 ( V_158 ) ;
T_2 V_86 = F_136 ( V_158 ) ;
V_154 [ V_86 ] -> V_165 = V_159 ;
}
static unsigned int F_111 ( struct V_22 * V_23 )
{
unsigned int V_25 = V_23 -> V_25 ;
T_2 V_116 = F_105 ( V_25 ) ;
T_2 V_158 = V_151 [ V_25 - V_45 ] ;
if ( V_158 == V_152 ) {
F_44 ( V_112
L_13
L_14 , V_25 ) ;
return - V_166 ;
}
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
T_2 V_158 = V_151 [ V_25 - V_45 ] ;
T_2 V_159 = F_135 ( V_158 ) ;
T_2 V_86 = F_136 ( V_158 ) ;
if ( V_158 == V_152 )
return - V_166 ;
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
if ( ( type & ( V_122 | V_124 ) ) )
V_154 [ V_86 ] -> V_161 = V_159 ;
else
V_154 [ V_86 ] -> V_162 = V_159 ;
if ( ( type & ( V_121 | V_122 ) )
== ( V_121 | V_122 ) ) {
if ( F_138 ( V_116 ) )
V_154 [ V_86 ] -> V_161 = V_159 ;
else
V_154 [ V_86 ] -> V_162 = V_159 ;
}
if ( type & ( V_121 | V_122 ) ) {
V_154 [ V_86 ] -> V_167 = V_159 ;
F_101 ( V_25 , V_125 ) ;
} else {
V_154 [ V_86 ] -> V_168 = V_159 ;
F_101 ( V_25 , V_115 ) ;
}
return 0 ;
}
static int F_125 ( struct V_22 * V_23 , unsigned int V_85 )
{
T_2 V_169 ;
T_2 V_158 = V_151 [ V_23 -> V_25 - V_45 ] ;
T_2 V_86 = F_136 ( V_158 ) ;
switch ( V_86 ) {
case 0 :
V_169 = V_170 ;
break;
case 2 :
V_169 = V_171 ;
break;
case 3 :
V_169 = V_172 ;
break;
case 1 :
V_169 = V_173 ;
break;
#ifdef F_133
case 4 :
V_169 = V_174 ;
break;
case 5 :
V_169 = V_175 ;
break;
#endif
default:
return - V_176 ;
}
F_63 ( V_169 , V_85 ) ;
return 0 ;
}
void F_139 ( void )
{
T_2 V_86 ;
for ( V_86 = 0 ; V_86 < V_153 ; V_86 ++ ) {
V_177 [ V_86 ] . V_165 = V_154 [ V_86 ] -> V_165 ;
V_177 [ V_86 ] . V_155 = V_154 [ V_86 ] -> V_155 ;
V_177 [ V_86 ] . V_167 = V_154 [ V_86 ] -> V_167 ;
V_177 [ V_86 ] . V_161 = V_154 [ V_86 ] -> V_161 ;
}
}
void F_140 ( void )
{
T_2 V_86 ;
for ( V_86 = 0 ; V_86 < V_153 ; V_86 ++ ) {
V_154 [ V_86 ] -> V_165 = V_177 [ V_86 ] . V_165 ;
V_154 [ V_86 ] -> V_155 = V_177 [ V_86 ] . V_155 ;
V_154 [ V_86 ] -> V_167 = V_177 [ V_86 ] . V_167 ;
V_154 [ V_86 ] -> V_161 = V_177 [ V_86 ] . V_161 ;
}
}
static int F_141 ( void )
{
T_2 V_86 ;
for ( V_86 = 0 ; V_86 < V_153 ; V_86 ++ )
V_178 [ V_86 ] = F_26 ( V_86 + F_13 ( V_170 ) ) ;
return 0 ;
}
static void F_142 ( void )
{
T_2 V_86 ;
F_21 ( 0 , V_49 , V_50 ) ;
F_39 ( 100 ) ;
F_40 ( V_51 ) ;
F_21 ( 0 , V_49 , V_52 | V_53 ) ;
for ( V_86 = 0 ; V_86 < V_153 ; V_86 ++ )
F_27 ( V_86 + F_13 ( V_170 ) , V_178 [ V_86 ] ) ;
}
void F_130 ( unsigned int V_127 ,
struct V_65 * V_66 )
{
T_2 V_86 , V_158 ;
T_2 V_163 , V_25 ;
T_2 V_179 ;
int V_180 = 0 ;
struct V_181 * V_182 = F_143 ( V_66 ) ;
if ( V_182 -> V_183 ) {
V_182 -> V_183 ( & V_66 -> V_22 ) ;
} else {
V_182 -> V_184 ( & V_66 -> V_22 ) ;
if ( V_182 -> V_185 )
V_182 -> V_185 ( & V_66 -> V_22 ) ;
}
switch ( V_127 ) {
case V_170 :
V_86 = 0 ;
break;
case V_171 :
V_86 = 2 ;
break;
case V_172 :
V_86 = 3 ;
break;
case V_173 :
V_86 = 1 ;
break;
#ifdef F_133
case V_174 :
V_86 = 4 ;
break;
case V_175 :
V_86 = 5 ;
break;
#endif
default:
return;
}
V_158 = V_86 * V_156 ;
V_163 = V_154 [ V_86 ] -> V_163 ;
V_179 = V_154 [ V_86 ] -> V_167 & V_163 ;
while ( V_163 ) {
if ( V_163 & 1 ) {
V_25 = V_157 [ V_158 ] + V_45 ;
if ( V_179 & F_135 ( V_158 ) ) {
V_180 = 1 ;
V_182 -> V_186 ( & V_66 -> V_22 ) ;
}
F_70 ( V_25 ) ;
}
V_158 ++ ;
V_163 >>= 1 ;
}
if ( ! V_180 )
V_182 -> V_186 ( & V_66 -> V_22 ) ;
}
void T_7 F_144 ( void )
{
F_145 ( V_187 ) ;
F_146 ( V_188 ) ;
F_147 ( V_189 ) ;
F_148 ( V_190 ) ;
F_149 ( V_191 ) ;
F_150 ( V_192 ) ;
F_151 ( V_193 ) ;
F_152 ( V_194 ) ;
F_153 ( V_195 ) ;
F_154 ( V_196 ) ;
F_155 ( V_197 ) ;
F_156 ( V_198 ) ;
F_157 ( V_199 ) ;
F_158 () ;
}
int T_1 F_159 ( void )
{
int V_25 ;
unsigned long V_200 = 0 ;
#ifdef F_12
F_160 ( V_201 ) ;
F_161 ( V_201 ) ;
# ifdef F_162
F_163 ( V_201 ) ;
# endif
# if F_3 ( V_29 ) || F_3 ( V_30 )
F_164 ( V_201 ) ;
F_165 ( V_201 ) ;
# endif
#else
F_14 ( V_201 ) ;
#endif
F_166 () ;
#if V_202
# ifdef F_167
V_154 [ 0 ] -> V_155 = V_203 ;
V_154 [ 1 ] -> V_155 = V_204 ;
V_154 [ 2 ] -> V_155 = V_205 ;
V_154 [ 3 ] -> V_155 = V_206 ;
# endif
F_134 () ;
#endif
for ( V_25 = 0 ; V_25 <= V_45 ; V_25 ++ ) {
if ( V_25 <= V_207 )
F_168 ( V_25 , & V_208 ) ;
else
F_168 ( V_25 , & V_209 ) ;
switch ( V_25 ) {
#if V_202
case V_170 :
case V_173 :
case V_171 :
case V_172 :
#elif F_3 ( F_93 )
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
F_169 ( V_25 , F_130 ) ;
break;
#if F_3 ( V_210 ) || F_3 ( V_211 )
case V_106 :
F_169 ( V_25 ,
F_98 ) ;
break;
#endif
#if F_3 ( V_29 ) || F_3 ( V_30 )
case V_212 :
case V_213 :
F_170 ( V_25 , V_214 ) ;
break;
#endif
#ifdef F_171
case V_207 :
# ifdef V_29
F_170 ( V_25 , V_214 ) ;
# else
F_170 ( V_25 , V_215 ) ;
# endif
break;
#endif
#ifdef F_172
case V_216 :
F_170 ( V_25 , V_215 ) ;
break;
#endif
default:
#ifdef F_71
F_170 ( V_25 , V_115 ) ;
#else
F_170 ( V_25 , V_215 ) ;
#endif
break;
}
}
F_173 () ;
#if ( F_3 ( V_210 ) || F_3 ( V_211 ) )
for ( V_25 = V_103 ; V_25 <= V_111 ; V_25 ++ )
F_174 ( V_25 , & V_217 ,
V_115 ) ;
#endif
for ( V_25 = V_218 ;
V_25 < ( V_218 + V_219 ) ; V_25 ++ )
F_174 ( V_25 , & V_220 ,
V_115 ) ;
F_175 ( 0 ) ;
F_158 () ;
V_200 = F_176 () ;
F_158 () ;
F_177 ( V_200 ) ;
F_158 () ;
F_44 ( V_221 L_15 ) ;
F_178 () ;
F_1 () ;
V_24 |= V_222 |
V_223 | V_224 | V_225 | V_226 |
V_227 | V_228 | V_229 | V_230 | V_231 ;
#ifdef F_179
F_180 ( V_232 ) ;
# ifdef F_181
if ( V_233 )
F_182 ( F_183 ( 10 ) | F_183 ( 11 ) ) ;
else
F_182 ( V_232 ) ;
# endif
# ifdef F_184
F_185 ( V_232 ) ;
# endif
#else
F_186 ( V_232 ) ;
#endif
return 0 ;
}
static int F_187 ( int V_234 )
{
struct V_235 * V_1 = V_6 [ V_234 - V_4 ] . V_8 ;
struct V_235 * V_236 = V_6 [ V_234 - V_4 ] . V_7 ;
unsigned long V_237 [ 3 ] ;
if ( F_188 ( V_234 == V_238 ) )
return V_207 ;
#ifdef F_189
V_237 [ 0 ] = F_15 () & F_190 () ;
#else
if ( F_191 () ) {
# ifdef F_192
V_237 [ 0 ] = F_193 () & F_194 () ;
V_237 [ 1 ] = F_195 () & F_196 () ;
# endif
} else {
V_237 [ 0 ] = F_197 () & F_198 () ;
V_237 [ 1 ] = F_199 () & F_200 () ;
}
#endif
#ifdef F_201
V_237 [ 2 ] = F_202 () & F_203 () ;
#endif
for (; ; V_1 ++ ) {
if ( V_1 >= V_236 )
return - 1 ;
#ifdef F_189
if ( V_237 [ 0 ] & V_1 -> V_21 )
#else
if ( V_237 [ ( V_1 -> V_20 - V_4 ) / 32 ] & V_1 -> V_21 )
#endif
return V_1 -> V_20 ;
}
}
int T_1 F_159 ( void )
{
int V_25 ;
unsigned long V_200 = 0 ;
F_40 ( V_239 ) ;
F_166 () ;
#if V_202
# ifdef F_167
V_154 [ 0 ] -> V_155 = V_203 ;
V_154 [ 1 ] -> V_155 = V_204 ;
V_154 [ 2 ] -> V_155 = V_205 ;
V_154 [ 3 ] -> V_155 = V_206 ;
V_154 [ 4 ] -> V_155 = V_240 ;
V_154 [ 5 ] -> V_155 = V_241 ;
# endif
F_134 () ;
#endif
for ( V_25 = 0 ; V_25 <= V_45 ; V_25 ++ ) {
if ( V_25 <= V_207 ) {
F_168 ( V_25 , & V_208 ) ;
#ifdef F_171
if ( V_25 == V_207 )
# ifdef V_29
F_170 ( V_25 , V_214 ) ;
# else
F_170 ( V_25 , V_215 ) ;
# endif
#endif
} else if ( V_25 < F_35 ( 0 ) ) {
F_174 ( V_25 , & V_209 ,
V_215 ) ;
} else if ( V_25 == V_242 ) {
F_174 ( V_25 , & V_243 ,
F_47 ) ;
} else if ( V_25 < V_244 && V_25 >= V_76 ) {
F_174 ( V_25 , & V_243 ,
F_50 ) ;
} else if ( V_25 >= F_35 ( 21 ) && V_25 <= F_35 ( 26 ) ) {
F_168 ( V_25 , & V_243 ) ;
F_169 ( V_25 , F_130 ) ;
} else if ( V_25 >= F_35 ( 34 ) && V_25 <= F_35 ( 37 ) ) {
F_168 ( V_25 , & V_243 ) ;
F_170 ( V_25 , V_214 ) ;
} else {
F_174 ( V_25 , & V_243 ,
V_245 ) ;
F_204 ( V_25 , F_20 ) ;
}
}
for ( V_25 = V_218 ;
V_25 < ( V_218 + V_219 ) ; V_25 ++ )
F_174 ( V_25 , & V_220 ,
V_115 ) ;
F_175 ( 0 ) ;
F_158 () ;
V_200 = F_176 () ;
F_158 () ;
F_177 ( V_200 ) ;
F_158 () ;
F_44 ( V_221 L_15 ) ;
F_34 ( V_246 , V_42 ) ;
F_34 ( V_246 , V_42 ) ;
V_24 |= V_222 |
V_223 | V_224 | V_225 | V_226 |
V_227 | V_228 | V_229 | V_230 | V_231 ;
F_205 ( V_247 | V_248 | V_249 ) ;
F_30 ( F_13 ( V_38 ) ) ;
F_25 ( F_13 ( V_38 ) ) ;
F_21 ( 0 , V_49 , V_50 ) ;
F_39 ( 100 ) ;
F_40 ( V_51 ) ;
F_21 ( 0 , V_49 , V_52 | V_53 ) ;
F_21 ( 1 , V_49 , V_52 | V_53 ) ;
F_37 () ;
F_206 ( & V_250 ) ;
return 0 ;
}
static int F_187 ( int V_234 )
{
if ( F_188 ( V_234 == V_238 ) )
return V_207 ;
return F_35 ( F_43 ( 0 , V_32 ) ) ;
}
void F_207 ( int V_234 , struct V_74 * V_75 )
{
int V_25 = F_187 ( V_234 ) ;
if ( V_25 == - 1 )
return;
F_208 ( V_25 , V_75 ) ;
}
int F_209 ( unsigned V_25 )
{
int V_251 , V_252 ;
if ( V_25 <= V_207 )
return V_25 ;
#ifdef F_11
if ( V_25 >= F_35 ( 0 ) )
return V_253 ;
#else
for ( V_251 = 0 ; V_251 < V_10 ; V_251 ++ ) {
struct V_235 * V_1 = V_9 + V_251 ;
if ( V_1 -> V_20 == V_25 ) {
for ( V_252 = 0 ; V_252 <= V_3 - V_4 ; V_252 ++ ) {
if ( V_6 [ V_252 ] . V_8 <= V_1 &&
V_6 [ V_252 ] . V_7 > V_1 )
return V_4 + V_252 ;
}
}
}
#endif
return V_254 ;
}
T_8 int F_210 ( int V_234 , struct V_74 * V_96 )
{
struct V_255 * V_256 = F_211 () ;
struct V_257 * V_258 = V_259 ;
int V_25 , V_260 = 0 ;
V_25 = F_187 ( V_234 ) ;
if ( V_25 == - 1 )
return 0 ;
if ( V_25 == V_261 ) {
#if ! F_3 ( V_262 ) || F_3 ( F_172 )
F_212 ( 1 ) ;
#endif
F_213 ( V_263 ) . V_264 = V_96 -> V_264 ;
F_213 ( V_263 ) . V_265 = V_96 -> V_265 ;
if ( V_258 != V_266 )
F_213 ( V_263 ) . V_264 &= ~ 0x10 ;
else
F_213 ( V_263 ) . V_264 |= 0x10 ;
}
if ( V_258 == V_266 ) {
V_260 = F_112 ( V_267 , & V_256 -> V_110 ) ;
F_214 () ;
}
F_72 ( V_25 ) ;
F_73 ( V_25 , V_96 ) ;
F_74 ( V_25 ) ;
if ( F_215 ( V_96 ) &&
! F_216 () &&
( V_79 -> V_268 & V_269 ) != 0 ) {
V_79 -> V_268 &= ~ V_269 ;
F_217 ( V_270 , V_96 ) ;
}
if ( V_258 == V_266 ) {
F_218 ( V_271 ) ;
if ( ! V_260 ) {
F_115 ( V_267 , & V_256 -> V_110 ) ;
return ! F_118 ( V_272 , & V_256 -> V_110 ) ;
}
}
return 0 ;
}
