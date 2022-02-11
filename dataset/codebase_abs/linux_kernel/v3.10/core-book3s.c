static inline unsigned long F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_2 ( struct V_1 * V_2 , T_1 * V_3 ) { }
static inline T_2 F_3 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_4 = 0 ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
return 1 ;
}
static inline void F_7 ( struct V_5 * V_6 ) {}
static inline void F_8 ( struct V_5 * V_6 ) {}
void F_9 ( void ) {}
static inline void F_10 ( struct V_7 * V_8 ) {}
static bool F_11 ( struct V_1 * V_2 )
{
return ! ! V_2 -> V_4 ;
}
static inline unsigned long F_1 ( struct V_1 * V_2 )
{
unsigned long V_9 = V_2 -> V_10 ;
if ( ( V_11 -> V_12 & V_13 ) && ( V_9 & V_14 ) ) {
unsigned long V_15 = ( V_9 & V_16 ) >> V_17 ;
if ( V_15 > 1 )
return 4 * ( V_15 - 1 ) ;
}
return 0 ;
}
static inline void F_2 ( struct V_1 * V_2 , T_1 * V_3 )
{
unsigned long V_9 = V_2 -> V_10 ;
bool V_18 ;
if ( V_11 -> V_12 & V_19 )
V_18 = V_2 -> V_20 & V_21 ;
else {
unsigned long V_22 ;
if ( V_11 -> V_12 & V_23 )
V_22 = V_24 ;
else if ( V_11 -> V_12 & V_25 )
V_22 = V_26 ;
else
V_22 = V_27 ;
V_18 = V_9 & V_22 ;
}
if ( ! ( V_9 & V_14 ) || V_18 )
* V_3 = F_12 ( V_28 ) ;
}
static bool F_13 ( struct V_1 * V_2 )
{
unsigned long V_29 = V_30 ;
if ( V_11 -> V_12 & V_19 )
return ! ! ( V_2 -> V_20 & V_31 ) ;
if ( V_11 -> V_12 & V_25 )
V_29 = V_32 ;
return ! ! ( V_2 -> V_10 & V_29 ) ;
}
static bool F_14 ( struct V_1 * V_2 )
{
unsigned long V_33 = V_34 ;
if ( V_11 -> V_12 & V_19 )
return ! ! ( V_2 -> V_20 & V_35 ) ;
if ( V_11 -> V_12 & V_25 )
V_33 = V_36 ;
return ! ! ( V_2 -> V_10 & V_33 ) ;
}
static inline T_2 F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 & V_38 )
return V_39 ;
if ( ( V_2 -> V_37 & V_40 ) && V_41 != V_42 )
return V_43 ;
return V_44 ;
}
static inline T_2 F_3 ( struct V_1 * V_2 )
{
bool V_45 = F_11 ( V_2 ) ;
if ( ! V_45 )
return F_15 ( V_2 ) ;
if ( V_11 -> V_12 & V_46 ) {
unsigned long V_47 = F_12 ( V_48 ) ;
if ( V_47 >= V_49 )
return V_44 ;
return V_39 ;
}
if ( F_14 ( V_2 ) )
return V_39 ;
if ( F_13 ( V_2 ) && ( V_41 != V_42 ) )
return V_43 ;
return V_44 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
unsigned long V_9 = F_12 ( V_50 ) ;
int V_51 = V_9 & V_14 ;
int V_45 ;
V_2 -> V_10 = V_9 ;
if ( V_11 -> V_12 & V_19 )
V_2 -> V_20 = F_12 ( V_52 ) ;
if ( F_16 ( V_2 ) != 0xf00 )
V_45 = 0 ;
else if ( V_51 )
V_45 = 1 ;
else if ( ( V_11 -> V_12 & V_53 ) )
V_45 = 0 ;
else if ( ! ( V_11 -> V_12 & V_46 ) && F_14 ( V_2 ) )
V_45 = 0 ;
else
V_45 = 1 ;
V_2 -> V_4 = V_45 ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
return ! V_2 -> V_54 ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
unsigned long V_9 = V_2 -> V_10 ;
int V_51 = V_9 & V_14 ;
if ( V_51 ) {
if ( V_11 -> V_12 & V_19 )
return V_2 -> V_20 & V_55 ;
if ( V_11 -> V_12 & V_23 )
return V_9 & V_56 ;
}
return 1 ;
}
static void F_17 ( void )
{
asm volatile(PPC_CLRBHRB);
}
static void F_7 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & F_18 ( V_7 ) ;
if ( ! V_11 -> V_57 )
return;
if ( V_6 -> V_58 -> V_59 && V_8 -> V_60 != V_6 -> V_58 ) {
F_17 () ;
V_8 -> V_60 = V_6 -> V_58 ;
}
V_8 -> V_61 ++ ;
}
static void F_8 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & F_18 ( V_7 ) ;
if ( ! V_11 -> V_57 )
return;
V_8 -> V_61 -- ;
F_19 ( V_8 -> V_61 < 0 ) ;
if ( ! V_8 -> V_62 && ! V_8 -> V_61 ) {
V_8 -> V_60 = NULL ;
}
}
void F_9 ( void )
{
if ( V_11 -> V_57 )
F_17 () ;
}
static T_3 F_20 ( T_1 V_63 )
{
unsigned int V_64 ;
int V_65 ;
T_3 V_66 ;
if ( F_21 ( V_63 ) )
return F_22 ( ( unsigned int * ) V_63 ) ;
F_23 () ;
V_65 = F_24 ( V_64 , ( unsigned int V_67 * ) V_63 ) ;
if ( V_65 ) {
F_25 () ;
return 0 ;
}
F_25 () ;
V_66 = F_22 ( & V_64 ) ;
if ( ( ! V_66 ) || ( V_64 & V_68 ) )
return V_66 ;
return V_66 - ( unsigned long ) & V_64 + V_63 ;
}
void F_10 ( struct V_7 * V_8 )
{
T_1 V_69 ;
T_1 V_63 ;
int V_70 , V_71 , V_72 ;
V_70 = 0 ;
V_71 = 0 ;
while ( V_70 < V_11 -> V_57 ) {
V_69 = F_26 ( V_70 ++ ) ;
if ( ! V_69 )
break;
else {
V_63 = V_69 & V_73 ;
V_72 = V_69 & V_74 ;
if ( ! V_63 )
continue;
if ( V_69 & V_75 ) {
V_8 -> V_76 [ V_71 ] . V_77 = V_63 ;
V_8 -> V_76 [ V_71 ] . V_78 = V_72 ;
V_8 -> V_76 [ V_71 ] . V_79 = ~ V_72 ;
V_69 = F_26 ( V_70 ++ ) ;
V_63 = V_69 & V_73 ;
if ( V_69 & V_75 ) {
V_70 -- ;
V_63 = 0 ;
}
V_8 -> V_76 [ V_71 ] . V_80 = V_63 ;
} else {
V_8 -> V_76 [ V_71 ] . V_80 = V_63 ;
V_8 -> V_76 [ V_71 ] . V_77 =
F_20 ( V_63 ) ;
V_8 -> V_76 [ V_71 ] . V_78 = V_72 ;
V_8 -> V_76 [ V_71 ] . V_79 = ~ V_72 ;
}
V_71 ++ ;
}
}
V_8 -> V_81 . V_82 = V_71 ;
return;
}
void F_27 ( void )
{
}
static unsigned long F_28 ( int V_83 )
{
unsigned long V_69 ;
switch ( V_83 ) {
case 1 :
V_69 = F_12 ( V_84 ) ;
break;
case 2 :
V_69 = F_12 ( V_85 ) ;
break;
case 3 :
V_69 = F_12 ( V_86 ) ;
break;
case 4 :
V_69 = F_12 ( V_87 ) ;
break;
case 5 :
V_69 = F_12 ( V_88 ) ;
break;
case 6 :
V_69 = F_12 ( V_89 ) ;
break;
#ifdef F_29
case 7 :
V_69 = F_12 ( V_90 ) ;
break;
case 8 :
V_69 = F_12 ( V_91 ) ;
break;
#endif
default:
F_30 ( V_92 L_1 , V_83 ) ;
V_69 = 0 ;
}
return V_69 ;
}
static void F_31 ( int V_83 , unsigned long V_69 )
{
switch ( V_83 ) {
case 1 :
F_32 ( V_84 , V_69 ) ;
break;
case 2 :
F_32 ( V_85 , V_69 ) ;
break;
case 3 :
F_32 ( V_86 , V_69 ) ;
break;
case 4 :
F_32 ( V_87 , V_69 ) ;
break;
case 5 :
F_32 ( V_88 , V_69 ) ;
break;
case 6 :
F_32 ( V_89 , V_69 ) ;
break;
#ifdef F_29
case 7 :
F_32 ( V_90 , V_69 ) ;
break;
case 8 :
F_32 ( V_91 , V_69 ) ;
break;
#endif
default:
F_30 ( V_92 L_2 , V_83 ) ;
}
}
static int F_33 ( struct V_7 * V_8 ,
T_1 V_93 [] , unsigned int V_94 [] ,
int V_95 )
{
unsigned long V_96 , V_97 , V_98 ;
unsigned long V_99 [ V_100 ] , V_101 [ V_100 ] ;
int V_102 [ V_100 ] , V_103 [ V_100 ] ;
int V_104 , V_105 ;
unsigned long V_106 = V_11 -> V_107 ;
unsigned long V_108 = V_11 -> V_109 ;
if ( V_95 > V_11 -> V_110 )
return - 1 ;
for ( V_104 = 0 ; V_104 < V_95 ; ++ V_104 ) {
if ( ( V_94 [ V_104 ] & V_111 )
&& ! V_11 -> V_112 ( V_93 [ V_104 ] ) ) {
V_11 -> V_113 ( V_93 [ V_104 ] , V_94 [ V_104 ] ,
V_8 -> V_114 [ V_104 ] ) ;
V_93 [ V_104 ] = V_8 -> V_114 [ V_104 ] [ 0 ] ;
}
if ( V_11 -> V_115 ( V_93 [ V_104 ] , & V_8 -> V_116 [ V_104 ] [ 0 ] ,
& V_8 -> V_117 [ V_104 ] [ 0 ] ) )
return - 1 ;
}
V_97 = V_96 = 0 ;
for ( V_104 = 0 ; V_104 < V_95 ; ++ V_104 ) {
V_98 = ( V_97 | V_8 -> V_117 [ V_104 ] [ 0 ] ) +
( V_97 & V_8 -> V_117 [ V_104 ] [ 0 ] & V_106 ) ;
if ( ( ( ( V_98 + V_108 ) ^ V_97 ) & V_96 ) != 0 ||
( ( ( V_98 + V_108 ) ^ V_8 -> V_117 [ V_104 ] [ 0 ] ) &
V_8 -> V_116 [ V_104 ] [ 0 ] ) != 0 )
break;
V_97 = V_98 ;
V_96 |= V_8 -> V_116 [ V_104 ] [ 0 ] ;
}
if ( V_104 == V_95 )
return 0 ;
if ( ! V_11 -> V_113 )
return - 1 ;
for ( V_104 = 0 ; V_104 < V_95 ; ++ V_104 ) {
V_103 [ V_104 ] = 0 ;
V_102 [ V_104 ] = V_11 -> V_113 ( V_93 [ V_104 ] , V_94 [ V_104 ] ,
V_8 -> V_114 [ V_104 ] ) ;
for ( V_105 = 1 ; V_105 < V_102 [ V_104 ] ; ++ V_105 )
V_11 -> V_115 ( V_8 -> V_114 [ V_104 ] [ V_105 ] ,
& V_8 -> V_116 [ V_104 ] [ V_105 ] ,
& V_8 -> V_117 [ V_104 ] [ V_105 ] ) ;
}
V_104 = 0 ;
V_105 = - 1 ;
V_97 = V_96 = V_98 = 0 ;
while ( V_104 < V_95 ) {
if ( V_105 >= 0 ) {
V_97 = V_101 [ V_104 ] ;
V_96 = V_99 [ V_104 ] ;
V_105 = V_103 [ V_104 ] ;
}
while ( ++ V_105 < V_102 [ V_104 ] ) {
V_98 = ( V_97 | V_8 -> V_117 [ V_104 ] [ V_105 ] ) +
( V_97 & V_8 -> V_117 [ V_104 ] [ V_105 ] & V_106 ) ;
if ( ( ( ( V_98 + V_108 ) ^ V_97 ) & V_96 ) == 0 &&
( ( ( V_98 + V_108 ) ^ V_8 -> V_117 [ V_104 ] [ V_105 ] )
& V_8 -> V_116 [ V_104 ] [ V_105 ] ) == 0 )
break;
}
if ( V_105 >= V_102 [ V_104 ] ) {
if ( -- V_104 < 0 )
return - 1 ;
} else {
V_103 [ V_104 ] = V_105 ;
V_101 [ V_104 ] = V_97 ;
V_99 [ V_104 ] = V_96 ;
V_97 = V_98 ;
V_96 |= V_8 -> V_116 [ V_104 ] [ V_105 ] ;
++ V_104 ;
V_105 = - 1 ;
}
}
for ( V_104 = 0 ; V_104 < V_95 ; ++ V_104 )
V_93 [ V_104 ] = V_8 -> V_114 [ V_104 ] [ V_103 [ V_104 ] ] ;
return 0 ;
}
static int F_34 ( struct V_5 * * V_118 , unsigned int V_94 [] ,
int V_119 , int V_120 )
{
int V_121 = 0 , V_122 = 0 , V_123 = 0 ;
int V_104 , V_124 , V_125 ;
struct V_5 * V_6 ;
V_124 = V_119 + V_120 ;
if ( V_124 <= 1 )
return 0 ;
V_125 = 1 ;
for ( V_104 = 0 ; V_104 < V_124 ; ++ V_104 ) {
if ( V_94 [ V_104 ] & V_126 ) {
V_94 [ V_104 ] &= ~ V_111 ;
continue;
}
V_6 = V_118 [ V_104 ] ;
if ( V_125 ) {
V_121 = V_6 -> V_127 . V_128 ;
V_122 = V_6 -> V_127 . V_129 ;
V_123 = V_6 -> V_127 . V_130 ;
V_125 = 0 ;
} else if ( V_6 -> V_127 . V_128 != V_121 ||
V_6 -> V_127 . V_129 != V_122 ||
V_6 -> V_127 . V_130 != V_123 ) {
return - V_131 ;
}
}
if ( V_121 || V_122 || V_123 )
for ( V_104 = 0 ; V_104 < V_124 ; ++ V_104 )
if ( V_94 [ V_104 ] & V_126 )
V_94 [ V_104 ] |= V_111 ;
return 0 ;
}
static T_1 F_35 ( T_1 V_132 , T_1 V_69 )
{
T_1 V_133 = ( V_69 - V_132 ) & 0xfffffffful ;
if ( V_132 > V_69 && ( V_132 - V_69 ) < 256 )
V_133 = 0 ;
return V_133 ;
}
static void F_36 ( struct V_5 * V_6 )
{
T_4 V_69 , V_133 , V_132 ;
if ( V_6 -> V_134 . V_135 & V_136 )
return;
if ( ! V_6 -> V_134 . V_83 )
return;
do {
V_132 = F_37 ( & V_6 -> V_134 . V_137 ) ;
F_38 () ;
V_69 = F_28 ( V_6 -> V_134 . V_83 ) ;
V_133 = F_35 ( V_132 , V_69 ) ;
if ( ! V_133 )
return;
} while ( F_39 ( & V_6 -> V_134 . V_137 , V_132 , V_69 ) != V_132 );
F_40 ( V_133 , & V_6 -> V_138 ) ;
F_41 ( V_133 , & V_6 -> V_134 . V_139 ) ;
}
static int F_42 ( int V_140 )
{
return ( V_11 -> V_12 & V_141 )
&& ( V_140 == 5 || V_140 == 6 ) ;
}
static void F_43 ( struct V_7 * V_8 ,
unsigned long V_142 , unsigned long V_143 )
{
struct V_5 * V_6 ;
T_1 V_69 , V_132 , V_133 ;
int V_104 ;
for ( V_104 = 0 ; V_104 < V_8 -> V_144 ; ++ V_104 ) {
V_6 = V_8 -> V_145 [ V_104 ] ;
if ( ! V_6 -> V_134 . V_83 )
continue;
V_69 = ( V_6 -> V_134 . V_83 == 5 ) ? V_142 : V_143 ;
V_132 = F_37 ( & V_6 -> V_134 . V_137 ) ;
V_6 -> V_134 . V_83 = 0 ;
V_133 = F_35 ( V_132 , V_69 ) ;
if ( V_133 )
F_40 ( V_133 , & V_6 -> V_138 ) ;
}
}
static void F_44 ( struct V_7 * V_8 ,
unsigned long V_142 , unsigned long V_143 )
{
struct V_5 * V_6 ;
T_1 V_69 , V_132 ;
int V_104 ;
for ( V_104 = 0 ; V_104 < V_8 -> V_144 ; ++ V_104 ) {
V_6 = V_8 -> V_145 [ V_104 ] ;
V_6 -> V_134 . V_83 = V_8 -> V_146 [ V_104 ] ;
V_69 = ( V_6 -> V_134 . V_83 == 5 ) ? V_142 : V_143 ;
V_132 = F_37 ( & V_6 -> V_134 . V_137 ) ;
if ( F_35 ( V_132 , V_69 ) )
F_45 ( & V_6 -> V_134 . V_137 , V_69 ) ;
F_46 ( V_6 ) ;
}
}
static void F_47 ( struct V_7 * V_8 , unsigned long V_147 )
{
unsigned long V_142 , V_143 ;
if ( ! V_8 -> V_144 ) {
F_32 ( V_148 , V_147 ) ;
return;
}
asm volatile("mtspr %3,%2; mfspr %0,%4; mfspr %1,%5"
: "=&r" (pmc5), "=&r" (pmc6)
: "r" (mmcr0 & ~(MMCR0_PMC1CE | MMCR0_PMCjCE)),
"i" (SPRN_MMCR0),
"i" (SPRN_PMC5), "i" (SPRN_PMC6));
if ( V_147 & V_149 )
F_43 ( V_8 , V_142 , V_143 ) ;
else
F_44 ( V_8 , V_142 , V_143 ) ;
if ( V_147 & ( V_150 | V_151 ) )
F_32 ( V_148 , V_147 ) ;
}
static void F_48 ( struct V_152 * V_152 )
{
struct V_7 * V_8 ;
unsigned long V_12 ;
if ( ! V_11 )
return;
F_49 ( V_12 ) ;
V_8 = & F_18 ( V_7 ) ;
if ( ! V_8 -> V_62 ) {
V_8 -> V_62 = 1 ;
V_8 -> V_153 = 0 ;
if ( ! V_8 -> V_154 ) {
F_50 () ;
V_8 -> V_154 = 1 ;
}
if ( V_8 -> V_155 [ 2 ] & V_14 ) {
F_32 ( V_50 ,
V_8 -> V_155 [ 2 ] & ~ V_14 ) ;
F_51 () ;
}
F_47 ( V_8 , F_12 ( V_148 ) | V_149 ) ;
F_51 () ;
}
F_52 ( V_12 ) ;
}
static void F_53 ( struct V_152 * V_152 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
unsigned long V_12 ;
long V_104 ;
unsigned long V_69 ;
T_4 V_156 ;
unsigned int V_157 [ V_100 ] ;
int V_158 ;
int V_83 ;
if ( ! V_11 )
return;
F_49 ( V_12 ) ;
V_8 = & F_18 ( V_7 ) ;
if ( ! V_8 -> V_62 ) {
F_52 ( V_12 ) ;
return;
}
V_8 -> V_62 = 0 ;
if ( ! V_8 -> V_153 ) {
F_32 ( V_50 , V_8 -> V_155 [ 2 ] & ~ V_14 ) ;
F_32 ( V_159 , V_8 -> V_155 [ 1 ] ) ;
if ( V_8 -> V_160 == 0 )
F_54 ( 0 ) ;
goto V_161;
}
if ( V_11 -> V_162 ( V_8 -> V_163 , V_8 -> V_160 , V_157 ,
V_8 -> V_155 ) ) {
F_30 ( V_92 L_3 ) ;
goto V_164;
}
V_6 = V_8 -> V_6 [ 0 ] ;
if ( V_6 -> V_127 . V_128 )
V_8 -> V_155 [ 0 ] |= V_165 ;
if ( V_6 -> V_127 . V_129 )
V_8 -> V_155 [ 0 ] |= V_41 ;
if ( V_6 -> V_127 . V_130 )
V_8 -> V_155 [ 0 ] |= V_42 ;
F_54 ( 1 ) ;
F_32 ( V_50 , V_8 -> V_155 [ 2 ] & ~ V_14 ) ;
F_32 ( V_159 , V_8 -> V_155 [ 1 ] ) ;
F_32 ( V_148 , ( V_8 -> V_155 [ 0 ] & ~ ( V_150 | V_151 ) )
| V_149 ) ;
for ( V_104 = 0 ; V_104 < V_8 -> V_160 ; ++ V_104 ) {
V_6 = V_8 -> V_6 [ V_104 ] ;
if ( V_6 -> V_134 . V_83 && V_6 -> V_134 . V_83 != V_157 [ V_104 ] + 1 ) {
F_36 ( V_6 ) ;
F_31 ( V_6 -> V_134 . V_83 , 0 ) ;
V_6 -> V_134 . V_83 = 0 ;
}
}
V_8 -> V_144 = V_158 = 0 ;
for ( V_104 = 0 ; V_104 < V_8 -> V_160 ; ++ V_104 ) {
V_6 = V_8 -> V_6 [ V_104 ] ;
if ( V_6 -> V_134 . V_83 )
continue;
V_83 = V_157 [ V_104 ] + 1 ;
if ( F_42 ( V_83 ) ) {
V_8 -> V_145 [ V_158 ] = V_6 ;
V_8 -> V_146 [ V_158 ] = V_83 ;
++ V_158 ;
continue;
}
V_69 = 0 ;
if ( V_6 -> V_134 . V_166 ) {
V_156 = F_37 ( & V_6 -> V_134 . V_139 ) ;
if ( V_156 < 0x80000000L )
V_69 = 0x80000000L - V_156 ;
}
F_45 ( & V_6 -> V_134 . V_137 , V_69 ) ;
V_6 -> V_134 . V_83 = V_83 ;
if ( V_6 -> V_134 . V_135 & V_136 )
V_69 = 0 ;
F_31 ( V_83 , V_69 ) ;
F_46 ( V_6 ) ;
}
V_8 -> V_144 = V_158 ;
V_8 -> V_155 [ 0 ] |= V_167 | V_168 ;
V_161:
F_51 () ;
F_47 ( V_8 , V_8 -> V_155 [ 0 ] ) ;
if ( V_8 -> V_155 [ 2 ] & V_14 ) {
F_51 () ;
F_32 ( V_50 , V_8 -> V_155 [ 2 ] ) ;
}
V_164:
if ( V_8 -> V_61 )
V_11 -> V_169 ( V_8 -> V_170 ) ;
F_52 ( V_12 ) ;
}
static int F_55 ( struct V_5 * V_171 , int V_172 ,
struct V_5 * V_118 [] , T_1 * V_163 ,
unsigned int * V_12 )
{
int V_124 = 0 ;
struct V_5 * V_6 ;
if ( ! F_56 ( V_171 ) ) {
if ( V_124 >= V_172 )
return - 1 ;
V_118 [ V_124 ] = V_171 ;
V_12 [ V_124 ] = V_171 -> V_134 . V_173 ;
V_163 [ V_124 ++ ] = V_171 -> V_134 . V_174 ;
}
F_57 (event, &group->sibling_list, group_entry) {
if ( ! F_56 ( V_6 ) &&
V_6 -> V_135 != V_175 ) {
if ( V_124 >= V_172 )
return - 1 ;
V_118 [ V_124 ] = V_6 ;
V_12 [ V_124 ] = V_6 -> V_134 . V_173 ;
V_163 [ V_124 ++ ] = V_6 -> V_134 . V_174 ;
}
}
return V_124 ;
}
static int F_58 ( struct V_5 * V_6 , int V_176 )
{
struct V_7 * V_8 ;
unsigned long V_12 ;
int V_177 ;
int V_65 = - V_131 ;
F_49 ( V_12 ) ;
F_59 ( V_6 -> V_152 ) ;
V_8 = & F_18 ( V_7 ) ;
V_177 = V_8 -> V_160 ;
if ( V_177 >= V_11 -> V_110 )
goto V_164;
V_8 -> V_6 [ V_177 ] = V_6 ;
V_8 -> V_163 [ V_177 ] = V_6 -> V_134 . V_174 ;
V_8 -> V_12 [ V_177 ] = V_6 -> V_134 . V_173 ;
if ( ! ( V_176 & V_178 ) )
V_6 -> V_134 . V_135 = V_136 | V_179 ;
else
V_6 -> V_134 . V_135 = 0 ;
if ( V_8 -> V_180 & V_181 )
goto V_182;
if ( F_34 ( V_8 -> V_6 , V_8 -> V_12 , V_177 , 1 ) )
goto V_164;
if ( F_33 ( V_8 , V_8 -> V_163 , V_8 -> V_12 , V_177 + 1 ) )
goto V_164;
V_6 -> V_134 . V_174 = V_8 -> V_163 [ V_177 ] ;
V_182:
++ V_8 -> V_160 ;
++ V_8 -> V_153 ;
V_65 = 0 ;
V_164:
if ( F_60 ( V_6 ) )
F_7 ( V_6 ) ;
F_61 ( V_6 -> V_152 ) ;
F_52 ( V_12 ) ;
return V_65 ;
}
static void F_62 ( struct V_5 * V_6 , int V_176 )
{
struct V_7 * V_8 ;
long V_104 ;
unsigned long V_12 ;
F_49 ( V_12 ) ;
F_59 ( V_6 -> V_152 ) ;
F_36 ( V_6 ) ;
V_8 = & F_18 ( V_7 ) ;
for ( V_104 = 0 ; V_104 < V_8 -> V_160 ; ++ V_104 ) {
if ( V_6 == V_8 -> V_6 [ V_104 ] ) {
while ( ++ V_104 < V_8 -> V_160 ) {
V_8 -> V_6 [ V_104 - 1 ] = V_8 -> V_6 [ V_104 ] ;
V_8 -> V_163 [ V_104 - 1 ] = V_8 -> V_163 [ V_104 ] ;
V_8 -> V_12 [ V_104 - 1 ] = V_8 -> V_12 [ V_104 ] ;
}
-- V_8 -> V_160 ;
V_11 -> V_183 ( V_6 -> V_134 . V_83 - 1 , V_8 -> V_155 ) ;
if ( V_6 -> V_134 . V_83 ) {
F_31 ( V_6 -> V_134 . V_83 , 0 ) ;
V_6 -> V_134 . V_83 = 0 ;
}
F_46 ( V_6 ) ;
break;
}
}
for ( V_104 = 0 ; V_104 < V_8 -> V_144 ; ++ V_104 )
if ( V_6 == V_8 -> V_145 [ V_104 ] )
break;
if ( V_104 < V_8 -> V_144 ) {
while ( ++ V_104 < V_8 -> V_144 ) {
V_8 -> V_145 [ V_104 - 1 ] = V_8 -> V_145 [ V_104 ] ;
V_8 -> V_146 [ V_104 - 1 ] = V_8 -> V_146 [ V_104 ] ;
}
-- V_8 -> V_144 ;
}
if ( V_8 -> V_160 == 0 ) {
V_8 -> V_155 [ 0 ] &= ~ ( V_167 | V_168 ) ;
}
if ( F_60 ( V_6 ) )
F_8 ( V_6 ) ;
F_61 ( V_6 -> V_152 ) ;
F_52 ( V_12 ) ;
}
static void F_63 ( struct V_5 * V_6 , int V_176 )
{
unsigned long V_12 ;
T_4 V_156 ;
unsigned long V_69 ;
if ( ! V_6 -> V_134 . V_83 || ! V_6 -> V_134 . V_166 )
return;
if ( ! ( V_6 -> V_134 . V_135 & V_136 ) )
return;
if ( V_176 & V_184 )
F_19 ( ! ( V_6 -> V_134 . V_135 & V_179 ) ) ;
F_49 ( V_12 ) ;
F_59 ( V_6 -> V_152 ) ;
V_6 -> V_134 . V_135 = 0 ;
V_156 = F_37 ( & V_6 -> V_134 . V_139 ) ;
V_69 = 0 ;
if ( V_156 < 0x80000000L )
V_69 = 0x80000000L - V_156 ;
F_31 ( V_6 -> V_134 . V_83 , V_69 ) ;
F_46 ( V_6 ) ;
F_61 ( V_6 -> V_152 ) ;
F_52 ( V_12 ) ;
}
static void F_64 ( struct V_5 * V_6 , int V_176 )
{
unsigned long V_12 ;
if ( ! V_6 -> V_134 . V_83 || ! V_6 -> V_134 . V_166 )
return;
if ( V_6 -> V_134 . V_135 & V_136 )
return;
F_49 ( V_12 ) ;
F_59 ( V_6 -> V_152 ) ;
F_36 ( V_6 ) ;
V_6 -> V_134 . V_135 |= V_136 | V_179 ;
F_31 ( V_6 -> V_134 . V_83 , 0 ) ;
F_46 ( V_6 ) ;
F_61 ( V_6 -> V_152 ) ;
F_52 ( V_12 ) ;
}
void F_65 ( struct V_152 * V_152 )
{
struct V_7 * V_8 = & F_18 ( V_7 ) ;
F_59 ( V_152 ) ;
V_8 -> V_180 |= V_181 ;
V_8 -> V_185 = V_8 -> V_160 ;
}
void F_66 ( struct V_152 * V_152 )
{
struct V_7 * V_8 = & F_18 ( V_7 ) ;
V_8 -> V_180 &= ~ V_181 ;
F_61 ( V_152 ) ;
}
int F_67 ( struct V_152 * V_152 )
{
struct V_7 * V_8 ;
long V_104 , V_124 ;
if ( ! V_11 )
return - V_131 ;
V_8 = & F_18 ( V_7 ) ;
V_124 = V_8 -> V_160 ;
if ( F_34 ( V_8 -> V_6 , V_8 -> V_12 , 0 , V_124 ) )
return - V_131 ;
V_104 = F_33 ( V_8 , V_8 -> V_163 , V_8 -> V_12 , V_124 ) ;
if ( V_104 < 0 )
return - V_131 ;
for ( V_104 = V_8 -> V_185 ; V_104 < V_124 ; ++ V_104 )
V_8 -> V_6 [ V_104 ] -> V_134 . V_174 = V_8 -> V_163 [ V_104 ] ;
V_8 -> V_180 &= ~ V_181 ;
F_61 ( V_152 ) ;
return 0 ;
}
static int F_68 ( struct V_5 * V_6 , T_1 V_186 ,
unsigned int V_12 )
{
int V_124 ;
T_1 V_187 [ V_188 ] ;
if ( V_6 -> V_127 . V_128
|| V_6 -> V_127 . V_129
|| V_6 -> V_127 . V_130
|| V_6 -> V_127 . V_166 )
return 0 ;
if ( V_11 -> V_112 ( V_186 ) )
return 1 ;
if ( ! V_11 -> V_113 )
return 0 ;
V_12 |= V_126 | V_111 ;
V_124 = V_11 -> V_113 ( V_186 , V_12 , V_187 ) ;
return V_124 > 0 ;
}
static T_1 F_69 ( T_1 V_186 , unsigned long V_12 )
{
T_1 V_187 [ V_188 ] ;
int V_124 ;
V_12 &= ~ ( V_126 | V_111 ) ;
V_124 = V_11 -> V_113 ( V_186 , V_12 , V_187 ) ;
if ( ! V_124 )
return 0 ;
return V_187 [ 0 ] ;
}
static void F_70 ( struct V_5 * V_6 )
{
if ( ! F_71 ( & V_189 , - 1 , 1 ) ) {
F_72 ( & V_190 ) ;
if ( F_73 ( & V_189 ) == 0 )
F_74 () ;
F_75 ( & V_190 ) ;
}
}
static int F_76 ( T_1 V_174 , T_1 * V_191 )
{
unsigned long type , V_192 , V_4 ;
int V_186 ;
if ( ! V_11 -> V_193 )
return - V_194 ;
type = V_174 & 0xff ;
V_192 = ( V_174 >> 8 ) & 0xff ;
V_4 = ( V_174 >> 16 ) & 0xff ;
if ( type >= V_195 ||
V_192 >= V_196 ||
V_4 >= V_197 )
return - V_194 ;
V_186 = ( * V_11 -> V_193 ) [ type ] [ V_192 ] [ V_4 ] ;
if ( V_186 == 0 )
return - V_198 ;
if ( V_186 == - 1 )
return - V_194 ;
* V_191 = V_186 ;
return 0 ;
}
static int F_77 ( struct V_5 * V_6 )
{
T_1 V_186 ;
unsigned long V_12 ;
struct V_5 * V_118 [ V_100 ] ;
T_1 V_163 [ V_100 ] ;
unsigned int V_94 [ V_100 ] ;
int V_124 ;
int V_199 ;
struct V_7 * V_8 ;
if ( ! V_11 )
return - V_200 ;
if ( F_60 ( V_6 ) ) {
if ( ! ( V_11 -> V_12 & V_201 ) )
return - V_198 ;
}
switch ( V_6 -> V_127 . type ) {
case V_202 :
V_186 = V_6 -> V_127 . V_174 ;
if ( V_186 >= V_11 -> V_203 || V_11 -> V_204 [ V_186 ] == 0 )
return - V_198 ;
V_186 = V_11 -> V_204 [ V_186 ] ;
break;
case V_205 :
V_199 = F_76 ( V_6 -> V_127 . V_174 , & V_186 ) ;
if ( V_199 )
return V_199 ;
break;
case V_206 :
V_186 = V_6 -> V_127 . V_174 ;
break;
default:
return - V_200 ;
}
V_6 -> V_134 . V_207 = V_186 ;
V_6 -> V_134 . V_83 = 0 ;
if ( ! F_78 ( V_208 ) )
V_6 -> V_127 . V_130 = 0 ;
V_12 = 0 ;
if ( V_6 -> V_209 & V_210 )
V_12 |= V_211 ;
if ( V_11 -> V_12 & V_141 ) {
if ( F_68 ( V_6 , V_186 , V_12 ) ) {
V_12 |= V_126 ;
} else if ( V_11 -> V_112 ( V_186 ) ) {
V_186 = F_69 ( V_186 , V_12 ) ;
if ( ! V_186 )
return - V_194 ;
}
}
V_124 = 0 ;
if ( V_6 -> V_212 != V_6 ) {
V_124 = F_55 ( V_6 -> V_212 , V_11 -> V_110 - 1 ,
V_118 , V_163 , V_94 ) ;
if ( V_124 < 0 )
return - V_194 ;
}
V_163 [ V_124 ] = V_186 ;
V_118 [ V_124 ] = V_6 ;
V_94 [ V_124 ] = V_12 ;
if ( F_34 ( V_118 , V_94 , V_124 , 1 ) )
return - V_194 ;
V_8 = & F_79 ( V_7 ) ;
V_199 = F_33 ( V_8 , V_163 , V_94 , V_124 + 1 ) ;
if ( F_60 ( V_6 ) ) {
V_8 -> V_170 = V_11 -> V_213 (
V_6 -> V_127 . V_214 ) ;
if( V_8 -> V_170 == - 1 )
return - V_198 ;
}
F_80 ( V_7 ) ;
if ( V_199 )
return - V_194 ;
V_6 -> V_134 . V_174 = V_163 [ V_124 ] ;
V_6 -> V_134 . V_173 = V_94 [ V_124 ] ;
V_6 -> V_134 . V_215 = V_6 -> V_134 . V_166 ;
F_45 ( & V_6 -> V_134 . V_139 , V_6 -> V_134 . V_215 ) ;
V_199 = 0 ;
if ( ! F_81 ( & V_189 ) ) {
F_72 ( & V_190 ) ;
if ( F_82 ( & V_189 ) == 0 &&
F_83 ( V_216 ) )
V_199 = - V_217 ;
else
F_84 ( & V_189 ) ;
F_75 ( & V_190 ) ;
}
V_6 -> V_218 = F_70 ;
return V_199 ;
}
static int F_85 ( struct V_5 * V_6 )
{
return V_6 -> V_134 . V_83 ;
}
T_5 F_86 ( struct V_219 * V_220 ,
struct V_221 * V_127 , char * V_222 )
{
struct V_223 * V_224 ;
V_224 = F_87 ( V_127 , struct V_223 , V_127 ) ;
return sprintf ( V_222 , L_4 , V_224 -> V_225 ) ;
}
static void F_88 ( struct V_5 * V_6 , unsigned long V_69 ,
struct V_1 * V_2 )
{
T_1 V_226 = V_6 -> V_134 . V_166 ;
T_4 V_132 , V_133 , V_156 ;
int V_227 = 0 ;
if ( V_6 -> V_134 . V_135 & V_136 ) {
F_31 ( V_6 -> V_134 . V_83 , 0 ) ;
return;
}
V_132 = F_37 ( & V_6 -> V_134 . V_137 ) ;
V_133 = F_35 ( V_132 , V_69 ) ;
F_40 ( V_133 , & V_6 -> V_138 ) ;
V_69 = 0 ;
V_156 = F_37 ( & V_6 -> V_134 . V_139 ) - V_133 ;
if ( V_133 == 0 )
V_156 ++ ;
if ( V_226 ) {
if ( V_156 <= 0 ) {
V_156 += V_226 ;
if ( V_156 <= 0 )
V_156 = V_226 ;
V_227 = F_6 ( V_2 ) ;
V_6 -> V_134 . V_215 = V_6 -> V_134 . V_166 ;
}
if ( V_156 < 0x80000000LL )
V_69 = 0x80000000LL - V_156 ;
}
F_31 ( V_6 -> V_134 . V_83 , V_69 ) ;
F_45 ( & V_6 -> V_134 . V_137 , V_69 ) ;
F_45 ( & V_6 -> V_134 . V_139 , V_156 ) ;
F_46 ( V_6 ) ;
if ( V_227 ) {
struct V_228 V_229 ;
F_89 ( & V_229 , ~ 0ULL , V_6 -> V_134 . V_215 ) ;
if ( V_6 -> V_127 . V_230 & V_231 )
F_2 ( V_2 , & V_229 . V_63 ) ;
if ( V_6 -> V_127 . V_230 & V_232 ) {
struct V_7 * V_8 ;
V_8 = & F_18 ( V_7 ) ;
F_10 ( V_8 ) ;
V_229 . V_233 = & V_8 -> V_81 ;
}
if ( F_90 ( V_6 , & V_229 , V_2 ) )
F_64 ( V_6 , 0 ) ;
}
}
unsigned long F_91 ( struct V_1 * V_2 )
{
T_2 V_12 = F_3 ( V_2 ) ;
if ( V_12 )
return V_12 ;
return F_92 ( V_2 ) ? V_39 :
V_44 ;
}
unsigned long F_93 ( struct V_1 * V_2 )
{
bool V_45 = F_11 ( V_2 ) ;
if ( V_45 && F_6 ( V_2 ) )
return F_12 ( V_48 ) + F_1 ( V_2 ) ;
else if ( V_45 )
return 0 ;
else
return V_2 -> V_234 ;
}
static bool F_94 ( unsigned long V_69 )
{
if ( ( 0x80000000 - V_69 ) <= 256 )
return true ;
return false ;
}
static bool F_95 ( unsigned long V_69 )
{
if ( ( int ) V_69 < 0 )
return true ;
return false ;
}
static void V_216 ( struct V_1 * V_2 )
{
int V_104 , V_105 ;
struct V_7 * V_8 = & F_18 ( V_7 ) ;
struct V_5 * V_6 ;
unsigned long V_69 [ 8 ] ;
int V_235 , V_236 ;
int V_237 ;
if ( V_8 -> V_144 )
F_43 ( V_8 , F_12 ( V_88 ) ,
F_12 ( V_89 ) ) ;
F_4 ( V_2 ) ;
V_237 = F_5 ( V_2 ) ;
if ( V_237 )
F_96 () ;
else
F_97 () ;
for ( V_104 = 0 ; V_104 < V_11 -> V_110 ; ++ V_104 )
V_69 [ V_104 ] = F_28 ( V_104 + 1 ) ;
V_235 = 0 ;
for ( V_104 = 0 ; V_104 < V_11 -> V_110 ; ++ V_104 ) {
if ( ! F_95 ( V_69 [ V_104 ] ) )
continue;
if ( F_42 ( V_104 + 1 ) )
continue;
V_235 = 1 ;
V_236 = 0 ;
for ( V_105 = 0 ; V_105 < V_8 -> V_160 ; ++ V_105 ) {
V_6 = V_8 -> V_6 [ V_105 ] ;
if ( V_6 -> V_134 . V_83 == ( V_104 + 1 ) ) {
V_236 = 1 ;
F_88 ( V_6 , V_69 [ V_104 ] , V_2 ) ;
break;
}
}
if ( ! V_236 )
F_31 ( V_104 + 1 , 0 ) ;
}
if ( ! V_235 && F_98 ( V_238 ) ) {
for ( V_104 = 0 ; V_104 < V_8 -> V_160 ; ++ V_104 ) {
V_6 = V_8 -> V_6 [ V_104 ] ;
if ( ! V_6 -> V_134 . V_83 || F_42 ( V_6 -> V_134 . V_83 ) )
continue;
if ( F_94 ( V_69 [ V_6 -> V_134 . V_83 - 1 ] ) ) {
V_235 = 1 ;
F_88 ( V_6 ,
V_69 [ V_6 -> V_134 . V_83 - 1 ] ,
V_2 ) ;
}
}
}
if ( ! V_235 && ! V_237 && F_99 () )
F_30 ( V_239 L_5 ) ;
F_47 ( V_8 , V_8 -> V_155 [ 0 ] ) ;
if ( V_237 )
F_100 () ;
else
F_101 () ;
}
static void F_102 ( int V_240 )
{
struct V_7 * V_8 = & F_103 ( V_7 , V_240 ) ;
if ( ! V_11 )
return;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_155 [ 0 ] = V_149 ;
}
static int T_6
F_104 ( struct V_241 * V_242 , unsigned long V_243 , void * V_244 )
{
unsigned int V_240 = ( long ) V_244 ;
switch ( V_243 & ~ V_245 ) {
case V_246 :
F_102 ( V_240 ) ;
break;
default:
break;
}
return V_247 ;
}
int T_6 F_105 ( struct V_248 * V_152 )
{
if ( V_11 )
return - V_217 ;
V_11 = V_152 ;
F_106 ( L_6 ,
V_152 -> V_249 ) ;
V_248 . V_250 = V_11 -> V_250 ;
#ifdef V_40
if ( F_107 () & V_40 )
V_41 = V_42 ;
#endif
F_108 ( & V_248 , L_7 , V_206 ) ;
F_109 ( F_104 ) ;
return 0 ;
}
