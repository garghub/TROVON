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
else if ( ( V_17 -> V_18 & V_59 ) )
V_51 = 0 ;
else if ( V_57 )
V_51 = 1 ;
else if ( ( V_17 -> V_18 & V_60 ) )
V_51 = 0 ;
else if ( ! ( V_17 -> V_18 & V_52 ) && F_21 ( V_2 ) )
V_51 = 0 ;
else
V_51 = 1 ;
V_2 -> V_4 = V_51 ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
return ! V_2 -> V_61 ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
unsigned long V_15 = V_2 -> V_16 ;
int V_57 = V_15 & V_20 ;
if ( V_57 ) {
if ( V_17 -> V_18 & V_25 )
return V_2 -> V_26 & V_62 ;
if ( V_17 -> V_18 & V_29 )
return V_15 & V_63 ;
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
if ( ! V_17 -> V_64 )
return;
if ( V_6 -> V_13 -> V_65 && V_10 -> V_66 != V_6 -> V_13 ) {
F_23 () ;
V_10 -> V_66 = V_6 -> V_13 ;
}
V_10 -> V_67 ++ ;
F_25 ( V_6 -> V_13 -> V_68 ) ;
}
static void F_13 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_24 ( & V_9 ) ;
if ( ! V_17 -> V_64 )
return;
F_26 ( ! V_10 -> V_67 ) ;
V_10 -> V_67 -- ;
F_27 ( V_6 -> V_13 -> V_68 ) ;
if ( ! V_10 -> V_69 && ! V_10 -> V_67 ) {
V_10 -> V_66 = NULL ;
}
}
static void F_14 ( struct V_12 * V_13 , bool V_14 )
{
if ( ! V_17 -> V_64 )
return;
if ( V_14 )
F_23 () ;
}
static T_3 F_28 ( T_1 V_70 )
{
unsigned int V_71 ;
int V_72 ;
T_3 V_73 ;
if ( F_29 ( V_70 ) )
return F_30 ( ( unsigned int * ) V_70 ) ;
F_31 () ;
V_72 = F_32 ( V_71 , ( unsigned int V_74 * ) V_70 ) ;
if ( V_72 ) {
F_33 () ;
return 0 ;
}
F_33 () ;
V_73 = F_30 ( & V_71 ) ;
if ( ( ! V_73 ) || ( V_71 & V_75 ) )
return V_73 ;
return V_73 - ( unsigned long ) & V_71 + V_70 ;
}
static void F_15 ( struct V_9 * V_10 )
{
T_1 V_76 ;
T_1 V_70 ;
int V_77 , V_78 , V_79 ;
V_77 = 0 ;
V_78 = 0 ;
while ( V_77 < V_17 -> V_64 ) {
V_76 = F_34 ( V_77 ++ ) ;
if ( ! V_76 )
break;
else {
V_70 = V_76 & V_80 ;
V_79 = V_76 & V_81 ;
if ( ! V_70 )
continue;
if ( V_76 & V_82 ) {
V_10 -> V_83 [ V_78 ] . V_84 = V_70 ;
V_10 -> V_83 [ V_78 ] . V_85 = V_79 ;
V_10 -> V_83 [ V_78 ] . V_86 = ~ V_79 ;
V_76 = F_34 ( V_77 ++ ) ;
V_70 = V_76 & V_80 ;
if ( V_76 & V_82 ) {
V_77 -- ;
V_70 = 0 ;
}
V_10 -> V_83 [ V_78 ] . V_87 = V_70 ;
} else {
V_10 -> V_83 [ V_78 ] . V_87 = V_70 ;
V_10 -> V_83 [ V_78 ] . V_84 =
F_28 ( V_70 ) ;
V_10 -> V_83 [ V_78 ] . V_85 = V_79 ;
V_10 -> V_83 [ V_78 ] . V_86 = ~ V_79 ;
}
V_78 ++ ;
}
}
V_10 -> V_88 . V_89 = V_78 ;
return;
}
static bool F_7 ( struct V_5 * V_6 )
{
return ( V_17 -> V_18 & V_90 ) &&
( ( V_6 -> V_91 . V_92 >> V_93 ) & 1 ) ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_5 * V_94 = V_6 -> V_95 ;
if ( F_7 ( V_94 ) != F_7 ( V_6 ) )
return - V_96 ;
if ( F_7 ( V_6 ) ) {
if ( ! ( V_6 -> V_97 & V_98 ) )
return - V_96 ;
if ( ! V_94 -> V_91 . V_99 || ! V_94 -> V_91 . V_100 )
return - V_96 ;
if ( V_6 -> V_91 . V_101 ||
V_6 -> V_91 . V_102 ||
V_6 -> V_91 . V_103 ||
V_6 -> V_91 . V_104 ||
V_6 -> V_91 . V_105 )
return - V_96 ;
}
return 0 ;
}
static void F_9 ( struct V_5 * V_6 )
{
if ( ! F_7 ( V_6 ) || V_106 -> V_107 . V_108 )
return;
V_106 -> V_107 . V_108 = 1 ;
V_106 -> V_107 . V_7 |= V_109 ;
}
static void F_10 ( unsigned long V_7 )
{
if ( ! ( V_7 & V_110 ) )
return;
V_106 -> V_107 . V_53 = F_19 ( V_54 ) ;
V_106 -> V_107 . V_111 = F_19 ( V_58 ) ;
V_106 -> V_107 . V_112 = F_19 ( V_34 ) ;
V_106 -> V_107 . V_7 = V_7 & V_113 ;
V_106 -> V_107 . V_114 = F_19 ( V_115 ) & V_116 ;
}
static unsigned long F_11 ( bool V_8 , struct V_9 * V_10 )
{
unsigned long V_7 = V_10 -> V_11 [ 0 ] ;
if ( ! V_8 )
goto V_117;
V_7 |= V_110 | V_118 | V_119 ;
V_7 |= V_106 -> V_107 . V_7 ;
if ( ! ( V_106 -> V_107 . V_7 & V_109 ) )
V_7 &= ~ V_109 ;
F_35 ( V_54 , V_106 -> V_107 . V_53 ) ;
F_35 ( V_58 , V_106 -> V_107 . V_111 ) ;
F_35 ( V_34 , V_106 -> V_107 . V_112 ) ;
F_35 ( V_115 , V_10 -> V_11 [ 3 ] | V_106 -> V_107 . V_114 ) ;
V_117:
return V_7 ;
}
static void F_16 ( bool V_8 )
{
unsigned V_120 [ 6 ] ;
if ( ! F_36 ( V_121 ) )
return;
if ( ( V_106 -> V_107 . V_7 & ( V_122 | V_123 ) ) != V_122 )
return;
if ( V_8 && ! ( V_106 -> V_107 . V_124 & V_125 ) )
return;
F_37 () ;
V_120 [ 0 ] = F_19 ( V_126 ) ;
V_120 [ 1 ] = F_19 ( V_127 ) ;
V_120 [ 2 ] = F_19 ( V_128 ) ;
V_120 [ 3 ] = F_19 ( V_129 ) ;
V_120 [ 4 ] = F_19 ( V_130 ) ;
V_120 [ 5 ] = F_19 ( V_131 ) ;
F_35 ( V_115 , 0 ) ;
F_35 ( V_131 , 0x7FFFFFFE ) ;
F_35 ( V_132 , V_109 | V_133 | V_122 ) ;
F_35 ( V_132 , V_134 | V_122 ) ;
F_35 ( V_126 , V_120 [ 0 ] ) ;
F_35 ( V_127 , V_120 [ 1 ] ) ;
F_35 ( V_128 , V_120 [ 2 ] ) ;
F_35 ( V_129 , V_120 [ 3 ] ) ;
F_35 ( V_130 , V_120 [ 4 ] ) ;
F_35 ( V_131 , V_120 [ 5 ] ) ;
}
static unsigned long F_38 ( int V_135 )
{
unsigned long V_76 ;
switch ( V_135 ) {
case 1 :
V_76 = F_19 ( V_126 ) ;
break;
case 2 :
V_76 = F_19 ( V_127 ) ;
break;
case 3 :
V_76 = F_19 ( V_128 ) ;
break;
case 4 :
V_76 = F_19 ( V_129 ) ;
break;
case 5 :
V_76 = F_19 ( V_130 ) ;
break;
case 6 :
V_76 = F_19 ( V_131 ) ;
break;
#ifdef F_39
case 7 :
V_76 = F_19 ( V_136 ) ;
break;
case 8 :
V_76 = F_19 ( V_137 ) ;
break;
#endif
default:
F_40 ( V_138 L_1 , V_135 ) ;
V_76 = 0 ;
}
return V_76 ;
}
static void F_41 ( int V_135 , unsigned long V_76 )
{
switch ( V_135 ) {
case 1 :
F_35 ( V_126 , V_76 ) ;
break;
case 2 :
F_35 ( V_127 , V_76 ) ;
break;
case 3 :
F_35 ( V_128 , V_76 ) ;
break;
case 4 :
F_35 ( V_129 , V_76 ) ;
break;
case 5 :
F_35 ( V_130 , V_76 ) ;
break;
case 6 :
F_35 ( V_131 , V_76 ) ;
break;
#ifdef F_39
case 7 :
F_35 ( V_136 , V_76 ) ;
break;
case 8 :
F_35 ( V_137 , V_76 ) ;
break;
#endif
default:
F_40 ( V_138 L_2 , V_135 ) ;
}
}
void F_42 ( void )
{
unsigned long V_112 , V_111 , V_18 ;
T_2 V_120 [ V_139 ] ;
int V_140 ;
if ( ! V_17 -> V_141 )
return;
F_43 ( V_18 ) ;
F_44 ( L_3 ,
F_45 () , V_17 -> V_142 , V_17 -> V_141 ) ;
for ( V_140 = 0 ; V_140 < V_17 -> V_141 ; V_140 ++ )
V_120 [ V_140 ] = F_38 ( V_140 + 1 ) ;
for (; V_140 < V_139 ; V_140 ++ )
V_120 [ V_140 ] = 0xdeadbeef ;
F_44 ( L_4 ,
V_120 [ 0 ] , V_120 [ 1 ] , V_120 [ 2 ] , V_120 [ 3 ] ) ;
if ( V_17 -> V_141 > 4 )
F_44 ( L_5 ,
V_120 [ 4 ] , V_120 [ 5 ] , V_120 [ 6 ] , V_120 [ 7 ] ) ;
F_44 ( L_6 ,
F_19 ( V_132 ) , F_19 ( V_143 ) , F_19 ( V_56 ) ) ;
V_112 = V_111 = 0 ;
#ifdef F_39
V_112 = F_19 ( V_34 ) ;
if ( V_17 -> V_18 & V_25 )
V_111 = F_19 ( V_58 ) ;
if ( V_17 -> V_18 & V_90 ) {
F_44 ( L_7 ,
F_19 ( V_115 ) , F_19 ( V_144 ) ) ;
F_44 ( L_8 ,
F_19 ( V_145 ) , F_19 ( V_146 ) ) ;
}
#endif
F_44 ( L_9 ,
F_19 ( V_54 ) , V_112 , V_111 ) ;
F_46 ( V_18 ) ;
}
static int F_47 ( struct V_9 * V_10 ,
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
static int F_48 ( struct V_5 * * V_169 , unsigned int V_148 [] ,
int V_170 , int V_171 )
{
int V_172 = 0 , V_173 = 0 , V_174 = 0 ;
int V_140 , V_175 , V_176 ;
struct V_5 * V_6 ;
if ( V_17 -> V_18 & V_90 )
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
V_172 = V_6 -> V_91 . V_178 ;
V_173 = V_6 -> V_91 . V_179 ;
V_174 = V_6 -> V_91 . V_180 ;
V_176 = 0 ;
} else if ( V_6 -> V_91 . V_178 != V_172 ||
V_6 -> V_91 . V_179 != V_173 ||
V_6 -> V_91 . V_180 != V_174 ) {
return - V_181 ;
}
}
if ( V_172 || V_173 || V_174 )
for ( V_140 = 0 ; V_140 < V_175 ; ++ V_140 )
if ( V_148 [ V_140 ] & V_177 )
V_148 [ V_140 ] |= V_162 ;
return 0 ;
}
static T_1 F_49 ( T_1 V_182 , T_1 V_76 )
{
T_1 V_183 = ( V_76 - V_182 ) & 0xfffffffful ;
if ( V_182 > V_76 && ( V_182 - V_76 ) < 256 )
V_183 = 0 ;
return V_183 ;
}
static void F_50 ( struct V_5 * V_6 )
{
T_4 V_76 , V_183 , V_182 ;
if ( V_6 -> V_184 . V_185 & V_186 )
return;
if ( ! V_6 -> V_184 . V_135 )
return;
if ( F_7 ( V_6 ) ) {
V_76 = F_38 ( V_6 -> V_184 . V_135 ) ;
F_51 ( & V_6 -> V_184 . V_187 , V_76 ) ;
return;
}
do {
V_182 = F_52 ( & V_6 -> V_184 . V_187 ) ;
F_53 () ;
V_76 = F_38 ( V_6 -> V_184 . V_135 ) ;
V_183 = F_49 ( V_182 , V_76 ) ;
if ( ! V_183 )
return;
} while ( F_54 ( & V_6 -> V_184 . V_187 , V_182 , V_76 ) != V_182 );
F_55 ( V_183 , & V_6 -> V_188 ) ;
do {
V_182 = F_52 ( & V_6 -> V_184 . V_189 ) ;
V_76 = V_182 - V_183 ;
if ( V_76 < 1 )
V_76 = 1 ;
} while ( F_54 ( & V_6 -> V_184 . V_189 , V_182 , V_76 ) != V_182 );
}
static int F_56 ( int V_190 )
{
return ( V_17 -> V_18 & V_191 )
&& ( V_190 == 5 || V_190 == 6 ) ;
}
static void F_57 ( struct V_9 * V_10 ,
unsigned long V_192 , unsigned long V_193 )
{
struct V_5 * V_6 ;
T_1 V_76 , V_182 , V_183 ;
int V_140 ;
for ( V_140 = 0 ; V_140 < V_10 -> V_194 ; ++ V_140 ) {
V_6 = V_10 -> V_195 [ V_140 ] ;
if ( ! V_6 -> V_184 . V_135 )
continue;
V_76 = ( V_6 -> V_184 . V_135 == 5 ) ? V_192 : V_193 ;
V_182 = F_52 ( & V_6 -> V_184 . V_187 ) ;
V_6 -> V_184 . V_135 = 0 ;
V_183 = F_49 ( V_182 , V_76 ) ;
if ( V_183 )
F_55 ( V_183 , & V_6 -> V_188 ) ;
}
}
static void F_58 ( struct V_9 * V_10 ,
unsigned long V_192 , unsigned long V_193 )
{
struct V_5 * V_6 ;
T_1 V_76 , V_182 ;
int V_140 ;
for ( V_140 = 0 ; V_140 < V_10 -> V_194 ; ++ V_140 ) {
V_6 = V_10 -> V_195 [ V_140 ] ;
V_6 -> V_184 . V_135 = V_10 -> V_196 [ V_140 ] ;
V_76 = ( V_6 -> V_184 . V_135 == 5 ) ? V_192 : V_193 ;
V_182 = F_52 ( & V_6 -> V_184 . V_187 ) ;
if ( F_49 ( V_182 , V_76 ) )
F_51 ( & V_6 -> V_184 . V_187 , V_76 ) ;
F_59 ( V_6 ) ;
}
}
static void F_60 ( struct V_9 * V_10 , unsigned long V_7 )
{
unsigned long V_192 , V_193 ;
if ( ! V_10 -> V_194 ) {
F_35 ( V_132 , V_7 ) ;
return;
}
asm volatile("mtspr %3,%2; mfspr %0,%4; mfspr %1,%5"
: "=&r" (pmc5), "=&r" (pmc6)
: "r" (mmcr0 & ~(MMCR0_PMC1CE | MMCR0_PMCjCE)),
"i" (SPRN_MMCR0),
"i" (SPRN_PMC5), "i" (SPRN_PMC6));
if ( V_7 & V_134 )
F_57 ( V_10 , V_192 , V_193 ) ;
else
F_58 ( V_10 , V_192 , V_193 ) ;
if ( V_7 & ( V_197 | V_133 ) )
F_35 ( V_132 , V_7 ) ;
}
static void F_61 ( struct V_68 * V_68 )
{
struct V_9 * V_10 ;
unsigned long V_18 , V_7 , V_76 ;
if ( ! V_17 )
return;
F_43 ( V_18 ) ;
V_10 = F_24 ( & V_9 ) ;
if ( ! V_10 -> V_69 ) {
if ( ! V_10 -> V_198 ) {
F_62 () ;
V_10 -> V_198 = 1 ;
}
V_76 = V_7 = F_19 ( V_132 ) ;
V_76 |= V_134 ;
V_76 &= ~ ( V_110 | V_118 | V_199 | V_122 |
V_200 ) ;
F_60 ( V_10 , V_76 ) ;
F_63 () ;
if ( V_10 -> V_11 [ 2 ] & V_20 ) {
F_35 ( V_56 ,
V_10 -> V_11 [ 2 ] & ~ V_20 ) ;
F_63 () ;
}
V_10 -> V_69 = 1 ;
V_10 -> V_201 = 0 ;
F_10 ( V_7 ) ;
}
F_46 ( V_18 ) ;
}
static void F_64 ( struct V_68 * V_68 )
{
struct V_5 * V_6 ;
struct V_9 * V_10 ;
unsigned long V_18 ;
long V_140 ;
unsigned long V_76 , V_7 ;
T_4 V_202 ;
unsigned int V_203 [ V_139 ] ;
int V_204 ;
int V_135 ;
bool V_8 ;
if ( ! V_17 )
return;
F_43 ( V_18 ) ;
V_10 = F_24 ( & V_9 ) ;
if ( ! V_10 -> V_69 )
goto V_117;
if ( V_10 -> V_205 == 0 ) {
F_65 ( 0 ) ;
goto V_117;
}
V_10 -> V_69 = 0 ;
V_8 = F_7 ( V_10 -> V_6 [ 0 ] ) ;
if ( ! V_10 -> V_201 ) {
F_35 ( V_56 , V_10 -> V_11 [ 2 ] & ~ V_20 ) ;
F_35 ( V_143 , V_10 -> V_11 [ 1 ] ) ;
goto V_206;
}
memset ( V_10 -> V_11 , 0 , sizeof( V_10 -> V_11 ) ) ;
if ( V_17 -> V_207 ( V_10 -> V_208 , V_10 -> V_205 , V_203 ,
V_10 -> V_11 , V_10 -> V_6 ) ) {
F_40 ( V_138 L_10 ) ;
goto V_117;
}
if ( ! ( V_17 -> V_18 & V_90 ) ) {
V_6 = V_10 -> V_6 [ 0 ] ;
if ( V_6 -> V_91 . V_178 )
V_10 -> V_11 [ 0 ] |= V_209 ;
if ( V_6 -> V_91 . V_179 )
V_10 -> V_11 [ 0 ] |= V_47 ;
if ( V_6 -> V_91 . V_180 )
V_10 -> V_11 [ 0 ] |= V_48 ;
}
F_65 ( 1 ) ;
F_35 ( V_56 , V_10 -> V_11 [ 2 ] & ~ V_20 ) ;
F_35 ( V_143 , V_10 -> V_11 [ 1 ] ) ;
F_35 ( V_132 , ( V_10 -> V_11 [ 0 ] & ~ ( V_197 | V_133 ) )
| V_134 ) ;
if ( V_17 -> V_18 & V_90 )
F_35 ( V_115 , V_10 -> V_11 [ 3 ] ) ;
for ( V_140 = 0 ; V_140 < V_10 -> V_205 ; ++ V_140 ) {
V_6 = V_10 -> V_6 [ V_140 ] ;
if ( V_6 -> V_184 . V_135 && V_6 -> V_184 . V_135 != V_203 [ V_140 ] + 1 ) {
F_50 ( V_6 ) ;
F_41 ( V_6 -> V_184 . V_135 , 0 ) ;
V_6 -> V_184 . V_135 = 0 ;
}
}
V_10 -> V_194 = V_204 = 0 ;
for ( V_140 = 0 ; V_140 < V_10 -> V_205 ; ++ V_140 ) {
V_6 = V_10 -> V_6 [ V_140 ] ;
if ( V_6 -> V_184 . V_135 )
continue;
V_135 = V_203 [ V_140 ] + 1 ;
if ( F_56 ( V_135 ) ) {
V_10 -> V_195 [ V_204 ] = V_6 ;
V_10 -> V_196 [ V_204 ] = V_135 ;
++ V_204 ;
continue;
}
if ( V_8 )
V_76 = F_52 ( & V_6 -> V_184 . V_187 ) ;
else {
V_76 = 0 ;
if ( V_6 -> V_184 . V_104 ) {
V_202 = F_52 ( & V_6 -> V_184 . V_189 ) ;
if ( V_202 < 0x80000000L )
V_76 = 0x80000000L - V_202 ;
}
F_51 ( & V_6 -> V_184 . V_187 , V_76 ) ;
}
V_6 -> V_184 . V_135 = V_135 ;
if ( V_6 -> V_184 . V_185 & V_186 )
V_76 = 0 ;
F_41 ( V_135 , V_76 ) ;
F_59 ( V_6 ) ;
}
V_10 -> V_194 = V_204 ;
V_10 -> V_11 [ 0 ] |= V_109 | V_210 ;
V_206:
F_16 ( V_8 ) ;
V_7 = F_11 ( V_8 , V_10 ) ;
F_63 () ;
if ( V_10 -> V_67 )
V_17 -> V_211 ( V_10 -> V_212 ) ;
F_60 ( V_10 , V_7 ) ;
if ( V_10 -> V_11 [ 2 ] & V_20 ) {
F_63 () ;
F_35 ( V_56 , V_10 -> V_11 [ 2 ] ) ;
}
V_117:
F_46 ( V_18 ) ;
}
static int F_66 ( struct V_5 * V_213 , int V_214 ,
struct V_5 * V_169 [] , T_1 * V_208 ,
unsigned int * V_18 )
{
int V_175 = 0 ;
struct V_5 * V_6 ;
if ( ! F_67 ( V_213 ) ) {
if ( V_175 >= V_214 )
return - 1 ;
V_169 [ V_175 ] = V_213 ;
V_18 [ V_175 ] = V_213 -> V_184 . V_215 ;
V_208 [ V_175 ++ ] = V_213 -> V_184 . V_92 ;
}
F_68 (event, &group->sibling_list, group_entry) {
if ( ! F_67 ( V_6 ) &&
V_6 -> V_185 != V_216 ) {
if ( V_175 >= V_214 )
return - 1 ;
V_169 [ V_175 ] = V_6 ;
V_18 [ V_175 ] = V_6 -> V_184 . V_215 ;
V_208 [ V_175 ++ ] = V_6 -> V_184 . V_92 ;
}
}
return V_175 ;
}
static int F_69 ( struct V_5 * V_6 , int V_217 )
{
struct V_9 * V_10 ;
unsigned long V_18 ;
int V_218 ;
int V_72 = - V_181 ;
F_43 ( V_18 ) ;
F_70 ( V_6 -> V_68 ) ;
V_10 = F_24 ( & V_9 ) ;
V_218 = V_10 -> V_205 ;
if ( V_218 >= V_17 -> V_141 )
goto V_117;
V_10 -> V_6 [ V_218 ] = V_6 ;
V_10 -> V_208 [ V_218 ] = V_6 -> V_184 . V_92 ;
V_10 -> V_18 [ V_218 ] = V_6 -> V_184 . V_215 ;
if ( ! ( V_217 & V_219 ) )
V_6 -> V_184 . V_185 = V_186 | V_220 ;
else
V_6 -> V_184 . V_185 = 0 ;
if ( V_10 -> V_221 & V_222 )
goto V_223;
if ( F_48 ( V_10 -> V_6 , V_10 -> V_18 , V_218 , 1 ) )
goto V_117;
if ( F_47 ( V_10 , V_10 -> V_208 , V_10 -> V_18 , V_218 + 1 ) )
goto V_117;
V_6 -> V_184 . V_92 = V_10 -> V_208 [ V_218 ] ;
V_223:
F_9 ( V_6 ) ;
++ V_10 -> V_205 ;
++ V_10 -> V_201 ;
V_72 = 0 ;
V_117:
if ( F_71 ( V_6 ) ) {
F_12 ( V_6 ) ;
V_10 -> V_212 = V_17 -> V_224 (
V_6 -> V_91 . V_225 ) ;
}
F_72 ( V_6 -> V_68 ) ;
F_46 ( V_18 ) ;
return V_72 ;
}
static void F_73 ( struct V_5 * V_6 , int V_217 )
{
struct V_9 * V_10 ;
long V_140 ;
unsigned long V_18 ;
F_43 ( V_18 ) ;
F_70 ( V_6 -> V_68 ) ;
F_50 ( V_6 ) ;
V_10 = F_24 ( & V_9 ) ;
for ( V_140 = 0 ; V_140 < V_10 -> V_205 ; ++ V_140 ) {
if ( V_6 == V_10 -> V_6 [ V_140 ] ) {
while ( ++ V_140 < V_10 -> V_205 ) {
V_10 -> V_6 [ V_140 - 1 ] = V_10 -> V_6 [ V_140 ] ;
V_10 -> V_208 [ V_140 - 1 ] = V_10 -> V_208 [ V_140 ] ;
V_10 -> V_18 [ V_140 - 1 ] = V_10 -> V_18 [ V_140 ] ;
}
-- V_10 -> V_205 ;
V_17 -> V_226 ( V_6 -> V_184 . V_135 - 1 , V_10 -> V_11 ) ;
if ( V_6 -> V_184 . V_135 ) {
F_41 ( V_6 -> V_184 . V_135 , 0 ) ;
V_6 -> V_184 . V_135 = 0 ;
}
F_59 ( V_6 ) ;
break;
}
}
for ( V_140 = 0 ; V_140 < V_10 -> V_194 ; ++ V_140 )
if ( V_6 == V_10 -> V_195 [ V_140 ] )
break;
if ( V_140 < V_10 -> V_194 ) {
while ( ++ V_140 < V_10 -> V_194 ) {
V_10 -> V_195 [ V_140 - 1 ] = V_10 -> V_195 [ V_140 ] ;
V_10 -> V_196 [ V_140 - 1 ] = V_10 -> V_196 [ V_140 ] ;
}
-- V_10 -> V_194 ;
}
if ( V_10 -> V_205 == 0 ) {
V_10 -> V_11 [ 0 ] &= ~ ( V_109 | V_210 ) ;
}
if ( F_71 ( V_6 ) )
F_13 ( V_6 ) ;
F_72 ( V_6 -> V_68 ) ;
F_46 ( V_18 ) ;
}
static void F_74 ( struct V_5 * V_6 , int V_217 )
{
unsigned long V_18 ;
T_4 V_202 ;
unsigned long V_76 ;
if ( ! V_6 -> V_184 . V_135 || ! V_6 -> V_184 . V_104 )
return;
if ( ! ( V_6 -> V_184 . V_185 & V_186 ) )
return;
if ( V_217 & V_227 )
F_26 ( ! ( V_6 -> V_184 . V_185 & V_220 ) ) ;
F_43 ( V_18 ) ;
F_70 ( V_6 -> V_68 ) ;
V_6 -> V_184 . V_185 = 0 ;
V_202 = F_52 ( & V_6 -> V_184 . V_189 ) ;
V_76 = 0 ;
if ( V_202 < 0x80000000L )
V_76 = 0x80000000L - V_202 ;
F_41 ( V_6 -> V_184 . V_135 , V_76 ) ;
F_59 ( V_6 ) ;
F_72 ( V_6 -> V_68 ) ;
F_46 ( V_18 ) ;
}
static void F_75 ( struct V_5 * V_6 , int V_217 )
{
unsigned long V_18 ;
if ( ! V_6 -> V_184 . V_135 || ! V_6 -> V_184 . V_104 )
return;
if ( V_6 -> V_184 . V_185 & V_186 )
return;
F_43 ( V_18 ) ;
F_70 ( V_6 -> V_68 ) ;
F_50 ( V_6 ) ;
V_6 -> V_184 . V_185 |= V_186 | V_220 ;
F_41 ( V_6 -> V_184 . V_135 , 0 ) ;
F_59 ( V_6 ) ;
F_72 ( V_6 -> V_68 ) ;
F_46 ( V_18 ) ;
}
static void F_76 ( struct V_68 * V_68 , unsigned int V_221 )
{
struct V_9 * V_10 = F_24 ( & V_9 ) ;
F_26 ( V_10 -> V_221 ) ;
V_10 -> V_221 = V_221 ;
if ( V_221 & ~ V_222 )
return;
F_70 ( V_68 ) ;
V_10 -> V_228 = V_10 -> V_205 ;
}
static void F_77 ( struct V_68 * V_68 )
{
struct V_9 * V_10 = F_24 ( & V_9 ) ;
unsigned int V_221 ;
F_26 ( ! V_10 -> V_221 ) ;
V_221 = V_10 -> V_221 ;
V_10 -> V_221 = 0 ;
if ( V_221 & ~ V_222 )
return;
F_72 ( V_68 ) ;
}
static int F_78 ( struct V_68 * V_68 )
{
struct V_9 * V_10 ;
long V_140 , V_175 ;
if ( ! V_17 )
return - V_181 ;
V_10 = F_24 ( & V_9 ) ;
F_26 ( ! V_10 -> V_221 ) ;
if ( V_10 -> V_221 & ~ V_222 ) {
V_10 -> V_221 = 0 ;
return 0 ;
}
V_175 = V_10 -> V_205 ;
if ( F_48 ( V_10 -> V_6 , V_10 -> V_18 , 0 , V_175 ) )
return - V_181 ;
V_140 = F_47 ( V_10 , V_10 -> V_208 , V_10 -> V_18 , V_175 ) ;
if ( V_140 < 0 )
return - V_181 ;
for ( V_140 = V_10 -> V_228 ; V_140 < V_175 ; ++ V_140 )
V_10 -> V_6 [ V_140 ] -> V_184 . V_92 = V_10 -> V_208 [ V_140 ] ;
V_10 -> V_221 = 0 ;
F_72 ( V_68 ) ;
return 0 ;
}
static int F_79 ( struct V_5 * V_6 , T_1 V_229 ,
unsigned int V_18 )
{
int V_175 ;
T_1 V_230 [ V_231 ] ;
if ( V_6 -> V_91 . V_178
|| V_6 -> V_91 . V_179
|| V_6 -> V_91 . V_180
|| V_6 -> V_91 . V_104 )
return 0 ;
if ( V_17 -> V_163 ( V_229 ) )
return 1 ;
if ( ! V_17 -> V_164 )
return 0 ;
V_18 |= V_177 | V_162 ;
V_175 = V_17 -> V_164 ( V_229 , V_18 , V_230 ) ;
return V_175 > 0 ;
}
static T_1 F_80 ( T_1 V_229 , unsigned long V_18 )
{
T_1 V_230 [ V_231 ] ;
int V_175 ;
V_18 &= ~ ( V_177 | V_162 ) ;
V_175 = V_17 -> V_164 ( V_229 , V_18 , V_230 ) ;
if ( ! V_175 )
return 0 ;
return V_230 [ 0 ] ;
}
static void F_81 ( struct V_5 * V_6 )
{
if ( ! F_82 ( & V_232 , - 1 , 1 ) ) {
F_83 ( & V_233 ) ;
if ( F_84 ( & V_232 ) == 0 )
F_85 () ;
F_86 ( & V_233 ) ;
}
}
static int F_87 ( T_1 V_92 , T_1 * V_234 )
{
unsigned long type , V_235 , V_4 ;
int V_229 ;
if ( ! V_17 -> V_236 )
return - V_96 ;
type = V_92 & 0xff ;
V_235 = ( V_92 >> 8 ) & 0xff ;
V_4 = ( V_92 >> 16 ) & 0xff ;
if ( type >= V_237 ||
V_235 >= V_238 ||
V_4 >= V_239 )
return - V_96 ;
V_229 = ( * V_17 -> V_236 ) [ type ] [ V_235 ] [ V_4 ] ;
if ( V_229 == 0 )
return - V_240 ;
if ( V_229 == - 1 )
return - V_96 ;
* V_234 = V_229 ;
return 0 ;
}
static int F_88 ( struct V_5 * V_6 )
{
T_1 V_229 ;
unsigned long V_18 ;
struct V_5 * V_169 [ V_139 ] ;
T_1 V_208 [ V_139 ] ;
unsigned int V_148 [ V_139 ] ;
int V_175 ;
int V_241 ;
struct V_9 * V_10 ;
if ( ! V_17 )
return - V_242 ;
if ( F_71 ( V_6 ) ) {
if ( ! ( V_17 -> V_18 & V_90 ) )
return - V_240 ;
}
switch ( V_6 -> V_91 . type ) {
case V_243 :
V_229 = V_6 -> V_91 . V_92 ;
if ( V_229 >= V_17 -> V_244 || V_17 -> V_245 [ V_229 ] == 0 )
return - V_240 ;
V_229 = V_17 -> V_245 [ V_229 ] ;
break;
case V_246 :
V_241 = F_87 ( V_6 -> V_91 . V_92 , & V_229 ) ;
if ( V_241 )
return V_241 ;
break;
case V_247 :
V_229 = V_6 -> V_91 . V_92 ;
break;
default:
return - V_242 ;
}
V_6 -> V_184 . V_248 = V_229 ;
V_6 -> V_184 . V_135 = 0 ;
if ( ! F_89 ( V_249 ) )
V_6 -> V_91 . V_180 = 0 ;
V_18 = 0 ;
if ( V_6 -> V_97 & V_98 )
V_18 |= V_250 ;
if ( V_17 -> V_18 & V_191 ) {
if ( F_79 ( V_6 , V_229 , V_18 ) ) {
V_18 |= V_177 ;
} else if ( V_17 -> V_163 ( V_229 ) ) {
V_229 = F_80 ( V_229 , V_18 ) ;
if ( ! V_229 )
return - V_96 ;
}
}
V_241 = F_8 ( V_6 ) ;
if ( V_241 )
return V_241 ;
V_175 = 0 ;
if ( V_6 -> V_95 != V_6 ) {
V_175 = F_66 ( V_6 -> V_95 , V_17 -> V_141 - 1 ,
V_169 , V_208 , V_148 ) ;
if ( V_175 < 0 )
return - V_96 ;
}
V_208 [ V_175 ] = V_229 ;
V_169 [ V_175 ] = V_6 ;
V_148 [ V_175 ] = V_18 ;
if ( F_48 ( V_169 , V_148 , V_175 , 1 ) )
return - V_96 ;
V_10 = & F_90 ( V_9 ) ;
V_241 = F_47 ( V_10 , V_208 , V_148 , V_175 + 1 ) ;
if ( F_71 ( V_6 ) ) {
V_10 -> V_212 = V_17 -> V_224 (
V_6 -> V_91 . V_225 ) ;
if ( V_10 -> V_212 == - 1 ) {
F_91 ( V_9 ) ;
return - V_240 ;
}
}
F_91 ( V_9 ) ;
if ( V_241 )
return - V_96 ;
V_6 -> V_184 . V_92 = V_208 [ V_175 ] ;
V_6 -> V_184 . V_215 = V_148 [ V_175 ] ;
V_6 -> V_184 . V_251 = V_6 -> V_184 . V_104 ;
F_51 ( & V_6 -> V_184 . V_189 , V_6 -> V_184 . V_251 ) ;
if ( F_7 ( V_6 ) )
F_51 ( & V_6 -> V_184 . V_187 , 0 ) ;
V_241 = 0 ;
if ( ! F_92 ( & V_232 ) ) {
F_83 ( & V_233 ) ;
if ( F_93 ( & V_232 ) == 0 &&
F_94 ( V_252 ) )
V_241 = - V_253 ;
else
F_95 ( & V_232 ) ;
F_86 ( & V_233 ) ;
}
V_6 -> V_254 = F_81 ;
return V_241 ;
}
static int F_96 ( struct V_5 * V_6 )
{
return V_6 -> V_184 . V_135 ;
}
T_5 F_97 ( struct V_255 * V_256 ,
struct V_257 * V_91 , char * V_258 )
{
struct V_259 * V_260 ;
V_260 = F_98 ( V_91 , struct V_259 , V_91 ) ;
return sprintf ( V_258 , L_11 , V_260 -> V_261 ) ;
}
static void F_99 ( struct V_5 * V_6 , unsigned long V_76 ,
struct V_1 * V_2 )
{
T_1 V_262 = V_6 -> V_184 . V_104 ;
T_4 V_182 , V_183 , V_202 ;
int V_263 = 0 ;
if ( V_6 -> V_184 . V_185 & V_186 ) {
F_41 ( V_6 -> V_184 . V_135 , 0 ) ;
return;
}
V_182 = F_52 ( & V_6 -> V_184 . V_187 ) ;
V_183 = F_49 ( V_182 , V_76 ) ;
F_55 ( V_183 , & V_6 -> V_188 ) ;
V_76 = 0 ;
V_202 = F_52 ( & V_6 -> V_184 . V_189 ) - V_183 ;
if ( V_183 == 0 )
V_202 ++ ;
if ( V_262 ) {
if ( V_202 <= 0 ) {
V_202 += V_262 ;
if ( V_202 <= 0 )
V_202 = V_262 ;
V_263 = F_6 ( V_2 ) ;
V_6 -> V_184 . V_251 = V_6 -> V_184 . V_104 ;
}
if ( V_202 < 0x80000000LL )
V_76 = 0x80000000LL - V_202 ;
}
F_41 ( V_6 -> V_184 . V_135 , V_76 ) ;
F_51 ( & V_6 -> V_184 . V_187 , V_76 ) ;
F_51 ( & V_6 -> V_184 . V_189 , V_202 ) ;
F_59 ( V_6 ) ;
if ( V_263 ) {
struct V_264 V_265 ;
F_100 ( & V_265 , ~ 0ULL , V_6 -> V_184 . V_251 ) ;
if ( V_6 -> V_91 . V_103 & V_266 )
F_2 ( V_2 , & V_265 . V_70 ) ;
if ( V_6 -> V_91 . V_103 & V_267 ) {
struct V_9 * V_10 ;
V_10 = F_24 ( & V_9 ) ;
F_15 ( V_10 ) ;
V_265 . V_268 = & V_10 -> V_88 ;
}
if ( F_101 ( V_6 , & V_265 , V_2 ) )
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
return V_2 -> V_269 ;
}
static bool F_105 ( unsigned long V_76 )
{
if ( ( 0x80000000 - V_76 ) <= 256 )
return true ;
return false ;
}
static bool F_106 ( unsigned long V_76 )
{
if ( ( int ) V_76 < 0 )
return true ;
return false ;
}
static void V_252 ( struct V_1 * V_2 )
{
int V_140 , V_157 ;
struct V_9 * V_10 = F_24 ( & V_9 ) ;
struct V_5 * V_6 ;
unsigned long V_76 [ 8 ] ;
int V_270 , V_271 ;
int V_272 ;
if ( V_10 -> V_194 )
F_57 ( V_10 , F_19 ( V_130 ) ,
F_19 ( V_131 ) ) ;
F_4 ( V_2 ) ;
V_272 = F_5 ( V_2 ) ;
if ( V_272 )
F_107 () ;
else
F_108 () ;
for ( V_140 = 0 ; V_140 < V_17 -> V_141 ; ++ V_140 )
V_76 [ V_140 ] = F_38 ( V_140 + 1 ) ;
V_270 = 0 ;
for ( V_140 = 0 ; V_140 < V_17 -> V_141 ; ++ V_140 ) {
if ( ! F_106 ( V_76 [ V_140 ] ) )
continue;
if ( F_56 ( V_140 + 1 ) )
continue;
V_270 = 1 ;
V_271 = 0 ;
for ( V_157 = 0 ; V_157 < V_10 -> V_205 ; ++ V_157 ) {
V_6 = V_10 -> V_6 [ V_157 ] ;
if ( V_6 -> V_184 . V_135 == ( V_140 + 1 ) ) {
V_271 = 1 ;
F_99 ( V_6 , V_76 [ V_140 ] , V_2 ) ;
break;
}
}
if ( ! V_271 )
F_41 ( V_140 + 1 , 0 ) ;
}
if ( ! V_270 && F_109 ( V_273 ) ) {
for ( V_140 = 0 ; V_140 < V_10 -> V_205 ; ++ V_140 ) {
V_6 = V_10 -> V_6 [ V_140 ] ;
if ( ! V_6 -> V_184 . V_135 || F_56 ( V_6 -> V_184 . V_135 ) )
continue;
if ( F_105 ( V_76 [ V_6 -> V_184 . V_135 - 1 ] ) ) {
V_270 = 1 ;
F_99 ( V_6 ,
V_76 [ V_6 -> V_184 . V_135 - 1 ] ,
V_2 ) ;
}
}
}
if ( ! V_270 && ! V_272 && F_110 () )
F_40 ( V_274 L_12 ) ;
F_60 ( V_10 , V_10 -> V_11 [ 0 ] ) ;
if ( V_272 )
F_111 () ;
else
F_112 () ;
}
static int F_113 ( unsigned int V_275 )
{
struct V_9 * V_10 = & F_114 ( V_9 , V_275 ) ;
if ( V_17 ) {
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_11 [ 0 ] = V_134 ;
}
return 0 ;
}
int F_115 ( struct V_276 * V_68 )
{
if ( V_17 )
return - V_253 ;
V_17 = V_68 ;
F_44 ( L_13 ,
V_68 -> V_142 ) ;
V_276 . V_277 = V_17 -> V_277 ;
#ifdef V_46
if ( F_116 () & V_46 )
V_47 = V_48 ;
#endif
F_117 ( & V_276 , L_14 , V_247 ) ;
F_118 ( V_278 , L_15 ,
F_113 , NULL ) ;
return 0 ;
}
