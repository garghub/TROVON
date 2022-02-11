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
static inline T_2 F_103 ( struct V_1 * V_2 , T_2 V_190 )
{
return F_104 ( V_190 , V_2 -> V_5 . V_206 ,
V_2 -> V_5 . V_207 ) ;
}
static T_1 F_105 ( T_1 V_208 , T_9 V_209 )
{
T_2 V_210 = ( T_2 ) V_208 * ( 1000000 + V_209 ) ;
F_106 ( V_210 , 1000000 ) ;
return V_210 ;
}
static void F_107 ( struct V_1 * V_2 , T_1 V_211 )
{
T_1 V_212 , V_213 ;
int V_214 = 0 ;
F_95 ( V_211 , V_215 / 1000 ,
& V_2 -> V_5 . V_207 ,
& V_2 -> V_5 . V_206 ) ;
V_2 -> V_5 . V_216 = V_211 ;
V_212 = F_105 ( V_217 , - V_218 ) ;
V_213 = F_105 ( V_217 , V_218 ) ;
if ( V_211 < V_212 || V_211 > V_213 ) {
F_96 ( L_3 , V_211 , V_212 , V_213 ) ;
V_214 = 1 ;
}
V_56 -> V_219 ( V_2 , V_211 , V_214 ) ;
}
static T_2 F_108 ( struct V_1 * V_2 , T_10 V_220 )
{
T_2 V_221 = F_104 ( V_220 - V_2 -> V_5 . V_222 ,
V_2 -> V_5 . V_206 ,
V_2 -> V_5 . V_207 ) ;
V_221 += V_2 -> V_5 . V_223 ;
return V_221 ;
}
void F_109 ( struct V_1 * V_2 , T_2 V_31 )
{
struct V_29 * V_29 = V_2 -> V_29 ;
T_2 V_74 , V_224 , V_225 ;
unsigned long V_226 ;
T_10 V_227 ;
F_110 ( & V_29 -> V_5 . V_228 , V_226 ) ;
V_74 = V_56 -> V_229 ( V_2 , V_31 ) ;
V_224 = F_97 () ;
V_225 = V_224 - V_29 -> V_5 . V_230 ;
V_227 = V_31 - V_29 -> V_5 . V_231 ;
#ifdef F_52
V_227 = ( V_227 * 1000 ) / V_2 -> V_5 . V_216 ;
#else
asm("idivl %2; xor %%edx, %%edx"
: "=A"(usdiff)
: "A"(usdiff * 1000), "rm"(vcpu->arch.virtual_tsc_khz));
#endif
F_106 ( V_225 , 1000 ) ;
V_227 -= V_225 ;
if ( V_227 < 0 )
V_227 = - V_227 ;
if ( V_227 < V_232 &&
V_2 -> V_5 . V_216 == V_29 -> V_5 . V_233 ) {
if ( ! F_111 () ) {
V_74 = V_29 -> V_5 . V_234 ;
F_96 ( L_4 , V_31 ) ;
} else {
T_2 V_235 = F_103 ( V_2 , V_225 ) ;
V_31 += V_235 ;
V_74 = V_56 -> V_229 ( V_2 , V_31 ) ;
F_96 ( L_5 , V_235 ) ;
}
} else {
V_29 -> V_5 . V_236 ++ ;
V_29 -> V_5 . V_237 = V_224 ;
V_29 -> V_5 . V_238 = V_31 ;
V_29 -> V_5 . V_234 = V_74 ;
F_96 ( L_6 ,
V_29 -> V_5 . V_236 , V_31 ) ;
}
V_29 -> V_5 . V_230 = V_224 ;
V_29 -> V_5 . V_231 = V_31 ;
V_29 -> V_5 . V_233 = V_2 -> V_5 . V_216 ;
V_2 -> V_5 . V_239 . V_240 = 0 ;
V_2 -> V_5 . V_241 = V_31 ;
V_2 -> V_5 . V_242 = V_29 -> V_5 . V_236 ;
V_2 -> V_5 . V_222 = V_29 -> V_5 . V_237 ;
V_2 -> V_5 . V_223 = V_29 -> V_5 . V_238 ;
V_56 -> V_243 ( V_2 , V_74 ) ;
F_112 ( & V_29 -> V_5 . V_228 , V_226 ) ;
}
static int F_113 ( struct V_1 * V_210 )
{
unsigned long V_226 ;
struct V_244 * V_2 = & V_210 -> V_5 ;
void * V_245 ;
unsigned long V_211 ;
T_10 V_220 , V_246 ;
T_2 V_240 ;
F_114 ( V_226 ) ;
V_240 = V_56 -> V_247 ( V_210 ) ;
V_220 = F_97 () ;
V_211 = F_8 ( V_248 ) ;
if ( F_69 ( V_211 == 0 ) ) {
F_115 ( V_226 ) ;
F_23 ( V_249 , V_210 ) ;
return 1 ;
}
if ( V_2 -> V_250 ) {
T_2 V_221 = F_108 ( V_210 , V_220 ) ;
if ( V_221 > V_240 ) {
F_116 ( V_210 , V_221 - V_240 ) ;
V_240 = V_221 ;
}
}
F_115 ( V_226 ) ;
if ( ! V_2 -> V_251 )
return 0 ;
V_246 = 0 ;
if ( V_2 -> V_239 . V_240 ) {
V_246 = V_2 -> V_241 -
V_2 -> V_239 . V_240 ;
V_246 = F_104 ( V_246 ,
V_2 -> V_239 . V_252 ,
V_2 -> V_239 . V_253 ) ;
V_246 += V_2 -> V_254 ;
}
if ( F_69 ( V_2 -> V_255 != V_211 ) ) {
F_95 ( V_215 / 1000 , V_211 ,
& V_2 -> V_239 . V_253 ,
& V_2 -> V_239 . V_252 ) ;
V_2 -> V_255 = V_211 ;
}
if ( V_246 > V_220 )
V_220 = V_246 ;
V_2 -> V_239 . V_240 = V_240 ;
V_2 -> V_239 . V_256 = V_220 + V_210 -> V_29 -> V_5 . V_257 ;
V_2 -> V_254 = V_220 ;
V_2 -> V_241 = V_240 ;
V_2 -> V_239 . V_226 = 0 ;
V_2 -> V_239 . V_183 += 2 ;
V_245 = F_117 ( V_2 -> V_251 ) ;
memcpy ( V_245 + V_2 -> V_258 , & V_2 -> V_239 ,
sizeof( V_2 -> V_239 ) ) ;
F_118 ( V_245 ) ;
F_119 ( V_210 -> V_29 , V_2 -> time >> V_86 ) ;
return 0 ;
}
static bool F_120 ( unsigned V_21 )
{
switch ( V_21 ) {
case 0x200 ... 0x200 + 2 * V_259 - 1 :
case V_260 :
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
case V_268 :
case V_269 :
case V_270 :
case V_271 :
case V_272 :
return true ;
case 0x2f8 :
return true ;
}
return false ;
}
static bool F_121 ( unsigned V_273 )
{
return V_273 < 8 && ( 1 << V_273 ) & 0xf3 ;
}
static bool F_122 ( unsigned V_273 )
{
return V_273 < 8 && ( 1 << V_273 ) & 0x73 ;
}
static bool F_123 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
int V_3 ;
if ( ! F_120 ( V_21 ) )
return false ;
if ( V_21 == V_272 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_121 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
} else if ( V_21 == V_271 ) {
if ( V_31 & ~ 0xcff )
return false ;
return F_122 ( V_31 & 0xff ) ;
} else if ( V_21 >= V_260 && V_21 <= V_270 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_122 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
}
return F_122 ( V_31 & 0xff ) ;
}
static int F_124 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
T_2 * V_274 = ( T_2 * ) & V_2 -> V_5 . V_275 . V_276 ;
if ( ! F_123 ( V_2 , V_21 , V_31 ) )
return 1 ;
if ( V_21 == V_271 ) {
V_2 -> V_5 . V_275 . V_277 = V_31 ;
V_2 -> V_5 . V_275 . V_278 = ( V_31 & 0xc00 ) >> 10 ;
} else if ( V_21 == V_260 )
V_274 [ 0 ] = V_31 ;
else if ( V_21 == V_261 || V_21 == V_262 )
V_274 [ 1 + V_21 - V_261 ] = V_31 ;
else if ( V_21 >= V_263 && V_21 <= V_270 )
V_274 [ 3 + V_21 - V_263 ] = V_31 ;
else if ( V_21 == V_272 )
V_2 -> V_5 . V_279 = V_31 ;
else {
int V_280 , V_281 ;
T_2 * V_282 ;
V_280 = ( V_21 - 0x200 ) / 2 ;
V_281 = V_21 - 0x200 - 2 * V_280 ;
if ( ! V_281 )
V_282 =
( T_2 * ) & V_2 -> V_5 . V_275 . V_283 [ V_280 ] . V_284 ;
else
V_282 =
( T_2 * ) & V_2 -> V_5 . V_275 . V_283 [ V_280 ] . V_285 ;
* V_282 = V_31 ;
}
F_55 ( V_2 ) ;
return 0 ;
}
static int F_125 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
T_2 V_286 = V_2 -> V_5 . V_286 ;
unsigned V_287 = V_286 & 0xff ;
switch ( V_21 ) {
case V_288 :
V_2 -> V_5 . V_289 = V_31 ;
break;
case V_290 :
if ( ! ( V_286 & V_291 ) )
return 1 ;
if ( V_31 != 0 && V_31 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_292 = V_31 ;
break;
default:
if ( V_21 >= V_293 &&
V_21 < V_293 + 4 * V_287 ) {
T_1 V_74 = V_21 - V_293 ;
if ( ( V_74 & 0x3 ) == 0 &&
V_31 != 0 && ( V_31 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_294 [ V_74 ] = V_31 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_126 ( struct V_1 * V_2 , T_2 V_31 )
{
struct V_29 * V_29 = V_2 -> V_29 ;
int V_295 = F_46 ( V_2 ) ;
T_11 * V_296 = V_295 ? ( T_11 * ) ( long ) V_29 -> V_5 . F_126 . V_297
: ( T_11 * ) ( long ) V_29 -> V_5 . F_126 . V_298 ;
T_11 V_299 = V_295 ? V_29 -> V_5 . F_126 . V_300
: V_29 -> V_5 . F_126 . V_301 ;
T_1 V_302 = V_31 & ~ V_303 ;
T_2 V_304 = V_31 & V_303 ;
T_11 * V_305 ;
int V_99 ;
V_99 = - V_306 ;
if ( V_302 >= V_299 )
goto V_93;
V_99 = - V_307 ;
V_305 = F_127 ( V_296 + ( V_302 * V_87 ) , V_87 ) ;
if ( F_128 ( V_305 ) ) {
V_99 = F_129 ( V_305 ) ;
goto V_93;
}
if ( F_92 ( V_29 , V_304 , V_305 , V_87 ) )
goto V_308;
V_99 = 0 ;
V_308:
F_130 ( V_305 ) ;
V_93:
return V_99 ;
}
static bool F_131 ( struct V_29 * V_29 )
{
return V_29 -> V_5 . V_309 & V_310 ;
}
static bool F_132 ( T_1 V_21 )
{
bool V_99 = false ;
switch ( V_21 ) {
case V_311 :
case V_312 :
V_99 = true ;
break;
}
return V_99 ;
}
static int F_133 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
struct V_29 * V_29 = V_2 -> V_29 ;
switch ( V_21 ) {
case V_311 :
V_29 -> V_5 . V_313 = V_31 ;
if ( ! V_29 -> V_5 . V_313 )
V_29 -> V_5 . V_309 &= ~ V_310 ;
break;
case V_312 : {
T_2 V_82 ;
unsigned long V_314 ;
T_11 V_315 [ 4 ] ;
if ( ! V_29 -> V_5 . V_313 )
break;
if ( ! ( V_31 & V_310 ) ) {
V_29 -> V_5 . V_309 = V_31 ;
break;
}
V_82 = V_31 >> V_316 ;
V_314 = F_134 ( V_29 , V_82 ) ;
if ( F_135 ( V_314 ) )
return 1 ;
V_56 -> V_317 ( V_2 , V_315 ) ;
( ( unsigned char * ) V_315 ) [ 3 ] = 0xc3 ;
if ( F_136 ( ( void V_318 * ) V_314 , V_315 , 4 ) )
return 1 ;
V_29 -> V_5 . V_309 = V_31 ;
break;
}
default:
F_137 ( V_2 , L_7
L_8 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_138 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
switch ( V_21 ) {
case V_319 : {
unsigned long V_314 ;
if ( ! ( V_31 & V_320 ) ) {
V_2 -> V_5 . V_321 = V_31 ;
break;
}
V_314 = F_134 ( V_2 -> V_29 , V_31 >>
V_322 ) ;
if ( F_135 ( V_314 ) )
return 1 ;
if ( F_139 ( ( void V_318 * ) V_314 , V_87 ) )
return 1 ;
V_2 -> V_5 . V_321 = V_31 ;
break;
}
case V_323 :
return F_140 ( V_2 , V_324 , V_31 ) ;
case V_325 :
return F_140 ( V_2 , V_326 , V_31 ) ;
case V_327 :
return F_140 ( V_2 , V_328 , V_31 ) ;
default:
F_137 ( V_2 , L_7
L_8 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_141 ( struct V_1 * V_2 , T_2 V_31 )
{
T_4 V_329 = V_31 & ~ 0x3f ;
if ( V_31 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_330 = V_31 ;
if ( ! ( V_31 & V_331 ) ) {
F_54 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_142 ( V_2 -> V_29 , & V_2 -> V_5 . V_6 . V_31 , V_329 ) )
return 1 ;
V_2 -> V_5 . V_6 . V_332 = ! ( V_31 & V_333 ) ;
F_143 ( V_2 ) ;
return 0 ;
}
static void F_144 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_251 ) {
F_145 ( V_2 -> V_5 . V_251 ) ;
V_2 -> V_5 . V_251 = NULL ;
}
}
static void F_146 ( struct V_1 * V_2 )
{
T_2 V_235 ;
if ( ! ( V_2 -> V_5 . V_334 . V_330 & V_335 ) )
return;
V_235 = V_336 -> V_337 . V_338 - V_2 -> V_5 . V_334 . V_339 ;
V_2 -> V_5 . V_334 . V_339 = V_336 -> V_337 . V_338 ;
V_2 -> V_5 . V_334 . V_340 = V_235 ;
}
static void F_147 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_334 . V_330 & V_335 ) )
return;
if ( F_69 ( F_148 ( V_2 -> V_29 , & V_2 -> V_5 . V_334 . V_341 ,
& V_2 -> V_5 . V_334 . V_342 , sizeof( struct V_343 ) ) ) )
return;
V_2 -> V_5 . V_334 . V_342 . V_342 += V_2 -> V_5 . V_334 . V_340 ;
V_2 -> V_5 . V_334 . V_342 . V_183 += 2 ;
V_2 -> V_5 . V_334 . V_340 = 0 ;
F_149 ( V_2 -> V_29 , & V_2 -> V_5 . V_334 . V_341 ,
& V_2 -> V_5 . V_334 . V_342 , sizeof( struct V_343 ) ) ;
}
int F_150 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
bool V_344 = false ;
switch ( V_21 ) {
case V_345 :
return F_84 ( V_2 , V_31 ) ;
case V_346 :
V_31 &= ~ ( T_2 ) 0x40 ;
V_31 &= ~ ( T_2 ) 0x100 ;
V_31 &= ~ ( T_2 ) 0x8 ;
if ( V_31 != 0 ) {
F_137 ( V_2 , L_9 ,
V_31 ) ;
return 1 ;
}
break;
case V_347 :
if ( V_31 != 0 ) {
F_137 ( V_2 , L_10
L_11 , V_31 ) ;
return 1 ;
}
break;
case V_348 :
break;
case V_349 :
if ( ! V_31 ) {
break;
} else if ( V_31 & ~ ( V_350 | V_351 ) ) {
return 1 ;
}
F_137 ( V_2 , L_12 ,
V_204 , V_31 ) ;
break;
case V_352 :
case V_353 :
case V_354 :
case V_355 :
break;
case 0x200 ... 0x2ff :
return F_124 ( V_2 , V_21 , V_31 ) ;
case V_356 :
F_19 ( V_2 , V_31 ) ;
break;
case V_357 ... V_357 + 0x3ff :
return F_151 ( V_2 , V_21 , V_31 ) ;
case V_358 :
F_152 ( V_2 , V_31 ) ;
break;
case V_359 :
V_2 -> V_5 . V_360 = V_31 ;
break;
case V_361 :
case V_362 :
V_2 -> V_29 -> V_5 . V_182 = V_31 ;
F_90 ( V_2 -> V_29 , V_31 ) ;
break;
case V_363 :
case V_364 : {
F_144 ( V_2 ) ;
V_2 -> V_5 . time = V_31 ;
F_23 ( V_249 , V_2 ) ;
if ( ! ( V_31 & 1 ) )
break;
V_2 -> V_5 . V_258 = V_31 & ~ ( V_303 | 1 ) ;
V_2 -> V_5 . V_251 =
F_153 ( V_2 -> V_29 , V_31 >> V_86 ) ;
if ( F_154 ( V_2 -> V_5 . V_251 ) ) {
F_155 ( V_2 -> V_5 . V_251 ) ;
V_2 -> V_5 . V_251 = NULL ;
}
break;
}
case V_365 :
if ( F_141 ( V_2 , V_31 ) )
return 1 ;
break;
case V_366 :
if ( F_69 ( ! F_156 () ) )
return 1 ;
if ( V_31 & V_367 )
return 1 ;
if ( F_142 ( V_2 -> V_29 , & V_2 -> V_5 . V_334 . V_341 ,
V_31 & V_368 ) )
return 1 ;
V_2 -> V_5 . V_334 . V_330 = V_31 ;
if ( ! ( V_31 & V_335 ) )
break;
V_2 -> V_5 . V_334 . V_339 = V_336 -> V_337 . V_338 ;
F_157 () ;
F_146 ( V_2 ) ;
F_158 () ;
F_23 ( V_369 , V_2 ) ;
break;
case V_290 :
case V_288 :
case V_293 ... V_293 + 4 * V_370 - 1 :
return F_125 ( V_2 , V_21 , V_31 ) ;
case V_371 :
case V_372 :
case V_373 :
case V_374 :
if ( V_31 != 0 )
F_137 ( V_2 , L_13
L_14 , V_21 , V_31 ) ;
break;
case V_375 :
case V_376 :
case V_377 :
case V_378 :
F_137 ( V_2 , L_13
L_14 , V_21 , V_31 ) ;
break;
case V_379 :
case V_380 :
V_344 = true ;
case V_381 :
case V_382 :
if ( F_159 ( V_2 , V_21 ) )
return F_160 ( V_2 , V_21 , V_31 ) ;
if ( V_344 || V_31 != 0 )
F_137 ( V_2 , L_15
L_14 , V_21 , V_31 ) ;
break;
case V_383 :
break;
case V_311 ... V_384 :
if ( F_132 ( V_21 ) ) {
int V_99 ;
F_161 ( & V_2 -> V_29 -> V_385 ) ;
V_99 = F_133 ( V_2 , V_21 , V_31 ) ;
F_162 ( & V_2 -> V_29 -> V_385 ) ;
return V_99 ;
} else
return F_138 ( V_2 , V_21 , V_31 ) ;
break;
case V_386 :
F_137 ( V_2 , L_16 , V_21 , V_31 ) ;
break;
case V_387 :
if ( ! F_163 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_388 . V_389 = V_31 ;
break;
case V_390 :
if ( ! F_163 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_388 . V_391 = V_31 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_29 -> V_5 . F_126 . V_21 ) )
return F_126 ( V_2 , V_31 ) ;
if ( F_159 ( V_2 , V_21 ) )
return F_160 ( V_2 , V_21 , V_31 ) ;
if ( ! V_392 ) {
F_137 ( V_2 , L_17 ,
V_21 , V_31 ) ;
return 1 ;
} else {
F_137 ( V_2 , L_16 ,
V_21 , V_31 ) ;
break;
}
}
return 0 ;
}
int F_164 ( struct V_1 * V_2 , T_1 V_180 , T_2 * V_393 )
{
return V_56 -> V_394 ( V_2 , V_180 , V_393 ) ;
}
static int F_165 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_393 )
{
T_2 * V_274 = ( T_2 * ) & V_2 -> V_5 . V_275 . V_276 ;
if ( ! F_120 ( V_21 ) )
return 1 ;
if ( V_21 == V_271 )
* V_393 = V_2 -> V_5 . V_275 . V_277 +
( V_2 -> V_5 . V_275 . V_278 << 10 ) ;
else if ( V_21 == V_260 )
* V_393 = V_274 [ 0 ] ;
else if ( V_21 == V_261 || V_21 == V_262 )
* V_393 = V_274 [ 1 + V_21 - V_261 ] ;
else if ( V_21 >= V_263 && V_21 <= V_270 )
* V_393 = V_274 [ 3 + V_21 - V_263 ] ;
else if ( V_21 == V_272 )
* V_393 = V_2 -> V_5 . V_279 ;
else {
int V_280 , V_281 ;
T_2 * V_282 ;
V_280 = ( V_21 - 0x200 ) / 2 ;
V_281 = V_21 - 0x200 - 2 * V_280 ;
if ( ! V_281 )
V_282 =
( T_2 * ) & V_2 -> V_5 . V_275 . V_283 [ V_280 ] . V_284 ;
else
V_282 =
( T_2 * ) & V_2 -> V_5 . V_275 . V_283 [ V_280 ] . V_285 ;
* V_393 = * V_282 ;
}
return 0 ;
}
static int F_166 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_393 )
{
T_2 V_31 ;
T_2 V_286 = V_2 -> V_5 . V_286 ;
unsigned V_287 = V_286 & 0xff ;
switch ( V_21 ) {
case V_395 :
case V_396 :
V_31 = 0 ;
break;
case V_397 :
V_31 = V_2 -> V_5 . V_286 ;
break;
case V_290 :
if ( ! ( V_286 & V_291 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_292 ;
break;
case V_288 :
V_31 = V_2 -> V_5 . V_289 ;
break;
default:
if ( V_21 >= V_293 &&
V_21 < V_293 + 4 * V_287 ) {
T_1 V_74 = V_21 - V_293 ;
V_31 = V_2 -> V_5 . V_294 [ V_74 ] ;
break;
}
return 1 ;
}
* V_393 = V_31 ;
return 0 ;
}
static int F_167 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_393 )
{
T_2 V_31 = 0 ;
struct V_29 * V_29 = V_2 -> V_29 ;
switch ( V_21 ) {
case V_311 :
V_31 = V_29 -> V_5 . V_313 ;
break;
case V_312 :
V_31 = V_29 -> V_5 . V_309 ;
break;
default:
F_137 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_393 = V_31 ;
return 0 ;
}
static int F_168 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_393 )
{
T_2 V_31 = 0 ;
switch ( V_21 ) {
case V_398 : {
int V_99 ;
struct V_1 * V_210 ;
F_169 (r, v, vcpu->kvm)
if ( V_210 == V_2 )
V_31 = V_99 ;
break;
}
case V_323 :
return F_170 ( V_2 , V_324 , V_393 ) ;
case V_325 :
return F_170 ( V_2 , V_326 , V_393 ) ;
case V_327 :
return F_170 ( V_2 , V_328 , V_393 ) ;
case V_319 :
V_31 = V_2 -> V_5 . V_321 ;
break;
default:
F_137 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_393 = V_31 ;
return 0 ;
}
int F_171 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_393 )
{
T_2 V_31 ;
switch ( V_21 ) {
case V_399 :
case V_400 :
case V_349 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_405 :
case V_346 :
case V_354 :
case V_371 :
case V_375 :
case V_406 :
case V_348 :
case V_347 :
V_31 = 0 ;
break;
case V_379 :
case V_380 :
case V_381 :
case V_382 :
if ( F_159 ( V_2 , V_21 ) )
return F_172 ( V_2 , V_21 , V_393 ) ;
V_31 = 0 ;
break;
case V_352 :
V_31 = 0x100000000ULL ;
break;
case V_407 :
V_31 = 0x500 | V_259 ;
break;
case 0x200 ... 0x2ff :
return F_165 ( V_2 , V_21 , V_393 ) ;
case 0xcd :
V_31 = 3 ;
break;
case V_408 :
V_31 = 1 << 24 ;
break;
case V_356 :
V_31 = F_17 ( V_2 ) ;
break;
case V_357 ... V_357 + 0x3ff :
return F_173 ( V_2 , V_21 , V_393 ) ;
break;
case V_358 :
V_31 = F_174 ( V_2 ) ;
break;
case V_359 :
V_31 = V_2 -> V_5 . V_360 ;
break;
case V_409 :
V_31 = 1000ULL ;
V_31 |= ( ( ( T_7 ) 4ULL ) << 40 ) ;
break;
case V_345 :
V_31 = V_2 -> V_5 . V_110 ;
break;
case V_362 :
case V_361 :
V_31 = V_2 -> V_29 -> V_5 . V_182 ;
break;
case V_364 :
case V_363 :
V_31 = V_2 -> V_5 . time ;
break;
case V_365 :
V_31 = V_2 -> V_5 . V_6 . V_330 ;
break;
case V_366 :
V_31 = V_2 -> V_5 . V_334 . V_330 ;
break;
case V_395 :
case V_396 :
case V_397 :
case V_290 :
case V_288 :
case V_293 ... V_293 + 4 * V_370 - 1 :
return F_166 ( V_2 , V_21 , V_393 ) ;
case V_383 :
V_31 = 0x20000000 ;
break;
case V_311 ... V_384 :
if ( F_132 ( V_21 ) ) {
int V_99 ;
F_161 ( & V_2 -> V_29 -> V_385 ) ;
V_99 = F_167 ( V_2 , V_21 , V_393 ) ;
F_162 ( & V_2 -> V_29 -> V_385 ) ;
return V_99 ;
} else
return F_168 ( V_2 , V_21 , V_393 ) ;
break;
case V_386 :
V_31 = 0xbe702111 ;
break;
case V_387 :
if ( ! F_163 ( V_2 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_388 . V_389 ;
break;
case V_390 :
if ( ! F_163 ( V_2 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_388 . V_391 ;
break;
default:
if ( F_159 ( V_2 , V_21 ) )
return F_172 ( V_2 , V_21 , V_393 ) ;
if ( ! V_392 ) {
F_137 ( V_2 , L_19 , V_21 ) ;
return 1 ;
} else {
F_137 ( V_2 , L_20 , V_21 ) ;
V_31 = 0 ;
}
break;
}
* V_393 = V_31 ;
return 0 ;
}
static int F_175 ( struct V_1 * V_2 , struct V_410 * V_19 ,
struct V_411 * V_412 ,
int (* F_176)( struct V_1 * V_2 ,
unsigned V_117 , T_2 * V_31 ) )
{
int V_3 , V_280 ;
V_280 = F_177 ( & V_2 -> V_29 -> V_413 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_414 ; ++ V_3 )
if ( F_176 ( V_2 , V_412 [ V_3 ] . V_117 , & V_412 [ V_3 ] . V_31 ) )
break;
F_178 ( & V_2 -> V_29 -> V_413 , V_280 ) ;
return V_3 ;
}
static int F_179 ( struct V_1 * V_2 , struct V_410 V_318 * V_415 ,
int (* F_176)( struct V_1 * V_2 ,
unsigned V_117 , T_2 * V_31 ) ,
int V_416 )
{
struct V_410 V_19 ;
struct V_411 * V_412 ;
int V_99 , V_417 ;
unsigned V_418 ;
V_99 = - V_81 ;
if ( F_180 ( & V_19 , V_415 , sizeof V_19 ) )
goto V_93;
V_99 = - V_306 ;
if ( V_19 . V_414 >= V_419 )
goto V_93;
V_418 = sizeof( struct V_411 ) * V_19 . V_414 ;
V_412 = F_127 ( V_415 -> V_412 , V_418 ) ;
if ( F_128 ( V_412 ) ) {
V_99 = F_129 ( V_412 ) ;
goto V_93;
}
V_99 = V_417 = F_175 ( V_2 , & V_19 , V_412 , F_176 ) ;
if ( V_99 < 0 )
goto V_308;
V_99 = - V_81 ;
if ( V_416 && F_181 ( V_415 -> V_412 , V_412 , V_418 ) )
goto V_308;
V_99 = V_417 ;
V_308:
F_130 ( V_412 ) ;
V_93:
return V_99 ;
}
int F_182 ( long V_420 )
{
int V_99 ;
switch ( V_420 ) {
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
case V_437 :
case V_438 :
case V_439 :
case V_440 :
case V_441 :
case V_442 :
case V_443 :
case V_444 :
case V_445 :
case V_446 :
case V_447 :
case V_448 :
case V_449 :
case V_450 :
case V_451 :
case V_452 :
V_99 = 1 ;
break;
case V_453 :
V_99 = V_454 ;
break;
case V_455 :
V_99 = ! V_56 -> V_456 () ;
break;
case V_457 :
V_99 = V_458 ;
break;
case V_459 :
V_99 = V_460 ;
break;
case V_461 :
V_99 = V_462 ;
break;
case V_463 :
V_99 = 0 ;
break;
case V_464 :
V_99 = F_183 ( & V_465 ) ;
break;
case V_466 :
V_99 = V_370 ;
break;
case V_467 :
V_99 = V_468 ;
break;
case V_469 :
V_99 = V_470 ;
break;
case V_471 :
V_99 = F_184 ( V_472 ) ;
break;
default:
V_99 = 0 ;
break;
}
return V_99 ;
}
long F_185 ( struct V_473 * V_474 ,
unsigned int V_475 , unsigned long V_476 )
{
void V_318 * V_477 = ( void V_318 * ) V_476 ;
long V_99 ;
switch ( V_475 ) {
case V_478 : {
struct V_479 V_318 * V_480 = V_477 ;
struct V_479 V_481 ;
unsigned V_417 ;
V_99 = - V_81 ;
if ( F_180 ( & V_481 , V_480 , sizeof V_481 ) )
goto V_93;
V_417 = V_481 . V_414 ;
V_481 . V_414 = V_482 + F_42 ( V_483 ) ;
if ( F_181 ( V_480 , & V_481 , sizeof V_481 ) )
goto V_93;
V_99 = - V_306 ;
if ( V_417 < V_481 . V_414 )
goto V_93;
V_99 = - V_81 ;
if ( F_181 ( V_480 -> V_484 , & V_485 ,
V_482 * sizeof( T_1 ) ) )
goto V_93;
if ( F_181 ( V_480 -> V_484 + V_482 ,
& V_483 ,
F_42 ( V_483 ) * sizeof( T_1 ) ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_486 : {
struct V_487 V_318 * V_488 = V_477 ;
struct V_487 V_489 ;
V_99 = - V_81 ;
if ( F_180 ( & V_489 , V_488 , sizeof V_489 ) )
goto V_93;
V_99 = F_186 ( & V_489 ,
V_488 -> V_412 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_181 ( V_488 , & V_489 , sizeof V_489 ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_490 : {
T_2 V_491 ;
V_491 = V_492 ;
V_99 = - V_81 ;
if ( F_181 ( V_477 , & V_491 , sizeof V_491 ) )
goto V_93;
V_99 = 0 ;
break;
}
default:
V_99 = - V_493 ;
}
V_93:
return V_99 ;
}
static void F_187 ( void * V_494 )
{
F_188 () ;
}
static bool F_189 ( struct V_1 * V_2 )
{
return V_2 -> V_29 -> V_5 . V_495 &&
! ( V_2 -> V_29 -> V_5 . V_496 & V_497 ) ;
}
void F_190 ( struct V_1 * V_2 , int V_498 )
{
if ( F_189 ( V_2 ) ) {
if ( V_56 -> V_499 () )
F_191 ( V_498 , V_2 -> V_5 . V_500 ) ;
else if ( V_2 -> V_498 != - 1 && V_2 -> V_498 != V_498 )
F_192 ( V_2 -> V_498 ,
F_187 , NULL , 1 ) ;
}
V_56 -> V_501 ( V_2 , V_498 ) ;
if ( F_69 ( V_2 -> V_5 . V_502 ) ) {
F_193 ( V_2 , V_2 -> V_5 . V_502 ) ;
V_2 -> V_5 . V_502 = 0 ;
F_194 ( V_249 , & V_2 -> V_503 ) ;
}
if ( F_69 ( V_2 -> V_498 != V_498 ) || F_111 () ) {
T_10 V_504 = ! V_2 -> V_5 . V_505 ? 0 :
F_195 () - V_2 -> V_5 . V_505 ;
if ( V_504 < 0 )
F_196 ( L_21 ) ;
if ( F_111 () ) {
T_2 V_74 = V_56 -> V_229 ( V_2 ,
V_2 -> V_5 . V_241 ) ;
V_56 -> V_243 ( V_2 , V_74 ) ;
V_2 -> V_5 . V_250 = 1 ;
}
F_23 ( V_249 , V_2 ) ;
if ( V_2 -> V_498 != V_498 )
F_197 ( V_2 ) ;
V_2 -> V_498 = V_498 ;
}
F_146 ( V_2 ) ;
F_23 ( V_369 , V_2 ) ;
}
void F_198 ( struct V_1 * V_2 )
{
V_56 -> V_506 ( V_2 ) ;
F_199 ( V_2 ) ;
V_2 -> V_5 . V_505 = F_195 () ;
}
static int F_200 ( struct V_1 * V_2 ,
struct V_507 * V_508 )
{
memcpy ( V_508 -> V_509 , V_2 -> V_5 . V_510 -> V_509 , sizeof *V_508 ) ;
return 0 ;
}
static int F_201 ( struct V_1 * V_2 ,
struct V_507 * V_508 )
{
memcpy ( V_2 -> V_5 . V_510 -> V_509 , V_508 -> V_509 , sizeof *V_508 ) ;
F_202 ( V_2 ) ;
F_203 ( V_2 ) ;
return 0 ;
}
static int F_204 ( struct V_1 * V_2 ,
struct V_511 * V_512 )
{
if ( V_512 -> V_512 < 0 || V_512 -> V_512 >= 256 )
return - V_493 ;
if ( F_18 ( V_2 -> V_29 ) )
return - V_513 ;
F_205 ( V_2 , V_512 -> V_512 , false ) ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
static int F_206 ( struct V_1 * V_2 )
{
F_32 ( V_2 ) ;
return 0 ;
}
static int F_207 ( struct V_1 * V_2 ,
struct V_514 * V_515 )
{
if ( V_515 -> V_226 )
return - V_493 ;
V_2 -> V_5 . V_516 = ! ! V_515 -> V_278 ;
return 0 ;
}
static int F_208 ( struct V_1 * V_2 ,
T_2 V_286 )
{
int V_99 ;
unsigned V_287 = V_286 & 0xff , V_517 ;
V_99 = - V_493 ;
if ( ! V_287 || V_287 >= V_370 )
goto V_93;
if ( V_286 & ~ ( V_492 | 0xff | 0xff0000 ) )
goto V_93;
V_99 = 0 ;
V_2 -> V_5 . V_286 = V_286 ;
if ( V_286 & V_291 )
V_2 -> V_5 . V_292 = ~ ( T_2 ) 0 ;
for ( V_517 = 0 ; V_517 < V_287 ; V_517 ++ )
V_2 -> V_5 . V_294 [ V_517 * 4 ] = ~ ( T_2 ) 0 ;
V_93:
return V_99 ;
}
static int F_209 ( struct V_1 * V_2 ,
struct V_518 * V_519 )
{
T_2 V_286 = V_2 -> V_5 . V_286 ;
unsigned V_287 = V_286 & 0xff ;
T_2 * V_520 = V_2 -> V_5 . V_294 ;
if ( V_519 -> V_517 >= V_287 || ! ( V_519 -> V_391 & V_521 ) )
return - V_493 ;
if ( ( V_519 -> V_391 & V_522 ) && ( V_286 & V_291 ) &&
V_2 -> V_5 . V_292 != ~ ( T_2 ) 0 )
return 0 ;
V_520 += 4 * V_519 -> V_517 ;
if ( ( V_519 -> V_391 & V_522 ) && V_520 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_519 -> V_391 & V_522 ) {
if ( ( V_2 -> V_5 . V_289 & V_523 ) ||
! F_76 ( V_2 , V_524 ) ) {
F_23 ( V_54 , V_2 ) ;
return 0 ;
}
if ( V_520 [ 1 ] & V_521 )
V_519 -> V_391 |= V_525 ;
V_520 [ 2 ] = V_519 -> V_314 ;
V_520 [ 3 ] = V_519 -> V_526 ;
V_2 -> V_5 . V_289 = V_519 -> V_289 ;
V_520 [ 1 ] = V_519 -> V_391 ;
F_24 ( V_2 , V_527 ) ;
} else if ( ! ( V_520 [ 1 ] & V_521 )
|| ! ( V_520 [ 1 ] & V_522 ) ) {
if ( V_520 [ 1 ] & V_521 )
V_519 -> V_391 |= V_525 ;
V_520 [ 2 ] = V_519 -> V_314 ;
V_520 [ 3 ] = V_519 -> V_526 ;
V_520 [ 1 ] = V_519 -> V_391 ;
} else
V_520 [ 1 ] |= V_525 ;
return 0 ;
}
static void F_210 ( struct V_1 * V_2 ,
struct V_528 * V_529 )
{
F_211 ( V_2 ) ;
V_529 -> V_49 . V_530 =
V_2 -> V_5 . V_49 . V_50 &&
! F_212 ( V_2 -> V_5 . V_49 . V_16 ) ;
V_529 -> V_49 . V_16 = V_2 -> V_5 . V_49 . V_16 ;
V_529 -> V_49 . V_52 = V_2 -> V_5 . V_49 . V_52 ;
V_529 -> V_49 . V_531 = 0 ;
V_529 -> V_49 . V_43 = V_2 -> V_5 . V_49 . V_43 ;
V_529 -> V_532 . V_530 =
V_2 -> V_5 . V_532 . V_50 && ! V_2 -> V_5 . V_532 . V_533 ;
V_529 -> V_532 . V_16 = V_2 -> V_5 . V_532 . V_16 ;
V_529 -> V_532 . V_533 = 0 ;
V_529 -> V_532 . V_534 =
V_56 -> V_535 ( V_2 ,
V_536 | V_537 ) ;
V_529 -> V_538 . V_530 = V_2 -> V_5 . V_539 ;
V_529 -> V_538 . V_50 = V_2 -> V_5 . V_540 != 0 ;
V_529 -> V_538 . V_541 = V_56 -> V_542 ( V_2 ) ;
V_529 -> V_538 . V_531 = 0 ;
V_529 -> V_543 = V_2 -> V_5 . V_543 ;
V_529 -> V_226 = ( V_544
| V_545
| V_546 ) ;
memset ( & V_529 -> V_547 , 0 , sizeof( V_529 -> V_547 ) ) ;
}
static int F_213 ( struct V_1 * V_2 ,
struct V_528 * V_529 )
{
if ( V_529 -> V_226 & ~ ( V_544
| V_545
| V_546 ) )
return - V_493 ;
F_211 ( V_2 ) ;
V_2 -> V_5 . V_49 . V_50 = V_529 -> V_49 . V_530 ;
V_2 -> V_5 . V_49 . V_16 = V_529 -> V_49 . V_16 ;
V_2 -> V_5 . V_49 . V_52 = V_529 -> V_49 . V_52 ;
V_2 -> V_5 . V_49 . V_43 = V_529 -> V_49 . V_43 ;
V_2 -> V_5 . V_532 . V_50 = V_529 -> V_532 . V_530 ;
V_2 -> V_5 . V_532 . V_16 = V_529 -> V_532 . V_16 ;
V_2 -> V_5 . V_532 . V_533 = V_529 -> V_532 . V_533 ;
if ( V_529 -> V_226 & V_546 )
V_56 -> V_548 ( V_2 ,
V_529 -> V_532 . V_534 ) ;
V_2 -> V_5 . V_539 = V_529 -> V_538 . V_530 ;
if ( V_529 -> V_226 & V_544 )
V_2 -> V_5 . V_540 = V_529 -> V_538 . V_50 ;
V_56 -> V_549 ( V_2 , V_529 -> V_538 . V_541 ) ;
if ( V_529 -> V_226 & V_545 )
V_2 -> V_5 . V_543 = V_529 -> V_543 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
static void F_214 ( struct V_1 * V_2 ,
struct V_550 * V_551 )
{
memcpy ( V_551 -> V_146 , V_2 -> V_5 . V_146 , sizeof( V_2 -> V_5 . V_146 ) ) ;
V_551 -> V_151 = V_2 -> V_5 . V_151 ;
V_551 -> V_154 = V_2 -> V_5 . V_154 ;
V_551 -> V_226 = 0 ;
memset ( & V_551 -> V_547 , 0 , sizeof( V_551 -> V_547 ) ) ;
}
static int F_215 ( struct V_1 * V_2 ,
struct V_550 * V_551 )
{
if ( V_551 -> V_226 )
return - V_493 ;
memcpy ( V_2 -> V_5 . V_146 , V_551 -> V_146 , sizeof( V_2 -> V_5 . V_146 ) ) ;
V_2 -> V_5 . V_151 = V_551 -> V_151 ;
V_2 -> V_5 . V_154 = V_551 -> V_154 ;
return 0 ;
}
static void F_216 ( struct V_1 * V_2 ,
struct V_552 * V_553 )
{
if ( V_468 )
memcpy ( V_553 -> V_554 ,
& V_2 -> V_5 . V_555 . V_556 -> V_557 ,
V_558 ) ;
else {
memcpy ( V_553 -> V_554 ,
& V_2 -> V_5 . V_555 . V_556 -> V_559 ,
sizeof( struct V_560 ) ) ;
* ( T_2 * ) & V_553 -> V_554 [ V_561 / sizeof( T_1 ) ] =
V_562 ;
}
}
static int F_217 ( struct V_1 * V_2 ,
struct V_552 * V_553 )
{
T_2 V_563 =
* ( T_2 * ) & V_553 -> V_554 [ V_561 / sizeof( T_1 ) ] ;
if ( V_468 )
memcpy ( & V_2 -> V_5 . V_555 . V_556 -> V_557 ,
V_553 -> V_554 , V_558 ) ;
else {
if ( V_563 & ~ V_562 )
return - V_493 ;
memcpy ( & V_2 -> V_5 . V_555 . V_556 -> V_559 ,
V_553 -> V_554 , sizeof( struct V_560 ) ) ;
}
return 0 ;
}
static void F_218 ( struct V_1 * V_2 ,
struct V_564 * V_565 )
{
if ( ! V_468 ) {
V_565 -> V_566 = 0 ;
return;
}
V_565 -> V_566 = 1 ;
V_565 -> V_226 = 0 ;
V_565 -> V_567 [ 0 ] . V_118 = V_120 ;
V_565 -> V_567 [ 0 ] . V_23 = V_2 -> V_5 . V_119 ;
}
static int F_219 ( struct V_1 * V_2 ,
struct V_564 * V_565 )
{
int V_3 , V_99 = 0 ;
if ( ! V_468 )
return - V_493 ;
if ( V_565 -> V_566 > V_568 || V_565 -> V_226 )
return - V_493 ;
for ( V_3 = 0 ; V_3 < V_565 -> V_566 ; V_3 ++ )
if ( V_565 -> V_567 [ 0 ] . V_118 == V_120 ) {
V_99 = F_58 ( V_2 , V_120 ,
V_565 -> V_567 [ 0 ] . V_23 ) ;
break;
}
if ( V_99 )
V_99 = - V_493 ;
return V_99 ;
}
long F_220 ( struct V_473 * V_474 ,
unsigned int V_475 , unsigned long V_476 )
{
struct V_1 * V_2 = V_474 -> V_569 ;
void V_318 * V_477 = ( void V_318 * ) V_476 ;
int V_99 ;
union {
struct V_507 * V_570 ;
struct V_552 * V_557 ;
struct V_564 * V_567 ;
void * V_571 ;
} V_572 ;
V_572 . V_571 = NULL ;
switch ( V_475 ) {
case V_573 : {
V_99 = - V_493 ;
if ( ! V_2 -> V_5 . V_510 )
goto V_93;
V_572 . V_570 = F_221 ( sizeof( struct V_507 ) , V_574 ) ;
V_99 = - V_307 ;
if ( ! V_572 . V_570 )
goto V_93;
V_99 = F_200 ( V_2 , V_572 . V_570 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_181 ( V_477 , V_572 . V_570 , sizeof( struct V_507 ) ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_575 : {
V_99 = - V_493 ;
if ( ! V_2 -> V_5 . V_510 )
goto V_93;
V_572 . V_570 = F_127 ( V_477 , sizeof( * V_572 . V_570 ) ) ;
if ( F_128 ( V_572 . V_570 ) ) {
V_99 = F_129 ( V_572 . V_570 ) ;
goto V_93;
}
V_99 = F_201 ( V_2 , V_572 . V_570 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_576 : {
struct V_511 V_512 ;
V_99 = - V_81 ;
if ( F_180 ( & V_512 , V_477 , sizeof V_512 ) )
goto V_93;
V_99 = F_204 ( V_2 , & V_512 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_577 : {
V_99 = F_206 ( V_2 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_578 : {
struct V_579 V_318 * V_488 = V_477 ;
struct V_579 V_489 ;
V_99 = - V_81 ;
if ( F_180 ( & V_489 , V_488 , sizeof V_489 ) )
goto V_93;
V_99 = F_222 ( V_2 , & V_489 , V_488 -> V_412 ) ;
if ( V_99 )
goto V_93;
break;
}
case V_580 : {
struct V_487 V_318 * V_488 = V_477 ;
struct V_487 V_489 ;
V_99 = - V_81 ;
if ( F_180 ( & V_489 , V_488 , sizeof V_489 ) )
goto V_93;
V_99 = F_223 ( V_2 , & V_489 ,
V_488 -> V_412 ) ;
if ( V_99 )
goto V_93;
break;
}
case V_581 : {
struct V_487 V_318 * V_488 = V_477 ;
struct V_487 V_489 ;
V_99 = - V_81 ;
if ( F_180 ( & V_489 , V_488 , sizeof V_489 ) )
goto V_93;
V_99 = F_224 ( V_2 , & V_489 ,
V_488 -> V_412 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_181 ( V_488 , & V_489 , sizeof V_489 ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_582 :
V_99 = F_179 ( V_2 , V_477 , F_164 , 1 ) ;
break;
case V_583 :
V_99 = F_179 ( V_2 , V_477 , F_89 , 0 ) ;
break;
case V_584 : {
struct V_514 V_515 ;
V_99 = - V_81 ;
if ( F_180 ( & V_515 , V_477 , sizeof V_515 ) )
goto V_93;
V_99 = F_207 ( V_2 , & V_515 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_181 ( V_477 , & V_515 , sizeof V_515 ) )
goto V_93;
V_99 = 0 ;
break;
} ;
case V_585 : {
struct V_586 V_587 ;
V_99 = - V_493 ;
if ( ! F_18 ( V_2 -> V_29 ) )
goto V_93;
V_99 = - V_81 ;
if ( F_180 ( & V_587 , V_477 , sizeof V_587 ) )
goto V_93;
V_99 = 0 ;
F_225 ( V_2 , V_587 . V_588 ) ;
break;
}
case V_589 : {
T_2 V_286 ;
V_99 = - V_81 ;
if ( F_180 ( & V_286 , V_477 , sizeof V_286 ) )
goto V_93;
V_99 = F_208 ( V_2 , V_286 ) ;
break;
}
case V_590 : {
struct V_518 V_519 ;
V_99 = - V_81 ;
if ( F_180 ( & V_519 , V_477 , sizeof V_519 ) )
goto V_93;
V_99 = F_209 ( V_2 , & V_519 ) ;
break;
}
case V_591 : {
struct V_528 V_529 ;
F_210 ( V_2 , & V_529 ) ;
V_99 = - V_81 ;
if ( F_181 ( V_477 , & V_529 , sizeof( struct V_528 ) ) )
break;
V_99 = 0 ;
break;
}
case V_592 : {
struct V_528 V_529 ;
V_99 = - V_81 ;
if ( F_180 ( & V_529 , V_477 , sizeof( struct V_528 ) ) )
break;
V_99 = F_213 ( V_2 , & V_529 ) ;
break;
}
case V_593 : {
struct V_550 V_551 ;
F_214 ( V_2 , & V_551 ) ;
V_99 = - V_81 ;
if ( F_181 ( V_477 , & V_551 ,
sizeof( struct V_550 ) ) )
break;
V_99 = 0 ;
break;
}
case V_594 : {
struct V_550 V_551 ;
V_99 = - V_81 ;
if ( F_180 ( & V_551 , V_477 ,
sizeof( struct V_550 ) ) )
break;
V_99 = F_215 ( V_2 , & V_551 ) ;
break;
}
case V_595 : {
V_572 . V_557 = F_221 ( sizeof( struct V_552 ) , V_574 ) ;
V_99 = - V_307 ;
if ( ! V_572 . V_557 )
break;
F_216 ( V_2 , V_572 . V_557 ) ;
V_99 = - V_81 ;
if ( F_181 ( V_477 , V_572 . V_557 , sizeof( struct V_552 ) ) )
break;
V_99 = 0 ;
break;
}
case V_596 : {
V_572 . V_557 = F_127 ( V_477 , sizeof( * V_572 . V_557 ) ) ;
if ( F_128 ( V_572 . V_557 ) ) {
V_99 = F_129 ( V_572 . V_557 ) ;
goto V_93;
}
V_99 = F_217 ( V_2 , V_572 . V_557 ) ;
break;
}
case V_597 : {
V_572 . V_567 = F_221 ( sizeof( struct V_564 ) , V_574 ) ;
V_99 = - V_307 ;
if ( ! V_572 . V_567 )
break;
F_218 ( V_2 , V_572 . V_567 ) ;
V_99 = - V_81 ;
if ( F_181 ( V_477 , V_572 . V_567 ,
sizeof( struct V_564 ) ) )
break;
V_99 = 0 ;
break;
}
case V_598 : {
V_572 . V_567 = F_127 ( V_477 , sizeof( * V_572 . V_567 ) ) ;
if ( F_128 ( V_572 . V_567 ) ) {
V_99 = F_129 ( V_572 . V_567 ) ;
goto V_93;
}
V_99 = F_219 ( V_2 , V_572 . V_567 ) ;
break;
}
case V_599 : {
T_1 V_600 ;
V_99 = - V_493 ;
V_600 = ( T_1 ) V_476 ;
if ( V_600 >= V_601 )
goto V_93;
if ( V_600 == 0 )
V_600 = V_217 ;
F_107 ( V_2 , V_600 ) ;
V_99 = 0 ;
goto V_93;
}
case V_602 : {
V_99 = V_2 -> V_5 . V_216 ;
goto V_93;
}
default:
V_99 = - V_493 ;
}
V_93:
F_130 ( V_572 . V_571 ) ;
return V_99 ;
}
int F_226 ( struct V_1 * V_2 , struct V_603 * V_604 )
{
return V_605 ;
}
static int F_227 ( struct V_29 * V_29 , unsigned long V_314 )
{
int V_88 ;
if ( V_314 > ( unsigned int ) ( - 3 * V_87 ) )
return - 1 ;
V_88 = V_56 -> V_606 ( V_29 , V_314 ) ;
return V_88 ;
}
static int F_228 ( struct V_29 * V_29 ,
T_2 V_607 )
{
V_29 -> V_5 . V_608 = V_607 ;
return 0 ;
}
static int F_229 ( struct V_29 * V_29 ,
T_1 V_609 )
{
if ( V_609 < V_610 )
return - V_493 ;
F_161 ( & V_29 -> V_611 ) ;
F_230 ( & V_29 -> V_612 ) ;
F_231 ( V_29 , V_609 ) ;
V_29 -> V_5 . V_613 = V_609 ;
F_232 ( & V_29 -> V_612 ) ;
F_162 ( & V_29 -> V_611 ) ;
return 0 ;
}
static int F_233 ( struct V_29 * V_29 )
{
return V_29 -> V_5 . V_614 ;
}
static int F_234 ( struct V_29 * V_29 , struct V_615 * V_616 )
{
int V_99 ;
V_99 = 0 ;
switch ( V_616 -> V_617 ) {
case V_618 :
memcpy ( & V_616 -> V_616 . V_619 ,
& F_235 ( V_29 ) -> V_620 [ 0 ] ,
sizeof( struct V_621 ) ) ;
break;
case V_622 :
memcpy ( & V_616 -> V_616 . V_619 ,
& F_235 ( V_29 ) -> V_620 [ 1 ] ,
sizeof( struct V_621 ) ) ;
break;
case V_623 :
V_99 = F_236 ( V_29 , & V_616 -> V_616 . V_624 ) ;
break;
default:
V_99 = - V_493 ;
break;
}
return V_99 ;
}
static int F_237 ( struct V_29 * V_29 , struct V_615 * V_616 )
{
int V_99 ;
V_99 = 0 ;
switch ( V_616 -> V_617 ) {
case V_618 :
F_230 ( & F_235 ( V_29 ) -> V_385 ) ;
memcpy ( & F_235 ( V_29 ) -> V_620 [ 0 ] ,
& V_616 -> V_616 . V_619 ,
sizeof( struct V_621 ) ) ;
F_232 ( & F_235 ( V_29 ) -> V_385 ) ;
break;
case V_622 :
F_230 ( & F_235 ( V_29 ) -> V_385 ) ;
memcpy ( & F_235 ( V_29 ) -> V_620 [ 1 ] ,
& V_616 -> V_616 . V_619 ,
sizeof( struct V_621 ) ) ;
F_232 ( & F_235 ( V_29 ) -> V_385 ) ;
break;
case V_623 :
V_99 = F_238 ( V_29 , & V_616 -> V_616 . V_624 ) ;
break;
default:
V_99 = - V_493 ;
break;
}
F_239 ( F_235 ( V_29 ) ) ;
return V_99 ;
}
static int F_240 ( struct V_29 * V_29 , struct V_625 * V_626 )
{
int V_99 = 0 ;
F_161 ( & V_29 -> V_5 . V_627 -> V_628 . V_385 ) ;
memcpy ( V_626 , & V_29 -> V_5 . V_627 -> V_628 , sizeof( struct V_625 ) ) ;
F_162 ( & V_29 -> V_5 . V_627 -> V_628 . V_385 ) ;
return V_99 ;
}
static int F_241 ( struct V_29 * V_29 , struct V_625 * V_626 )
{
int V_99 = 0 ;
F_161 ( & V_29 -> V_5 . V_627 -> V_628 . V_385 ) ;
memcpy ( & V_29 -> V_5 . V_627 -> V_628 , V_626 , sizeof( struct V_625 ) ) ;
F_242 ( V_29 , 0 , V_626 -> V_629 [ 0 ] . V_630 , 0 ) ;
F_162 ( & V_29 -> V_5 . V_627 -> V_628 . V_385 ) ;
return V_99 ;
}
static int F_243 ( struct V_29 * V_29 , struct V_631 * V_626 )
{
int V_99 = 0 ;
F_161 ( & V_29 -> V_5 . V_627 -> V_628 . V_385 ) ;
memcpy ( V_626 -> V_629 , & V_29 -> V_5 . V_627 -> V_628 . V_629 ,
sizeof( V_626 -> V_629 ) ) ;
V_626 -> V_226 = V_29 -> V_5 . V_627 -> V_628 . V_226 ;
F_162 ( & V_29 -> V_5 . V_627 -> V_628 . V_385 ) ;
memset ( & V_626 -> V_547 , 0 , sizeof( V_626 -> V_547 ) ) ;
return V_99 ;
}
static int F_244 ( struct V_29 * V_29 , struct V_631 * V_626 )
{
int V_99 = 0 , V_632 = 0 ;
T_1 V_633 , V_634 ;
F_161 ( & V_29 -> V_5 . V_627 -> V_628 . V_385 ) ;
V_633 = V_29 -> V_5 . V_627 -> V_628 . V_226 & V_635 ;
V_634 = V_626 -> V_226 & V_635 ;
if ( ! V_633 && V_634 )
V_632 = 1 ;
memcpy ( & V_29 -> V_5 . V_627 -> V_628 . V_629 , & V_626 -> V_629 ,
sizeof( V_29 -> V_5 . V_627 -> V_628 . V_629 ) ) ;
V_29 -> V_5 . V_627 -> V_628 . V_226 = V_626 -> V_226 ;
F_242 ( V_29 , 0 , V_29 -> V_5 . V_627 -> V_628 . V_629 [ 0 ] . V_630 , V_632 ) ;
F_162 ( & V_29 -> V_5 . V_627 -> V_628 . V_385 ) ;
return V_99 ;
}
static int F_245 ( struct V_29 * V_29 ,
struct V_636 * V_637 )
{
if ( ! V_29 -> V_5 . V_627 )
return - V_513 ;
F_161 ( & V_29 -> V_5 . V_627 -> V_628 . V_385 ) ;
V_29 -> V_5 . V_627 -> V_628 . V_638 . V_44 = V_637 -> V_639 ;
F_162 ( & V_29 -> V_5 . V_627 -> V_628 . V_385 ) ;
return 0 ;
}
static void F_246 ( struct V_29 * V_29 ,
struct V_640 * V_641 ,
unsigned long * V_642 ,
unsigned long V_643 )
{
F_230 ( & V_29 -> V_612 ) ;
if ( V_643 < V_29 -> V_5 . V_644 ) {
unsigned long V_645 ;
F_247 (gfn_offset, dirty_bitmap, memslot->npages) {
unsigned long V_82 = V_641 -> V_646 + V_645 ;
F_248 ( V_29 , V_82 , V_641 ) ;
}
F_249 ( V_29 ) ;
} else
F_250 ( V_29 , V_641 -> V_647 ) ;
F_232 ( & V_29 -> V_612 ) ;
}
int F_251 ( struct V_29 * V_29 ,
struct V_648 * log )
{
int V_99 ;
struct V_640 * V_641 ;
unsigned long V_417 , V_643 ;
F_161 ( & V_29 -> V_611 ) ;
V_99 = - V_493 ;
if ( log -> V_10 >= V_462 )
goto V_93;
V_641 = F_252 ( V_29 -> V_649 , log -> V_10 ) ;
V_99 = - V_650 ;
if ( ! V_641 -> V_642 )
goto V_93;
V_417 = F_253 ( V_641 ) ;
V_643 = V_641 -> V_643 ;
if ( V_643 ) {
struct V_651 * V_652 , * V_653 ;
unsigned long * V_642 , * V_654 ;
V_642 = V_641 -> V_642 ;
V_654 = V_641 -> V_654 ;
if ( V_642 == V_654 )
V_654 += V_417 / sizeof( long ) ;
memset ( V_654 , 0 , V_417 ) ;
V_99 = - V_307 ;
V_652 = F_254 ( V_29 -> V_649 , sizeof( * V_29 -> V_649 ) , V_574 ) ;
if ( ! V_652 )
goto V_93;
V_641 = F_252 ( V_652 , log -> V_10 ) ;
V_641 -> V_643 = 0 ;
V_641 -> V_642 = V_654 ;
F_255 ( V_652 , NULL ) ;
V_653 = V_29 -> V_649 ;
F_256 ( V_29 -> V_649 , V_652 ) ;
F_257 ( & V_29 -> V_413 ) ;
F_130 ( V_653 ) ;
F_246 ( V_29 , V_641 , V_642 , V_643 ) ;
V_99 = - V_81 ;
if ( F_181 ( log -> V_642 , V_642 , V_417 ) )
goto V_93;
} else {
V_99 = - V_81 ;
if ( F_258 ( log -> V_642 , V_417 ) )
goto V_93;
}
V_99 = 0 ;
V_93:
F_162 ( & V_29 -> V_611 ) ;
return V_99 ;
}
long F_259 ( struct V_473 * V_474 ,
unsigned int V_475 , unsigned long V_476 )
{
struct V_29 * V_29 = V_474 -> V_569 ;
void V_318 * V_477 = ( void V_318 * ) V_476 ;
int V_99 = - V_655 ;
union {
struct V_625 V_626 ;
struct V_631 V_656 ;
struct V_657 V_658 ;
} V_572 ;
switch ( V_475 ) {
case V_659 :
V_99 = F_227 ( V_29 , V_476 ) ;
if ( V_99 < 0 )
goto V_93;
break;
case V_660 : {
T_2 V_607 ;
V_99 = - V_81 ;
if ( F_180 ( & V_607 , V_477 , sizeof V_607 ) )
goto V_93;
V_99 = F_228 ( V_29 , V_607 ) ;
if ( V_99 < 0 )
goto V_93;
break;
}
case V_661 :
V_99 = F_229 ( V_29 , V_476 ) ;
if ( V_99 )
goto V_93;
break;
case V_662 :
V_99 = F_233 ( V_29 ) ;
break;
case V_663 : {
struct V_664 * V_665 ;
F_161 ( & V_29 -> V_385 ) ;
V_99 = - V_666 ;
if ( V_29 -> V_5 . V_665 )
goto V_667;
V_99 = - V_493 ;
if ( F_260 ( & V_29 -> V_668 ) )
goto V_667;
V_99 = - V_307 ;
V_665 = F_261 ( V_29 ) ;
if ( V_665 ) {
V_99 = F_262 ( V_29 ) ;
if ( V_99 ) {
F_161 ( & V_29 -> V_611 ) ;
F_263 ( V_29 , V_669 ,
& V_665 -> V_670 ) ;
F_263 ( V_29 , V_669 ,
& V_665 -> V_671 ) ;
F_263 ( V_29 , V_669 ,
& V_665 -> V_672 ) ;
F_162 ( & V_29 -> V_611 ) ;
F_130 ( V_665 ) ;
goto V_667;
}
} else
goto V_667;
F_12 () ;
V_29 -> V_5 . V_665 = V_665 ;
F_12 () ;
V_99 = F_264 ( V_29 ) ;
if ( V_99 ) {
F_161 ( & V_29 -> V_611 ) ;
F_161 ( & V_29 -> V_673 ) ;
F_265 ( V_29 ) ;
F_266 ( V_29 ) ;
F_162 ( & V_29 -> V_673 ) ;
F_162 ( & V_29 -> V_611 ) ;
}
V_667:
F_162 ( & V_29 -> V_385 ) ;
break;
}
case V_674 :
V_572 . V_658 . V_226 = V_675 ;
goto V_676;
case V_677 :
V_99 = - V_81 ;
if ( F_180 ( & V_572 . V_658 , V_477 ,
sizeof( struct V_657 ) ) )
goto V_93;
V_676:
F_161 ( & V_29 -> V_611 ) ;
V_99 = - V_666 ;
if ( V_29 -> V_5 . V_627 )
goto V_678;
V_99 = - V_307 ;
V_29 -> V_5 . V_627 = F_267 ( V_29 , V_572 . V_658 . V_226 ) ;
if ( V_29 -> V_5 . V_627 )
V_99 = 0 ;
V_678:
F_162 ( & V_29 -> V_611 ) ;
break;
case V_679 :
case V_680 : {
struct V_681 V_682 ;
V_99 = - V_81 ;
if ( F_180 ( & V_682 , V_477 , sizeof V_682 ) )
goto V_93;
V_99 = - V_513 ;
if ( F_18 ( V_29 ) ) {
T_12 V_391 ;
V_391 = F_268 ( V_29 , V_683 ,
V_682 . V_512 , V_682 . V_684 ) ;
if ( V_475 == V_679 ) {
V_99 = - V_81 ;
V_682 . V_391 = V_391 ;
if ( F_181 ( V_477 , & V_682 ,
sizeof V_682 ) )
goto V_93;
}
V_99 = 0 ;
}
break;
}
case V_685 : {
struct V_615 * V_616 ;
V_616 = F_127 ( V_477 , sizeof( * V_616 ) ) ;
if ( F_128 ( V_616 ) ) {
V_99 = F_129 ( V_616 ) ;
goto V_93;
}
V_99 = - V_513 ;
if ( ! F_18 ( V_29 ) )
goto V_686;
V_99 = F_234 ( V_29 , V_616 ) ;
if ( V_99 )
goto V_686;
V_99 = - V_81 ;
if ( F_181 ( V_477 , V_616 , sizeof *V_616 ) )
goto V_686;
V_99 = 0 ;
V_686:
F_130 ( V_616 ) ;
if ( V_99 )
goto V_93;
break;
}
case V_687 : {
struct V_615 * V_616 ;
V_616 = F_127 ( V_477 , sizeof( * V_616 ) ) ;
if ( F_128 ( V_616 ) ) {
V_99 = F_129 ( V_616 ) ;
goto V_93;
}
V_99 = - V_513 ;
if ( ! F_18 ( V_29 ) )
goto V_688;
V_99 = F_237 ( V_29 , V_616 ) ;
if ( V_99 )
goto V_688;
V_99 = 0 ;
V_688:
F_130 ( V_616 ) ;
if ( V_99 )
goto V_93;
break;
}
case V_689 : {
V_99 = - V_81 ;
if ( F_180 ( & V_572 . V_626 , V_477 , sizeof( struct V_625 ) ) )
goto V_93;
V_99 = - V_513 ;
if ( ! V_29 -> V_5 . V_627 )
goto V_93;
V_99 = F_240 ( V_29 , & V_572 . V_626 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_181 ( V_477 , & V_572 . V_626 , sizeof( struct V_625 ) ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_690 : {
V_99 = - V_81 ;
if ( F_180 ( & V_572 . V_626 , V_477 , sizeof V_572 . V_626 ) )
goto V_93;
V_99 = - V_513 ;
if ( ! V_29 -> V_5 . V_627 )
goto V_93;
V_99 = F_241 ( V_29 , & V_572 . V_626 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_691 : {
V_99 = - V_513 ;
if ( ! V_29 -> V_5 . V_627 )
goto V_93;
V_99 = F_243 ( V_29 , & V_572 . V_656 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_181 ( V_477 , & V_572 . V_656 , sizeof( V_572 . V_656 ) ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_692 : {
V_99 = - V_81 ;
if ( F_180 ( & V_572 . V_656 , V_477 , sizeof( V_572 . V_656 ) ) )
goto V_93;
V_99 = - V_513 ;
if ( ! V_29 -> V_5 . V_627 )
goto V_93;
V_99 = F_244 ( V_29 , & V_572 . V_656 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_693 : {
struct V_636 V_637 ;
V_99 = - V_81 ;
if ( F_180 ( & V_637 , V_477 , sizeof( V_637 ) ) )
goto V_93;
V_99 = F_245 ( V_29 , & V_637 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_694 : {
V_99 = - V_81 ;
if ( F_180 ( & V_29 -> V_5 . F_126 , V_477 ,
sizeof( struct V_695 ) ) )
goto V_93;
V_99 = - V_493 ;
if ( V_29 -> V_5 . F_126 . V_226 )
goto V_93;
V_99 = 0 ;
break;
}
case V_696 : {
struct V_697 V_698 ;
T_2 V_699 ;
T_10 V_235 ;
V_99 = - V_81 ;
if ( F_180 ( & V_698 , V_477 , sizeof( V_698 ) ) )
goto V_93;
V_99 = - V_493 ;
if ( V_698 . V_226 )
goto V_93;
V_99 = 0 ;
F_269 () ;
V_699 = F_97 () ;
V_235 = V_698 . clock - V_699 ;
F_270 () ;
V_29 -> V_5 . V_257 = V_235 ;
break;
}
case V_700 : {
struct V_697 V_698 ;
T_2 V_699 ;
F_269 () ;
V_699 = F_97 () ;
V_698 . clock = V_29 -> V_5 . V_257 + V_699 ;
F_270 () ;
V_698 . V_226 = 0 ;
memset ( & V_698 . V_531 , 0 , sizeof( V_698 . V_531 ) ) ;
V_99 = - V_81 ;
if ( F_181 ( V_477 , & V_698 , sizeof( V_698 ) ) )
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
static void F_271 ( void )
{
T_1 V_701 [ 2 ] ;
unsigned V_3 , V_702 ;
for ( V_3 = V_702 = V_703 ; V_3 < F_42 ( V_485 ) ; V_3 ++ ) {
if ( F_272 ( V_485 [ V_3 ] , & V_701 [ 0 ] , & V_701 [ 1 ] ) < 0 )
continue;
if ( V_702 < V_3 )
V_485 [ V_702 ] = V_485 [ V_3 ] ;
V_702 ++ ;
}
V_482 = V_702 ;
}
static int F_273 ( struct V_1 * V_2 , T_4 V_314 , int V_75 ,
const void * V_210 )
{
int V_704 = 0 ;
int V_417 ;
do {
V_417 = F_274 ( V_75 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_510 &&
! F_275 ( & V_2 -> V_5 . V_510 -> V_705 , V_314 , V_417 , V_210 ) )
&& F_276 ( V_2 -> V_29 , V_706 , V_314 , V_417 , V_210 ) )
break;
V_704 += V_417 ;
V_314 += V_417 ;
V_75 -= V_417 ;
V_210 += V_417 ;
} while ( V_75 );
return V_704 ;
}
static int F_277 ( struct V_1 * V_2 , T_4 V_314 , int V_75 , void * V_210 )
{
int V_704 = 0 ;
int V_417 ;
do {
V_417 = F_274 ( V_75 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_510 &&
! F_278 ( & V_2 -> V_5 . V_510 -> V_705 , V_314 , V_417 , V_210 ) )
&& F_279 ( V_2 -> V_29 , V_706 , V_314 , V_417 , V_210 ) )
break;
F_280 ( V_707 , V_417 , V_314 , * ( T_2 * ) V_210 ) ;
V_704 += V_417 ;
V_314 += V_417 ;
V_75 -= V_417 ;
V_210 += V_417 ;
} while ( V_75 );
return V_704 ;
}
static void F_281 ( struct V_1 * V_2 ,
struct V_708 * V_709 , int V_710 )
{
V_56 -> V_711 ( V_2 , V_709 , V_710 ) ;
}
void F_282 ( struct V_1 * V_2 ,
struct V_708 * V_709 , int V_710 )
{
V_56 -> V_712 ( V_2 , V_709 , V_710 ) ;
}
T_4 F_283 ( struct V_1 * V_2 , T_4 V_329 , T_1 V_76 )
{
T_4 V_713 ;
struct V_58 V_49 ;
F_284 ( ! F_31 ( V_2 ) ) ;
V_76 |= V_91 ;
V_713 = V_2 -> V_5 . V_67 . V_714 ( V_2 , V_329 , V_76 , & V_49 ) ;
return V_713 ;
}
T_4 F_285 ( struct V_1 * V_2 , T_13 V_715 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
return V_2 -> V_5 . V_83 -> V_714 ( V_2 , V_715 , V_76 , V_49 ) ;
}
T_4 F_286 ( struct V_1 * V_2 , T_13 V_715 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
V_76 |= V_716 ;
return V_2 -> V_5 . V_83 -> V_714 ( V_2 , V_715 , V_76 , V_49 ) ;
}
T_4 F_287 ( struct V_1 * V_2 , T_13 V_715 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
V_76 |= V_92 ;
return V_2 -> V_5 . V_83 -> V_714 ( V_2 , V_715 , V_76 , V_49 ) ;
}
T_4 F_288 ( struct V_1 * V_2 , T_13 V_715 ,
struct V_58 * V_49 )
{
return V_2 -> V_5 . V_83 -> V_714 ( V_2 , V_715 , 0 , V_49 ) ;
}
static int F_289 ( T_13 V_314 , void * V_145 , unsigned int V_717 ,
struct V_1 * V_2 , T_1 V_76 ,
struct V_58 * V_49 )
{
void * V_31 = V_145 ;
int V_99 = V_718 ;
while ( V_717 ) {
T_4 V_329 = V_2 -> V_5 . V_83 -> V_714 ( V_2 , V_314 , V_76 ,
V_49 ) ;
unsigned V_74 = V_314 & ( V_87 - 1 ) ;
unsigned V_719 = F_274 ( V_717 , ( unsigned ) V_87 - V_74 ) ;
int V_88 ;
if ( V_329 == V_80 )
return V_720 ;
V_88 = F_91 ( V_2 -> V_29 , V_329 , V_31 , V_719 ) ;
if ( V_88 < 0 ) {
V_99 = V_721 ;
goto V_93;
}
V_717 -= V_719 ;
V_31 += V_719 ;
V_314 += V_719 ;
}
V_93:
return V_99 ;
}
static int F_290 ( struct V_722 * V_723 ,
T_13 V_314 , void * V_145 , unsigned int V_717 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_291 ( V_723 ) ;
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
return F_289 ( V_314 , V_145 , V_717 , V_2 ,
V_76 | V_716 ,
V_49 ) ;
}
int F_292 ( struct V_722 * V_723 ,
T_13 V_314 , void * V_145 , unsigned int V_717 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_291 ( V_723 ) ;
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
return F_289 ( V_314 , V_145 , V_717 , V_2 , V_76 ,
V_49 ) ;
}
static int F_293 ( struct V_722 * V_723 ,
T_13 V_314 , void * V_145 , unsigned int V_717 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_291 ( V_723 ) ;
return F_289 ( V_314 , V_145 , V_717 , V_2 , 0 , V_49 ) ;
}
int F_294 ( struct V_722 * V_723 ,
T_13 V_314 , void * V_145 ,
unsigned int V_717 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_291 ( V_723 ) ;
void * V_31 = V_145 ;
int V_99 = V_718 ;
while ( V_717 ) {
T_4 V_329 = V_2 -> V_5 . V_83 -> V_714 ( V_2 , V_314 ,
V_92 ,
V_49 ) ;
unsigned V_74 = V_314 & ( V_87 - 1 ) ;
unsigned V_724 = F_274 ( V_717 , ( unsigned ) V_87 - V_74 ) ;
int V_88 ;
if ( V_329 == V_80 )
return V_720 ;
V_88 = F_92 ( V_2 -> V_29 , V_329 , V_31 , V_724 ) ;
if ( V_88 < 0 ) {
V_99 = V_721 ;
goto V_93;
}
V_717 -= V_724 ;
V_31 += V_724 ;
V_314 += V_724 ;
}
V_93:
return V_99 ;
}
static int F_295 ( struct V_1 * V_2 , unsigned long V_715 ,
T_4 * V_329 , struct V_58 * V_49 ,
bool V_725 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
if ( F_296 ( V_2 , V_715 ) &&
F_297 ( V_2 , V_725 , V_76 ,
V_2 -> V_5 . V_76 ) ) {
* V_329 = V_2 -> V_5 . V_726 << V_86 |
( V_715 & ( V_87 - 1 ) ) ;
F_298 ( V_715 , * V_329 , V_725 , false ) ;
return 1 ;
}
if ( V_725 )
V_76 |= V_92 ;
* V_329 = V_2 -> V_5 . V_83 -> V_714 ( V_2 , V_715 , V_76 , V_49 ) ;
if ( * V_329 == V_80 )
return - 1 ;
if ( ( * V_329 & V_303 ) == V_727 )
return 1 ;
if ( F_299 ( V_2 , * V_329 ) ) {
F_298 ( V_715 , * V_329 , V_725 , true ) ;
return 1 ;
}
return 0 ;
}
int F_300 ( struct V_1 * V_2 , T_4 V_329 ,
const void * V_145 , int V_717 )
{
int V_88 ;
V_88 = F_92 ( V_2 -> V_29 , V_329 , V_145 , V_717 ) ;
if ( V_88 < 0 )
return 0 ;
F_301 ( V_2 , V_329 , V_145 , V_717 ) ;
return 1 ;
}
static int F_302 ( struct V_1 * V_2 , void * V_145 , int V_717 )
{
if ( V_2 -> V_728 ) {
memcpy ( V_145 , V_2 -> V_729 , V_717 ) ;
F_280 ( V_707 , V_717 ,
V_2 -> V_730 , * ( T_2 * ) V_145 ) ;
V_2 -> V_728 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_303 ( struct V_1 * V_2 , T_4 V_329 ,
void * V_145 , int V_717 )
{
return ! F_91 ( V_2 -> V_29 , V_329 , V_145 , V_717 ) ;
}
static int F_304 ( struct V_1 * V_2 , T_4 V_329 ,
void * V_145 , int V_717 )
{
return F_300 ( V_2 , V_329 , V_145 , V_717 ) ;
}
static int F_305 ( struct V_1 * V_2 , T_4 V_329 , int V_717 , void * V_145 )
{
F_280 ( V_731 , V_717 , V_329 , * ( T_2 * ) V_145 ) ;
return F_273 ( V_2 , V_329 , V_717 , V_145 ) ;
}
static int F_306 ( struct V_1 * V_2 , T_4 V_329 ,
void * V_145 , int V_717 )
{
F_280 ( V_732 , V_717 , V_329 , 0 ) ;
return V_721 ;
}
static int F_307 ( struct V_1 * V_2 , T_4 V_329 ,
void * V_145 , int V_717 )
{
memcpy ( V_2 -> V_729 , V_145 , V_717 ) ;
memcpy ( V_2 -> V_733 -> V_734 . V_31 , V_2 -> V_729 , 8 ) ;
return V_718 ;
}
static int F_308 ( unsigned long V_314 , void * V_145 ,
unsigned int V_717 ,
struct V_58 * V_49 ,
struct V_1 * V_2 ,
struct V_735 * V_736 )
{
T_4 V_329 ;
int V_704 , V_88 ;
bool V_725 = V_736 -> V_725 ;
if ( V_736 -> V_737 &&
V_736 -> V_737 ( V_2 , V_145 , V_717 ) )
return V_718 ;
V_88 = F_295 ( V_2 , V_314 , & V_329 , V_49 , V_725 ) ;
if ( V_88 < 0 )
return V_720 ;
if ( V_88 )
goto V_734;
if ( V_736 -> V_738 ( V_2 , V_329 , V_145 , V_717 ) )
return V_718 ;
V_734:
V_704 = V_736 -> V_739 ( V_2 , V_329 , V_717 , V_145 ) ;
if ( V_704 == V_717 )
return V_718 ;
V_329 += V_704 ;
V_717 -= V_704 ;
V_145 += V_704 ;
V_2 -> V_740 = 1 ;
V_2 -> V_733 -> V_741 = V_742 ;
V_2 -> V_733 -> V_734 . V_743 = V_2 -> V_730 = V_329 ;
V_2 -> V_744 = V_717 ;
V_2 -> V_733 -> V_734 . V_75 = F_274 ( V_2 -> V_744 , 8 ) ;
V_2 -> V_733 -> V_734 . V_745 = V_2 -> V_746 = V_725 ;
V_2 -> V_747 = 0 ;
return V_736 -> V_748 ( V_2 , V_329 , V_145 , V_717 ) ;
}
int F_309 ( struct V_722 * V_723 , unsigned long V_314 ,
void * V_145 , unsigned int V_717 ,
struct V_58 * V_49 ,
struct V_735 * V_736 )
{
struct V_1 * V_2 = F_291 ( V_723 ) ;
if ( ( ( V_314 + V_717 - 1 ) ^ V_314 ) & V_303 ) {
int V_749 , V_750 ;
V_750 = - V_314 & ~ V_303 ;
V_749 = F_308 ( V_314 , V_145 , V_750 , V_49 ,
V_2 , V_736 ) ;
if ( V_749 != V_718 )
return V_749 ;
V_314 += V_750 ;
V_145 += V_750 ;
V_717 -= V_750 ;
}
return F_308 ( V_314 , V_145 , V_717 , V_49 ,
V_2 , V_736 ) ;
}
static int F_310 ( struct V_722 * V_723 ,
unsigned long V_314 ,
void * V_145 ,
unsigned int V_717 ,
struct V_58 * V_49 )
{
return F_309 ( V_723 , V_314 , V_145 , V_717 ,
V_49 , & V_751 ) ;
}
int F_311 ( struct V_722 * V_723 ,
unsigned long V_314 ,
const void * V_145 ,
unsigned int V_717 ,
struct V_58 * V_49 )
{
return F_309 ( V_723 , V_314 , ( void * ) V_145 , V_717 ,
V_49 , & V_752 ) ;
}
static int F_312 ( struct V_722 * V_723 ,
unsigned long V_314 ,
const void * V_753 ,
const void * V_754 ,
unsigned int V_717 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_291 ( V_723 ) ;
T_4 V_329 ;
struct V_305 * V_305 ;
char * V_755 ;
bool V_756 ;
if ( V_717 > 8 || ( V_717 & ( V_717 - 1 ) ) )
goto V_757;
V_329 = F_287 ( V_2 , V_314 , NULL ) ;
if ( V_329 == V_80 ||
( V_329 & V_303 ) == V_727 )
goto V_757;
if ( ( ( V_329 + V_717 - 1 ) & V_303 ) != ( V_329 & V_303 ) )
goto V_757;
V_305 = F_153 ( V_2 -> V_29 , V_329 >> V_86 ) ;
if ( F_154 ( V_305 ) ) {
F_155 ( V_305 ) ;
goto V_757;
}
V_755 = F_117 ( V_305 ) ;
V_755 += F_313 ( V_329 ) ;
switch ( V_717 ) {
case 1 :
V_756 = F_314 ( T_11 , V_755 , V_753 , V_754 ) ;
break;
case 2 :
V_756 = F_314 ( V_758 , V_755 , V_753 , V_754 ) ;
break;
case 4 :
V_756 = F_314 ( T_1 , V_755 , V_753 , V_754 ) ;
break;
case 8 :
V_756 = F_315 ( V_755 , V_753 , V_754 ) ;
break;
default:
F_316 () ;
}
F_118 ( V_755 ) ;
F_145 ( V_305 ) ;
if ( ! V_756 )
return V_759 ;
F_301 ( V_2 , V_329 , V_754 , V_717 ) ;
return V_718 ;
V_757:
F_317 ( V_760 L_22 ) ;
return F_311 ( V_723 , V_314 , V_754 , V_717 , V_49 ) ;
}
static int F_318 ( struct V_1 * V_2 , void * V_761 )
{
int V_99 ;
if ( V_2 -> V_5 . V_762 . V_763 )
V_99 = F_279 ( V_2 -> V_29 , V_669 , V_2 -> V_5 . V_762 . V_764 ,
V_2 -> V_5 . V_762 . V_418 , V_761 ) ;
else
V_99 = F_276 ( V_2 -> V_29 , V_669 ,
V_2 -> V_5 . V_762 . V_764 , V_2 -> V_5 . V_762 . V_418 ,
V_761 ) ;
return V_99 ;
}
static int F_319 ( struct V_1 * V_2 , int V_418 ,
unsigned short V_764 , void * V_145 ,
unsigned int V_630 , bool V_763 )
{
F_320 ( ! V_763 , V_764 , V_418 , V_630 ) ;
V_2 -> V_5 . V_762 . V_764 = V_764 ;
V_2 -> V_5 . V_762 . V_763 = V_763 ;
V_2 -> V_5 . V_762 . V_630 = V_630 ;
V_2 -> V_5 . V_762 . V_418 = V_418 ;
if ( ! F_318 ( V_2 , V_2 -> V_5 . V_765 ) ) {
V_2 -> V_5 . V_762 . V_630 = 0 ;
return 1 ;
}
V_2 -> V_733 -> V_741 = V_766 ;
V_2 -> V_733 -> V_767 . V_768 = V_763 ? V_769 : V_770 ;
V_2 -> V_733 -> V_767 . V_418 = V_418 ;
V_2 -> V_733 -> V_767 . V_771 = V_772 * V_87 ;
V_2 -> V_733 -> V_767 . V_630 = V_630 ;
V_2 -> V_733 -> V_767 . V_764 = V_764 ;
return 0 ;
}
static int F_321 ( struct V_722 * V_723 ,
int V_418 , unsigned short V_764 , void * V_145 ,
unsigned int V_630 )
{
struct V_1 * V_2 = F_291 ( V_723 ) ;
int V_88 ;
if ( V_2 -> V_5 . V_762 . V_630 )
goto V_773;
V_88 = F_319 ( V_2 , V_418 , V_764 , V_145 , V_630 , true ) ;
if ( V_88 ) {
V_773:
memcpy ( V_145 , V_2 -> V_5 . V_765 , V_418 * V_630 ) ;
V_2 -> V_5 . V_762 . V_630 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_322 ( struct V_722 * V_723 ,
int V_418 , unsigned short V_764 ,
const void * V_145 , unsigned int V_630 )
{
struct V_1 * V_2 = F_291 ( V_723 ) ;
memcpy ( V_2 -> V_5 . V_765 , V_145 , V_418 * V_630 ) ;
return F_319 ( V_2 , V_418 , V_764 , ( void * ) V_145 , V_630 , false ) ;
}
static unsigned long F_323 ( struct V_1 * V_2 , int V_710 )
{
return V_56 -> F_323 ( V_2 , V_710 ) ;
}
static void F_324 ( struct V_722 * V_723 , V_140 V_63 )
{
F_325 ( F_291 ( V_723 ) , V_63 ) ;
}
int F_326 ( struct V_1 * V_2 )
{
if ( ! F_189 ( V_2 ) )
return V_718 ;
if ( V_56 -> V_499 () ) {
int V_498 = F_327 () ;
F_191 ( V_498 , V_2 -> V_5 . V_500 ) ;
F_328 ( V_2 -> V_5 . V_500 ,
F_187 , NULL , 1 ) ;
F_329 () ;
F_330 ( V_2 -> V_5 . V_500 ) ;
} else
F_188 () ;
return V_718 ;
}
static void F_331 ( struct V_722 * V_723 )
{
F_326 ( F_291 ( V_723 ) ) ;
}
int F_332 ( struct V_722 * V_723 , int V_144 , unsigned long * V_774 )
{
return F_78 ( F_291 ( V_723 ) , V_144 , V_774 ) ;
}
int F_333 ( struct V_722 * V_723 , int V_144 , unsigned long V_23 )
{
return F_75 ( F_291 ( V_723 ) , V_144 , V_23 ) ;
}
static T_2 F_334 ( T_2 V_775 , T_1 V_776 )
{
return ( V_775 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_776 ;
}
static unsigned long F_335 ( struct V_722 * V_723 , int V_777 )
{
struct V_1 * V_2 = F_291 ( V_723 ) ;
unsigned long V_23 ;
switch ( V_777 ) {
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
F_336 ( V_2 , L_23 , V_204 , V_777 ) ;
return 0 ;
}
return V_23 ;
}
static int F_337 ( struct V_722 * V_723 , int V_777 , V_140 V_145 )
{
struct V_1 * V_2 = F_291 ( V_723 ) ;
int V_160 = 0 ;
switch ( V_777 ) {
case 0 :
V_160 = F_50 ( V_2 , F_334 ( F_51 ( V_2 ) , V_145 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_62 = V_145 ;
break;
case 3 :
V_160 = F_66 ( V_2 , V_145 ) ;
break;
case 4 :
V_160 = F_60 ( V_2 , F_334 ( F_61 ( V_2 ) , V_145 ) ) ;
break;
case 8 :
V_160 = F_71 ( V_2 , V_145 ) ;
break;
default:
F_336 ( V_2 , L_23 , V_204 , V_777 ) ;
V_160 = - 1 ;
}
return V_160 ;
}
static void F_338 ( struct V_722 * V_723 , V_140 V_145 )
{
F_339 ( F_291 ( V_723 ) , V_145 ) ;
}
static int F_340 ( struct V_722 * V_723 )
{
return V_56 -> V_71 ( F_291 ( V_723 ) ) ;
}
static void F_341 ( struct V_722 * V_723 , struct V_778 * V_779 )
{
V_56 -> V_780 ( F_291 ( V_723 ) , V_779 ) ;
}
static void F_342 ( struct V_722 * V_723 , struct V_778 * V_779 )
{
V_56 -> V_781 ( F_291 ( V_723 ) , V_779 ) ;
}
static void F_343 ( struct V_722 * V_723 , struct V_778 * V_779 )
{
V_56 -> V_782 ( F_291 ( V_723 ) , V_779 ) ;
}
static void F_344 ( struct V_722 * V_723 , struct V_778 * V_779 )
{
V_56 -> V_783 ( F_291 ( V_723 ) , V_779 ) ;
}
static unsigned long F_345 (
struct V_722 * V_723 , int V_710 )
{
return F_323 ( F_291 ( V_723 ) , V_710 ) ;
}
static bool F_346 ( struct V_722 * V_723 , V_758 * V_784 ,
struct V_785 * V_786 , T_1 * V_787 ,
int V_710 )
{
struct V_708 V_709 ;
F_282 ( F_291 ( V_723 ) , & V_709 , V_710 ) ;
* V_784 = V_709 . V_784 ;
if ( V_709 . V_788 )
return false ;
if ( V_709 . V_789 )
V_709 . V_790 >>= 12 ;
F_347 ( V_786 , V_709 . V_790 ) ;
F_348 ( V_786 , ( unsigned long ) V_709 . V_791 ) ;
#ifdef F_52
if ( V_787 )
* V_787 = V_709 . V_791 >> 32 ;
#endif
V_786 -> type = V_709 . type ;
V_786 -> V_508 = V_709 . V_508 ;
V_786 -> V_792 = V_709 . V_792 ;
V_786 -> V_274 = V_709 . V_793 ;
V_786 -> V_794 = V_709 . V_794 ;
V_786 -> V_795 = V_709 . V_795 ;
V_786 -> V_796 = V_709 . V_146 ;
V_786 -> V_789 = V_709 . V_789 ;
return true ;
}
static void F_349 ( struct V_722 * V_723 , V_758 V_784 ,
struct V_785 * V_786 , T_1 V_787 ,
int V_710 )
{
struct V_1 * V_2 = F_291 ( V_723 ) ;
struct V_708 V_709 ;
V_709 . V_784 = V_784 ;
V_709 . V_791 = F_350 ( V_786 ) ;
#ifdef F_52
V_709 . V_791 |= ( ( T_2 ) V_787 ) << 32 ;
#endif
V_709 . V_790 = F_351 ( V_786 ) ;
if ( V_786 -> V_789 )
V_709 . V_790 = ( V_709 . V_790 << 12 ) | 0xfff ;
V_709 . type = V_786 -> type ;
V_709 . V_793 = V_786 -> V_274 ;
V_709 . V_792 = V_786 -> V_792 ;
V_709 . V_146 = V_786 -> V_796 ;
V_709 . V_508 = V_786 -> V_508 ;
V_709 . V_795 = V_786 -> V_795 ;
V_709 . V_789 = V_786 -> V_789 ;
V_709 . V_794 = V_786 -> V_794 ;
V_709 . V_793 = V_786 -> V_274 ;
V_709 . V_788 = ! V_709 . V_793 ;
V_709 . V_797 = 0 ;
F_281 ( V_2 , & V_709 , V_710 ) ;
return;
}
static int F_352 ( struct V_722 * V_723 ,
T_1 V_180 , T_2 * V_393 )
{
return F_164 ( F_291 ( V_723 ) , V_180 , V_393 ) ;
}
static int F_353 ( struct V_722 * V_723 ,
T_1 V_180 , T_2 V_31 )
{
return F_88 ( F_291 ( V_723 ) , V_180 , V_31 ) ;
}
static int F_354 ( struct V_722 * V_723 ,
T_1 V_798 , T_2 * V_393 )
{
return F_82 ( F_291 ( V_723 ) , V_798 , V_393 ) ;
}
static void F_355 ( struct V_722 * V_723 )
{
F_291 ( V_723 ) -> V_5 . V_799 = 1 ;
}
static void F_356 ( struct V_722 * V_723 )
{
F_157 () ;
F_357 ( F_291 ( V_723 ) ) ;
F_358 () ;
}
static void F_359 ( struct V_722 * V_723 )
{
F_158 () ;
}
static int F_360 ( struct V_722 * V_723 ,
struct V_800 * V_801 ,
enum V_802 V_803 )
{
return V_56 -> V_804 ( F_291 ( V_723 ) , V_801 , V_803 ) ;
}
static bool F_361 ( struct V_722 * V_723 ,
T_1 * V_805 , T_1 * V_806 , T_1 * V_162 , T_1 * V_171 )
{
struct V_169 * V_489 = NULL ;
if ( V_805 && V_162 )
V_489 = F_85 ( F_291 ( V_723 ) ,
* V_805 , * V_162 ) ;
if ( V_489 ) {
* V_805 = V_489 -> V_805 ;
* V_162 = V_489 -> V_162 ;
if ( V_806 )
* V_806 = V_489 -> V_806 ;
if ( V_171 )
* V_171 = V_489 -> V_171 ;
return true ;
}
return false ;
}
static void F_362 ( struct V_1 * V_2 )
{
F_81 ( V_2 , V_164 ) ;
F_81 ( V_2 , V_807 ) ;
F_81 ( V_2 , V_808 ) ;
V_2 -> V_5 . V_97 = ~ 0 ;
}
static void F_363 ( struct V_1 * V_2 , T_1 V_26 )
{
T_1 V_809 = V_56 -> V_535 ( V_2 , V_26 ) ;
if ( ! ( V_809 & V_26 ) )
V_56 -> V_548 ( V_2 , V_26 ) ;
}
static void F_364 ( struct V_1 * V_2 )
{
struct V_722 * V_723 = & V_2 -> V_5 . V_810 ;
if ( V_723 -> V_49 . V_32 == V_33 )
F_30 ( V_2 , & V_723 -> V_49 ) ;
else if ( V_723 -> V_49 . V_811 )
F_29 ( V_2 , V_723 -> V_49 . V_32 ,
V_723 -> V_49 . V_43 ) ;
else
F_24 ( V_2 , V_723 -> V_49 . V_32 ) ;
}
static void F_365 ( struct V_722 * V_723 ,
const unsigned long * V_509 )
{
memset ( & V_723 -> V_812 , 0 ,
( void * ) & V_723 -> V_509 - ( void * ) & V_723 -> V_812 ) ;
memcpy ( V_723 -> V_509 , V_509 , sizeof( V_723 -> V_509 ) ) ;
V_723 -> V_813 . V_632 = 0 ;
V_723 -> V_813 . V_814 = 0 ;
V_723 -> V_815 . V_816 = 0 ;
V_723 -> V_815 . V_814 = 0 ;
V_723 -> V_817 . V_816 = 0 ;
V_723 -> V_817 . V_814 = 0 ;
}
static void F_366 ( struct V_1 * V_2 )
{
struct V_722 * V_723 = & V_2 -> V_5 . V_810 ;
int V_112 , V_113 ;
F_362 ( V_2 ) ;
V_56 -> V_114 ( V_2 , & V_112 , & V_113 ) ;
V_723 -> V_818 = F_367 ( V_2 ) ;
V_723 -> V_819 = F_368 ( V_2 ) ;
V_723 -> V_820 = ( ! F_369 ( V_2 ) ) ? V_821 :
( V_723 -> V_818 & V_822 ) ? V_823 :
V_113 ? V_824 :
V_112 ? V_825 :
V_826 ;
V_723 -> V_827 = F_370 ( V_2 ) ;
F_365 ( V_723 , V_2 -> V_5 . V_509 ) ;
V_2 -> V_5 . V_828 = false ;
}
int F_371 ( struct V_1 * V_2 , int V_512 , int V_829 )
{
struct V_722 * V_723 = & V_2 -> V_5 . V_810 ;
int V_88 ;
F_366 ( V_2 ) ;
V_723 -> V_830 = 2 ;
V_723 -> V_831 = 2 ;
V_723 -> V_832 = V_723 -> V_819 + V_829 ;
V_88 = F_372 ( V_723 , V_512 ) ;
if ( V_88 != V_718 )
return V_833 ;
V_723 -> V_819 = V_723 -> V_832 ;
memcpy ( V_2 -> V_5 . V_509 , V_723 -> V_509 , sizeof V_723 -> V_509 ) ;
F_373 ( V_2 , V_723 -> V_819 ) ;
F_339 ( V_2 , V_723 -> V_818 ) ;
if ( V_512 == V_834 )
V_2 -> V_5 . V_540 = 0 ;
else
V_2 -> V_5 . V_532 . V_50 = false ;
return V_835 ;
}
static int F_374 ( struct V_1 * V_2 )
{
int V_99 = V_835 ;
++ V_2 -> V_60 . V_836 ;
F_375 ( V_2 ) ;
if ( ! F_370 ( V_2 ) ) {
V_2 -> V_733 -> V_741 = V_837 ;
V_2 -> V_733 -> V_838 . V_839 = V_840 ;
V_2 -> V_733 -> V_838 . V_841 = 0 ;
V_99 = V_833 ;
}
F_24 ( V_2 , V_161 ) ;
return V_99 ;
}
static bool F_376 ( struct V_1 * V_2 , T_13 V_715 )
{
T_4 V_329 ;
if ( V_179 )
return false ;
if ( F_377 ( V_2 , V_715 ) )
return true ;
V_329 = F_288 ( V_2 , V_715 , NULL ) ;
if ( V_329 == V_80 )
return true ;
if ( ! F_135 ( F_134 ( V_2 -> V_29 , V_329 >> V_86 ) ) )
return true ;
return false ;
}
static bool F_378 ( struct V_722 * V_723 ,
unsigned long V_62 , int V_842 )
{
struct V_1 * V_2 = F_291 ( V_723 ) ;
unsigned long V_843 , V_844 , V_329 = V_62 ;
V_843 = V_2 -> V_5 . V_843 ;
V_844 = V_2 -> V_5 . V_844 ;
V_2 -> V_5 . V_843 = V_2 -> V_5 . V_844 = 0 ;
if ( ! ( V_842 & V_845 ) )
return false ;
if ( F_379 ( V_723 ) )
return false ;
if ( V_723 -> V_819 == V_843 && V_844 == V_62 )
return false ;
V_2 -> V_5 . V_843 = V_723 -> V_819 ;
V_2 -> V_5 . V_844 = V_62 ;
if ( ! V_2 -> V_5 . V_67 . V_846 )
V_329 = F_287 ( V_2 , V_62 , NULL ) ;
F_380 ( V_2 -> V_29 , V_329 >> V_86 ) ;
return true ;
}
int F_381 ( struct V_1 * V_2 ,
unsigned long V_62 ,
int V_842 ,
void * V_847 ,
int V_848 )
{
int V_99 ;
struct V_722 * V_723 = & V_2 -> V_5 . V_810 ;
bool V_416 = true ;
F_382 ( V_2 ) ;
if ( ! ( V_842 & V_849 ) ) {
F_366 ( V_2 ) ;
V_723 -> V_850 = 0 ;
V_723 -> V_851 = false ;
V_723 -> V_852 = false ;
V_723 -> V_853
= V_842 & V_854 ;
V_99 = F_383 ( V_723 , V_847 , V_848 ) ;
F_384 ( V_2 ) ;
++ V_2 -> V_60 . V_855 ;
if ( V_99 != V_856 ) {
if ( V_842 & V_854 )
return V_833 ;
if ( F_376 ( V_2 , V_62 ) )
return V_835 ;
if ( V_842 & V_857 )
return V_833 ;
return F_374 ( V_2 ) ;
}
}
if ( V_842 & V_857 ) {
F_373 ( V_2 , V_723 -> V_832 ) ;
return V_835 ;
}
if ( F_378 ( V_723 , V_62 , V_842 ) )
return V_835 ;
if ( V_2 -> V_5 . V_828 ) {
V_2 -> V_5 . V_828 = false ;
memcpy ( V_723 -> V_509 , V_2 -> V_5 . V_509 , sizeof V_723 -> V_509 ) ;
}
V_858:
V_99 = F_385 ( V_723 ) ;
if ( V_99 == V_859 )
return V_835 ;
if ( V_99 == V_860 ) {
if ( F_376 ( V_2 , V_62 ) )
return V_835 ;
return F_374 ( V_2 ) ;
}
if ( V_723 -> V_851 ) {
F_364 ( V_2 ) ;
V_99 = V_835 ;
} else if ( V_2 -> V_5 . V_762 . V_630 ) {
if ( ! V_2 -> V_5 . V_762 . V_763 )
V_2 -> V_5 . V_762 . V_630 = 0 ;
else
V_416 = false ;
V_99 = V_861 ;
} else if ( V_2 -> V_740 ) {
if ( ! V_2 -> V_746 )
V_416 = false ;
V_99 = V_861 ;
} else if ( V_99 == V_862 )
goto V_858;
else
V_99 = V_835 ;
if ( V_416 ) {
F_363 ( V_2 , V_723 -> V_850 ) ;
F_339 ( V_2 , V_723 -> V_818 ) ;
F_23 ( V_48 , V_2 ) ;
memcpy ( V_2 -> V_5 . V_509 , V_723 -> V_509 , sizeof V_723 -> V_509 ) ;
V_2 -> V_5 . V_863 = false ;
F_373 ( V_2 , V_723 -> V_819 ) ;
} else
V_2 -> V_5 . V_863 = true ;
return V_99 ;
}
int F_386 ( struct V_1 * V_2 , int V_418 , unsigned short V_764 )
{
unsigned long V_145 = F_81 ( V_2 , V_164 ) ;
int V_88 = F_322 ( & V_2 -> V_5 . V_810 ,
V_418 , V_764 , & V_145 , 1 ) ;
V_2 -> V_5 . V_762 . V_630 = 0 ;
return V_88 ;
}
static void F_387 ( void * V_801 )
{
F_388 ( V_248 , 0 ) ;
}
static void F_389 ( void * V_31 )
{
struct V_864 * V_865 = V_31 ;
unsigned long V_208 = 0 ;
if ( V_31 )
V_208 = V_865 -> V_754 ;
else if ( ! F_184 ( V_866 ) )
V_208 = F_390 ( F_391 () ) ;
if ( ! V_208 )
V_208 = V_217 ;
F_388 ( V_248 , V_208 ) ;
}
static int F_392 ( struct V_867 * V_868 , unsigned long V_145 ,
void * V_31 )
{
struct V_864 * V_865 = V_31 ;
struct V_29 * V_29 ;
struct V_1 * V_2 ;
int V_3 , V_869 = 0 ;
if ( V_145 == V_870 && V_865 -> V_753 > V_865 -> V_754 )
return 0 ;
if ( V_145 == V_871 && V_865 -> V_753 < V_865 -> V_754 )
return 0 ;
F_192 ( V_865 -> V_498 , F_389 , V_865 , 1 ) ;
F_393 ( & V_872 ) ;
F_394 (kvm, &vm_list, vm_list) {
F_169 (i, vcpu, kvm) {
if ( V_2 -> V_498 != V_865 -> V_498 )
continue;
F_23 ( V_249 , V_2 ) ;
if ( V_2 -> V_498 != F_395 () )
V_869 = 1 ;
}
}
F_396 ( & V_872 ) ;
if ( V_865 -> V_753 < V_865 -> V_754 && V_869 ) {
F_192 ( V_865 -> V_498 , F_389 , V_865 , 1 ) ;
}
return 0 ;
}
static int F_397 ( struct V_867 * V_873 ,
unsigned long V_874 , void * V_875 )
{
unsigned int V_498 = ( unsigned long ) V_875 ;
switch ( V_874 ) {
case V_876 :
case V_877 :
F_192 ( V_498 , F_389 , NULL , 1 ) ;
break;
case V_878 :
F_192 ( V_498 , F_387 , NULL , 1 ) ;
break;
}
return V_879 ;
}
static void F_398 ( void )
{
int V_498 ;
V_880 = V_217 ;
F_399 ( & V_881 ) ;
if ( ! F_184 ( V_866 ) ) {
#ifdef F_400
struct V_882 V_883 ;
memset ( & V_883 , 0 , sizeof( V_883 ) ) ;
V_498 = F_327 () ;
F_401 ( & V_883 , V_498 ) ;
if ( V_883 . V_884 . V_885 )
V_880 = V_883 . V_884 . V_885 ;
F_329 () ;
#endif
F_402 ( & V_886 ,
V_887 ) ;
}
F_96 ( L_24 , V_880 ) ;
F_403 (cpu)
F_192 ( V_498 , F_389 , NULL , 1 ) ;
}
int F_404 ( void )
{
return F_405 ( V_888 ) != NULL ;
}
static int F_406 ( void )
{
int V_889 = 3 ;
if ( F_405 ( V_888 ) )
V_889 = V_56 -> V_71 ( F_405 ( V_888 ) ) ;
return V_889 != 0 ;
}
static unsigned long F_407 ( void )
{
unsigned long V_890 = 0 ;
if ( F_405 ( V_888 ) )
V_890 = F_368 ( F_405 ( V_888 ) ) ;
return V_890 ;
}
void F_408 ( struct V_1 * V_2 )
{
F_388 ( V_888 , V_2 ) ;
}
void F_409 ( struct V_1 * V_2 )
{
F_388 ( V_888 , NULL ) ;
}
static void F_410 ( void )
{
T_2 V_26 ;
int V_891 = V_892 . V_893 ;
V_26 = ( ( 1ull << ( 62 - V_891 + 1 ) ) - 1 ) << V_891 ;
V_26 |= 1ull ;
#ifdef F_52
if ( V_891 == 52 )
V_26 &= ~ 1ull ;
#endif
F_411 ( V_26 ) ;
}
int F_412 ( void * V_894 )
{
int V_99 ;
struct V_56 * V_736 = (struct V_56 * ) V_894 ;
if ( V_56 ) {
F_9 ( V_25 L_25 ) ;
V_99 = - V_666 ;
goto V_93;
}
if ( ! V_736 -> V_895 () ) {
F_9 ( V_25 L_26 ) ;
V_99 = - V_896 ;
goto V_93;
}
if ( V_736 -> V_897 () ) {
F_9 ( V_25 L_27 ) ;
V_99 = - V_896 ;
goto V_93;
}
V_99 = F_413 () ;
if ( V_99 )
goto V_93;
F_410 () ;
F_271 () ;
V_56 = V_736 ;
F_414 ( V_898 , V_899 ,
V_900 , V_901 , 0 ) ;
F_398 () ;
F_415 ( & V_902 ) ;
if ( V_468 )
V_124 = F_416 ( V_120 ) ;
return 0 ;
V_93:
return V_99 ;
}
void F_417 ( void )
{
F_418 ( & V_902 ) ;
if ( ! F_184 ( V_866 ) )
F_419 ( & V_886 ,
V_887 ) ;
F_420 ( & V_881 ) ;
V_56 = NULL ;
F_421 () ;
}
int F_422 ( struct V_1 * V_2 )
{
++ V_2 -> V_60 . V_903 ;
if ( F_18 ( V_2 -> V_29 ) ) {
V_2 -> V_5 . V_904 = V_905 ;
return 1 ;
} else {
V_2 -> V_733 -> V_741 = V_906 ;
return 0 ;
}
}
int F_423 ( struct V_1 * V_2 )
{
T_2 V_907 , V_908 , V_909 , V_88 ;
T_14 V_910 , V_911 , V_912 , V_160 = V_913 , V_914 = 0 ;
bool V_915 , V_916 ;
int V_112 , V_113 ;
if ( V_56 -> V_71 ( V_2 ) != 0 || ! F_369 ( V_2 ) ) {
F_24 ( V_2 , V_161 ) ;
return 0 ;
}
V_56 -> V_114 ( V_2 , & V_112 , & V_113 ) ;
V_916 = F_46 ( V_2 ) && V_113 == 1 ;
if ( ! V_916 ) {
V_907 = ( ( T_2 ) F_81 ( V_2 , V_165 ) << 32 ) |
( F_81 ( V_2 , V_164 ) & 0xffffffff ) ;
V_908 = ( ( T_2 ) F_81 ( V_2 , V_917 ) << 32 ) |
( F_81 ( V_2 , V_163 ) & 0xffffffff ) ;
V_909 = ( ( T_2 ) F_81 ( V_2 , V_918 ) << 32 ) |
( F_81 ( V_2 , V_919 ) & 0xffffffff ) ;
}
#ifdef F_52
else {
V_907 = F_81 ( V_2 , V_163 ) ;
V_908 = F_81 ( V_2 , V_165 ) ;
V_909 = F_81 ( V_2 , V_920 ) ;
}
#endif
V_910 = V_907 & 0xffff ;
V_915 = ( V_907 >> 16 ) & 0x1 ;
V_912 = ( V_907 >> 32 ) & 0xfff ;
V_911 = ( V_907 >> 48 ) & 0xfff ;
F_424 ( V_910 , V_915 , V_912 , V_911 , V_908 , V_909 ) ;
switch ( V_910 ) {
case V_921 :
F_425 ( V_2 ) ;
break;
default:
V_160 = V_922 ;
break;
}
V_88 = V_160 | ( ( ( T_2 ) V_914 & 0xfff ) << 32 ) ;
if ( V_916 ) {
F_83 ( V_2 , V_164 , V_88 ) ;
} else {
F_83 ( V_2 , V_165 , V_88 >> 32 ) ;
F_83 ( V_2 , V_164 , V_88 & 0xffffffff ) ;
}
return 1 ;
}
int F_426 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_923 , V_924 , V_925 , V_926 , V_88 ;
int V_99 = 1 ;
if ( F_131 ( V_2 -> V_29 ) )
return F_423 ( V_2 ) ;
V_16 = F_81 ( V_2 , V_164 ) ;
V_923 = F_81 ( V_2 , V_917 ) ;
V_924 = F_81 ( V_2 , V_163 ) ;
V_925 = F_81 ( V_2 , V_165 ) ;
V_926 = F_81 ( V_2 , V_919 ) ;
F_427 ( V_16 , V_923 , V_924 , V_925 , V_926 ) ;
if ( ! F_46 ( V_2 ) ) {
V_16 &= 0xFFFFFFFF ;
V_923 &= 0xFFFFFFFF ;
V_924 &= 0xFFFFFFFF ;
V_925 &= 0xFFFFFFFF ;
V_926 &= 0xFFFFFFFF ;
}
if ( V_56 -> V_71 ( V_2 ) != 0 ) {
V_88 = - V_927 ;
goto V_93;
}
switch ( V_16 ) {
case V_928 :
V_88 = 0 ;
break;
default:
V_88 = - V_929 ;
break;
}
V_93:
F_83 ( V_2 , V_164 , V_88 ) ;
++ V_2 -> V_60 . V_930 ;
return V_99 ;
}
int F_428 ( struct V_722 * V_723 )
{
struct V_1 * V_2 = F_291 ( V_723 ) ;
char V_931 [ 3 ] ;
unsigned long V_932 = F_368 ( V_2 ) ;
F_429 ( V_2 -> V_29 ) ;
V_56 -> V_317 ( V_2 , V_931 ) ;
return F_311 ( V_723 , V_932 , V_931 , 3 , NULL ) ;
}
static int F_430 ( struct V_1 * V_2 )
{
return ( ! F_18 ( V_2 -> V_29 ) && ! F_431 ( V_2 ) &&
V_2 -> V_733 -> V_933 &&
F_432 ( V_2 ) ) ;
}
static void F_433 ( struct V_1 * V_2 )
{
struct V_934 * V_934 = V_2 -> V_733 ;
V_934 -> V_935 = ( F_367 ( V_2 ) & V_936 ) != 0 ;
V_934 -> V_142 = F_73 ( V_2 ) ;
V_934 -> V_30 = F_17 ( V_2 ) ;
if ( F_18 ( V_2 -> V_29 ) )
V_934 -> V_937 = 1 ;
else
V_934 -> V_937 =
F_432 ( V_2 ) &&
! F_431 ( V_2 ) &&
! F_434 ( V_2 ) ;
}
static void F_435 ( struct V_1 * V_2 )
{
struct V_938 * V_510 = V_2 -> V_5 . V_510 ;
struct V_305 * V_305 ;
if ( ! V_510 || ! V_510 -> V_588 )
return;
V_305 = F_153 ( V_2 -> V_29 , V_510 -> V_588 >> V_86 ) ;
V_2 -> V_5 . V_510 -> V_939 = V_305 ;
}
static void F_436 ( struct V_1 * V_2 )
{
struct V_938 * V_510 = V_2 -> V_5 . V_510 ;
int V_280 ;
if ( ! V_510 || ! V_510 -> V_588 )
return;
V_280 = F_177 ( & V_2 -> V_29 -> V_413 ) ;
F_145 ( V_510 -> V_939 ) ;
F_119 ( V_2 -> V_29 , V_510 -> V_588 >> V_86 ) ;
F_178 ( & V_2 -> V_29 -> V_413 , V_280 ) ;
}
static void F_203 ( struct V_1 * V_2 )
{
int V_940 , V_941 ;
if ( ! V_56 -> F_203 )
return;
if ( ! V_2 -> V_5 . V_510 )
return;
if ( ! V_2 -> V_5 . V_510 -> V_588 )
V_940 = F_437 ( V_2 ) ;
else
V_940 = - 1 ;
if ( V_940 != - 1 )
V_940 >>= 4 ;
V_941 = F_74 ( V_2 ) ;
V_56 -> F_203 ( V_2 , V_941 , V_940 ) ;
}
static void F_438 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_49 . V_50 ) {
F_439 ( V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ) ;
V_56 -> V_942 ( V_2 , V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ,
V_2 -> V_5 . V_49 . V_44 ) ;
return;
}
if ( V_2 -> V_5 . V_539 ) {
V_56 -> V_943 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_532 . V_50 ) {
V_56 -> V_944 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_540 ) {
if ( V_56 -> V_945 ( V_2 ) ) {
-- V_2 -> V_5 . V_540 ;
V_2 -> V_5 . V_539 = true ;
V_56 -> V_943 ( V_2 ) ;
}
} else if ( F_431 ( V_2 ) ) {
if ( V_56 -> V_946 ( V_2 ) ) {
F_205 ( V_2 , F_440 ( V_2 ) ,
false ) ;
V_56 -> V_944 ( V_2 ) ;
}
}
}
static void F_441 ( struct V_1 * V_2 )
{
if ( F_76 ( V_2 , V_134 ) &&
! V_2 -> V_125 ) {
F_442 ( V_120 , V_2 -> V_5 . V_119 ) ;
V_2 -> V_125 = 1 ;
}
}
static void F_443 ( struct V_1 * V_2 )
{
if ( V_2 -> V_125 ) {
if ( V_2 -> V_5 . V_119 != V_124 )
F_442 ( V_120 , V_124 ) ;
V_2 -> V_125 = 0 ;
}
}
static void F_211 ( struct V_1 * V_2 )
{
unsigned V_790 = 2 ;
if ( V_56 -> V_542 ( V_2 ) || V_2 -> V_5 . V_539 )
V_790 = 1 ;
V_2 -> V_5 . V_540 += F_444 ( & V_2 -> V_5 . V_68 , 0 ) ;
V_2 -> V_5 . V_540 = F_274 ( V_2 -> V_5 . V_540 , V_790 ) ;
F_23 ( V_48 , V_2 ) ;
}
static int F_445 ( struct V_1 * V_2 )
{
int V_99 ;
bool V_947 = ! F_18 ( V_2 -> V_29 ) &&
V_2 -> V_733 -> V_933 ;
bool V_948 = 0 ;
if ( V_2 -> V_503 ) {
if ( F_446 ( V_949 , V_2 ) )
F_447 ( V_2 ) ;
if ( F_446 ( V_950 , V_2 ) )
F_448 ( V_2 ) ;
if ( F_446 ( V_249 , V_2 ) ) {
V_99 = F_113 ( V_2 ) ;
if ( F_69 ( V_99 ) )
goto V_93;
}
if ( F_446 ( V_951 , V_2 ) )
F_67 ( V_2 ) ;
if ( F_446 ( V_952 , V_2 ) )
V_56 -> V_953 ( V_2 ) ;
if ( F_446 ( V_954 , V_2 ) ) {
V_2 -> V_733 -> V_741 = V_955 ;
V_99 = 0 ;
goto V_93;
}
if ( F_446 ( V_54 , V_2 ) ) {
V_2 -> V_733 -> V_741 = V_956 ;
V_99 = 0 ;
goto V_93;
}
if ( F_446 ( V_957 , V_2 ) ) {
V_2 -> V_958 = 0 ;
V_56 -> V_959 ( V_2 ) ;
}
if ( F_446 ( V_960 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_961 = true ;
V_99 = 1 ;
goto V_93;
}
if ( F_446 ( V_369 , V_2 ) )
F_147 ( V_2 ) ;
if ( F_446 ( V_69 , V_2 ) )
F_211 ( V_2 ) ;
V_948 =
F_446 ( V_962 , V_2 ) ;
if ( F_446 ( V_963 , V_2 ) )
F_449 ( V_2 ) ;
if ( F_446 ( V_964 , V_2 ) )
F_450 ( V_2 ) ;
}
V_99 = F_451 ( V_2 ) ;
if ( F_69 ( V_99 ) )
goto V_93;
if ( F_446 ( V_48 , V_2 ) || V_947 ) {
F_438 ( V_2 ) ;
if ( V_2 -> V_5 . V_540 )
V_56 -> V_965 ( V_2 ) ;
else if ( F_431 ( V_2 ) || V_947 )
V_56 -> V_966 ( V_2 ) ;
if ( F_452 ( V_2 ) ) {
F_203 ( V_2 ) ;
F_453 ( V_2 ) ;
}
}
F_157 () ;
V_56 -> V_967 ( V_2 ) ;
if ( V_2 -> V_958 )
F_357 ( V_2 ) ;
F_441 ( V_2 ) ;
V_2 -> V_820 = V_968 ;
F_454 () ;
F_269 () ;
if ( V_2 -> V_820 == V_969 || V_2 -> V_503
|| F_455 () || F_456 ( V_336 ) ) {
V_2 -> V_820 = V_970 ;
F_12 () ;
F_270 () ;
F_158 () ;
V_56 -> V_971 ( V_2 ) ;
V_99 = 1 ;
goto V_93;
}
F_178 ( & V_2 -> V_29 -> V_413 , V_2 -> V_972 ) ;
if ( V_948 )
F_457 ( V_2 -> V_498 ) ;
F_458 () ;
if ( F_69 ( V_2 -> V_5 . V_158 ) ) {
F_459 ( 0 , 7 ) ;
F_459 ( V_2 -> V_5 . V_149 [ 0 ] , 0 ) ;
F_459 ( V_2 -> V_5 . V_149 [ 1 ] , 1 ) ;
F_459 ( V_2 -> V_5 . V_149 [ 2 ] , 2 ) ;
F_459 ( V_2 -> V_5 . V_149 [ 3 ] , 3 ) ;
}
F_460 ( V_2 -> V_973 ) ;
V_56 -> V_733 ( V_2 ) ;
if ( F_461 () )
F_462 () ;
V_2 -> V_5 . V_241 = V_56 -> V_247 ( V_2 ) ;
V_2 -> V_820 = V_970 ;
F_12 () ;
F_270 () ;
++ V_2 -> V_60 . V_974 ;
F_463 () ;
F_464 () ;
F_158 () ;
V_2 -> V_972 = F_177 ( & V_2 -> V_29 -> V_413 ) ;
if ( F_69 ( V_975 == V_976 ) ) {
unsigned long V_932 = F_368 ( V_2 ) ;
F_465 ( V_976 , ( void * ) V_932 ) ;
}
if ( F_69 ( V_2 -> V_5 . V_977 ) )
F_23 ( V_249 , V_2 ) ;
F_466 ( V_2 ) ;
V_99 = V_56 -> V_978 ( V_2 ) ;
V_93:
return V_99 ;
}
static int F_467 ( struct V_1 * V_2 )
{
int V_99 ;
struct V_29 * V_29 = V_2 -> V_29 ;
if ( F_69 ( V_2 -> V_5 . V_904 == V_979 ) ) {
F_96 ( L_28 ,
V_2 -> V_973 , V_2 -> V_5 . V_543 ) ;
F_468 ( V_2 ) ;
V_99 = F_469 ( V_2 ) ;
if ( V_99 )
return V_99 ;
V_2 -> V_5 . V_904 = V_980 ;
}
V_2 -> V_972 = F_177 ( & V_29 -> V_413 ) ;
F_435 ( V_2 ) ;
V_99 = 1 ;
while ( V_99 > 0 ) {
if ( V_2 -> V_5 . V_904 == V_980 &&
! V_2 -> V_5 . V_6 . V_961 )
V_99 = F_445 ( V_2 ) ;
else {
F_178 ( & V_29 -> V_413 , V_2 -> V_972 ) ;
F_470 ( V_2 ) ;
V_2 -> V_972 = F_177 ( & V_29 -> V_413 ) ;
if ( F_446 ( V_981 , V_2 ) )
{
switch( V_2 -> V_5 . V_904 ) {
case V_905 :
V_2 -> V_5 . V_904 =
V_980 ;
case V_980 :
V_2 -> V_5 . V_6 . V_961 = false ;
break;
case V_979 :
default:
V_99 = - V_982 ;
break;
}
}
}
if ( V_99 <= 0 )
break;
F_471 ( V_983 , & V_2 -> V_503 ) ;
if ( F_472 ( V_2 ) )
F_473 ( V_2 ) ;
if ( F_430 ( V_2 ) ) {
V_99 = - V_982 ;
V_2 -> V_733 -> V_741 = V_984 ;
++ V_2 -> V_60 . V_985 ;
}
F_474 ( V_2 ) ;
if ( F_456 ( V_336 ) ) {
V_99 = - V_982 ;
V_2 -> V_733 -> V_741 = V_984 ;
++ V_2 -> V_60 . V_986 ;
}
if ( F_455 () ) {
F_178 ( & V_29 -> V_413 , V_2 -> V_972 ) ;
F_475 ( V_2 ) ;
V_2 -> V_972 = F_177 ( & V_29 -> V_413 ) ;
}
}
F_178 ( & V_29 -> V_413 , V_2 -> V_972 ) ;
F_436 ( V_2 ) ;
return V_99 ;
}
static int F_476 ( struct V_1 * V_2 )
{
struct V_934 * V_733 = V_2 -> V_733 ;
int V_99 ;
if ( ! ( V_2 -> V_5 . V_762 . V_630 || V_2 -> V_740 ) )
return 1 ;
if ( V_2 -> V_740 ) {
V_2 -> V_740 = 0 ;
if ( ! V_2 -> V_746 )
memcpy ( V_2 -> V_729 + V_2 -> V_747 ,
V_733 -> V_734 . V_31 , 8 ) ;
V_2 -> V_747 += 8 ;
if ( V_2 -> V_747 < V_2 -> V_744 ) {
V_733 -> V_741 = V_742 ;
V_733 -> V_734 . V_743 = V_2 -> V_730 + V_2 -> V_747 ;
memcpy ( V_733 -> V_734 . V_31 , V_2 -> V_729 + V_2 -> V_747 , 8 ) ;
V_733 -> V_734 . V_75 = F_274 ( V_2 -> V_744 - V_2 -> V_747 , 8 ) ;
V_733 -> V_734 . V_745 = V_2 -> V_746 ;
V_2 -> V_740 = 1 ;
return 0 ;
}
if ( V_2 -> V_746 )
return 1 ;
V_2 -> V_728 = 1 ;
}
V_2 -> V_972 = F_177 ( & V_2 -> V_29 -> V_413 ) ;
V_99 = F_477 ( V_2 , V_849 ) ;
F_178 ( & V_2 -> V_29 -> V_413 , V_2 -> V_972 ) ;
if ( V_99 != V_835 )
return 0 ;
return 1 ;
}
int F_478 ( struct V_1 * V_2 , struct V_934 * V_934 )
{
int V_99 ;
T_15 V_987 ;
if ( ! F_479 ( V_336 ) && F_480 ( V_336 ) )
return - V_307 ;
if ( V_2 -> V_988 )
F_481 ( V_989 , & V_2 -> V_990 , & V_987 ) ;
if ( F_69 ( V_2 -> V_5 . V_904 == V_991 ) ) {
F_470 ( V_2 ) ;
F_471 ( V_981 , & V_2 -> V_503 ) ;
V_99 = - V_992 ;
goto V_93;
}
if ( ! F_18 ( V_2 -> V_29 ) ) {
if ( F_71 ( V_2 , V_934 -> V_142 ) != 0 ) {
V_99 = - V_493 ;
goto V_93;
}
}
V_99 = F_476 ( V_2 ) ;
if ( V_99 <= 0 )
goto V_93;
V_99 = F_467 ( V_2 ) ;
V_93:
F_433 ( V_2 ) ;
if ( V_2 -> V_988 )
F_481 ( V_989 , & V_987 , NULL ) ;
return V_99 ;
}
int F_482 ( struct V_1 * V_2 , struct V_993 * V_509 )
{
if ( V_2 -> V_5 . V_863 ) {
struct V_722 * V_723 = & V_2 -> V_5 . V_810 ;
memcpy ( V_2 -> V_5 . V_509 , V_723 -> V_509 , sizeof V_723 -> V_509 ) ;
V_2 -> V_5 . V_863 = false ;
}
V_509 -> V_994 = F_81 ( V_2 , V_164 ) ;
V_509 -> V_995 = F_81 ( V_2 , V_917 ) ;
V_509 -> V_996 = F_81 ( V_2 , V_163 ) ;
V_509 -> V_997 = F_81 ( V_2 , V_165 ) ;
V_509 -> V_998 = F_81 ( V_2 , V_919 ) ;
V_509 -> V_999 = F_81 ( V_2 , V_918 ) ;
V_509 -> V_1000 = F_81 ( V_2 , V_807 ) ;
V_509 -> V_1001 = F_81 ( V_2 , V_1002 ) ;
#ifdef F_52
V_509 -> V_1003 = F_81 ( V_2 , V_920 ) ;
V_509 -> V_1004 = F_81 ( V_2 , V_1005 ) ;
V_509 -> V_1006 = F_81 ( V_2 , V_1007 ) ;
V_509 -> V_1008 = F_81 ( V_2 , V_1009 ) ;
V_509 -> V_1010 = F_81 ( V_2 , V_1011 ) ;
V_509 -> V_1012 = F_81 ( V_2 , V_1013 ) ;
V_509 -> V_1014 = F_81 ( V_2 , V_1015 ) ;
V_509 -> V_1016 = F_81 ( V_2 , V_1017 ) ;
#endif
V_509 -> V_932 = F_368 ( V_2 ) ;
V_509 -> V_1018 = F_367 ( V_2 ) ;
return 0 ;
}
int F_483 ( struct V_1 * V_2 , struct V_993 * V_509 )
{
V_2 -> V_5 . V_828 = true ;
V_2 -> V_5 . V_863 = false ;
F_83 ( V_2 , V_164 , V_509 -> V_994 ) ;
F_83 ( V_2 , V_917 , V_509 -> V_995 ) ;
F_83 ( V_2 , V_163 , V_509 -> V_996 ) ;
F_83 ( V_2 , V_165 , V_509 -> V_997 ) ;
F_83 ( V_2 , V_919 , V_509 -> V_998 ) ;
F_83 ( V_2 , V_918 , V_509 -> V_999 ) ;
F_83 ( V_2 , V_807 , V_509 -> V_1000 ) ;
F_83 ( V_2 , V_1002 , V_509 -> V_1001 ) ;
#ifdef F_52
F_83 ( V_2 , V_920 , V_509 -> V_1003 ) ;
F_83 ( V_2 , V_1005 , V_509 -> V_1004 ) ;
F_83 ( V_2 , V_1007 , V_509 -> V_1006 ) ;
F_83 ( V_2 , V_1009 , V_509 -> V_1008 ) ;
F_83 ( V_2 , V_1011 , V_509 -> V_1010 ) ;
F_83 ( V_2 , V_1013 , V_509 -> V_1012 ) ;
F_83 ( V_2 , V_1015 , V_509 -> V_1014 ) ;
F_83 ( V_2 , V_1017 , V_509 -> V_1016 ) ;
#endif
F_373 ( V_2 , V_509 -> V_932 ) ;
F_339 ( V_2 , V_509 -> V_1018 ) ;
V_2 -> V_5 . V_49 . V_50 = false ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
void F_484 ( struct V_1 * V_2 , int * V_146 , int * V_795 )
{
struct V_708 V_1019 ;
F_282 ( V_2 , & V_1019 , V_1020 ) ;
* V_146 = V_1019 . V_146 ;
* V_795 = V_1019 . V_795 ;
}
int F_485 ( struct V_1 * V_2 ,
struct V_1021 * V_1022 )
{
struct V_778 V_779 ;
F_282 ( V_2 , & V_1022 -> V_1019 , V_1020 ) ;
F_282 ( V_2 , & V_1022 -> V_1023 , V_1024 ) ;
F_282 ( V_2 , & V_1022 -> V_1025 , V_1026 ) ;
F_282 ( V_2 , & V_1022 -> V_1027 , V_1028 ) ;
F_282 ( V_2 , & V_1022 -> V_1029 , V_1030 ) ;
F_282 ( V_2 , & V_1022 -> V_1031 , V_1032 ) ;
F_282 ( V_2 , & V_1022 -> V_1033 , V_1034 ) ;
F_282 ( V_2 , & V_1022 -> V_1035 , V_1036 ) ;
V_56 -> V_781 ( V_2 , & V_779 ) ;
V_1022 -> V_1037 . V_790 = V_779 . V_418 ;
V_1022 -> V_1037 . V_791 = V_779 . V_63 ;
V_56 -> V_780 ( V_2 , & V_779 ) ;
V_1022 -> V_1038 . V_790 = V_779 . V_418 ;
V_1022 -> V_1038 . V_791 = V_779 . V_63 ;
V_1022 -> V_100 = F_51 ( V_2 ) ;
V_1022 -> V_62 = V_2 -> V_5 . V_62 ;
V_1022 -> V_84 = F_49 ( V_2 ) ;
V_1022 -> V_126 = F_61 ( V_2 ) ;
V_1022 -> V_142 = F_73 ( V_2 ) ;
V_1022 -> V_110 = V_2 -> V_5 . V_110 ;
V_1022 -> V_30 = F_17 ( V_2 ) ;
memset ( V_1022 -> V_1039 , 0 , sizeof V_1022 -> V_1039 ) ;
if ( V_2 -> V_5 . V_532 . V_50 && ! V_2 -> V_5 . V_532 . V_533 )
F_194 ( V_2 -> V_5 . V_532 . V_16 ,
( unsigned long * ) V_1022 -> V_1039 ) ;
return 0 ;
}
int F_486 ( struct V_1 * V_2 ,
struct V_1040 * V_904 )
{
V_904 -> V_904 = V_2 -> V_5 . V_904 ;
return 0 ;
}
int F_487 ( struct V_1 * V_2 ,
struct V_1040 * V_904 )
{
V_2 -> V_5 . V_904 = V_904 -> V_904 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
int F_488 ( struct V_1 * V_2 , V_758 V_1041 , int V_1042 ,
int V_1043 , bool V_52 , T_1 V_43 )
{
struct V_722 * V_723 = & V_2 -> V_5 . V_810 ;
int V_88 ;
F_366 ( V_2 ) ;
V_88 = F_489 ( V_723 , V_1041 , V_1042 , V_1043 ,
V_52 , V_43 ) ;
if ( V_88 )
return V_833 ;
memcpy ( V_2 -> V_5 . V_509 , V_723 -> V_509 , sizeof V_723 -> V_509 ) ;
F_373 ( V_2 , V_723 -> V_819 ) ;
F_339 ( V_2 , V_723 -> V_818 ) ;
F_23 ( V_48 , V_2 ) ;
return V_835 ;
}
int F_490 ( struct V_1 * V_2 ,
struct V_1021 * V_1022 )
{
int V_1044 = 0 ;
int V_1045 , V_1046 , V_280 ;
struct V_778 V_779 ;
V_779 . V_418 = V_1022 -> V_1037 . V_790 ;
V_779 . V_63 = V_1022 -> V_1037 . V_791 ;
V_56 -> V_783 ( V_2 , & V_779 ) ;
V_779 . V_418 = V_1022 -> V_1038 . V_790 ;
V_779 . V_63 = V_1022 -> V_1038 . V_791 ;
V_56 -> V_782 ( V_2 , & V_779 ) ;
V_2 -> V_5 . V_62 = V_1022 -> V_62 ;
V_1044 |= F_49 ( V_2 ) != V_1022 -> V_84 ;
V_2 -> V_5 . V_84 = V_1022 -> V_84 ;
F_44 ( V_139 , ( V_140 * ) & V_2 -> V_5 . V_96 ) ;
F_71 ( V_2 , V_1022 -> V_142 ) ;
V_1044 |= V_2 -> V_5 . V_110 != V_1022 -> V_110 ;
V_56 -> F_84 ( V_2 , V_1022 -> V_110 ) ;
F_19 ( V_2 , V_1022 -> V_30 ) ;
V_1044 |= F_51 ( V_2 ) != V_1022 -> V_100 ;
V_56 -> V_115 ( V_2 , V_1022 -> V_100 ) ;
V_2 -> V_5 . V_100 = V_1022 -> V_100 ;
V_1044 |= F_61 ( V_2 ) != V_1022 -> V_126 ;
V_56 -> V_136 ( V_2 , V_1022 -> V_126 ) ;
if ( V_1022 -> V_126 & V_134 )
F_65 ( V_2 ) ;
V_280 = F_177 ( & V_2 -> V_29 -> V_413 ) ;
if ( ! F_46 ( V_2 ) && F_47 ( V_2 ) ) {
F_41 ( V_2 , V_2 -> V_5 . V_83 , F_49 ( V_2 ) ) ;
V_1044 = 1 ;
}
F_178 ( & V_2 -> V_29 -> V_413 , V_280 ) ;
if ( V_1044 )
F_55 ( V_2 ) ;
V_1046 = ( sizeof V_1022 -> V_1039 ) << 3 ;
V_1045 = F_491 (
( const unsigned long * ) V_1022 -> V_1039 , V_1046 ) ;
if ( V_1045 < V_1046 ) {
F_205 ( V_2 , V_1045 , false ) ;
F_96 ( L_29 , V_1045 ) ;
}
F_281 ( V_2 , & V_1022 -> V_1019 , V_1020 ) ;
F_281 ( V_2 , & V_1022 -> V_1023 , V_1024 ) ;
F_281 ( V_2 , & V_1022 -> V_1025 , V_1026 ) ;
F_281 ( V_2 , & V_1022 -> V_1027 , V_1028 ) ;
F_281 ( V_2 , & V_1022 -> V_1029 , V_1030 ) ;
F_281 ( V_2 , & V_1022 -> V_1031 , V_1032 ) ;
F_281 ( V_2 , & V_1022 -> V_1033 , V_1034 ) ;
F_281 ( V_2 , & V_1022 -> V_1035 , V_1036 ) ;
F_203 ( V_2 ) ;
if ( F_492 ( V_2 ) && F_368 ( V_2 ) == 0xfff0 &&
V_1022 -> V_1019 . V_784 == 0xf000 && V_1022 -> V_1019 . V_791 == 0xffff0000 &&
! F_369 ( V_2 ) )
V_2 -> V_5 . V_904 = V_980 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
int F_493 ( struct V_1 * V_2 ,
struct V_1047 * V_1048 )
{
unsigned long V_1018 ;
int V_3 , V_99 ;
if ( V_1048 -> V_637 & ( V_1049 | V_1050 ) ) {
V_99 = - V_1051 ;
if ( V_2 -> V_5 . V_49 . V_50 )
goto V_93;
if ( V_1048 -> V_637 & V_1049 )
F_24 ( V_2 , V_1052 ) ;
else
F_24 ( V_2 , V_1053 ) ;
}
V_1018 = F_367 ( V_2 ) ;
V_2 -> V_147 = V_1048 -> V_637 ;
if ( ! ( V_2 -> V_147 & V_1054 ) )
V_2 -> V_147 = 0 ;
if ( V_2 -> V_147 & V_148 ) {
for ( V_3 = 0 ; V_3 < V_1055 ; ++ V_3 )
V_2 -> V_5 . V_149 [ V_3 ] = V_1048 -> V_5 . V_1056 [ V_3 ] ;
V_2 -> V_5 . V_158 =
( V_1048 -> V_5 . V_1056 [ 7 ] & V_159 ) ;
} else {
for ( V_3 = 0 ; V_3 < V_1055 ; V_3 ++ )
V_2 -> V_5 . V_149 [ V_3 ] = V_2 -> V_5 . V_146 [ V_3 ] ;
V_2 -> V_5 . V_158 = ( V_2 -> V_5 . V_154 & V_159 ) ;
}
if ( V_2 -> V_147 & V_1057 )
V_2 -> V_5 . V_1058 = F_368 ( V_2 ) +
F_323 ( V_2 , V_1020 ) ;
F_339 ( V_2 , V_1018 ) ;
V_56 -> V_1059 ( V_2 , V_1048 ) ;
V_99 = 0 ;
V_93:
return V_99 ;
}
int F_494 ( struct V_1 * V_2 ,
struct V_1060 * V_1033 )
{
unsigned long V_1061 = V_1033 -> V_1062 ;
T_4 V_329 ;
int V_280 ;
V_280 = F_177 ( & V_2 -> V_29 -> V_413 ) ;
V_329 = F_288 ( V_2 , V_1061 , NULL ) ;
F_178 ( & V_2 -> V_29 -> V_413 , V_280 ) ;
V_1033 -> V_1063 = V_329 ;
V_1033 -> V_1064 = V_329 != V_80 ;
V_1033 -> V_1065 = 1 ;
V_1033 -> V_1066 = 0 ;
return 0 ;
}
int F_495 ( struct V_1 * V_2 , struct V_1067 * V_1068 )
{
struct V_560 * V_559 =
& V_2 -> V_5 . V_555 . V_556 -> V_559 ;
memcpy ( V_1068 -> V_1069 , V_559 -> V_1070 , 128 ) ;
V_1068 -> V_1071 = V_559 -> V_1072 ;
V_1068 -> V_1073 = V_559 -> V_1074 ;
V_1068 -> V_1075 = V_559 -> V_1076 ;
V_1068 -> V_1077 = V_559 -> V_1078 ;
V_1068 -> V_1079 = V_559 -> V_932 ;
V_1068 -> V_1080 = V_559 -> V_1081 ;
memcpy ( V_1068 -> V_1082 , V_559 -> V_1083 , sizeof V_559 -> V_1083 ) ;
return 0 ;
}
int F_496 ( struct V_1 * V_2 , struct V_1067 * V_1068 )
{
struct V_560 * V_559 =
& V_2 -> V_5 . V_555 . V_556 -> V_559 ;
memcpy ( V_559 -> V_1070 , V_1068 -> V_1069 , 128 ) ;
V_559 -> V_1072 = V_1068 -> V_1071 ;
V_559 -> V_1074 = V_1068 -> V_1073 ;
V_559 -> V_1076 = V_1068 -> V_1075 ;
V_559 -> V_1078 = V_1068 -> V_1077 ;
V_559 -> V_932 = V_1068 -> V_1079 ;
V_559 -> V_1081 = V_1068 -> V_1080 ;
memcpy ( V_559 -> V_1083 , V_1068 -> V_1082 , sizeof V_559 -> V_1083 ) ;
return 0 ;
}
int F_497 ( struct V_1 * V_2 )
{
int V_55 ;
V_55 = F_498 ( & V_2 -> V_5 . V_555 ) ;
if ( V_55 )
return V_55 ;
F_499 ( & V_2 -> V_5 . V_555 ) ;
V_2 -> V_5 . V_119 = V_121 ;
V_2 -> V_5 . V_100 |= V_107 ;
return 0 ;
}
static void F_500 ( struct V_1 * V_2 )
{
F_501 ( & V_2 -> V_5 . V_555 ) ;
}
void F_357 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1084 )
return;
F_443 ( V_2 ) ;
V_2 -> V_1084 = 1 ;
F_502 ( V_336 ) ;
F_503 ( & V_2 -> V_5 . V_555 ) ;
F_504 ( 1 ) ;
}
void F_199 ( struct V_1 * V_2 )
{
F_443 ( V_2 ) ;
if ( ! V_2 -> V_1084 )
return;
V_2 -> V_1084 = 0 ;
F_505 ( & V_2 -> V_5 . V_555 ) ;
++ V_2 -> V_60 . V_1085 ;
F_23 ( V_957 , V_2 ) ;
F_504 ( 0 ) ;
}
void F_506 ( struct V_1 * V_2 )
{
F_144 ( V_2 ) ;
F_507 ( V_2 -> V_5 . V_500 ) ;
F_500 ( V_2 ) ;
V_56 -> V_1086 ( V_2 ) ;
}
struct V_1 * F_508 ( struct V_29 * V_29 ,
unsigned int V_647 )
{
if ( F_111 () && F_260 ( & V_29 -> V_668 ) != 0 )
F_317 ( V_760
L_30
L_31 ) ;
return V_56 -> V_1087 ( V_29 , V_647 ) ;
}
int F_509 ( struct V_1 * V_2 )
{
int V_99 ;
V_2 -> V_5 . V_275 . V_1088 = 1 ;
V_501 ( V_2 ) ;
V_99 = F_469 ( V_2 ) ;
if ( V_99 == 0 )
V_99 = F_510 ( V_2 ) ;
V_506 ( V_2 ) ;
return V_99 ;
}
void F_511 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_6 . V_330 = 0 ;
V_501 ( V_2 ) ;
F_447 ( V_2 ) ;
V_506 ( V_2 ) ;
F_500 ( V_2 ) ;
V_56 -> V_1086 ( V_2 ) ;
}
int F_469 ( struct V_1 * V_2 )
{
F_512 ( & V_2 -> V_5 . V_68 , 0 ) ;
V_2 -> V_5 . V_540 = 0 ;
V_2 -> V_5 . V_539 = false ;
V_2 -> V_5 . V_158 = 0 ;
memset ( V_2 -> V_5 . V_146 , 0 , sizeof( V_2 -> V_5 . V_146 ) ) ;
V_2 -> V_5 . V_151 = V_153 ;
V_2 -> V_5 . V_154 = V_156 ;
F_23 ( V_48 , V_2 ) ;
V_2 -> V_5 . V_6 . V_330 = 0 ;
V_2 -> V_5 . V_334 . V_330 = 0 ;
F_144 ( V_2 ) ;
F_54 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_961 = false ;
F_513 ( V_2 ) ;
return V_56 -> V_1089 ( V_2 ) ;
}
int F_514 ( void * V_494 )
{
struct V_29 * V_29 ;
struct V_1 * V_2 ;
int V_3 ;
int V_88 ;
T_2 V_1090 ;
T_2 V_1091 = 0 ;
bool V_1092 , V_1093 = false ;
F_13 () ;
V_88 = V_56 -> V_1094 ( V_494 ) ;
if ( V_88 != 0 )
return V_88 ;
V_1090 = F_195 () ;
V_1092 = ! F_111 () ;
F_394 (kvm, &vm_list, vm_list) {
F_169 (i, vcpu, kvm) {
if ( ! V_1092 && V_2 -> V_498 == F_395 () )
F_194 ( V_249 , & V_2 -> V_503 ) ;
if ( V_1092 && V_2 -> V_5 . V_505 > V_1090 ) {
V_1093 = true ;
if ( V_2 -> V_5 . V_505 > V_1091 )
V_1091 = V_2 -> V_5 . V_505 ;
}
}
}
if ( V_1093 ) {
T_2 V_1095 = V_1091 - V_1090 ;
F_394 (kvm, &vm_list, vm_list) {
F_169 (i, vcpu, kvm) {
V_2 -> V_5 . V_502 += V_1095 ;
V_2 -> V_5 . V_505 = V_1090 ;
}
V_29 -> V_5 . V_230 = 0 ;
V_29 -> V_5 . V_231 = 0 ;
}
}
return 0 ;
}
void F_515 ( void * V_494 )
{
V_56 -> V_1096 ( V_494 ) ;
F_16 ( V_494 ) ;
}
int F_516 ( void )
{
return V_56 -> V_1097 () ;
}
void F_517 ( void )
{
V_56 -> V_1098 () ;
}
void F_518 ( void * V_1099 )
{
V_56 -> V_1100 ( V_1099 ) ;
}
bool F_519 ( struct V_1 * V_2 )
{
return F_18 ( V_2 -> V_29 ) == ( V_2 -> V_5 . V_510 != NULL ) ;
}
int F_520 ( struct V_1 * V_2 )
{
struct V_305 * V_305 ;
struct V_29 * V_29 ;
int V_99 ;
F_284 ( V_2 -> V_29 == NULL ) ;
V_29 = V_2 -> V_29 ;
V_2 -> V_5 . V_810 . V_736 = & V_1101 ;
if ( ! F_18 ( V_29 ) || F_492 ( V_2 ) )
V_2 -> V_5 . V_904 = V_980 ;
else
V_2 -> V_5 . V_904 = V_991 ;
V_305 = F_521 ( V_574 | V_1102 ) ;
if ( ! V_305 ) {
V_99 = - V_307 ;
goto V_1103;
}
V_2 -> V_5 . V_765 = F_522 ( V_305 ) ;
F_107 ( V_2 , V_880 ) ;
V_99 = F_523 ( V_2 ) ;
if ( V_99 < 0 )
goto V_1104;
if ( F_18 ( V_29 ) ) {
V_99 = F_524 ( V_2 ) ;
if ( V_99 < 0 )
goto V_1105;
}
V_2 -> V_5 . V_294 = F_221 ( V_370 * sizeof( T_2 ) * 4 ,
V_574 ) ;
if ( ! V_2 -> V_5 . V_294 ) {
V_99 = - V_307 ;
goto V_1106;
}
V_2 -> V_5 . V_286 = V_370 ;
if ( ! F_525 ( & V_2 -> V_5 . V_500 , V_574 ) )
goto V_1107;
F_1 ( V_2 ) ;
F_526 ( V_2 ) ;
return 0 ;
V_1107:
F_130 ( V_2 -> V_5 . V_294 ) ;
V_1106:
F_527 ( V_2 ) ;
V_1105:
F_528 ( V_2 ) ;
V_1104:
F_529 ( ( unsigned long ) V_2 -> V_5 . V_765 ) ;
V_1103:
return V_99 ;
}
void F_530 ( struct V_1 * V_2 )
{
int V_280 ;
F_531 ( V_2 ) ;
F_130 ( V_2 -> V_5 . V_294 ) ;
F_527 ( V_2 ) ;
V_280 = F_177 ( & V_2 -> V_29 -> V_413 ) ;
F_528 ( V_2 ) ;
F_178 ( & V_2 -> V_29 -> V_413 , V_280 ) ;
F_529 ( ( unsigned long ) V_2 -> V_5 . V_765 ) ;
}
int F_532 ( struct V_29 * V_29 , unsigned long type )
{
if ( type )
return - V_493 ;
F_533 ( & V_29 -> V_5 . V_1108 ) ;
F_533 ( & V_29 -> V_5 . V_1109 ) ;
F_194 ( V_683 , & V_29 -> V_5 . V_1110 ) ;
F_534 ( & V_29 -> V_5 . V_228 ) ;
return 0 ;
}
static void F_535 ( struct V_1 * V_2 )
{
V_501 ( V_2 ) ;
F_447 ( V_2 ) ;
V_506 ( V_2 ) ;
}
static void F_536 ( struct V_29 * V_29 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_169 (i, vcpu, kvm) {
F_54 ( V_2 ) ;
F_535 ( V_2 ) ;
}
F_169 (i, vcpu, kvm)
F_506 ( V_2 ) ;
F_161 ( & V_29 -> V_385 ) ;
for ( V_3 = 0 ; V_3 < F_260 ( & V_29 -> V_668 ) ; V_3 ++ )
V_29 -> V_1111 [ V_3 ] = NULL ;
F_512 ( & V_29 -> V_668 , 0 ) ;
F_162 ( & V_29 -> V_385 ) ;
}
void F_537 ( struct V_29 * V_29 )
{
F_538 ( V_29 ) ;
F_539 ( V_29 ) ;
}
void F_540 ( struct V_29 * V_29 )
{
F_541 ( V_29 ) ;
F_130 ( V_29 -> V_5 . V_665 ) ;
F_130 ( V_29 -> V_5 . V_1112 ) ;
F_536 ( V_29 ) ;
if ( V_29 -> V_5 . V_1113 )
F_542 ( V_29 -> V_5 . V_1113 ) ;
if ( V_29 -> V_5 . V_1114 )
F_542 ( V_29 -> V_5 . V_1114 ) ;
}
void F_543 ( struct V_640 * free ,
struct V_640 * V_1115 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1116 - 1 ; ++ V_3 ) {
if ( ! V_1115 || free -> V_5 . V_1117 [ V_3 ] != V_1115 -> V_5 . V_1117 [ V_3 ] ) {
F_544 ( free -> V_5 . V_1117 [ V_3 ] ) ;
free -> V_5 . V_1117 [ V_3 ] = NULL ;
}
}
}
int F_545 ( struct V_640 * V_10 , unsigned long V_1118 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1116 - 1 ; ++ V_3 ) {
unsigned long V_1119 ;
int V_1120 ;
int V_684 = V_3 + 2 ;
V_1120 = F_546 ( V_10 -> V_646 + V_1118 - 1 ,
V_10 -> V_646 , V_684 ) + 1 ;
V_10 -> V_5 . V_1117 [ V_3 ] =
F_547 ( V_1120 * sizeof( * V_10 -> V_5 . V_1117 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1117 [ V_3 ] )
goto V_308;
if ( V_10 -> V_646 & ( F_548 ( V_684 ) - 1 ) )
V_10 -> V_5 . V_1117 [ V_3 ] [ 0 ] . V_1121 = 1 ;
if ( ( V_10 -> V_646 + V_1118 ) & ( F_548 ( V_684 ) - 1 ) )
V_10 -> V_5 . V_1117 [ V_3 ] [ V_1120 - 1 ] . V_1121 = 1 ;
V_1119 = V_10 -> V_1122 >> V_86 ;
if ( ( V_10 -> V_646 ^ V_1119 ) & ( F_548 ( V_684 ) - 1 ) ||
! F_549 () ) {
unsigned long V_702 ;
for ( V_702 = 0 ; V_702 < V_1120 ; ++ V_702 )
V_10 -> V_5 . V_1117 [ V_3 ] [ V_702 ] . V_1121 = 1 ;
}
}
return 0 ;
V_308:
for ( V_3 = 0 ; V_3 < V_1116 - 1 ; ++ V_3 ) {
F_544 ( V_10 -> V_5 . V_1117 [ V_3 ] ) ;
V_10 -> V_5 . V_1117 [ V_3 ] = NULL ;
}
return - V_307 ;
}
int F_550 ( struct V_29 * V_29 ,
struct V_640 * V_641 ,
struct V_640 V_753 ,
struct V_1123 * V_1124 ,
int V_1125 )
{
int V_1118 = V_641 -> V_1118 ;
int V_1126 = V_1127 | V_1128 ;
if ( V_641 -> V_647 >= V_462 )
V_1126 = V_1129 | V_1128 ;
if ( ! V_1125 ) {
if ( V_1118 && ! V_753 . V_1130 ) {
unsigned long V_1122 ;
V_1122 = F_551 ( NULL , 0 ,
V_1118 * V_87 ,
V_1131 | V_1132 ,
V_1126 ,
0 ) ;
if ( F_128 ( ( void * ) V_1122 ) )
return F_129 ( ( void * ) V_1122 ) ;
V_641 -> V_1122 = V_1122 ;
}
}
return 0 ;
}
void F_552 ( struct V_29 * V_29 ,
struct V_1123 * V_1124 ,
struct V_640 V_753 ,
int V_1125 )
{
int V_1133 = 0 , V_1118 = V_1124 -> V_1134 >> V_86 ;
if ( ! V_1125 && ! V_753 . V_1125 && V_753 . V_1130 && ! V_1118 ) {
int V_88 ;
V_88 = F_553 ( V_753 . V_1122 ,
V_753 . V_1118 * V_87 ) ;
if ( V_88 < 0 )
F_9 ( V_760
L_32
L_33 ) ;
}
if ( ! V_29 -> V_5 . V_613 )
V_1133 = F_554 ( V_29 ) ;
F_230 ( & V_29 -> V_612 ) ;
if ( V_1133 )
F_231 ( V_29 , V_1133 ) ;
F_250 ( V_29 , V_1124 -> V_10 ) ;
F_232 ( & V_29 -> V_612 ) ;
}
void F_555 ( struct V_29 * V_29 )
{
F_429 ( V_29 ) ;
F_556 ( V_29 ) ;
}
int F_557 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_904 == V_980 &&
! V_2 -> V_5 . V_6 . V_961 )
|| ! F_558 ( & V_2 -> V_1135 . V_1136 )
|| V_2 -> V_5 . V_904 == V_979
|| F_260 ( & V_2 -> V_5 . V_68 ) ||
( F_432 ( V_2 ) &&
F_431 ( V_2 ) ) ;
}
void F_559 ( struct V_1 * V_2 )
{
int V_1137 ;
int V_498 = V_2 -> V_498 ;
if ( F_560 ( & V_2 -> V_1138 ) ) {
F_561 ( & V_2 -> V_1138 ) ;
++ V_2 -> V_60 . V_1139 ;
}
V_1137 = F_327 () ;
if ( V_498 != V_1137 && ( unsigned ) V_498 < V_1140 && F_562 ( V_498 ) )
if ( F_563 ( V_2 ) == V_968 )
F_457 ( V_498 ) ;
F_329 () ;
}
int F_432 ( struct V_1 * V_2 )
{
return V_56 -> V_946 ( V_2 ) ;
}
bool F_564 ( struct V_1 * V_2 , unsigned long V_1141 )
{
unsigned long V_1142 = F_368 ( V_2 ) +
F_323 ( V_2 , V_1020 ) ;
return V_1142 == V_1141 ;
}
unsigned long F_367 ( struct V_1 * V_2 )
{
unsigned long V_1018 ;
V_1018 = V_56 -> V_1143 ( V_2 ) ;
if ( V_2 -> V_147 & V_1057 )
V_1018 &= ~ V_1144 ;
return V_1018 ;
}
void F_339 ( struct V_1 * V_2 , unsigned long V_1018 )
{
if ( V_2 -> V_147 & V_1057 &&
F_564 ( V_2 , V_2 -> V_5 . V_1058 ) )
V_1018 |= V_1144 ;
V_56 -> V_1145 ( V_2 , V_1018 ) ;
F_23 ( V_48 , V_2 ) ;
}
void F_565 ( struct V_1 * V_2 , struct V_1146 * V_1147 )
{
int V_99 ;
if ( ( V_2 -> V_5 . V_67 . V_846 != V_1147 -> V_5 . V_846 ) ||
F_154 ( V_1147 -> V_305 ) )
return;
V_99 = F_451 ( V_2 ) ;
if ( F_69 ( V_99 ) )
return;
if ( ! V_2 -> V_5 . V_67 . V_846 &&
V_1147 -> V_5 . V_84 != V_2 -> V_5 . V_67 . V_1148 ( V_2 ) )
return;
V_2 -> V_5 . V_67 . V_1149 ( V_2 , V_1147 -> V_715 , 0 , true ) ;
}
static inline T_1 F_566 ( T_3 V_82 )
{
return F_567 ( V_82 & 0xffffffff , F_568 ( V_4 ) ) ;
}
static inline T_1 F_569 ( T_1 V_1150 )
{
return ( V_1150 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_570 ( struct V_1 * V_2 , T_3 V_82 )
{
T_1 V_1150 = F_566 ( V_82 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1150 ] != ~ 0 )
V_1150 = F_569 ( V_1150 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1150 ] = V_82 ;
}
static T_1 F_571 ( struct V_1 * V_2 , T_3 V_82 )
{
int V_3 ;
T_1 V_1150 = F_566 ( V_82 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1150 ] != V_82 &&
V_2 -> V_5 . V_6 . V_7 [ V_1150 ] != ~ 0 ) ; V_3 ++ )
V_1150 = F_569 ( V_1150 ) ;
return V_1150 ;
}
bool F_572 ( struct V_1 * V_2 , T_3 V_82 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_571 ( V_2 , V_82 ) ] == V_82 ;
}
static void F_573 ( struct V_1 * V_2 , T_3 V_82 )
{
T_1 V_3 , V_702 , V_1151 ;
V_3 = V_702 = F_571 ( V_2 , V_82 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_702 = F_569 ( V_702 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_702 ] == ~ 0 )
return;
V_1151 = F_566 ( V_2 -> V_5 . V_6 . V_7 [ V_702 ] ) ;
} while ( ( V_3 <= V_702 ) ? ( V_3 < V_1151 && V_1151 <= V_702 ) : ( V_3 < V_1151 || V_1151 <= V_702 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_702 ] ;
V_3 = V_702 ;
}
}
static int F_574 ( struct V_1 * V_2 , T_1 V_145 )
{
return F_149 ( V_2 -> V_29 , & V_2 -> V_5 . V_6 . V_31 , & V_145 ,
sizeof( V_145 ) ) ;
}
void F_575 ( struct V_1 * V_2 ,
struct V_1146 * V_1147 )
{
struct V_58 V_59 ;
F_576 ( V_1147 -> V_5 . V_1152 , V_1147 -> V_715 ) ;
F_570 ( V_2 , V_1147 -> V_5 . V_82 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_330 & V_331 ) ||
( V_2 -> V_5 . V_6 . V_332 &&
V_56 -> V_71 ( V_2 ) == 0 ) )
F_23 ( V_960 , V_2 ) ;
else if ( ! F_574 ( V_2 , V_1153 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_811 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_1147 -> V_5 . V_1152 ;
F_28 ( V_2 , & V_59 ) ;
}
}
void F_577 ( struct V_1 * V_2 ,
struct V_1146 * V_1147 )
{
struct V_58 V_59 ;
F_578 ( V_1147 -> V_5 . V_1152 , V_1147 -> V_715 ) ;
if ( F_154 ( V_1147 -> V_305 ) )
V_1147 -> V_5 . V_1152 = ~ 0 ;
else
F_573 ( V_2 , V_1147 -> V_5 . V_82 ) ;
if ( ( V_2 -> V_5 . V_6 . V_330 & V_331 ) &&
! F_574 ( V_2 , V_1154 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_811 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_1147 -> V_5 . V_1152 ;
F_28 ( V_2 , & V_59 ) ;
}
V_2 -> V_5 . V_6 . V_961 = false ;
V_2 -> V_5 . V_904 = V_980 ;
}
bool F_579 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_330 & V_331 ) )
return true ;
else
return ! F_434 ( V_2 ) &&
V_56 -> V_946 ( V_2 ) ;
}
