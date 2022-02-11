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
F_23 ( V_48 , V_2 ) ;
V_2 -> V_5 . V_68 = 1 ;
}
void F_29 ( struct V_1 * V_2 , unsigned V_16 , T_1 V_43 )
{
F_22 ( V_2 , V_16 , true , V_43 , false ) ;
}
void F_33 ( struct V_1 * V_2 , unsigned V_16 , T_1 V_43 )
{
F_22 ( V_2 , V_16 , true , V_43 , true ) ;
}
bool F_34 ( struct V_1 * V_2 , int V_69 )
{
if ( V_56 -> V_70 ( V_2 ) <= V_69 )
return true ;
F_29 ( V_2 , V_39 , 0 ) ;
return false ;
}
int F_35 ( struct V_1 * V_2 , struct V_71 * V_67 ,
T_3 V_72 , void * V_31 , int V_73 , int V_74 ,
T_1 V_75 )
{
T_3 V_76 ;
T_4 V_77 ;
V_77 = F_36 ( V_72 ) ;
V_76 = V_67 -> V_78 ( V_2 , V_77 , V_75 ) ;
if ( V_76 == V_79 )
return - V_80 ;
V_76 = F_37 ( V_76 ) ;
return F_38 ( V_2 -> V_29 , V_76 , V_31 , V_73 , V_74 ) ;
}
int F_39 ( struct V_1 * V_2 , T_3 V_81 ,
void * V_31 , int V_73 , int V_74 , T_1 V_75 )
{
return F_35 ( V_2 , V_2 -> V_5 . V_82 , V_81 ,
V_31 , V_73 , V_74 , V_75 ) ;
}
int F_40 ( struct V_1 * V_2 , struct V_71 * V_67 , unsigned long V_83 )
{
T_3 V_84 = V_83 >> V_85 ;
unsigned V_73 = ( ( V_83 & ( V_86 - 1 ) ) >> 5 ) << 2 ;
int V_3 ;
int V_87 ;
T_2 V_88 [ F_41 ( V_67 -> V_89 ) ] ;
V_87 = F_35 ( V_2 , V_67 , V_84 , V_88 ,
V_73 * sizeof( T_2 ) , sizeof( V_88 ) ,
V_90 | V_91 ) ;
if ( V_87 < 0 ) {
V_87 = 0 ;
goto V_92;
}
for ( V_3 = 0 ; V_3 < F_41 ( V_88 ) ; ++ V_3 ) {
if ( F_42 ( V_88 [ V_3 ] ) &&
( V_88 [ V_3 ] & V_2 -> V_5 . V_67 . V_93 [ 0 ] [ 2 ] ) ) {
V_87 = 0 ;
goto V_92;
}
}
V_87 = 1 ;
memcpy ( V_67 -> V_89 , V_88 , sizeof( V_67 -> V_89 ) ) ;
F_43 ( V_94 ,
( unsigned long * ) & V_2 -> V_5 . V_95 ) ;
F_43 ( V_94 ,
( unsigned long * ) & V_2 -> V_5 . V_96 ) ;
V_92:
return V_87 ;
}
static bool F_44 ( struct V_1 * V_2 )
{
T_2 V_88 [ F_41 ( V_2 -> V_5 . V_82 -> V_89 ) ] ;
bool V_97 = true ;
int V_73 ;
T_3 V_81 ;
int V_98 ;
if ( F_45 ( V_2 ) || ! F_46 ( V_2 ) )
return false ;
if ( ! F_47 ( V_94 ,
( unsigned long * ) & V_2 -> V_5 . V_95 ) )
return true ;
V_81 = ( F_48 ( V_2 ) & ~ 31u ) >> V_85 ;
V_73 = ( F_48 ( V_2 ) & ~ 31u ) & ( V_86 - 1 ) ;
V_98 = F_39 ( V_2 , V_81 , V_88 , V_73 , sizeof( V_88 ) ,
V_90 | V_91 ) ;
if ( V_98 < 0 )
goto V_92;
V_97 = memcmp ( V_88 , V_2 -> V_5 . V_82 -> V_89 , sizeof( V_88 ) ) != 0 ;
V_92:
return V_97 ;
}
int F_49 ( struct V_1 * V_2 , unsigned long V_99 )
{
unsigned long V_100 = F_50 ( V_2 ) ;
unsigned long V_101 = V_102 | V_103 |
V_104 | V_105 ;
V_99 |= V_106 ;
#ifdef F_51
if ( V_99 & 0xffffffff00000000UL )
return 1 ;
#endif
V_99 &= ~ V_107 ;
if ( ( V_99 & V_105 ) && ! ( V_99 & V_104 ) )
return 1 ;
if ( ( V_99 & V_102 ) && ! ( V_99 & V_108 ) )
return 1 ;
if ( ! F_52 ( V_2 ) && ( V_99 & V_102 ) ) {
#ifdef F_51
if ( ( V_2 -> V_5 . V_109 & V_110 ) ) {
int V_111 , V_112 ;
if ( ! F_46 ( V_2 ) )
return 1 ;
V_56 -> V_113 ( V_2 , & V_111 , & V_112 ) ;
if ( V_112 )
return 1 ;
} else
#endif
if ( F_46 ( V_2 ) && ! F_40 ( V_2 , V_2 -> V_5 . V_82 ,
F_48 ( V_2 ) ) )
return 1 ;
}
V_56 -> V_114 ( V_2 , V_99 ) ;
if ( ( V_99 ^ V_100 ) & V_102 ) {
F_53 ( V_2 ) ;
F_1 ( V_2 ) ;
}
if ( ( V_99 ^ V_100 ) & V_101 )
F_54 ( V_2 ) ;
return 0 ;
}
void F_55 ( struct V_1 * V_2 , unsigned long V_115 )
{
( void ) F_49 ( V_2 , F_56 ( V_2 , ~ 0x0eul ) | ( V_115 & 0x0f ) ) ;
}
int F_57 ( struct V_1 * V_2 , T_1 V_116 , T_2 V_117 )
{
T_2 V_118 ;
if ( V_116 != V_119 )
return 1 ;
V_118 = V_117 ;
if ( V_56 -> V_70 ( V_2 ) != 0 )
return 1 ;
if ( ! ( V_118 & V_120 ) )
return 1 ;
if ( ( V_118 & V_121 ) && ! ( V_118 & V_122 ) )
return 1 ;
if ( V_118 & ~ V_123 )
return 1 ;
V_2 -> V_5 . V_118 = V_118 ;
V_2 -> V_124 = 0 ;
return 0 ;
}
int F_58 ( struct V_1 * V_2 , T_1 V_116 , T_2 V_117 )
{
if ( F_57 ( V_2 , V_116 , V_117 ) ) {
F_27 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
static bool F_59 ( struct V_1 * V_2 )
{
struct V_125 * V_126 ;
V_126 = F_60 ( V_2 , 1 , 0 ) ;
return V_126 && ( V_126 -> V_127 & F_61 ( V_128 ) ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_125 * V_126 ;
V_126 = F_60 ( V_2 , 1 , 0 ) ;
if ( ! V_126 )
return;
if ( V_129 && V_126 -> V_130 == 0x1 ) {
V_126 -> V_127 &= ~ ( F_61 ( V_131 ) ) ;
if ( F_63 ( V_2 , V_132 ) )
V_126 -> V_127 |= F_61 ( V_131 ) ;
}
}
int F_64 ( struct V_1 * V_2 , unsigned long V_133 )
{
unsigned long V_134 = F_65 ( V_2 ) ;
unsigned long V_135 = V_136 | V_137 | V_138 ;
if ( V_133 & V_139 )
return 1 ;
if ( ! F_59 ( V_2 ) && ( V_133 & V_132 ) )
return 1 ;
if ( F_45 ( V_2 ) ) {
if ( ! ( V_133 & V_138 ) )
return 1 ;
} else if ( F_52 ( V_2 ) && ( V_133 & V_138 )
&& ( ( V_133 ^ V_134 ) & V_135 )
&& ! F_40 ( V_2 , V_2 -> V_5 . V_82 ,
F_48 ( V_2 ) ) )
return 1 ;
if ( V_133 & V_140 )
return 1 ;
V_56 -> V_141 ( V_2 , V_133 ) ;
if ( ( V_133 ^ V_134 ) & V_135 )
F_54 ( V_2 ) ;
if ( ( V_133 ^ V_134 ) & V_132 )
F_62 ( V_2 ) ;
return 0 ;
}
int F_66 ( struct V_1 * V_2 , unsigned long V_83 )
{
if ( V_83 == F_48 ( V_2 ) && ! F_44 ( V_2 ) ) {
F_67 ( V_2 ) ;
F_68 ( V_2 ) ;
return 0 ;
}
if ( F_45 ( V_2 ) ) {
if ( V_83 & V_142 )
return 1 ;
} else {
if ( F_46 ( V_2 ) ) {
if ( V_83 & V_143 )
return 1 ;
if ( F_52 ( V_2 ) &&
! F_40 ( V_2 , V_2 -> V_5 . V_82 , V_83 ) )
return 1 ;
}
}
if ( F_69 ( ! F_70 ( V_2 -> V_29 , V_83 >> V_85 ) ) )
return 1 ;
V_2 -> V_5 . V_83 = V_83 ;
F_43 ( V_144 , ( V_145 * ) & V_2 -> V_5 . V_95 ) ;
V_2 -> V_5 . V_67 . V_146 ( V_2 ) ;
return 0 ;
}
int F_71 ( struct V_1 * V_2 , unsigned long V_147 )
{
if ( V_147 & V_148 )
return 1 ;
if ( F_18 ( V_2 -> V_29 ) )
F_72 ( V_2 , V_147 ) ;
else
V_2 -> V_5 . V_147 = V_147 ;
return 0 ;
}
unsigned long F_73 ( struct V_1 * V_2 )
{
if ( F_18 ( V_2 -> V_29 ) )
return F_74 ( V_2 ) ;
else
return V_2 -> V_5 . V_147 ;
}
static int F_75 ( struct V_1 * V_2 , int V_149 , unsigned long V_150 )
{
switch ( V_149 ) {
case 0 ... 3 :
V_2 -> V_5 . V_151 [ V_149 ] = V_150 ;
if ( ! ( V_2 -> V_152 & V_153 ) )
V_2 -> V_5 . V_154 [ V_149 ] = V_150 ;
break;
case 4 :
if ( F_63 ( V_2 , V_155 ) )
return 1 ;
case 6 :
if ( V_150 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_156 = ( V_150 & V_157 ) | V_158 ;
break;
case 5 :
if ( F_63 ( V_2 , V_155 ) )
return 1 ;
default:
if ( V_150 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_159 = ( V_150 & V_160 ) | V_161 ;
if ( ! ( V_2 -> V_152 & V_153 ) ) {
V_56 -> V_162 ( V_2 , V_2 -> V_5 . V_159 ) ;
V_2 -> V_5 . V_163 = ( V_150 & V_164 ) ;
}
break;
}
return 0 ;
}
int F_76 ( struct V_1 * V_2 , int V_149 , unsigned long V_150 )
{
int V_165 ;
V_165 = F_75 ( V_2 , V_149 , V_150 ) ;
if ( V_165 > 0 )
F_24 ( V_2 , V_166 ) ;
else if ( V_165 < 0 )
F_27 ( V_2 , 0 ) ;
return V_165 ;
}
static int F_77 ( struct V_1 * V_2 , int V_149 , unsigned long * V_150 )
{
switch ( V_149 ) {
case 0 ... 3 :
* V_150 = V_2 -> V_5 . V_151 [ V_149 ] ;
break;
case 4 :
if ( F_63 ( V_2 , V_155 ) )
return 1 ;
case 6 :
* V_150 = V_2 -> V_5 . V_156 ;
break;
case 5 :
if ( F_63 ( V_2 , V_155 ) )
return 1 ;
default:
* V_150 = V_2 -> V_5 . V_159 ;
break;
}
return 0 ;
}
int F_78 ( struct V_1 * V_2 , int V_149 , unsigned long * V_150 )
{
if ( F_77 ( V_2 , V_149 , V_150 ) ) {
F_24 ( V_2 , V_166 ) ;
return 1 ;
}
return 0 ;
}
static int F_79 ( struct V_1 * V_2 , T_2 V_109 )
{
T_2 V_167 = V_2 -> V_5 . V_109 ;
if ( V_109 & V_168 )
return 1 ;
if ( F_52 ( V_2 )
&& ( V_2 -> V_5 . V_109 & V_110 ) != ( V_109 & V_110 ) )
return 1 ;
if ( V_109 & V_169 ) {
struct V_125 * V_170 ;
V_170 = F_60 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_170 || ! ( V_170 -> V_171 & F_61 ( V_172 ) ) )
return 1 ;
}
if ( V_109 & V_173 ) {
struct V_125 * V_170 ;
V_170 = F_60 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_170 || ! ( V_170 -> V_127 & F_61 ( V_174 ) ) )
return 1 ;
}
V_109 &= ~ V_175 ;
V_109 |= V_2 -> V_5 . V_109 & V_175 ;
V_56 -> F_79 ( V_2 , V_109 ) ;
V_2 -> V_5 . V_67 . V_176 . V_177 = ( V_109 & V_178 ) && ! V_179 ;
if ( ( V_109 ^ V_167 ) & V_178 )
F_54 ( V_2 ) ;
return 0 ;
}
void F_80 ( T_2 V_26 )
{
V_168 &= ~ V_26 ;
}
int F_81 ( struct V_1 * V_2 , T_1 V_180 , T_2 V_31 )
{
return V_56 -> V_181 ( V_2 , V_180 , V_31 ) ;
}
static int F_82 ( struct V_1 * V_2 , unsigned V_116 , T_2 * V_31 )
{
return F_81 ( V_2 , V_116 , * V_31 ) ;
}
static void F_83 ( struct V_29 * V_29 , T_4 V_182 )
{
int V_183 ;
int V_98 ;
struct V_184 V_185 ;
struct V_186 V_187 ;
if ( ! V_182 )
return;
V_98 = F_84 ( V_29 , V_182 , & V_183 , sizeof( V_183 ) ) ;
if ( V_98 )
return;
if ( V_183 & 1 )
++ V_183 ;
++ V_183 ;
F_85 ( V_29 , V_182 , & V_183 , sizeof( V_183 ) ) ;
F_86 ( & V_187 ) ;
V_185 . V_188 = V_187 . V_189 ;
V_185 . V_190 = V_187 . V_191 ;
V_185 . V_183 = V_183 ;
F_85 ( V_29 , V_182 , & V_185 , sizeof( V_185 ) ) ;
V_183 ++ ;
F_85 ( V_29 , V_182 , & V_183 , sizeof( V_183 ) ) ;
}
static T_5 F_87 ( T_5 V_192 , T_5 V_193 )
{
T_5 V_194 , V_195 ;
__asm__ ( "divl %4"
: "=a" (quotient), "=d" (remainder)
: "0" (0), "1" (dividend), "r" (divisor) );
return V_194 ;
}
static void F_88 ( T_5 V_196 , T_5 V_197 ,
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
* V_199 = F_87 ( V_200 , V_203 ) ;
F_89 ( L_2 ,
V_204 , V_197 , V_196 , V_201 , * V_199 ) ;
}
static inline T_2 F_90 ( void )
{
struct V_186 V_205 ;
F_91 ( F_92 () ) ;
F_93 ( & V_205 ) ;
F_94 ( & V_205 ) ;
return F_95 ( & V_205 ) ;
}
static inline int F_96 ( void )
{
int V_206 = F_97 () ;
int V_87 = ! F_98 ( V_207 ) &&
F_99 ( V_206 ) != 0 ;
F_100 () ;
return V_87 ;
}
static T_2 F_101 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_208 )
return V_2 -> V_5 . V_208 ;
else
return F_102 ( V_209 ) ;
}
static inline T_2 F_103 ( struct V_1 * V_2 , T_2 V_190 )
{
T_2 V_87 ;
F_91 ( F_92 () ) ;
if ( F_96 () )
F_104 ( V_210
L_3 ) ;
V_87 = V_190 * F_101 ( V_2 ) ;
F_105 ( V_87 , V_211 ) ;
return V_87 ;
}
static void F_106 ( struct V_1 * V_2 , T_1 V_212 )
{
F_88 ( V_212 , V_213 / 1000 ,
& V_2 -> V_5 . V_214 ,
& V_2 -> V_5 . V_215 ) ;
}
static T_2 F_107 ( struct V_1 * V_2 , T_9 V_216 )
{
T_2 V_217 = F_108 ( V_216 - V_2 -> V_5 . V_218 ,
V_2 -> V_5 . V_215 ,
V_2 -> V_5 . V_214 ) ;
V_217 += V_2 -> V_5 . V_219 ;
return V_217 ;
}
void F_109 ( struct V_1 * V_2 , T_2 V_31 )
{
struct V_29 * V_29 = V_2 -> V_29 ;
T_2 V_73 , V_220 , V_221 ;
unsigned long V_222 ;
T_9 V_223 ;
F_110 ( & V_29 -> V_5 . V_224 , V_222 ) ;
V_73 = V_56 -> V_225 ( V_2 , V_31 ) ;
V_220 = F_90 () ;
V_221 = V_220 - V_29 -> V_5 . V_218 ;
V_223 = V_31 - V_29 -> V_5 . V_219 ;
if ( V_223 < 0 )
V_223 = - V_223 ;
if ( V_223 < F_103 ( V_2 , 5ULL * V_213 ) &&
V_221 < 5ULL * V_213 ) {
if ( ! F_111 () ) {
V_73 = V_29 -> V_5 . V_226 ;
F_89 ( L_4 , V_31 ) ;
} else {
T_2 V_227 = F_103 ( V_2 , V_221 ) ;
V_73 += V_227 ;
F_89 ( L_5 , V_227 ) ;
}
V_220 = V_29 -> V_5 . V_218 ;
}
V_29 -> V_5 . V_218 = V_220 ;
V_29 -> V_5 . V_219 = V_31 ;
V_29 -> V_5 . V_226 = V_73 ;
V_56 -> V_228 ( V_2 , V_73 ) ;
F_112 ( & V_29 -> V_5 . V_224 , V_222 ) ;
V_2 -> V_5 . V_229 . V_230 = 0 ;
V_2 -> V_5 . V_219 = V_31 ;
V_2 -> V_5 . V_218 = V_220 ;
}
static int F_113 ( struct V_1 * V_231 )
{
unsigned long V_222 ;
struct V_232 * V_2 = & V_231 -> V_5 ;
void * V_233 ;
unsigned long V_212 ;
T_9 V_216 , V_234 ;
T_2 V_230 ;
F_114 ( V_222 ) ;
F_115 ( V_231 , V_235 , & V_230 ) ;
V_216 = F_90 () ;
V_212 = F_101 ( V_231 ) ;
if ( F_69 ( V_212 == 0 ) ) {
F_116 ( V_222 ) ;
F_23 ( V_236 , V_231 ) ;
return 1 ;
}
if ( V_2 -> V_237 ) {
T_2 V_217 = F_107 ( V_231 , V_216 ) ;
if ( V_217 > V_230 ) {
V_56 -> V_238 ( V_231 , V_217 - V_230 ) ;
V_230 = V_217 ;
}
}
F_116 ( V_222 ) ;
if ( ! V_2 -> V_239 )
return 0 ;
V_234 = 0 ;
if ( V_2 -> V_229 . V_230 && V_2 -> V_240 ) {
V_234 = V_2 -> V_240 -
V_2 -> V_229 . V_230 ;
V_234 = F_108 ( V_234 ,
V_2 -> V_229 . V_241 ,
V_2 -> V_229 . V_242 ) ;
V_234 += V_2 -> V_243 ;
}
if ( F_69 ( V_2 -> V_244 != V_212 ) ) {
F_88 ( V_213 / 1000 , V_212 ,
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
V_233 = F_117 ( V_2 -> V_239 , V_247 ) ;
memcpy ( V_233 + V_2 -> V_248 , & V_2 -> V_229 ,
sizeof( V_2 -> V_229 ) ) ;
F_118 ( V_233 , V_247 ) ;
F_119 ( V_231 -> V_29 , V_2 -> time >> V_85 ) ;
return 0 ;
}
static bool F_120 ( unsigned V_21 )
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
static bool F_121 ( unsigned V_263 )
{
return V_263 < 8 && ( 1 << V_263 ) & 0xf3 ;
}
static bool F_122 ( unsigned V_263 )
{
return V_263 < 8 && ( 1 << V_263 ) & 0x73 ;
}
static bool F_123 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
int V_3 ;
if ( ! F_120 ( V_21 ) )
return false ;
if ( V_21 == V_262 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_121 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
} else if ( V_21 == V_261 ) {
if ( V_31 & ~ 0xcff )
return false ;
return F_122 ( V_31 & 0xff ) ;
} else if ( V_21 >= V_250 && V_21 <= V_260 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_122 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
}
return F_122 ( V_31 & 0xff ) ;
}
static int F_124 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
T_2 * V_264 = ( T_2 * ) & V_2 -> V_5 . V_265 . V_266 ;
if ( ! F_123 ( V_2 , V_21 , V_31 ) )
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
F_54 ( V_2 ) ;
return 0 ;
}
static int F_125 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
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
T_1 V_73 = V_21 - V_283 ;
if ( ( V_73 & 0x3 ) == 0 &&
V_31 != 0 && ( V_31 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_284 [ V_73 ] = V_31 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_126 ( struct V_1 * V_2 , T_2 V_31 )
{
struct V_29 * V_29 = V_2 -> V_29 ;
int V_285 = F_45 ( V_2 ) ;
T_10 * V_286 = V_285 ? ( T_10 * ) ( long ) V_29 -> V_5 . F_126 . V_287
: ( T_10 * ) ( long ) V_29 -> V_5 . F_126 . V_288 ;
T_10 V_289 = V_285 ? V_29 -> V_5 . F_126 . V_290
: V_29 -> V_5 . F_126 . V_291 ;
T_1 V_292 = V_31 & ~ V_293 ;
T_2 V_294 = V_31 & V_293 ;
T_10 * V_295 ;
int V_98 ;
V_98 = - V_296 ;
if ( V_292 >= V_289 )
goto V_92;
V_98 = - V_297 ;
V_295 = F_127 ( V_86 , V_298 ) ;
if ( ! V_295 )
goto V_92;
V_98 = - V_80 ;
if ( F_128 ( V_295 , V_286 + ( V_292 * V_86 ) , V_86 ) )
goto V_299;
if ( F_85 ( V_29 , V_294 , V_295 , V_86 ) )
goto V_299;
V_98 = 0 ;
V_299:
F_129 ( V_295 ) ;
V_92:
return V_98 ;
}
static bool F_130 ( struct V_29 * V_29 )
{
return V_29 -> V_5 . V_300 & V_301 ;
}
static bool F_131 ( T_1 V_21 )
{
bool V_98 = false ;
switch ( V_21 ) {
case V_302 :
case V_303 :
V_98 = true ;
break;
}
return V_98 ;
}
static int F_132 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
struct V_29 * V_29 = V_2 -> V_29 ;
switch ( V_21 ) {
case V_302 :
V_29 -> V_5 . V_304 = V_31 ;
if ( ! V_29 -> V_5 . V_304 )
V_29 -> V_5 . V_300 &= ~ V_301 ;
break;
case V_303 : {
T_2 V_81 ;
unsigned long V_305 ;
T_10 V_306 [ 4 ] ;
if ( ! V_29 -> V_5 . V_304 )
break;
if ( ! ( V_31 & V_301 ) ) {
V_29 -> V_5 . V_300 = V_31 ;
break;
}
V_81 = V_31 >> V_307 ;
V_305 = F_133 ( V_29 , V_81 ) ;
if ( F_134 ( V_305 ) )
return 1 ;
V_56 -> V_308 ( V_2 , V_306 ) ;
( ( unsigned char * ) V_306 ) [ 3 ] = 0xc3 ;
if ( F_135 ( ( void V_309 * ) V_305 , V_306 , 4 ) )
return 1 ;
V_29 -> V_5 . V_300 = V_31 ;
break;
}
default:
F_136 ( V_2 , L_6
L_7 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_137 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
switch ( V_21 ) {
case V_310 : {
unsigned long V_305 ;
if ( ! ( V_31 & V_311 ) ) {
V_2 -> V_5 . V_312 = V_31 ;
break;
}
V_305 = F_133 ( V_2 -> V_29 , V_31 >>
V_313 ) ;
if ( F_134 ( V_305 ) )
return 1 ;
if ( F_138 ( ( void V_309 * ) V_305 , V_86 ) )
return 1 ;
V_2 -> V_5 . V_312 = V_31 ;
break;
}
case V_314 :
return F_139 ( V_2 , V_315 , V_31 ) ;
case V_316 :
return F_139 ( V_2 , V_317 , V_31 ) ;
case V_318 :
return F_139 ( V_2 , V_319 , V_31 ) ;
default:
F_136 ( V_2 , L_6
L_7 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_140 ( struct V_1 * V_2 , T_2 V_31 )
{
T_4 V_320 = V_31 & ~ 0x3f ;
if ( V_31 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_321 = V_31 ;
if ( ! ( V_31 & V_322 ) ) {
F_53 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_141 ( V_2 -> V_29 , & V_2 -> V_5 . V_6 . V_31 , V_320 ) )
return 1 ;
V_2 -> V_5 . V_6 . V_323 = ! ( V_31 & V_324 ) ;
F_142 ( V_2 ) ;
return 0 ;
}
static void F_143 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_239 ) {
F_144 ( V_2 -> V_5 . V_239 ) ;
V_2 -> V_5 . V_239 = NULL ;
}
}
int F_145 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
switch ( V_21 ) {
case V_325 :
return F_79 ( V_2 , V_31 ) ;
case V_326 :
V_31 &= ~ ( T_2 ) 0x40 ;
V_31 &= ~ ( T_2 ) 0x100 ;
if ( V_31 != 0 ) {
F_136 ( V_2 , L_8 ,
V_31 ) ;
return 1 ;
}
break;
case V_327 :
if ( V_31 != 0 ) {
F_136 ( V_2 , L_9
L_10 , V_31 ) ;
return 1 ;
}
break;
case V_328 :
break;
case V_329 :
if ( ! V_31 ) {
break;
} else if ( V_31 & ~ ( V_330 | V_331 ) ) {
return 1 ;
}
F_136 ( V_2 , L_11 ,
V_204 , V_31 ) ;
break;
case V_332 :
case V_333 :
case V_334 :
case V_335 :
break;
case 0x200 ... 0x2ff :
return F_124 ( V_2 , V_21 , V_31 ) ;
case V_336 :
F_19 ( V_2 , V_31 ) ;
break;
case V_337 ... V_337 + 0x3ff :
return F_146 ( V_2 , V_21 , V_31 ) ;
case V_338 :
V_2 -> V_5 . V_339 = V_31 ;
break;
case V_340 :
case V_341 :
V_2 -> V_29 -> V_5 . V_182 = V_31 ;
F_83 ( V_2 -> V_29 , V_31 ) ;
break;
case V_342 :
case V_343 : {
F_143 ( V_2 ) ;
V_2 -> V_5 . time = V_31 ;
F_23 ( V_236 , V_2 ) ;
if ( ! ( V_31 & 1 ) )
break;
V_2 -> V_5 . V_248 = V_31 & ~ ( V_293 | 1 ) ;
V_2 -> V_5 . V_239 =
F_147 ( V_2 -> V_29 , V_31 >> V_85 ) ;
if ( F_148 ( V_2 -> V_5 . V_239 ) ) {
F_149 ( V_2 -> V_5 . V_239 ) ;
V_2 -> V_5 . V_239 = NULL ;
}
break;
}
case V_344 :
if ( F_140 ( V_2 , V_31 ) )
return 1 ;
break;
case V_280 :
case V_278 :
case V_283 ... V_283 + 4 * V_345 - 1 :
return F_125 ( V_2 , V_21 , V_31 ) ;
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
if ( V_31 != 0 )
F_136 ( V_2 , L_12
L_13 , V_21 , V_31 ) ;
break;
case V_352 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
case V_357 :
F_136 ( V_2 , L_12
L_13 , V_21 , V_31 ) ;
break;
case V_358 :
break;
case V_302 ... V_359 :
if ( F_131 ( V_21 ) ) {
int V_98 ;
F_150 ( & V_2 -> V_29 -> V_360 ) ;
V_98 = F_132 ( V_2 , V_21 , V_31 ) ;
F_151 ( & V_2 -> V_29 -> V_360 ) ;
return V_98 ;
} else
return F_137 ( V_2 , V_21 , V_31 ) ;
break;
case V_361 :
F_136 ( V_2 , L_14 , V_21 , V_31 ) ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_29 -> V_5 . F_126 . V_21 ) )
return F_126 ( V_2 , V_31 ) ;
if ( ! V_362 ) {
F_136 ( V_2 , L_15 ,
V_21 , V_31 ) ;
return 1 ;
} else {
F_136 ( V_2 , L_14 ,
V_21 , V_31 ) ;
break;
}
}
return 0 ;
}
int F_115 ( struct V_1 * V_2 , T_1 V_180 , T_2 * V_363 )
{
return V_56 -> V_364 ( V_2 , V_180 , V_363 ) ;
}
static int F_152 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_363 )
{
T_2 * V_264 = ( T_2 * ) & V_2 -> V_5 . V_265 . V_266 ;
if ( ! F_120 ( V_21 ) )
return 1 ;
if ( V_21 == V_261 )
* V_363 = V_2 -> V_5 . V_265 . V_267 +
( V_2 -> V_5 . V_265 . V_268 << 10 ) ;
else if ( V_21 == V_250 )
* V_363 = V_264 [ 0 ] ;
else if ( V_21 == V_251 || V_21 == V_252 )
* V_363 = V_264 [ 1 + V_21 - V_251 ] ;
else if ( V_21 >= V_253 && V_21 <= V_260 )
* V_363 = V_264 [ 3 + V_21 - V_253 ] ;
else if ( V_21 == V_262 )
* V_363 = V_2 -> V_5 . V_269 ;
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
* V_363 = * V_272 ;
}
return 0 ;
}
static int F_153 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_363 )
{
T_2 V_31 ;
T_2 V_276 = V_2 -> V_5 . V_276 ;
unsigned V_277 = V_276 & 0xff ;
switch ( V_21 ) {
case V_365 :
case V_366 :
V_31 = 0 ;
break;
case V_367 :
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
T_1 V_73 = V_21 - V_283 ;
V_31 = V_2 -> V_5 . V_284 [ V_73 ] ;
break;
}
return 1 ;
}
* V_363 = V_31 ;
return 0 ;
}
static int F_154 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_363 )
{
T_2 V_31 = 0 ;
struct V_29 * V_29 = V_2 -> V_29 ;
switch ( V_21 ) {
case V_302 :
V_31 = V_29 -> V_5 . V_304 ;
break;
case V_303 :
V_31 = V_29 -> V_5 . V_300 ;
break;
default:
F_136 ( V_2 , L_16 , V_21 ) ;
return 1 ;
}
* V_363 = V_31 ;
return 0 ;
}
static int F_155 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_363 )
{
T_2 V_31 = 0 ;
switch ( V_21 ) {
case V_368 : {
int V_98 ;
struct V_1 * V_231 ;
F_156 (r, v, vcpu->kvm)
if ( V_231 == V_2 )
V_31 = V_98 ;
break;
}
case V_314 :
return F_157 ( V_2 , V_315 , V_363 ) ;
case V_316 :
return F_157 ( V_2 , V_317 , V_363 ) ;
case V_318 :
return F_157 ( V_2 , V_319 , V_363 ) ;
default:
F_136 ( V_2 , L_16 , V_21 ) ;
return 1 ;
}
* V_363 = V_31 ;
return 0 ;
}
int F_158 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_363 )
{
T_2 V_31 ;
switch ( V_21 ) {
case V_369 :
case V_332 :
case V_370 :
case V_329 :
case V_371 :
case V_372 :
case V_373 :
case V_374 :
case V_375 :
case V_326 :
case V_334 :
case V_352 :
case V_353 :
case V_346 :
case V_347 :
case V_348 :
case V_354 :
case V_376 :
case V_328 :
case V_327 :
V_31 = 0 ;
break;
case V_377 :
V_31 = 0x500 | V_249 ;
break;
case 0x200 ... 0x2ff :
return F_152 ( V_2 , V_21 , V_363 ) ;
case 0xcd :
V_31 = 3 ;
break;
case V_378 :
V_31 = 1 << 24 ;
break;
case V_336 :
V_31 = F_17 ( V_2 ) ;
break;
case V_337 ... V_337 + 0x3ff :
return F_159 ( V_2 , V_21 , V_363 ) ;
break;
case V_338 :
V_31 = V_2 -> V_5 . V_339 ;
break;
case V_379 :
V_31 = 1000ULL ;
V_31 |= ( ( ( T_7 ) 4ULL ) << 40 ) ;
break;
case V_325 :
V_31 = V_2 -> V_5 . V_109 ;
break;
case V_341 :
case V_340 :
V_31 = V_2 -> V_29 -> V_5 . V_182 ;
break;
case V_343 :
case V_342 :
V_31 = V_2 -> V_5 . time ;
break;
case V_344 :
V_31 = V_2 -> V_5 . V_6 . V_321 ;
break;
case V_365 :
case V_366 :
case V_367 :
case V_280 :
case V_278 :
case V_283 ... V_283 + 4 * V_345 - 1 :
return F_153 ( V_2 , V_21 , V_363 ) ;
case V_358 :
V_31 = 0x20000000 ;
break;
case V_302 ... V_359 :
if ( F_131 ( V_21 ) ) {
int V_98 ;
F_150 ( & V_2 -> V_29 -> V_360 ) ;
V_98 = F_154 ( V_2 , V_21 , V_363 ) ;
F_151 ( & V_2 -> V_29 -> V_360 ) ;
return V_98 ;
} else
return F_155 ( V_2 , V_21 , V_363 ) ;
break;
case V_361 :
V_31 = 0xbe702111 ;
break;
default:
if ( ! V_362 ) {
F_136 ( V_2 , L_17 , V_21 ) ;
return 1 ;
} else {
F_136 ( V_2 , L_18 , V_21 ) ;
V_31 = 0 ;
}
break;
}
* V_363 = V_31 ;
return 0 ;
}
static int F_160 ( struct V_1 * V_2 , struct V_380 * V_19 ,
struct V_381 * V_382 ,
int (* F_161)( struct V_1 * V_2 ,
unsigned V_116 , T_2 * V_31 ) )
{
int V_3 , V_270 ;
V_270 = F_162 ( & V_2 -> V_29 -> V_383 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_384 ; ++ V_3 )
if ( F_161 ( V_2 , V_382 [ V_3 ] . V_116 , & V_382 [ V_3 ] . V_31 ) )
break;
F_163 ( & V_2 -> V_29 -> V_383 , V_270 ) ;
return V_3 ;
}
static int F_164 ( struct V_1 * V_2 , struct V_380 V_309 * V_385 ,
int (* F_161)( struct V_1 * V_2 ,
unsigned V_116 , T_2 * V_31 ) ,
int V_386 )
{
struct V_380 V_19 ;
struct V_381 * V_382 ;
int V_98 , V_387 ;
unsigned V_388 ;
V_98 = - V_80 ;
if ( F_128 ( & V_19 , V_385 , sizeof V_19 ) )
goto V_92;
V_98 = - V_296 ;
if ( V_19 . V_384 >= V_389 )
goto V_92;
V_98 = - V_297 ;
V_388 = sizeof( struct V_381 ) * V_19 . V_384 ;
V_382 = F_165 ( V_388 , V_298 ) ;
if ( ! V_382 )
goto V_92;
V_98 = - V_80 ;
if ( F_128 ( V_382 , V_385 -> V_382 , V_388 ) )
goto V_299;
V_98 = V_387 = F_160 ( V_2 , & V_19 , V_382 , F_161 ) ;
if ( V_98 < 0 )
goto V_299;
V_98 = - V_80 ;
if ( V_386 && F_135 ( V_385 -> V_382 , V_382 , V_388 ) )
goto V_299;
V_98 = V_387 ;
V_299:
F_129 ( V_382 ) ;
V_92:
return V_98 ;
}
int F_166 ( long V_390 )
{
int V_98 ;
switch ( V_390 ) {
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_397 :
case V_398 :
case V_399 :
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_405 :
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
V_98 = 1 ;
break;
case V_422 :
V_98 = V_423 ;
break;
case V_424 :
V_98 = ! V_56 -> V_425 () ;
break;
case V_426 :
V_98 = V_427 ;
break;
case V_428 :
V_98 = V_429 ;
break;
case V_430 :
V_98 = 0 ;
break;
case V_431 :
V_98 = F_167 () ;
break;
case V_432 :
V_98 = V_345 ;
break;
case V_433 :
V_98 = V_129 ;
break;
case V_434 :
V_98 = V_435 ;
break;
default:
V_98 = 0 ;
break;
}
return V_98 ;
}
long F_168 ( struct V_436 * V_437 ,
unsigned int V_438 , unsigned long V_439 )
{
void V_309 * V_440 = ( void V_309 * ) V_439 ;
long V_98 ;
switch ( V_438 ) {
case V_441 : {
struct V_442 V_309 * V_443 = V_440 ;
struct V_442 V_444 ;
unsigned V_387 ;
V_98 = - V_80 ;
if ( F_128 ( & V_444 , V_443 , sizeof V_444 ) )
goto V_92;
V_387 = V_444 . V_384 ;
V_444 . V_384 = V_445 + F_41 ( V_446 ) ;
if ( F_135 ( V_443 , & V_444 , sizeof V_444 ) )
goto V_92;
V_98 = - V_296 ;
if ( V_387 < V_444 . V_384 )
goto V_92;
V_98 = - V_80 ;
if ( F_135 ( V_443 -> V_447 , & V_448 ,
V_445 * sizeof( T_1 ) ) )
goto V_92;
if ( F_135 ( V_443 -> V_447 + V_445 ,
& V_446 ,
F_41 ( V_446 ) * sizeof( T_1 ) ) )
goto V_92;
V_98 = 0 ;
break;
}
case V_449 : {
struct V_450 V_309 * V_451 = V_440 ;
struct V_450 V_452 ;
V_98 = - V_80 ;
if ( F_128 ( & V_452 , V_451 , sizeof V_452 ) )
goto V_92;
V_98 = F_169 ( & V_452 ,
V_451 -> V_382 ) ;
if ( V_98 )
goto V_92;
V_98 = - V_80 ;
if ( F_135 ( V_451 , & V_452 , sizeof V_452 ) )
goto V_92;
V_98 = 0 ;
break;
}
case V_453 : {
T_2 V_454 ;
V_454 = V_455 ;
V_98 = - V_80 ;
if ( F_135 ( V_440 , & V_454 , sizeof V_454 ) )
goto V_92;
V_98 = 0 ;
break;
}
default:
V_98 = - V_456 ;
}
V_92:
return V_98 ;
}
static void F_170 ( void * V_457 )
{
F_171 () ;
}
static bool F_172 ( struct V_1 * V_2 )
{
return V_2 -> V_29 -> V_5 . V_458 &&
! ( V_2 -> V_29 -> V_5 . V_459 & V_460 ) ;
}
void F_173 ( struct V_1 * V_2 , int V_206 )
{
if ( F_172 ( V_2 ) ) {
if ( V_56 -> V_461 () )
F_174 ( V_206 , V_2 -> V_5 . V_462 ) ;
else if ( V_2 -> V_206 != - 1 && V_2 -> V_206 != V_206 )
F_175 ( V_2 -> V_206 ,
F_170 , NULL , 1 ) ;
}
V_56 -> V_463 ( V_2 , V_206 ) ;
if ( F_69 ( V_2 -> V_206 != V_206 ) || F_111 () ) {
T_9 V_464 ;
T_2 V_217 ;
F_115 ( V_2 , V_235 , & V_217 ) ;
V_464 = ! V_2 -> V_5 . V_240 ? 0 :
V_217 - V_2 -> V_5 . V_240 ;
if ( V_464 < 0 )
F_176 ( L_19 ) ;
if ( F_111 () ) {
V_56 -> V_238 ( V_2 , - V_464 ) ;
V_2 -> V_5 . V_237 = 1 ;
}
F_23 ( V_236 , V_2 ) ;
if ( V_2 -> V_206 != V_206 )
F_177 ( V_2 ) ;
V_2 -> V_206 = V_206 ;
}
}
void F_178 ( struct V_1 * V_2 )
{
V_56 -> V_465 ( V_2 ) ;
F_179 ( V_2 ) ;
F_115 ( V_2 , V_235 , & V_2 -> V_5 . V_240 ) ;
}
static int F_180 ( void )
{
unsigned long long V_109 = 0 ;
F_10 ( V_325 , & V_109 ) ;
return V_109 & V_178 ;
}
static void F_181 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_125 * V_466 , * V_467 ;
V_467 = NULL ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 . V_468 ; ++ V_3 ) {
V_466 = & V_2 -> V_5 . V_469 [ V_3 ] ;
if ( V_466 -> V_130 == 0x80000001 ) {
V_467 = V_466 ;
break;
}
}
if ( V_467 && ( V_467 -> V_171 & ( 1 << 20 ) ) && ! F_180 () ) {
V_467 -> V_171 &= ~ ( 1 << 20 ) ;
F_9 ( V_470 L_20 ) ;
}
}
static int F_182 ( struct V_1 * V_2 ,
struct V_471 * V_452 ,
struct V_472 V_309 * V_382 )
{
int V_98 , V_3 ;
struct V_472 * V_469 ;
V_98 = - V_296 ;
if ( V_452 -> V_473 > V_474 )
goto V_92;
V_98 = - V_297 ;
V_469 = F_183 ( sizeof( struct V_472 ) * V_452 -> V_473 ) ;
if ( ! V_469 )
goto V_92;
V_98 = - V_80 ;
if ( F_128 ( V_469 , V_382 ,
V_452 -> V_473 * sizeof( struct V_472 ) ) )
goto V_299;
for ( V_3 = 0 ; V_3 < V_452 -> V_473 ; V_3 ++ ) {
V_2 -> V_5 . V_469 [ V_3 ] . V_130 = V_469 [ V_3 ] . V_130 ;
V_2 -> V_5 . V_469 [ V_3 ] . V_475 = V_469 [ V_3 ] . V_475 ;
V_2 -> V_5 . V_469 [ V_3 ] . V_476 = V_469 [ V_3 ] . V_476 ;
V_2 -> V_5 . V_469 [ V_3 ] . V_127 = V_469 [ V_3 ] . V_127 ;
V_2 -> V_5 . V_469 [ V_3 ] . V_171 = V_469 [ V_3 ] . V_171 ;
V_2 -> V_5 . V_469 [ V_3 ] . V_116 = 0 ;
V_2 -> V_5 . V_469 [ V_3 ] . V_222 = 0 ;
V_2 -> V_5 . V_469 [ V_3 ] . V_477 [ 0 ] = 0 ;
V_2 -> V_5 . V_469 [ V_3 ] . V_477 [ 1 ] = 0 ;
V_2 -> V_5 . V_469 [ V_3 ] . V_477 [ 2 ] = 0 ;
}
V_2 -> V_5 . V_468 = V_452 -> V_473 ;
F_181 ( V_2 ) ;
V_98 = 0 ;
F_184 ( V_2 ) ;
V_56 -> V_478 ( V_2 ) ;
F_62 ( V_2 ) ;
V_299:
F_185 ( V_469 ) ;
V_92:
return V_98 ;
}
static int F_186 ( struct V_1 * V_2 ,
struct V_450 * V_452 ,
struct V_125 V_309 * V_382 )
{
int V_98 ;
V_98 = - V_296 ;
if ( V_452 -> V_473 > V_474 )
goto V_92;
V_98 = - V_80 ;
if ( F_128 ( & V_2 -> V_5 . V_469 , V_382 ,
V_452 -> V_473 * sizeof( struct V_125 ) ) )
goto V_92;
V_2 -> V_5 . V_468 = V_452 -> V_473 ;
F_184 ( V_2 ) ;
V_56 -> V_478 ( V_2 ) ;
F_62 ( V_2 ) ;
return 0 ;
V_92:
return V_98 ;
}
static int F_187 ( struct V_1 * V_2 ,
struct V_450 * V_452 ,
struct V_125 V_309 * V_382 )
{
int V_98 ;
V_98 = - V_296 ;
if ( V_452 -> V_473 < V_2 -> V_5 . V_468 )
goto V_92;
V_98 = - V_80 ;
if ( F_135 ( V_382 , & V_2 -> V_5 . V_469 ,
V_2 -> V_5 . V_468 * sizeof( struct V_125 ) ) )
goto V_92;
return 0 ;
V_92:
V_452 -> V_473 = V_2 -> V_5 . V_468 ;
return V_98 ;
}
static void F_188 ( T_1 * V_479 , int V_480 )
{
* V_479 &= V_481 . V_482 [ V_480 ] ;
}
static void F_189 ( struct V_125 * V_467 , T_1 V_130 ,
T_1 V_116 )
{
V_467 -> V_130 = V_130 ;
V_467 -> V_116 = V_116 ;
F_190 ( V_467 -> V_130 , V_467 -> V_116 ,
& V_467 -> V_475 , & V_467 -> V_476 , & V_467 -> V_127 , & V_467 -> V_171 ) ;
V_467 -> V_222 = 0 ;
}
static void F_191 ( struct V_125 * V_467 , T_1 V_130 ,
T_1 V_116 , int * V_473 , int V_483 )
{
unsigned V_484 = F_180 () ? F_192 ( V_485 ) : 0 ;
#ifdef F_51
unsigned V_486 = ( V_56 -> V_487 () == V_488 )
? F_192 ( V_489 ) : 0 ;
unsigned V_490 = F_192 ( V_491 ) ;
#else
unsigned V_486 = 0 ;
unsigned V_490 = 0 ;
#endif
unsigned V_492 = V_56 -> V_493 () ? F_192 ( V_494 ) : 0 ;
const T_1 V_495 =
F_192 ( V_496 ) | F_192 ( V_497 ) | F_192 ( V_498 ) | F_192 ( V_499 ) |
F_192 ( V_500 ) | F_192 ( V_501 ) | F_192 ( V_502 ) | F_192 ( V_503 ) |
F_192 ( V_504 ) | F_192 ( V_505 ) | 0 | F_192 ( V_506 ) |
F_192 ( V_507 ) | F_192 ( V_508 ) | F_192 ( V_509 ) | F_192 ( V_510 ) |
F_192 ( V_511 ) | F_192 ( V_512 ) | 0 | F_192 ( V_513 ) |
0 | F_192 ( V_514 ) |
F_192 ( V_515 ) | F_192 ( V_516 ) | F_192 ( V_517 ) | F_192 ( V_518 ) |
0 ;
const T_1 V_519 =
F_192 ( V_496 ) | F_192 ( V_497 ) | F_192 ( V_498 ) | F_192 ( V_499 ) |
F_192 ( V_500 ) | F_192 ( V_501 ) | F_192 ( V_502 ) | F_192 ( V_503 ) |
F_192 ( V_504 ) | F_192 ( V_505 ) | 0 | F_192 ( V_520 ) |
F_192 ( V_507 ) | F_192 ( V_508 ) | F_192 ( V_509 ) | F_192 ( V_510 ) |
F_192 ( V_511 ) | F_192 ( V_512 ) | 0 |
V_484 | 0 | F_192 ( V_521 ) | F_192 ( V_514 ) |
F_192 ( V_515 ) | F_192 ( V_522 ) | V_486 | V_492 |
0 | V_490 | F_192 ( 3DNOWEXT ) | F_192 ( 3DNOW ) ;
const T_1 V_523 =
F_192 ( V_524 ) | F_192 ( V_525 ) | 0 |
0 |
0 | F_192 ( V_526 ) | 0 | 0 |
0 | F_192 ( V_527 ) | 0 |
0 | F_192 ( V_528 ) |
F_192 ( V_529 ) | F_192 ( V_530 ) | F_192 ( V_531 ) | F_192 ( V_532 ) |
0 | F_192 ( V_533 ) | F_192 ( V_534 ) | 0 | F_192 ( V_535 ) |
F_192 ( V_536 ) ;
const T_1 V_537 =
F_192 ( V_538 ) | F_192 ( V_539 ) | 0 | 0 |
F_192 ( V_540 ) | F_192 ( V_541 ) | F_192 ( V_542 ) | F_192 ( V_543 ) |
F_192 ( 3DNOWPREFETCH ) | 0 | 0 | F_192 ( V_544 ) |
0 | F_192 ( V_545 ) | F_192 ( V_546 ) ;
const T_1 V_547 =
F_192 ( V_548 ) | F_192 ( V_549 ) | F_192 ( V_550 ) | F_192 ( V_551 ) |
F_192 ( V_552 ) | F_192 ( V_553 ) | F_192 ( V_554 ) | F_192 ( V_555 ) |
F_192 ( V_556 ) | F_192 ( V_557 ) ;
F_97 () ;
F_189 ( V_467 , V_130 , V_116 ) ;
++ * V_473 ;
switch ( V_130 ) {
case 0 :
V_467 -> V_475 = F_193 ( V_467 -> V_475 , ( T_1 ) 0xd ) ;
break;
case 1 :
V_467 -> V_171 &= V_495 ;
F_188 ( & V_467 -> V_171 , 0 ) ;
V_467 -> V_127 &= V_523 ;
F_188 ( & V_467 -> V_127 , 4 ) ;
V_467 -> V_127 |= F_192 ( V_530 ) ;
break;
case 2 : {
int V_263 , V_558 = V_467 -> V_475 & 0xff ;
V_467 -> V_222 |= V_559 ;
V_467 -> V_222 |= V_560 ;
for ( V_263 = 1 ; V_263 < V_558 && * V_473 < V_483 ; ++ V_263 ) {
F_189 ( & V_467 [ V_263 ] , V_130 , 0 ) ;
V_467 [ V_263 ] . V_222 |= V_559 ;
++ * V_473 ;
}
break;
}
case 4 : {
int V_3 , V_561 ;
V_467 -> V_222 |= V_562 ;
for ( V_3 = 1 ; * V_473 < V_483 ; ++ V_3 ) {
V_561 = V_467 [ V_3 - 1 ] . V_475 & 0x1f ;
if ( ! V_561 )
break;
F_189 ( & V_467 [ V_3 ] , V_130 , V_3 ) ;
V_467 [ V_3 ] . V_222 |=
V_562 ;
++ * V_473 ;
}
break;
}
case 0xb : {
int V_3 , V_563 ;
V_467 -> V_222 |= V_562 ;
for ( V_3 = 1 ; * V_473 < V_483 ; ++ V_3 ) {
V_563 = V_467 [ V_3 - 1 ] . V_127 & 0xff00 ;
if ( ! V_563 )
break;
F_189 ( & V_467 [ V_3 ] , V_130 , V_3 ) ;
V_467 [ V_3 ] . V_222 |=
V_562 ;
++ * V_473 ;
}
break;
}
case 0xd : {
int V_3 ;
V_467 -> V_222 |= V_562 ;
for ( V_3 = 1 ; * V_473 < V_483 && V_3 < 64 ; ++ V_3 ) {
if ( V_467 [ V_3 ] . V_475 == 0 )
continue;
F_189 ( & V_467 [ V_3 ] , V_130 , V_3 ) ;
V_467 [ V_3 ] . V_222 |=
V_562 ;
++ * V_473 ;
}
break;
}
case V_564 : {
char V_565 [ 12 ] = L_21 ;
T_1 * V_566 = ( T_1 * ) V_565 ;
V_467 -> V_475 = 0 ;
V_467 -> V_476 = V_566 [ 0 ] ;
V_467 -> V_127 = V_566 [ 1 ] ;
V_467 -> V_171 = V_566 [ 2 ] ;
break;
}
case V_567 :
V_467 -> V_475 = ( 1 << V_568 ) |
( 1 << V_569 ) |
( 1 << V_570 ) |
( 1 << V_571 ) |
( 1 << V_572 ) ;
V_467 -> V_476 = 0 ;
V_467 -> V_127 = 0 ;
V_467 -> V_171 = 0 ;
break;
case 0x80000000 :
V_467 -> V_475 = F_193 ( V_467 -> V_475 , 0x8000001a ) ;
break;
case 0x80000001 :
V_467 -> V_171 &= V_519 ;
F_188 ( & V_467 -> V_171 , 1 ) ;
V_467 -> V_127 &= V_537 ;
F_188 ( & V_467 -> V_127 , 6 ) ;
break;
case 0xC0000000 :
V_467 -> V_475 = F_193 ( V_467 -> V_475 , 0xC0000004 ) ;
break;
case 0xC0000001 :
V_467 -> V_171 &= V_547 ;
F_188 ( & V_467 -> V_171 , 5 ) ;
break;
case 0xC0000002 :
case 0xC0000003 :
case 0xC0000004 :
break;
}
V_56 -> V_573 ( V_130 , V_467 ) ;
F_100 () ;
}
static int F_169 ( struct V_450 * V_452 ,
struct V_125 V_309 * V_382 )
{
struct V_125 * V_469 ;
int V_574 , V_473 = 0 , V_98 = - V_296 ;
T_1 V_575 ;
if ( V_452 -> V_473 < 1 )
goto V_92;
if ( V_452 -> V_473 > V_474 )
V_452 -> V_473 = V_474 ;
V_98 = - V_297 ;
V_469 = F_183 ( sizeof( struct V_125 ) * V_452 -> V_473 ) ;
if ( ! V_469 )
goto V_92;
F_191 ( & V_469 [ 0 ] , 0 , 0 , & V_473 , V_452 -> V_473 ) ;
V_574 = V_469 [ 0 ] . V_475 ;
for ( V_575 = 1 ; V_575 <= V_574 && V_473 < V_452 -> V_473 ; ++ V_575 )
F_191 ( & V_469 [ V_473 ] , V_575 , 0 ,
& V_473 , V_452 -> V_473 ) ;
V_98 = - V_296 ;
if ( V_473 >= V_452 -> V_473 )
goto V_299;
F_191 ( & V_469 [ V_473 ] , 0x80000000 , 0 , & V_473 , V_452 -> V_473 ) ;
V_574 = V_469 [ V_473 - 1 ] . V_475 ;
for ( V_575 = 0x80000001 ; V_575 <= V_574 && V_473 < V_452 -> V_473 ; ++ V_575 )
F_191 ( & V_469 [ V_473 ] , V_575 , 0 ,
& V_473 , V_452 -> V_473 ) ;
V_98 = - V_296 ;
if ( V_473 >= V_452 -> V_473 )
goto V_299;
if ( V_481 . V_576 == V_577 ) {
F_191 ( & V_469 [ V_473 ] , 0xC0000000 , 0 ,
& V_473 , V_452 -> V_473 ) ;
V_98 = - V_296 ;
if ( V_473 >= V_452 -> V_473 )
goto V_299;
V_574 = V_469 [ V_473 - 1 ] . V_475 ;
for ( V_575 = 0xC0000001 ;
V_575 <= V_574 && V_473 < V_452 -> V_473 ; ++ V_575 )
F_191 ( & V_469 [ V_473 ] , V_575 , 0 ,
& V_473 , V_452 -> V_473 ) ;
V_98 = - V_296 ;
if ( V_473 >= V_452 -> V_473 )
goto V_299;
}
F_191 ( & V_469 [ V_473 ] , V_564 , 0 , & V_473 ,
V_452 -> V_473 ) ;
V_98 = - V_296 ;
if ( V_473 >= V_452 -> V_473 )
goto V_299;
F_191 ( & V_469 [ V_473 ] , V_567 , 0 , & V_473 ,
V_452 -> V_473 ) ;
V_98 = - V_296 ;
if ( V_473 >= V_452 -> V_473 )
goto V_299;
V_98 = - V_80 ;
if ( F_135 ( V_382 , V_469 ,
V_473 * sizeof( struct V_125 ) ) )
goto V_299;
V_452 -> V_473 = V_473 ;
V_98 = 0 ;
V_299:
F_185 ( V_469 ) ;
V_92:
return V_98 ;
}
static int F_194 ( struct V_1 * V_2 ,
struct V_578 * V_579 )
{
memcpy ( V_579 -> V_580 , V_2 -> V_5 . V_581 -> V_580 , sizeof *V_579 ) ;
return 0 ;
}
static int F_195 ( struct V_1 * V_2 ,
struct V_578 * V_579 )
{
memcpy ( V_2 -> V_5 . V_581 -> V_580 , V_579 -> V_580 , sizeof *V_579 ) ;
F_196 ( V_2 ) ;
F_197 ( V_2 ) ;
return 0 ;
}
static int F_198 ( struct V_1 * V_2 ,
struct V_582 * V_583 )
{
if ( V_583 -> V_583 < 0 || V_583 -> V_583 >= 256 )
return - V_456 ;
if ( F_18 ( V_2 -> V_29 ) )
return - V_584 ;
F_199 ( V_2 , V_583 -> V_583 , false ) ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
static int F_200 ( struct V_1 * V_2 )
{
F_32 ( V_2 ) ;
return 0 ;
}
static int F_201 ( struct V_1 * V_2 ,
struct V_585 * V_586 )
{
if ( V_586 -> V_222 )
return - V_456 ;
V_2 -> V_5 . V_587 = ! ! V_586 -> V_268 ;
return 0 ;
}
static int F_202 ( struct V_1 * V_2 ,
T_2 V_276 )
{
int V_98 ;
unsigned V_277 = V_276 & 0xff , V_588 ;
V_98 = - V_456 ;
if ( ! V_277 || V_277 >= V_345 )
goto V_92;
if ( V_276 & ~ ( V_455 | 0xff | 0xff0000 ) )
goto V_92;
V_98 = 0 ;
V_2 -> V_5 . V_276 = V_276 ;
if ( V_276 & V_281 )
V_2 -> V_5 . V_282 = ~ ( T_2 ) 0 ;
for ( V_588 = 0 ; V_588 < V_277 ; V_588 ++ )
V_2 -> V_5 . V_284 [ V_588 * 4 ] = ~ ( T_2 ) 0 ;
V_92:
return V_98 ;
}
static int F_203 ( struct V_1 * V_2 ,
struct V_589 * V_590 )
{
T_2 V_276 = V_2 -> V_5 . V_276 ;
unsigned V_277 = V_276 & 0xff ;
T_2 * V_591 = V_2 -> V_5 . V_284 ;
if ( V_590 -> V_588 >= V_277 || ! ( V_590 -> V_592 & V_593 ) )
return - V_456 ;
if ( ( V_590 -> V_592 & V_594 ) && ( V_276 & V_281 ) &&
V_2 -> V_5 . V_282 != ~ ( T_2 ) 0 )
return 0 ;
V_591 += 4 * V_590 -> V_588 ;
if ( ( V_590 -> V_592 & V_594 ) && V_591 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_590 -> V_592 & V_594 ) {
if ( ( V_2 -> V_5 . V_279 & V_595 ) ||
! F_63 ( V_2 , V_596 ) ) {
F_23 ( V_54 , V_2 ) ;
return 0 ;
}
if ( V_591 [ 1 ] & V_593 )
V_590 -> V_592 |= V_597 ;
V_591 [ 2 ] = V_590 -> V_305 ;
V_591 [ 3 ] = V_590 -> V_598 ;
V_2 -> V_5 . V_279 = V_590 -> V_279 ;
V_591 [ 1 ] = V_590 -> V_592 ;
F_24 ( V_2 , V_599 ) ;
} else if ( ! ( V_591 [ 1 ] & V_593 )
|| ! ( V_591 [ 1 ] & V_594 ) ) {
if ( V_591 [ 1 ] & V_593 )
V_590 -> V_592 |= V_597 ;
V_591 [ 2 ] = V_590 -> V_305 ;
V_591 [ 3 ] = V_590 -> V_598 ;
V_591 [ 1 ] = V_590 -> V_592 ;
} else
V_591 [ 1 ] |= V_597 ;
return 0 ;
}
static void F_204 ( struct V_1 * V_2 ,
struct V_600 * V_601 )
{
V_601 -> V_49 . V_602 =
V_2 -> V_5 . V_49 . V_50 &&
! F_205 ( V_2 -> V_5 . V_49 . V_16 ) ;
V_601 -> V_49 . V_16 = V_2 -> V_5 . V_49 . V_16 ;
V_601 -> V_49 . V_52 = V_2 -> V_5 . V_49 . V_52 ;
V_601 -> V_49 . V_603 = 0 ;
V_601 -> V_49 . V_43 = V_2 -> V_5 . V_49 . V_43 ;
V_601 -> V_604 . V_602 =
V_2 -> V_5 . V_604 . V_50 && ! V_2 -> V_5 . V_604 . V_605 ;
V_601 -> V_604 . V_16 = V_2 -> V_5 . V_604 . V_16 ;
V_601 -> V_604 . V_605 = 0 ;
V_601 -> V_604 . V_606 =
V_56 -> V_607 ( V_2 ,
V_608 | V_609 ) ;
V_601 -> V_610 . V_602 = V_2 -> V_5 . V_611 ;
V_601 -> V_610 . V_50 = V_2 -> V_5 . V_68 ;
V_601 -> V_610 . V_612 = V_56 -> V_613 ( V_2 ) ;
V_601 -> V_610 . V_603 = 0 ;
V_601 -> V_614 = V_2 -> V_5 . V_614 ;
V_601 -> V_222 = ( V_615
| V_616
| V_617 ) ;
memset ( & V_601 -> V_618 , 0 , sizeof( V_601 -> V_618 ) ) ;
}
static int F_206 ( struct V_1 * V_2 ,
struct V_600 * V_601 )
{
if ( V_601 -> V_222 & ~ ( V_615
| V_616
| V_617 ) )
return - V_456 ;
V_2 -> V_5 . V_49 . V_50 = V_601 -> V_49 . V_602 ;
V_2 -> V_5 . V_49 . V_16 = V_601 -> V_49 . V_16 ;
V_2 -> V_5 . V_49 . V_52 = V_601 -> V_49 . V_52 ;
V_2 -> V_5 . V_49 . V_43 = V_601 -> V_49 . V_43 ;
V_2 -> V_5 . V_604 . V_50 = V_601 -> V_604 . V_602 ;
V_2 -> V_5 . V_604 . V_16 = V_601 -> V_604 . V_16 ;
V_2 -> V_5 . V_604 . V_605 = V_601 -> V_604 . V_605 ;
if ( V_601 -> V_222 & V_617 )
V_56 -> V_619 ( V_2 ,
V_601 -> V_604 . V_606 ) ;
V_2 -> V_5 . V_611 = V_601 -> V_610 . V_602 ;
if ( V_601 -> V_222 & V_615 )
V_2 -> V_5 . V_68 = V_601 -> V_610 . V_50 ;
V_56 -> V_620 ( V_2 , V_601 -> V_610 . V_612 ) ;
if ( V_601 -> V_222 & V_616 )
V_2 -> V_5 . V_614 = V_601 -> V_614 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
static void F_207 ( struct V_1 * V_2 ,
struct V_621 * V_622 )
{
memcpy ( V_622 -> V_151 , V_2 -> V_5 . V_151 , sizeof( V_2 -> V_5 . V_151 ) ) ;
V_622 -> V_156 = V_2 -> V_5 . V_156 ;
V_622 -> V_159 = V_2 -> V_5 . V_159 ;
V_622 -> V_222 = 0 ;
memset ( & V_622 -> V_618 , 0 , sizeof( V_622 -> V_618 ) ) ;
}
static int F_208 ( struct V_1 * V_2 ,
struct V_621 * V_622 )
{
if ( V_622 -> V_222 )
return - V_456 ;
memcpy ( V_2 -> V_5 . V_151 , V_622 -> V_151 , sizeof( V_2 -> V_5 . V_151 ) ) ;
V_2 -> V_5 . V_156 = V_622 -> V_156 ;
V_2 -> V_5 . V_159 = V_622 -> V_159 ;
return 0 ;
}
static void F_209 ( struct V_1 * V_2 ,
struct V_623 * V_624 )
{
if ( V_129 )
memcpy ( V_624 -> V_625 ,
& V_2 -> V_5 . V_626 . V_627 -> V_628 ,
V_629 ) ;
else {
memcpy ( V_624 -> V_625 ,
& V_2 -> V_5 . V_626 . V_627 -> V_630 ,
sizeof( struct V_631 ) ) ;
* ( T_2 * ) & V_624 -> V_625 [ V_632 / sizeof( T_1 ) ] =
V_633 ;
}
}
static int F_210 ( struct V_1 * V_2 ,
struct V_623 * V_624 )
{
T_2 V_634 =
* ( T_2 * ) & V_624 -> V_625 [ V_632 / sizeof( T_1 ) ] ;
if ( V_129 )
memcpy ( & V_2 -> V_5 . V_626 . V_627 -> V_628 ,
V_624 -> V_625 , V_629 ) ;
else {
if ( V_634 & ~ V_633 )
return - V_456 ;
memcpy ( & V_2 -> V_5 . V_626 . V_627 -> V_630 ,
V_624 -> V_625 , sizeof( struct V_631 ) ) ;
}
return 0 ;
}
static void F_211 ( struct V_1 * V_2 ,
struct V_635 * V_636 )
{
if ( ! V_129 ) {
V_636 -> V_637 = 0 ;
return;
}
V_636 -> V_637 = 1 ;
V_636 -> V_222 = 0 ;
V_636 -> V_638 [ 0 ] . V_117 = V_119 ;
V_636 -> V_638 [ 0 ] . V_23 = V_2 -> V_5 . V_118 ;
}
static int F_212 ( struct V_1 * V_2 ,
struct V_635 * V_636 )
{
int V_3 , V_98 = 0 ;
if ( ! V_129 )
return - V_456 ;
if ( V_636 -> V_637 > V_639 || V_636 -> V_222 )
return - V_456 ;
for ( V_3 = 0 ; V_3 < V_636 -> V_637 ; V_3 ++ )
if ( V_636 -> V_638 [ 0 ] . V_117 == V_119 ) {
V_98 = F_57 ( V_2 , V_119 ,
V_636 -> V_638 [ 0 ] . V_23 ) ;
break;
}
if ( V_98 )
V_98 = - V_456 ;
return V_98 ;
}
long F_213 ( struct V_436 * V_437 ,
unsigned int V_438 , unsigned long V_439 )
{
struct V_1 * V_2 = V_437 -> V_640 ;
void V_309 * V_440 = ( void V_309 * ) V_439 ;
int V_98 ;
union {
struct V_578 * V_641 ;
struct V_623 * V_628 ;
struct V_635 * V_638 ;
void * V_642 ;
} V_643 ;
V_643 . V_642 = NULL ;
switch ( V_438 ) {
case V_644 : {
V_98 = - V_456 ;
if ( ! V_2 -> V_5 . V_581 )
goto V_92;
V_643 . V_641 = F_127 ( sizeof( struct V_578 ) , V_298 ) ;
V_98 = - V_297 ;
if ( ! V_643 . V_641 )
goto V_92;
V_98 = F_194 ( V_2 , V_643 . V_641 ) ;
if ( V_98 )
goto V_92;
V_98 = - V_80 ;
if ( F_135 ( V_440 , V_643 . V_641 , sizeof( struct V_578 ) ) )
goto V_92;
V_98 = 0 ;
break;
}
case V_645 : {
V_98 = - V_456 ;
if ( ! V_2 -> V_5 . V_581 )
goto V_92;
V_643 . V_641 = F_165 ( sizeof( struct V_578 ) , V_298 ) ;
V_98 = - V_297 ;
if ( ! V_643 . V_641 )
goto V_92;
V_98 = - V_80 ;
if ( F_128 ( V_643 . V_641 , V_440 , sizeof( struct V_578 ) ) )
goto V_92;
V_98 = F_195 ( V_2 , V_643 . V_641 ) ;
if ( V_98 )
goto V_92;
V_98 = 0 ;
break;
}
case V_646 : {
struct V_582 V_583 ;
V_98 = - V_80 ;
if ( F_128 ( & V_583 , V_440 , sizeof V_583 ) )
goto V_92;
V_98 = F_198 ( V_2 , & V_583 ) ;
if ( V_98 )
goto V_92;
V_98 = 0 ;
break;
}
case V_647 : {
V_98 = F_200 ( V_2 ) ;
if ( V_98 )
goto V_92;
V_98 = 0 ;
break;
}
case V_648 : {
struct V_471 V_309 * V_451 = V_440 ;
struct V_471 V_452 ;
V_98 = - V_80 ;
if ( F_128 ( & V_452 , V_451 , sizeof V_452 ) )
goto V_92;
V_98 = F_182 ( V_2 , & V_452 , V_451 -> V_382 ) ;
if ( V_98 )
goto V_92;
break;
}
case V_649 : {
struct V_450 V_309 * V_451 = V_440 ;
struct V_450 V_452 ;
V_98 = - V_80 ;
if ( F_128 ( & V_452 , V_451 , sizeof V_452 ) )
goto V_92;
V_98 = F_186 ( V_2 , & V_452 ,
V_451 -> V_382 ) ;
if ( V_98 )
goto V_92;
break;
}
case V_650 : {
struct V_450 V_309 * V_451 = V_440 ;
struct V_450 V_452 ;
V_98 = - V_80 ;
if ( F_128 ( & V_452 , V_451 , sizeof V_452 ) )
goto V_92;
V_98 = F_187 ( V_2 , & V_452 ,
V_451 -> V_382 ) ;
if ( V_98 )
goto V_92;
V_98 = - V_80 ;
if ( F_135 ( V_451 , & V_452 , sizeof V_452 ) )
goto V_92;
V_98 = 0 ;
break;
}
case V_651 :
V_98 = F_164 ( V_2 , V_440 , F_115 , 1 ) ;
break;
case V_652 :
V_98 = F_164 ( V_2 , V_440 , F_82 , 0 ) ;
break;
case V_653 : {
struct V_585 V_586 ;
V_98 = - V_80 ;
if ( F_128 ( & V_586 , V_440 , sizeof V_586 ) )
goto V_92;
V_98 = F_201 ( V_2 , & V_586 ) ;
if ( V_98 )
goto V_92;
V_98 = - V_80 ;
if ( F_135 ( V_440 , & V_586 , sizeof V_586 ) )
goto V_92;
V_98 = 0 ;
break;
} ;
case V_654 : {
struct V_655 V_656 ;
V_98 = - V_456 ;
if ( ! F_18 ( V_2 -> V_29 ) )
goto V_92;
V_98 = - V_80 ;
if ( F_128 ( & V_656 , V_440 , sizeof V_656 ) )
goto V_92;
V_98 = 0 ;
F_214 ( V_2 , V_656 . V_657 ) ;
break;
}
case V_658 : {
T_2 V_276 ;
V_98 = - V_80 ;
if ( F_128 ( & V_276 , V_440 , sizeof V_276 ) )
goto V_92;
V_98 = F_202 ( V_2 , V_276 ) ;
break;
}
case V_659 : {
struct V_589 V_590 ;
V_98 = - V_80 ;
if ( F_128 ( & V_590 , V_440 , sizeof V_590 ) )
goto V_92;
V_98 = F_203 ( V_2 , & V_590 ) ;
break;
}
case V_660 : {
struct V_600 V_601 ;
F_204 ( V_2 , & V_601 ) ;
V_98 = - V_80 ;
if ( F_135 ( V_440 , & V_601 , sizeof( struct V_600 ) ) )
break;
V_98 = 0 ;
break;
}
case V_661 : {
struct V_600 V_601 ;
V_98 = - V_80 ;
if ( F_128 ( & V_601 , V_440 , sizeof( struct V_600 ) ) )
break;
V_98 = F_206 ( V_2 , & V_601 ) ;
break;
}
case V_662 : {
struct V_621 V_622 ;
F_207 ( V_2 , & V_622 ) ;
V_98 = - V_80 ;
if ( F_135 ( V_440 , & V_622 ,
sizeof( struct V_621 ) ) )
break;
V_98 = 0 ;
break;
}
case V_663 : {
struct V_621 V_622 ;
V_98 = - V_80 ;
if ( F_128 ( & V_622 , V_440 ,
sizeof( struct V_621 ) ) )
break;
V_98 = F_208 ( V_2 , & V_622 ) ;
break;
}
case V_664 : {
V_643 . V_628 = F_127 ( sizeof( struct V_623 ) , V_298 ) ;
V_98 = - V_297 ;
if ( ! V_643 . V_628 )
break;
F_209 ( V_2 , V_643 . V_628 ) ;
V_98 = - V_80 ;
if ( F_135 ( V_440 , V_643 . V_628 , sizeof( struct V_623 ) ) )
break;
V_98 = 0 ;
break;
}
case V_665 : {
V_643 . V_628 = F_127 ( sizeof( struct V_623 ) , V_298 ) ;
V_98 = - V_297 ;
if ( ! V_643 . V_628 )
break;
V_98 = - V_80 ;
if ( F_128 ( V_643 . V_628 , V_440 , sizeof( struct V_623 ) ) )
break;
V_98 = F_210 ( V_2 , V_643 . V_628 ) ;
break;
}
case V_666 : {
V_643 . V_638 = F_127 ( sizeof( struct V_635 ) , V_298 ) ;
V_98 = - V_297 ;
if ( ! V_643 . V_638 )
break;
F_211 ( V_2 , V_643 . V_638 ) ;
V_98 = - V_80 ;
if ( F_135 ( V_440 , V_643 . V_638 ,
sizeof( struct V_635 ) ) )
break;
V_98 = 0 ;
break;
}
case V_667 : {
V_643 . V_638 = F_127 ( sizeof( struct V_635 ) , V_298 ) ;
V_98 = - V_297 ;
if ( ! V_643 . V_638 )
break;
V_98 = - V_80 ;
if ( F_128 ( V_643 . V_638 , V_440 ,
sizeof( struct V_635 ) ) )
break;
V_98 = F_212 ( V_2 , V_643 . V_638 ) ;
break;
}
case V_668 : {
T_1 V_669 ;
V_98 = - V_456 ;
if ( ! V_435 )
break;
V_669 = ( T_1 ) V_439 ;
if ( V_669 >= V_670 )
goto V_92;
V_56 -> V_671 ( V_2 , V_669 ) ;
V_98 = 0 ;
goto V_92;
}
case V_672 : {
V_98 = - V_673 ;
if ( F_111 () )
goto V_92;
V_98 = F_101 ( V_2 ) ;
goto V_92;
}
default:
V_98 = - V_456 ;
}
V_92:
F_129 ( V_643 . V_642 ) ;
return V_98 ;
}
static int F_215 ( struct V_29 * V_29 , unsigned long V_305 )
{
int V_87 ;
if ( V_305 > ( unsigned int ) ( - 3 * V_86 ) )
return - 1 ;
V_87 = V_56 -> V_674 ( V_29 , V_305 ) ;
return V_87 ;
}
static int F_216 ( struct V_29 * V_29 ,
T_2 V_675 )
{
V_29 -> V_5 . V_676 = V_675 ;
return 0 ;
}
static int F_217 ( struct V_29 * V_29 ,
T_1 V_677 )
{
if ( V_677 < V_678 )
return - V_456 ;
F_150 ( & V_29 -> V_679 ) ;
F_218 ( & V_29 -> V_680 ) ;
F_219 ( V_29 , V_677 ) ;
V_29 -> V_5 . V_681 = V_677 ;
F_220 ( & V_29 -> V_680 ) ;
F_151 ( & V_29 -> V_679 ) ;
return 0 ;
}
static int F_221 ( struct V_29 * V_29 )
{
return V_29 -> V_5 . V_682 ;
}
static int F_222 ( struct V_29 * V_29 , struct V_683 * V_684 )
{
int V_98 ;
V_98 = 0 ;
switch ( V_684 -> V_685 ) {
case V_686 :
memcpy ( & V_684 -> V_684 . V_687 ,
& F_223 ( V_29 ) -> V_688 [ 0 ] ,
sizeof( struct V_689 ) ) ;
break;
case V_690 :
memcpy ( & V_684 -> V_684 . V_687 ,
& F_223 ( V_29 ) -> V_688 [ 1 ] ,
sizeof( struct V_689 ) ) ;
break;
case V_691 :
V_98 = F_224 ( V_29 , & V_684 -> V_684 . V_692 ) ;
break;
default:
V_98 = - V_456 ;
break;
}
return V_98 ;
}
static int F_225 ( struct V_29 * V_29 , struct V_683 * V_684 )
{
int V_98 ;
V_98 = 0 ;
switch ( V_684 -> V_685 ) {
case V_686 :
F_218 ( & F_223 ( V_29 ) -> V_360 ) ;
memcpy ( & F_223 ( V_29 ) -> V_688 [ 0 ] ,
& V_684 -> V_684 . V_687 ,
sizeof( struct V_689 ) ) ;
F_220 ( & F_223 ( V_29 ) -> V_360 ) ;
break;
case V_690 :
F_218 ( & F_223 ( V_29 ) -> V_360 ) ;
memcpy ( & F_223 ( V_29 ) -> V_688 [ 1 ] ,
& V_684 -> V_684 . V_687 ,
sizeof( struct V_689 ) ) ;
F_220 ( & F_223 ( V_29 ) -> V_360 ) ;
break;
case V_691 :
V_98 = F_226 ( V_29 , & V_684 -> V_684 . V_692 ) ;
break;
default:
V_98 = - V_456 ;
break;
}
F_227 ( F_223 ( V_29 ) ) ;
return V_98 ;
}
static int F_228 ( struct V_29 * V_29 , struct V_693 * V_694 )
{
int V_98 = 0 ;
F_150 ( & V_29 -> V_5 . V_695 -> V_696 . V_360 ) ;
memcpy ( V_694 , & V_29 -> V_5 . V_695 -> V_696 , sizeof( struct V_693 ) ) ;
F_151 ( & V_29 -> V_5 . V_695 -> V_696 . V_360 ) ;
return V_98 ;
}
static int F_229 ( struct V_29 * V_29 , struct V_693 * V_694 )
{
int V_98 = 0 ;
F_150 ( & V_29 -> V_5 . V_695 -> V_696 . V_360 ) ;
memcpy ( & V_29 -> V_5 . V_695 -> V_696 , V_694 , sizeof( struct V_693 ) ) ;
F_230 ( V_29 , 0 , V_694 -> V_697 [ 0 ] . V_698 , 0 ) ;
F_151 ( & V_29 -> V_5 . V_695 -> V_696 . V_360 ) ;
return V_98 ;
}
static int F_231 ( struct V_29 * V_29 , struct V_699 * V_694 )
{
int V_98 = 0 ;
F_150 ( & V_29 -> V_5 . V_695 -> V_696 . V_360 ) ;
memcpy ( V_694 -> V_697 , & V_29 -> V_5 . V_695 -> V_696 . V_697 ,
sizeof( V_694 -> V_697 ) ) ;
V_694 -> V_222 = V_29 -> V_5 . V_695 -> V_696 . V_222 ;
F_151 ( & V_29 -> V_5 . V_695 -> V_696 . V_360 ) ;
memset ( & V_694 -> V_618 , 0 , sizeof( V_694 -> V_618 ) ) ;
return V_98 ;
}
static int F_232 ( struct V_29 * V_29 , struct V_699 * V_694 )
{
int V_98 = 0 , V_700 = 0 ;
T_1 V_701 , V_702 ;
F_150 ( & V_29 -> V_5 . V_695 -> V_696 . V_360 ) ;
V_701 = V_29 -> V_5 . V_695 -> V_696 . V_222 & V_703 ;
V_702 = V_694 -> V_222 & V_703 ;
if ( ! V_701 && V_702 )
V_700 = 1 ;
memcpy ( & V_29 -> V_5 . V_695 -> V_696 . V_697 , & V_694 -> V_697 ,
sizeof( V_29 -> V_5 . V_695 -> V_696 . V_697 ) ) ;
V_29 -> V_5 . V_695 -> V_696 . V_222 = V_694 -> V_222 ;
F_230 ( V_29 , 0 , V_29 -> V_5 . V_695 -> V_696 . V_697 [ 0 ] . V_698 , V_700 ) ;
F_151 ( & V_29 -> V_5 . V_695 -> V_696 . V_360 ) ;
return V_98 ;
}
static int F_233 ( struct V_29 * V_29 ,
struct V_704 * V_705 )
{
if ( ! V_29 -> V_5 . V_695 )
return - V_584 ;
F_150 ( & V_29 -> V_5 . V_695 -> V_696 . V_360 ) ;
V_29 -> V_5 . V_695 -> V_696 . V_706 . V_44 = V_705 -> V_707 ;
F_151 ( & V_29 -> V_5 . V_695 -> V_696 . V_360 ) ;
return 0 ;
}
int F_234 ( struct V_29 * V_29 ,
struct V_708 * log )
{
int V_98 , V_3 ;
struct V_709 * V_710 ;
unsigned long V_387 ;
unsigned long V_711 = 0 ;
F_150 ( & V_29 -> V_679 ) ;
V_98 = - V_456 ;
if ( log -> V_10 >= V_429 )
goto V_92;
V_710 = & V_29 -> V_712 -> V_712 [ log -> V_10 ] ;
V_98 = - V_713 ;
if ( ! V_710 -> V_714 )
goto V_92;
V_387 = F_235 ( V_710 ) ;
for ( V_3 = 0 ; ! V_711 && V_3 < V_387 / sizeof( long ) ; V_3 ++ )
V_711 = V_710 -> V_714 [ V_3 ] ;
if ( V_711 ) {
struct V_715 * V_716 , * V_717 ;
unsigned long * V_714 ;
V_714 = V_710 -> V_718 ;
if ( V_710 -> V_714 == V_714 )
V_714 += V_387 / sizeof( long ) ;
memset ( V_714 , 0 , V_387 ) ;
V_98 = - V_297 ;
V_716 = F_127 ( sizeof( struct V_715 ) , V_298 ) ;
if ( ! V_716 )
goto V_92;
memcpy ( V_716 , V_29 -> V_712 , sizeof( struct V_715 ) ) ;
V_716 -> V_712 [ log -> V_10 ] . V_714 = V_714 ;
V_716 -> V_719 ++ ;
V_717 = V_29 -> V_712 ;
F_236 ( V_29 -> V_712 , V_716 ) ;
F_237 ( & V_29 -> V_383 ) ;
V_714 = V_717 -> V_712 [ log -> V_10 ] . V_714 ;
F_129 ( V_717 ) ;
F_218 ( & V_29 -> V_680 ) ;
F_238 ( V_29 , log -> V_10 ) ;
F_220 ( & V_29 -> V_680 ) ;
V_98 = - V_80 ;
if ( F_135 ( log -> V_714 , V_714 , V_387 ) )
goto V_92;
} else {
V_98 = - V_80 ;
if ( F_138 ( log -> V_714 , V_387 ) )
goto V_92;
}
V_98 = 0 ;
V_92:
F_151 ( & V_29 -> V_679 ) ;
return V_98 ;
}
long F_239 ( struct V_436 * V_437 ,
unsigned int V_438 , unsigned long V_439 )
{
struct V_29 * V_29 = V_437 -> V_640 ;
void V_309 * V_440 = ( void V_309 * ) V_439 ;
int V_98 = - V_720 ;
union {
struct V_693 V_694 ;
struct V_699 V_721 ;
struct V_722 V_723 ;
} V_643 ;
switch ( V_438 ) {
case V_724 :
V_98 = F_215 ( V_29 , V_439 ) ;
if ( V_98 < 0 )
goto V_92;
break;
case V_725 : {
T_2 V_675 ;
V_98 = - V_80 ;
if ( F_128 ( & V_675 , V_440 , sizeof V_675 ) )
goto V_92;
V_98 = F_216 ( V_29 , V_675 ) ;
if ( V_98 < 0 )
goto V_92;
break;
}
case V_726 :
V_98 = F_217 ( V_29 , V_439 ) ;
if ( V_98 )
goto V_92;
break;
case V_727 :
V_98 = F_221 ( V_29 ) ;
break;
case V_728 : {
struct V_729 * V_730 ;
F_150 ( & V_29 -> V_360 ) ;
V_98 = - V_731 ;
if ( V_29 -> V_5 . V_730 )
goto V_732;
V_98 = - V_297 ;
V_730 = F_240 ( V_29 ) ;
if ( V_730 ) {
V_98 = F_241 ( V_29 ) ;
if ( V_98 ) {
F_150 ( & V_29 -> V_679 ) ;
F_242 ( V_29 , V_733 ,
& V_730 -> V_734 ) ;
F_151 ( & V_29 -> V_679 ) ;
F_129 ( V_730 ) ;
goto V_732;
}
} else
goto V_732;
F_12 () ;
V_29 -> V_5 . V_730 = V_730 ;
F_12 () ;
V_98 = F_243 ( V_29 ) ;
if ( V_98 ) {
F_150 ( & V_29 -> V_679 ) ;
F_150 ( & V_29 -> V_735 ) ;
F_244 ( V_29 ) ;
F_245 ( V_29 ) ;
F_151 ( & V_29 -> V_735 ) ;
F_151 ( & V_29 -> V_679 ) ;
}
V_732:
F_151 ( & V_29 -> V_360 ) ;
break;
}
case V_736 :
V_643 . V_723 . V_222 = V_737 ;
goto V_738;
case V_739 :
V_98 = - V_80 ;
if ( F_128 ( & V_643 . V_723 , V_440 ,
sizeof( struct V_722 ) ) )
goto V_92;
V_738:
F_150 ( & V_29 -> V_679 ) ;
V_98 = - V_731 ;
if ( V_29 -> V_5 . V_695 )
goto V_740;
V_98 = - V_297 ;
V_29 -> V_5 . V_695 = F_246 ( V_29 , V_643 . V_723 . V_222 ) ;
if ( V_29 -> V_5 . V_695 )
V_98 = 0 ;
V_740:
F_151 ( & V_29 -> V_679 ) ;
break;
case V_741 :
case V_742 : {
struct V_743 V_744 ;
V_98 = - V_80 ;
if ( F_128 ( & V_744 , V_440 , sizeof V_744 ) )
goto V_92;
V_98 = - V_584 ;
if ( F_18 ( V_29 ) ) {
T_11 V_592 ;
V_592 = F_247 ( V_29 , V_745 ,
V_744 . V_583 , V_744 . V_746 ) ;
if ( V_438 == V_741 ) {
V_98 = - V_80 ;
V_744 . V_592 = V_592 ;
if ( F_135 ( V_440 , & V_744 ,
sizeof V_744 ) )
goto V_92;
}
V_98 = 0 ;
}
break;
}
case V_747 : {
struct V_683 * V_684 = F_165 ( sizeof( * V_684 ) , V_298 ) ;
V_98 = - V_297 ;
if ( ! V_684 )
goto V_92;
V_98 = - V_80 ;
if ( F_128 ( V_684 , V_440 , sizeof *V_684 ) )
goto V_748;
V_98 = - V_584 ;
if ( ! F_18 ( V_29 ) )
goto V_748;
V_98 = F_222 ( V_29 , V_684 ) ;
if ( V_98 )
goto V_748;
V_98 = - V_80 ;
if ( F_135 ( V_440 , V_684 , sizeof *V_684 ) )
goto V_748;
V_98 = 0 ;
V_748:
F_129 ( V_684 ) ;
if ( V_98 )
goto V_92;
break;
}
case V_749 : {
struct V_683 * V_684 = F_165 ( sizeof( * V_684 ) , V_298 ) ;
V_98 = - V_297 ;
if ( ! V_684 )
goto V_92;
V_98 = - V_80 ;
if ( F_128 ( V_684 , V_440 , sizeof *V_684 ) )
goto V_750;
V_98 = - V_584 ;
if ( ! F_18 ( V_29 ) )
goto V_750;
V_98 = F_225 ( V_29 , V_684 ) ;
if ( V_98 )
goto V_750;
V_98 = 0 ;
V_750:
F_129 ( V_684 ) ;
if ( V_98 )
goto V_92;
break;
}
case V_751 : {
V_98 = - V_80 ;
if ( F_128 ( & V_643 . V_694 , V_440 , sizeof( struct V_693 ) ) )
goto V_92;
V_98 = - V_584 ;
if ( ! V_29 -> V_5 . V_695 )
goto V_92;
V_98 = F_228 ( V_29 , & V_643 . V_694 ) ;
if ( V_98 )
goto V_92;
V_98 = - V_80 ;
if ( F_135 ( V_440 , & V_643 . V_694 , sizeof( struct V_693 ) ) )
goto V_92;
V_98 = 0 ;
break;
}
case V_752 : {
V_98 = - V_80 ;
if ( F_128 ( & V_643 . V_694 , V_440 , sizeof V_643 . V_694 ) )
goto V_92;
V_98 = - V_584 ;
if ( ! V_29 -> V_5 . V_695 )
goto V_92;
V_98 = F_229 ( V_29 , & V_643 . V_694 ) ;
if ( V_98 )
goto V_92;
V_98 = 0 ;
break;
}
case V_753 : {
V_98 = - V_584 ;
if ( ! V_29 -> V_5 . V_695 )
goto V_92;
V_98 = F_231 ( V_29 , & V_643 . V_721 ) ;
if ( V_98 )
goto V_92;
V_98 = - V_80 ;
if ( F_135 ( V_440 , & V_643 . V_721 , sizeof( V_643 . V_721 ) ) )
goto V_92;
V_98 = 0 ;
break;
}
case V_754 : {
V_98 = - V_80 ;
if ( F_128 ( & V_643 . V_721 , V_440 , sizeof( V_643 . V_721 ) ) )
goto V_92;
V_98 = - V_584 ;
if ( ! V_29 -> V_5 . V_695 )
goto V_92;
V_98 = F_232 ( V_29 , & V_643 . V_721 ) ;
if ( V_98 )
goto V_92;
V_98 = 0 ;
break;
}
case V_755 : {
struct V_704 V_705 ;
V_98 = - V_80 ;
if ( F_128 ( & V_705 , V_440 , sizeof( V_705 ) ) )
goto V_92;
V_98 = F_233 ( V_29 , & V_705 ) ;
if ( V_98 )
goto V_92;
V_98 = 0 ;
break;
}
case V_756 : {
V_98 = - V_80 ;
if ( F_128 ( & V_29 -> V_5 . F_126 , V_440 ,
sizeof( struct V_757 ) ) )
goto V_92;
V_98 = - V_456 ;
if ( V_29 -> V_5 . F_126 . V_222 )
goto V_92;
V_98 = 0 ;
break;
}
case V_758 : {
struct V_759 V_760 ;
T_2 V_761 ;
T_9 V_227 ;
V_98 = - V_80 ;
if ( F_128 ( & V_760 , V_440 , sizeof( V_760 ) ) )
goto V_92;
V_98 = - V_456 ;
if ( V_760 . V_222 )
goto V_92;
V_98 = 0 ;
F_248 () ;
V_761 = F_90 () ;
V_227 = V_760 . clock - V_761 ;
F_249 () ;
V_29 -> V_5 . V_246 = V_227 ;
break;
}
case V_762 : {
struct V_759 V_760 ;
T_2 V_761 ;
F_248 () ;
V_761 = F_90 () ;
V_760 . clock = V_29 -> V_5 . V_246 + V_761 ;
F_249 () ;
V_760 . V_222 = 0 ;
memset ( & V_760 . V_603 , 0 , sizeof( V_760 . V_603 ) ) ;
V_98 = - V_80 ;
if ( F_135 ( V_440 , & V_760 , sizeof( V_760 ) ) )
goto V_92;
V_98 = 0 ;
break;
}
default:
;
}
V_92:
return V_98 ;
}
static void F_250 ( void )
{
T_1 V_763 [ 2 ] ;
unsigned V_3 , V_764 ;
for ( V_3 = V_764 = V_765 ; V_3 < F_41 ( V_448 ) ; V_3 ++ ) {
if ( F_251 ( V_448 [ V_3 ] , & V_763 [ 0 ] , & V_763 [ 1 ] ) < 0 )
continue;
if ( V_764 < V_3 )
V_448 [ V_764 ] = V_448 [ V_3 ] ;
V_764 ++ ;
}
V_445 = V_764 ;
}
static int F_252 ( struct V_1 * V_2 , T_4 V_305 , int V_74 ,
const void * V_231 )
{
int V_766 = 0 ;
int V_387 ;
do {
V_387 = F_193 ( V_74 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_581 &&
! F_253 ( & V_2 -> V_5 . V_581 -> V_734 , V_305 , V_387 , V_231 ) )
&& F_254 ( V_2 -> V_29 , V_767 , V_305 , V_387 , V_231 ) )
break;
V_766 += V_387 ;
V_305 += V_387 ;
V_74 -= V_387 ;
V_231 += V_387 ;
} while ( V_74 );
return V_766 ;
}
static int F_255 ( struct V_1 * V_2 , T_4 V_305 , int V_74 , void * V_231 )
{
int V_766 = 0 ;
int V_387 ;
do {
V_387 = F_193 ( V_74 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_581 &&
! F_256 ( & V_2 -> V_5 . V_581 -> V_734 , V_305 , V_387 , V_231 ) )
&& F_257 ( V_2 -> V_29 , V_767 , V_305 , V_387 , V_231 ) )
break;
F_258 ( V_768 , V_387 , V_305 , * ( T_2 * ) V_231 ) ;
V_766 += V_387 ;
V_305 += V_387 ;
V_74 -= V_387 ;
V_231 += V_387 ;
} while ( V_74 );
return V_766 ;
}
static void F_259 ( struct V_1 * V_2 ,
struct V_769 * V_770 , int V_771 )
{
V_56 -> V_772 ( V_2 , V_770 , V_771 ) ;
}
void F_260 ( struct V_1 * V_2 ,
struct V_769 * V_770 , int V_771 )
{
V_56 -> V_773 ( V_2 , V_770 , V_771 ) ;
}
static T_4 V_78 ( struct V_1 * V_2 , T_4 V_320 , T_1 V_75 )
{
return V_320 ;
}
static T_4 F_261 ( struct V_1 * V_2 , T_4 V_320 , T_1 V_75 )
{
T_4 V_774 ;
struct V_58 V_49 ;
F_262 ( ! F_31 ( V_2 ) ) ;
V_75 |= V_90 ;
V_774 = V_2 -> V_5 . V_67 . V_775 ( V_2 , V_320 , V_75 , & V_49 ) ;
return V_774 ;
}
T_4 F_263 ( struct V_1 * V_2 , T_12 V_776 ,
struct V_58 * V_49 )
{
T_1 V_75 = ( V_56 -> V_70 ( V_2 ) == 3 ) ? V_90 : 0 ;
return V_2 -> V_5 . V_82 -> V_775 ( V_2 , V_776 , V_75 , V_49 ) ;
}
T_4 F_264 ( struct V_1 * V_2 , T_12 V_776 ,
struct V_58 * V_49 )
{
T_1 V_75 = ( V_56 -> V_70 ( V_2 ) == 3 ) ? V_90 : 0 ;
V_75 |= V_777 ;
return V_2 -> V_5 . V_82 -> V_775 ( V_2 , V_776 , V_75 , V_49 ) ;
}
T_4 F_265 ( struct V_1 * V_2 , T_12 V_776 ,
struct V_58 * V_49 )
{
T_1 V_75 = ( V_56 -> V_70 ( V_2 ) == 3 ) ? V_90 : 0 ;
V_75 |= V_91 ;
return V_2 -> V_5 . V_82 -> V_775 ( V_2 , V_776 , V_75 , V_49 ) ;
}
T_4 F_266 ( struct V_1 * V_2 , T_12 V_776 ,
struct V_58 * V_49 )
{
return V_2 -> V_5 . V_82 -> V_775 ( V_2 , V_776 , 0 , V_49 ) ;
}
static int F_267 ( T_12 V_305 , void * V_150 , unsigned int V_778 ,
struct V_1 * V_2 , T_1 V_75 ,
struct V_58 * V_49 )
{
void * V_31 = V_150 ;
int V_98 = V_779 ;
while ( V_778 ) {
T_4 V_320 = V_2 -> V_5 . V_82 -> V_775 ( V_2 , V_305 , V_75 ,
V_49 ) ;
unsigned V_73 = V_305 & ( V_86 - 1 ) ;
unsigned V_780 = F_193 ( V_778 , ( unsigned ) V_86 - V_73 ) ;
int V_87 ;
if ( V_320 == V_79 )
return V_781 ;
V_87 = F_84 ( V_2 -> V_29 , V_320 , V_31 , V_780 ) ;
if ( V_87 < 0 ) {
V_98 = V_782 ;
goto V_92;
}
V_778 -= V_780 ;
V_31 += V_780 ;
V_305 += V_780 ;
}
V_92:
return V_98 ;
}
static int F_268 ( struct V_783 * V_784 ,
T_12 V_305 , void * V_150 , unsigned int V_778 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_269 ( V_784 ) ;
T_1 V_75 = ( V_56 -> V_70 ( V_2 ) == 3 ) ? V_90 : 0 ;
return F_267 ( V_305 , V_150 , V_778 , V_2 ,
V_75 | V_777 ,
V_49 ) ;
}
static int F_270 ( struct V_783 * V_784 ,
T_12 V_305 , void * V_150 , unsigned int V_778 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_269 ( V_784 ) ;
T_1 V_75 = ( V_56 -> V_70 ( V_2 ) == 3 ) ? V_90 : 0 ;
return F_267 ( V_305 , V_150 , V_778 , V_2 , V_75 ,
V_49 ) ;
}
static int F_271 ( struct V_783 * V_784 ,
T_12 V_305 , void * V_150 , unsigned int V_778 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_269 ( V_784 ) ;
return F_267 ( V_305 , V_150 , V_778 , V_2 , 0 , V_49 ) ;
}
static int F_272 ( struct V_783 * V_784 ,
T_12 V_305 , void * V_150 ,
unsigned int V_778 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_269 ( V_784 ) ;
void * V_31 = V_150 ;
int V_98 = V_779 ;
while ( V_778 ) {
T_4 V_320 = V_2 -> V_5 . V_82 -> V_775 ( V_2 , V_305 ,
V_91 ,
V_49 ) ;
unsigned V_73 = V_305 & ( V_86 - 1 ) ;
unsigned V_785 = F_193 ( V_778 , ( unsigned ) V_86 - V_73 ) ;
int V_87 ;
if ( V_320 == V_79 )
return V_781 ;
V_87 = F_85 ( V_2 -> V_29 , V_320 , V_31 , V_785 ) ;
if ( V_87 < 0 ) {
V_98 = V_782 ;
goto V_92;
}
V_778 -= V_785 ;
V_31 += V_785 ;
V_305 += V_785 ;
}
V_92:
return V_98 ;
}
static int F_273 ( struct V_783 * V_784 ,
unsigned long V_305 ,
void * V_150 ,
unsigned int V_778 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_269 ( V_784 ) ;
T_4 V_320 ;
int V_766 ;
if ( V_2 -> V_786 ) {
memcpy ( V_150 , V_2 -> V_787 , V_778 ) ;
F_258 ( V_768 , V_778 ,
V_2 -> V_788 , * ( T_2 * ) V_150 ) ;
V_2 -> V_786 = 0 ;
return V_779 ;
}
V_320 = F_263 ( V_2 , V_305 , V_49 ) ;
if ( V_320 == V_79 )
return V_781 ;
if ( ( V_320 & V_293 ) == V_789 )
goto V_790;
if ( F_270 ( V_784 , V_305 , V_150 , V_778 , V_49 )
== V_779 )
return V_779 ;
V_790:
V_766 = F_255 ( V_2 , V_320 , V_778 , V_150 ) ;
if ( V_766 == V_778 )
return V_779 ;
V_320 += V_766 ;
V_778 -= V_766 ;
V_150 += V_766 ;
F_258 ( V_791 , V_778 , V_320 , 0 ) ;
V_2 -> V_792 = 1 ;
V_2 -> V_793 -> V_794 = V_795 ;
V_2 -> V_793 -> V_790 . V_796 = V_2 -> V_788 = V_320 ;
V_2 -> V_797 = V_778 ;
V_2 -> V_793 -> V_790 . V_74 = F_193 ( V_2 -> V_797 , 8 ) ;
V_2 -> V_793 -> V_790 . V_798 = V_2 -> V_799 = 0 ;
V_2 -> V_800 = 0 ;
return V_782 ;
}
int F_274 ( struct V_1 * V_2 , T_4 V_320 ,
const void * V_150 , int V_778 )
{
int V_87 ;
V_87 = F_85 ( V_2 -> V_29 , V_320 , V_150 , V_778 ) ;
if ( V_87 < 0 )
return 0 ;
F_275 ( V_2 , V_320 , V_150 , V_778 , 1 ) ;
return 1 ;
}
static int F_276 ( unsigned long V_305 ,
const void * V_150 ,
unsigned int V_778 ,
struct V_58 * V_49 ,
struct V_1 * V_2 )
{
T_4 V_320 ;
int V_766 ;
V_320 = F_265 ( V_2 , V_305 , V_49 ) ;
if ( V_320 == V_79 )
return V_781 ;
if ( ( V_320 & V_293 ) == V_789 )
goto V_790;
if ( F_274 ( V_2 , V_320 , V_150 , V_778 ) )
return V_779 ;
V_790:
F_258 ( V_801 , V_778 , V_320 , * ( T_2 * ) V_150 ) ;
V_766 = F_252 ( V_2 , V_320 , V_778 , V_150 ) ;
if ( V_766 == V_778 )
return V_779 ;
V_320 += V_766 ;
V_778 -= V_766 ;
V_150 += V_766 ;
V_2 -> V_792 = 1 ;
memcpy ( V_2 -> V_787 , V_150 , V_778 ) ;
V_2 -> V_793 -> V_794 = V_795 ;
V_2 -> V_793 -> V_790 . V_796 = V_2 -> V_788 = V_320 ;
V_2 -> V_797 = V_778 ;
V_2 -> V_793 -> V_790 . V_74 = F_193 ( V_2 -> V_797 , 8 ) ;
V_2 -> V_793 -> V_790 . V_798 = V_2 -> V_799 = 1 ;
memcpy ( V_2 -> V_793 -> V_790 . V_31 , V_2 -> V_787 , 8 ) ;
V_2 -> V_800 = 0 ;
return V_779 ;
}
int F_277 ( struct V_783 * V_784 ,
unsigned long V_305 ,
const void * V_150 ,
unsigned int V_778 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_269 ( V_784 ) ;
if ( ( ( V_305 + V_778 - 1 ) ^ V_305 ) & V_293 ) {
int V_802 , V_803 ;
V_803 = - V_305 & ~ V_293 ;
V_802 = F_276 ( V_305 , V_150 , V_803 , V_49 ,
V_2 ) ;
if ( V_802 != V_779 )
return V_802 ;
V_305 += V_803 ;
V_150 += V_803 ;
V_778 -= V_803 ;
}
return F_276 ( V_305 , V_150 , V_778 , V_49 ,
V_2 ) ;
}
static int F_278 ( struct V_783 * V_784 ,
unsigned long V_305 ,
const void * V_804 ,
const void * V_805 ,
unsigned int V_778 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_269 ( V_784 ) ;
T_4 V_320 ;
struct V_295 * V_295 ;
char * V_806 ;
bool V_807 ;
if ( V_778 > 8 || ( V_778 & ( V_778 - 1 ) ) )
goto V_808;
V_320 = F_265 ( V_2 , V_305 , NULL ) ;
if ( V_320 == V_79 ||
( V_320 & V_293 ) == V_789 )
goto V_808;
if ( ( ( V_320 + V_778 - 1 ) & V_293 ) != ( V_320 & V_293 ) )
goto V_808;
V_295 = F_147 ( V_2 -> V_29 , V_320 >> V_85 ) ;
if ( F_148 ( V_295 ) ) {
F_149 ( V_295 ) ;
goto V_808;
}
V_806 = F_117 ( V_295 , V_247 ) ;
V_806 += F_279 ( V_320 ) ;
switch ( V_778 ) {
case 1 :
V_807 = F_280 ( T_10 , V_806 , V_804 , V_805 ) ;
break;
case 2 :
V_807 = F_280 ( V_809 , V_806 , V_804 , V_805 ) ;
break;
case 4 :
V_807 = F_280 ( T_1 , V_806 , V_804 , V_805 ) ;
break;
case 8 :
V_807 = F_281 ( V_806 , V_804 , V_805 ) ;
break;
default:
F_282 () ;
}
F_118 ( V_806 , V_247 ) ;
F_144 ( V_295 ) ;
if ( ! V_807 )
return V_810 ;
F_275 ( V_2 , V_320 , V_805 , V_778 , 1 ) ;
return V_779 ;
V_808:
F_104 ( V_210 L_22 ) ;
return F_277 ( V_784 , V_305 , V_805 , V_778 , V_49 ) ;
}
static int F_283 ( struct V_1 * V_2 , void * V_811 )
{
int V_98 ;
if ( V_2 -> V_5 . V_812 . V_813 )
V_98 = F_257 ( V_2 -> V_29 , V_733 , V_2 -> V_5 . V_812 . V_814 ,
V_2 -> V_5 . V_812 . V_388 , V_811 ) ;
else
V_98 = F_254 ( V_2 -> V_29 , V_733 ,
V_2 -> V_5 . V_812 . V_814 , V_2 -> V_5 . V_812 . V_388 ,
V_811 ) ;
return V_98 ;
}
static int F_284 ( struct V_783 * V_784 ,
int V_388 , unsigned short V_814 , void * V_150 ,
unsigned int V_698 )
{
struct V_1 * V_2 = F_269 ( V_784 ) ;
if ( V_2 -> V_5 . V_812 . V_698 )
goto V_815;
F_285 ( 0 , V_814 , V_388 , V_698 ) ;
V_2 -> V_5 . V_812 . V_814 = V_814 ;
V_2 -> V_5 . V_812 . V_813 = 1 ;
V_2 -> V_5 . V_812 . V_698 = V_698 ;
V_2 -> V_5 . V_812 . V_388 = V_388 ;
if ( ! F_283 ( V_2 , V_2 -> V_5 . V_816 ) ) {
V_815:
memcpy ( V_150 , V_2 -> V_5 . V_816 , V_388 * V_698 ) ;
V_2 -> V_5 . V_812 . V_698 = 0 ;
return 1 ;
}
V_2 -> V_793 -> V_794 = V_817 ;
V_2 -> V_793 -> V_818 . V_819 = V_820 ;
V_2 -> V_793 -> V_818 . V_388 = V_388 ;
V_2 -> V_793 -> V_818 . V_821 = V_822 * V_86 ;
V_2 -> V_793 -> V_818 . V_698 = V_698 ;
V_2 -> V_793 -> V_818 . V_814 = V_814 ;
return 0 ;
}
static int F_286 ( struct V_783 * V_784 ,
int V_388 , unsigned short V_814 ,
const void * V_150 , unsigned int V_698 )
{
struct V_1 * V_2 = F_269 ( V_784 ) ;
F_285 ( 1 , V_814 , V_388 , V_698 ) ;
V_2 -> V_5 . V_812 . V_814 = V_814 ;
V_2 -> V_5 . V_812 . V_813 = 0 ;
V_2 -> V_5 . V_812 . V_698 = V_698 ;
V_2 -> V_5 . V_812 . V_388 = V_388 ;
memcpy ( V_2 -> V_5 . V_816 , V_150 , V_388 * V_698 ) ;
if ( ! F_283 ( V_2 , V_2 -> V_5 . V_816 ) ) {
V_2 -> V_5 . V_812 . V_698 = 0 ;
return 1 ;
}
V_2 -> V_793 -> V_794 = V_817 ;
V_2 -> V_793 -> V_818 . V_819 = V_823 ;
V_2 -> V_793 -> V_818 . V_388 = V_388 ;
V_2 -> V_793 -> V_818 . V_821 = V_822 * V_86 ;
V_2 -> V_793 -> V_818 . V_698 = V_698 ;
V_2 -> V_793 -> V_818 . V_814 = V_814 ;
return 0 ;
}
static unsigned long F_287 ( struct V_1 * V_2 , int V_771 )
{
return V_56 -> F_287 ( V_2 , V_771 ) ;
}
static void F_288 ( struct V_783 * V_784 , V_145 V_63 )
{
F_289 ( F_269 ( V_784 ) , V_63 ) ;
}
int F_290 ( struct V_1 * V_2 )
{
if ( ! F_172 ( V_2 ) )
return V_779 ;
if ( V_56 -> V_461 () ) {
int V_206 = F_97 () ;
F_174 ( V_206 , V_2 -> V_5 . V_462 ) ;
F_291 ( V_2 -> V_5 . V_462 ,
F_170 , NULL , 1 ) ;
F_100 () ;
F_292 ( V_2 -> V_5 . V_462 ) ;
} else
F_171 () ;
return V_779 ;
}
static void F_293 ( struct V_783 * V_784 )
{
F_290 ( F_269 ( V_784 ) ) ;
}
int F_294 ( struct V_783 * V_784 , int V_149 , unsigned long * V_824 )
{
return F_77 ( F_269 ( V_784 ) , V_149 , V_824 ) ;
}
int F_295 ( struct V_783 * V_784 , int V_149 , unsigned long V_23 )
{
return F_75 ( F_269 ( V_784 ) , V_149 , V_23 ) ;
}
static T_2 F_296 ( T_2 V_825 , T_1 V_826 )
{
return ( V_825 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_826 ;
}
static unsigned long F_297 ( struct V_783 * V_784 , int V_827 )
{
struct V_1 * V_2 = F_269 ( V_784 ) ;
unsigned long V_23 ;
switch ( V_827 ) {
case 0 :
V_23 = F_50 ( V_2 ) ;
break;
case 2 :
V_23 = V_2 -> V_5 . V_62 ;
break;
case 3 :
V_23 = F_48 ( V_2 ) ;
break;
case 4 :
V_23 = F_65 ( V_2 ) ;
break;
case 8 :
V_23 = F_73 ( V_2 ) ;
break;
default:
F_298 ( V_2 , L_23 , V_204 , V_827 ) ;
return 0 ;
}
return V_23 ;
}
static int F_299 ( struct V_783 * V_784 , int V_827 , V_145 V_150 )
{
struct V_1 * V_2 = F_269 ( V_784 ) ;
int V_165 = 0 ;
switch ( V_827 ) {
case 0 :
V_165 = F_49 ( V_2 , F_296 ( F_50 ( V_2 ) , V_150 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_62 = V_150 ;
break;
case 3 :
V_165 = F_66 ( V_2 , V_150 ) ;
break;
case 4 :
V_165 = F_64 ( V_2 , F_296 ( F_65 ( V_2 ) , V_150 ) ) ;
break;
case 8 :
V_165 = F_71 ( V_2 , V_150 ) ;
break;
default:
F_298 ( V_2 , L_23 , V_204 , V_827 ) ;
V_165 = - 1 ;
}
return V_165 ;
}
static int F_300 ( struct V_783 * V_784 )
{
return V_56 -> V_70 ( F_269 ( V_784 ) ) ;
}
static void F_301 ( struct V_783 * V_784 , struct V_828 * V_829 )
{
V_56 -> V_830 ( F_269 ( V_784 ) , V_829 ) ;
}
static void F_302 ( struct V_783 * V_784 , struct V_828 * V_829 )
{
V_56 -> V_831 ( F_269 ( V_784 ) , V_829 ) ;
}
static void F_303 ( struct V_783 * V_784 , struct V_828 * V_829 )
{
V_56 -> V_832 ( F_269 ( V_784 ) , V_829 ) ;
}
static void F_304 ( struct V_783 * V_784 , struct V_828 * V_829 )
{
V_56 -> V_833 ( F_269 ( V_784 ) , V_829 ) ;
}
static unsigned long F_305 (
struct V_783 * V_784 , int V_771 )
{
return F_287 ( F_269 ( V_784 ) , V_771 ) ;
}
static bool F_306 ( struct V_783 * V_784 , V_809 * V_834 ,
struct V_835 * V_836 , T_1 * V_837 ,
int V_771 )
{
struct V_769 V_770 ;
F_260 ( F_269 ( V_784 ) , & V_770 , V_771 ) ;
* V_834 = V_770 . V_834 ;
if ( V_770 . V_838 )
return false ;
if ( V_770 . V_839 )
V_770 . V_574 >>= 12 ;
F_307 ( V_836 , V_770 . V_574 ) ;
F_308 ( V_836 , ( unsigned long ) V_770 . V_840 ) ;
#ifdef F_51
if ( V_837 )
* V_837 = V_770 . V_840 >> 32 ;
#endif
V_836 -> type = V_770 . type ;
V_836 -> V_579 = V_770 . V_579 ;
V_836 -> V_841 = V_770 . V_841 ;
V_836 -> V_264 = V_770 . V_842 ;
V_836 -> V_843 = V_770 . V_843 ;
V_836 -> V_844 = V_770 . V_844 ;
V_836 -> V_845 = V_770 . V_151 ;
V_836 -> V_839 = V_770 . V_839 ;
return true ;
}
static void F_309 ( struct V_783 * V_784 , V_809 V_834 ,
struct V_835 * V_836 , T_1 V_837 ,
int V_771 )
{
struct V_1 * V_2 = F_269 ( V_784 ) ;
struct V_769 V_770 ;
V_770 . V_834 = V_834 ;
V_770 . V_840 = F_310 ( V_836 ) ;
#ifdef F_51
V_770 . V_840 |= ( ( T_2 ) V_837 ) << 32 ;
#endif
V_770 . V_574 = F_311 ( V_836 ) ;
if ( V_836 -> V_839 )
V_770 . V_574 = ( V_770 . V_574 << 12 ) | 0xfff ;
V_770 . type = V_836 -> type ;
V_770 . V_842 = V_836 -> V_264 ;
V_770 . V_841 = V_836 -> V_841 ;
V_770 . V_151 = V_836 -> V_845 ;
V_770 . V_579 = V_836 -> V_579 ;
V_770 . V_844 = V_836 -> V_844 ;
V_770 . V_839 = V_836 -> V_839 ;
V_770 . V_843 = V_836 -> V_843 ;
V_770 . V_842 = V_836 -> V_264 ;
V_770 . V_838 = ! V_770 . V_842 ;
V_770 . V_477 = 0 ;
F_259 ( V_2 , & V_770 , V_771 ) ;
return;
}
static int F_312 ( struct V_783 * V_784 ,
T_1 V_180 , T_2 * V_363 )
{
return F_115 ( F_269 ( V_784 ) , V_180 , V_363 ) ;
}
static int F_313 ( struct V_783 * V_784 ,
T_1 V_180 , T_2 V_31 )
{
return F_81 ( F_269 ( V_784 ) , V_180 , V_31 ) ;
}
static void F_314 ( struct V_783 * V_784 )
{
F_269 ( V_784 ) -> V_5 . V_846 = 1 ;
}
static void F_315 ( struct V_783 * V_784 )
{
F_316 () ;
F_317 ( F_269 ( V_784 ) ) ;
F_318 () ;
}
static void F_319 ( struct V_783 * V_784 )
{
F_320 () ;
}
static int F_321 ( struct V_783 * V_784 ,
struct V_847 * V_848 ,
enum V_849 V_850 )
{
return V_56 -> V_851 ( F_269 ( V_784 ) , V_848 , V_850 ) ;
}
static void F_322 ( struct V_1 * V_2 )
{
F_323 ( V_2 , V_852 ) ;
F_323 ( V_2 , V_853 ) ;
F_323 ( V_2 , V_854 ) ;
V_2 -> V_5 . V_96 = ~ 0 ;
}
static void F_324 ( struct V_1 * V_2 , T_1 V_26 )
{
T_1 V_855 = V_56 -> V_607 ( V_2 , V_26 ) ;
if ( ! ( V_855 & V_26 ) )
V_56 -> V_619 ( V_2 , V_26 ) ;
}
static void F_325 ( struct V_1 * V_2 )
{
struct V_783 * V_784 = & V_2 -> V_5 . V_856 ;
if ( V_784 -> V_49 . V_32 == V_33 )
F_30 ( V_2 , & V_784 -> V_49 ) ;
else if ( V_784 -> V_49 . V_857 )
F_29 ( V_2 , V_784 -> V_49 . V_32 ,
V_784 -> V_49 . V_43 ) ;
else
F_24 ( V_2 , V_784 -> V_49 . V_32 ) ;
}
static void F_326 ( struct V_1 * V_2 )
{
struct V_858 * V_859 = & V_2 -> V_5 . V_856 . V_860 ;
int V_111 , V_112 ;
F_322 ( V_2 ) ;
V_56 -> V_113 ( V_2 , & V_111 , & V_112 ) ;
V_2 -> V_5 . V_856 . V_861 = F_327 ( V_2 ) ;
V_2 -> V_5 . V_856 . V_862 = F_328 ( V_2 ) ;
V_2 -> V_5 . V_856 . V_863 =
( ! F_329 ( V_2 ) ) ? V_864 :
( V_2 -> V_5 . V_856 . V_861 & V_865 )
? V_866 : V_112
? V_867 : V_111
? V_868 : V_869 ;
V_2 -> V_5 . V_856 . V_870 = F_330 ( V_2 ) ;
memset ( V_859 , 0 , sizeof( struct V_858 ) ) ;
memcpy ( V_859 -> V_580 , V_2 -> V_5 . V_580 , sizeof V_859 -> V_580 ) ;
V_2 -> V_5 . V_871 = false ;
}
int F_331 ( struct V_1 * V_2 , int V_583 , int V_872 )
{
struct V_858 * V_859 = & V_2 -> V_5 . V_856 . V_860 ;
int V_87 ;
F_326 ( V_2 ) ;
V_2 -> V_5 . V_856 . V_860 . V_873 = 2 ;
V_2 -> V_5 . V_856 . V_860 . V_874 = 2 ;
V_2 -> V_5 . V_856 . V_860 . V_862 = V_2 -> V_5 . V_856 . V_862 +
V_872 ;
V_87 = F_332 ( & V_2 -> V_5 . V_856 , & V_875 , V_583 ) ;
if ( V_87 != V_779 )
return V_876 ;
V_2 -> V_5 . V_856 . V_862 = V_859 -> V_862 ;
memcpy ( V_2 -> V_5 . V_580 , V_859 -> V_580 , sizeof V_859 -> V_580 ) ;
F_333 ( V_2 , V_2 -> V_5 . V_856 . V_862 ) ;
F_334 ( V_2 , V_2 -> V_5 . V_856 . V_861 ) ;
if ( V_583 == V_877 )
V_2 -> V_5 . V_68 = false ;
else
V_2 -> V_5 . V_604 . V_50 = false ;
return V_878 ;
}
static int F_335 ( struct V_1 * V_2 )
{
int V_98 = V_878 ;
++ V_2 -> V_60 . V_879 ;
F_336 ( V_2 ) ;
if ( ! F_330 ( V_2 ) ) {
V_2 -> V_793 -> V_794 = V_880 ;
V_2 -> V_793 -> V_881 . V_882 = V_883 ;
V_2 -> V_793 -> V_881 . V_884 = 0 ;
V_98 = V_876 ;
}
F_24 ( V_2 , V_166 ) ;
return V_98 ;
}
static bool F_337 ( struct V_1 * V_2 , T_12 V_776 )
{
T_4 V_320 ;
if ( V_179 )
return false ;
if ( F_338 ( V_2 , V_776 ) )
return true ;
V_320 = F_266 ( V_2 , V_776 , NULL ) ;
if ( V_320 == V_79 )
return true ;
if ( ! F_134 ( F_133 ( V_2 -> V_29 , V_320 >> V_85 ) ) )
return true ;
return false ;
}
int F_339 ( struct V_1 * V_2 ,
unsigned long V_62 ,
int V_885 ,
void * V_886 ,
int V_887 )
{
int V_98 ;
struct V_858 * V_859 = & V_2 -> V_5 . V_856 . V_860 ;
bool V_386 = true ;
F_340 ( V_2 ) ;
if ( ! ( V_885 & V_888 ) ) {
F_326 ( V_2 ) ;
V_2 -> V_5 . V_856 . V_889 = 0 ;
V_2 -> V_5 . V_856 . V_890 = false ;
V_2 -> V_5 . V_856 . V_891 = false ;
V_2 -> V_5 . V_856 . V_892
= V_885 & V_893 ;
V_98 = F_341 ( & V_2 -> V_5 . V_856 , V_886 , V_887 ) ;
F_342 ( V_2 ) ;
++ V_2 -> V_60 . V_894 ;
if ( V_98 ) {
if ( V_885 & V_893 )
return V_876 ;
if ( F_337 ( V_2 , V_62 ) )
return V_878 ;
if ( V_885 & V_895 )
return V_876 ;
return F_335 ( V_2 ) ;
}
}
if ( V_885 & V_895 ) {
F_333 ( V_2 , V_2 -> V_5 . V_856 . V_860 . V_862 ) ;
return V_878 ;
}
if ( V_2 -> V_5 . V_871 ) {
V_2 -> V_5 . V_871 = false ;
memcpy ( V_859 -> V_580 , V_2 -> V_5 . V_580 , sizeof V_859 -> V_580 ) ;
}
V_896:
V_98 = F_343 ( & V_2 -> V_5 . V_856 ) ;
if ( V_98 == V_897 )
return V_878 ;
if ( V_98 == V_898 ) {
if ( F_337 ( V_2 , V_62 ) )
return V_878 ;
return F_335 ( V_2 ) ;
}
if ( V_2 -> V_5 . V_856 . V_890 ) {
F_325 ( V_2 ) ;
V_98 = V_878 ;
} else if ( V_2 -> V_5 . V_812 . V_698 ) {
if ( ! V_2 -> V_5 . V_812 . V_813 )
V_2 -> V_5 . V_812 . V_698 = 0 ;
else
V_386 = false ;
V_98 = V_899 ;
} else if ( V_2 -> V_792 ) {
if ( ! V_2 -> V_799 )
V_386 = false ;
V_98 = V_899 ;
} else if ( V_98 == V_900 )
goto V_896;
else
V_98 = V_878 ;
if ( V_386 ) {
F_324 ( V_2 ,
V_2 -> V_5 . V_856 . V_889 ) ;
F_334 ( V_2 , V_2 -> V_5 . V_856 . V_861 ) ;
F_23 ( V_48 , V_2 ) ;
memcpy ( V_2 -> V_5 . V_580 , V_859 -> V_580 , sizeof V_859 -> V_580 ) ;
V_2 -> V_5 . V_901 = false ;
F_333 ( V_2 , V_2 -> V_5 . V_856 . V_862 ) ;
} else
V_2 -> V_5 . V_901 = true ;
return V_98 ;
}
int F_344 ( struct V_1 * V_2 , int V_388 , unsigned short V_814 )
{
unsigned long V_150 = F_323 ( V_2 , V_852 ) ;
int V_87 = F_286 ( & V_2 -> V_5 . V_856 ,
V_388 , V_814 , & V_150 , 1 ) ;
V_2 -> V_5 . V_812 . V_698 = 0 ;
return V_87 ;
}
static void F_345 ( void * V_848 )
{
F_346 ( V_209 , 0 ) ;
}
static void F_347 ( void * V_31 )
{
struct V_902 * V_903 = V_31 ;
unsigned long V_904 = 0 ;
if ( V_31 )
V_904 = V_903 -> V_805 ;
else if ( ! F_98 ( V_207 ) )
V_904 = F_99 ( F_348 () ) ;
if ( ! V_904 )
V_904 = V_905 ;
F_346 ( V_209 , V_904 ) ;
}
static int F_349 ( struct V_906 * V_907 , unsigned long V_150 ,
void * V_31 )
{
struct V_902 * V_903 = V_31 ;
struct V_29 * V_29 ;
struct V_1 * V_2 ;
int V_3 , V_908 = 0 ;
if ( V_150 == V_909 && V_903 -> V_804 > V_903 -> V_805 )
return 0 ;
if ( V_150 == V_910 && V_903 -> V_804 < V_903 -> V_805 )
return 0 ;
F_175 ( V_903 -> V_206 , F_347 , V_903 , 1 ) ;
F_350 ( & V_911 ) ;
F_351 (kvm, &vm_list, vm_list) {
F_156 (i, vcpu, kvm) {
if ( V_2 -> V_206 != V_903 -> V_206 )
continue;
F_23 ( V_236 , V_2 ) ;
if ( V_2 -> V_206 != F_352 () )
V_908 = 1 ;
}
}
F_353 ( & V_911 ) ;
if ( V_903 -> V_804 < V_903 -> V_805 && V_908 ) {
F_175 ( V_903 -> V_206 , F_347 , V_903 , 1 ) ;
}
return 0 ;
}
static int F_354 ( struct V_906 * V_912 ,
unsigned long V_913 , void * V_914 )
{
unsigned int V_206 = ( unsigned long ) V_914 ;
switch ( V_913 ) {
case V_915 :
case V_916 :
F_175 ( V_206 , F_347 , NULL , 1 ) ;
break;
case V_917 :
F_175 ( V_206 , F_345 , NULL , 1 ) ;
break;
}
return V_918 ;
}
static void F_355 ( void )
{
int V_206 ;
V_919 = V_905 ;
F_356 ( & V_920 ) ;
if ( ! F_98 ( V_207 ) ) {
#ifdef F_357
struct V_921 V_922 ;
memset ( & V_922 , 0 , sizeof( V_922 ) ) ;
V_206 = F_97 () ;
F_358 ( & V_922 , V_206 ) ;
if ( V_922 . V_923 . V_924 )
V_919 = V_922 . V_923 . V_924 ;
F_100 () ;
#endif
F_359 ( & V_925 ,
V_926 ) ;
}
F_89 ( L_24 , V_919 ) ;
F_360 (cpu)
F_175 ( V_206 , F_347 , NULL , 1 ) ;
}
static int F_361 ( void )
{
return F_362 ( V_927 ) != NULL ;
}
static int F_363 ( void )
{
int V_928 = 3 ;
if ( F_362 ( V_927 ) )
V_928 = V_56 -> V_70 ( F_362 ( V_927 ) ) ;
return V_928 != 0 ;
}
static unsigned long F_364 ( void )
{
unsigned long V_929 = 0 ;
if ( F_362 ( V_927 ) )
V_929 = F_328 ( F_362 ( V_927 ) ) ;
return V_929 ;
}
void F_365 ( struct V_1 * V_2 )
{
F_366 ( V_927 , V_2 ) ;
}
void F_367 ( struct V_1 * V_2 )
{
F_366 ( V_927 , NULL ) ;
}
int F_368 ( void * V_930 )
{
int V_98 ;
struct V_56 * V_931 = (struct V_56 * ) V_930 ;
if ( V_56 ) {
F_9 ( V_25 L_25 ) ;
V_98 = - V_731 ;
goto V_92;
}
if ( ! V_931 -> V_932 () ) {
F_9 ( V_25 L_26 ) ;
V_98 = - V_933 ;
goto V_92;
}
if ( V_931 -> V_934 () ) {
F_9 ( V_25 L_27 ) ;
V_98 = - V_933 ;
goto V_92;
}
V_98 = F_369 () ;
if ( V_98 )
goto V_92;
F_250 () ;
V_56 = V_931 ;
F_370 ( 0ull , 0ull ) ;
F_371 ( V_935 , V_936 ,
V_937 , V_938 , 0 ) ;
F_355 () ;
F_372 ( & V_939 ) ;
if ( V_129 )
V_123 = F_373 ( V_119 ) ;
return 0 ;
V_92:
return V_98 ;
}
void F_374 ( void )
{
F_375 ( & V_939 ) ;
if ( ! F_98 ( V_207 ) )
F_376 ( & V_925 ,
V_926 ) ;
F_377 ( & V_920 ) ;
V_56 = NULL ;
F_378 () ;
}
int F_379 ( struct V_1 * V_2 )
{
++ V_2 -> V_60 . V_940 ;
if ( F_18 ( V_2 -> V_29 ) ) {
V_2 -> V_5 . V_941 = V_942 ;
return 1 ;
} else {
V_2 -> V_793 -> V_794 = V_943 ;
return 0 ;
}
}
static inline T_4 F_380 ( struct V_1 * V_2 , unsigned long V_944 ,
unsigned long V_945 )
{
if ( F_45 ( V_2 ) )
return V_944 ;
else
return V_944 | ( ( T_4 ) V_945 << 32 ) ;
}
int F_381 ( struct V_1 * V_2 )
{
T_2 V_946 , V_947 , V_948 , V_87 ;
T_13 V_949 , V_950 , V_951 , V_165 = V_952 , V_953 = 0 ;
bool V_954 , V_955 ;
int V_111 , V_112 ;
if ( V_56 -> V_70 ( V_2 ) != 0 || ! F_329 ( V_2 ) ) {
F_24 ( V_2 , V_166 ) ;
return 0 ;
}
V_56 -> V_113 ( V_2 , & V_111 , & V_112 ) ;
V_955 = F_45 ( V_2 ) && V_112 == 1 ;
if ( ! V_955 ) {
V_946 = ( ( T_2 ) F_323 ( V_2 , V_956 ) << 32 ) |
( F_323 ( V_2 , V_852 ) & 0xffffffff ) ;
V_947 = ( ( T_2 ) F_323 ( V_2 , V_957 ) << 32 ) |
( F_323 ( V_2 , V_958 ) & 0xffffffff ) ;
V_948 = ( ( T_2 ) F_323 ( V_2 , V_959 ) << 32 ) |
( F_323 ( V_2 , V_960 ) & 0xffffffff ) ;
}
#ifdef F_51
else {
V_946 = F_323 ( V_2 , V_958 ) ;
V_947 = F_323 ( V_2 , V_956 ) ;
V_948 = F_323 ( V_2 , V_961 ) ;
}
#endif
V_949 = V_946 & 0xffff ;
V_954 = ( V_946 >> 16 ) & 0x1 ;
V_951 = ( V_946 >> 32 ) & 0xfff ;
V_950 = ( V_946 >> 48 ) & 0xfff ;
F_382 ( V_949 , V_954 , V_951 , V_950 , V_947 , V_948 ) ;
switch ( V_949 ) {
case V_962 :
F_383 ( V_2 ) ;
break;
default:
V_165 = V_963 ;
break;
}
V_87 = V_165 | ( ( ( T_2 ) V_953 & 0xfff ) << 32 ) ;
if ( V_955 ) {
F_384 ( V_2 , V_852 , V_87 ) ;
} else {
F_384 ( V_2 , V_956 , V_87 >> 32 ) ;
F_384 ( V_2 , V_852 , V_87 & 0xffffffff ) ;
}
return 1 ;
}
int F_385 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_944 , V_945 , V_964 , V_965 , V_87 ;
int V_98 = 1 ;
if ( F_130 ( V_2 -> V_29 ) )
return F_381 ( V_2 ) ;
V_16 = F_323 ( V_2 , V_852 ) ;
V_944 = F_323 ( V_2 , V_957 ) ;
V_945 = F_323 ( V_2 , V_958 ) ;
V_964 = F_323 ( V_2 , V_956 ) ;
V_965 = F_323 ( V_2 , V_960 ) ;
F_386 ( V_16 , V_944 , V_945 , V_964 , V_965 ) ;
if ( ! F_45 ( V_2 ) ) {
V_16 &= 0xFFFFFFFF ;
V_944 &= 0xFFFFFFFF ;
V_945 &= 0xFFFFFFFF ;
V_964 &= 0xFFFFFFFF ;
V_965 &= 0xFFFFFFFF ;
}
if ( V_56 -> V_70 ( V_2 ) != 0 ) {
V_87 = - V_966 ;
goto V_92;
}
switch ( V_16 ) {
case V_967 :
V_87 = 0 ;
break;
case V_968 :
V_98 = F_387 ( V_2 , V_944 , F_380 ( V_2 , V_945 , V_964 ) , & V_87 ) ;
break;
default:
V_87 = - V_969 ;
break;
}
V_92:
F_384 ( V_2 , V_852 , V_87 ) ;
++ V_2 -> V_60 . V_970 ;
return V_98 ;
}
int F_388 ( struct V_783 * V_784 )
{
struct V_1 * V_2 = F_269 ( V_784 ) ;
char V_971 [ 3 ] ;
unsigned long V_972 = F_328 ( V_2 ) ;
F_389 ( V_2 -> V_29 ) ;
V_56 -> V_308 ( V_2 , V_971 ) ;
return F_277 ( & V_2 -> V_5 . V_856 ,
V_972 , V_971 , 3 , NULL ) ;
}
static int F_390 ( struct V_1 * V_2 , int V_3 )
{
struct V_125 * V_466 = & V_2 -> V_5 . V_469 [ V_3 ] ;
int V_764 , V_473 = V_2 -> V_5 . V_468 ;
V_466 -> V_222 &= ~ V_560 ;
for ( V_764 = V_3 + 1 ; ; V_764 = ( V_764 + 1 ) % V_473 ) {
struct V_125 * V_973 = & V_2 -> V_5 . V_469 [ V_764 ] ;
if ( V_973 -> V_130 == V_466 -> V_130 ) {
V_973 -> V_222 |= V_560 ;
return V_764 ;
}
}
return 0 ;
}
static int F_391 ( struct V_125 * V_466 ,
T_1 V_130 , T_1 V_116 )
{
if ( V_466 -> V_130 != V_130 )
return 0 ;
if ( ( V_466 -> V_222 & V_562 ) && V_466 -> V_116 != V_116 )
return 0 ;
if ( ( V_466 -> V_222 & V_559 ) &&
! ( V_466 -> V_222 & V_560 ) )
return 0 ;
return 1 ;
}
struct V_125 * F_60 ( struct V_1 * V_2 ,
T_1 V_130 , T_1 V_116 )
{
int V_3 ;
struct V_125 * V_126 = NULL ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 . V_468 ; ++ V_3 ) {
struct V_125 * V_466 ;
V_466 = & V_2 -> V_5 . V_469 [ V_3 ] ;
if ( F_391 ( V_466 , V_130 , V_116 ) ) {
if ( V_466 -> V_222 & V_559 )
F_390 ( V_2 , V_3 ) ;
V_126 = V_466 ;
break;
}
}
return V_126 ;
}
int F_392 ( struct V_1 * V_2 )
{
struct V_125 * V_126 ;
V_126 = F_60 ( V_2 , 0x80000000 , 0 ) ;
if ( ! V_126 || V_126 -> V_475 < 0x80000008 )
goto V_974;
V_126 = F_60 ( V_2 , 0x80000008 , 0 ) ;
if ( V_126 )
return V_126 -> V_475 & 0xff ;
V_974:
return 36 ;
}
static struct V_125 * F_393 ( struct V_1 * V_2 ,
T_1 V_130 , T_1 V_116 )
{
struct V_125 * V_975 ;
V_975 = F_60 ( V_2 , V_130 & 0x80000000 , 0 ) ;
if ( ! V_975 || V_975 -> V_475 >= V_130 )
return NULL ;
if ( V_130 & 0x80000000 ) {
V_975 = F_60 ( V_2 , 0 , 0 ) ;
if ( ! V_975 )
return NULL ;
}
return F_60 ( V_2 , V_975 -> V_475 , V_116 ) ;
}
void F_394 ( struct V_1 * V_2 )
{
T_1 V_130 , V_116 ;
struct V_125 * V_126 ;
V_130 = F_323 ( V_2 , V_852 ) ;
V_116 = F_323 ( V_2 , V_958 ) ;
F_384 ( V_2 , V_852 , 0 ) ;
F_384 ( V_2 , V_957 , 0 ) ;
F_384 ( V_2 , V_958 , 0 ) ;
F_384 ( V_2 , V_956 , 0 ) ;
V_126 = F_60 ( V_2 , V_130 , V_116 ) ;
if ( ! V_126 )
V_126 = F_393 ( V_2 , V_130 , V_116 ) ;
if ( V_126 ) {
F_384 ( V_2 , V_852 , V_126 -> V_475 ) ;
F_384 ( V_2 , V_957 , V_126 -> V_476 ) ;
F_384 ( V_2 , V_958 , V_126 -> V_127 ) ;
F_384 ( V_2 , V_956 , V_126 -> V_171 ) ;
}
V_56 -> V_57 ( V_2 ) ;
F_395 ( V_130 ,
F_323 ( V_2 , V_852 ) ,
F_323 ( V_2 , V_957 ) ,
F_323 ( V_2 , V_958 ) ,
F_323 ( V_2 , V_956 ) ) ;
}
static int F_396 ( struct V_1 * V_2 )
{
return ( ! F_18 ( V_2 -> V_29 ) && ! F_397 ( V_2 ) &&
V_2 -> V_793 -> V_976 &&
F_398 ( V_2 ) ) ;
}
static void F_399 ( struct V_1 * V_2 )
{
struct V_977 * V_977 = V_2 -> V_793 ;
V_977 -> V_978 = ( F_327 ( V_2 ) & V_979 ) != 0 ;
V_977 -> V_147 = F_73 ( V_2 ) ;
V_977 -> V_30 = F_17 ( V_2 ) ;
if ( F_18 ( V_2 -> V_29 ) )
V_977 -> V_980 = 1 ;
else
V_977 -> V_980 =
F_398 ( V_2 ) &&
! F_397 ( V_2 ) &&
! F_400 ( V_2 ) ;
}
static void F_401 ( struct V_1 * V_2 )
{
struct V_981 * V_581 = V_2 -> V_5 . V_581 ;
struct V_295 * V_295 ;
if ( ! V_581 || ! V_581 -> V_657 )
return;
V_295 = F_147 ( V_2 -> V_29 , V_581 -> V_657 >> V_85 ) ;
V_2 -> V_5 . V_581 -> V_982 = V_295 ;
}
static void F_402 ( struct V_1 * V_2 )
{
struct V_981 * V_581 = V_2 -> V_5 . V_581 ;
int V_270 ;
if ( ! V_581 || ! V_581 -> V_657 )
return;
V_270 = F_162 ( & V_2 -> V_29 -> V_383 ) ;
F_144 ( V_581 -> V_982 ) ;
F_119 ( V_2 -> V_29 , V_581 -> V_657 >> V_85 ) ;
F_163 ( & V_2 -> V_29 -> V_383 , V_270 ) ;
}
static void F_197 ( struct V_1 * V_2 )
{
int V_983 , V_984 ;
if ( ! V_56 -> F_197 )
return;
if ( ! V_2 -> V_5 . V_581 )
return;
if ( ! V_2 -> V_5 . V_581 -> V_657 )
V_983 = F_403 ( V_2 ) ;
else
V_983 = - 1 ;
if ( V_983 != - 1 )
V_983 >>= 4 ;
V_984 = F_74 ( V_2 ) ;
V_56 -> F_197 ( V_2 , V_984 , V_983 ) ;
}
static void F_404 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_49 . V_50 ) {
F_405 ( V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ) ;
V_56 -> V_985 ( V_2 , V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ,
V_2 -> V_5 . V_49 . V_44 ) ;
return;
}
if ( V_2 -> V_5 . V_611 ) {
V_56 -> V_986 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_604 . V_50 ) {
V_56 -> V_987 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_68 ) {
if ( V_56 -> V_988 ( V_2 ) ) {
V_2 -> V_5 . V_68 = false ;
V_2 -> V_5 . V_611 = true ;
V_56 -> V_986 ( V_2 ) ;
}
} else if ( F_397 ( V_2 ) ) {
if ( V_56 -> V_989 ( V_2 ) ) {
F_199 ( V_2 , F_406 ( V_2 ) ,
false ) ;
V_56 -> V_987 ( V_2 ) ;
}
}
}
static void F_407 ( struct V_1 * V_2 )
{
if ( F_63 ( V_2 , V_132 ) &&
! V_2 -> V_124 ) {
F_408 ( V_119 , V_2 -> V_5 . V_118 ) ;
V_2 -> V_124 = 1 ;
}
}
static void F_409 ( struct V_1 * V_2 )
{
if ( V_2 -> V_124 ) {
if ( V_2 -> V_5 . V_118 != V_123 )
F_408 ( V_119 , V_123 ) ;
V_2 -> V_124 = 0 ;
}
}
static int F_410 ( struct V_1 * V_2 )
{
int V_98 ;
bool V_68 ;
bool V_990 = ! F_18 ( V_2 -> V_29 ) &&
V_2 -> V_793 -> V_976 ;
if ( V_2 -> V_991 ) {
if ( F_411 ( V_992 , V_2 ) )
F_412 ( V_2 ) ;
if ( F_411 ( V_993 , V_2 ) )
F_413 ( V_2 ) ;
if ( F_411 ( V_236 , V_2 ) ) {
V_98 = F_113 ( V_2 ) ;
if ( F_69 ( V_98 ) )
goto V_92;
}
if ( F_411 ( V_994 , V_2 ) )
F_67 ( V_2 ) ;
if ( F_411 ( V_995 , V_2 ) )
V_56 -> V_996 ( V_2 ) ;
if ( F_411 ( V_997 , V_2 ) ) {
V_2 -> V_793 -> V_794 = V_998 ;
V_98 = 0 ;
goto V_92;
}
if ( F_411 ( V_54 , V_2 ) ) {
V_2 -> V_793 -> V_794 = V_999 ;
V_98 = 0 ;
goto V_92;
}
if ( F_411 ( V_1000 , V_2 ) ) {
V_2 -> V_1001 = 0 ;
V_56 -> V_1002 ( V_2 ) ;
}
if ( F_411 ( V_1003 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1004 = true ;
V_98 = 1 ;
goto V_92;
}
}
V_98 = F_414 ( V_2 ) ;
if ( F_69 ( V_98 ) )
goto V_92;
V_68 = F_415 ( V_2 -> V_5 . V_68 ) ;
if ( F_411 ( V_48 , V_2 ) || V_990 ) {
F_404 ( V_2 ) ;
if ( V_68 )
V_56 -> V_1005 ( V_2 ) ;
else if ( F_397 ( V_2 ) || V_990 )
V_56 -> V_1006 ( V_2 ) ;
if ( F_416 ( V_2 ) ) {
F_197 ( V_2 ) ;
F_417 ( V_2 ) ;
}
}
F_316 () ;
V_56 -> V_1007 ( V_2 ) ;
if ( V_2 -> V_1001 )
F_317 ( V_2 ) ;
F_407 ( V_2 ) ;
V_2 -> V_863 = V_1008 ;
F_418 () ;
F_248 () ;
if ( V_2 -> V_863 == V_1009 || V_2 -> V_991
|| F_419 () || F_420 ( V_1010 ) ) {
V_2 -> V_863 = V_1011 ;
F_12 () ;
F_249 () ;
F_320 () ;
V_56 -> V_1012 ( V_2 ) ;
V_98 = 1 ;
goto V_92;
}
F_163 ( & V_2 -> V_29 -> V_383 , V_2 -> V_1013 ) ;
F_421 () ;
if ( F_69 ( V_2 -> V_5 . V_163 ) ) {
F_422 ( 0 , 7 ) ;
F_422 ( V_2 -> V_5 . V_154 [ 0 ] , 0 ) ;
F_422 ( V_2 -> V_5 . V_154 [ 1 ] , 1 ) ;
F_422 ( V_2 -> V_5 . V_154 [ 2 ] , 2 ) ;
F_422 ( V_2 -> V_5 . V_154 [ 3 ] , 3 ) ;
}
F_423 ( V_2 -> V_1014 ) ;
V_56 -> V_793 ( V_2 ) ;
if ( F_424 () )
F_425 () ;
F_115 ( V_2 , V_235 , & V_2 -> V_5 . V_240 ) ;
V_2 -> V_863 = V_1011 ;
F_12 () ;
F_249 () ;
++ V_2 -> V_60 . V_1015 ;
F_426 () ;
F_427 () ;
F_320 () ;
V_2 -> V_1013 = F_162 ( & V_2 -> V_29 -> V_383 ) ;
if ( F_69 ( V_1016 == V_1017 ) ) {
unsigned long V_972 = F_328 ( V_2 ) ;
F_428 ( V_1017 , ( void * ) V_972 ) ;
}
F_429 ( V_2 ) ;
V_98 = V_56 -> V_1018 ( V_2 ) ;
V_92:
return V_98 ;
}
static int F_430 ( struct V_1 * V_2 )
{
int V_98 ;
struct V_29 * V_29 = V_2 -> V_29 ;
if ( F_69 ( V_2 -> V_5 . V_941 == V_1019 ) ) {
F_89 ( L_28 ,
V_2 -> V_1014 , V_2 -> V_5 . V_614 ) ;
F_431 ( V_2 ) ;
V_98 = F_432 ( V_2 ) ;
if ( V_98 )
return V_98 ;
V_2 -> V_5 . V_941 = V_1020 ;
}
V_2 -> V_1013 = F_162 ( & V_29 -> V_383 ) ;
F_401 ( V_2 ) ;
V_98 = 1 ;
while ( V_98 > 0 ) {
if ( V_2 -> V_5 . V_941 == V_1020 &&
! V_2 -> V_5 . V_6 . V_1004 )
V_98 = F_410 ( V_2 ) ;
else {
F_163 ( & V_29 -> V_383 , V_2 -> V_1013 ) ;
F_433 ( V_2 ) ;
V_2 -> V_1013 = F_162 ( & V_29 -> V_383 ) ;
if ( F_411 ( V_1021 , V_2 ) )
{
switch( V_2 -> V_5 . V_941 ) {
case V_942 :
V_2 -> V_5 . V_941 =
V_1020 ;
case V_1020 :
V_2 -> V_5 . V_6 . V_1004 = false ;
break;
case V_1019 :
default:
V_98 = - V_1022 ;
break;
}
}
}
if ( V_98 <= 0 )
break;
F_434 ( V_1023 , & V_2 -> V_991 ) ;
if ( F_435 ( V_2 ) )
F_436 ( V_2 ) ;
if ( F_396 ( V_2 ) ) {
V_98 = - V_1022 ;
V_2 -> V_793 -> V_794 = V_1024 ;
++ V_2 -> V_60 . V_1025 ;
}
F_437 ( V_2 ) ;
if ( F_420 ( V_1010 ) ) {
V_98 = - V_1022 ;
V_2 -> V_793 -> V_794 = V_1024 ;
++ V_2 -> V_60 . V_1026 ;
}
if ( F_419 () ) {
F_163 ( & V_29 -> V_383 , V_2 -> V_1013 ) ;
F_438 ( V_2 ) ;
V_2 -> V_1013 = F_162 ( & V_29 -> V_383 ) ;
}
}
F_163 ( & V_29 -> V_383 , V_2 -> V_1013 ) ;
F_402 ( V_2 ) ;
return V_98 ;
}
static int F_439 ( struct V_1 * V_2 )
{
struct V_977 * V_793 = V_2 -> V_793 ;
int V_98 ;
if ( ! ( V_2 -> V_5 . V_812 . V_698 || V_2 -> V_792 ) )
return 1 ;
if ( V_2 -> V_792 ) {
V_2 -> V_792 = 0 ;
if ( ! V_2 -> V_799 )
memcpy ( V_2 -> V_787 + V_2 -> V_800 ,
V_793 -> V_790 . V_31 , 8 ) ;
V_2 -> V_800 += 8 ;
if ( V_2 -> V_800 < V_2 -> V_797 ) {
V_793 -> V_794 = V_795 ;
V_793 -> V_790 . V_796 = V_2 -> V_788 + V_2 -> V_800 ;
memcpy ( V_793 -> V_790 . V_31 , V_2 -> V_787 + V_2 -> V_800 , 8 ) ;
V_793 -> V_790 . V_74 = F_193 ( V_2 -> V_797 - V_2 -> V_800 , 8 ) ;
V_793 -> V_790 . V_798 = V_2 -> V_799 ;
V_2 -> V_792 = 1 ;
return 0 ;
}
if ( V_2 -> V_799 )
return 1 ;
V_2 -> V_786 = 1 ;
}
V_2 -> V_1013 = F_162 ( & V_2 -> V_29 -> V_383 ) ;
V_98 = F_440 ( V_2 , V_888 ) ;
F_163 ( & V_2 -> V_29 -> V_383 , V_2 -> V_1013 ) ;
if ( V_98 != V_878 )
return 0 ;
return 1 ;
}
int F_441 ( struct V_1 * V_2 , struct V_977 * V_977 )
{
int V_98 ;
T_14 V_1027 ;
if ( ! F_442 ( V_1010 ) && F_443 ( V_1010 ) )
return - V_297 ;
if ( V_2 -> V_1028 )
F_444 ( V_1029 , & V_2 -> V_1030 , & V_1027 ) ;
if ( F_69 ( V_2 -> V_5 . V_941 == V_1031 ) ) {
F_433 ( V_2 ) ;
F_434 ( V_1021 , & V_2 -> V_991 ) ;
V_98 = - V_1032 ;
goto V_92;
}
if ( ! F_18 ( V_2 -> V_29 ) ) {
if ( F_71 ( V_2 , V_977 -> V_147 ) != 0 ) {
V_98 = - V_456 ;
goto V_92;
}
}
V_98 = F_439 ( V_2 ) ;
if ( V_98 <= 0 )
goto V_92;
if ( V_977 -> V_794 == V_1033 )
F_384 ( V_2 , V_852 ,
V_977 -> V_1034 . V_87 ) ;
V_98 = F_430 ( V_2 ) ;
V_92:
F_399 ( V_2 ) ;
if ( V_2 -> V_1028 )
F_444 ( V_1029 , & V_1027 , NULL ) ;
return V_98 ;
}
int F_445 ( struct V_1 * V_2 , struct V_1035 * V_580 )
{
if ( V_2 -> V_5 . V_901 ) {
struct V_858 * V_859 = & V_2 -> V_5 . V_856 . V_860 ;
memcpy ( V_2 -> V_5 . V_580 , V_859 -> V_580 , sizeof V_859 -> V_580 ) ;
V_2 -> V_5 . V_901 = false ;
}
V_580 -> V_1036 = F_323 ( V_2 , V_852 ) ;
V_580 -> V_1037 = F_323 ( V_2 , V_957 ) ;
V_580 -> V_1038 = F_323 ( V_2 , V_958 ) ;
V_580 -> V_1039 = F_323 ( V_2 , V_956 ) ;
V_580 -> V_1040 = F_323 ( V_2 , V_960 ) ;
V_580 -> V_1041 = F_323 ( V_2 , V_959 ) ;
V_580 -> V_1042 = F_323 ( V_2 , V_853 ) ;
V_580 -> V_1043 = F_323 ( V_2 , V_1044 ) ;
#ifdef F_51
V_580 -> V_1045 = F_323 ( V_2 , V_961 ) ;
V_580 -> V_1046 = F_323 ( V_2 , V_1047 ) ;
V_580 -> V_1048 = F_323 ( V_2 , V_1049 ) ;
V_580 -> V_1050 = F_323 ( V_2 , V_1051 ) ;
V_580 -> V_1052 = F_323 ( V_2 , V_1053 ) ;
V_580 -> V_1054 = F_323 ( V_2 , V_1055 ) ;
V_580 -> V_1056 = F_323 ( V_2 , V_1057 ) ;
V_580 -> V_1058 = F_323 ( V_2 , V_1059 ) ;
#endif
V_580 -> V_972 = F_328 ( V_2 ) ;
V_580 -> V_1060 = F_327 ( V_2 ) ;
return 0 ;
}
int F_446 ( struct V_1 * V_2 , struct V_1035 * V_580 )
{
V_2 -> V_5 . V_871 = true ;
V_2 -> V_5 . V_901 = false ;
F_384 ( V_2 , V_852 , V_580 -> V_1036 ) ;
F_384 ( V_2 , V_957 , V_580 -> V_1037 ) ;
F_384 ( V_2 , V_958 , V_580 -> V_1038 ) ;
F_384 ( V_2 , V_956 , V_580 -> V_1039 ) ;
F_384 ( V_2 , V_960 , V_580 -> V_1040 ) ;
F_384 ( V_2 , V_959 , V_580 -> V_1041 ) ;
F_384 ( V_2 , V_853 , V_580 -> V_1042 ) ;
F_384 ( V_2 , V_1044 , V_580 -> V_1043 ) ;
#ifdef F_51
F_384 ( V_2 , V_961 , V_580 -> V_1045 ) ;
F_384 ( V_2 , V_1047 , V_580 -> V_1046 ) ;
F_384 ( V_2 , V_1049 , V_580 -> V_1048 ) ;
F_384 ( V_2 , V_1051 , V_580 -> V_1050 ) ;
F_384 ( V_2 , V_1053 , V_580 -> V_1052 ) ;
F_384 ( V_2 , V_1055 , V_580 -> V_1054 ) ;
F_384 ( V_2 , V_1057 , V_580 -> V_1056 ) ;
F_384 ( V_2 , V_1059 , V_580 -> V_1058 ) ;
#endif
F_333 ( V_2 , V_580 -> V_972 ) ;
F_334 ( V_2 , V_580 -> V_1060 ) ;
V_2 -> V_5 . V_49 . V_50 = false ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
void F_447 ( struct V_1 * V_2 , int * V_151 , int * V_844 )
{
struct V_769 V_1061 ;
F_260 ( V_2 , & V_1061 , V_1062 ) ;
* V_151 = V_1061 . V_151 ;
* V_844 = V_1061 . V_844 ;
}
int F_448 ( struct V_1 * V_2 ,
struct V_1063 * V_1064 )
{
struct V_828 V_829 ;
F_260 ( V_2 , & V_1064 -> V_1061 , V_1062 ) ;
F_260 ( V_2 , & V_1064 -> V_1065 , V_1066 ) ;
F_260 ( V_2 , & V_1064 -> V_1067 , V_1068 ) ;
F_260 ( V_2 , & V_1064 -> V_1069 , V_1070 ) ;
F_260 ( V_2 , & V_1064 -> V_1071 , V_1072 ) ;
F_260 ( V_2 , & V_1064 -> V_1073 , V_1074 ) ;
F_260 ( V_2 , & V_1064 -> V_1075 , V_1076 ) ;
F_260 ( V_2 , & V_1064 -> V_1077 , V_1078 ) ;
V_56 -> V_831 ( V_2 , & V_829 ) ;
V_1064 -> V_1079 . V_574 = V_829 . V_388 ;
V_1064 -> V_1079 . V_840 = V_829 . V_63 ;
V_56 -> V_830 ( V_2 , & V_829 ) ;
V_1064 -> V_1080 . V_574 = V_829 . V_388 ;
V_1064 -> V_1080 . V_840 = V_829 . V_63 ;
V_1064 -> V_99 = F_50 ( V_2 ) ;
V_1064 -> V_62 = V_2 -> V_5 . V_62 ;
V_1064 -> V_83 = F_48 ( V_2 ) ;
V_1064 -> V_133 = F_65 ( V_2 ) ;
V_1064 -> V_147 = F_73 ( V_2 ) ;
V_1064 -> V_109 = V_2 -> V_5 . V_109 ;
V_1064 -> V_30 = F_17 ( V_2 ) ;
memset ( V_1064 -> V_1081 , 0 , sizeof V_1064 -> V_1081 ) ;
if ( V_2 -> V_5 . V_604 . V_50 && ! V_2 -> V_5 . V_604 . V_605 )
F_449 ( V_2 -> V_5 . V_604 . V_16 ,
( unsigned long * ) V_1064 -> V_1081 ) ;
return 0 ;
}
int F_450 ( struct V_1 * V_2 ,
struct V_1082 * V_941 )
{
V_941 -> V_941 = V_2 -> V_5 . V_941 ;
return 0 ;
}
int F_451 ( struct V_1 * V_2 ,
struct V_1082 * V_941 )
{
V_2 -> V_5 . V_941 = V_941 -> V_941 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
int F_452 ( struct V_1 * V_2 , V_809 V_1083 , int V_1084 ,
bool V_52 , T_1 V_43 )
{
struct V_858 * V_859 = & V_2 -> V_5 . V_856 . V_860 ;
int V_87 ;
F_326 ( V_2 ) ;
V_87 = F_453 ( & V_2 -> V_5 . V_856 ,
V_1083 , V_1084 , V_52 ,
V_43 ) ;
if ( V_87 )
return V_876 ;
memcpy ( V_2 -> V_5 . V_580 , V_859 -> V_580 , sizeof V_859 -> V_580 ) ;
F_333 ( V_2 , V_2 -> V_5 . V_856 . V_862 ) ;
F_334 ( V_2 , V_2 -> V_5 . V_856 . V_861 ) ;
F_23 ( V_48 , V_2 ) ;
return V_878 ;
}
int F_454 ( struct V_1 * V_2 ,
struct V_1063 * V_1064 )
{
int V_1085 = 0 ;
int V_1086 , V_1087 , V_270 ;
struct V_828 V_829 ;
V_829 . V_388 = V_1064 -> V_1079 . V_574 ;
V_829 . V_63 = V_1064 -> V_1079 . V_840 ;
V_56 -> V_833 ( V_2 , & V_829 ) ;
V_829 . V_388 = V_1064 -> V_1080 . V_574 ;
V_829 . V_63 = V_1064 -> V_1080 . V_840 ;
V_56 -> V_832 ( V_2 , & V_829 ) ;
V_2 -> V_5 . V_62 = V_1064 -> V_62 ;
V_1085 |= F_48 ( V_2 ) != V_1064 -> V_83 ;
V_2 -> V_5 . V_83 = V_1064 -> V_83 ;
F_43 ( V_144 , ( V_145 * ) & V_2 -> V_5 . V_95 ) ;
F_71 ( V_2 , V_1064 -> V_147 ) ;
V_1085 |= V_2 -> V_5 . V_109 != V_1064 -> V_109 ;
V_56 -> F_79 ( V_2 , V_1064 -> V_109 ) ;
F_19 ( V_2 , V_1064 -> V_30 ) ;
V_1085 |= F_50 ( V_2 ) != V_1064 -> V_99 ;
V_56 -> V_114 ( V_2 , V_1064 -> V_99 ) ;
V_2 -> V_5 . V_99 = V_1064 -> V_99 ;
V_1085 |= F_65 ( V_2 ) != V_1064 -> V_133 ;
V_56 -> V_141 ( V_2 , V_1064 -> V_133 ) ;
if ( V_1064 -> V_133 & V_132 )
F_62 ( V_2 ) ;
V_270 = F_162 ( & V_2 -> V_29 -> V_383 ) ;
if ( ! F_45 ( V_2 ) && F_46 ( V_2 ) ) {
F_40 ( V_2 , V_2 -> V_5 . V_82 , F_48 ( V_2 ) ) ;
V_1085 = 1 ;
}
F_163 ( & V_2 -> V_29 -> V_383 , V_270 ) ;
if ( V_1085 )
F_54 ( V_2 ) ;
V_1087 = ( sizeof V_1064 -> V_1081 ) << 3 ;
V_1086 = F_455 (
( const unsigned long * ) V_1064 -> V_1081 , V_1087 ) ;
if ( V_1086 < V_1087 ) {
F_199 ( V_2 , V_1086 , false ) ;
F_89 ( L_29 , V_1086 ) ;
}
F_259 ( V_2 , & V_1064 -> V_1061 , V_1062 ) ;
F_259 ( V_2 , & V_1064 -> V_1065 , V_1066 ) ;
F_259 ( V_2 , & V_1064 -> V_1067 , V_1068 ) ;
F_259 ( V_2 , & V_1064 -> V_1069 , V_1070 ) ;
F_259 ( V_2 , & V_1064 -> V_1071 , V_1072 ) ;
F_259 ( V_2 , & V_1064 -> V_1073 , V_1074 ) ;
F_259 ( V_2 , & V_1064 -> V_1075 , V_1076 ) ;
F_259 ( V_2 , & V_1064 -> V_1077 , V_1078 ) ;
F_197 ( V_2 ) ;
if ( F_456 ( V_2 ) && F_328 ( V_2 ) == 0xfff0 &&
V_1064 -> V_1061 . V_834 == 0xf000 && V_1064 -> V_1061 . V_840 == 0xffff0000 &&
! F_329 ( V_2 ) )
V_2 -> V_5 . V_941 = V_1020 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
int F_457 ( struct V_1 * V_2 ,
struct V_1088 * V_1089 )
{
unsigned long V_1060 ;
int V_3 , V_98 ;
if ( V_1089 -> V_705 & ( V_1090 | V_1091 ) ) {
V_98 = - V_1092 ;
if ( V_2 -> V_5 . V_49 . V_50 )
goto V_92;
if ( V_1089 -> V_705 & V_1090 )
F_24 ( V_2 , V_1093 ) ;
else
F_24 ( V_2 , V_1094 ) ;
}
V_1060 = F_327 ( V_2 ) ;
V_2 -> V_152 = V_1089 -> V_705 ;
if ( ! ( V_2 -> V_152 & V_1095 ) )
V_2 -> V_152 = 0 ;
if ( V_2 -> V_152 & V_153 ) {
for ( V_3 = 0 ; V_3 < V_1096 ; ++ V_3 )
V_2 -> V_5 . V_154 [ V_3 ] = V_1089 -> V_5 . V_1097 [ V_3 ] ;
V_2 -> V_5 . V_163 =
( V_1089 -> V_5 . V_1097 [ 7 ] & V_164 ) ;
} else {
for ( V_3 = 0 ; V_3 < V_1096 ; V_3 ++ )
V_2 -> V_5 . V_154 [ V_3 ] = V_2 -> V_5 . V_151 [ V_3 ] ;
V_2 -> V_5 . V_163 = ( V_2 -> V_5 . V_159 & V_164 ) ;
}
if ( V_2 -> V_152 & V_1098 )
V_2 -> V_5 . V_1099 = F_328 ( V_2 ) +
F_287 ( V_2 , V_1062 ) ;
F_334 ( V_2 , V_1060 ) ;
V_56 -> V_1100 ( V_2 , V_1089 ) ;
V_98 = 0 ;
V_92:
return V_98 ;
}
int F_458 ( struct V_1 * V_2 ,
struct V_1101 * V_1075 )
{
unsigned long V_1102 = V_1075 -> V_1103 ;
T_4 V_320 ;
int V_270 ;
V_270 = F_162 ( & V_2 -> V_29 -> V_383 ) ;
V_320 = F_266 ( V_2 , V_1102 , NULL ) ;
F_163 ( & V_2 -> V_29 -> V_383 , V_270 ) ;
V_1075 -> V_1104 = V_320 ;
V_1075 -> V_1105 = V_320 != V_79 ;
V_1075 -> V_1106 = 1 ;
V_1075 -> V_1107 = 0 ;
return 0 ;
}
int F_459 ( struct V_1 * V_2 , struct V_1108 * V_1109 )
{
struct V_631 * V_630 =
& V_2 -> V_5 . V_626 . V_627 -> V_630 ;
memcpy ( V_1109 -> V_1110 , V_630 -> V_1111 , 128 ) ;
V_1109 -> V_1112 = V_630 -> V_1113 ;
V_1109 -> V_1114 = V_630 -> V_1115 ;
V_1109 -> V_1116 = V_630 -> V_1117 ;
V_1109 -> V_1118 = V_630 -> V_1119 ;
V_1109 -> V_1120 = V_630 -> V_972 ;
V_1109 -> V_1121 = V_630 -> V_1122 ;
memcpy ( V_1109 -> V_1123 , V_630 -> V_1124 , sizeof V_630 -> V_1124 ) ;
return 0 ;
}
int F_460 ( struct V_1 * V_2 , struct V_1108 * V_1109 )
{
struct V_631 * V_630 =
& V_2 -> V_5 . V_626 . V_627 -> V_630 ;
memcpy ( V_630 -> V_1111 , V_1109 -> V_1110 , 128 ) ;
V_630 -> V_1113 = V_1109 -> V_1112 ;
V_630 -> V_1115 = V_1109 -> V_1114 ;
V_630 -> V_1117 = V_1109 -> V_1116 ;
V_630 -> V_1119 = V_1109 -> V_1118 ;
V_630 -> V_972 = V_1109 -> V_1120 ;
V_630 -> V_1122 = V_1109 -> V_1121 ;
memcpy ( V_630 -> V_1124 , V_1109 -> V_1123 , sizeof V_630 -> V_1124 ) ;
return 0 ;
}
int F_461 ( struct V_1 * V_2 )
{
int V_55 ;
V_55 = F_462 ( & V_2 -> V_5 . V_626 ) ;
if ( V_55 )
return V_55 ;
F_463 ( & V_2 -> V_5 . V_626 ) ;
V_2 -> V_5 . V_118 = V_120 ;
V_2 -> V_5 . V_99 |= V_106 ;
return 0 ;
}
static void F_464 ( struct V_1 * V_2 )
{
F_465 ( & V_2 -> V_5 . V_626 ) ;
}
void F_317 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1125 )
return;
F_409 ( V_2 ) ;
V_2 -> V_1125 = 1 ;
F_466 ( V_1010 ) ;
F_467 ( & V_2 -> V_5 . V_626 ) ;
F_468 ( 1 ) ;
}
void F_179 ( struct V_1 * V_2 )
{
F_409 ( V_2 ) ;
if ( ! V_2 -> V_1125 )
return;
V_2 -> V_1125 = 0 ;
F_469 ( & V_2 -> V_5 . V_626 ) ;
++ V_2 -> V_60 . V_1126 ;
F_23 ( V_1000 , V_2 ) ;
F_468 ( 0 ) ;
}
void F_470 ( struct V_1 * V_2 )
{
F_143 ( V_2 ) ;
F_471 ( V_2 -> V_5 . V_462 ) ;
F_464 ( V_2 ) ;
V_56 -> V_1127 ( V_2 ) ;
}
struct V_1 * F_472 ( struct V_29 * V_29 ,
unsigned int V_1128 )
{
if ( F_111 () && F_473 ( & V_29 -> V_1129 ) != 0 )
F_104 ( V_210
L_30
L_31 ) ;
return V_56 -> V_1130 ( V_29 , V_1128 ) ;
}
int F_474 ( struct V_1 * V_2 )
{
int V_98 ;
V_2 -> V_5 . V_265 . V_1131 = 1 ;
V_463 ( V_2 ) ;
V_98 = F_432 ( V_2 ) ;
if ( V_98 == 0 )
V_98 = F_475 ( V_2 ) ;
V_465 ( V_2 ) ;
if ( V_98 < 0 )
goto V_1132;
return 0 ;
V_1132:
V_56 -> V_1127 ( V_2 ) ;
return V_98 ;
}
void F_476 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_6 . V_321 = 0 ;
V_463 ( V_2 ) ;
F_412 ( V_2 ) ;
V_465 ( V_2 ) ;
F_464 ( V_2 ) ;
V_56 -> V_1127 ( V_2 ) ;
}
int F_432 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_68 = false ;
V_2 -> V_5 . V_611 = false ;
V_2 -> V_5 . V_163 = 0 ;
memset ( V_2 -> V_5 . V_151 , 0 , sizeof( V_2 -> V_5 . V_151 ) ) ;
V_2 -> V_5 . V_156 = V_158 ;
V_2 -> V_5 . V_159 = V_161 ;
F_23 ( V_48 , V_2 ) ;
V_2 -> V_5 . V_6 . V_321 = 0 ;
F_143 ( V_2 ) ;
F_53 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1004 = false ;
return V_56 -> V_1133 ( V_2 ) ;
}
int F_477 ( void * V_457 )
{
struct V_29 * V_29 ;
struct V_1 * V_2 ;
int V_3 ;
F_13 () ;
F_351 (kvm, &vm_list, vm_list)
F_156 (i, vcpu, kvm)
if ( V_2 -> V_206 == F_352 () )
F_23 ( V_236 , V_2 ) ;
return V_56 -> V_1134 ( V_457 ) ;
}
void F_478 ( void * V_457 )
{
V_56 -> V_1135 ( V_457 ) ;
F_16 ( V_457 ) ;
}
int F_479 ( void )
{
return V_56 -> V_1136 () ;
}
void F_480 ( void )
{
V_56 -> V_1137 () ;
}
void F_481 ( void * V_1138 )
{
V_56 -> V_1139 ( V_1138 ) ;
}
int F_482 ( struct V_1 * V_2 )
{
struct V_295 * V_295 ;
struct V_29 * V_29 ;
int V_98 ;
F_262 ( V_2 -> V_29 == NULL ) ;
V_29 = V_2 -> V_29 ;
V_2 -> V_5 . V_856 . V_931 = & V_875 ;
V_2 -> V_5 . V_82 = & V_2 -> V_5 . V_67 ;
V_2 -> V_5 . V_67 . V_1140 = V_1141 ;
V_2 -> V_5 . V_67 . V_78 = V_78 ;
V_2 -> V_5 . V_65 . V_78 = F_261 ;
if ( ! F_18 ( V_29 ) || F_456 ( V_2 ) )
V_2 -> V_5 . V_941 = V_1020 ;
else
V_2 -> V_5 . V_941 = V_1031 ;
V_295 = F_483 ( V_298 | V_1142 ) ;
if ( ! V_295 ) {
V_98 = - V_297 ;
goto V_1143;
}
V_2 -> V_5 . V_816 = F_484 ( V_295 ) ;
F_106 ( V_2 , V_919 ) ;
V_98 = F_485 ( V_2 ) ;
if ( V_98 < 0 )
goto V_1144;
if ( F_18 ( V_29 ) ) {
V_98 = F_486 ( V_2 ) ;
if ( V_98 < 0 )
goto V_1145;
}
V_2 -> V_5 . V_284 = F_127 ( V_345 * sizeof( T_2 ) * 4 ,
V_298 ) ;
if ( ! V_2 -> V_5 . V_284 ) {
V_98 = - V_297 ;
goto V_1146;
}
V_2 -> V_5 . V_276 = V_345 ;
if ( ! F_487 ( & V_2 -> V_5 . V_462 , V_298 ) )
goto V_1147;
F_1 ( V_2 ) ;
return 0 ;
V_1147:
F_129 ( V_2 -> V_5 . V_284 ) ;
V_1146:
F_488 ( V_2 ) ;
V_1145:
F_489 ( V_2 ) ;
V_1144:
F_490 ( ( unsigned long ) V_2 -> V_5 . V_816 ) ;
V_1143:
return V_98 ;
}
void F_491 ( struct V_1 * V_2 )
{
int V_270 ;
F_129 ( V_2 -> V_5 . V_284 ) ;
F_488 ( V_2 ) ;
V_270 = F_162 ( & V_2 -> V_29 -> V_383 ) ;
F_489 ( V_2 ) ;
F_163 ( & V_2 -> V_29 -> V_383 , V_270 ) ;
F_490 ( ( unsigned long ) V_2 -> V_5 . V_816 ) ;
}
int F_492 ( struct V_29 * V_29 )
{
F_493 ( & V_29 -> V_5 . V_1148 ) ;
F_493 ( & V_29 -> V_5 . V_1149 ) ;
F_449 ( V_745 , & V_29 -> V_5 . V_1150 ) ;
F_494 ( & V_29 -> V_5 . V_224 ) ;
return 0 ;
}
static void F_495 ( struct V_1 * V_2 )
{
V_463 ( V_2 ) ;
F_412 ( V_2 ) ;
V_465 ( V_2 ) ;
}
static void F_496 ( struct V_29 * V_29 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_156 (i, vcpu, kvm) {
F_53 ( V_2 ) ;
F_495 ( V_2 ) ;
}
F_156 (i, vcpu, kvm)
F_470 ( V_2 ) ;
F_150 ( & V_29 -> V_360 ) ;
for ( V_3 = 0 ; V_3 < F_473 ( & V_29 -> V_1129 ) ; V_3 ++ )
V_29 -> V_1151 [ V_3 ] = NULL ;
F_497 ( & V_29 -> V_1129 , 0 ) ;
F_151 ( & V_29 -> V_360 ) ;
}
void F_498 ( struct V_29 * V_29 )
{
F_499 ( V_29 ) ;
F_500 ( V_29 ) ;
}
void F_501 ( struct V_29 * V_29 )
{
F_502 ( V_29 ) ;
F_129 ( V_29 -> V_5 . V_730 ) ;
F_129 ( V_29 -> V_5 . V_1152 ) ;
F_496 ( V_29 ) ;
if ( V_29 -> V_5 . V_1153 )
F_503 ( V_29 -> V_5 . V_1153 ) ;
if ( V_29 -> V_5 . V_1154 )
F_503 ( V_29 -> V_5 . V_1154 ) ;
}
int F_504 ( struct V_29 * V_29 ,
struct V_709 * V_710 ,
struct V_709 V_804 ,
struct V_1155 * V_1156 ,
int V_1157 )
{
int V_1158 = V_710 -> V_1158 ;
int V_1159 = V_1160 | V_1161 ;
if ( V_710 -> V_1128 >= V_429 )
V_1159 = V_1162 | V_1161 ;
if ( ! V_1157 ) {
if ( V_1158 && ! V_804 . V_1163 ) {
unsigned long V_1164 ;
F_505 ( & V_1010 -> V_1165 -> V_1166 ) ;
V_1164 = F_506 ( NULL , 0 ,
V_1158 * V_86 ,
V_1167 | V_1168 ,
V_1159 ,
0 ) ;
F_507 ( & V_1010 -> V_1165 -> V_1166 ) ;
if ( F_508 ( ( void * ) V_1164 ) )
return F_509 ( ( void * ) V_1164 ) ;
V_710 -> V_1164 = V_1164 ;
}
}
return 0 ;
}
void F_510 ( struct V_29 * V_29 ,
struct V_1155 * V_1156 ,
struct V_709 V_804 ,
int V_1157 )
{
int V_1169 = 0 , V_1158 = V_1156 -> V_1170 >> V_85 ;
if ( ! V_1157 && ! V_804 . V_1157 && V_804 . V_1163 && ! V_1158 ) {
int V_87 ;
F_505 ( & V_1010 -> V_1165 -> V_1166 ) ;
V_87 = F_511 ( V_1010 -> V_1165 , V_804 . V_1164 ,
V_804 . V_1158 * V_86 ) ;
F_507 ( & V_1010 -> V_1165 -> V_1166 ) ;
if ( V_87 < 0 )
F_9 ( V_210
L_32
L_33 ) ;
}
if ( ! V_29 -> V_5 . V_681 )
V_1169 = F_512 ( V_29 ) ;
F_218 ( & V_29 -> V_680 ) ;
if ( V_1169 )
F_219 ( V_29 , V_1169 ) ;
F_238 ( V_29 , V_1156 -> V_10 ) ;
F_220 ( & V_29 -> V_680 ) ;
}
void F_513 ( struct V_29 * V_29 )
{
F_389 ( V_29 ) ;
F_514 ( V_29 ) ;
}
int F_515 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_941 == V_1020 &&
! V_2 -> V_5 . V_6 . V_1004 )
|| ! F_516 ( & V_2 -> V_1171 . V_1172 )
|| V_2 -> V_5 . V_941 == V_1019
|| V_2 -> V_5 . V_68 ||
( F_398 ( V_2 ) &&
F_397 ( V_2 ) ) ;
}
void F_517 ( struct V_1 * V_2 )
{
int V_1173 ;
int V_206 = V_2 -> V_206 ;
if ( F_518 ( & V_2 -> V_1174 ) ) {
F_519 ( & V_2 -> V_1174 ) ;
++ V_2 -> V_60 . V_1175 ;
}
V_1173 = F_97 () ;
if ( V_206 != V_1173 && ( unsigned ) V_206 < V_1176 && F_520 ( V_206 ) )
if ( F_521 ( V_2 ) == V_1008 )
F_522 ( V_206 ) ;
F_100 () ;
}
int F_398 ( struct V_1 * V_2 )
{
return V_56 -> V_989 ( V_2 ) ;
}
bool F_523 ( struct V_1 * V_2 , unsigned long V_1177 )
{
unsigned long V_1178 = F_328 ( V_2 ) +
F_287 ( V_2 , V_1062 ) ;
return V_1178 == V_1177 ;
}
unsigned long F_327 ( struct V_1 * V_2 )
{
unsigned long V_1060 ;
V_1060 = V_56 -> V_1179 ( V_2 ) ;
if ( V_2 -> V_152 & V_1098 )
V_1060 &= ~ V_1180 ;
return V_1060 ;
}
void F_334 ( struct V_1 * V_2 , unsigned long V_1060 )
{
if ( V_2 -> V_152 & V_1098 &&
F_523 ( V_2 , V_2 -> V_5 . V_1099 ) )
V_1060 |= V_1180 ;
V_56 -> V_1181 ( V_2 , V_1060 ) ;
F_23 ( V_48 , V_2 ) ;
}
void F_524 ( struct V_1 * V_2 , struct V_1182 * V_1183 )
{
int V_98 ;
if ( ( V_2 -> V_5 . V_67 . V_1184 != V_1183 -> V_5 . V_1184 ) ||
F_148 ( V_1183 -> V_295 ) )
return;
V_98 = F_414 ( V_2 ) ;
if ( F_69 ( V_98 ) )
return;
if ( ! V_2 -> V_5 . V_67 . V_1184 &&
V_1183 -> V_5 . V_83 != V_2 -> V_5 . V_67 . V_1185 ( V_2 ) )
return;
V_2 -> V_5 . V_67 . V_1186 ( V_2 , V_1183 -> V_776 , 0 , true ) ;
}
static inline T_1 F_525 ( T_3 V_81 )
{
return F_526 ( V_81 & 0xffffffff , F_527 ( V_4 ) ) ;
}
static inline T_1 F_528 ( T_1 V_1187 )
{
return ( V_1187 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_529 ( struct V_1 * V_2 , T_3 V_81 )
{
T_1 V_1187 = F_525 ( V_81 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1187 ] != ~ 0 )
V_1187 = F_528 ( V_1187 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1187 ] = V_81 ;
}
static T_1 F_530 ( struct V_1 * V_2 , T_3 V_81 )
{
int V_3 ;
T_1 V_1187 = F_525 ( V_81 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1187 ] != V_81 &&
V_2 -> V_5 . V_6 . V_7 [ V_1187 ] != ~ 0 ) ; V_3 ++ )
V_1187 = F_528 ( V_1187 ) ;
return V_1187 ;
}
bool F_531 ( struct V_1 * V_2 , T_3 V_81 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_530 ( V_2 , V_81 ) ] == V_81 ;
}
static void F_532 ( struct V_1 * V_2 , T_3 V_81 )
{
T_1 V_3 , V_764 , V_1188 ;
V_3 = V_764 = F_530 ( V_2 , V_81 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_764 = F_528 ( V_764 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_764 ] == ~ 0 )
return;
V_1188 = F_525 ( V_2 -> V_5 . V_6 . V_7 [ V_764 ] ) ;
} while ( ( V_3 <= V_764 ) ? ( V_3 < V_1188 && V_1188 <= V_764 ) : ( V_3 < V_1188 || V_1188 <= V_764 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_764 ] ;
V_3 = V_764 ;
}
}
static int F_533 ( struct V_1 * V_2 , T_1 V_150 )
{
return F_534 ( V_2 -> V_29 , & V_2 -> V_5 . V_6 . V_31 , & V_150 ,
sizeof( V_150 ) ) ;
}
void F_535 ( struct V_1 * V_2 ,
struct V_1182 * V_1183 )
{
struct V_58 V_59 ;
F_536 ( V_1183 -> V_5 . V_1189 , V_1183 -> V_776 ) ;
F_529 ( V_2 , V_1183 -> V_5 . V_81 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_321 & V_322 ) ||
( V_2 -> V_5 . V_6 . V_323 &&
V_56 -> V_70 ( V_2 ) == 0 ) )
F_23 ( V_1003 , V_2 ) ;
else if ( ! F_533 ( V_2 , V_1190 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_857 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_1183 -> V_5 . V_1189 ;
F_28 ( V_2 , & V_59 ) ;
}
}
void F_537 ( struct V_1 * V_2 ,
struct V_1182 * V_1183 )
{
struct V_58 V_59 ;
F_538 ( V_1183 -> V_5 . V_1189 , V_1183 -> V_776 ) ;
if ( F_148 ( V_1183 -> V_295 ) )
V_1183 -> V_5 . V_1189 = ~ 0 ;
else
F_532 ( V_2 , V_1183 -> V_5 . V_81 ) ;
if ( ( V_2 -> V_5 . V_6 . V_321 & V_322 ) &&
! F_533 ( V_2 , V_1191 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_857 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_1183 -> V_5 . V_1189 ;
F_28 ( V_2 , & V_59 ) ;
}
V_2 -> V_5 . V_6 . V_1004 = false ;
}
bool F_539 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_321 & V_322 ) )
return true ;
else
return ! F_400 ( V_2 ) &&
V_56 -> V_989 ( V_2 ) ;
}
