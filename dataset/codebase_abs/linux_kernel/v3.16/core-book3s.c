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
static void F_16 ( bool V_8 ) { }
static bool F_17 ( struct V_1 * V_2 )
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
* V_3 = F_18 ( V_30 ) ;
}
static bool F_19 ( struct V_1 * V_2 )
{
unsigned long V_31 = V_32 ;
if ( V_13 -> V_14 & V_21 )
return ! ! ( V_2 -> V_22 & V_33 ) ;
if ( V_13 -> V_14 & V_27 )
V_31 = V_34 ;
return ! ! ( V_2 -> V_12 & V_31 ) ;
}
static bool F_20 ( struct V_1 * V_2 )
{
unsigned long V_35 = V_36 ;
if ( V_13 -> V_14 & V_21 )
return ! ! ( V_2 -> V_22 & V_37 ) ;
if ( V_13 -> V_14 & V_27 )
V_35 = V_38 ;
return ! ! ( V_2 -> V_12 & V_35 ) ;
}
static inline T_2 F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_39 & V_40 )
return V_41 ;
if ( ( V_2 -> V_39 & V_42 ) && V_43 != V_44 )
return V_45 ;
return V_46 ;
}
static inline T_2 F_3 ( struct V_1 * V_2 )
{
bool V_47 = F_17 ( V_2 ) ;
if ( ! V_47 )
return F_21 ( V_2 ) ;
if ( V_13 -> V_14 & V_48 ) {
unsigned long V_49 = F_18 ( V_50 ) ;
if ( V_49 >= V_51 )
return V_46 ;
return V_41 ;
}
if ( F_20 ( V_2 ) )
return V_41 ;
if ( F_19 ( V_2 ) && ( V_43 != V_44 ) )
return V_45 ;
return V_46 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
unsigned long V_11 = F_18 ( V_52 ) ;
int V_53 = V_11 & V_16 ;
int V_47 ;
V_2 -> V_12 = V_11 ;
if ( V_13 -> V_14 & V_21 )
V_2 -> V_22 = F_18 ( V_54 ) ;
if ( F_22 ( V_2 ) != 0xf00 )
V_47 = 0 ;
else if ( V_53 )
V_47 = 1 ;
else if ( ( V_13 -> V_14 & V_55 ) )
V_47 = 0 ;
else if ( ! ( V_13 -> V_14 & V_48 ) && F_20 ( V_2 ) )
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
static void F_23 ( void )
{
asm volatile(PPC_CLRBHRB);
}
static void F_12 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = & F_24 ( V_9 ) ;
if ( ! V_13 -> V_59 )
return;
if ( V_6 -> V_60 -> V_61 && V_10 -> V_62 != V_6 -> V_60 ) {
F_23 () ;
V_10 -> V_62 = V_6 -> V_60 ;
}
V_10 -> V_63 ++ ;
}
static void F_13 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = & F_24 ( V_9 ) ;
if ( ! V_13 -> V_59 )
return;
V_10 -> V_63 -- ;
F_25 ( V_10 -> V_63 < 0 ) ;
if ( ! V_10 -> V_64 && ! V_10 -> V_63 ) {
V_10 -> V_62 = NULL ;
}
}
void F_14 ( void )
{
if ( V_13 -> V_59 )
F_23 () ;
}
static T_3 F_26 ( T_1 V_65 )
{
unsigned int V_66 ;
int V_67 ;
T_3 V_68 ;
if ( F_27 ( V_65 ) )
return F_28 ( ( unsigned int * ) V_65 ) ;
F_29 () ;
V_67 = F_30 ( V_66 , ( unsigned int V_69 * ) V_65 ) ;
if ( V_67 ) {
F_31 () ;
return 0 ;
}
F_31 () ;
V_68 = F_28 ( & V_66 ) ;
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
V_71 = F_32 ( V_72 ++ ) ;
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
V_71 = F_32 ( V_72 ++ ) ;
V_65 = V_71 & V_75 ;
if ( V_71 & V_77 ) {
V_72 -- ;
V_65 = 0 ;
}
V_10 -> V_78 [ V_73 ] . V_82 = V_65 ;
} else {
V_10 -> V_78 [ V_73 ] . V_82 = V_65 ;
V_10 -> V_78 [ V_73 ] . V_79 =
F_26 ( V_65 ) ;
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
if ( V_6 -> V_86 . V_96 ||
V_6 -> V_86 . V_97 ||
V_6 -> V_86 . V_98 ||
V_6 -> V_86 . V_99 ||
V_6 -> V_86 . V_100 )
return - V_91 ;
}
return 0 ;
}
static void F_9 ( struct V_5 * V_6 )
{
if ( ! F_7 ( V_6 ) || V_101 -> V_102 . V_103 )
return;
V_101 -> V_102 . V_103 = 1 ;
V_101 -> V_102 . V_7 |= V_104 ;
}
static void F_10 ( unsigned long V_7 )
{
if ( ! ( V_7 & V_105 ) )
return;
V_101 -> V_102 . V_49 = F_18 ( V_50 ) ;
V_101 -> V_102 . V_106 = F_18 ( V_54 ) ;
V_101 -> V_102 . V_107 = F_18 ( V_30 ) ;
V_101 -> V_102 . V_7 = V_7 & V_108 ;
V_101 -> V_102 . V_109 = F_18 ( V_110 ) & V_111 ;
}
static unsigned long F_11 ( bool V_8 , unsigned long V_7 )
{
if ( ! V_8 )
goto V_112;
V_7 |= V_105 | V_113 | V_114 ;
V_7 |= V_101 -> V_102 . V_7 ;
if ( ! ( V_101 -> V_102 . V_7 & V_104 ) )
V_7 &= ~ V_104 ;
F_33 ( V_50 , V_101 -> V_102 . V_49 ) ;
F_33 ( V_54 , V_101 -> V_102 . V_106 ) ;
F_33 ( V_30 , V_101 -> V_102 . V_107 ) ;
F_33 ( V_110 , V_101 -> V_102 . V_109 ) ;
V_112:
return V_7 ;
}
static void F_16 ( bool V_8 )
{
unsigned V_115 [ 6 ] ;
if ( ! F_34 ( V_116 ) )
return;
if ( ( V_101 -> V_102 . V_7 & ( V_117 | V_118 ) ) != V_117 )
return;
if ( V_8 && ! ( V_101 -> V_102 . V_119 & V_120 ) )
return;
F_35 () ;
V_115 [ 0 ] = F_18 ( V_121 ) ;
V_115 [ 1 ] = F_18 ( V_122 ) ;
V_115 [ 2 ] = F_18 ( V_123 ) ;
V_115 [ 3 ] = F_18 ( V_124 ) ;
V_115 [ 4 ] = F_18 ( V_125 ) ;
V_115 [ 5 ] = F_18 ( V_126 ) ;
F_33 ( V_110 , 0 ) ;
F_33 ( V_126 , 0x7FFFFFFE ) ;
F_33 ( V_127 , V_104 | V_128 | V_117 ) ;
F_33 ( V_127 , V_129 | V_117 ) ;
F_33 ( V_121 , V_115 [ 0 ] ) ;
F_33 ( V_122 , V_115 [ 1 ] ) ;
F_33 ( V_123 , V_115 [ 2 ] ) ;
F_33 ( V_124 , V_115 [ 3 ] ) ;
F_33 ( V_125 , V_115 [ 4 ] ) ;
F_33 ( V_126 , V_115 [ 5 ] ) ;
}
static unsigned long F_36 ( int V_130 )
{
unsigned long V_71 ;
switch ( V_130 ) {
case 1 :
V_71 = F_18 ( V_121 ) ;
break;
case 2 :
V_71 = F_18 ( V_122 ) ;
break;
case 3 :
V_71 = F_18 ( V_123 ) ;
break;
case 4 :
V_71 = F_18 ( V_124 ) ;
break;
case 5 :
V_71 = F_18 ( V_125 ) ;
break;
case 6 :
V_71 = F_18 ( V_126 ) ;
break;
#ifdef F_37
case 7 :
V_71 = F_18 ( V_131 ) ;
break;
case 8 :
V_71 = F_18 ( V_132 ) ;
break;
#endif
default:
F_38 ( V_133 L_1 , V_130 ) ;
V_71 = 0 ;
}
return V_71 ;
}
static void F_39 ( int V_130 , unsigned long V_71 )
{
switch ( V_130 ) {
case 1 :
F_33 ( V_121 , V_71 ) ;
break;
case 2 :
F_33 ( V_122 , V_71 ) ;
break;
case 3 :
F_33 ( V_123 , V_71 ) ;
break;
case 4 :
F_33 ( V_124 , V_71 ) ;
break;
case 5 :
F_33 ( V_125 , V_71 ) ;
break;
case 6 :
F_33 ( V_126 , V_71 ) ;
break;
#ifdef F_37
case 7 :
F_33 ( V_131 , V_71 ) ;
break;
case 8 :
F_33 ( V_132 , V_71 ) ;
break;
#endif
default:
F_38 ( V_133 L_2 , V_130 ) ;
}
}
void F_40 ( void )
{
unsigned long V_107 , V_106 , V_14 ;
T_2 V_115 [ V_134 ] ;
int V_135 ;
if ( ! V_13 -> V_136 )
return;
F_41 ( V_14 ) ;
F_42 ( L_3 ,
F_43 () , V_13 -> V_137 , V_13 -> V_136 ) ;
for ( V_135 = 0 ; V_135 < V_13 -> V_136 ; V_135 ++ )
V_115 [ V_135 ] = F_36 ( V_135 + 1 ) ;
for (; V_135 < V_134 ; V_135 ++ )
V_115 [ V_135 ] = 0xdeadbeef ;
F_42 ( L_4 ,
V_115 [ 0 ] , V_115 [ 1 ] , V_115 [ 2 ] , V_115 [ 3 ] ) ;
if ( V_13 -> V_136 > 4 )
F_42 ( L_5 ,
V_115 [ 4 ] , V_115 [ 5 ] , V_115 [ 6 ] , V_115 [ 7 ] ) ;
F_42 ( L_6 ,
F_18 ( V_127 ) , F_18 ( V_138 ) , F_18 ( V_52 ) ) ;
V_107 = V_106 = 0 ;
#ifdef F_37
V_107 = F_18 ( V_30 ) ;
if ( V_13 -> V_14 & V_21 )
V_106 = F_18 ( V_54 ) ;
if ( V_13 -> V_14 & V_85 ) {
F_42 ( L_7 ,
F_18 ( V_110 ) , F_18 ( V_139 ) ) ;
F_42 ( L_8 ,
F_18 ( V_140 ) , F_18 ( V_141 ) ) ;
}
#endif
F_42 ( L_9 ,
F_18 ( V_50 ) , V_107 , V_106 ) ;
F_44 ( V_14 ) ;
}
static int F_45 ( struct V_9 * V_10 ,
T_1 V_142 [] , unsigned int V_143 [] ,
int V_144 )
{
unsigned long V_145 , V_146 , V_147 ;
unsigned long V_148 [ V_134 ] , V_149 [ V_134 ] ;
int V_150 [ V_134 ] , V_151 [ V_134 ] ;
int V_135 , V_152 ;
unsigned long V_153 = V_13 -> V_154 ;
unsigned long V_155 = V_13 -> V_156 ;
if ( V_144 > V_13 -> V_136 )
return - 1 ;
for ( V_135 = 0 ; V_135 < V_144 ; ++ V_135 ) {
if ( ( V_143 [ V_135 ] & V_157 )
&& ! V_13 -> V_158 ( V_142 [ V_135 ] ) ) {
V_13 -> V_159 ( V_142 [ V_135 ] , V_143 [ V_135 ] ,
V_10 -> V_160 [ V_135 ] ) ;
V_142 [ V_135 ] = V_10 -> V_160 [ V_135 ] [ 0 ] ;
}
if ( V_13 -> V_161 ( V_142 [ V_135 ] , & V_10 -> V_162 [ V_135 ] [ 0 ] ,
& V_10 -> V_163 [ V_135 ] [ 0 ] ) )
return - 1 ;
}
V_146 = V_145 = 0 ;
for ( V_135 = 0 ; V_135 < V_144 ; ++ V_135 ) {
V_147 = ( V_146 | V_10 -> V_163 [ V_135 ] [ 0 ] ) +
( V_146 & V_10 -> V_163 [ V_135 ] [ 0 ] & V_153 ) ;
if ( ( ( ( V_147 + V_155 ) ^ V_146 ) & V_145 ) != 0 ||
( ( ( V_147 + V_155 ) ^ V_10 -> V_163 [ V_135 ] [ 0 ] ) &
V_10 -> V_162 [ V_135 ] [ 0 ] ) != 0 )
break;
V_146 = V_147 ;
V_145 |= V_10 -> V_162 [ V_135 ] [ 0 ] ;
}
if ( V_135 == V_144 )
return 0 ;
if ( ! V_13 -> V_159 )
return - 1 ;
for ( V_135 = 0 ; V_135 < V_144 ; ++ V_135 ) {
V_151 [ V_135 ] = 0 ;
V_150 [ V_135 ] = V_13 -> V_159 ( V_142 [ V_135 ] , V_143 [ V_135 ] ,
V_10 -> V_160 [ V_135 ] ) ;
for ( V_152 = 1 ; V_152 < V_150 [ V_135 ] ; ++ V_152 )
V_13 -> V_161 ( V_10 -> V_160 [ V_135 ] [ V_152 ] ,
& V_10 -> V_162 [ V_135 ] [ V_152 ] ,
& V_10 -> V_163 [ V_135 ] [ V_152 ] ) ;
}
V_135 = 0 ;
V_152 = - 1 ;
V_146 = V_145 = V_147 = 0 ;
while ( V_135 < V_144 ) {
if ( V_152 >= 0 ) {
V_146 = V_149 [ V_135 ] ;
V_145 = V_148 [ V_135 ] ;
V_152 = V_151 [ V_135 ] ;
}
while ( ++ V_152 < V_150 [ V_135 ] ) {
V_147 = ( V_146 | V_10 -> V_163 [ V_135 ] [ V_152 ] ) +
( V_146 & V_10 -> V_163 [ V_135 ] [ V_152 ] & V_153 ) ;
if ( ( ( ( V_147 + V_155 ) ^ V_146 ) & V_145 ) == 0 &&
( ( ( V_147 + V_155 ) ^ V_10 -> V_163 [ V_135 ] [ V_152 ] )
& V_10 -> V_162 [ V_135 ] [ V_152 ] ) == 0 )
break;
}
if ( V_152 >= V_150 [ V_135 ] ) {
if ( -- V_135 < 0 )
return - 1 ;
} else {
V_151 [ V_135 ] = V_152 ;
V_149 [ V_135 ] = V_146 ;
V_148 [ V_135 ] = V_145 ;
V_146 = V_147 ;
V_145 |= V_10 -> V_162 [ V_135 ] [ V_152 ] ;
++ V_135 ;
V_152 = - 1 ;
}
}
for ( V_135 = 0 ; V_135 < V_144 ; ++ V_135 )
V_142 [ V_135 ] = V_10 -> V_160 [ V_135 ] [ V_151 [ V_135 ] ] ;
return 0 ;
}
static int F_46 ( struct V_5 * * V_164 , unsigned int V_143 [] ,
int V_165 , int V_166 )
{
int V_167 = 0 , V_168 = 0 , V_169 = 0 ;
int V_135 , V_170 , V_171 ;
struct V_5 * V_6 ;
V_170 = V_165 + V_166 ;
if ( V_170 <= 1 )
return 0 ;
V_171 = 1 ;
for ( V_135 = 0 ; V_135 < V_170 ; ++ V_135 ) {
if ( V_143 [ V_135 ] & V_172 ) {
V_143 [ V_135 ] &= ~ V_157 ;
continue;
}
V_6 = V_164 [ V_135 ] ;
if ( V_171 ) {
V_167 = V_6 -> V_86 . V_173 ;
V_168 = V_6 -> V_86 . V_174 ;
V_169 = V_6 -> V_86 . V_175 ;
V_171 = 0 ;
} else if ( V_6 -> V_86 . V_173 != V_167 ||
V_6 -> V_86 . V_174 != V_168 ||
V_6 -> V_86 . V_175 != V_169 ) {
return - V_176 ;
}
}
if ( V_167 || V_168 || V_169 )
for ( V_135 = 0 ; V_135 < V_170 ; ++ V_135 )
if ( V_143 [ V_135 ] & V_172 )
V_143 [ V_135 ] |= V_157 ;
return 0 ;
}
static T_1 F_47 ( T_1 V_177 , T_1 V_71 )
{
T_1 V_178 = ( V_71 - V_177 ) & 0xfffffffful ;
if ( V_177 > V_71 && ( V_177 - V_71 ) < 256 )
V_178 = 0 ;
return V_178 ;
}
static void F_48 ( struct V_5 * V_6 )
{
T_4 V_71 , V_178 , V_177 ;
if ( V_6 -> V_179 . V_180 & V_181 )
return;
if ( ! V_6 -> V_179 . V_130 )
return;
if ( F_7 ( V_6 ) ) {
V_71 = F_36 ( V_6 -> V_179 . V_130 ) ;
F_49 ( & V_6 -> V_179 . V_182 , V_71 ) ;
return;
}
do {
V_177 = F_50 ( & V_6 -> V_179 . V_182 ) ;
F_51 () ;
V_71 = F_36 ( V_6 -> V_179 . V_130 ) ;
V_178 = F_47 ( V_177 , V_71 ) ;
if ( ! V_178 )
return;
} while ( F_52 ( & V_6 -> V_179 . V_182 , V_177 , V_71 ) != V_177 );
F_53 ( V_178 , & V_6 -> V_183 ) ;
do {
V_177 = F_50 ( & V_6 -> V_179 . V_184 ) ;
V_71 = V_177 - V_178 ;
if ( V_71 < 1 )
V_71 = 1 ;
} while ( F_52 ( & V_6 -> V_179 . V_184 , V_177 , V_71 ) != V_177 );
}
static int F_54 ( int V_185 )
{
return ( V_13 -> V_14 & V_186 )
&& ( V_185 == 5 || V_185 == 6 ) ;
}
static void F_55 ( struct V_9 * V_10 ,
unsigned long V_187 , unsigned long V_188 )
{
struct V_5 * V_6 ;
T_1 V_71 , V_177 , V_178 ;
int V_135 ;
for ( V_135 = 0 ; V_135 < V_10 -> V_189 ; ++ V_135 ) {
V_6 = V_10 -> V_190 [ V_135 ] ;
if ( ! V_6 -> V_179 . V_130 )
continue;
V_71 = ( V_6 -> V_179 . V_130 == 5 ) ? V_187 : V_188 ;
V_177 = F_50 ( & V_6 -> V_179 . V_182 ) ;
V_6 -> V_179 . V_130 = 0 ;
V_178 = F_47 ( V_177 , V_71 ) ;
if ( V_178 )
F_53 ( V_178 , & V_6 -> V_183 ) ;
}
}
static void F_56 ( struct V_9 * V_10 ,
unsigned long V_187 , unsigned long V_188 )
{
struct V_5 * V_6 ;
T_1 V_71 , V_177 ;
int V_135 ;
for ( V_135 = 0 ; V_135 < V_10 -> V_189 ; ++ V_135 ) {
V_6 = V_10 -> V_190 [ V_135 ] ;
V_6 -> V_179 . V_130 = V_10 -> V_191 [ V_135 ] ;
V_71 = ( V_6 -> V_179 . V_130 == 5 ) ? V_187 : V_188 ;
V_177 = F_50 ( & V_6 -> V_179 . V_182 ) ;
if ( F_47 ( V_177 , V_71 ) )
F_49 ( & V_6 -> V_179 . V_182 , V_71 ) ;
F_57 ( V_6 ) ;
}
}
static void F_58 ( struct V_9 * V_10 , unsigned long V_7 )
{
unsigned long V_187 , V_188 ;
if ( ! V_10 -> V_189 ) {
F_33 ( V_127 , V_7 ) ;
return;
}
asm volatile("mtspr %3,%2; mfspr %0,%4; mfspr %1,%5"
: "=&r" (pmc5), "=&r" (pmc6)
: "r" (mmcr0 & ~(MMCR0_PMC1CE | MMCR0_PMCjCE)),
"i" (SPRN_MMCR0),
"i" (SPRN_PMC5), "i" (SPRN_PMC6));
if ( V_7 & V_129 )
F_55 ( V_10 , V_187 , V_188 ) ;
else
F_56 ( V_10 , V_187 , V_188 ) ;
if ( V_7 & ( V_192 | V_128 ) )
F_33 ( V_127 , V_7 ) ;
}
static void F_59 ( struct V_193 * V_193 )
{
struct V_9 * V_10 ;
unsigned long V_14 , V_7 , V_71 ;
if ( ! V_13 )
return;
F_41 ( V_14 ) ;
V_10 = & F_24 ( V_9 ) ;
if ( ! V_10 -> V_64 ) {
if ( ! V_10 -> V_194 ) {
F_60 () ;
V_10 -> V_194 = 1 ;
}
V_71 = V_7 = F_18 ( V_127 ) ;
V_71 |= V_129 ;
V_71 &= ~ ( V_105 | V_113 | V_195 | V_117 |
V_196 ) ;
F_58 ( V_10 , V_71 ) ;
F_61 () ;
if ( V_10 -> V_197 [ 2 ] & V_16 ) {
F_33 ( V_52 ,
V_10 -> V_197 [ 2 ] & ~ V_16 ) ;
F_61 () ;
}
V_10 -> V_64 = 1 ;
V_10 -> V_198 = 0 ;
F_10 ( V_7 ) ;
}
F_44 ( V_14 ) ;
}
static void F_62 ( struct V_193 * V_193 )
{
struct V_5 * V_6 ;
struct V_9 * V_10 ;
unsigned long V_14 ;
long V_135 ;
unsigned long V_71 , V_7 ;
T_4 V_199 ;
unsigned int V_200 [ V_134 ] ;
int V_201 ;
int V_130 ;
bool V_8 ;
if ( ! V_13 )
return;
F_41 ( V_14 ) ;
V_10 = & F_24 ( V_9 ) ;
if ( ! V_10 -> V_64 )
goto V_112;
if ( V_10 -> V_202 == 0 ) {
F_63 ( 0 ) ;
goto V_112;
}
V_10 -> V_64 = 0 ;
V_8 = F_7 ( V_10 -> V_6 [ 0 ] ) ;
if ( ! V_10 -> V_198 ) {
F_33 ( V_52 , V_10 -> V_197 [ 2 ] & ~ V_16 ) ;
F_33 ( V_138 , V_10 -> V_197 [ 1 ] ) ;
goto V_203;
}
if ( V_13 -> V_204 ( V_10 -> V_205 , V_10 -> V_202 , V_200 ,
V_10 -> V_197 ) ) {
F_38 ( V_133 L_10 ) ;
goto V_112;
}
V_6 = V_10 -> V_6 [ 0 ] ;
if ( V_6 -> V_86 . V_173 )
V_10 -> V_197 [ 0 ] |= V_206 ;
if ( V_6 -> V_86 . V_174 )
V_10 -> V_197 [ 0 ] |= V_43 ;
if ( V_6 -> V_86 . V_175 )
V_10 -> V_197 [ 0 ] |= V_44 ;
F_63 ( 1 ) ;
F_33 ( V_52 , V_10 -> V_197 [ 2 ] & ~ V_16 ) ;
F_33 ( V_138 , V_10 -> V_197 [ 1 ] ) ;
F_33 ( V_127 , ( V_10 -> V_197 [ 0 ] & ~ ( V_192 | V_128 ) )
| V_129 ) ;
for ( V_135 = 0 ; V_135 < V_10 -> V_202 ; ++ V_135 ) {
V_6 = V_10 -> V_6 [ V_135 ] ;
if ( V_6 -> V_179 . V_130 && V_6 -> V_179 . V_130 != V_200 [ V_135 ] + 1 ) {
F_48 ( V_6 ) ;
F_39 ( V_6 -> V_179 . V_130 , 0 ) ;
V_6 -> V_179 . V_130 = 0 ;
}
}
V_10 -> V_189 = V_201 = 0 ;
for ( V_135 = 0 ; V_135 < V_10 -> V_202 ; ++ V_135 ) {
V_6 = V_10 -> V_6 [ V_135 ] ;
if ( V_6 -> V_179 . V_130 )
continue;
V_130 = V_200 [ V_135 ] + 1 ;
if ( F_54 ( V_130 ) ) {
V_10 -> V_190 [ V_201 ] = V_6 ;
V_10 -> V_191 [ V_201 ] = V_130 ;
++ V_201 ;
continue;
}
if ( V_8 )
V_71 = F_50 ( & V_6 -> V_179 . V_182 ) ;
else {
V_71 = 0 ;
if ( V_6 -> V_179 . V_99 ) {
V_199 = F_50 ( & V_6 -> V_179 . V_184 ) ;
if ( V_199 < 0x80000000L )
V_71 = 0x80000000L - V_199 ;
}
F_49 ( & V_6 -> V_179 . V_182 , V_71 ) ;
}
V_6 -> V_179 . V_130 = V_130 ;
if ( V_6 -> V_179 . V_180 & V_181 )
V_71 = 0 ;
F_39 ( V_130 , V_71 ) ;
F_57 ( V_6 ) ;
}
V_10 -> V_189 = V_201 ;
V_10 -> V_197 [ 0 ] |= V_104 | V_207 ;
V_203:
F_16 ( V_8 ) ;
if ( V_13 -> V_14 & V_85 )
F_33 ( V_110 , 0 ) ;
V_7 = F_11 ( V_8 , V_10 -> V_197 [ 0 ] ) ;
F_61 () ;
if ( V_10 -> V_63 )
V_13 -> V_208 ( V_10 -> V_209 ) ;
F_58 ( V_10 , V_7 ) ;
if ( V_10 -> V_197 [ 2 ] & V_16 ) {
F_61 () ;
F_33 ( V_52 , V_10 -> V_197 [ 2 ] ) ;
}
V_112:
F_44 ( V_14 ) ;
}
static int F_64 ( struct V_5 * V_210 , int V_211 ,
struct V_5 * V_164 [] , T_1 * V_205 ,
unsigned int * V_14 )
{
int V_170 = 0 ;
struct V_5 * V_6 ;
if ( ! F_65 ( V_210 ) ) {
if ( V_170 >= V_211 )
return - 1 ;
V_164 [ V_170 ] = V_210 ;
V_14 [ V_170 ] = V_210 -> V_179 . V_212 ;
V_205 [ V_170 ++ ] = V_210 -> V_179 . V_87 ;
}
F_66 (event, &group->sibling_list, group_entry) {
if ( ! F_65 ( V_6 ) &&
V_6 -> V_180 != V_213 ) {
if ( V_170 >= V_211 )
return - 1 ;
V_164 [ V_170 ] = V_6 ;
V_14 [ V_170 ] = V_6 -> V_179 . V_212 ;
V_205 [ V_170 ++ ] = V_6 -> V_179 . V_87 ;
}
}
return V_170 ;
}
static int F_67 ( struct V_5 * V_6 , int V_214 )
{
struct V_9 * V_10 ;
unsigned long V_14 ;
int V_215 ;
int V_67 = - V_176 ;
F_41 ( V_14 ) ;
F_68 ( V_6 -> V_193 ) ;
V_10 = & F_24 ( V_9 ) ;
V_215 = V_10 -> V_202 ;
if ( V_215 >= V_13 -> V_136 )
goto V_112;
V_10 -> V_6 [ V_215 ] = V_6 ;
V_10 -> V_205 [ V_215 ] = V_6 -> V_179 . V_87 ;
V_10 -> V_14 [ V_215 ] = V_6 -> V_179 . V_212 ;
if ( ! ( V_214 & V_216 ) )
V_6 -> V_179 . V_180 = V_181 | V_217 ;
else
V_6 -> V_179 . V_180 = 0 ;
if ( V_10 -> V_218 & V_219 )
goto V_220;
if ( F_46 ( V_10 -> V_6 , V_10 -> V_14 , V_215 , 1 ) )
goto V_112;
if ( F_45 ( V_10 , V_10 -> V_205 , V_10 -> V_14 , V_215 + 1 ) )
goto V_112;
V_6 -> V_179 . V_87 = V_10 -> V_205 [ V_215 ] ;
V_220:
F_9 ( V_6 ) ;
++ V_10 -> V_202 ;
++ V_10 -> V_198 ;
V_67 = 0 ;
V_112:
if ( F_69 ( V_6 ) ) {
F_12 ( V_6 ) ;
V_10 -> V_209 = V_13 -> V_221 (
V_6 -> V_86 . V_222 ) ;
}
F_70 ( V_6 -> V_193 ) ;
F_44 ( V_14 ) ;
return V_67 ;
}
static void F_71 ( struct V_5 * V_6 , int V_214 )
{
struct V_9 * V_10 ;
long V_135 ;
unsigned long V_14 ;
F_41 ( V_14 ) ;
F_68 ( V_6 -> V_193 ) ;
F_48 ( V_6 ) ;
V_10 = & F_24 ( V_9 ) ;
for ( V_135 = 0 ; V_135 < V_10 -> V_202 ; ++ V_135 ) {
if ( V_6 == V_10 -> V_6 [ V_135 ] ) {
while ( ++ V_135 < V_10 -> V_202 ) {
V_10 -> V_6 [ V_135 - 1 ] = V_10 -> V_6 [ V_135 ] ;
V_10 -> V_205 [ V_135 - 1 ] = V_10 -> V_205 [ V_135 ] ;
V_10 -> V_14 [ V_135 - 1 ] = V_10 -> V_14 [ V_135 ] ;
}
-- V_10 -> V_202 ;
V_13 -> V_223 ( V_6 -> V_179 . V_130 - 1 , V_10 -> V_197 ) ;
if ( V_6 -> V_179 . V_130 ) {
F_39 ( V_6 -> V_179 . V_130 , 0 ) ;
V_6 -> V_179 . V_130 = 0 ;
}
F_57 ( V_6 ) ;
break;
}
}
for ( V_135 = 0 ; V_135 < V_10 -> V_189 ; ++ V_135 )
if ( V_6 == V_10 -> V_190 [ V_135 ] )
break;
if ( V_135 < V_10 -> V_189 ) {
while ( ++ V_135 < V_10 -> V_189 ) {
V_10 -> V_190 [ V_135 - 1 ] = V_10 -> V_190 [ V_135 ] ;
V_10 -> V_191 [ V_135 - 1 ] = V_10 -> V_191 [ V_135 ] ;
}
-- V_10 -> V_189 ;
}
if ( V_10 -> V_202 == 0 ) {
V_10 -> V_197 [ 0 ] &= ~ ( V_104 | V_207 ) ;
}
if ( F_69 ( V_6 ) )
F_13 ( V_6 ) ;
F_70 ( V_6 -> V_193 ) ;
F_44 ( V_14 ) ;
}
static void F_72 ( struct V_5 * V_6 , int V_214 )
{
unsigned long V_14 ;
T_4 V_199 ;
unsigned long V_71 ;
if ( ! V_6 -> V_179 . V_130 || ! V_6 -> V_179 . V_99 )
return;
if ( ! ( V_6 -> V_179 . V_180 & V_181 ) )
return;
if ( V_214 & V_224 )
F_25 ( ! ( V_6 -> V_179 . V_180 & V_217 ) ) ;
F_41 ( V_14 ) ;
F_68 ( V_6 -> V_193 ) ;
V_6 -> V_179 . V_180 = 0 ;
V_199 = F_50 ( & V_6 -> V_179 . V_184 ) ;
V_71 = 0 ;
if ( V_199 < 0x80000000L )
V_71 = 0x80000000L - V_199 ;
F_39 ( V_6 -> V_179 . V_130 , V_71 ) ;
F_57 ( V_6 ) ;
F_70 ( V_6 -> V_193 ) ;
F_44 ( V_14 ) ;
}
static void F_73 ( struct V_5 * V_6 , int V_214 )
{
unsigned long V_14 ;
if ( ! V_6 -> V_179 . V_130 || ! V_6 -> V_179 . V_99 )
return;
if ( V_6 -> V_179 . V_180 & V_181 )
return;
F_41 ( V_14 ) ;
F_68 ( V_6 -> V_193 ) ;
F_48 ( V_6 ) ;
V_6 -> V_179 . V_180 |= V_181 | V_217 ;
F_39 ( V_6 -> V_179 . V_130 , 0 ) ;
F_57 ( V_6 ) ;
F_70 ( V_6 -> V_193 ) ;
F_44 ( V_14 ) ;
}
void F_74 ( struct V_193 * V_193 )
{
struct V_9 * V_10 = & F_24 ( V_9 ) ;
F_68 ( V_193 ) ;
V_10 -> V_218 |= V_219 ;
V_10 -> V_225 = V_10 -> V_202 ;
}
void F_75 ( struct V_193 * V_193 )
{
struct V_9 * V_10 = & F_24 ( V_9 ) ;
V_10 -> V_218 &= ~ V_219 ;
F_70 ( V_193 ) ;
}
int F_76 ( struct V_193 * V_193 )
{
struct V_9 * V_10 ;
long V_135 , V_170 ;
if ( ! V_13 )
return - V_176 ;
V_10 = & F_24 ( V_9 ) ;
V_170 = V_10 -> V_202 ;
if ( F_46 ( V_10 -> V_6 , V_10 -> V_14 , 0 , V_170 ) )
return - V_176 ;
V_135 = F_45 ( V_10 , V_10 -> V_205 , V_10 -> V_14 , V_170 ) ;
if ( V_135 < 0 )
return - V_176 ;
for ( V_135 = V_10 -> V_225 ; V_135 < V_170 ; ++ V_135 )
V_10 -> V_6 [ V_135 ] -> V_179 . V_87 = V_10 -> V_205 [ V_135 ] ;
V_10 -> V_218 &= ~ V_219 ;
F_70 ( V_193 ) ;
return 0 ;
}
static int F_77 ( struct V_5 * V_6 , T_1 V_226 ,
unsigned int V_14 )
{
int V_170 ;
T_1 V_227 [ V_228 ] ;
if ( V_6 -> V_86 . V_173
|| V_6 -> V_86 . V_174
|| V_6 -> V_86 . V_175
|| V_6 -> V_86 . V_99 )
return 0 ;
if ( V_13 -> V_158 ( V_226 ) )
return 1 ;
if ( ! V_13 -> V_159 )
return 0 ;
V_14 |= V_172 | V_157 ;
V_170 = V_13 -> V_159 ( V_226 , V_14 , V_227 ) ;
return V_170 > 0 ;
}
static T_1 F_78 ( T_1 V_226 , unsigned long V_14 )
{
T_1 V_227 [ V_228 ] ;
int V_170 ;
V_14 &= ~ ( V_172 | V_157 ) ;
V_170 = V_13 -> V_159 ( V_226 , V_14 , V_227 ) ;
if ( ! V_170 )
return 0 ;
return V_227 [ 0 ] ;
}
static void F_79 ( struct V_5 * V_6 )
{
if ( ! F_80 ( & V_229 , - 1 , 1 ) ) {
F_81 ( & V_230 ) ;
if ( F_82 ( & V_229 ) == 0 )
F_83 () ;
F_84 ( & V_230 ) ;
}
}
static int F_85 ( T_1 V_87 , T_1 * V_231 )
{
unsigned long type , V_232 , V_4 ;
int V_226 ;
if ( ! V_13 -> V_233 )
return - V_91 ;
type = V_87 & 0xff ;
V_232 = ( V_87 >> 8 ) & 0xff ;
V_4 = ( V_87 >> 16 ) & 0xff ;
if ( type >= V_234 ||
V_232 >= V_235 ||
V_4 >= V_236 )
return - V_91 ;
V_226 = ( * V_13 -> V_233 ) [ type ] [ V_232 ] [ V_4 ] ;
if ( V_226 == 0 )
return - V_237 ;
if ( V_226 == - 1 )
return - V_91 ;
* V_231 = V_226 ;
return 0 ;
}
static int F_86 ( struct V_5 * V_6 )
{
T_1 V_226 ;
unsigned long V_14 ;
struct V_5 * V_164 [ V_134 ] ;
T_1 V_205 [ V_134 ] ;
unsigned int V_143 [ V_134 ] ;
int V_170 ;
int V_238 ;
struct V_9 * V_10 ;
if ( ! V_13 )
return - V_239 ;
if ( F_69 ( V_6 ) ) {
if ( ! ( V_13 -> V_14 & V_85 ) )
return - V_237 ;
}
switch ( V_6 -> V_86 . type ) {
case V_240 :
V_226 = V_6 -> V_86 . V_87 ;
if ( V_226 >= V_13 -> V_241 || V_13 -> V_242 [ V_226 ] == 0 )
return - V_237 ;
V_226 = V_13 -> V_242 [ V_226 ] ;
break;
case V_243 :
V_238 = F_85 ( V_6 -> V_86 . V_87 , & V_226 ) ;
if ( V_238 )
return V_238 ;
break;
case V_244 :
V_226 = V_6 -> V_86 . V_87 ;
break;
default:
return - V_239 ;
}
V_6 -> V_179 . V_245 = V_226 ;
V_6 -> V_179 . V_130 = 0 ;
if ( ! F_87 ( V_246 ) )
V_6 -> V_86 . V_175 = 0 ;
V_14 = 0 ;
if ( V_6 -> V_92 & V_93 )
V_14 |= V_247 ;
if ( V_13 -> V_14 & V_186 ) {
if ( F_77 ( V_6 , V_226 , V_14 ) ) {
V_14 |= V_172 ;
} else if ( V_13 -> V_158 ( V_226 ) ) {
V_226 = F_78 ( V_226 , V_14 ) ;
if ( ! V_226 )
return - V_91 ;
}
}
V_238 = F_8 ( V_6 ) ;
if ( V_238 )
return V_238 ;
V_170 = 0 ;
if ( V_6 -> V_90 != V_6 ) {
V_170 = F_64 ( V_6 -> V_90 , V_13 -> V_136 - 1 ,
V_164 , V_205 , V_143 ) ;
if ( V_170 < 0 )
return - V_91 ;
}
V_205 [ V_170 ] = V_226 ;
V_164 [ V_170 ] = V_6 ;
V_143 [ V_170 ] = V_14 ;
if ( F_46 ( V_164 , V_143 , V_170 , 1 ) )
return - V_91 ;
V_10 = & F_88 ( V_9 ) ;
V_238 = F_45 ( V_10 , V_205 , V_143 , V_170 + 1 ) ;
if ( F_69 ( V_6 ) ) {
V_10 -> V_209 = V_13 -> V_221 (
V_6 -> V_86 . V_222 ) ;
if( V_10 -> V_209 == - 1 )
return - V_237 ;
}
F_89 ( V_9 ) ;
if ( V_238 )
return - V_91 ;
V_6 -> V_179 . V_87 = V_205 [ V_170 ] ;
V_6 -> V_179 . V_212 = V_143 [ V_170 ] ;
V_6 -> V_179 . V_248 = V_6 -> V_179 . V_99 ;
F_49 ( & V_6 -> V_179 . V_184 , V_6 -> V_179 . V_248 ) ;
if ( F_7 ( V_6 ) )
F_49 ( & V_6 -> V_179 . V_182 , 0 ) ;
V_238 = 0 ;
if ( ! F_90 ( & V_229 ) ) {
F_81 ( & V_230 ) ;
if ( F_91 ( & V_229 ) == 0 &&
F_92 ( V_249 ) )
V_238 = - V_250 ;
else
F_93 ( & V_229 ) ;
F_84 ( & V_230 ) ;
}
V_6 -> V_251 = F_79 ;
return V_238 ;
}
static int F_94 ( struct V_5 * V_6 )
{
return V_6 -> V_179 . V_130 ;
}
T_5 F_95 ( struct V_252 * V_253 ,
struct V_254 * V_86 , char * V_255 )
{
struct V_256 * V_257 ;
V_257 = F_96 ( V_86 , struct V_256 , V_86 ) ;
return sprintf ( V_255 , L_11 , V_257 -> V_258 ) ;
}
static void F_97 ( struct V_5 * V_6 , unsigned long V_71 ,
struct V_1 * V_2 )
{
T_1 V_259 = V_6 -> V_179 . V_99 ;
T_4 V_177 , V_178 , V_199 ;
int V_260 = 0 ;
if ( V_6 -> V_179 . V_180 & V_181 ) {
F_39 ( V_6 -> V_179 . V_130 , 0 ) ;
return;
}
V_177 = F_50 ( & V_6 -> V_179 . V_182 ) ;
V_178 = F_47 ( V_177 , V_71 ) ;
F_53 ( V_178 , & V_6 -> V_183 ) ;
V_71 = 0 ;
V_199 = F_50 ( & V_6 -> V_179 . V_184 ) - V_178 ;
if ( V_178 == 0 )
V_199 ++ ;
if ( V_259 ) {
if ( V_199 <= 0 ) {
V_199 += V_259 ;
if ( V_199 <= 0 )
V_199 = V_259 ;
V_260 = F_6 ( V_2 ) ;
V_6 -> V_179 . V_248 = V_6 -> V_179 . V_99 ;
}
if ( V_199 < 0x80000000LL )
V_71 = 0x80000000LL - V_199 ;
}
F_39 ( V_6 -> V_179 . V_130 , V_71 ) ;
F_49 ( & V_6 -> V_179 . V_182 , V_71 ) ;
F_49 ( & V_6 -> V_179 . V_184 , V_199 ) ;
F_57 ( V_6 ) ;
if ( V_260 ) {
struct V_261 V_262 ;
F_98 ( & V_262 , ~ 0ULL , V_6 -> V_179 . V_248 ) ;
if ( V_6 -> V_86 . V_98 & V_263 )
F_2 ( V_2 , & V_262 . V_65 ) ;
if ( V_6 -> V_86 . V_98 & V_264 ) {
struct V_9 * V_10 ;
V_10 = & F_24 ( V_9 ) ;
F_15 ( V_10 ) ;
V_262 . V_265 = & V_10 -> V_83 ;
}
if ( F_99 ( V_6 , & V_262 , V_2 ) )
F_73 ( V_6 , 0 ) ;
}
}
unsigned long F_100 ( struct V_1 * V_2 )
{
T_2 V_14 = F_3 ( V_2 ) ;
if ( V_14 )
return V_14 ;
return F_101 ( V_2 ) ? V_41 :
V_46 ;
}
unsigned long F_102 ( struct V_1 * V_2 )
{
bool V_47 = F_17 ( V_2 ) ;
if ( V_47 && F_6 ( V_2 ) )
return F_18 ( V_50 ) + F_1 ( V_2 ) ;
else if ( V_47 )
return 0 ;
else
return V_2 -> V_266 ;
}
static bool F_103 ( unsigned long V_71 )
{
if ( ( 0x80000000 - V_71 ) <= 256 )
return true ;
return false ;
}
static bool F_104 ( unsigned long V_71 )
{
if ( ( int ) V_71 < 0 )
return true ;
return false ;
}
static void V_249 ( struct V_1 * V_2 )
{
int V_135 , V_152 ;
struct V_9 * V_10 = & F_24 ( V_9 ) ;
struct V_5 * V_6 ;
unsigned long V_71 [ 8 ] ;
int V_267 , V_268 ;
int V_269 ;
if ( V_10 -> V_189 )
F_55 ( V_10 , F_18 ( V_125 ) ,
F_18 ( V_126 ) ) ;
F_4 ( V_2 ) ;
V_269 = F_5 ( V_2 ) ;
if ( V_269 )
F_105 () ;
else
F_106 () ;
for ( V_135 = 0 ; V_135 < V_13 -> V_136 ; ++ V_135 )
V_71 [ V_135 ] = F_36 ( V_135 + 1 ) ;
V_267 = 0 ;
for ( V_135 = 0 ; V_135 < V_13 -> V_136 ; ++ V_135 ) {
if ( ! F_104 ( V_71 [ V_135 ] ) )
continue;
if ( F_54 ( V_135 + 1 ) )
continue;
V_267 = 1 ;
V_268 = 0 ;
for ( V_152 = 0 ; V_152 < V_10 -> V_202 ; ++ V_152 ) {
V_6 = V_10 -> V_6 [ V_152 ] ;
if ( V_6 -> V_179 . V_130 == ( V_135 + 1 ) ) {
V_268 = 1 ;
F_97 ( V_6 , V_71 [ V_135 ] , V_2 ) ;
break;
}
}
if ( ! V_268 )
F_39 ( V_135 + 1 , 0 ) ;
}
if ( ! V_267 && F_107 ( V_270 ) ) {
for ( V_135 = 0 ; V_135 < V_10 -> V_202 ; ++ V_135 ) {
V_6 = V_10 -> V_6 [ V_135 ] ;
if ( ! V_6 -> V_179 . V_130 || F_54 ( V_6 -> V_179 . V_130 ) )
continue;
if ( F_103 ( V_71 [ V_6 -> V_179 . V_130 - 1 ] ) ) {
V_267 = 1 ;
F_97 ( V_6 ,
V_71 [ V_6 -> V_179 . V_130 - 1 ] ,
V_2 ) ;
}
}
}
if ( ! V_267 && ! V_269 && F_108 () )
F_38 ( V_271 L_12 ) ;
F_58 ( V_10 , V_10 -> V_197 [ 0 ] ) ;
if ( V_269 )
F_109 () ;
else
F_110 () ;
}
static void F_111 ( int V_272 )
{
struct V_9 * V_10 = & F_112 ( V_9 , V_272 ) ;
if ( ! V_13 )
return;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_197 [ 0 ] = V_129 ;
}
static int
F_113 ( struct V_273 * V_274 , unsigned long V_275 , void * V_276 )
{
unsigned int V_272 = ( long ) V_276 ;
switch ( V_275 & ~ V_277 ) {
case V_278 :
F_111 ( V_272 ) ;
break;
default:
break;
}
return V_279 ;
}
int F_114 ( struct V_280 * V_193 )
{
if ( V_13 )
return - V_250 ;
V_13 = V_193 ;
F_42 ( L_13 ,
V_193 -> V_137 ) ;
V_280 . V_281 = V_13 -> V_281 ;
#ifdef V_42
if ( F_115 () & V_42 )
V_43 = V_44 ;
#endif
F_116 ( & V_280 , L_14 , V_244 ) ;
F_117 ( F_113 ) ;
return 0 ;
}
