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
static int F_125 ( struct V_22 * V_23 , unsigned int V_35 )
{
return F_126 ( F_105 ( V_23 -> V_25 ) , V_35 ) ;
}
static void F_127 ( unsigned int V_25 )
{
unsigned int V_126 , V_33 ;
V_126 = F_105 ( V_25 ) ;
V_33 = F_128 ( V_126 ) & F_129 ( V_126 ) ;
while ( V_33 ) {
if ( V_33 & 1 )
F_70 ( V_25 ) ;
V_25 ++ ;
V_33 >>= 1 ;
}
}
void F_130 ( unsigned int V_127 ,
struct V_80 * V_81 )
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
inline unsigned int F_132 ( T_2 V_36 , T_4 V_145 )
{
unsigned int V_146 ;
#ifndef F_133
if ( V_36 < 2 ) {
V_146 = V_147 + V_145 * 16 ;
} else {
V_146 = V_148 + V_145 * 16 ;
}
#else
V_146 = V_147 + V_36 * 16 + V_145 * 16 ;
#endif
return V_146 ;
}
void F_134 ( void )
{
T_6 V_36 , V_37 , V_146 , V_149 ;
T_2 V_150 ;
T_4 V_145 ;
memset ( V_151 , V_152 , sizeof( V_151 ) ) ;
for ( V_36 = 0 ; V_36 < V_153 ; V_36 ++ ) {
V_150 = V_154 [ V_36 ] -> V_155 ;
for ( V_37 = 0 ; V_37 < V_156 ; V_37 ++ ) {
V_145 = ( V_150 >> ( ( V_37 / 8 ) * 8 ) ) & 0xFF ;
V_146 = F_132 ( V_36 , V_145 ) ;
V_146 += ( V_37 % 8 ) + ( ( V_37 / 8 ) & 1 ? 8 : 0 ) ;
V_149 = V_37 + V_36 * V_156 ;
V_157 [ V_149 ] = V_146 - V_60 ;
V_151 [ V_146 - V_60 ] = V_149 ;
}
}
}
static void F_103 ( struct V_22 * V_23 )
{
T_2 V_158 = V_151 [ V_23 -> V_25 - V_60 ] ;
T_2 V_159 = F_135 ( V_158 ) ;
T_2 V_36 = F_136 ( V_158 ) ;
if ( F_137 ( V_23 ) == V_160 ) {
if ( V_154 [ V_36 ] -> V_161 & V_159 )
V_154 [ V_36 ] -> V_162 = V_159 ;
else
V_154 [ V_36 ] -> V_161 = V_159 ;
}
V_154 [ V_36 ] -> V_163 = V_159 ;
}
static void F_106 ( struct V_22 * V_23 )
{
T_2 V_158 = V_151 [ V_23 -> V_25 - V_60 ] ;
T_2 V_159 = F_135 ( V_158 ) ;
T_2 V_36 = F_136 ( V_158 ) ;
if ( F_137 ( V_23 ) == V_160 ) {
if ( V_154 [ V_36 ] -> V_161 & V_159 )
V_154 [ V_36 ] -> V_162 = V_159 ;
else
V_154 [ V_36 ] -> V_161 = V_159 ;
}
V_154 [ V_36 ] -> V_163 = V_159 ;
V_154 [ V_36 ] -> V_164 = V_159 ;
}
static void F_109 ( struct V_22 * V_23 )
{
T_2 V_158 = V_151 [ V_23 -> V_25 - V_60 ] ;
V_154 [ F_136 ( V_158 ) ] -> V_164 = F_135 ( V_158 ) ;
}
static void F_110 ( struct V_22 * V_23 )
{
T_2 V_158 = V_151 [ V_23 -> V_25 - V_60 ] ;
T_2 V_159 = F_135 ( V_158 ) ;
T_2 V_36 = F_136 ( V_158 ) ;
V_154 [ V_36 ] -> V_165 = V_159 ;
}
static unsigned int F_111 ( struct V_22 * V_23 )
{
unsigned int V_25 = V_23 -> V_25 ;
T_2 V_116 = F_105 ( V_25 ) ;
T_2 V_158 = V_151 [ V_25 - V_60 ] ;
if ( V_158 == V_152 ) {
F_54 ( V_112
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
T_2 V_158 = V_151 [ V_25 - V_60 ] ;
T_2 V_159 = F_135 ( V_158 ) ;
T_2 V_36 = F_136 ( V_158 ) ;
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
V_154 [ V_36 ] -> V_161 = V_159 ;
else
V_154 [ V_36 ] -> V_162 = V_159 ;
if ( ( type & ( V_121 | V_122 ) )
== ( V_121 | V_122 ) ) {
if ( F_138 ( V_116 ) )
V_154 [ V_36 ] -> V_161 = V_159 ;
else
V_154 [ V_36 ] -> V_162 = V_159 ;
}
if ( type & ( V_121 | V_122 ) ) {
V_154 [ V_36 ] -> V_167 = V_159 ;
F_101 ( V_25 , V_125 ) ;
} else {
V_154 [ V_36 ] -> V_168 = V_159 ;
F_101 ( V_25 , V_115 ) ;
}
return 0 ;
}
static int F_125 ( struct V_22 * V_23 , unsigned int V_35 )
{
T_2 V_169 ;
T_2 V_158 = V_151 [ V_23 -> V_25 - V_60 ] ;
T_2 V_36 = F_136 ( V_158 ) ;
switch ( V_36 ) {
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
#ifndef F_139
F_23 ( V_169 , V_35 ) ;
#endif
return 0 ;
}
void F_140 ( void )
{
T_2 V_36 ;
for ( V_36 = 0 ; V_36 < V_153 ; V_36 ++ ) {
V_177 [ V_36 ] . V_165 = V_154 [ V_36 ] -> V_165 ;
V_177 [ V_36 ] . V_155 = V_154 [ V_36 ] -> V_155 ;
V_177 [ V_36 ] . V_167 = V_154 [ V_36 ] -> V_167 ;
V_177 [ V_36 ] . V_161 = V_154 [ V_36 ] -> V_161 ;
}
}
void F_141 ( void )
{
T_2 V_36 ;
for ( V_36 = 0 ; V_36 < V_153 ; V_36 ++ ) {
V_154 [ V_36 ] -> V_165 = V_177 [ V_36 ] . V_165 ;
V_154 [ V_36 ] -> V_155 = V_177 [ V_36 ] . V_155 ;
V_154 [ V_36 ] -> V_167 = V_177 [ V_36 ] . V_167 ;
V_154 [ V_36 ] -> V_161 = V_177 [ V_36 ] . V_161 ;
}
}
static int F_142 ( void )
{
T_2 V_36 ;
for ( V_36 = 0 ; V_36 < V_153 ; V_36 ++ )
V_178 [ V_36 ] = F_36 ( V_36 + F_12 ( V_170 ) ) ;
return 0 ;
}
static void F_143 ( void )
{
T_2 V_36 ;
F_31 ( 0 , V_64 , V_65 ) ;
F_49 ( 100 ) ;
F_50 ( V_66 ) ;
F_31 ( 0 , V_64 , V_67 | V_68 ) ;
for ( V_36 = 0 ; V_36 < V_153 ; V_36 ++ )
F_37 ( V_36 + F_12 ( V_170 ) , V_178 [ V_36 ] ) ;
}
void F_130 ( unsigned int V_127 ,
struct V_80 * V_81 )
{
T_2 V_36 , V_158 ;
T_2 V_163 , V_25 ;
T_2 V_179 ;
int V_180 = 0 ;
struct V_181 * V_182 = F_144 ( V_81 ) ;
if ( V_182 -> V_183 ) {
V_182 -> V_183 ( & V_81 -> V_22 ) ;
} else {
V_182 -> V_184 ( & V_81 -> V_22 ) ;
if ( V_182 -> V_185 )
V_182 -> V_185 ( & V_81 -> V_22 ) ;
}
switch ( V_127 ) {
case V_170 :
V_36 = 0 ;
break;
case V_171 :
V_36 = 2 ;
break;
case V_172 :
V_36 = 3 ;
break;
case V_173 :
V_36 = 1 ;
break;
#ifdef F_133
case V_174 :
V_36 = 4 ;
break;
case V_175 :
V_36 = 5 ;
break;
#endif
default:
return;
}
V_158 = V_36 * V_156 ;
V_163 = V_154 [ V_36 ] -> V_163 ;
V_179 = V_154 [ V_36 ] -> V_167 & V_163 ;
while ( V_163 ) {
if ( V_163 & 1 ) {
V_25 = V_157 [ V_158 ] + V_60 ;
if ( V_179 & F_135 ( V_158 ) ) {
V_180 = 1 ;
V_182 -> V_186 ( & V_81 -> V_22 ) ;
}
F_70 ( V_25 ) ;
}
V_158 ++ ;
V_163 >>= 1 ;
}
if ( ! V_180 )
V_182 -> V_186 ( & V_81 -> V_22 ) ;
}
void T_7 F_145 ( void )
{
F_146 ( V_187 ) ;
F_147 ( V_188 ) ;
F_148 ( V_189 ) ;
F_149 ( V_190 ) ;
F_150 ( V_191 ) ;
F_151 ( V_192 ) ;
F_152 ( V_193 ) ;
F_153 ( V_194 ) ;
F_154 ( V_195 ) ;
F_155 ( V_196 ) ;
F_156 ( V_197 ) ;
F_157 ( V_198 ) ;
F_158 ( V_199 ) ;
F_159 () ;
}
int T_1 F_160 ( void )
{
int V_25 ;
unsigned long V_200 = 0 ;
#ifdef F_11
F_161 ( V_201 ) ;
F_162 ( V_201 ) ;
# ifdef F_163
F_164 ( V_201 ) ;
# endif
# if F_3 ( V_29 ) || F_3 ( V_30 )
F_165 ( V_201 ) ;
F_166 ( V_201 ) ;
# endif
#else
F_13 ( V_201 ) ;
#endif
F_167 () ;
#if V_202
# ifdef F_168
V_154 [ 0 ] -> V_155 = V_203 ;
V_154 [ 1 ] -> V_155 = V_204 ;
V_154 [ 2 ] -> V_155 = V_205 ;
V_154 [ 3 ] -> V_155 = V_206 ;
# endif
F_134 () ;
#endif
for ( V_25 = 0 ; V_25 <= V_60 ; V_25 ++ ) {
if ( V_25 <= V_207 )
F_169 ( V_25 , & V_208 ) ;
else
F_169 ( V_25 , & V_209 ) ;
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
F_170 ( V_25 , F_130 ) ;
break;
#if F_3 ( V_210 ) || F_3 ( V_211 )
case V_106 :
F_170 ( V_25 ,
F_98 ) ;
break;
#endif
#if F_3 ( V_29 ) || F_3 ( V_30 )
case V_212 :
case V_213 :
F_171 ( V_25 , V_214 ) ;
break;
#endif
#ifdef F_172
case V_207 :
# ifdef V_29
F_171 ( V_25 , V_214 ) ;
# else
F_171 ( V_25 , V_215 ) ;
# endif
break;
#endif
#ifdef F_173
case V_216 :
F_171 ( V_25 , V_215 ) ;
break;
#endif
default:
#ifdef F_71
F_171 ( V_25 , V_115 ) ;
#else
F_171 ( V_25 , V_215 ) ;
#endif
break;
}
}
F_174 () ;
#if ( F_3 ( V_210 ) || F_3 ( V_211 ) )
for ( V_25 = V_103 ; V_25 <= V_111 ; V_25 ++ )
F_175 ( V_25 , & V_217 ,
V_115 ) ;
#endif
for ( V_25 = V_218 ;
V_25 < ( V_218 + V_219 ) ; V_25 ++ )
F_175 ( V_25 , & V_220 ,
V_115 ) ;
F_176 ( 0 ) ;
F_159 () ;
V_200 = F_177 () ;
F_159 () ;
F_178 ( V_200 ) ;
F_159 () ;
F_54 ( V_221 L_15 ) ;
F_179 () ;
F_1 () ;
V_24 |= V_222 |
V_223 | V_224 | V_225 | V_226 |
V_227 | V_228 | V_229 | V_230 | V_231 ;
#ifdef F_180
F_181 ( V_232 ) ;
# ifdef F_182
if ( V_233 )
F_183 ( F_184 ( 10 ) | F_184 ( 11 ) ) ;
else
F_183 ( V_232 ) ;
# endif
# ifdef F_185
F_186 ( V_232 ) ;
# endif
#else
F_187 ( V_232 ) ;
#endif
return 0 ;
}
static int F_188 ( int V_234 )
{
struct V_235 * V_1 = V_6 [ V_234 - V_4 ] . V_8 ;
struct V_235 * V_236 = V_6 [ V_234 - V_4 ] . V_7 ;
unsigned long V_237 [ 3 ] ;
if ( F_189 ( V_234 == V_238 ) )
return V_207 ;
#ifdef F_190
V_237 [ 0 ] = F_14 () & F_191 () ;
#else
if ( F_192 () ) {
# ifdef F_193
V_237 [ 0 ] = F_194 () & F_195 () ;
V_237 [ 1 ] = F_196 () & F_197 () ;
# endif
} else {
V_237 [ 0 ] = F_198 () & F_199 () ;
V_237 [ 1 ] = F_200 () & F_201 () ;
}
#endif
#ifdef F_202
V_237 [ 2 ] = F_203 () & F_204 () ;
#endif
for (; ; V_1 ++ ) {
if ( V_1 >= V_236 )
return - 1 ;
#ifdef F_190
if ( V_237 [ 0 ] & V_1 -> V_21 )
#else
if ( V_237 [ ( V_1 -> V_20 - V_4 ) / 32 ] & V_1 -> V_21 )
#endif
return V_1 -> V_20 ;
}
}
int T_1 F_160 ( void )
{
int V_25 ;
unsigned long V_200 = 0 ;
F_50 ( V_239 ) ;
F_167 () ;
#if V_202
# ifdef F_168
V_154 [ 0 ] -> V_155 = V_203 ;
V_154 [ 1 ] -> V_155 = V_204 ;
V_154 [ 2 ] -> V_155 = V_205 ;
V_154 [ 3 ] -> V_155 = V_206 ;
V_154 [ 4 ] -> V_155 = V_240 ;
V_154 [ 5 ] -> V_155 = V_241 ;
# endif
F_134 () ;
#endif
for ( V_25 = 0 ; V_25 <= V_60 ; V_25 ++ ) {
if ( V_25 <= V_207 ) {
F_175 ( V_25 , & V_208 ,
V_215 ) ;
#if F_3 ( F_172 ) && F_3 ( V_29 )
if ( V_25 == V_207 )
F_171 ( V_25 , V_214 ) ;
#endif
} else if ( V_25 >= F_45 ( 21 ) && V_25 <= F_45 ( 26 ) ) {
F_169 ( V_25 , & V_242 ) ;
F_170 ( V_25 , F_130 ) ;
} else if ( V_25 >= F_45 ( 34 ) && V_25 <= F_45 ( 37 ) ) {
F_175 ( V_25 , & V_242 ,
V_214 ) ;
} else {
F_169 ( V_25 , & V_242 ) ;
if ( V_25 == V_243 )
F_171 ( V_25 , F_57 ) ;
else if ( V_25 >= V_91 && V_25 < V_244 )
F_171 ( V_25 , F_61 ) ;
else
F_171 ( V_25 , F_60 ) ;
F_205 ( V_25 , F_30 ) ;
}
}
for ( V_25 = V_218 ;
V_25 < ( V_218 + V_219 ) ; V_25 ++ )
F_175 ( V_25 , & V_220 ,
V_115 ) ;
F_176 ( 0 ) ;
F_159 () ;
V_200 = F_177 () ;
F_159 () ;
F_178 ( V_200 ) ;
F_159 () ;
F_54 ( V_221 L_15 ) ;
F_44 ( V_245 , V_57 ) ;
F_44 ( V_245 , V_57 ) ;
V_24 |= V_222 |
V_223 | V_224 | V_225 | V_226 |
V_227 | V_228 | V_229 | V_230 | V_231 ;
F_206 ( V_246 | V_247 | V_248 ) ;
F_40 ( F_12 ( V_53 ) ) ;
F_35 ( F_12 ( V_53 ) ) ;
F_31 ( 0 , V_64 , V_65 ) ;
F_49 ( 100 ) ;
F_50 ( V_66 ) ;
F_31 ( 0 , V_64 , V_67 | V_68 ) ;
F_31 ( 1 , V_64 , V_67 | V_68 ) ;
F_47 () ;
#ifdef F_207
F_208 ( & V_249 ) ;
#endif
return 0 ;
}
static int F_188 ( int V_234 )
{
if ( F_189 ( V_234 == V_238 ) )
return V_207 ;
return F_45 ( F_53 ( 0 , V_47 ) ) ;
}
void F_209 ( int V_234 , struct V_89 * V_90 )
{
int V_25 = F_188 ( V_234 ) ;
if ( V_25 == - 1 )
return;
F_210 ( V_25 , V_90 ) ;
}
int F_211 ( unsigned V_25 )
{
int V_250 , V_251 ;
if ( V_25 <= V_207 )
return V_25 ;
#ifdef F_139
if ( V_25 >= F_45 ( 0 ) )
return V_252 ;
#else
for ( V_250 = 0 ; V_250 < V_10 ; V_250 ++ ) {
struct V_235 * V_1 = V_9 + V_250 ;
if ( V_1 -> V_20 == V_25 ) {
for ( V_251 = 0 ; V_251 <= V_3 - V_4 ; V_251 ++ ) {
if ( V_6 [ V_251 ] . V_8 <= V_1 &&
V_6 [ V_251 ] . V_7 > V_1 )
return V_4 + V_251 ;
}
}
}
#endif
return V_253 ;
}
T_8 int F_212 ( int V_234 , struct V_89 * V_96 )
{
struct V_254 * V_255 = F_213 () ;
struct V_256 * V_257 = V_258 ;
int V_25 , V_259 = 0 ;
V_25 = F_188 ( V_234 ) ;
if ( V_25 == - 1 )
return 0 ;
if ( V_25 == V_260 ) {
#if ! F_3 ( V_261 ) || F_3 ( F_173 )
F_214 ( 1 ) ;
#endif
F_215 ( V_262 ) . V_263 = V_96 -> V_263 ;
F_215 ( V_262 ) . V_264 = V_96 -> V_264 ;
if ( V_257 != V_265 )
F_215 ( V_262 ) . V_263 &= ~ 0x10 ;
else
F_215 ( V_262 ) . V_263 |= 0x10 ;
}
if ( V_257 == V_265 ) {
V_259 = F_112 ( V_266 , & V_255 -> V_110 ) ;
F_216 () ;
}
F_72 ( V_25 ) ;
F_73 ( V_25 , V_96 ) ;
F_74 ( V_25 ) ;
if ( F_217 ( V_96 ) &&
! F_218 () &&
( V_94 -> V_267 & V_268 ) != 0 ) {
V_94 -> V_267 &= ~ V_268 ;
F_219 ( V_269 , V_96 ) ;
}
if ( V_257 == V_265 ) {
F_220 ( V_270 ) ;
if ( ! V_259 ) {
F_115 ( V_266 , & V_255 -> V_110 ) ;
return ! F_118 ( V_271 , & V_255 -> V_110 ) ;
}
}
return 0 ;
}
