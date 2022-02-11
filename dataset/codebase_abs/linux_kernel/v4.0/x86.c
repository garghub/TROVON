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
T_2 V_22 ;
unsigned int V_23 = F_8 () ;
struct V_11 * V_24 = F_9 ( V_25 , V_23 ) ;
if ( V_10 >= V_15 . V_16 ) {
F_10 ( V_26 L_1 ) ;
return;
}
F_11 ( V_21 , & V_22 ) ;
V_24 -> V_14 [ V_10 ] . V_17 = V_22 ;
V_24 -> V_14 [ V_10 ] . V_18 = V_22 ;
}
void F_12 ( unsigned V_10 , T_1 V_21 )
{
F_13 ( V_10 >= V_27 ) ;
if ( V_10 >= V_15 . V_16 )
V_15 . V_16 = V_10 + 1 ;
V_15 . V_19 [ V_10 ] = V_21 ;
F_14 () ;
}
static void F_15 ( void )
{
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_15 . V_16 ; ++ V_3 )
F_7 ( V_3 , V_15 . V_19 [ V_3 ] ) ;
}
int F_16 ( unsigned V_10 , T_2 V_22 , T_2 V_28 )
{
unsigned int V_23 = F_8 () ;
struct V_11 * V_24 = F_9 ( V_25 , V_23 ) ;
int V_29 ;
if ( ( ( V_22 ^ V_24 -> V_14 [ V_10 ] . V_18 ) & V_28 ) == 0 )
return 0 ;
V_24 -> V_14 [ V_10 ] . V_18 = V_22 ;
V_29 = F_17 ( V_15 . V_19 [ V_10 ] , V_22 ) ;
if ( V_29 )
return 1 ;
if ( ! V_24 -> V_20 ) {
V_24 -> V_9 . V_30 = F_3 ;
F_18 ( & V_24 -> V_9 ) ;
V_24 -> V_20 = true ;
}
return 0 ;
}
static void F_19 ( void )
{
unsigned int V_23 = F_8 () ;
struct V_11 * V_24 = F_9 ( V_25 , V_23 ) ;
if ( V_24 -> V_20 )
F_3 ( & V_24 -> V_9 ) ;
}
T_2 F_20 ( struct V_1 * V_2 )
{
return V_2 -> V_5 . V_31 ;
}
int F_21 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
T_2 V_34 = V_2 -> V_5 . V_31 &
( V_35 | V_36 ) ;
T_2 V_37 = V_33 -> V_38 &
( V_35 | V_36 ) ;
T_2 V_39 = ( ( ~ 0ULL ) << F_22 ( V_2 ) ) |
0x2ff | ( F_23 ( V_2 ) ? 0 : V_36 ) ;
if ( ! V_33 -> V_40 &&
( ( V_33 -> V_38 & V_39 ) != 0 ||
V_37 == V_36 ||
( V_37 == V_35 &&
V_34 == ( V_35 | V_36 ) ) ||
( V_37 == ( V_35 | V_36 ) &&
V_34 == 0 ) ) )
return 1 ;
F_24 ( V_2 , V_33 -> V_38 ) ;
return 0 ;
}
T_3 T_4 void F_25 ( void )
{
F_26 () ;
}
static int F_27 ( int V_41 )
{
switch ( V_41 ) {
case V_42 :
return V_43 ;
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
return V_49 ;
default:
break;
}
return V_50 ;
}
static int F_28 ( int V_41 )
{
unsigned int V_28 ;
if ( F_29 ( V_41 > 31 || V_41 == V_51 ) )
return V_52 ;
V_28 = 1 << V_41 ;
if ( V_28 & ( ( 1 << V_53 ) | ( 1 << V_54 ) | ( 1 << V_55 ) ) )
return V_56 ;
if ( V_28 & ( ( 1 << V_57 ) | ( 1 << V_58 ) ) )
return V_59 ;
return V_60 ;
}
static void F_30 ( struct V_1 * V_2 ,
unsigned V_16 , bool V_61 , T_1 V_62 ,
bool V_63 )
{
T_1 V_64 ;
int V_65 , V_66 ;
F_31 ( V_67 , V_2 ) ;
if ( ! V_2 -> V_5 . V_68 . V_69 ) {
V_70:
if ( V_61 && ! F_32 ( V_2 ) )
V_61 = false ;
V_2 -> V_5 . V_68 . V_69 = true ;
V_2 -> V_5 . V_68 . V_71 = V_61 ;
V_2 -> V_5 . V_68 . V_16 = V_16 ;
V_2 -> V_5 . V_68 . V_62 = V_62 ;
V_2 -> V_5 . V_68 . V_63 = V_63 ;
return;
}
V_64 = V_2 -> V_5 . V_68 . V_16 ;
if ( V_64 == V_57 ) {
F_31 ( V_72 , V_2 ) ;
return;
}
V_65 = F_27 ( V_64 ) ;
V_66 = F_27 ( V_16 ) ;
if ( ( V_65 == V_49 && V_66 == V_49 )
|| ( V_65 == V_43 && V_66 != V_50 ) ) {
V_2 -> V_5 . V_68 . V_69 = true ;
V_2 -> V_5 . V_68 . V_71 = true ;
V_2 -> V_5 . V_68 . V_16 = V_57 ;
V_2 -> V_5 . V_68 . V_62 = 0 ;
} else
goto V_70;
}
void F_33 ( struct V_1 * V_2 , unsigned V_16 )
{
F_30 ( V_2 , V_16 , false , 0 , false ) ;
}
void F_34 ( struct V_1 * V_2 , unsigned V_16 )
{
F_30 ( V_2 , V_16 , false , 0 , true ) ;
}
void F_35 ( struct V_1 * V_2 , int V_29 )
{
if ( V_29 )
F_36 ( V_2 , 0 ) ;
else
V_73 -> V_74 ( V_2 ) ;
}
void F_37 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
++ V_2 -> V_77 . V_78 ;
V_2 -> V_5 . V_79 = V_76 -> V_80 ;
F_38 ( V_2 , V_42 , V_76 -> V_62 ) ;
}
static bool F_39 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
if ( F_40 ( V_2 ) && ! V_76 -> V_81 )
V_2 -> V_5 . V_82 . V_83 ( V_2 , V_76 ) ;
else
V_2 -> V_5 . V_84 . V_83 ( V_2 , V_76 ) ;
return V_76 -> V_81 ;
}
void F_41 ( struct V_1 * V_2 )
{
F_42 ( & V_2 -> V_5 . V_85 ) ;
F_31 ( V_86 , V_2 ) ;
}
void F_38 ( struct V_1 * V_2 , unsigned V_16 , T_1 V_62 )
{
F_30 ( V_2 , V_16 , true , V_62 , false ) ;
}
void F_43 ( struct V_1 * V_2 , unsigned V_16 , T_1 V_62 )
{
F_30 ( V_2 , V_16 , true , V_62 , true ) ;
}
bool F_44 ( struct V_1 * V_2 , int V_87 )
{
if ( V_73 -> V_88 ( V_2 ) <= V_87 )
return true ;
F_38 ( V_2 , V_48 , 0 ) ;
return false ;
}
bool F_45 ( struct V_1 * V_2 , int V_89 )
{
if ( ( V_89 != 4 && V_89 != 5 ) || ! F_46 ( V_2 , V_90 ) )
return true ;
F_33 ( V_2 , V_91 ) ;
return false ;
}
int F_47 ( struct V_1 * V_2 , struct V_92 * V_84 ,
T_5 V_93 , void * V_38 , int V_94 , int V_95 ,
T_1 V_96 )
{
struct V_75 V_68 ;
T_5 V_97 ;
T_6 V_98 ;
V_98 = F_48 ( V_93 ) ;
V_97 = V_84 -> V_99 ( V_2 , V_98 , V_96 , & V_68 ) ;
if ( V_97 == V_100 )
return - V_101 ;
V_97 = F_49 ( V_97 ) ;
return F_50 ( V_2 -> V_102 , V_97 , V_38 , V_94 , V_95 ) ;
}
static int F_51 ( struct V_1 * V_2 , T_5 V_103 ,
void * V_38 , int V_94 , int V_95 , T_1 V_96 )
{
return F_47 ( V_2 , V_2 -> V_5 . V_104 , V_103 ,
V_38 , V_94 , V_95 , V_96 ) ;
}
int F_52 ( struct V_1 * V_2 , struct V_92 * V_84 , unsigned long V_105 )
{
T_5 V_106 = V_105 >> V_107 ;
unsigned V_94 = ( ( V_105 & ( V_108 - 1 ) ) >> 5 ) << 2 ;
int V_3 ;
int V_109 ;
T_2 V_110 [ F_53 ( V_84 -> V_111 ) ] ;
V_109 = F_47 ( V_2 , V_84 , V_106 , V_110 ,
V_94 * sizeof( T_2 ) , sizeof( V_110 ) ,
V_112 | V_113 ) ;
if ( V_109 < 0 ) {
V_109 = 0 ;
goto V_114;
}
for ( V_3 = 0 ; V_3 < F_53 ( V_110 ) ; ++ V_3 ) {
if ( F_54 ( V_110 [ V_3 ] ) &&
( V_110 [ V_3 ] & V_2 -> V_5 . V_84 . V_115 [ 0 ] [ 2 ] ) ) {
V_109 = 0 ;
goto V_114;
}
}
V_109 = 1 ;
memcpy ( V_84 -> V_111 , V_110 , sizeof( V_84 -> V_111 ) ) ;
F_55 ( V_116 ,
( unsigned long * ) & V_2 -> V_5 . V_117 ) ;
F_55 ( V_116 ,
( unsigned long * ) & V_2 -> V_5 . V_118 ) ;
V_114:
return V_109 ;
}
static bool F_56 ( struct V_1 * V_2 )
{
T_2 V_110 [ F_53 ( V_2 -> V_5 . V_104 -> V_111 ) ] ;
bool V_119 = true ;
int V_94 ;
T_5 V_103 ;
int V_120 ;
if ( F_57 ( V_2 ) || ! F_58 ( V_2 ) )
return false ;
if ( ! F_59 ( V_116 ,
( unsigned long * ) & V_2 -> V_5 . V_117 ) )
return true ;
V_103 = ( F_60 ( V_2 ) & ~ 31u ) >> V_107 ;
V_94 = ( F_60 ( V_2 ) & ~ 31u ) & ( V_108 - 1 ) ;
V_120 = F_51 ( V_2 , V_103 , V_110 , V_94 , sizeof( V_110 ) ,
V_112 | V_113 ) ;
if ( V_120 < 0 )
goto V_114;
V_119 = memcmp ( V_110 , V_2 -> V_5 . V_104 -> V_111 , sizeof( V_110 ) ) != 0 ;
V_114:
return V_119 ;
}
int F_61 ( struct V_1 * V_2 , unsigned long V_121 )
{
unsigned long V_122 = F_62 ( V_2 ) ;
unsigned long V_123 = V_124 | V_125 |
V_126 | V_127 ;
V_121 |= V_128 ;
#ifdef F_63
if ( V_121 & 0xffffffff00000000UL )
return 1 ;
#endif
V_121 &= ~ V_129 ;
if ( ( V_121 & V_127 ) && ! ( V_121 & V_126 ) )
return 1 ;
if ( ( V_121 & V_124 ) && ! ( V_121 & V_130 ) )
return 1 ;
if ( ! F_64 ( V_2 ) && ( V_121 & V_124 ) ) {
#ifdef F_63
if ( ( V_2 -> V_5 . V_131 & V_132 ) ) {
int V_133 , V_134 ;
if ( ! F_58 ( V_2 ) )
return 1 ;
V_73 -> V_135 ( V_2 , & V_133 , & V_134 ) ;
if ( V_134 )
return 1 ;
} else
#endif
if ( F_58 ( V_2 ) && ! F_52 ( V_2 , V_2 -> V_5 . V_104 ,
F_60 ( V_2 ) ) )
return 1 ;
}
if ( ! ( V_121 & V_124 ) && F_46 ( V_2 , V_136 ) )
return 1 ;
V_73 -> V_137 ( V_2 , V_121 ) ;
if ( ( V_121 ^ V_122 ) & V_124 ) {
F_65 ( V_2 ) ;
F_1 ( V_2 ) ;
}
if ( ( V_121 ^ V_122 ) & V_123 )
F_66 ( V_2 ) ;
return 0 ;
}
void F_67 ( struct V_1 * V_2 , unsigned long V_138 )
{
( void ) F_61 ( V_2 , F_68 ( V_2 , ~ 0x0eul ) | ( V_138 & 0x0f ) ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
if ( F_46 ( V_2 , V_139 ) &&
! V_2 -> V_140 ) {
F_70 ( V_141 , V_2 -> V_5 . V_142 ) ;
V_2 -> V_140 = 1 ;
}
}
static void F_71 ( struct V_1 * V_2 )
{
if ( V_2 -> V_140 ) {
if ( V_2 -> V_5 . V_142 != V_143 )
F_70 ( V_141 , V_143 ) ;
V_2 -> V_140 = 0 ;
}
}
static int F_72 ( struct V_1 * V_2 , T_1 V_144 , T_2 V_145 )
{
T_2 V_142 = V_145 ;
T_2 V_146 = V_2 -> V_5 . V_142 ;
T_2 V_147 ;
if ( V_144 != V_141 )
return 1 ;
if ( ! ( V_142 & V_148 ) )
return 1 ;
if ( ( V_142 & V_149 ) && ! ( V_142 & V_150 ) )
return 1 ;
V_147 = V_2 -> V_5 . V_151 | V_148 ;
if ( V_142 & ~ V_147 )
return 1 ;
if ( ( ! ( V_142 & V_152 ) ) != ( ! ( V_142 & V_153 ) ) )
return 1 ;
if ( V_142 & V_154 ) {
if ( ! ( V_142 & V_149 ) )
return 1 ;
if ( ( V_142 & V_154 ) != V_154 )
return 1 ;
}
F_71 ( V_2 ) ;
V_2 -> V_5 . V_142 = V_142 ;
if ( ( V_142 ^ V_146 ) & V_155 )
F_73 ( V_2 ) ;
return 0 ;
}
int F_74 ( struct V_1 * V_2 , T_1 V_144 , T_2 V_145 )
{
if ( V_73 -> V_88 ( V_2 ) != 0 ||
F_72 ( V_2 , V_144 , V_145 ) ) {
F_36 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_75 ( struct V_1 * V_2 , unsigned long V_156 )
{
unsigned long V_157 = F_76 ( V_2 ) ;
unsigned long V_158 = V_159 | V_160 |
V_161 | V_162 ;
if ( V_156 & V_163 )
return 1 ;
if ( ! F_77 ( V_2 ) && ( V_156 & V_139 ) )
return 1 ;
if ( ! F_78 ( V_2 ) && ( V_156 & V_162 ) )
return 1 ;
if ( ! F_79 ( V_2 ) && ( V_156 & V_164 ) )
return 1 ;
if ( ! F_80 ( V_2 ) && ( V_156 & V_165 ) )
return 1 ;
if ( F_57 ( V_2 ) ) {
if ( ! ( V_156 & V_161 ) )
return 1 ;
} else if ( F_64 ( V_2 ) && ( V_156 & V_161 )
&& ( ( V_156 ^ V_157 ) & V_158 )
&& ! F_52 ( V_2 , V_2 -> V_5 . V_104 ,
F_60 ( V_2 ) ) )
return 1 ;
if ( ( V_156 & V_136 ) && ! ( V_157 & V_136 ) ) {
if ( ! F_81 ( V_2 ) )
return 1 ;
if ( ( F_60 ( V_2 ) & V_166 ) || ! F_57 ( V_2 ) )
return 1 ;
}
if ( V_73 -> V_167 ( V_2 , V_156 ) )
return 1 ;
if ( ( ( V_156 ^ V_157 ) & V_158 ) ||
( ! ( V_156 & V_136 ) && ( V_157 & V_136 ) ) )
F_66 ( V_2 ) ;
if ( ( V_156 ^ V_157 ) & V_164 )
F_82 ( V_2 , V_2 -> V_5 . V_104 , false ) ;
if ( ( V_156 ^ V_157 ) & V_139 )
F_73 ( V_2 ) ;
return 0 ;
}
int F_83 ( struct V_1 * V_2 , unsigned long V_105 )
{
#ifdef F_63
V_105 &= ~ V_168 ;
#endif
if ( V_105 == F_60 ( V_2 ) && ! F_56 ( V_2 ) ) {
F_84 ( V_2 ) ;
F_31 ( V_169 , V_2 ) ;
return 0 ;
}
if ( F_57 ( V_2 ) ) {
if ( V_105 & V_170 )
return 1 ;
} else if ( F_58 ( V_2 ) && F_64 ( V_2 ) &&
! F_52 ( V_2 , V_2 -> V_5 . V_104 , V_105 ) )
return 1 ;
V_2 -> V_5 . V_105 = V_105 ;
F_55 ( V_171 , ( V_172 * ) & V_2 -> V_5 . V_117 ) ;
F_85 ( V_2 ) ;
return 0 ;
}
int F_86 ( struct V_1 * V_2 , unsigned long V_173 )
{
if ( V_173 & V_174 )
return 1 ;
if ( F_87 ( V_2 -> V_102 ) )
F_88 ( V_2 , V_173 ) ;
else
V_2 -> V_5 . V_173 = V_173 ;
return 0 ;
}
unsigned long F_89 ( struct V_1 * V_2 )
{
if ( F_87 ( V_2 -> V_102 ) )
return F_90 ( V_2 ) ;
else
return V_2 -> V_5 . V_173 ;
}
static void F_91 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_175 & V_176 ) )
V_73 -> V_177 ( V_2 , V_2 -> V_5 . V_178 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
unsigned long V_179 ;
if ( V_2 -> V_175 & V_176 )
V_179 = V_2 -> V_5 . V_180 ;
else
V_179 = V_2 -> V_5 . V_179 ;
V_73 -> V_181 ( V_2 , V_179 ) ;
V_2 -> V_5 . V_182 &= ~ V_183 ;
if ( V_179 & V_184 )
V_2 -> V_5 . V_182 |= V_183 ;
}
static T_2 F_93 ( struct V_1 * V_2 )
{
T_2 V_185 = V_186 ;
if ( ! F_94 ( V_2 ) )
V_185 |= V_187 ;
return V_185 ;
}
static int F_95 ( struct V_1 * V_2 , int V_89 , unsigned long V_188 )
{
switch ( V_89 ) {
case 0 ... 3 :
V_2 -> V_5 . V_189 [ V_89 ] = V_188 ;
if ( ! ( V_2 -> V_175 & V_176 ) )
V_2 -> V_5 . V_190 [ V_89 ] = V_188 ;
break;
case 4 :
case 6 :
if ( V_188 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_178 = ( V_188 & V_191 ) | F_93 ( V_2 ) ;
F_91 ( V_2 ) ;
break;
case 5 :
default:
if ( V_188 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_179 = ( V_188 & V_192 ) | V_193 ;
F_92 ( V_2 ) ;
break;
}
return 0 ;
}
int F_96 ( struct V_1 * V_2 , int V_89 , unsigned long V_188 )
{
if ( F_95 ( V_2 , V_89 , V_188 ) ) {
F_36 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_97 ( struct V_1 * V_2 , int V_89 , unsigned long * V_188 )
{
switch ( V_89 ) {
case 0 ... 3 :
* V_188 = V_2 -> V_5 . V_189 [ V_89 ] ;
break;
case 4 :
case 6 :
if ( V_2 -> V_175 & V_176 )
* V_188 = V_2 -> V_5 . V_178 ;
else
* V_188 = V_73 -> V_194 ( V_2 ) ;
break;
case 5 :
default:
* V_188 = V_2 -> V_5 . V_179 ;
break;
}
return 0 ;
}
bool F_98 ( struct V_1 * V_2 )
{
T_1 V_195 = F_99 ( V_2 , V_196 ) ;
T_2 V_38 ;
int V_29 ;
V_29 = F_100 ( V_2 , V_195 , & V_38 ) ;
if ( V_29 )
return V_29 ;
F_101 ( V_2 , V_197 , ( T_1 ) V_38 ) ;
F_101 ( V_2 , V_198 , V_38 >> 32 ) ;
return V_29 ;
}
bool F_102 ( struct V_1 * V_2 , T_2 V_131 )
{
if ( V_131 & V_199 )
return false ;
if ( V_131 & V_200 ) {
struct V_201 * V_202 ;
V_202 = F_103 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_202 || ! ( V_202 -> V_203 & F_104 ( V_204 ) ) )
return false ;
}
if ( V_131 & V_205 ) {
struct V_201 * V_202 ;
V_202 = F_103 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_202 || ! ( V_202 -> V_195 & F_104 ( V_206 ) ) )
return false ;
}
return true ;
}
static int F_105 ( struct V_1 * V_2 , T_2 V_131 )
{
T_2 V_207 = V_2 -> V_5 . V_131 ;
if ( ! F_102 ( V_2 , V_131 ) )
return 1 ;
if ( F_64 ( V_2 )
&& ( V_2 -> V_5 . V_131 & V_132 ) != ( V_131 & V_132 ) )
return 1 ;
V_131 &= ~ V_208 ;
V_131 |= V_2 -> V_5 . V_131 & V_208 ;
V_73 -> F_105 ( V_2 , V_131 ) ;
if ( ( V_131 ^ V_207 ) & V_209 )
F_66 ( V_2 ) ;
return 0 ;
}
void F_106 ( T_2 V_28 )
{
V_199 &= ~ V_28 ;
}
int F_107 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
switch ( V_21 -> V_144 ) {
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
if ( F_108 ( V_21 -> V_38 ) )
return 1 ;
break;
case V_215 :
case V_216 :
V_21 -> V_38 = F_109 ( V_21 -> V_38 ) ;
}
return V_73 -> V_217 ( V_2 , V_21 ) ;
}
static int F_110 ( struct V_1 * V_2 , unsigned V_144 , T_2 * V_38 )
{
struct V_32 V_21 ;
V_21 . V_38 = * V_38 ;
V_21 . V_144 = V_144 ;
V_21 . V_40 = true ;
return F_107 ( V_2 , & V_21 ) ;
}
static void F_111 ( struct V_218 * V_219 )
{
struct V_220 * V_221 = & V_220 ;
T_2 V_222 ;
V_222 = F_112 ( F_113 ( V_219 -> V_223 . V_224 , V_219 -> V_225 ) ) ;
F_114 ( & V_221 -> V_226 ) ;
V_221 -> clock . V_227 = V_219 -> V_223 . clock -> V_228 . V_227 ;
V_221 -> clock . V_229 = V_219 -> V_223 . V_229 ;
V_221 -> clock . V_28 = V_219 -> V_223 . V_28 ;
V_221 -> clock . V_230 = V_219 -> V_223 . V_230 ;
V_221 -> clock . V_231 = V_219 -> V_223 . V_231 ;
V_221 -> V_222 = V_222 ;
V_221 -> V_232 = V_219 -> V_223 . V_233 ;
F_115 ( & V_221 -> V_226 ) ;
}
void F_116 ( struct V_1 * V_2 )
{
F_31 ( V_234 , V_2 ) ;
}
static void F_117 ( struct V_102 * V_102 , T_6 V_235 )
{
int V_236 ;
int V_120 ;
struct V_237 V_238 ;
struct V_239 V_240 ;
if ( ! V_235 )
return;
V_120 = F_118 ( V_102 , V_235 , & V_236 , sizeof( V_236 ) ) ;
if ( V_120 )
return;
if ( V_236 & 1 )
++ V_236 ;
++ V_236 ;
F_119 ( V_102 , V_235 , & V_236 , sizeof( V_236 ) ) ;
F_120 ( & V_240 ) ;
if ( V_102 -> V_5 . V_241 ) {
struct V_239 V_242 = F_121 ( V_102 -> V_5 . V_241 ) ;
V_240 = F_122 ( V_240 , V_242 ) ;
}
V_238 . V_243 = V_240 . V_244 ;
V_238 . V_245 = V_240 . V_246 ;
V_238 . V_236 = V_236 ;
F_119 ( V_102 , V_235 , & V_238 , sizeof( V_238 ) ) ;
V_236 ++ ;
F_119 ( V_102 , V_235 , & V_236 , sizeof( V_236 ) ) ;
}
static T_7 F_123 ( T_7 V_247 , T_7 V_248 )
{
T_7 V_249 , V_250 ;
__asm__ ( "divl %4"
: "=a" (quotient), "=d" (remainder)
: "0" (0), "1" (dividend), "r" (divisor) );
return V_249 ;
}
static void F_124 ( T_7 V_251 , T_7 V_252 ,
T_8 * V_253 , T_1 * V_254 )
{
T_9 V_255 ;
T_10 V_231 = 0 ;
T_9 V_256 ;
T_7 V_257 ;
V_256 = V_252 * 1000LL ;
V_255 = V_251 * 1000LL ;
while ( V_256 > V_255 * 2 || V_256 & 0xffffffff00000000ULL ) {
V_256 >>= 1 ;
V_231 -- ;
}
V_257 = ( T_7 ) V_256 ;
while ( V_257 <= V_255 || V_255 & 0xffffffff00000000ULL ) {
if ( V_255 & 0xffffffff00000000ULL || V_257 & 0x80000000 )
V_255 >>= 1 ;
else
V_257 <<= 1 ;
V_231 ++ ;
}
* V_253 = V_231 ;
* V_254 = F_123 ( V_255 , V_257 ) ;
F_125 ( L_2 ,
V_258 , V_252 , V_251 , V_231 , * V_254 ) ;
}
static inline T_2 F_126 ( void )
{
return F_127 () ;
}
static inline T_2 F_128 ( struct V_1 * V_2 , T_2 V_245 )
{
return F_129 ( V_245 , V_2 -> V_5 . V_259 ,
V_2 -> V_5 . V_260 ) ;
}
static T_1 F_130 ( T_1 V_261 , T_11 V_262 )
{
T_2 V_263 = ( T_2 ) V_261 * ( 1000000 + V_262 ) ;
F_131 ( V_263 , 1000000 ) ;
return V_263 ;
}
static void F_132 ( struct V_1 * V_2 , T_1 V_264 )
{
T_1 V_265 , V_266 ;
int V_267 = 0 ;
if ( V_264 == 0 )
return;
F_124 ( V_264 , V_268 / 1000 ,
& V_2 -> V_5 . V_260 ,
& V_2 -> V_5 . V_259 ) ;
V_2 -> V_5 . V_269 = V_264 ;
V_265 = F_130 ( V_270 , - V_271 ) ;
V_266 = F_130 ( V_270 , V_271 ) ;
if ( V_264 < V_265 || V_264 > V_266 ) {
F_125 ( L_3 , V_264 , V_265 , V_266 ) ;
V_267 = 1 ;
}
V_73 -> V_272 ( V_2 , V_264 , V_267 ) ;
}
static T_2 F_133 ( struct V_1 * V_2 , T_12 V_273 )
{
T_2 V_274 = F_129 ( V_273 - V_2 -> V_5 . V_275 ,
V_2 -> V_5 . V_259 ,
V_2 -> V_5 . V_260 ) ;
V_274 += V_2 -> V_5 . V_276 ;
return V_274 ;
}
static void F_134 ( struct V_1 * V_2 )
{
#ifdef F_63
bool V_277 ;
struct V_278 * V_279 = & V_2 -> V_102 -> V_5 ;
struct V_220 * V_280 = & V_220 ;
V_277 = ( V_279 -> V_281 + 1 ==
F_135 ( & V_2 -> V_102 -> V_282 ) ) ;
if ( V_279 -> V_283 ||
( V_280 -> clock . V_227 == V_284 && V_277 ) )
F_31 ( V_285 , V_2 ) ;
F_136 ( V_2 -> V_286 , V_279 -> V_281 ,
F_135 ( & V_2 -> V_102 -> V_282 ) ,
V_279 -> V_283 , V_280 -> clock . V_227 ) ;
#endif
}
static void F_137 ( struct V_1 * V_2 , T_12 V_94 )
{
T_2 V_287 = V_73 -> V_288 ( V_2 ) ;
V_2 -> V_5 . V_289 += V_94 - V_287 ;
}
void F_138 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
struct V_102 * V_102 = V_2 -> V_102 ;
T_2 V_94 , V_290 , V_291 ;
unsigned long V_292 ;
T_12 V_293 ;
bool V_294 ;
bool V_295 ;
T_2 V_38 = V_21 -> V_38 ;
F_139 ( & V_102 -> V_5 . V_296 , V_292 ) ;
V_94 = V_73 -> V_297 ( V_2 , V_38 ) ;
V_290 = F_126 () ;
V_291 = V_290 - V_102 -> V_5 . V_298 ;
if ( V_2 -> V_5 . V_269 ) {
int V_299 = 0 ;
V_293 = V_38 - V_102 -> V_5 . V_300 ;
#ifdef F_63
V_293 = ( V_293 * 1000 ) / V_2 -> V_5 . V_269 ;
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
F_131 ( V_291 , 1000 ) ;
V_293 -= V_291 ;
if ( V_293 < 0 )
V_293 = - V_293 ;
if ( V_299 )
V_293 = V_301 ;
} else
V_293 = V_301 ;
if ( V_293 < V_301 &&
V_2 -> V_5 . V_269 == V_102 -> V_5 . V_302 ) {
if ( ! F_140 () ) {
V_94 = V_102 -> V_5 . V_303 ;
F_125 ( L_4 , V_38 ) ;
} else {
T_2 V_304 = F_128 ( V_2 , V_291 ) ;
V_38 += V_304 ;
V_94 = V_73 -> V_297 ( V_2 , V_38 ) ;
F_125 ( L_5 , V_304 ) ;
}
V_294 = true ;
V_295 = ( V_2 -> V_5 . V_305 == V_102 -> V_5 . V_306 ) ;
} else {
V_102 -> V_5 . V_306 ++ ;
V_102 -> V_5 . V_307 = V_290 ;
V_102 -> V_5 . V_308 = V_38 ;
V_102 -> V_5 . V_303 = V_94 ;
V_294 = false ;
F_125 ( L_6 ,
V_102 -> V_5 . V_306 , V_38 ) ;
}
V_102 -> V_5 . V_298 = V_290 ;
V_102 -> V_5 . V_300 = V_38 ;
V_102 -> V_5 . V_302 = V_2 -> V_5 . V_269 ;
V_2 -> V_5 . V_309 = V_38 ;
V_2 -> V_5 . V_305 = V_102 -> V_5 . V_306 ;
V_2 -> V_5 . V_275 = V_102 -> V_5 . V_307 ;
V_2 -> V_5 . V_276 = V_102 -> V_5 . V_308 ;
if ( F_141 ( V_2 ) && ! V_21 -> V_40 )
F_137 ( V_2 , V_94 ) ;
V_73 -> V_310 ( V_2 , V_94 ) ;
F_142 ( & V_102 -> V_5 . V_296 , V_292 ) ;
F_143 ( & V_102 -> V_5 . V_311 ) ;
if ( ! V_294 ) {
V_102 -> V_5 . V_281 = 0 ;
} else if ( ! V_295 ) {
V_102 -> V_5 . V_281 ++ ;
}
F_134 ( V_2 ) ;
F_144 ( & V_102 -> V_5 . V_311 ) ;
}
static T_13 F_145 ( void )
{
T_13 V_109 ;
T_2 V_312 ;
F_146 () ;
V_109 = ( T_13 ) F_147 () ;
V_312 = V_220 . clock . V_229 ;
if ( F_148 ( V_109 >= V_312 ) )
return V_109 ;
asm volatile ("");
return V_312 ;
}
static inline T_2 F_149 ( T_13 * V_313 )
{
long V_263 ;
struct V_220 * V_280 = & V_220 ;
* V_313 = F_145 () ;
V_263 = ( * V_313 - V_280 -> clock . V_229 ) & V_280 -> clock . V_28 ;
return V_263 * V_280 -> clock . V_230 ;
}
static int F_150 ( T_12 * V_314 , T_13 * V_313 )
{
struct V_220 * V_280 = & V_220 ;
unsigned long V_226 ;
int V_315 ;
T_2 V_290 ;
do {
V_226 = F_151 ( & V_280 -> V_226 ) ;
V_315 = V_280 -> clock . V_227 ;
V_290 = V_280 -> V_232 ;
V_290 += F_149 ( V_313 ) ;
V_290 >>= V_280 -> clock . V_231 ;
V_290 += V_280 -> V_222 ;
} while ( F_152 ( F_153 ( & V_280 -> V_226 , V_226 ) ) );
* V_314 = V_290 ;
return V_315 ;
}
static bool F_154 ( T_12 * V_273 , T_13 * V_313 )
{
if ( V_220 . clock . V_227 != V_284 )
return false ;
return F_150 ( V_273 , V_313 ) == V_284 ;
}
static void F_155 ( struct V_102 * V_102 )
{
#ifdef F_63
struct V_278 * V_279 = & V_102 -> V_5 ;
int V_227 ;
bool V_316 , V_277 ;
V_277 = ( V_279 -> V_281 + 1 ==
F_135 ( & V_102 -> V_282 ) ) ;
V_316 = F_154 (
& V_279 -> V_317 ,
& V_279 -> V_318 ) ;
V_279 -> V_283 = V_316 && V_277
&& ! V_319
&& ! V_279 -> V_320 ;
if ( V_279 -> V_283 )
F_156 ( & V_321 , 1 ) ;
V_227 = V_220 . clock . V_227 ;
F_157 ( V_279 -> V_283 , V_227 ,
V_277 ) ;
#endif
}
static void F_158 ( struct V_102 * V_102 )
{
#ifdef F_63
int V_3 ;
struct V_1 * V_2 ;
struct V_278 * V_279 = & V_102 -> V_5 ;
F_143 ( & V_279 -> V_311 ) ;
F_159 ( V_102 ) ;
F_155 ( V_102 ) ;
F_160 (i, vcpu, kvm)
F_31 ( V_322 , V_2 ) ;
F_160 (i, vcpu, kvm)
F_161 ( V_323 , & V_2 -> V_324 ) ;
F_144 ( & V_279 -> V_311 ) ;
#endif
}
static int F_162 ( struct V_1 * V_263 )
{
unsigned long V_292 , V_264 ;
struct V_325 * V_2 = & V_263 -> V_5 ;
struct V_278 * V_279 = & V_263 -> V_102 -> V_5 ;
T_12 V_273 ;
T_2 V_326 , V_327 ;
struct V_328 V_329 ;
T_14 V_330 ;
bool V_283 ;
V_273 = 0 ;
V_327 = 0 ;
F_143 ( & V_279 -> V_311 ) ;
V_283 = V_279 -> V_283 ;
if ( V_283 ) {
V_327 = V_279 -> V_318 ;
V_273 = V_279 -> V_317 ;
}
F_144 ( & V_279 -> V_311 ) ;
F_163 ( V_292 ) ;
V_264 = F_164 ( V_331 ) ;
if ( F_152 ( V_264 == 0 ) ) {
F_165 ( V_292 ) ;
F_31 ( V_322 , V_263 ) ;
return 1 ;
}
if ( ! V_283 ) {
V_327 = F_166 () ;
V_273 = F_126 () ;
}
V_326 = V_73 -> V_332 ( V_263 , V_327 ) ;
if ( V_2 -> V_333 ) {
T_2 V_274 = F_133 ( V_263 , V_273 ) ;
if ( V_274 > V_326 ) {
F_167 ( V_263 , V_274 - V_326 ) ;
V_326 = V_274 ;
}
}
F_165 ( V_292 ) ;
if ( ! V_2 -> V_334 )
return 0 ;
if ( F_152 ( V_2 -> V_335 != V_264 ) ) {
F_124 ( V_268 / 1000 , V_264 ,
& V_2 -> V_336 . V_337 ,
& V_2 -> V_336 . V_338 ) ;
V_2 -> V_335 = V_264 ;
}
V_2 -> V_336 . V_326 = V_326 ;
V_2 -> V_336 . V_339 = V_273 + V_263 -> V_102 -> V_5 . V_241 ;
V_2 -> V_309 = V_326 ;
if ( F_152 ( F_168 ( V_263 -> V_102 , & V_2 -> V_340 ,
& V_329 , sizeof( V_329 ) ) ) )
return 0 ;
V_2 -> V_336 . V_236 = V_329 . V_236 + 2 ;
V_330 = ( V_329 . V_292 & V_341 ) ;
if ( V_2 -> V_342 ) {
V_330 |= V_341 ;
V_2 -> V_342 = false ;
}
if ( V_283 )
V_330 |= V_343 ;
V_2 -> V_336 . V_292 = V_330 ;
F_169 ( V_263 -> V_286 , & V_2 -> V_336 ) ;
F_170 ( V_263 -> V_102 , & V_2 -> V_340 ,
& V_2 -> V_336 ,
sizeof( V_2 -> V_336 ) ) ;
return 0 ;
}
static void F_171 ( struct V_344 * V_345 )
{
int V_3 ;
struct V_346 * V_347 = F_172 ( V_345 ) ;
struct V_278 * V_279 = F_4 ( V_347 , struct V_278 ,
V_348 ) ;
struct V_102 * V_102 = F_4 ( V_279 , struct V_102 , V_5 ) ;
struct V_1 * V_2 ;
F_160 (i, vcpu, kvm) {
F_31 ( V_322 , V_2 ) ;
F_173 ( V_2 ) ;
}
}
static void F_174 ( struct V_1 * V_263 )
{
struct V_102 * V_102 = V_263 -> V_102 ;
F_31 ( V_322 , V_263 ) ;
F_175 ( & V_102 -> V_5 . V_348 ,
V_349 ) ;
}
static void F_176 ( struct V_344 * V_345 )
{
struct V_346 * V_347 = F_172 ( V_345 ) ;
struct V_278 * V_279 = F_4 ( V_347 , struct V_278 ,
V_350 ) ;
struct V_102 * V_102 = F_4 ( V_279 , struct V_102 , V_5 ) ;
F_175 ( & V_102 -> V_5 . V_348 , 0 ) ;
F_175 ( & V_102 -> V_5 . V_350 ,
V_351 ) ;
}
static bool F_177 ( unsigned V_21 )
{
switch ( V_21 ) {
case 0x200 ... 0x200 + 2 * V_352 - 1 :
case V_353 :
case V_354 :
case V_355 :
case V_356 :
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
case V_363 :
case V_364 :
case V_365 :
return true ;
case 0x2f8 :
return true ;
}
return false ;
}
static bool F_178 ( unsigned V_314 )
{
return V_314 < 8 && ( 1 << V_314 ) & 0xf3 ;
}
static bool F_179 ( unsigned V_314 )
{
return V_314 < 8 && ( 1 << V_314 ) & 0x73 ;
}
bool F_180 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
int V_3 ;
T_2 V_28 ;
if ( ! F_177 ( V_21 ) )
return false ;
if ( V_21 == V_365 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_178 ( ( V_38 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
} else if ( V_21 == V_364 ) {
if ( V_38 & ~ 0xcff )
return false ;
return F_179 ( V_38 & 0xff ) ;
} else if ( V_21 >= V_353 && V_21 <= V_363 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_179 ( ( V_38 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
}
F_29 ( ! ( V_21 >= 0x200 && V_21 < 0x200 + 2 * V_352 ) ) ;
V_28 = ( ~ 0ULL ) << F_22 ( V_2 ) ;
if ( ( V_21 & 1 ) == 0 ) {
if ( ! F_179 ( V_38 & 0xff ) )
return false ;
V_28 |= 0xf00 ;
} else
V_28 |= 0x7ff ;
if ( V_38 & V_28 ) {
F_36 ( V_2 , 0 ) ;
return false ;
}
return true ;
}
static int F_181 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
T_2 * V_366 = ( T_2 * ) & V_2 -> V_5 . V_367 . V_368 ;
if ( ! F_180 ( V_2 , V_21 , V_38 ) )
return 1 ;
if ( V_21 == V_364 ) {
V_2 -> V_5 . V_367 . V_369 = V_38 ;
V_2 -> V_5 . V_367 . V_370 = ( V_38 & 0xc00 ) >> 10 ;
} else if ( V_21 == V_353 )
V_366 [ 0 ] = V_38 ;
else if ( V_21 == V_354 || V_21 == V_355 )
V_366 [ 1 + V_21 - V_354 ] = V_38 ;
else if ( V_21 >= V_356 && V_21 <= V_363 )
V_366 [ 3 + V_21 - V_356 ] = V_38 ;
else if ( V_21 == V_365 )
V_2 -> V_5 . V_371 = V_38 ;
else {
int V_372 , V_373 ;
T_2 * V_374 ;
V_372 = ( V_21 - 0x200 ) / 2 ;
V_373 = V_21 - 0x200 - 2 * V_372 ;
if ( ! V_373 )
V_374 =
( T_2 * ) & V_2 -> V_5 . V_367 . V_375 [ V_372 ] . V_376 ;
else
V_374 =
( T_2 * ) & V_2 -> V_5 . V_367 . V_375 [ V_372 ] . V_377 ;
* V_374 = V_38 ;
}
F_66 ( V_2 ) ;
return 0 ;
}
static int F_182 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
T_2 V_378 = V_2 -> V_5 . V_378 ;
unsigned V_379 = V_378 & 0xff ;
switch ( V_21 ) {
case V_380 :
V_2 -> V_5 . V_381 = V_38 ;
break;
case V_382 :
if ( ! ( V_378 & V_383 ) )
return 1 ;
if ( V_38 != 0 && V_38 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_384 = V_38 ;
break;
default:
if ( V_21 >= V_385 &&
V_21 < F_183 ( V_379 ) ) {
T_1 V_94 = V_21 - V_385 ;
if ( ( V_94 & 0x3 ) == 0 &&
V_38 != 0 && ( V_38 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_386 [ V_94 ] = V_38 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_184 ( struct V_1 * V_2 , T_2 V_38 )
{
struct V_102 * V_102 = V_2 -> V_102 ;
int V_387 = F_57 ( V_2 ) ;
T_14 * V_388 = V_387 ? ( T_14 * ) ( long ) V_102 -> V_5 . F_184 . V_389
: ( T_14 * ) ( long ) V_102 -> V_5 . F_184 . V_390 ;
T_14 V_391 = V_387 ? V_102 -> V_5 . F_184 . V_392
: V_102 -> V_5 . F_184 . V_393 ;
T_1 V_394 = V_38 & ~ V_395 ;
T_2 V_396 = V_38 & V_395 ;
T_14 * V_397 ;
int V_120 ;
V_120 = - V_398 ;
if ( V_394 >= V_391 )
goto V_114;
V_120 = - V_399 ;
V_397 = F_185 ( V_388 + ( V_394 * V_108 ) , V_108 ) ;
if ( F_186 ( V_397 ) ) {
V_120 = F_187 ( V_397 ) ;
goto V_114;
}
if ( F_119 ( V_102 , V_396 , V_397 , V_108 ) )
goto V_400;
V_120 = 0 ;
V_400:
F_188 ( V_397 ) ;
V_114:
return V_120 ;
}
static bool F_189 ( struct V_102 * V_102 )
{
return V_102 -> V_5 . V_401 & V_402 ;
}
static bool F_190 ( T_1 V_21 )
{
bool V_120 = false ;
switch ( V_21 ) {
case V_403 :
case V_404 :
case V_405 :
case V_406 :
V_120 = true ;
break;
}
return V_120 ;
}
static int F_191 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
struct V_102 * V_102 = V_2 -> V_102 ;
switch ( V_21 ) {
case V_403 :
V_102 -> V_5 . V_407 = V_38 ;
if ( ! V_102 -> V_5 . V_407 )
V_102 -> V_5 . V_401 &= ~ V_402 ;
break;
case V_404 : {
T_2 V_103 ;
unsigned long V_408 ;
T_14 V_409 [ 4 ] ;
if ( ! V_102 -> V_5 . V_407 )
break;
if ( ! ( V_38 & V_402 ) ) {
V_102 -> V_5 . V_401 = V_38 ;
break;
}
V_103 = V_38 >> V_410 ;
V_408 = F_192 ( V_102 , V_103 ) ;
if ( F_193 ( V_408 ) )
return 1 ;
V_73 -> V_411 ( V_2 , V_409 ) ;
( ( unsigned char * ) V_409 ) [ 3 ] = 0xc3 ;
if ( F_194 ( ( void V_412 * ) V_408 , V_409 , 4 ) )
return 1 ;
V_102 -> V_5 . V_401 = V_38 ;
F_195 ( V_102 , V_103 ) ;
break;
}
case V_405 : {
T_2 V_103 ;
T_15 V_413 ;
memset ( & V_413 , 0 , sizeof( V_413 ) ) ;
V_102 -> V_5 . V_414 = V_38 ;
if ( ! ( V_38 & V_415 ) )
break;
V_103 = V_38 >> V_416 ;
if ( F_119 ( V_102 , V_103 << V_416 ,
& V_413 , sizeof( V_413 ) ) )
return 1 ;
F_195 ( V_102 , V_103 ) ;
break;
}
default:
F_196 ( V_2 , L_7
L_8 , V_21 , V_38 ) ;
return 1 ;
}
return 0 ;
}
static int F_197 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
switch ( V_21 ) {
case V_417 : {
T_2 V_103 ;
unsigned long V_408 ;
if ( ! ( V_38 & V_418 ) ) {
V_2 -> V_5 . V_419 = V_38 ;
if ( F_198 ( V_2 , 0 ) )
return 1 ;
break;
}
V_103 = V_38 >> V_420 ;
V_408 = F_192 ( V_2 -> V_102 , V_103 ) ;
if ( F_193 ( V_408 ) )
return 1 ;
if ( F_199 ( ( void V_412 * ) V_408 , V_108 ) )
return 1 ;
V_2 -> V_5 . V_419 = V_38 ;
F_195 ( V_2 -> V_102 , V_103 ) ;
if ( F_198 ( V_2 , F_48 ( V_103 ) | V_421 ) )
return 1 ;
break;
}
case V_422 :
return F_200 ( V_2 , V_423 , V_38 ) ;
case V_424 :
return F_200 ( V_2 , V_425 , V_38 ) ;
case V_426 :
return F_200 ( V_2 , V_427 , V_38 ) ;
default:
F_196 ( V_2 , L_7
L_8 , V_21 , V_38 ) ;
return 1 ;
}
return 0 ;
}
static int F_201 ( struct V_1 * V_2 , T_2 V_38 )
{
T_6 V_428 = V_38 & ~ 0x3f ;
if ( V_38 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_429 = V_38 ;
if ( ! ( V_38 & V_430 ) ) {
F_65 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_202 ( V_2 -> V_102 , & V_2 -> V_5 . V_6 . V_38 , V_428 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_431 = ! ( V_38 & V_432 ) ;
F_203 ( V_2 ) ;
return 0 ;
}
static void F_204 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_334 = false ;
}
static void F_205 ( struct V_1 * V_2 )
{
T_2 V_304 ;
if ( ! ( V_2 -> V_5 . V_433 . V_429 & V_421 ) )
return;
V_304 = V_434 -> V_435 . V_436 - V_2 -> V_5 . V_433 . V_437 ;
V_2 -> V_5 . V_433 . V_437 = V_434 -> V_435 . V_436 ;
V_2 -> V_5 . V_433 . V_438 = V_304 ;
}
static void F_206 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_433 . V_429 & V_421 ) )
return;
if ( F_152 ( F_168 ( V_2 -> V_102 , & V_2 -> V_5 . V_433 . V_439 ,
& V_2 -> V_5 . V_433 . V_440 , sizeof( struct V_441 ) ) ) )
return;
V_2 -> V_5 . V_433 . V_440 . V_440 += V_2 -> V_5 . V_433 . V_438 ;
V_2 -> V_5 . V_433 . V_440 . V_236 += 2 ;
V_2 -> V_5 . V_433 . V_438 = 0 ;
F_170 ( V_2 -> V_102 , & V_2 -> V_5 . V_433 . V_439 ,
& V_2 -> V_5 . V_433 . V_440 , sizeof( struct V_441 ) ) ;
}
int F_207 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
bool V_442 = false ;
T_1 V_21 = V_33 -> V_144 ;
T_2 V_38 = V_33 -> V_38 ;
switch ( V_21 ) {
case V_443 :
case V_444 :
case V_445 :
case V_446 :
case V_447 :
case V_448 :
break;
case V_449 :
return F_105 ( V_2 , V_38 ) ;
case V_450 :
V_38 &= ~ ( T_2 ) 0x40 ;
V_38 &= ~ ( T_2 ) 0x100 ;
V_38 &= ~ ( T_2 ) 0x8 ;
V_38 &= ~ ( T_2 ) 0x40000 ;
if ( V_38 != 0 ) {
F_196 ( V_2 , L_9 ,
V_38 ) ;
return 1 ;
}
break;
case V_451 :
if ( V_38 != 0 ) {
F_196 ( V_2 , L_10
L_11 , V_38 ) ;
return 1 ;
}
break;
case V_452 :
if ( ! V_38 ) {
break;
} else if ( V_38 & ~ ( V_453 | V_454 ) ) {
return 1 ;
}
F_196 ( V_2 , L_12 ,
V_258 , V_38 ) ;
break;
case 0x200 ... 0x2ff :
return F_181 ( V_2 , V_21 , V_38 ) ;
case V_455 :
return F_21 ( V_2 , V_33 ) ;
case V_456 ... V_456 + 0x3ff :
return F_208 ( V_2 , V_21 , V_38 ) ;
case V_457 :
F_209 ( V_2 , V_38 ) ;
break;
case V_458 :
if ( F_141 ( V_2 ) ) {
if ( ! V_33 -> V_40 ) {
T_12 V_459 = V_38 - V_2 -> V_5 . V_289 ;
V_73 -> V_460 ( V_2 , V_459 , true ) ;
}
V_2 -> V_5 . V_289 = V_38 ;
}
break;
case V_461 :
V_2 -> V_5 . V_462 = V_38 ;
break;
case V_463 :
case V_464 :
V_2 -> V_102 -> V_5 . V_235 = V_38 ;
F_117 ( V_2 -> V_102 , V_38 ) ;
break;
case V_465 :
case V_466 : {
T_2 V_467 ;
struct V_278 * V_279 = & V_2 -> V_102 -> V_5 ;
F_204 ( V_2 ) ;
if ( V_2 -> V_286 == 0 && ! V_33 -> V_40 ) {
bool V_468 = ( V_21 == V_466 ) ;
if ( V_279 -> V_320 != V_468 )
F_210 ( V_285 ,
& V_2 -> V_324 ) ;
V_279 -> V_320 = V_468 ;
}
V_2 -> V_5 . time = V_38 ;
F_31 ( V_469 , V_2 ) ;
if ( ! ( V_38 & 1 ) )
break;
V_467 = V_38 & ~ ( V_395 | 1 ) ;
if ( F_202 ( V_2 -> V_102 ,
& V_2 -> V_5 . V_340 , V_38 & ~ 1ULL ,
sizeof( struct V_328 ) ) )
V_2 -> V_5 . V_334 = false ;
else
V_2 -> V_5 . V_334 = true ;
break;
}
case V_470 :
if ( F_201 ( V_2 , V_38 ) )
return 1 ;
break;
case V_471 :
if ( F_152 ( ! F_211 () ) )
return 1 ;
if ( V_38 & V_472 )
return 1 ;
if ( F_202 ( V_2 -> V_102 , & V_2 -> V_5 . V_433 . V_439 ,
V_38 & V_473 ,
sizeof( struct V_441 ) ) )
return 1 ;
V_2 -> V_5 . V_433 . V_429 = V_38 ;
if ( ! ( V_38 & V_421 ) )
break;
V_2 -> V_5 . V_433 . V_437 = V_434 -> V_435 . V_436 ;
F_212 () ;
F_205 ( V_2 ) ;
F_213 () ;
F_31 ( V_474 , V_2 ) ;
break;
case V_475 :
if ( F_198 ( V_2 , V_38 ) )
return 1 ;
break;
case V_382 :
case V_380 :
case V_385 ... F_183 ( V_476 ) - 1 :
return F_182 ( V_2 , V_21 , V_38 ) ;
case V_477 :
case V_478 :
case V_479 :
case V_480 :
if ( V_38 != 0 )
F_196 ( V_2 , L_13
L_14 , V_21 , V_38 ) ;
break;
case V_481 :
case V_482 :
case V_483 :
case V_484 :
F_196 ( V_2 , L_13
L_14 , V_21 , V_38 ) ;
break;
case V_485 :
case V_486 :
V_442 = true ;
case V_487 :
case V_488 :
if ( F_214 ( V_2 , V_21 ) )
return F_215 ( V_2 , V_33 ) ;
if ( V_442 || V_38 != 0 )
F_196 ( V_2 , L_15
L_14 , V_21 , V_38 ) ;
break;
case V_489 :
break;
case V_403 ... V_490 :
if ( F_190 ( V_21 ) ) {
int V_120 ;
F_216 ( & V_2 -> V_102 -> V_491 ) ;
V_120 = F_191 ( V_2 , V_21 , V_38 ) ;
F_217 ( & V_2 -> V_102 -> V_491 ) ;
return V_120 ;
} else
return F_197 ( V_2 , V_21 , V_38 ) ;
break;
case V_492 :
F_196 ( V_2 , L_16 , V_21 , V_38 ) ;
break;
case V_493 :
if ( ! F_218 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_494 . V_495 = V_38 ;
break;
case V_496 :
if ( ! F_218 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_494 . V_497 = V_38 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_102 -> V_5 . F_184 . V_21 ) )
return F_184 ( V_2 , V_38 ) ;
if ( F_214 ( V_2 , V_21 ) )
return F_215 ( V_2 , V_33 ) ;
if ( ! V_498 ) {
F_196 ( V_2 , L_17 ,
V_21 , V_38 ) ;
return 1 ;
} else {
F_196 ( V_2 , L_16 ,
V_21 , V_38 ) ;
break;
}
}
return 0 ;
}
int F_219 ( struct V_1 * V_2 , T_1 V_499 , T_2 * V_500 )
{
return V_73 -> V_501 ( V_2 , V_499 , V_500 ) ;
}
static int F_220 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_500 )
{
T_2 * V_366 = ( T_2 * ) & V_2 -> V_5 . V_367 . V_368 ;
if ( ! F_177 ( V_21 ) )
return 1 ;
if ( V_21 == V_364 )
* V_500 = V_2 -> V_5 . V_367 . V_369 +
( V_2 -> V_5 . V_367 . V_370 << 10 ) ;
else if ( V_21 == V_353 )
* V_500 = V_366 [ 0 ] ;
else if ( V_21 == V_354 || V_21 == V_355 )
* V_500 = V_366 [ 1 + V_21 - V_354 ] ;
else if ( V_21 >= V_356 && V_21 <= V_363 )
* V_500 = V_366 [ 3 + V_21 - V_356 ] ;
else if ( V_21 == V_365 )
* V_500 = V_2 -> V_5 . V_371 ;
else {
int V_372 , V_373 ;
T_2 * V_374 ;
V_372 = ( V_21 - 0x200 ) / 2 ;
V_373 = V_21 - 0x200 - 2 * V_372 ;
if ( ! V_373 )
V_374 =
( T_2 * ) & V_2 -> V_5 . V_367 . V_375 [ V_372 ] . V_376 ;
else
V_374 =
( T_2 * ) & V_2 -> V_5 . V_367 . V_375 [ V_372 ] . V_377 ;
* V_500 = * V_374 ;
}
return 0 ;
}
static int F_221 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_500 )
{
T_2 V_38 ;
T_2 V_378 = V_2 -> V_5 . V_378 ;
unsigned V_379 = V_378 & 0xff ;
switch ( V_21 ) {
case V_502 :
case V_503 :
V_38 = 0 ;
break;
case V_504 :
V_38 = V_2 -> V_5 . V_378 ;
break;
case V_382 :
if ( ! ( V_378 & V_383 ) )
return 1 ;
V_38 = V_2 -> V_5 . V_384 ;
break;
case V_380 :
V_38 = V_2 -> V_5 . V_381 ;
break;
default:
if ( V_21 >= V_385 &&
V_21 < F_183 ( V_379 ) ) {
T_1 V_94 = V_21 - V_385 ;
V_38 = V_2 -> V_5 . V_386 [ V_94 ] ;
break;
}
return 1 ;
}
* V_500 = V_38 ;
return 0 ;
}
static int F_222 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_500 )
{
T_2 V_38 = 0 ;
struct V_102 * V_102 = V_2 -> V_102 ;
switch ( V_21 ) {
case V_403 :
V_38 = V_102 -> V_5 . V_407 ;
break;
case V_404 :
V_38 = V_102 -> V_5 . V_401 ;
break;
case V_406 : {
V_38 =
F_223 ( F_126 () + V_102 -> V_5 . V_241 , 100 ) ;
break;
}
case V_405 :
V_38 = V_102 -> V_5 . V_414 ;
break;
default:
F_196 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_500 = V_38 ;
return 0 ;
}
static int F_224 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_500 )
{
T_2 V_38 = 0 ;
switch ( V_21 ) {
case V_505 : {
int V_120 ;
struct V_1 * V_263 ;
F_160 (r, v, vcpu->kvm) {
if ( V_263 == V_2 ) {
V_38 = V_120 ;
break;
}
}
break;
}
case V_422 :
return F_225 ( V_2 , V_423 , V_500 ) ;
case V_424 :
return F_225 ( V_2 , V_425 , V_500 ) ;
case V_426 :
return F_225 ( V_2 , V_427 , V_500 ) ;
case V_417 :
V_38 = V_2 -> V_5 . V_419 ;
break;
default:
F_196 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_500 = V_38 ;
return 0 ;
}
int F_226 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_500 )
{
T_2 V_38 ;
switch ( V_21 ) {
case V_506 :
case V_507 :
case V_452 :
case V_508 :
case V_509 :
case V_510 :
case V_511 :
case V_512 :
case V_450 :
case V_446 :
case V_477 :
case V_478 :
case V_479 :
case V_480 :
case V_481 :
case V_482 :
case V_483 :
case V_484 :
case V_513 :
case V_443 :
case V_451 :
case V_448 :
V_38 = 0 ;
break;
case V_485 :
case V_486 :
case V_487 :
case V_488 :
if ( F_214 ( V_2 , V_21 ) )
return F_227 ( V_2 , V_21 , V_500 ) ;
V_38 = 0 ;
break;
case V_444 :
V_38 = 0x100000000ULL ;
break;
case V_514 :
V_38 = 0x500 | V_352 ;
break;
case 0x200 ... 0x2ff :
return F_220 ( V_2 , V_21 , V_500 ) ;
case 0xcd :
V_38 = 3 ;
break;
case V_515 :
V_38 = 1 << 24 ;
break;
case V_455 :
V_38 = F_20 ( V_2 ) ;
break;
case V_456 ... V_456 + 0x3ff :
return F_228 ( V_2 , V_21 , V_500 ) ;
break;
case V_457 :
V_38 = F_229 ( V_2 ) ;
break;
case V_458 :
V_38 = ( T_2 ) V_2 -> V_5 . V_289 ;
break;
case V_461 :
V_38 = V_2 -> V_5 . V_462 ;
break;
case V_516 :
V_38 = 1000ULL ;
V_38 |= ( ( ( T_9 ) 4ULL ) << 40 ) ;
break;
case V_449 :
V_38 = V_2 -> V_5 . V_131 ;
break;
case V_464 :
case V_463 :
V_38 = V_2 -> V_102 -> V_5 . V_235 ;
break;
case V_466 :
case V_465 :
V_38 = V_2 -> V_5 . time ;
break;
case V_470 :
V_38 = V_2 -> V_5 . V_6 . V_429 ;
break;
case V_471 :
V_38 = V_2 -> V_5 . V_433 . V_429 ;
break;
case V_475 :
V_38 = V_2 -> V_5 . V_517 . V_429 ;
break;
case V_502 :
case V_503 :
case V_504 :
case V_382 :
case V_380 :
case V_385 ... F_183 ( V_476 ) - 1 :
return F_221 ( V_2 , V_21 , V_500 ) ;
case V_489 :
V_38 = 0x20000000 ;
break;
case V_403 ... V_490 :
if ( F_190 ( V_21 ) ) {
int V_120 ;
F_216 ( & V_2 -> V_102 -> V_491 ) ;
V_120 = F_222 ( V_2 , V_21 , V_500 ) ;
F_217 ( & V_2 -> V_102 -> V_491 ) ;
return V_120 ;
} else
return F_224 ( V_2 , V_21 , V_500 ) ;
break;
case V_492 :
V_38 = 0xbe702111 ;
break;
case V_493 :
if ( ! F_218 ( V_2 ) )
return 1 ;
V_38 = V_2 -> V_5 . V_494 . V_495 ;
break;
case V_496 :
if ( ! F_218 ( V_2 ) )
return 1 ;
V_38 = V_2 -> V_5 . V_494 . V_497 ;
break;
default:
if ( F_214 ( V_2 , V_21 ) )
return F_227 ( V_2 , V_21 , V_500 ) ;
if ( ! V_498 ) {
F_196 ( V_2 , L_19 , V_21 ) ;
return 1 ;
} else {
F_196 ( V_2 , L_20 , V_21 ) ;
V_38 = 0 ;
}
break;
}
* V_500 = V_38 ;
return 0 ;
}
static int F_230 ( struct V_1 * V_2 , struct V_518 * V_19 ,
struct V_519 * V_520 ,
int (* F_231)( struct V_1 * V_2 ,
unsigned V_144 , T_2 * V_38 ) )
{
int V_3 , V_372 ;
V_372 = F_232 ( & V_2 -> V_102 -> V_521 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_522 ; ++ V_3 )
if ( F_231 ( V_2 , V_520 [ V_3 ] . V_144 , & V_520 [ V_3 ] . V_38 ) )
break;
F_233 ( & V_2 -> V_102 -> V_521 , V_372 ) ;
return V_3 ;
}
static int F_234 ( struct V_1 * V_2 , struct V_518 V_412 * V_523 ,
int (* F_231)( struct V_1 * V_2 ,
unsigned V_144 , T_2 * V_38 ) ,
int V_524 )
{
struct V_518 V_19 ;
struct V_519 * V_520 ;
int V_120 , V_525 ;
unsigned V_526 ;
V_120 = - V_101 ;
if ( F_235 ( & V_19 , V_523 , sizeof V_19 ) )
goto V_114;
V_120 = - V_398 ;
if ( V_19 . V_522 >= V_527 )
goto V_114;
V_526 = sizeof( struct V_519 ) * V_19 . V_522 ;
V_520 = F_185 ( V_523 -> V_520 , V_526 ) ;
if ( F_186 ( V_520 ) ) {
V_120 = F_187 ( V_520 ) ;
goto V_114;
}
V_120 = V_525 = F_230 ( V_2 , & V_19 , V_520 , F_231 ) ;
if ( V_120 < 0 )
goto V_400;
V_120 = - V_101 ;
if ( V_524 && F_236 ( V_523 -> V_520 , V_520 , V_526 ) )
goto V_400;
V_120 = V_525 ;
V_400:
F_188 ( V_520 ) ;
V_114:
return V_120 ;
}
int F_237 ( struct V_102 * V_102 , long V_528 )
{
int V_120 ;
switch ( V_528 ) {
case V_529 :
case V_530 :
case V_531 :
case V_532 :
case V_533 :
case V_534 :
case V_535 :
case V_536 :
case V_537 :
case V_538 :
case V_539 :
case V_540 :
case V_541 :
case V_542 :
case V_543 :
case V_544 :
case V_545 :
case V_546 :
case V_547 :
case V_548 :
case V_549 :
case V_550 :
case V_551 :
case V_552 :
case V_553 :
case V_554 :
case V_555 :
case V_556 :
case V_557 :
case V_558 :
case V_559 :
case V_560 :
case V_561 :
case V_562 :
case V_563 :
case V_564 :
#ifdef F_238
case V_565 :
case V_566 :
#endif
V_120 = 1 ;
break;
case V_567 :
V_120 = V_568 ;
break;
case V_569 :
V_120 = ! V_73 -> V_570 () ;
break;
case V_571 :
V_120 = V_572 ;
break;
case V_573 :
V_120 = V_574 ;
break;
case V_575 :
V_120 = V_576 ;
break;
case V_577 :
V_120 = 0 ;
break;
#ifdef F_238
case V_578 :
V_120 = F_239 ( & V_579 ) ;
break;
#endif
case V_580 :
V_120 = V_476 ;
break;
case V_581 :
V_120 = V_582 ;
break;
case V_583 :
V_120 = V_584 ;
break;
default:
V_120 = 0 ;
break;
}
return V_120 ;
}
long F_240 ( struct V_585 * V_586 ,
unsigned int V_587 , unsigned long V_588 )
{
void V_412 * V_589 = ( void V_412 * ) V_588 ;
long V_120 ;
switch ( V_587 ) {
case V_590 : {
struct V_591 V_412 * V_592 = V_589 ;
struct V_591 V_593 ;
unsigned V_525 ;
V_120 = - V_101 ;
if ( F_235 ( & V_593 , V_592 , sizeof V_593 ) )
goto V_114;
V_525 = V_593 . V_522 ;
V_593 . V_522 = V_594 + F_53 ( V_595 ) ;
if ( F_236 ( V_592 , & V_593 , sizeof V_593 ) )
goto V_114;
V_120 = - V_398 ;
if ( V_525 < V_593 . V_522 )
goto V_114;
V_120 = - V_101 ;
if ( F_236 ( V_592 -> V_596 , & V_597 ,
V_594 * sizeof( T_1 ) ) )
goto V_114;
if ( F_236 ( V_592 -> V_596 + V_594 ,
& V_595 ,
F_53 ( V_595 ) * sizeof( T_1 ) ) )
goto V_114;
V_120 = 0 ;
break;
}
case V_598 :
case V_599 : {
struct V_600 V_412 * V_601 = V_589 ;
struct V_600 V_602 ;
V_120 = - V_101 ;
if ( F_235 ( & V_602 , V_601 , sizeof V_602 ) )
goto V_114;
V_120 = F_241 ( & V_602 , V_601 -> V_520 ,
V_587 ) ;
if ( V_120 )
goto V_114;
V_120 = - V_101 ;
if ( F_236 ( V_601 , & V_602 , sizeof V_602 ) )
goto V_114;
V_120 = 0 ;
break;
}
case V_603 : {
T_2 V_604 ;
V_604 = V_605 ;
V_120 = - V_101 ;
if ( F_236 ( V_589 , & V_604 , sizeof V_604 ) )
goto V_114;
V_120 = 0 ;
break;
}
default:
V_120 = - V_606 ;
}
V_114:
return V_120 ;
}
static void F_242 ( void * V_607 )
{
F_243 () ;
}
static bool F_244 ( struct V_1 * V_2 )
{
return F_245 ( V_2 -> V_102 ) ;
}
void F_246 ( struct V_1 * V_2 , int V_23 )
{
if ( F_244 ( V_2 ) ) {
if ( V_73 -> V_608 () )
F_247 ( V_23 , V_2 -> V_5 . V_609 ) ;
else if ( V_2 -> V_23 != - 1 && V_2 -> V_23 != V_23 )
F_248 ( V_2 -> V_23 ,
F_242 , NULL , 1 ) ;
}
V_73 -> V_610 ( V_2 , V_23 ) ;
if ( F_152 ( V_2 -> V_5 . V_611 ) ) {
F_249 ( V_2 , V_2 -> V_5 . V_611 ) ;
V_2 -> V_5 . V_611 = 0 ;
F_31 ( V_322 , V_2 ) ;
}
if ( F_152 ( V_2 -> V_23 != V_23 ) || F_140 () ) {
T_12 V_612 = ! V_2 -> V_5 . V_613 ? 0 :
F_166 () - V_2 -> V_5 . V_613 ;
if ( V_612 < 0 )
F_250 ( L_21 ) ;
if ( F_140 () ) {
T_2 V_94 = V_73 -> V_297 ( V_2 ,
V_2 -> V_5 . V_309 ) ;
V_73 -> V_310 ( V_2 , V_94 ) ;
V_2 -> V_5 . V_333 = 1 ;
}
if ( ! V_2 -> V_102 -> V_5 . V_283 || V_2 -> V_23 == - 1 )
F_31 ( V_469 , V_2 ) ;
if ( V_2 -> V_23 != V_23 )
F_251 ( V_2 ) ;
V_2 -> V_23 = V_23 ;
}
F_205 ( V_2 ) ;
F_31 ( V_474 , V_2 ) ;
}
void F_252 ( struct V_1 * V_2 )
{
V_73 -> V_614 ( V_2 ) ;
F_253 ( V_2 ) ;
V_2 -> V_5 . V_613 = F_166 () ;
}
static int F_254 ( struct V_1 * V_2 ,
struct V_615 * V_616 )
{
V_73 -> V_617 ( V_2 ) ;
memcpy ( V_616 -> V_618 , V_2 -> V_5 . V_619 -> V_618 , sizeof *V_616 ) ;
return 0 ;
}
static int F_255 ( struct V_1 * V_2 ,
struct V_615 * V_616 )
{
F_256 ( V_2 , V_616 ) ;
F_257 ( V_2 ) ;
return 0 ;
}
static int F_258 ( struct V_1 * V_2 ,
struct V_620 * V_621 )
{
if ( V_621 -> V_621 >= V_622 )
return - V_606 ;
if ( F_87 ( V_2 -> V_102 ) )
return - V_623 ;
F_259 ( V_2 , V_621 -> V_621 , false ) ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
static int F_260 ( struct V_1 * V_2 )
{
F_41 ( V_2 ) ;
return 0 ;
}
static int F_261 ( struct V_1 * V_2 ,
struct V_624 * V_625 )
{
if ( V_625 -> V_292 )
return - V_606 ;
V_2 -> V_5 . V_626 = ! ! V_625 -> V_370 ;
return 0 ;
}
static int F_262 ( struct V_1 * V_2 ,
T_2 V_378 )
{
int V_120 ;
unsigned V_379 = V_378 & 0xff , V_627 ;
V_120 = - V_606 ;
if ( ! V_379 || V_379 >= V_476 )
goto V_114;
if ( V_378 & ~ ( V_605 | 0xff | 0xff0000 ) )
goto V_114;
V_120 = 0 ;
V_2 -> V_5 . V_378 = V_378 ;
if ( V_378 & V_383 )
V_2 -> V_5 . V_384 = ~ ( T_2 ) 0 ;
for ( V_627 = 0 ; V_627 < V_379 ; V_627 ++ )
V_2 -> V_5 . V_386 [ V_627 * 4 ] = ~ ( T_2 ) 0 ;
V_114:
return V_120 ;
}
static int F_263 ( struct V_1 * V_2 ,
struct V_628 * V_629 )
{
T_2 V_378 = V_2 -> V_5 . V_378 ;
unsigned V_379 = V_378 & 0xff ;
T_2 * V_630 = V_2 -> V_5 . V_386 ;
if ( V_629 -> V_627 >= V_379 || ! ( V_629 -> V_497 & V_631 ) )
return - V_606 ;
if ( ( V_629 -> V_497 & V_632 ) && ( V_378 & V_383 ) &&
V_2 -> V_5 . V_384 != ~ ( T_2 ) 0 )
return 0 ;
V_630 += 4 * V_629 -> V_627 ;
if ( ( V_629 -> V_497 & V_632 ) && V_630 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_629 -> V_497 & V_632 ) {
if ( ( V_2 -> V_5 . V_381 & V_633 ) ||
! F_46 ( V_2 , V_634 ) ) {
F_31 ( V_72 , V_2 ) ;
return 0 ;
}
if ( V_630 [ 1 ] & V_631 )
V_629 -> V_497 |= V_635 ;
V_630 [ 2 ] = V_629 -> V_408 ;
V_630 [ 3 ] = V_629 -> V_636 ;
V_2 -> V_5 . V_381 = V_629 -> V_381 ;
V_630 [ 1 ] = V_629 -> V_497 ;
F_33 ( V_2 , V_58 ) ;
} else if ( ! ( V_630 [ 1 ] & V_631 )
|| ! ( V_630 [ 1 ] & V_632 ) ) {
if ( V_630 [ 1 ] & V_631 )
V_629 -> V_497 |= V_635 ;
V_630 [ 2 ] = V_629 -> V_408 ;
V_630 [ 3 ] = V_629 -> V_636 ;
V_630 [ 1 ] = V_629 -> V_497 ;
} else
V_630 [ 1 ] |= V_635 ;
return 0 ;
}
static void F_264 ( struct V_1 * V_2 ,
struct V_637 * V_638 )
{
F_265 ( V_2 ) ;
V_638 -> V_68 . V_639 =
V_2 -> V_5 . V_68 . V_69 &&
! F_266 ( V_2 -> V_5 . V_68 . V_16 ) ;
V_638 -> V_68 . V_16 = V_2 -> V_5 . V_68 . V_16 ;
V_638 -> V_68 . V_71 = V_2 -> V_5 . V_68 . V_71 ;
V_638 -> V_68 . V_640 = 0 ;
V_638 -> V_68 . V_62 = V_2 -> V_5 . V_68 . V_62 ;
V_638 -> V_641 . V_639 =
V_2 -> V_5 . V_641 . V_69 && ! V_2 -> V_5 . V_641 . V_642 ;
V_638 -> V_641 . V_16 = V_2 -> V_5 . V_641 . V_16 ;
V_638 -> V_641 . V_642 = 0 ;
V_638 -> V_641 . V_643 = V_73 -> V_644 ( V_2 ) ;
V_638 -> V_645 . V_639 = V_2 -> V_5 . V_646 ;
V_638 -> V_645 . V_69 = V_2 -> V_5 . V_647 != 0 ;
V_638 -> V_645 . V_648 = V_73 -> V_649 ( V_2 ) ;
V_638 -> V_645 . V_640 = 0 ;
V_638 -> V_650 = 0 ;
V_638 -> V_292 = ( V_651
| V_652 ) ;
memset ( & V_638 -> V_653 , 0 , sizeof( V_638 -> V_653 ) ) ;
}
static int F_267 ( struct V_1 * V_2 ,
struct V_637 * V_638 )
{
if ( V_638 -> V_292 & ~ ( V_651
| V_654
| V_652 ) )
return - V_606 ;
F_265 ( V_2 ) ;
V_2 -> V_5 . V_68 . V_69 = V_638 -> V_68 . V_639 ;
V_2 -> V_5 . V_68 . V_16 = V_638 -> V_68 . V_16 ;
V_2 -> V_5 . V_68 . V_71 = V_638 -> V_68 . V_71 ;
V_2 -> V_5 . V_68 . V_62 = V_638 -> V_68 . V_62 ;
V_2 -> V_5 . V_641 . V_69 = V_638 -> V_641 . V_639 ;
V_2 -> V_5 . V_641 . V_16 = V_638 -> V_641 . V_16 ;
V_2 -> V_5 . V_641 . V_642 = V_638 -> V_641 . V_642 ;
if ( V_638 -> V_292 & V_652 )
V_73 -> V_655 ( V_2 ,
V_638 -> V_641 . V_643 ) ;
V_2 -> V_5 . V_646 = V_638 -> V_645 . V_639 ;
if ( V_638 -> V_292 & V_651 )
V_2 -> V_5 . V_647 = V_638 -> V_645 . V_69 ;
V_73 -> V_656 ( V_2 , V_638 -> V_645 . V_648 ) ;
if ( V_638 -> V_292 & V_654 &&
F_268 ( V_2 ) )
V_2 -> V_5 . V_619 -> V_650 = V_638 -> V_650 ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
static void F_269 ( struct V_1 * V_2 ,
struct V_657 * V_658 )
{
unsigned long V_188 ;
memcpy ( V_658 -> V_189 , V_2 -> V_5 . V_189 , sizeof( V_2 -> V_5 . V_189 ) ) ;
F_97 ( V_2 , 6 , & V_188 ) ;
V_658 -> V_178 = V_188 ;
V_658 -> V_179 = V_2 -> V_5 . V_179 ;
V_658 -> V_292 = 0 ;
memset ( & V_658 -> V_653 , 0 , sizeof( V_658 -> V_653 ) ) ;
}
static int F_270 ( struct V_1 * V_2 ,
struct V_657 * V_658 )
{
if ( V_658 -> V_292 )
return - V_606 ;
memcpy ( V_2 -> V_5 . V_189 , V_658 -> V_189 , sizeof( V_2 -> V_5 . V_189 ) ) ;
V_2 -> V_5 . V_178 = V_658 -> V_178 ;
F_91 ( V_2 ) ;
V_2 -> V_5 . V_179 = V_658 -> V_179 ;
F_92 ( V_2 ) ;
return 0 ;
}
static void F_271 ( T_14 * V_659 , struct V_1 * V_2 )
{
struct V_660 * V_661 = & V_2 -> V_5 . V_662 . V_663 -> V_661 ;
T_2 V_664 = V_661 -> V_665 . V_664 ;
T_2 V_666 ;
memcpy ( V_659 , V_661 , V_667 ) ;
* ( T_2 * ) ( V_659 + V_667 ) = V_664 ;
V_666 = V_664 & ~ V_668 ;
while ( V_666 ) {
T_2 V_669 = V_666 & - V_666 ;
int V_144 = F_272 ( V_669 ) - 1 ;
void * V_670 = F_273 ( V_661 , V_669 ) ;
if ( V_670 ) {
T_1 V_526 , V_94 , V_195 , V_203 ;
F_274 ( V_671 , V_144 ,
& V_526 , & V_94 , & V_195 , & V_203 ) ;
memcpy ( V_659 + V_94 , V_670 , V_526 ) ;
}
V_666 -= V_669 ;
}
}
static void F_275 ( struct V_1 * V_2 , T_14 * V_670 )
{
struct V_660 * V_661 = & V_2 -> V_5 . V_662 . V_663 -> V_661 ;
T_2 V_664 = * ( T_2 * ) ( V_670 + V_667 ) ;
T_2 V_666 ;
memcpy ( V_661 , V_670 , V_667 ) ;
V_661 -> V_665 . V_664 = V_664 ;
if ( V_672 )
V_661 -> V_665 . V_673 = V_143 | V_674 ;
V_666 = V_664 & ~ V_668 ;
while ( V_666 ) {
T_2 V_669 = V_666 & - V_666 ;
int V_144 = F_272 ( V_669 ) - 1 ;
void * V_659 = F_273 ( V_661 , V_669 ) ;
if ( V_659 ) {
T_1 V_526 , V_94 , V_195 , V_203 ;
F_274 ( V_671 , V_144 ,
& V_526 , & V_94 , & V_195 , & V_203 ) ;
memcpy ( V_659 , V_670 + V_94 , V_526 ) ;
} else
F_276 ( 1 ) ;
V_666 -= V_669 ;
}
}
static void F_277 ( struct V_1 * V_2 ,
struct V_675 * V_676 )
{
if ( V_582 ) {
memset ( V_676 , 0 , sizeof( struct V_675 ) ) ;
F_271 ( ( T_14 * ) V_676 -> V_677 , V_2 ) ;
} else {
memcpy ( V_676 -> V_677 ,
& V_2 -> V_5 . V_662 . V_663 -> V_678 ,
sizeof( struct V_679 ) ) ;
* ( T_2 * ) & V_676 -> V_677 [ V_667 / sizeof( T_1 ) ] =
V_668 ;
}
}
static int F_278 ( struct V_1 * V_2 ,
struct V_675 * V_676 )
{
T_2 V_664 =
* ( T_2 * ) & V_676 -> V_677 [ V_667 / sizeof( T_1 ) ] ;
if ( V_582 ) {
if ( V_664 & ~ F_279 () )
return - V_606 ;
F_275 ( V_2 , ( T_14 * ) V_676 -> V_677 ) ;
} else {
if ( V_664 & ~ V_668 )
return - V_606 ;
memcpy ( & V_2 -> V_5 . V_662 . V_663 -> V_678 ,
V_676 -> V_677 , sizeof( struct V_679 ) ) ;
}
return 0 ;
}
static void F_280 ( struct V_1 * V_2 ,
struct V_680 * V_681 )
{
if ( ! V_582 ) {
V_681 -> V_682 = 0 ;
return;
}
V_681 -> V_682 = 1 ;
V_681 -> V_292 = 0 ;
V_681 -> V_683 [ 0 ] . V_145 = V_141 ;
V_681 -> V_683 [ 0 ] . V_22 = V_2 -> V_5 . V_142 ;
}
static int F_281 ( struct V_1 * V_2 ,
struct V_680 * V_681 )
{
int V_3 , V_120 = 0 ;
if ( ! V_582 )
return - V_606 ;
if ( V_681 -> V_682 > V_684 || V_681 -> V_292 )
return - V_606 ;
for ( V_3 = 0 ; V_3 < V_681 -> V_682 ; V_3 ++ )
if ( V_681 -> V_683 [ V_3 ] . V_145 == V_141 ) {
V_120 = F_72 ( V_2 , V_141 ,
V_681 -> V_683 [ V_3 ] . V_22 ) ;
break;
}
if ( V_120 )
V_120 = - V_606 ;
return V_120 ;
}
static int F_282 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_334 )
return - V_606 ;
V_2 -> V_5 . V_342 = true ;
F_31 ( V_322 , V_2 ) ;
return 0 ;
}
long F_283 ( struct V_585 * V_586 ,
unsigned int V_587 , unsigned long V_588 )
{
struct V_1 * V_2 = V_586 -> V_685 ;
void V_412 * V_589 = ( void V_412 * ) V_588 ;
int V_120 ;
union {
struct V_615 * V_686 ;
struct V_675 * V_661 ;
struct V_680 * V_683 ;
void * V_687 ;
} V_688 ;
V_688 . V_687 = NULL ;
switch ( V_587 ) {
case V_689 : {
V_120 = - V_606 ;
if ( ! V_2 -> V_5 . V_619 )
goto V_114;
V_688 . V_686 = F_284 ( sizeof( struct V_615 ) , V_690 ) ;
V_120 = - V_399 ;
if ( ! V_688 . V_686 )
goto V_114;
V_120 = F_254 ( V_2 , V_688 . V_686 ) ;
if ( V_120 )
goto V_114;
V_120 = - V_101 ;
if ( F_236 ( V_589 , V_688 . V_686 , sizeof( struct V_615 ) ) )
goto V_114;
V_120 = 0 ;
break;
}
case V_691 : {
V_120 = - V_606 ;
if ( ! V_2 -> V_5 . V_619 )
goto V_114;
V_688 . V_686 = F_185 ( V_589 , sizeof( * V_688 . V_686 ) ) ;
if ( F_186 ( V_688 . V_686 ) )
return F_187 ( V_688 . V_686 ) ;
V_120 = F_255 ( V_2 , V_688 . V_686 ) ;
break;
}
case V_692 : {
struct V_620 V_621 ;
V_120 = - V_101 ;
if ( F_235 ( & V_621 , V_589 , sizeof V_621 ) )
goto V_114;
V_120 = F_258 ( V_2 , & V_621 ) ;
break;
}
case V_693 : {
V_120 = F_260 ( V_2 ) ;
break;
}
case V_694 : {
struct V_695 V_412 * V_601 = V_589 ;
struct V_695 V_602 ;
V_120 = - V_101 ;
if ( F_235 ( & V_602 , V_601 , sizeof V_602 ) )
goto V_114;
V_120 = F_285 ( V_2 , & V_602 , V_601 -> V_520 ) ;
break;
}
case V_696 : {
struct V_600 V_412 * V_601 = V_589 ;
struct V_600 V_602 ;
V_120 = - V_101 ;
if ( F_235 ( & V_602 , V_601 , sizeof V_602 ) )
goto V_114;
V_120 = F_286 ( V_2 , & V_602 ,
V_601 -> V_520 ) ;
break;
}
case V_697 : {
struct V_600 V_412 * V_601 = V_589 ;
struct V_600 V_602 ;
V_120 = - V_101 ;
if ( F_235 ( & V_602 , V_601 , sizeof V_602 ) )
goto V_114;
V_120 = F_287 ( V_2 , & V_602 ,
V_601 -> V_520 ) ;
if ( V_120 )
goto V_114;
V_120 = - V_101 ;
if ( F_236 ( V_601 , & V_602 , sizeof V_602 ) )
goto V_114;
V_120 = 0 ;
break;
}
case V_698 :
V_120 = F_234 ( V_2 , V_589 , F_219 , 1 ) ;
break;
case V_699 :
V_120 = F_234 ( V_2 , V_589 , F_110 , 0 ) ;
break;
case V_700 : {
struct V_624 V_625 ;
V_120 = - V_101 ;
if ( F_235 ( & V_625 , V_589 , sizeof V_625 ) )
goto V_114;
V_120 = F_261 ( V_2 , & V_625 ) ;
if ( V_120 )
goto V_114;
V_120 = - V_101 ;
if ( F_236 ( V_589 , & V_625 , sizeof V_625 ) )
goto V_114;
V_120 = 0 ;
break;
} ;
case V_701 : {
struct V_702 V_703 ;
V_120 = - V_606 ;
if ( ! F_87 ( V_2 -> V_102 ) )
goto V_114;
V_120 = - V_101 ;
if ( F_235 ( & V_703 , V_589 , sizeof V_703 ) )
goto V_114;
V_120 = F_288 ( V_2 , V_703 . V_704 ) ;
break;
}
case V_705 : {
T_2 V_378 ;
V_120 = - V_101 ;
if ( F_235 ( & V_378 , V_589 , sizeof V_378 ) )
goto V_114;
V_120 = F_262 ( V_2 , V_378 ) ;
break;
}
case V_706 : {
struct V_628 V_629 ;
V_120 = - V_101 ;
if ( F_235 ( & V_629 , V_589 , sizeof V_629 ) )
goto V_114;
V_120 = F_263 ( V_2 , & V_629 ) ;
break;
}
case V_707 : {
struct V_637 V_638 ;
F_264 ( V_2 , & V_638 ) ;
V_120 = - V_101 ;
if ( F_236 ( V_589 , & V_638 , sizeof( struct V_637 ) ) )
break;
V_120 = 0 ;
break;
}
case V_708 : {
struct V_637 V_638 ;
V_120 = - V_101 ;
if ( F_235 ( & V_638 , V_589 , sizeof( struct V_637 ) ) )
break;
V_120 = F_267 ( V_2 , & V_638 ) ;
break;
}
case V_709 : {
struct V_657 V_658 ;
F_269 ( V_2 , & V_658 ) ;
V_120 = - V_101 ;
if ( F_236 ( V_589 , & V_658 ,
sizeof( struct V_657 ) ) )
break;
V_120 = 0 ;
break;
}
case V_710 : {
struct V_657 V_658 ;
V_120 = - V_101 ;
if ( F_235 ( & V_658 , V_589 ,
sizeof( struct V_657 ) ) )
break;
V_120 = F_270 ( V_2 , & V_658 ) ;
break;
}
case V_711 : {
V_688 . V_661 = F_284 ( sizeof( struct V_675 ) , V_690 ) ;
V_120 = - V_399 ;
if ( ! V_688 . V_661 )
break;
F_277 ( V_2 , V_688 . V_661 ) ;
V_120 = - V_101 ;
if ( F_236 ( V_589 , V_688 . V_661 , sizeof( struct V_675 ) ) )
break;
V_120 = 0 ;
break;
}
case V_712 : {
V_688 . V_661 = F_185 ( V_589 , sizeof( * V_688 . V_661 ) ) ;
if ( F_186 ( V_688 . V_661 ) )
return F_187 ( V_688 . V_661 ) ;
V_120 = F_278 ( V_2 , V_688 . V_661 ) ;
break;
}
case V_713 : {
V_688 . V_683 = F_284 ( sizeof( struct V_680 ) , V_690 ) ;
V_120 = - V_399 ;
if ( ! V_688 . V_683 )
break;
F_280 ( V_2 , V_688 . V_683 ) ;
V_120 = - V_101 ;
if ( F_236 ( V_589 , V_688 . V_683 ,
sizeof( struct V_680 ) ) )
break;
V_120 = 0 ;
break;
}
case V_714 : {
V_688 . V_683 = F_185 ( V_589 , sizeof( * V_688 . V_683 ) ) ;
if ( F_186 ( V_688 . V_683 ) )
return F_187 ( V_688 . V_683 ) ;
V_120 = F_281 ( V_2 , V_688 . V_683 ) ;
break;
}
case V_715 : {
T_1 V_716 ;
V_120 = - V_606 ;
V_716 = ( T_1 ) V_588 ;
if ( V_716 >= V_717 )
goto V_114;
if ( V_716 == 0 )
V_716 = V_270 ;
F_132 ( V_2 , V_716 ) ;
V_120 = 0 ;
goto V_114;
}
case V_718 : {
V_120 = V_2 -> V_5 . V_269 ;
goto V_114;
}
case V_719 : {
V_120 = F_282 ( V_2 ) ;
goto V_114;
}
default:
V_120 = - V_606 ;
}
V_114:
F_188 ( V_688 . V_687 ) ;
return V_120 ;
}
int F_289 ( struct V_1 * V_2 , struct V_720 * V_721 )
{
return V_722 ;
}
static int F_290 ( struct V_102 * V_102 , unsigned long V_408 )
{
int V_109 ;
if ( V_408 > ( unsigned int ) ( - 3 * V_108 ) )
return - V_606 ;
V_109 = V_73 -> V_723 ( V_102 , V_408 ) ;
return V_109 ;
}
static int F_291 ( struct V_102 * V_102 ,
T_2 V_724 )
{
V_102 -> V_5 . V_725 = V_724 ;
return 0 ;
}
static int F_292 ( struct V_102 * V_102 ,
T_1 V_726 )
{
if ( V_726 < V_727 )
return - V_606 ;
F_216 ( & V_102 -> V_728 ) ;
F_293 ( V_102 , V_726 ) ;
V_102 -> V_5 . V_729 = V_726 ;
F_217 ( & V_102 -> V_728 ) ;
return 0 ;
}
static int F_294 ( struct V_102 * V_102 )
{
return V_102 -> V_5 . V_730 ;
}
static int F_295 ( struct V_102 * V_102 , struct V_731 * V_732 )
{
int V_120 ;
V_120 = 0 ;
switch ( V_732 -> V_733 ) {
case V_734 :
memcpy ( & V_732 -> V_732 . V_735 ,
& F_296 ( V_102 ) -> V_736 [ 0 ] ,
sizeof( struct V_737 ) ) ;
break;
case V_738 :
memcpy ( & V_732 -> V_732 . V_735 ,
& F_296 ( V_102 ) -> V_736 [ 1 ] ,
sizeof( struct V_737 ) ) ;
break;
case V_739 :
V_120 = F_297 ( V_102 , & V_732 -> V_732 . V_740 ) ;
break;
default:
V_120 = - V_606 ;
break;
}
return V_120 ;
}
static int F_298 ( struct V_102 * V_102 , struct V_731 * V_732 )
{
int V_120 ;
V_120 = 0 ;
switch ( V_732 -> V_733 ) {
case V_734 :
F_143 ( & F_296 ( V_102 ) -> V_491 ) ;
memcpy ( & F_296 ( V_102 ) -> V_736 [ 0 ] ,
& V_732 -> V_732 . V_735 ,
sizeof( struct V_737 ) ) ;
F_144 ( & F_296 ( V_102 ) -> V_491 ) ;
break;
case V_738 :
F_143 ( & F_296 ( V_102 ) -> V_491 ) ;
memcpy ( & F_296 ( V_102 ) -> V_736 [ 1 ] ,
& V_732 -> V_732 . V_735 ,
sizeof( struct V_737 ) ) ;
F_144 ( & F_296 ( V_102 ) -> V_491 ) ;
break;
case V_739 :
V_120 = F_299 ( V_102 , & V_732 -> V_732 . V_740 ) ;
break;
default:
V_120 = - V_606 ;
break;
}
F_300 ( F_296 ( V_102 ) ) ;
return V_120 ;
}
static int F_301 ( struct V_102 * V_102 , struct V_741 * V_742 )
{
int V_120 = 0 ;
F_216 ( & V_102 -> V_5 . V_743 -> V_744 . V_491 ) ;
memcpy ( V_742 , & V_102 -> V_5 . V_743 -> V_744 , sizeof( struct V_741 ) ) ;
F_217 ( & V_102 -> V_5 . V_743 -> V_744 . V_491 ) ;
return V_120 ;
}
static int F_302 ( struct V_102 * V_102 , struct V_741 * V_742 )
{
int V_120 = 0 ;
F_216 ( & V_102 -> V_5 . V_743 -> V_744 . V_491 ) ;
memcpy ( & V_102 -> V_5 . V_743 -> V_744 , V_742 , sizeof( struct V_741 ) ) ;
F_303 ( V_102 , 0 , V_742 -> V_745 [ 0 ] . V_746 , 0 ) ;
F_217 ( & V_102 -> V_5 . V_743 -> V_744 . V_491 ) ;
return V_120 ;
}
static int F_304 ( struct V_102 * V_102 , struct V_747 * V_742 )
{
int V_120 = 0 ;
F_216 ( & V_102 -> V_5 . V_743 -> V_744 . V_491 ) ;
memcpy ( V_742 -> V_745 , & V_102 -> V_5 . V_743 -> V_744 . V_745 ,
sizeof( V_742 -> V_745 ) ) ;
V_742 -> V_292 = V_102 -> V_5 . V_743 -> V_744 . V_292 ;
F_217 ( & V_102 -> V_5 . V_743 -> V_744 . V_491 ) ;
memset ( & V_742 -> V_653 , 0 , sizeof( V_742 -> V_653 ) ) ;
return V_120 ;
}
static int F_305 ( struct V_102 * V_102 , struct V_747 * V_742 )
{
int V_120 = 0 , V_748 = 0 ;
T_1 V_749 , V_750 ;
F_216 ( & V_102 -> V_5 . V_743 -> V_744 . V_491 ) ;
V_749 = V_102 -> V_5 . V_743 -> V_744 . V_292 & V_751 ;
V_750 = V_742 -> V_292 & V_751 ;
if ( ! V_749 && V_750 )
V_748 = 1 ;
memcpy ( & V_102 -> V_5 . V_743 -> V_744 . V_745 , & V_742 -> V_745 ,
sizeof( V_102 -> V_5 . V_743 -> V_744 . V_745 ) ) ;
V_102 -> V_5 . V_743 -> V_744 . V_292 = V_742 -> V_292 ;
F_303 ( V_102 , 0 , V_102 -> V_5 . V_743 -> V_744 . V_745 [ 0 ] . V_746 , V_748 ) ;
F_217 ( & V_102 -> V_5 . V_743 -> V_744 . V_491 ) ;
return V_120 ;
}
static int F_306 ( struct V_102 * V_102 ,
struct V_752 * V_753 )
{
if ( ! V_102 -> V_5 . V_743 )
return - V_623 ;
F_216 ( & V_102 -> V_5 . V_743 -> V_744 . V_491 ) ;
V_102 -> V_5 . V_743 -> V_744 . V_63 = V_753 -> V_754 ;
F_217 ( & V_102 -> V_5 . V_743 -> V_744 . V_491 ) ;
return 0 ;
}
int F_307 ( struct V_102 * V_102 , struct V_755 * log )
{
bool V_756 = false ;
int V_120 ;
F_216 ( & V_102 -> V_728 ) ;
if ( V_73 -> V_757 )
V_73 -> V_757 ( V_102 ) ;
V_120 = F_308 ( V_102 , log , & V_756 ) ;
F_309 ( & V_102 -> V_728 ) ;
if ( V_756 )
F_310 ( V_102 ) ;
F_217 ( & V_102 -> V_728 ) ;
return V_120 ;
}
int F_311 ( struct V_102 * V_102 , struct V_758 * V_759 ,
bool V_760 )
{
if ( ! F_87 ( V_102 ) )
return - V_623 ;
V_759 -> V_497 = F_312 ( V_102 , V_761 ,
V_759 -> V_621 , V_759 -> V_762 ,
V_760 ) ;
return 0 ;
}
long F_313 ( struct V_585 * V_586 ,
unsigned int V_587 , unsigned long V_588 )
{
struct V_102 * V_102 = V_586 -> V_685 ;
void V_412 * V_589 = ( void V_412 * ) V_588 ;
int V_120 = - V_763 ;
union {
struct V_741 V_742 ;
struct V_747 V_764 ;
struct V_765 V_766 ;
} V_688 ;
switch ( V_587 ) {
case V_767 :
V_120 = F_290 ( V_102 , V_588 ) ;
break;
case V_768 : {
T_2 V_724 ;
V_120 = - V_101 ;
if ( F_235 ( & V_724 , V_589 , sizeof V_724 ) )
goto V_114;
V_120 = F_291 ( V_102 , V_724 ) ;
break;
}
case V_769 :
V_120 = F_292 ( V_102 , V_588 ) ;
break;
case V_770 :
V_120 = F_294 ( V_102 ) ;
break;
case V_771 : {
struct V_772 * V_773 ;
F_216 ( & V_102 -> V_491 ) ;
V_120 = - V_774 ;
if ( V_102 -> V_5 . V_773 )
goto V_775;
V_120 = - V_606 ;
if ( F_135 ( & V_102 -> V_282 ) )
goto V_775;
V_120 = - V_399 ;
V_773 = F_314 ( V_102 ) ;
if ( V_773 ) {
V_120 = F_315 ( V_102 ) ;
if ( V_120 ) {
F_216 ( & V_102 -> V_728 ) ;
F_316 ( V_102 , V_776 ,
& V_773 -> V_777 ) ;
F_316 ( V_102 , V_776 ,
& V_773 -> V_778 ) ;
F_316 ( V_102 , V_776 ,
& V_773 -> V_779 ) ;
F_217 ( & V_102 -> V_728 ) ;
F_188 ( V_773 ) ;
goto V_775;
}
} else
goto V_775;
F_14 () ;
V_102 -> V_5 . V_773 = V_773 ;
F_14 () ;
V_120 = F_317 ( V_102 ) ;
if ( V_120 ) {
F_216 ( & V_102 -> V_728 ) ;
F_216 ( & V_102 -> V_780 ) ;
F_318 ( V_102 ) ;
F_319 ( V_102 ) ;
F_217 ( & V_102 -> V_780 ) ;
F_217 ( & V_102 -> V_728 ) ;
}
V_775:
F_217 ( & V_102 -> V_491 ) ;
break;
}
case V_781 :
V_688 . V_766 . V_292 = V_782 ;
goto V_783;
case V_784 :
V_120 = - V_101 ;
if ( F_235 ( & V_688 . V_766 , V_589 ,
sizeof( struct V_765 ) ) )
goto V_114;
V_783:
F_216 ( & V_102 -> V_728 ) ;
V_120 = - V_774 ;
if ( V_102 -> V_5 . V_743 )
goto V_785;
V_120 = - V_399 ;
V_102 -> V_5 . V_743 = F_320 ( V_102 , V_688 . V_766 . V_292 ) ;
if ( V_102 -> V_5 . V_743 )
V_120 = 0 ;
V_785:
F_217 ( & V_102 -> V_728 ) ;
break;
case V_786 : {
struct V_731 * V_732 ;
V_732 = F_185 ( V_589 , sizeof( * V_732 ) ) ;
if ( F_186 ( V_732 ) ) {
V_120 = F_187 ( V_732 ) ;
goto V_114;
}
V_120 = - V_623 ;
if ( ! F_87 ( V_102 ) )
goto V_787;
V_120 = F_295 ( V_102 , V_732 ) ;
if ( V_120 )
goto V_787;
V_120 = - V_101 ;
if ( F_236 ( V_589 , V_732 , sizeof *V_732 ) )
goto V_787;
V_120 = 0 ;
V_787:
F_188 ( V_732 ) ;
break;
}
case V_788 : {
struct V_731 * V_732 ;
V_732 = F_185 ( V_589 , sizeof( * V_732 ) ) ;
if ( F_186 ( V_732 ) ) {
V_120 = F_187 ( V_732 ) ;
goto V_114;
}
V_120 = - V_623 ;
if ( ! F_87 ( V_102 ) )
goto V_789;
V_120 = F_298 ( V_102 , V_732 ) ;
if ( V_120 )
goto V_789;
V_120 = 0 ;
V_789:
F_188 ( V_732 ) ;
break;
}
case V_790 : {
V_120 = - V_101 ;
if ( F_235 ( & V_688 . V_742 , V_589 , sizeof( struct V_741 ) ) )
goto V_114;
V_120 = - V_623 ;
if ( ! V_102 -> V_5 . V_743 )
goto V_114;
V_120 = F_301 ( V_102 , & V_688 . V_742 ) ;
if ( V_120 )
goto V_114;
V_120 = - V_101 ;
if ( F_236 ( V_589 , & V_688 . V_742 , sizeof( struct V_741 ) ) )
goto V_114;
V_120 = 0 ;
break;
}
case V_791 : {
V_120 = - V_101 ;
if ( F_235 ( & V_688 . V_742 , V_589 , sizeof V_688 . V_742 ) )
goto V_114;
V_120 = - V_623 ;
if ( ! V_102 -> V_5 . V_743 )
goto V_114;
V_120 = F_302 ( V_102 , & V_688 . V_742 ) ;
break;
}
case V_792 : {
V_120 = - V_623 ;
if ( ! V_102 -> V_5 . V_743 )
goto V_114;
V_120 = F_304 ( V_102 , & V_688 . V_764 ) ;
if ( V_120 )
goto V_114;
V_120 = - V_101 ;
if ( F_236 ( V_589 , & V_688 . V_764 , sizeof( V_688 . V_764 ) ) )
goto V_114;
V_120 = 0 ;
break;
}
case V_793 : {
V_120 = - V_101 ;
if ( F_235 ( & V_688 . V_764 , V_589 , sizeof( V_688 . V_764 ) ) )
goto V_114;
V_120 = - V_623 ;
if ( ! V_102 -> V_5 . V_743 )
goto V_114;
V_120 = F_305 ( V_102 , & V_688 . V_764 ) ;
break;
}
case V_794 : {
struct V_752 V_753 ;
V_120 = - V_101 ;
if ( F_235 ( & V_753 , V_589 , sizeof( V_753 ) ) )
goto V_114;
V_120 = F_306 ( V_102 , & V_753 ) ;
break;
}
case V_795 : {
V_120 = - V_101 ;
if ( F_235 ( & V_102 -> V_5 . F_184 , V_589 ,
sizeof( struct V_796 ) ) )
goto V_114;
V_120 = - V_606 ;
if ( V_102 -> V_5 . F_184 . V_292 )
goto V_114;
V_120 = 0 ;
break;
}
case V_797 : {
struct V_798 V_799 ;
T_2 V_800 ;
T_12 V_304 ;
V_120 = - V_101 ;
if ( F_235 ( & V_799 , V_589 , sizeof( V_799 ) ) )
goto V_114;
V_120 = - V_606 ;
if ( V_799 . V_292 )
goto V_114;
V_120 = 0 ;
F_321 () ;
V_800 = F_126 () ;
V_304 = V_799 . clock - V_800 ;
F_322 () ;
V_102 -> V_5 . V_241 = V_304 ;
F_158 ( V_102 ) ;
break;
}
case V_801 : {
struct V_798 V_799 ;
T_2 V_800 ;
F_321 () ;
V_800 = F_126 () ;
V_799 . clock = V_102 -> V_5 . V_241 + V_800 ;
F_322 () ;
V_799 . V_292 = 0 ;
memset ( & V_799 . V_640 , 0 , sizeof( V_799 . V_640 ) ) ;
V_120 = - V_101 ;
if ( F_236 ( V_589 , & V_799 , sizeof( V_799 ) ) )
goto V_114;
V_120 = 0 ;
break;
}
default:
V_120 = F_323 ( V_102 , V_587 , V_588 ) ;
}
V_114:
return V_120 ;
}
static void F_324 ( void )
{
T_1 V_802 [ 2 ] ;
unsigned V_3 , V_803 ;
for ( V_3 = V_803 = V_804 ; V_3 < F_53 ( V_597 ) ; V_3 ++ ) {
if ( F_325 ( V_597 [ V_3 ] , & V_802 [ 0 ] , & V_802 [ 1 ] ) < 0 )
continue;
switch ( V_597 [ V_3 ] ) {
case V_805 :
if ( ! V_73 -> V_806 () )
continue;
break;
default:
break;
}
if ( V_803 < V_3 )
V_597 [ V_803 ] = V_597 [ V_3 ] ;
V_803 ++ ;
}
V_594 = V_803 ;
}
static int F_326 ( struct V_1 * V_2 , T_6 V_408 , int V_95 ,
const void * V_263 )
{
int V_807 = 0 ;
int V_525 ;
do {
V_525 = F_327 ( V_95 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_619 &&
! F_328 ( & V_2 -> V_5 . V_619 -> V_808 , V_408 , V_525 , V_263 ) )
&& F_329 ( V_2 -> V_102 , V_809 , V_408 , V_525 , V_263 ) )
break;
V_807 += V_525 ;
V_408 += V_525 ;
V_95 -= V_525 ;
V_263 += V_525 ;
} while ( V_95 );
return V_807 ;
}
static int F_330 ( struct V_1 * V_2 , T_6 V_408 , int V_95 , void * V_263 )
{
int V_807 = 0 ;
int V_525 ;
do {
V_525 = F_327 ( V_95 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_619 &&
! F_331 ( & V_2 -> V_5 . V_619 -> V_808 , V_408 , V_525 , V_263 ) )
&& F_332 ( V_2 -> V_102 , V_809 , V_408 , V_525 , V_263 ) )
break;
F_333 ( V_810 , V_525 , V_408 , * ( T_2 * ) V_263 ) ;
V_807 += V_525 ;
V_408 += V_525 ;
V_95 -= V_525 ;
V_263 += V_525 ;
} while ( V_95 );
return V_807 ;
}
static void F_334 ( struct V_1 * V_2 ,
struct V_811 * V_812 , int V_813 )
{
V_73 -> V_814 ( V_2 , V_812 , V_813 ) ;
}
void F_335 ( struct V_1 * V_2 ,
struct V_811 * V_812 , int V_813 )
{
V_73 -> V_815 ( V_2 , V_812 , V_813 ) ;
}
T_6 F_336 ( struct V_1 * V_2 , T_6 V_428 , T_1 V_96 ,
struct V_75 * V_68 )
{
T_6 V_816 ;
F_13 ( ! F_40 ( V_2 ) ) ;
V_96 |= V_112 ;
V_816 = V_2 -> V_5 . V_84 . V_817 ( V_2 , V_428 , V_96 , V_68 ) ;
return V_816 ;
}
T_6 F_337 ( struct V_1 * V_2 , T_16 V_818 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_112 : 0 ;
return V_2 -> V_5 . V_104 -> V_817 ( V_2 , V_818 , V_96 , V_68 ) ;
}
T_6 F_338 ( struct V_1 * V_2 , T_16 V_818 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_112 : 0 ;
V_96 |= V_819 ;
return V_2 -> V_5 . V_104 -> V_817 ( V_2 , V_818 , V_96 , V_68 ) ;
}
T_6 F_339 ( struct V_1 * V_2 , T_16 V_818 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_112 : 0 ;
V_96 |= V_113 ;
return V_2 -> V_5 . V_104 -> V_817 ( V_2 , V_818 , V_96 , V_68 ) ;
}
T_6 F_340 ( struct V_1 * V_2 , T_16 V_818 ,
struct V_75 * V_68 )
{
return V_2 -> V_5 . V_104 -> V_817 ( V_2 , V_818 , 0 , V_68 ) ;
}
static int F_341 ( T_16 V_408 , void * V_188 , unsigned int V_820 ,
struct V_1 * V_2 , T_1 V_96 ,
struct V_75 * V_68 )
{
void * V_38 = V_188 ;
int V_120 = V_821 ;
while ( V_820 ) {
T_6 V_428 = V_2 -> V_5 . V_104 -> V_817 ( V_2 , V_408 , V_96 ,
V_68 ) ;
unsigned V_94 = V_408 & ( V_108 - 1 ) ;
unsigned V_822 = F_327 ( V_820 , ( unsigned ) V_108 - V_94 ) ;
int V_109 ;
if ( V_428 == V_100 )
return V_823 ;
V_109 = F_50 ( V_2 -> V_102 , V_428 >> V_107 , V_38 ,
V_94 , V_822 ) ;
if ( V_109 < 0 ) {
V_120 = V_824 ;
goto V_114;
}
V_820 -= V_822 ;
V_38 += V_822 ;
V_408 += V_822 ;
}
V_114:
return V_120 ;
}
static int F_342 ( struct V_825 * V_826 ,
T_16 V_408 , void * V_188 , unsigned int V_820 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_343 ( V_826 ) ;
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_112 : 0 ;
unsigned V_94 ;
int V_109 ;
T_6 V_428 = V_2 -> V_5 . V_104 -> V_817 ( V_2 , V_408 , V_96 | V_819 ,
V_68 ) ;
if ( F_152 ( V_428 == V_100 ) )
return V_823 ;
V_94 = V_408 & ( V_108 - 1 ) ;
if ( F_29 ( V_94 + V_820 > V_108 ) )
V_820 = ( unsigned ) V_108 - V_94 ;
V_109 = F_50 ( V_2 -> V_102 , V_428 >> V_107 , V_188 ,
V_94 , V_820 ) ;
if ( F_152 ( V_109 < 0 ) )
return V_824 ;
return V_821 ;
}
int F_344 ( struct V_825 * V_826 ,
T_16 V_408 , void * V_188 , unsigned int V_820 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_343 ( V_826 ) ;
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_112 : 0 ;
return F_341 ( V_408 , V_188 , V_820 , V_2 , V_96 ,
V_68 ) ;
}
static int F_345 ( struct V_825 * V_826 ,
T_16 V_408 , void * V_188 , unsigned int V_820 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_343 ( V_826 ) ;
return F_341 ( V_408 , V_188 , V_820 , V_2 , 0 , V_68 ) ;
}
int F_346 ( struct V_825 * V_826 ,
T_16 V_408 , void * V_188 ,
unsigned int V_820 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_343 ( V_826 ) ;
void * V_38 = V_188 ;
int V_120 = V_821 ;
while ( V_820 ) {
T_6 V_428 = V_2 -> V_5 . V_104 -> V_817 ( V_2 , V_408 ,
V_113 ,
V_68 ) ;
unsigned V_94 = V_408 & ( V_108 - 1 ) ;
unsigned V_827 = F_327 ( V_820 , ( unsigned ) V_108 - V_94 ) ;
int V_109 ;
if ( V_428 == V_100 )
return V_823 ;
V_109 = F_119 ( V_2 -> V_102 , V_428 , V_38 , V_827 ) ;
if ( V_109 < 0 ) {
V_120 = V_824 ;
goto V_114;
}
V_820 -= V_827 ;
V_38 += V_827 ;
V_408 += V_827 ;
}
V_114:
return V_120 ;
}
static int F_347 ( struct V_1 * V_2 , unsigned long V_818 ,
T_6 * V_428 , struct V_75 * V_68 ,
bool V_828 )
{
T_1 V_96 = ( ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_112 : 0 )
| ( V_828 ? V_113 : 0 ) ;
if ( F_348 ( V_2 , V_818 )
&& ! F_349 ( V_2 , V_2 -> V_5 . V_104 ,
V_2 -> V_5 . V_96 , V_96 ) ) {
* V_428 = V_2 -> V_5 . V_829 << V_107 |
( V_818 & ( V_108 - 1 ) ) ;
F_350 ( V_818 , * V_428 , V_828 , false ) ;
return 1 ;
}
* V_428 = V_2 -> V_5 . V_104 -> V_817 ( V_2 , V_818 , V_96 , V_68 ) ;
if ( * V_428 == V_100 )
return - 1 ;
if ( ( * V_428 & V_395 ) == V_830 )
return 1 ;
if ( F_351 ( V_2 , * V_428 ) ) {
F_350 ( V_818 , * V_428 , V_828 , true ) ;
return 1 ;
}
return 0 ;
}
int F_352 ( struct V_1 * V_2 , T_6 V_428 ,
const void * V_188 , int V_820 )
{
int V_109 ;
V_109 = F_119 ( V_2 -> V_102 , V_428 , V_188 , V_820 ) ;
if ( V_109 < 0 )
return 0 ;
F_353 ( V_2 , V_428 , V_188 , V_820 ) ;
return 1 ;
}
static int F_354 ( struct V_1 * V_2 , void * V_188 , int V_820 )
{
if ( V_2 -> V_831 ) {
F_333 ( V_810 , V_820 ,
V_2 -> V_832 [ 0 ] . V_428 , * ( T_2 * ) V_188 ) ;
V_2 -> V_831 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_355 ( struct V_1 * V_2 , T_6 V_428 ,
void * V_188 , int V_820 )
{
return ! F_118 ( V_2 -> V_102 , V_428 , V_188 , V_820 ) ;
}
static int F_356 ( struct V_1 * V_2 , T_6 V_428 ,
void * V_188 , int V_820 )
{
return F_352 ( V_2 , V_428 , V_188 , V_820 ) ;
}
static int F_357 ( struct V_1 * V_2 , T_6 V_428 , int V_820 , void * V_188 )
{
F_333 ( V_833 , V_820 , V_428 , * ( T_2 * ) V_188 ) ;
return F_326 ( V_2 , V_428 , V_820 , V_188 ) ;
}
static int F_358 ( struct V_1 * V_2 , T_6 V_428 ,
void * V_188 , int V_820 )
{
F_333 ( V_834 , V_820 , V_428 , 0 ) ;
return V_824 ;
}
static int F_359 ( struct V_1 * V_2 , T_6 V_428 ,
void * V_188 , int V_820 )
{
struct V_835 * V_836 = & V_2 -> V_832 [ 0 ] ;
memcpy ( V_2 -> V_837 -> V_838 . V_38 , V_836 -> V_38 , F_327 ( 8u , V_836 -> V_95 ) ) ;
return V_821 ;
}
static int F_360 ( unsigned long V_408 , void * V_188 ,
unsigned int V_820 ,
struct V_75 * V_68 ,
struct V_1 * V_2 ,
const struct V_839 * V_840 )
{
T_6 V_428 ;
int V_807 , V_109 ;
bool V_828 = V_840 -> V_828 ;
struct V_835 * V_836 ;
V_109 = F_347 ( V_2 , V_408 , & V_428 , V_68 , V_828 ) ;
if ( V_109 < 0 )
return V_823 ;
if ( V_109 )
goto V_838;
if ( V_840 -> V_841 ( V_2 , V_428 , V_188 , V_820 ) )
return V_821 ;
V_838:
V_807 = V_840 -> V_842 ( V_2 , V_428 , V_820 , V_188 ) ;
if ( V_807 == V_820 )
return V_821 ;
V_428 += V_807 ;
V_820 -= V_807 ;
V_188 += V_807 ;
F_29 ( V_2 -> V_843 >= V_844 ) ;
V_836 = & V_2 -> V_832 [ V_2 -> V_843 ++ ] ;
V_836 -> V_428 = V_428 ;
V_836 -> V_38 = V_188 ;
V_836 -> V_95 = V_820 ;
return V_821 ;
}
int F_361 ( struct V_825 * V_826 , unsigned long V_408 ,
void * V_188 , unsigned int V_820 ,
struct V_75 * V_68 ,
const struct V_839 * V_840 )
{
struct V_1 * V_2 = F_343 ( V_826 ) ;
T_6 V_428 ;
int V_845 ;
if ( V_840 -> V_846 &&
V_840 -> V_846 ( V_2 , V_188 , V_820 ) )
return V_821 ;
V_2 -> V_843 = 0 ;
if ( ( ( V_408 + V_820 - 1 ) ^ V_408 ) & V_395 ) {
int V_847 ;
V_847 = - V_408 & ~ V_395 ;
V_845 = F_360 ( V_408 , V_188 , V_847 , V_68 ,
V_2 , V_840 ) ;
if ( V_845 != V_821 )
return V_845 ;
V_408 += V_847 ;
if ( V_826 -> V_315 != V_848 )
V_408 = ( T_1 ) V_408 ;
V_188 += V_847 ;
V_820 -= V_847 ;
}
V_845 = F_360 ( V_408 , V_188 , V_820 , V_68 ,
V_2 , V_840 ) ;
if ( V_845 != V_821 )
return V_845 ;
if ( ! V_2 -> V_843 )
return V_845 ;
V_428 = V_2 -> V_832 [ 0 ] . V_428 ;
V_2 -> V_849 = 1 ;
V_2 -> V_850 = 0 ;
V_2 -> V_837 -> V_838 . V_95 = F_327 ( 8u , V_2 -> V_832 [ 0 ] . V_95 ) ;
V_2 -> V_837 -> V_838 . V_851 = V_2 -> V_852 = V_840 -> V_828 ;
V_2 -> V_837 -> V_853 = V_854 ;
V_2 -> V_837 -> V_838 . V_855 = V_428 ;
return V_840 -> V_856 ( V_2 , V_428 , V_188 , V_820 ) ;
}
static int F_362 ( struct V_825 * V_826 ,
unsigned long V_408 ,
void * V_188 ,
unsigned int V_820 ,
struct V_75 * V_68 )
{
return F_361 ( V_826 , V_408 , V_188 , V_820 ,
V_68 , & V_857 ) ;
}
int F_363 ( struct V_825 * V_826 ,
unsigned long V_408 ,
const void * V_188 ,
unsigned int V_820 ,
struct V_75 * V_68 )
{
return F_361 ( V_826 , V_408 , ( void * ) V_188 , V_820 ,
V_68 , & V_858 ) ;
}
static int F_364 ( struct V_825 * V_826 ,
unsigned long V_408 ,
const void * V_859 ,
const void * V_860 ,
unsigned int V_820 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_343 ( V_826 ) ;
T_6 V_428 ;
struct V_397 * V_397 ;
char * V_861 ;
bool V_862 ;
if ( V_820 > 8 || ( V_820 & ( V_820 - 1 ) ) )
goto V_863;
V_428 = F_339 ( V_2 , V_408 , NULL ) ;
if ( V_428 == V_100 ||
( V_428 & V_395 ) == V_830 )
goto V_863;
if ( ( ( V_428 + V_820 - 1 ) & V_395 ) != ( V_428 & V_395 ) )
goto V_863;
V_397 = F_365 ( V_2 -> V_102 , V_428 >> V_107 ) ;
if ( F_366 ( V_397 ) )
goto V_863;
V_861 = F_367 ( V_397 ) ;
V_861 += F_368 ( V_428 ) ;
switch ( V_820 ) {
case 1 :
V_862 = F_369 ( T_14 , V_861 , V_859 , V_860 ) ;
break;
case 2 :
V_862 = F_369 ( V_864 , V_861 , V_859 , V_860 ) ;
break;
case 4 :
V_862 = F_369 ( T_1 , V_861 , V_859 , V_860 ) ;
break;
case 8 :
V_862 = F_370 ( V_861 , V_859 , V_860 ) ;
break;
default:
F_26 () ;
}
F_371 ( V_861 ) ;
F_372 ( V_397 ) ;
if ( ! V_862 )
return V_865 ;
F_195 ( V_2 -> V_102 , V_428 >> V_107 ) ;
F_353 ( V_2 , V_428 , V_860 , V_820 ) ;
return V_821 ;
V_863:
F_373 ( V_866 L_22 ) ;
return F_363 ( V_826 , V_408 , V_860 , V_820 , V_68 ) ;
}
static int F_374 ( struct V_1 * V_2 , void * V_867 )
{
int V_120 ;
if ( V_2 -> V_5 . V_868 . V_869 )
V_120 = F_332 ( V_2 -> V_102 , V_776 , V_2 -> V_5 . V_868 . V_870 ,
V_2 -> V_5 . V_868 . V_526 , V_867 ) ;
else
V_120 = F_329 ( V_2 -> V_102 , V_776 ,
V_2 -> V_5 . V_868 . V_870 , V_2 -> V_5 . V_868 . V_526 ,
V_867 ) ;
return V_120 ;
}
static int F_375 ( struct V_1 * V_2 , int V_526 ,
unsigned short V_870 , void * V_188 ,
unsigned int V_746 , bool V_869 )
{
V_2 -> V_5 . V_868 . V_870 = V_870 ;
V_2 -> V_5 . V_868 . V_869 = V_869 ;
V_2 -> V_5 . V_868 . V_746 = V_746 ;
V_2 -> V_5 . V_868 . V_526 = V_526 ;
if ( ! F_374 ( V_2 , V_2 -> V_5 . V_871 ) ) {
V_2 -> V_5 . V_868 . V_746 = 0 ;
return 1 ;
}
V_2 -> V_837 -> V_853 = V_872 ;
V_2 -> V_837 -> V_873 . V_874 = V_869 ? V_875 : V_876 ;
V_2 -> V_837 -> V_873 . V_526 = V_526 ;
V_2 -> V_837 -> V_873 . V_877 = V_878 * V_108 ;
V_2 -> V_837 -> V_873 . V_746 = V_746 ;
V_2 -> V_837 -> V_873 . V_870 = V_870 ;
return 0 ;
}
static int F_376 ( struct V_825 * V_826 ,
int V_526 , unsigned short V_870 , void * V_188 ,
unsigned int V_746 )
{
struct V_1 * V_2 = F_343 ( V_826 ) ;
int V_109 ;
if ( V_2 -> V_5 . V_868 . V_746 )
goto V_879;
V_109 = F_375 ( V_2 , V_526 , V_870 , V_188 , V_746 , true ) ;
if ( V_109 ) {
V_879:
memcpy ( V_188 , V_2 -> V_5 . V_871 , V_526 * V_746 ) ;
F_377 ( V_880 , V_870 , V_526 , V_746 , V_2 -> V_5 . V_871 ) ;
V_2 -> V_5 . V_868 . V_746 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_378 ( struct V_825 * V_826 ,
int V_526 , unsigned short V_870 ,
const void * V_188 , unsigned int V_746 )
{
struct V_1 * V_2 = F_343 ( V_826 ) ;
memcpy ( V_2 -> V_5 . V_871 , V_188 , V_526 * V_746 ) ;
F_377 ( V_881 , V_870 , V_526 , V_746 , V_2 -> V_5 . V_871 ) ;
return F_375 ( V_2 , V_526 , V_870 , ( void * ) V_188 , V_746 , false ) ;
}
static unsigned long F_379 ( struct V_1 * V_2 , int V_813 )
{
return V_73 -> F_379 ( V_2 , V_813 ) ;
}
static void F_380 ( struct V_825 * V_826 , V_172 V_80 )
{
F_381 ( F_343 ( V_826 ) , V_80 ) ;
}
int F_382 ( struct V_1 * V_2 )
{
if ( ! F_244 ( V_2 ) )
return V_821 ;
if ( V_73 -> V_608 () ) {
int V_23 = F_383 () ;
F_247 ( V_23 , V_2 -> V_5 . V_609 ) ;
F_384 ( V_2 -> V_5 . V_609 ,
F_242 , NULL , 1 ) ;
F_385 () ;
F_386 ( V_2 -> V_5 . V_609 ) ;
} else
F_243 () ;
return V_821 ;
}
static void F_387 ( struct V_825 * V_826 )
{
F_382 ( F_343 ( V_826 ) ) ;
}
int F_388 ( struct V_825 * V_826 , int V_89 , unsigned long * V_659 )
{
return F_97 ( F_343 ( V_826 ) , V_89 , V_659 ) ;
}
int F_389 ( struct V_825 * V_826 , int V_89 , unsigned long V_22 )
{
return F_95 ( F_343 ( V_826 ) , V_89 , V_22 ) ;
}
static T_2 F_390 ( T_2 V_882 , T_1 V_883 )
{
return ( V_882 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_883 ;
}
static unsigned long F_391 ( struct V_825 * V_826 , int V_884 )
{
struct V_1 * V_2 = F_343 ( V_826 ) ;
unsigned long V_22 ;
switch ( V_884 ) {
case 0 :
V_22 = F_62 ( V_2 ) ;
break;
case 2 :
V_22 = V_2 -> V_5 . V_79 ;
break;
case 3 :
V_22 = F_60 ( V_2 ) ;
break;
case 4 :
V_22 = F_76 ( V_2 ) ;
break;
case 8 :
V_22 = F_89 ( V_2 ) ;
break;
default:
F_392 ( L_23 , V_258 , V_884 ) ;
return 0 ;
}
return V_22 ;
}
static int F_393 ( struct V_825 * V_826 , int V_884 , V_172 V_188 )
{
struct V_1 * V_2 = F_343 ( V_826 ) ;
int V_885 = 0 ;
switch ( V_884 ) {
case 0 :
V_885 = F_61 ( V_2 , F_390 ( F_62 ( V_2 ) , V_188 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_79 = V_188 ;
break;
case 3 :
V_885 = F_83 ( V_2 , V_188 ) ;
break;
case 4 :
V_885 = F_75 ( V_2 , F_390 ( F_76 ( V_2 ) , V_188 ) ) ;
break;
case 8 :
V_885 = F_86 ( V_2 , V_188 ) ;
break;
default:
F_392 ( L_23 , V_258 , V_884 ) ;
V_885 = - 1 ;
}
return V_885 ;
}
static int F_394 ( struct V_825 * V_826 )
{
return V_73 -> V_88 ( F_343 ( V_826 ) ) ;
}
static void F_395 ( struct V_825 * V_826 , struct V_886 * V_887 )
{
V_73 -> V_888 ( F_343 ( V_826 ) , V_887 ) ;
}
static void F_396 ( struct V_825 * V_826 , struct V_886 * V_887 )
{
V_73 -> V_889 ( F_343 ( V_826 ) , V_887 ) ;
}
static void F_397 ( struct V_825 * V_826 , struct V_886 * V_887 )
{
V_73 -> V_890 ( F_343 ( V_826 ) , V_887 ) ;
}
static void F_398 ( struct V_825 * V_826 , struct V_886 * V_887 )
{
V_73 -> V_891 ( F_343 ( V_826 ) , V_887 ) ;
}
static unsigned long F_399 (
struct V_825 * V_826 , int V_813 )
{
return F_379 ( F_343 ( V_826 ) , V_813 ) ;
}
static bool F_400 ( struct V_825 * V_826 , V_864 * V_892 ,
struct V_893 * V_894 , T_1 * V_895 ,
int V_813 )
{
struct V_811 V_812 ;
F_335 ( F_343 ( V_826 ) , & V_812 , V_813 ) ;
* V_892 = V_812 . V_892 ;
if ( V_812 . V_896 ) {
memset ( V_894 , 0 , sizeof( * V_894 ) ) ;
return false ;
}
if ( V_812 . V_897 )
V_812 . V_898 >>= 12 ;
F_401 ( V_894 , V_812 . V_898 ) ;
F_402 ( V_894 , ( unsigned long ) V_812 . V_899 ) ;
#ifdef F_63
if ( V_895 )
* V_895 = V_812 . V_899 >> 32 ;
#endif
V_894 -> type = V_812 . type ;
V_894 -> V_616 = V_812 . V_616 ;
V_894 -> V_900 = V_812 . V_900 ;
V_894 -> V_366 = V_812 . V_901 ;
V_894 -> V_902 = V_812 . V_902 ;
V_894 -> V_903 = V_812 . V_903 ;
V_894 -> V_904 = V_812 . V_189 ;
V_894 -> V_897 = V_812 . V_897 ;
return true ;
}
static void F_403 ( struct V_825 * V_826 , V_864 V_892 ,
struct V_893 * V_894 , T_1 V_895 ,
int V_813 )
{
struct V_1 * V_2 = F_343 ( V_826 ) ;
struct V_811 V_812 ;
V_812 . V_892 = V_892 ;
V_812 . V_899 = F_404 ( V_894 ) ;
#ifdef F_63
V_812 . V_899 |= ( ( T_2 ) V_895 ) << 32 ;
#endif
V_812 . V_898 = F_405 ( V_894 ) ;
if ( V_894 -> V_897 )
V_812 . V_898 = ( V_812 . V_898 << 12 ) | 0xfff ;
V_812 . type = V_894 -> type ;
V_812 . V_900 = V_894 -> V_900 ;
V_812 . V_189 = V_894 -> V_904 ;
V_812 . V_616 = V_894 -> V_616 ;
V_812 . V_903 = V_894 -> V_903 ;
V_812 . V_897 = V_894 -> V_897 ;
V_812 . V_902 = V_894 -> V_902 ;
V_812 . V_901 = V_894 -> V_366 ;
V_812 . V_896 = ! V_812 . V_901 ;
V_812 . V_905 = 0 ;
F_334 ( V_2 , & V_812 , V_813 ) ;
return;
}
static int F_406 ( struct V_825 * V_826 ,
T_1 V_499 , T_2 * V_500 )
{
return F_219 ( F_343 ( V_826 ) , V_499 , V_500 ) ;
}
static int F_407 ( struct V_825 * V_826 ,
T_1 V_499 , T_2 V_38 )
{
struct V_32 V_21 ;
V_21 . V_38 = V_38 ;
V_21 . V_144 = V_499 ;
V_21 . V_40 = false ;
return F_107 ( F_343 ( V_826 ) , & V_21 ) ;
}
static int F_408 ( struct V_825 * V_826 ,
T_1 V_906 )
{
return F_409 ( F_343 ( V_826 ) , V_906 ) ;
}
static int F_410 ( struct V_825 * V_826 ,
T_1 V_906 , T_2 * V_500 )
{
return F_100 ( F_343 ( V_826 ) , V_906 , V_500 ) ;
}
static void F_411 ( struct V_825 * V_826 )
{
F_343 ( V_826 ) -> V_5 . V_907 = 1 ;
}
static void F_412 ( struct V_825 * V_826 )
{
F_212 () ;
F_413 ( F_343 ( V_826 ) ) ;
F_414 () ;
}
static void F_415 ( struct V_825 * V_826 )
{
F_213 () ;
}
static int F_416 ( struct V_825 * V_826 ,
struct V_908 * V_909 ,
enum V_910 V_911 )
{
return V_73 -> V_912 ( F_343 ( V_826 ) , V_909 , V_911 ) ;
}
static void F_417 ( struct V_825 * V_826 ,
T_1 * V_913 , T_1 * V_914 , T_1 * V_195 , T_1 * V_203 )
{
V_695 ( F_343 ( V_826 ) , V_913 , V_914 , V_195 , V_203 ) ;
}
static V_172 F_418 ( struct V_825 * V_826 , unsigned V_915 )
{
return F_99 ( F_343 ( V_826 ) , V_915 ) ;
}
static void F_419 ( struct V_825 * V_826 , unsigned V_915 , V_172 V_188 )
{
F_101 ( F_343 ( V_826 ) , V_915 , V_188 ) ;
}
static void F_420 ( struct V_825 * V_826 , bool V_648 )
{
V_73 -> V_656 ( F_343 ( V_826 ) , V_648 ) ;
}
static void F_421 ( struct V_1 * V_2 , T_1 V_28 )
{
T_1 V_916 = V_73 -> V_644 ( V_2 ) ;
if ( V_916 & V_28 )
V_28 = 0 ;
if ( F_152 ( V_916 || V_28 ) ) {
V_73 -> V_655 ( V_2 , V_28 ) ;
if ( ! V_28 )
F_31 ( V_67 , V_2 ) ;
}
}
static bool F_422 ( struct V_1 * V_2 )
{
struct V_825 * V_826 = & V_2 -> V_5 . V_917 ;
if ( V_826 -> V_68 . V_41 == V_42 )
return F_39 ( V_2 , & V_826 -> V_68 ) ;
if ( V_826 -> V_68 . V_918 )
F_38 ( V_2 , V_826 -> V_68 . V_41 ,
V_826 -> V_68 . V_62 ) ;
else
F_33 ( V_2 , V_826 -> V_68 . V_41 ) ;
return false ;
}
static void F_423 ( struct V_1 * V_2 )
{
struct V_825 * V_826 = & V_2 -> V_5 . V_917 ;
int V_133 , V_134 ;
V_73 -> V_135 ( V_2 , & V_133 , & V_134 ) ;
V_826 -> V_919 = F_424 ( V_2 ) ;
V_826 -> V_920 = F_425 ( V_2 ) ;
V_826 -> V_315 = ( ! F_32 ( V_2 ) ) ? V_921 :
( V_826 -> V_919 & V_922 ) ? V_923 :
( V_134 && F_57 ( V_2 ) ) ? V_848 :
V_133 ? V_924 :
V_925 ;
V_826 -> V_926 = F_426 ( V_2 ) ;
F_427 ( V_826 ) ;
V_2 -> V_5 . V_927 = false ;
}
int F_428 ( struct V_1 * V_2 , int V_621 , int V_928 )
{
struct V_825 * V_826 = & V_2 -> V_5 . V_917 ;
int V_109 ;
F_423 ( V_2 ) ;
V_826 -> V_929 = 2 ;
V_826 -> V_930 = 2 ;
V_826 -> V_931 = V_826 -> V_920 + V_928 ;
V_109 = F_429 ( V_826 , V_621 ) ;
if ( V_109 != V_821 )
return V_932 ;
V_826 -> V_920 = V_826 -> V_931 ;
F_430 ( V_2 , V_826 -> V_920 ) ;
F_431 ( V_2 , V_826 -> V_919 ) ;
if ( V_621 == V_51 )
V_2 -> V_5 . V_647 = 0 ;
else
V_2 -> V_5 . V_641 . V_69 = false ;
return V_933 ;
}
static int F_432 ( struct V_1 * V_2 )
{
int V_120 = V_933 ;
++ V_2 -> V_77 . V_934 ;
F_433 ( V_2 ) ;
if ( ! F_426 ( V_2 ) && V_73 -> V_88 ( V_2 ) == 0 ) {
V_2 -> V_837 -> V_853 = V_935 ;
V_2 -> V_837 -> V_936 . V_937 = V_938 ;
V_2 -> V_837 -> V_936 . V_939 = 0 ;
V_120 = V_932 ;
}
F_33 ( V_2 , V_91 ) ;
return V_120 ;
}
static bool F_434 ( struct V_1 * V_2 , T_16 V_79 ,
bool V_940 ,
int V_941 )
{
T_6 V_428 = V_79 ;
T_17 V_942 ;
if ( V_941 & V_943 )
return false ;
if ( ! V_2 -> V_5 . V_84 . V_944 ) {
V_428 = F_339 ( V_2 , V_79 , NULL ) ;
if ( V_428 == V_100 )
return true ;
}
V_942 = F_435 ( V_2 -> V_102 , F_49 ( V_428 ) ) ;
if ( F_436 ( V_942 ) )
return false ;
F_437 ( V_942 ) ;
if ( V_2 -> V_5 . V_84 . V_944 ) {
unsigned int V_945 ;
F_143 ( & V_2 -> V_102 -> V_946 ) ;
V_945 = V_2 -> V_102 -> V_5 . V_945 ;
F_144 ( & V_2 -> V_102 -> V_946 ) ;
if ( V_945 )
F_438 ( V_2 -> V_102 , F_49 ( V_428 ) ) ;
return true ;
}
F_438 ( V_2 -> V_102 , F_49 ( V_428 ) ) ;
return ! V_940 ;
}
static bool F_439 ( struct V_825 * V_826 ,
unsigned long V_79 , int V_941 )
{
struct V_1 * V_2 = F_343 ( V_826 ) ;
unsigned long V_947 , V_948 , V_428 = V_79 ;
V_947 = V_2 -> V_5 . V_947 ;
V_948 = V_2 -> V_5 . V_948 ;
V_2 -> V_5 . V_947 = V_2 -> V_5 . V_948 = 0 ;
if ( ! ( V_941 & V_949 ) )
return false ;
if ( F_440 ( V_826 ) )
return false ;
if ( V_826 -> V_920 == V_947 && V_948 == V_79 )
return false ;
V_2 -> V_5 . V_947 = V_826 -> V_920 ;
V_2 -> V_5 . V_948 = V_79 ;
if ( ! V_2 -> V_5 . V_84 . V_944 )
V_428 = F_339 ( V_2 , V_79 , NULL ) ;
F_438 ( V_2 -> V_102 , F_49 ( V_428 ) ) ;
return true ;
}
static int F_441 ( unsigned long V_408 , T_1 type , T_1 V_179 ,
unsigned long * V_189 )
{
T_1 V_178 = 0 ;
int V_3 ;
T_1 V_950 , V_951 ;
V_950 = V_179 ;
V_951 = V_179 >> 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ , V_950 >>= 2 , V_951 >>= 4 )
if ( ( V_950 & 3 ) && ( V_951 & 15 ) == type && V_189 [ V_3 ] == V_408 )
V_178 |= ( 1 << V_3 ) ;
return V_178 ;
}
static void F_442 ( struct V_1 * V_2 , unsigned long V_952 , int * V_120 )
{
struct V_953 * V_953 = V_2 -> V_837 ;
if ( F_152 ( V_952 & V_954 ) ) {
if ( V_2 -> V_175 & V_955 ) {
V_953 -> V_956 . V_5 . V_178 = V_957 | V_186 |
V_187 ;
V_953 -> V_956 . V_5 . V_958 = V_2 -> V_5 . V_959 ;
V_953 -> V_956 . V_5 . V_68 = V_53 ;
V_953 -> V_853 = V_960 ;
* V_120 = V_961 ;
} else {
V_2 -> V_5 . V_917 . V_919 &= ~ V_954 ;
V_2 -> V_5 . V_178 &= ~ 15 ;
V_2 -> V_5 . V_178 |= V_957 | V_187 ;
F_33 ( V_2 , V_53 ) ;
}
}
}
static bool F_443 ( struct V_1 * V_2 , int * V_120 )
{
if ( F_152 ( V_2 -> V_175 & V_176 ) &&
( V_2 -> V_5 . V_180 & V_184 ) ) {
struct V_953 * V_953 = V_2 -> V_837 ;
unsigned long V_920 = F_444 ( V_2 ) ;
T_1 V_178 = F_441 ( V_920 , 0 ,
V_2 -> V_5 . V_180 ,
V_2 -> V_5 . V_190 ) ;
if ( V_178 != 0 ) {
V_953 -> V_956 . V_5 . V_178 = V_178 | V_186 | V_187 ;
V_953 -> V_956 . V_5 . V_958 = V_920 ;
V_953 -> V_956 . V_5 . V_68 = V_53 ;
V_953 -> V_853 = V_960 ;
* V_120 = V_961 ;
return true ;
}
}
if ( F_152 ( V_2 -> V_5 . V_179 & V_184 ) &&
! ( F_424 ( V_2 ) & V_962 ) ) {
unsigned long V_920 = F_444 ( V_2 ) ;
T_1 V_178 = F_441 ( V_920 , 0 ,
V_2 -> V_5 . V_179 ,
V_2 -> V_5 . V_189 ) ;
if ( V_178 != 0 ) {
V_2 -> V_5 . V_178 &= ~ 15 ;
V_2 -> V_5 . V_178 |= V_178 | V_187 ;
F_33 ( V_2 , V_53 ) ;
* V_120 = V_933 ;
return true ;
}
}
return false ;
}
int F_445 ( struct V_1 * V_2 ,
unsigned long V_79 ,
int V_941 ,
void * V_963 ,
int V_964 )
{
int V_120 ;
struct V_825 * V_826 = & V_2 -> V_5 . V_917 ;
bool V_524 = true ;
bool V_965 = V_2 -> V_5 . V_940 ;
V_2 -> V_5 . V_940 = false ;
F_446 ( V_2 ) ;
if ( ! ( V_941 & V_966 ) ) {
F_423 ( V_2 ) ;
if ( F_443 ( V_2 , & V_120 ) )
return V_120 ;
V_826 -> V_967 = 0 ;
V_826 -> V_968 = false ;
V_826 -> V_68 . V_41 = - 1 ;
V_826 -> V_969 = false ;
V_826 -> V_970 = V_941 & V_971 ;
V_120 = F_447 ( V_826 , V_963 , V_964 ) ;
F_448 ( V_2 ) ;
++ V_2 -> V_77 . V_972 ;
if ( V_120 != V_973 ) {
if ( V_941 & V_971 )
return V_932 ;
if ( F_434 ( V_2 , V_79 , V_965 ,
V_941 ) )
return V_933 ;
if ( V_941 & V_974 )
return V_932 ;
return F_432 ( V_2 ) ;
}
}
if ( V_941 & V_974 ) {
F_430 ( V_2 , V_826 -> V_931 ) ;
if ( V_826 -> V_919 & V_962 )
F_431 ( V_2 , V_826 -> V_919 & ~ V_962 ) ;
return V_933 ;
}
if ( F_439 ( V_826 , V_79 , V_941 ) )
return V_933 ;
if ( V_2 -> V_5 . V_927 ) {
V_2 -> V_5 . V_927 = false ;
F_449 ( V_826 ) ;
}
V_975:
V_120 = F_450 ( V_826 ) ;
if ( V_120 == V_976 )
return V_933 ;
if ( V_120 == V_977 ) {
if ( F_434 ( V_2 , V_79 , V_965 ,
V_941 ) )
return V_933 ;
return F_432 ( V_2 ) ;
}
if ( V_826 -> V_968 ) {
V_120 = V_933 ;
if ( F_422 ( V_2 ) )
return V_120 ;
} else if ( V_2 -> V_5 . V_868 . V_746 ) {
if ( ! V_2 -> V_5 . V_868 . V_869 ) {
V_2 -> V_5 . V_868 . V_746 = 0 ;
} else {
V_524 = false ;
V_2 -> V_5 . V_978 = V_979 ;
}
V_120 = V_961 ;
} else if ( V_2 -> V_849 ) {
if ( ! V_2 -> V_852 )
V_524 = false ;
V_120 = V_961 ;
V_2 -> V_5 . V_978 = V_980 ;
} else if ( V_120 == V_981 )
goto V_975;
else
V_120 = V_933 ;
if ( V_524 ) {
unsigned long V_952 = V_73 -> V_982 ( V_2 ) ;
F_421 ( V_2 , V_826 -> V_967 ) ;
V_2 -> V_5 . V_983 = false ;
F_430 ( V_2 , V_826 -> V_920 ) ;
if ( V_120 == V_933 )
F_442 ( V_2 , V_952 , & V_120 ) ;
if ( ! V_826 -> V_968 ||
F_28 ( V_826 -> V_68 . V_41 ) == V_56 )
F_451 ( V_2 , V_826 -> V_919 ) ;
if ( F_152 ( ( V_826 -> V_919 & ~ V_952 ) & V_984 ) )
F_31 ( V_67 , V_2 ) ;
} else
V_2 -> V_5 . V_983 = true ;
return V_120 ;
}
int F_452 ( struct V_1 * V_2 , int V_526 , unsigned short V_870 )
{
unsigned long V_188 = F_99 ( V_2 , V_197 ) ;
int V_109 = F_378 ( & V_2 -> V_5 . V_917 ,
V_526 , V_870 , & V_188 , 1 ) ;
V_2 -> V_5 . V_868 . V_746 = 0 ;
return V_109 ;
}
static void F_453 ( void * V_909 )
{
F_454 ( V_331 , 0 ) ;
}
static void F_455 ( void * V_38 )
{
struct V_985 * V_986 = V_38 ;
unsigned long V_261 = 0 ;
if ( V_38 )
V_261 = V_986 -> V_860 ;
else if ( ! F_456 ( V_987 ) )
V_261 = F_457 ( F_458 () ) ;
if ( ! V_261 )
V_261 = V_270 ;
F_454 ( V_331 , V_261 ) ;
}
static int F_459 ( struct V_988 * V_989 , unsigned long V_188 ,
void * V_38 )
{
struct V_985 * V_986 = V_38 ;
struct V_102 * V_102 ;
struct V_1 * V_2 ;
int V_3 , V_990 = 0 ;
if ( V_188 == V_991 && V_986 -> V_859 > V_986 -> V_860 )
return 0 ;
if ( V_188 == V_992 && V_986 -> V_859 < V_986 -> V_860 )
return 0 ;
F_248 ( V_986 -> V_23 , F_455 , V_986 , 1 ) ;
F_143 ( & V_993 ) ;
F_460 (kvm, &vm_list, vm_list) {
F_160 (i, vcpu, kvm) {
if ( V_2 -> V_23 != V_986 -> V_23 )
continue;
F_31 ( V_322 , V_2 ) ;
if ( V_2 -> V_23 != F_8 () )
V_990 = 1 ;
}
}
F_144 ( & V_993 ) ;
if ( V_986 -> V_859 < V_986 -> V_860 && V_990 ) {
F_248 ( V_986 -> V_23 , F_455 , V_986 , 1 ) ;
}
return 0 ;
}
static int F_461 ( struct V_988 * V_994 ,
unsigned long V_995 , void * V_996 )
{
unsigned int V_23 = ( unsigned long ) V_996 ;
switch ( V_995 ) {
case V_997 :
case V_998 :
F_248 ( V_23 , F_455 , NULL , 1 ) ;
break;
case V_999 :
F_248 ( V_23 , F_453 , NULL , 1 ) ;
break;
}
return V_1000 ;
}
static void F_462 ( void )
{
int V_23 ;
V_1001 = V_270 ;
F_463 () ;
if ( ! F_456 ( V_987 ) ) {
#ifdef F_464
struct V_1002 V_1003 ;
memset ( & V_1003 , 0 , sizeof( V_1003 ) ) ;
V_23 = F_383 () ;
F_465 ( & V_1003 , V_23 ) ;
if ( V_1003 . V_1004 . V_1005 )
V_1001 = V_1003 . V_1004 . V_1005 ;
F_385 () ;
#endif
F_466 ( & V_1006 ,
V_1007 ) ;
}
F_125 ( L_24 , V_1001 ) ;
F_467 (cpu)
F_248 ( V_23 , F_455 , NULL , 1 ) ;
F_468 ( & V_1008 ) ;
F_469 () ;
}
int F_470 ( void )
{
return F_164 ( V_1009 ) != NULL ;
}
static int F_471 ( void )
{
int V_1010 = 3 ;
if ( F_164 ( V_1009 ) )
V_1010 = V_73 -> V_88 ( F_164 ( V_1009 ) ) ;
return V_1010 != 0 ;
}
static unsigned long F_472 ( void )
{
unsigned long V_1011 = 0 ;
if ( F_164 ( V_1009 ) )
V_1011 = F_425 ( F_164 ( V_1009 ) ) ;
return V_1011 ;
}
void F_473 ( struct V_1 * V_2 )
{
F_454 ( V_1009 , V_2 ) ;
}
void F_474 ( struct V_1 * V_2 )
{
F_454 ( V_1009 , NULL ) ;
}
static void F_475 ( void )
{
T_2 V_28 ;
int V_1012 = V_1013 . V_1014 ;
V_28 = F_476 ( V_1012 , 51 ) ;
V_28 |= 0x3ull << 62 ;
V_28 |= 1ull ;
#ifdef F_63
if ( V_1012 == 52 )
V_28 &= ~ 1ull ;
#endif
F_477 ( V_28 ) ;
}
static void F_478 ( struct V_344 * V_345 )
{
struct V_102 * V_102 ;
struct V_1 * V_2 ;
int V_3 ;
F_143 ( & V_993 ) ;
F_460 (kvm, &vm_list, vm_list)
F_160 (i, vcpu, kvm)
F_31 ( V_285 , V_2 ) ;
F_156 ( & V_321 , 0 ) ;
F_144 ( & V_993 ) ;
}
static int F_479 ( struct V_988 * V_989 , unsigned long V_1015 ,
void * V_1016 )
{
struct V_220 * V_280 = & V_220 ;
struct V_218 * V_219 = V_1016 ;
F_111 ( V_219 ) ;
if ( V_280 -> clock . V_227 != V_284 &&
F_135 ( & V_321 ) != 0 )
F_480 ( V_1017 , & V_1018 ) ;
return 0 ;
}
int F_481 ( void * V_1019 )
{
int V_120 ;
struct V_73 * V_840 = V_1019 ;
if ( V_73 ) {
F_10 ( V_26 L_25 ) ;
V_120 = - V_774 ;
goto V_114;
}
if ( ! V_840 -> V_1020 () ) {
F_10 ( V_26 L_26 ) ;
V_120 = - V_1021 ;
goto V_114;
}
if ( V_840 -> V_1022 () ) {
F_10 ( V_26 L_27 ) ;
V_120 = - V_1021 ;
goto V_114;
}
V_120 = - V_399 ;
V_25 = F_482 ( struct V_11 ) ;
if ( ! V_25 ) {
F_10 ( V_26 L_28 ) ;
goto V_114;
}
V_120 = F_483 () ;
if ( V_120 )
goto V_1023;
F_475 () ;
V_73 = V_840 ;
F_324 () ;
F_484 ( V_1024 , V_1025 ,
V_1026 , V_1027 , 0 ) ;
F_462 () ;
F_485 ( & V_1028 ) ;
if ( V_582 )
V_143 = F_486 ( V_141 ) ;
F_487 () ;
#ifdef F_63
F_488 ( & V_1029 ) ;
#endif
return 0 ;
V_1023:
F_489 ( V_25 ) ;
V_114:
return V_120 ;
}
void F_490 ( void )
{
F_491 ( & V_1028 ) ;
if ( ! F_456 ( V_987 ) )
F_492 ( & V_1006 ,
V_1007 ) ;
F_493 ( & V_1008 ) ;
#ifdef F_63
F_494 ( & V_1029 ) ;
#endif
V_73 = NULL ;
F_495 () ;
F_489 ( V_25 ) ;
}
int F_496 ( struct V_1 * V_2 )
{
++ V_2 -> V_77 . V_1030 ;
if ( F_87 ( V_2 -> V_102 ) ) {
V_2 -> V_5 . V_1031 = V_1032 ;
return 1 ;
} else {
V_2 -> V_837 -> V_853 = V_1033 ;
return 0 ;
}
}
int F_497 ( struct V_1 * V_2 )
{
T_2 V_1034 , V_1035 , V_1036 , V_109 ;
T_18 V_1037 , V_1038 , V_1039 , V_885 = V_1040 , V_1041 = 0 ;
bool V_1042 , V_1043 ;
if ( V_73 -> V_88 ( V_2 ) != 0 || ! F_32 ( V_2 ) ) {
F_33 ( V_2 , V_91 ) ;
return 0 ;
}
V_1043 = F_498 ( V_2 ) ;
if ( ! V_1043 ) {
V_1034 = ( ( T_2 ) F_99 ( V_2 , V_198 ) << 32 ) |
( F_99 ( V_2 , V_197 ) & 0xffffffff ) ;
V_1035 = ( ( T_2 ) F_99 ( V_2 , V_1044 ) << 32 ) |
( F_99 ( V_2 , V_196 ) & 0xffffffff ) ;
V_1036 = ( ( T_2 ) F_99 ( V_2 , V_1045 ) << 32 ) |
( F_99 ( V_2 , V_1046 ) & 0xffffffff ) ;
}
#ifdef F_63
else {
V_1034 = F_99 ( V_2 , V_196 ) ;
V_1035 = F_99 ( V_2 , V_198 ) ;
V_1036 = F_99 ( V_2 , V_1047 ) ;
}
#endif
V_1037 = V_1034 & 0xffff ;
V_1042 = ( V_1034 >> 16 ) & 0x1 ;
V_1039 = ( V_1034 >> 32 ) & 0xfff ;
V_1038 = ( V_1034 >> 48 ) & 0xfff ;
F_499 ( V_1037 , V_1042 , V_1039 , V_1038 , V_1035 , V_1036 ) ;
switch ( V_1037 ) {
case V_1048 :
F_500 ( V_2 ) ;
break;
default:
V_885 = V_1049 ;
break;
}
V_109 = V_885 | ( ( ( T_2 ) V_1041 & 0xfff ) << 32 ) ;
if ( V_1043 ) {
F_101 ( V_2 , V_197 , V_109 ) ;
} else {
F_101 ( V_2 , V_198 , V_109 >> 32 ) ;
F_101 ( V_2 , V_197 , V_109 & 0xffffffff ) ;
}
return 1 ;
}
static void F_501 ( struct V_102 * V_102 , unsigned long V_292 , int V_1050 )
{
struct V_1051 V_1052 ;
V_1052 . V_1053 = 0 ;
V_1052 . V_1054 = 0 ;
V_1052 . V_1055 = V_1050 ;
V_1052 . V_1056 = V_1057 ;
F_502 ( V_102 , 0 , & V_1052 , NULL ) ;
}
int F_503 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_1058 , V_1059 , V_1060 , V_1061 , V_109 ;
int V_1062 , V_120 = 1 ;
if ( F_189 ( V_2 -> V_102 ) )
return F_497 ( V_2 ) ;
V_16 = F_99 ( V_2 , V_197 ) ;
V_1058 = F_99 ( V_2 , V_1044 ) ;
V_1059 = F_99 ( V_2 , V_196 ) ;
V_1060 = F_99 ( V_2 , V_198 ) ;
V_1061 = F_99 ( V_2 , V_1046 ) ;
F_504 ( V_16 , V_1058 , V_1059 , V_1060 , V_1061 ) ;
V_1062 = F_498 ( V_2 ) ;
if ( ! V_1062 ) {
V_16 &= 0xFFFFFFFF ;
V_1058 &= 0xFFFFFFFF ;
V_1059 &= 0xFFFFFFFF ;
V_1060 &= 0xFFFFFFFF ;
V_1061 &= 0xFFFFFFFF ;
}
if ( V_73 -> V_88 ( V_2 ) != 0 ) {
V_109 = - V_1063 ;
goto V_114;
}
switch ( V_16 ) {
case V_1064 :
V_109 = 0 ;
break;
case V_1065 :
F_501 ( V_2 -> V_102 , V_1058 , V_1059 ) ;
V_109 = 0 ;
break;
default:
V_109 = - V_1066 ;
break;
}
V_114:
if ( ! V_1062 )
V_109 = ( T_1 ) V_109 ;
F_101 ( V_2 , V_197 , V_109 ) ;
++ V_2 -> V_77 . V_1067 ;
return V_120 ;
}
static int F_505 ( struct V_825 * V_826 )
{
struct V_1 * V_2 = F_343 ( V_826 ) ;
char V_1068 [ 3 ] ;
unsigned long V_1069 = F_425 ( V_2 ) ;
V_73 -> V_411 ( V_2 , V_1068 ) ;
return F_363 ( V_826 , V_1069 , V_1068 , 3 , NULL ) ;
}
static int F_506 ( struct V_1 * V_2 )
{
return ( ! F_87 ( V_2 -> V_102 ) && ! F_507 ( V_2 ) &&
V_2 -> V_837 -> V_1070 &&
F_508 ( V_2 ) ) ;
}
static void F_509 ( struct V_1 * V_2 )
{
struct V_953 * V_953 = V_2 -> V_837 ;
V_953 -> V_1071 = ( F_424 ( V_2 ) & V_984 ) != 0 ;
V_953 -> V_173 = F_89 ( V_2 ) ;
V_953 -> V_31 = F_20 ( V_2 ) ;
if ( F_87 ( V_2 -> V_102 ) )
V_953 -> V_1072 = 1 ;
else
V_953 -> V_1072 =
F_508 ( V_2 ) &&
! F_507 ( V_2 ) &&
! F_510 ( V_2 ) ;
}
static void F_257 ( struct V_1 * V_2 )
{
int V_1073 , V_1074 ;
if ( ! V_73 -> F_257 )
return;
if ( ! V_2 -> V_5 . V_619 )
return;
if ( ! V_2 -> V_5 . V_619 -> V_704 )
V_1073 = F_511 ( V_2 ) ;
else
V_1073 = - 1 ;
if ( V_1073 != - 1 )
V_1073 >>= 4 ;
V_1074 = F_90 ( V_2 ) ;
V_73 -> F_257 ( V_2 , V_1074 , V_1073 ) ;
}
static int F_512 ( struct V_1 * V_2 , bool V_1075 )
{
int V_120 ;
if ( V_2 -> V_5 . V_68 . V_69 ) {
F_513 ( V_2 -> V_5 . V_68 . V_16 ,
V_2 -> V_5 . V_68 . V_71 ,
V_2 -> V_5 . V_68 . V_62 ) ;
if ( F_28 ( V_2 -> V_5 . V_68 . V_16 ) == V_60 )
F_451 ( V_2 , F_424 ( V_2 ) |
V_962 ) ;
if ( V_2 -> V_5 . V_68 . V_16 == V_53 &&
( V_2 -> V_5 . V_179 & V_1076 ) ) {
V_2 -> V_5 . V_179 &= ~ V_1076 ;
F_92 ( V_2 ) ;
}
V_73 -> V_1077 ( V_2 , V_2 -> V_5 . V_68 . V_16 ,
V_2 -> V_5 . V_68 . V_71 ,
V_2 -> V_5 . V_68 . V_62 ,
V_2 -> V_5 . V_68 . V_63 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_646 ) {
V_73 -> V_1078 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_641 . V_69 ) {
V_73 -> V_1079 ( V_2 ) ;
return 0 ;
}
if ( F_426 ( V_2 ) && V_73 -> V_1080 ) {
V_120 = V_73 -> V_1080 ( V_2 , V_1075 ) ;
if ( V_120 != 0 )
return V_120 ;
}
if ( V_2 -> V_5 . V_647 ) {
if ( V_73 -> V_1081 ( V_2 ) ) {
-- V_2 -> V_5 . V_647 ;
V_2 -> V_5 . V_646 = true ;
V_73 -> V_1078 ( V_2 ) ;
}
} else if ( F_514 ( V_2 ) ) {
if ( F_426 ( V_2 ) && V_73 -> V_1080 ) {
V_120 = V_73 -> V_1080 ( V_2 , V_1075 ) ;
if ( V_120 != 0 )
return V_120 ;
}
if ( V_73 -> V_1082 ( V_2 ) ) {
F_259 ( V_2 , F_515 ( V_2 ) ,
false ) ;
V_73 -> V_1079 ( V_2 ) ;
}
}
return 0 ;
}
static void F_265 ( struct V_1 * V_2 )
{
unsigned V_898 = 2 ;
if ( V_73 -> V_649 ( V_2 ) || V_2 -> V_5 . V_646 )
V_898 = 1 ;
V_2 -> V_5 . V_647 += F_516 ( & V_2 -> V_5 . V_85 , 0 ) ;
V_2 -> V_5 . V_647 = F_327 ( V_2 -> V_5 . V_647 , V_898 ) ;
F_31 ( V_67 , V_2 ) ;
}
static void F_517 ( struct V_1 * V_2 )
{
T_2 V_1083 [ 4 ] ;
T_1 V_1084 [ 8 ] ;
if ( ! F_518 ( V_2 -> V_5 . V_619 ) )
return;
memset ( V_1083 , 0 , 32 ) ;
memset ( V_1084 , 0 , 32 ) ;
F_519 ( V_2 , V_1083 , V_1084 ) ;
V_73 -> V_1085 ( V_2 , V_1083 ) ;
F_520 ( V_2 , V_1084 ) ;
}
static void F_521 ( struct V_1 * V_2 )
{
++ V_2 -> V_77 . V_1086 ;
V_73 -> V_1086 ( V_2 ) ;
}
void F_522 ( struct V_1 * V_2 )
{
struct V_397 * V_397 = NULL ;
if ( ! F_87 ( V_2 -> V_102 ) )
return;
if ( ! V_73 -> V_1087 )
return;
V_397 = F_365 ( V_2 -> V_102 , V_830 >> V_107 ) ;
V_73 -> V_1087 ( V_2 , F_523 ( V_397 ) ) ;
F_524 ( V_397 ) ;
}
void F_525 ( struct V_102 * V_102 ,
unsigned long V_80 )
{
if ( V_80 == F_192 ( V_102 , V_830 >> V_107 ) )
F_526 ( V_102 , V_1088 ) ;
}
static int F_527 ( struct V_1 * V_2 )
{
int V_120 ;
bool V_1075 = ! F_87 ( V_2 -> V_102 ) &&
V_2 -> V_837 -> V_1070 ;
bool V_1089 = false ;
if ( V_2 -> V_324 ) {
if ( F_528 ( V_1090 , V_2 ) )
F_529 ( V_2 ) ;
if ( F_528 ( V_1091 , V_2 ) )
F_530 ( V_2 ) ;
if ( F_528 ( V_285 , V_2 ) )
F_158 ( V_2 -> V_102 ) ;
if ( F_528 ( V_469 , V_2 ) )
F_174 ( V_2 ) ;
if ( F_528 ( V_322 , V_2 ) ) {
V_120 = F_162 ( V_2 ) ;
if ( F_152 ( V_120 ) )
goto V_114;
}
if ( F_528 ( V_1092 , V_2 ) )
F_84 ( V_2 ) ;
if ( F_528 ( V_169 , V_2 ) )
F_521 ( V_2 ) ;
if ( F_528 ( V_1093 , V_2 ) ) {
V_2 -> V_837 -> V_853 = V_1094 ;
V_120 = 0 ;
goto V_114;
}
if ( F_528 ( V_72 , V_2 ) ) {
V_2 -> V_837 -> V_853 = V_1095 ;
V_120 = 0 ;
goto V_114;
}
if ( F_528 ( V_1096 , V_2 ) ) {
V_2 -> V_1097 = 0 ;
V_73 -> V_1098 ( V_2 ) ;
}
if ( F_528 ( V_1099 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1100 = true ;
V_120 = 1 ;
goto V_114;
}
if ( F_528 ( V_474 , V_2 ) )
F_206 ( V_2 ) ;
if ( F_528 ( V_86 , V_2 ) )
F_265 ( V_2 ) ;
if ( F_528 ( V_1101 , V_2 ) )
F_531 ( V_2 ) ;
if ( F_528 ( V_1102 , V_2 ) )
F_532 ( V_2 ) ;
if ( F_528 ( V_1103 , V_2 ) )
F_517 ( V_2 ) ;
if ( F_528 ( V_1088 , V_2 ) )
F_522 ( V_2 ) ;
}
if ( F_528 ( V_67 , V_2 ) || V_1075 ) {
F_533 ( V_2 ) ;
if ( V_2 -> V_5 . V_1031 == V_1104 ) {
V_120 = 1 ;
goto V_114;
}
if ( F_512 ( V_2 , V_1075 ) != 0 )
V_1089 = true ;
else if ( V_2 -> V_5 . V_647 )
V_73 -> V_1105 ( V_2 ) ;
else if ( F_514 ( V_2 ) || V_1075 )
V_73 -> V_1106 ( V_2 ) ;
if ( F_534 ( V_2 ) ) {
if ( V_73 -> V_1107 )
V_73 -> V_1107 ( V_2 ,
F_511 ( V_2 ) ) ;
F_257 ( V_2 ) ;
F_535 ( V_2 ) ;
}
}
V_120 = F_536 ( V_2 ) ;
if ( F_152 ( V_120 ) ) {
goto V_1108;
}
F_212 () ;
V_73 -> V_1109 ( V_2 ) ;
if ( V_2 -> V_1097 )
F_413 ( V_2 ) ;
F_69 ( V_2 ) ;
V_2 -> V_315 = V_1110 ;
F_233 ( & V_2 -> V_102 -> V_521 , V_2 -> V_1111 ) ;
F_537 () ;
F_321 () ;
if ( V_2 -> V_315 == V_1112 || V_2 -> V_324
|| F_538 () || F_539 ( V_434 ) ) {
V_2 -> V_315 = V_1113 ;
F_14 () ;
F_322 () ;
F_213 () ;
V_2 -> V_1111 = F_232 ( & V_2 -> V_102 -> V_521 ) ;
V_120 = 1 ;
goto V_1108;
}
if ( V_1089 )
F_540 ( V_2 -> V_23 ) ;
F_541 () ;
if ( F_152 ( V_2 -> V_5 . V_182 ) ) {
F_542 ( 0 , 7 ) ;
F_542 ( V_2 -> V_5 . V_190 [ 0 ] , 0 ) ;
F_542 ( V_2 -> V_5 . V_190 [ 1 ] , 1 ) ;
F_542 ( V_2 -> V_5 . V_190 [ 2 ] , 2 ) ;
F_542 ( V_2 -> V_5 . V_190 [ 3 ] , 3 ) ;
F_542 ( V_2 -> V_5 . V_178 , 6 ) ;
}
F_543 ( V_2 -> V_286 ) ;
F_544 ( V_2 ) ;
V_73 -> V_837 ( V_2 ) ;
if ( F_152 ( V_2 -> V_5 . V_182 & V_1114 ) ) {
int V_3 ;
F_29 ( V_2 -> V_175 & V_176 ) ;
V_73 -> V_1115 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_1116 ; V_3 ++ )
V_2 -> V_5 . V_190 [ V_3 ] = V_2 -> V_5 . V_189 [ V_3 ] ;
}
if ( F_545 () )
F_546 () ;
V_2 -> V_5 . V_309 = V_73 -> V_332 ( V_2 ,
F_166 () ) ;
V_2 -> V_315 = V_1113 ;
F_14 () ;
V_73 -> V_1117 ( V_2 ) ;
++ V_2 -> V_77 . V_1118 ;
F_547 () ;
F_548 () ;
F_213 () ;
V_2 -> V_1111 = F_232 ( & V_2 -> V_102 -> V_521 ) ;
if ( F_152 ( V_1119 == V_1120 ) ) {
unsigned long V_1069 = F_425 ( V_2 ) ;
F_549 ( V_1120 , ( void * ) V_1069 ) ;
}
if ( F_152 ( V_2 -> V_5 . V_1121 ) )
F_31 ( V_322 , V_2 ) ;
if ( V_2 -> V_5 . V_1122 )
F_550 ( V_2 ) ;
V_120 = V_73 -> V_1123 ( V_2 ) ;
return V_120 ;
V_1108:
V_73 -> V_1108 ( V_2 ) ;
if ( F_152 ( V_2 -> V_5 . V_1122 ) )
F_550 ( V_2 ) ;
V_114:
return V_120 ;
}
static int F_551 ( struct V_1 * V_2 )
{
int V_120 ;
struct V_102 * V_102 = V_2 -> V_102 ;
V_2 -> V_1111 = F_232 ( & V_102 -> V_521 ) ;
V_120 = 1 ;
while ( V_120 > 0 ) {
if ( V_2 -> V_5 . V_1031 == V_1124 &&
! V_2 -> V_5 . V_6 . V_1100 )
V_120 = F_527 ( V_2 ) ;
else {
F_233 ( & V_102 -> V_521 , V_2 -> V_1111 ) ;
F_552 ( V_2 ) ;
V_2 -> V_1111 = F_232 ( & V_102 -> V_521 ) ;
if ( F_528 ( V_1125 , V_2 ) ) {
F_533 ( V_2 ) ;
switch( V_2 -> V_5 . V_1031 ) {
case V_1032 :
V_2 -> V_5 . V_1126 . V_1127 = false ;
V_2 -> V_5 . V_1031 =
V_1124 ;
case V_1124 :
V_2 -> V_5 . V_6 . V_1100 = false ;
break;
case V_1104 :
break;
default:
V_120 = - V_1128 ;
break;
}
}
}
if ( V_120 <= 0 )
break;
F_161 ( V_234 , & V_2 -> V_324 ) ;
if ( F_553 ( V_2 ) )
F_554 ( V_2 ) ;
if ( F_506 ( V_2 ) ) {
V_120 = - V_1128 ;
V_2 -> V_837 -> V_853 = V_1129 ;
++ V_2 -> V_77 . V_1130 ;
}
F_555 ( V_2 ) ;
if ( F_539 ( V_434 ) ) {
V_120 = - V_1128 ;
V_2 -> V_837 -> V_853 = V_1129 ;
++ V_2 -> V_77 . V_1131 ;
}
if ( F_538 () ) {
F_233 ( & V_102 -> V_521 , V_2 -> V_1111 ) ;
F_556 () ;
V_2 -> V_1111 = F_232 ( & V_102 -> V_521 ) ;
}
}
F_233 ( & V_102 -> V_521 , V_2 -> V_1111 ) ;
return V_120 ;
}
static inline int F_557 ( struct V_1 * V_2 )
{
int V_120 ;
V_2 -> V_1111 = F_232 ( & V_2 -> V_102 -> V_521 ) ;
V_120 = F_558 ( V_2 , V_966 ) ;
F_233 ( & V_2 -> V_102 -> V_521 , V_2 -> V_1111 ) ;
if ( V_120 != V_933 )
return 0 ;
return 1 ;
}
static int V_979 ( struct V_1 * V_2 )
{
F_13 ( ! V_2 -> V_5 . V_868 . V_746 ) ;
return F_557 ( V_2 ) ;
}
static int V_980 ( struct V_1 * V_2 )
{
struct V_953 * V_837 = V_2 -> V_837 ;
struct V_835 * V_836 ;
unsigned V_95 ;
F_13 ( ! V_2 -> V_849 ) ;
V_836 = & V_2 -> V_832 [ V_2 -> V_850 ] ;
V_95 = F_327 ( 8u , V_836 -> V_95 ) ;
if ( ! V_2 -> V_852 )
memcpy ( V_836 -> V_38 , V_837 -> V_838 . V_38 , V_95 ) ;
if ( V_836 -> V_95 <= 8 ) {
V_836 ++ ;
V_2 -> V_850 ++ ;
} else {
V_836 -> V_38 += V_95 ;
V_836 -> V_428 += V_95 ;
V_836 -> V_95 -= V_95 ;
}
if ( V_2 -> V_850 >= V_2 -> V_843 ) {
V_2 -> V_849 = 0 ;
if ( V_2 -> V_852 )
return 1 ;
V_2 -> V_831 = 1 ;
return F_557 ( V_2 ) ;
}
V_837 -> V_853 = V_854 ;
V_837 -> V_838 . V_855 = V_836 -> V_428 ;
if ( V_2 -> V_852 )
memcpy ( V_837 -> V_838 . V_38 , V_836 -> V_38 , F_327 ( 8u , V_836 -> V_95 ) ) ;
V_837 -> V_838 . V_95 = F_327 ( 8u , V_836 -> V_95 ) ;
V_837 -> V_838 . V_851 = V_2 -> V_852 ;
V_2 -> V_5 . V_978 = V_980 ;
return 0 ;
}
int F_559 ( struct V_1 * V_2 , struct V_953 * V_953 )
{
int V_120 ;
T_19 V_1132 ;
if ( ! F_560 ( V_434 ) && F_561 ( V_434 ) )
return - V_399 ;
if ( V_2 -> V_1133 )
F_562 ( V_1134 , & V_2 -> V_1135 , & V_1132 ) ;
if ( F_152 ( V_2 -> V_5 . V_1031 == V_1136 ) ) {
F_552 ( V_2 ) ;
F_533 ( V_2 ) ;
F_161 ( V_1125 , & V_2 -> V_324 ) ;
V_120 = - V_1137 ;
goto V_114;
}
if ( ! F_87 ( V_2 -> V_102 ) ) {
if ( F_86 ( V_2 , V_953 -> V_173 ) != 0 ) {
V_120 = - V_606 ;
goto V_114;
}
}
if ( F_152 ( V_2 -> V_5 . V_978 ) ) {
int (* F_563)( struct V_1 * ) = V_2 -> V_5 . V_978 ;
V_2 -> V_5 . V_978 = NULL ;
V_120 = F_563 ( V_2 ) ;
if ( V_120 <= 0 )
goto V_114;
} else
F_29 ( V_2 -> V_5 . V_868 . V_746 || V_2 -> V_849 ) ;
V_120 = F_551 ( V_2 ) ;
V_114:
F_509 ( V_2 ) ;
if ( V_2 -> V_1133 )
F_562 ( V_1134 , & V_1132 , NULL ) ;
return V_120 ;
}
int F_564 ( struct V_1 * V_2 , struct V_1138 * V_618 )
{
if ( V_2 -> V_5 . V_983 ) {
F_565 ( & V_2 -> V_5 . V_917 ) ;
V_2 -> V_5 . V_983 = false ;
}
V_618 -> V_1139 = F_99 ( V_2 , V_197 ) ;
V_618 -> V_1140 = F_99 ( V_2 , V_1044 ) ;
V_618 -> V_1141 = F_99 ( V_2 , V_196 ) ;
V_618 -> V_1142 = F_99 ( V_2 , V_198 ) ;
V_618 -> V_1143 = F_99 ( V_2 , V_1046 ) ;
V_618 -> V_1144 = F_99 ( V_2 , V_1045 ) ;
V_618 -> V_1145 = F_99 ( V_2 , V_1146 ) ;
V_618 -> V_1147 = F_99 ( V_2 , V_1148 ) ;
#ifdef F_63
V_618 -> V_1149 = F_99 ( V_2 , V_1047 ) ;
V_618 -> V_1150 = F_99 ( V_2 , V_1151 ) ;
V_618 -> V_1152 = F_99 ( V_2 , V_1153 ) ;
V_618 -> V_1154 = F_99 ( V_2 , V_1155 ) ;
V_618 -> V_1156 = F_99 ( V_2 , V_1157 ) ;
V_618 -> V_1158 = F_99 ( V_2 , V_1159 ) ;
V_618 -> V_1160 = F_99 ( V_2 , V_1161 ) ;
V_618 -> V_1162 = F_99 ( V_2 , V_1163 ) ;
#endif
V_618 -> V_1069 = F_425 ( V_2 ) ;
V_618 -> V_952 = F_424 ( V_2 ) ;
return 0 ;
}
int F_566 ( struct V_1 * V_2 , struct V_1138 * V_618 )
{
V_2 -> V_5 . V_927 = true ;
V_2 -> V_5 . V_983 = false ;
F_101 ( V_2 , V_197 , V_618 -> V_1139 ) ;
F_101 ( V_2 , V_1044 , V_618 -> V_1140 ) ;
F_101 ( V_2 , V_196 , V_618 -> V_1141 ) ;
F_101 ( V_2 , V_198 , V_618 -> V_1142 ) ;
F_101 ( V_2 , V_1046 , V_618 -> V_1143 ) ;
F_101 ( V_2 , V_1045 , V_618 -> V_1144 ) ;
F_101 ( V_2 , V_1146 , V_618 -> V_1145 ) ;
F_101 ( V_2 , V_1148 , V_618 -> V_1147 ) ;
#ifdef F_63
F_101 ( V_2 , V_1047 , V_618 -> V_1149 ) ;
F_101 ( V_2 , V_1151 , V_618 -> V_1150 ) ;
F_101 ( V_2 , V_1153 , V_618 -> V_1152 ) ;
F_101 ( V_2 , V_1155 , V_618 -> V_1154 ) ;
F_101 ( V_2 , V_1157 , V_618 -> V_1156 ) ;
F_101 ( V_2 , V_1159 , V_618 -> V_1158 ) ;
F_101 ( V_2 , V_1161 , V_618 -> V_1160 ) ;
F_101 ( V_2 , V_1163 , V_618 -> V_1162 ) ;
#endif
F_430 ( V_2 , V_618 -> V_1069 ) ;
F_431 ( V_2 , V_618 -> V_952 ) ;
V_2 -> V_5 . V_68 . V_69 = false ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
void F_567 ( struct V_1 * V_2 , int * V_189 , int * V_903 )
{
struct V_811 V_1164 ;
F_335 ( V_2 , & V_1164 , V_1165 ) ;
* V_189 = V_1164 . V_189 ;
* V_903 = V_1164 . V_903 ;
}
int F_568 ( struct V_1 * V_2 ,
struct V_1166 * V_1167 )
{
struct V_886 V_887 ;
F_335 ( V_2 , & V_1167 -> V_1164 , V_1165 ) ;
F_335 ( V_2 , & V_1167 -> V_1168 , V_1169 ) ;
F_335 ( V_2 , & V_1167 -> V_1170 , V_1171 ) ;
F_335 ( V_2 , & V_1167 -> V_1172 , V_1173 ) ;
F_335 ( V_2 , & V_1167 -> V_1174 , V_1175 ) ;
F_335 ( V_2 , & V_1167 -> V_1176 , V_1177 ) ;
F_335 ( V_2 , & V_1167 -> V_1178 , V_1179 ) ;
F_335 ( V_2 , & V_1167 -> V_1180 , V_1181 ) ;
V_73 -> V_889 ( V_2 , & V_887 ) ;
V_1167 -> V_1182 . V_898 = V_887 . V_526 ;
V_1167 -> V_1182 . V_899 = V_887 . V_80 ;
V_73 -> V_888 ( V_2 , & V_887 ) ;
V_1167 -> V_1183 . V_898 = V_887 . V_526 ;
V_1167 -> V_1183 . V_899 = V_887 . V_80 ;
V_1167 -> V_121 = F_62 ( V_2 ) ;
V_1167 -> V_79 = V_2 -> V_5 . V_79 ;
V_1167 -> V_105 = F_60 ( V_2 ) ;
V_1167 -> V_156 = F_76 ( V_2 ) ;
V_1167 -> V_173 = F_89 ( V_2 ) ;
V_1167 -> V_131 = V_2 -> V_5 . V_131 ;
V_1167 -> V_31 = F_20 ( V_2 ) ;
memset ( V_1167 -> V_1184 , 0 , sizeof V_1167 -> V_1184 ) ;
if ( V_2 -> V_5 . V_641 . V_69 && ! V_2 -> V_5 . V_641 . V_642 )
F_210 ( V_2 -> V_5 . V_641 . V_16 ,
( unsigned long * ) V_1167 -> V_1184 ) ;
return 0 ;
}
int F_569 ( struct V_1 * V_2 ,
struct V_1185 * V_1031 )
{
F_533 ( V_2 ) ;
if ( V_2 -> V_5 . V_1031 == V_1032 &&
V_2 -> V_5 . V_1126 . V_1127 )
V_1031 -> V_1031 = V_1124 ;
else
V_1031 -> V_1031 = V_2 -> V_5 . V_1031 ;
return 0 ;
}
int F_570 ( struct V_1 * V_2 ,
struct V_1185 * V_1031 )
{
if ( ! F_268 ( V_2 ) &&
V_1031 -> V_1031 != V_1124 )
return - V_606 ;
if ( V_1031 -> V_1031 == V_1186 ) {
V_2 -> V_5 . V_1031 = V_1104 ;
F_210 ( V_1187 , & V_2 -> V_5 . V_619 -> V_1188 ) ;
} else
V_2 -> V_5 . V_1031 = V_1031 -> V_1031 ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
int F_571 ( struct V_1 * V_2 , V_864 V_1189 , int V_1190 ,
int V_1191 , bool V_71 , T_1 V_62 )
{
struct V_825 * V_826 = & V_2 -> V_5 . V_917 ;
int V_109 ;
F_423 ( V_2 ) ;
V_109 = F_572 ( V_826 , V_1189 , V_1190 , V_1191 ,
V_71 , V_62 ) ;
if ( V_109 )
return V_932 ;
F_430 ( V_2 , V_826 -> V_920 ) ;
F_431 ( V_2 , V_826 -> V_919 ) ;
F_31 ( V_67 , V_2 ) ;
return V_933 ;
}
int F_573 ( struct V_1 * V_2 ,
struct V_1166 * V_1167 )
{
struct V_32 V_1192 ;
int V_1193 = 0 ;
int V_1194 , V_1195 , V_372 ;
struct V_886 V_887 ;
if ( ! F_77 ( V_2 ) && ( V_1167 -> V_156 & V_139 ) )
return - V_606 ;
V_887 . V_526 = V_1167 -> V_1182 . V_898 ;
V_887 . V_80 = V_1167 -> V_1182 . V_899 ;
V_73 -> V_891 ( V_2 , & V_887 ) ;
V_887 . V_526 = V_1167 -> V_1183 . V_898 ;
V_887 . V_80 = V_1167 -> V_1183 . V_899 ;
V_73 -> V_890 ( V_2 , & V_887 ) ;
V_2 -> V_5 . V_79 = V_1167 -> V_79 ;
V_1193 |= F_60 ( V_2 ) != V_1167 -> V_105 ;
V_2 -> V_5 . V_105 = V_1167 -> V_105 ;
F_55 ( V_171 , ( V_172 * ) & V_2 -> V_5 . V_117 ) ;
F_86 ( V_2 , V_1167 -> V_173 ) ;
V_1193 |= V_2 -> V_5 . V_131 != V_1167 -> V_131 ;
V_73 -> F_105 ( V_2 , V_1167 -> V_131 ) ;
V_1192 . V_38 = V_1167 -> V_31 ;
V_1192 . V_40 = true ;
F_21 ( V_2 , & V_1192 ) ;
V_1193 |= F_62 ( V_2 ) != V_1167 -> V_121 ;
V_73 -> V_137 ( V_2 , V_1167 -> V_121 ) ;
V_2 -> V_5 . V_121 = V_1167 -> V_121 ;
V_1193 |= F_76 ( V_2 ) != V_1167 -> V_156 ;
V_73 -> V_167 ( V_2 , V_1167 -> V_156 ) ;
if ( V_1167 -> V_156 & V_139 )
F_73 ( V_2 ) ;
V_372 = F_232 ( & V_2 -> V_102 -> V_521 ) ;
if ( ! F_57 ( V_2 ) && F_58 ( V_2 ) ) {
F_52 ( V_2 , V_2 -> V_5 . V_104 , F_60 ( V_2 ) ) ;
V_1193 = 1 ;
}
F_233 ( & V_2 -> V_102 -> V_521 , V_372 ) ;
if ( V_1193 )
F_66 ( V_2 ) ;
V_1195 = V_622 ;
V_1194 = F_574 (
( const unsigned long * ) V_1167 -> V_1184 , V_1195 ) ;
if ( V_1194 < V_1195 ) {
F_259 ( V_2 , V_1194 , false ) ;
F_125 ( L_29 , V_1194 ) ;
}
F_334 ( V_2 , & V_1167 -> V_1164 , V_1165 ) ;
F_334 ( V_2 , & V_1167 -> V_1168 , V_1169 ) ;
F_334 ( V_2 , & V_1167 -> V_1170 , V_1171 ) ;
F_334 ( V_2 , & V_1167 -> V_1172 , V_1173 ) ;
F_334 ( V_2 , & V_1167 -> V_1174 , V_1175 ) ;
F_334 ( V_2 , & V_1167 -> V_1176 , V_1177 ) ;
F_334 ( V_2 , & V_1167 -> V_1178 , V_1179 ) ;
F_334 ( V_2 , & V_1167 -> V_1180 , V_1181 ) ;
F_257 ( V_2 ) ;
if ( F_575 ( V_2 ) && F_425 ( V_2 ) == 0xfff0 &&
V_1167 -> V_1164 . V_892 == 0xf000 && V_1167 -> V_1164 . V_899 == 0xffff0000 &&
! F_32 ( V_2 ) )
V_2 -> V_5 . V_1031 = V_1124 ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
int F_576 ( struct V_1 * V_2 ,
struct V_1196 * V_1197 )
{
unsigned long V_952 ;
int V_3 , V_120 ;
if ( V_1197 -> V_753 & ( V_1198 | V_1199 ) ) {
V_120 = - V_1200 ;
if ( V_2 -> V_5 . V_68 . V_69 )
goto V_114;
if ( V_1197 -> V_753 & V_1198 )
F_33 ( V_2 , V_53 ) ;
else
F_33 ( V_2 , V_54 ) ;
}
V_952 = F_424 ( V_2 ) ;
V_2 -> V_175 = V_1197 -> V_753 ;
if ( ! ( V_2 -> V_175 & V_1201 ) )
V_2 -> V_175 = 0 ;
if ( V_2 -> V_175 & V_176 ) {
for ( V_3 = 0 ; V_3 < V_1116 ; ++ V_3 )
V_2 -> V_5 . V_190 [ V_3 ] = V_1197 -> V_5 . V_1202 [ V_3 ] ;
V_2 -> V_5 . V_180 = V_1197 -> V_5 . V_1202 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_1116 ; V_3 ++ )
V_2 -> V_5 . V_190 [ V_3 ] = V_2 -> V_5 . V_189 [ V_3 ] ;
}
F_92 ( V_2 ) ;
if ( V_2 -> V_175 & V_955 )
V_2 -> V_5 . V_959 = F_425 ( V_2 ) +
F_379 ( V_2 , V_1165 ) ;
F_431 ( V_2 , V_952 ) ;
V_73 -> V_1203 ( V_2 ) ;
V_120 = 0 ;
V_114:
return V_120 ;
}
int F_577 ( struct V_1 * V_2 ,
struct V_1204 * V_1178 )
{
unsigned long V_1205 = V_1178 -> V_1206 ;
T_6 V_428 ;
int V_372 ;
V_372 = F_232 ( & V_2 -> V_102 -> V_521 ) ;
V_428 = F_340 ( V_2 , V_1205 , NULL ) ;
F_233 ( & V_2 -> V_102 -> V_521 , V_372 ) ;
V_1178 -> V_1207 = V_428 ;
V_1178 -> V_666 = V_428 != V_100 ;
V_1178 -> V_1208 = 1 ;
V_1178 -> V_1209 = 0 ;
return 0 ;
}
int F_578 ( struct V_1 * V_2 , struct V_1210 * V_1211 )
{
struct V_679 * V_678 =
& V_2 -> V_5 . V_662 . V_663 -> V_678 ;
memcpy ( V_1211 -> V_1212 , V_678 -> V_1213 , 128 ) ;
V_1211 -> V_1214 = V_678 -> V_1215 ;
V_1211 -> V_1216 = V_678 -> V_1217 ;
V_1211 -> V_1218 = V_678 -> V_1219 ;
V_1211 -> V_1220 = V_678 -> V_1221 ;
V_1211 -> V_1222 = V_678 -> V_1069 ;
V_1211 -> V_1223 = V_678 -> V_1224 ;
memcpy ( V_1211 -> V_1225 , V_678 -> V_1226 , sizeof V_678 -> V_1226 ) ;
return 0 ;
}
int F_579 ( struct V_1 * V_2 , struct V_1210 * V_1211 )
{
struct V_679 * V_678 =
& V_2 -> V_5 . V_662 . V_663 -> V_678 ;
memcpy ( V_678 -> V_1213 , V_1211 -> V_1212 , 128 ) ;
V_678 -> V_1215 = V_1211 -> V_1214 ;
V_678 -> V_1217 = V_1211 -> V_1216 ;
V_678 -> V_1219 = V_1211 -> V_1218 ;
V_678 -> V_1221 = V_1211 -> V_1220 ;
V_678 -> V_1069 = V_1211 -> V_1222 ;
V_678 -> V_1224 = V_1211 -> V_1223 ;
memcpy ( V_678 -> V_1226 , V_1211 -> V_1225 , sizeof V_678 -> V_1226 ) ;
return 0 ;
}
int F_580 ( struct V_1 * V_2 )
{
int V_29 ;
V_29 = F_581 ( & V_2 -> V_5 . V_662 ) ;
if ( V_29 )
return V_29 ;
F_582 ( & V_2 -> V_5 . V_662 ) ;
if ( V_672 )
V_2 -> V_5 . V_662 . V_663 -> V_661 . V_665 . V_673 =
V_143 | V_674 ;
V_2 -> V_5 . V_142 = V_148 ;
V_2 -> V_5 . V_121 |= V_128 ;
return 0 ;
}
static void F_583 ( struct V_1 * V_2 )
{
F_584 ( & V_2 -> V_5 . V_662 ) ;
}
void F_413 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1227 )
return;
F_71 ( V_2 ) ;
V_2 -> V_1227 = 1 ;
F_585 () ;
F_586 ( & V_2 -> V_5 . V_662 ) ;
F_587 ( 1 ) ;
}
void F_253 ( struct V_1 * V_2 )
{
F_71 ( V_2 ) ;
if ( ! V_2 -> V_1227 )
return;
V_2 -> V_1227 = 0 ;
F_588 ( & V_2 -> V_5 . V_662 ) ;
F_589 () ;
++ V_2 -> V_77 . V_1228 ;
F_31 ( V_1096 , V_2 ) ;
F_587 ( 0 ) ;
}
void F_590 ( struct V_1 * V_2 )
{
F_204 ( V_2 ) ;
F_591 ( V_2 -> V_5 . V_609 ) ;
F_583 ( V_2 ) ;
V_73 -> V_1229 ( V_2 ) ;
}
struct V_1 * F_592 ( struct V_102 * V_102 ,
unsigned int V_1230 )
{
if ( F_140 () && F_135 ( & V_102 -> V_282 ) != 0 )
F_373 ( V_866
L_30
L_31 ) ;
return V_73 -> V_1231 ( V_102 , V_1230 ) ;
}
int F_593 ( struct V_1 * V_2 )
{
int V_120 ;
V_2 -> V_5 . V_367 . V_1232 = 1 ;
V_120 = V_610 ( V_2 ) ;
if ( V_120 )
return V_120 ;
F_594 ( V_2 ) ;
F_595 ( V_2 ) ;
V_614 ( V_2 ) ;
return V_120 ;
}
void F_596 ( struct V_1 * V_2 )
{
struct V_32 V_21 ;
struct V_102 * V_102 = V_2 -> V_102 ;
if ( V_610 ( V_2 ) )
return;
V_21 . V_38 = 0x0 ;
V_21 . V_144 = V_1233 ;
V_21 . V_40 = true ;
F_138 ( V_2 , & V_21 ) ;
V_614 ( V_2 ) ;
F_175 ( & V_102 -> V_5 . V_350 ,
V_351 ) ;
}
void F_597 ( struct V_1 * V_2 )
{
int V_120 ;
V_2 -> V_5 . V_6 . V_429 = 0 ;
V_120 = V_610 ( V_2 ) ;
F_13 ( V_120 ) ;
F_529 ( V_2 ) ;
V_614 ( V_2 ) ;
F_583 ( V_2 ) ;
V_73 -> V_1229 ( V_2 ) ;
}
void F_594 ( struct V_1 * V_2 )
{
F_156 ( & V_2 -> V_5 . V_85 , 0 ) ;
V_2 -> V_5 . V_647 = 0 ;
V_2 -> V_5 . V_646 = false ;
F_598 ( V_2 ) ;
F_446 ( V_2 ) ;
memset ( V_2 -> V_5 . V_189 , 0 , sizeof( V_2 -> V_5 . V_189 ) ) ;
V_2 -> V_5 . V_178 = V_1234 ;
F_91 ( V_2 ) ;
V_2 -> V_5 . V_179 = V_193 ;
F_92 ( V_2 ) ;
F_31 ( V_67 , V_2 ) ;
V_2 -> V_5 . V_6 . V_429 = 0 ;
V_2 -> V_5 . V_433 . V_429 = 0 ;
F_204 ( V_2 ) ;
F_65 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1100 = false ;
F_599 ( V_2 ) ;
memset ( V_2 -> V_5 . V_618 , 0 , sizeof( V_2 -> V_5 . V_618 ) ) ;
V_2 -> V_5 . V_117 = ~ 0 ;
V_2 -> V_5 . V_118 = ~ 0 ;
V_73 -> V_1235 ( V_2 ) ;
}
void F_600 ( struct V_1 * V_2 , T_14 V_41 )
{
struct V_811 V_1164 ;
F_335 ( V_2 , & V_1164 , V_1165 ) ;
V_1164 . V_892 = V_41 << 8 ;
V_1164 . V_899 = V_41 << 12 ;
F_334 ( V_2 , & V_1164 , V_1165 ) ;
F_430 ( V_2 , 0 ) ;
}
int F_601 ( void )
{
struct V_102 * V_102 ;
struct V_1 * V_2 ;
int V_3 ;
int V_109 ;
T_2 V_1236 ;
T_2 V_1237 = 0 ;
bool V_1238 , V_1239 = false ;
F_15 () ;
V_109 = V_73 -> V_1240 () ;
if ( V_109 != 0 )
return V_109 ;
V_1236 = F_166 () ;
V_1238 = ! F_140 () ;
F_460 (kvm, &vm_list, vm_list) {
F_160 (i, vcpu, kvm) {
if ( ! V_1238 && V_2 -> V_23 == F_8 () )
F_31 ( V_322 , V_2 ) ;
if ( V_1238 && V_2 -> V_5 . V_613 > V_1236 ) {
V_1239 = true ;
if ( V_2 -> V_5 . V_613 > V_1237 )
V_1237 = V_2 -> V_5 . V_613 ;
}
}
}
if ( V_1239 ) {
T_2 V_1241 = V_1237 - V_1236 ;
V_319 = true ;
F_460 (kvm, &vm_list, vm_list) {
F_160 (i, vcpu, kvm) {
V_2 -> V_5 . V_611 += V_1241 ;
V_2 -> V_5 . V_613 = V_1236 ;
F_31 ( V_285 , V_2 ) ;
}
V_102 -> V_5 . V_298 = 0 ;
V_102 -> V_5 . V_300 = 0 ;
}
}
return 0 ;
}
void F_602 ( void )
{
V_73 -> V_1242 () ;
F_19 () ;
}
int F_603 ( void )
{
return V_73 -> V_1243 () ;
}
void F_604 ( void )
{
V_73 -> V_1244 () ;
}
void F_605 ( void * V_1245 )
{
V_73 -> V_1246 ( V_1245 ) ;
}
bool F_606 ( struct V_1 * V_2 )
{
return F_87 ( V_2 -> V_102 ) == ( V_2 -> V_5 . V_619 != NULL ) ;
}
int F_607 ( struct V_1 * V_2 )
{
struct V_397 * V_397 ;
struct V_102 * V_102 ;
int V_120 ;
F_13 ( V_2 -> V_102 == NULL ) ;
V_102 = V_2 -> V_102 ;
V_2 -> V_5 . V_1126 . V_1127 = false ;
V_2 -> V_5 . V_917 . V_840 = & V_1247 ;
if ( ! F_87 ( V_102 ) || F_575 ( V_2 ) )
V_2 -> V_5 . V_1031 = V_1124 ;
else
V_2 -> V_5 . V_1031 = V_1136 ;
V_397 = F_608 ( V_690 | V_1248 ) ;
if ( ! V_397 ) {
V_120 = - V_399 ;
goto V_1249;
}
V_2 -> V_5 . V_871 = F_609 ( V_397 ) ;
F_132 ( V_2 , V_1001 ) ;
V_120 = F_610 ( V_2 ) ;
if ( V_120 < 0 )
goto V_1250;
if ( F_87 ( V_102 ) ) {
V_120 = F_611 ( V_2 ) ;
if ( V_120 < 0 )
goto V_1251;
} else
F_612 ( & V_1252 ) ;
V_2 -> V_5 . V_386 = F_284 ( V_476 * sizeof( T_2 ) * 4 ,
V_690 ) ;
if ( ! V_2 -> V_5 . V_386 ) {
V_120 = - V_399 ;
goto V_1253;
}
V_2 -> V_5 . V_378 = V_476 ;
if ( ! F_613 ( & V_2 -> V_5 . V_609 , V_690 ) ) {
V_120 = - V_399 ;
goto V_1254;
}
V_120 = F_580 ( V_2 ) ;
if ( V_120 )
goto V_1255;
V_2 -> V_5 . V_289 = 0x0 ;
V_2 -> V_5 . V_334 = false ;
V_2 -> V_5 . V_151 = 0 ;
V_2 -> V_5 . V_1256 = V_1257 + V_667 ;
F_1 ( V_2 ) ;
F_614 ( V_2 ) ;
return 0 ;
V_1255:
F_591 ( V_2 -> V_5 . V_609 ) ;
V_1254:
F_188 ( V_2 -> V_5 . V_386 ) ;
V_1253:
F_615 ( V_2 ) ;
V_1251:
F_616 ( V_2 ) ;
V_1250:
F_617 ( ( unsigned long ) V_2 -> V_5 . V_871 ) ;
V_1249:
return V_120 ;
}
void F_618 ( struct V_1 * V_2 )
{
int V_372 ;
F_619 ( V_2 ) ;
F_188 ( V_2 -> V_5 . V_386 ) ;
F_615 ( V_2 ) ;
V_372 = F_232 ( & V_2 -> V_102 -> V_521 ) ;
F_616 ( V_2 ) ;
F_233 ( & V_2 -> V_102 -> V_521 , V_372 ) ;
F_617 ( ( unsigned long ) V_2 -> V_5 . V_871 ) ;
if ( ! F_87 ( V_2 -> V_102 ) )
F_620 ( & V_1252 ) ;
}
void F_621 ( struct V_1 * V_2 , int V_23 )
{
V_73 -> V_1258 ( V_2 , V_23 ) ;
}
int F_622 ( struct V_102 * V_102 , unsigned long type )
{
if ( type )
return - V_606 ;
F_623 ( & V_102 -> V_5 . V_1259 ) ;
F_624 ( & V_102 -> V_5 . V_1260 ) ;
F_624 ( & V_102 -> V_5 . V_1261 ) ;
F_624 ( & V_102 -> V_5 . V_1262 ) ;
F_156 ( & V_102 -> V_5 . V_1263 , 0 ) ;
F_210 ( V_761 , & V_102 -> V_5 . V_1264 ) ;
F_210 ( V_1265 ,
& V_102 -> V_5 . V_1264 ) ;
F_625 ( & V_102 -> V_5 . V_296 ) ;
F_626 ( & V_102 -> V_5 . V_1266 ) ;
F_627 ( & V_102 -> V_5 . V_311 ) ;
F_155 ( V_102 ) ;
F_628 ( & V_102 -> V_5 . V_348 , F_171 ) ;
F_628 ( & V_102 -> V_5 . V_350 , F_176 ) ;
return 0 ;
}
static void F_629 ( struct V_1 * V_2 )
{
int V_120 ;
V_120 = V_610 ( V_2 ) ;
F_13 ( V_120 ) ;
F_529 ( V_2 ) ;
V_614 ( V_2 ) ;
}
static void F_630 ( struct V_102 * V_102 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_160 (i, vcpu, kvm) {
F_65 ( V_2 ) ;
F_629 ( V_2 ) ;
}
F_160 (i, vcpu, kvm)
F_590 ( V_2 ) ;
F_216 ( & V_102 -> V_491 ) ;
for ( V_3 = 0 ; V_3 < F_135 ( & V_102 -> V_282 ) ; V_3 ++ )
V_102 -> V_1267 [ V_3 ] = NULL ;
F_156 ( & V_102 -> V_282 , 0 ) ;
F_217 ( & V_102 -> V_491 ) ;
}
void F_631 ( struct V_102 * V_102 )
{
F_632 ( & V_102 -> V_5 . V_350 ) ;
F_632 ( & V_102 -> V_5 . V_348 ) ;
F_633 ( V_102 ) ;
F_634 ( V_102 ) ;
}
void F_635 ( struct V_102 * V_102 )
{
if ( V_434 -> V_1268 == V_102 -> V_1268 ) {
struct V_1269 V_1270 ;
memset ( & V_1270 , 0 , sizeof( V_1270 ) ) ;
V_1270 . V_10 = V_1271 ;
F_636 ( V_102 , & V_1270 ) ;
V_1270 . V_10 = V_1272 ;
F_636 ( V_102 , & V_1270 ) ;
V_1270 . V_10 = V_1273 ;
F_636 ( V_102 , & V_1270 ) ;
}
F_637 ( V_102 ) ;
F_188 ( V_102 -> V_5 . V_773 ) ;
F_188 ( V_102 -> V_5 . V_1274 ) ;
F_630 ( V_102 ) ;
F_188 ( F_638 ( V_102 -> V_5 . V_1275 , 1 ) ) ;
}
void F_639 ( struct V_102 * V_102 , struct V_1276 * free ,
struct V_1276 * V_1277 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1278 ; ++ V_3 ) {
if ( ! V_1277 || free -> V_5 . V_1279 [ V_3 ] != V_1277 -> V_5 . V_1279 [ V_3 ] ) {
F_640 ( free -> V_5 . V_1279 [ V_3 ] ) ;
free -> V_5 . V_1279 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1277 || free -> V_5 . V_1280 [ V_3 - 1 ] !=
V_1277 -> V_5 . V_1280 [ V_3 - 1 ] ) {
F_640 ( free -> V_5 . V_1280 [ V_3 - 1 ] ) ;
free -> V_5 . V_1280 [ V_3 - 1 ] = NULL ;
}
}
}
int F_641 ( struct V_102 * V_102 , struct V_1276 * V_10 ,
unsigned long V_1281 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1278 ; ++ V_3 ) {
unsigned long V_1282 ;
int V_1283 ;
int V_762 = V_3 + 1 ;
V_1283 = F_642 ( V_10 -> V_1284 + V_1281 - 1 ,
V_10 -> V_1284 , V_762 ) + 1 ;
V_10 -> V_5 . V_1279 [ V_3 ] =
F_643 ( V_1283 * sizeof( * V_10 -> V_5 . V_1279 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1279 [ V_3 ] )
goto V_400;
if ( V_3 == 0 )
continue;
V_10 -> V_5 . V_1280 [ V_3 - 1 ] = F_643 ( V_1283 *
sizeof( * V_10 -> V_5 . V_1280 [ V_3 - 1 ] ) ) ;
if ( ! V_10 -> V_5 . V_1280 [ V_3 - 1 ] )
goto V_400;
if ( V_10 -> V_1284 & ( F_644 ( V_762 ) - 1 ) )
V_10 -> V_5 . V_1280 [ V_3 - 1 ] [ 0 ] . V_1285 = 1 ;
if ( ( V_10 -> V_1284 + V_1281 ) & ( F_644 ( V_762 ) - 1 ) )
V_10 -> V_5 . V_1280 [ V_3 - 1 ] [ V_1283 - 1 ] . V_1285 = 1 ;
V_1282 = V_10 -> V_1286 >> V_107 ;
if ( ( V_10 -> V_1284 ^ V_1282 ) & ( F_644 ( V_762 ) - 1 ) ||
! F_645 () ) {
unsigned long V_803 ;
for ( V_803 = 0 ; V_803 < V_1283 ; ++ V_803 )
V_10 -> V_5 . V_1280 [ V_3 - 1 ] [ V_803 ] . V_1285 = 1 ;
}
}
return 0 ;
V_400:
for ( V_3 = 0 ; V_3 < V_1278 ; ++ V_3 ) {
F_640 ( V_10 -> V_5 . V_1279 [ V_3 ] ) ;
V_10 -> V_5 . V_1279 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_640 ( V_10 -> V_5 . V_1280 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1280 [ V_3 - 1 ] = NULL ;
}
return - V_399 ;
}
void F_646 ( struct V_102 * V_102 )
{
F_647 ( V_102 ) ;
}
int F_648 ( struct V_102 * V_102 ,
struct V_1276 * V_1287 ,
struct V_1269 * V_1270 ,
enum V_1288 V_1289 )
{
if ( ( V_1287 -> V_1230 >= V_576 ) && ( V_1289 == V_1290 ) ) {
unsigned long V_1286 ;
V_1286 = F_649 ( NULL , 0 , V_1287 -> V_1281 * V_108 ,
V_1291 | V_1292 ,
V_1293 | V_1294 , 0 ) ;
if ( F_186 ( ( void * ) V_1286 ) )
return F_187 ( ( void * ) V_1286 ) ;
V_1287 -> V_1286 = V_1286 ;
}
return 0 ;
}
static void F_650 ( struct V_102 * V_102 ,
struct V_1276 * V_860 )
{
if ( V_860 -> V_292 & V_1295 ) {
F_651 ( V_102 , V_860 ) ;
return;
}
if ( V_860 -> V_292 & V_1296 ) {
if ( V_73 -> V_1297 )
V_73 -> V_1297 ( V_102 , V_860 ) ;
else
F_651 ( V_102 , V_860 ) ;
} else {
if ( V_73 -> V_1298 )
V_73 -> V_1298 ( V_102 , V_860 ) ;
}
}
void F_652 ( struct V_102 * V_102 ,
struct V_1269 * V_1270 ,
const struct V_1276 * V_859 ,
enum V_1288 V_1289 )
{
struct V_1276 * V_860 ;
int V_1299 = 0 ;
if ( ( V_1270 -> V_10 >= V_576 ) && ( V_1289 == V_1300 ) ) {
int V_109 ;
V_109 = F_653 ( V_859 -> V_1286 ,
V_859 -> V_1281 * V_108 ) ;
if ( V_109 < 0 )
F_10 ( V_866
L_32
L_33 ) ;
}
if ( ! V_102 -> V_5 . V_729 )
V_1299 = F_654 ( V_102 ) ;
if ( V_1299 )
F_293 ( V_102 , V_1299 ) ;
V_860 = F_655 ( V_102 -> V_1301 , V_1270 -> V_10 ) ;
if ( V_1289 != V_1300 )
F_650 ( V_102 , V_860 ) ;
}
void F_656 ( struct V_102 * V_102 )
{
F_657 ( V_102 ) ;
}
void F_658 ( struct V_102 * V_102 ,
struct V_1276 * V_10 )
{
F_657 ( V_102 ) ;
}
int F_659 ( struct V_1 * V_2 )
{
if ( F_426 ( V_2 ) && V_73 -> V_1080 )
V_73 -> V_1080 ( V_2 , false ) ;
return ( V_2 -> V_5 . V_1031 == V_1124 &&
! V_2 -> V_5 . V_6 . V_1100 )
|| ! F_660 ( & V_2 -> V_1302 . V_1303 )
|| F_661 ( V_2 )
|| V_2 -> V_5 . V_1126 . V_1127
|| F_135 ( & V_2 -> V_5 . V_85 ) ||
( F_508 ( V_2 ) &&
F_507 ( V_2 ) ) ;
}
int F_662 ( struct V_1 * V_2 )
{
return F_663 ( V_2 ) == V_1110 ;
}
int F_508 ( struct V_1 * V_2 )
{
return V_73 -> V_1082 ( V_2 ) ;
}
unsigned long F_444 ( struct V_1 * V_2 )
{
if ( F_498 ( V_2 ) )
return F_425 ( V_2 ) ;
return ( T_1 ) ( F_379 ( V_2 , V_1165 ) +
F_425 ( V_2 ) ) ;
}
bool F_664 ( struct V_1 * V_2 , unsigned long V_1304 )
{
return F_444 ( V_2 ) == V_1304 ;
}
unsigned long F_424 ( struct V_1 * V_2 )
{
unsigned long V_952 ;
V_952 = V_73 -> V_982 ( V_2 ) ;
if ( V_2 -> V_175 & V_955 )
V_952 &= ~ V_954 ;
return V_952 ;
}
static void F_451 ( struct V_1 * V_2 , unsigned long V_952 )
{
if ( V_2 -> V_175 & V_955 &&
F_664 ( V_2 , V_2 -> V_5 . V_959 ) )
V_952 |= V_954 ;
V_73 -> V_1305 ( V_2 , V_952 ) ;
}
void F_431 ( struct V_1 * V_2 , unsigned long V_952 )
{
F_451 ( V_2 , V_952 ) ;
F_31 ( V_67 , V_2 ) ;
}
void F_665 ( struct V_1 * V_2 , struct V_1306 * V_345 )
{
int V_120 ;
if ( ( V_2 -> V_5 . V_84 . V_944 != V_345 -> V_5 . V_944 ) ||
V_345 -> V_1307 )
return;
V_120 = F_536 ( V_2 ) ;
if ( F_152 ( V_120 ) )
return;
if ( ! V_2 -> V_5 . V_84 . V_944 &&
V_345 -> V_5 . V_105 != V_2 -> V_5 . V_84 . V_1308 ( V_2 ) )
return;
V_2 -> V_5 . V_84 . V_1309 ( V_2 , V_345 -> V_818 , 0 , true ) ;
}
static inline T_1 F_666 ( T_5 V_103 )
{
return F_667 ( V_103 & 0xffffffff , F_668 ( V_4 ) ) ;
}
static inline T_1 F_669 ( T_1 V_1310 )
{
return ( V_1310 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_670 ( struct V_1 * V_2 , T_5 V_103 )
{
T_1 V_1310 = F_666 ( V_103 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1310 ] != ~ 0 )
V_1310 = F_669 ( V_1310 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1310 ] = V_103 ;
}
static T_1 F_671 ( struct V_1 * V_2 , T_5 V_103 )
{
int V_3 ;
T_1 V_1310 = F_666 ( V_103 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1310 ] != V_103 &&
V_2 -> V_5 . V_6 . V_7 [ V_1310 ] != ~ 0 ) ; V_3 ++ )
V_1310 = F_669 ( V_1310 ) ;
return V_1310 ;
}
bool F_672 ( struct V_1 * V_2 , T_5 V_103 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_671 ( V_2 , V_103 ) ] == V_103 ;
}
static void F_673 ( struct V_1 * V_2 , T_5 V_103 )
{
T_1 V_3 , V_803 , V_1311 ;
V_3 = V_803 = F_671 ( V_2 , V_103 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_803 = F_669 ( V_803 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_803 ] == ~ 0 )
return;
V_1311 = F_666 ( V_2 -> V_5 . V_6 . V_7 [ V_803 ] ) ;
} while ( ( V_3 <= V_803 ) ? ( V_3 < V_1311 && V_1311 <= V_803 ) : ( V_3 < V_1311 || V_1311 <= V_803 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_803 ] ;
V_3 = V_803 ;
}
}
static int F_674 ( struct V_1 * V_2 , T_1 V_188 )
{
return F_170 ( V_2 -> V_102 , & V_2 -> V_5 . V_6 . V_38 , & V_188 ,
sizeof( V_188 ) ) ;
}
void F_675 ( struct V_1 * V_2 ,
struct V_1306 * V_345 )
{
struct V_75 V_76 ;
F_676 ( V_345 -> V_5 . V_1312 , V_345 -> V_818 ) ;
F_670 ( V_2 , V_345 -> V_5 . V_103 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_429 & V_430 ) ||
( V_2 -> V_5 . V_6 . V_431 &&
V_73 -> V_88 ( V_2 ) == 0 ) )
F_31 ( V_1099 , V_2 ) ;
else if ( ! F_674 ( V_2 , V_1313 ) ) {
V_76 . V_41 = V_42 ;
V_76 . V_918 = true ;
V_76 . V_62 = 0 ;
V_76 . V_81 = false ;
V_76 . V_80 = V_345 -> V_5 . V_1312 ;
F_37 ( V_2 , & V_76 ) ;
}
}
void F_677 ( struct V_1 * V_2 ,
struct V_1306 * V_345 )
{
struct V_75 V_76 ;
F_678 ( V_345 -> V_5 . V_1312 , V_345 -> V_818 ) ;
if ( V_345 -> V_1307 )
V_345 -> V_5 . V_1312 = ~ 0 ;
else
F_673 ( V_2 , V_345 -> V_5 . V_103 ) ;
if ( ( V_2 -> V_5 . V_6 . V_429 & V_430 ) &&
! F_674 ( V_2 , V_1314 ) ) {
V_76 . V_41 = V_42 ;
V_76 . V_918 = true ;
V_76 . V_62 = 0 ;
V_76 . V_81 = false ;
V_76 . V_80 = V_345 -> V_5 . V_1312 ;
F_37 ( V_2 , & V_76 ) ;
}
V_2 -> V_5 . V_6 . V_1100 = false ;
V_2 -> V_5 . V_1031 = V_1124 ;
}
bool F_679 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_429 & V_430 ) )
return true ;
else
return ! F_510 ( V_2 ) &&
V_73 -> V_1082 ( V_2 ) ;
}
void F_680 ( struct V_102 * V_102 )
{
F_42 ( & V_102 -> V_5 . V_1263 ) ;
}
void F_681 ( struct V_102 * V_102 )
{
F_682 ( & V_102 -> V_5 . V_1263 ) ;
}
bool F_245 ( struct V_102 * V_102 )
{
return F_135 ( & V_102 -> V_5 . V_1263 ) ;
}
