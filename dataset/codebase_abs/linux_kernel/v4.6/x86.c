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
V_15 . V_19 [ V_10 ] = V_21 ;
if ( V_10 >= V_15 . V_16 )
V_15 . V_16 = V_10 + 1 ;
}
static void F_14 ( void )
{
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_15 . V_16 ; ++ V_3 )
F_7 ( V_3 , V_15 . V_19 [ V_3 ] ) ;
}
int F_15 ( unsigned V_10 , T_2 V_22 , T_2 V_28 )
{
unsigned int V_23 = F_8 () ;
struct V_11 * V_24 = F_9 ( V_25 , V_23 ) ;
int V_29 ;
if ( ( ( V_22 ^ V_24 -> V_14 [ V_10 ] . V_18 ) & V_28 ) == 0 )
return 0 ;
V_24 -> V_14 [ V_10 ] . V_18 = V_22 ;
V_29 = F_16 ( V_15 . V_19 [ V_10 ] , V_22 ) ;
if ( V_29 )
return 1 ;
if ( ! V_24 -> V_20 ) {
V_24 -> V_9 . V_30 = F_3 ;
F_17 ( & V_24 -> V_9 ) ;
V_24 -> V_20 = true ;
}
return 0 ;
}
static void F_18 ( void )
{
unsigned int V_23 = F_8 () ;
struct V_11 * V_24 = F_9 ( V_25 , V_23 ) ;
if ( V_24 -> V_20 )
F_3 ( & V_24 -> V_9 ) ;
}
T_2 F_19 ( struct V_1 * V_2 )
{
return V_2 -> V_5 . V_31 ;
}
int F_20 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
T_2 V_34 = V_2 -> V_5 . V_31 &
( V_35 | V_36 ) ;
T_2 V_37 = V_33 -> V_38 &
( V_35 | V_36 ) ;
T_2 V_39 = ( ( ~ 0ULL ) << F_21 ( V_2 ) ) |
0x2ff | ( F_22 ( V_2 ) ? 0 : V_36 ) ;
if ( ! V_33 -> V_40 &&
( ( V_33 -> V_38 & V_39 ) != 0 ||
V_37 == V_36 ||
( V_37 == V_35 &&
V_34 == ( V_35 | V_36 ) ) ||
( V_37 == ( V_35 | V_36 ) &&
V_34 == 0 ) ) )
return 1 ;
F_23 ( V_2 , V_33 -> V_38 ) ;
return 0 ;
}
T_3 T_4 void F_24 ( void )
{
F_25 () ;
}
static int F_26 ( int V_41 )
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
static int F_27 ( int V_41 )
{
unsigned int V_28 ;
if ( F_28 ( V_41 > 31 || V_41 == V_51 ) )
return V_52 ;
V_28 = 1 << V_41 ;
if ( V_28 & ( ( 1 << V_53 ) | ( 1 << V_54 ) | ( 1 << V_55 ) ) )
return V_56 ;
if ( V_28 & ( ( 1 << V_57 ) | ( 1 << V_58 ) ) )
return V_59 ;
return V_60 ;
}
static void F_29 ( struct V_1 * V_2 ,
unsigned V_16 , bool V_61 , T_1 V_62 ,
bool V_63 )
{
T_1 V_64 ;
int V_65 , V_66 ;
F_30 ( V_67 , V_2 ) ;
if ( ! V_2 -> V_5 . V_68 . V_69 ) {
V_70:
if ( V_61 && ! F_31 ( V_2 ) )
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
F_30 ( V_72 , V_2 ) ;
return;
}
V_65 = F_26 ( V_64 ) ;
V_66 = F_26 ( V_16 ) ;
if ( ( V_65 == V_49 && V_66 == V_49 )
|| ( V_65 == V_43 && V_66 != V_50 ) ) {
V_2 -> V_5 . V_68 . V_69 = true ;
V_2 -> V_5 . V_68 . V_71 = true ;
V_2 -> V_5 . V_68 . V_16 = V_57 ;
V_2 -> V_5 . V_68 . V_62 = 0 ;
} else
goto V_70;
}
void F_32 ( struct V_1 * V_2 , unsigned V_16 )
{
F_29 ( V_2 , V_16 , false , 0 , false ) ;
}
void F_33 ( struct V_1 * V_2 , unsigned V_16 )
{
F_29 ( V_2 , V_16 , false , 0 , true ) ;
}
void F_34 ( struct V_1 * V_2 , int V_29 )
{
if ( V_29 )
F_35 ( V_2 , 0 ) ;
else
V_73 -> V_74 ( V_2 ) ;
}
void F_36 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
++ V_2 -> V_77 . V_78 ;
V_2 -> V_5 . V_79 = V_76 -> V_80 ;
F_37 ( V_2 , V_42 , V_76 -> V_62 ) ;
}
static bool F_38 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
if ( F_39 ( V_2 ) && ! V_76 -> V_81 )
V_2 -> V_5 . V_82 . V_83 ( V_2 , V_76 ) ;
else
V_2 -> V_5 . V_84 . V_83 ( V_2 , V_76 ) ;
return V_76 -> V_81 ;
}
void F_40 ( struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_5 . V_85 ) ;
F_30 ( V_86 , V_2 ) ;
}
void F_37 ( struct V_1 * V_2 , unsigned V_16 , T_1 V_62 )
{
F_29 ( V_2 , V_16 , true , V_62 , false ) ;
}
void F_42 ( struct V_1 * V_2 , unsigned V_16 , T_1 V_62 )
{
F_29 ( V_2 , V_16 , true , V_62 , true ) ;
}
bool F_43 ( struct V_1 * V_2 , int V_87 )
{
if ( V_73 -> V_88 ( V_2 ) <= V_87 )
return true ;
F_37 ( V_2 , V_48 , 0 ) ;
return false ;
}
bool F_44 ( struct V_1 * V_2 , int V_89 )
{
if ( ( V_89 != 4 && V_89 != 5 ) || ! F_45 ( V_2 , V_90 ) )
return true ;
F_32 ( V_2 , V_91 ) ;
return false ;
}
int F_46 ( struct V_1 * V_2 , struct V_92 * V_84 ,
T_5 V_93 , void * V_38 , int V_94 , int V_95 ,
T_1 V_96 )
{
struct V_75 V_68 ;
T_5 V_97 ;
T_6 V_98 ;
V_98 = F_47 ( V_93 ) ;
V_97 = V_84 -> V_99 ( V_2 , V_98 , V_96 , & V_68 ) ;
if ( V_97 == V_100 )
return - V_101 ;
V_97 = F_48 ( V_97 ) ;
return F_49 ( V_2 , V_97 , V_38 , V_94 , V_95 ) ;
}
static int F_50 ( struct V_1 * V_2 , T_5 V_102 ,
void * V_38 , int V_94 , int V_95 , T_1 V_96 )
{
return F_46 ( V_2 , V_2 -> V_5 . V_103 , V_102 ,
V_38 , V_94 , V_95 , V_96 ) ;
}
int F_51 ( struct V_1 * V_2 , struct V_92 * V_84 , unsigned long V_104 )
{
T_5 V_105 = V_104 >> V_106 ;
unsigned V_94 = ( ( V_104 & ( V_107 - 1 ) ) >> 5 ) << 2 ;
int V_3 ;
int V_108 ;
T_2 V_109 [ F_52 ( V_84 -> V_110 ) ] ;
V_108 = F_46 ( V_2 , V_84 , V_105 , V_109 ,
V_94 * sizeof( T_2 ) , sizeof( V_109 ) ,
V_111 | V_112 ) ;
if ( V_108 < 0 ) {
V_108 = 0 ;
goto V_113;
}
for ( V_3 = 0 ; V_3 < F_52 ( V_109 ) ; ++ V_3 ) {
if ( F_53 ( V_109 [ V_3 ] ) &&
( V_109 [ V_3 ] &
V_2 -> V_5 . V_84 . V_114 . V_115 [ 0 ] [ 2 ] ) ) {
V_108 = 0 ;
goto V_113;
}
}
V_108 = 1 ;
memcpy ( V_84 -> V_110 , V_109 , sizeof( V_84 -> V_110 ) ) ;
F_54 ( V_116 ,
( unsigned long * ) & V_2 -> V_5 . V_117 ) ;
F_54 ( V_116 ,
( unsigned long * ) & V_2 -> V_5 . V_118 ) ;
V_113:
return V_108 ;
}
static bool F_55 ( struct V_1 * V_2 )
{
T_2 V_109 [ F_52 ( V_2 -> V_5 . V_103 -> V_110 ) ] ;
bool V_119 = true ;
int V_94 ;
T_5 V_102 ;
int V_120 ;
if ( F_56 ( V_2 ) || ! F_57 ( V_2 ) )
return false ;
if ( ! F_58 ( V_116 ,
( unsigned long * ) & V_2 -> V_5 . V_117 ) )
return true ;
V_102 = ( F_59 ( V_2 ) & ~ 31u ) >> V_106 ;
V_94 = ( F_59 ( V_2 ) & ~ 31u ) & ( V_107 - 1 ) ;
V_120 = F_50 ( V_2 , V_102 , V_109 , V_94 , sizeof( V_109 ) ,
V_111 | V_112 ) ;
if ( V_120 < 0 )
goto V_113;
V_119 = memcmp ( V_109 , V_2 -> V_5 . V_103 -> V_110 , sizeof( V_109 ) ) != 0 ;
V_113:
return V_119 ;
}
int F_60 ( struct V_1 * V_2 , unsigned long V_121 )
{
unsigned long V_122 = F_61 ( V_2 ) ;
unsigned long V_123 = V_124 | V_125 ;
V_121 |= V_126 ;
#ifdef F_62
if ( V_121 & 0xffffffff00000000UL )
return 1 ;
#endif
V_121 &= ~ V_127 ;
if ( ( V_121 & V_128 ) && ! ( V_121 & V_129 ) )
return 1 ;
if ( ( V_121 & V_124 ) && ! ( V_121 & V_130 ) )
return 1 ;
if ( ! F_63 ( V_2 ) && ( V_121 & V_124 ) ) {
#ifdef F_62
if ( ( V_2 -> V_5 . V_131 & V_132 ) ) {
int V_133 , V_134 ;
if ( ! F_57 ( V_2 ) )
return 1 ;
V_73 -> V_135 ( V_2 , & V_133 , & V_134 ) ;
if ( V_134 )
return 1 ;
} else
#endif
if ( F_57 ( V_2 ) && ! F_51 ( V_2 , V_2 -> V_5 . V_103 ,
F_59 ( V_2 ) ) )
return 1 ;
}
if ( ! ( V_121 & V_124 ) && F_45 ( V_2 , V_136 ) )
return 1 ;
V_73 -> V_137 ( V_2 , V_121 ) ;
if ( ( V_121 ^ V_122 ) & V_124 ) {
F_64 ( V_2 ) ;
F_1 ( V_2 ) ;
}
if ( ( V_121 ^ V_122 ) & V_123 )
F_65 ( V_2 ) ;
if ( ( ( V_121 ^ V_122 ) & V_129 ) &&
F_66 ( V_2 -> V_138 ) &&
! F_67 ( V_2 -> V_138 , V_139 ) )
F_68 ( V_2 -> V_138 , 0 , ~ 0ULL ) ;
return 0 ;
}
void F_69 ( struct V_1 * V_2 , unsigned long V_140 )
{
( void ) F_60 ( V_2 , F_70 ( V_2 , ~ 0x0eul ) | ( V_140 & 0x0f ) ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
if ( F_45 ( V_2 , V_141 ) &&
! V_2 -> V_142 ) {
F_72 ( V_143 , V_2 -> V_5 . V_144 ) ;
V_2 -> V_142 = 1 ;
}
}
static void F_73 ( struct V_1 * V_2 )
{
if ( V_2 -> V_142 ) {
if ( V_2 -> V_5 . V_144 != V_145 )
F_72 ( V_143 , V_145 ) ;
V_2 -> V_142 = 0 ;
}
}
static int F_74 ( struct V_1 * V_2 , T_1 V_146 , T_2 V_147 )
{
T_2 V_144 = V_147 ;
T_2 V_148 = V_2 -> V_5 . V_144 ;
T_2 V_149 ;
if ( V_146 != V_143 )
return 1 ;
if ( ! ( V_144 & V_150 ) )
return 1 ;
if ( ( V_144 & V_151 ) && ! ( V_144 & V_152 ) )
return 1 ;
V_149 = V_2 -> V_5 . V_153 | V_150 ;
if ( V_144 & ~ V_149 )
return 1 ;
if ( ( ! ( V_144 & V_154 ) ) !=
( ! ( V_144 & V_155 ) ) )
return 1 ;
if ( V_144 & V_156 ) {
if ( ! ( V_144 & V_151 ) )
return 1 ;
if ( ( V_144 & V_156 ) != V_156 )
return 1 ;
}
V_2 -> V_5 . V_144 = V_144 ;
if ( ( V_144 ^ V_148 ) & V_157 )
F_75 ( V_2 ) ;
return 0 ;
}
int F_76 ( struct V_1 * V_2 , T_1 V_146 , T_2 V_147 )
{
if ( V_73 -> V_88 ( V_2 ) != 0 ||
F_74 ( V_2 , V_146 , V_147 ) ) {
F_35 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_77 ( struct V_1 * V_2 , unsigned long V_158 )
{
unsigned long V_159 = F_78 ( V_2 ) ;
unsigned long V_160 = V_161 | V_162 | V_163 |
V_164 | V_165 | V_166 ;
if ( V_158 & V_167 )
return 1 ;
if ( ! F_79 ( V_2 ) && ( V_158 & V_141 ) )
return 1 ;
if ( ! F_80 ( V_2 ) && ( V_158 & V_164 ) )
return 1 ;
if ( ! F_81 ( V_2 ) && ( V_158 & V_165 ) )
return 1 ;
if ( ! F_82 ( V_2 ) && ( V_158 & V_168 ) )
return 1 ;
if ( ! F_83 ( V_2 ) && ( V_158 & V_166 ) )
return 1 ;
if ( F_56 ( V_2 ) ) {
if ( ! ( V_158 & V_163 ) )
return 1 ;
} else if ( F_63 ( V_2 ) && ( V_158 & V_163 )
&& ( ( V_158 ^ V_159 ) & V_160 )
&& ! F_51 ( V_2 , V_2 -> V_5 . V_103 ,
F_59 ( V_2 ) ) )
return 1 ;
if ( ( V_158 & V_136 ) && ! ( V_159 & V_136 ) ) {
if ( ! F_84 ( V_2 ) )
return 1 ;
if ( ( F_59 ( V_2 ) & V_169 ) || ! F_56 ( V_2 ) )
return 1 ;
}
if ( V_73 -> V_170 ( V_2 , V_158 ) )
return 1 ;
if ( ( ( V_158 ^ V_159 ) & V_160 ) ||
( ! ( V_158 & V_136 ) && ( V_159 & V_136 ) ) )
F_65 ( V_2 ) ;
if ( ( V_158 ^ V_159 ) & ( V_141 | V_166 ) )
F_75 ( V_2 ) ;
return 0 ;
}
int F_85 ( struct V_1 * V_2 , unsigned long V_104 )
{
#ifdef F_62
V_104 &= ~ V_171 ;
#endif
if ( V_104 == F_59 ( V_2 ) && ! F_55 ( V_2 ) ) {
F_86 ( V_2 ) ;
F_30 ( V_172 , V_2 ) ;
return 0 ;
}
if ( F_56 ( V_2 ) ) {
if ( V_104 & V_173 )
return 1 ;
} else if ( F_57 ( V_2 ) && F_63 ( V_2 ) &&
! F_51 ( V_2 , V_2 -> V_5 . V_103 , V_104 ) )
return 1 ;
V_2 -> V_5 . V_104 = V_104 ;
F_54 ( V_174 , ( V_175 * ) & V_2 -> V_5 . V_117 ) ;
F_87 ( V_2 ) ;
return 0 ;
}
int F_88 ( struct V_1 * V_2 , unsigned long V_176 )
{
if ( V_176 & V_177 )
return 1 ;
if ( F_89 ( V_2 ) )
F_90 ( V_2 , V_176 ) ;
else
V_2 -> V_5 . V_176 = V_176 ;
return 0 ;
}
unsigned long F_91 ( struct V_1 * V_2 )
{
if ( F_89 ( V_2 ) )
return F_92 ( V_2 ) ;
else
return V_2 -> V_5 . V_176 ;
}
static void F_93 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! ( V_2 -> V_178 & V_179 ) ) {
for ( V_3 = 0 ; V_3 < V_180 ; V_3 ++ )
V_2 -> V_5 . V_181 [ V_3 ] = V_2 -> V_5 . V_182 [ V_3 ] ;
V_2 -> V_5 . V_183 |= V_184 ;
}
}
static void F_94 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_178 & V_179 ) )
V_73 -> V_185 ( V_2 , V_2 -> V_5 . V_186 ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
unsigned long V_187 ;
if ( V_2 -> V_178 & V_179 )
V_187 = V_2 -> V_5 . V_188 ;
else
V_187 = V_2 -> V_5 . V_187 ;
V_73 -> V_189 ( V_2 , V_187 ) ;
V_2 -> V_5 . V_183 &= ~ V_190 ;
if ( V_187 & V_191 )
V_2 -> V_5 . V_183 |= V_190 ;
}
static T_2 F_96 ( struct V_1 * V_2 )
{
T_2 V_192 = V_193 ;
if ( ! F_97 ( V_2 ) )
V_192 |= V_194 ;
return V_192 ;
}
static int F_98 ( struct V_1 * V_2 , int V_89 , unsigned long V_195 )
{
switch ( V_89 ) {
case 0 ... 3 :
V_2 -> V_5 . V_182 [ V_89 ] = V_195 ;
if ( ! ( V_2 -> V_178 & V_179 ) )
V_2 -> V_5 . V_181 [ V_89 ] = V_195 ;
break;
case 4 :
case 6 :
if ( V_195 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_186 = ( V_195 & V_196 ) | F_96 ( V_2 ) ;
F_94 ( V_2 ) ;
break;
case 5 :
default:
if ( V_195 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_187 = ( V_195 & V_197 ) | V_198 ;
F_95 ( V_2 ) ;
break;
}
return 0 ;
}
int F_99 ( struct V_1 * V_2 , int V_89 , unsigned long V_195 )
{
if ( F_98 ( V_2 , V_89 , V_195 ) ) {
F_35 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_100 ( struct V_1 * V_2 , int V_89 , unsigned long * V_195 )
{
switch ( V_89 ) {
case 0 ... 3 :
* V_195 = V_2 -> V_5 . V_182 [ V_89 ] ;
break;
case 4 :
case 6 :
if ( V_2 -> V_178 & V_179 )
* V_195 = V_2 -> V_5 . V_186 ;
else
* V_195 = V_73 -> V_199 ( V_2 ) ;
break;
case 5 :
default:
* V_195 = V_2 -> V_5 . V_187 ;
break;
}
return 0 ;
}
bool F_101 ( struct V_1 * V_2 )
{
T_1 V_200 = F_102 ( V_2 , V_201 ) ;
T_2 V_38 ;
int V_29 ;
V_29 = F_103 ( V_2 , V_200 , & V_38 ) ;
if ( V_29 )
return V_29 ;
F_104 ( V_2 , V_202 , ( T_1 ) V_38 ) ;
F_104 ( V_2 , V_203 , V_38 >> 32 ) ;
return V_29 ;
}
bool F_105 ( struct V_1 * V_2 , T_2 V_131 )
{
if ( V_131 & V_204 )
return false ;
if ( V_131 & V_205 ) {
struct V_206 * V_207 ;
V_207 = F_106 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_207 || ! ( V_207 -> V_208 & F_107 ( V_209 ) ) )
return false ;
}
if ( V_131 & V_210 ) {
struct V_206 * V_207 ;
V_207 = F_106 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_207 || ! ( V_207 -> V_200 & F_107 ( V_211 ) ) )
return false ;
}
return true ;
}
static int F_108 ( struct V_1 * V_2 , T_2 V_131 )
{
T_2 V_212 = V_2 -> V_5 . V_131 ;
if ( ! F_105 ( V_2 , V_131 ) )
return 1 ;
if ( F_63 ( V_2 )
&& ( V_2 -> V_5 . V_131 & V_132 ) != ( V_131 & V_132 ) )
return 1 ;
V_131 &= ~ V_213 ;
V_131 |= V_2 -> V_5 . V_131 & V_213 ;
V_73 -> F_108 ( V_2 , V_131 ) ;
if ( ( V_131 ^ V_212 ) & V_214 )
F_65 ( V_2 ) ;
return 0 ;
}
void F_109 ( T_2 V_28 )
{
V_204 &= ~ V_28 ;
}
int F_110 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
switch ( V_21 -> V_146 ) {
case V_215 :
case V_216 :
case V_217 :
case V_218 :
case V_219 :
if ( F_111 ( V_21 -> V_38 ) )
return 1 ;
break;
case V_220 :
case V_221 :
V_21 -> V_38 = F_112 ( V_21 -> V_38 ) ;
}
return V_73 -> V_222 ( V_2 , V_21 ) ;
}
static int F_113 ( struct V_1 * V_2 , unsigned V_146 , T_2 * V_38 )
{
struct V_32 V_21 ;
int V_120 ;
V_21 . V_146 = V_146 ;
V_21 . V_40 = true ;
V_120 = F_114 ( V_2 , & V_21 ) ;
if ( V_120 )
return V_120 ;
* V_38 = V_21 . V_38 ;
return 0 ;
}
static int F_115 ( struct V_1 * V_2 , unsigned V_146 , T_2 * V_38 )
{
struct V_32 V_21 ;
V_21 . V_38 = * V_38 ;
V_21 . V_146 = V_146 ;
V_21 . V_40 = true ;
return F_110 ( V_2 , & V_21 ) ;
}
static void F_116 ( struct V_223 * V_224 )
{
struct V_225 * V_226 = & V_225 ;
T_2 V_227 ;
V_227 = F_117 ( F_118 ( V_224 -> V_228 . V_229 , V_224 -> V_230 ) ) ;
F_119 ( & V_226 -> V_231 ) ;
V_226 -> clock . V_232 = V_224 -> V_228 . clock -> V_233 . V_232 ;
V_226 -> clock . V_234 = V_224 -> V_228 . V_234 ;
V_226 -> clock . V_28 = V_224 -> V_228 . V_28 ;
V_226 -> clock . V_235 = V_224 -> V_228 . V_235 ;
V_226 -> clock . V_236 = V_224 -> V_228 . V_236 ;
V_226 -> V_227 = V_227 ;
V_226 -> V_237 = V_224 -> V_228 . V_238 ;
F_120 ( & V_226 -> V_231 ) ;
}
void F_121 ( struct V_1 * V_2 )
{
F_30 ( V_239 , V_2 ) ;
}
static void F_122 ( struct V_138 * V_138 , T_6 V_240 )
{
int V_241 ;
int V_120 ;
struct V_242 V_243 ;
struct V_244 V_245 ;
if ( ! V_240 )
return;
V_120 = F_123 ( V_138 , V_240 , & V_241 , sizeof( V_241 ) ) ;
if ( V_120 )
return;
if ( V_241 & 1 )
++ V_241 ;
++ V_241 ;
if ( F_124 ( V_138 , V_240 , & V_241 , sizeof( V_241 ) ) )
return;
F_125 ( & V_245 ) ;
if ( V_138 -> V_5 . V_246 ) {
struct V_244 V_247 = F_126 ( V_138 -> V_5 . V_246 ) ;
V_245 = F_127 ( V_245 , V_247 ) ;
}
V_243 . V_248 = V_245 . V_249 ;
V_243 . V_250 = V_245 . V_251 ;
V_243 . V_241 = V_241 ;
F_124 ( V_138 , V_240 , & V_243 , sizeof( V_243 ) ) ;
V_241 ++ ;
F_124 ( V_138 , V_240 , & V_241 , sizeof( V_241 ) ) ;
}
static T_7 F_128 ( T_7 V_252 , T_7 V_253 )
{
F_129 ( V_252 , V_253 ) ;
return V_252 ;
}
static void F_130 ( T_8 V_254 , T_8 V_255 ,
T_9 * V_256 , T_1 * V_257 )
{
T_8 V_258 ;
T_10 V_236 = 0 ;
T_8 V_259 ;
T_7 V_260 ;
V_259 = V_255 ;
V_258 = V_254 ;
while ( V_259 > V_258 * 2 || V_259 & 0xffffffff00000000ULL ) {
V_259 >>= 1 ;
V_236 -- ;
}
V_260 = ( T_7 ) V_259 ;
while ( V_260 <= V_258 || V_258 & 0xffffffff00000000ULL ) {
if ( V_258 & 0xffffffff00000000ULL || V_260 & 0x80000000 )
V_258 >>= 1 ;
else
V_260 <<= 1 ;
V_236 ++ ;
}
* V_256 = V_236 ;
* V_257 = F_128 ( V_258 , V_260 ) ;
F_131 ( L_2 ,
V_261 , V_255 , V_254 , V_236 , * V_257 ) ;
}
static inline T_2 F_132 ( struct V_1 * V_2 , T_2 V_250 )
{
return F_133 ( V_250 , V_2 -> V_5 . V_262 ,
V_2 -> V_5 . V_263 ) ;
}
static T_1 F_134 ( T_1 V_264 , T_11 V_265 )
{
T_2 V_266 = ( T_2 ) V_264 * ( 1000000 + V_265 ) ;
F_135 ( V_266 , 1000000 ) ;
return V_266 ;
}
static int F_136 ( struct V_1 * V_2 , T_1 V_267 , bool V_268 )
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
F_137 ( 1 , L_3 ) ;
return - 1 ;
}
}
V_269 = F_138 ( 1ULL << V_276 ,
V_267 , V_273 ) ;
if ( V_269 == 0 || V_269 >= V_277 ) {
F_139 ( 1 , L_4 ,
V_267 ) ;
return - 1 ;
}
V_2 -> V_5 . V_270 = V_269 ;
return 0 ;
}
static int F_140 ( struct V_1 * V_2 , T_1 V_267 )
{
T_1 V_278 , V_279 ;
int V_280 = 0 ;
if ( V_267 == 0 ) {
V_2 -> V_5 . V_270 = V_271 ;
return - 1 ;
}
F_130 ( V_267 * 1000LL , V_281 ,
& V_2 -> V_5 . V_263 ,
& V_2 -> V_5 . V_262 ) ;
V_2 -> V_5 . V_282 = V_267 ;
V_278 = F_134 ( V_273 , - V_283 ) ;
V_279 = F_134 ( V_273 , V_283 ) ;
if ( V_267 < V_278 || V_267 > V_279 ) {
F_131 ( L_5 , V_267 , V_278 , V_279 ) ;
V_280 = 1 ;
}
return F_136 ( V_2 , V_267 , V_280 ) ;
}
static T_2 F_141 ( struct V_1 * V_2 , T_12 V_284 )
{
T_2 V_285 = F_133 ( V_284 - V_2 -> V_5 . V_286 ,
V_2 -> V_5 . V_262 ,
V_2 -> V_5 . V_263 ) ;
V_285 += V_2 -> V_5 . V_287 ;
return V_285 ;
}
static void F_142 ( struct V_1 * V_2 )
{
#ifdef F_62
bool V_288 ;
struct V_289 * V_290 = & V_2 -> V_138 -> V_5 ;
struct V_225 * V_291 = & V_225 ;
V_288 = ( V_290 -> V_292 + 1 ==
F_143 ( & V_2 -> V_138 -> V_293 ) ) ;
if ( V_290 -> V_294 ||
( V_291 -> clock . V_232 == V_295 && V_288 ) )
F_30 ( V_296 , V_2 ) ;
F_144 ( V_2 -> V_297 , V_290 -> V_292 ,
F_143 ( & V_2 -> V_138 -> V_293 ) ,
V_290 -> V_294 , V_291 -> clock . V_232 ) ;
#endif
}
static void F_145 ( struct V_1 * V_2 , T_12 V_94 )
{
T_2 V_298 = V_73 -> V_299 ( V_2 ) ;
V_2 -> V_5 . V_300 += V_94 - V_298 ;
}
static inline T_2 F_146 ( T_2 V_269 , T_2 V_285 )
{
return F_147 ( V_285 , V_269 , V_276 ) ;
}
T_2 F_148 ( struct V_1 * V_2 , T_2 V_285 )
{
T_2 V_301 = V_285 ;
T_2 V_269 = V_2 -> V_5 . V_270 ;
if ( V_269 != V_271 )
V_301 = F_146 ( V_269 , V_285 ) ;
return V_301 ;
}
static T_2 F_149 ( struct V_1 * V_2 , T_2 V_302 )
{
T_2 V_285 ;
V_285 = F_148 ( V_2 , F_150 () ) ;
return V_302 - V_285 ;
}
T_2 F_151 ( struct V_1 * V_2 , T_2 V_303 )
{
return V_73 -> V_304 ( V_2 , F_148 ( V_2 , V_303 ) ) ;
}
void F_152 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
struct V_138 * V_138 = V_2 -> V_138 ;
T_2 V_94 , V_305 , V_306 ;
unsigned long V_307 ;
T_12 V_308 ;
bool V_309 ;
bool V_310 ;
T_2 V_38 = V_21 -> V_38 ;
F_153 ( & V_138 -> V_5 . V_311 , V_307 ) ;
V_94 = F_149 ( V_2 , V_38 ) ;
V_305 = F_154 () ;
V_306 = V_305 - V_138 -> V_5 . V_312 ;
if ( V_2 -> V_5 . V_282 ) {
int V_313 = 0 ;
V_308 = V_38 - V_138 -> V_5 . V_314 ;
#ifdef F_62
V_308 = ( V_308 * 1000 ) / V_2 -> V_5 . V_282 ;
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
F_135 ( V_306 , 1000 ) ;
V_308 -= V_306 ;
if ( V_308 < 0 )
V_308 = - V_308 ;
if ( V_313 )
V_308 = V_315 ;
} else
V_308 = V_315 ;
if ( V_308 < V_315 &&
V_2 -> V_5 . V_282 == V_138 -> V_5 . V_316 ) {
if ( ! F_155 () ) {
V_94 = V_138 -> V_5 . V_317 ;
F_131 ( L_6 , V_38 ) ;
} else {
T_2 V_318 = F_132 ( V_2 , V_306 ) ;
V_38 += V_318 ;
V_94 = F_149 ( V_2 , V_38 ) ;
F_131 ( L_7 , V_318 ) ;
}
V_309 = true ;
V_310 = ( V_2 -> V_5 . V_319 == V_138 -> V_5 . V_320 ) ;
} else {
V_138 -> V_5 . V_320 ++ ;
V_138 -> V_5 . V_321 = V_305 ;
V_138 -> V_5 . V_322 = V_38 ;
V_138 -> V_5 . V_317 = V_94 ;
V_309 = false ;
F_131 ( L_8 ,
V_138 -> V_5 . V_320 , V_38 ) ;
}
V_138 -> V_5 . V_312 = V_305 ;
V_138 -> V_5 . V_314 = V_38 ;
V_138 -> V_5 . V_316 = V_2 -> V_5 . V_282 ;
V_2 -> V_5 . V_323 = V_38 ;
V_2 -> V_5 . V_319 = V_138 -> V_5 . V_320 ;
V_2 -> V_5 . V_286 = V_138 -> V_5 . V_321 ;
V_2 -> V_5 . V_287 = V_138 -> V_5 . V_322 ;
if ( F_156 ( V_2 ) && ! V_21 -> V_40 )
F_145 ( V_2 , V_94 ) ;
V_73 -> V_324 ( V_2 , V_94 ) ;
F_157 ( & V_138 -> V_5 . V_311 , V_307 ) ;
F_158 ( & V_138 -> V_5 . V_325 ) ;
if ( ! V_309 ) {
V_138 -> V_5 . V_292 = 0 ;
} else if ( ! V_310 ) {
V_138 -> V_5 . V_292 ++ ;
}
F_142 ( V_2 ) ;
F_159 ( & V_138 -> V_5 . V_325 ) ;
}
static inline void F_160 ( struct V_1 * V_2 ,
T_12 V_326 )
{
V_73 -> F_160 ( V_2 , V_326 ) ;
}
static inline void F_161 ( struct V_1 * V_2 , T_12 V_326 )
{
if ( V_2 -> V_5 . V_270 != V_271 )
F_28 ( V_326 < 0 ) ;
V_326 = F_148 ( V_2 , ( T_2 ) V_326 ) ;
V_73 -> F_160 ( V_2 , V_326 ) ;
}
static T_13 F_162 ( void )
{
T_13 V_108 = ( T_13 ) F_163 () ;
T_2 V_327 = V_225 . clock . V_234 ;
if ( F_164 ( V_108 >= V_327 ) )
return V_108 ;
asm volatile ("");
return V_327 ;
}
static inline T_2 F_165 ( T_13 * V_328 )
{
long V_266 ;
struct V_225 * V_291 = & V_225 ;
* V_328 = F_162 () ;
V_266 = ( * V_328 - V_291 -> clock . V_234 ) & V_291 -> clock . V_28 ;
return V_266 * V_291 -> clock . V_235 ;
}
static int F_166 ( T_12 * V_329 , T_13 * V_328 )
{
struct V_225 * V_291 = & V_225 ;
unsigned long V_231 ;
int V_330 ;
T_2 V_305 ;
do {
V_231 = F_167 ( & V_291 -> V_231 ) ;
V_330 = V_291 -> clock . V_232 ;
V_305 = V_291 -> V_237 ;
V_305 += F_165 ( V_328 ) ;
V_305 >>= V_291 -> clock . V_236 ;
V_305 += V_291 -> V_227 ;
} while ( F_168 ( F_169 ( & V_291 -> V_231 , V_231 ) ) );
* V_329 = V_305 ;
return V_330 ;
}
static bool F_170 ( T_12 * V_284 , T_13 * V_328 )
{
if ( V_225 . clock . V_232 != V_295 )
return false ;
return F_166 ( V_284 , V_328 ) == V_295 ;
}
static void F_171 ( struct V_138 * V_138 )
{
#ifdef F_62
struct V_289 * V_290 = & V_138 -> V_5 ;
int V_232 ;
bool V_331 , V_288 ;
V_288 = ( V_290 -> V_292 + 1 ==
F_143 ( & V_138 -> V_293 ) ) ;
V_331 = F_170 (
& V_290 -> V_332 ,
& V_290 -> V_333 ) ;
V_290 -> V_294 = V_331 && V_288
&& ! V_334
&& ! V_290 -> V_335 ;
if ( V_290 -> V_294 )
F_172 ( & V_336 , 1 ) ;
V_232 = V_225 . clock . V_232 ;
F_173 ( V_290 -> V_294 , V_232 ,
V_288 ) ;
#endif
}
void F_174 ( struct V_138 * V_138 )
{
F_175 ( V_138 , V_337 ) ;
}
static void F_176 ( struct V_138 * V_138 )
{
#ifdef F_62
int V_3 ;
struct V_1 * V_2 ;
struct V_289 * V_290 = & V_138 -> V_5 ;
F_158 ( & V_290 -> V_325 ) ;
F_174 ( V_138 ) ;
F_171 ( V_138 ) ;
F_177 (i, vcpu, kvm)
F_30 ( V_338 , V_2 ) ;
F_177 (i, vcpu, kvm)
F_178 ( V_337 , & V_2 -> V_339 ) ;
F_159 ( & V_290 -> V_325 ) ;
#endif
}
static int F_179 ( struct V_1 * V_266 )
{
unsigned long V_307 , V_340 ;
struct V_341 * V_2 = & V_266 -> V_5 ;
struct V_289 * V_290 = & V_266 -> V_138 -> V_5 ;
T_12 V_284 ;
T_2 V_342 , V_303 ;
struct V_343 V_344 ;
T_14 V_345 ;
bool V_294 ;
V_284 = 0 ;
V_303 = 0 ;
F_158 ( & V_290 -> V_325 ) ;
V_294 = V_290 -> V_294 ;
if ( V_294 ) {
V_303 = V_290 -> V_333 ;
V_284 = V_290 -> V_332 ;
}
F_159 ( & V_290 -> V_325 ) ;
F_180 ( V_307 ) ;
V_340 = F_181 ( V_346 ) ;
if ( F_168 ( V_340 == 0 ) ) {
F_182 ( V_307 ) ;
F_30 ( V_338 , V_266 ) ;
return 1 ;
}
if ( ! V_294 ) {
V_303 = F_150 () ;
V_284 = F_154 () ;
}
V_342 = F_151 ( V_266 , V_303 ) ;
if ( V_2 -> V_274 ) {
T_2 V_285 = F_141 ( V_266 , V_284 ) ;
if ( V_285 > V_342 ) {
F_160 ( V_266 , V_285 - V_342 ) ;
V_342 = V_285 ;
}
}
F_182 ( V_307 ) ;
if ( ! V_2 -> V_347 )
return 0 ;
if ( V_272 )
V_340 = F_148 ( V_266 , V_340 ) ;
if ( F_168 ( V_2 -> V_348 != V_340 ) ) {
F_130 ( V_281 , V_340 * 1000LL ,
& V_2 -> V_349 . V_350 ,
& V_2 -> V_349 . V_351 ) ;
V_2 -> V_348 = V_340 ;
}
V_2 -> V_349 . V_342 = V_342 ;
V_2 -> V_349 . V_352 = V_284 + V_266 -> V_138 -> V_5 . V_246 ;
V_2 -> V_323 = V_342 ;
if ( F_168 ( F_183 ( V_266 -> V_138 , & V_2 -> V_353 ,
& V_344 , sizeof( V_344 ) ) ) )
return 0 ;
F_184 ( F_185 ( struct V_343 , V_241 ) != 0 ) ;
V_2 -> V_349 . V_241 = V_344 . V_241 + 1 ;
F_186 ( V_266 -> V_138 , & V_2 -> V_353 ,
& V_2 -> V_349 ,
sizeof( V_2 -> V_349 . V_241 ) ) ;
F_187 () ;
V_345 = ( V_344 . V_307 & V_354 ) ;
if ( V_2 -> V_355 ) {
V_345 |= V_354 ;
V_2 -> V_355 = false ;
}
if ( V_294 )
V_345 |= V_356 ;
V_2 -> V_349 . V_307 = V_345 ;
F_188 ( V_266 -> V_297 , & V_2 -> V_349 ) ;
F_186 ( V_266 -> V_138 , & V_2 -> V_353 ,
& V_2 -> V_349 ,
sizeof( V_2 -> V_349 ) ) ;
F_187 () ;
V_2 -> V_349 . V_241 ++ ;
F_186 ( V_266 -> V_138 , & V_2 -> V_353 ,
& V_2 -> V_349 ,
sizeof( V_2 -> V_349 . V_241 ) ) ;
return 0 ;
}
static void F_189 ( struct V_357 * V_358 )
{
int V_3 ;
struct V_359 * V_360 = F_190 ( V_358 ) ;
struct V_289 * V_290 = F_4 ( V_360 , struct V_289 ,
V_361 ) ;
struct V_138 * V_138 = F_4 ( V_290 , struct V_138 , V_5 ) ;
struct V_1 * V_2 ;
F_177 (i, vcpu, kvm) {
F_30 ( V_338 , V_2 ) ;
F_191 ( V_2 ) ;
}
}
static void F_192 ( struct V_1 * V_266 )
{
struct V_138 * V_138 = V_266 -> V_138 ;
F_30 ( V_338 , V_266 ) ;
F_193 ( & V_138 -> V_5 . V_361 ,
V_362 ) ;
}
static void F_194 ( struct V_357 * V_358 )
{
struct V_359 * V_360 = F_190 ( V_358 ) ;
struct V_289 * V_290 = F_4 ( V_360 , struct V_289 ,
V_363 ) ;
struct V_138 * V_138 = F_4 ( V_290 , struct V_138 , V_5 ) ;
if ( ! V_364 )
return;
F_193 ( & V_138 -> V_5 . V_361 , 0 ) ;
F_193 ( & V_138 -> V_5 . V_363 ,
V_365 ) ;
}
static int F_195 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
T_2 V_366 = V_2 -> V_5 . V_366 ;
unsigned V_367 = V_366 & 0xff ;
switch ( V_21 ) {
case V_368 :
V_2 -> V_5 . V_369 = V_38 ;
break;
case V_370 :
if ( ! ( V_366 & V_371 ) )
return 1 ;
if ( V_38 != 0 && V_38 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_372 = V_38 ;
break;
default:
if ( V_21 >= V_373 &&
V_21 < F_196 ( V_367 ) ) {
T_1 V_94 = V_21 - V_373 ;
if ( ( V_94 & 0x3 ) == 0 &&
V_38 != 0 && ( V_38 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_374 [ V_94 ] = V_38 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_197 ( struct V_1 * V_2 , T_2 V_38 )
{
struct V_138 * V_138 = V_2 -> V_138 ;
int V_375 = F_56 ( V_2 ) ;
T_14 * V_376 = V_375 ? ( T_14 * ) ( long ) V_138 -> V_5 . F_197 . V_377
: ( T_14 * ) ( long ) V_138 -> V_5 . F_197 . V_378 ;
T_14 V_379 = V_375 ? V_138 -> V_5 . F_197 . V_380
: V_138 -> V_5 . F_197 . V_381 ;
T_1 V_382 = V_38 & ~ V_383 ;
T_2 V_384 = V_38 & V_383 ;
T_14 * V_385 ;
int V_120 ;
V_120 = - V_386 ;
if ( V_382 >= V_379 )
goto V_113;
V_120 = - V_387 ;
V_385 = F_198 ( V_376 + ( V_382 * V_107 ) , V_107 ) ;
if ( F_199 ( V_385 ) ) {
V_120 = F_200 ( V_385 ) ;
goto V_113;
}
if ( F_201 ( V_2 , V_384 , V_385 , V_107 ) )
goto V_388;
V_120 = 0 ;
V_388:
F_202 ( V_385 ) ;
V_113:
return V_120 ;
}
static int F_203 ( struct V_1 * V_2 , T_2 V_38 )
{
T_6 V_389 = V_38 & ~ 0x3f ;
if ( V_38 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_390 = V_38 ;
if ( ! ( V_38 & V_391 ) ) {
F_64 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_204 ( V_2 -> V_138 , & V_2 -> V_5 . V_6 . V_38 , V_389 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_392 = ! ( V_38 & V_393 ) ;
F_205 ( V_2 ) ;
return 0 ;
}
static void F_206 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_347 = false ;
}
static void F_207 ( struct V_1 * V_2 )
{
T_2 V_318 ;
if ( ! ( V_2 -> V_5 . V_394 . V_390 & V_395 ) )
return;
V_318 = V_396 -> V_397 . V_398 - V_2 -> V_5 . V_394 . V_399 ;
V_2 -> V_5 . V_394 . V_399 = V_396 -> V_397 . V_398 ;
V_2 -> V_5 . V_394 . V_400 = V_318 ;
}
static void F_208 ( struct V_1 * V_2 )
{
F_207 ( V_2 ) ;
if ( ! ( V_2 -> V_5 . V_394 . V_390 & V_395 ) )
return;
if ( F_168 ( F_183 ( V_2 -> V_138 , & V_2 -> V_5 . V_394 . V_401 ,
& V_2 -> V_5 . V_394 . V_402 , sizeof( struct V_403 ) ) ) )
return;
V_2 -> V_5 . V_394 . V_402 . V_402 += V_2 -> V_5 . V_394 . V_400 ;
V_2 -> V_5 . V_394 . V_402 . V_241 += 2 ;
V_2 -> V_5 . V_394 . V_400 = 0 ;
F_186 ( V_2 -> V_138 , & V_2 -> V_5 . V_394 . V_401 ,
& V_2 -> V_5 . V_394 . V_402 , sizeof( struct V_403 ) ) ;
}
int F_209 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
bool V_404 = false ;
T_1 V_21 = V_33 -> V_146 ;
T_2 V_38 = V_33 -> V_38 ;
switch ( V_21 ) {
case V_405 :
case V_406 :
case V_407 :
case V_408 :
case V_409 :
case V_410 :
break;
case V_411 :
return F_108 ( V_2 , V_38 ) ;
case V_412 :
V_38 &= ~ ( T_2 ) 0x40 ;
V_38 &= ~ ( T_2 ) 0x100 ;
V_38 &= ~ ( T_2 ) 0x8 ;
V_38 &= ~ ( T_2 ) 0x40000 ;
if ( V_38 != 0 ) {
F_210 ( V_2 , L_9 ,
V_38 ) ;
return 1 ;
}
break;
case V_413 :
if ( V_38 != 0 ) {
F_210 ( V_2 , L_10
L_11 , V_38 ) ;
return 1 ;
}
break;
case V_414 :
if ( ! V_38 ) {
break;
} else if ( V_38 & ~ ( V_415 | V_416 ) ) {
return 1 ;
}
F_210 ( V_2 , L_12 ,
V_261 , V_38 ) ;
break;
case 0x200 ... 0x2ff :
return F_211 ( V_2 , V_21 , V_38 ) ;
case V_417 :
return F_20 ( V_2 , V_33 ) ;
case V_418 ... V_418 + 0x3ff :
return F_212 ( V_2 , V_21 , V_38 ) ;
case V_419 :
F_213 ( V_2 , V_38 ) ;
break;
case V_420 :
if ( F_156 ( V_2 ) ) {
if ( ! V_33 -> V_40 ) {
T_12 V_421 = V_38 - V_2 -> V_5 . V_300 ;
F_160 ( V_2 , V_421 ) ;
}
V_2 -> V_5 . V_300 = V_38 ;
}
break;
case V_422 :
V_2 -> V_5 . V_423 = V_38 ;
break;
case V_424 :
if ( ! V_33 -> V_40 )
return 1 ;
V_2 -> V_5 . V_425 = V_38 ;
break;
case V_426 :
case V_427 :
V_2 -> V_138 -> V_5 . V_240 = V_38 ;
F_122 ( V_2 -> V_138 , V_38 ) ;
break;
case V_428 :
case V_429 : {
T_2 V_430 ;
struct V_289 * V_290 = & V_2 -> V_138 -> V_5 ;
F_206 ( V_2 ) ;
if ( V_2 -> V_297 == 0 && ! V_33 -> V_40 ) {
bool V_431 = ( V_21 == V_429 ) ;
if ( V_290 -> V_335 != V_431 )
F_214 ( V_296 ,
& V_2 -> V_339 ) ;
V_290 -> V_335 = V_431 ;
}
V_2 -> V_5 . time = V_38 ;
F_30 ( V_432 , V_2 ) ;
if ( ! ( V_38 & 1 ) )
break;
V_430 = V_38 & ~ ( V_383 | 1 ) ;
if ( F_204 ( V_2 -> V_138 ,
& V_2 -> V_5 . V_353 , V_38 & ~ 1ULL ,
sizeof( struct V_343 ) ) )
V_2 -> V_5 . V_347 = false ;
else
V_2 -> V_5 . V_347 = true ;
break;
}
case V_433 :
if ( F_203 ( V_2 , V_38 ) )
return 1 ;
break;
case V_434 :
if ( F_168 ( ! F_215 () ) )
return 1 ;
if ( V_38 & V_435 )
return 1 ;
if ( F_204 ( V_2 -> V_138 , & V_2 -> V_5 . V_394 . V_401 ,
V_38 & V_436 ,
sizeof( struct V_403 ) ) )
return 1 ;
V_2 -> V_5 . V_394 . V_390 = V_38 ;
if ( ! ( V_38 & V_395 ) )
break;
F_30 ( V_437 , V_2 ) ;
break;
case V_438 :
if ( F_216 ( V_2 , V_38 ) )
return 1 ;
break;
case V_370 :
case V_368 :
case V_373 ... F_196 ( V_439 ) - 1 :
return F_195 ( V_2 , V_21 , V_38 ) ;
case V_440 ... V_441 :
case V_442 ... V_443 :
V_404 = true ;
case V_444 ... V_445 :
case V_446 ... V_447 :
if ( F_217 ( V_2 , V_21 ) )
return F_218 ( V_2 , V_33 ) ;
if ( V_404 || V_38 != 0 )
F_210 ( V_2 , L_13
L_14 , V_21 , V_38 ) ;
break;
case V_448 :
break;
case V_449 ... V_450 :
case V_451 ... V_452 :
case V_453 :
case V_454 ... V_455 :
return F_219 ( V_2 , V_21 , V_38 ,
V_33 -> V_40 ) ;
case V_456 :
F_210 ( V_2 , L_15 , V_21 , V_38 ) ;
break;
case V_457 :
if ( ! F_220 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_458 . V_459 = V_38 ;
break;
case V_460 :
if ( ! F_220 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_458 . V_461 = V_38 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_138 -> V_5 . F_197 . V_21 ) )
return F_197 ( V_2 , V_38 ) ;
if ( F_217 ( V_2 , V_21 ) )
return F_218 ( V_2 , V_33 ) ;
if ( ! V_462 ) {
F_210 ( V_2 , L_16 ,
V_21 , V_38 ) ;
return 1 ;
} else {
F_210 ( V_2 , L_15 ,
V_21 , V_38 ) ;
break;
}
}
return 0 ;
}
int F_114 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
return V_73 -> V_463 ( V_2 , V_21 ) ;
}
static int F_221 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_464 )
{
T_2 V_38 ;
T_2 V_366 = V_2 -> V_5 . V_366 ;
unsigned V_367 = V_366 & 0xff ;
switch ( V_21 ) {
case V_465 :
case V_466 :
V_38 = 0 ;
break;
case V_467 :
V_38 = V_2 -> V_5 . V_366 ;
break;
case V_370 :
if ( ! ( V_366 & V_371 ) )
return 1 ;
V_38 = V_2 -> V_5 . V_372 ;
break;
case V_368 :
V_38 = V_2 -> V_5 . V_369 ;
break;
default:
if ( V_21 >= V_373 &&
V_21 < F_196 ( V_367 ) ) {
T_1 V_94 = V_21 - V_373 ;
V_38 = V_2 -> V_5 . V_374 [ V_94 ] ;
break;
}
return 1 ;
}
* V_464 = V_38 ;
return 0 ;
}
int F_222 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
switch ( V_33 -> V_146 ) {
case V_468 :
case V_469 :
case V_414 :
case V_470 :
case V_471 :
case V_472 :
case V_473 :
case V_474 :
case V_475 :
case V_476 :
case V_412 :
case V_408 :
case V_477 :
case V_405 :
case V_413 :
case V_410 :
V_33 -> V_38 = 0 ;
break;
case V_444 ... V_445 :
case V_440 ... V_441 :
case V_442 ... V_443 :
case V_446 ... V_447 :
if ( F_217 ( V_2 , V_33 -> V_146 ) )
return F_223 ( V_2 , V_33 -> V_146 , & V_33 -> V_38 ) ;
V_33 -> V_38 = 0 ;
break;
case V_406 :
V_33 -> V_38 = 0x100000000ULL ;
break;
case V_478 :
case 0x200 ... 0x2ff :
return F_224 ( V_2 , V_33 -> V_146 , & V_33 -> V_38 ) ;
case 0xcd :
V_33 -> V_38 = 3 ;
break;
case V_479 :
V_33 -> V_38 = 1 << 24 ;
break;
case V_417 :
V_33 -> V_38 = F_19 ( V_2 ) ;
break;
case V_418 ... V_418 + 0x3ff :
return F_225 ( V_2 , V_33 -> V_146 , & V_33 -> V_38 ) ;
break;
case V_419 :
V_33 -> V_38 = F_226 ( V_2 ) ;
break;
case V_420 :
V_33 -> V_38 = ( T_2 ) V_2 -> V_5 . V_300 ;
break;
case V_422 :
V_33 -> V_38 = V_2 -> V_5 . V_423 ;
break;
case V_424 :
if ( ! V_33 -> V_40 )
return 1 ;
V_33 -> V_38 = V_2 -> V_5 . V_425 ;
break;
case V_480 :
V_33 -> V_38 = 1000ULL ;
V_33 -> V_38 |= ( ( ( T_8 ) 4ULL ) << 40 ) ;
break;
case V_411 :
V_33 -> V_38 = V_2 -> V_5 . V_131 ;
break;
case V_427 :
case V_426 :
V_33 -> V_38 = V_2 -> V_138 -> V_5 . V_240 ;
break;
case V_429 :
case V_428 :
V_33 -> V_38 = V_2 -> V_5 . time ;
break;
case V_433 :
V_33 -> V_38 = V_2 -> V_5 . V_6 . V_390 ;
break;
case V_434 :
V_33 -> V_38 = V_2 -> V_5 . V_394 . V_390 ;
break;
case V_438 :
V_33 -> V_38 = V_2 -> V_5 . V_481 . V_390 ;
break;
case V_465 :
case V_466 :
case V_467 :
case V_370 :
case V_368 :
case V_373 ... F_196 ( V_439 ) - 1 :
return F_221 ( V_2 , V_33 -> V_146 , & V_33 -> V_38 ) ;
case V_448 :
V_33 -> V_38 = 0x20000000 ;
break;
case V_449 ... V_450 :
case V_451 ... V_452 :
case V_453 :
case V_454 ... V_455 :
return F_227 ( V_2 ,
V_33 -> V_146 , & V_33 -> V_38 ) ;
break;
case V_456 :
V_33 -> V_38 = 0xbe702111 ;
break;
case V_457 :
if ( ! F_220 ( V_2 ) )
return 1 ;
V_33 -> V_38 = V_2 -> V_5 . V_458 . V_459 ;
break;
case V_460 :
if ( ! F_220 ( V_2 ) )
return 1 ;
V_33 -> V_38 = V_2 -> V_5 . V_458 . V_461 ;
break;
default:
if ( F_217 ( V_2 , V_33 -> V_146 ) )
return F_223 ( V_2 , V_33 -> V_146 , & V_33 -> V_38 ) ;
if ( ! V_462 ) {
F_210 ( V_2 , L_17 , V_33 -> V_146 ) ;
return 1 ;
} else {
F_210 ( V_2 , L_18 , V_33 -> V_146 ) ;
V_33 -> V_38 = 0 ;
}
break;
}
return 0 ;
}
static int F_228 ( struct V_1 * V_2 , struct V_482 * V_19 ,
struct V_483 * V_484 ,
int (* F_229)( struct V_1 * V_2 ,
unsigned V_146 , T_2 * V_38 ) )
{
int V_3 , V_485 ;
V_485 = F_230 ( & V_2 -> V_138 -> V_486 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_487 ; ++ V_3 )
if ( F_229 ( V_2 , V_484 [ V_3 ] . V_146 , & V_484 [ V_3 ] . V_38 ) )
break;
F_231 ( & V_2 -> V_138 -> V_486 , V_485 ) ;
return V_3 ;
}
static int F_232 ( struct V_1 * V_2 , struct V_482 T_15 * V_488 ,
int (* F_229)( struct V_1 * V_2 ,
unsigned V_146 , T_2 * V_38 ) ,
int V_489 )
{
struct V_482 V_19 ;
struct V_483 * V_484 ;
int V_120 , V_490 ;
unsigned V_491 ;
V_120 = - V_101 ;
if ( F_233 ( & V_19 , V_488 , sizeof V_19 ) )
goto V_113;
V_120 = - V_386 ;
if ( V_19 . V_487 >= V_492 )
goto V_113;
V_491 = sizeof( struct V_483 ) * V_19 . V_487 ;
V_484 = F_198 ( V_488 -> V_484 , V_491 ) ;
if ( F_199 ( V_484 ) ) {
V_120 = F_200 ( V_484 ) ;
goto V_113;
}
V_120 = V_490 = F_228 ( V_2 , & V_19 , V_484 , F_229 ) ;
if ( V_120 < 0 )
goto V_388;
V_120 = - V_101 ;
if ( V_489 && F_234 ( V_488 -> V_484 , V_484 , V_491 ) )
goto V_388;
V_120 = V_490 ;
V_388:
F_202 ( V_484 ) ;
V_113:
return V_120 ;
}
int F_235 ( struct V_138 * V_138 , long V_493 )
{
int V_120 ;
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
case V_534 :
#ifdef F_236
case V_535 :
case V_536 :
#endif
V_120 = 1 ;
break;
case V_537 :
V_120 = V_73 -> V_538 () ;
break;
case V_539 :
V_120 = V_540 ;
break;
case V_541 :
V_120 = ! V_73 -> V_542 () ;
break;
case V_543 :
V_120 = V_544 ;
break;
case V_545 :
V_120 = V_546 ;
break;
case V_547 :
V_120 = V_548 ;
break;
case V_549 :
V_120 = 0 ;
break;
#ifdef F_236
case V_550 :
V_120 = F_237 ( & V_551 ) ;
break;
#endif
case V_552 :
V_120 = V_439 ;
break;
case V_553 :
V_120 = V_554 ;
break;
case V_555 :
V_120 = V_272 ;
break;
default:
V_120 = 0 ;
break;
}
return V_120 ;
}
long F_238 ( struct V_556 * V_557 ,
unsigned int V_558 , unsigned long V_559 )
{
void T_15 * V_560 = ( void T_15 * ) V_559 ;
long V_120 ;
switch ( V_558 ) {
case V_561 : {
struct V_562 T_15 * V_563 = V_560 ;
struct V_562 V_564 ;
unsigned V_490 ;
V_120 = - V_101 ;
if ( F_233 ( & V_564 , V_563 , sizeof V_564 ) )
goto V_113;
V_490 = V_564 . V_487 ;
V_564 . V_487 = V_565 + V_566 ;
if ( F_234 ( V_563 , & V_564 , sizeof V_564 ) )
goto V_113;
V_120 = - V_386 ;
if ( V_490 < V_564 . V_487 )
goto V_113;
V_120 = - V_101 ;
if ( F_234 ( V_563 -> V_567 , & V_568 ,
V_565 * sizeof( T_1 ) ) )
goto V_113;
if ( F_234 ( V_563 -> V_567 + V_565 ,
& V_569 ,
V_566 * sizeof( T_1 ) ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_570 :
case V_571 : {
struct V_572 T_15 * V_573 = V_560 ;
struct V_572 V_574 ;
V_120 = - V_101 ;
if ( F_233 ( & V_574 , V_573 , sizeof V_574 ) )
goto V_113;
V_120 = F_239 ( & V_574 , V_573 -> V_484 ,
V_558 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_234 ( V_573 , & V_574 , sizeof V_574 ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_575 : {
T_2 V_576 ;
V_576 = V_577 ;
V_120 = - V_101 ;
if ( F_234 ( V_560 , & V_576 , sizeof V_576 ) )
goto V_113;
V_120 = 0 ;
break;
}
default:
V_120 = - V_578 ;
}
V_113:
return V_120 ;
}
static void F_240 ( void * V_579 )
{
F_241 () ;
}
static bool F_242 ( struct V_1 * V_2 )
{
return F_66 ( V_2 -> V_138 ) ;
}
static inline void F_243 ( struct V_1 * V_2 )
{
F_214 ( V_580 , & V_2 -> V_339 ) ;
}
void F_244 ( struct V_1 * V_2 , int V_23 )
{
if ( F_242 ( V_2 ) ) {
if ( V_73 -> V_581 () )
F_245 ( V_23 , V_2 -> V_5 . V_582 ) ;
else if ( V_2 -> V_23 != - 1 && V_2 -> V_23 != V_23 )
F_246 ( V_2 -> V_23 ,
F_240 , NULL , 1 ) ;
}
V_73 -> V_583 ( V_2 , V_23 ) ;
if ( F_168 ( V_2 -> V_5 . V_584 ) ) {
F_161 ( V_2 , V_2 -> V_5 . V_584 ) ;
V_2 -> V_5 . V_584 = 0 ;
F_30 ( V_338 , V_2 ) ;
}
if ( F_168 ( V_2 -> V_23 != V_23 ) || F_155 () ) {
T_12 V_585 = ! V_2 -> V_5 . V_586 ? 0 :
F_150 () - V_2 -> V_5 . V_586 ;
if ( V_585 < 0 )
F_247 ( L_19 ) ;
if ( F_155 () ) {
T_2 V_94 = F_149 ( V_2 ,
V_2 -> V_5 . V_323 ) ;
V_73 -> V_324 ( V_2 , V_94 ) ;
V_2 -> V_5 . V_274 = 1 ;
}
if ( ! V_2 -> V_138 -> V_5 . V_294 || V_2 -> V_23 == - 1 )
F_30 ( V_432 , V_2 ) ;
if ( V_2 -> V_23 != V_23 )
F_243 ( V_2 ) ;
V_2 -> V_23 = V_23 ;
}
F_30 ( V_437 , V_2 ) ;
}
void F_248 ( struct V_1 * V_2 )
{
V_73 -> V_587 ( V_2 ) ;
F_249 ( V_2 ) ;
V_2 -> V_5 . V_586 = F_150 () ;
}
static int F_250 ( struct V_1 * V_2 ,
struct V_588 * V_589 )
{
if ( V_2 -> V_5 . V_590 )
V_73 -> V_591 ( V_2 ) ;
memcpy ( V_589 -> V_592 , V_2 -> V_5 . V_593 -> V_592 , sizeof *V_589 ) ;
return 0 ;
}
static int F_251 ( struct V_1 * V_2 ,
struct V_588 * V_589 )
{
F_252 ( V_2 , V_589 ) ;
F_253 ( V_2 ) ;
return 0 ;
}
static int F_254 ( struct V_1 * V_2 )
{
return ( ! F_89 ( V_2 ) ||
F_255 ( V_2 ) ) ;
}
static int F_256 ( struct V_1 * V_2 )
{
return F_257 ( V_2 ) &&
! F_258 ( V_2 ) &&
! F_259 ( V_2 ) &&
F_254 ( V_2 ) ;
}
static int F_260 ( struct V_1 * V_2 ,
struct V_594 * V_595 )
{
if ( V_595 -> V_595 >= V_596 )
return - V_578 ;
if ( ! F_261 ( V_2 -> V_138 ) ) {
F_262 ( V_2 , V_595 -> V_595 , false ) ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
if ( F_263 ( V_2 -> V_138 ) )
return - V_597 ;
if ( V_2 -> V_5 . V_598 != - 1 )
return - V_599 ;
V_2 -> V_5 . V_598 = V_595 -> V_595 ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
static int F_264 ( struct V_1 * V_2 )
{
F_40 ( V_2 ) ;
return 0 ;
}
static int F_265 ( struct V_1 * V_2 )
{
F_30 ( V_600 , V_2 ) ;
return 0 ;
}
static int F_266 ( struct V_1 * V_2 ,
struct V_601 * V_602 )
{
if ( V_602 -> V_307 )
return - V_578 ;
V_2 -> V_5 . V_603 = ! ! V_602 -> V_604 ;
return 0 ;
}
static int F_267 ( struct V_1 * V_2 ,
T_2 V_366 )
{
int V_120 ;
unsigned V_367 = V_366 & 0xff , V_605 ;
V_120 = - V_578 ;
if ( ! V_367 || V_367 >= V_439 )
goto V_113;
if ( V_366 & ~ ( V_577 | 0xff | 0xff0000 ) )
goto V_113;
V_120 = 0 ;
V_2 -> V_5 . V_366 = V_366 ;
if ( V_366 & V_371 )
V_2 -> V_5 . V_372 = ~ ( T_2 ) 0 ;
for ( V_605 = 0 ; V_605 < V_367 ; V_605 ++ )
V_2 -> V_5 . V_374 [ V_605 * 4 ] = ~ ( T_2 ) 0 ;
V_113:
return V_120 ;
}
static int F_268 ( struct V_1 * V_2 ,
struct V_606 * V_607 )
{
T_2 V_366 = V_2 -> V_5 . V_366 ;
unsigned V_367 = V_366 & 0xff ;
T_2 * V_608 = V_2 -> V_5 . V_374 ;
if ( V_607 -> V_605 >= V_367 || ! ( V_607 -> V_461 & V_609 ) )
return - V_578 ;
if ( ( V_607 -> V_461 & V_610 ) && ( V_366 & V_371 ) &&
V_2 -> V_5 . V_372 != ~ ( T_2 ) 0 )
return 0 ;
V_608 += 4 * V_607 -> V_605 ;
if ( ( V_607 -> V_461 & V_610 ) && V_608 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_607 -> V_461 & V_610 ) {
if ( ( V_2 -> V_5 . V_369 & V_611 ) ||
! F_45 ( V_2 , V_612 ) ) {
F_30 ( V_72 , V_2 ) ;
return 0 ;
}
if ( V_608 [ 1 ] & V_609 )
V_607 -> V_461 |= V_613 ;
V_608 [ 2 ] = V_607 -> V_614 ;
V_608 [ 3 ] = V_607 -> V_615 ;
V_2 -> V_5 . V_369 = V_607 -> V_369 ;
V_608 [ 1 ] = V_607 -> V_461 ;
F_32 ( V_2 , V_58 ) ;
} else if ( ! ( V_608 [ 1 ] & V_609 )
|| ! ( V_608 [ 1 ] & V_610 ) ) {
if ( V_608 [ 1 ] & V_609 )
V_607 -> V_461 |= V_613 ;
V_608 [ 2 ] = V_607 -> V_614 ;
V_608 [ 3 ] = V_607 -> V_615 ;
V_608 [ 1 ] = V_607 -> V_461 ;
} else
V_608 [ 1 ] |= V_613 ;
return 0 ;
}
static void F_269 ( struct V_1 * V_2 ,
struct V_616 * V_617 )
{
F_270 ( V_2 ) ;
V_617 -> V_68 . V_618 =
V_2 -> V_5 . V_68 . V_69 &&
! F_271 ( V_2 -> V_5 . V_68 . V_16 ) ;
V_617 -> V_68 . V_16 = V_2 -> V_5 . V_68 . V_16 ;
V_617 -> V_68 . V_71 = V_2 -> V_5 . V_68 . V_71 ;
V_617 -> V_68 . V_619 = 0 ;
V_617 -> V_68 . V_62 = V_2 -> V_5 . V_68 . V_62 ;
V_617 -> V_620 . V_618 =
V_2 -> V_5 . V_620 . V_69 && ! V_2 -> V_5 . V_620 . V_621 ;
V_617 -> V_620 . V_16 = V_2 -> V_5 . V_620 . V_16 ;
V_617 -> V_620 . V_621 = 0 ;
V_617 -> V_620 . V_622 = V_73 -> V_623 ( V_2 ) ;
V_617 -> V_624 . V_618 = V_2 -> V_5 . V_625 ;
V_617 -> V_624 . V_69 = V_2 -> V_5 . V_626 != 0 ;
V_617 -> V_624 . V_627 = V_73 -> V_628 ( V_2 ) ;
V_617 -> V_624 . V_619 = 0 ;
V_617 -> V_629 = 0 ;
V_617 -> V_630 . V_631 = F_272 ( V_2 ) ;
V_617 -> V_630 . V_69 = V_2 -> V_5 . V_632 ;
V_617 -> V_630 . V_633 =
! ! ( V_2 -> V_5 . V_634 & V_635 ) ;
V_617 -> V_630 . V_636 = F_273 ( V_2 ) ;
V_617 -> V_307 = ( V_637
| V_638
| V_639 ) ;
memset ( & V_617 -> V_640 , 0 , sizeof( V_617 -> V_640 ) ) ;
}
static int F_274 ( struct V_1 * V_2 ,
struct V_616 * V_617 )
{
if ( V_617 -> V_307 & ~ ( V_637
| V_641
| V_638
| V_639 ) )
return - V_578 ;
F_270 ( V_2 ) ;
V_2 -> V_5 . V_68 . V_69 = V_617 -> V_68 . V_618 ;
V_2 -> V_5 . V_68 . V_16 = V_617 -> V_68 . V_16 ;
V_2 -> V_5 . V_68 . V_71 = V_617 -> V_68 . V_71 ;
V_2 -> V_5 . V_68 . V_62 = V_617 -> V_68 . V_62 ;
V_2 -> V_5 . V_620 . V_69 = V_617 -> V_620 . V_618 ;
V_2 -> V_5 . V_620 . V_16 = V_617 -> V_620 . V_16 ;
V_2 -> V_5 . V_620 . V_621 = V_617 -> V_620 . V_621 ;
if ( V_617 -> V_307 & V_638 )
V_73 -> V_642 ( V_2 ,
V_617 -> V_620 . V_622 ) ;
V_2 -> V_5 . V_625 = V_617 -> V_624 . V_618 ;
if ( V_617 -> V_307 & V_637 )
V_2 -> V_5 . V_626 = V_617 -> V_624 . V_69 ;
V_73 -> V_643 ( V_2 , V_617 -> V_624 . V_627 ) ;
if ( V_617 -> V_307 & V_641 &&
F_89 ( V_2 ) )
V_2 -> V_5 . V_593 -> V_629 = V_617 -> V_629 ;
if ( V_617 -> V_307 & V_639 ) {
if ( V_617 -> V_630 . V_631 )
V_2 -> V_5 . V_634 |= V_644 ;
else
V_2 -> V_5 . V_634 &= ~ V_644 ;
V_2 -> V_5 . V_632 = V_617 -> V_630 . V_69 ;
if ( V_617 -> V_630 . V_633 )
V_2 -> V_5 . V_634 |= V_635 ;
else
V_2 -> V_5 . V_634 &= ~ V_635 ;
if ( F_89 ( V_2 ) ) {
if ( V_617 -> V_630 . V_636 )
F_214 ( V_645 , & V_2 -> V_5 . V_593 -> V_646 ) ;
else
F_178 ( V_645 , & V_2 -> V_5 . V_593 -> V_646 ) ;
}
}
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
static void F_275 ( struct V_1 * V_2 ,
struct V_647 * V_648 )
{
unsigned long V_195 ;
memcpy ( V_648 -> V_182 , V_2 -> V_5 . V_182 , sizeof( V_2 -> V_5 . V_182 ) ) ;
F_100 ( V_2 , 6 , & V_195 ) ;
V_648 -> V_186 = V_195 ;
V_648 -> V_187 = V_2 -> V_5 . V_187 ;
V_648 -> V_307 = 0 ;
memset ( & V_648 -> V_640 , 0 , sizeof( V_648 -> V_640 ) ) ;
}
static int F_276 ( struct V_1 * V_2 ,
struct V_647 * V_648 )
{
if ( V_648 -> V_307 )
return - V_578 ;
memcpy ( V_2 -> V_5 . V_182 , V_648 -> V_182 , sizeof( V_2 -> V_5 . V_182 ) ) ;
F_93 ( V_2 ) ;
V_2 -> V_5 . V_186 = V_648 -> V_186 ;
F_94 ( V_2 ) ;
V_2 -> V_5 . V_187 = V_648 -> V_187 ;
F_95 ( V_2 ) ;
return 0 ;
}
static void F_277 ( T_14 * V_649 , struct V_1 * V_2 )
{
struct V_650 * V_651 = & V_2 -> V_5 . V_652 . V_653 . V_651 ;
T_2 V_654 = V_651 -> V_655 . V_656 ;
T_2 V_657 ;
memcpy ( V_649 , V_651 , V_658 ) ;
* ( T_2 * ) ( V_649 + V_658 ) = V_654 ;
V_657 = V_654 & ~ V_659 ;
while ( V_657 ) {
T_2 V_660 = V_657 & - V_657 ;
int V_146 = F_278 ( V_660 ) - 1 ;
void * V_661 = F_279 ( V_651 , V_660 ) ;
if ( V_661 ) {
T_1 V_491 , V_94 , V_200 , V_208 ;
F_280 ( V_662 , V_146 ,
& V_491 , & V_94 , & V_200 , & V_208 ) ;
memcpy ( V_649 + V_94 , V_661 , V_491 ) ;
}
V_657 -= V_660 ;
}
}
static void F_281 ( struct V_1 * V_2 , T_14 * V_661 )
{
struct V_650 * V_651 = & V_2 -> V_5 . V_652 . V_653 . V_651 ;
T_2 V_654 = * ( T_2 * ) ( V_661 + V_658 ) ;
T_2 V_657 ;
memcpy ( V_651 , V_661 , V_658 ) ;
V_651 -> V_655 . V_656 = V_654 ;
if ( V_663 )
V_651 -> V_655 . V_664 = V_145 | V_665 ;
V_657 = V_654 & ~ V_659 ;
while ( V_657 ) {
T_2 V_660 = V_657 & - V_657 ;
int V_146 = F_278 ( V_660 ) - 1 ;
void * V_649 = F_279 ( V_651 , V_660 ) ;
if ( V_649 ) {
T_1 V_491 , V_94 , V_200 , V_208 ;
F_280 ( V_662 , V_146 ,
& V_491 , & V_94 , & V_200 , & V_208 ) ;
memcpy ( V_649 , V_661 + V_94 , V_491 ) ;
}
V_657 -= V_660 ;
}
}
static void F_282 ( struct V_1 * V_2 ,
struct V_666 * V_667 )
{
if ( V_554 ) {
memset ( V_667 , 0 , sizeof( struct V_666 ) ) ;
F_277 ( ( T_14 * ) V_667 -> V_668 , V_2 ) ;
} else {
memcpy ( V_667 -> V_668 ,
& V_2 -> V_5 . V_652 . V_653 . V_669 ,
sizeof( struct V_670 ) ) ;
* ( T_2 * ) & V_667 -> V_668 [ V_658 / sizeof( T_1 ) ] =
V_659 ;
}
}
static int F_283 ( struct V_1 * V_2 ,
struct V_666 * V_667 )
{
T_2 V_654 =
* ( T_2 * ) & V_667 -> V_668 [ V_658 / sizeof( T_1 ) ] ;
if ( V_554 ) {
if ( V_654 & ~ F_284 () )
return - V_578 ;
F_281 ( V_2 , ( T_14 * ) V_667 -> V_668 ) ;
} else {
if ( V_654 & ~ V_659 )
return - V_578 ;
memcpy ( & V_2 -> V_5 . V_652 . V_653 . V_669 ,
V_667 -> V_668 , sizeof( struct V_670 ) ) ;
}
return 0 ;
}
static void F_285 ( struct V_1 * V_2 ,
struct V_671 * V_672 )
{
if ( ! V_554 ) {
V_672 -> V_673 = 0 ;
return;
}
V_672 -> V_673 = 1 ;
V_672 -> V_307 = 0 ;
V_672 -> V_674 [ 0 ] . V_147 = V_143 ;
V_672 -> V_674 [ 0 ] . V_22 = V_2 -> V_5 . V_144 ;
}
static int F_286 ( struct V_1 * V_2 ,
struct V_671 * V_672 )
{
int V_3 , V_120 = 0 ;
if ( ! V_554 )
return - V_578 ;
if ( V_672 -> V_673 > V_675 || V_672 -> V_307 )
return - V_578 ;
for ( V_3 = 0 ; V_3 < V_672 -> V_673 ; V_3 ++ )
if ( V_672 -> V_674 [ V_3 ] . V_147 == V_143 ) {
V_120 = F_74 ( V_2 , V_143 ,
V_672 -> V_674 [ V_3 ] . V_22 ) ;
break;
}
if ( V_120 )
V_120 = - V_578 ;
return V_120 ;
}
static int F_287 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_347 )
return - V_578 ;
V_2 -> V_5 . V_355 = true ;
F_30 ( V_338 , V_2 ) ;
return 0 ;
}
static int F_288 ( struct V_1 * V_2 ,
struct V_676 * V_677 )
{
if ( V_677 -> V_307 )
return - V_578 ;
switch ( V_677 -> V_677 ) {
case V_519 :
return F_289 ( V_2 ) ;
default:
return - V_578 ;
}
}
long F_290 ( struct V_556 * V_557 ,
unsigned int V_558 , unsigned long V_559 )
{
struct V_1 * V_2 = V_557 -> V_678 ;
void T_15 * V_560 = ( void T_15 * ) V_559 ;
int V_120 ;
union {
struct V_588 * V_679 ;
struct V_666 * V_651 ;
struct V_671 * V_674 ;
void * V_680 ;
} V_681 ;
V_681 . V_680 = NULL ;
switch ( V_558 ) {
case V_682 : {
V_120 = - V_578 ;
if ( ! F_89 ( V_2 ) )
goto V_113;
V_681 . V_679 = F_291 ( sizeof( struct V_588 ) , V_683 ) ;
V_120 = - V_387 ;
if ( ! V_681 . V_679 )
goto V_113;
V_120 = F_250 ( V_2 , V_681 . V_679 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_234 ( V_560 , V_681 . V_679 , sizeof( struct V_588 ) ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_684 : {
V_120 = - V_578 ;
if ( ! F_89 ( V_2 ) )
goto V_113;
V_681 . V_679 = F_198 ( V_560 , sizeof( * V_681 . V_679 ) ) ;
if ( F_199 ( V_681 . V_679 ) )
return F_200 ( V_681 . V_679 ) ;
V_120 = F_251 ( V_2 , V_681 . V_679 ) ;
break;
}
case V_685 : {
struct V_594 V_595 ;
V_120 = - V_101 ;
if ( F_233 ( & V_595 , V_560 , sizeof V_595 ) )
goto V_113;
V_120 = F_260 ( V_2 , & V_595 ) ;
break;
}
case V_686 : {
V_120 = F_264 ( V_2 ) ;
break;
}
case V_687 : {
V_120 = F_265 ( V_2 ) ;
break;
}
case V_688 : {
struct V_689 T_15 * V_573 = V_560 ;
struct V_689 V_574 ;
V_120 = - V_101 ;
if ( F_233 ( & V_574 , V_573 , sizeof V_574 ) )
goto V_113;
V_120 = F_292 ( V_2 , & V_574 , V_573 -> V_484 ) ;
break;
}
case V_690 : {
struct V_572 T_15 * V_573 = V_560 ;
struct V_572 V_574 ;
V_120 = - V_101 ;
if ( F_233 ( & V_574 , V_573 , sizeof V_574 ) )
goto V_113;
V_120 = F_293 ( V_2 , & V_574 ,
V_573 -> V_484 ) ;
break;
}
case V_691 : {
struct V_572 T_15 * V_573 = V_560 ;
struct V_572 V_574 ;
V_120 = - V_101 ;
if ( F_233 ( & V_574 , V_573 , sizeof V_574 ) )
goto V_113;
V_120 = F_294 ( V_2 , & V_574 ,
V_573 -> V_484 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_234 ( V_573 , & V_574 , sizeof V_574 ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_692 :
V_120 = F_232 ( V_2 , V_560 , F_113 , 1 ) ;
break;
case V_693 :
V_120 = F_232 ( V_2 , V_560 , F_115 , 0 ) ;
break;
case V_694 : {
struct V_601 V_602 ;
V_120 = - V_101 ;
if ( F_233 ( & V_602 , V_560 , sizeof V_602 ) )
goto V_113;
V_120 = F_266 ( V_2 , & V_602 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_234 ( V_560 , & V_602 , sizeof V_602 ) )
goto V_113;
V_120 = 0 ;
break;
} ;
case V_695 : {
struct V_696 V_697 ;
V_120 = - V_578 ;
if ( ! F_89 ( V_2 ) )
goto V_113;
V_120 = - V_101 ;
if ( F_233 ( & V_697 , V_560 , sizeof V_697 ) )
goto V_113;
V_120 = F_295 ( V_2 , V_697 . V_698 ) ;
break;
}
case V_699 : {
T_2 V_366 ;
V_120 = - V_101 ;
if ( F_233 ( & V_366 , V_560 , sizeof V_366 ) )
goto V_113;
V_120 = F_267 ( V_2 , V_366 ) ;
break;
}
case V_700 : {
struct V_606 V_607 ;
V_120 = - V_101 ;
if ( F_233 ( & V_607 , V_560 , sizeof V_607 ) )
goto V_113;
V_120 = F_268 ( V_2 , & V_607 ) ;
break;
}
case V_701 : {
struct V_616 V_617 ;
F_269 ( V_2 , & V_617 ) ;
V_120 = - V_101 ;
if ( F_234 ( V_560 , & V_617 , sizeof( struct V_616 ) ) )
break;
V_120 = 0 ;
break;
}
case V_702 : {
struct V_616 V_617 ;
V_120 = - V_101 ;
if ( F_233 ( & V_617 , V_560 , sizeof( struct V_616 ) ) )
break;
V_120 = F_274 ( V_2 , & V_617 ) ;
break;
}
case V_703 : {
struct V_647 V_648 ;
F_275 ( V_2 , & V_648 ) ;
V_120 = - V_101 ;
if ( F_234 ( V_560 , & V_648 ,
sizeof( struct V_647 ) ) )
break;
V_120 = 0 ;
break;
}
case V_704 : {
struct V_647 V_648 ;
V_120 = - V_101 ;
if ( F_233 ( & V_648 , V_560 ,
sizeof( struct V_647 ) ) )
break;
V_120 = F_276 ( V_2 , & V_648 ) ;
break;
}
case V_705 : {
V_681 . V_651 = F_291 ( sizeof( struct V_666 ) , V_683 ) ;
V_120 = - V_387 ;
if ( ! V_681 . V_651 )
break;
F_282 ( V_2 , V_681 . V_651 ) ;
V_120 = - V_101 ;
if ( F_234 ( V_560 , V_681 . V_651 , sizeof( struct V_666 ) ) )
break;
V_120 = 0 ;
break;
}
case V_706 : {
V_681 . V_651 = F_198 ( V_560 , sizeof( * V_681 . V_651 ) ) ;
if ( F_199 ( V_681 . V_651 ) )
return F_200 ( V_681 . V_651 ) ;
V_120 = F_283 ( V_2 , V_681 . V_651 ) ;
break;
}
case V_707 : {
V_681 . V_674 = F_291 ( sizeof( struct V_671 ) , V_683 ) ;
V_120 = - V_387 ;
if ( ! V_681 . V_674 )
break;
F_285 ( V_2 , V_681 . V_674 ) ;
V_120 = - V_101 ;
if ( F_234 ( V_560 , V_681 . V_674 ,
sizeof( struct V_671 ) ) )
break;
V_120 = 0 ;
break;
}
case V_708 : {
V_681 . V_674 = F_198 ( V_560 , sizeof( * V_681 . V_674 ) ) ;
if ( F_199 ( V_681 . V_674 ) )
return F_200 ( V_681 . V_674 ) ;
V_120 = F_286 ( V_2 , V_681 . V_674 ) ;
break;
}
case V_709 : {
T_1 V_267 ;
V_120 = - V_578 ;
V_267 = ( T_1 ) V_559 ;
if ( V_267 >= V_710 )
goto V_113;
if ( V_267 == 0 )
V_267 = V_273 ;
if ( ! F_140 ( V_2 , V_267 ) )
V_120 = 0 ;
goto V_113;
}
case V_711 : {
V_120 = V_2 -> V_5 . V_282 ;
goto V_113;
}
case V_712 : {
V_120 = F_287 ( V_2 ) ;
goto V_113;
}
case V_713 : {
struct V_676 V_677 ;
V_120 = - V_101 ;
if ( F_233 ( & V_677 , V_560 , sizeof( V_677 ) ) )
goto V_113;
V_120 = F_288 ( V_2 , & V_677 ) ;
break;
}
default:
V_120 = - V_578 ;
}
V_113:
F_202 ( V_681 . V_680 ) ;
return V_120 ;
}
int F_296 ( struct V_1 * V_2 , struct V_714 * V_715 )
{
return V_716 ;
}
static int F_297 ( struct V_138 * V_138 , unsigned long V_614 )
{
int V_108 ;
if ( V_614 > ( unsigned int ) ( - 3 * V_107 ) )
return - V_578 ;
V_108 = V_73 -> V_717 ( V_138 , V_614 ) ;
return V_108 ;
}
static int F_298 ( struct V_138 * V_138 ,
T_2 V_718 )
{
V_138 -> V_5 . V_719 = V_718 ;
return 0 ;
}
static int F_299 ( struct V_138 * V_138 ,
T_1 V_720 )
{
if ( V_720 < V_721 )
return - V_578 ;
F_300 ( & V_138 -> V_722 ) ;
F_301 ( V_138 , V_720 ) ;
V_138 -> V_5 . V_723 = V_720 ;
F_302 ( & V_138 -> V_722 ) ;
return 0 ;
}
static int F_303 ( struct V_138 * V_138 )
{
return V_138 -> V_5 . V_724 ;
}
static int F_304 ( struct V_138 * V_138 , struct V_725 * V_726 )
{
int V_120 ;
V_120 = 0 ;
switch ( V_726 -> V_727 ) {
case V_728 :
memcpy ( & V_726 -> V_726 . V_729 ,
& F_305 ( V_138 ) -> V_730 [ 0 ] ,
sizeof( struct V_731 ) ) ;
break;
case V_732 :
memcpy ( & V_726 -> V_726 . V_729 ,
& F_305 ( V_138 ) -> V_730 [ 1 ] ,
sizeof( struct V_731 ) ) ;
break;
case V_733 :
V_120 = F_306 ( V_138 , & V_726 -> V_726 . V_734 ) ;
break;
default:
V_120 = - V_578 ;
break;
}
return V_120 ;
}
static int F_307 ( struct V_138 * V_138 , struct V_725 * V_726 )
{
int V_120 ;
V_120 = 0 ;
switch ( V_726 -> V_727 ) {
case V_728 :
F_158 ( & F_305 ( V_138 ) -> V_735 ) ;
memcpy ( & F_305 ( V_138 ) -> V_730 [ 0 ] ,
& V_726 -> V_726 . V_729 ,
sizeof( struct V_731 ) ) ;
F_159 ( & F_305 ( V_138 ) -> V_735 ) ;
break;
case V_732 :
F_158 ( & F_305 ( V_138 ) -> V_735 ) ;
memcpy ( & F_305 ( V_138 ) -> V_730 [ 1 ] ,
& V_726 -> V_726 . V_729 ,
sizeof( struct V_731 ) ) ;
F_159 ( & F_305 ( V_138 ) -> V_735 ) ;
break;
case V_733 :
V_120 = F_308 ( V_138 , & V_726 -> V_726 . V_734 ) ;
break;
default:
V_120 = - V_578 ;
break;
}
F_309 ( F_305 ( V_138 ) ) ;
return V_120 ;
}
static int F_310 ( struct V_138 * V_138 , struct V_736 * V_737 )
{
struct V_738 * V_739 = & V_138 -> V_5 . V_740 -> V_741 ;
F_184 ( sizeof( * V_737 ) != sizeof( V_739 -> V_742 ) ) ;
F_300 ( & V_739 -> V_735 ) ;
memcpy ( V_737 , & V_739 -> V_742 , sizeof( * V_737 ) ) ;
F_302 ( & V_739 -> V_735 ) ;
return 0 ;
}
static int F_311 ( struct V_138 * V_138 , struct V_736 * V_737 )
{
int V_3 ;
struct V_743 * V_744 = V_138 -> V_5 . V_740 ;
F_300 ( & V_744 -> V_741 . V_735 ) ;
memcpy ( & V_744 -> V_741 . V_742 , V_737 , sizeof( * V_737 ) ) ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
F_312 ( V_744 , V_3 , V_737 -> V_742 [ V_3 ] . V_745 , 0 ) ;
F_302 ( & V_744 -> V_741 . V_735 ) ;
return 0 ;
}
static int F_313 ( struct V_138 * V_138 , struct V_746 * V_737 )
{
F_300 ( & V_138 -> V_5 . V_740 -> V_741 . V_735 ) ;
memcpy ( V_737 -> V_742 , & V_138 -> V_5 . V_740 -> V_741 . V_742 ,
sizeof( V_737 -> V_742 ) ) ;
V_737 -> V_307 = V_138 -> V_5 . V_740 -> V_741 . V_307 ;
F_302 ( & V_138 -> V_5 . V_740 -> V_741 . V_735 ) ;
memset ( & V_737 -> V_640 , 0 , sizeof( V_737 -> V_640 ) ) ;
return 0 ;
}
static int F_314 ( struct V_138 * V_138 , struct V_746 * V_737 )
{
int V_747 = 0 ;
int V_3 ;
T_1 V_748 , V_749 ;
struct V_743 * V_744 = V_138 -> V_5 . V_740 ;
F_300 ( & V_744 -> V_741 . V_735 ) ;
V_748 = V_744 -> V_741 . V_307 & V_750 ;
V_749 = V_737 -> V_307 & V_750 ;
if ( ! V_748 && V_749 )
V_747 = 1 ;
memcpy ( & V_744 -> V_741 . V_742 , & V_737 -> V_742 ,
sizeof( V_744 -> V_741 . V_742 ) ) ;
V_744 -> V_741 . V_307 = V_737 -> V_307 ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
F_312 ( V_744 , V_3 , V_744 -> V_741 . V_742 [ V_3 ] . V_745 ,
V_747 && V_3 == 0 ) ;
F_302 ( & V_744 -> V_741 . V_735 ) ;
return 0 ;
}
static int F_315 ( struct V_138 * V_138 ,
struct V_751 * V_752 )
{
struct V_743 * V_744 = V_138 -> V_5 . V_740 ;
if ( ! V_744 )
return - V_597 ;
F_300 ( & V_744 -> V_741 . V_735 ) ;
F_316 ( V_744 , V_752 -> V_753 ) ;
F_302 ( & V_744 -> V_741 . V_735 ) ;
return 0 ;
}
int F_317 ( struct V_138 * V_138 , struct V_754 * log )
{
bool V_755 = false ;
int V_120 ;
F_300 ( & V_138 -> V_722 ) ;
if ( V_73 -> V_756 )
V_73 -> V_756 ( V_138 ) ;
V_120 = F_318 ( V_138 , log , & V_755 ) ;
F_319 ( & V_138 -> V_722 ) ;
if ( V_755 )
F_320 ( V_138 ) ;
F_302 ( & V_138 -> V_722 ) ;
return V_120 ;
}
int F_321 ( struct V_138 * V_138 , struct V_757 * V_758 ,
bool V_759 )
{
if ( ! F_261 ( V_138 ) )
return - V_597 ;
V_758 -> V_461 = F_322 ( V_138 , V_760 ,
V_758 -> V_595 , V_758 -> V_761 ,
V_759 ) ;
return 0 ;
}
static int F_323 ( struct V_138 * V_138 ,
struct V_676 * V_677 )
{
int V_120 ;
if ( V_677 -> V_307 )
return - V_578 ;
switch ( V_677 -> V_677 ) {
case V_532 :
V_138 -> V_5 . V_762 = V_677 -> args [ 0 ] ;
V_120 = 0 ;
break;
case V_534 : {
F_300 ( & V_138 -> V_735 ) ;
V_120 = - V_578 ;
if ( V_677 -> args [ 0 ] > V_763 )
goto V_764;
V_120 = - V_599 ;
if ( F_261 ( V_138 ) )
goto V_764;
if ( F_143 ( & V_138 -> V_293 ) )
goto V_764;
V_120 = F_324 ( V_138 ) ;
if ( V_120 )
goto V_764;
F_187 () ;
V_138 -> V_5 . V_765 = true ;
V_138 -> V_5 . V_766 = V_677 -> args [ 0 ] ;
V_120 = 0 ;
V_764:
F_302 ( & V_138 -> V_735 ) ;
break;
}
default:
V_120 = - V_578 ;
break;
}
return V_120 ;
}
long F_325 ( struct V_556 * V_557 ,
unsigned int V_558 , unsigned long V_559 )
{
struct V_138 * V_138 = V_557 -> V_678 ;
void T_15 * V_560 = ( void T_15 * ) V_559 ;
int V_120 = - V_767 ;
union {
struct V_736 V_737 ;
struct V_746 V_768 ;
struct V_769 V_770 ;
} V_681 ;
switch ( V_558 ) {
case V_771 :
V_120 = F_297 ( V_138 , V_559 ) ;
break;
case V_772 : {
T_2 V_718 ;
V_120 = - V_101 ;
if ( F_233 ( & V_718 , V_560 , sizeof V_718 ) )
goto V_113;
V_120 = F_298 ( V_138 , V_718 ) ;
break;
}
case V_773 :
V_120 = F_299 ( V_138 , V_559 ) ;
break;
case V_774 :
V_120 = F_303 ( V_138 ) ;
break;
case V_775 : {
struct V_776 * V_777 ;
F_300 ( & V_138 -> V_735 ) ;
V_120 = - V_599 ;
if ( V_138 -> V_5 . V_777 )
goto V_778;
V_120 = - V_578 ;
if ( F_143 ( & V_138 -> V_293 ) )
goto V_778;
V_120 = - V_387 ;
V_777 = F_326 ( V_138 ) ;
if ( V_777 ) {
V_120 = F_327 ( V_138 ) ;
if ( V_120 ) {
F_300 ( & V_138 -> V_722 ) ;
F_328 ( V_777 ) ;
F_302 ( & V_138 -> V_722 ) ;
goto V_778;
}
} else
goto V_778;
V_120 = F_329 ( V_138 ) ;
if ( V_120 ) {
F_300 ( & V_138 -> V_722 ) ;
F_300 ( & V_138 -> V_779 ) ;
F_330 ( V_138 ) ;
F_328 ( V_777 ) ;
F_302 ( & V_138 -> V_779 ) ;
F_302 ( & V_138 -> V_722 ) ;
goto V_778;
}
F_187 () ;
V_138 -> V_5 . V_777 = V_777 ;
V_778:
F_302 ( & V_138 -> V_735 ) ;
break;
}
case V_780 :
V_681 . V_770 . V_307 = V_781 ;
goto V_782;
case V_783 :
V_120 = - V_101 ;
if ( F_233 ( & V_681 . V_770 , V_560 ,
sizeof( struct V_769 ) ) )
goto V_113;
V_782:
F_300 ( & V_138 -> V_722 ) ;
V_120 = - V_599 ;
if ( V_138 -> V_5 . V_740 )
goto V_784;
V_120 = - V_387 ;
V_138 -> V_5 . V_740 = F_331 ( V_138 , V_681 . V_770 . V_307 ) ;
if ( V_138 -> V_5 . V_740 )
V_120 = 0 ;
V_784:
F_302 ( & V_138 -> V_722 ) ;
break;
case V_785 : {
struct V_725 * V_726 ;
V_726 = F_198 ( V_560 , sizeof( * V_726 ) ) ;
if ( F_199 ( V_726 ) ) {
V_120 = F_200 ( V_726 ) ;
goto V_113;
}
V_120 = - V_597 ;
if ( ! F_261 ( V_138 ) || V_765 ( V_138 ) )
goto V_786;
V_120 = F_304 ( V_138 , V_726 ) ;
if ( V_120 )
goto V_786;
V_120 = - V_101 ;
if ( F_234 ( V_560 , V_726 , sizeof *V_726 ) )
goto V_786;
V_120 = 0 ;
V_786:
F_202 ( V_726 ) ;
break;
}
case V_787 : {
struct V_725 * V_726 ;
V_726 = F_198 ( V_560 , sizeof( * V_726 ) ) ;
if ( F_199 ( V_726 ) ) {
V_120 = F_200 ( V_726 ) ;
goto V_113;
}
V_120 = - V_597 ;
if ( ! F_261 ( V_138 ) || V_765 ( V_138 ) )
goto V_788;
V_120 = F_307 ( V_138 , V_726 ) ;
if ( V_120 )
goto V_788;
V_120 = 0 ;
V_788:
F_202 ( V_726 ) ;
break;
}
case V_789 : {
V_120 = - V_101 ;
if ( F_233 ( & V_681 . V_737 , V_560 , sizeof( struct V_736 ) ) )
goto V_113;
V_120 = - V_597 ;
if ( ! V_138 -> V_5 . V_740 )
goto V_113;
V_120 = F_310 ( V_138 , & V_681 . V_737 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_234 ( V_560 , & V_681 . V_737 , sizeof( struct V_736 ) ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_790 : {
V_120 = - V_101 ;
if ( F_233 ( & V_681 . V_737 , V_560 , sizeof V_681 . V_737 ) )
goto V_113;
V_120 = - V_597 ;
if ( ! V_138 -> V_5 . V_740 )
goto V_113;
V_120 = F_311 ( V_138 , & V_681 . V_737 ) ;
break;
}
case V_791 : {
V_120 = - V_597 ;
if ( ! V_138 -> V_5 . V_740 )
goto V_113;
V_120 = F_313 ( V_138 , & V_681 . V_768 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_234 ( V_560 , & V_681 . V_768 , sizeof( V_681 . V_768 ) ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_792 : {
V_120 = - V_101 ;
if ( F_233 ( & V_681 . V_768 , V_560 , sizeof( V_681 . V_768 ) ) )
goto V_113;
V_120 = - V_597 ;
if ( ! V_138 -> V_5 . V_740 )
goto V_113;
V_120 = F_314 ( V_138 , & V_681 . V_768 ) ;
break;
}
case V_793 : {
struct V_751 V_752 ;
V_120 = - V_101 ;
if ( F_233 ( & V_752 , V_560 , sizeof( V_752 ) ) )
goto V_113;
V_120 = F_315 ( V_138 , & V_752 ) ;
break;
}
case V_794 :
V_120 = 0 ;
F_300 ( & V_138 -> V_735 ) ;
if ( F_143 ( & V_138 -> V_293 ) != 0 )
V_120 = - V_795 ;
else
V_138 -> V_5 . V_796 = V_559 ;
F_302 ( & V_138 -> V_735 ) ;
break;
case V_797 : {
V_120 = - V_101 ;
if ( F_233 ( & V_138 -> V_5 . F_197 , V_560 ,
sizeof( struct V_798 ) ) )
goto V_113;
V_120 = - V_578 ;
if ( V_138 -> V_5 . F_197 . V_307 )
goto V_113;
V_120 = 0 ;
break;
}
case V_799 : {
struct V_800 V_801 ;
T_2 V_802 ;
T_12 V_318 ;
V_120 = - V_101 ;
if ( F_233 ( & V_801 , V_560 , sizeof( V_801 ) ) )
goto V_113;
V_120 = - V_578 ;
if ( V_801 . V_307 )
goto V_113;
V_120 = 0 ;
F_332 () ;
V_802 = F_154 () ;
V_318 = V_801 . clock - V_802 ;
F_333 () ;
V_138 -> V_5 . V_246 = V_318 ;
F_176 ( V_138 ) ;
break;
}
case V_803 : {
struct V_800 V_801 ;
T_2 V_802 ;
F_332 () ;
V_802 = F_154 () ;
V_801 . clock = V_138 -> V_5 . V_246 + V_802 ;
F_333 () ;
V_801 . V_307 = 0 ;
memset ( & V_801 . V_619 , 0 , sizeof( V_801 . V_619 ) ) ;
V_120 = - V_101 ;
if ( F_234 ( V_560 , & V_801 , sizeof( V_801 ) ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_713 : {
struct V_676 V_677 ;
V_120 = - V_101 ;
if ( F_233 ( & V_677 , V_560 , sizeof( V_677 ) ) )
goto V_113;
V_120 = F_323 ( V_138 , & V_677 ) ;
break;
}
default:
V_120 = F_334 ( V_138 , V_558 , V_559 ) ;
}
V_113:
return V_120 ;
}
static void F_335 ( void )
{
T_1 V_804 [ 2 ] ;
unsigned V_3 , V_805 ;
for ( V_3 = V_805 = 0 ; V_3 < F_52 ( V_568 ) ; V_3 ++ ) {
if ( F_336 ( V_568 [ V_3 ] , & V_804 [ 0 ] , & V_804 [ 1 ] ) < 0 )
continue;
switch ( V_568 [ V_3 ] ) {
case V_806 :
if ( ! V_73 -> V_807 () )
continue;
break;
case V_808 :
if ( ! V_73 -> V_809 () )
continue;
break;
default:
break;
}
if ( V_805 < V_3 )
V_568 [ V_805 ] = V_568 [ V_3 ] ;
V_805 ++ ;
}
V_565 = V_805 ;
for ( V_3 = V_805 = 0 ; V_3 < F_52 ( V_569 ) ; V_3 ++ ) {
switch ( V_569 [ V_3 ] ) {
case V_424 :
if ( ! V_73 -> V_538 () )
continue;
break;
default:
break;
}
if ( V_805 < V_3 )
V_569 [ V_805 ] = V_569 [ V_3 ] ;
V_805 ++ ;
}
V_566 = V_805 ;
}
static int F_337 ( struct V_1 * V_2 , T_6 V_614 , int V_95 ,
const void * V_266 )
{
int V_810 = 0 ;
int V_490 ;
do {
V_490 = F_338 ( V_95 , 8 ) ;
if ( ! ( F_89 ( V_2 ) &&
! F_339 ( V_2 , & V_2 -> V_5 . V_593 -> V_811 , V_614 , V_490 , V_266 ) )
&& F_340 ( V_2 , V_812 , V_614 , V_490 , V_266 ) )
break;
V_810 += V_490 ;
V_614 += V_490 ;
V_95 -= V_490 ;
V_266 += V_490 ;
} while ( V_95 );
return V_810 ;
}
static int F_341 ( struct V_1 * V_2 , T_6 V_614 , int V_95 , void * V_266 )
{
int V_810 = 0 ;
int V_490 ;
do {
V_490 = F_338 ( V_95 , 8 ) ;
if ( ! ( F_89 ( V_2 ) &&
! F_342 ( V_2 , & V_2 -> V_5 . V_593 -> V_811 ,
V_614 , V_490 , V_266 ) )
&& F_343 ( V_2 , V_812 , V_614 , V_490 , V_266 ) )
break;
F_344 ( V_813 , V_490 , V_614 , * ( T_2 * ) V_266 ) ;
V_810 += V_490 ;
V_614 += V_490 ;
V_95 -= V_490 ;
V_266 += V_490 ;
} while ( V_95 );
return V_810 ;
}
static void F_345 ( struct V_1 * V_2 ,
struct V_814 * V_815 , int V_816 )
{
V_73 -> V_817 ( V_2 , V_815 , V_816 ) ;
}
void F_346 ( struct V_1 * V_2 ,
struct V_814 * V_815 , int V_816 )
{
V_73 -> V_818 ( V_2 , V_815 , V_816 ) ;
}
T_6 F_347 ( struct V_1 * V_2 , T_6 V_389 , T_1 V_96 ,
struct V_75 * V_68 )
{
T_6 V_819 ;
F_13 ( ! F_39 ( V_2 ) ) ;
V_96 |= V_111 ;
V_819 = V_2 -> V_5 . V_84 . V_820 ( V_2 , V_389 , V_96 , V_68 ) ;
return V_819 ;
}
T_6 F_348 ( struct V_1 * V_2 , T_16 V_821 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
return V_2 -> V_5 . V_103 -> V_820 ( V_2 , V_821 , V_96 , V_68 ) ;
}
T_6 F_349 ( struct V_1 * V_2 , T_16 V_821 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
V_96 |= V_822 ;
return V_2 -> V_5 . V_103 -> V_820 ( V_2 , V_821 , V_96 , V_68 ) ;
}
T_6 F_350 ( struct V_1 * V_2 , T_16 V_821 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
V_96 |= V_112 ;
return V_2 -> V_5 . V_103 -> V_820 ( V_2 , V_821 , V_96 , V_68 ) ;
}
T_6 F_351 ( struct V_1 * V_2 , T_16 V_821 ,
struct V_75 * V_68 )
{
return V_2 -> V_5 . V_103 -> V_820 ( V_2 , V_821 , 0 , V_68 ) ;
}
static int F_352 ( T_16 V_614 , void * V_195 , unsigned int V_823 ,
struct V_1 * V_2 , T_1 V_96 ,
struct V_75 * V_68 )
{
void * V_38 = V_195 ;
int V_120 = V_824 ;
while ( V_823 ) {
T_6 V_389 = V_2 -> V_5 . V_103 -> V_820 ( V_2 , V_614 , V_96 ,
V_68 ) ;
unsigned V_94 = V_614 & ( V_107 - 1 ) ;
unsigned V_825 = F_338 ( V_823 , ( unsigned ) V_107 - V_94 ) ;
int V_108 ;
if ( V_389 == V_100 )
return V_826 ;
V_108 = F_49 ( V_2 , V_389 >> V_106 , V_38 ,
V_94 , V_825 ) ;
if ( V_108 < 0 ) {
V_120 = V_827 ;
goto V_113;
}
V_823 -= V_825 ;
V_38 += V_825 ;
V_614 += V_825 ;
}
V_113:
return V_120 ;
}
static int F_353 ( struct V_828 * V_829 ,
T_16 V_614 , void * V_195 , unsigned int V_823 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_354 ( V_829 ) ;
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
unsigned V_94 ;
int V_108 ;
T_6 V_389 = V_2 -> V_5 . V_103 -> V_820 ( V_2 , V_614 , V_96 | V_822 ,
V_68 ) ;
if ( F_168 ( V_389 == V_100 ) )
return V_826 ;
V_94 = V_614 & ( V_107 - 1 ) ;
if ( F_28 ( V_94 + V_823 > V_107 ) )
V_823 = ( unsigned ) V_107 - V_94 ;
V_108 = F_49 ( V_2 , V_389 >> V_106 , V_195 ,
V_94 , V_823 ) ;
if ( F_168 ( V_108 < 0 ) )
return V_827 ;
return V_824 ;
}
int F_355 ( struct V_828 * V_829 ,
T_16 V_614 , void * V_195 , unsigned int V_823 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_354 ( V_829 ) ;
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
return F_352 ( V_614 , V_195 , V_823 , V_2 , V_96 ,
V_68 ) ;
}
static int F_356 ( struct V_828 * V_829 ,
T_16 V_614 , void * V_195 , unsigned int V_823 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_354 ( V_829 ) ;
return F_352 ( V_614 , V_195 , V_823 , V_2 , 0 , V_68 ) ;
}
static int F_357 ( struct V_828 * V_829 ,
unsigned long V_614 , void * V_195 , unsigned int V_823 )
{
struct V_1 * V_2 = F_354 ( V_829 ) ;
int V_120 = F_358 ( V_2 , V_614 , V_195 , V_823 ) ;
return V_120 < 0 ? V_827 : V_824 ;
}
int F_359 ( struct V_828 * V_829 ,
T_16 V_614 , void * V_195 ,
unsigned int V_823 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_354 ( V_829 ) ;
void * V_38 = V_195 ;
int V_120 = V_824 ;
while ( V_823 ) {
T_6 V_389 = V_2 -> V_5 . V_103 -> V_820 ( V_2 , V_614 ,
V_112 ,
V_68 ) ;
unsigned V_94 = V_614 & ( V_107 - 1 ) ;
unsigned V_830 = F_338 ( V_823 , ( unsigned ) V_107 - V_94 ) ;
int V_108 ;
if ( V_389 == V_100 )
return V_826 ;
V_108 = F_201 ( V_2 , V_389 , V_38 , V_830 ) ;
if ( V_108 < 0 ) {
V_120 = V_827 ;
goto V_113;
}
V_823 -= V_830 ;
V_38 += V_830 ;
V_614 += V_830 ;
}
V_113:
return V_120 ;
}
static int F_360 ( struct V_1 * V_2 , unsigned long V_821 ,
T_6 * V_389 , struct V_75 * V_68 ,
bool V_831 )
{
T_1 V_96 = ( ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 )
| ( V_831 ? V_112 : 0 ) ;
if ( F_361 ( V_2 , V_821 )
&& ! F_362 ( V_2 , V_2 -> V_5 . V_103 ,
V_2 -> V_5 . V_96 , 0 , V_96 ) ) {
* V_389 = V_2 -> V_5 . V_832 << V_106 |
( V_821 & ( V_107 - 1 ) ) ;
F_363 ( V_821 , * V_389 , V_831 , false ) ;
return 1 ;
}
* V_389 = V_2 -> V_5 . V_103 -> V_820 ( V_2 , V_821 , V_96 , V_68 ) ;
if ( * V_389 == V_100 )
return - 1 ;
if ( ( * V_389 & V_383 ) == V_833 )
return 1 ;
if ( F_364 ( V_2 , * V_389 ) ) {
F_363 ( V_821 , * V_389 , V_831 , true ) ;
return 1 ;
}
return 0 ;
}
int F_365 ( struct V_1 * V_2 , T_6 V_389 ,
const void * V_195 , int V_823 )
{
int V_108 ;
V_108 = F_201 ( V_2 , V_389 , V_195 , V_823 ) ;
if ( V_108 < 0 )
return 0 ;
F_366 ( V_2 , V_389 , V_195 , V_823 ) ;
return 1 ;
}
static int F_367 ( struct V_1 * V_2 , void * V_195 , int V_823 )
{
if ( V_2 -> V_834 ) {
F_344 ( V_813 , V_823 ,
V_2 -> V_835 [ 0 ] . V_389 , * ( T_2 * ) V_195 ) ;
V_2 -> V_834 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_368 ( struct V_1 * V_2 , T_6 V_389 ,
void * V_195 , int V_823 )
{
return ! F_358 ( V_2 , V_389 , V_195 , V_823 ) ;
}
static int F_369 ( struct V_1 * V_2 , T_6 V_389 ,
void * V_195 , int V_823 )
{
return F_365 ( V_2 , V_389 , V_195 , V_823 ) ;
}
static int F_370 ( struct V_1 * V_2 , T_6 V_389 , int V_823 , void * V_195 )
{
F_344 ( V_836 , V_823 , V_389 , * ( T_2 * ) V_195 ) ;
return F_337 ( V_2 , V_389 , V_823 , V_195 ) ;
}
static int F_371 ( struct V_1 * V_2 , T_6 V_389 ,
void * V_195 , int V_823 )
{
F_344 ( V_837 , V_823 , V_389 , 0 ) ;
return V_827 ;
}
static int F_372 ( struct V_1 * V_2 , T_6 V_389 ,
void * V_195 , int V_823 )
{
struct V_838 * V_839 = & V_2 -> V_835 [ 0 ] ;
memcpy ( V_2 -> V_840 -> V_841 . V_38 , V_839 -> V_38 , F_338 ( 8u , V_839 -> V_95 ) ) ;
return V_824 ;
}
static int F_373 ( unsigned long V_614 , void * V_195 ,
unsigned int V_823 ,
struct V_75 * V_68 ,
struct V_1 * V_2 ,
const struct V_842 * V_843 )
{
T_6 V_389 ;
int V_810 , V_108 ;
bool V_831 = V_843 -> V_831 ;
struct V_838 * V_839 ;
V_108 = F_360 ( V_2 , V_614 , & V_389 , V_68 , V_831 ) ;
if ( V_108 < 0 )
return V_826 ;
if ( V_108 )
goto V_841;
if ( V_843 -> V_844 ( V_2 , V_389 , V_195 , V_823 ) )
return V_824 ;
V_841:
V_810 = V_843 -> V_845 ( V_2 , V_389 , V_823 , V_195 ) ;
if ( V_810 == V_823 )
return V_824 ;
V_389 += V_810 ;
V_823 -= V_810 ;
V_195 += V_810 ;
F_28 ( V_2 -> V_846 >= V_847 ) ;
V_839 = & V_2 -> V_835 [ V_2 -> V_846 ++ ] ;
V_839 -> V_389 = V_389 ;
V_839 -> V_38 = V_195 ;
V_839 -> V_95 = V_823 ;
return V_824 ;
}
static int F_374 ( struct V_828 * V_829 ,
unsigned long V_614 ,
void * V_195 , unsigned int V_823 ,
struct V_75 * V_68 ,
const struct V_842 * V_843 )
{
struct V_1 * V_2 = F_354 ( V_829 ) ;
T_6 V_389 ;
int V_848 ;
if ( V_843 -> V_849 &&
V_843 -> V_849 ( V_2 , V_195 , V_823 ) )
return V_824 ;
V_2 -> V_846 = 0 ;
if ( ( ( V_614 + V_823 - 1 ) ^ V_614 ) & V_383 ) {
int V_850 ;
V_850 = - V_614 & ~ V_383 ;
V_848 = F_373 ( V_614 , V_195 , V_850 , V_68 ,
V_2 , V_843 ) ;
if ( V_848 != V_824 )
return V_848 ;
V_614 += V_850 ;
if ( V_829 -> V_330 != V_851 )
V_614 = ( T_1 ) V_614 ;
V_195 += V_850 ;
V_823 -= V_850 ;
}
V_848 = F_373 ( V_614 , V_195 , V_823 , V_68 ,
V_2 , V_843 ) ;
if ( V_848 != V_824 )
return V_848 ;
if ( ! V_2 -> V_846 )
return V_848 ;
V_389 = V_2 -> V_835 [ 0 ] . V_389 ;
V_2 -> V_852 = 1 ;
V_2 -> V_853 = 0 ;
V_2 -> V_840 -> V_841 . V_95 = F_338 ( 8u , V_2 -> V_835 [ 0 ] . V_95 ) ;
V_2 -> V_840 -> V_841 . V_854 = V_2 -> V_855 = V_843 -> V_831 ;
V_2 -> V_840 -> V_856 = V_857 ;
V_2 -> V_840 -> V_841 . V_858 = V_389 ;
return V_843 -> V_859 ( V_2 , V_389 , V_195 , V_823 ) ;
}
static int F_375 ( struct V_828 * V_829 ,
unsigned long V_614 ,
void * V_195 ,
unsigned int V_823 ,
struct V_75 * V_68 )
{
return F_374 ( V_829 , V_614 , V_195 , V_823 ,
V_68 , & V_860 ) ;
}
static int F_376 ( struct V_828 * V_829 ,
unsigned long V_614 ,
const void * V_195 ,
unsigned int V_823 ,
struct V_75 * V_68 )
{
return F_374 ( V_829 , V_614 , ( void * ) V_195 , V_823 ,
V_68 , & V_861 ) ;
}
static int F_377 ( struct V_828 * V_829 ,
unsigned long V_614 ,
const void * V_862 ,
const void * V_863 ,
unsigned int V_823 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_354 ( V_829 ) ;
T_6 V_389 ;
struct V_385 * V_385 ;
char * V_864 ;
bool V_865 ;
if ( V_823 > 8 || ( V_823 & ( V_823 - 1 ) ) )
goto V_866;
V_389 = F_350 ( V_2 , V_614 , NULL ) ;
if ( V_389 == V_100 ||
( V_389 & V_383 ) == V_833 )
goto V_866;
if ( ( ( V_389 + V_823 - 1 ) & V_383 ) != ( V_389 & V_383 ) )
goto V_866;
V_385 = F_378 ( V_2 , V_389 >> V_106 ) ;
if ( F_379 ( V_385 ) )
goto V_866;
V_864 = F_380 ( V_385 ) ;
V_864 += F_381 ( V_389 ) ;
switch ( V_823 ) {
case 1 :
V_865 = F_382 ( T_14 , V_864 , V_862 , V_863 ) ;
break;
case 2 :
V_865 = F_382 ( V_867 , V_864 , V_862 , V_863 ) ;
break;
case 4 :
V_865 = F_382 ( T_1 , V_864 , V_862 , V_863 ) ;
break;
case 8 :
V_865 = F_383 ( V_864 , V_862 , V_863 ) ;
break;
default:
F_25 () ;
}
F_384 ( V_864 ) ;
F_385 ( V_385 ) ;
if ( ! V_865 )
return V_868 ;
F_386 ( V_2 , V_389 >> V_106 ) ;
F_366 ( V_2 , V_389 , V_863 , V_823 ) ;
return V_824 ;
V_866:
F_387 ( V_869 L_20 ) ;
return F_376 ( V_829 , V_614 , V_863 , V_823 , V_68 ) ;
}
static int F_388 ( struct V_1 * V_2 , void * V_870 )
{
int V_120 ;
if ( V_2 -> V_5 . V_871 . V_872 )
V_120 = F_343 ( V_2 , V_873 , V_2 -> V_5 . V_871 . V_874 ,
V_2 -> V_5 . V_871 . V_491 , V_870 ) ;
else
V_120 = F_340 ( V_2 , V_873 ,
V_2 -> V_5 . V_871 . V_874 , V_2 -> V_5 . V_871 . V_491 ,
V_870 ) ;
return V_120 ;
}
static int F_389 ( struct V_1 * V_2 , int V_491 ,
unsigned short V_874 , void * V_195 ,
unsigned int V_745 , bool V_872 )
{
V_2 -> V_5 . V_871 . V_874 = V_874 ;
V_2 -> V_5 . V_871 . V_872 = V_872 ;
V_2 -> V_5 . V_871 . V_745 = V_745 ;
V_2 -> V_5 . V_871 . V_491 = V_491 ;
if ( ! F_388 ( V_2 , V_2 -> V_5 . V_875 ) ) {
V_2 -> V_5 . V_871 . V_745 = 0 ;
return 1 ;
}
V_2 -> V_840 -> V_856 = V_876 ;
V_2 -> V_840 -> V_877 . V_878 = V_872 ? V_879 : V_880 ;
V_2 -> V_840 -> V_877 . V_491 = V_491 ;
V_2 -> V_840 -> V_877 . V_881 = V_882 * V_107 ;
V_2 -> V_840 -> V_877 . V_745 = V_745 ;
V_2 -> V_840 -> V_877 . V_874 = V_874 ;
return 0 ;
}
static int F_390 ( struct V_828 * V_829 ,
int V_491 , unsigned short V_874 , void * V_195 ,
unsigned int V_745 )
{
struct V_1 * V_2 = F_354 ( V_829 ) ;
int V_108 ;
if ( V_2 -> V_5 . V_871 . V_745 )
goto V_883;
V_108 = F_389 ( V_2 , V_491 , V_874 , V_195 , V_745 , true ) ;
if ( V_108 ) {
V_883:
memcpy ( V_195 , V_2 -> V_5 . V_875 , V_491 * V_745 ) ;
F_391 ( V_884 , V_874 , V_491 , V_745 , V_2 -> V_5 . V_875 ) ;
V_2 -> V_5 . V_871 . V_745 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_392 ( struct V_828 * V_829 ,
int V_491 , unsigned short V_874 ,
const void * V_195 , unsigned int V_745 )
{
struct V_1 * V_2 = F_354 ( V_829 ) ;
memcpy ( V_2 -> V_5 . V_875 , V_195 , V_491 * V_745 ) ;
F_391 ( V_885 , V_874 , V_491 , V_745 , V_2 -> V_5 . V_875 ) ;
return F_389 ( V_2 , V_491 , V_874 , ( void * ) V_195 , V_745 , false ) ;
}
static unsigned long F_393 ( struct V_1 * V_2 , int V_816 )
{
return V_73 -> F_393 ( V_2 , V_816 ) ;
}
static void F_394 ( struct V_828 * V_829 , V_175 V_80 )
{
F_395 ( F_354 ( V_829 ) , V_80 ) ;
}
int F_396 ( struct V_1 * V_2 )
{
if ( ! F_242 ( V_2 ) )
return V_824 ;
if ( V_73 -> V_581 () ) {
int V_23 = F_397 () ;
F_245 ( V_23 , V_2 -> V_5 . V_582 ) ;
F_398 ( V_2 -> V_5 . V_582 ,
F_240 , NULL , 1 ) ;
F_399 () ;
F_400 ( V_2 -> V_5 . V_582 ) ;
} else
F_241 () ;
return V_824 ;
}
int F_401 ( struct V_1 * V_2 )
{
V_73 -> V_74 ( V_2 ) ;
return F_396 ( V_2 ) ;
}
static void F_402 ( struct V_828 * V_829 )
{
F_396 ( F_354 ( V_829 ) ) ;
}
static int F_403 ( struct V_828 * V_829 , int V_89 ,
unsigned long * V_649 )
{
return F_100 ( F_354 ( V_829 ) , V_89 , V_649 ) ;
}
static int F_404 ( struct V_828 * V_829 , int V_89 ,
unsigned long V_22 )
{
return F_98 ( F_354 ( V_829 ) , V_89 , V_22 ) ;
}
static T_2 F_405 ( T_2 V_886 , T_1 V_887 )
{
return ( V_886 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_887 ;
}
static unsigned long F_406 ( struct V_828 * V_829 , int V_888 )
{
struct V_1 * V_2 = F_354 ( V_829 ) ;
unsigned long V_22 ;
switch ( V_888 ) {
case 0 :
V_22 = F_61 ( V_2 ) ;
break;
case 2 :
V_22 = V_2 -> V_5 . V_79 ;
break;
case 3 :
V_22 = F_59 ( V_2 ) ;
break;
case 4 :
V_22 = F_78 ( V_2 ) ;
break;
case 8 :
V_22 = F_91 ( V_2 ) ;
break;
default:
F_407 ( L_21 , V_261 , V_888 ) ;
return 0 ;
}
return V_22 ;
}
static int F_408 ( struct V_828 * V_829 , int V_888 , V_175 V_195 )
{
struct V_1 * V_2 = F_354 ( V_829 ) ;
int V_889 = 0 ;
switch ( V_888 ) {
case 0 :
V_889 = F_60 ( V_2 , F_405 ( F_61 ( V_2 ) , V_195 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_79 = V_195 ;
break;
case 3 :
V_889 = F_85 ( V_2 , V_195 ) ;
break;
case 4 :
V_889 = F_77 ( V_2 , F_405 ( F_78 ( V_2 ) , V_195 ) ) ;
break;
case 8 :
V_889 = F_88 ( V_2 , V_195 ) ;
break;
default:
F_407 ( L_21 , V_261 , V_888 ) ;
V_889 = - 1 ;
}
return V_889 ;
}
static int F_409 ( struct V_828 * V_829 )
{
return V_73 -> V_88 ( F_354 ( V_829 ) ) ;
}
static void F_410 ( struct V_828 * V_829 , struct V_890 * V_891 )
{
V_73 -> V_892 ( F_354 ( V_829 ) , V_891 ) ;
}
static void F_411 ( struct V_828 * V_829 , struct V_890 * V_891 )
{
V_73 -> V_893 ( F_354 ( V_829 ) , V_891 ) ;
}
static void F_412 ( struct V_828 * V_829 , struct V_890 * V_891 )
{
V_73 -> V_894 ( F_354 ( V_829 ) , V_891 ) ;
}
static void F_413 ( struct V_828 * V_829 , struct V_890 * V_891 )
{
V_73 -> V_895 ( F_354 ( V_829 ) , V_891 ) ;
}
static unsigned long F_414 (
struct V_828 * V_829 , int V_816 )
{
return F_393 ( F_354 ( V_829 ) , V_816 ) ;
}
static bool F_415 ( struct V_828 * V_829 , V_867 * V_896 ,
struct V_897 * V_898 , T_1 * V_899 ,
int V_816 )
{
struct V_814 V_815 ;
F_346 ( F_354 ( V_829 ) , & V_815 , V_816 ) ;
* V_896 = V_815 . V_896 ;
if ( V_815 . V_900 ) {
memset ( V_898 , 0 , sizeof( * V_898 ) ) ;
return false ;
}
if ( V_815 . V_901 )
V_815 . V_902 >>= 12 ;
F_416 ( V_898 , V_815 . V_902 ) ;
F_417 ( V_898 , ( unsigned long ) V_815 . V_229 ) ;
#ifdef F_62
if ( V_899 )
* V_899 = V_815 . V_229 >> 32 ;
#endif
V_898 -> type = V_815 . type ;
V_898 -> V_589 = V_815 . V_589 ;
V_898 -> V_903 = V_815 . V_903 ;
V_898 -> V_904 = V_815 . V_905 ;
V_898 -> V_906 = V_815 . V_906 ;
V_898 -> V_907 = V_815 . V_907 ;
V_898 -> V_908 = V_815 . V_182 ;
V_898 -> V_901 = V_815 . V_901 ;
return true ;
}
static void F_418 ( struct V_828 * V_829 , V_867 V_896 ,
struct V_897 * V_898 , T_1 V_899 ,
int V_816 )
{
struct V_1 * V_2 = F_354 ( V_829 ) ;
struct V_814 V_815 ;
V_815 . V_896 = V_896 ;
V_815 . V_229 = F_419 ( V_898 ) ;
#ifdef F_62
V_815 . V_229 |= ( ( T_2 ) V_899 ) << 32 ;
#endif
V_815 . V_902 = F_420 ( V_898 ) ;
if ( V_898 -> V_901 )
V_815 . V_902 = ( V_815 . V_902 << 12 ) | 0xfff ;
V_815 . type = V_898 -> type ;
V_815 . V_903 = V_898 -> V_903 ;
V_815 . V_182 = V_898 -> V_908 ;
V_815 . V_589 = V_898 -> V_589 ;
V_815 . V_907 = V_898 -> V_907 ;
V_815 . V_901 = V_898 -> V_901 ;
V_815 . V_906 = V_898 -> V_906 ;
V_815 . V_905 = V_898 -> V_904 ;
V_815 . V_900 = ! V_815 . V_905 ;
V_815 . V_909 = 0 ;
F_345 ( V_2 , & V_815 , V_816 ) ;
return;
}
static int F_421 ( struct V_828 * V_829 ,
T_1 V_910 , T_2 * V_464 )
{
struct V_32 V_21 ;
int V_120 ;
V_21 . V_146 = V_910 ;
V_21 . V_40 = false ;
V_120 = F_114 ( F_354 ( V_829 ) , & V_21 ) ;
if ( V_120 )
return V_120 ;
* V_464 = V_21 . V_38 ;
return 0 ;
}
static int F_422 ( struct V_828 * V_829 ,
T_1 V_910 , T_2 V_38 )
{
struct V_32 V_21 ;
V_21 . V_38 = V_38 ;
V_21 . V_146 = V_910 ;
V_21 . V_40 = false ;
return F_110 ( F_354 ( V_829 ) , & V_21 ) ;
}
static T_2 F_423 ( struct V_828 * V_829 )
{
struct V_1 * V_2 = F_354 ( V_829 ) ;
return V_2 -> V_5 . V_425 ;
}
static void F_424 ( struct V_828 * V_829 , T_2 V_425 )
{
struct V_1 * V_2 = F_354 ( V_829 ) ;
V_2 -> V_5 . V_425 = V_425 ;
}
static int F_425 ( struct V_828 * V_829 ,
T_1 V_911 )
{
return F_426 ( F_354 ( V_829 ) , V_911 ) ;
}
static int F_427 ( struct V_828 * V_829 ,
T_1 V_911 , T_2 * V_464 )
{
return F_103 ( F_354 ( V_829 ) , V_911 , V_464 ) ;
}
static void F_428 ( struct V_828 * V_829 )
{
F_354 ( V_829 ) -> V_5 . V_912 = 1 ;
}
static void F_429 ( struct V_828 * V_829 )
{
F_430 () ;
F_431 ( F_354 ( V_829 ) ) ;
F_432 () ;
}
static void F_433 ( struct V_828 * V_829 )
{
F_434 () ;
}
static int F_435 ( struct V_828 * V_829 ,
struct V_913 * V_914 ,
enum V_915 V_916 )
{
return V_73 -> V_917 ( F_354 ( V_829 ) , V_914 , V_916 ) ;
}
static void F_436 ( struct V_828 * V_829 ,
T_1 * V_918 , T_1 * V_919 , T_1 * V_200 , T_1 * V_208 )
{
V_689 ( F_354 ( V_829 ) , V_918 , V_919 , V_200 , V_208 ) ;
}
static V_175 F_437 ( struct V_828 * V_829 , unsigned V_920 )
{
return F_102 ( F_354 ( V_829 ) , V_920 ) ;
}
static void F_438 ( struct V_828 * V_829 , unsigned V_920 , V_175 V_195 )
{
F_104 ( F_354 ( V_829 ) , V_920 , V_195 ) ;
}
static void F_439 ( struct V_828 * V_829 , bool V_627 )
{
V_73 -> V_643 ( F_354 ( V_829 ) , V_627 ) ;
}
static void F_440 ( struct V_1 * V_2 , T_1 V_28 )
{
T_1 V_921 = V_73 -> V_623 ( V_2 ) ;
if ( V_921 & V_28 )
V_28 = 0 ;
if ( F_168 ( V_921 || V_28 ) ) {
V_73 -> V_642 ( V_2 , V_28 ) ;
if ( ! V_28 )
F_30 ( V_67 , V_2 ) ;
}
}
static bool F_441 ( struct V_1 * V_2 )
{
struct V_828 * V_829 = & V_2 -> V_5 . V_922 ;
if ( V_829 -> V_68 . V_41 == V_42 )
return F_38 ( V_2 , & V_829 -> V_68 ) ;
if ( V_829 -> V_68 . V_923 )
F_37 ( V_2 , V_829 -> V_68 . V_41 ,
V_829 -> V_68 . V_62 ) ;
else
F_32 ( V_2 , V_829 -> V_68 . V_41 ) ;
return false ;
}
static void F_442 ( struct V_1 * V_2 )
{
struct V_828 * V_829 = & V_2 -> V_5 . V_922 ;
int V_133 , V_134 ;
V_73 -> V_135 ( V_2 , & V_133 , & V_134 ) ;
V_829 -> V_924 = F_443 ( V_2 ) ;
V_829 -> V_925 = F_444 ( V_2 ) ;
V_829 -> V_330 = ( ! F_31 ( V_2 ) ) ? V_926 :
( V_829 -> V_924 & V_927 ) ? V_928 :
( V_134 && F_56 ( V_2 ) ) ? V_851 :
V_133 ? V_929 :
V_930 ;
F_184 ( V_931 != V_932 ) ;
F_184 ( V_644 != V_933 ) ;
F_184 ( V_635 != V_934 ) ;
V_829 -> V_935 = V_2 -> V_5 . V_634 ;
F_445 ( V_829 ) ;
V_2 -> V_5 . V_936 = false ;
}
int F_446 ( struct V_1 * V_2 , int V_595 , int V_937 )
{
struct V_828 * V_829 = & V_2 -> V_5 . V_922 ;
int V_108 ;
F_442 ( V_2 ) ;
V_829 -> V_938 = 2 ;
V_829 -> V_939 = 2 ;
V_829 -> V_940 = V_829 -> V_925 + V_937 ;
V_108 = F_447 ( V_829 , V_595 ) ;
if ( V_108 != V_824 )
return V_941 ;
V_829 -> V_925 = V_829 -> V_940 ;
F_448 ( V_2 , V_829 -> V_925 ) ;
F_449 ( V_2 , V_829 -> V_924 ) ;
if ( V_595 == V_51 )
V_2 -> V_5 . V_626 = 0 ;
else
V_2 -> V_5 . V_620 . V_69 = false ;
return V_942 ;
}
static int F_450 ( struct V_1 * V_2 )
{
int V_120 = V_942 ;
++ V_2 -> V_77 . V_943 ;
F_451 ( V_2 ) ;
if ( ! F_452 ( V_2 ) && V_73 -> V_88 ( V_2 ) == 0 ) {
V_2 -> V_840 -> V_856 = V_944 ;
V_2 -> V_840 -> V_945 . V_946 = V_947 ;
V_2 -> V_840 -> V_945 . V_948 = 0 ;
V_120 = V_941 ;
}
F_32 ( V_2 , V_91 ) ;
return V_120 ;
}
static bool F_453 ( struct V_1 * V_2 , T_16 V_79 ,
bool V_949 ,
int V_950 )
{
T_6 V_389 = V_79 ;
T_17 V_951 ;
if ( V_950 & V_952 )
return false ;
if ( ! V_2 -> V_5 . V_84 . V_953 ) {
V_389 = F_350 ( V_2 , V_79 , NULL ) ;
if ( V_389 == V_100 )
return true ;
}
V_951 = F_454 ( V_2 -> V_138 , F_48 ( V_389 ) ) ;
if ( F_455 ( V_951 ) )
return false ;
F_456 ( V_951 ) ;
if ( V_2 -> V_5 . V_84 . V_953 ) {
unsigned int V_954 ;
F_158 ( & V_2 -> V_138 -> V_955 ) ;
V_954 = V_2 -> V_138 -> V_5 . V_954 ;
F_159 ( & V_2 -> V_138 -> V_955 ) ;
if ( V_954 )
F_457 ( V_2 -> V_138 , F_48 ( V_389 ) ) ;
return true ;
}
F_457 ( V_2 -> V_138 , F_48 ( V_389 ) ) ;
return ! V_949 ;
}
static bool F_458 ( struct V_828 * V_829 ,
unsigned long V_79 , int V_950 )
{
struct V_1 * V_2 = F_354 ( V_829 ) ;
unsigned long V_956 , V_957 , V_389 = V_79 ;
V_956 = V_2 -> V_5 . V_956 ;
V_957 = V_2 -> V_5 . V_957 ;
V_2 -> V_5 . V_956 = V_2 -> V_5 . V_957 = 0 ;
if ( ! ( V_950 & V_958 ) )
return false ;
if ( F_459 ( V_829 ) )
return false ;
if ( V_829 -> V_925 == V_956 && V_957 == V_79 )
return false ;
V_2 -> V_5 . V_956 = V_829 -> V_925 ;
V_2 -> V_5 . V_957 = V_79 ;
if ( ! V_2 -> V_5 . V_84 . V_953 )
V_389 = F_350 ( V_2 , V_79 , NULL ) ;
F_457 ( V_2 -> V_138 , F_48 ( V_389 ) ) ;
return true ;
}
static void F_460 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_634 & V_644 ) ) {
F_461 ( V_2 -> V_297 , V_2 -> V_5 . V_425 , false ) ;
if ( F_168 ( V_2 -> V_5 . V_632 ) ) {
F_30 ( V_600 , V_2 ) ;
V_2 -> V_5 . V_632 = 0 ;
} else {
F_30 ( V_67 , V_2 ) ;
}
}
F_65 ( V_2 ) ;
}
static void F_462 ( struct V_1 * V_2 , unsigned V_935 )
{
unsigned V_119 = V_2 -> V_5 . V_634 ^ V_935 ;
V_2 -> V_5 . V_634 = V_935 ;
if ( V_119 & V_644 )
F_460 ( V_2 ) ;
}
static int F_463 ( unsigned long V_614 , T_1 type , T_1 V_187 ,
unsigned long * V_182 )
{
T_1 V_186 = 0 ;
int V_3 ;
T_1 V_959 , V_960 ;
V_959 = V_187 ;
V_960 = V_187 >> 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ , V_959 >>= 2 , V_960 >>= 4 )
if ( ( V_959 & 3 ) && ( V_960 & 15 ) == type && V_182 [ V_3 ] == V_614 )
V_186 |= ( 1 << V_3 ) ;
return V_186 ;
}
static void F_464 ( struct V_1 * V_2 , unsigned long V_961 , int * V_120 )
{
struct V_962 * V_962 = V_2 -> V_840 ;
if ( F_168 ( V_961 & V_963 ) ) {
if ( V_2 -> V_178 & V_964 ) {
V_962 -> V_965 . V_5 . V_186 = V_966 | V_193 |
V_194 ;
V_962 -> V_965 . V_5 . V_967 = V_2 -> V_5 . V_968 ;
V_962 -> V_965 . V_5 . V_68 = V_53 ;
V_962 -> V_856 = V_969 ;
* V_120 = V_970 ;
} else {
V_2 -> V_5 . V_922 . V_924 &= ~ V_963 ;
V_2 -> V_5 . V_186 &= ~ 15 ;
V_2 -> V_5 . V_186 |= V_966 | V_194 ;
F_32 ( V_2 , V_53 ) ;
}
}
}
static bool F_465 ( struct V_1 * V_2 , int * V_120 )
{
if ( F_168 ( V_2 -> V_178 & V_179 ) &&
( V_2 -> V_5 . V_188 & V_191 ) ) {
struct V_962 * V_962 = V_2 -> V_840 ;
unsigned long V_925 = F_466 ( V_2 ) ;
T_1 V_186 = F_463 ( V_925 , 0 ,
V_2 -> V_5 . V_188 ,
V_2 -> V_5 . V_181 ) ;
if ( V_186 != 0 ) {
V_962 -> V_965 . V_5 . V_186 = V_186 | V_193 | V_194 ;
V_962 -> V_965 . V_5 . V_967 = V_925 ;
V_962 -> V_965 . V_5 . V_68 = V_53 ;
V_962 -> V_856 = V_969 ;
* V_120 = V_970 ;
return true ;
}
}
if ( F_168 ( V_2 -> V_5 . V_187 & V_191 ) &&
! ( F_443 ( V_2 ) & V_971 ) ) {
unsigned long V_925 = F_466 ( V_2 ) ;
T_1 V_186 = F_463 ( V_925 , 0 ,
V_2 -> V_5 . V_187 ,
V_2 -> V_5 . V_182 ) ;
if ( V_186 != 0 ) {
V_2 -> V_5 . V_186 &= ~ 15 ;
V_2 -> V_5 . V_186 |= V_186 | V_194 ;
F_32 ( V_2 , V_53 ) ;
* V_120 = V_942 ;
return true ;
}
}
return false ;
}
int F_467 ( struct V_1 * V_2 ,
unsigned long V_79 ,
int V_950 ,
void * V_972 ,
int V_973 )
{
int V_120 ;
struct V_828 * V_829 = & V_2 -> V_5 . V_922 ;
bool V_489 = true ;
bool V_974 = V_2 -> V_5 . V_949 ;
V_2 -> V_5 . V_949 = false ;
F_468 ( V_2 ) ;
if ( ! ( V_950 & V_975 ) ) {
F_442 ( V_2 ) ;
if ( F_465 ( V_2 , & V_120 ) )
return V_120 ;
V_829 -> V_976 = 0 ;
V_829 -> V_977 = false ;
V_829 -> V_68 . V_41 = - 1 ;
V_829 -> V_978 = false ;
V_829 -> V_979 = V_950 & V_980 ;
V_120 = F_469 ( V_829 , V_972 , V_973 ) ;
F_470 ( V_2 ) ;
++ V_2 -> V_77 . V_981 ;
if ( V_120 != V_982 ) {
if ( V_950 & V_980 )
return V_941 ;
if ( F_453 ( V_2 , V_79 , V_974 ,
V_950 ) )
return V_942 ;
if ( V_950 & V_983 )
return V_941 ;
return F_450 ( V_2 ) ;
}
}
if ( V_950 & V_983 ) {
F_448 ( V_2 , V_829 -> V_940 ) ;
if ( V_829 -> V_924 & V_971 )
F_449 ( V_2 , V_829 -> V_924 & ~ V_971 ) ;
return V_942 ;
}
if ( F_458 ( V_829 , V_79 , V_950 ) )
return V_942 ;
if ( V_2 -> V_5 . V_936 ) {
V_2 -> V_5 . V_936 = false ;
F_471 ( V_829 ) ;
}
V_984:
V_120 = F_472 ( V_829 ) ;
if ( V_120 == V_985 )
return V_942 ;
if ( V_120 == V_986 ) {
if ( F_453 ( V_2 , V_79 , V_974 ,
V_950 ) )
return V_942 ;
return F_450 ( V_2 ) ;
}
if ( V_829 -> V_977 ) {
V_120 = V_942 ;
if ( F_441 ( V_2 ) )
return V_120 ;
} else if ( V_2 -> V_5 . V_871 . V_745 ) {
if ( ! V_2 -> V_5 . V_871 . V_872 ) {
V_2 -> V_5 . V_871 . V_745 = 0 ;
} else {
V_489 = false ;
V_2 -> V_5 . V_987 = V_988 ;
}
V_120 = V_970 ;
} else if ( V_2 -> V_852 ) {
if ( ! V_2 -> V_855 )
V_489 = false ;
V_120 = V_970 ;
V_2 -> V_5 . V_987 = V_989 ;
} else if ( V_120 == V_990 )
goto V_984;
else
V_120 = V_942 ;
if ( V_489 ) {
unsigned long V_961 = V_73 -> V_991 ( V_2 ) ;
F_440 ( V_2 , V_829 -> V_976 ) ;
V_2 -> V_5 . V_992 = false ;
if ( V_2 -> V_5 . V_634 != V_829 -> V_935 )
F_462 ( V_2 , V_829 -> V_935 ) ;
F_448 ( V_2 , V_829 -> V_925 ) ;
if ( V_120 == V_942 )
F_464 ( V_2 , V_961 , & V_120 ) ;
if ( ! V_829 -> V_977 ||
F_27 ( V_829 -> V_68 . V_41 ) == V_56 )
F_473 ( V_2 , V_829 -> V_924 ) ;
if ( F_168 ( ( V_829 -> V_924 & ~ V_961 ) & V_993 ) )
F_30 ( V_67 , V_2 ) ;
} else
V_2 -> V_5 . V_992 = true ;
return V_120 ;
}
int F_474 ( struct V_1 * V_2 , int V_491 , unsigned short V_874 )
{
unsigned long V_195 = F_102 ( V_2 , V_202 ) ;
int V_108 = F_392 ( & V_2 -> V_5 . V_922 ,
V_491 , V_874 , & V_195 , 1 ) ;
V_2 -> V_5 . V_871 . V_745 = 0 ;
return V_108 ;
}
static void F_475 ( void * V_914 )
{
F_476 ( V_346 , 0 ) ;
}
static void F_477 ( void * V_38 )
{
struct V_994 * V_995 = V_38 ;
unsigned long V_264 = 0 ;
if ( V_38 )
V_264 = V_995 -> V_863 ;
else if ( ! F_478 ( V_996 ) )
V_264 = F_479 ( F_480 () ) ;
if ( ! V_264 )
V_264 = V_273 ;
F_476 ( V_346 , V_264 ) ;
}
static int F_481 ( struct V_997 * V_998 , unsigned long V_195 ,
void * V_38 )
{
struct V_994 * V_995 = V_38 ;
struct V_138 * V_138 ;
struct V_1 * V_2 ;
int V_3 , V_999 = 0 ;
if ( V_195 == V_1000 && V_995 -> V_862 > V_995 -> V_863 )
return 0 ;
if ( V_195 == V_1001 && V_995 -> V_862 < V_995 -> V_863 )
return 0 ;
F_246 ( V_995 -> V_23 , F_477 , V_995 , 1 ) ;
F_158 ( & V_1002 ) ;
F_482 (kvm, &vm_list, vm_list) {
F_177 (i, vcpu, kvm) {
if ( V_2 -> V_23 != V_995 -> V_23 )
continue;
F_30 ( V_338 , V_2 ) ;
if ( V_2 -> V_23 != F_8 () )
V_999 = 1 ;
}
}
F_159 ( & V_1002 ) ;
if ( V_995 -> V_862 < V_995 -> V_863 && V_999 ) {
F_246 ( V_995 -> V_23 , F_477 , V_995 , 1 ) ;
}
return 0 ;
}
static int F_483 ( struct V_997 * V_1003 ,
unsigned long V_1004 , void * V_1005 )
{
unsigned int V_23 = ( unsigned long ) V_1005 ;
switch ( V_1004 ) {
case V_1006 :
case V_1007 :
F_246 ( V_23 , F_477 , NULL , 1 ) ;
break;
case V_1008 :
F_246 ( V_23 , F_475 , NULL , 1 ) ;
break;
}
return V_1009 ;
}
static void F_484 ( void )
{
int V_23 ;
V_1010 = V_273 ;
F_485 () ;
if ( ! F_478 ( V_996 ) ) {
#ifdef F_486
struct V_1011 V_1012 ;
memset ( & V_1012 , 0 , sizeof( V_1012 ) ) ;
V_23 = F_397 () ;
F_487 ( & V_1012 , V_23 ) ;
if ( V_1012 . V_1013 . V_1014 )
V_1010 = V_1012 . V_1013 . V_1014 ;
F_399 () ;
#endif
F_488 ( & V_1015 ,
V_1016 ) ;
}
F_131 ( L_22 , V_1010 ) ;
F_489 (cpu)
F_246 ( V_23 , F_477 , NULL , 1 ) ;
F_490 ( & V_1017 ) ;
F_491 () ;
}
int F_492 ( void )
{
return F_181 ( V_1018 ) != NULL ;
}
static int F_493 ( void )
{
int V_1019 = 3 ;
if ( F_181 ( V_1018 ) )
V_1019 = V_73 -> V_88 ( F_181 ( V_1018 ) ) ;
return V_1019 != 0 ;
}
static unsigned long F_494 ( void )
{
unsigned long V_1020 = 0 ;
if ( F_181 ( V_1018 ) )
V_1020 = F_444 ( F_181 ( V_1018 ) ) ;
return V_1020 ;
}
void F_495 ( struct V_1 * V_2 )
{
F_476 ( V_1018 , V_2 ) ;
}
void F_496 ( struct V_1 * V_2 )
{
F_476 ( V_1018 , NULL ) ;
}
static void F_497 ( void )
{
T_2 V_28 ;
int V_1021 = V_1022 . V_1023 ;
V_28 = F_498 ( V_1021 , 51 ) ;
V_28 |= 0x3ull << 62 ;
V_28 |= 1ull ;
#ifdef F_62
if ( V_1021 == 52 )
V_28 &= ~ 1ull ;
#endif
F_499 ( V_28 ) ;
}
static void F_500 ( struct V_357 * V_358 )
{
struct V_138 * V_138 ;
struct V_1 * V_2 ;
int V_3 ;
F_158 ( & V_1002 ) ;
F_482 (kvm, &vm_list, vm_list)
F_177 (i, vcpu, kvm)
F_30 ( V_296 , V_2 ) ;
F_172 ( & V_336 , 0 ) ;
F_159 ( & V_1002 ) ;
}
static int F_501 ( struct V_997 * V_998 , unsigned long V_1024 ,
void * V_1025 )
{
struct V_225 * V_291 = & V_225 ;
struct V_223 * V_224 = V_1025 ;
F_116 ( V_224 ) ;
if ( V_291 -> clock . V_232 != V_295 &&
F_143 ( & V_336 ) != 0 )
F_502 ( V_1026 , & V_1027 ) ;
return 0 ;
}
int F_503 ( void * V_1028 )
{
int V_120 ;
struct V_73 * V_843 = V_1028 ;
if ( V_73 ) {
F_10 ( V_26 L_23 ) ;
V_120 = - V_599 ;
goto V_113;
}
if ( ! V_843 -> V_1029 () ) {
F_10 ( V_26 L_24 ) ;
V_120 = - V_1030 ;
goto V_113;
}
if ( V_843 -> V_1031 () ) {
F_10 ( V_26 L_25 ) ;
V_120 = - V_1030 ;
goto V_113;
}
V_120 = - V_387 ;
V_25 = F_504 ( struct V_11 ) ;
if ( ! V_25 ) {
F_10 ( V_26 L_26 ) ;
goto V_113;
}
V_120 = F_505 () ;
if ( V_120 )
goto V_1032;
F_497 () ;
V_73 = V_843 ;
F_506 ( V_1033 , V_1034 ,
V_1035 , V_1036 , 0 ) ;
F_484 () ;
F_507 ( & V_1037 ) ;
if ( V_554 )
V_145 = F_508 ( V_143 ) ;
F_509 () ;
#ifdef F_62
F_510 ( & V_1038 ) ;
#endif
return 0 ;
V_1032:
F_511 ( V_25 ) ;
V_113:
return V_120 ;
}
void F_512 ( void )
{
F_513 ( & V_1037 ) ;
if ( ! F_478 ( V_996 ) )
F_514 ( & V_1015 ,
V_1016 ) ;
F_515 ( & V_1017 ) ;
#ifdef F_62
F_516 ( & V_1038 ) ;
#endif
V_73 = NULL ;
F_517 () ;
F_511 ( V_25 ) ;
}
int F_518 ( struct V_1 * V_2 )
{
++ V_2 -> V_77 . V_1039 ;
if ( F_89 ( V_2 ) ) {
V_2 -> V_5 . V_1040 = V_1041 ;
return 1 ;
} else {
V_2 -> V_840 -> V_856 = V_1042 ;
return 0 ;
}
}
int F_519 ( struct V_1 * V_2 )
{
V_73 -> V_74 ( V_2 ) ;
return F_518 ( V_2 ) ;
}
static void F_520 ( struct V_138 * V_138 , unsigned long V_307 , int V_1043 )
{
struct V_1044 V_1045 ;
V_1045 . V_1046 = 0 ;
V_1045 . V_1047 = 0 ;
V_1045 . V_1048 = V_1043 ;
V_1045 . V_1049 = false ;
V_1045 . V_1050 = V_1051 ;
F_521 ( V_138 , NULL , & V_1045 , NULL ) ;
}
void F_522 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_590 = false ;
V_73 -> V_1052 ( V_2 ) ;
}
int F_523 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_1053 , V_1054 , V_1055 , V_1056 , V_108 ;
int V_1057 , V_120 = 1 ;
V_73 -> V_74 ( V_2 ) ;
if ( F_524 ( V_2 -> V_138 ) )
return F_525 ( V_2 ) ;
V_16 = F_102 ( V_2 , V_202 ) ;
V_1053 = F_102 ( V_2 , V_1058 ) ;
V_1054 = F_102 ( V_2 , V_201 ) ;
V_1055 = F_102 ( V_2 , V_203 ) ;
V_1056 = F_102 ( V_2 , V_1059 ) ;
F_526 ( V_16 , V_1053 , V_1054 , V_1055 , V_1056 ) ;
V_1057 = F_527 ( V_2 ) ;
if ( ! V_1057 ) {
V_16 &= 0xFFFFFFFF ;
V_1053 &= 0xFFFFFFFF ;
V_1054 &= 0xFFFFFFFF ;
V_1055 &= 0xFFFFFFFF ;
V_1056 &= 0xFFFFFFFF ;
}
if ( V_73 -> V_88 ( V_2 ) != 0 ) {
V_108 = - V_1060 ;
goto V_113;
}
switch ( V_16 ) {
case V_1061 :
V_108 = 0 ;
break;
case V_1062 :
F_520 ( V_2 -> V_138 , V_1053 , V_1054 ) ;
V_108 = 0 ;
break;
default:
V_108 = - V_1063 ;
break;
}
V_113:
if ( ! V_1057 )
V_108 = ( T_1 ) V_108 ;
F_104 ( V_2 , V_202 , V_108 ) ;
++ V_2 -> V_77 . V_1064 ;
return V_120 ;
}
static int F_528 ( struct V_828 * V_829 )
{
struct V_1 * V_2 = F_354 ( V_829 ) ;
char V_1065 [ 3 ] ;
unsigned long V_1066 = F_444 ( V_2 ) ;
V_73 -> V_1067 ( V_2 , V_1065 ) ;
return F_376 ( V_829 , V_1066 , V_1065 , 3 , NULL ) ;
}
static int F_529 ( struct V_1 * V_2 )
{
return V_2 -> V_840 -> V_1068 &&
F_164 ( ! F_263 ( V_2 -> V_138 ) ) ;
}
static void F_530 ( struct V_1 * V_2 )
{
struct V_962 * V_962 = V_2 -> V_840 ;
V_962 -> V_1069 = ( F_443 ( V_2 ) & V_993 ) != 0 ;
V_962 -> V_307 = F_272 ( V_2 ) ? V_1070 : 0 ;
V_962 -> V_176 = F_91 ( V_2 ) ;
V_962 -> V_31 = F_19 ( V_2 ) ;
V_962 -> V_1071 =
F_263 ( V_2 -> V_138 ) ||
F_256 ( V_2 ) ;
}
static void F_253 ( struct V_1 * V_2 )
{
int V_1072 , V_1073 ;
if ( ! V_73 -> F_253 )
return;
if ( ! F_89 ( V_2 ) )
return;
if ( V_2 -> V_5 . V_590 )
return;
if ( ! V_2 -> V_5 . V_593 -> V_698 )
V_1072 = F_531 ( V_2 ) ;
else
V_1072 = - 1 ;
if ( V_1072 != - 1 )
V_1072 >>= 4 ;
V_1073 = F_92 ( V_2 ) ;
V_73 -> F_253 ( V_2 , V_1073 , V_1072 ) ;
}
static int F_532 ( struct V_1 * V_2 , bool V_1074 )
{
int V_120 ;
if ( V_2 -> V_5 . V_68 . V_69 ) {
F_533 ( V_2 -> V_5 . V_68 . V_16 ,
V_2 -> V_5 . V_68 . V_71 ,
V_2 -> V_5 . V_68 . V_62 ) ;
if ( F_27 ( V_2 -> V_5 . V_68 . V_16 ) == V_60 )
F_473 ( V_2 , F_443 ( V_2 ) |
V_971 ) ;
if ( V_2 -> V_5 . V_68 . V_16 == V_53 &&
( V_2 -> V_5 . V_187 & V_1075 ) ) {
V_2 -> V_5 . V_187 &= ~ V_1075 ;
F_95 ( V_2 ) ;
}
V_73 -> V_1076 ( V_2 , V_2 -> V_5 . V_68 . V_16 ,
V_2 -> V_5 . V_68 . V_71 ,
V_2 -> V_5 . V_68 . V_62 ,
V_2 -> V_5 . V_68 . V_63 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_625 ) {
V_73 -> V_1077 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_620 . V_69 ) {
V_73 -> V_1078 ( V_2 ) ;
return 0 ;
}
if ( F_452 ( V_2 ) && V_73 -> V_1079 ) {
V_120 = V_73 -> V_1079 ( V_2 , V_1074 ) ;
if ( V_120 != 0 )
return V_120 ;
}
if ( V_2 -> V_5 . V_626 && V_73 -> V_1080 ( V_2 ) ) {
-- V_2 -> V_5 . V_626 ;
V_2 -> V_5 . V_625 = true ;
V_73 -> V_1077 ( V_2 ) ;
} else if ( F_534 ( V_2 ) ) {
if ( F_452 ( V_2 ) && V_73 -> V_1079 ) {
V_120 = V_73 -> V_1079 ( V_2 , V_1074 ) ;
if ( V_120 != 0 )
return V_120 ;
}
if ( V_73 -> V_1081 ( V_2 ) ) {
F_262 ( V_2 , F_535 ( V_2 ) ,
false ) ;
V_73 -> V_1078 ( V_2 ) ;
}
}
return 0 ;
}
static void F_270 ( struct V_1 * V_2 )
{
unsigned V_902 = 2 ;
if ( V_73 -> V_628 ( V_2 ) || V_2 -> V_5 . V_625 )
V_902 = 1 ;
V_2 -> V_5 . V_626 += F_536 ( & V_2 -> V_5 . V_85 , 0 ) ;
V_2 -> V_5 . V_626 = F_338 ( V_2 -> V_5 . V_626 , V_902 ) ;
F_30 ( V_67 , V_2 ) ;
}
static T_1 F_537 ( struct V_814 * V_816 )
{
T_1 V_307 = 0 ;
V_307 |= V_816 -> V_901 << 23 ;
V_307 |= V_816 -> V_182 << 22 ;
V_307 |= V_816 -> V_907 << 21 ;
V_307 |= V_816 -> V_906 << 20 ;
V_307 |= V_816 -> V_905 << 15 ;
V_307 |= V_816 -> V_903 << 13 ;
V_307 |= V_816 -> V_589 << 12 ;
V_307 |= V_816 -> type << 8 ;
return V_307 ;
}
static void F_538 ( struct V_1 * V_2 , char * V_1082 , int V_490 )
{
struct V_814 V_816 ;
int V_94 ;
F_346 ( V_2 , & V_816 , V_490 ) ;
F_539 ( T_1 , V_1082 , 0x7fa8 + V_490 * 4 , V_816 . V_896 ) ;
if ( V_490 < 3 )
V_94 = 0x7f84 + V_490 * 12 ;
else
V_94 = 0x7f2c + ( V_490 - 3 ) * 12 ;
F_539 ( T_1 , V_1082 , V_94 + 8 , V_816 . V_229 ) ;
F_539 ( T_1 , V_1082 , V_94 + 4 , V_816 . V_902 ) ;
F_539 ( T_1 , V_1082 , V_94 , F_537 ( & V_816 ) ) ;
}
static void F_540 ( struct V_1 * V_2 , char * V_1082 , int V_490 )
{
struct V_814 V_816 ;
int V_94 ;
V_867 V_307 ;
F_346 ( V_2 , & V_816 , V_490 ) ;
V_94 = 0x7e00 + V_490 * 16 ;
V_307 = F_537 ( & V_816 ) >> 8 ;
F_539 ( V_867 , V_1082 , V_94 , V_816 . V_896 ) ;
F_539 ( V_867 , V_1082 , V_94 + 2 , V_307 ) ;
F_539 ( T_1 , V_1082 , V_94 + 4 , V_816 . V_902 ) ;
F_539 ( T_2 , V_1082 , V_94 + 8 , V_816 . V_229 ) ;
}
static void F_541 ( struct V_1 * V_2 , char * V_1082 )
{
struct V_890 V_891 ;
struct V_814 V_816 ;
unsigned long V_195 ;
int V_3 ;
F_539 ( T_1 , V_1082 , 0x7ffc , F_61 ( V_2 ) ) ;
F_539 ( T_1 , V_1082 , 0x7ff8 , F_59 ( V_2 ) ) ;
F_539 ( T_1 , V_1082 , 0x7ff4 , F_443 ( V_2 ) ) ;
F_539 ( T_1 , V_1082 , 0x7ff0 , F_444 ( V_2 ) ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
F_539 ( T_1 , V_1082 , 0x7fd0 + V_3 * 4 , F_102 ( V_2 , V_3 ) ) ;
F_100 ( V_2 , 6 , & V_195 ) ;
F_539 ( T_1 , V_1082 , 0x7fcc , ( T_1 ) V_195 ) ;
F_100 ( V_2 , 7 , & V_195 ) ;
F_539 ( T_1 , V_1082 , 0x7fc8 , ( T_1 ) V_195 ) ;
F_346 ( V_2 , & V_816 , V_1083 ) ;
F_539 ( T_1 , V_1082 , 0x7fc4 , V_816 . V_896 ) ;
F_539 ( T_1 , V_1082 , 0x7f64 , V_816 . V_229 ) ;
F_539 ( T_1 , V_1082 , 0x7f60 , V_816 . V_902 ) ;
F_539 ( T_1 , V_1082 , 0x7f5c , F_537 ( & V_816 ) ) ;
F_346 ( V_2 , & V_816 , V_1084 ) ;
F_539 ( T_1 , V_1082 , 0x7fc0 , V_816 . V_896 ) ;
F_539 ( T_1 , V_1082 , 0x7f80 , V_816 . V_229 ) ;
F_539 ( T_1 , V_1082 , 0x7f7c , V_816 . V_902 ) ;
F_539 ( T_1 , V_1082 , 0x7f78 , F_537 ( & V_816 ) ) ;
V_73 -> V_892 ( V_2 , & V_891 ) ;
F_539 ( T_1 , V_1082 , 0x7f74 , V_891 . V_80 ) ;
F_539 ( T_1 , V_1082 , 0x7f70 , V_891 . V_491 ) ;
V_73 -> V_893 ( V_2 , & V_891 ) ;
F_539 ( T_1 , V_1082 , 0x7f58 , V_891 . V_80 ) ;
F_539 ( T_1 , V_1082 , 0x7f54 , V_891 . V_491 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_538 ( V_2 , V_1082 , V_3 ) ;
F_539 ( T_1 , V_1082 , 0x7f14 , F_78 ( V_2 ) ) ;
F_539 ( T_1 , V_1082 , 0x7efc , 0x00020000 ) ;
F_539 ( T_1 , V_1082 , 0x7ef8 , V_2 -> V_5 . V_425 ) ;
}
static void F_542 ( struct V_1 * V_2 , char * V_1082 )
{
#ifdef F_62
struct V_890 V_891 ;
struct V_814 V_816 ;
unsigned long V_195 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ )
F_539 ( T_2 , V_1082 , 0x7ff8 - V_3 * 8 , F_102 ( V_2 , V_3 ) ) ;
F_539 ( T_2 , V_1082 , 0x7f78 , F_444 ( V_2 ) ) ;
F_539 ( T_1 , V_1082 , 0x7f70 , F_443 ( V_2 ) ) ;
F_100 ( V_2 , 6 , & V_195 ) ;
F_539 ( T_2 , V_1082 , 0x7f68 , V_195 ) ;
F_100 ( V_2 , 7 , & V_195 ) ;
F_539 ( T_2 , V_1082 , 0x7f60 , V_195 ) ;
F_539 ( T_2 , V_1082 , 0x7f58 , F_61 ( V_2 ) ) ;
F_539 ( T_2 , V_1082 , 0x7f50 , F_59 ( V_2 ) ) ;
F_539 ( T_2 , V_1082 , 0x7f48 , F_78 ( V_2 ) ) ;
F_539 ( T_1 , V_1082 , 0x7f00 , V_2 -> V_5 . V_425 ) ;
F_539 ( T_1 , V_1082 , 0x7efc , 0x00020064 ) ;
F_539 ( T_2 , V_1082 , 0x7ed0 , V_2 -> V_5 . V_131 ) ;
F_346 ( V_2 , & V_816 , V_1083 ) ;
F_539 ( V_867 , V_1082 , 0x7e90 , V_816 . V_896 ) ;
F_539 ( V_867 , V_1082 , 0x7e92 , F_537 ( & V_816 ) >> 8 ) ;
F_539 ( T_1 , V_1082 , 0x7e94 , V_816 . V_902 ) ;
F_539 ( T_2 , V_1082 , 0x7e98 , V_816 . V_229 ) ;
V_73 -> V_893 ( V_2 , & V_891 ) ;
F_539 ( T_1 , V_1082 , 0x7e84 , V_891 . V_491 ) ;
F_539 ( T_2 , V_1082 , 0x7e88 , V_891 . V_80 ) ;
F_346 ( V_2 , & V_816 , V_1084 ) ;
F_539 ( V_867 , V_1082 , 0x7e70 , V_816 . V_896 ) ;
F_539 ( V_867 , V_1082 , 0x7e72 , F_537 ( & V_816 ) >> 8 ) ;
F_539 ( T_1 , V_1082 , 0x7e74 , V_816 . V_902 ) ;
F_539 ( T_2 , V_1082 , 0x7e78 , V_816 . V_229 ) ;
V_73 -> V_892 ( V_2 , & V_891 ) ;
F_539 ( T_1 , V_1082 , 0x7e64 , V_891 . V_491 ) ;
F_539 ( T_2 , V_1082 , 0x7e68 , V_891 . V_80 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_540 ( V_2 , V_1082 , V_3 ) ;
#else
F_543 ( 1 ) ;
#endif
}
static void F_544 ( struct V_1 * V_2 )
{
struct V_814 V_1085 , V_1086 ;
struct V_890 V_891 ;
char V_1082 [ 512 ] ;
T_1 V_121 ;
if ( F_272 ( V_2 ) ) {
V_2 -> V_5 . V_632 = true ;
return;
}
F_461 ( V_2 -> V_297 , V_2 -> V_5 . V_425 , true ) ;
V_2 -> V_5 . V_634 |= V_644 ;
memset ( V_1082 , 0 , 512 ) ;
if ( F_545 ( V_2 ) )
F_542 ( V_2 , V_1082 ) ;
else
F_541 ( V_2 , V_1082 ) ;
F_201 ( V_2 , V_2 -> V_5 . V_425 + 0xfe00 , V_1082 , sizeof( V_1082 ) ) ;
if ( V_73 -> V_628 ( V_2 ) )
V_2 -> V_5 . V_634 |= V_635 ;
else
V_73 -> V_643 ( V_2 , true ) ;
F_449 ( V_2 , V_1087 ) ;
F_448 ( V_2 , 0x8000 ) ;
V_121 = V_2 -> V_5 . V_121 & ~ ( V_130 | V_1088 | V_1089 | V_124 ) ;
V_73 -> V_137 ( V_2 , V_121 ) ;
V_2 -> V_5 . V_121 = V_121 ;
V_73 -> V_170 ( V_2 , 0 ) ;
V_891 . V_80 = V_891 . V_491 = 0 ;
V_73 -> V_895 ( V_2 , & V_891 ) ;
F_98 ( V_2 , 7 , V_198 ) ;
V_1085 . V_896 = ( V_2 -> V_5 . V_425 >> 4 ) & 0xffff ;
V_1085 . V_229 = V_2 -> V_5 . V_425 ;
V_1086 . V_896 = 0 ;
V_1086 . V_229 = 0 ;
V_1085 . V_902 = V_1086 . V_902 = 0xffffffff ;
V_1085 . type = V_1086 . type = 0x3 ;
V_1085 . V_903 = V_1086 . V_903 = 0 ;
V_1085 . V_182 = V_1086 . V_182 = 0 ;
V_1085 . V_589 = V_1086 . V_589 = 1 ;
V_1085 . V_907 = V_1086 . V_907 = 0 ;
V_1085 . V_901 = V_1086 . V_901 = 1 ;
V_1085 . V_906 = V_1086 . V_906 = 0 ;
V_1085 . V_905 = V_1086 . V_905 = 1 ;
V_1085 . V_900 = V_1086 . V_900 = 0 ;
V_1085 . V_909 = V_1086 . V_909 = 0 ;
F_345 ( V_2 , & V_1085 , V_1090 ) ;
F_345 ( V_2 , & V_1086 , V_1091 ) ;
F_345 ( V_2 , & V_1086 , V_1092 ) ;
F_345 ( V_2 , & V_1086 , V_1093 ) ;
F_345 ( V_2 , & V_1086 , V_1094 ) ;
F_345 ( V_2 , & V_1086 , V_1095 ) ;
if ( F_545 ( V_2 ) )
V_73 -> F_108 ( V_2 , 0 ) ;
F_75 ( V_2 ) ;
F_65 ( V_2 ) ;
}
void F_546 ( struct V_138 * V_138 )
{
F_175 ( V_138 , V_1096 ) ;
}
static void F_547 ( struct V_1 * V_2 )
{
T_2 V_1097 [ 4 ] ;
if ( ! F_548 ( V_2 -> V_5 . V_593 ) )
return;
F_549 ( V_2 -> V_5 . V_1098 , 256 ) ;
if ( V_765 ( V_2 -> V_138 ) )
F_550 ( V_2 , V_2 -> V_5 . V_1098 ) ;
else {
if ( V_2 -> V_5 . V_590 )
V_73 -> V_591 ( V_2 ) ;
F_551 ( V_2 , V_2 -> V_5 . V_1098 ) ;
}
F_552 ( ( V_175 * ) V_1097 , V_2 -> V_5 . V_1098 ,
F_553 ( V_2 ) -> V_1099 , 256 ) ;
V_73 -> V_1100 ( V_2 , V_1097 ) ;
}
static void F_554 ( struct V_1 * V_2 )
{
++ V_2 -> V_77 . V_1101 ;
V_73 -> V_1101 ( V_2 ) ;
}
void F_555 ( struct V_1 * V_2 )
{
struct V_385 * V_385 = NULL ;
if ( ! F_89 ( V_2 ) )
return;
if ( ! V_73 -> V_1102 )
return;
V_385 = F_556 ( V_2 -> V_138 , V_833 >> V_106 ) ;
if ( F_379 ( V_385 ) )
return;
V_73 -> V_1102 ( V_2 , F_557 ( V_385 ) ) ;
F_558 ( V_385 ) ;
}
void F_559 ( struct V_138 * V_138 ,
unsigned long V_80 )
{
if ( V_80 == F_560 ( V_138 , V_833 >> V_106 ) )
F_175 ( V_138 , V_1103 ) ;
}
static int F_561 ( struct V_1 * V_2 )
{
int V_120 ;
bool V_1074 =
F_529 ( V_2 ) &&
F_254 ( V_2 ) ;
bool V_1104 = false ;
if ( V_2 -> V_339 ) {
if ( F_562 ( V_1105 , V_2 ) )
F_563 ( V_2 ) ;
if ( F_562 ( V_580 , V_2 ) )
F_564 ( V_2 ) ;
if ( F_562 ( V_296 , V_2 ) )
F_176 ( V_2 -> V_138 ) ;
if ( F_562 ( V_432 , V_2 ) )
F_192 ( V_2 ) ;
if ( F_562 ( V_338 , V_2 ) ) {
V_120 = F_179 ( V_2 ) ;
if ( F_168 ( V_120 ) )
goto V_113;
}
if ( F_562 ( V_1106 , V_2 ) )
F_86 ( V_2 ) ;
if ( F_562 ( V_172 , V_2 ) )
F_554 ( V_2 ) ;
if ( F_562 ( V_1107 , V_2 ) ) {
V_2 -> V_840 -> V_856 = V_1108 ;
V_120 = 0 ;
goto V_113;
}
if ( F_562 ( V_72 , V_2 ) ) {
V_2 -> V_840 -> V_856 = V_1109 ;
V_120 = 0 ;
goto V_113;
}
if ( F_562 ( V_1110 , V_2 ) ) {
V_2 -> V_1111 = 0 ;
V_73 -> V_1112 ( V_2 ) ;
}
if ( F_562 ( V_1113 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1114 = true ;
V_120 = 1 ;
goto V_113;
}
if ( F_562 ( V_437 , V_2 ) )
F_208 ( V_2 ) ;
if ( F_562 ( V_600 , V_2 ) )
F_544 ( V_2 ) ;
if ( F_562 ( V_86 , V_2 ) )
F_270 ( V_2 ) ;
if ( F_562 ( V_1115 , V_2 ) )
F_565 ( V_2 ) ;
if ( F_562 ( V_1116 , V_2 ) )
F_566 ( V_2 ) ;
if ( F_562 ( V_1117 , V_2 ) ) {
F_13 ( V_2 -> V_5 . V_1118 > 255 ) ;
if ( F_58 ( V_2 -> V_5 . V_1118 ,
V_2 -> V_5 . V_1098 ) ) {
V_2 -> V_840 -> V_856 = V_1119 ;
V_2 -> V_840 -> V_1120 . V_41 =
V_2 -> V_5 . V_1118 ;
V_120 = 0 ;
goto V_113;
}
}
if ( F_562 ( V_1096 , V_2 ) )
F_547 ( V_2 ) ;
if ( F_562 ( V_1103 , V_2 ) )
F_555 ( V_2 ) ;
if ( F_562 ( V_1121 , V_2 ) ) {
V_2 -> V_840 -> V_856 = V_1122 ;
V_2 -> V_840 -> V_1123 . type = V_1124 ;
V_120 = 0 ;
goto V_113;
}
if ( F_562 ( V_1125 , V_2 ) ) {
V_2 -> V_840 -> V_856 = V_1122 ;
V_2 -> V_840 -> V_1123 . type = V_1126 ;
V_120 = 0 ;
goto V_113;
}
if ( F_562 ( V_1127 , V_2 ) ) {
V_2 -> V_840 -> V_856 = V_1128 ;
V_2 -> V_840 -> V_1129 = V_2 -> V_5 . V_1129 . exit ;
V_120 = 0 ;
goto V_113;
}
if ( F_562 ( V_1130 , V_2 ) )
F_567 ( V_2 ) ;
}
if ( F_568 ( V_2 ) ) {
if ( V_2 -> V_5 . V_590 )
V_73 -> V_1131 ( V_2 ,
F_531 ( V_2 ) ) ;
}
if ( F_562 ( V_67 , V_2 ) || V_1074 ) {
F_569 ( V_2 ) ;
if ( V_2 -> V_5 . V_1040 == V_1132 ) {
V_120 = 1 ;
goto V_113;
}
if ( F_532 ( V_2 , V_1074 ) != 0 )
V_1104 = true ;
else {
if ( V_2 -> V_5 . V_626 )
V_73 -> V_1133 ( V_2 ) ;
if ( F_534 ( V_2 ) || V_1074 )
V_73 -> V_1134 ( V_2 ) ;
}
if ( F_568 ( V_2 ) ) {
F_253 ( V_2 ) ;
F_570 ( V_2 ) ;
}
}
V_120 = F_571 ( V_2 ) ;
if ( F_168 ( V_120 ) ) {
goto V_1135;
}
F_430 () ;
V_73 -> V_1136 ( V_2 ) ;
if ( V_2 -> V_1111 )
F_431 ( V_2 ) ;
V_2 -> V_330 = V_1137 ;
F_231 ( & V_2 -> V_138 -> V_486 , V_2 -> V_1138 ) ;
F_572 () ;
F_332 () ;
if ( V_2 -> V_330 == V_1139 || V_2 -> V_339
|| F_573 () || F_574 ( V_396 ) ) {
V_2 -> V_330 = V_1140 ;
F_187 () ;
F_333 () ;
F_434 () ;
V_2 -> V_1138 = F_230 ( & V_2 -> V_138 -> V_486 ) ;
V_120 = 1 ;
goto V_1135;
}
F_71 ( V_2 ) ;
if ( V_1104 )
F_575 ( V_2 -> V_23 ) ;
F_576 ( V_2 -> V_297 ) ;
F_577 ( V_2 ) ;
F_578 () ;
if ( F_168 ( V_2 -> V_5 . V_183 ) ) {
F_579 ( 0 , 7 ) ;
F_579 ( V_2 -> V_5 . V_181 [ 0 ] , 0 ) ;
F_579 ( V_2 -> V_5 . V_181 [ 1 ] , 1 ) ;
F_579 ( V_2 -> V_5 . V_181 [ 2 ] , 2 ) ;
F_579 ( V_2 -> V_5 . V_181 [ 3 ] , 3 ) ;
F_579 ( V_2 -> V_5 . V_186 , 6 ) ;
V_2 -> V_5 . V_183 &= ~ V_184 ;
}
V_73 -> V_840 ( V_2 ) ;
if ( F_168 ( V_2 -> V_5 . V_183 & V_1141 ) ) {
F_28 ( V_2 -> V_178 & V_179 ) ;
V_73 -> V_1142 ( V_2 ) ;
F_93 ( V_2 ) ;
F_94 ( V_2 ) ;
F_95 ( V_2 ) ;
V_2 -> V_5 . V_183 &= ~ V_184 ;
}
if ( F_580 () )
F_581 () ;
V_2 -> V_5 . V_323 = F_151 ( V_2 , F_150 () ) ;
V_2 -> V_330 = V_1140 ;
F_187 () ;
F_73 ( V_2 ) ;
V_73 -> V_1143 ( V_2 ) ;
++ V_2 -> V_77 . V_1144 ;
F_582 () ;
F_583 () ;
F_434 () ;
V_2 -> V_1138 = F_230 ( & V_2 -> V_138 -> V_486 ) ;
if ( F_168 ( V_1145 == V_1146 ) ) {
unsigned long V_1066 = F_444 ( V_2 ) ;
F_584 ( V_1146 , ( void * ) V_1066 ) ;
}
if ( F_168 ( V_2 -> V_5 . V_275 ) )
F_30 ( V_338 , V_2 ) ;
if ( V_2 -> V_5 . V_1147 )
F_585 ( V_2 ) ;
V_120 = V_73 -> V_1148 ( V_2 ) ;
return V_120 ;
V_1135:
V_73 -> V_1135 ( V_2 ) ;
if ( F_168 ( V_2 -> V_5 . V_1147 ) )
F_585 ( V_2 ) ;
V_113:
return V_120 ;
}
static inline int F_586 ( struct V_138 * V_138 , struct V_1 * V_2 )
{
if ( ! F_587 ( V_2 ) &&
( ! V_73 -> V_1149 || V_73 -> V_1149 ( V_2 ) == 0 ) ) {
F_231 ( & V_138 -> V_486 , V_2 -> V_1138 ) ;
F_588 ( V_2 ) ;
V_2 -> V_1138 = F_230 ( & V_138 -> V_486 ) ;
if ( V_73 -> V_1150 )
V_73 -> V_1150 ( V_2 ) ;
if ( ! F_562 ( V_1151 , V_2 ) )
return 1 ;
}
F_569 ( V_2 ) ;
switch( V_2 -> V_5 . V_1040 ) {
case V_1041 :
V_2 -> V_5 . V_1152 . V_1153 = false ;
V_2 -> V_5 . V_1040 =
V_1154 ;
case V_1154 :
V_2 -> V_5 . V_6 . V_1114 = false ;
break;
case V_1132 :
break;
default:
return - V_1155 ;
break;
}
return 1 ;
}
static inline bool F_589 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_1040 == V_1154 &&
! V_2 -> V_5 . V_6 . V_1114 ) ;
}
static int F_590 ( struct V_1 * V_2 )
{
int V_120 ;
struct V_138 * V_138 = V_2 -> V_138 ;
V_2 -> V_1138 = F_230 ( & V_138 -> V_486 ) ;
for (; ; ) {
if ( F_589 ( V_2 ) ) {
V_120 = F_561 ( V_2 ) ;
} else {
V_120 = F_586 ( V_138 , V_2 ) ;
}
if ( V_120 <= 0 )
break;
F_178 ( V_239 , & V_2 -> V_339 ) ;
if ( F_591 ( V_2 ) )
F_592 ( V_2 ) ;
if ( F_529 ( V_2 ) &&
F_256 ( V_2 ) ) {
V_120 = 0 ;
V_2 -> V_840 -> V_856 = V_1156 ;
++ V_2 -> V_77 . V_1157 ;
break;
}
F_593 ( V_2 ) ;
if ( F_574 ( V_396 ) ) {
V_120 = - V_1155 ;
V_2 -> V_840 -> V_856 = V_1158 ;
++ V_2 -> V_77 . V_1159 ;
break;
}
if ( F_573 () ) {
F_231 ( & V_138 -> V_486 , V_2 -> V_1138 ) ;
F_594 () ;
V_2 -> V_1138 = F_230 ( & V_138 -> V_486 ) ;
}
}
F_231 ( & V_138 -> V_486 , V_2 -> V_1138 ) ;
return V_120 ;
}
static inline int F_595 ( struct V_1 * V_2 )
{
int V_120 ;
V_2 -> V_1138 = F_230 ( & V_2 -> V_138 -> V_486 ) ;
V_120 = F_596 ( V_2 , V_975 ) ;
F_231 ( & V_2 -> V_138 -> V_486 , V_2 -> V_1138 ) ;
if ( V_120 != V_942 )
return 0 ;
return 1 ;
}
static int V_988 ( struct V_1 * V_2 )
{
F_13 ( ! V_2 -> V_5 . V_871 . V_745 ) ;
return F_595 ( V_2 ) ;
}
static int V_989 ( struct V_1 * V_2 )
{
struct V_962 * V_840 = V_2 -> V_840 ;
struct V_838 * V_839 ;
unsigned V_95 ;
F_13 ( ! V_2 -> V_852 ) ;
V_839 = & V_2 -> V_835 [ V_2 -> V_853 ] ;
V_95 = F_338 ( 8u , V_839 -> V_95 ) ;
if ( ! V_2 -> V_855 )
memcpy ( V_839 -> V_38 , V_840 -> V_841 . V_38 , V_95 ) ;
if ( V_839 -> V_95 <= 8 ) {
V_839 ++ ;
V_2 -> V_853 ++ ;
} else {
V_839 -> V_38 += V_95 ;
V_839 -> V_389 += V_95 ;
V_839 -> V_95 -= V_95 ;
}
if ( V_2 -> V_853 >= V_2 -> V_846 ) {
V_2 -> V_852 = 0 ;
if ( V_2 -> V_855 )
return 1 ;
V_2 -> V_834 = 1 ;
return F_595 ( V_2 ) ;
}
V_840 -> V_856 = V_857 ;
V_840 -> V_841 . V_858 = V_839 -> V_389 ;
if ( V_2 -> V_855 )
memcpy ( V_840 -> V_841 . V_38 , V_839 -> V_38 , F_338 ( 8u , V_839 -> V_95 ) ) ;
V_840 -> V_841 . V_95 = F_338 ( 8u , V_839 -> V_95 ) ;
V_840 -> V_841 . V_854 = V_2 -> V_855 ;
V_2 -> V_5 . V_987 = V_989 ;
return 0 ;
}
int F_597 ( struct V_1 * V_2 , struct V_962 * V_962 )
{
struct V_1160 * V_1160 = & V_396 -> V_1161 . V_1160 ;
int V_120 ;
T_18 V_1162 ;
F_598 ( V_1160 ) ;
if ( V_2 -> V_1163 )
F_599 ( V_1164 , & V_2 -> V_1165 , & V_1162 ) ;
if ( F_168 ( V_2 -> V_5 . V_1040 == V_1166 ) ) {
F_588 ( V_2 ) ;
F_569 ( V_2 ) ;
F_178 ( V_1151 , & V_2 -> V_339 ) ;
V_120 = - V_1167 ;
goto V_113;
}
if ( ! F_89 ( V_2 ) ) {
if ( F_88 ( V_2 , V_962 -> V_176 ) != 0 ) {
V_120 = - V_578 ;
goto V_113;
}
}
if ( F_168 ( V_2 -> V_5 . V_987 ) ) {
int (* F_600)( struct V_1 * ) = V_2 -> V_5 . V_987 ;
V_2 -> V_5 . V_987 = NULL ;
V_120 = F_600 ( V_2 ) ;
if ( V_120 <= 0 )
goto V_113;
} else
F_28 ( V_2 -> V_5 . V_871 . V_745 || V_2 -> V_852 ) ;
V_120 = F_590 ( V_2 ) ;
V_113:
F_530 ( V_2 ) ;
if ( V_2 -> V_1163 )
F_599 ( V_1164 , & V_1162 , NULL ) ;
return V_120 ;
}
int F_601 ( struct V_1 * V_2 , struct V_1168 * V_592 )
{
if ( V_2 -> V_5 . V_992 ) {
F_602 ( & V_2 -> V_5 . V_922 ) ;
V_2 -> V_5 . V_992 = false ;
}
V_592 -> V_1169 = F_102 ( V_2 , V_202 ) ;
V_592 -> V_1170 = F_102 ( V_2 , V_1058 ) ;
V_592 -> V_1171 = F_102 ( V_2 , V_201 ) ;
V_592 -> V_1172 = F_102 ( V_2 , V_203 ) ;
V_592 -> V_1173 = F_102 ( V_2 , V_1059 ) ;
V_592 -> V_1174 = F_102 ( V_2 , V_1175 ) ;
V_592 -> V_1176 = F_102 ( V_2 , V_1177 ) ;
V_592 -> V_1178 = F_102 ( V_2 , V_1179 ) ;
#ifdef F_62
V_592 -> V_1180 = F_102 ( V_2 , V_1181 ) ;
V_592 -> V_1182 = F_102 ( V_2 , V_1183 ) ;
V_592 -> V_1184 = F_102 ( V_2 , V_1185 ) ;
V_592 -> V_1186 = F_102 ( V_2 , V_1187 ) ;
V_592 -> V_1188 = F_102 ( V_2 , V_1189 ) ;
V_592 -> V_1190 = F_102 ( V_2 , V_1191 ) ;
V_592 -> V_1192 = F_102 ( V_2 , V_1193 ) ;
V_592 -> V_1194 = F_102 ( V_2 , V_1195 ) ;
#endif
V_592 -> V_1066 = F_444 ( V_2 ) ;
V_592 -> V_961 = F_443 ( V_2 ) ;
return 0 ;
}
int F_603 ( struct V_1 * V_2 , struct V_1168 * V_592 )
{
V_2 -> V_5 . V_936 = true ;
V_2 -> V_5 . V_992 = false ;
F_104 ( V_2 , V_202 , V_592 -> V_1169 ) ;
F_104 ( V_2 , V_1058 , V_592 -> V_1170 ) ;
F_104 ( V_2 , V_201 , V_592 -> V_1171 ) ;
F_104 ( V_2 , V_203 , V_592 -> V_1172 ) ;
F_104 ( V_2 , V_1059 , V_592 -> V_1173 ) ;
F_104 ( V_2 , V_1175 , V_592 -> V_1174 ) ;
F_104 ( V_2 , V_1177 , V_592 -> V_1176 ) ;
F_104 ( V_2 , V_1179 , V_592 -> V_1178 ) ;
#ifdef F_62
F_104 ( V_2 , V_1181 , V_592 -> V_1180 ) ;
F_104 ( V_2 , V_1183 , V_592 -> V_1182 ) ;
F_104 ( V_2 , V_1185 , V_592 -> V_1184 ) ;
F_104 ( V_2 , V_1187 , V_592 -> V_1186 ) ;
F_104 ( V_2 , V_1189 , V_592 -> V_1188 ) ;
F_104 ( V_2 , V_1191 , V_592 -> V_1190 ) ;
F_104 ( V_2 , V_1193 , V_592 -> V_1192 ) ;
F_104 ( V_2 , V_1195 , V_592 -> V_1194 ) ;
#endif
F_448 ( V_2 , V_592 -> V_1066 ) ;
F_449 ( V_2 , V_592 -> V_961 ) ;
V_2 -> V_5 . V_68 . V_69 = false ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
void F_604 ( struct V_1 * V_2 , int * V_182 , int * V_907 )
{
struct V_814 V_1085 ;
F_346 ( V_2 , & V_1085 , V_1090 ) ;
* V_182 = V_1085 . V_182 ;
* V_907 = V_1085 . V_907 ;
}
int F_605 ( struct V_1 * V_2 ,
struct V_1196 * V_1197 )
{
struct V_890 V_891 ;
F_346 ( V_2 , & V_1197 -> V_1085 , V_1090 ) ;
F_346 ( V_2 , & V_1197 -> V_1086 , V_1091 ) ;
F_346 ( V_2 , & V_1197 -> V_1198 , V_1092 ) ;
F_346 ( V_2 , & V_1197 -> V_1199 , V_1093 ) ;
F_346 ( V_2 , & V_1197 -> V_1200 , V_1094 ) ;
F_346 ( V_2 , & V_1197 -> V_1201 , V_1095 ) ;
F_346 ( V_2 , & V_1197 -> V_1202 , V_1083 ) ;
F_346 ( V_2 , & V_1197 -> V_1203 , V_1084 ) ;
V_73 -> V_893 ( V_2 , & V_891 ) ;
V_1197 -> V_1204 . V_902 = V_891 . V_491 ;
V_1197 -> V_1204 . V_229 = V_891 . V_80 ;
V_73 -> V_892 ( V_2 , & V_891 ) ;
V_1197 -> V_1205 . V_902 = V_891 . V_491 ;
V_1197 -> V_1205 . V_229 = V_891 . V_80 ;
V_1197 -> V_121 = F_61 ( V_2 ) ;
V_1197 -> V_79 = V_2 -> V_5 . V_79 ;
V_1197 -> V_104 = F_59 ( V_2 ) ;
V_1197 -> V_158 = F_78 ( V_2 ) ;
V_1197 -> V_176 = F_91 ( V_2 ) ;
V_1197 -> V_131 = V_2 -> V_5 . V_131 ;
V_1197 -> V_31 = F_19 ( V_2 ) ;
memset ( V_1197 -> V_1206 , 0 , sizeof V_1197 -> V_1206 ) ;
if ( V_2 -> V_5 . V_620 . V_69 && ! V_2 -> V_5 . V_620 . V_621 )
F_214 ( V_2 -> V_5 . V_620 . V_16 ,
( unsigned long * ) V_1197 -> V_1206 ) ;
return 0 ;
}
int F_606 ( struct V_1 * V_2 ,
struct V_1207 * V_1040 )
{
F_569 ( V_2 ) ;
if ( V_2 -> V_5 . V_1040 == V_1041 &&
V_2 -> V_5 . V_1152 . V_1153 )
V_1040 -> V_1040 = V_1154 ;
else
V_1040 -> V_1040 = V_2 -> V_5 . V_1040 ;
return 0 ;
}
int F_607 ( struct V_1 * V_2 ,
struct V_1207 * V_1040 )
{
if ( ! F_89 ( V_2 ) &&
V_1040 -> V_1040 != V_1154 )
return - V_578 ;
if ( V_1040 -> V_1040 == V_1208 ) {
V_2 -> V_5 . V_1040 = V_1132 ;
F_214 ( V_1209 , & V_2 -> V_5 . V_593 -> V_646 ) ;
} else
V_2 -> V_5 . V_1040 = V_1040 -> V_1040 ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
int F_608 ( struct V_1 * V_2 , V_867 V_1210 , int V_1211 ,
int V_1212 , bool V_71 , T_1 V_62 )
{
struct V_828 * V_829 = & V_2 -> V_5 . V_922 ;
int V_108 ;
F_442 ( V_2 ) ;
V_108 = F_609 ( V_829 , V_1210 , V_1211 , V_1212 ,
V_71 , V_62 ) ;
if ( V_108 )
return V_941 ;
F_448 ( V_2 , V_829 -> V_925 ) ;
F_449 ( V_2 , V_829 -> V_924 ) ;
F_30 ( V_67 , V_2 ) ;
return V_942 ;
}
int F_610 ( struct V_1 * V_2 ,
struct V_1196 * V_1197 )
{
struct V_32 V_1213 ;
int V_1214 = 0 ;
int V_1215 , V_1216 , V_485 ;
struct V_890 V_891 ;
if ( ! F_79 ( V_2 ) && ( V_1197 -> V_158 & V_141 ) )
return - V_578 ;
V_891 . V_491 = V_1197 -> V_1204 . V_902 ;
V_891 . V_80 = V_1197 -> V_1204 . V_229 ;
V_73 -> V_895 ( V_2 , & V_891 ) ;
V_891 . V_491 = V_1197 -> V_1205 . V_902 ;
V_891 . V_80 = V_1197 -> V_1205 . V_229 ;
V_73 -> V_894 ( V_2 , & V_891 ) ;
V_2 -> V_5 . V_79 = V_1197 -> V_79 ;
V_1214 |= F_59 ( V_2 ) != V_1197 -> V_104 ;
V_2 -> V_5 . V_104 = V_1197 -> V_104 ;
F_54 ( V_174 , ( V_175 * ) & V_2 -> V_5 . V_117 ) ;
F_88 ( V_2 , V_1197 -> V_176 ) ;
V_1214 |= V_2 -> V_5 . V_131 != V_1197 -> V_131 ;
V_73 -> F_108 ( V_2 , V_1197 -> V_131 ) ;
V_1213 . V_38 = V_1197 -> V_31 ;
V_1213 . V_40 = true ;
F_20 ( V_2 , & V_1213 ) ;
V_1214 |= F_61 ( V_2 ) != V_1197 -> V_121 ;
V_73 -> V_137 ( V_2 , V_1197 -> V_121 ) ;
V_2 -> V_5 . V_121 = V_1197 -> V_121 ;
V_1214 |= F_78 ( V_2 ) != V_1197 -> V_158 ;
V_73 -> V_170 ( V_2 , V_1197 -> V_158 ) ;
if ( V_1197 -> V_158 & ( V_141 | V_166 ) )
F_75 ( V_2 ) ;
V_485 = F_230 ( & V_2 -> V_138 -> V_486 ) ;
if ( ! F_56 ( V_2 ) && F_57 ( V_2 ) ) {
F_51 ( V_2 , V_2 -> V_5 . V_103 , F_59 ( V_2 ) ) ;
V_1214 = 1 ;
}
F_231 ( & V_2 -> V_138 -> V_486 , V_485 ) ;
if ( V_1214 )
F_65 ( V_2 ) ;
V_1216 = V_596 ;
V_1215 = F_611 (
( const unsigned long * ) V_1197 -> V_1206 , V_1216 ) ;
if ( V_1215 < V_1216 ) {
F_262 ( V_2 , V_1215 , false ) ;
F_131 ( L_27 , V_1215 ) ;
}
F_345 ( V_2 , & V_1197 -> V_1085 , V_1090 ) ;
F_345 ( V_2 , & V_1197 -> V_1086 , V_1091 ) ;
F_345 ( V_2 , & V_1197 -> V_1198 , V_1092 ) ;
F_345 ( V_2 , & V_1197 -> V_1199 , V_1093 ) ;
F_345 ( V_2 , & V_1197 -> V_1200 , V_1094 ) ;
F_345 ( V_2 , & V_1197 -> V_1201 , V_1095 ) ;
F_345 ( V_2 , & V_1197 -> V_1202 , V_1083 ) ;
F_345 ( V_2 , & V_1197 -> V_1203 , V_1084 ) ;
F_253 ( V_2 ) ;
if ( F_612 ( V_2 ) && F_444 ( V_2 ) == 0xfff0 &&
V_1197 -> V_1085 . V_896 == 0xf000 && V_1197 -> V_1085 . V_229 == 0xffff0000 &&
! F_31 ( V_2 ) )
V_2 -> V_5 . V_1040 = V_1154 ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
int F_613 ( struct V_1 * V_2 ,
struct V_1217 * V_1218 )
{
unsigned long V_961 ;
int V_3 , V_120 ;
if ( V_1218 -> V_752 & ( V_1219 | V_1220 ) ) {
V_120 = - V_795 ;
if ( V_2 -> V_5 . V_68 . V_69 )
goto V_113;
if ( V_1218 -> V_752 & V_1219 )
F_32 ( V_2 , V_53 ) ;
else
F_32 ( V_2 , V_54 ) ;
}
V_961 = F_443 ( V_2 ) ;
V_2 -> V_178 = V_1218 -> V_752 ;
if ( ! ( V_2 -> V_178 & V_1221 ) )
V_2 -> V_178 = 0 ;
if ( V_2 -> V_178 & V_179 ) {
for ( V_3 = 0 ; V_3 < V_180 ; ++ V_3 )
V_2 -> V_5 . V_181 [ V_3 ] = V_1218 -> V_5 . V_1222 [ V_3 ] ;
V_2 -> V_5 . V_188 = V_1218 -> V_5 . V_1222 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_180 ; V_3 ++ )
V_2 -> V_5 . V_181 [ V_3 ] = V_2 -> V_5 . V_182 [ V_3 ] ;
}
F_95 ( V_2 ) ;
if ( V_2 -> V_178 & V_964 )
V_2 -> V_5 . V_968 = F_444 ( V_2 ) +
F_393 ( V_2 , V_1090 ) ;
F_449 ( V_2 , V_961 ) ;
V_73 -> V_1223 ( V_2 ) ;
V_120 = 0 ;
V_113:
return V_120 ;
}
int F_614 ( struct V_1 * V_2 ,
struct V_1224 * V_1202 )
{
unsigned long V_1225 = V_1202 -> V_1226 ;
T_6 V_389 ;
int V_485 ;
V_485 = F_230 ( & V_2 -> V_138 -> V_486 ) ;
V_389 = F_351 ( V_2 , V_1225 , NULL ) ;
F_231 ( & V_2 -> V_138 -> V_486 , V_485 ) ;
V_1202 -> V_1227 = V_389 ;
V_1202 -> V_657 = V_389 != V_100 ;
V_1202 -> V_1228 = 1 ;
V_1202 -> V_1229 = 0 ;
return 0 ;
}
int F_615 ( struct V_1 * V_2 , struct V_1230 * V_1160 )
{
struct V_670 * V_669 =
& V_2 -> V_5 . V_652 . V_653 . V_669 ;
memcpy ( V_1160 -> V_1231 , V_669 -> V_1232 , 128 ) ;
V_1160 -> V_1233 = V_669 -> V_1234 ;
V_1160 -> V_1235 = V_669 -> V_1236 ;
V_1160 -> V_1237 = V_669 -> V_1238 ;
V_1160 -> V_1239 = V_669 -> V_1240 ;
V_1160 -> V_1241 = V_669 -> V_1066 ;
V_1160 -> V_1242 = V_669 -> V_1243 ;
memcpy ( V_1160 -> V_1244 , V_669 -> V_1245 , sizeof V_669 -> V_1245 ) ;
return 0 ;
}
int F_616 ( struct V_1 * V_2 , struct V_1230 * V_1160 )
{
struct V_670 * V_669 =
& V_2 -> V_5 . V_652 . V_653 . V_669 ;
memcpy ( V_669 -> V_1232 , V_1160 -> V_1231 , 128 ) ;
V_669 -> V_1234 = V_1160 -> V_1233 ;
V_669 -> V_1236 = V_1160 -> V_1235 ;
V_669 -> V_1238 = V_1160 -> V_1237 ;
V_669 -> V_1240 = V_1160 -> V_1239 ;
V_669 -> V_1066 = V_1160 -> V_1241 ;
V_669 -> V_1243 = V_1160 -> V_1242 ;
memcpy ( V_669 -> V_1245 , V_1160 -> V_1244 , sizeof V_669 -> V_1245 ) ;
return 0 ;
}
static void F_617 ( struct V_1 * V_2 )
{
F_618 ( & V_2 -> V_5 . V_652 . V_653 ) ;
if ( V_663 )
V_2 -> V_5 . V_652 . V_653 . V_651 . V_655 . V_664 =
V_145 | V_665 ;
V_2 -> V_5 . V_144 = V_150 ;
V_2 -> V_5 . V_121 |= V_126 ;
}
void F_431 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1246 )
return;
V_2 -> V_1246 = 1 ;
F_619 () ;
F_620 ( & V_2 -> V_5 . V_652 . V_653 ) ;
F_621 ( 1 ) ;
}
void F_249 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_1246 ) {
V_2 -> V_1247 = 0 ;
return;
}
V_2 -> V_1246 = 0 ;
F_622 ( & V_2 -> V_5 . V_652 ) ;
F_623 () ;
++ V_2 -> V_77 . V_1248 ;
if ( ! F_624 () ) {
if ( ++ V_2 -> V_1247 < 5 )
F_30 ( V_1110 , V_2 ) ;
}
F_621 ( 0 ) ;
}
void F_625 ( struct V_1 * V_2 )
{
F_206 ( V_2 ) ;
F_626 ( V_2 -> V_5 . V_582 ) ;
V_73 -> V_1249 ( V_2 ) ;
}
struct V_1 * F_627 ( struct V_138 * V_138 ,
unsigned int V_1250 )
{
struct V_1 * V_2 ;
if ( F_155 () && F_143 ( & V_138 -> V_293 ) != 0 )
F_387 ( V_869
L_28
L_29 ) ;
V_2 = V_73 -> V_1251 ( V_138 , V_1250 ) ;
return V_2 ;
}
int F_628 ( struct V_1 * V_2 )
{
int V_120 ;
F_629 ( V_2 ) ;
V_120 = V_583 ( V_2 ) ;
if ( V_120 )
return V_120 ;
F_630 ( V_2 , false ) ;
F_631 ( V_2 ) ;
V_587 ( V_2 ) ;
return V_120 ;
}
void F_632 ( struct V_1 * V_2 )
{
struct V_32 V_21 ;
struct V_138 * V_138 = V_2 -> V_138 ;
if ( V_583 ( V_2 ) )
return;
V_21 . V_38 = 0x0 ;
V_21 . V_146 = V_1252 ;
V_21 . V_40 = true ;
F_152 ( V_2 , & V_21 ) ;
V_587 ( V_2 ) ;
if ( ! V_364 )
return;
F_193 ( & V_138 -> V_5 . V_363 ,
V_365 ) ;
}
void F_633 ( struct V_1 * V_2 )
{
int V_120 ;
V_2 -> V_5 . V_6 . V_390 = 0 ;
V_120 = V_583 ( V_2 ) ;
F_13 ( V_120 ) ;
F_563 ( V_2 ) ;
V_587 ( V_2 ) ;
V_73 -> V_1249 ( V_2 ) ;
}
void F_630 ( struct V_1 * V_2 , bool V_1253 )
{
V_2 -> V_5 . V_634 = 0 ;
F_172 ( & V_2 -> V_5 . V_85 , 0 ) ;
V_2 -> V_5 . V_626 = 0 ;
V_2 -> V_5 . V_625 = false ;
F_634 ( V_2 ) ;
F_468 ( V_2 ) ;
memset ( V_2 -> V_5 . V_182 , 0 , sizeof( V_2 -> V_5 . V_182 ) ) ;
F_93 ( V_2 ) ;
V_2 -> V_5 . V_186 = V_1254 ;
F_94 ( V_2 ) ;
V_2 -> V_5 . V_187 = V_198 ;
F_95 ( V_2 ) ;
V_2 -> V_5 . V_79 = 0 ;
F_30 ( V_67 , V_2 ) ;
V_2 -> V_5 . V_6 . V_390 = 0 ;
V_2 -> V_5 . V_394 . V_390 = 0 ;
F_206 ( V_2 ) ;
F_64 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1114 = false ;
if ( ! V_1253 ) {
F_635 ( V_2 ) ;
V_2 -> V_5 . V_425 = 0x30000 ;
}
memset ( V_2 -> V_5 . V_592 , 0 , sizeof( V_2 -> V_5 . V_592 ) ) ;
V_2 -> V_5 . V_117 = ~ 0 ;
V_2 -> V_5 . V_118 = ~ 0 ;
V_73 -> V_1255 ( V_2 , V_1253 ) ;
}
void F_636 ( struct V_1 * V_2 , T_14 V_41 )
{
struct V_814 V_1085 ;
F_346 ( V_2 , & V_1085 , V_1090 ) ;
V_1085 . V_896 = V_41 << 8 ;
V_1085 . V_229 = V_41 << 12 ;
F_345 ( V_2 , & V_1085 , V_1090 ) ;
F_448 ( V_2 , 0 ) ;
}
int F_637 ( void )
{
struct V_138 * V_138 ;
struct V_1 * V_2 ;
int V_3 ;
int V_108 ;
T_2 V_1256 ;
T_2 V_1257 = 0 ;
bool V_1258 , V_1259 = false ;
F_14 () ;
V_108 = V_73 -> V_1260 () ;
if ( V_108 != 0 )
return V_108 ;
V_1256 = F_150 () ;
V_1258 = ! F_155 () ;
F_482 (kvm, &vm_list, vm_list) {
F_177 (i, vcpu, kvm) {
if ( ! V_1258 && V_2 -> V_23 == F_8 () )
F_30 ( V_338 , V_2 ) ;
if ( V_1258 && V_2 -> V_5 . V_586 > V_1256 ) {
V_1259 = true ;
if ( V_2 -> V_5 . V_586 > V_1257 )
V_1257 = V_2 -> V_5 . V_586 ;
}
}
}
if ( V_1259 ) {
T_2 V_1261 = V_1257 - V_1256 ;
V_334 = true ;
F_482 (kvm, &vm_list, vm_list) {
F_177 (i, vcpu, kvm) {
V_2 -> V_5 . V_584 += V_1261 ;
V_2 -> V_5 . V_586 = V_1256 ;
F_30 ( V_296 , V_2 ) ;
}
V_138 -> V_5 . V_312 = 0 ;
V_138 -> V_5 . V_314 = 0 ;
}
}
return 0 ;
}
void F_638 ( void )
{
V_73 -> V_1262 () ;
F_18 () ;
}
int F_639 ( void )
{
int V_120 ;
V_120 = V_73 -> V_1263 () ;
if ( V_120 != 0 )
return V_120 ;
if ( V_272 ) {
T_2 V_1264 = F_338 ( 0x7fffffffULL ,
F_146 ( V_277 , V_273 ) ) ;
V_710 = V_1264 ;
V_271 = 1ULL << V_276 ;
}
F_335 () ;
return 0 ;
}
void F_640 ( void )
{
V_73 -> V_1265 () ;
}
void F_641 ( void * V_1266 )
{
V_73 -> V_1267 ( V_1266 ) ;
}
bool F_642 ( struct V_1 * V_2 )
{
return V_2 -> V_138 -> V_5 . V_796 == V_2 -> V_297 ;
}
bool F_612 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_31 & V_1268 ) != 0 ;
}
bool F_643 ( struct V_1 * V_2 )
{
return F_261 ( V_2 -> V_138 ) == F_89 ( V_2 ) ;
}
int F_644 ( struct V_1 * V_2 )
{
struct V_385 * V_385 ;
struct V_138 * V_138 ;
int V_120 ;
F_13 ( V_2 -> V_138 == NULL ) ;
V_138 = V_2 -> V_138 ;
V_2 -> V_5 . V_590 = V_73 -> V_1269 () ;
V_2 -> V_5 . V_1152 . V_1153 = false ;
V_2 -> V_5 . V_922 . V_843 = & V_1270 ;
if ( ! F_261 ( V_138 ) || F_642 ( V_2 ) )
V_2 -> V_5 . V_1040 = V_1154 ;
else
V_2 -> V_5 . V_1040 = V_1166 ;
V_385 = F_645 ( V_683 | V_1271 ) ;
if ( ! V_385 ) {
V_120 = - V_387 ;
goto V_1272;
}
V_2 -> V_5 . V_875 = F_646 ( V_385 ) ;
F_140 ( V_2 , V_1010 ) ;
V_120 = F_647 ( V_2 ) ;
if ( V_120 < 0 )
goto V_1273;
if ( F_261 ( V_138 ) ) {
V_120 = F_648 ( V_2 ) ;
if ( V_120 < 0 )
goto V_1274;
} else
F_649 ( & V_1275 ) ;
V_2 -> V_5 . V_374 = F_291 ( V_439 * sizeof( T_2 ) * 4 ,
V_683 ) ;
if ( ! V_2 -> V_5 . V_374 ) {
V_120 = - V_387 ;
goto V_1276;
}
V_2 -> V_5 . V_366 = V_439 ;
if ( ! F_650 ( & V_2 -> V_5 . V_582 , V_683 ) ) {
V_120 = - V_387 ;
goto V_1277;
}
F_617 ( V_2 ) ;
V_2 -> V_5 . V_300 = 0x0 ;
V_2 -> V_5 . V_347 = false ;
V_2 -> V_5 . V_153 = 0 ;
V_2 -> V_5 . V_1278 = V_1279 + V_658 ;
V_2 -> V_5 . V_1021 = F_651 ( V_2 ) ;
V_2 -> V_5 . V_1280 = V_1281 ;
F_1 ( V_2 ) ;
F_652 ( V_2 ) ;
V_2 -> V_5 . V_598 = - 1 ;
F_653 ( V_2 ) ;
return 0 ;
V_1277:
F_202 ( V_2 -> V_5 . V_374 ) ;
V_1276:
F_654 ( V_2 ) ;
V_1274:
F_655 ( V_2 ) ;
V_1273:
F_656 ( ( unsigned long ) V_2 -> V_5 . V_875 ) ;
V_1272:
return V_120 ;
}
void F_657 ( struct V_1 * V_2 )
{
int V_485 ;
F_658 ( V_2 ) ;
F_659 ( V_2 ) ;
F_202 ( V_2 -> V_5 . V_374 ) ;
F_654 ( V_2 ) ;
V_485 = F_230 ( & V_2 -> V_138 -> V_486 ) ;
F_655 ( V_2 ) ;
F_231 ( & V_2 -> V_138 -> V_486 , V_485 ) ;
F_656 ( ( unsigned long ) V_2 -> V_5 . V_875 ) ;
if ( ! F_89 ( V_2 ) )
F_660 ( & V_1275 ) ;
}
void F_661 ( struct V_1 * V_2 , int V_23 )
{
V_73 -> V_1282 ( V_2 , V_23 ) ;
}
int F_662 ( struct V_138 * V_138 , unsigned long type )
{
if ( type )
return - V_578 ;
F_663 ( & V_138 -> V_5 . V_1283 ) ;
F_664 ( & V_138 -> V_5 . V_1284 ) ;
F_664 ( & V_138 -> V_5 . V_1285 ) ;
F_664 ( & V_138 -> V_5 . V_1286 ) ;
F_172 ( & V_138 -> V_5 . V_1287 , 0 ) ;
F_214 ( V_760 , & V_138 -> V_5 . V_1288 ) ;
F_214 ( V_1289 ,
& V_138 -> V_5 . V_1288 ) ;
F_665 ( & V_138 -> V_5 . V_311 ) ;
F_666 ( & V_138 -> V_5 . V_1290 ) ;
F_667 ( & V_138 -> V_5 . V_325 ) ;
F_171 ( V_138 ) ;
F_668 ( & V_138 -> V_5 . V_361 , F_189 ) ;
F_668 ( & V_138 -> V_5 . V_363 , F_194 ) ;
F_669 ( V_138 ) ;
F_670 ( V_138 ) ;
return 0 ;
}
static void F_671 ( struct V_1 * V_2 )
{
int V_120 ;
V_120 = V_583 ( V_2 ) ;
F_13 ( V_120 ) ;
F_563 ( V_2 ) ;
V_587 ( V_2 ) ;
}
static void F_672 ( struct V_138 * V_138 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_177 (i, vcpu, kvm) {
F_64 ( V_2 ) ;
F_671 ( V_2 ) ;
}
F_177 (i, vcpu, kvm)
F_625 ( V_2 ) ;
F_300 ( & V_138 -> V_735 ) ;
for ( V_3 = 0 ; V_3 < F_143 ( & V_138 -> V_293 ) ; V_3 ++ )
V_138 -> V_1291 [ V_3 ] = NULL ;
F_172 ( & V_138 -> V_293 , 0 ) ;
F_302 ( & V_138 -> V_735 ) ;
}
void F_673 ( struct V_138 * V_138 )
{
F_674 ( & V_138 -> V_5 . V_363 ) ;
F_674 ( & V_138 -> V_5 . V_361 ) ;
F_675 ( V_138 ) ;
F_676 ( V_138 ) ;
}
int F_677 ( struct V_138 * V_138 , int V_1250 , T_6 V_389 , T_1 V_491 )
{
int V_3 , V_120 ;
unsigned long V_1292 ;
struct V_1293 * V_1294 = V_1293 ( V_138 ) ;
struct V_1295 * V_10 , V_862 ;
if ( F_28 ( V_1250 >= V_1296 ) )
return - V_578 ;
V_10 = F_678 ( V_1294 , V_1250 ) ;
if ( V_491 ) {
if ( F_28 ( V_10 -> V_1297 ) )
return - V_599 ;
V_1292 = F_679 ( NULL , 0 , V_491 , V_1298 | V_1299 ,
V_1300 | V_1301 , 0 ) ;
if ( F_199 ( ( void * ) V_1292 ) )
return F_200 ( ( void * ) V_1292 ) ;
} else {
if ( ! V_10 -> V_1297 )
return 0 ;
V_1292 = 0 ;
}
V_862 = * V_10 ;
for ( V_3 = 0 ; V_3 < V_1302 ; V_3 ++ ) {
struct V_1303 V_1304 ;
V_1304 . V_10 = V_1250 | ( V_3 << 16 ) ;
V_1304 . V_307 = 0 ;
V_1304 . V_1305 = V_389 ;
V_1304 . V_1306 = V_1292 ;
V_1304 . V_1307 = V_491 ;
V_120 = F_680 ( V_138 , & V_1304 ) ;
if ( V_120 < 0 )
return V_120 ;
}
if ( ! V_491 ) {
V_120 = F_681 ( V_862 . V_1306 , V_862 . V_1297 * V_107 ) ;
F_28 ( V_120 < 0 ) ;
}
return 0 ;
}
int F_682 ( struct V_138 * V_138 , int V_1250 , T_6 V_389 , T_1 V_491 )
{
int V_120 ;
F_300 ( & V_138 -> V_722 ) ;
V_120 = F_677 ( V_138 , V_1250 , V_389 , V_491 ) ;
F_302 ( & V_138 -> V_722 ) ;
return V_120 ;
}
void F_683 ( struct V_138 * V_138 )
{
if ( V_396 -> V_1308 == V_138 -> V_1308 ) {
F_682 ( V_138 , V_1309 , 0 , 0 ) ;
F_682 ( V_138 , V_1310 , 0 , 0 ) ;
F_682 ( V_138 , V_1311 , 0 , 0 ) ;
}
F_684 ( V_138 ) ;
F_202 ( V_138 -> V_5 . V_777 ) ;
F_202 ( V_138 -> V_5 . V_1312 ) ;
F_672 ( V_138 ) ;
F_202 ( F_685 ( V_138 -> V_5 . V_1313 , 1 ) ) ;
F_686 ( V_138 ) ;
}
void F_687 ( struct V_138 * V_138 , struct V_1295 * free ,
struct V_1295 * V_1314 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1315 ; ++ V_3 ) {
if ( ! V_1314 || free -> V_5 . V_1316 [ V_3 ] != V_1314 -> V_5 . V_1316 [ V_3 ] ) {
F_688 ( free -> V_5 . V_1316 [ V_3 ] ) ;
free -> V_5 . V_1316 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1314 || free -> V_5 . V_1317 [ V_3 - 1 ] !=
V_1314 -> V_5 . V_1317 [ V_3 - 1 ] ) {
F_688 ( free -> V_5 . V_1317 [ V_3 - 1 ] ) ;
free -> V_5 . V_1317 [ V_3 - 1 ] = NULL ;
}
}
F_689 ( free , V_1314 ) ;
}
int F_690 ( struct V_138 * V_138 , struct V_1295 * V_10 ,
unsigned long V_1297 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1315 ; ++ V_3 ) {
struct V_1318 * V_1319 ;
unsigned long V_1320 ;
int V_1321 ;
int V_761 = V_3 + 1 ;
V_1321 = F_691 ( V_10 -> V_1322 + V_1297 - 1 ,
V_10 -> V_1322 , V_761 ) + 1 ;
V_10 -> V_5 . V_1316 [ V_3 ] =
F_692 ( V_1321 * sizeof( * V_10 -> V_5 . V_1316 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1316 [ V_3 ] )
goto V_388;
if ( V_3 == 0 )
continue;
V_1319 = F_692 ( V_1321 * sizeof( * V_1319 ) ) ;
if ( ! V_1319 )
goto V_388;
V_10 -> V_5 . V_1317 [ V_3 - 1 ] = V_1319 ;
if ( V_10 -> V_1322 & ( F_693 ( V_761 ) - 1 ) )
V_1319 [ 0 ] . V_1323 = 1 ;
if ( ( V_10 -> V_1322 + V_1297 ) & ( F_693 ( V_761 ) - 1 ) )
V_1319 [ V_1321 - 1 ] . V_1323 = 1 ;
V_1320 = V_10 -> V_1306 >> V_106 ;
if ( ( V_10 -> V_1322 ^ V_1320 ) & ( F_693 ( V_761 ) - 1 ) ||
! F_694 () ) {
unsigned long V_805 ;
for ( V_805 = 0 ; V_805 < V_1321 ; ++ V_805 )
V_1319 [ V_805 ] . V_1323 = 1 ;
}
}
if ( F_695 ( V_10 , V_1297 ) )
goto V_388;
return 0 ;
V_388:
for ( V_3 = 0 ; V_3 < V_1315 ; ++ V_3 ) {
F_688 ( V_10 -> V_5 . V_1316 [ V_3 ] ) ;
V_10 -> V_5 . V_1316 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_688 ( V_10 -> V_5 . V_1317 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1317 [ V_3 - 1 ] = NULL ;
}
return - V_387 ;
}
void F_696 ( struct V_138 * V_138 , struct V_1293 * V_1294 )
{
F_697 ( V_138 , V_1294 ) ;
}
int F_698 ( struct V_138 * V_138 ,
struct V_1295 * V_1324 ,
const struct V_1303 * V_1325 ,
enum V_1326 V_1327 )
{
return 0 ;
}
static void F_699 ( struct V_138 * V_138 ,
struct V_1295 * V_863 )
{
if ( V_863 -> V_307 & V_1328 ) {
F_700 ( V_138 , V_863 ) ;
return;
}
if ( V_863 -> V_307 & V_1329 ) {
if ( V_73 -> V_1330 )
V_73 -> V_1330 ( V_138 , V_863 ) ;
else
F_700 ( V_138 , V_863 ) ;
} else {
if ( V_73 -> V_1331 )
V_73 -> V_1331 ( V_138 , V_863 ) ;
}
}
void F_701 ( struct V_138 * V_138 ,
const struct V_1303 * V_1325 ,
const struct V_1295 * V_862 ,
const struct V_1295 * V_863 ,
enum V_1326 V_1327 )
{
int V_1332 = 0 ;
if ( ! V_138 -> V_5 . V_723 )
V_1332 = F_702 ( V_138 ) ;
if ( V_1332 )
F_301 ( V_138 , V_1332 ) ;
if ( ( V_1327 != V_1333 ) &&
( V_862 -> V_307 & V_1329 ) &&
! ( V_863 -> V_307 & V_1329 ) )
F_703 ( V_138 , V_863 ) ;
if ( V_1327 != V_1333 )
F_699 ( V_138 , (struct V_1295 * ) V_863 ) ;
}
void F_704 ( struct V_138 * V_138 )
{
F_705 ( V_138 ) ;
}
void F_706 ( struct V_138 * V_138 ,
struct V_1295 * V_10 )
{
F_705 ( V_138 ) ;
}
static inline bool F_707 ( struct V_1 * V_2 )
{
if ( ! F_708 ( & V_2 -> V_1334 . V_1335 ) )
return true ;
if ( F_709 ( V_2 ) )
return true ;
if ( V_2 -> V_5 . V_1152 . V_1153 )
return true ;
if ( F_143 ( & V_2 -> V_5 . V_85 ) )
return true ;
if ( F_58 ( V_600 , & V_2 -> V_339 ) )
return true ;
if ( F_257 ( V_2 ) &&
F_258 ( V_2 ) )
return true ;
if ( F_710 ( V_2 ) )
return true ;
return false ;
}
int F_587 ( struct V_1 * V_2 )
{
if ( F_452 ( V_2 ) && V_73 -> V_1079 )
V_73 -> V_1079 ( V_2 , false ) ;
return F_589 ( V_2 ) || F_707 ( V_2 ) ;
}
int F_711 ( struct V_1 * V_2 )
{
return F_712 ( V_2 ) == V_1137 ;
}
int F_257 ( struct V_1 * V_2 )
{
return V_73 -> V_1081 ( V_2 ) ;
}
unsigned long F_466 ( struct V_1 * V_2 )
{
if ( F_527 ( V_2 ) )
return F_444 ( V_2 ) ;
return ( T_1 ) ( F_393 ( V_2 , V_1090 ) +
F_444 ( V_2 ) ) ;
}
bool F_713 ( struct V_1 * V_2 , unsigned long V_1336 )
{
return F_466 ( V_2 ) == V_1336 ;
}
unsigned long F_443 ( struct V_1 * V_2 )
{
unsigned long V_961 ;
V_961 = V_73 -> V_991 ( V_2 ) ;
if ( V_2 -> V_178 & V_964 )
V_961 &= ~ V_963 ;
return V_961 ;
}
static void F_473 ( struct V_1 * V_2 , unsigned long V_961 )
{
if ( V_2 -> V_178 & V_964 &&
F_713 ( V_2 , V_2 -> V_5 . V_968 ) )
V_961 |= V_963 ;
V_73 -> V_1337 ( V_2 , V_961 ) ;
}
void F_449 ( struct V_1 * V_2 , unsigned long V_961 )
{
F_473 ( V_2 , V_961 ) ;
F_30 ( V_67 , V_2 ) ;
}
void F_714 ( struct V_1 * V_2 , struct V_1338 * V_358 )
{
int V_120 ;
if ( ( V_2 -> V_5 . V_84 . V_953 != V_358 -> V_5 . V_953 ) ||
V_358 -> V_1339 )
return;
V_120 = F_571 ( V_2 ) ;
if ( F_168 ( V_120 ) )
return;
if ( ! V_2 -> V_5 . V_84 . V_953 &&
V_358 -> V_5 . V_104 != V_2 -> V_5 . V_84 . V_1340 ( V_2 ) )
return;
V_2 -> V_5 . V_84 . V_1341 ( V_2 , V_358 -> V_821 , 0 , true ) ;
}
static inline T_1 F_715 ( T_5 V_102 )
{
return F_716 ( V_102 & 0xffffffff , F_717 ( V_4 ) ) ;
}
static inline T_1 F_718 ( T_1 V_1342 )
{
return ( V_1342 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_719 ( struct V_1 * V_2 , T_5 V_102 )
{
T_1 V_1342 = F_715 ( V_102 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1342 ] != ~ 0 )
V_1342 = F_718 ( V_1342 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1342 ] = V_102 ;
}
static T_1 F_720 ( struct V_1 * V_2 , T_5 V_102 )
{
int V_3 ;
T_1 V_1342 = F_715 ( V_102 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1342 ] != V_102 &&
V_2 -> V_5 . V_6 . V_7 [ V_1342 ] != ~ 0 ) ; V_3 ++ )
V_1342 = F_718 ( V_1342 ) ;
return V_1342 ;
}
bool F_721 ( struct V_1 * V_2 , T_5 V_102 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_720 ( V_2 , V_102 ) ] == V_102 ;
}
static void F_722 ( struct V_1 * V_2 , T_5 V_102 )
{
T_1 V_3 , V_805 , V_1343 ;
V_3 = V_805 = F_720 ( V_2 , V_102 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_805 = F_718 ( V_805 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_805 ] == ~ 0 )
return;
V_1343 = F_715 ( V_2 -> V_5 . V_6 . V_7 [ V_805 ] ) ;
} while ( ( V_3 <= V_805 ) ? ( V_3 < V_1343 && V_1343 <= V_805 ) : ( V_3 < V_1343 || V_1343 <= V_805 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_805 ] ;
V_3 = V_805 ;
}
}
static int F_723 ( struct V_1 * V_2 , T_1 V_195 )
{
return F_186 ( V_2 -> V_138 , & V_2 -> V_5 . V_6 . V_38 , & V_195 ,
sizeof( V_195 ) ) ;
}
void F_724 ( struct V_1 * V_2 ,
struct V_1338 * V_358 )
{
struct V_75 V_76 ;
F_725 ( V_358 -> V_5 . V_1344 , V_358 -> V_821 ) ;
F_719 ( V_2 , V_358 -> V_5 . V_102 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_390 & V_391 ) ||
( V_2 -> V_5 . V_6 . V_392 &&
V_73 -> V_88 ( V_2 ) == 0 ) )
F_30 ( V_1113 , V_2 ) ;
else if ( ! F_723 ( V_2 , V_1345 ) ) {
V_76 . V_41 = V_42 ;
V_76 . V_923 = true ;
V_76 . V_62 = 0 ;
V_76 . V_81 = false ;
V_76 . V_80 = V_358 -> V_5 . V_1344 ;
F_36 ( V_2 , & V_76 ) ;
}
}
void F_726 ( struct V_1 * V_2 ,
struct V_1338 * V_358 )
{
struct V_75 V_76 ;
F_727 ( V_358 -> V_5 . V_1344 , V_358 -> V_821 ) ;
if ( V_358 -> V_1339 )
V_358 -> V_5 . V_1344 = ~ 0 ;
else
F_722 ( V_2 , V_358 -> V_5 . V_102 ) ;
if ( ( V_2 -> V_5 . V_6 . V_390 & V_391 ) &&
! F_723 ( V_2 , V_1346 ) ) {
V_76 . V_41 = V_42 ;
V_76 . V_923 = true ;
V_76 . V_62 = 0 ;
V_76 . V_81 = false ;
V_76 . V_80 = V_358 -> V_5 . V_1344 ;
F_36 ( V_2 , & V_76 ) ;
}
V_2 -> V_5 . V_6 . V_1114 = false ;
V_2 -> V_5 . V_1040 = V_1154 ;
}
bool F_728 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_390 & V_391 ) )
return true ;
else
return ! F_259 ( V_2 ) &&
V_73 -> V_1081 ( V_2 ) ;
}
void F_729 ( struct V_138 * V_138 )
{
F_41 ( & V_138 -> V_5 . V_1347 ) ;
}
void F_730 ( struct V_138 * V_138 )
{
F_731 ( & V_138 -> V_5 . V_1347 ) ;
}
bool F_732 ( struct V_138 * V_138 )
{
return F_143 ( & V_138 -> V_5 . V_1347 ) ;
}
void F_733 ( struct V_138 * V_138 )
{
F_41 ( & V_138 -> V_5 . V_1287 ) ;
}
void F_734 ( struct V_138 * V_138 )
{
F_731 ( & V_138 -> V_5 . V_1287 ) ;
}
bool F_66 ( struct V_138 * V_138 )
{
return F_143 ( & V_138 -> V_5 . V_1287 ) ;
}
int F_735 ( struct V_1348 * V_1349 ,
struct V_1350 * V_1351 )
{
struct V_1352 * V_1353 =
F_4 ( V_1349 , struct V_1352 , V_1354 ) ;
if ( V_73 -> V_1355 ) {
V_1353 -> V_1356 = V_1351 ;
return V_73 -> V_1355 ( V_1353 -> V_138 ,
V_1351 -> V_595 , V_1353 -> V_1357 , 1 ) ;
}
return - V_578 ;
}
void F_736 ( struct V_1348 * V_1349 ,
struct V_1350 * V_1351 )
{
int V_108 ;
struct V_1352 * V_1353 =
F_4 ( V_1349 , struct V_1352 , V_1354 ) ;
if ( ! V_73 -> V_1355 ) {
F_28 ( V_1353 -> V_1356 != NULL ) ;
return;
}
F_28 ( V_1353 -> V_1356 != V_1351 ) ;
V_1353 -> V_1356 = NULL ;
V_108 = V_73 -> V_1355 ( V_1353 -> V_138 , V_1351 -> V_595 , V_1353 -> V_1357 , 0 ) ;
if ( V_108 )
F_10 ( V_1358 L_30
L_31 , V_1353 -> V_1354 . V_1344 , V_108 ) ;
}
int F_737 ( struct V_138 * V_138 , unsigned int V_1359 ,
T_7 V_1360 , bool V_1361 )
{
if ( ! V_73 -> V_1355 )
return - V_578 ;
return V_73 -> V_1355 ( V_138 , V_1359 , V_1360 , V_1361 ) ;
}
bool F_738 ( void )
{
return V_1362 ;
}
