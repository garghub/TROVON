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
return F_50 ( V_2 , V_97 , V_38 , V_94 , V_95 ) ;
}
static int F_51 ( struct V_1 * V_2 , T_5 V_102 ,
void * V_38 , int V_94 , int V_95 , T_1 V_96 )
{
return F_47 ( V_2 , V_2 -> V_5 . V_103 , V_102 ,
V_38 , V_94 , V_95 , V_96 ) ;
}
int F_52 ( struct V_1 * V_2 , struct V_92 * V_84 , unsigned long V_104 )
{
T_5 V_105 = V_104 >> V_106 ;
unsigned V_94 = ( ( V_104 & ( V_107 - 1 ) ) >> 5 ) << 2 ;
int V_3 ;
int V_108 ;
T_2 V_109 [ F_53 ( V_84 -> V_110 ) ] ;
V_108 = F_47 ( V_2 , V_84 , V_105 , V_109 ,
V_94 * sizeof( T_2 ) , sizeof( V_109 ) ,
V_111 | V_112 ) ;
if ( V_108 < 0 ) {
V_108 = 0 ;
goto V_113;
}
for ( V_3 = 0 ; V_3 < F_53 ( V_109 ) ; ++ V_3 ) {
if ( F_54 ( V_109 [ V_3 ] ) &&
( V_109 [ V_3 ] & V_2 -> V_5 . V_84 . V_114 [ 0 ] [ 2 ] ) ) {
V_108 = 0 ;
goto V_113;
}
}
V_108 = 1 ;
memcpy ( V_84 -> V_110 , V_109 , sizeof( V_84 -> V_110 ) ) ;
F_55 ( V_115 ,
( unsigned long * ) & V_2 -> V_5 . V_116 ) ;
F_55 ( V_115 ,
( unsigned long * ) & V_2 -> V_5 . V_117 ) ;
V_113:
return V_108 ;
}
static bool F_56 ( struct V_1 * V_2 )
{
T_2 V_109 [ F_53 ( V_2 -> V_5 . V_103 -> V_110 ) ] ;
bool V_118 = true ;
int V_94 ;
T_5 V_102 ;
int V_119 ;
if ( F_57 ( V_2 ) || ! F_58 ( V_2 ) )
return false ;
if ( ! F_59 ( V_115 ,
( unsigned long * ) & V_2 -> V_5 . V_116 ) )
return true ;
V_102 = ( F_60 ( V_2 ) & ~ 31u ) >> V_106 ;
V_94 = ( F_60 ( V_2 ) & ~ 31u ) & ( V_107 - 1 ) ;
V_119 = F_51 ( V_2 , V_102 , V_109 , V_94 , sizeof( V_109 ) ,
V_111 | V_112 ) ;
if ( V_119 < 0 )
goto V_113;
V_118 = memcmp ( V_109 , V_2 -> V_5 . V_103 -> V_110 , sizeof( V_109 ) ) != 0 ;
V_113:
return V_118 ;
}
int F_61 ( struct V_1 * V_2 , unsigned long V_120 )
{
unsigned long V_121 = F_62 ( V_2 ) ;
unsigned long V_122 = V_123 | V_124 ;
V_120 |= V_125 ;
#ifdef F_63
if ( V_120 & 0xffffffff00000000UL )
return 1 ;
#endif
V_120 &= ~ V_126 ;
if ( ( V_120 & V_127 ) && ! ( V_120 & V_128 ) )
return 1 ;
if ( ( V_120 & V_123 ) && ! ( V_120 & V_129 ) )
return 1 ;
if ( ! F_64 ( V_2 ) && ( V_120 & V_123 ) ) {
#ifdef F_63
if ( ( V_2 -> V_5 . V_130 & V_131 ) ) {
int V_132 , V_133 ;
if ( ! F_58 ( V_2 ) )
return 1 ;
V_73 -> V_134 ( V_2 , & V_132 , & V_133 ) ;
if ( V_133 )
return 1 ;
} else
#endif
if ( F_58 ( V_2 ) && ! F_52 ( V_2 , V_2 -> V_5 . V_103 ,
F_60 ( V_2 ) ) )
return 1 ;
}
if ( ! ( V_120 & V_123 ) && F_46 ( V_2 , V_135 ) )
return 1 ;
V_73 -> V_136 ( V_2 , V_120 ) ;
if ( ( V_120 ^ V_121 ) & V_123 ) {
F_65 ( V_2 ) ;
F_1 ( V_2 ) ;
}
if ( ( V_120 ^ V_121 ) & V_122 )
F_66 ( V_2 ) ;
if ( ( V_120 ^ V_121 ) & V_128 )
F_67 ( V_2 -> V_137 , 0 , ~ 0ULL ) ;
return 0 ;
}
void F_68 ( struct V_1 * V_2 , unsigned long V_138 )
{
( void ) F_61 ( V_2 , F_69 ( V_2 , ~ 0x0eul ) | ( V_138 & 0x0f ) ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
if ( F_46 ( V_2 , V_139 ) &&
! V_2 -> V_140 ) {
F_71 ( V_141 , V_2 -> V_5 . V_142 ) ;
V_2 -> V_140 = 1 ;
}
}
static void F_72 ( struct V_1 * V_2 )
{
if ( V_2 -> V_140 ) {
if ( V_2 -> V_5 . V_142 != V_143 )
F_71 ( V_141 , V_143 ) ;
V_2 -> V_140 = 0 ;
}
}
static int F_73 ( struct V_1 * V_2 , T_1 V_144 , T_2 V_145 )
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
F_72 ( V_2 ) ;
V_2 -> V_5 . V_142 = V_142 ;
if ( ( V_142 ^ V_146 ) & V_155 )
F_74 ( V_2 ) ;
return 0 ;
}
int F_75 ( struct V_1 * V_2 , T_1 V_144 , T_2 V_145 )
{
if ( V_73 -> V_88 ( V_2 ) != 0 ||
F_73 ( V_2 , V_144 , V_145 ) ) {
F_36 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_76 ( struct V_1 * V_2 , unsigned long V_156 )
{
unsigned long V_157 = F_77 ( V_2 ) ;
unsigned long V_158 = V_159 | V_160 | V_161 |
V_162 | V_163 ;
if ( V_156 & V_164 )
return 1 ;
if ( ! F_78 ( V_2 ) && ( V_156 & V_139 ) )
return 1 ;
if ( ! F_79 ( V_2 ) && ( V_156 & V_162 ) )
return 1 ;
if ( ! F_80 ( V_2 ) && ( V_156 & V_163 ) )
return 1 ;
if ( ! F_81 ( V_2 ) && ( V_156 & V_165 ) )
return 1 ;
if ( F_57 ( V_2 ) ) {
if ( ! ( V_156 & V_161 ) )
return 1 ;
} else if ( F_64 ( V_2 ) && ( V_156 & V_161 )
&& ( ( V_156 ^ V_157 ) & V_158 )
&& ! F_52 ( V_2 , V_2 -> V_5 . V_103 ,
F_60 ( V_2 ) ) )
return 1 ;
if ( ( V_156 & V_135 ) && ! ( V_157 & V_135 ) ) {
if ( ! F_82 ( V_2 ) )
return 1 ;
if ( ( F_60 ( V_2 ) & V_166 ) || ! F_57 ( V_2 ) )
return 1 ;
}
if ( V_73 -> V_167 ( V_2 , V_156 ) )
return 1 ;
if ( ( ( V_156 ^ V_157 ) & V_158 ) ||
( ! ( V_156 & V_135 ) && ( V_157 & V_135 ) ) )
F_66 ( V_2 ) ;
if ( ( V_156 ^ V_157 ) & V_139 )
F_74 ( V_2 ) ;
return 0 ;
}
int F_83 ( struct V_1 * V_2 , unsigned long V_104 )
{
#ifdef F_63
V_104 &= ~ V_168 ;
#endif
if ( V_104 == F_60 ( V_2 ) && ! F_56 ( V_2 ) ) {
F_84 ( V_2 ) ;
F_31 ( V_169 , V_2 ) ;
return 0 ;
}
if ( F_57 ( V_2 ) ) {
if ( V_104 & V_170 )
return 1 ;
} else if ( F_58 ( V_2 ) && F_64 ( V_2 ) &&
! F_52 ( V_2 , V_2 -> V_5 . V_103 , V_104 ) )
return 1 ;
V_2 -> V_5 . V_104 = V_104 ;
F_55 ( V_171 , ( V_172 * ) & V_2 -> V_5 . V_116 ) ;
F_85 ( V_2 ) ;
return 0 ;
}
int F_86 ( struct V_1 * V_2 , unsigned long V_173 )
{
if ( V_173 & V_174 )
return 1 ;
if ( F_87 ( V_2 -> V_137 ) )
F_88 ( V_2 , V_173 ) ;
else
V_2 -> V_5 . V_173 = V_173 ;
return 0 ;
}
unsigned long F_89 ( struct V_1 * V_2 )
{
if ( F_87 ( V_2 -> V_137 ) )
return F_90 ( V_2 ) ;
else
return V_2 -> V_5 . V_173 ;
}
static void F_91 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! ( V_2 -> V_175 & V_176 ) ) {
for ( V_3 = 0 ; V_3 < V_177 ; V_3 ++ )
V_2 -> V_5 . V_178 [ V_3 ] = V_2 -> V_5 . V_179 [ V_3 ] ;
V_2 -> V_5 . V_180 |= V_181 ;
}
}
static void F_92 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_175 & V_176 ) )
V_73 -> V_182 ( V_2 , V_2 -> V_5 . V_183 ) ;
}
static void F_93 ( struct V_1 * V_2 )
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
static T_2 F_94 ( struct V_1 * V_2 )
{
T_2 V_189 = V_190 ;
if ( ! F_95 ( V_2 ) )
V_189 |= V_191 ;
return V_189 ;
}
static int F_96 ( struct V_1 * V_2 , int V_89 , unsigned long V_192 )
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
V_2 -> V_5 . V_183 = ( V_192 & V_193 ) | F_94 ( V_2 ) ;
F_92 ( V_2 ) ;
break;
case 5 :
default:
if ( V_192 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_184 = ( V_192 & V_194 ) | V_195 ;
F_93 ( V_2 ) ;
break;
}
return 0 ;
}
int F_97 ( struct V_1 * V_2 , int V_89 , unsigned long V_192 )
{
if ( F_96 ( V_2 , V_89 , V_192 ) ) {
F_36 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_98 ( struct V_1 * V_2 , int V_89 , unsigned long * V_192 )
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
bool F_99 ( struct V_1 * V_2 )
{
T_1 V_197 = F_100 ( V_2 , V_198 ) ;
T_2 V_38 ;
int V_29 ;
V_29 = F_101 ( V_2 , V_197 , & V_38 ) ;
if ( V_29 )
return V_29 ;
F_102 ( V_2 , V_199 , ( T_1 ) V_38 ) ;
F_102 ( V_2 , V_200 , V_38 >> 32 ) ;
return V_29 ;
}
bool F_103 ( struct V_1 * V_2 , T_2 V_130 )
{
if ( V_130 & V_201 )
return false ;
if ( V_130 & V_202 ) {
struct V_203 * V_204 ;
V_204 = F_104 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_204 || ! ( V_204 -> V_205 & F_105 ( V_206 ) ) )
return false ;
}
if ( V_130 & V_207 ) {
struct V_203 * V_204 ;
V_204 = F_104 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_204 || ! ( V_204 -> V_197 & F_105 ( V_208 ) ) )
return false ;
}
return true ;
}
static int F_106 ( struct V_1 * V_2 , T_2 V_130 )
{
T_2 V_209 = V_2 -> V_5 . V_130 ;
if ( ! F_103 ( V_2 , V_130 ) )
return 1 ;
if ( F_64 ( V_2 )
&& ( V_2 -> V_5 . V_130 & V_131 ) != ( V_130 & V_131 ) )
return 1 ;
V_130 &= ~ V_210 ;
V_130 |= V_2 -> V_5 . V_130 & V_210 ;
V_73 -> F_106 ( V_2 , V_130 ) ;
if ( ( V_130 ^ V_209 ) & V_211 )
F_66 ( V_2 ) ;
return 0 ;
}
void F_107 ( T_2 V_28 )
{
V_201 &= ~ V_28 ;
}
int F_108 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
switch ( V_21 -> V_144 ) {
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
if ( F_109 ( V_21 -> V_38 ) )
return 1 ;
break;
case V_217 :
case V_218 :
V_21 -> V_38 = F_110 ( V_21 -> V_38 ) ;
}
return V_73 -> V_219 ( V_2 , V_21 ) ;
}
static int F_111 ( struct V_1 * V_2 , unsigned V_144 , T_2 * V_38 )
{
struct V_32 V_21 ;
int V_119 ;
V_21 . V_144 = V_144 ;
V_21 . V_40 = true ;
V_119 = F_112 ( V_2 , & V_21 ) ;
if ( V_119 )
return V_119 ;
* V_38 = V_21 . V_38 ;
return 0 ;
}
static int F_113 ( struct V_1 * V_2 , unsigned V_144 , T_2 * V_38 )
{
struct V_32 V_21 ;
V_21 . V_38 = * V_38 ;
V_21 . V_144 = V_144 ;
V_21 . V_40 = true ;
return F_108 ( V_2 , & V_21 ) ;
}
static void F_114 ( struct V_220 * V_221 )
{
struct V_222 * V_223 = & V_222 ;
T_2 V_224 ;
V_224 = F_115 ( F_116 ( V_221 -> V_225 . V_226 , V_221 -> V_227 ) ) ;
F_117 ( & V_223 -> V_228 ) ;
V_223 -> clock . V_229 = V_221 -> V_225 . clock -> V_230 . V_229 ;
V_223 -> clock . V_231 = V_221 -> V_225 . V_231 ;
V_223 -> clock . V_28 = V_221 -> V_225 . V_28 ;
V_223 -> clock . V_232 = V_221 -> V_225 . V_232 ;
V_223 -> clock . V_233 = V_221 -> V_225 . V_233 ;
V_223 -> V_224 = V_224 ;
V_223 -> V_234 = V_221 -> V_225 . V_235 ;
F_118 ( & V_223 -> V_228 ) ;
}
void F_119 ( struct V_1 * V_2 )
{
F_31 ( V_236 , V_2 ) ;
}
static void F_120 ( struct V_137 * V_137 , T_6 V_237 )
{
int V_238 ;
int V_119 ;
struct V_239 V_240 ;
struct V_241 V_242 ;
if ( ! V_237 )
return;
V_119 = F_121 ( V_137 , V_237 , & V_238 , sizeof( V_238 ) ) ;
if ( V_119 )
return;
if ( V_238 & 1 )
++ V_238 ;
++ V_238 ;
F_122 ( V_137 , V_237 , & V_238 , sizeof( V_238 ) ) ;
F_123 ( & V_242 ) ;
if ( V_137 -> V_5 . V_243 ) {
struct V_241 V_244 = F_124 ( V_137 -> V_5 . V_243 ) ;
V_242 = F_125 ( V_242 , V_244 ) ;
}
V_240 . V_245 = V_242 . V_246 ;
V_240 . V_247 = V_242 . V_248 ;
V_240 . V_238 = V_238 ;
F_122 ( V_137 , V_237 , & V_240 , sizeof( V_240 ) ) ;
V_238 ++ ;
F_122 ( V_137 , V_237 , & V_238 , sizeof( V_238 ) ) ;
}
static T_7 F_126 ( T_7 V_249 , T_7 V_250 )
{
T_7 V_251 , V_252 ;
__asm__ ( "divl %4"
: "=a" (quotient), "=d" (remainder)
: "0" (0), "1" (dividend), "r" (divisor) );
return V_251 ;
}
static void F_127 ( T_7 V_253 , T_7 V_254 ,
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
* V_256 = F_126 ( V_257 , V_259 ) ;
F_128 ( L_2 ,
V_260 , V_254 , V_253 , V_233 , * V_256 ) ;
}
static inline T_2 F_129 ( void )
{
return F_130 () ;
}
static inline T_2 F_131 ( struct V_1 * V_2 , T_2 V_247 )
{
return F_132 ( V_247 , V_2 -> V_5 . V_261 ,
V_2 -> V_5 . V_262 ) ;
}
static T_1 F_133 ( T_1 V_263 , T_11 V_264 )
{
T_2 V_265 = ( T_2 ) V_263 * ( 1000000 + V_264 ) ;
F_134 ( V_265 , 1000000 ) ;
return V_265 ;
}
static void F_135 ( struct V_1 * V_2 , T_1 V_266 )
{
T_1 V_267 , V_268 ;
int V_269 = 0 ;
if ( V_266 == 0 )
return;
F_127 ( V_266 , V_270 / 1000 ,
& V_2 -> V_5 . V_262 ,
& V_2 -> V_5 . V_261 ) ;
V_2 -> V_5 . V_271 = V_266 ;
V_267 = F_133 ( V_272 , - V_273 ) ;
V_268 = F_133 ( V_272 , V_273 ) ;
if ( V_266 < V_267 || V_266 > V_268 ) {
F_128 ( L_3 , V_266 , V_267 , V_268 ) ;
V_269 = 1 ;
}
V_73 -> V_274 ( V_2 , V_266 , V_269 ) ;
}
static T_2 F_136 ( struct V_1 * V_2 , T_12 V_275 )
{
T_2 V_276 = F_132 ( V_275 - V_2 -> V_5 . V_277 ,
V_2 -> V_5 . V_261 ,
V_2 -> V_5 . V_262 ) ;
V_276 += V_2 -> V_5 . V_278 ;
return V_276 ;
}
static void F_137 ( struct V_1 * V_2 )
{
#ifdef F_63
bool V_279 ;
struct V_280 * V_281 = & V_2 -> V_137 -> V_5 ;
struct V_222 * V_282 = & V_222 ;
V_279 = ( V_281 -> V_283 + 1 ==
F_138 ( & V_2 -> V_137 -> V_284 ) ) ;
if ( V_281 -> V_285 ||
( V_282 -> clock . V_229 == V_286 && V_279 ) )
F_31 ( V_287 , V_2 ) ;
F_139 ( V_2 -> V_288 , V_281 -> V_283 ,
F_138 ( & V_2 -> V_137 -> V_284 ) ,
V_281 -> V_285 , V_282 -> clock . V_229 ) ;
#endif
}
static void F_140 ( struct V_1 * V_2 , T_12 V_94 )
{
T_2 V_289 = V_73 -> V_290 ( V_2 ) ;
V_2 -> V_5 . V_291 += V_94 - V_289 ;
}
void F_141 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
struct V_137 * V_137 = V_2 -> V_137 ;
T_2 V_94 , V_292 , V_293 ;
unsigned long V_294 ;
T_12 V_295 ;
bool V_296 ;
bool V_297 ;
T_2 V_38 = V_21 -> V_38 ;
F_142 ( & V_137 -> V_5 . V_298 , V_294 ) ;
V_94 = V_73 -> V_299 ( V_2 , V_38 ) ;
V_292 = F_129 () ;
V_293 = V_292 - V_137 -> V_5 . V_300 ;
if ( V_2 -> V_5 . V_271 ) {
int V_301 = 0 ;
V_295 = V_38 - V_137 -> V_5 . V_302 ;
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
F_134 ( V_293 , 1000 ) ;
V_295 -= V_293 ;
if ( V_295 < 0 )
V_295 = - V_295 ;
if ( V_301 )
V_295 = V_303 ;
} else
V_295 = V_303 ;
if ( V_295 < V_303 &&
V_2 -> V_5 . V_271 == V_137 -> V_5 . V_304 ) {
if ( ! F_143 () ) {
V_94 = V_137 -> V_5 . V_305 ;
F_128 ( L_4 , V_38 ) ;
} else {
T_2 V_306 = F_131 ( V_2 , V_293 ) ;
V_38 += V_306 ;
V_94 = V_73 -> V_299 ( V_2 , V_38 ) ;
F_128 ( L_5 , V_306 ) ;
}
V_296 = true ;
V_297 = ( V_2 -> V_5 . V_307 == V_137 -> V_5 . V_308 ) ;
} else {
V_137 -> V_5 . V_308 ++ ;
V_137 -> V_5 . V_309 = V_292 ;
V_137 -> V_5 . V_310 = V_38 ;
V_137 -> V_5 . V_305 = V_94 ;
V_296 = false ;
F_128 ( L_6 ,
V_137 -> V_5 . V_308 , V_38 ) ;
}
V_137 -> V_5 . V_300 = V_292 ;
V_137 -> V_5 . V_302 = V_38 ;
V_137 -> V_5 . V_304 = V_2 -> V_5 . V_271 ;
V_2 -> V_5 . V_311 = V_38 ;
V_2 -> V_5 . V_307 = V_137 -> V_5 . V_308 ;
V_2 -> V_5 . V_277 = V_137 -> V_5 . V_309 ;
V_2 -> V_5 . V_278 = V_137 -> V_5 . V_310 ;
if ( F_144 ( V_2 ) && ! V_21 -> V_40 )
F_140 ( V_2 , V_94 ) ;
V_73 -> V_312 ( V_2 , V_94 ) ;
F_145 ( & V_137 -> V_5 . V_298 , V_294 ) ;
F_146 ( & V_137 -> V_5 . V_313 ) ;
if ( ! V_296 ) {
V_137 -> V_5 . V_283 = 0 ;
} else if ( ! V_297 ) {
V_137 -> V_5 . V_283 ++ ;
}
F_137 ( V_2 ) ;
F_147 ( & V_137 -> V_5 . V_313 ) ;
}
static T_13 F_148 ( void )
{
T_13 V_108 ;
T_2 V_314 ;
F_149 () ;
V_108 = ( T_13 ) F_150 () ;
V_314 = V_222 . clock . V_231 ;
if ( F_151 ( V_108 >= V_314 ) )
return V_108 ;
asm volatile ("");
return V_314 ;
}
static inline T_2 F_152 ( T_13 * V_315 )
{
long V_265 ;
struct V_222 * V_282 = & V_222 ;
* V_315 = F_148 () ;
V_265 = ( * V_315 - V_282 -> clock . V_231 ) & V_282 -> clock . V_28 ;
return V_265 * V_282 -> clock . V_232 ;
}
static int F_153 ( T_12 * V_316 , T_13 * V_315 )
{
struct V_222 * V_282 = & V_222 ;
unsigned long V_228 ;
int V_317 ;
T_2 V_292 ;
do {
V_228 = F_154 ( & V_282 -> V_228 ) ;
V_317 = V_282 -> clock . V_229 ;
V_292 = V_282 -> V_234 ;
V_292 += F_152 ( V_315 ) ;
V_292 >>= V_282 -> clock . V_233 ;
V_292 += V_282 -> V_224 ;
} while ( F_155 ( F_156 ( & V_282 -> V_228 , V_228 ) ) );
* V_316 = V_292 ;
return V_317 ;
}
static bool F_157 ( T_12 * V_275 , T_13 * V_315 )
{
if ( V_222 . clock . V_229 != V_286 )
return false ;
return F_153 ( V_275 , V_315 ) == V_286 ;
}
static void F_158 ( struct V_137 * V_137 )
{
#ifdef F_63
struct V_280 * V_281 = & V_137 -> V_5 ;
int V_229 ;
bool V_318 , V_279 ;
V_279 = ( V_281 -> V_283 + 1 ==
F_138 ( & V_137 -> V_284 ) ) ;
V_318 = F_157 (
& V_281 -> V_319 ,
& V_281 -> V_320 ) ;
V_281 -> V_285 = V_318 && V_279
&& ! V_321
&& ! V_281 -> V_322 ;
if ( V_281 -> V_285 )
F_159 ( & V_323 , 1 ) ;
V_229 = V_222 . clock . V_229 ;
F_160 ( V_281 -> V_285 , V_229 ,
V_279 ) ;
#endif
}
static void F_161 ( struct V_137 * V_137 )
{
#ifdef F_63
int V_3 ;
struct V_1 * V_2 ;
struct V_280 * V_281 = & V_137 -> V_5 ;
F_146 ( & V_281 -> V_313 ) ;
F_162 ( V_137 ) ;
F_158 ( V_137 ) ;
F_163 (i, vcpu, kvm)
F_31 ( V_324 , V_2 ) ;
F_163 (i, vcpu, kvm)
F_164 ( V_325 , & V_2 -> V_326 ) ;
F_147 ( & V_281 -> V_313 ) ;
#endif
}
static int F_165 ( struct V_1 * V_265 )
{
unsigned long V_294 , V_266 ;
struct V_327 * V_2 = & V_265 -> V_5 ;
struct V_280 * V_281 = & V_265 -> V_137 -> V_5 ;
T_12 V_275 ;
T_2 V_328 , V_329 ;
struct V_330 V_331 ;
T_14 V_332 ;
bool V_285 ;
V_275 = 0 ;
V_329 = 0 ;
F_146 ( & V_281 -> V_313 ) ;
V_285 = V_281 -> V_285 ;
if ( V_285 ) {
V_329 = V_281 -> V_320 ;
V_275 = V_281 -> V_319 ;
}
F_147 ( & V_281 -> V_313 ) ;
F_166 ( V_294 ) ;
V_266 = F_167 ( V_333 ) ;
if ( F_155 ( V_266 == 0 ) ) {
F_168 ( V_294 ) ;
F_31 ( V_324 , V_265 ) ;
return 1 ;
}
if ( ! V_285 ) {
V_329 = F_169 () ;
V_275 = F_129 () ;
}
V_328 = V_73 -> V_334 ( V_265 , V_329 ) ;
if ( V_2 -> V_335 ) {
T_2 V_276 = F_136 ( V_265 , V_275 ) ;
if ( V_276 > V_328 ) {
F_170 ( V_265 , V_276 - V_328 ) ;
V_328 = V_276 ;
}
}
F_168 ( V_294 ) ;
if ( ! V_2 -> V_336 )
return 0 ;
if ( F_155 ( V_2 -> V_337 != V_266 ) ) {
F_127 ( V_270 / 1000 , V_266 ,
& V_2 -> V_338 . V_339 ,
& V_2 -> V_338 . V_340 ) ;
V_2 -> V_337 = V_266 ;
}
V_2 -> V_338 . V_328 = V_328 ;
V_2 -> V_338 . V_341 = V_275 + V_265 -> V_137 -> V_5 . V_243 ;
V_2 -> V_311 = V_328 ;
if ( F_155 ( F_171 ( V_265 -> V_137 , & V_2 -> V_342 ,
& V_331 , sizeof( V_331 ) ) ) )
return 0 ;
F_172 ( F_173 ( struct V_330 , V_238 ) != 0 ) ;
V_2 -> V_338 . V_238 = V_331 . V_238 + 1 ;
F_174 ( V_265 -> V_137 , & V_2 -> V_342 ,
& V_2 -> V_338 ,
sizeof( V_2 -> V_338 . V_238 ) ) ;
F_14 () ;
V_332 = ( V_331 . V_294 & V_343 ) ;
if ( V_2 -> V_344 ) {
V_332 |= V_343 ;
V_2 -> V_344 = false ;
}
V_332 |= V_345 ;
if ( V_285 )
V_332 |= V_346 ;
V_2 -> V_338 . V_294 = V_332 ;
F_175 ( V_265 -> V_288 , & V_2 -> V_338 ) ;
F_174 ( V_265 -> V_137 , & V_2 -> V_342 ,
& V_2 -> V_338 ,
sizeof( V_2 -> V_338 ) ) ;
F_14 () ;
V_2 -> V_338 . V_238 ++ ;
F_174 ( V_265 -> V_137 , & V_2 -> V_342 ,
& V_2 -> V_338 ,
sizeof( V_2 -> V_338 . V_238 ) ) ;
return 0 ;
}
static void F_176 ( struct V_347 * V_348 )
{
int V_3 ;
struct V_349 * V_350 = F_177 ( V_348 ) ;
struct V_280 * V_281 = F_4 ( V_350 , struct V_280 ,
V_351 ) ;
struct V_137 * V_137 = F_4 ( V_281 , struct V_137 , V_5 ) ;
struct V_1 * V_2 ;
F_163 (i, vcpu, kvm) {
F_31 ( V_324 , V_2 ) ;
F_178 ( V_2 ) ;
}
}
static void F_179 ( struct V_1 * V_265 )
{
struct V_137 * V_137 = V_265 -> V_137 ;
F_31 ( V_324 , V_265 ) ;
F_180 ( & V_137 -> V_5 . V_351 ,
V_352 ) ;
}
static void F_181 ( struct V_347 * V_348 )
{
struct V_349 * V_350 = F_177 ( V_348 ) ;
struct V_280 * V_281 = F_4 ( V_350 , struct V_280 ,
V_353 ) ;
struct V_137 * V_137 = F_4 ( V_281 , struct V_137 , V_5 ) ;
if ( ! V_354 )
return;
F_180 ( & V_137 -> V_5 . V_351 , 0 ) ;
F_180 ( & V_137 -> V_5 . V_353 ,
V_355 ) ;
}
static int F_182 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
T_2 V_356 = V_2 -> V_5 . V_356 ;
unsigned V_357 = V_356 & 0xff ;
switch ( V_21 ) {
case V_358 :
V_2 -> V_5 . V_359 = V_38 ;
break;
case V_360 :
if ( ! ( V_356 & V_361 ) )
return 1 ;
if ( V_38 != 0 && V_38 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_362 = V_38 ;
break;
default:
if ( V_21 >= V_363 &&
V_21 < F_183 ( V_357 ) ) {
T_1 V_94 = V_21 - V_363 ;
if ( ( V_94 & 0x3 ) == 0 &&
V_38 != 0 && ( V_38 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_364 [ V_94 ] = V_38 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_184 ( struct V_1 * V_2 , T_2 V_38 )
{
struct V_137 * V_137 = V_2 -> V_137 ;
int V_365 = F_57 ( V_2 ) ;
T_14 * V_366 = V_365 ? ( T_14 * ) ( long ) V_137 -> V_5 . F_184 . V_367
: ( T_14 * ) ( long ) V_137 -> V_5 . F_184 . V_368 ;
T_14 V_369 = V_365 ? V_137 -> V_5 . F_184 . V_370
: V_137 -> V_5 . F_184 . V_371 ;
T_1 V_372 = V_38 & ~ V_373 ;
T_2 V_374 = V_38 & V_373 ;
T_14 * V_375 ;
int V_119 ;
V_119 = - V_376 ;
if ( V_372 >= V_369 )
goto V_113;
V_119 = - V_377 ;
V_375 = F_185 ( V_366 + ( V_372 * V_107 ) , V_107 ) ;
if ( F_186 ( V_375 ) ) {
V_119 = F_187 ( V_375 ) ;
goto V_113;
}
if ( F_188 ( V_2 , V_374 , V_375 , V_107 ) )
goto V_378;
V_119 = 0 ;
V_378:
F_189 ( V_375 ) ;
V_113:
return V_119 ;
}
static bool F_190 ( struct V_137 * V_137 )
{
return V_137 -> V_5 . V_379 & V_380 ;
}
static bool F_191 ( T_1 V_21 )
{
bool V_119 = false ;
switch ( V_21 ) {
case V_381 :
case V_382 :
case V_383 :
case V_384 :
V_119 = true ;
break;
}
return V_119 ;
}
static int F_192 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
struct V_137 * V_137 = V_2 -> V_137 ;
switch ( V_21 ) {
case V_381 :
V_137 -> V_5 . V_385 = V_38 ;
if ( ! V_137 -> V_5 . V_385 )
V_137 -> V_5 . V_379 &= ~ V_380 ;
break;
case V_382 : {
T_2 V_102 ;
unsigned long V_386 ;
T_14 V_387 [ 4 ] ;
if ( ! V_137 -> V_5 . V_385 )
break;
if ( ! ( V_38 & V_380 ) ) {
V_137 -> V_5 . V_379 = V_38 ;
break;
}
V_102 = V_38 >> V_388 ;
V_386 = F_193 ( V_137 , V_102 ) ;
if ( F_194 ( V_386 ) )
return 1 ;
V_73 -> V_389 ( V_2 , V_387 ) ;
( ( unsigned char * ) V_387 ) [ 3 ] = 0xc3 ;
if ( F_195 ( ( void V_390 * ) V_386 , V_387 , 4 ) )
return 1 ;
V_137 -> V_5 . V_379 = V_38 ;
F_196 ( V_137 , V_102 ) ;
break;
}
case V_383 : {
T_2 V_102 ;
T_15 V_391 ;
memset ( & V_391 , 0 , sizeof( V_391 ) ) ;
V_137 -> V_5 . V_392 = V_38 ;
if ( ! ( V_38 & V_393 ) )
break;
V_102 = V_38 >> V_394 ;
if ( F_122 ( V_137 , V_102 << V_394 ,
& V_391 , sizeof( V_391 ) ) )
return 1 ;
F_196 ( V_137 , V_102 ) ;
break;
}
default:
F_197 ( V_2 , L_7
L_8 , V_21 , V_38 ) ;
return 1 ;
}
return 0 ;
}
static int F_198 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
switch ( V_21 ) {
case V_395 : {
T_2 V_102 ;
unsigned long V_386 ;
if ( ! ( V_38 & V_396 ) ) {
V_2 -> V_5 . V_397 = V_38 ;
if ( F_199 ( V_2 , 0 ) )
return 1 ;
break;
}
V_102 = V_38 >> V_398 ;
V_386 = F_200 ( V_2 , V_102 ) ;
if ( F_194 ( V_386 ) )
return 1 ;
if ( F_201 ( ( void V_390 * ) V_386 , V_107 ) )
return 1 ;
V_2 -> V_5 . V_397 = V_38 ;
F_202 ( V_2 , V_102 ) ;
if ( F_199 ( V_2 , F_48 ( V_102 ) | V_399 ) )
return 1 ;
break;
}
case V_400 :
return F_203 ( V_2 , V_401 , V_38 ) ;
case V_402 :
return F_203 ( V_2 , V_403 , V_38 ) ;
case V_404 :
return F_203 ( V_2 , V_405 , V_38 ) ;
default:
F_197 ( V_2 , L_7
L_8 , V_21 , V_38 ) ;
return 1 ;
}
return 0 ;
}
static int F_204 ( struct V_1 * V_2 , T_2 V_38 )
{
T_6 V_406 = V_38 & ~ 0x3f ;
if ( V_38 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_407 = V_38 ;
if ( ! ( V_38 & V_408 ) ) {
F_65 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_205 ( V_2 -> V_137 , & V_2 -> V_5 . V_6 . V_38 , V_406 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_409 = ! ( V_38 & V_410 ) ;
F_206 ( V_2 ) ;
return 0 ;
}
static void F_207 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_336 = false ;
}
static void F_208 ( struct V_1 * V_2 )
{
T_2 V_306 ;
if ( ! ( V_2 -> V_5 . V_411 . V_407 & V_399 ) )
return;
V_306 = V_412 -> V_413 . V_414 - V_2 -> V_5 . V_411 . V_415 ;
V_2 -> V_5 . V_411 . V_415 = V_412 -> V_413 . V_414 ;
V_2 -> V_5 . V_411 . V_416 = V_306 ;
}
static void F_209 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_411 . V_407 & V_399 ) )
return;
if ( F_155 ( F_171 ( V_2 -> V_137 , & V_2 -> V_5 . V_411 . V_417 ,
& V_2 -> V_5 . V_411 . V_418 , sizeof( struct V_419 ) ) ) )
return;
V_2 -> V_5 . V_411 . V_418 . V_418 += V_2 -> V_5 . V_411 . V_416 ;
V_2 -> V_5 . V_411 . V_418 . V_238 += 2 ;
V_2 -> V_5 . V_411 . V_416 = 0 ;
F_174 ( V_2 -> V_137 , & V_2 -> V_5 . V_411 . V_417 ,
& V_2 -> V_5 . V_411 . V_418 , sizeof( struct V_419 ) ) ;
}
int F_210 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
bool V_420 = false ;
T_1 V_21 = V_33 -> V_144 ;
T_2 V_38 = V_33 -> V_38 ;
switch ( V_21 ) {
case V_421 :
case V_422 :
case V_423 :
case V_424 :
case V_425 :
case V_426 :
break;
case V_427 :
return F_106 ( V_2 , V_38 ) ;
case V_428 :
V_38 &= ~ ( T_2 ) 0x40 ;
V_38 &= ~ ( T_2 ) 0x100 ;
V_38 &= ~ ( T_2 ) 0x8 ;
V_38 &= ~ ( T_2 ) 0x40000 ;
if ( V_38 != 0 ) {
F_197 ( V_2 , L_9 ,
V_38 ) ;
return 1 ;
}
break;
case V_429 :
if ( V_38 != 0 ) {
F_197 ( V_2 , L_10
L_11 , V_38 ) ;
return 1 ;
}
break;
case V_430 :
if ( ! V_38 ) {
break;
} else if ( V_38 & ~ ( V_431 | V_432 ) ) {
return 1 ;
}
F_197 ( V_2 , L_12 ,
V_260 , V_38 ) ;
break;
case 0x200 ... 0x2ff :
return F_211 ( V_2 , V_21 , V_38 ) ;
case V_433 :
return F_21 ( V_2 , V_33 ) ;
case V_434 ... V_434 + 0x3ff :
return F_212 ( V_2 , V_21 , V_38 ) ;
case V_435 :
F_213 ( V_2 , V_38 ) ;
break;
case V_436 :
if ( F_144 ( V_2 ) ) {
if ( ! V_33 -> V_40 ) {
T_12 V_437 = V_38 - V_2 -> V_5 . V_291 ;
F_170 ( V_2 , V_437 ) ;
}
V_2 -> V_5 . V_291 = V_38 ;
}
break;
case V_438 :
V_2 -> V_5 . V_439 = V_38 ;
break;
case V_440 :
if ( ! V_33 -> V_40 )
return 1 ;
V_2 -> V_5 . V_441 = V_38 ;
break;
case V_442 :
case V_443 :
V_2 -> V_137 -> V_5 . V_237 = V_38 ;
F_120 ( V_2 -> V_137 , V_38 ) ;
break;
case V_444 :
case V_445 : {
T_2 V_446 ;
struct V_280 * V_281 = & V_2 -> V_137 -> V_5 ;
F_207 ( V_2 ) ;
if ( V_2 -> V_288 == 0 && ! V_33 -> V_40 ) {
bool V_447 = ( V_21 == V_445 ) ;
if ( V_281 -> V_322 != V_447 )
F_214 ( V_287 ,
& V_2 -> V_326 ) ;
V_281 -> V_322 = V_447 ;
V_281 -> V_243 = - F_129 () ;
}
V_2 -> V_5 . time = V_38 ;
F_31 ( V_448 , V_2 ) ;
if ( ! ( V_38 & 1 ) )
break;
V_446 = V_38 & ~ ( V_373 | 1 ) ;
if ( F_205 ( V_2 -> V_137 ,
& V_2 -> V_5 . V_342 , V_38 & ~ 1ULL ,
sizeof( struct V_330 ) ) )
V_2 -> V_5 . V_336 = false ;
else
V_2 -> V_5 . V_336 = true ;
break;
}
case V_449 :
if ( F_204 ( V_2 , V_38 ) )
return 1 ;
break;
case V_450 :
if ( F_155 ( ! F_215 () ) )
return 1 ;
if ( V_38 & V_451 )
return 1 ;
if ( F_205 ( V_2 -> V_137 , & V_2 -> V_5 . V_411 . V_417 ,
V_38 & V_452 ,
sizeof( struct V_419 ) ) )
return 1 ;
V_2 -> V_5 . V_411 . V_407 = V_38 ;
if ( ! ( V_38 & V_399 ) )
break;
V_2 -> V_5 . V_411 . V_415 = V_412 -> V_413 . V_414 ;
F_216 () ;
F_208 ( V_2 ) ;
F_217 () ;
F_31 ( V_453 , V_2 ) ;
break;
case V_454 :
if ( F_199 ( V_2 , V_38 ) )
return 1 ;
break;
case V_360 :
case V_358 :
case V_363 ... F_183 ( V_455 ) - 1 :
return F_182 ( V_2 , V_21 , V_38 ) ;
case V_456 ... V_457 :
case V_458 ... V_459 :
V_420 = true ;
case V_460 ... V_461 :
case V_462 ... V_463 :
if ( F_218 ( V_2 , V_21 ) )
return F_219 ( V_2 , V_33 ) ;
if ( V_420 || V_38 != 0 )
F_197 ( V_2 , L_13
L_14 , V_21 , V_38 ) ;
break;
case V_464 :
break;
case V_381 ... V_465 :
if ( F_191 ( V_21 ) ) {
int V_119 ;
F_220 ( & V_2 -> V_137 -> V_466 ) ;
V_119 = F_192 ( V_2 , V_21 , V_38 ) ;
F_221 ( & V_2 -> V_137 -> V_466 ) ;
return V_119 ;
} else
return F_198 ( V_2 , V_21 , V_38 ) ;
break;
case V_467 :
F_197 ( V_2 , L_15 , V_21 , V_38 ) ;
break;
case V_468 :
if ( ! F_222 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_469 . V_470 = V_38 ;
break;
case V_471 :
if ( ! F_222 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_469 . V_472 = V_38 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_137 -> V_5 . F_184 . V_21 ) )
return F_184 ( V_2 , V_38 ) ;
if ( F_218 ( V_2 , V_21 ) )
return F_219 ( V_2 , V_33 ) ;
if ( ! V_473 ) {
F_197 ( V_2 , L_16 ,
V_21 , V_38 ) ;
return 1 ;
} else {
F_197 ( V_2 , L_15 ,
V_21 , V_38 ) ;
break;
}
}
return 0 ;
}
int F_112 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
return V_73 -> V_474 ( V_2 , V_21 ) ;
}
static int F_223 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_475 )
{
T_2 V_38 ;
T_2 V_356 = V_2 -> V_5 . V_356 ;
unsigned V_357 = V_356 & 0xff ;
switch ( V_21 ) {
case V_476 :
case V_477 :
V_38 = 0 ;
break;
case V_478 :
V_38 = V_2 -> V_5 . V_356 ;
break;
case V_360 :
if ( ! ( V_356 & V_361 ) )
return 1 ;
V_38 = V_2 -> V_5 . V_362 ;
break;
case V_358 :
V_38 = V_2 -> V_5 . V_359 ;
break;
default:
if ( V_21 >= V_363 &&
V_21 < F_183 ( V_357 ) ) {
T_1 V_94 = V_21 - V_363 ;
V_38 = V_2 -> V_5 . V_364 [ V_94 ] ;
break;
}
return 1 ;
}
* V_475 = V_38 ;
return 0 ;
}
static int F_224 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_475 )
{
T_2 V_38 = 0 ;
struct V_137 * V_137 = V_2 -> V_137 ;
switch ( V_21 ) {
case V_381 :
V_38 = V_137 -> V_5 . V_385 ;
break;
case V_382 :
V_38 = V_137 -> V_5 . V_379 ;
break;
case V_384 : {
V_38 =
F_225 ( F_129 () + V_137 -> V_5 . V_243 , 100 ) ;
break;
}
case V_383 :
V_38 = V_137 -> V_5 . V_392 ;
break;
default:
F_197 ( V_2 , L_17 , V_21 ) ;
return 1 ;
}
* V_475 = V_38 ;
return 0 ;
}
static int F_226 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_475 )
{
T_2 V_38 = 0 ;
switch ( V_21 ) {
case V_479 : {
int V_119 ;
struct V_1 * V_265 ;
F_163 (r, v, vcpu->kvm) {
if ( V_265 == V_2 ) {
V_38 = V_119 ;
break;
}
}
break;
}
case V_400 :
return F_227 ( V_2 , V_401 , V_475 ) ;
case V_402 :
return F_227 ( V_2 , V_403 , V_475 ) ;
case V_404 :
return F_227 ( V_2 , V_405 , V_475 ) ;
case V_395 :
V_38 = V_2 -> V_5 . V_397 ;
break;
default:
F_197 ( V_2 , L_17 , V_21 ) ;
return 1 ;
}
* V_475 = V_38 ;
return 0 ;
}
int F_228 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
switch ( V_33 -> V_144 ) {
case V_480 :
case V_481 :
case V_430 :
case V_482 :
case V_483 :
case V_484 :
case V_485 :
case V_486 :
case V_428 :
case V_424 :
case V_487 :
case V_421 :
case V_429 :
case V_426 :
V_33 -> V_38 = 0 ;
break;
case V_460 ... V_461 :
case V_456 ... V_457 :
case V_458 ... V_459 :
case V_462 ... V_463 :
if ( F_218 ( V_2 , V_33 -> V_144 ) )
return F_229 ( V_2 , V_33 -> V_144 , & V_33 -> V_38 ) ;
V_33 -> V_38 = 0 ;
break;
case V_422 :
V_33 -> V_38 = 0x100000000ULL ;
break;
case V_488 :
case 0x200 ... 0x2ff :
return F_230 ( V_2 , V_33 -> V_144 , & V_33 -> V_38 ) ;
case 0xcd :
V_33 -> V_38 = 3 ;
break;
case V_489 :
V_33 -> V_38 = 1 << 24 ;
break;
case V_433 :
V_33 -> V_38 = F_20 ( V_2 ) ;
break;
case V_434 ... V_434 + 0x3ff :
return F_231 ( V_2 , V_33 -> V_144 , & V_33 -> V_38 ) ;
break;
case V_435 :
V_33 -> V_38 = F_232 ( V_2 ) ;
break;
case V_436 :
V_33 -> V_38 = ( T_2 ) V_2 -> V_5 . V_291 ;
break;
case V_438 :
V_33 -> V_38 = V_2 -> V_5 . V_439 ;
break;
case V_440 :
if ( ! V_33 -> V_40 )
return 1 ;
V_33 -> V_38 = V_2 -> V_5 . V_441 ;
break;
case V_490 :
V_33 -> V_38 = 1000ULL ;
V_33 -> V_38 |= ( ( ( T_9 ) 4ULL ) << 40 ) ;
break;
case V_427 :
V_33 -> V_38 = V_2 -> V_5 . V_130 ;
break;
case V_443 :
case V_442 :
V_33 -> V_38 = V_2 -> V_137 -> V_5 . V_237 ;
break;
case V_445 :
case V_444 :
V_33 -> V_38 = V_2 -> V_5 . time ;
break;
case V_449 :
V_33 -> V_38 = V_2 -> V_5 . V_6 . V_407 ;
break;
case V_450 :
V_33 -> V_38 = V_2 -> V_5 . V_411 . V_407 ;
break;
case V_454 :
V_33 -> V_38 = V_2 -> V_5 . V_491 . V_407 ;
break;
case V_476 :
case V_477 :
case V_478 :
case V_360 :
case V_358 :
case V_363 ... F_183 ( V_455 ) - 1 :
return F_223 ( V_2 , V_33 -> V_144 , & V_33 -> V_38 ) ;
case V_464 :
V_33 -> V_38 = 0x20000000 ;
break;
case V_381 ... V_465 :
if ( F_191 ( V_33 -> V_144 ) ) {
int V_119 ;
F_220 ( & V_2 -> V_137 -> V_466 ) ;
V_119 = F_224 ( V_2 , V_33 -> V_144 , & V_33 -> V_38 ) ;
F_221 ( & V_2 -> V_137 -> V_466 ) ;
return V_119 ;
} else
return F_226 ( V_2 , V_33 -> V_144 , & V_33 -> V_38 ) ;
break;
case V_467 :
V_33 -> V_38 = 0xbe702111 ;
break;
case V_468 :
if ( ! F_222 ( V_2 ) )
return 1 ;
V_33 -> V_38 = V_2 -> V_5 . V_469 . V_470 ;
break;
case V_471 :
if ( ! F_222 ( V_2 ) )
return 1 ;
V_33 -> V_38 = V_2 -> V_5 . V_469 . V_472 ;
break;
default:
if ( F_218 ( V_2 , V_33 -> V_144 ) )
return F_229 ( V_2 , V_33 -> V_144 , & V_33 -> V_38 ) ;
if ( ! V_473 ) {
F_197 ( V_2 , L_18 , V_33 -> V_144 ) ;
return 1 ;
} else {
F_197 ( V_2 , L_19 , V_33 -> V_144 ) ;
V_33 -> V_38 = 0 ;
}
break;
}
return 0 ;
}
static int F_233 ( struct V_1 * V_2 , struct V_492 * V_19 ,
struct V_493 * V_494 ,
int (* F_234)( struct V_1 * V_2 ,
unsigned V_144 , T_2 * V_38 ) )
{
int V_3 , V_495 ;
V_495 = F_235 ( & V_2 -> V_137 -> V_496 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_497 ; ++ V_3 )
if ( F_234 ( V_2 , V_494 [ V_3 ] . V_144 , & V_494 [ V_3 ] . V_38 ) )
break;
F_236 ( & V_2 -> V_137 -> V_496 , V_495 ) ;
return V_3 ;
}
static int F_237 ( struct V_1 * V_2 , struct V_492 V_390 * V_498 ,
int (* F_234)( struct V_1 * V_2 ,
unsigned V_144 , T_2 * V_38 ) ,
int V_499 )
{
struct V_492 V_19 ;
struct V_493 * V_494 ;
int V_119 , V_500 ;
unsigned V_501 ;
V_119 = - V_101 ;
if ( F_238 ( & V_19 , V_498 , sizeof V_19 ) )
goto V_113;
V_119 = - V_376 ;
if ( V_19 . V_497 >= V_502 )
goto V_113;
V_501 = sizeof( struct V_493 ) * V_19 . V_497 ;
V_494 = F_185 ( V_498 -> V_494 , V_501 ) ;
if ( F_186 ( V_494 ) ) {
V_119 = F_187 ( V_494 ) ;
goto V_113;
}
V_119 = V_500 = F_233 ( V_2 , & V_19 , V_494 , F_234 ) ;
if ( V_119 < 0 )
goto V_378;
V_119 = - V_101 ;
if ( V_499 && F_239 ( V_498 -> V_494 , V_494 , V_501 ) )
goto V_378;
V_119 = V_500 ;
V_378:
F_189 ( V_494 ) ;
V_113:
return V_119 ;
}
int F_240 ( struct V_137 * V_137 , long V_503 )
{
int V_119 ;
switch ( V_503 ) {
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
case V_534 :
case V_535 :
case V_536 :
case V_537 :
case V_538 :
case V_539 :
case V_540 :
case V_541 :
#ifdef F_241
case V_542 :
case V_543 :
#endif
V_119 = 1 ;
break;
case V_544 :
V_119 = V_73 -> V_545 () ;
break;
case V_546 :
V_119 = V_547 ;
break;
case V_548 :
V_119 = ! V_73 -> V_549 () ;
break;
case V_550 :
V_119 = V_551 ;
break;
case V_552 :
V_119 = V_553 ;
break;
case V_554 :
V_119 = V_555 ;
break;
case V_556 :
V_119 = 0 ;
break;
#ifdef F_241
case V_557 :
V_119 = F_242 ( & V_558 ) ;
break;
#endif
case V_559 :
V_119 = V_455 ;
break;
case V_560 :
V_119 = V_561 ;
break;
case V_562 :
V_119 = V_563 ;
break;
default:
V_119 = 0 ;
break;
}
return V_119 ;
}
long F_243 ( struct V_564 * V_565 ,
unsigned int V_566 , unsigned long V_567 )
{
void V_390 * V_568 = ( void V_390 * ) V_567 ;
long V_119 ;
switch ( V_566 ) {
case V_569 : {
struct V_570 V_390 * V_571 = V_568 ;
struct V_570 V_572 ;
unsigned V_500 ;
V_119 = - V_101 ;
if ( F_238 ( & V_572 , V_571 , sizeof V_572 ) )
goto V_113;
V_500 = V_572 . V_497 ;
V_572 . V_497 = V_573 + V_574 ;
if ( F_239 ( V_571 , & V_572 , sizeof V_572 ) )
goto V_113;
V_119 = - V_376 ;
if ( V_500 < V_572 . V_497 )
goto V_113;
V_119 = - V_101 ;
if ( F_239 ( V_571 -> V_575 , & V_576 ,
V_573 * sizeof( T_1 ) ) )
goto V_113;
if ( F_239 ( V_571 -> V_575 + V_573 ,
& V_577 ,
V_574 * sizeof( T_1 ) ) )
goto V_113;
V_119 = 0 ;
break;
}
case V_578 :
case V_579 : {
struct V_580 V_390 * V_581 = V_568 ;
struct V_580 V_582 ;
V_119 = - V_101 ;
if ( F_238 ( & V_582 , V_581 , sizeof V_582 ) )
goto V_113;
V_119 = F_244 ( & V_582 , V_581 -> V_494 ,
V_566 ) ;
if ( V_119 )
goto V_113;
V_119 = - V_101 ;
if ( F_239 ( V_581 , & V_582 , sizeof V_582 ) )
goto V_113;
V_119 = 0 ;
break;
}
case V_583 : {
T_2 V_584 ;
V_584 = V_585 ;
V_119 = - V_101 ;
if ( F_239 ( V_568 , & V_584 , sizeof V_584 ) )
goto V_113;
V_119 = 0 ;
break;
}
default:
V_119 = - V_586 ;
}
V_113:
return V_119 ;
}
static void F_245 ( void * V_587 )
{
F_246 () ;
}
static bool F_247 ( struct V_1 * V_2 )
{
return F_248 ( V_2 -> V_137 ) ;
}
void F_249 ( struct V_1 * V_2 , int V_23 )
{
if ( F_247 ( V_2 ) ) {
if ( V_73 -> V_588 () )
F_250 ( V_23 , V_2 -> V_5 . V_589 ) ;
else if ( V_2 -> V_23 != - 1 && V_2 -> V_23 != V_23 )
F_251 ( V_2 -> V_23 ,
F_245 , NULL , 1 ) ;
}
V_73 -> V_590 ( V_2 , V_23 ) ;
if ( F_155 ( V_2 -> V_5 . V_591 ) ) {
F_252 ( V_2 , V_2 -> V_5 . V_591 ) ;
V_2 -> V_5 . V_591 = 0 ;
F_31 ( V_324 , V_2 ) ;
}
if ( F_155 ( V_2 -> V_23 != V_23 ) || F_143 () ) {
T_12 V_592 = ! V_2 -> V_5 . V_593 ? 0 :
F_169 () - V_2 -> V_5 . V_593 ;
if ( V_592 < 0 )
F_253 ( L_20 ) ;
if ( F_143 () ) {
T_2 V_94 = V_73 -> V_299 ( V_2 ,
V_2 -> V_5 . V_311 ) ;
V_73 -> V_312 ( V_2 , V_94 ) ;
V_2 -> V_5 . V_335 = 1 ;
}
if ( ! V_2 -> V_137 -> V_5 . V_285 || V_2 -> V_23 == - 1 )
F_31 ( V_448 , V_2 ) ;
if ( V_2 -> V_23 != V_23 )
F_254 ( V_2 ) ;
V_2 -> V_23 = V_23 ;
}
F_208 ( V_2 ) ;
F_31 ( V_453 , V_2 ) ;
}
void F_255 ( struct V_1 * V_2 )
{
V_73 -> V_594 ( V_2 ) ;
F_256 ( V_2 ) ;
V_2 -> V_5 . V_593 = F_169 () ;
}
static int F_257 ( struct V_1 * V_2 ,
struct V_595 * V_596 )
{
V_73 -> V_597 ( V_2 ) ;
memcpy ( V_596 -> V_598 , V_2 -> V_5 . V_599 -> V_598 , sizeof *V_596 ) ;
return 0 ;
}
static int F_258 ( struct V_1 * V_2 ,
struct V_595 * V_596 )
{
F_259 ( V_2 , V_596 ) ;
F_260 ( V_2 ) ;
return 0 ;
}
static int F_261 ( struct V_1 * V_2 ,
struct V_600 * V_601 )
{
if ( V_601 -> V_601 >= V_602 )
return - V_586 ;
if ( F_87 ( V_2 -> V_137 ) )
return - V_603 ;
F_262 ( V_2 , V_601 -> V_601 , false ) ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
static int F_263 ( struct V_1 * V_2 )
{
F_41 ( V_2 ) ;
return 0 ;
}
static int F_264 ( struct V_1 * V_2 )
{
F_31 ( V_604 , V_2 ) ;
return 0 ;
}
static int F_265 ( struct V_1 * V_2 ,
struct V_605 * V_606 )
{
if ( V_606 -> V_294 )
return - V_586 ;
V_2 -> V_5 . V_607 = ! ! V_606 -> V_608 ;
return 0 ;
}
static int F_266 ( struct V_1 * V_2 ,
T_2 V_356 )
{
int V_119 ;
unsigned V_357 = V_356 & 0xff , V_609 ;
V_119 = - V_586 ;
if ( ! V_357 || V_357 >= V_455 )
goto V_113;
if ( V_356 & ~ ( V_585 | 0xff | 0xff0000 ) )
goto V_113;
V_119 = 0 ;
V_2 -> V_5 . V_356 = V_356 ;
if ( V_356 & V_361 )
V_2 -> V_5 . V_362 = ~ ( T_2 ) 0 ;
for ( V_609 = 0 ; V_609 < V_357 ; V_609 ++ )
V_2 -> V_5 . V_364 [ V_609 * 4 ] = ~ ( T_2 ) 0 ;
V_113:
return V_119 ;
}
static int F_267 ( struct V_1 * V_2 ,
struct V_610 * V_611 )
{
T_2 V_356 = V_2 -> V_5 . V_356 ;
unsigned V_357 = V_356 & 0xff ;
T_2 * V_612 = V_2 -> V_5 . V_364 ;
if ( V_611 -> V_609 >= V_357 || ! ( V_611 -> V_472 & V_613 ) )
return - V_586 ;
if ( ( V_611 -> V_472 & V_614 ) && ( V_356 & V_361 ) &&
V_2 -> V_5 . V_362 != ~ ( T_2 ) 0 )
return 0 ;
V_612 += 4 * V_611 -> V_609 ;
if ( ( V_611 -> V_472 & V_614 ) && V_612 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_611 -> V_472 & V_614 ) {
if ( ( V_2 -> V_5 . V_359 & V_615 ) ||
! F_46 ( V_2 , V_616 ) ) {
F_31 ( V_72 , V_2 ) ;
return 0 ;
}
if ( V_612 [ 1 ] & V_613 )
V_611 -> V_472 |= V_617 ;
V_612 [ 2 ] = V_611 -> V_386 ;
V_612 [ 3 ] = V_611 -> V_618 ;
V_2 -> V_5 . V_359 = V_611 -> V_359 ;
V_612 [ 1 ] = V_611 -> V_472 ;
F_33 ( V_2 , V_58 ) ;
} else if ( ! ( V_612 [ 1 ] & V_613 )
|| ! ( V_612 [ 1 ] & V_614 ) ) {
if ( V_612 [ 1 ] & V_613 )
V_611 -> V_472 |= V_617 ;
V_612 [ 2 ] = V_611 -> V_386 ;
V_612 [ 3 ] = V_611 -> V_618 ;
V_612 [ 1 ] = V_611 -> V_472 ;
} else
V_612 [ 1 ] |= V_617 ;
return 0 ;
}
static void F_268 ( struct V_1 * V_2 ,
struct V_619 * V_620 )
{
F_269 ( V_2 ) ;
V_620 -> V_68 . V_621 =
V_2 -> V_5 . V_68 . V_69 &&
! F_270 ( V_2 -> V_5 . V_68 . V_16 ) ;
V_620 -> V_68 . V_16 = V_2 -> V_5 . V_68 . V_16 ;
V_620 -> V_68 . V_71 = V_2 -> V_5 . V_68 . V_71 ;
V_620 -> V_68 . V_622 = 0 ;
V_620 -> V_68 . V_62 = V_2 -> V_5 . V_68 . V_62 ;
V_620 -> V_623 . V_621 =
V_2 -> V_5 . V_623 . V_69 && ! V_2 -> V_5 . V_623 . V_624 ;
V_620 -> V_623 . V_16 = V_2 -> V_5 . V_623 . V_16 ;
V_620 -> V_623 . V_624 = 0 ;
V_620 -> V_623 . V_625 = V_73 -> V_626 ( V_2 ) ;
V_620 -> V_627 . V_621 = V_2 -> V_5 . V_628 ;
V_620 -> V_627 . V_69 = V_2 -> V_5 . V_629 != 0 ;
V_620 -> V_627 . V_630 = V_73 -> V_631 ( V_2 ) ;
V_620 -> V_627 . V_622 = 0 ;
V_620 -> V_632 = 0 ;
V_620 -> V_633 . V_634 = F_271 ( V_2 ) ;
V_620 -> V_633 . V_69 = V_2 -> V_5 . V_635 ;
V_620 -> V_633 . V_636 =
! ! ( V_2 -> V_5 . V_637 & V_638 ) ;
V_620 -> V_633 . V_639 = F_272 ( V_2 ) ;
V_620 -> V_294 = ( V_640
| V_641
| V_642 ) ;
memset ( & V_620 -> V_643 , 0 , sizeof( V_620 -> V_643 ) ) ;
}
static int F_273 ( struct V_1 * V_2 ,
struct V_619 * V_620 )
{
if ( V_620 -> V_294 & ~ ( V_640
| V_644
| V_641
| V_642 ) )
return - V_586 ;
F_269 ( V_2 ) ;
V_2 -> V_5 . V_68 . V_69 = V_620 -> V_68 . V_621 ;
V_2 -> V_5 . V_68 . V_16 = V_620 -> V_68 . V_16 ;
V_2 -> V_5 . V_68 . V_71 = V_620 -> V_68 . V_71 ;
V_2 -> V_5 . V_68 . V_62 = V_620 -> V_68 . V_62 ;
V_2 -> V_5 . V_623 . V_69 = V_620 -> V_623 . V_621 ;
V_2 -> V_5 . V_623 . V_16 = V_620 -> V_623 . V_16 ;
V_2 -> V_5 . V_623 . V_624 = V_620 -> V_623 . V_624 ;
if ( V_620 -> V_294 & V_641 )
V_73 -> V_645 ( V_2 ,
V_620 -> V_623 . V_625 ) ;
V_2 -> V_5 . V_628 = V_620 -> V_627 . V_621 ;
if ( V_620 -> V_294 & V_640 )
V_2 -> V_5 . V_629 = V_620 -> V_627 . V_69 ;
V_73 -> V_646 ( V_2 , V_620 -> V_627 . V_630 ) ;
if ( V_620 -> V_294 & V_644 &&
F_274 ( V_2 ) )
V_2 -> V_5 . V_599 -> V_632 = V_620 -> V_632 ;
if ( V_620 -> V_294 & V_642 ) {
if ( V_620 -> V_633 . V_634 )
V_2 -> V_5 . V_637 |= V_647 ;
else
V_2 -> V_5 . V_637 &= ~ V_647 ;
V_2 -> V_5 . V_635 = V_620 -> V_633 . V_69 ;
if ( V_620 -> V_633 . V_636 )
V_2 -> V_5 . V_637 |= V_638 ;
else
V_2 -> V_5 . V_637 &= ~ V_638 ;
if ( F_274 ( V_2 ) ) {
if ( V_620 -> V_633 . V_639 )
F_214 ( V_648 , & V_2 -> V_5 . V_599 -> V_649 ) ;
else
F_164 ( V_648 , & V_2 -> V_5 . V_599 -> V_649 ) ;
}
}
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
static void F_275 ( struct V_1 * V_2 ,
struct V_650 * V_651 )
{
unsigned long V_192 ;
memcpy ( V_651 -> V_179 , V_2 -> V_5 . V_179 , sizeof( V_2 -> V_5 . V_179 ) ) ;
F_98 ( V_2 , 6 , & V_192 ) ;
V_651 -> V_183 = V_192 ;
V_651 -> V_184 = V_2 -> V_5 . V_184 ;
V_651 -> V_294 = 0 ;
memset ( & V_651 -> V_643 , 0 , sizeof( V_651 -> V_643 ) ) ;
}
static int F_276 ( struct V_1 * V_2 ,
struct V_650 * V_651 )
{
if ( V_651 -> V_294 )
return - V_586 ;
memcpy ( V_2 -> V_5 . V_179 , V_651 -> V_179 , sizeof( V_2 -> V_5 . V_179 ) ) ;
F_91 ( V_2 ) ;
V_2 -> V_5 . V_183 = V_651 -> V_183 ;
F_92 ( V_2 ) ;
V_2 -> V_5 . V_184 = V_651 -> V_184 ;
F_93 ( V_2 ) ;
return 0 ;
}
static void F_277 ( T_14 * V_652 , struct V_1 * V_2 )
{
struct V_653 * V_654 = & V_2 -> V_5 . V_655 . V_656 . V_654 ;
T_2 V_657 = V_654 -> V_658 . V_659 ;
T_2 V_660 ;
memcpy ( V_652 , V_654 , V_661 ) ;
* ( T_2 * ) ( V_652 + V_661 ) = V_657 ;
V_660 = V_657 & ~ V_662 ;
while ( V_660 ) {
T_2 V_663 = V_660 & - V_660 ;
int V_144 = F_278 ( V_663 ) - 1 ;
void * V_664 = F_279 ( V_654 , V_663 ) ;
if ( V_664 ) {
T_1 V_501 , V_94 , V_197 , V_205 ;
F_280 ( V_665 , V_144 ,
& V_501 , & V_94 , & V_197 , & V_205 ) ;
memcpy ( V_652 + V_94 , V_664 , V_501 ) ;
}
V_660 -= V_663 ;
}
}
static void F_281 ( struct V_1 * V_2 , T_14 * V_664 )
{
struct V_653 * V_654 = & V_2 -> V_5 . V_655 . V_656 . V_654 ;
T_2 V_657 = * ( T_2 * ) ( V_664 + V_661 ) ;
T_2 V_660 ;
memcpy ( V_654 , V_664 , V_661 ) ;
V_654 -> V_658 . V_659 = V_657 ;
if ( V_666 )
V_654 -> V_658 . V_667 = V_143 | V_668 ;
V_660 = V_657 & ~ V_662 ;
while ( V_660 ) {
T_2 V_663 = V_660 & - V_660 ;
int V_144 = F_278 ( V_663 ) - 1 ;
void * V_652 = F_279 ( V_654 , V_663 ) ;
if ( V_652 ) {
T_1 V_501 , V_94 , V_197 , V_205 ;
F_280 ( V_665 , V_144 ,
& V_501 , & V_94 , & V_197 , & V_205 ) ;
memcpy ( V_652 , V_664 + V_94 , V_501 ) ;
}
V_660 -= V_663 ;
}
}
static void F_282 ( struct V_1 * V_2 ,
struct V_669 * V_670 )
{
if ( V_561 ) {
memset ( V_670 , 0 , sizeof( struct V_669 ) ) ;
F_277 ( ( T_14 * ) V_670 -> V_671 , V_2 ) ;
} else {
memcpy ( V_670 -> V_671 ,
& V_2 -> V_5 . V_655 . V_656 . V_672 ,
sizeof( struct V_673 ) ) ;
* ( T_2 * ) & V_670 -> V_671 [ V_661 / sizeof( T_1 ) ] =
V_662 ;
}
}
static int F_283 ( struct V_1 * V_2 ,
struct V_669 * V_670 )
{
T_2 V_657 =
* ( T_2 * ) & V_670 -> V_671 [ V_661 / sizeof( T_1 ) ] ;
if ( V_561 ) {
if ( V_657 & ~ F_284 () )
return - V_586 ;
F_281 ( V_2 , ( T_14 * ) V_670 -> V_671 ) ;
} else {
if ( V_657 & ~ V_662 )
return - V_586 ;
memcpy ( & V_2 -> V_5 . V_655 . V_656 . V_672 ,
V_670 -> V_671 , sizeof( struct V_673 ) ) ;
}
return 0 ;
}
static void F_285 ( struct V_1 * V_2 ,
struct V_674 * V_675 )
{
if ( ! V_561 ) {
V_675 -> V_676 = 0 ;
return;
}
V_675 -> V_676 = 1 ;
V_675 -> V_294 = 0 ;
V_675 -> V_677 [ 0 ] . V_145 = V_141 ;
V_675 -> V_677 [ 0 ] . V_22 = V_2 -> V_5 . V_142 ;
}
static int F_286 ( struct V_1 * V_2 ,
struct V_674 * V_675 )
{
int V_3 , V_119 = 0 ;
if ( ! V_561 )
return - V_586 ;
if ( V_675 -> V_676 > V_678 || V_675 -> V_294 )
return - V_586 ;
for ( V_3 = 0 ; V_3 < V_675 -> V_676 ; V_3 ++ )
if ( V_675 -> V_677 [ V_3 ] . V_145 == V_141 ) {
V_119 = F_73 ( V_2 , V_141 ,
V_675 -> V_677 [ V_3 ] . V_22 ) ;
break;
}
if ( V_119 )
V_119 = - V_586 ;
return V_119 ;
}
static int F_287 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_336 )
return - V_586 ;
V_2 -> V_5 . V_344 = true ;
F_31 ( V_324 , V_2 ) ;
return 0 ;
}
long F_288 ( struct V_564 * V_565 ,
unsigned int V_566 , unsigned long V_567 )
{
struct V_1 * V_2 = V_565 -> V_679 ;
void V_390 * V_568 = ( void V_390 * ) V_567 ;
int V_119 ;
union {
struct V_595 * V_680 ;
struct V_669 * V_654 ;
struct V_674 * V_677 ;
void * V_681 ;
} V_682 ;
V_682 . V_681 = NULL ;
switch ( V_566 ) {
case V_683 : {
V_119 = - V_586 ;
if ( ! V_2 -> V_5 . V_599 )
goto V_113;
V_682 . V_680 = F_289 ( sizeof( struct V_595 ) , V_684 ) ;
V_119 = - V_377 ;
if ( ! V_682 . V_680 )
goto V_113;
V_119 = F_257 ( V_2 , V_682 . V_680 ) ;
if ( V_119 )
goto V_113;
V_119 = - V_101 ;
if ( F_239 ( V_568 , V_682 . V_680 , sizeof( struct V_595 ) ) )
goto V_113;
V_119 = 0 ;
break;
}
case V_685 : {
V_119 = - V_586 ;
if ( ! V_2 -> V_5 . V_599 )
goto V_113;
V_682 . V_680 = F_185 ( V_568 , sizeof( * V_682 . V_680 ) ) ;
if ( F_186 ( V_682 . V_680 ) )
return F_187 ( V_682 . V_680 ) ;
V_119 = F_258 ( V_2 , V_682 . V_680 ) ;
break;
}
case V_686 : {
struct V_600 V_601 ;
V_119 = - V_101 ;
if ( F_238 ( & V_601 , V_568 , sizeof V_601 ) )
goto V_113;
V_119 = F_261 ( V_2 , & V_601 ) ;
break;
}
case V_687 : {
V_119 = F_263 ( V_2 ) ;
break;
}
case V_688 : {
V_119 = F_264 ( V_2 ) ;
break;
}
case V_689 : {
struct V_690 V_390 * V_581 = V_568 ;
struct V_690 V_582 ;
V_119 = - V_101 ;
if ( F_238 ( & V_582 , V_581 , sizeof V_582 ) )
goto V_113;
V_119 = F_290 ( V_2 , & V_582 , V_581 -> V_494 ) ;
break;
}
case V_691 : {
struct V_580 V_390 * V_581 = V_568 ;
struct V_580 V_582 ;
V_119 = - V_101 ;
if ( F_238 ( & V_582 , V_581 , sizeof V_582 ) )
goto V_113;
V_119 = F_291 ( V_2 , & V_582 ,
V_581 -> V_494 ) ;
break;
}
case V_692 : {
struct V_580 V_390 * V_581 = V_568 ;
struct V_580 V_582 ;
V_119 = - V_101 ;
if ( F_238 ( & V_582 , V_581 , sizeof V_582 ) )
goto V_113;
V_119 = F_292 ( V_2 , & V_582 ,
V_581 -> V_494 ) ;
if ( V_119 )
goto V_113;
V_119 = - V_101 ;
if ( F_239 ( V_581 , & V_582 , sizeof V_582 ) )
goto V_113;
V_119 = 0 ;
break;
}
case V_693 :
V_119 = F_237 ( V_2 , V_568 , F_111 , 1 ) ;
break;
case V_694 :
V_119 = F_237 ( V_2 , V_568 , F_113 , 0 ) ;
break;
case V_695 : {
struct V_605 V_606 ;
V_119 = - V_101 ;
if ( F_238 ( & V_606 , V_568 , sizeof V_606 ) )
goto V_113;
V_119 = F_265 ( V_2 , & V_606 ) ;
if ( V_119 )
goto V_113;
V_119 = - V_101 ;
if ( F_239 ( V_568 , & V_606 , sizeof V_606 ) )
goto V_113;
V_119 = 0 ;
break;
} ;
case V_696 : {
struct V_697 V_698 ;
V_119 = - V_586 ;
if ( ! F_87 ( V_2 -> V_137 ) )
goto V_113;
V_119 = - V_101 ;
if ( F_238 ( & V_698 , V_568 , sizeof V_698 ) )
goto V_113;
V_119 = F_293 ( V_2 , V_698 . V_699 ) ;
break;
}
case V_700 : {
T_2 V_356 ;
V_119 = - V_101 ;
if ( F_238 ( & V_356 , V_568 , sizeof V_356 ) )
goto V_113;
V_119 = F_266 ( V_2 , V_356 ) ;
break;
}
case V_701 : {
struct V_610 V_611 ;
V_119 = - V_101 ;
if ( F_238 ( & V_611 , V_568 , sizeof V_611 ) )
goto V_113;
V_119 = F_267 ( V_2 , & V_611 ) ;
break;
}
case V_702 : {
struct V_619 V_620 ;
F_268 ( V_2 , & V_620 ) ;
V_119 = - V_101 ;
if ( F_239 ( V_568 , & V_620 , sizeof( struct V_619 ) ) )
break;
V_119 = 0 ;
break;
}
case V_703 : {
struct V_619 V_620 ;
V_119 = - V_101 ;
if ( F_238 ( & V_620 , V_568 , sizeof( struct V_619 ) ) )
break;
V_119 = F_273 ( V_2 , & V_620 ) ;
break;
}
case V_704 : {
struct V_650 V_651 ;
F_275 ( V_2 , & V_651 ) ;
V_119 = - V_101 ;
if ( F_239 ( V_568 , & V_651 ,
sizeof( struct V_650 ) ) )
break;
V_119 = 0 ;
break;
}
case V_705 : {
struct V_650 V_651 ;
V_119 = - V_101 ;
if ( F_238 ( & V_651 , V_568 ,
sizeof( struct V_650 ) ) )
break;
V_119 = F_276 ( V_2 , & V_651 ) ;
break;
}
case V_706 : {
V_682 . V_654 = F_289 ( sizeof( struct V_669 ) , V_684 ) ;
V_119 = - V_377 ;
if ( ! V_682 . V_654 )
break;
F_282 ( V_2 , V_682 . V_654 ) ;
V_119 = - V_101 ;
if ( F_239 ( V_568 , V_682 . V_654 , sizeof( struct V_669 ) ) )
break;
V_119 = 0 ;
break;
}
case V_707 : {
V_682 . V_654 = F_185 ( V_568 , sizeof( * V_682 . V_654 ) ) ;
if ( F_186 ( V_682 . V_654 ) )
return F_187 ( V_682 . V_654 ) ;
V_119 = F_283 ( V_2 , V_682 . V_654 ) ;
break;
}
case V_708 : {
V_682 . V_677 = F_289 ( sizeof( struct V_674 ) , V_684 ) ;
V_119 = - V_377 ;
if ( ! V_682 . V_677 )
break;
F_285 ( V_2 , V_682 . V_677 ) ;
V_119 = - V_101 ;
if ( F_239 ( V_568 , V_682 . V_677 ,
sizeof( struct V_674 ) ) )
break;
V_119 = 0 ;
break;
}
case V_709 : {
V_682 . V_677 = F_185 ( V_568 , sizeof( * V_682 . V_677 ) ) ;
if ( F_186 ( V_682 . V_677 ) )
return F_187 ( V_682 . V_677 ) ;
V_119 = F_286 ( V_2 , V_682 . V_677 ) ;
break;
}
case V_710 : {
T_1 V_711 ;
V_119 = - V_586 ;
V_711 = ( T_1 ) V_567 ;
if ( V_711 >= V_712 )
goto V_113;
if ( V_711 == 0 )
V_711 = V_272 ;
F_135 ( V_2 , V_711 ) ;
V_119 = 0 ;
goto V_113;
}
case V_713 : {
V_119 = V_2 -> V_5 . V_271 ;
goto V_113;
}
case V_714 : {
V_119 = F_287 ( V_2 ) ;
goto V_113;
}
default:
V_119 = - V_586 ;
}
V_113:
F_189 ( V_682 . V_681 ) ;
return V_119 ;
}
int F_294 ( struct V_1 * V_2 , struct V_715 * V_716 )
{
return V_717 ;
}
static int F_295 ( struct V_137 * V_137 , unsigned long V_386 )
{
int V_108 ;
if ( V_386 > ( unsigned int ) ( - 3 * V_107 ) )
return - V_586 ;
V_108 = V_73 -> V_718 ( V_137 , V_386 ) ;
return V_108 ;
}
static int F_296 ( struct V_137 * V_137 ,
T_2 V_719 )
{
V_137 -> V_5 . V_720 = V_719 ;
return 0 ;
}
static int F_297 ( struct V_137 * V_137 ,
T_1 V_721 )
{
if ( V_721 < V_722 )
return - V_586 ;
F_220 ( & V_137 -> V_723 ) ;
F_298 ( V_137 , V_721 ) ;
V_137 -> V_5 . V_724 = V_721 ;
F_221 ( & V_137 -> V_723 ) ;
return 0 ;
}
static int F_299 ( struct V_137 * V_137 )
{
return V_137 -> V_5 . V_725 ;
}
static int F_300 ( struct V_137 * V_137 , struct V_726 * V_727 )
{
int V_119 ;
V_119 = 0 ;
switch ( V_727 -> V_728 ) {
case V_729 :
memcpy ( & V_727 -> V_727 . V_730 ,
& F_301 ( V_137 ) -> V_731 [ 0 ] ,
sizeof( struct V_732 ) ) ;
break;
case V_733 :
memcpy ( & V_727 -> V_727 . V_730 ,
& F_301 ( V_137 ) -> V_731 [ 1 ] ,
sizeof( struct V_732 ) ) ;
break;
case V_734 :
V_119 = F_302 ( V_137 , & V_727 -> V_727 . V_735 ) ;
break;
default:
V_119 = - V_586 ;
break;
}
return V_119 ;
}
static int F_303 ( struct V_137 * V_137 , struct V_726 * V_727 )
{
int V_119 ;
V_119 = 0 ;
switch ( V_727 -> V_728 ) {
case V_729 :
F_146 ( & F_301 ( V_137 ) -> V_466 ) ;
memcpy ( & F_301 ( V_137 ) -> V_731 [ 0 ] ,
& V_727 -> V_727 . V_730 ,
sizeof( struct V_732 ) ) ;
F_147 ( & F_301 ( V_137 ) -> V_466 ) ;
break;
case V_733 :
F_146 ( & F_301 ( V_137 ) -> V_466 ) ;
memcpy ( & F_301 ( V_137 ) -> V_731 [ 1 ] ,
& V_727 -> V_727 . V_730 ,
sizeof( struct V_732 ) ) ;
F_147 ( & F_301 ( V_137 ) -> V_466 ) ;
break;
case V_734 :
V_119 = F_304 ( V_137 , & V_727 -> V_727 . V_735 ) ;
break;
default:
V_119 = - V_586 ;
break;
}
F_305 ( F_301 ( V_137 ) ) ;
return V_119 ;
}
static int F_306 ( struct V_137 * V_137 , struct V_736 * V_737 )
{
int V_119 = 0 ;
F_220 ( & V_137 -> V_5 . V_738 -> V_739 . V_466 ) ;
memcpy ( V_737 , & V_137 -> V_5 . V_738 -> V_739 , sizeof( struct V_736 ) ) ;
F_221 ( & V_137 -> V_5 . V_738 -> V_739 . V_466 ) ;
return V_119 ;
}
static int F_307 ( struct V_137 * V_137 , struct V_736 * V_737 )
{
int V_119 = 0 ;
F_220 ( & V_137 -> V_5 . V_738 -> V_739 . V_466 ) ;
memcpy ( & V_137 -> V_5 . V_738 -> V_739 , V_737 , sizeof( struct V_736 ) ) ;
F_308 ( V_137 , 0 , V_737 -> V_740 [ 0 ] . V_741 , 0 ) ;
F_221 ( & V_137 -> V_5 . V_738 -> V_739 . V_466 ) ;
return V_119 ;
}
static int F_309 ( struct V_137 * V_137 , struct V_742 * V_737 )
{
int V_119 = 0 ;
F_220 ( & V_137 -> V_5 . V_738 -> V_739 . V_466 ) ;
memcpy ( V_737 -> V_740 , & V_137 -> V_5 . V_738 -> V_739 . V_740 ,
sizeof( V_737 -> V_740 ) ) ;
V_737 -> V_294 = V_137 -> V_5 . V_738 -> V_739 . V_294 ;
F_221 ( & V_137 -> V_5 . V_738 -> V_739 . V_466 ) ;
memset ( & V_737 -> V_643 , 0 , sizeof( V_737 -> V_643 ) ) ;
return V_119 ;
}
static int F_310 ( struct V_137 * V_137 , struct V_742 * V_737 )
{
int V_119 = 0 , V_743 = 0 ;
T_1 V_744 , V_745 ;
F_220 ( & V_137 -> V_5 . V_738 -> V_739 . V_466 ) ;
V_744 = V_137 -> V_5 . V_738 -> V_739 . V_294 & V_746 ;
V_745 = V_737 -> V_294 & V_746 ;
if ( ! V_744 && V_745 )
V_743 = 1 ;
memcpy ( & V_137 -> V_5 . V_738 -> V_739 . V_740 , & V_737 -> V_740 ,
sizeof( V_137 -> V_5 . V_738 -> V_739 . V_740 ) ) ;
V_137 -> V_5 . V_738 -> V_739 . V_294 = V_737 -> V_294 ;
F_308 ( V_137 , 0 , V_137 -> V_5 . V_738 -> V_739 . V_740 [ 0 ] . V_741 , V_743 ) ;
F_221 ( & V_137 -> V_5 . V_738 -> V_739 . V_466 ) ;
return V_119 ;
}
static int F_311 ( struct V_137 * V_137 ,
struct V_747 * V_748 )
{
if ( ! V_137 -> V_5 . V_738 )
return - V_603 ;
F_220 ( & V_137 -> V_5 . V_738 -> V_739 . V_466 ) ;
V_137 -> V_5 . V_738 -> V_739 . V_63 = V_748 -> V_749 ;
F_221 ( & V_137 -> V_5 . V_738 -> V_739 . V_466 ) ;
return 0 ;
}
int F_312 ( struct V_137 * V_137 , struct V_750 * log )
{
bool V_751 = false ;
int V_119 ;
F_220 ( & V_137 -> V_723 ) ;
if ( V_73 -> V_752 )
V_73 -> V_752 ( V_137 ) ;
V_119 = F_313 ( V_137 , log , & V_751 ) ;
F_314 ( & V_137 -> V_723 ) ;
if ( V_751 )
F_315 ( V_137 ) ;
F_221 ( & V_137 -> V_723 ) ;
return V_119 ;
}
int F_316 ( struct V_137 * V_137 , struct V_753 * V_754 ,
bool V_755 )
{
if ( ! F_87 ( V_137 ) )
return - V_603 ;
V_754 -> V_472 = F_317 ( V_137 , V_756 ,
V_754 -> V_601 , V_754 -> V_757 ,
V_755 ) ;
return 0 ;
}
static int F_318 ( struct V_137 * V_137 ,
struct V_758 * V_759 )
{
int V_119 ;
if ( V_759 -> V_294 )
return - V_586 ;
switch ( V_759 -> V_759 ) {
case V_541 :
V_137 -> V_5 . V_760 = V_759 -> args [ 0 ] ;
V_119 = 0 ;
break;
default:
V_119 = - V_586 ;
break;
}
return V_119 ;
}
long F_319 ( struct V_564 * V_565 ,
unsigned int V_566 , unsigned long V_567 )
{
struct V_137 * V_137 = V_565 -> V_679 ;
void V_390 * V_568 = ( void V_390 * ) V_567 ;
int V_119 = - V_761 ;
union {
struct V_736 V_737 ;
struct V_742 V_762 ;
struct V_763 V_764 ;
} V_682 ;
switch ( V_566 ) {
case V_765 :
V_119 = F_295 ( V_137 , V_567 ) ;
break;
case V_766 : {
T_2 V_719 ;
V_119 = - V_101 ;
if ( F_238 ( & V_719 , V_568 , sizeof V_719 ) )
goto V_113;
V_119 = F_296 ( V_137 , V_719 ) ;
break;
}
case V_767 :
V_119 = F_297 ( V_137 , V_567 ) ;
break;
case V_768 :
V_119 = F_299 ( V_137 ) ;
break;
case V_769 : {
struct V_770 * V_771 ;
F_220 ( & V_137 -> V_466 ) ;
V_119 = - V_772 ;
if ( V_137 -> V_5 . V_771 )
goto V_773;
V_119 = - V_586 ;
if ( F_138 ( & V_137 -> V_284 ) )
goto V_773;
V_119 = - V_377 ;
V_771 = F_320 ( V_137 ) ;
if ( V_771 ) {
V_119 = F_321 ( V_137 ) ;
if ( V_119 ) {
F_220 ( & V_137 -> V_723 ) ;
F_322 ( V_137 , V_774 ,
& V_771 -> V_775 ) ;
F_322 ( V_137 , V_774 ,
& V_771 -> V_776 ) ;
F_322 ( V_137 , V_774 ,
& V_771 -> V_777 ) ;
F_221 ( & V_137 -> V_723 ) ;
F_189 ( V_771 ) ;
goto V_773;
}
} else
goto V_773;
F_14 () ;
V_137 -> V_5 . V_771 = V_771 ;
F_14 () ;
V_119 = F_323 ( V_137 ) ;
if ( V_119 ) {
F_220 ( & V_137 -> V_723 ) ;
F_220 ( & V_137 -> V_778 ) ;
F_324 ( V_137 ) ;
F_325 ( V_137 ) ;
F_221 ( & V_137 -> V_778 ) ;
F_221 ( & V_137 -> V_723 ) ;
}
V_773:
F_221 ( & V_137 -> V_466 ) ;
break;
}
case V_779 :
V_682 . V_764 . V_294 = V_780 ;
goto V_781;
case V_782 :
V_119 = - V_101 ;
if ( F_238 ( & V_682 . V_764 , V_568 ,
sizeof( struct V_763 ) ) )
goto V_113;
V_781:
F_220 ( & V_137 -> V_723 ) ;
V_119 = - V_772 ;
if ( V_137 -> V_5 . V_738 )
goto V_783;
V_119 = - V_377 ;
V_137 -> V_5 . V_738 = F_326 ( V_137 , V_682 . V_764 . V_294 ) ;
if ( V_137 -> V_5 . V_738 )
V_119 = 0 ;
V_783:
F_221 ( & V_137 -> V_723 ) ;
break;
case V_784 : {
struct V_726 * V_727 ;
V_727 = F_185 ( V_568 , sizeof( * V_727 ) ) ;
if ( F_186 ( V_727 ) ) {
V_119 = F_187 ( V_727 ) ;
goto V_113;
}
V_119 = - V_603 ;
if ( ! F_87 ( V_137 ) )
goto V_785;
V_119 = F_300 ( V_137 , V_727 ) ;
if ( V_119 )
goto V_785;
V_119 = - V_101 ;
if ( F_239 ( V_568 , V_727 , sizeof *V_727 ) )
goto V_785;
V_119 = 0 ;
V_785:
F_189 ( V_727 ) ;
break;
}
case V_786 : {
struct V_726 * V_727 ;
V_727 = F_185 ( V_568 , sizeof( * V_727 ) ) ;
if ( F_186 ( V_727 ) ) {
V_119 = F_187 ( V_727 ) ;
goto V_113;
}
V_119 = - V_603 ;
if ( ! F_87 ( V_137 ) )
goto V_787;
V_119 = F_303 ( V_137 , V_727 ) ;
if ( V_119 )
goto V_787;
V_119 = 0 ;
V_787:
F_189 ( V_727 ) ;
break;
}
case V_788 : {
V_119 = - V_101 ;
if ( F_238 ( & V_682 . V_737 , V_568 , sizeof( struct V_736 ) ) )
goto V_113;
V_119 = - V_603 ;
if ( ! V_137 -> V_5 . V_738 )
goto V_113;
V_119 = F_306 ( V_137 , & V_682 . V_737 ) ;
if ( V_119 )
goto V_113;
V_119 = - V_101 ;
if ( F_239 ( V_568 , & V_682 . V_737 , sizeof( struct V_736 ) ) )
goto V_113;
V_119 = 0 ;
break;
}
case V_789 : {
V_119 = - V_101 ;
if ( F_238 ( & V_682 . V_737 , V_568 , sizeof V_682 . V_737 ) )
goto V_113;
V_119 = - V_603 ;
if ( ! V_137 -> V_5 . V_738 )
goto V_113;
V_119 = F_307 ( V_137 , & V_682 . V_737 ) ;
break;
}
case V_790 : {
V_119 = - V_603 ;
if ( ! V_137 -> V_5 . V_738 )
goto V_113;
V_119 = F_309 ( V_137 , & V_682 . V_762 ) ;
if ( V_119 )
goto V_113;
V_119 = - V_101 ;
if ( F_239 ( V_568 , & V_682 . V_762 , sizeof( V_682 . V_762 ) ) )
goto V_113;
V_119 = 0 ;
break;
}
case V_791 : {
V_119 = - V_101 ;
if ( F_238 ( & V_682 . V_762 , V_568 , sizeof( V_682 . V_762 ) ) )
goto V_113;
V_119 = - V_603 ;
if ( ! V_137 -> V_5 . V_738 )
goto V_113;
V_119 = F_310 ( V_137 , & V_682 . V_762 ) ;
break;
}
case V_792 : {
struct V_747 V_748 ;
V_119 = - V_101 ;
if ( F_238 ( & V_748 , V_568 , sizeof( V_748 ) ) )
goto V_113;
V_119 = F_311 ( V_137 , & V_748 ) ;
break;
}
case V_793 : {
V_119 = - V_101 ;
if ( F_238 ( & V_137 -> V_5 . F_184 , V_568 ,
sizeof( struct V_794 ) ) )
goto V_113;
V_119 = - V_586 ;
if ( V_137 -> V_5 . F_184 . V_294 )
goto V_113;
V_119 = 0 ;
break;
}
case V_795 : {
struct V_796 V_797 ;
T_2 V_798 ;
T_12 V_306 ;
V_119 = - V_101 ;
if ( F_238 ( & V_797 , V_568 , sizeof( V_797 ) ) )
goto V_113;
V_119 = - V_586 ;
if ( V_797 . V_294 )
goto V_113;
V_119 = 0 ;
F_327 () ;
V_798 = F_129 () ;
V_306 = V_797 . clock - V_798 ;
F_328 () ;
V_137 -> V_5 . V_243 = V_306 ;
F_161 ( V_137 ) ;
break;
}
case V_799 : {
struct V_796 V_797 ;
T_2 V_798 ;
F_327 () ;
V_798 = F_129 () ;
V_797 . clock = V_137 -> V_5 . V_243 + V_798 ;
F_328 () ;
V_797 . V_294 = 0 ;
memset ( & V_797 . V_622 , 0 , sizeof( V_797 . V_622 ) ) ;
V_119 = - V_101 ;
if ( F_239 ( V_568 , & V_797 , sizeof( V_797 ) ) )
goto V_113;
V_119 = 0 ;
break;
}
case V_800 : {
struct V_758 V_759 ;
V_119 = - V_101 ;
if ( F_238 ( & V_759 , V_568 , sizeof( V_759 ) ) )
goto V_113;
V_119 = F_318 ( V_137 , & V_759 ) ;
break;
}
default:
V_119 = F_329 ( V_137 , V_566 , V_567 ) ;
}
V_113:
return V_119 ;
}
static void F_330 ( void )
{
T_1 V_801 [ 2 ] ;
unsigned V_3 , V_802 ;
for ( V_3 = V_802 = 0 ; V_3 < F_53 ( V_576 ) ; V_3 ++ ) {
if ( F_331 ( V_576 [ V_3 ] , & V_801 [ 0 ] , & V_801 [ 1 ] ) < 0 )
continue;
switch ( V_576 [ V_3 ] ) {
case V_803 :
if ( ! V_73 -> V_804 () )
continue;
break;
default:
break;
}
if ( V_802 < V_3 )
V_576 [ V_802 ] = V_576 [ V_3 ] ;
V_802 ++ ;
}
V_573 = V_802 ;
for ( V_3 = V_802 = 0 ; V_3 < F_53 ( V_577 ) ; V_3 ++ ) {
switch ( V_577 [ V_3 ] ) {
case V_440 :
if ( ! V_73 -> V_545 () )
continue;
break;
default:
break;
}
if ( V_802 < V_3 )
V_577 [ V_802 ] = V_577 [ V_3 ] ;
V_802 ++ ;
}
V_574 = V_802 ;
}
static int F_332 ( struct V_1 * V_2 , T_6 V_386 , int V_95 ,
const void * V_265 )
{
int V_805 = 0 ;
int V_500 ;
do {
V_500 = F_333 ( V_95 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_599 &&
! F_334 ( V_2 , & V_2 -> V_5 . V_599 -> V_806 , V_386 , V_500 , V_265 ) )
&& F_335 ( V_2 , V_807 , V_386 , V_500 , V_265 ) )
break;
V_805 += V_500 ;
V_386 += V_500 ;
V_95 -= V_500 ;
V_265 += V_500 ;
} while ( V_95 );
return V_805 ;
}
static int F_336 ( struct V_1 * V_2 , T_6 V_386 , int V_95 , void * V_265 )
{
int V_805 = 0 ;
int V_500 ;
do {
V_500 = F_333 ( V_95 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_599 &&
! F_337 ( V_2 , & V_2 -> V_5 . V_599 -> V_806 ,
V_386 , V_500 , V_265 ) )
&& F_338 ( V_2 , V_807 , V_386 , V_500 , V_265 ) )
break;
F_339 ( V_808 , V_500 , V_386 , * ( T_2 * ) V_265 ) ;
V_805 += V_500 ;
V_386 += V_500 ;
V_95 -= V_500 ;
V_265 += V_500 ;
} while ( V_95 );
return V_805 ;
}
static void F_340 ( struct V_1 * V_2 ,
struct V_809 * V_810 , int V_811 )
{
V_73 -> V_812 ( V_2 , V_810 , V_811 ) ;
}
void F_341 ( struct V_1 * V_2 ,
struct V_809 * V_810 , int V_811 )
{
V_73 -> V_813 ( V_2 , V_810 , V_811 ) ;
}
T_6 F_342 ( struct V_1 * V_2 , T_6 V_406 , T_1 V_96 ,
struct V_75 * V_68 )
{
T_6 V_814 ;
F_13 ( ! F_40 ( V_2 ) ) ;
V_96 |= V_111 ;
V_814 = V_2 -> V_5 . V_84 . V_815 ( V_2 , V_406 , V_96 , V_68 ) ;
return V_814 ;
}
T_6 F_343 ( struct V_1 * V_2 , T_16 V_816 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
return V_2 -> V_5 . V_103 -> V_815 ( V_2 , V_816 , V_96 , V_68 ) ;
}
T_6 F_344 ( struct V_1 * V_2 , T_16 V_816 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
V_96 |= V_817 ;
return V_2 -> V_5 . V_103 -> V_815 ( V_2 , V_816 , V_96 , V_68 ) ;
}
T_6 F_345 ( struct V_1 * V_2 , T_16 V_816 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
V_96 |= V_112 ;
return V_2 -> V_5 . V_103 -> V_815 ( V_2 , V_816 , V_96 , V_68 ) ;
}
T_6 F_346 ( struct V_1 * V_2 , T_16 V_816 ,
struct V_75 * V_68 )
{
return V_2 -> V_5 . V_103 -> V_815 ( V_2 , V_816 , 0 , V_68 ) ;
}
static int F_347 ( T_16 V_386 , void * V_192 , unsigned int V_818 ,
struct V_1 * V_2 , T_1 V_96 ,
struct V_75 * V_68 )
{
void * V_38 = V_192 ;
int V_119 = V_819 ;
while ( V_818 ) {
T_6 V_406 = V_2 -> V_5 . V_103 -> V_815 ( V_2 , V_386 , V_96 ,
V_68 ) ;
unsigned V_94 = V_386 & ( V_107 - 1 ) ;
unsigned V_820 = F_333 ( V_818 , ( unsigned ) V_107 - V_94 ) ;
int V_108 ;
if ( V_406 == V_100 )
return V_821 ;
V_108 = F_50 ( V_2 , V_406 >> V_106 , V_38 ,
V_94 , V_820 ) ;
if ( V_108 < 0 ) {
V_119 = V_822 ;
goto V_113;
}
V_818 -= V_820 ;
V_38 += V_820 ;
V_386 += V_820 ;
}
V_113:
return V_119 ;
}
static int F_348 ( struct V_823 * V_824 ,
T_16 V_386 , void * V_192 , unsigned int V_818 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_349 ( V_824 ) ;
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
unsigned V_94 ;
int V_108 ;
T_6 V_406 = V_2 -> V_5 . V_103 -> V_815 ( V_2 , V_386 , V_96 | V_817 ,
V_68 ) ;
if ( F_155 ( V_406 == V_100 ) )
return V_821 ;
V_94 = V_386 & ( V_107 - 1 ) ;
if ( F_29 ( V_94 + V_818 > V_107 ) )
V_818 = ( unsigned ) V_107 - V_94 ;
V_108 = F_50 ( V_2 , V_406 >> V_106 , V_192 ,
V_94 , V_818 ) ;
if ( F_155 ( V_108 < 0 ) )
return V_822 ;
return V_819 ;
}
int F_350 ( struct V_823 * V_824 ,
T_16 V_386 , void * V_192 , unsigned int V_818 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_349 ( V_824 ) ;
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
return F_347 ( V_386 , V_192 , V_818 , V_2 , V_96 ,
V_68 ) ;
}
static int F_351 ( struct V_823 * V_824 ,
T_16 V_386 , void * V_192 , unsigned int V_818 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_349 ( V_824 ) ;
return F_347 ( V_386 , V_192 , V_818 , V_2 , 0 , V_68 ) ;
}
int F_352 ( struct V_823 * V_824 ,
T_16 V_386 , void * V_192 ,
unsigned int V_818 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_349 ( V_824 ) ;
void * V_38 = V_192 ;
int V_119 = V_819 ;
while ( V_818 ) {
T_6 V_406 = V_2 -> V_5 . V_103 -> V_815 ( V_2 , V_386 ,
V_112 ,
V_68 ) ;
unsigned V_94 = V_386 & ( V_107 - 1 ) ;
unsigned V_825 = F_333 ( V_818 , ( unsigned ) V_107 - V_94 ) ;
int V_108 ;
if ( V_406 == V_100 )
return V_821 ;
V_108 = F_188 ( V_2 , V_406 , V_38 , V_825 ) ;
if ( V_108 < 0 ) {
V_119 = V_822 ;
goto V_113;
}
V_818 -= V_825 ;
V_38 += V_825 ;
V_386 += V_825 ;
}
V_113:
return V_119 ;
}
static int F_353 ( struct V_1 * V_2 , unsigned long V_816 ,
T_6 * V_406 , struct V_75 * V_68 ,
bool V_826 )
{
T_1 V_96 = ( ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 )
| ( V_826 ? V_112 : 0 ) ;
if ( F_354 ( V_2 , V_816 )
&& ! F_355 ( V_2 , V_2 -> V_5 . V_103 ,
V_2 -> V_5 . V_96 , V_96 ) ) {
* V_406 = V_2 -> V_5 . V_827 << V_106 |
( V_816 & ( V_107 - 1 ) ) ;
F_356 ( V_816 , * V_406 , V_826 , false ) ;
return 1 ;
}
* V_406 = V_2 -> V_5 . V_103 -> V_815 ( V_2 , V_816 , V_96 , V_68 ) ;
if ( * V_406 == V_100 )
return - 1 ;
if ( ( * V_406 & V_373 ) == V_828 )
return 1 ;
if ( F_357 ( V_2 , * V_406 ) ) {
F_356 ( V_816 , * V_406 , V_826 , true ) ;
return 1 ;
}
return 0 ;
}
int F_358 ( struct V_1 * V_2 , T_6 V_406 ,
const void * V_192 , int V_818 )
{
int V_108 ;
V_108 = F_188 ( V_2 , V_406 , V_192 , V_818 ) ;
if ( V_108 < 0 )
return 0 ;
F_359 ( V_2 , V_406 , V_192 , V_818 ) ;
return 1 ;
}
static int F_360 ( struct V_1 * V_2 , void * V_192 , int V_818 )
{
if ( V_2 -> V_829 ) {
F_339 ( V_808 , V_818 ,
V_2 -> V_830 [ 0 ] . V_406 , * ( T_2 * ) V_192 ) ;
V_2 -> V_829 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_361 ( struct V_1 * V_2 , T_6 V_406 ,
void * V_192 , int V_818 )
{
return ! F_362 ( V_2 , V_406 , V_192 , V_818 ) ;
}
static int F_363 ( struct V_1 * V_2 , T_6 V_406 ,
void * V_192 , int V_818 )
{
return F_358 ( V_2 , V_406 , V_192 , V_818 ) ;
}
static int F_364 ( struct V_1 * V_2 , T_6 V_406 , int V_818 , void * V_192 )
{
F_339 ( V_831 , V_818 , V_406 , * ( T_2 * ) V_192 ) ;
return F_332 ( V_2 , V_406 , V_818 , V_192 ) ;
}
static int F_365 ( struct V_1 * V_2 , T_6 V_406 ,
void * V_192 , int V_818 )
{
F_339 ( V_832 , V_818 , V_406 , 0 ) ;
return V_822 ;
}
static int F_366 ( struct V_1 * V_2 , T_6 V_406 ,
void * V_192 , int V_818 )
{
struct V_833 * V_834 = & V_2 -> V_830 [ 0 ] ;
memcpy ( V_2 -> V_835 -> V_836 . V_38 , V_834 -> V_38 , F_333 ( 8u , V_834 -> V_95 ) ) ;
return V_819 ;
}
static int F_367 ( unsigned long V_386 , void * V_192 ,
unsigned int V_818 ,
struct V_75 * V_68 ,
struct V_1 * V_2 ,
const struct V_837 * V_838 )
{
T_6 V_406 ;
int V_805 , V_108 ;
bool V_826 = V_838 -> V_826 ;
struct V_833 * V_834 ;
V_108 = F_353 ( V_2 , V_386 , & V_406 , V_68 , V_826 ) ;
if ( V_108 < 0 )
return V_821 ;
if ( V_108 )
goto V_836;
if ( V_838 -> V_839 ( V_2 , V_406 , V_192 , V_818 ) )
return V_819 ;
V_836:
V_805 = V_838 -> V_840 ( V_2 , V_406 , V_818 , V_192 ) ;
if ( V_805 == V_818 )
return V_819 ;
V_406 += V_805 ;
V_818 -= V_805 ;
V_192 += V_805 ;
F_29 ( V_2 -> V_841 >= V_842 ) ;
V_834 = & V_2 -> V_830 [ V_2 -> V_841 ++ ] ;
V_834 -> V_406 = V_406 ;
V_834 -> V_38 = V_192 ;
V_834 -> V_95 = V_818 ;
return V_819 ;
}
static int F_368 ( struct V_823 * V_824 ,
unsigned long V_386 ,
void * V_192 , unsigned int V_818 ,
struct V_75 * V_68 ,
const struct V_837 * V_838 )
{
struct V_1 * V_2 = F_349 ( V_824 ) ;
T_6 V_406 ;
int V_843 ;
if ( V_838 -> V_844 &&
V_838 -> V_844 ( V_2 , V_192 , V_818 ) )
return V_819 ;
V_2 -> V_841 = 0 ;
if ( ( ( V_386 + V_818 - 1 ) ^ V_386 ) & V_373 ) {
int V_845 ;
V_845 = - V_386 & ~ V_373 ;
V_843 = F_367 ( V_386 , V_192 , V_845 , V_68 ,
V_2 , V_838 ) ;
if ( V_843 != V_819 )
return V_843 ;
V_386 += V_845 ;
if ( V_824 -> V_317 != V_846 )
V_386 = ( T_1 ) V_386 ;
V_192 += V_845 ;
V_818 -= V_845 ;
}
V_843 = F_367 ( V_386 , V_192 , V_818 , V_68 ,
V_2 , V_838 ) ;
if ( V_843 != V_819 )
return V_843 ;
if ( ! V_2 -> V_841 )
return V_843 ;
V_406 = V_2 -> V_830 [ 0 ] . V_406 ;
V_2 -> V_847 = 1 ;
V_2 -> V_848 = 0 ;
V_2 -> V_835 -> V_836 . V_95 = F_333 ( 8u , V_2 -> V_830 [ 0 ] . V_95 ) ;
V_2 -> V_835 -> V_836 . V_849 = V_2 -> V_850 = V_838 -> V_826 ;
V_2 -> V_835 -> V_851 = V_852 ;
V_2 -> V_835 -> V_836 . V_853 = V_406 ;
return V_838 -> V_854 ( V_2 , V_406 , V_192 , V_818 ) ;
}
static int F_369 ( struct V_823 * V_824 ,
unsigned long V_386 ,
void * V_192 ,
unsigned int V_818 ,
struct V_75 * V_68 )
{
return F_368 ( V_824 , V_386 , V_192 , V_818 ,
V_68 , & V_855 ) ;
}
static int F_370 ( struct V_823 * V_824 ,
unsigned long V_386 ,
const void * V_192 ,
unsigned int V_818 ,
struct V_75 * V_68 )
{
return F_368 ( V_824 , V_386 , ( void * ) V_192 , V_818 ,
V_68 , & V_856 ) ;
}
static int F_371 ( struct V_823 * V_824 ,
unsigned long V_386 ,
const void * V_857 ,
const void * V_858 ,
unsigned int V_818 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_349 ( V_824 ) ;
T_6 V_406 ;
struct V_375 * V_375 ;
char * V_859 ;
bool V_860 ;
if ( V_818 > 8 || ( V_818 & ( V_818 - 1 ) ) )
goto V_861;
V_406 = F_345 ( V_2 , V_386 , NULL ) ;
if ( V_406 == V_100 ||
( V_406 & V_373 ) == V_828 )
goto V_861;
if ( ( ( V_406 + V_818 - 1 ) & V_373 ) != ( V_406 & V_373 ) )
goto V_861;
V_375 = F_372 ( V_2 , V_406 >> V_106 ) ;
if ( F_373 ( V_375 ) )
goto V_861;
V_859 = F_374 ( V_375 ) ;
V_859 += F_375 ( V_406 ) ;
switch ( V_818 ) {
case 1 :
V_860 = F_376 ( T_14 , V_859 , V_857 , V_858 ) ;
break;
case 2 :
V_860 = F_376 ( V_862 , V_859 , V_857 , V_858 ) ;
break;
case 4 :
V_860 = F_376 ( T_1 , V_859 , V_857 , V_858 ) ;
break;
case 8 :
V_860 = F_377 ( V_859 , V_857 , V_858 ) ;
break;
default:
F_26 () ;
}
F_378 ( V_859 ) ;
F_379 ( V_375 ) ;
if ( ! V_860 )
return V_863 ;
F_202 ( V_2 , V_406 >> V_106 ) ;
F_359 ( V_2 , V_406 , V_858 , V_818 ) ;
return V_819 ;
V_861:
F_380 ( V_864 L_21 ) ;
return F_370 ( V_824 , V_386 , V_858 , V_818 , V_68 ) ;
}
static int F_381 ( struct V_1 * V_2 , void * V_865 )
{
int V_119 ;
if ( V_2 -> V_5 . V_866 . V_867 )
V_119 = F_338 ( V_2 , V_774 , V_2 -> V_5 . V_866 . V_868 ,
V_2 -> V_5 . V_866 . V_501 , V_865 ) ;
else
V_119 = F_335 ( V_2 , V_774 ,
V_2 -> V_5 . V_866 . V_868 , V_2 -> V_5 . V_866 . V_501 ,
V_865 ) ;
return V_119 ;
}
static int F_382 ( struct V_1 * V_2 , int V_501 ,
unsigned short V_868 , void * V_192 ,
unsigned int V_741 , bool V_867 )
{
V_2 -> V_5 . V_866 . V_868 = V_868 ;
V_2 -> V_5 . V_866 . V_867 = V_867 ;
V_2 -> V_5 . V_866 . V_741 = V_741 ;
V_2 -> V_5 . V_866 . V_501 = V_501 ;
if ( ! F_381 ( V_2 , V_2 -> V_5 . V_869 ) ) {
V_2 -> V_5 . V_866 . V_741 = 0 ;
return 1 ;
}
V_2 -> V_835 -> V_851 = V_870 ;
V_2 -> V_835 -> V_871 . V_872 = V_867 ? V_873 : V_874 ;
V_2 -> V_835 -> V_871 . V_501 = V_501 ;
V_2 -> V_835 -> V_871 . V_875 = V_876 * V_107 ;
V_2 -> V_835 -> V_871 . V_741 = V_741 ;
V_2 -> V_835 -> V_871 . V_868 = V_868 ;
return 0 ;
}
static int F_383 ( struct V_823 * V_824 ,
int V_501 , unsigned short V_868 , void * V_192 ,
unsigned int V_741 )
{
struct V_1 * V_2 = F_349 ( V_824 ) ;
int V_108 ;
if ( V_2 -> V_5 . V_866 . V_741 )
goto V_877;
V_108 = F_382 ( V_2 , V_501 , V_868 , V_192 , V_741 , true ) ;
if ( V_108 ) {
V_877:
memcpy ( V_192 , V_2 -> V_5 . V_869 , V_501 * V_741 ) ;
F_384 ( V_878 , V_868 , V_501 , V_741 , V_2 -> V_5 . V_869 ) ;
V_2 -> V_5 . V_866 . V_741 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_385 ( struct V_823 * V_824 ,
int V_501 , unsigned short V_868 ,
const void * V_192 , unsigned int V_741 )
{
struct V_1 * V_2 = F_349 ( V_824 ) ;
memcpy ( V_2 -> V_5 . V_869 , V_192 , V_501 * V_741 ) ;
F_384 ( V_879 , V_868 , V_501 , V_741 , V_2 -> V_5 . V_869 ) ;
return F_382 ( V_2 , V_501 , V_868 , ( void * ) V_192 , V_741 , false ) ;
}
static unsigned long F_386 ( struct V_1 * V_2 , int V_811 )
{
return V_73 -> F_386 ( V_2 , V_811 ) ;
}
static void F_387 ( struct V_823 * V_824 , V_172 V_80 )
{
F_388 ( F_349 ( V_824 ) , V_80 ) ;
}
int F_389 ( struct V_1 * V_2 )
{
if ( ! F_247 ( V_2 ) )
return V_819 ;
if ( V_73 -> V_588 () ) {
int V_23 = F_390 () ;
F_250 ( V_23 , V_2 -> V_5 . V_589 ) ;
F_391 ( V_2 -> V_5 . V_589 ,
F_245 , NULL , 1 ) ;
F_392 () ;
F_393 ( V_2 -> V_5 . V_589 ) ;
} else
F_246 () ;
return V_819 ;
}
int F_394 ( struct V_1 * V_2 )
{
V_73 -> V_74 ( V_2 ) ;
return F_389 ( V_2 ) ;
}
static void F_395 ( struct V_823 * V_824 )
{
F_389 ( F_349 ( V_824 ) ) ;
}
static int F_396 ( struct V_823 * V_824 , int V_89 ,
unsigned long * V_652 )
{
return F_98 ( F_349 ( V_824 ) , V_89 , V_652 ) ;
}
static int F_397 ( struct V_823 * V_824 , int V_89 ,
unsigned long V_22 )
{
return F_96 ( F_349 ( V_824 ) , V_89 , V_22 ) ;
}
static T_2 F_398 ( T_2 V_880 , T_1 V_881 )
{
return ( V_880 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_881 ;
}
static unsigned long F_399 ( struct V_823 * V_824 , int V_882 )
{
struct V_1 * V_2 = F_349 ( V_824 ) ;
unsigned long V_22 ;
switch ( V_882 ) {
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
V_22 = F_77 ( V_2 ) ;
break;
case 8 :
V_22 = F_89 ( V_2 ) ;
break;
default:
F_400 ( L_22 , V_260 , V_882 ) ;
return 0 ;
}
return V_22 ;
}
static int F_401 ( struct V_823 * V_824 , int V_882 , V_172 V_192 )
{
struct V_1 * V_2 = F_349 ( V_824 ) ;
int V_883 = 0 ;
switch ( V_882 ) {
case 0 :
V_883 = F_61 ( V_2 , F_398 ( F_62 ( V_2 ) , V_192 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_79 = V_192 ;
break;
case 3 :
V_883 = F_83 ( V_2 , V_192 ) ;
break;
case 4 :
V_883 = F_76 ( V_2 , F_398 ( F_77 ( V_2 ) , V_192 ) ) ;
break;
case 8 :
V_883 = F_86 ( V_2 , V_192 ) ;
break;
default:
F_400 ( L_22 , V_260 , V_882 ) ;
V_883 = - 1 ;
}
return V_883 ;
}
static int F_402 ( struct V_823 * V_824 )
{
return V_73 -> V_88 ( F_349 ( V_824 ) ) ;
}
static void F_403 ( struct V_823 * V_824 , struct V_884 * V_885 )
{
V_73 -> V_886 ( F_349 ( V_824 ) , V_885 ) ;
}
static void F_404 ( struct V_823 * V_824 , struct V_884 * V_885 )
{
V_73 -> V_887 ( F_349 ( V_824 ) , V_885 ) ;
}
static void F_405 ( struct V_823 * V_824 , struct V_884 * V_885 )
{
V_73 -> V_888 ( F_349 ( V_824 ) , V_885 ) ;
}
static void F_406 ( struct V_823 * V_824 , struct V_884 * V_885 )
{
V_73 -> V_889 ( F_349 ( V_824 ) , V_885 ) ;
}
static unsigned long F_407 (
struct V_823 * V_824 , int V_811 )
{
return F_386 ( F_349 ( V_824 ) , V_811 ) ;
}
static bool F_408 ( struct V_823 * V_824 , V_862 * V_890 ,
struct V_891 * V_892 , T_1 * V_893 ,
int V_811 )
{
struct V_809 V_810 ;
F_341 ( F_349 ( V_824 ) , & V_810 , V_811 ) ;
* V_890 = V_810 . V_890 ;
if ( V_810 . V_894 ) {
memset ( V_892 , 0 , sizeof( * V_892 ) ) ;
return false ;
}
if ( V_810 . V_895 )
V_810 . V_896 >>= 12 ;
F_409 ( V_892 , V_810 . V_896 ) ;
F_410 ( V_892 , ( unsigned long ) V_810 . V_226 ) ;
#ifdef F_63
if ( V_893 )
* V_893 = V_810 . V_226 >> 32 ;
#endif
V_892 -> type = V_810 . type ;
V_892 -> V_596 = V_810 . V_596 ;
V_892 -> V_897 = V_810 . V_897 ;
V_892 -> V_898 = V_810 . V_899 ;
V_892 -> V_900 = V_810 . V_900 ;
V_892 -> V_901 = V_810 . V_901 ;
V_892 -> V_902 = V_810 . V_179 ;
V_892 -> V_895 = V_810 . V_895 ;
return true ;
}
static void F_411 ( struct V_823 * V_824 , V_862 V_890 ,
struct V_891 * V_892 , T_1 V_893 ,
int V_811 )
{
struct V_1 * V_2 = F_349 ( V_824 ) ;
struct V_809 V_810 ;
V_810 . V_890 = V_890 ;
V_810 . V_226 = F_412 ( V_892 ) ;
#ifdef F_63
V_810 . V_226 |= ( ( T_2 ) V_893 ) << 32 ;
#endif
V_810 . V_896 = F_413 ( V_892 ) ;
if ( V_892 -> V_895 )
V_810 . V_896 = ( V_810 . V_896 << 12 ) | 0xfff ;
V_810 . type = V_892 -> type ;
V_810 . V_897 = V_892 -> V_897 ;
V_810 . V_179 = V_892 -> V_902 ;
V_810 . V_596 = V_892 -> V_596 ;
V_810 . V_901 = V_892 -> V_901 ;
V_810 . V_895 = V_892 -> V_895 ;
V_810 . V_900 = V_892 -> V_900 ;
V_810 . V_899 = V_892 -> V_898 ;
V_810 . V_894 = ! V_810 . V_899 ;
V_810 . V_903 = 0 ;
F_340 ( V_2 , & V_810 , V_811 ) ;
return;
}
static int F_414 ( struct V_823 * V_824 ,
T_1 V_904 , T_2 * V_475 )
{
struct V_32 V_21 ;
int V_119 ;
V_21 . V_144 = V_904 ;
V_21 . V_40 = false ;
V_119 = F_112 ( F_349 ( V_824 ) , & V_21 ) ;
if ( V_119 )
return V_119 ;
* V_475 = V_21 . V_38 ;
return 0 ;
}
static int F_415 ( struct V_823 * V_824 ,
T_1 V_904 , T_2 V_38 )
{
struct V_32 V_21 ;
V_21 . V_38 = V_38 ;
V_21 . V_144 = V_904 ;
V_21 . V_40 = false ;
return F_108 ( F_349 ( V_824 ) , & V_21 ) ;
}
static T_2 F_416 ( struct V_823 * V_824 )
{
struct V_1 * V_2 = F_349 ( V_824 ) ;
return V_2 -> V_5 . V_441 ;
}
static void F_417 ( struct V_823 * V_824 , T_2 V_441 )
{
struct V_1 * V_2 = F_349 ( V_824 ) ;
V_2 -> V_5 . V_441 = V_441 ;
}
static int F_418 ( struct V_823 * V_824 ,
T_1 V_905 )
{
return F_419 ( F_349 ( V_824 ) , V_905 ) ;
}
static int F_420 ( struct V_823 * V_824 ,
T_1 V_905 , T_2 * V_475 )
{
return F_101 ( F_349 ( V_824 ) , V_905 , V_475 ) ;
}
static void F_421 ( struct V_823 * V_824 )
{
F_349 ( V_824 ) -> V_5 . V_906 = 1 ;
}
static void F_422 ( struct V_823 * V_824 )
{
F_216 () ;
F_423 ( F_349 ( V_824 ) ) ;
F_424 () ;
}
static void F_425 ( struct V_823 * V_824 )
{
F_217 () ;
}
static int F_426 ( struct V_823 * V_824 ,
struct V_907 * V_908 ,
enum V_909 V_910 )
{
return V_73 -> V_911 ( F_349 ( V_824 ) , V_908 , V_910 ) ;
}
static void F_427 ( struct V_823 * V_824 ,
T_1 * V_912 , T_1 * V_913 , T_1 * V_197 , T_1 * V_205 )
{
V_690 ( F_349 ( V_824 ) , V_912 , V_913 , V_197 , V_205 ) ;
}
static V_172 F_428 ( struct V_823 * V_824 , unsigned V_914 )
{
return F_100 ( F_349 ( V_824 ) , V_914 ) ;
}
static void F_429 ( struct V_823 * V_824 , unsigned V_914 , V_172 V_192 )
{
F_102 ( F_349 ( V_824 ) , V_914 , V_192 ) ;
}
static void F_430 ( struct V_823 * V_824 , bool V_630 )
{
V_73 -> V_646 ( F_349 ( V_824 ) , V_630 ) ;
}
static void F_431 ( struct V_1 * V_2 , T_1 V_28 )
{
T_1 V_915 = V_73 -> V_626 ( V_2 ) ;
if ( V_915 & V_28 )
V_28 = 0 ;
if ( F_155 ( V_915 || V_28 ) ) {
V_73 -> V_645 ( V_2 , V_28 ) ;
if ( ! V_28 )
F_31 ( V_67 , V_2 ) ;
}
}
static bool F_432 ( struct V_1 * V_2 )
{
struct V_823 * V_824 = & V_2 -> V_5 . V_916 ;
if ( V_824 -> V_68 . V_41 == V_42 )
return F_39 ( V_2 , & V_824 -> V_68 ) ;
if ( V_824 -> V_68 . V_917 )
F_38 ( V_2 , V_824 -> V_68 . V_41 ,
V_824 -> V_68 . V_62 ) ;
else
F_33 ( V_2 , V_824 -> V_68 . V_41 ) ;
return false ;
}
static void F_433 ( struct V_1 * V_2 )
{
struct V_823 * V_824 = & V_2 -> V_5 . V_916 ;
int V_132 , V_133 ;
V_73 -> V_134 ( V_2 , & V_132 , & V_133 ) ;
V_824 -> V_918 = F_434 ( V_2 ) ;
V_824 -> V_919 = F_435 ( V_2 ) ;
V_824 -> V_317 = ( ! F_32 ( V_2 ) ) ? V_920 :
( V_824 -> V_918 & V_921 ) ? V_922 :
( V_133 && F_57 ( V_2 ) ) ? V_846 :
V_132 ? V_923 :
V_924 ;
F_172 ( V_925 != V_926 ) ;
F_172 ( V_647 != V_927 ) ;
F_172 ( V_638 != V_928 ) ;
V_824 -> V_929 = V_2 -> V_5 . V_637 ;
F_436 ( V_824 ) ;
V_2 -> V_5 . V_930 = false ;
}
int F_437 ( struct V_1 * V_2 , int V_601 , int V_931 )
{
struct V_823 * V_824 = & V_2 -> V_5 . V_916 ;
int V_108 ;
F_433 ( V_2 ) ;
V_824 -> V_932 = 2 ;
V_824 -> V_933 = 2 ;
V_824 -> V_934 = V_824 -> V_919 + V_931 ;
V_108 = F_438 ( V_824 , V_601 ) ;
if ( V_108 != V_819 )
return V_935 ;
V_824 -> V_919 = V_824 -> V_934 ;
F_439 ( V_2 , V_824 -> V_919 ) ;
F_440 ( V_2 , V_824 -> V_918 ) ;
if ( V_601 == V_51 )
V_2 -> V_5 . V_629 = 0 ;
else
V_2 -> V_5 . V_623 . V_69 = false ;
return V_936 ;
}
static int F_441 ( struct V_1 * V_2 )
{
int V_119 = V_936 ;
++ V_2 -> V_77 . V_937 ;
F_442 ( V_2 ) ;
if ( ! F_443 ( V_2 ) && V_73 -> V_88 ( V_2 ) == 0 ) {
V_2 -> V_835 -> V_851 = V_938 ;
V_2 -> V_835 -> V_939 . V_940 = V_941 ;
V_2 -> V_835 -> V_939 . V_942 = 0 ;
V_119 = V_935 ;
}
F_33 ( V_2 , V_91 ) ;
return V_119 ;
}
static bool F_444 ( struct V_1 * V_2 , T_16 V_79 ,
bool V_943 ,
int V_944 )
{
T_6 V_406 = V_79 ;
T_17 V_945 ;
if ( V_944 & V_946 )
return false ;
if ( ! V_2 -> V_5 . V_84 . V_947 ) {
V_406 = F_345 ( V_2 , V_79 , NULL ) ;
if ( V_406 == V_100 )
return true ;
}
V_945 = F_445 ( V_2 -> V_137 , F_49 ( V_406 ) ) ;
if ( F_446 ( V_945 ) )
return false ;
F_447 ( V_945 ) ;
if ( V_2 -> V_5 . V_84 . V_947 ) {
unsigned int V_948 ;
F_146 ( & V_2 -> V_137 -> V_949 ) ;
V_948 = V_2 -> V_137 -> V_5 . V_948 ;
F_147 ( & V_2 -> V_137 -> V_949 ) ;
if ( V_948 )
F_448 ( V_2 -> V_137 , F_49 ( V_406 ) ) ;
return true ;
}
F_448 ( V_2 -> V_137 , F_49 ( V_406 ) ) ;
return ! V_943 ;
}
static bool F_449 ( struct V_823 * V_824 ,
unsigned long V_79 , int V_944 )
{
struct V_1 * V_2 = F_349 ( V_824 ) ;
unsigned long V_950 , V_951 , V_406 = V_79 ;
V_950 = V_2 -> V_5 . V_950 ;
V_951 = V_2 -> V_5 . V_951 ;
V_2 -> V_5 . V_950 = V_2 -> V_5 . V_951 = 0 ;
if ( ! ( V_944 & V_952 ) )
return false ;
if ( F_450 ( V_824 ) )
return false ;
if ( V_824 -> V_919 == V_950 && V_951 == V_79 )
return false ;
V_2 -> V_5 . V_950 = V_824 -> V_919 ;
V_2 -> V_5 . V_951 = V_79 ;
if ( ! V_2 -> V_5 . V_84 . V_947 )
V_406 = F_345 ( V_2 , V_79 , NULL ) ;
F_448 ( V_2 -> V_137 , F_49 ( V_406 ) ) ;
return true ;
}
static void F_451 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_637 & V_647 ) ) {
F_452 ( V_2 -> V_288 , V_2 -> V_5 . V_441 , false ) ;
if ( F_155 ( V_2 -> V_5 . V_635 ) ) {
F_31 ( V_604 , V_2 ) ;
V_2 -> V_5 . V_635 = 0 ;
} else {
F_31 ( V_67 , V_2 ) ;
}
}
F_66 ( V_2 ) ;
}
static void F_453 ( struct V_1 * V_2 , unsigned V_929 )
{
unsigned V_118 = V_2 -> V_5 . V_637 ^ V_929 ;
V_2 -> V_5 . V_637 = V_929 ;
if ( V_118 & V_647 )
F_451 ( V_2 ) ;
}
static int F_454 ( unsigned long V_386 , T_1 type , T_1 V_184 ,
unsigned long * V_179 )
{
T_1 V_183 = 0 ;
int V_3 ;
T_1 V_953 , V_954 ;
V_953 = V_184 ;
V_954 = V_184 >> 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ , V_953 >>= 2 , V_954 >>= 4 )
if ( ( V_953 & 3 ) && ( V_954 & 15 ) == type && V_179 [ V_3 ] == V_386 )
V_183 |= ( 1 << V_3 ) ;
return V_183 ;
}
static void F_455 ( struct V_1 * V_2 , unsigned long V_955 , int * V_119 )
{
struct V_956 * V_956 = V_2 -> V_835 ;
if ( F_155 ( V_955 & V_957 ) ) {
if ( V_2 -> V_175 & V_958 ) {
V_956 -> V_959 . V_5 . V_183 = V_960 | V_190 |
V_191 ;
V_956 -> V_959 . V_5 . V_961 = V_2 -> V_5 . V_962 ;
V_956 -> V_959 . V_5 . V_68 = V_53 ;
V_956 -> V_851 = V_963 ;
* V_119 = V_964 ;
} else {
V_2 -> V_5 . V_916 . V_918 &= ~ V_957 ;
V_2 -> V_5 . V_183 &= ~ 15 ;
V_2 -> V_5 . V_183 |= V_960 | V_191 ;
F_33 ( V_2 , V_53 ) ;
}
}
}
static bool F_456 ( struct V_1 * V_2 , int * V_119 )
{
if ( F_155 ( V_2 -> V_175 & V_176 ) &&
( V_2 -> V_5 . V_185 & V_188 ) ) {
struct V_956 * V_956 = V_2 -> V_835 ;
unsigned long V_919 = F_457 ( V_2 ) ;
T_1 V_183 = F_454 ( V_919 , 0 ,
V_2 -> V_5 . V_185 ,
V_2 -> V_5 . V_178 ) ;
if ( V_183 != 0 ) {
V_956 -> V_959 . V_5 . V_183 = V_183 | V_190 | V_191 ;
V_956 -> V_959 . V_5 . V_961 = V_919 ;
V_956 -> V_959 . V_5 . V_68 = V_53 ;
V_956 -> V_851 = V_963 ;
* V_119 = V_964 ;
return true ;
}
}
if ( F_155 ( V_2 -> V_5 . V_184 & V_188 ) &&
! ( F_434 ( V_2 ) & V_965 ) ) {
unsigned long V_919 = F_457 ( V_2 ) ;
T_1 V_183 = F_454 ( V_919 , 0 ,
V_2 -> V_5 . V_184 ,
V_2 -> V_5 . V_179 ) ;
if ( V_183 != 0 ) {
V_2 -> V_5 . V_183 &= ~ 15 ;
V_2 -> V_5 . V_183 |= V_183 | V_191 ;
F_33 ( V_2 , V_53 ) ;
* V_119 = V_936 ;
return true ;
}
}
return false ;
}
int F_458 ( struct V_1 * V_2 ,
unsigned long V_79 ,
int V_944 ,
void * V_966 ,
int V_967 )
{
int V_119 ;
struct V_823 * V_824 = & V_2 -> V_5 . V_916 ;
bool V_499 = true ;
bool V_968 = V_2 -> V_5 . V_943 ;
V_2 -> V_5 . V_943 = false ;
F_459 ( V_2 ) ;
if ( ! ( V_944 & V_969 ) ) {
F_433 ( V_2 ) ;
if ( F_456 ( V_2 , & V_119 ) )
return V_119 ;
V_824 -> V_970 = 0 ;
V_824 -> V_971 = false ;
V_824 -> V_68 . V_41 = - 1 ;
V_824 -> V_972 = false ;
V_824 -> V_973 = V_944 & V_974 ;
V_119 = F_460 ( V_824 , V_966 , V_967 ) ;
F_461 ( V_2 ) ;
++ V_2 -> V_77 . V_975 ;
if ( V_119 != V_976 ) {
if ( V_944 & V_974 )
return V_935 ;
if ( F_444 ( V_2 , V_79 , V_968 ,
V_944 ) )
return V_936 ;
if ( V_944 & V_977 )
return V_935 ;
return F_441 ( V_2 ) ;
}
}
if ( V_944 & V_977 ) {
F_439 ( V_2 , V_824 -> V_934 ) ;
if ( V_824 -> V_918 & V_965 )
F_440 ( V_2 , V_824 -> V_918 & ~ V_965 ) ;
return V_936 ;
}
if ( F_449 ( V_824 , V_79 , V_944 ) )
return V_936 ;
if ( V_2 -> V_5 . V_930 ) {
V_2 -> V_5 . V_930 = false ;
F_462 ( V_824 ) ;
}
V_978:
V_119 = F_463 ( V_824 ) ;
if ( V_119 == V_979 )
return V_936 ;
if ( V_119 == V_980 ) {
if ( F_444 ( V_2 , V_79 , V_968 ,
V_944 ) )
return V_936 ;
return F_441 ( V_2 ) ;
}
if ( V_824 -> V_971 ) {
V_119 = V_936 ;
if ( F_432 ( V_2 ) )
return V_119 ;
} else if ( V_2 -> V_5 . V_866 . V_741 ) {
if ( ! V_2 -> V_5 . V_866 . V_867 ) {
V_2 -> V_5 . V_866 . V_741 = 0 ;
} else {
V_499 = false ;
V_2 -> V_5 . V_981 = V_982 ;
}
V_119 = V_964 ;
} else if ( V_2 -> V_847 ) {
if ( ! V_2 -> V_850 )
V_499 = false ;
V_119 = V_964 ;
V_2 -> V_5 . V_981 = V_983 ;
} else if ( V_119 == V_984 )
goto V_978;
else
V_119 = V_936 ;
if ( V_499 ) {
unsigned long V_955 = V_73 -> V_985 ( V_2 ) ;
F_431 ( V_2 , V_824 -> V_970 ) ;
V_2 -> V_5 . V_986 = false ;
if ( V_2 -> V_5 . V_637 != V_824 -> V_929 )
F_453 ( V_2 , V_824 -> V_929 ) ;
F_439 ( V_2 , V_824 -> V_919 ) ;
if ( V_119 == V_936 )
F_455 ( V_2 , V_955 , & V_119 ) ;
if ( ! V_824 -> V_971 ||
F_28 ( V_824 -> V_68 . V_41 ) == V_56 )
F_464 ( V_2 , V_824 -> V_918 ) ;
if ( F_155 ( ( V_824 -> V_918 & ~ V_955 ) & V_987 ) )
F_31 ( V_67 , V_2 ) ;
} else
V_2 -> V_5 . V_986 = true ;
return V_119 ;
}
int F_465 ( struct V_1 * V_2 , int V_501 , unsigned short V_868 )
{
unsigned long V_192 = F_100 ( V_2 , V_199 ) ;
int V_108 = F_385 ( & V_2 -> V_5 . V_916 ,
V_501 , V_868 , & V_192 , 1 ) ;
V_2 -> V_5 . V_866 . V_741 = 0 ;
return V_108 ;
}
static void F_466 ( void * V_908 )
{
F_467 ( V_333 , 0 ) ;
}
static void F_468 ( void * V_38 )
{
struct V_988 * V_989 = V_38 ;
unsigned long V_263 = 0 ;
if ( V_38 )
V_263 = V_989 -> V_858 ;
else if ( ! F_469 ( V_990 ) )
V_263 = F_470 ( F_471 () ) ;
if ( ! V_263 )
V_263 = V_272 ;
F_467 ( V_333 , V_263 ) ;
}
static int F_472 ( struct V_991 * V_992 , unsigned long V_192 ,
void * V_38 )
{
struct V_988 * V_989 = V_38 ;
struct V_137 * V_137 ;
struct V_1 * V_2 ;
int V_3 , V_993 = 0 ;
if ( V_192 == V_994 && V_989 -> V_857 > V_989 -> V_858 )
return 0 ;
if ( V_192 == V_995 && V_989 -> V_857 < V_989 -> V_858 )
return 0 ;
F_251 ( V_989 -> V_23 , F_468 , V_989 , 1 ) ;
F_146 ( & V_996 ) ;
F_473 (kvm, &vm_list, vm_list) {
F_163 (i, vcpu, kvm) {
if ( V_2 -> V_23 != V_989 -> V_23 )
continue;
F_31 ( V_324 , V_2 ) ;
if ( V_2 -> V_23 != F_8 () )
V_993 = 1 ;
}
}
F_147 ( & V_996 ) ;
if ( V_989 -> V_857 < V_989 -> V_858 && V_993 ) {
F_251 ( V_989 -> V_23 , F_468 , V_989 , 1 ) ;
}
return 0 ;
}
static int F_474 ( struct V_991 * V_997 ,
unsigned long V_998 , void * V_999 )
{
unsigned int V_23 = ( unsigned long ) V_999 ;
switch ( V_998 ) {
case V_1000 :
case V_1001 :
F_251 ( V_23 , F_468 , NULL , 1 ) ;
break;
case V_1002 :
F_251 ( V_23 , F_466 , NULL , 1 ) ;
break;
}
return V_1003 ;
}
static void F_475 ( void )
{
int V_23 ;
V_1004 = V_272 ;
F_476 () ;
if ( ! F_469 ( V_990 ) ) {
#ifdef F_477
struct V_1005 V_1006 ;
memset ( & V_1006 , 0 , sizeof( V_1006 ) ) ;
V_23 = F_390 () ;
F_478 ( & V_1006 , V_23 ) ;
if ( V_1006 . V_1007 . V_1008 )
V_1004 = V_1006 . V_1007 . V_1008 ;
F_392 () ;
#endif
F_479 ( & V_1009 ,
V_1010 ) ;
}
F_128 ( L_23 , V_1004 ) ;
F_480 (cpu)
F_251 ( V_23 , F_468 , NULL , 1 ) ;
F_481 ( & V_1011 ) ;
F_482 () ;
}
int F_483 ( void )
{
return F_167 ( V_1012 ) != NULL ;
}
static int F_484 ( void )
{
int V_1013 = 3 ;
if ( F_167 ( V_1012 ) )
V_1013 = V_73 -> V_88 ( F_167 ( V_1012 ) ) ;
return V_1013 != 0 ;
}
static unsigned long F_485 ( void )
{
unsigned long V_1014 = 0 ;
if ( F_167 ( V_1012 ) )
V_1014 = F_435 ( F_167 ( V_1012 ) ) ;
return V_1014 ;
}
void F_486 ( struct V_1 * V_2 )
{
F_467 ( V_1012 , V_2 ) ;
}
void F_487 ( struct V_1 * V_2 )
{
F_467 ( V_1012 , NULL ) ;
}
static void F_488 ( void )
{
T_2 V_28 ;
int V_1015 = V_1016 . V_1017 ;
V_28 = F_489 ( V_1015 , 51 ) ;
V_28 |= 0x3ull << 62 ;
V_28 |= 1ull ;
#ifdef F_63
if ( V_1015 == 52 )
V_28 &= ~ 1ull ;
#endif
F_490 ( V_28 ) ;
}
static void F_491 ( struct V_347 * V_348 )
{
struct V_137 * V_137 ;
struct V_1 * V_2 ;
int V_3 ;
F_146 ( & V_996 ) ;
F_473 (kvm, &vm_list, vm_list)
F_163 (i, vcpu, kvm)
F_31 ( V_287 , V_2 ) ;
F_159 ( & V_323 , 0 ) ;
F_147 ( & V_996 ) ;
}
static int F_492 ( struct V_991 * V_992 , unsigned long V_1018 ,
void * V_1019 )
{
struct V_222 * V_282 = & V_222 ;
struct V_220 * V_221 = V_1019 ;
F_114 ( V_221 ) ;
if ( V_282 -> clock . V_229 != V_286 &&
F_138 ( & V_323 ) != 0 )
F_493 ( V_1020 , & V_1021 ) ;
return 0 ;
}
int F_494 ( void * V_1022 )
{
int V_119 ;
struct V_73 * V_838 = V_1022 ;
if ( V_73 ) {
F_10 ( V_26 L_24 ) ;
V_119 = - V_772 ;
goto V_113;
}
if ( ! V_838 -> V_1023 () ) {
F_10 ( V_26 L_25 ) ;
V_119 = - V_1024 ;
goto V_113;
}
if ( V_838 -> V_1025 () ) {
F_10 ( V_26 L_26 ) ;
V_119 = - V_1024 ;
goto V_113;
}
V_119 = - V_377 ;
V_25 = F_495 ( struct V_11 ) ;
if ( ! V_25 ) {
F_10 ( V_26 L_27 ) ;
goto V_113;
}
V_119 = F_496 () ;
if ( V_119 )
goto V_1026;
F_488 () ;
V_73 = V_838 ;
F_497 ( V_1027 , V_1028 ,
V_1029 , V_1030 , 0 ) ;
F_475 () ;
F_498 ( & V_1031 ) ;
if ( V_561 )
V_143 = F_499 ( V_141 ) ;
F_500 () ;
#ifdef F_63
F_501 ( & V_1032 ) ;
#endif
return 0 ;
V_1026:
F_502 ( V_25 ) ;
V_113:
return V_119 ;
}
void F_503 ( void )
{
F_504 ( & V_1031 ) ;
if ( ! F_469 ( V_990 ) )
F_505 ( & V_1009 ,
V_1010 ) ;
F_506 ( & V_1011 ) ;
#ifdef F_63
F_507 ( & V_1032 ) ;
#endif
V_73 = NULL ;
F_508 () ;
F_502 ( V_25 ) ;
}
int F_509 ( struct V_1 * V_2 )
{
++ V_2 -> V_77 . V_1033 ;
if ( F_87 ( V_2 -> V_137 ) ) {
V_2 -> V_5 . V_1034 = V_1035 ;
return 1 ;
} else {
V_2 -> V_835 -> V_851 = V_1036 ;
return 0 ;
}
}
int F_510 ( struct V_1 * V_2 )
{
V_73 -> V_74 ( V_2 ) ;
return F_509 ( V_2 ) ;
}
int F_511 ( struct V_1 * V_2 )
{
T_2 V_1037 , V_1038 , V_1039 , V_108 ;
T_18 V_1040 , V_1041 , V_1042 , V_883 = V_1043 , V_1044 = 0 ;
bool V_1045 , V_1046 ;
if ( V_73 -> V_88 ( V_2 ) != 0 || ! F_32 ( V_2 ) ) {
F_33 ( V_2 , V_91 ) ;
return 0 ;
}
V_1046 = F_512 ( V_2 ) ;
if ( ! V_1046 ) {
V_1037 = ( ( T_2 ) F_100 ( V_2 , V_200 ) << 32 ) |
( F_100 ( V_2 , V_199 ) & 0xffffffff ) ;
V_1038 = ( ( T_2 ) F_100 ( V_2 , V_1047 ) << 32 ) |
( F_100 ( V_2 , V_198 ) & 0xffffffff ) ;
V_1039 = ( ( T_2 ) F_100 ( V_2 , V_1048 ) << 32 ) |
( F_100 ( V_2 , V_1049 ) & 0xffffffff ) ;
}
#ifdef F_63
else {
V_1037 = F_100 ( V_2 , V_198 ) ;
V_1038 = F_100 ( V_2 , V_200 ) ;
V_1039 = F_100 ( V_2 , V_1050 ) ;
}
#endif
V_1040 = V_1037 & 0xffff ;
V_1045 = ( V_1037 >> 16 ) & 0x1 ;
V_1042 = ( V_1037 >> 32 ) & 0xfff ;
V_1041 = ( V_1037 >> 48 ) & 0xfff ;
F_513 ( V_1040 , V_1045 , V_1042 , V_1041 , V_1038 , V_1039 ) ;
switch ( V_1040 ) {
case V_1051 :
F_514 ( V_2 ) ;
break;
default:
V_883 = V_1052 ;
break;
}
V_108 = V_883 | ( ( ( T_2 ) V_1044 & 0xfff ) << 32 ) ;
if ( V_1046 ) {
F_102 ( V_2 , V_199 , V_108 ) ;
} else {
F_102 ( V_2 , V_200 , V_108 >> 32 ) ;
F_102 ( V_2 , V_199 , V_108 & 0xffffffff ) ;
}
return 1 ;
}
static void F_515 ( struct V_137 * V_137 , unsigned long V_294 , int V_1053 )
{
struct V_1054 V_1055 ;
V_1055 . V_1056 = 0 ;
V_1055 . V_1057 = 0 ;
V_1055 . V_1058 = V_1053 ;
V_1055 . V_1059 = false ;
V_1055 . V_1060 = V_1061 ;
F_516 ( V_137 , NULL , & V_1055 , NULL ) ;
}
int F_517 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_1062 , V_1063 , V_1064 , V_1065 , V_108 ;
int V_1066 , V_119 = 1 ;
V_73 -> V_74 ( V_2 ) ;
if ( F_190 ( V_2 -> V_137 ) )
return F_511 ( V_2 ) ;
V_16 = F_100 ( V_2 , V_199 ) ;
V_1062 = F_100 ( V_2 , V_1047 ) ;
V_1063 = F_100 ( V_2 , V_198 ) ;
V_1064 = F_100 ( V_2 , V_200 ) ;
V_1065 = F_100 ( V_2 , V_1049 ) ;
F_518 ( V_16 , V_1062 , V_1063 , V_1064 , V_1065 ) ;
V_1066 = F_512 ( V_2 ) ;
if ( ! V_1066 ) {
V_16 &= 0xFFFFFFFF ;
V_1062 &= 0xFFFFFFFF ;
V_1063 &= 0xFFFFFFFF ;
V_1064 &= 0xFFFFFFFF ;
V_1065 &= 0xFFFFFFFF ;
}
if ( V_73 -> V_88 ( V_2 ) != 0 ) {
V_108 = - V_1067 ;
goto V_113;
}
switch ( V_16 ) {
case V_1068 :
V_108 = 0 ;
break;
case V_1069 :
F_515 ( V_2 -> V_137 , V_1062 , V_1063 ) ;
V_108 = 0 ;
break;
default:
V_108 = - V_1070 ;
break;
}
V_113:
if ( ! V_1066 )
V_108 = ( T_1 ) V_108 ;
F_102 ( V_2 , V_199 , V_108 ) ;
++ V_2 -> V_77 . V_1071 ;
return V_119 ;
}
static int F_519 ( struct V_823 * V_824 )
{
struct V_1 * V_2 = F_349 ( V_824 ) ;
char V_1072 [ 3 ] ;
unsigned long V_1073 = F_435 ( V_2 ) ;
V_73 -> V_389 ( V_2 , V_1072 ) ;
return F_370 ( V_824 , V_1073 , V_1072 , 3 , NULL ) ;
}
static int F_520 ( struct V_1 * V_2 )
{
return ( ! F_87 ( V_2 -> V_137 ) && ! F_521 ( V_2 ) &&
V_2 -> V_835 -> V_1074 &&
F_522 ( V_2 ) ) ;
}
static void F_523 ( struct V_1 * V_2 )
{
struct V_956 * V_956 = V_2 -> V_835 ;
V_956 -> V_1075 = ( F_434 ( V_2 ) & V_987 ) != 0 ;
V_956 -> V_294 = F_271 ( V_2 ) ? V_1076 : 0 ;
V_956 -> V_173 = F_89 ( V_2 ) ;
V_956 -> V_31 = F_20 ( V_2 ) ;
if ( F_87 ( V_2 -> V_137 ) )
V_956 -> V_1077 = 1 ;
else
V_956 -> V_1077 =
F_522 ( V_2 ) &&
! F_521 ( V_2 ) &&
! F_524 ( V_2 ) ;
}
static void F_260 ( struct V_1 * V_2 )
{
int V_1078 , V_1079 ;
if ( ! V_73 -> F_260 )
return;
if ( ! V_2 -> V_5 . V_599 )
return;
if ( ! V_2 -> V_5 . V_599 -> V_699 )
V_1078 = F_525 ( V_2 ) ;
else
V_1078 = - 1 ;
if ( V_1078 != - 1 )
V_1078 >>= 4 ;
V_1079 = F_90 ( V_2 ) ;
V_73 -> F_260 ( V_2 , V_1079 , V_1078 ) ;
}
static int F_526 ( struct V_1 * V_2 , bool V_1080 )
{
int V_119 ;
if ( V_2 -> V_5 . V_68 . V_69 ) {
F_527 ( V_2 -> V_5 . V_68 . V_16 ,
V_2 -> V_5 . V_68 . V_71 ,
V_2 -> V_5 . V_68 . V_62 ) ;
if ( F_28 ( V_2 -> V_5 . V_68 . V_16 ) == V_60 )
F_464 ( V_2 , F_434 ( V_2 ) |
V_965 ) ;
if ( V_2 -> V_5 . V_68 . V_16 == V_53 &&
( V_2 -> V_5 . V_184 & V_1081 ) ) {
V_2 -> V_5 . V_184 &= ~ V_1081 ;
F_93 ( V_2 ) ;
}
V_73 -> V_1082 ( V_2 , V_2 -> V_5 . V_68 . V_16 ,
V_2 -> V_5 . V_68 . V_71 ,
V_2 -> V_5 . V_68 . V_62 ,
V_2 -> V_5 . V_68 . V_63 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_628 ) {
V_73 -> V_1083 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_623 . V_69 ) {
V_73 -> V_1084 ( V_2 ) ;
return 0 ;
}
if ( F_443 ( V_2 ) && V_73 -> V_1085 ) {
V_119 = V_73 -> V_1085 ( V_2 , V_1080 ) ;
if ( V_119 != 0 )
return V_119 ;
}
if ( V_2 -> V_5 . V_629 ) {
if ( V_73 -> V_1086 ( V_2 ) ) {
-- V_2 -> V_5 . V_629 ;
V_2 -> V_5 . V_628 = true ;
V_73 -> V_1083 ( V_2 ) ;
}
} else if ( F_528 ( V_2 ) ) {
if ( F_443 ( V_2 ) && V_73 -> V_1085 ) {
V_119 = V_73 -> V_1085 ( V_2 , V_1080 ) ;
if ( V_119 != 0 )
return V_119 ;
}
if ( V_73 -> V_1087 ( V_2 ) ) {
F_262 ( V_2 , F_529 ( V_2 ) ,
false ) ;
V_73 -> V_1084 ( V_2 ) ;
}
}
return 0 ;
}
static void F_269 ( struct V_1 * V_2 )
{
unsigned V_896 = 2 ;
if ( V_73 -> V_631 ( V_2 ) || V_2 -> V_5 . V_628 )
V_896 = 1 ;
V_2 -> V_5 . V_629 += F_530 ( & V_2 -> V_5 . V_85 , 0 ) ;
V_2 -> V_5 . V_629 = F_333 ( V_2 -> V_5 . V_629 , V_896 ) ;
F_31 ( V_67 , V_2 ) ;
}
static T_1 F_531 ( struct V_809 * V_811 )
{
T_1 V_294 = 0 ;
V_294 |= V_811 -> V_895 << 23 ;
V_294 |= V_811 -> V_179 << 22 ;
V_294 |= V_811 -> V_901 << 21 ;
V_294 |= V_811 -> V_900 << 20 ;
V_294 |= V_811 -> V_899 << 15 ;
V_294 |= V_811 -> V_897 << 13 ;
V_294 |= V_811 -> V_596 << 12 ;
V_294 |= V_811 -> type << 8 ;
return V_294 ;
}
static void F_532 ( struct V_1 * V_2 , char * V_1088 , int V_500 )
{
struct V_809 V_811 ;
int V_94 ;
F_341 ( V_2 , & V_811 , V_500 ) ;
F_533 ( T_1 , V_1088 , 0x7fa8 + V_500 * 4 , V_811 . V_890 ) ;
if ( V_500 < 3 )
V_94 = 0x7f84 + V_500 * 12 ;
else
V_94 = 0x7f2c + ( V_500 - 3 ) * 12 ;
F_533 ( T_1 , V_1088 , V_94 + 8 , V_811 . V_226 ) ;
F_533 ( T_1 , V_1088 , V_94 + 4 , V_811 . V_896 ) ;
F_533 ( T_1 , V_1088 , V_94 , F_531 ( & V_811 ) ) ;
}
static void F_534 ( struct V_1 * V_2 , char * V_1088 , int V_500 )
{
struct V_809 V_811 ;
int V_94 ;
V_862 V_294 ;
F_341 ( V_2 , & V_811 , V_500 ) ;
V_94 = 0x7e00 + V_500 * 16 ;
V_294 = F_531 ( & V_811 ) >> 8 ;
F_533 ( V_862 , V_1088 , V_94 , V_811 . V_890 ) ;
F_533 ( V_862 , V_1088 , V_94 + 2 , V_294 ) ;
F_533 ( T_1 , V_1088 , V_94 + 4 , V_811 . V_896 ) ;
F_533 ( T_2 , V_1088 , V_94 + 8 , V_811 . V_226 ) ;
}
static void F_535 ( struct V_1 * V_2 , char * V_1088 )
{
struct V_884 V_885 ;
struct V_809 V_811 ;
unsigned long V_192 ;
int V_3 ;
F_533 ( T_1 , V_1088 , 0x7ffc , F_62 ( V_2 ) ) ;
F_533 ( T_1 , V_1088 , 0x7ff8 , F_60 ( V_2 ) ) ;
F_533 ( T_1 , V_1088 , 0x7ff4 , F_434 ( V_2 ) ) ;
F_533 ( T_1 , V_1088 , 0x7ff0 , F_435 ( V_2 ) ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
F_533 ( T_1 , V_1088 , 0x7fd0 + V_3 * 4 , F_100 ( V_2 , V_3 ) ) ;
F_98 ( V_2 , 6 , & V_192 ) ;
F_533 ( T_1 , V_1088 , 0x7fcc , ( T_1 ) V_192 ) ;
F_98 ( V_2 , 7 , & V_192 ) ;
F_533 ( T_1 , V_1088 , 0x7fc8 , ( T_1 ) V_192 ) ;
F_341 ( V_2 , & V_811 , V_1089 ) ;
F_533 ( T_1 , V_1088 , 0x7fc4 , V_811 . V_890 ) ;
F_533 ( T_1 , V_1088 , 0x7f64 , V_811 . V_226 ) ;
F_533 ( T_1 , V_1088 , 0x7f60 , V_811 . V_896 ) ;
F_533 ( T_1 , V_1088 , 0x7f5c , F_531 ( & V_811 ) ) ;
F_341 ( V_2 , & V_811 , V_1090 ) ;
F_533 ( T_1 , V_1088 , 0x7fc0 , V_811 . V_890 ) ;
F_533 ( T_1 , V_1088 , 0x7f80 , V_811 . V_226 ) ;
F_533 ( T_1 , V_1088 , 0x7f7c , V_811 . V_896 ) ;
F_533 ( T_1 , V_1088 , 0x7f78 , F_531 ( & V_811 ) ) ;
V_73 -> V_886 ( V_2 , & V_885 ) ;
F_533 ( T_1 , V_1088 , 0x7f74 , V_885 . V_80 ) ;
F_533 ( T_1 , V_1088 , 0x7f70 , V_885 . V_501 ) ;
V_73 -> V_887 ( V_2 , & V_885 ) ;
F_533 ( T_1 , V_1088 , 0x7f58 , V_885 . V_80 ) ;
F_533 ( T_1 , V_1088 , 0x7f54 , V_885 . V_501 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_532 ( V_2 , V_1088 , V_3 ) ;
F_533 ( T_1 , V_1088 , 0x7f14 , F_77 ( V_2 ) ) ;
F_533 ( T_1 , V_1088 , 0x7efc , 0x00020000 ) ;
F_533 ( T_1 , V_1088 , 0x7ef8 , V_2 -> V_5 . V_441 ) ;
}
static void F_536 ( struct V_1 * V_2 , char * V_1088 )
{
#ifdef F_63
struct V_884 V_885 ;
struct V_809 V_811 ;
unsigned long V_192 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ )
F_533 ( T_2 , V_1088 , 0x7ff8 - V_3 * 8 , F_100 ( V_2 , V_3 ) ) ;
F_533 ( T_2 , V_1088 , 0x7f78 , F_435 ( V_2 ) ) ;
F_533 ( T_1 , V_1088 , 0x7f70 , F_434 ( V_2 ) ) ;
F_98 ( V_2 , 6 , & V_192 ) ;
F_533 ( T_2 , V_1088 , 0x7f68 , V_192 ) ;
F_98 ( V_2 , 7 , & V_192 ) ;
F_533 ( T_2 , V_1088 , 0x7f60 , V_192 ) ;
F_533 ( T_2 , V_1088 , 0x7f58 , F_62 ( V_2 ) ) ;
F_533 ( T_2 , V_1088 , 0x7f50 , F_60 ( V_2 ) ) ;
F_533 ( T_2 , V_1088 , 0x7f48 , F_77 ( V_2 ) ) ;
F_533 ( T_1 , V_1088 , 0x7f00 , V_2 -> V_5 . V_441 ) ;
F_533 ( T_1 , V_1088 , 0x7efc , 0x00020064 ) ;
F_533 ( T_2 , V_1088 , 0x7ed0 , V_2 -> V_5 . V_130 ) ;
F_341 ( V_2 , & V_811 , V_1089 ) ;
F_533 ( V_862 , V_1088 , 0x7e90 , V_811 . V_890 ) ;
F_533 ( V_862 , V_1088 , 0x7e92 , F_531 ( & V_811 ) >> 8 ) ;
F_533 ( T_1 , V_1088 , 0x7e94 , V_811 . V_896 ) ;
F_533 ( T_2 , V_1088 , 0x7e98 , V_811 . V_226 ) ;
V_73 -> V_887 ( V_2 , & V_885 ) ;
F_533 ( T_1 , V_1088 , 0x7e84 , V_885 . V_501 ) ;
F_533 ( T_2 , V_1088 , 0x7e88 , V_885 . V_80 ) ;
F_341 ( V_2 , & V_811 , V_1090 ) ;
F_533 ( V_862 , V_1088 , 0x7e70 , V_811 . V_890 ) ;
F_533 ( V_862 , V_1088 , 0x7e72 , F_531 ( & V_811 ) >> 8 ) ;
F_533 ( T_1 , V_1088 , 0x7e74 , V_811 . V_896 ) ;
F_533 ( T_2 , V_1088 , 0x7e78 , V_811 . V_226 ) ;
V_73 -> V_886 ( V_2 , & V_885 ) ;
F_533 ( T_1 , V_1088 , 0x7e64 , V_885 . V_501 ) ;
F_533 ( T_2 , V_1088 , 0x7e68 , V_885 . V_80 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_534 ( V_2 , V_1088 , V_3 ) ;
#else
F_537 ( 1 ) ;
#endif
}
static void F_538 ( struct V_1 * V_2 )
{
struct V_809 V_1091 , V_1092 ;
struct V_884 V_885 ;
char V_1088 [ 512 ] ;
T_1 V_120 ;
if ( F_271 ( V_2 ) ) {
V_2 -> V_5 . V_635 = true ;
return;
}
F_452 ( V_2 -> V_288 , V_2 -> V_5 . V_441 , true ) ;
V_2 -> V_5 . V_637 |= V_647 ;
memset ( V_1088 , 0 , 512 ) ;
if ( F_539 ( V_2 ) )
F_536 ( V_2 , V_1088 ) ;
else
F_535 ( V_2 , V_1088 ) ;
F_188 ( V_2 , V_2 -> V_5 . V_441 + 0xfe00 , V_1088 , sizeof( V_1088 ) ) ;
if ( V_73 -> V_631 ( V_2 ) )
V_2 -> V_5 . V_637 |= V_638 ;
else
V_73 -> V_646 ( V_2 , true ) ;
F_440 ( V_2 , V_1093 ) ;
F_439 ( V_2 , 0x8000 ) ;
V_120 = V_2 -> V_5 . V_120 & ~ ( V_129 | V_1094 | V_1095 | V_123 ) ;
V_73 -> V_136 ( V_2 , V_120 ) ;
V_2 -> V_5 . V_120 = V_120 ;
V_73 -> V_167 ( V_2 , 0 ) ;
V_885 . V_80 = V_885 . V_501 = 0 ;
V_73 -> V_889 ( V_2 , & V_885 ) ;
F_96 ( V_2 , 7 , V_195 ) ;
V_1091 . V_890 = ( V_2 -> V_5 . V_441 >> 4 ) & 0xffff ;
V_1091 . V_226 = V_2 -> V_5 . V_441 ;
V_1092 . V_890 = 0 ;
V_1092 . V_226 = 0 ;
V_1091 . V_896 = V_1092 . V_896 = 0xffffffff ;
V_1091 . type = V_1092 . type = 0x3 ;
V_1091 . V_897 = V_1092 . V_897 = 0 ;
V_1091 . V_179 = V_1092 . V_179 = 0 ;
V_1091 . V_596 = V_1092 . V_596 = 1 ;
V_1091 . V_901 = V_1092 . V_901 = 0 ;
V_1091 . V_895 = V_1092 . V_895 = 1 ;
V_1091 . V_900 = V_1092 . V_900 = 0 ;
V_1091 . V_899 = V_1092 . V_899 = 1 ;
V_1091 . V_894 = V_1092 . V_894 = 0 ;
V_1091 . V_903 = V_1092 . V_903 = 0 ;
F_340 ( V_2 , & V_1091 , V_1096 ) ;
F_340 ( V_2 , & V_1092 , V_1097 ) ;
F_340 ( V_2 , & V_1092 , V_1098 ) ;
F_340 ( V_2 , & V_1092 , V_1099 ) ;
F_340 ( V_2 , & V_1092 , V_1100 ) ;
F_340 ( V_2 , & V_1092 , V_1101 ) ;
if ( F_539 ( V_2 ) )
V_73 -> F_106 ( V_2 , 0 ) ;
F_74 ( V_2 ) ;
F_66 ( V_2 ) ;
}
static void F_540 ( struct V_1 * V_2 )
{
T_2 V_1102 [ 4 ] ;
T_1 V_1103 [ 8 ] ;
if ( ! F_541 ( V_2 -> V_5 . V_599 ) )
return;
memset ( V_1102 , 0 , 32 ) ;
memset ( V_1103 , 0 , 32 ) ;
F_542 ( V_2 , V_1102 , V_1103 ) ;
V_73 -> V_1104 ( V_2 , V_1102 ) ;
F_543 ( V_2 , V_1103 ) ;
}
static void F_544 ( struct V_1 * V_2 )
{
++ V_2 -> V_77 . V_1105 ;
V_73 -> V_1105 ( V_2 ) ;
}
void F_545 ( struct V_1 * V_2 )
{
struct V_375 * V_375 = NULL ;
if ( ! F_87 ( V_2 -> V_137 ) )
return;
if ( ! V_73 -> V_1106 )
return;
V_375 = F_546 ( V_2 -> V_137 , V_828 >> V_106 ) ;
if ( F_373 ( V_375 ) )
return;
V_73 -> V_1106 ( V_2 , F_547 ( V_375 ) ) ;
F_548 ( V_375 ) ;
}
void F_549 ( struct V_137 * V_137 ,
unsigned long V_80 )
{
if ( V_80 == F_193 ( V_137 , V_828 >> V_106 ) )
F_550 ( V_137 , V_1107 ) ;
}
static int F_551 ( struct V_1 * V_2 )
{
int V_119 ;
bool V_1080 = ! F_87 ( V_2 -> V_137 ) &&
V_2 -> V_835 -> V_1074 ;
bool V_1108 = false ;
if ( V_2 -> V_326 ) {
if ( F_552 ( V_1109 , V_2 ) )
F_553 ( V_2 ) ;
if ( F_552 ( V_1110 , V_2 ) )
F_554 ( V_2 ) ;
if ( F_552 ( V_287 , V_2 ) )
F_161 ( V_2 -> V_137 ) ;
if ( F_552 ( V_448 , V_2 ) )
F_179 ( V_2 ) ;
if ( F_552 ( V_324 , V_2 ) ) {
V_119 = F_165 ( V_2 ) ;
if ( F_155 ( V_119 ) )
goto V_113;
}
if ( F_552 ( V_1111 , V_2 ) )
F_84 ( V_2 ) ;
if ( F_552 ( V_169 , V_2 ) )
F_544 ( V_2 ) ;
if ( F_552 ( V_1112 , V_2 ) ) {
V_2 -> V_835 -> V_851 = V_1113 ;
V_119 = 0 ;
goto V_113;
}
if ( F_552 ( V_72 , V_2 ) ) {
V_2 -> V_835 -> V_851 = V_1114 ;
V_119 = 0 ;
goto V_113;
}
if ( F_552 ( V_1115 , V_2 ) ) {
V_2 -> V_1116 = 0 ;
V_73 -> V_1117 ( V_2 ) ;
}
if ( F_552 ( V_1118 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1119 = true ;
V_119 = 1 ;
goto V_113;
}
if ( F_552 ( V_453 , V_2 ) )
F_209 ( V_2 ) ;
if ( F_552 ( V_604 , V_2 ) )
F_538 ( V_2 ) ;
if ( F_552 ( V_86 , V_2 ) )
F_269 ( V_2 ) ;
if ( F_552 ( V_1120 , V_2 ) )
F_555 ( V_2 ) ;
if ( F_552 ( V_1121 , V_2 ) )
F_556 ( V_2 ) ;
if ( F_552 ( V_1122 , V_2 ) )
F_540 ( V_2 ) ;
if ( F_552 ( V_1107 , V_2 ) )
F_545 ( V_2 ) ;
}
if ( F_552 ( V_67 , V_2 ) || V_1080 ) {
F_557 ( V_2 ) ;
if ( V_2 -> V_5 . V_1034 == V_1123 ) {
V_119 = 1 ;
goto V_113;
}
if ( F_526 ( V_2 , V_1080 ) != 0 )
V_1108 = true ;
else if ( V_2 -> V_5 . V_629 )
V_73 -> V_1124 ( V_2 ) ;
else if ( F_528 ( V_2 ) || V_1080 )
V_73 -> V_1125 ( V_2 ) ;
if ( F_558 ( V_2 ) ) {
if ( V_73 -> V_1126 )
V_73 -> V_1126 ( V_2 ,
F_525 ( V_2 ) ) ;
F_260 ( V_2 ) ;
F_559 ( V_2 ) ;
}
}
V_119 = F_560 ( V_2 ) ;
if ( F_155 ( V_119 ) ) {
goto V_1127;
}
F_216 () ;
V_73 -> V_1128 ( V_2 ) ;
if ( V_2 -> V_1116 )
F_423 ( V_2 ) ;
F_70 ( V_2 ) ;
V_2 -> V_317 = V_1129 ;
F_236 ( & V_2 -> V_137 -> V_496 , V_2 -> V_1130 ) ;
F_561 () ;
F_327 () ;
if ( V_2 -> V_317 == V_1131 || V_2 -> V_326
|| F_562 () || F_563 ( V_412 ) ) {
V_2 -> V_317 = V_1132 ;
F_14 () ;
F_328 () ;
F_217 () ;
V_2 -> V_1130 = F_235 ( & V_2 -> V_137 -> V_496 ) ;
V_119 = 1 ;
goto V_1127;
}
if ( V_1108 )
F_564 ( V_2 -> V_23 ) ;
F_565 () ;
if ( F_155 ( V_2 -> V_5 . V_180 ) ) {
F_566 ( 0 , 7 ) ;
F_566 ( V_2 -> V_5 . V_178 [ 0 ] , 0 ) ;
F_566 ( V_2 -> V_5 . V_178 [ 1 ] , 1 ) ;
F_566 ( V_2 -> V_5 . V_178 [ 2 ] , 2 ) ;
F_566 ( V_2 -> V_5 . V_178 [ 3 ] , 3 ) ;
F_566 ( V_2 -> V_5 . V_183 , 6 ) ;
V_2 -> V_5 . V_180 &= ~ V_181 ;
}
F_567 ( V_2 -> V_288 ) ;
F_568 ( V_2 ) ;
V_73 -> V_835 ( V_2 ) ;
if ( F_155 ( V_2 -> V_5 . V_180 & V_1133 ) ) {
int V_3 ;
F_29 ( V_2 -> V_175 & V_176 ) ;
V_73 -> V_1134 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_177 ; V_3 ++ )
V_2 -> V_5 . V_178 [ V_3 ] = V_2 -> V_5 . V_179 [ V_3 ] ;
}
if ( F_569 () )
F_570 () ;
V_2 -> V_5 . V_311 = V_73 -> V_334 ( V_2 ,
F_169 () ) ;
V_2 -> V_317 = V_1132 ;
F_14 () ;
V_73 -> V_1135 ( V_2 ) ;
++ V_2 -> V_77 . V_1136 ;
F_571 () ;
F_572 () ;
F_217 () ;
V_2 -> V_1130 = F_235 ( & V_2 -> V_137 -> V_496 ) ;
if ( F_155 ( V_1137 == V_1138 ) ) {
unsigned long V_1073 = F_435 ( V_2 ) ;
F_573 ( V_1138 , ( void * ) V_1073 ) ;
}
if ( F_155 ( V_2 -> V_5 . V_1139 ) )
F_31 ( V_324 , V_2 ) ;
if ( V_2 -> V_5 . V_1140 )
F_574 ( V_2 ) ;
V_119 = V_73 -> V_1141 ( V_2 ) ;
return V_119 ;
V_1127:
V_73 -> V_1127 ( V_2 ) ;
if ( F_155 ( V_2 -> V_5 . V_1140 ) )
F_574 ( V_2 ) ;
V_113:
return V_119 ;
}
static inline int F_575 ( struct V_137 * V_137 , struct V_1 * V_2 )
{
if ( ! F_576 ( V_2 ) ) {
F_236 ( & V_137 -> V_496 , V_2 -> V_1130 ) ;
F_577 ( V_2 ) ;
V_2 -> V_1130 = F_235 ( & V_137 -> V_496 ) ;
if ( ! F_552 ( V_1142 , V_2 ) )
return 1 ;
}
F_557 ( V_2 ) ;
switch( V_2 -> V_5 . V_1034 ) {
case V_1035 :
V_2 -> V_5 . V_1143 . V_1144 = false ;
V_2 -> V_5 . V_1034 =
V_1145 ;
case V_1145 :
V_2 -> V_5 . V_6 . V_1119 = false ;
break;
case V_1123 :
break;
default:
return - V_1146 ;
break;
}
return 1 ;
}
static int F_578 ( struct V_1 * V_2 )
{
int V_119 ;
struct V_137 * V_137 = V_2 -> V_137 ;
V_2 -> V_1130 = F_235 ( & V_137 -> V_496 ) ;
for (; ; ) {
if ( V_2 -> V_5 . V_1034 == V_1145 &&
! V_2 -> V_5 . V_6 . V_1119 )
V_119 = F_551 ( V_2 ) ;
else
V_119 = F_575 ( V_137 , V_2 ) ;
if ( V_119 <= 0 )
break;
F_164 ( V_236 , & V_2 -> V_326 ) ;
if ( F_579 ( V_2 ) )
F_580 ( V_2 ) ;
if ( F_520 ( V_2 ) ) {
V_119 = - V_1146 ;
V_2 -> V_835 -> V_851 = V_1147 ;
++ V_2 -> V_77 . V_1148 ;
break;
}
F_581 ( V_2 ) ;
if ( F_563 ( V_412 ) ) {
V_119 = - V_1146 ;
V_2 -> V_835 -> V_851 = V_1147 ;
++ V_2 -> V_77 . V_1149 ;
break;
}
if ( F_562 () ) {
F_236 ( & V_137 -> V_496 , V_2 -> V_1130 ) ;
F_582 () ;
V_2 -> V_1130 = F_235 ( & V_137 -> V_496 ) ;
}
}
F_236 ( & V_137 -> V_496 , V_2 -> V_1130 ) ;
return V_119 ;
}
static inline int F_583 ( struct V_1 * V_2 )
{
int V_119 ;
V_2 -> V_1130 = F_235 ( & V_2 -> V_137 -> V_496 ) ;
V_119 = F_584 ( V_2 , V_969 ) ;
F_236 ( & V_2 -> V_137 -> V_496 , V_2 -> V_1130 ) ;
if ( V_119 != V_936 )
return 0 ;
return 1 ;
}
static int V_982 ( struct V_1 * V_2 )
{
F_13 ( ! V_2 -> V_5 . V_866 . V_741 ) ;
return F_583 ( V_2 ) ;
}
static int V_983 ( struct V_1 * V_2 )
{
struct V_956 * V_835 = V_2 -> V_835 ;
struct V_833 * V_834 ;
unsigned V_95 ;
F_13 ( ! V_2 -> V_847 ) ;
V_834 = & V_2 -> V_830 [ V_2 -> V_848 ] ;
V_95 = F_333 ( 8u , V_834 -> V_95 ) ;
if ( ! V_2 -> V_850 )
memcpy ( V_834 -> V_38 , V_835 -> V_836 . V_38 , V_95 ) ;
if ( V_834 -> V_95 <= 8 ) {
V_834 ++ ;
V_2 -> V_848 ++ ;
} else {
V_834 -> V_38 += V_95 ;
V_834 -> V_406 += V_95 ;
V_834 -> V_95 -= V_95 ;
}
if ( V_2 -> V_848 >= V_2 -> V_841 ) {
V_2 -> V_847 = 0 ;
if ( V_2 -> V_850 )
return 1 ;
V_2 -> V_829 = 1 ;
return F_583 ( V_2 ) ;
}
V_835 -> V_851 = V_852 ;
V_835 -> V_836 . V_853 = V_834 -> V_406 ;
if ( V_2 -> V_850 )
memcpy ( V_835 -> V_836 . V_38 , V_834 -> V_38 , F_333 ( 8u , V_834 -> V_95 ) ) ;
V_835 -> V_836 . V_95 = F_333 ( 8u , V_834 -> V_95 ) ;
V_835 -> V_836 . V_849 = V_2 -> V_850 ;
V_2 -> V_5 . V_981 = V_983 ;
return 0 ;
}
int F_585 ( struct V_1 * V_2 , struct V_956 * V_956 )
{
struct V_1150 * V_1150 = & V_412 -> V_1151 . V_1150 ;
int V_119 ;
T_19 V_1152 ;
F_586 ( V_1150 ) ;
if ( V_2 -> V_1153 )
F_587 ( V_1154 , & V_2 -> V_1155 , & V_1152 ) ;
if ( F_155 ( V_2 -> V_5 . V_1034 == V_1156 ) ) {
F_577 ( V_2 ) ;
F_557 ( V_2 ) ;
F_164 ( V_1142 , & V_2 -> V_326 ) ;
V_119 = - V_1157 ;
goto V_113;
}
if ( ! F_87 ( V_2 -> V_137 ) ) {
if ( F_86 ( V_2 , V_956 -> V_173 ) != 0 ) {
V_119 = - V_586 ;
goto V_113;
}
}
if ( F_155 ( V_2 -> V_5 . V_981 ) ) {
int (* F_588)( struct V_1 * ) = V_2 -> V_5 . V_981 ;
V_2 -> V_5 . V_981 = NULL ;
V_119 = F_588 ( V_2 ) ;
if ( V_119 <= 0 )
goto V_113;
} else
F_29 ( V_2 -> V_5 . V_866 . V_741 || V_2 -> V_847 ) ;
V_119 = F_578 ( V_2 ) ;
V_113:
F_523 ( V_2 ) ;
if ( V_2 -> V_1153 )
F_587 ( V_1154 , & V_1152 , NULL ) ;
return V_119 ;
}
int F_589 ( struct V_1 * V_2 , struct V_1158 * V_598 )
{
if ( V_2 -> V_5 . V_986 ) {
F_590 ( & V_2 -> V_5 . V_916 ) ;
V_2 -> V_5 . V_986 = false ;
}
V_598 -> V_1159 = F_100 ( V_2 , V_199 ) ;
V_598 -> V_1160 = F_100 ( V_2 , V_1047 ) ;
V_598 -> V_1161 = F_100 ( V_2 , V_198 ) ;
V_598 -> V_1162 = F_100 ( V_2 , V_200 ) ;
V_598 -> V_1163 = F_100 ( V_2 , V_1049 ) ;
V_598 -> V_1164 = F_100 ( V_2 , V_1048 ) ;
V_598 -> V_1165 = F_100 ( V_2 , V_1166 ) ;
V_598 -> V_1167 = F_100 ( V_2 , V_1168 ) ;
#ifdef F_63
V_598 -> V_1169 = F_100 ( V_2 , V_1050 ) ;
V_598 -> V_1170 = F_100 ( V_2 , V_1171 ) ;
V_598 -> V_1172 = F_100 ( V_2 , V_1173 ) ;
V_598 -> V_1174 = F_100 ( V_2 , V_1175 ) ;
V_598 -> V_1176 = F_100 ( V_2 , V_1177 ) ;
V_598 -> V_1178 = F_100 ( V_2 , V_1179 ) ;
V_598 -> V_1180 = F_100 ( V_2 , V_1181 ) ;
V_598 -> V_1182 = F_100 ( V_2 , V_1183 ) ;
#endif
V_598 -> V_1073 = F_435 ( V_2 ) ;
V_598 -> V_955 = F_434 ( V_2 ) ;
return 0 ;
}
int F_591 ( struct V_1 * V_2 , struct V_1158 * V_598 )
{
V_2 -> V_5 . V_930 = true ;
V_2 -> V_5 . V_986 = false ;
F_102 ( V_2 , V_199 , V_598 -> V_1159 ) ;
F_102 ( V_2 , V_1047 , V_598 -> V_1160 ) ;
F_102 ( V_2 , V_198 , V_598 -> V_1161 ) ;
F_102 ( V_2 , V_200 , V_598 -> V_1162 ) ;
F_102 ( V_2 , V_1049 , V_598 -> V_1163 ) ;
F_102 ( V_2 , V_1048 , V_598 -> V_1164 ) ;
F_102 ( V_2 , V_1166 , V_598 -> V_1165 ) ;
F_102 ( V_2 , V_1168 , V_598 -> V_1167 ) ;
#ifdef F_63
F_102 ( V_2 , V_1050 , V_598 -> V_1169 ) ;
F_102 ( V_2 , V_1171 , V_598 -> V_1170 ) ;
F_102 ( V_2 , V_1173 , V_598 -> V_1172 ) ;
F_102 ( V_2 , V_1175 , V_598 -> V_1174 ) ;
F_102 ( V_2 , V_1177 , V_598 -> V_1176 ) ;
F_102 ( V_2 , V_1179 , V_598 -> V_1178 ) ;
F_102 ( V_2 , V_1181 , V_598 -> V_1180 ) ;
F_102 ( V_2 , V_1183 , V_598 -> V_1182 ) ;
#endif
F_439 ( V_2 , V_598 -> V_1073 ) ;
F_440 ( V_2 , V_598 -> V_955 ) ;
V_2 -> V_5 . V_68 . V_69 = false ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
void F_592 ( struct V_1 * V_2 , int * V_179 , int * V_901 )
{
struct V_809 V_1091 ;
F_341 ( V_2 , & V_1091 , V_1096 ) ;
* V_179 = V_1091 . V_179 ;
* V_901 = V_1091 . V_901 ;
}
int F_593 ( struct V_1 * V_2 ,
struct V_1184 * V_1185 )
{
struct V_884 V_885 ;
F_341 ( V_2 , & V_1185 -> V_1091 , V_1096 ) ;
F_341 ( V_2 , & V_1185 -> V_1092 , V_1097 ) ;
F_341 ( V_2 , & V_1185 -> V_1186 , V_1098 ) ;
F_341 ( V_2 , & V_1185 -> V_1187 , V_1099 ) ;
F_341 ( V_2 , & V_1185 -> V_1188 , V_1100 ) ;
F_341 ( V_2 , & V_1185 -> V_1189 , V_1101 ) ;
F_341 ( V_2 , & V_1185 -> V_1190 , V_1089 ) ;
F_341 ( V_2 , & V_1185 -> V_1191 , V_1090 ) ;
V_73 -> V_887 ( V_2 , & V_885 ) ;
V_1185 -> V_1192 . V_896 = V_885 . V_501 ;
V_1185 -> V_1192 . V_226 = V_885 . V_80 ;
V_73 -> V_886 ( V_2 , & V_885 ) ;
V_1185 -> V_1193 . V_896 = V_885 . V_501 ;
V_1185 -> V_1193 . V_226 = V_885 . V_80 ;
V_1185 -> V_120 = F_62 ( V_2 ) ;
V_1185 -> V_79 = V_2 -> V_5 . V_79 ;
V_1185 -> V_104 = F_60 ( V_2 ) ;
V_1185 -> V_156 = F_77 ( V_2 ) ;
V_1185 -> V_173 = F_89 ( V_2 ) ;
V_1185 -> V_130 = V_2 -> V_5 . V_130 ;
V_1185 -> V_31 = F_20 ( V_2 ) ;
memset ( V_1185 -> V_1194 , 0 , sizeof V_1185 -> V_1194 ) ;
if ( V_2 -> V_5 . V_623 . V_69 && ! V_2 -> V_5 . V_623 . V_624 )
F_214 ( V_2 -> V_5 . V_623 . V_16 ,
( unsigned long * ) V_1185 -> V_1194 ) ;
return 0 ;
}
int F_594 ( struct V_1 * V_2 ,
struct V_1195 * V_1034 )
{
F_557 ( V_2 ) ;
if ( V_2 -> V_5 . V_1034 == V_1035 &&
V_2 -> V_5 . V_1143 . V_1144 )
V_1034 -> V_1034 = V_1145 ;
else
V_1034 -> V_1034 = V_2 -> V_5 . V_1034 ;
return 0 ;
}
int F_595 ( struct V_1 * V_2 ,
struct V_1195 * V_1034 )
{
if ( ! F_274 ( V_2 ) &&
V_1034 -> V_1034 != V_1145 )
return - V_586 ;
if ( V_1034 -> V_1034 == V_1196 ) {
V_2 -> V_5 . V_1034 = V_1123 ;
F_214 ( V_1197 , & V_2 -> V_5 . V_599 -> V_649 ) ;
} else
V_2 -> V_5 . V_1034 = V_1034 -> V_1034 ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
int F_596 ( struct V_1 * V_2 , V_862 V_1198 , int V_1199 ,
int V_1200 , bool V_71 , T_1 V_62 )
{
struct V_823 * V_824 = & V_2 -> V_5 . V_916 ;
int V_108 ;
F_433 ( V_2 ) ;
V_108 = F_597 ( V_824 , V_1198 , V_1199 , V_1200 ,
V_71 , V_62 ) ;
if ( V_108 )
return V_935 ;
F_439 ( V_2 , V_824 -> V_919 ) ;
F_440 ( V_2 , V_824 -> V_918 ) ;
F_31 ( V_67 , V_2 ) ;
return V_936 ;
}
int F_598 ( struct V_1 * V_2 ,
struct V_1184 * V_1185 )
{
struct V_32 V_1201 ;
int V_1202 = 0 ;
int V_1203 , V_1204 , V_495 ;
struct V_884 V_885 ;
if ( ! F_78 ( V_2 ) && ( V_1185 -> V_156 & V_139 ) )
return - V_586 ;
V_885 . V_501 = V_1185 -> V_1192 . V_896 ;
V_885 . V_80 = V_1185 -> V_1192 . V_226 ;
V_73 -> V_889 ( V_2 , & V_885 ) ;
V_885 . V_501 = V_1185 -> V_1193 . V_896 ;
V_885 . V_80 = V_1185 -> V_1193 . V_226 ;
V_73 -> V_888 ( V_2 , & V_885 ) ;
V_2 -> V_5 . V_79 = V_1185 -> V_79 ;
V_1202 |= F_60 ( V_2 ) != V_1185 -> V_104 ;
V_2 -> V_5 . V_104 = V_1185 -> V_104 ;
F_55 ( V_171 , ( V_172 * ) & V_2 -> V_5 . V_116 ) ;
F_86 ( V_2 , V_1185 -> V_173 ) ;
V_1202 |= V_2 -> V_5 . V_130 != V_1185 -> V_130 ;
V_73 -> F_106 ( V_2 , V_1185 -> V_130 ) ;
V_1201 . V_38 = V_1185 -> V_31 ;
V_1201 . V_40 = true ;
F_21 ( V_2 , & V_1201 ) ;
V_1202 |= F_62 ( V_2 ) != V_1185 -> V_120 ;
V_73 -> V_136 ( V_2 , V_1185 -> V_120 ) ;
V_2 -> V_5 . V_120 = V_1185 -> V_120 ;
V_1202 |= F_77 ( V_2 ) != V_1185 -> V_156 ;
V_73 -> V_167 ( V_2 , V_1185 -> V_156 ) ;
if ( V_1185 -> V_156 & V_139 )
F_74 ( V_2 ) ;
V_495 = F_235 ( & V_2 -> V_137 -> V_496 ) ;
if ( ! F_57 ( V_2 ) && F_58 ( V_2 ) ) {
F_52 ( V_2 , V_2 -> V_5 . V_103 , F_60 ( V_2 ) ) ;
V_1202 = 1 ;
}
F_236 ( & V_2 -> V_137 -> V_496 , V_495 ) ;
if ( V_1202 )
F_66 ( V_2 ) ;
V_1204 = V_602 ;
V_1203 = F_599 (
( const unsigned long * ) V_1185 -> V_1194 , V_1204 ) ;
if ( V_1203 < V_1204 ) {
F_262 ( V_2 , V_1203 , false ) ;
F_128 ( L_28 , V_1203 ) ;
}
F_340 ( V_2 , & V_1185 -> V_1091 , V_1096 ) ;
F_340 ( V_2 , & V_1185 -> V_1092 , V_1097 ) ;
F_340 ( V_2 , & V_1185 -> V_1186 , V_1098 ) ;
F_340 ( V_2 , & V_1185 -> V_1187 , V_1099 ) ;
F_340 ( V_2 , & V_1185 -> V_1188 , V_1100 ) ;
F_340 ( V_2 , & V_1185 -> V_1189 , V_1101 ) ;
F_340 ( V_2 , & V_1185 -> V_1190 , V_1089 ) ;
F_340 ( V_2 , & V_1185 -> V_1191 , V_1090 ) ;
F_260 ( V_2 ) ;
if ( F_600 ( V_2 ) && F_435 ( V_2 ) == 0xfff0 &&
V_1185 -> V_1091 . V_890 == 0xf000 && V_1185 -> V_1091 . V_226 == 0xffff0000 &&
! F_32 ( V_2 ) )
V_2 -> V_5 . V_1034 = V_1145 ;
F_31 ( V_67 , V_2 ) ;
return 0 ;
}
int F_601 ( struct V_1 * V_2 ,
struct V_1205 * V_1206 )
{
unsigned long V_955 ;
int V_3 , V_119 ;
if ( V_1206 -> V_748 & ( V_1207 | V_1208 ) ) {
V_119 = - V_1209 ;
if ( V_2 -> V_5 . V_68 . V_69 )
goto V_113;
if ( V_1206 -> V_748 & V_1207 )
F_33 ( V_2 , V_53 ) ;
else
F_33 ( V_2 , V_54 ) ;
}
V_955 = F_434 ( V_2 ) ;
V_2 -> V_175 = V_1206 -> V_748 ;
if ( ! ( V_2 -> V_175 & V_1210 ) )
V_2 -> V_175 = 0 ;
if ( V_2 -> V_175 & V_176 ) {
for ( V_3 = 0 ; V_3 < V_177 ; ++ V_3 )
V_2 -> V_5 . V_178 [ V_3 ] = V_1206 -> V_5 . V_1211 [ V_3 ] ;
V_2 -> V_5 . V_185 = V_1206 -> V_5 . V_1211 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_177 ; V_3 ++ )
V_2 -> V_5 . V_178 [ V_3 ] = V_2 -> V_5 . V_179 [ V_3 ] ;
}
F_93 ( V_2 ) ;
if ( V_2 -> V_175 & V_958 )
V_2 -> V_5 . V_962 = F_435 ( V_2 ) +
F_386 ( V_2 , V_1096 ) ;
F_440 ( V_2 , V_955 ) ;
V_73 -> V_1212 ( V_2 ) ;
V_119 = 0 ;
V_113:
return V_119 ;
}
int F_602 ( struct V_1 * V_2 ,
struct V_1213 * V_1190 )
{
unsigned long V_1214 = V_1190 -> V_1215 ;
T_6 V_406 ;
int V_495 ;
V_495 = F_235 ( & V_2 -> V_137 -> V_496 ) ;
V_406 = F_346 ( V_2 , V_1214 , NULL ) ;
F_236 ( & V_2 -> V_137 -> V_496 , V_495 ) ;
V_1190 -> V_1216 = V_406 ;
V_1190 -> V_660 = V_406 != V_100 ;
V_1190 -> V_1217 = 1 ;
V_1190 -> V_1218 = 0 ;
return 0 ;
}
int F_603 ( struct V_1 * V_2 , struct V_1219 * V_1150 )
{
struct V_673 * V_672 =
& V_2 -> V_5 . V_655 . V_656 . V_672 ;
memcpy ( V_1150 -> V_1220 , V_672 -> V_1221 , 128 ) ;
V_1150 -> V_1222 = V_672 -> V_1223 ;
V_1150 -> V_1224 = V_672 -> V_1225 ;
V_1150 -> V_1226 = V_672 -> V_1227 ;
V_1150 -> V_1228 = V_672 -> V_1229 ;
V_1150 -> V_1230 = V_672 -> V_1073 ;
V_1150 -> V_1231 = V_672 -> V_1232 ;
memcpy ( V_1150 -> V_1233 , V_672 -> V_1234 , sizeof V_672 -> V_1234 ) ;
return 0 ;
}
int F_604 ( struct V_1 * V_2 , struct V_1219 * V_1150 )
{
struct V_673 * V_672 =
& V_2 -> V_5 . V_655 . V_656 . V_672 ;
memcpy ( V_672 -> V_1221 , V_1150 -> V_1220 , 128 ) ;
V_672 -> V_1223 = V_1150 -> V_1222 ;
V_672 -> V_1225 = V_1150 -> V_1224 ;
V_672 -> V_1227 = V_1150 -> V_1226 ;
V_672 -> V_1229 = V_1150 -> V_1228 ;
V_672 -> V_1073 = V_1150 -> V_1230 ;
V_672 -> V_1232 = V_1150 -> V_1231 ;
memcpy ( V_672 -> V_1234 , V_1150 -> V_1233 , sizeof V_672 -> V_1234 ) ;
return 0 ;
}
static void F_605 ( struct V_1 * V_2 )
{
F_606 ( & V_2 -> V_5 . V_655 . V_656 ) ;
if ( V_666 )
V_2 -> V_5 . V_655 . V_656 . V_654 . V_658 . V_667 =
V_143 | V_668 ;
V_2 -> V_5 . V_142 = V_148 ;
V_2 -> V_5 . V_120 |= V_125 ;
}
void F_423 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1235 )
return;
F_72 ( V_2 ) ;
V_2 -> V_1235 = 1 ;
F_607 () ;
F_608 ( & V_2 -> V_5 . V_655 . V_656 ) ;
F_609 ( 1 ) ;
}
void F_256 ( struct V_1 * V_2 )
{
F_72 ( V_2 ) ;
if ( ! V_2 -> V_1235 ) {
V_2 -> V_1236 = 0 ;
return;
}
V_2 -> V_1235 = 0 ;
F_610 ( & V_2 -> V_5 . V_655 ) ;
F_611 () ;
++ V_2 -> V_77 . V_1237 ;
if ( ! V_2 -> V_5 . V_1238 ) {
if ( ++ V_2 -> V_1236 < 5 )
F_31 ( V_1115 , V_2 ) ;
}
F_609 ( 0 ) ;
}
void F_612 ( struct V_1 * V_2 )
{
F_207 ( V_2 ) ;
F_613 ( V_2 -> V_5 . V_589 ) ;
V_73 -> V_1239 ( V_2 ) ;
}
struct V_1 * F_614 ( struct V_137 * V_137 ,
unsigned int V_1240 )
{
struct V_1 * V_2 ;
if ( F_143 () && F_138 ( & V_137 -> V_284 ) != 0 )
F_380 ( V_864
L_29
L_30 ) ;
V_2 = V_73 -> V_1241 ( V_137 , V_1240 ) ;
return V_2 ;
}
int F_615 ( struct V_1 * V_2 )
{
int V_119 ;
F_616 ( V_2 ) ;
V_119 = V_590 ( V_2 ) ;
if ( V_119 )
return V_119 ;
F_617 ( V_2 , false ) ;
F_618 ( V_2 ) ;
V_594 ( V_2 ) ;
return V_119 ;
}
void F_619 ( struct V_1 * V_2 )
{
struct V_32 V_21 ;
struct V_137 * V_137 = V_2 -> V_137 ;
if ( V_590 ( V_2 ) )
return;
V_21 . V_38 = 0x0 ;
V_21 . V_144 = V_1242 ;
V_21 . V_40 = true ;
F_141 ( V_2 , & V_21 ) ;
V_594 ( V_2 ) ;
if ( ! V_354 )
return;
F_180 ( & V_137 -> V_5 . V_353 ,
V_355 ) ;
}
void F_620 ( struct V_1 * V_2 )
{
int V_119 ;
V_2 -> V_5 . V_6 . V_407 = 0 ;
V_119 = V_590 ( V_2 ) ;
F_13 ( V_119 ) ;
F_553 ( V_2 ) ;
V_594 ( V_2 ) ;
V_73 -> V_1239 ( V_2 ) ;
}
void F_617 ( struct V_1 * V_2 , bool V_1243 )
{
V_2 -> V_5 . V_637 = 0 ;
F_159 ( & V_2 -> V_5 . V_85 , 0 ) ;
V_2 -> V_5 . V_629 = 0 ;
V_2 -> V_5 . V_628 = false ;
F_621 ( V_2 ) ;
F_459 ( V_2 ) ;
memset ( V_2 -> V_5 . V_179 , 0 , sizeof( V_2 -> V_5 . V_179 ) ) ;
F_91 ( V_2 ) ;
V_2 -> V_5 . V_183 = V_1244 ;
F_92 ( V_2 ) ;
V_2 -> V_5 . V_184 = V_195 ;
F_93 ( V_2 ) ;
V_2 -> V_5 . V_79 = 0 ;
F_31 ( V_67 , V_2 ) ;
V_2 -> V_5 . V_6 . V_407 = 0 ;
V_2 -> V_5 . V_411 . V_407 = 0 ;
F_207 ( V_2 ) ;
F_65 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1119 = false ;
if ( ! V_1243 ) {
F_622 ( V_2 ) ;
V_2 -> V_5 . V_441 = 0x30000 ;
}
memset ( V_2 -> V_5 . V_598 , 0 , sizeof( V_2 -> V_5 . V_598 ) ) ;
V_2 -> V_5 . V_116 = ~ 0 ;
V_2 -> V_5 . V_117 = ~ 0 ;
V_73 -> V_1245 ( V_2 , V_1243 ) ;
}
void F_623 ( struct V_1 * V_2 , T_14 V_41 )
{
struct V_809 V_1091 ;
F_341 ( V_2 , & V_1091 , V_1096 ) ;
V_1091 . V_890 = V_41 << 8 ;
V_1091 . V_226 = V_41 << 12 ;
F_340 ( V_2 , & V_1091 , V_1096 ) ;
F_439 ( V_2 , 0 ) ;
}
int F_624 ( void )
{
struct V_137 * V_137 ;
struct V_1 * V_2 ;
int V_3 ;
int V_108 ;
T_2 V_1246 ;
T_2 V_1247 = 0 ;
bool V_1248 , V_1249 = false ;
F_15 () ;
V_108 = V_73 -> V_1250 () ;
if ( V_108 != 0 )
return V_108 ;
V_1246 = F_169 () ;
V_1248 = ! F_143 () ;
F_473 (kvm, &vm_list, vm_list) {
F_163 (i, vcpu, kvm) {
if ( ! V_1248 && V_2 -> V_23 == F_8 () )
F_31 ( V_324 , V_2 ) ;
if ( V_1248 && V_2 -> V_5 . V_593 > V_1246 ) {
V_1249 = true ;
if ( V_2 -> V_5 . V_593 > V_1247 )
V_1247 = V_2 -> V_5 . V_593 ;
}
}
}
if ( V_1249 ) {
T_2 V_1251 = V_1247 - V_1246 ;
V_321 = true ;
F_473 (kvm, &vm_list, vm_list) {
F_163 (i, vcpu, kvm) {
V_2 -> V_5 . V_591 += V_1251 ;
V_2 -> V_5 . V_593 = V_1246 ;
F_31 ( V_287 , V_2 ) ;
}
V_137 -> V_5 . V_300 = 0 ;
V_137 -> V_5 . V_302 = 0 ;
}
}
return 0 ;
}
void F_625 ( void )
{
V_73 -> V_1252 () ;
F_19 () ;
}
int F_626 ( void )
{
int V_119 ;
V_119 = V_73 -> V_1253 () ;
if ( V_119 != 0 )
return V_119 ;
F_330 () ;
return 0 ;
}
void F_627 ( void )
{
V_73 -> V_1254 () ;
}
void F_628 ( void * V_1255 )
{
V_73 -> V_1256 ( V_1255 ) ;
}
bool F_629 ( struct V_1 * V_2 )
{
return F_87 ( V_2 -> V_137 ) == ( V_2 -> V_5 . V_599 != NULL ) ;
}
int F_630 ( struct V_1 * V_2 )
{
struct V_375 * V_375 ;
struct V_137 * V_137 ;
int V_119 ;
F_13 ( V_2 -> V_137 == NULL ) ;
V_137 = V_2 -> V_137 ;
V_2 -> V_5 . V_1143 . V_1144 = false ;
V_2 -> V_5 . V_916 . V_838 = & V_1257 ;
if ( ! F_87 ( V_137 ) || F_631 ( V_2 ) )
V_2 -> V_5 . V_1034 = V_1145 ;
else
V_2 -> V_5 . V_1034 = V_1156 ;
V_375 = F_632 ( V_684 | V_1258 ) ;
if ( ! V_375 ) {
V_119 = - V_377 ;
goto V_1259;
}
V_2 -> V_5 . V_869 = F_633 ( V_375 ) ;
F_135 ( V_2 , V_1004 ) ;
V_119 = F_634 ( V_2 ) ;
if ( V_119 < 0 )
goto V_1260;
if ( F_87 ( V_137 ) ) {
V_119 = F_635 ( V_2 ) ;
if ( V_119 < 0 )
goto V_1261;
} else
F_636 ( & V_1262 ) ;
V_2 -> V_5 . V_364 = F_289 ( V_455 * sizeof( T_2 ) * 4 ,
V_684 ) ;
if ( ! V_2 -> V_5 . V_364 ) {
V_119 = - V_377 ;
goto V_1263;
}
V_2 -> V_5 . V_356 = V_455 ;
if ( ! F_637 ( & V_2 -> V_5 . V_589 , V_684 ) ) {
V_119 = - V_377 ;
goto V_1264;
}
F_605 ( V_2 ) ;
V_2 -> V_5 . V_291 = 0x0 ;
V_2 -> V_5 . V_336 = false ;
V_2 -> V_5 . V_151 = 0 ;
V_2 -> V_5 . V_1265 = V_1266 + V_661 ;
V_2 -> V_5 . V_1015 = F_638 ( V_2 ) ;
V_2 -> V_5 . V_1267 = V_1268 ;
F_1 ( V_2 ) ;
F_639 ( V_2 ) ;
return 0 ;
V_1264:
F_189 ( V_2 -> V_5 . V_364 ) ;
V_1263:
F_640 ( V_2 ) ;
V_1261:
F_641 ( V_2 ) ;
V_1260:
F_642 ( ( unsigned long ) V_2 -> V_5 . V_869 ) ;
V_1259:
return V_119 ;
}
void F_643 ( struct V_1 * V_2 )
{
int V_495 ;
F_644 ( V_2 ) ;
F_189 ( V_2 -> V_5 . V_364 ) ;
F_640 ( V_2 ) ;
V_495 = F_235 ( & V_2 -> V_137 -> V_496 ) ;
F_641 ( V_2 ) ;
F_236 ( & V_2 -> V_137 -> V_496 , V_495 ) ;
F_642 ( ( unsigned long ) V_2 -> V_5 . V_869 ) ;
if ( ! F_87 ( V_2 -> V_137 ) )
F_645 ( & V_1262 ) ;
}
void F_646 ( struct V_1 * V_2 , int V_23 )
{
V_73 -> V_1269 ( V_2 , V_23 ) ;
}
int F_647 ( struct V_137 * V_137 , unsigned long type )
{
if ( type )
return - V_586 ;
F_648 ( & V_137 -> V_5 . V_1270 ) ;
F_649 ( & V_137 -> V_5 . V_1271 ) ;
F_649 ( & V_137 -> V_5 . V_1272 ) ;
F_649 ( & V_137 -> V_5 . V_1273 ) ;
F_159 ( & V_137 -> V_5 . V_1274 , 0 ) ;
F_214 ( V_756 , & V_137 -> V_5 . V_1275 ) ;
F_214 ( V_1276 ,
& V_137 -> V_5 . V_1275 ) ;
F_650 ( & V_137 -> V_5 . V_298 ) ;
F_651 ( & V_137 -> V_5 . V_1277 ) ;
F_652 ( & V_137 -> V_5 . V_313 ) ;
F_158 ( V_137 ) ;
F_653 ( & V_137 -> V_5 . V_351 , F_176 ) ;
F_653 ( & V_137 -> V_5 . V_353 , F_181 ) ;
return 0 ;
}
static void F_654 ( struct V_1 * V_2 )
{
int V_119 ;
V_119 = V_590 ( V_2 ) ;
F_13 ( V_119 ) ;
F_553 ( V_2 ) ;
V_594 ( V_2 ) ;
}
static void F_655 ( struct V_137 * V_137 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_163 (i, vcpu, kvm) {
F_65 ( V_2 ) ;
F_654 ( V_2 ) ;
}
F_163 (i, vcpu, kvm)
F_612 ( V_2 ) ;
F_220 ( & V_137 -> V_466 ) ;
for ( V_3 = 0 ; V_3 < F_138 ( & V_137 -> V_284 ) ; V_3 ++ )
V_137 -> V_1278 [ V_3 ] = NULL ;
F_159 ( & V_137 -> V_284 , 0 ) ;
F_221 ( & V_137 -> V_466 ) ;
}
void F_656 ( struct V_137 * V_137 )
{
F_657 ( & V_137 -> V_5 . V_353 ) ;
F_657 ( & V_137 -> V_5 . V_351 ) ;
F_658 ( V_137 ) ;
F_659 ( V_137 ) ;
}
int F_660 ( struct V_137 * V_137 ,
const struct V_1279 * V_1280 )
{
int V_3 , V_119 ;
F_13 ( V_1280 -> V_10 >= V_1281 ) ;
for ( V_3 = 0 ; V_3 < V_1282 ; V_3 ++ ) {
struct V_1279 V_1283 = * V_1280 ;
V_1283 . V_10 |= V_3 << 16 ;
V_119 = F_661 ( V_137 , & V_1283 ) ;
if ( V_119 < 0 )
return V_119 ;
}
return 0 ;
}
int F_662 ( struct V_137 * V_137 ,
const struct V_1279 * V_1280 )
{
int V_119 ;
F_220 ( & V_137 -> V_723 ) ;
V_119 = F_660 ( V_137 , V_1280 ) ;
F_221 ( & V_137 -> V_723 ) ;
return V_119 ;
}
void F_663 ( struct V_137 * V_137 )
{
if ( V_412 -> V_1284 == V_137 -> V_1284 ) {
struct V_1279 V_1280 ;
memset ( & V_1280 , 0 , sizeof( V_1280 ) ) ;
V_1280 . V_10 = V_1285 ;
F_662 ( V_137 , & V_1280 ) ;
V_1280 . V_10 = V_1286 ;
F_662 ( V_137 , & V_1280 ) ;
V_1280 . V_10 = V_1287 ;
F_662 ( V_137 , & V_1280 ) ;
}
F_664 ( V_137 ) ;
F_189 ( V_137 -> V_5 . V_771 ) ;
F_189 ( V_137 -> V_5 . V_1288 ) ;
F_655 ( V_137 ) ;
F_189 ( F_665 ( V_137 -> V_5 . V_1289 , 1 ) ) ;
}
void F_666 ( struct V_137 * V_137 , struct V_1290 * free ,
struct V_1290 * V_1291 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1292 ; ++ V_3 ) {
if ( ! V_1291 || free -> V_5 . V_1293 [ V_3 ] != V_1291 -> V_5 . V_1293 [ V_3 ] ) {
F_667 ( free -> V_5 . V_1293 [ V_3 ] ) ;
free -> V_5 . V_1293 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1291 || free -> V_5 . V_1294 [ V_3 - 1 ] !=
V_1291 -> V_5 . V_1294 [ V_3 - 1 ] ) {
F_667 ( free -> V_5 . V_1294 [ V_3 - 1 ] ) ;
free -> V_5 . V_1294 [ V_3 - 1 ] = NULL ;
}
}
}
int F_668 ( struct V_137 * V_137 , struct V_1290 * V_10 ,
unsigned long V_1295 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1292 ; ++ V_3 ) {
unsigned long V_1296 ;
int V_1297 ;
int V_757 = V_3 + 1 ;
V_1297 = F_669 ( V_10 -> V_1298 + V_1295 - 1 ,
V_10 -> V_1298 , V_757 ) + 1 ;
V_10 -> V_5 . V_1293 [ V_3 ] =
F_670 ( V_1297 * sizeof( * V_10 -> V_5 . V_1293 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1293 [ V_3 ] )
goto V_378;
if ( V_3 == 0 )
continue;
V_10 -> V_5 . V_1294 [ V_3 - 1 ] = F_670 ( V_1297 *
sizeof( * V_10 -> V_5 . V_1294 [ V_3 - 1 ] ) ) ;
if ( ! V_10 -> V_5 . V_1294 [ V_3 - 1 ] )
goto V_378;
if ( V_10 -> V_1298 & ( F_671 ( V_757 ) - 1 ) )
V_10 -> V_5 . V_1294 [ V_3 - 1 ] [ 0 ] . V_1299 = 1 ;
if ( ( V_10 -> V_1298 + V_1295 ) & ( F_671 ( V_757 ) - 1 ) )
V_10 -> V_5 . V_1294 [ V_3 - 1 ] [ V_1297 - 1 ] . V_1299 = 1 ;
V_1296 = V_10 -> V_1300 >> V_106 ;
if ( ( V_10 -> V_1298 ^ V_1296 ) & ( F_671 ( V_757 ) - 1 ) ||
! F_672 () ) {
unsigned long V_802 ;
for ( V_802 = 0 ; V_802 < V_1297 ; ++ V_802 )
V_10 -> V_5 . V_1294 [ V_3 - 1 ] [ V_802 ] . V_1299 = 1 ;
}
}
return 0 ;
V_378:
for ( V_3 = 0 ; V_3 < V_1292 ; ++ V_3 ) {
F_667 ( V_10 -> V_5 . V_1293 [ V_3 ] ) ;
V_10 -> V_5 . V_1293 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_667 ( V_10 -> V_5 . V_1294 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1294 [ V_3 - 1 ] = NULL ;
}
return - V_377 ;
}
void F_673 ( struct V_137 * V_137 , struct V_1301 * V_1302 )
{
F_674 ( V_137 , V_1302 ) ;
}
int F_675 ( struct V_137 * V_137 ,
struct V_1290 * V_1303 ,
const struct V_1279 * V_1280 ,
enum V_1304 V_1305 )
{
if ( ( V_1303 -> V_1240 >= V_555 ) && ( V_1305 == V_1306 ) ) {
unsigned long V_1300 ;
V_1300 = F_676 ( NULL , 0 , V_1303 -> V_1295 * V_107 ,
V_1307 | V_1308 ,
V_1309 | V_1310 , 0 ) ;
if ( F_186 ( ( void * ) V_1300 ) )
return F_187 ( ( void * ) V_1300 ) ;
V_1303 -> V_1300 = V_1300 ;
}
return 0 ;
}
static void F_677 ( struct V_137 * V_137 ,
struct V_1290 * V_858 )
{
if ( V_858 -> V_294 & V_1311 ) {
F_678 ( V_137 , V_858 ) ;
return;
}
if ( V_858 -> V_294 & V_1312 ) {
if ( V_73 -> V_1313 )
V_73 -> V_1313 ( V_137 , V_858 ) ;
else
F_678 ( V_137 , V_858 ) ;
} else {
if ( V_73 -> V_1314 )
V_73 -> V_1314 ( V_137 , V_858 ) ;
}
}
void F_679 ( struct V_137 * V_137 ,
const struct V_1279 * V_1280 ,
const struct V_1290 * V_857 ,
const struct V_1290 * V_858 ,
enum V_1304 V_1305 )
{
int V_1315 = 0 ;
if ( V_1305 == V_1316 && V_857 -> V_1240 >= V_555 ) {
int V_108 ;
V_108 = F_680 ( V_857 -> V_1300 ,
V_857 -> V_1295 * V_107 ) ;
if ( V_108 < 0 )
F_10 ( V_864
L_31
L_32 ) ;
}
if ( ! V_137 -> V_5 . V_724 )
V_1315 = F_681 ( V_137 ) ;
if ( V_1315 )
F_298 ( V_137 , V_1315 ) ;
if ( ( V_1305 != V_1316 ) &&
( V_857 -> V_294 & V_1312 ) &&
! ( V_858 -> V_294 & V_1312 ) )
F_682 ( V_137 , V_858 ) ;
if ( V_1305 != V_1316 )
F_677 ( V_137 , (struct V_1290 * ) V_858 ) ;
}
void F_683 ( struct V_137 * V_137 )
{
F_684 ( V_137 ) ;
}
void F_685 ( struct V_137 * V_137 ,
struct V_1290 * V_10 )
{
F_684 ( V_137 ) ;
}
int F_576 ( struct V_1 * V_2 )
{
if ( F_443 ( V_2 ) && V_73 -> V_1085 )
V_73 -> V_1085 ( V_2 , false ) ;
return ( V_2 -> V_5 . V_1034 == V_1145 &&
! V_2 -> V_5 . V_6 . V_1119 )
|| ! F_686 ( & V_2 -> V_1317 . V_1318 )
|| F_687 ( V_2 )
|| V_2 -> V_5 . V_1143 . V_1144
|| F_138 ( & V_2 -> V_5 . V_85 ) ||
( F_522 ( V_2 ) &&
F_521 ( V_2 ) ) ;
}
int F_688 ( struct V_1 * V_2 )
{
return F_689 ( V_2 ) == V_1129 ;
}
int F_522 ( struct V_1 * V_2 )
{
return V_73 -> V_1087 ( V_2 ) ;
}
unsigned long F_457 ( struct V_1 * V_2 )
{
if ( F_512 ( V_2 ) )
return F_435 ( V_2 ) ;
return ( T_1 ) ( F_386 ( V_2 , V_1096 ) +
F_435 ( V_2 ) ) ;
}
bool F_690 ( struct V_1 * V_2 , unsigned long V_1319 )
{
return F_457 ( V_2 ) == V_1319 ;
}
unsigned long F_434 ( struct V_1 * V_2 )
{
unsigned long V_955 ;
V_955 = V_73 -> V_985 ( V_2 ) ;
if ( V_2 -> V_175 & V_958 )
V_955 &= ~ V_957 ;
return V_955 ;
}
static void F_464 ( struct V_1 * V_2 , unsigned long V_955 )
{
if ( V_2 -> V_175 & V_958 &&
F_690 ( V_2 , V_2 -> V_5 . V_962 ) )
V_955 |= V_957 ;
V_73 -> V_1320 ( V_2 , V_955 ) ;
}
void F_440 ( struct V_1 * V_2 , unsigned long V_955 )
{
F_464 ( V_2 , V_955 ) ;
F_31 ( V_67 , V_2 ) ;
}
void F_691 ( struct V_1 * V_2 , struct V_1321 * V_348 )
{
int V_119 ;
if ( ( V_2 -> V_5 . V_84 . V_947 != V_348 -> V_5 . V_947 ) ||
V_348 -> V_1322 )
return;
V_119 = F_560 ( V_2 ) ;
if ( F_155 ( V_119 ) )
return;
if ( ! V_2 -> V_5 . V_84 . V_947 &&
V_348 -> V_5 . V_104 != V_2 -> V_5 . V_84 . V_1323 ( V_2 ) )
return;
V_2 -> V_5 . V_84 . V_1324 ( V_2 , V_348 -> V_816 , 0 , true ) ;
}
static inline T_1 F_692 ( T_5 V_102 )
{
return F_693 ( V_102 & 0xffffffff , F_694 ( V_4 ) ) ;
}
static inline T_1 F_695 ( T_1 V_1325 )
{
return ( V_1325 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_696 ( struct V_1 * V_2 , T_5 V_102 )
{
T_1 V_1325 = F_692 ( V_102 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1325 ] != ~ 0 )
V_1325 = F_695 ( V_1325 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1325 ] = V_102 ;
}
static T_1 F_697 ( struct V_1 * V_2 , T_5 V_102 )
{
int V_3 ;
T_1 V_1325 = F_692 ( V_102 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1325 ] != V_102 &&
V_2 -> V_5 . V_6 . V_7 [ V_1325 ] != ~ 0 ) ; V_3 ++ )
V_1325 = F_695 ( V_1325 ) ;
return V_1325 ;
}
bool F_698 ( struct V_1 * V_2 , T_5 V_102 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_697 ( V_2 , V_102 ) ] == V_102 ;
}
static void F_699 ( struct V_1 * V_2 , T_5 V_102 )
{
T_1 V_3 , V_802 , V_1326 ;
V_3 = V_802 = F_697 ( V_2 , V_102 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_802 = F_695 ( V_802 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_802 ] == ~ 0 )
return;
V_1326 = F_692 ( V_2 -> V_5 . V_6 . V_7 [ V_802 ] ) ;
} while ( ( V_3 <= V_802 ) ? ( V_3 < V_1326 && V_1326 <= V_802 ) : ( V_3 < V_1326 || V_1326 <= V_802 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_802 ] ;
V_3 = V_802 ;
}
}
static int F_700 ( struct V_1 * V_2 , T_1 V_192 )
{
return F_174 ( V_2 -> V_137 , & V_2 -> V_5 . V_6 . V_38 , & V_192 ,
sizeof( V_192 ) ) ;
}
void F_701 ( struct V_1 * V_2 ,
struct V_1321 * V_348 )
{
struct V_75 V_76 ;
F_702 ( V_348 -> V_5 . V_1327 , V_348 -> V_816 ) ;
F_696 ( V_2 , V_348 -> V_5 . V_102 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_407 & V_408 ) ||
( V_2 -> V_5 . V_6 . V_409 &&
V_73 -> V_88 ( V_2 ) == 0 ) )
F_31 ( V_1118 , V_2 ) ;
else if ( ! F_700 ( V_2 , V_1328 ) ) {
V_76 . V_41 = V_42 ;
V_76 . V_917 = true ;
V_76 . V_62 = 0 ;
V_76 . V_81 = false ;
V_76 . V_80 = V_348 -> V_5 . V_1327 ;
F_37 ( V_2 , & V_76 ) ;
}
}
void F_703 ( struct V_1 * V_2 ,
struct V_1321 * V_348 )
{
struct V_75 V_76 ;
F_704 ( V_348 -> V_5 . V_1327 , V_348 -> V_816 ) ;
if ( V_348 -> V_1322 )
V_348 -> V_5 . V_1327 = ~ 0 ;
else
F_699 ( V_2 , V_348 -> V_5 . V_102 ) ;
if ( ( V_2 -> V_5 . V_6 . V_407 & V_408 ) &&
! F_700 ( V_2 , V_1329 ) ) {
V_76 . V_41 = V_42 ;
V_76 . V_917 = true ;
V_76 . V_62 = 0 ;
V_76 . V_81 = false ;
V_76 . V_80 = V_348 -> V_5 . V_1327 ;
F_37 ( V_2 , & V_76 ) ;
}
V_2 -> V_5 . V_6 . V_1119 = false ;
V_2 -> V_5 . V_1034 = V_1145 ;
}
bool F_705 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_407 & V_408 ) )
return true ;
else
return ! F_524 ( V_2 ) &&
V_73 -> V_1087 ( V_2 ) ;
}
void F_706 ( struct V_137 * V_137 )
{
F_42 ( & V_137 -> V_5 . V_1330 ) ;
}
void F_707 ( struct V_137 * V_137 )
{
F_708 ( & V_137 -> V_5 . V_1330 ) ;
}
bool F_709 ( struct V_137 * V_137 )
{
return F_138 ( & V_137 -> V_5 . V_1330 ) ;
}
void F_710 ( struct V_137 * V_137 )
{
F_42 ( & V_137 -> V_5 . V_1274 ) ;
}
void F_711 ( struct V_137 * V_137 )
{
F_708 ( & V_137 -> V_5 . V_1274 ) ;
}
bool F_248 ( struct V_137 * V_137 )
{
return F_138 ( & V_137 -> V_5 . V_1274 ) ;
}
