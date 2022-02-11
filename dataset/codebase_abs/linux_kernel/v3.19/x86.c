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
int F_51 ( struct V_1 * V_2 , T_5 V_103 ,
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
int F_72 ( struct V_1 * V_2 , T_1 V_144 , T_2 V_145 )
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
static void F_116 ( struct V_102 * V_102 , T_6 V_234 )
{
int V_235 ;
int V_120 ;
struct V_236 V_237 ;
struct V_238 V_239 ;
if ( ! V_234 )
return;
V_120 = F_117 ( V_102 , V_234 , & V_235 , sizeof( V_235 ) ) ;
if ( V_120 )
return;
if ( V_235 & 1 )
++ V_235 ;
++ V_235 ;
F_118 ( V_102 , V_234 , & V_235 , sizeof( V_235 ) ) ;
F_119 ( & V_239 ) ;
if ( V_102 -> V_5 . V_240 ) {
struct V_238 V_241 = F_120 ( V_102 -> V_5 . V_240 ) ;
V_239 = F_121 ( V_239 , V_241 ) ;
}
V_237 . V_242 = V_239 . V_243 ;
V_237 . V_244 = V_239 . V_245 ;
V_237 . V_235 = V_235 ;
F_118 ( V_102 , V_234 , & V_237 , sizeof( V_237 ) ) ;
V_235 ++ ;
F_118 ( V_102 , V_234 , & V_235 , sizeof( V_235 ) ) ;
}
static T_7 F_122 ( T_7 V_246 , T_7 V_247 )
{
T_7 V_248 , V_249 ;
__asm__ ( "divl %4"
: "=a" (quotient), "=d" (remainder)
: "0" (0), "1" (dividend), "r" (divisor) );
return V_248 ;
}
static void F_123 ( T_7 V_250 , T_7 V_251 ,
T_8 * V_252 , T_1 * V_253 )
{
T_9 V_254 ;
T_10 V_231 = 0 ;
T_9 V_255 ;
T_7 V_256 ;
V_255 = V_251 * 1000LL ;
V_254 = V_250 * 1000LL ;
while ( V_255 > V_254 * 2 || V_255 & 0xffffffff00000000ULL ) {
V_255 >>= 1 ;
V_231 -- ;
}
V_256 = ( T_7 ) V_255 ;
while ( V_256 <= V_254 || V_254 & 0xffffffff00000000ULL ) {
if ( V_254 & 0xffffffff00000000ULL || V_256 & 0x80000000 )
V_254 >>= 1 ;
else
V_256 <<= 1 ;
V_231 ++ ;
}
* V_252 = V_231 ;
* V_253 = F_122 ( V_254 , V_256 ) ;
F_124 ( L_2 ,
V_257 , V_251 , V_250 , V_231 , * V_253 ) ;
}
static inline T_2 F_125 ( void )
{
return F_126 () ;
}
static inline T_2 F_127 ( struct V_1 * V_2 , T_2 V_244 )
{
return F_128 ( V_244 , V_2 -> V_5 . V_258 ,
V_2 -> V_5 . V_259 ) ;
}
static T_1 F_129 ( T_1 V_260 , T_11 V_261 )
{
T_2 V_262 = ( T_2 ) V_260 * ( 1000000 + V_261 ) ;
F_130 ( V_262 , 1000000 ) ;
return V_262 ;
}
static void F_131 ( struct V_1 * V_2 , T_1 V_263 )
{
T_1 V_264 , V_265 ;
int V_266 = 0 ;
if ( V_263 == 0 )
return;
F_123 ( V_263 , V_267 / 1000 ,
& V_2 -> V_5 . V_259 ,
& V_2 -> V_5 . V_258 ) ;
V_2 -> V_5 . V_268 = V_263 ;
V_264 = F_129 ( V_269 , - V_270 ) ;
V_265 = F_129 ( V_269 , V_270 ) ;
if ( V_263 < V_264 || V_263 > V_265 ) {
F_124 ( L_3 , V_263 , V_264 , V_265 ) ;
V_266 = 1 ;
}
V_73 -> V_271 ( V_2 , V_263 , V_266 ) ;
}
static T_2 F_132 ( struct V_1 * V_2 , T_12 V_272 )
{
T_2 V_273 = F_128 ( V_272 - V_2 -> V_5 . V_274 ,
V_2 -> V_5 . V_258 ,
V_2 -> V_5 . V_259 ) ;
V_273 += V_2 -> V_5 . V_275 ;
return V_273 ;
}
void F_133 ( struct V_1 * V_2 )
{
#ifdef F_63
bool V_276 ;
struct V_277 * V_278 = & V_2 -> V_102 -> V_5 ;
struct V_220 * V_279 = & V_220 ;
V_276 = ( V_278 -> V_280 + 1 ==
F_134 ( & V_2 -> V_102 -> V_281 ) ) ;
if ( V_278 -> V_282 ||
( V_279 -> clock . V_227 == V_283 && V_276 ) )
F_31 ( V_284 , V_2 ) ;
F_135 ( V_2 -> V_285 , V_278 -> V_280 ,
F_134 ( & V_2 -> V_102 -> V_281 ) ,
V_278 -> V_282 , V_279 -> clock . V_227 ) ;
#endif
}
static void F_136 ( struct V_1 * V_2 , T_12 V_94 )
{
T_2 V_286 = V_73 -> V_287 ( V_2 ) ;
V_2 -> V_5 . V_288 += V_94 - V_286 ;
}
void F_137 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
struct V_102 * V_102 = V_2 -> V_102 ;
T_2 V_94 , V_289 , V_290 ;
unsigned long V_291 ;
T_12 V_292 ;
bool V_293 ;
bool V_294 ;
T_2 V_38 = V_21 -> V_38 ;
F_138 ( & V_102 -> V_5 . V_295 , V_291 ) ;
V_94 = V_73 -> V_296 ( V_2 , V_38 ) ;
V_289 = F_125 () ;
V_290 = V_289 - V_102 -> V_5 . V_297 ;
if ( V_2 -> V_5 . V_268 ) {
int V_298 = 0 ;
V_292 = V_38 - V_102 -> V_5 . V_299 ;
#ifdef F_63
V_292 = ( V_292 * 1000 ) / V_2 -> V_5 . V_268 ;
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
F_130 ( V_290 , 1000 ) ;
V_292 -= V_290 ;
if ( V_292 < 0 )
V_292 = - V_292 ;
if ( V_298 )
V_292 = V_300 ;
} else
V_292 = V_300 ;
if ( V_292 < V_300 &&
V_2 -> V_5 . V_268 == V_102 -> V_5 . V_301 ) {
if ( ! F_139 () ) {
V_94 = V_102 -> V_5 . V_302 ;
F_124 ( L_4 , V_38 ) ;
} else {
T_2 V_303 = F_127 ( V_2 , V_290 ) ;
V_38 += V_303 ;
V_94 = V_73 -> V_296 ( V_2 , V_38 ) ;
F_124 ( L_5 , V_303 ) ;
}
V_293 = true ;
V_294 = ( V_2 -> V_5 . V_304 == V_102 -> V_5 . V_305 ) ;
} else {
V_102 -> V_5 . V_305 ++ ;
V_102 -> V_5 . V_306 = V_289 ;
V_102 -> V_5 . V_307 = V_38 ;
V_102 -> V_5 . V_302 = V_94 ;
V_293 = false ;
F_124 ( L_6 ,
V_102 -> V_5 . V_305 , V_38 ) ;
}
V_102 -> V_5 . V_297 = V_289 ;
V_102 -> V_5 . V_299 = V_38 ;
V_102 -> V_5 . V_301 = V_2 -> V_5 . V_268 ;
V_2 -> V_5 . V_308 = V_38 ;
V_2 -> V_5 . V_304 = V_102 -> V_5 . V_305 ;
V_2 -> V_5 . V_274 = V_102 -> V_5 . V_306 ;
V_2 -> V_5 . V_275 = V_102 -> V_5 . V_307 ;
if ( F_140 ( V_2 ) && ! V_21 -> V_40 )
F_136 ( V_2 , V_94 ) ;
V_73 -> V_309 ( V_2 , V_94 ) ;
F_141 ( & V_102 -> V_5 . V_295 , V_291 ) ;
F_142 ( & V_102 -> V_5 . V_310 ) ;
if ( ! V_293 ) {
V_102 -> V_5 . V_280 = 0 ;
} else if ( ! V_294 ) {
V_102 -> V_5 . V_280 ++ ;
}
F_133 ( V_2 ) ;
F_143 ( & V_102 -> V_5 . V_310 ) ;
}
static T_13 F_144 ( void )
{
T_13 V_109 ;
T_2 V_311 ;
F_145 () ;
V_109 = ( T_13 ) F_146 () ;
V_311 = V_220 . clock . V_229 ;
if ( F_147 ( V_109 >= V_311 ) )
return V_109 ;
asm volatile ("");
return V_311 ;
}
static inline T_2 F_148 ( T_13 * V_312 )
{
long V_262 ;
struct V_220 * V_279 = & V_220 ;
* V_312 = F_144 () ;
V_262 = ( * V_312 - V_279 -> clock . V_229 ) & V_279 -> clock . V_28 ;
return V_262 * V_279 -> clock . V_230 ;
}
static int F_149 ( T_12 * V_313 , T_13 * V_312 )
{
struct V_220 * V_279 = & V_220 ;
unsigned long V_226 ;
int V_314 ;
T_2 V_289 ;
do {
V_226 = F_150 ( & V_279 -> V_226 ) ;
V_314 = V_279 -> clock . V_227 ;
V_289 = V_279 -> V_232 ;
V_289 += F_148 ( V_312 ) ;
V_289 >>= V_279 -> clock . V_231 ;
V_289 += V_279 -> V_222 ;
} while ( F_151 ( F_152 ( & V_279 -> V_226 , V_226 ) ) );
* V_313 = V_289 ;
return V_314 ;
}
static bool F_153 ( T_12 * V_272 , T_13 * V_312 )
{
if ( V_220 . clock . V_227 != V_283 )
return false ;
return F_149 ( V_272 , V_312 ) == V_283 ;
}
static void F_154 ( struct V_102 * V_102 )
{
#ifdef F_63
struct V_277 * V_278 = & V_102 -> V_5 ;
int V_227 ;
bool V_315 , V_276 ;
V_276 = ( V_278 -> V_280 + 1 ==
F_134 ( & V_102 -> V_281 ) ) ;
V_315 = F_153 (
& V_278 -> V_316 ,
& V_278 -> V_317 ) ;
V_278 -> V_282 = V_315 && V_276
&& ! V_318 ;
if ( V_278 -> V_282 )
F_155 ( & V_319 , 1 ) ;
V_227 = V_220 . clock . V_227 ;
F_156 ( V_278 -> V_282 , V_227 ,
V_276 ) ;
#endif
}
static void F_157 ( struct V_102 * V_102 )
{
#ifdef F_63
int V_3 ;
struct V_1 * V_2 ;
struct V_277 * V_278 = & V_102 -> V_5 ;
F_142 ( & V_278 -> V_310 ) ;
F_158 ( V_102 ) ;
F_154 ( V_102 ) ;
F_159 (i, vcpu, kvm)
F_31 ( V_320 , V_2 ) ;
F_159 (i, vcpu, kvm)
F_160 ( V_321 , & V_2 -> V_322 ) ;
F_143 ( & V_278 -> V_310 ) ;
#endif
}
static int F_161 ( struct V_1 * V_262 )
{
unsigned long V_291 , V_263 ;
struct V_323 * V_2 = & V_262 -> V_5 ;
struct V_277 * V_278 = & V_262 -> V_102 -> V_5 ;
T_12 V_272 ;
T_2 V_324 , V_325 ;
struct V_326 V_327 ;
T_14 V_328 ;
bool V_282 ;
V_272 = 0 ;
V_325 = 0 ;
F_142 ( & V_278 -> V_310 ) ;
V_282 = V_278 -> V_282 ;
if ( V_282 ) {
V_325 = V_278 -> V_317 ;
V_272 = V_278 -> V_316 ;
}
F_143 ( & V_278 -> V_310 ) ;
F_162 ( V_291 ) ;
V_263 = F_163 ( V_329 ) ;
if ( F_151 ( V_263 == 0 ) ) {
F_164 ( V_291 ) ;
F_31 ( V_320 , V_262 ) ;
return 1 ;
}
if ( ! V_282 ) {
V_325 = F_165 () ;
V_272 = F_125 () ;
}
V_324 = V_73 -> V_330 ( V_262 , V_325 ) ;
if ( V_2 -> V_331 ) {
T_2 V_273 = F_132 ( V_262 , V_272 ) ;
if ( V_273 > V_324 ) {
F_166 ( V_262 , V_273 - V_324 ) ;
V_324 = V_273 ;
}
}
F_164 ( V_291 ) ;
if ( ! V_2 -> V_332 )
return 0 ;
if ( F_151 ( V_2 -> V_333 != V_263 ) ) {
F_123 ( V_267 / 1000 , V_263 ,
& V_2 -> V_334 . V_335 ,
& V_2 -> V_334 . V_336 ) ;
V_2 -> V_333 = V_263 ;
}
V_2 -> V_334 . V_324 = V_324 ;
V_2 -> V_334 . V_337 = V_272 + V_262 -> V_102 -> V_5 . V_240 ;
V_2 -> V_308 = V_324 ;
if ( F_151 ( F_167 ( V_262 -> V_102 , & V_2 -> V_338 ,
& V_327 , sizeof( V_327 ) ) ) )
return 0 ;
V_2 -> V_334 . V_235 = V_327 . V_235 + 2 ;
V_328 = ( V_327 . V_291 & V_339 ) ;
if ( V_2 -> V_340 ) {
V_328 |= V_339 ;
V_2 -> V_340 = false ;
}
if ( V_282 )
V_328 |= V_341 ;
V_2 -> V_334 . V_291 = V_328 ;
F_168 ( V_262 -> V_285 , & V_2 -> V_334 ) ;
F_169 ( V_262 -> V_102 , & V_2 -> V_338 ,
& V_2 -> V_334 ,
sizeof( V_2 -> V_334 ) ) ;
return 0 ;
}
static void F_170 ( struct V_342 * V_343 )
{
int V_3 ;
struct V_344 * V_345 = F_171 ( V_343 ) ;
struct V_277 * V_278 = F_4 ( V_345 , struct V_277 ,
V_346 ) ;
struct V_102 * V_102 = F_4 ( V_278 , struct V_102 , V_5 ) ;
struct V_1 * V_2 ;
F_159 (i, vcpu, kvm) {
F_31 ( V_320 , V_2 ) ;
F_172 ( V_2 ) ;
}
}
static void F_173 ( struct V_1 * V_262 )
{
struct V_102 * V_102 = V_262 -> V_102 ;
F_31 ( V_320 , V_262 ) ;
F_174 ( & V_102 -> V_5 . V_346 ,
V_347 ) ;
}
static void F_175 ( struct V_342 * V_343 )
{
struct V_344 * V_345 = F_171 ( V_343 ) ;
struct V_277 * V_278 = F_4 ( V_345 , struct V_277 ,
V_348 ) ;
struct V_102 * V_102 = F_4 ( V_278 , struct V_102 , V_5 ) ;
F_174 ( & V_102 -> V_5 . V_346 , 0 ) ;
F_174 ( & V_102 -> V_5 . V_348 ,
V_349 ) ;
}
static bool F_176 ( unsigned V_21 )
{
switch ( V_21 ) {
case 0x200 ... 0x200 + 2 * V_350 - 1 :
case V_351 :
case V_352 :
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
return true ;
case 0x2f8 :
return true ;
}
return false ;
}
static bool F_177 ( unsigned V_313 )
{
return V_313 < 8 && ( 1 << V_313 ) & 0xf3 ;
}
static bool F_178 ( unsigned V_313 )
{
return V_313 < 8 && ( 1 << V_313 ) & 0x73 ;
}
bool F_179 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
int V_3 ;
T_2 V_28 ;
if ( ! F_176 ( V_21 ) )
return false ;
if ( V_21 == V_363 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_177 ( ( V_38 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
} else if ( V_21 == V_362 ) {
if ( V_38 & ~ 0xcff )
return false ;
return F_178 ( V_38 & 0xff ) ;
} else if ( V_21 >= V_351 && V_21 <= V_361 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_178 ( ( V_38 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
}
F_29 ( ! ( V_21 >= 0x200 && V_21 < 0x200 + 2 * V_350 ) ) ;
V_28 = ( ~ 0ULL ) << F_22 ( V_2 ) ;
if ( ( V_21 & 1 ) == 0 ) {
if ( ! F_178 ( V_38 & 0xff ) )
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
static int F_180 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
T_2 * V_364 = ( T_2 * ) & V_2 -> V_5 . V_365 . V_366 ;
if ( ! F_179 ( V_2 , V_21 , V_38 ) )
return 1 ;
if ( V_21 == V_362 ) {
V_2 -> V_5 . V_365 . V_367 = V_38 ;
V_2 -> V_5 . V_365 . V_368 = ( V_38 & 0xc00 ) >> 10 ;
} else if ( V_21 == V_351 )
V_364 [ 0 ] = V_38 ;
else if ( V_21 == V_352 || V_21 == V_353 )
V_364 [ 1 + V_21 - V_352 ] = V_38 ;
else if ( V_21 >= V_354 && V_21 <= V_361 )
V_364 [ 3 + V_21 - V_354 ] = V_38 ;
else if ( V_21 == V_363 )
V_2 -> V_5 . V_369 = V_38 ;
else {
int V_370 , V_371 ;
T_2 * V_372 ;
V_370 = ( V_21 - 0x200 ) / 2 ;
V_371 = V_21 - 0x200 - 2 * V_370 ;
if ( ! V_371 )
V_372 =
( T_2 * ) & V_2 -> V_5 . V_365 . V_373 [ V_370 ] . V_374 ;
else
V_372 =
( T_2 * ) & V_2 -> V_5 . V_365 . V_373 [ V_370 ] . V_375 ;
* V_372 = V_38 ;
}
F_66 ( V_2 ) ;
return 0 ;
}
static int F_181 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
T_2 V_376 = V_2 -> V_5 . V_376 ;
unsigned V_377 = V_376 & 0xff ;
switch ( V_21 ) {
case V_378 :
V_2 -> V_5 . V_379 = V_38 ;
break;
case V_380 :
if ( ! ( V_376 & V_381 ) )
return 1 ;
if ( V_38 != 0 && V_38 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_382 = V_38 ;
break;
default:
if ( V_21 >= V_383 &&
V_21 < F_182 ( V_377 ) ) {
T_1 V_94 = V_21 - V_383 ;
if ( ( V_94 & 0x3 ) == 0 &&
V_38 != 0 && ( V_38 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_384 [ V_94 ] = V_38 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_183 ( struct V_1 * V_2 , T_2 V_38 )
{
struct V_102 * V_102 = V_2 -> V_102 ;
int V_385 = F_57 ( V_2 ) ;
T_14 * V_386 = V_385 ? ( T_14 * ) ( long ) V_102 -> V_5 . F_183 . V_387
: ( T_14 * ) ( long ) V_102 -> V_5 . F_183 . V_388 ;
T_14 V_389 = V_385 ? V_102 -> V_5 . F_183 . V_390
: V_102 -> V_5 . F_183 . V_391 ;
T_1 V_392 = V_38 & ~ V_393 ;
T_2 V_394 = V_38 & V_393 ;
T_14 * V_395 ;
int V_120 ;
V_120 = - V_396 ;
if ( V_392 >= V_389 )
goto V_114;
V_120 = - V_397 ;
V_395 = F_184 ( V_386 + ( V_392 * V_108 ) , V_108 ) ;
if ( F_185 ( V_395 ) ) {
V_120 = F_186 ( V_395 ) ;
goto V_114;
}
if ( F_118 ( V_102 , V_394 , V_395 , V_108 ) )
goto V_398;
V_120 = 0 ;
V_398:
F_187 ( V_395 ) ;
V_114:
return V_120 ;
}
static bool F_188 ( struct V_102 * V_102 )
{
return V_102 -> V_5 . V_399 & V_400 ;
}
static bool F_189 ( T_1 V_21 )
{
bool V_120 = false ;
switch ( V_21 ) {
case V_401 :
case V_402 :
case V_403 :
case V_404 :
V_120 = true ;
break;
}
return V_120 ;
}
static int F_190 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
struct V_102 * V_102 = V_2 -> V_102 ;
switch ( V_21 ) {
case V_401 :
V_102 -> V_5 . V_405 = V_38 ;
if ( ! V_102 -> V_5 . V_405 )
V_102 -> V_5 . V_399 &= ~ V_400 ;
break;
case V_402 : {
T_2 V_103 ;
unsigned long V_406 ;
T_14 V_407 [ 4 ] ;
if ( ! V_102 -> V_5 . V_405 )
break;
if ( ! ( V_38 & V_400 ) ) {
V_102 -> V_5 . V_399 = V_38 ;
break;
}
V_103 = V_38 >> V_408 ;
V_406 = F_191 ( V_102 , V_103 ) ;
if ( F_192 ( V_406 ) )
return 1 ;
V_73 -> V_409 ( V_2 , V_407 ) ;
( ( unsigned char * ) V_407 ) [ 3 ] = 0xc3 ;
if ( F_193 ( ( void V_410 * ) V_406 , V_407 , 4 ) )
return 1 ;
V_102 -> V_5 . V_399 = V_38 ;
F_194 ( V_102 , V_103 ) ;
break;
}
case V_403 : {
T_2 V_103 ;
T_15 V_411 ;
memset ( & V_411 , 0 , sizeof( V_411 ) ) ;
V_102 -> V_5 . V_412 = V_38 ;
if ( ! ( V_38 & V_413 ) )
break;
V_103 = V_38 >> V_414 ;
if ( F_118 ( V_102 , V_103 << V_414 ,
& V_411 , sizeof( V_411 ) ) )
return 1 ;
F_194 ( V_102 , V_103 ) ;
break;
}
default:
F_195 ( V_2 , L_7
L_8 , V_21 , V_38 ) ;
return 1 ;
}
return 0 ;
}
static int F_196 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
switch ( V_21 ) {
case V_415 : {
T_2 V_103 ;
unsigned long V_406 ;
if ( ! ( V_38 & V_416 ) ) {
V_2 -> V_5 . V_417 = V_38 ;
if ( F_197 ( V_2 , 0 ) )
return 1 ;
break;
}
V_103 = V_38 >> V_418 ;
V_406 = F_191 ( V_2 -> V_102 , V_103 ) ;
if ( F_192 ( V_406 ) )
return 1 ;
if ( F_198 ( ( void V_410 * ) V_406 , V_108 ) )
return 1 ;
V_2 -> V_5 . V_417 = V_38 ;
F_194 ( V_2 -> V_102 , V_103 ) ;
if ( F_197 ( V_2 , F_48 ( V_103 ) | V_419 ) )
return 1 ;
break;
}
case V_420 :
return F_199 ( V_2 , V_421 , V_38 ) ;
case V_422 :
return F_199 ( V_2 , V_423 , V_38 ) ;
case V_424 :
return F_199 ( V_2 , V_425 , V_38 ) ;
default:
F_195 ( V_2 , L_7
L_8 , V_21 , V_38 ) ;
return 1 ;
}
return 0 ;
}
static int F_200 ( struct V_1 * V_2 , T_2 V_38 )
{
T_6 V_426 = V_38 & ~ 0x3f ;
if ( V_38 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_427 = V_38 ;
if ( ! ( V_38 & V_428 ) ) {
F_65 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_201 ( V_2 -> V_102 , & V_2 -> V_5 . V_6 . V_38 , V_426 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_429 = ! ( V_38 & V_430 ) ;
F_202 ( V_2 ) ;
return 0 ;
}
static void F_203 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_332 = false ;
}
static void F_204 ( struct V_1 * V_2 )
{
T_2 V_303 ;
if ( ! ( V_2 -> V_5 . V_431 . V_427 & V_419 ) )
return;
V_303 = V_432 -> V_433 . V_434 - V_2 -> V_5 . V_431 . V_435 ;
V_2 -> V_5 . V_431 . V_435 = V_432 -> V_433 . V_434 ;
V_2 -> V_5 . V_431 . V_436 = V_303 ;
}
static void F_205 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_431 . V_427 & V_419 ) )
return;
if ( F_151 ( F_167 ( V_2 -> V_102 , & V_2 -> V_5 . V_431 . V_437 ,
& V_2 -> V_5 . V_431 . V_438 , sizeof( struct V_439 ) ) ) )
return;
V_2 -> V_5 . V_431 . V_438 . V_438 += V_2 -> V_5 . V_431 . V_436 ;
V_2 -> V_5 . V_431 . V_438 . V_235 += 2 ;
V_2 -> V_5 . V_431 . V_436 = 0 ;
F_169 ( V_2 -> V_102 , & V_2 -> V_5 . V_431 . V_437 ,
& V_2 -> V_5 . V_431 . V_438 , sizeof( struct V_439 ) ) ;
}
int F_206 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
bool V_440 = false ;
T_1 V_21 = V_33 -> V_144 ;
T_2 V_38 = V_33 -> V_38 ;
switch ( V_21 ) {
case V_441 :
case V_442 :
case V_443 :
case V_444 :
case V_445 :
case V_446 :
break;
case V_447 :
return F_105 ( V_2 , V_38 ) ;
case V_448 :
V_38 &= ~ ( T_2 ) 0x40 ;
V_38 &= ~ ( T_2 ) 0x100 ;
V_38 &= ~ ( T_2 ) 0x8 ;
V_38 &= ~ ( T_2 ) 0x40000 ;
if ( V_38 != 0 ) {
F_195 ( V_2 , L_9 ,
V_38 ) ;
return 1 ;
}
break;
case V_449 :
if ( V_38 != 0 ) {
F_195 ( V_2 , L_10
L_11 , V_38 ) ;
return 1 ;
}
break;
case V_450 :
if ( ! V_38 ) {
break;
} else if ( V_38 & ~ ( V_451 | V_452 ) ) {
return 1 ;
}
F_195 ( V_2 , L_12 ,
V_257 , V_38 ) ;
break;
case 0x200 ... 0x2ff :
return F_180 ( V_2 , V_21 , V_38 ) ;
case V_453 :
return F_21 ( V_2 , V_33 ) ;
case V_454 ... V_454 + 0x3ff :
return F_207 ( V_2 , V_21 , V_38 ) ;
case V_455 :
F_208 ( V_2 , V_38 ) ;
break;
case V_456 :
if ( F_140 ( V_2 ) ) {
if ( ! V_33 -> V_40 ) {
T_12 V_457 = V_38 - V_2 -> V_5 . V_288 ;
V_73 -> V_458 ( V_2 , V_457 , true ) ;
}
V_2 -> V_5 . V_288 = V_38 ;
}
break;
case V_459 :
V_2 -> V_5 . V_460 = V_38 ;
break;
case V_461 :
case V_462 :
V_2 -> V_102 -> V_5 . V_234 = V_38 ;
F_116 ( V_2 -> V_102 , V_38 ) ;
break;
case V_463 :
case V_464 : {
T_2 V_465 ;
F_203 ( V_2 ) ;
V_2 -> V_5 . time = V_38 ;
F_31 ( V_466 , V_2 ) ;
if ( ! ( V_38 & 1 ) )
break;
V_465 = V_38 & ~ ( V_393 | 1 ) ;
if ( F_201 ( V_2 -> V_102 ,
& V_2 -> V_5 . V_338 , V_38 & ~ 1ULL ,
sizeof( struct V_326 ) ) )
V_2 -> V_5 . V_332 = false ;
else
V_2 -> V_5 . V_332 = true ;
break;
}
case V_467 :
if ( F_200 ( V_2 , V_38 ) )
return 1 ;
break;
case V_468 :
if ( F_151 ( ! F_209 () ) )
return 1 ;
if ( V_38 & V_469 )
return 1 ;
if ( F_201 ( V_2 -> V_102 , & V_2 -> V_5 . V_431 . V_437 ,
V_38 & V_470 ,
sizeof( struct V_439 ) ) )
return 1 ;
V_2 -> V_5 . V_431 . V_427 = V_38 ;
if ( ! ( V_38 & V_419 ) )
break;
V_2 -> V_5 . V_431 . V_435 = V_432 -> V_433 . V_434 ;
F_210 () ;
F_204 ( V_2 ) ;
F_211 () ;
F_31 ( V_471 , V_2 ) ;
break;
case V_472 :
if ( F_197 ( V_2 , V_38 ) )
return 1 ;
break;
case V_380 :
case V_378 :
case V_383 ... F_182 ( V_473 ) - 1 :
return F_181 ( V_2 , V_21 , V_38 ) ;
case V_474 :
case V_475 :
case V_476 :
case V_477 :
if ( V_38 != 0 )
F_195 ( V_2 , L_13
L_14 , V_21 , V_38 ) ;
break;
case V_478 :
case V_479 :
case V_480 :
case V_481 :
F_195 ( V_2 , L_13
L_14 , V_21 , V_38 ) ;
break;
case V_482 :
case V_483 :
V_440 = true ;
case V_484 :
case V_485 :
if ( F_212 ( V_2 , V_21 ) )
return F_213 ( V_2 , V_33 ) ;
if ( V_440 || V_38 != 0 )
F_195 ( V_2 , L_15
L_14 , V_21 , V_38 ) ;
break;
case V_486 :
break;
case V_401 ... V_487 :
if ( F_189 ( V_21 ) ) {
int V_120 ;
F_214 ( & V_2 -> V_102 -> V_488 ) ;
V_120 = F_190 ( V_2 , V_21 , V_38 ) ;
F_215 ( & V_2 -> V_102 -> V_488 ) ;
return V_120 ;
} else
return F_196 ( V_2 , V_21 , V_38 ) ;
break;
case V_489 :
F_195 ( V_2 , L_16 , V_21 , V_38 ) ;
break;
case V_490 :
if ( ! F_216 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_491 . V_492 = V_38 ;
break;
case V_493 :
if ( ! F_216 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_491 . V_494 = V_38 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_102 -> V_5 . F_183 . V_21 ) )
return F_183 ( V_2 , V_38 ) ;
if ( F_212 ( V_2 , V_21 ) )
return F_213 ( V_2 , V_33 ) ;
if ( ! V_495 ) {
F_195 ( V_2 , L_17 ,
V_21 , V_38 ) ;
return 1 ;
} else {
F_195 ( V_2 , L_16 ,
V_21 , V_38 ) ;
break;
}
}
return 0 ;
}
int F_217 ( struct V_1 * V_2 , T_1 V_496 , T_2 * V_497 )
{
return V_73 -> V_498 ( V_2 , V_496 , V_497 ) ;
}
static int F_218 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_497 )
{
T_2 * V_364 = ( T_2 * ) & V_2 -> V_5 . V_365 . V_366 ;
if ( ! F_176 ( V_21 ) )
return 1 ;
if ( V_21 == V_362 )
* V_497 = V_2 -> V_5 . V_365 . V_367 +
( V_2 -> V_5 . V_365 . V_368 << 10 ) ;
else if ( V_21 == V_351 )
* V_497 = V_364 [ 0 ] ;
else if ( V_21 == V_352 || V_21 == V_353 )
* V_497 = V_364 [ 1 + V_21 - V_352 ] ;
else if ( V_21 >= V_354 && V_21 <= V_361 )
* V_497 = V_364 [ 3 + V_21 - V_354 ] ;
else if ( V_21 == V_363 )
* V_497 = V_2 -> V_5 . V_369 ;
else {
int V_370 , V_371 ;
T_2 * V_372 ;
V_370 = ( V_21 - 0x200 ) / 2 ;
V_371 = V_21 - 0x200 - 2 * V_370 ;
if ( ! V_371 )
V_372 =
( T_2 * ) & V_2 -> V_5 . V_365 . V_373 [ V_370 ] . V_374 ;
else
V_372 =
( T_2 * ) & V_2 -> V_5 . V_365 . V_373 [ V_370 ] . V_375 ;
* V_497 = * V_372 ;
}
return 0 ;
}
static int F_219 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_497 )
{
T_2 V_38 ;
T_2 V_376 = V_2 -> V_5 . V_376 ;
unsigned V_377 = V_376 & 0xff ;
switch ( V_21 ) {
case V_499 :
case V_500 :
V_38 = 0 ;
break;
case V_501 :
V_38 = V_2 -> V_5 . V_376 ;
break;
case V_380 :
if ( ! ( V_376 & V_381 ) )
return 1 ;
V_38 = V_2 -> V_5 . V_382 ;
break;
case V_378 :
V_38 = V_2 -> V_5 . V_379 ;
break;
default:
if ( V_21 >= V_383 &&
V_21 < F_182 ( V_377 ) ) {
T_1 V_94 = V_21 - V_383 ;
V_38 = V_2 -> V_5 . V_384 [ V_94 ] ;
break;
}
return 1 ;
}
* V_497 = V_38 ;
return 0 ;
}
static int F_220 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_497 )
{
T_2 V_38 = 0 ;
struct V_102 * V_102 = V_2 -> V_102 ;
switch ( V_21 ) {
case V_401 :
V_38 = V_102 -> V_5 . V_405 ;
break;
case V_402 :
V_38 = V_102 -> V_5 . V_399 ;
break;
case V_404 : {
V_38 =
F_221 ( F_125 () + V_102 -> V_5 . V_240 , 100 ) ;
break;
}
case V_403 :
V_38 = V_102 -> V_5 . V_412 ;
break;
default:
F_195 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_497 = V_38 ;
return 0 ;
}
static int F_222 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_497 )
{
T_2 V_38 = 0 ;
switch ( V_21 ) {
case V_502 : {
int V_120 ;
struct V_1 * V_262 ;
F_159 (r, v, vcpu->kvm) {
if ( V_262 == V_2 ) {
V_38 = V_120 ;
break;
}
}
break;
}
case V_420 :
return F_223 ( V_2 , V_421 , V_497 ) ;
case V_422 :
return F_223 ( V_2 , V_423 , V_497 ) ;
case V_424 :
return F_223 ( V_2 , V_425 , V_497 ) ;
case V_415 :
V_38 = V_2 -> V_5 . V_417 ;
break;
default:
F_195 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_497 = V_38 ;
return 0 ;
}
int F_224 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_497 )
{
T_2 V_38 ;
switch ( V_21 ) {
case V_503 :
case V_504 :
case V_450 :
case V_505 :
case V_506 :
case V_507 :
case V_508 :
case V_509 :
case V_448 :
case V_444 :
case V_474 :
case V_475 :
case V_476 :
case V_477 :
case V_478 :
case V_479 :
case V_480 :
case V_481 :
case V_510 :
case V_441 :
case V_449 :
case V_446 :
V_38 = 0 ;
break;
case V_482 :
case V_483 :
case V_484 :
case V_485 :
if ( F_212 ( V_2 , V_21 ) )
return F_225 ( V_2 , V_21 , V_497 ) ;
V_38 = 0 ;
break;
case V_442 :
V_38 = 0x100000000ULL ;
break;
case V_511 :
V_38 = 0x500 | V_350 ;
break;
case 0x200 ... 0x2ff :
return F_218 ( V_2 , V_21 , V_497 ) ;
case 0xcd :
V_38 = 3 ;
break;
case V_512 :
V_38 = 1 << 24 ;
break;
case V_453 :
V_38 = F_20 ( V_2 ) ;
break;
case V_454 ... V_454 + 0x3ff :
return F_226 ( V_2 , V_21 , V_497 ) ;
break;
case V_455 :
V_38 = F_227 ( V_2 ) ;
break;
case V_456 :
V_38 = ( T_2 ) V_2 -> V_5 . V_288 ;
break;
case V_459 :
V_38 = V_2 -> V_5 . V_460 ;
break;
case V_513 :
V_38 = 1000ULL ;
V_38 |= ( ( ( T_9 ) 4ULL ) << 40 ) ;
break;
case V_447 :
V_38 = V_2 -> V_5 . V_131 ;
break;
case V_462 :
case V_461 :
V_38 = V_2 -> V_102 -> V_5 . V_234 ;
break;
case V_464 :
case V_463 :
V_38 = V_2 -> V_5 . time ;
break;
case V_467 :
V_38 = V_2 -> V_5 . V_6 . V_427 ;
break;
case V_468 :
V_38 = V_2 -> V_5 . V_431 . V_427 ;
break;
case V_472 :
V_38 = V_2 -> V_5 . V_514 . V_427 ;
break;
case V_499 :
case V_500 :
case V_501 :
case V_380 :
case V_378 :
case V_383 ... F_182 ( V_473 ) - 1 :
return F_219 ( V_2 , V_21 , V_497 ) ;
case V_486 :
V_38 = 0x20000000 ;
break;
case V_401 ... V_487 :
if ( F_189 ( V_21 ) ) {
int V_120 ;
F_214 ( & V_2 -> V_102 -> V_488 ) ;
V_120 = F_220 ( V_2 , V_21 , V_497 ) ;
F_215 ( & V_2 -> V_102 -> V_488 ) ;
return V_120 ;
} else
return F_222 ( V_2 , V_21 , V_497 ) ;
break;
case V_489 :
V_38 = 0xbe702111 ;
break;
case V_490 :
if ( ! F_216 ( V_2 ) )
return 1 ;
V_38 = V_2 -> V_5 . V_491 . V_492 ;
break;
case V_493 :
if ( ! F_216 ( V_2 ) )
return 1 ;
V_38 = V_2 -> V_5 . V_491 . V_494 ;
break;
default:
if ( F_212 ( V_2 , V_21 ) )
return F_225 ( V_2 , V_21 , V_497 ) ;
if ( ! V_495 ) {
F_195 ( V_2 , L_19 , V_21 ) ;
return 1 ;
} else {
F_195 ( V_2 , L_20 , V_21 ) ;
V_38 = 0 ;
}
break;
}
* V_497 = V_38 ;
return 0 ;
}
static int F_228 ( struct V_1 * V_2 , struct V_515 * V_19 ,
struct V_516 * V_517 ,
int (* F_229)( struct V_1 * V_2 ,
unsigned V_144 , T_2 * V_38 ) )
{
int V_3 , V_370 ;
V_370 = F_230 ( & V_2 -> V_102 -> V_518 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_519 ; ++ V_3 )
if ( F_229 ( V_2 , V_517 [ V_3 ] . V_144 , & V_517 [ V_3 ] . V_38 ) )
break;
F_231 ( & V_2 -> V_102 -> V_518 , V_370 ) ;
return V_3 ;
}
static int F_232 ( struct V_1 * V_2 , struct V_515 V_410 * V_520 ,
int (* F_229)( struct V_1 * V_2 ,
unsigned V_144 , T_2 * V_38 ) ,
int V_521 )
{
struct V_515 V_19 ;
struct V_516 * V_517 ;
int V_120 , V_522 ;
unsigned V_523 ;
V_120 = - V_101 ;
if ( F_233 ( & V_19 , V_520 , sizeof V_19 ) )
goto V_114;
V_120 = - V_396 ;
if ( V_19 . V_519 >= V_524 )
goto V_114;
V_523 = sizeof( struct V_516 ) * V_19 . V_519 ;
V_517 = F_184 ( V_520 -> V_517 , V_523 ) ;
if ( F_185 ( V_517 ) ) {
V_120 = F_186 ( V_517 ) ;
goto V_114;
}
V_120 = V_522 = F_228 ( V_2 , & V_19 , V_517 , F_229 ) ;
if ( V_120 < 0 )
goto V_398;
V_120 = - V_101 ;
if ( V_521 && F_234 ( V_520 -> V_517 , V_517 , V_523 ) )
goto V_398;
V_120 = V_522 ;
V_398:
F_187 ( V_517 ) ;
V_114:
return V_120 ;
}
int F_235 ( struct V_102 * V_102 , long V_525 )
{
int V_120 ;
switch ( V_525 ) {
case V_526 :
case V_527 :
case V_528 :
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
#ifdef F_236
case V_562 :
case V_563 :
#endif
V_120 = 1 ;
break;
case V_564 :
V_120 = V_565 ;
break;
case V_566 :
V_120 = ! V_73 -> V_567 () ;
break;
case V_568 :
V_120 = V_569 ;
break;
case V_570 :
V_120 = V_571 ;
break;
case V_572 :
V_120 = V_573 ;
break;
case V_574 :
V_120 = 0 ;
break;
#ifdef F_236
case V_575 :
V_120 = F_237 ( & V_576 ) ;
break;
#endif
case V_577 :
V_120 = V_473 ;
break;
case V_578 :
V_120 = V_579 ;
break;
case V_580 :
V_120 = V_581 ;
break;
case V_582 :
V_120 = F_238 ( V_583 ) ;
break;
default:
V_120 = 0 ;
break;
}
return V_120 ;
}
long F_239 ( struct V_584 * V_585 ,
unsigned int V_586 , unsigned long V_587 )
{
void V_410 * V_588 = ( void V_410 * ) V_587 ;
long V_120 ;
switch ( V_586 ) {
case V_589 : {
struct V_590 V_410 * V_591 = V_588 ;
struct V_590 V_592 ;
unsigned V_522 ;
V_120 = - V_101 ;
if ( F_233 ( & V_592 , V_591 , sizeof V_592 ) )
goto V_114;
V_522 = V_592 . V_519 ;
V_592 . V_519 = V_593 + F_53 ( V_594 ) ;
if ( F_234 ( V_591 , & V_592 , sizeof V_592 ) )
goto V_114;
V_120 = - V_396 ;
if ( V_522 < V_592 . V_519 )
goto V_114;
V_120 = - V_101 ;
if ( F_234 ( V_591 -> V_595 , & V_596 ,
V_593 * sizeof( T_1 ) ) )
goto V_114;
if ( F_234 ( V_591 -> V_595 + V_593 ,
& V_594 ,
F_53 ( V_594 ) * sizeof( T_1 ) ) )
goto V_114;
V_120 = 0 ;
break;
}
case V_597 :
case V_598 : {
struct V_599 V_410 * V_600 = V_588 ;
struct V_599 V_601 ;
V_120 = - V_101 ;
if ( F_233 ( & V_601 , V_600 , sizeof V_601 ) )
goto V_114;
V_120 = F_240 ( & V_601 , V_600 -> V_517 ,
V_586 ) ;
if ( V_120 )
goto V_114;
V_120 = - V_101 ;
if ( F_234 ( V_600 , & V_601 , sizeof V_601 ) )
goto V_114;
V_120 = 0 ;
break;
}
case V_602 : {
T_2 V_603 ;
V_603 = V_604 ;
V_120 = - V_101 ;
if ( F_234 ( V_588 , & V_603 , sizeof V_603 ) )
goto V_114;
V_120 = 0 ;
break;
}
default:
V_120 = - V_605 ;
}
V_114:
return V_120 ;
}
static void F_241 ( void * V_606 )
{
F_242 () ;
}
static bool F_243 ( struct V_1 * V_2 )
{
return F_244 ( V_2 -> V_102 ) ;
}
void F_245 ( struct V_1 * V_2 , int V_23 )
{
if ( F_243 ( V_2 ) ) {
if ( V_73 -> V_607 () )
F_246 ( V_23 , V_2 -> V_5 . V_608 ) ;
else if ( V_2 -> V_23 != - 1 && V_2 -> V_23 != V_23 )
F_247 ( V_2 -> V_23 ,
F_241 , NULL , 1 ) ;
}
V_73 -> V_609 ( V_2 , V_23 ) ;
if ( F_151 ( V_2 -> V_5 . V_610 ) ) {
F_248 ( V_2 , V_2 -> V_5 . V_610 ) ;
V_2 -> V_5 . V_610 = 0 ;
F_31 ( V_320 , V_2 ) ;
}
if ( F_151 ( V_2 -> V_23 != V_23 ) || F_139 () ) {
T_12 V_611 = ! V_2 -> V_5 . V_612 ? 0 :
F_165 () - V_2 -> V_5 . V_612 ;
if ( V_611 < 0 )
F_249 ( L_21 ) ;
if ( F_139 () ) {
T_2 V_94 = V_73 -> V_296 ( V_2 ,
V_2 -> V_5 . V_308 ) ;
V_73 -> V_309 ( V_2 , V_94 ) ;
V_2 -> V_5 . V_331 = 1 ;
}
if ( ! V_2 -> V_102 -> V_5 . V_282 || V_2 -> V_23 == - 1 )
F_31 ( V_466 , V_2 ) ;
if ( V_2 -> V_23 != V_23 )
F_250 ( V_2 ) ;
V_2 -> V_23 = V_23 ;
}
F_204 ( V_2 ) ;
F_31 ( V_471 , V_2 ) ;
}
void F_251 ( struct V_1 * V_2 )
{
V_73 -> V_613 ( V_2 ) ;
F_252 ( V_2 ) ;
V_2 -> V_5 . V_612 = F_165 () ;
}
static int F_253 ( struct V_1 * V_2 ,
struct V_614 * V_615 )
{
V_73 -> V_616 ( V_2 ) ;
memcpy ( V_615 -> V_617 , V_2 -> V_5 . V_618 -> V_617 , sizeof *V_615 ) ;
return 0 ;
}
static int F_254 ( struct V_1 * V_2 ,
struct V_614 * V_615 )
{
F_255 ( V_2 , V_615 ) ;
F_256 ( V_2 ) ;
return 0 ;
}
static int F_257 ( struct V_1 * V_2 ,
struct V_619 * V_620 )
{
if ( V_620 -> V_620 >= V_621 )
return - V_605 ;
if ( F_87 ( V_2 -> V_102 ) )
return - V_622 ;
F_258 ( V_2 , V_620 -> V_620 , false ) ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
static int F_259 ( struct V_1 * V_2 )
{
F_41 ( V_2 ) ;
return 0 ;
}
static int F_260 ( struct V_1 * V_2 ,
struct V_623 * V_624 )
{
if ( V_624 -> V_291 )
return - V_605 ;
V_2 -> V_5 . V_625 = ! ! V_624 -> V_368 ;
return 0 ;
}
static int F_261 ( struct V_1 * V_2 ,
T_2 V_376 )
{
int V_120 ;
unsigned V_377 = V_376 & 0xff , V_626 ;
V_120 = - V_605 ;
if ( ! V_377 || V_377 >= V_473 )
goto V_114;
if ( V_376 & ~ ( V_604 | 0xff | 0xff0000 ) )
goto V_114;
V_120 = 0 ;
V_2 -> V_5 . V_376 = V_376 ;
if ( V_376 & V_381 )
V_2 -> V_5 . V_382 = ~ ( T_2 ) 0 ;
for ( V_626 = 0 ; V_626 < V_377 ; V_626 ++ )
V_2 -> V_5 . V_384 [ V_626 * 4 ] = ~ ( T_2 ) 0 ;
V_114:
return V_120 ;
}
static int F_262 ( struct V_1 * V_2 ,
struct V_627 * V_628 )
{
T_2 V_376 = V_2 -> V_5 . V_376 ;
unsigned V_377 = V_376 & 0xff ;
T_2 * V_629 = V_2 -> V_5 . V_384 ;
if ( V_628 -> V_626 >= V_377 || ! ( V_628 -> V_494 & V_630 ) )
return - V_605 ;
if ( ( V_628 -> V_494 & V_631 ) && ( V_376 & V_381 ) &&
V_2 -> V_5 . V_382 != ~ ( T_2 ) 0 )
return 0 ;
V_629 += 4 * V_628 -> V_626 ;
if ( ( V_628 -> V_494 & V_631 ) && V_629 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_628 -> V_494 & V_631 ) {
if ( ( V_2 -> V_5 . V_379 & V_632 ) ||
! F_46 ( V_2 , V_633 ) ) {
F_31 ( V_72 , V_2 ) ;
return 0 ;
}
if ( V_629 [ 1 ] & V_630 )
V_628 -> V_494 |= V_634 ;
V_629 [ 2 ] = V_628 -> V_406 ;
V_629 [ 3 ] = V_628 -> V_635 ;
V_2 -> V_5 . V_379 = V_628 -> V_379 ;
V_629 [ 1 ] = V_628 -> V_494 ;
F_33 ( V_2 , V_58 ) ;
} else if ( ! ( V_629 [ 1 ] & V_630 )
|| ! ( V_629 [ 1 ] & V_631 ) ) {
if ( V_629 [ 1 ] & V_630 )
V_628 -> V_494 |= V_634 ;
V_629 [ 2 ] = V_628 -> V_406 ;
V_629 [ 3 ] = V_628 -> V_635 ;
V_629 [ 1 ] = V_628 -> V_494 ;
} else
V_629 [ 1 ] |= V_634 ;
return 0 ;
}
static void F_263 ( struct V_1 * V_2 ,
struct V_636 * V_637 )
{
F_264 ( V_2 ) ;
V_637 -> V_68 . V_638 =
V_2 -> V_5 . V_68 . V_69 &&
! F_265 ( V_2 -> V_5 . V_68 . V_16 ) ;
V_637 -> V_68 . V_16 = V_2 -> V_5 . V_68 . V_16 ;
V_637 -> V_68 . V_71 = V_2 -> V_5 . V_68 . V_71 ;
V_637 -> V_68 . V_639 = 0 ;
V_637 -> V_68 . V_62 = V_2 -> V_5 . V_68 . V_62 ;
V_637 -> V_640 . V_638 =
V_2 -> V_5 . V_640 . V_69 && ! V_2 -> V_5 . V_640 . V_641 ;
V_637 -> V_640 . V_16 = V_2 -> V_5 . V_640 . V_16 ;
V_637 -> V_640 . V_641 = 0 ;
V_637 -> V_640 . V_642 = V_73 -> V_643 ( V_2 ) ;
V_637 -> V_644 . V_638 = V_2 -> V_5 . V_645 ;
V_637 -> V_644 . V_69 = V_2 -> V_5 . V_646 != 0 ;
V_637 -> V_644 . V_647 = V_73 -> V_648 ( V_2 ) ;
V_637 -> V_644 . V_639 = 0 ;
V_637 -> V_649 = 0 ;
V_637 -> V_291 = ( V_650
| V_651 ) ;
memset ( & V_637 -> V_652 , 0 , sizeof( V_637 -> V_652 ) ) ;
}
static int F_266 ( struct V_1 * V_2 ,
struct V_636 * V_637 )
{
if ( V_637 -> V_291 & ~ ( V_650
| V_653
| V_651 ) )
return - V_605 ;
F_264 ( V_2 ) ;
V_2 -> V_5 . V_68 . V_69 = V_637 -> V_68 . V_638 ;
V_2 -> V_5 . V_68 . V_16 = V_637 -> V_68 . V_16 ;
V_2 -> V_5 . V_68 . V_71 = V_637 -> V_68 . V_71 ;
V_2 -> V_5 . V_68 . V_62 = V_637 -> V_68 . V_62 ;
V_2 -> V_5 . V_640 . V_69 = V_637 -> V_640 . V_638 ;
V_2 -> V_5 . V_640 . V_16 = V_637 -> V_640 . V_16 ;
V_2 -> V_5 . V_640 . V_641 = V_637 -> V_640 . V_641 ;
if ( V_637 -> V_291 & V_651 )
V_73 -> V_654 ( V_2 ,
V_637 -> V_640 . V_642 ) ;
V_2 -> V_5 . V_645 = V_637 -> V_644 . V_638 ;
if ( V_637 -> V_291 & V_650 )
V_2 -> V_5 . V_646 = V_637 -> V_644 . V_69 ;
V_73 -> V_655 ( V_2 , V_637 -> V_644 . V_647 ) ;
if ( V_637 -> V_291 & V_653 &&
F_267 ( V_2 ) )
V_2 -> V_5 . V_618 -> V_649 = V_637 -> V_649 ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
static void F_268 ( struct V_1 * V_2 ,
struct V_656 * V_657 )
{
unsigned long V_188 ;
memcpy ( V_657 -> V_189 , V_2 -> V_5 . V_189 , sizeof( V_2 -> V_5 . V_189 ) ) ;
F_97 ( V_2 , 6 , & V_188 ) ;
V_657 -> V_178 = V_188 ;
V_657 -> V_179 = V_2 -> V_5 . V_179 ;
V_657 -> V_291 = 0 ;
memset ( & V_657 -> V_652 , 0 , sizeof( V_657 -> V_652 ) ) ;
}
static int F_269 ( struct V_1 * V_2 ,
struct V_656 * V_657 )
{
if ( V_657 -> V_291 )
return - V_605 ;
memcpy ( V_2 -> V_5 . V_189 , V_657 -> V_189 , sizeof( V_2 -> V_5 . V_189 ) ) ;
V_2 -> V_5 . V_178 = V_657 -> V_178 ;
F_91 ( V_2 ) ;
V_2 -> V_5 . V_179 = V_657 -> V_179 ;
F_92 ( V_2 ) ;
return 0 ;
}
static void F_270 ( T_14 * V_658 , struct V_1 * V_2 )
{
struct V_659 * V_660 = & V_2 -> V_5 . V_661 . V_662 -> V_660 ;
T_2 V_663 = V_660 -> V_664 . V_663 ;
T_2 V_665 ;
memcpy ( V_658 , V_660 , V_666 ) ;
* ( T_2 * ) ( V_658 + V_666 ) = V_663 ;
V_665 = V_663 & ~ V_667 ;
while ( V_665 ) {
T_2 V_668 = V_665 & - V_665 ;
int V_144 = F_271 ( V_668 ) - 1 ;
void * V_669 = F_272 ( V_660 , V_668 ) ;
if ( V_669 ) {
T_1 V_523 , V_94 , V_195 , V_203 ;
F_273 ( V_670 , V_144 ,
& V_523 , & V_94 , & V_195 , & V_203 ) ;
memcpy ( V_658 + V_94 , V_669 , V_523 ) ;
}
V_665 -= V_668 ;
}
}
static void F_274 ( struct V_1 * V_2 , T_14 * V_669 )
{
struct V_659 * V_660 = & V_2 -> V_5 . V_661 . V_662 -> V_660 ;
T_2 V_663 = * ( T_2 * ) ( V_669 + V_666 ) ;
T_2 V_665 ;
memcpy ( V_660 , V_669 , V_666 ) ;
V_660 -> V_664 . V_663 = V_663 ;
if ( V_671 )
V_660 -> V_664 . V_672 = V_143 | V_673 ;
V_665 = V_663 & ~ V_667 ;
while ( V_665 ) {
T_2 V_668 = V_665 & - V_665 ;
int V_144 = F_271 ( V_668 ) - 1 ;
void * V_658 = F_272 ( V_660 , V_668 ) ;
if ( V_658 ) {
T_1 V_523 , V_94 , V_195 , V_203 ;
F_273 ( V_670 , V_144 ,
& V_523 , & V_94 , & V_195 , & V_203 ) ;
memcpy ( V_658 , V_669 + V_94 , V_523 ) ;
} else
F_275 ( 1 ) ;
V_665 -= V_668 ;
}
}
static void F_276 ( struct V_1 * V_2 ,
struct V_674 * V_675 )
{
if ( V_579 ) {
memset ( V_675 , 0 , sizeof( struct V_674 ) ) ;
F_270 ( ( T_14 * ) V_675 -> V_676 , V_2 ) ;
} else {
memcpy ( V_675 -> V_676 ,
& V_2 -> V_5 . V_661 . V_662 -> V_677 ,
sizeof( struct V_678 ) ) ;
* ( T_2 * ) & V_675 -> V_676 [ V_666 / sizeof( T_1 ) ] =
V_667 ;
}
}
static int F_277 ( struct V_1 * V_2 ,
struct V_674 * V_675 )
{
T_2 V_663 =
* ( T_2 * ) & V_675 -> V_676 [ V_666 / sizeof( T_1 ) ] ;
if ( V_579 ) {
if ( V_663 & ~ F_278 () )
return - V_605 ;
F_274 ( V_2 , ( T_14 * ) V_675 -> V_676 ) ;
} else {
if ( V_663 & ~ V_667 )
return - V_605 ;
memcpy ( & V_2 -> V_5 . V_661 . V_662 -> V_677 ,
V_675 -> V_676 , sizeof( struct V_678 ) ) ;
}
return 0 ;
}
static void F_279 ( struct V_1 * V_2 ,
struct V_679 * V_680 )
{
if ( ! V_579 ) {
V_680 -> V_681 = 0 ;
return;
}
V_680 -> V_681 = 1 ;
V_680 -> V_291 = 0 ;
V_680 -> V_682 [ 0 ] . V_145 = V_141 ;
V_680 -> V_682 [ 0 ] . V_22 = V_2 -> V_5 . V_142 ;
}
static int F_280 ( struct V_1 * V_2 ,
struct V_679 * V_680 )
{
int V_3 , V_120 = 0 ;
if ( ! V_579 )
return - V_605 ;
if ( V_680 -> V_681 > V_683 || V_680 -> V_291 )
return - V_605 ;
for ( V_3 = 0 ; V_3 < V_680 -> V_681 ; V_3 ++ )
if ( V_680 -> V_682 [ V_3 ] . V_145 == V_141 ) {
V_120 = F_72 ( V_2 , V_141 ,
V_680 -> V_682 [ V_3 ] . V_22 ) ;
break;
}
if ( V_120 )
V_120 = - V_605 ;
return V_120 ;
}
static int F_281 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_332 )
return - V_605 ;
V_2 -> V_5 . V_340 = true ;
F_31 ( V_320 , V_2 ) ;
return 0 ;
}
long F_282 ( struct V_584 * V_585 ,
unsigned int V_586 , unsigned long V_587 )
{
struct V_1 * V_2 = V_585 -> V_684 ;
void V_410 * V_588 = ( void V_410 * ) V_587 ;
int V_120 ;
union {
struct V_614 * V_685 ;
struct V_674 * V_660 ;
struct V_679 * V_682 ;
void * V_686 ;
} V_687 ;
V_687 . V_686 = NULL ;
switch ( V_586 ) {
case V_688 : {
V_120 = - V_605 ;
if ( ! V_2 -> V_5 . V_618 )
goto V_114;
V_687 . V_685 = F_283 ( sizeof( struct V_614 ) , V_689 ) ;
V_120 = - V_397 ;
if ( ! V_687 . V_685 )
goto V_114;
V_120 = F_253 ( V_2 , V_687 . V_685 ) ;
if ( V_120 )
goto V_114;
V_120 = - V_101 ;
if ( F_234 ( V_588 , V_687 . V_685 , sizeof( struct V_614 ) ) )
goto V_114;
V_120 = 0 ;
break;
}
case V_690 : {
V_120 = - V_605 ;
if ( ! V_2 -> V_5 . V_618 )
goto V_114;
V_687 . V_685 = F_184 ( V_588 , sizeof( * V_687 . V_685 ) ) ;
if ( F_185 ( V_687 . V_685 ) )
return F_186 ( V_687 . V_685 ) ;
V_120 = F_254 ( V_2 , V_687 . V_685 ) ;
break;
}
case V_691 : {
struct V_619 V_620 ;
V_120 = - V_101 ;
if ( F_233 ( & V_620 , V_588 , sizeof V_620 ) )
goto V_114;
V_120 = F_257 ( V_2 , & V_620 ) ;
break;
}
case V_692 : {
V_120 = F_259 ( V_2 ) ;
break;
}
case V_693 : {
struct V_694 V_410 * V_600 = V_588 ;
struct V_694 V_601 ;
V_120 = - V_101 ;
if ( F_233 ( & V_601 , V_600 , sizeof V_601 ) )
goto V_114;
V_120 = F_284 ( V_2 , & V_601 , V_600 -> V_517 ) ;
break;
}
case V_695 : {
struct V_599 V_410 * V_600 = V_588 ;
struct V_599 V_601 ;
V_120 = - V_101 ;
if ( F_233 ( & V_601 , V_600 , sizeof V_601 ) )
goto V_114;
V_120 = F_285 ( V_2 , & V_601 ,
V_600 -> V_517 ) ;
break;
}
case V_696 : {
struct V_599 V_410 * V_600 = V_588 ;
struct V_599 V_601 ;
V_120 = - V_101 ;
if ( F_233 ( & V_601 , V_600 , sizeof V_601 ) )
goto V_114;
V_120 = F_286 ( V_2 , & V_601 ,
V_600 -> V_517 ) ;
if ( V_120 )
goto V_114;
V_120 = - V_101 ;
if ( F_234 ( V_600 , & V_601 , sizeof V_601 ) )
goto V_114;
V_120 = 0 ;
break;
}
case V_697 :
V_120 = F_232 ( V_2 , V_588 , F_217 , 1 ) ;
break;
case V_698 :
V_120 = F_232 ( V_2 , V_588 , F_110 , 0 ) ;
break;
case V_699 : {
struct V_623 V_624 ;
V_120 = - V_101 ;
if ( F_233 ( & V_624 , V_588 , sizeof V_624 ) )
goto V_114;
V_120 = F_260 ( V_2 , & V_624 ) ;
if ( V_120 )
goto V_114;
V_120 = - V_101 ;
if ( F_234 ( V_588 , & V_624 , sizeof V_624 ) )
goto V_114;
V_120 = 0 ;
break;
} ;
case V_700 : {
struct V_701 V_702 ;
V_120 = - V_605 ;
if ( ! F_87 ( V_2 -> V_102 ) )
goto V_114;
V_120 = - V_101 ;
if ( F_233 ( & V_702 , V_588 , sizeof V_702 ) )
goto V_114;
V_120 = F_287 ( V_2 , V_702 . V_703 ) ;
break;
}
case V_704 : {
T_2 V_376 ;
V_120 = - V_101 ;
if ( F_233 ( & V_376 , V_588 , sizeof V_376 ) )
goto V_114;
V_120 = F_261 ( V_2 , V_376 ) ;
break;
}
case V_705 : {
struct V_627 V_628 ;
V_120 = - V_101 ;
if ( F_233 ( & V_628 , V_588 , sizeof V_628 ) )
goto V_114;
V_120 = F_262 ( V_2 , & V_628 ) ;
break;
}
case V_706 : {
struct V_636 V_637 ;
F_263 ( V_2 , & V_637 ) ;
V_120 = - V_101 ;
if ( F_234 ( V_588 , & V_637 , sizeof( struct V_636 ) ) )
break;
V_120 = 0 ;
break;
}
case V_707 : {
struct V_636 V_637 ;
V_120 = - V_101 ;
if ( F_233 ( & V_637 , V_588 , sizeof( struct V_636 ) ) )
break;
V_120 = F_266 ( V_2 , & V_637 ) ;
break;
}
case V_708 : {
struct V_656 V_657 ;
F_268 ( V_2 , & V_657 ) ;
V_120 = - V_101 ;
if ( F_234 ( V_588 , & V_657 ,
sizeof( struct V_656 ) ) )
break;
V_120 = 0 ;
break;
}
case V_709 : {
struct V_656 V_657 ;
V_120 = - V_101 ;
if ( F_233 ( & V_657 , V_588 ,
sizeof( struct V_656 ) ) )
break;
V_120 = F_269 ( V_2 , & V_657 ) ;
break;
}
case V_710 : {
V_687 . V_660 = F_283 ( sizeof( struct V_674 ) , V_689 ) ;
V_120 = - V_397 ;
if ( ! V_687 . V_660 )
break;
F_276 ( V_2 , V_687 . V_660 ) ;
V_120 = - V_101 ;
if ( F_234 ( V_588 , V_687 . V_660 , sizeof( struct V_674 ) ) )
break;
V_120 = 0 ;
break;
}
case V_711 : {
V_687 . V_660 = F_184 ( V_588 , sizeof( * V_687 . V_660 ) ) ;
if ( F_185 ( V_687 . V_660 ) )
return F_186 ( V_687 . V_660 ) ;
V_120 = F_277 ( V_2 , V_687 . V_660 ) ;
break;
}
case V_712 : {
V_687 . V_682 = F_283 ( sizeof( struct V_679 ) , V_689 ) ;
V_120 = - V_397 ;
if ( ! V_687 . V_682 )
break;
F_279 ( V_2 , V_687 . V_682 ) ;
V_120 = - V_101 ;
if ( F_234 ( V_588 , V_687 . V_682 ,
sizeof( struct V_679 ) ) )
break;
V_120 = 0 ;
break;
}
case V_713 : {
V_687 . V_682 = F_184 ( V_588 , sizeof( * V_687 . V_682 ) ) ;
if ( F_185 ( V_687 . V_682 ) )
return F_186 ( V_687 . V_682 ) ;
V_120 = F_280 ( V_2 , V_687 . V_682 ) ;
break;
}
case V_714 : {
T_1 V_715 ;
V_120 = - V_605 ;
V_715 = ( T_1 ) V_587 ;
if ( V_715 >= V_716 )
goto V_114;
if ( V_715 == 0 )
V_715 = V_269 ;
F_131 ( V_2 , V_715 ) ;
V_120 = 0 ;
goto V_114;
}
case V_717 : {
V_120 = V_2 -> V_5 . V_268 ;
goto V_114;
}
case V_718 : {
V_120 = F_281 ( V_2 ) ;
goto V_114;
}
default:
V_120 = - V_605 ;
}
V_114:
F_187 ( V_687 . V_686 ) ;
return V_120 ;
}
int F_288 ( struct V_1 * V_2 , struct V_719 * V_720 )
{
return V_721 ;
}
static int F_289 ( struct V_102 * V_102 , unsigned long V_406 )
{
int V_109 ;
if ( V_406 > ( unsigned int ) ( - 3 * V_108 ) )
return - V_605 ;
V_109 = V_73 -> V_722 ( V_102 , V_406 ) ;
return V_109 ;
}
static int F_290 ( struct V_102 * V_102 ,
T_2 V_723 )
{
V_102 -> V_5 . V_724 = V_723 ;
return 0 ;
}
static int F_291 ( struct V_102 * V_102 ,
T_1 V_725 )
{
if ( V_725 < V_726 )
return - V_605 ;
F_214 ( & V_102 -> V_727 ) ;
F_292 ( V_102 , V_725 ) ;
V_102 -> V_5 . V_728 = V_725 ;
F_215 ( & V_102 -> V_727 ) ;
return 0 ;
}
static int F_293 ( struct V_102 * V_102 )
{
return V_102 -> V_5 . V_729 ;
}
static int F_294 ( struct V_102 * V_102 , struct V_730 * V_731 )
{
int V_120 ;
V_120 = 0 ;
switch ( V_731 -> V_732 ) {
case V_733 :
memcpy ( & V_731 -> V_731 . V_734 ,
& F_295 ( V_102 ) -> V_735 [ 0 ] ,
sizeof( struct V_736 ) ) ;
break;
case V_737 :
memcpy ( & V_731 -> V_731 . V_734 ,
& F_295 ( V_102 ) -> V_735 [ 1 ] ,
sizeof( struct V_736 ) ) ;
break;
case V_738 :
V_120 = F_296 ( V_102 , & V_731 -> V_731 . V_739 ) ;
break;
default:
V_120 = - V_605 ;
break;
}
return V_120 ;
}
static int F_297 ( struct V_102 * V_102 , struct V_730 * V_731 )
{
int V_120 ;
V_120 = 0 ;
switch ( V_731 -> V_732 ) {
case V_733 :
F_142 ( & F_295 ( V_102 ) -> V_488 ) ;
memcpy ( & F_295 ( V_102 ) -> V_735 [ 0 ] ,
& V_731 -> V_731 . V_734 ,
sizeof( struct V_736 ) ) ;
F_143 ( & F_295 ( V_102 ) -> V_488 ) ;
break;
case V_737 :
F_142 ( & F_295 ( V_102 ) -> V_488 ) ;
memcpy ( & F_295 ( V_102 ) -> V_735 [ 1 ] ,
& V_731 -> V_731 . V_734 ,
sizeof( struct V_736 ) ) ;
F_143 ( & F_295 ( V_102 ) -> V_488 ) ;
break;
case V_738 :
V_120 = F_298 ( V_102 , & V_731 -> V_731 . V_739 ) ;
break;
default:
V_120 = - V_605 ;
break;
}
F_299 ( F_295 ( V_102 ) ) ;
return V_120 ;
}
static int F_300 ( struct V_102 * V_102 , struct V_740 * V_741 )
{
int V_120 = 0 ;
F_214 ( & V_102 -> V_5 . V_742 -> V_743 . V_488 ) ;
memcpy ( V_741 , & V_102 -> V_5 . V_742 -> V_743 , sizeof( struct V_740 ) ) ;
F_215 ( & V_102 -> V_5 . V_742 -> V_743 . V_488 ) ;
return V_120 ;
}
static int F_301 ( struct V_102 * V_102 , struct V_740 * V_741 )
{
int V_120 = 0 ;
F_214 ( & V_102 -> V_5 . V_742 -> V_743 . V_488 ) ;
memcpy ( & V_102 -> V_5 . V_742 -> V_743 , V_741 , sizeof( struct V_740 ) ) ;
F_302 ( V_102 , 0 , V_741 -> V_744 [ 0 ] . V_745 , 0 ) ;
F_215 ( & V_102 -> V_5 . V_742 -> V_743 . V_488 ) ;
return V_120 ;
}
static int F_303 ( struct V_102 * V_102 , struct V_746 * V_741 )
{
int V_120 = 0 ;
F_214 ( & V_102 -> V_5 . V_742 -> V_743 . V_488 ) ;
memcpy ( V_741 -> V_744 , & V_102 -> V_5 . V_742 -> V_743 . V_744 ,
sizeof( V_741 -> V_744 ) ) ;
V_741 -> V_291 = V_102 -> V_5 . V_742 -> V_743 . V_291 ;
F_215 ( & V_102 -> V_5 . V_742 -> V_743 . V_488 ) ;
memset ( & V_741 -> V_652 , 0 , sizeof( V_741 -> V_652 ) ) ;
return V_120 ;
}
static int F_304 ( struct V_102 * V_102 , struct V_746 * V_741 )
{
int V_120 = 0 , V_747 = 0 ;
T_1 V_748 , V_749 ;
F_214 ( & V_102 -> V_5 . V_742 -> V_743 . V_488 ) ;
V_748 = V_102 -> V_5 . V_742 -> V_743 . V_291 & V_750 ;
V_749 = V_741 -> V_291 & V_750 ;
if ( ! V_748 && V_749 )
V_747 = 1 ;
memcpy ( & V_102 -> V_5 . V_742 -> V_743 . V_744 , & V_741 -> V_744 ,
sizeof( V_102 -> V_5 . V_742 -> V_743 . V_744 ) ) ;
V_102 -> V_5 . V_742 -> V_743 . V_291 = V_741 -> V_291 ;
F_302 ( V_102 , 0 , V_102 -> V_5 . V_742 -> V_743 . V_744 [ 0 ] . V_745 , V_747 ) ;
F_215 ( & V_102 -> V_5 . V_742 -> V_743 . V_488 ) ;
return V_120 ;
}
static int F_305 ( struct V_102 * V_102 ,
struct V_751 * V_752 )
{
if ( ! V_102 -> V_5 . V_742 )
return - V_622 ;
F_214 ( & V_102 -> V_5 . V_742 -> V_743 . V_488 ) ;
V_102 -> V_5 . V_742 -> V_743 . V_63 = V_752 -> V_753 ;
F_215 ( & V_102 -> V_5 . V_742 -> V_743 . V_488 ) ;
return 0 ;
}
int F_306 ( struct V_102 * V_102 , struct V_754 * log )
{
int V_120 ;
struct V_755 * V_756 ;
unsigned long V_522 , V_3 ;
unsigned long * V_757 ;
unsigned long * V_758 ;
bool V_759 = false ;
F_214 ( & V_102 -> V_727 ) ;
V_120 = - V_605 ;
if ( log -> V_10 >= V_573 )
goto V_114;
V_756 = F_307 ( V_102 -> V_760 , log -> V_10 ) ;
V_757 = V_756 -> V_757 ;
V_120 = - V_761 ;
if ( ! V_757 )
goto V_114;
V_522 = F_308 ( V_756 ) ;
V_758 = V_757 + V_522 / sizeof( long ) ;
memset ( V_758 , 0 , V_522 ) ;
F_142 ( & V_102 -> V_762 ) ;
for ( V_3 = 0 ; V_3 < V_522 / sizeof( long ) ; V_3 ++ ) {
unsigned long V_28 ;
T_5 V_94 ;
if ( ! V_757 [ V_3 ] )
continue;
V_759 = true ;
V_28 = F_309 ( & V_757 [ V_3 ] , 0 ) ;
V_758 [ V_3 ] = V_28 ;
V_94 = V_3 * V_763 ;
F_310 ( V_102 , V_756 , V_94 , V_28 ) ;
}
F_143 ( & V_102 -> V_762 ) ;
F_311 ( & V_102 -> V_727 ) ;
if ( V_759 )
F_312 ( V_102 ) ;
V_120 = - V_101 ;
if ( F_234 ( log -> V_757 , V_758 , V_522 ) )
goto V_114;
V_120 = 0 ;
V_114:
F_215 ( & V_102 -> V_727 ) ;
return V_120 ;
}
int F_313 ( struct V_102 * V_102 , struct V_764 * V_765 ,
bool V_766 )
{
if ( ! F_87 ( V_102 ) )
return - V_622 ;
V_765 -> V_494 = F_314 ( V_102 , V_767 ,
V_765 -> V_620 , V_765 -> V_768 ,
V_766 ) ;
return 0 ;
}
long F_315 ( struct V_584 * V_585 ,
unsigned int V_586 , unsigned long V_587 )
{
struct V_102 * V_102 = V_585 -> V_684 ;
void V_410 * V_588 = ( void V_410 * ) V_587 ;
int V_120 = - V_769 ;
union {
struct V_740 V_741 ;
struct V_746 V_770 ;
struct V_771 V_772 ;
} V_687 ;
switch ( V_586 ) {
case V_773 :
V_120 = F_289 ( V_102 , V_587 ) ;
break;
case V_774 : {
T_2 V_723 ;
V_120 = - V_101 ;
if ( F_233 ( & V_723 , V_588 , sizeof V_723 ) )
goto V_114;
V_120 = F_290 ( V_102 , V_723 ) ;
break;
}
case V_775 :
V_120 = F_291 ( V_102 , V_587 ) ;
break;
case V_776 :
V_120 = F_293 ( V_102 ) ;
break;
case V_777 : {
struct V_778 * V_779 ;
F_214 ( & V_102 -> V_488 ) ;
V_120 = - V_780 ;
if ( V_102 -> V_5 . V_779 )
goto V_781;
V_120 = - V_605 ;
if ( F_134 ( & V_102 -> V_281 ) )
goto V_781;
V_120 = - V_397 ;
V_779 = F_316 ( V_102 ) ;
if ( V_779 ) {
V_120 = F_317 ( V_102 ) ;
if ( V_120 ) {
F_214 ( & V_102 -> V_727 ) ;
F_318 ( V_102 , V_782 ,
& V_779 -> V_783 ) ;
F_318 ( V_102 , V_782 ,
& V_779 -> V_784 ) ;
F_318 ( V_102 , V_782 ,
& V_779 -> V_785 ) ;
F_215 ( & V_102 -> V_727 ) ;
F_187 ( V_779 ) ;
goto V_781;
}
} else
goto V_781;
F_14 () ;
V_102 -> V_5 . V_779 = V_779 ;
F_14 () ;
V_120 = F_319 ( V_102 ) ;
if ( V_120 ) {
F_214 ( & V_102 -> V_727 ) ;
F_214 ( & V_102 -> V_786 ) ;
F_320 ( V_102 ) ;
F_321 ( V_102 ) ;
F_215 ( & V_102 -> V_786 ) ;
F_215 ( & V_102 -> V_727 ) ;
}
V_781:
F_215 ( & V_102 -> V_488 ) ;
break;
}
case V_787 :
V_687 . V_772 . V_291 = V_788 ;
goto V_789;
case V_790 :
V_120 = - V_101 ;
if ( F_233 ( & V_687 . V_772 , V_588 ,
sizeof( struct V_771 ) ) )
goto V_114;
V_789:
F_214 ( & V_102 -> V_727 ) ;
V_120 = - V_780 ;
if ( V_102 -> V_5 . V_742 )
goto V_791;
V_120 = - V_397 ;
V_102 -> V_5 . V_742 = F_322 ( V_102 , V_687 . V_772 . V_291 ) ;
if ( V_102 -> V_5 . V_742 )
V_120 = 0 ;
V_791:
F_215 ( & V_102 -> V_727 ) ;
break;
case V_792 : {
struct V_730 * V_731 ;
V_731 = F_184 ( V_588 , sizeof( * V_731 ) ) ;
if ( F_185 ( V_731 ) ) {
V_120 = F_186 ( V_731 ) ;
goto V_114;
}
V_120 = - V_622 ;
if ( ! F_87 ( V_102 ) )
goto V_793;
V_120 = F_294 ( V_102 , V_731 ) ;
if ( V_120 )
goto V_793;
V_120 = - V_101 ;
if ( F_234 ( V_588 , V_731 , sizeof *V_731 ) )
goto V_793;
V_120 = 0 ;
V_793:
F_187 ( V_731 ) ;
break;
}
case V_794 : {
struct V_730 * V_731 ;
V_731 = F_184 ( V_588 , sizeof( * V_731 ) ) ;
if ( F_185 ( V_731 ) ) {
V_120 = F_186 ( V_731 ) ;
goto V_114;
}
V_120 = - V_622 ;
if ( ! F_87 ( V_102 ) )
goto V_795;
V_120 = F_297 ( V_102 , V_731 ) ;
if ( V_120 )
goto V_795;
V_120 = 0 ;
V_795:
F_187 ( V_731 ) ;
break;
}
case V_796 : {
V_120 = - V_101 ;
if ( F_233 ( & V_687 . V_741 , V_588 , sizeof( struct V_740 ) ) )
goto V_114;
V_120 = - V_622 ;
if ( ! V_102 -> V_5 . V_742 )
goto V_114;
V_120 = F_300 ( V_102 , & V_687 . V_741 ) ;
if ( V_120 )
goto V_114;
V_120 = - V_101 ;
if ( F_234 ( V_588 , & V_687 . V_741 , sizeof( struct V_740 ) ) )
goto V_114;
V_120 = 0 ;
break;
}
case V_797 : {
V_120 = - V_101 ;
if ( F_233 ( & V_687 . V_741 , V_588 , sizeof V_687 . V_741 ) )
goto V_114;
V_120 = - V_622 ;
if ( ! V_102 -> V_5 . V_742 )
goto V_114;
V_120 = F_301 ( V_102 , & V_687 . V_741 ) ;
break;
}
case V_798 : {
V_120 = - V_622 ;
if ( ! V_102 -> V_5 . V_742 )
goto V_114;
V_120 = F_303 ( V_102 , & V_687 . V_770 ) ;
if ( V_120 )
goto V_114;
V_120 = - V_101 ;
if ( F_234 ( V_588 , & V_687 . V_770 , sizeof( V_687 . V_770 ) ) )
goto V_114;
V_120 = 0 ;
break;
}
case V_799 : {
V_120 = - V_101 ;
if ( F_233 ( & V_687 . V_770 , V_588 , sizeof( V_687 . V_770 ) ) )
goto V_114;
V_120 = - V_622 ;
if ( ! V_102 -> V_5 . V_742 )
goto V_114;
V_120 = F_304 ( V_102 , & V_687 . V_770 ) ;
break;
}
case V_800 : {
struct V_751 V_752 ;
V_120 = - V_101 ;
if ( F_233 ( & V_752 , V_588 , sizeof( V_752 ) ) )
goto V_114;
V_120 = F_305 ( V_102 , & V_752 ) ;
break;
}
case V_801 : {
V_120 = - V_101 ;
if ( F_233 ( & V_102 -> V_5 . F_183 , V_588 ,
sizeof( struct V_802 ) ) )
goto V_114;
V_120 = - V_605 ;
if ( V_102 -> V_5 . F_183 . V_291 )
goto V_114;
V_120 = 0 ;
break;
}
case V_803 : {
struct V_804 V_805 ;
T_2 V_806 ;
T_12 V_303 ;
V_120 = - V_101 ;
if ( F_233 ( & V_805 , V_588 , sizeof( V_805 ) ) )
goto V_114;
V_120 = - V_605 ;
if ( V_805 . V_291 )
goto V_114;
V_120 = 0 ;
F_323 () ;
V_806 = F_125 () ;
V_303 = V_805 . clock - V_806 ;
F_324 () ;
V_102 -> V_5 . V_240 = V_303 ;
F_157 ( V_102 ) ;
break;
}
case V_807 : {
struct V_804 V_805 ;
T_2 V_806 ;
F_323 () ;
V_806 = F_125 () ;
V_805 . clock = V_102 -> V_5 . V_240 + V_806 ;
F_324 () ;
V_805 . V_291 = 0 ;
memset ( & V_805 . V_639 , 0 , sizeof( V_805 . V_639 ) ) ;
V_120 = - V_101 ;
if ( F_234 ( V_588 , & V_805 , sizeof( V_805 ) ) )
goto V_114;
V_120 = 0 ;
break;
}
default:
V_120 = F_325 ( V_102 , V_586 , V_587 ) ;
}
V_114:
return V_120 ;
}
static void F_326 ( void )
{
T_1 V_808 [ 2 ] ;
unsigned V_3 , V_809 ;
for ( V_3 = V_809 = V_810 ; V_3 < F_53 ( V_596 ) ; V_3 ++ ) {
if ( F_327 ( V_596 [ V_3 ] , & V_808 [ 0 ] , & V_808 [ 1 ] ) < 0 )
continue;
switch ( V_596 [ V_3 ] ) {
case V_811 :
if ( ! V_73 -> V_812 () )
continue;
break;
default:
break;
}
if ( V_809 < V_3 )
V_596 [ V_809 ] = V_596 [ V_3 ] ;
V_809 ++ ;
}
V_593 = V_809 ;
}
static int F_328 ( struct V_1 * V_2 , T_6 V_406 , int V_95 ,
const void * V_262 )
{
int V_813 = 0 ;
int V_522 ;
do {
V_522 = F_329 ( V_95 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_618 &&
! F_330 ( & V_2 -> V_5 . V_618 -> V_814 , V_406 , V_522 , V_262 ) )
&& F_331 ( V_2 -> V_102 , V_815 , V_406 , V_522 , V_262 ) )
break;
V_813 += V_522 ;
V_406 += V_522 ;
V_95 -= V_522 ;
V_262 += V_522 ;
} while ( V_95 );
return V_813 ;
}
static int F_332 ( struct V_1 * V_2 , T_6 V_406 , int V_95 , void * V_262 )
{
int V_813 = 0 ;
int V_522 ;
do {
V_522 = F_329 ( V_95 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_618 &&
! F_333 ( & V_2 -> V_5 . V_618 -> V_814 , V_406 , V_522 , V_262 ) )
&& F_334 ( V_2 -> V_102 , V_815 , V_406 , V_522 , V_262 ) )
break;
F_335 ( V_816 , V_522 , V_406 , * ( T_2 * ) V_262 ) ;
V_813 += V_522 ;
V_406 += V_522 ;
V_95 -= V_522 ;
V_262 += V_522 ;
} while ( V_95 );
return V_813 ;
}
static void F_336 ( struct V_1 * V_2 ,
struct V_817 * V_818 , int V_819 )
{
V_73 -> V_820 ( V_2 , V_818 , V_819 ) ;
}
void F_337 ( struct V_1 * V_2 ,
struct V_817 * V_818 , int V_819 )
{
V_73 -> V_821 ( V_2 , V_818 , V_819 ) ;
}
T_6 F_338 ( struct V_1 * V_2 , T_6 V_426 , T_1 V_96 ,
struct V_75 * V_68 )
{
T_6 V_822 ;
F_13 ( ! F_40 ( V_2 ) ) ;
V_96 |= V_112 ;
V_822 = V_2 -> V_5 . V_84 . V_823 ( V_2 , V_426 , V_96 , V_68 ) ;
return V_822 ;
}
T_6 F_339 ( struct V_1 * V_2 , T_16 V_824 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_112 : 0 ;
return V_2 -> V_5 . V_104 -> V_823 ( V_2 , V_824 , V_96 , V_68 ) ;
}
T_6 F_340 ( struct V_1 * V_2 , T_16 V_824 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_112 : 0 ;
V_96 |= V_825 ;
return V_2 -> V_5 . V_104 -> V_823 ( V_2 , V_824 , V_96 , V_68 ) ;
}
T_6 F_341 ( struct V_1 * V_2 , T_16 V_824 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_112 : 0 ;
V_96 |= V_113 ;
return V_2 -> V_5 . V_104 -> V_823 ( V_2 , V_824 , V_96 , V_68 ) ;
}
T_6 F_342 ( struct V_1 * V_2 , T_16 V_824 ,
struct V_75 * V_68 )
{
return V_2 -> V_5 . V_104 -> V_823 ( V_2 , V_824 , 0 , V_68 ) ;
}
static int F_343 ( T_16 V_406 , void * V_188 , unsigned int V_826 ,
struct V_1 * V_2 , T_1 V_96 ,
struct V_75 * V_68 )
{
void * V_38 = V_188 ;
int V_120 = V_827 ;
while ( V_826 ) {
T_6 V_426 = V_2 -> V_5 . V_104 -> V_823 ( V_2 , V_406 , V_96 ,
V_68 ) ;
unsigned V_94 = V_406 & ( V_108 - 1 ) ;
unsigned V_828 = F_329 ( V_826 , ( unsigned ) V_108 - V_94 ) ;
int V_109 ;
if ( V_426 == V_100 )
return V_829 ;
V_109 = F_50 ( V_2 -> V_102 , V_426 >> V_107 , V_38 ,
V_94 , V_828 ) ;
if ( V_109 < 0 ) {
V_120 = V_830 ;
goto V_114;
}
V_826 -= V_828 ;
V_38 += V_828 ;
V_406 += V_828 ;
}
V_114:
return V_120 ;
}
static int F_344 ( struct V_831 * V_832 ,
T_16 V_406 , void * V_188 , unsigned int V_826 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_345 ( V_832 ) ;
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_112 : 0 ;
unsigned V_94 ;
int V_109 ;
T_6 V_426 = V_2 -> V_5 . V_104 -> V_823 ( V_2 , V_406 , V_96 | V_825 ,
V_68 ) ;
if ( F_151 ( V_426 == V_100 ) )
return V_829 ;
V_94 = V_406 & ( V_108 - 1 ) ;
if ( F_29 ( V_94 + V_826 > V_108 ) )
V_826 = ( unsigned ) V_108 - V_94 ;
V_109 = F_50 ( V_2 -> V_102 , V_426 >> V_107 , V_188 ,
V_94 , V_826 ) ;
if ( F_151 ( V_109 < 0 ) )
return V_830 ;
return V_827 ;
}
int F_346 ( struct V_831 * V_832 ,
T_16 V_406 , void * V_188 , unsigned int V_826 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_345 ( V_832 ) ;
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_112 : 0 ;
return F_343 ( V_406 , V_188 , V_826 , V_2 , V_96 ,
V_68 ) ;
}
static int F_347 ( struct V_831 * V_832 ,
T_16 V_406 , void * V_188 , unsigned int V_826 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_345 ( V_832 ) ;
return F_343 ( V_406 , V_188 , V_826 , V_2 , 0 , V_68 ) ;
}
int F_348 ( struct V_831 * V_832 ,
T_16 V_406 , void * V_188 ,
unsigned int V_826 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_345 ( V_832 ) ;
void * V_38 = V_188 ;
int V_120 = V_827 ;
while ( V_826 ) {
T_6 V_426 = V_2 -> V_5 . V_104 -> V_823 ( V_2 , V_406 ,
V_113 ,
V_68 ) ;
unsigned V_94 = V_406 & ( V_108 - 1 ) ;
unsigned V_833 = F_329 ( V_826 , ( unsigned ) V_108 - V_94 ) ;
int V_109 ;
if ( V_426 == V_100 )
return V_829 ;
V_109 = F_118 ( V_2 -> V_102 , V_426 , V_38 , V_833 ) ;
if ( V_109 < 0 ) {
V_120 = V_830 ;
goto V_114;
}
V_826 -= V_833 ;
V_38 += V_833 ;
V_406 += V_833 ;
}
V_114:
return V_120 ;
}
static int F_349 ( struct V_1 * V_2 , unsigned long V_824 ,
T_6 * V_426 , struct V_75 * V_68 ,
bool V_834 )
{
T_1 V_96 = ( ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_112 : 0 )
| ( V_834 ? V_113 : 0 ) ;
if ( F_350 ( V_2 , V_824 )
&& ! F_351 ( V_2 , V_2 -> V_5 . V_104 ,
V_2 -> V_5 . V_96 , V_96 ) ) {
* V_426 = V_2 -> V_5 . V_835 << V_107 |
( V_824 & ( V_108 - 1 ) ) ;
F_352 ( V_824 , * V_426 , V_834 , false ) ;
return 1 ;
}
* V_426 = V_2 -> V_5 . V_104 -> V_823 ( V_2 , V_824 , V_96 , V_68 ) ;
if ( * V_426 == V_100 )
return - 1 ;
if ( ( * V_426 & V_393 ) == V_836 )
return 1 ;
if ( F_353 ( V_2 , * V_426 ) ) {
F_352 ( V_824 , * V_426 , V_834 , true ) ;
return 1 ;
}
return 0 ;
}
int F_354 ( struct V_1 * V_2 , T_6 V_426 ,
const void * V_188 , int V_826 )
{
int V_109 ;
V_109 = F_118 ( V_2 -> V_102 , V_426 , V_188 , V_826 ) ;
if ( V_109 < 0 )
return 0 ;
F_355 ( V_2 , V_426 , V_188 , V_826 ) ;
return 1 ;
}
static int F_356 ( struct V_1 * V_2 , void * V_188 , int V_826 )
{
if ( V_2 -> V_837 ) {
F_335 ( V_816 , V_826 ,
V_2 -> V_838 [ 0 ] . V_426 , * ( T_2 * ) V_188 ) ;
V_2 -> V_837 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_357 ( struct V_1 * V_2 , T_6 V_426 ,
void * V_188 , int V_826 )
{
return ! F_117 ( V_2 -> V_102 , V_426 , V_188 , V_826 ) ;
}
static int F_358 ( struct V_1 * V_2 , T_6 V_426 ,
void * V_188 , int V_826 )
{
return F_354 ( V_2 , V_426 , V_188 , V_826 ) ;
}
static int F_359 ( struct V_1 * V_2 , T_6 V_426 , int V_826 , void * V_188 )
{
F_335 ( V_839 , V_826 , V_426 , * ( T_2 * ) V_188 ) ;
return F_328 ( V_2 , V_426 , V_826 , V_188 ) ;
}
static int F_360 ( struct V_1 * V_2 , T_6 V_426 ,
void * V_188 , int V_826 )
{
F_335 ( V_840 , V_826 , V_426 , 0 ) ;
return V_830 ;
}
static int F_361 ( struct V_1 * V_2 , T_6 V_426 ,
void * V_188 , int V_826 )
{
struct V_841 * V_842 = & V_2 -> V_838 [ 0 ] ;
memcpy ( V_2 -> V_843 -> V_844 . V_38 , V_842 -> V_38 , F_329 ( 8u , V_842 -> V_95 ) ) ;
return V_827 ;
}
static int F_362 ( unsigned long V_406 , void * V_188 ,
unsigned int V_826 ,
struct V_75 * V_68 ,
struct V_1 * V_2 ,
const struct V_845 * V_846 )
{
T_6 V_426 ;
int V_813 , V_109 ;
bool V_834 = V_846 -> V_834 ;
struct V_841 * V_842 ;
V_109 = F_349 ( V_2 , V_406 , & V_426 , V_68 , V_834 ) ;
if ( V_109 < 0 )
return V_829 ;
if ( V_109 )
goto V_844;
if ( V_846 -> V_847 ( V_2 , V_426 , V_188 , V_826 ) )
return V_827 ;
V_844:
V_813 = V_846 -> V_848 ( V_2 , V_426 , V_826 , V_188 ) ;
if ( V_813 == V_826 )
return V_827 ;
V_426 += V_813 ;
V_826 -= V_813 ;
V_188 += V_813 ;
F_29 ( V_2 -> V_849 >= V_850 ) ;
V_842 = & V_2 -> V_838 [ V_2 -> V_849 ++ ] ;
V_842 -> V_426 = V_426 ;
V_842 -> V_38 = V_188 ;
V_842 -> V_95 = V_826 ;
return V_827 ;
}
int F_363 ( struct V_831 * V_832 , unsigned long V_406 ,
void * V_188 , unsigned int V_826 ,
struct V_75 * V_68 ,
const struct V_845 * V_846 )
{
struct V_1 * V_2 = F_345 ( V_832 ) ;
T_6 V_426 ;
int V_851 ;
if ( V_846 -> V_852 &&
V_846 -> V_852 ( V_2 , V_188 , V_826 ) )
return V_827 ;
V_2 -> V_849 = 0 ;
if ( ( ( V_406 + V_826 - 1 ) ^ V_406 ) & V_393 ) {
int V_853 ;
V_853 = - V_406 & ~ V_393 ;
V_851 = F_362 ( V_406 , V_188 , V_853 , V_68 ,
V_2 , V_846 ) ;
if ( V_851 != V_827 )
return V_851 ;
V_406 += V_853 ;
V_188 += V_853 ;
V_826 -= V_853 ;
}
V_851 = F_362 ( V_406 , V_188 , V_826 , V_68 ,
V_2 , V_846 ) ;
if ( V_851 != V_827 )
return V_851 ;
if ( ! V_2 -> V_849 )
return V_851 ;
V_426 = V_2 -> V_838 [ 0 ] . V_426 ;
V_2 -> V_854 = 1 ;
V_2 -> V_855 = 0 ;
V_2 -> V_843 -> V_844 . V_95 = F_329 ( 8u , V_2 -> V_838 [ 0 ] . V_95 ) ;
V_2 -> V_843 -> V_844 . V_856 = V_2 -> V_857 = V_846 -> V_834 ;
V_2 -> V_843 -> V_858 = V_859 ;
V_2 -> V_843 -> V_844 . V_860 = V_426 ;
return V_846 -> V_861 ( V_2 , V_426 , V_188 , V_826 ) ;
}
static int F_364 ( struct V_831 * V_832 ,
unsigned long V_406 ,
void * V_188 ,
unsigned int V_826 ,
struct V_75 * V_68 )
{
return F_363 ( V_832 , V_406 , V_188 , V_826 ,
V_68 , & V_862 ) ;
}
int F_365 ( struct V_831 * V_832 ,
unsigned long V_406 ,
const void * V_188 ,
unsigned int V_826 ,
struct V_75 * V_68 )
{
return F_363 ( V_832 , V_406 , ( void * ) V_188 , V_826 ,
V_68 , & V_863 ) ;
}
static int F_366 ( struct V_831 * V_832 ,
unsigned long V_406 ,
const void * V_864 ,
const void * V_865 ,
unsigned int V_826 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_345 ( V_832 ) ;
T_6 V_426 ;
struct V_395 * V_395 ;
char * V_866 ;
bool V_867 ;
if ( V_826 > 8 || ( V_826 & ( V_826 - 1 ) ) )
goto V_868;
V_426 = F_341 ( V_2 , V_406 , NULL ) ;
if ( V_426 == V_100 ||
( V_426 & V_393 ) == V_836 )
goto V_868;
if ( ( ( V_426 + V_826 - 1 ) & V_393 ) != ( V_426 & V_393 ) )
goto V_868;
V_395 = F_367 ( V_2 -> V_102 , V_426 >> V_107 ) ;
if ( F_368 ( V_395 ) )
goto V_868;
V_866 = F_369 ( V_395 ) ;
V_866 += F_370 ( V_426 ) ;
switch ( V_826 ) {
case 1 :
V_867 = F_371 ( T_14 , V_866 , V_864 , V_865 ) ;
break;
case 2 :
V_867 = F_371 ( V_869 , V_866 , V_864 , V_865 ) ;
break;
case 4 :
V_867 = F_371 ( T_1 , V_866 , V_864 , V_865 ) ;
break;
case 8 :
V_867 = F_372 ( V_866 , V_864 , V_865 ) ;
break;
default:
F_26 () ;
}
F_373 ( V_866 ) ;
F_374 ( V_395 ) ;
if ( ! V_867 )
return V_870 ;
F_194 ( V_2 -> V_102 , V_426 >> V_107 ) ;
F_355 ( V_2 , V_426 , V_865 , V_826 ) ;
return V_827 ;
V_868:
F_375 ( V_871 L_22 ) ;
return F_365 ( V_832 , V_406 , V_865 , V_826 , V_68 ) ;
}
static int F_376 ( struct V_1 * V_2 , void * V_872 )
{
int V_120 ;
if ( V_2 -> V_5 . V_873 . V_874 )
V_120 = F_334 ( V_2 -> V_102 , V_782 , V_2 -> V_5 . V_873 . V_875 ,
V_2 -> V_5 . V_873 . V_523 , V_872 ) ;
else
V_120 = F_331 ( V_2 -> V_102 , V_782 ,
V_2 -> V_5 . V_873 . V_875 , V_2 -> V_5 . V_873 . V_523 ,
V_872 ) ;
return V_120 ;
}
static int F_377 ( struct V_1 * V_2 , int V_523 ,
unsigned short V_875 , void * V_188 ,
unsigned int V_745 , bool V_874 )
{
V_2 -> V_5 . V_873 . V_875 = V_875 ;
V_2 -> V_5 . V_873 . V_874 = V_874 ;
V_2 -> V_5 . V_873 . V_745 = V_745 ;
V_2 -> V_5 . V_873 . V_523 = V_523 ;
if ( ! F_376 ( V_2 , V_2 -> V_5 . V_876 ) ) {
V_2 -> V_5 . V_873 . V_745 = 0 ;
return 1 ;
}
V_2 -> V_843 -> V_858 = V_877 ;
V_2 -> V_843 -> V_878 . V_879 = V_874 ? V_880 : V_881 ;
V_2 -> V_843 -> V_878 . V_523 = V_523 ;
V_2 -> V_843 -> V_878 . V_882 = V_883 * V_108 ;
V_2 -> V_843 -> V_878 . V_745 = V_745 ;
V_2 -> V_843 -> V_878 . V_875 = V_875 ;
return 0 ;
}
static int F_378 ( struct V_831 * V_832 ,
int V_523 , unsigned short V_875 , void * V_188 ,
unsigned int V_745 )
{
struct V_1 * V_2 = F_345 ( V_832 ) ;
int V_109 ;
if ( V_2 -> V_5 . V_873 . V_745 )
goto V_884;
V_109 = F_377 ( V_2 , V_523 , V_875 , V_188 , V_745 , true ) ;
if ( V_109 ) {
V_884:
memcpy ( V_188 , V_2 -> V_5 . V_876 , V_523 * V_745 ) ;
F_379 ( V_885 , V_875 , V_523 , V_745 , V_2 -> V_5 . V_876 ) ;
V_2 -> V_5 . V_873 . V_745 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_380 ( struct V_831 * V_832 ,
int V_523 , unsigned short V_875 ,
const void * V_188 , unsigned int V_745 )
{
struct V_1 * V_2 = F_345 ( V_832 ) ;
memcpy ( V_2 -> V_5 . V_876 , V_188 , V_523 * V_745 ) ;
F_379 ( V_886 , V_875 , V_523 , V_745 , V_2 -> V_5 . V_876 ) ;
return F_377 ( V_2 , V_523 , V_875 , ( void * ) V_188 , V_745 , false ) ;
}
static unsigned long F_381 ( struct V_1 * V_2 , int V_819 )
{
return V_73 -> F_381 ( V_2 , V_819 ) ;
}
static void F_382 ( struct V_831 * V_832 , V_172 V_80 )
{
F_383 ( F_345 ( V_832 ) , V_80 ) ;
}
int F_384 ( struct V_1 * V_2 )
{
if ( ! F_243 ( V_2 ) )
return V_827 ;
if ( V_73 -> V_607 () ) {
int V_23 = F_385 () ;
F_246 ( V_23 , V_2 -> V_5 . V_608 ) ;
F_386 ( V_2 -> V_5 . V_608 ,
F_241 , NULL , 1 ) ;
F_387 () ;
F_388 ( V_2 -> V_5 . V_608 ) ;
} else
F_242 () ;
return V_827 ;
}
static void F_389 ( struct V_831 * V_832 )
{
F_384 ( F_345 ( V_832 ) ) ;
}
int F_390 ( struct V_831 * V_832 , int V_89 , unsigned long * V_658 )
{
return F_97 ( F_345 ( V_832 ) , V_89 , V_658 ) ;
}
int F_391 ( struct V_831 * V_832 , int V_89 , unsigned long V_22 )
{
return F_95 ( F_345 ( V_832 ) , V_89 , V_22 ) ;
}
static T_2 F_392 ( T_2 V_887 , T_1 V_888 )
{
return ( V_887 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_888 ;
}
static unsigned long F_393 ( struct V_831 * V_832 , int V_889 )
{
struct V_1 * V_2 = F_345 ( V_832 ) ;
unsigned long V_22 ;
switch ( V_889 ) {
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
F_394 ( L_23 , V_257 , V_889 ) ;
return 0 ;
}
return V_22 ;
}
static int F_395 ( struct V_831 * V_832 , int V_889 , V_172 V_188 )
{
struct V_1 * V_2 = F_345 ( V_832 ) ;
int V_890 = 0 ;
switch ( V_889 ) {
case 0 :
V_890 = F_61 ( V_2 , F_392 ( F_62 ( V_2 ) , V_188 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_79 = V_188 ;
break;
case 3 :
V_890 = F_83 ( V_2 , V_188 ) ;
break;
case 4 :
V_890 = F_75 ( V_2 , F_392 ( F_76 ( V_2 ) , V_188 ) ) ;
break;
case 8 :
V_890 = F_86 ( V_2 , V_188 ) ;
break;
default:
F_394 ( L_23 , V_257 , V_889 ) ;
V_890 = - 1 ;
}
return V_890 ;
}
static int F_396 ( struct V_831 * V_832 )
{
return V_73 -> V_88 ( F_345 ( V_832 ) ) ;
}
static void F_397 ( struct V_831 * V_832 , struct V_891 * V_892 )
{
V_73 -> V_893 ( F_345 ( V_832 ) , V_892 ) ;
}
static void F_398 ( struct V_831 * V_832 , struct V_891 * V_892 )
{
V_73 -> V_894 ( F_345 ( V_832 ) , V_892 ) ;
}
static void F_399 ( struct V_831 * V_832 , struct V_891 * V_892 )
{
V_73 -> V_895 ( F_345 ( V_832 ) , V_892 ) ;
}
static void F_400 ( struct V_831 * V_832 , struct V_891 * V_892 )
{
V_73 -> V_896 ( F_345 ( V_832 ) , V_892 ) ;
}
static unsigned long F_401 (
struct V_831 * V_832 , int V_819 )
{
return F_381 ( F_345 ( V_832 ) , V_819 ) ;
}
static bool F_402 ( struct V_831 * V_832 , V_869 * V_897 ,
struct V_898 * V_899 , T_1 * V_900 ,
int V_819 )
{
struct V_817 V_818 ;
F_337 ( F_345 ( V_832 ) , & V_818 , V_819 ) ;
* V_897 = V_818 . V_897 ;
if ( V_818 . V_901 ) {
memset ( V_899 , 0 , sizeof( * V_899 ) ) ;
return false ;
}
if ( V_818 . V_902 )
V_818 . V_903 >>= 12 ;
F_403 ( V_899 , V_818 . V_903 ) ;
F_404 ( V_899 , ( unsigned long ) V_818 . V_904 ) ;
#ifdef F_63
if ( V_900 )
* V_900 = V_818 . V_904 >> 32 ;
#endif
V_899 -> type = V_818 . type ;
V_899 -> V_615 = V_818 . V_615 ;
V_899 -> V_905 = V_818 . V_905 ;
V_899 -> V_364 = V_818 . V_906 ;
V_899 -> V_907 = V_818 . V_907 ;
V_899 -> V_908 = V_818 . V_908 ;
V_899 -> V_909 = V_818 . V_189 ;
V_899 -> V_902 = V_818 . V_902 ;
return true ;
}
static void F_405 ( struct V_831 * V_832 , V_869 V_897 ,
struct V_898 * V_899 , T_1 V_900 ,
int V_819 )
{
struct V_1 * V_2 = F_345 ( V_832 ) ;
struct V_817 V_818 ;
V_818 . V_897 = V_897 ;
V_818 . V_904 = F_406 ( V_899 ) ;
#ifdef F_63
V_818 . V_904 |= ( ( T_2 ) V_900 ) << 32 ;
#endif
V_818 . V_903 = F_407 ( V_899 ) ;
if ( V_899 -> V_902 )
V_818 . V_903 = ( V_818 . V_903 << 12 ) | 0xfff ;
V_818 . type = V_899 -> type ;
V_818 . V_905 = V_899 -> V_905 ;
V_818 . V_189 = V_899 -> V_909 ;
V_818 . V_615 = V_899 -> V_615 ;
V_818 . V_908 = V_899 -> V_908 ;
V_818 . V_902 = V_899 -> V_902 ;
V_818 . V_907 = V_899 -> V_907 ;
V_818 . V_906 = V_899 -> V_364 ;
V_818 . V_901 = ! V_818 . V_906 ;
V_818 . V_910 = 0 ;
F_336 ( V_2 , & V_818 , V_819 ) ;
return;
}
static int F_408 ( struct V_831 * V_832 ,
T_1 V_496 , T_2 * V_497 )
{
return F_217 ( F_345 ( V_832 ) , V_496 , V_497 ) ;
}
static int F_409 ( struct V_831 * V_832 ,
T_1 V_496 , T_2 V_38 )
{
struct V_32 V_21 ;
V_21 . V_38 = V_38 ;
V_21 . V_144 = V_496 ;
V_21 . V_40 = false ;
return F_107 ( F_345 ( V_832 ) , & V_21 ) ;
}
static int F_410 ( struct V_831 * V_832 ,
T_1 V_911 )
{
return F_411 ( F_345 ( V_832 ) , V_911 ) ;
}
static int F_412 ( struct V_831 * V_832 ,
T_1 V_911 , T_2 * V_497 )
{
return F_100 ( F_345 ( V_832 ) , V_911 , V_497 ) ;
}
static void F_413 ( struct V_831 * V_832 )
{
F_345 ( V_832 ) -> V_5 . V_912 = 1 ;
}
static void F_414 ( struct V_831 * V_832 )
{
F_210 () ;
F_415 ( F_345 ( V_832 ) ) ;
F_416 () ;
}
static void F_417 ( struct V_831 * V_832 )
{
F_211 () ;
}
static int F_418 ( struct V_831 * V_832 ,
struct V_913 * V_914 ,
enum V_915 V_916 )
{
return V_73 -> V_917 ( F_345 ( V_832 ) , V_914 , V_916 ) ;
}
static void F_419 ( struct V_831 * V_832 ,
T_1 * V_918 , T_1 * V_919 , T_1 * V_195 , T_1 * V_203 )
{
V_694 ( F_345 ( V_832 ) , V_918 , V_919 , V_195 , V_203 ) ;
}
static V_172 F_420 ( struct V_831 * V_832 , unsigned V_920 )
{
return F_99 ( F_345 ( V_832 ) , V_920 ) ;
}
static void F_421 ( struct V_831 * V_832 , unsigned V_920 , V_172 V_188 )
{
F_101 ( F_345 ( V_832 ) , V_920 , V_188 ) ;
}
static void F_422 ( struct V_1 * V_2 , T_1 V_28 )
{
T_1 V_921 = V_73 -> V_643 ( V_2 ) ;
if ( V_921 & V_28 )
V_28 = 0 ;
if ( F_151 ( V_921 || V_28 ) ) {
V_73 -> V_654 ( V_2 , V_28 ) ;
if ( ! V_28 )
F_31 ( V_67 , V_2 ) ;
}
}
static bool F_423 ( struct V_1 * V_2 )
{
struct V_831 * V_832 = & V_2 -> V_5 . V_922 ;
if ( V_832 -> V_68 . V_41 == V_42 )
return F_39 ( V_2 , & V_832 -> V_68 ) ;
if ( V_832 -> V_68 . V_923 )
F_38 ( V_2 , V_832 -> V_68 . V_41 ,
V_832 -> V_68 . V_62 ) ;
else
F_33 ( V_2 , V_832 -> V_68 . V_41 ) ;
return false ;
}
static void F_424 ( struct V_1 * V_2 )
{
struct V_831 * V_832 = & V_2 -> V_5 . V_922 ;
int V_133 , V_134 ;
V_73 -> V_135 ( V_2 , & V_133 , & V_134 ) ;
V_832 -> V_924 = F_425 ( V_2 ) ;
V_832 -> V_925 = F_426 ( V_2 ) ;
V_832 -> V_314 = ( ! F_32 ( V_2 ) ) ? V_926 :
( V_832 -> V_924 & V_927 ) ? V_928 :
( V_134 && F_57 ( V_2 ) ) ? V_929 :
V_133 ? V_930 :
V_931 ;
V_832 -> V_932 = F_427 ( V_2 ) ;
F_428 ( V_832 ) ;
V_2 -> V_5 . V_933 = false ;
}
int F_429 ( struct V_1 * V_2 , int V_620 , int V_934 )
{
struct V_831 * V_832 = & V_2 -> V_5 . V_922 ;
int V_109 ;
F_424 ( V_2 ) ;
V_832 -> V_935 = 2 ;
V_832 -> V_936 = 2 ;
V_832 -> V_937 = V_832 -> V_925 + V_934 ;
V_109 = F_430 ( V_832 , V_620 ) ;
if ( V_109 != V_827 )
return V_938 ;
V_832 -> V_925 = V_832 -> V_937 ;
F_431 ( V_2 , V_832 -> V_925 ) ;
F_432 ( V_2 , V_832 -> V_924 ) ;
if ( V_620 == V_51 )
V_2 -> V_5 . V_646 = 0 ;
else
V_2 -> V_5 . V_640 . V_69 = false ;
return V_939 ;
}
static int F_433 ( struct V_1 * V_2 )
{
int V_120 = V_939 ;
++ V_2 -> V_77 . V_940 ;
F_434 ( V_2 ) ;
if ( ! F_427 ( V_2 ) && V_73 -> V_88 ( V_2 ) == 0 ) {
V_2 -> V_843 -> V_858 = V_941 ;
V_2 -> V_843 -> V_942 . V_943 = V_944 ;
V_2 -> V_843 -> V_942 . V_945 = 0 ;
V_120 = V_938 ;
}
F_33 ( V_2 , V_91 ) ;
return V_120 ;
}
static bool F_435 ( struct V_1 * V_2 , T_16 V_79 ,
bool V_946 ,
int V_947 )
{
T_6 V_426 = V_79 ;
T_17 V_948 ;
if ( V_947 & V_949 )
return false ;
if ( ! V_2 -> V_5 . V_84 . V_950 ) {
V_426 = F_341 ( V_2 , V_79 , NULL ) ;
if ( V_426 == V_100 )
return true ;
}
V_948 = F_436 ( V_2 -> V_102 , F_49 ( V_426 ) ) ;
if ( F_437 ( V_948 ) )
return false ;
F_438 ( V_948 ) ;
if ( V_2 -> V_5 . V_84 . V_950 ) {
unsigned int V_951 ;
F_142 ( & V_2 -> V_102 -> V_762 ) ;
V_951 = V_2 -> V_102 -> V_5 . V_951 ;
F_143 ( & V_2 -> V_102 -> V_762 ) ;
if ( V_951 )
F_439 ( V_2 -> V_102 , F_49 ( V_426 ) ) ;
return true ;
}
F_439 ( V_2 -> V_102 , F_49 ( V_426 ) ) ;
return ! V_946 ;
}
static bool F_440 ( struct V_831 * V_832 ,
unsigned long V_79 , int V_947 )
{
struct V_1 * V_2 = F_345 ( V_832 ) ;
unsigned long V_952 , V_953 , V_426 = V_79 ;
V_952 = V_2 -> V_5 . V_952 ;
V_953 = V_2 -> V_5 . V_953 ;
V_2 -> V_5 . V_952 = V_2 -> V_5 . V_953 = 0 ;
if ( ! ( V_947 & V_954 ) )
return false ;
if ( F_441 ( V_832 ) )
return false ;
if ( V_832 -> V_925 == V_952 && V_953 == V_79 )
return false ;
V_2 -> V_5 . V_952 = V_832 -> V_925 ;
V_2 -> V_5 . V_953 = V_79 ;
if ( ! V_2 -> V_5 . V_84 . V_950 )
V_426 = F_341 ( V_2 , V_79 , NULL ) ;
F_439 ( V_2 -> V_102 , F_49 ( V_426 ) ) ;
return true ;
}
static int F_442 ( unsigned long V_406 , T_1 type , T_1 V_179 ,
unsigned long * V_189 )
{
T_1 V_178 = 0 ;
int V_3 ;
T_1 V_955 , V_956 ;
V_955 = V_179 ;
V_956 = V_179 >> 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ , V_955 >>= 2 , V_956 >>= 4 )
if ( ( V_955 & 3 ) && ( V_956 & 15 ) == type && V_189 [ V_3 ] == V_406 )
V_178 |= ( 1 << V_3 ) ;
return V_178 ;
}
static void F_443 ( struct V_1 * V_2 , unsigned long V_957 , int * V_120 )
{
struct V_958 * V_958 = V_2 -> V_843 ;
if ( F_151 ( V_957 & V_959 ) ) {
if ( V_2 -> V_175 & V_960 ) {
V_958 -> V_961 . V_5 . V_178 = V_962 | V_186 |
V_187 ;
V_958 -> V_961 . V_5 . V_963 = V_2 -> V_5 . V_964 ;
V_958 -> V_961 . V_5 . V_68 = V_53 ;
V_958 -> V_858 = V_965 ;
* V_120 = V_966 ;
} else {
V_2 -> V_5 . V_922 . V_924 &= ~ V_959 ;
V_2 -> V_5 . V_178 &= ~ 15 ;
V_2 -> V_5 . V_178 |= V_962 | V_187 ;
F_33 ( V_2 , V_53 ) ;
}
}
}
static bool F_444 ( struct V_1 * V_2 , int * V_120 )
{
if ( F_151 ( V_2 -> V_175 & V_176 ) &&
( V_2 -> V_5 . V_180 & V_184 ) ) {
struct V_958 * V_958 = V_2 -> V_843 ;
unsigned long V_925 = F_445 ( V_2 ) ;
T_1 V_178 = F_442 ( V_925 , 0 ,
V_2 -> V_5 . V_180 ,
V_2 -> V_5 . V_190 ) ;
if ( V_178 != 0 ) {
V_958 -> V_961 . V_5 . V_178 = V_178 | V_186 | V_187 ;
V_958 -> V_961 . V_5 . V_963 = V_925 ;
V_958 -> V_961 . V_5 . V_68 = V_53 ;
V_958 -> V_858 = V_965 ;
* V_120 = V_966 ;
return true ;
}
}
if ( F_151 ( V_2 -> V_5 . V_179 & V_184 ) &&
! ( F_425 ( V_2 ) & V_967 ) ) {
unsigned long V_925 = F_445 ( V_2 ) ;
T_1 V_178 = F_442 ( V_925 , 0 ,
V_2 -> V_5 . V_179 ,
V_2 -> V_5 . V_189 ) ;
if ( V_178 != 0 ) {
V_2 -> V_5 . V_178 &= ~ 15 ;
V_2 -> V_5 . V_178 |= V_178 | V_187 ;
F_33 ( V_2 , V_53 ) ;
* V_120 = V_939 ;
return true ;
}
}
return false ;
}
int F_446 ( struct V_1 * V_2 ,
unsigned long V_79 ,
int V_947 ,
void * V_968 ,
int V_969 )
{
int V_120 ;
struct V_831 * V_832 = & V_2 -> V_5 . V_922 ;
bool V_521 = true ;
bool V_970 = V_2 -> V_5 . V_946 ;
V_2 -> V_5 . V_946 = false ;
F_447 ( V_2 ) ;
if ( ! ( V_947 & V_971 ) ) {
F_424 ( V_2 ) ;
if ( F_444 ( V_2 , & V_120 ) )
return V_120 ;
V_832 -> V_972 = 0 ;
V_832 -> V_973 = false ;
V_832 -> V_68 . V_41 = - 1 ;
V_832 -> V_974 = false ;
V_832 -> V_975 = V_947 & V_976 ;
V_120 = F_448 ( V_832 , V_968 , V_969 ) ;
F_449 ( V_2 ) ;
++ V_2 -> V_77 . V_977 ;
if ( V_120 != V_978 ) {
if ( V_947 & V_976 )
return V_938 ;
if ( F_435 ( V_2 , V_79 , V_970 ,
V_947 ) )
return V_939 ;
if ( V_947 & V_979 )
return V_938 ;
return F_433 ( V_2 ) ;
}
}
if ( V_947 & V_979 ) {
F_431 ( V_2 , V_832 -> V_937 ) ;
if ( V_832 -> V_924 & V_967 )
F_432 ( V_2 , V_832 -> V_924 & ~ V_967 ) ;
return V_939 ;
}
if ( F_440 ( V_832 , V_79 , V_947 ) )
return V_939 ;
if ( V_2 -> V_5 . V_933 ) {
V_2 -> V_5 . V_933 = false ;
F_450 ( V_832 ) ;
}
V_980:
V_120 = F_451 ( V_832 ) ;
if ( V_120 == V_981 )
return V_939 ;
if ( V_120 == V_982 ) {
if ( F_435 ( V_2 , V_79 , V_970 ,
V_947 ) )
return V_939 ;
return F_433 ( V_2 ) ;
}
if ( V_832 -> V_973 ) {
V_120 = V_939 ;
if ( F_423 ( V_2 ) )
return V_120 ;
} else if ( V_2 -> V_5 . V_873 . V_745 ) {
if ( ! V_2 -> V_5 . V_873 . V_874 ) {
V_2 -> V_5 . V_873 . V_745 = 0 ;
} else {
V_521 = false ;
V_2 -> V_5 . V_983 = V_984 ;
}
V_120 = V_966 ;
} else if ( V_2 -> V_854 ) {
if ( ! V_2 -> V_857 )
V_521 = false ;
V_120 = V_966 ;
V_2 -> V_5 . V_983 = V_985 ;
} else if ( V_120 == V_986 )
goto V_980;
else
V_120 = V_939 ;
if ( V_521 ) {
unsigned long V_957 = V_73 -> V_987 ( V_2 ) ;
F_422 ( V_2 , V_832 -> V_972 ) ;
V_2 -> V_5 . V_988 = false ;
F_431 ( V_2 , V_832 -> V_925 ) ;
if ( V_120 == V_939 )
F_443 ( V_2 , V_957 , & V_120 ) ;
if ( ! V_832 -> V_973 ||
F_28 ( V_832 -> V_68 . V_41 ) == V_56 )
F_452 ( V_2 , V_832 -> V_924 ) ;
if ( F_151 ( ( V_832 -> V_924 & ~ V_957 ) & V_989 ) )
F_31 ( V_67 , V_2 ) ;
} else
V_2 -> V_5 . V_988 = true ;
return V_120 ;
}
int F_453 ( struct V_1 * V_2 , int V_523 , unsigned short V_875 )
{
unsigned long V_188 = F_99 ( V_2 , V_197 ) ;
int V_109 = F_380 ( & V_2 -> V_5 . V_922 ,
V_523 , V_875 , & V_188 , 1 ) ;
V_2 -> V_5 . V_873 . V_745 = 0 ;
return V_109 ;
}
static void F_454 ( void * V_914 )
{
F_455 ( V_329 , 0 ) ;
}
static void F_456 ( void * V_38 )
{
struct V_990 * V_991 = V_38 ;
unsigned long V_260 = 0 ;
if ( V_38 )
V_260 = V_991 -> V_865 ;
else if ( ! F_238 ( V_992 ) )
V_260 = F_457 ( F_458 () ) ;
if ( ! V_260 )
V_260 = V_269 ;
F_455 ( V_329 , V_260 ) ;
}
static int F_459 ( struct V_993 * V_994 , unsigned long V_188 ,
void * V_38 )
{
struct V_990 * V_991 = V_38 ;
struct V_102 * V_102 ;
struct V_1 * V_2 ;
int V_3 , V_995 = 0 ;
if ( V_188 == V_996 && V_991 -> V_864 > V_991 -> V_865 )
return 0 ;
if ( V_188 == V_997 && V_991 -> V_864 < V_991 -> V_865 )
return 0 ;
F_247 ( V_991 -> V_23 , F_456 , V_991 , 1 ) ;
F_142 ( & V_998 ) ;
F_460 (kvm, &vm_list, vm_list) {
F_159 (i, vcpu, kvm) {
if ( V_2 -> V_23 != V_991 -> V_23 )
continue;
F_31 ( V_320 , V_2 ) ;
if ( V_2 -> V_23 != F_8 () )
V_995 = 1 ;
}
}
F_143 ( & V_998 ) ;
if ( V_991 -> V_864 < V_991 -> V_865 && V_995 ) {
F_247 ( V_991 -> V_23 , F_456 , V_991 , 1 ) ;
}
return 0 ;
}
static int F_461 ( struct V_993 * V_999 ,
unsigned long V_1000 , void * V_1001 )
{
unsigned int V_23 = ( unsigned long ) V_1001 ;
switch ( V_1000 ) {
case V_1002 :
case V_1003 :
F_247 ( V_23 , F_456 , NULL , 1 ) ;
break;
case V_1004 :
F_247 ( V_23 , F_454 , NULL , 1 ) ;
break;
}
return V_1005 ;
}
static void F_462 ( void )
{
int V_23 ;
V_1006 = V_269 ;
F_463 () ;
if ( ! F_238 ( V_992 ) ) {
#ifdef F_464
struct V_1007 V_1008 ;
memset ( & V_1008 , 0 , sizeof( V_1008 ) ) ;
V_23 = F_385 () ;
F_465 ( & V_1008 , V_23 ) ;
if ( V_1008 . V_1009 . V_1010 )
V_1006 = V_1008 . V_1009 . V_1010 ;
F_387 () ;
#endif
F_466 ( & V_1011 ,
V_1012 ) ;
}
F_124 ( L_24 , V_1006 ) ;
F_467 (cpu)
F_247 ( V_23 , F_456 , NULL , 1 ) ;
F_468 ( & V_1013 ) ;
F_469 () ;
}
int F_470 ( void )
{
return F_163 ( V_1014 ) != NULL ;
}
static int F_471 ( void )
{
int V_1015 = 3 ;
if ( F_163 ( V_1014 ) )
V_1015 = V_73 -> V_88 ( F_163 ( V_1014 ) ) ;
return V_1015 != 0 ;
}
static unsigned long F_472 ( void )
{
unsigned long V_1016 = 0 ;
if ( F_163 ( V_1014 ) )
V_1016 = F_426 ( F_163 ( V_1014 ) ) ;
return V_1016 ;
}
void F_473 ( struct V_1 * V_2 )
{
F_455 ( V_1014 , V_2 ) ;
}
void F_474 ( struct V_1 * V_2 )
{
F_455 ( V_1014 , NULL ) ;
}
static void F_475 ( void )
{
T_2 V_28 ;
int V_1017 = V_1018 . V_1019 ;
V_28 = F_476 ( V_1017 , 51 ) ;
V_28 |= 0x3ull << 62 ;
V_28 |= 1ull ;
#ifdef F_63
if ( V_1017 == 52 )
V_28 &= ~ 1ull ;
#endif
F_477 ( V_28 ) ;
}
static void F_478 ( struct V_342 * V_343 )
{
struct V_102 * V_102 ;
struct V_1 * V_2 ;
int V_3 ;
F_142 ( & V_998 ) ;
F_460 (kvm, &vm_list, vm_list)
F_159 (i, vcpu, kvm)
F_31 ( V_284 , V_2 ) ;
F_155 ( & V_319 , 0 ) ;
F_143 ( & V_998 ) ;
}
static int F_479 ( struct V_993 * V_994 , unsigned long V_1020 ,
void * V_1021 )
{
struct V_220 * V_279 = & V_220 ;
struct V_218 * V_219 = V_1021 ;
F_111 ( V_219 ) ;
if ( V_279 -> clock . V_227 != V_283 &&
F_134 ( & V_319 ) != 0 )
F_480 ( V_1022 , & V_1023 ) ;
return 0 ;
}
int F_481 ( void * V_1024 )
{
int V_120 ;
struct V_73 * V_846 = V_1024 ;
if ( V_73 ) {
F_10 ( V_26 L_25 ) ;
V_120 = - V_780 ;
goto V_114;
}
if ( ! V_846 -> V_1025 () ) {
F_10 ( V_26 L_26 ) ;
V_120 = - V_1026 ;
goto V_114;
}
if ( V_846 -> V_1027 () ) {
F_10 ( V_26 L_27 ) ;
V_120 = - V_1026 ;
goto V_114;
}
V_120 = - V_397 ;
V_25 = F_482 ( struct V_11 ) ;
if ( ! V_25 ) {
F_10 ( V_26 L_28 ) ;
goto V_114;
}
V_120 = F_483 () ;
if ( V_120 )
goto V_1028;
F_475 () ;
V_73 = V_846 ;
F_326 () ;
F_484 ( V_1029 , V_1030 ,
V_1031 , V_1032 , 0 ) ;
F_462 () ;
F_485 ( & V_1033 ) ;
if ( V_579 )
V_143 = F_486 ( V_141 ) ;
F_487 () ;
#ifdef F_63
F_488 ( & V_1034 ) ;
#endif
return 0 ;
V_1028:
F_489 ( V_25 ) ;
V_114:
return V_120 ;
}
void F_490 ( void )
{
F_491 ( & V_1033 ) ;
if ( ! F_238 ( V_992 ) )
F_492 ( & V_1011 ,
V_1012 ) ;
F_493 ( & V_1013 ) ;
#ifdef F_63
F_494 ( & V_1034 ) ;
#endif
V_73 = NULL ;
F_495 () ;
F_489 ( V_25 ) ;
}
int F_496 ( struct V_1 * V_2 )
{
++ V_2 -> V_77 . V_1035 ;
if ( F_87 ( V_2 -> V_102 ) ) {
V_2 -> V_5 . V_1036 = V_1037 ;
return 1 ;
} else {
V_2 -> V_843 -> V_858 = V_1038 ;
return 0 ;
}
}
int F_497 ( struct V_1 * V_2 )
{
T_2 V_1039 , V_1040 , V_1041 , V_109 ;
T_18 V_1042 , V_1043 , V_1044 , V_890 = V_1045 , V_1046 = 0 ;
bool V_1047 , V_1048 ;
if ( V_73 -> V_88 ( V_2 ) != 0 || ! F_32 ( V_2 ) ) {
F_33 ( V_2 , V_91 ) ;
return 0 ;
}
V_1048 = F_498 ( V_2 ) ;
if ( ! V_1048 ) {
V_1039 = ( ( T_2 ) F_99 ( V_2 , V_198 ) << 32 ) |
( F_99 ( V_2 , V_197 ) & 0xffffffff ) ;
V_1040 = ( ( T_2 ) F_99 ( V_2 , V_1049 ) << 32 ) |
( F_99 ( V_2 , V_196 ) & 0xffffffff ) ;
V_1041 = ( ( T_2 ) F_99 ( V_2 , V_1050 ) << 32 ) |
( F_99 ( V_2 , V_1051 ) & 0xffffffff ) ;
}
#ifdef F_63
else {
V_1039 = F_99 ( V_2 , V_196 ) ;
V_1040 = F_99 ( V_2 , V_198 ) ;
V_1041 = F_99 ( V_2 , V_1052 ) ;
}
#endif
V_1042 = V_1039 & 0xffff ;
V_1047 = ( V_1039 >> 16 ) & 0x1 ;
V_1044 = ( V_1039 >> 32 ) & 0xfff ;
V_1043 = ( V_1039 >> 48 ) & 0xfff ;
F_499 ( V_1042 , V_1047 , V_1044 , V_1043 , V_1040 , V_1041 ) ;
switch ( V_1042 ) {
case V_1053 :
F_500 ( V_2 ) ;
break;
default:
V_890 = V_1054 ;
break;
}
V_109 = V_890 | ( ( ( T_2 ) V_1046 & 0xfff ) << 32 ) ;
if ( V_1048 ) {
F_101 ( V_2 , V_197 , V_109 ) ;
} else {
F_101 ( V_2 , V_198 , V_109 >> 32 ) ;
F_101 ( V_2 , V_197 , V_109 & 0xffffffff ) ;
}
return 1 ;
}
static void F_501 ( struct V_102 * V_102 , unsigned long V_291 , int V_1055 )
{
struct V_1056 V_1057 ;
V_1057 . V_1058 = 0 ;
V_1057 . V_1059 = 0 ;
V_1057 . V_1060 = V_1055 ;
V_1057 . V_1061 = V_1062 ;
F_502 ( V_102 , 0 , & V_1057 , NULL ) ;
}
int F_503 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_1063 , V_1064 , V_1065 , V_1066 , V_109 ;
int V_1067 , V_120 = 1 ;
if ( F_188 ( V_2 -> V_102 ) )
return F_497 ( V_2 ) ;
V_16 = F_99 ( V_2 , V_197 ) ;
V_1063 = F_99 ( V_2 , V_1049 ) ;
V_1064 = F_99 ( V_2 , V_196 ) ;
V_1065 = F_99 ( V_2 , V_198 ) ;
V_1066 = F_99 ( V_2 , V_1051 ) ;
F_504 ( V_16 , V_1063 , V_1064 , V_1065 , V_1066 ) ;
V_1067 = F_498 ( V_2 ) ;
if ( ! V_1067 ) {
V_16 &= 0xFFFFFFFF ;
V_1063 &= 0xFFFFFFFF ;
V_1064 &= 0xFFFFFFFF ;
V_1065 &= 0xFFFFFFFF ;
V_1066 &= 0xFFFFFFFF ;
}
if ( V_73 -> V_88 ( V_2 ) != 0 ) {
V_109 = - V_1068 ;
goto V_114;
}
switch ( V_16 ) {
case V_1069 :
V_109 = 0 ;
break;
case V_1070 :
F_501 ( V_2 -> V_102 , V_1063 , V_1064 ) ;
V_109 = 0 ;
break;
default:
V_109 = - V_1071 ;
break;
}
V_114:
if ( ! V_1067 )
V_109 = ( T_1 ) V_109 ;
F_101 ( V_2 , V_197 , V_109 ) ;
++ V_2 -> V_77 . V_1072 ;
return V_120 ;
}
static int F_505 ( struct V_831 * V_832 )
{
struct V_1 * V_2 = F_345 ( V_832 ) ;
char V_1073 [ 3 ] ;
unsigned long V_1074 = F_426 ( V_2 ) ;
V_73 -> V_409 ( V_2 , V_1073 ) ;
return F_365 ( V_832 , V_1074 , V_1073 , 3 , NULL ) ;
}
static int F_506 ( struct V_1 * V_2 )
{
return ( ! F_87 ( V_2 -> V_102 ) && ! F_507 ( V_2 ) &&
V_2 -> V_843 -> V_1075 &&
F_508 ( V_2 ) ) ;
}
static void F_509 ( struct V_1 * V_2 )
{
struct V_958 * V_958 = V_2 -> V_843 ;
V_958 -> V_1076 = ( F_425 ( V_2 ) & V_989 ) != 0 ;
V_958 -> V_173 = F_89 ( V_2 ) ;
V_958 -> V_31 = F_20 ( V_2 ) ;
if ( F_87 ( V_2 -> V_102 ) )
V_958 -> V_1077 = 1 ;
else
V_958 -> V_1077 =
F_508 ( V_2 ) &&
! F_507 ( V_2 ) &&
! F_510 ( V_2 ) ;
}
static void F_256 ( struct V_1 * V_2 )
{
int V_1078 , V_1079 ;
if ( ! V_73 -> F_256 )
return;
if ( ! V_2 -> V_5 . V_618 )
return;
if ( ! V_2 -> V_5 . V_618 -> V_703 )
V_1078 = F_511 ( V_2 ) ;
else
V_1078 = - 1 ;
if ( V_1078 != - 1 )
V_1078 >>= 4 ;
V_1079 = F_90 ( V_2 ) ;
V_73 -> F_256 ( V_2 , V_1079 , V_1078 ) ;
}
static int F_512 ( struct V_1 * V_2 , bool V_1080 )
{
int V_120 ;
if ( V_2 -> V_5 . V_68 . V_69 ) {
F_513 ( V_2 -> V_5 . V_68 . V_16 ,
V_2 -> V_5 . V_68 . V_71 ,
V_2 -> V_5 . V_68 . V_62 ) ;
if ( F_28 ( V_2 -> V_5 . V_68 . V_16 ) == V_60 )
F_452 ( V_2 , F_425 ( V_2 ) |
V_967 ) ;
if ( V_2 -> V_5 . V_68 . V_16 == V_53 &&
( V_2 -> V_5 . V_179 & V_1081 ) ) {
V_2 -> V_5 . V_179 &= ~ V_1081 ;
F_92 ( V_2 ) ;
}
V_73 -> V_1082 ( V_2 , V_2 -> V_5 . V_68 . V_16 ,
V_2 -> V_5 . V_68 . V_71 ,
V_2 -> V_5 . V_68 . V_62 ,
V_2 -> V_5 . V_68 . V_63 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_645 ) {
V_73 -> V_1083 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_640 . V_69 ) {
V_73 -> V_1084 ( V_2 ) ;
return 0 ;
}
if ( F_427 ( V_2 ) && V_73 -> V_1085 ) {
V_120 = V_73 -> V_1085 ( V_2 , V_1080 ) ;
if ( V_120 != 0 )
return V_120 ;
}
if ( V_2 -> V_5 . V_646 ) {
if ( V_73 -> V_1086 ( V_2 ) ) {
-- V_2 -> V_5 . V_646 ;
V_2 -> V_5 . V_645 = true ;
V_73 -> V_1083 ( V_2 ) ;
}
} else if ( F_514 ( V_2 ) ) {
if ( F_427 ( V_2 ) && V_73 -> V_1085 ) {
V_120 = V_73 -> V_1085 ( V_2 , V_1080 ) ;
if ( V_120 != 0 )
return V_120 ;
}
if ( V_73 -> V_1087 ( V_2 ) ) {
F_258 ( V_2 , F_515 ( V_2 ) ,
false ) ;
V_73 -> V_1084 ( V_2 ) ;
}
}
return 0 ;
}
static void F_264 ( struct V_1 * V_2 )
{
unsigned V_903 = 2 ;
if ( V_73 -> V_648 ( V_2 ) || V_2 -> V_5 . V_645 )
V_903 = 1 ;
V_2 -> V_5 . V_646 += F_516 ( & V_2 -> V_5 . V_85 , 0 ) ;
V_2 -> V_5 . V_646 = F_329 ( V_2 -> V_5 . V_646 , V_903 ) ;
F_31 ( V_67 , V_2 ) ;
}
static void F_517 ( struct V_1 * V_2 )
{
T_2 V_1088 [ 4 ] ;
T_1 V_1089 [ 8 ] ;
if ( ! F_518 ( V_2 -> V_5 . V_618 ) )
return;
memset ( V_1088 , 0 , 32 ) ;
memset ( V_1089 , 0 , 32 ) ;
F_519 ( V_2 , V_1088 , V_1089 ) ;
V_73 -> V_1090 ( V_2 , V_1088 ) ;
F_520 ( V_2 , V_1089 ) ;
}
static void F_521 ( struct V_1 * V_2 )
{
++ V_2 -> V_77 . V_1091 ;
V_73 -> V_1091 ( V_2 ) ;
}
void F_522 ( struct V_1 * V_2 )
{
struct V_395 * V_395 = NULL ;
if ( ! F_87 ( V_2 -> V_102 ) )
return;
if ( ! V_73 -> V_1092 )
return;
V_395 = F_367 ( V_2 -> V_102 , V_836 >> V_107 ) ;
V_73 -> V_1092 ( V_2 , F_523 ( V_395 ) ) ;
F_524 ( V_395 ) ;
}
void F_525 ( struct V_102 * V_102 ,
unsigned long V_80 )
{
if ( V_80 == F_191 ( V_102 , V_836 >> V_107 ) )
F_526 ( V_102 , V_1093 ) ;
}
static int F_527 ( struct V_1 * V_2 )
{
int V_120 ;
bool V_1080 = ! F_87 ( V_2 -> V_102 ) &&
V_2 -> V_843 -> V_1075 ;
bool V_1094 = false ;
if ( V_2 -> V_322 ) {
if ( F_528 ( V_1095 , V_2 ) )
F_529 ( V_2 ) ;
if ( F_528 ( V_1096 , V_2 ) )
F_530 ( V_2 ) ;
if ( F_528 ( V_284 , V_2 ) )
F_157 ( V_2 -> V_102 ) ;
if ( F_528 ( V_466 , V_2 ) )
F_173 ( V_2 ) ;
if ( F_528 ( V_320 , V_2 ) ) {
V_120 = F_161 ( V_2 ) ;
if ( F_151 ( V_120 ) )
goto V_114;
}
if ( F_528 ( V_1097 , V_2 ) )
F_84 ( V_2 ) ;
if ( F_528 ( V_169 , V_2 ) )
F_521 ( V_2 ) ;
if ( F_528 ( V_1098 , V_2 ) ) {
V_2 -> V_843 -> V_858 = V_1099 ;
V_120 = 0 ;
goto V_114;
}
if ( F_528 ( V_72 , V_2 ) ) {
V_2 -> V_843 -> V_858 = V_1100 ;
V_120 = 0 ;
goto V_114;
}
if ( F_528 ( V_1101 , V_2 ) ) {
V_2 -> V_1102 = 0 ;
V_73 -> V_1103 ( V_2 ) ;
}
if ( F_528 ( V_1104 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1105 = true ;
V_120 = 1 ;
goto V_114;
}
if ( F_528 ( V_471 , V_2 ) )
F_205 ( V_2 ) ;
if ( F_528 ( V_86 , V_2 ) )
F_264 ( V_2 ) ;
if ( F_528 ( V_1106 , V_2 ) )
F_531 ( V_2 ) ;
if ( F_528 ( V_1107 , V_2 ) )
F_532 ( V_2 ) ;
if ( F_528 ( V_1108 , V_2 ) )
F_517 ( V_2 ) ;
if ( F_528 ( V_1093 , V_2 ) )
F_522 ( V_2 ) ;
}
if ( F_528 ( V_67 , V_2 ) || V_1080 ) {
F_533 ( V_2 ) ;
if ( V_2 -> V_5 . V_1036 == V_1109 ) {
V_120 = 1 ;
goto V_114;
}
if ( F_512 ( V_2 , V_1080 ) != 0 )
V_1094 = true ;
else if ( V_2 -> V_5 . V_646 )
V_73 -> V_1110 ( V_2 ) ;
else if ( F_514 ( V_2 ) || V_1080 )
V_73 -> V_1111 ( V_2 ) ;
if ( F_534 ( V_2 ) ) {
if ( V_73 -> V_1112 )
V_73 -> V_1112 ( V_2 ,
F_511 ( V_2 ) ) ;
F_256 ( V_2 ) ;
F_535 ( V_2 ) ;
}
}
V_120 = F_536 ( V_2 ) ;
if ( F_151 ( V_120 ) ) {
goto V_1113;
}
F_210 () ;
V_73 -> V_1114 ( V_2 ) ;
if ( V_2 -> V_1102 )
F_415 ( V_2 ) ;
F_69 ( V_2 ) ;
V_2 -> V_314 = V_1115 ;
F_231 ( & V_2 -> V_102 -> V_518 , V_2 -> V_1116 ) ;
F_537 () ;
F_323 () ;
if ( V_2 -> V_314 == V_1117 || V_2 -> V_322
|| F_538 () || F_539 ( V_432 ) ) {
V_2 -> V_314 = V_1118 ;
F_14 () ;
F_324 () ;
F_211 () ;
V_2 -> V_1116 = F_230 ( & V_2 -> V_102 -> V_518 ) ;
V_120 = 1 ;
goto V_1113;
}
if ( V_1094 )
F_540 ( V_2 -> V_23 ) ;
F_541 () ;
if ( F_151 ( V_2 -> V_5 . V_182 ) ) {
F_542 ( 0 , 7 ) ;
F_542 ( V_2 -> V_5 . V_190 [ 0 ] , 0 ) ;
F_542 ( V_2 -> V_5 . V_190 [ 1 ] , 1 ) ;
F_542 ( V_2 -> V_5 . V_190 [ 2 ] , 2 ) ;
F_542 ( V_2 -> V_5 . V_190 [ 3 ] , 3 ) ;
F_542 ( V_2 -> V_5 . V_178 , 6 ) ;
}
F_543 ( V_2 -> V_285 ) ;
V_73 -> V_843 ( V_2 ) ;
if ( F_151 ( V_2 -> V_5 . V_182 & V_1119 ) ) {
int V_3 ;
F_29 ( V_2 -> V_175 & V_176 ) ;
V_73 -> V_1120 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_1121 ; V_3 ++ )
V_2 -> V_5 . V_190 [ V_3 ] = V_2 -> V_5 . V_189 [ V_3 ] ;
}
if ( F_544 () )
F_545 () ;
V_2 -> V_5 . V_308 = V_73 -> V_330 ( V_2 ,
F_165 () ) ;
V_2 -> V_314 = V_1118 ;
F_14 () ;
V_73 -> V_1122 ( V_2 ) ;
++ V_2 -> V_77 . V_1123 ;
F_546 () ;
F_547 () ;
F_211 () ;
V_2 -> V_1116 = F_230 ( & V_2 -> V_102 -> V_518 ) ;
if ( F_151 ( V_1124 == V_1125 ) ) {
unsigned long V_1074 = F_426 ( V_2 ) ;
F_548 ( V_1125 , ( void * ) V_1074 ) ;
}
if ( F_151 ( V_2 -> V_5 . V_1126 ) )
F_31 ( V_320 , V_2 ) ;
if ( V_2 -> V_5 . V_1127 )
F_549 ( V_2 ) ;
V_120 = V_73 -> V_1128 ( V_2 ) ;
return V_120 ;
V_1113:
V_73 -> V_1113 ( V_2 ) ;
if ( F_151 ( V_2 -> V_5 . V_1127 ) )
F_549 ( V_2 ) ;
V_114:
return V_120 ;
}
static int F_550 ( struct V_1 * V_2 )
{
int V_120 ;
struct V_102 * V_102 = V_2 -> V_102 ;
V_2 -> V_1116 = F_230 ( & V_102 -> V_518 ) ;
V_120 = 1 ;
while ( V_120 > 0 ) {
if ( V_2 -> V_5 . V_1036 == V_1129 &&
! V_2 -> V_5 . V_6 . V_1105 )
V_120 = F_527 ( V_2 ) ;
else {
F_231 ( & V_102 -> V_518 , V_2 -> V_1116 ) ;
F_551 ( V_2 ) ;
V_2 -> V_1116 = F_230 ( & V_102 -> V_518 ) ;
if ( F_528 ( V_1130 , V_2 ) ) {
F_533 ( V_2 ) ;
switch( V_2 -> V_5 . V_1036 ) {
case V_1037 :
V_2 -> V_5 . V_1131 . V_1132 = false ;
V_2 -> V_5 . V_1036 =
V_1129 ;
case V_1129 :
V_2 -> V_5 . V_6 . V_1105 = false ;
break;
case V_1109 :
break;
default:
V_120 = - V_1133 ;
break;
}
}
}
if ( V_120 <= 0 )
break;
F_160 ( V_1134 , & V_2 -> V_322 ) ;
if ( F_552 ( V_2 ) )
F_553 ( V_2 ) ;
if ( F_506 ( V_2 ) ) {
V_120 = - V_1133 ;
V_2 -> V_843 -> V_858 = V_1135 ;
++ V_2 -> V_77 . V_1136 ;
}
F_554 ( V_2 ) ;
if ( F_539 ( V_432 ) ) {
V_120 = - V_1133 ;
V_2 -> V_843 -> V_858 = V_1135 ;
++ V_2 -> V_77 . V_1137 ;
}
if ( F_538 () ) {
F_231 ( & V_102 -> V_518 , V_2 -> V_1116 ) ;
F_555 () ;
V_2 -> V_1116 = F_230 ( & V_102 -> V_518 ) ;
}
}
F_231 ( & V_102 -> V_518 , V_2 -> V_1116 ) ;
return V_120 ;
}
static inline int F_556 ( struct V_1 * V_2 )
{
int V_120 ;
V_2 -> V_1116 = F_230 ( & V_2 -> V_102 -> V_518 ) ;
V_120 = F_557 ( V_2 , V_971 ) ;
F_231 ( & V_2 -> V_102 -> V_518 , V_2 -> V_1116 ) ;
if ( V_120 != V_939 )
return 0 ;
return 1 ;
}
static int V_984 ( struct V_1 * V_2 )
{
F_13 ( ! V_2 -> V_5 . V_873 . V_745 ) ;
return F_556 ( V_2 ) ;
}
static int V_985 ( struct V_1 * V_2 )
{
struct V_958 * V_843 = V_2 -> V_843 ;
struct V_841 * V_842 ;
unsigned V_95 ;
F_13 ( ! V_2 -> V_854 ) ;
V_842 = & V_2 -> V_838 [ V_2 -> V_855 ] ;
V_95 = F_329 ( 8u , V_842 -> V_95 ) ;
if ( ! V_2 -> V_857 )
memcpy ( V_842 -> V_38 , V_843 -> V_844 . V_38 , V_95 ) ;
if ( V_842 -> V_95 <= 8 ) {
V_842 ++ ;
V_2 -> V_855 ++ ;
} else {
V_842 -> V_38 += V_95 ;
V_842 -> V_426 += V_95 ;
V_842 -> V_95 -= V_95 ;
}
if ( V_2 -> V_855 >= V_2 -> V_849 ) {
V_2 -> V_854 = 0 ;
if ( V_2 -> V_857 )
return 1 ;
V_2 -> V_837 = 1 ;
return F_556 ( V_2 ) ;
}
V_843 -> V_858 = V_859 ;
V_843 -> V_844 . V_860 = V_842 -> V_426 ;
if ( V_2 -> V_857 )
memcpy ( V_843 -> V_844 . V_38 , V_842 -> V_38 , F_329 ( 8u , V_842 -> V_95 ) ) ;
V_843 -> V_844 . V_95 = F_329 ( 8u , V_842 -> V_95 ) ;
V_843 -> V_844 . V_856 = V_2 -> V_857 ;
V_2 -> V_5 . V_983 = V_985 ;
return 0 ;
}
int F_558 ( struct V_1 * V_2 , struct V_958 * V_958 )
{
int V_120 ;
T_19 V_1138 ;
if ( ! F_559 ( V_432 ) && F_560 ( V_432 ) )
return - V_397 ;
if ( V_2 -> V_1139 )
F_561 ( V_1140 , & V_2 -> V_1141 , & V_1138 ) ;
if ( F_151 ( V_2 -> V_5 . V_1036 == V_1142 ) ) {
F_551 ( V_2 ) ;
F_533 ( V_2 ) ;
F_160 ( V_1130 , & V_2 -> V_322 ) ;
V_120 = - V_1143 ;
goto V_114;
}
if ( ! F_87 ( V_2 -> V_102 ) ) {
if ( F_86 ( V_2 , V_958 -> V_173 ) != 0 ) {
V_120 = - V_605 ;
goto V_114;
}
}
if ( F_151 ( V_2 -> V_5 . V_983 ) ) {
int (* F_562)( struct V_1 * ) = V_2 -> V_5 . V_983 ;
V_2 -> V_5 . V_983 = NULL ;
V_120 = F_562 ( V_2 ) ;
if ( V_120 <= 0 )
goto V_114;
} else
F_29 ( V_2 -> V_5 . V_873 . V_745 || V_2 -> V_854 ) ;
V_120 = F_550 ( V_2 ) ;
V_114:
F_509 ( V_2 ) ;
if ( V_2 -> V_1139 )
F_561 ( V_1140 , & V_1138 , NULL ) ;
return V_120 ;
}
int F_563 ( struct V_1 * V_2 , struct V_1144 * V_617 )
{
if ( V_2 -> V_5 . V_988 ) {
F_564 ( & V_2 -> V_5 . V_922 ) ;
V_2 -> V_5 . V_988 = false ;
}
V_617 -> V_1145 = F_99 ( V_2 , V_197 ) ;
V_617 -> V_1146 = F_99 ( V_2 , V_1049 ) ;
V_617 -> V_1147 = F_99 ( V_2 , V_196 ) ;
V_617 -> V_1148 = F_99 ( V_2 , V_198 ) ;
V_617 -> V_1149 = F_99 ( V_2 , V_1051 ) ;
V_617 -> V_1150 = F_99 ( V_2 , V_1050 ) ;
V_617 -> V_1151 = F_99 ( V_2 , V_1152 ) ;
V_617 -> V_1153 = F_99 ( V_2 , V_1154 ) ;
#ifdef F_63
V_617 -> V_1155 = F_99 ( V_2 , V_1052 ) ;
V_617 -> V_1156 = F_99 ( V_2 , V_1157 ) ;
V_617 -> V_1158 = F_99 ( V_2 , V_1159 ) ;
V_617 -> V_1160 = F_99 ( V_2 , V_1161 ) ;
V_617 -> V_1162 = F_99 ( V_2 , V_1163 ) ;
V_617 -> V_1164 = F_99 ( V_2 , V_1165 ) ;
V_617 -> V_1166 = F_99 ( V_2 , V_1167 ) ;
V_617 -> V_1168 = F_99 ( V_2 , V_1169 ) ;
#endif
V_617 -> V_1074 = F_426 ( V_2 ) ;
V_617 -> V_957 = F_425 ( V_2 ) ;
return 0 ;
}
int F_565 ( struct V_1 * V_2 , struct V_1144 * V_617 )
{
V_2 -> V_5 . V_933 = true ;
V_2 -> V_5 . V_988 = false ;
F_101 ( V_2 , V_197 , V_617 -> V_1145 ) ;
F_101 ( V_2 , V_1049 , V_617 -> V_1146 ) ;
F_101 ( V_2 , V_196 , V_617 -> V_1147 ) ;
F_101 ( V_2 , V_198 , V_617 -> V_1148 ) ;
F_101 ( V_2 , V_1051 , V_617 -> V_1149 ) ;
F_101 ( V_2 , V_1050 , V_617 -> V_1150 ) ;
F_101 ( V_2 , V_1152 , V_617 -> V_1151 ) ;
F_101 ( V_2 , V_1154 , V_617 -> V_1153 ) ;
#ifdef F_63
F_101 ( V_2 , V_1052 , V_617 -> V_1155 ) ;
F_101 ( V_2 , V_1157 , V_617 -> V_1156 ) ;
F_101 ( V_2 , V_1159 , V_617 -> V_1158 ) ;
F_101 ( V_2 , V_1161 , V_617 -> V_1160 ) ;
F_101 ( V_2 , V_1163 , V_617 -> V_1162 ) ;
F_101 ( V_2 , V_1165 , V_617 -> V_1164 ) ;
F_101 ( V_2 , V_1167 , V_617 -> V_1166 ) ;
F_101 ( V_2 , V_1169 , V_617 -> V_1168 ) ;
#endif
F_431 ( V_2 , V_617 -> V_1074 ) ;
F_432 ( V_2 , V_617 -> V_957 ) ;
V_2 -> V_5 . V_68 . V_69 = false ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
void F_566 ( struct V_1 * V_2 , int * V_189 , int * V_908 )
{
struct V_817 V_1170 ;
F_337 ( V_2 , & V_1170 , V_1171 ) ;
* V_189 = V_1170 . V_189 ;
* V_908 = V_1170 . V_908 ;
}
int F_567 ( struct V_1 * V_2 ,
struct V_1172 * V_1173 )
{
struct V_891 V_892 ;
F_337 ( V_2 , & V_1173 -> V_1170 , V_1171 ) ;
F_337 ( V_2 , & V_1173 -> V_1174 , V_1175 ) ;
F_337 ( V_2 , & V_1173 -> V_1176 , V_1177 ) ;
F_337 ( V_2 , & V_1173 -> V_1178 , V_1179 ) ;
F_337 ( V_2 , & V_1173 -> V_1180 , V_1181 ) ;
F_337 ( V_2 , & V_1173 -> V_1182 , V_1183 ) ;
F_337 ( V_2 , & V_1173 -> V_1184 , V_1185 ) ;
F_337 ( V_2 , & V_1173 -> V_1186 , V_1187 ) ;
V_73 -> V_894 ( V_2 , & V_892 ) ;
V_1173 -> V_1188 . V_903 = V_892 . V_523 ;
V_1173 -> V_1188 . V_904 = V_892 . V_80 ;
V_73 -> V_893 ( V_2 , & V_892 ) ;
V_1173 -> V_1189 . V_903 = V_892 . V_523 ;
V_1173 -> V_1189 . V_904 = V_892 . V_80 ;
V_1173 -> V_121 = F_62 ( V_2 ) ;
V_1173 -> V_79 = V_2 -> V_5 . V_79 ;
V_1173 -> V_105 = F_60 ( V_2 ) ;
V_1173 -> V_156 = F_76 ( V_2 ) ;
V_1173 -> V_173 = F_89 ( V_2 ) ;
V_1173 -> V_131 = V_2 -> V_5 . V_131 ;
V_1173 -> V_31 = F_20 ( V_2 ) ;
memset ( V_1173 -> V_1190 , 0 , sizeof V_1173 -> V_1190 ) ;
if ( V_2 -> V_5 . V_640 . V_69 && ! V_2 -> V_5 . V_640 . V_641 )
F_568 ( V_2 -> V_5 . V_640 . V_16 ,
( unsigned long * ) V_1173 -> V_1190 ) ;
return 0 ;
}
int F_569 ( struct V_1 * V_2 ,
struct V_1191 * V_1036 )
{
F_533 ( V_2 ) ;
if ( V_2 -> V_5 . V_1036 == V_1037 &&
V_2 -> V_5 . V_1131 . V_1132 )
V_1036 -> V_1036 = V_1129 ;
else
V_1036 -> V_1036 = V_2 -> V_5 . V_1036 ;
return 0 ;
}
int F_570 ( struct V_1 * V_2 ,
struct V_1191 * V_1036 )
{
if ( ! F_267 ( V_2 ) &&
V_1036 -> V_1036 != V_1129 )
return - V_605 ;
if ( V_1036 -> V_1036 == V_1192 ) {
V_2 -> V_5 . V_1036 = V_1109 ;
F_568 ( V_1193 , & V_2 -> V_5 . V_618 -> V_1194 ) ;
} else
V_2 -> V_5 . V_1036 = V_1036 -> V_1036 ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
int F_571 ( struct V_1 * V_2 , V_869 V_1195 , int V_1196 ,
int V_1197 , bool V_71 , T_1 V_62 )
{
struct V_831 * V_832 = & V_2 -> V_5 . V_922 ;
int V_109 ;
F_424 ( V_2 ) ;
V_109 = F_572 ( V_832 , V_1195 , V_1196 , V_1197 ,
V_71 , V_62 ) ;
if ( V_109 )
return V_938 ;
F_431 ( V_2 , V_832 -> V_925 ) ;
F_432 ( V_2 , V_832 -> V_924 ) ;
F_31 ( V_67 , V_2 ) ;
return V_939 ;
}
int F_573 ( struct V_1 * V_2 ,
struct V_1172 * V_1173 )
{
struct V_32 V_1198 ;
int V_1199 = 0 ;
int V_1200 , V_1201 , V_370 ;
struct V_891 V_892 ;
if ( ! F_77 ( V_2 ) && ( V_1173 -> V_156 & V_139 ) )
return - V_605 ;
V_892 . V_523 = V_1173 -> V_1188 . V_903 ;
V_892 . V_80 = V_1173 -> V_1188 . V_904 ;
V_73 -> V_896 ( V_2 , & V_892 ) ;
V_892 . V_523 = V_1173 -> V_1189 . V_903 ;
V_892 . V_80 = V_1173 -> V_1189 . V_904 ;
V_73 -> V_895 ( V_2 , & V_892 ) ;
V_2 -> V_5 . V_79 = V_1173 -> V_79 ;
V_1199 |= F_60 ( V_2 ) != V_1173 -> V_105 ;
V_2 -> V_5 . V_105 = V_1173 -> V_105 ;
F_55 ( V_171 , ( V_172 * ) & V_2 -> V_5 . V_117 ) ;
F_86 ( V_2 , V_1173 -> V_173 ) ;
V_1199 |= V_2 -> V_5 . V_131 != V_1173 -> V_131 ;
V_73 -> F_105 ( V_2 , V_1173 -> V_131 ) ;
V_1198 . V_38 = V_1173 -> V_31 ;
V_1198 . V_40 = true ;
F_21 ( V_2 , & V_1198 ) ;
V_1199 |= F_62 ( V_2 ) != V_1173 -> V_121 ;
V_73 -> V_137 ( V_2 , V_1173 -> V_121 ) ;
V_2 -> V_5 . V_121 = V_1173 -> V_121 ;
V_1199 |= F_76 ( V_2 ) != V_1173 -> V_156 ;
V_73 -> V_167 ( V_2 , V_1173 -> V_156 ) ;
if ( V_1173 -> V_156 & V_139 )
F_73 ( V_2 ) ;
V_370 = F_230 ( & V_2 -> V_102 -> V_518 ) ;
if ( ! F_57 ( V_2 ) && F_58 ( V_2 ) ) {
F_52 ( V_2 , V_2 -> V_5 . V_104 , F_60 ( V_2 ) ) ;
V_1199 = 1 ;
}
F_231 ( & V_2 -> V_102 -> V_518 , V_370 ) ;
if ( V_1199 )
F_66 ( V_2 ) ;
V_1201 = V_621 ;
V_1200 = F_574 (
( const unsigned long * ) V_1173 -> V_1190 , V_1201 ) ;
if ( V_1200 < V_1201 ) {
F_258 ( V_2 , V_1200 , false ) ;
F_124 ( L_29 , V_1200 ) ;
}
F_336 ( V_2 , & V_1173 -> V_1170 , V_1171 ) ;
F_336 ( V_2 , & V_1173 -> V_1174 , V_1175 ) ;
F_336 ( V_2 , & V_1173 -> V_1176 , V_1177 ) ;
F_336 ( V_2 , & V_1173 -> V_1178 , V_1179 ) ;
F_336 ( V_2 , & V_1173 -> V_1180 , V_1181 ) ;
F_336 ( V_2 , & V_1173 -> V_1182 , V_1183 ) ;
F_336 ( V_2 , & V_1173 -> V_1184 , V_1185 ) ;
F_336 ( V_2 , & V_1173 -> V_1186 , V_1187 ) ;
F_256 ( V_2 ) ;
if ( F_575 ( V_2 ) && F_426 ( V_2 ) == 0xfff0 &&
V_1173 -> V_1170 . V_897 == 0xf000 && V_1173 -> V_1170 . V_904 == 0xffff0000 &&
! F_32 ( V_2 ) )
V_2 -> V_5 . V_1036 = V_1129 ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
int F_576 ( struct V_1 * V_2 ,
struct V_1202 * V_1203 )
{
unsigned long V_957 ;
int V_3 , V_120 ;
if ( V_1203 -> V_752 & ( V_1204 | V_1205 ) ) {
V_120 = - V_1206 ;
if ( V_2 -> V_5 . V_68 . V_69 )
goto V_114;
if ( V_1203 -> V_752 & V_1204 )
F_33 ( V_2 , V_53 ) ;
else
F_33 ( V_2 , V_54 ) ;
}
V_957 = F_425 ( V_2 ) ;
V_2 -> V_175 = V_1203 -> V_752 ;
if ( ! ( V_2 -> V_175 & V_1207 ) )
V_2 -> V_175 = 0 ;
if ( V_2 -> V_175 & V_176 ) {
for ( V_3 = 0 ; V_3 < V_1121 ; ++ V_3 )
V_2 -> V_5 . V_190 [ V_3 ] = V_1203 -> V_5 . V_1208 [ V_3 ] ;
V_2 -> V_5 . V_180 = V_1203 -> V_5 . V_1208 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_1121 ; V_3 ++ )
V_2 -> V_5 . V_190 [ V_3 ] = V_2 -> V_5 . V_189 [ V_3 ] ;
}
F_92 ( V_2 ) ;
if ( V_2 -> V_175 & V_960 )
V_2 -> V_5 . V_964 = F_426 ( V_2 ) +
F_381 ( V_2 , V_1171 ) ;
F_432 ( V_2 , V_957 ) ;
V_73 -> V_1209 ( V_2 ) ;
V_120 = 0 ;
V_114:
return V_120 ;
}
int F_577 ( struct V_1 * V_2 ,
struct V_1210 * V_1184 )
{
unsigned long V_1211 = V_1184 -> V_1212 ;
T_6 V_426 ;
int V_370 ;
V_370 = F_230 ( & V_2 -> V_102 -> V_518 ) ;
V_426 = F_342 ( V_2 , V_1211 , NULL ) ;
F_231 ( & V_2 -> V_102 -> V_518 , V_370 ) ;
V_1184 -> V_1213 = V_426 ;
V_1184 -> V_665 = V_426 != V_100 ;
V_1184 -> V_1214 = 1 ;
V_1184 -> V_1215 = 0 ;
return 0 ;
}
int F_578 ( struct V_1 * V_2 , struct V_1216 * V_1217 )
{
struct V_678 * V_677 =
& V_2 -> V_5 . V_661 . V_662 -> V_677 ;
memcpy ( V_1217 -> V_1218 , V_677 -> V_1219 , 128 ) ;
V_1217 -> V_1220 = V_677 -> V_1221 ;
V_1217 -> V_1222 = V_677 -> V_1223 ;
V_1217 -> V_1224 = V_677 -> V_1225 ;
V_1217 -> V_1226 = V_677 -> V_1227 ;
V_1217 -> V_1228 = V_677 -> V_1074 ;
V_1217 -> V_1229 = V_677 -> V_1230 ;
memcpy ( V_1217 -> V_1231 , V_677 -> V_1232 , sizeof V_677 -> V_1232 ) ;
return 0 ;
}
int F_579 ( struct V_1 * V_2 , struct V_1216 * V_1217 )
{
struct V_678 * V_677 =
& V_2 -> V_5 . V_661 . V_662 -> V_677 ;
memcpy ( V_677 -> V_1219 , V_1217 -> V_1218 , 128 ) ;
V_677 -> V_1221 = V_1217 -> V_1220 ;
V_677 -> V_1223 = V_1217 -> V_1222 ;
V_677 -> V_1225 = V_1217 -> V_1224 ;
V_677 -> V_1227 = V_1217 -> V_1226 ;
V_677 -> V_1074 = V_1217 -> V_1228 ;
V_677 -> V_1230 = V_1217 -> V_1229 ;
memcpy ( V_677 -> V_1232 , V_1217 -> V_1231 , sizeof V_677 -> V_1232 ) ;
return 0 ;
}
int F_580 ( struct V_1 * V_2 )
{
int V_29 ;
V_29 = F_581 ( & V_2 -> V_5 . V_661 ) ;
if ( V_29 )
return V_29 ;
F_582 ( & V_2 -> V_5 . V_661 ) ;
if ( V_671 )
V_2 -> V_5 . V_661 . V_662 -> V_660 . V_664 . V_672 =
V_143 | V_673 ;
V_2 -> V_5 . V_142 = V_148 ;
V_2 -> V_5 . V_121 |= V_128 ;
return 0 ;
}
static void F_583 ( struct V_1 * V_2 )
{
F_584 ( & V_2 -> V_5 . V_661 ) ;
}
void F_415 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1233 )
return;
F_71 ( V_2 ) ;
V_2 -> V_1233 = 1 ;
F_585 () ;
F_586 ( & V_2 -> V_5 . V_661 ) ;
F_587 ( 1 ) ;
}
void F_252 ( struct V_1 * V_2 )
{
F_71 ( V_2 ) ;
if ( ! V_2 -> V_1233 )
return;
V_2 -> V_1233 = 0 ;
F_588 ( & V_2 -> V_5 . V_661 ) ;
F_589 () ;
++ V_2 -> V_77 . V_1234 ;
F_31 ( V_1101 , V_2 ) ;
F_587 ( 0 ) ;
}
void F_590 ( struct V_1 * V_2 )
{
F_203 ( V_2 ) ;
F_591 ( V_2 -> V_5 . V_608 ) ;
F_583 ( V_2 ) ;
V_73 -> V_1235 ( V_2 ) ;
}
struct V_1 * F_592 ( struct V_102 * V_102 ,
unsigned int V_1236 )
{
if ( F_139 () && F_134 ( & V_102 -> V_281 ) != 0 )
F_375 ( V_871
L_30
L_31 ) ;
return V_73 -> V_1237 ( V_102 , V_1236 ) ;
}
int F_593 ( struct V_1 * V_2 )
{
int V_120 ;
V_2 -> V_5 . V_365 . V_1238 = 1 ;
V_120 = V_609 ( V_2 ) ;
if ( V_120 )
return V_120 ;
F_594 ( V_2 ) ;
F_595 ( V_2 ) ;
V_613 ( V_2 ) ;
return V_120 ;
}
int F_596 ( struct V_1 * V_2 )
{
int V_120 ;
struct V_32 V_21 ;
struct V_102 * V_102 = V_2 -> V_102 ;
V_120 = V_609 ( V_2 ) ;
if ( V_120 )
return V_120 ;
V_21 . V_38 = 0x0 ;
V_21 . V_144 = V_1239 ;
V_21 . V_40 = true ;
F_137 ( V_2 , & V_21 ) ;
V_613 ( V_2 ) ;
F_174 ( & V_102 -> V_5 . V_348 ,
V_349 ) ;
return V_120 ;
}
void F_597 ( struct V_1 * V_2 )
{
int V_120 ;
V_2 -> V_5 . V_6 . V_427 = 0 ;
V_120 = V_609 ( V_2 ) ;
F_13 ( V_120 ) ;
F_529 ( V_2 ) ;
V_613 ( V_2 ) ;
F_583 ( V_2 ) ;
V_73 -> V_1235 ( V_2 ) ;
}
void F_594 ( struct V_1 * V_2 )
{
F_155 ( & V_2 -> V_5 . V_85 , 0 ) ;
V_2 -> V_5 . V_646 = 0 ;
V_2 -> V_5 . V_645 = false ;
F_598 ( V_2 ) ;
F_447 ( V_2 ) ;
memset ( V_2 -> V_5 . V_189 , 0 , sizeof( V_2 -> V_5 . V_189 ) ) ;
V_2 -> V_5 . V_178 = V_1240 ;
F_91 ( V_2 ) ;
V_2 -> V_5 . V_179 = V_193 ;
F_92 ( V_2 ) ;
F_31 ( V_67 , V_2 ) ;
V_2 -> V_5 . V_6 . V_427 = 0 ;
V_2 -> V_5 . V_431 . V_427 = 0 ;
F_203 ( V_2 ) ;
F_65 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1105 = false ;
F_599 ( V_2 ) ;
memset ( V_2 -> V_5 . V_617 , 0 , sizeof( V_2 -> V_5 . V_617 ) ) ;
V_2 -> V_5 . V_117 = ~ 0 ;
V_2 -> V_5 . V_118 = ~ 0 ;
V_73 -> V_1241 ( V_2 ) ;
}
void F_600 ( struct V_1 * V_2 , T_14 V_41 )
{
struct V_817 V_1170 ;
F_337 ( V_2 , & V_1170 , V_1171 ) ;
V_1170 . V_897 = V_41 << 8 ;
V_1170 . V_904 = V_41 << 12 ;
F_336 ( V_2 , & V_1170 , V_1171 ) ;
F_431 ( V_2 , 0 ) ;
}
int F_601 ( void )
{
struct V_102 * V_102 ;
struct V_1 * V_2 ;
int V_3 ;
int V_109 ;
T_2 V_1242 ;
T_2 V_1243 = 0 ;
bool V_1244 , V_1245 = false ;
F_15 () ;
V_109 = V_73 -> V_1246 () ;
if ( V_109 != 0 )
return V_109 ;
V_1242 = F_165 () ;
V_1244 = ! F_139 () ;
F_460 (kvm, &vm_list, vm_list) {
F_159 (i, vcpu, kvm) {
if ( ! V_1244 && V_2 -> V_23 == F_8 () )
F_31 ( V_320 , V_2 ) ;
if ( V_1244 && V_2 -> V_5 . V_612 > V_1242 ) {
V_1245 = true ;
if ( V_2 -> V_5 . V_612 > V_1243 )
V_1243 = V_2 -> V_5 . V_612 ;
}
}
}
if ( V_1245 ) {
T_2 V_1247 = V_1243 - V_1242 ;
V_318 = true ;
F_460 (kvm, &vm_list, vm_list) {
F_159 (i, vcpu, kvm) {
V_2 -> V_5 . V_610 += V_1247 ;
V_2 -> V_5 . V_612 = V_1242 ;
F_31 ( V_284 , V_2 ) ;
}
V_102 -> V_5 . V_297 = 0 ;
V_102 -> V_5 . V_299 = 0 ;
}
}
return 0 ;
}
void F_602 ( void )
{
V_73 -> V_1248 () ;
F_19 () ;
}
int F_603 ( void )
{
return V_73 -> V_1249 () ;
}
void F_604 ( void )
{
V_73 -> V_1250 () ;
}
void F_605 ( void * V_1251 )
{
V_73 -> V_1252 ( V_1251 ) ;
}
bool F_606 ( struct V_1 * V_2 )
{
return F_87 ( V_2 -> V_102 ) == ( V_2 -> V_5 . V_618 != NULL ) ;
}
int F_607 ( struct V_1 * V_2 )
{
struct V_395 * V_395 ;
struct V_102 * V_102 ;
int V_120 ;
F_13 ( V_2 -> V_102 == NULL ) ;
V_102 = V_2 -> V_102 ;
V_2 -> V_5 . V_1131 . V_1132 = false ;
V_2 -> V_5 . V_922 . V_846 = & V_1253 ;
if ( ! F_87 ( V_102 ) || F_575 ( V_2 ) )
V_2 -> V_5 . V_1036 = V_1129 ;
else
V_2 -> V_5 . V_1036 = V_1142 ;
V_395 = F_608 ( V_689 | V_1254 ) ;
if ( ! V_395 ) {
V_120 = - V_397 ;
goto V_1255;
}
V_2 -> V_5 . V_876 = F_609 ( V_395 ) ;
F_131 ( V_2 , V_1006 ) ;
V_120 = F_610 ( V_2 ) ;
if ( V_120 < 0 )
goto V_1256;
if ( F_87 ( V_102 ) ) {
V_120 = F_611 ( V_2 ) ;
if ( V_120 < 0 )
goto V_1257;
} else
F_612 ( & V_1258 ) ;
V_2 -> V_5 . V_384 = F_283 ( V_473 * sizeof( T_2 ) * 4 ,
V_689 ) ;
if ( ! V_2 -> V_5 . V_384 ) {
V_120 = - V_397 ;
goto V_1259;
}
V_2 -> V_5 . V_376 = V_473 ;
if ( ! F_613 ( & V_2 -> V_5 . V_608 , V_689 ) ) {
V_120 = - V_397 ;
goto V_1260;
}
V_120 = F_580 ( V_2 ) ;
if ( V_120 )
goto V_1261;
V_2 -> V_5 . V_288 = 0x0 ;
V_2 -> V_5 . V_332 = false ;
V_2 -> V_5 . V_151 = 0 ;
V_2 -> V_5 . V_1262 = V_1263 + V_666 ;
F_1 ( V_2 ) ;
F_614 ( V_2 ) ;
return 0 ;
V_1261:
F_591 ( V_2 -> V_5 . V_608 ) ;
V_1260:
F_187 ( V_2 -> V_5 . V_384 ) ;
V_1259:
F_615 ( V_2 ) ;
V_1257:
F_616 ( V_2 ) ;
V_1256:
F_617 ( ( unsigned long ) V_2 -> V_5 . V_876 ) ;
V_1255:
return V_120 ;
}
void F_618 ( struct V_1 * V_2 )
{
int V_370 ;
F_619 ( V_2 ) ;
F_187 ( V_2 -> V_5 . V_384 ) ;
F_615 ( V_2 ) ;
V_370 = F_230 ( & V_2 -> V_102 -> V_518 ) ;
F_616 ( V_2 ) ;
F_231 ( & V_2 -> V_102 -> V_518 , V_370 ) ;
F_617 ( ( unsigned long ) V_2 -> V_5 . V_876 ) ;
if ( ! F_87 ( V_2 -> V_102 ) )
F_620 ( & V_1258 ) ;
}
void F_621 ( struct V_1 * V_2 , int V_23 )
{
V_73 -> V_1264 ( V_2 , V_23 ) ;
}
int F_622 ( struct V_102 * V_102 , unsigned long type )
{
if ( type )
return - V_605 ;
F_623 ( & V_102 -> V_5 . V_1265 ) ;
F_624 ( & V_102 -> V_5 . V_1266 ) ;
F_624 ( & V_102 -> V_5 . V_1267 ) ;
F_624 ( & V_102 -> V_5 . V_1268 ) ;
F_155 ( & V_102 -> V_5 . V_1269 , 0 ) ;
F_568 ( V_767 , & V_102 -> V_5 . V_1270 ) ;
F_568 ( V_1271 ,
& V_102 -> V_5 . V_1270 ) ;
F_625 ( & V_102 -> V_5 . V_295 ) ;
F_626 ( & V_102 -> V_5 . V_1272 ) ;
F_627 ( & V_102 -> V_5 . V_310 ) ;
F_154 ( V_102 ) ;
F_628 ( & V_102 -> V_5 . V_346 , F_170 ) ;
F_628 ( & V_102 -> V_5 . V_348 , F_175 ) ;
return 0 ;
}
static void F_629 ( struct V_1 * V_2 )
{
int V_120 ;
V_120 = V_609 ( V_2 ) ;
F_13 ( V_120 ) ;
F_529 ( V_2 ) ;
V_613 ( V_2 ) ;
}
static void F_630 ( struct V_102 * V_102 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_159 (i, vcpu, kvm) {
F_65 ( V_2 ) ;
F_629 ( V_2 ) ;
}
F_159 (i, vcpu, kvm)
F_590 ( V_2 ) ;
F_214 ( & V_102 -> V_488 ) ;
for ( V_3 = 0 ; V_3 < F_134 ( & V_102 -> V_281 ) ; V_3 ++ )
V_102 -> V_1273 [ V_3 ] = NULL ;
F_155 ( & V_102 -> V_281 , 0 ) ;
F_215 ( & V_102 -> V_488 ) ;
}
void F_631 ( struct V_102 * V_102 )
{
F_632 ( & V_102 -> V_5 . V_348 ) ;
F_632 ( & V_102 -> V_5 . V_346 ) ;
F_633 ( V_102 ) ;
F_634 ( V_102 ) ;
}
void F_635 ( struct V_102 * V_102 )
{
if ( V_432 -> V_1274 == V_102 -> V_1274 ) {
struct V_1275 V_1276 ;
memset ( & V_1276 , 0 , sizeof( V_1276 ) ) ;
V_1276 . V_10 = V_1277 ;
F_636 ( V_102 , & V_1276 ) ;
V_1276 . V_10 = V_1278 ;
F_636 ( V_102 , & V_1276 ) ;
V_1276 . V_10 = V_1279 ;
F_636 ( V_102 , & V_1276 ) ;
}
F_637 ( V_102 ) ;
F_187 ( V_102 -> V_5 . V_779 ) ;
F_187 ( V_102 -> V_5 . V_1280 ) ;
F_630 ( V_102 ) ;
F_187 ( F_638 ( V_102 -> V_5 . V_1281 , 1 ) ) ;
}
void F_639 ( struct V_102 * V_102 , struct V_755 * free ,
struct V_755 * V_1282 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1283 ; ++ V_3 ) {
if ( ! V_1282 || free -> V_5 . V_1284 [ V_3 ] != V_1282 -> V_5 . V_1284 [ V_3 ] ) {
F_640 ( free -> V_5 . V_1284 [ V_3 ] ) ;
free -> V_5 . V_1284 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1282 || free -> V_5 . V_1285 [ V_3 - 1 ] !=
V_1282 -> V_5 . V_1285 [ V_3 - 1 ] ) {
F_640 ( free -> V_5 . V_1285 [ V_3 - 1 ] ) ;
free -> V_5 . V_1285 [ V_3 - 1 ] = NULL ;
}
}
}
int F_641 ( struct V_102 * V_102 , struct V_755 * V_10 ,
unsigned long V_1286 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1283 ; ++ V_3 ) {
unsigned long V_1287 ;
int V_1288 ;
int V_768 = V_3 + 1 ;
V_1288 = F_642 ( V_10 -> V_1289 + V_1286 - 1 ,
V_10 -> V_1289 , V_768 ) + 1 ;
V_10 -> V_5 . V_1284 [ V_3 ] =
F_643 ( V_1288 * sizeof( * V_10 -> V_5 . V_1284 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1284 [ V_3 ] )
goto V_398;
if ( V_3 == 0 )
continue;
V_10 -> V_5 . V_1285 [ V_3 - 1 ] = F_643 ( V_1288 *
sizeof( * V_10 -> V_5 . V_1285 [ V_3 - 1 ] ) ) ;
if ( ! V_10 -> V_5 . V_1285 [ V_3 - 1 ] )
goto V_398;
if ( V_10 -> V_1289 & ( F_644 ( V_768 ) - 1 ) )
V_10 -> V_5 . V_1285 [ V_3 - 1 ] [ 0 ] . V_1290 = 1 ;
if ( ( V_10 -> V_1289 + V_1286 ) & ( F_644 ( V_768 ) - 1 ) )
V_10 -> V_5 . V_1285 [ V_3 - 1 ] [ V_1288 - 1 ] . V_1290 = 1 ;
V_1287 = V_10 -> V_1291 >> V_107 ;
if ( ( V_10 -> V_1289 ^ V_1287 ) & ( F_644 ( V_768 ) - 1 ) ||
! F_645 () ) {
unsigned long V_809 ;
for ( V_809 = 0 ; V_809 < V_1288 ; ++ V_809 )
V_10 -> V_5 . V_1285 [ V_3 - 1 ] [ V_809 ] . V_1290 = 1 ;
}
}
return 0 ;
V_398:
for ( V_3 = 0 ; V_3 < V_1283 ; ++ V_3 ) {
F_640 ( V_10 -> V_5 . V_1284 [ V_3 ] ) ;
V_10 -> V_5 . V_1284 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_640 ( V_10 -> V_5 . V_1285 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1285 [ V_3 - 1 ] = NULL ;
}
return - V_397 ;
}
void F_646 ( struct V_102 * V_102 )
{
F_647 ( V_102 ) ;
}
int F_648 ( struct V_102 * V_102 ,
struct V_755 * V_756 ,
struct V_1275 * V_1276 ,
enum V_1292 V_1293 )
{
if ( ( V_756 -> V_1236 >= V_573 ) && ( V_1293 == V_1294 ) ) {
unsigned long V_1291 ;
V_1291 = F_649 ( NULL , 0 , V_756 -> V_1286 * V_108 ,
V_1295 | V_1296 ,
V_1297 | V_1298 , 0 ) ;
if ( F_185 ( ( void * ) V_1291 ) )
return F_186 ( ( void * ) V_1291 ) ;
V_756 -> V_1291 = V_1291 ;
}
return 0 ;
}
void F_650 ( struct V_102 * V_102 ,
struct V_1275 * V_1276 ,
const struct V_755 * V_864 ,
enum V_1292 V_1293 )
{
int V_1299 = 0 ;
if ( ( V_1276 -> V_10 >= V_573 ) && ( V_1293 == V_1300 ) ) {
int V_109 ;
V_109 = F_651 ( V_864 -> V_1291 ,
V_864 -> V_1286 * V_108 ) ;
if ( V_109 < 0 )
F_10 ( V_871
L_32
L_33 ) ;
}
if ( ! V_102 -> V_5 . V_728 )
V_1299 = F_652 ( V_102 ) ;
if ( V_1299 )
F_292 ( V_102 , V_1299 ) ;
if ( ( V_1293 != V_1300 ) && ( V_1276 -> V_291 & V_1301 ) )
F_653 ( V_102 , V_1276 -> V_10 ) ;
}
void F_654 ( struct V_102 * V_102 )
{
F_655 ( V_102 ) ;
}
void F_656 ( struct V_102 * V_102 ,
struct V_755 * V_10 )
{
F_655 ( V_102 ) ;
}
int F_657 ( struct V_1 * V_2 )
{
if ( F_427 ( V_2 ) && V_73 -> V_1085 )
V_73 -> V_1085 ( V_2 , false ) ;
return ( V_2 -> V_5 . V_1036 == V_1129 &&
! V_2 -> V_5 . V_6 . V_1105 )
|| ! F_658 ( & V_2 -> V_1302 . V_1303 )
|| F_659 ( V_2 )
|| V_2 -> V_5 . V_1131 . V_1132
|| F_134 ( & V_2 -> V_5 . V_85 ) ||
( F_508 ( V_2 ) &&
F_507 ( V_2 ) ) ;
}
int F_660 ( struct V_1 * V_2 )
{
return F_661 ( V_2 ) == V_1115 ;
}
int F_508 ( struct V_1 * V_2 )
{
return V_73 -> V_1087 ( V_2 ) ;
}
unsigned long F_445 ( struct V_1 * V_2 )
{
if ( F_498 ( V_2 ) )
return F_426 ( V_2 ) ;
return ( T_1 ) ( F_381 ( V_2 , V_1171 ) +
F_426 ( V_2 ) ) ;
}
bool F_662 ( struct V_1 * V_2 , unsigned long V_1304 )
{
return F_445 ( V_2 ) == V_1304 ;
}
unsigned long F_425 ( struct V_1 * V_2 )
{
unsigned long V_957 ;
V_957 = V_73 -> V_987 ( V_2 ) ;
if ( V_2 -> V_175 & V_960 )
V_957 &= ~ V_959 ;
return V_957 ;
}
static void F_452 ( struct V_1 * V_2 , unsigned long V_957 )
{
if ( V_2 -> V_175 & V_960 &&
F_662 ( V_2 , V_2 -> V_5 . V_964 ) )
V_957 |= V_959 ;
V_73 -> V_1305 ( V_2 , V_957 ) ;
}
void F_432 ( struct V_1 * V_2 , unsigned long V_957 )
{
F_452 ( V_2 , V_957 ) ;
F_31 ( V_67 , V_2 ) ;
}
void F_663 ( struct V_1 * V_2 , struct V_1306 * V_343 )
{
int V_120 ;
if ( ( V_2 -> V_5 . V_84 . V_950 != V_343 -> V_5 . V_950 ) ||
V_343 -> V_1307 )
return;
V_120 = F_536 ( V_2 ) ;
if ( F_151 ( V_120 ) )
return;
if ( ! V_2 -> V_5 . V_84 . V_950 &&
V_343 -> V_5 . V_105 != V_2 -> V_5 . V_84 . V_1308 ( V_2 ) )
return;
V_2 -> V_5 . V_84 . V_1309 ( V_2 , V_343 -> V_824 , 0 , true ) ;
}
static inline T_1 F_664 ( T_5 V_103 )
{
return F_665 ( V_103 & 0xffffffff , F_666 ( V_4 ) ) ;
}
static inline T_1 F_667 ( T_1 V_1310 )
{
return ( V_1310 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_668 ( struct V_1 * V_2 , T_5 V_103 )
{
T_1 V_1310 = F_664 ( V_103 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1310 ] != ~ 0 )
V_1310 = F_667 ( V_1310 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1310 ] = V_103 ;
}
static T_1 F_669 ( struct V_1 * V_2 , T_5 V_103 )
{
int V_3 ;
T_1 V_1310 = F_664 ( V_103 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1310 ] != V_103 &&
V_2 -> V_5 . V_6 . V_7 [ V_1310 ] != ~ 0 ) ; V_3 ++ )
V_1310 = F_667 ( V_1310 ) ;
return V_1310 ;
}
bool F_670 ( struct V_1 * V_2 , T_5 V_103 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_669 ( V_2 , V_103 ) ] == V_103 ;
}
static void F_671 ( struct V_1 * V_2 , T_5 V_103 )
{
T_1 V_3 , V_809 , V_1311 ;
V_3 = V_809 = F_669 ( V_2 , V_103 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_809 = F_667 ( V_809 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_809 ] == ~ 0 )
return;
V_1311 = F_664 ( V_2 -> V_5 . V_6 . V_7 [ V_809 ] ) ;
} while ( ( V_3 <= V_809 ) ? ( V_3 < V_1311 && V_1311 <= V_809 ) : ( V_3 < V_1311 || V_1311 <= V_809 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_809 ] ;
V_3 = V_809 ;
}
}
static int F_672 ( struct V_1 * V_2 , T_1 V_188 )
{
return F_169 ( V_2 -> V_102 , & V_2 -> V_5 . V_6 . V_38 , & V_188 ,
sizeof( V_188 ) ) ;
}
void F_673 ( struct V_1 * V_2 ,
struct V_1306 * V_343 )
{
struct V_75 V_76 ;
F_674 ( V_343 -> V_5 . V_1312 , V_343 -> V_824 ) ;
F_668 ( V_2 , V_343 -> V_5 . V_103 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_427 & V_428 ) ||
( V_2 -> V_5 . V_6 . V_429 &&
V_73 -> V_88 ( V_2 ) == 0 ) )
F_31 ( V_1104 , V_2 ) ;
else if ( ! F_672 ( V_2 , V_1313 ) ) {
V_76 . V_41 = V_42 ;
V_76 . V_923 = true ;
V_76 . V_62 = 0 ;
V_76 . V_81 = false ;
V_76 . V_80 = V_343 -> V_5 . V_1312 ;
F_37 ( V_2 , & V_76 ) ;
}
}
void F_675 ( struct V_1 * V_2 ,
struct V_1306 * V_343 )
{
struct V_75 V_76 ;
F_676 ( V_343 -> V_5 . V_1312 , V_343 -> V_824 ) ;
if ( V_343 -> V_1307 )
V_343 -> V_5 . V_1312 = ~ 0 ;
else
F_671 ( V_2 , V_343 -> V_5 . V_103 ) ;
if ( ( V_2 -> V_5 . V_6 . V_427 & V_428 ) &&
! F_672 ( V_2 , V_1314 ) ) {
V_76 . V_41 = V_42 ;
V_76 . V_923 = true ;
V_76 . V_62 = 0 ;
V_76 . V_81 = false ;
V_76 . V_80 = V_343 -> V_5 . V_1312 ;
F_37 ( V_2 , & V_76 ) ;
}
V_2 -> V_5 . V_6 . V_1105 = false ;
V_2 -> V_5 . V_1036 = V_1129 ;
}
bool F_677 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_427 & V_428 ) )
return true ;
else
return ! F_510 ( V_2 ) &&
V_73 -> V_1087 ( V_2 ) ;
}
void F_678 ( struct V_102 * V_102 )
{
F_42 ( & V_102 -> V_5 . V_1269 ) ;
}
void F_679 ( struct V_102 * V_102 )
{
F_680 ( & V_102 -> V_5 . V_1269 ) ;
}
bool F_244 ( struct V_102 * V_102 )
{
return F_134 ( & V_102 -> V_5 . V_1269 ) ;
}
