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
static unsigned long F_11 ( bool V_8 , struct V_9 * V_10 )
{
return V_10 -> V_11 [ 0 ] ;
}
static inline void F_12 ( struct V_5 * V_6 ) {}
static inline void F_13 ( struct V_5 * V_6 ) {}
static void F_14 ( struct V_12 * V_13 , bool V_14 ) {}
static inline void F_15 ( struct V_9 * V_10 ) {}
static void F_16 ( bool V_8 ) { }
static bool F_17 ( T_1 V_6 )
{
return false ;
}
static bool F_18 ( struct V_1 * V_2 )
{
return ( ( F_19 ( V_2 ) == 0xf00 ) && V_2 -> V_4 ) ;
}
static inline unsigned long F_1 ( struct V_1 * V_2 )
{
unsigned long V_15 = V_2 -> V_16 ;
if ( ( V_17 -> V_18 & V_19 ) && ( V_15 & V_20 ) ) {
unsigned long V_21 = ( V_15 & V_22 ) >> V_23 ;
if ( V_21 > 1 )
return 4 * ( V_21 - 1 ) ;
}
return 0 ;
}
static inline void F_2 ( struct V_1 * V_2 , T_1 * V_3 )
{
unsigned long V_15 = V_2 -> V_16 ;
bool V_24 ;
if ( V_17 -> V_18 & V_25 )
V_24 = V_2 -> V_26 & V_27 ;
else {
unsigned long V_28 ;
if ( V_17 -> V_18 & V_29 )
V_28 = V_30 ;
else if ( V_17 -> V_18 & V_31 )
V_28 = V_32 ;
else if ( V_17 -> V_18 & V_33 )
V_28 = V_20 ;
else
V_28 = V_34 ;
V_24 = V_15 & V_28 ;
}
if ( ! ( V_15 & V_20 ) || V_24 )
* V_3 = F_20 ( V_35 ) ;
}
static bool F_21 ( struct V_1 * V_2 )
{
unsigned long V_36 = V_37 ;
if ( V_17 -> V_18 & V_25 )
return ! ! ( V_2 -> V_26 & V_38 ) ;
if ( V_17 -> V_18 & V_31 )
V_36 = V_39 ;
return ! ! ( V_2 -> V_16 & V_36 ) ;
}
static bool F_22 ( struct V_1 * V_2 )
{
unsigned long V_40 = V_41 ;
if ( V_17 -> V_18 & V_25 )
return ! ! ( V_2 -> V_26 & V_42 ) ;
if ( V_17 -> V_18 & V_31 )
V_40 = V_43 ;
return ! ! ( V_2 -> V_16 & V_40 ) ;
}
static inline T_2 F_23 ( struct V_1 * V_2 )
{
if ( V_2 -> V_44 & V_45 )
return V_46 ;
if ( ( V_2 -> V_44 & V_47 ) && V_48 != V_49 )
return V_50 ;
return V_51 ;
}
static inline T_2 F_3 ( struct V_1 * V_2 )
{
bool V_52 = F_18 ( V_2 ) ;
if ( ! V_52 )
return F_23 ( V_2 ) ;
if ( V_17 -> V_18 & V_53 ) {
unsigned long V_54 = F_20 ( V_55 ) ;
if ( F_24 ( V_54 ) )
return V_51 ;
return V_46 ;
}
if ( F_22 ( V_2 ) )
return V_46 ;
if ( F_21 ( V_2 ) && ( V_48 != V_49 ) )
return V_50 ;
return V_51 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
unsigned long V_15 = F_20 ( V_56 ) ;
int V_57 = V_15 & V_20 ;
int V_52 ;
V_2 -> V_16 = V_15 ;
if ( V_17 -> V_18 & V_25 )
V_2 -> V_26 = F_20 ( V_58 ) ;
if ( F_19 ( V_2 ) != 0xf00 )
V_52 = 0 ;
else if ( ( V_17 -> V_18 & V_33 ) )
V_52 = 0 ;
else if ( V_57 )
V_52 = 1 ;
else if ( ( V_17 -> V_18 & V_59 ) )
V_52 = 0 ;
else if ( ! ( V_17 -> V_18 & V_53 ) && F_22 ( V_2 ) )
V_52 = 0 ;
else
V_52 = 1 ;
V_2 -> V_4 = V_52 ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
return ! V_2 -> V_60 ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
unsigned long V_15 = V_2 -> V_16 ;
int V_57 = V_15 & V_20 ;
if ( V_57 ) {
if ( V_17 -> V_18 & V_25 )
return V_2 -> V_26 & V_61 ;
if ( V_17 -> V_18 & V_29 )
return V_15 & V_62 ;
}
return 1 ;
}
static void F_25 ( void )
{
asm volatile(PPC_CLRBHRB);
}
static void F_12 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_26 ( & V_9 ) ;
if ( ! V_17 -> V_63 )
return;
if ( V_6 -> V_13 -> V_64 && V_10 -> V_65 != V_6 -> V_13 ) {
F_25 () ;
V_10 -> V_65 = V_6 -> V_13 ;
}
V_10 -> V_66 ++ ;
F_27 ( V_6 -> V_13 -> V_67 ) ;
}
static void F_13 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_26 ( & V_9 ) ;
if ( ! V_17 -> V_63 )
return;
F_28 ( ! V_10 -> V_66 ) ;
V_10 -> V_66 -- ;
F_29 ( V_6 -> V_13 -> V_67 ) ;
if ( ! V_10 -> V_68 && ! V_10 -> V_66 ) {
V_10 -> V_65 = NULL ;
}
}
static void F_14 ( struct V_12 * V_13 , bool V_14 )
{
if ( ! V_17 -> V_63 )
return;
if ( V_14 )
F_25 () ;
}
static T_3 F_30 ( T_1 V_69 )
{
unsigned int V_70 ;
int V_71 ;
T_3 V_72 ;
if ( F_24 ( V_69 ) )
return F_31 ( ( unsigned int * ) V_69 ) ;
F_32 () ;
V_71 = F_33 ( V_70 , ( unsigned int V_73 * ) V_69 ) ;
if ( V_71 ) {
F_34 () ;
return 0 ;
}
F_34 () ;
V_72 = F_31 ( & V_70 ) ;
if ( ( ! V_72 ) || ( V_70 & V_74 ) )
return V_72 ;
return V_72 - ( unsigned long ) & V_70 + V_69 ;
}
static void F_15 ( struct V_9 * V_10 )
{
T_1 V_75 ;
T_1 V_69 ;
int V_76 , V_77 , V_78 ;
V_76 = 0 ;
V_77 = 0 ;
while ( V_76 < V_17 -> V_63 ) {
V_75 = F_35 ( V_76 ++ ) ;
if ( ! V_75 )
break;
else {
V_69 = V_75 & V_79 ;
V_78 = V_75 & V_80 ;
if ( ! V_69 )
continue;
if ( V_75 & V_81 ) {
V_10 -> V_82 [ V_77 ] . V_83 = V_69 ;
V_10 -> V_82 [ V_77 ] . V_84 = V_78 ;
V_10 -> V_82 [ V_77 ] . V_85 = ~ V_78 ;
V_75 = F_35 ( V_76 ++ ) ;
V_69 = V_75 & V_79 ;
if ( V_75 & V_81 ) {
V_76 -- ;
V_69 = 0 ;
}
V_10 -> V_82 [ V_77 ] . V_86 = V_69 ;
} else {
V_10 -> V_82 [ V_77 ] . V_86 = V_69 ;
V_10 -> V_82 [ V_77 ] . V_83 =
F_30 ( V_69 ) ;
V_10 -> V_82 [ V_77 ] . V_84 = V_78 ;
V_10 -> V_82 [ V_77 ] . V_85 = ~ V_78 ;
}
V_77 ++ ;
}
}
V_10 -> V_87 . V_88 = V_77 ;
return;
}
static bool F_7 ( struct V_5 * V_6 )
{
return ( V_17 -> V_18 & V_89 ) &&
( ( V_6 -> V_90 . V_91 >> V_92 ) & 1 ) ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_5 * V_93 = V_6 -> V_94 ;
if ( F_7 ( V_93 ) != F_7 ( V_6 ) )
return - V_95 ;
if ( F_7 ( V_6 ) ) {
if ( ! ( V_6 -> V_96 & V_97 ) )
return - V_95 ;
if ( ! V_93 -> V_90 . V_98 || ! V_93 -> V_90 . V_99 )
return - V_95 ;
if ( V_6 -> V_90 . V_100 ||
V_6 -> V_90 . V_101 ||
V_6 -> V_90 . V_102 ||
V_6 -> V_90 . V_103 ||
V_6 -> V_90 . V_104 )
return - V_95 ;
}
return 0 ;
}
static void F_9 ( struct V_5 * V_6 )
{
if ( ! F_7 ( V_6 ) || V_105 -> V_106 . V_107 )
return;
V_105 -> V_106 . V_107 = 1 ;
V_105 -> V_106 . V_7 |= V_108 ;
}
static void F_10 ( unsigned long V_7 )
{
if ( ! ( V_7 & V_109 ) )
return;
V_105 -> V_106 . V_54 = F_20 ( V_55 ) ;
V_105 -> V_106 . V_110 = F_20 ( V_58 ) ;
V_105 -> V_106 . V_111 = F_20 ( V_35 ) ;
V_105 -> V_106 . V_7 = V_7 & V_112 ;
V_105 -> V_106 . V_113 = F_20 ( V_114 ) & V_115 ;
}
static unsigned long F_11 ( bool V_8 , struct V_9 * V_10 )
{
unsigned long V_7 = V_10 -> V_11 [ 0 ] ;
if ( ! V_8 )
goto V_116;
V_7 |= V_109 | V_117 | V_118 ;
V_7 |= V_105 -> V_106 . V_7 ;
if ( ! ( V_105 -> V_106 . V_7 & V_108 ) )
V_7 &= ~ V_108 ;
F_36 ( V_55 , V_105 -> V_106 . V_54 ) ;
F_36 ( V_58 , V_105 -> V_106 . V_110 ) ;
F_36 ( V_35 , V_105 -> V_106 . V_111 ) ;
F_36 ( V_114 , V_10 -> V_11 [ 3 ] | V_105 -> V_106 . V_113 ) ;
V_116:
return V_7 ;
}
static void F_16 ( bool V_8 )
{
unsigned V_119 [ 6 ] ;
if ( ! F_37 ( V_120 ) )
return;
if ( ( V_105 -> V_106 . V_7 & ( V_121 | V_122 ) ) != V_121 )
return;
if ( V_8 && ! ( V_105 -> V_106 . V_123 & V_124 ) )
return;
F_38 () ;
V_119 [ 0 ] = F_20 ( V_125 ) ;
V_119 [ 1 ] = F_20 ( V_126 ) ;
V_119 [ 2 ] = F_20 ( V_127 ) ;
V_119 [ 3 ] = F_20 ( V_128 ) ;
V_119 [ 4 ] = F_20 ( V_129 ) ;
V_119 [ 5 ] = F_20 ( V_130 ) ;
F_36 ( V_114 , 0 ) ;
F_36 ( V_130 , 0x7FFFFFFE ) ;
F_36 ( V_131 , V_108 | V_132 | V_121 ) ;
F_36 ( V_131 , V_133 | V_121 ) ;
F_36 ( V_125 , V_119 [ 0 ] ) ;
F_36 ( V_126 , V_119 [ 1 ] ) ;
F_36 ( V_127 , V_119 [ 2 ] ) ;
F_36 ( V_128 , V_119 [ 3 ] ) ;
F_36 ( V_129 , V_119 [ 4 ] ) ;
F_36 ( V_130 , V_119 [ 5 ] ) ;
}
static bool F_17 ( T_1 V_6 )
{
if ( F_37 ( V_134 ) &&
( V_6 == 0x200f2 || V_6 == 0x300f2 ) )
return true ;
return false ;
}
static unsigned long F_39 ( int V_135 )
{
unsigned long V_75 ;
switch ( V_135 ) {
case 1 :
V_75 = F_20 ( V_125 ) ;
break;
case 2 :
V_75 = F_20 ( V_126 ) ;
break;
case 3 :
V_75 = F_20 ( V_127 ) ;
break;
case 4 :
V_75 = F_20 ( V_128 ) ;
break;
case 5 :
V_75 = F_20 ( V_129 ) ;
break;
case 6 :
V_75 = F_20 ( V_130 ) ;
break;
#ifdef F_40
case 7 :
V_75 = F_20 ( V_136 ) ;
break;
case 8 :
V_75 = F_20 ( V_137 ) ;
break;
#endif
default:
F_41 ( V_138 L_1 , V_135 ) ;
V_75 = 0 ;
}
return V_75 ;
}
static void F_42 ( int V_135 , unsigned long V_75 )
{
switch ( V_135 ) {
case 1 :
F_36 ( V_125 , V_75 ) ;
break;
case 2 :
F_36 ( V_126 , V_75 ) ;
break;
case 3 :
F_36 ( V_127 , V_75 ) ;
break;
case 4 :
F_36 ( V_128 , V_75 ) ;
break;
case 5 :
F_36 ( V_129 , V_75 ) ;
break;
case 6 :
F_36 ( V_130 , V_75 ) ;
break;
#ifdef F_40
case 7 :
F_36 ( V_136 , V_75 ) ;
break;
case 8 :
F_36 ( V_137 , V_75 ) ;
break;
#endif
default:
F_41 ( V_138 L_2 , V_135 ) ;
}
}
void F_43 ( void )
{
unsigned long V_111 , V_110 , V_18 ;
T_2 V_119 [ V_139 ] ;
int V_140 ;
if ( ! V_17 -> V_141 )
return;
F_44 ( V_18 ) ;
F_45 ( L_3 ,
F_46 () , V_17 -> V_142 , V_17 -> V_141 ) ;
for ( V_140 = 0 ; V_140 < V_17 -> V_141 ; V_140 ++ )
V_119 [ V_140 ] = F_39 ( V_140 + 1 ) ;
for (; V_140 < V_139 ; V_140 ++ )
V_119 [ V_140 ] = 0xdeadbeef ;
F_45 ( L_4 ,
V_119 [ 0 ] , V_119 [ 1 ] , V_119 [ 2 ] , V_119 [ 3 ] ) ;
if ( V_17 -> V_141 > 4 )
F_45 ( L_5 ,
V_119 [ 4 ] , V_119 [ 5 ] , V_119 [ 6 ] , V_119 [ 7 ] ) ;
F_45 ( L_6 ,
F_20 ( V_131 ) , F_20 ( V_143 ) , F_20 ( V_56 ) ) ;
V_111 = V_110 = 0 ;
#ifdef F_40
V_111 = F_20 ( V_35 ) ;
if ( V_17 -> V_18 & V_25 )
V_110 = F_20 ( V_58 ) ;
if ( V_17 -> V_18 & V_89 ) {
F_45 ( L_7 ,
F_20 ( V_114 ) , F_20 ( V_144 ) ) ;
F_45 ( L_8 ,
F_20 ( V_145 ) , F_20 ( V_146 ) ) ;
}
#endif
F_45 ( L_9 ,
F_20 ( V_55 ) , V_111 , V_110 ) ;
F_47 ( V_18 ) ;
}
static int F_48 ( struct V_9 * V_10 ,
T_1 V_147 [] , unsigned int V_148 [] ,
int V_149 )
{
unsigned long V_150 , V_151 , V_152 ;
unsigned long V_153 [ V_139 ] , V_154 [ V_139 ] ;
int V_155 [ V_139 ] , V_156 [ V_139 ] ;
int V_140 , V_157 ;
unsigned long V_158 = V_17 -> V_159 ;
unsigned long V_160 = V_17 -> V_161 ;
if ( V_149 > V_17 -> V_141 )
return - 1 ;
for ( V_140 = 0 ; V_140 < V_149 ; ++ V_140 ) {
if ( ( V_148 [ V_140 ] & V_162 )
&& ! V_17 -> V_163 ( V_147 [ V_140 ] ) ) {
V_17 -> V_164 ( V_147 [ V_140 ] , V_148 [ V_140 ] ,
V_10 -> V_165 [ V_140 ] ) ;
V_147 [ V_140 ] = V_10 -> V_165 [ V_140 ] [ 0 ] ;
}
if ( V_17 -> V_166 ( V_147 [ V_140 ] , & V_10 -> V_167 [ V_140 ] [ 0 ] ,
& V_10 -> V_168 [ V_140 ] [ 0 ] ) )
return - 1 ;
}
V_151 = V_150 = 0 ;
for ( V_140 = 0 ; V_140 < V_149 ; ++ V_140 ) {
V_152 = ( V_151 | V_10 -> V_168 [ V_140 ] [ 0 ] ) +
( V_151 & V_10 -> V_168 [ V_140 ] [ 0 ] & V_158 ) ;
if ( ( ( ( V_152 + V_160 ) ^ V_151 ) & V_150 ) != 0 ||
( ( ( V_152 + V_160 ) ^ V_10 -> V_168 [ V_140 ] [ 0 ] ) &
V_10 -> V_167 [ V_140 ] [ 0 ] ) != 0 )
break;
V_151 = V_152 ;
V_150 |= V_10 -> V_167 [ V_140 ] [ 0 ] ;
}
if ( V_140 == V_149 )
return 0 ;
if ( ! V_17 -> V_164 )
return - 1 ;
for ( V_140 = 0 ; V_140 < V_149 ; ++ V_140 ) {
V_156 [ V_140 ] = 0 ;
V_155 [ V_140 ] = V_17 -> V_164 ( V_147 [ V_140 ] , V_148 [ V_140 ] ,
V_10 -> V_165 [ V_140 ] ) ;
for ( V_157 = 1 ; V_157 < V_155 [ V_140 ] ; ++ V_157 )
V_17 -> V_166 ( V_10 -> V_165 [ V_140 ] [ V_157 ] ,
& V_10 -> V_167 [ V_140 ] [ V_157 ] ,
& V_10 -> V_168 [ V_140 ] [ V_157 ] ) ;
}
V_140 = 0 ;
V_157 = - 1 ;
V_151 = V_150 = V_152 = 0 ;
while ( V_140 < V_149 ) {
if ( V_157 >= 0 ) {
V_151 = V_154 [ V_140 ] ;
V_150 = V_153 [ V_140 ] ;
V_157 = V_156 [ V_140 ] ;
}
while ( ++ V_157 < V_155 [ V_140 ] ) {
V_152 = ( V_151 | V_10 -> V_168 [ V_140 ] [ V_157 ] ) +
( V_151 & V_10 -> V_168 [ V_140 ] [ V_157 ] & V_158 ) ;
if ( ( ( ( V_152 + V_160 ) ^ V_151 ) & V_150 ) == 0 &&
( ( ( V_152 + V_160 ) ^ V_10 -> V_168 [ V_140 ] [ V_157 ] )
& V_10 -> V_167 [ V_140 ] [ V_157 ] ) == 0 )
break;
}
if ( V_157 >= V_155 [ V_140 ] ) {
if ( -- V_140 < 0 )
return - 1 ;
} else {
V_156 [ V_140 ] = V_157 ;
V_154 [ V_140 ] = V_151 ;
V_153 [ V_140 ] = V_150 ;
V_151 = V_152 ;
V_150 |= V_10 -> V_167 [ V_140 ] [ V_157 ] ;
++ V_140 ;
V_157 = - 1 ;
}
}
for ( V_140 = 0 ; V_140 < V_149 ; ++ V_140 )
V_147 [ V_140 ] = V_10 -> V_165 [ V_140 ] [ V_156 [ V_140 ] ] ;
return 0 ;
}
static int F_49 ( struct V_5 * * V_169 , unsigned int V_148 [] ,
int V_170 , int V_171 )
{
int V_172 = 0 , V_173 = 0 , V_174 = 0 ;
int V_140 , V_175 , V_176 ;
struct V_5 * V_6 ;
if ( V_17 -> V_18 & V_89 )
return 0 ;
V_175 = V_170 + V_171 ;
if ( V_175 <= 1 )
return 0 ;
V_176 = 1 ;
for ( V_140 = 0 ; V_140 < V_175 ; ++ V_140 ) {
if ( V_148 [ V_140 ] & V_177 ) {
V_148 [ V_140 ] &= ~ V_162 ;
continue;
}
V_6 = V_169 [ V_140 ] ;
if ( V_176 ) {
V_172 = V_6 -> V_90 . V_178 ;
V_173 = V_6 -> V_90 . V_179 ;
V_174 = V_6 -> V_90 . V_180 ;
V_176 = 0 ;
} else if ( V_6 -> V_90 . V_178 != V_172 ||
V_6 -> V_90 . V_179 != V_173 ||
V_6 -> V_90 . V_180 != V_174 ) {
return - V_181 ;
}
}
if ( V_172 || V_173 || V_174 )
for ( V_140 = 0 ; V_140 < V_175 ; ++ V_140 )
if ( V_148 [ V_140 ] & V_177 )
V_148 [ V_140 ] |= V_162 ;
return 0 ;
}
static T_1 F_50 ( T_1 V_182 , T_1 V_75 )
{
T_1 V_183 = ( V_75 - V_182 ) & 0xfffffffful ;
if ( V_182 > V_75 && ( V_182 - V_75 ) < 256 )
V_183 = 0 ;
return V_183 ;
}
static void F_51 ( struct V_5 * V_6 )
{
T_4 V_75 , V_183 , V_182 ;
struct V_9 * V_10 = F_26 ( & V_9 ) ;
if ( V_6 -> V_184 . V_185 & V_186 )
return;
if ( ! V_6 -> V_184 . V_135 )
return;
if ( F_7 ( V_6 ) ) {
V_75 = F_39 ( V_6 -> V_184 . V_135 ) ;
if ( F_17 ( V_6 -> V_90 . V_91 ) ) {
V_75 = F_20 ( V_187 ) ;
if ( V_75 > V_10 -> V_188 )
V_75 = V_75 - V_10 -> V_188 ;
else
V_75 = V_75 + ( 0 - V_10 -> V_188 ) ;
}
F_52 ( & V_6 -> V_184 . V_189 , V_75 ) ;
return;
}
do {
V_182 = F_53 ( & V_6 -> V_184 . V_189 ) ;
F_54 () ;
V_75 = F_39 ( V_6 -> V_184 . V_135 ) ;
if ( F_17 ( V_6 -> V_90 . V_91 ) ) {
V_75 = F_20 ( V_187 ) ;
if ( V_75 > V_10 -> V_188 )
V_75 = V_75 - V_10 -> V_188 ;
else
V_75 = V_75 + ( 0 - V_10 -> V_188 ) ;
}
V_183 = F_50 ( V_182 , V_75 ) ;
if ( ! V_183 )
return;
} while ( F_55 ( & V_6 -> V_184 . V_189 , V_182 , V_75 ) != V_182 );
F_56 ( V_183 , & V_6 -> V_190 ) ;
do {
V_182 = F_53 ( & V_6 -> V_184 . V_191 ) ;
V_75 = V_182 - V_183 ;
if ( V_75 < 1 )
V_75 = 1 ;
} while ( F_55 ( & V_6 -> V_184 . V_191 , V_182 , V_75 ) != V_182 );
}
static int F_57 ( int V_192 )
{
return ( V_17 -> V_18 & V_193 )
&& ( V_192 == 5 || V_192 == 6 ) ;
}
static void F_58 ( struct V_9 * V_10 ,
unsigned long V_194 , unsigned long V_195 )
{
struct V_5 * V_6 ;
T_1 V_75 , V_182 , V_183 ;
int V_140 ;
for ( V_140 = 0 ; V_140 < V_10 -> V_196 ; ++ V_140 ) {
V_6 = V_10 -> V_197 [ V_140 ] ;
if ( ! V_6 -> V_184 . V_135 )
continue;
V_75 = ( V_6 -> V_184 . V_135 == 5 ) ? V_194 : V_195 ;
V_182 = F_53 ( & V_6 -> V_184 . V_189 ) ;
V_6 -> V_184 . V_135 = 0 ;
V_183 = F_50 ( V_182 , V_75 ) ;
if ( V_183 )
F_56 ( V_183 , & V_6 -> V_190 ) ;
}
}
static void F_59 ( struct V_9 * V_10 ,
unsigned long V_194 , unsigned long V_195 )
{
struct V_5 * V_6 ;
T_1 V_75 , V_182 ;
int V_140 ;
for ( V_140 = 0 ; V_140 < V_10 -> V_196 ; ++ V_140 ) {
V_6 = V_10 -> V_197 [ V_140 ] ;
V_6 -> V_184 . V_135 = V_10 -> V_198 [ V_140 ] ;
V_75 = ( V_6 -> V_184 . V_135 == 5 ) ? V_194 : V_195 ;
V_182 = F_53 ( & V_6 -> V_184 . V_189 ) ;
if ( F_50 ( V_182 , V_75 ) )
F_52 ( & V_6 -> V_184 . V_189 , V_75 ) ;
F_60 ( V_6 ) ;
}
}
static void F_61 ( struct V_9 * V_10 , unsigned long V_7 )
{
unsigned long V_194 , V_195 ;
if ( ! V_10 -> V_196 ) {
F_36 ( V_131 , V_7 ) ;
return;
}
asm volatile("mtspr %3,%2; mfspr %0,%4; mfspr %1,%5"
: "=&r" (pmc5), "=&r" (pmc6)
: "r" (mmcr0 & ~(MMCR0_PMC1CE | MMCR0_PMCjCE)),
"i" (SPRN_MMCR0),
"i" (SPRN_PMC5), "i" (SPRN_PMC6));
if ( V_7 & V_133 )
F_58 ( V_10 , V_194 , V_195 ) ;
else
F_59 ( V_10 , V_194 , V_195 ) ;
if ( V_7 & ( V_199 | V_132 ) )
F_36 ( V_131 , V_7 ) ;
}
static void F_62 ( struct V_67 * V_67 )
{
struct V_9 * V_10 ;
unsigned long V_18 , V_7 , V_75 ;
if ( ! V_17 )
return;
F_44 ( V_18 ) ;
V_10 = F_26 ( & V_9 ) ;
if ( ! V_10 -> V_68 ) {
if ( ! V_10 -> V_200 ) {
F_63 () ;
V_10 -> V_200 = 1 ;
}
V_75 = V_7 = F_20 ( V_131 ) ;
V_75 |= V_133 ;
V_75 &= ~ ( V_109 | V_117 | V_201 | V_121 |
V_202 ) ;
F_61 ( V_10 , V_75 ) ;
F_64 () ;
if ( V_10 -> V_11 [ 2 ] & V_20 ) {
F_36 ( V_56 ,
V_10 -> V_11 [ 2 ] & ~ V_20 ) ;
F_64 () ;
}
V_10 -> V_68 = 1 ;
V_10 -> V_203 = 0 ;
F_10 ( V_7 ) ;
}
F_47 ( V_18 ) ;
}
static void F_65 ( struct V_67 * V_67 )
{
struct V_5 * V_6 ;
struct V_9 * V_10 ;
unsigned long V_18 ;
long V_140 ;
unsigned long V_75 , V_7 ;
T_4 V_204 ;
unsigned int V_205 [ V_139 ] ;
int V_206 ;
int V_135 ;
bool V_8 ;
if ( ! V_17 )
return;
F_44 ( V_18 ) ;
V_10 = F_26 ( & V_9 ) ;
if ( ! V_10 -> V_68 )
goto V_116;
if ( V_10 -> V_207 == 0 ) {
F_66 ( 0 ) ;
goto V_116;
}
V_10 -> V_68 = 0 ;
V_8 = F_7 ( V_10 -> V_6 [ 0 ] ) ;
if ( ! V_10 -> V_203 ) {
F_36 ( V_56 , V_10 -> V_11 [ 2 ] & ~ V_20 ) ;
F_36 ( V_143 , V_10 -> V_11 [ 1 ] ) ;
goto V_208;
}
memset ( V_10 -> V_11 , 0 , sizeof( V_10 -> V_11 ) ) ;
if ( V_17 -> V_209 ( V_10 -> V_210 , V_10 -> V_207 , V_205 ,
V_10 -> V_11 , V_10 -> V_6 ) ) {
F_41 ( V_138 L_10 ) ;
goto V_116;
}
if ( ! ( V_17 -> V_18 & V_89 ) ) {
V_6 = V_10 -> V_6 [ 0 ] ;
if ( V_6 -> V_90 . V_178 )
V_10 -> V_11 [ 0 ] |= V_211 ;
if ( V_6 -> V_90 . V_179 )
V_10 -> V_11 [ 0 ] |= V_48 ;
if ( V_6 -> V_90 . V_180 )
V_10 -> V_11 [ 0 ] |= V_49 ;
}
F_66 ( 1 ) ;
F_36 ( V_56 , V_10 -> V_11 [ 2 ] & ~ V_20 ) ;
F_36 ( V_143 , V_10 -> V_11 [ 1 ] ) ;
F_36 ( V_131 , ( V_10 -> V_11 [ 0 ] & ~ ( V_199 | V_132 ) )
| V_133 ) ;
if ( V_17 -> V_18 & V_89 )
F_36 ( V_114 , V_10 -> V_11 [ 3 ] ) ;
for ( V_140 = 0 ; V_140 < V_10 -> V_207 ; ++ V_140 ) {
V_6 = V_10 -> V_6 [ V_140 ] ;
if ( V_6 -> V_184 . V_135 && V_6 -> V_184 . V_135 != V_205 [ V_140 ] + 1 ) {
F_51 ( V_6 ) ;
F_42 ( V_6 -> V_184 . V_135 , 0 ) ;
V_6 -> V_184 . V_135 = 0 ;
}
}
V_10 -> V_196 = V_206 = 0 ;
for ( V_140 = 0 ; V_140 < V_10 -> V_207 ; ++ V_140 ) {
V_6 = V_10 -> V_6 [ V_140 ] ;
if ( V_6 -> V_184 . V_135 )
continue;
V_135 = V_205 [ V_140 ] + 1 ;
if ( F_57 ( V_135 ) ) {
V_10 -> V_197 [ V_206 ] = V_6 ;
V_10 -> V_198 [ V_206 ] = V_135 ;
++ V_206 ;
continue;
}
if ( V_8 )
V_75 = F_53 ( & V_6 -> V_184 . V_189 ) ;
else {
V_75 = 0 ;
if ( V_6 -> V_184 . V_103 ) {
V_204 = F_53 ( & V_6 -> V_184 . V_191 ) ;
if ( V_204 < 0x80000000L )
V_75 = 0x80000000L - V_204 ;
}
F_52 ( & V_6 -> V_184 . V_189 , V_75 ) ;
}
V_6 -> V_184 . V_135 = V_135 ;
if ( V_6 -> V_184 . V_185 & V_186 )
V_75 = 0 ;
F_42 ( V_135 , V_75 ) ;
F_60 ( V_6 ) ;
}
V_10 -> V_196 = V_206 ;
V_10 -> V_11 [ 0 ] |= V_108 | V_212 ;
V_208:
F_16 ( V_8 ) ;
V_7 = F_11 ( V_8 , V_10 ) ;
F_64 () ;
if ( V_10 -> V_66 )
V_17 -> V_213 ( V_10 -> V_214 ) ;
F_61 ( V_10 , V_7 ) ;
if ( V_10 -> V_11 [ 2 ] & V_20 ) {
F_64 () ;
F_36 ( V_56 , V_10 -> V_11 [ 2 ] ) ;
}
V_116:
F_47 ( V_18 ) ;
}
static int F_67 ( struct V_5 * V_215 , int V_216 ,
struct V_5 * V_169 [] , T_1 * V_210 ,
unsigned int * V_18 )
{
int V_175 = 0 ;
struct V_5 * V_6 ;
if ( ! F_68 ( V_215 ) ) {
if ( V_175 >= V_216 )
return - 1 ;
V_169 [ V_175 ] = V_215 ;
V_18 [ V_175 ] = V_215 -> V_184 . V_217 ;
V_210 [ V_175 ++ ] = V_215 -> V_184 . V_91 ;
}
F_69 (event, &group->sibling_list, group_entry) {
if ( ! F_68 ( V_6 ) &&
V_6 -> V_185 != V_218 ) {
if ( V_175 >= V_216 )
return - 1 ;
V_169 [ V_175 ] = V_6 ;
V_18 [ V_175 ] = V_6 -> V_184 . V_217 ;
V_210 [ V_175 ++ ] = V_6 -> V_184 . V_91 ;
}
}
return V_175 ;
}
static int F_70 ( struct V_5 * V_6 , int V_219 )
{
struct V_9 * V_10 ;
unsigned long V_18 ;
int V_220 ;
int V_71 = - V_181 ;
F_44 ( V_18 ) ;
F_71 ( V_6 -> V_67 ) ;
V_10 = F_26 ( & V_9 ) ;
V_220 = V_10 -> V_207 ;
if ( V_220 >= V_17 -> V_141 )
goto V_116;
V_10 -> V_6 [ V_220 ] = V_6 ;
V_10 -> V_210 [ V_220 ] = V_6 -> V_184 . V_91 ;
V_10 -> V_18 [ V_220 ] = V_6 -> V_184 . V_217 ;
if ( ! ( V_219 & V_221 ) )
V_6 -> V_184 . V_185 = V_186 | V_222 ;
else
V_6 -> V_184 . V_185 = 0 ;
if ( V_10 -> V_223 & V_224 )
goto V_225;
if ( F_49 ( V_10 -> V_6 , V_10 -> V_18 , V_220 , 1 ) )
goto V_116;
if ( F_48 ( V_10 , V_10 -> V_210 , V_10 -> V_18 , V_220 + 1 ) )
goto V_116;
V_6 -> V_184 . V_91 = V_10 -> V_210 [ V_220 ] ;
V_225:
F_9 ( V_6 ) ;
++ V_10 -> V_207 ;
++ V_10 -> V_203 ;
V_71 = 0 ;
V_116:
if ( F_72 ( V_6 ) ) {
F_12 ( V_6 ) ;
V_10 -> V_214 = V_17 -> V_226 (
V_6 -> V_90 . V_227 ) ;
}
if ( F_17 ( V_6 -> V_90 . V_91 ) )
V_10 -> V_188 = F_20 ( V_187 ) ;
F_73 ( V_6 -> V_67 ) ;
F_47 ( V_18 ) ;
return V_71 ;
}
static void F_74 ( struct V_5 * V_6 , int V_219 )
{
struct V_9 * V_10 ;
long V_140 ;
unsigned long V_18 ;
F_44 ( V_18 ) ;
F_71 ( V_6 -> V_67 ) ;
F_51 ( V_6 ) ;
V_10 = F_26 ( & V_9 ) ;
for ( V_140 = 0 ; V_140 < V_10 -> V_207 ; ++ V_140 ) {
if ( V_6 == V_10 -> V_6 [ V_140 ] ) {
while ( ++ V_140 < V_10 -> V_207 ) {
V_10 -> V_6 [ V_140 - 1 ] = V_10 -> V_6 [ V_140 ] ;
V_10 -> V_210 [ V_140 - 1 ] = V_10 -> V_210 [ V_140 ] ;
V_10 -> V_18 [ V_140 - 1 ] = V_10 -> V_18 [ V_140 ] ;
}
-- V_10 -> V_207 ;
V_17 -> V_228 ( V_6 -> V_184 . V_135 - 1 , V_10 -> V_11 ) ;
if ( V_6 -> V_184 . V_135 ) {
F_42 ( V_6 -> V_184 . V_135 , 0 ) ;
V_6 -> V_184 . V_135 = 0 ;
}
F_60 ( V_6 ) ;
break;
}
}
for ( V_140 = 0 ; V_140 < V_10 -> V_196 ; ++ V_140 )
if ( V_6 == V_10 -> V_197 [ V_140 ] )
break;
if ( V_140 < V_10 -> V_196 ) {
while ( ++ V_140 < V_10 -> V_196 ) {
V_10 -> V_197 [ V_140 - 1 ] = V_10 -> V_197 [ V_140 ] ;
V_10 -> V_198 [ V_140 - 1 ] = V_10 -> V_198 [ V_140 ] ;
}
-- V_10 -> V_196 ;
}
if ( V_10 -> V_207 == 0 ) {
V_10 -> V_11 [ 0 ] &= ~ ( V_108 | V_212 ) ;
}
if ( F_72 ( V_6 ) )
F_13 ( V_6 ) ;
F_73 ( V_6 -> V_67 ) ;
F_47 ( V_18 ) ;
}
static void F_75 ( struct V_5 * V_6 , int V_219 )
{
unsigned long V_18 ;
T_4 V_204 ;
unsigned long V_75 ;
if ( ! V_6 -> V_184 . V_135 || ! V_6 -> V_184 . V_103 )
return;
if ( ! ( V_6 -> V_184 . V_185 & V_186 ) )
return;
if ( V_219 & V_229 )
F_28 ( ! ( V_6 -> V_184 . V_185 & V_222 ) ) ;
F_44 ( V_18 ) ;
F_71 ( V_6 -> V_67 ) ;
V_6 -> V_184 . V_185 = 0 ;
V_204 = F_53 ( & V_6 -> V_184 . V_191 ) ;
V_75 = 0 ;
if ( V_204 < 0x80000000L )
V_75 = 0x80000000L - V_204 ;
F_42 ( V_6 -> V_184 . V_135 , V_75 ) ;
F_60 ( V_6 ) ;
F_73 ( V_6 -> V_67 ) ;
F_47 ( V_18 ) ;
}
static void F_76 ( struct V_5 * V_6 , int V_219 )
{
unsigned long V_18 ;
if ( ! V_6 -> V_184 . V_135 || ! V_6 -> V_184 . V_103 )
return;
if ( V_6 -> V_184 . V_185 & V_186 )
return;
F_44 ( V_18 ) ;
F_71 ( V_6 -> V_67 ) ;
F_51 ( V_6 ) ;
V_6 -> V_184 . V_185 |= V_186 | V_222 ;
F_42 ( V_6 -> V_184 . V_135 , 0 ) ;
F_60 ( V_6 ) ;
F_73 ( V_6 -> V_67 ) ;
F_47 ( V_18 ) ;
}
static void F_77 ( struct V_67 * V_67 , unsigned int V_223 )
{
struct V_9 * V_10 = F_26 ( & V_9 ) ;
F_28 ( V_10 -> V_223 ) ;
V_10 -> V_223 = V_223 ;
if ( V_223 & ~ V_224 )
return;
F_71 ( V_67 ) ;
V_10 -> V_230 = V_10 -> V_207 ;
}
static void F_78 ( struct V_67 * V_67 )
{
struct V_9 * V_10 = F_26 ( & V_9 ) ;
unsigned int V_223 ;
F_28 ( ! V_10 -> V_223 ) ;
V_223 = V_10 -> V_223 ;
V_10 -> V_223 = 0 ;
if ( V_223 & ~ V_224 )
return;
F_73 ( V_67 ) ;
}
static int F_79 ( struct V_67 * V_67 )
{
struct V_9 * V_10 ;
long V_140 , V_175 ;
if ( ! V_17 )
return - V_181 ;
V_10 = F_26 ( & V_9 ) ;
F_28 ( ! V_10 -> V_223 ) ;
if ( V_10 -> V_223 & ~ V_224 ) {
V_10 -> V_223 = 0 ;
return 0 ;
}
V_175 = V_10 -> V_207 ;
if ( F_49 ( V_10 -> V_6 , V_10 -> V_18 , 0 , V_175 ) )
return - V_181 ;
V_140 = F_48 ( V_10 , V_10 -> V_210 , V_10 -> V_18 , V_175 ) ;
if ( V_140 < 0 )
return - V_181 ;
for ( V_140 = V_10 -> V_230 ; V_140 < V_175 ; ++ V_140 )
V_10 -> V_6 [ V_140 ] -> V_184 . V_91 = V_10 -> V_210 [ V_140 ] ;
V_10 -> V_223 = 0 ;
F_73 ( V_67 ) ;
return 0 ;
}
static int F_80 ( struct V_5 * V_6 , T_1 V_231 ,
unsigned int V_18 )
{
int V_175 ;
T_1 V_232 [ V_233 ] ;
if ( V_6 -> V_90 . V_178
|| V_6 -> V_90 . V_179
|| V_6 -> V_90 . V_180
|| V_6 -> V_90 . V_103 )
return 0 ;
if ( V_17 -> V_163 ( V_231 ) )
return 1 ;
if ( ! V_17 -> V_164 )
return 0 ;
V_18 |= V_177 | V_162 ;
V_175 = V_17 -> V_164 ( V_231 , V_18 , V_232 ) ;
return V_175 > 0 ;
}
static T_1 F_81 ( T_1 V_231 , unsigned long V_18 )
{
T_1 V_232 [ V_233 ] ;
int V_175 ;
V_18 &= ~ ( V_177 | V_162 ) ;
V_175 = V_17 -> V_164 ( V_231 , V_18 , V_232 ) ;
if ( ! V_175 )
return 0 ;
return V_232 [ 0 ] ;
}
static void F_82 ( struct V_5 * V_6 )
{
if ( ! F_83 ( & V_234 , - 1 , 1 ) ) {
F_84 ( & V_235 ) ;
if ( F_85 ( & V_234 ) == 0 )
F_86 () ;
F_87 ( & V_235 ) ;
}
}
static int F_88 ( T_1 V_91 , T_1 * V_236 )
{
unsigned long type , V_237 , V_4 ;
int V_231 ;
if ( ! V_17 -> V_238 )
return - V_95 ;
type = V_91 & 0xff ;
V_237 = ( V_91 >> 8 ) & 0xff ;
V_4 = ( V_91 >> 16 ) & 0xff ;
if ( type >= V_239 ||
V_237 >= V_240 ||
V_4 >= V_241 )
return - V_95 ;
V_231 = ( * V_17 -> V_238 ) [ type ] [ V_237 ] [ V_4 ] ;
if ( V_231 == 0 )
return - V_242 ;
if ( V_231 == - 1 )
return - V_95 ;
* V_236 = V_231 ;
return 0 ;
}
static int F_89 ( struct V_5 * V_6 )
{
T_1 V_231 ;
unsigned long V_18 ;
struct V_5 * V_169 [ V_139 ] ;
T_1 V_210 [ V_139 ] ;
unsigned int V_148 [ V_139 ] ;
int V_175 ;
int V_243 ;
struct V_9 * V_10 ;
if ( ! V_17 )
return - V_244 ;
if ( F_72 ( V_6 ) ) {
if ( ! ( V_17 -> V_18 & V_89 ) )
return - V_242 ;
}
switch ( V_6 -> V_90 . type ) {
case V_245 :
V_231 = V_6 -> V_90 . V_91 ;
if ( V_231 >= V_17 -> V_246 || V_17 -> V_247 [ V_231 ] == 0 )
return - V_242 ;
V_231 = V_17 -> V_247 [ V_231 ] ;
break;
case V_248 :
V_243 = F_88 ( V_6 -> V_90 . V_91 , & V_231 ) ;
if ( V_243 )
return V_243 ;
break;
case V_249 :
V_231 = V_6 -> V_90 . V_91 ;
break;
default:
return - V_244 ;
}
V_6 -> V_184 . V_250 = V_231 ;
V_6 -> V_184 . V_135 = 0 ;
if ( ! F_90 ( V_251 ) )
V_6 -> V_90 . V_180 = 0 ;
V_18 = 0 ;
if ( V_6 -> V_96 & V_97 )
V_18 |= V_252 ;
if ( V_17 -> V_18 & V_193 ) {
if ( F_80 ( V_6 , V_231 , V_18 ) ) {
V_18 |= V_177 ;
} else if ( V_17 -> V_163 ( V_231 ) ) {
V_231 = F_81 ( V_231 , V_18 ) ;
if ( ! V_231 )
return - V_95 ;
}
}
V_243 = F_8 ( V_6 ) ;
if ( V_243 )
return V_243 ;
V_175 = 0 ;
if ( V_6 -> V_94 != V_6 ) {
V_175 = F_67 ( V_6 -> V_94 , V_17 -> V_141 - 1 ,
V_169 , V_210 , V_148 ) ;
if ( V_175 < 0 )
return - V_95 ;
}
V_210 [ V_175 ] = V_231 ;
V_169 [ V_175 ] = V_6 ;
V_148 [ V_175 ] = V_18 ;
if ( F_49 ( V_169 , V_148 , V_175 , 1 ) )
return - V_95 ;
V_10 = & F_91 ( V_9 ) ;
V_243 = F_48 ( V_10 , V_210 , V_148 , V_175 + 1 ) ;
if ( F_72 ( V_6 ) ) {
V_10 -> V_214 = V_17 -> V_226 (
V_6 -> V_90 . V_227 ) ;
if ( V_10 -> V_214 == - 1 ) {
F_92 ( V_9 ) ;
return - V_242 ;
}
}
F_92 ( V_9 ) ;
if ( V_243 )
return - V_95 ;
V_6 -> V_184 . V_91 = V_210 [ V_175 ] ;
V_6 -> V_184 . V_217 = V_148 [ V_175 ] ;
V_6 -> V_184 . V_253 = V_6 -> V_184 . V_103 ;
F_52 ( & V_6 -> V_184 . V_191 , V_6 -> V_184 . V_253 ) ;
if ( F_7 ( V_6 ) )
F_52 ( & V_6 -> V_184 . V_189 , 0 ) ;
V_243 = 0 ;
if ( ! F_93 ( & V_234 ) ) {
F_84 ( & V_235 ) ;
if ( F_94 ( & V_234 ) == 0 &&
F_95 ( V_254 ) )
V_243 = - V_255 ;
else
F_96 ( & V_234 ) ;
F_87 ( & V_235 ) ;
}
V_6 -> V_256 = F_82 ;
return V_243 ;
}
static int F_97 ( struct V_5 * V_6 )
{
return V_6 -> V_184 . V_135 ;
}
T_5 F_98 ( struct V_257 * V_258 ,
struct V_259 * V_90 , char * V_260 )
{
struct V_261 * V_262 ;
V_262 = F_99 ( V_90 , struct V_261 , V_90 ) ;
return sprintf ( V_260 , L_11 , V_262 -> V_263 ) ;
}
static void F_100 ( struct V_5 * V_6 , unsigned long V_75 ,
struct V_1 * V_2 )
{
T_1 V_264 = V_6 -> V_184 . V_103 ;
T_4 V_182 , V_183 , V_204 ;
int V_265 = 0 ;
if ( V_6 -> V_184 . V_185 & V_186 ) {
F_42 ( V_6 -> V_184 . V_135 , 0 ) ;
return;
}
V_182 = F_53 ( & V_6 -> V_184 . V_189 ) ;
V_183 = F_50 ( V_182 , V_75 ) ;
F_56 ( V_183 , & V_6 -> V_190 ) ;
V_75 = 0 ;
V_204 = F_53 ( & V_6 -> V_184 . V_191 ) - V_183 ;
if ( V_183 == 0 )
V_204 ++ ;
if ( V_264 ) {
if ( V_204 <= 0 ) {
V_204 += V_264 ;
if ( V_204 <= 0 )
V_204 = V_264 ;
V_265 = F_6 ( V_2 ) ;
V_6 -> V_184 . V_253 = V_6 -> V_184 . V_103 ;
}
if ( V_204 < 0x80000000LL )
V_75 = 0x80000000LL - V_204 ;
}
F_42 ( V_6 -> V_184 . V_135 , V_75 ) ;
F_52 ( & V_6 -> V_184 . V_189 , V_75 ) ;
F_52 ( & V_6 -> V_184 . V_191 , V_204 ) ;
F_60 ( V_6 ) ;
if ( V_265 ) {
struct V_266 V_267 ;
F_101 ( & V_267 , ~ 0ULL , V_6 -> V_184 . V_253 ) ;
if ( V_6 -> V_90 . V_102 & V_268 )
F_2 ( V_2 , & V_267 . V_69 ) ;
if ( V_6 -> V_90 . V_102 & V_269 ) {
struct V_9 * V_10 ;
V_10 = F_26 ( & V_9 ) ;
F_15 ( V_10 ) ;
V_267 . V_270 = & V_10 -> V_87 ;
}
if ( V_6 -> V_90 . V_102 & V_271 &&
V_17 -> V_272 )
V_17 -> V_272 ( & V_267 . V_273 , V_17 -> V_18 , V_2 ) ;
if ( V_6 -> V_90 . V_102 & V_274 &&
V_17 -> V_275 )
V_17 -> V_275 ( & V_267 . V_276 ) ;
if ( F_102 ( V_6 , & V_267 , V_2 ) )
F_76 ( V_6 , 0 ) ;
}
}
unsigned long F_103 ( struct V_1 * V_2 )
{
T_2 V_18 = F_3 ( V_2 ) ;
if ( V_18 )
return V_18 ;
return F_104 ( V_2 ) ? V_46 :
V_51 ;
}
unsigned long F_105 ( struct V_1 * V_2 )
{
bool V_52 = F_18 ( V_2 ) ;
if ( V_52 && F_6 ( V_2 ) )
return F_20 ( V_55 ) + F_1 ( V_2 ) ;
else if ( V_52 )
return 0 ;
else
return V_2 -> V_277 ;
}
static bool F_106 ( unsigned long V_75 )
{
if ( ( 0x80000000 - V_75 ) <= 256 )
return true ;
return false ;
}
static bool F_107 ( unsigned long V_75 )
{
if ( ( int ) V_75 < 0 )
return true ;
return false ;
}
static void V_254 ( struct V_1 * V_2 )
{
int V_140 , V_157 ;
struct V_9 * V_10 = F_26 ( & V_9 ) ;
struct V_5 * V_6 ;
unsigned long V_75 [ 8 ] ;
int V_278 , V_279 ;
int V_280 ;
if ( V_10 -> V_196 )
F_58 ( V_10 , F_20 ( V_129 ) ,
F_20 ( V_130 ) ) ;
F_4 ( V_2 ) ;
V_280 = F_5 ( V_2 ) ;
if ( V_280 )
F_108 () ;
else
F_109 () ;
for ( V_140 = 0 ; V_140 < V_17 -> V_141 ; ++ V_140 )
V_75 [ V_140 ] = F_39 ( V_140 + 1 ) ;
V_278 = 0 ;
for ( V_140 = 0 ; V_140 < V_17 -> V_141 ; ++ V_140 ) {
if ( ! F_107 ( V_75 [ V_140 ] ) )
continue;
if ( F_57 ( V_140 + 1 ) )
continue;
V_278 = 1 ;
V_279 = 0 ;
for ( V_157 = 0 ; V_157 < V_10 -> V_207 ; ++ V_157 ) {
V_6 = V_10 -> V_6 [ V_157 ] ;
if ( V_6 -> V_184 . V_135 == ( V_140 + 1 ) ) {
V_279 = 1 ;
F_100 ( V_6 , V_75 [ V_140 ] , V_2 ) ;
break;
}
}
if ( ! V_279 )
F_42 ( V_140 + 1 , 0 ) ;
}
if ( ! V_278 && F_110 ( V_281 ) ) {
for ( V_140 = 0 ; V_140 < V_10 -> V_207 ; ++ V_140 ) {
V_6 = V_10 -> V_6 [ V_140 ] ;
if ( ! V_6 -> V_184 . V_135 || F_57 ( V_6 -> V_184 . V_135 ) )
continue;
if ( F_106 ( V_75 [ V_6 -> V_184 . V_135 - 1 ] ) ) {
V_278 = 1 ;
F_100 ( V_6 ,
V_75 [ V_6 -> V_184 . V_135 - 1 ] ,
V_2 ) ;
}
}
}
if ( ! V_278 && ! V_280 && F_111 () )
F_41 ( V_282 L_12 ) ;
F_61 ( V_10 , V_10 -> V_11 [ 0 ] ) ;
if ( V_280 )
F_112 () ;
else
F_113 () ;
}
static int F_114 ( unsigned int V_283 )
{
struct V_9 * V_10 = & F_115 ( V_9 , V_283 ) ;
if ( V_17 ) {
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_11 [ 0 ] = V_133 ;
}
return 0 ;
}
int F_116 ( struct V_284 * V_67 )
{
if ( V_17 )
return - V_255 ;
V_17 = V_67 ;
F_45 ( L_13 ,
V_67 -> V_142 ) ;
V_284 . V_285 = V_17 -> V_285 ;
#ifdef V_47
if ( F_117 () & V_47 )
V_48 = V_49 ;
#endif
F_118 ( & V_284 , L_14 , V_249 ) ;
F_119 ( V_286 , L_15 ,
F_114 , NULL ) ;
return 0 ;
}
