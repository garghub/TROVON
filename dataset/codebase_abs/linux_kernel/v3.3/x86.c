static inline void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
}
static void F_3 ( struct V_8 * V_9 )
{
unsigned V_10 ;
struct V_11 * V_12
= F_4 ( V_9 , struct V_11 , V_9 ) ;
struct V_13 * V_14 ;
for ( V_10 = 0 ; V_10 < V_15 . V_16 ; ++ V_10 ) {
V_14 = & V_12 -> V_14 [ V_10 ] ;
if ( V_14 -> V_17 != V_14 -> V_18 ) {
F_5 ( V_15 . V_19 [ V_10 ] , V_14 -> V_17 ) ;
V_14 -> V_18 = V_14 -> V_17 ;
}
}
V_12 -> V_20 = false ;
F_6 ( V_9 ) ;
}
static void F_7 ( unsigned V_10 , T_1 V_21 )
{
struct V_11 * V_22 ;
T_2 V_23 ;
V_22 = & F_8 ( V_24 ) ;
if ( V_10 >= V_15 . V_16 ) {
F_9 ( V_25 L_1 ) ;
return;
}
F_10 ( V_21 , & V_23 ) ;
V_22 -> V_14 [ V_10 ] . V_17 = V_23 ;
V_22 -> V_14 [ V_10 ] . V_18 = V_23 ;
}
void F_11 ( unsigned V_10 , T_1 V_21 )
{
if ( V_10 >= V_15 . V_16 )
V_15 . V_16 = V_10 + 1 ;
V_15 . V_19 [ V_10 ] = V_21 ;
F_12 () ;
}
static void F_13 ( void )
{
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_15 . V_16 ; ++ V_3 )
F_7 ( V_3 , V_15 . V_19 [ V_3 ] ) ;
}
void F_14 ( unsigned V_10 , T_2 V_23 , T_2 V_26 )
{
struct V_11 * V_22 = & F_8 ( V_24 ) ;
if ( ( ( V_23 ^ V_22 -> V_14 [ V_10 ] . V_18 ) & V_26 ) == 0 )
return;
V_22 -> V_14 [ V_10 ] . V_18 = V_23 ;
F_5 ( V_15 . V_19 [ V_10 ] , V_23 ) ;
if ( ! V_22 -> V_20 ) {
V_22 -> V_9 . V_27 = F_3 ;
F_15 ( & V_22 -> V_9 ) ;
V_22 -> V_20 = true ;
}
}
static void F_16 ( void * V_28 )
{
struct V_11 * V_22 = & F_8 ( V_24 ) ;
if ( V_22 -> V_20 )
F_3 ( & V_22 -> V_9 ) ;
}
T_2 F_17 ( struct V_1 * V_2 )
{
if ( F_18 ( V_2 -> V_29 ) )
return V_2 -> V_5 . V_30 ;
else
return V_2 -> V_5 . V_30 ;
}
void F_19 ( struct V_1 * V_2 , T_2 V_31 )
{
if ( F_18 ( V_2 -> V_29 ) )
F_20 ( V_2 , V_31 ) ;
else
V_2 -> V_5 . V_30 = V_31 ;
}
static int F_21 ( int V_32 )
{
switch ( V_32 ) {
case V_33 :
return V_34 ;
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
return V_40 ;
default:
break;
}
return V_41 ;
}
static void F_22 ( struct V_1 * V_2 ,
unsigned V_16 , bool V_42 , T_1 V_43 ,
bool V_44 )
{
T_1 V_45 ;
int V_46 , V_47 ;
F_23 ( V_48 , V_2 ) ;
if ( ! V_2 -> V_5 . V_49 . V_50 ) {
V_51:
V_2 -> V_5 . V_49 . V_50 = true ;
V_2 -> V_5 . V_49 . V_52 = V_42 ;
V_2 -> V_5 . V_49 . V_16 = V_16 ;
V_2 -> V_5 . V_49 . V_43 = V_43 ;
V_2 -> V_5 . V_49 . V_44 = V_44 ;
return;
}
V_45 = V_2 -> V_5 . V_49 . V_16 ;
if ( V_45 == V_53 ) {
F_23 ( V_54 , V_2 ) ;
return;
}
V_46 = F_21 ( V_45 ) ;
V_47 = F_21 ( V_16 ) ;
if ( ( V_46 == V_40 && V_47 == V_40 )
|| ( V_46 == V_34 && V_47 != V_41 ) ) {
V_2 -> V_5 . V_49 . V_50 = true ;
V_2 -> V_5 . V_49 . V_52 = true ;
V_2 -> V_5 . V_49 . V_16 = V_53 ;
V_2 -> V_5 . V_49 . V_43 = 0 ;
} else
goto V_51;
}
void F_24 ( struct V_1 * V_2 , unsigned V_16 )
{
F_22 ( V_2 , V_16 , false , 0 , false ) ;
}
void F_25 ( struct V_1 * V_2 , unsigned V_16 )
{
F_22 ( V_2 , V_16 , false , 0 , true ) ;
}
void F_26 ( struct V_1 * V_2 , int V_55 )
{
if ( V_55 )
F_27 ( V_2 , 0 ) ;
else
V_56 -> V_57 ( V_2 ) ;
}
void F_28 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
++ V_2 -> V_60 . V_61 ;
V_2 -> V_5 . V_62 = V_59 -> V_63 ;
F_29 ( V_2 , V_33 , V_59 -> V_43 ) ;
}
void F_30 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
if ( F_31 ( V_2 ) && ! V_59 -> V_64 )
V_2 -> V_5 . V_65 . V_66 ( V_2 , V_59 ) ;
else
V_2 -> V_5 . V_67 . V_66 ( V_2 , V_59 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_5 . V_68 ) ;
F_23 ( V_69 , V_2 ) ;
}
void F_29 ( struct V_1 * V_2 , unsigned V_16 , T_1 V_43 )
{
F_22 ( V_2 , V_16 , true , V_43 , false ) ;
}
void F_34 ( struct V_1 * V_2 , unsigned V_16 , T_1 V_43 )
{
F_22 ( V_2 , V_16 , true , V_43 , true ) ;
}
bool F_35 ( struct V_1 * V_2 , int V_70 )
{
if ( V_56 -> V_71 ( V_2 ) <= V_70 )
return true ;
F_29 ( V_2 , V_39 , 0 ) ;
return false ;
}
int F_36 ( struct V_1 * V_2 , struct V_72 * V_67 ,
T_3 V_73 , void * V_31 , int V_74 , int V_75 ,
T_1 V_76 )
{
T_3 V_77 ;
T_4 V_78 ;
V_78 = F_37 ( V_73 ) ;
V_77 = V_67 -> V_79 ( V_2 , V_78 , V_76 ) ;
if ( V_77 == V_80 )
return - V_81 ;
V_77 = F_38 ( V_77 ) ;
return F_39 ( V_2 -> V_29 , V_77 , V_31 , V_74 , V_75 ) ;
}
int F_40 ( struct V_1 * V_2 , T_3 V_82 ,
void * V_31 , int V_74 , int V_75 , T_1 V_76 )
{
return F_36 ( V_2 , V_2 -> V_5 . V_83 , V_82 ,
V_31 , V_74 , V_75 , V_76 ) ;
}
int F_41 ( struct V_1 * V_2 , struct V_72 * V_67 , unsigned long V_84 )
{
T_3 V_85 = V_84 >> V_86 ;
unsigned V_74 = ( ( V_84 & ( V_87 - 1 ) ) >> 5 ) << 2 ;
int V_3 ;
int V_88 ;
T_2 V_89 [ F_42 ( V_67 -> V_90 ) ] ;
V_88 = F_36 ( V_2 , V_67 , V_85 , V_89 ,
V_74 * sizeof( T_2 ) , sizeof( V_89 ) ,
V_91 | V_92 ) ;
if ( V_88 < 0 ) {
V_88 = 0 ;
goto V_93;
}
for ( V_3 = 0 ; V_3 < F_42 ( V_89 ) ; ++ V_3 ) {
if ( F_43 ( V_89 [ V_3 ] ) &&
( V_89 [ V_3 ] & V_2 -> V_5 . V_67 . V_94 [ 0 ] [ 2 ] ) ) {
V_88 = 0 ;
goto V_93;
}
}
V_88 = 1 ;
memcpy ( V_67 -> V_90 , V_89 , sizeof( V_67 -> V_90 ) ) ;
F_44 ( V_95 ,
( unsigned long * ) & V_2 -> V_5 . V_96 ) ;
F_44 ( V_95 ,
( unsigned long * ) & V_2 -> V_5 . V_97 ) ;
V_93:
return V_88 ;
}
static bool F_45 ( struct V_1 * V_2 )
{
T_2 V_89 [ F_42 ( V_2 -> V_5 . V_83 -> V_90 ) ] ;
bool V_98 = true ;
int V_74 ;
T_3 V_82 ;
int V_99 ;
if ( F_46 ( V_2 ) || ! F_47 ( V_2 ) )
return false ;
if ( ! F_48 ( V_95 ,
( unsigned long * ) & V_2 -> V_5 . V_96 ) )
return true ;
V_82 = ( F_49 ( V_2 ) & ~ 31u ) >> V_86 ;
V_74 = ( F_49 ( V_2 ) & ~ 31u ) & ( V_87 - 1 ) ;
V_99 = F_40 ( V_2 , V_82 , V_89 , V_74 , sizeof( V_89 ) ,
V_91 | V_92 ) ;
if ( V_99 < 0 )
goto V_93;
V_98 = memcmp ( V_89 , V_2 -> V_5 . V_83 -> V_90 , sizeof( V_89 ) ) != 0 ;
V_93:
return V_98 ;
}
int F_50 ( struct V_1 * V_2 , unsigned long V_100 )
{
unsigned long V_101 = F_51 ( V_2 ) ;
unsigned long V_102 = V_103 | V_104 |
V_105 | V_106 ;
V_100 |= V_107 ;
#ifdef F_52
if ( V_100 & 0xffffffff00000000UL )
return 1 ;
#endif
V_100 &= ~ V_108 ;
if ( ( V_100 & V_106 ) && ! ( V_100 & V_105 ) )
return 1 ;
if ( ( V_100 & V_103 ) && ! ( V_100 & V_109 ) )
return 1 ;
if ( ! F_53 ( V_2 ) && ( V_100 & V_103 ) ) {
#ifdef F_52
if ( ( V_2 -> V_5 . V_110 & V_111 ) ) {
int V_112 , V_113 ;
if ( ! F_47 ( V_2 ) )
return 1 ;
V_56 -> V_114 ( V_2 , & V_112 , & V_113 ) ;
if ( V_113 )
return 1 ;
} else
#endif
if ( F_47 ( V_2 ) && ! F_41 ( V_2 , V_2 -> V_5 . V_83 ,
F_49 ( V_2 ) ) )
return 1 ;
}
V_56 -> V_115 ( V_2 , V_100 ) ;
if ( ( V_100 ^ V_101 ) & V_103 ) {
F_54 ( V_2 ) ;
F_1 ( V_2 ) ;
}
if ( ( V_100 ^ V_101 ) & V_102 )
F_55 ( V_2 ) ;
return 0 ;
}
void F_56 ( struct V_1 * V_2 , unsigned long V_116 )
{
( void ) F_50 ( V_2 , F_57 ( V_2 , ~ 0x0eul ) | ( V_116 & 0x0f ) ) ;
}
int F_58 ( struct V_1 * V_2 , T_1 V_117 , T_2 V_118 )
{
T_2 V_119 ;
if ( V_117 != V_120 )
return 1 ;
V_119 = V_118 ;
if ( V_56 -> V_71 ( V_2 ) != 0 )
return 1 ;
if ( ! ( V_119 & V_121 ) )
return 1 ;
if ( ( V_119 & V_122 ) && ! ( V_119 & V_123 ) )
return 1 ;
if ( V_119 & ~ V_124 )
return 1 ;
V_2 -> V_5 . V_119 = V_119 ;
V_2 -> V_125 = 0 ;
return 0 ;
}
int F_59 ( struct V_1 * V_2 , T_1 V_117 , T_2 V_118 )
{
if ( F_58 ( V_2 , V_117 , V_118 ) ) {
F_27 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_60 ( struct V_1 * V_2 , unsigned long V_126 )
{
unsigned long V_127 = F_61 ( V_2 ) ;
unsigned long V_128 = V_129 | V_130 |
V_131 | V_132 ;
if ( V_126 & V_133 )
return 1 ;
if ( ! F_62 ( V_2 ) && ( V_126 & V_134 ) )
return 1 ;
if ( ! F_63 ( V_2 ) && ( V_126 & V_132 ) )
return 1 ;
if ( ! F_64 ( V_2 ) && ( V_126 & V_135 ) )
return 1 ;
if ( F_46 ( V_2 ) ) {
if ( ! ( V_126 & V_131 ) )
return 1 ;
} else if ( F_53 ( V_2 ) && ( V_126 & V_131 )
&& ( ( V_126 ^ V_127 ) & V_128 )
&& ! F_41 ( V_2 , V_2 -> V_5 . V_83 ,
F_49 ( V_2 ) ) )
return 1 ;
if ( V_56 -> V_136 ( V_2 , V_126 ) )
return 1 ;
if ( ( V_126 ^ V_127 ) & V_128 )
F_55 ( V_2 ) ;
if ( ( V_126 ^ V_127 ) & V_134 )
F_65 ( V_2 ) ;
return 0 ;
}
int F_66 ( struct V_1 * V_2 , unsigned long V_84 )
{
if ( V_84 == F_49 ( V_2 ) && ! F_45 ( V_2 ) ) {
F_67 ( V_2 ) ;
F_68 ( V_2 ) ;
return 0 ;
}
if ( F_46 ( V_2 ) ) {
if ( V_84 & V_137 )
return 1 ;
} else {
if ( F_47 ( V_2 ) ) {
if ( V_84 & V_138 )
return 1 ;
if ( F_53 ( V_2 ) &&
! F_41 ( V_2 , V_2 -> V_5 . V_83 , V_84 ) )
return 1 ;
}
}
if ( F_69 ( ! F_70 ( V_2 -> V_29 , V_84 >> V_86 ) ) )
return 1 ;
V_2 -> V_5 . V_84 = V_84 ;
F_44 ( V_139 , ( V_140 * ) & V_2 -> V_5 . V_96 ) ;
V_2 -> V_5 . V_67 . V_141 ( V_2 ) ;
return 0 ;
}
int F_71 ( struct V_1 * V_2 , unsigned long V_142 )
{
if ( V_142 & V_143 )
return 1 ;
if ( F_18 ( V_2 -> V_29 ) )
F_72 ( V_2 , V_142 ) ;
else
V_2 -> V_5 . V_142 = V_142 ;
return 0 ;
}
unsigned long F_73 ( struct V_1 * V_2 )
{
if ( F_18 ( V_2 -> V_29 ) )
return F_74 ( V_2 ) ;
else
return V_2 -> V_5 . V_142 ;
}
static int F_75 ( struct V_1 * V_2 , int V_144 , unsigned long V_145 )
{
switch ( V_144 ) {
case 0 ... 3 :
V_2 -> V_5 . V_146 [ V_144 ] = V_145 ;
if ( ! ( V_2 -> V_147 & V_148 ) )
V_2 -> V_5 . V_149 [ V_144 ] = V_145 ;
break;
case 4 :
if ( F_76 ( V_2 , V_150 ) )
return 1 ;
case 6 :
if ( V_145 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_151 = ( V_145 & V_152 ) | V_153 ;
break;
case 5 :
if ( F_76 ( V_2 , V_150 ) )
return 1 ;
default:
if ( V_145 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_154 = ( V_145 & V_155 ) | V_156 ;
if ( ! ( V_2 -> V_147 & V_148 ) ) {
V_56 -> V_157 ( V_2 , V_2 -> V_5 . V_154 ) ;
V_2 -> V_5 . V_158 = ( V_145 & V_159 ) ;
}
break;
}
return 0 ;
}
int F_77 ( struct V_1 * V_2 , int V_144 , unsigned long V_145 )
{
int V_160 ;
V_160 = F_75 ( V_2 , V_144 , V_145 ) ;
if ( V_160 > 0 )
F_24 ( V_2 , V_161 ) ;
else if ( V_160 < 0 )
F_27 ( V_2 , 0 ) ;
return V_160 ;
}
static int F_78 ( struct V_1 * V_2 , int V_144 , unsigned long * V_145 )
{
switch ( V_144 ) {
case 0 ... 3 :
* V_145 = V_2 -> V_5 . V_146 [ V_144 ] ;
break;
case 4 :
if ( F_76 ( V_2 , V_150 ) )
return 1 ;
case 6 :
* V_145 = V_2 -> V_5 . V_151 ;
break;
case 5 :
if ( F_76 ( V_2 , V_150 ) )
return 1 ;
default:
* V_145 = V_2 -> V_5 . V_154 ;
break;
}
return 0 ;
}
int F_79 ( struct V_1 * V_2 , int V_144 , unsigned long * V_145 )
{
if ( F_78 ( V_2 , V_144 , V_145 ) ) {
F_24 ( V_2 , V_161 ) ;
return 1 ;
}
return 0 ;
}
bool F_80 ( struct V_1 * V_2 )
{
T_1 V_162 = F_81 ( V_2 , V_163 ) ;
T_2 V_31 ;
int V_55 ;
V_55 = F_82 ( V_2 , V_162 , & V_31 ) ;
if ( V_55 )
return V_55 ;
F_83 ( V_2 , V_164 , ( T_1 ) V_31 ) ;
F_83 ( V_2 , V_165 , V_31 >> 32 ) ;
return V_55 ;
}
static int F_84 ( struct V_1 * V_2 , T_2 V_110 )
{
T_2 V_166 = V_2 -> V_5 . V_110 ;
if ( V_110 & V_167 )
return 1 ;
if ( F_53 ( V_2 )
&& ( V_2 -> V_5 . V_110 & V_111 ) != ( V_110 & V_111 ) )
return 1 ;
if ( V_110 & V_168 ) {
struct V_169 * V_170 ;
V_170 = F_85 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_170 || ! ( V_170 -> V_171 & F_86 ( V_172 ) ) )
return 1 ;
}
if ( V_110 & V_173 ) {
struct V_169 * V_170 ;
V_170 = F_85 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_170 || ! ( V_170 -> V_162 & F_86 ( V_174 ) ) )
return 1 ;
}
V_110 &= ~ V_175 ;
V_110 |= V_2 -> V_5 . V_110 & V_175 ;
V_56 -> F_84 ( V_2 , V_110 ) ;
V_2 -> V_5 . V_67 . V_176 . V_177 = ( V_110 & V_178 ) && ! V_179 ;
if ( ( V_110 ^ V_166 ) & V_178 )
F_55 ( V_2 ) ;
return 0 ;
}
void F_87 ( T_2 V_26 )
{
V_167 &= ~ V_26 ;
}
int F_88 ( struct V_1 * V_2 , T_1 V_180 , T_2 V_31 )
{
return V_56 -> V_181 ( V_2 , V_180 , V_31 ) ;
}
static int F_89 ( struct V_1 * V_2 , unsigned V_117 , T_2 * V_31 )
{
return F_88 ( V_2 , V_117 , * V_31 ) ;
}
static void F_90 ( struct V_29 * V_29 , T_4 V_182 )
{
int V_183 ;
int V_99 ;
struct V_184 V_185 ;
struct V_186 V_187 ;
if ( ! V_182 )
return;
V_99 = F_91 ( V_29 , V_182 , & V_183 , sizeof( V_183 ) ) ;
if ( V_99 )
return;
if ( V_183 & 1 )
++ V_183 ;
++ V_183 ;
F_92 ( V_29 , V_182 , & V_183 , sizeof( V_183 ) ) ;
F_93 ( & V_187 ) ;
V_185 . V_188 = V_187 . V_189 ;
V_185 . V_190 = V_187 . V_191 ;
V_185 . V_183 = V_183 ;
F_92 ( V_29 , V_182 , & V_185 , sizeof( V_185 ) ) ;
V_183 ++ ;
F_92 ( V_29 , V_182 , & V_183 , sizeof( V_183 ) ) ;
}
static T_5 F_94 ( T_5 V_192 , T_5 V_193 )
{
T_5 V_194 , V_195 ;
__asm__ ( "divl %4"
: "=a" (quotient), "=d" (remainder)
: "0" (0), "1" (dividend), "r" (divisor) );
return V_194 ;
}
static void F_95 ( T_5 V_196 , T_5 V_197 ,
T_6 * V_198 , T_1 * V_199 )
{
T_7 V_200 ;
T_8 V_201 = 0 ;
T_7 V_202 ;
T_5 V_203 ;
V_202 = V_197 * 1000LL ;
V_200 = V_196 * 1000LL ;
while ( V_202 > V_200 * 2 || V_202 & 0xffffffff00000000ULL ) {
V_202 >>= 1 ;
V_201 -- ;
}
V_203 = ( T_5 ) V_202 ;
while ( V_203 <= V_200 || V_200 & 0xffffffff00000000ULL ) {
if ( V_200 & 0xffffffff00000000ULL || V_203 & 0x80000000 )
V_200 >>= 1 ;
else
V_203 <<= 1 ;
V_201 ++ ;
}
* V_198 = V_201 ;
* V_199 = F_94 ( V_200 , V_203 ) ;
F_96 ( L_2 ,
V_204 , V_197 , V_196 , V_201 , * V_199 ) ;
}
static inline T_2 F_97 ( void )
{
struct V_186 V_205 ;
F_98 ( F_99 () ) ;
F_100 ( & V_205 ) ;
F_101 ( & V_205 ) ;
return F_102 ( & V_205 ) ;
}
static inline int F_103 ( void )
{
int V_206 = F_104 () ;
int V_88 = ! F_105 ( V_207 ) &&
F_106 ( V_206 ) != 0 ;
F_107 () ;
return V_88 ;
}
T_2 F_108 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_208 )
return V_2 -> V_5 . V_208 ;
else
return F_109 ( V_209 ) ;
}
static inline T_2 F_110 ( struct V_1 * V_2 , T_2 V_190 )
{
T_2 V_88 ;
F_98 ( F_99 () ) ;
if ( F_103 () )
F_111 ( V_210
L_3 ) ;
V_88 = V_190 * F_108 ( V_2 ) ;
F_112 ( V_88 , V_211 ) ;
return V_88 ;
}
static void F_113 ( struct V_1 * V_2 , T_1 V_212 )
{
F_95 ( V_212 , V_213 / 1000 ,
& V_2 -> V_5 . V_214 ,
& V_2 -> V_5 . V_215 ) ;
}
static T_2 F_114 ( struct V_1 * V_2 , T_9 V_216 )
{
T_2 V_217 = F_115 ( V_216 - V_2 -> V_5 . V_218 ,
V_2 -> V_5 . V_215 ,
V_2 -> V_5 . V_214 ) ;
V_217 += V_2 -> V_5 . V_219 ;
return V_217 ;
}
void F_116 ( struct V_1 * V_2 , T_2 V_31 )
{
struct V_29 * V_29 = V_2 -> V_29 ;
T_2 V_74 , V_220 , V_221 ;
unsigned long V_222 ;
T_9 V_223 ;
F_117 ( & V_29 -> V_5 . V_224 , V_222 ) ;
V_74 = V_56 -> V_225 ( V_2 , V_31 ) ;
V_220 = F_97 () ;
V_221 = V_220 - V_29 -> V_5 . V_218 ;
V_223 = V_31 - V_29 -> V_5 . V_219 ;
if ( V_223 < 0 )
V_223 = - V_223 ;
if ( V_223 < F_110 ( V_2 , 5ULL * V_213 ) &&
V_221 < 5ULL * V_213 ) {
if ( ! F_118 () ) {
V_74 = V_29 -> V_5 . V_226 ;
F_96 ( L_4 , V_31 ) ;
} else {
T_2 V_227 = F_110 ( V_2 , V_221 ) ;
V_74 += V_227 ;
F_96 ( L_5 , V_227 ) ;
}
V_220 = V_29 -> V_5 . V_218 ;
}
V_29 -> V_5 . V_218 = V_220 ;
V_29 -> V_5 . V_219 = V_31 ;
V_29 -> V_5 . V_226 = V_74 ;
V_56 -> V_228 ( V_2 , V_74 ) ;
F_119 ( & V_29 -> V_5 . V_224 , V_222 ) ;
V_2 -> V_5 . V_229 . V_230 = 0 ;
V_2 -> V_5 . V_219 = V_31 ;
V_2 -> V_5 . V_218 = V_220 ;
}
static int F_120 ( struct V_1 * V_231 )
{
unsigned long V_222 ;
struct V_232 * V_2 = & V_231 -> V_5 ;
void * V_233 ;
unsigned long V_212 ;
T_9 V_216 , V_234 ;
T_2 V_230 ;
F_121 ( V_222 ) ;
V_230 = V_56 -> V_235 ( V_231 ) ;
V_216 = F_97 () ;
V_212 = F_108 ( V_231 ) ;
if ( F_69 ( V_212 == 0 ) ) {
F_122 ( V_222 ) ;
F_23 ( V_236 , V_231 ) ;
return 1 ;
}
if ( V_2 -> V_237 ) {
T_2 V_217 = F_114 ( V_231 , V_216 ) ;
if ( V_217 > V_230 ) {
V_56 -> V_238 ( V_231 , V_217 - V_230 ) ;
V_230 = V_217 ;
}
}
F_122 ( V_222 ) ;
if ( ! V_2 -> V_239 )
return 0 ;
V_234 = 0 ;
if ( V_2 -> V_229 . V_230 && V_2 -> V_240 ) {
V_234 = V_2 -> V_240 -
V_2 -> V_229 . V_230 ;
V_234 = F_115 ( V_234 ,
V_2 -> V_229 . V_241 ,
V_2 -> V_229 . V_242 ) ;
V_234 += V_2 -> V_243 ;
}
if ( F_69 ( V_2 -> V_244 != V_212 ) ) {
F_95 ( V_213 / 1000 , V_212 ,
& V_2 -> V_229 . V_242 ,
& V_2 -> V_229 . V_241 ) ;
V_2 -> V_244 = V_212 ;
}
if ( V_234 > V_216 )
V_216 = V_234 ;
V_2 -> V_229 . V_230 = V_230 ;
V_2 -> V_229 . V_245 = V_216 + V_231 -> V_29 -> V_5 . V_246 ;
V_2 -> V_243 = V_216 ;
V_2 -> V_240 = V_230 ;
V_2 -> V_229 . V_222 = 0 ;
V_2 -> V_229 . V_183 += 2 ;
V_233 = F_123 ( V_2 -> V_239 , V_247 ) ;
memcpy ( V_233 + V_2 -> V_248 , & V_2 -> V_229 ,
sizeof( V_2 -> V_229 ) ) ;
F_124 ( V_233 , V_247 ) ;
F_125 ( V_231 -> V_29 , V_2 -> time >> V_86 ) ;
return 0 ;
}
static bool F_126 ( unsigned V_21 )
{
switch ( V_21 ) {
case 0x200 ... 0x200 + 2 * V_249 - 1 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
case V_262 :
return true ;
case 0x2f8 :
return true ;
}
return false ;
}
static bool F_127 ( unsigned V_263 )
{
return V_263 < 8 && ( 1 << V_263 ) & 0xf3 ;
}
static bool F_128 ( unsigned V_263 )
{
return V_263 < 8 && ( 1 << V_263 ) & 0x73 ;
}
static bool F_129 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
int V_3 ;
if ( ! F_126 ( V_21 ) )
return false ;
if ( V_21 == V_262 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_127 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
} else if ( V_21 == V_261 ) {
if ( V_31 & ~ 0xcff )
return false ;
return F_128 ( V_31 & 0xff ) ;
} else if ( V_21 >= V_250 && V_21 <= V_260 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_128 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
}
return F_128 ( V_31 & 0xff ) ;
}
static int F_130 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
T_2 * V_264 = ( T_2 * ) & V_2 -> V_5 . V_265 . V_266 ;
if ( ! F_129 ( V_2 , V_21 , V_31 ) )
return 1 ;
if ( V_21 == V_261 ) {
V_2 -> V_5 . V_265 . V_267 = V_31 ;
V_2 -> V_5 . V_265 . V_268 = ( V_31 & 0xc00 ) >> 10 ;
} else if ( V_21 == V_250 )
V_264 [ 0 ] = V_31 ;
else if ( V_21 == V_251 || V_21 == V_252 )
V_264 [ 1 + V_21 - V_251 ] = V_31 ;
else if ( V_21 >= V_253 && V_21 <= V_260 )
V_264 [ 3 + V_21 - V_253 ] = V_31 ;
else if ( V_21 == V_262 )
V_2 -> V_5 . V_269 = V_31 ;
else {
int V_270 , V_271 ;
T_2 * V_272 ;
V_270 = ( V_21 - 0x200 ) / 2 ;
V_271 = V_21 - 0x200 - 2 * V_270 ;
if ( ! V_271 )
V_272 =
( T_2 * ) & V_2 -> V_5 . V_265 . V_273 [ V_270 ] . V_274 ;
else
V_272 =
( T_2 * ) & V_2 -> V_5 . V_265 . V_273 [ V_270 ] . V_275 ;
* V_272 = V_31 ;
}
F_55 ( V_2 ) ;
return 0 ;
}
static int F_131 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
T_2 V_276 = V_2 -> V_5 . V_276 ;
unsigned V_277 = V_276 & 0xff ;
switch ( V_21 ) {
case V_278 :
V_2 -> V_5 . V_279 = V_31 ;
break;
case V_280 :
if ( ! ( V_276 & V_281 ) )
return 1 ;
if ( V_31 != 0 && V_31 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_282 = V_31 ;
break;
default:
if ( V_21 >= V_283 &&
V_21 < V_283 + 4 * V_277 ) {
T_1 V_74 = V_21 - V_283 ;
if ( ( V_74 & 0x3 ) == 0 &&
V_31 != 0 && ( V_31 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_284 [ V_74 ] = V_31 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_132 ( struct V_1 * V_2 , T_2 V_31 )
{
struct V_29 * V_29 = V_2 -> V_29 ;
int V_285 = F_46 ( V_2 ) ;
T_10 * V_286 = V_285 ? ( T_10 * ) ( long ) V_29 -> V_5 . F_132 . V_287
: ( T_10 * ) ( long ) V_29 -> V_5 . F_132 . V_288 ;
T_10 V_289 = V_285 ? V_29 -> V_5 . F_132 . V_290
: V_29 -> V_5 . F_132 . V_291 ;
T_1 V_292 = V_31 & ~ V_293 ;
T_2 V_294 = V_31 & V_293 ;
T_10 * V_295 ;
int V_99 ;
V_99 = - V_296 ;
if ( V_292 >= V_289 )
goto V_93;
V_99 = - V_297 ;
V_295 = F_133 ( V_286 + ( V_292 * V_87 ) , V_87 ) ;
if ( F_134 ( V_295 ) ) {
V_99 = F_135 ( V_295 ) ;
goto V_93;
}
if ( F_92 ( V_29 , V_294 , V_295 , V_87 ) )
goto V_298;
V_99 = 0 ;
V_298:
F_136 ( V_295 ) ;
V_93:
return V_99 ;
}
static bool F_137 ( struct V_29 * V_29 )
{
return V_29 -> V_5 . V_299 & V_300 ;
}
static bool F_138 ( T_1 V_21 )
{
bool V_99 = false ;
switch ( V_21 ) {
case V_301 :
case V_302 :
V_99 = true ;
break;
}
return V_99 ;
}
static int F_139 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
struct V_29 * V_29 = V_2 -> V_29 ;
switch ( V_21 ) {
case V_301 :
V_29 -> V_5 . V_303 = V_31 ;
if ( ! V_29 -> V_5 . V_303 )
V_29 -> V_5 . V_299 &= ~ V_300 ;
break;
case V_302 : {
T_2 V_82 ;
unsigned long V_304 ;
T_10 V_305 [ 4 ] ;
if ( ! V_29 -> V_5 . V_303 )
break;
if ( ! ( V_31 & V_300 ) ) {
V_29 -> V_5 . V_299 = V_31 ;
break;
}
V_82 = V_31 >> V_306 ;
V_304 = F_140 ( V_29 , V_82 ) ;
if ( F_141 ( V_304 ) )
return 1 ;
V_56 -> V_307 ( V_2 , V_305 ) ;
( ( unsigned char * ) V_305 ) [ 3 ] = 0xc3 ;
if ( F_142 ( ( void V_308 * ) V_304 , V_305 , 4 ) )
return 1 ;
V_29 -> V_5 . V_299 = V_31 ;
break;
}
default:
F_143 ( V_2 , L_6
L_7 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_144 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
switch ( V_21 ) {
case V_309 : {
unsigned long V_304 ;
if ( ! ( V_31 & V_310 ) ) {
V_2 -> V_5 . V_311 = V_31 ;
break;
}
V_304 = F_140 ( V_2 -> V_29 , V_31 >>
V_312 ) ;
if ( F_141 ( V_304 ) )
return 1 ;
if ( F_145 ( ( void V_308 * ) V_304 , V_87 ) )
return 1 ;
V_2 -> V_5 . V_311 = V_31 ;
break;
}
case V_313 :
return F_146 ( V_2 , V_314 , V_31 ) ;
case V_315 :
return F_146 ( V_2 , V_316 , V_31 ) ;
case V_317 :
return F_146 ( V_2 , V_318 , V_31 ) ;
default:
F_143 ( V_2 , L_6
L_7 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_147 ( struct V_1 * V_2 , T_2 V_31 )
{
T_4 V_319 = V_31 & ~ 0x3f ;
if ( V_31 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_320 = V_31 ;
if ( ! ( V_31 & V_321 ) ) {
F_54 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_148 ( V_2 -> V_29 , & V_2 -> V_5 . V_6 . V_31 , V_319 ) )
return 1 ;
V_2 -> V_5 . V_6 . V_322 = ! ( V_31 & V_323 ) ;
F_149 ( V_2 ) ;
return 0 ;
}
static void F_150 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_239 ) {
F_151 ( V_2 -> V_5 . V_239 ) ;
V_2 -> V_5 . V_239 = NULL ;
}
}
static void F_152 ( struct V_1 * V_2 )
{
T_2 V_227 ;
if ( ! ( V_2 -> V_5 . V_324 . V_320 & V_325 ) )
return;
V_227 = V_326 -> V_327 . V_328 - V_2 -> V_5 . V_324 . V_329 ;
V_2 -> V_5 . V_324 . V_329 = V_326 -> V_327 . V_328 ;
V_2 -> V_5 . V_324 . V_330 = V_227 ;
}
static void F_153 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_324 . V_320 & V_325 ) )
return;
if ( F_69 ( F_154 ( V_2 -> V_29 , & V_2 -> V_5 . V_324 . V_331 ,
& V_2 -> V_5 . V_324 . V_332 , sizeof( struct V_333 ) ) ) )
return;
V_2 -> V_5 . V_324 . V_332 . V_332 += V_2 -> V_5 . V_324 . V_330 ;
V_2 -> V_5 . V_324 . V_332 . V_183 += 2 ;
V_2 -> V_5 . V_324 . V_330 = 0 ;
F_155 ( V_2 -> V_29 , & V_2 -> V_5 . V_324 . V_331 ,
& V_2 -> V_5 . V_324 . V_332 , sizeof( struct V_333 ) ) ;
}
int F_156 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
bool V_334 = false ;
switch ( V_21 ) {
case V_335 :
return F_84 ( V_2 , V_31 ) ;
case V_336 :
V_31 &= ~ ( T_2 ) 0x40 ;
V_31 &= ~ ( T_2 ) 0x100 ;
if ( V_31 != 0 ) {
F_143 ( V_2 , L_8 ,
V_31 ) ;
return 1 ;
}
break;
case V_337 :
if ( V_31 != 0 ) {
F_143 ( V_2 , L_9
L_10 , V_31 ) ;
return 1 ;
}
break;
case V_338 :
break;
case V_339 :
if ( ! V_31 ) {
break;
} else if ( V_31 & ~ ( V_340 | V_341 ) ) {
return 1 ;
}
F_143 ( V_2 , L_11 ,
V_204 , V_31 ) ;
break;
case V_342 :
case V_343 :
case V_344 :
case V_345 :
break;
case 0x200 ... 0x2ff :
return F_130 ( V_2 , V_21 , V_31 ) ;
case V_346 :
F_19 ( V_2 , V_31 ) ;
break;
case V_347 ... V_347 + 0x3ff :
return F_157 ( V_2 , V_21 , V_31 ) ;
case V_348 :
F_158 ( V_2 , V_31 ) ;
break;
case V_349 :
V_2 -> V_5 . V_350 = V_31 ;
break;
case V_351 :
case V_352 :
V_2 -> V_29 -> V_5 . V_182 = V_31 ;
F_90 ( V_2 -> V_29 , V_31 ) ;
break;
case V_353 :
case V_354 : {
F_150 ( V_2 ) ;
V_2 -> V_5 . time = V_31 ;
F_23 ( V_236 , V_2 ) ;
if ( ! ( V_31 & 1 ) )
break;
V_2 -> V_5 . V_248 = V_31 & ~ ( V_293 | 1 ) ;
V_2 -> V_5 . V_239 =
F_159 ( V_2 -> V_29 , V_31 >> V_86 ) ;
if ( F_160 ( V_2 -> V_5 . V_239 ) ) {
F_161 ( V_2 -> V_5 . V_239 ) ;
V_2 -> V_5 . V_239 = NULL ;
}
break;
}
case V_355 :
if ( F_147 ( V_2 , V_31 ) )
return 1 ;
break;
case V_356 :
if ( F_69 ( ! F_162 () ) )
return 1 ;
if ( V_31 & V_357 )
return 1 ;
if ( F_148 ( V_2 -> V_29 , & V_2 -> V_5 . V_324 . V_331 ,
V_31 & V_358 ) )
return 1 ;
V_2 -> V_5 . V_324 . V_320 = V_31 ;
if ( ! ( V_31 & V_325 ) )
break;
V_2 -> V_5 . V_324 . V_329 = V_326 -> V_327 . V_328 ;
F_163 () ;
F_152 ( V_2 ) ;
F_164 () ;
F_23 ( V_359 , V_2 ) ;
break;
case V_280 :
case V_278 :
case V_283 ... V_283 + 4 * V_360 - 1 :
return F_131 ( V_2 , V_21 , V_31 ) ;
case V_361 :
case V_362 :
case V_363 :
case V_364 :
if ( V_31 != 0 )
F_143 ( V_2 , L_12
L_13 , V_21 , V_31 ) ;
break;
case V_365 :
case V_366 :
case V_367 :
case V_368 :
F_143 ( V_2 , L_12
L_13 , V_21 , V_31 ) ;
break;
case V_369 :
case V_370 :
V_334 = true ;
case V_371 :
case V_372 :
if ( F_165 ( V_2 , V_21 ) )
return F_166 ( V_2 , V_21 , V_31 ) ;
if ( V_334 || V_31 != 0 )
F_143 ( V_2 , L_14
L_13 , V_21 , V_31 ) ;
break;
case V_373 :
break;
case V_301 ... V_374 :
if ( F_138 ( V_21 ) ) {
int V_99 ;
F_167 ( & V_2 -> V_29 -> V_375 ) ;
V_99 = F_139 ( V_2 , V_21 , V_31 ) ;
F_168 ( & V_2 -> V_29 -> V_375 ) ;
return V_99 ;
} else
return F_144 ( V_2 , V_21 , V_31 ) ;
break;
case V_376 :
F_143 ( V_2 , L_15 , V_21 , V_31 ) ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_29 -> V_5 . F_132 . V_21 ) )
return F_132 ( V_2 , V_31 ) ;
if ( F_165 ( V_2 , V_21 ) )
return F_166 ( V_2 , V_21 , V_31 ) ;
if ( ! V_377 ) {
F_143 ( V_2 , L_16 ,
V_21 , V_31 ) ;
return 1 ;
} else {
F_143 ( V_2 , L_15 ,
V_21 , V_31 ) ;
break;
}
}
return 0 ;
}
int F_169 ( struct V_1 * V_2 , T_1 V_180 , T_2 * V_378 )
{
return V_56 -> V_379 ( V_2 , V_180 , V_378 ) ;
}
static int F_170 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_378 )
{
T_2 * V_264 = ( T_2 * ) & V_2 -> V_5 . V_265 . V_266 ;
if ( ! F_126 ( V_21 ) )
return 1 ;
if ( V_21 == V_261 )
* V_378 = V_2 -> V_5 . V_265 . V_267 +
( V_2 -> V_5 . V_265 . V_268 << 10 ) ;
else if ( V_21 == V_250 )
* V_378 = V_264 [ 0 ] ;
else if ( V_21 == V_251 || V_21 == V_252 )
* V_378 = V_264 [ 1 + V_21 - V_251 ] ;
else if ( V_21 >= V_253 && V_21 <= V_260 )
* V_378 = V_264 [ 3 + V_21 - V_253 ] ;
else if ( V_21 == V_262 )
* V_378 = V_2 -> V_5 . V_269 ;
else {
int V_270 , V_271 ;
T_2 * V_272 ;
V_270 = ( V_21 - 0x200 ) / 2 ;
V_271 = V_21 - 0x200 - 2 * V_270 ;
if ( ! V_271 )
V_272 =
( T_2 * ) & V_2 -> V_5 . V_265 . V_273 [ V_270 ] . V_274 ;
else
V_272 =
( T_2 * ) & V_2 -> V_5 . V_265 . V_273 [ V_270 ] . V_275 ;
* V_378 = * V_272 ;
}
return 0 ;
}
static int F_171 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_378 )
{
T_2 V_31 ;
T_2 V_276 = V_2 -> V_5 . V_276 ;
unsigned V_277 = V_276 & 0xff ;
switch ( V_21 ) {
case V_380 :
case V_381 :
V_31 = 0 ;
break;
case V_382 :
V_31 = V_2 -> V_5 . V_276 ;
break;
case V_280 :
if ( ! ( V_276 & V_281 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_282 ;
break;
case V_278 :
V_31 = V_2 -> V_5 . V_279 ;
break;
default:
if ( V_21 >= V_283 &&
V_21 < V_283 + 4 * V_277 ) {
T_1 V_74 = V_21 - V_283 ;
V_31 = V_2 -> V_5 . V_284 [ V_74 ] ;
break;
}
return 1 ;
}
* V_378 = V_31 ;
return 0 ;
}
static int F_172 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_378 )
{
T_2 V_31 = 0 ;
struct V_29 * V_29 = V_2 -> V_29 ;
switch ( V_21 ) {
case V_301 :
V_31 = V_29 -> V_5 . V_303 ;
break;
case V_302 :
V_31 = V_29 -> V_5 . V_299 ;
break;
default:
F_143 ( V_2 , L_17 , V_21 ) ;
return 1 ;
}
* V_378 = V_31 ;
return 0 ;
}
static int F_173 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_378 )
{
T_2 V_31 = 0 ;
switch ( V_21 ) {
case V_383 : {
int V_99 ;
struct V_1 * V_231 ;
F_174 (r, v, vcpu->kvm)
if ( V_231 == V_2 )
V_31 = V_99 ;
break;
}
case V_313 :
return F_175 ( V_2 , V_314 , V_378 ) ;
case V_315 :
return F_175 ( V_2 , V_316 , V_378 ) ;
case V_317 :
return F_175 ( V_2 , V_318 , V_378 ) ;
case V_309 :
V_31 = V_2 -> V_5 . V_311 ;
break;
default:
F_143 ( V_2 , L_17 , V_21 ) ;
return 1 ;
}
* V_378 = V_31 ;
return 0 ;
}
int F_176 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_378 )
{
T_2 V_31 ;
switch ( V_21 ) {
case V_384 :
case V_385 :
case V_339 :
case V_386 :
case V_387 :
case V_388 :
case V_389 :
case V_390 :
case V_336 :
case V_344 :
case V_361 :
case V_365 :
case V_391 :
case V_338 :
case V_337 :
V_31 = 0 ;
break;
case V_369 :
case V_370 :
case V_371 :
case V_372 :
if ( F_165 ( V_2 , V_21 ) )
return F_177 ( V_2 , V_21 , V_378 ) ;
V_31 = 0 ;
break;
case V_342 :
V_31 = 0x100000000ULL ;
break;
case V_392 :
V_31 = 0x500 | V_249 ;
break;
case 0x200 ... 0x2ff :
return F_170 ( V_2 , V_21 , V_378 ) ;
case 0xcd :
V_31 = 3 ;
break;
case V_393 :
V_31 = 1 << 24 ;
break;
case V_346 :
V_31 = F_17 ( V_2 ) ;
break;
case V_347 ... V_347 + 0x3ff :
return F_178 ( V_2 , V_21 , V_378 ) ;
break;
case V_348 :
V_31 = F_179 ( V_2 ) ;
break;
case V_349 :
V_31 = V_2 -> V_5 . V_350 ;
break;
case V_394 :
V_31 = 1000ULL ;
V_31 |= ( ( ( T_7 ) 4ULL ) << 40 ) ;
break;
case V_335 :
V_31 = V_2 -> V_5 . V_110 ;
break;
case V_352 :
case V_351 :
V_31 = V_2 -> V_29 -> V_5 . V_182 ;
break;
case V_354 :
case V_353 :
V_31 = V_2 -> V_5 . time ;
break;
case V_355 :
V_31 = V_2 -> V_5 . V_6 . V_320 ;
break;
case V_356 :
V_31 = V_2 -> V_5 . V_324 . V_320 ;
break;
case V_380 :
case V_381 :
case V_382 :
case V_280 :
case V_278 :
case V_283 ... V_283 + 4 * V_360 - 1 :
return F_171 ( V_2 , V_21 , V_378 ) ;
case V_373 :
V_31 = 0x20000000 ;
break;
case V_301 ... V_374 :
if ( F_138 ( V_21 ) ) {
int V_99 ;
F_167 ( & V_2 -> V_29 -> V_375 ) ;
V_99 = F_172 ( V_2 , V_21 , V_378 ) ;
F_168 ( & V_2 -> V_29 -> V_375 ) ;
return V_99 ;
} else
return F_173 ( V_2 , V_21 , V_378 ) ;
break;
case V_376 :
V_31 = 0xbe702111 ;
break;
default:
if ( F_165 ( V_2 , V_21 ) )
return F_177 ( V_2 , V_21 , V_378 ) ;
if ( ! V_377 ) {
F_143 ( V_2 , L_18 , V_21 ) ;
return 1 ;
} else {
F_143 ( V_2 , L_19 , V_21 ) ;
V_31 = 0 ;
}
break;
}
* V_378 = V_31 ;
return 0 ;
}
static int F_180 ( struct V_1 * V_2 , struct V_395 * V_19 ,
struct V_396 * V_397 ,
int (* F_181)( struct V_1 * V_2 ,
unsigned V_117 , T_2 * V_31 ) )
{
int V_3 , V_270 ;
V_270 = F_182 ( & V_2 -> V_29 -> V_398 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_399 ; ++ V_3 )
if ( F_181 ( V_2 , V_397 [ V_3 ] . V_117 , & V_397 [ V_3 ] . V_31 ) )
break;
F_183 ( & V_2 -> V_29 -> V_398 , V_270 ) ;
return V_3 ;
}
static int F_184 ( struct V_1 * V_2 , struct V_395 V_308 * V_400 ,
int (* F_181)( struct V_1 * V_2 ,
unsigned V_117 , T_2 * V_31 ) ,
int V_401 )
{
struct V_395 V_19 ;
struct V_396 * V_397 ;
int V_99 , V_402 ;
unsigned V_403 ;
V_99 = - V_81 ;
if ( F_185 ( & V_19 , V_400 , sizeof V_19 ) )
goto V_93;
V_99 = - V_296 ;
if ( V_19 . V_399 >= V_404 )
goto V_93;
V_403 = sizeof( struct V_396 ) * V_19 . V_399 ;
V_397 = F_133 ( V_400 -> V_397 , V_403 ) ;
if ( F_134 ( V_397 ) ) {
V_99 = F_135 ( V_397 ) ;
goto V_93;
}
V_99 = V_402 = F_180 ( V_2 , & V_19 , V_397 , F_181 ) ;
if ( V_99 < 0 )
goto V_298;
V_99 = - V_81 ;
if ( V_401 && F_186 ( V_400 -> V_397 , V_397 , V_403 ) )
goto V_298;
V_99 = V_402 ;
V_298:
F_136 ( V_397 ) ;
V_93:
return V_99 ;
}
int F_187 ( long V_405 )
{
int V_99 ;
switch ( V_405 ) {
case V_406 :
case V_407 :
case V_408 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_413 :
case V_414 :
case V_415 :
case V_416 :
case V_417 :
case V_418 :
case V_419 :
case V_420 :
case V_421 :
case V_422 :
case V_423 :
case V_424 :
case V_425 :
case V_426 :
case V_427 :
case V_428 :
case V_429 :
case V_430 :
case V_431 :
case V_432 :
case V_433 :
case V_434 :
case V_435 :
case V_436 :
V_99 = 1 ;
break;
case V_437 :
V_99 = V_438 ;
break;
case V_439 :
V_99 = ! V_56 -> V_440 () ;
break;
case V_441 :
V_99 = V_442 ;
break;
case V_443 :
V_99 = V_444 ;
break;
case V_445 :
V_99 = V_446 ;
break;
case V_447 :
V_99 = 0 ;
break;
case V_448 :
V_99 = F_188 ( & V_449 ) ;
break;
case V_450 :
V_99 = V_360 ;
break;
case V_451 :
V_99 = V_452 ;
break;
case V_453 :
V_99 = V_454 ;
break;
case V_455 :
V_99 = F_105 ( V_456 ) ;
break;
default:
V_99 = 0 ;
break;
}
return V_99 ;
}
long F_189 ( struct V_457 * V_458 ,
unsigned int V_459 , unsigned long V_460 )
{
void V_308 * V_461 = ( void V_308 * ) V_460 ;
long V_99 ;
switch ( V_459 ) {
case V_462 : {
struct V_463 V_308 * V_464 = V_461 ;
struct V_463 V_465 ;
unsigned V_402 ;
V_99 = - V_81 ;
if ( F_185 ( & V_465 , V_464 , sizeof V_465 ) )
goto V_93;
V_402 = V_465 . V_399 ;
V_465 . V_399 = V_466 + F_42 ( V_467 ) ;
if ( F_186 ( V_464 , & V_465 , sizeof V_465 ) )
goto V_93;
V_99 = - V_296 ;
if ( V_402 < V_465 . V_399 )
goto V_93;
V_99 = - V_81 ;
if ( F_186 ( V_464 -> V_468 , & V_469 ,
V_466 * sizeof( T_1 ) ) )
goto V_93;
if ( F_186 ( V_464 -> V_468 + V_466 ,
& V_467 ,
F_42 ( V_467 ) * sizeof( T_1 ) ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_470 : {
struct V_471 V_308 * V_472 = V_461 ;
struct V_471 V_473 ;
V_99 = - V_81 ;
if ( F_185 ( & V_473 , V_472 , sizeof V_473 ) )
goto V_93;
V_99 = F_190 ( & V_473 ,
V_472 -> V_397 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_186 ( V_472 , & V_473 , sizeof V_473 ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_474 : {
T_2 V_475 ;
V_475 = V_476 ;
V_99 = - V_81 ;
if ( F_186 ( V_461 , & V_475 , sizeof V_475 ) )
goto V_93;
V_99 = 0 ;
break;
}
default:
V_99 = - V_477 ;
}
V_93:
return V_99 ;
}
static void F_191 ( void * V_478 )
{
F_192 () ;
}
static bool F_193 ( struct V_1 * V_2 )
{
return V_2 -> V_29 -> V_5 . V_479 &&
! ( V_2 -> V_29 -> V_5 . V_480 & V_481 ) ;
}
void F_194 ( struct V_1 * V_2 , int V_206 )
{
if ( F_193 ( V_2 ) ) {
if ( V_56 -> V_482 () )
F_195 ( V_206 , V_2 -> V_5 . V_483 ) ;
else if ( V_2 -> V_206 != - 1 && V_2 -> V_206 != V_206 )
F_196 ( V_2 -> V_206 ,
F_191 , NULL , 1 ) ;
}
V_56 -> V_484 ( V_2 , V_206 ) ;
if ( F_69 ( V_2 -> V_206 != V_206 ) || F_118 () ) {
T_9 V_485 ;
T_2 V_217 ;
V_217 = V_56 -> V_235 ( V_2 ) ;
V_485 = ! V_2 -> V_5 . V_240 ? 0 :
V_217 - V_2 -> V_5 . V_240 ;
if ( V_485 < 0 )
F_197 ( L_20 ) ;
if ( F_118 () ) {
V_56 -> V_238 ( V_2 , - V_485 ) ;
V_2 -> V_5 . V_237 = 1 ;
}
F_23 ( V_236 , V_2 ) ;
if ( V_2 -> V_206 != V_206 )
F_198 ( V_2 ) ;
V_2 -> V_206 = V_206 ;
}
F_152 ( V_2 ) ;
F_23 ( V_359 , V_2 ) ;
}
void F_199 ( struct V_1 * V_2 )
{
V_56 -> V_486 ( V_2 ) ;
F_200 ( V_2 ) ;
V_2 -> V_5 . V_240 = V_56 -> V_235 ( V_2 ) ;
}
static int F_201 ( struct V_1 * V_2 ,
struct V_487 * V_488 )
{
memcpy ( V_488 -> V_489 , V_2 -> V_5 . V_490 -> V_489 , sizeof *V_488 ) ;
return 0 ;
}
static int F_202 ( struct V_1 * V_2 ,
struct V_487 * V_488 )
{
memcpy ( V_2 -> V_5 . V_490 -> V_489 , V_488 -> V_489 , sizeof *V_488 ) ;
F_203 ( V_2 ) ;
F_204 ( V_2 ) ;
return 0 ;
}
static int F_205 ( struct V_1 * V_2 ,
struct V_491 * V_492 )
{
if ( V_492 -> V_492 < 0 || V_492 -> V_492 >= 256 )
return - V_477 ;
if ( F_18 ( V_2 -> V_29 ) )
return - V_493 ;
F_206 ( V_2 , V_492 -> V_492 , false ) ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
static int F_207 ( struct V_1 * V_2 )
{
F_32 ( V_2 ) ;
return 0 ;
}
static int F_208 ( struct V_1 * V_2 ,
struct V_494 * V_495 )
{
if ( V_495 -> V_222 )
return - V_477 ;
V_2 -> V_5 . V_496 = ! ! V_495 -> V_268 ;
return 0 ;
}
static int F_209 ( struct V_1 * V_2 ,
T_2 V_276 )
{
int V_99 ;
unsigned V_277 = V_276 & 0xff , V_497 ;
V_99 = - V_477 ;
if ( ! V_277 || V_277 >= V_360 )
goto V_93;
if ( V_276 & ~ ( V_476 | 0xff | 0xff0000 ) )
goto V_93;
V_99 = 0 ;
V_2 -> V_5 . V_276 = V_276 ;
if ( V_276 & V_281 )
V_2 -> V_5 . V_282 = ~ ( T_2 ) 0 ;
for ( V_497 = 0 ; V_497 < V_277 ; V_497 ++ )
V_2 -> V_5 . V_284 [ V_497 * 4 ] = ~ ( T_2 ) 0 ;
V_93:
return V_99 ;
}
static int F_210 ( struct V_1 * V_2 ,
struct V_498 * V_499 )
{
T_2 V_276 = V_2 -> V_5 . V_276 ;
unsigned V_277 = V_276 & 0xff ;
T_2 * V_500 = V_2 -> V_5 . V_284 ;
if ( V_499 -> V_497 >= V_277 || ! ( V_499 -> V_501 & V_502 ) )
return - V_477 ;
if ( ( V_499 -> V_501 & V_503 ) && ( V_276 & V_281 ) &&
V_2 -> V_5 . V_282 != ~ ( T_2 ) 0 )
return 0 ;
V_500 += 4 * V_499 -> V_497 ;
if ( ( V_499 -> V_501 & V_503 ) && V_500 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_499 -> V_501 & V_503 ) {
if ( ( V_2 -> V_5 . V_279 & V_504 ) ||
! F_76 ( V_2 , V_505 ) ) {
F_23 ( V_54 , V_2 ) ;
return 0 ;
}
if ( V_500 [ 1 ] & V_502 )
V_499 -> V_501 |= V_506 ;
V_500 [ 2 ] = V_499 -> V_304 ;
V_500 [ 3 ] = V_499 -> V_507 ;
V_2 -> V_5 . V_279 = V_499 -> V_279 ;
V_500 [ 1 ] = V_499 -> V_501 ;
F_24 ( V_2 , V_508 ) ;
} else if ( ! ( V_500 [ 1 ] & V_502 )
|| ! ( V_500 [ 1 ] & V_503 ) ) {
if ( V_500 [ 1 ] & V_502 )
V_499 -> V_501 |= V_506 ;
V_500 [ 2 ] = V_499 -> V_304 ;
V_500 [ 3 ] = V_499 -> V_507 ;
V_500 [ 1 ] = V_499 -> V_501 ;
} else
V_500 [ 1 ] |= V_506 ;
return 0 ;
}
static void F_211 ( struct V_1 * V_2 ,
struct V_509 * V_510 )
{
F_212 ( V_2 ) ;
V_510 -> V_49 . V_511 =
V_2 -> V_5 . V_49 . V_50 &&
! F_213 ( V_2 -> V_5 . V_49 . V_16 ) ;
V_510 -> V_49 . V_16 = V_2 -> V_5 . V_49 . V_16 ;
V_510 -> V_49 . V_52 = V_2 -> V_5 . V_49 . V_52 ;
V_510 -> V_49 . V_512 = 0 ;
V_510 -> V_49 . V_43 = V_2 -> V_5 . V_49 . V_43 ;
V_510 -> V_513 . V_511 =
V_2 -> V_5 . V_513 . V_50 && ! V_2 -> V_5 . V_513 . V_514 ;
V_510 -> V_513 . V_16 = V_2 -> V_5 . V_513 . V_16 ;
V_510 -> V_513 . V_514 = 0 ;
V_510 -> V_513 . V_515 =
V_56 -> V_516 ( V_2 ,
V_517 | V_518 ) ;
V_510 -> V_519 . V_511 = V_2 -> V_5 . V_520 ;
V_510 -> V_519 . V_50 = V_2 -> V_5 . V_521 != 0 ;
V_510 -> V_519 . V_522 = V_56 -> V_523 ( V_2 ) ;
V_510 -> V_519 . V_512 = 0 ;
V_510 -> V_524 = V_2 -> V_5 . V_524 ;
V_510 -> V_222 = ( V_525
| V_526
| V_527 ) ;
memset ( & V_510 -> V_528 , 0 , sizeof( V_510 -> V_528 ) ) ;
}
static int F_214 ( struct V_1 * V_2 ,
struct V_509 * V_510 )
{
if ( V_510 -> V_222 & ~ ( V_525
| V_526
| V_527 ) )
return - V_477 ;
F_212 ( V_2 ) ;
V_2 -> V_5 . V_49 . V_50 = V_510 -> V_49 . V_511 ;
V_2 -> V_5 . V_49 . V_16 = V_510 -> V_49 . V_16 ;
V_2 -> V_5 . V_49 . V_52 = V_510 -> V_49 . V_52 ;
V_2 -> V_5 . V_49 . V_43 = V_510 -> V_49 . V_43 ;
V_2 -> V_5 . V_513 . V_50 = V_510 -> V_513 . V_511 ;
V_2 -> V_5 . V_513 . V_16 = V_510 -> V_513 . V_16 ;
V_2 -> V_5 . V_513 . V_514 = V_510 -> V_513 . V_514 ;
if ( V_510 -> V_222 & V_527 )
V_56 -> V_529 ( V_2 ,
V_510 -> V_513 . V_515 ) ;
V_2 -> V_5 . V_520 = V_510 -> V_519 . V_511 ;
if ( V_510 -> V_222 & V_525 )
V_2 -> V_5 . V_521 = V_510 -> V_519 . V_50 ;
V_56 -> V_530 ( V_2 , V_510 -> V_519 . V_522 ) ;
if ( V_510 -> V_222 & V_526 )
V_2 -> V_5 . V_524 = V_510 -> V_524 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
static void F_215 ( struct V_1 * V_2 ,
struct V_531 * V_532 )
{
memcpy ( V_532 -> V_146 , V_2 -> V_5 . V_146 , sizeof( V_2 -> V_5 . V_146 ) ) ;
V_532 -> V_151 = V_2 -> V_5 . V_151 ;
V_532 -> V_154 = V_2 -> V_5 . V_154 ;
V_532 -> V_222 = 0 ;
memset ( & V_532 -> V_528 , 0 , sizeof( V_532 -> V_528 ) ) ;
}
static int F_216 ( struct V_1 * V_2 ,
struct V_531 * V_532 )
{
if ( V_532 -> V_222 )
return - V_477 ;
memcpy ( V_2 -> V_5 . V_146 , V_532 -> V_146 , sizeof( V_2 -> V_5 . V_146 ) ) ;
V_2 -> V_5 . V_151 = V_532 -> V_151 ;
V_2 -> V_5 . V_154 = V_532 -> V_154 ;
return 0 ;
}
static void F_217 ( struct V_1 * V_2 ,
struct V_533 * V_534 )
{
if ( V_452 )
memcpy ( V_534 -> V_535 ,
& V_2 -> V_5 . V_536 . V_537 -> V_538 ,
V_539 ) ;
else {
memcpy ( V_534 -> V_535 ,
& V_2 -> V_5 . V_536 . V_537 -> V_540 ,
sizeof( struct V_541 ) ) ;
* ( T_2 * ) & V_534 -> V_535 [ V_542 / sizeof( T_1 ) ] =
V_543 ;
}
}
static int F_218 ( struct V_1 * V_2 ,
struct V_533 * V_534 )
{
T_2 V_544 =
* ( T_2 * ) & V_534 -> V_535 [ V_542 / sizeof( T_1 ) ] ;
if ( V_452 )
memcpy ( & V_2 -> V_5 . V_536 . V_537 -> V_538 ,
V_534 -> V_535 , V_539 ) ;
else {
if ( V_544 & ~ V_543 )
return - V_477 ;
memcpy ( & V_2 -> V_5 . V_536 . V_537 -> V_540 ,
V_534 -> V_535 , sizeof( struct V_541 ) ) ;
}
return 0 ;
}
static void F_219 ( struct V_1 * V_2 ,
struct V_545 * V_546 )
{
if ( ! V_452 ) {
V_546 -> V_547 = 0 ;
return;
}
V_546 -> V_547 = 1 ;
V_546 -> V_222 = 0 ;
V_546 -> V_548 [ 0 ] . V_118 = V_120 ;
V_546 -> V_548 [ 0 ] . V_23 = V_2 -> V_5 . V_119 ;
}
static int F_220 ( struct V_1 * V_2 ,
struct V_545 * V_546 )
{
int V_3 , V_99 = 0 ;
if ( ! V_452 )
return - V_477 ;
if ( V_546 -> V_547 > V_549 || V_546 -> V_222 )
return - V_477 ;
for ( V_3 = 0 ; V_3 < V_546 -> V_547 ; V_3 ++ )
if ( V_546 -> V_548 [ 0 ] . V_118 == V_120 ) {
V_99 = F_58 ( V_2 , V_120 ,
V_546 -> V_548 [ 0 ] . V_23 ) ;
break;
}
if ( V_99 )
V_99 = - V_477 ;
return V_99 ;
}
long F_221 ( struct V_457 * V_458 ,
unsigned int V_459 , unsigned long V_460 )
{
struct V_1 * V_2 = V_458 -> V_550 ;
void V_308 * V_461 = ( void V_308 * ) V_460 ;
int V_99 ;
union {
struct V_487 * V_551 ;
struct V_533 * V_538 ;
struct V_545 * V_548 ;
void * V_552 ;
} V_553 ;
V_553 . V_552 = NULL ;
switch ( V_459 ) {
case V_554 : {
V_99 = - V_477 ;
if ( ! V_2 -> V_5 . V_490 )
goto V_93;
V_553 . V_551 = F_222 ( sizeof( struct V_487 ) , V_555 ) ;
V_99 = - V_297 ;
if ( ! V_553 . V_551 )
goto V_93;
V_99 = F_201 ( V_2 , V_553 . V_551 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_186 ( V_461 , V_553 . V_551 , sizeof( struct V_487 ) ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_556 : {
V_99 = - V_477 ;
if ( ! V_2 -> V_5 . V_490 )
goto V_93;
V_553 . V_551 = F_133 ( V_461 , sizeof( * V_553 . V_551 ) ) ;
if ( F_134 ( V_553 . V_551 ) ) {
V_99 = F_135 ( V_553 . V_551 ) ;
goto V_93;
}
V_99 = F_202 ( V_2 , V_553 . V_551 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_557 : {
struct V_491 V_492 ;
V_99 = - V_81 ;
if ( F_185 ( & V_492 , V_461 , sizeof V_492 ) )
goto V_93;
V_99 = F_205 ( V_2 , & V_492 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_558 : {
V_99 = F_207 ( V_2 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_559 : {
struct V_560 V_308 * V_472 = V_461 ;
struct V_560 V_473 ;
V_99 = - V_81 ;
if ( F_185 ( & V_473 , V_472 , sizeof V_473 ) )
goto V_93;
V_99 = F_223 ( V_2 , & V_473 , V_472 -> V_397 ) ;
if ( V_99 )
goto V_93;
break;
}
case V_561 : {
struct V_471 V_308 * V_472 = V_461 ;
struct V_471 V_473 ;
V_99 = - V_81 ;
if ( F_185 ( & V_473 , V_472 , sizeof V_473 ) )
goto V_93;
V_99 = F_224 ( V_2 , & V_473 ,
V_472 -> V_397 ) ;
if ( V_99 )
goto V_93;
break;
}
case V_562 : {
struct V_471 V_308 * V_472 = V_461 ;
struct V_471 V_473 ;
V_99 = - V_81 ;
if ( F_185 ( & V_473 , V_472 , sizeof V_473 ) )
goto V_93;
V_99 = F_225 ( V_2 , & V_473 ,
V_472 -> V_397 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_186 ( V_472 , & V_473 , sizeof V_473 ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_563 :
V_99 = F_184 ( V_2 , V_461 , F_169 , 1 ) ;
break;
case V_564 :
V_99 = F_184 ( V_2 , V_461 , F_89 , 0 ) ;
break;
case V_565 : {
struct V_494 V_495 ;
V_99 = - V_81 ;
if ( F_185 ( & V_495 , V_461 , sizeof V_495 ) )
goto V_93;
V_99 = F_208 ( V_2 , & V_495 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_186 ( V_461 , & V_495 , sizeof V_495 ) )
goto V_93;
V_99 = 0 ;
break;
} ;
case V_566 : {
struct V_567 V_568 ;
V_99 = - V_477 ;
if ( ! F_18 ( V_2 -> V_29 ) )
goto V_93;
V_99 = - V_81 ;
if ( F_185 ( & V_568 , V_461 , sizeof V_568 ) )
goto V_93;
V_99 = 0 ;
F_226 ( V_2 , V_568 . V_569 ) ;
break;
}
case V_570 : {
T_2 V_276 ;
V_99 = - V_81 ;
if ( F_185 ( & V_276 , V_461 , sizeof V_276 ) )
goto V_93;
V_99 = F_209 ( V_2 , V_276 ) ;
break;
}
case V_571 : {
struct V_498 V_499 ;
V_99 = - V_81 ;
if ( F_185 ( & V_499 , V_461 , sizeof V_499 ) )
goto V_93;
V_99 = F_210 ( V_2 , & V_499 ) ;
break;
}
case V_572 : {
struct V_509 V_510 ;
F_211 ( V_2 , & V_510 ) ;
V_99 = - V_81 ;
if ( F_186 ( V_461 , & V_510 , sizeof( struct V_509 ) ) )
break;
V_99 = 0 ;
break;
}
case V_573 : {
struct V_509 V_510 ;
V_99 = - V_81 ;
if ( F_185 ( & V_510 , V_461 , sizeof( struct V_509 ) ) )
break;
V_99 = F_214 ( V_2 , & V_510 ) ;
break;
}
case V_574 : {
struct V_531 V_532 ;
F_215 ( V_2 , & V_532 ) ;
V_99 = - V_81 ;
if ( F_186 ( V_461 , & V_532 ,
sizeof( struct V_531 ) ) )
break;
V_99 = 0 ;
break;
}
case V_575 : {
struct V_531 V_532 ;
V_99 = - V_81 ;
if ( F_185 ( & V_532 , V_461 ,
sizeof( struct V_531 ) ) )
break;
V_99 = F_216 ( V_2 , & V_532 ) ;
break;
}
case V_576 : {
V_553 . V_538 = F_222 ( sizeof( struct V_533 ) , V_555 ) ;
V_99 = - V_297 ;
if ( ! V_553 . V_538 )
break;
F_217 ( V_2 , V_553 . V_538 ) ;
V_99 = - V_81 ;
if ( F_186 ( V_461 , V_553 . V_538 , sizeof( struct V_533 ) ) )
break;
V_99 = 0 ;
break;
}
case V_577 : {
V_553 . V_538 = F_133 ( V_461 , sizeof( * V_553 . V_538 ) ) ;
if ( F_134 ( V_553 . V_538 ) ) {
V_99 = F_135 ( V_553 . V_538 ) ;
goto V_93;
}
V_99 = F_218 ( V_2 , V_553 . V_538 ) ;
break;
}
case V_578 : {
V_553 . V_548 = F_222 ( sizeof( struct V_545 ) , V_555 ) ;
V_99 = - V_297 ;
if ( ! V_553 . V_548 )
break;
F_219 ( V_2 , V_553 . V_548 ) ;
V_99 = - V_81 ;
if ( F_186 ( V_461 , V_553 . V_548 ,
sizeof( struct V_545 ) ) )
break;
V_99 = 0 ;
break;
}
case V_579 : {
V_553 . V_548 = F_133 ( V_461 , sizeof( * V_553 . V_548 ) ) ;
if ( F_134 ( V_553 . V_548 ) ) {
V_99 = F_135 ( V_553 . V_548 ) ;
goto V_93;
}
V_99 = F_220 ( V_2 , V_553 . V_548 ) ;
break;
}
case V_580 : {
T_1 V_581 ;
V_99 = - V_477 ;
if ( ! V_454 )
break;
V_581 = ( T_1 ) V_460 ;
if ( V_581 >= V_582 )
goto V_93;
V_56 -> V_583 ( V_2 , V_581 ) ;
V_99 = 0 ;
goto V_93;
}
case V_584 : {
V_99 = - V_585 ;
if ( F_118 () )
goto V_93;
V_99 = F_108 ( V_2 ) ;
goto V_93;
}
default:
V_99 = - V_477 ;
}
V_93:
F_136 ( V_553 . V_552 ) ;
return V_99 ;
}
static int F_227 ( struct V_29 * V_29 , unsigned long V_304 )
{
int V_88 ;
if ( V_304 > ( unsigned int ) ( - 3 * V_87 ) )
return - 1 ;
V_88 = V_56 -> V_586 ( V_29 , V_304 ) ;
return V_88 ;
}
static int F_228 ( struct V_29 * V_29 ,
T_2 V_587 )
{
V_29 -> V_5 . V_588 = V_587 ;
return 0 ;
}
static int F_229 ( struct V_29 * V_29 ,
T_1 V_589 )
{
if ( V_589 < V_590 )
return - V_477 ;
F_167 ( & V_29 -> V_591 ) ;
F_230 ( & V_29 -> V_592 ) ;
F_231 ( V_29 , V_589 ) ;
V_29 -> V_5 . V_593 = V_589 ;
F_232 ( & V_29 -> V_592 ) ;
F_168 ( & V_29 -> V_591 ) ;
return 0 ;
}
static int F_233 ( struct V_29 * V_29 )
{
return V_29 -> V_5 . V_594 ;
}
static int F_234 ( struct V_29 * V_29 , struct V_595 * V_596 )
{
int V_99 ;
V_99 = 0 ;
switch ( V_596 -> V_597 ) {
case V_598 :
memcpy ( & V_596 -> V_596 . V_599 ,
& F_235 ( V_29 ) -> V_600 [ 0 ] ,
sizeof( struct V_601 ) ) ;
break;
case V_602 :
memcpy ( & V_596 -> V_596 . V_599 ,
& F_235 ( V_29 ) -> V_600 [ 1 ] ,
sizeof( struct V_601 ) ) ;
break;
case V_603 :
V_99 = F_236 ( V_29 , & V_596 -> V_596 . V_604 ) ;
break;
default:
V_99 = - V_477 ;
break;
}
return V_99 ;
}
static int F_237 ( struct V_29 * V_29 , struct V_595 * V_596 )
{
int V_99 ;
V_99 = 0 ;
switch ( V_596 -> V_597 ) {
case V_598 :
F_230 ( & F_235 ( V_29 ) -> V_375 ) ;
memcpy ( & F_235 ( V_29 ) -> V_600 [ 0 ] ,
& V_596 -> V_596 . V_599 ,
sizeof( struct V_601 ) ) ;
F_232 ( & F_235 ( V_29 ) -> V_375 ) ;
break;
case V_602 :
F_230 ( & F_235 ( V_29 ) -> V_375 ) ;
memcpy ( & F_235 ( V_29 ) -> V_600 [ 1 ] ,
& V_596 -> V_596 . V_599 ,
sizeof( struct V_601 ) ) ;
F_232 ( & F_235 ( V_29 ) -> V_375 ) ;
break;
case V_603 :
V_99 = F_238 ( V_29 , & V_596 -> V_596 . V_604 ) ;
break;
default:
V_99 = - V_477 ;
break;
}
F_239 ( F_235 ( V_29 ) ) ;
return V_99 ;
}
static int F_240 ( struct V_29 * V_29 , struct V_605 * V_606 )
{
int V_99 = 0 ;
F_167 ( & V_29 -> V_5 . V_607 -> V_608 . V_375 ) ;
memcpy ( V_606 , & V_29 -> V_5 . V_607 -> V_608 , sizeof( struct V_605 ) ) ;
F_168 ( & V_29 -> V_5 . V_607 -> V_608 . V_375 ) ;
return V_99 ;
}
static int F_241 ( struct V_29 * V_29 , struct V_605 * V_606 )
{
int V_99 = 0 ;
F_167 ( & V_29 -> V_5 . V_607 -> V_608 . V_375 ) ;
memcpy ( & V_29 -> V_5 . V_607 -> V_608 , V_606 , sizeof( struct V_605 ) ) ;
F_242 ( V_29 , 0 , V_606 -> V_609 [ 0 ] . V_610 , 0 ) ;
F_168 ( & V_29 -> V_5 . V_607 -> V_608 . V_375 ) ;
return V_99 ;
}
static int F_243 ( struct V_29 * V_29 , struct V_611 * V_606 )
{
int V_99 = 0 ;
F_167 ( & V_29 -> V_5 . V_607 -> V_608 . V_375 ) ;
memcpy ( V_606 -> V_609 , & V_29 -> V_5 . V_607 -> V_608 . V_609 ,
sizeof( V_606 -> V_609 ) ) ;
V_606 -> V_222 = V_29 -> V_5 . V_607 -> V_608 . V_222 ;
F_168 ( & V_29 -> V_5 . V_607 -> V_608 . V_375 ) ;
memset ( & V_606 -> V_528 , 0 , sizeof( V_606 -> V_528 ) ) ;
return V_99 ;
}
static int F_244 ( struct V_29 * V_29 , struct V_611 * V_606 )
{
int V_99 = 0 , V_612 = 0 ;
T_1 V_613 , V_614 ;
F_167 ( & V_29 -> V_5 . V_607 -> V_608 . V_375 ) ;
V_613 = V_29 -> V_5 . V_607 -> V_608 . V_222 & V_615 ;
V_614 = V_606 -> V_222 & V_615 ;
if ( ! V_613 && V_614 )
V_612 = 1 ;
memcpy ( & V_29 -> V_5 . V_607 -> V_608 . V_609 , & V_606 -> V_609 ,
sizeof( V_29 -> V_5 . V_607 -> V_608 . V_609 ) ) ;
V_29 -> V_5 . V_607 -> V_608 . V_222 = V_606 -> V_222 ;
F_242 ( V_29 , 0 , V_29 -> V_5 . V_607 -> V_608 . V_609 [ 0 ] . V_610 , V_612 ) ;
F_168 ( & V_29 -> V_5 . V_607 -> V_608 . V_375 ) ;
return V_99 ;
}
static int F_245 ( struct V_29 * V_29 ,
struct V_616 * V_617 )
{
if ( ! V_29 -> V_5 . V_607 )
return - V_493 ;
F_167 ( & V_29 -> V_5 . V_607 -> V_608 . V_375 ) ;
V_29 -> V_5 . V_607 -> V_608 . V_618 . V_44 = V_617 -> V_619 ;
F_168 ( & V_29 -> V_5 . V_607 -> V_608 . V_375 ) ;
return 0 ;
}
static void F_246 ( struct V_29 * V_29 ,
struct V_620 * V_621 ,
unsigned long * V_622 ,
unsigned long V_623 )
{
if ( V_623 < V_29 -> V_5 . V_624 ) {
unsigned long V_625 ;
F_247 (gfn_offset, dirty_bitmap, memslot->npages) {
unsigned long V_82 = V_621 -> V_626 + V_625 ;
F_230 ( & V_29 -> V_592 ) ;
F_248 ( V_29 , V_82 , V_621 ) ;
F_232 ( & V_29 -> V_592 ) ;
}
F_249 ( V_29 ) ;
} else {
F_230 ( & V_29 -> V_592 ) ;
F_250 ( V_29 , V_621 -> V_627 ) ;
F_232 ( & V_29 -> V_592 ) ;
}
}
int F_251 ( struct V_29 * V_29 ,
struct V_628 * log )
{
int V_99 ;
struct V_620 * V_621 ;
unsigned long V_402 , V_623 ;
F_167 ( & V_29 -> V_591 ) ;
V_99 = - V_477 ;
if ( log -> V_10 >= V_446 )
goto V_93;
V_621 = F_252 ( V_29 -> V_629 , log -> V_10 ) ;
V_99 = - V_630 ;
if ( ! V_621 -> V_622 )
goto V_93;
V_402 = F_253 ( V_621 ) ;
V_623 = V_621 -> V_623 ;
if ( V_623 ) {
struct V_631 * V_632 , * V_633 ;
unsigned long * V_622 , * V_634 ;
V_622 = V_621 -> V_622 ;
V_634 = V_621 -> V_634 ;
if ( V_622 == V_634 )
V_634 += V_402 / sizeof( long ) ;
memset ( V_634 , 0 , V_402 ) ;
V_99 = - V_297 ;
V_632 = F_254 ( V_29 -> V_629 , sizeof( * V_29 -> V_629 ) , V_555 ) ;
if ( ! V_632 )
goto V_93;
V_621 = F_252 ( V_632 , log -> V_10 ) ;
V_621 -> V_623 = 0 ;
V_621 -> V_622 = V_634 ;
F_255 ( V_632 , NULL ) ;
V_633 = V_29 -> V_629 ;
F_256 ( V_29 -> V_629 , V_632 ) ;
F_257 ( & V_29 -> V_398 ) ;
F_136 ( V_633 ) ;
F_246 ( V_29 , V_621 , V_622 , V_623 ) ;
V_99 = - V_81 ;
if ( F_186 ( log -> V_622 , V_622 , V_402 ) )
goto V_93;
} else {
V_99 = - V_81 ;
if ( F_258 ( log -> V_622 , V_402 ) )
goto V_93;
}
V_99 = 0 ;
V_93:
F_168 ( & V_29 -> V_591 ) ;
return V_99 ;
}
long F_259 ( struct V_457 * V_458 ,
unsigned int V_459 , unsigned long V_460 )
{
struct V_29 * V_29 = V_458 -> V_550 ;
void V_308 * V_461 = ( void V_308 * ) V_460 ;
int V_99 = - V_635 ;
union {
struct V_605 V_606 ;
struct V_611 V_636 ;
struct V_637 V_638 ;
} V_553 ;
switch ( V_459 ) {
case V_639 :
V_99 = F_227 ( V_29 , V_460 ) ;
if ( V_99 < 0 )
goto V_93;
break;
case V_640 : {
T_2 V_587 ;
V_99 = - V_81 ;
if ( F_185 ( & V_587 , V_461 , sizeof V_587 ) )
goto V_93;
V_99 = F_228 ( V_29 , V_587 ) ;
if ( V_99 < 0 )
goto V_93;
break;
}
case V_641 :
V_99 = F_229 ( V_29 , V_460 ) ;
if ( V_99 )
goto V_93;
break;
case V_642 :
V_99 = F_233 ( V_29 ) ;
break;
case V_643 : {
struct V_644 * V_645 ;
F_167 ( & V_29 -> V_375 ) ;
V_99 = - V_646 ;
if ( V_29 -> V_5 . V_645 )
goto V_647;
V_99 = - V_297 ;
V_645 = F_260 ( V_29 ) ;
if ( V_645 ) {
V_99 = F_261 ( V_29 ) ;
if ( V_99 ) {
F_167 ( & V_29 -> V_591 ) ;
F_262 ( V_29 , V_648 ,
& V_645 -> V_649 ) ;
F_262 ( V_29 , V_648 ,
& V_645 -> V_650 ) ;
F_262 ( V_29 , V_648 ,
& V_645 -> V_651 ) ;
F_168 ( & V_29 -> V_591 ) ;
F_136 ( V_645 ) ;
goto V_647;
}
} else
goto V_647;
F_12 () ;
V_29 -> V_5 . V_645 = V_645 ;
F_12 () ;
V_99 = F_263 ( V_29 ) ;
if ( V_99 ) {
F_167 ( & V_29 -> V_591 ) ;
F_167 ( & V_29 -> V_652 ) ;
F_264 ( V_29 ) ;
F_265 ( V_29 ) ;
F_168 ( & V_29 -> V_652 ) ;
F_168 ( & V_29 -> V_591 ) ;
}
V_647:
F_168 ( & V_29 -> V_375 ) ;
break;
}
case V_653 :
V_553 . V_638 . V_222 = V_654 ;
goto V_655;
case V_656 :
V_99 = - V_81 ;
if ( F_185 ( & V_553 . V_638 , V_461 ,
sizeof( struct V_637 ) ) )
goto V_93;
V_655:
F_167 ( & V_29 -> V_591 ) ;
V_99 = - V_646 ;
if ( V_29 -> V_5 . V_607 )
goto V_657;
V_99 = - V_297 ;
V_29 -> V_5 . V_607 = F_266 ( V_29 , V_553 . V_638 . V_222 ) ;
if ( V_29 -> V_5 . V_607 )
V_99 = 0 ;
V_657:
F_168 ( & V_29 -> V_591 ) ;
break;
case V_658 :
case V_659 : {
struct V_660 V_661 ;
V_99 = - V_81 ;
if ( F_185 ( & V_661 , V_461 , sizeof V_661 ) )
goto V_93;
V_99 = - V_493 ;
if ( F_18 ( V_29 ) ) {
T_11 V_501 ;
V_501 = F_267 ( V_29 , V_662 ,
V_661 . V_492 , V_661 . V_663 ) ;
if ( V_459 == V_658 ) {
V_99 = - V_81 ;
V_661 . V_501 = V_501 ;
if ( F_186 ( V_461 , & V_661 ,
sizeof V_661 ) )
goto V_93;
}
V_99 = 0 ;
}
break;
}
case V_664 : {
struct V_595 * V_596 ;
V_596 = F_133 ( V_461 , sizeof( * V_596 ) ) ;
if ( F_134 ( V_596 ) ) {
V_99 = F_135 ( V_596 ) ;
goto V_93;
}
V_99 = - V_493 ;
if ( ! F_18 ( V_29 ) )
goto V_665;
V_99 = F_234 ( V_29 , V_596 ) ;
if ( V_99 )
goto V_665;
V_99 = - V_81 ;
if ( F_186 ( V_461 , V_596 , sizeof *V_596 ) )
goto V_665;
V_99 = 0 ;
V_665:
F_136 ( V_596 ) ;
if ( V_99 )
goto V_93;
break;
}
case V_666 : {
struct V_595 * V_596 ;
V_596 = F_133 ( V_461 , sizeof( * V_596 ) ) ;
if ( F_134 ( V_596 ) ) {
V_99 = F_135 ( V_596 ) ;
goto V_93;
}
V_99 = - V_493 ;
if ( ! F_18 ( V_29 ) )
goto V_667;
V_99 = F_237 ( V_29 , V_596 ) ;
if ( V_99 )
goto V_667;
V_99 = 0 ;
V_667:
F_136 ( V_596 ) ;
if ( V_99 )
goto V_93;
break;
}
case V_668 : {
V_99 = - V_81 ;
if ( F_185 ( & V_553 . V_606 , V_461 , sizeof( struct V_605 ) ) )
goto V_93;
V_99 = - V_493 ;
if ( ! V_29 -> V_5 . V_607 )
goto V_93;
V_99 = F_240 ( V_29 , & V_553 . V_606 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_186 ( V_461 , & V_553 . V_606 , sizeof( struct V_605 ) ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_669 : {
V_99 = - V_81 ;
if ( F_185 ( & V_553 . V_606 , V_461 , sizeof V_553 . V_606 ) )
goto V_93;
V_99 = - V_493 ;
if ( ! V_29 -> V_5 . V_607 )
goto V_93;
V_99 = F_241 ( V_29 , & V_553 . V_606 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_670 : {
V_99 = - V_493 ;
if ( ! V_29 -> V_5 . V_607 )
goto V_93;
V_99 = F_243 ( V_29 , & V_553 . V_636 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_186 ( V_461 , & V_553 . V_636 , sizeof( V_553 . V_636 ) ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_671 : {
V_99 = - V_81 ;
if ( F_185 ( & V_553 . V_636 , V_461 , sizeof( V_553 . V_636 ) ) )
goto V_93;
V_99 = - V_493 ;
if ( ! V_29 -> V_5 . V_607 )
goto V_93;
V_99 = F_244 ( V_29 , & V_553 . V_636 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_672 : {
struct V_616 V_617 ;
V_99 = - V_81 ;
if ( F_185 ( & V_617 , V_461 , sizeof( V_617 ) ) )
goto V_93;
V_99 = F_245 ( V_29 , & V_617 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_673 : {
V_99 = - V_81 ;
if ( F_185 ( & V_29 -> V_5 . F_132 , V_461 ,
sizeof( struct V_674 ) ) )
goto V_93;
V_99 = - V_477 ;
if ( V_29 -> V_5 . F_132 . V_222 )
goto V_93;
V_99 = 0 ;
break;
}
case V_675 : {
struct V_676 V_677 ;
T_2 V_678 ;
T_9 V_227 ;
V_99 = - V_81 ;
if ( F_185 ( & V_677 , V_461 , sizeof( V_677 ) ) )
goto V_93;
V_99 = - V_477 ;
if ( V_677 . V_222 )
goto V_93;
V_99 = 0 ;
F_268 () ;
V_678 = F_97 () ;
V_227 = V_677 . clock - V_678 ;
F_269 () ;
V_29 -> V_5 . V_246 = V_227 ;
break;
}
case V_679 : {
struct V_676 V_677 ;
T_2 V_678 ;
F_268 () ;
V_678 = F_97 () ;
V_677 . clock = V_29 -> V_5 . V_246 + V_678 ;
F_269 () ;
V_677 . V_222 = 0 ;
memset ( & V_677 . V_512 , 0 , sizeof( V_677 . V_512 ) ) ;
V_99 = - V_81 ;
if ( F_186 ( V_461 , & V_677 , sizeof( V_677 ) ) )
goto V_93;
V_99 = 0 ;
break;
}
default:
;
}
V_93:
return V_99 ;
}
static void F_270 ( void )
{
T_1 V_680 [ 2 ] ;
unsigned V_3 , V_681 ;
for ( V_3 = V_681 = V_682 ; V_3 < F_42 ( V_469 ) ; V_3 ++ ) {
if ( F_271 ( V_469 [ V_3 ] , & V_680 [ 0 ] , & V_680 [ 1 ] ) < 0 )
continue;
if ( V_681 < V_3 )
V_469 [ V_681 ] = V_469 [ V_3 ] ;
V_681 ++ ;
}
V_466 = V_681 ;
}
static int F_272 ( struct V_1 * V_2 , T_4 V_304 , int V_75 ,
const void * V_231 )
{
int V_683 = 0 ;
int V_402 ;
do {
V_402 = F_273 ( V_75 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_490 &&
! F_274 ( & V_2 -> V_5 . V_490 -> V_684 , V_304 , V_402 , V_231 ) )
&& F_275 ( V_2 -> V_29 , V_685 , V_304 , V_402 , V_231 ) )
break;
V_683 += V_402 ;
V_304 += V_402 ;
V_75 -= V_402 ;
V_231 += V_402 ;
} while ( V_75 );
return V_683 ;
}
static int F_276 ( struct V_1 * V_2 , T_4 V_304 , int V_75 , void * V_231 )
{
int V_683 = 0 ;
int V_402 ;
do {
V_402 = F_273 ( V_75 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_490 &&
! F_277 ( & V_2 -> V_5 . V_490 -> V_684 , V_304 , V_402 , V_231 ) )
&& F_278 ( V_2 -> V_29 , V_685 , V_304 , V_402 , V_231 ) )
break;
F_279 ( V_686 , V_402 , V_304 , * ( T_2 * ) V_231 ) ;
V_683 += V_402 ;
V_304 += V_402 ;
V_75 -= V_402 ;
V_231 += V_402 ;
} while ( V_75 );
return V_683 ;
}
static void F_280 ( struct V_1 * V_2 ,
struct V_687 * V_688 , int V_689 )
{
V_56 -> V_690 ( V_2 , V_688 , V_689 ) ;
}
void F_281 ( struct V_1 * V_2 ,
struct V_687 * V_688 , int V_689 )
{
V_56 -> V_691 ( V_2 , V_688 , V_689 ) ;
}
T_4 F_282 ( struct V_1 * V_2 , T_4 V_319 , T_1 V_76 )
{
T_4 V_692 ;
struct V_58 V_49 ;
F_283 ( ! F_31 ( V_2 ) ) ;
V_76 |= V_91 ;
V_692 = V_2 -> V_5 . V_67 . V_693 ( V_2 , V_319 , V_76 , & V_49 ) ;
return V_692 ;
}
T_4 F_284 ( struct V_1 * V_2 , T_12 V_694 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
return V_2 -> V_5 . V_83 -> V_693 ( V_2 , V_694 , V_76 , V_49 ) ;
}
T_4 F_285 ( struct V_1 * V_2 , T_12 V_694 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
V_76 |= V_695 ;
return V_2 -> V_5 . V_83 -> V_693 ( V_2 , V_694 , V_76 , V_49 ) ;
}
T_4 F_286 ( struct V_1 * V_2 , T_12 V_694 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
V_76 |= V_92 ;
return V_2 -> V_5 . V_83 -> V_693 ( V_2 , V_694 , V_76 , V_49 ) ;
}
T_4 F_287 ( struct V_1 * V_2 , T_12 V_694 ,
struct V_58 * V_49 )
{
return V_2 -> V_5 . V_83 -> V_693 ( V_2 , V_694 , 0 , V_49 ) ;
}
static int F_288 ( T_12 V_304 , void * V_145 , unsigned int V_696 ,
struct V_1 * V_2 , T_1 V_76 ,
struct V_58 * V_49 )
{
void * V_31 = V_145 ;
int V_99 = V_697 ;
while ( V_696 ) {
T_4 V_319 = V_2 -> V_5 . V_83 -> V_693 ( V_2 , V_304 , V_76 ,
V_49 ) ;
unsigned V_74 = V_304 & ( V_87 - 1 ) ;
unsigned V_698 = F_273 ( V_696 , ( unsigned ) V_87 - V_74 ) ;
int V_88 ;
if ( V_319 == V_80 )
return V_699 ;
V_88 = F_91 ( V_2 -> V_29 , V_319 , V_31 , V_698 ) ;
if ( V_88 < 0 ) {
V_99 = V_700 ;
goto V_93;
}
V_696 -= V_698 ;
V_31 += V_698 ;
V_304 += V_698 ;
}
V_93:
return V_99 ;
}
static int F_289 ( struct V_701 * V_702 ,
T_12 V_304 , void * V_145 , unsigned int V_696 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_290 ( V_702 ) ;
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
return F_288 ( V_304 , V_145 , V_696 , V_2 ,
V_76 | V_695 ,
V_49 ) ;
}
int F_291 ( struct V_701 * V_702 ,
T_12 V_304 , void * V_145 , unsigned int V_696 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_290 ( V_702 ) ;
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
return F_288 ( V_304 , V_145 , V_696 , V_2 , V_76 ,
V_49 ) ;
}
static int F_292 ( struct V_701 * V_702 ,
T_12 V_304 , void * V_145 , unsigned int V_696 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_290 ( V_702 ) ;
return F_288 ( V_304 , V_145 , V_696 , V_2 , 0 , V_49 ) ;
}
int F_293 ( struct V_701 * V_702 ,
T_12 V_304 , void * V_145 ,
unsigned int V_696 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_290 ( V_702 ) ;
void * V_31 = V_145 ;
int V_99 = V_697 ;
while ( V_696 ) {
T_4 V_319 = V_2 -> V_5 . V_83 -> V_693 ( V_2 , V_304 ,
V_92 ,
V_49 ) ;
unsigned V_74 = V_304 & ( V_87 - 1 ) ;
unsigned V_703 = F_273 ( V_696 , ( unsigned ) V_87 - V_74 ) ;
int V_88 ;
if ( V_319 == V_80 )
return V_699 ;
V_88 = F_92 ( V_2 -> V_29 , V_319 , V_31 , V_703 ) ;
if ( V_88 < 0 ) {
V_99 = V_700 ;
goto V_93;
}
V_696 -= V_703 ;
V_31 += V_703 ;
V_304 += V_703 ;
}
V_93:
return V_99 ;
}
static int F_294 ( struct V_1 * V_2 , unsigned long V_694 ,
T_4 * V_319 , struct V_58 * V_49 ,
bool V_704 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
if ( F_295 ( V_2 , V_694 ) &&
F_296 ( V_2 , V_704 , V_76 ,
V_2 -> V_5 . V_76 ) ) {
* V_319 = V_2 -> V_5 . V_705 << V_86 |
( V_694 & ( V_87 - 1 ) ) ;
F_297 ( V_694 , * V_319 , V_704 , false ) ;
return 1 ;
}
if ( V_704 )
V_76 |= V_92 ;
* V_319 = V_2 -> V_5 . V_83 -> V_693 ( V_2 , V_694 , V_76 , V_49 ) ;
if ( * V_319 == V_80 )
return - 1 ;
if ( ( * V_319 & V_293 ) == V_706 )
return 1 ;
if ( F_298 ( V_2 , * V_319 ) ) {
F_297 ( V_694 , * V_319 , V_704 , true ) ;
return 1 ;
}
return 0 ;
}
int F_299 ( struct V_1 * V_2 , T_4 V_319 ,
const void * V_145 , int V_696 )
{
int V_88 ;
V_88 = F_92 ( V_2 -> V_29 , V_319 , V_145 , V_696 ) ;
if ( V_88 < 0 )
return 0 ;
F_300 ( V_2 , V_319 , V_145 , V_696 ) ;
return 1 ;
}
static int F_301 ( struct V_1 * V_2 , void * V_145 , int V_696 )
{
if ( V_2 -> V_707 ) {
memcpy ( V_145 , V_2 -> V_708 , V_696 ) ;
F_279 ( V_686 , V_696 ,
V_2 -> V_709 , * ( T_2 * ) V_145 ) ;
V_2 -> V_707 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_302 ( struct V_1 * V_2 , T_4 V_319 ,
void * V_145 , int V_696 )
{
return ! F_91 ( V_2 -> V_29 , V_319 , V_145 , V_696 ) ;
}
static int F_303 ( struct V_1 * V_2 , T_4 V_319 ,
void * V_145 , int V_696 )
{
return F_299 ( V_2 , V_319 , V_145 , V_696 ) ;
}
static int F_304 ( struct V_1 * V_2 , T_4 V_319 , int V_696 , void * V_145 )
{
F_279 ( V_710 , V_696 , V_319 , * ( T_2 * ) V_145 ) ;
return F_272 ( V_2 , V_319 , V_696 , V_145 ) ;
}
static int F_305 ( struct V_1 * V_2 , T_4 V_319 ,
void * V_145 , int V_696 )
{
F_279 ( V_711 , V_696 , V_319 , 0 ) ;
return V_700 ;
}
static int F_306 ( struct V_1 * V_2 , T_4 V_319 ,
void * V_145 , int V_696 )
{
memcpy ( V_2 -> V_708 , V_145 , V_696 ) ;
memcpy ( V_2 -> V_712 -> V_713 . V_31 , V_2 -> V_708 , 8 ) ;
return V_697 ;
}
static int F_307 ( unsigned long V_304 , void * V_145 ,
unsigned int V_696 ,
struct V_58 * V_49 ,
struct V_1 * V_2 ,
struct V_714 * V_715 )
{
T_4 V_319 ;
int V_683 , V_88 ;
bool V_704 = V_715 -> V_704 ;
if ( V_715 -> V_716 &&
V_715 -> V_716 ( V_2 , V_145 , V_696 ) )
return V_697 ;
V_88 = F_294 ( V_2 , V_304 , & V_319 , V_49 , V_704 ) ;
if ( V_88 < 0 )
return V_699 ;
if ( V_88 )
goto V_713;
if ( V_715 -> V_717 ( V_2 , V_319 , V_145 , V_696 ) )
return V_697 ;
V_713:
V_683 = V_715 -> V_718 ( V_2 , V_319 , V_696 , V_145 ) ;
if ( V_683 == V_696 )
return V_697 ;
V_319 += V_683 ;
V_696 -= V_683 ;
V_145 += V_683 ;
V_2 -> V_719 = 1 ;
V_2 -> V_712 -> V_720 = V_721 ;
V_2 -> V_712 -> V_713 . V_722 = V_2 -> V_709 = V_319 ;
V_2 -> V_723 = V_696 ;
V_2 -> V_712 -> V_713 . V_75 = F_273 ( V_2 -> V_723 , 8 ) ;
V_2 -> V_712 -> V_713 . V_724 = V_2 -> V_725 = V_704 ;
V_2 -> V_726 = 0 ;
return V_715 -> V_727 ( V_2 , V_319 , V_145 , V_696 ) ;
}
int F_308 ( struct V_701 * V_702 , unsigned long V_304 ,
void * V_145 , unsigned int V_696 ,
struct V_58 * V_49 ,
struct V_714 * V_715 )
{
struct V_1 * V_2 = F_290 ( V_702 ) ;
if ( ( ( V_304 + V_696 - 1 ) ^ V_304 ) & V_293 ) {
int V_728 , V_729 ;
V_729 = - V_304 & ~ V_293 ;
V_728 = F_307 ( V_304 , V_145 , V_729 , V_49 ,
V_2 , V_715 ) ;
if ( V_728 != V_697 )
return V_728 ;
V_304 += V_729 ;
V_145 += V_729 ;
V_696 -= V_729 ;
}
return F_307 ( V_304 , V_145 , V_696 , V_49 ,
V_2 , V_715 ) ;
}
static int F_309 ( struct V_701 * V_702 ,
unsigned long V_304 ,
void * V_145 ,
unsigned int V_696 ,
struct V_58 * V_49 )
{
return F_308 ( V_702 , V_304 , V_145 , V_696 ,
V_49 , & V_730 ) ;
}
int F_310 ( struct V_701 * V_702 ,
unsigned long V_304 ,
const void * V_145 ,
unsigned int V_696 ,
struct V_58 * V_49 )
{
return F_308 ( V_702 , V_304 , ( void * ) V_145 , V_696 ,
V_49 , & V_731 ) ;
}
static int F_311 ( struct V_701 * V_702 ,
unsigned long V_304 ,
const void * V_732 ,
const void * V_733 ,
unsigned int V_696 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_290 ( V_702 ) ;
T_4 V_319 ;
struct V_295 * V_295 ;
char * V_734 ;
bool V_735 ;
if ( V_696 > 8 || ( V_696 & ( V_696 - 1 ) ) )
goto V_736;
V_319 = F_286 ( V_2 , V_304 , NULL ) ;
if ( V_319 == V_80 ||
( V_319 & V_293 ) == V_706 )
goto V_736;
if ( ( ( V_319 + V_696 - 1 ) & V_293 ) != ( V_319 & V_293 ) )
goto V_736;
V_295 = F_159 ( V_2 -> V_29 , V_319 >> V_86 ) ;
if ( F_160 ( V_295 ) ) {
F_161 ( V_295 ) ;
goto V_736;
}
V_734 = F_123 ( V_295 , V_247 ) ;
V_734 += F_312 ( V_319 ) ;
switch ( V_696 ) {
case 1 :
V_735 = F_313 ( T_10 , V_734 , V_732 , V_733 ) ;
break;
case 2 :
V_735 = F_313 ( V_737 , V_734 , V_732 , V_733 ) ;
break;
case 4 :
V_735 = F_313 ( T_1 , V_734 , V_732 , V_733 ) ;
break;
case 8 :
V_735 = F_314 ( V_734 , V_732 , V_733 ) ;
break;
default:
F_315 () ;
}
F_124 ( V_734 , V_247 ) ;
F_151 ( V_295 ) ;
if ( ! V_735 )
return V_738 ;
F_300 ( V_2 , V_319 , V_733 , V_696 ) ;
return V_697 ;
V_736:
F_111 ( V_210 L_21 ) ;
return F_310 ( V_702 , V_304 , V_733 , V_696 , V_49 ) ;
}
static int F_316 ( struct V_1 * V_2 , void * V_739 )
{
int V_99 ;
if ( V_2 -> V_5 . V_740 . V_741 )
V_99 = F_278 ( V_2 -> V_29 , V_648 , V_2 -> V_5 . V_740 . V_742 ,
V_2 -> V_5 . V_740 . V_403 , V_739 ) ;
else
V_99 = F_275 ( V_2 -> V_29 , V_648 ,
V_2 -> V_5 . V_740 . V_742 , V_2 -> V_5 . V_740 . V_403 ,
V_739 ) ;
return V_99 ;
}
static int F_317 ( struct V_1 * V_2 , int V_403 ,
unsigned short V_742 , void * V_145 ,
unsigned int V_610 , bool V_741 )
{
F_318 ( ! V_741 , V_742 , V_403 , V_610 ) ;
V_2 -> V_5 . V_740 . V_742 = V_742 ;
V_2 -> V_5 . V_740 . V_741 = V_741 ;
V_2 -> V_5 . V_740 . V_610 = V_610 ;
V_2 -> V_5 . V_740 . V_403 = V_403 ;
if ( ! F_316 ( V_2 , V_2 -> V_5 . V_743 ) ) {
V_2 -> V_5 . V_740 . V_610 = 0 ;
return 1 ;
}
V_2 -> V_712 -> V_720 = V_744 ;
V_2 -> V_712 -> V_745 . V_746 = V_741 ? V_747 : V_748 ;
V_2 -> V_712 -> V_745 . V_403 = V_403 ;
V_2 -> V_712 -> V_745 . V_749 = V_750 * V_87 ;
V_2 -> V_712 -> V_745 . V_610 = V_610 ;
V_2 -> V_712 -> V_745 . V_742 = V_742 ;
return 0 ;
}
static int F_319 ( struct V_701 * V_702 ,
int V_403 , unsigned short V_742 , void * V_145 ,
unsigned int V_610 )
{
struct V_1 * V_2 = F_290 ( V_702 ) ;
int V_88 ;
if ( V_2 -> V_5 . V_740 . V_610 )
goto V_751;
V_88 = F_317 ( V_2 , V_403 , V_742 , V_145 , V_610 , true ) ;
if ( V_88 ) {
V_751:
memcpy ( V_145 , V_2 -> V_5 . V_743 , V_403 * V_610 ) ;
V_2 -> V_5 . V_740 . V_610 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_320 ( struct V_701 * V_702 ,
int V_403 , unsigned short V_742 ,
const void * V_145 , unsigned int V_610 )
{
struct V_1 * V_2 = F_290 ( V_702 ) ;
memcpy ( V_2 -> V_5 . V_743 , V_145 , V_403 * V_610 ) ;
return F_317 ( V_2 , V_403 , V_742 , ( void * ) V_145 , V_610 , false ) ;
}
static unsigned long F_321 ( struct V_1 * V_2 , int V_689 )
{
return V_56 -> F_321 ( V_2 , V_689 ) ;
}
static void F_322 ( struct V_701 * V_702 , V_140 V_63 )
{
F_323 ( F_290 ( V_702 ) , V_63 ) ;
}
int F_324 ( struct V_1 * V_2 )
{
if ( ! F_193 ( V_2 ) )
return V_697 ;
if ( V_56 -> V_482 () ) {
int V_206 = F_104 () ;
F_195 ( V_206 , V_2 -> V_5 . V_483 ) ;
F_325 ( V_2 -> V_5 . V_483 ,
F_191 , NULL , 1 ) ;
F_107 () ;
F_326 ( V_2 -> V_5 . V_483 ) ;
} else
F_192 () ;
return V_697 ;
}
static void F_327 ( struct V_701 * V_702 )
{
F_324 ( F_290 ( V_702 ) ) ;
}
int F_328 ( struct V_701 * V_702 , int V_144 , unsigned long * V_752 )
{
return F_78 ( F_290 ( V_702 ) , V_144 , V_752 ) ;
}
int F_329 ( struct V_701 * V_702 , int V_144 , unsigned long V_23 )
{
return F_75 ( F_290 ( V_702 ) , V_144 , V_23 ) ;
}
static T_2 F_330 ( T_2 V_753 , T_1 V_754 )
{
return ( V_753 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_754 ;
}
static unsigned long F_331 ( struct V_701 * V_702 , int V_755 )
{
struct V_1 * V_2 = F_290 ( V_702 ) ;
unsigned long V_23 ;
switch ( V_755 ) {
case 0 :
V_23 = F_51 ( V_2 ) ;
break;
case 2 :
V_23 = V_2 -> V_5 . V_62 ;
break;
case 3 :
V_23 = F_49 ( V_2 ) ;
break;
case 4 :
V_23 = F_61 ( V_2 ) ;
break;
case 8 :
V_23 = F_73 ( V_2 ) ;
break;
default:
F_332 ( V_2 , L_22 , V_204 , V_755 ) ;
return 0 ;
}
return V_23 ;
}
static int F_333 ( struct V_701 * V_702 , int V_755 , V_140 V_145 )
{
struct V_1 * V_2 = F_290 ( V_702 ) ;
int V_160 = 0 ;
switch ( V_755 ) {
case 0 :
V_160 = F_50 ( V_2 , F_330 ( F_51 ( V_2 ) , V_145 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_62 = V_145 ;
break;
case 3 :
V_160 = F_66 ( V_2 , V_145 ) ;
break;
case 4 :
V_160 = F_60 ( V_2 , F_330 ( F_61 ( V_2 ) , V_145 ) ) ;
break;
case 8 :
V_160 = F_71 ( V_2 , V_145 ) ;
break;
default:
F_332 ( V_2 , L_22 , V_204 , V_755 ) ;
V_160 = - 1 ;
}
return V_160 ;
}
static int F_334 ( struct V_701 * V_702 )
{
return V_56 -> V_71 ( F_290 ( V_702 ) ) ;
}
static void F_335 ( struct V_701 * V_702 , struct V_756 * V_757 )
{
V_56 -> V_758 ( F_290 ( V_702 ) , V_757 ) ;
}
static void F_336 ( struct V_701 * V_702 , struct V_756 * V_757 )
{
V_56 -> V_759 ( F_290 ( V_702 ) , V_757 ) ;
}
static void F_337 ( struct V_701 * V_702 , struct V_756 * V_757 )
{
V_56 -> V_760 ( F_290 ( V_702 ) , V_757 ) ;
}
static void F_338 ( struct V_701 * V_702 , struct V_756 * V_757 )
{
V_56 -> V_761 ( F_290 ( V_702 ) , V_757 ) ;
}
static unsigned long F_339 (
struct V_701 * V_702 , int V_689 )
{
return F_321 ( F_290 ( V_702 ) , V_689 ) ;
}
static bool F_340 ( struct V_701 * V_702 , V_737 * V_762 ,
struct V_763 * V_764 , T_1 * V_765 ,
int V_689 )
{
struct V_687 V_688 ;
F_281 ( F_290 ( V_702 ) , & V_688 , V_689 ) ;
* V_762 = V_688 . V_762 ;
if ( V_688 . V_766 )
return false ;
if ( V_688 . V_767 )
V_688 . V_768 >>= 12 ;
F_341 ( V_764 , V_688 . V_768 ) ;
F_342 ( V_764 , ( unsigned long ) V_688 . V_769 ) ;
#ifdef F_52
if ( V_765 )
* V_765 = V_688 . V_769 >> 32 ;
#endif
V_764 -> type = V_688 . type ;
V_764 -> V_488 = V_688 . V_488 ;
V_764 -> V_770 = V_688 . V_770 ;
V_764 -> V_264 = V_688 . V_771 ;
V_764 -> V_772 = V_688 . V_772 ;
V_764 -> V_773 = V_688 . V_773 ;
V_764 -> V_774 = V_688 . V_146 ;
V_764 -> V_767 = V_688 . V_767 ;
return true ;
}
static void F_343 ( struct V_701 * V_702 , V_737 V_762 ,
struct V_763 * V_764 , T_1 V_765 ,
int V_689 )
{
struct V_1 * V_2 = F_290 ( V_702 ) ;
struct V_687 V_688 ;
V_688 . V_762 = V_762 ;
V_688 . V_769 = F_344 ( V_764 ) ;
#ifdef F_52
V_688 . V_769 |= ( ( T_2 ) V_765 ) << 32 ;
#endif
V_688 . V_768 = F_345 ( V_764 ) ;
if ( V_764 -> V_767 )
V_688 . V_768 = ( V_688 . V_768 << 12 ) | 0xfff ;
V_688 . type = V_764 -> type ;
V_688 . V_771 = V_764 -> V_264 ;
V_688 . V_770 = V_764 -> V_770 ;
V_688 . V_146 = V_764 -> V_774 ;
V_688 . V_488 = V_764 -> V_488 ;
V_688 . V_773 = V_764 -> V_773 ;
V_688 . V_767 = V_764 -> V_767 ;
V_688 . V_772 = V_764 -> V_772 ;
V_688 . V_771 = V_764 -> V_264 ;
V_688 . V_766 = ! V_688 . V_771 ;
V_688 . V_775 = 0 ;
F_280 ( V_2 , & V_688 , V_689 ) ;
return;
}
static int F_346 ( struct V_701 * V_702 ,
T_1 V_180 , T_2 * V_378 )
{
return F_169 ( F_290 ( V_702 ) , V_180 , V_378 ) ;
}
static int F_347 ( struct V_701 * V_702 ,
T_1 V_180 , T_2 V_31 )
{
return F_88 ( F_290 ( V_702 ) , V_180 , V_31 ) ;
}
static int F_348 ( struct V_701 * V_702 ,
T_1 V_776 , T_2 * V_378 )
{
return F_82 ( F_290 ( V_702 ) , V_776 , V_378 ) ;
}
static void F_349 ( struct V_701 * V_702 )
{
F_290 ( V_702 ) -> V_5 . V_777 = 1 ;
}
static void F_350 ( struct V_701 * V_702 )
{
F_163 () ;
F_351 ( F_290 ( V_702 ) ) ;
F_352 () ;
}
static void F_353 ( struct V_701 * V_702 )
{
F_164 () ;
}
static int F_354 ( struct V_701 * V_702 ,
struct V_778 * V_779 ,
enum V_780 V_781 )
{
return V_56 -> V_782 ( F_290 ( V_702 ) , V_779 , V_781 ) ;
}
static bool F_355 ( struct V_701 * V_702 ,
T_1 * V_783 , T_1 * V_784 , T_1 * V_162 , T_1 * V_171 )
{
struct V_169 * V_473 = NULL ;
if ( V_783 && V_162 )
V_473 = F_85 ( F_290 ( V_702 ) ,
* V_783 , * V_162 ) ;
if ( V_473 ) {
* V_783 = V_473 -> V_783 ;
* V_162 = V_473 -> V_162 ;
if ( V_784 )
* V_784 = V_473 -> V_784 ;
if ( V_171 )
* V_171 = V_473 -> V_171 ;
return true ;
}
return false ;
}
static void F_356 ( struct V_1 * V_2 )
{
F_81 ( V_2 , V_164 ) ;
F_81 ( V_2 , V_785 ) ;
F_81 ( V_2 , V_786 ) ;
V_2 -> V_5 . V_97 = ~ 0 ;
}
static void F_357 ( struct V_1 * V_2 , T_1 V_26 )
{
T_1 V_787 = V_56 -> V_516 ( V_2 , V_26 ) ;
if ( ! ( V_787 & V_26 ) )
V_56 -> V_529 ( V_2 , V_26 ) ;
}
static void F_358 ( struct V_1 * V_2 )
{
struct V_701 * V_702 = & V_2 -> V_5 . V_788 ;
if ( V_702 -> V_49 . V_32 == V_33 )
F_30 ( V_2 , & V_702 -> V_49 ) ;
else if ( V_702 -> V_49 . V_789 )
F_29 ( V_2 , V_702 -> V_49 . V_32 ,
V_702 -> V_49 . V_43 ) ;
else
F_24 ( V_2 , V_702 -> V_49 . V_32 ) ;
}
static void F_359 ( struct V_701 * V_702 ,
const unsigned long * V_489 )
{
memset ( & V_702 -> V_790 , 0 ,
( void * ) & V_702 -> V_489 - ( void * ) & V_702 -> V_790 ) ;
memcpy ( V_702 -> V_489 , V_489 , sizeof( V_702 -> V_489 ) ) ;
V_702 -> V_791 . V_612 = 0 ;
V_702 -> V_791 . V_792 = 0 ;
V_702 -> V_793 . V_794 = 0 ;
V_702 -> V_793 . V_792 = 0 ;
V_702 -> V_795 . V_794 = 0 ;
V_702 -> V_795 . V_792 = 0 ;
}
static void F_360 ( struct V_1 * V_2 )
{
struct V_701 * V_702 = & V_2 -> V_5 . V_788 ;
int V_112 , V_113 ;
F_356 ( V_2 ) ;
V_56 -> V_114 ( V_2 , & V_112 , & V_113 ) ;
V_702 -> V_796 = F_361 ( V_2 ) ;
V_702 -> V_797 = F_362 ( V_2 ) ;
V_702 -> V_798 = ( ! F_363 ( V_2 ) ) ? V_799 :
( V_702 -> V_796 & V_800 ) ? V_801 :
V_113 ? V_802 :
V_112 ? V_803 :
V_804 ;
V_702 -> V_805 = F_364 ( V_2 ) ;
F_359 ( V_702 , V_2 -> V_5 . V_489 ) ;
V_2 -> V_5 . V_806 = false ;
}
int F_365 ( struct V_1 * V_2 , int V_492 , int V_807 )
{
struct V_701 * V_702 = & V_2 -> V_5 . V_788 ;
int V_88 ;
F_360 ( V_2 ) ;
V_702 -> V_808 = 2 ;
V_702 -> V_809 = 2 ;
V_702 -> V_810 = V_702 -> V_797 + V_807 ;
V_88 = F_366 ( V_702 , V_492 ) ;
if ( V_88 != V_697 )
return V_811 ;
V_702 -> V_797 = V_702 -> V_810 ;
memcpy ( V_2 -> V_5 . V_489 , V_702 -> V_489 , sizeof V_702 -> V_489 ) ;
F_367 ( V_2 , V_702 -> V_797 ) ;
F_368 ( V_2 , V_702 -> V_796 ) ;
if ( V_492 == V_812 )
V_2 -> V_5 . V_521 = 0 ;
else
V_2 -> V_5 . V_513 . V_50 = false ;
return V_813 ;
}
static int F_369 ( struct V_1 * V_2 )
{
int V_99 = V_813 ;
++ V_2 -> V_60 . V_814 ;
F_370 ( V_2 ) ;
if ( ! F_364 ( V_2 ) ) {
V_2 -> V_712 -> V_720 = V_815 ;
V_2 -> V_712 -> V_816 . V_817 = V_818 ;
V_2 -> V_712 -> V_816 . V_819 = 0 ;
V_99 = V_811 ;
}
F_24 ( V_2 , V_161 ) ;
return V_99 ;
}
static bool F_371 ( struct V_1 * V_2 , T_12 V_694 )
{
T_4 V_319 ;
if ( V_179 )
return false ;
if ( F_372 ( V_2 , V_694 ) )
return true ;
V_319 = F_287 ( V_2 , V_694 , NULL ) ;
if ( V_319 == V_80 )
return true ;
if ( ! F_141 ( F_140 ( V_2 -> V_29 , V_319 >> V_86 ) ) )
return true ;
return false ;
}
static bool F_373 ( struct V_701 * V_702 ,
unsigned long V_62 , int V_820 )
{
struct V_1 * V_2 = F_290 ( V_702 ) ;
unsigned long V_821 , V_822 , V_319 = V_62 ;
V_821 = V_2 -> V_5 . V_821 ;
V_822 = V_2 -> V_5 . V_822 ;
V_2 -> V_5 . V_821 = V_2 -> V_5 . V_822 = 0 ;
if ( ! ( V_820 & V_823 ) )
return false ;
if ( F_374 ( V_702 ) )
return false ;
if ( V_702 -> V_797 == V_821 && V_822 == V_62 )
return false ;
V_2 -> V_5 . V_821 = V_702 -> V_797 ;
V_2 -> V_5 . V_822 = V_62 ;
if ( ! V_2 -> V_5 . V_67 . V_824 )
V_319 = F_286 ( V_2 , V_62 , NULL ) ;
F_375 ( V_2 -> V_29 , V_319 >> V_86 ) ;
return true ;
}
int F_376 ( struct V_1 * V_2 ,
unsigned long V_62 ,
int V_820 ,
void * V_825 ,
int V_826 )
{
int V_99 ;
struct V_701 * V_702 = & V_2 -> V_5 . V_788 ;
bool V_401 = true ;
F_377 ( V_2 ) ;
if ( ! ( V_820 & V_827 ) ) {
F_360 ( V_2 ) ;
V_702 -> V_828 = 0 ;
V_702 -> V_829 = false ;
V_702 -> V_830 = false ;
V_702 -> V_831
= V_820 & V_832 ;
V_99 = F_378 ( V_702 , V_825 , V_826 ) ;
F_379 ( V_2 ) ;
++ V_2 -> V_60 . V_833 ;
if ( V_99 != V_834 ) {
if ( V_820 & V_832 )
return V_811 ;
if ( F_371 ( V_2 , V_62 ) )
return V_813 ;
if ( V_820 & V_835 )
return V_811 ;
return F_369 ( V_2 ) ;
}
}
if ( V_820 & V_835 ) {
F_367 ( V_2 , V_702 -> V_810 ) ;
return V_813 ;
}
if ( F_373 ( V_702 , V_62 , V_820 ) )
return V_813 ;
if ( V_2 -> V_5 . V_806 ) {
V_2 -> V_5 . V_806 = false ;
memcpy ( V_702 -> V_489 , V_2 -> V_5 . V_489 , sizeof V_702 -> V_489 ) ;
}
V_836:
V_99 = F_380 ( V_702 ) ;
if ( V_99 == V_837 )
return V_813 ;
if ( V_99 == V_838 ) {
if ( F_371 ( V_2 , V_62 ) )
return V_813 ;
return F_369 ( V_2 ) ;
}
if ( V_702 -> V_829 ) {
F_358 ( V_2 ) ;
V_99 = V_813 ;
} else if ( V_2 -> V_5 . V_740 . V_610 ) {
if ( ! V_2 -> V_5 . V_740 . V_741 )
V_2 -> V_5 . V_740 . V_610 = 0 ;
else
V_401 = false ;
V_99 = V_839 ;
} else if ( V_2 -> V_719 ) {
if ( ! V_2 -> V_725 )
V_401 = false ;
V_99 = V_839 ;
} else if ( V_99 == V_840 )
goto V_836;
else
V_99 = V_813 ;
if ( V_401 ) {
F_357 ( V_2 , V_702 -> V_828 ) ;
F_368 ( V_2 , V_702 -> V_796 ) ;
F_23 ( V_48 , V_2 ) ;
memcpy ( V_2 -> V_5 . V_489 , V_702 -> V_489 , sizeof V_702 -> V_489 ) ;
V_2 -> V_5 . V_841 = false ;
F_367 ( V_2 , V_702 -> V_797 ) ;
} else
V_2 -> V_5 . V_841 = true ;
return V_99 ;
}
int F_381 ( struct V_1 * V_2 , int V_403 , unsigned short V_742 )
{
unsigned long V_145 = F_81 ( V_2 , V_164 ) ;
int V_88 = F_320 ( & V_2 -> V_5 . V_788 ,
V_403 , V_742 , & V_145 , 1 ) ;
V_2 -> V_5 . V_740 . V_610 = 0 ;
return V_88 ;
}
static void F_382 ( void * V_779 )
{
F_383 ( V_209 , 0 ) ;
}
static void F_384 ( void * V_31 )
{
struct V_842 * V_843 = V_31 ;
unsigned long V_844 = 0 ;
if ( V_31 )
V_844 = V_843 -> V_733 ;
else if ( ! F_105 ( V_207 ) )
V_844 = F_106 ( F_385 () ) ;
if ( ! V_844 )
V_844 = V_845 ;
F_383 ( V_209 , V_844 ) ;
}
static int F_386 ( struct V_846 * V_847 , unsigned long V_145 ,
void * V_31 )
{
struct V_842 * V_843 = V_31 ;
struct V_29 * V_29 ;
struct V_1 * V_2 ;
int V_3 , V_848 = 0 ;
if ( V_145 == V_849 && V_843 -> V_732 > V_843 -> V_733 )
return 0 ;
if ( V_145 == V_850 && V_843 -> V_732 < V_843 -> V_733 )
return 0 ;
F_196 ( V_843 -> V_206 , F_384 , V_843 , 1 ) ;
F_387 ( & V_851 ) ;
F_388 (kvm, &vm_list, vm_list) {
F_174 (i, vcpu, kvm) {
if ( V_2 -> V_206 != V_843 -> V_206 )
continue;
F_23 ( V_236 , V_2 ) ;
if ( V_2 -> V_206 != F_389 () )
V_848 = 1 ;
}
}
F_390 ( & V_851 ) ;
if ( V_843 -> V_732 < V_843 -> V_733 && V_848 ) {
F_196 ( V_843 -> V_206 , F_384 , V_843 , 1 ) ;
}
return 0 ;
}
static int F_391 ( struct V_846 * V_852 ,
unsigned long V_853 , void * V_854 )
{
unsigned int V_206 = ( unsigned long ) V_854 ;
switch ( V_853 ) {
case V_855 :
case V_856 :
F_196 ( V_206 , F_384 , NULL , 1 ) ;
break;
case V_857 :
F_196 ( V_206 , F_382 , NULL , 1 ) ;
break;
}
return V_858 ;
}
static void F_392 ( void )
{
int V_206 ;
V_859 = V_845 ;
F_393 ( & V_860 ) ;
if ( ! F_105 ( V_207 ) ) {
#ifdef F_394
struct V_861 V_862 ;
memset ( & V_862 , 0 , sizeof( V_862 ) ) ;
V_206 = F_104 () ;
F_395 ( & V_862 , V_206 ) ;
if ( V_862 . V_863 . V_864 )
V_859 = V_862 . V_863 . V_864 ;
F_107 () ;
#endif
F_396 ( & V_865 ,
V_866 ) ;
}
F_96 ( L_23 , V_859 ) ;
F_397 (cpu)
F_196 ( V_206 , F_384 , NULL , 1 ) ;
}
int F_398 ( void )
{
return F_109 ( V_867 ) != NULL ;
}
static int F_399 ( void )
{
int V_868 = 3 ;
if ( F_109 ( V_867 ) )
V_868 = V_56 -> V_71 ( F_109 ( V_867 ) ) ;
return V_868 != 0 ;
}
static unsigned long F_400 ( void )
{
unsigned long V_869 = 0 ;
if ( F_109 ( V_867 ) )
V_869 = F_362 ( F_109 ( V_867 ) ) ;
return V_869 ;
}
void F_401 ( struct V_1 * V_2 )
{
F_383 ( V_867 , V_2 ) ;
}
void F_402 ( struct V_1 * V_2 )
{
F_383 ( V_867 , NULL ) ;
}
static void F_403 ( void )
{
T_2 V_26 ;
int V_870 = V_871 . V_872 ;
V_26 = ( ( 1ull << ( 62 - V_870 + 1 ) ) - 1 ) << V_870 ;
V_26 |= 1ull ;
#ifdef F_52
if ( V_870 == 52 )
V_26 &= ~ 1ull ;
#endif
F_404 ( V_26 ) ;
}
int F_405 ( void * V_873 )
{
int V_99 ;
struct V_56 * V_715 = (struct V_56 * ) V_873 ;
if ( V_56 ) {
F_9 ( V_25 L_24 ) ;
V_99 = - V_646 ;
goto V_93;
}
if ( ! V_715 -> V_874 () ) {
F_9 ( V_25 L_25 ) ;
V_99 = - V_875 ;
goto V_93;
}
if ( V_715 -> V_876 () ) {
F_9 ( V_25 L_26 ) ;
V_99 = - V_875 ;
goto V_93;
}
V_99 = F_406 () ;
if ( V_99 )
goto V_93;
F_403 () ;
F_270 () ;
V_56 = V_715 ;
F_407 ( V_877 , V_878 ,
V_879 , V_880 , 0 ) ;
F_392 () ;
F_408 ( & V_881 ) ;
if ( V_452 )
V_124 = F_409 ( V_120 ) ;
return 0 ;
V_93:
return V_99 ;
}
void F_410 ( void )
{
F_411 ( & V_881 ) ;
if ( ! F_105 ( V_207 ) )
F_412 ( & V_865 ,
V_866 ) ;
F_413 ( & V_860 ) ;
V_56 = NULL ;
F_414 () ;
}
int F_415 ( struct V_1 * V_2 )
{
++ V_2 -> V_60 . V_882 ;
if ( F_18 ( V_2 -> V_29 ) ) {
V_2 -> V_5 . V_883 = V_884 ;
return 1 ;
} else {
V_2 -> V_712 -> V_720 = V_885 ;
return 0 ;
}
}
int F_416 ( struct V_1 * V_2 )
{
T_2 V_886 , V_887 , V_888 , V_88 ;
T_13 V_889 , V_890 , V_891 , V_160 = V_892 , V_893 = 0 ;
bool V_894 , V_895 ;
int V_112 , V_113 ;
if ( V_56 -> V_71 ( V_2 ) != 0 || ! F_363 ( V_2 ) ) {
F_24 ( V_2 , V_161 ) ;
return 0 ;
}
V_56 -> V_114 ( V_2 , & V_112 , & V_113 ) ;
V_895 = F_46 ( V_2 ) && V_113 == 1 ;
if ( ! V_895 ) {
V_886 = ( ( T_2 ) F_81 ( V_2 , V_165 ) << 32 ) |
( F_81 ( V_2 , V_164 ) & 0xffffffff ) ;
V_887 = ( ( T_2 ) F_81 ( V_2 , V_896 ) << 32 ) |
( F_81 ( V_2 , V_163 ) & 0xffffffff ) ;
V_888 = ( ( T_2 ) F_81 ( V_2 , V_897 ) << 32 ) |
( F_81 ( V_2 , V_898 ) & 0xffffffff ) ;
}
#ifdef F_52
else {
V_886 = F_81 ( V_2 , V_163 ) ;
V_887 = F_81 ( V_2 , V_165 ) ;
V_888 = F_81 ( V_2 , V_899 ) ;
}
#endif
V_889 = V_886 & 0xffff ;
V_894 = ( V_886 >> 16 ) & 0x1 ;
V_891 = ( V_886 >> 32 ) & 0xfff ;
V_890 = ( V_886 >> 48 ) & 0xfff ;
F_417 ( V_889 , V_894 , V_891 , V_890 , V_887 , V_888 ) ;
switch ( V_889 ) {
case V_900 :
F_418 ( V_2 ) ;
break;
default:
V_160 = V_901 ;
break;
}
V_88 = V_160 | ( ( ( T_2 ) V_893 & 0xfff ) << 32 ) ;
if ( V_895 ) {
F_83 ( V_2 , V_164 , V_88 ) ;
} else {
F_83 ( V_2 , V_165 , V_88 >> 32 ) ;
F_83 ( V_2 , V_164 , V_88 & 0xffffffff ) ;
}
return 1 ;
}
int F_419 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_902 , V_903 , V_904 , V_905 , V_88 ;
int V_99 = 1 ;
if ( F_137 ( V_2 -> V_29 ) )
return F_416 ( V_2 ) ;
V_16 = F_81 ( V_2 , V_164 ) ;
V_902 = F_81 ( V_2 , V_896 ) ;
V_903 = F_81 ( V_2 , V_163 ) ;
V_904 = F_81 ( V_2 , V_165 ) ;
V_905 = F_81 ( V_2 , V_898 ) ;
F_420 ( V_16 , V_902 , V_903 , V_904 , V_905 ) ;
if ( ! F_46 ( V_2 ) ) {
V_16 &= 0xFFFFFFFF ;
V_902 &= 0xFFFFFFFF ;
V_903 &= 0xFFFFFFFF ;
V_904 &= 0xFFFFFFFF ;
V_905 &= 0xFFFFFFFF ;
}
if ( V_56 -> V_71 ( V_2 ) != 0 ) {
V_88 = - V_906 ;
goto V_93;
}
switch ( V_16 ) {
case V_907 :
V_88 = 0 ;
break;
default:
V_88 = - V_908 ;
break;
}
V_93:
F_83 ( V_2 , V_164 , V_88 ) ;
++ V_2 -> V_60 . V_909 ;
return V_99 ;
}
int F_421 ( struct V_701 * V_702 )
{
struct V_1 * V_2 = F_290 ( V_702 ) ;
char V_910 [ 3 ] ;
unsigned long V_911 = F_362 ( V_2 ) ;
F_422 ( V_2 -> V_29 ) ;
V_56 -> V_307 ( V_2 , V_910 ) ;
return F_310 ( V_702 , V_911 , V_910 , 3 , NULL ) ;
}
static int F_423 ( struct V_1 * V_2 )
{
return ( ! F_18 ( V_2 -> V_29 ) && ! F_424 ( V_2 ) &&
V_2 -> V_712 -> V_912 &&
F_425 ( V_2 ) ) ;
}
static void F_426 ( struct V_1 * V_2 )
{
struct V_913 * V_913 = V_2 -> V_712 ;
V_913 -> V_914 = ( F_361 ( V_2 ) & V_915 ) != 0 ;
V_913 -> V_142 = F_73 ( V_2 ) ;
V_913 -> V_30 = F_17 ( V_2 ) ;
if ( F_18 ( V_2 -> V_29 ) )
V_913 -> V_916 = 1 ;
else
V_913 -> V_916 =
F_425 ( V_2 ) &&
! F_424 ( V_2 ) &&
! F_427 ( V_2 ) ;
}
static void F_428 ( struct V_1 * V_2 )
{
struct V_917 * V_490 = V_2 -> V_5 . V_490 ;
struct V_295 * V_295 ;
if ( ! V_490 || ! V_490 -> V_569 )
return;
V_295 = F_159 ( V_2 -> V_29 , V_490 -> V_569 >> V_86 ) ;
V_2 -> V_5 . V_490 -> V_918 = V_295 ;
}
static void F_429 ( struct V_1 * V_2 )
{
struct V_917 * V_490 = V_2 -> V_5 . V_490 ;
int V_270 ;
if ( ! V_490 || ! V_490 -> V_569 )
return;
V_270 = F_182 ( & V_2 -> V_29 -> V_398 ) ;
F_151 ( V_490 -> V_918 ) ;
F_125 ( V_2 -> V_29 , V_490 -> V_569 >> V_86 ) ;
F_183 ( & V_2 -> V_29 -> V_398 , V_270 ) ;
}
static void F_204 ( struct V_1 * V_2 )
{
int V_919 , V_920 ;
if ( ! V_56 -> F_204 )
return;
if ( ! V_2 -> V_5 . V_490 )
return;
if ( ! V_2 -> V_5 . V_490 -> V_569 )
V_919 = F_430 ( V_2 ) ;
else
V_919 = - 1 ;
if ( V_919 != - 1 )
V_919 >>= 4 ;
V_920 = F_74 ( V_2 ) ;
V_56 -> F_204 ( V_2 , V_920 , V_919 ) ;
}
static void F_431 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_49 . V_50 ) {
F_432 ( V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ) ;
V_56 -> V_921 ( V_2 , V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ,
V_2 -> V_5 . V_49 . V_44 ) ;
return;
}
if ( V_2 -> V_5 . V_520 ) {
V_56 -> V_922 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_513 . V_50 ) {
V_56 -> V_923 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_521 ) {
if ( V_56 -> V_924 ( V_2 ) ) {
-- V_2 -> V_5 . V_521 ;
V_2 -> V_5 . V_520 = true ;
V_56 -> V_922 ( V_2 ) ;
}
} else if ( F_424 ( V_2 ) ) {
if ( V_56 -> V_925 ( V_2 ) ) {
F_206 ( V_2 , F_433 ( V_2 ) ,
false ) ;
V_56 -> V_923 ( V_2 ) ;
}
}
}
static void F_434 ( struct V_1 * V_2 )
{
if ( F_76 ( V_2 , V_134 ) &&
! V_2 -> V_125 ) {
F_435 ( V_120 , V_2 -> V_5 . V_119 ) ;
V_2 -> V_125 = 1 ;
}
}
static void F_436 ( struct V_1 * V_2 )
{
if ( V_2 -> V_125 ) {
if ( V_2 -> V_5 . V_119 != V_124 )
F_435 ( V_120 , V_124 ) ;
V_2 -> V_125 = 0 ;
}
}
static void F_212 ( struct V_1 * V_2 )
{
unsigned V_768 = 2 ;
if ( V_56 -> V_523 ( V_2 ) || V_2 -> V_5 . V_520 )
V_768 = 1 ;
V_2 -> V_5 . V_521 += F_437 ( & V_2 -> V_5 . V_68 , 0 ) ;
V_2 -> V_5 . V_521 = F_273 ( V_2 -> V_5 . V_521 , V_768 ) ;
F_23 ( V_48 , V_2 ) ;
}
static int F_438 ( struct V_1 * V_2 )
{
int V_99 ;
bool V_926 = ! F_18 ( V_2 -> V_29 ) &&
V_2 -> V_712 -> V_912 ;
bool V_927 = 0 ;
if ( V_2 -> V_928 ) {
if ( F_439 ( V_929 , V_2 ) )
F_440 ( V_2 ) ;
if ( F_439 ( V_930 , V_2 ) )
F_441 ( V_2 ) ;
if ( F_439 ( V_236 , V_2 ) ) {
V_99 = F_120 ( V_2 ) ;
if ( F_69 ( V_99 ) )
goto V_93;
}
if ( F_439 ( V_931 , V_2 ) )
F_67 ( V_2 ) ;
if ( F_439 ( V_932 , V_2 ) )
V_56 -> V_933 ( V_2 ) ;
if ( F_439 ( V_934 , V_2 ) ) {
V_2 -> V_712 -> V_720 = V_935 ;
V_99 = 0 ;
goto V_93;
}
if ( F_439 ( V_54 , V_2 ) ) {
V_2 -> V_712 -> V_720 = V_936 ;
V_99 = 0 ;
goto V_93;
}
if ( F_439 ( V_937 , V_2 ) ) {
V_2 -> V_938 = 0 ;
V_56 -> V_939 ( V_2 ) ;
}
if ( F_439 ( V_940 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_941 = true ;
V_99 = 1 ;
goto V_93;
}
if ( F_439 ( V_359 , V_2 ) )
F_153 ( V_2 ) ;
if ( F_439 ( V_69 , V_2 ) )
F_212 ( V_2 ) ;
V_927 =
F_439 ( V_942 , V_2 ) ;
if ( F_439 ( V_943 , V_2 ) )
F_442 ( V_2 ) ;
if ( F_439 ( V_944 , V_2 ) )
F_443 ( V_2 ) ;
}
V_99 = F_444 ( V_2 ) ;
if ( F_69 ( V_99 ) )
goto V_93;
if ( F_439 ( V_48 , V_2 ) || V_926 ) {
F_431 ( V_2 ) ;
if ( V_2 -> V_5 . V_521 )
V_56 -> V_945 ( V_2 ) ;
else if ( F_424 ( V_2 ) || V_926 )
V_56 -> V_946 ( V_2 ) ;
if ( F_445 ( V_2 ) ) {
F_204 ( V_2 ) ;
F_446 ( V_2 ) ;
}
}
F_163 () ;
V_56 -> V_947 ( V_2 ) ;
if ( V_2 -> V_938 )
F_351 ( V_2 ) ;
F_434 ( V_2 ) ;
V_2 -> V_798 = V_948 ;
F_447 () ;
F_268 () ;
if ( V_2 -> V_798 == V_949 || V_2 -> V_928
|| F_448 () || F_449 ( V_326 ) ) {
V_2 -> V_798 = V_950 ;
F_12 () ;
F_269 () ;
F_164 () ;
V_56 -> V_951 ( V_2 ) ;
V_99 = 1 ;
goto V_93;
}
F_183 ( & V_2 -> V_29 -> V_398 , V_2 -> V_952 ) ;
if ( V_927 )
F_450 ( V_2 -> V_206 ) ;
F_451 () ;
if ( F_69 ( V_2 -> V_5 . V_158 ) ) {
F_452 ( 0 , 7 ) ;
F_452 ( V_2 -> V_5 . V_149 [ 0 ] , 0 ) ;
F_452 ( V_2 -> V_5 . V_149 [ 1 ] , 1 ) ;
F_452 ( V_2 -> V_5 . V_149 [ 2 ] , 2 ) ;
F_452 ( V_2 -> V_5 . V_149 [ 3 ] , 3 ) ;
}
F_453 ( V_2 -> V_953 ) ;
V_56 -> V_712 ( V_2 ) ;
if ( F_454 () )
F_455 () ;
V_2 -> V_5 . V_240 = V_56 -> V_235 ( V_2 ) ;
V_2 -> V_798 = V_950 ;
F_12 () ;
F_269 () ;
++ V_2 -> V_60 . V_954 ;
F_456 () ;
F_457 () ;
F_164 () ;
V_2 -> V_952 = F_182 ( & V_2 -> V_29 -> V_398 ) ;
if ( F_69 ( V_955 == V_956 ) ) {
unsigned long V_911 = F_362 ( V_2 ) ;
F_458 ( V_956 , ( void * ) V_911 ) ;
}
F_459 ( V_2 ) ;
V_99 = V_56 -> V_957 ( V_2 ) ;
V_93:
return V_99 ;
}
static int F_460 ( struct V_1 * V_2 )
{
int V_99 ;
struct V_29 * V_29 = V_2 -> V_29 ;
if ( F_69 ( V_2 -> V_5 . V_883 == V_958 ) ) {
F_96 ( L_27 ,
V_2 -> V_953 , V_2 -> V_5 . V_524 ) ;
F_461 ( V_2 ) ;
V_99 = F_462 ( V_2 ) ;
if ( V_99 )
return V_99 ;
V_2 -> V_5 . V_883 = V_959 ;
}
V_2 -> V_952 = F_182 ( & V_29 -> V_398 ) ;
F_428 ( V_2 ) ;
V_99 = 1 ;
while ( V_99 > 0 ) {
if ( V_2 -> V_5 . V_883 == V_959 &&
! V_2 -> V_5 . V_6 . V_941 )
V_99 = F_438 ( V_2 ) ;
else {
F_183 ( & V_29 -> V_398 , V_2 -> V_952 ) ;
F_463 ( V_2 ) ;
V_2 -> V_952 = F_182 ( & V_29 -> V_398 ) ;
if ( F_439 ( V_960 , V_2 ) )
{
switch( V_2 -> V_5 . V_883 ) {
case V_884 :
V_2 -> V_5 . V_883 =
V_959 ;
case V_959 :
V_2 -> V_5 . V_6 . V_941 = false ;
break;
case V_958 :
default:
V_99 = - V_961 ;
break;
}
}
}
if ( V_99 <= 0 )
break;
F_464 ( V_962 , & V_2 -> V_928 ) ;
if ( F_465 ( V_2 ) )
F_466 ( V_2 ) ;
if ( F_423 ( V_2 ) ) {
V_99 = - V_961 ;
V_2 -> V_712 -> V_720 = V_963 ;
++ V_2 -> V_60 . V_964 ;
}
F_467 ( V_2 ) ;
if ( F_449 ( V_326 ) ) {
V_99 = - V_961 ;
V_2 -> V_712 -> V_720 = V_963 ;
++ V_2 -> V_60 . V_965 ;
}
if ( F_448 () ) {
F_183 ( & V_29 -> V_398 , V_2 -> V_952 ) ;
F_468 ( V_2 ) ;
V_2 -> V_952 = F_182 ( & V_29 -> V_398 ) ;
}
}
F_183 ( & V_29 -> V_398 , V_2 -> V_952 ) ;
F_429 ( V_2 ) ;
return V_99 ;
}
static int F_469 ( struct V_1 * V_2 )
{
struct V_913 * V_712 = V_2 -> V_712 ;
int V_99 ;
if ( ! ( V_2 -> V_5 . V_740 . V_610 || V_2 -> V_719 ) )
return 1 ;
if ( V_2 -> V_719 ) {
V_2 -> V_719 = 0 ;
if ( ! V_2 -> V_725 )
memcpy ( V_2 -> V_708 + V_2 -> V_726 ,
V_712 -> V_713 . V_31 , 8 ) ;
V_2 -> V_726 += 8 ;
if ( V_2 -> V_726 < V_2 -> V_723 ) {
V_712 -> V_720 = V_721 ;
V_712 -> V_713 . V_722 = V_2 -> V_709 + V_2 -> V_726 ;
memcpy ( V_712 -> V_713 . V_31 , V_2 -> V_708 + V_2 -> V_726 , 8 ) ;
V_712 -> V_713 . V_75 = F_273 ( V_2 -> V_723 - V_2 -> V_726 , 8 ) ;
V_712 -> V_713 . V_724 = V_2 -> V_725 ;
V_2 -> V_719 = 1 ;
return 0 ;
}
if ( V_2 -> V_725 )
return 1 ;
V_2 -> V_707 = 1 ;
}
V_2 -> V_952 = F_182 ( & V_2 -> V_29 -> V_398 ) ;
V_99 = F_470 ( V_2 , V_827 ) ;
F_183 ( & V_2 -> V_29 -> V_398 , V_2 -> V_952 ) ;
if ( V_99 != V_813 )
return 0 ;
return 1 ;
}
int F_471 ( struct V_1 * V_2 , struct V_913 * V_913 )
{
int V_99 ;
T_14 V_966 ;
if ( ! F_472 ( V_326 ) && F_473 ( V_326 ) )
return - V_297 ;
if ( V_2 -> V_967 )
F_474 ( V_968 , & V_2 -> V_969 , & V_966 ) ;
if ( F_69 ( V_2 -> V_5 . V_883 == V_970 ) ) {
F_463 ( V_2 ) ;
F_464 ( V_960 , & V_2 -> V_928 ) ;
V_99 = - V_971 ;
goto V_93;
}
if ( ! F_18 ( V_2 -> V_29 ) ) {
if ( F_71 ( V_2 , V_913 -> V_142 ) != 0 ) {
V_99 = - V_477 ;
goto V_93;
}
}
V_99 = F_469 ( V_2 ) ;
if ( V_99 <= 0 )
goto V_93;
V_99 = F_460 ( V_2 ) ;
V_93:
F_426 ( V_2 ) ;
if ( V_2 -> V_967 )
F_474 ( V_968 , & V_966 , NULL ) ;
return V_99 ;
}
int F_475 ( struct V_1 * V_2 , struct V_972 * V_489 )
{
if ( V_2 -> V_5 . V_841 ) {
struct V_701 * V_702 = & V_2 -> V_5 . V_788 ;
memcpy ( V_2 -> V_5 . V_489 , V_702 -> V_489 , sizeof V_702 -> V_489 ) ;
V_2 -> V_5 . V_841 = false ;
}
V_489 -> V_973 = F_81 ( V_2 , V_164 ) ;
V_489 -> V_974 = F_81 ( V_2 , V_896 ) ;
V_489 -> V_975 = F_81 ( V_2 , V_163 ) ;
V_489 -> V_976 = F_81 ( V_2 , V_165 ) ;
V_489 -> V_977 = F_81 ( V_2 , V_898 ) ;
V_489 -> V_978 = F_81 ( V_2 , V_897 ) ;
V_489 -> V_979 = F_81 ( V_2 , V_785 ) ;
V_489 -> V_980 = F_81 ( V_2 , V_981 ) ;
#ifdef F_52
V_489 -> V_982 = F_81 ( V_2 , V_899 ) ;
V_489 -> V_983 = F_81 ( V_2 , V_984 ) ;
V_489 -> V_985 = F_81 ( V_2 , V_986 ) ;
V_489 -> V_987 = F_81 ( V_2 , V_988 ) ;
V_489 -> V_989 = F_81 ( V_2 , V_990 ) ;
V_489 -> V_991 = F_81 ( V_2 , V_992 ) ;
V_489 -> V_993 = F_81 ( V_2 , V_994 ) ;
V_489 -> V_995 = F_81 ( V_2 , V_996 ) ;
#endif
V_489 -> V_911 = F_362 ( V_2 ) ;
V_489 -> V_997 = F_361 ( V_2 ) ;
return 0 ;
}
int F_476 ( struct V_1 * V_2 , struct V_972 * V_489 )
{
V_2 -> V_5 . V_806 = true ;
V_2 -> V_5 . V_841 = false ;
F_83 ( V_2 , V_164 , V_489 -> V_973 ) ;
F_83 ( V_2 , V_896 , V_489 -> V_974 ) ;
F_83 ( V_2 , V_163 , V_489 -> V_975 ) ;
F_83 ( V_2 , V_165 , V_489 -> V_976 ) ;
F_83 ( V_2 , V_898 , V_489 -> V_977 ) ;
F_83 ( V_2 , V_897 , V_489 -> V_978 ) ;
F_83 ( V_2 , V_785 , V_489 -> V_979 ) ;
F_83 ( V_2 , V_981 , V_489 -> V_980 ) ;
#ifdef F_52
F_83 ( V_2 , V_899 , V_489 -> V_982 ) ;
F_83 ( V_2 , V_984 , V_489 -> V_983 ) ;
F_83 ( V_2 , V_986 , V_489 -> V_985 ) ;
F_83 ( V_2 , V_988 , V_489 -> V_987 ) ;
F_83 ( V_2 , V_990 , V_489 -> V_989 ) ;
F_83 ( V_2 , V_992 , V_489 -> V_991 ) ;
F_83 ( V_2 , V_994 , V_489 -> V_993 ) ;
F_83 ( V_2 , V_996 , V_489 -> V_995 ) ;
#endif
F_367 ( V_2 , V_489 -> V_911 ) ;
F_368 ( V_2 , V_489 -> V_997 ) ;
V_2 -> V_5 . V_49 . V_50 = false ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
void F_477 ( struct V_1 * V_2 , int * V_146 , int * V_773 )
{
struct V_687 V_998 ;
F_281 ( V_2 , & V_998 , V_999 ) ;
* V_146 = V_998 . V_146 ;
* V_773 = V_998 . V_773 ;
}
int F_478 ( struct V_1 * V_2 ,
struct V_1000 * V_1001 )
{
struct V_756 V_757 ;
F_281 ( V_2 , & V_1001 -> V_998 , V_999 ) ;
F_281 ( V_2 , & V_1001 -> V_1002 , V_1003 ) ;
F_281 ( V_2 , & V_1001 -> V_1004 , V_1005 ) ;
F_281 ( V_2 , & V_1001 -> V_1006 , V_1007 ) ;
F_281 ( V_2 , & V_1001 -> V_1008 , V_1009 ) ;
F_281 ( V_2 , & V_1001 -> V_1010 , V_1011 ) ;
F_281 ( V_2 , & V_1001 -> V_1012 , V_1013 ) ;
F_281 ( V_2 , & V_1001 -> V_1014 , V_1015 ) ;
V_56 -> V_759 ( V_2 , & V_757 ) ;
V_1001 -> V_1016 . V_768 = V_757 . V_403 ;
V_1001 -> V_1016 . V_769 = V_757 . V_63 ;
V_56 -> V_758 ( V_2 , & V_757 ) ;
V_1001 -> V_1017 . V_768 = V_757 . V_403 ;
V_1001 -> V_1017 . V_769 = V_757 . V_63 ;
V_1001 -> V_100 = F_51 ( V_2 ) ;
V_1001 -> V_62 = V_2 -> V_5 . V_62 ;
V_1001 -> V_84 = F_49 ( V_2 ) ;
V_1001 -> V_126 = F_61 ( V_2 ) ;
V_1001 -> V_142 = F_73 ( V_2 ) ;
V_1001 -> V_110 = V_2 -> V_5 . V_110 ;
V_1001 -> V_30 = F_17 ( V_2 ) ;
memset ( V_1001 -> V_1018 , 0 , sizeof V_1001 -> V_1018 ) ;
if ( V_2 -> V_5 . V_513 . V_50 && ! V_2 -> V_5 . V_513 . V_514 )
F_479 ( V_2 -> V_5 . V_513 . V_16 ,
( unsigned long * ) V_1001 -> V_1018 ) ;
return 0 ;
}
int F_480 ( struct V_1 * V_2 ,
struct V_1019 * V_883 )
{
V_883 -> V_883 = V_2 -> V_5 . V_883 ;
return 0 ;
}
int F_481 ( struct V_1 * V_2 ,
struct V_1019 * V_883 )
{
V_2 -> V_5 . V_883 = V_883 -> V_883 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
int F_482 ( struct V_1 * V_2 , V_737 V_1020 , int V_1021 ,
bool V_52 , T_1 V_43 )
{
struct V_701 * V_702 = & V_2 -> V_5 . V_788 ;
int V_88 ;
F_360 ( V_2 ) ;
V_88 = F_483 ( V_702 , V_1020 , V_1021 ,
V_52 , V_43 ) ;
if ( V_88 )
return V_811 ;
memcpy ( V_2 -> V_5 . V_489 , V_702 -> V_489 , sizeof V_702 -> V_489 ) ;
F_367 ( V_2 , V_702 -> V_797 ) ;
F_368 ( V_2 , V_702 -> V_796 ) ;
F_23 ( V_48 , V_2 ) ;
return V_813 ;
}
int F_484 ( struct V_1 * V_2 ,
struct V_1000 * V_1001 )
{
int V_1022 = 0 ;
int V_1023 , V_1024 , V_270 ;
struct V_756 V_757 ;
V_757 . V_403 = V_1001 -> V_1016 . V_768 ;
V_757 . V_63 = V_1001 -> V_1016 . V_769 ;
V_56 -> V_761 ( V_2 , & V_757 ) ;
V_757 . V_403 = V_1001 -> V_1017 . V_768 ;
V_757 . V_63 = V_1001 -> V_1017 . V_769 ;
V_56 -> V_760 ( V_2 , & V_757 ) ;
V_2 -> V_5 . V_62 = V_1001 -> V_62 ;
V_1022 |= F_49 ( V_2 ) != V_1001 -> V_84 ;
V_2 -> V_5 . V_84 = V_1001 -> V_84 ;
F_44 ( V_139 , ( V_140 * ) & V_2 -> V_5 . V_96 ) ;
F_71 ( V_2 , V_1001 -> V_142 ) ;
V_1022 |= V_2 -> V_5 . V_110 != V_1001 -> V_110 ;
V_56 -> F_84 ( V_2 , V_1001 -> V_110 ) ;
F_19 ( V_2 , V_1001 -> V_30 ) ;
V_1022 |= F_51 ( V_2 ) != V_1001 -> V_100 ;
V_56 -> V_115 ( V_2 , V_1001 -> V_100 ) ;
V_2 -> V_5 . V_100 = V_1001 -> V_100 ;
V_1022 |= F_61 ( V_2 ) != V_1001 -> V_126 ;
V_56 -> V_136 ( V_2 , V_1001 -> V_126 ) ;
if ( V_1001 -> V_126 & V_134 )
F_65 ( V_2 ) ;
V_270 = F_182 ( & V_2 -> V_29 -> V_398 ) ;
if ( ! F_46 ( V_2 ) && F_47 ( V_2 ) ) {
F_41 ( V_2 , V_2 -> V_5 . V_83 , F_49 ( V_2 ) ) ;
V_1022 = 1 ;
}
F_183 ( & V_2 -> V_29 -> V_398 , V_270 ) ;
if ( V_1022 )
F_55 ( V_2 ) ;
V_1024 = ( sizeof V_1001 -> V_1018 ) << 3 ;
V_1023 = F_485 (
( const unsigned long * ) V_1001 -> V_1018 , V_1024 ) ;
if ( V_1023 < V_1024 ) {
F_206 ( V_2 , V_1023 , false ) ;
F_96 ( L_28 , V_1023 ) ;
}
F_280 ( V_2 , & V_1001 -> V_998 , V_999 ) ;
F_280 ( V_2 , & V_1001 -> V_1002 , V_1003 ) ;
F_280 ( V_2 , & V_1001 -> V_1004 , V_1005 ) ;
F_280 ( V_2 , & V_1001 -> V_1006 , V_1007 ) ;
F_280 ( V_2 , & V_1001 -> V_1008 , V_1009 ) ;
F_280 ( V_2 , & V_1001 -> V_1010 , V_1011 ) ;
F_280 ( V_2 , & V_1001 -> V_1012 , V_1013 ) ;
F_280 ( V_2 , & V_1001 -> V_1014 , V_1015 ) ;
F_204 ( V_2 ) ;
if ( F_486 ( V_2 ) && F_362 ( V_2 ) == 0xfff0 &&
V_1001 -> V_998 . V_762 == 0xf000 && V_1001 -> V_998 . V_769 == 0xffff0000 &&
! F_363 ( V_2 ) )
V_2 -> V_5 . V_883 = V_959 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
int F_487 ( struct V_1 * V_2 ,
struct V_1025 * V_1026 )
{
unsigned long V_997 ;
int V_3 , V_99 ;
if ( V_1026 -> V_617 & ( V_1027 | V_1028 ) ) {
V_99 = - V_1029 ;
if ( V_2 -> V_5 . V_49 . V_50 )
goto V_93;
if ( V_1026 -> V_617 & V_1027 )
F_24 ( V_2 , V_1030 ) ;
else
F_24 ( V_2 , V_1031 ) ;
}
V_997 = F_361 ( V_2 ) ;
V_2 -> V_147 = V_1026 -> V_617 ;
if ( ! ( V_2 -> V_147 & V_1032 ) )
V_2 -> V_147 = 0 ;
if ( V_2 -> V_147 & V_148 ) {
for ( V_3 = 0 ; V_3 < V_1033 ; ++ V_3 )
V_2 -> V_5 . V_149 [ V_3 ] = V_1026 -> V_5 . V_1034 [ V_3 ] ;
V_2 -> V_5 . V_158 =
( V_1026 -> V_5 . V_1034 [ 7 ] & V_159 ) ;
} else {
for ( V_3 = 0 ; V_3 < V_1033 ; V_3 ++ )
V_2 -> V_5 . V_149 [ V_3 ] = V_2 -> V_5 . V_146 [ V_3 ] ;
V_2 -> V_5 . V_158 = ( V_2 -> V_5 . V_154 & V_159 ) ;
}
if ( V_2 -> V_147 & V_1035 )
V_2 -> V_5 . V_1036 = F_362 ( V_2 ) +
F_321 ( V_2 , V_999 ) ;
F_368 ( V_2 , V_997 ) ;
V_56 -> V_1037 ( V_2 , V_1026 ) ;
V_99 = 0 ;
V_93:
return V_99 ;
}
int F_488 ( struct V_1 * V_2 ,
struct V_1038 * V_1012 )
{
unsigned long V_1039 = V_1012 -> V_1040 ;
T_4 V_319 ;
int V_270 ;
V_270 = F_182 ( & V_2 -> V_29 -> V_398 ) ;
V_319 = F_287 ( V_2 , V_1039 , NULL ) ;
F_183 ( & V_2 -> V_29 -> V_398 , V_270 ) ;
V_1012 -> V_1041 = V_319 ;
V_1012 -> V_1042 = V_319 != V_80 ;
V_1012 -> V_1043 = 1 ;
V_1012 -> V_1044 = 0 ;
return 0 ;
}
int F_489 ( struct V_1 * V_2 , struct V_1045 * V_1046 )
{
struct V_541 * V_540 =
& V_2 -> V_5 . V_536 . V_537 -> V_540 ;
memcpy ( V_1046 -> V_1047 , V_540 -> V_1048 , 128 ) ;
V_1046 -> V_1049 = V_540 -> V_1050 ;
V_1046 -> V_1051 = V_540 -> V_1052 ;
V_1046 -> V_1053 = V_540 -> V_1054 ;
V_1046 -> V_1055 = V_540 -> V_1056 ;
V_1046 -> V_1057 = V_540 -> V_911 ;
V_1046 -> V_1058 = V_540 -> V_1059 ;
memcpy ( V_1046 -> V_1060 , V_540 -> V_1061 , sizeof V_540 -> V_1061 ) ;
return 0 ;
}
int F_490 ( struct V_1 * V_2 , struct V_1045 * V_1046 )
{
struct V_541 * V_540 =
& V_2 -> V_5 . V_536 . V_537 -> V_540 ;
memcpy ( V_540 -> V_1048 , V_1046 -> V_1047 , 128 ) ;
V_540 -> V_1050 = V_1046 -> V_1049 ;
V_540 -> V_1052 = V_1046 -> V_1051 ;
V_540 -> V_1054 = V_1046 -> V_1053 ;
V_540 -> V_1056 = V_1046 -> V_1055 ;
V_540 -> V_911 = V_1046 -> V_1057 ;
V_540 -> V_1059 = V_1046 -> V_1058 ;
memcpy ( V_540 -> V_1061 , V_1046 -> V_1060 , sizeof V_540 -> V_1061 ) ;
return 0 ;
}
int F_491 ( struct V_1 * V_2 )
{
int V_55 ;
V_55 = F_492 ( & V_2 -> V_5 . V_536 ) ;
if ( V_55 )
return V_55 ;
F_493 ( & V_2 -> V_5 . V_536 ) ;
V_2 -> V_5 . V_119 = V_121 ;
V_2 -> V_5 . V_100 |= V_107 ;
return 0 ;
}
static void F_494 ( struct V_1 * V_2 )
{
F_495 ( & V_2 -> V_5 . V_536 ) ;
}
void F_351 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1062 )
return;
F_436 ( V_2 ) ;
V_2 -> V_1062 = 1 ;
F_496 ( V_326 ) ;
F_497 ( & V_2 -> V_5 . V_536 ) ;
F_498 ( 1 ) ;
}
void F_200 ( struct V_1 * V_2 )
{
F_436 ( V_2 ) ;
if ( ! V_2 -> V_1062 )
return;
V_2 -> V_1062 = 0 ;
F_499 ( & V_2 -> V_5 . V_536 ) ;
++ V_2 -> V_60 . V_1063 ;
F_23 ( V_937 , V_2 ) ;
F_498 ( 0 ) ;
}
void F_500 ( struct V_1 * V_2 )
{
F_150 ( V_2 ) ;
F_501 ( V_2 -> V_5 . V_483 ) ;
F_494 ( V_2 ) ;
V_56 -> V_1064 ( V_2 ) ;
}
struct V_1 * F_502 ( struct V_29 * V_29 ,
unsigned int V_627 )
{
if ( F_118 () && F_503 ( & V_29 -> V_1065 ) != 0 )
F_111 ( V_210
L_29
L_30 ) ;
return V_56 -> V_1066 ( V_29 , V_627 ) ;
}
int F_504 ( struct V_1 * V_2 )
{
int V_99 ;
V_2 -> V_5 . V_265 . V_1067 = 1 ;
V_484 ( V_2 ) ;
V_99 = F_462 ( V_2 ) ;
if ( V_99 == 0 )
V_99 = F_505 ( V_2 ) ;
V_486 ( V_2 ) ;
return V_99 ;
}
void F_506 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_6 . V_320 = 0 ;
V_484 ( V_2 ) ;
F_440 ( V_2 ) ;
V_486 ( V_2 ) ;
F_494 ( V_2 ) ;
V_56 -> V_1064 ( V_2 ) ;
}
int F_462 ( struct V_1 * V_2 )
{
F_507 ( & V_2 -> V_5 . V_68 , 0 ) ;
V_2 -> V_5 . V_521 = 0 ;
V_2 -> V_5 . V_520 = false ;
V_2 -> V_5 . V_158 = 0 ;
memset ( V_2 -> V_5 . V_146 , 0 , sizeof( V_2 -> V_5 . V_146 ) ) ;
V_2 -> V_5 . V_151 = V_153 ;
V_2 -> V_5 . V_154 = V_156 ;
F_23 ( V_48 , V_2 ) ;
V_2 -> V_5 . V_6 . V_320 = 0 ;
V_2 -> V_5 . V_324 . V_320 = 0 ;
F_150 ( V_2 ) ;
F_54 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_941 = false ;
F_508 ( V_2 ) ;
return V_56 -> V_1068 ( V_2 ) ;
}
int F_509 ( void * V_478 )
{
struct V_29 * V_29 ;
struct V_1 * V_2 ;
int V_3 ;
F_13 () ;
F_388 (kvm, &vm_list, vm_list)
F_174 (i, vcpu, kvm)
if ( V_2 -> V_206 == F_389 () )
F_23 ( V_236 , V_2 ) ;
return V_56 -> V_1069 ( V_478 ) ;
}
void F_510 ( void * V_478 )
{
V_56 -> V_1070 ( V_478 ) ;
F_16 ( V_478 ) ;
}
int F_511 ( void )
{
return V_56 -> V_1071 () ;
}
void F_512 ( void )
{
V_56 -> V_1072 () ;
}
void F_513 ( void * V_1073 )
{
V_56 -> V_1074 ( V_1073 ) ;
}
int F_514 ( struct V_1 * V_2 )
{
struct V_295 * V_295 ;
struct V_29 * V_29 ;
int V_99 ;
F_283 ( V_2 -> V_29 == NULL ) ;
V_29 = V_2 -> V_29 ;
V_2 -> V_5 . V_788 . V_715 = & V_1075 ;
if ( ! F_18 ( V_29 ) || F_486 ( V_2 ) )
V_2 -> V_5 . V_883 = V_959 ;
else
V_2 -> V_5 . V_883 = V_970 ;
V_295 = F_515 ( V_555 | V_1076 ) ;
if ( ! V_295 ) {
V_99 = - V_297 ;
goto V_1077;
}
V_2 -> V_5 . V_743 = F_516 ( V_295 ) ;
F_113 ( V_2 , V_859 ) ;
V_99 = F_517 ( V_2 ) ;
if ( V_99 < 0 )
goto V_1078;
if ( F_18 ( V_29 ) ) {
V_99 = F_518 ( V_2 ) ;
if ( V_99 < 0 )
goto V_1079;
}
V_2 -> V_5 . V_284 = F_222 ( V_360 * sizeof( T_2 ) * 4 ,
V_555 ) ;
if ( ! V_2 -> V_5 . V_284 ) {
V_99 = - V_297 ;
goto V_1080;
}
V_2 -> V_5 . V_276 = V_360 ;
if ( ! F_519 ( & V_2 -> V_5 . V_483 , V_555 ) )
goto V_1081;
F_1 ( V_2 ) ;
F_520 ( V_2 ) ;
return 0 ;
V_1081:
F_136 ( V_2 -> V_5 . V_284 ) ;
V_1080:
F_521 ( V_2 ) ;
V_1079:
F_522 ( V_2 ) ;
V_1078:
F_523 ( ( unsigned long ) V_2 -> V_5 . V_743 ) ;
V_1077:
return V_99 ;
}
void F_524 ( struct V_1 * V_2 )
{
int V_270 ;
F_525 ( V_2 ) ;
F_136 ( V_2 -> V_5 . V_284 ) ;
F_521 ( V_2 ) ;
V_270 = F_182 ( & V_2 -> V_29 -> V_398 ) ;
F_522 ( V_2 ) ;
F_183 ( & V_2 -> V_29 -> V_398 , V_270 ) ;
F_523 ( ( unsigned long ) V_2 -> V_5 . V_743 ) ;
}
int F_526 ( struct V_29 * V_29 )
{
F_527 ( & V_29 -> V_5 . V_1082 ) ;
F_527 ( & V_29 -> V_5 . V_1083 ) ;
F_479 ( V_662 , & V_29 -> V_5 . V_1084 ) ;
F_528 ( & V_29 -> V_5 . V_224 ) ;
return 0 ;
}
static void F_529 ( struct V_1 * V_2 )
{
V_484 ( V_2 ) ;
F_440 ( V_2 ) ;
V_486 ( V_2 ) ;
}
static void F_530 ( struct V_29 * V_29 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_174 (i, vcpu, kvm) {
F_54 ( V_2 ) ;
F_529 ( V_2 ) ;
}
F_174 (i, vcpu, kvm)
F_500 ( V_2 ) ;
F_167 ( & V_29 -> V_375 ) ;
for ( V_3 = 0 ; V_3 < F_503 ( & V_29 -> V_1065 ) ; V_3 ++ )
V_29 -> V_1085 [ V_3 ] = NULL ;
F_507 ( & V_29 -> V_1065 , 0 ) ;
F_168 ( & V_29 -> V_375 ) ;
}
void F_531 ( struct V_29 * V_29 )
{
F_532 ( V_29 ) ;
F_533 ( V_29 ) ;
}
void F_534 ( struct V_29 * V_29 )
{
F_535 ( V_29 ) ;
F_136 ( V_29 -> V_5 . V_645 ) ;
F_136 ( V_29 -> V_5 . V_1086 ) ;
F_530 ( V_29 ) ;
if ( V_29 -> V_5 . V_1087 )
F_536 ( V_29 -> V_5 . V_1087 ) ;
if ( V_29 -> V_5 . V_1088 )
F_536 ( V_29 -> V_5 . V_1088 ) ;
}
int F_537 ( struct V_29 * V_29 ,
struct V_620 * V_621 ,
struct V_620 V_732 ,
struct V_1089 * V_1090 ,
int V_1091 )
{
int V_1092 = V_621 -> V_1092 ;
int V_1093 = V_1094 | V_1095 ;
if ( V_621 -> V_627 >= V_446 )
V_1093 = V_1096 | V_1095 ;
if ( ! V_1091 ) {
if ( V_1092 && ! V_732 . V_1097 ) {
unsigned long V_1098 ;
F_538 ( & V_326 -> V_1099 -> V_1100 ) ;
V_1098 = F_539 ( NULL , 0 ,
V_1092 * V_87 ,
V_1101 | V_1102 ,
V_1093 ,
0 ) ;
F_540 ( & V_326 -> V_1099 -> V_1100 ) ;
if ( F_134 ( ( void * ) V_1098 ) )
return F_135 ( ( void * ) V_1098 ) ;
V_621 -> V_1098 = V_1098 ;
}
}
return 0 ;
}
void F_541 ( struct V_29 * V_29 ,
struct V_1089 * V_1090 ,
struct V_620 V_732 ,
int V_1091 )
{
int V_1103 = 0 , V_1092 = V_1090 -> V_1104 >> V_86 ;
if ( ! V_1091 && ! V_732 . V_1091 && V_732 . V_1097 && ! V_1092 ) {
int V_88 ;
F_538 ( & V_326 -> V_1099 -> V_1100 ) ;
V_88 = F_542 ( V_326 -> V_1099 , V_732 . V_1098 ,
V_732 . V_1092 * V_87 ) ;
F_540 ( & V_326 -> V_1099 -> V_1100 ) ;
if ( V_88 < 0 )
F_9 ( V_210
L_31
L_32 ) ;
}
if ( ! V_29 -> V_5 . V_593 )
V_1103 = F_543 ( V_29 ) ;
F_230 ( & V_29 -> V_592 ) ;
if ( V_1103 )
F_231 ( V_29 , V_1103 ) ;
F_250 ( V_29 , V_1090 -> V_10 ) ;
F_232 ( & V_29 -> V_592 ) ;
}
void F_544 ( struct V_29 * V_29 )
{
F_422 ( V_29 ) ;
F_545 ( V_29 ) ;
}
int F_546 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_883 == V_959 &&
! V_2 -> V_5 . V_6 . V_941 )
|| ! F_547 ( & V_2 -> V_1105 . V_1106 )
|| V_2 -> V_5 . V_883 == V_958
|| F_503 ( & V_2 -> V_5 . V_68 ) ||
( F_425 ( V_2 ) &&
F_424 ( V_2 ) ) ;
}
void F_548 ( struct V_1 * V_2 )
{
int V_1107 ;
int V_206 = V_2 -> V_206 ;
if ( F_549 ( & V_2 -> V_1108 ) ) {
F_550 ( & V_2 -> V_1108 ) ;
++ V_2 -> V_60 . V_1109 ;
}
V_1107 = F_104 () ;
if ( V_206 != V_1107 && ( unsigned ) V_206 < V_1110 && F_551 ( V_206 ) )
if ( F_552 ( V_2 ) == V_948 )
F_450 ( V_206 ) ;
F_107 () ;
}
int F_425 ( struct V_1 * V_2 )
{
return V_56 -> V_925 ( V_2 ) ;
}
bool F_553 ( struct V_1 * V_2 , unsigned long V_1111 )
{
unsigned long V_1112 = F_362 ( V_2 ) +
F_321 ( V_2 , V_999 ) ;
return V_1112 == V_1111 ;
}
unsigned long F_361 ( struct V_1 * V_2 )
{
unsigned long V_997 ;
V_997 = V_56 -> V_1113 ( V_2 ) ;
if ( V_2 -> V_147 & V_1035 )
V_997 &= ~ V_1114 ;
return V_997 ;
}
void F_368 ( struct V_1 * V_2 , unsigned long V_997 )
{
if ( V_2 -> V_147 & V_1035 &&
F_553 ( V_2 , V_2 -> V_5 . V_1036 ) )
V_997 |= V_1114 ;
V_56 -> V_1115 ( V_2 , V_997 ) ;
F_23 ( V_48 , V_2 ) ;
}
void F_554 ( struct V_1 * V_2 , struct V_1116 * V_1117 )
{
int V_99 ;
if ( ( V_2 -> V_5 . V_67 . V_824 != V_1117 -> V_5 . V_824 ) ||
F_160 ( V_1117 -> V_295 ) )
return;
V_99 = F_444 ( V_2 ) ;
if ( F_69 ( V_99 ) )
return;
if ( ! V_2 -> V_5 . V_67 . V_824 &&
V_1117 -> V_5 . V_84 != V_2 -> V_5 . V_67 . V_1118 ( V_2 ) )
return;
V_2 -> V_5 . V_67 . V_1119 ( V_2 , V_1117 -> V_694 , 0 , true ) ;
}
static inline T_1 F_555 ( T_3 V_82 )
{
return F_556 ( V_82 & 0xffffffff , F_557 ( V_4 ) ) ;
}
static inline T_1 F_558 ( T_1 V_1120 )
{
return ( V_1120 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_559 ( struct V_1 * V_2 , T_3 V_82 )
{
T_1 V_1120 = F_555 ( V_82 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1120 ] != ~ 0 )
V_1120 = F_558 ( V_1120 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1120 ] = V_82 ;
}
static T_1 F_560 ( struct V_1 * V_2 , T_3 V_82 )
{
int V_3 ;
T_1 V_1120 = F_555 ( V_82 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1120 ] != V_82 &&
V_2 -> V_5 . V_6 . V_7 [ V_1120 ] != ~ 0 ) ; V_3 ++ )
V_1120 = F_558 ( V_1120 ) ;
return V_1120 ;
}
bool F_561 ( struct V_1 * V_2 , T_3 V_82 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_560 ( V_2 , V_82 ) ] == V_82 ;
}
static void F_562 ( struct V_1 * V_2 , T_3 V_82 )
{
T_1 V_3 , V_681 , V_1121 ;
V_3 = V_681 = F_560 ( V_2 , V_82 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_681 = F_558 ( V_681 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_681 ] == ~ 0 )
return;
V_1121 = F_555 ( V_2 -> V_5 . V_6 . V_7 [ V_681 ] ) ;
} while ( ( V_3 <= V_681 ) ? ( V_3 < V_1121 && V_1121 <= V_681 ) : ( V_3 < V_1121 || V_1121 <= V_681 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_681 ] ;
V_3 = V_681 ;
}
}
static int F_563 ( struct V_1 * V_2 , T_1 V_145 )
{
return F_155 ( V_2 -> V_29 , & V_2 -> V_5 . V_6 . V_31 , & V_145 ,
sizeof( V_145 ) ) ;
}
void F_564 ( struct V_1 * V_2 ,
struct V_1116 * V_1117 )
{
struct V_58 V_59 ;
F_565 ( V_1117 -> V_5 . V_1122 , V_1117 -> V_694 ) ;
F_559 ( V_2 , V_1117 -> V_5 . V_82 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_320 & V_321 ) ||
( V_2 -> V_5 . V_6 . V_322 &&
V_56 -> V_71 ( V_2 ) == 0 ) )
F_23 ( V_940 , V_2 ) ;
else if ( ! F_563 ( V_2 , V_1123 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_789 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_1117 -> V_5 . V_1122 ;
F_28 ( V_2 , & V_59 ) ;
}
}
void F_566 ( struct V_1 * V_2 ,
struct V_1116 * V_1117 )
{
struct V_58 V_59 ;
F_567 ( V_1117 -> V_5 . V_1122 , V_1117 -> V_694 ) ;
if ( F_160 ( V_1117 -> V_295 ) )
V_1117 -> V_5 . V_1122 = ~ 0 ;
else
F_562 ( V_2 , V_1117 -> V_5 . V_82 ) ;
if ( ( V_2 -> V_5 . V_6 . V_320 & V_321 ) &&
! F_563 ( V_2 , V_1124 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_789 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_1117 -> V_5 . V_1122 ;
F_28 ( V_2 , & V_59 ) ;
}
V_2 -> V_5 . V_6 . V_941 = false ;
}
bool F_568 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_320 & V_321 ) )
return true ;
else
return ! F_427 ( V_2 ) &&
V_56 -> V_925 ( V_2 ) ;
}
