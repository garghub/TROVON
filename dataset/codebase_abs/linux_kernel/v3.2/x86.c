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
static bool F_60 ( struct V_1 * V_2 )
{
struct V_126 * V_127 ;
V_127 = F_61 ( V_2 , 1 , 0 ) ;
return V_127 && ( V_127 -> V_128 & F_62 ( V_129 ) ) ;
}
static bool F_63 ( struct V_1 * V_2 )
{
struct V_126 * V_127 ;
V_127 = F_61 ( V_2 , 7 , 0 ) ;
return V_127 && ( V_127 -> V_130 & F_62 ( V_131 ) ) ;
}
static bool F_64 ( struct V_1 * V_2 )
{
struct V_126 * V_127 ;
V_127 = F_61 ( V_2 , 7 , 0 ) ;
return V_127 && ( V_127 -> V_130 & F_62 ( V_132 ) ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_126 * V_127 ;
struct V_133 * V_134 = V_2 -> V_5 . V_134 ;
V_127 = F_61 ( V_2 , 1 , 0 ) ;
if ( ! V_127 )
return;
if ( V_135 && V_127 -> V_136 == 0x1 ) {
V_127 -> V_128 &= ~ ( F_62 ( V_137 ) ) ;
if ( F_66 ( V_2 , V_138 ) )
V_127 -> V_128 |= F_62 ( V_137 ) ;
}
if ( V_134 ) {
if ( V_127 -> V_128 & F_62 ( V_139 ) )
V_134 -> V_140 . V_141 = 3 << 17 ;
else
V_134 -> V_140 . V_141 = 1 << 17 ;
}
}
int F_67 ( struct V_1 * V_2 , unsigned long V_142 )
{
unsigned long V_143 = F_68 ( V_2 ) ;
unsigned long V_144 = V_145 | V_146 |
V_147 | V_148 ;
if ( V_142 & V_149 )
return 1 ;
if ( ! F_60 ( V_2 ) && ( V_142 & V_138 ) )
return 1 ;
if ( ! F_63 ( V_2 ) && ( V_142 & V_148 ) )
return 1 ;
if ( ! F_64 ( V_2 ) && ( V_142 & V_150 ) )
return 1 ;
if ( F_46 ( V_2 ) ) {
if ( ! ( V_142 & V_147 ) )
return 1 ;
} else if ( F_53 ( V_2 ) && ( V_142 & V_147 )
&& ( ( V_142 ^ V_143 ) & V_144 )
&& ! F_41 ( V_2 , V_2 -> V_5 . V_83 ,
F_49 ( V_2 ) ) )
return 1 ;
if ( V_56 -> V_151 ( V_2 , V_142 ) )
return 1 ;
if ( ( V_142 ^ V_143 ) & V_144 )
F_55 ( V_2 ) ;
if ( ( V_142 ^ V_143 ) & V_138 )
F_65 ( V_2 ) ;
return 0 ;
}
int F_69 ( struct V_1 * V_2 , unsigned long V_84 )
{
if ( V_84 == F_49 ( V_2 ) && ! F_45 ( V_2 ) ) {
F_70 ( V_2 ) ;
F_71 ( V_2 ) ;
return 0 ;
}
if ( F_46 ( V_2 ) ) {
if ( V_84 & V_152 )
return 1 ;
} else {
if ( F_47 ( V_2 ) ) {
if ( V_84 & V_153 )
return 1 ;
if ( F_53 ( V_2 ) &&
! F_41 ( V_2 , V_2 -> V_5 . V_83 , V_84 ) )
return 1 ;
}
}
if ( F_72 ( ! F_73 ( V_2 -> V_29 , V_84 >> V_86 ) ) )
return 1 ;
V_2 -> V_5 . V_84 = V_84 ;
F_44 ( V_154 , ( V_155 * ) & V_2 -> V_5 . V_96 ) ;
V_2 -> V_5 . V_67 . V_156 ( V_2 ) ;
return 0 ;
}
int F_74 ( struct V_1 * V_2 , unsigned long V_157 )
{
if ( V_157 & V_158 )
return 1 ;
if ( F_18 ( V_2 -> V_29 ) )
F_75 ( V_2 , V_157 ) ;
else
V_2 -> V_5 . V_157 = V_157 ;
return 0 ;
}
unsigned long F_76 ( struct V_1 * V_2 )
{
if ( F_18 ( V_2 -> V_29 ) )
return F_77 ( V_2 ) ;
else
return V_2 -> V_5 . V_157 ;
}
static int F_78 ( struct V_1 * V_2 , int V_159 , unsigned long V_160 )
{
switch ( V_159 ) {
case 0 ... 3 :
V_2 -> V_5 . V_161 [ V_159 ] = V_160 ;
if ( ! ( V_2 -> V_162 & V_163 ) )
V_2 -> V_5 . V_164 [ V_159 ] = V_160 ;
break;
case 4 :
if ( F_66 ( V_2 , V_165 ) )
return 1 ;
case 6 :
if ( V_160 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_166 = ( V_160 & V_167 ) | V_168 ;
break;
case 5 :
if ( F_66 ( V_2 , V_165 ) )
return 1 ;
default:
if ( V_160 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_169 = ( V_160 & V_170 ) | V_171 ;
if ( ! ( V_2 -> V_162 & V_163 ) ) {
V_56 -> V_172 ( V_2 , V_2 -> V_5 . V_169 ) ;
V_2 -> V_5 . V_173 = ( V_160 & V_174 ) ;
}
break;
}
return 0 ;
}
int F_79 ( struct V_1 * V_2 , int V_159 , unsigned long V_160 )
{
int V_175 ;
V_175 = F_78 ( V_2 , V_159 , V_160 ) ;
if ( V_175 > 0 )
F_24 ( V_2 , V_176 ) ;
else if ( V_175 < 0 )
F_27 ( V_2 , 0 ) ;
return V_175 ;
}
static int F_80 ( struct V_1 * V_2 , int V_159 , unsigned long * V_160 )
{
switch ( V_159 ) {
case 0 ... 3 :
* V_160 = V_2 -> V_5 . V_161 [ V_159 ] ;
break;
case 4 :
if ( F_66 ( V_2 , V_165 ) )
return 1 ;
case 6 :
* V_160 = V_2 -> V_5 . V_166 ;
break;
case 5 :
if ( F_66 ( V_2 , V_165 ) )
return 1 ;
default:
* V_160 = V_2 -> V_5 . V_169 ;
break;
}
return 0 ;
}
int F_81 ( struct V_1 * V_2 , int V_159 , unsigned long * V_160 )
{
if ( F_80 ( V_2 , V_159 , V_160 ) ) {
F_24 ( V_2 , V_176 ) ;
return 1 ;
}
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , T_2 V_110 )
{
T_2 V_177 = V_2 -> V_5 . V_110 ;
if ( V_110 & V_178 )
return 1 ;
if ( F_53 ( V_2 )
&& ( V_2 -> V_5 . V_110 & V_111 ) != ( V_110 & V_111 ) )
return 1 ;
if ( V_110 & V_179 ) {
struct V_126 * V_180 ;
V_180 = F_61 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_180 || ! ( V_180 -> V_181 & F_62 ( V_182 ) ) )
return 1 ;
}
if ( V_110 & V_183 ) {
struct V_126 * V_180 ;
V_180 = F_61 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_180 || ! ( V_180 -> V_128 & F_62 ( V_184 ) ) )
return 1 ;
}
V_110 &= ~ V_185 ;
V_110 |= V_2 -> V_5 . V_110 & V_185 ;
V_56 -> F_82 ( V_2 , V_110 ) ;
V_2 -> V_5 . V_67 . V_186 . V_187 = ( V_110 & V_188 ) && ! V_189 ;
if ( ( V_110 ^ V_177 ) & V_188 )
F_55 ( V_2 ) ;
return 0 ;
}
void F_83 ( T_2 V_26 )
{
V_178 &= ~ V_26 ;
}
int F_84 ( struct V_1 * V_2 , T_1 V_190 , T_2 V_31 )
{
return V_56 -> V_191 ( V_2 , V_190 , V_31 ) ;
}
static int F_85 ( struct V_1 * V_2 , unsigned V_117 , T_2 * V_31 )
{
return F_84 ( V_2 , V_117 , * V_31 ) ;
}
static void F_86 ( struct V_29 * V_29 , T_4 V_192 )
{
int V_193 ;
int V_99 ;
struct V_194 V_195 ;
struct V_196 V_197 ;
if ( ! V_192 )
return;
V_99 = F_87 ( V_29 , V_192 , & V_193 , sizeof( V_193 ) ) ;
if ( V_99 )
return;
if ( V_193 & 1 )
++ V_193 ;
++ V_193 ;
F_88 ( V_29 , V_192 , & V_193 , sizeof( V_193 ) ) ;
F_89 ( & V_197 ) ;
V_195 . V_198 = V_197 . V_199 ;
V_195 . V_200 = V_197 . V_201 ;
V_195 . V_193 = V_193 ;
F_88 ( V_29 , V_192 , & V_195 , sizeof( V_195 ) ) ;
V_193 ++ ;
F_88 ( V_29 , V_192 , & V_193 , sizeof( V_193 ) ) ;
}
static T_5 F_90 ( T_5 V_202 , T_5 V_203 )
{
T_5 V_204 , V_205 ;
__asm__ ( "divl %4"
: "=a" (quotient), "=d" (remainder)
: "0" (0), "1" (dividend), "r" (divisor) );
return V_204 ;
}
static void F_91 ( T_5 V_206 , T_5 V_207 ,
T_6 * V_208 , T_1 * V_209 )
{
T_7 V_210 ;
T_8 V_211 = 0 ;
T_7 V_212 ;
T_5 V_213 ;
V_212 = V_207 * 1000LL ;
V_210 = V_206 * 1000LL ;
while ( V_212 > V_210 * 2 || V_212 & 0xffffffff00000000ULL ) {
V_212 >>= 1 ;
V_211 -- ;
}
V_213 = ( T_5 ) V_212 ;
while ( V_213 <= V_210 || V_210 & 0xffffffff00000000ULL ) {
if ( V_210 & 0xffffffff00000000ULL || V_213 & 0x80000000 )
V_210 >>= 1 ;
else
V_213 <<= 1 ;
V_211 ++ ;
}
* V_208 = V_211 ;
* V_209 = F_90 ( V_210 , V_213 ) ;
F_92 ( L_2 ,
V_214 , V_207 , V_206 , V_211 , * V_209 ) ;
}
static inline T_2 F_93 ( void )
{
struct V_196 V_215 ;
F_94 ( F_95 () ) ;
F_96 ( & V_215 ) ;
F_97 ( & V_215 ) ;
return F_98 ( & V_215 ) ;
}
static inline int F_99 ( void )
{
int V_216 = F_100 () ;
int V_88 = ! F_101 ( V_217 ) &&
F_102 ( V_216 ) != 0 ;
F_103 () ;
return V_88 ;
}
T_2 F_104 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_218 )
return V_2 -> V_5 . V_218 ;
else
return F_105 ( V_219 ) ;
}
static inline T_2 F_106 ( struct V_1 * V_2 , T_2 V_200 )
{
T_2 V_88 ;
F_94 ( F_95 () ) ;
if ( F_99 () )
F_107 ( V_220
L_3 ) ;
V_88 = V_200 * F_104 ( V_2 ) ;
F_108 ( V_88 , V_221 ) ;
return V_88 ;
}
static void F_109 ( struct V_1 * V_2 , T_1 V_222 )
{
F_91 ( V_222 , V_223 / 1000 ,
& V_2 -> V_5 . V_224 ,
& V_2 -> V_5 . V_225 ) ;
}
static T_2 F_110 ( struct V_1 * V_2 , T_9 V_226 )
{
T_2 V_227 = F_111 ( V_226 - V_2 -> V_5 . V_228 ,
V_2 -> V_5 . V_225 ,
V_2 -> V_5 . V_224 ) ;
V_227 += V_2 -> V_5 . V_229 ;
return V_227 ;
}
void F_112 ( struct V_1 * V_2 , T_2 V_31 )
{
struct V_29 * V_29 = V_2 -> V_29 ;
T_2 V_74 , V_230 , V_231 ;
unsigned long V_232 ;
T_9 V_233 ;
F_113 ( & V_29 -> V_5 . V_234 , V_232 ) ;
V_74 = V_56 -> V_235 ( V_2 , V_31 ) ;
V_230 = F_93 () ;
V_231 = V_230 - V_29 -> V_5 . V_228 ;
V_233 = V_31 - V_29 -> V_5 . V_229 ;
if ( V_233 < 0 )
V_233 = - V_233 ;
if ( V_233 < F_106 ( V_2 , 5ULL * V_223 ) &&
V_231 < 5ULL * V_223 ) {
if ( ! F_114 () ) {
V_74 = V_29 -> V_5 . V_236 ;
F_92 ( L_4 , V_31 ) ;
} else {
T_2 V_237 = F_106 ( V_2 , V_231 ) ;
V_74 += V_237 ;
F_92 ( L_5 , V_237 ) ;
}
V_230 = V_29 -> V_5 . V_228 ;
}
V_29 -> V_5 . V_228 = V_230 ;
V_29 -> V_5 . V_229 = V_31 ;
V_29 -> V_5 . V_236 = V_74 ;
V_56 -> V_238 ( V_2 , V_74 ) ;
F_115 ( & V_29 -> V_5 . V_234 , V_232 ) ;
V_2 -> V_5 . V_239 . V_240 = 0 ;
V_2 -> V_5 . V_229 = V_31 ;
V_2 -> V_5 . V_228 = V_230 ;
}
static int F_116 ( struct V_1 * V_241 )
{
unsigned long V_232 ;
struct V_242 * V_2 = & V_241 -> V_5 ;
void * V_243 ;
unsigned long V_222 ;
T_9 V_226 , V_244 ;
T_2 V_240 ;
F_117 ( V_232 ) ;
V_240 = V_56 -> V_245 ( V_241 ) ;
V_226 = F_93 () ;
V_222 = F_104 ( V_241 ) ;
if ( F_72 ( V_222 == 0 ) ) {
F_118 ( V_232 ) ;
F_23 ( V_246 , V_241 ) ;
return 1 ;
}
if ( V_2 -> V_247 ) {
T_2 V_227 = F_110 ( V_241 , V_226 ) ;
if ( V_227 > V_240 ) {
V_56 -> V_248 ( V_241 , V_227 - V_240 ) ;
V_240 = V_227 ;
}
}
F_118 ( V_232 ) ;
if ( ! V_2 -> V_249 )
return 0 ;
V_244 = 0 ;
if ( V_2 -> V_239 . V_240 && V_2 -> V_250 ) {
V_244 = V_2 -> V_250 -
V_2 -> V_239 . V_240 ;
V_244 = F_111 ( V_244 ,
V_2 -> V_239 . V_251 ,
V_2 -> V_239 . V_252 ) ;
V_244 += V_2 -> V_253 ;
}
if ( F_72 ( V_2 -> V_254 != V_222 ) ) {
F_91 ( V_223 / 1000 , V_222 ,
& V_2 -> V_239 . V_252 ,
& V_2 -> V_239 . V_251 ) ;
V_2 -> V_254 = V_222 ;
}
if ( V_244 > V_226 )
V_226 = V_244 ;
V_2 -> V_239 . V_240 = V_240 ;
V_2 -> V_239 . V_255 = V_226 + V_241 -> V_29 -> V_5 . V_256 ;
V_2 -> V_253 = V_226 ;
V_2 -> V_250 = V_240 ;
V_2 -> V_239 . V_232 = 0 ;
V_2 -> V_239 . V_193 += 2 ;
V_243 = F_119 ( V_2 -> V_249 , V_257 ) ;
memcpy ( V_243 + V_2 -> V_258 , & V_2 -> V_239 ,
sizeof( V_2 -> V_239 ) ) ;
F_120 ( V_243 , V_257 ) ;
F_121 ( V_241 -> V_29 , V_2 -> time >> V_86 ) ;
return 0 ;
}
static bool F_122 ( unsigned V_21 )
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
static bool F_123 ( unsigned V_273 )
{
return V_273 < 8 && ( 1 << V_273 ) & 0xf3 ;
}
static bool F_124 ( unsigned V_273 )
{
return V_273 < 8 && ( 1 << V_273 ) & 0x73 ;
}
static bool F_125 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
int V_3 ;
if ( ! F_122 ( V_21 ) )
return false ;
if ( V_21 == V_272 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_123 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
} else if ( V_21 == V_271 ) {
if ( V_31 & ~ 0xcff )
return false ;
return F_124 ( V_31 & 0xff ) ;
} else if ( V_21 >= V_260 && V_21 <= V_270 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_124 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
}
return F_124 ( V_31 & 0xff ) ;
}
static int F_126 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
T_2 * V_274 = ( T_2 * ) & V_2 -> V_5 . V_275 . V_276 ;
if ( ! F_125 ( V_2 , V_21 , V_31 ) )
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
static int F_127 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
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
static int F_128 ( struct V_1 * V_2 , T_2 V_31 )
{
struct V_29 * V_29 = V_2 -> V_29 ;
int V_295 = F_46 ( V_2 ) ;
T_10 * V_296 = V_295 ? ( T_10 * ) ( long ) V_29 -> V_5 . F_128 . V_297
: ( T_10 * ) ( long ) V_29 -> V_5 . F_128 . V_298 ;
T_10 V_299 = V_295 ? V_29 -> V_5 . F_128 . V_300
: V_29 -> V_5 . F_128 . V_301 ;
T_1 V_302 = V_31 & ~ V_303 ;
T_2 V_304 = V_31 & V_303 ;
T_10 * V_305 ;
int V_99 ;
V_99 = - V_306 ;
if ( V_302 >= V_299 )
goto V_93;
V_99 = - V_307 ;
V_305 = F_129 ( V_87 , V_308 ) ;
if ( ! V_305 )
goto V_93;
V_99 = - V_81 ;
if ( F_130 ( V_305 , V_296 + ( V_302 * V_87 ) , V_87 ) )
goto V_309;
if ( F_88 ( V_29 , V_304 , V_305 , V_87 ) )
goto V_309;
V_99 = 0 ;
V_309:
F_131 ( V_305 ) ;
V_93:
return V_99 ;
}
static bool F_132 ( struct V_29 * V_29 )
{
return V_29 -> V_5 . V_310 & V_311 ;
}
static bool F_133 ( T_1 V_21 )
{
bool V_99 = false ;
switch ( V_21 ) {
case V_312 :
case V_313 :
V_99 = true ;
break;
}
return V_99 ;
}
static int F_134 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
struct V_29 * V_29 = V_2 -> V_29 ;
switch ( V_21 ) {
case V_312 :
V_29 -> V_5 . V_314 = V_31 ;
if ( ! V_29 -> V_5 . V_314 )
V_29 -> V_5 . V_310 &= ~ V_311 ;
break;
case V_313 : {
T_2 V_82 ;
unsigned long V_315 ;
T_10 V_316 [ 4 ] ;
if ( ! V_29 -> V_5 . V_314 )
break;
if ( ! ( V_31 & V_311 ) ) {
V_29 -> V_5 . V_310 = V_31 ;
break;
}
V_82 = V_31 >> V_317 ;
V_315 = F_135 ( V_29 , V_82 ) ;
if ( F_136 ( V_315 ) )
return 1 ;
V_56 -> V_318 ( V_2 , V_316 ) ;
( ( unsigned char * ) V_316 ) [ 3 ] = 0xc3 ;
if ( F_137 ( ( void V_319 * ) V_315 , V_316 , 4 ) )
return 1 ;
V_29 -> V_5 . V_310 = V_31 ;
break;
}
default:
F_138 ( V_2 , L_6
L_7 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_139 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
switch ( V_21 ) {
case V_320 : {
unsigned long V_315 ;
if ( ! ( V_31 & V_321 ) ) {
V_2 -> V_5 . V_322 = V_31 ;
break;
}
V_315 = F_135 ( V_2 -> V_29 , V_31 >>
V_323 ) ;
if ( F_136 ( V_315 ) )
return 1 ;
if ( F_140 ( ( void V_319 * ) V_315 , V_87 ) )
return 1 ;
V_2 -> V_5 . V_322 = V_31 ;
break;
}
case V_324 :
return F_141 ( V_2 , V_325 , V_31 ) ;
case V_326 :
return F_141 ( V_2 , V_327 , V_31 ) ;
case V_328 :
return F_141 ( V_2 , V_329 , V_31 ) ;
default:
F_138 ( V_2 , L_6
L_7 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_142 ( struct V_1 * V_2 , T_2 V_31 )
{
T_4 V_330 = V_31 & ~ 0x3f ;
if ( V_31 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_331 = V_31 ;
if ( ! ( V_31 & V_332 ) ) {
F_54 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_143 ( V_2 -> V_29 , & V_2 -> V_5 . V_6 . V_31 , V_330 ) )
return 1 ;
V_2 -> V_5 . V_6 . V_333 = ! ( V_31 & V_334 ) ;
F_144 ( V_2 ) ;
return 0 ;
}
static void F_145 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_249 ) {
F_146 ( V_2 -> V_5 . V_249 ) ;
V_2 -> V_5 . V_249 = NULL ;
}
}
static void F_147 ( struct V_1 * V_2 )
{
T_2 V_237 ;
if ( ! ( V_2 -> V_5 . V_335 . V_331 & V_336 ) )
return;
V_237 = V_337 -> V_338 . V_339 - V_2 -> V_5 . V_335 . V_340 ;
V_2 -> V_5 . V_335 . V_340 = V_337 -> V_338 . V_339 ;
V_2 -> V_5 . V_335 . V_341 = V_237 ;
}
static void F_148 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_335 . V_331 & V_336 ) )
return;
if ( F_72 ( F_149 ( V_2 -> V_29 , & V_2 -> V_5 . V_335 . V_342 ,
& V_2 -> V_5 . V_335 . V_343 , sizeof( struct V_344 ) ) ) )
return;
V_2 -> V_5 . V_335 . V_343 . V_343 += V_2 -> V_5 . V_335 . V_341 ;
V_2 -> V_5 . V_335 . V_343 . V_193 += 2 ;
V_2 -> V_5 . V_335 . V_341 = 0 ;
F_150 ( V_2 -> V_29 , & V_2 -> V_5 . V_335 . V_342 ,
& V_2 -> V_5 . V_335 . V_343 , sizeof( struct V_344 ) ) ;
}
int F_151 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
switch ( V_21 ) {
case V_345 :
return F_82 ( V_2 , V_31 ) ;
case V_346 :
V_31 &= ~ ( T_2 ) 0x40 ;
V_31 &= ~ ( T_2 ) 0x100 ;
if ( V_31 != 0 ) {
F_138 ( V_2 , L_8 ,
V_31 ) ;
return 1 ;
}
break;
case V_347 :
if ( V_31 != 0 ) {
F_138 ( V_2 , L_9
L_10 , V_31 ) ;
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
F_138 ( V_2 , L_11 ,
V_214 , V_31 ) ;
break;
case V_352 :
case V_353 :
case V_354 :
case V_355 :
break;
case 0x200 ... 0x2ff :
return F_126 ( V_2 , V_21 , V_31 ) ;
case V_356 :
F_19 ( V_2 , V_31 ) ;
break;
case V_357 ... V_357 + 0x3ff :
return F_152 ( V_2 , V_21 , V_31 ) ;
case V_358 :
F_153 ( V_2 , V_31 ) ;
break;
case V_359 :
V_2 -> V_5 . V_360 = V_31 ;
break;
case V_361 :
case V_362 :
V_2 -> V_29 -> V_5 . V_192 = V_31 ;
F_86 ( V_2 -> V_29 , V_31 ) ;
break;
case V_363 :
case V_364 : {
F_145 ( V_2 ) ;
V_2 -> V_5 . time = V_31 ;
F_23 ( V_246 , V_2 ) ;
if ( ! ( V_31 & 1 ) )
break;
V_2 -> V_5 . V_258 = V_31 & ~ ( V_303 | 1 ) ;
V_2 -> V_5 . V_249 =
F_154 ( V_2 -> V_29 , V_31 >> V_86 ) ;
if ( F_155 ( V_2 -> V_5 . V_249 ) ) {
F_156 ( V_2 -> V_5 . V_249 ) ;
V_2 -> V_5 . V_249 = NULL ;
}
break;
}
case V_365 :
if ( F_142 ( V_2 , V_31 ) )
return 1 ;
break;
case V_366 :
if ( F_72 ( ! F_157 () ) )
return 1 ;
if ( V_31 & V_367 )
return 1 ;
if ( F_143 ( V_2 -> V_29 , & V_2 -> V_5 . V_335 . V_342 ,
V_31 & V_368 ) )
return 1 ;
V_2 -> V_5 . V_335 . V_331 = V_31 ;
if ( ! ( V_31 & V_336 ) )
break;
V_2 -> V_5 . V_335 . V_340 = V_337 -> V_338 . V_339 ;
F_158 () ;
F_147 ( V_2 ) ;
F_159 () ;
F_23 ( V_369 , V_2 ) ;
break;
case V_290 :
case V_288 :
case V_293 ... V_293 + 4 * V_370 - 1 :
return F_127 ( V_2 , V_21 , V_31 ) ;
case V_371 :
case V_372 :
case V_373 :
case V_374 :
case V_375 :
case V_376 :
if ( V_31 != 0 )
F_138 ( V_2 , L_12
L_13 , V_21 , V_31 ) ;
break;
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
F_138 ( V_2 , L_12
L_13 , V_21 , V_31 ) ;
break;
case V_383 :
break;
case V_312 ... V_384 :
if ( F_133 ( V_21 ) ) {
int V_99 ;
F_160 ( & V_2 -> V_29 -> V_385 ) ;
V_99 = F_134 ( V_2 , V_21 , V_31 ) ;
F_161 ( & V_2 -> V_29 -> V_385 ) ;
return V_99 ;
} else
return F_139 ( V_2 , V_21 , V_31 ) ;
break;
case V_386 :
F_138 ( V_2 , L_14 , V_21 , V_31 ) ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_29 -> V_5 . F_128 . V_21 ) )
return F_128 ( V_2 , V_31 ) ;
if ( ! V_387 ) {
F_138 ( V_2 , L_15 ,
V_21 , V_31 ) ;
return 1 ;
} else {
F_138 ( V_2 , L_14 ,
V_21 , V_31 ) ;
break;
}
}
return 0 ;
}
int F_162 ( struct V_1 * V_2 , T_1 V_190 , T_2 * V_388 )
{
return V_56 -> V_389 ( V_2 , V_190 , V_388 ) ;
}
static int F_163 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_388 )
{
T_2 * V_274 = ( T_2 * ) & V_2 -> V_5 . V_275 . V_276 ;
if ( ! F_122 ( V_21 ) )
return 1 ;
if ( V_21 == V_271 )
* V_388 = V_2 -> V_5 . V_275 . V_277 +
( V_2 -> V_5 . V_275 . V_278 << 10 ) ;
else if ( V_21 == V_260 )
* V_388 = V_274 [ 0 ] ;
else if ( V_21 == V_261 || V_21 == V_262 )
* V_388 = V_274 [ 1 + V_21 - V_261 ] ;
else if ( V_21 >= V_263 && V_21 <= V_270 )
* V_388 = V_274 [ 3 + V_21 - V_263 ] ;
else if ( V_21 == V_272 )
* V_388 = V_2 -> V_5 . V_279 ;
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
* V_388 = * V_282 ;
}
return 0 ;
}
static int F_164 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_388 )
{
T_2 V_31 ;
T_2 V_286 = V_2 -> V_5 . V_286 ;
unsigned V_287 = V_286 & 0xff ;
switch ( V_21 ) {
case V_390 :
case V_391 :
V_31 = 0 ;
break;
case V_392 :
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
* V_388 = V_31 ;
return 0 ;
}
static int F_165 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_388 )
{
T_2 V_31 = 0 ;
struct V_29 * V_29 = V_2 -> V_29 ;
switch ( V_21 ) {
case V_312 :
V_31 = V_29 -> V_5 . V_314 ;
break;
case V_313 :
V_31 = V_29 -> V_5 . V_310 ;
break;
default:
F_138 ( V_2 , L_16 , V_21 ) ;
return 1 ;
}
* V_388 = V_31 ;
return 0 ;
}
static int F_166 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_388 )
{
T_2 V_31 = 0 ;
switch ( V_21 ) {
case V_393 : {
int V_99 ;
struct V_1 * V_241 ;
F_167 (r, v, vcpu->kvm)
if ( V_241 == V_2 )
V_31 = V_99 ;
break;
}
case V_324 :
return F_168 ( V_2 , V_325 , V_388 ) ;
case V_326 :
return F_168 ( V_2 , V_327 , V_388 ) ;
case V_328 :
return F_168 ( V_2 , V_329 , V_388 ) ;
case V_320 :
V_31 = V_2 -> V_5 . V_322 ;
break;
default:
F_138 ( V_2 , L_16 , V_21 ) ;
return 1 ;
}
* V_388 = V_31 ;
return 0 ;
}
int F_169 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_388 )
{
T_2 V_31 ;
switch ( V_21 ) {
case V_394 :
case V_395 :
case V_349 :
case V_396 :
case V_397 :
case V_398 :
case V_399 :
case V_400 :
case V_346 :
case V_354 :
case V_377 :
case V_378 :
case V_371 :
case V_372 :
case V_373 :
case V_379 :
case V_401 :
case V_348 :
case V_347 :
V_31 = 0 ;
break;
case V_352 :
V_31 = 0x100000000ULL ;
break;
case V_402 :
V_31 = 0x500 | V_259 ;
break;
case 0x200 ... 0x2ff :
return F_163 ( V_2 , V_21 , V_388 ) ;
case 0xcd :
V_31 = 3 ;
break;
case V_403 :
V_31 = 1 << 24 ;
break;
case V_356 :
V_31 = F_17 ( V_2 ) ;
break;
case V_357 ... V_357 + 0x3ff :
return F_170 ( V_2 , V_21 , V_388 ) ;
break;
case V_358 :
V_31 = F_171 ( V_2 ) ;
break;
case V_359 :
V_31 = V_2 -> V_5 . V_360 ;
break;
case V_404 :
V_31 = 1000ULL ;
V_31 |= ( ( ( T_7 ) 4ULL ) << 40 ) ;
break;
case V_345 :
V_31 = V_2 -> V_5 . V_110 ;
break;
case V_362 :
case V_361 :
V_31 = V_2 -> V_29 -> V_5 . V_192 ;
break;
case V_364 :
case V_363 :
V_31 = V_2 -> V_5 . time ;
break;
case V_365 :
V_31 = V_2 -> V_5 . V_6 . V_331 ;
break;
case V_366 :
V_31 = V_2 -> V_5 . V_335 . V_331 ;
break;
case V_390 :
case V_391 :
case V_392 :
case V_290 :
case V_288 :
case V_293 ... V_293 + 4 * V_370 - 1 :
return F_164 ( V_2 , V_21 , V_388 ) ;
case V_383 :
V_31 = 0x20000000 ;
break;
case V_312 ... V_384 :
if ( F_133 ( V_21 ) ) {
int V_99 ;
F_160 ( & V_2 -> V_29 -> V_385 ) ;
V_99 = F_165 ( V_2 , V_21 , V_388 ) ;
F_161 ( & V_2 -> V_29 -> V_385 ) ;
return V_99 ;
} else
return F_166 ( V_2 , V_21 , V_388 ) ;
break;
case V_386 :
V_31 = 0xbe702111 ;
break;
default:
if ( ! V_387 ) {
F_138 ( V_2 , L_17 , V_21 ) ;
return 1 ;
} else {
F_138 ( V_2 , L_18 , V_21 ) ;
V_31 = 0 ;
}
break;
}
* V_388 = V_31 ;
return 0 ;
}
static int F_172 ( struct V_1 * V_2 , struct V_405 * V_19 ,
struct V_406 * V_407 ,
int (* F_173)( struct V_1 * V_2 ,
unsigned V_117 , T_2 * V_31 ) )
{
int V_3 , V_280 ;
V_280 = F_174 ( & V_2 -> V_29 -> V_408 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_409 ; ++ V_3 )
if ( F_173 ( V_2 , V_407 [ V_3 ] . V_117 , & V_407 [ V_3 ] . V_31 ) )
break;
F_175 ( & V_2 -> V_29 -> V_408 , V_280 ) ;
return V_3 ;
}
static int F_176 ( struct V_1 * V_2 , struct V_405 V_319 * V_410 ,
int (* F_173)( struct V_1 * V_2 ,
unsigned V_117 , T_2 * V_31 ) ,
int V_411 )
{
struct V_405 V_19 ;
struct V_406 * V_407 ;
int V_99 , V_412 ;
unsigned V_413 ;
V_99 = - V_81 ;
if ( F_130 ( & V_19 , V_410 , sizeof V_19 ) )
goto V_93;
V_99 = - V_306 ;
if ( V_19 . V_409 >= V_414 )
goto V_93;
V_99 = - V_307 ;
V_413 = sizeof( struct V_406 ) * V_19 . V_409 ;
V_407 = F_177 ( V_413 , V_308 ) ;
if ( ! V_407 )
goto V_93;
V_99 = - V_81 ;
if ( F_130 ( V_407 , V_410 -> V_407 , V_413 ) )
goto V_309;
V_99 = V_412 = F_172 ( V_2 , & V_19 , V_407 , F_173 ) ;
if ( V_99 < 0 )
goto V_309;
V_99 = - V_81 ;
if ( V_411 && F_178 ( V_410 -> V_407 , V_407 , V_413 ) )
goto V_309;
V_99 = V_412 ;
V_309:
F_131 ( V_407 ) ;
V_93:
return V_99 ;
}
int F_179 ( long V_415 )
{
int V_99 ;
switch ( V_415 ) {
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
V_99 = 1 ;
break;
case V_447 :
V_99 = V_448 ;
break;
case V_449 :
V_99 = ! V_56 -> V_450 () ;
break;
case V_451 :
V_99 = V_452 ;
break;
case V_453 :
V_99 = V_454 ;
break;
case V_455 :
V_99 = V_456 ;
break;
case V_457 :
V_99 = 0 ;
break;
case V_458 :
V_99 = F_180 ( & V_459 ) ;
break;
case V_460 :
V_99 = V_370 ;
break;
case V_461 :
V_99 = V_135 ;
break;
case V_462 :
V_99 = V_463 ;
break;
case V_464 :
V_99 = F_101 ( V_139 ) ;
break;
default:
V_99 = 0 ;
break;
}
return V_99 ;
}
long F_181 ( struct V_465 * V_466 ,
unsigned int V_467 , unsigned long V_468 )
{
void V_319 * V_469 = ( void V_319 * ) V_468 ;
long V_99 ;
switch ( V_467 ) {
case V_470 : {
struct V_471 V_319 * V_472 = V_469 ;
struct V_471 V_473 ;
unsigned V_412 ;
V_99 = - V_81 ;
if ( F_130 ( & V_473 , V_472 , sizeof V_473 ) )
goto V_93;
V_412 = V_473 . V_409 ;
V_473 . V_409 = V_474 + F_42 ( V_475 ) ;
if ( F_178 ( V_472 , & V_473 , sizeof V_473 ) )
goto V_93;
V_99 = - V_306 ;
if ( V_412 < V_473 . V_409 )
goto V_93;
V_99 = - V_81 ;
if ( F_178 ( V_472 -> V_476 , & V_477 ,
V_474 * sizeof( T_1 ) ) )
goto V_93;
if ( F_178 ( V_472 -> V_476 + V_474 ,
& V_475 ,
F_42 ( V_475 ) * sizeof( T_1 ) ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_478 : {
struct V_479 V_319 * V_480 = V_469 ;
struct V_479 V_481 ;
V_99 = - V_81 ;
if ( F_130 ( & V_481 , V_480 , sizeof V_481 ) )
goto V_93;
V_99 = F_182 ( & V_481 ,
V_480 -> V_407 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_178 ( V_480 , & V_481 , sizeof V_481 ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_482 : {
T_2 V_483 ;
V_483 = V_484 ;
V_99 = - V_81 ;
if ( F_178 ( V_469 , & V_483 , sizeof V_483 ) )
goto V_93;
V_99 = 0 ;
break;
}
default:
V_99 = - V_485 ;
}
V_93:
return V_99 ;
}
static void F_183 ( void * V_486 )
{
F_184 () ;
}
static bool F_185 ( struct V_1 * V_2 )
{
return V_2 -> V_29 -> V_5 . V_487 &&
! ( V_2 -> V_29 -> V_5 . V_488 & V_489 ) ;
}
void F_186 ( struct V_1 * V_2 , int V_216 )
{
if ( F_185 ( V_2 ) ) {
if ( V_56 -> V_490 () )
F_187 ( V_216 , V_2 -> V_5 . V_491 ) ;
else if ( V_2 -> V_216 != - 1 && V_2 -> V_216 != V_216 )
F_188 ( V_2 -> V_216 ,
F_183 , NULL , 1 ) ;
}
V_56 -> V_492 ( V_2 , V_216 ) ;
if ( F_72 ( V_2 -> V_216 != V_216 ) || F_114 () ) {
T_9 V_493 ;
T_2 V_227 ;
V_227 = V_56 -> V_245 ( V_2 ) ;
V_493 = ! V_2 -> V_5 . V_250 ? 0 :
V_227 - V_2 -> V_5 . V_250 ;
if ( V_493 < 0 )
F_189 ( L_19 ) ;
if ( F_114 () ) {
V_56 -> V_248 ( V_2 , - V_493 ) ;
V_2 -> V_5 . V_247 = 1 ;
}
F_23 ( V_246 , V_2 ) ;
if ( V_2 -> V_216 != V_216 )
F_190 ( V_2 ) ;
V_2 -> V_216 = V_216 ;
}
F_147 ( V_2 ) ;
F_23 ( V_369 , V_2 ) ;
}
void F_191 ( struct V_1 * V_2 )
{
V_56 -> V_494 ( V_2 ) ;
F_192 ( V_2 ) ;
V_2 -> V_5 . V_250 = V_56 -> V_245 ( V_2 ) ;
}
static int F_193 ( void )
{
unsigned long long V_110 = 0 ;
F_10 ( V_345 , & V_110 ) ;
return V_110 & V_188 ;
}
static void F_194 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_126 * V_495 , * V_496 ;
V_496 = NULL ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 . V_497 ; ++ V_3 ) {
V_495 = & V_2 -> V_5 . V_498 [ V_3 ] ;
if ( V_495 -> V_136 == 0x80000001 ) {
V_496 = V_495 ;
break;
}
}
if ( V_496 && ( V_496 -> V_181 & ( 1 << 20 ) ) && ! F_193 () ) {
V_496 -> V_181 &= ~ ( 1 << 20 ) ;
F_9 ( V_499 L_20 ) ;
}
}
static int F_195 ( struct V_1 * V_2 ,
struct V_500 * V_481 ,
struct V_501 V_319 * V_407 )
{
int V_99 , V_3 ;
struct V_501 * V_498 ;
V_99 = - V_306 ;
if ( V_481 -> V_502 > V_503 )
goto V_93;
V_99 = - V_307 ;
V_498 = F_196 ( sizeof( struct V_501 ) * V_481 -> V_502 ) ;
if ( ! V_498 )
goto V_93;
V_99 = - V_81 ;
if ( F_130 ( V_498 , V_407 ,
V_481 -> V_502 * sizeof( struct V_501 ) ) )
goto V_309;
for ( V_3 = 0 ; V_3 < V_481 -> V_502 ; V_3 ++ ) {
V_2 -> V_5 . V_498 [ V_3 ] . V_136 = V_498 [ V_3 ] . V_136 ;
V_2 -> V_5 . V_498 [ V_3 ] . V_504 = V_498 [ V_3 ] . V_504 ;
V_2 -> V_5 . V_498 [ V_3 ] . V_130 = V_498 [ V_3 ] . V_130 ;
V_2 -> V_5 . V_498 [ V_3 ] . V_128 = V_498 [ V_3 ] . V_128 ;
V_2 -> V_5 . V_498 [ V_3 ] . V_181 = V_498 [ V_3 ] . V_181 ;
V_2 -> V_5 . V_498 [ V_3 ] . V_117 = 0 ;
V_2 -> V_5 . V_498 [ V_3 ] . V_232 = 0 ;
V_2 -> V_5 . V_498 [ V_3 ] . V_505 [ 0 ] = 0 ;
V_2 -> V_5 . V_498 [ V_3 ] . V_505 [ 1 ] = 0 ;
V_2 -> V_5 . V_498 [ V_3 ] . V_505 [ 2 ] = 0 ;
}
V_2 -> V_5 . V_497 = V_481 -> V_502 ;
F_194 ( V_2 ) ;
V_99 = 0 ;
F_197 ( V_2 ) ;
V_56 -> V_506 ( V_2 ) ;
F_65 ( V_2 ) ;
V_309:
F_198 ( V_498 ) ;
V_93:
return V_99 ;
}
static int F_199 ( struct V_1 * V_2 ,
struct V_479 * V_481 ,
struct V_126 V_319 * V_407 )
{
int V_99 ;
V_99 = - V_306 ;
if ( V_481 -> V_502 > V_503 )
goto V_93;
V_99 = - V_81 ;
if ( F_130 ( & V_2 -> V_5 . V_498 , V_407 ,
V_481 -> V_502 * sizeof( struct V_126 ) ) )
goto V_93;
V_2 -> V_5 . V_497 = V_481 -> V_502 ;
F_197 ( V_2 ) ;
V_56 -> V_506 ( V_2 ) ;
F_65 ( V_2 ) ;
return 0 ;
V_93:
return V_99 ;
}
static int F_200 ( struct V_1 * V_2 ,
struct V_479 * V_481 ,
struct V_126 V_319 * V_407 )
{
int V_99 ;
V_99 = - V_306 ;
if ( V_481 -> V_502 < V_2 -> V_5 . V_497 )
goto V_93;
V_99 = - V_81 ;
if ( F_178 ( V_407 , & V_2 -> V_5 . V_498 ,
V_2 -> V_5 . V_497 * sizeof( struct V_126 ) ) )
goto V_93;
return 0 ;
V_93:
V_481 -> V_502 = V_2 -> V_5 . V_497 ;
return V_99 ;
}
static void F_201 ( T_1 * V_507 , int V_508 )
{
* V_507 &= V_509 . V_510 [ V_508 ] ;
}
static void F_202 ( struct V_126 * V_496 , T_1 V_136 ,
T_1 V_117 )
{
V_496 -> V_136 = V_136 ;
V_496 -> V_117 = V_117 ;
F_203 ( V_496 -> V_136 , V_496 -> V_117 ,
& V_496 -> V_504 , & V_496 -> V_130 , & V_496 -> V_128 , & V_496 -> V_181 ) ;
V_496 -> V_232 = 0 ;
}
static bool F_204 ( unsigned F_62 )
{
T_2 V_26 = ( ( T_2 ) 1 << F_62 ) ;
return V_26 & ( V_121 | V_123 | V_122 ) & V_124 ;
}
static void F_205 ( struct V_126 * V_496 , T_1 V_136 ,
T_1 V_117 , int * V_502 , int V_511 )
{
unsigned V_512 = F_193 () ? F_206 ( V_513 ) : 0 ;
#ifdef F_52
unsigned V_514 = ( V_56 -> V_515 () == V_516 )
? F_206 ( V_517 ) : 0 ;
unsigned V_518 = F_206 ( V_519 ) ;
#else
unsigned V_514 = 0 ;
unsigned V_518 = 0 ;
#endif
unsigned V_520 = V_56 -> V_521 () ? F_206 ( V_522 ) : 0 ;
const T_1 V_523 =
F_206 ( V_524 ) | F_206 ( V_525 ) | F_206 ( V_526 ) | F_206 ( V_527 ) |
F_206 ( V_528 ) | F_206 ( V_529 ) | F_206 ( V_530 ) | F_206 ( V_531 ) |
F_206 ( V_532 ) | F_206 ( V_533 ) | 0 | F_206 ( V_534 ) |
F_206 ( V_535 ) | F_206 ( V_536 ) | F_206 ( V_537 ) | F_206 ( V_538 ) |
F_206 ( V_539 ) | F_206 ( V_540 ) | 0 | F_206 ( V_541 ) |
0 | F_206 ( V_542 ) |
F_206 ( V_543 ) | F_206 ( V_544 ) | F_206 ( V_545 ) | F_206 ( V_546 ) |
0 ;
const T_1 V_547 =
F_206 ( V_524 ) | F_206 ( V_525 ) | F_206 ( V_526 ) | F_206 ( V_527 ) |
F_206 ( V_528 ) | F_206 ( V_529 ) | F_206 ( V_530 ) | F_206 ( V_531 ) |
F_206 ( V_532 ) | F_206 ( V_533 ) | 0 | F_206 ( V_548 ) |
F_206 ( V_535 ) | F_206 ( V_536 ) | F_206 ( V_537 ) | F_206 ( V_538 ) |
F_206 ( V_539 ) | F_206 ( V_540 ) | 0 |
V_512 | 0 | F_206 ( V_549 ) | F_206 ( V_542 ) |
F_206 ( V_543 ) | F_206 ( V_550 ) | V_514 | V_520 |
0 | V_518 | F_206 ( 3DNOWEXT ) | F_206 ( 3DNOW ) ;
const T_1 V_551 =
F_206 ( V_552 ) | F_206 ( V_553 ) | 0 |
0 |
0 | F_206 ( V_554 ) | 0 | 0 |
0 | F_206 ( V_555 ) | 0 |
0 | F_206 ( V_556 ) |
F_206 ( V_557 ) | F_206 ( V_558 ) | F_206 ( V_559 ) | F_206 ( V_560 ) |
0 | F_206 ( V_561 ) | F_206 ( V_562 ) | 0 | F_206 ( V_563 ) |
F_206 ( V_564 ) | F_206 ( V_565 ) ;
const T_1 V_566 =
F_206 ( V_567 ) | F_206 ( V_568 ) | 0 | 0 |
F_206 ( V_569 ) | F_206 ( V_570 ) | F_206 ( V_571 ) | F_206 ( V_572 ) |
F_206 ( 3DNOWPREFETCH ) | 0 | 0 | F_206 ( V_573 ) |
0 | F_206 ( V_574 ) | F_206 ( V_575 ) ;
const T_1 V_576 =
F_206 ( V_577 ) | F_206 ( V_578 ) | F_206 ( V_579 ) | F_206 ( V_580 ) |
F_206 ( V_581 ) | F_206 ( V_582 ) | F_206 ( V_583 ) | F_206 ( V_584 ) |
F_206 ( V_585 ) | F_206 ( V_586 ) ;
const T_1 V_587 =
F_206 ( V_588 ) | F_206 ( V_589 ) | F_206 ( V_590 ) ;
F_100 () ;
F_202 ( V_496 , V_136 , V_117 ) ;
++ * V_502 ;
switch ( V_136 ) {
case 0 :
V_496 -> V_504 = F_207 ( V_496 -> V_504 , ( T_1 ) 0xd ) ;
break;
case 1 :
V_496 -> V_181 &= V_523 ;
F_201 ( & V_496 -> V_181 , 0 ) ;
V_496 -> V_128 &= V_551 ;
F_201 ( & V_496 -> V_128 , 4 ) ;
V_496 -> V_128 |= F_206 ( V_558 ) ;
break;
case 2 : {
int V_273 , V_591 = V_496 -> V_504 & 0xff ;
V_496 -> V_232 |= V_592 ;
V_496 -> V_232 |= V_593 ;
for ( V_273 = 1 ; V_273 < V_591 && * V_502 < V_511 ; ++ V_273 ) {
F_202 ( & V_496 [ V_273 ] , V_136 , 0 ) ;
V_496 [ V_273 ] . V_232 |= V_592 ;
++ * V_502 ;
}
break;
}
case 4 : {
int V_3 , V_594 ;
V_496 -> V_232 |= V_595 ;
for ( V_3 = 1 ; * V_502 < V_511 ; ++ V_3 ) {
V_594 = V_496 [ V_3 - 1 ] . V_504 & 0x1f ;
if ( ! V_594 )
break;
F_202 ( & V_496 [ V_3 ] , V_136 , V_3 ) ;
V_496 [ V_3 ] . V_232 |=
V_595 ;
++ * V_502 ;
}
break;
}
case 7 : {
V_496 -> V_232 |= V_595 ;
if ( V_117 == 0 ) {
V_496 -> V_130 &= V_587 ;
F_201 ( & V_496 -> V_130 , 9 ) ;
} else
V_496 -> V_130 = 0 ;
V_496 -> V_504 = 0 ;
V_496 -> V_128 = 0 ;
V_496 -> V_181 = 0 ;
break;
}
case 9 :
break;
case 0xb : {
int V_3 , V_596 ;
V_496 -> V_232 |= V_595 ;
for ( V_3 = 1 ; * V_502 < V_511 ; ++ V_3 ) {
V_596 = V_496 [ V_3 - 1 ] . V_128 & 0xff00 ;
if ( ! V_596 )
break;
F_202 ( & V_496 [ V_3 ] , V_136 , V_3 ) ;
V_496 [ V_3 ] . V_232 |=
V_595 ;
++ * V_502 ;
}
break;
}
case 0xd : {
int V_280 , V_3 ;
V_496 -> V_232 |= V_595 ;
for ( V_280 = 1 , V_3 = 1 ; * V_502 < V_511 && V_280 < 64 ; ++ V_280 ) {
F_202 ( & V_496 [ V_3 ] , V_136 , V_280 ) ;
if ( V_496 [ V_3 ] . V_504 == 0 || ! F_204 ( V_280 ) )
continue;
V_496 [ V_3 ] . V_232 |=
V_595 ;
++ * V_502 ;
++ V_3 ;
}
break;
}
case V_597 : {
char V_598 [ 12 ] = L_21 ;
T_1 * V_599 = ( T_1 * ) V_598 ;
V_496 -> V_504 = 0 ;
V_496 -> V_130 = V_599 [ 0 ] ;
V_496 -> V_128 = V_599 [ 1 ] ;
V_496 -> V_181 = V_599 [ 2 ] ;
break;
}
case V_600 :
V_496 -> V_504 = ( 1 << V_601 ) |
( 1 << V_602 ) |
( 1 << V_603 ) |
( 1 << V_604 ) |
( 1 << V_605 ) ;
if ( F_157 () )
V_496 -> V_504 |= ( 1 << V_606 ) ;
V_496 -> V_130 = 0 ;
V_496 -> V_128 = 0 ;
V_496 -> V_181 = 0 ;
break;
case 0x80000000 :
V_496 -> V_504 = F_207 ( V_496 -> V_504 , 0x8000001a ) ;
break;
case 0x80000001 :
V_496 -> V_181 &= V_547 ;
F_201 ( & V_496 -> V_181 , 1 ) ;
V_496 -> V_128 &= V_566 ;
F_201 ( & V_496 -> V_128 , 6 ) ;
break;
case 0x80000008 : {
unsigned V_607 = ( V_496 -> V_504 >> 16 ) & 0xff ;
unsigned V_608 = F_208 ( ( V_496 -> V_504 >> 8 ) & 0xff , 48U ) ;
unsigned V_609 = V_496 -> V_504 & 0xff ;
if ( ! V_607 )
V_607 = V_609 ;
V_496 -> V_504 = V_607 | ( V_608 << 8 ) ;
V_496 -> V_130 = V_496 -> V_181 = 0 ;
break;
}
case 0x80000019 :
V_496 -> V_128 = V_496 -> V_181 = 0 ;
break;
case 0x8000001a :
break;
case 0x8000001d :
break;
case 0xC0000000 :
V_496 -> V_504 = F_207 ( V_496 -> V_504 , 0xC0000004 ) ;
break;
case 0xC0000001 :
V_496 -> V_181 &= V_576 ;
F_201 ( & V_496 -> V_181 , 5 ) ;
break;
case 3 :
case 5 :
case 6 :
case 0xA :
case 0x80000007 :
case 0xC0000002 :
case 0xC0000003 :
case 0xC0000004 :
default:
V_496 -> V_504 = V_496 -> V_130 = V_496 -> V_128 = V_496 -> V_181 = 0 ;
break;
}
V_56 -> V_610 ( V_136 , V_496 ) ;
F_103 () ;
}
static int F_182 ( struct V_479 * V_481 ,
struct V_126 V_319 * V_407 )
{
struct V_126 * V_498 ;
int V_611 , V_502 = 0 , V_99 = - V_306 ;
T_1 V_612 ;
if ( V_481 -> V_502 < 1 )
goto V_93;
if ( V_481 -> V_502 > V_503 )
V_481 -> V_502 = V_503 ;
V_99 = - V_307 ;
V_498 = F_196 ( sizeof( struct V_126 ) * V_481 -> V_502 ) ;
if ( ! V_498 )
goto V_93;
F_205 ( & V_498 [ 0 ] , 0 , 0 , & V_502 , V_481 -> V_502 ) ;
V_611 = V_498 [ 0 ] . V_504 ;
for ( V_612 = 1 ; V_612 <= V_611 && V_502 < V_481 -> V_502 ; ++ V_612 )
F_205 ( & V_498 [ V_502 ] , V_612 , 0 ,
& V_502 , V_481 -> V_502 ) ;
V_99 = - V_306 ;
if ( V_502 >= V_481 -> V_502 )
goto V_309;
F_205 ( & V_498 [ V_502 ] , 0x80000000 , 0 , & V_502 , V_481 -> V_502 ) ;
V_611 = V_498 [ V_502 - 1 ] . V_504 ;
for ( V_612 = 0x80000001 ; V_612 <= V_611 && V_502 < V_481 -> V_502 ; ++ V_612 )
F_205 ( & V_498 [ V_502 ] , V_612 , 0 ,
& V_502 , V_481 -> V_502 ) ;
V_99 = - V_306 ;
if ( V_502 >= V_481 -> V_502 )
goto V_309;
if ( V_509 . V_613 == V_614 ) {
F_205 ( & V_498 [ V_502 ] , 0xC0000000 , 0 ,
& V_502 , V_481 -> V_502 ) ;
V_99 = - V_306 ;
if ( V_502 >= V_481 -> V_502 )
goto V_309;
V_611 = V_498 [ V_502 - 1 ] . V_504 ;
for ( V_612 = 0xC0000001 ;
V_612 <= V_611 && V_502 < V_481 -> V_502 ; ++ V_612 )
F_205 ( & V_498 [ V_502 ] , V_612 , 0 ,
& V_502 , V_481 -> V_502 ) ;
V_99 = - V_306 ;
if ( V_502 >= V_481 -> V_502 )
goto V_309;
}
F_205 ( & V_498 [ V_502 ] , V_597 , 0 , & V_502 ,
V_481 -> V_502 ) ;
V_99 = - V_306 ;
if ( V_502 >= V_481 -> V_502 )
goto V_309;
F_205 ( & V_498 [ V_502 ] , V_600 , 0 , & V_502 ,
V_481 -> V_502 ) ;
V_99 = - V_306 ;
if ( V_502 >= V_481 -> V_502 )
goto V_309;
V_99 = - V_81 ;
if ( F_178 ( V_407 , V_498 ,
V_502 * sizeof( struct V_126 ) ) )
goto V_309;
V_481 -> V_502 = V_502 ;
V_99 = 0 ;
V_309:
F_198 ( V_498 ) ;
V_93:
return V_99 ;
}
static int F_209 ( struct V_1 * V_2 ,
struct V_615 * V_616 )
{
memcpy ( V_616 -> V_617 , V_2 -> V_5 . V_134 -> V_617 , sizeof *V_616 ) ;
return 0 ;
}
static int F_210 ( struct V_1 * V_2 ,
struct V_615 * V_616 )
{
memcpy ( V_2 -> V_5 . V_134 -> V_617 , V_616 -> V_617 , sizeof *V_616 ) ;
F_211 ( V_2 ) ;
F_212 ( V_2 ) ;
return 0 ;
}
static int F_213 ( struct V_1 * V_2 ,
struct V_618 * V_619 )
{
if ( V_619 -> V_619 < 0 || V_619 -> V_619 >= 256 )
return - V_485 ;
if ( F_18 ( V_2 -> V_29 ) )
return - V_620 ;
F_214 ( V_2 , V_619 -> V_619 , false ) ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
static int F_215 ( struct V_1 * V_2 )
{
F_32 ( V_2 ) ;
return 0 ;
}
static int F_216 ( struct V_1 * V_2 ,
struct V_621 * V_622 )
{
if ( V_622 -> V_232 )
return - V_485 ;
V_2 -> V_5 . V_623 = ! ! V_622 -> V_278 ;
return 0 ;
}
static int F_217 ( struct V_1 * V_2 ,
T_2 V_286 )
{
int V_99 ;
unsigned V_287 = V_286 & 0xff , V_624 ;
V_99 = - V_485 ;
if ( ! V_287 || V_287 >= V_370 )
goto V_93;
if ( V_286 & ~ ( V_484 | 0xff | 0xff0000 ) )
goto V_93;
V_99 = 0 ;
V_2 -> V_5 . V_286 = V_286 ;
if ( V_286 & V_291 )
V_2 -> V_5 . V_292 = ~ ( T_2 ) 0 ;
for ( V_624 = 0 ; V_624 < V_287 ; V_624 ++ )
V_2 -> V_5 . V_294 [ V_624 * 4 ] = ~ ( T_2 ) 0 ;
V_93:
return V_99 ;
}
static int F_218 ( struct V_1 * V_2 ,
struct V_625 * V_626 )
{
T_2 V_286 = V_2 -> V_5 . V_286 ;
unsigned V_287 = V_286 & 0xff ;
T_2 * V_627 = V_2 -> V_5 . V_294 ;
if ( V_626 -> V_624 >= V_287 || ! ( V_626 -> V_628 & V_629 ) )
return - V_485 ;
if ( ( V_626 -> V_628 & V_630 ) && ( V_286 & V_291 ) &&
V_2 -> V_5 . V_292 != ~ ( T_2 ) 0 )
return 0 ;
V_627 += 4 * V_626 -> V_624 ;
if ( ( V_626 -> V_628 & V_630 ) && V_627 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_626 -> V_628 & V_630 ) {
if ( ( V_2 -> V_5 . V_289 & V_631 ) ||
! F_66 ( V_2 , V_632 ) ) {
F_23 ( V_54 , V_2 ) ;
return 0 ;
}
if ( V_627 [ 1 ] & V_629 )
V_626 -> V_628 |= V_633 ;
V_627 [ 2 ] = V_626 -> V_315 ;
V_627 [ 3 ] = V_626 -> V_634 ;
V_2 -> V_5 . V_289 = V_626 -> V_289 ;
V_627 [ 1 ] = V_626 -> V_628 ;
F_24 ( V_2 , V_635 ) ;
} else if ( ! ( V_627 [ 1 ] & V_629 )
|| ! ( V_627 [ 1 ] & V_630 ) ) {
if ( V_627 [ 1 ] & V_629 )
V_626 -> V_628 |= V_633 ;
V_627 [ 2 ] = V_626 -> V_315 ;
V_627 [ 3 ] = V_626 -> V_634 ;
V_627 [ 1 ] = V_626 -> V_628 ;
} else
V_627 [ 1 ] |= V_633 ;
return 0 ;
}
static void F_219 ( struct V_1 * V_2 ,
struct V_636 * V_637 )
{
F_220 ( V_2 ) ;
V_637 -> V_49 . V_638 =
V_2 -> V_5 . V_49 . V_50 &&
! F_221 ( V_2 -> V_5 . V_49 . V_16 ) ;
V_637 -> V_49 . V_16 = V_2 -> V_5 . V_49 . V_16 ;
V_637 -> V_49 . V_52 = V_2 -> V_5 . V_49 . V_52 ;
V_637 -> V_49 . V_639 = 0 ;
V_637 -> V_49 . V_43 = V_2 -> V_5 . V_49 . V_43 ;
V_637 -> V_640 . V_638 =
V_2 -> V_5 . V_640 . V_50 && ! V_2 -> V_5 . V_640 . V_641 ;
V_637 -> V_640 . V_16 = V_2 -> V_5 . V_640 . V_16 ;
V_637 -> V_640 . V_641 = 0 ;
V_637 -> V_640 . V_642 =
V_56 -> V_643 ( V_2 ,
V_644 | V_645 ) ;
V_637 -> V_646 . V_638 = V_2 -> V_5 . V_647 ;
V_637 -> V_646 . V_50 = V_2 -> V_5 . V_648 != 0 ;
V_637 -> V_646 . V_649 = V_56 -> V_650 ( V_2 ) ;
V_637 -> V_646 . V_639 = 0 ;
V_637 -> V_651 = V_2 -> V_5 . V_651 ;
V_637 -> V_232 = ( V_652
| V_653
| V_654 ) ;
memset ( & V_637 -> V_655 , 0 , sizeof( V_637 -> V_655 ) ) ;
}
static int F_222 ( struct V_1 * V_2 ,
struct V_636 * V_637 )
{
if ( V_637 -> V_232 & ~ ( V_652
| V_653
| V_654 ) )
return - V_485 ;
F_220 ( V_2 ) ;
V_2 -> V_5 . V_49 . V_50 = V_637 -> V_49 . V_638 ;
V_2 -> V_5 . V_49 . V_16 = V_637 -> V_49 . V_16 ;
V_2 -> V_5 . V_49 . V_52 = V_637 -> V_49 . V_52 ;
V_2 -> V_5 . V_49 . V_43 = V_637 -> V_49 . V_43 ;
V_2 -> V_5 . V_640 . V_50 = V_637 -> V_640 . V_638 ;
V_2 -> V_5 . V_640 . V_16 = V_637 -> V_640 . V_16 ;
V_2 -> V_5 . V_640 . V_641 = V_637 -> V_640 . V_641 ;
if ( V_637 -> V_232 & V_654 )
V_56 -> V_656 ( V_2 ,
V_637 -> V_640 . V_642 ) ;
V_2 -> V_5 . V_647 = V_637 -> V_646 . V_638 ;
if ( V_637 -> V_232 & V_652 )
V_2 -> V_5 . V_648 = V_637 -> V_646 . V_50 ;
V_56 -> V_657 ( V_2 , V_637 -> V_646 . V_649 ) ;
if ( V_637 -> V_232 & V_653 )
V_2 -> V_5 . V_651 = V_637 -> V_651 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
static void F_223 ( struct V_1 * V_2 ,
struct V_658 * V_659 )
{
memcpy ( V_659 -> V_161 , V_2 -> V_5 . V_161 , sizeof( V_2 -> V_5 . V_161 ) ) ;
V_659 -> V_166 = V_2 -> V_5 . V_166 ;
V_659 -> V_169 = V_2 -> V_5 . V_169 ;
V_659 -> V_232 = 0 ;
memset ( & V_659 -> V_655 , 0 , sizeof( V_659 -> V_655 ) ) ;
}
static int F_224 ( struct V_1 * V_2 ,
struct V_658 * V_659 )
{
if ( V_659 -> V_232 )
return - V_485 ;
memcpy ( V_2 -> V_5 . V_161 , V_659 -> V_161 , sizeof( V_2 -> V_5 . V_161 ) ) ;
V_2 -> V_5 . V_166 = V_659 -> V_166 ;
V_2 -> V_5 . V_169 = V_659 -> V_169 ;
return 0 ;
}
static void F_225 ( struct V_1 * V_2 ,
struct V_660 * V_661 )
{
if ( V_135 )
memcpy ( V_661 -> V_662 ,
& V_2 -> V_5 . V_663 . V_664 -> V_665 ,
V_666 ) ;
else {
memcpy ( V_661 -> V_662 ,
& V_2 -> V_5 . V_663 . V_664 -> V_667 ,
sizeof( struct V_668 ) ) ;
* ( T_2 * ) & V_661 -> V_662 [ V_669 / sizeof( T_1 ) ] =
V_670 ;
}
}
static int F_226 ( struct V_1 * V_2 ,
struct V_660 * V_661 )
{
T_2 V_671 =
* ( T_2 * ) & V_661 -> V_662 [ V_669 / sizeof( T_1 ) ] ;
if ( V_135 )
memcpy ( & V_2 -> V_5 . V_663 . V_664 -> V_665 ,
V_661 -> V_662 , V_666 ) ;
else {
if ( V_671 & ~ V_670 )
return - V_485 ;
memcpy ( & V_2 -> V_5 . V_663 . V_664 -> V_667 ,
V_661 -> V_662 , sizeof( struct V_668 ) ) ;
}
return 0 ;
}
static void F_227 ( struct V_1 * V_2 ,
struct V_672 * V_673 )
{
if ( ! V_135 ) {
V_673 -> V_674 = 0 ;
return;
}
V_673 -> V_674 = 1 ;
V_673 -> V_232 = 0 ;
V_673 -> V_675 [ 0 ] . V_118 = V_120 ;
V_673 -> V_675 [ 0 ] . V_23 = V_2 -> V_5 . V_119 ;
}
static int F_228 ( struct V_1 * V_2 ,
struct V_672 * V_673 )
{
int V_3 , V_99 = 0 ;
if ( ! V_135 )
return - V_485 ;
if ( V_673 -> V_674 > V_676 || V_673 -> V_232 )
return - V_485 ;
for ( V_3 = 0 ; V_3 < V_673 -> V_674 ; V_3 ++ )
if ( V_673 -> V_675 [ 0 ] . V_118 == V_120 ) {
V_99 = F_58 ( V_2 , V_120 ,
V_673 -> V_675 [ 0 ] . V_23 ) ;
break;
}
if ( V_99 )
V_99 = - V_485 ;
return V_99 ;
}
long F_229 ( struct V_465 * V_466 ,
unsigned int V_467 , unsigned long V_468 )
{
struct V_1 * V_2 = V_466 -> V_677 ;
void V_319 * V_469 = ( void V_319 * ) V_468 ;
int V_99 ;
union {
struct V_615 * V_678 ;
struct V_660 * V_665 ;
struct V_672 * V_675 ;
void * V_679 ;
} V_680 ;
V_680 . V_679 = NULL ;
switch ( V_467 ) {
case V_681 : {
V_99 = - V_485 ;
if ( ! V_2 -> V_5 . V_134 )
goto V_93;
V_680 . V_678 = F_129 ( sizeof( struct V_615 ) , V_308 ) ;
V_99 = - V_307 ;
if ( ! V_680 . V_678 )
goto V_93;
V_99 = F_209 ( V_2 , V_680 . V_678 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_178 ( V_469 , V_680 . V_678 , sizeof( struct V_615 ) ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_682 : {
V_99 = - V_485 ;
if ( ! V_2 -> V_5 . V_134 )
goto V_93;
V_680 . V_678 = F_177 ( sizeof( struct V_615 ) , V_308 ) ;
V_99 = - V_307 ;
if ( ! V_680 . V_678 )
goto V_93;
V_99 = - V_81 ;
if ( F_130 ( V_680 . V_678 , V_469 , sizeof( struct V_615 ) ) )
goto V_93;
V_99 = F_210 ( V_2 , V_680 . V_678 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_683 : {
struct V_618 V_619 ;
V_99 = - V_81 ;
if ( F_130 ( & V_619 , V_469 , sizeof V_619 ) )
goto V_93;
V_99 = F_213 ( V_2 , & V_619 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_684 : {
V_99 = F_215 ( V_2 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_685 : {
struct V_500 V_319 * V_480 = V_469 ;
struct V_500 V_481 ;
V_99 = - V_81 ;
if ( F_130 ( & V_481 , V_480 , sizeof V_481 ) )
goto V_93;
V_99 = F_195 ( V_2 , & V_481 , V_480 -> V_407 ) ;
if ( V_99 )
goto V_93;
break;
}
case V_686 : {
struct V_479 V_319 * V_480 = V_469 ;
struct V_479 V_481 ;
V_99 = - V_81 ;
if ( F_130 ( & V_481 , V_480 , sizeof V_481 ) )
goto V_93;
V_99 = F_199 ( V_2 , & V_481 ,
V_480 -> V_407 ) ;
if ( V_99 )
goto V_93;
break;
}
case V_687 : {
struct V_479 V_319 * V_480 = V_469 ;
struct V_479 V_481 ;
V_99 = - V_81 ;
if ( F_130 ( & V_481 , V_480 , sizeof V_481 ) )
goto V_93;
V_99 = F_200 ( V_2 , & V_481 ,
V_480 -> V_407 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_178 ( V_480 , & V_481 , sizeof V_481 ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_688 :
V_99 = F_176 ( V_2 , V_469 , F_162 , 1 ) ;
break;
case V_689 :
V_99 = F_176 ( V_2 , V_469 , F_85 , 0 ) ;
break;
case V_690 : {
struct V_621 V_622 ;
V_99 = - V_81 ;
if ( F_130 ( & V_622 , V_469 , sizeof V_622 ) )
goto V_93;
V_99 = F_216 ( V_2 , & V_622 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_178 ( V_469 , & V_622 , sizeof V_622 ) )
goto V_93;
V_99 = 0 ;
break;
} ;
case V_691 : {
struct V_692 V_693 ;
V_99 = - V_485 ;
if ( ! F_18 ( V_2 -> V_29 ) )
goto V_93;
V_99 = - V_81 ;
if ( F_130 ( & V_693 , V_469 , sizeof V_693 ) )
goto V_93;
V_99 = 0 ;
F_230 ( V_2 , V_693 . V_694 ) ;
break;
}
case V_695 : {
T_2 V_286 ;
V_99 = - V_81 ;
if ( F_130 ( & V_286 , V_469 , sizeof V_286 ) )
goto V_93;
V_99 = F_217 ( V_2 , V_286 ) ;
break;
}
case V_696 : {
struct V_625 V_626 ;
V_99 = - V_81 ;
if ( F_130 ( & V_626 , V_469 , sizeof V_626 ) )
goto V_93;
V_99 = F_218 ( V_2 , & V_626 ) ;
break;
}
case V_697 : {
struct V_636 V_637 ;
F_219 ( V_2 , & V_637 ) ;
V_99 = - V_81 ;
if ( F_178 ( V_469 , & V_637 , sizeof( struct V_636 ) ) )
break;
V_99 = 0 ;
break;
}
case V_698 : {
struct V_636 V_637 ;
V_99 = - V_81 ;
if ( F_130 ( & V_637 , V_469 , sizeof( struct V_636 ) ) )
break;
V_99 = F_222 ( V_2 , & V_637 ) ;
break;
}
case V_699 : {
struct V_658 V_659 ;
F_223 ( V_2 , & V_659 ) ;
V_99 = - V_81 ;
if ( F_178 ( V_469 , & V_659 ,
sizeof( struct V_658 ) ) )
break;
V_99 = 0 ;
break;
}
case V_700 : {
struct V_658 V_659 ;
V_99 = - V_81 ;
if ( F_130 ( & V_659 , V_469 ,
sizeof( struct V_658 ) ) )
break;
V_99 = F_224 ( V_2 , & V_659 ) ;
break;
}
case V_701 : {
V_680 . V_665 = F_129 ( sizeof( struct V_660 ) , V_308 ) ;
V_99 = - V_307 ;
if ( ! V_680 . V_665 )
break;
F_225 ( V_2 , V_680 . V_665 ) ;
V_99 = - V_81 ;
if ( F_178 ( V_469 , V_680 . V_665 , sizeof( struct V_660 ) ) )
break;
V_99 = 0 ;
break;
}
case V_702 : {
V_680 . V_665 = F_129 ( sizeof( struct V_660 ) , V_308 ) ;
V_99 = - V_307 ;
if ( ! V_680 . V_665 )
break;
V_99 = - V_81 ;
if ( F_130 ( V_680 . V_665 , V_469 , sizeof( struct V_660 ) ) )
break;
V_99 = F_226 ( V_2 , V_680 . V_665 ) ;
break;
}
case V_703 : {
V_680 . V_675 = F_129 ( sizeof( struct V_672 ) , V_308 ) ;
V_99 = - V_307 ;
if ( ! V_680 . V_675 )
break;
F_227 ( V_2 , V_680 . V_675 ) ;
V_99 = - V_81 ;
if ( F_178 ( V_469 , V_680 . V_675 ,
sizeof( struct V_672 ) ) )
break;
V_99 = 0 ;
break;
}
case V_704 : {
V_680 . V_675 = F_129 ( sizeof( struct V_672 ) , V_308 ) ;
V_99 = - V_307 ;
if ( ! V_680 . V_675 )
break;
V_99 = - V_81 ;
if ( F_130 ( V_680 . V_675 , V_469 ,
sizeof( struct V_672 ) ) )
break;
V_99 = F_228 ( V_2 , V_680 . V_675 ) ;
break;
}
case V_705 : {
T_1 V_706 ;
V_99 = - V_485 ;
if ( ! V_463 )
break;
V_706 = ( T_1 ) V_468 ;
if ( V_706 >= V_707 )
goto V_93;
V_56 -> V_708 ( V_2 , V_706 ) ;
V_99 = 0 ;
goto V_93;
}
case V_709 : {
V_99 = - V_710 ;
if ( F_114 () )
goto V_93;
V_99 = F_104 ( V_2 ) ;
goto V_93;
}
default:
V_99 = - V_485 ;
}
V_93:
F_131 ( V_680 . V_679 ) ;
return V_99 ;
}
static int F_231 ( struct V_29 * V_29 , unsigned long V_315 )
{
int V_88 ;
if ( V_315 > ( unsigned int ) ( - 3 * V_87 ) )
return - 1 ;
V_88 = V_56 -> V_711 ( V_29 , V_315 ) ;
return V_88 ;
}
static int F_232 ( struct V_29 * V_29 ,
T_2 V_712 )
{
V_29 -> V_5 . V_713 = V_712 ;
return 0 ;
}
static int F_233 ( struct V_29 * V_29 ,
T_1 V_714 )
{
if ( V_714 < V_715 )
return - V_485 ;
F_160 ( & V_29 -> V_716 ) ;
F_234 ( & V_29 -> V_717 ) ;
F_235 ( V_29 , V_714 ) ;
V_29 -> V_5 . V_718 = V_714 ;
F_236 ( & V_29 -> V_717 ) ;
F_161 ( & V_29 -> V_716 ) ;
return 0 ;
}
static int F_237 ( struct V_29 * V_29 )
{
return V_29 -> V_5 . V_719 ;
}
static int F_238 ( struct V_29 * V_29 , struct V_720 * V_721 )
{
int V_99 ;
V_99 = 0 ;
switch ( V_721 -> V_722 ) {
case V_723 :
memcpy ( & V_721 -> V_721 . V_724 ,
& F_239 ( V_29 ) -> V_725 [ 0 ] ,
sizeof( struct V_726 ) ) ;
break;
case V_727 :
memcpy ( & V_721 -> V_721 . V_724 ,
& F_239 ( V_29 ) -> V_725 [ 1 ] ,
sizeof( struct V_726 ) ) ;
break;
case V_728 :
V_99 = F_240 ( V_29 , & V_721 -> V_721 . V_729 ) ;
break;
default:
V_99 = - V_485 ;
break;
}
return V_99 ;
}
static int F_241 ( struct V_29 * V_29 , struct V_720 * V_721 )
{
int V_99 ;
V_99 = 0 ;
switch ( V_721 -> V_722 ) {
case V_723 :
F_234 ( & F_239 ( V_29 ) -> V_385 ) ;
memcpy ( & F_239 ( V_29 ) -> V_725 [ 0 ] ,
& V_721 -> V_721 . V_724 ,
sizeof( struct V_726 ) ) ;
F_236 ( & F_239 ( V_29 ) -> V_385 ) ;
break;
case V_727 :
F_234 ( & F_239 ( V_29 ) -> V_385 ) ;
memcpy ( & F_239 ( V_29 ) -> V_725 [ 1 ] ,
& V_721 -> V_721 . V_724 ,
sizeof( struct V_726 ) ) ;
F_236 ( & F_239 ( V_29 ) -> V_385 ) ;
break;
case V_728 :
V_99 = F_242 ( V_29 , & V_721 -> V_721 . V_729 ) ;
break;
default:
V_99 = - V_485 ;
break;
}
F_243 ( F_239 ( V_29 ) ) ;
return V_99 ;
}
static int F_244 ( struct V_29 * V_29 , struct V_730 * V_731 )
{
int V_99 = 0 ;
F_160 ( & V_29 -> V_5 . V_732 -> V_733 . V_385 ) ;
memcpy ( V_731 , & V_29 -> V_5 . V_732 -> V_733 , sizeof( struct V_730 ) ) ;
F_161 ( & V_29 -> V_5 . V_732 -> V_733 . V_385 ) ;
return V_99 ;
}
static int F_245 ( struct V_29 * V_29 , struct V_730 * V_731 )
{
int V_99 = 0 ;
F_160 ( & V_29 -> V_5 . V_732 -> V_733 . V_385 ) ;
memcpy ( & V_29 -> V_5 . V_732 -> V_733 , V_731 , sizeof( struct V_730 ) ) ;
F_246 ( V_29 , 0 , V_731 -> V_734 [ 0 ] . V_735 , 0 ) ;
F_161 ( & V_29 -> V_5 . V_732 -> V_733 . V_385 ) ;
return V_99 ;
}
static int F_247 ( struct V_29 * V_29 , struct V_736 * V_731 )
{
int V_99 = 0 ;
F_160 ( & V_29 -> V_5 . V_732 -> V_733 . V_385 ) ;
memcpy ( V_731 -> V_734 , & V_29 -> V_5 . V_732 -> V_733 . V_734 ,
sizeof( V_731 -> V_734 ) ) ;
V_731 -> V_232 = V_29 -> V_5 . V_732 -> V_733 . V_232 ;
F_161 ( & V_29 -> V_5 . V_732 -> V_733 . V_385 ) ;
memset ( & V_731 -> V_655 , 0 , sizeof( V_731 -> V_655 ) ) ;
return V_99 ;
}
static int F_248 ( struct V_29 * V_29 , struct V_736 * V_731 )
{
int V_99 = 0 , V_737 = 0 ;
T_1 V_738 , V_739 ;
F_160 ( & V_29 -> V_5 . V_732 -> V_733 . V_385 ) ;
V_738 = V_29 -> V_5 . V_732 -> V_733 . V_232 & V_740 ;
V_739 = V_731 -> V_232 & V_740 ;
if ( ! V_738 && V_739 )
V_737 = 1 ;
memcpy ( & V_29 -> V_5 . V_732 -> V_733 . V_734 , & V_731 -> V_734 ,
sizeof( V_29 -> V_5 . V_732 -> V_733 . V_734 ) ) ;
V_29 -> V_5 . V_732 -> V_733 . V_232 = V_731 -> V_232 ;
F_246 ( V_29 , 0 , V_29 -> V_5 . V_732 -> V_733 . V_734 [ 0 ] . V_735 , V_737 ) ;
F_161 ( & V_29 -> V_5 . V_732 -> V_733 . V_385 ) ;
return V_99 ;
}
static int F_249 ( struct V_29 * V_29 ,
struct V_741 * V_742 )
{
if ( ! V_29 -> V_5 . V_732 )
return - V_620 ;
F_160 ( & V_29 -> V_5 . V_732 -> V_733 . V_385 ) ;
V_29 -> V_5 . V_732 -> V_733 . V_743 . V_44 = V_742 -> V_744 ;
F_161 ( & V_29 -> V_5 . V_732 -> V_733 . V_385 ) ;
return 0 ;
}
int F_250 ( struct V_29 * V_29 ,
struct V_745 * log )
{
int V_99 , V_3 ;
struct V_746 * V_747 ;
unsigned long V_412 ;
unsigned long V_748 = 0 ;
F_160 ( & V_29 -> V_716 ) ;
V_99 = - V_485 ;
if ( log -> V_10 >= V_456 )
goto V_93;
V_747 = & V_29 -> V_749 -> V_749 [ log -> V_10 ] ;
V_99 = - V_750 ;
if ( ! V_747 -> V_751 )
goto V_93;
V_412 = F_251 ( V_747 ) ;
for ( V_3 = 0 ; ! V_748 && V_3 < V_412 / sizeof( long ) ; V_3 ++ )
V_748 = V_747 -> V_751 [ V_3 ] ;
if ( V_748 ) {
struct V_752 * V_753 , * V_754 ;
unsigned long * V_751 ;
V_751 = V_747 -> V_755 ;
if ( V_747 -> V_751 == V_751 )
V_751 += V_412 / sizeof( long ) ;
memset ( V_751 , 0 , V_412 ) ;
V_99 = - V_307 ;
V_753 = F_129 ( sizeof( struct V_752 ) , V_308 ) ;
if ( ! V_753 )
goto V_93;
memcpy ( V_753 , V_29 -> V_749 , sizeof( struct V_752 ) ) ;
V_753 -> V_749 [ log -> V_10 ] . V_751 = V_751 ;
V_753 -> V_756 ++ ;
V_754 = V_29 -> V_749 ;
F_252 ( V_29 -> V_749 , V_753 ) ;
F_253 ( & V_29 -> V_408 ) ;
V_751 = V_754 -> V_749 [ log -> V_10 ] . V_751 ;
F_131 ( V_754 ) ;
F_234 ( & V_29 -> V_717 ) ;
F_254 ( V_29 , log -> V_10 ) ;
F_236 ( & V_29 -> V_717 ) ;
V_99 = - V_81 ;
if ( F_178 ( log -> V_751 , V_751 , V_412 ) )
goto V_93;
} else {
V_99 = - V_81 ;
if ( F_255 ( log -> V_751 , V_412 ) )
goto V_93;
}
V_99 = 0 ;
V_93:
F_161 ( & V_29 -> V_716 ) ;
return V_99 ;
}
long F_256 ( struct V_465 * V_466 ,
unsigned int V_467 , unsigned long V_468 )
{
struct V_29 * V_29 = V_466 -> V_677 ;
void V_319 * V_469 = ( void V_319 * ) V_468 ;
int V_99 = - V_757 ;
union {
struct V_730 V_731 ;
struct V_736 V_758 ;
struct V_759 V_760 ;
} V_680 ;
switch ( V_467 ) {
case V_761 :
V_99 = F_231 ( V_29 , V_468 ) ;
if ( V_99 < 0 )
goto V_93;
break;
case V_762 : {
T_2 V_712 ;
V_99 = - V_81 ;
if ( F_130 ( & V_712 , V_469 , sizeof V_712 ) )
goto V_93;
V_99 = F_232 ( V_29 , V_712 ) ;
if ( V_99 < 0 )
goto V_93;
break;
}
case V_763 :
V_99 = F_233 ( V_29 , V_468 ) ;
if ( V_99 )
goto V_93;
break;
case V_764 :
V_99 = F_237 ( V_29 ) ;
break;
case V_765 : {
struct V_766 * V_767 ;
F_160 ( & V_29 -> V_385 ) ;
V_99 = - V_768 ;
if ( V_29 -> V_5 . V_767 )
goto V_769;
V_99 = - V_307 ;
V_767 = F_257 ( V_29 ) ;
if ( V_767 ) {
V_99 = F_258 ( V_29 ) ;
if ( V_99 ) {
F_160 ( & V_29 -> V_716 ) ;
F_259 ( V_29 , V_770 ,
& V_767 -> V_771 ) ;
F_259 ( V_29 , V_770 ,
& V_767 -> V_772 ) ;
F_259 ( V_29 , V_770 ,
& V_767 -> V_773 ) ;
F_161 ( & V_29 -> V_716 ) ;
F_131 ( V_767 ) ;
goto V_769;
}
} else
goto V_769;
F_12 () ;
V_29 -> V_5 . V_767 = V_767 ;
F_12 () ;
V_99 = F_260 ( V_29 ) ;
if ( V_99 ) {
F_160 ( & V_29 -> V_716 ) ;
F_160 ( & V_29 -> V_774 ) ;
F_261 ( V_29 ) ;
F_262 ( V_29 ) ;
F_161 ( & V_29 -> V_774 ) ;
F_161 ( & V_29 -> V_716 ) ;
}
V_769:
F_161 ( & V_29 -> V_385 ) ;
break;
}
case V_775 :
V_680 . V_760 . V_232 = V_776 ;
goto V_777;
case V_778 :
V_99 = - V_81 ;
if ( F_130 ( & V_680 . V_760 , V_469 ,
sizeof( struct V_759 ) ) )
goto V_93;
V_777:
F_160 ( & V_29 -> V_716 ) ;
V_99 = - V_768 ;
if ( V_29 -> V_5 . V_732 )
goto V_779;
V_99 = - V_307 ;
V_29 -> V_5 . V_732 = F_263 ( V_29 , V_680 . V_760 . V_232 ) ;
if ( V_29 -> V_5 . V_732 )
V_99 = 0 ;
V_779:
F_161 ( & V_29 -> V_716 ) ;
break;
case V_780 :
case V_781 : {
struct V_782 V_783 ;
V_99 = - V_81 ;
if ( F_130 ( & V_783 , V_469 , sizeof V_783 ) )
goto V_93;
V_99 = - V_620 ;
if ( F_18 ( V_29 ) ) {
T_11 V_628 ;
V_628 = F_264 ( V_29 , V_784 ,
V_783 . V_619 , V_783 . V_785 ) ;
if ( V_467 == V_780 ) {
V_99 = - V_81 ;
V_783 . V_628 = V_628 ;
if ( F_178 ( V_469 , & V_783 ,
sizeof V_783 ) )
goto V_93;
}
V_99 = 0 ;
}
break;
}
case V_786 : {
struct V_720 * V_721 = F_177 ( sizeof( * V_721 ) , V_308 ) ;
V_99 = - V_307 ;
if ( ! V_721 )
goto V_93;
V_99 = - V_81 ;
if ( F_130 ( V_721 , V_469 , sizeof *V_721 ) )
goto V_787;
V_99 = - V_620 ;
if ( ! F_18 ( V_29 ) )
goto V_787;
V_99 = F_238 ( V_29 , V_721 ) ;
if ( V_99 )
goto V_787;
V_99 = - V_81 ;
if ( F_178 ( V_469 , V_721 , sizeof *V_721 ) )
goto V_787;
V_99 = 0 ;
V_787:
F_131 ( V_721 ) ;
if ( V_99 )
goto V_93;
break;
}
case V_788 : {
struct V_720 * V_721 = F_177 ( sizeof( * V_721 ) , V_308 ) ;
V_99 = - V_307 ;
if ( ! V_721 )
goto V_93;
V_99 = - V_81 ;
if ( F_130 ( V_721 , V_469 , sizeof *V_721 ) )
goto V_789;
V_99 = - V_620 ;
if ( ! F_18 ( V_29 ) )
goto V_789;
V_99 = F_241 ( V_29 , V_721 ) ;
if ( V_99 )
goto V_789;
V_99 = 0 ;
V_789:
F_131 ( V_721 ) ;
if ( V_99 )
goto V_93;
break;
}
case V_790 : {
V_99 = - V_81 ;
if ( F_130 ( & V_680 . V_731 , V_469 , sizeof( struct V_730 ) ) )
goto V_93;
V_99 = - V_620 ;
if ( ! V_29 -> V_5 . V_732 )
goto V_93;
V_99 = F_244 ( V_29 , & V_680 . V_731 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_178 ( V_469 , & V_680 . V_731 , sizeof( struct V_730 ) ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_791 : {
V_99 = - V_81 ;
if ( F_130 ( & V_680 . V_731 , V_469 , sizeof V_680 . V_731 ) )
goto V_93;
V_99 = - V_620 ;
if ( ! V_29 -> V_5 . V_732 )
goto V_93;
V_99 = F_245 ( V_29 , & V_680 . V_731 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_792 : {
V_99 = - V_620 ;
if ( ! V_29 -> V_5 . V_732 )
goto V_93;
V_99 = F_247 ( V_29 , & V_680 . V_758 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_178 ( V_469 , & V_680 . V_758 , sizeof( V_680 . V_758 ) ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_793 : {
V_99 = - V_81 ;
if ( F_130 ( & V_680 . V_758 , V_469 , sizeof( V_680 . V_758 ) ) )
goto V_93;
V_99 = - V_620 ;
if ( ! V_29 -> V_5 . V_732 )
goto V_93;
V_99 = F_248 ( V_29 , & V_680 . V_758 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_794 : {
struct V_741 V_742 ;
V_99 = - V_81 ;
if ( F_130 ( & V_742 , V_469 , sizeof( V_742 ) ) )
goto V_93;
V_99 = F_249 ( V_29 , & V_742 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_795 : {
V_99 = - V_81 ;
if ( F_130 ( & V_29 -> V_5 . F_128 , V_469 ,
sizeof( struct V_796 ) ) )
goto V_93;
V_99 = - V_485 ;
if ( V_29 -> V_5 . F_128 . V_232 )
goto V_93;
V_99 = 0 ;
break;
}
case V_797 : {
struct V_798 V_799 ;
T_2 V_800 ;
T_9 V_237 ;
V_99 = - V_81 ;
if ( F_130 ( & V_799 , V_469 , sizeof( V_799 ) ) )
goto V_93;
V_99 = - V_485 ;
if ( V_799 . V_232 )
goto V_93;
V_99 = 0 ;
F_265 () ;
V_800 = F_93 () ;
V_237 = V_799 . clock - V_800 ;
F_266 () ;
V_29 -> V_5 . V_256 = V_237 ;
break;
}
case V_801 : {
struct V_798 V_799 ;
T_2 V_800 ;
F_265 () ;
V_800 = F_93 () ;
V_799 . clock = V_29 -> V_5 . V_256 + V_800 ;
F_266 () ;
V_799 . V_232 = 0 ;
memset ( & V_799 . V_639 , 0 , sizeof( V_799 . V_639 ) ) ;
V_99 = - V_81 ;
if ( F_178 ( V_469 , & V_799 , sizeof( V_799 ) ) )
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
static void F_267 ( void )
{
T_1 V_802 [ 2 ] ;
unsigned V_3 , V_803 ;
for ( V_3 = V_803 = V_804 ; V_3 < F_42 ( V_477 ) ; V_3 ++ ) {
if ( F_268 ( V_477 [ V_3 ] , & V_802 [ 0 ] , & V_802 [ 1 ] ) < 0 )
continue;
if ( V_803 < V_3 )
V_477 [ V_803 ] = V_477 [ V_3 ] ;
V_803 ++ ;
}
V_474 = V_803 ;
}
static int F_269 ( struct V_1 * V_2 , T_4 V_315 , int V_75 ,
const void * V_241 )
{
int V_805 = 0 ;
int V_412 ;
do {
V_412 = F_207 ( V_75 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_134 &&
! F_270 ( & V_2 -> V_5 . V_134 -> V_806 , V_315 , V_412 , V_241 ) )
&& F_271 ( V_2 -> V_29 , V_807 , V_315 , V_412 , V_241 ) )
break;
V_805 += V_412 ;
V_315 += V_412 ;
V_75 -= V_412 ;
V_241 += V_412 ;
} while ( V_75 );
return V_805 ;
}
static int F_272 ( struct V_1 * V_2 , T_4 V_315 , int V_75 , void * V_241 )
{
int V_805 = 0 ;
int V_412 ;
do {
V_412 = F_207 ( V_75 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_134 &&
! F_273 ( & V_2 -> V_5 . V_134 -> V_806 , V_315 , V_412 , V_241 ) )
&& F_274 ( V_2 -> V_29 , V_807 , V_315 , V_412 , V_241 ) )
break;
F_275 ( V_808 , V_412 , V_315 , * ( T_2 * ) V_241 ) ;
V_805 += V_412 ;
V_315 += V_412 ;
V_75 -= V_412 ;
V_241 += V_412 ;
} while ( V_75 );
return V_805 ;
}
static void F_276 ( struct V_1 * V_2 ,
struct V_809 * V_810 , int V_811 )
{
V_56 -> V_812 ( V_2 , V_810 , V_811 ) ;
}
void F_277 ( struct V_1 * V_2 ,
struct V_809 * V_810 , int V_811 )
{
V_56 -> V_813 ( V_2 , V_810 , V_811 ) ;
}
static T_4 V_79 ( struct V_1 * V_2 , T_4 V_330 , T_1 V_76 )
{
return V_330 ;
}
static T_4 F_278 ( struct V_1 * V_2 , T_4 V_330 , T_1 V_76 )
{
T_4 V_814 ;
struct V_58 V_49 ;
F_279 ( ! F_31 ( V_2 ) ) ;
V_76 |= V_91 ;
V_814 = V_2 -> V_5 . V_67 . V_815 ( V_2 , V_330 , V_76 , & V_49 ) ;
return V_814 ;
}
T_4 F_280 ( struct V_1 * V_2 , T_12 V_816 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
return V_2 -> V_5 . V_83 -> V_815 ( V_2 , V_816 , V_76 , V_49 ) ;
}
T_4 F_281 ( struct V_1 * V_2 , T_12 V_816 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
V_76 |= V_817 ;
return V_2 -> V_5 . V_83 -> V_815 ( V_2 , V_816 , V_76 , V_49 ) ;
}
T_4 F_282 ( struct V_1 * V_2 , T_12 V_816 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
V_76 |= V_92 ;
return V_2 -> V_5 . V_83 -> V_815 ( V_2 , V_816 , V_76 , V_49 ) ;
}
T_4 F_283 ( struct V_1 * V_2 , T_12 V_816 ,
struct V_58 * V_49 )
{
return V_2 -> V_5 . V_83 -> V_815 ( V_2 , V_816 , 0 , V_49 ) ;
}
static int F_284 ( T_12 V_315 , void * V_160 , unsigned int V_818 ,
struct V_1 * V_2 , T_1 V_76 ,
struct V_58 * V_49 )
{
void * V_31 = V_160 ;
int V_99 = V_819 ;
while ( V_818 ) {
T_4 V_330 = V_2 -> V_5 . V_83 -> V_815 ( V_2 , V_315 , V_76 ,
V_49 ) ;
unsigned V_74 = V_315 & ( V_87 - 1 ) ;
unsigned V_820 = F_207 ( V_818 , ( unsigned ) V_87 - V_74 ) ;
int V_88 ;
if ( V_330 == V_80 )
return V_821 ;
V_88 = F_87 ( V_2 -> V_29 , V_330 , V_31 , V_820 ) ;
if ( V_88 < 0 ) {
V_99 = V_822 ;
goto V_93;
}
V_818 -= V_820 ;
V_31 += V_820 ;
V_315 += V_820 ;
}
V_93:
return V_99 ;
}
static int F_285 ( struct V_823 * V_824 ,
T_12 V_315 , void * V_160 , unsigned int V_818 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_286 ( V_824 ) ;
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
return F_284 ( V_315 , V_160 , V_818 , V_2 ,
V_76 | V_817 ,
V_49 ) ;
}
int F_287 ( struct V_823 * V_824 ,
T_12 V_315 , void * V_160 , unsigned int V_818 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_286 ( V_824 ) ;
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
return F_284 ( V_315 , V_160 , V_818 , V_2 , V_76 ,
V_49 ) ;
}
static int F_288 ( struct V_823 * V_824 ,
T_12 V_315 , void * V_160 , unsigned int V_818 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_286 ( V_824 ) ;
return F_284 ( V_315 , V_160 , V_818 , V_2 , 0 , V_49 ) ;
}
int F_289 ( struct V_823 * V_824 ,
T_12 V_315 , void * V_160 ,
unsigned int V_818 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_286 ( V_824 ) ;
void * V_31 = V_160 ;
int V_99 = V_819 ;
while ( V_818 ) {
T_4 V_330 = V_2 -> V_5 . V_83 -> V_815 ( V_2 , V_315 ,
V_92 ,
V_49 ) ;
unsigned V_74 = V_315 & ( V_87 - 1 ) ;
unsigned V_825 = F_207 ( V_818 , ( unsigned ) V_87 - V_74 ) ;
int V_88 ;
if ( V_330 == V_80 )
return V_821 ;
V_88 = F_88 ( V_2 -> V_29 , V_330 , V_31 , V_825 ) ;
if ( V_88 < 0 ) {
V_99 = V_822 ;
goto V_93;
}
V_818 -= V_825 ;
V_31 += V_825 ;
V_315 += V_825 ;
}
V_93:
return V_99 ;
}
static int F_290 ( struct V_1 * V_2 , unsigned long V_816 ,
T_4 * V_330 , struct V_58 * V_49 ,
bool V_826 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
if ( F_291 ( V_2 , V_816 ) &&
F_292 ( V_2 , V_826 , V_76 ,
V_2 -> V_5 . V_76 ) ) {
* V_330 = V_2 -> V_5 . V_827 << V_86 |
( V_816 & ( V_87 - 1 ) ) ;
F_293 ( V_816 , * V_330 , V_826 , false ) ;
return 1 ;
}
if ( V_826 )
V_76 |= V_92 ;
* V_330 = V_2 -> V_5 . V_83 -> V_815 ( V_2 , V_816 , V_76 , V_49 ) ;
if ( * V_330 == V_80 )
return - 1 ;
if ( ( * V_330 & V_303 ) == V_828 )
return 1 ;
if ( F_294 ( V_2 , * V_330 ) ) {
F_293 ( V_816 , * V_330 , V_826 , true ) ;
return 1 ;
}
return 0 ;
}
int F_295 ( struct V_1 * V_2 , T_4 V_330 ,
const void * V_160 , int V_818 )
{
int V_88 ;
V_88 = F_88 ( V_2 -> V_29 , V_330 , V_160 , V_818 ) ;
if ( V_88 < 0 )
return 0 ;
F_296 ( V_2 , V_330 , V_160 , V_818 , 1 ) ;
return 1 ;
}
static int F_297 ( struct V_1 * V_2 , void * V_160 , int V_818 )
{
if ( V_2 -> V_829 ) {
memcpy ( V_160 , V_2 -> V_830 , V_818 ) ;
F_275 ( V_808 , V_818 ,
V_2 -> V_831 , * ( T_2 * ) V_160 ) ;
V_2 -> V_829 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_298 ( struct V_1 * V_2 , T_4 V_330 ,
void * V_160 , int V_818 )
{
return ! F_87 ( V_2 -> V_29 , V_330 , V_160 , V_818 ) ;
}
static int F_299 ( struct V_1 * V_2 , T_4 V_330 ,
void * V_160 , int V_818 )
{
return F_295 ( V_2 , V_330 , V_160 , V_818 ) ;
}
static int F_300 ( struct V_1 * V_2 , T_4 V_330 , int V_818 , void * V_160 )
{
F_275 ( V_832 , V_818 , V_330 , * ( T_2 * ) V_160 ) ;
return F_269 ( V_2 , V_330 , V_818 , V_160 ) ;
}
static int F_301 ( struct V_1 * V_2 , T_4 V_330 ,
void * V_160 , int V_818 )
{
F_275 ( V_833 , V_818 , V_330 , 0 ) ;
return V_822 ;
}
static int F_302 ( struct V_1 * V_2 , T_4 V_330 ,
void * V_160 , int V_818 )
{
memcpy ( V_2 -> V_830 , V_160 , V_818 ) ;
memcpy ( V_2 -> V_834 -> V_835 . V_31 , V_2 -> V_830 , 8 ) ;
return V_819 ;
}
static int F_303 ( unsigned long V_315 , void * V_160 ,
unsigned int V_818 ,
struct V_58 * V_49 ,
struct V_1 * V_2 ,
struct V_836 * V_837 )
{
T_4 V_330 ;
int V_805 , V_88 ;
bool V_826 = V_837 -> V_826 ;
if ( V_837 -> V_838 &&
V_837 -> V_838 ( V_2 , V_160 , V_818 ) )
return V_819 ;
V_88 = F_290 ( V_2 , V_315 , & V_330 , V_49 , V_826 ) ;
if ( V_88 < 0 )
return V_821 ;
if ( V_88 )
goto V_835;
if ( V_837 -> V_839 ( V_2 , V_330 , V_160 , V_818 ) )
return V_819 ;
V_835:
V_805 = V_837 -> V_840 ( V_2 , V_330 , V_818 , V_160 ) ;
if ( V_805 == V_818 )
return V_819 ;
V_330 += V_805 ;
V_818 -= V_805 ;
V_160 += V_805 ;
V_2 -> V_841 = 1 ;
V_2 -> V_834 -> V_842 = V_843 ;
V_2 -> V_834 -> V_835 . V_844 = V_2 -> V_831 = V_330 ;
V_2 -> V_845 = V_818 ;
V_2 -> V_834 -> V_835 . V_75 = F_207 ( V_2 -> V_845 , 8 ) ;
V_2 -> V_834 -> V_835 . V_846 = V_2 -> V_847 = V_826 ;
V_2 -> V_848 = 0 ;
return V_837 -> V_849 ( V_2 , V_330 , V_160 , V_818 ) ;
}
int F_304 ( struct V_823 * V_824 , unsigned long V_315 ,
void * V_160 , unsigned int V_818 ,
struct V_58 * V_49 ,
struct V_836 * V_837 )
{
struct V_1 * V_2 = F_286 ( V_824 ) ;
if ( ( ( V_315 + V_818 - 1 ) ^ V_315 ) & V_303 ) {
int V_850 , V_851 ;
V_851 = - V_315 & ~ V_303 ;
V_850 = F_303 ( V_315 , V_160 , V_851 , V_49 ,
V_2 , V_837 ) ;
if ( V_850 != V_819 )
return V_850 ;
V_315 += V_851 ;
V_160 += V_851 ;
V_818 -= V_851 ;
}
return F_303 ( V_315 , V_160 , V_818 , V_49 ,
V_2 , V_837 ) ;
}
static int F_305 ( struct V_823 * V_824 ,
unsigned long V_315 ,
void * V_160 ,
unsigned int V_818 ,
struct V_58 * V_49 )
{
return F_304 ( V_824 , V_315 , V_160 , V_818 ,
V_49 , & V_852 ) ;
}
int F_306 ( struct V_823 * V_824 ,
unsigned long V_315 ,
const void * V_160 ,
unsigned int V_818 ,
struct V_58 * V_49 )
{
return F_304 ( V_824 , V_315 , ( void * ) V_160 , V_818 ,
V_49 , & V_853 ) ;
}
static int F_307 ( struct V_823 * V_824 ,
unsigned long V_315 ,
const void * V_854 ,
const void * V_855 ,
unsigned int V_818 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_286 ( V_824 ) ;
T_4 V_330 ;
struct V_305 * V_305 ;
char * V_856 ;
bool V_857 ;
if ( V_818 > 8 || ( V_818 & ( V_818 - 1 ) ) )
goto V_858;
V_330 = F_282 ( V_2 , V_315 , NULL ) ;
if ( V_330 == V_80 ||
( V_330 & V_303 ) == V_828 )
goto V_858;
if ( ( ( V_330 + V_818 - 1 ) & V_303 ) != ( V_330 & V_303 ) )
goto V_858;
V_305 = F_154 ( V_2 -> V_29 , V_330 >> V_86 ) ;
if ( F_155 ( V_305 ) ) {
F_156 ( V_305 ) ;
goto V_858;
}
V_856 = F_119 ( V_305 , V_257 ) ;
V_856 += F_308 ( V_330 ) ;
switch ( V_818 ) {
case 1 :
V_857 = F_309 ( T_10 , V_856 , V_854 , V_855 ) ;
break;
case 2 :
V_857 = F_309 ( V_859 , V_856 , V_854 , V_855 ) ;
break;
case 4 :
V_857 = F_309 ( T_1 , V_856 , V_854 , V_855 ) ;
break;
case 8 :
V_857 = F_310 ( V_856 , V_854 , V_855 ) ;
break;
default:
F_311 () ;
}
F_120 ( V_856 , V_257 ) ;
F_146 ( V_305 ) ;
if ( ! V_857 )
return V_860 ;
F_296 ( V_2 , V_330 , V_855 , V_818 , 1 ) ;
return V_819 ;
V_858:
F_107 ( V_220 L_22 ) ;
return F_306 ( V_824 , V_315 , V_855 , V_818 , V_49 ) ;
}
static int F_312 ( struct V_1 * V_2 , void * V_861 )
{
int V_99 ;
if ( V_2 -> V_5 . V_862 . V_863 )
V_99 = F_274 ( V_2 -> V_29 , V_770 , V_2 -> V_5 . V_862 . V_864 ,
V_2 -> V_5 . V_862 . V_413 , V_861 ) ;
else
V_99 = F_271 ( V_2 -> V_29 , V_770 ,
V_2 -> V_5 . V_862 . V_864 , V_2 -> V_5 . V_862 . V_413 ,
V_861 ) ;
return V_99 ;
}
static int F_313 ( struct V_823 * V_824 ,
int V_413 , unsigned short V_864 , void * V_160 ,
unsigned int V_735 )
{
struct V_1 * V_2 = F_286 ( V_824 ) ;
if ( V_2 -> V_5 . V_862 . V_735 )
goto V_865;
F_314 ( 0 , V_864 , V_413 , V_735 ) ;
V_2 -> V_5 . V_862 . V_864 = V_864 ;
V_2 -> V_5 . V_862 . V_863 = 1 ;
V_2 -> V_5 . V_862 . V_735 = V_735 ;
V_2 -> V_5 . V_862 . V_413 = V_413 ;
if ( ! F_312 ( V_2 , V_2 -> V_5 . V_866 ) ) {
V_865:
memcpy ( V_160 , V_2 -> V_5 . V_866 , V_413 * V_735 ) ;
V_2 -> V_5 . V_862 . V_735 = 0 ;
return 1 ;
}
V_2 -> V_834 -> V_842 = V_867 ;
V_2 -> V_834 -> V_868 . V_869 = V_870 ;
V_2 -> V_834 -> V_868 . V_413 = V_413 ;
V_2 -> V_834 -> V_868 . V_871 = V_872 * V_87 ;
V_2 -> V_834 -> V_868 . V_735 = V_735 ;
V_2 -> V_834 -> V_868 . V_864 = V_864 ;
return 0 ;
}
static int F_315 ( struct V_823 * V_824 ,
int V_413 , unsigned short V_864 ,
const void * V_160 , unsigned int V_735 )
{
struct V_1 * V_2 = F_286 ( V_824 ) ;
F_314 ( 1 , V_864 , V_413 , V_735 ) ;
V_2 -> V_5 . V_862 . V_864 = V_864 ;
V_2 -> V_5 . V_862 . V_863 = 0 ;
V_2 -> V_5 . V_862 . V_735 = V_735 ;
V_2 -> V_5 . V_862 . V_413 = V_413 ;
memcpy ( V_2 -> V_5 . V_866 , V_160 , V_413 * V_735 ) ;
if ( ! F_312 ( V_2 , V_2 -> V_5 . V_866 ) ) {
V_2 -> V_5 . V_862 . V_735 = 0 ;
return 1 ;
}
V_2 -> V_834 -> V_842 = V_867 ;
V_2 -> V_834 -> V_868 . V_869 = V_873 ;
V_2 -> V_834 -> V_868 . V_413 = V_413 ;
V_2 -> V_834 -> V_868 . V_871 = V_872 * V_87 ;
V_2 -> V_834 -> V_868 . V_735 = V_735 ;
V_2 -> V_834 -> V_868 . V_864 = V_864 ;
return 0 ;
}
static unsigned long F_316 ( struct V_1 * V_2 , int V_811 )
{
return V_56 -> F_316 ( V_2 , V_811 ) ;
}
static void F_317 ( struct V_823 * V_824 , V_155 V_63 )
{
F_318 ( F_286 ( V_824 ) , V_63 ) ;
}
int F_319 ( struct V_1 * V_2 )
{
if ( ! F_185 ( V_2 ) )
return V_819 ;
if ( V_56 -> V_490 () ) {
int V_216 = F_100 () ;
F_187 ( V_216 , V_2 -> V_5 . V_491 ) ;
F_320 ( V_2 -> V_5 . V_491 ,
F_183 , NULL , 1 ) ;
F_103 () ;
F_321 ( V_2 -> V_5 . V_491 ) ;
} else
F_184 () ;
return V_819 ;
}
static void F_322 ( struct V_823 * V_824 )
{
F_319 ( F_286 ( V_824 ) ) ;
}
int F_323 ( struct V_823 * V_824 , int V_159 , unsigned long * V_874 )
{
return F_80 ( F_286 ( V_824 ) , V_159 , V_874 ) ;
}
int F_324 ( struct V_823 * V_824 , int V_159 , unsigned long V_23 )
{
return F_78 ( F_286 ( V_824 ) , V_159 , V_23 ) ;
}
static T_2 F_325 ( T_2 V_875 , T_1 V_876 )
{
return ( V_875 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_876 ;
}
static unsigned long F_326 ( struct V_823 * V_824 , int V_877 )
{
struct V_1 * V_2 = F_286 ( V_824 ) ;
unsigned long V_23 ;
switch ( V_877 ) {
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
V_23 = F_68 ( V_2 ) ;
break;
case 8 :
V_23 = F_76 ( V_2 ) ;
break;
default:
F_327 ( V_2 , L_23 , V_214 , V_877 ) ;
return 0 ;
}
return V_23 ;
}
static int F_328 ( struct V_823 * V_824 , int V_877 , V_155 V_160 )
{
struct V_1 * V_2 = F_286 ( V_824 ) ;
int V_175 = 0 ;
switch ( V_877 ) {
case 0 :
V_175 = F_50 ( V_2 , F_325 ( F_51 ( V_2 ) , V_160 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_62 = V_160 ;
break;
case 3 :
V_175 = F_69 ( V_2 , V_160 ) ;
break;
case 4 :
V_175 = F_67 ( V_2 , F_325 ( F_68 ( V_2 ) , V_160 ) ) ;
break;
case 8 :
V_175 = F_74 ( V_2 , V_160 ) ;
break;
default:
F_327 ( V_2 , L_23 , V_214 , V_877 ) ;
V_175 = - 1 ;
}
return V_175 ;
}
static int F_329 ( struct V_823 * V_824 )
{
return V_56 -> V_71 ( F_286 ( V_824 ) ) ;
}
static void F_330 ( struct V_823 * V_824 , struct V_878 * V_879 )
{
V_56 -> V_880 ( F_286 ( V_824 ) , V_879 ) ;
}
static void F_331 ( struct V_823 * V_824 , struct V_878 * V_879 )
{
V_56 -> V_881 ( F_286 ( V_824 ) , V_879 ) ;
}
static void F_332 ( struct V_823 * V_824 , struct V_878 * V_879 )
{
V_56 -> V_882 ( F_286 ( V_824 ) , V_879 ) ;
}
static void F_333 ( struct V_823 * V_824 , struct V_878 * V_879 )
{
V_56 -> V_883 ( F_286 ( V_824 ) , V_879 ) ;
}
static unsigned long F_334 (
struct V_823 * V_824 , int V_811 )
{
return F_316 ( F_286 ( V_824 ) , V_811 ) ;
}
static bool F_335 ( struct V_823 * V_824 , V_859 * V_884 ,
struct V_885 * V_886 , T_1 * V_887 ,
int V_811 )
{
struct V_809 V_810 ;
F_277 ( F_286 ( V_824 ) , & V_810 , V_811 ) ;
* V_884 = V_810 . V_884 ;
if ( V_810 . V_888 )
return false ;
if ( V_810 . V_889 )
V_810 . V_611 >>= 12 ;
F_336 ( V_886 , V_810 . V_611 ) ;
F_337 ( V_886 , ( unsigned long ) V_810 . V_890 ) ;
#ifdef F_52
if ( V_887 )
* V_887 = V_810 . V_890 >> 32 ;
#endif
V_886 -> type = V_810 . type ;
V_886 -> V_616 = V_810 . V_616 ;
V_886 -> V_891 = V_810 . V_891 ;
V_886 -> V_274 = V_810 . V_892 ;
V_886 -> V_893 = V_810 . V_893 ;
V_886 -> V_894 = V_810 . V_894 ;
V_886 -> V_895 = V_810 . V_161 ;
V_886 -> V_889 = V_810 . V_889 ;
return true ;
}
static void F_338 ( struct V_823 * V_824 , V_859 V_884 ,
struct V_885 * V_886 , T_1 V_887 ,
int V_811 )
{
struct V_1 * V_2 = F_286 ( V_824 ) ;
struct V_809 V_810 ;
V_810 . V_884 = V_884 ;
V_810 . V_890 = F_339 ( V_886 ) ;
#ifdef F_52
V_810 . V_890 |= ( ( T_2 ) V_887 ) << 32 ;
#endif
V_810 . V_611 = F_340 ( V_886 ) ;
if ( V_886 -> V_889 )
V_810 . V_611 = ( V_810 . V_611 << 12 ) | 0xfff ;
V_810 . type = V_886 -> type ;
V_810 . V_892 = V_886 -> V_274 ;
V_810 . V_891 = V_886 -> V_891 ;
V_810 . V_161 = V_886 -> V_895 ;
V_810 . V_616 = V_886 -> V_616 ;
V_810 . V_894 = V_886 -> V_894 ;
V_810 . V_889 = V_886 -> V_889 ;
V_810 . V_893 = V_886 -> V_893 ;
V_810 . V_892 = V_886 -> V_274 ;
V_810 . V_888 = ! V_810 . V_892 ;
V_810 . V_505 = 0 ;
F_276 ( V_2 , & V_810 , V_811 ) ;
return;
}
static int F_341 ( struct V_823 * V_824 ,
T_1 V_190 , T_2 * V_388 )
{
return F_162 ( F_286 ( V_824 ) , V_190 , V_388 ) ;
}
static int F_342 ( struct V_823 * V_824 ,
T_1 V_190 , T_2 V_31 )
{
return F_84 ( F_286 ( V_824 ) , V_190 , V_31 ) ;
}
static void F_343 ( struct V_823 * V_824 )
{
F_286 ( V_824 ) -> V_5 . V_896 = 1 ;
}
static void F_344 ( struct V_823 * V_824 )
{
F_158 () ;
F_345 ( F_286 ( V_824 ) ) ;
F_346 () ;
}
static void F_347 ( struct V_823 * V_824 )
{
F_159 () ;
}
static int F_348 ( struct V_823 * V_824 ,
struct V_897 * V_898 ,
enum V_899 V_900 )
{
return V_56 -> V_901 ( F_286 ( V_824 ) , V_898 , V_900 ) ;
}
static void F_349 ( struct V_1 * V_2 )
{
F_350 ( V_2 , V_902 ) ;
F_350 ( V_2 , V_903 ) ;
F_350 ( V_2 , V_904 ) ;
V_2 -> V_5 . V_97 = ~ 0 ;
}
static void F_351 ( struct V_1 * V_2 , T_1 V_26 )
{
T_1 V_905 = V_56 -> V_643 ( V_2 , V_26 ) ;
if ( ! ( V_905 & V_26 ) )
V_56 -> V_656 ( V_2 , V_26 ) ;
}
static void F_352 ( struct V_1 * V_2 )
{
struct V_823 * V_824 = & V_2 -> V_5 . V_906 ;
if ( V_824 -> V_49 . V_32 == V_33 )
F_30 ( V_2 , & V_824 -> V_49 ) ;
else if ( V_824 -> V_49 . V_907 )
F_29 ( V_2 , V_824 -> V_49 . V_32 ,
V_824 -> V_49 . V_43 ) ;
else
F_24 ( V_2 , V_824 -> V_49 . V_32 ) ;
}
static void F_353 ( struct V_823 * V_824 ,
const unsigned long * V_617 )
{
memset ( & V_824 -> V_908 , 0 ,
( void * ) & V_824 -> V_617 - ( void * ) & V_824 -> V_908 ) ;
memcpy ( V_824 -> V_617 , V_617 , sizeof( V_824 -> V_617 ) ) ;
V_824 -> V_909 . V_737 = 0 ;
V_824 -> V_909 . V_910 = 0 ;
V_824 -> V_911 . V_912 = 0 ;
V_824 -> V_911 . V_910 = 0 ;
V_824 -> V_913 . V_912 = 0 ;
V_824 -> V_913 . V_910 = 0 ;
}
static void F_354 ( struct V_1 * V_2 )
{
struct V_823 * V_824 = & V_2 -> V_5 . V_906 ;
int V_112 , V_113 ;
F_349 ( V_2 ) ;
V_56 -> V_114 ( V_2 , & V_112 , & V_113 ) ;
V_824 -> V_914 = F_355 ( V_2 ) ;
V_824 -> V_915 = F_356 ( V_2 ) ;
V_824 -> V_916 = ( ! F_357 ( V_2 ) ) ? V_917 :
( V_824 -> V_914 & V_918 ) ? V_919 :
V_113 ? V_920 :
V_112 ? V_921 :
V_922 ;
V_824 -> V_923 = F_358 ( V_2 ) ;
F_353 ( V_824 , V_2 -> V_5 . V_617 ) ;
V_2 -> V_5 . V_924 = false ;
}
int F_359 ( struct V_1 * V_2 , int V_619 , int V_925 )
{
struct V_823 * V_824 = & V_2 -> V_5 . V_906 ;
int V_88 ;
F_354 ( V_2 ) ;
V_824 -> V_926 = 2 ;
V_824 -> V_927 = 2 ;
V_824 -> V_928 = V_824 -> V_915 + V_925 ;
V_88 = F_360 ( V_824 , V_619 ) ;
if ( V_88 != V_819 )
return V_929 ;
V_824 -> V_915 = V_824 -> V_928 ;
memcpy ( V_2 -> V_5 . V_617 , V_824 -> V_617 , sizeof V_824 -> V_617 ) ;
F_361 ( V_2 , V_824 -> V_915 ) ;
F_362 ( V_2 , V_824 -> V_914 ) ;
if ( V_619 == V_930 )
V_2 -> V_5 . V_648 = 0 ;
else
V_2 -> V_5 . V_640 . V_50 = false ;
return V_931 ;
}
static int F_363 ( struct V_1 * V_2 )
{
int V_99 = V_931 ;
++ V_2 -> V_60 . V_932 ;
F_364 ( V_2 ) ;
if ( ! F_358 ( V_2 ) ) {
V_2 -> V_834 -> V_842 = V_933 ;
V_2 -> V_834 -> V_934 . V_935 = V_936 ;
V_2 -> V_834 -> V_934 . V_937 = 0 ;
V_99 = V_929 ;
}
F_24 ( V_2 , V_176 ) ;
return V_99 ;
}
static bool F_365 ( struct V_1 * V_2 , T_12 V_816 )
{
T_4 V_330 ;
if ( V_189 )
return false ;
if ( F_366 ( V_2 , V_816 ) )
return true ;
V_330 = F_283 ( V_2 , V_816 , NULL ) ;
if ( V_330 == V_80 )
return true ;
if ( ! F_136 ( F_135 ( V_2 -> V_29 , V_330 >> V_86 ) ) )
return true ;
return false ;
}
int F_367 ( struct V_1 * V_2 ,
unsigned long V_62 ,
int V_938 ,
void * V_939 ,
int V_940 )
{
int V_99 ;
struct V_823 * V_824 = & V_2 -> V_5 . V_906 ;
bool V_411 = true ;
F_368 ( V_2 ) ;
if ( ! ( V_938 & V_941 ) ) {
F_354 ( V_2 ) ;
V_824 -> V_942 = 0 ;
V_824 -> V_943 = false ;
V_824 -> V_944 = false ;
V_824 -> V_945
= V_938 & V_946 ;
V_99 = F_369 ( V_824 , V_939 , V_940 ) ;
F_370 ( V_2 ) ;
++ V_2 -> V_60 . V_947 ;
if ( V_99 != V_948 ) {
if ( V_938 & V_946 )
return V_929 ;
if ( F_365 ( V_2 , V_62 ) )
return V_931 ;
if ( V_938 & V_949 )
return V_929 ;
return F_363 ( V_2 ) ;
}
}
if ( V_938 & V_949 ) {
F_361 ( V_2 , V_824 -> V_928 ) ;
return V_931 ;
}
if ( V_2 -> V_5 . V_924 ) {
V_2 -> V_5 . V_924 = false ;
memcpy ( V_824 -> V_617 , V_2 -> V_5 . V_617 , sizeof V_824 -> V_617 ) ;
}
V_950:
V_99 = F_371 ( V_824 ) ;
if ( V_99 == V_951 )
return V_931 ;
if ( V_99 == V_952 ) {
if ( F_365 ( V_2 , V_62 ) )
return V_931 ;
return F_363 ( V_2 ) ;
}
if ( V_824 -> V_943 ) {
F_352 ( V_2 ) ;
V_99 = V_931 ;
} else if ( V_2 -> V_5 . V_862 . V_735 ) {
if ( ! V_2 -> V_5 . V_862 . V_863 )
V_2 -> V_5 . V_862 . V_735 = 0 ;
else
V_411 = false ;
V_99 = V_953 ;
} else if ( V_2 -> V_841 ) {
if ( ! V_2 -> V_847 )
V_411 = false ;
V_99 = V_953 ;
} else if ( V_99 == V_954 )
goto V_950;
else
V_99 = V_931 ;
if ( V_411 ) {
F_351 ( V_2 , V_824 -> V_942 ) ;
F_362 ( V_2 , V_824 -> V_914 ) ;
F_23 ( V_48 , V_2 ) ;
memcpy ( V_2 -> V_5 . V_617 , V_824 -> V_617 , sizeof V_824 -> V_617 ) ;
V_2 -> V_5 . V_955 = false ;
F_361 ( V_2 , V_824 -> V_915 ) ;
} else
V_2 -> V_5 . V_955 = true ;
return V_99 ;
}
int F_372 ( struct V_1 * V_2 , int V_413 , unsigned short V_864 )
{
unsigned long V_160 = F_350 ( V_2 , V_902 ) ;
int V_88 = F_315 ( & V_2 -> V_5 . V_906 ,
V_413 , V_864 , & V_160 , 1 ) ;
V_2 -> V_5 . V_862 . V_735 = 0 ;
return V_88 ;
}
static void F_373 ( void * V_898 )
{
F_374 ( V_219 , 0 ) ;
}
static void F_375 ( void * V_31 )
{
struct V_956 * V_957 = V_31 ;
unsigned long V_958 = 0 ;
if ( V_31 )
V_958 = V_957 -> V_855 ;
else if ( ! F_101 ( V_217 ) )
V_958 = F_102 ( F_376 () ) ;
if ( ! V_958 )
V_958 = V_959 ;
F_374 ( V_219 , V_958 ) ;
}
static int F_377 ( struct V_960 * V_961 , unsigned long V_160 ,
void * V_31 )
{
struct V_956 * V_957 = V_31 ;
struct V_29 * V_29 ;
struct V_1 * V_2 ;
int V_3 , V_962 = 0 ;
if ( V_160 == V_963 && V_957 -> V_854 > V_957 -> V_855 )
return 0 ;
if ( V_160 == V_964 && V_957 -> V_854 < V_957 -> V_855 )
return 0 ;
F_188 ( V_957 -> V_216 , F_375 , V_957 , 1 ) ;
F_378 ( & V_965 ) ;
F_379 (kvm, &vm_list, vm_list) {
F_167 (i, vcpu, kvm) {
if ( V_2 -> V_216 != V_957 -> V_216 )
continue;
F_23 ( V_246 , V_2 ) ;
if ( V_2 -> V_216 != F_380 () )
V_962 = 1 ;
}
}
F_381 ( & V_965 ) ;
if ( V_957 -> V_854 < V_957 -> V_855 && V_962 ) {
F_188 ( V_957 -> V_216 , F_375 , V_957 , 1 ) ;
}
return 0 ;
}
static int F_382 ( struct V_960 * V_966 ,
unsigned long V_967 , void * V_968 )
{
unsigned int V_216 = ( unsigned long ) V_968 ;
switch ( V_967 ) {
case V_969 :
case V_970 :
F_188 ( V_216 , F_375 , NULL , 1 ) ;
break;
case V_971 :
F_188 ( V_216 , F_373 , NULL , 1 ) ;
break;
}
return V_972 ;
}
static void F_383 ( void )
{
int V_216 ;
V_973 = V_959 ;
F_384 ( & V_974 ) ;
if ( ! F_101 ( V_217 ) ) {
#ifdef F_385
struct V_975 V_976 ;
memset ( & V_976 , 0 , sizeof( V_976 ) ) ;
V_216 = F_100 () ;
F_386 ( & V_976 , V_216 ) ;
if ( V_976 . V_977 . V_978 )
V_973 = V_976 . V_977 . V_978 ;
F_103 () ;
#endif
F_387 ( & V_979 ,
V_980 ) ;
}
F_92 ( L_24 , V_973 ) ;
F_388 (cpu)
F_188 ( V_216 , F_375 , NULL , 1 ) ;
}
static int F_389 ( void )
{
return F_390 ( V_981 ) != NULL ;
}
static int F_391 ( void )
{
int V_982 = 3 ;
if ( F_390 ( V_981 ) )
V_982 = V_56 -> V_71 ( F_390 ( V_981 ) ) ;
return V_982 != 0 ;
}
static unsigned long F_392 ( void )
{
unsigned long V_983 = 0 ;
if ( F_390 ( V_981 ) )
V_983 = F_356 ( F_390 ( V_981 ) ) ;
return V_983 ;
}
void F_393 ( struct V_1 * V_2 )
{
F_394 ( V_981 , V_2 ) ;
}
void F_395 ( struct V_1 * V_2 )
{
F_394 ( V_981 , NULL ) ;
}
static void F_396 ( void )
{
T_2 V_26 ;
int V_984 = V_509 . V_985 ;
V_26 = ( ( 1ull << ( 62 - V_984 + 1 ) ) - 1 ) << V_984 ;
V_26 |= 1ull ;
#ifdef F_52
if ( V_984 == 52 )
V_26 &= ~ 1ull ;
#endif
F_397 ( V_26 ) ;
}
int F_398 ( void * V_986 )
{
int V_99 ;
struct V_56 * V_837 = (struct V_56 * ) V_986 ;
if ( V_56 ) {
F_9 ( V_25 L_25 ) ;
V_99 = - V_768 ;
goto V_93;
}
if ( ! V_837 -> V_987 () ) {
F_9 ( V_25 L_26 ) ;
V_99 = - V_988 ;
goto V_93;
}
if ( V_837 -> V_989 () ) {
F_9 ( V_25 L_27 ) ;
V_99 = - V_988 ;
goto V_93;
}
V_99 = F_399 () ;
if ( V_99 )
goto V_93;
F_396 () ;
F_267 () ;
V_56 = V_837 ;
F_400 ( V_990 , V_991 ,
V_992 , V_993 , 0 ) ;
F_383 () ;
F_401 ( & V_994 ) ;
if ( V_135 )
V_124 = F_402 ( V_120 ) ;
return 0 ;
V_93:
return V_99 ;
}
void F_403 ( void )
{
F_404 ( & V_994 ) ;
if ( ! F_101 ( V_217 ) )
F_405 ( & V_979 ,
V_980 ) ;
F_406 ( & V_974 ) ;
V_56 = NULL ;
F_407 () ;
}
int F_408 ( struct V_1 * V_2 )
{
++ V_2 -> V_60 . V_995 ;
if ( F_18 ( V_2 -> V_29 ) ) {
V_2 -> V_5 . V_996 = V_997 ;
return 1 ;
} else {
V_2 -> V_834 -> V_842 = V_998 ;
return 0 ;
}
}
static inline T_4 F_409 ( struct V_1 * V_2 , unsigned long V_999 ,
unsigned long V_1000 )
{
if ( F_46 ( V_2 ) )
return V_999 ;
else
return V_999 | ( ( T_4 ) V_1000 << 32 ) ;
}
int F_410 ( struct V_1 * V_2 )
{
T_2 V_1001 , V_1002 , V_1003 , V_88 ;
T_13 V_1004 , V_1005 , V_1006 , V_175 = V_1007 , V_1008 = 0 ;
bool V_1009 , V_1010 ;
int V_112 , V_113 ;
if ( V_56 -> V_71 ( V_2 ) != 0 || ! F_357 ( V_2 ) ) {
F_24 ( V_2 , V_176 ) ;
return 0 ;
}
V_56 -> V_114 ( V_2 , & V_112 , & V_113 ) ;
V_1010 = F_46 ( V_2 ) && V_113 == 1 ;
if ( ! V_1010 ) {
V_1001 = ( ( T_2 ) F_350 ( V_2 , V_1011 ) << 32 ) |
( F_350 ( V_2 , V_902 ) & 0xffffffff ) ;
V_1002 = ( ( T_2 ) F_350 ( V_2 , V_1012 ) << 32 ) |
( F_350 ( V_2 , V_1013 ) & 0xffffffff ) ;
V_1003 = ( ( T_2 ) F_350 ( V_2 , V_1014 ) << 32 ) |
( F_350 ( V_2 , V_1015 ) & 0xffffffff ) ;
}
#ifdef F_52
else {
V_1001 = F_350 ( V_2 , V_1013 ) ;
V_1002 = F_350 ( V_2 , V_1011 ) ;
V_1003 = F_350 ( V_2 , V_1016 ) ;
}
#endif
V_1004 = V_1001 & 0xffff ;
V_1009 = ( V_1001 >> 16 ) & 0x1 ;
V_1006 = ( V_1001 >> 32 ) & 0xfff ;
V_1005 = ( V_1001 >> 48 ) & 0xfff ;
F_411 ( V_1004 , V_1009 , V_1006 , V_1005 , V_1002 , V_1003 ) ;
switch ( V_1004 ) {
case V_1017 :
F_412 ( V_2 ) ;
break;
default:
V_175 = V_1018 ;
break;
}
V_88 = V_175 | ( ( ( T_2 ) V_1008 & 0xfff ) << 32 ) ;
if ( V_1010 ) {
F_413 ( V_2 , V_902 , V_88 ) ;
} else {
F_413 ( V_2 , V_1011 , V_88 >> 32 ) ;
F_413 ( V_2 , V_902 , V_88 & 0xffffffff ) ;
}
return 1 ;
}
int F_414 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_999 , V_1000 , V_1019 , V_1020 , V_88 ;
int V_99 = 1 ;
if ( F_132 ( V_2 -> V_29 ) )
return F_410 ( V_2 ) ;
V_16 = F_350 ( V_2 , V_902 ) ;
V_999 = F_350 ( V_2 , V_1012 ) ;
V_1000 = F_350 ( V_2 , V_1013 ) ;
V_1019 = F_350 ( V_2 , V_1011 ) ;
V_1020 = F_350 ( V_2 , V_1015 ) ;
F_415 ( V_16 , V_999 , V_1000 , V_1019 , V_1020 ) ;
if ( ! F_46 ( V_2 ) ) {
V_16 &= 0xFFFFFFFF ;
V_999 &= 0xFFFFFFFF ;
V_1000 &= 0xFFFFFFFF ;
V_1019 &= 0xFFFFFFFF ;
V_1020 &= 0xFFFFFFFF ;
}
if ( V_56 -> V_71 ( V_2 ) != 0 ) {
V_88 = - V_1021 ;
goto V_93;
}
switch ( V_16 ) {
case V_1022 :
V_88 = 0 ;
break;
case V_1023 :
V_99 = F_416 ( V_2 , V_999 , F_409 ( V_2 , V_1000 , V_1019 ) , & V_88 ) ;
break;
default:
V_88 = - V_1024 ;
break;
}
V_93:
F_413 ( V_2 , V_902 , V_88 ) ;
++ V_2 -> V_60 . V_1025 ;
return V_99 ;
}
int F_417 ( struct V_823 * V_824 )
{
struct V_1 * V_2 = F_286 ( V_824 ) ;
char V_1026 [ 3 ] ;
unsigned long V_1027 = F_356 ( V_2 ) ;
F_418 ( V_2 -> V_29 ) ;
V_56 -> V_318 ( V_2 , V_1026 ) ;
return F_306 ( V_824 , V_1027 , V_1026 , 3 , NULL ) ;
}
static int F_419 ( struct V_1 * V_2 , int V_3 )
{
struct V_126 * V_495 = & V_2 -> V_5 . V_498 [ V_3 ] ;
int V_803 , V_502 = V_2 -> V_5 . V_497 ;
V_495 -> V_232 &= ~ V_593 ;
for ( V_803 = V_3 + 1 ; ; V_803 = ( V_803 + 1 ) % V_502 ) {
struct V_126 * V_1028 = & V_2 -> V_5 . V_498 [ V_803 ] ;
if ( V_1028 -> V_136 == V_495 -> V_136 ) {
V_1028 -> V_232 |= V_593 ;
return V_803 ;
}
}
return 0 ;
}
static int F_420 ( struct V_126 * V_495 ,
T_1 V_136 , T_1 V_117 )
{
if ( V_495 -> V_136 != V_136 )
return 0 ;
if ( ( V_495 -> V_232 & V_595 ) && V_495 -> V_117 != V_117 )
return 0 ;
if ( ( V_495 -> V_232 & V_592 ) &&
! ( V_495 -> V_232 & V_593 ) )
return 0 ;
return 1 ;
}
struct V_126 * F_61 ( struct V_1 * V_2 ,
T_1 V_136 , T_1 V_117 )
{
int V_3 ;
struct V_126 * V_127 = NULL ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 . V_497 ; ++ V_3 ) {
struct V_126 * V_495 ;
V_495 = & V_2 -> V_5 . V_498 [ V_3 ] ;
if ( F_420 ( V_495 , V_136 , V_117 ) ) {
if ( V_495 -> V_232 & V_592 )
F_419 ( V_2 , V_3 ) ;
V_127 = V_495 ;
break;
}
}
return V_127 ;
}
int F_421 ( struct V_1 * V_2 )
{
struct V_126 * V_127 ;
V_127 = F_61 ( V_2 , 0x80000000 , 0 ) ;
if ( ! V_127 || V_127 -> V_504 < 0x80000008 )
goto V_1029;
V_127 = F_61 ( V_2 , 0x80000008 , 0 ) ;
if ( V_127 )
return V_127 -> V_504 & 0xff ;
V_1029:
return 36 ;
}
static struct V_126 * F_422 ( struct V_1 * V_2 ,
T_1 V_136 , T_1 V_117 )
{
struct V_126 * V_1030 ;
V_1030 = F_61 ( V_2 , V_136 & 0x80000000 , 0 ) ;
if ( ! V_1030 || V_1030 -> V_504 >= V_136 )
return NULL ;
if ( V_136 & 0x80000000 ) {
V_1030 = F_61 ( V_2 , 0 , 0 ) ;
if ( ! V_1030 )
return NULL ;
}
return F_61 ( V_2 , V_1030 -> V_504 , V_117 ) ;
}
void F_423 ( struct V_1 * V_2 )
{
T_1 V_136 , V_117 ;
struct V_126 * V_127 ;
V_136 = F_350 ( V_2 , V_902 ) ;
V_117 = F_350 ( V_2 , V_1013 ) ;
F_413 ( V_2 , V_902 , 0 ) ;
F_413 ( V_2 , V_1012 , 0 ) ;
F_413 ( V_2 , V_1013 , 0 ) ;
F_413 ( V_2 , V_1011 , 0 ) ;
V_127 = F_61 ( V_2 , V_136 , V_117 ) ;
if ( ! V_127 )
V_127 = F_422 ( V_2 , V_136 , V_117 ) ;
if ( V_127 ) {
F_413 ( V_2 , V_902 , V_127 -> V_504 ) ;
F_413 ( V_2 , V_1012 , V_127 -> V_130 ) ;
F_413 ( V_2 , V_1013 , V_127 -> V_128 ) ;
F_413 ( V_2 , V_1011 , V_127 -> V_181 ) ;
}
V_56 -> V_57 ( V_2 ) ;
F_424 ( V_136 ,
F_350 ( V_2 , V_902 ) ,
F_350 ( V_2 , V_1012 ) ,
F_350 ( V_2 , V_1013 ) ,
F_350 ( V_2 , V_1011 ) ) ;
}
static int F_425 ( struct V_1 * V_2 )
{
return ( ! F_18 ( V_2 -> V_29 ) && ! F_426 ( V_2 ) &&
V_2 -> V_834 -> V_1031 &&
F_427 ( V_2 ) ) ;
}
static void F_428 ( struct V_1 * V_2 )
{
struct V_1032 * V_1032 = V_2 -> V_834 ;
V_1032 -> V_1033 = ( F_355 ( V_2 ) & V_1034 ) != 0 ;
V_1032 -> V_157 = F_76 ( V_2 ) ;
V_1032 -> V_30 = F_17 ( V_2 ) ;
if ( F_18 ( V_2 -> V_29 ) )
V_1032 -> V_1035 = 1 ;
else
V_1032 -> V_1035 =
F_427 ( V_2 ) &&
! F_426 ( V_2 ) &&
! F_429 ( V_2 ) ;
}
static void F_430 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_5 . V_134 ;
struct V_305 * V_305 ;
if ( ! V_134 || ! V_134 -> V_694 )
return;
V_305 = F_154 ( V_2 -> V_29 , V_134 -> V_694 >> V_86 ) ;
V_2 -> V_5 . V_134 -> V_1036 = V_305 ;
}
static void F_431 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_5 . V_134 ;
int V_280 ;
if ( ! V_134 || ! V_134 -> V_694 )
return;
V_280 = F_174 ( & V_2 -> V_29 -> V_408 ) ;
F_146 ( V_134 -> V_1036 ) ;
F_121 ( V_2 -> V_29 , V_134 -> V_694 >> V_86 ) ;
F_175 ( & V_2 -> V_29 -> V_408 , V_280 ) ;
}
static void F_212 ( struct V_1 * V_2 )
{
int V_1037 , V_1038 ;
if ( ! V_56 -> F_212 )
return;
if ( ! V_2 -> V_5 . V_134 )
return;
if ( ! V_2 -> V_5 . V_134 -> V_694 )
V_1037 = F_432 ( V_2 ) ;
else
V_1037 = - 1 ;
if ( V_1037 != - 1 )
V_1037 >>= 4 ;
V_1038 = F_77 ( V_2 ) ;
V_56 -> F_212 ( V_2 , V_1038 , V_1037 ) ;
}
static void F_433 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_49 . V_50 ) {
F_434 ( V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ) ;
V_56 -> V_1039 ( V_2 , V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ,
V_2 -> V_5 . V_49 . V_44 ) ;
return;
}
if ( V_2 -> V_5 . V_647 ) {
V_56 -> V_1040 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_640 . V_50 ) {
V_56 -> V_1041 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_648 ) {
if ( V_56 -> V_1042 ( V_2 ) ) {
-- V_2 -> V_5 . V_648 ;
V_2 -> V_5 . V_647 = true ;
V_56 -> V_1040 ( V_2 ) ;
}
} else if ( F_426 ( V_2 ) ) {
if ( V_56 -> V_1043 ( V_2 ) ) {
F_214 ( V_2 , F_435 ( V_2 ) ,
false ) ;
V_56 -> V_1041 ( V_2 ) ;
}
}
}
static void F_436 ( struct V_1 * V_2 )
{
if ( F_66 ( V_2 , V_138 ) &&
! V_2 -> V_125 ) {
F_437 ( V_120 , V_2 -> V_5 . V_119 ) ;
V_2 -> V_125 = 1 ;
}
}
static void F_438 ( struct V_1 * V_2 )
{
if ( V_2 -> V_125 ) {
if ( V_2 -> V_5 . V_119 != V_124 )
F_437 ( V_120 , V_124 ) ;
V_2 -> V_125 = 0 ;
}
}
static void F_220 ( struct V_1 * V_2 )
{
unsigned V_611 = 2 ;
if ( V_56 -> V_650 ( V_2 ) || V_2 -> V_5 . V_647 )
V_611 = 1 ;
V_2 -> V_5 . V_648 += F_439 ( & V_2 -> V_5 . V_68 , 0 ) ;
V_2 -> V_5 . V_648 = F_207 ( V_2 -> V_5 . V_648 , V_611 ) ;
F_23 ( V_48 , V_2 ) ;
}
static int F_440 ( struct V_1 * V_2 )
{
int V_99 ;
bool V_1044 = ! F_18 ( V_2 -> V_29 ) &&
V_2 -> V_834 -> V_1031 ;
if ( V_2 -> V_1045 ) {
if ( F_441 ( V_1046 , V_2 ) )
F_442 ( V_2 ) ;
if ( F_441 ( V_1047 , V_2 ) )
F_443 ( V_2 ) ;
if ( F_441 ( V_246 , V_2 ) ) {
V_99 = F_116 ( V_2 ) ;
if ( F_72 ( V_99 ) )
goto V_93;
}
if ( F_441 ( V_1048 , V_2 ) )
F_70 ( V_2 ) ;
if ( F_441 ( V_1049 , V_2 ) )
V_56 -> V_1050 ( V_2 ) ;
if ( F_441 ( V_1051 , V_2 ) ) {
V_2 -> V_834 -> V_842 = V_1052 ;
V_99 = 0 ;
goto V_93;
}
if ( F_441 ( V_54 , V_2 ) ) {
V_2 -> V_834 -> V_842 = V_1053 ;
V_99 = 0 ;
goto V_93;
}
if ( F_441 ( V_1054 , V_2 ) ) {
V_2 -> V_1055 = 0 ;
V_56 -> V_1056 ( V_2 ) ;
}
if ( F_441 ( V_1057 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1058 = true ;
V_99 = 1 ;
goto V_93;
}
if ( F_441 ( V_369 , V_2 ) )
F_148 ( V_2 ) ;
if ( F_441 ( V_69 , V_2 ) )
F_220 ( V_2 ) ;
}
V_99 = F_444 ( V_2 ) ;
if ( F_72 ( V_99 ) )
goto V_93;
if ( F_441 ( V_48 , V_2 ) || V_1044 ) {
F_433 ( V_2 ) ;
if ( V_2 -> V_5 . V_648 )
V_56 -> V_1059 ( V_2 ) ;
else if ( F_426 ( V_2 ) || V_1044 )
V_56 -> V_1060 ( V_2 ) ;
if ( F_445 ( V_2 ) ) {
F_212 ( V_2 ) ;
F_446 ( V_2 ) ;
}
}
F_158 () ;
V_56 -> V_1061 ( V_2 ) ;
if ( V_2 -> V_1055 )
F_345 ( V_2 ) ;
F_436 ( V_2 ) ;
V_2 -> V_916 = V_1062 ;
F_447 () ;
F_265 () ;
if ( V_2 -> V_916 == V_1063 || V_2 -> V_1045
|| F_448 () || F_449 ( V_337 ) ) {
V_2 -> V_916 = V_1064 ;
F_12 () ;
F_266 () ;
F_159 () ;
V_56 -> V_1065 ( V_2 ) ;
V_99 = 1 ;
goto V_93;
}
F_175 ( & V_2 -> V_29 -> V_408 , V_2 -> V_1066 ) ;
F_450 () ;
if ( F_72 ( V_2 -> V_5 . V_173 ) ) {
F_451 ( 0 , 7 ) ;
F_451 ( V_2 -> V_5 . V_164 [ 0 ] , 0 ) ;
F_451 ( V_2 -> V_5 . V_164 [ 1 ] , 1 ) ;
F_451 ( V_2 -> V_5 . V_164 [ 2 ] , 2 ) ;
F_451 ( V_2 -> V_5 . V_164 [ 3 ] , 3 ) ;
}
F_452 ( V_2 -> V_1067 ) ;
V_56 -> V_834 ( V_2 ) ;
if ( F_453 () )
F_454 () ;
V_2 -> V_5 . V_250 = V_56 -> V_245 ( V_2 ) ;
V_2 -> V_916 = V_1064 ;
F_12 () ;
F_266 () ;
++ V_2 -> V_60 . V_1068 ;
F_455 () ;
F_456 () ;
F_159 () ;
V_2 -> V_1066 = F_174 ( & V_2 -> V_29 -> V_408 ) ;
if ( F_72 ( V_1069 == V_1070 ) ) {
unsigned long V_1027 = F_356 ( V_2 ) ;
F_457 ( V_1070 , ( void * ) V_1027 ) ;
}
F_458 ( V_2 ) ;
V_99 = V_56 -> V_1071 ( V_2 ) ;
V_93:
return V_99 ;
}
static int F_459 ( struct V_1 * V_2 )
{
int V_99 ;
struct V_29 * V_29 = V_2 -> V_29 ;
if ( F_72 ( V_2 -> V_5 . V_996 == V_1072 ) ) {
F_92 ( L_28 ,
V_2 -> V_1067 , V_2 -> V_5 . V_651 ) ;
F_460 ( V_2 ) ;
V_99 = F_461 ( V_2 ) ;
if ( V_99 )
return V_99 ;
V_2 -> V_5 . V_996 = V_1073 ;
}
V_2 -> V_1066 = F_174 ( & V_29 -> V_408 ) ;
F_430 ( V_2 ) ;
V_99 = 1 ;
while ( V_99 > 0 ) {
if ( V_2 -> V_5 . V_996 == V_1073 &&
! V_2 -> V_5 . V_6 . V_1058 )
V_99 = F_440 ( V_2 ) ;
else {
F_175 ( & V_29 -> V_408 , V_2 -> V_1066 ) ;
F_462 ( V_2 ) ;
V_2 -> V_1066 = F_174 ( & V_29 -> V_408 ) ;
if ( F_441 ( V_1074 , V_2 ) )
{
switch( V_2 -> V_5 . V_996 ) {
case V_997 :
V_2 -> V_5 . V_996 =
V_1073 ;
case V_1073 :
V_2 -> V_5 . V_6 . V_1058 = false ;
break;
case V_1072 :
default:
V_99 = - V_1075 ;
break;
}
}
}
if ( V_99 <= 0 )
break;
F_463 ( V_1076 , & V_2 -> V_1045 ) ;
if ( F_464 ( V_2 ) )
F_465 ( V_2 ) ;
if ( F_425 ( V_2 ) ) {
V_99 = - V_1075 ;
V_2 -> V_834 -> V_842 = V_1077 ;
++ V_2 -> V_60 . V_1078 ;
}
F_466 ( V_2 ) ;
if ( F_449 ( V_337 ) ) {
V_99 = - V_1075 ;
V_2 -> V_834 -> V_842 = V_1077 ;
++ V_2 -> V_60 . V_1079 ;
}
if ( F_448 () ) {
F_175 ( & V_29 -> V_408 , V_2 -> V_1066 ) ;
F_467 ( V_2 ) ;
V_2 -> V_1066 = F_174 ( & V_29 -> V_408 ) ;
}
}
F_175 ( & V_29 -> V_408 , V_2 -> V_1066 ) ;
F_431 ( V_2 ) ;
return V_99 ;
}
static int F_468 ( struct V_1 * V_2 )
{
struct V_1032 * V_834 = V_2 -> V_834 ;
int V_99 ;
if ( ! ( V_2 -> V_5 . V_862 . V_735 || V_2 -> V_841 ) )
return 1 ;
if ( V_2 -> V_841 ) {
V_2 -> V_841 = 0 ;
if ( ! V_2 -> V_847 )
memcpy ( V_2 -> V_830 + V_2 -> V_848 ,
V_834 -> V_835 . V_31 , 8 ) ;
V_2 -> V_848 += 8 ;
if ( V_2 -> V_848 < V_2 -> V_845 ) {
V_834 -> V_842 = V_843 ;
V_834 -> V_835 . V_844 = V_2 -> V_831 + V_2 -> V_848 ;
memcpy ( V_834 -> V_835 . V_31 , V_2 -> V_830 + V_2 -> V_848 , 8 ) ;
V_834 -> V_835 . V_75 = F_207 ( V_2 -> V_845 - V_2 -> V_848 , 8 ) ;
V_834 -> V_835 . V_846 = V_2 -> V_847 ;
V_2 -> V_841 = 1 ;
return 0 ;
}
if ( V_2 -> V_847 )
return 1 ;
V_2 -> V_829 = 1 ;
}
V_2 -> V_1066 = F_174 ( & V_2 -> V_29 -> V_408 ) ;
V_99 = F_469 ( V_2 , V_941 ) ;
F_175 ( & V_2 -> V_29 -> V_408 , V_2 -> V_1066 ) ;
if ( V_99 != V_931 )
return 0 ;
return 1 ;
}
int F_470 ( struct V_1 * V_2 , struct V_1032 * V_1032 )
{
int V_99 ;
T_14 V_1080 ;
if ( ! F_471 ( V_337 ) && F_472 ( V_337 ) )
return - V_307 ;
if ( V_2 -> V_1081 )
F_473 ( V_1082 , & V_2 -> V_1083 , & V_1080 ) ;
if ( F_72 ( V_2 -> V_5 . V_996 == V_1084 ) ) {
F_462 ( V_2 ) ;
F_463 ( V_1074 , & V_2 -> V_1045 ) ;
V_99 = - V_1085 ;
goto V_93;
}
if ( ! F_18 ( V_2 -> V_29 ) ) {
if ( F_74 ( V_2 , V_1032 -> V_157 ) != 0 ) {
V_99 = - V_485 ;
goto V_93;
}
}
V_99 = F_468 ( V_2 ) ;
if ( V_99 <= 0 )
goto V_93;
if ( V_1032 -> V_842 == V_1086 )
F_413 ( V_2 , V_902 ,
V_1032 -> V_1087 . V_88 ) ;
V_99 = F_459 ( V_2 ) ;
V_93:
F_428 ( V_2 ) ;
if ( V_2 -> V_1081 )
F_473 ( V_1082 , & V_1080 , NULL ) ;
return V_99 ;
}
int F_474 ( struct V_1 * V_2 , struct V_1088 * V_617 )
{
if ( V_2 -> V_5 . V_955 ) {
struct V_823 * V_824 = & V_2 -> V_5 . V_906 ;
memcpy ( V_2 -> V_5 . V_617 , V_824 -> V_617 , sizeof V_824 -> V_617 ) ;
V_2 -> V_5 . V_955 = false ;
}
V_617 -> V_1089 = F_350 ( V_2 , V_902 ) ;
V_617 -> V_1090 = F_350 ( V_2 , V_1012 ) ;
V_617 -> V_1091 = F_350 ( V_2 , V_1013 ) ;
V_617 -> V_1092 = F_350 ( V_2 , V_1011 ) ;
V_617 -> V_1093 = F_350 ( V_2 , V_1015 ) ;
V_617 -> V_1094 = F_350 ( V_2 , V_1014 ) ;
V_617 -> V_1095 = F_350 ( V_2 , V_903 ) ;
V_617 -> V_1096 = F_350 ( V_2 , V_1097 ) ;
#ifdef F_52
V_617 -> V_1098 = F_350 ( V_2 , V_1016 ) ;
V_617 -> V_1099 = F_350 ( V_2 , V_1100 ) ;
V_617 -> V_1101 = F_350 ( V_2 , V_1102 ) ;
V_617 -> V_1103 = F_350 ( V_2 , V_1104 ) ;
V_617 -> V_1105 = F_350 ( V_2 , V_1106 ) ;
V_617 -> V_1107 = F_350 ( V_2 , V_1108 ) ;
V_617 -> V_1109 = F_350 ( V_2 , V_1110 ) ;
V_617 -> V_1111 = F_350 ( V_2 , V_1112 ) ;
#endif
V_617 -> V_1027 = F_356 ( V_2 ) ;
V_617 -> V_1113 = F_355 ( V_2 ) ;
return 0 ;
}
int F_475 ( struct V_1 * V_2 , struct V_1088 * V_617 )
{
V_2 -> V_5 . V_924 = true ;
V_2 -> V_5 . V_955 = false ;
F_413 ( V_2 , V_902 , V_617 -> V_1089 ) ;
F_413 ( V_2 , V_1012 , V_617 -> V_1090 ) ;
F_413 ( V_2 , V_1013 , V_617 -> V_1091 ) ;
F_413 ( V_2 , V_1011 , V_617 -> V_1092 ) ;
F_413 ( V_2 , V_1015 , V_617 -> V_1093 ) ;
F_413 ( V_2 , V_1014 , V_617 -> V_1094 ) ;
F_413 ( V_2 , V_903 , V_617 -> V_1095 ) ;
F_413 ( V_2 , V_1097 , V_617 -> V_1096 ) ;
#ifdef F_52
F_413 ( V_2 , V_1016 , V_617 -> V_1098 ) ;
F_413 ( V_2 , V_1100 , V_617 -> V_1099 ) ;
F_413 ( V_2 , V_1102 , V_617 -> V_1101 ) ;
F_413 ( V_2 , V_1104 , V_617 -> V_1103 ) ;
F_413 ( V_2 , V_1106 , V_617 -> V_1105 ) ;
F_413 ( V_2 , V_1108 , V_617 -> V_1107 ) ;
F_413 ( V_2 , V_1110 , V_617 -> V_1109 ) ;
F_413 ( V_2 , V_1112 , V_617 -> V_1111 ) ;
#endif
F_361 ( V_2 , V_617 -> V_1027 ) ;
F_362 ( V_2 , V_617 -> V_1113 ) ;
V_2 -> V_5 . V_49 . V_50 = false ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
void F_476 ( struct V_1 * V_2 , int * V_161 , int * V_894 )
{
struct V_809 V_1114 ;
F_277 ( V_2 , & V_1114 , V_1115 ) ;
* V_161 = V_1114 . V_161 ;
* V_894 = V_1114 . V_894 ;
}
int F_477 ( struct V_1 * V_2 ,
struct V_1116 * V_1117 )
{
struct V_878 V_879 ;
F_277 ( V_2 , & V_1117 -> V_1114 , V_1115 ) ;
F_277 ( V_2 , & V_1117 -> V_1118 , V_1119 ) ;
F_277 ( V_2 , & V_1117 -> V_1120 , V_1121 ) ;
F_277 ( V_2 , & V_1117 -> V_1122 , V_1123 ) ;
F_277 ( V_2 , & V_1117 -> V_1124 , V_1125 ) ;
F_277 ( V_2 , & V_1117 -> V_1126 , V_1127 ) ;
F_277 ( V_2 , & V_1117 -> V_1128 , V_1129 ) ;
F_277 ( V_2 , & V_1117 -> V_1130 , V_1131 ) ;
V_56 -> V_881 ( V_2 , & V_879 ) ;
V_1117 -> V_1132 . V_611 = V_879 . V_413 ;
V_1117 -> V_1132 . V_890 = V_879 . V_63 ;
V_56 -> V_880 ( V_2 , & V_879 ) ;
V_1117 -> V_1133 . V_611 = V_879 . V_413 ;
V_1117 -> V_1133 . V_890 = V_879 . V_63 ;
V_1117 -> V_100 = F_51 ( V_2 ) ;
V_1117 -> V_62 = V_2 -> V_5 . V_62 ;
V_1117 -> V_84 = F_49 ( V_2 ) ;
V_1117 -> V_142 = F_68 ( V_2 ) ;
V_1117 -> V_157 = F_76 ( V_2 ) ;
V_1117 -> V_110 = V_2 -> V_5 . V_110 ;
V_1117 -> V_30 = F_17 ( V_2 ) ;
memset ( V_1117 -> V_1134 , 0 , sizeof V_1117 -> V_1134 ) ;
if ( V_2 -> V_5 . V_640 . V_50 && ! V_2 -> V_5 . V_640 . V_641 )
F_478 ( V_2 -> V_5 . V_640 . V_16 ,
( unsigned long * ) V_1117 -> V_1134 ) ;
return 0 ;
}
int F_479 ( struct V_1 * V_2 ,
struct V_1135 * V_996 )
{
V_996 -> V_996 = V_2 -> V_5 . V_996 ;
return 0 ;
}
int F_480 ( struct V_1 * V_2 ,
struct V_1135 * V_996 )
{
V_2 -> V_5 . V_996 = V_996 -> V_996 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
int F_481 ( struct V_1 * V_2 , V_859 V_1136 , int V_1137 ,
bool V_52 , T_1 V_43 )
{
struct V_823 * V_824 = & V_2 -> V_5 . V_906 ;
int V_88 ;
F_354 ( V_2 ) ;
V_88 = F_482 ( V_824 , V_1136 , V_1137 ,
V_52 , V_43 ) ;
if ( V_88 )
return V_929 ;
memcpy ( V_2 -> V_5 . V_617 , V_824 -> V_617 , sizeof V_824 -> V_617 ) ;
F_361 ( V_2 , V_824 -> V_915 ) ;
F_362 ( V_2 , V_824 -> V_914 ) ;
F_23 ( V_48 , V_2 ) ;
return V_931 ;
}
int F_483 ( struct V_1 * V_2 ,
struct V_1116 * V_1117 )
{
int V_1138 = 0 ;
int V_1139 , V_1140 , V_280 ;
struct V_878 V_879 ;
V_879 . V_413 = V_1117 -> V_1132 . V_611 ;
V_879 . V_63 = V_1117 -> V_1132 . V_890 ;
V_56 -> V_883 ( V_2 , & V_879 ) ;
V_879 . V_413 = V_1117 -> V_1133 . V_611 ;
V_879 . V_63 = V_1117 -> V_1133 . V_890 ;
V_56 -> V_882 ( V_2 , & V_879 ) ;
V_2 -> V_5 . V_62 = V_1117 -> V_62 ;
V_1138 |= F_49 ( V_2 ) != V_1117 -> V_84 ;
V_2 -> V_5 . V_84 = V_1117 -> V_84 ;
F_44 ( V_154 , ( V_155 * ) & V_2 -> V_5 . V_96 ) ;
F_74 ( V_2 , V_1117 -> V_157 ) ;
V_1138 |= V_2 -> V_5 . V_110 != V_1117 -> V_110 ;
V_56 -> F_82 ( V_2 , V_1117 -> V_110 ) ;
F_19 ( V_2 , V_1117 -> V_30 ) ;
V_1138 |= F_51 ( V_2 ) != V_1117 -> V_100 ;
V_56 -> V_115 ( V_2 , V_1117 -> V_100 ) ;
V_2 -> V_5 . V_100 = V_1117 -> V_100 ;
V_1138 |= F_68 ( V_2 ) != V_1117 -> V_142 ;
V_56 -> V_151 ( V_2 , V_1117 -> V_142 ) ;
if ( V_1117 -> V_142 & V_138 )
F_65 ( V_2 ) ;
V_280 = F_174 ( & V_2 -> V_29 -> V_408 ) ;
if ( ! F_46 ( V_2 ) && F_47 ( V_2 ) ) {
F_41 ( V_2 , V_2 -> V_5 . V_83 , F_49 ( V_2 ) ) ;
V_1138 = 1 ;
}
F_175 ( & V_2 -> V_29 -> V_408 , V_280 ) ;
if ( V_1138 )
F_55 ( V_2 ) ;
V_1140 = ( sizeof V_1117 -> V_1134 ) << 3 ;
V_1139 = F_484 (
( const unsigned long * ) V_1117 -> V_1134 , V_1140 ) ;
if ( V_1139 < V_1140 ) {
F_214 ( V_2 , V_1139 , false ) ;
F_92 ( L_29 , V_1139 ) ;
}
F_276 ( V_2 , & V_1117 -> V_1114 , V_1115 ) ;
F_276 ( V_2 , & V_1117 -> V_1118 , V_1119 ) ;
F_276 ( V_2 , & V_1117 -> V_1120 , V_1121 ) ;
F_276 ( V_2 , & V_1117 -> V_1122 , V_1123 ) ;
F_276 ( V_2 , & V_1117 -> V_1124 , V_1125 ) ;
F_276 ( V_2 , & V_1117 -> V_1126 , V_1127 ) ;
F_276 ( V_2 , & V_1117 -> V_1128 , V_1129 ) ;
F_276 ( V_2 , & V_1117 -> V_1130 , V_1131 ) ;
F_212 ( V_2 ) ;
if ( F_485 ( V_2 ) && F_356 ( V_2 ) == 0xfff0 &&
V_1117 -> V_1114 . V_884 == 0xf000 && V_1117 -> V_1114 . V_890 == 0xffff0000 &&
! F_357 ( V_2 ) )
V_2 -> V_5 . V_996 = V_1073 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
int F_486 ( struct V_1 * V_2 ,
struct V_1141 * V_1142 )
{
unsigned long V_1113 ;
int V_3 , V_99 ;
if ( V_1142 -> V_742 & ( V_1143 | V_1144 ) ) {
V_99 = - V_1145 ;
if ( V_2 -> V_5 . V_49 . V_50 )
goto V_93;
if ( V_1142 -> V_742 & V_1143 )
F_24 ( V_2 , V_1146 ) ;
else
F_24 ( V_2 , V_1147 ) ;
}
V_1113 = F_355 ( V_2 ) ;
V_2 -> V_162 = V_1142 -> V_742 ;
if ( ! ( V_2 -> V_162 & V_1148 ) )
V_2 -> V_162 = 0 ;
if ( V_2 -> V_162 & V_163 ) {
for ( V_3 = 0 ; V_3 < V_1149 ; ++ V_3 )
V_2 -> V_5 . V_164 [ V_3 ] = V_1142 -> V_5 . V_1150 [ V_3 ] ;
V_2 -> V_5 . V_173 =
( V_1142 -> V_5 . V_1150 [ 7 ] & V_174 ) ;
} else {
for ( V_3 = 0 ; V_3 < V_1149 ; V_3 ++ )
V_2 -> V_5 . V_164 [ V_3 ] = V_2 -> V_5 . V_161 [ V_3 ] ;
V_2 -> V_5 . V_173 = ( V_2 -> V_5 . V_169 & V_174 ) ;
}
if ( V_2 -> V_162 & V_1151 )
V_2 -> V_5 . V_1152 = F_356 ( V_2 ) +
F_316 ( V_2 , V_1115 ) ;
F_362 ( V_2 , V_1113 ) ;
V_56 -> V_1153 ( V_2 , V_1142 ) ;
V_99 = 0 ;
V_93:
return V_99 ;
}
int F_487 ( struct V_1 * V_2 ,
struct V_1154 * V_1128 )
{
unsigned long V_1155 = V_1128 -> V_1156 ;
T_4 V_330 ;
int V_280 ;
V_280 = F_174 ( & V_2 -> V_29 -> V_408 ) ;
V_330 = F_283 ( V_2 , V_1155 , NULL ) ;
F_175 ( & V_2 -> V_29 -> V_408 , V_280 ) ;
V_1128 -> V_1157 = V_330 ;
V_1128 -> V_1158 = V_330 != V_80 ;
V_1128 -> V_1159 = 1 ;
V_1128 -> V_1160 = 0 ;
return 0 ;
}
int F_488 ( struct V_1 * V_2 , struct V_1161 * V_1162 )
{
struct V_668 * V_667 =
& V_2 -> V_5 . V_663 . V_664 -> V_667 ;
memcpy ( V_1162 -> V_1163 , V_667 -> V_1164 , 128 ) ;
V_1162 -> V_1165 = V_667 -> V_1166 ;
V_1162 -> V_1167 = V_667 -> V_1168 ;
V_1162 -> V_1169 = V_667 -> V_1170 ;
V_1162 -> V_1171 = V_667 -> V_1172 ;
V_1162 -> V_1173 = V_667 -> V_1027 ;
V_1162 -> V_1174 = V_667 -> V_1175 ;
memcpy ( V_1162 -> V_1176 , V_667 -> V_1177 , sizeof V_667 -> V_1177 ) ;
return 0 ;
}
int F_489 ( struct V_1 * V_2 , struct V_1161 * V_1162 )
{
struct V_668 * V_667 =
& V_2 -> V_5 . V_663 . V_664 -> V_667 ;
memcpy ( V_667 -> V_1164 , V_1162 -> V_1163 , 128 ) ;
V_667 -> V_1166 = V_1162 -> V_1165 ;
V_667 -> V_1168 = V_1162 -> V_1167 ;
V_667 -> V_1170 = V_1162 -> V_1169 ;
V_667 -> V_1172 = V_1162 -> V_1171 ;
V_667 -> V_1027 = V_1162 -> V_1173 ;
V_667 -> V_1175 = V_1162 -> V_1174 ;
memcpy ( V_667 -> V_1177 , V_1162 -> V_1176 , sizeof V_667 -> V_1177 ) ;
return 0 ;
}
int F_490 ( struct V_1 * V_2 )
{
int V_55 ;
V_55 = F_491 ( & V_2 -> V_5 . V_663 ) ;
if ( V_55 )
return V_55 ;
F_492 ( & V_2 -> V_5 . V_663 ) ;
V_2 -> V_5 . V_119 = V_121 ;
V_2 -> V_5 . V_100 |= V_107 ;
return 0 ;
}
static void F_493 ( struct V_1 * V_2 )
{
F_494 ( & V_2 -> V_5 . V_663 ) ;
}
void F_345 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1178 )
return;
F_438 ( V_2 ) ;
V_2 -> V_1178 = 1 ;
F_495 ( V_337 ) ;
F_496 ( & V_2 -> V_5 . V_663 ) ;
F_497 ( 1 ) ;
}
void F_192 ( struct V_1 * V_2 )
{
F_438 ( V_2 ) ;
if ( ! V_2 -> V_1178 )
return;
V_2 -> V_1178 = 0 ;
F_498 ( & V_2 -> V_5 . V_663 ) ;
++ V_2 -> V_60 . V_1179 ;
F_23 ( V_1054 , V_2 ) ;
F_497 ( 0 ) ;
}
void F_499 ( struct V_1 * V_2 )
{
F_145 ( V_2 ) ;
F_500 ( V_2 -> V_5 . V_491 ) ;
F_493 ( V_2 ) ;
V_56 -> V_1180 ( V_2 ) ;
}
struct V_1 * F_501 ( struct V_29 * V_29 ,
unsigned int V_1181 )
{
if ( F_114 () && F_502 ( & V_29 -> V_1182 ) != 0 )
F_107 ( V_220
L_30
L_31 ) ;
return V_56 -> V_1183 ( V_29 , V_1181 ) ;
}
int F_503 ( struct V_1 * V_2 )
{
int V_99 ;
V_2 -> V_5 . V_275 . V_1184 = 1 ;
V_492 ( V_2 ) ;
V_99 = F_461 ( V_2 ) ;
if ( V_99 == 0 )
V_99 = F_504 ( V_2 ) ;
V_494 ( V_2 ) ;
return V_99 ;
}
void F_505 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_6 . V_331 = 0 ;
V_492 ( V_2 ) ;
F_442 ( V_2 ) ;
V_494 ( V_2 ) ;
F_493 ( V_2 ) ;
V_56 -> V_1180 ( V_2 ) ;
}
int F_461 ( struct V_1 * V_2 )
{
F_506 ( & V_2 -> V_5 . V_68 , 0 ) ;
V_2 -> V_5 . V_648 = 0 ;
V_2 -> V_5 . V_647 = false ;
V_2 -> V_5 . V_173 = 0 ;
memset ( V_2 -> V_5 . V_161 , 0 , sizeof( V_2 -> V_5 . V_161 ) ) ;
V_2 -> V_5 . V_166 = V_168 ;
V_2 -> V_5 . V_169 = V_171 ;
F_23 ( V_48 , V_2 ) ;
V_2 -> V_5 . V_6 . V_331 = 0 ;
V_2 -> V_5 . V_335 . V_331 = 0 ;
F_145 ( V_2 ) ;
F_54 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1058 = false ;
return V_56 -> V_1185 ( V_2 ) ;
}
int F_507 ( void * V_486 )
{
struct V_29 * V_29 ;
struct V_1 * V_2 ;
int V_3 ;
F_13 () ;
F_379 (kvm, &vm_list, vm_list)
F_167 (i, vcpu, kvm)
if ( V_2 -> V_216 == F_380 () )
F_23 ( V_246 , V_2 ) ;
return V_56 -> V_1186 ( V_486 ) ;
}
void F_508 ( void * V_486 )
{
V_56 -> V_1187 ( V_486 ) ;
F_16 ( V_486 ) ;
}
int F_509 ( void )
{
return V_56 -> V_1188 () ;
}
void F_510 ( void )
{
V_56 -> V_1189 () ;
}
void F_511 ( void * V_1190 )
{
V_56 -> V_1191 ( V_1190 ) ;
}
int F_512 ( struct V_1 * V_2 )
{
struct V_305 * V_305 ;
struct V_29 * V_29 ;
int V_99 ;
F_279 ( V_2 -> V_29 == NULL ) ;
V_29 = V_2 -> V_29 ;
V_2 -> V_5 . V_906 . V_837 = & V_1192 ;
V_2 -> V_5 . V_83 = & V_2 -> V_5 . V_67 ;
V_2 -> V_5 . V_67 . V_1193 = V_1194 ;
V_2 -> V_5 . V_67 . V_79 = V_79 ;
V_2 -> V_5 . V_65 . V_79 = F_278 ;
if ( ! F_18 ( V_29 ) || F_485 ( V_2 ) )
V_2 -> V_5 . V_996 = V_1073 ;
else
V_2 -> V_5 . V_996 = V_1084 ;
V_305 = F_513 ( V_308 | V_1195 ) ;
if ( ! V_305 ) {
V_99 = - V_307 ;
goto V_1196;
}
V_2 -> V_5 . V_866 = F_514 ( V_305 ) ;
F_109 ( V_2 , V_973 ) ;
V_99 = F_515 ( V_2 ) ;
if ( V_99 < 0 )
goto V_1197;
if ( F_18 ( V_29 ) ) {
V_99 = F_516 ( V_2 ) ;
if ( V_99 < 0 )
goto V_1198;
}
V_2 -> V_5 . V_294 = F_129 ( V_370 * sizeof( T_2 ) * 4 ,
V_308 ) ;
if ( ! V_2 -> V_5 . V_294 ) {
V_99 = - V_307 ;
goto V_1199;
}
V_2 -> V_5 . V_286 = V_370 ;
if ( ! F_517 ( & V_2 -> V_5 . V_491 , V_308 ) )
goto V_1200;
F_1 ( V_2 ) ;
return 0 ;
V_1200:
F_131 ( V_2 -> V_5 . V_294 ) ;
V_1199:
F_518 ( V_2 ) ;
V_1198:
F_519 ( V_2 ) ;
V_1197:
F_520 ( ( unsigned long ) V_2 -> V_5 . V_866 ) ;
V_1196:
return V_99 ;
}
void F_521 ( struct V_1 * V_2 )
{
int V_280 ;
F_131 ( V_2 -> V_5 . V_294 ) ;
F_518 ( V_2 ) ;
V_280 = F_174 ( & V_2 -> V_29 -> V_408 ) ;
F_519 ( V_2 ) ;
F_175 ( & V_2 -> V_29 -> V_408 , V_280 ) ;
F_520 ( ( unsigned long ) V_2 -> V_5 . V_866 ) ;
}
int F_522 ( struct V_29 * V_29 )
{
F_523 ( & V_29 -> V_5 . V_1201 ) ;
F_523 ( & V_29 -> V_5 . V_1202 ) ;
F_478 ( V_784 , & V_29 -> V_5 . V_1203 ) ;
F_524 ( & V_29 -> V_5 . V_234 ) ;
return 0 ;
}
static void F_525 ( struct V_1 * V_2 )
{
V_492 ( V_2 ) ;
F_442 ( V_2 ) ;
V_494 ( V_2 ) ;
}
static void F_526 ( struct V_29 * V_29 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_167 (i, vcpu, kvm) {
F_54 ( V_2 ) ;
F_525 ( V_2 ) ;
}
F_167 (i, vcpu, kvm)
F_499 ( V_2 ) ;
F_160 ( & V_29 -> V_385 ) ;
for ( V_3 = 0 ; V_3 < F_502 ( & V_29 -> V_1182 ) ; V_3 ++ )
V_29 -> V_1204 [ V_3 ] = NULL ;
F_506 ( & V_29 -> V_1182 , 0 ) ;
F_161 ( & V_29 -> V_385 ) ;
}
void F_527 ( struct V_29 * V_29 )
{
F_528 ( V_29 ) ;
F_529 ( V_29 ) ;
}
void F_530 ( struct V_29 * V_29 )
{
F_531 ( V_29 ) ;
F_131 ( V_29 -> V_5 . V_767 ) ;
F_131 ( V_29 -> V_5 . V_1205 ) ;
F_526 ( V_29 ) ;
if ( V_29 -> V_5 . V_1206 )
F_532 ( V_29 -> V_5 . V_1206 ) ;
if ( V_29 -> V_5 . V_1207 )
F_532 ( V_29 -> V_5 . V_1207 ) ;
}
int F_533 ( struct V_29 * V_29 ,
struct V_746 * V_747 ,
struct V_746 V_854 ,
struct V_1208 * V_1209 ,
int V_1210 )
{
int V_1211 = V_747 -> V_1211 ;
int V_1212 = V_1213 | V_1214 ;
if ( V_747 -> V_1181 >= V_456 )
V_1212 = V_1215 | V_1214 ;
if ( ! V_1210 ) {
if ( V_1211 && ! V_854 . V_1216 ) {
unsigned long V_1217 ;
F_534 ( & V_337 -> V_1218 -> V_1219 ) ;
V_1217 = F_535 ( NULL , 0 ,
V_1211 * V_87 ,
V_1220 | V_1221 ,
V_1212 ,
0 ) ;
F_536 ( & V_337 -> V_1218 -> V_1219 ) ;
if ( F_537 ( ( void * ) V_1217 ) )
return F_538 ( ( void * ) V_1217 ) ;
V_747 -> V_1217 = V_1217 ;
}
}
return 0 ;
}
void F_539 ( struct V_29 * V_29 ,
struct V_1208 * V_1209 ,
struct V_746 V_854 ,
int V_1210 )
{
int V_1222 = 0 , V_1211 = V_1209 -> V_1223 >> V_86 ;
if ( ! V_1210 && ! V_854 . V_1210 && V_854 . V_1216 && ! V_1211 ) {
int V_88 ;
F_534 ( & V_337 -> V_1218 -> V_1219 ) ;
V_88 = F_540 ( V_337 -> V_1218 , V_854 . V_1217 ,
V_854 . V_1211 * V_87 ) ;
F_536 ( & V_337 -> V_1218 -> V_1219 ) ;
if ( V_88 < 0 )
F_9 ( V_220
L_32
L_33 ) ;
}
if ( ! V_29 -> V_5 . V_718 )
V_1222 = F_541 ( V_29 ) ;
F_234 ( & V_29 -> V_717 ) ;
if ( V_1222 )
F_235 ( V_29 , V_1222 ) ;
F_254 ( V_29 , V_1209 -> V_10 ) ;
F_236 ( & V_29 -> V_717 ) ;
}
void F_542 ( struct V_29 * V_29 )
{
F_418 ( V_29 ) ;
F_543 ( V_29 ) ;
}
int F_544 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_996 == V_1073 &&
! V_2 -> V_5 . V_6 . V_1058 )
|| ! F_545 ( & V_2 -> V_1224 . V_1225 )
|| V_2 -> V_5 . V_996 == V_1072
|| F_502 ( & V_2 -> V_5 . V_68 ) ||
( F_427 ( V_2 ) &&
F_426 ( V_2 ) ) ;
}
void F_546 ( struct V_1 * V_2 )
{
int V_1226 ;
int V_216 = V_2 -> V_216 ;
if ( F_547 ( & V_2 -> V_1227 ) ) {
F_548 ( & V_2 -> V_1227 ) ;
++ V_2 -> V_60 . V_1228 ;
}
V_1226 = F_100 () ;
if ( V_216 != V_1226 && ( unsigned ) V_216 < V_1229 && F_549 ( V_216 ) )
if ( F_550 ( V_2 ) == V_1062 )
F_551 ( V_216 ) ;
F_103 () ;
}
int F_427 ( struct V_1 * V_2 )
{
return V_56 -> V_1043 ( V_2 ) ;
}
bool F_552 ( struct V_1 * V_2 , unsigned long V_1230 )
{
unsigned long V_1231 = F_356 ( V_2 ) +
F_316 ( V_2 , V_1115 ) ;
return V_1231 == V_1230 ;
}
unsigned long F_355 ( struct V_1 * V_2 )
{
unsigned long V_1113 ;
V_1113 = V_56 -> V_1232 ( V_2 ) ;
if ( V_2 -> V_162 & V_1151 )
V_1113 &= ~ V_1233 ;
return V_1113 ;
}
void F_362 ( struct V_1 * V_2 , unsigned long V_1113 )
{
if ( V_2 -> V_162 & V_1151 &&
F_552 ( V_2 , V_2 -> V_5 . V_1152 ) )
V_1113 |= V_1233 ;
V_56 -> V_1234 ( V_2 , V_1113 ) ;
F_23 ( V_48 , V_2 ) ;
}
void F_553 ( struct V_1 * V_2 , struct V_1235 * V_1236 )
{
int V_99 ;
if ( ( V_2 -> V_5 . V_67 . V_1237 != V_1236 -> V_5 . V_1237 ) ||
F_155 ( V_1236 -> V_305 ) )
return;
V_99 = F_444 ( V_2 ) ;
if ( F_72 ( V_99 ) )
return;
if ( ! V_2 -> V_5 . V_67 . V_1237 &&
V_1236 -> V_5 . V_84 != V_2 -> V_5 . V_67 . V_1238 ( V_2 ) )
return;
V_2 -> V_5 . V_67 . V_1239 ( V_2 , V_1236 -> V_816 , 0 , true ) ;
}
static inline T_1 F_554 ( T_3 V_82 )
{
return F_555 ( V_82 & 0xffffffff , F_556 ( V_4 ) ) ;
}
static inline T_1 F_557 ( T_1 V_1240 )
{
return ( V_1240 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_558 ( struct V_1 * V_2 , T_3 V_82 )
{
T_1 V_1240 = F_554 ( V_82 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1240 ] != ~ 0 )
V_1240 = F_557 ( V_1240 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1240 ] = V_82 ;
}
static T_1 F_559 ( struct V_1 * V_2 , T_3 V_82 )
{
int V_3 ;
T_1 V_1240 = F_554 ( V_82 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1240 ] != V_82 &&
V_2 -> V_5 . V_6 . V_7 [ V_1240 ] != ~ 0 ) ; V_3 ++ )
V_1240 = F_557 ( V_1240 ) ;
return V_1240 ;
}
bool F_560 ( struct V_1 * V_2 , T_3 V_82 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_559 ( V_2 , V_82 ) ] == V_82 ;
}
static void F_561 ( struct V_1 * V_2 , T_3 V_82 )
{
T_1 V_3 , V_803 , V_1241 ;
V_3 = V_803 = F_559 ( V_2 , V_82 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_803 = F_557 ( V_803 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_803 ] == ~ 0 )
return;
V_1241 = F_554 ( V_2 -> V_5 . V_6 . V_7 [ V_803 ] ) ;
} while ( ( V_3 <= V_803 ) ? ( V_3 < V_1241 && V_1241 <= V_803 ) : ( V_3 < V_1241 || V_1241 <= V_803 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_803 ] ;
V_3 = V_803 ;
}
}
static int F_562 ( struct V_1 * V_2 , T_1 V_160 )
{
return F_150 ( V_2 -> V_29 , & V_2 -> V_5 . V_6 . V_31 , & V_160 ,
sizeof( V_160 ) ) ;
}
void F_563 ( struct V_1 * V_2 ,
struct V_1235 * V_1236 )
{
struct V_58 V_59 ;
F_564 ( V_1236 -> V_5 . V_1242 , V_1236 -> V_816 ) ;
F_558 ( V_2 , V_1236 -> V_5 . V_82 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_331 & V_332 ) ||
( V_2 -> V_5 . V_6 . V_333 &&
V_56 -> V_71 ( V_2 ) == 0 ) )
F_23 ( V_1057 , V_2 ) ;
else if ( ! F_562 ( V_2 , V_1243 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_907 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_1236 -> V_5 . V_1242 ;
F_28 ( V_2 , & V_59 ) ;
}
}
void F_565 ( struct V_1 * V_2 ,
struct V_1235 * V_1236 )
{
struct V_58 V_59 ;
F_566 ( V_1236 -> V_5 . V_1242 , V_1236 -> V_816 ) ;
if ( F_155 ( V_1236 -> V_305 ) )
V_1236 -> V_5 . V_1242 = ~ 0 ;
else
F_561 ( V_2 , V_1236 -> V_5 . V_82 ) ;
if ( ( V_2 -> V_5 . V_6 . V_331 & V_332 ) &&
! F_562 ( V_2 , V_1244 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_907 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_1236 -> V_5 . V_1242 ;
F_28 ( V_2 , & V_59 ) ;
}
V_2 -> V_5 . V_6 . V_1058 = false ;
}
bool F_567 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_331 & V_332 ) )
return true ;
else
return ! F_429 ( V_2 ) &&
V_56 -> V_1043 ( V_2 ) ;
}
