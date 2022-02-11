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
return V_2 -> V_5 . V_29 ;
}
void F_18 ( struct V_1 * V_2 , T_2 V_30 )
{
F_19 ( V_2 , V_30 ) ;
}
static int F_20 ( int V_31 )
{
switch ( V_31 ) {
case V_32 :
return V_33 ;
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
return V_39 ;
default:
break;
}
return V_40 ;
}
static void F_21 ( struct V_1 * V_2 ,
unsigned V_16 , bool V_41 , T_1 V_42 ,
bool V_43 )
{
T_1 V_44 ;
int V_45 , V_46 ;
F_22 ( V_47 , V_2 ) ;
if ( ! V_2 -> V_5 . V_48 . V_49 ) {
V_50:
V_2 -> V_5 . V_48 . V_49 = true ;
V_2 -> V_5 . V_48 . V_51 = V_41 ;
V_2 -> V_5 . V_48 . V_16 = V_16 ;
V_2 -> V_5 . V_48 . V_42 = V_42 ;
V_2 -> V_5 . V_48 . V_43 = V_43 ;
return;
}
V_44 = V_2 -> V_5 . V_48 . V_16 ;
if ( V_44 == V_52 ) {
F_22 ( V_53 , V_2 ) ;
return;
}
V_45 = F_20 ( V_44 ) ;
V_46 = F_20 ( V_16 ) ;
if ( ( V_45 == V_39 && V_46 == V_39 )
|| ( V_45 == V_33 && V_46 != V_40 ) ) {
V_2 -> V_5 . V_48 . V_49 = true ;
V_2 -> V_5 . V_48 . V_51 = true ;
V_2 -> V_5 . V_48 . V_16 = V_52 ;
V_2 -> V_5 . V_48 . V_42 = 0 ;
} else
goto V_50;
}
void F_23 ( struct V_1 * V_2 , unsigned V_16 )
{
F_21 ( V_2 , V_16 , false , 0 , false ) ;
}
void F_24 ( struct V_1 * V_2 , unsigned V_16 )
{
F_21 ( V_2 , V_16 , false , 0 , true ) ;
}
void F_25 ( struct V_1 * V_2 , int V_54 )
{
if ( V_54 )
F_26 ( V_2 , 0 ) ;
else
V_55 -> V_56 ( V_2 ) ;
}
void F_27 ( struct V_1 * V_2 , struct V_57 * V_58 )
{
++ V_2 -> V_59 . V_60 ;
V_2 -> V_5 . V_61 = V_58 -> V_62 ;
F_28 ( V_2 , V_32 , V_58 -> V_42 ) ;
}
void F_29 ( struct V_1 * V_2 , struct V_57 * V_58 )
{
if ( F_30 ( V_2 ) && ! V_58 -> V_63 )
V_2 -> V_5 . V_64 . V_65 ( V_2 , V_58 ) ;
else
V_2 -> V_5 . V_66 . V_65 ( V_2 , V_58 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
F_32 ( & V_2 -> V_5 . V_67 ) ;
F_22 ( V_68 , V_2 ) ;
}
void F_28 ( struct V_1 * V_2 , unsigned V_16 , T_1 V_42 )
{
F_21 ( V_2 , V_16 , true , V_42 , false ) ;
}
void F_33 ( struct V_1 * V_2 , unsigned V_16 , T_1 V_42 )
{
F_21 ( V_2 , V_16 , true , V_42 , true ) ;
}
bool F_34 ( struct V_1 * V_2 , int V_69 )
{
if ( V_55 -> V_70 ( V_2 ) <= V_69 )
return true ;
F_28 ( V_2 , V_38 , 0 ) ;
return false ;
}
int F_35 ( struct V_1 * V_2 , struct V_71 * V_66 ,
T_3 V_72 , void * V_30 , int V_73 , int V_74 ,
T_1 V_75 )
{
T_3 V_76 ;
T_4 V_77 ;
V_77 = F_36 ( V_72 ) ;
V_76 = V_66 -> V_78 ( V_2 , V_77 , V_75 ) ;
if ( V_76 == V_79 )
return - V_80 ;
V_76 = F_37 ( V_76 ) ;
return F_38 ( V_2 -> V_81 , V_76 , V_30 , V_73 , V_74 ) ;
}
int F_39 ( struct V_1 * V_2 , T_3 V_82 ,
void * V_30 , int V_73 , int V_74 , T_1 V_75 )
{
return F_35 ( V_2 , V_2 -> V_5 . V_83 , V_82 ,
V_30 , V_73 , V_74 , V_75 ) ;
}
int F_40 ( struct V_1 * V_2 , struct V_71 * V_66 , unsigned long V_84 )
{
T_3 V_85 = V_84 >> V_86 ;
unsigned V_73 = ( ( V_84 & ( V_87 - 1 ) ) >> 5 ) << 2 ;
int V_3 ;
int V_88 ;
T_2 V_89 [ F_41 ( V_66 -> V_90 ) ] ;
V_88 = F_35 ( V_2 , V_66 , V_85 , V_89 ,
V_73 * sizeof( T_2 ) , sizeof( V_89 ) ,
V_91 | V_92 ) ;
if ( V_88 < 0 ) {
V_88 = 0 ;
goto V_93;
}
for ( V_3 = 0 ; V_3 < F_41 ( V_89 ) ; ++ V_3 ) {
if ( F_42 ( V_89 [ V_3 ] ) &&
( V_89 [ V_3 ] & V_2 -> V_5 . V_66 . V_94 [ 0 ] [ 2 ] ) ) {
V_88 = 0 ;
goto V_93;
}
}
V_88 = 1 ;
memcpy ( V_66 -> V_90 , V_89 , sizeof( V_66 -> V_90 ) ) ;
F_43 ( V_95 ,
( unsigned long * ) & V_2 -> V_5 . V_96 ) ;
F_43 ( V_95 ,
( unsigned long * ) & V_2 -> V_5 . V_97 ) ;
V_93:
return V_88 ;
}
static bool F_44 ( struct V_1 * V_2 )
{
T_2 V_89 [ F_41 ( V_2 -> V_5 . V_83 -> V_90 ) ] ;
bool V_98 = true ;
int V_73 ;
T_3 V_82 ;
int V_99 ;
if ( F_45 ( V_2 ) || ! F_46 ( V_2 ) )
return false ;
if ( ! F_47 ( V_95 ,
( unsigned long * ) & V_2 -> V_5 . V_96 ) )
return true ;
V_82 = ( F_48 ( V_2 ) & ~ 31u ) >> V_86 ;
V_73 = ( F_48 ( V_2 ) & ~ 31u ) & ( V_87 - 1 ) ;
V_99 = F_39 ( V_2 , V_82 , V_89 , V_73 , sizeof( V_89 ) ,
V_91 | V_92 ) ;
if ( V_99 < 0 )
goto V_93;
V_98 = memcmp ( V_89 , V_2 -> V_5 . V_83 -> V_90 , sizeof( V_89 ) ) != 0 ;
V_93:
return V_98 ;
}
int F_49 ( struct V_1 * V_2 , unsigned long V_100 )
{
unsigned long V_101 = F_50 ( V_2 ) ;
unsigned long V_102 = V_103 | V_104 |
V_105 | V_106 ;
V_100 |= V_107 ;
#ifdef F_51
if ( V_100 & 0xffffffff00000000UL )
return 1 ;
#endif
V_100 &= ~ V_108 ;
if ( ( V_100 & V_106 ) && ! ( V_100 & V_105 ) )
return 1 ;
if ( ( V_100 & V_103 ) && ! ( V_100 & V_109 ) )
return 1 ;
if ( ! F_52 ( V_2 ) && ( V_100 & V_103 ) ) {
#ifdef F_51
if ( ( V_2 -> V_5 . V_110 & V_111 ) ) {
int V_112 , V_113 ;
if ( ! F_46 ( V_2 ) )
return 1 ;
V_55 -> V_114 ( V_2 , & V_112 , & V_113 ) ;
if ( V_113 )
return 1 ;
} else
#endif
if ( F_46 ( V_2 ) && ! F_40 ( V_2 , V_2 -> V_5 . V_83 ,
F_48 ( V_2 ) ) )
return 1 ;
}
if ( ! ( V_100 & V_103 ) && F_53 ( V_2 , V_115 ) )
return 1 ;
V_55 -> V_116 ( V_2 , V_100 ) ;
if ( ( V_100 ^ V_101 ) & V_103 ) {
F_54 ( V_2 ) ;
F_1 ( V_2 ) ;
}
if ( ( V_100 ^ V_101 ) & V_102 )
F_55 ( V_2 ) ;
return 0 ;
}
void F_56 ( struct V_1 * V_2 , unsigned long V_117 )
{
( void ) F_49 ( V_2 , F_57 ( V_2 , ~ 0x0eul ) | ( V_117 & 0x0f ) ) ;
}
int F_58 ( struct V_1 * V_2 , T_1 V_118 , T_2 V_119 )
{
T_2 V_120 ;
if ( V_118 != V_121 )
return 1 ;
V_120 = V_119 ;
if ( V_55 -> V_70 ( V_2 ) != 0 )
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
int F_59 ( struct V_1 * V_2 , T_1 V_118 , T_2 V_119 )
{
if ( F_58 ( V_2 , V_118 , V_119 ) ) {
F_26 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_60 ( struct V_1 * V_2 , unsigned long V_127 )
{
unsigned long V_128 = F_61 ( V_2 ) ;
unsigned long V_129 = V_130 | V_131 |
V_132 | V_133 ;
if ( V_127 & V_134 )
return 1 ;
if ( ! F_62 ( V_2 ) && ( V_127 & V_135 ) )
return 1 ;
if ( ! F_63 ( V_2 ) && ( V_127 & V_133 ) )
return 1 ;
if ( ! F_64 ( V_2 ) && ( V_127 & V_136 ) )
return 1 ;
if ( F_45 ( V_2 ) ) {
if ( ! ( V_127 & V_132 ) )
return 1 ;
} else if ( F_52 ( V_2 ) && ( V_127 & V_132 )
&& ( ( V_127 ^ V_128 ) & V_129 )
&& ! F_40 ( V_2 , V_2 -> V_5 . V_83 ,
F_48 ( V_2 ) ) )
return 1 ;
if ( ( V_127 & V_115 ) && ! ( V_128 & V_115 ) ) {
if ( ! F_65 ( V_2 ) )
return 1 ;
if ( ( F_48 ( V_2 ) & V_137 ) || ! F_45 ( V_2 ) )
return 1 ;
}
if ( V_55 -> V_138 ( V_2 , V_127 ) )
return 1 ;
if ( ( ( V_127 ^ V_128 ) & V_129 ) ||
( ! ( V_127 & V_115 ) && ( V_128 & V_115 ) ) )
F_55 ( V_2 ) ;
if ( ( V_127 ^ V_128 ) & V_135 )
F_66 ( V_2 ) ;
return 0 ;
}
int F_67 ( struct V_1 * V_2 , unsigned long V_84 )
{
if ( V_84 == F_48 ( V_2 ) && ! F_44 ( V_2 ) ) {
F_68 ( V_2 ) ;
F_69 ( V_2 ) ;
return 0 ;
}
if ( F_45 ( V_2 ) ) {
if ( F_61 ( V_2 ) & V_115 ) {
if ( V_84 & V_139 )
return 1 ;
} else
if ( V_84 & V_140 )
return 1 ;
} else {
if ( F_46 ( V_2 ) ) {
if ( V_84 & V_141 )
return 1 ;
if ( F_52 ( V_2 ) &&
! F_40 ( V_2 , V_2 -> V_5 . V_83 , V_84 ) )
return 1 ;
}
}
if ( F_70 ( ! F_71 ( V_2 -> V_81 , V_84 >> V_86 ) ) )
return 1 ;
V_2 -> V_5 . V_84 = V_84 ;
F_43 ( V_142 , ( V_143 * ) & V_2 -> V_5 . V_96 ) ;
V_2 -> V_5 . V_66 . V_144 ( V_2 ) ;
return 0 ;
}
int F_72 ( struct V_1 * V_2 , unsigned long V_145 )
{
if ( V_145 & V_146 )
return 1 ;
if ( F_73 ( V_2 -> V_81 ) )
F_74 ( V_2 , V_145 ) ;
else
V_2 -> V_5 . V_145 = V_145 ;
return 0 ;
}
unsigned long F_75 ( struct V_1 * V_2 )
{
if ( F_73 ( V_2 -> V_81 ) )
return F_76 ( V_2 ) ;
else
return V_2 -> V_5 . V_145 ;
}
static void F_77 ( struct V_1 * V_2 )
{
unsigned long V_147 ;
if ( V_2 -> V_148 & V_149 )
V_147 = V_2 -> V_5 . V_150 ;
else
V_147 = V_2 -> V_5 . V_147 ;
V_55 -> V_151 ( V_2 , V_147 ) ;
V_2 -> V_5 . V_152 = ( V_147 & V_153 ) ;
}
static int F_78 ( struct V_1 * V_2 , int V_154 , unsigned long V_155 )
{
switch ( V_154 ) {
case 0 ... 3 :
V_2 -> V_5 . V_156 [ V_154 ] = V_155 ;
if ( ! ( V_2 -> V_148 & V_149 ) )
V_2 -> V_5 . V_157 [ V_154 ] = V_155 ;
break;
case 4 :
if ( F_53 ( V_2 , V_158 ) )
return 1 ;
case 6 :
if ( V_155 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_159 = ( V_155 & V_160 ) | V_161 ;
break;
case 5 :
if ( F_53 ( V_2 , V_158 ) )
return 1 ;
default:
if ( V_155 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_147 = ( V_155 & V_162 ) | V_163 ;
F_77 ( V_2 ) ;
break;
}
return 0 ;
}
int F_79 ( struct V_1 * V_2 , int V_154 , unsigned long V_155 )
{
int V_164 ;
V_164 = F_78 ( V_2 , V_154 , V_155 ) ;
if ( V_164 > 0 )
F_23 ( V_2 , V_165 ) ;
else if ( V_164 < 0 )
F_26 ( V_2 , 0 ) ;
return V_164 ;
}
static int F_80 ( struct V_1 * V_2 , int V_154 , unsigned long * V_155 )
{
switch ( V_154 ) {
case 0 ... 3 :
* V_155 = V_2 -> V_5 . V_156 [ V_154 ] ;
break;
case 4 :
if ( F_53 ( V_2 , V_158 ) )
return 1 ;
case 6 :
* V_155 = V_2 -> V_5 . V_159 ;
break;
case 5 :
if ( F_53 ( V_2 , V_158 ) )
return 1 ;
default:
* V_155 = V_2 -> V_5 . V_147 ;
break;
}
return 0 ;
}
int F_81 ( struct V_1 * V_2 , int V_154 , unsigned long * V_155 )
{
if ( F_80 ( V_2 , V_154 , V_155 ) ) {
F_23 ( V_2 , V_165 ) ;
return 1 ;
}
return 0 ;
}
bool F_82 ( struct V_1 * V_2 )
{
T_1 V_166 = F_83 ( V_2 , V_167 ) ;
T_2 V_30 ;
int V_54 ;
V_54 = F_84 ( V_2 , V_166 , & V_30 ) ;
if ( V_54 )
return V_54 ;
F_85 ( V_2 , V_168 , ( T_1 ) V_30 ) ;
F_85 ( V_2 , V_169 , V_30 >> 32 ) ;
return V_54 ;
}
static int F_86 ( struct V_1 * V_2 , T_2 V_110 )
{
T_2 V_170 = V_2 -> V_5 . V_110 ;
if ( V_110 & V_171 )
return 1 ;
if ( F_52 ( V_2 )
&& ( V_2 -> V_5 . V_110 & V_111 ) != ( V_110 & V_111 ) )
return 1 ;
if ( V_110 & V_172 ) {
struct V_173 * V_174 ;
V_174 = F_87 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_174 || ! ( V_174 -> V_175 & F_88 ( V_176 ) ) )
return 1 ;
}
if ( V_110 & V_177 ) {
struct V_173 * V_174 ;
V_174 = F_87 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_174 || ! ( V_174 -> V_166 & F_88 ( V_178 ) ) )
return 1 ;
}
V_110 &= ~ V_179 ;
V_110 |= V_2 -> V_5 . V_110 & V_179 ;
V_55 -> F_86 ( V_2 , V_110 ) ;
V_2 -> V_5 . V_66 . V_180 . V_181 = ( V_110 & V_182 ) && ! V_183 ;
if ( ( V_110 ^ V_170 ) & V_182 )
F_55 ( V_2 ) ;
return 0 ;
}
void F_89 ( T_2 V_26 )
{
V_171 &= ~ V_26 ;
}
int F_90 ( struct V_1 * V_2 , T_1 V_184 , T_2 V_30 )
{
return V_55 -> V_185 ( V_2 , V_184 , V_30 ) ;
}
static int F_91 ( struct V_1 * V_2 , unsigned V_118 , T_2 * V_30 )
{
return F_90 ( V_2 , V_118 , * V_30 ) ;
}
static void F_92 ( struct V_81 * V_81 , T_4 V_186 )
{
int V_187 ;
int V_99 ;
struct V_188 V_189 ;
struct V_190 V_191 ;
if ( ! V_186 )
return;
V_99 = F_93 ( V_81 , V_186 , & V_187 , sizeof( V_187 ) ) ;
if ( V_99 )
return;
if ( V_187 & 1 )
++ V_187 ;
++ V_187 ;
F_94 ( V_81 , V_186 , & V_187 , sizeof( V_187 ) ) ;
F_95 ( & V_191 ) ;
if ( V_81 -> V_5 . V_192 ) {
struct V_190 V_193 = F_96 ( V_81 -> V_5 . V_192 ) ;
V_191 = F_97 ( V_191 , V_193 ) ;
}
V_189 . V_194 = V_191 . V_195 ;
V_189 . V_196 = V_191 . V_197 ;
V_189 . V_187 = V_187 ;
F_94 ( V_81 , V_186 , & V_189 , sizeof( V_189 ) ) ;
V_187 ++ ;
F_94 ( V_81 , V_186 , & V_187 , sizeof( V_187 ) ) ;
}
static T_5 F_98 ( T_5 V_198 , T_5 V_199 )
{
T_5 V_200 , V_201 ;
__asm__ ( "divl %4"
: "=a" (quotient), "=d" (remainder)
: "0" (0), "1" (dividend), "r" (divisor) );
return V_200 ;
}
static void F_99 ( T_5 V_202 , T_5 V_203 ,
T_6 * V_204 , T_1 * V_205 )
{
T_7 V_206 ;
T_8 V_207 = 0 ;
T_7 V_208 ;
T_5 V_209 ;
V_208 = V_203 * 1000LL ;
V_206 = V_202 * 1000LL ;
while ( V_208 > V_206 * 2 || V_208 & 0xffffffff00000000ULL ) {
V_208 >>= 1 ;
V_207 -- ;
}
V_209 = ( T_5 ) V_208 ;
while ( V_209 <= V_206 || V_206 & 0xffffffff00000000ULL ) {
if ( V_206 & 0xffffffff00000000ULL || V_209 & 0x80000000 )
V_206 >>= 1 ;
else
V_209 <<= 1 ;
V_207 ++ ;
}
* V_204 = V_207 ;
* V_205 = F_98 ( V_206 , V_209 ) ;
F_100 ( L_2 ,
V_210 , V_203 , V_202 , V_207 , * V_205 ) ;
}
static inline T_2 F_101 ( void )
{
struct V_190 V_193 ;
F_102 ( F_103 () ) ;
F_104 ( & V_193 ) ;
F_105 ( & V_193 ) ;
return F_106 ( & V_193 ) ;
}
static inline T_2 F_107 ( struct V_1 * V_2 , T_2 V_196 )
{
return F_108 ( V_196 , V_2 -> V_5 . V_211 ,
V_2 -> V_5 . V_212 ) ;
}
static T_1 F_109 ( T_1 V_213 , T_9 V_214 )
{
T_2 V_215 = ( T_2 ) V_213 * ( 1000000 + V_214 ) ;
F_110 ( V_215 , 1000000 ) ;
return V_215 ;
}
static void F_111 ( struct V_1 * V_2 , T_1 V_216 )
{
T_1 V_217 , V_218 ;
int V_219 = 0 ;
F_99 ( V_216 , V_220 / 1000 ,
& V_2 -> V_5 . V_212 ,
& V_2 -> V_5 . V_211 ) ;
V_2 -> V_5 . V_221 = V_216 ;
V_217 = F_109 ( V_222 , - V_223 ) ;
V_218 = F_109 ( V_222 , V_223 ) ;
if ( V_216 < V_217 || V_216 > V_218 ) {
F_100 ( L_3 , V_216 , V_217 , V_218 ) ;
V_219 = 1 ;
}
V_55 -> V_224 ( V_2 , V_216 , V_219 ) ;
}
static T_2 F_112 ( struct V_1 * V_2 , T_10 V_225 )
{
T_2 V_226 = F_108 ( V_225 - V_2 -> V_5 . V_227 ,
V_2 -> V_5 . V_211 ,
V_2 -> V_5 . V_212 ) ;
V_226 += V_2 -> V_5 . V_228 ;
return V_226 ;
}
void F_113 ( struct V_1 * V_2 , T_2 V_30 )
{
struct V_81 * V_81 = V_2 -> V_81 ;
T_2 V_73 , V_229 , V_230 ;
unsigned long V_231 ;
T_10 V_232 ;
F_114 ( & V_81 -> V_5 . V_233 , V_231 ) ;
V_73 = V_55 -> V_234 ( V_2 , V_30 ) ;
V_229 = F_101 () ;
V_230 = V_229 - V_81 -> V_5 . V_235 ;
V_232 = V_30 - V_81 -> V_5 . V_236 ;
#ifdef F_51
V_232 = ( V_232 * 1000 ) / V_2 -> V_5 . V_221 ;
#else
asm("idivl %2; xor %%edx, %%edx"
: "=A"(usdiff)
: "A"(usdiff * 1000), "rm"(vcpu->arch.virtual_tsc_khz));
#endif
F_110 ( V_230 , 1000 ) ;
V_232 -= V_230 ;
if ( V_232 < 0 )
V_232 = - V_232 ;
if ( V_232 < V_237 &&
V_2 -> V_5 . V_221 == V_81 -> V_5 . V_238 ) {
if ( ! F_115 () ) {
V_73 = V_81 -> V_5 . V_239 ;
F_100 ( L_4 , V_30 ) ;
} else {
T_2 V_240 = F_107 ( V_2 , V_230 ) ;
V_30 += V_240 ;
V_73 = V_55 -> V_234 ( V_2 , V_30 ) ;
F_100 ( L_5 , V_240 ) ;
}
} else {
V_81 -> V_5 . V_241 ++ ;
V_81 -> V_5 . V_242 = V_229 ;
V_81 -> V_5 . V_243 = V_30 ;
V_81 -> V_5 . V_239 = V_73 ;
F_100 ( L_6 ,
V_81 -> V_5 . V_241 , V_30 ) ;
}
V_81 -> V_5 . V_235 = V_229 ;
V_81 -> V_5 . V_236 = V_30 ;
V_81 -> V_5 . V_238 = V_2 -> V_5 . V_221 ;
V_2 -> V_5 . V_244 . V_245 = 0 ;
V_2 -> V_5 . V_246 = V_30 ;
V_2 -> V_5 . V_247 = V_81 -> V_5 . V_241 ;
V_2 -> V_5 . V_227 = V_81 -> V_5 . V_242 ;
V_2 -> V_5 . V_228 = V_81 -> V_5 . V_243 ;
V_55 -> V_248 ( V_2 , V_73 ) ;
F_116 ( & V_81 -> V_5 . V_233 , V_231 ) ;
}
static int F_117 ( struct V_1 * V_215 )
{
unsigned long V_231 ;
struct V_249 * V_2 = & V_215 -> V_5 ;
void * V_250 ;
unsigned long V_216 ;
T_10 V_225 , V_251 ;
T_2 V_245 ;
T_11 V_252 ;
F_118 ( V_231 ) ;
V_245 = V_55 -> V_253 ( V_215 ) ;
V_225 = F_101 () ;
V_216 = F_8 ( V_254 ) ;
if ( F_70 ( V_216 == 0 ) ) {
F_119 ( V_231 ) ;
F_22 ( V_255 , V_215 ) ;
return 1 ;
}
if ( V_2 -> V_256 ) {
T_2 V_226 = F_112 ( V_215 , V_225 ) ;
if ( V_226 > V_245 ) {
F_120 ( V_215 , V_226 - V_245 ) ;
V_245 = V_226 ;
}
}
F_119 ( V_231 ) ;
if ( ! V_2 -> V_257 )
return 0 ;
V_251 = 0 ;
if ( V_2 -> V_244 . V_245 ) {
V_251 = V_2 -> V_246 -
V_2 -> V_244 . V_245 ;
V_251 = F_108 ( V_251 ,
V_2 -> V_244 . V_258 ,
V_2 -> V_244 . V_259 ) ;
V_251 += V_2 -> V_260 ;
}
if ( F_70 ( V_2 -> V_261 != V_216 ) ) {
F_99 ( V_220 / 1000 , V_216 ,
& V_2 -> V_244 . V_259 ,
& V_2 -> V_244 . V_258 ) ;
V_2 -> V_261 = V_216 ;
}
if ( V_251 > V_225 )
V_225 = V_251 ;
V_2 -> V_244 . V_245 = V_245 ;
V_2 -> V_244 . V_262 = V_225 + V_215 -> V_81 -> V_5 . V_192 ;
V_2 -> V_260 = V_225 ;
V_2 -> V_246 = V_245 ;
V_252 = 0 ;
if ( V_2 -> V_263 ) {
V_252 |= V_264 ;
V_2 -> V_263 = false ;
}
V_2 -> V_244 . V_231 = V_252 ;
V_2 -> V_244 . V_187 += 2 ;
V_250 = F_121 ( V_2 -> V_257 ) ;
memcpy ( V_250 + V_2 -> V_265 , & V_2 -> V_244 ,
sizeof( V_2 -> V_244 ) ) ;
F_122 ( V_250 ) ;
F_123 ( V_215 -> V_81 , V_2 -> time >> V_86 ) ;
return 0 ;
}
static bool F_124 ( unsigned V_21 )
{
switch ( V_21 ) {
case 0x200 ... 0x200 + 2 * V_266 - 1 :
case V_267 :
case V_268 :
case V_269 :
case V_270 :
case V_271 :
case V_272 :
case V_273 :
case V_274 :
case V_275 :
case V_276 :
case V_277 :
case V_278 :
case V_279 :
return true ;
case 0x2f8 :
return true ;
}
return false ;
}
static bool F_125 ( unsigned V_280 )
{
return V_280 < 8 && ( 1 << V_280 ) & 0xf3 ;
}
static bool F_126 ( unsigned V_280 )
{
return V_280 < 8 && ( 1 << V_280 ) & 0x73 ;
}
static bool F_127 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_30 )
{
int V_3 ;
if ( ! F_124 ( V_21 ) )
return false ;
if ( V_21 == V_279 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_125 ( ( V_30 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
} else if ( V_21 == V_278 ) {
if ( V_30 & ~ 0xcff )
return false ;
return F_126 ( V_30 & 0xff ) ;
} else if ( V_21 >= V_267 && V_21 <= V_277 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_126 ( ( V_30 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
}
return F_126 ( V_30 & 0xff ) ;
}
static int F_128 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_30 )
{
T_2 * V_281 = ( T_2 * ) & V_2 -> V_5 . V_282 . V_283 ;
if ( ! F_127 ( V_2 , V_21 , V_30 ) )
return 1 ;
if ( V_21 == V_278 ) {
V_2 -> V_5 . V_282 . V_284 = V_30 ;
V_2 -> V_5 . V_282 . V_285 = ( V_30 & 0xc00 ) >> 10 ;
} else if ( V_21 == V_267 )
V_281 [ 0 ] = V_30 ;
else if ( V_21 == V_268 || V_21 == V_269 )
V_281 [ 1 + V_21 - V_268 ] = V_30 ;
else if ( V_21 >= V_270 && V_21 <= V_277 )
V_281 [ 3 + V_21 - V_270 ] = V_30 ;
else if ( V_21 == V_279 )
V_2 -> V_5 . V_286 = V_30 ;
else {
int V_287 , V_288 ;
T_2 * V_289 ;
V_287 = ( V_21 - 0x200 ) / 2 ;
V_288 = V_21 - 0x200 - 2 * V_287 ;
if ( ! V_288 )
V_289 =
( T_2 * ) & V_2 -> V_5 . V_282 . V_290 [ V_287 ] . V_291 ;
else
V_289 =
( T_2 * ) & V_2 -> V_5 . V_282 . V_290 [ V_287 ] . V_292 ;
* V_289 = V_30 ;
}
F_55 ( V_2 ) ;
return 0 ;
}
static int F_129 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_30 )
{
T_2 V_293 = V_2 -> V_5 . V_293 ;
unsigned V_294 = V_293 & 0xff ;
switch ( V_21 ) {
case V_295 :
V_2 -> V_5 . V_296 = V_30 ;
break;
case V_297 :
if ( ! ( V_293 & V_298 ) )
return 1 ;
if ( V_30 != 0 && V_30 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_299 = V_30 ;
break;
default:
if ( V_21 >= V_300 &&
V_21 < V_300 + 4 * V_294 ) {
T_1 V_73 = V_21 - V_300 ;
if ( ( V_73 & 0x3 ) == 0 &&
V_30 != 0 && ( V_30 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_301 [ V_73 ] = V_30 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_130 ( struct V_1 * V_2 , T_2 V_30 )
{
struct V_81 * V_81 = V_2 -> V_81 ;
int V_302 = F_45 ( V_2 ) ;
T_11 * V_303 = V_302 ? ( T_11 * ) ( long ) V_81 -> V_5 . F_130 . V_304
: ( T_11 * ) ( long ) V_81 -> V_5 . F_130 . V_305 ;
T_11 V_306 = V_302 ? V_81 -> V_5 . F_130 . V_307
: V_81 -> V_5 . F_130 . V_308 ;
T_1 V_309 = V_30 & ~ V_310 ;
T_2 V_311 = V_30 & V_310 ;
T_11 * V_312 ;
int V_99 ;
V_99 = - V_313 ;
if ( V_309 >= V_306 )
goto V_93;
V_99 = - V_314 ;
V_312 = F_131 ( V_303 + ( V_309 * V_87 ) , V_87 ) ;
if ( F_132 ( V_312 ) ) {
V_99 = F_133 ( V_312 ) ;
goto V_93;
}
if ( F_94 ( V_81 , V_311 , V_312 , V_87 ) )
goto V_315;
V_99 = 0 ;
V_315:
F_134 ( V_312 ) ;
V_93:
return V_99 ;
}
static bool F_135 ( struct V_81 * V_81 )
{
return V_81 -> V_5 . V_316 & V_317 ;
}
static bool F_136 ( T_1 V_21 )
{
bool V_99 = false ;
switch ( V_21 ) {
case V_318 :
case V_319 :
V_99 = true ;
break;
}
return V_99 ;
}
static int F_137 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_30 )
{
struct V_81 * V_81 = V_2 -> V_81 ;
switch ( V_21 ) {
case V_318 :
V_81 -> V_5 . V_320 = V_30 ;
if ( ! V_81 -> V_5 . V_320 )
V_81 -> V_5 . V_316 &= ~ V_317 ;
break;
case V_319 : {
T_2 V_82 ;
unsigned long V_321 ;
T_11 V_322 [ 4 ] ;
if ( ! V_81 -> V_5 . V_320 )
break;
if ( ! ( V_30 & V_317 ) ) {
V_81 -> V_5 . V_316 = V_30 ;
break;
}
V_82 = V_30 >> V_323 ;
V_321 = F_138 ( V_81 , V_82 ) ;
if ( F_139 ( V_321 ) )
return 1 ;
V_55 -> V_324 ( V_2 , V_322 ) ;
( ( unsigned char * ) V_322 ) [ 3 ] = 0xc3 ;
if ( F_140 ( ( void V_325 * ) V_321 , V_322 , 4 ) )
return 1 ;
V_81 -> V_5 . V_316 = V_30 ;
break;
}
default:
F_141 ( V_2 , L_7
L_8 , V_21 , V_30 ) ;
return 1 ;
}
return 0 ;
}
static int F_142 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_30 )
{
switch ( V_21 ) {
case V_326 : {
unsigned long V_321 ;
if ( ! ( V_30 & V_327 ) ) {
V_2 -> V_5 . V_328 = V_30 ;
break;
}
V_321 = F_138 ( V_2 -> V_81 , V_30 >>
V_329 ) ;
if ( F_139 ( V_321 ) )
return 1 ;
if ( F_143 ( ( void V_325 * ) V_321 , V_87 ) )
return 1 ;
V_2 -> V_5 . V_328 = V_30 ;
break;
}
case V_330 :
return F_144 ( V_2 , V_331 , V_30 ) ;
case V_332 :
return F_144 ( V_2 , V_333 , V_30 ) ;
case V_334 :
return F_144 ( V_2 , V_335 , V_30 ) ;
default:
F_141 ( V_2 , L_7
L_8 , V_21 , V_30 ) ;
return 1 ;
}
return 0 ;
}
static int F_145 ( struct V_1 * V_2 , T_2 V_30 )
{
T_4 V_336 = V_30 & ~ 0x3f ;
if ( V_30 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_337 = V_30 ;
if ( ! ( V_30 & V_338 ) ) {
F_54 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_146 ( V_2 -> V_81 , & V_2 -> V_5 . V_6 . V_30 , V_336 ) )
return 1 ;
V_2 -> V_5 . V_6 . V_339 = ! ( V_30 & V_340 ) ;
F_147 ( V_2 ) ;
return 0 ;
}
static void F_148 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_257 ) {
F_149 ( V_2 -> V_5 . V_257 ) ;
V_2 -> V_5 . V_257 = NULL ;
}
}
static void F_150 ( struct V_1 * V_2 )
{
T_2 V_240 ;
if ( ! ( V_2 -> V_5 . V_341 . V_337 & V_342 ) )
return;
V_240 = V_343 -> V_344 . V_345 - V_2 -> V_5 . V_341 . V_346 ;
V_2 -> V_5 . V_341 . V_346 = V_343 -> V_344 . V_345 ;
V_2 -> V_5 . V_341 . V_347 = V_240 ;
}
static void F_151 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_341 . V_337 & V_342 ) )
return;
if ( F_70 ( F_152 ( V_2 -> V_81 , & V_2 -> V_5 . V_341 . V_348 ,
& V_2 -> V_5 . V_341 . V_349 , sizeof( struct V_350 ) ) ) )
return;
V_2 -> V_5 . V_341 . V_349 . V_349 += V_2 -> V_5 . V_341 . V_347 ;
V_2 -> V_5 . V_341 . V_349 . V_187 += 2 ;
V_2 -> V_5 . V_341 . V_347 = 0 ;
F_153 ( V_2 -> V_81 , & V_2 -> V_5 . V_341 . V_348 ,
& V_2 -> V_5 . V_341 . V_349 , sizeof( struct V_350 ) ) ;
}
int F_154 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_30 )
{
bool V_351 = false ;
switch ( V_21 ) {
case V_352 :
return F_86 ( V_2 , V_30 ) ;
case V_353 :
V_30 &= ~ ( T_2 ) 0x40 ;
V_30 &= ~ ( T_2 ) 0x100 ;
V_30 &= ~ ( T_2 ) 0x8 ;
if ( V_30 != 0 ) {
F_141 ( V_2 , L_9 ,
V_30 ) ;
return 1 ;
}
break;
case V_354 :
if ( V_30 != 0 ) {
F_141 ( V_2 , L_10
L_11 , V_30 ) ;
return 1 ;
}
break;
case V_355 :
break;
case V_356 :
if ( ! V_30 ) {
break;
} else if ( V_30 & ~ ( V_357 | V_358 ) ) {
return 1 ;
}
F_141 ( V_2 , L_12 ,
V_210 , V_30 ) ;
break;
case V_359 :
case V_360 :
case V_361 :
case V_362 :
break;
case 0x200 ... 0x2ff :
return F_128 ( V_2 , V_21 , V_30 ) ;
case V_363 :
F_18 ( V_2 , V_30 ) ;
break;
case V_364 ... V_364 + 0x3ff :
return F_155 ( V_2 , V_21 , V_30 ) ;
case V_365 :
F_156 ( V_2 , V_30 ) ;
break;
case V_366 :
V_2 -> V_5 . V_367 = V_30 ;
break;
case V_368 :
case V_369 :
V_2 -> V_81 -> V_5 . V_186 = V_30 ;
F_92 ( V_2 -> V_81 , V_30 ) ;
break;
case V_370 :
case V_371 : {
F_148 ( V_2 ) ;
V_2 -> V_5 . time = V_30 ;
F_22 ( V_255 , V_2 ) ;
if ( ! ( V_30 & 1 ) )
break;
V_2 -> V_5 . V_265 = V_30 & ~ ( V_310 | 1 ) ;
V_2 -> V_5 . V_257 =
F_157 ( V_2 -> V_81 , V_30 >> V_86 ) ;
if ( F_158 ( V_2 -> V_5 . V_257 ) )
V_2 -> V_5 . V_257 = NULL ;
break;
}
case V_372 :
if ( F_145 ( V_2 , V_30 ) )
return 1 ;
break;
case V_373 :
if ( F_70 ( ! F_159 () ) )
return 1 ;
if ( V_30 & V_374 )
return 1 ;
if ( F_146 ( V_2 -> V_81 , & V_2 -> V_5 . V_341 . V_348 ,
V_30 & V_375 ) )
return 1 ;
V_2 -> V_5 . V_341 . V_337 = V_30 ;
if ( ! ( V_30 & V_342 ) )
break;
V_2 -> V_5 . V_341 . V_346 = V_343 -> V_344 . V_345 ;
F_160 () ;
F_150 ( V_2 ) ;
F_161 () ;
F_22 ( V_376 , V_2 ) ;
break;
case V_377 :
if ( F_162 ( V_2 , V_30 ) )
return 1 ;
break;
case V_297 :
case V_295 :
case V_300 ... V_300 + 4 * V_378 - 1 :
return F_129 ( V_2 , V_21 , V_30 ) ;
case V_379 :
case V_380 :
case V_381 :
case V_382 :
if ( V_30 != 0 )
F_141 ( V_2 , L_13
L_14 , V_21 , V_30 ) ;
break;
case V_383 :
case V_384 :
case V_385 :
case V_386 :
F_141 ( V_2 , L_13
L_14 , V_21 , V_30 ) ;
break;
case V_387 :
case V_388 :
V_351 = true ;
case V_389 :
case V_390 :
if ( F_163 ( V_2 , V_21 ) )
return F_164 ( V_2 , V_21 , V_30 ) ;
if ( V_351 || V_30 != 0 )
F_141 ( V_2 , L_15
L_14 , V_21 , V_30 ) ;
break;
case V_391 :
break;
case V_318 ... V_392 :
if ( F_136 ( V_21 ) ) {
int V_99 ;
F_165 ( & V_2 -> V_81 -> V_393 ) ;
V_99 = F_137 ( V_2 , V_21 , V_30 ) ;
F_166 ( & V_2 -> V_81 -> V_393 ) ;
return V_99 ;
} else
return F_142 ( V_2 , V_21 , V_30 ) ;
break;
case V_394 :
F_141 ( V_2 , L_16 , V_21 , V_30 ) ;
break;
case V_395 :
if ( ! F_167 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_396 . V_397 = V_30 ;
break;
case V_398 :
if ( ! F_167 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_396 . V_399 = V_30 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_81 -> V_5 . F_130 . V_21 ) )
return F_130 ( V_2 , V_30 ) ;
if ( F_163 ( V_2 , V_21 ) )
return F_164 ( V_2 , V_21 , V_30 ) ;
if ( ! V_400 ) {
F_141 ( V_2 , L_17 ,
V_21 , V_30 ) ;
return 1 ;
} else {
F_141 ( V_2 , L_16 ,
V_21 , V_30 ) ;
break;
}
}
return 0 ;
}
int F_168 ( struct V_1 * V_2 , T_1 V_184 , T_2 * V_401 )
{
return V_55 -> V_402 ( V_2 , V_184 , V_401 ) ;
}
static int F_169 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_401 )
{
T_2 * V_281 = ( T_2 * ) & V_2 -> V_5 . V_282 . V_283 ;
if ( ! F_124 ( V_21 ) )
return 1 ;
if ( V_21 == V_278 )
* V_401 = V_2 -> V_5 . V_282 . V_284 +
( V_2 -> V_5 . V_282 . V_285 << 10 ) ;
else if ( V_21 == V_267 )
* V_401 = V_281 [ 0 ] ;
else if ( V_21 == V_268 || V_21 == V_269 )
* V_401 = V_281 [ 1 + V_21 - V_268 ] ;
else if ( V_21 >= V_270 && V_21 <= V_277 )
* V_401 = V_281 [ 3 + V_21 - V_270 ] ;
else if ( V_21 == V_279 )
* V_401 = V_2 -> V_5 . V_286 ;
else {
int V_287 , V_288 ;
T_2 * V_289 ;
V_287 = ( V_21 - 0x200 ) / 2 ;
V_288 = V_21 - 0x200 - 2 * V_287 ;
if ( ! V_288 )
V_289 =
( T_2 * ) & V_2 -> V_5 . V_282 . V_290 [ V_287 ] . V_291 ;
else
V_289 =
( T_2 * ) & V_2 -> V_5 . V_282 . V_290 [ V_287 ] . V_292 ;
* V_401 = * V_289 ;
}
return 0 ;
}
static int F_170 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_401 )
{
T_2 V_30 ;
T_2 V_293 = V_2 -> V_5 . V_293 ;
unsigned V_294 = V_293 & 0xff ;
switch ( V_21 ) {
case V_403 :
case V_404 :
V_30 = 0 ;
break;
case V_405 :
V_30 = V_2 -> V_5 . V_293 ;
break;
case V_297 :
if ( ! ( V_293 & V_298 ) )
return 1 ;
V_30 = V_2 -> V_5 . V_299 ;
break;
case V_295 :
V_30 = V_2 -> V_5 . V_296 ;
break;
default:
if ( V_21 >= V_300 &&
V_21 < V_300 + 4 * V_294 ) {
T_1 V_73 = V_21 - V_300 ;
V_30 = V_2 -> V_5 . V_301 [ V_73 ] ;
break;
}
return 1 ;
}
* V_401 = V_30 ;
return 0 ;
}
static int F_171 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_401 )
{
T_2 V_30 = 0 ;
struct V_81 * V_81 = V_2 -> V_81 ;
switch ( V_21 ) {
case V_318 :
V_30 = V_81 -> V_5 . V_320 ;
break;
case V_319 :
V_30 = V_81 -> V_5 . V_316 ;
break;
default:
F_141 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_401 = V_30 ;
return 0 ;
}
static int F_172 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_401 )
{
T_2 V_30 = 0 ;
switch ( V_21 ) {
case V_406 : {
int V_99 ;
struct V_1 * V_215 ;
F_173 (r, v, vcpu->kvm)
if ( V_215 == V_2 )
V_30 = V_99 ;
break;
}
case V_330 :
return F_174 ( V_2 , V_331 , V_401 ) ;
case V_332 :
return F_174 ( V_2 , V_333 , V_401 ) ;
case V_334 :
return F_174 ( V_2 , V_335 , V_401 ) ;
case V_326 :
V_30 = V_2 -> V_5 . V_328 ;
break;
default:
F_141 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_401 = V_30 ;
return 0 ;
}
int F_175 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_401 )
{
T_2 V_30 ;
switch ( V_21 ) {
case V_407 :
case V_408 :
case V_356 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
case V_413 :
case V_353 :
case V_361 :
case V_379 :
case V_383 :
case V_414 :
case V_355 :
case V_354 :
V_30 = 0 ;
break;
case V_387 :
case V_388 :
case V_389 :
case V_390 :
if ( F_163 ( V_2 , V_21 ) )
return F_176 ( V_2 , V_21 , V_401 ) ;
V_30 = 0 ;
break;
case V_359 :
V_30 = 0x100000000ULL ;
break;
case V_415 :
V_30 = 0x500 | V_266 ;
break;
case 0x200 ... 0x2ff :
return F_169 ( V_2 , V_21 , V_401 ) ;
case 0xcd :
V_30 = 3 ;
break;
case V_416 :
V_30 = 1 << 24 ;
break;
case V_363 :
V_30 = F_17 ( V_2 ) ;
break;
case V_364 ... V_364 + 0x3ff :
return F_177 ( V_2 , V_21 , V_401 ) ;
break;
case V_365 :
V_30 = F_178 ( V_2 ) ;
break;
case V_366 :
V_30 = V_2 -> V_5 . V_367 ;
break;
case V_417 :
V_30 = 1000ULL ;
V_30 |= ( ( ( T_7 ) 4ULL ) << 40 ) ;
break;
case V_352 :
V_30 = V_2 -> V_5 . V_110 ;
break;
case V_369 :
case V_368 :
V_30 = V_2 -> V_81 -> V_5 . V_186 ;
break;
case V_371 :
case V_370 :
V_30 = V_2 -> V_5 . time ;
break;
case V_372 :
V_30 = V_2 -> V_5 . V_6 . V_337 ;
break;
case V_373 :
V_30 = V_2 -> V_5 . V_341 . V_337 ;
break;
case V_377 :
V_30 = V_2 -> V_5 . V_418 . V_337 ;
break;
case V_403 :
case V_404 :
case V_405 :
case V_297 :
case V_295 :
case V_300 ... V_300 + 4 * V_378 - 1 :
return F_170 ( V_2 , V_21 , V_401 ) ;
case V_391 :
V_30 = 0x20000000 ;
break;
case V_318 ... V_392 :
if ( F_136 ( V_21 ) ) {
int V_99 ;
F_165 ( & V_2 -> V_81 -> V_393 ) ;
V_99 = F_171 ( V_2 , V_21 , V_401 ) ;
F_166 ( & V_2 -> V_81 -> V_393 ) ;
return V_99 ;
} else
return F_172 ( V_2 , V_21 , V_401 ) ;
break;
case V_394 :
V_30 = 0xbe702111 ;
break;
case V_395 :
if ( ! F_167 ( V_2 ) )
return 1 ;
V_30 = V_2 -> V_5 . V_396 . V_397 ;
break;
case V_398 :
if ( ! F_167 ( V_2 ) )
return 1 ;
V_30 = V_2 -> V_5 . V_396 . V_399 ;
break;
default:
if ( F_163 ( V_2 , V_21 ) )
return F_176 ( V_2 , V_21 , V_401 ) ;
if ( ! V_400 ) {
F_141 ( V_2 , L_19 , V_21 ) ;
return 1 ;
} else {
F_141 ( V_2 , L_20 , V_21 ) ;
V_30 = 0 ;
}
break;
}
* V_401 = V_30 ;
return 0 ;
}
static int F_179 ( struct V_1 * V_2 , struct V_419 * V_19 ,
struct V_420 * V_421 ,
int (* F_180)( struct V_1 * V_2 ,
unsigned V_118 , T_2 * V_30 ) )
{
int V_3 , V_287 ;
V_287 = F_181 ( & V_2 -> V_81 -> V_422 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_423 ; ++ V_3 )
if ( F_180 ( V_2 , V_421 [ V_3 ] . V_118 , & V_421 [ V_3 ] . V_30 ) )
break;
F_182 ( & V_2 -> V_81 -> V_422 , V_287 ) ;
return V_3 ;
}
static int F_183 ( struct V_1 * V_2 , struct V_419 V_325 * V_424 ,
int (* F_180)( struct V_1 * V_2 ,
unsigned V_118 , T_2 * V_30 ) ,
int V_425 )
{
struct V_419 V_19 ;
struct V_420 * V_421 ;
int V_99 , V_426 ;
unsigned V_427 ;
V_99 = - V_80 ;
if ( F_184 ( & V_19 , V_424 , sizeof V_19 ) )
goto V_93;
V_99 = - V_313 ;
if ( V_19 . V_423 >= V_428 )
goto V_93;
V_427 = sizeof( struct V_420 ) * V_19 . V_423 ;
V_421 = F_131 ( V_424 -> V_421 , V_427 ) ;
if ( F_132 ( V_421 ) ) {
V_99 = F_133 ( V_421 ) ;
goto V_93;
}
V_99 = V_426 = F_179 ( V_2 , & V_19 , V_421 , F_180 ) ;
if ( V_99 < 0 )
goto V_315;
V_99 = - V_80 ;
if ( V_425 && F_185 ( V_424 -> V_421 , V_421 , V_427 ) )
goto V_315;
V_99 = V_426 ;
V_315:
F_134 ( V_421 ) ;
V_93:
return V_99 ;
}
int F_186 ( long V_429 )
{
int V_99 ;
switch ( V_429 ) {
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
case V_459 :
case V_460 :
case V_461 :
case V_462 :
case V_463 :
case V_464 :
V_99 = 1 ;
break;
case V_465 :
V_99 = V_466 ;
break;
case V_467 :
V_99 = ! V_55 -> V_468 () ;
break;
case V_469 :
V_99 = V_470 ;
break;
case V_471 :
V_99 = V_472 ;
break;
case V_473 :
V_99 = V_474 ;
break;
case V_475 :
V_99 = 0 ;
break;
case V_476 :
V_99 = F_187 ( & V_477 ) ;
break;
case V_478 :
V_99 = V_378 ;
break;
case V_479 :
V_99 = V_480 ;
break;
case V_481 :
V_99 = V_482 ;
break;
case V_483 :
V_99 = F_188 ( V_484 ) ;
break;
default:
V_99 = 0 ;
break;
}
return V_99 ;
}
long F_189 ( struct V_485 * V_486 ,
unsigned int V_487 , unsigned long V_488 )
{
void V_325 * V_489 = ( void V_325 * ) V_488 ;
long V_99 ;
switch ( V_487 ) {
case V_490 : {
struct V_491 V_325 * V_492 = V_489 ;
struct V_491 V_493 ;
unsigned V_426 ;
V_99 = - V_80 ;
if ( F_184 ( & V_493 , V_492 , sizeof V_493 ) )
goto V_93;
V_426 = V_493 . V_423 ;
V_493 . V_423 = V_494 + F_41 ( V_495 ) ;
if ( F_185 ( V_492 , & V_493 , sizeof V_493 ) )
goto V_93;
V_99 = - V_313 ;
if ( V_426 < V_493 . V_423 )
goto V_93;
V_99 = - V_80 ;
if ( F_185 ( V_492 -> V_496 , & V_497 ,
V_494 * sizeof( T_1 ) ) )
goto V_93;
if ( F_185 ( V_492 -> V_496 + V_494 ,
& V_495 ,
F_41 ( V_495 ) * sizeof( T_1 ) ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_498 : {
struct V_499 V_325 * V_500 = V_489 ;
struct V_499 V_501 ;
V_99 = - V_80 ;
if ( F_184 ( & V_501 , V_500 , sizeof V_501 ) )
goto V_93;
V_99 = F_190 ( & V_501 ,
V_500 -> V_421 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_80 ;
if ( F_185 ( V_500 , & V_501 , sizeof V_501 ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_502 : {
T_2 V_503 ;
V_503 = V_504 ;
V_99 = - V_80 ;
if ( F_185 ( V_489 , & V_503 , sizeof V_503 ) )
goto V_93;
V_99 = 0 ;
break;
}
default:
V_99 = - V_505 ;
}
V_93:
return V_99 ;
}
static void F_191 ( void * V_506 )
{
F_192 () ;
}
static bool F_193 ( struct V_1 * V_2 )
{
return V_2 -> V_81 -> V_5 . V_507 &&
! ( V_2 -> V_81 -> V_5 . V_508 & V_509 ) ;
}
void F_194 ( struct V_1 * V_2 , int V_510 )
{
if ( F_193 ( V_2 ) ) {
if ( V_55 -> V_511 () )
F_195 ( V_510 , V_2 -> V_5 . V_512 ) ;
else if ( V_2 -> V_510 != - 1 && V_2 -> V_510 != V_510 )
F_196 ( V_2 -> V_510 ,
F_191 , NULL , 1 ) ;
}
V_55 -> V_513 ( V_2 , V_510 ) ;
if ( F_70 ( V_2 -> V_5 . V_514 ) ) {
F_197 ( V_2 , V_2 -> V_5 . V_514 ) ;
V_2 -> V_5 . V_514 = 0 ;
F_198 ( V_255 , & V_2 -> V_515 ) ;
}
if ( F_70 ( V_2 -> V_510 != V_510 ) || F_115 () ) {
T_10 V_516 = ! V_2 -> V_5 . V_517 ? 0 :
F_199 () - V_2 -> V_5 . V_517 ;
if ( V_516 < 0 )
F_200 ( L_21 ) ;
if ( F_115 () ) {
T_2 V_73 = V_55 -> V_234 ( V_2 ,
V_2 -> V_5 . V_246 ) ;
V_55 -> V_248 ( V_2 , V_73 ) ;
V_2 -> V_5 . V_256 = 1 ;
}
F_22 ( V_255 , V_2 ) ;
if ( V_2 -> V_510 != V_510 )
F_201 ( V_2 ) ;
V_2 -> V_510 = V_510 ;
}
F_150 ( V_2 ) ;
F_22 ( V_376 , V_2 ) ;
}
void F_202 ( struct V_1 * V_2 )
{
V_55 -> V_518 ( V_2 ) ;
F_203 ( V_2 ) ;
V_2 -> V_5 . V_517 = F_199 () ;
}
static int F_204 ( struct V_1 * V_2 ,
struct V_519 * V_520 )
{
memcpy ( V_520 -> V_521 , V_2 -> V_5 . V_522 -> V_521 , sizeof *V_520 ) ;
return 0 ;
}
static int F_205 ( struct V_1 * V_2 ,
struct V_519 * V_520 )
{
F_206 ( V_2 , V_520 ) ;
F_207 ( V_2 ) ;
return 0 ;
}
static int F_208 ( struct V_1 * V_2 ,
struct V_523 * V_524 )
{
if ( V_524 -> V_524 < 0 || V_524 -> V_524 >= V_525 )
return - V_505 ;
if ( F_73 ( V_2 -> V_81 ) )
return - V_526 ;
F_209 ( V_2 , V_524 -> V_524 , false ) ;
F_22 ( V_47 , V_2 ) ;
return 0 ;
}
static int F_210 ( struct V_1 * V_2 )
{
F_31 ( V_2 ) ;
return 0 ;
}
static int F_211 ( struct V_1 * V_2 ,
struct V_527 * V_528 )
{
if ( V_528 -> V_231 )
return - V_505 ;
V_2 -> V_5 . V_529 = ! ! V_528 -> V_285 ;
return 0 ;
}
static int F_212 ( struct V_1 * V_2 ,
T_2 V_293 )
{
int V_99 ;
unsigned V_294 = V_293 & 0xff , V_530 ;
V_99 = - V_505 ;
if ( ! V_294 || V_294 >= V_378 )
goto V_93;
if ( V_293 & ~ ( V_504 | 0xff | 0xff0000 ) )
goto V_93;
V_99 = 0 ;
V_2 -> V_5 . V_293 = V_293 ;
if ( V_293 & V_298 )
V_2 -> V_5 . V_299 = ~ ( T_2 ) 0 ;
for ( V_530 = 0 ; V_530 < V_294 ; V_530 ++ )
V_2 -> V_5 . V_301 [ V_530 * 4 ] = ~ ( T_2 ) 0 ;
V_93:
return V_99 ;
}
static int F_213 ( struct V_1 * V_2 ,
struct V_531 * V_532 )
{
T_2 V_293 = V_2 -> V_5 . V_293 ;
unsigned V_294 = V_293 & 0xff ;
T_2 * V_533 = V_2 -> V_5 . V_301 ;
if ( V_532 -> V_530 >= V_294 || ! ( V_532 -> V_399 & V_534 ) )
return - V_505 ;
if ( ( V_532 -> V_399 & V_535 ) && ( V_293 & V_298 ) &&
V_2 -> V_5 . V_299 != ~ ( T_2 ) 0 )
return 0 ;
V_533 += 4 * V_532 -> V_530 ;
if ( ( V_532 -> V_399 & V_535 ) && V_533 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_532 -> V_399 & V_535 ) {
if ( ( V_2 -> V_5 . V_296 & V_536 ) ||
! F_53 ( V_2 , V_537 ) ) {
F_22 ( V_53 , V_2 ) ;
return 0 ;
}
if ( V_533 [ 1 ] & V_534 )
V_532 -> V_399 |= V_538 ;
V_533 [ 2 ] = V_532 -> V_321 ;
V_533 [ 3 ] = V_532 -> V_539 ;
V_2 -> V_5 . V_296 = V_532 -> V_296 ;
V_533 [ 1 ] = V_532 -> V_399 ;
F_23 ( V_2 , V_540 ) ;
} else if ( ! ( V_533 [ 1 ] & V_534 )
|| ! ( V_533 [ 1 ] & V_535 ) ) {
if ( V_533 [ 1 ] & V_534 )
V_532 -> V_399 |= V_538 ;
V_533 [ 2 ] = V_532 -> V_321 ;
V_533 [ 3 ] = V_532 -> V_539 ;
V_533 [ 1 ] = V_532 -> V_399 ;
} else
V_533 [ 1 ] |= V_538 ;
return 0 ;
}
static void F_214 ( struct V_1 * V_2 ,
struct V_541 * V_542 )
{
F_215 ( V_2 ) ;
V_542 -> V_48 . V_543 =
V_2 -> V_5 . V_48 . V_49 &&
! F_216 ( V_2 -> V_5 . V_48 . V_16 ) ;
V_542 -> V_48 . V_16 = V_2 -> V_5 . V_48 . V_16 ;
V_542 -> V_48 . V_51 = V_2 -> V_5 . V_48 . V_51 ;
V_542 -> V_48 . V_544 = 0 ;
V_542 -> V_48 . V_42 = V_2 -> V_5 . V_48 . V_42 ;
V_542 -> V_545 . V_543 =
V_2 -> V_5 . V_545 . V_49 && ! V_2 -> V_5 . V_545 . V_546 ;
V_542 -> V_545 . V_16 = V_2 -> V_5 . V_545 . V_16 ;
V_542 -> V_545 . V_546 = 0 ;
V_542 -> V_545 . V_547 =
V_55 -> V_548 ( V_2 ,
V_549 | V_550 ) ;
V_542 -> V_551 . V_543 = V_2 -> V_5 . V_552 ;
V_542 -> V_551 . V_49 = V_2 -> V_5 . V_553 != 0 ;
V_542 -> V_551 . V_554 = V_55 -> V_555 ( V_2 ) ;
V_542 -> V_551 . V_544 = 0 ;
V_542 -> V_556 = V_2 -> V_5 . V_556 ;
V_542 -> V_231 = ( V_557
| V_558
| V_559 ) ;
memset ( & V_542 -> V_560 , 0 , sizeof( V_542 -> V_560 ) ) ;
}
static int F_217 ( struct V_1 * V_2 ,
struct V_541 * V_542 )
{
if ( V_542 -> V_231 & ~ ( V_557
| V_558
| V_559 ) )
return - V_505 ;
F_215 ( V_2 ) ;
V_2 -> V_5 . V_48 . V_49 = V_542 -> V_48 . V_543 ;
V_2 -> V_5 . V_48 . V_16 = V_542 -> V_48 . V_16 ;
V_2 -> V_5 . V_48 . V_51 = V_542 -> V_48 . V_51 ;
V_2 -> V_5 . V_48 . V_42 = V_542 -> V_48 . V_42 ;
V_2 -> V_5 . V_545 . V_49 = V_542 -> V_545 . V_543 ;
V_2 -> V_5 . V_545 . V_16 = V_542 -> V_545 . V_16 ;
V_2 -> V_5 . V_545 . V_546 = V_542 -> V_545 . V_546 ;
if ( V_542 -> V_231 & V_559 )
V_55 -> V_561 ( V_2 ,
V_542 -> V_545 . V_547 ) ;
V_2 -> V_5 . V_552 = V_542 -> V_551 . V_543 ;
if ( V_542 -> V_231 & V_557 )
V_2 -> V_5 . V_553 = V_542 -> V_551 . V_49 ;
V_55 -> V_562 ( V_2 , V_542 -> V_551 . V_554 ) ;
if ( V_542 -> V_231 & V_558 )
V_2 -> V_5 . V_556 = V_542 -> V_556 ;
F_22 ( V_47 , V_2 ) ;
return 0 ;
}
static void F_218 ( struct V_1 * V_2 ,
struct V_563 * V_564 )
{
memcpy ( V_564 -> V_156 , V_2 -> V_5 . V_156 , sizeof( V_2 -> V_5 . V_156 ) ) ;
V_564 -> V_159 = V_2 -> V_5 . V_159 ;
V_564 -> V_147 = V_2 -> V_5 . V_147 ;
V_564 -> V_231 = 0 ;
memset ( & V_564 -> V_560 , 0 , sizeof( V_564 -> V_560 ) ) ;
}
static int F_219 ( struct V_1 * V_2 ,
struct V_563 * V_564 )
{
if ( V_564 -> V_231 )
return - V_505 ;
memcpy ( V_2 -> V_5 . V_156 , V_564 -> V_156 , sizeof( V_2 -> V_5 . V_156 ) ) ;
V_2 -> V_5 . V_159 = V_564 -> V_159 ;
V_2 -> V_5 . V_147 = V_564 -> V_147 ;
return 0 ;
}
static void F_220 ( struct V_1 * V_2 ,
struct V_565 * V_566 )
{
if ( V_480 )
memcpy ( V_566 -> V_567 ,
& V_2 -> V_5 . V_568 . V_569 -> V_570 ,
V_571 ) ;
else {
memcpy ( V_566 -> V_567 ,
& V_2 -> V_5 . V_568 . V_569 -> V_572 ,
sizeof( struct V_573 ) ) ;
* ( T_2 * ) & V_566 -> V_567 [ V_574 / sizeof( T_1 ) ] =
V_575 ;
}
}
static int F_221 ( struct V_1 * V_2 ,
struct V_565 * V_566 )
{
T_2 V_576 =
* ( T_2 * ) & V_566 -> V_567 [ V_574 / sizeof( T_1 ) ] ;
if ( V_480 )
memcpy ( & V_2 -> V_5 . V_568 . V_569 -> V_570 ,
V_566 -> V_567 , V_571 ) ;
else {
if ( V_576 & ~ V_575 )
return - V_505 ;
memcpy ( & V_2 -> V_5 . V_568 . V_569 -> V_572 ,
V_566 -> V_567 , sizeof( struct V_573 ) ) ;
}
return 0 ;
}
static void F_222 ( struct V_1 * V_2 ,
struct V_577 * V_578 )
{
if ( ! V_480 ) {
V_578 -> V_579 = 0 ;
return;
}
V_578 -> V_579 = 1 ;
V_578 -> V_231 = 0 ;
V_578 -> V_580 [ 0 ] . V_119 = V_121 ;
V_578 -> V_580 [ 0 ] . V_23 = V_2 -> V_5 . V_120 ;
}
static int F_223 ( struct V_1 * V_2 ,
struct V_577 * V_578 )
{
int V_3 , V_99 = 0 ;
if ( ! V_480 )
return - V_505 ;
if ( V_578 -> V_579 > V_581 || V_578 -> V_231 )
return - V_505 ;
for ( V_3 = 0 ; V_3 < V_578 -> V_579 ; V_3 ++ )
if ( V_578 -> V_580 [ 0 ] . V_119 == V_121 ) {
V_99 = F_58 ( V_2 , V_121 ,
V_578 -> V_580 [ 0 ] . V_23 ) ;
break;
}
if ( V_99 )
V_99 = - V_505 ;
return V_99 ;
}
static int F_224 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_257 )
return - V_505 ;
V_2 -> V_5 . V_263 = true ;
F_22 ( V_255 , V_2 ) ;
return 0 ;
}
long F_225 ( struct V_485 * V_486 ,
unsigned int V_487 , unsigned long V_488 )
{
struct V_1 * V_2 = V_486 -> V_582 ;
void V_325 * V_489 = ( void V_325 * ) V_488 ;
int V_99 ;
union {
struct V_519 * V_583 ;
struct V_565 * V_570 ;
struct V_577 * V_580 ;
void * V_584 ;
} V_585 ;
V_585 . V_584 = NULL ;
switch ( V_487 ) {
case V_586 : {
V_99 = - V_505 ;
if ( ! V_2 -> V_5 . V_522 )
goto V_93;
V_585 . V_583 = F_226 ( sizeof( struct V_519 ) , V_587 ) ;
V_99 = - V_314 ;
if ( ! V_585 . V_583 )
goto V_93;
V_99 = F_204 ( V_2 , V_585 . V_583 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_80 ;
if ( F_185 ( V_489 , V_585 . V_583 , sizeof( struct V_519 ) ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_588 : {
V_99 = - V_505 ;
if ( ! V_2 -> V_5 . V_522 )
goto V_93;
V_585 . V_583 = F_131 ( V_489 , sizeof( * V_585 . V_583 ) ) ;
if ( F_132 ( V_585 . V_583 ) ) {
V_99 = F_133 ( V_585 . V_583 ) ;
goto V_93;
}
V_99 = F_205 ( V_2 , V_585 . V_583 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_589 : {
struct V_523 V_524 ;
V_99 = - V_80 ;
if ( F_184 ( & V_524 , V_489 , sizeof V_524 ) )
goto V_93;
V_99 = F_208 ( V_2 , & V_524 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_590 : {
V_99 = F_210 ( V_2 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_591 : {
struct V_592 V_325 * V_500 = V_489 ;
struct V_592 V_501 ;
V_99 = - V_80 ;
if ( F_184 ( & V_501 , V_500 , sizeof V_501 ) )
goto V_93;
V_99 = F_227 ( V_2 , & V_501 , V_500 -> V_421 ) ;
if ( V_99 )
goto V_93;
break;
}
case V_593 : {
struct V_499 V_325 * V_500 = V_489 ;
struct V_499 V_501 ;
V_99 = - V_80 ;
if ( F_184 ( & V_501 , V_500 , sizeof V_501 ) )
goto V_93;
V_99 = F_228 ( V_2 , & V_501 ,
V_500 -> V_421 ) ;
if ( V_99 )
goto V_93;
break;
}
case V_594 : {
struct V_499 V_325 * V_500 = V_489 ;
struct V_499 V_501 ;
V_99 = - V_80 ;
if ( F_184 ( & V_501 , V_500 , sizeof V_501 ) )
goto V_93;
V_99 = F_229 ( V_2 , & V_501 ,
V_500 -> V_421 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_80 ;
if ( F_185 ( V_500 , & V_501 , sizeof V_501 ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_595 :
V_99 = F_183 ( V_2 , V_489 , F_168 , 1 ) ;
break;
case V_596 :
V_99 = F_183 ( V_2 , V_489 , F_91 , 0 ) ;
break;
case V_597 : {
struct V_527 V_528 ;
V_99 = - V_80 ;
if ( F_184 ( & V_528 , V_489 , sizeof V_528 ) )
goto V_93;
V_99 = F_211 ( V_2 , & V_528 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_80 ;
if ( F_185 ( V_489 , & V_528 , sizeof V_528 ) )
goto V_93;
V_99 = 0 ;
break;
} ;
case V_598 : {
struct V_599 V_600 ;
V_99 = - V_505 ;
if ( ! F_73 ( V_2 -> V_81 ) )
goto V_93;
V_99 = - V_80 ;
if ( F_184 ( & V_600 , V_489 , sizeof V_600 ) )
goto V_93;
V_99 = 0 ;
F_230 ( V_2 , V_600 . V_601 ) ;
break;
}
case V_602 : {
T_2 V_293 ;
V_99 = - V_80 ;
if ( F_184 ( & V_293 , V_489 , sizeof V_293 ) )
goto V_93;
V_99 = F_212 ( V_2 , V_293 ) ;
break;
}
case V_603 : {
struct V_531 V_532 ;
V_99 = - V_80 ;
if ( F_184 ( & V_532 , V_489 , sizeof V_532 ) )
goto V_93;
V_99 = F_213 ( V_2 , & V_532 ) ;
break;
}
case V_604 : {
struct V_541 V_542 ;
F_214 ( V_2 , & V_542 ) ;
V_99 = - V_80 ;
if ( F_185 ( V_489 , & V_542 , sizeof( struct V_541 ) ) )
break;
V_99 = 0 ;
break;
}
case V_605 : {
struct V_541 V_542 ;
V_99 = - V_80 ;
if ( F_184 ( & V_542 , V_489 , sizeof( struct V_541 ) ) )
break;
V_99 = F_217 ( V_2 , & V_542 ) ;
break;
}
case V_606 : {
struct V_563 V_564 ;
F_218 ( V_2 , & V_564 ) ;
V_99 = - V_80 ;
if ( F_185 ( V_489 , & V_564 ,
sizeof( struct V_563 ) ) )
break;
V_99 = 0 ;
break;
}
case V_607 : {
struct V_563 V_564 ;
V_99 = - V_80 ;
if ( F_184 ( & V_564 , V_489 ,
sizeof( struct V_563 ) ) )
break;
V_99 = F_219 ( V_2 , & V_564 ) ;
break;
}
case V_608 : {
V_585 . V_570 = F_226 ( sizeof( struct V_565 ) , V_587 ) ;
V_99 = - V_314 ;
if ( ! V_585 . V_570 )
break;
F_220 ( V_2 , V_585 . V_570 ) ;
V_99 = - V_80 ;
if ( F_185 ( V_489 , V_585 . V_570 , sizeof( struct V_565 ) ) )
break;
V_99 = 0 ;
break;
}
case V_609 : {
V_585 . V_570 = F_131 ( V_489 , sizeof( * V_585 . V_570 ) ) ;
if ( F_132 ( V_585 . V_570 ) ) {
V_99 = F_133 ( V_585 . V_570 ) ;
goto V_93;
}
V_99 = F_221 ( V_2 , V_585 . V_570 ) ;
break;
}
case V_610 : {
V_585 . V_580 = F_226 ( sizeof( struct V_577 ) , V_587 ) ;
V_99 = - V_314 ;
if ( ! V_585 . V_580 )
break;
F_222 ( V_2 , V_585 . V_580 ) ;
V_99 = - V_80 ;
if ( F_185 ( V_489 , V_585 . V_580 ,
sizeof( struct V_577 ) ) )
break;
V_99 = 0 ;
break;
}
case V_611 : {
V_585 . V_580 = F_131 ( V_489 , sizeof( * V_585 . V_580 ) ) ;
if ( F_132 ( V_585 . V_580 ) ) {
V_99 = F_133 ( V_585 . V_580 ) ;
goto V_93;
}
V_99 = F_223 ( V_2 , V_585 . V_580 ) ;
break;
}
case V_612 : {
T_1 V_613 ;
V_99 = - V_505 ;
V_613 = ( T_1 ) V_488 ;
if ( V_613 >= V_614 )
goto V_93;
if ( V_613 == 0 )
V_613 = V_222 ;
F_111 ( V_2 , V_613 ) ;
V_99 = 0 ;
goto V_93;
}
case V_615 : {
V_99 = V_2 -> V_5 . V_221 ;
goto V_93;
}
case V_616 : {
V_99 = F_224 ( V_2 ) ;
goto V_93;
}
default:
V_99 = - V_505 ;
}
V_93:
F_134 ( V_585 . V_584 ) ;
return V_99 ;
}
int F_231 ( struct V_1 * V_2 , struct V_617 * V_618 )
{
return V_619 ;
}
static int F_232 ( struct V_81 * V_81 , unsigned long V_321 )
{
int V_88 ;
if ( V_321 > ( unsigned int ) ( - 3 * V_87 ) )
return - 1 ;
V_88 = V_55 -> V_620 ( V_81 , V_321 ) ;
return V_88 ;
}
static int F_233 ( struct V_81 * V_81 ,
T_2 V_621 )
{
V_81 -> V_5 . V_622 = V_621 ;
return 0 ;
}
static int F_234 ( struct V_81 * V_81 ,
T_1 V_623 )
{
if ( V_623 < V_624 )
return - V_505 ;
F_165 ( & V_81 -> V_625 ) ;
F_235 ( & V_81 -> V_626 ) ;
F_236 ( V_81 , V_623 ) ;
V_81 -> V_5 . V_627 = V_623 ;
F_237 ( & V_81 -> V_626 ) ;
F_166 ( & V_81 -> V_625 ) ;
return 0 ;
}
static int F_238 ( struct V_81 * V_81 )
{
return V_81 -> V_5 . V_628 ;
}
static int F_239 ( struct V_81 * V_81 , struct V_629 * V_630 )
{
int V_99 ;
V_99 = 0 ;
switch ( V_630 -> V_631 ) {
case V_632 :
memcpy ( & V_630 -> V_630 . V_633 ,
& F_240 ( V_81 ) -> V_634 [ 0 ] ,
sizeof( struct V_635 ) ) ;
break;
case V_636 :
memcpy ( & V_630 -> V_630 . V_633 ,
& F_240 ( V_81 ) -> V_634 [ 1 ] ,
sizeof( struct V_635 ) ) ;
break;
case V_637 :
V_99 = F_241 ( V_81 , & V_630 -> V_630 . V_638 ) ;
break;
default:
V_99 = - V_505 ;
break;
}
return V_99 ;
}
static int F_242 ( struct V_81 * V_81 , struct V_629 * V_630 )
{
int V_99 ;
V_99 = 0 ;
switch ( V_630 -> V_631 ) {
case V_632 :
F_235 ( & F_240 ( V_81 ) -> V_393 ) ;
memcpy ( & F_240 ( V_81 ) -> V_634 [ 0 ] ,
& V_630 -> V_630 . V_633 ,
sizeof( struct V_635 ) ) ;
F_237 ( & F_240 ( V_81 ) -> V_393 ) ;
break;
case V_636 :
F_235 ( & F_240 ( V_81 ) -> V_393 ) ;
memcpy ( & F_240 ( V_81 ) -> V_634 [ 1 ] ,
& V_630 -> V_630 . V_633 ,
sizeof( struct V_635 ) ) ;
F_237 ( & F_240 ( V_81 ) -> V_393 ) ;
break;
case V_637 :
V_99 = F_243 ( V_81 , & V_630 -> V_630 . V_638 ) ;
break;
default:
V_99 = - V_505 ;
break;
}
F_244 ( F_240 ( V_81 ) ) ;
return V_99 ;
}
static int F_245 ( struct V_81 * V_81 , struct V_639 * V_640 )
{
int V_99 = 0 ;
F_165 ( & V_81 -> V_5 . V_641 -> V_642 . V_393 ) ;
memcpy ( V_640 , & V_81 -> V_5 . V_641 -> V_642 , sizeof( struct V_639 ) ) ;
F_166 ( & V_81 -> V_5 . V_641 -> V_642 . V_393 ) ;
return V_99 ;
}
static int F_246 ( struct V_81 * V_81 , struct V_639 * V_640 )
{
int V_99 = 0 ;
F_165 ( & V_81 -> V_5 . V_641 -> V_642 . V_393 ) ;
memcpy ( & V_81 -> V_5 . V_641 -> V_642 , V_640 , sizeof( struct V_639 ) ) ;
F_247 ( V_81 , 0 , V_640 -> V_643 [ 0 ] . V_644 , 0 ) ;
F_166 ( & V_81 -> V_5 . V_641 -> V_642 . V_393 ) ;
return V_99 ;
}
static int F_248 ( struct V_81 * V_81 , struct V_645 * V_640 )
{
int V_99 = 0 ;
F_165 ( & V_81 -> V_5 . V_641 -> V_642 . V_393 ) ;
memcpy ( V_640 -> V_643 , & V_81 -> V_5 . V_641 -> V_642 . V_643 ,
sizeof( V_640 -> V_643 ) ) ;
V_640 -> V_231 = V_81 -> V_5 . V_641 -> V_642 . V_231 ;
F_166 ( & V_81 -> V_5 . V_641 -> V_642 . V_393 ) ;
memset ( & V_640 -> V_560 , 0 , sizeof( V_640 -> V_560 ) ) ;
return V_99 ;
}
static int F_249 ( struct V_81 * V_81 , struct V_645 * V_640 )
{
int V_99 = 0 , V_646 = 0 ;
T_1 V_647 , V_648 ;
F_165 ( & V_81 -> V_5 . V_641 -> V_642 . V_393 ) ;
V_647 = V_81 -> V_5 . V_641 -> V_642 . V_231 & V_649 ;
V_648 = V_640 -> V_231 & V_649 ;
if ( ! V_647 && V_648 )
V_646 = 1 ;
memcpy ( & V_81 -> V_5 . V_641 -> V_642 . V_643 , & V_640 -> V_643 ,
sizeof( V_81 -> V_5 . V_641 -> V_642 . V_643 ) ) ;
V_81 -> V_5 . V_641 -> V_642 . V_231 = V_640 -> V_231 ;
F_247 ( V_81 , 0 , V_81 -> V_5 . V_641 -> V_642 . V_643 [ 0 ] . V_644 , V_646 ) ;
F_166 ( & V_81 -> V_5 . V_641 -> V_642 . V_393 ) ;
return V_99 ;
}
static int F_250 ( struct V_81 * V_81 ,
struct V_650 * V_651 )
{
if ( ! V_81 -> V_5 . V_641 )
return - V_526 ;
F_165 ( & V_81 -> V_5 . V_641 -> V_642 . V_393 ) ;
V_81 -> V_5 . V_641 -> V_642 . V_43 = V_651 -> V_652 ;
F_166 ( & V_81 -> V_5 . V_641 -> V_642 . V_393 ) ;
return 0 ;
}
int F_251 ( struct V_81 * V_81 , struct V_653 * log )
{
int V_99 ;
struct V_654 * V_655 ;
unsigned long V_426 , V_3 ;
unsigned long * V_656 ;
unsigned long * V_657 ;
bool V_658 = false ;
F_165 ( & V_81 -> V_625 ) ;
V_99 = - V_505 ;
if ( log -> V_10 >= V_474 )
goto V_93;
V_655 = F_252 ( V_81 -> V_659 , log -> V_10 ) ;
V_656 = V_655 -> V_656 ;
V_99 = - V_660 ;
if ( ! V_656 )
goto V_93;
V_426 = F_253 ( V_655 ) ;
V_657 = V_656 + V_426 / sizeof( long ) ;
memset ( V_657 , 0 , V_426 ) ;
F_235 ( & V_81 -> V_626 ) ;
for ( V_3 = 0 ; V_3 < V_426 / sizeof( long ) ; V_3 ++ ) {
unsigned long V_26 ;
T_3 V_73 ;
if ( ! V_656 [ V_3 ] )
continue;
V_658 = true ;
V_26 = F_254 ( & V_656 [ V_3 ] , 0 ) ;
V_657 [ V_3 ] = V_26 ;
V_73 = V_3 * V_661 ;
F_255 ( V_81 , V_655 , V_73 , V_26 ) ;
}
if ( V_658 )
F_256 ( V_81 ) ;
F_237 ( & V_81 -> V_626 ) ;
V_99 = - V_80 ;
if ( F_185 ( log -> V_656 , V_657 , V_426 ) )
goto V_93;
V_99 = 0 ;
V_93:
F_166 ( & V_81 -> V_625 ) ;
return V_99 ;
}
int F_257 ( struct V_81 * V_81 , struct V_662 * V_663 )
{
if ( ! F_73 ( V_81 ) )
return - V_526 ;
V_663 -> V_399 = F_258 ( V_81 , V_664 ,
V_663 -> V_524 , V_663 -> V_665 ) ;
return 0 ;
}
long F_259 ( struct V_485 * V_486 ,
unsigned int V_487 , unsigned long V_488 )
{
struct V_81 * V_81 = V_486 -> V_582 ;
void V_325 * V_489 = ( void V_325 * ) V_488 ;
int V_99 = - V_666 ;
union {
struct V_639 V_640 ;
struct V_645 V_667 ;
struct V_668 V_669 ;
} V_585 ;
switch ( V_487 ) {
case V_670 :
V_99 = F_232 ( V_81 , V_488 ) ;
if ( V_99 < 0 )
goto V_93;
break;
case V_671 : {
T_2 V_621 ;
V_99 = - V_80 ;
if ( F_184 ( & V_621 , V_489 , sizeof V_621 ) )
goto V_93;
V_99 = F_233 ( V_81 , V_621 ) ;
if ( V_99 < 0 )
goto V_93;
break;
}
case V_672 :
V_99 = F_234 ( V_81 , V_488 ) ;
if ( V_99 )
goto V_93;
break;
case V_673 :
V_99 = F_238 ( V_81 ) ;
break;
case V_674 : {
struct V_675 * V_676 ;
F_165 ( & V_81 -> V_393 ) ;
V_99 = - V_677 ;
if ( V_81 -> V_5 . V_676 )
goto V_678;
V_99 = - V_505 ;
if ( F_260 ( & V_81 -> V_679 ) )
goto V_678;
V_99 = - V_314 ;
V_676 = F_261 ( V_81 ) ;
if ( V_676 ) {
V_99 = F_262 ( V_81 ) ;
if ( V_99 ) {
F_165 ( & V_81 -> V_625 ) ;
F_263 ( V_81 , V_680 ,
& V_676 -> V_681 ) ;
F_263 ( V_81 , V_680 ,
& V_676 -> V_682 ) ;
F_263 ( V_81 , V_680 ,
& V_676 -> V_683 ) ;
F_166 ( & V_81 -> V_625 ) ;
F_134 ( V_676 ) ;
goto V_678;
}
} else
goto V_678;
F_12 () ;
V_81 -> V_5 . V_676 = V_676 ;
F_12 () ;
V_99 = F_264 ( V_81 ) ;
if ( V_99 ) {
F_165 ( & V_81 -> V_625 ) ;
F_165 ( & V_81 -> V_684 ) ;
F_265 ( V_81 ) ;
F_266 ( V_81 ) ;
F_166 ( & V_81 -> V_684 ) ;
F_166 ( & V_81 -> V_625 ) ;
}
V_678:
F_166 ( & V_81 -> V_393 ) ;
break;
}
case V_685 :
V_585 . V_669 . V_231 = V_686 ;
goto V_687;
case V_688 :
V_99 = - V_80 ;
if ( F_184 ( & V_585 . V_669 , V_489 ,
sizeof( struct V_668 ) ) )
goto V_93;
V_687:
F_165 ( & V_81 -> V_625 ) ;
V_99 = - V_677 ;
if ( V_81 -> V_5 . V_641 )
goto V_689;
V_99 = - V_314 ;
V_81 -> V_5 . V_641 = F_267 ( V_81 , V_585 . V_669 . V_231 ) ;
if ( V_81 -> V_5 . V_641 )
V_99 = 0 ;
V_689:
F_166 ( & V_81 -> V_625 ) ;
break;
case V_690 : {
struct V_629 * V_630 ;
V_630 = F_131 ( V_489 , sizeof( * V_630 ) ) ;
if ( F_132 ( V_630 ) ) {
V_99 = F_133 ( V_630 ) ;
goto V_93;
}
V_99 = - V_526 ;
if ( ! F_73 ( V_81 ) )
goto V_691;
V_99 = F_239 ( V_81 , V_630 ) ;
if ( V_99 )
goto V_691;
V_99 = - V_80 ;
if ( F_185 ( V_489 , V_630 , sizeof *V_630 ) )
goto V_691;
V_99 = 0 ;
V_691:
F_134 ( V_630 ) ;
if ( V_99 )
goto V_93;
break;
}
case V_692 : {
struct V_629 * V_630 ;
V_630 = F_131 ( V_489 , sizeof( * V_630 ) ) ;
if ( F_132 ( V_630 ) ) {
V_99 = F_133 ( V_630 ) ;
goto V_93;
}
V_99 = - V_526 ;
if ( ! F_73 ( V_81 ) )
goto V_693;
V_99 = F_242 ( V_81 , V_630 ) ;
if ( V_99 )
goto V_693;
V_99 = 0 ;
V_693:
F_134 ( V_630 ) ;
if ( V_99 )
goto V_93;
break;
}
case V_694 : {
V_99 = - V_80 ;
if ( F_184 ( & V_585 . V_640 , V_489 , sizeof( struct V_639 ) ) )
goto V_93;
V_99 = - V_526 ;
if ( ! V_81 -> V_5 . V_641 )
goto V_93;
V_99 = F_245 ( V_81 , & V_585 . V_640 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_80 ;
if ( F_185 ( V_489 , & V_585 . V_640 , sizeof( struct V_639 ) ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_695 : {
V_99 = - V_80 ;
if ( F_184 ( & V_585 . V_640 , V_489 , sizeof V_585 . V_640 ) )
goto V_93;
V_99 = - V_526 ;
if ( ! V_81 -> V_5 . V_641 )
goto V_93;
V_99 = F_246 ( V_81 , & V_585 . V_640 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_696 : {
V_99 = - V_526 ;
if ( ! V_81 -> V_5 . V_641 )
goto V_93;
V_99 = F_248 ( V_81 , & V_585 . V_667 ) ;
if ( V_99 )
goto V_93;
V_99 = - V_80 ;
if ( F_185 ( V_489 , & V_585 . V_667 , sizeof( V_585 . V_667 ) ) )
goto V_93;
V_99 = 0 ;
break;
}
case V_697 : {
V_99 = - V_80 ;
if ( F_184 ( & V_585 . V_667 , V_489 , sizeof( V_585 . V_667 ) ) )
goto V_93;
V_99 = - V_526 ;
if ( ! V_81 -> V_5 . V_641 )
goto V_93;
V_99 = F_249 ( V_81 , & V_585 . V_667 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_698 : {
struct V_650 V_651 ;
V_99 = - V_80 ;
if ( F_184 ( & V_651 , V_489 , sizeof( V_651 ) ) )
goto V_93;
V_99 = F_250 ( V_81 , & V_651 ) ;
if ( V_99 )
goto V_93;
V_99 = 0 ;
break;
}
case V_699 : {
V_99 = - V_80 ;
if ( F_184 ( & V_81 -> V_5 . F_130 , V_489 ,
sizeof( struct V_700 ) ) )
goto V_93;
V_99 = - V_505 ;
if ( V_81 -> V_5 . F_130 . V_231 )
goto V_93;
V_99 = 0 ;
break;
}
case V_701 : {
struct V_702 V_703 ;
T_2 V_704 ;
T_10 V_240 ;
V_99 = - V_80 ;
if ( F_184 ( & V_703 , V_489 , sizeof( V_703 ) ) )
goto V_93;
V_99 = - V_505 ;
if ( V_703 . V_231 )
goto V_93;
V_99 = 0 ;
F_268 () ;
V_704 = F_101 () ;
V_240 = V_703 . clock - V_704 ;
F_269 () ;
V_81 -> V_5 . V_192 = V_240 ;
break;
}
case V_705 : {
struct V_702 V_703 ;
T_2 V_704 ;
F_268 () ;
V_704 = F_101 () ;
V_703 . clock = V_81 -> V_5 . V_192 + V_704 ;
F_269 () ;
V_703 . V_231 = 0 ;
memset ( & V_703 . V_544 , 0 , sizeof( V_703 . V_544 ) ) ;
V_99 = - V_80 ;
if ( F_185 ( V_489 , & V_703 , sizeof( V_703 ) ) )
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
T_1 V_706 [ 2 ] ;
unsigned V_3 , V_707 ;
for ( V_3 = V_707 = V_708 ; V_3 < F_41 ( V_497 ) ; V_3 ++ ) {
if ( F_271 ( V_497 [ V_3 ] , & V_706 [ 0 ] , & V_706 [ 1 ] ) < 0 )
continue;
if ( V_707 < V_3 )
V_497 [ V_707 ] = V_497 [ V_3 ] ;
V_707 ++ ;
}
V_494 = V_707 ;
}
static int F_272 ( struct V_1 * V_2 , T_4 V_321 , int V_74 ,
const void * V_215 )
{
int V_709 = 0 ;
int V_426 ;
do {
V_426 = F_273 ( V_74 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_522 &&
! F_274 ( & V_2 -> V_5 . V_522 -> V_710 , V_321 , V_426 , V_215 ) )
&& F_275 ( V_2 -> V_81 , V_711 , V_321 , V_426 , V_215 ) )
break;
V_709 += V_426 ;
V_321 += V_426 ;
V_74 -= V_426 ;
V_215 += V_426 ;
} while ( V_74 );
return V_709 ;
}
static int F_276 ( struct V_1 * V_2 , T_4 V_321 , int V_74 , void * V_215 )
{
int V_709 = 0 ;
int V_426 ;
do {
V_426 = F_273 ( V_74 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_522 &&
! F_277 ( & V_2 -> V_5 . V_522 -> V_710 , V_321 , V_426 , V_215 ) )
&& F_278 ( V_2 -> V_81 , V_711 , V_321 , V_426 , V_215 ) )
break;
F_279 ( V_712 , V_426 , V_321 , * ( T_2 * ) V_215 ) ;
V_709 += V_426 ;
V_321 += V_426 ;
V_74 -= V_426 ;
V_215 += V_426 ;
} while ( V_74 );
return V_709 ;
}
static void F_280 ( struct V_1 * V_2 ,
struct V_713 * V_714 , int V_715 )
{
V_55 -> V_716 ( V_2 , V_714 , V_715 ) ;
}
void F_281 ( struct V_1 * V_2 ,
struct V_713 * V_714 , int V_715 )
{
V_55 -> V_717 ( V_2 , V_714 , V_715 ) ;
}
T_4 F_282 ( struct V_1 * V_2 , T_4 V_336 , T_1 V_75 )
{
T_4 V_718 ;
struct V_57 V_48 ;
F_283 ( ! F_30 ( V_2 ) ) ;
V_75 |= V_91 ;
V_718 = V_2 -> V_5 . V_66 . V_719 ( V_2 , V_336 , V_75 , & V_48 ) ;
return V_718 ;
}
T_4 F_284 ( struct V_1 * V_2 , T_12 V_720 ,
struct V_57 * V_48 )
{
T_1 V_75 = ( V_55 -> V_70 ( V_2 ) == 3 ) ? V_91 : 0 ;
return V_2 -> V_5 . V_83 -> V_719 ( V_2 , V_720 , V_75 , V_48 ) ;
}
T_4 F_285 ( struct V_1 * V_2 , T_12 V_720 ,
struct V_57 * V_48 )
{
T_1 V_75 = ( V_55 -> V_70 ( V_2 ) == 3 ) ? V_91 : 0 ;
V_75 |= V_721 ;
return V_2 -> V_5 . V_83 -> V_719 ( V_2 , V_720 , V_75 , V_48 ) ;
}
T_4 F_286 ( struct V_1 * V_2 , T_12 V_720 ,
struct V_57 * V_48 )
{
T_1 V_75 = ( V_55 -> V_70 ( V_2 ) == 3 ) ? V_91 : 0 ;
V_75 |= V_92 ;
return V_2 -> V_5 . V_83 -> V_719 ( V_2 , V_720 , V_75 , V_48 ) ;
}
T_4 F_287 ( struct V_1 * V_2 , T_12 V_720 ,
struct V_57 * V_48 )
{
return V_2 -> V_5 . V_83 -> V_719 ( V_2 , V_720 , 0 , V_48 ) ;
}
static int F_288 ( T_12 V_321 , void * V_155 , unsigned int V_722 ,
struct V_1 * V_2 , T_1 V_75 ,
struct V_57 * V_48 )
{
void * V_30 = V_155 ;
int V_99 = V_723 ;
while ( V_722 ) {
T_4 V_336 = V_2 -> V_5 . V_83 -> V_719 ( V_2 , V_321 , V_75 ,
V_48 ) ;
unsigned V_73 = V_321 & ( V_87 - 1 ) ;
unsigned V_724 = F_273 ( V_722 , ( unsigned ) V_87 - V_73 ) ;
int V_88 ;
if ( V_336 == V_79 )
return V_725 ;
V_88 = F_93 ( V_2 -> V_81 , V_336 , V_30 , V_724 ) ;
if ( V_88 < 0 ) {
V_99 = V_726 ;
goto V_93;
}
V_722 -= V_724 ;
V_30 += V_724 ;
V_321 += V_724 ;
}
V_93:
return V_99 ;
}
static int F_289 ( struct V_727 * V_728 ,
T_12 V_321 , void * V_155 , unsigned int V_722 ,
struct V_57 * V_48 )
{
struct V_1 * V_2 = F_290 ( V_728 ) ;
T_1 V_75 = ( V_55 -> V_70 ( V_2 ) == 3 ) ? V_91 : 0 ;
return F_288 ( V_321 , V_155 , V_722 , V_2 ,
V_75 | V_721 ,
V_48 ) ;
}
int F_291 ( struct V_727 * V_728 ,
T_12 V_321 , void * V_155 , unsigned int V_722 ,
struct V_57 * V_48 )
{
struct V_1 * V_2 = F_290 ( V_728 ) ;
T_1 V_75 = ( V_55 -> V_70 ( V_2 ) == 3 ) ? V_91 : 0 ;
return F_288 ( V_321 , V_155 , V_722 , V_2 , V_75 ,
V_48 ) ;
}
static int F_292 ( struct V_727 * V_728 ,
T_12 V_321 , void * V_155 , unsigned int V_722 ,
struct V_57 * V_48 )
{
struct V_1 * V_2 = F_290 ( V_728 ) ;
return F_288 ( V_321 , V_155 , V_722 , V_2 , 0 , V_48 ) ;
}
int F_293 ( struct V_727 * V_728 ,
T_12 V_321 , void * V_155 ,
unsigned int V_722 ,
struct V_57 * V_48 )
{
struct V_1 * V_2 = F_290 ( V_728 ) ;
void * V_30 = V_155 ;
int V_99 = V_723 ;
while ( V_722 ) {
T_4 V_336 = V_2 -> V_5 . V_83 -> V_719 ( V_2 , V_321 ,
V_92 ,
V_48 ) ;
unsigned V_73 = V_321 & ( V_87 - 1 ) ;
unsigned V_729 = F_273 ( V_722 , ( unsigned ) V_87 - V_73 ) ;
int V_88 ;
if ( V_336 == V_79 )
return V_725 ;
V_88 = F_94 ( V_2 -> V_81 , V_336 , V_30 , V_729 ) ;
if ( V_88 < 0 ) {
V_99 = V_726 ;
goto V_93;
}
V_722 -= V_729 ;
V_30 += V_729 ;
V_321 += V_729 ;
}
V_93:
return V_99 ;
}
static int F_294 ( struct V_1 * V_2 , unsigned long V_720 ,
T_4 * V_336 , struct V_57 * V_48 ,
bool V_730 )
{
T_1 V_75 = ( ( V_55 -> V_70 ( V_2 ) == 3 ) ? V_91 : 0 )
| ( V_730 ? V_92 : 0 ) ;
if ( F_295 ( V_2 , V_720 )
&& ! F_296 ( V_2 -> V_5 . V_83 , V_2 -> V_5 . V_75 , V_75 ) ) {
* V_336 = V_2 -> V_5 . V_731 << V_86 |
( V_720 & ( V_87 - 1 ) ) ;
F_297 ( V_720 , * V_336 , V_730 , false ) ;
return 1 ;
}
* V_336 = V_2 -> V_5 . V_83 -> V_719 ( V_2 , V_720 , V_75 , V_48 ) ;
if ( * V_336 == V_79 )
return - 1 ;
if ( ( * V_336 & V_310 ) == V_732 )
return 1 ;
if ( F_298 ( V_2 , * V_336 ) ) {
F_297 ( V_720 , * V_336 , V_730 , true ) ;
return 1 ;
}
return 0 ;
}
int F_299 ( struct V_1 * V_2 , T_4 V_336 ,
const void * V_155 , int V_722 )
{
int V_88 ;
V_88 = F_94 ( V_2 -> V_81 , V_336 , V_155 , V_722 ) ;
if ( V_88 < 0 )
return 0 ;
F_300 ( V_2 , V_336 , V_155 , V_722 ) ;
return 1 ;
}
static int F_301 ( struct V_1 * V_2 , void * V_155 , int V_722 )
{
if ( V_2 -> V_733 ) {
F_279 ( V_712 , V_722 ,
V_2 -> V_734 [ 0 ] . V_336 , * ( T_2 * ) V_155 ) ;
V_2 -> V_733 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_302 ( struct V_1 * V_2 , T_4 V_336 ,
void * V_155 , int V_722 )
{
return ! F_93 ( V_2 -> V_81 , V_336 , V_155 , V_722 ) ;
}
static int F_303 ( struct V_1 * V_2 , T_4 V_336 ,
void * V_155 , int V_722 )
{
return F_299 ( V_2 , V_336 , V_155 , V_722 ) ;
}
static int F_304 ( struct V_1 * V_2 , T_4 V_336 , int V_722 , void * V_155 )
{
F_279 ( V_735 , V_722 , V_336 , * ( T_2 * ) V_155 ) ;
return F_272 ( V_2 , V_336 , V_722 , V_155 ) ;
}
static int F_305 ( struct V_1 * V_2 , T_4 V_336 ,
void * V_155 , int V_722 )
{
F_279 ( V_736 , V_722 , V_336 , 0 ) ;
return V_726 ;
}
static int F_306 ( struct V_1 * V_2 , T_4 V_336 ,
void * V_155 , int V_722 )
{
struct V_737 * V_738 = & V_2 -> V_734 [ 0 ] ;
memcpy ( V_2 -> V_739 -> V_740 . V_30 , V_738 -> V_30 , F_273 ( 8u , V_738 -> V_74 ) ) ;
return V_723 ;
}
static int F_307 ( unsigned long V_321 , void * V_155 ,
unsigned int V_722 ,
struct V_57 * V_48 ,
struct V_1 * V_2 ,
const struct V_741 * V_742 )
{
T_4 V_336 ;
int V_709 , V_88 ;
bool V_730 = V_742 -> V_730 ;
struct V_737 * V_738 ;
V_88 = F_294 ( V_2 , V_321 , & V_336 , V_48 , V_730 ) ;
if ( V_88 < 0 )
return V_725 ;
if ( V_88 )
goto V_740;
if ( V_742 -> V_743 ( V_2 , V_336 , V_155 , V_722 ) )
return V_723 ;
V_740:
V_709 = V_742 -> V_744 ( V_2 , V_336 , V_722 , V_155 ) ;
if ( V_709 == V_722 )
return V_723 ;
V_336 += V_709 ;
V_722 -= V_709 ;
V_155 += V_709 ;
F_102 ( V_2 -> V_745 >= V_746 ) ;
V_738 = & V_2 -> V_734 [ V_2 -> V_745 ++ ] ;
V_738 -> V_336 = V_336 ;
V_738 -> V_30 = V_155 ;
V_738 -> V_74 = V_722 ;
return V_723 ;
}
int F_308 ( struct V_727 * V_728 , unsigned long V_321 ,
void * V_155 , unsigned int V_722 ,
struct V_57 * V_48 ,
const struct V_741 * V_742 )
{
struct V_1 * V_2 = F_290 ( V_728 ) ;
T_4 V_336 ;
int V_747 ;
if ( V_742 -> V_748 &&
V_742 -> V_748 ( V_2 , V_155 , V_722 ) )
return V_723 ;
V_2 -> V_745 = 0 ;
if ( ( ( V_321 + V_722 - 1 ) ^ V_321 ) & V_310 ) {
int V_749 ;
V_749 = - V_321 & ~ V_310 ;
V_747 = F_307 ( V_321 , V_155 , V_749 , V_48 ,
V_2 , V_742 ) ;
if ( V_747 != V_723 )
return V_747 ;
V_321 += V_749 ;
V_155 += V_749 ;
V_722 -= V_749 ;
}
V_747 = F_307 ( V_321 , V_155 , V_722 , V_48 ,
V_2 , V_742 ) ;
if ( V_747 != V_723 )
return V_747 ;
if ( ! V_2 -> V_745 )
return V_747 ;
V_336 = V_2 -> V_734 [ 0 ] . V_336 ;
V_2 -> V_750 = 1 ;
V_2 -> V_751 = 0 ;
V_2 -> V_739 -> V_740 . V_74 = F_273 ( 8u , V_2 -> V_734 [ 0 ] . V_74 ) ;
V_2 -> V_739 -> V_740 . V_752 = V_2 -> V_753 = V_742 -> V_730 ;
V_2 -> V_739 -> V_754 = V_755 ;
V_2 -> V_739 -> V_740 . V_756 = V_336 ;
return V_742 -> V_757 ( V_2 , V_336 , V_155 , V_722 ) ;
}
static int F_309 ( struct V_727 * V_728 ,
unsigned long V_321 ,
void * V_155 ,
unsigned int V_722 ,
struct V_57 * V_48 )
{
return F_308 ( V_728 , V_321 , V_155 , V_722 ,
V_48 , & V_758 ) ;
}
int F_310 ( struct V_727 * V_728 ,
unsigned long V_321 ,
const void * V_155 ,
unsigned int V_722 ,
struct V_57 * V_48 )
{
return F_308 ( V_728 , V_321 , ( void * ) V_155 , V_722 ,
V_48 , & V_759 ) ;
}
static int F_311 ( struct V_727 * V_728 ,
unsigned long V_321 ,
const void * V_760 ,
const void * V_761 ,
unsigned int V_722 ,
struct V_57 * V_48 )
{
struct V_1 * V_2 = F_290 ( V_728 ) ;
T_4 V_336 ;
struct V_312 * V_312 ;
char * V_762 ;
bool V_763 ;
if ( V_722 > 8 || ( V_722 & ( V_722 - 1 ) ) )
goto V_764;
V_336 = F_286 ( V_2 , V_321 , NULL ) ;
if ( V_336 == V_79 ||
( V_336 & V_310 ) == V_732 )
goto V_764;
if ( ( ( V_336 + V_722 - 1 ) & V_310 ) != ( V_336 & V_310 ) )
goto V_764;
V_312 = F_157 ( V_2 -> V_81 , V_336 >> V_86 ) ;
if ( F_158 ( V_312 ) )
goto V_764;
V_762 = F_121 ( V_312 ) ;
V_762 += F_312 ( V_336 ) ;
switch ( V_722 ) {
case 1 :
V_763 = F_313 ( T_11 , V_762 , V_760 , V_761 ) ;
break;
case 2 :
V_763 = F_313 ( V_765 , V_762 , V_760 , V_761 ) ;
break;
case 4 :
V_763 = F_313 ( T_1 , V_762 , V_760 , V_761 ) ;
break;
case 8 :
V_763 = F_314 ( V_762 , V_760 , V_761 ) ;
break;
default:
F_315 () ;
}
F_122 ( V_762 ) ;
F_149 ( V_312 ) ;
if ( ! V_763 )
return V_766 ;
F_300 ( V_2 , V_336 , V_761 , V_722 ) ;
return V_723 ;
V_764:
F_316 ( V_767 L_22 ) ;
return F_310 ( V_728 , V_321 , V_761 , V_722 , V_48 ) ;
}
static int F_317 ( struct V_1 * V_2 , void * V_768 )
{
int V_99 ;
if ( V_2 -> V_5 . V_769 . V_770 )
V_99 = F_278 ( V_2 -> V_81 , V_680 , V_2 -> V_5 . V_769 . V_771 ,
V_2 -> V_5 . V_769 . V_427 , V_768 ) ;
else
V_99 = F_275 ( V_2 -> V_81 , V_680 ,
V_2 -> V_5 . V_769 . V_771 , V_2 -> V_5 . V_769 . V_427 ,
V_768 ) ;
return V_99 ;
}
static int F_318 ( struct V_1 * V_2 , int V_427 ,
unsigned short V_771 , void * V_155 ,
unsigned int V_644 , bool V_770 )
{
F_319 ( ! V_770 , V_771 , V_427 , V_644 ) ;
V_2 -> V_5 . V_769 . V_771 = V_771 ;
V_2 -> V_5 . V_769 . V_770 = V_770 ;
V_2 -> V_5 . V_769 . V_644 = V_644 ;
V_2 -> V_5 . V_769 . V_427 = V_427 ;
if ( ! F_317 ( V_2 , V_2 -> V_5 . V_772 ) ) {
V_2 -> V_5 . V_769 . V_644 = 0 ;
return 1 ;
}
V_2 -> V_739 -> V_754 = V_773 ;
V_2 -> V_739 -> V_774 . V_775 = V_770 ? V_776 : V_777 ;
V_2 -> V_739 -> V_774 . V_427 = V_427 ;
V_2 -> V_739 -> V_774 . V_778 = V_779 * V_87 ;
V_2 -> V_739 -> V_774 . V_644 = V_644 ;
V_2 -> V_739 -> V_774 . V_771 = V_771 ;
return 0 ;
}
static int F_320 ( struct V_727 * V_728 ,
int V_427 , unsigned short V_771 , void * V_155 ,
unsigned int V_644 )
{
struct V_1 * V_2 = F_290 ( V_728 ) ;
int V_88 ;
if ( V_2 -> V_5 . V_769 . V_644 )
goto V_780;
V_88 = F_318 ( V_2 , V_427 , V_771 , V_155 , V_644 , true ) ;
if ( V_88 ) {
V_780:
memcpy ( V_155 , V_2 -> V_5 . V_772 , V_427 * V_644 ) ;
V_2 -> V_5 . V_769 . V_644 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_321 ( struct V_727 * V_728 ,
int V_427 , unsigned short V_771 ,
const void * V_155 , unsigned int V_644 )
{
struct V_1 * V_2 = F_290 ( V_728 ) ;
memcpy ( V_2 -> V_5 . V_772 , V_155 , V_427 * V_644 ) ;
return F_318 ( V_2 , V_427 , V_771 , ( void * ) V_155 , V_644 , false ) ;
}
static unsigned long F_322 ( struct V_1 * V_2 , int V_715 )
{
return V_55 -> F_322 ( V_2 , V_715 ) ;
}
static void F_323 ( struct V_727 * V_728 , V_143 V_62 )
{
F_324 ( F_290 ( V_728 ) , V_62 ) ;
}
int F_325 ( struct V_1 * V_2 )
{
if ( ! F_193 ( V_2 ) )
return V_723 ;
if ( V_55 -> V_511 () ) {
int V_510 = F_326 () ;
F_195 ( V_510 , V_2 -> V_5 . V_512 ) ;
F_327 ( V_2 -> V_5 . V_512 ,
F_191 , NULL , 1 ) ;
F_328 () ;
F_329 ( V_2 -> V_5 . V_512 ) ;
} else
F_192 () ;
return V_723 ;
}
static void F_330 ( struct V_727 * V_728 )
{
F_325 ( F_290 ( V_728 ) ) ;
}
int F_331 ( struct V_727 * V_728 , int V_154 , unsigned long * V_781 )
{
return F_80 ( F_290 ( V_728 ) , V_154 , V_781 ) ;
}
int F_332 ( struct V_727 * V_728 , int V_154 , unsigned long V_23 )
{
return F_78 ( F_290 ( V_728 ) , V_154 , V_23 ) ;
}
static T_2 F_333 ( T_2 V_782 , T_1 V_783 )
{
return ( V_782 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_783 ;
}
static unsigned long F_334 ( struct V_727 * V_728 , int V_784 )
{
struct V_1 * V_2 = F_290 ( V_728 ) ;
unsigned long V_23 ;
switch ( V_784 ) {
case 0 :
V_23 = F_50 ( V_2 ) ;
break;
case 2 :
V_23 = V_2 -> V_5 . V_61 ;
break;
case 3 :
V_23 = F_48 ( V_2 ) ;
break;
case 4 :
V_23 = F_61 ( V_2 ) ;
break;
case 8 :
V_23 = F_75 ( V_2 ) ;
break;
default:
F_335 ( L_23 , V_210 , V_784 ) ;
return 0 ;
}
return V_23 ;
}
static int F_336 ( struct V_727 * V_728 , int V_784 , V_143 V_155 )
{
struct V_1 * V_2 = F_290 ( V_728 ) ;
int V_164 = 0 ;
switch ( V_784 ) {
case 0 :
V_164 = F_49 ( V_2 , F_333 ( F_50 ( V_2 ) , V_155 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_61 = V_155 ;
break;
case 3 :
V_164 = F_67 ( V_2 , V_155 ) ;
break;
case 4 :
V_164 = F_60 ( V_2 , F_333 ( F_61 ( V_2 ) , V_155 ) ) ;
break;
case 8 :
V_164 = F_72 ( V_2 , V_155 ) ;
break;
default:
F_335 ( L_23 , V_210 , V_784 ) ;
V_164 = - 1 ;
}
return V_164 ;
}
static void F_337 ( struct V_727 * V_728 , V_143 V_155 )
{
F_338 ( F_290 ( V_728 ) , V_155 ) ;
}
static int F_339 ( struct V_727 * V_728 )
{
return V_55 -> V_70 ( F_290 ( V_728 ) ) ;
}
static void F_340 ( struct V_727 * V_728 , struct V_785 * V_786 )
{
V_55 -> V_787 ( F_290 ( V_728 ) , V_786 ) ;
}
static void F_341 ( struct V_727 * V_728 , struct V_785 * V_786 )
{
V_55 -> V_788 ( F_290 ( V_728 ) , V_786 ) ;
}
static void F_342 ( struct V_727 * V_728 , struct V_785 * V_786 )
{
V_55 -> V_789 ( F_290 ( V_728 ) , V_786 ) ;
}
static void F_343 ( struct V_727 * V_728 , struct V_785 * V_786 )
{
V_55 -> V_790 ( F_290 ( V_728 ) , V_786 ) ;
}
static unsigned long F_344 (
struct V_727 * V_728 , int V_715 )
{
return F_322 ( F_290 ( V_728 ) , V_715 ) ;
}
static bool F_345 ( struct V_727 * V_728 , V_765 * V_791 ,
struct V_792 * V_793 , T_1 * V_794 ,
int V_715 )
{
struct V_713 V_714 ;
F_281 ( F_290 ( V_728 ) , & V_714 , V_715 ) ;
* V_791 = V_714 . V_791 ;
if ( V_714 . V_795 )
return false ;
if ( V_714 . V_796 )
V_714 . V_797 >>= 12 ;
F_346 ( V_793 , V_714 . V_797 ) ;
F_347 ( V_793 , ( unsigned long ) V_714 . V_798 ) ;
#ifdef F_51
if ( V_794 )
* V_794 = V_714 . V_798 >> 32 ;
#endif
V_793 -> type = V_714 . type ;
V_793 -> V_520 = V_714 . V_520 ;
V_793 -> V_799 = V_714 . V_799 ;
V_793 -> V_281 = V_714 . V_800 ;
V_793 -> V_801 = V_714 . V_801 ;
V_793 -> V_802 = V_714 . V_802 ;
V_793 -> V_803 = V_714 . V_156 ;
V_793 -> V_796 = V_714 . V_796 ;
return true ;
}
static void F_348 ( struct V_727 * V_728 , V_765 V_791 ,
struct V_792 * V_793 , T_1 V_794 ,
int V_715 )
{
struct V_1 * V_2 = F_290 ( V_728 ) ;
struct V_713 V_714 ;
V_714 . V_791 = V_791 ;
V_714 . V_798 = F_349 ( V_793 ) ;
#ifdef F_51
V_714 . V_798 |= ( ( T_2 ) V_794 ) << 32 ;
#endif
V_714 . V_797 = F_350 ( V_793 ) ;
if ( V_793 -> V_796 )
V_714 . V_797 = ( V_714 . V_797 << 12 ) | 0xfff ;
V_714 . type = V_793 -> type ;
V_714 . V_800 = V_793 -> V_281 ;
V_714 . V_799 = V_793 -> V_799 ;
V_714 . V_156 = V_793 -> V_803 ;
V_714 . V_520 = V_793 -> V_520 ;
V_714 . V_802 = V_793 -> V_802 ;
V_714 . V_796 = V_793 -> V_796 ;
V_714 . V_801 = V_793 -> V_801 ;
V_714 . V_800 = V_793 -> V_281 ;
V_714 . V_795 = ! V_714 . V_800 ;
V_714 . V_804 = 0 ;
F_280 ( V_2 , & V_714 , V_715 ) ;
return;
}
static int F_351 ( struct V_727 * V_728 ,
T_1 V_184 , T_2 * V_401 )
{
return F_168 ( F_290 ( V_728 ) , V_184 , V_401 ) ;
}
static int F_352 ( struct V_727 * V_728 ,
T_1 V_184 , T_2 V_30 )
{
return F_90 ( F_290 ( V_728 ) , V_184 , V_30 ) ;
}
static int F_353 ( struct V_727 * V_728 ,
T_1 V_805 , T_2 * V_401 )
{
return F_84 ( F_290 ( V_728 ) , V_805 , V_401 ) ;
}
static void F_354 ( struct V_727 * V_728 )
{
F_290 ( V_728 ) -> V_5 . V_806 = 1 ;
}
static void F_355 ( struct V_727 * V_728 )
{
F_160 () ;
F_356 ( F_290 ( V_728 ) ) ;
F_357 () ;
}
static void F_358 ( struct V_727 * V_728 )
{
F_161 () ;
}
static int F_359 ( struct V_727 * V_728 ,
struct V_807 * V_808 ,
enum V_809 V_810 )
{
return V_55 -> V_811 ( F_290 ( V_728 ) , V_808 , V_810 ) ;
}
static void F_360 ( struct V_727 * V_728 ,
T_1 * V_812 , T_1 * V_813 , T_1 * V_166 , T_1 * V_175 )
{
V_592 ( F_290 ( V_728 ) , V_812 , V_813 , V_166 , V_175 ) ;
}
static V_143 F_361 ( struct V_727 * V_728 , unsigned V_814 )
{
return F_83 ( F_290 ( V_728 ) , V_814 ) ;
}
static void F_362 ( struct V_727 * V_728 , unsigned V_814 , V_143 V_155 )
{
F_85 ( F_290 ( V_728 ) , V_814 , V_155 ) ;
}
static void F_363 ( struct V_1 * V_2 , T_1 V_26 )
{
T_1 V_815 = V_55 -> V_548 ( V_2 , V_26 ) ;
if ( ! ( V_815 & V_26 ) )
V_55 -> V_561 ( V_2 , V_26 ) ;
}
static void F_364 ( struct V_1 * V_2 )
{
struct V_727 * V_728 = & V_2 -> V_5 . V_816 ;
if ( V_728 -> V_48 . V_31 == V_32 )
F_29 ( V_2 , & V_728 -> V_48 ) ;
else if ( V_728 -> V_48 . V_817 )
F_28 ( V_2 , V_728 -> V_48 . V_31 ,
V_728 -> V_48 . V_42 ) ;
else
F_23 ( V_2 , V_728 -> V_48 . V_31 ) ;
}
static void F_365 ( struct V_727 * V_728 )
{
memset ( & V_728 -> V_818 , 0 ,
( void * ) & V_728 -> V_819 - ( void * ) & V_728 -> V_818 ) ;
V_728 -> V_820 . V_646 = 0 ;
V_728 -> V_820 . V_821 = 0 ;
V_728 -> V_822 . V_823 = 0 ;
V_728 -> V_822 . V_821 = 0 ;
V_728 -> V_824 . V_823 = 0 ;
V_728 -> V_824 . V_821 = 0 ;
}
static void F_366 ( struct V_1 * V_2 )
{
struct V_727 * V_728 = & V_2 -> V_5 . V_816 ;
int V_112 , V_113 ;
V_55 -> V_114 ( V_2 , & V_112 , & V_113 ) ;
V_728 -> V_825 = F_367 ( V_2 ) ;
V_728 -> V_826 = F_368 ( V_2 ) ;
V_728 -> V_827 = ( ! F_369 ( V_2 ) ) ? V_828 :
( V_728 -> V_825 & V_829 ) ? V_830 :
V_113 ? V_831 :
V_112 ? V_832 :
V_833 ;
V_728 -> V_834 = F_370 ( V_2 ) ;
F_365 ( V_728 ) ;
V_2 -> V_5 . V_835 = false ;
}
int F_371 ( struct V_1 * V_2 , int V_524 , int V_836 )
{
struct V_727 * V_728 = & V_2 -> V_5 . V_816 ;
int V_88 ;
F_366 ( V_2 ) ;
V_728 -> V_837 = 2 ;
V_728 -> V_838 = 2 ;
V_728 -> V_839 = V_728 -> V_826 + V_836 ;
V_88 = F_372 ( V_728 , V_524 ) ;
if ( V_88 != V_723 )
return V_840 ;
V_728 -> V_826 = V_728 -> V_839 ;
F_373 ( V_2 , V_728 -> V_826 ) ;
F_338 ( V_2 , V_728 -> V_825 ) ;
if ( V_524 == V_841 )
V_2 -> V_5 . V_553 = 0 ;
else
V_2 -> V_5 . V_545 . V_49 = false ;
return V_842 ;
}
static int F_374 ( struct V_1 * V_2 )
{
int V_99 = V_842 ;
++ V_2 -> V_59 . V_843 ;
F_375 ( V_2 ) ;
if ( ! F_370 ( V_2 ) ) {
V_2 -> V_739 -> V_754 = V_844 ;
V_2 -> V_739 -> V_845 . V_846 = V_847 ;
V_2 -> V_739 -> V_845 . V_848 = 0 ;
V_99 = V_840 ;
}
F_23 ( V_2 , V_165 ) ;
return V_99 ;
}
static bool F_376 ( struct V_1 * V_2 , T_12 V_720 )
{
T_4 V_336 ;
T_13 V_849 ;
if ( V_183 )
return false ;
if ( F_377 ( V_2 , V_720 ) )
return true ;
V_336 = F_287 ( V_2 , V_720 , NULL ) ;
if ( V_336 == V_79 )
return true ;
V_849 = F_378 ( V_2 -> V_81 , F_37 ( V_336 ) ) ;
if ( ! F_379 ( V_849 ) ) {
F_380 ( V_849 ) ;
return true ;
}
return false ;
}
static bool F_381 ( struct V_727 * V_728 ,
unsigned long V_61 , int V_850 )
{
struct V_1 * V_2 = F_290 ( V_728 ) ;
unsigned long V_851 , V_852 , V_336 = V_61 ;
V_851 = V_2 -> V_5 . V_851 ;
V_852 = V_2 -> V_5 . V_852 ;
V_2 -> V_5 . V_851 = V_2 -> V_5 . V_852 = 0 ;
if ( ! ( V_850 & V_853 ) )
return false ;
if ( F_382 ( V_728 ) )
return false ;
if ( V_728 -> V_826 == V_851 && V_852 == V_61 )
return false ;
V_2 -> V_5 . V_851 = V_728 -> V_826 ;
V_2 -> V_5 . V_852 = V_61 ;
if ( ! V_2 -> V_5 . V_66 . V_854 )
V_336 = F_286 ( V_2 , V_61 , NULL ) ;
F_383 ( V_2 -> V_81 , V_336 >> V_86 ) ;
return true ;
}
int F_384 ( struct V_1 * V_2 ,
unsigned long V_61 ,
int V_850 ,
void * V_855 ,
int V_856 )
{
int V_99 ;
struct V_727 * V_728 = & V_2 -> V_5 . V_816 ;
bool V_425 = true ;
F_385 ( V_2 ) ;
if ( ! ( V_850 & V_857 ) ) {
F_366 ( V_2 ) ;
V_728 -> V_858 = 0 ;
V_728 -> V_859 = false ;
V_728 -> V_860 = false ;
V_728 -> V_861
= V_850 & V_862 ;
V_99 = F_386 ( V_728 , V_855 , V_856 ) ;
F_387 ( V_2 ) ;
++ V_2 -> V_59 . V_863 ;
if ( V_99 != V_864 ) {
if ( V_850 & V_862 )
return V_840 ;
if ( F_376 ( V_2 , V_61 ) )
return V_842 ;
if ( V_850 & V_865 )
return V_840 ;
return F_374 ( V_2 ) ;
}
}
if ( V_850 & V_865 ) {
F_373 ( V_2 , V_728 -> V_839 ) ;
return V_842 ;
}
if ( F_381 ( V_728 , V_61 , V_850 ) )
return V_842 ;
if ( V_2 -> V_5 . V_835 ) {
V_2 -> V_5 . V_835 = false ;
F_388 ( V_728 ) ;
}
V_866:
V_99 = F_389 ( V_728 ) ;
if ( V_99 == V_867 )
return V_842 ;
if ( V_99 == V_868 ) {
if ( F_376 ( V_2 , V_61 ) )
return V_842 ;
return F_374 ( V_2 ) ;
}
if ( V_728 -> V_859 ) {
F_364 ( V_2 ) ;
V_99 = V_842 ;
} else if ( V_2 -> V_5 . V_769 . V_644 ) {
if ( ! V_2 -> V_5 . V_769 . V_770 )
V_2 -> V_5 . V_769 . V_644 = 0 ;
else {
V_425 = false ;
V_2 -> V_5 . V_869 = V_870 ;
}
V_99 = V_871 ;
} else if ( V_2 -> V_750 ) {
if ( ! V_2 -> V_753 )
V_425 = false ;
V_99 = V_871 ;
V_2 -> V_5 . V_869 = V_872 ;
} else if ( V_99 == V_873 )
goto V_866;
else
V_99 = V_842 ;
if ( V_425 ) {
F_363 ( V_2 , V_728 -> V_858 ) ;
F_338 ( V_2 , V_728 -> V_825 ) ;
F_22 ( V_47 , V_2 ) ;
V_2 -> V_5 . V_874 = false ;
F_373 ( V_2 , V_728 -> V_826 ) ;
} else
V_2 -> V_5 . V_874 = true ;
return V_99 ;
}
int F_390 ( struct V_1 * V_2 , int V_427 , unsigned short V_771 )
{
unsigned long V_155 = F_83 ( V_2 , V_168 ) ;
int V_88 = F_321 ( & V_2 -> V_5 . V_816 ,
V_427 , V_771 , & V_155 , 1 ) ;
V_2 -> V_5 . V_769 . V_644 = 0 ;
return V_88 ;
}
static void F_391 ( void * V_808 )
{
F_392 ( V_254 , 0 ) ;
}
static void F_393 ( void * V_30 )
{
struct V_875 * V_876 = V_30 ;
unsigned long V_213 = 0 ;
if ( V_30 )
V_213 = V_876 -> V_761 ;
else if ( ! F_188 ( V_877 ) )
V_213 = F_394 ( F_395 () ) ;
if ( ! V_213 )
V_213 = V_222 ;
F_392 ( V_254 , V_213 ) ;
}
static int F_396 ( struct V_878 * V_879 , unsigned long V_155 ,
void * V_30 )
{
struct V_875 * V_876 = V_30 ;
struct V_81 * V_81 ;
struct V_1 * V_2 ;
int V_3 , V_880 = 0 ;
if ( V_155 == V_881 && V_876 -> V_760 > V_876 -> V_761 )
return 0 ;
if ( V_155 == V_882 && V_876 -> V_760 < V_876 -> V_761 )
return 0 ;
F_196 ( V_876 -> V_510 , F_393 , V_876 , 1 ) ;
F_397 ( & V_883 ) ;
F_398 (kvm, &vm_list, vm_list) {
F_173 (i, vcpu, kvm) {
if ( V_2 -> V_510 != V_876 -> V_510 )
continue;
F_22 ( V_255 , V_2 ) ;
if ( V_2 -> V_510 != F_399 () )
V_880 = 1 ;
}
}
F_400 ( & V_883 ) ;
if ( V_876 -> V_760 < V_876 -> V_761 && V_880 ) {
F_196 ( V_876 -> V_510 , F_393 , V_876 , 1 ) ;
}
return 0 ;
}
static int F_401 ( struct V_878 * V_884 ,
unsigned long V_885 , void * V_886 )
{
unsigned int V_510 = ( unsigned long ) V_886 ;
switch ( V_885 ) {
case V_887 :
case V_888 :
F_196 ( V_510 , F_393 , NULL , 1 ) ;
break;
case V_889 :
F_196 ( V_510 , F_391 , NULL , 1 ) ;
break;
}
return V_890 ;
}
static void F_402 ( void )
{
int V_510 ;
V_891 = V_222 ;
F_403 ( & V_892 ) ;
if ( ! F_188 ( V_877 ) ) {
#ifdef F_404
struct V_893 V_894 ;
memset ( & V_894 , 0 , sizeof( V_894 ) ) ;
V_510 = F_326 () ;
F_405 ( & V_894 , V_510 ) ;
if ( V_894 . V_895 . V_896 )
V_891 = V_894 . V_895 . V_896 ;
F_328 () ;
#endif
F_406 ( & V_897 ,
V_898 ) ;
}
F_100 ( L_24 , V_891 ) ;
F_407 (cpu)
F_196 ( V_510 , F_393 , NULL , 1 ) ;
}
int F_408 ( void )
{
return F_409 ( V_899 ) != NULL ;
}
static int F_410 ( void )
{
int V_900 = 3 ;
if ( F_409 ( V_899 ) )
V_900 = V_55 -> V_70 ( F_409 ( V_899 ) ) ;
return V_900 != 0 ;
}
static unsigned long F_411 ( void )
{
unsigned long V_901 = 0 ;
if ( F_409 ( V_899 ) )
V_901 = F_368 ( F_409 ( V_899 ) ) ;
return V_901 ;
}
void F_412 ( struct V_1 * V_2 )
{
F_392 ( V_899 , V_2 ) ;
}
void F_413 ( struct V_1 * V_2 )
{
F_392 ( V_899 , NULL ) ;
}
static void F_414 ( void )
{
T_2 V_26 ;
int V_902 = V_903 . V_904 ;
V_26 = ( ( 1ull << ( 62 - V_902 + 1 ) ) - 1 ) << V_902 ;
V_26 |= 1ull ;
#ifdef F_51
if ( V_902 == 52 )
V_26 &= ~ 1ull ;
#endif
F_415 ( V_26 ) ;
}
int F_416 ( void * V_905 )
{
int V_99 ;
struct V_55 * V_742 = (struct V_55 * ) V_905 ;
if ( V_55 ) {
F_9 ( V_25 L_25 ) ;
V_99 = - V_677 ;
goto V_93;
}
if ( ! V_742 -> V_906 () ) {
F_9 ( V_25 L_26 ) ;
V_99 = - V_907 ;
goto V_93;
}
if ( V_742 -> V_908 () ) {
F_9 ( V_25 L_27 ) ;
V_99 = - V_907 ;
goto V_93;
}
V_99 = F_417 () ;
if ( V_99 )
goto V_93;
F_414 () ;
F_270 () ;
V_55 = V_742 ;
F_418 ( V_909 , V_910 ,
V_911 , V_912 , 0 ) ;
F_402 () ;
F_419 ( & V_913 ) ;
if ( V_480 )
V_125 = F_420 ( V_121 ) ;
F_421 () ;
return 0 ;
V_93:
return V_99 ;
}
void F_422 ( void )
{
F_423 ( & V_913 ) ;
if ( ! F_188 ( V_877 ) )
F_424 ( & V_897 ,
V_898 ) ;
F_425 ( & V_892 ) ;
V_55 = NULL ;
F_426 () ;
}
int F_427 ( struct V_1 * V_2 )
{
++ V_2 -> V_59 . V_914 ;
if ( F_73 ( V_2 -> V_81 ) ) {
V_2 -> V_5 . V_915 = V_916 ;
return 1 ;
} else {
V_2 -> V_739 -> V_754 = V_917 ;
return 0 ;
}
}
int F_428 ( struct V_1 * V_2 )
{
T_2 V_918 , V_919 , V_920 , V_88 ;
T_14 V_921 , V_922 , V_923 , V_164 = V_924 , V_925 = 0 ;
bool V_926 , V_927 ;
int V_112 , V_113 ;
if ( V_55 -> V_70 ( V_2 ) != 0 || ! F_369 ( V_2 ) ) {
F_23 ( V_2 , V_165 ) ;
return 0 ;
}
V_55 -> V_114 ( V_2 , & V_112 , & V_113 ) ;
V_927 = F_45 ( V_2 ) && V_113 == 1 ;
if ( ! V_927 ) {
V_918 = ( ( T_2 ) F_83 ( V_2 , V_169 ) << 32 ) |
( F_83 ( V_2 , V_168 ) & 0xffffffff ) ;
V_919 = ( ( T_2 ) F_83 ( V_2 , V_928 ) << 32 ) |
( F_83 ( V_2 , V_167 ) & 0xffffffff ) ;
V_920 = ( ( T_2 ) F_83 ( V_2 , V_929 ) << 32 ) |
( F_83 ( V_2 , V_930 ) & 0xffffffff ) ;
}
#ifdef F_51
else {
V_918 = F_83 ( V_2 , V_167 ) ;
V_919 = F_83 ( V_2 , V_169 ) ;
V_920 = F_83 ( V_2 , V_931 ) ;
}
#endif
V_921 = V_918 & 0xffff ;
V_926 = ( V_918 >> 16 ) & 0x1 ;
V_923 = ( V_918 >> 32 ) & 0xfff ;
V_922 = ( V_918 >> 48 ) & 0xfff ;
F_429 ( V_921 , V_926 , V_923 , V_922 , V_919 , V_920 ) ;
switch ( V_921 ) {
case V_932 :
F_430 ( V_2 ) ;
break;
default:
V_164 = V_933 ;
break;
}
V_88 = V_164 | ( ( ( T_2 ) V_925 & 0xfff ) << 32 ) ;
if ( V_927 ) {
F_85 ( V_2 , V_168 , V_88 ) ;
} else {
F_85 ( V_2 , V_169 , V_88 >> 32 ) ;
F_85 ( V_2 , V_168 , V_88 & 0xffffffff ) ;
}
return 1 ;
}
int F_431 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_934 , V_935 , V_936 , V_937 , V_88 ;
int V_99 = 1 ;
if ( F_135 ( V_2 -> V_81 ) )
return F_428 ( V_2 ) ;
V_16 = F_83 ( V_2 , V_168 ) ;
V_934 = F_83 ( V_2 , V_928 ) ;
V_935 = F_83 ( V_2 , V_167 ) ;
V_936 = F_83 ( V_2 , V_169 ) ;
V_937 = F_83 ( V_2 , V_930 ) ;
F_432 ( V_16 , V_934 , V_935 , V_936 , V_937 ) ;
if ( ! F_45 ( V_2 ) ) {
V_16 &= 0xFFFFFFFF ;
V_934 &= 0xFFFFFFFF ;
V_935 &= 0xFFFFFFFF ;
V_936 &= 0xFFFFFFFF ;
V_937 &= 0xFFFFFFFF ;
}
if ( V_55 -> V_70 ( V_2 ) != 0 ) {
V_88 = - V_938 ;
goto V_93;
}
switch ( V_16 ) {
case V_939 :
V_88 = 0 ;
break;
default:
V_88 = - V_940 ;
break;
}
V_93:
F_85 ( V_2 , V_168 , V_88 ) ;
++ V_2 -> V_59 . V_941 ;
return V_99 ;
}
int F_433 ( struct V_727 * V_728 )
{
struct V_1 * V_2 = F_290 ( V_728 ) ;
char V_942 [ 3 ] ;
unsigned long V_943 = F_368 ( V_2 ) ;
F_434 ( V_2 -> V_81 ) ;
V_55 -> V_324 ( V_2 , V_942 ) ;
return F_310 ( V_728 , V_943 , V_942 , 3 , NULL ) ;
}
static int F_435 ( struct V_1 * V_2 )
{
return ( ! F_73 ( V_2 -> V_81 ) && ! F_436 ( V_2 ) &&
V_2 -> V_739 -> V_944 &&
F_437 ( V_2 ) ) ;
}
static void F_438 ( struct V_1 * V_2 )
{
struct V_945 * V_945 = V_2 -> V_739 ;
V_945 -> V_946 = ( F_367 ( V_2 ) & V_947 ) != 0 ;
V_945 -> V_145 = F_75 ( V_2 ) ;
V_945 -> V_29 = F_17 ( V_2 ) ;
if ( F_73 ( V_2 -> V_81 ) )
V_945 -> V_948 = 1 ;
else
V_945 -> V_948 =
F_437 ( V_2 ) &&
! F_436 ( V_2 ) &&
! F_439 ( V_2 ) ;
}
static int F_440 ( struct V_1 * V_2 )
{
struct V_949 * V_522 = V_2 -> V_5 . V_522 ;
struct V_312 * V_312 ;
if ( ! V_522 || ! V_522 -> V_601 )
return 0 ;
V_312 = F_157 ( V_2 -> V_81 , V_522 -> V_601 >> V_86 ) ;
if ( F_158 ( V_312 ) )
return - V_80 ;
V_2 -> V_5 . V_522 -> V_950 = V_312 ;
return 0 ;
}
static void F_441 ( struct V_1 * V_2 )
{
struct V_949 * V_522 = V_2 -> V_5 . V_522 ;
int V_287 ;
if ( ! V_522 || ! V_522 -> V_601 )
return;
V_287 = F_181 ( & V_2 -> V_81 -> V_422 ) ;
F_149 ( V_522 -> V_950 ) ;
F_123 ( V_2 -> V_81 , V_522 -> V_601 >> V_86 ) ;
F_182 ( & V_2 -> V_81 -> V_422 , V_287 ) ;
}
static void F_207 ( struct V_1 * V_2 )
{
int V_951 , V_952 ;
if ( ! V_55 -> F_207 )
return;
if ( ! V_2 -> V_5 . V_522 )
return;
if ( ! V_2 -> V_5 . V_522 -> V_601 )
V_951 = F_442 ( V_2 ) ;
else
V_951 = - 1 ;
if ( V_951 != - 1 )
V_951 >>= 4 ;
V_952 = F_76 ( V_2 ) ;
V_55 -> F_207 ( V_2 , V_952 , V_951 ) ;
}
static void F_443 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_48 . V_49 ) {
F_444 ( V_2 -> V_5 . V_48 . V_16 ,
V_2 -> V_5 . V_48 . V_51 ,
V_2 -> V_5 . V_48 . V_42 ) ;
V_55 -> V_953 ( V_2 , V_2 -> V_5 . V_48 . V_16 ,
V_2 -> V_5 . V_48 . V_51 ,
V_2 -> V_5 . V_48 . V_42 ,
V_2 -> V_5 . V_48 . V_43 ) ;
return;
}
if ( V_2 -> V_5 . V_552 ) {
V_55 -> V_954 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_545 . V_49 ) {
V_55 -> V_955 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_553 ) {
if ( V_55 -> V_956 ( V_2 ) ) {
-- V_2 -> V_5 . V_553 ;
V_2 -> V_5 . V_552 = true ;
V_55 -> V_954 ( V_2 ) ;
}
} else if ( F_436 ( V_2 ) ) {
if ( V_55 -> V_957 ( V_2 ) ) {
F_209 ( V_2 , F_445 ( V_2 ) ,
false ) ;
V_55 -> V_955 ( V_2 ) ;
}
}
}
static void F_446 ( struct V_1 * V_2 )
{
if ( F_53 ( V_2 , V_135 ) &&
! V_2 -> V_126 ) {
F_447 ( V_121 , V_2 -> V_5 . V_120 ) ;
V_2 -> V_126 = 1 ;
}
}
static void F_448 ( struct V_1 * V_2 )
{
if ( V_2 -> V_126 ) {
if ( V_2 -> V_5 . V_120 != V_125 )
F_447 ( V_121 , V_125 ) ;
V_2 -> V_126 = 0 ;
}
}
static void F_215 ( struct V_1 * V_2 )
{
unsigned V_797 = 2 ;
if ( V_55 -> V_555 ( V_2 ) || V_2 -> V_5 . V_552 )
V_797 = 1 ;
V_2 -> V_5 . V_553 += F_449 ( & V_2 -> V_5 . V_67 , 0 ) ;
V_2 -> V_5 . V_553 = F_273 ( V_2 -> V_5 . V_553 , V_797 ) ;
F_22 ( V_47 , V_2 ) ;
}
static int F_450 ( struct V_1 * V_2 )
{
int V_99 ;
bool V_958 = ! F_73 ( V_2 -> V_81 ) &&
V_2 -> V_739 -> V_944 ;
bool V_959 = 0 ;
if ( V_2 -> V_515 ) {
if ( F_451 ( V_960 , V_2 ) )
F_452 ( V_2 ) ;
if ( F_451 ( V_961 , V_2 ) )
F_453 ( V_2 ) ;
if ( F_451 ( V_255 , V_2 ) ) {
V_99 = F_117 ( V_2 ) ;
if ( F_70 ( V_99 ) )
goto V_93;
}
if ( F_451 ( V_962 , V_2 ) )
F_68 ( V_2 ) ;
if ( F_451 ( V_963 , V_2 ) )
V_55 -> V_964 ( V_2 ) ;
if ( F_451 ( V_965 , V_2 ) ) {
V_2 -> V_739 -> V_754 = V_966 ;
V_99 = 0 ;
goto V_93;
}
if ( F_451 ( V_53 , V_2 ) ) {
V_2 -> V_739 -> V_754 = V_967 ;
V_99 = 0 ;
goto V_93;
}
if ( F_451 ( V_968 , V_2 ) ) {
V_2 -> V_969 = 0 ;
V_55 -> V_970 ( V_2 ) ;
}
if ( F_451 ( V_971 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_972 = true ;
V_99 = 1 ;
goto V_93;
}
if ( F_451 ( V_376 , V_2 ) )
F_151 ( V_2 ) ;
if ( F_451 ( V_68 , V_2 ) )
F_215 ( V_2 ) ;
V_959 =
F_451 ( V_973 , V_2 ) ;
if ( F_451 ( V_974 , V_2 ) )
F_454 ( V_2 ) ;
if ( F_451 ( V_975 , V_2 ) )
F_455 ( V_2 ) ;
}
if ( F_451 ( V_47 , V_2 ) || V_958 ) {
F_443 ( V_2 ) ;
if ( V_2 -> V_5 . V_553 )
V_55 -> V_976 ( V_2 ) ;
else if ( F_436 ( V_2 ) || V_958 )
V_55 -> V_977 ( V_2 ) ;
if ( F_456 ( V_2 ) ) {
F_207 ( V_2 ) ;
F_457 ( V_2 ) ;
}
}
V_99 = F_458 ( V_2 ) ;
if ( F_70 ( V_99 ) ) {
goto V_978;
}
F_160 () ;
V_55 -> V_979 ( V_2 ) ;
if ( V_2 -> V_969 )
F_356 ( V_2 ) ;
F_446 ( V_2 ) ;
V_2 -> V_827 = V_980 ;
F_459 () ;
F_268 () ;
if ( V_2 -> V_827 == V_981 || V_2 -> V_515
|| F_460 () || F_461 ( V_343 ) ) {
V_2 -> V_827 = V_982 ;
F_12 () ;
F_269 () ;
F_161 () ;
V_99 = 1 ;
goto V_978;
}
F_182 ( & V_2 -> V_81 -> V_422 , V_2 -> V_983 ) ;
if ( V_959 )
F_462 ( V_2 -> V_510 ) ;
F_463 () ;
if ( F_70 ( V_2 -> V_5 . V_152 ) ) {
F_464 ( 0 , 7 ) ;
F_464 ( V_2 -> V_5 . V_157 [ 0 ] , 0 ) ;
F_464 ( V_2 -> V_5 . V_157 [ 1 ] , 1 ) ;
F_464 ( V_2 -> V_5 . V_157 [ 2 ] , 2 ) ;
F_464 ( V_2 -> V_5 . V_157 [ 3 ] , 3 ) ;
}
F_465 ( V_2 -> V_984 ) ;
V_55 -> V_739 ( V_2 ) ;
if ( F_466 () )
F_467 () ;
V_2 -> V_5 . V_246 = V_55 -> V_253 ( V_2 ) ;
V_2 -> V_827 = V_982 ;
F_12 () ;
F_269 () ;
++ V_2 -> V_59 . V_985 ;
F_468 () ;
F_469 () ;
F_161 () ;
V_2 -> V_983 = F_181 ( & V_2 -> V_81 -> V_422 ) ;
if ( F_70 ( V_986 == V_987 ) ) {
unsigned long V_943 = F_368 ( V_2 ) ;
F_470 ( V_987 , ( void * ) V_943 ) ;
}
if ( F_70 ( V_2 -> V_5 . V_988 ) )
F_22 ( V_255 , V_2 ) ;
if ( V_2 -> V_5 . V_989 )
F_471 ( V_2 ) ;
V_99 = V_55 -> V_990 ( V_2 ) ;
return V_99 ;
V_978:
V_55 -> V_978 ( V_2 ) ;
if ( F_70 ( V_2 -> V_5 . V_989 ) )
F_471 ( V_2 ) ;
V_93:
return V_99 ;
}
static int F_472 ( struct V_1 * V_2 )
{
int V_99 ;
struct V_81 * V_81 = V_2 -> V_81 ;
if ( F_70 ( V_2 -> V_5 . V_915 == V_991 ) ) {
F_100 ( L_28 ,
V_2 -> V_984 , V_2 -> V_5 . V_556 ) ;
F_473 ( V_2 ) ;
V_99 = F_474 ( V_2 ) ;
if ( V_99 )
return V_99 ;
V_2 -> V_5 . V_915 = V_992 ;
}
V_2 -> V_983 = F_181 ( & V_81 -> V_422 ) ;
V_99 = F_440 ( V_2 ) ;
if ( V_99 ) {
F_182 ( & V_81 -> V_422 , V_2 -> V_983 ) ;
return V_99 ;
}
V_99 = 1 ;
while ( V_99 > 0 ) {
if ( V_2 -> V_5 . V_915 == V_992 &&
! V_2 -> V_5 . V_6 . V_972 )
V_99 = F_450 ( V_2 ) ;
else {
F_182 ( & V_81 -> V_422 , V_2 -> V_983 ) ;
F_475 ( V_2 ) ;
V_2 -> V_983 = F_181 ( & V_81 -> V_422 ) ;
if ( F_451 ( V_993 , V_2 ) )
{
switch( V_2 -> V_5 . V_915 ) {
case V_916 :
V_2 -> V_5 . V_915 =
V_992 ;
case V_992 :
V_2 -> V_5 . V_6 . V_972 = false ;
break;
case V_991 :
default:
V_99 = - V_994 ;
break;
}
}
}
if ( V_99 <= 0 )
break;
F_476 ( V_995 , & V_2 -> V_515 ) ;
if ( F_477 ( V_2 ) )
F_478 ( V_2 ) ;
if ( F_435 ( V_2 ) ) {
V_99 = - V_994 ;
V_2 -> V_739 -> V_754 = V_996 ;
++ V_2 -> V_59 . V_997 ;
}
F_479 ( V_2 ) ;
if ( F_461 ( V_343 ) ) {
V_99 = - V_994 ;
V_2 -> V_739 -> V_754 = V_996 ;
++ V_2 -> V_59 . V_998 ;
}
if ( F_460 () ) {
F_182 ( & V_81 -> V_422 , V_2 -> V_983 ) ;
F_480 ( V_2 ) ;
V_2 -> V_983 = F_181 ( & V_81 -> V_422 ) ;
}
}
F_182 ( & V_81 -> V_422 , V_2 -> V_983 ) ;
F_441 ( V_2 ) ;
return V_99 ;
}
static inline int F_481 ( struct V_1 * V_2 )
{
int V_99 ;
V_2 -> V_983 = F_181 ( & V_2 -> V_81 -> V_422 ) ;
V_99 = F_482 ( V_2 , V_857 ) ;
F_182 ( & V_2 -> V_81 -> V_422 , V_2 -> V_983 ) ;
if ( V_99 != V_842 )
return 0 ;
return 1 ;
}
static int V_870 ( struct V_1 * V_2 )
{
F_283 ( ! V_2 -> V_5 . V_769 . V_644 ) ;
return F_481 ( V_2 ) ;
}
static int V_872 ( struct V_1 * V_2 )
{
struct V_945 * V_739 = V_2 -> V_739 ;
struct V_737 * V_738 ;
unsigned V_74 ;
F_283 ( ! V_2 -> V_750 ) ;
V_738 = & V_2 -> V_734 [ V_2 -> V_751 ] ;
V_74 = F_273 ( 8u , V_738 -> V_74 ) ;
if ( ! V_2 -> V_753 )
memcpy ( V_738 -> V_30 , V_739 -> V_740 . V_30 , V_74 ) ;
if ( V_738 -> V_74 <= 8 ) {
V_738 ++ ;
V_2 -> V_751 ++ ;
} else {
V_738 -> V_30 += V_74 ;
V_738 -> V_336 += V_74 ;
V_738 -> V_74 -= V_74 ;
}
if ( V_2 -> V_751 == V_2 -> V_745 ) {
V_2 -> V_750 = 0 ;
if ( V_2 -> V_753 )
return 1 ;
V_2 -> V_733 = 1 ;
return F_481 ( V_2 ) ;
}
V_739 -> V_754 = V_755 ;
V_739 -> V_740 . V_756 = V_738 -> V_336 ;
if ( V_2 -> V_753 )
memcpy ( V_739 -> V_740 . V_30 , V_738 -> V_30 , F_273 ( 8u , V_738 -> V_74 ) ) ;
V_739 -> V_740 . V_74 = F_273 ( 8u , V_738 -> V_74 ) ;
V_739 -> V_740 . V_752 = V_2 -> V_753 ;
V_2 -> V_5 . V_869 = V_872 ;
return 0 ;
}
int F_483 ( struct V_1 * V_2 , struct V_945 * V_945 )
{
int V_99 ;
T_15 V_999 ;
if ( ! F_484 ( V_343 ) && F_485 ( V_343 ) )
return - V_314 ;
if ( V_2 -> V_1000 )
F_486 ( V_1001 , & V_2 -> V_1002 , & V_999 ) ;
if ( F_70 ( V_2 -> V_5 . V_915 == V_1003 ) ) {
F_475 ( V_2 ) ;
F_476 ( V_993 , & V_2 -> V_515 ) ;
V_99 = - V_1004 ;
goto V_93;
}
if ( ! F_73 ( V_2 -> V_81 ) ) {
if ( F_72 ( V_2 , V_945 -> V_145 ) != 0 ) {
V_99 = - V_505 ;
goto V_93;
}
}
if ( F_70 ( V_2 -> V_5 . V_869 ) ) {
int (* F_487)( struct V_1 * ) = V_2 -> V_5 . V_869 ;
V_2 -> V_5 . V_869 = NULL ;
V_99 = F_487 ( V_2 ) ;
if ( V_99 <= 0 )
goto V_93;
} else
F_102 ( V_2 -> V_5 . V_769 . V_644 || V_2 -> V_750 ) ;
V_99 = F_472 ( V_2 ) ;
V_93:
F_438 ( V_2 ) ;
if ( V_2 -> V_1000 )
F_486 ( V_1001 , & V_999 , NULL ) ;
return V_99 ;
}
int F_488 ( struct V_1 * V_2 , struct V_1005 * V_521 )
{
if ( V_2 -> V_5 . V_874 ) {
F_489 ( & V_2 -> V_5 . V_816 ) ;
V_2 -> V_5 . V_874 = false ;
}
V_521 -> V_1006 = F_83 ( V_2 , V_168 ) ;
V_521 -> V_1007 = F_83 ( V_2 , V_928 ) ;
V_521 -> V_1008 = F_83 ( V_2 , V_167 ) ;
V_521 -> V_1009 = F_83 ( V_2 , V_169 ) ;
V_521 -> V_1010 = F_83 ( V_2 , V_930 ) ;
V_521 -> V_1011 = F_83 ( V_2 , V_929 ) ;
V_521 -> V_1012 = F_83 ( V_2 , V_1013 ) ;
V_521 -> V_1014 = F_83 ( V_2 , V_1015 ) ;
#ifdef F_51
V_521 -> V_1016 = F_83 ( V_2 , V_931 ) ;
V_521 -> V_1017 = F_83 ( V_2 , V_1018 ) ;
V_521 -> V_1019 = F_83 ( V_2 , V_1020 ) ;
V_521 -> V_1021 = F_83 ( V_2 , V_1022 ) ;
V_521 -> V_1023 = F_83 ( V_2 , V_1024 ) ;
V_521 -> V_1025 = F_83 ( V_2 , V_1026 ) ;
V_521 -> V_1027 = F_83 ( V_2 , V_1028 ) ;
V_521 -> V_1029 = F_83 ( V_2 , V_1030 ) ;
#endif
V_521 -> V_943 = F_368 ( V_2 ) ;
V_521 -> V_1031 = F_367 ( V_2 ) ;
return 0 ;
}
int F_490 ( struct V_1 * V_2 , struct V_1005 * V_521 )
{
V_2 -> V_5 . V_835 = true ;
V_2 -> V_5 . V_874 = false ;
F_85 ( V_2 , V_168 , V_521 -> V_1006 ) ;
F_85 ( V_2 , V_928 , V_521 -> V_1007 ) ;
F_85 ( V_2 , V_167 , V_521 -> V_1008 ) ;
F_85 ( V_2 , V_169 , V_521 -> V_1009 ) ;
F_85 ( V_2 , V_930 , V_521 -> V_1010 ) ;
F_85 ( V_2 , V_929 , V_521 -> V_1011 ) ;
F_85 ( V_2 , V_1013 , V_521 -> V_1012 ) ;
F_85 ( V_2 , V_1015 , V_521 -> V_1014 ) ;
#ifdef F_51
F_85 ( V_2 , V_931 , V_521 -> V_1016 ) ;
F_85 ( V_2 , V_1018 , V_521 -> V_1017 ) ;
F_85 ( V_2 , V_1020 , V_521 -> V_1019 ) ;
F_85 ( V_2 , V_1022 , V_521 -> V_1021 ) ;
F_85 ( V_2 , V_1024 , V_521 -> V_1023 ) ;
F_85 ( V_2 , V_1026 , V_521 -> V_1025 ) ;
F_85 ( V_2 , V_1028 , V_521 -> V_1027 ) ;
F_85 ( V_2 , V_1030 , V_521 -> V_1029 ) ;
#endif
F_373 ( V_2 , V_521 -> V_943 ) ;
F_338 ( V_2 , V_521 -> V_1031 ) ;
V_2 -> V_5 . V_48 . V_49 = false ;
F_22 ( V_47 , V_2 ) ;
return 0 ;
}
void F_491 ( struct V_1 * V_2 , int * V_156 , int * V_802 )
{
struct V_713 V_1032 ;
F_281 ( V_2 , & V_1032 , V_1033 ) ;
* V_156 = V_1032 . V_156 ;
* V_802 = V_1032 . V_802 ;
}
int F_492 ( struct V_1 * V_2 ,
struct V_1034 * V_1035 )
{
struct V_785 V_786 ;
F_281 ( V_2 , & V_1035 -> V_1032 , V_1033 ) ;
F_281 ( V_2 , & V_1035 -> V_1036 , V_1037 ) ;
F_281 ( V_2 , & V_1035 -> V_1038 , V_1039 ) ;
F_281 ( V_2 , & V_1035 -> V_1040 , V_1041 ) ;
F_281 ( V_2 , & V_1035 -> V_1042 , V_1043 ) ;
F_281 ( V_2 , & V_1035 -> V_1044 , V_1045 ) ;
F_281 ( V_2 , & V_1035 -> V_1046 , V_1047 ) ;
F_281 ( V_2 , & V_1035 -> V_1048 , V_1049 ) ;
V_55 -> V_788 ( V_2 , & V_786 ) ;
V_1035 -> V_1050 . V_797 = V_786 . V_427 ;
V_1035 -> V_1050 . V_798 = V_786 . V_62 ;
V_55 -> V_787 ( V_2 , & V_786 ) ;
V_1035 -> V_1051 . V_797 = V_786 . V_427 ;
V_1035 -> V_1051 . V_798 = V_786 . V_62 ;
V_1035 -> V_100 = F_50 ( V_2 ) ;
V_1035 -> V_61 = V_2 -> V_5 . V_61 ;
V_1035 -> V_84 = F_48 ( V_2 ) ;
V_1035 -> V_127 = F_61 ( V_2 ) ;
V_1035 -> V_145 = F_75 ( V_2 ) ;
V_1035 -> V_110 = V_2 -> V_5 . V_110 ;
V_1035 -> V_29 = F_17 ( V_2 ) ;
memset ( V_1035 -> V_1052 , 0 , sizeof V_1035 -> V_1052 ) ;
if ( V_2 -> V_5 . V_545 . V_49 && ! V_2 -> V_5 . V_545 . V_546 )
F_198 ( V_2 -> V_5 . V_545 . V_16 ,
( unsigned long * ) V_1035 -> V_1052 ) ;
return 0 ;
}
int F_493 ( struct V_1 * V_2 ,
struct V_1053 * V_915 )
{
V_915 -> V_915 = V_2 -> V_5 . V_915 ;
return 0 ;
}
int F_494 ( struct V_1 * V_2 ,
struct V_1053 * V_915 )
{
V_2 -> V_5 . V_915 = V_915 -> V_915 ;
F_22 ( V_47 , V_2 ) ;
return 0 ;
}
int F_495 ( struct V_1 * V_2 , V_765 V_1054 , int V_1055 ,
int V_1056 , bool V_51 , T_1 V_42 )
{
struct V_727 * V_728 = & V_2 -> V_5 . V_816 ;
int V_88 ;
F_366 ( V_2 ) ;
V_88 = F_496 ( V_728 , V_1054 , V_1055 , V_1056 ,
V_51 , V_42 ) ;
if ( V_88 )
return V_840 ;
F_373 ( V_2 , V_728 -> V_826 ) ;
F_338 ( V_2 , V_728 -> V_825 ) ;
F_22 ( V_47 , V_2 ) ;
return V_842 ;
}
int F_497 ( struct V_1 * V_2 ,
struct V_1034 * V_1035 )
{
int V_1057 = 0 ;
int V_1058 , V_1059 , V_287 ;
struct V_785 V_786 ;
if ( ! F_62 ( V_2 ) && ( V_1035 -> V_127 & V_135 ) )
return - V_505 ;
V_786 . V_427 = V_1035 -> V_1050 . V_797 ;
V_786 . V_62 = V_1035 -> V_1050 . V_798 ;
V_55 -> V_790 ( V_2 , & V_786 ) ;
V_786 . V_427 = V_1035 -> V_1051 . V_797 ;
V_786 . V_62 = V_1035 -> V_1051 . V_798 ;
V_55 -> V_789 ( V_2 , & V_786 ) ;
V_2 -> V_5 . V_61 = V_1035 -> V_61 ;
V_1057 |= F_48 ( V_2 ) != V_1035 -> V_84 ;
V_2 -> V_5 . V_84 = V_1035 -> V_84 ;
F_43 ( V_142 , ( V_143 * ) & V_2 -> V_5 . V_96 ) ;
F_72 ( V_2 , V_1035 -> V_145 ) ;
V_1057 |= V_2 -> V_5 . V_110 != V_1035 -> V_110 ;
V_55 -> F_86 ( V_2 , V_1035 -> V_110 ) ;
F_18 ( V_2 , V_1035 -> V_29 ) ;
V_1057 |= F_50 ( V_2 ) != V_1035 -> V_100 ;
V_55 -> V_116 ( V_2 , V_1035 -> V_100 ) ;
V_2 -> V_5 . V_100 = V_1035 -> V_100 ;
V_1057 |= F_61 ( V_2 ) != V_1035 -> V_127 ;
V_55 -> V_138 ( V_2 , V_1035 -> V_127 ) ;
if ( V_1035 -> V_127 & V_135 )
F_66 ( V_2 ) ;
V_287 = F_181 ( & V_2 -> V_81 -> V_422 ) ;
if ( ! F_45 ( V_2 ) && F_46 ( V_2 ) ) {
F_40 ( V_2 , V_2 -> V_5 . V_83 , F_48 ( V_2 ) ) ;
V_1057 = 1 ;
}
F_182 ( & V_2 -> V_81 -> V_422 , V_287 ) ;
if ( V_1057 )
F_55 ( V_2 ) ;
V_1059 = V_525 ;
V_1058 = F_498 (
( const unsigned long * ) V_1035 -> V_1052 , V_1059 ) ;
if ( V_1058 < V_1059 ) {
F_209 ( V_2 , V_1058 , false ) ;
F_100 ( L_29 , V_1058 ) ;
}
F_280 ( V_2 , & V_1035 -> V_1032 , V_1033 ) ;
F_280 ( V_2 , & V_1035 -> V_1036 , V_1037 ) ;
F_280 ( V_2 , & V_1035 -> V_1038 , V_1039 ) ;
F_280 ( V_2 , & V_1035 -> V_1040 , V_1041 ) ;
F_280 ( V_2 , & V_1035 -> V_1042 , V_1043 ) ;
F_280 ( V_2 , & V_1035 -> V_1044 , V_1045 ) ;
F_280 ( V_2 , & V_1035 -> V_1046 , V_1047 ) ;
F_280 ( V_2 , & V_1035 -> V_1048 , V_1049 ) ;
F_207 ( V_2 ) ;
if ( F_499 ( V_2 ) && F_368 ( V_2 ) == 0xfff0 &&
V_1035 -> V_1032 . V_791 == 0xf000 && V_1035 -> V_1032 . V_798 == 0xffff0000 &&
! F_369 ( V_2 ) )
V_2 -> V_5 . V_915 = V_992 ;
F_22 ( V_47 , V_2 ) ;
return 0 ;
}
int F_500 ( struct V_1 * V_2 ,
struct V_1060 * V_1061 )
{
unsigned long V_1031 ;
int V_3 , V_99 ;
if ( V_1061 -> V_651 & ( V_1062 | V_1063 ) ) {
V_99 = - V_1064 ;
if ( V_2 -> V_5 . V_48 . V_49 )
goto V_93;
if ( V_1061 -> V_651 & V_1062 )
F_23 ( V_2 , V_1065 ) ;
else
F_23 ( V_2 , V_1066 ) ;
}
V_1031 = F_367 ( V_2 ) ;
V_2 -> V_148 = V_1061 -> V_651 ;
if ( ! ( V_2 -> V_148 & V_1067 ) )
V_2 -> V_148 = 0 ;
if ( V_2 -> V_148 & V_149 ) {
for ( V_3 = 0 ; V_3 < V_1068 ; ++ V_3 )
V_2 -> V_5 . V_157 [ V_3 ] = V_1061 -> V_5 . V_1069 [ V_3 ] ;
V_2 -> V_5 . V_150 = V_1061 -> V_5 . V_1069 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_1068 ; V_3 ++ )
V_2 -> V_5 . V_157 [ V_3 ] = V_2 -> V_5 . V_156 [ V_3 ] ;
}
F_77 ( V_2 ) ;
if ( V_2 -> V_148 & V_1070 )
V_2 -> V_5 . V_1071 = F_368 ( V_2 ) +
F_322 ( V_2 , V_1033 ) ;
F_338 ( V_2 , V_1031 ) ;
V_55 -> V_1072 ( V_2 ) ;
V_99 = 0 ;
V_93:
return V_99 ;
}
int F_501 ( struct V_1 * V_2 ,
struct V_1073 * V_1046 )
{
unsigned long V_1074 = V_1046 -> V_1075 ;
T_4 V_336 ;
int V_287 ;
V_287 = F_181 ( & V_2 -> V_81 -> V_422 ) ;
V_336 = F_287 ( V_2 , V_1074 , NULL ) ;
F_182 ( & V_2 -> V_81 -> V_422 , V_287 ) ;
V_1046 -> V_1076 = V_336 ;
V_1046 -> V_1077 = V_336 != V_79 ;
V_1046 -> V_1078 = 1 ;
V_1046 -> V_1079 = 0 ;
return 0 ;
}
int F_502 ( struct V_1 * V_2 , struct V_1080 * V_1081 )
{
struct V_573 * V_572 =
& V_2 -> V_5 . V_568 . V_569 -> V_572 ;
memcpy ( V_1081 -> V_1082 , V_572 -> V_1083 , 128 ) ;
V_1081 -> V_1084 = V_572 -> V_1085 ;
V_1081 -> V_1086 = V_572 -> V_1087 ;
V_1081 -> V_1088 = V_572 -> V_1089 ;
V_1081 -> V_1090 = V_572 -> V_1091 ;
V_1081 -> V_1092 = V_572 -> V_943 ;
V_1081 -> V_1093 = V_572 -> V_1094 ;
memcpy ( V_1081 -> V_1095 , V_572 -> V_1096 , sizeof V_572 -> V_1096 ) ;
return 0 ;
}
int F_503 ( struct V_1 * V_2 , struct V_1080 * V_1081 )
{
struct V_573 * V_572 =
& V_2 -> V_5 . V_568 . V_569 -> V_572 ;
memcpy ( V_572 -> V_1083 , V_1081 -> V_1082 , 128 ) ;
V_572 -> V_1085 = V_1081 -> V_1084 ;
V_572 -> V_1087 = V_1081 -> V_1086 ;
V_572 -> V_1089 = V_1081 -> V_1088 ;
V_572 -> V_1091 = V_1081 -> V_1090 ;
V_572 -> V_943 = V_1081 -> V_1092 ;
V_572 -> V_1094 = V_1081 -> V_1093 ;
memcpy ( V_572 -> V_1096 , V_1081 -> V_1095 , sizeof V_572 -> V_1096 ) ;
return 0 ;
}
int F_504 ( struct V_1 * V_2 )
{
int V_54 ;
V_54 = F_505 ( & V_2 -> V_5 . V_568 ) ;
if ( V_54 )
return V_54 ;
F_506 ( & V_2 -> V_5 . V_568 ) ;
V_2 -> V_5 . V_120 = V_122 ;
V_2 -> V_5 . V_100 |= V_107 ;
return 0 ;
}
static void F_507 ( struct V_1 * V_2 )
{
F_508 ( & V_2 -> V_5 . V_568 ) ;
}
void F_356 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1097 )
return;
F_448 ( V_2 ) ;
V_2 -> V_1097 = 1 ;
F_509 () ;
F_510 ( & V_2 -> V_5 . V_568 ) ;
F_511 ( 1 ) ;
}
void F_203 ( struct V_1 * V_2 )
{
F_448 ( V_2 ) ;
if ( ! V_2 -> V_1097 )
return;
V_2 -> V_1097 = 0 ;
F_512 ( & V_2 -> V_5 . V_568 ) ;
F_513 () ;
++ V_2 -> V_59 . V_1098 ;
F_22 ( V_968 , V_2 ) ;
F_511 ( 0 ) ;
}
void F_514 ( struct V_1 * V_2 )
{
F_148 ( V_2 ) ;
F_515 ( V_2 -> V_5 . V_512 ) ;
F_507 ( V_2 ) ;
V_55 -> V_1099 ( V_2 ) ;
}
struct V_1 * F_516 ( struct V_81 * V_81 ,
unsigned int V_1100 )
{
if ( F_115 () && F_260 ( & V_81 -> V_679 ) != 0 )
F_316 ( V_767
L_30
L_31 ) ;
return V_55 -> V_1101 ( V_81 , V_1100 ) ;
}
int F_517 ( struct V_1 * V_2 )
{
int V_99 ;
V_2 -> V_5 . V_282 . V_1102 = 1 ;
V_99 = V_513 ( V_2 ) ;
if ( V_99 )
return V_99 ;
V_99 = F_474 ( V_2 ) ;
if ( V_99 == 0 )
V_99 = F_518 ( V_2 ) ;
V_518 ( V_2 ) ;
return V_99 ;
}
void F_519 ( struct V_1 * V_2 )
{
int V_99 ;
V_2 -> V_5 . V_6 . V_337 = 0 ;
V_99 = V_513 ( V_2 ) ;
F_283 ( V_99 ) ;
F_452 ( V_2 ) ;
V_518 ( V_2 ) ;
F_507 ( V_2 ) ;
V_55 -> V_1099 ( V_2 ) ;
}
int F_474 ( struct V_1 * V_2 )
{
F_520 ( & V_2 -> V_5 . V_67 , 0 ) ;
V_2 -> V_5 . V_553 = 0 ;
V_2 -> V_5 . V_552 = false ;
memset ( V_2 -> V_5 . V_156 , 0 , sizeof( V_2 -> V_5 . V_156 ) ) ;
V_2 -> V_5 . V_159 = V_161 ;
V_2 -> V_5 . V_147 = V_163 ;
F_77 ( V_2 ) ;
F_22 ( V_47 , V_2 ) ;
V_2 -> V_5 . V_6 . V_337 = 0 ;
V_2 -> V_5 . V_341 . V_337 = 0 ;
F_148 ( V_2 ) ;
F_54 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_972 = false ;
F_521 ( V_2 ) ;
return V_55 -> V_1103 ( V_2 ) ;
}
int F_522 ( void * V_506 )
{
struct V_81 * V_81 ;
struct V_1 * V_2 ;
int V_3 ;
int V_88 ;
T_2 V_1104 ;
T_2 V_1105 = 0 ;
bool V_1106 , V_1107 = false ;
F_13 () ;
V_88 = V_55 -> V_1108 ( V_506 ) ;
if ( V_88 != 0 )
return V_88 ;
V_1104 = F_199 () ;
V_1106 = ! F_115 () ;
F_398 (kvm, &vm_list, vm_list) {
F_173 (i, vcpu, kvm) {
if ( ! V_1106 && V_2 -> V_510 == F_399 () )
F_198 ( V_255 , & V_2 -> V_515 ) ;
if ( V_1106 && V_2 -> V_5 . V_517 > V_1104 ) {
V_1107 = true ;
if ( V_2 -> V_5 . V_517 > V_1105 )
V_1105 = V_2 -> V_5 . V_517 ;
}
}
}
if ( V_1107 ) {
T_2 V_1109 = V_1105 - V_1104 ;
F_398 (kvm, &vm_list, vm_list) {
F_173 (i, vcpu, kvm) {
V_2 -> V_5 . V_514 += V_1109 ;
V_2 -> V_5 . V_517 = V_1104 ;
}
V_81 -> V_5 . V_235 = 0 ;
V_81 -> V_5 . V_236 = 0 ;
}
}
return 0 ;
}
void F_523 ( void * V_506 )
{
V_55 -> V_1110 ( V_506 ) ;
F_16 ( V_506 ) ;
}
int F_524 ( void )
{
return V_55 -> V_1111 () ;
}
void F_525 ( void )
{
V_55 -> V_1112 () ;
}
void F_526 ( void * V_1113 )
{
V_55 -> V_1114 ( V_1113 ) ;
}
bool F_527 ( struct V_1 * V_2 )
{
return F_73 ( V_2 -> V_81 ) == ( V_2 -> V_5 . V_522 != NULL ) ;
}
int F_528 ( struct V_1 * V_2 )
{
struct V_312 * V_312 ;
struct V_81 * V_81 ;
int V_99 ;
F_283 ( V_2 -> V_81 == NULL ) ;
V_81 = V_2 -> V_81 ;
V_2 -> V_5 . V_816 . V_742 = & V_1115 ;
if ( ! F_73 ( V_81 ) || F_499 ( V_2 ) )
V_2 -> V_5 . V_915 = V_992 ;
else
V_2 -> V_5 . V_915 = V_1003 ;
V_312 = F_529 ( V_587 | V_1116 ) ;
if ( ! V_312 ) {
V_99 = - V_314 ;
goto V_1117;
}
V_2 -> V_5 . V_772 = F_530 ( V_312 ) ;
F_111 ( V_2 , V_891 ) ;
V_99 = F_531 ( V_2 ) ;
if ( V_99 < 0 )
goto V_1118;
if ( F_73 ( V_81 ) ) {
V_99 = F_532 ( V_2 ) ;
if ( V_99 < 0 )
goto V_1119;
} else
F_533 ( & V_1120 ) ;
V_2 -> V_5 . V_301 = F_226 ( V_378 * sizeof( T_2 ) * 4 ,
V_587 ) ;
if ( ! V_2 -> V_5 . V_301 ) {
V_99 = - V_314 ;
goto V_1121;
}
V_2 -> V_5 . V_293 = V_378 ;
if ( ! F_534 ( & V_2 -> V_5 . V_512 , V_587 ) )
goto V_1122;
F_1 ( V_2 ) ;
F_535 ( V_2 ) ;
return 0 ;
V_1122:
F_134 ( V_2 -> V_5 . V_301 ) ;
V_1121:
F_536 ( V_2 ) ;
V_1119:
F_537 ( V_2 ) ;
V_1118:
F_538 ( ( unsigned long ) V_2 -> V_5 . V_772 ) ;
V_1117:
return V_99 ;
}
void F_539 ( struct V_1 * V_2 )
{
int V_287 ;
F_540 ( V_2 ) ;
F_134 ( V_2 -> V_5 . V_301 ) ;
F_536 ( V_2 ) ;
V_287 = F_181 ( & V_2 -> V_81 -> V_422 ) ;
F_537 ( V_2 ) ;
F_182 ( & V_2 -> V_81 -> V_422 , V_287 ) ;
F_538 ( ( unsigned long ) V_2 -> V_5 . V_772 ) ;
if ( ! F_73 ( V_2 -> V_81 ) )
F_541 ( & V_1120 ) ;
}
int F_542 ( struct V_81 * V_81 , unsigned long type )
{
if ( type )
return - V_505 ;
F_543 ( & V_81 -> V_5 . V_1123 ) ;
F_543 ( & V_81 -> V_5 . V_1124 ) ;
F_198 ( V_664 , & V_81 -> V_5 . V_1125 ) ;
F_198 ( V_1126 ,
& V_81 -> V_5 . V_1125 ) ;
F_544 ( & V_81 -> V_5 . V_233 ) ;
F_545 ( & V_81 -> V_5 . V_1127 ) ;
return 0 ;
}
static void F_546 ( struct V_1 * V_2 )
{
int V_99 ;
V_99 = V_513 ( V_2 ) ;
F_283 ( V_99 ) ;
F_452 ( V_2 ) ;
V_518 ( V_2 ) ;
}
static void F_547 ( struct V_81 * V_81 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_173 (i, vcpu, kvm) {
F_54 ( V_2 ) ;
F_546 ( V_2 ) ;
}
F_173 (i, vcpu, kvm)
F_514 ( V_2 ) ;
F_165 ( & V_81 -> V_393 ) ;
for ( V_3 = 0 ; V_3 < F_260 ( & V_81 -> V_679 ) ; V_3 ++ )
V_81 -> V_1128 [ V_3 ] = NULL ;
F_520 ( & V_81 -> V_679 , 0 ) ;
F_166 ( & V_81 -> V_393 ) ;
}
void F_548 ( struct V_81 * V_81 )
{
F_549 ( V_81 ) ;
F_550 ( V_81 ) ;
}
void F_551 ( struct V_81 * V_81 )
{
F_552 ( V_81 ) ;
F_134 ( V_81 -> V_5 . V_676 ) ;
F_134 ( V_81 -> V_5 . V_1129 ) ;
F_547 ( V_81 ) ;
if ( V_81 -> V_5 . V_1130 )
F_553 ( V_81 -> V_5 . V_1130 ) ;
if ( V_81 -> V_5 . V_1131 )
F_553 ( V_81 -> V_5 . V_1131 ) ;
F_134 ( F_554 ( V_81 -> V_5 . V_1132 , 1 ) ) ;
}
void F_555 ( struct V_654 * free ,
struct V_654 * V_1133 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1134 ; ++ V_3 ) {
if ( ! V_1133 || free -> V_5 . V_1135 [ V_3 ] != V_1133 -> V_5 . V_1135 [ V_3 ] ) {
F_556 ( free -> V_5 . V_1135 [ V_3 ] ) ;
free -> V_5 . V_1135 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1133 || free -> V_5 . V_1136 [ V_3 - 1 ] !=
V_1133 -> V_5 . V_1136 [ V_3 - 1 ] ) {
F_556 ( free -> V_5 . V_1136 [ V_3 - 1 ] ) ;
free -> V_5 . V_1136 [ V_3 - 1 ] = NULL ;
}
}
}
int F_557 ( struct V_654 * V_10 , unsigned long V_1137 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1134 ; ++ V_3 ) {
unsigned long V_1138 ;
int V_1139 ;
int V_665 = V_3 + 1 ;
V_1139 = F_558 ( V_10 -> V_1140 + V_1137 - 1 ,
V_10 -> V_1140 , V_665 ) + 1 ;
V_10 -> V_5 . V_1135 [ V_3 ] =
F_559 ( V_1139 * sizeof( * V_10 -> V_5 . V_1135 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1135 [ V_3 ] )
goto V_315;
if ( V_3 == 0 )
continue;
V_10 -> V_5 . V_1136 [ V_3 - 1 ] = F_559 ( V_1139 *
sizeof( * V_10 -> V_5 . V_1136 [ V_3 - 1 ] ) ) ;
if ( ! V_10 -> V_5 . V_1136 [ V_3 - 1 ] )
goto V_315;
if ( V_10 -> V_1140 & ( F_560 ( V_665 ) - 1 ) )
V_10 -> V_5 . V_1136 [ V_3 - 1 ] [ 0 ] . V_1141 = 1 ;
if ( ( V_10 -> V_1140 + V_1137 ) & ( F_560 ( V_665 ) - 1 ) )
V_10 -> V_5 . V_1136 [ V_3 - 1 ] [ V_1139 - 1 ] . V_1141 = 1 ;
V_1138 = V_10 -> V_1142 >> V_86 ;
if ( ( V_10 -> V_1140 ^ V_1138 ) & ( F_560 ( V_665 ) - 1 ) ||
! F_561 () ) {
unsigned long V_707 ;
for ( V_707 = 0 ; V_707 < V_1139 ; ++ V_707 )
V_10 -> V_5 . V_1136 [ V_3 - 1 ] [ V_707 ] . V_1141 = 1 ;
}
}
return 0 ;
V_315:
for ( V_3 = 0 ; V_3 < V_1134 ; ++ V_3 ) {
F_556 ( V_10 -> V_5 . V_1135 [ V_3 ] ) ;
V_10 -> V_5 . V_1135 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_556 ( V_10 -> V_5 . V_1136 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1136 [ V_3 - 1 ] = NULL ;
}
return - V_314 ;
}
int F_562 ( struct V_81 * V_81 ,
struct V_654 * V_655 ,
struct V_654 V_760 ,
struct V_1143 * V_1144 ,
int V_1145 )
{
int V_1137 = V_655 -> V_1137 ;
int V_1146 = V_1147 | V_1148 ;
if ( V_655 -> V_1100 >= V_474 )
V_1146 = V_1149 | V_1148 ;
if ( ! V_1145 ) {
if ( V_1137 && ! V_760 . V_1137 ) {
unsigned long V_1142 ;
V_1142 = F_563 ( NULL , 0 ,
V_1137 * V_87 ,
V_1150 | V_1151 ,
V_1146 ,
0 ) ;
if ( F_132 ( ( void * ) V_1142 ) )
return F_133 ( ( void * ) V_1142 ) ;
V_655 -> V_1142 = V_1142 ;
}
}
return 0 ;
}
void F_564 ( struct V_81 * V_81 ,
struct V_1143 * V_1144 ,
struct V_654 V_760 ,
int V_1145 )
{
int V_1152 = 0 , V_1137 = V_1144 -> V_1153 >> V_86 ;
if ( ! V_1145 && ! V_760 . V_1145 && V_760 . V_1137 && ! V_1137 ) {
int V_88 ;
V_88 = F_565 ( V_760 . V_1142 ,
V_760 . V_1137 * V_87 ) ;
if ( V_88 < 0 )
F_9 ( V_767
L_32
L_33 ) ;
}
if ( ! V_81 -> V_5 . V_627 )
V_1152 = F_566 ( V_81 ) ;
F_235 ( & V_81 -> V_626 ) ;
if ( V_1152 )
F_236 ( V_81 , V_1152 ) ;
F_567 ( V_81 , V_1144 -> V_10 ) ;
F_237 ( & V_81 -> V_626 ) ;
if ( V_1137 && V_760 . V_1140 != V_1144 -> V_1154 >> V_86 ) {
F_434 ( V_81 ) ;
F_568 ( V_81 ) ;
}
}
void F_569 ( struct V_81 * V_81 )
{
F_434 ( V_81 ) ;
F_568 ( V_81 ) ;
}
void F_570 ( struct V_81 * V_81 ,
struct V_654 * V_10 )
{
F_569 ( V_81 ) ;
}
int F_571 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_915 == V_992 &&
! V_2 -> V_5 . V_6 . V_972 )
|| ! F_572 ( & V_2 -> V_1155 . V_1156 )
|| V_2 -> V_5 . V_915 == V_991
|| F_260 ( & V_2 -> V_5 . V_67 ) ||
( F_437 ( V_2 ) &&
F_436 ( V_2 ) ) ;
}
int F_573 ( struct V_1 * V_2 )
{
return F_574 ( V_2 ) == V_980 ;
}
int F_437 ( struct V_1 * V_2 )
{
return V_55 -> V_957 ( V_2 ) ;
}
bool F_575 ( struct V_1 * V_2 , unsigned long V_1157 )
{
unsigned long V_1158 = F_368 ( V_2 ) +
F_322 ( V_2 , V_1033 ) ;
return V_1158 == V_1157 ;
}
unsigned long F_367 ( struct V_1 * V_2 )
{
unsigned long V_1031 ;
V_1031 = V_55 -> V_1159 ( V_2 ) ;
if ( V_2 -> V_148 & V_1070 )
V_1031 &= ~ V_1160 ;
return V_1031 ;
}
void F_338 ( struct V_1 * V_2 , unsigned long V_1031 )
{
if ( V_2 -> V_148 & V_1070 &&
F_575 ( V_2 , V_2 -> V_5 . V_1071 ) )
V_1031 |= V_1160 ;
V_55 -> V_1161 ( V_2 , V_1031 ) ;
F_22 ( V_47 , V_2 ) ;
}
void F_576 ( struct V_1 * V_2 , struct V_1162 * V_1163 )
{
int V_99 ;
if ( ( V_2 -> V_5 . V_66 . V_854 != V_1163 -> V_5 . V_854 ) ||
F_158 ( V_1163 -> V_312 ) )
return;
V_99 = F_458 ( V_2 ) ;
if ( F_70 ( V_99 ) )
return;
if ( ! V_2 -> V_5 . V_66 . V_854 &&
V_1163 -> V_5 . V_84 != V_2 -> V_5 . V_66 . V_1164 ( V_2 ) )
return;
V_2 -> V_5 . V_66 . V_1165 ( V_2 , V_1163 -> V_720 , 0 , true ) ;
}
static inline T_1 F_577 ( T_3 V_82 )
{
return F_578 ( V_82 & 0xffffffff , F_579 ( V_4 ) ) ;
}
static inline T_1 F_580 ( T_1 V_1166 )
{
return ( V_1166 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_581 ( struct V_1 * V_2 , T_3 V_82 )
{
T_1 V_1166 = F_577 ( V_82 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1166 ] != ~ 0 )
V_1166 = F_580 ( V_1166 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1166 ] = V_82 ;
}
static T_1 F_582 ( struct V_1 * V_2 , T_3 V_82 )
{
int V_3 ;
T_1 V_1166 = F_577 ( V_82 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1166 ] != V_82 &&
V_2 -> V_5 . V_6 . V_7 [ V_1166 ] != ~ 0 ) ; V_3 ++ )
V_1166 = F_580 ( V_1166 ) ;
return V_1166 ;
}
bool F_583 ( struct V_1 * V_2 , T_3 V_82 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_582 ( V_2 , V_82 ) ] == V_82 ;
}
static void F_584 ( struct V_1 * V_2 , T_3 V_82 )
{
T_1 V_3 , V_707 , V_1167 ;
V_3 = V_707 = F_582 ( V_2 , V_82 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_707 = F_580 ( V_707 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_707 ] == ~ 0 )
return;
V_1167 = F_577 ( V_2 -> V_5 . V_6 . V_7 [ V_707 ] ) ;
} while ( ( V_3 <= V_707 ) ? ( V_3 < V_1167 && V_1167 <= V_707 ) : ( V_3 < V_1167 || V_1167 <= V_707 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_707 ] ;
V_3 = V_707 ;
}
}
static int F_585 ( struct V_1 * V_2 , T_1 V_155 )
{
return F_153 ( V_2 -> V_81 , & V_2 -> V_5 . V_6 . V_30 , & V_155 ,
sizeof( V_155 ) ) ;
}
void F_586 ( struct V_1 * V_2 ,
struct V_1162 * V_1163 )
{
struct V_57 V_58 ;
F_587 ( V_1163 -> V_5 . V_1168 , V_1163 -> V_720 ) ;
F_581 ( V_2 , V_1163 -> V_5 . V_82 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_337 & V_338 ) ||
( V_2 -> V_5 . V_6 . V_339 &&
V_55 -> V_70 ( V_2 ) == 0 ) )
F_22 ( V_971 , V_2 ) ;
else if ( ! F_585 ( V_2 , V_1169 ) ) {
V_58 . V_31 = V_32 ;
V_58 . V_817 = true ;
V_58 . V_42 = 0 ;
V_58 . V_63 = false ;
V_58 . V_62 = V_1163 -> V_5 . V_1168 ;
F_27 ( V_2 , & V_58 ) ;
}
}
void F_588 ( struct V_1 * V_2 ,
struct V_1162 * V_1163 )
{
struct V_57 V_58 ;
F_589 ( V_1163 -> V_5 . V_1168 , V_1163 -> V_720 ) ;
if ( F_158 ( V_1163 -> V_312 ) )
V_1163 -> V_5 . V_1168 = ~ 0 ;
else
F_584 ( V_2 , V_1163 -> V_5 . V_82 ) ;
if ( ( V_2 -> V_5 . V_6 . V_337 & V_338 ) &&
! F_585 ( V_2 , V_1170 ) ) {
V_58 . V_31 = V_32 ;
V_58 . V_817 = true ;
V_58 . V_42 = 0 ;
V_58 . V_63 = false ;
V_58 . V_62 = V_1163 -> V_5 . V_1168 ;
F_27 ( V_2 , & V_58 ) ;
}
V_2 -> V_5 . V_6 . V_972 = false ;
V_2 -> V_5 . V_915 = V_992 ;
}
bool F_590 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_337 & V_338 ) )
return true ;
else
return ! F_439 ( V_2 ) &&
V_55 -> V_957 ( V_2 ) ;
}
