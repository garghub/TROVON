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
static void F_34 ( unsigned int V_31 )
{
unsigned long V_26 = F_10 () ;
F_24 ( V_41 , V_31 ) ;
F_18 ( V_26 ) ;
}
static void F_35 ( void )
{
F_29 ( 34 , 0 ) ;
F_29 ( 35 , 1 ) ;
F_29 ( 36 , 0 ) ;
F_29 ( 37 , 1 ) ;
}
void F_36 ( void )
{
F_21 ( 0 , V_42 , V_43 ) ;
F_37 ( 100 ) ;
F_38 ( V_44 ) ;
F_21 ( 0 , V_42 , V_45 | V_46 ) ;
}
void F_39 ( T_3 V_47 )
{
}
void F_40 ( T_3 V_47 )
{
T_3 V_48 ;
T_3 V_49 ;
V_48 = V_47 & V_50 ;
V_49 = F_41 ( V_48 , V_51 ) ;
if ( V_49 & V_52 ) {
switch ( V_49 & V_53 ) {
case V_54 :
F_42 ( V_55 L_1 ) ;
break;
default:
F_42 ( V_55 L_2 ) ;
}
}
}
void F_43 ( T_3 V_47 )
{
T_3 V_31 ;
T_3 V_56 ;
V_31 = V_47 & V_57 ;
V_56 = F_44 ( V_31 ) ;
}
void F_45 ( unsigned int V_25 , struct V_58 * V_59 )
{
T_3 V_60 ;
F_46 ( & V_59 -> V_61 ) ;
V_60 = F_2 ( V_62 ) ;
if ( V_60 & V_63 ) {
switch ( V_60 & V_64 ) {
case 0 :
F_39 ( V_60 ) ;
break;
case V_65 :
F_40 ( V_60 ) ;
break;
case V_66 :
F_43 ( V_60 ) ;
break;
}
}
F_47 ( & V_59 -> V_61 ) ;
}
static int F_48 ( void )
{
return 0 ;
}
static void F_49 ( void )
{
F_21 ( 0 , V_42 , V_43 ) ;
F_37 ( 100 ) ;
F_38 ( V_44 ) ;
F_21 ( 0 , V_42 , V_45 | V_46 ) ;
}
static void F_50 ( struct V_22 * V_23 )
{
F_51 ( V_23 -> V_25 , V_23 -> V_67 ) ;
}
static int F_52 ( struct V_22 * V_23 ,
const struct V_68 * V_69 , bool V_70 )
{
F_9 ( V_23 -> V_25 ) ;
F_51 ( V_23 -> V_25 , V_69 ) ;
return 0 ;
}
static void F_50 ( struct V_22 * V_23 )
{
F_53 ( V_23 -> V_25 ) ;
}
int F_54 ( unsigned int V_25 , unsigned int V_71 )
{
T_2 V_72 , V_73 , V_74 = 0 ;
unsigned long V_26 ;
V_72 = F_13 ( V_25 ) / 32 ;
V_73 = F_13 ( V_25 ) % 32 ;
switch ( V_25 ) {
#ifdef F_55
case F_55 :
V_74 |= V_75 ;
break;
#endif
#ifdef F_56
case F_56 :
V_74 |= V_76 ;
break;
#endif
#ifdef F_57
case F_57 :
V_74 |= V_76 ;
break;
#endif
#ifdef F_58
case F_58 :
V_74 |= V_77 ;
break;
#endif
#ifdef F_59
case V_78 :
V_74 |= V_79 ;
break;
#endif
default:
break;
}
V_26 = F_10 () ;
if ( V_71 ) {
V_80 [ V_72 ] |= ( 1 << V_73 ) ;
V_81 |= V_74 ;
} else {
V_80 [ V_72 ] &= ~ ( 1 << V_73 ) ;
V_81 &= ~ V_74 ;
}
F_18 ( V_26 ) ;
return 0 ;
}
static int F_60 ( struct V_22 * V_23 , unsigned int V_71 )
{
return F_54 ( V_23 -> V_25 , V_71 ) ;
}
void F_61 ( unsigned V_25 )
{
#ifdef F_62
struct V_82 V_83 ;
F_63 ( V_25 ) ;
F_64 ( V_25 , & V_83 ) ;
F_65 ( V_25 ) ;
#else
F_66 ( V_25 ) ;
#endif
}
static void F_67 ( unsigned int V_25 )
{
switch ( V_25 ) {
case V_84 :
F_68 (
F_69 () &
F_70 () ) ;
F_71 (
F_72 () &
F_73 () ) ;
break;
case V_85 :
F_74 (
F_75 () &
F_76 () ) ;
break;
case V_86 :
F_77 (
F_78 () &
F_79 () ) ;
break;
case V_87 :
F_80 (
F_81 () | V_88 | V_89 ) ;
break;
default:
F_82 ( 1L << ( V_25 - V_90 ) ) ;
break;
}
}
static void F_83 ( struct V_22 * V_23 )
{
unsigned int V_25 = V_23 -> V_25 ;
V_91 &= ~ ( 1L << ( V_25 - V_90 ) ) ;
#ifdef F_84
switch ( V_25 ) {
case V_90 :
F_85 ( F_86 () & ~ V_92 ) ;
break;
default:
break;
}
#else
if ( ! V_91 )
F_9 ( V_93 ) ;
#endif
F_67 ( V_25 ) ;
}
static void F_87 ( struct V_22 * V_23 )
{
unsigned int V_25 = V_23 -> V_25 ;
#ifdef F_84
switch ( V_25 ) {
case V_90 :
F_85 ( F_86 () | V_92 ) ;
break;
default:
break;
}
#else
if ( ! V_91 )
F_53 ( V_93 ) ;
#endif
V_91 |= 1L << ( V_25 - V_90 ) ;
}
int F_88 ( struct V_22 * V_23 , unsigned int V_71 )
{
#ifdef F_84
return F_54 ( V_94 , V_71 ) ;
#else
return F_54 ( V_93 , V_71 ) ;
#endif
}
void F_89 ( unsigned int V_95 ,
struct V_58 * V_96 )
{
int V_97 , V_25 = 0 ;
T_2 V_98 = F_90 () ;
for ( V_97 = 0 ; V_97 <= ( V_99 - V_90 ) ; V_97 ++ )
if ( V_98 & ( 1L << V_97 ) ) {
V_25 = V_90 + V_97 ;
break;
}
if ( V_25 ) {
if ( V_91 & ( 1L << ( V_25 - V_90 ) ) ) {
F_61 ( V_25 ) ;
} else {
F_67 ( V_25 ) ;
F_91 ( L_3
L_4 ,
V_25 ) ;
}
} else
F_42 ( V_100
L_5
L_6
L_7 ,
V_101 , __FILE__ , __LINE__ , V_98 ) ;
}
static inline void F_92 ( unsigned V_25 , T_4 V_102 )
{
#ifdef F_62
V_102 = V_103 ;
#endif
F_93 ( V_25 , V_102 ) ;
}
static void F_94 ( struct V_22 * V_23 )
{
F_95 ( F_96 ( V_23 -> V_25 ) , 0 ) ;
}
static void F_97 ( struct V_22 * V_23 )
{
unsigned int V_25 = V_23 -> V_25 ;
T_2 V_104 = F_96 ( V_25 ) ;
if ( ! F_98 ( V_23 ) )
F_95 ( V_104 , 0 ) ;
F_99 ( V_104 , 0 ) ;
}
static void F_100 ( struct V_22 * V_23 )
{
F_99 ( F_96 ( V_23 -> V_25 ) , 0 ) ;
}
static void F_101 ( struct V_22 * V_23 )
{
F_99 ( F_96 ( V_23 -> V_25 ) , 1 ) ;
}
static unsigned int F_102 ( struct V_22 * V_23 )
{
T_2 V_104 = F_96 ( V_23 -> V_25 ) ;
if ( F_103 ( V_104 , V_105 ) )
F_104 ( V_104 ) ;
F_101 ( V_23 ) ;
return 0 ;
}
static void F_105 ( struct V_22 * V_23 )
{
T_2 V_104 = F_96 ( V_23 -> V_25 ) ;
F_100 ( V_23 ) ;
F_106 ( V_104 , V_105 ) ;
F_107 ( V_104 ) ;
}
static int F_108 ( struct V_22 * V_23 , unsigned int type )
{
unsigned int V_25 = V_23 -> V_25 ;
int V_106 ;
char V_107 [ 16 ] ;
T_2 V_104 = F_96 ( V_25 ) ;
if ( type == V_108 ) {
if ( F_109 ( V_104 , V_105 ) )
return 0 ;
type = V_109 | V_110 ;
}
if ( type & ( V_109 | V_110 |
V_111 | V_112 ) ) {
snprintf ( V_107 , 16 , L_8 , V_25 ) ;
V_106 = F_110 ( V_104 , V_107 ) ;
if ( V_106 )
return V_106 ;
if ( F_103 ( V_104 , V_105 ) )
F_104 ( V_104 ) ;
} else {
F_106 ( V_104 , V_105 ) ;
return 0 ;
}
F_111 ( V_104 , 0 ) ;
F_112 ( V_104 , 0 ) ;
if ( ( type & ( V_109 | V_110 ) )
== ( V_109 | V_110 ) )
F_113 ( V_104 , 1 ) ;
else
F_113 ( V_104 , 0 ) ;
if ( ( type & ( V_110 | V_112 ) ) )
F_114 ( V_104 , 1 ) ;
else
F_114 ( V_104 , 0 ) ;
if ( type & ( V_109 | V_110 ) ) {
F_115 ( V_104 , 1 ) ;
F_111 ( V_104 , 1 ) ;
F_95 ( V_104 , 0 ) ;
} else {
F_115 ( V_104 , 0 ) ;
F_111 ( V_104 , 1 ) ;
}
if ( type & ( V_109 | V_110 ) )
F_92 ( V_25 , V_113 ) ;
else
F_92 ( V_25 , V_103 ) ;
return 0 ;
}
static int F_116 ( struct V_22 * V_23 , unsigned int V_71 )
{
return F_117 ( F_96 ( V_23 -> V_25 ) , V_71 ) ;
}
static void F_118 ( unsigned int V_25 )
{
unsigned int V_114 , V_69 ;
V_114 = F_96 ( V_25 ) ;
V_69 = F_119 ( V_114 ) & F_120 ( V_114 ) ;
while ( V_69 ) {
if ( V_69 & 1 )
F_61 ( V_25 ) ;
V_25 ++ ;
V_69 >>= 1 ;
}
}
void F_121 ( unsigned int V_115 ,
struct V_58 * V_59 )
{
unsigned int V_25 ;
switch ( V_115 ) {
#if F_3 ( F_84 )
case V_116 :
F_118 ( V_117 ) ;
V_25 = V_118 ;
break;
case V_119 :
V_25 = V_120 ;
break;
#elif F_3 ( V_121 )
case V_122 :
V_25 = V_117 ;
break;
#elif F_3 ( V_123 )
case V_124 :
V_25 = V_117 ;
break;
#elif F_3 ( V_15 ) || F_3 ( V_14 )
case V_124 :
V_25 = V_117 ;
break;
case V_125 :
V_25 = V_118 ;
break;
case V_126 :
V_25 = V_120 ;
break;
#elif F_3 ( V_127 )
case V_128 :
V_25 = V_117 ;
break;
case V_129 :
V_25 = V_130 ;
break;
case V_131 :
V_25 = V_132 ;
break;
#endif
default:
F_122 () ;
return;
}
F_118 ( V_25 ) ;
}
inline unsigned int F_123 ( T_2 V_72 , T_5 V_133 )
{
unsigned int V_134 ;
if ( V_72 < 2 ) {
V_134 = V_135 + V_133 * 16 ;
} else {
V_134 = V_136 + V_133 * 16 ;
}
return V_134 ;
}
inline unsigned int F_123 ( T_2 V_72 , T_5 V_133 )
{
unsigned int V_134 ;
V_134 = V_135 + V_72 * 16 + V_133 * 16 ;
return V_134 ;
}
void F_124 ( void )
{
T_6 V_72 , V_73 , V_134 , V_137 ;
T_2 V_138 ;
T_5 V_133 ;
memset ( V_139 , V_140 , sizeof( V_139 ) ) ;
for ( V_72 = 0 ; V_72 < V_141 ; V_72 ++ ) {
V_138 = V_142 [ V_72 ] -> V_143 ;
for ( V_73 = 0 ; V_73 < V_144 ; V_73 ++ ) {
V_133 = ( V_138 >> ( ( V_73 / 8 ) * 8 ) ) & 0xFF ;
V_134 = F_123 ( V_72 , V_133 ) ;
V_134 += ( V_73 % 8 ) + ( ( V_73 / 8 ) & 1 ? 8 : 0 ) ;
V_137 = V_73 + V_72 * V_144 ;
V_145 [ V_137 ] = V_134 - V_146 ;
V_139 [ V_134 - V_146 ] = V_137 ;
}
}
}
static void F_94 ( struct V_22 * V_23 )
{
T_2 V_147 = V_139 [ V_23 -> V_25 - V_146 ] ;
T_2 V_148 = F_125 ( V_147 ) ;
T_2 V_72 = F_126 ( V_147 ) ;
if ( F_127 ( V_23 ) == V_149 ) {
if ( V_142 [ V_72 ] -> V_150 & V_148 )
V_142 [ V_72 ] -> V_151 = V_148 ;
else
V_142 [ V_72 ] -> V_150 = V_148 ;
}
V_142 [ V_72 ] -> V_152 = V_148 ;
}
static void F_97 ( struct V_22 * V_23 )
{
T_2 V_147 = V_139 [ V_23 -> V_25 - V_146 ] ;
T_2 V_148 = F_125 ( V_147 ) ;
T_2 V_72 = F_126 ( V_147 ) ;
if ( F_127 ( V_23 ) == V_149 ) {
if ( V_142 [ V_72 ] -> V_150 & V_148 )
V_142 [ V_72 ] -> V_151 = V_148 ;
else
V_142 [ V_72 ] -> V_150 = V_148 ;
}
V_142 [ V_72 ] -> V_152 = V_148 ;
V_142 [ V_72 ] -> V_153 = V_148 ;
}
static void F_100 ( struct V_22 * V_23 )
{
T_2 V_147 = V_139 [ V_23 -> V_25 - V_146 ] ;
V_142 [ F_126 ( V_147 ) ] -> V_153 = F_125 ( V_147 ) ;
}
static void F_101 ( struct V_22 * V_23 )
{
T_2 V_147 = V_139 [ V_23 -> V_25 - V_146 ] ;
T_2 V_148 = F_125 ( V_147 ) ;
T_2 V_72 = F_126 ( V_147 ) ;
V_142 [ V_72 ] -> V_154 = V_148 ;
}
static unsigned int F_102 ( struct V_22 * V_23 )
{
unsigned int V_25 = V_23 -> V_25 ;
T_2 V_104 = F_96 ( V_25 ) ;
T_2 V_147 = V_139 [ V_25 - V_146 ] ;
if ( V_147 == V_140 ) {
F_42 ( V_100
L_9
L_10 , V_25 ) ;
return - V_155 ;
}
if ( F_103 ( V_104 , V_105 ) )
F_104 ( V_104 ) ;
F_101 ( V_23 ) ;
return 0 ;
}
static void F_105 ( struct V_22 * V_23 )
{
T_2 V_104 = F_96 ( V_23 -> V_25 ) ;
F_100 ( V_23 ) ;
F_106 ( V_104 , V_105 ) ;
F_107 ( V_104 ) ;
}
static int F_108 ( struct V_22 * V_23 , unsigned int type )
{
unsigned int V_25 = V_23 -> V_25 ;
int V_106 ;
char V_107 [ 16 ] ;
T_2 V_104 = F_96 ( V_25 ) ;
T_2 V_147 = V_139 [ V_25 - V_146 ] ;
T_2 V_148 = F_125 ( V_147 ) ;
T_2 V_72 = F_126 ( V_147 ) ;
if ( V_147 == V_140 )
return - V_155 ;
if ( type == V_108 ) {
if ( F_109 ( V_104 , V_105 ) )
return 0 ;
type = V_109 | V_110 ;
}
if ( type & ( V_109 | V_110 |
V_111 | V_112 ) ) {
snprintf ( V_107 , 16 , L_8 , V_25 ) ;
V_106 = F_110 ( V_104 , V_107 ) ;
if ( V_106 )
return V_106 ;
if ( F_103 ( V_104 , V_105 ) )
F_104 ( V_104 ) ;
} else {
F_106 ( V_104 , V_105 ) ;
return 0 ;
}
if ( ( type & ( V_110 | V_112 ) ) )
V_142 [ V_72 ] -> V_150 = V_148 ;
else
V_142 [ V_72 ] -> V_151 = V_148 ;
if ( ( type & ( V_109 | V_110 ) )
== ( V_109 | V_110 ) ) {
if ( F_128 ( V_104 ) )
V_142 [ V_72 ] -> V_150 = V_148 ;
else
V_142 [ V_72 ] -> V_151 = V_148 ;
}
if ( type & ( V_109 | V_110 ) ) {
V_142 [ V_72 ] -> V_156 = V_148 ;
F_92 ( V_25 , V_113 ) ;
} else {
V_142 [ V_72 ] -> V_157 = V_148 ;
F_92 ( V_25 , V_103 ) ;
}
return 0 ;
}
static int F_116 ( struct V_22 * V_23 , unsigned int V_71 )
{
T_2 V_158 ;
T_2 V_147 = V_139 [ V_23 -> V_25 - V_146 ] ;
T_2 V_72 = F_126 ( V_147 ) ;
switch ( V_72 ) {
case 0 :
V_158 = V_159 ;
break;
case 2 :
V_158 = V_160 ;
break;
case 3 :
V_158 = V_161 ;
break;
case 1 :
V_158 = V_162 ;
break;
#ifdef F_11
case 4 :
V_158 = V_163 ;
break;
case 5 :
V_158 = V_164 ;
break;
#endif
default:
return - V_165 ;
}
F_54 ( V_158 , V_71 ) ;
return 0 ;
}
void F_121 ( unsigned int V_115 ,
struct V_58 * V_59 )
{
T_2 V_72 , V_147 ;
T_2 V_152 , V_25 ;
T_2 V_166 ;
int V_167 = 0 ;
struct V_168 * V_169 = F_129 ( V_59 ) ;
if ( V_169 -> V_170 ) {
V_169 -> V_170 ( & V_59 -> V_22 ) ;
} else {
V_169 -> V_171 ( & V_59 -> V_22 ) ;
if ( V_169 -> V_172 )
V_169 -> V_172 ( & V_59 -> V_22 ) ;
}
switch ( V_115 ) {
case V_159 :
V_72 = 0 ;
break;
case V_160 :
V_72 = 2 ;
break;
case V_161 :
V_72 = 3 ;
break;
case V_162 :
V_72 = 1 ;
break;
#ifdef F_11
case V_163 :
V_72 = 4 ;
break;
case V_164 :
V_72 = 5 ;
break;
#endif
default:
return;
}
V_147 = V_72 * V_144 ;
V_152 = V_142 [ V_72 ] -> V_152 ;
V_166 = V_142 [ V_72 ] -> V_156 & V_152 ;
while ( V_152 ) {
if ( V_152 & 1 ) {
V_25 = V_145 [ V_147 ] + V_146 ;
if ( V_166 & F_125 ( V_147 ) ) {
V_167 = 1 ;
V_169 -> V_173 ( & V_59 -> V_22 ) ;
}
F_61 ( V_25 ) ;
}
V_147 ++ ;
V_152 >>= 1 ;
}
if ( ! V_167 )
V_169 -> V_173 ( & V_59 -> V_22 ) ;
}
void T_7 F_130 ( void )
{
F_131 ( V_174 ) ;
F_132 ( V_175 ) ;
F_133 ( V_176 ) ;
F_134 ( V_177 ) ;
F_135 ( V_178 ) ;
F_136 ( V_179 ) ;
F_137 ( V_180 ) ;
F_138 ( V_181 ) ;
F_139 ( V_182 ) ;
F_140 ( V_183 ) ;
F_141 ( V_184 ) ;
F_142 ( V_185 ) ;
F_143 ( V_186 ) ;
F_144 () ;
}
int T_1 F_145 ( void )
{
int V_25 ;
unsigned long V_187 = 0 ;
#ifndef F_11
#ifdef F_12
F_146 ( V_188 ) ;
F_147 ( V_188 ) ;
# ifdef F_148
F_149 ( V_188 ) ;
# endif
# if F_3 ( V_29 ) || F_3 ( V_30 )
F_150 ( V_188 ) ;
F_151 ( V_188 ) ;
# endif
#else
F_14 ( V_188 ) ;
#endif
#else
F_38 ( V_189 ) ;
#endif
F_152 () ;
#if V_190
# ifdef F_153
V_142 [ 0 ] -> V_143 = V_191 ;
V_142 [ 1 ] -> V_143 = V_192 ;
V_142 [ 2 ] -> V_143 = V_193 ;
V_142 [ 3 ] -> V_143 = V_194 ;
# ifdef F_11
V_142 [ 4 ] -> V_143 = V_195 ;
V_142 [ 5 ] -> V_143 = V_196 ;
# endif
# endif
F_124 () ;
#endif
for ( V_25 = 0 ; V_25 <= V_146 ; V_25 ++ ) {
if ( V_25 <= V_197 )
F_154 ( V_25 , & V_198 ) ;
else
F_154 ( V_25 , & V_199 ) ;
switch ( V_25 ) {
#ifndef F_11
#if V_190
case V_159 :
case V_162 :
case V_160 :
case V_161 :
#elif F_3 ( F_84 )
case V_119 :
case V_116 :
#elif F_3 ( V_121 )
case V_122 :
#elif F_3 ( V_15 ) || F_3 ( V_14 )
case V_124 :
case V_125 :
case V_126 :
#elif F_3 ( V_127 )
case V_128 :
case V_129 :
case V_131 :
#elif F_3 ( V_123 )
case V_124 :
#endif
F_155 ( V_25 , F_121 ) ;
break;
#if F_3 ( V_200 ) || F_3 ( V_201 )
case V_93 :
F_155 ( V_25 ,
F_89 ) ;
break;
#endif
#if F_3 ( V_29 ) || F_3 ( V_30 )
case V_202 :
case V_203 :
F_156 ( V_25 , V_204 ) ;
break;
#endif
#endif
#ifdef F_157
case V_197 :
# ifdef V_29
F_156 ( V_25 , V_204 ) ;
# else
F_156 ( V_25 , V_205 ) ;
# endif
break;
#endif
#ifdef F_158
case V_206 :
F_156 ( V_25 , V_205 ) ;
break;
#endif
default:
#ifdef F_62
F_156 ( V_25 , V_103 ) ;
#else
F_156 ( V_25 , V_205 ) ;
#endif
break;
}
}
F_159 () ;
#ifndef F_11
#if ( F_3 ( V_200 ) || F_3 ( V_201 ) ) && ! F_3 ( F_11 )
for ( V_25 = V_90 ; V_25 <= V_99 ; V_25 ++ )
F_160 ( V_25 , & V_207 ,
V_103 ) ;
#endif
for ( V_25 = V_208 ;
V_25 < ( V_208 + V_209 ) ; V_25 ++ )
F_160 ( V_25 , & V_210 ,
V_103 ) ;
#else
for ( V_25 = F_161 ( 0 ) ; V_25 <= V_146 ; V_25 ++ ) {
if ( V_25 < V_211 ) {
F_154 ( V_25 , & V_212 ) ;
F_162 ( V_25 , F_45 , 0 , NULL ) ;
} else if ( V_25 >= F_161 ( 21 ) && V_25 <= F_161 ( 26 ) ) {
F_154 ( V_25 , & V_212 ) ;
F_155 ( V_25 , F_121 ) ;
} else if ( V_25 >= F_161 ( 34 ) && V_25 <= F_161 ( 37 ) ) {
F_154 ( V_25 , & V_212 ) ;
F_156 ( V_25 , V_204 ) ;
} else {
F_160 ( V_25 , & V_212 ,
V_213 ) ;
F_163 ( V_25 , F_20 ) ;
}
}
for ( V_25 = V_208 ;
V_25 < ( V_208 + V_209 ) ; V_25 ++ )
F_160 ( V_25 , & V_210 ,
V_103 ) ;
#endif
F_164 ( 0 ) ;
F_144 () ;
V_187 = F_165 () ;
F_144 () ;
F_166 ( V_187 ) ;
F_144 () ;
F_42 ( V_214 L_11 ) ;
#ifndef F_11
F_167 () ;
F_1 () ;
V_24 |= V_215 |
V_216 | V_217 | V_218 | V_219 |
V_220 | V_221 | V_222 | V_223 | V_224 ;
F_168 ( V_24 ) ;
#ifdef F_169
F_170 ( V_225 ) ;
# ifdef F_171
if ( V_226 )
F_172 ( F_173 ( 10 ) | F_173 ( 11 ) ) ;
else
F_172 ( V_225 ) ;
# endif
# ifdef F_174
F_175 ( V_225 ) ;
# endif
#else
F_176 ( V_225 ) ;
#endif
#else
V_24 |= V_215 |
V_216 | V_217 | V_218 | V_219 |
V_220 | V_221 | V_222 | V_223 | V_224 ;
F_177 ( V_227 | V_228 | V_229 ) ;
F_30 ( F_13 ( V_38 ) ) ;
F_25 ( F_13 ( V_38 ) ) ;
F_21 ( 0 , V_42 , V_43 ) ;
F_37 ( 100 ) ;
F_38 ( V_44 ) ;
F_21 ( 0 , V_42 , V_45 | V_46 ) ;
F_35 () ;
F_178 ( & V_230 ) ;
#endif
return 0 ;
}
static int F_179 ( int V_231 )
{
#ifndef F_11
struct V_232 * V_1 = V_6 [ V_231 - V_4 ] . V_8 ;
struct V_232 * V_233 = V_6 [ V_231 - V_4 ] . V_7 ;
unsigned long V_234 [ 3 ] ;
#endif
if ( F_180 ( V_231 == V_235 ) )
return V_197 ;
#ifndef F_11
#ifdef F_181
V_234 [ 0 ] = F_15 () & F_182 () ;
#else
if ( F_183 () ) {
# ifdef F_184
V_234 [ 0 ] = F_185 () & F_186 () ;
V_234 [ 1 ] = F_187 () & F_188 () ;
# endif
} else {
V_234 [ 0 ] = F_189 () & F_190 () ;
V_234 [ 1 ] = F_191 () & F_192 () ;
}
#endif
#ifdef F_193
V_234 [ 2 ] = F_194 () & F_195 () ;
#endif
for (; ; V_1 ++ ) {
if ( V_1 >= V_233 )
return - 1 ;
#ifdef F_181
if ( V_234 [ 0 ] & V_1 -> V_21 )
#else
if ( V_234 [ ( V_1 -> V_20 - V_4 ) / 32 ] & V_1 -> V_21 )
#endif
return V_1 -> V_20 ;
}
#else
return F_161 ( F_41 ( 0 , V_32 ) ) ;
#endif
}
void F_196 ( int V_231 , struct V_82 * V_236 )
{
int V_25 = F_179 ( V_231 ) ;
if ( V_25 == - 1 )
return;
F_197 ( V_25 , V_236 ) ;
}
int F_198 ( unsigned V_25 )
{
int V_237 , V_238 ;
if ( V_25 <= V_197 )
return V_25 ;
for ( V_237 = 0 ; V_237 < V_10 ; V_237 ++ ) {
struct V_232 * V_1 = V_9 + V_237 ;
if ( V_1 -> V_20 == V_25 ) {
for ( V_238 = 0 ; V_238 <= V_3 - V_4 ; V_238 ++ ) {
if ( V_6 [ V_238 ] . V_8 <= V_1 &&
V_6 [ V_238 ] . V_7 > V_1 )
return V_4 + V_238 ;
}
}
}
return V_239 ;
}
T_8 int F_199 ( int V_231 , struct V_82 * V_83 )
{
struct V_240 * V_241 = F_200 () ;
struct V_242 * V_243 = V_244 ;
struct V_232 * V_233 = V_6 [ V_231 - V_4 ] . V_7 ;
struct V_232 * V_1 = V_6 [ V_231 - V_4 ] . V_8 ;
int V_25 , V_245 = 0 ;
V_25 = F_179 ( V_231 ) ;
if ( V_25 == - 1 )
return 0 ;
if ( V_25 == V_246 ) {
#if ! F_3 ( V_247 ) || F_3 ( F_158 )
F_201 ( 1 ) ;
#endif
F_202 ( V_248 ) . V_249 = V_83 -> V_249 ;
F_202 ( V_248 ) . V_250 = V_83 -> V_250 ;
if ( V_243 != V_251 )
F_202 ( V_248 ) . V_249 &= ~ 0x10 ;
else
F_202 ( V_248 ) . V_249 |= 0x10 ;
}
if ( V_243 == V_251 ) {
V_245 = F_103 ( V_252 , & V_241 -> V_98 ) ;
F_203 () ;
}
F_63 ( V_25 ) ;
F_64 ( V_25 , V_83 ) ;
F_65 ( V_25 ) ;
if ( F_204 ( V_83 ) &&
! F_205 () &&
( V_253 -> V_254 & V_255 ) != 0 ) {
V_253 -> V_254 &= ~ V_255 ;
F_206 ( V_256 , V_83 ) ;
}
if ( V_243 == V_251 ) {
F_207 ( V_257 ) ;
if ( ! V_245 ) {
F_106 ( V_252 , & V_241 -> V_98 ) ;
return ! F_109 ( V_258 , & V_241 -> V_98 ) ;
}
}
return 0 ;
}
