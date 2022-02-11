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
static bool F_17 ( struct V_1 * V_2 )
{
return ( ( F_18 ( V_2 ) == 0xf00 ) && V_2 -> V_4 ) ;
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
else
V_28 = V_33 ;
V_24 = V_15 & V_28 ;
}
if ( ! ( V_15 & V_20 ) || V_24 )
* V_3 = F_19 ( V_34 ) ;
}
static bool F_20 ( struct V_1 * V_2 )
{
unsigned long V_35 = V_36 ;
if ( V_17 -> V_18 & V_25 )
return ! ! ( V_2 -> V_26 & V_37 ) ;
if ( V_17 -> V_18 & V_31 )
V_35 = V_38 ;
return ! ! ( V_2 -> V_16 & V_35 ) ;
}
static bool F_21 ( struct V_1 * V_2 )
{
unsigned long V_39 = V_40 ;
if ( V_17 -> V_18 & V_25 )
return ! ! ( V_2 -> V_26 & V_41 ) ;
if ( V_17 -> V_18 & V_31 )
V_39 = V_42 ;
return ! ! ( V_2 -> V_16 & V_39 ) ;
}
static inline T_2 F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_43 & V_44 )
return V_45 ;
if ( ( V_2 -> V_43 & V_46 ) && V_47 != V_48 )
return V_49 ;
return V_50 ;
}
static inline T_2 F_3 ( struct V_1 * V_2 )
{
bool V_51 = F_17 ( V_2 ) ;
if ( ! V_51 )
return F_22 ( V_2 ) ;
if ( V_17 -> V_18 & V_52 ) {
unsigned long V_53 = F_19 ( V_54 ) ;
if ( V_53 >= V_55 )
return V_50 ;
return V_45 ;
}
if ( F_21 ( V_2 ) )
return V_45 ;
if ( F_20 ( V_2 ) && ( V_47 != V_48 ) )
return V_49 ;
return V_50 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
unsigned long V_15 = F_19 ( V_56 ) ;
int V_57 = V_15 & V_20 ;
int V_51 ;
V_2 -> V_16 = V_15 ;
if ( V_17 -> V_18 & V_25 )
V_2 -> V_26 = F_19 ( V_58 ) ;
if ( F_18 ( V_2 ) != 0xf00 )
V_51 = 0 ;
else if ( V_57 )
V_51 = 1 ;
else if ( ( V_17 -> V_18 & V_59 ) )
V_51 = 0 ;
else if ( ! ( V_17 -> V_18 & V_52 ) && F_21 ( V_2 ) )
V_51 = 0 ;
else
V_51 = 1 ;
V_2 -> V_4 = V_51 ;
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
static void F_23 ( void )
{
asm volatile(PPC_CLRBHRB);
}
static void F_12 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_24 ( & V_9 ) ;
if ( ! V_17 -> V_63 )
return;
if ( V_6 -> V_13 -> V_64 && V_10 -> V_65 != V_6 -> V_13 ) {
F_23 () ;
V_10 -> V_65 = V_6 -> V_13 ;
}
V_10 -> V_66 ++ ;
F_25 ( V_6 -> V_13 -> V_67 ) ;
}
static void F_13 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_24 ( & V_9 ) ;
if ( ! V_17 -> V_63 )
return;
V_10 -> V_66 -- ;
F_26 ( V_10 -> V_66 < 0 ) ;
F_27 ( V_6 -> V_13 -> V_67 ) ;
if ( ! V_10 -> V_68 && ! V_10 -> V_66 ) {
V_10 -> V_65 = NULL ;
}
}
static void F_14 ( struct V_12 * V_13 , bool V_14 )
{
if ( ! V_17 -> V_63 )
return;
if ( V_14 )
F_23 () ;
}
static T_3 F_28 ( T_1 V_69 )
{
unsigned int V_70 ;
int V_71 ;
T_3 V_72 ;
if ( F_29 ( V_69 ) )
return F_30 ( ( unsigned int * ) V_69 ) ;
F_31 () ;
V_71 = F_32 ( V_70 , ( unsigned int V_73 * ) V_69 ) ;
if ( V_71 ) {
F_33 () ;
return 0 ;
}
F_33 () ;
V_72 = F_30 ( & V_70 ) ;
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
V_75 = F_34 ( V_76 ++ ) ;
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
V_75 = F_34 ( V_76 ++ ) ;
V_69 = V_75 & V_79 ;
if ( V_75 & V_81 ) {
V_76 -- ;
V_69 = 0 ;
}
V_10 -> V_82 [ V_77 ] . V_86 = V_69 ;
} else {
V_10 -> V_82 [ V_77 ] . V_86 = V_69 ;
V_10 -> V_82 [ V_77 ] . V_83 =
F_28 ( V_69 ) ;
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
V_105 -> V_106 . V_53 = F_19 ( V_54 ) ;
V_105 -> V_106 . V_110 = F_19 ( V_58 ) ;
V_105 -> V_106 . V_111 = F_19 ( V_34 ) ;
V_105 -> V_106 . V_7 = V_7 & V_112 ;
V_105 -> V_106 . V_113 = F_19 ( V_114 ) & V_115 ;
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
F_35 ( V_54 , V_105 -> V_106 . V_53 ) ;
F_35 ( V_58 , V_105 -> V_106 . V_110 ) ;
F_35 ( V_34 , V_105 -> V_106 . V_111 ) ;
F_35 ( V_114 , V_10 -> V_11 [ 3 ] | V_105 -> V_106 . V_113 ) ;
V_116:
return V_7 ;
}
static void F_16 ( bool V_8 )
{
unsigned V_119 [ 6 ] ;
if ( ! F_36 ( V_120 ) )
return;
if ( ( V_105 -> V_106 . V_7 & ( V_121 | V_122 ) ) != V_121 )
return;
if ( V_8 && ! ( V_105 -> V_106 . V_123 & V_124 ) )
return;
F_37 () ;
V_119 [ 0 ] = F_19 ( V_125 ) ;
V_119 [ 1 ] = F_19 ( V_126 ) ;
V_119 [ 2 ] = F_19 ( V_127 ) ;
V_119 [ 3 ] = F_19 ( V_128 ) ;
V_119 [ 4 ] = F_19 ( V_129 ) ;
V_119 [ 5 ] = F_19 ( V_130 ) ;
F_35 ( V_114 , 0 ) ;
F_35 ( V_130 , 0x7FFFFFFE ) ;
F_35 ( V_131 , V_108 | V_132 | V_121 ) ;
F_35 ( V_131 , V_133 | V_121 ) ;
F_35 ( V_125 , V_119 [ 0 ] ) ;
F_35 ( V_126 , V_119 [ 1 ] ) ;
F_35 ( V_127 , V_119 [ 2 ] ) ;
F_35 ( V_128 , V_119 [ 3 ] ) ;
F_35 ( V_129 , V_119 [ 4 ] ) ;
F_35 ( V_130 , V_119 [ 5 ] ) ;
}
static unsigned long F_38 ( int V_134 )
{
unsigned long V_75 ;
switch ( V_134 ) {
case 1 :
V_75 = F_19 ( V_125 ) ;
break;
case 2 :
V_75 = F_19 ( V_126 ) ;
break;
case 3 :
V_75 = F_19 ( V_127 ) ;
break;
case 4 :
V_75 = F_19 ( V_128 ) ;
break;
case 5 :
V_75 = F_19 ( V_129 ) ;
break;
case 6 :
V_75 = F_19 ( V_130 ) ;
break;
#ifdef F_39
case 7 :
V_75 = F_19 ( V_135 ) ;
break;
case 8 :
V_75 = F_19 ( V_136 ) ;
break;
#endif
default:
F_40 ( V_137 L_1 , V_134 ) ;
V_75 = 0 ;
}
return V_75 ;
}
static void F_41 ( int V_134 , unsigned long V_75 )
{
switch ( V_134 ) {
case 1 :
F_35 ( V_125 , V_75 ) ;
break;
case 2 :
F_35 ( V_126 , V_75 ) ;
break;
case 3 :
F_35 ( V_127 , V_75 ) ;
break;
case 4 :
F_35 ( V_128 , V_75 ) ;
break;
case 5 :
F_35 ( V_129 , V_75 ) ;
break;
case 6 :
F_35 ( V_130 , V_75 ) ;
break;
#ifdef F_39
case 7 :
F_35 ( V_135 , V_75 ) ;
break;
case 8 :
F_35 ( V_136 , V_75 ) ;
break;
#endif
default:
F_40 ( V_137 L_2 , V_134 ) ;
}
}
void F_42 ( void )
{
unsigned long V_111 , V_110 , V_18 ;
T_2 V_119 [ V_138 ] ;
int V_139 ;
if ( ! V_17 -> V_140 )
return;
F_43 ( V_18 ) ;
F_44 ( L_3 ,
F_45 () , V_17 -> V_141 , V_17 -> V_140 ) ;
for ( V_139 = 0 ; V_139 < V_17 -> V_140 ; V_139 ++ )
V_119 [ V_139 ] = F_38 ( V_139 + 1 ) ;
for (; V_139 < V_138 ; V_139 ++ )
V_119 [ V_139 ] = 0xdeadbeef ;
F_44 ( L_4 ,
V_119 [ 0 ] , V_119 [ 1 ] , V_119 [ 2 ] , V_119 [ 3 ] ) ;
if ( V_17 -> V_140 > 4 )
F_44 ( L_5 ,
V_119 [ 4 ] , V_119 [ 5 ] , V_119 [ 6 ] , V_119 [ 7 ] ) ;
F_44 ( L_6 ,
F_19 ( V_131 ) , F_19 ( V_142 ) , F_19 ( V_56 ) ) ;
V_111 = V_110 = 0 ;
#ifdef F_39
V_111 = F_19 ( V_34 ) ;
if ( V_17 -> V_18 & V_25 )
V_110 = F_19 ( V_58 ) ;
if ( V_17 -> V_18 & V_89 ) {
F_44 ( L_7 ,
F_19 ( V_114 ) , F_19 ( V_143 ) ) ;
F_44 ( L_8 ,
F_19 ( V_144 ) , F_19 ( V_145 ) ) ;
}
#endif
F_44 ( L_9 ,
F_19 ( V_54 ) , V_111 , V_110 ) ;
F_46 ( V_18 ) ;
}
static int F_47 ( struct V_9 * V_10 ,
T_1 V_146 [] , unsigned int V_147 [] ,
int V_148 )
{
unsigned long V_149 , V_150 , V_151 ;
unsigned long V_152 [ V_138 ] , V_153 [ V_138 ] ;
int V_154 [ V_138 ] , V_155 [ V_138 ] ;
int V_139 , V_156 ;
unsigned long V_157 = V_17 -> V_158 ;
unsigned long V_159 = V_17 -> V_160 ;
if ( V_148 > V_17 -> V_140 )
return - 1 ;
for ( V_139 = 0 ; V_139 < V_148 ; ++ V_139 ) {
if ( ( V_147 [ V_139 ] & V_161 )
&& ! V_17 -> V_162 ( V_146 [ V_139 ] ) ) {
V_17 -> V_163 ( V_146 [ V_139 ] , V_147 [ V_139 ] ,
V_10 -> V_164 [ V_139 ] ) ;
V_146 [ V_139 ] = V_10 -> V_164 [ V_139 ] [ 0 ] ;
}
if ( V_17 -> V_165 ( V_146 [ V_139 ] , & V_10 -> V_166 [ V_139 ] [ 0 ] ,
& V_10 -> V_167 [ V_139 ] [ 0 ] ) )
return - 1 ;
}
V_150 = V_149 = 0 ;
for ( V_139 = 0 ; V_139 < V_148 ; ++ V_139 ) {
V_151 = ( V_150 | V_10 -> V_167 [ V_139 ] [ 0 ] ) +
( V_150 & V_10 -> V_167 [ V_139 ] [ 0 ] & V_157 ) ;
if ( ( ( ( V_151 + V_159 ) ^ V_150 ) & V_149 ) != 0 ||
( ( ( V_151 + V_159 ) ^ V_10 -> V_167 [ V_139 ] [ 0 ] ) &
V_10 -> V_166 [ V_139 ] [ 0 ] ) != 0 )
break;
V_150 = V_151 ;
V_149 |= V_10 -> V_166 [ V_139 ] [ 0 ] ;
}
if ( V_139 == V_148 )
return 0 ;
if ( ! V_17 -> V_163 )
return - 1 ;
for ( V_139 = 0 ; V_139 < V_148 ; ++ V_139 ) {
V_155 [ V_139 ] = 0 ;
V_154 [ V_139 ] = V_17 -> V_163 ( V_146 [ V_139 ] , V_147 [ V_139 ] ,
V_10 -> V_164 [ V_139 ] ) ;
for ( V_156 = 1 ; V_156 < V_154 [ V_139 ] ; ++ V_156 )
V_17 -> V_165 ( V_10 -> V_164 [ V_139 ] [ V_156 ] ,
& V_10 -> V_166 [ V_139 ] [ V_156 ] ,
& V_10 -> V_167 [ V_139 ] [ V_156 ] ) ;
}
V_139 = 0 ;
V_156 = - 1 ;
V_150 = V_149 = V_151 = 0 ;
while ( V_139 < V_148 ) {
if ( V_156 >= 0 ) {
V_150 = V_153 [ V_139 ] ;
V_149 = V_152 [ V_139 ] ;
V_156 = V_155 [ V_139 ] ;
}
while ( ++ V_156 < V_154 [ V_139 ] ) {
V_151 = ( V_150 | V_10 -> V_167 [ V_139 ] [ V_156 ] ) +
( V_150 & V_10 -> V_167 [ V_139 ] [ V_156 ] & V_157 ) ;
if ( ( ( ( V_151 + V_159 ) ^ V_150 ) & V_149 ) == 0 &&
( ( ( V_151 + V_159 ) ^ V_10 -> V_167 [ V_139 ] [ V_156 ] )
& V_10 -> V_166 [ V_139 ] [ V_156 ] ) == 0 )
break;
}
if ( V_156 >= V_154 [ V_139 ] ) {
if ( -- V_139 < 0 )
return - 1 ;
} else {
V_155 [ V_139 ] = V_156 ;
V_153 [ V_139 ] = V_150 ;
V_152 [ V_139 ] = V_149 ;
V_150 = V_151 ;
V_149 |= V_10 -> V_166 [ V_139 ] [ V_156 ] ;
++ V_139 ;
V_156 = - 1 ;
}
}
for ( V_139 = 0 ; V_139 < V_148 ; ++ V_139 )
V_146 [ V_139 ] = V_10 -> V_164 [ V_139 ] [ V_155 [ V_139 ] ] ;
return 0 ;
}
static int F_48 ( struct V_5 * * V_168 , unsigned int V_147 [] ,
int V_169 , int V_170 )
{
int V_171 = 0 , V_172 = 0 , V_173 = 0 ;
int V_139 , V_174 , V_175 ;
struct V_5 * V_6 ;
if ( V_17 -> V_18 & V_89 )
return 0 ;
V_174 = V_169 + V_170 ;
if ( V_174 <= 1 )
return 0 ;
V_175 = 1 ;
for ( V_139 = 0 ; V_139 < V_174 ; ++ V_139 ) {
if ( V_147 [ V_139 ] & V_176 ) {
V_147 [ V_139 ] &= ~ V_161 ;
continue;
}
V_6 = V_168 [ V_139 ] ;
if ( V_175 ) {
V_171 = V_6 -> V_90 . V_177 ;
V_172 = V_6 -> V_90 . V_178 ;
V_173 = V_6 -> V_90 . V_179 ;
V_175 = 0 ;
} else if ( V_6 -> V_90 . V_177 != V_171 ||
V_6 -> V_90 . V_178 != V_172 ||
V_6 -> V_90 . V_179 != V_173 ) {
return - V_180 ;
}
}
if ( V_171 || V_172 || V_173 )
for ( V_139 = 0 ; V_139 < V_174 ; ++ V_139 )
if ( V_147 [ V_139 ] & V_176 )
V_147 [ V_139 ] |= V_161 ;
return 0 ;
}
static T_1 F_49 ( T_1 V_181 , T_1 V_75 )
{
T_1 V_182 = ( V_75 - V_181 ) & 0xfffffffful ;
if ( V_181 > V_75 && ( V_181 - V_75 ) < 256 )
V_182 = 0 ;
return V_182 ;
}
static void F_50 ( struct V_5 * V_6 )
{
T_4 V_75 , V_182 , V_181 ;
if ( V_6 -> V_183 . V_184 & V_185 )
return;
if ( ! V_6 -> V_183 . V_134 )
return;
if ( F_7 ( V_6 ) ) {
V_75 = F_38 ( V_6 -> V_183 . V_134 ) ;
F_51 ( & V_6 -> V_183 . V_186 , V_75 ) ;
return;
}
do {
V_181 = F_52 ( & V_6 -> V_183 . V_186 ) ;
F_53 () ;
V_75 = F_38 ( V_6 -> V_183 . V_134 ) ;
V_182 = F_49 ( V_181 , V_75 ) ;
if ( ! V_182 )
return;
} while ( F_54 ( & V_6 -> V_183 . V_186 , V_181 , V_75 ) != V_181 );
F_55 ( V_182 , & V_6 -> V_187 ) ;
do {
V_181 = F_52 ( & V_6 -> V_183 . V_188 ) ;
V_75 = V_181 - V_182 ;
if ( V_75 < 1 )
V_75 = 1 ;
} while ( F_54 ( & V_6 -> V_183 . V_188 , V_181 , V_75 ) != V_181 );
}
static int F_56 ( int V_189 )
{
return ( V_17 -> V_18 & V_190 )
&& ( V_189 == 5 || V_189 == 6 ) ;
}
static void F_57 ( struct V_9 * V_10 ,
unsigned long V_191 , unsigned long V_192 )
{
struct V_5 * V_6 ;
T_1 V_75 , V_181 , V_182 ;
int V_139 ;
for ( V_139 = 0 ; V_139 < V_10 -> V_193 ; ++ V_139 ) {
V_6 = V_10 -> V_194 [ V_139 ] ;
if ( ! V_6 -> V_183 . V_134 )
continue;
V_75 = ( V_6 -> V_183 . V_134 == 5 ) ? V_191 : V_192 ;
V_181 = F_52 ( & V_6 -> V_183 . V_186 ) ;
V_6 -> V_183 . V_134 = 0 ;
V_182 = F_49 ( V_181 , V_75 ) ;
if ( V_182 )
F_55 ( V_182 , & V_6 -> V_187 ) ;
}
}
static void F_58 ( struct V_9 * V_10 ,
unsigned long V_191 , unsigned long V_192 )
{
struct V_5 * V_6 ;
T_1 V_75 , V_181 ;
int V_139 ;
for ( V_139 = 0 ; V_139 < V_10 -> V_193 ; ++ V_139 ) {
V_6 = V_10 -> V_194 [ V_139 ] ;
V_6 -> V_183 . V_134 = V_10 -> V_195 [ V_139 ] ;
V_75 = ( V_6 -> V_183 . V_134 == 5 ) ? V_191 : V_192 ;
V_181 = F_52 ( & V_6 -> V_183 . V_186 ) ;
if ( F_49 ( V_181 , V_75 ) )
F_51 ( & V_6 -> V_183 . V_186 , V_75 ) ;
F_59 ( V_6 ) ;
}
}
static void F_60 ( struct V_9 * V_10 , unsigned long V_7 )
{
unsigned long V_191 , V_192 ;
if ( ! V_10 -> V_193 ) {
F_35 ( V_131 , V_7 ) ;
return;
}
asm volatile("mtspr %3,%2; mfspr %0,%4; mfspr %1,%5"
: "=&r" (pmc5), "=&r" (pmc6)
: "r" (mmcr0 & ~(MMCR0_PMC1CE | MMCR0_PMCjCE)),
"i" (SPRN_MMCR0),
"i" (SPRN_PMC5), "i" (SPRN_PMC6));
if ( V_7 & V_133 )
F_57 ( V_10 , V_191 , V_192 ) ;
else
F_58 ( V_10 , V_191 , V_192 ) ;
if ( V_7 & ( V_196 | V_132 ) )
F_35 ( V_131 , V_7 ) ;
}
static void F_61 ( struct V_67 * V_67 )
{
struct V_9 * V_10 ;
unsigned long V_18 , V_7 , V_75 ;
if ( ! V_17 )
return;
F_43 ( V_18 ) ;
V_10 = F_24 ( & V_9 ) ;
if ( ! V_10 -> V_68 ) {
if ( ! V_10 -> V_197 ) {
F_62 () ;
V_10 -> V_197 = 1 ;
}
V_75 = V_7 = F_19 ( V_131 ) ;
V_75 |= V_133 ;
V_75 &= ~ ( V_109 | V_117 | V_198 | V_121 |
V_199 ) ;
F_60 ( V_10 , V_75 ) ;
F_63 () ;
if ( V_10 -> V_11 [ 2 ] & V_20 ) {
F_35 ( V_56 ,
V_10 -> V_11 [ 2 ] & ~ V_20 ) ;
F_63 () ;
}
V_10 -> V_68 = 1 ;
V_10 -> V_200 = 0 ;
F_10 ( V_7 ) ;
}
F_46 ( V_18 ) ;
}
static void F_64 ( struct V_67 * V_67 )
{
struct V_5 * V_6 ;
struct V_9 * V_10 ;
unsigned long V_18 ;
long V_139 ;
unsigned long V_75 , V_7 ;
T_4 V_201 ;
unsigned int V_202 [ V_138 ] ;
int V_203 ;
int V_134 ;
bool V_8 ;
if ( ! V_17 )
return;
F_43 ( V_18 ) ;
V_10 = F_24 ( & V_9 ) ;
if ( ! V_10 -> V_68 )
goto V_116;
if ( V_10 -> V_204 == 0 ) {
F_65 ( 0 ) ;
goto V_116;
}
V_10 -> V_68 = 0 ;
V_8 = F_7 ( V_10 -> V_6 [ 0 ] ) ;
if ( ! V_10 -> V_200 ) {
F_35 ( V_56 , V_10 -> V_11 [ 2 ] & ~ V_20 ) ;
F_35 ( V_142 , V_10 -> V_11 [ 1 ] ) ;
goto V_205;
}
memset ( V_10 -> V_11 , 0 , sizeof( V_10 -> V_11 ) ) ;
if ( V_17 -> V_206 ( V_10 -> V_207 , V_10 -> V_204 , V_202 ,
V_10 -> V_11 , V_10 -> V_6 ) ) {
F_40 ( V_137 L_10 ) ;
goto V_116;
}
if ( ! ( V_17 -> V_18 & V_89 ) ) {
V_6 = V_10 -> V_6 [ 0 ] ;
if ( V_6 -> V_90 . V_177 )
V_10 -> V_11 [ 0 ] |= V_208 ;
if ( V_6 -> V_90 . V_178 )
V_10 -> V_11 [ 0 ] |= V_47 ;
if ( V_6 -> V_90 . V_179 )
V_10 -> V_11 [ 0 ] |= V_48 ;
}
F_65 ( 1 ) ;
F_35 ( V_56 , V_10 -> V_11 [ 2 ] & ~ V_20 ) ;
F_35 ( V_142 , V_10 -> V_11 [ 1 ] ) ;
F_35 ( V_131 , ( V_10 -> V_11 [ 0 ] & ~ ( V_196 | V_132 ) )
| V_133 ) ;
if ( V_17 -> V_18 & V_89 )
F_35 ( V_114 , V_10 -> V_11 [ 3 ] ) ;
for ( V_139 = 0 ; V_139 < V_10 -> V_204 ; ++ V_139 ) {
V_6 = V_10 -> V_6 [ V_139 ] ;
if ( V_6 -> V_183 . V_134 && V_6 -> V_183 . V_134 != V_202 [ V_139 ] + 1 ) {
F_50 ( V_6 ) ;
F_41 ( V_6 -> V_183 . V_134 , 0 ) ;
V_6 -> V_183 . V_134 = 0 ;
}
}
V_10 -> V_193 = V_203 = 0 ;
for ( V_139 = 0 ; V_139 < V_10 -> V_204 ; ++ V_139 ) {
V_6 = V_10 -> V_6 [ V_139 ] ;
if ( V_6 -> V_183 . V_134 )
continue;
V_134 = V_202 [ V_139 ] + 1 ;
if ( F_56 ( V_134 ) ) {
V_10 -> V_194 [ V_203 ] = V_6 ;
V_10 -> V_195 [ V_203 ] = V_134 ;
++ V_203 ;
continue;
}
if ( V_8 )
V_75 = F_52 ( & V_6 -> V_183 . V_186 ) ;
else {
V_75 = 0 ;
if ( V_6 -> V_183 . V_103 ) {
V_201 = F_52 ( & V_6 -> V_183 . V_188 ) ;
if ( V_201 < 0x80000000L )
V_75 = 0x80000000L - V_201 ;
}
F_51 ( & V_6 -> V_183 . V_186 , V_75 ) ;
}
V_6 -> V_183 . V_134 = V_134 ;
if ( V_6 -> V_183 . V_184 & V_185 )
V_75 = 0 ;
F_41 ( V_134 , V_75 ) ;
F_59 ( V_6 ) ;
}
V_10 -> V_193 = V_203 ;
V_10 -> V_11 [ 0 ] |= V_108 | V_209 ;
V_205:
F_16 ( V_8 ) ;
V_7 = F_11 ( V_8 , V_10 ) ;
F_63 () ;
if ( V_10 -> V_66 )
V_17 -> V_210 ( V_10 -> V_211 ) ;
F_60 ( V_10 , V_7 ) ;
if ( V_10 -> V_11 [ 2 ] & V_20 ) {
F_63 () ;
F_35 ( V_56 , V_10 -> V_11 [ 2 ] ) ;
}
V_116:
F_46 ( V_18 ) ;
}
static int F_66 ( struct V_5 * V_212 , int V_213 ,
struct V_5 * V_168 [] , T_1 * V_207 ,
unsigned int * V_18 )
{
int V_174 = 0 ;
struct V_5 * V_6 ;
if ( ! F_67 ( V_212 ) ) {
if ( V_174 >= V_213 )
return - 1 ;
V_168 [ V_174 ] = V_212 ;
V_18 [ V_174 ] = V_212 -> V_183 . V_214 ;
V_207 [ V_174 ++ ] = V_212 -> V_183 . V_91 ;
}
F_68 (event, &group->sibling_list, group_entry) {
if ( ! F_67 ( V_6 ) &&
V_6 -> V_184 != V_215 ) {
if ( V_174 >= V_213 )
return - 1 ;
V_168 [ V_174 ] = V_6 ;
V_18 [ V_174 ] = V_6 -> V_183 . V_214 ;
V_207 [ V_174 ++ ] = V_6 -> V_183 . V_91 ;
}
}
return V_174 ;
}
static int F_69 ( struct V_5 * V_6 , int V_216 )
{
struct V_9 * V_10 ;
unsigned long V_18 ;
int V_217 ;
int V_71 = - V_180 ;
F_43 ( V_18 ) ;
F_70 ( V_6 -> V_67 ) ;
V_10 = F_24 ( & V_9 ) ;
V_217 = V_10 -> V_204 ;
if ( V_217 >= V_17 -> V_140 )
goto V_116;
V_10 -> V_6 [ V_217 ] = V_6 ;
V_10 -> V_207 [ V_217 ] = V_6 -> V_183 . V_91 ;
V_10 -> V_18 [ V_217 ] = V_6 -> V_183 . V_214 ;
if ( ! ( V_216 & V_218 ) )
V_6 -> V_183 . V_184 = V_185 | V_219 ;
else
V_6 -> V_183 . V_184 = 0 ;
if ( V_10 -> V_220 & V_221 )
goto V_222;
if ( F_48 ( V_10 -> V_6 , V_10 -> V_18 , V_217 , 1 ) )
goto V_116;
if ( F_47 ( V_10 , V_10 -> V_207 , V_10 -> V_18 , V_217 + 1 ) )
goto V_116;
V_6 -> V_183 . V_91 = V_10 -> V_207 [ V_217 ] ;
V_222:
F_9 ( V_6 ) ;
++ V_10 -> V_204 ;
++ V_10 -> V_200 ;
V_71 = 0 ;
V_116:
if ( F_71 ( V_6 ) ) {
F_12 ( V_6 ) ;
V_10 -> V_211 = V_17 -> V_223 (
V_6 -> V_90 . V_224 ) ;
}
F_72 ( V_6 -> V_67 ) ;
F_46 ( V_18 ) ;
return V_71 ;
}
static void F_73 ( struct V_5 * V_6 , int V_216 )
{
struct V_9 * V_10 ;
long V_139 ;
unsigned long V_18 ;
F_43 ( V_18 ) ;
F_70 ( V_6 -> V_67 ) ;
F_50 ( V_6 ) ;
V_10 = F_24 ( & V_9 ) ;
for ( V_139 = 0 ; V_139 < V_10 -> V_204 ; ++ V_139 ) {
if ( V_6 == V_10 -> V_6 [ V_139 ] ) {
while ( ++ V_139 < V_10 -> V_204 ) {
V_10 -> V_6 [ V_139 - 1 ] = V_10 -> V_6 [ V_139 ] ;
V_10 -> V_207 [ V_139 - 1 ] = V_10 -> V_207 [ V_139 ] ;
V_10 -> V_18 [ V_139 - 1 ] = V_10 -> V_18 [ V_139 ] ;
}
-- V_10 -> V_204 ;
V_17 -> V_225 ( V_6 -> V_183 . V_134 - 1 , V_10 -> V_11 ) ;
if ( V_6 -> V_183 . V_134 ) {
F_41 ( V_6 -> V_183 . V_134 , 0 ) ;
V_6 -> V_183 . V_134 = 0 ;
}
F_59 ( V_6 ) ;
break;
}
}
for ( V_139 = 0 ; V_139 < V_10 -> V_193 ; ++ V_139 )
if ( V_6 == V_10 -> V_194 [ V_139 ] )
break;
if ( V_139 < V_10 -> V_193 ) {
while ( ++ V_139 < V_10 -> V_193 ) {
V_10 -> V_194 [ V_139 - 1 ] = V_10 -> V_194 [ V_139 ] ;
V_10 -> V_195 [ V_139 - 1 ] = V_10 -> V_195 [ V_139 ] ;
}
-- V_10 -> V_193 ;
}
if ( V_10 -> V_204 == 0 ) {
V_10 -> V_11 [ 0 ] &= ~ ( V_108 | V_209 ) ;
}
if ( F_71 ( V_6 ) )
F_13 ( V_6 ) ;
F_72 ( V_6 -> V_67 ) ;
F_46 ( V_18 ) ;
}
static void F_74 ( struct V_5 * V_6 , int V_216 )
{
unsigned long V_18 ;
T_4 V_201 ;
unsigned long V_75 ;
if ( ! V_6 -> V_183 . V_134 || ! V_6 -> V_183 . V_103 )
return;
if ( ! ( V_6 -> V_183 . V_184 & V_185 ) )
return;
if ( V_216 & V_226 )
F_26 ( ! ( V_6 -> V_183 . V_184 & V_219 ) ) ;
F_43 ( V_18 ) ;
F_70 ( V_6 -> V_67 ) ;
V_6 -> V_183 . V_184 = 0 ;
V_201 = F_52 ( & V_6 -> V_183 . V_188 ) ;
V_75 = 0 ;
if ( V_201 < 0x80000000L )
V_75 = 0x80000000L - V_201 ;
F_41 ( V_6 -> V_183 . V_134 , V_75 ) ;
F_59 ( V_6 ) ;
F_72 ( V_6 -> V_67 ) ;
F_46 ( V_18 ) ;
}
static void F_75 ( struct V_5 * V_6 , int V_216 )
{
unsigned long V_18 ;
if ( ! V_6 -> V_183 . V_134 || ! V_6 -> V_183 . V_103 )
return;
if ( V_6 -> V_183 . V_184 & V_185 )
return;
F_43 ( V_18 ) ;
F_70 ( V_6 -> V_67 ) ;
F_50 ( V_6 ) ;
V_6 -> V_183 . V_184 |= V_185 | V_219 ;
F_41 ( V_6 -> V_183 . V_134 , 0 ) ;
F_59 ( V_6 ) ;
F_72 ( V_6 -> V_67 ) ;
F_46 ( V_18 ) ;
}
static void F_76 ( struct V_67 * V_67 )
{
struct V_9 * V_10 = F_24 ( & V_9 ) ;
F_70 ( V_67 ) ;
V_10 -> V_220 |= V_221 ;
V_10 -> V_227 = V_10 -> V_204 ;
}
static void F_77 ( struct V_67 * V_67 )
{
struct V_9 * V_10 = F_24 ( & V_9 ) ;
V_10 -> V_220 &= ~ V_221 ;
F_72 ( V_67 ) ;
}
static int F_78 ( struct V_67 * V_67 )
{
struct V_9 * V_10 ;
long V_139 , V_174 ;
if ( ! V_17 )
return - V_180 ;
V_10 = F_24 ( & V_9 ) ;
V_174 = V_10 -> V_204 ;
if ( F_48 ( V_10 -> V_6 , V_10 -> V_18 , 0 , V_174 ) )
return - V_180 ;
V_139 = F_47 ( V_10 , V_10 -> V_207 , V_10 -> V_18 , V_174 ) ;
if ( V_139 < 0 )
return - V_180 ;
for ( V_139 = V_10 -> V_227 ; V_139 < V_174 ; ++ V_139 )
V_10 -> V_6 [ V_139 ] -> V_183 . V_91 = V_10 -> V_207 [ V_139 ] ;
V_10 -> V_220 &= ~ V_221 ;
F_72 ( V_67 ) ;
return 0 ;
}
static int F_79 ( struct V_5 * V_6 , T_1 V_228 ,
unsigned int V_18 )
{
int V_174 ;
T_1 V_229 [ V_230 ] ;
if ( V_6 -> V_90 . V_177
|| V_6 -> V_90 . V_178
|| V_6 -> V_90 . V_179
|| V_6 -> V_90 . V_103 )
return 0 ;
if ( V_17 -> V_162 ( V_228 ) )
return 1 ;
if ( ! V_17 -> V_163 )
return 0 ;
V_18 |= V_176 | V_161 ;
V_174 = V_17 -> V_163 ( V_228 , V_18 , V_229 ) ;
return V_174 > 0 ;
}
static T_1 F_80 ( T_1 V_228 , unsigned long V_18 )
{
T_1 V_229 [ V_230 ] ;
int V_174 ;
V_18 &= ~ ( V_176 | V_161 ) ;
V_174 = V_17 -> V_163 ( V_228 , V_18 , V_229 ) ;
if ( ! V_174 )
return 0 ;
return V_229 [ 0 ] ;
}
static void F_81 ( struct V_5 * V_6 )
{
if ( ! F_82 ( & V_231 , - 1 , 1 ) ) {
F_83 ( & V_232 ) ;
if ( F_84 ( & V_231 ) == 0 )
F_85 () ;
F_86 ( & V_232 ) ;
}
}
static int F_87 ( T_1 V_91 , T_1 * V_233 )
{
unsigned long type , V_234 , V_4 ;
int V_228 ;
if ( ! V_17 -> V_235 )
return - V_95 ;
type = V_91 & 0xff ;
V_234 = ( V_91 >> 8 ) & 0xff ;
V_4 = ( V_91 >> 16 ) & 0xff ;
if ( type >= V_236 ||
V_234 >= V_237 ||
V_4 >= V_238 )
return - V_95 ;
V_228 = ( * V_17 -> V_235 ) [ type ] [ V_234 ] [ V_4 ] ;
if ( V_228 == 0 )
return - V_239 ;
if ( V_228 == - 1 )
return - V_95 ;
* V_233 = V_228 ;
return 0 ;
}
static int F_88 ( struct V_5 * V_6 )
{
T_1 V_228 ;
unsigned long V_18 ;
struct V_5 * V_168 [ V_138 ] ;
T_1 V_207 [ V_138 ] ;
unsigned int V_147 [ V_138 ] ;
int V_174 ;
int V_240 ;
struct V_9 * V_10 ;
if ( ! V_17 )
return - V_241 ;
if ( F_71 ( V_6 ) ) {
if ( ! ( V_17 -> V_18 & V_89 ) )
return - V_239 ;
}
switch ( V_6 -> V_90 . type ) {
case V_242 :
V_228 = V_6 -> V_90 . V_91 ;
if ( V_228 >= V_17 -> V_243 || V_17 -> V_244 [ V_228 ] == 0 )
return - V_239 ;
V_228 = V_17 -> V_244 [ V_228 ] ;
break;
case V_245 :
V_240 = F_87 ( V_6 -> V_90 . V_91 , & V_228 ) ;
if ( V_240 )
return V_240 ;
break;
case V_246 :
V_228 = V_6 -> V_90 . V_91 ;
break;
default:
return - V_241 ;
}
V_6 -> V_183 . V_247 = V_228 ;
V_6 -> V_183 . V_134 = 0 ;
if ( ! F_89 ( V_248 ) )
V_6 -> V_90 . V_179 = 0 ;
V_18 = 0 ;
if ( V_6 -> V_96 & V_97 )
V_18 |= V_249 ;
if ( V_17 -> V_18 & V_190 ) {
if ( F_79 ( V_6 , V_228 , V_18 ) ) {
V_18 |= V_176 ;
} else if ( V_17 -> V_162 ( V_228 ) ) {
V_228 = F_80 ( V_228 , V_18 ) ;
if ( ! V_228 )
return - V_95 ;
}
}
V_240 = F_8 ( V_6 ) ;
if ( V_240 )
return V_240 ;
V_174 = 0 ;
if ( V_6 -> V_94 != V_6 ) {
V_174 = F_66 ( V_6 -> V_94 , V_17 -> V_140 - 1 ,
V_168 , V_207 , V_147 ) ;
if ( V_174 < 0 )
return - V_95 ;
}
V_207 [ V_174 ] = V_228 ;
V_168 [ V_174 ] = V_6 ;
V_147 [ V_174 ] = V_18 ;
if ( F_48 ( V_168 , V_147 , V_174 , 1 ) )
return - V_95 ;
V_10 = & F_90 ( V_9 ) ;
V_240 = F_47 ( V_10 , V_207 , V_147 , V_174 + 1 ) ;
if ( F_71 ( V_6 ) ) {
V_10 -> V_211 = V_17 -> V_223 (
V_6 -> V_90 . V_224 ) ;
if ( V_10 -> V_211 == - 1 ) {
F_91 ( V_9 ) ;
return - V_239 ;
}
}
F_91 ( V_9 ) ;
if ( V_240 )
return - V_95 ;
V_6 -> V_183 . V_91 = V_207 [ V_174 ] ;
V_6 -> V_183 . V_214 = V_147 [ V_174 ] ;
V_6 -> V_183 . V_250 = V_6 -> V_183 . V_103 ;
F_51 ( & V_6 -> V_183 . V_188 , V_6 -> V_183 . V_250 ) ;
if ( F_7 ( V_6 ) )
F_51 ( & V_6 -> V_183 . V_186 , 0 ) ;
V_240 = 0 ;
if ( ! F_92 ( & V_231 ) ) {
F_83 ( & V_232 ) ;
if ( F_93 ( & V_231 ) == 0 &&
F_94 ( V_251 ) )
V_240 = - V_252 ;
else
F_95 ( & V_231 ) ;
F_86 ( & V_232 ) ;
}
V_6 -> V_253 = F_81 ;
return V_240 ;
}
static int F_96 ( struct V_5 * V_6 )
{
return V_6 -> V_183 . V_134 ;
}
T_5 F_97 ( struct V_254 * V_255 ,
struct V_256 * V_90 , char * V_257 )
{
struct V_258 * V_259 ;
V_259 = F_98 ( V_90 , struct V_258 , V_90 ) ;
return sprintf ( V_257 , L_11 , V_259 -> V_260 ) ;
}
static void F_99 ( struct V_5 * V_6 , unsigned long V_75 ,
struct V_1 * V_2 )
{
T_1 V_261 = V_6 -> V_183 . V_103 ;
T_4 V_181 , V_182 , V_201 ;
int V_262 = 0 ;
if ( V_6 -> V_183 . V_184 & V_185 ) {
F_41 ( V_6 -> V_183 . V_134 , 0 ) ;
return;
}
V_181 = F_52 ( & V_6 -> V_183 . V_186 ) ;
V_182 = F_49 ( V_181 , V_75 ) ;
F_55 ( V_182 , & V_6 -> V_187 ) ;
V_75 = 0 ;
V_201 = F_52 ( & V_6 -> V_183 . V_188 ) - V_182 ;
if ( V_182 == 0 )
V_201 ++ ;
if ( V_261 ) {
if ( V_201 <= 0 ) {
V_201 += V_261 ;
if ( V_201 <= 0 )
V_201 = V_261 ;
V_262 = F_6 ( V_2 ) ;
V_6 -> V_183 . V_250 = V_6 -> V_183 . V_103 ;
}
if ( V_201 < 0x80000000LL )
V_75 = 0x80000000LL - V_201 ;
}
F_41 ( V_6 -> V_183 . V_134 , V_75 ) ;
F_51 ( & V_6 -> V_183 . V_186 , V_75 ) ;
F_51 ( & V_6 -> V_183 . V_188 , V_201 ) ;
F_59 ( V_6 ) ;
if ( V_262 ) {
struct V_263 V_264 ;
F_100 ( & V_264 , ~ 0ULL , V_6 -> V_183 . V_250 ) ;
if ( V_6 -> V_90 . V_102 & V_265 )
F_2 ( V_2 , & V_264 . V_69 ) ;
if ( V_6 -> V_90 . V_102 & V_266 ) {
struct V_9 * V_10 ;
V_10 = F_24 ( & V_9 ) ;
F_15 ( V_10 ) ;
V_264 . V_267 = & V_10 -> V_87 ;
}
if ( F_101 ( V_6 , & V_264 , V_2 ) )
F_75 ( V_6 , 0 ) ;
}
}
unsigned long F_102 ( struct V_1 * V_2 )
{
T_2 V_18 = F_3 ( V_2 ) ;
if ( V_18 )
return V_18 ;
return F_103 ( V_2 ) ? V_45 :
V_50 ;
}
unsigned long F_104 ( struct V_1 * V_2 )
{
bool V_51 = F_17 ( V_2 ) ;
if ( V_51 && F_6 ( V_2 ) )
return F_19 ( V_54 ) + F_1 ( V_2 ) ;
else if ( V_51 )
return 0 ;
else
return V_2 -> V_268 ;
}
static bool F_105 ( unsigned long V_75 )
{
if ( ( 0x80000000 - V_75 ) <= 256 )
return true ;
return false ;
}
static bool F_106 ( unsigned long V_75 )
{
if ( ( int ) V_75 < 0 )
return true ;
return false ;
}
static void V_251 ( struct V_1 * V_2 )
{
int V_139 , V_156 ;
struct V_9 * V_10 = F_24 ( & V_9 ) ;
struct V_5 * V_6 ;
unsigned long V_75 [ 8 ] ;
int V_269 , V_270 ;
int V_271 ;
if ( V_10 -> V_193 )
F_57 ( V_10 , F_19 ( V_129 ) ,
F_19 ( V_130 ) ) ;
F_4 ( V_2 ) ;
V_271 = F_5 ( V_2 ) ;
if ( V_271 )
F_107 () ;
else
F_108 () ;
for ( V_139 = 0 ; V_139 < V_17 -> V_140 ; ++ V_139 )
V_75 [ V_139 ] = F_38 ( V_139 + 1 ) ;
V_269 = 0 ;
for ( V_139 = 0 ; V_139 < V_17 -> V_140 ; ++ V_139 ) {
if ( ! F_106 ( V_75 [ V_139 ] ) )
continue;
if ( F_56 ( V_139 + 1 ) )
continue;
V_269 = 1 ;
V_270 = 0 ;
for ( V_156 = 0 ; V_156 < V_10 -> V_204 ; ++ V_156 ) {
V_6 = V_10 -> V_6 [ V_156 ] ;
if ( V_6 -> V_183 . V_134 == ( V_139 + 1 ) ) {
V_270 = 1 ;
F_99 ( V_6 , V_75 [ V_139 ] , V_2 ) ;
break;
}
}
if ( ! V_270 )
F_41 ( V_139 + 1 , 0 ) ;
}
if ( ! V_269 && F_109 ( V_272 ) ) {
for ( V_139 = 0 ; V_139 < V_10 -> V_204 ; ++ V_139 ) {
V_6 = V_10 -> V_6 [ V_139 ] ;
if ( ! V_6 -> V_183 . V_134 || F_56 ( V_6 -> V_183 . V_134 ) )
continue;
if ( F_105 ( V_75 [ V_6 -> V_183 . V_134 - 1 ] ) ) {
V_269 = 1 ;
F_99 ( V_6 ,
V_75 [ V_6 -> V_183 . V_134 - 1 ] ,
V_2 ) ;
}
}
}
if ( ! V_269 && ! V_271 && F_110 () )
F_40 ( V_273 L_12 ) ;
F_60 ( V_10 , V_10 -> V_11 [ 0 ] ) ;
if ( V_271 )
F_111 () ;
else
F_112 () ;
}
static void F_113 ( int V_274 )
{
struct V_9 * V_10 = & F_114 ( V_9 , V_274 ) ;
if ( ! V_17 )
return;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_11 [ 0 ] = V_133 ;
}
static int
F_115 ( struct V_275 * V_276 , unsigned long V_277 , void * V_278 )
{
unsigned int V_274 = ( long ) V_278 ;
switch ( V_277 & ~ V_279 ) {
case V_280 :
F_113 ( V_274 ) ;
break;
default:
break;
}
return V_281 ;
}
int F_116 ( struct V_282 * V_67 )
{
if ( V_17 )
return - V_252 ;
V_17 = V_67 ;
F_44 ( L_13 ,
V_67 -> V_141 ) ;
V_282 . V_283 = V_17 -> V_283 ;
#ifdef V_46
if ( F_117 () & V_46 )
V_47 = V_48 ;
#endif
F_118 ( & V_282 , L_14 , V_246 ) ;
F_119 ( F_115 ) ;
return 0 ;
}
