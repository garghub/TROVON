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
if ( ! ( V_100 & V_103 ) && F_54 ( V_2 , V_115 ) )
return 1 ;
V_56 -> V_116 ( V_2 , V_100 ) ;
if ( ( V_100 ^ V_101 ) & V_103 ) {
F_55 ( V_2 ) ;
F_1 ( V_2 ) ;
}
if ( ( V_100 ^ V_101 ) & V_102 )
F_56 ( V_2 ) ;
return 0 ;
}
void F_57 ( struct V_1 * V_2 , unsigned long V_117 )
{
( void ) F_50 ( V_2 , F_58 ( V_2 , ~ 0x0eul ) | ( V_117 & 0x0f ) ) ;
}
int F_59 ( struct V_1 * V_2 , T_1 V_118 , T_2 V_119 )
{
T_2 V_120 ;
if ( V_118 != V_121 )
return 1 ;
V_120 = V_119 ;
if ( V_56 -> V_71 ( V_2 ) != 0 )
return 1 ;
if ( ! ( V_120 & V_122 ) )
return 1 ;
if ( ( V_120 & V_123 ) && ! ( V_120 & V_124 ) )
return 1 ;
if ( V_120 & ~ V_125 )
return 1 ;
V_2 -> V_5 . V_120 = V_120 ;
V_2 -> V_126 = 0 ;
return 0 ;
}
int F_60 ( struct V_1 * V_2 , T_1 V_118 , T_2 V_119 )
{
if ( F_59 ( V_2 , V_118 , V_119 ) ) {
F_27 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_61 ( struct V_1 * V_2 , unsigned long V_127 )
{
unsigned long V_128 = F_62 ( V_2 ) ;
unsigned long V_129 = V_130 | V_131 |
V_132 | V_133 ;
if ( V_127 & V_134 )
return 1 ;
if ( ! F_63 ( V_2 ) && ( V_127 & V_135 ) )
return 1 ;
if ( ! F_64 ( V_2 ) && ( V_127 & V_133 ) )
return 1 ;
if ( ! F_65 ( V_2 ) && ( V_127 & V_136 ) )
return 1 ;
if ( F_46 ( V_2 ) ) {
if ( ! ( V_127 & V_132 ) )
return 1 ;
} else if ( F_53 ( V_2 ) && ( V_127 & V_132 )
&& ( ( V_127 ^ V_128 ) & V_129 )
&& ! F_41 ( V_2 , V_2 -> V_5 . V_83 ,
F_49 ( V_2 ) ) )
return 1 ;
if ( ( V_127 & V_115 ) && ! ( V_128 & V_115 ) ) {
if ( ! F_66 ( V_2 ) )
return 1 ;
if ( ( F_49 ( V_2 ) & V_137 ) || ! F_46 ( V_2 ) )
return 1 ;
}
if ( V_56 -> V_138 ( V_2 , V_127 ) )
return 1 ;
if ( ( ( V_127 ^ V_128 ) & V_129 ) ||
( ! ( V_127 & V_115 ) && ( V_128 & V_115 ) ) )
F_56 ( V_2 ) ;
if ( ( V_127 ^ V_128 ) & V_135 )
F_67 ( V_2 ) ;
return 0 ;
}
int F_68 ( struct V_1 * V_2 , unsigned long V_84 )
{
if ( V_84 == F_49 ( V_2 ) && ! F_45 ( V_2 ) ) {
F_69 ( V_2 ) ;
F_70 ( V_2 ) ;
return 0 ;
}
if ( F_46 ( V_2 ) ) {
if ( F_62 ( V_2 ) & V_115 ) {
if ( V_84 & V_139 )
return 1 ;
} else
if ( V_84 & V_140 )
return 1 ;
} else {
if ( F_47 ( V_2 ) ) {
if ( V_84 & V_141 )
return 1 ;
if ( F_53 ( V_2 ) &&
! F_41 ( V_2 , V_2 -> V_5 . V_83 , V_84 ) )
return 1 ;
}
}
if ( F_71 ( ! F_72 ( V_2 -> V_29 , V_84 >> V_86 ) ) )
return 1 ;
V_2 -> V_5 . V_84 = V_84 ;
F_44 ( V_142 , ( V_143 * ) & V_2 -> V_5 . V_96 ) ;
V_2 -> V_5 . V_67 . V_144 ( V_2 ) ;
return 0 ;
}
int F_73 ( struct V_1 * V_2 , unsigned long V_145 )
{
if ( V_145 & V_146 )
return 1 ;
if ( F_18 ( V_2 -> V_29 ) )
F_74 ( V_2 , V_145 ) ;
else
V_2 -> V_5 . V_145 = V_145 ;
return 0 ;
}
unsigned long F_75 ( struct V_1 * V_2 )
{
if ( F_18 ( V_2 -> V_29 ) )
return F_76 ( V_2 ) ;
else
return V_2 -> V_5 . V_145 ;
}
static int F_77 ( struct V_1 * V_2 , int V_147 , unsigned long V_148 )
{
switch ( V_147 ) {
case 0 ... 3 :
V_2 -> V_5 . V_149 [ V_147 ] = V_148 ;
if ( ! ( V_2 -> V_150 & V_151 ) )
V_2 -> V_5 . V_152 [ V_147 ] = V_148 ;
break;
case 4 :
if ( F_54 ( V_2 , V_153 ) )
return 1 ;
case 6 :
if ( V_148 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_154 = ( V_148 & V_155 ) | V_156 ;
break;
case 5 :
if ( F_54 ( V_2 , V_153 ) )
return 1 ;
default:
if ( V_148 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_157 = ( V_148 & V_158 ) | V_159 ;
if ( ! ( V_2 -> V_150 & V_151 ) ) {
V_56 -> V_160 ( V_2 , V_2 -> V_5 . V_157 ) ;
V_2 -> V_5 . V_161 = ( V_148 & V_162 ) ;
}
break;
}
return 0 ;
}
int F_78 ( struct V_1 * V_2 , int V_147 , unsigned long V_148 )
{
int V_163 ;
V_163 = F_77 ( V_2 , V_147 , V_148 ) ;
if ( V_163 > 0 )
F_24 ( V_2 , V_164 ) ;
else if ( V_163 < 0 )
F_27 ( V_2 , 0 ) ;
return V_163 ;
}
static int F_79 ( struct V_1 * V_2 , int V_147 , unsigned long * V_148 )
{
switch ( V_147 ) {
case 0 ... 3 :
* V_148 = V_2 -> V_5 . V_149 [ V_147 ] ;
break;
case 4 :
if ( F_54 ( V_2 , V_153 ) )
return 1 ;
case 6 :
* V_148 = V_2 -> V_5 . V_154 ;
break;
case 5 :
if ( F_54 ( V_2 , V_153 ) )
return 1 ;
default:
* V_148 = V_2 -> V_5 . V_157 ;
break;
}
return 0 ;
}
int F_80 ( struct V_1 * V_2 , int V_147 , unsigned long * V_148 )
{
if ( F_79 ( V_2 , V_147 , V_148 ) ) {
F_24 ( V_2 , V_164 ) ;
return 1 ;
}
return 0 ;
}
bool F_81 ( struct V_1 * V_2 )
{
T_1 V_165 = F_82 ( V_2 , V_166 ) ;
T_2 V_31 ;
int V_55 ;
V_55 = F_83 ( V_2 , V_165 , & V_31 ) ;
if ( V_55 )
return V_55 ;
F_84 ( V_2 , V_167 , ( T_1 ) V_31 ) ;
F_84 ( V_2 , V_168 , V_31 >> 32 ) ;
return V_55 ;
}
static int F_85 ( struct V_1 * V_2 , T_2 V_110 )
{
T_2 V_169 = V_2 -> V_5 . V_110 ;
if ( V_110 & V_170 )
return 1 ;
if ( F_53 ( V_2 )
&& ( V_2 -> V_5 . V_110 & V_111 ) != ( V_110 & V_111 ) )
return 1 ;
if ( V_110 & V_171 ) {
struct V_172 * V_173 ;
V_173 = F_86 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_173 || ! ( V_173 -> V_174 & F_87 ( V_175 ) ) )
return 1 ;
}
if ( V_110 & V_176 ) {
struct V_172 * V_173 ;
V_173 = F_86 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_173 || ! ( V_173 -> V_165 & F_87 ( V_177 ) ) )
return 1 ;
}
V_110 &= ~ V_178 ;
V_110 |= V_2 -> V_5 . V_110 & V_178 ;
V_56 -> F_85 ( V_2 , V_110 ) ;
V_2 -> V_5 . V_67 . V_179 . V_180 = ( V_110 & V_181 ) && ! V_182 ;
if ( ( V_110 ^ V_169 ) & V_181 )
F_56 ( V_2 ) ;
return 0 ;
}
void F_88 ( T_2 V_26 )
{
V_170 &= ~ V_26 ;
}
int F_89 ( struct V_1 * V_2 , T_1 V_183 , T_2 V_31 )
{
return V_56 -> V_184 ( V_2 , V_183 , V_31 ) ;
}
static int F_90 ( struct V_1 * V_2 , unsigned V_118 , T_2 * V_31 )
{
return F_89 ( V_2 , V_118 , * V_31 ) ;
}
static void F_91 ( struct V_29 * V_29 , T_4 V_185 )
{
int V_186 ;
int V_99 ;
struct V_187 V_188 ;
struct V_189 V_190 ;
if ( ! V_185 )
return;
V_99 = F_92 ( V_29 , V_185 , & V_186 , sizeof( V_186 ) ) ;
if ( V_99 )
return;
if ( V_186 & 1 )
++ V_186 ;
++ V_186 ;
F_93 ( V_29 , V_185 , & V_186 , sizeof( V_186 ) ) ;
F_94 ( & V_190 ) ;
if ( V_29 -> V_5 . V_191 ) {
struct V_189 V_192 = F_95 ( V_29 -> V_5 . V_191 ) ;
V_190 = F_96 ( V_190 , V_192 ) ;
}
V_188 . V_193 = V_190 . V_194 ;
V_188 . V_195 = V_190 . V_196 ;
V_188 . V_186 = V_186 ;
F_93 ( V_29 , V_185 , & V_188 , sizeof( V_188 ) ) ;
V_186 ++ ;
F_93 ( V_29 , V_185 , & V_186 , sizeof( V_186 ) ) ;
}
static T_5 F_97 ( T_5 V_197 , T_5 V_198 )
{
T_5 V_199 , V_200 ;
__asm__ ( "divl %4"
: "=a" (quotient), "=d" (remainder)
: "0" (0), "1" (dividend), "r" (divisor) );
return V_199 ;
}
static void F_98 ( T_5 V_201 , T_5 V_202 ,
T_6 * V_203 , T_1 * V_204 )
{
T_7 V_205 ;
T_8 V_206 = 0 ;
T_7 V_207 ;
T_5 V_208 ;
V_207 = V_202 * 1000LL ;
V_205 = V_201 * 1000LL ;
while ( V_207 > V_205 * 2 || V_207 & 0xffffffff00000000ULL ) {
V_207 >>= 1 ;
V_206 -- ;
}
V_208 = ( T_5 ) V_207 ;
while ( V_208 <= V_205 || V_205 & 0xffffffff00000000ULL ) {
if ( V_205 & 0xffffffff00000000ULL || V_208 & 0x80000000 )
V_205 >>= 1 ;
else
V_208 <<= 1 ;
V_206 ++ ;
}
* V_203 = V_206 ;
* V_204 = F_97 ( V_205 , V_208 ) ;
F_99 ( L_2 ,
V_209 , V_202 , V_201 , V_206 , * V_204 ) ;
}
static inline T_2 F_100 ( void )
{
struct V_189 V_192 ;
F_101 ( F_102 () ) ;
F_103 ( & V_192 ) ;
F_104 ( & V_192 ) ;
return F_105 ( & V_192 ) ;
}
static inline T_2 F_106 ( struct V_1 * V_2 , T_2 V_195 )
{
return F_107 ( V_195 , V_2 -> V_5 . V_210 ,
V_2 -> V_5 . V_211 ) ;
}
static T_1 F_108 ( T_1 V_212 , T_9 V_213 )
{
T_2 V_214 = ( T_2 ) V_212 * ( 1000000 + V_213 ) ;
F_109 ( V_214 , 1000000 ) ;
return V_214 ;
}
static void F_110 ( struct V_1 * V_2 , T_1 V_215 )
{
T_1 V_216 , V_217 ;
int V_218 = 0 ;
F_98 ( V_215 , V_219 / 1000 ,
& V_2 -> V_5 . V_211 ,
& V_2 -> V_5 . V_210 ) ;
V_2 -> V_5 . V_220 = V_215 ;
V_216 = F_108 ( V_221 , - V_222 ) ;
V_217 = F_108 ( V_221 , V_222 ) ;
if ( V_215 < V_216 || V_215 > V_217 ) {
F_99 ( L_3 , V_215 , V_216 , V_217 ) ;
V_218 = 1 ;
}
V_56 -> V_223 ( V_2 , V_215 , V_218 ) ;
}
static T_2 F_111 ( struct V_1 * V_2 , T_10 V_224 )
{
T_2 V_225 = F_107 ( V_224 - V_2 -> V_5 . V_226 ,
V_2 -> V_5 . V_210 ,
V_2 -> V_5 . V_211 ) ;
V_225 += V_2 -> V_5 . V_227 ;
return V_225 ;
}
void F_112 ( struct V_1 * V_2 , T_2 V_31 )
{
struct V_29 * V_29 = V_2 -> V_29 ;
T_2 V_74 , V_228 , V_229 ;
unsigned long V_230 ;
T_10 V_231 ;
F_113 ( & V_29 -> V_5 . V_232 , V_230 ) ;
V_74 = V_56 -> V_233 ( V_2 , V_31 ) ;
V_228 = F_100 () ;
V_229 = V_228 - V_29 -> V_5 . V_234 ;
V_231 = V_31 - V_29 -> V_5 . V_235 ;
#ifdef F_52
V_231 = ( V_231 * 1000 ) / V_2 -> V_5 . V_220 ;
#else
asm("idivl %2; xor %%edx, %%edx"
: "=A"(usdiff)
: "A"(usdiff * 1000), "rm"(vcpu->arch.virtual_tsc_khz));
#endif
F_109 ( V_229 , 1000 ) ;
V_231 -= V_229 ;
if ( V_231 < 0 )
V_231 = - V_231 ;
if ( V_231 < V_236 &&
V_2 -> V_5 . V_220 == V_29 -> V_5 . V_237 ) {
if ( ! F_114 () ) {
V_74 = V_29 -> V_5 . V_238 ;
F_99 ( L_4 , V_31 ) ;
} else {
T_2 V_239 = F_106 ( V_2 , V_229 ) ;
V_31 += V_239 ;
V_74 = V_56 -> V_233 ( V_2 , V_31 ) ;
F_99 ( L_5 , V_239 ) ;
}
} else {
V_29 -> V_5 . V_240 ++ ;
V_29 -> V_5 . V_241 = V_228 ;
V_29 -> V_5 . V_242 = V_31 ;
V_29 -> V_5 . V_238 = V_74 ;
F_99 ( L_6 ,
V_29 -> V_5 . V_240 , V_31 ) ;
}
V_29 -> V_5 . V_234 = V_228 ;
V_29 -> V_5 . V_235 = V_31 ;
V_29 -> V_5 . V_237 = V_2 -> V_5 . V_220 ;
V_2 -> V_5 . V_243 . V_244 = 0 ;
V_2 -> V_5 . V_245 = V_31 ;
V_2 -> V_5 . V_246 = V_29 -> V_5 . V_240 ;
V_2 -> V_5 . V_226 = V_29 -> V_5 . V_241 ;
V_2 -> V_5 . V_227 = V_29 -> V_5 . V_242 ;
V_56 -> V_247 ( V_2 , V_74 ) ;
F_115 ( & V_29 -> V_5 . V_232 , V_230 ) ;
}
static int F_116 ( struct V_1 * V_214 )
{
unsigned long V_230 ;
struct V_248 * V_2 = & V_214 -> V_5 ;
void * V_249 ;
unsigned long V_215 ;
T_10 V_224 , V_250 ;
T_2 V_244 ;
F_117 ( V_230 ) ;
V_244 = V_56 -> V_251 ( V_214 ) ;
V_224 = F_100 () ;
V_215 = F_8 ( V_252 ) ;
if ( F_71 ( V_215 == 0 ) ) {
F_118 ( V_230 ) ;
F_23 ( V_253 , V_214 ) ;
return 1 ;
}
if ( V_2 -> V_254 ) {
T_2 V_225 = F_111 ( V_214 , V_224 ) ;
if ( V_225 > V_244 ) {
F_119 ( V_214 , V_225 - V_244 ) ;
V_244 = V_225 ;
}
}
F_118 ( V_230 ) ;
if ( ! V_2 -> V_255 )
return 0 ;
V_250 = 0 ;
if ( V_2 -> V_243 . V_244 ) {
V_250 = V_2 -> V_245 -
V_2 -> V_243 . V_244 ;
V_250 = F_107 ( V_250 ,
V_2 -> V_243 . V_256 ,
V_2 -> V_243 . V_257 ) ;
V_250 += V_2 -> V_258 ;
}
if ( F_71 ( V_2 -> V_259 != V_215 ) ) {
F_98 ( V_219 / 1000 , V_215 ,
& V_2 -> V_243 . V_257 ,
& V_2 -> V_243 . V_256 ) ;
V_2 -> V_259 = V_215 ;
}
if ( V_250 > V_224 )
V_224 = V_250 ;
V_2 -> V_243 . V_244 = V_244 ;
V_2 -> V_243 . V_260 = V_224 + V_214 -> V_29 -> V_5 . V_191 ;
V_2 -> V_258 = V_224 ;
V_2 -> V_245 = V_244 ;
V_2 -> V_243 . V_230 = 0 ;
V_2 -> V_243 . V_186 += 2 ;
V_249 = F_120 ( V_2 -> V_255 ) ;
memcpy ( V_249 + V_2 -> V_261 , & V_2 -> V_243 ,
sizeof( V_2 -> V_243 ) ) ;
F_121 ( V_249 ) ;
F_122 ( V_214 -> V_29 , V_2 -> time >> V_86 ) ;
return 0 ;
}
static bool F_123 ( unsigned V_21 )
{
switch ( V_21 ) {
case 0x200 ... 0x200 + 2 * V_262 - 1 :
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
case V_273 :
case V_274 :
case V_275 :
return true ;
case 0x2f8 :
return true ;
}
return false ;
}
static bool F_124 ( unsigned V_276 )
{
return V_276 < 8 && ( 1 << V_276 ) & 0xf3 ;
}
static bool F_125 ( unsigned V_276 )
{
return V_276 < 8 && ( 1 << V_276 ) & 0x73 ;
}
static bool F_126 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
int V_3 ;
if ( ! F_123 ( V_21 ) )
return false ;
if ( V_21 == V_275 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_124 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
} else if ( V_21 == V_274 ) {
if ( V_31 & ~ 0xcff )
return false ;
return F_125 ( V_31 & 0xff ) ;
} else if ( V_21 >= V_263 && V_21 <= V_273 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_125 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
}
return F_125 ( V_31 & 0xff ) ;
}
static int F_127 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
T_2 * V_277 = ( T_2 * ) & V_2 -> V_5 . V_278 . V_279 ;
if ( ! F_126 ( V_2 , V_21 , V_31 ) )
return 1 ;
if ( V_21 == V_274 ) {
V_2 -> V_5 . V_278 . V_280 = V_31 ;
V_2 -> V_5 . V_278 . V_281 = ( V_31 & 0xc00 ) >> 10 ;
} else if ( V_21 == V_263 )
V_277 [ 0 ] = V_31 ;
else if ( V_21 == V_264 || V_21 == V_265 )
V_277 [ 1 + V_21 - V_264 ] = V_31 ;
else if ( V_21 >= V_266 && V_21 <= V_273 )
V_277 [ 3 + V_21 - V_266 ] = V_31 ;
else if ( V_21 == V_275 )
V_2 -> V_5 . V_282 = V_31 ;
else {
int V_283 , V_284 ;
T_2 * V_285 ;
V_283 = ( V_21 - 0x200 ) / 2 ;
V_284 = V_21 - 0x200 - 2 * V_283 ;
if ( ! V_284 )
V_285 =
( T_2 * ) & V_2 -> V_5 . V_278 . V_286 [ V_283 ] . V_287 ;
else
V_285 =
( T_2 * ) & V_2 -> V_5 . V_278 . V_286 [ V_283 ] . V_288 ;
* V_285 = V_31 ;
}
F_56 ( V_2 ) ;
return 0 ;
}
static int F_128 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
T_2 V_289 = V_2 -> V_5 . V_289 ;
unsigned V_290 = V_289 & 0xff ;
switch ( V_21 ) {
case V_291 :
V_2 -> V_5 . V_292 = V_31 ;
break;
case V_293 :
if ( ! ( V_289 & V_294 ) )
return 1 ;
if ( V_31 != 0 && V_31 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_295 = V_31 ;
break;
default:
if ( V_21 >= V_296 &&
V_21 < V_296 + 4 * V_290 ) {
T_1 V_74 = V_21 - V_296 ;
if ( ( V_74 & 0x3 ) == 0 &&
V_31 != 0 && ( V_31 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_297 [ V_74 ] = V_31 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_129 ( struct V_1 * V_2 , T_2 V_31 )
{
struct V_29 * V_29 = V_2 -> V_29 ;
int V_298 = F_46 ( V_2 ) ;
T_11 * V_299 = V_298 ? ( T_11 * ) ( long ) V_29 -> V_5 . F_129 . V_300
: ( T_11 * ) ( long ) V_29 -> V_5 . F_129 . V_301 ;
T_11 V_302 = V_298 ? V_29 -> V_5 . F_129 . V_303
: V_29 -> V_5 . F_129 . V_304 ;
T_1 V_305 = V_31 & ~ V_306 ;
T_2 V_307 = V_31 & V_306 ;
T_11 * V_308 ;
int V_99 ;
V_99 = - V_309 ;
if ( V_305 >= V_302 )
goto V_93;
V_99 = - V_310 ;
V_308 = F_130 ( V_299 + ( V_305 * V_87 ) , V_87 ) ;
if ( F_131 ( V_308 ) ) {
V_99 = F_132 ( V_308 ) ;
goto V_93;
}
if ( F_93 ( V_29 , V_307 , V_308 , V_87 ) )
goto V_311;
V_99 = 0 ;
V_311:
F_133 ( V_308 ) ;
V_93:
return V_99 ;
}
static bool F_134 ( struct V_29 * V_29 )
{
return V_29 -> V_5 . V_312 & V_313 ;
}
static bool F_135 ( T_1 V_21 )
{
bool V_99 = false ;
switch ( V_21 ) {
case V_314 :
case V_315 :
V_99 = true ;
break;
}
return V_99 ;
}
static int F_136 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
struct V_29 * V_29 = V_2 -> V_29 ;
switch ( V_21 ) {
case V_314 :
V_29 -> V_5 . V_316 = V_31 ;
if ( ! V_29 -> V_5 . V_316 )
V_29 -> V_5 . V_312 &= ~ V_313 ;
break;
case V_315 : {
T_2 V_82 ;
unsigned long V_317 ;
T_11 V_318 [ 4 ] ;
if ( ! V_29 -> V_5 . V_316 )
break;
if ( ! ( V_31 & V_313 ) ) {
V_29 -> V_5 . V_312 = V_31 ;
break;
}
V_82 = V_31 >> V_319 ;
V_317 = F_137 ( V_29 , V_82 ) ;
if ( F_138 ( V_317 ) )
return 1 ;
V_56 -> V_320 ( V_2 , V_318 ) ;
( ( unsigned char * ) V_318 ) [ 3 ] = 0xc3 ;
if ( F_139 ( ( void V_321 * ) V_317 , V_318 , 4 ) )
return 1 ;
V_29 -> V_5 . V_312 = V_31 ;
break;
}
default:
F_140 ( V_2 , L_7
L_8 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_141 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
switch ( V_21 ) {
case V_322 : {
unsigned long V_317 ;
if ( ! ( V_31 & V_323 ) ) {
V_2 -> V_5 . V_324 = V_31 ;
break;
}
V_317 = F_137 ( V_2 -> V_29 , V_31 >>
V_325 ) ;
if ( F_138 ( V_317 ) )
return 1 ;
if ( F_142 ( ( void V_321 * ) V_317 , V_87 ) )
return 1 ;
V_2 -> V_5 . V_324 = V_31 ;
break;
}
case V_326 :
return F_143 ( V_2 , V_327 , V_31 ) ;
case V_328 :
return F_143 ( V_2 , V_329 , V_31 ) ;
case V_330 :
return F_143 ( V_2 , V_331 , V_31 ) ;
default:
F_140 ( V_2 , L_7
L_8 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_144 ( struct V_1 * V_2 , T_2 V_31 )
{
T_4 V_332 = V_31 & ~ 0x3f ;
if ( V_31 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_333 = V_31 ;
if ( ! ( V_31 & V_334 ) ) {
F_55 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_145 ( V_2 -> V_29 , & V_2 -> V_5 . V_6 . V_31 , V_332 ) )
return 1 ;
V_2 -> V_5 . V_6 . V_335 = ! ( V_31 & V_336 ) ;
F_146 ( V_2 ) ;
return 0 ;
}
static void F_147 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_255 ) {
F_148 ( V_2 -> V_5 . V_255 ) ;
V_2 -> V_5 . V_255 = NULL ;
}
}
static void F_149 ( struct V_1 * V_2 )
{
T_2 V_239 ;
if ( ! ( V_2 -> V_5 . V_337 . V_333 & V_338 ) )
return;
V_239 = V_339 -> V_340 . V_341 - V_2 -> V_5 . V_337 . V_342 ;
V_2 -> V_5 . V_337 . V_342 = V_339 -> V_340 . V_341 ;
V_2 -> V_5 . V_337 . V_343 = V_239 ;
}
static void F_150 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_337 . V_333 & V_338 ) )
return;
if ( F_71 ( F_151 ( V_2 -> V_29 , & V_2 -> V_5 . V_337 . V_344 ,
& V_2 -> V_5 . V_337 . V_345 , sizeof( struct V_346 ) ) ) )
return;
V_2 -> V_5 . V_337 . V_345 . V_345 += V_2 -> V_5 . V_337 . V_343 ;
V_2 -> V_5 . V_337 . V_345 . V_186 += 2 ;
V_2 -> V_5 . V_337 . V_343 = 0 ;
F_152 ( V_2 -> V_29 , & V_2 -> V_5 . V_337 . V_344 ,
& V_2 -> V_5 . V_337 . V_345 , sizeof( struct V_346 ) ) ;
}
int F_153 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
bool V_347 = false ;
switch ( V_21 ) {
case V_348 :
return F_85 ( V_2 , V_31 ) ;
case V_349 :
V_31 &= ~ ( T_2 ) 0x40 ;
V_31 &= ~ ( T_2 ) 0x100 ;
V_31 &= ~ ( T_2 ) 0x8 ;
if ( V_31 != 0 ) {
F_140 ( V_2 , L_9 ,
V_31 ) ;
return 1 ;
}
break;
case V_350 :
if ( V_31 != 0 ) {
F_140 ( V_2 , L_10
L_11 , V_31 ) ;
return 1 ;
}
break;
case V_351 :
break;
case V_352 :
if ( ! V_31 ) {
break;
} else if ( V_31 & ~ ( V_353 | V_354 ) ) {
return 1 ;
}
F_140 ( V_2 , L_12 ,
V_209 , V_31 ) ;
break;
case V_355 :
case V_356 :
case V_357 :
case V_358 :
break;
case 0x200 ... 0x2ff :
return F_127 ( V_2 , V_21 , V_31 ) ;
case V_359 :
F_19 ( V_2 , V_31 ) ;
break;
case V_360 ... V_360 + 0x3ff :
return F_154 ( V_2 , V_21 , V_31 ) ;
case V_361 :
F_155 ( V_2 , V_31 ) ;
break;
case V_362 :
V_2 -> V_5 . V_363 = V_31 ;
break;
case V_364 :
case V_365 :
V_2 -> V_29 -> V_5 . V_185 = V_31 ;
F_91 ( V_2 -> V_29 , V_31 ) ;
break;
case V_366 :
case V_367 : {
F_147 ( V_2 ) ;
V_2 -> V_5 . time = V_31 ;
F_23 ( V_253 , V_2 ) ;
if ( ! ( V_31 & 1 ) )
break;
V_2 -> V_5 . V_261 = V_31 & ~ ( V_306 | 1 ) ;
V_2 -> V_5 . V_255 =
F_156 ( V_2 -> V_29 , V_31 >> V_86 ) ;
if ( F_157 ( V_2 -> V_5 . V_255 ) ) {
F_158 ( V_2 -> V_5 . V_255 ) ;
V_2 -> V_5 . V_255 = NULL ;
}
break;
}
case V_368 :
if ( F_144 ( V_2 , V_31 ) )
return 1 ;
break;
case V_369 :
if ( F_71 ( ! F_159 () ) )
return 1 ;
if ( V_31 & V_370 )
return 1 ;
if ( F_145 ( V_2 -> V_29 , & V_2 -> V_5 . V_337 . V_344 ,
V_31 & V_371 ) )
return 1 ;
V_2 -> V_5 . V_337 . V_333 = V_31 ;
if ( ! ( V_31 & V_338 ) )
break;
V_2 -> V_5 . V_337 . V_342 = V_339 -> V_340 . V_341 ;
F_160 () ;
F_149 ( V_2 ) ;
F_161 () ;
F_23 ( V_372 , V_2 ) ;
break;
case V_373 :
if ( F_162 ( V_2 , V_31 ) )
return 1 ;
break;
case V_293 :
case V_291 :
case V_296 ... V_296 + 4 * V_374 - 1 :
return F_128 ( V_2 , V_21 , V_31 ) ;
case V_375 :
case V_376 :
case V_377 :
case V_378 :
if ( V_31 != 0 )
F_140 ( V_2 , L_13
L_14 , V_21 , V_31 ) ;
break;
case V_379 :
case V_380 :
case V_381 :
case V_382 :
F_140 ( V_2 , L_13
L_14 , V_21 , V_31 ) ;
break;
case V_383 :
case V_384 :
V_347 = true ;
case V_385 :
case V_386 :
if ( F_163 ( V_2 , V_21 ) )
return F_164 ( V_2 , V_21 , V_31 ) ;
if ( V_347 || V_31 != 0 )
F_140 ( V_2 , L_15
L_14 , V_21 , V_31 ) ;
break;
case V_387 :
break;
case V_314 ... V_388 :
if ( F_135 ( V_21 ) ) {
int V_99 ;
F_165 ( & V_2 -> V_29 -> V_389 ) ;
V_99 = F_136 ( V_2 , V_21 , V_31 ) ;
F_166 ( & V_2 -> V_29 -> V_389 ) ;
return V_99 ;
} else
return F_141 ( V_2 , V_21 , V_31 ) ;
break;
case V_390 :
F_140 ( V_2 , L_16 , V_21 , V_31 ) ;
break;
case V_391 :
if ( ! F_167 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_392 . V_393 = V_31 ;
break;
case V_394 :
if ( ! F_167 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_392 . V_395 = V_31 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_29 -> V_5 . F_129 . V_21 ) )
return F_129 ( V_2 , V_31 ) ;
if ( F_163 ( V_2 , V_21 ) )
return F_164 ( V_2 , V_21 , V_31 ) ;
if ( ! V_396 ) {
F_140 ( V_2 , L_17 ,
V_21 , V_31 ) ;
return 1 ;
} else {
F_140 ( V_2 , L_16 ,
V_21 , V_31 ) ;
break;
}
}
return 0 ;
}
int F_168 ( struct V_1 * V_2 , T_1 V_183 , T_2 * V_397 )
{
return V_56 -> V_398 ( V_2 , V_183 , V_397 ) ;
}
static int F_169 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_397 )
{
T_2 * V_277 = ( T_2 * ) & V_2 -> V_5 . V_278 . V_279 ;
if ( ! F_123 ( V_21 ) )
return 1 ;
if ( V_21 == V_274 )
* V_397 = V_2 -> V_5 . V_278 . V_280 +
( V_2 -> V_5 . V_278 . V_281 << 10 ) ;
else if ( V_21 == V_263 )
* V_397 = V_277 [ 0 ] ;
else if ( V_21 == V_264 || V_21 == V_265 )
* V_397 = V_277 [ 1 + V_21 - V_264 ] ;
else if ( V_21 >= V_266 && V_21 <= V_273 )
* V_397 = V_277 [ 3 + V_21 - V_266 ] ;
else if ( V_21 == V_275 )
* V_397 = V_2 -> V_5 . V_282 ;
else {
int V_283 , V_284 ;
T_2 * V_285 ;
V_283 = ( V_21 - 0x200 ) / 2 ;
V_284 = V_21 - 0x200 - 2 * V_283 ;
if ( ! V_284 )
V_285 =
( T_2 * ) & V_2 -> V_5 . V_278 . V_286 [ V_283 ] . V_287 ;
else
V_285 =
( T_2 * ) & V_2 -> V_5 . V_278 . V_286 [ V_283 ] . V_288 ;
* V_397 = * V_285 ;
}
return 0 ;
}
static int F_170 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_397 )
{
T_2 V_31 ;
T_2 V_289 = V_2 -> V_5 . V_289 ;
unsigned V_290 = V_289 & 0xff ;
switch ( V_21 ) {
case V_399 :
case V_400 :
V_31 = 0 ;
break;
case V_401 :
V_31 = V_2 -> V_5 . V_289 ;
break;
case V_293 :
if ( ! ( V_289 & V_294 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_295 ;
break;
case V_291 :
V_31 = V_2 -> V_5 . V_292 ;
break;
default:
if ( V_21 >= V_296 &&
V_21 < V_296 + 4 * V_290 ) {
T_1 V_74 = V_21 - V_296 ;
V_31 = V_2 -> V_5 . V_297 [ V_74 ] ;
break;
}
return 1 ;
}
* V_397 = V_31 ;
return 0 ;
}
static int F_171 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_397 )
{
T_2 V_31 = 0 ;
struct V_29 * V_29 = V_2 -> V_29 ;
switch ( V_21 ) {
case V_314 :
V_31 = V_29 -> V_5 . V_316 ;
break;
case V_315 :
V_31 = V_29 -> V_5 . V_312 ;
break;
default:
F_140 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_397 = V_31 ;
return 0 ;
}
static int F_172 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_397 )
{
T_2 V_31 = 0 ;
switch ( V_21 ) {
case V_402 : {
int V_99 ;
struct V_1 * V_214 ;
F_173 (r, v, vcpu->kvm)
if ( V_214 == V_2 )
V_31 = V_99 ;
break;
}
case V_326 :
return F_174 ( V_2 , V_327 , V_397 ) ;
case V_328 :
return F_174 ( V_2 , V_329 , V_397 ) ;
case V_330 :
return F_174 ( V_2 , V_331 , V_397 ) ;
case V_322 :
V_31 = V_2 -> V_5 . V_324 ;
break;
default:
F_140 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_397 = V_31 ;
return 0 ;
}
int F_175 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_397 )
{
T_2 V_31 ;
switch ( V_21 ) {
case V_403 :
case V_404 :
case V_352 :
case V_405 :
case V_406 :
case V_407 :
case V_408 :
case V_409 :
case V_349 :
case V_357 :
case V_375 :
case V_379 :
case V_410 :
case V_351 :
case V_350 :
V_31 = 0 ;
break;
case V_383 :
case V_384 :
case V_385 :
case V_386 :
if ( F_163 ( V_2 , V_21 ) )
return F_176 ( V_2 , V_21 , V_397 ) ;
V_31 = 0 ;
break;
case V_355 :
V_31 = 0x100000000ULL ;
break;
case V_411 :
V_31 = 0x500 | V_262 ;
break;
case 0x200 ... 0x2ff :
return F_169 ( V_2 , V_21 , V_397 ) ;
case 0xcd :
V_31 = 3 ;
break;
case V_412 :
V_31 = 1 << 24 ;
break;
case V_359 :
V_31 = F_17 ( V_2 ) ;
break;
case V_360 ... V_360 + 0x3ff :
return F_177 ( V_2 , V_21 , V_397 ) ;
break;
case V_361 :
V_31 = F_178 ( V_2 ) ;
break;
case V_362 :
V_31 = V_2 -> V_5 . V_363 ;
break;
case V_413 :
V_31 = 1000ULL ;
V_31 |= ( ( ( T_7 ) 4ULL ) << 40 ) ;
break;
case V_348 :
V_31 = V_2 -> V_5 . V_110 ;
break;
case V_365 :
case V_364 :
V_31 = V_2 -> V_29 -> V_5 . V_185 ;
break;
case V_367 :
case V_366 :
V_31 = V_2 -> V_5 . time ;
break;
case V_368 :
V_31 = V_2 -> V_5 . V_6 . V_333 ;
break;
case V_369 :
V_31 = V_2 -> V_5 . V_337 . V_333 ;
break;
case V_373 :
V_31 = V_2 -> V_5 . V_414 . V_333 ;
break;
case V_399 :
case V_400 :
case V_401 :
case V_293 :
case V_291 :
case V_296 ... V_296 + 4 * V_374 - 1 :
return F_170 ( V_2 , V_21 , V_397 ) ;
case V_387 :
V_31 = 0x20000000 ;
break;
case V_314 ... V_388 :
if ( F_135 ( V_21 ) ) {
int V_99 ;
F_165 ( & V_2 -> V_29 -> V_389 ) ;
V_99 = F_171 ( V_2 , V_21 , V_397 ) ;
F_166 ( & V_2 -> V_29 -> V_389 ) ;
return V_99 ;
} else
return F_172 ( V_2 , V_21 , V_397 ) ;
break;
case V_390 :
V_31 = 0xbe702111 ;
break;
case V_391 :
if ( ! F_167 ( V_2 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_392 . V_393 ;
break;
case V_394 :
if ( ! F_167 ( V_2 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_392 . V_395 ;
break;
default:
if ( F_163 ( V_2 , V_21 ) )
return F_176 ( V_2 , V_21 , V_397 ) ;
if ( ! V_396 ) {
F_140 ( V_2 , L_19 , V_21 ) ;
return 1 ;
} else {
F_140 ( V_2 , L_20 , V_21 ) ;
V_31 = 0 ;
}
break;
}
* V_397 = V_31 ;
return 0 ;
}
static int F_179 ( struct V_1 * V_2 , struct V_415 * V_19 ,
struct V_416 * V_417 ,
int (* F_180)( struct V_1 * V_2 ,
unsigned V_118 , T_2 * V_31 ) )
{
int V_3 , V_283 ;
V_283 = F_181 ( & V_2 -> V_29 -> V_418 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_419 ; ++ V_3 )
if ( F_180 ( V_2 , V_417 [ V_3 ] . V_118 , & V_417 [ V_3 ] . V_31 ) )
break;
F_182 ( & V_2 -> V_29 -> V_418 , V_283 ) ;
return V_3 ;
}
static int F_183 ( struct V_1 * V_2 , struct V_415 V_321 * V_420 ,
int (* F_180)( struct V_1 * V_2 ,
unsigned V_118 , T_2 * V_31 ) ,
int V_421 )
{
struct V_415 V_19 ;
struct V_416 * V_417 ;
int V_99 , V_422 ;
unsigned V_423 ;
V_99 = - V_81 ;
if ( F_184 ( & V_19 , V_420 , sizeof V_19 ) )
goto V_93;
V_99 = - V_309 ;
if ( V_19 . V_419 >= V_424 )
goto V_93;
V_423 = sizeof( struct V_416 ) * V_19 . V_419 ;
V_417 = F_130 ( V_420 -> V_417 , V_423 ) ;
if ( F_131 ( V_417 ) ) {
V_99 = F_132 ( V_417 ) ;
goto V_93;
}
V_99 = V_422 = F_179 ( V_2 , & V_19 , V_417 , F_180 ) ;
if ( V_99 < 0 )
goto V_311;
V_99 = - V_81 ;
if ( V_421 && F_185 ( V_420 -> V_417 , V_417 , V_423 ) )
goto V_311;
V_99 = V_422 ;
V_311:
F_133 ( V_417 ) ;
V_93:
return V_99 ;
}
int F_186 ( long V_425 )
{
int V_99 ;
switch ( V_425 ) {
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
case V_453 :
case V_454 :
case V_455 :
case V_456 :
case V_457 :
case V_458 :
V_99 = 1 ;
break;
case V_459 :
V_99 = V_460 ;
break;
case V_461 :
V_99 = ! V_56 -> V_462 () ;
break;
case V_463 :
V_99 = V_464 ;
break;
case V_465 :
V_99 = V_466 ;
break;
case V_467 :
V_99 = V_468 ;
break;
case V_469 :
V_99 = 0 ;
break;
case V_470 :
V_99 = F_187 ( & V_471 ) ;
break;
case V_472 :
V_99 = V_374 ;
break;
case V_473 :
V_99 = V_474 ;
break;
case V_475 :
V_99 = V_476 ;
break;
case V_477 :
V_99 = F_188 ( V_478 ) ;
break;
default:
V_99 = 0 ;
break;
}
return V_99 ;
}
long F_189 ( struct V_479 * V_480 ,
unsigned int V_481 , unsigned long V_482 )
{
void V_321 * V_483 = ( void V_321 * ) V_482 ;
long V_99 ;
switch ( V_481 ) {
case V_484 : {
struct V_485 V_321 * V_486 = V_483 ;
struct V_485 V_487 ;
unsigned V_422 ;
V_99 = - V_81 ;
if ( F_184 ( & V_487 , V_486 , sizeof V_487 ) )
goto V_93;
V_422 = V_487 . V_419 ;
V_487 . V_419 = V_488 + F_42 ( V_489 ) ;
if ( F_185 ( V_486 , & V_487 , sizeof V_487 ) )
goto V_93;
V_99 = - V_309 ;
if ( V_422 < V_487 . V_419 )
goto V_93;
V_99 = - V_81 ;
if ( F_185 ( V_486 -> V_490 , & V_491 ,
V_488 * sizeof( T_1 ) ) )
goto V_93;
if ( F_185 ( V_486 -> V_490 + V_488 ,
& V_489 ,
F_42 ( V_489 ) * sizeof( T_1 ) ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_492 : {
struct V_493 V_321 * V_494 = V_483 ;
struct V_493 V_495 ;
V_99 = - V_81 ;
if ( F_184 ( & V_495 , V_494 , sizeof V_495 ) )
goto V_93;
V_99 = F_190 ( & V_495 ,
V_494 -> V_417 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_185 ( V_494 , & V_495 , sizeof V_495 ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_496 : {
T_2 V_497 ;
V_497 = V_498 ;
V_99 = - V_81 ;
if ( F_185 ( V_483 , & V_497 , sizeof V_497 ) )
goto V_93;
V_99 = 0 ;
break;
}
default:
V_99 = - V_499 ;
}
V_93:
return V_99 ;
}
static void F_191 ( void * V_500 )
{
F_192 () ;
}
static bool F_193 ( struct V_1 * V_2 )
{
return V_2 -> V_29 -> V_5 . V_501 &&
! ( V_2 -> V_29 -> V_5 . V_502 & V_503 ) ;
}
void F_194 ( struct V_1 * V_2 , int V_504 )
{
if ( F_193 ( V_2 ) ) {
if ( V_56 -> V_505 () )
F_195 ( V_504 , V_2 -> V_5 . V_506 ) ;
else if ( V_2 -> V_504 != - 1 && V_2 -> V_504 != V_504 )
F_196 ( V_2 -> V_504 ,
F_191 , NULL , 1 ) ;
}
V_56 -> V_507 ( V_2 , V_504 ) ;
if ( F_71 ( V_2 -> V_5 . V_508 ) ) {
F_197 ( V_2 , V_2 -> V_5 . V_508 ) ;
V_2 -> V_5 . V_508 = 0 ;
F_198 ( V_253 , & V_2 -> V_509 ) ;
}
if ( F_71 ( V_2 -> V_504 != V_504 ) || F_114 () ) {
T_10 V_510 = ! V_2 -> V_5 . V_511 ? 0 :
F_199 () - V_2 -> V_5 . V_511 ;
if ( V_510 < 0 )
F_200 ( L_21 ) ;
if ( F_114 () ) {
T_2 V_74 = V_56 -> V_233 ( V_2 ,
V_2 -> V_5 . V_245 ) ;
V_56 -> V_247 ( V_2 , V_74 ) ;
V_2 -> V_5 . V_254 = 1 ;
}
F_23 ( V_253 , V_2 ) ;
if ( V_2 -> V_504 != V_504 )
F_201 ( V_2 ) ;
V_2 -> V_504 = V_504 ;
}
F_149 ( V_2 ) ;
F_23 ( V_372 , V_2 ) ;
}
void F_202 ( struct V_1 * V_2 )
{
V_56 -> V_512 ( V_2 ) ;
F_203 ( V_2 ) ;
V_2 -> V_5 . V_511 = F_199 () ;
}
static int F_204 ( struct V_1 * V_2 ,
struct V_513 * V_514 )
{
memcpy ( V_514 -> V_515 , V_2 -> V_5 . V_516 -> V_515 , sizeof *V_514 ) ;
return 0 ;
}
static int F_205 ( struct V_1 * V_2 ,
struct V_513 * V_514 )
{
memcpy ( V_2 -> V_5 . V_516 -> V_515 , V_514 -> V_515 , sizeof *V_514 ) ;
F_206 ( V_2 ) ;
F_207 ( V_2 ) ;
return 0 ;
}
static int F_208 ( struct V_1 * V_2 ,
struct V_517 * V_518 )
{
if ( V_518 -> V_518 < 0 || V_518 -> V_518 >= 256 )
return - V_499 ;
if ( F_18 ( V_2 -> V_29 ) )
return - V_519 ;
F_209 ( V_2 , V_518 -> V_518 , false ) ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
static int F_210 ( struct V_1 * V_2 )
{
F_32 ( V_2 ) ;
return 0 ;
}
static int F_211 ( struct V_1 * V_2 ,
struct V_520 * V_521 )
{
if ( V_521 -> V_230 )
return - V_499 ;
V_2 -> V_5 . V_522 = ! ! V_521 -> V_281 ;
return 0 ;
}
static int F_212 ( struct V_1 * V_2 ,
T_2 V_289 )
{
int V_99 ;
unsigned V_290 = V_289 & 0xff , V_523 ;
V_99 = - V_499 ;
if ( ! V_290 || V_290 >= V_374 )
goto V_93;
if ( V_289 & ~ ( V_498 | 0xff | 0xff0000 ) )
goto V_93;
V_99 = 0 ;
V_2 -> V_5 . V_289 = V_289 ;
if ( V_289 & V_294 )
V_2 -> V_5 . V_295 = ~ ( T_2 ) 0 ;
for ( V_523 = 0 ; V_523 < V_290 ; V_523 ++ )
V_2 -> V_5 . V_297 [ V_523 * 4 ] = ~ ( T_2 ) 0 ;
V_93:
return V_99 ;
}
static int F_213 ( struct V_1 * V_2 ,
struct V_524 * V_525 )
{
T_2 V_289 = V_2 -> V_5 . V_289 ;
unsigned V_290 = V_289 & 0xff ;
T_2 * V_526 = V_2 -> V_5 . V_297 ;
if ( V_525 -> V_523 >= V_290 || ! ( V_525 -> V_395 & V_527 ) )
return - V_499 ;
if ( ( V_525 -> V_395 & V_528 ) && ( V_289 & V_294 ) &&
V_2 -> V_5 . V_295 != ~ ( T_2 ) 0 )
return 0 ;
V_526 += 4 * V_525 -> V_523 ;
if ( ( V_525 -> V_395 & V_528 ) && V_526 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_525 -> V_395 & V_528 ) {
if ( ( V_2 -> V_5 . V_292 & V_529 ) ||
! F_54 ( V_2 , V_530 ) ) {
F_23 ( V_54 , V_2 ) ;
return 0 ;
}
if ( V_526 [ 1 ] & V_527 )
V_525 -> V_395 |= V_531 ;
V_526 [ 2 ] = V_525 -> V_317 ;
V_526 [ 3 ] = V_525 -> V_532 ;
V_2 -> V_5 . V_292 = V_525 -> V_292 ;
V_526 [ 1 ] = V_525 -> V_395 ;
F_24 ( V_2 , V_533 ) ;
} else if ( ! ( V_526 [ 1 ] & V_527 )
|| ! ( V_526 [ 1 ] & V_528 ) ) {
if ( V_526 [ 1 ] & V_527 )
V_525 -> V_395 |= V_531 ;
V_526 [ 2 ] = V_525 -> V_317 ;
V_526 [ 3 ] = V_525 -> V_532 ;
V_526 [ 1 ] = V_525 -> V_395 ;
} else
V_526 [ 1 ] |= V_531 ;
return 0 ;
}
static void F_214 ( struct V_1 * V_2 ,
struct V_534 * V_535 )
{
F_215 ( V_2 ) ;
V_535 -> V_49 . V_536 =
V_2 -> V_5 . V_49 . V_50 &&
! F_216 ( V_2 -> V_5 . V_49 . V_16 ) ;
V_535 -> V_49 . V_16 = V_2 -> V_5 . V_49 . V_16 ;
V_535 -> V_49 . V_52 = V_2 -> V_5 . V_49 . V_52 ;
V_535 -> V_49 . V_537 = 0 ;
V_535 -> V_49 . V_43 = V_2 -> V_5 . V_49 . V_43 ;
V_535 -> V_538 . V_536 =
V_2 -> V_5 . V_538 . V_50 && ! V_2 -> V_5 . V_538 . V_539 ;
V_535 -> V_538 . V_16 = V_2 -> V_5 . V_538 . V_16 ;
V_535 -> V_538 . V_539 = 0 ;
V_535 -> V_538 . V_540 =
V_56 -> V_541 ( V_2 ,
V_542 | V_543 ) ;
V_535 -> V_544 . V_536 = V_2 -> V_5 . V_545 ;
V_535 -> V_544 . V_50 = V_2 -> V_5 . V_546 != 0 ;
V_535 -> V_544 . V_547 = V_56 -> V_548 ( V_2 ) ;
V_535 -> V_544 . V_537 = 0 ;
V_535 -> V_549 = V_2 -> V_5 . V_549 ;
V_535 -> V_230 = ( V_550
| V_551
| V_552 ) ;
memset ( & V_535 -> V_553 , 0 , sizeof( V_535 -> V_553 ) ) ;
}
static int F_217 ( struct V_1 * V_2 ,
struct V_534 * V_535 )
{
if ( V_535 -> V_230 & ~ ( V_550
| V_551
| V_552 ) )
return - V_499 ;
F_215 ( V_2 ) ;
V_2 -> V_5 . V_49 . V_50 = V_535 -> V_49 . V_536 ;
V_2 -> V_5 . V_49 . V_16 = V_535 -> V_49 . V_16 ;
V_2 -> V_5 . V_49 . V_52 = V_535 -> V_49 . V_52 ;
V_2 -> V_5 . V_49 . V_43 = V_535 -> V_49 . V_43 ;
V_2 -> V_5 . V_538 . V_50 = V_535 -> V_538 . V_536 ;
V_2 -> V_5 . V_538 . V_16 = V_535 -> V_538 . V_16 ;
V_2 -> V_5 . V_538 . V_539 = V_535 -> V_538 . V_539 ;
if ( V_535 -> V_230 & V_552 )
V_56 -> V_554 ( V_2 ,
V_535 -> V_538 . V_540 ) ;
V_2 -> V_5 . V_545 = V_535 -> V_544 . V_536 ;
if ( V_535 -> V_230 & V_550 )
V_2 -> V_5 . V_546 = V_535 -> V_544 . V_50 ;
V_56 -> V_555 ( V_2 , V_535 -> V_544 . V_547 ) ;
if ( V_535 -> V_230 & V_551 )
V_2 -> V_5 . V_549 = V_535 -> V_549 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
static void F_218 ( struct V_1 * V_2 ,
struct V_556 * V_557 )
{
memcpy ( V_557 -> V_149 , V_2 -> V_5 . V_149 , sizeof( V_2 -> V_5 . V_149 ) ) ;
V_557 -> V_154 = V_2 -> V_5 . V_154 ;
V_557 -> V_157 = V_2 -> V_5 . V_157 ;
V_557 -> V_230 = 0 ;
memset ( & V_557 -> V_553 , 0 , sizeof( V_557 -> V_553 ) ) ;
}
static int F_219 ( struct V_1 * V_2 ,
struct V_556 * V_557 )
{
if ( V_557 -> V_230 )
return - V_499 ;
memcpy ( V_2 -> V_5 . V_149 , V_557 -> V_149 , sizeof( V_2 -> V_5 . V_149 ) ) ;
V_2 -> V_5 . V_154 = V_557 -> V_154 ;
V_2 -> V_5 . V_157 = V_557 -> V_157 ;
return 0 ;
}
static void F_220 ( struct V_1 * V_2 ,
struct V_558 * V_559 )
{
if ( V_474 )
memcpy ( V_559 -> V_560 ,
& V_2 -> V_5 . V_561 . V_562 -> V_563 ,
V_564 ) ;
else {
memcpy ( V_559 -> V_560 ,
& V_2 -> V_5 . V_561 . V_562 -> V_565 ,
sizeof( struct V_566 ) ) ;
* ( T_2 * ) & V_559 -> V_560 [ V_567 / sizeof( T_1 ) ] =
V_568 ;
}
}
static int F_221 ( struct V_1 * V_2 ,
struct V_558 * V_559 )
{
T_2 V_569 =
* ( T_2 * ) & V_559 -> V_560 [ V_567 / sizeof( T_1 ) ] ;
if ( V_474 )
memcpy ( & V_2 -> V_5 . V_561 . V_562 -> V_563 ,
V_559 -> V_560 , V_564 ) ;
else {
if ( V_569 & ~ V_568 )
return - V_499 ;
memcpy ( & V_2 -> V_5 . V_561 . V_562 -> V_565 ,
V_559 -> V_560 , sizeof( struct V_566 ) ) ;
}
return 0 ;
}
static void F_222 ( struct V_1 * V_2 ,
struct V_570 * V_571 )
{
if ( ! V_474 ) {
V_571 -> V_572 = 0 ;
return;
}
V_571 -> V_572 = 1 ;
V_571 -> V_230 = 0 ;
V_571 -> V_573 [ 0 ] . V_119 = V_121 ;
V_571 -> V_573 [ 0 ] . V_23 = V_2 -> V_5 . V_120 ;
}
static int F_223 ( struct V_1 * V_2 ,
struct V_570 * V_571 )
{
int V_3 , V_99 = 0 ;
if ( ! V_474 )
return - V_499 ;
if ( V_571 -> V_572 > V_574 || V_571 -> V_230 )
return - V_499 ;
for ( V_3 = 0 ; V_3 < V_571 -> V_572 ; V_3 ++ )
if ( V_571 -> V_573 [ 0 ] . V_119 == V_121 ) {
V_99 = F_59 ( V_2 , V_121 ,
V_571 -> V_573 [ 0 ] . V_23 ) ;
break;
}
if ( V_99 )
V_99 = - V_499 ;
return V_99 ;
}
static int F_224 ( struct V_1 * V_2 )
{
struct V_575 * V_576 = & V_2 -> V_5 . V_243 ;
if ( ! V_2 -> V_5 . V_255 )
return - V_499 ;
V_576 -> V_230 |= V_577 ;
F_122 ( V_2 -> V_29 , V_2 -> V_5 . time >> V_86 ) ;
F_23 ( V_253 , V_2 ) ;
return 0 ;
}
long F_225 ( struct V_479 * V_480 ,
unsigned int V_481 , unsigned long V_482 )
{
struct V_1 * V_2 = V_480 -> V_578 ;
void V_321 * V_483 = ( void V_321 * ) V_482 ;
int V_99 ;
union {
struct V_513 * V_579 ;
struct V_558 * V_563 ;
struct V_570 * V_573 ;
void * V_580 ;
} V_581 ;
V_581 . V_580 = NULL ;
switch ( V_481 ) {
case V_582 : {
V_99 = - V_499 ;
if ( ! V_2 -> V_5 . V_516 )
goto V_93;
V_581 . V_579 = F_226 ( sizeof( struct V_513 ) , V_583 ) ;
V_99 = - V_310 ;
if ( ! V_581 . V_579 )
goto V_93;
V_99 = F_204 ( V_2 , V_581 . V_579 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_185 ( V_483 , V_581 . V_579 , sizeof( struct V_513 ) ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_584 : {
V_99 = - V_499 ;
if ( ! V_2 -> V_5 . V_516 )
goto V_93;
V_581 . V_579 = F_130 ( V_483 , sizeof( * V_581 . V_579 ) ) ;
if ( F_131 ( V_581 . V_579 ) ) {
V_99 = F_132 ( V_581 . V_579 ) ;
goto V_93;
}
V_99 = F_205 ( V_2 , V_581 . V_579 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_585 : {
struct V_517 V_518 ;
V_99 = - V_81 ;
if ( F_184 ( & V_518 , V_483 , sizeof V_518 ) )
goto V_93;
V_99 = F_208 ( V_2 , & V_518 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_586 : {
V_99 = F_210 ( V_2 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_587 : {
struct V_588 V_321 * V_494 = V_483 ;
struct V_588 V_495 ;
V_99 = - V_81 ;
if ( F_184 ( & V_495 , V_494 , sizeof V_495 ) )
goto V_93;
V_99 = F_227 ( V_2 , & V_495 , V_494 -> V_417 ) ;
if ( V_99 )
goto V_93;
break;
}
case V_589 : {
struct V_493 V_321 * V_494 = V_483 ;
struct V_493 V_495 ;
V_99 = - V_81 ;
if ( F_184 ( & V_495 , V_494 , sizeof V_495 ) )
goto V_93;
V_99 = F_228 ( V_2 , & V_495 ,
V_494 -> V_417 ) ;
if ( V_99 )
goto V_93;
break;
}
case V_590 : {
struct V_493 V_321 * V_494 = V_483 ;
struct V_493 V_495 ;
V_99 = - V_81 ;
if ( F_184 ( & V_495 , V_494 , sizeof V_495 ) )
goto V_93;
V_99 = F_229 ( V_2 , & V_495 ,
V_494 -> V_417 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_185 ( V_494 , & V_495 , sizeof V_495 ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_591 :
V_99 = F_183 ( V_2 , V_483 , F_168 , 1 ) ;
break;
case V_592 :
V_99 = F_183 ( V_2 , V_483 , F_90 , 0 ) ;
break;
case V_593 : {
struct V_520 V_521 ;
V_99 = - V_81 ;
if ( F_184 ( & V_521 , V_483 , sizeof V_521 ) )
goto V_93;
V_99 = F_211 ( V_2 , & V_521 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_185 ( V_483 , & V_521 , sizeof V_521 ) )
goto V_93;
V_99 = 0 ;
break;
} ;
case V_594 : {
struct V_595 V_596 ;
V_99 = - V_499 ;
if ( ! F_18 ( V_2 -> V_29 ) )
goto V_93;
V_99 = - V_81 ;
if ( F_184 ( & V_596 , V_483 , sizeof V_596 ) )
goto V_93;
V_99 = 0 ;
F_230 ( V_2 , V_596 . V_597 ) ;
break;
}
case V_598 : {
T_2 V_289 ;
V_99 = - V_81 ;
if ( F_184 ( & V_289 , V_483 , sizeof V_289 ) )
goto V_93;
V_99 = F_212 ( V_2 , V_289 ) ;
break;
}
case V_599 : {
struct V_524 V_525 ;
V_99 = - V_81 ;
if ( F_184 ( & V_525 , V_483 , sizeof V_525 ) )
goto V_93;
V_99 = F_213 ( V_2 , & V_525 ) ;
break;
}
case V_600 : {
struct V_534 V_535 ;
F_214 ( V_2 , & V_535 ) ;
V_99 = - V_81 ;
if ( F_185 ( V_483 , & V_535 , sizeof( struct V_534 ) ) )
break;
V_99 = 0 ;
break;
}
case V_601 : {
struct V_534 V_535 ;
V_99 = - V_81 ;
if ( F_184 ( & V_535 , V_483 , sizeof( struct V_534 ) ) )
break;
V_99 = F_217 ( V_2 , & V_535 ) ;
break;
}
case V_602 : {
struct V_556 V_557 ;
F_218 ( V_2 , & V_557 ) ;
V_99 = - V_81 ;
if ( F_185 ( V_483 , & V_557 ,
sizeof( struct V_556 ) ) )
break;
V_99 = 0 ;
break;
}
case V_603 : {
struct V_556 V_557 ;
V_99 = - V_81 ;
if ( F_184 ( & V_557 , V_483 ,
sizeof( struct V_556 ) ) )
break;
V_99 = F_219 ( V_2 , & V_557 ) ;
break;
}
case V_604 : {
V_581 . V_563 = F_226 ( sizeof( struct V_558 ) , V_583 ) ;
V_99 = - V_310 ;
if ( ! V_581 . V_563 )
break;
F_220 ( V_2 , V_581 . V_563 ) ;
V_99 = - V_81 ;
if ( F_185 ( V_483 , V_581 . V_563 , sizeof( struct V_558 ) ) )
break;
V_99 = 0 ;
break;
}
case V_605 : {
V_581 . V_563 = F_130 ( V_483 , sizeof( * V_581 . V_563 ) ) ;
if ( F_131 ( V_581 . V_563 ) ) {
V_99 = F_132 ( V_581 . V_563 ) ;
goto V_93;
}
V_99 = F_221 ( V_2 , V_581 . V_563 ) ;
break;
}
case V_606 : {
V_581 . V_573 = F_226 ( sizeof( struct V_570 ) , V_583 ) ;
V_99 = - V_310 ;
if ( ! V_581 . V_573 )
break;
F_222 ( V_2 , V_581 . V_573 ) ;
V_99 = - V_81 ;
if ( F_185 ( V_483 , V_581 . V_573 ,
sizeof( struct V_570 ) ) )
break;
V_99 = 0 ;
break;
}
case V_607 : {
V_581 . V_573 = F_130 ( V_483 , sizeof( * V_581 . V_573 ) ) ;
if ( F_131 ( V_581 . V_573 ) ) {
V_99 = F_132 ( V_581 . V_573 ) ;
goto V_93;
}
V_99 = F_223 ( V_2 , V_581 . V_573 ) ;
break;
}
case V_608 : {
T_1 V_609 ;
V_99 = - V_499 ;
V_609 = ( T_1 ) V_482 ;
if ( V_609 >= V_610 )
goto V_93;
if ( V_609 == 0 )
V_609 = V_221 ;
F_110 ( V_2 , V_609 ) ;
V_99 = 0 ;
goto V_93;
}
case V_611 : {
V_99 = V_2 -> V_5 . V_220 ;
goto V_93;
}
case V_612 : {
V_99 = F_224 ( V_2 ) ;
goto V_93;
}
default:
V_99 = - V_499 ;
}
V_93:
F_133 ( V_581 . V_580 ) ;
return V_99 ;
}
int F_231 ( struct V_1 * V_2 , struct V_613 * V_614 )
{
return V_615 ;
}
static int F_232 ( struct V_29 * V_29 , unsigned long V_317 )
{
int V_88 ;
if ( V_317 > ( unsigned int ) ( - 3 * V_87 ) )
return - 1 ;
V_88 = V_56 -> V_616 ( V_29 , V_317 ) ;
return V_88 ;
}
static int F_233 ( struct V_29 * V_29 ,
T_2 V_617 )
{
V_29 -> V_5 . V_618 = V_617 ;
return 0 ;
}
static int F_234 ( struct V_29 * V_29 ,
T_1 V_619 )
{
if ( V_619 < V_620 )
return - V_499 ;
F_165 ( & V_29 -> V_621 ) ;
F_235 ( & V_29 -> V_622 ) ;
F_236 ( V_29 , V_619 ) ;
V_29 -> V_5 . V_623 = V_619 ;
F_237 ( & V_29 -> V_622 ) ;
F_166 ( & V_29 -> V_621 ) ;
return 0 ;
}
static int F_238 ( struct V_29 * V_29 )
{
return V_29 -> V_5 . V_624 ;
}
static int F_239 ( struct V_29 * V_29 , struct V_625 * V_626 )
{
int V_99 ;
V_99 = 0 ;
switch ( V_626 -> V_627 ) {
case V_628 :
memcpy ( & V_626 -> V_626 . V_629 ,
& F_240 ( V_29 ) -> V_630 [ 0 ] ,
sizeof( struct V_631 ) ) ;
break;
case V_632 :
memcpy ( & V_626 -> V_626 . V_629 ,
& F_240 ( V_29 ) -> V_630 [ 1 ] ,
sizeof( struct V_631 ) ) ;
break;
case V_633 :
V_99 = F_241 ( V_29 , & V_626 -> V_626 . V_634 ) ;
break;
default:
V_99 = - V_499 ;
break;
}
return V_99 ;
}
static int F_242 ( struct V_29 * V_29 , struct V_625 * V_626 )
{
int V_99 ;
V_99 = 0 ;
switch ( V_626 -> V_627 ) {
case V_628 :
F_235 ( & F_240 ( V_29 ) -> V_389 ) ;
memcpy ( & F_240 ( V_29 ) -> V_630 [ 0 ] ,
& V_626 -> V_626 . V_629 ,
sizeof( struct V_631 ) ) ;
F_237 ( & F_240 ( V_29 ) -> V_389 ) ;
break;
case V_632 :
F_235 ( & F_240 ( V_29 ) -> V_389 ) ;
memcpy ( & F_240 ( V_29 ) -> V_630 [ 1 ] ,
& V_626 -> V_626 . V_629 ,
sizeof( struct V_631 ) ) ;
F_237 ( & F_240 ( V_29 ) -> V_389 ) ;
break;
case V_633 :
V_99 = F_243 ( V_29 , & V_626 -> V_626 . V_634 ) ;
break;
default:
V_99 = - V_499 ;
break;
}
F_244 ( F_240 ( V_29 ) ) ;
return V_99 ;
}
static int F_245 ( struct V_29 * V_29 , struct V_635 * V_636 )
{
int V_99 = 0 ;
F_165 ( & V_29 -> V_5 . V_637 -> V_638 . V_389 ) ;
memcpy ( V_636 , & V_29 -> V_5 . V_637 -> V_638 , sizeof( struct V_635 ) ) ;
F_166 ( & V_29 -> V_5 . V_637 -> V_638 . V_389 ) ;
return V_99 ;
}
static int F_246 ( struct V_29 * V_29 , struct V_635 * V_636 )
{
int V_99 = 0 ;
F_165 ( & V_29 -> V_5 . V_637 -> V_638 . V_389 ) ;
memcpy ( & V_29 -> V_5 . V_637 -> V_638 , V_636 , sizeof( struct V_635 ) ) ;
F_247 ( V_29 , 0 , V_636 -> V_639 [ 0 ] . V_640 , 0 ) ;
F_166 ( & V_29 -> V_5 . V_637 -> V_638 . V_389 ) ;
return V_99 ;
}
static int F_248 ( struct V_29 * V_29 , struct V_641 * V_636 )
{
int V_99 = 0 ;
F_165 ( & V_29 -> V_5 . V_637 -> V_638 . V_389 ) ;
memcpy ( V_636 -> V_639 , & V_29 -> V_5 . V_637 -> V_638 . V_639 ,
sizeof( V_636 -> V_639 ) ) ;
V_636 -> V_230 = V_29 -> V_5 . V_637 -> V_638 . V_230 ;
F_166 ( & V_29 -> V_5 . V_637 -> V_638 . V_389 ) ;
memset ( & V_636 -> V_553 , 0 , sizeof( V_636 -> V_553 ) ) ;
return V_99 ;
}
static int F_249 ( struct V_29 * V_29 , struct V_641 * V_636 )
{
int V_99 = 0 , V_642 = 0 ;
T_1 V_643 , V_644 ;
F_165 ( & V_29 -> V_5 . V_637 -> V_638 . V_389 ) ;
V_643 = V_29 -> V_5 . V_637 -> V_638 . V_230 & V_645 ;
V_644 = V_636 -> V_230 & V_645 ;
if ( ! V_643 && V_644 )
V_642 = 1 ;
memcpy ( & V_29 -> V_5 . V_637 -> V_638 . V_639 , & V_636 -> V_639 ,
sizeof( V_29 -> V_5 . V_637 -> V_638 . V_639 ) ) ;
V_29 -> V_5 . V_637 -> V_638 . V_230 = V_636 -> V_230 ;
F_247 ( V_29 , 0 , V_29 -> V_5 . V_637 -> V_638 . V_639 [ 0 ] . V_640 , V_642 ) ;
F_166 ( & V_29 -> V_5 . V_637 -> V_638 . V_389 ) ;
return V_99 ;
}
static int F_250 ( struct V_29 * V_29 ,
struct V_646 * V_647 )
{
if ( ! V_29 -> V_5 . V_637 )
return - V_519 ;
F_165 ( & V_29 -> V_5 . V_637 -> V_638 . V_389 ) ;
V_29 -> V_5 . V_637 -> V_638 . V_648 . V_44 = V_647 -> V_649 ;
F_166 ( & V_29 -> V_5 . V_637 -> V_638 . V_389 ) ;
return 0 ;
}
int F_251 ( struct V_29 * V_29 , struct V_650 * log )
{
int V_99 ;
struct V_651 * V_652 ;
unsigned long V_422 , V_3 ;
unsigned long * V_653 ;
unsigned long * V_654 ;
bool V_655 = false ;
F_165 ( & V_29 -> V_621 ) ;
V_99 = - V_499 ;
if ( log -> V_10 >= V_468 )
goto V_93;
V_652 = F_252 ( V_29 -> V_656 , log -> V_10 ) ;
V_653 = V_652 -> V_653 ;
V_99 = - V_657 ;
if ( ! V_653 )
goto V_93;
V_422 = F_253 ( V_652 ) ;
V_654 = V_653 + V_422 / sizeof( long ) ;
memset ( V_654 , 0 , V_422 ) ;
F_235 ( & V_29 -> V_622 ) ;
for ( V_3 = 0 ; V_3 < V_422 / sizeof( long ) ; V_3 ++ ) {
unsigned long V_26 ;
T_3 V_74 ;
if ( ! V_653 [ V_3 ] )
continue;
V_655 = true ;
V_26 = F_254 ( & V_653 [ V_3 ] , 0 ) ;
V_654 [ V_3 ] = V_26 ;
V_74 = V_3 * V_658 ;
F_255 ( V_29 , V_652 , V_74 , V_26 ) ;
}
if ( V_655 )
F_256 ( V_29 ) ;
F_237 ( & V_29 -> V_622 ) ;
V_99 = - V_81 ;
if ( F_185 ( log -> V_653 , V_654 , V_422 ) )
goto V_93;
V_99 = 0 ;
V_93:
F_166 ( & V_29 -> V_621 ) ;
return V_99 ;
}
long F_257 ( struct V_479 * V_480 ,
unsigned int V_481 , unsigned long V_482 )
{
struct V_29 * V_29 = V_480 -> V_578 ;
void V_321 * V_483 = ( void V_321 * ) V_482 ;
int V_99 = - V_659 ;
union {
struct V_635 V_636 ;
struct V_641 V_660 ;
struct V_661 V_662 ;
} V_581 ;
switch ( V_481 ) {
case V_663 :
V_99 = F_232 ( V_29 , V_482 ) ;
if ( V_99 < 0 )
goto V_93;
break;
case V_664 : {
T_2 V_617 ;
V_99 = - V_81 ;
if ( F_184 ( & V_617 , V_483 , sizeof V_617 ) )
goto V_93;
V_99 = F_233 ( V_29 , V_617 ) ;
if ( V_99 < 0 )
goto V_93;
break;
}
case V_665 :
V_99 = F_234 ( V_29 , V_482 ) ;
if ( V_99 )
goto V_93;
break;
case V_666 :
V_99 = F_238 ( V_29 ) ;
break;
case V_667 : {
struct V_668 * V_669 ;
F_165 ( & V_29 -> V_389 ) ;
V_99 = - V_670 ;
if ( V_29 -> V_5 . V_669 )
goto V_671;
V_99 = - V_499 ;
if ( F_258 ( & V_29 -> V_672 ) )
goto V_671;
V_99 = - V_310 ;
V_669 = F_259 ( V_29 ) ;
if ( V_669 ) {
V_99 = F_260 ( V_29 ) ;
if ( V_99 ) {
F_165 ( & V_29 -> V_621 ) ;
F_261 ( V_29 , V_673 ,
& V_669 -> V_674 ) ;
F_261 ( V_29 , V_673 ,
& V_669 -> V_675 ) ;
F_261 ( V_29 , V_673 ,
& V_669 -> V_676 ) ;
F_166 ( & V_29 -> V_621 ) ;
F_133 ( V_669 ) ;
goto V_671;
}
} else
goto V_671;
F_12 () ;
V_29 -> V_5 . V_669 = V_669 ;
F_12 () ;
V_99 = F_262 ( V_29 ) ;
if ( V_99 ) {
F_165 ( & V_29 -> V_621 ) ;
F_165 ( & V_29 -> V_677 ) ;
F_263 ( V_29 ) ;
F_264 ( V_29 ) ;
F_166 ( & V_29 -> V_677 ) ;
F_166 ( & V_29 -> V_621 ) ;
}
V_671:
F_166 ( & V_29 -> V_389 ) ;
break;
}
case V_678 :
V_581 . V_662 . V_230 = V_679 ;
goto V_680;
case V_681 :
V_99 = - V_81 ;
if ( F_184 ( & V_581 . V_662 , V_483 ,
sizeof( struct V_661 ) ) )
goto V_93;
V_680:
F_165 ( & V_29 -> V_621 ) ;
V_99 = - V_670 ;
if ( V_29 -> V_5 . V_637 )
goto V_682;
V_99 = - V_310 ;
V_29 -> V_5 . V_637 = F_265 ( V_29 , V_581 . V_662 . V_230 ) ;
if ( V_29 -> V_5 . V_637 )
V_99 = 0 ;
V_682:
F_166 ( & V_29 -> V_621 ) ;
break;
case V_683 :
case V_684 : {
struct V_685 V_686 ;
V_99 = - V_81 ;
if ( F_184 ( & V_686 , V_483 , sizeof V_686 ) )
goto V_93;
V_99 = - V_519 ;
if ( F_18 ( V_29 ) ) {
T_12 V_395 ;
V_395 = F_266 ( V_29 , V_687 ,
V_686 . V_518 , V_686 . V_688 ) ;
if ( V_481 == V_683 ) {
V_99 = - V_81 ;
V_686 . V_395 = V_395 ;
if ( F_185 ( V_483 , & V_686 ,
sizeof V_686 ) )
goto V_93;
}
V_99 = 0 ;
}
break;
}
case V_689 : {
struct V_625 * V_626 ;
V_626 = F_130 ( V_483 , sizeof( * V_626 ) ) ;
if ( F_131 ( V_626 ) ) {
V_99 = F_132 ( V_626 ) ;
goto V_93;
}
V_99 = - V_519 ;
if ( ! F_18 ( V_29 ) )
goto V_690;
V_99 = F_239 ( V_29 , V_626 ) ;
if ( V_99 )
goto V_690;
V_99 = - V_81 ;
if ( F_185 ( V_483 , V_626 , sizeof *V_626 ) )
goto V_690;
V_99 = 0 ;
V_690:
F_133 ( V_626 ) ;
if ( V_99 )
goto V_93;
break;
}
case V_691 : {
struct V_625 * V_626 ;
V_626 = F_130 ( V_483 , sizeof( * V_626 ) ) ;
if ( F_131 ( V_626 ) ) {
V_99 = F_132 ( V_626 ) ;
goto V_93;
}
V_99 = - V_519 ;
if ( ! F_18 ( V_29 ) )
goto V_692;
V_99 = F_242 ( V_29 , V_626 ) ;
if ( V_99 )
goto V_692;
V_99 = 0 ;
V_692:
F_133 ( V_626 ) ;
if ( V_99 )
goto V_93;
break;
}
case V_693 : {
V_99 = - V_81 ;
if ( F_184 ( & V_581 . V_636 , V_483 , sizeof( struct V_635 ) ) )
goto V_93;
V_99 = - V_519 ;
if ( ! V_29 -> V_5 . V_637 )
goto V_93;
V_99 = F_245 ( V_29 , & V_581 . V_636 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_185 ( V_483 , & V_581 . V_636 , sizeof( struct V_635 ) ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_694 : {
V_99 = - V_81 ;
if ( F_184 ( & V_581 . V_636 , V_483 , sizeof V_581 . V_636 ) )
goto V_93;
V_99 = - V_519 ;
if ( ! V_29 -> V_5 . V_637 )
goto V_93;
V_99 = F_246 ( V_29 , & V_581 . V_636 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_695 : {
V_99 = - V_519 ;
if ( ! V_29 -> V_5 . V_637 )
goto V_93;
V_99 = F_248 ( V_29 , & V_581 . V_660 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_81 ;
if ( F_185 ( V_483 , & V_581 . V_660 , sizeof( V_581 . V_660 ) ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_696 : {
V_99 = - V_81 ;
if ( F_184 ( & V_581 . V_660 , V_483 , sizeof( V_581 . V_660 ) ) )
goto V_93;
V_99 = - V_519 ;
if ( ! V_29 -> V_5 . V_637 )
goto V_93;
V_99 = F_249 ( V_29 , & V_581 . V_660 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_697 : {
struct V_646 V_647 ;
V_99 = - V_81 ;
if ( F_184 ( & V_647 , V_483 , sizeof( V_647 ) ) )
goto V_93;
V_99 = F_250 ( V_29 , & V_647 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_698 : {
V_99 = - V_81 ;
if ( F_184 ( & V_29 -> V_5 . F_129 , V_483 ,
sizeof( struct V_699 ) ) )
goto V_93;
V_99 = - V_499 ;
if ( V_29 -> V_5 . F_129 . V_230 )
goto V_93;
V_99 = 0 ;
break;
}
case V_700 : {
struct V_701 V_702 ;
T_2 V_703 ;
T_10 V_239 ;
V_99 = - V_81 ;
if ( F_184 ( & V_702 , V_483 , sizeof( V_702 ) ) )
goto V_93;
V_99 = - V_499 ;
if ( V_702 . V_230 )
goto V_93;
V_99 = 0 ;
F_267 () ;
V_703 = F_100 () ;
V_239 = V_702 . clock - V_703 ;
F_268 () ;
V_29 -> V_5 . V_191 = V_239 ;
break;
}
case V_704 : {
struct V_701 V_702 ;
T_2 V_703 ;
F_267 () ;
V_703 = F_100 () ;
V_702 . clock = V_29 -> V_5 . V_191 + V_703 ;
F_268 () ;
V_702 . V_230 = 0 ;
memset ( & V_702 . V_537 , 0 , sizeof( V_702 . V_537 ) ) ;
V_99 = - V_81 ;
if ( F_185 ( V_483 , & V_702 , sizeof( V_702 ) ) )
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
static void F_269 ( void )
{
T_1 V_705 [ 2 ] ;
unsigned V_3 , V_706 ;
for ( V_3 = V_706 = V_707 ; V_3 < F_42 ( V_491 ) ; V_3 ++ ) {
if ( F_270 ( V_491 [ V_3 ] , & V_705 [ 0 ] , & V_705 [ 1 ] ) < 0 )
continue;
if ( V_706 < V_3 )
V_491 [ V_706 ] = V_491 [ V_3 ] ;
V_706 ++ ;
}
V_488 = V_706 ;
}
static int F_271 ( struct V_1 * V_2 , T_4 V_317 , int V_75 ,
const void * V_214 )
{
int V_708 = 0 ;
int V_422 ;
do {
V_422 = F_272 ( V_75 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_516 &&
! F_273 ( & V_2 -> V_5 . V_516 -> V_709 , V_317 , V_422 , V_214 ) )
&& F_274 ( V_2 -> V_29 , V_710 , V_317 , V_422 , V_214 ) )
break;
V_708 += V_422 ;
V_317 += V_422 ;
V_75 -= V_422 ;
V_214 += V_422 ;
} while ( V_75 );
return V_708 ;
}
static int F_275 ( struct V_1 * V_2 , T_4 V_317 , int V_75 , void * V_214 )
{
int V_708 = 0 ;
int V_422 ;
do {
V_422 = F_272 ( V_75 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_516 &&
! F_276 ( & V_2 -> V_5 . V_516 -> V_709 , V_317 , V_422 , V_214 ) )
&& F_277 ( V_2 -> V_29 , V_710 , V_317 , V_422 , V_214 ) )
break;
F_278 ( V_711 , V_422 , V_317 , * ( T_2 * ) V_214 ) ;
V_708 += V_422 ;
V_317 += V_422 ;
V_75 -= V_422 ;
V_214 += V_422 ;
} while ( V_75 );
return V_708 ;
}
static void F_279 ( struct V_1 * V_2 ,
struct V_712 * V_713 , int V_714 )
{
V_56 -> V_715 ( V_2 , V_713 , V_714 ) ;
}
void F_280 ( struct V_1 * V_2 ,
struct V_712 * V_713 , int V_714 )
{
V_56 -> V_716 ( V_2 , V_713 , V_714 ) ;
}
T_4 F_281 ( struct V_1 * V_2 , T_4 V_332 , T_1 V_76 )
{
T_4 V_717 ;
struct V_58 V_49 ;
F_282 ( ! F_31 ( V_2 ) ) ;
V_76 |= V_91 ;
V_717 = V_2 -> V_5 . V_67 . V_718 ( V_2 , V_332 , V_76 , & V_49 ) ;
return V_717 ;
}
T_4 F_283 ( struct V_1 * V_2 , T_13 V_719 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
return V_2 -> V_5 . V_83 -> V_718 ( V_2 , V_719 , V_76 , V_49 ) ;
}
T_4 F_284 ( struct V_1 * V_2 , T_13 V_719 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
V_76 |= V_720 ;
return V_2 -> V_5 . V_83 -> V_718 ( V_2 , V_719 , V_76 , V_49 ) ;
}
T_4 F_285 ( struct V_1 * V_2 , T_13 V_719 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
V_76 |= V_92 ;
return V_2 -> V_5 . V_83 -> V_718 ( V_2 , V_719 , V_76 , V_49 ) ;
}
T_4 F_286 ( struct V_1 * V_2 , T_13 V_719 ,
struct V_58 * V_49 )
{
return V_2 -> V_5 . V_83 -> V_718 ( V_2 , V_719 , 0 , V_49 ) ;
}
static int F_287 ( T_13 V_317 , void * V_148 , unsigned int V_721 ,
struct V_1 * V_2 , T_1 V_76 ,
struct V_58 * V_49 )
{
void * V_31 = V_148 ;
int V_99 = V_722 ;
while ( V_721 ) {
T_4 V_332 = V_2 -> V_5 . V_83 -> V_718 ( V_2 , V_317 , V_76 ,
V_49 ) ;
unsigned V_74 = V_317 & ( V_87 - 1 ) ;
unsigned V_723 = F_272 ( V_721 , ( unsigned ) V_87 - V_74 ) ;
int V_88 ;
if ( V_332 == V_80 )
return V_724 ;
V_88 = F_92 ( V_2 -> V_29 , V_332 , V_31 , V_723 ) ;
if ( V_88 < 0 ) {
V_99 = V_725 ;
goto V_93;
}
V_721 -= V_723 ;
V_31 += V_723 ;
V_317 += V_723 ;
}
V_93:
return V_99 ;
}
static int F_288 ( struct V_726 * V_727 ,
T_13 V_317 , void * V_148 , unsigned int V_721 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_289 ( V_727 ) ;
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
return F_287 ( V_317 , V_148 , V_721 , V_2 ,
V_76 | V_720 ,
V_49 ) ;
}
int F_290 ( struct V_726 * V_727 ,
T_13 V_317 , void * V_148 , unsigned int V_721 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_289 ( V_727 ) ;
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
return F_287 ( V_317 , V_148 , V_721 , V_2 , V_76 ,
V_49 ) ;
}
static int F_291 ( struct V_726 * V_727 ,
T_13 V_317 , void * V_148 , unsigned int V_721 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_289 ( V_727 ) ;
return F_287 ( V_317 , V_148 , V_721 , V_2 , 0 , V_49 ) ;
}
int F_292 ( struct V_726 * V_727 ,
T_13 V_317 , void * V_148 ,
unsigned int V_721 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_289 ( V_727 ) ;
void * V_31 = V_148 ;
int V_99 = V_722 ;
while ( V_721 ) {
T_4 V_332 = V_2 -> V_5 . V_83 -> V_718 ( V_2 , V_317 ,
V_92 ,
V_49 ) ;
unsigned V_74 = V_317 & ( V_87 - 1 ) ;
unsigned V_728 = F_272 ( V_721 , ( unsigned ) V_87 - V_74 ) ;
int V_88 ;
if ( V_332 == V_80 )
return V_724 ;
V_88 = F_93 ( V_2 -> V_29 , V_332 , V_31 , V_728 ) ;
if ( V_88 < 0 ) {
V_99 = V_725 ;
goto V_93;
}
V_721 -= V_728 ;
V_31 += V_728 ;
V_317 += V_728 ;
}
V_93:
return V_99 ;
}
static int F_293 ( struct V_1 * V_2 , unsigned long V_719 ,
T_4 * V_332 , struct V_58 * V_49 ,
bool V_729 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_91 : 0 ;
if ( F_294 ( V_2 , V_719 ) &&
F_295 ( V_2 , V_729 , V_76 ,
V_2 -> V_5 . V_76 ) ) {
* V_332 = V_2 -> V_5 . V_730 << V_86 |
( V_719 & ( V_87 - 1 ) ) ;
F_296 ( V_719 , * V_332 , V_729 , false ) ;
return 1 ;
}
if ( V_729 )
V_76 |= V_92 ;
* V_332 = V_2 -> V_5 . V_83 -> V_718 ( V_2 , V_719 , V_76 , V_49 ) ;
if ( * V_332 == V_80 )
return - 1 ;
if ( ( * V_332 & V_306 ) == V_731 )
return 1 ;
if ( F_297 ( V_2 , * V_332 ) ) {
F_296 ( V_719 , * V_332 , V_729 , true ) ;
return 1 ;
}
return 0 ;
}
int F_298 ( struct V_1 * V_2 , T_4 V_332 ,
const void * V_148 , int V_721 )
{
int V_88 ;
V_88 = F_93 ( V_2 -> V_29 , V_332 , V_148 , V_721 ) ;
if ( V_88 < 0 )
return 0 ;
F_299 ( V_2 , V_332 , V_148 , V_721 ) ;
return 1 ;
}
static int F_300 ( struct V_1 * V_2 , void * V_148 , int V_721 )
{
if ( V_2 -> V_732 ) {
F_278 ( V_711 , V_721 ,
V_2 -> V_733 [ 0 ] . V_332 , * ( T_2 * ) V_148 ) ;
V_2 -> V_732 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_301 ( struct V_1 * V_2 , T_4 V_332 ,
void * V_148 , int V_721 )
{
return ! F_92 ( V_2 -> V_29 , V_332 , V_148 , V_721 ) ;
}
static int F_302 ( struct V_1 * V_2 , T_4 V_332 ,
void * V_148 , int V_721 )
{
return F_298 ( V_2 , V_332 , V_148 , V_721 ) ;
}
static int F_303 ( struct V_1 * V_2 , T_4 V_332 , int V_721 , void * V_148 )
{
F_278 ( V_734 , V_721 , V_332 , * ( T_2 * ) V_148 ) ;
return F_271 ( V_2 , V_332 , V_721 , V_148 ) ;
}
static int F_304 ( struct V_1 * V_2 , T_4 V_332 ,
void * V_148 , int V_721 )
{
F_278 ( V_735 , V_721 , V_332 , 0 ) ;
return V_725 ;
}
static int F_305 ( struct V_1 * V_2 , T_4 V_332 ,
void * V_148 , int V_721 )
{
struct V_736 * V_737 = & V_2 -> V_733 [ 0 ] ;
memcpy ( V_2 -> V_738 -> V_739 . V_31 , V_737 -> V_31 , V_737 -> V_75 ) ;
return V_722 ;
}
static int F_306 ( unsigned long V_317 , void * V_148 ,
unsigned int V_721 ,
struct V_58 * V_49 ,
struct V_1 * V_2 ,
struct V_740 * V_741 )
{
T_4 V_332 ;
int V_708 , V_88 ;
bool V_729 = V_741 -> V_729 ;
struct V_736 * V_737 ;
V_88 = F_293 ( V_2 , V_317 , & V_332 , V_49 , V_729 ) ;
if ( V_88 < 0 )
return V_724 ;
if ( V_88 )
goto V_739;
if ( V_741 -> V_742 ( V_2 , V_332 , V_148 , V_721 ) )
return V_722 ;
V_739:
V_708 = V_741 -> V_743 ( V_2 , V_332 , V_721 , V_148 ) ;
if ( V_708 == V_721 )
return V_722 ;
V_332 += V_708 ;
V_721 -= V_708 ;
V_148 += V_708 ;
while ( V_721 ) {
unsigned V_744 = F_272 ( V_721 , 8U ) ;
V_737 = & V_2 -> V_733 [ V_2 -> V_745 ++ ] ;
V_737 -> V_332 = V_332 ;
V_737 -> V_31 = V_148 ;
V_737 -> V_75 = V_744 ;
V_332 += V_744 ;
V_148 += V_744 ;
V_721 -= V_744 ;
}
return V_722 ;
}
int F_307 ( struct V_726 * V_727 , unsigned long V_317 ,
void * V_148 , unsigned int V_721 ,
struct V_58 * V_49 ,
struct V_740 * V_741 )
{
struct V_1 * V_2 = F_289 ( V_727 ) ;
T_4 V_332 ;
int V_746 ;
if ( V_741 -> V_747 &&
V_741 -> V_747 ( V_2 , V_148 , V_721 ) )
return V_722 ;
V_2 -> V_745 = 0 ;
if ( ( ( V_317 + V_721 - 1 ) ^ V_317 ) & V_306 ) {
int V_744 ;
V_744 = - V_317 & ~ V_306 ;
V_746 = F_306 ( V_317 , V_148 , V_744 , V_49 ,
V_2 , V_741 ) ;
if ( V_746 != V_722 )
return V_746 ;
V_317 += V_744 ;
V_148 += V_744 ;
V_721 -= V_744 ;
}
V_746 = F_306 ( V_317 , V_148 , V_721 , V_49 ,
V_2 , V_741 ) ;
if ( V_746 != V_722 )
return V_746 ;
if ( ! V_2 -> V_745 )
return V_746 ;
V_332 = V_2 -> V_733 [ 0 ] . V_332 ;
V_2 -> V_748 = 1 ;
V_2 -> V_749 = 0 ;
V_2 -> V_738 -> V_739 . V_75 = V_2 -> V_733 [ 0 ] . V_75 ;
V_2 -> V_738 -> V_739 . V_750 = V_2 -> V_751 = V_741 -> V_729 ;
V_2 -> V_738 -> V_752 = V_753 ;
V_2 -> V_738 -> V_739 . V_754 = V_332 ;
return V_741 -> V_755 ( V_2 , V_332 , V_148 , V_721 ) ;
}
static int F_308 ( struct V_726 * V_727 ,
unsigned long V_317 ,
void * V_148 ,
unsigned int V_721 ,
struct V_58 * V_49 )
{
return F_307 ( V_727 , V_317 , V_148 , V_721 ,
V_49 , & V_756 ) ;
}
int F_309 ( struct V_726 * V_727 ,
unsigned long V_317 ,
const void * V_148 ,
unsigned int V_721 ,
struct V_58 * V_49 )
{
return F_307 ( V_727 , V_317 , ( void * ) V_148 , V_721 ,
V_49 , & V_757 ) ;
}
static int F_310 ( struct V_726 * V_727 ,
unsigned long V_317 ,
const void * V_758 ,
const void * V_759 ,
unsigned int V_721 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_289 ( V_727 ) ;
T_4 V_332 ;
struct V_308 * V_308 ;
char * V_760 ;
bool V_761 ;
if ( V_721 > 8 || ( V_721 & ( V_721 - 1 ) ) )
goto V_762;
V_332 = F_285 ( V_2 , V_317 , NULL ) ;
if ( V_332 == V_80 ||
( V_332 & V_306 ) == V_731 )
goto V_762;
if ( ( ( V_332 + V_721 - 1 ) & V_306 ) != ( V_332 & V_306 ) )
goto V_762;
V_308 = F_156 ( V_2 -> V_29 , V_332 >> V_86 ) ;
if ( F_157 ( V_308 ) ) {
F_158 ( V_308 ) ;
goto V_762;
}
V_760 = F_120 ( V_308 ) ;
V_760 += F_311 ( V_332 ) ;
switch ( V_721 ) {
case 1 :
V_761 = F_312 ( T_11 , V_760 , V_758 , V_759 ) ;
break;
case 2 :
V_761 = F_312 ( V_763 , V_760 , V_758 , V_759 ) ;
break;
case 4 :
V_761 = F_312 ( T_1 , V_760 , V_758 , V_759 ) ;
break;
case 8 :
V_761 = F_313 ( V_760 , V_758 , V_759 ) ;
break;
default:
F_314 () ;
}
F_121 ( V_760 ) ;
F_148 ( V_308 ) ;
if ( ! V_761 )
return V_764 ;
F_299 ( V_2 , V_332 , V_759 , V_721 ) ;
return V_722 ;
V_762:
F_315 ( V_765 L_22 ) ;
return F_309 ( V_727 , V_317 , V_759 , V_721 , V_49 ) ;
}
static int F_316 ( struct V_1 * V_2 , void * V_766 )
{
int V_99 ;
if ( V_2 -> V_5 . V_767 . V_768 )
V_99 = F_277 ( V_2 -> V_29 , V_673 , V_2 -> V_5 . V_767 . V_769 ,
V_2 -> V_5 . V_767 . V_423 , V_766 ) ;
else
V_99 = F_274 ( V_2 -> V_29 , V_673 ,
V_2 -> V_5 . V_767 . V_769 , V_2 -> V_5 . V_767 . V_423 ,
V_766 ) ;
return V_99 ;
}
static int F_317 ( struct V_1 * V_2 , int V_423 ,
unsigned short V_769 , void * V_148 ,
unsigned int V_640 , bool V_768 )
{
F_318 ( ! V_768 , V_769 , V_423 , V_640 ) ;
V_2 -> V_5 . V_767 . V_769 = V_769 ;
V_2 -> V_5 . V_767 . V_768 = V_768 ;
V_2 -> V_5 . V_767 . V_640 = V_640 ;
V_2 -> V_5 . V_767 . V_423 = V_423 ;
if ( ! F_316 ( V_2 , V_2 -> V_5 . V_770 ) ) {
V_2 -> V_5 . V_767 . V_640 = 0 ;
return 1 ;
}
V_2 -> V_738 -> V_752 = V_771 ;
V_2 -> V_738 -> V_772 . V_773 = V_768 ? V_774 : V_775 ;
V_2 -> V_738 -> V_772 . V_423 = V_423 ;
V_2 -> V_738 -> V_772 . V_776 = V_777 * V_87 ;
V_2 -> V_738 -> V_772 . V_640 = V_640 ;
V_2 -> V_738 -> V_772 . V_769 = V_769 ;
return 0 ;
}
static int F_319 ( struct V_726 * V_727 ,
int V_423 , unsigned short V_769 , void * V_148 ,
unsigned int V_640 )
{
struct V_1 * V_2 = F_289 ( V_727 ) ;
int V_88 ;
if ( V_2 -> V_5 . V_767 . V_640 )
goto V_778;
V_88 = F_317 ( V_2 , V_423 , V_769 , V_148 , V_640 , true ) ;
if ( V_88 ) {
V_778:
memcpy ( V_148 , V_2 -> V_5 . V_770 , V_423 * V_640 ) ;
V_2 -> V_5 . V_767 . V_640 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_320 ( struct V_726 * V_727 ,
int V_423 , unsigned short V_769 ,
const void * V_148 , unsigned int V_640 )
{
struct V_1 * V_2 = F_289 ( V_727 ) ;
memcpy ( V_2 -> V_5 . V_770 , V_148 , V_423 * V_640 ) ;
return F_317 ( V_2 , V_423 , V_769 , ( void * ) V_148 , V_640 , false ) ;
}
static unsigned long F_321 ( struct V_1 * V_2 , int V_714 )
{
return V_56 -> F_321 ( V_2 , V_714 ) ;
}
static void F_322 ( struct V_726 * V_727 , V_143 V_63 )
{
F_323 ( F_289 ( V_727 ) , V_63 ) ;
}
int F_324 ( struct V_1 * V_2 )
{
if ( ! F_193 ( V_2 ) )
return V_722 ;
if ( V_56 -> V_505 () ) {
int V_504 = F_325 () ;
F_195 ( V_504 , V_2 -> V_5 . V_506 ) ;
F_326 ( V_2 -> V_5 . V_506 ,
F_191 , NULL , 1 ) ;
F_327 () ;
F_328 ( V_2 -> V_5 . V_506 ) ;
} else
F_192 () ;
return V_722 ;
}
static void F_329 ( struct V_726 * V_727 )
{
F_324 ( F_289 ( V_727 ) ) ;
}
int F_330 ( struct V_726 * V_727 , int V_147 , unsigned long * V_779 )
{
return F_79 ( F_289 ( V_727 ) , V_147 , V_779 ) ;
}
int F_331 ( struct V_726 * V_727 , int V_147 , unsigned long V_23 )
{
return F_77 ( F_289 ( V_727 ) , V_147 , V_23 ) ;
}
static T_2 F_332 ( T_2 V_780 , T_1 V_781 )
{
return ( V_780 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_781 ;
}
static unsigned long F_333 ( struct V_726 * V_727 , int V_782 )
{
struct V_1 * V_2 = F_289 ( V_727 ) ;
unsigned long V_23 ;
switch ( V_782 ) {
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
V_23 = F_62 ( V_2 ) ;
break;
case 8 :
V_23 = F_75 ( V_2 ) ;
break;
default:
F_334 ( L_23 , V_209 , V_782 ) ;
return 0 ;
}
return V_23 ;
}
static int F_335 ( struct V_726 * V_727 , int V_782 , V_143 V_148 )
{
struct V_1 * V_2 = F_289 ( V_727 ) ;
int V_163 = 0 ;
switch ( V_782 ) {
case 0 :
V_163 = F_50 ( V_2 , F_332 ( F_51 ( V_2 ) , V_148 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_62 = V_148 ;
break;
case 3 :
V_163 = F_68 ( V_2 , V_148 ) ;
break;
case 4 :
V_163 = F_61 ( V_2 , F_332 ( F_62 ( V_2 ) , V_148 ) ) ;
break;
case 8 :
V_163 = F_73 ( V_2 , V_148 ) ;
break;
default:
F_334 ( L_23 , V_209 , V_782 ) ;
V_163 = - 1 ;
}
return V_163 ;
}
static void F_336 ( struct V_726 * V_727 , V_143 V_148 )
{
F_337 ( F_289 ( V_727 ) , V_148 ) ;
}
static int F_338 ( struct V_726 * V_727 )
{
return V_56 -> V_71 ( F_289 ( V_727 ) ) ;
}
static void F_339 ( struct V_726 * V_727 , struct V_783 * V_784 )
{
V_56 -> V_785 ( F_289 ( V_727 ) , V_784 ) ;
}
static void F_340 ( struct V_726 * V_727 , struct V_783 * V_784 )
{
V_56 -> V_786 ( F_289 ( V_727 ) , V_784 ) ;
}
static void F_341 ( struct V_726 * V_727 , struct V_783 * V_784 )
{
V_56 -> V_787 ( F_289 ( V_727 ) , V_784 ) ;
}
static void F_342 ( struct V_726 * V_727 , struct V_783 * V_784 )
{
V_56 -> V_788 ( F_289 ( V_727 ) , V_784 ) ;
}
static unsigned long F_343 (
struct V_726 * V_727 , int V_714 )
{
return F_321 ( F_289 ( V_727 ) , V_714 ) ;
}
static bool F_344 ( struct V_726 * V_727 , V_763 * V_789 ,
struct V_790 * V_791 , T_1 * V_792 ,
int V_714 )
{
struct V_712 V_713 ;
F_280 ( F_289 ( V_727 ) , & V_713 , V_714 ) ;
* V_789 = V_713 . V_789 ;
if ( V_713 . V_793 )
return false ;
if ( V_713 . V_794 )
V_713 . V_795 >>= 12 ;
F_345 ( V_791 , V_713 . V_795 ) ;
F_346 ( V_791 , ( unsigned long ) V_713 . V_796 ) ;
#ifdef F_52
if ( V_792 )
* V_792 = V_713 . V_796 >> 32 ;
#endif
V_791 -> type = V_713 . type ;
V_791 -> V_514 = V_713 . V_514 ;
V_791 -> V_797 = V_713 . V_797 ;
V_791 -> V_277 = V_713 . V_798 ;
V_791 -> V_799 = V_713 . V_799 ;
V_791 -> V_800 = V_713 . V_800 ;
V_791 -> V_801 = V_713 . V_149 ;
V_791 -> V_794 = V_713 . V_794 ;
return true ;
}
static void F_347 ( struct V_726 * V_727 , V_763 V_789 ,
struct V_790 * V_791 , T_1 V_792 ,
int V_714 )
{
struct V_1 * V_2 = F_289 ( V_727 ) ;
struct V_712 V_713 ;
V_713 . V_789 = V_789 ;
V_713 . V_796 = F_348 ( V_791 ) ;
#ifdef F_52
V_713 . V_796 |= ( ( T_2 ) V_792 ) << 32 ;
#endif
V_713 . V_795 = F_349 ( V_791 ) ;
if ( V_791 -> V_794 )
V_713 . V_795 = ( V_713 . V_795 << 12 ) | 0xfff ;
V_713 . type = V_791 -> type ;
V_713 . V_798 = V_791 -> V_277 ;
V_713 . V_797 = V_791 -> V_797 ;
V_713 . V_149 = V_791 -> V_801 ;
V_713 . V_514 = V_791 -> V_514 ;
V_713 . V_800 = V_791 -> V_800 ;
V_713 . V_794 = V_791 -> V_794 ;
V_713 . V_799 = V_791 -> V_799 ;
V_713 . V_798 = V_791 -> V_277 ;
V_713 . V_793 = ! V_713 . V_798 ;
V_713 . V_802 = 0 ;
F_279 ( V_2 , & V_713 , V_714 ) ;
return;
}
static int F_350 ( struct V_726 * V_727 ,
T_1 V_183 , T_2 * V_397 )
{
return F_168 ( F_289 ( V_727 ) , V_183 , V_397 ) ;
}
static int F_351 ( struct V_726 * V_727 ,
T_1 V_183 , T_2 V_31 )
{
return F_89 ( F_289 ( V_727 ) , V_183 , V_31 ) ;
}
static int F_352 ( struct V_726 * V_727 ,
T_1 V_803 , T_2 * V_397 )
{
return F_83 ( F_289 ( V_727 ) , V_803 , V_397 ) ;
}
static void F_353 ( struct V_726 * V_727 )
{
F_289 ( V_727 ) -> V_5 . V_804 = 1 ;
}
static void F_354 ( struct V_726 * V_727 )
{
F_160 () ;
F_355 ( F_289 ( V_727 ) ) ;
F_356 () ;
}
static void F_357 ( struct V_726 * V_727 )
{
F_161 () ;
}
static int F_358 ( struct V_726 * V_727 ,
struct V_805 * V_806 ,
enum V_807 V_808 )
{
return V_56 -> V_809 ( F_289 ( V_727 ) , V_806 , V_808 ) ;
}
static void F_359 ( struct V_726 * V_727 ,
T_1 * V_810 , T_1 * V_811 , T_1 * V_165 , T_1 * V_174 )
{
V_588 ( F_289 ( V_727 ) , V_810 , V_811 , V_165 , V_174 ) ;
}
static void F_360 ( struct V_1 * V_2 )
{
F_82 ( V_2 , V_167 ) ;
F_82 ( V_2 , V_812 ) ;
F_82 ( V_2 , V_813 ) ;
V_2 -> V_5 . V_97 = ~ 0 ;
}
static void F_361 ( struct V_1 * V_2 , T_1 V_26 )
{
T_1 V_814 = V_56 -> V_541 ( V_2 , V_26 ) ;
if ( ! ( V_814 & V_26 ) )
V_56 -> V_554 ( V_2 , V_26 ) ;
}
static void F_362 ( struct V_1 * V_2 )
{
struct V_726 * V_727 = & V_2 -> V_5 . V_815 ;
if ( V_727 -> V_49 . V_32 == V_33 )
F_30 ( V_2 , & V_727 -> V_49 ) ;
else if ( V_727 -> V_49 . V_816 )
F_29 ( V_2 , V_727 -> V_49 . V_32 ,
V_727 -> V_49 . V_43 ) ;
else
F_24 ( V_2 , V_727 -> V_49 . V_32 ) ;
}
static void F_363 ( struct V_726 * V_727 ,
const unsigned long * V_515 )
{
memset ( & V_727 -> V_817 , 0 ,
( void * ) & V_727 -> V_515 - ( void * ) & V_727 -> V_817 ) ;
memcpy ( V_727 -> V_515 , V_515 , sizeof( V_727 -> V_515 ) ) ;
V_727 -> V_818 . V_642 = 0 ;
V_727 -> V_818 . V_819 = 0 ;
V_727 -> V_820 . V_821 = 0 ;
V_727 -> V_820 . V_819 = 0 ;
V_727 -> V_822 . V_821 = 0 ;
V_727 -> V_822 . V_819 = 0 ;
}
static void F_364 ( struct V_1 * V_2 )
{
struct V_726 * V_727 = & V_2 -> V_5 . V_815 ;
int V_112 , V_113 ;
F_360 ( V_2 ) ;
V_56 -> V_114 ( V_2 , & V_112 , & V_113 ) ;
V_727 -> V_823 = F_365 ( V_2 ) ;
V_727 -> V_824 = F_366 ( V_2 ) ;
V_727 -> V_825 = ( ! F_367 ( V_2 ) ) ? V_826 :
( V_727 -> V_823 & V_827 ) ? V_828 :
V_113 ? V_829 :
V_112 ? V_830 :
V_831 ;
V_727 -> V_832 = F_368 ( V_2 ) ;
F_363 ( V_727 , V_2 -> V_5 . V_515 ) ;
V_2 -> V_5 . V_833 = false ;
}
int F_369 ( struct V_1 * V_2 , int V_518 , int V_834 )
{
struct V_726 * V_727 = & V_2 -> V_5 . V_815 ;
int V_88 ;
F_364 ( V_2 ) ;
V_727 -> V_835 = 2 ;
V_727 -> V_836 = 2 ;
V_727 -> V_837 = V_727 -> V_824 + V_834 ;
V_88 = F_370 ( V_727 , V_518 ) ;
if ( V_88 != V_722 )
return V_838 ;
V_727 -> V_824 = V_727 -> V_837 ;
memcpy ( V_2 -> V_5 . V_515 , V_727 -> V_515 , sizeof V_727 -> V_515 ) ;
F_371 ( V_2 , V_727 -> V_824 ) ;
F_337 ( V_2 , V_727 -> V_823 ) ;
if ( V_518 == V_839 )
V_2 -> V_5 . V_546 = 0 ;
else
V_2 -> V_5 . V_538 . V_50 = false ;
return V_840 ;
}
static int F_372 ( struct V_1 * V_2 )
{
int V_99 = V_840 ;
++ V_2 -> V_60 . V_841 ;
F_373 ( V_2 ) ;
if ( ! F_368 ( V_2 ) ) {
V_2 -> V_738 -> V_752 = V_842 ;
V_2 -> V_738 -> V_843 . V_844 = V_845 ;
V_2 -> V_738 -> V_843 . V_846 = 0 ;
V_99 = V_838 ;
}
F_24 ( V_2 , V_164 ) ;
return V_99 ;
}
static bool F_374 ( struct V_1 * V_2 , T_13 V_719 )
{
T_4 V_332 ;
if ( V_182 )
return false ;
if ( F_375 ( V_2 , V_719 ) )
return true ;
V_332 = F_286 ( V_2 , V_719 , NULL ) ;
if ( V_332 == V_80 )
return true ;
if ( ! F_138 ( F_137 ( V_2 -> V_29 , V_332 >> V_86 ) ) )
return true ;
return false ;
}
static bool F_376 ( struct V_726 * V_727 ,
unsigned long V_62 , int V_847 )
{
struct V_1 * V_2 = F_289 ( V_727 ) ;
unsigned long V_848 , V_849 , V_332 = V_62 ;
V_848 = V_2 -> V_5 . V_848 ;
V_849 = V_2 -> V_5 . V_849 ;
V_2 -> V_5 . V_848 = V_2 -> V_5 . V_849 = 0 ;
if ( ! ( V_847 & V_850 ) )
return false ;
if ( F_377 ( V_727 ) )
return false ;
if ( V_727 -> V_824 == V_848 && V_849 == V_62 )
return false ;
V_2 -> V_5 . V_848 = V_727 -> V_824 ;
V_2 -> V_5 . V_849 = V_62 ;
if ( ! V_2 -> V_5 . V_67 . V_851 )
V_332 = F_285 ( V_2 , V_62 , NULL ) ;
F_378 ( V_2 -> V_29 , V_332 >> V_86 ) ;
return true ;
}
int F_379 ( struct V_1 * V_2 ,
unsigned long V_62 ,
int V_847 ,
void * V_852 ,
int V_853 )
{
int V_99 ;
struct V_726 * V_727 = & V_2 -> V_5 . V_815 ;
bool V_421 = true ;
F_380 ( V_2 ) ;
if ( ! ( V_847 & V_854 ) ) {
F_364 ( V_2 ) ;
V_727 -> V_855 = 0 ;
V_727 -> V_856 = false ;
V_727 -> V_857 = false ;
V_727 -> V_858
= V_847 & V_859 ;
V_99 = F_381 ( V_727 , V_852 , V_853 ) ;
F_382 ( V_2 ) ;
++ V_2 -> V_60 . V_860 ;
if ( V_99 != V_861 ) {
if ( V_847 & V_859 )
return V_838 ;
if ( F_374 ( V_2 , V_62 ) )
return V_840 ;
if ( V_847 & V_862 )
return V_838 ;
return F_372 ( V_2 ) ;
}
}
if ( V_847 & V_862 ) {
F_371 ( V_2 , V_727 -> V_837 ) ;
return V_840 ;
}
if ( F_376 ( V_727 , V_62 , V_847 ) )
return V_840 ;
if ( V_2 -> V_5 . V_833 ) {
V_2 -> V_5 . V_833 = false ;
memcpy ( V_727 -> V_515 , V_2 -> V_5 . V_515 , sizeof V_727 -> V_515 ) ;
}
V_863:
V_99 = F_383 ( V_727 ) ;
if ( V_99 == V_864 )
return V_840 ;
if ( V_99 == V_865 ) {
if ( F_374 ( V_2 , V_62 ) )
return V_840 ;
return F_372 ( V_2 ) ;
}
if ( V_727 -> V_856 ) {
F_362 ( V_2 ) ;
V_99 = V_840 ;
} else if ( V_2 -> V_5 . V_767 . V_640 ) {
if ( ! V_2 -> V_5 . V_767 . V_768 )
V_2 -> V_5 . V_767 . V_640 = 0 ;
else
V_421 = false ;
V_99 = V_866 ;
} else if ( V_2 -> V_748 ) {
if ( ! V_2 -> V_751 )
V_421 = false ;
V_99 = V_866 ;
} else if ( V_99 == V_867 )
goto V_863;
else
V_99 = V_840 ;
if ( V_421 ) {
F_361 ( V_2 , V_727 -> V_855 ) ;
F_337 ( V_2 , V_727 -> V_823 ) ;
F_23 ( V_48 , V_2 ) ;
memcpy ( V_2 -> V_5 . V_515 , V_727 -> V_515 , sizeof V_727 -> V_515 ) ;
V_2 -> V_5 . V_868 = false ;
F_371 ( V_2 , V_727 -> V_824 ) ;
} else
V_2 -> V_5 . V_868 = true ;
return V_99 ;
}
int F_384 ( struct V_1 * V_2 , int V_423 , unsigned short V_769 )
{
unsigned long V_148 = F_82 ( V_2 , V_167 ) ;
int V_88 = F_320 ( & V_2 -> V_5 . V_815 ,
V_423 , V_769 , & V_148 , 1 ) ;
V_2 -> V_5 . V_767 . V_640 = 0 ;
return V_88 ;
}
static void F_385 ( void * V_806 )
{
F_386 ( V_252 , 0 ) ;
}
static void F_387 ( void * V_31 )
{
struct V_869 * V_870 = V_31 ;
unsigned long V_212 = 0 ;
if ( V_31 )
V_212 = V_870 -> V_759 ;
else if ( ! F_188 ( V_871 ) )
V_212 = F_388 ( F_389 () ) ;
if ( ! V_212 )
V_212 = V_221 ;
F_386 ( V_252 , V_212 ) ;
}
static int F_390 ( struct V_872 * V_873 , unsigned long V_148 ,
void * V_31 )
{
struct V_869 * V_870 = V_31 ;
struct V_29 * V_29 ;
struct V_1 * V_2 ;
int V_3 , V_874 = 0 ;
if ( V_148 == V_875 && V_870 -> V_758 > V_870 -> V_759 )
return 0 ;
if ( V_148 == V_876 && V_870 -> V_758 < V_870 -> V_759 )
return 0 ;
F_196 ( V_870 -> V_504 , F_387 , V_870 , 1 ) ;
F_391 ( & V_877 ) ;
F_392 (kvm, &vm_list, vm_list) {
F_173 (i, vcpu, kvm) {
if ( V_2 -> V_504 != V_870 -> V_504 )
continue;
F_23 ( V_253 , V_2 ) ;
if ( V_2 -> V_504 != F_393 () )
V_874 = 1 ;
}
}
F_394 ( & V_877 ) ;
if ( V_870 -> V_758 < V_870 -> V_759 && V_874 ) {
F_196 ( V_870 -> V_504 , F_387 , V_870 , 1 ) ;
}
return 0 ;
}
static int F_395 ( struct V_872 * V_878 ,
unsigned long V_879 , void * V_880 )
{
unsigned int V_504 = ( unsigned long ) V_880 ;
switch ( V_879 ) {
case V_881 :
case V_882 :
F_196 ( V_504 , F_387 , NULL , 1 ) ;
break;
case V_883 :
F_196 ( V_504 , F_385 , NULL , 1 ) ;
break;
}
return V_884 ;
}
static void F_396 ( void )
{
int V_504 ;
V_885 = V_221 ;
F_397 ( & V_886 ) ;
if ( ! F_188 ( V_871 ) ) {
#ifdef F_398
struct V_887 V_888 ;
memset ( & V_888 , 0 , sizeof( V_888 ) ) ;
V_504 = F_325 () ;
F_399 ( & V_888 , V_504 ) ;
if ( V_888 . V_889 . V_890 )
V_885 = V_888 . V_889 . V_890 ;
F_327 () ;
#endif
F_400 ( & V_891 ,
V_892 ) ;
}
F_99 ( L_24 , V_885 ) ;
F_401 (cpu)
F_196 ( V_504 , F_387 , NULL , 1 ) ;
}
int F_402 ( void )
{
return F_403 ( V_893 ) != NULL ;
}
static int F_404 ( void )
{
int V_894 = 3 ;
if ( F_403 ( V_893 ) )
V_894 = V_56 -> V_71 ( F_403 ( V_893 ) ) ;
return V_894 != 0 ;
}
static unsigned long F_405 ( void )
{
unsigned long V_895 = 0 ;
if ( F_403 ( V_893 ) )
V_895 = F_366 ( F_403 ( V_893 ) ) ;
return V_895 ;
}
void F_406 ( struct V_1 * V_2 )
{
F_386 ( V_893 , V_2 ) ;
}
void F_407 ( struct V_1 * V_2 )
{
F_386 ( V_893 , NULL ) ;
}
static void F_408 ( void )
{
T_2 V_26 ;
int V_896 = V_897 . V_898 ;
V_26 = ( ( 1ull << ( 62 - V_896 + 1 ) ) - 1 ) << V_896 ;
V_26 |= 1ull ;
#ifdef F_52
if ( V_896 == 52 )
V_26 &= ~ 1ull ;
#endif
F_409 ( V_26 ) ;
}
int F_410 ( void * V_899 )
{
int V_99 ;
struct V_56 * V_741 = (struct V_56 * ) V_899 ;
if ( V_56 ) {
F_9 ( V_25 L_25 ) ;
V_99 = - V_670 ;
goto V_93;
}
if ( ! V_741 -> V_900 () ) {
F_9 ( V_25 L_26 ) ;
V_99 = - V_901 ;
goto V_93;
}
if ( V_741 -> V_902 () ) {
F_9 ( V_25 L_27 ) ;
V_99 = - V_901 ;
goto V_93;
}
V_99 = F_411 () ;
if ( V_99 )
goto V_93;
F_408 () ;
F_269 () ;
V_56 = V_741 ;
F_412 ( V_903 , V_904 ,
V_905 , V_906 , 0 ) ;
F_396 () ;
F_413 ( & V_907 ) ;
if ( V_474 )
V_125 = F_414 ( V_121 ) ;
return 0 ;
V_93:
return V_99 ;
}
void F_415 ( void )
{
F_416 ( & V_907 ) ;
if ( ! F_188 ( V_871 ) )
F_417 ( & V_891 ,
V_892 ) ;
F_418 ( & V_886 ) ;
V_56 = NULL ;
F_419 () ;
}
int F_420 ( struct V_1 * V_2 )
{
++ V_2 -> V_60 . V_908 ;
if ( F_18 ( V_2 -> V_29 ) ) {
V_2 -> V_5 . V_909 = V_910 ;
return 1 ;
} else {
V_2 -> V_738 -> V_752 = V_911 ;
return 0 ;
}
}
int F_421 ( struct V_1 * V_2 )
{
T_2 V_912 , V_913 , V_914 , V_88 ;
T_14 V_915 , V_916 , V_917 , V_163 = V_918 , V_919 = 0 ;
bool V_920 , V_921 ;
int V_112 , V_113 ;
if ( V_56 -> V_71 ( V_2 ) != 0 || ! F_367 ( V_2 ) ) {
F_24 ( V_2 , V_164 ) ;
return 0 ;
}
V_56 -> V_114 ( V_2 , & V_112 , & V_113 ) ;
V_921 = F_46 ( V_2 ) && V_113 == 1 ;
if ( ! V_921 ) {
V_912 = ( ( T_2 ) F_82 ( V_2 , V_168 ) << 32 ) |
( F_82 ( V_2 , V_167 ) & 0xffffffff ) ;
V_913 = ( ( T_2 ) F_82 ( V_2 , V_922 ) << 32 ) |
( F_82 ( V_2 , V_166 ) & 0xffffffff ) ;
V_914 = ( ( T_2 ) F_82 ( V_2 , V_923 ) << 32 ) |
( F_82 ( V_2 , V_924 ) & 0xffffffff ) ;
}
#ifdef F_52
else {
V_912 = F_82 ( V_2 , V_166 ) ;
V_913 = F_82 ( V_2 , V_168 ) ;
V_914 = F_82 ( V_2 , V_925 ) ;
}
#endif
V_915 = V_912 & 0xffff ;
V_920 = ( V_912 >> 16 ) & 0x1 ;
V_917 = ( V_912 >> 32 ) & 0xfff ;
V_916 = ( V_912 >> 48 ) & 0xfff ;
F_422 ( V_915 , V_920 , V_917 , V_916 , V_913 , V_914 ) ;
switch ( V_915 ) {
case V_926 :
F_423 ( V_2 ) ;
break;
default:
V_163 = V_927 ;
break;
}
V_88 = V_163 | ( ( ( T_2 ) V_919 & 0xfff ) << 32 ) ;
if ( V_921 ) {
F_84 ( V_2 , V_167 , V_88 ) ;
} else {
F_84 ( V_2 , V_168 , V_88 >> 32 ) ;
F_84 ( V_2 , V_167 , V_88 & 0xffffffff ) ;
}
return 1 ;
}
int F_424 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_928 , V_929 , V_930 , V_931 , V_88 ;
int V_99 = 1 ;
if ( F_134 ( V_2 -> V_29 ) )
return F_421 ( V_2 ) ;
V_16 = F_82 ( V_2 , V_167 ) ;
V_928 = F_82 ( V_2 , V_922 ) ;
V_929 = F_82 ( V_2 , V_166 ) ;
V_930 = F_82 ( V_2 , V_168 ) ;
V_931 = F_82 ( V_2 , V_924 ) ;
F_425 ( V_16 , V_928 , V_929 , V_930 , V_931 ) ;
if ( ! F_46 ( V_2 ) ) {
V_16 &= 0xFFFFFFFF ;
V_928 &= 0xFFFFFFFF ;
V_929 &= 0xFFFFFFFF ;
V_930 &= 0xFFFFFFFF ;
V_931 &= 0xFFFFFFFF ;
}
if ( V_56 -> V_71 ( V_2 ) != 0 ) {
V_88 = - V_932 ;
goto V_93;
}
switch ( V_16 ) {
case V_933 :
V_88 = 0 ;
break;
default:
V_88 = - V_934 ;
break;
}
V_93:
F_84 ( V_2 , V_167 , V_88 ) ;
++ V_2 -> V_60 . V_935 ;
return V_99 ;
}
int F_426 ( struct V_726 * V_727 )
{
struct V_1 * V_2 = F_289 ( V_727 ) ;
char V_936 [ 3 ] ;
unsigned long V_937 = F_366 ( V_2 ) ;
F_427 ( V_2 -> V_29 ) ;
V_56 -> V_320 ( V_2 , V_936 ) ;
return F_309 ( V_727 , V_937 , V_936 , 3 , NULL ) ;
}
static int F_428 ( struct V_1 * V_2 )
{
return ( ! F_18 ( V_2 -> V_29 ) && ! F_429 ( V_2 ) &&
V_2 -> V_738 -> V_938 &&
F_430 ( V_2 ) ) ;
}
static void F_431 ( struct V_1 * V_2 )
{
struct V_939 * V_939 = V_2 -> V_738 ;
V_939 -> V_940 = ( F_365 ( V_2 ) & V_941 ) != 0 ;
V_939 -> V_145 = F_75 ( V_2 ) ;
V_939 -> V_30 = F_17 ( V_2 ) ;
if ( F_18 ( V_2 -> V_29 ) )
V_939 -> V_942 = 1 ;
else
V_939 -> V_942 =
F_430 ( V_2 ) &&
! F_429 ( V_2 ) &&
! F_432 ( V_2 ) ;
}
static int F_433 ( struct V_1 * V_2 )
{
struct V_943 * V_516 = V_2 -> V_5 . V_516 ;
struct V_308 * V_308 ;
if ( ! V_516 || ! V_516 -> V_597 )
return 0 ;
V_308 = F_156 ( V_2 -> V_29 , V_516 -> V_597 >> V_86 ) ;
if ( F_157 ( V_308 ) )
return - V_81 ;
V_2 -> V_5 . V_516 -> V_944 = V_308 ;
return 0 ;
}
static void F_434 ( struct V_1 * V_2 )
{
struct V_943 * V_516 = V_2 -> V_5 . V_516 ;
int V_283 ;
if ( ! V_516 || ! V_516 -> V_597 )
return;
V_283 = F_181 ( & V_2 -> V_29 -> V_418 ) ;
F_148 ( V_516 -> V_944 ) ;
F_122 ( V_2 -> V_29 , V_516 -> V_597 >> V_86 ) ;
F_182 ( & V_2 -> V_29 -> V_418 , V_283 ) ;
}
static void F_207 ( struct V_1 * V_2 )
{
int V_945 , V_946 ;
if ( ! V_56 -> F_207 )
return;
if ( ! V_2 -> V_5 . V_516 )
return;
if ( ! V_2 -> V_5 . V_516 -> V_597 )
V_945 = F_435 ( V_2 ) ;
else
V_945 = - 1 ;
if ( V_945 != - 1 )
V_945 >>= 4 ;
V_946 = F_76 ( V_2 ) ;
V_56 -> F_207 ( V_2 , V_946 , V_945 ) ;
}
static void F_436 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_49 . V_50 ) {
F_437 ( V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ) ;
V_56 -> V_947 ( V_2 , V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ,
V_2 -> V_5 . V_49 . V_44 ) ;
return;
}
if ( V_2 -> V_5 . V_545 ) {
V_56 -> V_948 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_538 . V_50 ) {
V_56 -> V_949 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_546 ) {
if ( V_56 -> V_950 ( V_2 ) ) {
-- V_2 -> V_5 . V_546 ;
V_2 -> V_5 . V_545 = true ;
V_56 -> V_948 ( V_2 ) ;
}
} else if ( F_429 ( V_2 ) ) {
if ( V_56 -> V_951 ( V_2 ) ) {
F_209 ( V_2 , F_438 ( V_2 ) ,
false ) ;
V_56 -> V_949 ( V_2 ) ;
}
}
}
static void F_439 ( struct V_1 * V_2 )
{
if ( F_54 ( V_2 , V_135 ) &&
! V_2 -> V_126 ) {
F_440 ( V_121 , V_2 -> V_5 . V_120 ) ;
V_2 -> V_126 = 1 ;
}
}
static void F_441 ( struct V_1 * V_2 )
{
if ( V_2 -> V_126 ) {
if ( V_2 -> V_5 . V_120 != V_125 )
F_440 ( V_121 , V_125 ) ;
V_2 -> V_126 = 0 ;
}
}
static void F_215 ( struct V_1 * V_2 )
{
unsigned V_795 = 2 ;
if ( V_56 -> V_548 ( V_2 ) || V_2 -> V_5 . V_545 )
V_795 = 1 ;
V_2 -> V_5 . V_546 += F_442 ( & V_2 -> V_5 . V_68 , 0 ) ;
V_2 -> V_5 . V_546 = F_272 ( V_2 -> V_5 . V_546 , V_795 ) ;
F_23 ( V_48 , V_2 ) ;
}
static int F_443 ( struct V_1 * V_2 )
{
int V_99 ;
bool V_952 = ! F_18 ( V_2 -> V_29 ) &&
V_2 -> V_738 -> V_938 ;
bool V_953 = 0 ;
if ( V_2 -> V_509 ) {
if ( F_444 ( V_954 , V_2 ) )
F_445 ( V_2 ) ;
if ( F_444 ( V_955 , V_2 ) )
F_446 ( V_2 ) ;
if ( F_444 ( V_253 , V_2 ) ) {
V_99 = F_116 ( V_2 ) ;
if ( F_71 ( V_99 ) )
goto V_93;
}
if ( F_444 ( V_956 , V_2 ) )
F_69 ( V_2 ) ;
if ( F_444 ( V_957 , V_2 ) )
V_56 -> V_958 ( V_2 ) ;
if ( F_444 ( V_959 , V_2 ) ) {
V_2 -> V_738 -> V_752 = V_960 ;
V_99 = 0 ;
goto V_93;
}
if ( F_444 ( V_54 , V_2 ) ) {
V_2 -> V_738 -> V_752 = V_961 ;
V_99 = 0 ;
goto V_93;
}
if ( F_444 ( V_962 , V_2 ) ) {
V_2 -> V_963 = 0 ;
V_56 -> V_964 ( V_2 ) ;
}
if ( F_444 ( V_965 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_966 = true ;
V_99 = 1 ;
goto V_93;
}
if ( F_444 ( V_372 , V_2 ) )
F_150 ( V_2 ) ;
if ( F_444 ( V_69 , V_2 ) )
F_215 ( V_2 ) ;
V_953 =
F_444 ( V_967 , V_2 ) ;
if ( F_444 ( V_968 , V_2 ) )
F_447 ( V_2 ) ;
if ( F_444 ( V_969 , V_2 ) )
F_448 ( V_2 ) ;
}
if ( F_444 ( V_48 , V_2 ) || V_952 ) {
F_436 ( V_2 ) ;
if ( V_2 -> V_5 . V_546 )
V_56 -> V_970 ( V_2 ) ;
else if ( F_429 ( V_2 ) || V_952 )
V_56 -> V_971 ( V_2 ) ;
if ( F_449 ( V_2 ) ) {
F_207 ( V_2 ) ;
F_450 ( V_2 ) ;
}
}
V_99 = F_451 ( V_2 ) ;
if ( F_71 ( V_99 ) ) {
goto V_972;
}
F_160 () ;
V_56 -> V_973 ( V_2 ) ;
if ( V_2 -> V_963 )
F_355 ( V_2 ) ;
F_439 ( V_2 ) ;
V_2 -> V_825 = V_974 ;
F_452 () ;
F_267 () ;
if ( V_2 -> V_825 == V_975 || V_2 -> V_509
|| F_453 () || F_454 ( V_339 ) ) {
V_2 -> V_825 = V_976 ;
F_12 () ;
F_268 () ;
F_161 () ;
V_99 = 1 ;
goto V_972;
}
F_182 ( & V_2 -> V_29 -> V_418 , V_2 -> V_977 ) ;
if ( V_953 )
F_455 ( V_2 -> V_504 ) ;
F_456 () ;
if ( F_71 ( V_2 -> V_5 . V_161 ) ) {
F_457 ( 0 , 7 ) ;
F_457 ( V_2 -> V_5 . V_152 [ 0 ] , 0 ) ;
F_457 ( V_2 -> V_5 . V_152 [ 1 ] , 1 ) ;
F_457 ( V_2 -> V_5 . V_152 [ 2 ] , 2 ) ;
F_457 ( V_2 -> V_5 . V_152 [ 3 ] , 3 ) ;
}
F_458 ( V_2 -> V_978 ) ;
V_56 -> V_738 ( V_2 ) ;
if ( F_459 () )
F_460 () ;
V_2 -> V_5 . V_245 = V_56 -> V_251 ( V_2 ) ;
V_2 -> V_825 = V_976 ;
F_12 () ;
F_268 () ;
++ V_2 -> V_60 . V_979 ;
F_461 () ;
F_462 () ;
F_161 () ;
V_2 -> V_977 = F_181 ( & V_2 -> V_29 -> V_418 ) ;
if ( F_71 ( V_980 == V_981 ) ) {
unsigned long V_937 = F_366 ( V_2 ) ;
F_463 ( V_981 , ( void * ) V_937 ) ;
}
if ( F_71 ( V_2 -> V_5 . V_982 ) )
F_23 ( V_253 , V_2 ) ;
if ( V_2 -> V_5 . V_983 )
F_464 ( V_2 ) ;
V_99 = V_56 -> V_984 ( V_2 ) ;
return V_99 ;
V_972:
V_56 -> V_972 ( V_2 ) ;
if ( F_71 ( V_2 -> V_5 . V_983 ) )
F_464 ( V_2 ) ;
V_93:
return V_99 ;
}
static int F_465 ( struct V_1 * V_2 )
{
int V_99 ;
struct V_29 * V_29 = V_2 -> V_29 ;
if ( F_71 ( V_2 -> V_5 . V_909 == V_985 ) ) {
F_99 ( L_28 ,
V_2 -> V_978 , V_2 -> V_5 . V_549 ) ;
F_466 ( V_2 ) ;
V_99 = F_467 ( V_2 ) ;
if ( V_99 )
return V_99 ;
V_2 -> V_5 . V_909 = V_986 ;
}
V_2 -> V_977 = F_181 ( & V_29 -> V_418 ) ;
V_99 = F_433 ( V_2 ) ;
if ( V_99 ) {
F_182 ( & V_29 -> V_418 , V_2 -> V_977 ) ;
return V_99 ;
}
V_99 = 1 ;
while ( V_99 > 0 ) {
if ( V_2 -> V_5 . V_909 == V_986 &&
! V_2 -> V_5 . V_6 . V_966 )
V_99 = F_443 ( V_2 ) ;
else {
F_182 ( & V_29 -> V_418 , V_2 -> V_977 ) ;
F_468 ( V_2 ) ;
V_2 -> V_977 = F_181 ( & V_29 -> V_418 ) ;
if ( F_444 ( V_987 , V_2 ) )
{
switch( V_2 -> V_5 . V_909 ) {
case V_910 :
V_2 -> V_5 . V_909 =
V_986 ;
case V_986 :
V_2 -> V_5 . V_6 . V_966 = false ;
break;
case V_985 :
default:
V_99 = - V_988 ;
break;
}
}
}
if ( V_99 <= 0 )
break;
F_469 ( V_989 , & V_2 -> V_509 ) ;
if ( F_470 ( V_2 ) )
F_471 ( V_2 ) ;
if ( F_428 ( V_2 ) ) {
V_99 = - V_988 ;
V_2 -> V_738 -> V_752 = V_990 ;
++ V_2 -> V_60 . V_991 ;
}
F_472 ( V_2 ) ;
if ( F_454 ( V_339 ) ) {
V_99 = - V_988 ;
V_2 -> V_738 -> V_752 = V_990 ;
++ V_2 -> V_60 . V_992 ;
}
if ( F_453 () ) {
F_182 ( & V_29 -> V_418 , V_2 -> V_977 ) ;
F_473 ( V_2 ) ;
V_2 -> V_977 = F_181 ( & V_29 -> V_418 ) ;
}
}
F_182 ( & V_29 -> V_418 , V_2 -> V_977 ) ;
F_434 ( V_2 ) ;
return V_99 ;
}
static int F_474 ( struct V_1 * V_2 )
{
struct V_939 * V_738 = V_2 -> V_738 ;
struct V_736 * V_737 ;
int V_99 ;
if ( ! ( V_2 -> V_5 . V_767 . V_640 || V_2 -> V_748 ) )
return 1 ;
if ( V_2 -> V_748 ) {
V_737 = & V_2 -> V_733 [ V_2 -> V_749 ++ ] ;
if ( ! V_2 -> V_751 )
memcpy ( V_737 -> V_31 , V_738 -> V_739 . V_31 , V_737 -> V_75 ) ;
if ( V_2 -> V_749 == V_2 -> V_745 ) {
V_2 -> V_748 = 0 ;
if ( V_2 -> V_751 )
return 1 ;
V_2 -> V_732 = 1 ;
goto V_993;
}
++ V_737 ;
V_738 -> V_752 = V_753 ;
V_738 -> V_739 . V_754 = V_737 -> V_332 ;
if ( V_2 -> V_751 )
memcpy ( V_738 -> V_739 . V_31 , V_737 -> V_31 , V_737 -> V_75 ) ;
V_738 -> V_739 . V_75 = V_737 -> V_75 ;
V_738 -> V_739 . V_750 = V_2 -> V_751 ;
return 0 ;
}
V_993:
V_2 -> V_977 = F_181 ( & V_2 -> V_29 -> V_418 ) ;
V_99 = F_475 ( V_2 , V_854 ) ;
F_182 ( & V_2 -> V_29 -> V_418 , V_2 -> V_977 ) ;
if ( V_99 != V_840 )
return 0 ;
return 1 ;
}
int F_476 ( struct V_1 * V_2 , struct V_939 * V_939 )
{
int V_99 ;
T_15 V_994 ;
if ( ! F_477 ( V_339 ) && F_478 ( V_339 ) )
return - V_310 ;
if ( V_2 -> V_995 )
F_479 ( V_996 , & V_2 -> V_997 , & V_994 ) ;
if ( F_71 ( V_2 -> V_5 . V_909 == V_998 ) ) {
F_468 ( V_2 ) ;
F_469 ( V_987 , & V_2 -> V_509 ) ;
V_99 = - V_999 ;
goto V_93;
}
if ( ! F_18 ( V_2 -> V_29 ) ) {
if ( F_73 ( V_2 , V_939 -> V_145 ) != 0 ) {
V_99 = - V_499 ;
goto V_93;
}
}
V_99 = F_474 ( V_2 ) ;
if ( V_99 <= 0 )
goto V_93;
V_99 = F_465 ( V_2 ) ;
V_93:
F_431 ( V_2 ) ;
if ( V_2 -> V_995 )
F_479 ( V_996 , & V_994 , NULL ) ;
return V_99 ;
}
int F_480 ( struct V_1 * V_2 , struct V_1000 * V_515 )
{
if ( V_2 -> V_5 . V_868 ) {
struct V_726 * V_727 = & V_2 -> V_5 . V_815 ;
memcpy ( V_2 -> V_5 . V_515 , V_727 -> V_515 , sizeof V_727 -> V_515 ) ;
V_2 -> V_5 . V_868 = false ;
}
V_515 -> V_1001 = F_82 ( V_2 , V_167 ) ;
V_515 -> V_1002 = F_82 ( V_2 , V_922 ) ;
V_515 -> V_1003 = F_82 ( V_2 , V_166 ) ;
V_515 -> V_1004 = F_82 ( V_2 , V_168 ) ;
V_515 -> V_1005 = F_82 ( V_2 , V_924 ) ;
V_515 -> V_1006 = F_82 ( V_2 , V_923 ) ;
V_515 -> V_1007 = F_82 ( V_2 , V_812 ) ;
V_515 -> V_1008 = F_82 ( V_2 , V_1009 ) ;
#ifdef F_52
V_515 -> V_1010 = F_82 ( V_2 , V_925 ) ;
V_515 -> V_1011 = F_82 ( V_2 , V_1012 ) ;
V_515 -> V_1013 = F_82 ( V_2 , V_1014 ) ;
V_515 -> V_1015 = F_82 ( V_2 , V_1016 ) ;
V_515 -> V_1017 = F_82 ( V_2 , V_1018 ) ;
V_515 -> V_1019 = F_82 ( V_2 , V_1020 ) ;
V_515 -> V_1021 = F_82 ( V_2 , V_1022 ) ;
V_515 -> V_1023 = F_82 ( V_2 , V_1024 ) ;
#endif
V_515 -> V_937 = F_366 ( V_2 ) ;
V_515 -> V_1025 = F_365 ( V_2 ) ;
return 0 ;
}
int F_481 ( struct V_1 * V_2 , struct V_1000 * V_515 )
{
V_2 -> V_5 . V_833 = true ;
V_2 -> V_5 . V_868 = false ;
F_84 ( V_2 , V_167 , V_515 -> V_1001 ) ;
F_84 ( V_2 , V_922 , V_515 -> V_1002 ) ;
F_84 ( V_2 , V_166 , V_515 -> V_1003 ) ;
F_84 ( V_2 , V_168 , V_515 -> V_1004 ) ;
F_84 ( V_2 , V_924 , V_515 -> V_1005 ) ;
F_84 ( V_2 , V_923 , V_515 -> V_1006 ) ;
F_84 ( V_2 , V_812 , V_515 -> V_1007 ) ;
F_84 ( V_2 , V_1009 , V_515 -> V_1008 ) ;
#ifdef F_52
F_84 ( V_2 , V_925 , V_515 -> V_1010 ) ;
F_84 ( V_2 , V_1012 , V_515 -> V_1011 ) ;
F_84 ( V_2 , V_1014 , V_515 -> V_1013 ) ;
F_84 ( V_2 , V_1016 , V_515 -> V_1015 ) ;
F_84 ( V_2 , V_1018 , V_515 -> V_1017 ) ;
F_84 ( V_2 , V_1020 , V_515 -> V_1019 ) ;
F_84 ( V_2 , V_1022 , V_515 -> V_1021 ) ;
F_84 ( V_2 , V_1024 , V_515 -> V_1023 ) ;
#endif
F_371 ( V_2 , V_515 -> V_937 ) ;
F_337 ( V_2 , V_515 -> V_1025 ) ;
V_2 -> V_5 . V_49 . V_50 = false ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
void F_482 ( struct V_1 * V_2 , int * V_149 , int * V_800 )
{
struct V_712 V_1026 ;
F_280 ( V_2 , & V_1026 , V_1027 ) ;
* V_149 = V_1026 . V_149 ;
* V_800 = V_1026 . V_800 ;
}
int F_483 ( struct V_1 * V_2 ,
struct V_1028 * V_1029 )
{
struct V_783 V_784 ;
F_280 ( V_2 , & V_1029 -> V_1026 , V_1027 ) ;
F_280 ( V_2 , & V_1029 -> V_1030 , V_1031 ) ;
F_280 ( V_2 , & V_1029 -> V_1032 , V_1033 ) ;
F_280 ( V_2 , & V_1029 -> V_1034 , V_1035 ) ;
F_280 ( V_2 , & V_1029 -> V_1036 , V_1037 ) ;
F_280 ( V_2 , & V_1029 -> V_1038 , V_1039 ) ;
F_280 ( V_2 , & V_1029 -> V_1040 , V_1041 ) ;
F_280 ( V_2 , & V_1029 -> V_1042 , V_1043 ) ;
V_56 -> V_786 ( V_2 , & V_784 ) ;
V_1029 -> V_1044 . V_795 = V_784 . V_423 ;
V_1029 -> V_1044 . V_796 = V_784 . V_63 ;
V_56 -> V_785 ( V_2 , & V_784 ) ;
V_1029 -> V_1045 . V_795 = V_784 . V_423 ;
V_1029 -> V_1045 . V_796 = V_784 . V_63 ;
V_1029 -> V_100 = F_51 ( V_2 ) ;
V_1029 -> V_62 = V_2 -> V_5 . V_62 ;
V_1029 -> V_84 = F_49 ( V_2 ) ;
V_1029 -> V_127 = F_62 ( V_2 ) ;
V_1029 -> V_145 = F_75 ( V_2 ) ;
V_1029 -> V_110 = V_2 -> V_5 . V_110 ;
V_1029 -> V_30 = F_17 ( V_2 ) ;
memset ( V_1029 -> V_1046 , 0 , sizeof V_1029 -> V_1046 ) ;
if ( V_2 -> V_5 . V_538 . V_50 && ! V_2 -> V_5 . V_538 . V_539 )
F_198 ( V_2 -> V_5 . V_538 . V_16 ,
( unsigned long * ) V_1029 -> V_1046 ) ;
return 0 ;
}
int F_484 ( struct V_1 * V_2 ,
struct V_1047 * V_909 )
{
V_909 -> V_909 = V_2 -> V_5 . V_909 ;
return 0 ;
}
int F_485 ( struct V_1 * V_2 ,
struct V_1047 * V_909 )
{
V_2 -> V_5 . V_909 = V_909 -> V_909 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
int F_486 ( struct V_1 * V_2 , V_763 V_1048 , int V_1049 ,
int V_1050 , bool V_52 , T_1 V_43 )
{
struct V_726 * V_727 = & V_2 -> V_5 . V_815 ;
int V_88 ;
F_364 ( V_2 ) ;
V_88 = F_487 ( V_727 , V_1048 , V_1049 , V_1050 ,
V_52 , V_43 ) ;
if ( V_88 )
return V_838 ;
memcpy ( V_2 -> V_5 . V_515 , V_727 -> V_515 , sizeof V_727 -> V_515 ) ;
F_371 ( V_2 , V_727 -> V_824 ) ;
F_337 ( V_2 , V_727 -> V_823 ) ;
F_23 ( V_48 , V_2 ) ;
return V_840 ;
}
int F_488 ( struct V_1 * V_2 ,
struct V_1028 * V_1029 )
{
int V_1051 = 0 ;
int V_1052 , V_1053 , V_283 ;
struct V_783 V_784 ;
V_784 . V_423 = V_1029 -> V_1044 . V_795 ;
V_784 . V_63 = V_1029 -> V_1044 . V_796 ;
V_56 -> V_788 ( V_2 , & V_784 ) ;
V_784 . V_423 = V_1029 -> V_1045 . V_795 ;
V_784 . V_63 = V_1029 -> V_1045 . V_796 ;
V_56 -> V_787 ( V_2 , & V_784 ) ;
V_2 -> V_5 . V_62 = V_1029 -> V_62 ;
V_1051 |= F_49 ( V_2 ) != V_1029 -> V_84 ;
V_2 -> V_5 . V_84 = V_1029 -> V_84 ;
F_44 ( V_142 , ( V_143 * ) & V_2 -> V_5 . V_96 ) ;
F_73 ( V_2 , V_1029 -> V_145 ) ;
V_1051 |= V_2 -> V_5 . V_110 != V_1029 -> V_110 ;
V_56 -> F_85 ( V_2 , V_1029 -> V_110 ) ;
F_19 ( V_2 , V_1029 -> V_30 ) ;
V_1051 |= F_51 ( V_2 ) != V_1029 -> V_100 ;
V_56 -> V_116 ( V_2 , V_1029 -> V_100 ) ;
V_2 -> V_5 . V_100 = V_1029 -> V_100 ;
V_1051 |= F_62 ( V_2 ) != V_1029 -> V_127 ;
V_56 -> V_138 ( V_2 , V_1029 -> V_127 ) ;
if ( V_1029 -> V_127 & V_135 )
F_67 ( V_2 ) ;
V_283 = F_181 ( & V_2 -> V_29 -> V_418 ) ;
if ( ! F_46 ( V_2 ) && F_47 ( V_2 ) ) {
F_41 ( V_2 , V_2 -> V_5 . V_83 , F_49 ( V_2 ) ) ;
V_1051 = 1 ;
}
F_182 ( & V_2 -> V_29 -> V_418 , V_283 ) ;
if ( V_1051 )
F_56 ( V_2 ) ;
V_1053 = ( sizeof V_1029 -> V_1046 ) << 3 ;
V_1052 = F_489 (
( const unsigned long * ) V_1029 -> V_1046 , V_1053 ) ;
if ( V_1052 < V_1053 ) {
F_209 ( V_2 , V_1052 , false ) ;
F_99 ( L_29 , V_1052 ) ;
}
F_279 ( V_2 , & V_1029 -> V_1026 , V_1027 ) ;
F_279 ( V_2 , & V_1029 -> V_1030 , V_1031 ) ;
F_279 ( V_2 , & V_1029 -> V_1032 , V_1033 ) ;
F_279 ( V_2 , & V_1029 -> V_1034 , V_1035 ) ;
F_279 ( V_2 , & V_1029 -> V_1036 , V_1037 ) ;
F_279 ( V_2 , & V_1029 -> V_1038 , V_1039 ) ;
F_279 ( V_2 , & V_1029 -> V_1040 , V_1041 ) ;
F_279 ( V_2 , & V_1029 -> V_1042 , V_1043 ) ;
F_207 ( V_2 ) ;
if ( F_490 ( V_2 ) && F_366 ( V_2 ) == 0xfff0 &&
V_1029 -> V_1026 . V_789 == 0xf000 && V_1029 -> V_1026 . V_796 == 0xffff0000 &&
! F_367 ( V_2 ) )
V_2 -> V_5 . V_909 = V_986 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
int F_491 ( struct V_1 * V_2 ,
struct V_1054 * V_1055 )
{
unsigned long V_1025 ;
int V_3 , V_99 ;
if ( V_1055 -> V_647 & ( V_1056 | V_1057 ) ) {
V_99 = - V_1058 ;
if ( V_2 -> V_5 . V_49 . V_50 )
goto V_93;
if ( V_1055 -> V_647 & V_1056 )
F_24 ( V_2 , V_1059 ) ;
else
F_24 ( V_2 , V_1060 ) ;
}
V_1025 = F_365 ( V_2 ) ;
V_2 -> V_150 = V_1055 -> V_647 ;
if ( ! ( V_2 -> V_150 & V_1061 ) )
V_2 -> V_150 = 0 ;
if ( V_2 -> V_150 & V_151 ) {
for ( V_3 = 0 ; V_3 < V_1062 ; ++ V_3 )
V_2 -> V_5 . V_152 [ V_3 ] = V_1055 -> V_5 . V_1063 [ V_3 ] ;
V_2 -> V_5 . V_161 =
( V_1055 -> V_5 . V_1063 [ 7 ] & V_162 ) ;
} else {
for ( V_3 = 0 ; V_3 < V_1062 ; V_3 ++ )
V_2 -> V_5 . V_152 [ V_3 ] = V_2 -> V_5 . V_149 [ V_3 ] ;
V_2 -> V_5 . V_161 = ( V_2 -> V_5 . V_157 & V_162 ) ;
}
if ( V_2 -> V_150 & V_1064 )
V_2 -> V_5 . V_1065 = F_366 ( V_2 ) +
F_321 ( V_2 , V_1027 ) ;
F_337 ( V_2 , V_1025 ) ;
V_56 -> V_1066 ( V_2 , V_1055 ) ;
V_99 = 0 ;
V_93:
return V_99 ;
}
int F_492 ( struct V_1 * V_2 ,
struct V_1067 * V_1040 )
{
unsigned long V_1068 = V_1040 -> V_1069 ;
T_4 V_332 ;
int V_283 ;
V_283 = F_181 ( & V_2 -> V_29 -> V_418 ) ;
V_332 = F_286 ( V_2 , V_1068 , NULL ) ;
F_182 ( & V_2 -> V_29 -> V_418 , V_283 ) ;
V_1040 -> V_1070 = V_332 ;
V_1040 -> V_1071 = V_332 != V_80 ;
V_1040 -> V_1072 = 1 ;
V_1040 -> V_1073 = 0 ;
return 0 ;
}
int F_493 ( struct V_1 * V_2 , struct V_1074 * V_1075 )
{
struct V_566 * V_565 =
& V_2 -> V_5 . V_561 . V_562 -> V_565 ;
memcpy ( V_1075 -> V_1076 , V_565 -> V_1077 , 128 ) ;
V_1075 -> V_1078 = V_565 -> V_1079 ;
V_1075 -> V_1080 = V_565 -> V_1081 ;
V_1075 -> V_1082 = V_565 -> V_1083 ;
V_1075 -> V_1084 = V_565 -> V_1085 ;
V_1075 -> V_1086 = V_565 -> V_937 ;
V_1075 -> V_1087 = V_565 -> V_1088 ;
memcpy ( V_1075 -> V_1089 , V_565 -> V_1090 , sizeof V_565 -> V_1090 ) ;
return 0 ;
}
int F_494 ( struct V_1 * V_2 , struct V_1074 * V_1075 )
{
struct V_566 * V_565 =
& V_2 -> V_5 . V_561 . V_562 -> V_565 ;
memcpy ( V_565 -> V_1077 , V_1075 -> V_1076 , 128 ) ;
V_565 -> V_1079 = V_1075 -> V_1078 ;
V_565 -> V_1081 = V_1075 -> V_1080 ;
V_565 -> V_1083 = V_1075 -> V_1082 ;
V_565 -> V_1085 = V_1075 -> V_1084 ;
V_565 -> V_937 = V_1075 -> V_1086 ;
V_565 -> V_1088 = V_1075 -> V_1087 ;
memcpy ( V_565 -> V_1090 , V_1075 -> V_1089 , sizeof V_565 -> V_1090 ) ;
return 0 ;
}
int F_495 ( struct V_1 * V_2 )
{
int V_55 ;
V_55 = F_496 ( & V_2 -> V_5 . V_561 ) ;
if ( V_55 )
return V_55 ;
F_497 ( & V_2 -> V_5 . V_561 ) ;
V_2 -> V_5 . V_120 = V_122 ;
V_2 -> V_5 . V_100 |= V_107 ;
return 0 ;
}
static void F_498 ( struct V_1 * V_2 )
{
F_499 ( & V_2 -> V_5 . V_561 ) ;
}
void F_355 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1091 )
return;
F_441 ( V_2 ) ;
V_2 -> V_1091 = 1 ;
F_500 ( V_339 ) ;
F_501 ( & V_2 -> V_5 . V_561 ) ;
F_502 ( 1 ) ;
}
void F_203 ( struct V_1 * V_2 )
{
F_441 ( V_2 ) ;
if ( ! V_2 -> V_1091 )
return;
V_2 -> V_1091 = 0 ;
F_503 ( & V_2 -> V_5 . V_561 ) ;
++ V_2 -> V_60 . V_1092 ;
F_23 ( V_962 , V_2 ) ;
F_502 ( 0 ) ;
}
void F_504 ( struct V_1 * V_2 )
{
F_147 ( V_2 ) ;
F_505 ( V_2 -> V_5 . V_506 ) ;
F_498 ( V_2 ) ;
V_56 -> V_1093 ( V_2 ) ;
}
struct V_1 * F_506 ( struct V_29 * V_29 ,
unsigned int V_1094 )
{
if ( F_114 () && F_258 ( & V_29 -> V_672 ) != 0 )
F_315 ( V_765
L_30
L_31 ) ;
return V_56 -> V_1095 ( V_29 , V_1094 ) ;
}
int F_507 ( struct V_1 * V_2 )
{
int V_99 ;
V_2 -> V_5 . V_278 . V_1096 = 1 ;
V_507 ( V_2 ) ;
V_99 = F_467 ( V_2 ) ;
if ( V_99 == 0 )
V_99 = F_508 ( V_2 ) ;
V_512 ( V_2 ) ;
return V_99 ;
}
void F_509 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_6 . V_333 = 0 ;
V_507 ( V_2 ) ;
F_445 ( V_2 ) ;
V_512 ( V_2 ) ;
F_498 ( V_2 ) ;
V_56 -> V_1093 ( V_2 ) ;
}
int F_467 ( struct V_1 * V_2 )
{
F_510 ( & V_2 -> V_5 . V_68 , 0 ) ;
V_2 -> V_5 . V_546 = 0 ;
V_2 -> V_5 . V_545 = false ;
V_2 -> V_5 . V_161 = 0 ;
memset ( V_2 -> V_5 . V_149 , 0 , sizeof( V_2 -> V_5 . V_149 ) ) ;
V_2 -> V_5 . V_154 = V_156 ;
V_2 -> V_5 . V_157 = V_159 ;
F_23 ( V_48 , V_2 ) ;
V_2 -> V_5 . V_6 . V_333 = 0 ;
V_2 -> V_5 . V_337 . V_333 = 0 ;
F_147 ( V_2 ) ;
F_55 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_966 = false ;
F_511 ( V_2 ) ;
return V_56 -> V_1097 ( V_2 ) ;
}
int F_512 ( void * V_500 )
{
struct V_29 * V_29 ;
struct V_1 * V_2 ;
int V_3 ;
int V_88 ;
T_2 V_1098 ;
T_2 V_1099 = 0 ;
bool V_1100 , V_1101 = false ;
F_13 () ;
V_88 = V_56 -> V_1102 ( V_500 ) ;
if ( V_88 != 0 )
return V_88 ;
V_1098 = F_199 () ;
V_1100 = ! F_114 () ;
F_392 (kvm, &vm_list, vm_list) {
F_173 (i, vcpu, kvm) {
if ( ! V_1100 && V_2 -> V_504 == F_393 () )
F_198 ( V_253 , & V_2 -> V_509 ) ;
if ( V_1100 && V_2 -> V_5 . V_511 > V_1098 ) {
V_1101 = true ;
if ( V_2 -> V_5 . V_511 > V_1099 )
V_1099 = V_2 -> V_5 . V_511 ;
}
}
}
if ( V_1101 ) {
T_2 V_1103 = V_1099 - V_1098 ;
F_392 (kvm, &vm_list, vm_list) {
F_173 (i, vcpu, kvm) {
V_2 -> V_5 . V_508 += V_1103 ;
V_2 -> V_5 . V_511 = V_1098 ;
}
V_29 -> V_5 . V_234 = 0 ;
V_29 -> V_5 . V_235 = 0 ;
}
}
return 0 ;
}
void F_513 ( void * V_500 )
{
V_56 -> V_1104 ( V_500 ) ;
F_16 ( V_500 ) ;
}
int F_514 ( void )
{
return V_56 -> V_1105 () ;
}
void F_515 ( void )
{
V_56 -> V_1106 () ;
}
void F_516 ( void * V_1107 )
{
V_56 -> V_1108 ( V_1107 ) ;
}
bool F_517 ( struct V_1 * V_2 )
{
return F_18 ( V_2 -> V_29 ) == ( V_2 -> V_5 . V_516 != NULL ) ;
}
int F_518 ( struct V_1 * V_2 )
{
struct V_308 * V_308 ;
struct V_29 * V_29 ;
int V_99 ;
F_282 ( V_2 -> V_29 == NULL ) ;
V_29 = V_2 -> V_29 ;
V_2 -> V_5 . V_815 . V_741 = & V_1109 ;
if ( ! F_18 ( V_29 ) || F_490 ( V_2 ) )
V_2 -> V_5 . V_909 = V_986 ;
else
V_2 -> V_5 . V_909 = V_998 ;
V_308 = F_519 ( V_583 | V_1110 ) ;
if ( ! V_308 ) {
V_99 = - V_310 ;
goto V_1111;
}
V_2 -> V_5 . V_770 = F_520 ( V_308 ) ;
F_110 ( V_2 , V_885 ) ;
V_99 = F_521 ( V_2 ) ;
if ( V_99 < 0 )
goto V_1112;
if ( F_18 ( V_29 ) ) {
V_99 = F_522 ( V_2 ) ;
if ( V_99 < 0 )
goto V_1113;
}
V_2 -> V_5 . V_297 = F_226 ( V_374 * sizeof( T_2 ) * 4 ,
V_583 ) ;
if ( ! V_2 -> V_5 . V_297 ) {
V_99 = - V_310 ;
goto V_1114;
}
V_2 -> V_5 . V_289 = V_374 ;
if ( ! F_523 ( & V_2 -> V_5 . V_506 , V_583 ) )
goto V_1115;
F_1 ( V_2 ) ;
F_524 ( V_2 ) ;
return 0 ;
V_1115:
F_133 ( V_2 -> V_5 . V_297 ) ;
V_1114:
F_525 ( V_2 ) ;
V_1113:
F_526 ( V_2 ) ;
V_1112:
F_527 ( ( unsigned long ) V_2 -> V_5 . V_770 ) ;
V_1111:
return V_99 ;
}
void F_528 ( struct V_1 * V_2 )
{
int V_283 ;
F_529 ( V_2 ) ;
F_133 ( V_2 -> V_5 . V_297 ) ;
F_525 ( V_2 ) ;
V_283 = F_181 ( & V_2 -> V_29 -> V_418 ) ;
F_526 ( V_2 ) ;
F_182 ( & V_2 -> V_29 -> V_418 , V_283 ) ;
F_527 ( ( unsigned long ) V_2 -> V_5 . V_770 ) ;
}
int F_530 ( struct V_29 * V_29 , unsigned long type )
{
if ( type )
return - V_499 ;
F_531 ( & V_29 -> V_5 . V_1116 ) ;
F_531 ( & V_29 -> V_5 . V_1117 ) ;
F_198 ( V_687 , & V_29 -> V_5 . V_1118 ) ;
F_532 ( & V_29 -> V_5 . V_232 ) ;
return 0 ;
}
static void F_533 ( struct V_1 * V_2 )
{
V_507 ( V_2 ) ;
F_445 ( V_2 ) ;
V_512 ( V_2 ) ;
}
static void F_534 ( struct V_29 * V_29 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_173 (i, vcpu, kvm) {
F_55 ( V_2 ) ;
F_533 ( V_2 ) ;
}
F_173 (i, vcpu, kvm)
F_504 ( V_2 ) ;
F_165 ( & V_29 -> V_389 ) ;
for ( V_3 = 0 ; V_3 < F_258 ( & V_29 -> V_672 ) ; V_3 ++ )
V_29 -> V_1119 [ V_3 ] = NULL ;
F_510 ( & V_29 -> V_672 , 0 ) ;
F_166 ( & V_29 -> V_389 ) ;
}
void F_535 ( struct V_29 * V_29 )
{
F_536 ( V_29 ) ;
F_537 ( V_29 ) ;
}
void F_538 ( struct V_29 * V_29 )
{
F_539 ( V_29 ) ;
F_133 ( V_29 -> V_5 . V_669 ) ;
F_133 ( V_29 -> V_5 . V_1120 ) ;
F_534 ( V_29 ) ;
if ( V_29 -> V_5 . V_1121 )
F_540 ( V_29 -> V_5 . V_1121 ) ;
if ( V_29 -> V_5 . V_1122 )
F_540 ( V_29 -> V_5 . V_1122 ) ;
}
void F_541 ( struct V_651 * free ,
struct V_651 * V_1123 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1124 - 1 ; ++ V_3 ) {
if ( ! V_1123 || free -> V_5 . V_1125 [ V_3 ] != V_1123 -> V_5 . V_1125 [ V_3 ] ) {
F_542 ( free -> V_5 . V_1125 [ V_3 ] ) ;
free -> V_5 . V_1125 [ V_3 ] = NULL ;
}
}
}
int F_543 ( struct V_651 * V_10 , unsigned long V_1126 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1124 - 1 ; ++ V_3 ) {
unsigned long V_1127 ;
int V_1128 ;
int V_688 = V_3 + 2 ;
V_1128 = F_544 ( V_10 -> V_1129 + V_1126 - 1 ,
V_10 -> V_1129 , V_688 ) + 1 ;
V_10 -> V_5 . V_1125 [ V_3 ] =
F_545 ( V_1128 * sizeof( * V_10 -> V_5 . V_1125 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1125 [ V_3 ] )
goto V_311;
if ( V_10 -> V_1129 & ( F_546 ( V_688 ) - 1 ) )
V_10 -> V_5 . V_1125 [ V_3 ] [ 0 ] . V_1130 = 1 ;
if ( ( V_10 -> V_1129 + V_1126 ) & ( F_546 ( V_688 ) - 1 ) )
V_10 -> V_5 . V_1125 [ V_3 ] [ V_1128 - 1 ] . V_1130 = 1 ;
V_1127 = V_10 -> V_1131 >> V_86 ;
if ( ( V_10 -> V_1129 ^ V_1127 ) & ( F_546 ( V_688 ) - 1 ) ||
! F_547 () ) {
unsigned long V_706 ;
for ( V_706 = 0 ; V_706 < V_1128 ; ++ V_706 )
V_10 -> V_5 . V_1125 [ V_3 ] [ V_706 ] . V_1130 = 1 ;
}
}
return 0 ;
V_311:
for ( V_3 = 0 ; V_3 < V_1124 - 1 ; ++ V_3 ) {
F_542 ( V_10 -> V_5 . V_1125 [ V_3 ] ) ;
V_10 -> V_5 . V_1125 [ V_3 ] = NULL ;
}
return - V_310 ;
}
int F_548 ( struct V_29 * V_29 ,
struct V_651 * V_652 ,
struct V_651 V_758 ,
struct V_1132 * V_1133 ,
int V_1134 )
{
int V_1126 = V_652 -> V_1126 ;
int V_1135 = V_1136 | V_1137 ;
if ( V_652 -> V_1094 >= V_468 )
V_1135 = V_1138 | V_1137 ;
if ( ! V_1134 ) {
if ( V_1126 && ! V_758 . V_1139 ) {
unsigned long V_1131 ;
V_1131 = F_549 ( NULL , 0 ,
V_1126 * V_87 ,
V_1140 | V_1141 ,
V_1135 ,
0 ) ;
if ( F_131 ( ( void * ) V_1131 ) )
return F_132 ( ( void * ) V_1131 ) ;
V_652 -> V_1131 = V_1131 ;
}
}
return 0 ;
}
void F_550 ( struct V_29 * V_29 ,
struct V_1132 * V_1133 ,
struct V_651 V_758 ,
int V_1134 )
{
int V_1142 = 0 , V_1126 = V_1133 -> V_1143 >> V_86 ;
if ( ! V_1134 && ! V_758 . V_1134 && V_758 . V_1139 && ! V_1126 ) {
int V_88 ;
V_88 = F_551 ( V_758 . V_1131 ,
V_758 . V_1126 * V_87 ) ;
if ( V_88 < 0 )
F_9 ( V_765
L_32
L_33 ) ;
}
if ( ! V_29 -> V_5 . V_623 )
V_1142 = F_552 ( V_29 ) ;
F_235 ( & V_29 -> V_622 ) ;
if ( V_1142 )
F_236 ( V_29 , V_1142 ) ;
F_553 ( V_29 , V_1133 -> V_10 ) ;
F_237 ( & V_29 -> V_622 ) ;
}
void F_554 ( struct V_29 * V_29 )
{
F_427 ( V_29 ) ;
F_555 ( V_29 ) ;
}
int F_556 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_909 == V_986 &&
! V_2 -> V_5 . V_6 . V_966 )
|| ! F_557 ( & V_2 -> V_1144 . V_993 )
|| V_2 -> V_5 . V_909 == V_985
|| F_258 ( & V_2 -> V_5 . V_68 ) ||
( F_430 ( V_2 ) &&
F_429 ( V_2 ) ) ;
}
int F_558 ( struct V_1 * V_2 )
{
return F_559 ( V_2 ) == V_974 ;
}
int F_430 ( struct V_1 * V_2 )
{
return V_56 -> V_951 ( V_2 ) ;
}
bool F_560 ( struct V_1 * V_2 , unsigned long V_1145 )
{
unsigned long V_1146 = F_366 ( V_2 ) +
F_321 ( V_2 , V_1027 ) ;
return V_1146 == V_1145 ;
}
unsigned long F_365 ( struct V_1 * V_2 )
{
unsigned long V_1025 ;
V_1025 = V_56 -> V_1147 ( V_2 ) ;
if ( V_2 -> V_150 & V_1064 )
V_1025 &= ~ V_1148 ;
return V_1025 ;
}
void F_337 ( struct V_1 * V_2 , unsigned long V_1025 )
{
if ( V_2 -> V_150 & V_1064 &&
F_560 ( V_2 , V_2 -> V_5 . V_1065 ) )
V_1025 |= V_1148 ;
V_56 -> V_1149 ( V_2 , V_1025 ) ;
F_23 ( V_48 , V_2 ) ;
}
void F_561 ( struct V_1 * V_2 , struct V_1150 * V_1151 )
{
int V_99 ;
if ( ( V_2 -> V_5 . V_67 . V_851 != V_1151 -> V_5 . V_851 ) ||
F_157 ( V_1151 -> V_308 ) )
return;
V_99 = F_451 ( V_2 ) ;
if ( F_71 ( V_99 ) )
return;
if ( ! V_2 -> V_5 . V_67 . V_851 &&
V_1151 -> V_5 . V_84 != V_2 -> V_5 . V_67 . V_1152 ( V_2 ) )
return;
V_2 -> V_5 . V_67 . V_1153 ( V_2 , V_1151 -> V_719 , 0 , true ) ;
}
static inline T_1 F_562 ( T_3 V_82 )
{
return F_563 ( V_82 & 0xffffffff , F_564 ( V_4 ) ) ;
}
static inline T_1 F_565 ( T_1 V_1154 )
{
return ( V_1154 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_566 ( struct V_1 * V_2 , T_3 V_82 )
{
T_1 V_1154 = F_562 ( V_82 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1154 ] != ~ 0 )
V_1154 = F_565 ( V_1154 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1154 ] = V_82 ;
}
static T_1 F_567 ( struct V_1 * V_2 , T_3 V_82 )
{
int V_3 ;
T_1 V_1154 = F_562 ( V_82 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1154 ] != V_82 &&
V_2 -> V_5 . V_6 . V_7 [ V_1154 ] != ~ 0 ) ; V_3 ++ )
V_1154 = F_565 ( V_1154 ) ;
return V_1154 ;
}
bool F_568 ( struct V_1 * V_2 , T_3 V_82 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_567 ( V_2 , V_82 ) ] == V_82 ;
}
static void F_569 ( struct V_1 * V_2 , T_3 V_82 )
{
T_1 V_3 , V_706 , V_1155 ;
V_3 = V_706 = F_567 ( V_2 , V_82 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_706 = F_565 ( V_706 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_706 ] == ~ 0 )
return;
V_1155 = F_562 ( V_2 -> V_5 . V_6 . V_7 [ V_706 ] ) ;
} while ( ( V_3 <= V_706 ) ? ( V_3 < V_1155 && V_1155 <= V_706 ) : ( V_3 < V_1155 || V_1155 <= V_706 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_706 ] ;
V_3 = V_706 ;
}
}
static int F_570 ( struct V_1 * V_2 , T_1 V_148 )
{
return F_152 ( V_2 -> V_29 , & V_2 -> V_5 . V_6 . V_31 , & V_148 ,
sizeof( V_148 ) ) ;
}
void F_571 ( struct V_1 * V_2 ,
struct V_1150 * V_1151 )
{
struct V_58 V_59 ;
F_572 ( V_1151 -> V_5 . V_1156 , V_1151 -> V_719 ) ;
F_566 ( V_2 , V_1151 -> V_5 . V_82 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_333 & V_334 ) ||
( V_2 -> V_5 . V_6 . V_335 &&
V_56 -> V_71 ( V_2 ) == 0 ) )
F_23 ( V_965 , V_2 ) ;
else if ( ! F_570 ( V_2 , V_1157 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_816 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_1151 -> V_5 . V_1156 ;
F_28 ( V_2 , & V_59 ) ;
}
}
void F_573 ( struct V_1 * V_2 ,
struct V_1150 * V_1151 )
{
struct V_58 V_59 ;
F_574 ( V_1151 -> V_5 . V_1156 , V_1151 -> V_719 ) ;
if ( F_157 ( V_1151 -> V_308 ) )
V_1151 -> V_5 . V_1156 = ~ 0 ;
else
F_569 ( V_2 , V_1151 -> V_5 . V_82 ) ;
if ( ( V_2 -> V_5 . V_6 . V_333 & V_334 ) &&
! F_570 ( V_2 , V_1158 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_816 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_1151 -> V_5 . V_1156 ;
F_28 ( V_2 , & V_59 ) ;
}
V_2 -> V_5 . V_6 . V_966 = false ;
V_2 -> V_5 . V_909 = V_986 ;
}
bool F_575 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_333 & V_334 ) )
return true ;
else
return ! F_432 ( V_2 ) &&
V_56 -> V_951 ( V_2 ) ;
}
