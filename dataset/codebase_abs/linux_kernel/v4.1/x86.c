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
unsigned long V_158 = V_159 | V_160 | V_161 |
V_162 | V_163 ;
if ( V_156 & V_164 )
return 1 ;
if ( ! F_77 ( V_2 ) && ( V_156 & V_139 ) )
return 1 ;
if ( ! F_78 ( V_2 ) && ( V_156 & V_162 ) )
return 1 ;
if ( ! F_79 ( V_2 ) && ( V_156 & V_163 ) )
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
if ( ( V_156 ^ V_157 ) & V_139 )
F_73 ( V_2 ) ;
return 0 ;
}
int F_82 ( struct V_1 * V_2 , unsigned long V_105 )
{
#ifdef F_63
V_105 &= ~ V_168 ;
#endif
if ( V_105 == F_60 ( V_2 ) && ! F_56 ( V_2 ) ) {
F_83 ( V_2 ) ;
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
F_84 ( V_2 ) ;
return 0 ;
}
int F_85 ( struct V_1 * V_2 , unsigned long V_173 )
{
if ( V_173 & V_174 )
return 1 ;
if ( F_86 ( V_2 -> V_102 ) )
F_87 ( V_2 , V_173 ) ;
else
V_2 -> V_5 . V_173 = V_173 ;
return 0 ;
}
unsigned long F_88 ( struct V_1 * V_2 )
{
if ( F_86 ( V_2 -> V_102 ) )
return F_89 ( V_2 ) ;
else
return V_2 -> V_5 . V_173 ;
}
static void F_90 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! ( V_2 -> V_175 & V_176 ) ) {
for ( V_3 = 0 ; V_3 < V_177 ; V_3 ++ )
V_2 -> V_5 . V_178 [ V_3 ] = V_2 -> V_5 . V_179 [ V_3 ] ;
V_2 -> V_5 . V_180 |= V_181 ;
}
}
static void F_91 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_175 & V_176 ) )
V_73 -> V_182 ( V_2 , V_2 -> V_5 . V_183 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
unsigned long V_184 ;
if ( V_2 -> V_175 & V_176 )
V_184 = V_2 -> V_5 . V_185 ;
else
V_184 = V_2 -> V_5 . V_184 ;
V_73 -> V_186 ( V_2 , V_184 ) ;
V_2 -> V_5 . V_180 &= ~ V_187 ;
if ( V_184 & V_188 )
V_2 -> V_5 . V_180 |= V_187 ;
}
static T_2 F_93 ( struct V_1 * V_2 )
{
T_2 V_189 = V_190 ;
if ( ! F_94 ( V_2 ) )
V_189 |= V_191 ;
return V_189 ;
}
static int F_95 ( struct V_1 * V_2 , int V_89 , unsigned long V_192 )
{
switch ( V_89 ) {
case 0 ... 3 :
V_2 -> V_5 . V_179 [ V_89 ] = V_192 ;
if ( ! ( V_2 -> V_175 & V_176 ) )
V_2 -> V_5 . V_178 [ V_89 ] = V_192 ;
break;
case 4 :
case 6 :
if ( V_192 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_183 = ( V_192 & V_193 ) | F_93 ( V_2 ) ;
F_91 ( V_2 ) ;
break;
case 5 :
default:
if ( V_192 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_184 = ( V_192 & V_194 ) | V_195 ;
F_92 ( V_2 ) ;
break;
}
return 0 ;
}
int F_96 ( struct V_1 * V_2 , int V_89 , unsigned long V_192 )
{
if ( F_95 ( V_2 , V_89 , V_192 ) ) {
F_36 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_97 ( struct V_1 * V_2 , int V_89 , unsigned long * V_192 )
{
switch ( V_89 ) {
case 0 ... 3 :
* V_192 = V_2 -> V_5 . V_179 [ V_89 ] ;
break;
case 4 :
case 6 :
if ( V_2 -> V_175 & V_176 )
* V_192 = V_2 -> V_5 . V_183 ;
else
* V_192 = V_73 -> V_196 ( V_2 ) ;
break;
case 5 :
default:
* V_192 = V_2 -> V_5 . V_184 ;
break;
}
return 0 ;
}
bool F_98 ( struct V_1 * V_2 )
{
T_1 V_197 = F_99 ( V_2 , V_198 ) ;
T_2 V_38 ;
int V_29 ;
V_29 = F_100 ( V_2 , V_197 , & V_38 ) ;
if ( V_29 )
return V_29 ;
F_101 ( V_2 , V_199 , ( T_1 ) V_38 ) ;
F_101 ( V_2 , V_200 , V_38 >> 32 ) ;
return V_29 ;
}
bool F_102 ( struct V_1 * V_2 , T_2 V_131 )
{
if ( V_131 & V_201 )
return false ;
if ( V_131 & V_202 ) {
struct V_203 * V_204 ;
V_204 = F_103 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_204 || ! ( V_204 -> V_205 & F_104 ( V_206 ) ) )
return false ;
}
if ( V_131 & V_207 ) {
struct V_203 * V_204 ;
V_204 = F_103 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_204 || ! ( V_204 -> V_197 & F_104 ( V_208 ) ) )
return false ;
}
return true ;
}
static int F_105 ( struct V_1 * V_2 , T_2 V_131 )
{
T_2 V_209 = V_2 -> V_5 . V_131 ;
if ( ! F_102 ( V_2 , V_131 ) )
return 1 ;
if ( F_64 ( V_2 )
&& ( V_2 -> V_5 . V_131 & V_132 ) != ( V_131 & V_132 ) )
return 1 ;
V_131 &= ~ V_210 ;
V_131 |= V_2 -> V_5 . V_131 & V_210 ;
V_73 -> F_105 ( V_2 , V_131 ) ;
if ( ( V_131 ^ V_209 ) & V_211 )
F_66 ( V_2 ) ;
return 0 ;
}
void F_106 ( T_2 V_28 )
{
V_201 &= ~ V_28 ;
}
int F_107 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
switch ( V_21 -> V_144 ) {
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
if ( F_108 ( V_21 -> V_38 ) )
return 1 ;
break;
case V_217 :
case V_218 :
V_21 -> V_38 = F_109 ( V_21 -> V_38 ) ;
}
return V_73 -> V_219 ( V_2 , V_21 ) ;
}
static int F_110 ( struct V_1 * V_2 , unsigned V_144 , T_2 * V_38 )
{
struct V_32 V_21 ;
V_21 . V_38 = * V_38 ;
V_21 . V_144 = V_144 ;
V_21 . V_40 = true ;
return F_107 ( V_2 , & V_21 ) ;
}
static void F_111 ( struct V_220 * V_221 )
{
struct V_222 * V_223 = & V_222 ;
T_2 V_224 ;
V_224 = F_112 ( F_113 ( V_221 -> V_225 . V_226 , V_221 -> V_227 ) ) ;
F_114 ( & V_223 -> V_228 ) ;
V_223 -> clock . V_229 = V_221 -> V_225 . clock -> V_230 . V_229 ;
V_223 -> clock . V_231 = V_221 -> V_225 . V_231 ;
V_223 -> clock . V_28 = V_221 -> V_225 . V_28 ;
V_223 -> clock . V_232 = V_221 -> V_225 . V_232 ;
V_223 -> clock . V_233 = V_221 -> V_225 . V_233 ;
V_223 -> V_224 = V_224 ;
V_223 -> V_234 = V_221 -> V_225 . V_235 ;
F_115 ( & V_223 -> V_228 ) ;
}
void F_116 ( struct V_1 * V_2 )
{
F_31 ( V_236 , V_2 ) ;
}
static void F_117 ( struct V_102 * V_102 , T_6 V_237 )
{
int V_238 ;
int V_120 ;
struct V_239 V_240 ;
struct V_241 V_242 ;
if ( ! V_237 )
return;
V_120 = F_118 ( V_102 , V_237 , & V_238 , sizeof( V_238 ) ) ;
if ( V_120 )
return;
if ( V_238 & 1 )
++ V_238 ;
++ V_238 ;
F_119 ( V_102 , V_237 , & V_238 , sizeof( V_238 ) ) ;
F_120 ( & V_242 ) ;
if ( V_102 -> V_5 . V_243 ) {
struct V_241 V_244 = F_121 ( V_102 -> V_5 . V_243 ) ;
V_242 = F_122 ( V_242 , V_244 ) ;
}
V_240 . V_245 = V_242 . V_246 ;
V_240 . V_247 = V_242 . V_248 ;
V_240 . V_238 = V_238 ;
F_119 ( V_102 , V_237 , & V_240 , sizeof( V_240 ) ) ;
V_238 ++ ;
F_119 ( V_102 , V_237 , & V_238 , sizeof( V_238 ) ) ;
}
static T_7 F_123 ( T_7 V_249 , T_7 V_250 )
{
T_7 V_251 , V_252 ;
__asm__ ( "divl %4"
: "=a" (quotient), "=d" (remainder)
: "0" (0), "1" (dividend), "r" (divisor) );
return V_251 ;
}
static void F_124 ( T_7 V_253 , T_7 V_254 ,
T_8 * V_255 , T_1 * V_256 )
{
T_9 V_257 ;
T_10 V_233 = 0 ;
T_9 V_258 ;
T_7 V_259 ;
V_258 = V_254 * 1000LL ;
V_257 = V_253 * 1000LL ;
while ( V_258 > V_257 * 2 || V_258 & 0xffffffff00000000ULL ) {
V_258 >>= 1 ;
V_233 -- ;
}
V_259 = ( T_7 ) V_258 ;
while ( V_259 <= V_257 || V_257 & 0xffffffff00000000ULL ) {
if ( V_257 & 0xffffffff00000000ULL || V_259 & 0x80000000 )
V_257 >>= 1 ;
else
V_259 <<= 1 ;
V_233 ++ ;
}
* V_255 = V_233 ;
* V_256 = F_123 ( V_257 , V_259 ) ;
F_125 ( L_2 ,
V_260 , V_254 , V_253 , V_233 , * V_256 ) ;
}
static inline T_2 F_126 ( void )
{
return F_127 () ;
}
static inline T_2 F_128 ( struct V_1 * V_2 , T_2 V_247 )
{
return F_129 ( V_247 , V_2 -> V_5 . V_261 ,
V_2 -> V_5 . V_262 ) ;
}
static T_1 F_130 ( T_1 V_263 , T_11 V_264 )
{
T_2 V_265 = ( T_2 ) V_263 * ( 1000000 + V_264 ) ;
F_131 ( V_265 , 1000000 ) ;
return V_265 ;
}
static void F_132 ( struct V_1 * V_2 , T_1 V_266 )
{
T_1 V_267 , V_268 ;
int V_269 = 0 ;
if ( V_266 == 0 )
return;
F_124 ( V_266 , V_270 / 1000 ,
& V_2 -> V_5 . V_262 ,
& V_2 -> V_5 . V_261 ) ;
V_2 -> V_5 . V_271 = V_266 ;
V_267 = F_130 ( V_272 , - V_273 ) ;
V_268 = F_130 ( V_272 , V_273 ) ;
if ( V_266 < V_267 || V_266 > V_268 ) {
F_125 ( L_3 , V_266 , V_267 , V_268 ) ;
V_269 = 1 ;
}
V_73 -> V_274 ( V_2 , V_266 , V_269 ) ;
}
static T_2 F_133 ( struct V_1 * V_2 , T_12 V_275 )
{
T_2 V_276 = F_129 ( V_275 - V_2 -> V_5 . V_277 ,
V_2 -> V_5 . V_261 ,
V_2 -> V_5 . V_262 ) ;
V_276 += V_2 -> V_5 . V_278 ;
return V_276 ;
}
static void F_134 ( struct V_1 * V_2 )
{
#ifdef F_63
bool V_279 ;
struct V_280 * V_281 = & V_2 -> V_102 -> V_5 ;
struct V_222 * V_282 = & V_222 ;
V_279 = ( V_281 -> V_283 + 1 ==
F_135 ( & V_2 -> V_102 -> V_284 ) ) ;
if ( V_281 -> V_285 ||
( V_282 -> clock . V_229 == V_286 && V_279 ) )
F_31 ( V_287 , V_2 ) ;
F_136 ( V_2 -> V_288 , V_281 -> V_283 ,
F_135 ( & V_2 -> V_102 -> V_284 ) ,
V_281 -> V_285 , V_282 -> clock . V_229 ) ;
#endif
}
static void F_137 ( struct V_1 * V_2 , T_12 V_94 )
{
T_2 V_289 = V_73 -> V_290 ( V_2 ) ;
V_2 -> V_5 . V_291 += V_94 - V_289 ;
}
void F_138 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
struct V_102 * V_102 = V_2 -> V_102 ;
T_2 V_94 , V_292 , V_293 ;
unsigned long V_294 ;
T_12 V_295 ;
bool V_296 ;
bool V_297 ;
T_2 V_38 = V_21 -> V_38 ;
F_139 ( & V_102 -> V_5 . V_298 , V_294 ) ;
V_94 = V_73 -> V_299 ( V_2 , V_38 ) ;
V_292 = F_126 () ;
V_293 = V_292 - V_102 -> V_5 . V_300 ;
if ( V_2 -> V_5 . V_271 ) {
int V_301 = 0 ;
V_295 = V_38 - V_102 -> V_5 . V_302 ;
#ifdef F_63
V_295 = ( V_295 * 1000 ) / V_2 -> V_5 . V_271 ;
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
F_131 ( V_293 , 1000 ) ;
V_295 -= V_293 ;
if ( V_295 < 0 )
V_295 = - V_295 ;
if ( V_301 )
V_295 = V_303 ;
} else
V_295 = V_303 ;
if ( V_295 < V_303 &&
V_2 -> V_5 . V_271 == V_102 -> V_5 . V_304 ) {
if ( ! F_140 () ) {
V_94 = V_102 -> V_5 . V_305 ;
F_125 ( L_4 , V_38 ) ;
} else {
T_2 V_306 = F_128 ( V_2 , V_293 ) ;
V_38 += V_306 ;
V_94 = V_73 -> V_299 ( V_2 , V_38 ) ;
F_125 ( L_5 , V_306 ) ;
}
V_296 = true ;
V_297 = ( V_2 -> V_5 . V_307 == V_102 -> V_5 . V_308 ) ;
} else {
V_102 -> V_5 . V_308 ++ ;
V_102 -> V_5 . V_309 = V_292 ;
V_102 -> V_5 . V_310 = V_38 ;
V_102 -> V_5 . V_305 = V_94 ;
V_296 = false ;
F_125 ( L_6 ,
V_102 -> V_5 . V_308 , V_38 ) ;
}
V_102 -> V_5 . V_300 = V_292 ;
V_102 -> V_5 . V_302 = V_38 ;
V_102 -> V_5 . V_304 = V_2 -> V_5 . V_271 ;
V_2 -> V_5 . V_311 = V_38 ;
V_2 -> V_5 . V_307 = V_102 -> V_5 . V_308 ;
V_2 -> V_5 . V_277 = V_102 -> V_5 . V_309 ;
V_2 -> V_5 . V_278 = V_102 -> V_5 . V_310 ;
if ( F_141 ( V_2 ) && ! V_21 -> V_40 )
F_137 ( V_2 , V_94 ) ;
V_73 -> V_312 ( V_2 , V_94 ) ;
F_142 ( & V_102 -> V_5 . V_298 , V_294 ) ;
F_143 ( & V_102 -> V_5 . V_313 ) ;
if ( ! V_296 ) {
V_102 -> V_5 . V_283 = 0 ;
} else if ( ! V_297 ) {
V_102 -> V_5 . V_283 ++ ;
}
F_134 ( V_2 ) ;
F_144 ( & V_102 -> V_5 . V_313 ) ;
}
static T_13 F_145 ( void )
{
T_13 V_109 ;
T_2 V_314 ;
F_146 () ;
V_109 = ( T_13 ) F_147 () ;
V_314 = V_222 . clock . V_231 ;
if ( F_148 ( V_109 >= V_314 ) )
return V_109 ;
asm volatile ("");
return V_314 ;
}
static inline T_2 F_149 ( T_13 * V_315 )
{
long V_265 ;
struct V_222 * V_282 = & V_222 ;
* V_315 = F_145 () ;
V_265 = ( * V_315 - V_282 -> clock . V_231 ) & V_282 -> clock . V_28 ;
return V_265 * V_282 -> clock . V_232 ;
}
static int F_150 ( T_12 * V_316 , T_13 * V_315 )
{
struct V_222 * V_282 = & V_222 ;
unsigned long V_228 ;
int V_317 ;
T_2 V_292 ;
do {
V_228 = F_151 ( & V_282 -> V_228 ) ;
V_317 = V_282 -> clock . V_229 ;
V_292 = V_282 -> V_234 ;
V_292 += F_149 ( V_315 ) ;
V_292 >>= V_282 -> clock . V_233 ;
V_292 += V_282 -> V_224 ;
} while ( F_152 ( F_153 ( & V_282 -> V_228 , V_228 ) ) );
* V_316 = V_292 ;
return V_317 ;
}
static bool F_154 ( T_12 * V_275 , T_13 * V_315 )
{
if ( V_222 . clock . V_229 != V_286 )
return false ;
return F_150 ( V_275 , V_315 ) == V_286 ;
}
static void F_155 ( struct V_102 * V_102 )
{
#ifdef F_63
struct V_280 * V_281 = & V_102 -> V_5 ;
int V_229 ;
bool V_318 , V_279 ;
V_279 = ( V_281 -> V_283 + 1 ==
F_135 ( & V_102 -> V_284 ) ) ;
V_318 = F_154 (
& V_281 -> V_319 ,
& V_281 -> V_320 ) ;
V_281 -> V_285 = V_318 && V_279
&& ! V_321
&& ! V_281 -> V_322 ;
if ( V_281 -> V_285 )
F_156 ( & V_323 , 1 ) ;
V_229 = V_222 . clock . V_229 ;
F_157 ( V_281 -> V_285 , V_229 ,
V_279 ) ;
#endif
}
static void F_158 ( struct V_102 * V_102 )
{
#ifdef F_63
int V_3 ;
struct V_1 * V_2 ;
struct V_280 * V_281 = & V_102 -> V_5 ;
F_143 ( & V_281 -> V_313 ) ;
F_159 ( V_102 ) ;
F_155 ( V_102 ) ;
F_160 (i, vcpu, kvm)
F_31 ( V_324 , V_2 ) ;
F_160 (i, vcpu, kvm)
F_161 ( V_325 , & V_2 -> V_326 ) ;
F_144 ( & V_281 -> V_313 ) ;
#endif
}
static int F_162 ( struct V_1 * V_265 )
{
unsigned long V_294 , V_266 ;
struct V_327 * V_2 = & V_265 -> V_5 ;
struct V_280 * V_281 = & V_265 -> V_102 -> V_5 ;
T_12 V_275 ;
T_2 V_328 , V_329 ;
struct V_330 V_331 ;
T_14 V_332 ;
bool V_285 ;
V_275 = 0 ;
V_329 = 0 ;
F_143 ( & V_281 -> V_313 ) ;
V_285 = V_281 -> V_285 ;
if ( V_285 ) {
V_329 = V_281 -> V_320 ;
V_275 = V_281 -> V_319 ;
}
F_144 ( & V_281 -> V_313 ) ;
F_163 ( V_294 ) ;
V_266 = F_164 ( V_333 ) ;
if ( F_152 ( V_266 == 0 ) ) {
F_165 ( V_294 ) ;
F_31 ( V_324 , V_265 ) ;
return 1 ;
}
if ( ! V_285 ) {
V_329 = F_166 () ;
V_275 = F_126 () ;
}
V_328 = V_73 -> V_334 ( V_265 , V_329 ) ;
if ( V_2 -> V_335 ) {
T_2 V_276 = F_133 ( V_265 , V_275 ) ;
if ( V_276 > V_328 ) {
F_167 ( V_265 , V_276 - V_328 ) ;
V_328 = V_276 ;
}
}
F_165 ( V_294 ) ;
if ( ! V_2 -> V_336 )
return 0 ;
if ( F_152 ( V_2 -> V_337 != V_266 ) ) {
F_124 ( V_270 / 1000 , V_266 ,
& V_2 -> V_338 . V_339 ,
& V_2 -> V_338 . V_340 ) ;
V_2 -> V_337 = V_266 ;
}
V_2 -> V_338 . V_328 = V_328 ;
V_2 -> V_338 . V_341 = V_275 + V_265 -> V_102 -> V_5 . V_243 ;
V_2 -> V_311 = V_328 ;
if ( F_152 ( F_168 ( V_265 -> V_102 , & V_2 -> V_342 ,
& V_331 , sizeof( V_331 ) ) ) )
return 0 ;
F_169 ( F_170 ( struct V_330 , V_238 ) != 0 ) ;
V_2 -> V_338 . V_238 = V_331 . V_238 + 1 ;
F_171 ( V_265 -> V_102 , & V_2 -> V_342 ,
& V_2 -> V_338 ,
sizeof( V_2 -> V_338 . V_238 ) ) ;
F_14 () ;
V_332 = ( V_331 . V_294 & V_343 ) ;
if ( V_2 -> V_344 ) {
V_332 |= V_343 ;
V_2 -> V_344 = false ;
}
if ( V_285 )
V_332 |= V_345 ;
V_2 -> V_338 . V_294 = V_332 ;
F_172 ( V_265 -> V_288 , & V_2 -> V_338 ) ;
F_171 ( V_265 -> V_102 , & V_2 -> V_342 ,
& V_2 -> V_338 ,
sizeof( V_2 -> V_338 ) ) ;
F_14 () ;
V_2 -> V_338 . V_238 ++ ;
F_171 ( V_265 -> V_102 , & V_2 -> V_342 ,
& V_2 -> V_338 ,
sizeof( V_2 -> V_338 . V_238 ) ) ;
return 0 ;
}
static void F_173 ( struct V_346 * V_347 )
{
int V_3 ;
struct V_348 * V_349 = F_174 ( V_347 ) ;
struct V_280 * V_281 = F_4 ( V_349 , struct V_280 ,
V_350 ) ;
struct V_102 * V_102 = F_4 ( V_281 , struct V_102 , V_5 ) ;
struct V_1 * V_2 ;
F_160 (i, vcpu, kvm) {
F_31 ( V_324 , V_2 ) ;
F_175 ( V_2 ) ;
}
}
static void F_176 ( struct V_1 * V_265 )
{
struct V_102 * V_102 = V_265 -> V_102 ;
F_31 ( V_324 , V_265 ) ;
F_177 ( & V_102 -> V_5 . V_350 ,
V_351 ) ;
}
static void F_178 ( struct V_346 * V_347 )
{
struct V_348 * V_349 = F_174 ( V_347 ) ;
struct V_280 * V_281 = F_4 ( V_349 , struct V_280 ,
V_352 ) ;
struct V_102 * V_102 = F_4 ( V_281 , struct V_102 , V_5 ) ;
F_177 ( & V_102 -> V_5 . V_350 , 0 ) ;
F_177 ( & V_102 -> V_5 . V_352 ,
V_353 ) ;
}
static bool F_179 ( unsigned V_21 )
{
switch ( V_21 ) {
case 0x200 ... 0x200 + 2 * V_354 - 1 :
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
case V_366 :
case V_367 :
return true ;
case 0x2f8 :
return true ;
}
return false ;
}
static bool F_180 ( unsigned V_316 )
{
return V_316 < 8 && ( 1 << V_316 ) & 0xf3 ;
}
static bool F_181 ( unsigned V_316 )
{
return V_316 < 8 && ( 1 << V_316 ) & 0x73 ;
}
bool F_182 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
int V_3 ;
T_2 V_28 ;
if ( ! F_179 ( V_21 ) )
return false ;
if ( V_21 == V_367 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_180 ( ( V_38 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
} else if ( V_21 == V_366 ) {
if ( V_38 & ~ 0xcff )
return false ;
return F_181 ( V_38 & 0xff ) ;
} else if ( V_21 >= V_355 && V_21 <= V_365 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_181 ( ( V_38 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
}
F_29 ( ! ( V_21 >= 0x200 && V_21 < 0x200 + 2 * V_354 ) ) ;
V_28 = ( ~ 0ULL ) << F_22 ( V_2 ) ;
if ( ( V_21 & 1 ) == 0 ) {
if ( ! F_181 ( V_38 & 0xff ) )
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
static int F_183 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
T_2 * V_368 = ( T_2 * ) & V_2 -> V_5 . V_369 . V_370 ;
if ( ! F_182 ( V_2 , V_21 , V_38 ) )
return 1 ;
if ( V_21 == V_366 ) {
V_2 -> V_5 . V_369 . V_371 = V_38 ;
V_2 -> V_5 . V_369 . V_372 = ( V_38 & 0xc00 ) >> 10 ;
} else if ( V_21 == V_355 )
V_368 [ 0 ] = V_38 ;
else if ( V_21 == V_356 || V_21 == V_357 )
V_368 [ 1 + V_21 - V_356 ] = V_38 ;
else if ( V_21 >= V_358 && V_21 <= V_365 )
V_368 [ 3 + V_21 - V_358 ] = V_38 ;
else if ( V_21 == V_367 )
V_2 -> V_5 . V_373 = V_38 ;
else {
int V_374 , V_375 ;
T_2 * V_376 ;
V_374 = ( V_21 - 0x200 ) / 2 ;
V_375 = V_21 - 0x200 - 2 * V_374 ;
if ( ! V_375 )
V_376 =
( T_2 * ) & V_2 -> V_5 . V_369 . V_377 [ V_374 ] . V_378 ;
else
V_376 =
( T_2 * ) & V_2 -> V_5 . V_369 . V_377 [ V_374 ] . V_379 ;
* V_376 = V_38 ;
}
F_66 ( V_2 ) ;
return 0 ;
}
static int F_184 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
T_2 V_380 = V_2 -> V_5 . V_380 ;
unsigned V_381 = V_380 & 0xff ;
switch ( V_21 ) {
case V_382 :
V_2 -> V_5 . V_383 = V_38 ;
break;
case V_384 :
if ( ! ( V_380 & V_385 ) )
return 1 ;
if ( V_38 != 0 && V_38 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_386 = V_38 ;
break;
default:
if ( V_21 >= V_387 &&
V_21 < F_185 ( V_381 ) ) {
T_1 V_94 = V_21 - V_387 ;
if ( ( V_94 & 0x3 ) == 0 &&
V_38 != 0 && ( V_38 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_388 [ V_94 ] = V_38 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_186 ( struct V_1 * V_2 , T_2 V_38 )
{
struct V_102 * V_102 = V_2 -> V_102 ;
int V_389 = F_57 ( V_2 ) ;
T_14 * V_390 = V_389 ? ( T_14 * ) ( long ) V_102 -> V_5 . F_186 . V_391
: ( T_14 * ) ( long ) V_102 -> V_5 . F_186 . V_392 ;
T_14 V_393 = V_389 ? V_102 -> V_5 . F_186 . V_394
: V_102 -> V_5 . F_186 . V_395 ;
T_1 V_396 = V_38 & ~ V_397 ;
T_2 V_398 = V_38 & V_397 ;
T_14 * V_399 ;
int V_120 ;
V_120 = - V_400 ;
if ( V_396 >= V_393 )
goto V_114;
V_120 = - V_401 ;
V_399 = F_187 ( V_390 + ( V_396 * V_108 ) , V_108 ) ;
if ( F_188 ( V_399 ) ) {
V_120 = F_189 ( V_399 ) ;
goto V_114;
}
if ( F_119 ( V_102 , V_398 , V_399 , V_108 ) )
goto V_402;
V_120 = 0 ;
V_402:
F_190 ( V_399 ) ;
V_114:
return V_120 ;
}
static bool F_191 ( struct V_102 * V_102 )
{
return V_102 -> V_5 . V_403 & V_404 ;
}
static bool F_192 ( T_1 V_21 )
{
bool V_120 = false ;
switch ( V_21 ) {
case V_405 :
case V_406 :
case V_407 :
case V_408 :
V_120 = true ;
break;
}
return V_120 ;
}
static int F_193 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
struct V_102 * V_102 = V_2 -> V_102 ;
switch ( V_21 ) {
case V_405 :
V_102 -> V_5 . V_409 = V_38 ;
if ( ! V_102 -> V_5 . V_409 )
V_102 -> V_5 . V_403 &= ~ V_404 ;
break;
case V_406 : {
T_2 V_103 ;
unsigned long V_410 ;
T_14 V_411 [ 4 ] ;
if ( ! V_102 -> V_5 . V_409 )
break;
if ( ! ( V_38 & V_404 ) ) {
V_102 -> V_5 . V_403 = V_38 ;
break;
}
V_103 = V_38 >> V_412 ;
V_410 = F_194 ( V_102 , V_103 ) ;
if ( F_195 ( V_410 ) )
return 1 ;
V_73 -> V_413 ( V_2 , V_411 ) ;
( ( unsigned char * ) V_411 ) [ 3 ] = 0xc3 ;
if ( F_196 ( ( void V_414 * ) V_410 , V_411 , 4 ) )
return 1 ;
V_102 -> V_5 . V_403 = V_38 ;
F_197 ( V_102 , V_103 ) ;
break;
}
case V_407 : {
T_2 V_103 ;
T_15 V_415 ;
memset ( & V_415 , 0 , sizeof( V_415 ) ) ;
V_102 -> V_5 . V_416 = V_38 ;
if ( ! ( V_38 & V_417 ) )
break;
V_103 = V_38 >> V_418 ;
if ( F_119 ( V_102 , V_103 << V_418 ,
& V_415 , sizeof( V_415 ) ) )
return 1 ;
F_197 ( V_102 , V_103 ) ;
break;
}
default:
F_198 ( V_2 , L_7
L_8 , V_21 , V_38 ) ;
return 1 ;
}
return 0 ;
}
static int F_199 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
switch ( V_21 ) {
case V_419 : {
T_2 V_103 ;
unsigned long V_410 ;
if ( ! ( V_38 & V_420 ) ) {
V_2 -> V_5 . V_421 = V_38 ;
if ( F_200 ( V_2 , 0 ) )
return 1 ;
break;
}
V_103 = V_38 >> V_422 ;
V_410 = F_194 ( V_2 -> V_102 , V_103 ) ;
if ( F_195 ( V_410 ) )
return 1 ;
if ( F_201 ( ( void V_414 * ) V_410 , V_108 ) )
return 1 ;
V_2 -> V_5 . V_421 = V_38 ;
F_197 ( V_2 -> V_102 , V_103 ) ;
if ( F_200 ( V_2 , F_48 ( V_103 ) | V_423 ) )
return 1 ;
break;
}
case V_424 :
return F_202 ( V_2 , V_425 , V_38 ) ;
case V_426 :
return F_202 ( V_2 , V_427 , V_38 ) ;
case V_428 :
return F_202 ( V_2 , V_429 , V_38 ) ;
default:
F_198 ( V_2 , L_7
L_8 , V_21 , V_38 ) ;
return 1 ;
}
return 0 ;
}
static int F_203 ( struct V_1 * V_2 , T_2 V_38 )
{
T_6 V_430 = V_38 & ~ 0x3f ;
if ( V_38 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_431 = V_38 ;
if ( ! ( V_38 & V_432 ) ) {
F_65 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_204 ( V_2 -> V_102 , & V_2 -> V_5 . V_6 . V_38 , V_430 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_433 = ! ( V_38 & V_434 ) ;
F_205 ( V_2 ) ;
return 0 ;
}
static void F_206 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_336 = false ;
}
static void F_207 ( struct V_1 * V_2 )
{
T_2 V_306 ;
if ( ! ( V_2 -> V_5 . V_435 . V_431 & V_423 ) )
return;
V_306 = V_436 -> V_437 . V_438 - V_2 -> V_5 . V_435 . V_439 ;
V_2 -> V_5 . V_435 . V_439 = V_436 -> V_437 . V_438 ;
V_2 -> V_5 . V_435 . V_440 = V_306 ;
}
static void F_208 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_435 . V_431 & V_423 ) )
return;
if ( F_152 ( F_168 ( V_2 -> V_102 , & V_2 -> V_5 . V_435 . V_441 ,
& V_2 -> V_5 . V_435 . V_442 , sizeof( struct V_443 ) ) ) )
return;
V_2 -> V_5 . V_435 . V_442 . V_442 += V_2 -> V_5 . V_435 . V_440 ;
V_2 -> V_5 . V_435 . V_442 . V_238 += 2 ;
V_2 -> V_5 . V_435 . V_440 = 0 ;
F_171 ( V_2 -> V_102 , & V_2 -> V_5 . V_435 . V_441 ,
& V_2 -> V_5 . V_435 . V_442 , sizeof( struct V_443 ) ) ;
}
int F_209 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
bool V_444 = false ;
T_1 V_21 = V_33 -> V_144 ;
T_2 V_38 = V_33 -> V_38 ;
switch ( V_21 ) {
case V_445 :
case V_446 :
case V_447 :
case V_448 :
case V_449 :
case V_450 :
break;
case V_451 :
return F_105 ( V_2 , V_38 ) ;
case V_452 :
V_38 &= ~ ( T_2 ) 0x40 ;
V_38 &= ~ ( T_2 ) 0x100 ;
V_38 &= ~ ( T_2 ) 0x8 ;
V_38 &= ~ ( T_2 ) 0x40000 ;
if ( V_38 != 0 ) {
F_198 ( V_2 , L_9 ,
V_38 ) ;
return 1 ;
}
break;
case V_453 :
if ( V_38 != 0 ) {
F_198 ( V_2 , L_10
L_11 , V_38 ) ;
return 1 ;
}
break;
case V_454 :
if ( ! V_38 ) {
break;
} else if ( V_38 & ~ ( V_455 | V_456 ) ) {
return 1 ;
}
F_198 ( V_2 , L_12 ,
V_260 , V_38 ) ;
break;
case 0x200 ... 0x2ff :
return F_183 ( V_2 , V_21 , V_38 ) ;
case V_457 :
return F_21 ( V_2 , V_33 ) ;
case V_458 ... V_458 + 0x3ff :
return F_210 ( V_2 , V_21 , V_38 ) ;
case V_459 :
F_211 ( V_2 , V_38 ) ;
break;
case V_460 :
if ( F_141 ( V_2 ) ) {
if ( ! V_33 -> V_40 ) {
T_12 V_461 = V_38 - V_2 -> V_5 . V_291 ;
V_73 -> V_462 ( V_2 , V_461 , true ) ;
}
V_2 -> V_5 . V_291 = V_38 ;
}
break;
case V_463 :
V_2 -> V_5 . V_464 = V_38 ;
break;
case V_465 :
case V_466 :
V_2 -> V_102 -> V_5 . V_237 = V_38 ;
F_117 ( V_2 -> V_102 , V_38 ) ;
break;
case V_467 :
case V_468 : {
T_2 V_469 ;
struct V_280 * V_281 = & V_2 -> V_102 -> V_5 ;
F_206 ( V_2 ) ;
if ( V_2 -> V_288 == 0 && ! V_33 -> V_40 ) {
bool V_470 = ( V_21 == V_468 ) ;
if ( V_281 -> V_322 != V_470 )
F_212 ( V_287 ,
& V_2 -> V_326 ) ;
V_281 -> V_322 = V_470 ;
}
V_2 -> V_5 . time = V_38 ;
F_31 ( V_471 , V_2 ) ;
if ( ! ( V_38 & 1 ) )
break;
V_469 = V_38 & ~ ( V_397 | 1 ) ;
if ( F_204 ( V_2 -> V_102 ,
& V_2 -> V_5 . V_342 , V_38 & ~ 1ULL ,
sizeof( struct V_330 ) ) )
V_2 -> V_5 . V_336 = false ;
else
V_2 -> V_5 . V_336 = true ;
break;
}
case V_472 :
if ( F_203 ( V_2 , V_38 ) )
return 1 ;
break;
case V_473 :
if ( F_152 ( ! F_213 () ) )
return 1 ;
if ( V_38 & V_474 )
return 1 ;
if ( F_204 ( V_2 -> V_102 , & V_2 -> V_5 . V_435 . V_441 ,
V_38 & V_475 ,
sizeof( struct V_443 ) ) )
return 1 ;
V_2 -> V_5 . V_435 . V_431 = V_38 ;
if ( ! ( V_38 & V_423 ) )
break;
V_2 -> V_5 . V_435 . V_439 = V_436 -> V_437 . V_438 ;
F_214 () ;
F_207 ( V_2 ) ;
F_215 () ;
F_31 ( V_476 , V_2 ) ;
break;
case V_477 :
if ( F_200 ( V_2 , V_38 ) )
return 1 ;
break;
case V_384 :
case V_382 :
case V_387 ... F_185 ( V_478 ) - 1 :
return F_184 ( V_2 , V_21 , V_38 ) ;
case V_479 :
case V_480 :
case V_481 :
case V_482 :
if ( V_38 != 0 )
F_198 ( V_2 , L_13
L_14 , V_21 , V_38 ) ;
break;
case V_483 :
case V_484 :
case V_485 :
case V_486 :
F_198 ( V_2 , L_13
L_14 , V_21 , V_38 ) ;
break;
case V_487 :
case V_488 :
V_444 = true ;
case V_489 :
case V_490 :
if ( F_216 ( V_2 , V_21 ) )
return F_217 ( V_2 , V_33 ) ;
if ( V_444 || V_38 != 0 )
F_198 ( V_2 , L_15
L_14 , V_21 , V_38 ) ;
break;
case V_491 :
break;
case V_405 ... V_492 :
if ( F_192 ( V_21 ) ) {
int V_120 ;
F_218 ( & V_2 -> V_102 -> V_493 ) ;
V_120 = F_193 ( V_2 , V_21 , V_38 ) ;
F_219 ( & V_2 -> V_102 -> V_493 ) ;
return V_120 ;
} else
return F_199 ( V_2 , V_21 , V_38 ) ;
break;
case V_494 :
F_198 ( V_2 , L_16 , V_21 , V_38 ) ;
break;
case V_495 :
if ( ! F_220 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_496 . V_497 = V_38 ;
break;
case V_498 :
if ( ! F_220 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_496 . V_499 = V_38 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_102 -> V_5 . F_186 . V_21 ) )
return F_186 ( V_2 , V_38 ) ;
if ( F_216 ( V_2 , V_21 ) )
return F_217 ( V_2 , V_33 ) ;
if ( ! V_500 ) {
F_198 ( V_2 , L_17 ,
V_21 , V_38 ) ;
return 1 ;
} else {
F_198 ( V_2 , L_16 ,
V_21 , V_38 ) ;
break;
}
}
return 0 ;
}
int F_221 ( struct V_1 * V_2 , T_1 V_501 , T_2 * V_502 )
{
return V_73 -> V_503 ( V_2 , V_501 , V_502 ) ;
}
static int F_222 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_502 )
{
T_2 * V_368 = ( T_2 * ) & V_2 -> V_5 . V_369 . V_370 ;
if ( ! F_179 ( V_21 ) )
return 1 ;
if ( V_21 == V_366 )
* V_502 = V_2 -> V_5 . V_369 . V_371 +
( V_2 -> V_5 . V_369 . V_372 << 10 ) ;
else if ( V_21 == V_355 )
* V_502 = V_368 [ 0 ] ;
else if ( V_21 == V_356 || V_21 == V_357 )
* V_502 = V_368 [ 1 + V_21 - V_356 ] ;
else if ( V_21 >= V_358 && V_21 <= V_365 )
* V_502 = V_368 [ 3 + V_21 - V_358 ] ;
else if ( V_21 == V_367 )
* V_502 = V_2 -> V_5 . V_373 ;
else {
int V_374 , V_375 ;
T_2 * V_376 ;
V_374 = ( V_21 - 0x200 ) / 2 ;
V_375 = V_21 - 0x200 - 2 * V_374 ;
if ( ! V_375 )
V_376 =
( T_2 * ) & V_2 -> V_5 . V_369 . V_377 [ V_374 ] . V_378 ;
else
V_376 =
( T_2 * ) & V_2 -> V_5 . V_369 . V_377 [ V_374 ] . V_379 ;
* V_502 = * V_376 ;
}
return 0 ;
}
static int F_223 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_502 )
{
T_2 V_38 ;
T_2 V_380 = V_2 -> V_5 . V_380 ;
unsigned V_381 = V_380 & 0xff ;
switch ( V_21 ) {
case V_504 :
case V_505 :
V_38 = 0 ;
break;
case V_506 :
V_38 = V_2 -> V_5 . V_380 ;
break;
case V_384 :
if ( ! ( V_380 & V_385 ) )
return 1 ;
V_38 = V_2 -> V_5 . V_386 ;
break;
case V_382 :
V_38 = V_2 -> V_5 . V_383 ;
break;
default:
if ( V_21 >= V_387 &&
V_21 < F_185 ( V_381 ) ) {
T_1 V_94 = V_21 - V_387 ;
V_38 = V_2 -> V_5 . V_388 [ V_94 ] ;
break;
}
return 1 ;
}
* V_502 = V_38 ;
return 0 ;
}
static int F_224 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_502 )
{
T_2 V_38 = 0 ;
struct V_102 * V_102 = V_2 -> V_102 ;
switch ( V_21 ) {
case V_405 :
V_38 = V_102 -> V_5 . V_409 ;
break;
case V_406 :
V_38 = V_102 -> V_5 . V_403 ;
break;
case V_408 : {
V_38 =
F_225 ( F_126 () + V_102 -> V_5 . V_243 , 100 ) ;
break;
}
case V_407 :
V_38 = V_102 -> V_5 . V_416 ;
break;
default:
F_198 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_502 = V_38 ;
return 0 ;
}
static int F_226 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_502 )
{
T_2 V_38 = 0 ;
switch ( V_21 ) {
case V_507 : {
int V_120 ;
struct V_1 * V_265 ;
F_160 (r, v, vcpu->kvm) {
if ( V_265 == V_2 ) {
V_38 = V_120 ;
break;
}
}
break;
}
case V_424 :
return F_227 ( V_2 , V_425 , V_502 ) ;
case V_426 :
return F_227 ( V_2 , V_427 , V_502 ) ;
case V_428 :
return F_227 ( V_2 , V_429 , V_502 ) ;
case V_419 :
V_38 = V_2 -> V_5 . V_421 ;
break;
default:
F_198 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_502 = V_38 ;
return 0 ;
}
int F_228 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_502 )
{
T_2 V_38 ;
switch ( V_21 ) {
case V_508 :
case V_509 :
case V_454 :
case V_510 :
case V_511 :
case V_512 :
case V_513 :
case V_514 :
case V_452 :
case V_448 :
case V_479 :
case V_480 :
case V_481 :
case V_482 :
case V_483 :
case V_484 :
case V_485 :
case V_486 :
case V_515 :
case V_445 :
case V_453 :
case V_450 :
V_38 = 0 ;
break;
case V_487 :
case V_488 :
case V_489 :
case V_490 :
if ( F_216 ( V_2 , V_21 ) )
return F_229 ( V_2 , V_21 , V_502 ) ;
V_38 = 0 ;
break;
case V_446 :
V_38 = 0x100000000ULL ;
break;
case V_516 :
V_38 = 0x500 | V_354 ;
break;
case 0x200 ... 0x2ff :
return F_222 ( V_2 , V_21 , V_502 ) ;
case 0xcd :
V_38 = 3 ;
break;
case V_517 :
V_38 = 1 << 24 ;
break;
case V_457 :
V_38 = F_20 ( V_2 ) ;
break;
case V_458 ... V_458 + 0x3ff :
return F_230 ( V_2 , V_21 , V_502 ) ;
break;
case V_459 :
V_38 = F_231 ( V_2 ) ;
break;
case V_460 :
V_38 = ( T_2 ) V_2 -> V_5 . V_291 ;
break;
case V_463 :
V_38 = V_2 -> V_5 . V_464 ;
break;
case V_518 :
V_38 = 1000ULL ;
V_38 |= ( ( ( T_9 ) 4ULL ) << 40 ) ;
break;
case V_451 :
V_38 = V_2 -> V_5 . V_131 ;
break;
case V_466 :
case V_465 :
V_38 = V_2 -> V_102 -> V_5 . V_237 ;
break;
case V_468 :
case V_467 :
V_38 = V_2 -> V_5 . time ;
break;
case V_472 :
V_38 = V_2 -> V_5 . V_6 . V_431 ;
break;
case V_473 :
V_38 = V_2 -> V_5 . V_435 . V_431 ;
break;
case V_477 :
V_38 = V_2 -> V_5 . V_519 . V_431 ;
break;
case V_504 :
case V_505 :
case V_506 :
case V_384 :
case V_382 :
case V_387 ... F_185 ( V_478 ) - 1 :
return F_223 ( V_2 , V_21 , V_502 ) ;
case V_491 :
V_38 = 0x20000000 ;
break;
case V_405 ... V_492 :
if ( F_192 ( V_21 ) ) {
int V_120 ;
F_218 ( & V_2 -> V_102 -> V_493 ) ;
V_120 = F_224 ( V_2 , V_21 , V_502 ) ;
F_219 ( & V_2 -> V_102 -> V_493 ) ;
return V_120 ;
} else
return F_226 ( V_2 , V_21 , V_502 ) ;
break;
case V_494 :
V_38 = 0xbe702111 ;
break;
case V_495 :
if ( ! F_220 ( V_2 ) )
return 1 ;
V_38 = V_2 -> V_5 . V_496 . V_497 ;
break;
case V_498 :
if ( ! F_220 ( V_2 ) )
return 1 ;
V_38 = V_2 -> V_5 . V_496 . V_499 ;
break;
default:
if ( F_216 ( V_2 , V_21 ) )
return F_229 ( V_2 , V_21 , V_502 ) ;
if ( ! V_500 ) {
F_198 ( V_2 , L_19 , V_21 ) ;
return 1 ;
} else {
F_198 ( V_2 , L_20 , V_21 ) ;
V_38 = 0 ;
}
break;
}
* V_502 = V_38 ;
return 0 ;
}
static int F_232 ( struct V_1 * V_2 , struct V_520 * V_19 ,
struct V_521 * V_522 ,
int (* F_233)( struct V_1 * V_2 ,
unsigned V_144 , T_2 * V_38 ) )
{
int V_3 , V_374 ;
V_374 = F_234 ( & V_2 -> V_102 -> V_523 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_524 ; ++ V_3 )
if ( F_233 ( V_2 , V_522 [ V_3 ] . V_144 , & V_522 [ V_3 ] . V_38 ) )
break;
F_235 ( & V_2 -> V_102 -> V_523 , V_374 ) ;
return V_3 ;
}
static int F_236 ( struct V_1 * V_2 , struct V_520 V_414 * V_525 ,
int (* F_233)( struct V_1 * V_2 ,
unsigned V_144 , T_2 * V_38 ) ,
int V_526 )
{
struct V_520 V_19 ;
struct V_521 * V_522 ;
int V_120 , V_527 ;
unsigned V_528 ;
V_120 = - V_101 ;
if ( F_237 ( & V_19 , V_525 , sizeof V_19 ) )
goto V_114;
V_120 = - V_400 ;
if ( V_19 . V_524 >= V_529 )
goto V_114;
V_528 = sizeof( struct V_521 ) * V_19 . V_524 ;
V_522 = F_187 ( V_525 -> V_522 , V_528 ) ;
if ( F_188 ( V_522 ) ) {
V_120 = F_189 ( V_522 ) ;
goto V_114;
}
V_120 = V_527 = F_232 ( V_2 , & V_19 , V_522 , F_233 ) ;
if ( V_120 < 0 )
goto V_402;
V_120 = - V_101 ;
if ( V_526 && F_238 ( V_525 -> V_522 , V_522 , V_528 ) )
goto V_402;
V_120 = V_527 ;
V_402:
F_190 ( V_522 ) ;
V_114:
return V_120 ;
}
int F_239 ( struct V_102 * V_102 , long V_530 )
{
int V_120 ;
switch ( V_530 ) {
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
case V_565 :
case V_566 :
#ifdef F_240
case V_567 :
case V_568 :
#endif
V_120 = 1 ;
break;
case V_569 :
V_120 = V_570 ;
break;
case V_571 :
V_120 = ! V_73 -> V_572 () ;
break;
case V_573 :
V_120 = V_574 ;
break;
case V_575 :
V_120 = V_576 ;
break;
case V_577 :
V_120 = V_578 ;
break;
case V_579 :
V_120 = 0 ;
break;
#ifdef F_240
case V_580 :
V_120 = F_241 ( & V_581 ) ;
break;
#endif
case V_582 :
V_120 = V_478 ;
break;
case V_583 :
V_120 = V_584 ;
break;
case V_585 :
V_120 = V_586 ;
break;
default:
V_120 = 0 ;
break;
}
return V_120 ;
}
long F_242 ( struct V_587 * V_588 ,
unsigned int V_589 , unsigned long V_590 )
{
void V_414 * V_591 = ( void V_414 * ) V_590 ;
long V_120 ;
switch ( V_589 ) {
case V_592 : {
struct V_593 V_414 * V_594 = V_591 ;
struct V_593 V_595 ;
unsigned V_527 ;
V_120 = - V_101 ;
if ( F_237 ( & V_595 , V_594 , sizeof V_595 ) )
goto V_114;
V_527 = V_595 . V_524 ;
V_595 . V_524 = V_596 + F_53 ( V_597 ) ;
if ( F_238 ( V_594 , & V_595 , sizeof V_595 ) )
goto V_114;
V_120 = - V_400 ;
if ( V_527 < V_595 . V_524 )
goto V_114;
V_120 = - V_101 ;
if ( F_238 ( V_594 -> V_598 , & V_599 ,
V_596 * sizeof( T_1 ) ) )
goto V_114;
if ( F_238 ( V_594 -> V_598 + V_596 ,
& V_597 ,
F_53 ( V_597 ) * sizeof( T_1 ) ) )
goto V_114;
V_120 = 0 ;
break;
}
case V_600 :
case V_601 : {
struct V_602 V_414 * V_603 = V_591 ;
struct V_602 V_604 ;
V_120 = - V_101 ;
if ( F_237 ( & V_604 , V_603 , sizeof V_604 ) )
goto V_114;
V_120 = F_243 ( & V_604 , V_603 -> V_522 ,
V_589 ) ;
if ( V_120 )
goto V_114;
V_120 = - V_101 ;
if ( F_238 ( V_603 , & V_604 , sizeof V_604 ) )
goto V_114;
V_120 = 0 ;
break;
}
case V_605 : {
T_2 V_606 ;
V_606 = V_607 ;
V_120 = - V_101 ;
if ( F_238 ( V_591 , & V_606 , sizeof V_606 ) )
goto V_114;
V_120 = 0 ;
break;
}
default:
V_120 = - V_608 ;
}
V_114:
return V_120 ;
}
static void F_244 ( void * V_609 )
{
F_245 () ;
}
static bool F_246 ( struct V_1 * V_2 )
{
return F_247 ( V_2 -> V_102 ) ;
}
void F_248 ( struct V_1 * V_2 , int V_23 )
{
if ( F_246 ( V_2 ) ) {
if ( V_73 -> V_610 () )
F_249 ( V_23 , V_2 -> V_5 . V_611 ) ;
else if ( V_2 -> V_23 != - 1 && V_2 -> V_23 != V_23 )
F_250 ( V_2 -> V_23 ,
F_244 , NULL , 1 ) ;
}
V_73 -> V_612 ( V_2 , V_23 ) ;
if ( F_152 ( V_2 -> V_5 . V_613 ) ) {
F_251 ( V_2 , V_2 -> V_5 . V_613 ) ;
V_2 -> V_5 . V_613 = 0 ;
F_31 ( V_324 , V_2 ) ;
}
if ( F_152 ( V_2 -> V_23 != V_23 ) || F_140 () ) {
T_12 V_614 = ! V_2 -> V_5 . V_615 ? 0 :
F_166 () - V_2 -> V_5 . V_615 ;
if ( V_614 < 0 )
F_252 ( L_21 ) ;
if ( F_140 () ) {
T_2 V_94 = V_73 -> V_299 ( V_2 ,
V_2 -> V_5 . V_311 ) ;
V_73 -> V_312 ( V_2 , V_94 ) ;
V_2 -> V_5 . V_335 = 1 ;
}
if ( ! V_2 -> V_102 -> V_5 . V_285 || V_2 -> V_23 == - 1 )
F_31 ( V_471 , V_2 ) ;
if ( V_2 -> V_23 != V_23 )
F_253 ( V_2 ) ;
V_2 -> V_23 = V_23 ;
}
F_207 ( V_2 ) ;
F_31 ( V_476 , V_2 ) ;
}
void F_254 ( struct V_1 * V_2 )
{
V_73 -> V_616 ( V_2 ) ;
F_255 ( V_2 ) ;
V_2 -> V_5 . V_615 = F_166 () ;
}
static int F_256 ( struct V_1 * V_2 ,
struct V_617 * V_618 )
{
V_73 -> V_619 ( V_2 ) ;
memcpy ( V_618 -> V_620 , V_2 -> V_5 . V_621 -> V_620 , sizeof *V_618 ) ;
return 0 ;
}
static int F_257 ( struct V_1 * V_2 ,
struct V_617 * V_618 )
{
F_258 ( V_2 , V_618 ) ;
F_259 ( V_2 ) ;
return 0 ;
}
static int F_260 ( struct V_1 * V_2 ,
struct V_622 * V_623 )
{
if ( V_623 -> V_623 >= V_624 )
return - V_608 ;
if ( F_86 ( V_2 -> V_102 ) )
return - V_625 ;
F_261 ( V_2 , V_623 -> V_623 , false ) ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
static int F_262 ( struct V_1 * V_2 )
{
F_41 ( V_2 ) ;
return 0 ;
}
static int F_263 ( struct V_1 * V_2 ,
struct V_626 * V_627 )
{
if ( V_627 -> V_294 )
return - V_608 ;
V_2 -> V_5 . V_628 = ! ! V_627 -> V_372 ;
return 0 ;
}
static int F_264 ( struct V_1 * V_2 ,
T_2 V_380 )
{
int V_120 ;
unsigned V_381 = V_380 & 0xff , V_629 ;
V_120 = - V_608 ;
if ( ! V_381 || V_381 >= V_478 )
goto V_114;
if ( V_380 & ~ ( V_607 | 0xff | 0xff0000 ) )
goto V_114;
V_120 = 0 ;
V_2 -> V_5 . V_380 = V_380 ;
if ( V_380 & V_385 )
V_2 -> V_5 . V_386 = ~ ( T_2 ) 0 ;
for ( V_629 = 0 ; V_629 < V_381 ; V_629 ++ )
V_2 -> V_5 . V_388 [ V_629 * 4 ] = ~ ( T_2 ) 0 ;
V_114:
return V_120 ;
}
static int F_265 ( struct V_1 * V_2 ,
struct V_630 * V_631 )
{
T_2 V_380 = V_2 -> V_5 . V_380 ;
unsigned V_381 = V_380 & 0xff ;
T_2 * V_632 = V_2 -> V_5 . V_388 ;
if ( V_631 -> V_629 >= V_381 || ! ( V_631 -> V_499 & V_633 ) )
return - V_608 ;
if ( ( V_631 -> V_499 & V_634 ) && ( V_380 & V_385 ) &&
V_2 -> V_5 . V_386 != ~ ( T_2 ) 0 )
return 0 ;
V_632 += 4 * V_631 -> V_629 ;
if ( ( V_631 -> V_499 & V_634 ) && V_632 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_631 -> V_499 & V_634 ) {
if ( ( V_2 -> V_5 . V_383 & V_635 ) ||
! F_46 ( V_2 , V_636 ) ) {
F_31 ( V_72 , V_2 ) ;
return 0 ;
}
if ( V_632 [ 1 ] & V_633 )
V_631 -> V_499 |= V_637 ;
V_632 [ 2 ] = V_631 -> V_410 ;
V_632 [ 3 ] = V_631 -> V_638 ;
V_2 -> V_5 . V_383 = V_631 -> V_383 ;
V_632 [ 1 ] = V_631 -> V_499 ;
F_33 ( V_2 , V_58 ) ;
} else if ( ! ( V_632 [ 1 ] & V_633 )
|| ! ( V_632 [ 1 ] & V_634 ) ) {
if ( V_632 [ 1 ] & V_633 )
V_631 -> V_499 |= V_637 ;
V_632 [ 2 ] = V_631 -> V_410 ;
V_632 [ 3 ] = V_631 -> V_638 ;
V_632 [ 1 ] = V_631 -> V_499 ;
} else
V_632 [ 1 ] |= V_637 ;
return 0 ;
}
static void F_266 ( struct V_1 * V_2 ,
struct V_639 * V_640 )
{
F_267 ( V_2 ) ;
V_640 -> V_68 . V_641 =
V_2 -> V_5 . V_68 . V_69 &&
! F_268 ( V_2 -> V_5 . V_68 . V_16 ) ;
V_640 -> V_68 . V_16 = V_2 -> V_5 . V_68 . V_16 ;
V_640 -> V_68 . V_71 = V_2 -> V_5 . V_68 . V_71 ;
V_640 -> V_68 . V_642 = 0 ;
V_640 -> V_68 . V_62 = V_2 -> V_5 . V_68 . V_62 ;
V_640 -> V_643 . V_641 =
V_2 -> V_5 . V_643 . V_69 && ! V_2 -> V_5 . V_643 . V_644 ;
V_640 -> V_643 . V_16 = V_2 -> V_5 . V_643 . V_16 ;
V_640 -> V_643 . V_644 = 0 ;
V_640 -> V_643 . V_645 = V_73 -> V_646 ( V_2 ) ;
V_640 -> V_647 . V_641 = V_2 -> V_5 . V_648 ;
V_640 -> V_647 . V_69 = V_2 -> V_5 . V_649 != 0 ;
V_640 -> V_647 . V_650 = V_73 -> V_651 ( V_2 ) ;
V_640 -> V_647 . V_642 = 0 ;
V_640 -> V_652 = 0 ;
V_640 -> V_294 = ( V_653
| V_654 ) ;
memset ( & V_640 -> V_655 , 0 , sizeof( V_640 -> V_655 ) ) ;
}
static int F_269 ( struct V_1 * V_2 ,
struct V_639 * V_640 )
{
if ( V_640 -> V_294 & ~ ( V_653
| V_656
| V_654 ) )
return - V_608 ;
F_267 ( V_2 ) ;
V_2 -> V_5 . V_68 . V_69 = V_640 -> V_68 . V_641 ;
V_2 -> V_5 . V_68 . V_16 = V_640 -> V_68 . V_16 ;
V_2 -> V_5 . V_68 . V_71 = V_640 -> V_68 . V_71 ;
V_2 -> V_5 . V_68 . V_62 = V_640 -> V_68 . V_62 ;
V_2 -> V_5 . V_643 . V_69 = V_640 -> V_643 . V_641 ;
V_2 -> V_5 . V_643 . V_16 = V_640 -> V_643 . V_16 ;
V_2 -> V_5 . V_643 . V_644 = V_640 -> V_643 . V_644 ;
if ( V_640 -> V_294 & V_654 )
V_73 -> V_657 ( V_2 ,
V_640 -> V_643 . V_645 ) ;
V_2 -> V_5 . V_648 = V_640 -> V_647 . V_641 ;
if ( V_640 -> V_294 & V_653 )
V_2 -> V_5 . V_649 = V_640 -> V_647 . V_69 ;
V_73 -> V_658 ( V_2 , V_640 -> V_647 . V_650 ) ;
if ( V_640 -> V_294 & V_656 &&
F_270 ( V_2 ) )
V_2 -> V_5 . V_621 -> V_652 = V_640 -> V_652 ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
static void F_271 ( struct V_1 * V_2 ,
struct V_659 * V_660 )
{
unsigned long V_192 ;
memcpy ( V_660 -> V_179 , V_2 -> V_5 . V_179 , sizeof( V_2 -> V_5 . V_179 ) ) ;
F_97 ( V_2 , 6 , & V_192 ) ;
V_660 -> V_183 = V_192 ;
V_660 -> V_184 = V_2 -> V_5 . V_184 ;
V_660 -> V_294 = 0 ;
memset ( & V_660 -> V_655 , 0 , sizeof( V_660 -> V_655 ) ) ;
}
static int F_272 ( struct V_1 * V_2 ,
struct V_659 * V_660 )
{
if ( V_660 -> V_294 )
return - V_608 ;
memcpy ( V_2 -> V_5 . V_179 , V_660 -> V_179 , sizeof( V_2 -> V_5 . V_179 ) ) ;
F_90 ( V_2 ) ;
V_2 -> V_5 . V_183 = V_660 -> V_183 ;
F_91 ( V_2 ) ;
V_2 -> V_5 . V_184 = V_660 -> V_184 ;
F_92 ( V_2 ) ;
return 0 ;
}
static void F_273 ( T_14 * V_661 , struct V_1 * V_2 )
{
struct V_662 * V_663 = & V_2 -> V_5 . V_664 . V_665 -> V_663 ;
T_2 V_666 = V_663 -> V_667 . V_666 ;
T_2 V_668 ;
memcpy ( V_661 , V_663 , V_669 ) ;
* ( T_2 * ) ( V_661 + V_669 ) = V_666 ;
V_668 = V_666 & ~ V_670 ;
while ( V_668 ) {
T_2 V_671 = V_668 & - V_668 ;
int V_144 = F_274 ( V_671 ) - 1 ;
void * V_672 = F_275 ( V_663 , V_671 ) ;
if ( V_672 ) {
T_1 V_528 , V_94 , V_197 , V_205 ;
F_276 ( V_673 , V_144 ,
& V_528 , & V_94 , & V_197 , & V_205 ) ;
memcpy ( V_661 + V_94 , V_672 , V_528 ) ;
}
V_668 -= V_671 ;
}
}
static void F_277 ( struct V_1 * V_2 , T_14 * V_672 )
{
struct V_662 * V_663 = & V_2 -> V_5 . V_664 . V_665 -> V_663 ;
T_2 V_666 = * ( T_2 * ) ( V_672 + V_669 ) ;
T_2 V_668 ;
memcpy ( V_663 , V_672 , V_669 ) ;
V_663 -> V_667 . V_666 = V_666 ;
if ( V_674 )
V_663 -> V_667 . V_675 = V_143 | V_676 ;
V_668 = V_666 & ~ V_670 ;
while ( V_668 ) {
T_2 V_671 = V_668 & - V_668 ;
int V_144 = F_274 ( V_671 ) - 1 ;
void * V_661 = F_275 ( V_663 , V_671 ) ;
if ( V_661 ) {
T_1 V_528 , V_94 , V_197 , V_205 ;
F_276 ( V_673 , V_144 ,
& V_528 , & V_94 , & V_197 , & V_205 ) ;
memcpy ( V_661 , V_672 + V_94 , V_528 ) ;
} else
F_278 ( 1 ) ;
V_668 -= V_671 ;
}
}
static void F_279 ( struct V_1 * V_2 ,
struct V_677 * V_678 )
{
if ( V_584 ) {
memset ( V_678 , 0 , sizeof( struct V_677 ) ) ;
F_273 ( ( T_14 * ) V_678 -> V_679 , V_2 ) ;
} else {
memcpy ( V_678 -> V_679 ,
& V_2 -> V_5 . V_664 . V_665 -> V_680 ,
sizeof( struct V_681 ) ) ;
* ( T_2 * ) & V_678 -> V_679 [ V_669 / sizeof( T_1 ) ] =
V_670 ;
}
}
static int F_280 ( struct V_1 * V_2 ,
struct V_677 * V_678 )
{
T_2 V_666 =
* ( T_2 * ) & V_678 -> V_679 [ V_669 / sizeof( T_1 ) ] ;
if ( V_584 ) {
if ( V_666 & ~ F_281 () )
return - V_608 ;
F_277 ( V_2 , ( T_14 * ) V_678 -> V_679 ) ;
} else {
if ( V_666 & ~ V_670 )
return - V_608 ;
memcpy ( & V_2 -> V_5 . V_664 . V_665 -> V_680 ,
V_678 -> V_679 , sizeof( struct V_681 ) ) ;
}
return 0 ;
}
static void F_282 ( struct V_1 * V_2 ,
struct V_682 * V_683 )
{
if ( ! V_584 ) {
V_683 -> V_684 = 0 ;
return;
}
V_683 -> V_684 = 1 ;
V_683 -> V_294 = 0 ;
V_683 -> V_685 [ 0 ] . V_145 = V_141 ;
V_683 -> V_685 [ 0 ] . V_22 = V_2 -> V_5 . V_142 ;
}
static int F_283 ( struct V_1 * V_2 ,
struct V_682 * V_683 )
{
int V_3 , V_120 = 0 ;
if ( ! V_584 )
return - V_608 ;
if ( V_683 -> V_684 > V_686 || V_683 -> V_294 )
return - V_608 ;
for ( V_3 = 0 ; V_3 < V_683 -> V_684 ; V_3 ++ )
if ( V_683 -> V_685 [ V_3 ] . V_145 == V_141 ) {
V_120 = F_72 ( V_2 , V_141 ,
V_683 -> V_685 [ V_3 ] . V_22 ) ;
break;
}
if ( V_120 )
V_120 = - V_608 ;
return V_120 ;
}
static int F_284 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_336 )
return - V_608 ;
V_2 -> V_5 . V_344 = true ;
F_31 ( V_324 , V_2 ) ;
return 0 ;
}
long F_285 ( struct V_587 * V_588 ,
unsigned int V_589 , unsigned long V_590 )
{
struct V_1 * V_2 = V_588 -> V_687 ;
void V_414 * V_591 = ( void V_414 * ) V_590 ;
int V_120 ;
union {
struct V_617 * V_688 ;
struct V_677 * V_663 ;
struct V_682 * V_685 ;
void * V_689 ;
} V_690 ;
V_690 . V_689 = NULL ;
switch ( V_589 ) {
case V_691 : {
V_120 = - V_608 ;
if ( ! V_2 -> V_5 . V_621 )
goto V_114;
V_690 . V_688 = F_286 ( sizeof( struct V_617 ) , V_692 ) ;
V_120 = - V_401 ;
if ( ! V_690 . V_688 )
goto V_114;
V_120 = F_256 ( V_2 , V_690 . V_688 ) ;
if ( V_120 )
goto V_114;
V_120 = - V_101 ;
if ( F_238 ( V_591 , V_690 . V_688 , sizeof( struct V_617 ) ) )
goto V_114;
V_120 = 0 ;
break;
}
case V_693 : {
V_120 = - V_608 ;
if ( ! V_2 -> V_5 . V_621 )
goto V_114;
V_690 . V_688 = F_187 ( V_591 , sizeof( * V_690 . V_688 ) ) ;
if ( F_188 ( V_690 . V_688 ) )
return F_189 ( V_690 . V_688 ) ;
V_120 = F_257 ( V_2 , V_690 . V_688 ) ;
break;
}
case V_694 : {
struct V_622 V_623 ;
V_120 = - V_101 ;
if ( F_237 ( & V_623 , V_591 , sizeof V_623 ) )
goto V_114;
V_120 = F_260 ( V_2 , & V_623 ) ;
break;
}
case V_695 : {
V_120 = F_262 ( V_2 ) ;
break;
}
case V_696 : {
struct V_697 V_414 * V_603 = V_591 ;
struct V_697 V_604 ;
V_120 = - V_101 ;
if ( F_237 ( & V_604 , V_603 , sizeof V_604 ) )
goto V_114;
V_120 = F_287 ( V_2 , & V_604 , V_603 -> V_522 ) ;
break;
}
case V_698 : {
struct V_602 V_414 * V_603 = V_591 ;
struct V_602 V_604 ;
V_120 = - V_101 ;
if ( F_237 ( & V_604 , V_603 , sizeof V_604 ) )
goto V_114;
V_120 = F_288 ( V_2 , & V_604 ,
V_603 -> V_522 ) ;
break;
}
case V_699 : {
struct V_602 V_414 * V_603 = V_591 ;
struct V_602 V_604 ;
V_120 = - V_101 ;
if ( F_237 ( & V_604 , V_603 , sizeof V_604 ) )
goto V_114;
V_120 = F_289 ( V_2 , & V_604 ,
V_603 -> V_522 ) ;
if ( V_120 )
goto V_114;
V_120 = - V_101 ;
if ( F_238 ( V_603 , & V_604 , sizeof V_604 ) )
goto V_114;
V_120 = 0 ;
break;
}
case V_700 :
V_120 = F_236 ( V_2 , V_591 , F_221 , 1 ) ;
break;
case V_701 :
V_120 = F_236 ( V_2 , V_591 , F_110 , 0 ) ;
break;
case V_702 : {
struct V_626 V_627 ;
V_120 = - V_101 ;
if ( F_237 ( & V_627 , V_591 , sizeof V_627 ) )
goto V_114;
V_120 = F_263 ( V_2 , & V_627 ) ;
if ( V_120 )
goto V_114;
V_120 = - V_101 ;
if ( F_238 ( V_591 , & V_627 , sizeof V_627 ) )
goto V_114;
V_120 = 0 ;
break;
} ;
case V_703 : {
struct V_704 V_705 ;
V_120 = - V_608 ;
if ( ! F_86 ( V_2 -> V_102 ) )
goto V_114;
V_120 = - V_101 ;
if ( F_237 ( & V_705 , V_591 , sizeof V_705 ) )
goto V_114;
V_120 = F_290 ( V_2 , V_705 . V_706 ) ;
break;
}
case V_707 : {
T_2 V_380 ;
V_120 = - V_101 ;
if ( F_237 ( & V_380 , V_591 , sizeof V_380 ) )
goto V_114;
V_120 = F_264 ( V_2 , V_380 ) ;
break;
}
case V_708 : {
struct V_630 V_631 ;
V_120 = - V_101 ;
if ( F_237 ( & V_631 , V_591 , sizeof V_631 ) )
goto V_114;
V_120 = F_265 ( V_2 , & V_631 ) ;
break;
}
case V_709 : {
struct V_639 V_640 ;
F_266 ( V_2 , & V_640 ) ;
V_120 = - V_101 ;
if ( F_238 ( V_591 , & V_640 , sizeof( struct V_639 ) ) )
break;
V_120 = 0 ;
break;
}
case V_710 : {
struct V_639 V_640 ;
V_120 = - V_101 ;
if ( F_237 ( & V_640 , V_591 , sizeof( struct V_639 ) ) )
break;
V_120 = F_269 ( V_2 , & V_640 ) ;
break;
}
case V_711 : {
struct V_659 V_660 ;
F_271 ( V_2 , & V_660 ) ;
V_120 = - V_101 ;
if ( F_238 ( V_591 , & V_660 ,
sizeof( struct V_659 ) ) )
break;
V_120 = 0 ;
break;
}
case V_712 : {
struct V_659 V_660 ;
V_120 = - V_101 ;
if ( F_237 ( & V_660 , V_591 ,
sizeof( struct V_659 ) ) )
break;
V_120 = F_272 ( V_2 , & V_660 ) ;
break;
}
case V_713 : {
V_690 . V_663 = F_286 ( sizeof( struct V_677 ) , V_692 ) ;
V_120 = - V_401 ;
if ( ! V_690 . V_663 )
break;
F_279 ( V_2 , V_690 . V_663 ) ;
V_120 = - V_101 ;
if ( F_238 ( V_591 , V_690 . V_663 , sizeof( struct V_677 ) ) )
break;
V_120 = 0 ;
break;
}
case V_714 : {
V_690 . V_663 = F_187 ( V_591 , sizeof( * V_690 . V_663 ) ) ;
if ( F_188 ( V_690 . V_663 ) )
return F_189 ( V_690 . V_663 ) ;
V_120 = F_280 ( V_2 , V_690 . V_663 ) ;
break;
}
case V_715 : {
V_690 . V_685 = F_286 ( sizeof( struct V_682 ) , V_692 ) ;
V_120 = - V_401 ;
if ( ! V_690 . V_685 )
break;
F_282 ( V_2 , V_690 . V_685 ) ;
V_120 = - V_101 ;
if ( F_238 ( V_591 , V_690 . V_685 ,
sizeof( struct V_682 ) ) )
break;
V_120 = 0 ;
break;
}
case V_716 : {
V_690 . V_685 = F_187 ( V_591 , sizeof( * V_690 . V_685 ) ) ;
if ( F_188 ( V_690 . V_685 ) )
return F_189 ( V_690 . V_685 ) ;
V_120 = F_283 ( V_2 , V_690 . V_685 ) ;
break;
}
case V_717 : {
T_1 V_718 ;
V_120 = - V_608 ;
V_718 = ( T_1 ) V_590 ;
if ( V_718 >= V_719 )
goto V_114;
if ( V_718 == 0 )
V_718 = V_272 ;
F_132 ( V_2 , V_718 ) ;
V_120 = 0 ;
goto V_114;
}
case V_720 : {
V_120 = V_2 -> V_5 . V_271 ;
goto V_114;
}
case V_721 : {
V_120 = F_284 ( V_2 ) ;
goto V_114;
}
default:
V_120 = - V_608 ;
}
V_114:
F_190 ( V_690 . V_689 ) ;
return V_120 ;
}
int F_291 ( struct V_1 * V_2 , struct V_722 * V_723 )
{
return V_724 ;
}
static int F_292 ( struct V_102 * V_102 , unsigned long V_410 )
{
int V_109 ;
if ( V_410 > ( unsigned int ) ( - 3 * V_108 ) )
return - V_608 ;
V_109 = V_73 -> V_725 ( V_102 , V_410 ) ;
return V_109 ;
}
static int F_293 ( struct V_102 * V_102 ,
T_2 V_726 )
{
V_102 -> V_5 . V_727 = V_726 ;
return 0 ;
}
static int F_294 ( struct V_102 * V_102 ,
T_1 V_728 )
{
if ( V_728 < V_729 )
return - V_608 ;
F_218 ( & V_102 -> V_730 ) ;
F_295 ( V_102 , V_728 ) ;
V_102 -> V_5 . V_731 = V_728 ;
F_219 ( & V_102 -> V_730 ) ;
return 0 ;
}
static int F_296 ( struct V_102 * V_102 )
{
return V_102 -> V_5 . V_732 ;
}
static int F_297 ( struct V_102 * V_102 , struct V_733 * V_734 )
{
int V_120 ;
V_120 = 0 ;
switch ( V_734 -> V_735 ) {
case V_736 :
memcpy ( & V_734 -> V_734 . V_737 ,
& F_298 ( V_102 ) -> V_738 [ 0 ] ,
sizeof( struct V_739 ) ) ;
break;
case V_740 :
memcpy ( & V_734 -> V_734 . V_737 ,
& F_298 ( V_102 ) -> V_738 [ 1 ] ,
sizeof( struct V_739 ) ) ;
break;
case V_741 :
V_120 = F_299 ( V_102 , & V_734 -> V_734 . V_742 ) ;
break;
default:
V_120 = - V_608 ;
break;
}
return V_120 ;
}
static int F_300 ( struct V_102 * V_102 , struct V_733 * V_734 )
{
int V_120 ;
V_120 = 0 ;
switch ( V_734 -> V_735 ) {
case V_736 :
F_143 ( & F_298 ( V_102 ) -> V_493 ) ;
memcpy ( & F_298 ( V_102 ) -> V_738 [ 0 ] ,
& V_734 -> V_734 . V_737 ,
sizeof( struct V_739 ) ) ;
F_144 ( & F_298 ( V_102 ) -> V_493 ) ;
break;
case V_740 :
F_143 ( & F_298 ( V_102 ) -> V_493 ) ;
memcpy ( & F_298 ( V_102 ) -> V_738 [ 1 ] ,
& V_734 -> V_734 . V_737 ,
sizeof( struct V_739 ) ) ;
F_144 ( & F_298 ( V_102 ) -> V_493 ) ;
break;
case V_741 :
V_120 = F_301 ( V_102 , & V_734 -> V_734 . V_742 ) ;
break;
default:
V_120 = - V_608 ;
break;
}
F_302 ( F_298 ( V_102 ) ) ;
return V_120 ;
}
static int F_303 ( struct V_102 * V_102 , struct V_743 * V_744 )
{
int V_120 = 0 ;
F_218 ( & V_102 -> V_5 . V_745 -> V_746 . V_493 ) ;
memcpy ( V_744 , & V_102 -> V_5 . V_745 -> V_746 , sizeof( struct V_743 ) ) ;
F_219 ( & V_102 -> V_5 . V_745 -> V_746 . V_493 ) ;
return V_120 ;
}
static int F_304 ( struct V_102 * V_102 , struct V_743 * V_744 )
{
int V_120 = 0 ;
F_218 ( & V_102 -> V_5 . V_745 -> V_746 . V_493 ) ;
memcpy ( & V_102 -> V_5 . V_745 -> V_746 , V_744 , sizeof( struct V_743 ) ) ;
F_305 ( V_102 , 0 , V_744 -> V_747 [ 0 ] . V_748 , 0 ) ;
F_219 ( & V_102 -> V_5 . V_745 -> V_746 . V_493 ) ;
return V_120 ;
}
static int F_306 ( struct V_102 * V_102 , struct V_749 * V_744 )
{
int V_120 = 0 ;
F_218 ( & V_102 -> V_5 . V_745 -> V_746 . V_493 ) ;
memcpy ( V_744 -> V_747 , & V_102 -> V_5 . V_745 -> V_746 . V_747 ,
sizeof( V_744 -> V_747 ) ) ;
V_744 -> V_294 = V_102 -> V_5 . V_745 -> V_746 . V_294 ;
F_219 ( & V_102 -> V_5 . V_745 -> V_746 . V_493 ) ;
memset ( & V_744 -> V_655 , 0 , sizeof( V_744 -> V_655 ) ) ;
return V_120 ;
}
static int F_307 ( struct V_102 * V_102 , struct V_749 * V_744 )
{
int V_120 = 0 , V_750 = 0 ;
T_1 V_751 , V_752 ;
F_218 ( & V_102 -> V_5 . V_745 -> V_746 . V_493 ) ;
V_751 = V_102 -> V_5 . V_745 -> V_746 . V_294 & V_753 ;
V_752 = V_744 -> V_294 & V_753 ;
if ( ! V_751 && V_752 )
V_750 = 1 ;
memcpy ( & V_102 -> V_5 . V_745 -> V_746 . V_747 , & V_744 -> V_747 ,
sizeof( V_102 -> V_5 . V_745 -> V_746 . V_747 ) ) ;
V_102 -> V_5 . V_745 -> V_746 . V_294 = V_744 -> V_294 ;
F_305 ( V_102 , 0 , V_102 -> V_5 . V_745 -> V_746 . V_747 [ 0 ] . V_748 , V_750 ) ;
F_219 ( & V_102 -> V_5 . V_745 -> V_746 . V_493 ) ;
return V_120 ;
}
static int F_308 ( struct V_102 * V_102 ,
struct V_754 * V_755 )
{
if ( ! V_102 -> V_5 . V_745 )
return - V_625 ;
F_218 ( & V_102 -> V_5 . V_745 -> V_746 . V_493 ) ;
V_102 -> V_5 . V_745 -> V_746 . V_63 = V_755 -> V_756 ;
F_219 ( & V_102 -> V_5 . V_745 -> V_746 . V_493 ) ;
return 0 ;
}
int F_309 ( struct V_102 * V_102 , struct V_757 * log )
{
bool V_758 = false ;
int V_120 ;
F_218 ( & V_102 -> V_730 ) ;
if ( V_73 -> V_759 )
V_73 -> V_759 ( V_102 ) ;
V_120 = F_310 ( V_102 , log , & V_758 ) ;
F_311 ( & V_102 -> V_730 ) ;
if ( V_758 )
F_312 ( V_102 ) ;
F_219 ( & V_102 -> V_730 ) ;
return V_120 ;
}
int F_313 ( struct V_102 * V_102 , struct V_760 * V_761 ,
bool V_762 )
{
if ( ! F_86 ( V_102 ) )
return - V_625 ;
V_761 -> V_499 = F_314 ( V_102 , V_763 ,
V_761 -> V_623 , V_761 -> V_764 ,
V_762 ) ;
return 0 ;
}
long F_315 ( struct V_587 * V_588 ,
unsigned int V_589 , unsigned long V_590 )
{
struct V_102 * V_102 = V_588 -> V_687 ;
void V_414 * V_591 = ( void V_414 * ) V_590 ;
int V_120 = - V_765 ;
union {
struct V_743 V_744 ;
struct V_749 V_766 ;
struct V_767 V_768 ;
} V_690 ;
switch ( V_589 ) {
case V_769 :
V_120 = F_292 ( V_102 , V_590 ) ;
break;
case V_770 : {
T_2 V_726 ;
V_120 = - V_101 ;
if ( F_237 ( & V_726 , V_591 , sizeof V_726 ) )
goto V_114;
V_120 = F_293 ( V_102 , V_726 ) ;
break;
}
case V_771 :
V_120 = F_294 ( V_102 , V_590 ) ;
break;
case V_772 :
V_120 = F_296 ( V_102 ) ;
break;
case V_773 : {
struct V_774 * V_775 ;
F_218 ( & V_102 -> V_493 ) ;
V_120 = - V_776 ;
if ( V_102 -> V_5 . V_775 )
goto V_777;
V_120 = - V_608 ;
if ( F_135 ( & V_102 -> V_284 ) )
goto V_777;
V_120 = - V_401 ;
V_775 = F_316 ( V_102 ) ;
if ( V_775 ) {
V_120 = F_317 ( V_102 ) ;
if ( V_120 ) {
F_218 ( & V_102 -> V_730 ) ;
F_318 ( V_102 , V_778 ,
& V_775 -> V_779 ) ;
F_318 ( V_102 , V_778 ,
& V_775 -> V_780 ) ;
F_318 ( V_102 , V_778 ,
& V_775 -> V_781 ) ;
F_219 ( & V_102 -> V_730 ) ;
F_190 ( V_775 ) ;
goto V_777;
}
} else
goto V_777;
F_14 () ;
V_102 -> V_5 . V_775 = V_775 ;
F_14 () ;
V_120 = F_319 ( V_102 ) ;
if ( V_120 ) {
F_218 ( & V_102 -> V_730 ) ;
F_218 ( & V_102 -> V_782 ) ;
F_320 ( V_102 ) ;
F_321 ( V_102 ) ;
F_219 ( & V_102 -> V_782 ) ;
F_219 ( & V_102 -> V_730 ) ;
}
V_777:
F_219 ( & V_102 -> V_493 ) ;
break;
}
case V_783 :
V_690 . V_768 . V_294 = V_784 ;
goto V_785;
case V_786 :
V_120 = - V_101 ;
if ( F_237 ( & V_690 . V_768 , V_591 ,
sizeof( struct V_767 ) ) )
goto V_114;
V_785:
F_218 ( & V_102 -> V_730 ) ;
V_120 = - V_776 ;
if ( V_102 -> V_5 . V_745 )
goto V_787;
V_120 = - V_401 ;
V_102 -> V_5 . V_745 = F_322 ( V_102 , V_690 . V_768 . V_294 ) ;
if ( V_102 -> V_5 . V_745 )
V_120 = 0 ;
V_787:
F_219 ( & V_102 -> V_730 ) ;
break;
case V_788 : {
struct V_733 * V_734 ;
V_734 = F_187 ( V_591 , sizeof( * V_734 ) ) ;
if ( F_188 ( V_734 ) ) {
V_120 = F_189 ( V_734 ) ;
goto V_114;
}
V_120 = - V_625 ;
if ( ! F_86 ( V_102 ) )
goto V_789;
V_120 = F_297 ( V_102 , V_734 ) ;
if ( V_120 )
goto V_789;
V_120 = - V_101 ;
if ( F_238 ( V_591 , V_734 , sizeof *V_734 ) )
goto V_789;
V_120 = 0 ;
V_789:
F_190 ( V_734 ) ;
break;
}
case V_790 : {
struct V_733 * V_734 ;
V_734 = F_187 ( V_591 , sizeof( * V_734 ) ) ;
if ( F_188 ( V_734 ) ) {
V_120 = F_189 ( V_734 ) ;
goto V_114;
}
V_120 = - V_625 ;
if ( ! F_86 ( V_102 ) )
goto V_791;
V_120 = F_300 ( V_102 , V_734 ) ;
if ( V_120 )
goto V_791;
V_120 = 0 ;
V_791:
F_190 ( V_734 ) ;
break;
}
case V_792 : {
V_120 = - V_101 ;
if ( F_237 ( & V_690 . V_744 , V_591 , sizeof( struct V_743 ) ) )
goto V_114;
V_120 = - V_625 ;
if ( ! V_102 -> V_5 . V_745 )
goto V_114;
V_120 = F_303 ( V_102 , & V_690 . V_744 ) ;
if ( V_120 )
goto V_114;
V_120 = - V_101 ;
if ( F_238 ( V_591 , & V_690 . V_744 , sizeof( struct V_743 ) ) )
goto V_114;
V_120 = 0 ;
break;
}
case V_793 : {
V_120 = - V_101 ;
if ( F_237 ( & V_690 . V_744 , V_591 , sizeof V_690 . V_744 ) )
goto V_114;
V_120 = - V_625 ;
if ( ! V_102 -> V_5 . V_745 )
goto V_114;
V_120 = F_304 ( V_102 , & V_690 . V_744 ) ;
break;
}
case V_794 : {
V_120 = - V_625 ;
if ( ! V_102 -> V_5 . V_745 )
goto V_114;
V_120 = F_306 ( V_102 , & V_690 . V_766 ) ;
if ( V_120 )
goto V_114;
V_120 = - V_101 ;
if ( F_238 ( V_591 , & V_690 . V_766 , sizeof( V_690 . V_766 ) ) )
goto V_114;
V_120 = 0 ;
break;
}
case V_795 : {
V_120 = - V_101 ;
if ( F_237 ( & V_690 . V_766 , V_591 , sizeof( V_690 . V_766 ) ) )
goto V_114;
V_120 = - V_625 ;
if ( ! V_102 -> V_5 . V_745 )
goto V_114;
V_120 = F_307 ( V_102 , & V_690 . V_766 ) ;
break;
}
case V_796 : {
struct V_754 V_755 ;
V_120 = - V_101 ;
if ( F_237 ( & V_755 , V_591 , sizeof( V_755 ) ) )
goto V_114;
V_120 = F_308 ( V_102 , & V_755 ) ;
break;
}
case V_797 : {
V_120 = - V_101 ;
if ( F_237 ( & V_102 -> V_5 . F_186 , V_591 ,
sizeof( struct V_798 ) ) )
goto V_114;
V_120 = - V_608 ;
if ( V_102 -> V_5 . F_186 . V_294 )
goto V_114;
V_120 = 0 ;
break;
}
case V_799 : {
struct V_800 V_801 ;
T_2 V_802 ;
T_12 V_306 ;
V_120 = - V_101 ;
if ( F_237 ( & V_801 , V_591 , sizeof( V_801 ) ) )
goto V_114;
V_120 = - V_608 ;
if ( V_801 . V_294 )
goto V_114;
V_120 = 0 ;
F_323 () ;
V_802 = F_126 () ;
V_306 = V_801 . clock - V_802 ;
F_324 () ;
V_102 -> V_5 . V_243 = V_306 ;
F_158 ( V_102 ) ;
break;
}
case V_803 : {
struct V_800 V_801 ;
T_2 V_802 ;
F_323 () ;
V_802 = F_126 () ;
V_801 . clock = V_102 -> V_5 . V_243 + V_802 ;
F_324 () ;
V_801 . V_294 = 0 ;
memset ( & V_801 . V_642 , 0 , sizeof( V_801 . V_642 ) ) ;
V_120 = - V_101 ;
if ( F_238 ( V_591 , & V_801 , sizeof( V_801 ) ) )
goto V_114;
V_120 = 0 ;
break;
}
default:
V_120 = F_325 ( V_102 , V_589 , V_590 ) ;
}
V_114:
return V_120 ;
}
static void F_326 ( void )
{
T_1 V_804 [ 2 ] ;
unsigned V_3 , V_805 ;
for ( V_3 = V_805 = V_806 ; V_3 < F_53 ( V_599 ) ; V_3 ++ ) {
if ( F_327 ( V_599 [ V_3 ] , & V_804 [ 0 ] , & V_804 [ 1 ] ) < 0 )
continue;
switch ( V_599 [ V_3 ] ) {
case V_807 :
if ( ! V_73 -> V_808 () )
continue;
break;
default:
break;
}
if ( V_805 < V_3 )
V_599 [ V_805 ] = V_599 [ V_3 ] ;
V_805 ++ ;
}
V_596 = V_805 ;
}
static int F_328 ( struct V_1 * V_2 , T_6 V_410 , int V_95 ,
const void * V_265 )
{
int V_809 = 0 ;
int V_527 ;
do {
V_527 = F_329 ( V_95 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_621 &&
! F_330 ( V_2 , & V_2 -> V_5 . V_621 -> V_810 , V_410 , V_527 , V_265 ) )
&& F_331 ( V_2 , V_811 , V_410 , V_527 , V_265 ) )
break;
V_809 += V_527 ;
V_410 += V_527 ;
V_95 -= V_527 ;
V_265 += V_527 ;
} while ( V_95 );
return V_809 ;
}
static int F_332 ( struct V_1 * V_2 , T_6 V_410 , int V_95 , void * V_265 )
{
int V_809 = 0 ;
int V_527 ;
do {
V_527 = F_329 ( V_95 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_621 &&
! F_333 ( V_2 , & V_2 -> V_5 . V_621 -> V_810 ,
V_410 , V_527 , V_265 ) )
&& F_334 ( V_2 , V_811 , V_410 , V_527 , V_265 ) )
break;
F_335 ( V_812 , V_527 , V_410 , * ( T_2 * ) V_265 ) ;
V_809 += V_527 ;
V_410 += V_527 ;
V_95 -= V_527 ;
V_265 += V_527 ;
} while ( V_95 );
return V_809 ;
}
static void F_336 ( struct V_1 * V_2 ,
struct V_813 * V_814 , int V_815 )
{
V_73 -> V_816 ( V_2 , V_814 , V_815 ) ;
}
void F_337 ( struct V_1 * V_2 ,
struct V_813 * V_814 , int V_815 )
{
V_73 -> V_817 ( V_2 , V_814 , V_815 ) ;
}
T_6 F_338 ( struct V_1 * V_2 , T_6 V_430 , T_1 V_96 ,
struct V_75 * V_68 )
{
T_6 V_818 ;
F_13 ( ! F_40 ( V_2 ) ) ;
V_96 |= V_112 ;
V_818 = V_2 -> V_5 . V_84 . V_819 ( V_2 , V_430 , V_96 , V_68 ) ;
return V_818 ;
}
T_6 F_339 ( struct V_1 * V_2 , T_16 V_820 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_112 : 0 ;
return V_2 -> V_5 . V_104 -> V_819 ( V_2 , V_820 , V_96 , V_68 ) ;
}
T_6 F_340 ( struct V_1 * V_2 , T_16 V_820 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_112 : 0 ;
V_96 |= V_821 ;
return V_2 -> V_5 . V_104 -> V_819 ( V_2 , V_820 , V_96 , V_68 ) ;
}
T_6 F_341 ( struct V_1 * V_2 , T_16 V_820 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_112 : 0 ;
V_96 |= V_113 ;
return V_2 -> V_5 . V_104 -> V_819 ( V_2 , V_820 , V_96 , V_68 ) ;
}
T_6 F_342 ( struct V_1 * V_2 , T_16 V_820 ,
struct V_75 * V_68 )
{
return V_2 -> V_5 . V_104 -> V_819 ( V_2 , V_820 , 0 , V_68 ) ;
}
static int F_343 ( T_16 V_410 , void * V_192 , unsigned int V_822 ,
struct V_1 * V_2 , T_1 V_96 ,
struct V_75 * V_68 )
{
void * V_38 = V_192 ;
int V_120 = V_823 ;
while ( V_822 ) {
T_6 V_430 = V_2 -> V_5 . V_104 -> V_819 ( V_2 , V_410 , V_96 ,
V_68 ) ;
unsigned V_94 = V_410 & ( V_108 - 1 ) ;
unsigned V_824 = F_329 ( V_822 , ( unsigned ) V_108 - V_94 ) ;
int V_109 ;
if ( V_430 == V_100 )
return V_825 ;
V_109 = F_50 ( V_2 -> V_102 , V_430 >> V_107 , V_38 ,
V_94 , V_824 ) ;
if ( V_109 < 0 ) {
V_120 = V_826 ;
goto V_114;
}
V_822 -= V_824 ;
V_38 += V_824 ;
V_410 += V_824 ;
}
V_114:
return V_120 ;
}
static int F_344 ( struct V_827 * V_828 ,
T_16 V_410 , void * V_192 , unsigned int V_822 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_345 ( V_828 ) ;
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_112 : 0 ;
unsigned V_94 ;
int V_109 ;
T_6 V_430 = V_2 -> V_5 . V_104 -> V_819 ( V_2 , V_410 , V_96 | V_821 ,
V_68 ) ;
if ( F_152 ( V_430 == V_100 ) )
return V_825 ;
V_94 = V_410 & ( V_108 - 1 ) ;
if ( F_29 ( V_94 + V_822 > V_108 ) )
V_822 = ( unsigned ) V_108 - V_94 ;
V_109 = F_50 ( V_2 -> V_102 , V_430 >> V_107 , V_192 ,
V_94 , V_822 ) ;
if ( F_152 ( V_109 < 0 ) )
return V_826 ;
return V_823 ;
}
int F_346 ( struct V_827 * V_828 ,
T_16 V_410 , void * V_192 , unsigned int V_822 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_345 ( V_828 ) ;
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_112 : 0 ;
return F_343 ( V_410 , V_192 , V_822 , V_2 , V_96 ,
V_68 ) ;
}
static int F_347 ( struct V_827 * V_828 ,
T_16 V_410 , void * V_192 , unsigned int V_822 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_345 ( V_828 ) ;
return F_343 ( V_410 , V_192 , V_822 , V_2 , 0 , V_68 ) ;
}
int F_348 ( struct V_827 * V_828 ,
T_16 V_410 , void * V_192 ,
unsigned int V_822 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_345 ( V_828 ) ;
void * V_38 = V_192 ;
int V_120 = V_823 ;
while ( V_822 ) {
T_6 V_430 = V_2 -> V_5 . V_104 -> V_819 ( V_2 , V_410 ,
V_113 ,
V_68 ) ;
unsigned V_94 = V_410 & ( V_108 - 1 ) ;
unsigned V_829 = F_329 ( V_822 , ( unsigned ) V_108 - V_94 ) ;
int V_109 ;
if ( V_430 == V_100 )
return V_825 ;
V_109 = F_119 ( V_2 -> V_102 , V_430 , V_38 , V_829 ) ;
if ( V_109 < 0 ) {
V_120 = V_826 ;
goto V_114;
}
V_822 -= V_829 ;
V_38 += V_829 ;
V_410 += V_829 ;
}
V_114:
return V_120 ;
}
static int F_349 ( struct V_1 * V_2 , unsigned long V_820 ,
T_6 * V_430 , struct V_75 * V_68 ,
bool V_830 )
{
T_1 V_96 = ( ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_112 : 0 )
| ( V_830 ? V_113 : 0 ) ;
if ( F_350 ( V_2 , V_820 )
&& ! F_351 ( V_2 , V_2 -> V_5 . V_104 ,
V_2 -> V_5 . V_96 , V_96 ) ) {
* V_430 = V_2 -> V_5 . V_831 << V_107 |
( V_820 & ( V_108 - 1 ) ) ;
F_352 ( V_820 , * V_430 , V_830 , false ) ;
return 1 ;
}
* V_430 = V_2 -> V_5 . V_104 -> V_819 ( V_2 , V_820 , V_96 , V_68 ) ;
if ( * V_430 == V_100 )
return - 1 ;
if ( ( * V_430 & V_397 ) == V_832 )
return 1 ;
if ( F_353 ( V_2 , * V_430 ) ) {
F_352 ( V_820 , * V_430 , V_830 , true ) ;
return 1 ;
}
return 0 ;
}
int F_354 ( struct V_1 * V_2 , T_6 V_430 ,
const void * V_192 , int V_822 )
{
int V_109 ;
V_109 = F_119 ( V_2 -> V_102 , V_430 , V_192 , V_822 ) ;
if ( V_109 < 0 )
return 0 ;
F_355 ( V_2 , V_430 , V_192 , V_822 ) ;
return 1 ;
}
static int F_356 ( struct V_1 * V_2 , void * V_192 , int V_822 )
{
if ( V_2 -> V_833 ) {
F_335 ( V_812 , V_822 ,
V_2 -> V_834 [ 0 ] . V_430 , * ( T_2 * ) V_192 ) ;
V_2 -> V_833 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_357 ( struct V_1 * V_2 , T_6 V_430 ,
void * V_192 , int V_822 )
{
return ! F_118 ( V_2 -> V_102 , V_430 , V_192 , V_822 ) ;
}
static int F_358 ( struct V_1 * V_2 , T_6 V_430 ,
void * V_192 , int V_822 )
{
return F_354 ( V_2 , V_430 , V_192 , V_822 ) ;
}
static int F_359 ( struct V_1 * V_2 , T_6 V_430 , int V_822 , void * V_192 )
{
F_335 ( V_835 , V_822 , V_430 , * ( T_2 * ) V_192 ) ;
return F_328 ( V_2 , V_430 , V_822 , V_192 ) ;
}
static int F_360 ( struct V_1 * V_2 , T_6 V_430 ,
void * V_192 , int V_822 )
{
F_335 ( V_836 , V_822 , V_430 , 0 ) ;
return V_826 ;
}
static int F_361 ( struct V_1 * V_2 , T_6 V_430 ,
void * V_192 , int V_822 )
{
struct V_837 * V_838 = & V_2 -> V_834 [ 0 ] ;
memcpy ( V_2 -> V_839 -> V_840 . V_38 , V_838 -> V_38 , F_329 ( 8u , V_838 -> V_95 ) ) ;
return V_823 ;
}
static int F_362 ( unsigned long V_410 , void * V_192 ,
unsigned int V_822 ,
struct V_75 * V_68 ,
struct V_1 * V_2 ,
const struct V_841 * V_842 )
{
T_6 V_430 ;
int V_809 , V_109 ;
bool V_830 = V_842 -> V_830 ;
struct V_837 * V_838 ;
V_109 = F_349 ( V_2 , V_410 , & V_430 , V_68 , V_830 ) ;
if ( V_109 < 0 )
return V_825 ;
if ( V_109 )
goto V_840;
if ( V_842 -> V_843 ( V_2 , V_430 , V_192 , V_822 ) )
return V_823 ;
V_840:
V_809 = V_842 -> V_844 ( V_2 , V_430 , V_822 , V_192 ) ;
if ( V_809 == V_822 )
return V_823 ;
V_430 += V_809 ;
V_822 -= V_809 ;
V_192 += V_809 ;
F_29 ( V_2 -> V_845 >= V_846 ) ;
V_838 = & V_2 -> V_834 [ V_2 -> V_845 ++ ] ;
V_838 -> V_430 = V_430 ;
V_838 -> V_38 = V_192 ;
V_838 -> V_95 = V_822 ;
return V_823 ;
}
static int F_363 ( struct V_827 * V_828 ,
unsigned long V_410 ,
void * V_192 , unsigned int V_822 ,
struct V_75 * V_68 ,
const struct V_841 * V_842 )
{
struct V_1 * V_2 = F_345 ( V_828 ) ;
T_6 V_430 ;
int V_847 ;
if ( V_842 -> V_848 &&
V_842 -> V_848 ( V_2 , V_192 , V_822 ) )
return V_823 ;
V_2 -> V_845 = 0 ;
if ( ( ( V_410 + V_822 - 1 ) ^ V_410 ) & V_397 ) {
int V_849 ;
V_849 = - V_410 & ~ V_397 ;
V_847 = F_362 ( V_410 , V_192 , V_849 , V_68 ,
V_2 , V_842 ) ;
if ( V_847 != V_823 )
return V_847 ;
V_410 += V_849 ;
if ( V_828 -> V_317 != V_850 )
V_410 = ( T_1 ) V_410 ;
V_192 += V_849 ;
V_822 -= V_849 ;
}
V_847 = F_362 ( V_410 , V_192 , V_822 , V_68 ,
V_2 , V_842 ) ;
if ( V_847 != V_823 )
return V_847 ;
if ( ! V_2 -> V_845 )
return V_847 ;
V_430 = V_2 -> V_834 [ 0 ] . V_430 ;
V_2 -> V_851 = 1 ;
V_2 -> V_852 = 0 ;
V_2 -> V_839 -> V_840 . V_95 = F_329 ( 8u , V_2 -> V_834 [ 0 ] . V_95 ) ;
V_2 -> V_839 -> V_840 . V_853 = V_2 -> V_854 = V_842 -> V_830 ;
V_2 -> V_839 -> V_855 = V_856 ;
V_2 -> V_839 -> V_840 . V_857 = V_430 ;
return V_842 -> V_858 ( V_2 , V_430 , V_192 , V_822 ) ;
}
static int F_364 ( struct V_827 * V_828 ,
unsigned long V_410 ,
void * V_192 ,
unsigned int V_822 ,
struct V_75 * V_68 )
{
return F_363 ( V_828 , V_410 , V_192 , V_822 ,
V_68 , & V_859 ) ;
}
static int F_365 ( struct V_827 * V_828 ,
unsigned long V_410 ,
const void * V_192 ,
unsigned int V_822 ,
struct V_75 * V_68 )
{
return F_363 ( V_828 , V_410 , ( void * ) V_192 , V_822 ,
V_68 , & V_860 ) ;
}
static int F_366 ( struct V_827 * V_828 ,
unsigned long V_410 ,
const void * V_861 ,
const void * V_862 ,
unsigned int V_822 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_345 ( V_828 ) ;
T_6 V_430 ;
struct V_399 * V_399 ;
char * V_863 ;
bool V_864 ;
if ( V_822 > 8 || ( V_822 & ( V_822 - 1 ) ) )
goto V_865;
V_430 = F_341 ( V_2 , V_410 , NULL ) ;
if ( V_430 == V_100 ||
( V_430 & V_397 ) == V_832 )
goto V_865;
if ( ( ( V_430 + V_822 - 1 ) & V_397 ) != ( V_430 & V_397 ) )
goto V_865;
V_399 = F_367 ( V_2 -> V_102 , V_430 >> V_107 ) ;
if ( F_368 ( V_399 ) )
goto V_865;
V_863 = F_369 ( V_399 ) ;
V_863 += F_370 ( V_430 ) ;
switch ( V_822 ) {
case 1 :
V_864 = F_371 ( T_14 , V_863 , V_861 , V_862 ) ;
break;
case 2 :
V_864 = F_371 ( V_866 , V_863 , V_861 , V_862 ) ;
break;
case 4 :
V_864 = F_371 ( T_1 , V_863 , V_861 , V_862 ) ;
break;
case 8 :
V_864 = F_372 ( V_863 , V_861 , V_862 ) ;
break;
default:
F_26 () ;
}
F_373 ( V_863 ) ;
F_374 ( V_399 ) ;
if ( ! V_864 )
return V_867 ;
F_197 ( V_2 -> V_102 , V_430 >> V_107 ) ;
F_355 ( V_2 , V_430 , V_862 , V_822 ) ;
return V_823 ;
V_865:
F_375 ( V_868 L_22 ) ;
return F_365 ( V_828 , V_410 , V_862 , V_822 , V_68 ) ;
}
static int F_376 ( struct V_1 * V_2 , void * V_869 )
{
int V_120 ;
if ( V_2 -> V_5 . V_870 . V_871 )
V_120 = F_334 ( V_2 , V_778 , V_2 -> V_5 . V_870 . V_872 ,
V_2 -> V_5 . V_870 . V_528 , V_869 ) ;
else
V_120 = F_331 ( V_2 , V_778 ,
V_2 -> V_5 . V_870 . V_872 , V_2 -> V_5 . V_870 . V_528 ,
V_869 ) ;
return V_120 ;
}
static int F_377 ( struct V_1 * V_2 , int V_528 ,
unsigned short V_872 , void * V_192 ,
unsigned int V_748 , bool V_871 )
{
V_2 -> V_5 . V_870 . V_872 = V_872 ;
V_2 -> V_5 . V_870 . V_871 = V_871 ;
V_2 -> V_5 . V_870 . V_748 = V_748 ;
V_2 -> V_5 . V_870 . V_528 = V_528 ;
if ( ! F_376 ( V_2 , V_2 -> V_5 . V_873 ) ) {
V_2 -> V_5 . V_870 . V_748 = 0 ;
return 1 ;
}
V_2 -> V_839 -> V_855 = V_874 ;
V_2 -> V_839 -> V_875 . V_876 = V_871 ? V_877 : V_878 ;
V_2 -> V_839 -> V_875 . V_528 = V_528 ;
V_2 -> V_839 -> V_875 . V_879 = V_880 * V_108 ;
V_2 -> V_839 -> V_875 . V_748 = V_748 ;
V_2 -> V_839 -> V_875 . V_872 = V_872 ;
return 0 ;
}
static int F_378 ( struct V_827 * V_828 ,
int V_528 , unsigned short V_872 , void * V_192 ,
unsigned int V_748 )
{
struct V_1 * V_2 = F_345 ( V_828 ) ;
int V_109 ;
if ( V_2 -> V_5 . V_870 . V_748 )
goto V_881;
V_109 = F_377 ( V_2 , V_528 , V_872 , V_192 , V_748 , true ) ;
if ( V_109 ) {
V_881:
memcpy ( V_192 , V_2 -> V_5 . V_873 , V_528 * V_748 ) ;
F_379 ( V_882 , V_872 , V_528 , V_748 , V_2 -> V_5 . V_873 ) ;
V_2 -> V_5 . V_870 . V_748 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_380 ( struct V_827 * V_828 ,
int V_528 , unsigned short V_872 ,
const void * V_192 , unsigned int V_748 )
{
struct V_1 * V_2 = F_345 ( V_828 ) ;
memcpy ( V_2 -> V_5 . V_873 , V_192 , V_528 * V_748 ) ;
F_379 ( V_883 , V_872 , V_528 , V_748 , V_2 -> V_5 . V_873 ) ;
return F_377 ( V_2 , V_528 , V_872 , ( void * ) V_192 , V_748 , false ) ;
}
static unsigned long F_381 ( struct V_1 * V_2 , int V_815 )
{
return V_73 -> F_381 ( V_2 , V_815 ) ;
}
static void F_382 ( struct V_827 * V_828 , V_172 V_80 )
{
F_383 ( F_345 ( V_828 ) , V_80 ) ;
}
int F_384 ( struct V_1 * V_2 )
{
if ( ! F_246 ( V_2 ) )
return V_823 ;
if ( V_73 -> V_610 () ) {
int V_23 = F_385 () ;
F_249 ( V_23 , V_2 -> V_5 . V_611 ) ;
F_386 ( V_2 -> V_5 . V_611 ,
F_244 , NULL , 1 ) ;
F_387 () ;
F_388 ( V_2 -> V_5 . V_611 ) ;
} else
F_245 () ;
return V_823 ;
}
int F_389 ( struct V_1 * V_2 )
{
V_73 -> V_74 ( V_2 ) ;
return F_384 ( V_2 ) ;
}
static void F_390 ( struct V_827 * V_828 )
{
F_384 ( F_345 ( V_828 ) ) ;
}
static int F_391 ( struct V_827 * V_828 , int V_89 ,
unsigned long * V_661 )
{
return F_97 ( F_345 ( V_828 ) , V_89 , V_661 ) ;
}
static int F_392 ( struct V_827 * V_828 , int V_89 ,
unsigned long V_22 )
{
return F_95 ( F_345 ( V_828 ) , V_89 , V_22 ) ;
}
static T_2 F_393 ( T_2 V_884 , T_1 V_885 )
{
return ( V_884 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_885 ;
}
static unsigned long F_394 ( struct V_827 * V_828 , int V_886 )
{
struct V_1 * V_2 = F_345 ( V_828 ) ;
unsigned long V_22 ;
switch ( V_886 ) {
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
V_22 = F_88 ( V_2 ) ;
break;
default:
F_395 ( L_23 , V_260 , V_886 ) ;
return 0 ;
}
return V_22 ;
}
static int F_396 ( struct V_827 * V_828 , int V_886 , V_172 V_192 )
{
struct V_1 * V_2 = F_345 ( V_828 ) ;
int V_887 = 0 ;
switch ( V_886 ) {
case 0 :
V_887 = F_61 ( V_2 , F_393 ( F_62 ( V_2 ) , V_192 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_79 = V_192 ;
break;
case 3 :
V_887 = F_82 ( V_2 , V_192 ) ;
break;
case 4 :
V_887 = F_75 ( V_2 , F_393 ( F_76 ( V_2 ) , V_192 ) ) ;
break;
case 8 :
V_887 = F_85 ( V_2 , V_192 ) ;
break;
default:
F_395 ( L_23 , V_260 , V_886 ) ;
V_887 = - 1 ;
}
return V_887 ;
}
static int F_397 ( struct V_827 * V_828 )
{
return V_73 -> V_88 ( F_345 ( V_828 ) ) ;
}
static void F_398 ( struct V_827 * V_828 , struct V_888 * V_889 )
{
V_73 -> V_890 ( F_345 ( V_828 ) , V_889 ) ;
}
static void F_399 ( struct V_827 * V_828 , struct V_888 * V_889 )
{
V_73 -> V_891 ( F_345 ( V_828 ) , V_889 ) ;
}
static void F_400 ( struct V_827 * V_828 , struct V_888 * V_889 )
{
V_73 -> V_892 ( F_345 ( V_828 ) , V_889 ) ;
}
static void F_401 ( struct V_827 * V_828 , struct V_888 * V_889 )
{
V_73 -> V_893 ( F_345 ( V_828 ) , V_889 ) ;
}
static unsigned long F_402 (
struct V_827 * V_828 , int V_815 )
{
return F_381 ( F_345 ( V_828 ) , V_815 ) ;
}
static bool F_403 ( struct V_827 * V_828 , V_866 * V_894 ,
struct V_895 * V_896 , T_1 * V_897 ,
int V_815 )
{
struct V_813 V_814 ;
F_337 ( F_345 ( V_828 ) , & V_814 , V_815 ) ;
* V_894 = V_814 . V_894 ;
if ( V_814 . V_898 ) {
memset ( V_896 , 0 , sizeof( * V_896 ) ) ;
return false ;
}
if ( V_814 . V_899 )
V_814 . V_900 >>= 12 ;
F_404 ( V_896 , V_814 . V_900 ) ;
F_405 ( V_896 , ( unsigned long ) V_814 . V_226 ) ;
#ifdef F_63
if ( V_897 )
* V_897 = V_814 . V_226 >> 32 ;
#endif
V_896 -> type = V_814 . type ;
V_896 -> V_618 = V_814 . V_618 ;
V_896 -> V_901 = V_814 . V_901 ;
V_896 -> V_368 = V_814 . V_902 ;
V_896 -> V_903 = V_814 . V_903 ;
V_896 -> V_904 = V_814 . V_904 ;
V_896 -> V_905 = V_814 . V_179 ;
V_896 -> V_899 = V_814 . V_899 ;
return true ;
}
static void F_406 ( struct V_827 * V_828 , V_866 V_894 ,
struct V_895 * V_896 , T_1 V_897 ,
int V_815 )
{
struct V_1 * V_2 = F_345 ( V_828 ) ;
struct V_813 V_814 ;
V_814 . V_894 = V_894 ;
V_814 . V_226 = F_407 ( V_896 ) ;
#ifdef F_63
V_814 . V_226 |= ( ( T_2 ) V_897 ) << 32 ;
#endif
V_814 . V_900 = F_408 ( V_896 ) ;
if ( V_896 -> V_899 )
V_814 . V_900 = ( V_814 . V_900 << 12 ) | 0xfff ;
V_814 . type = V_896 -> type ;
V_814 . V_901 = V_896 -> V_901 ;
V_814 . V_179 = V_896 -> V_905 ;
V_814 . V_618 = V_896 -> V_618 ;
V_814 . V_904 = V_896 -> V_904 ;
V_814 . V_899 = V_896 -> V_899 ;
V_814 . V_903 = V_896 -> V_903 ;
V_814 . V_902 = V_896 -> V_368 ;
V_814 . V_898 = ! V_814 . V_902 ;
V_814 . V_906 = 0 ;
F_336 ( V_2 , & V_814 , V_815 ) ;
return;
}
static int F_409 ( struct V_827 * V_828 ,
T_1 V_501 , T_2 * V_502 )
{
return F_221 ( F_345 ( V_828 ) , V_501 , V_502 ) ;
}
static int F_410 ( struct V_827 * V_828 ,
T_1 V_501 , T_2 V_38 )
{
struct V_32 V_21 ;
V_21 . V_38 = V_38 ;
V_21 . V_144 = V_501 ;
V_21 . V_40 = false ;
return F_107 ( F_345 ( V_828 ) , & V_21 ) ;
}
static int F_411 ( struct V_827 * V_828 ,
T_1 V_907 )
{
return F_412 ( F_345 ( V_828 ) , V_907 ) ;
}
static int F_413 ( struct V_827 * V_828 ,
T_1 V_907 , T_2 * V_502 )
{
return F_100 ( F_345 ( V_828 ) , V_907 , V_502 ) ;
}
static void F_414 ( struct V_827 * V_828 )
{
F_345 ( V_828 ) -> V_5 . V_908 = 1 ;
}
static void F_415 ( struct V_827 * V_828 )
{
F_214 () ;
F_416 ( F_345 ( V_828 ) ) ;
F_417 () ;
}
static void F_418 ( struct V_827 * V_828 )
{
F_215 () ;
}
static int F_419 ( struct V_827 * V_828 ,
struct V_909 * V_910 ,
enum V_911 V_912 )
{
return V_73 -> V_913 ( F_345 ( V_828 ) , V_910 , V_912 ) ;
}
static void F_420 ( struct V_827 * V_828 ,
T_1 * V_914 , T_1 * V_915 , T_1 * V_197 , T_1 * V_205 )
{
V_697 ( F_345 ( V_828 ) , V_914 , V_915 , V_197 , V_205 ) ;
}
static V_172 F_421 ( struct V_827 * V_828 , unsigned V_916 )
{
return F_99 ( F_345 ( V_828 ) , V_916 ) ;
}
static void F_422 ( struct V_827 * V_828 , unsigned V_916 , V_172 V_192 )
{
F_101 ( F_345 ( V_828 ) , V_916 , V_192 ) ;
}
static void F_423 ( struct V_827 * V_828 , bool V_650 )
{
V_73 -> V_658 ( F_345 ( V_828 ) , V_650 ) ;
}
static void F_424 ( struct V_1 * V_2 , T_1 V_28 )
{
T_1 V_917 = V_73 -> V_646 ( V_2 ) ;
if ( V_917 & V_28 )
V_28 = 0 ;
if ( F_152 ( V_917 || V_28 ) ) {
V_73 -> V_657 ( V_2 , V_28 ) ;
if ( ! V_28 )
F_31 ( V_67 , V_2 ) ;
}
}
static bool F_425 ( struct V_1 * V_2 )
{
struct V_827 * V_828 = & V_2 -> V_5 . V_918 ;
if ( V_828 -> V_68 . V_41 == V_42 )
return F_39 ( V_2 , & V_828 -> V_68 ) ;
if ( V_828 -> V_68 . V_919 )
F_38 ( V_2 , V_828 -> V_68 . V_41 ,
V_828 -> V_68 . V_62 ) ;
else
F_33 ( V_2 , V_828 -> V_68 . V_41 ) ;
return false ;
}
static void F_426 ( struct V_1 * V_2 )
{
struct V_827 * V_828 = & V_2 -> V_5 . V_918 ;
int V_133 , V_134 ;
V_73 -> V_135 ( V_2 , & V_133 , & V_134 ) ;
V_828 -> V_920 = F_427 ( V_2 ) ;
V_828 -> V_921 = F_428 ( V_2 ) ;
V_828 -> V_317 = ( ! F_32 ( V_2 ) ) ? V_922 :
( V_828 -> V_920 & V_923 ) ? V_924 :
( V_134 && F_57 ( V_2 ) ) ? V_850 :
V_133 ? V_925 :
V_926 ;
V_828 -> V_927 = F_429 ( V_2 ) ;
F_430 ( V_828 ) ;
V_2 -> V_5 . V_928 = false ;
}
int F_431 ( struct V_1 * V_2 , int V_623 , int V_929 )
{
struct V_827 * V_828 = & V_2 -> V_5 . V_918 ;
int V_109 ;
F_426 ( V_2 ) ;
V_828 -> V_930 = 2 ;
V_828 -> V_931 = 2 ;
V_828 -> V_932 = V_828 -> V_921 + V_929 ;
V_109 = F_432 ( V_828 , V_623 ) ;
if ( V_109 != V_823 )
return V_933 ;
V_828 -> V_921 = V_828 -> V_932 ;
F_433 ( V_2 , V_828 -> V_921 ) ;
F_434 ( V_2 , V_828 -> V_920 ) ;
if ( V_623 == V_51 )
V_2 -> V_5 . V_649 = 0 ;
else
V_2 -> V_5 . V_643 . V_69 = false ;
return V_934 ;
}
static int F_435 ( struct V_1 * V_2 )
{
int V_120 = V_934 ;
++ V_2 -> V_77 . V_935 ;
F_436 ( V_2 ) ;
if ( ! F_429 ( V_2 ) && V_73 -> V_88 ( V_2 ) == 0 ) {
V_2 -> V_839 -> V_855 = V_936 ;
V_2 -> V_839 -> V_937 . V_938 = V_939 ;
V_2 -> V_839 -> V_937 . V_940 = 0 ;
V_120 = V_933 ;
}
F_33 ( V_2 , V_91 ) ;
return V_120 ;
}
static bool F_437 ( struct V_1 * V_2 , T_16 V_79 ,
bool V_941 ,
int V_942 )
{
T_6 V_430 = V_79 ;
T_17 V_943 ;
if ( V_942 & V_944 )
return false ;
if ( ! V_2 -> V_5 . V_84 . V_945 ) {
V_430 = F_341 ( V_2 , V_79 , NULL ) ;
if ( V_430 == V_100 )
return true ;
}
V_943 = F_438 ( V_2 -> V_102 , F_49 ( V_430 ) ) ;
if ( F_439 ( V_943 ) )
return false ;
F_440 ( V_943 ) ;
if ( V_2 -> V_5 . V_84 . V_945 ) {
unsigned int V_946 ;
F_143 ( & V_2 -> V_102 -> V_947 ) ;
V_946 = V_2 -> V_102 -> V_5 . V_946 ;
F_144 ( & V_2 -> V_102 -> V_947 ) ;
if ( V_946 )
F_441 ( V_2 -> V_102 , F_49 ( V_430 ) ) ;
return true ;
}
F_441 ( V_2 -> V_102 , F_49 ( V_430 ) ) ;
return ! V_941 ;
}
static bool F_442 ( struct V_827 * V_828 ,
unsigned long V_79 , int V_942 )
{
struct V_1 * V_2 = F_345 ( V_828 ) ;
unsigned long V_948 , V_949 , V_430 = V_79 ;
V_948 = V_2 -> V_5 . V_948 ;
V_949 = V_2 -> V_5 . V_949 ;
V_2 -> V_5 . V_948 = V_2 -> V_5 . V_949 = 0 ;
if ( ! ( V_942 & V_950 ) )
return false ;
if ( F_443 ( V_828 ) )
return false ;
if ( V_828 -> V_921 == V_948 && V_949 == V_79 )
return false ;
V_2 -> V_5 . V_948 = V_828 -> V_921 ;
V_2 -> V_5 . V_949 = V_79 ;
if ( ! V_2 -> V_5 . V_84 . V_945 )
V_430 = F_341 ( V_2 , V_79 , NULL ) ;
F_441 ( V_2 -> V_102 , F_49 ( V_430 ) ) ;
return true ;
}
static int F_444 ( unsigned long V_410 , T_1 type , T_1 V_184 ,
unsigned long * V_179 )
{
T_1 V_183 = 0 ;
int V_3 ;
T_1 V_951 , V_952 ;
V_951 = V_184 ;
V_952 = V_184 >> 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ , V_951 >>= 2 , V_952 >>= 4 )
if ( ( V_951 & 3 ) && ( V_952 & 15 ) == type && V_179 [ V_3 ] == V_410 )
V_183 |= ( 1 << V_3 ) ;
return V_183 ;
}
static void F_445 ( struct V_1 * V_2 , unsigned long V_953 , int * V_120 )
{
struct V_954 * V_954 = V_2 -> V_839 ;
if ( F_152 ( V_953 & V_955 ) ) {
if ( V_2 -> V_175 & V_956 ) {
V_954 -> V_957 . V_5 . V_183 = V_958 | V_190 |
V_191 ;
V_954 -> V_957 . V_5 . V_959 = V_2 -> V_5 . V_960 ;
V_954 -> V_957 . V_5 . V_68 = V_53 ;
V_954 -> V_855 = V_961 ;
* V_120 = V_962 ;
} else {
V_2 -> V_5 . V_918 . V_920 &= ~ V_955 ;
V_2 -> V_5 . V_183 &= ~ 15 ;
V_2 -> V_5 . V_183 |= V_958 | V_191 ;
F_33 ( V_2 , V_53 ) ;
}
}
}
static bool F_446 ( struct V_1 * V_2 , int * V_120 )
{
if ( F_152 ( V_2 -> V_175 & V_176 ) &&
( V_2 -> V_5 . V_185 & V_188 ) ) {
struct V_954 * V_954 = V_2 -> V_839 ;
unsigned long V_921 = F_447 ( V_2 ) ;
T_1 V_183 = F_444 ( V_921 , 0 ,
V_2 -> V_5 . V_185 ,
V_2 -> V_5 . V_178 ) ;
if ( V_183 != 0 ) {
V_954 -> V_957 . V_5 . V_183 = V_183 | V_190 | V_191 ;
V_954 -> V_957 . V_5 . V_959 = V_921 ;
V_954 -> V_957 . V_5 . V_68 = V_53 ;
V_954 -> V_855 = V_961 ;
* V_120 = V_962 ;
return true ;
}
}
if ( F_152 ( V_2 -> V_5 . V_184 & V_188 ) &&
! ( F_427 ( V_2 ) & V_963 ) ) {
unsigned long V_921 = F_447 ( V_2 ) ;
T_1 V_183 = F_444 ( V_921 , 0 ,
V_2 -> V_5 . V_184 ,
V_2 -> V_5 . V_179 ) ;
if ( V_183 != 0 ) {
V_2 -> V_5 . V_183 &= ~ 15 ;
V_2 -> V_5 . V_183 |= V_183 | V_191 ;
F_33 ( V_2 , V_53 ) ;
* V_120 = V_934 ;
return true ;
}
}
return false ;
}
int F_448 ( struct V_1 * V_2 ,
unsigned long V_79 ,
int V_942 ,
void * V_964 ,
int V_965 )
{
int V_120 ;
struct V_827 * V_828 = & V_2 -> V_5 . V_918 ;
bool V_526 = true ;
bool V_966 = V_2 -> V_5 . V_941 ;
V_2 -> V_5 . V_941 = false ;
F_449 ( V_2 ) ;
if ( ! ( V_942 & V_967 ) ) {
F_426 ( V_2 ) ;
if ( F_446 ( V_2 , & V_120 ) )
return V_120 ;
V_828 -> V_968 = 0 ;
V_828 -> V_969 = false ;
V_828 -> V_68 . V_41 = - 1 ;
V_828 -> V_970 = false ;
V_828 -> V_971 = V_942 & V_972 ;
V_120 = F_450 ( V_828 , V_964 , V_965 ) ;
F_451 ( V_2 ) ;
++ V_2 -> V_77 . V_973 ;
if ( V_120 != V_974 ) {
if ( V_942 & V_972 )
return V_933 ;
if ( F_437 ( V_2 , V_79 , V_966 ,
V_942 ) )
return V_934 ;
if ( V_942 & V_975 )
return V_933 ;
return F_435 ( V_2 ) ;
}
}
if ( V_942 & V_975 ) {
F_433 ( V_2 , V_828 -> V_932 ) ;
if ( V_828 -> V_920 & V_963 )
F_434 ( V_2 , V_828 -> V_920 & ~ V_963 ) ;
return V_934 ;
}
if ( F_442 ( V_828 , V_79 , V_942 ) )
return V_934 ;
if ( V_2 -> V_5 . V_928 ) {
V_2 -> V_5 . V_928 = false ;
F_452 ( V_828 ) ;
}
V_976:
V_120 = F_453 ( V_828 ) ;
if ( V_120 == V_977 )
return V_934 ;
if ( V_120 == V_978 ) {
if ( F_437 ( V_2 , V_79 , V_966 ,
V_942 ) )
return V_934 ;
return F_435 ( V_2 ) ;
}
if ( V_828 -> V_969 ) {
V_120 = V_934 ;
if ( F_425 ( V_2 ) )
return V_120 ;
} else if ( V_2 -> V_5 . V_870 . V_748 ) {
if ( ! V_2 -> V_5 . V_870 . V_871 ) {
V_2 -> V_5 . V_870 . V_748 = 0 ;
} else {
V_526 = false ;
V_2 -> V_5 . V_979 = V_980 ;
}
V_120 = V_962 ;
} else if ( V_2 -> V_851 ) {
if ( ! V_2 -> V_854 )
V_526 = false ;
V_120 = V_962 ;
V_2 -> V_5 . V_979 = V_981 ;
} else if ( V_120 == V_982 )
goto V_976;
else
V_120 = V_934 ;
if ( V_526 ) {
unsigned long V_953 = V_73 -> V_983 ( V_2 ) ;
F_424 ( V_2 , V_828 -> V_968 ) ;
V_2 -> V_5 . V_984 = false ;
F_433 ( V_2 , V_828 -> V_921 ) ;
if ( V_120 == V_934 )
F_445 ( V_2 , V_953 , & V_120 ) ;
if ( ! V_828 -> V_969 ||
F_28 ( V_828 -> V_68 . V_41 ) == V_56 )
F_454 ( V_2 , V_828 -> V_920 ) ;
if ( F_152 ( ( V_828 -> V_920 & ~ V_953 ) & V_985 ) )
F_31 ( V_67 , V_2 ) ;
} else
V_2 -> V_5 . V_984 = true ;
return V_120 ;
}
int F_455 ( struct V_1 * V_2 , int V_528 , unsigned short V_872 )
{
unsigned long V_192 = F_99 ( V_2 , V_199 ) ;
int V_109 = F_380 ( & V_2 -> V_5 . V_918 ,
V_528 , V_872 , & V_192 , 1 ) ;
V_2 -> V_5 . V_870 . V_748 = 0 ;
return V_109 ;
}
static void F_456 ( void * V_910 )
{
F_457 ( V_333 , 0 ) ;
}
static void F_458 ( void * V_38 )
{
struct V_986 * V_987 = V_38 ;
unsigned long V_263 = 0 ;
if ( V_38 )
V_263 = V_987 -> V_862 ;
else if ( ! F_459 ( V_988 ) )
V_263 = F_460 ( F_461 () ) ;
if ( ! V_263 )
V_263 = V_272 ;
F_457 ( V_333 , V_263 ) ;
}
static int F_462 ( struct V_989 * V_990 , unsigned long V_192 ,
void * V_38 )
{
struct V_986 * V_987 = V_38 ;
struct V_102 * V_102 ;
struct V_1 * V_2 ;
int V_3 , V_991 = 0 ;
if ( V_192 == V_992 && V_987 -> V_861 > V_987 -> V_862 )
return 0 ;
if ( V_192 == V_993 && V_987 -> V_861 < V_987 -> V_862 )
return 0 ;
F_250 ( V_987 -> V_23 , F_458 , V_987 , 1 ) ;
F_143 ( & V_994 ) ;
F_463 (kvm, &vm_list, vm_list) {
F_160 (i, vcpu, kvm) {
if ( V_2 -> V_23 != V_987 -> V_23 )
continue;
F_31 ( V_324 , V_2 ) ;
if ( V_2 -> V_23 != F_8 () )
V_991 = 1 ;
}
}
F_144 ( & V_994 ) ;
if ( V_987 -> V_861 < V_987 -> V_862 && V_991 ) {
F_250 ( V_987 -> V_23 , F_458 , V_987 , 1 ) ;
}
return 0 ;
}
static int F_464 ( struct V_989 * V_995 ,
unsigned long V_996 , void * V_997 )
{
unsigned int V_23 = ( unsigned long ) V_997 ;
switch ( V_996 ) {
case V_998 :
case V_999 :
F_250 ( V_23 , F_458 , NULL , 1 ) ;
break;
case V_1000 :
F_250 ( V_23 , F_456 , NULL , 1 ) ;
break;
}
return V_1001 ;
}
static void F_465 ( void )
{
int V_23 ;
V_1002 = V_272 ;
F_466 () ;
if ( ! F_459 ( V_988 ) ) {
#ifdef F_467
struct V_1003 V_1004 ;
memset ( & V_1004 , 0 , sizeof( V_1004 ) ) ;
V_23 = F_385 () ;
F_468 ( & V_1004 , V_23 ) ;
if ( V_1004 . V_1005 . V_1006 )
V_1002 = V_1004 . V_1005 . V_1006 ;
F_387 () ;
#endif
F_469 ( & V_1007 ,
V_1008 ) ;
}
F_125 ( L_24 , V_1002 ) ;
F_470 (cpu)
F_250 ( V_23 , F_458 , NULL , 1 ) ;
F_471 ( & V_1009 ) ;
F_472 () ;
}
int F_473 ( void )
{
return F_164 ( V_1010 ) != NULL ;
}
static int F_474 ( void )
{
int V_1011 = 3 ;
if ( F_164 ( V_1010 ) )
V_1011 = V_73 -> V_88 ( F_164 ( V_1010 ) ) ;
return V_1011 != 0 ;
}
static unsigned long F_475 ( void )
{
unsigned long V_1012 = 0 ;
if ( F_164 ( V_1010 ) )
V_1012 = F_428 ( F_164 ( V_1010 ) ) ;
return V_1012 ;
}
void F_476 ( struct V_1 * V_2 )
{
F_457 ( V_1010 , V_2 ) ;
}
void F_477 ( struct V_1 * V_2 )
{
F_457 ( V_1010 , NULL ) ;
}
static void F_478 ( void )
{
T_2 V_28 ;
int V_1013 = V_1014 . V_1015 ;
V_28 = F_479 ( V_1013 , 51 ) ;
V_28 |= 0x3ull << 62 ;
V_28 |= 1ull ;
#ifdef F_63
if ( V_1013 == 52 )
V_28 &= ~ 1ull ;
#endif
F_480 ( V_28 ) ;
}
static void F_481 ( struct V_346 * V_347 )
{
struct V_102 * V_102 ;
struct V_1 * V_2 ;
int V_3 ;
F_143 ( & V_994 ) ;
F_463 (kvm, &vm_list, vm_list)
F_160 (i, vcpu, kvm)
F_31 ( V_287 , V_2 ) ;
F_156 ( & V_323 , 0 ) ;
F_144 ( & V_994 ) ;
}
static int F_482 ( struct V_989 * V_990 , unsigned long V_1016 ,
void * V_1017 )
{
struct V_222 * V_282 = & V_222 ;
struct V_220 * V_221 = V_1017 ;
F_111 ( V_221 ) ;
if ( V_282 -> clock . V_229 != V_286 &&
F_135 ( & V_323 ) != 0 )
F_483 ( V_1018 , & V_1019 ) ;
return 0 ;
}
int F_484 ( void * V_1020 )
{
int V_120 ;
struct V_73 * V_842 = V_1020 ;
if ( V_73 ) {
F_10 ( V_26 L_25 ) ;
V_120 = - V_776 ;
goto V_114;
}
if ( ! V_842 -> V_1021 () ) {
F_10 ( V_26 L_26 ) ;
V_120 = - V_1022 ;
goto V_114;
}
if ( V_842 -> V_1023 () ) {
F_10 ( V_26 L_27 ) ;
V_120 = - V_1022 ;
goto V_114;
}
V_120 = - V_401 ;
V_25 = F_485 ( struct V_11 ) ;
if ( ! V_25 ) {
F_10 ( V_26 L_28 ) ;
goto V_114;
}
V_120 = F_486 () ;
if ( V_120 )
goto V_1024;
F_478 () ;
V_73 = V_842 ;
F_487 ( V_1025 , V_1026 ,
V_1027 , V_1028 , 0 ) ;
F_465 () ;
F_488 ( & V_1029 ) ;
if ( V_584 )
V_143 = F_489 ( V_141 ) ;
F_490 () ;
#ifdef F_63
F_491 ( & V_1030 ) ;
#endif
return 0 ;
V_1024:
F_492 ( V_25 ) ;
V_114:
return V_120 ;
}
void F_493 ( void )
{
F_494 ( & V_1029 ) ;
if ( ! F_459 ( V_988 ) )
F_495 ( & V_1007 ,
V_1008 ) ;
F_496 ( & V_1009 ) ;
#ifdef F_63
F_497 ( & V_1030 ) ;
#endif
V_73 = NULL ;
F_498 () ;
F_492 ( V_25 ) ;
}
int F_499 ( struct V_1 * V_2 )
{
++ V_2 -> V_77 . V_1031 ;
if ( F_86 ( V_2 -> V_102 ) ) {
V_2 -> V_5 . V_1032 = V_1033 ;
return 1 ;
} else {
V_2 -> V_839 -> V_855 = V_1034 ;
return 0 ;
}
}
int F_500 ( struct V_1 * V_2 )
{
V_73 -> V_74 ( V_2 ) ;
return F_499 ( V_2 ) ;
}
int F_501 ( struct V_1 * V_2 )
{
T_2 V_1035 , V_1036 , V_1037 , V_109 ;
T_18 V_1038 , V_1039 , V_1040 , V_887 = V_1041 , V_1042 = 0 ;
bool V_1043 , V_1044 ;
if ( V_73 -> V_88 ( V_2 ) != 0 || ! F_32 ( V_2 ) ) {
F_33 ( V_2 , V_91 ) ;
return 0 ;
}
V_1044 = F_502 ( V_2 ) ;
if ( ! V_1044 ) {
V_1035 = ( ( T_2 ) F_99 ( V_2 , V_200 ) << 32 ) |
( F_99 ( V_2 , V_199 ) & 0xffffffff ) ;
V_1036 = ( ( T_2 ) F_99 ( V_2 , V_1045 ) << 32 ) |
( F_99 ( V_2 , V_198 ) & 0xffffffff ) ;
V_1037 = ( ( T_2 ) F_99 ( V_2 , V_1046 ) << 32 ) |
( F_99 ( V_2 , V_1047 ) & 0xffffffff ) ;
}
#ifdef F_63
else {
V_1035 = F_99 ( V_2 , V_198 ) ;
V_1036 = F_99 ( V_2 , V_200 ) ;
V_1037 = F_99 ( V_2 , V_1048 ) ;
}
#endif
V_1038 = V_1035 & 0xffff ;
V_1043 = ( V_1035 >> 16 ) & 0x1 ;
V_1040 = ( V_1035 >> 32 ) & 0xfff ;
V_1039 = ( V_1035 >> 48 ) & 0xfff ;
F_503 ( V_1038 , V_1043 , V_1040 , V_1039 , V_1036 , V_1037 ) ;
switch ( V_1038 ) {
case V_1049 :
F_504 ( V_2 ) ;
break;
default:
V_887 = V_1050 ;
break;
}
V_109 = V_887 | ( ( ( T_2 ) V_1042 & 0xfff ) << 32 ) ;
if ( V_1044 ) {
F_101 ( V_2 , V_199 , V_109 ) ;
} else {
F_101 ( V_2 , V_200 , V_109 >> 32 ) ;
F_101 ( V_2 , V_199 , V_109 & 0xffffffff ) ;
}
return 1 ;
}
static void F_505 ( struct V_102 * V_102 , unsigned long V_294 , int V_1051 )
{
struct V_1052 V_1053 ;
V_1053 . V_1054 = 0 ;
V_1053 . V_1055 = 0 ;
V_1053 . V_1056 = V_1051 ;
V_1053 . V_1057 = V_1058 ;
F_506 ( V_102 , NULL , & V_1053 , NULL ) ;
}
int F_507 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_1059 , V_1060 , V_1061 , V_1062 , V_109 ;
int V_1063 , V_120 = 1 ;
V_73 -> V_74 ( V_2 ) ;
if ( F_191 ( V_2 -> V_102 ) )
return F_501 ( V_2 ) ;
V_16 = F_99 ( V_2 , V_199 ) ;
V_1059 = F_99 ( V_2 , V_1045 ) ;
V_1060 = F_99 ( V_2 , V_198 ) ;
V_1061 = F_99 ( V_2 , V_200 ) ;
V_1062 = F_99 ( V_2 , V_1047 ) ;
F_508 ( V_16 , V_1059 , V_1060 , V_1061 , V_1062 ) ;
V_1063 = F_502 ( V_2 ) ;
if ( ! V_1063 ) {
V_16 &= 0xFFFFFFFF ;
V_1059 &= 0xFFFFFFFF ;
V_1060 &= 0xFFFFFFFF ;
V_1061 &= 0xFFFFFFFF ;
V_1062 &= 0xFFFFFFFF ;
}
if ( V_73 -> V_88 ( V_2 ) != 0 ) {
V_109 = - V_1064 ;
goto V_114;
}
switch ( V_16 ) {
case V_1065 :
V_109 = 0 ;
break;
case V_1066 :
F_505 ( V_2 -> V_102 , V_1059 , V_1060 ) ;
V_109 = 0 ;
break;
default:
V_109 = - V_1067 ;
break;
}
V_114:
if ( ! V_1063 )
V_109 = ( T_1 ) V_109 ;
F_101 ( V_2 , V_199 , V_109 ) ;
++ V_2 -> V_77 . V_1068 ;
return V_120 ;
}
static int F_509 ( struct V_827 * V_828 )
{
struct V_1 * V_2 = F_345 ( V_828 ) ;
char V_1069 [ 3 ] ;
unsigned long V_1070 = F_428 ( V_2 ) ;
V_73 -> V_413 ( V_2 , V_1069 ) ;
return F_365 ( V_828 , V_1070 , V_1069 , 3 , NULL ) ;
}
static int F_510 ( struct V_1 * V_2 )
{
return ( ! F_86 ( V_2 -> V_102 ) && ! F_511 ( V_2 ) &&
V_2 -> V_839 -> V_1071 &&
F_512 ( V_2 ) ) ;
}
static void F_513 ( struct V_1 * V_2 )
{
struct V_954 * V_954 = V_2 -> V_839 ;
V_954 -> V_1072 = ( F_427 ( V_2 ) & V_985 ) != 0 ;
V_954 -> V_173 = F_88 ( V_2 ) ;
V_954 -> V_31 = F_20 ( V_2 ) ;
if ( F_86 ( V_2 -> V_102 ) )
V_954 -> V_1073 = 1 ;
else
V_954 -> V_1073 =
F_512 ( V_2 ) &&
! F_511 ( V_2 ) &&
! F_514 ( V_2 ) ;
}
static void F_259 ( struct V_1 * V_2 )
{
int V_1074 , V_1075 ;
if ( ! V_73 -> F_259 )
return;
if ( ! V_2 -> V_5 . V_621 )
return;
if ( ! V_2 -> V_5 . V_621 -> V_706 )
V_1074 = F_515 ( V_2 ) ;
else
V_1074 = - 1 ;
if ( V_1074 != - 1 )
V_1074 >>= 4 ;
V_1075 = F_89 ( V_2 ) ;
V_73 -> F_259 ( V_2 , V_1075 , V_1074 ) ;
}
static int F_516 ( struct V_1 * V_2 , bool V_1076 )
{
int V_120 ;
if ( V_2 -> V_5 . V_68 . V_69 ) {
F_517 ( V_2 -> V_5 . V_68 . V_16 ,
V_2 -> V_5 . V_68 . V_71 ,
V_2 -> V_5 . V_68 . V_62 ) ;
if ( F_28 ( V_2 -> V_5 . V_68 . V_16 ) == V_60 )
F_454 ( V_2 , F_427 ( V_2 ) |
V_963 ) ;
if ( V_2 -> V_5 . V_68 . V_16 == V_53 &&
( V_2 -> V_5 . V_184 & V_1077 ) ) {
V_2 -> V_5 . V_184 &= ~ V_1077 ;
F_92 ( V_2 ) ;
}
V_73 -> V_1078 ( V_2 , V_2 -> V_5 . V_68 . V_16 ,
V_2 -> V_5 . V_68 . V_71 ,
V_2 -> V_5 . V_68 . V_62 ,
V_2 -> V_5 . V_68 . V_63 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_648 ) {
V_73 -> V_1079 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_643 . V_69 ) {
V_73 -> V_1080 ( V_2 ) ;
return 0 ;
}
if ( F_429 ( V_2 ) && V_73 -> V_1081 ) {
V_120 = V_73 -> V_1081 ( V_2 , V_1076 ) ;
if ( V_120 != 0 )
return V_120 ;
}
if ( V_2 -> V_5 . V_649 ) {
if ( V_73 -> V_1082 ( V_2 ) ) {
-- V_2 -> V_5 . V_649 ;
V_2 -> V_5 . V_648 = true ;
V_73 -> V_1079 ( V_2 ) ;
}
} else if ( F_518 ( V_2 ) ) {
if ( F_429 ( V_2 ) && V_73 -> V_1081 ) {
V_120 = V_73 -> V_1081 ( V_2 , V_1076 ) ;
if ( V_120 != 0 )
return V_120 ;
}
if ( V_73 -> V_1083 ( V_2 ) ) {
F_261 ( V_2 , F_519 ( V_2 ) ,
false ) ;
V_73 -> V_1080 ( V_2 ) ;
}
}
return 0 ;
}
static void F_267 ( struct V_1 * V_2 )
{
unsigned V_900 = 2 ;
if ( V_73 -> V_651 ( V_2 ) || V_2 -> V_5 . V_648 )
V_900 = 1 ;
V_2 -> V_5 . V_649 += F_520 ( & V_2 -> V_5 . V_85 , 0 ) ;
V_2 -> V_5 . V_649 = F_329 ( V_2 -> V_5 . V_649 , V_900 ) ;
F_31 ( V_67 , V_2 ) ;
}
static void F_521 ( struct V_1 * V_2 )
{
T_2 V_1084 [ 4 ] ;
T_1 V_1085 [ 8 ] ;
if ( ! F_522 ( V_2 -> V_5 . V_621 ) )
return;
memset ( V_1084 , 0 , 32 ) ;
memset ( V_1085 , 0 , 32 ) ;
F_523 ( V_2 , V_1084 , V_1085 ) ;
V_73 -> V_1086 ( V_2 , V_1084 ) ;
F_524 ( V_2 , V_1085 ) ;
}
static void F_525 ( struct V_1 * V_2 )
{
++ V_2 -> V_77 . V_1087 ;
V_73 -> V_1087 ( V_2 ) ;
}
void F_526 ( struct V_1 * V_2 )
{
struct V_399 * V_399 = NULL ;
if ( ! F_86 ( V_2 -> V_102 ) )
return;
if ( ! V_73 -> V_1088 )
return;
V_399 = F_367 ( V_2 -> V_102 , V_832 >> V_107 ) ;
if ( F_368 ( V_399 ) )
return;
V_73 -> V_1088 ( V_2 , F_527 ( V_399 ) ) ;
F_528 ( V_399 ) ;
}
void F_529 ( struct V_102 * V_102 ,
unsigned long V_80 )
{
if ( V_80 == F_194 ( V_102 , V_832 >> V_107 ) )
F_530 ( V_102 , V_1089 ) ;
}
static int F_531 ( struct V_1 * V_2 )
{
int V_120 ;
bool V_1076 = ! F_86 ( V_2 -> V_102 ) &&
V_2 -> V_839 -> V_1071 ;
bool V_1090 = false ;
if ( V_2 -> V_326 ) {
if ( F_532 ( V_1091 , V_2 ) )
F_533 ( V_2 ) ;
if ( F_532 ( V_1092 , V_2 ) )
F_534 ( V_2 ) ;
if ( F_532 ( V_287 , V_2 ) )
F_158 ( V_2 -> V_102 ) ;
if ( F_532 ( V_471 , V_2 ) )
F_176 ( V_2 ) ;
if ( F_532 ( V_324 , V_2 ) ) {
V_120 = F_162 ( V_2 ) ;
if ( F_152 ( V_120 ) )
goto V_114;
}
if ( F_532 ( V_1093 , V_2 ) )
F_83 ( V_2 ) ;
if ( F_532 ( V_169 , V_2 ) )
F_525 ( V_2 ) ;
if ( F_532 ( V_1094 , V_2 ) ) {
V_2 -> V_839 -> V_855 = V_1095 ;
V_120 = 0 ;
goto V_114;
}
if ( F_532 ( V_72 , V_2 ) ) {
V_2 -> V_839 -> V_855 = V_1096 ;
V_120 = 0 ;
goto V_114;
}
if ( F_532 ( V_1097 , V_2 ) ) {
V_2 -> V_1098 = 0 ;
V_73 -> V_1099 ( V_2 ) ;
}
if ( F_532 ( V_1100 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1101 = true ;
V_120 = 1 ;
goto V_114;
}
if ( F_532 ( V_476 , V_2 ) )
F_208 ( V_2 ) ;
if ( F_532 ( V_86 , V_2 ) )
F_267 ( V_2 ) ;
if ( F_532 ( V_1102 , V_2 ) )
F_535 ( V_2 ) ;
if ( F_532 ( V_1103 , V_2 ) )
F_536 ( V_2 ) ;
if ( F_532 ( V_1104 , V_2 ) )
F_521 ( V_2 ) ;
if ( F_532 ( V_1089 , V_2 ) )
F_526 ( V_2 ) ;
}
if ( F_532 ( V_67 , V_2 ) || V_1076 ) {
F_537 ( V_2 ) ;
if ( V_2 -> V_5 . V_1032 == V_1105 ) {
V_120 = 1 ;
goto V_114;
}
if ( F_516 ( V_2 , V_1076 ) != 0 )
V_1090 = true ;
else if ( V_2 -> V_5 . V_649 )
V_73 -> V_1106 ( V_2 ) ;
else if ( F_518 ( V_2 ) || V_1076 )
V_73 -> V_1107 ( V_2 ) ;
if ( F_538 ( V_2 ) ) {
if ( V_73 -> V_1108 )
V_73 -> V_1108 ( V_2 ,
F_515 ( V_2 ) ) ;
F_259 ( V_2 ) ;
F_539 ( V_2 ) ;
}
}
V_120 = F_540 ( V_2 ) ;
if ( F_152 ( V_120 ) ) {
goto V_1109;
}
F_214 () ;
V_73 -> V_1110 ( V_2 ) ;
if ( V_2 -> V_1098 )
F_416 ( V_2 ) ;
F_69 ( V_2 ) ;
V_2 -> V_317 = V_1111 ;
F_235 ( & V_2 -> V_102 -> V_523 , V_2 -> V_1112 ) ;
F_541 () ;
F_323 () ;
if ( V_2 -> V_317 == V_1113 || V_2 -> V_326
|| F_542 () || F_543 ( V_436 ) ) {
V_2 -> V_317 = V_1114 ;
F_14 () ;
F_324 () ;
F_215 () ;
V_2 -> V_1112 = F_234 ( & V_2 -> V_102 -> V_523 ) ;
V_120 = 1 ;
goto V_1109;
}
if ( V_1090 )
F_544 ( V_2 -> V_23 ) ;
F_545 () ;
if ( F_152 ( V_2 -> V_5 . V_180 ) ) {
F_546 ( 0 , 7 ) ;
F_546 ( V_2 -> V_5 . V_178 [ 0 ] , 0 ) ;
F_546 ( V_2 -> V_5 . V_178 [ 1 ] , 1 ) ;
F_546 ( V_2 -> V_5 . V_178 [ 2 ] , 2 ) ;
F_546 ( V_2 -> V_5 . V_178 [ 3 ] , 3 ) ;
F_546 ( V_2 -> V_5 . V_183 , 6 ) ;
V_2 -> V_5 . V_180 &= ~ V_181 ;
}
F_547 ( V_2 -> V_288 ) ;
F_548 ( V_2 ) ;
V_73 -> V_839 ( V_2 ) ;
if ( F_152 ( V_2 -> V_5 . V_180 & V_1115 ) ) {
int V_3 ;
F_29 ( V_2 -> V_175 & V_176 ) ;
V_73 -> V_1116 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_177 ; V_3 ++ )
V_2 -> V_5 . V_178 [ V_3 ] = V_2 -> V_5 . V_179 [ V_3 ] ;
}
if ( F_549 () )
F_550 () ;
V_2 -> V_5 . V_311 = V_73 -> V_334 ( V_2 ,
F_166 () ) ;
V_2 -> V_317 = V_1114 ;
F_14 () ;
V_73 -> V_1117 ( V_2 ) ;
++ V_2 -> V_77 . V_1118 ;
F_551 () ;
F_552 () ;
F_215 () ;
V_2 -> V_1112 = F_234 ( & V_2 -> V_102 -> V_523 ) ;
if ( F_152 ( V_1119 == V_1120 ) ) {
unsigned long V_1070 = F_428 ( V_2 ) ;
F_553 ( V_1120 , ( void * ) V_1070 ) ;
}
if ( F_152 ( V_2 -> V_5 . V_1121 ) )
F_31 ( V_324 , V_2 ) ;
if ( V_2 -> V_5 . V_1122 )
F_554 ( V_2 ) ;
V_120 = V_73 -> V_1123 ( V_2 ) ;
return V_120 ;
V_1109:
V_73 -> V_1109 ( V_2 ) ;
if ( F_152 ( V_2 -> V_5 . V_1122 ) )
F_554 ( V_2 ) ;
V_114:
return V_120 ;
}
static inline int F_555 ( struct V_102 * V_102 , struct V_1 * V_2 )
{
if ( ! F_556 ( V_2 ) ) {
F_235 ( & V_102 -> V_523 , V_2 -> V_1112 ) ;
F_557 ( V_2 ) ;
V_2 -> V_1112 = F_234 ( & V_102 -> V_523 ) ;
if ( ! F_532 ( V_1124 , V_2 ) )
return 1 ;
}
F_537 ( V_2 ) ;
switch( V_2 -> V_5 . V_1032 ) {
case V_1033 :
V_2 -> V_5 . V_1125 . V_1126 = false ;
V_2 -> V_5 . V_1032 =
V_1127 ;
case V_1127 :
V_2 -> V_5 . V_6 . V_1101 = false ;
break;
case V_1105 :
break;
default:
return - V_1128 ;
break;
}
return 1 ;
}
static int F_558 ( struct V_1 * V_2 )
{
int V_120 ;
struct V_102 * V_102 = V_2 -> V_102 ;
V_2 -> V_1112 = F_234 ( & V_102 -> V_523 ) ;
for (; ; ) {
if ( V_2 -> V_5 . V_1032 == V_1127 &&
! V_2 -> V_5 . V_6 . V_1101 )
V_120 = F_531 ( V_2 ) ;
else
V_120 = F_555 ( V_102 , V_2 ) ;
if ( V_120 <= 0 )
break;
F_161 ( V_236 , & V_2 -> V_326 ) ;
if ( F_559 ( V_2 ) )
F_560 ( V_2 ) ;
if ( F_510 ( V_2 ) ) {
V_120 = - V_1128 ;
V_2 -> V_839 -> V_855 = V_1129 ;
++ V_2 -> V_77 . V_1130 ;
break;
}
F_561 ( V_2 ) ;
if ( F_543 ( V_436 ) ) {
V_120 = - V_1128 ;
V_2 -> V_839 -> V_855 = V_1129 ;
++ V_2 -> V_77 . V_1131 ;
break;
}
if ( F_542 () ) {
F_235 ( & V_102 -> V_523 , V_2 -> V_1112 ) ;
F_562 () ;
V_2 -> V_1112 = F_234 ( & V_102 -> V_523 ) ;
}
}
F_235 ( & V_102 -> V_523 , V_2 -> V_1112 ) ;
return V_120 ;
}
static inline int F_563 ( struct V_1 * V_2 )
{
int V_120 ;
V_2 -> V_1112 = F_234 ( & V_2 -> V_102 -> V_523 ) ;
V_120 = F_564 ( V_2 , V_967 ) ;
F_235 ( & V_2 -> V_102 -> V_523 , V_2 -> V_1112 ) ;
if ( V_120 != V_934 )
return 0 ;
return 1 ;
}
static int V_980 ( struct V_1 * V_2 )
{
F_13 ( ! V_2 -> V_5 . V_870 . V_748 ) ;
return F_563 ( V_2 ) ;
}
static int V_981 ( struct V_1 * V_2 )
{
struct V_954 * V_839 = V_2 -> V_839 ;
struct V_837 * V_838 ;
unsigned V_95 ;
F_13 ( ! V_2 -> V_851 ) ;
V_838 = & V_2 -> V_834 [ V_2 -> V_852 ] ;
V_95 = F_329 ( 8u , V_838 -> V_95 ) ;
if ( ! V_2 -> V_854 )
memcpy ( V_838 -> V_38 , V_839 -> V_840 . V_38 , V_95 ) ;
if ( V_838 -> V_95 <= 8 ) {
V_838 ++ ;
V_2 -> V_852 ++ ;
} else {
V_838 -> V_38 += V_95 ;
V_838 -> V_430 += V_95 ;
V_838 -> V_95 -= V_95 ;
}
if ( V_2 -> V_852 >= V_2 -> V_845 ) {
V_2 -> V_851 = 0 ;
if ( V_2 -> V_854 )
return 1 ;
V_2 -> V_833 = 1 ;
return F_563 ( V_2 ) ;
}
V_839 -> V_855 = V_856 ;
V_839 -> V_840 . V_857 = V_838 -> V_430 ;
if ( V_2 -> V_854 )
memcpy ( V_839 -> V_840 . V_38 , V_838 -> V_38 , F_329 ( 8u , V_838 -> V_95 ) ) ;
V_839 -> V_840 . V_95 = F_329 ( 8u , V_838 -> V_95 ) ;
V_839 -> V_840 . V_853 = V_2 -> V_854 ;
V_2 -> V_5 . V_979 = V_981 ;
return 0 ;
}
int F_565 ( struct V_1 * V_2 , struct V_954 * V_954 )
{
int V_120 ;
T_19 V_1132 ;
if ( ! F_566 ( V_436 ) && F_567 ( V_436 ) )
return - V_401 ;
if ( V_2 -> V_1133 )
F_568 ( V_1134 , & V_2 -> V_1135 , & V_1132 ) ;
if ( F_152 ( V_2 -> V_5 . V_1032 == V_1136 ) ) {
F_557 ( V_2 ) ;
F_537 ( V_2 ) ;
F_161 ( V_1124 , & V_2 -> V_326 ) ;
V_120 = - V_1137 ;
goto V_114;
}
if ( ! F_86 ( V_2 -> V_102 ) ) {
if ( F_85 ( V_2 , V_954 -> V_173 ) != 0 ) {
V_120 = - V_608 ;
goto V_114;
}
}
if ( F_152 ( V_2 -> V_5 . V_979 ) ) {
int (* F_569)( struct V_1 * ) = V_2 -> V_5 . V_979 ;
V_2 -> V_5 . V_979 = NULL ;
V_120 = F_569 ( V_2 ) ;
if ( V_120 <= 0 )
goto V_114;
} else
F_29 ( V_2 -> V_5 . V_870 . V_748 || V_2 -> V_851 ) ;
V_120 = F_558 ( V_2 ) ;
V_114:
F_513 ( V_2 ) ;
if ( V_2 -> V_1133 )
F_568 ( V_1134 , & V_1132 , NULL ) ;
return V_120 ;
}
int F_570 ( struct V_1 * V_2 , struct V_1138 * V_620 )
{
if ( V_2 -> V_5 . V_984 ) {
F_571 ( & V_2 -> V_5 . V_918 ) ;
V_2 -> V_5 . V_984 = false ;
}
V_620 -> V_1139 = F_99 ( V_2 , V_199 ) ;
V_620 -> V_1140 = F_99 ( V_2 , V_1045 ) ;
V_620 -> V_1141 = F_99 ( V_2 , V_198 ) ;
V_620 -> V_1142 = F_99 ( V_2 , V_200 ) ;
V_620 -> V_1143 = F_99 ( V_2 , V_1047 ) ;
V_620 -> V_1144 = F_99 ( V_2 , V_1046 ) ;
V_620 -> V_1145 = F_99 ( V_2 , V_1146 ) ;
V_620 -> V_1147 = F_99 ( V_2 , V_1148 ) ;
#ifdef F_63
V_620 -> V_1149 = F_99 ( V_2 , V_1048 ) ;
V_620 -> V_1150 = F_99 ( V_2 , V_1151 ) ;
V_620 -> V_1152 = F_99 ( V_2 , V_1153 ) ;
V_620 -> V_1154 = F_99 ( V_2 , V_1155 ) ;
V_620 -> V_1156 = F_99 ( V_2 , V_1157 ) ;
V_620 -> V_1158 = F_99 ( V_2 , V_1159 ) ;
V_620 -> V_1160 = F_99 ( V_2 , V_1161 ) ;
V_620 -> V_1162 = F_99 ( V_2 , V_1163 ) ;
#endif
V_620 -> V_1070 = F_428 ( V_2 ) ;
V_620 -> V_953 = F_427 ( V_2 ) ;
return 0 ;
}
int F_572 ( struct V_1 * V_2 , struct V_1138 * V_620 )
{
V_2 -> V_5 . V_928 = true ;
V_2 -> V_5 . V_984 = false ;
F_101 ( V_2 , V_199 , V_620 -> V_1139 ) ;
F_101 ( V_2 , V_1045 , V_620 -> V_1140 ) ;
F_101 ( V_2 , V_198 , V_620 -> V_1141 ) ;
F_101 ( V_2 , V_200 , V_620 -> V_1142 ) ;
F_101 ( V_2 , V_1047 , V_620 -> V_1143 ) ;
F_101 ( V_2 , V_1046 , V_620 -> V_1144 ) ;
F_101 ( V_2 , V_1146 , V_620 -> V_1145 ) ;
F_101 ( V_2 , V_1148 , V_620 -> V_1147 ) ;
#ifdef F_63
F_101 ( V_2 , V_1048 , V_620 -> V_1149 ) ;
F_101 ( V_2 , V_1151 , V_620 -> V_1150 ) ;
F_101 ( V_2 , V_1153 , V_620 -> V_1152 ) ;
F_101 ( V_2 , V_1155 , V_620 -> V_1154 ) ;
F_101 ( V_2 , V_1157 , V_620 -> V_1156 ) ;
F_101 ( V_2 , V_1159 , V_620 -> V_1158 ) ;
F_101 ( V_2 , V_1161 , V_620 -> V_1160 ) ;
F_101 ( V_2 , V_1163 , V_620 -> V_1162 ) ;
#endif
F_433 ( V_2 , V_620 -> V_1070 ) ;
F_434 ( V_2 , V_620 -> V_953 ) ;
V_2 -> V_5 . V_68 . V_69 = false ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
void F_573 ( struct V_1 * V_2 , int * V_179 , int * V_904 )
{
struct V_813 V_1164 ;
F_337 ( V_2 , & V_1164 , V_1165 ) ;
* V_179 = V_1164 . V_179 ;
* V_904 = V_1164 . V_904 ;
}
int F_574 ( struct V_1 * V_2 ,
struct V_1166 * V_1167 )
{
struct V_888 V_889 ;
F_337 ( V_2 , & V_1167 -> V_1164 , V_1165 ) ;
F_337 ( V_2 , & V_1167 -> V_1168 , V_1169 ) ;
F_337 ( V_2 , & V_1167 -> V_1170 , V_1171 ) ;
F_337 ( V_2 , & V_1167 -> V_1172 , V_1173 ) ;
F_337 ( V_2 , & V_1167 -> V_1174 , V_1175 ) ;
F_337 ( V_2 , & V_1167 -> V_1176 , V_1177 ) ;
F_337 ( V_2 , & V_1167 -> V_1178 , V_1179 ) ;
F_337 ( V_2 , & V_1167 -> V_1180 , V_1181 ) ;
V_73 -> V_891 ( V_2 , & V_889 ) ;
V_1167 -> V_1182 . V_900 = V_889 . V_528 ;
V_1167 -> V_1182 . V_226 = V_889 . V_80 ;
V_73 -> V_890 ( V_2 , & V_889 ) ;
V_1167 -> V_1183 . V_900 = V_889 . V_528 ;
V_1167 -> V_1183 . V_226 = V_889 . V_80 ;
V_1167 -> V_121 = F_62 ( V_2 ) ;
V_1167 -> V_79 = V_2 -> V_5 . V_79 ;
V_1167 -> V_105 = F_60 ( V_2 ) ;
V_1167 -> V_156 = F_76 ( V_2 ) ;
V_1167 -> V_173 = F_88 ( V_2 ) ;
V_1167 -> V_131 = V_2 -> V_5 . V_131 ;
V_1167 -> V_31 = F_20 ( V_2 ) ;
memset ( V_1167 -> V_1184 , 0 , sizeof V_1167 -> V_1184 ) ;
if ( V_2 -> V_5 . V_643 . V_69 && ! V_2 -> V_5 . V_643 . V_644 )
F_212 ( V_2 -> V_5 . V_643 . V_16 ,
( unsigned long * ) V_1167 -> V_1184 ) ;
return 0 ;
}
int F_575 ( struct V_1 * V_2 ,
struct V_1185 * V_1032 )
{
F_537 ( V_2 ) ;
if ( V_2 -> V_5 . V_1032 == V_1033 &&
V_2 -> V_5 . V_1125 . V_1126 )
V_1032 -> V_1032 = V_1127 ;
else
V_1032 -> V_1032 = V_2 -> V_5 . V_1032 ;
return 0 ;
}
int F_576 ( struct V_1 * V_2 ,
struct V_1185 * V_1032 )
{
if ( ! F_270 ( V_2 ) &&
V_1032 -> V_1032 != V_1127 )
return - V_608 ;
if ( V_1032 -> V_1032 == V_1186 ) {
V_2 -> V_5 . V_1032 = V_1105 ;
F_212 ( V_1187 , & V_2 -> V_5 . V_621 -> V_1188 ) ;
} else
V_2 -> V_5 . V_1032 = V_1032 -> V_1032 ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
int F_577 ( struct V_1 * V_2 , V_866 V_1189 , int V_1190 ,
int V_1191 , bool V_71 , T_1 V_62 )
{
struct V_827 * V_828 = & V_2 -> V_5 . V_918 ;
int V_109 ;
F_426 ( V_2 ) ;
V_109 = F_578 ( V_828 , V_1189 , V_1190 , V_1191 ,
V_71 , V_62 ) ;
if ( V_109 )
return V_933 ;
F_433 ( V_2 , V_828 -> V_921 ) ;
F_434 ( V_2 , V_828 -> V_920 ) ;
F_31 ( V_67 , V_2 ) ;
return V_934 ;
}
int F_579 ( struct V_1 * V_2 ,
struct V_1166 * V_1167 )
{
struct V_32 V_1192 ;
int V_1193 = 0 ;
int V_1194 , V_1195 , V_374 ;
struct V_888 V_889 ;
if ( ! F_77 ( V_2 ) && ( V_1167 -> V_156 & V_139 ) )
return - V_608 ;
V_889 . V_528 = V_1167 -> V_1182 . V_900 ;
V_889 . V_80 = V_1167 -> V_1182 . V_226 ;
V_73 -> V_893 ( V_2 , & V_889 ) ;
V_889 . V_528 = V_1167 -> V_1183 . V_900 ;
V_889 . V_80 = V_1167 -> V_1183 . V_226 ;
V_73 -> V_892 ( V_2 , & V_889 ) ;
V_2 -> V_5 . V_79 = V_1167 -> V_79 ;
V_1193 |= F_60 ( V_2 ) != V_1167 -> V_105 ;
V_2 -> V_5 . V_105 = V_1167 -> V_105 ;
F_55 ( V_171 , ( V_172 * ) & V_2 -> V_5 . V_117 ) ;
F_85 ( V_2 , V_1167 -> V_173 ) ;
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
V_374 = F_234 ( & V_2 -> V_102 -> V_523 ) ;
if ( ! F_57 ( V_2 ) && F_58 ( V_2 ) ) {
F_52 ( V_2 , V_2 -> V_5 . V_104 , F_60 ( V_2 ) ) ;
V_1193 = 1 ;
}
F_235 ( & V_2 -> V_102 -> V_523 , V_374 ) ;
if ( V_1193 )
F_66 ( V_2 ) ;
V_1195 = V_624 ;
V_1194 = F_580 (
( const unsigned long * ) V_1167 -> V_1184 , V_1195 ) ;
if ( V_1194 < V_1195 ) {
F_261 ( V_2 , V_1194 , false ) ;
F_125 ( L_29 , V_1194 ) ;
}
F_336 ( V_2 , & V_1167 -> V_1164 , V_1165 ) ;
F_336 ( V_2 , & V_1167 -> V_1168 , V_1169 ) ;
F_336 ( V_2 , & V_1167 -> V_1170 , V_1171 ) ;
F_336 ( V_2 , & V_1167 -> V_1172 , V_1173 ) ;
F_336 ( V_2 , & V_1167 -> V_1174 , V_1175 ) ;
F_336 ( V_2 , & V_1167 -> V_1176 , V_1177 ) ;
F_336 ( V_2 , & V_1167 -> V_1178 , V_1179 ) ;
F_336 ( V_2 , & V_1167 -> V_1180 , V_1181 ) ;
F_259 ( V_2 ) ;
if ( F_581 ( V_2 ) && F_428 ( V_2 ) == 0xfff0 &&
V_1167 -> V_1164 . V_894 == 0xf000 && V_1167 -> V_1164 . V_226 == 0xffff0000 &&
! F_32 ( V_2 ) )
V_2 -> V_5 . V_1032 = V_1127 ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
int F_582 ( struct V_1 * V_2 ,
struct V_1196 * V_1197 )
{
unsigned long V_953 ;
int V_3 , V_120 ;
if ( V_1197 -> V_755 & ( V_1198 | V_1199 ) ) {
V_120 = - V_1200 ;
if ( V_2 -> V_5 . V_68 . V_69 )
goto V_114;
if ( V_1197 -> V_755 & V_1198 )
F_33 ( V_2 , V_53 ) ;
else
F_33 ( V_2 , V_54 ) ;
}
V_953 = F_427 ( V_2 ) ;
V_2 -> V_175 = V_1197 -> V_755 ;
if ( ! ( V_2 -> V_175 & V_1201 ) )
V_2 -> V_175 = 0 ;
if ( V_2 -> V_175 & V_176 ) {
for ( V_3 = 0 ; V_3 < V_177 ; ++ V_3 )
V_2 -> V_5 . V_178 [ V_3 ] = V_1197 -> V_5 . V_1202 [ V_3 ] ;
V_2 -> V_5 . V_185 = V_1197 -> V_5 . V_1202 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_177 ; V_3 ++ )
V_2 -> V_5 . V_178 [ V_3 ] = V_2 -> V_5 . V_179 [ V_3 ] ;
}
F_92 ( V_2 ) ;
if ( V_2 -> V_175 & V_956 )
V_2 -> V_5 . V_960 = F_428 ( V_2 ) +
F_381 ( V_2 , V_1165 ) ;
F_434 ( V_2 , V_953 ) ;
V_73 -> V_1203 ( V_2 ) ;
V_120 = 0 ;
V_114:
return V_120 ;
}
int F_583 ( struct V_1 * V_2 ,
struct V_1204 * V_1178 )
{
unsigned long V_1205 = V_1178 -> V_1206 ;
T_6 V_430 ;
int V_374 ;
V_374 = F_234 ( & V_2 -> V_102 -> V_523 ) ;
V_430 = F_342 ( V_2 , V_1205 , NULL ) ;
F_235 ( & V_2 -> V_102 -> V_523 , V_374 ) ;
V_1178 -> V_1207 = V_430 ;
V_1178 -> V_668 = V_430 != V_100 ;
V_1178 -> V_1208 = 1 ;
V_1178 -> V_1209 = 0 ;
return 0 ;
}
int F_584 ( struct V_1 * V_2 , struct V_1210 * V_1211 )
{
struct V_681 * V_680 =
& V_2 -> V_5 . V_664 . V_665 -> V_680 ;
memcpy ( V_1211 -> V_1212 , V_680 -> V_1213 , 128 ) ;
V_1211 -> V_1214 = V_680 -> V_1215 ;
V_1211 -> V_1216 = V_680 -> V_1217 ;
V_1211 -> V_1218 = V_680 -> V_1219 ;
V_1211 -> V_1220 = V_680 -> V_1221 ;
V_1211 -> V_1222 = V_680 -> V_1070 ;
V_1211 -> V_1223 = V_680 -> V_1224 ;
memcpy ( V_1211 -> V_1225 , V_680 -> V_1226 , sizeof V_680 -> V_1226 ) ;
return 0 ;
}
int F_585 ( struct V_1 * V_2 , struct V_1210 * V_1211 )
{
struct V_681 * V_680 =
& V_2 -> V_5 . V_664 . V_665 -> V_680 ;
memcpy ( V_680 -> V_1213 , V_1211 -> V_1212 , 128 ) ;
V_680 -> V_1215 = V_1211 -> V_1214 ;
V_680 -> V_1217 = V_1211 -> V_1216 ;
V_680 -> V_1219 = V_1211 -> V_1218 ;
V_680 -> V_1221 = V_1211 -> V_1220 ;
V_680 -> V_1070 = V_1211 -> V_1222 ;
V_680 -> V_1224 = V_1211 -> V_1223 ;
memcpy ( V_680 -> V_1226 , V_1211 -> V_1225 , sizeof V_680 -> V_1226 ) ;
return 0 ;
}
int F_586 ( struct V_1 * V_2 )
{
int V_29 ;
V_29 = F_587 ( & V_2 -> V_5 . V_664 ) ;
if ( V_29 )
return V_29 ;
F_588 ( & V_2 -> V_5 . V_664 ) ;
if ( V_674 )
V_2 -> V_5 . V_664 . V_665 -> V_663 . V_667 . V_675 =
V_143 | V_676 ;
V_2 -> V_5 . V_142 = V_148 ;
V_2 -> V_5 . V_121 |= V_128 ;
return 0 ;
}
static void F_589 ( struct V_1 * V_2 )
{
F_590 ( & V_2 -> V_5 . V_664 ) ;
}
void F_416 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1227 )
return;
F_71 ( V_2 ) ;
V_2 -> V_1227 = 1 ;
F_591 () ;
F_592 ( & V_2 -> V_5 . V_664 ) ;
F_593 ( 1 ) ;
}
void F_255 ( struct V_1 * V_2 )
{
F_71 ( V_2 ) ;
if ( ! V_2 -> V_1227 )
return;
V_2 -> V_1227 = 0 ;
F_594 ( & V_2 -> V_5 . V_664 ) ;
F_595 () ;
++ V_2 -> V_77 . V_1228 ;
if ( ! V_2 -> V_5 . V_1229 )
F_31 ( V_1097 , V_2 ) ;
F_593 ( 0 ) ;
}
void F_596 ( struct V_1 * V_2 )
{
F_206 ( V_2 ) ;
F_597 ( V_2 -> V_5 . V_611 ) ;
F_589 ( V_2 ) ;
V_73 -> V_1230 ( V_2 ) ;
}
struct V_1 * F_598 ( struct V_102 * V_102 ,
unsigned int V_1231 )
{
struct V_1 * V_2 ;
if ( F_140 () && F_135 ( & V_102 -> V_284 ) != 0 )
F_375 ( V_868
L_30
L_31 ) ;
V_2 = V_73 -> V_1232 ( V_102 , V_1231 ) ;
V_73 -> V_1233 ( V_2 ) ;
return V_2 ;
}
int F_599 ( struct V_1 * V_2 )
{
int V_120 ;
V_2 -> V_5 . V_369 . V_1234 = 1 ;
V_120 = V_612 ( V_2 ) ;
if ( V_120 )
return V_120 ;
F_600 ( V_2 ) ;
F_601 ( V_2 ) ;
V_616 ( V_2 ) ;
return V_120 ;
}
void F_602 ( struct V_1 * V_2 )
{
struct V_32 V_21 ;
struct V_102 * V_102 = V_2 -> V_102 ;
if ( V_612 ( V_2 ) )
return;
V_21 . V_38 = 0x0 ;
V_21 . V_144 = V_1235 ;
V_21 . V_40 = true ;
F_138 ( V_2 , & V_21 ) ;
V_616 ( V_2 ) ;
F_177 ( & V_102 -> V_5 . V_352 ,
V_353 ) ;
}
void F_603 ( struct V_1 * V_2 )
{
int V_120 ;
V_2 -> V_5 . V_6 . V_431 = 0 ;
V_120 = V_612 ( V_2 ) ;
F_13 ( V_120 ) ;
F_533 ( V_2 ) ;
V_616 ( V_2 ) ;
F_589 ( V_2 ) ;
V_73 -> V_1230 ( V_2 ) ;
}
void F_600 ( struct V_1 * V_2 )
{
F_156 ( & V_2 -> V_5 . V_85 , 0 ) ;
V_2 -> V_5 . V_649 = 0 ;
V_2 -> V_5 . V_648 = false ;
F_604 ( V_2 ) ;
F_449 ( V_2 ) ;
memset ( V_2 -> V_5 . V_179 , 0 , sizeof( V_2 -> V_5 . V_179 ) ) ;
F_90 ( V_2 ) ;
V_2 -> V_5 . V_183 = V_1236 ;
F_91 ( V_2 ) ;
V_2 -> V_5 . V_184 = V_195 ;
F_92 ( V_2 ) ;
V_2 -> V_5 . V_79 = 0 ;
F_31 ( V_67 , V_2 ) ;
V_2 -> V_5 . V_6 . V_431 = 0 ;
V_2 -> V_5 . V_435 . V_431 = 0 ;
F_206 ( V_2 ) ;
F_65 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1101 = false ;
F_605 ( V_2 ) ;
memset ( V_2 -> V_5 . V_620 , 0 , sizeof( V_2 -> V_5 . V_620 ) ) ;
V_2 -> V_5 . V_117 = ~ 0 ;
V_2 -> V_5 . V_118 = ~ 0 ;
V_73 -> V_1237 ( V_2 ) ;
}
void F_606 ( struct V_1 * V_2 , T_14 V_41 )
{
struct V_813 V_1164 ;
F_337 ( V_2 , & V_1164 , V_1165 ) ;
V_1164 . V_894 = V_41 << 8 ;
V_1164 . V_226 = V_41 << 12 ;
F_336 ( V_2 , & V_1164 , V_1165 ) ;
F_433 ( V_2 , 0 ) ;
}
int F_607 ( void )
{
struct V_102 * V_102 ;
struct V_1 * V_2 ;
int V_3 ;
int V_109 ;
T_2 V_1238 ;
T_2 V_1239 = 0 ;
bool V_1240 , V_1241 = false ;
F_15 () ;
V_109 = V_73 -> V_1242 () ;
if ( V_109 != 0 )
return V_109 ;
V_1238 = F_166 () ;
V_1240 = ! F_140 () ;
F_463 (kvm, &vm_list, vm_list) {
F_160 (i, vcpu, kvm) {
if ( ! V_1240 && V_2 -> V_23 == F_8 () )
F_31 ( V_324 , V_2 ) ;
if ( V_1240 && V_2 -> V_5 . V_615 > V_1238 ) {
V_1241 = true ;
if ( V_2 -> V_5 . V_615 > V_1239 )
V_1239 = V_2 -> V_5 . V_615 ;
}
}
}
if ( V_1241 ) {
T_2 V_1243 = V_1239 - V_1238 ;
V_321 = true ;
F_463 (kvm, &vm_list, vm_list) {
F_160 (i, vcpu, kvm) {
V_2 -> V_5 . V_613 += V_1243 ;
V_2 -> V_5 . V_615 = V_1238 ;
F_31 ( V_287 , V_2 ) ;
}
V_102 -> V_5 . V_300 = 0 ;
V_102 -> V_5 . V_302 = 0 ;
}
}
return 0 ;
}
void F_608 ( void )
{
V_73 -> V_1244 () ;
F_19 () ;
}
int F_609 ( void )
{
int V_120 ;
V_120 = V_73 -> V_1245 () ;
if ( V_120 != 0 )
return V_120 ;
F_326 () ;
return 0 ;
}
void F_610 ( void )
{
V_73 -> V_1246 () ;
}
void F_611 ( void * V_1247 )
{
V_73 -> V_1248 ( V_1247 ) ;
}
bool F_612 ( struct V_1 * V_2 )
{
return F_86 ( V_2 -> V_102 ) == ( V_2 -> V_5 . V_621 != NULL ) ;
}
int F_613 ( struct V_1 * V_2 )
{
struct V_399 * V_399 ;
struct V_102 * V_102 ;
int V_120 ;
F_13 ( V_2 -> V_102 == NULL ) ;
V_102 = V_2 -> V_102 ;
V_2 -> V_5 . V_1125 . V_1126 = false ;
V_2 -> V_5 . V_918 . V_842 = & V_1249 ;
if ( ! F_86 ( V_102 ) || F_614 ( V_2 ) )
V_2 -> V_5 . V_1032 = V_1127 ;
else
V_2 -> V_5 . V_1032 = V_1136 ;
V_399 = F_615 ( V_692 | V_1250 ) ;
if ( ! V_399 ) {
V_120 = - V_401 ;
goto V_1251;
}
V_2 -> V_5 . V_873 = F_616 ( V_399 ) ;
F_132 ( V_2 , V_1002 ) ;
V_120 = F_617 ( V_2 ) ;
if ( V_120 < 0 )
goto V_1252;
if ( F_86 ( V_102 ) ) {
V_120 = F_618 ( V_2 ) ;
if ( V_120 < 0 )
goto V_1253;
} else
F_619 ( & V_1254 ) ;
V_2 -> V_5 . V_388 = F_286 ( V_478 * sizeof( T_2 ) * 4 ,
V_692 ) ;
if ( ! V_2 -> V_5 . V_388 ) {
V_120 = - V_401 ;
goto V_1255;
}
V_2 -> V_5 . V_380 = V_478 ;
if ( ! F_620 ( & V_2 -> V_5 . V_611 , V_692 ) ) {
V_120 = - V_401 ;
goto V_1256;
}
V_120 = F_586 ( V_2 ) ;
if ( V_120 )
goto V_1257;
V_2 -> V_5 . V_291 = 0x0 ;
V_2 -> V_5 . V_336 = false ;
V_2 -> V_5 . V_151 = 0 ;
V_2 -> V_5 . V_1258 = V_1259 + V_669 ;
V_2 -> V_5 . V_1013 = F_621 ( V_2 ) ;
F_1 ( V_2 ) ;
F_622 ( V_2 ) ;
return 0 ;
V_1257:
F_597 ( V_2 -> V_5 . V_611 ) ;
V_1256:
F_190 ( V_2 -> V_5 . V_388 ) ;
V_1255:
F_623 ( V_2 ) ;
V_1253:
F_624 ( V_2 ) ;
V_1252:
F_625 ( ( unsigned long ) V_2 -> V_5 . V_873 ) ;
V_1251:
return V_120 ;
}
void F_626 ( struct V_1 * V_2 )
{
int V_374 ;
F_627 ( V_2 ) ;
F_190 ( V_2 -> V_5 . V_388 ) ;
F_623 ( V_2 ) ;
V_374 = F_234 ( & V_2 -> V_102 -> V_523 ) ;
F_624 ( V_2 ) ;
F_235 ( & V_2 -> V_102 -> V_523 , V_374 ) ;
F_625 ( ( unsigned long ) V_2 -> V_5 . V_873 ) ;
if ( ! F_86 ( V_2 -> V_102 ) )
F_628 ( & V_1254 ) ;
}
void F_629 ( struct V_1 * V_2 , int V_23 )
{
V_73 -> V_1260 ( V_2 , V_23 ) ;
}
int F_630 ( struct V_102 * V_102 , unsigned long type )
{
if ( type )
return - V_608 ;
F_631 ( & V_102 -> V_5 . V_1261 ) ;
F_632 ( & V_102 -> V_5 . V_1262 ) ;
F_632 ( & V_102 -> V_5 . V_1263 ) ;
F_632 ( & V_102 -> V_5 . V_1264 ) ;
F_156 ( & V_102 -> V_5 . V_1265 , 0 ) ;
F_212 ( V_763 , & V_102 -> V_5 . V_1266 ) ;
F_212 ( V_1267 ,
& V_102 -> V_5 . V_1266 ) ;
F_633 ( & V_102 -> V_5 . V_298 ) ;
F_634 ( & V_102 -> V_5 . V_1268 ) ;
F_635 ( & V_102 -> V_5 . V_313 ) ;
F_155 ( V_102 ) ;
F_636 ( & V_102 -> V_5 . V_350 , F_173 ) ;
F_636 ( & V_102 -> V_5 . V_352 , F_178 ) ;
return 0 ;
}
static void F_637 ( struct V_1 * V_2 )
{
int V_120 ;
V_120 = V_612 ( V_2 ) ;
F_13 ( V_120 ) ;
F_533 ( V_2 ) ;
V_616 ( V_2 ) ;
}
static void F_638 ( struct V_102 * V_102 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_160 (i, vcpu, kvm) {
F_65 ( V_2 ) ;
F_637 ( V_2 ) ;
}
F_160 (i, vcpu, kvm)
F_596 ( V_2 ) ;
F_218 ( & V_102 -> V_493 ) ;
for ( V_3 = 0 ; V_3 < F_135 ( & V_102 -> V_284 ) ; V_3 ++ )
V_102 -> V_1269 [ V_3 ] = NULL ;
F_156 ( & V_102 -> V_284 , 0 ) ;
F_219 ( & V_102 -> V_493 ) ;
}
void F_639 ( struct V_102 * V_102 )
{
F_640 ( & V_102 -> V_5 . V_352 ) ;
F_640 ( & V_102 -> V_5 . V_350 ) ;
F_641 ( V_102 ) ;
F_642 ( V_102 ) ;
}
void F_643 ( struct V_102 * V_102 )
{
if ( V_436 -> V_1270 == V_102 -> V_1270 ) {
struct V_1271 V_1272 ;
memset ( & V_1272 , 0 , sizeof( V_1272 ) ) ;
V_1272 . V_10 = V_1273 ;
F_644 ( V_102 , & V_1272 ) ;
V_1272 . V_10 = V_1274 ;
F_644 ( V_102 , & V_1272 ) ;
V_1272 . V_10 = V_1275 ;
F_644 ( V_102 , & V_1272 ) ;
}
F_645 ( V_102 ) ;
F_190 ( V_102 -> V_5 . V_775 ) ;
F_190 ( V_102 -> V_5 . V_1276 ) ;
F_638 ( V_102 ) ;
F_190 ( F_646 ( V_102 -> V_5 . V_1277 , 1 ) ) ;
}
void F_647 ( struct V_102 * V_102 , struct V_1278 * free ,
struct V_1278 * V_1279 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1280 ; ++ V_3 ) {
if ( ! V_1279 || free -> V_5 . V_1281 [ V_3 ] != V_1279 -> V_5 . V_1281 [ V_3 ] ) {
F_648 ( free -> V_5 . V_1281 [ V_3 ] ) ;
free -> V_5 . V_1281 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1279 || free -> V_5 . V_1282 [ V_3 - 1 ] !=
V_1279 -> V_5 . V_1282 [ V_3 - 1 ] ) {
F_648 ( free -> V_5 . V_1282 [ V_3 - 1 ] ) ;
free -> V_5 . V_1282 [ V_3 - 1 ] = NULL ;
}
}
}
int F_649 ( struct V_102 * V_102 , struct V_1278 * V_10 ,
unsigned long V_1283 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1280 ; ++ V_3 ) {
unsigned long V_1284 ;
int V_1285 ;
int V_764 = V_3 + 1 ;
V_1285 = F_650 ( V_10 -> V_1286 + V_1283 - 1 ,
V_10 -> V_1286 , V_764 ) + 1 ;
V_10 -> V_5 . V_1281 [ V_3 ] =
F_651 ( V_1285 * sizeof( * V_10 -> V_5 . V_1281 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1281 [ V_3 ] )
goto V_402;
if ( V_3 == 0 )
continue;
V_10 -> V_5 . V_1282 [ V_3 - 1 ] = F_651 ( V_1285 *
sizeof( * V_10 -> V_5 . V_1282 [ V_3 - 1 ] ) ) ;
if ( ! V_10 -> V_5 . V_1282 [ V_3 - 1 ] )
goto V_402;
if ( V_10 -> V_1286 & ( F_652 ( V_764 ) - 1 ) )
V_10 -> V_5 . V_1282 [ V_3 - 1 ] [ 0 ] . V_1287 = 1 ;
if ( ( V_10 -> V_1286 + V_1283 ) & ( F_652 ( V_764 ) - 1 ) )
V_10 -> V_5 . V_1282 [ V_3 - 1 ] [ V_1285 - 1 ] . V_1287 = 1 ;
V_1284 = V_10 -> V_1288 >> V_107 ;
if ( ( V_10 -> V_1286 ^ V_1284 ) & ( F_652 ( V_764 ) - 1 ) ||
! F_653 () ) {
unsigned long V_805 ;
for ( V_805 = 0 ; V_805 < V_1285 ; ++ V_805 )
V_10 -> V_5 . V_1282 [ V_3 - 1 ] [ V_805 ] . V_1287 = 1 ;
}
}
return 0 ;
V_402:
for ( V_3 = 0 ; V_3 < V_1280 ; ++ V_3 ) {
F_648 ( V_10 -> V_5 . V_1281 [ V_3 ] ) ;
V_10 -> V_5 . V_1281 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_648 ( V_10 -> V_5 . V_1282 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1282 [ V_3 - 1 ] = NULL ;
}
return - V_401 ;
}
void F_654 ( struct V_102 * V_102 )
{
F_655 ( V_102 ) ;
}
int F_656 ( struct V_102 * V_102 ,
struct V_1278 * V_1289 ,
struct V_1271 * V_1272 ,
enum V_1290 V_1291 )
{
if ( ( V_1289 -> V_1231 >= V_578 ) && ( V_1291 == V_1292 ) ) {
unsigned long V_1288 ;
V_1288 = F_657 ( NULL , 0 , V_1289 -> V_1283 * V_108 ,
V_1293 | V_1294 ,
V_1295 | V_1296 , 0 ) ;
if ( F_188 ( ( void * ) V_1288 ) )
return F_189 ( ( void * ) V_1288 ) ;
V_1289 -> V_1288 = V_1288 ;
}
return 0 ;
}
static void F_658 ( struct V_102 * V_102 ,
struct V_1278 * V_862 )
{
if ( V_862 -> V_294 & V_1297 ) {
F_659 ( V_102 , V_862 ) ;
return;
}
if ( V_862 -> V_294 & V_1298 ) {
if ( V_73 -> V_1299 )
V_73 -> V_1299 ( V_102 , V_862 ) ;
else
F_659 ( V_102 , V_862 ) ;
} else {
if ( V_73 -> V_1300 )
V_73 -> V_1300 ( V_102 , V_862 ) ;
}
}
void F_660 ( struct V_102 * V_102 ,
struct V_1271 * V_1272 ,
const struct V_1278 * V_861 ,
enum V_1290 V_1291 )
{
struct V_1278 * V_862 ;
int V_1301 = 0 ;
if ( ( V_1272 -> V_10 >= V_578 ) && ( V_1291 == V_1302 ) ) {
int V_109 ;
V_109 = F_661 ( V_861 -> V_1288 ,
V_861 -> V_1283 * V_108 ) ;
if ( V_109 < 0 )
F_10 ( V_868
L_32
L_33 ) ;
}
if ( ! V_102 -> V_5 . V_731 )
V_1301 = F_662 ( V_102 ) ;
if ( V_1301 )
F_295 ( V_102 , V_1301 ) ;
V_862 = F_663 ( V_102 -> V_1303 , V_1272 -> V_10 ) ;
if ( ( V_1291 != V_1302 ) &&
( V_861 -> V_294 & V_1298 ) &&
! ( V_862 -> V_294 & V_1298 ) )
F_664 ( V_102 , V_862 ) ;
if ( V_1291 != V_1302 )
F_658 ( V_102 , V_862 ) ;
}
void F_665 ( struct V_102 * V_102 )
{
F_666 ( V_102 ) ;
}
void F_667 ( struct V_102 * V_102 ,
struct V_1278 * V_10 )
{
F_666 ( V_102 ) ;
}
int F_556 ( struct V_1 * V_2 )
{
if ( F_429 ( V_2 ) && V_73 -> V_1081 )
V_73 -> V_1081 ( V_2 , false ) ;
return ( V_2 -> V_5 . V_1032 == V_1127 &&
! V_2 -> V_5 . V_6 . V_1101 )
|| ! F_668 ( & V_2 -> V_1304 . V_1305 )
|| F_669 ( V_2 )
|| V_2 -> V_5 . V_1125 . V_1126
|| F_135 ( & V_2 -> V_5 . V_85 ) ||
( F_512 ( V_2 ) &&
F_511 ( V_2 ) ) ;
}
int F_670 ( struct V_1 * V_2 )
{
return F_671 ( V_2 ) == V_1111 ;
}
int F_512 ( struct V_1 * V_2 )
{
return V_73 -> V_1083 ( V_2 ) ;
}
unsigned long F_447 ( struct V_1 * V_2 )
{
if ( F_502 ( V_2 ) )
return F_428 ( V_2 ) ;
return ( T_1 ) ( F_381 ( V_2 , V_1165 ) +
F_428 ( V_2 ) ) ;
}
bool F_672 ( struct V_1 * V_2 , unsigned long V_1306 )
{
return F_447 ( V_2 ) == V_1306 ;
}
unsigned long F_427 ( struct V_1 * V_2 )
{
unsigned long V_953 ;
V_953 = V_73 -> V_983 ( V_2 ) ;
if ( V_2 -> V_175 & V_956 )
V_953 &= ~ V_955 ;
return V_953 ;
}
static void F_454 ( struct V_1 * V_2 , unsigned long V_953 )
{
if ( V_2 -> V_175 & V_956 &&
F_672 ( V_2 , V_2 -> V_5 . V_960 ) )
V_953 |= V_955 ;
V_73 -> V_1307 ( V_2 , V_953 ) ;
}
void F_434 ( struct V_1 * V_2 , unsigned long V_953 )
{
F_454 ( V_2 , V_953 ) ;
F_31 ( V_67 , V_2 ) ;
}
void F_673 ( struct V_1 * V_2 , struct V_1308 * V_347 )
{
int V_120 ;
if ( ( V_2 -> V_5 . V_84 . V_945 != V_347 -> V_5 . V_945 ) ||
V_347 -> V_1309 )
return;
V_120 = F_540 ( V_2 ) ;
if ( F_152 ( V_120 ) )
return;
if ( ! V_2 -> V_5 . V_84 . V_945 &&
V_347 -> V_5 . V_105 != V_2 -> V_5 . V_84 . V_1310 ( V_2 ) )
return;
V_2 -> V_5 . V_84 . V_1311 ( V_2 , V_347 -> V_820 , 0 , true ) ;
}
static inline T_1 F_674 ( T_5 V_103 )
{
return F_675 ( V_103 & 0xffffffff , F_676 ( V_4 ) ) ;
}
static inline T_1 F_677 ( T_1 V_1312 )
{
return ( V_1312 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_678 ( struct V_1 * V_2 , T_5 V_103 )
{
T_1 V_1312 = F_674 ( V_103 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1312 ] != ~ 0 )
V_1312 = F_677 ( V_1312 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1312 ] = V_103 ;
}
static T_1 F_679 ( struct V_1 * V_2 , T_5 V_103 )
{
int V_3 ;
T_1 V_1312 = F_674 ( V_103 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1312 ] != V_103 &&
V_2 -> V_5 . V_6 . V_7 [ V_1312 ] != ~ 0 ) ; V_3 ++ )
V_1312 = F_677 ( V_1312 ) ;
return V_1312 ;
}
bool F_680 ( struct V_1 * V_2 , T_5 V_103 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_679 ( V_2 , V_103 ) ] == V_103 ;
}
static void F_681 ( struct V_1 * V_2 , T_5 V_103 )
{
T_1 V_3 , V_805 , V_1313 ;
V_3 = V_805 = F_679 ( V_2 , V_103 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_805 = F_677 ( V_805 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_805 ] == ~ 0 )
return;
V_1313 = F_674 ( V_2 -> V_5 . V_6 . V_7 [ V_805 ] ) ;
} while ( ( V_3 <= V_805 ) ? ( V_3 < V_1313 && V_1313 <= V_805 ) : ( V_3 < V_1313 || V_1313 <= V_805 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_805 ] ;
V_3 = V_805 ;
}
}
static int F_682 ( struct V_1 * V_2 , T_1 V_192 )
{
return F_171 ( V_2 -> V_102 , & V_2 -> V_5 . V_6 . V_38 , & V_192 ,
sizeof( V_192 ) ) ;
}
void F_683 ( struct V_1 * V_2 ,
struct V_1308 * V_347 )
{
struct V_75 V_76 ;
F_684 ( V_347 -> V_5 . V_1314 , V_347 -> V_820 ) ;
F_678 ( V_2 , V_347 -> V_5 . V_103 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_431 & V_432 ) ||
( V_2 -> V_5 . V_6 . V_433 &&
V_73 -> V_88 ( V_2 ) == 0 ) )
F_31 ( V_1100 , V_2 ) ;
else if ( ! F_682 ( V_2 , V_1315 ) ) {
V_76 . V_41 = V_42 ;
V_76 . V_919 = true ;
V_76 . V_62 = 0 ;
V_76 . V_81 = false ;
V_76 . V_80 = V_347 -> V_5 . V_1314 ;
F_37 ( V_2 , & V_76 ) ;
}
}
void F_685 ( struct V_1 * V_2 ,
struct V_1308 * V_347 )
{
struct V_75 V_76 ;
F_686 ( V_347 -> V_5 . V_1314 , V_347 -> V_820 ) ;
if ( V_347 -> V_1309 )
V_347 -> V_5 . V_1314 = ~ 0 ;
else
F_681 ( V_2 , V_347 -> V_5 . V_103 ) ;
if ( ( V_2 -> V_5 . V_6 . V_431 & V_432 ) &&
! F_682 ( V_2 , V_1316 ) ) {
V_76 . V_41 = V_42 ;
V_76 . V_919 = true ;
V_76 . V_62 = 0 ;
V_76 . V_81 = false ;
V_76 . V_80 = V_347 -> V_5 . V_1314 ;
F_37 ( V_2 , & V_76 ) ;
}
V_2 -> V_5 . V_6 . V_1101 = false ;
V_2 -> V_5 . V_1032 = V_1127 ;
}
bool F_687 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_431 & V_432 ) )
return true ;
else
return ! F_514 ( V_2 ) &&
V_73 -> V_1083 ( V_2 ) ;
}
void F_688 ( struct V_102 * V_102 )
{
F_42 ( & V_102 -> V_5 . V_1265 ) ;
}
void F_689 ( struct V_102 * V_102 )
{
F_690 ( & V_102 -> V_5 . V_1265 ) ;
}
bool F_247 ( struct V_102 * V_102 )
{
return F_135 ( & V_102 -> V_5 . V_1265 ) ;
}
