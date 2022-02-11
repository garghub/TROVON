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
static bool F_7 ( struct V_5 * V_6 ) { return false ; }
static int F_8 ( struct V_5 * V_6 ) { return 0 ; }
static void F_9 ( struct V_5 * V_6 ) { }
static void F_10 ( unsigned long V_7 ) { }
static unsigned long F_11 ( bool V_8 , unsigned long V_7 )
{
return V_7 ;
}
static inline void F_12 ( struct V_5 * V_6 ) {}
static inline void F_13 ( struct V_5 * V_6 ) {}
void F_14 ( void ) {}
static inline void F_15 ( struct V_9 * V_10 ) {}
static bool F_16 ( struct V_1 * V_2 )
{
return ! ! V_2 -> V_4 ;
}
static inline unsigned long F_1 ( struct V_1 * V_2 )
{
unsigned long V_11 = V_2 -> V_12 ;
if ( ( V_13 -> V_14 & V_15 ) && ( V_11 & V_16 ) ) {
unsigned long V_17 = ( V_11 & V_18 ) >> V_19 ;
if ( V_17 > 1 )
return 4 * ( V_17 - 1 ) ;
}
return 0 ;
}
static inline void F_2 ( struct V_1 * V_2 , T_1 * V_3 )
{
unsigned long V_11 = V_2 -> V_12 ;
bool V_20 ;
if ( V_13 -> V_14 & V_21 )
V_20 = V_2 -> V_22 & V_23 ;
else {
unsigned long V_24 ;
if ( V_13 -> V_14 & V_25 )
V_24 = V_26 ;
else if ( V_13 -> V_14 & V_27 )
V_24 = V_28 ;
else
V_24 = V_29 ;
V_20 = V_11 & V_24 ;
}
if ( ! ( V_11 & V_16 ) || V_20 )
* V_3 = F_17 ( V_30 ) ;
}
static bool F_18 ( struct V_1 * V_2 )
{
unsigned long V_31 = V_32 ;
if ( V_13 -> V_14 & V_21 )
return ! ! ( V_2 -> V_22 & V_33 ) ;
if ( V_13 -> V_14 & V_27 )
V_31 = V_34 ;
return ! ! ( V_2 -> V_12 & V_31 ) ;
}
static bool F_19 ( struct V_1 * V_2 )
{
unsigned long V_35 = V_36 ;
if ( V_13 -> V_14 & V_21 )
return ! ! ( V_2 -> V_22 & V_37 ) ;
if ( V_13 -> V_14 & V_27 )
V_35 = V_38 ;
return ! ! ( V_2 -> V_12 & V_35 ) ;
}
static inline T_2 F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_39 & V_40 )
return V_41 ;
if ( ( V_2 -> V_39 & V_42 ) && V_43 != V_44 )
return V_45 ;
return V_46 ;
}
static inline T_2 F_3 ( struct V_1 * V_2 )
{
bool V_47 = F_16 ( V_2 ) ;
if ( ! V_47 )
return F_20 ( V_2 ) ;
if ( V_13 -> V_14 & V_48 ) {
unsigned long V_49 = F_17 ( V_50 ) ;
if ( V_49 >= V_51 )
return V_46 ;
return V_41 ;
}
if ( F_19 ( V_2 ) )
return V_41 ;
if ( F_18 ( V_2 ) && ( V_43 != V_44 ) )
return V_45 ;
return V_46 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
unsigned long V_11 = F_17 ( V_52 ) ;
int V_53 = V_11 & V_16 ;
int V_47 ;
V_2 -> V_12 = V_11 ;
if ( V_13 -> V_14 & V_21 )
V_2 -> V_22 = F_17 ( V_54 ) ;
if ( F_21 ( V_2 ) != 0xf00 )
V_47 = 0 ;
else if ( V_53 )
V_47 = 1 ;
else if ( ( V_13 -> V_14 & V_55 ) )
V_47 = 0 ;
else if ( ! ( V_13 -> V_14 & V_48 ) && F_19 ( V_2 ) )
V_47 = 0 ;
else
V_47 = 1 ;
V_2 -> V_4 = V_47 ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
return ! V_2 -> V_56 ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
unsigned long V_11 = V_2 -> V_12 ;
int V_53 = V_11 & V_16 ;
if ( V_53 ) {
if ( V_13 -> V_14 & V_21 )
return V_2 -> V_22 & V_57 ;
if ( V_13 -> V_14 & V_25 )
return V_11 & V_58 ;
}
return 1 ;
}
static void F_22 ( void )
{
asm volatile(PPC_CLRBHRB);
}
static void F_12 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = & F_23 ( V_9 ) ;
if ( ! V_13 -> V_59 )
return;
if ( V_6 -> V_60 -> V_61 && V_10 -> V_62 != V_6 -> V_60 ) {
F_22 () ;
V_10 -> V_62 = V_6 -> V_60 ;
}
V_10 -> V_63 ++ ;
}
static void F_13 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = & F_23 ( V_9 ) ;
if ( ! V_13 -> V_59 )
return;
V_10 -> V_63 -- ;
F_24 ( V_10 -> V_63 < 0 ) ;
if ( ! V_10 -> V_64 && ! V_10 -> V_63 ) {
V_10 -> V_62 = NULL ;
}
}
void F_14 ( void )
{
if ( V_13 -> V_59 )
F_22 () ;
}
static T_3 F_25 ( T_1 V_65 )
{
unsigned int V_66 ;
int V_67 ;
T_3 V_68 ;
if ( F_26 ( V_65 ) )
return F_27 ( ( unsigned int * ) V_65 ) ;
F_28 () ;
V_67 = F_29 ( V_66 , ( unsigned int V_69 * ) V_65 ) ;
if ( V_67 ) {
F_30 () ;
return 0 ;
}
F_30 () ;
V_68 = F_27 ( & V_66 ) ;
if ( ( ! V_68 ) || ( V_66 & V_70 ) )
return V_68 ;
return V_68 - ( unsigned long ) & V_66 + V_65 ;
}
void F_15 ( struct V_9 * V_10 )
{
T_1 V_71 ;
T_1 V_65 ;
int V_72 , V_73 , V_74 ;
V_72 = 0 ;
V_73 = 0 ;
while ( V_72 < V_13 -> V_59 ) {
V_71 = F_31 ( V_72 ++ ) ;
if ( ! V_71 )
break;
else {
V_65 = V_71 & V_75 ;
V_74 = V_71 & V_76 ;
if ( ! V_65 )
continue;
if ( V_71 & V_77 ) {
V_10 -> V_78 [ V_73 ] . V_79 = V_65 ;
V_10 -> V_78 [ V_73 ] . V_80 = V_74 ;
V_10 -> V_78 [ V_73 ] . V_81 = ~ V_74 ;
V_71 = F_31 ( V_72 ++ ) ;
V_65 = V_71 & V_75 ;
if ( V_71 & V_77 ) {
V_72 -- ;
V_65 = 0 ;
}
V_10 -> V_78 [ V_73 ] . V_82 = V_65 ;
} else {
V_10 -> V_78 [ V_73 ] . V_82 = V_65 ;
V_10 -> V_78 [ V_73 ] . V_79 =
F_25 ( V_65 ) ;
V_10 -> V_78 [ V_73 ] . V_80 = V_74 ;
V_10 -> V_78 [ V_73 ] . V_81 = ~ V_74 ;
}
V_73 ++ ;
}
}
V_10 -> V_83 . V_84 = V_73 ;
return;
}
static bool F_7 ( struct V_5 * V_6 )
{
return ( V_13 -> V_14 & V_85 ) &&
( ( V_6 -> V_86 . V_87 >> V_88 ) & 1 ) ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_5 * V_89 = V_6 -> V_90 ;
if ( F_7 ( V_89 ) != F_7 ( V_6 ) )
return - V_91 ;
if ( F_7 ( V_6 ) ) {
if ( ! ( V_6 -> V_92 & V_93 ) )
return - V_91 ;
if ( ! V_89 -> V_86 . V_94 || ! V_89 -> V_86 . V_95 )
return - V_91 ;
if ( V_6 -> V_86 . V_96 || V_6 -> V_86 . V_97 ||
V_6 -> V_86 . V_98 || V_6 -> V_86 . V_99 )
return - V_91 ;
}
return 0 ;
}
static void F_9 ( struct V_5 * V_6 )
{
if ( ! F_7 ( V_6 ) || V_100 -> V_101 . V_102 )
return;
V_100 -> V_101 . V_102 = 1 ;
V_100 -> V_101 . V_7 |= V_103 ;
}
static void F_10 ( unsigned long V_7 )
{
if ( ! ( V_7 & V_104 ) )
return;
V_100 -> V_101 . V_49 = F_17 ( V_50 ) ;
V_100 -> V_101 . V_105 = F_17 ( V_54 ) ;
V_100 -> V_101 . V_106 = F_17 ( V_30 ) ;
V_100 -> V_101 . V_7 = V_7 & V_107 ;
V_100 -> V_101 . V_108 = F_17 ( V_109 ) & V_110 ;
}
static unsigned long F_11 ( bool V_8 , unsigned long V_7 )
{
if ( ! V_8 )
goto V_111;
V_7 |= V_104 | V_112 ;
V_7 |= V_100 -> V_101 . V_7 ;
if ( ! ( V_100 -> V_101 . V_7 & V_103 ) )
V_7 &= ~ V_103 ;
F_32 ( V_50 , V_100 -> V_101 . V_49 ) ;
F_32 ( V_54 , V_100 -> V_101 . V_105 ) ;
F_32 ( V_30 , V_100 -> V_101 . V_106 ) ;
F_32 ( V_109 , V_100 -> V_101 . V_108 ) ;
V_111:
return V_7 ;
}
void F_33 ( void )
{
}
static unsigned long F_34 ( int V_113 )
{
unsigned long V_71 ;
switch ( V_113 ) {
case 1 :
V_71 = F_17 ( V_114 ) ;
break;
case 2 :
V_71 = F_17 ( V_115 ) ;
break;
case 3 :
V_71 = F_17 ( V_116 ) ;
break;
case 4 :
V_71 = F_17 ( V_117 ) ;
break;
case 5 :
V_71 = F_17 ( V_118 ) ;
break;
case 6 :
V_71 = F_17 ( V_119 ) ;
break;
#ifdef F_35
case 7 :
V_71 = F_17 ( V_120 ) ;
break;
case 8 :
V_71 = F_17 ( V_121 ) ;
break;
#endif
default:
F_36 ( V_122 L_1 , V_113 ) ;
V_71 = 0 ;
}
return V_71 ;
}
static void F_37 ( int V_113 , unsigned long V_71 )
{
switch ( V_113 ) {
case 1 :
F_32 ( V_114 , V_71 ) ;
break;
case 2 :
F_32 ( V_115 , V_71 ) ;
break;
case 3 :
F_32 ( V_116 , V_71 ) ;
break;
case 4 :
F_32 ( V_117 , V_71 ) ;
break;
case 5 :
F_32 ( V_118 , V_71 ) ;
break;
case 6 :
F_32 ( V_119 , V_71 ) ;
break;
#ifdef F_35
case 7 :
F_32 ( V_120 , V_71 ) ;
break;
case 8 :
F_32 ( V_121 , V_71 ) ;
break;
#endif
default:
F_36 ( V_122 L_2 , V_113 ) ;
}
}
static int F_38 ( struct V_9 * V_10 ,
T_1 V_123 [] , unsigned int V_124 [] ,
int V_125 )
{
unsigned long V_126 , V_127 , V_128 ;
unsigned long V_129 [ V_130 ] , V_131 [ V_130 ] ;
int V_132 [ V_130 ] , V_133 [ V_130 ] ;
int V_134 , V_135 ;
unsigned long V_136 = V_13 -> V_137 ;
unsigned long V_138 = V_13 -> V_139 ;
if ( V_125 > V_13 -> V_140 )
return - 1 ;
for ( V_134 = 0 ; V_134 < V_125 ; ++ V_134 ) {
if ( ( V_124 [ V_134 ] & V_141 )
&& ! V_13 -> V_142 ( V_123 [ V_134 ] ) ) {
V_13 -> V_143 ( V_123 [ V_134 ] , V_124 [ V_134 ] ,
V_10 -> V_144 [ V_134 ] ) ;
V_123 [ V_134 ] = V_10 -> V_144 [ V_134 ] [ 0 ] ;
}
if ( V_13 -> V_145 ( V_123 [ V_134 ] , & V_10 -> V_146 [ V_134 ] [ 0 ] ,
& V_10 -> V_147 [ V_134 ] [ 0 ] ) )
return - 1 ;
}
V_127 = V_126 = 0 ;
for ( V_134 = 0 ; V_134 < V_125 ; ++ V_134 ) {
V_128 = ( V_127 | V_10 -> V_147 [ V_134 ] [ 0 ] ) +
( V_127 & V_10 -> V_147 [ V_134 ] [ 0 ] & V_136 ) ;
if ( ( ( ( V_128 + V_138 ) ^ V_127 ) & V_126 ) != 0 ||
( ( ( V_128 + V_138 ) ^ V_10 -> V_147 [ V_134 ] [ 0 ] ) &
V_10 -> V_146 [ V_134 ] [ 0 ] ) != 0 )
break;
V_127 = V_128 ;
V_126 |= V_10 -> V_146 [ V_134 ] [ 0 ] ;
}
if ( V_134 == V_125 )
return 0 ;
if ( ! V_13 -> V_143 )
return - 1 ;
for ( V_134 = 0 ; V_134 < V_125 ; ++ V_134 ) {
V_133 [ V_134 ] = 0 ;
V_132 [ V_134 ] = V_13 -> V_143 ( V_123 [ V_134 ] , V_124 [ V_134 ] ,
V_10 -> V_144 [ V_134 ] ) ;
for ( V_135 = 1 ; V_135 < V_132 [ V_134 ] ; ++ V_135 )
V_13 -> V_145 ( V_10 -> V_144 [ V_134 ] [ V_135 ] ,
& V_10 -> V_146 [ V_134 ] [ V_135 ] ,
& V_10 -> V_147 [ V_134 ] [ V_135 ] ) ;
}
V_134 = 0 ;
V_135 = - 1 ;
V_127 = V_126 = V_128 = 0 ;
while ( V_134 < V_125 ) {
if ( V_135 >= 0 ) {
V_127 = V_131 [ V_134 ] ;
V_126 = V_129 [ V_134 ] ;
V_135 = V_133 [ V_134 ] ;
}
while ( ++ V_135 < V_132 [ V_134 ] ) {
V_128 = ( V_127 | V_10 -> V_147 [ V_134 ] [ V_135 ] ) +
( V_127 & V_10 -> V_147 [ V_134 ] [ V_135 ] & V_136 ) ;
if ( ( ( ( V_128 + V_138 ) ^ V_127 ) & V_126 ) == 0 &&
( ( ( V_128 + V_138 ) ^ V_10 -> V_147 [ V_134 ] [ V_135 ] )
& V_10 -> V_146 [ V_134 ] [ V_135 ] ) == 0 )
break;
}
if ( V_135 >= V_132 [ V_134 ] ) {
if ( -- V_134 < 0 )
return - 1 ;
} else {
V_133 [ V_134 ] = V_135 ;
V_131 [ V_134 ] = V_127 ;
V_129 [ V_134 ] = V_126 ;
V_127 = V_128 ;
V_126 |= V_10 -> V_146 [ V_134 ] [ V_135 ] ;
++ V_134 ;
V_135 = - 1 ;
}
}
for ( V_134 = 0 ; V_134 < V_125 ; ++ V_134 )
V_123 [ V_134 ] = V_10 -> V_144 [ V_134 ] [ V_133 [ V_134 ] ] ;
return 0 ;
}
static int F_39 ( struct V_5 * * V_148 , unsigned int V_124 [] ,
int V_149 , int V_150 )
{
int V_151 = 0 , V_152 = 0 , V_153 = 0 ;
int V_134 , V_154 , V_155 ;
struct V_5 * V_6 ;
V_154 = V_149 + V_150 ;
if ( V_154 <= 1 )
return 0 ;
V_155 = 1 ;
for ( V_134 = 0 ; V_134 < V_154 ; ++ V_134 ) {
if ( V_124 [ V_134 ] & V_156 ) {
V_124 [ V_134 ] &= ~ V_141 ;
continue;
}
V_6 = V_148 [ V_134 ] ;
if ( V_155 ) {
V_151 = V_6 -> V_86 . V_157 ;
V_152 = V_6 -> V_86 . V_158 ;
V_153 = V_6 -> V_86 . V_159 ;
V_155 = 0 ;
} else if ( V_6 -> V_86 . V_157 != V_151 ||
V_6 -> V_86 . V_158 != V_152 ||
V_6 -> V_86 . V_159 != V_153 ) {
return - V_160 ;
}
}
if ( V_151 || V_152 || V_153 )
for ( V_134 = 0 ; V_134 < V_154 ; ++ V_134 )
if ( V_124 [ V_134 ] & V_156 )
V_124 [ V_134 ] |= V_141 ;
return 0 ;
}
static T_1 F_40 ( T_1 V_161 , T_1 V_71 )
{
T_1 V_162 = ( V_71 - V_161 ) & 0xfffffffful ;
if ( V_161 > V_71 && ( V_161 - V_71 ) < 256 )
V_162 = 0 ;
return V_162 ;
}
static void F_41 ( struct V_5 * V_6 )
{
T_4 V_71 , V_162 , V_161 ;
if ( V_6 -> V_163 . V_164 & V_165 )
return;
if ( ! V_6 -> V_163 . V_113 )
return;
if ( F_7 ( V_6 ) ) {
V_71 = F_34 ( V_6 -> V_163 . V_113 ) ;
F_42 ( & V_6 -> V_163 . V_166 , V_71 ) ;
return;
}
do {
V_161 = F_43 ( & V_6 -> V_163 . V_166 ) ;
F_44 () ;
V_71 = F_34 ( V_6 -> V_163 . V_113 ) ;
V_162 = F_40 ( V_161 , V_71 ) ;
if ( ! V_162 )
return;
} while ( F_45 ( & V_6 -> V_163 . V_166 , V_161 , V_71 ) != V_161 );
F_46 ( V_162 , & V_6 -> V_167 ) ;
F_47 ( V_162 , & V_6 -> V_163 . V_168 ) ;
}
static int F_48 ( int V_169 )
{
return ( V_13 -> V_14 & V_170 )
&& ( V_169 == 5 || V_169 == 6 ) ;
}
static void F_49 ( struct V_9 * V_10 ,
unsigned long V_171 , unsigned long V_172 )
{
struct V_5 * V_6 ;
T_1 V_71 , V_161 , V_162 ;
int V_134 ;
for ( V_134 = 0 ; V_134 < V_10 -> V_173 ; ++ V_134 ) {
V_6 = V_10 -> V_174 [ V_134 ] ;
if ( ! V_6 -> V_163 . V_113 )
continue;
V_71 = ( V_6 -> V_163 . V_113 == 5 ) ? V_171 : V_172 ;
V_161 = F_43 ( & V_6 -> V_163 . V_166 ) ;
V_6 -> V_163 . V_113 = 0 ;
V_162 = F_40 ( V_161 , V_71 ) ;
if ( V_162 )
F_46 ( V_162 , & V_6 -> V_167 ) ;
}
}
static void F_50 ( struct V_9 * V_10 ,
unsigned long V_171 , unsigned long V_172 )
{
struct V_5 * V_6 ;
T_1 V_71 , V_161 ;
int V_134 ;
for ( V_134 = 0 ; V_134 < V_10 -> V_173 ; ++ V_134 ) {
V_6 = V_10 -> V_174 [ V_134 ] ;
V_6 -> V_163 . V_113 = V_10 -> V_175 [ V_134 ] ;
V_71 = ( V_6 -> V_163 . V_113 == 5 ) ? V_171 : V_172 ;
V_161 = F_43 ( & V_6 -> V_163 . V_166 ) ;
if ( F_40 ( V_161 , V_71 ) )
F_42 ( & V_6 -> V_163 . V_166 , V_71 ) ;
F_51 ( V_6 ) ;
}
}
static void F_52 ( struct V_9 * V_10 , unsigned long V_7 )
{
unsigned long V_171 , V_172 ;
if ( ! V_10 -> V_173 ) {
F_32 ( V_176 , V_7 ) ;
return;
}
asm volatile("mtspr %3,%2; mfspr %0,%4; mfspr %1,%5"
: "=&r" (pmc5), "=&r" (pmc6)
: "r" (mmcr0 & ~(MMCR0_PMC1CE | MMCR0_PMCjCE)),
"i" (SPRN_MMCR0),
"i" (SPRN_PMC5), "i" (SPRN_PMC6));
if ( V_7 & V_177 )
F_49 ( V_10 , V_171 , V_172 ) ;
else
F_50 ( V_10 , V_171 , V_172 ) ;
if ( V_7 & ( V_178 | V_179 ) )
F_32 ( V_176 , V_7 ) ;
}
static void F_53 ( struct V_180 * V_180 )
{
struct V_9 * V_10 ;
unsigned long V_14 , V_7 , V_71 ;
if ( ! V_13 )
return;
F_54 ( V_14 ) ;
V_10 = & F_23 ( V_9 ) ;
if ( ! V_10 -> V_64 ) {
if ( ! V_10 -> V_181 ) {
F_55 () ;
V_10 -> V_181 = 1 ;
}
V_71 = V_7 = F_17 ( V_176 ) ;
V_71 |= V_177 ;
V_71 &= ~ ( V_104 | V_182 | V_183 | V_184 ) ;
F_52 ( V_10 , V_71 ) ;
F_56 () ;
if ( V_10 -> V_185 [ 2 ] & V_16 ) {
F_32 ( V_52 ,
V_10 -> V_185 [ 2 ] & ~ V_16 ) ;
F_56 () ;
}
V_10 -> V_64 = 1 ;
V_10 -> V_186 = 0 ;
F_10 ( V_7 ) ;
}
F_57 ( V_14 ) ;
}
static void F_58 ( struct V_180 * V_180 )
{
struct V_5 * V_6 ;
struct V_9 * V_10 ;
unsigned long V_14 ;
long V_134 ;
unsigned long V_71 , V_7 ;
T_4 V_187 ;
unsigned int V_188 [ V_130 ] ;
int V_189 ;
int V_113 ;
bool V_8 ;
if ( ! V_13 )
return;
F_54 ( V_14 ) ;
V_10 = & F_23 ( V_9 ) ;
if ( ! V_10 -> V_64 )
goto V_111;
if ( V_10 -> V_190 == 0 ) {
F_59 ( 0 ) ;
goto V_111;
}
V_10 -> V_64 = 0 ;
V_8 = F_7 ( V_10 -> V_6 [ 0 ] ) ;
if ( ! V_10 -> V_186 ) {
F_32 ( V_52 , V_10 -> V_185 [ 2 ] & ~ V_16 ) ;
F_32 ( V_191 , V_10 -> V_185 [ 1 ] ) ;
goto V_192;
}
if ( V_13 -> V_193 ( V_10 -> V_194 , V_10 -> V_190 , V_188 ,
V_10 -> V_185 ) ) {
F_36 ( V_122 L_3 ) ;
goto V_111;
}
V_6 = V_10 -> V_6 [ 0 ] ;
if ( V_6 -> V_86 . V_157 )
V_10 -> V_185 [ 0 ] |= V_195 ;
if ( V_6 -> V_86 . V_158 )
V_10 -> V_185 [ 0 ] |= V_43 ;
if ( V_6 -> V_86 . V_159 )
V_10 -> V_185 [ 0 ] |= V_44 ;
F_59 ( 1 ) ;
F_32 ( V_52 , V_10 -> V_185 [ 2 ] & ~ V_16 ) ;
F_32 ( V_191 , V_10 -> V_185 [ 1 ] ) ;
F_32 ( V_176 , ( V_10 -> V_185 [ 0 ] & ~ ( V_178 | V_179 ) )
| V_177 ) ;
for ( V_134 = 0 ; V_134 < V_10 -> V_190 ; ++ V_134 ) {
V_6 = V_10 -> V_6 [ V_134 ] ;
if ( V_6 -> V_163 . V_113 && V_6 -> V_163 . V_113 != V_188 [ V_134 ] + 1 ) {
F_41 ( V_6 ) ;
F_37 ( V_6 -> V_163 . V_113 , 0 ) ;
V_6 -> V_163 . V_113 = 0 ;
}
}
V_10 -> V_173 = V_189 = 0 ;
for ( V_134 = 0 ; V_134 < V_10 -> V_190 ; ++ V_134 ) {
V_6 = V_10 -> V_6 [ V_134 ] ;
if ( V_6 -> V_163 . V_113 )
continue;
V_113 = V_188 [ V_134 ] + 1 ;
if ( F_48 ( V_113 ) ) {
V_10 -> V_174 [ V_189 ] = V_6 ;
V_10 -> V_175 [ V_189 ] = V_113 ;
++ V_189 ;
continue;
}
if ( V_8 )
V_71 = F_43 ( & V_6 -> V_163 . V_166 ) ;
else {
V_71 = 0 ;
if ( V_6 -> V_163 . V_97 ) {
V_187 = F_43 ( & V_6 -> V_163 . V_168 ) ;
if ( V_187 < 0x80000000L )
V_71 = 0x80000000L - V_187 ;
}
F_42 ( & V_6 -> V_163 . V_166 , V_71 ) ;
}
V_6 -> V_163 . V_113 = V_113 ;
if ( V_6 -> V_163 . V_164 & V_165 )
V_71 = 0 ;
F_37 ( V_113 , V_71 ) ;
F_51 ( V_6 ) ;
}
V_10 -> V_173 = V_189 ;
V_10 -> V_185 [ 0 ] |= V_103 | V_196 ;
V_192:
V_7 = F_11 ( V_8 , V_10 -> V_185 [ 0 ] ) ;
F_56 () ;
F_52 ( V_10 , V_7 ) ;
if ( V_10 -> V_185 [ 2 ] & V_16 ) {
F_56 () ;
F_32 ( V_52 , V_10 -> V_185 [ 2 ] ) ;
}
V_111:
if ( V_10 -> V_63 )
V_13 -> V_197 ( V_10 -> V_198 ) ;
F_57 ( V_14 ) ;
}
static int F_60 ( struct V_5 * V_199 , int V_200 ,
struct V_5 * V_148 [] , T_1 * V_194 ,
unsigned int * V_14 )
{
int V_154 = 0 ;
struct V_5 * V_6 ;
if ( ! F_61 ( V_199 ) ) {
if ( V_154 >= V_200 )
return - 1 ;
V_148 [ V_154 ] = V_199 ;
V_14 [ V_154 ] = V_199 -> V_163 . V_201 ;
V_194 [ V_154 ++ ] = V_199 -> V_163 . V_87 ;
}
F_62 (event, &group->sibling_list, group_entry) {
if ( ! F_61 ( V_6 ) &&
V_6 -> V_164 != V_202 ) {
if ( V_154 >= V_200 )
return - 1 ;
V_148 [ V_154 ] = V_6 ;
V_14 [ V_154 ] = V_6 -> V_163 . V_201 ;
V_194 [ V_154 ++ ] = V_6 -> V_163 . V_87 ;
}
}
return V_154 ;
}
static int F_63 ( struct V_5 * V_6 , int V_203 )
{
struct V_9 * V_10 ;
unsigned long V_14 ;
int V_204 ;
int V_67 = - V_160 ;
F_54 ( V_14 ) ;
F_64 ( V_6 -> V_180 ) ;
V_10 = & F_23 ( V_9 ) ;
V_204 = V_10 -> V_190 ;
if ( V_204 >= V_13 -> V_140 )
goto V_111;
V_10 -> V_6 [ V_204 ] = V_6 ;
V_10 -> V_194 [ V_204 ] = V_6 -> V_163 . V_87 ;
V_10 -> V_14 [ V_204 ] = V_6 -> V_163 . V_201 ;
if ( ! ( V_203 & V_205 ) )
V_6 -> V_163 . V_164 = V_165 | V_206 ;
else
V_6 -> V_163 . V_164 = 0 ;
if ( V_10 -> V_207 & V_208 )
goto V_209;
if ( F_39 ( V_10 -> V_6 , V_10 -> V_14 , V_204 , 1 ) )
goto V_111;
if ( F_38 ( V_10 , V_10 -> V_194 , V_10 -> V_14 , V_204 + 1 ) )
goto V_111;
V_6 -> V_163 . V_87 = V_10 -> V_194 [ V_204 ] ;
V_209:
F_9 ( V_6 ) ;
++ V_10 -> V_190 ;
++ V_10 -> V_186 ;
V_67 = 0 ;
V_111:
if ( F_65 ( V_6 ) ) {
F_12 ( V_6 ) ;
V_10 -> V_198 = V_13 -> V_210 (
V_6 -> V_86 . V_211 ) ;
}
F_66 ( V_6 -> V_180 ) ;
F_57 ( V_14 ) ;
return V_67 ;
}
static void F_67 ( struct V_5 * V_6 , int V_203 )
{
struct V_9 * V_10 ;
long V_134 ;
unsigned long V_14 ;
F_54 ( V_14 ) ;
F_64 ( V_6 -> V_180 ) ;
F_41 ( V_6 ) ;
V_10 = & F_23 ( V_9 ) ;
for ( V_134 = 0 ; V_134 < V_10 -> V_190 ; ++ V_134 ) {
if ( V_6 == V_10 -> V_6 [ V_134 ] ) {
while ( ++ V_134 < V_10 -> V_190 ) {
V_10 -> V_6 [ V_134 - 1 ] = V_10 -> V_6 [ V_134 ] ;
V_10 -> V_194 [ V_134 - 1 ] = V_10 -> V_194 [ V_134 ] ;
V_10 -> V_14 [ V_134 - 1 ] = V_10 -> V_14 [ V_134 ] ;
}
-- V_10 -> V_190 ;
V_13 -> V_212 ( V_6 -> V_163 . V_113 - 1 , V_10 -> V_185 ) ;
if ( V_6 -> V_163 . V_113 ) {
F_37 ( V_6 -> V_163 . V_113 , 0 ) ;
V_6 -> V_163 . V_113 = 0 ;
}
F_51 ( V_6 ) ;
break;
}
}
for ( V_134 = 0 ; V_134 < V_10 -> V_173 ; ++ V_134 )
if ( V_6 == V_10 -> V_174 [ V_134 ] )
break;
if ( V_134 < V_10 -> V_173 ) {
while ( ++ V_134 < V_10 -> V_173 ) {
V_10 -> V_174 [ V_134 - 1 ] = V_10 -> V_174 [ V_134 ] ;
V_10 -> V_175 [ V_134 - 1 ] = V_10 -> V_175 [ V_134 ] ;
}
-- V_10 -> V_173 ;
}
if ( V_10 -> V_190 == 0 ) {
V_10 -> V_185 [ 0 ] &= ~ ( V_103 | V_196 ) ;
}
if ( F_65 ( V_6 ) )
F_13 ( V_6 ) ;
F_66 ( V_6 -> V_180 ) ;
F_57 ( V_14 ) ;
}
static void F_68 ( struct V_5 * V_6 , int V_203 )
{
unsigned long V_14 ;
T_4 V_187 ;
unsigned long V_71 ;
if ( ! V_6 -> V_163 . V_113 || ! V_6 -> V_163 . V_97 )
return;
if ( ! ( V_6 -> V_163 . V_164 & V_165 ) )
return;
if ( V_203 & V_213 )
F_24 ( ! ( V_6 -> V_163 . V_164 & V_206 ) ) ;
F_54 ( V_14 ) ;
F_64 ( V_6 -> V_180 ) ;
V_6 -> V_163 . V_164 = 0 ;
V_187 = F_43 ( & V_6 -> V_163 . V_168 ) ;
V_71 = 0 ;
if ( V_187 < 0x80000000L )
V_71 = 0x80000000L - V_187 ;
F_37 ( V_6 -> V_163 . V_113 , V_71 ) ;
F_51 ( V_6 ) ;
F_66 ( V_6 -> V_180 ) ;
F_57 ( V_14 ) ;
}
static void F_69 ( struct V_5 * V_6 , int V_203 )
{
unsigned long V_14 ;
if ( ! V_6 -> V_163 . V_113 || ! V_6 -> V_163 . V_97 )
return;
if ( V_6 -> V_163 . V_164 & V_165 )
return;
F_54 ( V_14 ) ;
F_64 ( V_6 -> V_180 ) ;
F_41 ( V_6 ) ;
V_6 -> V_163 . V_164 |= V_165 | V_206 ;
F_37 ( V_6 -> V_163 . V_113 , 0 ) ;
F_51 ( V_6 ) ;
F_66 ( V_6 -> V_180 ) ;
F_57 ( V_14 ) ;
}
void F_70 ( struct V_180 * V_180 )
{
struct V_9 * V_10 = & F_23 ( V_9 ) ;
F_64 ( V_180 ) ;
V_10 -> V_207 |= V_208 ;
V_10 -> V_214 = V_10 -> V_190 ;
}
void F_71 ( struct V_180 * V_180 )
{
struct V_9 * V_10 = & F_23 ( V_9 ) ;
V_10 -> V_207 &= ~ V_208 ;
F_66 ( V_180 ) ;
}
int F_72 ( struct V_180 * V_180 )
{
struct V_9 * V_10 ;
long V_134 , V_154 ;
if ( ! V_13 )
return - V_160 ;
V_10 = & F_23 ( V_9 ) ;
V_154 = V_10 -> V_190 ;
if ( F_39 ( V_10 -> V_6 , V_10 -> V_14 , 0 , V_154 ) )
return - V_160 ;
V_134 = F_38 ( V_10 , V_10 -> V_194 , V_10 -> V_14 , V_154 ) ;
if ( V_134 < 0 )
return - V_160 ;
for ( V_134 = V_10 -> V_214 ; V_134 < V_154 ; ++ V_134 )
V_10 -> V_6 [ V_134 ] -> V_163 . V_87 = V_10 -> V_194 [ V_134 ] ;
V_10 -> V_207 &= ~ V_208 ;
F_66 ( V_180 ) ;
return 0 ;
}
static int F_73 ( struct V_5 * V_6 , T_1 V_215 ,
unsigned int V_14 )
{
int V_154 ;
T_1 V_216 [ V_217 ] ;
if ( V_6 -> V_86 . V_157
|| V_6 -> V_86 . V_158
|| V_6 -> V_86 . V_159
|| V_6 -> V_86 . V_97 )
return 0 ;
if ( V_13 -> V_142 ( V_215 ) )
return 1 ;
if ( ! V_13 -> V_143 )
return 0 ;
V_14 |= V_156 | V_141 ;
V_154 = V_13 -> V_143 ( V_215 , V_14 , V_216 ) ;
return V_154 > 0 ;
}
static T_1 F_74 ( T_1 V_215 , unsigned long V_14 )
{
T_1 V_216 [ V_217 ] ;
int V_154 ;
V_14 &= ~ ( V_156 | V_141 ) ;
V_154 = V_13 -> V_143 ( V_215 , V_14 , V_216 ) ;
if ( ! V_154 )
return 0 ;
return V_216 [ 0 ] ;
}
static void F_75 ( struct V_5 * V_6 )
{
if ( ! F_76 ( & V_218 , - 1 , 1 ) ) {
F_77 ( & V_219 ) ;
if ( F_78 ( & V_218 ) == 0 )
F_79 () ;
F_80 ( & V_219 ) ;
}
}
static int F_81 ( T_1 V_87 , T_1 * V_220 )
{
unsigned long type , V_221 , V_4 ;
int V_215 ;
if ( ! V_13 -> V_222 )
return - V_91 ;
type = V_87 & 0xff ;
V_221 = ( V_87 >> 8 ) & 0xff ;
V_4 = ( V_87 >> 16 ) & 0xff ;
if ( type >= V_223 ||
V_221 >= V_224 ||
V_4 >= V_225 )
return - V_91 ;
V_215 = ( * V_13 -> V_222 ) [ type ] [ V_221 ] [ V_4 ] ;
if ( V_215 == 0 )
return - V_226 ;
if ( V_215 == - 1 )
return - V_91 ;
* V_220 = V_215 ;
return 0 ;
}
static int F_82 ( struct V_5 * V_6 )
{
T_1 V_215 ;
unsigned long V_14 ;
struct V_5 * V_148 [ V_130 ] ;
T_1 V_194 [ V_130 ] ;
unsigned int V_124 [ V_130 ] ;
int V_154 ;
int V_227 ;
struct V_9 * V_10 ;
if ( ! V_13 )
return - V_228 ;
if ( F_65 ( V_6 ) ) {
if ( ! ( V_13 -> V_14 & V_229 ) )
return - V_226 ;
}
switch ( V_6 -> V_86 . type ) {
case V_230 :
V_215 = V_6 -> V_86 . V_87 ;
if ( V_215 >= V_13 -> V_231 || V_13 -> V_232 [ V_215 ] == 0 )
return - V_226 ;
V_215 = V_13 -> V_232 [ V_215 ] ;
break;
case V_233 :
V_227 = F_81 ( V_6 -> V_86 . V_87 , & V_215 ) ;
if ( V_227 )
return V_227 ;
break;
case V_234 :
V_215 = V_6 -> V_86 . V_87 ;
break;
default:
return - V_228 ;
}
V_6 -> V_163 . V_235 = V_215 ;
V_6 -> V_163 . V_113 = 0 ;
if ( ! F_83 ( V_236 ) )
V_6 -> V_86 . V_159 = 0 ;
V_14 = 0 ;
if ( V_6 -> V_92 & V_93 )
V_14 |= V_237 ;
if ( V_13 -> V_14 & V_170 ) {
if ( F_73 ( V_6 , V_215 , V_14 ) ) {
V_14 |= V_156 ;
} else if ( V_13 -> V_142 ( V_215 ) ) {
V_215 = F_74 ( V_215 , V_14 ) ;
if ( ! V_215 )
return - V_91 ;
}
}
V_227 = F_8 ( V_6 ) ;
if ( V_227 )
return V_227 ;
V_154 = 0 ;
if ( V_6 -> V_90 != V_6 ) {
V_154 = F_60 ( V_6 -> V_90 , V_13 -> V_140 - 1 ,
V_148 , V_194 , V_124 ) ;
if ( V_154 < 0 )
return - V_91 ;
}
V_194 [ V_154 ] = V_215 ;
V_148 [ V_154 ] = V_6 ;
V_124 [ V_154 ] = V_14 ;
if ( F_39 ( V_148 , V_124 , V_154 , 1 ) )
return - V_91 ;
V_10 = & F_84 ( V_9 ) ;
V_227 = F_38 ( V_10 , V_194 , V_124 , V_154 + 1 ) ;
if ( F_65 ( V_6 ) ) {
V_10 -> V_198 = V_13 -> V_210 (
V_6 -> V_86 . V_211 ) ;
if( V_10 -> V_198 == - 1 )
return - V_226 ;
}
F_85 ( V_9 ) ;
if ( V_227 )
return - V_91 ;
V_6 -> V_163 . V_87 = V_194 [ V_154 ] ;
V_6 -> V_163 . V_201 = V_124 [ V_154 ] ;
V_6 -> V_163 . V_238 = V_6 -> V_163 . V_97 ;
F_42 ( & V_6 -> V_163 . V_168 , V_6 -> V_163 . V_238 ) ;
if ( F_7 ( V_6 ) )
F_42 ( & V_6 -> V_163 . V_166 , 0 ) ;
V_227 = 0 ;
if ( ! F_86 ( & V_218 ) ) {
F_77 ( & V_219 ) ;
if ( F_87 ( & V_218 ) == 0 &&
F_88 ( V_239 ) )
V_227 = - V_240 ;
else
F_89 ( & V_218 ) ;
F_80 ( & V_219 ) ;
}
V_6 -> V_241 = F_75 ;
return V_227 ;
}
static int F_90 ( struct V_5 * V_6 )
{
return V_6 -> V_163 . V_113 ;
}
T_5 F_91 ( struct V_242 * V_243 ,
struct V_244 * V_86 , char * V_245 )
{
struct V_246 * V_247 ;
V_247 = F_92 ( V_86 , struct V_246 , V_86 ) ;
return sprintf ( V_245 , L_4 , V_247 -> V_248 ) ;
}
static void F_93 ( struct V_5 * V_6 , unsigned long V_71 ,
struct V_1 * V_2 )
{
T_1 V_249 = V_6 -> V_163 . V_97 ;
T_4 V_161 , V_162 , V_187 ;
int V_250 = 0 ;
if ( V_6 -> V_163 . V_164 & V_165 ) {
F_37 ( V_6 -> V_163 . V_113 , 0 ) ;
return;
}
V_161 = F_43 ( & V_6 -> V_163 . V_166 ) ;
V_162 = F_40 ( V_161 , V_71 ) ;
F_46 ( V_162 , & V_6 -> V_167 ) ;
V_71 = 0 ;
V_187 = F_43 ( & V_6 -> V_163 . V_168 ) - V_162 ;
if ( V_162 == 0 )
V_187 ++ ;
if ( V_249 ) {
if ( V_187 <= 0 ) {
V_187 += V_249 ;
if ( V_187 <= 0 )
V_187 = V_249 ;
V_250 = F_6 ( V_2 ) ;
V_6 -> V_163 . V_238 = V_6 -> V_163 . V_97 ;
}
if ( V_187 < 0x80000000LL )
V_71 = 0x80000000LL - V_187 ;
}
F_37 ( V_6 -> V_163 . V_113 , V_71 ) ;
F_42 ( & V_6 -> V_163 . V_166 , V_71 ) ;
F_42 ( & V_6 -> V_163 . V_168 , V_187 ) ;
F_51 ( V_6 ) ;
if ( V_250 ) {
struct V_251 V_252 ;
F_94 ( & V_252 , ~ 0ULL , V_6 -> V_163 . V_238 ) ;
if ( V_6 -> V_86 . V_253 & V_254 )
F_2 ( V_2 , & V_252 . V_65 ) ;
if ( V_6 -> V_86 . V_253 & V_255 ) {
struct V_9 * V_10 ;
V_10 = & F_23 ( V_9 ) ;
F_15 ( V_10 ) ;
V_252 . V_256 = & V_10 -> V_83 ;
}
if ( F_95 ( V_6 , & V_252 , V_2 ) )
F_69 ( V_6 , 0 ) ;
}
}
unsigned long F_96 ( struct V_1 * V_2 )
{
T_2 V_14 = F_3 ( V_2 ) ;
if ( V_14 )
return V_14 ;
return F_97 ( V_2 ) ? V_41 :
V_46 ;
}
unsigned long F_98 ( struct V_1 * V_2 )
{
bool V_47 = F_16 ( V_2 ) ;
if ( V_47 && F_6 ( V_2 ) )
return F_17 ( V_50 ) + F_1 ( V_2 ) ;
else if ( V_47 )
return 0 ;
else
return V_2 -> V_257 ;
}
static bool F_99 ( unsigned long V_71 )
{
if ( ( 0x80000000 - V_71 ) <= 256 )
return true ;
return false ;
}
static bool F_100 ( unsigned long V_71 )
{
if ( ( int ) V_71 < 0 )
return true ;
return false ;
}
static void V_239 ( struct V_1 * V_2 )
{
int V_134 , V_135 ;
struct V_9 * V_10 = & F_23 ( V_9 ) ;
struct V_5 * V_6 ;
unsigned long V_71 [ 8 ] ;
int V_258 , V_259 ;
int V_260 ;
if ( V_10 -> V_173 )
F_49 ( V_10 , F_17 ( V_118 ) ,
F_17 ( V_119 ) ) ;
F_4 ( V_2 ) ;
V_260 = F_5 ( V_2 ) ;
if ( V_260 )
F_101 () ;
else
F_102 () ;
for ( V_134 = 0 ; V_134 < V_13 -> V_140 ; ++ V_134 )
V_71 [ V_134 ] = F_34 ( V_134 + 1 ) ;
V_258 = 0 ;
for ( V_134 = 0 ; V_134 < V_13 -> V_140 ; ++ V_134 ) {
if ( ! F_100 ( V_71 [ V_134 ] ) )
continue;
if ( F_48 ( V_134 + 1 ) )
continue;
V_258 = 1 ;
V_259 = 0 ;
for ( V_135 = 0 ; V_135 < V_10 -> V_190 ; ++ V_135 ) {
V_6 = V_10 -> V_6 [ V_135 ] ;
if ( V_6 -> V_163 . V_113 == ( V_134 + 1 ) ) {
V_259 = 1 ;
F_93 ( V_6 , V_71 [ V_134 ] , V_2 ) ;
break;
}
}
if ( ! V_259 )
F_37 ( V_134 + 1 , 0 ) ;
}
if ( ! V_258 && F_103 ( V_261 ) ) {
for ( V_134 = 0 ; V_134 < V_10 -> V_190 ; ++ V_134 ) {
V_6 = V_10 -> V_6 [ V_134 ] ;
if ( ! V_6 -> V_163 . V_113 || F_48 ( V_6 -> V_163 . V_113 ) )
continue;
if ( F_99 ( V_71 [ V_6 -> V_163 . V_113 - 1 ] ) ) {
V_258 = 1 ;
F_93 ( V_6 ,
V_71 [ V_6 -> V_163 . V_113 - 1 ] ,
V_2 ) ;
}
}
}
if ( ! V_258 && ! V_260 && F_104 () )
F_36 ( V_262 L_5 ) ;
F_52 ( V_10 , V_10 -> V_185 [ 0 ] ) ;
if ( V_260 )
F_105 () ;
else
F_106 () ;
}
static void F_107 ( int V_263 )
{
struct V_9 * V_10 = & F_108 ( V_9 , V_263 ) ;
if ( ! V_13 )
return;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_185 [ 0 ] = V_177 ;
}
static int
F_109 ( struct V_264 * V_265 , unsigned long V_266 , void * V_267 )
{
unsigned int V_263 = ( long ) V_267 ;
switch ( V_266 & ~ V_268 ) {
case V_269 :
F_107 ( V_263 ) ;
break;
default:
break;
}
return V_270 ;
}
int F_110 ( struct V_271 * V_180 )
{
if ( V_13 )
return - V_240 ;
V_13 = V_180 ;
F_111 ( L_6 ,
V_180 -> V_272 ) ;
V_271 . V_273 = V_13 -> V_273 ;
#ifdef V_42
if ( F_112 () & V_42 )
V_43 = V_44 ;
#endif
F_113 ( & V_271 , L_7 , V_234 ) ;
F_114 ( F_109 ) ;
return 0 ;
}
