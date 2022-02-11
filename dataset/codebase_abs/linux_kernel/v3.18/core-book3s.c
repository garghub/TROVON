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
static void F_14 ( void ) {}
static inline void F_15 ( struct V_9 * V_10 ) {}
static void F_16 ( bool V_8 ) { }
static bool F_17 ( struct V_1 * V_2 )
{
return ! ! V_2 -> V_4 ;
}
static inline unsigned long F_1 ( struct V_1 * V_2 )
{
unsigned long V_12 = V_2 -> V_13 ;
if ( ( V_14 -> V_15 & V_16 ) && ( V_12 & V_17 ) ) {
unsigned long V_18 = ( V_12 & V_19 ) >> V_20 ;
if ( V_18 > 1 )
return 4 * ( V_18 - 1 ) ;
}
return 0 ;
}
static inline void F_2 ( struct V_1 * V_2 , T_1 * V_3 )
{
unsigned long V_12 = V_2 -> V_13 ;
bool V_21 ;
if ( V_14 -> V_15 & V_22 )
V_21 = V_2 -> V_23 & V_24 ;
else {
unsigned long V_25 ;
if ( V_14 -> V_15 & V_26 )
V_25 = V_27 ;
else if ( V_14 -> V_15 & V_28 )
V_25 = V_29 ;
else
V_25 = V_30 ;
V_21 = V_12 & V_25 ;
}
if ( ! ( V_12 & V_17 ) || V_21 )
* V_3 = F_18 ( V_31 ) ;
}
static bool F_19 ( struct V_1 * V_2 )
{
unsigned long V_32 = V_33 ;
if ( V_14 -> V_15 & V_22 )
return ! ! ( V_2 -> V_23 & V_34 ) ;
if ( V_14 -> V_15 & V_28 )
V_32 = V_35 ;
return ! ! ( V_2 -> V_13 & V_32 ) ;
}
static bool F_20 ( struct V_1 * V_2 )
{
unsigned long V_36 = V_37 ;
if ( V_14 -> V_15 & V_22 )
return ! ! ( V_2 -> V_23 & V_38 ) ;
if ( V_14 -> V_15 & V_28 )
V_36 = V_39 ;
return ! ! ( V_2 -> V_13 & V_36 ) ;
}
static inline T_2 F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_40 & V_41 )
return V_42 ;
if ( ( V_2 -> V_40 & V_43 ) && V_44 != V_45 )
return V_46 ;
return V_47 ;
}
static inline T_2 F_3 ( struct V_1 * V_2 )
{
bool V_48 = F_17 ( V_2 ) ;
if ( ! V_48 )
return F_21 ( V_2 ) ;
if ( V_14 -> V_15 & V_49 ) {
unsigned long V_50 = F_18 ( V_51 ) ;
if ( V_50 >= V_52 )
return V_47 ;
return V_42 ;
}
if ( F_20 ( V_2 ) )
return V_42 ;
if ( F_19 ( V_2 ) && ( V_44 != V_45 ) )
return V_46 ;
return V_47 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
unsigned long V_12 = F_18 ( V_53 ) ;
int V_54 = V_12 & V_17 ;
int V_48 ;
V_2 -> V_13 = V_12 ;
if ( V_14 -> V_15 & V_22 )
V_2 -> V_23 = F_18 ( V_55 ) ;
if ( F_22 ( V_2 ) != 0xf00 )
V_48 = 0 ;
else if ( V_54 )
V_48 = 1 ;
else if ( ( V_14 -> V_15 & V_56 ) )
V_48 = 0 ;
else if ( ! ( V_14 -> V_15 & V_49 ) && F_20 ( V_2 ) )
V_48 = 0 ;
else
V_48 = 1 ;
V_2 -> V_4 = V_48 ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
return ! V_2 -> V_57 ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
unsigned long V_12 = V_2 -> V_13 ;
int V_54 = V_12 & V_17 ;
if ( V_54 ) {
if ( V_14 -> V_15 & V_22 )
return V_2 -> V_23 & V_58 ;
if ( V_14 -> V_15 & V_26 )
return V_12 & V_59 ;
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
if ( ! V_14 -> V_60 )
return;
if ( V_6 -> V_61 -> V_62 && V_10 -> V_63 != V_6 -> V_61 ) {
F_23 () ;
V_10 -> V_63 = V_6 -> V_61 ;
}
V_10 -> V_64 ++ ;
}
static void F_13 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = & F_24 ( V_9 ) ;
if ( ! V_14 -> V_60 )
return;
V_10 -> V_64 -- ;
F_25 ( V_10 -> V_64 < 0 ) ;
if ( ! V_10 -> V_65 && ! V_10 -> V_64 ) {
V_10 -> V_63 = NULL ;
}
}
static void F_14 ( void )
{
if ( V_14 -> V_60 )
F_23 () ;
}
static T_3 F_26 ( T_1 V_66 )
{
unsigned int V_67 ;
int V_68 ;
T_3 V_69 ;
if ( F_27 ( V_66 ) )
return F_28 ( ( unsigned int * ) V_66 ) ;
F_29 () ;
V_68 = F_30 ( V_67 , ( unsigned int V_70 * ) V_66 ) ;
if ( V_68 ) {
F_31 () ;
return 0 ;
}
F_31 () ;
V_69 = F_28 ( & V_67 ) ;
if ( ( ! V_69 ) || ( V_67 & V_71 ) )
return V_69 ;
return V_69 - ( unsigned long ) & V_67 + V_66 ;
}
static void F_15 ( struct V_9 * V_10 )
{
T_1 V_72 ;
T_1 V_66 ;
int V_73 , V_74 , V_75 ;
V_73 = 0 ;
V_74 = 0 ;
while ( V_73 < V_14 -> V_60 ) {
V_72 = F_32 ( V_73 ++ ) ;
if ( ! V_72 )
break;
else {
V_66 = V_72 & V_76 ;
V_75 = V_72 & V_77 ;
if ( ! V_66 )
continue;
if ( V_72 & V_78 ) {
V_10 -> V_79 [ V_74 ] . V_80 = V_66 ;
V_10 -> V_79 [ V_74 ] . V_81 = V_75 ;
V_10 -> V_79 [ V_74 ] . V_82 = ~ V_75 ;
V_72 = F_32 ( V_73 ++ ) ;
V_66 = V_72 & V_76 ;
if ( V_72 & V_78 ) {
V_73 -- ;
V_66 = 0 ;
}
V_10 -> V_79 [ V_74 ] . V_83 = V_66 ;
} else {
V_10 -> V_79 [ V_74 ] . V_83 = V_66 ;
V_10 -> V_79 [ V_74 ] . V_80 =
F_26 ( V_66 ) ;
V_10 -> V_79 [ V_74 ] . V_81 = V_75 ;
V_10 -> V_79 [ V_74 ] . V_82 = ~ V_75 ;
}
V_74 ++ ;
}
}
V_10 -> V_84 . V_85 = V_74 ;
return;
}
static bool F_7 ( struct V_5 * V_6 )
{
return ( V_14 -> V_15 & V_86 ) &&
( ( V_6 -> V_87 . V_88 >> V_89 ) & 1 ) ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_5 * V_90 = V_6 -> V_91 ;
if ( F_7 ( V_90 ) != F_7 ( V_6 ) )
return - V_92 ;
if ( F_7 ( V_6 ) ) {
if ( ! ( V_6 -> V_93 & V_94 ) )
return - V_92 ;
if ( ! V_90 -> V_87 . V_95 || ! V_90 -> V_87 . V_96 )
return - V_92 ;
if ( V_6 -> V_87 . V_97 ||
V_6 -> V_87 . V_98 ||
V_6 -> V_87 . V_99 ||
V_6 -> V_87 . V_100 ||
V_6 -> V_87 . V_101 )
return - V_92 ;
}
return 0 ;
}
static void F_9 ( struct V_5 * V_6 )
{
if ( ! F_7 ( V_6 ) || V_102 -> V_103 . V_104 )
return;
V_102 -> V_103 . V_104 = 1 ;
V_102 -> V_103 . V_7 |= V_105 ;
}
static void F_10 ( unsigned long V_7 )
{
if ( ! ( V_7 & V_106 ) )
return;
V_102 -> V_103 . V_50 = F_18 ( V_51 ) ;
V_102 -> V_103 . V_107 = F_18 ( V_55 ) ;
V_102 -> V_103 . V_108 = F_18 ( V_31 ) ;
V_102 -> V_103 . V_7 = V_7 & V_109 ;
V_102 -> V_103 . V_110 = F_18 ( V_111 ) & V_112 ;
}
static unsigned long F_11 ( bool V_8 , struct V_9 * V_10 )
{
unsigned long V_7 = V_10 -> V_11 [ 0 ] ;
if ( ! V_8 )
goto V_113;
V_7 |= V_106 | V_114 | V_115 ;
V_7 |= V_102 -> V_103 . V_7 ;
if ( ! ( V_102 -> V_103 . V_7 & V_105 ) )
V_7 &= ~ V_105 ;
F_33 ( V_51 , V_102 -> V_103 . V_50 ) ;
F_33 ( V_55 , V_102 -> V_103 . V_107 ) ;
F_33 ( V_31 , V_102 -> V_103 . V_108 ) ;
F_33 ( V_111 , V_10 -> V_11 [ 3 ] | V_102 -> V_103 . V_110 ) ;
V_113:
return V_7 ;
}
static void F_16 ( bool V_8 )
{
unsigned V_116 [ 6 ] ;
if ( ! F_34 ( V_117 ) )
return;
if ( ( V_102 -> V_103 . V_7 & ( V_118 | V_119 ) ) != V_118 )
return;
if ( V_8 && ! ( V_102 -> V_103 . V_120 & V_121 ) )
return;
F_35 () ;
V_116 [ 0 ] = F_18 ( V_122 ) ;
V_116 [ 1 ] = F_18 ( V_123 ) ;
V_116 [ 2 ] = F_18 ( V_124 ) ;
V_116 [ 3 ] = F_18 ( V_125 ) ;
V_116 [ 4 ] = F_18 ( V_126 ) ;
V_116 [ 5 ] = F_18 ( V_127 ) ;
F_33 ( V_111 , 0 ) ;
F_33 ( V_127 , 0x7FFFFFFE ) ;
F_33 ( V_128 , V_105 | V_129 | V_118 ) ;
F_33 ( V_128 , V_130 | V_118 ) ;
F_33 ( V_122 , V_116 [ 0 ] ) ;
F_33 ( V_123 , V_116 [ 1 ] ) ;
F_33 ( V_124 , V_116 [ 2 ] ) ;
F_33 ( V_125 , V_116 [ 3 ] ) ;
F_33 ( V_126 , V_116 [ 4 ] ) ;
F_33 ( V_127 , V_116 [ 5 ] ) ;
}
static unsigned long F_36 ( int V_131 )
{
unsigned long V_72 ;
switch ( V_131 ) {
case 1 :
V_72 = F_18 ( V_122 ) ;
break;
case 2 :
V_72 = F_18 ( V_123 ) ;
break;
case 3 :
V_72 = F_18 ( V_124 ) ;
break;
case 4 :
V_72 = F_18 ( V_125 ) ;
break;
case 5 :
V_72 = F_18 ( V_126 ) ;
break;
case 6 :
V_72 = F_18 ( V_127 ) ;
break;
#ifdef F_37
case 7 :
V_72 = F_18 ( V_132 ) ;
break;
case 8 :
V_72 = F_18 ( V_133 ) ;
break;
#endif
default:
F_38 ( V_134 L_1 , V_131 ) ;
V_72 = 0 ;
}
return V_72 ;
}
static void F_39 ( int V_131 , unsigned long V_72 )
{
switch ( V_131 ) {
case 1 :
F_33 ( V_122 , V_72 ) ;
break;
case 2 :
F_33 ( V_123 , V_72 ) ;
break;
case 3 :
F_33 ( V_124 , V_72 ) ;
break;
case 4 :
F_33 ( V_125 , V_72 ) ;
break;
case 5 :
F_33 ( V_126 , V_72 ) ;
break;
case 6 :
F_33 ( V_127 , V_72 ) ;
break;
#ifdef F_37
case 7 :
F_33 ( V_132 , V_72 ) ;
break;
case 8 :
F_33 ( V_133 , V_72 ) ;
break;
#endif
default:
F_38 ( V_134 L_2 , V_131 ) ;
}
}
void F_40 ( void )
{
unsigned long V_108 , V_107 , V_15 ;
T_2 V_116 [ V_135 ] ;
int V_136 ;
if ( ! V_14 -> V_137 )
return;
F_41 ( V_15 ) ;
F_42 ( L_3 ,
F_43 () , V_14 -> V_138 , V_14 -> V_137 ) ;
for ( V_136 = 0 ; V_136 < V_14 -> V_137 ; V_136 ++ )
V_116 [ V_136 ] = F_36 ( V_136 + 1 ) ;
for (; V_136 < V_135 ; V_136 ++ )
V_116 [ V_136 ] = 0xdeadbeef ;
F_42 ( L_4 ,
V_116 [ 0 ] , V_116 [ 1 ] , V_116 [ 2 ] , V_116 [ 3 ] ) ;
if ( V_14 -> V_137 > 4 )
F_42 ( L_5 ,
V_116 [ 4 ] , V_116 [ 5 ] , V_116 [ 6 ] , V_116 [ 7 ] ) ;
F_42 ( L_6 ,
F_18 ( V_128 ) , F_18 ( V_139 ) , F_18 ( V_53 ) ) ;
V_108 = V_107 = 0 ;
#ifdef F_37
V_108 = F_18 ( V_31 ) ;
if ( V_14 -> V_15 & V_22 )
V_107 = F_18 ( V_55 ) ;
if ( V_14 -> V_15 & V_86 ) {
F_42 ( L_7 ,
F_18 ( V_111 ) , F_18 ( V_140 ) ) ;
F_42 ( L_8 ,
F_18 ( V_141 ) , F_18 ( V_142 ) ) ;
}
#endif
F_42 ( L_9 ,
F_18 ( V_51 ) , V_108 , V_107 ) ;
F_44 ( V_15 ) ;
}
static int F_45 ( struct V_9 * V_10 ,
T_1 V_143 [] , unsigned int V_144 [] ,
int V_145 )
{
unsigned long V_146 , V_147 , V_148 ;
unsigned long V_149 [ V_135 ] , V_150 [ V_135 ] ;
int V_151 [ V_135 ] , V_152 [ V_135 ] ;
int V_136 , V_153 ;
unsigned long V_154 = V_14 -> V_155 ;
unsigned long V_156 = V_14 -> V_157 ;
if ( V_145 > V_14 -> V_137 )
return - 1 ;
for ( V_136 = 0 ; V_136 < V_145 ; ++ V_136 ) {
if ( ( V_144 [ V_136 ] & V_158 )
&& ! V_14 -> V_159 ( V_143 [ V_136 ] ) ) {
V_14 -> V_160 ( V_143 [ V_136 ] , V_144 [ V_136 ] ,
V_10 -> V_161 [ V_136 ] ) ;
V_143 [ V_136 ] = V_10 -> V_161 [ V_136 ] [ 0 ] ;
}
if ( V_14 -> V_162 ( V_143 [ V_136 ] , & V_10 -> V_163 [ V_136 ] [ 0 ] ,
& V_10 -> V_164 [ V_136 ] [ 0 ] ) )
return - 1 ;
}
V_147 = V_146 = 0 ;
for ( V_136 = 0 ; V_136 < V_145 ; ++ V_136 ) {
V_148 = ( V_147 | V_10 -> V_164 [ V_136 ] [ 0 ] ) +
( V_147 & V_10 -> V_164 [ V_136 ] [ 0 ] & V_154 ) ;
if ( ( ( ( V_148 + V_156 ) ^ V_147 ) & V_146 ) != 0 ||
( ( ( V_148 + V_156 ) ^ V_10 -> V_164 [ V_136 ] [ 0 ] ) &
V_10 -> V_163 [ V_136 ] [ 0 ] ) != 0 )
break;
V_147 = V_148 ;
V_146 |= V_10 -> V_163 [ V_136 ] [ 0 ] ;
}
if ( V_136 == V_145 )
return 0 ;
if ( ! V_14 -> V_160 )
return - 1 ;
for ( V_136 = 0 ; V_136 < V_145 ; ++ V_136 ) {
V_152 [ V_136 ] = 0 ;
V_151 [ V_136 ] = V_14 -> V_160 ( V_143 [ V_136 ] , V_144 [ V_136 ] ,
V_10 -> V_161 [ V_136 ] ) ;
for ( V_153 = 1 ; V_153 < V_151 [ V_136 ] ; ++ V_153 )
V_14 -> V_162 ( V_10 -> V_161 [ V_136 ] [ V_153 ] ,
& V_10 -> V_163 [ V_136 ] [ V_153 ] ,
& V_10 -> V_164 [ V_136 ] [ V_153 ] ) ;
}
V_136 = 0 ;
V_153 = - 1 ;
V_147 = V_146 = V_148 = 0 ;
while ( V_136 < V_145 ) {
if ( V_153 >= 0 ) {
V_147 = V_150 [ V_136 ] ;
V_146 = V_149 [ V_136 ] ;
V_153 = V_152 [ V_136 ] ;
}
while ( ++ V_153 < V_151 [ V_136 ] ) {
V_148 = ( V_147 | V_10 -> V_164 [ V_136 ] [ V_153 ] ) +
( V_147 & V_10 -> V_164 [ V_136 ] [ V_153 ] & V_154 ) ;
if ( ( ( ( V_148 + V_156 ) ^ V_147 ) & V_146 ) == 0 &&
( ( ( V_148 + V_156 ) ^ V_10 -> V_164 [ V_136 ] [ V_153 ] )
& V_10 -> V_163 [ V_136 ] [ V_153 ] ) == 0 )
break;
}
if ( V_153 >= V_151 [ V_136 ] ) {
if ( -- V_136 < 0 )
return - 1 ;
} else {
V_152 [ V_136 ] = V_153 ;
V_150 [ V_136 ] = V_147 ;
V_149 [ V_136 ] = V_146 ;
V_147 = V_148 ;
V_146 |= V_10 -> V_163 [ V_136 ] [ V_153 ] ;
++ V_136 ;
V_153 = - 1 ;
}
}
for ( V_136 = 0 ; V_136 < V_145 ; ++ V_136 )
V_143 [ V_136 ] = V_10 -> V_161 [ V_136 ] [ V_152 [ V_136 ] ] ;
return 0 ;
}
static int F_46 ( struct V_5 * * V_165 , unsigned int V_144 [] ,
int V_166 , int V_167 )
{
int V_168 = 0 , V_169 = 0 , V_170 = 0 ;
int V_136 , V_171 , V_172 ;
struct V_5 * V_6 ;
if ( V_14 -> V_15 & V_86 )
return 0 ;
V_171 = V_166 + V_167 ;
if ( V_171 <= 1 )
return 0 ;
V_172 = 1 ;
for ( V_136 = 0 ; V_136 < V_171 ; ++ V_136 ) {
if ( V_144 [ V_136 ] & V_173 ) {
V_144 [ V_136 ] &= ~ V_158 ;
continue;
}
V_6 = V_165 [ V_136 ] ;
if ( V_172 ) {
V_168 = V_6 -> V_87 . V_174 ;
V_169 = V_6 -> V_87 . V_175 ;
V_170 = V_6 -> V_87 . V_176 ;
V_172 = 0 ;
} else if ( V_6 -> V_87 . V_174 != V_168 ||
V_6 -> V_87 . V_175 != V_169 ||
V_6 -> V_87 . V_176 != V_170 ) {
return - V_177 ;
}
}
if ( V_168 || V_169 || V_170 )
for ( V_136 = 0 ; V_136 < V_171 ; ++ V_136 )
if ( V_144 [ V_136 ] & V_173 )
V_144 [ V_136 ] |= V_158 ;
return 0 ;
}
static T_1 F_47 ( T_1 V_178 , T_1 V_72 )
{
T_1 V_179 = ( V_72 - V_178 ) & 0xfffffffful ;
if ( V_178 > V_72 && ( V_178 - V_72 ) < 256 )
V_179 = 0 ;
return V_179 ;
}
static void F_48 ( struct V_5 * V_6 )
{
T_4 V_72 , V_179 , V_178 ;
if ( V_6 -> V_180 . V_181 & V_182 )
return;
if ( ! V_6 -> V_180 . V_131 )
return;
if ( F_7 ( V_6 ) ) {
V_72 = F_36 ( V_6 -> V_180 . V_131 ) ;
F_49 ( & V_6 -> V_180 . V_183 , V_72 ) ;
return;
}
do {
V_178 = F_50 ( & V_6 -> V_180 . V_183 ) ;
F_51 () ;
V_72 = F_36 ( V_6 -> V_180 . V_131 ) ;
V_179 = F_47 ( V_178 , V_72 ) ;
if ( ! V_179 )
return;
} while ( F_52 ( & V_6 -> V_180 . V_183 , V_178 , V_72 ) != V_178 );
F_53 ( V_179 , & V_6 -> V_184 ) ;
do {
V_178 = F_50 ( & V_6 -> V_180 . V_185 ) ;
V_72 = V_178 - V_179 ;
if ( V_72 < 1 )
V_72 = 1 ;
} while ( F_52 ( & V_6 -> V_180 . V_185 , V_178 , V_72 ) != V_178 );
}
static int F_54 ( int V_186 )
{
return ( V_14 -> V_15 & V_187 )
&& ( V_186 == 5 || V_186 == 6 ) ;
}
static void F_55 ( struct V_9 * V_10 ,
unsigned long V_188 , unsigned long V_189 )
{
struct V_5 * V_6 ;
T_1 V_72 , V_178 , V_179 ;
int V_136 ;
for ( V_136 = 0 ; V_136 < V_10 -> V_190 ; ++ V_136 ) {
V_6 = V_10 -> V_191 [ V_136 ] ;
if ( ! V_6 -> V_180 . V_131 )
continue;
V_72 = ( V_6 -> V_180 . V_131 == 5 ) ? V_188 : V_189 ;
V_178 = F_50 ( & V_6 -> V_180 . V_183 ) ;
V_6 -> V_180 . V_131 = 0 ;
V_179 = F_47 ( V_178 , V_72 ) ;
if ( V_179 )
F_53 ( V_179 , & V_6 -> V_184 ) ;
}
}
static void F_56 ( struct V_9 * V_10 ,
unsigned long V_188 , unsigned long V_189 )
{
struct V_5 * V_6 ;
T_1 V_72 , V_178 ;
int V_136 ;
for ( V_136 = 0 ; V_136 < V_10 -> V_190 ; ++ V_136 ) {
V_6 = V_10 -> V_191 [ V_136 ] ;
V_6 -> V_180 . V_131 = V_10 -> V_192 [ V_136 ] ;
V_72 = ( V_6 -> V_180 . V_131 == 5 ) ? V_188 : V_189 ;
V_178 = F_50 ( & V_6 -> V_180 . V_183 ) ;
if ( F_47 ( V_178 , V_72 ) )
F_49 ( & V_6 -> V_180 . V_183 , V_72 ) ;
F_57 ( V_6 ) ;
}
}
static void F_58 ( struct V_9 * V_10 , unsigned long V_7 )
{
unsigned long V_188 , V_189 ;
if ( ! V_10 -> V_190 ) {
F_33 ( V_128 , V_7 ) ;
return;
}
asm volatile("mtspr %3,%2; mfspr %0,%4; mfspr %1,%5"
: "=&r" (pmc5), "=&r" (pmc6)
: "r" (mmcr0 & ~(MMCR0_PMC1CE | MMCR0_PMCjCE)),
"i" (SPRN_MMCR0),
"i" (SPRN_PMC5), "i" (SPRN_PMC6));
if ( V_7 & V_130 )
F_55 ( V_10 , V_188 , V_189 ) ;
else
F_56 ( V_10 , V_188 , V_189 ) ;
if ( V_7 & ( V_193 | V_129 ) )
F_33 ( V_128 , V_7 ) ;
}
static void F_59 ( struct V_194 * V_194 )
{
struct V_9 * V_10 ;
unsigned long V_15 , V_7 , V_72 ;
if ( ! V_14 )
return;
F_41 ( V_15 ) ;
V_10 = & F_24 ( V_9 ) ;
if ( ! V_10 -> V_65 ) {
if ( ! V_10 -> V_195 ) {
F_60 () ;
V_10 -> V_195 = 1 ;
}
V_72 = V_7 = F_18 ( V_128 ) ;
V_72 |= V_130 ;
V_72 &= ~ ( V_106 | V_114 | V_196 | V_118 |
V_197 ) ;
F_58 ( V_10 , V_72 ) ;
F_61 () ;
if ( V_10 -> V_11 [ 2 ] & V_17 ) {
F_33 ( V_53 ,
V_10 -> V_11 [ 2 ] & ~ V_17 ) ;
F_61 () ;
}
V_10 -> V_65 = 1 ;
V_10 -> V_198 = 0 ;
F_10 ( V_7 ) ;
}
F_44 ( V_15 ) ;
}
static void F_62 ( struct V_194 * V_194 )
{
struct V_5 * V_6 ;
struct V_9 * V_10 ;
unsigned long V_15 ;
long V_136 ;
unsigned long V_72 , V_7 ;
T_4 V_199 ;
unsigned int V_200 [ V_135 ] ;
int V_201 ;
int V_131 ;
bool V_8 ;
if ( ! V_14 )
return;
F_41 ( V_15 ) ;
V_10 = & F_24 ( V_9 ) ;
if ( ! V_10 -> V_65 )
goto V_113;
if ( V_10 -> V_202 == 0 ) {
F_63 ( 0 ) ;
goto V_113;
}
V_10 -> V_65 = 0 ;
V_8 = F_7 ( V_10 -> V_6 [ 0 ] ) ;
if ( ! V_10 -> V_198 ) {
F_33 ( V_53 , V_10 -> V_11 [ 2 ] & ~ V_17 ) ;
F_33 ( V_139 , V_10 -> V_11 [ 1 ] ) ;
goto V_203;
}
memset ( V_10 -> V_11 , 0 , sizeof( V_10 -> V_11 ) ) ;
if ( V_14 -> V_204 ( V_10 -> V_205 , V_10 -> V_202 , V_200 ,
V_10 -> V_11 , V_10 -> V_6 ) ) {
F_38 ( V_134 L_10 ) ;
goto V_113;
}
if ( ! ( V_14 -> V_15 & V_86 ) ) {
V_6 = V_10 -> V_6 [ 0 ] ;
if ( V_6 -> V_87 . V_174 )
V_10 -> V_11 [ 0 ] |= V_206 ;
if ( V_6 -> V_87 . V_175 )
V_10 -> V_11 [ 0 ] |= V_44 ;
if ( V_6 -> V_87 . V_176 )
V_10 -> V_11 [ 0 ] |= V_45 ;
}
F_63 ( 1 ) ;
F_33 ( V_53 , V_10 -> V_11 [ 2 ] & ~ V_17 ) ;
F_33 ( V_139 , V_10 -> V_11 [ 1 ] ) ;
F_33 ( V_128 , ( V_10 -> V_11 [ 0 ] & ~ ( V_193 | V_129 ) )
| V_130 ) ;
if ( V_14 -> V_15 & V_86 )
F_33 ( V_111 , V_10 -> V_11 [ 3 ] ) ;
for ( V_136 = 0 ; V_136 < V_10 -> V_202 ; ++ V_136 ) {
V_6 = V_10 -> V_6 [ V_136 ] ;
if ( V_6 -> V_180 . V_131 && V_6 -> V_180 . V_131 != V_200 [ V_136 ] + 1 ) {
F_48 ( V_6 ) ;
F_39 ( V_6 -> V_180 . V_131 , 0 ) ;
V_6 -> V_180 . V_131 = 0 ;
}
}
V_10 -> V_190 = V_201 = 0 ;
for ( V_136 = 0 ; V_136 < V_10 -> V_202 ; ++ V_136 ) {
V_6 = V_10 -> V_6 [ V_136 ] ;
if ( V_6 -> V_180 . V_131 )
continue;
V_131 = V_200 [ V_136 ] + 1 ;
if ( F_54 ( V_131 ) ) {
V_10 -> V_191 [ V_201 ] = V_6 ;
V_10 -> V_192 [ V_201 ] = V_131 ;
++ V_201 ;
continue;
}
if ( V_8 )
V_72 = F_50 ( & V_6 -> V_180 . V_183 ) ;
else {
V_72 = 0 ;
if ( V_6 -> V_180 . V_100 ) {
V_199 = F_50 ( & V_6 -> V_180 . V_185 ) ;
if ( V_199 < 0x80000000L )
V_72 = 0x80000000L - V_199 ;
}
F_49 ( & V_6 -> V_180 . V_183 , V_72 ) ;
}
V_6 -> V_180 . V_131 = V_131 ;
if ( V_6 -> V_180 . V_181 & V_182 )
V_72 = 0 ;
F_39 ( V_131 , V_72 ) ;
F_57 ( V_6 ) ;
}
V_10 -> V_190 = V_201 ;
V_10 -> V_11 [ 0 ] |= V_105 | V_207 ;
V_203:
F_16 ( V_8 ) ;
V_7 = F_11 ( V_8 , V_10 ) ;
F_61 () ;
if ( V_10 -> V_64 )
V_14 -> V_208 ( V_10 -> V_209 ) ;
F_58 ( V_10 , V_7 ) ;
if ( V_10 -> V_11 [ 2 ] & V_17 ) {
F_61 () ;
F_33 ( V_53 , V_10 -> V_11 [ 2 ] ) ;
}
V_113:
F_44 ( V_15 ) ;
}
static int F_64 ( struct V_5 * V_210 , int V_211 ,
struct V_5 * V_165 [] , T_1 * V_205 ,
unsigned int * V_15 )
{
int V_171 = 0 ;
struct V_5 * V_6 ;
if ( ! F_65 ( V_210 ) ) {
if ( V_171 >= V_211 )
return - 1 ;
V_165 [ V_171 ] = V_210 ;
V_15 [ V_171 ] = V_210 -> V_180 . V_212 ;
V_205 [ V_171 ++ ] = V_210 -> V_180 . V_88 ;
}
F_66 (event, &group->sibling_list, group_entry) {
if ( ! F_65 ( V_6 ) &&
V_6 -> V_181 != V_213 ) {
if ( V_171 >= V_211 )
return - 1 ;
V_165 [ V_171 ] = V_6 ;
V_15 [ V_171 ] = V_6 -> V_180 . V_212 ;
V_205 [ V_171 ++ ] = V_6 -> V_180 . V_88 ;
}
}
return V_171 ;
}
static int F_67 ( struct V_5 * V_6 , int V_214 )
{
struct V_9 * V_10 ;
unsigned long V_15 ;
int V_215 ;
int V_68 = - V_177 ;
F_41 ( V_15 ) ;
F_68 ( V_6 -> V_194 ) ;
V_10 = & F_24 ( V_9 ) ;
V_215 = V_10 -> V_202 ;
if ( V_215 >= V_14 -> V_137 )
goto V_113;
V_10 -> V_6 [ V_215 ] = V_6 ;
V_10 -> V_205 [ V_215 ] = V_6 -> V_180 . V_88 ;
V_10 -> V_15 [ V_215 ] = V_6 -> V_180 . V_212 ;
if ( ! ( V_214 & V_216 ) )
V_6 -> V_180 . V_181 = V_182 | V_217 ;
else
V_6 -> V_180 . V_181 = 0 ;
if ( V_10 -> V_218 & V_219 )
goto V_220;
if ( F_46 ( V_10 -> V_6 , V_10 -> V_15 , V_215 , 1 ) )
goto V_113;
if ( F_45 ( V_10 , V_10 -> V_205 , V_10 -> V_15 , V_215 + 1 ) )
goto V_113;
V_6 -> V_180 . V_88 = V_10 -> V_205 [ V_215 ] ;
V_220:
F_9 ( V_6 ) ;
++ V_10 -> V_202 ;
++ V_10 -> V_198 ;
V_68 = 0 ;
V_113:
if ( F_69 ( V_6 ) ) {
F_12 ( V_6 ) ;
V_10 -> V_209 = V_14 -> V_221 (
V_6 -> V_87 . V_222 ) ;
}
F_70 ( V_6 -> V_194 ) ;
F_44 ( V_15 ) ;
return V_68 ;
}
static void F_71 ( struct V_5 * V_6 , int V_214 )
{
struct V_9 * V_10 ;
long V_136 ;
unsigned long V_15 ;
F_41 ( V_15 ) ;
F_68 ( V_6 -> V_194 ) ;
F_48 ( V_6 ) ;
V_10 = & F_24 ( V_9 ) ;
for ( V_136 = 0 ; V_136 < V_10 -> V_202 ; ++ V_136 ) {
if ( V_6 == V_10 -> V_6 [ V_136 ] ) {
while ( ++ V_136 < V_10 -> V_202 ) {
V_10 -> V_6 [ V_136 - 1 ] = V_10 -> V_6 [ V_136 ] ;
V_10 -> V_205 [ V_136 - 1 ] = V_10 -> V_205 [ V_136 ] ;
V_10 -> V_15 [ V_136 - 1 ] = V_10 -> V_15 [ V_136 ] ;
}
-- V_10 -> V_202 ;
V_14 -> V_223 ( V_6 -> V_180 . V_131 - 1 , V_10 -> V_11 ) ;
if ( V_6 -> V_180 . V_131 ) {
F_39 ( V_6 -> V_180 . V_131 , 0 ) ;
V_6 -> V_180 . V_131 = 0 ;
}
F_57 ( V_6 ) ;
break;
}
}
for ( V_136 = 0 ; V_136 < V_10 -> V_190 ; ++ V_136 )
if ( V_6 == V_10 -> V_191 [ V_136 ] )
break;
if ( V_136 < V_10 -> V_190 ) {
while ( ++ V_136 < V_10 -> V_190 ) {
V_10 -> V_191 [ V_136 - 1 ] = V_10 -> V_191 [ V_136 ] ;
V_10 -> V_192 [ V_136 - 1 ] = V_10 -> V_192 [ V_136 ] ;
}
-- V_10 -> V_190 ;
}
if ( V_10 -> V_202 == 0 ) {
V_10 -> V_11 [ 0 ] &= ~ ( V_105 | V_207 ) ;
}
if ( F_69 ( V_6 ) )
F_13 ( V_6 ) ;
F_70 ( V_6 -> V_194 ) ;
F_44 ( V_15 ) ;
}
static void F_72 ( struct V_5 * V_6 , int V_214 )
{
unsigned long V_15 ;
T_4 V_199 ;
unsigned long V_72 ;
if ( ! V_6 -> V_180 . V_131 || ! V_6 -> V_180 . V_100 )
return;
if ( ! ( V_6 -> V_180 . V_181 & V_182 ) )
return;
if ( V_214 & V_224 )
F_25 ( ! ( V_6 -> V_180 . V_181 & V_217 ) ) ;
F_41 ( V_15 ) ;
F_68 ( V_6 -> V_194 ) ;
V_6 -> V_180 . V_181 = 0 ;
V_199 = F_50 ( & V_6 -> V_180 . V_185 ) ;
V_72 = 0 ;
if ( V_199 < 0x80000000L )
V_72 = 0x80000000L - V_199 ;
F_39 ( V_6 -> V_180 . V_131 , V_72 ) ;
F_57 ( V_6 ) ;
F_70 ( V_6 -> V_194 ) ;
F_44 ( V_15 ) ;
}
static void F_73 ( struct V_5 * V_6 , int V_214 )
{
unsigned long V_15 ;
if ( ! V_6 -> V_180 . V_131 || ! V_6 -> V_180 . V_100 )
return;
if ( V_6 -> V_180 . V_181 & V_182 )
return;
F_41 ( V_15 ) ;
F_68 ( V_6 -> V_194 ) ;
F_48 ( V_6 ) ;
V_6 -> V_180 . V_181 |= V_182 | V_217 ;
F_39 ( V_6 -> V_180 . V_131 , 0 ) ;
F_57 ( V_6 ) ;
F_70 ( V_6 -> V_194 ) ;
F_44 ( V_15 ) ;
}
static void F_74 ( struct V_194 * V_194 )
{
struct V_9 * V_10 = & F_24 ( V_9 ) ;
F_68 ( V_194 ) ;
V_10 -> V_218 |= V_219 ;
V_10 -> V_225 = V_10 -> V_202 ;
}
static void F_75 ( struct V_194 * V_194 )
{
struct V_9 * V_10 = & F_24 ( V_9 ) ;
V_10 -> V_218 &= ~ V_219 ;
F_70 ( V_194 ) ;
}
static int F_76 ( struct V_194 * V_194 )
{
struct V_9 * V_10 ;
long V_136 , V_171 ;
if ( ! V_14 )
return - V_177 ;
V_10 = & F_24 ( V_9 ) ;
V_171 = V_10 -> V_202 ;
if ( F_46 ( V_10 -> V_6 , V_10 -> V_15 , 0 , V_171 ) )
return - V_177 ;
V_136 = F_45 ( V_10 , V_10 -> V_205 , V_10 -> V_15 , V_171 ) ;
if ( V_136 < 0 )
return - V_177 ;
for ( V_136 = V_10 -> V_225 ; V_136 < V_171 ; ++ V_136 )
V_10 -> V_6 [ V_136 ] -> V_180 . V_88 = V_10 -> V_205 [ V_136 ] ;
V_10 -> V_218 &= ~ V_219 ;
F_70 ( V_194 ) ;
return 0 ;
}
static int F_77 ( struct V_5 * V_6 , T_1 V_226 ,
unsigned int V_15 )
{
int V_171 ;
T_1 V_227 [ V_228 ] ;
if ( V_6 -> V_87 . V_174
|| V_6 -> V_87 . V_175
|| V_6 -> V_87 . V_176
|| V_6 -> V_87 . V_100 )
return 0 ;
if ( V_14 -> V_159 ( V_226 ) )
return 1 ;
if ( ! V_14 -> V_160 )
return 0 ;
V_15 |= V_173 | V_158 ;
V_171 = V_14 -> V_160 ( V_226 , V_15 , V_227 ) ;
return V_171 > 0 ;
}
static T_1 F_78 ( T_1 V_226 , unsigned long V_15 )
{
T_1 V_227 [ V_228 ] ;
int V_171 ;
V_15 &= ~ ( V_173 | V_158 ) ;
V_171 = V_14 -> V_160 ( V_226 , V_15 , V_227 ) ;
if ( ! V_171 )
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
static int F_85 ( T_1 V_88 , T_1 * V_231 )
{
unsigned long type , V_232 , V_4 ;
int V_226 ;
if ( ! V_14 -> V_233 )
return - V_92 ;
type = V_88 & 0xff ;
V_232 = ( V_88 >> 8 ) & 0xff ;
V_4 = ( V_88 >> 16 ) & 0xff ;
if ( type >= V_234 ||
V_232 >= V_235 ||
V_4 >= V_236 )
return - V_92 ;
V_226 = ( * V_14 -> V_233 ) [ type ] [ V_232 ] [ V_4 ] ;
if ( V_226 == 0 )
return - V_237 ;
if ( V_226 == - 1 )
return - V_92 ;
* V_231 = V_226 ;
return 0 ;
}
static int F_86 ( struct V_5 * V_6 )
{
T_1 V_226 ;
unsigned long V_15 ;
struct V_5 * V_165 [ V_135 ] ;
T_1 V_205 [ V_135 ] ;
unsigned int V_144 [ V_135 ] ;
int V_171 ;
int V_238 ;
struct V_9 * V_10 ;
if ( ! V_14 )
return - V_239 ;
if ( F_69 ( V_6 ) ) {
if ( ! ( V_14 -> V_15 & V_86 ) )
return - V_237 ;
}
switch ( V_6 -> V_87 . type ) {
case V_240 :
V_226 = V_6 -> V_87 . V_88 ;
if ( V_226 >= V_14 -> V_241 || V_14 -> V_242 [ V_226 ] == 0 )
return - V_237 ;
V_226 = V_14 -> V_242 [ V_226 ] ;
break;
case V_243 :
V_238 = F_85 ( V_6 -> V_87 . V_88 , & V_226 ) ;
if ( V_238 )
return V_238 ;
break;
case V_244 :
V_226 = V_6 -> V_87 . V_88 ;
break;
default:
return - V_239 ;
}
V_6 -> V_180 . V_245 = V_226 ;
V_6 -> V_180 . V_131 = 0 ;
if ( ! F_87 ( V_246 ) )
V_6 -> V_87 . V_176 = 0 ;
V_15 = 0 ;
if ( V_6 -> V_93 & V_94 )
V_15 |= V_247 ;
if ( V_14 -> V_15 & V_187 ) {
if ( F_77 ( V_6 , V_226 , V_15 ) ) {
V_15 |= V_173 ;
} else if ( V_14 -> V_159 ( V_226 ) ) {
V_226 = F_78 ( V_226 , V_15 ) ;
if ( ! V_226 )
return - V_92 ;
}
}
V_238 = F_8 ( V_6 ) ;
if ( V_238 )
return V_238 ;
V_171 = 0 ;
if ( V_6 -> V_91 != V_6 ) {
V_171 = F_64 ( V_6 -> V_91 , V_14 -> V_137 - 1 ,
V_165 , V_205 , V_144 ) ;
if ( V_171 < 0 )
return - V_92 ;
}
V_205 [ V_171 ] = V_226 ;
V_165 [ V_171 ] = V_6 ;
V_144 [ V_171 ] = V_15 ;
if ( F_46 ( V_165 , V_144 , V_171 , 1 ) )
return - V_92 ;
V_10 = & F_88 ( V_9 ) ;
V_238 = F_45 ( V_10 , V_205 , V_144 , V_171 + 1 ) ;
if ( F_69 ( V_6 ) ) {
V_10 -> V_209 = V_14 -> V_221 (
V_6 -> V_87 . V_222 ) ;
if( V_10 -> V_209 == - 1 )
return - V_237 ;
}
F_89 ( V_9 ) ;
if ( V_238 )
return - V_92 ;
V_6 -> V_180 . V_88 = V_205 [ V_171 ] ;
V_6 -> V_180 . V_212 = V_144 [ V_171 ] ;
V_6 -> V_180 . V_248 = V_6 -> V_180 . V_100 ;
F_49 ( & V_6 -> V_180 . V_185 , V_6 -> V_180 . V_248 ) ;
if ( F_7 ( V_6 ) )
F_49 ( & V_6 -> V_180 . V_183 , 0 ) ;
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
return V_6 -> V_180 . V_131 ;
}
T_5 F_95 ( struct V_252 * V_253 ,
struct V_254 * V_87 , char * V_255 )
{
struct V_256 * V_257 ;
V_257 = F_96 ( V_87 , struct V_256 , V_87 ) ;
return sprintf ( V_255 , L_11 , V_257 -> V_258 ) ;
}
static void F_97 ( struct V_5 * V_6 , unsigned long V_72 ,
struct V_1 * V_2 )
{
T_1 V_259 = V_6 -> V_180 . V_100 ;
T_4 V_178 , V_179 , V_199 ;
int V_260 = 0 ;
if ( V_6 -> V_180 . V_181 & V_182 ) {
F_39 ( V_6 -> V_180 . V_131 , 0 ) ;
return;
}
V_178 = F_50 ( & V_6 -> V_180 . V_183 ) ;
V_179 = F_47 ( V_178 , V_72 ) ;
F_53 ( V_179 , & V_6 -> V_184 ) ;
V_72 = 0 ;
V_199 = F_50 ( & V_6 -> V_180 . V_185 ) - V_179 ;
if ( V_179 == 0 )
V_199 ++ ;
if ( V_259 ) {
if ( V_199 <= 0 ) {
V_199 += V_259 ;
if ( V_199 <= 0 )
V_199 = V_259 ;
V_260 = F_6 ( V_2 ) ;
V_6 -> V_180 . V_248 = V_6 -> V_180 . V_100 ;
}
if ( V_199 < 0x80000000LL )
V_72 = 0x80000000LL - V_199 ;
}
F_39 ( V_6 -> V_180 . V_131 , V_72 ) ;
F_49 ( & V_6 -> V_180 . V_183 , V_72 ) ;
F_49 ( & V_6 -> V_180 . V_185 , V_199 ) ;
F_57 ( V_6 ) ;
if ( V_260 ) {
struct V_261 V_262 ;
F_98 ( & V_262 , ~ 0ULL , V_6 -> V_180 . V_248 ) ;
if ( V_6 -> V_87 . V_99 & V_263 )
F_2 ( V_2 , & V_262 . V_66 ) ;
if ( V_6 -> V_87 . V_99 & V_264 ) {
struct V_9 * V_10 ;
V_10 = & F_24 ( V_9 ) ;
F_15 ( V_10 ) ;
V_262 . V_265 = & V_10 -> V_84 ;
}
if ( F_99 ( V_6 , & V_262 , V_2 ) )
F_73 ( V_6 , 0 ) ;
}
}
unsigned long F_100 ( struct V_1 * V_2 )
{
T_2 V_15 = F_3 ( V_2 ) ;
if ( V_15 )
return V_15 ;
return F_101 ( V_2 ) ? V_42 :
V_47 ;
}
unsigned long F_102 ( struct V_1 * V_2 )
{
bool V_48 = F_17 ( V_2 ) ;
if ( V_48 && F_6 ( V_2 ) )
return F_18 ( V_51 ) + F_1 ( V_2 ) ;
else if ( V_48 )
return 0 ;
else
return V_2 -> V_266 ;
}
static bool F_103 ( unsigned long V_72 )
{
if ( ( 0x80000000 - V_72 ) <= 256 )
return true ;
return false ;
}
static bool F_104 ( unsigned long V_72 )
{
if ( ( int ) V_72 < 0 )
return true ;
return false ;
}
static void V_249 ( struct V_1 * V_2 )
{
int V_136 , V_153 ;
struct V_9 * V_10 = & F_24 ( V_9 ) ;
struct V_5 * V_6 ;
unsigned long V_72 [ 8 ] ;
int V_267 , V_268 ;
int V_269 ;
if ( V_10 -> V_190 )
F_55 ( V_10 , F_18 ( V_126 ) ,
F_18 ( V_127 ) ) ;
F_4 ( V_2 ) ;
V_269 = F_5 ( V_2 ) ;
if ( V_269 )
F_105 () ;
else
F_106 () ;
for ( V_136 = 0 ; V_136 < V_14 -> V_137 ; ++ V_136 )
V_72 [ V_136 ] = F_36 ( V_136 + 1 ) ;
V_267 = 0 ;
for ( V_136 = 0 ; V_136 < V_14 -> V_137 ; ++ V_136 ) {
if ( ! F_104 ( V_72 [ V_136 ] ) )
continue;
if ( F_54 ( V_136 + 1 ) )
continue;
V_267 = 1 ;
V_268 = 0 ;
for ( V_153 = 0 ; V_153 < V_10 -> V_202 ; ++ V_153 ) {
V_6 = V_10 -> V_6 [ V_153 ] ;
if ( V_6 -> V_180 . V_131 == ( V_136 + 1 ) ) {
V_268 = 1 ;
F_97 ( V_6 , V_72 [ V_136 ] , V_2 ) ;
break;
}
}
if ( ! V_268 )
F_39 ( V_136 + 1 , 0 ) ;
}
if ( ! V_267 && F_107 ( V_270 ) ) {
for ( V_136 = 0 ; V_136 < V_10 -> V_202 ; ++ V_136 ) {
V_6 = V_10 -> V_6 [ V_136 ] ;
if ( ! V_6 -> V_180 . V_131 || F_54 ( V_6 -> V_180 . V_131 ) )
continue;
if ( F_103 ( V_72 [ V_6 -> V_180 . V_131 - 1 ] ) ) {
V_267 = 1 ;
F_97 ( V_6 ,
V_72 [ V_6 -> V_180 . V_131 - 1 ] ,
V_2 ) ;
}
}
}
if ( ! V_267 && ! V_269 && F_108 () )
F_38 ( V_271 L_12 ) ;
F_58 ( V_10 , V_10 -> V_11 [ 0 ] ) ;
if ( V_269 )
F_109 () ;
else
F_110 () ;
}
static void F_111 ( int V_272 )
{
struct V_9 * V_10 = & F_112 ( V_9 , V_272 ) ;
if ( ! V_14 )
return;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_11 [ 0 ] = V_130 ;
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
int F_114 ( struct V_280 * V_194 )
{
if ( V_14 )
return - V_250 ;
V_14 = V_194 ;
F_42 ( L_13 ,
V_194 -> V_138 ) ;
V_280 . V_281 = V_14 -> V_281 ;
#ifdef V_43
if ( F_115 () & V_43 )
V_44 = V_45 ;
#endif
F_116 ( & V_280 , L_14 , V_244 ) ;
F_117 ( F_113 ) ;
return 0 ;
}
