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
unsigned long V_15 ;
F_5 ( V_15 ) ;
if ( V_12 -> V_16 ) {
V_12 -> V_16 = false ;
F_6 ( V_9 ) ;
}
F_7 ( V_15 ) ;
for ( V_10 = 0 ; V_10 < V_17 . V_18 ; ++ V_10 ) {
V_14 = & V_12 -> V_14 [ V_10 ] ;
if ( V_14 -> V_19 != V_14 -> V_20 ) {
F_8 ( V_17 . V_21 [ V_10 ] , V_14 -> V_19 ) ;
V_14 -> V_20 = V_14 -> V_19 ;
}
}
}
static void F_9 ( unsigned V_10 , T_1 V_22 )
{
T_2 V_23 ;
unsigned int V_24 = F_10 () ;
struct V_11 * V_25 = F_11 ( V_26 , V_24 ) ;
if ( V_10 >= V_17 . V_18 ) {
F_12 ( V_27 L_1 ) ;
return;
}
F_13 ( V_22 , & V_23 ) ;
V_25 -> V_14 [ V_10 ] . V_19 = V_23 ;
V_25 -> V_14 [ V_10 ] . V_20 = V_23 ;
}
void F_14 ( unsigned V_10 , T_1 V_22 )
{
F_15 ( V_10 >= V_28 ) ;
V_17 . V_21 [ V_10 ] = V_22 ;
if ( V_10 >= V_17 . V_18 )
V_17 . V_18 = V_10 + 1 ;
}
static void F_16 ( void )
{
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_17 . V_18 ; ++ V_3 )
F_9 ( V_3 , V_17 . V_21 [ V_3 ] ) ;
}
int F_17 ( unsigned V_10 , T_2 V_23 , T_2 V_29 )
{
unsigned int V_24 = F_10 () ;
struct V_11 * V_25 = F_11 ( V_26 , V_24 ) ;
int V_30 ;
if ( ( ( V_23 ^ V_25 -> V_14 [ V_10 ] . V_20 ) & V_29 ) == 0 )
return 0 ;
V_25 -> V_14 [ V_10 ] . V_20 = V_23 ;
V_30 = F_18 ( V_17 . V_21 [ V_10 ] , V_23 ) ;
if ( V_30 )
return 1 ;
if ( ! V_25 -> V_16 ) {
V_25 -> V_9 . V_31 = F_3 ;
F_19 ( & V_25 -> V_9 ) ;
V_25 -> V_16 = true ;
}
return 0 ;
}
static void F_20 ( void )
{
unsigned int V_24 = F_10 () ;
struct V_11 * V_25 = F_11 ( V_26 , V_24 ) ;
if ( V_25 -> V_16 )
F_3 ( & V_25 -> V_9 ) ;
}
T_2 F_21 ( struct V_1 * V_2 )
{
return V_2 -> V_5 . V_32 ;
}
int F_22 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
T_2 V_35 = V_2 -> V_5 . V_32 &
( V_36 | V_37 ) ;
T_2 V_38 = V_34 -> V_39 &
( V_36 | V_37 ) ;
T_2 V_40 = ( ( ~ 0ULL ) << F_23 ( V_2 ) ) |
0x2ff | ( F_24 ( V_2 ) ? 0 : V_37 ) ;
if ( ! V_34 -> V_41 &&
( ( V_34 -> V_39 & V_40 ) != 0 ||
V_38 == V_37 ||
( V_38 == V_36 &&
V_35 == ( V_36 | V_37 ) ) ||
( V_38 == ( V_36 | V_37 ) &&
V_35 == 0 ) ) )
return 1 ;
F_25 ( V_2 , V_34 -> V_39 ) ;
return 0 ;
}
T_3 T_4 void F_26 ( void )
{
F_27 () ;
}
static int F_28 ( int V_42 )
{
switch ( V_42 ) {
case V_43 :
return V_44 ;
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
return V_50 ;
default:
break;
}
return V_51 ;
}
static int F_29 ( int V_42 )
{
unsigned int V_29 ;
if ( F_30 ( V_42 > 31 || V_42 == V_52 ) )
return V_53 ;
V_29 = 1 << V_42 ;
if ( V_29 & ( ( 1 << V_54 ) | ( 1 << V_55 ) | ( 1 << V_56 ) ) )
return V_57 ;
if ( V_29 & ( ( 1 << V_58 ) | ( 1 << V_59 ) ) )
return V_60 ;
return V_61 ;
}
static void F_31 ( struct V_1 * V_2 ,
unsigned V_18 , bool V_62 , T_1 V_63 ,
bool V_64 )
{
T_1 V_65 ;
int V_66 , V_67 ;
F_32 ( V_68 , V_2 ) ;
if ( ! V_2 -> V_5 . V_69 . V_70 ) {
V_71:
if ( V_62 && ! F_33 ( V_2 ) )
V_62 = false ;
V_2 -> V_5 . V_69 . V_70 = true ;
V_2 -> V_5 . V_69 . V_72 = V_62 ;
V_2 -> V_5 . V_69 . V_18 = V_18 ;
V_2 -> V_5 . V_69 . V_63 = V_63 ;
V_2 -> V_5 . V_69 . V_64 = V_64 ;
return;
}
V_65 = V_2 -> V_5 . V_69 . V_18 ;
if ( V_65 == V_58 ) {
F_32 ( V_73 , V_2 ) ;
return;
}
V_66 = F_28 ( V_65 ) ;
V_67 = F_28 ( V_18 ) ;
if ( ( V_66 == V_50 && V_67 == V_50 )
|| ( V_66 == V_44 && V_67 != V_51 ) ) {
V_2 -> V_5 . V_69 . V_70 = true ;
V_2 -> V_5 . V_69 . V_72 = true ;
V_2 -> V_5 . V_69 . V_18 = V_58 ;
V_2 -> V_5 . V_69 . V_63 = 0 ;
} else
goto V_71;
}
void F_34 ( struct V_1 * V_2 , unsigned V_18 )
{
F_31 ( V_2 , V_18 , false , 0 , false ) ;
}
void F_35 ( struct V_1 * V_2 , unsigned V_18 )
{
F_31 ( V_2 , V_18 , false , 0 , true ) ;
}
void F_36 ( struct V_1 * V_2 , int V_30 )
{
if ( V_30 )
F_37 ( V_2 , 0 ) ;
else
V_74 -> V_75 ( V_2 ) ;
}
void F_38 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
++ V_2 -> V_78 . V_79 ;
V_2 -> V_5 . V_80 = V_77 -> V_81 ;
F_39 ( V_2 , V_43 , V_77 -> V_63 ) ;
}
static bool F_40 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
if ( F_41 ( V_2 ) && ! V_77 -> V_82 )
V_2 -> V_5 . V_83 . V_84 ( V_2 , V_77 ) ;
else
V_2 -> V_5 . V_85 . V_84 ( V_2 , V_77 ) ;
return V_77 -> V_82 ;
}
void F_42 ( struct V_1 * V_2 )
{
F_43 ( & V_2 -> V_5 . V_86 ) ;
F_32 ( V_87 , V_2 ) ;
}
void F_39 ( struct V_1 * V_2 , unsigned V_18 , T_1 V_63 )
{
F_31 ( V_2 , V_18 , true , V_63 , false ) ;
}
void F_44 ( struct V_1 * V_2 , unsigned V_18 , T_1 V_63 )
{
F_31 ( V_2 , V_18 , true , V_63 , true ) ;
}
bool F_45 ( struct V_1 * V_2 , int V_88 )
{
if ( V_74 -> V_89 ( V_2 ) <= V_88 )
return true ;
F_39 ( V_2 , V_49 , 0 ) ;
return false ;
}
bool F_46 ( struct V_1 * V_2 , int V_90 )
{
if ( ( V_90 != 4 && V_90 != 5 ) || ! F_47 ( V_2 , V_91 ) )
return true ;
F_34 ( V_2 , V_92 ) ;
return false ;
}
int F_48 ( struct V_1 * V_2 , struct V_93 * V_85 ,
T_5 V_94 , void * V_39 , int V_95 , int V_96 ,
T_1 V_97 )
{
struct V_76 V_69 ;
T_5 V_98 ;
T_6 V_99 ;
V_99 = F_49 ( V_94 ) ;
V_98 = V_85 -> V_100 ( V_2 , V_99 , V_97 , & V_69 ) ;
if ( V_98 == V_101 )
return - V_102 ;
V_98 = F_50 ( V_98 ) ;
return F_51 ( V_2 , V_98 , V_39 , V_95 , V_96 ) ;
}
static int F_52 ( struct V_1 * V_2 , T_5 V_103 ,
void * V_39 , int V_95 , int V_96 , T_1 V_97 )
{
return F_48 ( V_2 , V_2 -> V_5 . V_104 , V_103 ,
V_39 , V_95 , V_96 , V_97 ) ;
}
int F_53 ( struct V_1 * V_2 , struct V_93 * V_85 , unsigned long V_105 )
{
T_5 V_106 = V_105 >> V_107 ;
unsigned V_95 = ( ( V_105 & ( V_108 - 1 ) ) >> 5 ) << 2 ;
int V_3 ;
int V_109 ;
T_2 V_110 [ F_54 ( V_85 -> V_111 ) ] ;
V_109 = F_48 ( V_2 , V_85 , V_106 , V_110 ,
V_95 * sizeof( T_2 ) , sizeof( V_110 ) ,
V_112 | V_113 ) ;
if ( V_109 < 0 ) {
V_109 = 0 ;
goto V_114;
}
for ( V_3 = 0 ; V_3 < F_54 ( V_110 ) ; ++ V_3 ) {
if ( ( V_110 [ V_3 ] & V_115 ) &&
( V_110 [ V_3 ] &
V_2 -> V_5 . V_85 . V_116 . V_117 [ 0 ] [ 2 ] ) ) {
V_109 = 0 ;
goto V_114;
}
}
V_109 = 1 ;
memcpy ( V_85 -> V_111 , V_110 , sizeof( V_85 -> V_111 ) ) ;
F_55 ( V_118 ,
( unsigned long * ) & V_2 -> V_5 . V_119 ) ;
F_55 ( V_118 ,
( unsigned long * ) & V_2 -> V_5 . V_120 ) ;
V_114:
return V_109 ;
}
static bool F_56 ( struct V_1 * V_2 )
{
T_2 V_110 [ F_54 ( V_2 -> V_5 . V_104 -> V_111 ) ] ;
bool V_121 = true ;
int V_95 ;
T_5 V_103 ;
int V_122 ;
if ( F_57 ( V_2 ) || ! F_58 ( V_2 ) )
return false ;
if ( ! F_59 ( V_118 ,
( unsigned long * ) & V_2 -> V_5 . V_119 ) )
return true ;
V_103 = ( F_60 ( V_2 ) & ~ 31u ) >> V_107 ;
V_95 = ( F_60 ( V_2 ) & ~ 31u ) & ( V_108 - 1 ) ;
V_122 = F_52 ( V_2 , V_103 , V_110 , V_95 , sizeof( V_110 ) ,
V_112 | V_113 ) ;
if ( V_122 < 0 )
goto V_114;
V_121 = memcmp ( V_110 , V_2 -> V_5 . V_104 -> V_111 , sizeof( V_110 ) ) != 0 ;
V_114:
return V_121 ;
}
int F_61 ( struct V_1 * V_2 , unsigned long V_123 )
{
unsigned long V_124 = F_62 ( V_2 ) ;
unsigned long V_125 = V_126 | V_127 ;
V_123 |= V_128 ;
#ifdef F_63
if ( V_123 & 0xffffffff00000000UL )
return 1 ;
#endif
V_123 &= ~ V_129 ;
if ( ( V_123 & V_130 ) && ! ( V_123 & V_131 ) )
return 1 ;
if ( ( V_123 & V_126 ) && ! ( V_123 & V_132 ) )
return 1 ;
if ( ! F_64 ( V_2 ) && ( V_123 & V_126 ) ) {
#ifdef F_63
if ( ( V_2 -> V_5 . V_133 & V_134 ) ) {
int V_135 , V_136 ;
if ( ! F_58 ( V_2 ) )
return 1 ;
V_74 -> V_137 ( V_2 , & V_135 , & V_136 ) ;
if ( V_136 )
return 1 ;
} else
#endif
if ( F_58 ( V_2 ) && ! F_53 ( V_2 , V_2 -> V_5 . V_104 ,
F_60 ( V_2 ) ) )
return 1 ;
}
if ( ! ( V_123 & V_126 ) && F_47 ( V_2 , V_138 ) )
return 1 ;
V_74 -> V_139 ( V_2 , V_123 ) ;
if ( ( V_123 ^ V_124 ) & V_126 ) {
F_65 ( V_2 ) ;
F_1 ( V_2 ) ;
}
if ( ( V_123 ^ V_124 ) & V_125 )
F_66 ( V_2 ) ;
if ( ( ( V_123 ^ V_124 ) & V_131 ) &&
F_67 ( V_2 -> V_140 ) &&
! F_68 ( V_2 -> V_140 , V_141 ) )
F_69 ( V_2 -> V_140 , 0 , ~ 0ULL ) ;
return 0 ;
}
void F_70 ( struct V_1 * V_2 , unsigned long V_142 )
{
( void ) F_61 ( V_2 , F_71 ( V_2 , ~ 0x0eul ) | ( V_142 & 0x0f ) ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
if ( F_47 ( V_2 , V_143 ) &&
! V_2 -> V_144 ) {
F_73 ( V_145 , V_2 -> V_5 . V_146 ) ;
V_2 -> V_144 = 1 ;
}
}
static void F_74 ( struct V_1 * V_2 )
{
if ( V_2 -> V_144 ) {
if ( V_2 -> V_5 . V_146 != V_147 )
F_73 ( V_145 , V_147 ) ;
V_2 -> V_144 = 0 ;
}
}
static int F_75 ( struct V_1 * V_2 , T_1 V_148 , T_2 V_149 )
{
T_2 V_146 = V_149 ;
T_2 V_150 = V_2 -> V_5 . V_146 ;
T_2 V_151 ;
if ( V_148 != V_145 )
return 1 ;
if ( ! ( V_146 & V_152 ) )
return 1 ;
if ( ( V_146 & V_153 ) && ! ( V_146 & V_154 ) )
return 1 ;
V_151 = V_2 -> V_5 . V_155 | V_152 ;
if ( V_146 & ~ V_151 )
return 1 ;
if ( ( ! ( V_146 & V_156 ) ) !=
( ! ( V_146 & V_157 ) ) )
return 1 ;
if ( V_146 & V_158 ) {
if ( ! ( V_146 & V_153 ) )
return 1 ;
if ( ( V_146 & V_158 ) != V_158 )
return 1 ;
}
V_2 -> V_5 . V_146 = V_146 ;
if ( ( V_146 ^ V_150 ) & V_159 )
F_76 ( V_2 ) ;
return 0 ;
}
int F_77 ( struct V_1 * V_2 , T_1 V_148 , T_2 V_149 )
{
if ( V_74 -> V_89 ( V_2 ) != 0 ||
F_75 ( V_2 , V_148 , V_149 ) ) {
F_37 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_78 ( struct V_1 * V_2 , unsigned long V_160 )
{
unsigned long V_161 = F_79 ( V_2 ) ;
unsigned long V_162 = V_163 | V_164 | V_165 |
V_166 | V_167 | V_168 ;
if ( V_160 & V_169 )
return 1 ;
if ( ! F_80 ( V_2 ) && ( V_160 & V_143 ) )
return 1 ;
if ( ! F_81 ( V_2 ) && ( V_160 & V_166 ) )
return 1 ;
if ( ! F_82 ( V_2 ) && ( V_160 & V_167 ) )
return 1 ;
if ( ! F_83 ( V_2 ) && ( V_160 & V_170 ) )
return 1 ;
if ( ! F_84 ( V_2 ) && ( V_160 & V_168 ) )
return 1 ;
if ( F_57 ( V_2 ) ) {
if ( ! ( V_160 & V_165 ) )
return 1 ;
} else if ( F_64 ( V_2 ) && ( V_160 & V_165 )
&& ( ( V_160 ^ V_161 ) & V_162 )
&& ! F_53 ( V_2 , V_2 -> V_5 . V_104 ,
F_60 ( V_2 ) ) )
return 1 ;
if ( ( V_160 & V_138 ) && ! ( V_161 & V_138 ) ) {
if ( ! F_85 ( V_2 ) )
return 1 ;
if ( ( F_60 ( V_2 ) & V_171 ) || ! F_57 ( V_2 ) )
return 1 ;
}
if ( V_74 -> V_172 ( V_2 , V_160 ) )
return 1 ;
if ( ( ( V_160 ^ V_161 ) & V_162 ) ||
( ! ( V_160 & V_138 ) && ( V_161 & V_138 ) ) )
F_66 ( V_2 ) ;
if ( ( V_160 ^ V_161 ) & ( V_143 | V_168 ) )
F_76 ( V_2 ) ;
return 0 ;
}
int F_86 ( struct V_1 * V_2 , unsigned long V_105 )
{
#ifdef F_63
V_105 &= ~ V_173 ;
#endif
if ( V_105 == F_60 ( V_2 ) && ! F_56 ( V_2 ) ) {
F_87 ( V_2 ) ;
F_32 ( V_174 , V_2 ) ;
return 0 ;
}
if ( F_57 ( V_2 ) ) {
if ( V_105 & V_175 )
return 1 ;
} else if ( F_58 ( V_2 ) && F_64 ( V_2 ) &&
! F_53 ( V_2 , V_2 -> V_5 . V_104 , V_105 ) )
return 1 ;
V_2 -> V_5 . V_105 = V_105 ;
F_55 ( V_176 , ( V_177 * ) & V_2 -> V_5 . V_119 ) ;
F_88 ( V_2 ) ;
return 0 ;
}
int F_89 ( struct V_1 * V_2 , unsigned long V_178 )
{
if ( V_178 & V_179 )
return 1 ;
if ( F_90 ( V_2 ) )
F_91 ( V_2 , V_178 ) ;
else
V_2 -> V_5 . V_178 = V_178 ;
return 0 ;
}
unsigned long F_92 ( struct V_1 * V_2 )
{
if ( F_90 ( V_2 ) )
return F_93 ( V_2 ) ;
else
return V_2 -> V_5 . V_178 ;
}
static void F_94 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! ( V_2 -> V_180 & V_181 ) ) {
for ( V_3 = 0 ; V_3 < V_182 ; V_3 ++ )
V_2 -> V_5 . V_183 [ V_3 ] = V_2 -> V_5 . V_184 [ V_3 ] ;
V_2 -> V_5 . V_185 |= V_186 ;
}
}
static void F_95 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_180 & V_181 ) )
V_74 -> V_187 ( V_2 , V_2 -> V_5 . V_188 ) ;
}
static void F_96 ( struct V_1 * V_2 )
{
unsigned long V_189 ;
if ( V_2 -> V_180 & V_181 )
V_189 = V_2 -> V_5 . V_190 ;
else
V_189 = V_2 -> V_5 . V_189 ;
V_74 -> V_191 ( V_2 , V_189 ) ;
V_2 -> V_5 . V_185 &= ~ V_192 ;
if ( V_189 & V_193 )
V_2 -> V_5 . V_185 |= V_192 ;
}
static T_2 F_97 ( struct V_1 * V_2 )
{
T_2 V_194 = V_195 ;
if ( ! F_98 ( V_2 ) )
V_194 |= V_196 ;
return V_194 ;
}
static int F_99 ( struct V_1 * V_2 , int V_90 , unsigned long V_197 )
{
switch ( V_90 ) {
case 0 ... 3 :
V_2 -> V_5 . V_184 [ V_90 ] = V_197 ;
if ( ! ( V_2 -> V_180 & V_181 ) )
V_2 -> V_5 . V_183 [ V_90 ] = V_197 ;
break;
case 4 :
case 6 :
if ( V_197 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_188 = ( V_197 & V_198 ) | F_97 ( V_2 ) ;
F_95 ( V_2 ) ;
break;
case 5 :
default:
if ( V_197 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_189 = ( V_197 & V_199 ) | V_200 ;
F_96 ( V_2 ) ;
break;
}
return 0 ;
}
int F_100 ( struct V_1 * V_2 , int V_90 , unsigned long V_197 )
{
if ( F_99 ( V_2 , V_90 , V_197 ) ) {
F_37 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_101 ( struct V_1 * V_2 , int V_90 , unsigned long * V_197 )
{
switch ( V_90 ) {
case 0 ... 3 :
* V_197 = V_2 -> V_5 . V_184 [ V_90 ] ;
break;
case 4 :
case 6 :
if ( V_2 -> V_180 & V_181 )
* V_197 = V_2 -> V_5 . V_188 ;
else
* V_197 = V_74 -> V_201 ( V_2 ) ;
break;
case 5 :
default:
* V_197 = V_2 -> V_5 . V_189 ;
break;
}
return 0 ;
}
bool F_102 ( struct V_1 * V_2 )
{
T_1 V_202 = F_103 ( V_2 , V_203 ) ;
T_2 V_39 ;
int V_30 ;
V_30 = F_104 ( V_2 , V_202 , & V_39 ) ;
if ( V_30 )
return V_30 ;
F_105 ( V_2 , V_204 , ( T_1 ) V_39 ) ;
F_105 ( V_2 , V_205 , V_39 >> 32 ) ;
return V_30 ;
}
bool F_106 ( struct V_1 * V_2 , T_2 V_133 )
{
if ( V_133 & V_206 )
return false ;
if ( V_133 & V_207 ) {
struct V_208 * V_209 ;
V_209 = F_107 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_209 || ! ( V_209 -> V_210 & F_108 ( V_211 ) ) )
return false ;
}
if ( V_133 & V_212 ) {
struct V_208 * V_209 ;
V_209 = F_107 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_209 || ! ( V_209 -> V_202 & F_108 ( V_213 ) ) )
return false ;
}
return true ;
}
static int F_109 ( struct V_1 * V_2 , T_2 V_133 )
{
T_2 V_214 = V_2 -> V_5 . V_133 ;
if ( ! F_106 ( V_2 , V_133 ) )
return 1 ;
if ( F_64 ( V_2 )
&& ( V_2 -> V_5 . V_133 & V_134 ) != ( V_133 & V_134 ) )
return 1 ;
V_133 &= ~ V_215 ;
V_133 |= V_2 -> V_5 . V_133 & V_215 ;
V_74 -> F_109 ( V_2 , V_133 ) ;
if ( ( V_133 ^ V_214 ) & V_216 )
F_66 ( V_2 ) ;
return 0 ;
}
void F_110 ( T_2 V_29 )
{
V_206 &= ~ V_29 ;
}
int F_111 ( struct V_1 * V_2 , struct V_33 * V_22 )
{
switch ( V_22 -> V_148 ) {
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
if ( F_112 ( V_22 -> V_39 ) )
return 1 ;
break;
case V_222 :
case V_223 :
V_22 -> V_39 = F_113 ( V_22 -> V_39 ) ;
}
return V_74 -> V_224 ( V_2 , V_22 ) ;
}
static int F_114 ( struct V_1 * V_2 , unsigned V_148 , T_2 * V_39 )
{
struct V_33 V_22 ;
int V_122 ;
V_22 . V_148 = V_148 ;
V_22 . V_41 = true ;
V_122 = F_115 ( V_2 , & V_22 ) ;
if ( V_122 )
return V_122 ;
* V_39 = V_22 . V_39 ;
return 0 ;
}
static int F_116 ( struct V_1 * V_2 , unsigned V_148 , T_2 * V_39 )
{
struct V_33 V_22 ;
V_22 . V_39 = * V_39 ;
V_22 . V_148 = V_148 ;
V_22 . V_41 = true ;
return F_111 ( V_2 , & V_22 ) ;
}
static void F_117 ( struct V_225 * V_226 )
{
struct V_227 * V_228 = & V_227 ;
T_2 V_229 ;
V_229 = F_118 ( F_119 ( V_226 -> V_230 . V_231 , V_226 -> V_232 ) ) ;
F_120 ( & V_228 -> V_233 ) ;
V_228 -> clock . V_234 = V_226 -> V_230 . clock -> V_235 . V_234 ;
V_228 -> clock . V_236 = V_226 -> V_230 . V_236 ;
V_228 -> clock . V_29 = V_226 -> V_230 . V_29 ;
V_228 -> clock . V_237 = V_226 -> V_230 . V_237 ;
V_228 -> clock . V_238 = V_226 -> V_230 . V_238 ;
V_228 -> V_229 = V_229 ;
V_228 -> V_239 = V_226 -> V_230 . V_240 ;
F_121 ( & V_228 -> V_233 ) ;
}
void F_122 ( struct V_1 * V_2 )
{
F_32 ( V_241 , V_2 ) ;
}
static void F_123 ( struct V_140 * V_140 , T_6 V_242 )
{
int V_243 ;
int V_122 ;
struct V_244 V_245 ;
struct V_246 V_247 ;
if ( ! V_242 )
return;
V_122 = F_124 ( V_140 , V_242 , & V_243 , sizeof( V_243 ) ) ;
if ( V_122 )
return;
if ( V_243 & 1 )
++ V_243 ;
++ V_243 ;
if ( F_125 ( V_140 , V_242 , & V_243 , sizeof( V_243 ) ) )
return;
F_126 ( & V_247 ) ;
if ( V_140 -> V_5 . V_248 ) {
struct V_246 V_249 = F_127 ( V_140 -> V_5 . V_248 ) ;
V_247 = F_128 ( V_247 , V_249 ) ;
}
V_245 . V_250 = ( T_1 ) V_247 . V_251 ;
V_245 . V_252 = V_247 . V_253 ;
V_245 . V_243 = V_243 ;
F_125 ( V_140 , V_242 , & V_245 , sizeof( V_245 ) ) ;
V_243 ++ ;
F_125 ( V_140 , V_242 , & V_243 , sizeof( V_243 ) ) ;
}
static T_7 F_129 ( T_7 V_254 , T_7 V_255 )
{
F_130 ( V_254 , V_255 ) ;
return V_254 ;
}
static void F_131 ( T_8 V_256 , T_8 V_257 ,
T_9 * V_258 , T_1 * V_259 )
{
T_8 V_260 ;
T_10 V_238 = 0 ;
T_8 V_261 ;
T_7 V_262 ;
V_261 = V_257 ;
V_260 = V_256 ;
while ( V_261 > V_260 * 2 || V_261 & 0xffffffff00000000ULL ) {
V_261 >>= 1 ;
V_238 -- ;
}
V_262 = ( T_7 ) V_261 ;
while ( V_262 <= V_260 || V_260 & 0xffffffff00000000ULL ) {
if ( V_260 & 0xffffffff00000000ULL || V_262 & 0x80000000 )
V_260 >>= 1 ;
else
V_262 <<= 1 ;
V_238 ++ ;
}
* V_258 = V_238 ;
* V_259 = F_129 ( V_260 , V_262 ) ;
F_132 ( L_2 ,
V_263 , V_257 , V_256 , V_238 , * V_259 ) ;
}
static T_1 F_133 ( T_1 V_264 , T_11 V_265 )
{
T_2 V_266 = ( T_2 ) V_264 * ( 1000000 + V_265 ) ;
F_134 ( V_266 , 1000000 ) ;
return V_266 ;
}
static int F_135 ( struct V_1 * V_2 , T_1 V_267 , bool V_268 )
{
T_2 V_269 ;
if ( ! V_268 ) {
V_2 -> V_5 . V_270 = V_271 ;
return 0 ;
}
if ( ! V_272 ) {
if ( V_267 > V_273 ) {
V_2 -> V_5 . V_274 = 1 ;
V_2 -> V_5 . V_275 = 1 ;
return 0 ;
} else {
F_136 ( 1 , L_3 ) ;
return - 1 ;
}
}
V_269 = F_137 ( 1ULL << V_276 ,
V_267 , V_273 ) ;
if ( V_269 == 0 || V_269 >= V_277 ) {
F_138 ( 1 , L_4 ,
V_267 ) ;
return - 1 ;
}
V_2 -> V_5 . V_270 = V_269 ;
return 0 ;
}
static int F_139 ( struct V_1 * V_2 , T_1 V_267 )
{
T_1 V_278 , V_279 ;
int V_280 = 0 ;
if ( V_267 == 0 ) {
V_2 -> V_5 . V_270 = V_271 ;
return - 1 ;
}
F_131 ( V_267 * 1000LL , V_281 ,
& V_2 -> V_5 . V_282 ,
& V_2 -> V_5 . V_283 ) ;
V_2 -> V_5 . V_284 = V_267 ;
V_278 = F_133 ( V_273 , - V_285 ) ;
V_279 = F_133 ( V_273 , V_285 ) ;
if ( V_267 < V_278 || V_267 > V_279 ) {
F_132 ( L_5 , V_267 , V_278 , V_279 ) ;
V_280 = 1 ;
}
return F_135 ( V_2 , V_267 , V_280 ) ;
}
static T_2 F_140 ( struct V_1 * V_2 , T_12 V_286 )
{
T_2 V_287 = F_141 ( V_286 - V_2 -> V_5 . V_288 ,
V_2 -> V_5 . V_283 ,
V_2 -> V_5 . V_282 ) ;
V_287 += V_2 -> V_5 . V_289 ;
return V_287 ;
}
static void F_142 ( struct V_1 * V_2 )
{
#ifdef F_63
bool V_290 ;
struct V_291 * V_292 = & V_2 -> V_140 -> V_5 ;
struct V_227 * V_293 = & V_227 ;
V_290 = ( V_292 -> V_294 + 1 ==
F_143 ( & V_2 -> V_140 -> V_295 ) ) ;
if ( V_292 -> V_296 ||
( V_293 -> clock . V_234 == V_297 && V_290 ) )
F_32 ( V_298 , V_2 ) ;
F_144 ( V_2 -> V_299 , V_292 -> V_294 ,
F_143 ( & V_2 -> V_140 -> V_295 ) ,
V_292 -> V_296 , V_293 -> clock . V_234 ) ;
#endif
}
static void F_145 ( struct V_1 * V_2 , T_12 V_95 )
{
T_2 V_300 = V_2 -> V_5 . V_301 ;
V_2 -> V_5 . V_302 += V_95 - V_300 ;
}
static inline T_2 F_146 ( T_2 V_269 , T_2 V_287 )
{
return F_147 ( V_287 , V_269 , V_276 ) ;
}
T_2 F_148 ( struct V_1 * V_2 , T_2 V_287 )
{
T_2 V_303 = V_287 ;
T_2 V_269 = V_2 -> V_5 . V_270 ;
if ( V_269 != V_271 )
V_303 = F_146 ( V_269 , V_287 ) ;
return V_303 ;
}
static T_2 F_149 ( struct V_1 * V_2 , T_2 V_304 )
{
T_2 V_287 ;
V_287 = F_148 ( V_2 , F_150 () ) ;
return V_304 - V_287 ;
}
T_2 F_151 ( struct V_1 * V_2 , T_2 V_305 )
{
return V_2 -> V_5 . V_301 + F_148 ( V_2 , V_305 ) ;
}
static void F_152 ( struct V_1 * V_2 , T_2 V_95 )
{
V_74 -> V_306 ( V_2 , V_95 ) ;
V_2 -> V_5 . V_301 = V_95 ;
}
void F_153 ( struct V_1 * V_2 , struct V_33 * V_22 )
{
struct V_140 * V_140 = V_2 -> V_140 ;
T_2 V_95 , V_307 , V_308 ;
unsigned long V_15 ;
T_12 V_309 ;
bool V_310 ;
bool V_311 ;
T_2 V_39 = V_22 -> V_39 ;
F_154 ( & V_140 -> V_5 . V_312 , V_15 ) ;
V_95 = F_149 ( V_2 , V_39 ) ;
V_307 = F_155 () ;
V_308 = V_307 - V_140 -> V_5 . V_313 ;
if ( V_2 -> V_5 . V_284 ) {
int V_314 = 0 ;
V_309 = V_39 - V_140 -> V_5 . V_315 ;
#ifdef F_63
V_309 = ( V_309 * 1000 ) / V_2 -> V_5 . V_284 ;
#else
asm("1: idivl %[divisor]\n"
"2: xor %%edx, %%edx\n"
" movl $0, %[faulted]\n"
"3:\n"
".section .fixup,\"ax\"\n"
"4: movl $1, %[faulted]\n"
" jmp 3b\n"
".previous\n"
_ASM_EXTABLE(1b, 4b)
: "=A"(usdiff), [faulted] "=r" (faulted)
: "A"(usdiff * 1000), [divisor] "rm"(vcpu->arch.virtual_tsc_khz));
#endif
F_134 ( V_308 , 1000 ) ;
V_309 -= V_308 ;
if ( V_309 < 0 )
V_309 = - V_309 ;
if ( V_314 )
V_309 = V_316 ;
} else
V_309 = V_316 ;
if ( V_309 < V_316 &&
V_2 -> V_5 . V_284 == V_140 -> V_5 . V_317 ) {
if ( ! F_156 () ) {
V_95 = V_140 -> V_5 . V_318 ;
F_132 ( L_6 , V_39 ) ;
} else {
T_2 V_319 = F_157 ( V_2 , V_308 ) ;
V_39 += V_319 ;
V_95 = F_149 ( V_2 , V_39 ) ;
F_132 ( L_7 , V_319 ) ;
}
V_310 = true ;
V_311 = ( V_2 -> V_5 . V_320 == V_140 -> V_5 . V_321 ) ;
} else {
V_140 -> V_5 . V_321 ++ ;
V_140 -> V_5 . V_322 = V_307 ;
V_140 -> V_5 . V_323 = V_39 ;
V_140 -> V_5 . V_318 = V_95 ;
V_310 = false ;
F_132 ( L_8 ,
V_140 -> V_5 . V_321 , V_39 ) ;
}
V_140 -> V_5 . V_313 = V_307 ;
V_140 -> V_5 . V_315 = V_39 ;
V_140 -> V_5 . V_317 = V_2 -> V_5 . V_284 ;
V_2 -> V_5 . V_324 = V_39 ;
V_2 -> V_5 . V_320 = V_140 -> V_5 . V_321 ;
V_2 -> V_5 . V_288 = V_140 -> V_5 . V_322 ;
V_2 -> V_5 . V_289 = V_140 -> V_5 . V_323 ;
if ( F_158 ( V_2 ) && ! V_22 -> V_41 )
F_145 ( V_2 , V_95 ) ;
F_152 ( V_2 , V_95 ) ;
F_159 ( & V_140 -> V_5 . V_312 , V_15 ) ;
F_160 ( & V_140 -> V_5 . V_325 ) ;
if ( ! V_310 ) {
V_140 -> V_5 . V_294 = 0 ;
} else if ( ! V_311 ) {
V_140 -> V_5 . V_294 ++ ;
}
F_142 ( V_2 ) ;
F_161 ( & V_140 -> V_5 . V_325 ) ;
}
static inline void F_162 ( struct V_1 * V_2 ,
T_12 V_326 )
{
F_152 ( V_2 , V_2 -> V_5 . V_301 + V_326 ) ;
}
static inline void F_163 ( struct V_1 * V_2 , T_12 V_326 )
{
if ( V_2 -> V_5 . V_270 != V_271 )
F_30 ( V_326 < 0 ) ;
V_326 = F_148 ( V_2 , ( T_2 ) V_326 ) ;
F_162 ( V_2 , V_326 ) ;
}
static T_13 F_164 ( void )
{
T_13 V_109 = ( T_13 ) F_165 () ;
T_2 V_327 = V_227 . clock . V_236 ;
if ( F_166 ( V_109 >= V_327 ) )
return V_109 ;
asm volatile ("");
return V_327 ;
}
static inline T_2 F_167 ( T_13 * V_328 )
{
long V_266 ;
struct V_227 * V_293 = & V_227 ;
* V_328 = F_164 () ;
V_266 = ( * V_328 - V_293 -> clock . V_236 ) & V_293 -> clock . V_29 ;
return V_266 * V_293 -> clock . V_237 ;
}
static int F_168 ( T_12 * V_329 , T_13 * V_328 )
{
struct V_227 * V_293 = & V_227 ;
unsigned long V_233 ;
int V_330 ;
T_2 V_307 ;
do {
V_233 = F_169 ( & V_293 -> V_233 ) ;
V_330 = V_293 -> clock . V_234 ;
V_307 = V_293 -> V_239 ;
V_307 += F_167 ( V_328 ) ;
V_307 >>= V_293 -> clock . V_238 ;
V_307 += V_293 -> V_229 ;
} while ( F_170 ( F_171 ( & V_293 -> V_233 , V_233 ) ) );
* V_329 = V_307 ;
return V_330 ;
}
static bool F_172 ( T_12 * V_286 , T_13 * V_328 )
{
if ( V_227 . clock . V_234 != V_297 )
return false ;
return F_168 ( V_286 , V_328 ) == V_297 ;
}
static void F_173 ( struct V_140 * V_140 )
{
#ifdef F_63
struct V_291 * V_292 = & V_140 -> V_5 ;
int V_234 ;
bool V_331 , V_290 ;
V_290 = ( V_292 -> V_294 + 1 ==
F_143 ( & V_140 -> V_295 ) ) ;
V_331 = F_172 (
& V_292 -> V_332 ,
& V_292 -> V_333 ) ;
V_292 -> V_296 = V_331 && V_290
&& ! V_334
&& ! V_292 -> V_335 ;
if ( V_292 -> V_296 )
F_174 ( & V_336 , 1 ) ;
V_234 = V_227 . clock . V_234 ;
F_175 ( V_292 -> V_296 , V_234 ,
V_290 ) ;
#endif
}
void F_176 ( struct V_140 * V_140 )
{
F_177 ( V_140 , V_337 ) ;
}
static void F_178 ( struct V_140 * V_140 )
{
#ifdef F_63
int V_3 ;
struct V_1 * V_2 ;
struct V_291 * V_292 = & V_140 -> V_5 ;
F_160 ( & V_292 -> V_325 ) ;
F_176 ( V_140 ) ;
F_173 ( V_140 ) ;
F_179 (i, vcpu, kvm)
F_32 ( V_338 , V_2 ) ;
F_179 (i, vcpu, kvm)
F_180 ( V_337 , & V_2 -> V_339 ) ;
F_161 ( & V_292 -> V_325 ) ;
#endif
}
static T_2 F_181 ( struct V_140 * V_140 )
{
struct V_291 * V_292 = & V_140 -> V_5 ;
struct V_340 V_341 ;
F_160 ( & V_292 -> V_325 ) ;
if ( ! V_292 -> V_296 ) {
F_161 ( & V_292 -> V_325 ) ;
return F_155 () + V_292 -> V_248 ;
}
V_341 . V_342 = V_292 -> V_333 ;
V_341 . V_343 = V_292 -> V_332 + V_292 -> V_248 ;
F_161 ( & V_292 -> V_325 ) ;
F_131 ( V_281 , F_182 ( V_344 ) * 1000LL ,
& V_341 . V_345 ,
& V_341 . V_346 ) ;
return F_183 ( & V_341 , F_150 () ) ;
}
T_2 F_184 ( struct V_140 * V_140 )
{
unsigned long V_15 ;
T_12 V_307 ;
F_5 ( V_15 ) ;
V_307 = F_181 ( V_140 ) ;
F_7 ( V_15 ) ;
return V_307 ;
}
static void F_185 ( struct V_1 * V_266 )
{
struct V_347 * V_2 = & V_266 -> V_5 ;
struct V_340 V_348 ;
if ( F_170 ( F_186 ( V_266 -> V_140 , & V_2 -> V_349 ,
& V_348 , sizeof( V_348 ) ) ) )
return;
F_187 ( F_188 ( struct V_340 , V_243 ) != 0 ) ;
V_2 -> V_341 . V_243 = V_348 . V_243 + 1 ;
F_189 ( V_266 -> V_140 , & V_2 -> V_349 ,
& V_2 -> V_341 ,
sizeof( V_2 -> V_341 . V_243 ) ) ;
F_190 () ;
V_2 -> V_341 . V_15 |= ( V_348 . V_15 & V_350 ) ;
if ( V_2 -> V_351 ) {
V_2 -> V_341 . V_15 |= V_350 ;
V_2 -> V_351 = false ;
}
F_191 ( V_266 -> V_299 , & V_2 -> V_341 ) ;
F_189 ( V_266 -> V_140 , & V_2 -> V_349 ,
& V_2 -> V_341 ,
sizeof( V_2 -> V_341 ) ) ;
F_190 () ;
V_2 -> V_341 . V_243 ++ ;
F_189 ( V_266 -> V_140 , & V_2 -> V_349 ,
& V_2 -> V_341 ,
sizeof( V_2 -> V_341 . V_243 ) ) ;
}
static int F_192 ( struct V_1 * V_266 )
{
unsigned long V_15 , V_352 ;
struct V_347 * V_2 = & V_266 -> V_5 ;
struct V_291 * V_292 = & V_266 -> V_140 -> V_5 ;
T_12 V_286 ;
T_2 V_342 , V_305 ;
T_14 V_353 ;
bool V_296 ;
V_286 = 0 ;
V_305 = 0 ;
F_160 ( & V_292 -> V_325 ) ;
V_296 = V_292 -> V_296 ;
if ( V_296 ) {
V_305 = V_292 -> V_333 ;
V_286 = V_292 -> V_332 ;
}
F_161 ( & V_292 -> V_325 ) ;
F_5 ( V_15 ) ;
V_352 = F_182 ( V_344 ) ;
if ( F_170 ( V_352 == 0 ) ) {
F_7 ( V_15 ) ;
F_32 ( V_338 , V_266 ) ;
return 1 ;
}
if ( ! V_296 ) {
V_305 = F_150 () ;
V_286 = F_155 () ;
}
V_342 = F_151 ( V_266 , V_305 ) ;
if ( V_2 -> V_274 ) {
T_2 V_287 = F_140 ( V_266 , V_286 ) ;
if ( V_287 > V_342 ) {
F_162 ( V_266 , V_287 - V_342 ) ;
V_342 = V_287 ;
}
}
F_7 ( V_15 ) ;
if ( V_272 )
V_352 = F_148 ( V_266 , V_352 ) ;
if ( F_170 ( V_2 -> V_354 != V_352 ) ) {
F_131 ( V_281 , V_352 * 1000LL ,
& V_2 -> V_341 . V_345 ,
& V_2 -> V_341 . V_346 ) ;
V_2 -> V_354 = V_352 ;
}
V_2 -> V_341 . V_342 = V_342 ;
V_2 -> V_341 . V_343 = V_286 + V_266 -> V_140 -> V_5 . V_248 ;
V_2 -> V_324 = V_342 ;
V_353 = 0 ;
if ( V_296 )
V_353 |= V_355 ;
V_2 -> V_341 . V_15 = V_353 ;
if ( V_2 -> V_356 )
F_185 ( V_266 ) ;
if ( V_266 == F_193 ( V_266 -> V_140 , 0 ) )
F_194 ( V_266 -> V_140 , & V_2 -> V_341 ) ;
return 0 ;
}
static void F_195 ( struct V_357 * V_358 )
{
int V_3 ;
struct V_359 * V_360 = F_196 ( V_358 ) ;
struct V_291 * V_292 = F_4 ( V_360 , struct V_291 ,
V_361 ) ;
struct V_140 * V_140 = F_4 ( V_292 , struct V_140 , V_5 ) ;
struct V_1 * V_2 ;
F_179 (i, vcpu, kvm) {
F_32 ( V_338 , V_2 ) ;
F_197 ( V_2 ) ;
}
}
static void F_198 ( struct V_1 * V_266 )
{
struct V_140 * V_140 = V_266 -> V_140 ;
F_32 ( V_338 , V_266 ) ;
F_199 ( & V_140 -> V_5 . V_361 ,
V_362 ) ;
}
static void F_200 ( struct V_357 * V_358 )
{
struct V_359 * V_360 = F_196 ( V_358 ) ;
struct V_291 * V_292 = F_4 ( V_360 , struct V_291 ,
V_363 ) ;
struct V_140 * V_140 = F_4 ( V_292 , struct V_140 , V_5 ) ;
if ( ! V_364 )
return;
F_199 ( & V_140 -> V_5 . V_361 , 0 ) ;
F_199 ( & V_140 -> V_5 . V_363 ,
V_365 ) ;
}
static int F_201 ( struct V_1 * V_2 , T_1 V_22 , T_2 V_39 )
{
T_2 V_366 = V_2 -> V_5 . V_366 ;
unsigned V_367 = V_366 & 0xff ;
switch ( V_22 ) {
case V_368 :
V_2 -> V_5 . V_369 = V_39 ;
break;
case V_370 :
if ( ! ( V_366 & V_371 ) )
return 1 ;
if ( V_39 != 0 && V_39 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_372 = V_39 ;
break;
default:
if ( V_22 >= V_373 &&
V_22 < F_202 ( V_367 ) ) {
T_1 V_95 = V_22 - V_373 ;
if ( ( V_95 & 0x3 ) == 0 &&
V_39 != 0 && ( V_39 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_374 [ V_95 ] = V_39 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_203 ( struct V_1 * V_2 , T_2 V_39 )
{
struct V_140 * V_140 = V_2 -> V_140 ;
int V_375 = F_57 ( V_2 ) ;
T_14 * V_376 = V_375 ? ( T_14 * ) ( long ) V_140 -> V_5 . F_203 . V_377
: ( T_14 * ) ( long ) V_140 -> V_5 . F_203 . V_378 ;
T_14 V_379 = V_375 ? V_140 -> V_5 . F_203 . V_380
: V_140 -> V_5 . F_203 . V_381 ;
T_1 V_382 = V_39 & ~ V_383 ;
T_2 V_384 = V_39 & V_383 ;
T_14 * V_385 ;
int V_122 ;
V_122 = - V_386 ;
if ( V_382 >= V_379 )
goto V_114;
V_122 = - V_387 ;
V_385 = F_204 ( V_376 + ( V_382 * V_108 ) , V_108 ) ;
if ( F_205 ( V_385 ) ) {
V_122 = F_206 ( V_385 ) ;
goto V_114;
}
if ( F_207 ( V_2 , V_384 , V_385 , V_108 ) )
goto V_388;
V_122 = 0 ;
V_388:
F_208 ( V_385 ) ;
V_114:
return V_122 ;
}
static int F_209 ( struct V_1 * V_2 , T_2 V_39 )
{
T_6 V_389 = V_39 & ~ 0x3f ;
if ( V_39 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_390 = V_39 ;
if ( ! ( V_39 & V_391 ) ) {
F_65 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_210 ( V_2 -> V_140 , & V_2 -> V_5 . V_6 . V_39 , V_389 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_392 = ! ( V_39 & V_393 ) ;
F_211 ( V_2 ) ;
return 0 ;
}
static void F_212 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_356 = false ;
}
static void F_213 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_394 . V_390 & V_395 ) )
return;
if ( F_170 ( F_186 ( V_2 -> V_140 , & V_2 -> V_5 . V_394 . V_396 ,
& V_2 -> V_5 . V_394 . V_397 , sizeof( struct V_398 ) ) ) )
return;
if ( V_2 -> V_5 . V_394 . V_397 . V_243 & 1 )
V_2 -> V_5 . V_394 . V_397 . V_243 += 1 ;
V_2 -> V_5 . V_394 . V_397 . V_243 += 1 ;
F_189 ( V_2 -> V_140 , & V_2 -> V_5 . V_394 . V_396 ,
& V_2 -> V_5 . V_394 . V_397 , sizeof( struct V_398 ) ) ;
F_190 () ;
V_2 -> V_5 . V_394 . V_397 . V_397 += V_399 -> V_400 . V_401 -
V_2 -> V_5 . V_394 . V_402 ;
V_2 -> V_5 . V_394 . V_402 = V_399 -> V_400 . V_401 ;
F_189 ( V_2 -> V_140 , & V_2 -> V_5 . V_394 . V_396 ,
& V_2 -> V_5 . V_394 . V_397 , sizeof( struct V_398 ) ) ;
F_190 () ;
V_2 -> V_5 . V_394 . V_397 . V_243 += 1 ;
F_189 ( V_2 -> V_140 , & V_2 -> V_5 . V_394 . V_396 ,
& V_2 -> V_5 . V_394 . V_397 , sizeof( struct V_398 ) ) ;
}
int F_214 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
bool V_403 = false ;
T_1 V_22 = V_34 -> V_148 ;
T_2 V_39 = V_34 -> V_39 ;
switch ( V_22 ) {
case V_404 :
case V_405 :
case V_406 :
case V_407 :
case V_408 :
case V_409 :
break;
case V_410 :
return F_109 ( V_2 , V_39 ) ;
case V_411 :
V_39 &= ~ ( T_2 ) 0x40 ;
V_39 &= ~ ( T_2 ) 0x100 ;
V_39 &= ~ ( T_2 ) 0x8 ;
V_39 &= ~ ( T_2 ) 0x40000 ;
if ( V_39 != 0 ) {
F_215 ( V_2 , L_9 ,
V_39 ) ;
return 1 ;
}
break;
case V_412 :
if ( V_39 != 0 ) {
F_215 ( V_2 , L_10
L_11 , V_39 ) ;
return 1 ;
}
break;
case V_413 :
if ( ! V_39 ) {
break;
} else if ( V_39 & ~ ( V_414 | V_415 ) ) {
return 1 ;
}
F_215 ( V_2 , L_12 ,
V_263 , V_39 ) ;
break;
case 0x200 ... 0x2ff :
return F_216 ( V_2 , V_22 , V_39 ) ;
case V_416 :
return F_22 ( V_2 , V_34 ) ;
case V_417 ... V_417 + 0x3ff :
return F_217 ( V_2 , V_22 , V_39 ) ;
case V_418 :
F_218 ( V_2 , V_39 ) ;
break;
case V_419 :
if ( F_158 ( V_2 ) ) {
if ( ! V_34 -> V_41 ) {
T_12 V_420 = V_39 - V_2 -> V_5 . V_302 ;
F_162 ( V_2 , V_420 ) ;
}
V_2 -> V_5 . V_302 = V_39 ;
}
break;
case V_421 :
V_2 -> V_5 . V_422 = V_39 ;
break;
case V_423 :
if ( ! V_34 -> V_41 )
return 1 ;
V_2 -> V_5 . V_424 = V_39 ;
break;
case V_425 :
case V_426 :
V_2 -> V_140 -> V_5 . V_242 = V_39 ;
F_123 ( V_2 -> V_140 , V_39 ) ;
break;
case V_427 :
case V_428 : {
T_2 V_429 ;
struct V_291 * V_292 = & V_2 -> V_140 -> V_5 ;
F_212 ( V_2 ) ;
if ( V_2 -> V_299 == 0 && ! V_34 -> V_41 ) {
bool V_430 = ( V_22 == V_428 ) ;
if ( V_292 -> V_335 != V_430 )
F_219 ( V_298 ,
& V_2 -> V_339 ) ;
V_292 -> V_335 = V_430 ;
}
V_2 -> V_5 . time = V_39 ;
F_32 ( V_431 , V_2 ) ;
if ( ! ( V_39 & 1 ) )
break;
V_429 = V_39 & ~ ( V_383 | 1 ) ;
if ( F_210 ( V_2 -> V_140 ,
& V_2 -> V_5 . V_349 , V_39 & ~ 1ULL ,
sizeof( struct V_340 ) ) )
V_2 -> V_5 . V_356 = false ;
else
V_2 -> V_5 . V_356 = true ;
break;
}
case V_432 :
if ( F_209 ( V_2 , V_39 ) )
return 1 ;
break;
case V_433 :
if ( F_170 ( ! F_220 () ) )
return 1 ;
if ( V_39 & V_434 )
return 1 ;
if ( F_210 ( V_2 -> V_140 , & V_2 -> V_5 . V_394 . V_396 ,
V_39 & V_435 ,
sizeof( struct V_398 ) ) )
return 1 ;
V_2 -> V_5 . V_394 . V_390 = V_39 ;
if ( ! ( V_39 & V_395 ) )
break;
F_32 ( V_436 , V_2 ) ;
break;
case V_437 :
if ( F_221 ( V_2 , V_39 ) )
return 1 ;
break;
case V_370 :
case V_368 :
case V_373 ... F_202 ( V_438 ) - 1 :
return F_201 ( V_2 , V_22 , V_39 ) ;
case V_439 ... V_440 :
case V_441 ... V_442 :
V_403 = true ;
case V_443 ... V_444 :
case V_445 ... V_446 :
if ( F_222 ( V_2 , V_22 ) )
return F_223 ( V_2 , V_34 ) ;
if ( V_403 || V_39 != 0 )
F_215 ( V_2 , L_13
L_14 , V_22 , V_39 ) ;
break;
case V_447 :
break;
case V_448 ... V_449 :
case V_450 ... V_451 :
case V_452 :
case V_453 ... V_454 :
return F_224 ( V_2 , V_22 , V_39 ,
V_34 -> V_41 ) ;
case V_455 :
F_215 ( V_2 , L_15 , V_22 , V_39 ) ;
break;
case V_456 :
if ( ! F_225 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_457 . V_458 = V_39 ;
break;
case V_459 :
if ( ! F_225 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_457 . V_460 = V_39 ;
break;
default:
if ( V_22 && ( V_22 == V_2 -> V_140 -> V_5 . F_203 . V_22 ) )
return F_203 ( V_2 , V_39 ) ;
if ( F_222 ( V_2 , V_22 ) )
return F_223 ( V_2 , V_34 ) ;
if ( ! V_461 ) {
F_215 ( V_2 , L_16 ,
V_22 , V_39 ) ;
return 1 ;
} else {
F_215 ( V_2 , L_15 ,
V_22 , V_39 ) ;
break;
}
}
return 0 ;
}
int F_115 ( struct V_1 * V_2 , struct V_33 * V_22 )
{
return V_74 -> V_462 ( V_2 , V_22 ) ;
}
static int F_226 ( struct V_1 * V_2 , T_1 V_22 , T_2 * V_463 )
{
T_2 V_39 ;
T_2 V_366 = V_2 -> V_5 . V_366 ;
unsigned V_367 = V_366 & 0xff ;
switch ( V_22 ) {
case V_464 :
case V_465 :
V_39 = 0 ;
break;
case V_466 :
V_39 = V_2 -> V_5 . V_366 ;
break;
case V_370 :
if ( ! ( V_366 & V_371 ) )
return 1 ;
V_39 = V_2 -> V_5 . V_372 ;
break;
case V_368 :
V_39 = V_2 -> V_5 . V_369 ;
break;
default:
if ( V_22 >= V_373 &&
V_22 < F_202 ( V_367 ) ) {
T_1 V_95 = V_22 - V_373 ;
V_39 = V_2 -> V_5 . V_374 [ V_95 ] ;
break;
}
return 1 ;
}
* V_463 = V_39 ;
return 0 ;
}
int F_227 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
switch ( V_34 -> V_148 ) {
case V_467 :
case V_468 :
case V_413 :
case V_469 :
case V_470 :
case V_471 :
case V_472 :
case V_473 :
case V_474 :
case V_475 :
case V_411 :
case V_407 :
case V_476 :
case V_404 :
case V_412 :
case V_409 :
case V_477 :
V_34 -> V_39 = 0 ;
break;
case V_443 ... V_444 :
case V_439 ... V_440 :
case V_441 ... V_442 :
case V_445 ... V_446 :
if ( F_222 ( V_2 , V_34 -> V_148 ) )
return F_228 ( V_2 , V_34 -> V_148 , & V_34 -> V_39 ) ;
V_34 -> V_39 = 0 ;
break;
case V_405 :
V_34 -> V_39 = 0x100000000ULL ;
break;
case V_478 :
case 0x200 ... 0x2ff :
return F_229 ( V_2 , V_34 -> V_148 , & V_34 -> V_39 ) ;
case 0xcd :
V_34 -> V_39 = 3 ;
break;
case V_479 :
V_34 -> V_39 = 1 << 24 ;
break;
case V_416 :
V_34 -> V_39 = F_21 ( V_2 ) ;
break;
case V_417 ... V_417 + 0x3ff :
return F_230 ( V_2 , V_34 -> V_148 , & V_34 -> V_39 ) ;
break;
case V_418 :
V_34 -> V_39 = F_231 ( V_2 ) ;
break;
case V_419 :
V_34 -> V_39 = ( T_2 ) V_2 -> V_5 . V_302 ;
break;
case V_421 :
V_34 -> V_39 = V_2 -> V_5 . V_422 ;
break;
case V_423 :
if ( ! V_34 -> V_41 )
return 1 ;
V_34 -> V_39 = V_2 -> V_5 . V_424 ;
break;
case V_480 :
V_34 -> V_39 = 1000ULL ;
V_34 -> V_39 |= ( ( ( T_8 ) 4ULL ) << 40 ) ;
break;
case V_410 :
V_34 -> V_39 = V_2 -> V_5 . V_133 ;
break;
case V_426 :
case V_425 :
V_34 -> V_39 = V_2 -> V_140 -> V_5 . V_242 ;
break;
case V_428 :
case V_427 :
V_34 -> V_39 = V_2 -> V_5 . time ;
break;
case V_432 :
V_34 -> V_39 = V_2 -> V_5 . V_6 . V_390 ;
break;
case V_433 :
V_34 -> V_39 = V_2 -> V_5 . V_394 . V_390 ;
break;
case V_437 :
V_34 -> V_39 = V_2 -> V_5 . V_481 . V_390 ;
break;
case V_464 :
case V_465 :
case V_466 :
case V_370 :
case V_368 :
case V_373 ... F_202 ( V_438 ) - 1 :
return F_226 ( V_2 , V_34 -> V_148 , & V_34 -> V_39 ) ;
case V_447 :
V_34 -> V_39 = 0x20000000 ;
break;
case V_448 ... V_449 :
case V_450 ... V_451 :
case V_452 :
case V_453 ... V_454 :
return F_232 ( V_2 ,
V_34 -> V_148 , & V_34 -> V_39 ) ;
break;
case V_455 :
V_34 -> V_39 = 0xbe702111 ;
break;
case V_456 :
if ( ! F_225 ( V_2 ) )
return 1 ;
V_34 -> V_39 = V_2 -> V_5 . V_457 . V_458 ;
break;
case V_459 :
if ( ! F_225 ( V_2 ) )
return 1 ;
V_34 -> V_39 = V_2 -> V_5 . V_457 . V_460 ;
break;
default:
if ( F_222 ( V_2 , V_34 -> V_148 ) )
return F_228 ( V_2 , V_34 -> V_148 , & V_34 -> V_39 ) ;
if ( ! V_461 ) {
F_215 ( V_2 , L_17 , V_34 -> V_148 ) ;
return 1 ;
} else {
F_215 ( V_2 , L_18 , V_34 -> V_148 ) ;
V_34 -> V_39 = 0 ;
}
break;
}
return 0 ;
}
static int F_233 ( struct V_1 * V_2 , struct V_482 * V_21 ,
struct V_483 * V_484 ,
int (* F_234)( struct V_1 * V_2 ,
unsigned V_148 , T_2 * V_39 ) )
{
int V_3 , V_485 ;
V_485 = F_235 ( & V_2 -> V_140 -> V_486 ) ;
for ( V_3 = 0 ; V_3 < V_21 -> V_487 ; ++ V_3 )
if ( F_234 ( V_2 , V_484 [ V_3 ] . V_148 , & V_484 [ V_3 ] . V_39 ) )
break;
F_236 ( & V_2 -> V_140 -> V_486 , V_485 ) ;
return V_3 ;
}
static int F_237 ( struct V_1 * V_2 , struct V_482 T_15 * V_488 ,
int (* F_234)( struct V_1 * V_2 ,
unsigned V_148 , T_2 * V_39 ) ,
int V_489 )
{
struct V_482 V_21 ;
struct V_483 * V_484 ;
int V_122 , V_490 ;
unsigned V_491 ;
V_122 = - V_102 ;
if ( F_238 ( & V_21 , V_488 , sizeof V_21 ) )
goto V_114;
V_122 = - V_386 ;
if ( V_21 . V_487 >= V_492 )
goto V_114;
V_491 = sizeof( struct V_483 ) * V_21 . V_487 ;
V_484 = F_204 ( V_488 -> V_484 , V_491 ) ;
if ( F_205 ( V_484 ) ) {
V_122 = F_206 ( V_484 ) ;
goto V_114;
}
V_122 = V_490 = F_233 ( V_2 , & V_21 , V_484 , F_234 ) ;
if ( V_122 < 0 )
goto V_388;
V_122 = - V_102 ;
if ( V_489 && F_239 ( V_488 -> V_484 , V_484 , V_491 ) )
goto V_388;
V_122 = V_490 ;
V_388:
F_208 ( V_484 ) ;
V_114:
return V_122 ;
}
int F_240 ( struct V_140 * V_140 , long V_493 )
{
int V_122 ;
switch ( V_493 ) {
case V_494 :
case V_495 :
case V_496 :
case V_497 :
case V_498 :
case V_499 :
case V_500 :
case V_501 :
case V_502 :
case V_503 :
case V_504 :
case V_505 :
case V_506 :
case V_507 :
case V_508 :
case V_509 :
case V_510 :
case V_511 :
case V_512 :
case V_513 :
case V_514 :
case V_515 :
case V_516 :
case V_517 :
case V_518 :
case V_519 :
case V_520 :
case V_521 :
case V_522 :
case V_523 :
case V_524 :
case V_525 :
case V_526 :
case V_527 :
case V_528 :
case V_529 :
case V_530 :
case V_531 :
case V_532 :
case V_533 :
#ifdef F_241
case V_534 :
case V_535 :
#endif
V_122 = 1 ;
break;
case V_536 :
V_122 = V_537 ;
break;
case V_538 :
V_122 = V_74 -> V_539 () ;
break;
case V_540 :
V_122 = V_541 ;
break;
case V_542 :
V_122 = ! V_74 -> V_543 () ;
break;
case V_544 :
V_122 = V_545 ;
break;
case V_546 :
V_122 = V_547 ;
break;
case V_548 :
V_122 = V_549 ;
break;
case V_550 :
V_122 = 0 ;
break;
#ifdef F_241
case V_551 :
V_122 = F_242 ( & V_552 ) ;
break;
#endif
case V_553 :
V_122 = V_438 ;
break;
case V_554 :
V_122 = F_243 ( V_555 ) ;
break;
case V_556 :
V_122 = V_272 ;
break;
case V_557 :
V_122 = V_558 ;
break;
default:
V_122 = 0 ;
break;
}
return V_122 ;
}
long F_244 ( struct V_559 * V_560 ,
unsigned int V_561 , unsigned long V_562 )
{
void T_15 * V_563 = ( void T_15 * ) V_562 ;
long V_122 ;
switch ( V_561 ) {
case V_564 : {
struct V_565 T_15 * V_566 = V_563 ;
struct V_565 V_567 ;
unsigned V_490 ;
V_122 = - V_102 ;
if ( F_238 ( & V_567 , V_566 , sizeof V_567 ) )
goto V_114;
V_490 = V_567 . V_487 ;
V_567 . V_487 = V_568 + V_569 ;
if ( F_239 ( V_566 , & V_567 , sizeof V_567 ) )
goto V_114;
V_122 = - V_386 ;
if ( V_490 < V_567 . V_487 )
goto V_114;
V_122 = - V_102 ;
if ( F_239 ( V_566 -> V_570 , & V_571 ,
V_568 * sizeof( T_1 ) ) )
goto V_114;
if ( F_239 ( V_566 -> V_570 + V_568 ,
& V_572 ,
V_569 * sizeof( T_1 ) ) )
goto V_114;
V_122 = 0 ;
break;
}
case V_573 :
case V_574 : {
struct V_575 T_15 * V_576 = V_563 ;
struct V_575 V_577 ;
V_122 = - V_102 ;
if ( F_238 ( & V_577 , V_576 , sizeof V_577 ) )
goto V_114;
V_122 = F_245 ( & V_577 , V_576 -> V_484 ,
V_561 ) ;
if ( V_122 )
goto V_114;
V_122 = - V_102 ;
if ( F_239 ( V_576 , & V_577 , sizeof V_577 ) )
goto V_114;
V_122 = 0 ;
break;
}
case V_578 : {
V_122 = - V_102 ;
if ( F_239 ( V_563 , & V_579 ,
sizeof( V_579 ) ) )
goto V_114;
V_122 = 0 ;
break;
}
default:
V_122 = - V_580 ;
}
V_114:
return V_122 ;
}
static void F_246 ( void * V_581 )
{
F_247 () ;
}
static bool F_248 ( struct V_1 * V_2 )
{
return F_67 ( V_2 -> V_140 ) ;
}
static inline void F_249 ( struct V_1 * V_2 )
{
F_219 ( V_582 , & V_2 -> V_339 ) ;
}
void F_250 ( struct V_1 * V_2 , int V_24 )
{
if ( F_248 ( V_2 ) ) {
if ( V_74 -> V_583 () )
F_251 ( V_24 , V_2 -> V_5 . V_584 ) ;
else if ( V_2 -> V_24 != - 1 && V_2 -> V_24 != V_24 )
F_252 ( V_2 -> V_24 ,
F_246 , NULL , 1 ) ;
}
V_74 -> V_585 ( V_2 , V_24 ) ;
if ( F_170 ( V_2 -> V_5 . V_586 ) ) {
F_163 ( V_2 , V_2 -> V_5 . V_586 ) ;
V_2 -> V_5 . V_586 = 0 ;
F_32 ( V_338 , V_2 ) ;
}
if ( F_170 ( V_2 -> V_24 != V_24 ) || F_156 () ) {
T_12 V_587 = ! V_2 -> V_5 . V_588 ? 0 :
F_150 () - V_2 -> V_5 . V_588 ;
if ( V_587 < 0 )
F_253 ( L_19 ) ;
if ( F_156 () ) {
T_2 V_95 = F_149 ( V_2 ,
V_2 -> V_5 . V_324 ) ;
F_152 ( V_2 , V_95 ) ;
V_2 -> V_5 . V_274 = 1 ;
}
if ( F_254 ( V_2 ) &&
V_74 -> V_589 ( V_2 ,
F_231 ( V_2 ) ) )
F_255 ( V_2 ) ;
if ( ! V_2 -> V_140 -> V_5 . V_296 || V_2 -> V_24 == - 1 )
F_32 ( V_431 , V_2 ) ;
if ( V_2 -> V_24 != V_24 )
F_249 ( V_2 ) ;
V_2 -> V_24 = V_24 ;
}
F_32 ( V_436 , V_2 ) ;
}
void F_256 ( struct V_1 * V_2 )
{
V_74 -> V_590 ( V_2 ) ;
F_257 ( V_2 ) ;
V_2 -> V_5 . V_588 = F_150 () ;
}
static int F_258 ( struct V_1 * V_2 ,
struct V_591 * V_592 )
{
if ( V_2 -> V_5 . V_593 )
V_74 -> V_594 ( V_2 ) ;
return F_259 ( V_2 , V_592 ) ;
}
static int F_260 ( struct V_1 * V_2 ,
struct V_591 * V_592 )
{
int V_122 ;
V_122 = F_261 ( V_2 , V_592 ) ;
if ( V_122 )
return V_122 ;
F_262 ( V_2 ) ;
return 0 ;
}
static int F_263 ( struct V_1 * V_2 )
{
return ( ! F_90 ( V_2 ) ||
F_264 ( V_2 ) ) ;
}
static int F_265 ( struct V_1 * V_2 )
{
return F_266 ( V_2 ) &&
! F_267 ( V_2 ) &&
! F_268 ( V_2 ) &&
F_263 ( V_2 ) ;
}
static int F_269 ( struct V_1 * V_2 ,
struct V_595 * V_596 )
{
if ( V_596 -> V_596 >= V_597 )
return - V_580 ;
if ( ! F_270 ( V_2 -> V_140 ) ) {
F_271 ( V_2 , V_596 -> V_596 , false ) ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
if ( F_272 ( V_2 -> V_140 ) )
return - V_598 ;
if ( V_2 -> V_5 . V_599 != - 1 )
return - V_600 ;
V_2 -> V_5 . V_599 = V_596 -> V_596 ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
static int F_273 ( struct V_1 * V_2 )
{
F_42 ( V_2 ) ;
return 0 ;
}
static int F_274 ( struct V_1 * V_2 )
{
F_32 ( V_601 , V_2 ) ;
return 0 ;
}
static int F_275 ( struct V_1 * V_2 ,
struct V_602 * V_603 )
{
if ( V_603 -> V_15 )
return - V_580 ;
V_2 -> V_5 . V_604 = ! ! V_603 -> V_605 ;
return 0 ;
}
static int F_276 ( struct V_1 * V_2 ,
T_2 V_366 )
{
int V_122 ;
unsigned V_367 = V_366 & 0xff , V_606 ;
V_122 = - V_580 ;
if ( ! V_367 || V_367 >= V_438 )
goto V_114;
if ( V_366 & ~ ( V_579 | 0xff | 0xff0000 ) )
goto V_114;
V_122 = 0 ;
V_2 -> V_5 . V_366 = V_366 ;
if ( V_366 & V_371 )
V_2 -> V_5 . V_372 = ~ ( T_2 ) 0 ;
for ( V_606 = 0 ; V_606 < V_367 ; V_606 ++ )
V_2 -> V_5 . V_374 [ V_606 * 4 ] = ~ ( T_2 ) 0 ;
if ( V_74 -> V_607 )
V_74 -> V_607 ( V_2 ) ;
V_114:
return V_122 ;
}
static int F_277 ( struct V_1 * V_2 ,
struct V_608 * V_609 )
{
T_2 V_366 = V_2 -> V_5 . V_366 ;
unsigned V_367 = V_366 & 0xff ;
T_2 * V_610 = V_2 -> V_5 . V_374 ;
if ( V_609 -> V_606 >= V_367 || ! ( V_609 -> V_460 & V_611 ) )
return - V_580 ;
if ( ( V_609 -> V_460 & V_612 ) && ( V_366 & V_371 ) &&
V_2 -> V_5 . V_372 != ~ ( T_2 ) 0 )
return 0 ;
V_610 += 4 * V_609 -> V_606 ;
if ( ( V_609 -> V_460 & V_612 ) && V_610 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_609 -> V_460 & V_612 ) {
if ( ( V_2 -> V_5 . V_369 & V_613 ) ||
! F_47 ( V_2 , V_614 ) ) {
F_32 ( V_73 , V_2 ) ;
return 0 ;
}
if ( V_610 [ 1 ] & V_611 )
V_609 -> V_460 |= V_615 ;
V_610 [ 2 ] = V_609 -> V_616 ;
V_610 [ 3 ] = V_609 -> V_617 ;
V_2 -> V_5 . V_369 = V_609 -> V_369 ;
V_610 [ 1 ] = V_609 -> V_460 ;
F_34 ( V_2 , V_59 ) ;
} else if ( ! ( V_610 [ 1 ] & V_611 )
|| ! ( V_610 [ 1 ] & V_612 ) ) {
if ( V_610 [ 1 ] & V_611 )
V_609 -> V_460 |= V_615 ;
V_610 [ 2 ] = V_609 -> V_616 ;
V_610 [ 3 ] = V_609 -> V_617 ;
V_610 [ 1 ] = V_609 -> V_460 ;
} else
V_610 [ 1 ] |= V_615 ;
return 0 ;
}
static void F_278 ( struct V_1 * V_2 ,
struct V_618 * V_619 )
{
F_279 ( V_2 ) ;
V_619 -> V_69 . V_620 =
V_2 -> V_5 . V_69 . V_70 &&
! F_280 ( V_2 -> V_5 . V_69 . V_18 ) ;
V_619 -> V_69 . V_18 = V_2 -> V_5 . V_69 . V_18 ;
V_619 -> V_69 . V_72 = V_2 -> V_5 . V_69 . V_72 ;
V_619 -> V_69 . V_621 = 0 ;
V_619 -> V_69 . V_63 = V_2 -> V_5 . V_69 . V_63 ;
V_619 -> V_622 . V_620 =
V_2 -> V_5 . V_622 . V_70 && ! V_2 -> V_5 . V_622 . V_623 ;
V_619 -> V_622 . V_18 = V_2 -> V_5 . V_622 . V_18 ;
V_619 -> V_622 . V_623 = 0 ;
V_619 -> V_622 . V_624 = V_74 -> V_625 ( V_2 ) ;
V_619 -> V_626 . V_620 = V_2 -> V_5 . V_627 ;
V_619 -> V_626 . V_70 = V_2 -> V_5 . V_628 != 0 ;
V_619 -> V_626 . V_629 = V_74 -> V_630 ( V_2 ) ;
V_619 -> V_626 . V_621 = 0 ;
V_619 -> V_631 = 0 ;
V_619 -> V_632 . V_633 = F_281 ( V_2 ) ;
V_619 -> V_632 . V_70 = V_2 -> V_5 . V_634 ;
V_619 -> V_632 . V_635 =
! ! ( V_2 -> V_5 . V_636 & V_637 ) ;
V_619 -> V_632 . V_638 = F_282 ( V_2 ) ;
V_619 -> V_15 = ( V_639
| V_640
| V_641 ) ;
memset ( & V_619 -> V_642 , 0 , sizeof( V_619 -> V_642 ) ) ;
}
static int F_283 ( struct V_1 * V_2 ,
struct V_618 * V_619 )
{
if ( V_619 -> V_15 & ~ ( V_639
| V_643
| V_640
| V_641 ) )
return - V_580 ;
if ( V_619 -> V_69 . V_620 &&
( V_619 -> V_69 . V_18 > 31 || V_619 -> V_69 . V_18 == V_52 ) )
return - V_580 ;
F_279 ( V_2 ) ;
V_2 -> V_5 . V_69 . V_70 = V_619 -> V_69 . V_620 ;
V_2 -> V_5 . V_69 . V_18 = V_619 -> V_69 . V_18 ;
V_2 -> V_5 . V_69 . V_72 = V_619 -> V_69 . V_72 ;
V_2 -> V_5 . V_69 . V_63 = V_619 -> V_69 . V_63 ;
V_2 -> V_5 . V_622 . V_70 = V_619 -> V_622 . V_620 ;
V_2 -> V_5 . V_622 . V_18 = V_619 -> V_622 . V_18 ;
V_2 -> V_5 . V_622 . V_623 = V_619 -> V_622 . V_623 ;
if ( V_619 -> V_15 & V_640 )
V_74 -> V_644 ( V_2 ,
V_619 -> V_622 . V_624 ) ;
V_2 -> V_5 . V_627 = V_619 -> V_626 . V_620 ;
if ( V_619 -> V_15 & V_639 )
V_2 -> V_5 . V_628 = V_619 -> V_626 . V_70 ;
V_74 -> V_645 ( V_2 , V_619 -> V_626 . V_629 ) ;
if ( V_619 -> V_15 & V_643 &&
F_90 ( V_2 ) )
V_2 -> V_5 . V_646 -> V_631 = V_619 -> V_631 ;
if ( V_619 -> V_15 & V_641 ) {
if ( V_619 -> V_632 . V_633 )
V_2 -> V_5 . V_636 |= V_647 ;
else
V_2 -> V_5 . V_636 &= ~ V_647 ;
V_2 -> V_5 . V_634 = V_619 -> V_632 . V_70 ;
if ( V_619 -> V_632 . V_635 )
V_2 -> V_5 . V_636 |= V_637 ;
else
V_2 -> V_5 . V_636 &= ~ V_637 ;
if ( F_90 ( V_2 ) ) {
if ( V_619 -> V_632 . V_638 )
F_219 ( V_648 , & V_2 -> V_5 . V_646 -> V_649 ) ;
else
F_180 ( V_648 , & V_2 -> V_5 . V_646 -> V_649 ) ;
}
}
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
static void F_284 ( struct V_1 * V_2 ,
struct V_650 * V_651 )
{
unsigned long V_197 ;
memcpy ( V_651 -> V_184 , V_2 -> V_5 . V_184 , sizeof( V_2 -> V_5 . V_184 ) ) ;
F_101 ( V_2 , 6 , & V_197 ) ;
V_651 -> V_188 = V_197 ;
V_651 -> V_189 = V_2 -> V_5 . V_189 ;
V_651 -> V_15 = 0 ;
memset ( & V_651 -> V_642 , 0 , sizeof( V_651 -> V_642 ) ) ;
}
static int F_285 ( struct V_1 * V_2 ,
struct V_650 * V_651 )
{
if ( V_651 -> V_15 )
return - V_580 ;
if ( V_651 -> V_188 & ~ 0xffffffffull )
return - V_580 ;
if ( V_651 -> V_189 & ~ 0xffffffffull )
return - V_580 ;
memcpy ( V_2 -> V_5 . V_184 , V_651 -> V_184 , sizeof( V_2 -> V_5 . V_184 ) ) ;
F_94 ( V_2 ) ;
V_2 -> V_5 . V_188 = V_651 -> V_188 ;
F_95 ( V_2 ) ;
V_2 -> V_5 . V_189 = V_651 -> V_189 ;
F_96 ( V_2 ) ;
return 0 ;
}
static void F_286 ( T_14 * V_652 , struct V_1 * V_2 )
{
struct V_653 * V_654 = & V_2 -> V_5 . V_655 . V_656 . V_654 ;
T_2 V_657 = V_654 -> V_658 . V_659 ;
T_2 V_660 ;
memcpy ( V_652 , V_654 , V_661 ) ;
* ( T_2 * ) ( V_652 + V_661 ) = V_657 ;
V_660 = V_657 & ~ V_662 ;
while ( V_660 ) {
T_2 V_663 = V_660 & - V_660 ;
int V_148 = F_287 ( V_663 ) - 1 ;
void * V_664 = F_288 ( V_654 , V_663 ) ;
if ( V_664 ) {
T_1 V_491 , V_95 , V_202 , V_210 ;
F_289 ( V_665 , V_148 ,
& V_491 , & V_95 , & V_202 , & V_210 ) ;
memcpy ( V_652 + V_95 , V_664 , V_491 ) ;
}
V_660 -= V_663 ;
}
}
static void F_290 ( struct V_1 * V_2 , T_14 * V_664 )
{
struct V_653 * V_654 = & V_2 -> V_5 . V_655 . V_656 . V_654 ;
T_2 V_657 = * ( T_2 * ) ( V_664 + V_661 ) ;
T_2 V_660 ;
memcpy ( V_654 , V_664 , V_661 ) ;
V_654 -> V_658 . V_659 = V_657 ;
if ( F_243 ( V_666 ) )
V_654 -> V_658 . V_667 = V_147 | V_668 ;
V_660 = V_657 & ~ V_662 ;
while ( V_660 ) {
T_2 V_663 = V_660 & - V_660 ;
int V_148 = F_287 ( V_663 ) - 1 ;
void * V_652 = F_288 ( V_654 , V_663 ) ;
if ( V_652 ) {
T_1 V_491 , V_95 , V_202 , V_210 ;
F_289 ( V_665 , V_148 ,
& V_491 , & V_95 , & V_202 , & V_210 ) ;
memcpy ( V_652 , V_664 + V_95 , V_491 ) ;
}
V_660 -= V_663 ;
}
}
static void F_291 ( struct V_1 * V_2 ,
struct V_669 * V_670 )
{
if ( F_243 ( V_555 ) ) {
memset ( V_670 , 0 , sizeof( struct V_669 ) ) ;
F_286 ( ( T_14 * ) V_670 -> V_671 , V_2 ) ;
} else {
memcpy ( V_670 -> V_671 ,
& V_2 -> V_5 . V_655 . V_656 . V_672 ,
sizeof( struct V_673 ) ) ;
* ( T_2 * ) & V_670 -> V_671 [ V_661 / sizeof( T_1 ) ] =
V_662 ;
}
}
static int F_292 ( struct V_1 * V_2 ,
struct V_669 * V_670 )
{
T_2 V_657 =
* ( T_2 * ) & V_670 -> V_671 [ V_661 / sizeof( T_1 ) ] ;
if ( F_243 ( V_555 ) ) {
if ( V_657 & ~ F_293 () )
return - V_580 ;
F_290 ( V_2 , ( T_14 * ) V_670 -> V_671 ) ;
} else {
if ( V_657 & ~ V_662 )
return - V_580 ;
memcpy ( & V_2 -> V_5 . V_655 . V_656 . V_672 ,
V_670 -> V_671 , sizeof( struct V_673 ) ) ;
}
return 0 ;
}
static void F_294 ( struct V_1 * V_2 ,
struct V_674 * V_675 )
{
if ( ! F_243 ( V_555 ) ) {
V_675 -> V_676 = 0 ;
return;
}
V_675 -> V_676 = 1 ;
V_675 -> V_15 = 0 ;
V_675 -> V_677 [ 0 ] . V_149 = V_145 ;
V_675 -> V_677 [ 0 ] . V_23 = V_2 -> V_5 . V_146 ;
}
static int F_295 ( struct V_1 * V_2 ,
struct V_674 * V_675 )
{
int V_3 , V_122 = 0 ;
if ( ! F_243 ( V_555 ) )
return - V_580 ;
if ( V_675 -> V_676 > V_678 || V_675 -> V_15 )
return - V_580 ;
for ( V_3 = 0 ; V_3 < V_675 -> V_676 ; V_3 ++ )
if ( V_675 -> V_677 [ V_3 ] . V_149 == V_145 ) {
V_122 = F_75 ( V_2 , V_145 ,
V_675 -> V_677 [ V_3 ] . V_23 ) ;
break;
}
if ( V_122 )
V_122 = - V_580 ;
return V_122 ;
}
static int F_296 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_356 )
return - V_580 ;
V_2 -> V_5 . V_351 = true ;
F_32 ( V_338 , V_2 ) ;
return 0 ;
}
static int F_297 ( struct V_1 * V_2 ,
struct V_679 * V_680 )
{
if ( V_680 -> V_15 )
return - V_580 ;
switch ( V_680 -> V_680 ) {
case V_518 :
return F_298 ( V_2 ) ;
default:
return - V_580 ;
}
}
long F_299 ( struct V_559 * V_560 ,
unsigned int V_561 , unsigned long V_562 )
{
struct V_1 * V_2 = V_560 -> V_681 ;
void T_15 * V_563 = ( void T_15 * ) V_562 ;
int V_122 ;
union {
struct V_591 * V_682 ;
struct V_669 * V_654 ;
struct V_674 * V_677 ;
void * V_683 ;
} V_684 ;
V_684 . V_683 = NULL ;
switch ( V_561 ) {
case V_685 : {
V_122 = - V_580 ;
if ( ! F_90 ( V_2 ) )
goto V_114;
V_684 . V_682 = F_300 ( sizeof( struct V_591 ) , V_686 ) ;
V_122 = - V_387 ;
if ( ! V_684 . V_682 )
goto V_114;
V_122 = F_258 ( V_2 , V_684 . V_682 ) ;
if ( V_122 )
goto V_114;
V_122 = - V_102 ;
if ( F_239 ( V_563 , V_684 . V_682 , sizeof( struct V_591 ) ) )
goto V_114;
V_122 = 0 ;
break;
}
case V_687 : {
V_122 = - V_580 ;
if ( ! F_90 ( V_2 ) )
goto V_114;
V_684 . V_682 = F_204 ( V_563 , sizeof( * V_684 . V_682 ) ) ;
if ( F_205 ( V_684 . V_682 ) )
return F_206 ( V_684 . V_682 ) ;
V_122 = F_260 ( V_2 , V_684 . V_682 ) ;
break;
}
case V_688 : {
struct V_595 V_596 ;
V_122 = - V_102 ;
if ( F_238 ( & V_596 , V_563 , sizeof V_596 ) )
goto V_114;
V_122 = F_269 ( V_2 , & V_596 ) ;
break;
}
case V_689 : {
V_122 = F_273 ( V_2 ) ;
break;
}
case V_690 : {
V_122 = F_274 ( V_2 ) ;
break;
}
case V_691 : {
struct V_692 T_15 * V_576 = V_563 ;
struct V_692 V_577 ;
V_122 = - V_102 ;
if ( F_238 ( & V_577 , V_576 , sizeof V_577 ) )
goto V_114;
V_122 = F_301 ( V_2 , & V_577 , V_576 -> V_484 ) ;
break;
}
case V_693 : {
struct V_575 T_15 * V_576 = V_563 ;
struct V_575 V_577 ;
V_122 = - V_102 ;
if ( F_238 ( & V_577 , V_576 , sizeof V_577 ) )
goto V_114;
V_122 = F_302 ( V_2 , & V_577 ,
V_576 -> V_484 ) ;
break;
}
case V_694 : {
struct V_575 T_15 * V_576 = V_563 ;
struct V_575 V_577 ;
V_122 = - V_102 ;
if ( F_238 ( & V_577 , V_576 , sizeof V_577 ) )
goto V_114;
V_122 = F_303 ( V_2 , & V_577 ,
V_576 -> V_484 ) ;
if ( V_122 )
goto V_114;
V_122 = - V_102 ;
if ( F_239 ( V_576 , & V_577 , sizeof V_577 ) )
goto V_114;
V_122 = 0 ;
break;
}
case V_695 :
V_122 = F_237 ( V_2 , V_563 , F_114 , 1 ) ;
break;
case V_696 :
V_122 = F_237 ( V_2 , V_563 , F_116 , 0 ) ;
break;
case V_697 : {
struct V_602 V_603 ;
V_122 = - V_102 ;
if ( F_238 ( & V_603 , V_563 , sizeof V_603 ) )
goto V_114;
V_122 = F_275 ( V_2 , & V_603 ) ;
if ( V_122 )
goto V_114;
V_122 = - V_102 ;
if ( F_239 ( V_563 , & V_603 , sizeof V_603 ) )
goto V_114;
V_122 = 0 ;
break;
} ;
case V_698 : {
struct V_699 V_700 ;
int V_485 ;
V_122 = - V_580 ;
if ( ! F_90 ( V_2 ) )
goto V_114;
V_122 = - V_102 ;
if ( F_238 ( & V_700 , V_563 , sizeof V_700 ) )
goto V_114;
V_485 = F_235 ( & V_2 -> V_140 -> V_486 ) ;
V_122 = F_304 ( V_2 , V_700 . V_701 ) ;
F_236 ( & V_2 -> V_140 -> V_486 , V_485 ) ;
break;
}
case V_702 : {
T_2 V_366 ;
V_122 = - V_102 ;
if ( F_238 ( & V_366 , V_563 , sizeof V_366 ) )
goto V_114;
V_122 = F_276 ( V_2 , V_366 ) ;
break;
}
case V_703 : {
struct V_608 V_609 ;
V_122 = - V_102 ;
if ( F_238 ( & V_609 , V_563 , sizeof V_609 ) )
goto V_114;
V_122 = F_277 ( V_2 , & V_609 ) ;
break;
}
case V_704 : {
struct V_618 V_619 ;
F_278 ( V_2 , & V_619 ) ;
V_122 = - V_102 ;
if ( F_239 ( V_563 , & V_619 , sizeof( struct V_618 ) ) )
break;
V_122 = 0 ;
break;
}
case V_705 : {
struct V_618 V_619 ;
V_122 = - V_102 ;
if ( F_238 ( & V_619 , V_563 , sizeof( struct V_618 ) ) )
break;
V_122 = F_283 ( V_2 , & V_619 ) ;
break;
}
case V_706 : {
struct V_650 V_651 ;
F_284 ( V_2 , & V_651 ) ;
V_122 = - V_102 ;
if ( F_239 ( V_563 , & V_651 ,
sizeof( struct V_650 ) ) )
break;
V_122 = 0 ;
break;
}
case V_707 : {
struct V_650 V_651 ;
V_122 = - V_102 ;
if ( F_238 ( & V_651 , V_563 ,
sizeof( struct V_650 ) ) )
break;
V_122 = F_285 ( V_2 , & V_651 ) ;
break;
}
case V_708 : {
V_684 . V_654 = F_300 ( sizeof( struct V_669 ) , V_686 ) ;
V_122 = - V_387 ;
if ( ! V_684 . V_654 )
break;
F_291 ( V_2 , V_684 . V_654 ) ;
V_122 = - V_102 ;
if ( F_239 ( V_563 , V_684 . V_654 , sizeof( struct V_669 ) ) )
break;
V_122 = 0 ;
break;
}
case V_709 : {
V_684 . V_654 = F_204 ( V_563 , sizeof( * V_684 . V_654 ) ) ;
if ( F_205 ( V_684 . V_654 ) )
return F_206 ( V_684 . V_654 ) ;
V_122 = F_292 ( V_2 , V_684 . V_654 ) ;
break;
}
case V_710 : {
V_684 . V_677 = F_300 ( sizeof( struct V_674 ) , V_686 ) ;
V_122 = - V_387 ;
if ( ! V_684 . V_677 )
break;
F_294 ( V_2 , V_684 . V_677 ) ;
V_122 = - V_102 ;
if ( F_239 ( V_563 , V_684 . V_677 ,
sizeof( struct V_674 ) ) )
break;
V_122 = 0 ;
break;
}
case V_711 : {
V_684 . V_677 = F_204 ( V_563 , sizeof( * V_684 . V_677 ) ) ;
if ( F_205 ( V_684 . V_677 ) )
return F_206 ( V_684 . V_677 ) ;
V_122 = F_295 ( V_2 , V_684 . V_677 ) ;
break;
}
case V_712 : {
T_1 V_267 ;
V_122 = - V_580 ;
V_267 = ( T_1 ) V_562 ;
if ( V_267 >= V_713 )
goto V_114;
if ( V_267 == 0 )
V_267 = V_273 ;
if ( ! F_139 ( V_2 , V_267 ) )
V_122 = 0 ;
goto V_114;
}
case V_714 : {
V_122 = V_2 -> V_5 . V_284 ;
goto V_114;
}
case V_715 : {
V_122 = F_296 ( V_2 ) ;
goto V_114;
}
case V_716 : {
struct V_679 V_680 ;
V_122 = - V_102 ;
if ( F_238 ( & V_680 , V_563 , sizeof( V_680 ) ) )
goto V_114;
V_122 = F_297 ( V_2 , & V_680 ) ;
break;
}
default:
V_122 = - V_580 ;
}
V_114:
F_208 ( V_684 . V_683 ) ;
return V_122 ;
}
int F_305 ( struct V_1 * V_2 , struct V_717 * V_718 )
{
return V_719 ;
}
static int F_306 ( struct V_140 * V_140 , unsigned long V_616 )
{
int V_109 ;
if ( V_616 > ( unsigned int ) ( - 3 * V_108 ) )
return - V_580 ;
V_109 = V_74 -> V_720 ( V_140 , V_616 ) ;
return V_109 ;
}
static int F_307 ( struct V_140 * V_140 ,
T_2 V_721 )
{
V_140 -> V_5 . V_722 = V_721 ;
return 0 ;
}
static int F_308 ( struct V_140 * V_140 ,
T_1 V_723 )
{
if ( V_723 < V_724 )
return - V_580 ;
F_309 ( & V_140 -> V_725 ) ;
F_310 ( V_140 , V_723 ) ;
V_140 -> V_5 . V_726 = V_723 ;
F_311 ( & V_140 -> V_725 ) ;
return 0 ;
}
static int F_312 ( struct V_140 * V_140 )
{
return V_140 -> V_5 . V_727 ;
}
static int F_313 ( struct V_140 * V_140 , struct V_728 * V_729 )
{
int V_122 ;
V_122 = 0 ;
switch ( V_729 -> V_730 ) {
case V_731 :
memcpy ( & V_729 -> V_729 . V_732 ,
& F_314 ( V_140 ) -> V_733 [ 0 ] ,
sizeof( struct V_734 ) ) ;
break;
case V_735 :
memcpy ( & V_729 -> V_729 . V_732 ,
& F_314 ( V_140 ) -> V_733 [ 1 ] ,
sizeof( struct V_734 ) ) ;
break;
case V_736 :
V_122 = F_315 ( V_140 , & V_729 -> V_729 . V_737 ) ;
break;
default:
V_122 = - V_580 ;
break;
}
return V_122 ;
}
static int F_316 ( struct V_140 * V_140 , struct V_728 * V_729 )
{
int V_122 ;
V_122 = 0 ;
switch ( V_729 -> V_730 ) {
case V_731 :
F_160 ( & F_314 ( V_140 ) -> V_738 ) ;
memcpy ( & F_314 ( V_140 ) -> V_733 [ 0 ] ,
& V_729 -> V_729 . V_732 ,
sizeof( struct V_734 ) ) ;
F_161 ( & F_314 ( V_140 ) -> V_738 ) ;
break;
case V_735 :
F_160 ( & F_314 ( V_140 ) -> V_738 ) ;
memcpy ( & F_314 ( V_140 ) -> V_733 [ 1 ] ,
& V_729 -> V_729 . V_732 ,
sizeof( struct V_734 ) ) ;
F_161 ( & F_314 ( V_140 ) -> V_738 ) ;
break;
case V_736 :
V_122 = F_317 ( V_140 , & V_729 -> V_729 . V_737 ) ;
break;
default:
V_122 = - V_580 ;
break;
}
F_318 ( F_314 ( V_140 ) ) ;
return V_122 ;
}
static int F_319 ( struct V_140 * V_140 , struct V_739 * V_740 )
{
struct V_741 * V_742 = & V_140 -> V_5 . V_743 -> V_744 ;
F_187 ( sizeof( * V_740 ) != sizeof( V_742 -> V_745 ) ) ;
F_309 ( & V_742 -> V_738 ) ;
memcpy ( V_740 , & V_742 -> V_745 , sizeof( * V_740 ) ) ;
F_311 ( & V_742 -> V_738 ) ;
return 0 ;
}
static int F_320 ( struct V_140 * V_140 , struct V_739 * V_740 )
{
int V_3 ;
struct V_746 * V_747 = V_140 -> V_5 . V_743 ;
F_309 ( & V_747 -> V_744 . V_738 ) ;
memcpy ( & V_747 -> V_744 . V_745 , V_740 , sizeof( * V_740 ) ) ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
F_321 ( V_747 , V_3 , V_740 -> V_745 [ V_3 ] . V_748 , 0 ) ;
F_311 ( & V_747 -> V_744 . V_738 ) ;
return 0 ;
}
static int F_322 ( struct V_140 * V_140 , struct V_749 * V_740 )
{
F_309 ( & V_140 -> V_5 . V_743 -> V_744 . V_738 ) ;
memcpy ( V_740 -> V_745 , & V_140 -> V_5 . V_743 -> V_744 . V_745 ,
sizeof( V_740 -> V_745 ) ) ;
V_740 -> V_15 = V_140 -> V_5 . V_743 -> V_744 . V_15 ;
F_311 ( & V_140 -> V_5 . V_743 -> V_744 . V_738 ) ;
memset ( & V_740 -> V_642 , 0 , sizeof( V_740 -> V_642 ) ) ;
return 0 ;
}
static int F_323 ( struct V_140 * V_140 , struct V_749 * V_740 )
{
int V_750 = 0 ;
int V_3 ;
T_1 V_751 , V_752 ;
struct V_746 * V_747 = V_140 -> V_5 . V_743 ;
F_309 ( & V_747 -> V_744 . V_738 ) ;
V_751 = V_747 -> V_744 . V_15 & V_753 ;
V_752 = V_740 -> V_15 & V_753 ;
if ( ! V_751 && V_752 )
V_750 = 1 ;
memcpy ( & V_747 -> V_744 . V_745 , & V_740 -> V_745 ,
sizeof( V_747 -> V_744 . V_745 ) ) ;
V_747 -> V_744 . V_15 = V_740 -> V_15 ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
F_321 ( V_747 , V_3 , V_747 -> V_744 . V_745 [ V_3 ] . V_748 ,
V_750 && V_3 == 0 ) ;
F_311 ( & V_747 -> V_744 . V_738 ) ;
return 0 ;
}
static int F_324 ( struct V_140 * V_140 ,
struct V_754 * V_755 )
{
struct V_746 * V_747 = V_140 -> V_5 . V_743 ;
if ( ! V_747 )
return - V_598 ;
F_309 ( & V_747 -> V_744 . V_738 ) ;
F_325 ( V_747 , V_755 -> V_756 ) ;
F_311 ( & V_747 -> V_744 . V_738 ) ;
return 0 ;
}
int F_326 ( struct V_140 * V_140 , struct V_757 * log )
{
bool V_758 = false ;
int V_122 ;
F_309 ( & V_140 -> V_725 ) ;
if ( V_74 -> V_759 )
V_74 -> V_759 ( V_140 ) ;
V_122 = F_327 ( V_140 , log , & V_758 ) ;
F_328 ( & V_140 -> V_725 ) ;
if ( V_758 )
F_329 ( V_140 ) ;
F_311 ( & V_140 -> V_725 ) ;
return V_122 ;
}
int F_330 ( struct V_140 * V_140 , struct V_760 * V_761 ,
bool V_762 )
{
if ( ! F_270 ( V_140 ) )
return - V_598 ;
V_761 -> V_460 = F_331 ( V_140 , V_763 ,
V_761 -> V_596 , V_761 -> V_764 ,
V_762 ) ;
return 0 ;
}
static int F_332 ( struct V_140 * V_140 ,
struct V_679 * V_680 )
{
int V_122 ;
if ( V_680 -> V_15 )
return - V_580 ;
switch ( V_680 -> V_680 ) {
case V_531 :
V_140 -> V_5 . V_765 = V_680 -> args [ 0 ] ;
V_122 = 0 ;
break;
case V_533 : {
F_309 ( & V_140 -> V_738 ) ;
V_122 = - V_580 ;
if ( V_680 -> args [ 0 ] > V_766 )
goto V_767;
V_122 = - V_600 ;
if ( F_270 ( V_140 ) )
goto V_767;
if ( V_140 -> V_768 )
goto V_767;
V_122 = F_333 ( V_140 ) ;
if ( V_122 )
goto V_767;
F_190 () ;
V_140 -> V_5 . V_769 = true ;
V_140 -> V_5 . V_770 = V_680 -> args [ 0 ] ;
V_122 = 0 ;
V_767:
F_311 ( & V_140 -> V_738 ) ;
break;
}
case V_557 :
V_122 = - V_580 ;
if ( V_680 -> args [ 0 ] & ~ V_558 )
break;
if ( V_680 -> args [ 0 ] & V_771 )
V_140 -> V_5 . V_772 = true ;
if ( V_680 -> args [ 0 ] & V_773 )
V_140 -> V_5 . V_774 = true ;
V_122 = 0 ;
break;
default:
V_122 = - V_580 ;
break;
}
return V_122 ;
}
long F_334 ( struct V_559 * V_560 ,
unsigned int V_561 , unsigned long V_562 )
{
struct V_140 * V_140 = V_560 -> V_681 ;
void T_15 * V_563 = ( void T_15 * ) V_562 ;
int V_122 = - V_775 ;
union {
struct V_739 V_740 ;
struct V_749 V_776 ;
struct V_777 V_778 ;
} V_684 ;
switch ( V_561 ) {
case V_779 :
V_122 = F_306 ( V_140 , V_562 ) ;
break;
case V_780 : {
T_2 V_721 ;
V_122 = - V_102 ;
if ( F_238 ( & V_721 , V_563 , sizeof V_721 ) )
goto V_114;
V_122 = F_307 ( V_140 , V_721 ) ;
break;
}
case V_781 :
V_122 = F_308 ( V_140 , V_562 ) ;
break;
case V_782 :
V_122 = F_312 ( V_140 ) ;
break;
case V_783 : {
struct V_784 * V_785 ;
F_309 ( & V_140 -> V_738 ) ;
V_122 = - V_600 ;
if ( V_140 -> V_5 . V_785 )
goto V_786;
V_122 = - V_580 ;
if ( V_140 -> V_768 )
goto V_786;
V_122 = - V_387 ;
V_785 = F_335 ( V_140 ) ;
if ( V_785 ) {
V_122 = F_336 ( V_140 ) ;
if ( V_122 ) {
F_309 ( & V_140 -> V_725 ) ;
F_337 ( V_785 ) ;
F_311 ( & V_140 -> V_725 ) ;
goto V_786;
}
} else
goto V_786;
V_122 = F_338 ( V_140 ) ;
if ( V_122 ) {
F_309 ( & V_140 -> V_725 ) ;
F_309 ( & V_140 -> V_787 ) ;
F_339 ( V_140 ) ;
F_337 ( V_785 ) ;
F_311 ( & V_140 -> V_787 ) ;
F_311 ( & V_140 -> V_725 ) ;
goto V_786;
}
F_190 () ;
V_140 -> V_5 . V_785 = V_785 ;
V_786:
F_311 ( & V_140 -> V_738 ) ;
break;
}
case V_788 :
V_684 . V_778 . V_15 = V_789 ;
goto V_790;
case V_791 :
V_122 = - V_102 ;
if ( F_238 ( & V_684 . V_778 , V_563 ,
sizeof( struct V_777 ) ) )
goto V_114;
V_790:
F_309 ( & V_140 -> V_738 ) ;
V_122 = - V_600 ;
if ( V_140 -> V_5 . V_743 )
goto V_792;
V_122 = - V_387 ;
V_140 -> V_5 . V_743 = F_340 ( V_140 , V_684 . V_778 . V_15 ) ;
if ( V_140 -> V_5 . V_743 )
V_122 = 0 ;
V_792:
F_311 ( & V_140 -> V_738 ) ;
break;
case V_793 : {
struct V_728 * V_729 ;
V_729 = F_204 ( V_563 , sizeof( * V_729 ) ) ;
if ( F_205 ( V_729 ) ) {
V_122 = F_206 ( V_729 ) ;
goto V_114;
}
V_122 = - V_598 ;
if ( ! F_270 ( V_140 ) || V_769 ( V_140 ) )
goto V_794;
V_122 = F_313 ( V_140 , V_729 ) ;
if ( V_122 )
goto V_794;
V_122 = - V_102 ;
if ( F_239 ( V_563 , V_729 , sizeof *V_729 ) )
goto V_794;
V_122 = 0 ;
V_794:
F_208 ( V_729 ) ;
break;
}
case V_795 : {
struct V_728 * V_729 ;
V_729 = F_204 ( V_563 , sizeof( * V_729 ) ) ;
if ( F_205 ( V_729 ) ) {
V_122 = F_206 ( V_729 ) ;
goto V_114;
}
V_122 = - V_598 ;
if ( ! F_270 ( V_140 ) || V_769 ( V_140 ) )
goto V_796;
V_122 = F_316 ( V_140 , V_729 ) ;
if ( V_122 )
goto V_796;
V_122 = 0 ;
V_796:
F_208 ( V_729 ) ;
break;
}
case V_797 : {
V_122 = - V_102 ;
if ( F_238 ( & V_684 . V_740 , V_563 , sizeof( struct V_739 ) ) )
goto V_114;
V_122 = - V_598 ;
if ( ! V_140 -> V_5 . V_743 )
goto V_114;
V_122 = F_319 ( V_140 , & V_684 . V_740 ) ;
if ( V_122 )
goto V_114;
V_122 = - V_102 ;
if ( F_239 ( V_563 , & V_684 . V_740 , sizeof( struct V_739 ) ) )
goto V_114;
V_122 = 0 ;
break;
}
case V_798 : {
V_122 = - V_102 ;
if ( F_238 ( & V_684 . V_740 , V_563 , sizeof V_684 . V_740 ) )
goto V_114;
V_122 = - V_598 ;
if ( ! V_140 -> V_5 . V_743 )
goto V_114;
V_122 = F_320 ( V_140 , & V_684 . V_740 ) ;
break;
}
case V_799 : {
V_122 = - V_598 ;
if ( ! V_140 -> V_5 . V_743 )
goto V_114;
V_122 = F_322 ( V_140 , & V_684 . V_776 ) ;
if ( V_122 )
goto V_114;
V_122 = - V_102 ;
if ( F_239 ( V_563 , & V_684 . V_776 , sizeof( V_684 . V_776 ) ) )
goto V_114;
V_122 = 0 ;
break;
}
case V_800 : {
V_122 = - V_102 ;
if ( F_238 ( & V_684 . V_776 , V_563 , sizeof( V_684 . V_776 ) ) )
goto V_114;
V_122 = - V_598 ;
if ( ! V_140 -> V_5 . V_743 )
goto V_114;
V_122 = F_323 ( V_140 , & V_684 . V_776 ) ;
break;
}
case V_801 : {
struct V_754 V_755 ;
V_122 = - V_102 ;
if ( F_238 ( & V_755 , V_563 , sizeof( V_755 ) ) )
goto V_114;
V_122 = F_324 ( V_140 , & V_755 ) ;
break;
}
case V_802 :
V_122 = 0 ;
F_309 ( & V_140 -> V_738 ) ;
if ( V_140 -> V_768 )
V_122 = - V_803 ;
else
V_140 -> V_5 . V_804 = V_562 ;
F_311 ( & V_140 -> V_738 ) ;
break;
case V_805 : {
V_122 = - V_102 ;
if ( F_238 ( & V_140 -> V_5 . F_203 , V_563 ,
sizeof( struct V_806 ) ) )
goto V_114;
V_122 = - V_580 ;
if ( V_140 -> V_5 . F_203 . V_15 )
goto V_114;
V_122 = 0 ;
break;
}
case V_807 : {
struct V_808 V_809 ;
T_2 V_810 ;
V_122 = - V_102 ;
if ( F_238 ( & V_809 , V_563 , sizeof( V_809 ) ) )
goto V_114;
V_122 = - V_580 ;
if ( V_809 . V_15 )
goto V_114;
V_122 = 0 ;
F_341 () ;
V_810 = F_181 ( V_140 ) ;
V_140 -> V_5 . V_248 += V_809 . clock - V_810 ;
F_342 () ;
F_178 ( V_140 ) ;
break;
}
case V_811 : {
struct V_808 V_809 ;
T_2 V_810 ;
F_341 () ;
V_810 = F_181 ( V_140 ) ;
V_809 . clock = V_810 ;
V_809 . V_15 = V_140 -> V_5 . V_296 ? V_537 : 0 ;
F_342 () ;
memset ( & V_809 . V_621 , 0 , sizeof( V_809 . V_621 ) ) ;
V_122 = - V_102 ;
if ( F_239 ( V_563 , & V_809 , sizeof( V_809 ) ) )
goto V_114;
V_122 = 0 ;
break;
}
case V_716 : {
struct V_679 V_680 ;
V_122 = - V_102 ;
if ( F_238 ( & V_680 , V_563 , sizeof( V_680 ) ) )
goto V_114;
V_122 = F_332 ( V_140 , & V_680 ) ;
break;
}
default:
V_122 = F_343 ( V_140 , V_561 , V_562 ) ;
}
V_114:
return V_122 ;
}
static void F_344 ( void )
{
T_1 V_812 [ 2 ] ;
unsigned V_3 , V_813 ;
for ( V_3 = V_813 = 0 ; V_3 < F_54 ( V_571 ) ; V_3 ++ ) {
if ( F_345 ( V_571 [ V_3 ] , & V_812 [ 0 ] , & V_812 [ 1 ] ) < 0 )
continue;
switch ( V_571 [ V_3 ] ) {
case V_814 :
if ( ! V_74 -> V_815 () )
continue;
break;
case V_816 :
if ( ! V_74 -> V_817 () )
continue;
break;
default:
break;
}
if ( V_813 < V_3 )
V_571 [ V_813 ] = V_571 [ V_3 ] ;
V_813 ++ ;
}
V_568 = V_813 ;
for ( V_3 = V_813 = 0 ; V_3 < F_54 ( V_572 ) ; V_3 ++ ) {
switch ( V_572 [ V_3 ] ) {
case V_423 :
if ( ! V_74 -> V_539 () )
continue;
break;
default:
break;
}
if ( V_813 < V_3 )
V_572 [ V_813 ] = V_572 [ V_3 ] ;
V_813 ++ ;
}
V_569 = V_813 ;
}
static int F_346 ( struct V_1 * V_2 , T_6 V_616 , int V_96 ,
const void * V_266 )
{
int V_818 = 0 ;
int V_490 ;
do {
V_490 = F_347 ( V_96 , 8 ) ;
if ( ! ( F_90 ( V_2 ) &&
! F_348 ( V_2 , & V_2 -> V_5 . V_646 -> V_819 , V_616 , V_490 , V_266 ) )
&& F_349 ( V_2 , V_820 , V_616 , V_490 , V_266 ) )
break;
V_818 += V_490 ;
V_616 += V_490 ;
V_96 -= V_490 ;
V_266 += V_490 ;
} while ( V_96 );
return V_818 ;
}
static int F_350 ( struct V_1 * V_2 , T_6 V_616 , int V_96 , void * V_266 )
{
int V_818 = 0 ;
int V_490 ;
do {
V_490 = F_347 ( V_96 , 8 ) ;
if ( ! ( F_90 ( V_2 ) &&
! F_351 ( V_2 , & V_2 -> V_5 . V_646 -> V_819 ,
V_616 , V_490 , V_266 ) )
&& F_352 ( V_2 , V_820 , V_616 , V_490 , V_266 ) )
break;
F_353 ( V_821 , V_490 , V_616 , * ( T_2 * ) V_266 ) ;
V_818 += V_490 ;
V_616 += V_490 ;
V_96 -= V_490 ;
V_266 += V_490 ;
} while ( V_96 );
return V_818 ;
}
static void F_354 ( struct V_1 * V_2 ,
struct V_822 * V_823 , int V_824 )
{
V_74 -> V_825 ( V_2 , V_823 , V_824 ) ;
}
void F_355 ( struct V_1 * V_2 ,
struct V_822 * V_823 , int V_824 )
{
V_74 -> V_826 ( V_2 , V_823 , V_824 ) ;
}
T_6 F_356 ( struct V_1 * V_2 , T_6 V_389 , T_1 V_97 ,
struct V_76 * V_69 )
{
T_6 V_827 ;
F_15 ( ! F_41 ( V_2 ) ) ;
V_97 |= V_112 ;
V_827 = V_2 -> V_5 . V_85 . V_828 ( V_2 , V_389 , V_97 , V_69 ) ;
return V_827 ;
}
T_6 F_357 ( struct V_1 * V_2 , T_16 V_829 ,
struct V_76 * V_69 )
{
T_1 V_97 = ( V_74 -> V_89 ( V_2 ) == 3 ) ? V_112 : 0 ;
return V_2 -> V_5 . V_104 -> V_828 ( V_2 , V_829 , V_97 , V_69 ) ;
}
T_6 F_358 ( struct V_1 * V_2 , T_16 V_829 ,
struct V_76 * V_69 )
{
T_1 V_97 = ( V_74 -> V_89 ( V_2 ) == 3 ) ? V_112 : 0 ;
V_97 |= V_830 ;
return V_2 -> V_5 . V_104 -> V_828 ( V_2 , V_829 , V_97 , V_69 ) ;
}
T_6 F_359 ( struct V_1 * V_2 , T_16 V_829 ,
struct V_76 * V_69 )
{
T_1 V_97 = ( V_74 -> V_89 ( V_2 ) == 3 ) ? V_112 : 0 ;
V_97 |= V_113 ;
return V_2 -> V_5 . V_104 -> V_828 ( V_2 , V_829 , V_97 , V_69 ) ;
}
T_6 F_360 ( struct V_1 * V_2 , T_16 V_829 ,
struct V_76 * V_69 )
{
return V_2 -> V_5 . V_104 -> V_828 ( V_2 , V_829 , 0 , V_69 ) ;
}
static int F_361 ( T_16 V_616 , void * V_197 , unsigned int V_831 ,
struct V_1 * V_2 , T_1 V_97 ,
struct V_76 * V_69 )
{
void * V_39 = V_197 ;
int V_122 = V_832 ;
while ( V_831 ) {
T_6 V_389 = V_2 -> V_5 . V_104 -> V_828 ( V_2 , V_616 , V_97 ,
V_69 ) ;
unsigned V_95 = V_616 & ( V_108 - 1 ) ;
unsigned V_833 = F_347 ( V_831 , ( unsigned ) V_108 - V_95 ) ;
int V_109 ;
if ( V_389 == V_101 )
return V_834 ;
V_109 = F_51 ( V_2 , V_389 >> V_107 , V_39 ,
V_95 , V_833 ) ;
if ( V_109 < 0 ) {
V_122 = V_835 ;
goto V_114;
}
V_831 -= V_833 ;
V_39 += V_833 ;
V_616 += V_833 ;
}
V_114:
return V_122 ;
}
static int F_362 ( struct V_836 * V_837 ,
T_16 V_616 , void * V_197 , unsigned int V_831 ,
struct V_76 * V_69 )
{
struct V_1 * V_2 = F_363 ( V_837 ) ;
T_1 V_97 = ( V_74 -> V_89 ( V_2 ) == 3 ) ? V_112 : 0 ;
unsigned V_95 ;
int V_109 ;
T_6 V_389 = V_2 -> V_5 . V_104 -> V_828 ( V_2 , V_616 , V_97 | V_830 ,
V_69 ) ;
if ( F_170 ( V_389 == V_101 ) )
return V_834 ;
V_95 = V_616 & ( V_108 - 1 ) ;
if ( F_30 ( V_95 + V_831 > V_108 ) )
V_831 = ( unsigned ) V_108 - V_95 ;
V_109 = F_51 ( V_2 , V_389 >> V_107 , V_197 ,
V_95 , V_831 ) ;
if ( F_170 ( V_109 < 0 ) )
return V_835 ;
return V_832 ;
}
int F_364 ( struct V_836 * V_837 ,
T_16 V_616 , void * V_197 , unsigned int V_831 ,
struct V_76 * V_69 )
{
struct V_1 * V_2 = F_363 ( V_837 ) ;
T_1 V_97 = ( V_74 -> V_89 ( V_2 ) == 3 ) ? V_112 : 0 ;
return F_361 ( V_616 , V_197 , V_831 , V_2 , V_97 ,
V_69 ) ;
}
static int F_365 ( struct V_836 * V_837 ,
T_16 V_616 , void * V_197 , unsigned int V_831 ,
struct V_76 * V_69 )
{
struct V_1 * V_2 = F_363 ( V_837 ) ;
return F_361 ( V_616 , V_197 , V_831 , V_2 , 0 , V_69 ) ;
}
static int F_366 ( struct V_836 * V_837 ,
unsigned long V_616 , void * V_197 , unsigned int V_831 )
{
struct V_1 * V_2 = F_363 ( V_837 ) ;
int V_122 = F_367 ( V_2 , V_616 , V_197 , V_831 ) ;
return V_122 < 0 ? V_835 : V_832 ;
}
int F_368 ( struct V_836 * V_837 ,
T_16 V_616 , void * V_197 ,
unsigned int V_831 ,
struct V_76 * V_69 )
{
struct V_1 * V_2 = F_363 ( V_837 ) ;
void * V_39 = V_197 ;
int V_122 = V_832 ;
while ( V_831 ) {
T_6 V_389 = V_2 -> V_5 . V_104 -> V_828 ( V_2 , V_616 ,
V_113 ,
V_69 ) ;
unsigned V_95 = V_616 & ( V_108 - 1 ) ;
unsigned V_838 = F_347 ( V_831 , ( unsigned ) V_108 - V_95 ) ;
int V_109 ;
if ( V_389 == V_101 )
return V_834 ;
V_109 = F_207 ( V_2 , V_389 , V_39 , V_838 ) ;
if ( V_109 < 0 ) {
V_122 = V_835 ;
goto V_114;
}
V_831 -= V_838 ;
V_39 += V_838 ;
V_616 += V_838 ;
}
V_114:
return V_122 ;
}
static int F_369 ( struct V_1 * V_2 , unsigned long V_829 ,
T_6 * V_389 , struct V_76 * V_69 ,
bool V_839 )
{
T_1 V_97 = ( ( V_74 -> V_89 ( V_2 ) == 3 ) ? V_112 : 0 )
| ( V_839 ? V_113 : 0 ) ;
if ( F_370 ( V_2 , V_829 )
&& ! F_371 ( V_2 , V_2 -> V_5 . V_104 ,
V_2 -> V_5 . V_97 , 0 , V_97 ) ) {
* V_389 = V_2 -> V_5 . V_840 << V_107 |
( V_829 & ( V_108 - 1 ) ) ;
F_372 ( V_829 , * V_389 , V_839 , false ) ;
return 1 ;
}
* V_389 = V_2 -> V_5 . V_104 -> V_828 ( V_2 , V_829 , V_97 , V_69 ) ;
if ( * V_389 == V_101 )
return - 1 ;
if ( ( * V_389 & V_383 ) == V_841 )
return 1 ;
if ( F_373 ( V_2 , * V_389 ) ) {
F_372 ( V_829 , * V_389 , V_839 , true ) ;
return 1 ;
}
return 0 ;
}
int F_374 ( struct V_1 * V_2 , T_6 V_389 ,
const void * V_197 , int V_831 )
{
int V_109 ;
V_109 = F_207 ( V_2 , V_389 , V_197 , V_831 ) ;
if ( V_109 < 0 )
return 0 ;
F_375 ( V_2 , V_389 , V_197 , V_831 ) ;
return 1 ;
}
static int F_376 ( struct V_1 * V_2 , void * V_197 , int V_831 )
{
if ( V_2 -> V_842 ) {
F_353 ( V_821 , V_831 ,
V_2 -> V_843 [ 0 ] . V_389 , * ( T_2 * ) V_197 ) ;
V_2 -> V_842 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_377 ( struct V_1 * V_2 , T_6 V_389 ,
void * V_197 , int V_831 )
{
return ! F_367 ( V_2 , V_389 , V_197 , V_831 ) ;
}
static int F_378 ( struct V_1 * V_2 , T_6 V_389 ,
void * V_197 , int V_831 )
{
return F_374 ( V_2 , V_389 , V_197 , V_831 ) ;
}
static int F_379 ( struct V_1 * V_2 , T_6 V_389 , int V_831 , void * V_197 )
{
F_353 ( V_844 , V_831 , V_389 , * ( T_2 * ) V_197 ) ;
return F_346 ( V_2 , V_389 , V_831 , V_197 ) ;
}
static int F_380 ( struct V_1 * V_2 , T_6 V_389 ,
void * V_197 , int V_831 )
{
F_353 ( V_845 , V_831 , V_389 , 0 ) ;
return V_835 ;
}
static int F_381 ( struct V_1 * V_2 , T_6 V_389 ,
void * V_197 , int V_831 )
{
struct V_846 * V_847 = & V_2 -> V_843 [ 0 ] ;
memcpy ( V_2 -> V_848 -> V_849 . V_39 , V_847 -> V_39 , F_347 ( 8u , V_847 -> V_96 ) ) ;
return V_832 ;
}
static int F_382 ( unsigned long V_616 , void * V_197 ,
unsigned int V_831 ,
struct V_76 * V_69 ,
struct V_1 * V_2 ,
const struct V_850 * V_851 )
{
T_6 V_389 ;
int V_818 , V_109 ;
bool V_839 = V_851 -> V_839 ;
struct V_846 * V_847 ;
V_109 = F_369 ( V_2 , V_616 , & V_389 , V_69 , V_839 ) ;
if ( V_109 < 0 )
return V_834 ;
if ( V_109 )
goto V_849;
if ( V_851 -> V_852 ( V_2 , V_389 , V_197 , V_831 ) )
return V_832 ;
V_849:
V_818 = V_851 -> V_853 ( V_2 , V_389 , V_831 , V_197 ) ;
if ( V_818 == V_831 )
return V_832 ;
V_389 += V_818 ;
V_831 -= V_818 ;
V_197 += V_818 ;
F_30 ( V_2 -> V_854 >= V_855 ) ;
V_847 = & V_2 -> V_843 [ V_2 -> V_854 ++ ] ;
V_847 -> V_389 = V_389 ;
V_847 -> V_39 = V_197 ;
V_847 -> V_96 = V_831 ;
return V_832 ;
}
static int F_383 ( struct V_836 * V_837 ,
unsigned long V_616 ,
void * V_197 , unsigned int V_831 ,
struct V_76 * V_69 ,
const struct V_850 * V_851 )
{
struct V_1 * V_2 = F_363 ( V_837 ) ;
T_6 V_389 ;
int V_856 ;
if ( V_851 -> V_857 &&
V_851 -> V_857 ( V_2 , V_197 , V_831 ) )
return V_832 ;
V_2 -> V_854 = 0 ;
if ( ( ( V_616 + V_831 - 1 ) ^ V_616 ) & V_383 ) {
int V_858 ;
V_858 = - V_616 & ~ V_383 ;
V_856 = F_382 ( V_616 , V_197 , V_858 , V_69 ,
V_2 , V_851 ) ;
if ( V_856 != V_832 )
return V_856 ;
V_616 += V_858 ;
if ( V_837 -> V_330 != V_859 )
V_616 = ( T_1 ) V_616 ;
V_197 += V_858 ;
V_831 -= V_858 ;
}
V_856 = F_382 ( V_616 , V_197 , V_831 , V_69 ,
V_2 , V_851 ) ;
if ( V_856 != V_832 )
return V_856 ;
if ( ! V_2 -> V_854 )
return V_856 ;
V_389 = V_2 -> V_843 [ 0 ] . V_389 ;
V_2 -> V_860 = 1 ;
V_2 -> V_861 = 0 ;
V_2 -> V_848 -> V_849 . V_96 = F_347 ( 8u , V_2 -> V_843 [ 0 ] . V_96 ) ;
V_2 -> V_848 -> V_849 . V_862 = V_2 -> V_863 = V_851 -> V_839 ;
V_2 -> V_848 -> V_864 = V_865 ;
V_2 -> V_848 -> V_849 . V_866 = V_389 ;
return V_851 -> V_867 ( V_2 , V_389 , V_197 , V_831 ) ;
}
static int F_384 ( struct V_836 * V_837 ,
unsigned long V_616 ,
void * V_197 ,
unsigned int V_831 ,
struct V_76 * V_69 )
{
return F_383 ( V_837 , V_616 , V_197 , V_831 ,
V_69 , & V_868 ) ;
}
static int F_385 ( struct V_836 * V_837 ,
unsigned long V_616 ,
const void * V_197 ,
unsigned int V_831 ,
struct V_76 * V_69 )
{
return F_383 ( V_837 , V_616 , ( void * ) V_197 , V_831 ,
V_69 , & V_869 ) ;
}
static int F_386 ( struct V_836 * V_837 ,
unsigned long V_616 ,
const void * V_870 ,
const void * V_871 ,
unsigned int V_831 ,
struct V_76 * V_69 )
{
struct V_1 * V_2 = F_363 ( V_837 ) ;
T_6 V_389 ;
struct V_385 * V_385 ;
char * V_872 ;
bool V_873 ;
if ( V_831 > 8 || ( V_831 & ( V_831 - 1 ) ) )
goto V_874;
V_389 = F_359 ( V_2 , V_616 , NULL ) ;
if ( V_389 == V_101 ||
( V_389 & V_383 ) == V_841 )
goto V_874;
if ( ( ( V_389 + V_831 - 1 ) & V_383 ) != ( V_389 & V_383 ) )
goto V_874;
V_385 = F_387 ( V_2 , V_389 >> V_107 ) ;
if ( F_388 ( V_385 ) )
goto V_874;
V_872 = F_389 ( V_385 ) ;
V_872 += F_390 ( V_389 ) ;
switch ( V_831 ) {
case 1 :
V_873 = F_391 ( T_14 , V_872 , V_870 , V_871 ) ;
break;
case 2 :
V_873 = F_391 ( V_875 , V_872 , V_870 , V_871 ) ;
break;
case 4 :
V_873 = F_391 ( T_1 , V_872 , V_870 , V_871 ) ;
break;
case 8 :
V_873 = F_392 ( V_872 , V_870 , V_871 ) ;
break;
default:
F_27 () ;
}
F_393 ( V_872 ) ;
F_394 ( V_385 ) ;
if ( ! V_873 )
return V_876 ;
F_395 ( V_2 , V_389 >> V_107 ) ;
F_375 ( V_2 , V_389 , V_871 , V_831 ) ;
return V_832 ;
V_874:
F_396 ( V_877 L_20 ) ;
return F_385 ( V_837 , V_616 , V_871 , V_831 , V_69 ) ;
}
static int F_397 ( struct V_1 * V_2 , void * V_878 )
{
int V_122 ;
if ( V_2 -> V_5 . V_879 . V_880 )
V_122 = F_352 ( V_2 , V_881 , V_2 -> V_5 . V_879 . V_882 ,
V_2 -> V_5 . V_879 . V_491 , V_878 ) ;
else
V_122 = F_349 ( V_2 , V_881 ,
V_2 -> V_5 . V_879 . V_882 , V_2 -> V_5 . V_879 . V_491 ,
V_878 ) ;
return V_122 ;
}
static int F_398 ( struct V_1 * V_2 , int V_491 ,
unsigned short V_882 , void * V_197 ,
unsigned int V_748 , bool V_880 )
{
V_2 -> V_5 . V_879 . V_882 = V_882 ;
V_2 -> V_5 . V_879 . V_880 = V_880 ;
V_2 -> V_5 . V_879 . V_748 = V_748 ;
V_2 -> V_5 . V_879 . V_491 = V_491 ;
if ( ! F_397 ( V_2 , V_2 -> V_5 . V_883 ) ) {
V_2 -> V_5 . V_879 . V_748 = 0 ;
return 1 ;
}
V_2 -> V_848 -> V_864 = V_884 ;
V_2 -> V_848 -> V_885 . V_886 = V_880 ? V_887 : V_888 ;
V_2 -> V_848 -> V_885 . V_491 = V_491 ;
V_2 -> V_848 -> V_885 . V_889 = V_890 * V_108 ;
V_2 -> V_848 -> V_885 . V_748 = V_748 ;
V_2 -> V_848 -> V_885 . V_882 = V_882 ;
return 0 ;
}
static int F_399 ( struct V_836 * V_837 ,
int V_491 , unsigned short V_882 , void * V_197 ,
unsigned int V_748 )
{
struct V_1 * V_2 = F_363 ( V_837 ) ;
int V_109 ;
if ( V_2 -> V_5 . V_879 . V_748 )
goto V_891;
V_109 = F_398 ( V_2 , V_491 , V_882 , V_197 , V_748 , true ) ;
if ( V_109 ) {
V_891:
memcpy ( V_197 , V_2 -> V_5 . V_883 , V_491 * V_748 ) ;
F_400 ( V_892 , V_882 , V_491 , V_748 , V_2 -> V_5 . V_883 ) ;
V_2 -> V_5 . V_879 . V_748 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_401 ( struct V_836 * V_837 ,
int V_491 , unsigned short V_882 ,
const void * V_197 , unsigned int V_748 )
{
struct V_1 * V_2 = F_363 ( V_837 ) ;
memcpy ( V_2 -> V_5 . V_883 , V_197 , V_491 * V_748 ) ;
F_400 ( V_893 , V_882 , V_491 , V_748 , V_2 -> V_5 . V_883 ) ;
return F_398 ( V_2 , V_491 , V_882 , ( void * ) V_197 , V_748 , false ) ;
}
static unsigned long F_402 ( struct V_1 * V_2 , int V_824 )
{
return V_74 -> F_402 ( V_2 , V_824 ) ;
}
static void F_403 ( struct V_836 * V_837 , V_177 V_81 )
{
F_404 ( F_363 ( V_837 ) , V_81 ) ;
}
int F_405 ( struct V_1 * V_2 )
{
if ( ! F_248 ( V_2 ) )
return V_832 ;
if ( V_74 -> V_583 () ) {
int V_24 = F_406 () ;
F_251 ( V_24 , V_2 -> V_5 . V_584 ) ;
F_407 ( V_2 -> V_5 . V_584 ,
F_246 , NULL , 1 ) ;
F_408 () ;
F_409 ( V_2 -> V_5 . V_584 ) ;
} else
F_247 () ;
return V_832 ;
}
int F_410 ( struct V_1 * V_2 )
{
V_74 -> V_75 ( V_2 ) ;
return F_405 ( V_2 ) ;
}
static void F_411 ( struct V_836 * V_837 )
{
F_405 ( F_363 ( V_837 ) ) ;
}
static int F_412 ( struct V_836 * V_837 , int V_90 ,
unsigned long * V_652 )
{
return F_101 ( F_363 ( V_837 ) , V_90 , V_652 ) ;
}
static int F_413 ( struct V_836 * V_837 , int V_90 ,
unsigned long V_23 )
{
return F_99 ( F_363 ( V_837 ) , V_90 , V_23 ) ;
}
static T_2 F_414 ( T_2 V_894 , T_1 V_895 )
{
return ( V_894 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_895 ;
}
static unsigned long F_415 ( struct V_836 * V_837 , int V_896 )
{
struct V_1 * V_2 = F_363 ( V_837 ) ;
unsigned long V_23 ;
switch ( V_896 ) {
case 0 :
V_23 = F_62 ( V_2 ) ;
break;
case 2 :
V_23 = V_2 -> V_5 . V_80 ;
break;
case 3 :
V_23 = F_60 ( V_2 ) ;
break;
case 4 :
V_23 = F_79 ( V_2 ) ;
break;
case 8 :
V_23 = F_92 ( V_2 ) ;
break;
default:
F_416 ( L_21 , V_263 , V_896 ) ;
return 0 ;
}
return V_23 ;
}
static int F_417 ( struct V_836 * V_837 , int V_896 , V_177 V_197 )
{
struct V_1 * V_2 = F_363 ( V_837 ) ;
int V_897 = 0 ;
switch ( V_896 ) {
case 0 :
V_897 = F_61 ( V_2 , F_414 ( F_62 ( V_2 ) , V_197 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_80 = V_197 ;
break;
case 3 :
V_897 = F_86 ( V_2 , V_197 ) ;
break;
case 4 :
V_897 = F_78 ( V_2 , F_414 ( F_79 ( V_2 ) , V_197 ) ) ;
break;
case 8 :
V_897 = F_89 ( V_2 , V_197 ) ;
break;
default:
F_416 ( L_21 , V_263 , V_896 ) ;
V_897 = - 1 ;
}
return V_897 ;
}
static int F_418 ( struct V_836 * V_837 )
{
return V_74 -> V_89 ( F_363 ( V_837 ) ) ;
}
static void F_419 ( struct V_836 * V_837 , struct V_898 * V_899 )
{
V_74 -> V_900 ( F_363 ( V_837 ) , V_899 ) ;
}
static void F_420 ( struct V_836 * V_837 , struct V_898 * V_899 )
{
V_74 -> V_901 ( F_363 ( V_837 ) , V_899 ) ;
}
static void F_421 ( struct V_836 * V_837 , struct V_898 * V_899 )
{
V_74 -> V_902 ( F_363 ( V_837 ) , V_899 ) ;
}
static void F_422 ( struct V_836 * V_837 , struct V_898 * V_899 )
{
V_74 -> V_903 ( F_363 ( V_837 ) , V_899 ) ;
}
static unsigned long F_423 (
struct V_836 * V_837 , int V_824 )
{
return F_402 ( F_363 ( V_837 ) , V_824 ) ;
}
static bool F_424 ( struct V_836 * V_837 , V_875 * V_904 ,
struct V_905 * V_906 , T_1 * V_907 ,
int V_824 )
{
struct V_822 V_823 ;
F_355 ( F_363 ( V_837 ) , & V_823 , V_824 ) ;
* V_904 = V_823 . V_904 ;
if ( V_823 . V_908 ) {
memset ( V_906 , 0 , sizeof( * V_906 ) ) ;
return false ;
}
if ( V_823 . V_909 )
V_823 . V_910 >>= 12 ;
F_425 ( V_906 , V_823 . V_910 ) ;
F_426 ( V_906 , ( unsigned long ) V_823 . V_231 ) ;
#ifdef F_63
if ( V_907 )
* V_907 = V_823 . V_231 >> 32 ;
#endif
V_906 -> type = V_823 . type ;
V_906 -> V_592 = V_823 . V_592 ;
V_906 -> V_911 = V_823 . V_911 ;
V_906 -> V_912 = V_823 . V_913 ;
V_906 -> V_914 = V_823 . V_914 ;
V_906 -> V_915 = V_823 . V_915 ;
V_906 -> V_916 = V_823 . V_184 ;
V_906 -> V_909 = V_823 . V_909 ;
return true ;
}
static void F_427 ( struct V_836 * V_837 , V_875 V_904 ,
struct V_905 * V_906 , T_1 V_907 ,
int V_824 )
{
struct V_1 * V_2 = F_363 ( V_837 ) ;
struct V_822 V_823 ;
V_823 . V_904 = V_904 ;
V_823 . V_231 = F_428 ( V_906 ) ;
#ifdef F_63
V_823 . V_231 |= ( ( T_2 ) V_907 ) << 32 ;
#endif
V_823 . V_910 = F_429 ( V_906 ) ;
if ( V_906 -> V_909 )
V_823 . V_910 = ( V_823 . V_910 << 12 ) | 0xfff ;
V_823 . type = V_906 -> type ;
V_823 . V_911 = V_906 -> V_911 ;
V_823 . V_184 = V_906 -> V_916 ;
V_823 . V_592 = V_906 -> V_592 ;
V_823 . V_915 = V_906 -> V_915 ;
V_823 . V_909 = V_906 -> V_909 ;
V_823 . V_914 = V_906 -> V_914 ;
V_823 . V_913 = V_906 -> V_912 ;
V_823 . V_908 = ! V_823 . V_913 ;
V_823 . V_917 = 0 ;
F_354 ( V_2 , & V_823 , V_824 ) ;
return;
}
static int F_430 ( struct V_836 * V_837 ,
T_1 V_918 , T_2 * V_463 )
{
struct V_33 V_22 ;
int V_122 ;
V_22 . V_148 = V_918 ;
V_22 . V_41 = false ;
V_122 = F_115 ( F_363 ( V_837 ) , & V_22 ) ;
if ( V_122 )
return V_122 ;
* V_463 = V_22 . V_39 ;
return 0 ;
}
static int F_431 ( struct V_836 * V_837 ,
T_1 V_918 , T_2 V_39 )
{
struct V_33 V_22 ;
V_22 . V_39 = V_39 ;
V_22 . V_148 = V_918 ;
V_22 . V_41 = false ;
return F_111 ( F_363 ( V_837 ) , & V_22 ) ;
}
static T_2 F_432 ( struct V_836 * V_837 )
{
struct V_1 * V_2 = F_363 ( V_837 ) ;
return V_2 -> V_5 . V_424 ;
}
static void F_433 ( struct V_836 * V_837 , T_2 V_424 )
{
struct V_1 * V_2 = F_363 ( V_837 ) ;
V_2 -> V_5 . V_424 = V_424 ;
}
static int F_434 ( struct V_836 * V_837 ,
T_1 V_919 )
{
return F_435 ( F_363 ( V_837 ) , V_919 ) ;
}
static int F_436 ( struct V_836 * V_837 ,
T_1 V_919 , T_2 * V_463 )
{
return F_104 ( F_363 ( V_837 ) , V_919 , V_463 ) ;
}
static void F_437 ( struct V_836 * V_837 )
{
F_363 ( V_837 ) -> V_5 . V_920 = 1 ;
}
static void F_438 ( struct V_836 * V_837 )
{
F_439 () ;
F_440 ( F_363 ( V_837 ) ) ;
F_441 () ;
}
static void F_442 ( struct V_836 * V_837 )
{
F_443 () ;
}
static int F_444 ( struct V_836 * V_837 ,
struct V_921 * V_922 ,
enum V_923 V_924 )
{
return V_74 -> V_925 ( F_363 ( V_837 ) , V_922 , V_924 ) ;
}
static void F_445 ( struct V_836 * V_837 ,
T_1 * V_926 , T_1 * V_927 , T_1 * V_202 , T_1 * V_210 )
{
V_692 ( F_363 ( V_837 ) , V_926 , V_927 , V_202 , V_210 ) ;
}
static V_177 F_446 ( struct V_836 * V_837 , unsigned V_928 )
{
return F_103 ( F_363 ( V_837 ) , V_928 ) ;
}
static void F_447 ( struct V_836 * V_837 , unsigned V_928 , V_177 V_197 )
{
F_105 ( F_363 ( V_837 ) , V_928 , V_197 ) ;
}
static void F_448 ( struct V_836 * V_837 , bool V_629 )
{
V_74 -> V_645 ( F_363 ( V_837 ) , V_629 ) ;
}
static void F_449 ( struct V_1 * V_2 , T_1 V_29 )
{
T_1 V_929 = V_74 -> V_625 ( V_2 ) ;
if ( V_929 & V_29 )
V_29 = 0 ;
if ( F_170 ( V_929 || V_29 ) ) {
V_74 -> V_644 ( V_2 , V_29 ) ;
if ( ! V_29 )
F_32 ( V_68 , V_2 ) ;
}
}
static bool F_450 ( struct V_1 * V_2 )
{
struct V_836 * V_837 = & V_2 -> V_5 . V_930 ;
if ( V_837 -> V_69 . V_42 == V_43 )
return F_40 ( V_2 , & V_837 -> V_69 ) ;
if ( V_837 -> V_69 . V_931 )
F_39 ( V_2 , V_837 -> V_69 . V_42 ,
V_837 -> V_69 . V_63 ) ;
else
F_34 ( V_2 , V_837 -> V_69 . V_42 ) ;
return false ;
}
static void F_451 ( struct V_1 * V_2 )
{
struct V_836 * V_837 = & V_2 -> V_5 . V_930 ;
int V_135 , V_136 ;
V_74 -> V_137 ( V_2 , & V_135 , & V_136 ) ;
V_837 -> V_932 = F_452 ( V_2 ) ;
V_837 -> V_933 = F_453 ( V_2 ) ;
V_837 -> V_330 = ( ! F_33 ( V_2 ) ) ? V_934 :
( V_837 -> V_932 & V_935 ) ? V_936 :
( V_136 && F_57 ( V_2 ) ) ? V_859 :
V_135 ? V_937 :
V_938 ;
F_187 ( V_939 != V_940 ) ;
F_187 ( V_647 != V_941 ) ;
F_187 ( V_637 != V_942 ) ;
V_837 -> V_943 = V_2 -> V_5 . V_636 ;
F_454 ( V_837 ) ;
V_2 -> V_5 . V_944 = false ;
}
int F_455 ( struct V_1 * V_2 , int V_596 , int V_945 )
{
struct V_836 * V_837 = & V_2 -> V_5 . V_930 ;
int V_109 ;
F_451 ( V_2 ) ;
V_837 -> V_946 = 2 ;
V_837 -> V_947 = 2 ;
V_837 -> V_948 = V_837 -> V_933 + V_945 ;
V_109 = F_456 ( V_837 , V_596 ) ;
if ( V_109 != V_832 )
return V_949 ;
V_837 -> V_933 = V_837 -> V_948 ;
F_457 ( V_2 , V_837 -> V_933 ) ;
F_458 ( V_2 , V_837 -> V_932 ) ;
if ( V_596 == V_52 )
V_2 -> V_5 . V_628 = 0 ;
else
V_2 -> V_5 . V_622 . V_70 = false ;
return V_950 ;
}
static int F_459 ( struct V_1 * V_2 )
{
int V_122 = V_950 ;
++ V_2 -> V_78 . V_951 ;
F_460 ( V_2 ) ;
if ( ! F_461 ( V_2 ) && V_74 -> V_89 ( V_2 ) == 0 ) {
V_2 -> V_848 -> V_864 = V_952 ;
V_2 -> V_848 -> V_953 . V_954 = V_955 ;
V_2 -> V_848 -> V_953 . V_956 = 0 ;
V_122 = V_949 ;
}
F_34 ( V_2 , V_92 ) ;
return V_122 ;
}
static bool F_462 ( struct V_1 * V_2 , T_16 V_80 ,
bool V_957 ,
int V_958 )
{
T_6 V_389 = V_80 ;
T_17 V_959 ;
if ( V_958 & V_960 )
return false ;
if ( ! V_2 -> V_5 . V_85 . V_961 ) {
V_389 = F_359 ( V_2 , V_80 , NULL ) ;
if ( V_389 == V_101 )
return true ;
}
V_959 = F_463 ( V_2 -> V_140 , F_50 ( V_389 ) ) ;
if ( F_464 ( V_959 ) )
return false ;
F_465 ( V_959 ) ;
if ( V_2 -> V_5 . V_85 . V_961 ) {
unsigned int V_962 ;
F_160 ( & V_2 -> V_140 -> V_963 ) ;
V_962 = V_2 -> V_140 -> V_5 . V_962 ;
F_161 ( & V_2 -> V_140 -> V_963 ) ;
if ( V_962 )
F_466 ( V_2 -> V_140 , F_50 ( V_389 ) ) ;
return true ;
}
F_466 ( V_2 -> V_140 , F_50 ( V_389 ) ) ;
return ! V_957 ;
}
static bool F_467 ( struct V_836 * V_837 ,
unsigned long V_80 , int V_958 )
{
struct V_1 * V_2 = F_363 ( V_837 ) ;
unsigned long V_964 , V_965 , V_389 = V_80 ;
V_964 = V_2 -> V_5 . V_964 ;
V_965 = V_2 -> V_5 . V_965 ;
V_2 -> V_5 . V_964 = V_2 -> V_5 . V_965 = 0 ;
if ( ! ( V_958 & V_966 ) )
return false ;
if ( F_468 ( V_837 ) )
return false ;
if ( V_837 -> V_933 == V_964 && V_965 == V_80 )
return false ;
V_2 -> V_5 . V_964 = V_837 -> V_933 ;
V_2 -> V_5 . V_965 = V_80 ;
if ( ! V_2 -> V_5 . V_85 . V_961 )
V_389 = F_359 ( V_2 , V_80 , NULL ) ;
F_466 ( V_2 -> V_140 , F_50 ( V_389 ) ) ;
return true ;
}
static void F_469 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_636 & V_647 ) ) {
F_470 ( V_2 -> V_299 , V_2 -> V_5 . V_424 , false ) ;
F_32 ( V_68 , V_2 ) ;
}
F_66 ( V_2 ) ;
}
static void F_471 ( struct V_1 * V_2 , unsigned V_943 )
{
unsigned V_121 = V_2 -> V_5 . V_636 ^ V_943 ;
V_2 -> V_5 . V_636 = V_943 ;
if ( V_121 & V_647 )
F_469 ( V_2 ) ;
}
static int F_472 ( unsigned long V_616 , T_1 type , T_1 V_189 ,
unsigned long * V_184 )
{
T_1 V_188 = 0 ;
int V_3 ;
T_1 V_967 , V_968 ;
V_967 = V_189 ;
V_968 = V_189 >> 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ , V_967 >>= 2 , V_968 >>= 4 )
if ( ( V_967 & 3 ) && ( V_968 & 15 ) == type && V_184 [ V_3 ] == V_616 )
V_188 |= ( 1 << V_3 ) ;
return V_188 ;
}
static void F_473 ( struct V_1 * V_2 , unsigned long V_969 , int * V_122 )
{
struct V_970 * V_970 = V_2 -> V_848 ;
if ( F_170 ( V_969 & V_971 ) ) {
if ( V_2 -> V_180 & V_972 ) {
V_970 -> V_973 . V_5 . V_188 = V_974 | V_195 |
V_196 ;
V_970 -> V_973 . V_5 . V_975 = V_2 -> V_5 . V_976 ;
V_970 -> V_973 . V_5 . V_69 = V_54 ;
V_970 -> V_864 = V_977 ;
* V_122 = V_978 ;
} else {
V_2 -> V_5 . V_930 . V_932 &= ~ V_971 ;
V_2 -> V_5 . V_188 &= ~ 15 ;
V_2 -> V_5 . V_188 |= V_974 | V_196 ;
F_34 ( V_2 , V_54 ) ;
}
}
}
static bool F_474 ( struct V_1 * V_2 , int * V_122 )
{
if ( F_170 ( V_2 -> V_180 & V_181 ) &&
( V_2 -> V_5 . V_190 & V_193 ) ) {
struct V_970 * V_970 = V_2 -> V_848 ;
unsigned long V_933 = F_475 ( V_2 ) ;
T_1 V_188 = F_472 ( V_933 , 0 ,
V_2 -> V_5 . V_190 ,
V_2 -> V_5 . V_183 ) ;
if ( V_188 != 0 ) {
V_970 -> V_973 . V_5 . V_188 = V_188 | V_195 | V_196 ;
V_970 -> V_973 . V_5 . V_975 = V_933 ;
V_970 -> V_973 . V_5 . V_69 = V_54 ;
V_970 -> V_864 = V_977 ;
* V_122 = V_978 ;
return true ;
}
}
if ( F_170 ( V_2 -> V_5 . V_189 & V_193 ) &&
! ( F_452 ( V_2 ) & V_979 ) ) {
unsigned long V_933 = F_475 ( V_2 ) ;
T_1 V_188 = F_472 ( V_933 , 0 ,
V_2 -> V_5 . V_189 ,
V_2 -> V_5 . V_184 ) ;
if ( V_188 != 0 ) {
V_2 -> V_5 . V_188 &= ~ 15 ;
V_2 -> V_5 . V_188 |= V_188 | V_196 ;
F_34 ( V_2 , V_54 ) ;
* V_122 = V_950 ;
return true ;
}
}
return false ;
}
int F_476 ( struct V_1 * V_2 ,
unsigned long V_80 ,
int V_958 ,
void * V_980 ,
int V_981 )
{
int V_122 ;
struct V_836 * V_837 = & V_2 -> V_5 . V_930 ;
bool V_489 = true ;
bool V_982 = V_2 -> V_5 . V_957 ;
V_2 -> V_5 . V_957 = false ;
F_477 ( V_2 ) ;
if ( ! ( V_958 & V_983 ) ) {
F_451 ( V_2 ) ;
if ( F_474 ( V_2 , & V_122 ) )
return V_122 ;
V_837 -> V_984 = 0 ;
V_837 -> V_985 = false ;
V_837 -> V_69 . V_42 = - 1 ;
V_837 -> V_986 = false ;
V_837 -> V_987 = V_958 & V_988 ;
V_122 = F_478 ( V_837 , V_980 , V_981 ) ;
F_479 ( V_2 ) ;
++ V_2 -> V_78 . V_989 ;
if ( V_122 != V_990 ) {
if ( V_958 & V_988 )
return V_949 ;
if ( F_462 ( V_2 , V_80 , V_982 ,
V_958 ) )
return V_950 ;
if ( V_958 & V_991 )
return V_949 ;
return F_459 ( V_2 ) ;
}
}
if ( V_958 & V_991 ) {
F_457 ( V_2 , V_837 -> V_948 ) ;
if ( V_837 -> V_932 & V_979 )
F_458 ( V_2 , V_837 -> V_932 & ~ V_979 ) ;
return V_950 ;
}
if ( F_467 ( V_837 , V_80 , V_958 ) )
return V_950 ;
if ( V_2 -> V_5 . V_944 ) {
V_2 -> V_5 . V_944 = false ;
F_480 ( V_837 ) ;
}
V_992:
V_122 = F_481 ( V_837 ) ;
if ( V_122 == V_993 )
return V_950 ;
if ( V_122 == V_994 ) {
if ( F_462 ( V_2 , V_80 , V_982 ,
V_958 ) )
return V_950 ;
return F_459 ( V_2 ) ;
}
if ( V_837 -> V_985 ) {
V_122 = V_950 ;
if ( F_450 ( V_2 ) )
return V_122 ;
} else if ( V_2 -> V_5 . V_879 . V_748 ) {
if ( ! V_2 -> V_5 . V_879 . V_880 ) {
V_2 -> V_5 . V_879 . V_748 = 0 ;
} else {
V_489 = false ;
V_2 -> V_5 . V_995 = V_996 ;
}
V_122 = V_978 ;
} else if ( V_2 -> V_860 ) {
if ( ! V_2 -> V_863 )
V_489 = false ;
V_122 = V_978 ;
V_2 -> V_5 . V_995 = V_997 ;
} else if ( V_122 == V_998 )
goto V_992;
else
V_122 = V_950 ;
if ( V_489 ) {
unsigned long V_969 = V_74 -> V_999 ( V_2 ) ;
F_449 ( V_2 , V_837 -> V_984 ) ;
V_2 -> V_5 . V_1000 = false ;
if ( V_2 -> V_5 . V_636 != V_837 -> V_943 )
F_471 ( V_2 , V_837 -> V_943 ) ;
F_457 ( V_2 , V_837 -> V_933 ) ;
if ( V_122 == V_950 )
F_473 ( V_2 , V_969 , & V_122 ) ;
if ( ! V_837 -> V_985 ||
F_29 ( V_837 -> V_69 . V_42 ) == V_57 )
F_482 ( V_2 , V_837 -> V_932 ) ;
if ( F_170 ( ( V_837 -> V_932 & ~ V_969 ) & V_1001 ) )
F_32 ( V_68 , V_2 ) ;
} else
V_2 -> V_5 . V_1000 = true ;
return V_122 ;
}
int F_483 ( struct V_1 * V_2 , int V_491 , unsigned short V_882 )
{
unsigned long V_197 = F_103 ( V_2 , V_204 ) ;
int V_109 = F_401 ( & V_2 -> V_5 . V_930 ,
V_491 , V_882 , & V_197 , 1 ) ;
V_2 -> V_5 . V_879 . V_748 = 0 ;
return V_109 ;
}
static int F_484 ( unsigned int V_24 )
{
F_485 ( V_344 , 0 ) ;
return 0 ;
}
static void F_486 ( void * V_39 )
{
struct V_1002 * V_1003 = V_39 ;
unsigned long V_264 = 0 ;
if ( V_39 )
V_264 = V_1003 -> V_871 ;
else if ( ! F_243 ( V_1004 ) )
V_264 = F_487 ( F_488 () ) ;
if ( ! V_264 )
V_264 = V_273 ;
F_485 ( V_344 , V_264 ) ;
}
static int F_489 ( struct V_1005 * V_1006 , unsigned long V_197 ,
void * V_39 )
{
struct V_1002 * V_1003 = V_39 ;
struct V_140 * V_140 ;
struct V_1 * V_2 ;
int V_3 , V_1007 = 0 ;
if ( V_197 == V_1008 && V_1003 -> V_870 > V_1003 -> V_871 )
return 0 ;
if ( V_197 == V_1009 && V_1003 -> V_870 < V_1003 -> V_871 )
return 0 ;
F_252 ( V_1003 -> V_24 , F_486 , V_1003 , 1 ) ;
F_160 ( & V_1010 ) ;
F_490 (kvm, &vm_list, vm_list) {
F_179 (i, vcpu, kvm) {
if ( V_2 -> V_24 != V_1003 -> V_24 )
continue;
F_32 ( V_338 , V_2 ) ;
if ( V_2 -> V_24 != F_10 () )
V_1007 = 1 ;
}
}
F_161 ( & V_1010 ) ;
if ( V_1003 -> V_870 < V_1003 -> V_871 && V_1007 ) {
F_252 ( V_1003 -> V_24 , F_486 , V_1003 , 1 ) ;
}
return 0 ;
}
static int F_491 ( unsigned int V_24 )
{
F_486 ( NULL ) ;
return 0 ;
}
static void F_492 ( void )
{
V_1011 = V_273 ;
if ( ! F_243 ( V_1004 ) ) {
#ifdef F_493
struct V_1012 V_1013 ;
int V_24 ;
memset ( & V_1013 , 0 , sizeof( V_1013 ) ) ;
V_24 = F_406 () ;
F_494 ( & V_1013 , V_24 ) ;
if ( V_1013 . V_1014 . V_1015 )
V_1011 = V_1013 . V_1014 . V_1015 ;
F_408 () ;
#endif
F_495 ( & V_1016 ,
V_1017 ) ;
}
F_132 ( L_22 , V_1011 ) ;
F_496 ( V_1018 , L_23 ,
F_491 , F_484 ) ;
}
int F_497 ( void )
{
return F_182 ( V_1019 ) != NULL ;
}
static int F_498 ( void )
{
int V_1020 = 3 ;
if ( F_182 ( V_1019 ) )
V_1020 = V_74 -> V_89 ( F_182 ( V_1019 ) ) ;
return V_1020 != 0 ;
}
static unsigned long F_499 ( void )
{
unsigned long V_1021 = 0 ;
if ( F_182 ( V_1019 ) )
V_1021 = F_453 ( F_182 ( V_1019 ) ) ;
return V_1021 ;
}
void F_500 ( struct V_1 * V_2 )
{
F_485 ( V_1019 , V_2 ) ;
}
void F_501 ( struct V_1 * V_2 )
{
F_485 ( V_1019 , NULL ) ;
}
static void F_502 ( void )
{
T_2 V_29 ;
int V_1022 = V_1023 . V_1024 ;
V_29 = F_503 ( V_1022 , 51 ) ;
V_29 |= 0x3ull << 62 ;
V_29 |= 1ull ;
#ifdef F_63
if ( V_1022 == 52 )
V_29 &= ~ 1ull ;
#endif
F_504 ( V_29 ) ;
}
static void F_505 ( struct V_357 * V_358 )
{
struct V_140 * V_140 ;
struct V_1 * V_2 ;
int V_3 ;
F_160 ( & V_1010 ) ;
F_490 (kvm, &vm_list, vm_list)
F_179 (i, vcpu, kvm)
F_32 ( V_298 , V_2 ) ;
F_174 ( & V_336 , 0 ) ;
F_161 ( & V_1010 ) ;
}
static int F_506 ( struct V_1005 * V_1006 , unsigned long V_1025 ,
void * V_1026 )
{
struct V_227 * V_293 = & V_227 ;
struct V_225 * V_226 = V_1026 ;
F_117 ( V_226 ) ;
if ( V_293 -> clock . V_234 != V_297 &&
F_143 ( & V_336 ) != 0 )
F_507 ( V_1027 , & V_1028 ) ;
return 0 ;
}
int F_508 ( void * V_1029 )
{
int V_122 ;
struct V_74 * V_851 = V_1029 ;
if ( V_74 ) {
F_12 ( V_27 L_24 ) ;
V_122 = - V_600 ;
goto V_114;
}
if ( ! V_851 -> V_1030 () ) {
F_12 ( V_27 L_25 ) ;
V_122 = - V_1031 ;
goto V_114;
}
if ( V_851 -> V_1032 () ) {
F_12 ( V_27 L_26 ) ;
V_122 = - V_1031 ;
goto V_114;
}
V_122 = - V_387 ;
V_26 = F_509 ( struct V_11 ) ;
if ( ! V_26 ) {
F_12 ( V_27 L_27 ) ;
goto V_114;
}
V_122 = F_510 () ;
if ( V_122 )
goto V_1033;
F_502 () ;
V_74 = V_851 ;
F_511 ( V_1034 , V_1035 ,
V_1036 , V_1037 , 0 ,
V_115 ) ;
F_492 () ;
F_512 ( & V_1038 ) ;
if ( F_243 ( V_555 ) )
V_147 = F_513 ( V_145 ) ;
F_514 () ;
#ifdef F_63
F_515 ( & V_1039 ) ;
#endif
return 0 ;
V_1033:
F_516 ( V_26 ) ;
V_114:
return V_122 ;
}
void F_517 ( void )
{
F_518 ( & V_1038 ) ;
if ( ! F_243 ( V_1004 ) )
F_519 ( & V_1016 ,
V_1017 ) ;
F_520 ( V_1018 ) ;
#ifdef F_63
F_521 ( & V_1039 ) ;
#endif
V_74 = NULL ;
F_522 () ;
F_516 ( V_26 ) ;
}
int F_523 ( struct V_1 * V_2 )
{
++ V_2 -> V_78 . V_1040 ;
if ( F_90 ( V_2 ) ) {
V_2 -> V_5 . V_1041 = V_1042 ;
return 1 ;
} else {
V_2 -> V_848 -> V_864 = V_1043 ;
return 0 ;
}
}
int F_524 ( struct V_1 * V_2 )
{
V_74 -> V_75 ( V_2 ) ;
return F_523 ( V_2 ) ;
}
static void F_525 ( struct V_140 * V_140 , unsigned long V_15 , int V_1044 )
{
struct V_1045 V_1046 ;
V_1046 . V_1047 = 0 ;
V_1046 . V_1048 = 0 ;
V_1046 . V_1049 = V_1044 ;
V_1046 . V_1050 = false ;
V_1046 . V_1051 = V_1052 ;
F_526 ( V_140 , NULL , & V_1046 , NULL ) ;
}
void F_527 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_593 = false ;
V_74 -> V_1053 ( V_2 ) ;
}
int F_528 ( struct V_1 * V_2 )
{
unsigned long V_18 , V_1054 , V_1055 , V_1056 , V_1057 , V_109 ;
int V_1058 , V_122 = 1 ;
V_74 -> V_75 ( V_2 ) ;
if ( F_529 ( V_2 -> V_140 ) )
return F_530 ( V_2 ) ;
V_18 = F_103 ( V_2 , V_204 ) ;
V_1054 = F_103 ( V_2 , V_1059 ) ;
V_1055 = F_103 ( V_2 , V_203 ) ;
V_1056 = F_103 ( V_2 , V_205 ) ;
V_1057 = F_103 ( V_2 , V_1060 ) ;
F_531 ( V_18 , V_1054 , V_1055 , V_1056 , V_1057 ) ;
V_1058 = F_532 ( V_2 ) ;
if ( ! V_1058 ) {
V_18 &= 0xFFFFFFFF ;
V_1054 &= 0xFFFFFFFF ;
V_1055 &= 0xFFFFFFFF ;
V_1056 &= 0xFFFFFFFF ;
V_1057 &= 0xFFFFFFFF ;
}
if ( V_74 -> V_89 ( V_2 ) != 0 ) {
V_109 = - V_1061 ;
goto V_114;
}
switch ( V_18 ) {
case V_1062 :
V_109 = 0 ;
break;
case V_1063 :
F_525 ( V_2 -> V_140 , V_1054 , V_1055 ) ;
V_109 = 0 ;
break;
default:
V_109 = - V_1064 ;
break;
}
V_114:
if ( ! V_1058 )
V_109 = ( T_1 ) V_109 ;
F_105 ( V_2 , V_204 , V_109 ) ;
++ V_2 -> V_78 . V_1065 ;
return V_122 ;
}
static int F_533 ( struct V_836 * V_837 )
{
struct V_1 * V_2 = F_363 ( V_837 ) ;
char V_1066 [ 3 ] ;
unsigned long V_1067 = F_453 ( V_2 ) ;
V_74 -> V_1068 ( V_2 , V_1066 ) ;
return F_385 ( V_837 , V_1067 , V_1066 , 3 , NULL ) ;
}
static int F_534 ( struct V_1 * V_2 )
{
return V_2 -> V_848 -> V_1069 &&
F_166 ( ! F_272 ( V_2 -> V_140 ) ) ;
}
static void F_535 ( struct V_1 * V_2 )
{
struct V_970 * V_970 = V_2 -> V_848 ;
V_970 -> V_1070 = ( F_452 ( V_2 ) & V_1001 ) != 0 ;
V_970 -> V_15 = F_281 ( V_2 ) ? V_1071 : 0 ;
V_970 -> V_178 = F_92 ( V_2 ) ;
V_970 -> V_32 = F_21 ( V_2 ) ;
V_970 -> V_1072 =
F_272 ( V_2 -> V_140 ) ||
F_265 ( V_2 ) ;
}
static void F_262 ( struct V_1 * V_2 )
{
int V_1073 , V_1074 ;
if ( ! V_74 -> F_262 )
return;
if ( ! F_90 ( V_2 ) )
return;
if ( V_2 -> V_5 . V_593 )
return;
if ( ! V_2 -> V_5 . V_646 -> V_701 )
V_1073 = F_536 ( V_2 ) ;
else
V_1073 = - 1 ;
if ( V_1073 != - 1 )
V_1073 >>= 4 ;
V_1074 = F_93 ( V_2 ) ;
V_74 -> F_262 ( V_2 , V_1074 , V_1073 ) ;
}
static int F_537 ( struct V_1 * V_2 , bool V_1075 )
{
int V_122 ;
if ( V_2 -> V_5 . V_69 . V_70 ) {
F_538 ( V_2 -> V_5 . V_69 . V_18 ,
V_2 -> V_5 . V_69 . V_72 ,
V_2 -> V_5 . V_69 . V_63 ) ;
if ( F_29 ( V_2 -> V_5 . V_69 . V_18 ) == V_61 )
F_482 ( V_2 , F_452 ( V_2 ) |
V_979 ) ;
if ( V_2 -> V_5 . V_69 . V_18 == V_54 &&
( V_2 -> V_5 . V_189 & V_1076 ) ) {
V_2 -> V_5 . V_189 &= ~ V_1076 ;
F_96 ( V_2 ) ;
}
V_74 -> V_1077 ( V_2 , V_2 -> V_5 . V_69 . V_18 ,
V_2 -> V_5 . V_69 . V_72 ,
V_2 -> V_5 . V_69 . V_63 ,
V_2 -> V_5 . V_69 . V_64 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_627 ) {
V_74 -> V_1078 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_622 . V_70 ) {
V_74 -> V_1079 ( V_2 ) ;
return 0 ;
}
if ( F_461 ( V_2 ) && V_74 -> V_1080 ) {
V_122 = V_74 -> V_1080 ( V_2 , V_1075 ) ;
if ( V_122 != 0 )
return V_122 ;
}
if ( V_2 -> V_5 . V_634 && ! F_281 ( V_2 ) ) {
V_2 -> V_5 . V_634 = false ;
F_539 ( V_2 ) ;
} else if ( V_2 -> V_5 . V_628 && V_74 -> V_1081 ( V_2 ) ) {
-- V_2 -> V_5 . V_628 ;
V_2 -> V_5 . V_627 = true ;
V_74 -> V_1078 ( V_2 ) ;
} else if ( F_540 ( V_2 ) ) {
if ( F_461 ( V_2 ) && V_74 -> V_1080 ) {
V_122 = V_74 -> V_1080 ( V_2 , V_1075 ) ;
if ( V_122 != 0 )
return V_122 ;
}
if ( V_74 -> V_1082 ( V_2 ) ) {
F_271 ( V_2 , F_541 ( V_2 ) ,
false ) ;
V_74 -> V_1079 ( V_2 ) ;
}
}
return 0 ;
}
static void F_279 ( struct V_1 * V_2 )
{
unsigned V_910 = 2 ;
if ( V_74 -> V_630 ( V_2 ) || V_2 -> V_5 . V_627 )
V_910 = 1 ;
V_2 -> V_5 . V_628 += F_542 ( & V_2 -> V_5 . V_86 , 0 ) ;
V_2 -> V_5 . V_628 = F_347 ( V_2 -> V_5 . V_628 , V_910 ) ;
F_32 ( V_68 , V_2 ) ;
}
static T_1 F_543 ( struct V_822 * V_824 )
{
T_1 V_15 = 0 ;
V_15 |= V_824 -> V_909 << 23 ;
V_15 |= V_824 -> V_184 << 22 ;
V_15 |= V_824 -> V_915 << 21 ;
V_15 |= V_824 -> V_914 << 20 ;
V_15 |= V_824 -> V_913 << 15 ;
V_15 |= V_824 -> V_911 << 13 ;
V_15 |= V_824 -> V_592 << 12 ;
V_15 |= V_824 -> type << 8 ;
return V_15 ;
}
static void F_544 ( struct V_1 * V_2 , char * V_1083 , int V_490 )
{
struct V_822 V_824 ;
int V_95 ;
F_355 ( V_2 , & V_824 , V_490 ) ;
F_545 ( T_1 , V_1083 , 0x7fa8 + V_490 * 4 , V_824 . V_904 ) ;
if ( V_490 < 3 )
V_95 = 0x7f84 + V_490 * 12 ;
else
V_95 = 0x7f2c + ( V_490 - 3 ) * 12 ;
F_545 ( T_1 , V_1083 , V_95 + 8 , V_824 . V_231 ) ;
F_545 ( T_1 , V_1083 , V_95 + 4 , V_824 . V_910 ) ;
F_545 ( T_1 , V_1083 , V_95 , F_543 ( & V_824 ) ) ;
}
static void F_546 ( struct V_1 * V_2 , char * V_1083 , int V_490 )
{
struct V_822 V_824 ;
int V_95 ;
V_875 V_15 ;
F_355 ( V_2 , & V_824 , V_490 ) ;
V_95 = 0x7e00 + V_490 * 16 ;
V_15 = F_543 ( & V_824 ) >> 8 ;
F_545 ( V_875 , V_1083 , V_95 , V_824 . V_904 ) ;
F_545 ( V_875 , V_1083 , V_95 + 2 , V_15 ) ;
F_545 ( T_1 , V_1083 , V_95 + 4 , V_824 . V_910 ) ;
F_545 ( T_2 , V_1083 , V_95 + 8 , V_824 . V_231 ) ;
}
static void F_547 ( struct V_1 * V_2 , char * V_1083 )
{
struct V_898 V_899 ;
struct V_822 V_824 ;
unsigned long V_197 ;
int V_3 ;
F_545 ( T_1 , V_1083 , 0x7ffc , F_62 ( V_2 ) ) ;
F_545 ( T_1 , V_1083 , 0x7ff8 , F_60 ( V_2 ) ) ;
F_545 ( T_1 , V_1083 , 0x7ff4 , F_452 ( V_2 ) ) ;
F_545 ( T_1 , V_1083 , 0x7ff0 , F_453 ( V_2 ) ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
F_545 ( T_1 , V_1083 , 0x7fd0 + V_3 * 4 , F_103 ( V_2 , V_3 ) ) ;
F_101 ( V_2 , 6 , & V_197 ) ;
F_545 ( T_1 , V_1083 , 0x7fcc , ( T_1 ) V_197 ) ;
F_101 ( V_2 , 7 , & V_197 ) ;
F_545 ( T_1 , V_1083 , 0x7fc8 , ( T_1 ) V_197 ) ;
F_355 ( V_2 , & V_824 , V_1084 ) ;
F_545 ( T_1 , V_1083 , 0x7fc4 , V_824 . V_904 ) ;
F_545 ( T_1 , V_1083 , 0x7f64 , V_824 . V_231 ) ;
F_545 ( T_1 , V_1083 , 0x7f60 , V_824 . V_910 ) ;
F_545 ( T_1 , V_1083 , 0x7f5c , F_543 ( & V_824 ) ) ;
F_355 ( V_2 , & V_824 , V_1085 ) ;
F_545 ( T_1 , V_1083 , 0x7fc0 , V_824 . V_904 ) ;
F_545 ( T_1 , V_1083 , 0x7f80 , V_824 . V_231 ) ;
F_545 ( T_1 , V_1083 , 0x7f7c , V_824 . V_910 ) ;
F_545 ( T_1 , V_1083 , 0x7f78 , F_543 ( & V_824 ) ) ;
V_74 -> V_900 ( V_2 , & V_899 ) ;
F_545 ( T_1 , V_1083 , 0x7f74 , V_899 . V_81 ) ;
F_545 ( T_1 , V_1083 , 0x7f70 , V_899 . V_491 ) ;
V_74 -> V_901 ( V_2 , & V_899 ) ;
F_545 ( T_1 , V_1083 , 0x7f58 , V_899 . V_81 ) ;
F_545 ( T_1 , V_1083 , 0x7f54 , V_899 . V_491 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_544 ( V_2 , V_1083 , V_3 ) ;
F_545 ( T_1 , V_1083 , 0x7f14 , F_79 ( V_2 ) ) ;
F_545 ( T_1 , V_1083 , 0x7efc , 0x00020000 ) ;
F_545 ( T_1 , V_1083 , 0x7ef8 , V_2 -> V_5 . V_424 ) ;
}
static void F_548 ( struct V_1 * V_2 , char * V_1083 )
{
#ifdef F_63
struct V_898 V_899 ;
struct V_822 V_824 ;
unsigned long V_197 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ )
F_545 ( T_2 , V_1083 , 0x7ff8 - V_3 * 8 , F_103 ( V_2 , V_3 ) ) ;
F_545 ( T_2 , V_1083 , 0x7f78 , F_453 ( V_2 ) ) ;
F_545 ( T_1 , V_1083 , 0x7f70 , F_452 ( V_2 ) ) ;
F_101 ( V_2 , 6 , & V_197 ) ;
F_545 ( T_2 , V_1083 , 0x7f68 , V_197 ) ;
F_101 ( V_2 , 7 , & V_197 ) ;
F_545 ( T_2 , V_1083 , 0x7f60 , V_197 ) ;
F_545 ( T_2 , V_1083 , 0x7f58 , F_62 ( V_2 ) ) ;
F_545 ( T_2 , V_1083 , 0x7f50 , F_60 ( V_2 ) ) ;
F_545 ( T_2 , V_1083 , 0x7f48 , F_79 ( V_2 ) ) ;
F_545 ( T_1 , V_1083 , 0x7f00 , V_2 -> V_5 . V_424 ) ;
F_545 ( T_1 , V_1083 , 0x7efc , 0x00020064 ) ;
F_545 ( T_2 , V_1083 , 0x7ed0 , V_2 -> V_5 . V_133 ) ;
F_355 ( V_2 , & V_824 , V_1084 ) ;
F_545 ( V_875 , V_1083 , 0x7e90 , V_824 . V_904 ) ;
F_545 ( V_875 , V_1083 , 0x7e92 , F_543 ( & V_824 ) >> 8 ) ;
F_545 ( T_1 , V_1083 , 0x7e94 , V_824 . V_910 ) ;
F_545 ( T_2 , V_1083 , 0x7e98 , V_824 . V_231 ) ;
V_74 -> V_901 ( V_2 , & V_899 ) ;
F_545 ( T_1 , V_1083 , 0x7e84 , V_899 . V_491 ) ;
F_545 ( T_2 , V_1083 , 0x7e88 , V_899 . V_81 ) ;
F_355 ( V_2 , & V_824 , V_1085 ) ;
F_545 ( V_875 , V_1083 , 0x7e70 , V_824 . V_904 ) ;
F_545 ( V_875 , V_1083 , 0x7e72 , F_543 ( & V_824 ) >> 8 ) ;
F_545 ( T_1 , V_1083 , 0x7e74 , V_824 . V_910 ) ;
F_545 ( T_2 , V_1083 , 0x7e78 , V_824 . V_231 ) ;
V_74 -> V_900 ( V_2 , & V_899 ) ;
F_545 ( T_1 , V_1083 , 0x7e64 , V_899 . V_491 ) ;
F_545 ( T_2 , V_1083 , 0x7e68 , V_899 . V_81 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_546 ( V_2 , V_1083 , V_3 ) ;
#else
F_549 ( 1 ) ;
#endif
}
static void F_539 ( struct V_1 * V_2 )
{
struct V_822 V_1086 , V_1087 ;
struct V_898 V_899 ;
char V_1083 [ 512 ] ;
T_1 V_123 ;
F_470 ( V_2 -> V_299 , V_2 -> V_5 . V_424 , true ) ;
V_2 -> V_5 . V_636 |= V_647 ;
memset ( V_1083 , 0 , 512 ) ;
if ( F_550 ( V_2 ) )
F_548 ( V_2 , V_1083 ) ;
else
F_547 ( V_2 , V_1083 ) ;
F_207 ( V_2 , V_2 -> V_5 . V_424 + 0xfe00 , V_1083 , sizeof( V_1083 ) ) ;
if ( V_74 -> V_630 ( V_2 ) )
V_2 -> V_5 . V_636 |= V_637 ;
else
V_74 -> V_645 ( V_2 , true ) ;
F_458 ( V_2 , V_1088 ) ;
F_457 ( V_2 , 0x8000 ) ;
V_123 = V_2 -> V_5 . V_123 & ~ ( V_132 | V_1089 | V_1090 | V_126 ) ;
V_74 -> V_139 ( V_2 , V_123 ) ;
V_2 -> V_5 . V_123 = V_123 ;
V_74 -> V_172 ( V_2 , 0 ) ;
V_899 . V_81 = V_899 . V_491 = 0 ;
V_74 -> V_903 ( V_2 , & V_899 ) ;
F_99 ( V_2 , 7 , V_200 ) ;
V_1086 . V_904 = ( V_2 -> V_5 . V_424 >> 4 ) & 0xffff ;
V_1086 . V_231 = V_2 -> V_5 . V_424 ;
V_1087 . V_904 = 0 ;
V_1087 . V_231 = 0 ;
V_1086 . V_910 = V_1087 . V_910 = 0xffffffff ;
V_1086 . type = V_1087 . type = 0x3 ;
V_1086 . V_911 = V_1087 . V_911 = 0 ;
V_1086 . V_184 = V_1087 . V_184 = 0 ;
V_1086 . V_592 = V_1087 . V_592 = 1 ;
V_1086 . V_915 = V_1087 . V_915 = 0 ;
V_1086 . V_909 = V_1087 . V_909 = 1 ;
V_1086 . V_914 = V_1087 . V_914 = 0 ;
V_1086 . V_913 = V_1087 . V_913 = 1 ;
V_1086 . V_908 = V_1087 . V_908 = 0 ;
V_1086 . V_917 = V_1087 . V_917 = 0 ;
F_354 ( V_2 , & V_1086 , V_1091 ) ;
F_354 ( V_2 , & V_1087 , V_1092 ) ;
F_354 ( V_2 , & V_1087 , V_1093 ) ;
F_354 ( V_2 , & V_1087 , V_1094 ) ;
F_354 ( V_2 , & V_1087 , V_1095 ) ;
F_354 ( V_2 , & V_1087 , V_1096 ) ;
if ( F_550 ( V_2 ) )
V_74 -> F_109 ( V_2 , 0 ) ;
F_76 ( V_2 ) ;
F_66 ( V_2 ) ;
}
static void F_551 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_634 = true ;
F_32 ( V_68 , V_2 ) ;
}
void F_552 ( struct V_140 * V_140 )
{
F_177 ( V_140 , V_1097 ) ;
}
static void F_553 ( struct V_1 * V_2 )
{
T_2 V_1098 [ 4 ] ;
if ( ! F_554 ( V_2 -> V_5 . V_646 ) )
return;
F_555 ( V_2 -> V_5 . V_1099 , 256 ) ;
if ( V_769 ( V_2 -> V_140 ) )
F_556 ( V_2 , V_2 -> V_5 . V_1099 ) ;
else {
if ( V_2 -> V_5 . V_593 )
V_74 -> V_594 ( V_2 ) ;
F_557 ( V_2 , V_2 -> V_5 . V_1099 ) ;
}
F_558 ( ( V_177 * ) V_1098 , V_2 -> V_5 . V_1099 ,
F_559 ( V_2 ) -> V_1100 , 256 ) ;
V_74 -> V_1101 ( V_2 , V_1098 ) ;
}
static void F_560 ( struct V_1 * V_2 )
{
++ V_2 -> V_78 . V_1102 ;
V_74 -> V_1102 ( V_2 ) ;
}
void F_561 ( struct V_1 * V_2 )
{
struct V_385 * V_385 = NULL ;
if ( ! F_90 ( V_2 ) )
return;
if ( ! V_74 -> V_1103 )
return;
V_385 = F_562 ( V_2 -> V_140 , V_841 >> V_107 ) ;
if ( F_388 ( V_385 ) )
return;
V_74 -> V_1103 ( V_2 , F_563 ( V_385 ) ) ;
F_564 ( V_385 ) ;
}
void F_565 ( struct V_140 * V_140 ,
unsigned long V_81 )
{
if ( V_81 == F_566 ( V_140 , V_841 >> V_107 ) )
F_177 ( V_140 , V_1104 ) ;
}
static int F_567 ( struct V_1 * V_2 )
{
int V_122 ;
bool V_1075 =
F_534 ( V_2 ) &&
F_263 ( V_2 ) ;
bool V_1105 = false ;
if ( V_2 -> V_339 ) {
if ( F_568 ( V_1106 , V_2 ) )
F_569 ( V_2 ) ;
if ( F_568 ( V_582 , V_2 ) )
F_570 ( V_2 ) ;
if ( F_568 ( V_298 , V_2 ) )
F_178 ( V_2 -> V_140 ) ;
if ( F_568 ( V_431 , V_2 ) )
F_198 ( V_2 ) ;
if ( F_568 ( V_338 , V_2 ) ) {
V_122 = F_192 ( V_2 ) ;
if ( F_170 ( V_122 ) )
goto V_114;
}
if ( F_568 ( V_1107 , V_2 ) )
F_87 ( V_2 ) ;
if ( F_568 ( V_174 , V_2 ) )
F_560 ( V_2 ) ;
if ( F_568 ( V_1108 , V_2 ) ) {
V_2 -> V_848 -> V_864 = V_1109 ;
V_122 = 0 ;
goto V_114;
}
if ( F_568 ( V_73 , V_2 ) ) {
V_2 -> V_848 -> V_864 = V_1110 ;
V_122 = 0 ;
goto V_114;
}
if ( F_568 ( V_1111 , V_2 ) ) {
V_2 -> V_1112 = 0 ;
V_74 -> V_1113 ( V_2 ) ;
}
if ( F_568 ( V_1114 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1115 = true ;
V_122 = 1 ;
goto V_114;
}
if ( F_568 ( V_436 , V_2 ) )
F_213 ( V_2 ) ;
if ( F_568 ( V_601 , V_2 ) )
F_551 ( V_2 ) ;
if ( F_568 ( V_87 , V_2 ) )
F_279 ( V_2 ) ;
if ( F_568 ( V_1116 , V_2 ) )
F_571 ( V_2 ) ;
if ( F_568 ( V_1117 , V_2 ) )
F_572 ( V_2 ) ;
if ( F_568 ( V_1118 , V_2 ) ) {
F_15 ( V_2 -> V_5 . V_1119 > 255 ) ;
if ( F_59 ( V_2 -> V_5 . V_1119 ,
V_2 -> V_5 . V_1099 ) ) {
V_2 -> V_848 -> V_864 = V_1120 ;
V_2 -> V_848 -> V_1121 . V_42 =
V_2 -> V_5 . V_1119 ;
V_122 = 0 ;
goto V_114;
}
}
if ( F_568 ( V_1097 , V_2 ) )
F_553 ( V_2 ) ;
if ( F_568 ( V_1104 , V_2 ) )
F_561 ( V_2 ) ;
if ( F_568 ( V_1122 , V_2 ) ) {
V_2 -> V_848 -> V_864 = V_1123 ;
V_2 -> V_848 -> V_1124 . type = V_1125 ;
V_122 = 0 ;
goto V_114;
}
if ( F_568 ( V_1126 , V_2 ) ) {
V_2 -> V_848 -> V_864 = V_1123 ;
V_2 -> V_848 -> V_1124 . type = V_1127 ;
V_122 = 0 ;
goto V_114;
}
if ( F_568 ( V_1128 , V_2 ) ) {
V_2 -> V_848 -> V_864 = V_1129 ;
V_2 -> V_848 -> V_1130 = V_2 -> V_5 . V_1130 . exit ;
V_122 = 0 ;
goto V_114;
}
if ( F_568 ( V_1131 , V_2 ) )
F_573 ( V_2 ) ;
}
if ( F_574 ( V_2 ) ) {
if ( V_2 -> V_5 . V_593 )
V_74 -> V_1132 ( V_2 ,
F_536 ( V_2 ) ) ;
}
if ( F_568 ( V_68 , V_2 ) || V_1075 ) {
F_575 ( V_2 ) ;
if ( V_2 -> V_5 . V_1041 == V_1133 ) {
V_122 = 1 ;
goto V_114;
}
if ( F_537 ( V_2 , V_1075 ) != 0 )
V_1105 = true ;
else {
if ( V_2 -> V_5 . V_634 && ! F_281 ( V_2 ) )
V_1105 = true ;
if ( V_2 -> V_5 . V_628 )
V_74 -> V_1134 ( V_2 ) ;
if ( F_540 ( V_2 ) || V_1075 )
V_74 -> V_1135 ( V_2 ) ;
}
if ( F_574 ( V_2 ) ) {
F_262 ( V_2 ) ;
F_576 ( V_2 ) ;
}
}
V_122 = F_577 ( V_2 ) ;
if ( F_170 ( V_122 ) ) {
goto V_1136;
}
F_439 () ;
V_74 -> V_1137 ( V_2 ) ;
if ( V_2 -> V_1112 )
F_440 ( V_2 ) ;
V_2 -> V_330 = V_1138 ;
F_236 ( & V_2 -> V_140 -> V_486 , V_2 -> V_1139 ) ;
F_578 () ;
F_341 () ;
if ( V_2 -> V_330 == V_1140 || V_2 -> V_339
|| F_579 () || F_580 ( V_399 ) ) {
V_2 -> V_330 = V_1141 ;
F_190 () ;
F_342 () ;
F_443 () ;
V_2 -> V_1139 = F_235 ( & V_2 -> V_140 -> V_486 ) ;
V_122 = 1 ;
goto V_1136;
}
F_72 ( V_2 ) ;
if ( V_1105 ) {
F_32 ( V_68 , V_2 ) ;
F_581 ( V_2 -> V_24 ) ;
}
F_582 ( V_2 -> V_299 ) ;
F_583 ( V_2 ) ;
F_584 () ;
if ( F_170 ( V_2 -> V_5 . V_185 ) ) {
F_585 ( 0 , 7 ) ;
F_585 ( V_2 -> V_5 . V_183 [ 0 ] , 0 ) ;
F_585 ( V_2 -> V_5 . V_183 [ 1 ] , 1 ) ;
F_585 ( V_2 -> V_5 . V_183 [ 2 ] , 2 ) ;
F_585 ( V_2 -> V_5 . V_183 [ 3 ] , 3 ) ;
F_585 ( V_2 -> V_5 . V_188 , 6 ) ;
V_2 -> V_5 . V_185 &= ~ V_186 ;
}
V_74 -> V_848 ( V_2 ) ;
if ( F_170 ( V_2 -> V_5 . V_185 & V_1142 ) ) {
F_30 ( V_2 -> V_180 & V_181 ) ;
V_74 -> V_1143 ( V_2 ) ;
F_94 ( V_2 ) ;
F_95 ( V_2 ) ;
F_96 ( V_2 ) ;
V_2 -> V_5 . V_185 &= ~ V_186 ;
}
if ( F_586 () )
F_587 () ;
V_2 -> V_5 . V_324 = F_151 ( V_2 , F_150 () ) ;
V_2 -> V_330 = V_1141 ;
F_190 () ;
F_74 ( V_2 ) ;
V_74 -> V_1144 ( V_2 ) ;
++ V_2 -> V_78 . V_1145 ;
F_588 () ;
F_342 () ;
F_443 () ;
V_2 -> V_1139 = F_235 ( & V_2 -> V_140 -> V_486 ) ;
if ( F_170 ( V_1146 == V_1147 ) ) {
unsigned long V_1067 = F_453 ( V_2 ) ;
F_589 ( V_1147 , ( void * ) V_1067 ) ;
}
if ( F_170 ( V_2 -> V_5 . V_275 ) )
F_32 ( V_338 , V_2 ) ;
if ( V_2 -> V_5 . V_1148 )
F_590 ( V_2 ) ;
V_122 = V_74 -> V_1149 ( V_2 ) ;
return V_122 ;
V_1136:
V_74 -> V_1136 ( V_2 ) ;
if ( F_170 ( V_2 -> V_5 . V_1148 ) )
F_590 ( V_2 ) ;
V_114:
return V_122 ;
}
static inline int F_591 ( struct V_140 * V_140 , struct V_1 * V_2 )
{
if ( ! F_592 ( V_2 ) &&
( ! V_74 -> V_1150 || V_74 -> V_1150 ( V_2 ) == 0 ) ) {
F_236 ( & V_140 -> V_486 , V_2 -> V_1139 ) ;
F_593 ( V_2 ) ;
V_2 -> V_1139 = F_235 ( & V_140 -> V_486 ) ;
if ( V_74 -> V_1151 )
V_74 -> V_1151 ( V_2 ) ;
if ( ! F_568 ( V_1152 , V_2 ) )
return 1 ;
}
F_575 ( V_2 ) ;
switch( V_2 -> V_5 . V_1041 ) {
case V_1042 :
V_2 -> V_5 . V_1153 . V_1154 = false ;
V_2 -> V_5 . V_1041 =
V_1155 ;
case V_1155 :
V_2 -> V_5 . V_6 . V_1115 = false ;
break;
case V_1133 :
break;
default:
return - V_1156 ;
break;
}
return 1 ;
}
static inline bool F_594 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_1041 == V_1155 &&
! V_2 -> V_5 . V_6 . V_1115 ) ;
}
static int F_595 ( struct V_1 * V_2 )
{
int V_122 ;
struct V_140 * V_140 = V_2 -> V_140 ;
V_2 -> V_1139 = F_235 ( & V_140 -> V_486 ) ;
for (; ; ) {
if ( F_594 ( V_2 ) ) {
V_122 = F_567 ( V_2 ) ;
} else {
V_122 = F_591 ( V_140 , V_2 ) ;
}
if ( V_122 <= 0 )
break;
F_180 ( V_241 , & V_2 -> V_339 ) ;
if ( F_596 ( V_2 ) )
F_597 ( V_2 ) ;
if ( F_534 ( V_2 ) &&
F_265 ( V_2 ) ) {
V_122 = 0 ;
V_2 -> V_848 -> V_864 = V_1157 ;
++ V_2 -> V_78 . V_1158 ;
break;
}
F_598 ( V_2 ) ;
if ( F_580 ( V_399 ) ) {
V_122 = - V_1156 ;
V_2 -> V_848 -> V_864 = V_1159 ;
++ V_2 -> V_78 . V_1160 ;
break;
}
if ( F_579 () ) {
F_236 ( & V_140 -> V_486 , V_2 -> V_1139 ) ;
F_599 () ;
V_2 -> V_1139 = F_235 ( & V_140 -> V_486 ) ;
}
}
F_236 ( & V_140 -> V_486 , V_2 -> V_1139 ) ;
return V_122 ;
}
static inline int F_600 ( struct V_1 * V_2 )
{
int V_122 ;
V_2 -> V_1139 = F_235 ( & V_2 -> V_140 -> V_486 ) ;
V_122 = F_601 ( V_2 , V_983 ) ;
F_236 ( & V_2 -> V_140 -> V_486 , V_2 -> V_1139 ) ;
if ( V_122 != V_950 )
return 0 ;
return 1 ;
}
static int V_996 ( struct V_1 * V_2 )
{
F_15 ( ! V_2 -> V_5 . V_879 . V_748 ) ;
return F_600 ( V_2 ) ;
}
static int V_997 ( struct V_1 * V_2 )
{
struct V_970 * V_848 = V_2 -> V_848 ;
struct V_846 * V_847 ;
unsigned V_96 ;
F_15 ( ! V_2 -> V_860 ) ;
V_847 = & V_2 -> V_843 [ V_2 -> V_861 ] ;
V_96 = F_347 ( 8u , V_847 -> V_96 ) ;
if ( ! V_2 -> V_863 )
memcpy ( V_847 -> V_39 , V_848 -> V_849 . V_39 , V_96 ) ;
if ( V_847 -> V_96 <= 8 ) {
V_847 ++ ;
V_2 -> V_861 ++ ;
} else {
V_847 -> V_39 += V_96 ;
V_847 -> V_389 += V_96 ;
V_847 -> V_96 -= V_96 ;
}
if ( V_2 -> V_861 >= V_2 -> V_854 ) {
V_2 -> V_860 = 0 ;
if ( V_2 -> V_863 )
return 1 ;
V_2 -> V_842 = 1 ;
return F_600 ( V_2 ) ;
}
V_848 -> V_864 = V_865 ;
V_848 -> V_849 . V_866 = V_847 -> V_389 ;
if ( V_2 -> V_863 )
memcpy ( V_848 -> V_849 . V_39 , V_847 -> V_39 , F_347 ( 8u , V_847 -> V_96 ) ) ;
V_848 -> V_849 . V_96 = F_347 ( 8u , V_847 -> V_96 ) ;
V_848 -> V_849 . V_862 = V_2 -> V_863 ;
V_2 -> V_5 . V_995 = V_997 ;
return 0 ;
}
int F_602 ( struct V_1 * V_2 , struct V_970 * V_970 )
{
struct V_1161 * V_1161 = & V_399 -> V_1162 . V_1161 ;
int V_122 ;
T_18 V_1163 ;
F_603 ( V_1161 ) ;
if ( V_2 -> V_1164 )
F_604 ( V_1165 , & V_2 -> V_1166 , & V_1163 ) ;
if ( F_170 ( V_2 -> V_5 . V_1041 == V_1167 ) ) {
F_593 ( V_2 ) ;
F_575 ( V_2 ) ;
F_180 ( V_1152 , & V_2 -> V_339 ) ;
V_122 = - V_1168 ;
goto V_114;
}
if ( ! F_90 ( V_2 ) ) {
if ( F_89 ( V_2 , V_970 -> V_178 ) != 0 ) {
V_122 = - V_580 ;
goto V_114;
}
}
if ( F_170 ( V_2 -> V_5 . V_995 ) ) {
int (* F_605)( struct V_1 * ) = V_2 -> V_5 . V_995 ;
V_2 -> V_5 . V_995 = NULL ;
V_122 = F_605 ( V_2 ) ;
if ( V_122 <= 0 )
goto V_114;
} else
F_30 ( V_2 -> V_5 . V_879 . V_748 || V_2 -> V_860 ) ;
V_122 = F_595 ( V_2 ) ;
V_114:
F_535 ( V_2 ) ;
if ( V_2 -> V_1164 )
F_604 ( V_1165 , & V_1163 , NULL ) ;
return V_122 ;
}
int F_606 ( struct V_1 * V_2 , struct V_1169 * V_1170 )
{
if ( V_2 -> V_5 . V_1000 ) {
F_607 ( & V_2 -> V_5 . V_930 ) ;
V_2 -> V_5 . V_1000 = false ;
}
V_1170 -> V_1171 = F_103 ( V_2 , V_204 ) ;
V_1170 -> V_1172 = F_103 ( V_2 , V_1059 ) ;
V_1170 -> V_1173 = F_103 ( V_2 , V_203 ) ;
V_1170 -> V_1174 = F_103 ( V_2 , V_205 ) ;
V_1170 -> V_1175 = F_103 ( V_2 , V_1060 ) ;
V_1170 -> V_1176 = F_103 ( V_2 , V_1177 ) ;
V_1170 -> V_1178 = F_103 ( V_2 , V_1179 ) ;
V_1170 -> V_1180 = F_103 ( V_2 , V_1181 ) ;
#ifdef F_63
V_1170 -> V_1182 = F_103 ( V_2 , V_1183 ) ;
V_1170 -> V_1184 = F_103 ( V_2 , V_1185 ) ;
V_1170 -> V_1186 = F_103 ( V_2 , V_1187 ) ;
V_1170 -> V_1188 = F_103 ( V_2 , V_1189 ) ;
V_1170 -> V_1190 = F_103 ( V_2 , V_1191 ) ;
V_1170 -> V_1192 = F_103 ( V_2 , V_1193 ) ;
V_1170 -> V_1194 = F_103 ( V_2 , V_1195 ) ;
V_1170 -> V_1196 = F_103 ( V_2 , V_1197 ) ;
#endif
V_1170 -> V_1067 = F_453 ( V_2 ) ;
V_1170 -> V_969 = F_452 ( V_2 ) ;
return 0 ;
}
int F_608 ( struct V_1 * V_2 , struct V_1169 * V_1170 )
{
V_2 -> V_5 . V_944 = true ;
V_2 -> V_5 . V_1000 = false ;
F_105 ( V_2 , V_204 , V_1170 -> V_1171 ) ;
F_105 ( V_2 , V_1059 , V_1170 -> V_1172 ) ;
F_105 ( V_2 , V_203 , V_1170 -> V_1173 ) ;
F_105 ( V_2 , V_205 , V_1170 -> V_1174 ) ;
F_105 ( V_2 , V_1060 , V_1170 -> V_1175 ) ;
F_105 ( V_2 , V_1177 , V_1170 -> V_1176 ) ;
F_105 ( V_2 , V_1179 , V_1170 -> V_1178 ) ;
F_105 ( V_2 , V_1181 , V_1170 -> V_1180 ) ;
#ifdef F_63
F_105 ( V_2 , V_1183 , V_1170 -> V_1182 ) ;
F_105 ( V_2 , V_1185 , V_1170 -> V_1184 ) ;
F_105 ( V_2 , V_1187 , V_1170 -> V_1186 ) ;
F_105 ( V_2 , V_1189 , V_1170 -> V_1188 ) ;
F_105 ( V_2 , V_1191 , V_1170 -> V_1190 ) ;
F_105 ( V_2 , V_1193 , V_1170 -> V_1192 ) ;
F_105 ( V_2 , V_1195 , V_1170 -> V_1194 ) ;
F_105 ( V_2 , V_1197 , V_1170 -> V_1196 ) ;
#endif
F_457 ( V_2 , V_1170 -> V_1067 ) ;
F_458 ( V_2 , V_1170 -> V_969 ) ;
V_2 -> V_5 . V_69 . V_70 = false ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
void F_609 ( struct V_1 * V_2 , int * V_184 , int * V_915 )
{
struct V_822 V_1086 ;
F_355 ( V_2 , & V_1086 , V_1091 ) ;
* V_184 = V_1086 . V_184 ;
* V_915 = V_1086 . V_915 ;
}
int F_610 ( struct V_1 * V_2 ,
struct V_1198 * V_1199 )
{
struct V_898 V_899 ;
F_355 ( V_2 , & V_1199 -> V_1086 , V_1091 ) ;
F_355 ( V_2 , & V_1199 -> V_1087 , V_1092 ) ;
F_355 ( V_2 , & V_1199 -> V_1200 , V_1093 ) ;
F_355 ( V_2 , & V_1199 -> V_1201 , V_1094 ) ;
F_355 ( V_2 , & V_1199 -> V_1202 , V_1095 ) ;
F_355 ( V_2 , & V_1199 -> V_1203 , V_1096 ) ;
F_355 ( V_2 , & V_1199 -> V_1204 , V_1084 ) ;
F_355 ( V_2 , & V_1199 -> V_1205 , V_1085 ) ;
V_74 -> V_901 ( V_2 , & V_899 ) ;
V_1199 -> V_1206 . V_910 = V_899 . V_491 ;
V_1199 -> V_1206 . V_231 = V_899 . V_81 ;
V_74 -> V_900 ( V_2 , & V_899 ) ;
V_1199 -> V_1207 . V_910 = V_899 . V_491 ;
V_1199 -> V_1207 . V_231 = V_899 . V_81 ;
V_1199 -> V_123 = F_62 ( V_2 ) ;
V_1199 -> V_80 = V_2 -> V_5 . V_80 ;
V_1199 -> V_105 = F_60 ( V_2 ) ;
V_1199 -> V_160 = F_79 ( V_2 ) ;
V_1199 -> V_178 = F_92 ( V_2 ) ;
V_1199 -> V_133 = V_2 -> V_5 . V_133 ;
V_1199 -> V_32 = F_21 ( V_2 ) ;
memset ( V_1199 -> V_1208 , 0 , sizeof V_1199 -> V_1208 ) ;
if ( V_2 -> V_5 . V_622 . V_70 && ! V_2 -> V_5 . V_622 . V_623 )
F_219 ( V_2 -> V_5 . V_622 . V_18 ,
( unsigned long * ) V_1199 -> V_1208 ) ;
return 0 ;
}
int F_611 ( struct V_1 * V_2 ,
struct V_1209 * V_1041 )
{
F_575 ( V_2 ) ;
if ( V_2 -> V_5 . V_1041 == V_1042 &&
V_2 -> V_5 . V_1153 . V_1154 )
V_1041 -> V_1041 = V_1155 ;
else
V_1041 -> V_1041 = V_2 -> V_5 . V_1041 ;
return 0 ;
}
int F_612 ( struct V_1 * V_2 ,
struct V_1209 * V_1041 )
{
if ( ! F_90 ( V_2 ) &&
V_1041 -> V_1041 != V_1155 )
return - V_580 ;
if ( V_1041 -> V_1041 == V_1210 ) {
V_2 -> V_5 . V_1041 = V_1133 ;
F_219 ( V_1211 , & V_2 -> V_5 . V_646 -> V_649 ) ;
} else
V_2 -> V_5 . V_1041 = V_1041 -> V_1041 ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
int F_613 ( struct V_1 * V_2 , V_875 V_1212 , int V_1213 ,
int V_1214 , bool V_72 , T_1 V_63 )
{
struct V_836 * V_837 = & V_2 -> V_5 . V_930 ;
int V_109 ;
F_451 ( V_2 ) ;
V_109 = F_614 ( V_837 , V_1212 , V_1213 , V_1214 ,
V_72 , V_63 ) ;
if ( V_109 )
return V_949 ;
F_457 ( V_2 , V_837 -> V_933 ) ;
F_458 ( V_2 , V_837 -> V_932 ) ;
F_32 ( V_68 , V_2 ) ;
return V_950 ;
}
int F_615 ( struct V_1 * V_2 ,
struct V_1198 * V_1199 )
{
struct V_33 V_1215 ;
int V_1216 = 0 ;
int V_1217 , V_1218 , V_485 ;
struct V_898 V_899 ;
if ( ! F_80 ( V_2 ) && ( V_1199 -> V_160 & V_143 ) )
return - V_580 ;
V_899 . V_491 = V_1199 -> V_1206 . V_910 ;
V_899 . V_81 = V_1199 -> V_1206 . V_231 ;
V_74 -> V_903 ( V_2 , & V_899 ) ;
V_899 . V_491 = V_1199 -> V_1207 . V_910 ;
V_899 . V_81 = V_1199 -> V_1207 . V_231 ;
V_74 -> V_902 ( V_2 , & V_899 ) ;
V_2 -> V_5 . V_80 = V_1199 -> V_80 ;
V_1216 |= F_60 ( V_2 ) != V_1199 -> V_105 ;
V_2 -> V_5 . V_105 = V_1199 -> V_105 ;
F_55 ( V_176 , ( V_177 * ) & V_2 -> V_5 . V_119 ) ;
F_89 ( V_2 , V_1199 -> V_178 ) ;
V_1216 |= V_2 -> V_5 . V_133 != V_1199 -> V_133 ;
V_74 -> F_109 ( V_2 , V_1199 -> V_133 ) ;
V_1215 . V_39 = V_1199 -> V_32 ;
V_1215 . V_41 = true ;
F_22 ( V_2 , & V_1215 ) ;
V_1216 |= F_62 ( V_2 ) != V_1199 -> V_123 ;
V_74 -> V_139 ( V_2 , V_1199 -> V_123 ) ;
V_2 -> V_5 . V_123 = V_1199 -> V_123 ;
V_1216 |= F_79 ( V_2 ) != V_1199 -> V_160 ;
V_74 -> V_172 ( V_2 , V_1199 -> V_160 ) ;
if ( V_1199 -> V_160 & ( V_143 | V_168 ) )
F_76 ( V_2 ) ;
V_485 = F_235 ( & V_2 -> V_140 -> V_486 ) ;
if ( ! F_57 ( V_2 ) && F_58 ( V_2 ) ) {
F_53 ( V_2 , V_2 -> V_5 . V_104 , F_60 ( V_2 ) ) ;
V_1216 = 1 ;
}
F_236 ( & V_2 -> V_140 -> V_486 , V_485 ) ;
if ( V_1216 )
F_66 ( V_2 ) ;
V_1218 = V_597 ;
V_1217 = F_616 (
( const unsigned long * ) V_1199 -> V_1208 , V_1218 ) ;
if ( V_1217 < V_1218 ) {
F_271 ( V_2 , V_1217 , false ) ;
F_132 ( L_28 , V_1217 ) ;
}
F_354 ( V_2 , & V_1199 -> V_1086 , V_1091 ) ;
F_354 ( V_2 , & V_1199 -> V_1087 , V_1092 ) ;
F_354 ( V_2 , & V_1199 -> V_1200 , V_1093 ) ;
F_354 ( V_2 , & V_1199 -> V_1201 , V_1094 ) ;
F_354 ( V_2 , & V_1199 -> V_1202 , V_1095 ) ;
F_354 ( V_2 , & V_1199 -> V_1203 , V_1096 ) ;
F_354 ( V_2 , & V_1199 -> V_1204 , V_1084 ) ;
F_354 ( V_2 , & V_1199 -> V_1205 , V_1085 ) ;
F_262 ( V_2 ) ;
if ( F_617 ( V_2 ) && F_453 ( V_2 ) == 0xfff0 &&
V_1199 -> V_1086 . V_904 == 0xf000 && V_1199 -> V_1086 . V_231 == 0xffff0000 &&
! F_33 ( V_2 ) )
V_2 -> V_5 . V_1041 = V_1155 ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
int F_618 ( struct V_1 * V_2 ,
struct V_1219 * V_1220 )
{
unsigned long V_969 ;
int V_3 , V_122 ;
if ( V_1220 -> V_755 & ( V_1221 | V_1222 ) ) {
V_122 = - V_803 ;
if ( V_2 -> V_5 . V_69 . V_70 )
goto V_114;
if ( V_1220 -> V_755 & V_1221 )
F_34 ( V_2 , V_54 ) ;
else
F_34 ( V_2 , V_55 ) ;
}
V_969 = F_452 ( V_2 ) ;
V_2 -> V_180 = V_1220 -> V_755 ;
if ( ! ( V_2 -> V_180 & V_1223 ) )
V_2 -> V_180 = 0 ;
if ( V_2 -> V_180 & V_181 ) {
for ( V_3 = 0 ; V_3 < V_182 ; ++ V_3 )
V_2 -> V_5 . V_183 [ V_3 ] = V_1220 -> V_5 . V_1224 [ V_3 ] ;
V_2 -> V_5 . V_190 = V_1220 -> V_5 . V_1224 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_182 ; V_3 ++ )
V_2 -> V_5 . V_183 [ V_3 ] = V_2 -> V_5 . V_184 [ V_3 ] ;
}
F_96 ( V_2 ) ;
if ( V_2 -> V_180 & V_972 )
V_2 -> V_5 . V_976 = F_453 ( V_2 ) +
F_402 ( V_2 , V_1091 ) ;
F_458 ( V_2 , V_969 ) ;
V_74 -> V_1225 ( V_2 ) ;
V_122 = 0 ;
V_114:
return V_122 ;
}
int F_619 ( struct V_1 * V_2 ,
struct V_1226 * V_1204 )
{
unsigned long V_1227 = V_1204 -> V_1228 ;
T_6 V_389 ;
int V_485 ;
V_485 = F_235 ( & V_2 -> V_140 -> V_486 ) ;
V_389 = F_360 ( V_2 , V_1227 , NULL ) ;
F_236 ( & V_2 -> V_140 -> V_486 , V_485 ) ;
V_1204 -> V_1229 = V_389 ;
V_1204 -> V_660 = V_389 != V_101 ;
V_1204 -> V_1230 = 1 ;
V_1204 -> V_1231 = 0 ;
return 0 ;
}
int F_620 ( struct V_1 * V_2 , struct V_1232 * V_1161 )
{
struct V_673 * V_672 =
& V_2 -> V_5 . V_655 . V_656 . V_672 ;
memcpy ( V_1161 -> V_1233 , V_672 -> V_1234 , 128 ) ;
V_1161 -> V_1235 = V_672 -> V_1236 ;
V_1161 -> V_1237 = V_672 -> V_1238 ;
V_1161 -> V_1239 = V_672 -> V_1240 ;
V_1161 -> V_1241 = V_672 -> V_1242 ;
V_1161 -> V_1243 = V_672 -> V_1067 ;
V_1161 -> V_1244 = V_672 -> V_1245 ;
memcpy ( V_1161 -> V_1246 , V_672 -> V_1247 , sizeof V_672 -> V_1247 ) ;
return 0 ;
}
int F_621 ( struct V_1 * V_2 , struct V_1232 * V_1161 )
{
struct V_673 * V_672 =
& V_2 -> V_5 . V_655 . V_656 . V_672 ;
memcpy ( V_672 -> V_1234 , V_1161 -> V_1233 , 128 ) ;
V_672 -> V_1236 = V_1161 -> V_1235 ;
V_672 -> V_1238 = V_1161 -> V_1237 ;
V_672 -> V_1240 = V_1161 -> V_1239 ;
V_672 -> V_1242 = V_1161 -> V_1241 ;
V_672 -> V_1067 = V_1161 -> V_1243 ;
V_672 -> V_1245 = V_1161 -> V_1244 ;
memcpy ( V_672 -> V_1247 , V_1161 -> V_1246 , sizeof V_672 -> V_1247 ) ;
return 0 ;
}
static void F_622 ( struct V_1 * V_2 )
{
F_623 ( & V_2 -> V_5 . V_655 . V_656 ) ;
if ( F_243 ( V_666 ) )
V_2 -> V_5 . V_655 . V_656 . V_654 . V_658 . V_667 =
V_147 | V_668 ;
V_2 -> V_5 . V_146 = V_152 ;
V_2 -> V_5 . V_123 |= V_128 ;
}
void F_440 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1248 )
return;
V_2 -> V_1248 = 1 ;
F_624 () ;
F_625 ( & V_2 -> V_5 . V_655 . V_656 ) ;
F_626 ( 1 ) ;
}
void F_257 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_1248 ) {
V_2 -> V_1249 = 0 ;
return;
}
V_2 -> V_1248 = 0 ;
F_627 ( & V_2 -> V_5 . V_655 ) ;
F_628 () ;
++ V_2 -> V_78 . V_1250 ;
if ( ! F_629 () ) {
if ( ++ V_2 -> V_1249 < 5 )
F_32 ( V_1111 , V_2 ) ;
}
F_626 ( 0 ) ;
}
void F_630 ( struct V_1 * V_2 )
{
void * V_584 = V_2 -> V_5 . V_584 ;
F_212 ( V_2 ) ;
V_74 -> V_1251 ( V_2 ) ;
F_631 ( V_584 ) ;
}
struct V_1 * F_632 ( struct V_140 * V_140 ,
unsigned int V_1252 )
{
struct V_1 * V_2 ;
if ( F_156 () && F_143 ( & V_140 -> V_295 ) != 0 )
F_396 ( V_877
L_29
L_30 ) ;
V_2 = V_74 -> V_1253 ( V_140 , V_1252 ) ;
return V_2 ;
}
int F_633 ( struct V_1 * V_2 )
{
int V_122 ;
F_634 ( V_2 ) ;
V_122 = V_585 ( V_2 ) ;
if ( V_122 )
return V_122 ;
F_635 ( V_2 , false ) ;
F_636 ( V_2 ) ;
V_590 ( V_2 ) ;
return V_122 ;
}
void F_637 ( struct V_1 * V_2 )
{
struct V_33 V_22 ;
struct V_140 * V_140 = V_2 -> V_140 ;
if ( V_585 ( V_2 ) )
return;
V_22 . V_39 = 0x0 ;
V_22 . V_148 = V_1254 ;
V_22 . V_41 = true ;
F_153 ( V_2 , & V_22 ) ;
V_590 ( V_2 ) ;
if ( ! V_364 )
return;
F_199 ( & V_140 -> V_5 . V_363 ,
V_365 ) ;
}
void F_638 ( struct V_1 * V_2 )
{
int V_122 ;
V_2 -> V_5 . V_6 . V_390 = 0 ;
V_122 = V_585 ( V_2 ) ;
F_15 ( V_122 ) ;
F_569 ( V_2 ) ;
V_590 ( V_2 ) ;
V_74 -> V_1251 ( V_2 ) ;
}
void F_635 ( struct V_1 * V_2 , bool V_1255 )
{
V_2 -> V_5 . V_636 = 0 ;
V_2 -> V_5 . V_634 = 0 ;
F_174 ( & V_2 -> V_5 . V_86 , 0 ) ;
V_2 -> V_5 . V_628 = 0 ;
V_2 -> V_5 . V_627 = false ;
F_639 ( V_2 ) ;
F_477 ( V_2 ) ;
memset ( V_2 -> V_5 . V_184 , 0 , sizeof( V_2 -> V_5 . V_184 ) ) ;
F_94 ( V_2 ) ;
V_2 -> V_5 . V_188 = V_1256 ;
F_95 ( V_2 ) ;
V_2 -> V_5 . V_189 = V_200 ;
F_96 ( V_2 ) ;
V_2 -> V_5 . V_80 = 0 ;
F_32 ( V_68 , V_2 ) ;
V_2 -> V_5 . V_6 . V_390 = 0 ;
V_2 -> V_5 . V_394 . V_390 = 0 ;
F_212 ( V_2 ) ;
F_65 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1115 = false ;
if ( ! V_1255 ) {
F_640 ( V_2 ) ;
V_2 -> V_5 . V_424 = 0x30000 ;
}
memset ( V_2 -> V_5 . V_1170 , 0 , sizeof( V_2 -> V_5 . V_1170 ) ) ;
V_2 -> V_5 . V_119 = ~ 0 ;
V_2 -> V_5 . V_120 = ~ 0 ;
V_74 -> V_1257 ( V_2 , V_1255 ) ;
}
void F_641 ( struct V_1 * V_2 , T_14 V_42 )
{
struct V_822 V_1086 ;
F_355 ( V_2 , & V_1086 , V_1091 ) ;
V_1086 . V_904 = V_42 << 8 ;
V_1086 . V_231 = V_42 << 12 ;
F_354 ( V_2 , & V_1086 , V_1091 ) ;
F_457 ( V_2 , 0 ) ;
}
int F_642 ( void )
{
struct V_140 * V_140 ;
struct V_1 * V_2 ;
int V_3 ;
int V_109 ;
T_2 V_1258 ;
T_2 V_1259 = 0 ;
bool V_1260 , V_1261 = false ;
F_16 () ;
V_109 = V_74 -> V_1262 () ;
if ( V_109 != 0 )
return V_109 ;
V_1258 = F_150 () ;
V_1260 = ! F_156 () ;
F_490 (kvm, &vm_list, vm_list) {
F_179 (i, vcpu, kvm) {
if ( ! V_1260 && V_2 -> V_24 == F_10 () )
F_32 ( V_338 , V_2 ) ;
if ( V_1260 && V_2 -> V_5 . V_588 > V_1258 ) {
V_1261 = true ;
if ( V_2 -> V_5 . V_588 > V_1259 )
V_1259 = V_2 -> V_5 . V_588 ;
}
}
}
if ( V_1261 ) {
T_2 V_1263 = V_1259 - V_1258 ;
V_334 = true ;
F_490 (kvm, &vm_list, vm_list) {
F_179 (i, vcpu, kvm) {
V_2 -> V_5 . V_586 += V_1263 ;
V_2 -> V_5 . V_588 = V_1258 ;
F_32 ( V_298 , V_2 ) ;
}
V_140 -> V_5 . V_313 = 0 ;
V_140 -> V_5 . V_315 = 0 ;
}
}
return 0 ;
}
void F_643 ( void )
{
V_74 -> V_1264 () ;
F_20 () ;
}
int F_644 ( void )
{
int V_122 ;
V_122 = V_74 -> V_1265 () ;
if ( V_122 != 0 )
return V_122 ;
if ( V_272 ) {
T_2 V_1266 = F_347 ( 0x7fffffffULL ,
F_146 ( V_277 , V_273 ) ) ;
V_713 = V_1266 ;
V_271 = 1ULL << V_276 ;
}
F_344 () ;
return 0 ;
}
void F_645 ( void )
{
V_74 -> V_1267 () ;
}
void F_646 ( void * V_1268 )
{
V_74 -> V_1269 ( V_1268 ) ;
}
bool F_647 ( struct V_1 * V_2 )
{
return V_2 -> V_140 -> V_5 . V_804 == V_2 -> V_299 ;
}
bool F_617 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_32 & V_1270 ) != 0 ;
}
int F_648 ( struct V_1 * V_2 )
{
struct V_385 * V_385 ;
struct V_140 * V_140 ;
int V_122 ;
F_15 ( V_2 -> V_140 == NULL ) ;
V_140 = V_2 -> V_140 ;
V_2 -> V_5 . V_593 = V_74 -> V_1271 () ;
V_2 -> V_5 . V_1153 . V_1154 = false ;
V_2 -> V_5 . V_930 . V_851 = & V_1272 ;
if ( ! F_270 ( V_140 ) || F_647 ( V_2 ) )
V_2 -> V_5 . V_1041 = V_1155 ;
else
V_2 -> V_5 . V_1041 = V_1167 ;
V_385 = F_649 ( V_686 | V_1273 ) ;
if ( ! V_385 ) {
V_122 = - V_387 ;
goto V_1274;
}
V_2 -> V_5 . V_883 = F_650 ( V_385 ) ;
F_139 ( V_2 , V_1011 ) ;
V_122 = F_651 ( V_2 ) ;
if ( V_122 < 0 )
goto V_1275;
if ( F_270 ( V_140 ) ) {
V_122 = F_652 ( V_2 ) ;
if ( V_122 < 0 )
goto V_1276;
} else
F_653 ( & V_1277 ) ;
V_2 -> V_5 . V_374 = F_300 ( V_438 * sizeof( T_2 ) * 4 ,
V_686 ) ;
if ( ! V_2 -> V_5 . V_374 ) {
V_122 = - V_387 ;
goto V_1278;
}
V_2 -> V_5 . V_366 = V_438 ;
if ( ! F_654 ( & V_2 -> V_5 . V_584 , V_686 ) ) {
V_122 = - V_387 ;
goto V_1279;
}
F_622 ( V_2 ) ;
V_2 -> V_5 . V_302 = 0x0 ;
V_2 -> V_5 . V_356 = false ;
V_2 -> V_5 . V_155 = 0 ;
V_2 -> V_5 . V_1280 = V_1281 + V_661 ;
V_2 -> V_5 . V_1022 = F_655 ( V_2 ) ;
V_2 -> V_5 . V_1282 = V_1283 ;
F_1 ( V_2 ) ;
F_656 ( V_2 ) ;
V_2 -> V_5 . V_599 = - 1 ;
F_657 ( V_2 ) ;
return 0 ;
V_1279:
F_208 ( V_2 -> V_5 . V_374 ) ;
V_1278:
F_658 ( V_2 ) ;
V_1276:
F_659 ( V_2 ) ;
V_1275:
F_660 ( ( unsigned long ) V_2 -> V_5 . V_883 ) ;
V_1274:
return V_122 ;
}
void F_661 ( struct V_1 * V_2 )
{
int V_485 ;
F_662 ( V_2 ) ;
F_663 ( V_2 ) ;
F_208 ( V_2 -> V_5 . V_374 ) ;
F_658 ( V_2 ) ;
V_485 = F_235 ( & V_2 -> V_140 -> V_486 ) ;
F_659 ( V_2 ) ;
F_236 ( & V_2 -> V_140 -> V_486 , V_485 ) ;
F_660 ( ( unsigned long ) V_2 -> V_5 . V_883 ) ;
if ( ! F_90 ( V_2 ) )
F_664 ( & V_1277 ) ;
}
void F_665 ( struct V_1 * V_2 , int V_24 )
{
V_74 -> V_1284 ( V_2 , V_24 ) ;
}
int F_666 ( struct V_140 * V_140 , unsigned long type )
{
if ( type )
return - V_580 ;
F_667 ( & V_140 -> V_5 . V_1285 ) ;
F_668 ( & V_140 -> V_5 . V_1286 ) ;
F_668 ( & V_140 -> V_5 . V_1287 ) ;
F_668 ( & V_140 -> V_5 . V_1288 ) ;
F_174 ( & V_140 -> V_5 . V_1289 , 0 ) ;
F_219 ( V_763 , & V_140 -> V_5 . V_1290 ) ;
F_219 ( V_1291 ,
& V_140 -> V_5 . V_1290 ) ;
F_669 ( & V_140 -> V_5 . V_312 ) ;
F_670 ( & V_140 -> V_5 . V_1292 ) ;
F_671 ( & V_140 -> V_5 . V_325 ) ;
V_140 -> V_5 . V_248 = - F_155 () ;
F_173 ( V_140 ) ;
F_672 ( & V_140 -> V_5 . V_361 , F_195 ) ;
F_672 ( & V_140 -> V_5 . V_363 , F_200 ) ;
F_673 ( V_140 ) ;
F_674 ( V_140 ) ;
if ( V_74 -> V_1293 )
return V_74 -> V_1293 ( V_140 ) ;
return 0 ;
}
static void F_675 ( struct V_1 * V_2 )
{
int V_122 ;
V_122 = V_585 ( V_2 ) ;
F_15 ( V_122 ) ;
F_569 ( V_2 ) ;
V_590 ( V_2 ) ;
}
static void F_676 ( struct V_140 * V_140 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_179 (i, vcpu, kvm) {
F_65 ( V_2 ) ;
F_675 ( V_2 ) ;
}
F_179 (i, vcpu, kvm)
F_630 ( V_2 ) ;
F_309 ( & V_140 -> V_738 ) ;
for ( V_3 = 0 ; V_3 < F_143 ( & V_140 -> V_295 ) ; V_3 ++ )
V_140 -> V_1294 [ V_3 ] = NULL ;
F_174 ( & V_140 -> V_295 , 0 ) ;
F_311 ( & V_140 -> V_738 ) ;
}
void F_677 ( struct V_140 * V_140 )
{
F_678 ( & V_140 -> V_5 . V_363 ) ;
F_678 ( & V_140 -> V_5 . V_361 ) ;
F_679 ( V_140 ) ;
F_680 ( V_140 ) ;
}
int F_681 ( struct V_140 * V_140 , int V_1252 , T_6 V_389 , T_1 V_491 )
{
int V_3 , V_122 ;
unsigned long V_1295 ;
struct V_1296 * V_1297 = V_1296 ( V_140 ) ;
struct V_1298 * V_10 , V_870 ;
if ( F_30 ( V_1252 >= V_1299 ) )
return - V_580 ;
V_10 = F_682 ( V_1297 , V_1252 ) ;
if ( V_491 ) {
if ( V_10 -> V_1300 )
return - V_600 ;
V_1295 = F_683 ( NULL , 0 , V_491 , V_1301 | V_1302 ,
V_1303 | V_1304 , 0 ) ;
if ( F_205 ( ( void * ) V_1295 ) )
return F_206 ( ( void * ) V_1295 ) ;
} else {
if ( ! V_10 -> V_1300 )
return 0 ;
V_1295 = 0 ;
}
V_870 = * V_10 ;
for ( V_3 = 0 ; V_3 < V_1305 ; V_3 ++ ) {
struct V_1306 V_1307 ;
V_1307 . V_10 = V_1252 | ( V_3 << 16 ) ;
V_1307 . V_15 = 0 ;
V_1307 . V_1308 = V_389 ;
V_1307 . V_1309 = V_1295 ;
V_1307 . V_1310 = V_491 ;
V_122 = F_684 ( V_140 , & V_1307 ) ;
if ( V_122 < 0 )
return V_122 ;
}
if ( ! V_491 ) {
V_122 = F_685 ( V_870 . V_1309 , V_870 . V_1300 * V_108 ) ;
F_30 ( V_122 < 0 ) ;
}
return 0 ;
}
int F_686 ( struct V_140 * V_140 , int V_1252 , T_6 V_389 , T_1 V_491 )
{
int V_122 ;
F_309 ( & V_140 -> V_725 ) ;
V_122 = F_681 ( V_140 , V_1252 , V_389 , V_491 ) ;
F_311 ( & V_140 -> V_725 ) ;
return V_122 ;
}
void F_687 ( struct V_140 * V_140 )
{
if ( V_399 -> V_1311 == V_140 -> V_1311 ) {
F_686 ( V_140 , V_1312 , 0 , 0 ) ;
F_686 ( V_140 , V_1313 , 0 , 0 ) ;
F_686 ( V_140 , V_1314 , 0 , 0 ) ;
}
if ( V_74 -> V_1315 )
V_74 -> V_1315 ( V_140 ) ;
F_688 ( V_140 ) ;
F_208 ( V_140 -> V_5 . V_785 ) ;
F_208 ( V_140 -> V_5 . V_1316 ) ;
F_676 ( V_140 ) ;
F_689 ( F_690 ( V_140 -> V_5 . V_1317 , 1 ) ) ;
F_691 ( V_140 ) ;
}
void F_692 ( struct V_140 * V_140 , struct V_1298 * free ,
struct V_1298 * V_1318 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1319 ; ++ V_3 ) {
if ( ! V_1318 || free -> V_5 . V_1320 [ V_3 ] != V_1318 -> V_5 . V_1320 [ V_3 ] ) {
F_689 ( free -> V_5 . V_1320 [ V_3 ] ) ;
free -> V_5 . V_1320 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1318 || free -> V_5 . V_1321 [ V_3 - 1 ] !=
V_1318 -> V_5 . V_1321 [ V_3 - 1 ] ) {
F_689 ( free -> V_5 . V_1321 [ V_3 - 1 ] ) ;
free -> V_5 . V_1321 [ V_3 - 1 ] = NULL ;
}
}
F_693 ( free , V_1318 ) ;
}
int F_694 ( struct V_140 * V_140 , struct V_1298 * V_10 ,
unsigned long V_1300 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1319 ; ++ V_3 ) {
struct V_1322 * V_1323 ;
unsigned long V_1324 ;
int V_1325 ;
int V_764 = V_3 + 1 ;
V_1325 = F_695 ( V_10 -> V_1326 + V_1300 - 1 ,
V_10 -> V_1326 , V_764 ) + 1 ;
V_10 -> V_5 . V_1320 [ V_3 ] =
F_696 ( V_1325 * sizeof( * V_10 -> V_5 . V_1320 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1320 [ V_3 ] )
goto V_388;
if ( V_3 == 0 )
continue;
V_1323 = F_696 ( V_1325 * sizeof( * V_1323 ) ) ;
if ( ! V_1323 )
goto V_388;
V_10 -> V_5 . V_1321 [ V_3 - 1 ] = V_1323 ;
if ( V_10 -> V_1326 & ( F_697 ( V_764 ) - 1 ) )
V_1323 [ 0 ] . V_1327 = 1 ;
if ( ( V_10 -> V_1326 + V_1300 ) & ( F_697 ( V_764 ) - 1 ) )
V_1323 [ V_1325 - 1 ] . V_1327 = 1 ;
V_1324 = V_10 -> V_1309 >> V_107 ;
if ( ( V_10 -> V_1326 ^ V_1324 ) & ( F_697 ( V_764 ) - 1 ) ||
! F_698 () ) {
unsigned long V_813 ;
for ( V_813 = 0 ; V_813 < V_1325 ; ++ V_813 )
V_1323 [ V_813 ] . V_1327 = 1 ;
}
}
if ( F_699 ( V_10 , V_1300 ) )
goto V_388;
return 0 ;
V_388:
for ( V_3 = 0 ; V_3 < V_1319 ; ++ V_3 ) {
F_689 ( V_10 -> V_5 . V_1320 [ V_3 ] ) ;
V_10 -> V_5 . V_1320 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_689 ( V_10 -> V_5 . V_1321 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1321 [ V_3 - 1 ] = NULL ;
}
return - V_387 ;
}
void F_700 ( struct V_140 * V_140 , struct V_1296 * V_1297 )
{
F_701 ( V_140 , V_1297 ) ;
}
int F_702 ( struct V_140 * V_140 ,
struct V_1298 * V_1328 ,
const struct V_1306 * V_1329 ,
enum V_1330 V_1331 )
{
return 0 ;
}
static void F_703 ( struct V_140 * V_140 ,
struct V_1298 * V_871 )
{
if ( V_871 -> V_15 & V_1332 ) {
F_704 ( V_140 , V_871 ) ;
return;
}
if ( V_871 -> V_15 & V_1333 ) {
if ( V_74 -> V_1334 )
V_74 -> V_1334 ( V_140 , V_871 ) ;
else
F_704 ( V_140 , V_871 ) ;
} else {
if ( V_74 -> V_1335 )
V_74 -> V_1335 ( V_140 , V_871 ) ;
}
}
void F_705 ( struct V_140 * V_140 ,
const struct V_1306 * V_1329 ,
const struct V_1298 * V_870 ,
const struct V_1298 * V_871 ,
enum V_1330 V_1331 )
{
int V_1336 = 0 ;
if ( ! V_140 -> V_5 . V_726 )
V_1336 = F_706 ( V_140 ) ;
if ( V_1336 )
F_310 ( V_140 , V_1336 ) ;
if ( ( V_1331 != V_1337 ) &&
( V_870 -> V_15 & V_1333 ) &&
! ( V_871 -> V_15 & V_1333 ) )
F_707 ( V_140 , V_871 ) ;
if ( V_1331 != V_1337 )
F_703 ( V_140 , (struct V_1298 * ) V_871 ) ;
}
void F_708 ( struct V_140 * V_140 )
{
F_709 ( V_140 ) ;
}
void F_710 ( struct V_140 * V_140 ,
struct V_1298 * V_10 )
{
F_709 ( V_140 ) ;
}
static inline bool F_711 ( struct V_1 * V_2 )
{
if ( ! F_712 ( & V_2 -> V_1338 . V_1339 ) )
return true ;
if ( F_713 ( V_2 ) )
return true ;
if ( V_2 -> V_5 . V_1153 . V_1154 )
return true ;
if ( F_143 ( & V_2 -> V_5 . V_86 ) )
return true ;
if ( F_59 ( V_601 , & V_2 -> V_339 ) )
return true ;
if ( F_266 ( V_2 ) &&
F_267 ( V_2 ) )
return true ;
if ( F_714 ( V_2 ) )
return true ;
return false ;
}
int F_592 ( struct V_1 * V_2 )
{
if ( F_461 ( V_2 ) && V_74 -> V_1080 )
V_74 -> V_1080 ( V_2 , false ) ;
return F_594 ( V_2 ) || F_711 ( V_2 ) ;
}
int F_715 ( struct V_1 * V_2 )
{
return F_716 ( V_2 ) == V_1138 ;
}
int F_266 ( struct V_1 * V_2 )
{
return V_74 -> V_1082 ( V_2 ) ;
}
unsigned long F_475 ( struct V_1 * V_2 )
{
if ( F_532 ( V_2 ) )
return F_453 ( V_2 ) ;
return ( T_1 ) ( F_402 ( V_2 , V_1091 ) +
F_453 ( V_2 ) ) ;
}
bool F_717 ( struct V_1 * V_2 , unsigned long V_1340 )
{
return F_475 ( V_2 ) == V_1340 ;
}
unsigned long F_452 ( struct V_1 * V_2 )
{
unsigned long V_969 ;
V_969 = V_74 -> V_999 ( V_2 ) ;
if ( V_2 -> V_180 & V_972 )
V_969 &= ~ V_971 ;
return V_969 ;
}
static void F_482 ( struct V_1 * V_2 , unsigned long V_969 )
{
if ( V_2 -> V_180 & V_972 &&
F_717 ( V_2 , V_2 -> V_5 . V_976 ) )
V_969 |= V_971 ;
V_74 -> V_1341 ( V_2 , V_969 ) ;
}
void F_458 ( struct V_1 * V_2 , unsigned long V_969 )
{
F_482 ( V_2 , V_969 ) ;
F_32 ( V_68 , V_2 ) ;
}
void F_718 ( struct V_1 * V_2 , struct V_1342 * V_358 )
{
int V_122 ;
if ( ( V_2 -> V_5 . V_85 . V_961 != V_358 -> V_5 . V_961 ) ||
V_358 -> V_1343 )
return;
V_122 = F_577 ( V_2 ) ;
if ( F_170 ( V_122 ) )
return;
if ( ! V_2 -> V_5 . V_85 . V_961 &&
V_358 -> V_5 . V_105 != V_2 -> V_5 . V_85 . V_1344 ( V_2 ) )
return;
V_2 -> V_5 . V_85 . V_1345 ( V_2 , V_358 -> V_829 , 0 , true ) ;
}
static inline T_1 F_719 ( T_5 V_103 )
{
return F_720 ( V_103 & 0xffffffff , F_721 ( V_4 ) ) ;
}
static inline T_1 F_722 ( T_1 V_1346 )
{
return ( V_1346 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_723 ( struct V_1 * V_2 , T_5 V_103 )
{
T_1 V_1346 = F_719 ( V_103 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1346 ] != ~ 0 )
V_1346 = F_722 ( V_1346 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1346 ] = V_103 ;
}
static T_1 F_724 ( struct V_1 * V_2 , T_5 V_103 )
{
int V_3 ;
T_1 V_1346 = F_719 ( V_103 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1346 ] != V_103 &&
V_2 -> V_5 . V_6 . V_7 [ V_1346 ] != ~ 0 ) ; V_3 ++ )
V_1346 = F_722 ( V_1346 ) ;
return V_1346 ;
}
bool F_725 ( struct V_1 * V_2 , T_5 V_103 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_724 ( V_2 , V_103 ) ] == V_103 ;
}
static void F_726 ( struct V_1 * V_2 , T_5 V_103 )
{
T_1 V_3 , V_813 , V_1347 ;
V_3 = V_813 = F_724 ( V_2 , V_103 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_813 = F_722 ( V_813 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_813 ] == ~ 0 )
return;
V_1347 = F_719 ( V_2 -> V_5 . V_6 . V_7 [ V_813 ] ) ;
} while ( ( V_3 <= V_813 ) ? ( V_3 < V_1347 && V_1347 <= V_813 ) : ( V_3 < V_1347 || V_1347 <= V_813 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_813 ] ;
V_3 = V_813 ;
}
}
static int F_727 ( struct V_1 * V_2 , T_1 V_197 )
{
return F_189 ( V_2 -> V_140 , & V_2 -> V_5 . V_6 . V_39 , & V_197 ,
sizeof( V_197 ) ) ;
}
void F_728 ( struct V_1 * V_2 ,
struct V_1342 * V_358 )
{
struct V_76 V_77 ;
F_729 ( V_358 -> V_5 . V_1348 , V_358 -> V_829 ) ;
F_723 ( V_2 , V_358 -> V_5 . V_103 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_390 & V_391 ) ||
( V_2 -> V_5 . V_6 . V_392 &&
V_74 -> V_89 ( V_2 ) == 0 ) )
F_32 ( V_1114 , V_2 ) ;
else if ( ! F_727 ( V_2 , V_1349 ) ) {
V_77 . V_42 = V_43 ;
V_77 . V_931 = true ;
V_77 . V_63 = 0 ;
V_77 . V_82 = false ;
V_77 . V_81 = V_358 -> V_5 . V_1348 ;
F_38 ( V_2 , & V_77 ) ;
}
}
void F_730 ( struct V_1 * V_2 ,
struct V_1342 * V_358 )
{
struct V_76 V_77 ;
F_731 ( V_358 -> V_5 . V_1348 , V_358 -> V_829 ) ;
if ( V_358 -> V_1343 )
V_358 -> V_5 . V_1348 = ~ 0 ;
else
F_726 ( V_2 , V_358 -> V_5 . V_103 ) ;
if ( ( V_2 -> V_5 . V_6 . V_390 & V_391 ) &&
! F_727 ( V_2 , V_1350 ) ) {
V_77 . V_42 = V_43 ;
V_77 . V_931 = true ;
V_77 . V_63 = 0 ;
V_77 . V_82 = false ;
V_77 . V_81 = V_358 -> V_5 . V_1348 ;
F_38 ( V_2 , & V_77 ) ;
}
V_2 -> V_5 . V_6 . V_1115 = false ;
V_2 -> V_5 . V_1041 = V_1155 ;
}
bool F_732 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_390 & V_391 ) )
return true ;
else
return ! F_268 ( V_2 ) &&
V_74 -> V_1082 ( V_2 ) ;
}
void F_733 ( struct V_140 * V_140 )
{
F_43 ( & V_140 -> V_5 . V_1351 ) ;
}
void F_734 ( struct V_140 * V_140 )
{
F_735 ( & V_140 -> V_5 . V_1351 ) ;
}
bool F_736 ( struct V_140 * V_140 )
{
return F_143 ( & V_140 -> V_5 . V_1351 ) ;
}
void F_737 ( struct V_140 * V_140 )
{
F_43 ( & V_140 -> V_5 . V_1289 ) ;
}
void F_738 ( struct V_140 * V_140 )
{
F_735 ( & V_140 -> V_5 . V_1289 ) ;
}
bool F_67 ( struct V_140 * V_140 )
{
return F_143 ( & V_140 -> V_5 . V_1289 ) ;
}
bool F_739 ( void )
{
return V_74 -> V_1352 != NULL ;
}
int F_740 ( struct V_1353 * V_1354 ,
struct V_1355 * V_1356 )
{
struct V_1357 * V_1358 =
F_4 ( V_1354 , struct V_1357 , V_1359 ) ;
V_1358 -> V_1360 = V_1356 ;
return V_74 -> V_1352 ( V_1358 -> V_140 ,
V_1356 -> V_596 , V_1358 -> V_1361 , 1 ) ;
}
void F_741 ( struct V_1353 * V_1354 ,
struct V_1355 * V_1356 )
{
int V_109 ;
struct V_1357 * V_1358 =
F_4 ( V_1354 , struct V_1357 , V_1359 ) ;
F_30 ( V_1358 -> V_1360 != V_1356 ) ;
V_1358 -> V_1360 = NULL ;
V_109 = V_74 -> V_1352 ( V_1358 -> V_140 , V_1356 -> V_596 , V_1358 -> V_1361 , 0 ) ;
if ( V_109 )
F_12 ( V_1362 L_31
L_32 , V_1358 -> V_1359 . V_1348 , V_109 ) ;
}
int F_742 ( struct V_140 * V_140 , unsigned int V_1363 ,
T_7 V_1364 , bool V_1365 )
{
if ( ! V_74 -> V_1352 )
return - V_580 ;
return V_74 -> V_1352 ( V_140 , V_1363 , V_1364 , V_1365 ) ;
}
bool F_743 ( void )
{
return V_1366 ;
}
