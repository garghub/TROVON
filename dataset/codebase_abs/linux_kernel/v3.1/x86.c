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
static bool F_62 ( struct V_1 * V_2 )
{
struct V_125 * V_126 ;
V_126 = F_60 ( V_2 , 7 , 0 ) ;
return V_126 && ( V_126 -> V_129 & F_61 ( V_130 ) ) ;
}
static bool F_63 ( struct V_1 * V_2 )
{
struct V_125 * V_126 ;
V_126 = F_60 ( V_2 , 7 , 0 ) ;
return V_126 && ( V_126 -> V_129 & F_61 ( V_131 ) ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_125 * V_126 ;
V_126 = F_60 ( V_2 , 1 , 0 ) ;
if ( ! V_126 )
return;
if ( V_132 && V_126 -> V_133 == 0x1 ) {
V_126 -> V_127 &= ~ ( F_61 ( V_134 ) ) ;
if ( F_65 ( V_2 , V_135 ) )
V_126 -> V_127 |= F_61 ( V_134 ) ;
}
}
int F_66 ( struct V_1 * V_2 , unsigned long V_136 )
{
unsigned long V_137 = F_67 ( V_2 ) ;
unsigned long V_138 = V_139 | V_140 |
V_141 | V_142 ;
if ( V_136 & V_143 )
return 1 ;
if ( ! F_59 ( V_2 ) && ( V_136 & V_135 ) )
return 1 ;
if ( ! F_62 ( V_2 ) && ( V_136 & V_142 ) )
return 1 ;
if ( ! F_63 ( V_2 ) && ( V_136 & V_144 ) )
return 1 ;
if ( F_45 ( V_2 ) ) {
if ( ! ( V_136 & V_141 ) )
return 1 ;
} else if ( F_52 ( V_2 ) && ( V_136 & V_141 )
&& ( ( V_136 ^ V_137 ) & V_138 )
&& ! F_40 ( V_2 , V_2 -> V_5 . V_82 ,
F_48 ( V_2 ) ) )
return 1 ;
if ( V_56 -> V_145 ( V_2 , V_136 ) )
return 1 ;
if ( ( V_136 ^ V_137 ) & V_138 )
F_54 ( V_2 ) ;
if ( ( V_136 ^ V_137 ) & V_135 )
F_64 ( V_2 ) ;
return 0 ;
}
int F_68 ( struct V_1 * V_2 , unsigned long V_83 )
{
if ( V_83 == F_48 ( V_2 ) && ! F_44 ( V_2 ) ) {
F_69 ( V_2 ) ;
F_70 ( V_2 ) ;
return 0 ;
}
if ( F_45 ( V_2 ) ) {
if ( V_83 & V_146 )
return 1 ;
} else {
if ( F_46 ( V_2 ) ) {
if ( V_83 & V_147 )
return 1 ;
if ( F_52 ( V_2 ) &&
! F_40 ( V_2 , V_2 -> V_5 . V_82 , V_83 ) )
return 1 ;
}
}
if ( F_71 ( ! F_72 ( V_2 -> V_29 , V_83 >> V_85 ) ) )
return 1 ;
V_2 -> V_5 . V_83 = V_83 ;
F_43 ( V_148 , ( V_149 * ) & V_2 -> V_5 . V_95 ) ;
V_2 -> V_5 . V_67 . V_150 ( V_2 ) ;
return 0 ;
}
int F_73 ( struct V_1 * V_2 , unsigned long V_151 )
{
if ( V_151 & V_152 )
return 1 ;
if ( F_18 ( V_2 -> V_29 ) )
F_74 ( V_2 , V_151 ) ;
else
V_2 -> V_5 . V_151 = V_151 ;
return 0 ;
}
unsigned long F_75 ( struct V_1 * V_2 )
{
if ( F_18 ( V_2 -> V_29 ) )
return F_76 ( V_2 ) ;
else
return V_2 -> V_5 . V_151 ;
}
static int F_77 ( struct V_1 * V_2 , int V_153 , unsigned long V_154 )
{
switch ( V_153 ) {
case 0 ... 3 :
V_2 -> V_5 . V_155 [ V_153 ] = V_154 ;
if ( ! ( V_2 -> V_156 & V_157 ) )
V_2 -> V_5 . V_158 [ V_153 ] = V_154 ;
break;
case 4 :
if ( F_65 ( V_2 , V_159 ) )
return 1 ;
case 6 :
if ( V_154 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_160 = ( V_154 & V_161 ) | V_162 ;
break;
case 5 :
if ( F_65 ( V_2 , V_159 ) )
return 1 ;
default:
if ( V_154 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_163 = ( V_154 & V_164 ) | V_165 ;
if ( ! ( V_2 -> V_156 & V_157 ) ) {
V_56 -> V_166 ( V_2 , V_2 -> V_5 . V_163 ) ;
V_2 -> V_5 . V_167 = ( V_154 & V_168 ) ;
}
break;
}
return 0 ;
}
int F_78 ( struct V_1 * V_2 , int V_153 , unsigned long V_154 )
{
int V_169 ;
V_169 = F_77 ( V_2 , V_153 , V_154 ) ;
if ( V_169 > 0 )
F_24 ( V_2 , V_170 ) ;
else if ( V_169 < 0 )
F_27 ( V_2 , 0 ) ;
return V_169 ;
}
static int F_79 ( struct V_1 * V_2 , int V_153 , unsigned long * V_154 )
{
switch ( V_153 ) {
case 0 ... 3 :
* V_154 = V_2 -> V_5 . V_155 [ V_153 ] ;
break;
case 4 :
if ( F_65 ( V_2 , V_159 ) )
return 1 ;
case 6 :
* V_154 = V_2 -> V_5 . V_160 ;
break;
case 5 :
if ( F_65 ( V_2 , V_159 ) )
return 1 ;
default:
* V_154 = V_2 -> V_5 . V_163 ;
break;
}
return 0 ;
}
int F_80 ( struct V_1 * V_2 , int V_153 , unsigned long * V_154 )
{
if ( F_79 ( V_2 , V_153 , V_154 ) ) {
F_24 ( V_2 , V_170 ) ;
return 1 ;
}
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , T_2 V_109 )
{
T_2 V_171 = V_2 -> V_5 . V_109 ;
if ( V_109 & V_172 )
return 1 ;
if ( F_52 ( V_2 )
&& ( V_2 -> V_5 . V_109 & V_110 ) != ( V_109 & V_110 ) )
return 1 ;
if ( V_109 & V_173 ) {
struct V_125 * V_174 ;
V_174 = F_60 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_174 || ! ( V_174 -> V_175 & F_61 ( V_176 ) ) )
return 1 ;
}
if ( V_109 & V_177 ) {
struct V_125 * V_174 ;
V_174 = F_60 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_174 || ! ( V_174 -> V_127 & F_61 ( V_178 ) ) )
return 1 ;
}
V_109 &= ~ V_179 ;
V_109 |= V_2 -> V_5 . V_109 & V_179 ;
V_56 -> F_81 ( V_2 , V_109 ) ;
V_2 -> V_5 . V_67 . V_180 . V_181 = ( V_109 & V_182 ) && ! V_183 ;
if ( ( V_109 ^ V_171 ) & V_182 )
F_54 ( V_2 ) ;
return 0 ;
}
void F_82 ( T_2 V_26 )
{
V_172 &= ~ V_26 ;
}
int F_83 ( struct V_1 * V_2 , T_1 V_184 , T_2 V_31 )
{
return V_56 -> V_185 ( V_2 , V_184 , V_31 ) ;
}
static int F_84 ( struct V_1 * V_2 , unsigned V_116 , T_2 * V_31 )
{
return F_83 ( V_2 , V_116 , * V_31 ) ;
}
static void F_85 ( struct V_29 * V_29 , T_4 V_186 )
{
int V_187 ;
int V_98 ;
struct V_188 V_189 ;
struct V_190 V_191 ;
if ( ! V_186 )
return;
V_98 = F_86 ( V_29 , V_186 , & V_187 , sizeof( V_187 ) ) ;
if ( V_98 )
return;
if ( V_187 & 1 )
++ V_187 ;
++ V_187 ;
F_87 ( V_29 , V_186 , & V_187 , sizeof( V_187 ) ) ;
F_88 ( & V_191 ) ;
V_189 . V_192 = V_191 . V_193 ;
V_189 . V_194 = V_191 . V_195 ;
V_189 . V_187 = V_187 ;
F_87 ( V_29 , V_186 , & V_189 , sizeof( V_189 ) ) ;
V_187 ++ ;
F_87 ( V_29 , V_186 , & V_187 , sizeof( V_187 ) ) ;
}
static T_5 F_89 ( T_5 V_196 , T_5 V_197 )
{
T_5 V_198 , V_199 ;
__asm__ ( "divl %4"
: "=a" (quotient), "=d" (remainder)
: "0" (0), "1" (dividend), "r" (divisor) );
return V_198 ;
}
static void F_90 ( T_5 V_200 , T_5 V_201 ,
T_6 * V_202 , T_1 * V_203 )
{
T_7 V_204 ;
T_8 V_205 = 0 ;
T_7 V_206 ;
T_5 V_207 ;
V_206 = V_201 * 1000LL ;
V_204 = V_200 * 1000LL ;
while ( V_206 > V_204 * 2 || V_206 & 0xffffffff00000000ULL ) {
V_206 >>= 1 ;
V_205 -- ;
}
V_207 = ( T_5 ) V_206 ;
while ( V_207 <= V_204 || V_204 & 0xffffffff00000000ULL ) {
if ( V_204 & 0xffffffff00000000ULL || V_207 & 0x80000000 )
V_204 >>= 1 ;
else
V_207 <<= 1 ;
V_205 ++ ;
}
* V_202 = V_205 ;
* V_203 = F_89 ( V_204 , V_207 ) ;
F_91 ( L_2 ,
V_208 , V_201 , V_200 , V_205 , * V_203 ) ;
}
static inline T_2 F_92 ( void )
{
struct V_190 V_209 ;
F_93 ( F_94 () ) ;
F_95 ( & V_209 ) ;
F_96 ( & V_209 ) ;
return F_97 ( & V_209 ) ;
}
static inline int F_98 ( void )
{
int V_210 = F_99 () ;
int V_87 = ! F_100 ( V_211 ) &&
F_101 ( V_210 ) != 0 ;
F_102 () ;
return V_87 ;
}
static T_2 F_103 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_212 )
return V_2 -> V_5 . V_212 ;
else
return F_104 ( V_213 ) ;
}
static inline T_2 F_105 ( struct V_1 * V_2 , T_2 V_194 )
{
T_2 V_87 ;
F_93 ( F_94 () ) ;
if ( F_98 () )
F_106 ( V_214
L_3 ) ;
V_87 = V_194 * F_103 ( V_2 ) ;
F_107 ( V_87 , V_215 ) ;
return V_87 ;
}
static void F_108 ( struct V_1 * V_2 , T_1 V_216 )
{
F_90 ( V_216 , V_217 / 1000 ,
& V_2 -> V_5 . V_218 ,
& V_2 -> V_5 . V_219 ) ;
}
static T_2 F_109 ( struct V_1 * V_2 , T_9 V_220 )
{
T_2 V_221 = F_110 ( V_220 - V_2 -> V_5 . V_222 ,
V_2 -> V_5 . V_219 ,
V_2 -> V_5 . V_218 ) ;
V_221 += V_2 -> V_5 . V_223 ;
return V_221 ;
}
void F_111 ( struct V_1 * V_2 , T_2 V_31 )
{
struct V_29 * V_29 = V_2 -> V_29 ;
T_2 V_73 , V_224 , V_225 ;
unsigned long V_226 ;
T_9 V_227 ;
F_112 ( & V_29 -> V_5 . V_228 , V_226 ) ;
V_73 = V_56 -> V_229 ( V_2 , V_31 ) ;
V_224 = F_92 () ;
V_225 = V_224 - V_29 -> V_5 . V_222 ;
V_227 = V_31 - V_29 -> V_5 . V_223 ;
if ( V_227 < 0 )
V_227 = - V_227 ;
if ( V_227 < F_105 ( V_2 , 5ULL * V_217 ) &&
V_225 < 5ULL * V_217 ) {
if ( ! F_113 () ) {
V_73 = V_29 -> V_5 . V_230 ;
F_91 ( L_4 , V_31 ) ;
} else {
T_2 V_231 = F_105 ( V_2 , V_225 ) ;
V_73 += V_231 ;
F_91 ( L_5 , V_231 ) ;
}
V_224 = V_29 -> V_5 . V_222 ;
}
V_29 -> V_5 . V_222 = V_224 ;
V_29 -> V_5 . V_223 = V_31 ;
V_29 -> V_5 . V_230 = V_73 ;
V_56 -> V_232 ( V_2 , V_73 ) ;
F_114 ( & V_29 -> V_5 . V_228 , V_226 ) ;
V_2 -> V_5 . V_233 . V_234 = 0 ;
V_2 -> V_5 . V_223 = V_31 ;
V_2 -> V_5 . V_222 = V_224 ;
}
static int F_115 ( struct V_1 * V_235 )
{
unsigned long V_226 ;
struct V_236 * V_2 = & V_235 -> V_5 ;
void * V_237 ;
unsigned long V_216 ;
T_9 V_220 , V_238 ;
T_2 V_234 ;
F_116 ( V_226 ) ;
F_117 ( V_235 , V_239 , & V_234 ) ;
V_220 = F_92 () ;
V_216 = F_103 ( V_235 ) ;
if ( F_71 ( V_216 == 0 ) ) {
F_118 ( V_226 ) ;
F_23 ( V_240 , V_235 ) ;
return 1 ;
}
if ( V_2 -> V_241 ) {
T_2 V_221 = F_109 ( V_235 , V_220 ) ;
if ( V_221 > V_234 ) {
V_56 -> V_242 ( V_235 , V_221 - V_234 ) ;
V_234 = V_221 ;
}
}
F_118 ( V_226 ) ;
if ( ! V_2 -> V_243 )
return 0 ;
V_238 = 0 ;
if ( V_2 -> V_233 . V_234 && V_2 -> V_244 ) {
V_238 = V_2 -> V_244 -
V_2 -> V_233 . V_234 ;
V_238 = F_110 ( V_238 ,
V_2 -> V_233 . V_245 ,
V_2 -> V_233 . V_246 ) ;
V_238 += V_2 -> V_247 ;
}
if ( F_71 ( V_2 -> V_248 != V_216 ) ) {
F_90 ( V_217 / 1000 , V_216 ,
& V_2 -> V_233 . V_246 ,
& V_2 -> V_233 . V_245 ) ;
V_2 -> V_248 = V_216 ;
}
if ( V_238 > V_220 )
V_220 = V_238 ;
V_2 -> V_233 . V_234 = V_234 ;
V_2 -> V_233 . V_249 = V_220 + V_235 -> V_29 -> V_5 . V_250 ;
V_2 -> V_247 = V_220 ;
V_2 -> V_244 = V_234 ;
V_2 -> V_233 . V_226 = 0 ;
V_2 -> V_233 . V_187 += 2 ;
V_237 = F_119 ( V_2 -> V_243 , V_251 ) ;
memcpy ( V_237 + V_2 -> V_252 , & V_2 -> V_233 ,
sizeof( V_2 -> V_233 ) ) ;
F_120 ( V_237 , V_251 ) ;
F_121 ( V_235 -> V_29 , V_2 -> time >> V_85 ) ;
return 0 ;
}
static bool F_122 ( unsigned V_21 )
{
switch ( V_21 ) {
case 0x200 ... 0x200 + 2 * V_253 - 1 :
case V_254 :
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
return true ;
case 0x2f8 :
return true ;
}
return false ;
}
static bool F_123 ( unsigned V_267 )
{
return V_267 < 8 && ( 1 << V_267 ) & 0xf3 ;
}
static bool F_124 ( unsigned V_267 )
{
return V_267 < 8 && ( 1 << V_267 ) & 0x73 ;
}
static bool F_125 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
int V_3 ;
if ( ! F_122 ( V_21 ) )
return false ;
if ( V_21 == V_266 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_123 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
} else if ( V_21 == V_265 ) {
if ( V_31 & ~ 0xcff )
return false ;
return F_124 ( V_31 & 0xff ) ;
} else if ( V_21 >= V_254 && V_21 <= V_264 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_124 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
}
return F_124 ( V_31 & 0xff ) ;
}
static int F_126 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
T_2 * V_268 = ( T_2 * ) & V_2 -> V_5 . V_269 . V_270 ;
if ( ! F_125 ( V_2 , V_21 , V_31 ) )
return 1 ;
if ( V_21 == V_265 ) {
V_2 -> V_5 . V_269 . V_271 = V_31 ;
V_2 -> V_5 . V_269 . V_272 = ( V_31 & 0xc00 ) >> 10 ;
} else if ( V_21 == V_254 )
V_268 [ 0 ] = V_31 ;
else if ( V_21 == V_255 || V_21 == V_256 )
V_268 [ 1 + V_21 - V_255 ] = V_31 ;
else if ( V_21 >= V_257 && V_21 <= V_264 )
V_268 [ 3 + V_21 - V_257 ] = V_31 ;
else if ( V_21 == V_266 )
V_2 -> V_5 . V_273 = V_31 ;
else {
int V_274 , V_275 ;
T_2 * V_276 ;
V_274 = ( V_21 - 0x200 ) / 2 ;
V_275 = V_21 - 0x200 - 2 * V_274 ;
if ( ! V_275 )
V_276 =
( T_2 * ) & V_2 -> V_5 . V_269 . V_277 [ V_274 ] . V_278 ;
else
V_276 =
( T_2 * ) & V_2 -> V_5 . V_269 . V_277 [ V_274 ] . V_279 ;
* V_276 = V_31 ;
}
F_54 ( V_2 ) ;
return 0 ;
}
static int F_127 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
T_2 V_280 = V_2 -> V_5 . V_280 ;
unsigned V_281 = V_280 & 0xff ;
switch ( V_21 ) {
case V_282 :
V_2 -> V_5 . V_283 = V_31 ;
break;
case V_284 :
if ( ! ( V_280 & V_285 ) )
return 1 ;
if ( V_31 != 0 && V_31 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_286 = V_31 ;
break;
default:
if ( V_21 >= V_287 &&
V_21 < V_287 + 4 * V_281 ) {
T_1 V_73 = V_21 - V_287 ;
if ( ( V_73 & 0x3 ) == 0 &&
V_31 != 0 && ( V_31 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_288 [ V_73 ] = V_31 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_128 ( struct V_1 * V_2 , T_2 V_31 )
{
struct V_29 * V_29 = V_2 -> V_29 ;
int V_289 = F_45 ( V_2 ) ;
T_10 * V_290 = V_289 ? ( T_10 * ) ( long ) V_29 -> V_5 . F_128 . V_291
: ( T_10 * ) ( long ) V_29 -> V_5 . F_128 . V_292 ;
T_10 V_293 = V_289 ? V_29 -> V_5 . F_128 . V_294
: V_29 -> V_5 . F_128 . V_295 ;
T_1 V_296 = V_31 & ~ V_297 ;
T_2 V_298 = V_31 & V_297 ;
T_10 * V_299 ;
int V_98 ;
V_98 = - V_300 ;
if ( V_296 >= V_293 )
goto V_92;
V_98 = - V_301 ;
V_299 = F_129 ( V_86 , V_302 ) ;
if ( ! V_299 )
goto V_92;
V_98 = - V_80 ;
if ( F_130 ( V_299 , V_290 + ( V_296 * V_86 ) , V_86 ) )
goto V_303;
if ( F_87 ( V_29 , V_298 , V_299 , V_86 ) )
goto V_303;
V_98 = 0 ;
V_303:
F_131 ( V_299 ) ;
V_92:
return V_98 ;
}
static bool F_132 ( struct V_29 * V_29 )
{
return V_29 -> V_5 . V_304 & V_305 ;
}
static bool F_133 ( T_1 V_21 )
{
bool V_98 = false ;
switch ( V_21 ) {
case V_306 :
case V_307 :
V_98 = true ;
break;
}
return V_98 ;
}
static int F_134 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
struct V_29 * V_29 = V_2 -> V_29 ;
switch ( V_21 ) {
case V_306 :
V_29 -> V_5 . V_308 = V_31 ;
if ( ! V_29 -> V_5 . V_308 )
V_29 -> V_5 . V_304 &= ~ V_305 ;
break;
case V_307 : {
T_2 V_81 ;
unsigned long V_309 ;
T_10 V_310 [ 4 ] ;
if ( ! V_29 -> V_5 . V_308 )
break;
if ( ! ( V_31 & V_305 ) ) {
V_29 -> V_5 . V_304 = V_31 ;
break;
}
V_81 = V_31 >> V_311 ;
V_309 = F_135 ( V_29 , V_81 ) ;
if ( F_136 ( V_309 ) )
return 1 ;
V_56 -> V_312 ( V_2 , V_310 ) ;
( ( unsigned char * ) V_310 ) [ 3 ] = 0xc3 ;
if ( F_137 ( ( void V_313 * ) V_309 , V_310 , 4 ) )
return 1 ;
V_29 -> V_5 . V_304 = V_31 ;
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
case V_314 : {
unsigned long V_309 ;
if ( ! ( V_31 & V_315 ) ) {
V_2 -> V_5 . V_316 = V_31 ;
break;
}
V_309 = F_135 ( V_2 -> V_29 , V_31 >>
V_317 ) ;
if ( F_136 ( V_309 ) )
return 1 ;
if ( F_140 ( ( void V_313 * ) V_309 , V_86 ) )
return 1 ;
V_2 -> V_5 . V_316 = V_31 ;
break;
}
case V_318 :
return F_141 ( V_2 , V_319 , V_31 ) ;
case V_320 :
return F_141 ( V_2 , V_321 , V_31 ) ;
case V_322 :
return F_141 ( V_2 , V_323 , V_31 ) ;
default:
F_138 ( V_2 , L_6
L_7 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_142 ( struct V_1 * V_2 , T_2 V_31 )
{
T_4 V_324 = V_31 & ~ 0x3f ;
if ( V_31 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_325 = V_31 ;
if ( ! ( V_31 & V_326 ) ) {
F_53 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_143 ( V_2 -> V_29 , & V_2 -> V_5 . V_6 . V_31 , V_324 ) )
return 1 ;
V_2 -> V_5 . V_6 . V_327 = ! ( V_31 & V_328 ) ;
F_144 ( V_2 ) ;
return 0 ;
}
static void F_145 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_243 ) {
F_146 ( V_2 -> V_5 . V_243 ) ;
V_2 -> V_5 . V_243 = NULL ;
}
}
static void F_147 ( struct V_1 * V_2 )
{
T_2 V_231 ;
if ( ! ( V_2 -> V_5 . V_329 . V_325 & V_330 ) )
return;
V_231 = V_331 -> V_332 . V_333 - V_2 -> V_5 . V_329 . V_334 ;
V_2 -> V_5 . V_329 . V_334 = V_331 -> V_332 . V_333 ;
V_2 -> V_5 . V_329 . V_335 = V_231 ;
}
static void F_148 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_329 . V_325 & V_330 ) )
return;
if ( F_71 ( F_149 ( V_2 -> V_29 , & V_2 -> V_5 . V_329 . V_336 ,
& V_2 -> V_5 . V_329 . V_337 , sizeof( struct V_338 ) ) ) )
return;
V_2 -> V_5 . V_329 . V_337 . V_337 += V_2 -> V_5 . V_329 . V_335 ;
V_2 -> V_5 . V_329 . V_337 . V_187 += 2 ;
V_2 -> V_5 . V_329 . V_335 = 0 ;
F_150 ( V_2 -> V_29 , & V_2 -> V_5 . V_329 . V_336 ,
& V_2 -> V_5 . V_329 . V_337 , sizeof( struct V_338 ) ) ;
}
int F_151 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
switch ( V_21 ) {
case V_339 :
return F_81 ( V_2 , V_31 ) ;
case V_340 :
V_31 &= ~ ( T_2 ) 0x40 ;
V_31 &= ~ ( T_2 ) 0x100 ;
if ( V_31 != 0 ) {
F_138 ( V_2 , L_8 ,
V_31 ) ;
return 1 ;
}
break;
case V_341 :
if ( V_31 != 0 ) {
F_138 ( V_2 , L_9
L_10 , V_31 ) ;
return 1 ;
}
break;
case V_342 :
break;
case V_343 :
if ( ! V_31 ) {
break;
} else if ( V_31 & ~ ( V_344 | V_345 ) ) {
return 1 ;
}
F_138 ( V_2 , L_11 ,
V_208 , V_31 ) ;
break;
case V_346 :
case V_347 :
case V_348 :
case V_349 :
break;
case 0x200 ... 0x2ff :
return F_126 ( V_2 , V_21 , V_31 ) ;
case V_350 :
F_19 ( V_2 , V_31 ) ;
break;
case V_351 ... V_351 + 0x3ff :
return F_152 ( V_2 , V_21 , V_31 ) ;
case V_352 :
V_2 -> V_5 . V_353 = V_31 ;
break;
case V_354 :
case V_355 :
V_2 -> V_29 -> V_5 . V_186 = V_31 ;
F_85 ( V_2 -> V_29 , V_31 ) ;
break;
case V_356 :
case V_357 : {
F_145 ( V_2 ) ;
V_2 -> V_5 . time = V_31 ;
F_23 ( V_240 , V_2 ) ;
if ( ! ( V_31 & 1 ) )
break;
V_2 -> V_5 . V_252 = V_31 & ~ ( V_297 | 1 ) ;
V_2 -> V_5 . V_243 =
F_153 ( V_2 -> V_29 , V_31 >> V_85 ) ;
if ( F_154 ( V_2 -> V_5 . V_243 ) ) {
F_155 ( V_2 -> V_5 . V_243 ) ;
V_2 -> V_5 . V_243 = NULL ;
}
break;
}
case V_358 :
if ( F_142 ( V_2 , V_31 ) )
return 1 ;
break;
case V_359 :
if ( F_71 ( ! F_156 () ) )
return 1 ;
if ( V_31 & V_360 )
return 1 ;
if ( F_143 ( V_2 -> V_29 , & V_2 -> V_5 . V_329 . V_336 ,
V_31 & V_361 ) )
return 1 ;
V_2 -> V_5 . V_329 . V_325 = V_31 ;
if ( ! ( V_31 & V_330 ) )
break;
V_2 -> V_5 . V_329 . V_334 = V_331 -> V_332 . V_333 ;
F_157 () ;
F_147 ( V_2 ) ;
F_158 () ;
F_23 ( V_362 , V_2 ) ;
break;
case V_284 :
case V_282 :
case V_287 ... V_287 + 4 * V_363 - 1 :
return F_127 ( V_2 , V_21 , V_31 ) ;
case V_364 :
case V_365 :
case V_366 :
case V_367 :
case V_368 :
case V_369 :
if ( V_31 != 0 )
F_138 ( V_2 , L_12
L_13 , V_21 , V_31 ) ;
break;
case V_370 :
case V_371 :
case V_372 :
case V_373 :
case V_374 :
case V_375 :
F_138 ( V_2 , L_12
L_13 , V_21 , V_31 ) ;
break;
case V_376 :
break;
case V_306 ... V_377 :
if ( F_133 ( V_21 ) ) {
int V_98 ;
F_159 ( & V_2 -> V_29 -> V_378 ) ;
V_98 = F_134 ( V_2 , V_21 , V_31 ) ;
F_160 ( & V_2 -> V_29 -> V_378 ) ;
return V_98 ;
} else
return F_139 ( V_2 , V_21 , V_31 ) ;
break;
case V_379 :
F_138 ( V_2 , L_14 , V_21 , V_31 ) ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_29 -> V_5 . F_128 . V_21 ) )
return F_128 ( V_2 , V_31 ) ;
if ( ! V_380 ) {
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
int F_117 ( struct V_1 * V_2 , T_1 V_184 , T_2 * V_381 )
{
return V_56 -> V_382 ( V_2 , V_184 , V_381 ) ;
}
static int F_161 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_381 )
{
T_2 * V_268 = ( T_2 * ) & V_2 -> V_5 . V_269 . V_270 ;
if ( ! F_122 ( V_21 ) )
return 1 ;
if ( V_21 == V_265 )
* V_381 = V_2 -> V_5 . V_269 . V_271 +
( V_2 -> V_5 . V_269 . V_272 << 10 ) ;
else if ( V_21 == V_254 )
* V_381 = V_268 [ 0 ] ;
else if ( V_21 == V_255 || V_21 == V_256 )
* V_381 = V_268 [ 1 + V_21 - V_255 ] ;
else if ( V_21 >= V_257 && V_21 <= V_264 )
* V_381 = V_268 [ 3 + V_21 - V_257 ] ;
else if ( V_21 == V_266 )
* V_381 = V_2 -> V_5 . V_273 ;
else {
int V_274 , V_275 ;
T_2 * V_276 ;
V_274 = ( V_21 - 0x200 ) / 2 ;
V_275 = V_21 - 0x200 - 2 * V_274 ;
if ( ! V_275 )
V_276 =
( T_2 * ) & V_2 -> V_5 . V_269 . V_277 [ V_274 ] . V_278 ;
else
V_276 =
( T_2 * ) & V_2 -> V_5 . V_269 . V_277 [ V_274 ] . V_279 ;
* V_381 = * V_276 ;
}
return 0 ;
}
static int F_162 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_381 )
{
T_2 V_31 ;
T_2 V_280 = V_2 -> V_5 . V_280 ;
unsigned V_281 = V_280 & 0xff ;
switch ( V_21 ) {
case V_383 :
case V_384 :
V_31 = 0 ;
break;
case V_385 :
V_31 = V_2 -> V_5 . V_280 ;
break;
case V_284 :
if ( ! ( V_280 & V_285 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_286 ;
break;
case V_282 :
V_31 = V_2 -> V_5 . V_283 ;
break;
default:
if ( V_21 >= V_287 &&
V_21 < V_287 + 4 * V_281 ) {
T_1 V_73 = V_21 - V_287 ;
V_31 = V_2 -> V_5 . V_288 [ V_73 ] ;
break;
}
return 1 ;
}
* V_381 = V_31 ;
return 0 ;
}
static int F_163 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_381 )
{
T_2 V_31 = 0 ;
struct V_29 * V_29 = V_2 -> V_29 ;
switch ( V_21 ) {
case V_306 :
V_31 = V_29 -> V_5 . V_308 ;
break;
case V_307 :
V_31 = V_29 -> V_5 . V_304 ;
break;
default:
F_138 ( V_2 , L_16 , V_21 ) ;
return 1 ;
}
* V_381 = V_31 ;
return 0 ;
}
static int F_164 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_381 )
{
T_2 V_31 = 0 ;
switch ( V_21 ) {
case V_386 : {
int V_98 ;
struct V_1 * V_235 ;
F_165 (r, v, vcpu->kvm)
if ( V_235 == V_2 )
V_31 = V_98 ;
break;
}
case V_318 :
return F_166 ( V_2 , V_319 , V_381 ) ;
case V_320 :
return F_166 ( V_2 , V_321 , V_381 ) ;
case V_322 :
return F_166 ( V_2 , V_323 , V_381 ) ;
default:
F_138 ( V_2 , L_16 , V_21 ) ;
return 1 ;
}
* V_381 = V_31 ;
return 0 ;
}
int F_167 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_381 )
{
T_2 V_31 ;
switch ( V_21 ) {
case V_387 :
case V_346 :
case V_388 :
case V_343 :
case V_389 :
case V_390 :
case V_391 :
case V_392 :
case V_393 :
case V_340 :
case V_348 :
case V_370 :
case V_371 :
case V_364 :
case V_365 :
case V_366 :
case V_372 :
case V_394 :
case V_342 :
case V_341 :
V_31 = 0 ;
break;
case V_395 :
V_31 = 0x500 | V_253 ;
break;
case 0x200 ... 0x2ff :
return F_161 ( V_2 , V_21 , V_381 ) ;
case 0xcd :
V_31 = 3 ;
break;
case V_396 :
V_31 = 1 << 24 ;
break;
case V_350 :
V_31 = F_17 ( V_2 ) ;
break;
case V_351 ... V_351 + 0x3ff :
return F_168 ( V_2 , V_21 , V_381 ) ;
break;
case V_352 :
V_31 = V_2 -> V_5 . V_353 ;
break;
case V_397 :
V_31 = 1000ULL ;
V_31 |= ( ( ( T_7 ) 4ULL ) << 40 ) ;
break;
case V_339 :
V_31 = V_2 -> V_5 . V_109 ;
break;
case V_355 :
case V_354 :
V_31 = V_2 -> V_29 -> V_5 . V_186 ;
break;
case V_357 :
case V_356 :
V_31 = V_2 -> V_5 . time ;
break;
case V_358 :
V_31 = V_2 -> V_5 . V_6 . V_325 ;
break;
case V_359 :
V_31 = V_2 -> V_5 . V_329 . V_325 ;
break;
case V_383 :
case V_384 :
case V_385 :
case V_284 :
case V_282 :
case V_287 ... V_287 + 4 * V_363 - 1 :
return F_162 ( V_2 , V_21 , V_381 ) ;
case V_376 :
V_31 = 0x20000000 ;
break;
case V_306 ... V_377 :
if ( F_133 ( V_21 ) ) {
int V_98 ;
F_159 ( & V_2 -> V_29 -> V_378 ) ;
V_98 = F_163 ( V_2 , V_21 , V_381 ) ;
F_160 ( & V_2 -> V_29 -> V_378 ) ;
return V_98 ;
} else
return F_164 ( V_2 , V_21 , V_381 ) ;
break;
case V_379 :
V_31 = 0xbe702111 ;
break;
default:
if ( ! V_380 ) {
F_138 ( V_2 , L_17 , V_21 ) ;
return 1 ;
} else {
F_138 ( V_2 , L_18 , V_21 ) ;
V_31 = 0 ;
}
break;
}
* V_381 = V_31 ;
return 0 ;
}
static int F_169 ( struct V_1 * V_2 , struct V_398 * V_19 ,
struct V_399 * V_400 ,
int (* F_170)( struct V_1 * V_2 ,
unsigned V_116 , T_2 * V_31 ) )
{
int V_3 , V_274 ;
V_274 = F_171 ( & V_2 -> V_29 -> V_401 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_402 ; ++ V_3 )
if ( F_170 ( V_2 , V_400 [ V_3 ] . V_116 , & V_400 [ V_3 ] . V_31 ) )
break;
F_172 ( & V_2 -> V_29 -> V_401 , V_274 ) ;
return V_3 ;
}
static int F_173 ( struct V_1 * V_2 , struct V_398 V_313 * V_403 ,
int (* F_170)( struct V_1 * V_2 ,
unsigned V_116 , T_2 * V_31 ) ,
int V_404 )
{
struct V_398 V_19 ;
struct V_399 * V_400 ;
int V_98 , V_405 ;
unsigned V_406 ;
V_98 = - V_80 ;
if ( F_130 ( & V_19 , V_403 , sizeof V_19 ) )
goto V_92;
V_98 = - V_300 ;
if ( V_19 . V_402 >= V_407 )
goto V_92;
V_98 = - V_301 ;
V_406 = sizeof( struct V_399 ) * V_19 . V_402 ;
V_400 = F_174 ( V_406 , V_302 ) ;
if ( ! V_400 )
goto V_92;
V_98 = - V_80 ;
if ( F_130 ( V_400 , V_403 -> V_400 , V_406 ) )
goto V_303;
V_98 = V_405 = F_169 ( V_2 , & V_19 , V_400 , F_170 ) ;
if ( V_98 < 0 )
goto V_303;
V_98 = - V_80 ;
if ( V_404 && F_175 ( V_403 -> V_400 , V_400 , V_406 ) )
goto V_303;
V_98 = V_405 ;
V_303:
F_131 ( V_400 ) ;
V_92:
return V_98 ;
}
int F_176 ( long V_408 )
{
int V_98 ;
switch ( V_408 ) {
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
case V_437 :
case V_438 :
case V_439 :
V_98 = 1 ;
break;
case V_440 :
V_98 = V_441 ;
break;
case V_442 :
V_98 = ! V_56 -> V_443 () ;
break;
case V_444 :
V_98 = V_445 ;
break;
case V_446 :
V_98 = V_447 ;
break;
case V_448 :
V_98 = 0 ;
break;
case V_449 :
V_98 = F_177 () ;
break;
case V_450 :
V_98 = V_363 ;
break;
case V_451 :
V_98 = V_132 ;
break;
case V_452 :
V_98 = V_453 ;
break;
default:
V_98 = 0 ;
break;
}
return V_98 ;
}
long F_178 ( struct V_454 * V_455 ,
unsigned int V_456 , unsigned long V_457 )
{
void V_313 * V_458 = ( void V_313 * ) V_457 ;
long V_98 ;
switch ( V_456 ) {
case V_459 : {
struct V_460 V_313 * V_461 = V_458 ;
struct V_460 V_462 ;
unsigned V_405 ;
V_98 = - V_80 ;
if ( F_130 ( & V_462 , V_461 , sizeof V_462 ) )
goto V_92;
V_405 = V_462 . V_402 ;
V_462 . V_402 = V_463 + F_41 ( V_464 ) ;
if ( F_175 ( V_461 , & V_462 , sizeof V_462 ) )
goto V_92;
V_98 = - V_300 ;
if ( V_405 < V_462 . V_402 )
goto V_92;
V_98 = - V_80 ;
if ( F_175 ( V_461 -> V_465 , & V_466 ,
V_463 * sizeof( T_1 ) ) )
goto V_92;
if ( F_175 ( V_461 -> V_465 + V_463 ,
& V_464 ,
F_41 ( V_464 ) * sizeof( T_1 ) ) )
goto V_92;
V_98 = 0 ;
break;
}
case V_467 : {
struct V_468 V_313 * V_469 = V_458 ;
struct V_468 V_470 ;
V_98 = - V_80 ;
if ( F_130 ( & V_470 , V_469 , sizeof V_470 ) )
goto V_92;
V_98 = F_179 ( & V_470 ,
V_469 -> V_400 ) ;
if ( V_98 )
goto V_92;
V_98 = - V_80 ;
if ( F_175 ( V_469 , & V_470 , sizeof V_470 ) )
goto V_92;
V_98 = 0 ;
break;
}
case V_471 : {
T_2 V_472 ;
V_472 = V_473 ;
V_98 = - V_80 ;
if ( F_175 ( V_458 , & V_472 , sizeof V_472 ) )
goto V_92;
V_98 = 0 ;
break;
}
default:
V_98 = - V_474 ;
}
V_92:
return V_98 ;
}
static void F_180 ( void * V_475 )
{
F_181 () ;
}
static bool F_182 ( struct V_1 * V_2 )
{
return V_2 -> V_29 -> V_5 . V_476 &&
! ( V_2 -> V_29 -> V_5 . V_477 & V_478 ) ;
}
void F_183 ( struct V_1 * V_2 , int V_210 )
{
if ( F_182 ( V_2 ) ) {
if ( V_56 -> V_479 () )
F_184 ( V_210 , V_2 -> V_5 . V_480 ) ;
else if ( V_2 -> V_210 != - 1 && V_2 -> V_210 != V_210 )
F_185 ( V_2 -> V_210 ,
F_180 , NULL , 1 ) ;
}
V_56 -> V_481 ( V_2 , V_210 ) ;
if ( F_71 ( V_2 -> V_210 != V_210 ) || F_113 () ) {
T_9 V_482 ;
T_2 V_221 ;
F_117 ( V_2 , V_239 , & V_221 ) ;
V_482 = ! V_2 -> V_5 . V_244 ? 0 :
V_221 - V_2 -> V_5 . V_244 ;
if ( V_482 < 0 )
F_186 ( L_19 ) ;
if ( F_113 () ) {
V_56 -> V_242 ( V_2 , - V_482 ) ;
V_2 -> V_5 . V_241 = 1 ;
}
F_23 ( V_240 , V_2 ) ;
if ( V_2 -> V_210 != V_210 )
F_187 ( V_2 ) ;
V_2 -> V_210 = V_210 ;
}
F_147 ( V_2 ) ;
F_23 ( V_362 , V_2 ) ;
}
void F_188 ( struct V_1 * V_2 )
{
V_56 -> V_483 ( V_2 ) ;
F_189 ( V_2 ) ;
F_117 ( V_2 , V_239 , & V_2 -> V_5 . V_244 ) ;
}
static int F_190 ( void )
{
unsigned long long V_109 = 0 ;
F_10 ( V_339 , & V_109 ) ;
return V_109 & V_182 ;
}
static void F_191 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_125 * V_484 , * V_485 ;
V_485 = NULL ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 . V_486 ; ++ V_3 ) {
V_484 = & V_2 -> V_5 . V_487 [ V_3 ] ;
if ( V_484 -> V_133 == 0x80000001 ) {
V_485 = V_484 ;
break;
}
}
if ( V_485 && ( V_485 -> V_175 & ( 1 << 20 ) ) && ! F_190 () ) {
V_485 -> V_175 &= ~ ( 1 << 20 ) ;
F_9 ( V_488 L_20 ) ;
}
}
static int F_192 ( struct V_1 * V_2 ,
struct V_489 * V_470 ,
struct V_490 V_313 * V_400 )
{
int V_98 , V_3 ;
struct V_490 * V_487 ;
V_98 = - V_300 ;
if ( V_470 -> V_491 > V_492 )
goto V_92;
V_98 = - V_301 ;
V_487 = F_193 ( sizeof( struct V_490 ) * V_470 -> V_491 ) ;
if ( ! V_487 )
goto V_92;
V_98 = - V_80 ;
if ( F_130 ( V_487 , V_400 ,
V_470 -> V_491 * sizeof( struct V_490 ) ) )
goto V_303;
for ( V_3 = 0 ; V_3 < V_470 -> V_491 ; V_3 ++ ) {
V_2 -> V_5 . V_487 [ V_3 ] . V_133 = V_487 [ V_3 ] . V_133 ;
V_2 -> V_5 . V_487 [ V_3 ] . V_493 = V_487 [ V_3 ] . V_493 ;
V_2 -> V_5 . V_487 [ V_3 ] . V_129 = V_487 [ V_3 ] . V_129 ;
V_2 -> V_5 . V_487 [ V_3 ] . V_127 = V_487 [ V_3 ] . V_127 ;
V_2 -> V_5 . V_487 [ V_3 ] . V_175 = V_487 [ V_3 ] . V_175 ;
V_2 -> V_5 . V_487 [ V_3 ] . V_116 = 0 ;
V_2 -> V_5 . V_487 [ V_3 ] . V_226 = 0 ;
V_2 -> V_5 . V_487 [ V_3 ] . V_494 [ 0 ] = 0 ;
V_2 -> V_5 . V_487 [ V_3 ] . V_494 [ 1 ] = 0 ;
V_2 -> V_5 . V_487 [ V_3 ] . V_494 [ 2 ] = 0 ;
}
V_2 -> V_5 . V_486 = V_470 -> V_491 ;
F_191 ( V_2 ) ;
V_98 = 0 ;
F_194 ( V_2 ) ;
V_56 -> V_495 ( V_2 ) ;
F_64 ( V_2 ) ;
V_303:
F_195 ( V_487 ) ;
V_92:
return V_98 ;
}
static int F_196 ( struct V_1 * V_2 ,
struct V_468 * V_470 ,
struct V_125 V_313 * V_400 )
{
int V_98 ;
V_98 = - V_300 ;
if ( V_470 -> V_491 > V_492 )
goto V_92;
V_98 = - V_80 ;
if ( F_130 ( & V_2 -> V_5 . V_487 , V_400 ,
V_470 -> V_491 * sizeof( struct V_125 ) ) )
goto V_92;
V_2 -> V_5 . V_486 = V_470 -> V_491 ;
F_194 ( V_2 ) ;
V_56 -> V_495 ( V_2 ) ;
F_64 ( V_2 ) ;
return 0 ;
V_92:
return V_98 ;
}
static int F_197 ( struct V_1 * V_2 ,
struct V_468 * V_470 ,
struct V_125 V_313 * V_400 )
{
int V_98 ;
V_98 = - V_300 ;
if ( V_470 -> V_491 < V_2 -> V_5 . V_486 )
goto V_92;
V_98 = - V_80 ;
if ( F_175 ( V_400 , & V_2 -> V_5 . V_487 ,
V_2 -> V_5 . V_486 * sizeof( struct V_125 ) ) )
goto V_92;
return 0 ;
V_92:
V_470 -> V_491 = V_2 -> V_5 . V_486 ;
return V_98 ;
}
static void F_198 ( T_1 * V_496 , int V_497 )
{
* V_496 &= V_498 . V_499 [ V_497 ] ;
}
static void F_199 ( struct V_125 * V_485 , T_1 V_133 ,
T_1 V_116 )
{
V_485 -> V_133 = V_133 ;
V_485 -> V_116 = V_116 ;
F_200 ( V_485 -> V_133 , V_485 -> V_116 ,
& V_485 -> V_493 , & V_485 -> V_129 , & V_485 -> V_127 , & V_485 -> V_175 ) ;
V_485 -> V_226 = 0 ;
}
static bool F_201 ( unsigned F_61 )
{
T_2 V_26 = ( ( T_2 ) 1 << F_61 ) ;
return V_26 & ( V_120 | V_122 | V_121 ) & V_123 ;
}
static void F_202 ( struct V_125 * V_485 , T_1 V_133 ,
T_1 V_116 , int * V_491 , int V_500 )
{
unsigned V_501 = F_190 () ? F_203 ( V_502 ) : 0 ;
#ifdef F_51
unsigned V_503 = ( V_56 -> V_504 () == V_505 )
? F_203 ( V_506 ) : 0 ;
unsigned V_507 = F_203 ( V_508 ) ;
#else
unsigned V_503 = 0 ;
unsigned V_507 = 0 ;
#endif
unsigned V_509 = V_56 -> V_510 () ? F_203 ( V_511 ) : 0 ;
const T_1 V_512 =
F_203 ( V_513 ) | F_203 ( V_514 ) | F_203 ( V_515 ) | F_203 ( V_516 ) |
F_203 ( V_517 ) | F_203 ( V_518 ) | F_203 ( V_519 ) | F_203 ( V_520 ) |
F_203 ( V_521 ) | F_203 ( V_522 ) | 0 | F_203 ( V_523 ) |
F_203 ( V_524 ) | F_203 ( V_525 ) | F_203 ( V_526 ) | F_203 ( V_527 ) |
F_203 ( V_528 ) | F_203 ( V_529 ) | 0 | F_203 ( V_530 ) |
0 | F_203 ( V_531 ) |
F_203 ( V_532 ) | F_203 ( V_533 ) | F_203 ( V_534 ) | F_203 ( V_535 ) |
0 ;
const T_1 V_536 =
F_203 ( V_513 ) | F_203 ( V_514 ) | F_203 ( V_515 ) | F_203 ( V_516 ) |
F_203 ( V_517 ) | F_203 ( V_518 ) | F_203 ( V_519 ) | F_203 ( V_520 ) |
F_203 ( V_521 ) | F_203 ( V_522 ) | 0 | F_203 ( V_537 ) |
F_203 ( V_524 ) | F_203 ( V_525 ) | F_203 ( V_526 ) | F_203 ( V_527 ) |
F_203 ( V_528 ) | F_203 ( V_529 ) | 0 |
V_501 | 0 | F_203 ( V_538 ) | F_203 ( V_531 ) |
F_203 ( V_532 ) | F_203 ( V_539 ) | V_503 | V_509 |
0 | V_507 | F_203 ( 3DNOWEXT ) | F_203 ( 3DNOW ) ;
const T_1 V_540 =
F_203 ( V_541 ) | F_203 ( V_542 ) | 0 |
0 |
0 | F_203 ( V_543 ) | 0 | 0 |
0 | F_203 ( V_544 ) | 0 |
0 | F_203 ( V_545 ) |
F_203 ( V_546 ) | F_203 ( V_547 ) | F_203 ( V_548 ) | F_203 ( V_549 ) |
0 | F_203 ( V_550 ) | F_203 ( V_551 ) | 0 | F_203 ( V_552 ) |
F_203 ( V_553 ) | F_203 ( V_554 ) ;
const T_1 V_555 =
F_203 ( V_556 ) | F_203 ( V_557 ) | 0 | 0 |
F_203 ( V_558 ) | F_203 ( V_559 ) | F_203 ( V_560 ) | F_203 ( V_561 ) |
F_203 ( 3DNOWPREFETCH ) | 0 | 0 | F_203 ( V_562 ) |
0 | F_203 ( V_563 ) | F_203 ( V_564 ) ;
const T_1 V_565 =
F_203 ( V_566 ) | F_203 ( V_567 ) | F_203 ( V_568 ) | F_203 ( V_569 ) |
F_203 ( V_570 ) | F_203 ( V_571 ) | F_203 ( V_572 ) | F_203 ( V_573 ) |
F_203 ( V_574 ) | F_203 ( V_575 ) ;
const T_1 V_576 =
F_203 ( V_577 ) | F_203 ( V_578 ) | F_203 ( V_579 ) ;
F_99 () ;
F_199 ( V_485 , V_133 , V_116 ) ;
++ * V_491 ;
switch ( V_133 ) {
case 0 :
V_485 -> V_493 = F_204 ( V_485 -> V_493 , ( T_1 ) 0xd ) ;
break;
case 1 :
V_485 -> V_175 &= V_512 ;
F_198 ( & V_485 -> V_175 , 0 ) ;
V_485 -> V_127 &= V_540 ;
F_198 ( & V_485 -> V_127 , 4 ) ;
V_485 -> V_127 |= F_203 ( V_547 ) ;
break;
case 2 : {
int V_267 , V_580 = V_485 -> V_493 & 0xff ;
V_485 -> V_226 |= V_581 ;
V_485 -> V_226 |= V_582 ;
for ( V_267 = 1 ; V_267 < V_580 && * V_491 < V_500 ; ++ V_267 ) {
F_199 ( & V_485 [ V_267 ] , V_133 , 0 ) ;
V_485 [ V_267 ] . V_226 |= V_581 ;
++ * V_491 ;
}
break;
}
case 4 : {
int V_3 , V_583 ;
V_485 -> V_226 |= V_584 ;
for ( V_3 = 1 ; * V_491 < V_500 ; ++ V_3 ) {
V_583 = V_485 [ V_3 - 1 ] . V_493 & 0x1f ;
if ( ! V_583 )
break;
F_199 ( & V_485 [ V_3 ] , V_133 , V_3 ) ;
V_485 [ V_3 ] . V_226 |=
V_584 ;
++ * V_491 ;
}
break;
}
case 7 : {
V_485 -> V_226 |= V_584 ;
if ( V_116 == 0 ) {
V_485 -> V_129 &= V_576 ;
F_198 ( & V_485 -> V_129 , 9 ) ;
} else
V_485 -> V_129 = 0 ;
V_485 -> V_493 = 0 ;
V_485 -> V_127 = 0 ;
V_485 -> V_175 = 0 ;
break;
}
case 9 :
break;
case 0xb : {
int V_3 , V_585 ;
V_485 -> V_226 |= V_584 ;
for ( V_3 = 1 ; * V_491 < V_500 ; ++ V_3 ) {
V_585 = V_485 [ V_3 - 1 ] . V_127 & 0xff00 ;
if ( ! V_585 )
break;
F_199 ( & V_485 [ V_3 ] , V_133 , V_3 ) ;
V_485 [ V_3 ] . V_226 |=
V_584 ;
++ * V_491 ;
}
break;
}
case 0xd : {
int V_274 , V_3 ;
V_485 -> V_226 |= V_584 ;
for ( V_274 = 1 , V_3 = 1 ; * V_491 < V_500 && V_274 < 64 ; ++ V_274 ) {
F_199 ( & V_485 [ V_3 ] , V_133 , V_274 ) ;
if ( V_485 [ V_3 ] . V_493 == 0 || ! F_201 ( V_274 ) )
continue;
V_485 [ V_3 ] . V_226 |=
V_584 ;
++ * V_491 ;
++ V_3 ;
}
break;
}
case V_586 : {
char V_587 [ 12 ] = L_21 ;
T_1 * V_588 = ( T_1 * ) V_587 ;
V_485 -> V_493 = 0 ;
V_485 -> V_129 = V_588 [ 0 ] ;
V_485 -> V_127 = V_588 [ 1 ] ;
V_485 -> V_175 = V_588 [ 2 ] ;
break;
}
case V_589 :
V_485 -> V_493 = ( 1 << V_590 ) |
( 1 << V_591 ) |
( 1 << V_592 ) |
( 1 << V_593 ) |
( 1 << V_594 ) ;
if ( F_156 () )
V_485 -> V_493 |= ( 1 << V_595 ) ;
V_485 -> V_129 = 0 ;
V_485 -> V_127 = 0 ;
V_485 -> V_175 = 0 ;
break;
case 0x80000000 :
V_485 -> V_493 = F_204 ( V_485 -> V_493 , 0x8000001a ) ;
break;
case 0x80000001 :
V_485 -> V_175 &= V_536 ;
F_198 ( & V_485 -> V_175 , 1 ) ;
V_485 -> V_127 &= V_555 ;
F_198 ( & V_485 -> V_127 , 6 ) ;
break;
case 0x80000008 : {
unsigned V_596 = ( V_485 -> V_493 >> 16 ) & 0xff ;
unsigned V_597 = F_205 ( ( V_485 -> V_493 >> 8 ) & 0xff , 48U ) ;
unsigned V_598 = V_485 -> V_493 & 0xff ;
if ( ! V_596 )
V_596 = V_598 ;
V_485 -> V_493 = V_596 | ( V_597 << 8 ) ;
V_485 -> V_129 = V_485 -> V_175 = 0 ;
break;
}
case 0x80000019 :
V_485 -> V_127 = V_485 -> V_175 = 0 ;
break;
case 0x8000001a :
break;
case 0x8000001d :
break;
case 0xC0000000 :
V_485 -> V_493 = F_204 ( V_485 -> V_493 , 0xC0000004 ) ;
break;
case 0xC0000001 :
V_485 -> V_175 &= V_565 ;
F_198 ( & V_485 -> V_175 , 5 ) ;
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
V_485 -> V_493 = V_485 -> V_129 = V_485 -> V_127 = V_485 -> V_175 = 0 ;
break;
}
V_56 -> V_599 ( V_133 , V_485 ) ;
F_102 () ;
}
static int F_179 ( struct V_468 * V_470 ,
struct V_125 V_313 * V_400 )
{
struct V_125 * V_487 ;
int V_600 , V_491 = 0 , V_98 = - V_300 ;
T_1 V_601 ;
if ( V_470 -> V_491 < 1 )
goto V_92;
if ( V_470 -> V_491 > V_492 )
V_470 -> V_491 = V_492 ;
V_98 = - V_301 ;
V_487 = F_193 ( sizeof( struct V_125 ) * V_470 -> V_491 ) ;
if ( ! V_487 )
goto V_92;
F_202 ( & V_487 [ 0 ] , 0 , 0 , & V_491 , V_470 -> V_491 ) ;
V_600 = V_487 [ 0 ] . V_493 ;
for ( V_601 = 1 ; V_601 <= V_600 && V_491 < V_470 -> V_491 ; ++ V_601 )
F_202 ( & V_487 [ V_491 ] , V_601 , 0 ,
& V_491 , V_470 -> V_491 ) ;
V_98 = - V_300 ;
if ( V_491 >= V_470 -> V_491 )
goto V_303;
F_202 ( & V_487 [ V_491 ] , 0x80000000 , 0 , & V_491 , V_470 -> V_491 ) ;
V_600 = V_487 [ V_491 - 1 ] . V_493 ;
for ( V_601 = 0x80000001 ; V_601 <= V_600 && V_491 < V_470 -> V_491 ; ++ V_601 )
F_202 ( & V_487 [ V_491 ] , V_601 , 0 ,
& V_491 , V_470 -> V_491 ) ;
V_98 = - V_300 ;
if ( V_491 >= V_470 -> V_491 )
goto V_303;
if ( V_498 . V_602 == V_603 ) {
F_202 ( & V_487 [ V_491 ] , 0xC0000000 , 0 ,
& V_491 , V_470 -> V_491 ) ;
V_98 = - V_300 ;
if ( V_491 >= V_470 -> V_491 )
goto V_303;
V_600 = V_487 [ V_491 - 1 ] . V_493 ;
for ( V_601 = 0xC0000001 ;
V_601 <= V_600 && V_491 < V_470 -> V_491 ; ++ V_601 )
F_202 ( & V_487 [ V_491 ] , V_601 , 0 ,
& V_491 , V_470 -> V_491 ) ;
V_98 = - V_300 ;
if ( V_491 >= V_470 -> V_491 )
goto V_303;
}
F_202 ( & V_487 [ V_491 ] , V_586 , 0 , & V_491 ,
V_470 -> V_491 ) ;
V_98 = - V_300 ;
if ( V_491 >= V_470 -> V_491 )
goto V_303;
F_202 ( & V_487 [ V_491 ] , V_589 , 0 , & V_491 ,
V_470 -> V_491 ) ;
V_98 = - V_300 ;
if ( V_491 >= V_470 -> V_491 )
goto V_303;
V_98 = - V_80 ;
if ( F_175 ( V_400 , V_487 ,
V_491 * sizeof( struct V_125 ) ) )
goto V_303;
V_470 -> V_491 = V_491 ;
V_98 = 0 ;
V_303:
F_195 ( V_487 ) ;
V_92:
return V_98 ;
}
static int F_206 ( struct V_1 * V_2 ,
struct V_604 * V_605 )
{
memcpy ( V_605 -> V_606 , V_2 -> V_5 . V_607 -> V_606 , sizeof *V_605 ) ;
return 0 ;
}
static int F_207 ( struct V_1 * V_2 ,
struct V_604 * V_605 )
{
memcpy ( V_2 -> V_5 . V_607 -> V_606 , V_605 -> V_606 , sizeof *V_605 ) ;
F_208 ( V_2 ) ;
F_209 ( V_2 ) ;
return 0 ;
}
static int F_210 ( struct V_1 * V_2 ,
struct V_608 * V_609 )
{
if ( V_609 -> V_609 < 0 || V_609 -> V_609 >= 256 )
return - V_474 ;
if ( F_18 ( V_2 -> V_29 ) )
return - V_610 ;
F_211 ( V_2 , V_609 -> V_609 , false ) ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
static int F_212 ( struct V_1 * V_2 )
{
F_32 ( V_2 ) ;
return 0 ;
}
static int F_213 ( struct V_1 * V_2 ,
struct V_611 * V_612 )
{
if ( V_612 -> V_226 )
return - V_474 ;
V_2 -> V_5 . V_613 = ! ! V_612 -> V_272 ;
return 0 ;
}
static int F_214 ( struct V_1 * V_2 ,
T_2 V_280 )
{
int V_98 ;
unsigned V_281 = V_280 & 0xff , V_614 ;
V_98 = - V_474 ;
if ( ! V_281 || V_281 >= V_363 )
goto V_92;
if ( V_280 & ~ ( V_473 | 0xff | 0xff0000 ) )
goto V_92;
V_98 = 0 ;
V_2 -> V_5 . V_280 = V_280 ;
if ( V_280 & V_285 )
V_2 -> V_5 . V_286 = ~ ( T_2 ) 0 ;
for ( V_614 = 0 ; V_614 < V_281 ; V_614 ++ )
V_2 -> V_5 . V_288 [ V_614 * 4 ] = ~ ( T_2 ) 0 ;
V_92:
return V_98 ;
}
static int F_215 ( struct V_1 * V_2 ,
struct V_615 * V_616 )
{
T_2 V_280 = V_2 -> V_5 . V_280 ;
unsigned V_281 = V_280 & 0xff ;
T_2 * V_617 = V_2 -> V_5 . V_288 ;
if ( V_616 -> V_614 >= V_281 || ! ( V_616 -> V_618 & V_619 ) )
return - V_474 ;
if ( ( V_616 -> V_618 & V_620 ) && ( V_280 & V_285 ) &&
V_2 -> V_5 . V_286 != ~ ( T_2 ) 0 )
return 0 ;
V_617 += 4 * V_616 -> V_614 ;
if ( ( V_616 -> V_618 & V_620 ) && V_617 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_616 -> V_618 & V_620 ) {
if ( ( V_2 -> V_5 . V_283 & V_621 ) ||
! F_65 ( V_2 , V_622 ) ) {
F_23 ( V_54 , V_2 ) ;
return 0 ;
}
if ( V_617 [ 1 ] & V_619 )
V_616 -> V_618 |= V_623 ;
V_617 [ 2 ] = V_616 -> V_309 ;
V_617 [ 3 ] = V_616 -> V_624 ;
V_2 -> V_5 . V_283 = V_616 -> V_283 ;
V_617 [ 1 ] = V_616 -> V_618 ;
F_24 ( V_2 , V_625 ) ;
} else if ( ! ( V_617 [ 1 ] & V_619 )
|| ! ( V_617 [ 1 ] & V_620 ) ) {
if ( V_617 [ 1 ] & V_619 )
V_616 -> V_618 |= V_623 ;
V_617 [ 2 ] = V_616 -> V_309 ;
V_617 [ 3 ] = V_616 -> V_624 ;
V_617 [ 1 ] = V_616 -> V_618 ;
} else
V_617 [ 1 ] |= V_623 ;
return 0 ;
}
static void F_216 ( struct V_1 * V_2 ,
struct V_626 * V_627 )
{
V_627 -> V_49 . V_628 =
V_2 -> V_5 . V_49 . V_50 &&
! F_217 ( V_2 -> V_5 . V_49 . V_16 ) ;
V_627 -> V_49 . V_16 = V_2 -> V_5 . V_49 . V_16 ;
V_627 -> V_49 . V_52 = V_2 -> V_5 . V_49 . V_52 ;
V_627 -> V_49 . V_629 = 0 ;
V_627 -> V_49 . V_43 = V_2 -> V_5 . V_49 . V_43 ;
V_627 -> V_630 . V_628 =
V_2 -> V_5 . V_630 . V_50 && ! V_2 -> V_5 . V_630 . V_631 ;
V_627 -> V_630 . V_16 = V_2 -> V_5 . V_630 . V_16 ;
V_627 -> V_630 . V_631 = 0 ;
V_627 -> V_630 . V_632 =
V_56 -> V_633 ( V_2 ,
V_634 | V_635 ) ;
V_627 -> V_636 . V_628 = V_2 -> V_5 . V_637 ;
V_627 -> V_636 . V_50 = V_2 -> V_5 . V_68 ;
V_627 -> V_636 . V_638 = V_56 -> V_639 ( V_2 ) ;
V_627 -> V_636 . V_629 = 0 ;
V_627 -> V_640 = V_2 -> V_5 . V_640 ;
V_627 -> V_226 = ( V_641
| V_642
| V_643 ) ;
memset ( & V_627 -> V_644 , 0 , sizeof( V_627 -> V_644 ) ) ;
}
static int F_218 ( struct V_1 * V_2 ,
struct V_626 * V_627 )
{
if ( V_627 -> V_226 & ~ ( V_641
| V_642
| V_643 ) )
return - V_474 ;
V_2 -> V_5 . V_49 . V_50 = V_627 -> V_49 . V_628 ;
V_2 -> V_5 . V_49 . V_16 = V_627 -> V_49 . V_16 ;
V_2 -> V_5 . V_49 . V_52 = V_627 -> V_49 . V_52 ;
V_2 -> V_5 . V_49 . V_43 = V_627 -> V_49 . V_43 ;
V_2 -> V_5 . V_630 . V_50 = V_627 -> V_630 . V_628 ;
V_2 -> V_5 . V_630 . V_16 = V_627 -> V_630 . V_16 ;
V_2 -> V_5 . V_630 . V_631 = V_627 -> V_630 . V_631 ;
if ( V_627 -> V_226 & V_643 )
V_56 -> V_645 ( V_2 ,
V_627 -> V_630 . V_632 ) ;
V_2 -> V_5 . V_637 = V_627 -> V_636 . V_628 ;
if ( V_627 -> V_226 & V_641 )
V_2 -> V_5 . V_68 = V_627 -> V_636 . V_50 ;
V_56 -> V_646 ( V_2 , V_627 -> V_636 . V_638 ) ;
if ( V_627 -> V_226 & V_642 )
V_2 -> V_5 . V_640 = V_627 -> V_640 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
static void F_219 ( struct V_1 * V_2 ,
struct V_647 * V_648 )
{
memcpy ( V_648 -> V_155 , V_2 -> V_5 . V_155 , sizeof( V_2 -> V_5 . V_155 ) ) ;
V_648 -> V_160 = V_2 -> V_5 . V_160 ;
V_648 -> V_163 = V_2 -> V_5 . V_163 ;
V_648 -> V_226 = 0 ;
memset ( & V_648 -> V_644 , 0 , sizeof( V_648 -> V_644 ) ) ;
}
static int F_220 ( struct V_1 * V_2 ,
struct V_647 * V_648 )
{
if ( V_648 -> V_226 )
return - V_474 ;
memcpy ( V_2 -> V_5 . V_155 , V_648 -> V_155 , sizeof( V_2 -> V_5 . V_155 ) ) ;
V_2 -> V_5 . V_160 = V_648 -> V_160 ;
V_2 -> V_5 . V_163 = V_648 -> V_163 ;
return 0 ;
}
static void F_221 ( struct V_1 * V_2 ,
struct V_649 * V_650 )
{
if ( V_132 )
memcpy ( V_650 -> V_651 ,
& V_2 -> V_5 . V_652 . V_653 -> V_654 ,
V_655 ) ;
else {
memcpy ( V_650 -> V_651 ,
& V_2 -> V_5 . V_652 . V_653 -> V_656 ,
sizeof( struct V_657 ) ) ;
* ( T_2 * ) & V_650 -> V_651 [ V_658 / sizeof( T_1 ) ] =
V_659 ;
}
}
static int F_222 ( struct V_1 * V_2 ,
struct V_649 * V_650 )
{
T_2 V_660 =
* ( T_2 * ) & V_650 -> V_651 [ V_658 / sizeof( T_1 ) ] ;
if ( V_132 )
memcpy ( & V_2 -> V_5 . V_652 . V_653 -> V_654 ,
V_650 -> V_651 , V_655 ) ;
else {
if ( V_660 & ~ V_659 )
return - V_474 ;
memcpy ( & V_2 -> V_5 . V_652 . V_653 -> V_656 ,
V_650 -> V_651 , sizeof( struct V_657 ) ) ;
}
return 0 ;
}
static void F_223 ( struct V_1 * V_2 ,
struct V_661 * V_662 )
{
if ( ! V_132 ) {
V_662 -> V_663 = 0 ;
return;
}
V_662 -> V_663 = 1 ;
V_662 -> V_226 = 0 ;
V_662 -> V_664 [ 0 ] . V_117 = V_119 ;
V_662 -> V_664 [ 0 ] . V_23 = V_2 -> V_5 . V_118 ;
}
static int F_224 ( struct V_1 * V_2 ,
struct V_661 * V_662 )
{
int V_3 , V_98 = 0 ;
if ( ! V_132 )
return - V_474 ;
if ( V_662 -> V_663 > V_665 || V_662 -> V_226 )
return - V_474 ;
for ( V_3 = 0 ; V_3 < V_662 -> V_663 ; V_3 ++ )
if ( V_662 -> V_664 [ 0 ] . V_117 == V_119 ) {
V_98 = F_57 ( V_2 , V_119 ,
V_662 -> V_664 [ 0 ] . V_23 ) ;
break;
}
if ( V_98 )
V_98 = - V_474 ;
return V_98 ;
}
long F_225 ( struct V_454 * V_455 ,
unsigned int V_456 , unsigned long V_457 )
{
struct V_1 * V_2 = V_455 -> V_666 ;
void V_313 * V_458 = ( void V_313 * ) V_457 ;
int V_98 ;
union {
struct V_604 * V_667 ;
struct V_649 * V_654 ;
struct V_661 * V_664 ;
void * V_668 ;
} V_669 ;
V_669 . V_668 = NULL ;
switch ( V_456 ) {
case V_670 : {
V_98 = - V_474 ;
if ( ! V_2 -> V_5 . V_607 )
goto V_92;
V_669 . V_667 = F_129 ( sizeof( struct V_604 ) , V_302 ) ;
V_98 = - V_301 ;
if ( ! V_669 . V_667 )
goto V_92;
V_98 = F_206 ( V_2 , V_669 . V_667 ) ;
if ( V_98 )
goto V_92;
V_98 = - V_80 ;
if ( F_175 ( V_458 , V_669 . V_667 , sizeof( struct V_604 ) ) )
goto V_92;
V_98 = 0 ;
break;
}
case V_671 : {
V_98 = - V_474 ;
if ( ! V_2 -> V_5 . V_607 )
goto V_92;
V_669 . V_667 = F_174 ( sizeof( struct V_604 ) , V_302 ) ;
V_98 = - V_301 ;
if ( ! V_669 . V_667 )
goto V_92;
V_98 = - V_80 ;
if ( F_130 ( V_669 . V_667 , V_458 , sizeof( struct V_604 ) ) )
goto V_92;
V_98 = F_207 ( V_2 , V_669 . V_667 ) ;
if ( V_98 )
goto V_92;
V_98 = 0 ;
break;
}
case V_672 : {
struct V_608 V_609 ;
V_98 = - V_80 ;
if ( F_130 ( & V_609 , V_458 , sizeof V_609 ) )
goto V_92;
V_98 = F_210 ( V_2 , & V_609 ) ;
if ( V_98 )
goto V_92;
V_98 = 0 ;
break;
}
case V_673 : {
V_98 = F_212 ( V_2 ) ;
if ( V_98 )
goto V_92;
V_98 = 0 ;
break;
}
case V_674 : {
struct V_489 V_313 * V_469 = V_458 ;
struct V_489 V_470 ;
V_98 = - V_80 ;
if ( F_130 ( & V_470 , V_469 , sizeof V_470 ) )
goto V_92;
V_98 = F_192 ( V_2 , & V_470 , V_469 -> V_400 ) ;
if ( V_98 )
goto V_92;
break;
}
case V_675 : {
struct V_468 V_313 * V_469 = V_458 ;
struct V_468 V_470 ;
V_98 = - V_80 ;
if ( F_130 ( & V_470 , V_469 , sizeof V_470 ) )
goto V_92;
V_98 = F_196 ( V_2 , & V_470 ,
V_469 -> V_400 ) ;
if ( V_98 )
goto V_92;
break;
}
case V_676 : {
struct V_468 V_313 * V_469 = V_458 ;
struct V_468 V_470 ;
V_98 = - V_80 ;
if ( F_130 ( & V_470 , V_469 , sizeof V_470 ) )
goto V_92;
V_98 = F_197 ( V_2 , & V_470 ,
V_469 -> V_400 ) ;
if ( V_98 )
goto V_92;
V_98 = - V_80 ;
if ( F_175 ( V_469 , & V_470 , sizeof V_470 ) )
goto V_92;
V_98 = 0 ;
break;
}
case V_677 :
V_98 = F_173 ( V_2 , V_458 , F_117 , 1 ) ;
break;
case V_678 :
V_98 = F_173 ( V_2 , V_458 , F_84 , 0 ) ;
break;
case V_679 : {
struct V_611 V_612 ;
V_98 = - V_80 ;
if ( F_130 ( & V_612 , V_458 , sizeof V_612 ) )
goto V_92;
V_98 = F_213 ( V_2 , & V_612 ) ;
if ( V_98 )
goto V_92;
V_98 = - V_80 ;
if ( F_175 ( V_458 , & V_612 , sizeof V_612 ) )
goto V_92;
V_98 = 0 ;
break;
} ;
case V_680 : {
struct V_681 V_682 ;
V_98 = - V_474 ;
if ( ! F_18 ( V_2 -> V_29 ) )
goto V_92;
V_98 = - V_80 ;
if ( F_130 ( & V_682 , V_458 , sizeof V_682 ) )
goto V_92;
V_98 = 0 ;
F_226 ( V_2 , V_682 . V_683 ) ;
break;
}
case V_684 : {
T_2 V_280 ;
V_98 = - V_80 ;
if ( F_130 ( & V_280 , V_458 , sizeof V_280 ) )
goto V_92;
V_98 = F_214 ( V_2 , V_280 ) ;
break;
}
case V_685 : {
struct V_615 V_616 ;
V_98 = - V_80 ;
if ( F_130 ( & V_616 , V_458 , sizeof V_616 ) )
goto V_92;
V_98 = F_215 ( V_2 , & V_616 ) ;
break;
}
case V_686 : {
struct V_626 V_627 ;
F_216 ( V_2 , & V_627 ) ;
V_98 = - V_80 ;
if ( F_175 ( V_458 , & V_627 , sizeof( struct V_626 ) ) )
break;
V_98 = 0 ;
break;
}
case V_687 : {
struct V_626 V_627 ;
V_98 = - V_80 ;
if ( F_130 ( & V_627 , V_458 , sizeof( struct V_626 ) ) )
break;
V_98 = F_218 ( V_2 , & V_627 ) ;
break;
}
case V_688 : {
struct V_647 V_648 ;
F_219 ( V_2 , & V_648 ) ;
V_98 = - V_80 ;
if ( F_175 ( V_458 , & V_648 ,
sizeof( struct V_647 ) ) )
break;
V_98 = 0 ;
break;
}
case V_689 : {
struct V_647 V_648 ;
V_98 = - V_80 ;
if ( F_130 ( & V_648 , V_458 ,
sizeof( struct V_647 ) ) )
break;
V_98 = F_220 ( V_2 , & V_648 ) ;
break;
}
case V_690 : {
V_669 . V_654 = F_129 ( sizeof( struct V_649 ) , V_302 ) ;
V_98 = - V_301 ;
if ( ! V_669 . V_654 )
break;
F_221 ( V_2 , V_669 . V_654 ) ;
V_98 = - V_80 ;
if ( F_175 ( V_458 , V_669 . V_654 , sizeof( struct V_649 ) ) )
break;
V_98 = 0 ;
break;
}
case V_691 : {
V_669 . V_654 = F_129 ( sizeof( struct V_649 ) , V_302 ) ;
V_98 = - V_301 ;
if ( ! V_669 . V_654 )
break;
V_98 = - V_80 ;
if ( F_130 ( V_669 . V_654 , V_458 , sizeof( struct V_649 ) ) )
break;
V_98 = F_222 ( V_2 , V_669 . V_654 ) ;
break;
}
case V_692 : {
V_669 . V_664 = F_129 ( sizeof( struct V_661 ) , V_302 ) ;
V_98 = - V_301 ;
if ( ! V_669 . V_664 )
break;
F_223 ( V_2 , V_669 . V_664 ) ;
V_98 = - V_80 ;
if ( F_175 ( V_458 , V_669 . V_664 ,
sizeof( struct V_661 ) ) )
break;
V_98 = 0 ;
break;
}
case V_693 : {
V_669 . V_664 = F_129 ( sizeof( struct V_661 ) , V_302 ) ;
V_98 = - V_301 ;
if ( ! V_669 . V_664 )
break;
V_98 = - V_80 ;
if ( F_130 ( V_669 . V_664 , V_458 ,
sizeof( struct V_661 ) ) )
break;
V_98 = F_224 ( V_2 , V_669 . V_664 ) ;
break;
}
case V_694 : {
T_1 V_695 ;
V_98 = - V_474 ;
if ( ! V_453 )
break;
V_695 = ( T_1 ) V_457 ;
if ( V_695 >= V_696 )
goto V_92;
V_56 -> V_697 ( V_2 , V_695 ) ;
V_98 = 0 ;
goto V_92;
}
case V_698 : {
V_98 = - V_699 ;
if ( F_113 () )
goto V_92;
V_98 = F_103 ( V_2 ) ;
goto V_92;
}
default:
V_98 = - V_474 ;
}
V_92:
F_131 ( V_669 . V_668 ) ;
return V_98 ;
}
static int F_227 ( struct V_29 * V_29 , unsigned long V_309 )
{
int V_87 ;
if ( V_309 > ( unsigned int ) ( - 3 * V_86 ) )
return - 1 ;
V_87 = V_56 -> V_700 ( V_29 , V_309 ) ;
return V_87 ;
}
static int F_228 ( struct V_29 * V_29 ,
T_2 V_701 )
{
V_29 -> V_5 . V_702 = V_701 ;
return 0 ;
}
static int F_229 ( struct V_29 * V_29 ,
T_1 V_703 )
{
if ( V_703 < V_704 )
return - V_474 ;
F_159 ( & V_29 -> V_705 ) ;
F_230 ( & V_29 -> V_706 ) ;
F_231 ( V_29 , V_703 ) ;
V_29 -> V_5 . V_707 = V_703 ;
F_232 ( & V_29 -> V_706 ) ;
F_160 ( & V_29 -> V_705 ) ;
return 0 ;
}
static int F_233 ( struct V_29 * V_29 )
{
return V_29 -> V_5 . V_708 ;
}
static int F_234 ( struct V_29 * V_29 , struct V_709 * V_710 )
{
int V_98 ;
V_98 = 0 ;
switch ( V_710 -> V_711 ) {
case V_712 :
memcpy ( & V_710 -> V_710 . V_713 ,
& F_235 ( V_29 ) -> V_714 [ 0 ] ,
sizeof( struct V_715 ) ) ;
break;
case V_716 :
memcpy ( & V_710 -> V_710 . V_713 ,
& F_235 ( V_29 ) -> V_714 [ 1 ] ,
sizeof( struct V_715 ) ) ;
break;
case V_717 :
V_98 = F_236 ( V_29 , & V_710 -> V_710 . V_718 ) ;
break;
default:
V_98 = - V_474 ;
break;
}
return V_98 ;
}
static int F_237 ( struct V_29 * V_29 , struct V_709 * V_710 )
{
int V_98 ;
V_98 = 0 ;
switch ( V_710 -> V_711 ) {
case V_712 :
F_230 ( & F_235 ( V_29 ) -> V_378 ) ;
memcpy ( & F_235 ( V_29 ) -> V_714 [ 0 ] ,
& V_710 -> V_710 . V_713 ,
sizeof( struct V_715 ) ) ;
F_232 ( & F_235 ( V_29 ) -> V_378 ) ;
break;
case V_716 :
F_230 ( & F_235 ( V_29 ) -> V_378 ) ;
memcpy ( & F_235 ( V_29 ) -> V_714 [ 1 ] ,
& V_710 -> V_710 . V_713 ,
sizeof( struct V_715 ) ) ;
F_232 ( & F_235 ( V_29 ) -> V_378 ) ;
break;
case V_717 :
V_98 = F_238 ( V_29 , & V_710 -> V_710 . V_718 ) ;
break;
default:
V_98 = - V_474 ;
break;
}
F_239 ( F_235 ( V_29 ) ) ;
return V_98 ;
}
static int F_240 ( struct V_29 * V_29 , struct V_719 * V_720 )
{
int V_98 = 0 ;
F_159 ( & V_29 -> V_5 . V_721 -> V_722 . V_378 ) ;
memcpy ( V_720 , & V_29 -> V_5 . V_721 -> V_722 , sizeof( struct V_719 ) ) ;
F_160 ( & V_29 -> V_5 . V_721 -> V_722 . V_378 ) ;
return V_98 ;
}
static int F_241 ( struct V_29 * V_29 , struct V_719 * V_720 )
{
int V_98 = 0 ;
F_159 ( & V_29 -> V_5 . V_721 -> V_722 . V_378 ) ;
memcpy ( & V_29 -> V_5 . V_721 -> V_722 , V_720 , sizeof( struct V_719 ) ) ;
F_242 ( V_29 , 0 , V_720 -> V_723 [ 0 ] . V_724 , 0 ) ;
F_160 ( & V_29 -> V_5 . V_721 -> V_722 . V_378 ) ;
return V_98 ;
}
static int F_243 ( struct V_29 * V_29 , struct V_725 * V_720 )
{
int V_98 = 0 ;
F_159 ( & V_29 -> V_5 . V_721 -> V_722 . V_378 ) ;
memcpy ( V_720 -> V_723 , & V_29 -> V_5 . V_721 -> V_722 . V_723 ,
sizeof( V_720 -> V_723 ) ) ;
V_720 -> V_226 = V_29 -> V_5 . V_721 -> V_722 . V_226 ;
F_160 ( & V_29 -> V_5 . V_721 -> V_722 . V_378 ) ;
memset ( & V_720 -> V_644 , 0 , sizeof( V_720 -> V_644 ) ) ;
return V_98 ;
}
static int F_244 ( struct V_29 * V_29 , struct V_725 * V_720 )
{
int V_98 = 0 , V_726 = 0 ;
T_1 V_727 , V_728 ;
F_159 ( & V_29 -> V_5 . V_721 -> V_722 . V_378 ) ;
V_727 = V_29 -> V_5 . V_721 -> V_722 . V_226 & V_729 ;
V_728 = V_720 -> V_226 & V_729 ;
if ( ! V_727 && V_728 )
V_726 = 1 ;
memcpy ( & V_29 -> V_5 . V_721 -> V_722 . V_723 , & V_720 -> V_723 ,
sizeof( V_29 -> V_5 . V_721 -> V_722 . V_723 ) ) ;
V_29 -> V_5 . V_721 -> V_722 . V_226 = V_720 -> V_226 ;
F_242 ( V_29 , 0 , V_29 -> V_5 . V_721 -> V_722 . V_723 [ 0 ] . V_724 , V_726 ) ;
F_160 ( & V_29 -> V_5 . V_721 -> V_722 . V_378 ) ;
return V_98 ;
}
static int F_245 ( struct V_29 * V_29 ,
struct V_730 * V_731 )
{
if ( ! V_29 -> V_5 . V_721 )
return - V_610 ;
F_159 ( & V_29 -> V_5 . V_721 -> V_722 . V_378 ) ;
V_29 -> V_5 . V_721 -> V_722 . V_732 . V_44 = V_731 -> V_733 ;
F_160 ( & V_29 -> V_5 . V_721 -> V_722 . V_378 ) ;
return 0 ;
}
int F_246 ( struct V_29 * V_29 ,
struct V_734 * log )
{
int V_98 , V_3 ;
struct V_735 * V_736 ;
unsigned long V_405 ;
unsigned long V_737 = 0 ;
F_159 ( & V_29 -> V_705 ) ;
V_98 = - V_474 ;
if ( log -> V_10 >= V_447 )
goto V_92;
V_736 = & V_29 -> V_738 -> V_738 [ log -> V_10 ] ;
V_98 = - V_739 ;
if ( ! V_736 -> V_740 )
goto V_92;
V_405 = F_247 ( V_736 ) ;
for ( V_3 = 0 ; ! V_737 && V_3 < V_405 / sizeof( long ) ; V_3 ++ )
V_737 = V_736 -> V_740 [ V_3 ] ;
if ( V_737 ) {
struct V_741 * V_742 , * V_743 ;
unsigned long * V_740 ;
V_740 = V_736 -> V_744 ;
if ( V_736 -> V_740 == V_740 )
V_740 += V_405 / sizeof( long ) ;
memset ( V_740 , 0 , V_405 ) ;
V_98 = - V_301 ;
V_742 = F_129 ( sizeof( struct V_741 ) , V_302 ) ;
if ( ! V_742 )
goto V_92;
memcpy ( V_742 , V_29 -> V_738 , sizeof( struct V_741 ) ) ;
V_742 -> V_738 [ log -> V_10 ] . V_740 = V_740 ;
V_742 -> V_745 ++ ;
V_743 = V_29 -> V_738 ;
F_248 ( V_29 -> V_738 , V_742 ) ;
F_249 ( & V_29 -> V_401 ) ;
V_740 = V_743 -> V_738 [ log -> V_10 ] . V_740 ;
F_131 ( V_743 ) ;
F_230 ( & V_29 -> V_706 ) ;
F_250 ( V_29 , log -> V_10 ) ;
F_232 ( & V_29 -> V_706 ) ;
V_98 = - V_80 ;
if ( F_175 ( log -> V_740 , V_740 , V_405 ) )
goto V_92;
} else {
V_98 = - V_80 ;
if ( F_251 ( log -> V_740 , V_405 ) )
goto V_92;
}
V_98 = 0 ;
V_92:
F_160 ( & V_29 -> V_705 ) ;
return V_98 ;
}
long F_252 ( struct V_454 * V_455 ,
unsigned int V_456 , unsigned long V_457 )
{
struct V_29 * V_29 = V_455 -> V_666 ;
void V_313 * V_458 = ( void V_313 * ) V_457 ;
int V_98 = - V_746 ;
union {
struct V_719 V_720 ;
struct V_725 V_747 ;
struct V_748 V_749 ;
} V_669 ;
switch ( V_456 ) {
case V_750 :
V_98 = F_227 ( V_29 , V_457 ) ;
if ( V_98 < 0 )
goto V_92;
break;
case V_751 : {
T_2 V_701 ;
V_98 = - V_80 ;
if ( F_130 ( & V_701 , V_458 , sizeof V_701 ) )
goto V_92;
V_98 = F_228 ( V_29 , V_701 ) ;
if ( V_98 < 0 )
goto V_92;
break;
}
case V_752 :
V_98 = F_229 ( V_29 , V_457 ) ;
if ( V_98 )
goto V_92;
break;
case V_753 :
V_98 = F_233 ( V_29 ) ;
break;
case V_754 : {
struct V_755 * V_756 ;
F_159 ( & V_29 -> V_378 ) ;
V_98 = - V_757 ;
if ( V_29 -> V_5 . V_756 )
goto V_758;
V_98 = - V_301 ;
V_756 = F_253 ( V_29 ) ;
if ( V_756 ) {
V_98 = F_254 ( V_29 ) ;
if ( V_98 ) {
F_159 ( & V_29 -> V_705 ) ;
F_255 ( V_29 , V_759 ,
& V_756 -> V_760 ) ;
F_160 ( & V_29 -> V_705 ) ;
F_131 ( V_756 ) ;
goto V_758;
}
} else
goto V_758;
F_12 () ;
V_29 -> V_5 . V_756 = V_756 ;
F_12 () ;
V_98 = F_256 ( V_29 ) ;
if ( V_98 ) {
F_159 ( & V_29 -> V_705 ) ;
F_159 ( & V_29 -> V_761 ) ;
F_257 ( V_29 ) ;
F_258 ( V_29 ) ;
F_160 ( & V_29 -> V_761 ) ;
F_160 ( & V_29 -> V_705 ) ;
}
V_758:
F_160 ( & V_29 -> V_378 ) ;
break;
}
case V_762 :
V_669 . V_749 . V_226 = V_763 ;
goto V_764;
case V_765 :
V_98 = - V_80 ;
if ( F_130 ( & V_669 . V_749 , V_458 ,
sizeof( struct V_748 ) ) )
goto V_92;
V_764:
F_159 ( & V_29 -> V_705 ) ;
V_98 = - V_757 ;
if ( V_29 -> V_5 . V_721 )
goto V_766;
V_98 = - V_301 ;
V_29 -> V_5 . V_721 = F_259 ( V_29 , V_669 . V_749 . V_226 ) ;
if ( V_29 -> V_5 . V_721 )
V_98 = 0 ;
V_766:
F_160 ( & V_29 -> V_705 ) ;
break;
case V_767 :
case V_768 : {
struct V_769 V_770 ;
V_98 = - V_80 ;
if ( F_130 ( & V_770 , V_458 , sizeof V_770 ) )
goto V_92;
V_98 = - V_610 ;
if ( F_18 ( V_29 ) ) {
T_11 V_618 ;
V_618 = F_260 ( V_29 , V_771 ,
V_770 . V_609 , V_770 . V_772 ) ;
if ( V_456 == V_767 ) {
V_98 = - V_80 ;
V_770 . V_618 = V_618 ;
if ( F_175 ( V_458 , & V_770 ,
sizeof V_770 ) )
goto V_92;
}
V_98 = 0 ;
}
break;
}
case V_773 : {
struct V_709 * V_710 = F_174 ( sizeof( * V_710 ) , V_302 ) ;
V_98 = - V_301 ;
if ( ! V_710 )
goto V_92;
V_98 = - V_80 ;
if ( F_130 ( V_710 , V_458 , sizeof *V_710 ) )
goto V_774;
V_98 = - V_610 ;
if ( ! F_18 ( V_29 ) )
goto V_774;
V_98 = F_234 ( V_29 , V_710 ) ;
if ( V_98 )
goto V_774;
V_98 = - V_80 ;
if ( F_175 ( V_458 , V_710 , sizeof *V_710 ) )
goto V_774;
V_98 = 0 ;
V_774:
F_131 ( V_710 ) ;
if ( V_98 )
goto V_92;
break;
}
case V_775 : {
struct V_709 * V_710 = F_174 ( sizeof( * V_710 ) , V_302 ) ;
V_98 = - V_301 ;
if ( ! V_710 )
goto V_92;
V_98 = - V_80 ;
if ( F_130 ( V_710 , V_458 , sizeof *V_710 ) )
goto V_776;
V_98 = - V_610 ;
if ( ! F_18 ( V_29 ) )
goto V_776;
V_98 = F_237 ( V_29 , V_710 ) ;
if ( V_98 )
goto V_776;
V_98 = 0 ;
V_776:
F_131 ( V_710 ) ;
if ( V_98 )
goto V_92;
break;
}
case V_777 : {
V_98 = - V_80 ;
if ( F_130 ( & V_669 . V_720 , V_458 , sizeof( struct V_719 ) ) )
goto V_92;
V_98 = - V_610 ;
if ( ! V_29 -> V_5 . V_721 )
goto V_92;
V_98 = F_240 ( V_29 , & V_669 . V_720 ) ;
if ( V_98 )
goto V_92;
V_98 = - V_80 ;
if ( F_175 ( V_458 , & V_669 . V_720 , sizeof( struct V_719 ) ) )
goto V_92;
V_98 = 0 ;
break;
}
case V_778 : {
V_98 = - V_80 ;
if ( F_130 ( & V_669 . V_720 , V_458 , sizeof V_669 . V_720 ) )
goto V_92;
V_98 = - V_610 ;
if ( ! V_29 -> V_5 . V_721 )
goto V_92;
V_98 = F_241 ( V_29 , & V_669 . V_720 ) ;
if ( V_98 )
goto V_92;
V_98 = 0 ;
break;
}
case V_779 : {
V_98 = - V_610 ;
if ( ! V_29 -> V_5 . V_721 )
goto V_92;
V_98 = F_243 ( V_29 , & V_669 . V_747 ) ;
if ( V_98 )
goto V_92;
V_98 = - V_80 ;
if ( F_175 ( V_458 , & V_669 . V_747 , sizeof( V_669 . V_747 ) ) )
goto V_92;
V_98 = 0 ;
break;
}
case V_780 : {
V_98 = - V_80 ;
if ( F_130 ( & V_669 . V_747 , V_458 , sizeof( V_669 . V_747 ) ) )
goto V_92;
V_98 = - V_610 ;
if ( ! V_29 -> V_5 . V_721 )
goto V_92;
V_98 = F_244 ( V_29 , & V_669 . V_747 ) ;
if ( V_98 )
goto V_92;
V_98 = 0 ;
break;
}
case V_781 : {
struct V_730 V_731 ;
V_98 = - V_80 ;
if ( F_130 ( & V_731 , V_458 , sizeof( V_731 ) ) )
goto V_92;
V_98 = F_245 ( V_29 , & V_731 ) ;
if ( V_98 )
goto V_92;
V_98 = 0 ;
break;
}
case V_782 : {
V_98 = - V_80 ;
if ( F_130 ( & V_29 -> V_5 . F_128 , V_458 ,
sizeof( struct V_783 ) ) )
goto V_92;
V_98 = - V_474 ;
if ( V_29 -> V_5 . F_128 . V_226 )
goto V_92;
V_98 = 0 ;
break;
}
case V_784 : {
struct V_785 V_786 ;
T_2 V_787 ;
T_9 V_231 ;
V_98 = - V_80 ;
if ( F_130 ( & V_786 , V_458 , sizeof( V_786 ) ) )
goto V_92;
V_98 = - V_474 ;
if ( V_786 . V_226 )
goto V_92;
V_98 = 0 ;
F_261 () ;
V_787 = F_92 () ;
V_231 = V_786 . clock - V_787 ;
F_262 () ;
V_29 -> V_5 . V_250 = V_231 ;
break;
}
case V_788 : {
struct V_785 V_786 ;
T_2 V_787 ;
F_261 () ;
V_787 = F_92 () ;
V_786 . clock = V_29 -> V_5 . V_250 + V_787 ;
F_262 () ;
V_786 . V_226 = 0 ;
memset ( & V_786 . V_629 , 0 , sizeof( V_786 . V_629 ) ) ;
V_98 = - V_80 ;
if ( F_175 ( V_458 , & V_786 , sizeof( V_786 ) ) )
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
static void F_263 ( void )
{
T_1 V_789 [ 2 ] ;
unsigned V_3 , V_790 ;
for ( V_3 = V_790 = V_791 ; V_3 < F_41 ( V_466 ) ; V_3 ++ ) {
if ( F_264 ( V_466 [ V_3 ] , & V_789 [ 0 ] , & V_789 [ 1 ] ) < 0 )
continue;
if ( V_790 < V_3 )
V_466 [ V_790 ] = V_466 [ V_3 ] ;
V_790 ++ ;
}
V_463 = V_790 ;
}
static int F_265 ( struct V_1 * V_2 , T_4 V_309 , int V_74 ,
const void * V_235 )
{
int V_792 = 0 ;
int V_405 ;
do {
V_405 = F_204 ( V_74 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_607 &&
! F_266 ( & V_2 -> V_5 . V_607 -> V_760 , V_309 , V_405 , V_235 ) )
&& F_267 ( V_2 -> V_29 , V_793 , V_309 , V_405 , V_235 ) )
break;
V_792 += V_405 ;
V_309 += V_405 ;
V_74 -= V_405 ;
V_235 += V_405 ;
} while ( V_74 );
return V_792 ;
}
static int F_268 ( struct V_1 * V_2 , T_4 V_309 , int V_74 , void * V_235 )
{
int V_792 = 0 ;
int V_405 ;
do {
V_405 = F_204 ( V_74 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_607 &&
! F_269 ( & V_2 -> V_5 . V_607 -> V_760 , V_309 , V_405 , V_235 ) )
&& F_270 ( V_2 -> V_29 , V_793 , V_309 , V_405 , V_235 ) )
break;
F_271 ( V_794 , V_405 , V_309 , * ( T_2 * ) V_235 ) ;
V_792 += V_405 ;
V_309 += V_405 ;
V_74 -= V_405 ;
V_235 += V_405 ;
} while ( V_74 );
return V_792 ;
}
static void F_272 ( struct V_1 * V_2 ,
struct V_795 * V_796 , int V_797 )
{
V_56 -> V_798 ( V_2 , V_796 , V_797 ) ;
}
void F_273 ( struct V_1 * V_2 ,
struct V_795 * V_796 , int V_797 )
{
V_56 -> V_799 ( V_2 , V_796 , V_797 ) ;
}
static T_4 V_78 ( struct V_1 * V_2 , T_4 V_324 , T_1 V_75 )
{
return V_324 ;
}
static T_4 F_274 ( struct V_1 * V_2 , T_4 V_324 , T_1 V_75 )
{
T_4 V_800 ;
struct V_58 V_49 ;
F_275 ( ! F_31 ( V_2 ) ) ;
V_75 |= V_90 ;
V_800 = V_2 -> V_5 . V_67 . V_801 ( V_2 , V_324 , V_75 , & V_49 ) ;
return V_800 ;
}
T_4 F_276 ( struct V_1 * V_2 , T_12 V_802 ,
struct V_58 * V_49 )
{
T_1 V_75 = ( V_56 -> V_70 ( V_2 ) == 3 ) ? V_90 : 0 ;
return V_2 -> V_5 . V_82 -> V_801 ( V_2 , V_802 , V_75 , V_49 ) ;
}
T_4 F_277 ( struct V_1 * V_2 , T_12 V_802 ,
struct V_58 * V_49 )
{
T_1 V_75 = ( V_56 -> V_70 ( V_2 ) == 3 ) ? V_90 : 0 ;
V_75 |= V_803 ;
return V_2 -> V_5 . V_82 -> V_801 ( V_2 , V_802 , V_75 , V_49 ) ;
}
T_4 F_278 ( struct V_1 * V_2 , T_12 V_802 ,
struct V_58 * V_49 )
{
T_1 V_75 = ( V_56 -> V_70 ( V_2 ) == 3 ) ? V_90 : 0 ;
V_75 |= V_91 ;
return V_2 -> V_5 . V_82 -> V_801 ( V_2 , V_802 , V_75 , V_49 ) ;
}
T_4 F_279 ( struct V_1 * V_2 , T_12 V_802 ,
struct V_58 * V_49 )
{
return V_2 -> V_5 . V_82 -> V_801 ( V_2 , V_802 , 0 , V_49 ) ;
}
static int F_280 ( T_12 V_309 , void * V_154 , unsigned int V_804 ,
struct V_1 * V_2 , T_1 V_75 ,
struct V_58 * V_49 )
{
void * V_31 = V_154 ;
int V_98 = V_805 ;
while ( V_804 ) {
T_4 V_324 = V_2 -> V_5 . V_82 -> V_801 ( V_2 , V_309 , V_75 ,
V_49 ) ;
unsigned V_73 = V_309 & ( V_86 - 1 ) ;
unsigned V_806 = F_204 ( V_804 , ( unsigned ) V_86 - V_73 ) ;
int V_87 ;
if ( V_324 == V_79 )
return V_807 ;
V_87 = F_86 ( V_2 -> V_29 , V_324 , V_31 , V_806 ) ;
if ( V_87 < 0 ) {
V_98 = V_808 ;
goto V_92;
}
V_804 -= V_806 ;
V_31 += V_806 ;
V_309 += V_806 ;
}
V_92:
return V_98 ;
}
static int F_281 ( struct V_809 * V_810 ,
T_12 V_309 , void * V_154 , unsigned int V_804 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_282 ( V_810 ) ;
T_1 V_75 = ( V_56 -> V_70 ( V_2 ) == 3 ) ? V_90 : 0 ;
return F_280 ( V_309 , V_154 , V_804 , V_2 ,
V_75 | V_803 ,
V_49 ) ;
}
int F_283 ( struct V_809 * V_810 ,
T_12 V_309 , void * V_154 , unsigned int V_804 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_282 ( V_810 ) ;
T_1 V_75 = ( V_56 -> V_70 ( V_2 ) == 3 ) ? V_90 : 0 ;
return F_280 ( V_309 , V_154 , V_804 , V_2 , V_75 ,
V_49 ) ;
}
static int F_284 ( struct V_809 * V_810 ,
T_12 V_309 , void * V_154 , unsigned int V_804 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_282 ( V_810 ) ;
return F_280 ( V_309 , V_154 , V_804 , V_2 , 0 , V_49 ) ;
}
int F_285 ( struct V_809 * V_810 ,
T_12 V_309 , void * V_154 ,
unsigned int V_804 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_282 ( V_810 ) ;
void * V_31 = V_154 ;
int V_98 = V_805 ;
while ( V_804 ) {
T_4 V_324 = V_2 -> V_5 . V_82 -> V_801 ( V_2 , V_309 ,
V_91 ,
V_49 ) ;
unsigned V_73 = V_309 & ( V_86 - 1 ) ;
unsigned V_811 = F_204 ( V_804 , ( unsigned ) V_86 - V_73 ) ;
int V_87 ;
if ( V_324 == V_79 )
return V_807 ;
V_87 = F_87 ( V_2 -> V_29 , V_324 , V_31 , V_811 ) ;
if ( V_87 < 0 ) {
V_98 = V_808 ;
goto V_92;
}
V_804 -= V_811 ;
V_31 += V_811 ;
V_309 += V_811 ;
}
V_92:
return V_98 ;
}
static int F_286 ( struct V_1 * V_2 , unsigned long V_802 ,
T_4 * V_324 , struct V_58 * V_49 ,
bool V_812 )
{
T_1 V_75 = ( V_56 -> V_70 ( V_2 ) == 3 ) ? V_90 : 0 ;
if ( F_287 ( V_2 , V_802 ) &&
F_288 ( V_2 , V_812 , V_75 ,
V_2 -> V_5 . V_75 ) ) {
* V_324 = V_2 -> V_5 . V_813 << V_85 |
( V_802 & ( V_86 - 1 ) ) ;
F_289 ( V_802 , * V_324 , V_812 , false ) ;
return 1 ;
}
if ( V_812 )
V_75 |= V_91 ;
* V_324 = V_2 -> V_5 . V_82 -> V_801 ( V_2 , V_802 , V_75 , V_49 ) ;
if ( * V_324 == V_79 )
return - 1 ;
if ( ( * V_324 & V_297 ) == V_814 )
return 1 ;
if ( F_290 ( V_2 , * V_324 ) ) {
F_289 ( V_802 , * V_324 , V_812 , true ) ;
return 1 ;
}
return 0 ;
}
static int F_291 ( struct V_809 * V_810 ,
unsigned long V_309 ,
void * V_154 ,
unsigned int V_804 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_282 ( V_810 ) ;
T_4 V_324 ;
int V_792 , V_87 ;
if ( V_2 -> V_815 ) {
memcpy ( V_154 , V_2 -> V_816 , V_804 ) ;
F_271 ( V_794 , V_804 ,
V_2 -> V_817 , * ( T_2 * ) V_154 ) ;
V_2 -> V_815 = 0 ;
return V_805 ;
}
V_87 = F_286 ( V_2 , V_309 , & V_324 , V_49 , false ) ;
if ( V_87 < 0 )
return V_807 ;
if ( V_87 )
goto V_818;
if ( F_283 ( V_810 , V_309 , V_154 , V_804 , V_49 )
== V_805 )
return V_805 ;
V_818:
V_792 = F_268 ( V_2 , V_324 , V_804 , V_154 ) ;
if ( V_792 == V_804 )
return V_805 ;
V_324 += V_792 ;
V_804 -= V_792 ;
V_154 += V_792 ;
F_271 ( V_819 , V_804 , V_324 , 0 ) ;
V_2 -> V_820 = 1 ;
V_2 -> V_821 -> V_822 = V_823 ;
V_2 -> V_821 -> V_818 . V_824 = V_2 -> V_817 = V_324 ;
V_2 -> V_825 = V_804 ;
V_2 -> V_821 -> V_818 . V_74 = F_204 ( V_2 -> V_825 , 8 ) ;
V_2 -> V_821 -> V_818 . V_826 = V_2 -> V_827 = 0 ;
V_2 -> V_828 = 0 ;
return V_808 ;
}
int F_292 ( struct V_1 * V_2 , T_4 V_324 ,
const void * V_154 , int V_804 )
{
int V_87 ;
V_87 = F_87 ( V_2 -> V_29 , V_324 , V_154 , V_804 ) ;
if ( V_87 < 0 )
return 0 ;
F_293 ( V_2 , V_324 , V_154 , V_804 , 1 ) ;
return 1 ;
}
static int F_294 ( unsigned long V_309 ,
const void * V_154 ,
unsigned int V_804 ,
struct V_58 * V_49 ,
struct V_1 * V_2 )
{
T_4 V_324 ;
int V_792 , V_87 ;
V_87 = F_286 ( V_2 , V_309 , & V_324 , V_49 , true ) ;
if ( V_87 < 0 )
return V_807 ;
if ( V_87 )
goto V_818;
if ( F_292 ( V_2 , V_324 , V_154 , V_804 ) )
return V_805 ;
V_818:
F_271 ( V_829 , V_804 , V_324 , * ( T_2 * ) V_154 ) ;
V_792 = F_265 ( V_2 , V_324 , V_804 , V_154 ) ;
if ( V_792 == V_804 )
return V_805 ;
V_324 += V_792 ;
V_804 -= V_792 ;
V_154 += V_792 ;
V_2 -> V_820 = 1 ;
memcpy ( V_2 -> V_816 , V_154 , V_804 ) ;
V_2 -> V_821 -> V_822 = V_823 ;
V_2 -> V_821 -> V_818 . V_824 = V_2 -> V_817 = V_324 ;
V_2 -> V_825 = V_804 ;
V_2 -> V_821 -> V_818 . V_74 = F_204 ( V_2 -> V_825 , 8 ) ;
V_2 -> V_821 -> V_818 . V_826 = V_2 -> V_827 = 1 ;
memcpy ( V_2 -> V_821 -> V_818 . V_31 , V_2 -> V_816 , 8 ) ;
V_2 -> V_828 = 0 ;
return V_805 ;
}
int F_295 ( struct V_809 * V_810 ,
unsigned long V_309 ,
const void * V_154 ,
unsigned int V_804 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_282 ( V_810 ) ;
if ( ( ( V_309 + V_804 - 1 ) ^ V_309 ) & V_297 ) {
int V_830 , V_831 ;
V_831 = - V_309 & ~ V_297 ;
V_830 = F_294 ( V_309 , V_154 , V_831 , V_49 ,
V_2 ) ;
if ( V_830 != V_805 )
return V_830 ;
V_309 += V_831 ;
V_154 += V_831 ;
V_804 -= V_831 ;
}
return F_294 ( V_309 , V_154 , V_804 , V_49 ,
V_2 ) ;
}
static int F_296 ( struct V_809 * V_810 ,
unsigned long V_309 ,
const void * V_832 ,
const void * V_833 ,
unsigned int V_804 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_282 ( V_810 ) ;
T_4 V_324 ;
struct V_299 * V_299 ;
char * V_834 ;
bool V_835 ;
if ( V_804 > 8 || ( V_804 & ( V_804 - 1 ) ) )
goto V_836;
V_324 = F_278 ( V_2 , V_309 , NULL ) ;
if ( V_324 == V_79 ||
( V_324 & V_297 ) == V_814 )
goto V_836;
if ( ( ( V_324 + V_804 - 1 ) & V_297 ) != ( V_324 & V_297 ) )
goto V_836;
V_299 = F_153 ( V_2 -> V_29 , V_324 >> V_85 ) ;
if ( F_154 ( V_299 ) ) {
F_155 ( V_299 ) ;
goto V_836;
}
V_834 = F_119 ( V_299 , V_251 ) ;
V_834 += F_297 ( V_324 ) ;
switch ( V_804 ) {
case 1 :
V_835 = F_298 ( T_10 , V_834 , V_832 , V_833 ) ;
break;
case 2 :
V_835 = F_298 ( V_837 , V_834 , V_832 , V_833 ) ;
break;
case 4 :
V_835 = F_298 ( T_1 , V_834 , V_832 , V_833 ) ;
break;
case 8 :
V_835 = F_299 ( V_834 , V_832 , V_833 ) ;
break;
default:
F_300 () ;
}
F_120 ( V_834 , V_251 ) ;
F_146 ( V_299 ) ;
if ( ! V_835 )
return V_838 ;
F_293 ( V_2 , V_324 , V_833 , V_804 , 1 ) ;
return V_805 ;
V_836:
F_106 ( V_214 L_22 ) ;
return F_295 ( V_810 , V_309 , V_833 , V_804 , V_49 ) ;
}
static int F_301 ( struct V_1 * V_2 , void * V_839 )
{
int V_98 ;
if ( V_2 -> V_5 . V_840 . V_841 )
V_98 = F_270 ( V_2 -> V_29 , V_759 , V_2 -> V_5 . V_840 . V_842 ,
V_2 -> V_5 . V_840 . V_406 , V_839 ) ;
else
V_98 = F_267 ( V_2 -> V_29 , V_759 ,
V_2 -> V_5 . V_840 . V_842 , V_2 -> V_5 . V_840 . V_406 ,
V_839 ) ;
return V_98 ;
}
static int F_302 ( struct V_809 * V_810 ,
int V_406 , unsigned short V_842 , void * V_154 ,
unsigned int V_724 )
{
struct V_1 * V_2 = F_282 ( V_810 ) ;
if ( V_2 -> V_5 . V_840 . V_724 )
goto V_843;
F_303 ( 0 , V_842 , V_406 , V_724 ) ;
V_2 -> V_5 . V_840 . V_842 = V_842 ;
V_2 -> V_5 . V_840 . V_841 = 1 ;
V_2 -> V_5 . V_840 . V_724 = V_724 ;
V_2 -> V_5 . V_840 . V_406 = V_406 ;
if ( ! F_301 ( V_2 , V_2 -> V_5 . V_844 ) ) {
V_843:
memcpy ( V_154 , V_2 -> V_5 . V_844 , V_406 * V_724 ) ;
V_2 -> V_5 . V_840 . V_724 = 0 ;
return 1 ;
}
V_2 -> V_821 -> V_822 = V_845 ;
V_2 -> V_821 -> V_846 . V_847 = V_848 ;
V_2 -> V_821 -> V_846 . V_406 = V_406 ;
V_2 -> V_821 -> V_846 . V_849 = V_850 * V_86 ;
V_2 -> V_821 -> V_846 . V_724 = V_724 ;
V_2 -> V_821 -> V_846 . V_842 = V_842 ;
return 0 ;
}
static int F_304 ( struct V_809 * V_810 ,
int V_406 , unsigned short V_842 ,
const void * V_154 , unsigned int V_724 )
{
struct V_1 * V_2 = F_282 ( V_810 ) ;
F_303 ( 1 , V_842 , V_406 , V_724 ) ;
V_2 -> V_5 . V_840 . V_842 = V_842 ;
V_2 -> V_5 . V_840 . V_841 = 0 ;
V_2 -> V_5 . V_840 . V_724 = V_724 ;
V_2 -> V_5 . V_840 . V_406 = V_406 ;
memcpy ( V_2 -> V_5 . V_844 , V_154 , V_406 * V_724 ) ;
if ( ! F_301 ( V_2 , V_2 -> V_5 . V_844 ) ) {
V_2 -> V_5 . V_840 . V_724 = 0 ;
return 1 ;
}
V_2 -> V_821 -> V_822 = V_845 ;
V_2 -> V_821 -> V_846 . V_847 = V_851 ;
V_2 -> V_821 -> V_846 . V_406 = V_406 ;
V_2 -> V_821 -> V_846 . V_849 = V_850 * V_86 ;
V_2 -> V_821 -> V_846 . V_724 = V_724 ;
V_2 -> V_821 -> V_846 . V_842 = V_842 ;
return 0 ;
}
static unsigned long F_305 ( struct V_1 * V_2 , int V_797 )
{
return V_56 -> F_305 ( V_2 , V_797 ) ;
}
static void F_306 ( struct V_809 * V_810 , V_149 V_63 )
{
F_307 ( F_282 ( V_810 ) , V_63 ) ;
}
int F_308 ( struct V_1 * V_2 )
{
if ( ! F_182 ( V_2 ) )
return V_805 ;
if ( V_56 -> V_479 () ) {
int V_210 = F_99 () ;
F_184 ( V_210 , V_2 -> V_5 . V_480 ) ;
F_309 ( V_2 -> V_5 . V_480 ,
F_180 , NULL , 1 ) ;
F_102 () ;
F_310 ( V_2 -> V_5 . V_480 ) ;
} else
F_181 () ;
return V_805 ;
}
static void F_311 ( struct V_809 * V_810 )
{
F_308 ( F_282 ( V_810 ) ) ;
}
int F_312 ( struct V_809 * V_810 , int V_153 , unsigned long * V_852 )
{
return F_79 ( F_282 ( V_810 ) , V_153 , V_852 ) ;
}
int F_313 ( struct V_809 * V_810 , int V_153 , unsigned long V_23 )
{
return F_77 ( F_282 ( V_810 ) , V_153 , V_23 ) ;
}
static T_2 F_314 ( T_2 V_853 , T_1 V_854 )
{
return ( V_853 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_854 ;
}
static unsigned long F_315 ( struct V_809 * V_810 , int V_855 )
{
struct V_1 * V_2 = F_282 ( V_810 ) ;
unsigned long V_23 ;
switch ( V_855 ) {
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
V_23 = F_67 ( V_2 ) ;
break;
case 8 :
V_23 = F_75 ( V_2 ) ;
break;
default:
F_316 ( V_2 , L_23 , V_208 , V_855 ) ;
return 0 ;
}
return V_23 ;
}
static int F_317 ( struct V_809 * V_810 , int V_855 , V_149 V_154 )
{
struct V_1 * V_2 = F_282 ( V_810 ) ;
int V_169 = 0 ;
switch ( V_855 ) {
case 0 :
V_169 = F_49 ( V_2 , F_314 ( F_50 ( V_2 ) , V_154 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_62 = V_154 ;
break;
case 3 :
V_169 = F_68 ( V_2 , V_154 ) ;
break;
case 4 :
V_169 = F_66 ( V_2 , F_314 ( F_67 ( V_2 ) , V_154 ) ) ;
break;
case 8 :
V_169 = F_73 ( V_2 , V_154 ) ;
break;
default:
F_316 ( V_2 , L_23 , V_208 , V_855 ) ;
V_169 = - 1 ;
}
return V_169 ;
}
static int F_318 ( struct V_809 * V_810 )
{
return V_56 -> V_70 ( F_282 ( V_810 ) ) ;
}
static void F_319 ( struct V_809 * V_810 , struct V_856 * V_857 )
{
V_56 -> V_858 ( F_282 ( V_810 ) , V_857 ) ;
}
static void F_320 ( struct V_809 * V_810 , struct V_856 * V_857 )
{
V_56 -> V_859 ( F_282 ( V_810 ) , V_857 ) ;
}
static void F_321 ( struct V_809 * V_810 , struct V_856 * V_857 )
{
V_56 -> V_860 ( F_282 ( V_810 ) , V_857 ) ;
}
static void F_322 ( struct V_809 * V_810 , struct V_856 * V_857 )
{
V_56 -> V_861 ( F_282 ( V_810 ) , V_857 ) ;
}
static unsigned long F_323 (
struct V_809 * V_810 , int V_797 )
{
return F_305 ( F_282 ( V_810 ) , V_797 ) ;
}
static bool F_324 ( struct V_809 * V_810 , V_837 * V_862 ,
struct V_863 * V_864 , T_1 * V_865 ,
int V_797 )
{
struct V_795 V_796 ;
F_273 ( F_282 ( V_810 ) , & V_796 , V_797 ) ;
* V_862 = V_796 . V_862 ;
if ( V_796 . V_866 )
return false ;
if ( V_796 . V_867 )
V_796 . V_600 >>= 12 ;
F_325 ( V_864 , V_796 . V_600 ) ;
F_326 ( V_864 , ( unsigned long ) V_796 . V_868 ) ;
#ifdef F_51
if ( V_865 )
* V_865 = V_796 . V_868 >> 32 ;
#endif
V_864 -> type = V_796 . type ;
V_864 -> V_605 = V_796 . V_605 ;
V_864 -> V_869 = V_796 . V_869 ;
V_864 -> V_268 = V_796 . V_870 ;
V_864 -> V_871 = V_796 . V_871 ;
V_864 -> V_872 = V_796 . V_872 ;
V_864 -> V_873 = V_796 . V_155 ;
V_864 -> V_867 = V_796 . V_867 ;
return true ;
}
static void F_327 ( struct V_809 * V_810 , V_837 V_862 ,
struct V_863 * V_864 , T_1 V_865 ,
int V_797 )
{
struct V_1 * V_2 = F_282 ( V_810 ) ;
struct V_795 V_796 ;
V_796 . V_862 = V_862 ;
V_796 . V_868 = F_328 ( V_864 ) ;
#ifdef F_51
V_796 . V_868 |= ( ( T_2 ) V_865 ) << 32 ;
#endif
V_796 . V_600 = F_329 ( V_864 ) ;
if ( V_864 -> V_867 )
V_796 . V_600 = ( V_796 . V_600 << 12 ) | 0xfff ;
V_796 . type = V_864 -> type ;
V_796 . V_870 = V_864 -> V_268 ;
V_796 . V_869 = V_864 -> V_869 ;
V_796 . V_155 = V_864 -> V_873 ;
V_796 . V_605 = V_864 -> V_605 ;
V_796 . V_872 = V_864 -> V_872 ;
V_796 . V_867 = V_864 -> V_867 ;
V_796 . V_871 = V_864 -> V_871 ;
V_796 . V_870 = V_864 -> V_268 ;
V_796 . V_866 = ! V_796 . V_870 ;
V_796 . V_494 = 0 ;
F_272 ( V_2 , & V_796 , V_797 ) ;
return;
}
static int F_330 ( struct V_809 * V_810 ,
T_1 V_184 , T_2 * V_381 )
{
return F_117 ( F_282 ( V_810 ) , V_184 , V_381 ) ;
}
static int F_331 ( struct V_809 * V_810 ,
T_1 V_184 , T_2 V_31 )
{
return F_83 ( F_282 ( V_810 ) , V_184 , V_31 ) ;
}
static void F_332 ( struct V_809 * V_810 )
{
F_282 ( V_810 ) -> V_5 . V_874 = 1 ;
}
static void F_333 ( struct V_809 * V_810 )
{
F_157 () ;
F_334 ( F_282 ( V_810 ) ) ;
F_335 () ;
}
static void F_336 ( struct V_809 * V_810 )
{
F_158 () ;
}
static int F_337 ( struct V_809 * V_810 ,
struct V_875 * V_876 ,
enum V_877 V_878 )
{
return V_56 -> V_879 ( F_282 ( V_810 ) , V_876 , V_878 ) ;
}
static void F_338 ( struct V_1 * V_2 )
{
F_339 ( V_2 , V_880 ) ;
F_339 ( V_2 , V_881 ) ;
F_339 ( V_2 , V_882 ) ;
V_2 -> V_5 . V_96 = ~ 0 ;
}
static void F_340 ( struct V_1 * V_2 , T_1 V_26 )
{
T_1 V_883 = V_56 -> V_633 ( V_2 , V_26 ) ;
if ( ! ( V_883 & V_26 ) )
V_56 -> V_645 ( V_2 , V_26 ) ;
}
static void F_341 ( struct V_1 * V_2 )
{
struct V_809 * V_810 = & V_2 -> V_5 . V_884 ;
if ( V_810 -> V_49 . V_32 == V_33 )
F_30 ( V_2 , & V_810 -> V_49 ) ;
else if ( V_810 -> V_49 . V_885 )
F_29 ( V_2 , V_810 -> V_49 . V_32 ,
V_810 -> V_49 . V_43 ) ;
else
F_24 ( V_2 , V_810 -> V_49 . V_32 ) ;
}
static void F_342 ( struct V_809 * V_810 ,
const unsigned long * V_606 )
{
memset ( & V_810 -> V_886 , 0 ,
( void * ) & V_810 -> V_606 - ( void * ) & V_810 -> V_886 ) ;
memcpy ( V_810 -> V_606 , V_606 , sizeof( V_810 -> V_606 ) ) ;
V_810 -> V_887 . V_726 = 0 ;
V_810 -> V_887 . V_888 = 0 ;
V_810 -> V_889 . V_890 = 0 ;
V_810 -> V_889 . V_888 = 0 ;
V_810 -> V_891 . V_890 = 0 ;
V_810 -> V_891 . V_888 = 0 ;
}
static void F_343 ( struct V_1 * V_2 )
{
struct V_809 * V_810 = & V_2 -> V_5 . V_884 ;
int V_111 , V_112 ;
F_338 ( V_2 ) ;
V_56 -> V_113 ( V_2 , & V_111 , & V_112 ) ;
V_810 -> V_892 = F_344 ( V_2 ) ;
V_810 -> V_893 = F_345 ( V_2 ) ;
V_810 -> V_894 = ( ! F_346 ( V_2 ) ) ? V_895 :
( V_810 -> V_892 & V_896 ) ? V_897 :
V_112 ? V_898 :
V_111 ? V_899 :
V_900 ;
V_810 -> V_901 = F_347 ( V_2 ) ;
F_342 ( V_810 , V_2 -> V_5 . V_606 ) ;
V_2 -> V_5 . V_902 = false ;
}
int F_348 ( struct V_1 * V_2 , int V_609 , int V_903 )
{
struct V_809 * V_810 = & V_2 -> V_5 . V_884 ;
int V_87 ;
F_343 ( V_2 ) ;
V_810 -> V_904 = 2 ;
V_810 -> V_905 = 2 ;
V_810 -> V_906 = V_810 -> V_893 + V_903 ;
V_87 = F_349 ( V_810 , V_609 ) ;
if ( V_87 != V_805 )
return V_907 ;
V_810 -> V_893 = V_810 -> V_906 ;
memcpy ( V_2 -> V_5 . V_606 , V_810 -> V_606 , sizeof V_810 -> V_606 ) ;
F_350 ( V_2 , V_810 -> V_893 ) ;
F_351 ( V_2 , V_810 -> V_892 ) ;
if ( V_609 == V_908 )
V_2 -> V_5 . V_68 = false ;
else
V_2 -> V_5 . V_630 . V_50 = false ;
return V_909 ;
}
static int F_352 ( struct V_1 * V_2 )
{
int V_98 = V_909 ;
++ V_2 -> V_60 . V_910 ;
F_353 ( V_2 ) ;
if ( ! F_347 ( V_2 ) ) {
V_2 -> V_821 -> V_822 = V_911 ;
V_2 -> V_821 -> V_912 . V_913 = V_914 ;
V_2 -> V_821 -> V_912 . V_915 = 0 ;
V_98 = V_907 ;
}
F_24 ( V_2 , V_170 ) ;
return V_98 ;
}
static bool F_354 ( struct V_1 * V_2 , T_12 V_802 )
{
T_4 V_324 ;
if ( V_183 )
return false ;
if ( F_355 ( V_2 , V_802 ) )
return true ;
V_324 = F_279 ( V_2 , V_802 , NULL ) ;
if ( V_324 == V_79 )
return true ;
if ( ! F_136 ( F_135 ( V_2 -> V_29 , V_324 >> V_85 ) ) )
return true ;
return false ;
}
int F_356 ( struct V_1 * V_2 ,
unsigned long V_62 ,
int V_916 ,
void * V_917 ,
int V_918 )
{
int V_98 ;
struct V_809 * V_810 = & V_2 -> V_5 . V_884 ;
bool V_404 = true ;
F_357 ( V_2 ) ;
if ( ! ( V_916 & V_919 ) ) {
F_343 ( V_2 ) ;
V_810 -> V_920 = 0 ;
V_810 -> V_921 = false ;
V_810 -> V_922 = false ;
V_810 -> V_923
= V_916 & V_924 ;
V_98 = F_358 ( V_810 , V_917 , V_918 ) ;
F_359 ( V_2 ) ;
++ V_2 -> V_60 . V_925 ;
if ( V_98 ) {
if ( V_916 & V_924 )
return V_907 ;
if ( F_354 ( V_2 , V_62 ) )
return V_909 ;
if ( V_916 & V_926 )
return V_907 ;
return F_352 ( V_2 ) ;
}
}
if ( V_916 & V_926 ) {
F_350 ( V_2 , V_810 -> V_906 ) ;
return V_909 ;
}
if ( V_2 -> V_5 . V_902 ) {
V_2 -> V_5 . V_902 = false ;
memcpy ( V_810 -> V_606 , V_2 -> V_5 . V_606 , sizeof V_810 -> V_606 ) ;
}
V_927:
V_98 = F_360 ( V_810 ) ;
if ( V_98 == V_928 )
return V_909 ;
if ( V_98 == V_929 ) {
if ( F_354 ( V_2 , V_62 ) )
return V_909 ;
return F_352 ( V_2 ) ;
}
if ( V_810 -> V_921 ) {
F_341 ( V_2 ) ;
V_98 = V_909 ;
} else if ( V_2 -> V_5 . V_840 . V_724 ) {
if ( ! V_2 -> V_5 . V_840 . V_841 )
V_2 -> V_5 . V_840 . V_724 = 0 ;
else
V_404 = false ;
V_98 = V_930 ;
} else if ( V_2 -> V_820 ) {
if ( ! V_2 -> V_827 )
V_404 = false ;
V_98 = V_930 ;
} else if ( V_98 == V_931 )
goto V_927;
else
V_98 = V_909 ;
if ( V_404 ) {
F_340 ( V_2 , V_810 -> V_920 ) ;
F_351 ( V_2 , V_810 -> V_892 ) ;
F_23 ( V_48 , V_2 ) ;
memcpy ( V_2 -> V_5 . V_606 , V_810 -> V_606 , sizeof V_810 -> V_606 ) ;
V_2 -> V_5 . V_932 = false ;
F_350 ( V_2 , V_810 -> V_893 ) ;
} else
V_2 -> V_5 . V_932 = true ;
return V_98 ;
}
int F_361 ( struct V_1 * V_2 , int V_406 , unsigned short V_842 )
{
unsigned long V_154 = F_339 ( V_2 , V_880 ) ;
int V_87 = F_304 ( & V_2 -> V_5 . V_884 ,
V_406 , V_842 , & V_154 , 1 ) ;
V_2 -> V_5 . V_840 . V_724 = 0 ;
return V_87 ;
}
static void F_362 ( void * V_876 )
{
F_363 ( V_213 , 0 ) ;
}
static void F_364 ( void * V_31 )
{
struct V_933 * V_934 = V_31 ;
unsigned long V_935 = 0 ;
if ( V_31 )
V_935 = V_934 -> V_833 ;
else if ( ! F_100 ( V_211 ) )
V_935 = F_101 ( F_365 () ) ;
if ( ! V_935 )
V_935 = V_936 ;
F_363 ( V_213 , V_935 ) ;
}
static int F_366 ( struct V_937 * V_938 , unsigned long V_154 ,
void * V_31 )
{
struct V_933 * V_934 = V_31 ;
struct V_29 * V_29 ;
struct V_1 * V_2 ;
int V_3 , V_939 = 0 ;
if ( V_154 == V_940 && V_934 -> V_832 > V_934 -> V_833 )
return 0 ;
if ( V_154 == V_941 && V_934 -> V_832 < V_934 -> V_833 )
return 0 ;
F_185 ( V_934 -> V_210 , F_364 , V_934 , 1 ) ;
F_367 ( & V_942 ) ;
F_368 (kvm, &vm_list, vm_list) {
F_165 (i, vcpu, kvm) {
if ( V_2 -> V_210 != V_934 -> V_210 )
continue;
F_23 ( V_240 , V_2 ) ;
if ( V_2 -> V_210 != F_369 () )
V_939 = 1 ;
}
}
F_370 ( & V_942 ) ;
if ( V_934 -> V_832 < V_934 -> V_833 && V_939 ) {
F_185 ( V_934 -> V_210 , F_364 , V_934 , 1 ) ;
}
return 0 ;
}
static int F_371 ( struct V_937 * V_943 ,
unsigned long V_944 , void * V_945 )
{
unsigned int V_210 = ( unsigned long ) V_945 ;
switch ( V_944 ) {
case V_946 :
case V_947 :
F_185 ( V_210 , F_364 , NULL , 1 ) ;
break;
case V_948 :
F_185 ( V_210 , F_362 , NULL , 1 ) ;
break;
}
return V_949 ;
}
static void F_372 ( void )
{
int V_210 ;
V_950 = V_936 ;
F_373 ( & V_951 ) ;
if ( ! F_100 ( V_211 ) ) {
#ifdef F_374
struct V_952 V_953 ;
memset ( & V_953 , 0 , sizeof( V_953 ) ) ;
V_210 = F_99 () ;
F_375 ( & V_953 , V_210 ) ;
if ( V_953 . V_954 . V_955 )
V_950 = V_953 . V_954 . V_955 ;
F_102 () ;
#endif
F_376 ( & V_956 ,
V_957 ) ;
}
F_91 ( L_24 , V_950 ) ;
F_377 (cpu)
F_185 ( V_210 , F_364 , NULL , 1 ) ;
}
static int F_378 ( void )
{
return F_379 ( V_958 ) != NULL ;
}
static int F_380 ( void )
{
int V_959 = 3 ;
if ( F_379 ( V_958 ) )
V_959 = V_56 -> V_70 ( F_379 ( V_958 ) ) ;
return V_959 != 0 ;
}
static unsigned long F_381 ( void )
{
unsigned long V_960 = 0 ;
if ( F_379 ( V_958 ) )
V_960 = F_345 ( F_379 ( V_958 ) ) ;
return V_960 ;
}
void F_382 ( struct V_1 * V_2 )
{
F_383 ( V_958 , V_2 ) ;
}
void F_384 ( struct V_1 * V_2 )
{
F_383 ( V_958 , NULL ) ;
}
static void F_385 ( void )
{
T_2 V_26 ;
int V_961 = V_498 . V_962 ;
V_26 = ( ( 1ull << ( 62 - V_961 + 1 ) ) - 1 ) << V_961 ;
V_26 |= 1ull ;
#ifdef F_51
if ( V_961 == 52 )
V_26 &= ~ 1ull ;
#endif
F_386 ( V_26 ) ;
}
int F_387 ( void * V_963 )
{
int V_98 ;
struct V_56 * V_964 = (struct V_56 * ) V_963 ;
if ( V_56 ) {
F_9 ( V_25 L_25 ) ;
V_98 = - V_757 ;
goto V_92;
}
if ( ! V_964 -> V_965 () ) {
F_9 ( V_25 L_26 ) ;
V_98 = - V_966 ;
goto V_92;
}
if ( V_964 -> V_967 () ) {
F_9 ( V_25 L_27 ) ;
V_98 = - V_966 ;
goto V_92;
}
V_98 = F_388 () ;
if ( V_98 )
goto V_92;
F_385 () ;
F_263 () ;
V_56 = V_964 ;
F_389 ( V_968 , V_969 ,
V_970 , V_971 , 0 ) ;
F_372 () ;
F_390 ( & V_972 ) ;
if ( V_132 )
V_123 = F_391 ( V_119 ) ;
return 0 ;
V_92:
return V_98 ;
}
void F_392 ( void )
{
F_393 ( & V_972 ) ;
if ( ! F_100 ( V_211 ) )
F_394 ( & V_956 ,
V_957 ) ;
F_395 ( & V_951 ) ;
V_56 = NULL ;
F_396 () ;
}
int F_397 ( struct V_1 * V_2 )
{
++ V_2 -> V_60 . V_973 ;
if ( F_18 ( V_2 -> V_29 ) ) {
V_2 -> V_5 . V_974 = V_975 ;
return 1 ;
} else {
V_2 -> V_821 -> V_822 = V_976 ;
return 0 ;
}
}
static inline T_4 F_398 ( struct V_1 * V_2 , unsigned long V_977 ,
unsigned long V_978 )
{
if ( F_45 ( V_2 ) )
return V_977 ;
else
return V_977 | ( ( T_4 ) V_978 << 32 ) ;
}
int F_399 ( struct V_1 * V_2 )
{
T_2 V_979 , V_980 , V_981 , V_87 ;
T_13 V_982 , V_983 , V_984 , V_169 = V_985 , V_986 = 0 ;
bool V_987 , V_988 ;
int V_111 , V_112 ;
if ( V_56 -> V_70 ( V_2 ) != 0 || ! F_346 ( V_2 ) ) {
F_24 ( V_2 , V_170 ) ;
return 0 ;
}
V_56 -> V_113 ( V_2 , & V_111 , & V_112 ) ;
V_988 = F_45 ( V_2 ) && V_112 == 1 ;
if ( ! V_988 ) {
V_979 = ( ( T_2 ) F_339 ( V_2 , V_989 ) << 32 ) |
( F_339 ( V_2 , V_880 ) & 0xffffffff ) ;
V_980 = ( ( T_2 ) F_339 ( V_2 , V_990 ) << 32 ) |
( F_339 ( V_2 , V_991 ) & 0xffffffff ) ;
V_981 = ( ( T_2 ) F_339 ( V_2 , V_992 ) << 32 ) |
( F_339 ( V_2 , V_993 ) & 0xffffffff ) ;
}
#ifdef F_51
else {
V_979 = F_339 ( V_2 , V_991 ) ;
V_980 = F_339 ( V_2 , V_989 ) ;
V_981 = F_339 ( V_2 , V_994 ) ;
}
#endif
V_982 = V_979 & 0xffff ;
V_987 = ( V_979 >> 16 ) & 0x1 ;
V_984 = ( V_979 >> 32 ) & 0xfff ;
V_983 = ( V_979 >> 48 ) & 0xfff ;
F_400 ( V_982 , V_987 , V_984 , V_983 , V_980 , V_981 ) ;
switch ( V_982 ) {
case V_995 :
F_401 ( V_2 ) ;
break;
default:
V_169 = V_996 ;
break;
}
V_87 = V_169 | ( ( ( T_2 ) V_986 & 0xfff ) << 32 ) ;
if ( V_988 ) {
F_402 ( V_2 , V_880 , V_87 ) ;
} else {
F_402 ( V_2 , V_989 , V_87 >> 32 ) ;
F_402 ( V_2 , V_880 , V_87 & 0xffffffff ) ;
}
return 1 ;
}
int F_403 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_977 , V_978 , V_997 , V_998 , V_87 ;
int V_98 = 1 ;
if ( F_132 ( V_2 -> V_29 ) )
return F_399 ( V_2 ) ;
V_16 = F_339 ( V_2 , V_880 ) ;
V_977 = F_339 ( V_2 , V_990 ) ;
V_978 = F_339 ( V_2 , V_991 ) ;
V_997 = F_339 ( V_2 , V_989 ) ;
V_998 = F_339 ( V_2 , V_993 ) ;
F_404 ( V_16 , V_977 , V_978 , V_997 , V_998 ) ;
if ( ! F_45 ( V_2 ) ) {
V_16 &= 0xFFFFFFFF ;
V_977 &= 0xFFFFFFFF ;
V_978 &= 0xFFFFFFFF ;
V_997 &= 0xFFFFFFFF ;
V_998 &= 0xFFFFFFFF ;
}
if ( V_56 -> V_70 ( V_2 ) != 0 ) {
V_87 = - V_999 ;
goto V_92;
}
switch ( V_16 ) {
case V_1000 :
V_87 = 0 ;
break;
case V_1001 :
V_98 = F_405 ( V_2 , V_977 , F_398 ( V_2 , V_978 , V_997 ) , & V_87 ) ;
break;
default:
V_87 = - V_1002 ;
break;
}
V_92:
F_402 ( V_2 , V_880 , V_87 ) ;
++ V_2 -> V_60 . V_1003 ;
return V_98 ;
}
int F_406 ( struct V_809 * V_810 )
{
struct V_1 * V_2 = F_282 ( V_810 ) ;
char V_1004 [ 3 ] ;
unsigned long V_1005 = F_345 ( V_2 ) ;
F_407 ( V_2 -> V_29 ) ;
V_56 -> V_312 ( V_2 , V_1004 ) ;
return F_295 ( V_810 , V_1005 , V_1004 , 3 , NULL ) ;
}
static int F_408 ( struct V_1 * V_2 , int V_3 )
{
struct V_125 * V_484 = & V_2 -> V_5 . V_487 [ V_3 ] ;
int V_790 , V_491 = V_2 -> V_5 . V_486 ;
V_484 -> V_226 &= ~ V_582 ;
for ( V_790 = V_3 + 1 ; ; V_790 = ( V_790 + 1 ) % V_491 ) {
struct V_125 * V_1006 = & V_2 -> V_5 . V_487 [ V_790 ] ;
if ( V_1006 -> V_133 == V_484 -> V_133 ) {
V_1006 -> V_226 |= V_582 ;
return V_790 ;
}
}
return 0 ;
}
static int F_409 ( struct V_125 * V_484 ,
T_1 V_133 , T_1 V_116 )
{
if ( V_484 -> V_133 != V_133 )
return 0 ;
if ( ( V_484 -> V_226 & V_584 ) && V_484 -> V_116 != V_116 )
return 0 ;
if ( ( V_484 -> V_226 & V_581 ) &&
! ( V_484 -> V_226 & V_582 ) )
return 0 ;
return 1 ;
}
struct V_125 * F_60 ( struct V_1 * V_2 ,
T_1 V_133 , T_1 V_116 )
{
int V_3 ;
struct V_125 * V_126 = NULL ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 . V_486 ; ++ V_3 ) {
struct V_125 * V_484 ;
V_484 = & V_2 -> V_5 . V_487 [ V_3 ] ;
if ( F_409 ( V_484 , V_133 , V_116 ) ) {
if ( V_484 -> V_226 & V_581 )
F_408 ( V_2 , V_3 ) ;
V_126 = V_484 ;
break;
}
}
return V_126 ;
}
int F_410 ( struct V_1 * V_2 )
{
struct V_125 * V_126 ;
V_126 = F_60 ( V_2 , 0x80000000 , 0 ) ;
if ( ! V_126 || V_126 -> V_493 < 0x80000008 )
goto V_1007;
V_126 = F_60 ( V_2 , 0x80000008 , 0 ) ;
if ( V_126 )
return V_126 -> V_493 & 0xff ;
V_1007:
return 36 ;
}
static struct V_125 * F_411 ( struct V_1 * V_2 ,
T_1 V_133 , T_1 V_116 )
{
struct V_125 * V_1008 ;
V_1008 = F_60 ( V_2 , V_133 & 0x80000000 , 0 ) ;
if ( ! V_1008 || V_1008 -> V_493 >= V_133 )
return NULL ;
if ( V_133 & 0x80000000 ) {
V_1008 = F_60 ( V_2 , 0 , 0 ) ;
if ( ! V_1008 )
return NULL ;
}
return F_60 ( V_2 , V_1008 -> V_493 , V_116 ) ;
}
void F_412 ( struct V_1 * V_2 )
{
T_1 V_133 , V_116 ;
struct V_125 * V_126 ;
V_133 = F_339 ( V_2 , V_880 ) ;
V_116 = F_339 ( V_2 , V_991 ) ;
F_402 ( V_2 , V_880 , 0 ) ;
F_402 ( V_2 , V_990 , 0 ) ;
F_402 ( V_2 , V_991 , 0 ) ;
F_402 ( V_2 , V_989 , 0 ) ;
V_126 = F_60 ( V_2 , V_133 , V_116 ) ;
if ( ! V_126 )
V_126 = F_411 ( V_2 , V_133 , V_116 ) ;
if ( V_126 ) {
F_402 ( V_2 , V_880 , V_126 -> V_493 ) ;
F_402 ( V_2 , V_990 , V_126 -> V_129 ) ;
F_402 ( V_2 , V_991 , V_126 -> V_127 ) ;
F_402 ( V_2 , V_989 , V_126 -> V_175 ) ;
}
V_56 -> V_57 ( V_2 ) ;
F_413 ( V_133 ,
F_339 ( V_2 , V_880 ) ,
F_339 ( V_2 , V_990 ) ,
F_339 ( V_2 , V_991 ) ,
F_339 ( V_2 , V_989 ) ) ;
}
static int F_414 ( struct V_1 * V_2 )
{
return ( ! F_18 ( V_2 -> V_29 ) && ! F_415 ( V_2 ) &&
V_2 -> V_821 -> V_1009 &&
F_416 ( V_2 ) ) ;
}
static void F_417 ( struct V_1 * V_2 )
{
struct V_1010 * V_1010 = V_2 -> V_821 ;
V_1010 -> V_1011 = ( F_344 ( V_2 ) & V_1012 ) != 0 ;
V_1010 -> V_151 = F_75 ( V_2 ) ;
V_1010 -> V_30 = F_17 ( V_2 ) ;
if ( F_18 ( V_2 -> V_29 ) )
V_1010 -> V_1013 = 1 ;
else
V_1010 -> V_1013 =
F_416 ( V_2 ) &&
! F_415 ( V_2 ) &&
! F_418 ( V_2 ) ;
}
static void F_419 ( struct V_1 * V_2 )
{
struct V_1014 * V_607 = V_2 -> V_5 . V_607 ;
struct V_299 * V_299 ;
if ( ! V_607 || ! V_607 -> V_683 )
return;
V_299 = F_153 ( V_2 -> V_29 , V_607 -> V_683 >> V_85 ) ;
V_2 -> V_5 . V_607 -> V_1015 = V_299 ;
}
static void F_420 ( struct V_1 * V_2 )
{
struct V_1014 * V_607 = V_2 -> V_5 . V_607 ;
int V_274 ;
if ( ! V_607 || ! V_607 -> V_683 )
return;
V_274 = F_171 ( & V_2 -> V_29 -> V_401 ) ;
F_146 ( V_607 -> V_1015 ) ;
F_121 ( V_2 -> V_29 , V_607 -> V_683 >> V_85 ) ;
F_172 ( & V_2 -> V_29 -> V_401 , V_274 ) ;
}
static void F_209 ( struct V_1 * V_2 )
{
int V_1016 , V_1017 ;
if ( ! V_56 -> F_209 )
return;
if ( ! V_2 -> V_5 . V_607 )
return;
if ( ! V_2 -> V_5 . V_607 -> V_683 )
V_1016 = F_421 ( V_2 ) ;
else
V_1016 = - 1 ;
if ( V_1016 != - 1 )
V_1016 >>= 4 ;
V_1017 = F_76 ( V_2 ) ;
V_56 -> F_209 ( V_2 , V_1017 , V_1016 ) ;
}
static void F_422 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_49 . V_50 ) {
F_423 ( V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ) ;
V_56 -> V_1018 ( V_2 , V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ,
V_2 -> V_5 . V_49 . V_44 ) ;
return;
}
if ( V_2 -> V_5 . V_637 ) {
V_56 -> V_1019 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_630 . V_50 ) {
V_56 -> V_1020 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_68 ) {
if ( V_56 -> V_1021 ( V_2 ) ) {
V_2 -> V_5 . V_68 = false ;
V_2 -> V_5 . V_637 = true ;
V_56 -> V_1019 ( V_2 ) ;
}
} else if ( F_415 ( V_2 ) ) {
if ( V_56 -> V_1022 ( V_2 ) ) {
F_211 ( V_2 , F_424 ( V_2 ) ,
false ) ;
V_56 -> V_1020 ( V_2 ) ;
}
}
}
static void F_425 ( struct V_1 * V_2 )
{
if ( F_65 ( V_2 , V_135 ) &&
! V_2 -> V_124 ) {
F_426 ( V_119 , V_2 -> V_5 . V_118 ) ;
V_2 -> V_124 = 1 ;
}
}
static void F_427 ( struct V_1 * V_2 )
{
if ( V_2 -> V_124 ) {
if ( V_2 -> V_5 . V_118 != V_123 )
F_426 ( V_119 , V_123 ) ;
V_2 -> V_124 = 0 ;
}
}
static int F_428 ( struct V_1 * V_2 )
{
int V_98 ;
bool V_68 ;
bool V_1023 = ! F_18 ( V_2 -> V_29 ) &&
V_2 -> V_821 -> V_1009 ;
if ( V_2 -> V_1024 ) {
if ( F_429 ( V_1025 , V_2 ) )
F_430 ( V_2 ) ;
if ( F_429 ( V_1026 , V_2 ) )
F_431 ( V_2 ) ;
if ( F_429 ( V_240 , V_2 ) ) {
V_98 = F_115 ( V_2 ) ;
if ( F_71 ( V_98 ) )
goto V_92;
}
if ( F_429 ( V_1027 , V_2 ) )
F_69 ( V_2 ) ;
if ( F_429 ( V_1028 , V_2 ) )
V_56 -> V_1029 ( V_2 ) ;
if ( F_429 ( V_1030 , V_2 ) ) {
V_2 -> V_821 -> V_822 = V_1031 ;
V_98 = 0 ;
goto V_92;
}
if ( F_429 ( V_54 , V_2 ) ) {
V_2 -> V_821 -> V_822 = V_1032 ;
V_98 = 0 ;
goto V_92;
}
if ( F_429 ( V_1033 , V_2 ) ) {
V_2 -> V_1034 = 0 ;
V_56 -> V_1035 ( V_2 ) ;
}
if ( F_429 ( V_1036 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1037 = true ;
V_98 = 1 ;
goto V_92;
}
if ( F_429 ( V_362 , V_2 ) )
F_148 ( V_2 ) ;
}
V_98 = F_432 ( V_2 ) ;
if ( F_71 ( V_98 ) )
goto V_92;
V_68 = F_433 ( V_2 -> V_5 . V_68 ) ;
if ( F_429 ( V_48 , V_2 ) || V_1023 ) {
F_422 ( V_2 ) ;
if ( V_68 )
V_56 -> V_1038 ( V_2 ) ;
else if ( F_415 ( V_2 ) || V_1023 )
V_56 -> V_1039 ( V_2 ) ;
if ( F_434 ( V_2 ) ) {
F_209 ( V_2 ) ;
F_435 ( V_2 ) ;
}
}
F_157 () ;
V_56 -> V_1040 ( V_2 ) ;
if ( V_2 -> V_1034 )
F_334 ( V_2 ) ;
F_425 ( V_2 ) ;
V_2 -> V_894 = V_1041 ;
F_436 () ;
F_261 () ;
if ( V_2 -> V_894 == V_1042 || V_2 -> V_1024
|| F_437 () || F_438 ( V_331 ) ) {
V_2 -> V_894 = V_1043 ;
F_12 () ;
F_262 () ;
F_158 () ;
V_56 -> V_1044 ( V_2 ) ;
V_98 = 1 ;
goto V_92;
}
F_172 ( & V_2 -> V_29 -> V_401 , V_2 -> V_1045 ) ;
F_439 () ;
if ( F_71 ( V_2 -> V_5 . V_167 ) ) {
F_440 ( 0 , 7 ) ;
F_440 ( V_2 -> V_5 . V_158 [ 0 ] , 0 ) ;
F_440 ( V_2 -> V_5 . V_158 [ 1 ] , 1 ) ;
F_440 ( V_2 -> V_5 . V_158 [ 2 ] , 2 ) ;
F_440 ( V_2 -> V_5 . V_158 [ 3 ] , 3 ) ;
}
F_441 ( V_2 -> V_1046 ) ;
V_56 -> V_821 ( V_2 ) ;
if ( F_442 () )
F_443 () ;
F_117 ( V_2 , V_239 , & V_2 -> V_5 . V_244 ) ;
V_2 -> V_894 = V_1043 ;
F_12 () ;
F_262 () ;
++ V_2 -> V_60 . V_1047 ;
F_444 () ;
F_445 () ;
F_158 () ;
V_2 -> V_1045 = F_171 ( & V_2 -> V_29 -> V_401 ) ;
if ( F_71 ( V_1048 == V_1049 ) ) {
unsigned long V_1005 = F_345 ( V_2 ) ;
F_446 ( V_1049 , ( void * ) V_1005 ) ;
}
F_447 ( V_2 ) ;
V_98 = V_56 -> V_1050 ( V_2 ) ;
V_92:
return V_98 ;
}
static int F_448 ( struct V_1 * V_2 )
{
int V_98 ;
struct V_29 * V_29 = V_2 -> V_29 ;
if ( F_71 ( V_2 -> V_5 . V_974 == V_1051 ) ) {
F_91 ( L_28 ,
V_2 -> V_1046 , V_2 -> V_5 . V_640 ) ;
F_449 ( V_2 ) ;
V_98 = F_450 ( V_2 ) ;
if ( V_98 )
return V_98 ;
V_2 -> V_5 . V_974 = V_1052 ;
}
V_2 -> V_1045 = F_171 ( & V_29 -> V_401 ) ;
F_419 ( V_2 ) ;
V_98 = 1 ;
while ( V_98 > 0 ) {
if ( V_2 -> V_5 . V_974 == V_1052 &&
! V_2 -> V_5 . V_6 . V_1037 )
V_98 = F_428 ( V_2 ) ;
else {
F_172 ( & V_29 -> V_401 , V_2 -> V_1045 ) ;
F_451 ( V_2 ) ;
V_2 -> V_1045 = F_171 ( & V_29 -> V_401 ) ;
if ( F_429 ( V_1053 , V_2 ) )
{
switch( V_2 -> V_5 . V_974 ) {
case V_975 :
V_2 -> V_5 . V_974 =
V_1052 ;
case V_1052 :
V_2 -> V_5 . V_6 . V_1037 = false ;
break;
case V_1051 :
default:
V_98 = - V_1054 ;
break;
}
}
}
if ( V_98 <= 0 )
break;
F_452 ( V_1055 , & V_2 -> V_1024 ) ;
if ( F_453 ( V_2 ) )
F_454 ( V_2 ) ;
if ( F_414 ( V_2 ) ) {
V_98 = - V_1054 ;
V_2 -> V_821 -> V_822 = V_1056 ;
++ V_2 -> V_60 . V_1057 ;
}
F_455 ( V_2 ) ;
if ( F_438 ( V_331 ) ) {
V_98 = - V_1054 ;
V_2 -> V_821 -> V_822 = V_1056 ;
++ V_2 -> V_60 . V_1058 ;
}
if ( F_437 () ) {
F_172 ( & V_29 -> V_401 , V_2 -> V_1045 ) ;
F_456 ( V_2 ) ;
V_2 -> V_1045 = F_171 ( & V_29 -> V_401 ) ;
}
}
F_172 ( & V_29 -> V_401 , V_2 -> V_1045 ) ;
F_420 ( V_2 ) ;
return V_98 ;
}
static int F_457 ( struct V_1 * V_2 )
{
struct V_1010 * V_821 = V_2 -> V_821 ;
int V_98 ;
if ( ! ( V_2 -> V_5 . V_840 . V_724 || V_2 -> V_820 ) )
return 1 ;
if ( V_2 -> V_820 ) {
V_2 -> V_820 = 0 ;
if ( ! V_2 -> V_827 )
memcpy ( V_2 -> V_816 + V_2 -> V_828 ,
V_821 -> V_818 . V_31 , 8 ) ;
V_2 -> V_828 += 8 ;
if ( V_2 -> V_828 < V_2 -> V_825 ) {
V_821 -> V_822 = V_823 ;
V_821 -> V_818 . V_824 = V_2 -> V_817 + V_2 -> V_828 ;
memcpy ( V_821 -> V_818 . V_31 , V_2 -> V_816 + V_2 -> V_828 , 8 ) ;
V_821 -> V_818 . V_74 = F_204 ( V_2 -> V_825 - V_2 -> V_828 , 8 ) ;
V_821 -> V_818 . V_826 = V_2 -> V_827 ;
V_2 -> V_820 = 1 ;
return 0 ;
}
if ( V_2 -> V_827 )
return 1 ;
V_2 -> V_815 = 1 ;
}
V_2 -> V_1045 = F_171 ( & V_2 -> V_29 -> V_401 ) ;
V_98 = F_458 ( V_2 , V_919 ) ;
F_172 ( & V_2 -> V_29 -> V_401 , V_2 -> V_1045 ) ;
if ( V_98 != V_909 )
return 0 ;
return 1 ;
}
int F_459 ( struct V_1 * V_2 , struct V_1010 * V_1010 )
{
int V_98 ;
T_14 V_1059 ;
if ( ! F_460 ( V_331 ) && F_461 ( V_331 ) )
return - V_301 ;
if ( V_2 -> V_1060 )
F_462 ( V_1061 , & V_2 -> V_1062 , & V_1059 ) ;
if ( F_71 ( V_2 -> V_5 . V_974 == V_1063 ) ) {
F_451 ( V_2 ) ;
F_452 ( V_1053 , & V_2 -> V_1024 ) ;
V_98 = - V_1064 ;
goto V_92;
}
if ( ! F_18 ( V_2 -> V_29 ) ) {
if ( F_73 ( V_2 , V_1010 -> V_151 ) != 0 ) {
V_98 = - V_474 ;
goto V_92;
}
}
V_98 = F_457 ( V_2 ) ;
if ( V_98 <= 0 )
goto V_92;
if ( V_1010 -> V_822 == V_1065 )
F_402 ( V_2 , V_880 ,
V_1010 -> V_1066 . V_87 ) ;
V_98 = F_448 ( V_2 ) ;
V_92:
F_417 ( V_2 ) ;
if ( V_2 -> V_1060 )
F_462 ( V_1061 , & V_1059 , NULL ) ;
return V_98 ;
}
int F_463 ( struct V_1 * V_2 , struct V_1067 * V_606 )
{
if ( V_2 -> V_5 . V_932 ) {
struct V_809 * V_810 = & V_2 -> V_5 . V_884 ;
memcpy ( V_2 -> V_5 . V_606 , V_810 -> V_606 , sizeof V_810 -> V_606 ) ;
V_2 -> V_5 . V_932 = false ;
}
V_606 -> V_1068 = F_339 ( V_2 , V_880 ) ;
V_606 -> V_1069 = F_339 ( V_2 , V_990 ) ;
V_606 -> V_1070 = F_339 ( V_2 , V_991 ) ;
V_606 -> V_1071 = F_339 ( V_2 , V_989 ) ;
V_606 -> V_1072 = F_339 ( V_2 , V_993 ) ;
V_606 -> V_1073 = F_339 ( V_2 , V_992 ) ;
V_606 -> V_1074 = F_339 ( V_2 , V_881 ) ;
V_606 -> V_1075 = F_339 ( V_2 , V_1076 ) ;
#ifdef F_51
V_606 -> V_1077 = F_339 ( V_2 , V_994 ) ;
V_606 -> V_1078 = F_339 ( V_2 , V_1079 ) ;
V_606 -> V_1080 = F_339 ( V_2 , V_1081 ) ;
V_606 -> V_1082 = F_339 ( V_2 , V_1083 ) ;
V_606 -> V_1084 = F_339 ( V_2 , V_1085 ) ;
V_606 -> V_1086 = F_339 ( V_2 , V_1087 ) ;
V_606 -> V_1088 = F_339 ( V_2 , V_1089 ) ;
V_606 -> V_1090 = F_339 ( V_2 , V_1091 ) ;
#endif
V_606 -> V_1005 = F_345 ( V_2 ) ;
V_606 -> V_1092 = F_344 ( V_2 ) ;
return 0 ;
}
int F_464 ( struct V_1 * V_2 , struct V_1067 * V_606 )
{
V_2 -> V_5 . V_902 = true ;
V_2 -> V_5 . V_932 = false ;
F_402 ( V_2 , V_880 , V_606 -> V_1068 ) ;
F_402 ( V_2 , V_990 , V_606 -> V_1069 ) ;
F_402 ( V_2 , V_991 , V_606 -> V_1070 ) ;
F_402 ( V_2 , V_989 , V_606 -> V_1071 ) ;
F_402 ( V_2 , V_993 , V_606 -> V_1072 ) ;
F_402 ( V_2 , V_992 , V_606 -> V_1073 ) ;
F_402 ( V_2 , V_881 , V_606 -> V_1074 ) ;
F_402 ( V_2 , V_1076 , V_606 -> V_1075 ) ;
#ifdef F_51
F_402 ( V_2 , V_994 , V_606 -> V_1077 ) ;
F_402 ( V_2 , V_1079 , V_606 -> V_1078 ) ;
F_402 ( V_2 , V_1081 , V_606 -> V_1080 ) ;
F_402 ( V_2 , V_1083 , V_606 -> V_1082 ) ;
F_402 ( V_2 , V_1085 , V_606 -> V_1084 ) ;
F_402 ( V_2 , V_1087 , V_606 -> V_1086 ) ;
F_402 ( V_2 , V_1089 , V_606 -> V_1088 ) ;
F_402 ( V_2 , V_1091 , V_606 -> V_1090 ) ;
#endif
F_350 ( V_2 , V_606 -> V_1005 ) ;
F_351 ( V_2 , V_606 -> V_1092 ) ;
V_2 -> V_5 . V_49 . V_50 = false ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
void F_465 ( struct V_1 * V_2 , int * V_155 , int * V_872 )
{
struct V_795 V_1093 ;
F_273 ( V_2 , & V_1093 , V_1094 ) ;
* V_155 = V_1093 . V_155 ;
* V_872 = V_1093 . V_872 ;
}
int F_466 ( struct V_1 * V_2 ,
struct V_1095 * V_1096 )
{
struct V_856 V_857 ;
F_273 ( V_2 , & V_1096 -> V_1093 , V_1094 ) ;
F_273 ( V_2 , & V_1096 -> V_1097 , V_1098 ) ;
F_273 ( V_2 , & V_1096 -> V_1099 , V_1100 ) ;
F_273 ( V_2 , & V_1096 -> V_1101 , V_1102 ) ;
F_273 ( V_2 , & V_1096 -> V_1103 , V_1104 ) ;
F_273 ( V_2 , & V_1096 -> V_1105 , V_1106 ) ;
F_273 ( V_2 , & V_1096 -> V_1107 , V_1108 ) ;
F_273 ( V_2 , & V_1096 -> V_1109 , V_1110 ) ;
V_56 -> V_859 ( V_2 , & V_857 ) ;
V_1096 -> V_1111 . V_600 = V_857 . V_406 ;
V_1096 -> V_1111 . V_868 = V_857 . V_63 ;
V_56 -> V_858 ( V_2 , & V_857 ) ;
V_1096 -> V_1112 . V_600 = V_857 . V_406 ;
V_1096 -> V_1112 . V_868 = V_857 . V_63 ;
V_1096 -> V_99 = F_50 ( V_2 ) ;
V_1096 -> V_62 = V_2 -> V_5 . V_62 ;
V_1096 -> V_83 = F_48 ( V_2 ) ;
V_1096 -> V_136 = F_67 ( V_2 ) ;
V_1096 -> V_151 = F_75 ( V_2 ) ;
V_1096 -> V_109 = V_2 -> V_5 . V_109 ;
V_1096 -> V_30 = F_17 ( V_2 ) ;
memset ( V_1096 -> V_1113 , 0 , sizeof V_1096 -> V_1113 ) ;
if ( V_2 -> V_5 . V_630 . V_50 && ! V_2 -> V_5 . V_630 . V_631 )
F_467 ( V_2 -> V_5 . V_630 . V_16 ,
( unsigned long * ) V_1096 -> V_1113 ) ;
return 0 ;
}
int F_468 ( struct V_1 * V_2 ,
struct V_1114 * V_974 )
{
V_974 -> V_974 = V_2 -> V_5 . V_974 ;
return 0 ;
}
int F_469 ( struct V_1 * V_2 ,
struct V_1114 * V_974 )
{
V_2 -> V_5 . V_974 = V_974 -> V_974 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
int F_470 ( struct V_1 * V_2 , V_837 V_1115 , int V_1116 ,
bool V_52 , T_1 V_43 )
{
struct V_809 * V_810 = & V_2 -> V_5 . V_884 ;
int V_87 ;
F_343 ( V_2 ) ;
V_87 = F_471 ( V_810 , V_1115 , V_1116 ,
V_52 , V_43 ) ;
if ( V_87 )
return V_907 ;
memcpy ( V_2 -> V_5 . V_606 , V_810 -> V_606 , sizeof V_810 -> V_606 ) ;
F_350 ( V_2 , V_810 -> V_893 ) ;
F_351 ( V_2 , V_810 -> V_892 ) ;
F_23 ( V_48 , V_2 ) ;
return V_909 ;
}
int F_472 ( struct V_1 * V_2 ,
struct V_1095 * V_1096 )
{
int V_1117 = 0 ;
int V_1118 , V_1119 , V_274 ;
struct V_856 V_857 ;
V_857 . V_406 = V_1096 -> V_1111 . V_600 ;
V_857 . V_63 = V_1096 -> V_1111 . V_868 ;
V_56 -> V_861 ( V_2 , & V_857 ) ;
V_857 . V_406 = V_1096 -> V_1112 . V_600 ;
V_857 . V_63 = V_1096 -> V_1112 . V_868 ;
V_56 -> V_860 ( V_2 , & V_857 ) ;
V_2 -> V_5 . V_62 = V_1096 -> V_62 ;
V_1117 |= F_48 ( V_2 ) != V_1096 -> V_83 ;
V_2 -> V_5 . V_83 = V_1096 -> V_83 ;
F_43 ( V_148 , ( V_149 * ) & V_2 -> V_5 . V_95 ) ;
F_73 ( V_2 , V_1096 -> V_151 ) ;
V_1117 |= V_2 -> V_5 . V_109 != V_1096 -> V_109 ;
V_56 -> F_81 ( V_2 , V_1096 -> V_109 ) ;
F_19 ( V_2 , V_1096 -> V_30 ) ;
V_1117 |= F_50 ( V_2 ) != V_1096 -> V_99 ;
V_56 -> V_114 ( V_2 , V_1096 -> V_99 ) ;
V_2 -> V_5 . V_99 = V_1096 -> V_99 ;
V_1117 |= F_67 ( V_2 ) != V_1096 -> V_136 ;
V_56 -> V_145 ( V_2 , V_1096 -> V_136 ) ;
if ( V_1096 -> V_136 & V_135 )
F_64 ( V_2 ) ;
V_274 = F_171 ( & V_2 -> V_29 -> V_401 ) ;
if ( ! F_45 ( V_2 ) && F_46 ( V_2 ) ) {
F_40 ( V_2 , V_2 -> V_5 . V_82 , F_48 ( V_2 ) ) ;
V_1117 = 1 ;
}
F_172 ( & V_2 -> V_29 -> V_401 , V_274 ) ;
if ( V_1117 )
F_54 ( V_2 ) ;
V_1119 = ( sizeof V_1096 -> V_1113 ) << 3 ;
V_1118 = F_473 (
( const unsigned long * ) V_1096 -> V_1113 , V_1119 ) ;
if ( V_1118 < V_1119 ) {
F_211 ( V_2 , V_1118 , false ) ;
F_91 ( L_29 , V_1118 ) ;
}
F_272 ( V_2 , & V_1096 -> V_1093 , V_1094 ) ;
F_272 ( V_2 , & V_1096 -> V_1097 , V_1098 ) ;
F_272 ( V_2 , & V_1096 -> V_1099 , V_1100 ) ;
F_272 ( V_2 , & V_1096 -> V_1101 , V_1102 ) ;
F_272 ( V_2 , & V_1096 -> V_1103 , V_1104 ) ;
F_272 ( V_2 , & V_1096 -> V_1105 , V_1106 ) ;
F_272 ( V_2 , & V_1096 -> V_1107 , V_1108 ) ;
F_272 ( V_2 , & V_1096 -> V_1109 , V_1110 ) ;
F_209 ( V_2 ) ;
if ( F_474 ( V_2 ) && F_345 ( V_2 ) == 0xfff0 &&
V_1096 -> V_1093 . V_862 == 0xf000 && V_1096 -> V_1093 . V_868 == 0xffff0000 &&
! F_346 ( V_2 ) )
V_2 -> V_5 . V_974 = V_1052 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
int F_475 ( struct V_1 * V_2 ,
struct V_1120 * V_1121 )
{
unsigned long V_1092 ;
int V_3 , V_98 ;
if ( V_1121 -> V_731 & ( V_1122 | V_1123 ) ) {
V_98 = - V_1124 ;
if ( V_2 -> V_5 . V_49 . V_50 )
goto V_92;
if ( V_1121 -> V_731 & V_1122 )
F_24 ( V_2 , V_1125 ) ;
else
F_24 ( V_2 , V_1126 ) ;
}
V_1092 = F_344 ( V_2 ) ;
V_2 -> V_156 = V_1121 -> V_731 ;
if ( ! ( V_2 -> V_156 & V_1127 ) )
V_2 -> V_156 = 0 ;
if ( V_2 -> V_156 & V_157 ) {
for ( V_3 = 0 ; V_3 < V_1128 ; ++ V_3 )
V_2 -> V_5 . V_158 [ V_3 ] = V_1121 -> V_5 . V_1129 [ V_3 ] ;
V_2 -> V_5 . V_167 =
( V_1121 -> V_5 . V_1129 [ 7 ] & V_168 ) ;
} else {
for ( V_3 = 0 ; V_3 < V_1128 ; V_3 ++ )
V_2 -> V_5 . V_158 [ V_3 ] = V_2 -> V_5 . V_155 [ V_3 ] ;
V_2 -> V_5 . V_167 = ( V_2 -> V_5 . V_163 & V_168 ) ;
}
if ( V_2 -> V_156 & V_1130 )
V_2 -> V_5 . V_1131 = F_345 ( V_2 ) +
F_305 ( V_2 , V_1094 ) ;
F_351 ( V_2 , V_1092 ) ;
V_56 -> V_1132 ( V_2 , V_1121 ) ;
V_98 = 0 ;
V_92:
return V_98 ;
}
int F_476 ( struct V_1 * V_2 ,
struct V_1133 * V_1107 )
{
unsigned long V_1134 = V_1107 -> V_1135 ;
T_4 V_324 ;
int V_274 ;
V_274 = F_171 ( & V_2 -> V_29 -> V_401 ) ;
V_324 = F_279 ( V_2 , V_1134 , NULL ) ;
F_172 ( & V_2 -> V_29 -> V_401 , V_274 ) ;
V_1107 -> V_1136 = V_324 ;
V_1107 -> V_1137 = V_324 != V_79 ;
V_1107 -> V_1138 = 1 ;
V_1107 -> V_1139 = 0 ;
return 0 ;
}
int F_477 ( struct V_1 * V_2 , struct V_1140 * V_1141 )
{
struct V_657 * V_656 =
& V_2 -> V_5 . V_652 . V_653 -> V_656 ;
memcpy ( V_1141 -> V_1142 , V_656 -> V_1143 , 128 ) ;
V_1141 -> V_1144 = V_656 -> V_1145 ;
V_1141 -> V_1146 = V_656 -> V_1147 ;
V_1141 -> V_1148 = V_656 -> V_1149 ;
V_1141 -> V_1150 = V_656 -> V_1151 ;
V_1141 -> V_1152 = V_656 -> V_1005 ;
V_1141 -> V_1153 = V_656 -> V_1154 ;
memcpy ( V_1141 -> V_1155 , V_656 -> V_1156 , sizeof V_656 -> V_1156 ) ;
return 0 ;
}
int F_478 ( struct V_1 * V_2 , struct V_1140 * V_1141 )
{
struct V_657 * V_656 =
& V_2 -> V_5 . V_652 . V_653 -> V_656 ;
memcpy ( V_656 -> V_1143 , V_1141 -> V_1142 , 128 ) ;
V_656 -> V_1145 = V_1141 -> V_1144 ;
V_656 -> V_1147 = V_1141 -> V_1146 ;
V_656 -> V_1149 = V_1141 -> V_1148 ;
V_656 -> V_1151 = V_1141 -> V_1150 ;
V_656 -> V_1005 = V_1141 -> V_1152 ;
V_656 -> V_1154 = V_1141 -> V_1153 ;
memcpy ( V_656 -> V_1156 , V_1141 -> V_1155 , sizeof V_656 -> V_1156 ) ;
return 0 ;
}
int F_479 ( struct V_1 * V_2 )
{
int V_55 ;
V_55 = F_480 ( & V_2 -> V_5 . V_652 ) ;
if ( V_55 )
return V_55 ;
F_481 ( & V_2 -> V_5 . V_652 ) ;
V_2 -> V_5 . V_118 = V_120 ;
V_2 -> V_5 . V_99 |= V_106 ;
return 0 ;
}
static void F_482 ( struct V_1 * V_2 )
{
F_483 ( & V_2 -> V_5 . V_652 ) ;
}
void F_334 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1157 )
return;
F_427 ( V_2 ) ;
V_2 -> V_1157 = 1 ;
F_484 ( V_331 ) ;
F_485 ( & V_2 -> V_5 . V_652 ) ;
F_486 ( 1 ) ;
}
void F_189 ( struct V_1 * V_2 )
{
F_427 ( V_2 ) ;
if ( ! V_2 -> V_1157 )
return;
V_2 -> V_1157 = 0 ;
F_487 ( & V_2 -> V_5 . V_652 ) ;
++ V_2 -> V_60 . V_1158 ;
F_23 ( V_1033 , V_2 ) ;
F_486 ( 0 ) ;
}
void F_488 ( struct V_1 * V_2 )
{
F_145 ( V_2 ) ;
F_489 ( V_2 -> V_5 . V_480 ) ;
F_482 ( V_2 ) ;
V_56 -> V_1159 ( V_2 ) ;
}
struct V_1 * F_490 ( struct V_29 * V_29 ,
unsigned int V_1160 )
{
if ( F_113 () && F_491 ( & V_29 -> V_1161 ) != 0 )
F_106 ( V_214
L_30
L_31 ) ;
return V_56 -> V_1162 ( V_29 , V_1160 ) ;
}
int F_492 ( struct V_1 * V_2 )
{
int V_98 ;
V_2 -> V_5 . V_269 . V_1163 = 1 ;
V_481 ( V_2 ) ;
V_98 = F_450 ( V_2 ) ;
if ( V_98 == 0 )
V_98 = F_493 ( V_2 ) ;
V_483 ( V_2 ) ;
return V_98 ;
}
void F_494 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_6 . V_325 = 0 ;
V_481 ( V_2 ) ;
F_430 ( V_2 ) ;
V_483 ( V_2 ) ;
F_482 ( V_2 ) ;
V_56 -> V_1159 ( V_2 ) ;
}
int F_450 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_68 = false ;
V_2 -> V_5 . V_637 = false ;
V_2 -> V_5 . V_167 = 0 ;
memset ( V_2 -> V_5 . V_155 , 0 , sizeof( V_2 -> V_5 . V_155 ) ) ;
V_2 -> V_5 . V_160 = V_162 ;
V_2 -> V_5 . V_163 = V_165 ;
F_23 ( V_48 , V_2 ) ;
V_2 -> V_5 . V_6 . V_325 = 0 ;
V_2 -> V_5 . V_329 . V_325 = 0 ;
F_145 ( V_2 ) ;
F_53 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1037 = false ;
return V_56 -> V_1164 ( V_2 ) ;
}
int F_495 ( void * V_475 )
{
struct V_29 * V_29 ;
struct V_1 * V_2 ;
int V_3 ;
F_13 () ;
F_368 (kvm, &vm_list, vm_list)
F_165 (i, vcpu, kvm)
if ( V_2 -> V_210 == F_369 () )
F_23 ( V_240 , V_2 ) ;
return V_56 -> V_1165 ( V_475 ) ;
}
void F_496 ( void * V_475 )
{
V_56 -> V_1166 ( V_475 ) ;
F_16 ( V_475 ) ;
}
int F_497 ( void )
{
return V_56 -> V_1167 () ;
}
void F_498 ( void )
{
V_56 -> V_1168 () ;
}
void F_499 ( void * V_1169 )
{
V_56 -> V_1170 ( V_1169 ) ;
}
int F_500 ( struct V_1 * V_2 )
{
struct V_299 * V_299 ;
struct V_29 * V_29 ;
int V_98 ;
F_275 ( V_2 -> V_29 == NULL ) ;
V_29 = V_2 -> V_29 ;
V_2 -> V_5 . V_884 . V_964 = & V_1171 ;
V_2 -> V_5 . V_82 = & V_2 -> V_5 . V_67 ;
V_2 -> V_5 . V_67 . V_1172 = V_1173 ;
V_2 -> V_5 . V_67 . V_78 = V_78 ;
V_2 -> V_5 . V_65 . V_78 = F_274 ;
if ( ! F_18 ( V_29 ) || F_474 ( V_2 ) )
V_2 -> V_5 . V_974 = V_1052 ;
else
V_2 -> V_5 . V_974 = V_1063 ;
V_299 = F_501 ( V_302 | V_1174 ) ;
if ( ! V_299 ) {
V_98 = - V_301 ;
goto V_1175;
}
V_2 -> V_5 . V_844 = F_502 ( V_299 ) ;
F_108 ( V_2 , V_950 ) ;
V_98 = F_503 ( V_2 ) ;
if ( V_98 < 0 )
goto V_1176;
if ( F_18 ( V_29 ) ) {
V_98 = F_504 ( V_2 ) ;
if ( V_98 < 0 )
goto V_1177;
}
V_2 -> V_5 . V_288 = F_129 ( V_363 * sizeof( T_2 ) * 4 ,
V_302 ) ;
if ( ! V_2 -> V_5 . V_288 ) {
V_98 = - V_301 ;
goto V_1178;
}
V_2 -> V_5 . V_280 = V_363 ;
if ( ! F_505 ( & V_2 -> V_5 . V_480 , V_302 ) )
goto V_1179;
F_1 ( V_2 ) ;
return 0 ;
V_1179:
F_131 ( V_2 -> V_5 . V_288 ) ;
V_1178:
F_506 ( V_2 ) ;
V_1177:
F_507 ( V_2 ) ;
V_1176:
F_508 ( ( unsigned long ) V_2 -> V_5 . V_844 ) ;
V_1175:
return V_98 ;
}
void F_509 ( struct V_1 * V_2 )
{
int V_274 ;
F_131 ( V_2 -> V_5 . V_288 ) ;
F_506 ( V_2 ) ;
V_274 = F_171 ( & V_2 -> V_29 -> V_401 ) ;
F_507 ( V_2 ) ;
F_172 ( & V_2 -> V_29 -> V_401 , V_274 ) ;
F_508 ( ( unsigned long ) V_2 -> V_5 . V_844 ) ;
}
int F_510 ( struct V_29 * V_29 )
{
F_511 ( & V_29 -> V_5 . V_1180 ) ;
F_511 ( & V_29 -> V_5 . V_1181 ) ;
F_467 ( V_771 , & V_29 -> V_5 . V_1182 ) ;
F_512 ( & V_29 -> V_5 . V_228 ) ;
return 0 ;
}
static void F_513 ( struct V_1 * V_2 )
{
V_481 ( V_2 ) ;
F_430 ( V_2 ) ;
V_483 ( V_2 ) ;
}
static void F_514 ( struct V_29 * V_29 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_165 (i, vcpu, kvm) {
F_53 ( V_2 ) ;
F_513 ( V_2 ) ;
}
F_165 (i, vcpu, kvm)
F_488 ( V_2 ) ;
F_159 ( & V_29 -> V_378 ) ;
for ( V_3 = 0 ; V_3 < F_491 ( & V_29 -> V_1161 ) ; V_3 ++ )
V_29 -> V_1183 [ V_3 ] = NULL ;
F_515 ( & V_29 -> V_1161 , 0 ) ;
F_160 ( & V_29 -> V_378 ) ;
}
void F_516 ( struct V_29 * V_29 )
{
F_517 ( V_29 ) ;
F_518 ( V_29 ) ;
}
void F_519 ( struct V_29 * V_29 )
{
F_520 ( V_29 ) ;
F_131 ( V_29 -> V_5 . V_756 ) ;
F_131 ( V_29 -> V_5 . V_1184 ) ;
F_514 ( V_29 ) ;
if ( V_29 -> V_5 . V_1185 )
F_521 ( V_29 -> V_5 . V_1185 ) ;
if ( V_29 -> V_5 . V_1186 )
F_521 ( V_29 -> V_5 . V_1186 ) ;
}
int F_522 ( struct V_29 * V_29 ,
struct V_735 * V_736 ,
struct V_735 V_832 ,
struct V_1187 * V_1188 ,
int V_1189 )
{
int V_1190 = V_736 -> V_1190 ;
int V_1191 = V_1192 | V_1193 ;
if ( V_736 -> V_1160 >= V_447 )
V_1191 = V_1194 | V_1193 ;
if ( ! V_1189 ) {
if ( V_1190 && ! V_832 . V_1195 ) {
unsigned long V_1196 ;
F_523 ( & V_331 -> V_1197 -> V_1198 ) ;
V_1196 = F_524 ( NULL , 0 ,
V_1190 * V_86 ,
V_1199 | V_1200 ,
V_1191 ,
0 ) ;
F_525 ( & V_331 -> V_1197 -> V_1198 ) ;
if ( F_526 ( ( void * ) V_1196 ) )
return F_527 ( ( void * ) V_1196 ) ;
V_736 -> V_1196 = V_1196 ;
}
}
return 0 ;
}
void F_528 ( struct V_29 * V_29 ,
struct V_1187 * V_1188 ,
struct V_735 V_832 ,
int V_1189 )
{
int V_1201 = 0 , V_1190 = V_1188 -> V_1202 >> V_85 ;
if ( ! V_1189 && ! V_832 . V_1189 && V_832 . V_1195 && ! V_1190 ) {
int V_87 ;
F_523 ( & V_331 -> V_1197 -> V_1198 ) ;
V_87 = F_529 ( V_331 -> V_1197 , V_832 . V_1196 ,
V_832 . V_1190 * V_86 ) ;
F_525 ( & V_331 -> V_1197 -> V_1198 ) ;
if ( V_87 < 0 )
F_9 ( V_214
L_32
L_33 ) ;
}
if ( ! V_29 -> V_5 . V_707 )
V_1201 = F_530 ( V_29 ) ;
F_230 ( & V_29 -> V_706 ) ;
if ( V_1201 )
F_231 ( V_29 , V_1201 ) ;
F_250 ( V_29 , V_1188 -> V_10 ) ;
F_232 ( & V_29 -> V_706 ) ;
}
void F_531 ( struct V_29 * V_29 )
{
F_407 ( V_29 ) ;
F_532 ( V_29 ) ;
}
int F_533 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_974 == V_1052 &&
! V_2 -> V_5 . V_6 . V_1037 )
|| ! F_534 ( & V_2 -> V_1203 . V_1204 )
|| V_2 -> V_5 . V_974 == V_1051
|| V_2 -> V_5 . V_68 ||
( F_416 ( V_2 ) &&
F_415 ( V_2 ) ) ;
}
void F_535 ( struct V_1 * V_2 )
{
int V_1205 ;
int V_210 = V_2 -> V_210 ;
if ( F_536 ( & V_2 -> V_1206 ) ) {
F_537 ( & V_2 -> V_1206 ) ;
++ V_2 -> V_60 . V_1207 ;
}
V_1205 = F_99 () ;
if ( V_210 != V_1205 && ( unsigned ) V_210 < V_1208 && F_538 ( V_210 ) )
if ( F_539 ( V_2 ) == V_1041 )
F_540 ( V_210 ) ;
F_102 () ;
}
int F_416 ( struct V_1 * V_2 )
{
return V_56 -> V_1022 ( V_2 ) ;
}
bool F_541 ( struct V_1 * V_2 , unsigned long V_1209 )
{
unsigned long V_1210 = F_345 ( V_2 ) +
F_305 ( V_2 , V_1094 ) ;
return V_1210 == V_1209 ;
}
unsigned long F_344 ( struct V_1 * V_2 )
{
unsigned long V_1092 ;
V_1092 = V_56 -> V_1211 ( V_2 ) ;
if ( V_2 -> V_156 & V_1130 )
V_1092 &= ~ V_1212 ;
return V_1092 ;
}
void F_351 ( struct V_1 * V_2 , unsigned long V_1092 )
{
if ( V_2 -> V_156 & V_1130 &&
F_541 ( V_2 , V_2 -> V_5 . V_1131 ) )
V_1092 |= V_1212 ;
V_56 -> V_1213 ( V_2 , V_1092 ) ;
F_23 ( V_48 , V_2 ) ;
}
void F_542 ( struct V_1 * V_2 , struct V_1214 * V_1215 )
{
int V_98 ;
if ( ( V_2 -> V_5 . V_67 . V_1216 != V_1215 -> V_5 . V_1216 ) ||
F_154 ( V_1215 -> V_299 ) )
return;
V_98 = F_432 ( V_2 ) ;
if ( F_71 ( V_98 ) )
return;
if ( ! V_2 -> V_5 . V_67 . V_1216 &&
V_1215 -> V_5 . V_83 != V_2 -> V_5 . V_67 . V_1217 ( V_2 ) )
return;
V_2 -> V_5 . V_67 . V_1218 ( V_2 , V_1215 -> V_802 , 0 , true ) ;
}
static inline T_1 F_543 ( T_3 V_81 )
{
return F_544 ( V_81 & 0xffffffff , F_545 ( V_4 ) ) ;
}
static inline T_1 F_546 ( T_1 V_1219 )
{
return ( V_1219 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_547 ( struct V_1 * V_2 , T_3 V_81 )
{
T_1 V_1219 = F_543 ( V_81 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1219 ] != ~ 0 )
V_1219 = F_546 ( V_1219 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1219 ] = V_81 ;
}
static T_1 F_548 ( struct V_1 * V_2 , T_3 V_81 )
{
int V_3 ;
T_1 V_1219 = F_543 ( V_81 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1219 ] != V_81 &&
V_2 -> V_5 . V_6 . V_7 [ V_1219 ] != ~ 0 ) ; V_3 ++ )
V_1219 = F_546 ( V_1219 ) ;
return V_1219 ;
}
bool F_549 ( struct V_1 * V_2 , T_3 V_81 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_548 ( V_2 , V_81 ) ] == V_81 ;
}
static void F_550 ( struct V_1 * V_2 , T_3 V_81 )
{
T_1 V_3 , V_790 , V_1220 ;
V_3 = V_790 = F_548 ( V_2 , V_81 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_790 = F_546 ( V_790 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_790 ] == ~ 0 )
return;
V_1220 = F_543 ( V_2 -> V_5 . V_6 . V_7 [ V_790 ] ) ;
} while ( ( V_3 <= V_790 ) ? ( V_3 < V_1220 && V_1220 <= V_790 ) : ( V_3 < V_1220 || V_1220 <= V_790 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_790 ] ;
V_3 = V_790 ;
}
}
static int F_551 ( struct V_1 * V_2 , T_1 V_154 )
{
return F_150 ( V_2 -> V_29 , & V_2 -> V_5 . V_6 . V_31 , & V_154 ,
sizeof( V_154 ) ) ;
}
void F_552 ( struct V_1 * V_2 ,
struct V_1214 * V_1215 )
{
struct V_58 V_59 ;
F_553 ( V_1215 -> V_5 . V_1221 , V_1215 -> V_802 ) ;
F_547 ( V_2 , V_1215 -> V_5 . V_81 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_325 & V_326 ) ||
( V_2 -> V_5 . V_6 . V_327 &&
V_56 -> V_70 ( V_2 ) == 0 ) )
F_23 ( V_1036 , V_2 ) ;
else if ( ! F_551 ( V_2 , V_1222 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_885 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_1215 -> V_5 . V_1221 ;
F_28 ( V_2 , & V_59 ) ;
}
}
void F_554 ( struct V_1 * V_2 ,
struct V_1214 * V_1215 )
{
struct V_58 V_59 ;
F_555 ( V_1215 -> V_5 . V_1221 , V_1215 -> V_802 ) ;
if ( F_154 ( V_1215 -> V_299 ) )
V_1215 -> V_5 . V_1221 = ~ 0 ;
else
F_550 ( V_2 , V_1215 -> V_5 . V_81 ) ;
if ( ( V_2 -> V_5 . V_6 . V_325 & V_326 ) &&
! F_551 ( V_2 , V_1223 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_885 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_1215 -> V_5 . V_1221 ;
F_28 ( V_2 , & V_59 ) ;
}
V_2 -> V_5 . V_6 . V_1037 = false ;
}
bool F_556 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_325 & V_326 ) )
return true ;
else
return ! F_418 ( V_2 ) &&
V_56 -> V_1022 ( V_2 ) ;
}
