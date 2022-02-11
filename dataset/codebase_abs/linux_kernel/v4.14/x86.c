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
T_2 V_40 = ( ( ~ 0ULL ) << F_23 ( V_2 ) ) | 0x2ff |
( F_24 ( V_2 , V_41 ) ? 0 : V_37 ) ;
if ( ( V_34 -> V_39 & V_40 ) || V_38 == V_37 )
return 1 ;
if ( ! V_34 -> V_42 &&
( ( V_38 == V_36 &&
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
static int F_28 ( int V_43 )
{
switch ( V_43 ) {
case V_44 :
return V_45 ;
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
return V_51 ;
default:
break;
}
return V_52 ;
}
static int F_29 ( int V_43 )
{
unsigned int V_29 ;
if ( F_30 ( V_43 > 31 || V_43 == V_53 ) )
return V_54 ;
V_29 = 1 << V_43 ;
if ( V_29 & ( ( 1 << V_55 ) | ( 1 << V_56 ) | ( 1 << V_57 ) ) )
return V_58 ;
if ( V_29 & ( ( 1 << V_59 ) | ( 1 << V_60 ) ) )
return V_61 ;
return V_62 ;
}
static void F_31 ( struct V_1 * V_2 ,
unsigned V_18 , bool V_63 , T_1 V_64 ,
bool V_65 )
{
T_1 V_66 ;
int V_67 , V_68 ;
F_32 ( V_69 , V_2 ) ;
if ( ! V_2 -> V_5 . V_70 . V_71 && ! V_2 -> V_5 . V_70 . V_72 ) {
V_73:
if ( V_63 && ! F_33 ( V_2 ) )
V_63 = false ;
if ( V_65 ) {
F_34 ( V_2 -> V_5 . V_70 . V_71 ) ;
V_2 -> V_5 . V_70 . V_72 = true ;
} else {
V_2 -> V_5 . V_70 . V_71 = true ;
V_2 -> V_5 . V_70 . V_72 = false ;
}
V_2 -> V_5 . V_70 . V_74 = V_63 ;
V_2 -> V_5 . V_70 . V_18 = V_18 ;
V_2 -> V_5 . V_70 . V_64 = V_64 ;
return;
}
V_66 = V_2 -> V_5 . V_70 . V_18 ;
if ( V_66 == V_59 ) {
F_32 ( V_75 , V_2 ) ;
return;
}
V_67 = F_28 ( V_66 ) ;
V_68 = F_28 ( V_18 ) ;
if ( ( V_67 == V_51 && V_68 == V_51 )
|| ( V_67 == V_45 && V_68 != V_52 ) ) {
V_2 -> V_5 . V_70 . V_71 = true ;
V_2 -> V_5 . V_70 . V_72 = false ;
V_2 -> V_5 . V_70 . V_74 = true ;
V_2 -> V_5 . V_70 . V_18 = V_59 ;
V_2 -> V_5 . V_70 . V_64 = 0 ;
} else
goto V_73;
}
void F_35 ( struct V_1 * V_2 , unsigned V_18 )
{
F_31 ( V_2 , V_18 , false , 0 , false ) ;
}
void F_36 ( struct V_1 * V_2 , unsigned V_18 )
{
F_31 ( V_2 , V_18 , false , 0 , true ) ;
}
int F_37 ( struct V_1 * V_2 , int V_30 )
{
if ( V_30 )
F_38 ( V_2 , 0 ) ;
else
return F_39 ( V_2 ) ;
return 1 ;
}
void F_40 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
++ V_2 -> V_78 . V_79 ;
V_2 -> V_5 . V_70 . V_80 =
F_41 ( V_2 ) && V_77 -> V_81 ;
if ( V_2 -> V_5 . V_70 . V_80 )
V_2 -> V_5 . V_6 . V_82 = V_77 -> V_83 ;
else
V_2 -> V_5 . V_84 = V_77 -> V_83 ;
F_42 ( V_2 , V_44 , V_77 -> V_64 ) ;
}
static bool F_43 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
if ( F_44 ( V_2 ) && ! V_77 -> V_85 )
V_2 -> V_5 . V_86 . V_87 ( V_2 , V_77 ) ;
else
V_2 -> V_5 . V_88 . V_87 ( V_2 , V_77 ) ;
return V_77 -> V_85 ;
}
void F_45 ( struct V_1 * V_2 )
{
F_46 ( & V_2 -> V_5 . V_89 ) ;
F_32 ( V_90 , V_2 ) ;
}
void F_42 ( struct V_1 * V_2 , unsigned V_18 , T_1 V_64 )
{
F_31 ( V_2 , V_18 , true , V_64 , false ) ;
}
void F_47 ( struct V_1 * V_2 , unsigned V_18 , T_1 V_64 )
{
F_31 ( V_2 , V_18 , true , V_64 , true ) ;
}
bool F_48 ( struct V_1 * V_2 , int V_91 )
{
if ( V_92 -> V_93 ( V_2 ) <= V_91 )
return true ;
F_42 ( V_2 , V_50 , 0 ) ;
return false ;
}
bool F_49 ( struct V_1 * V_2 , int V_94 )
{
if ( ( V_94 != 4 && V_94 != 5 ) || ! F_50 ( V_2 , V_95 ) )
return true ;
F_35 ( V_2 , V_96 ) ;
return false ;
}
int F_51 ( struct V_1 * V_2 , struct V_97 * V_88 ,
T_5 V_98 , void * V_39 , int V_99 , int V_100 ,
T_1 V_101 )
{
struct V_76 V_70 ;
T_5 V_102 ;
T_6 V_103 ;
V_103 = F_52 ( V_98 ) ;
V_102 = V_88 -> V_104 ( V_2 , V_103 , V_101 , & V_70 ) ;
if ( V_102 == V_105 )
return - V_106 ;
V_102 = F_53 ( V_102 ) ;
return F_54 ( V_2 , V_102 , V_39 , V_99 , V_100 ) ;
}
static int F_55 ( struct V_1 * V_2 , T_5 V_107 ,
void * V_39 , int V_99 , int V_100 , T_1 V_101 )
{
return F_51 ( V_2 , V_2 -> V_5 . V_108 , V_107 ,
V_39 , V_99 , V_100 , V_101 ) ;
}
int F_56 ( struct V_1 * V_2 , struct V_97 * V_88 , unsigned long V_109 )
{
T_5 V_110 = V_109 >> V_111 ;
unsigned V_99 = ( ( V_109 & ( V_112 - 1 ) ) >> 5 ) << 2 ;
int V_3 ;
int V_113 ;
T_2 V_114 [ F_57 ( V_88 -> V_115 ) ] ;
V_113 = F_51 ( V_2 , V_88 , V_110 , V_114 ,
V_99 * sizeof( T_2 ) , sizeof( V_114 ) ,
V_116 | V_117 ) ;
if ( V_113 < 0 ) {
V_113 = 0 ;
goto V_118;
}
for ( V_3 = 0 ; V_3 < F_57 ( V_114 ) ; ++ V_3 ) {
if ( ( V_114 [ V_3 ] & V_119 ) &&
( V_114 [ V_3 ] &
V_2 -> V_5 . V_88 . V_120 . V_121 [ 0 ] [ 2 ] ) ) {
V_113 = 0 ;
goto V_118;
}
}
V_113 = 1 ;
memcpy ( V_88 -> V_115 , V_114 , sizeof( V_88 -> V_115 ) ) ;
F_58 ( V_122 ,
( unsigned long * ) & V_2 -> V_5 . V_123 ) ;
F_58 ( V_122 ,
( unsigned long * ) & V_2 -> V_5 . V_124 ) ;
V_118:
return V_113 ;
}
bool F_59 ( struct V_1 * V_2 )
{
T_2 V_114 [ F_57 ( V_2 -> V_5 . V_108 -> V_115 ) ] ;
bool V_125 = true ;
int V_99 ;
T_5 V_107 ;
int V_126 ;
if ( F_60 ( V_2 ) || ! F_61 ( V_2 ) )
return false ;
if ( ! F_62 ( V_122 ,
( unsigned long * ) & V_2 -> V_5 . V_123 ) )
return true ;
V_107 = ( F_63 ( V_2 ) & 0xffffffe0ul ) >> V_111 ;
V_99 = ( F_63 ( V_2 ) & 0xffffffe0ul ) & ( V_112 - 1 ) ;
V_126 = F_55 ( V_2 , V_107 , V_114 , V_99 , sizeof( V_114 ) ,
V_116 | V_117 ) ;
if ( V_126 < 0 )
goto V_118;
V_125 = memcmp ( V_114 , V_2 -> V_5 . V_108 -> V_115 , sizeof( V_114 ) ) != 0 ;
V_118:
return V_125 ;
}
int F_64 ( struct V_1 * V_2 , unsigned long V_127 )
{
unsigned long V_128 = F_65 ( V_2 ) ;
unsigned long V_129 = V_130 | V_131 ;
V_127 |= V_132 ;
#ifdef F_66
if ( V_127 & 0xffffffff00000000UL )
return 1 ;
#endif
V_127 &= ~ V_133 ;
if ( ( V_127 & V_134 ) && ! ( V_127 & V_135 ) )
return 1 ;
if ( ( V_127 & V_130 ) && ! ( V_127 & V_136 ) )
return 1 ;
if ( ! F_67 ( V_2 ) && ( V_127 & V_130 ) ) {
#ifdef F_66
if ( ( V_2 -> V_5 . V_137 & V_138 ) ) {
int V_139 , V_140 ;
if ( ! F_61 ( V_2 ) )
return 1 ;
V_92 -> V_141 ( V_2 , & V_139 , & V_140 ) ;
if ( V_140 )
return 1 ;
} else
#endif
if ( F_61 ( V_2 ) && ! F_56 ( V_2 , V_2 -> V_5 . V_108 ,
F_63 ( V_2 ) ) )
return 1 ;
}
if ( ! ( V_127 & V_130 ) && F_50 ( V_2 , V_142 ) )
return 1 ;
V_92 -> V_143 ( V_2 , V_127 ) ;
if ( ( V_127 ^ V_128 ) & V_130 ) {
F_68 ( V_2 ) ;
F_1 ( V_2 ) ;
}
if ( ( V_127 ^ V_128 ) & V_129 )
F_69 ( V_2 ) ;
if ( ( ( V_127 ^ V_128 ) & V_135 ) &&
F_70 ( V_2 -> V_144 ) &&
! F_71 ( V_2 -> V_144 , V_145 ) )
F_72 ( V_2 -> V_144 , 0 , ~ 0ULL ) ;
return 0 ;
}
void F_73 ( struct V_1 * V_2 , unsigned long V_146 )
{
( void ) F_64 ( V_2 , F_74 ( V_2 , ~ 0x0eul ) | ( V_146 & 0x0f ) ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
if ( F_50 ( V_2 , V_147 ) &&
! V_2 -> V_148 ) {
F_76 ( V_149 , V_2 -> V_5 . V_150 ) ;
V_2 -> V_148 = 1 ;
}
}
static void F_77 ( struct V_1 * V_2 )
{
if ( V_2 -> V_148 ) {
if ( V_2 -> V_5 . V_150 != V_151 )
F_76 ( V_149 , V_151 ) ;
V_2 -> V_148 = 0 ;
}
}
static int F_78 ( struct V_1 * V_2 , T_1 V_152 , T_2 V_153 )
{
T_2 V_150 = V_153 ;
T_2 V_154 = V_2 -> V_5 . V_150 ;
T_2 V_155 ;
if ( V_152 != V_149 )
return 1 ;
if ( ! ( V_150 & V_156 ) )
return 1 ;
if ( ( V_150 & V_157 ) && ! ( V_150 & V_158 ) )
return 1 ;
V_155 = V_2 -> V_5 . V_159 | V_156 ;
if ( V_150 & ~ V_155 )
return 1 ;
if ( ( ! ( V_150 & V_160 ) ) !=
( ! ( V_150 & V_161 ) ) )
return 1 ;
if ( V_150 & V_162 ) {
if ( ! ( V_150 & V_157 ) )
return 1 ;
if ( ( V_150 & V_162 ) != V_162 )
return 1 ;
}
V_2 -> V_5 . V_150 = V_150 ;
if ( ( V_150 ^ V_154 ) & V_163 )
F_79 ( V_2 ) ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 , T_1 V_152 , T_2 V_153 )
{
if ( V_92 -> V_93 ( V_2 ) != 0 ||
F_78 ( V_2 , V_152 , V_153 ) ) {
F_38 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_81 ( struct V_1 * V_2 , unsigned long V_164 )
{
unsigned long V_165 = F_82 ( V_2 ) ;
unsigned long V_166 = V_167 | V_168 | V_169 |
V_170 | V_171 | V_172 ;
if ( V_164 & V_173 )
return 1 ;
if ( ! F_24 ( V_2 , V_174 ) && ( V_164 & V_147 ) )
return 1 ;
if ( ! F_24 ( V_2 , V_175 ) && ( V_164 & V_170 ) )
return 1 ;
if ( ! F_24 ( V_2 , V_176 ) && ( V_164 & V_171 ) )
return 1 ;
if ( ! F_24 ( V_2 , V_177 ) && ( V_164 & V_178 ) )
return 1 ;
if ( ! F_24 ( V_2 , V_179 ) && ( V_164 & V_172 ) )
return 1 ;
if ( ! F_24 ( V_2 , V_180 ) && ( V_164 & V_181 ) )
return 1 ;
if ( F_60 ( V_2 ) ) {
if ( ! ( V_164 & V_169 ) )
return 1 ;
} else if ( F_67 ( V_2 ) && ( V_164 & V_169 )
&& ( ( V_164 ^ V_165 ) & V_166 )
&& ! F_56 ( V_2 , V_2 -> V_5 . V_108 ,
F_63 ( V_2 ) ) )
return 1 ;
if ( ( V_164 & V_142 ) && ! ( V_165 & V_142 ) ) {
if ( ! F_24 ( V_2 , V_182 ) )
return 1 ;
if ( ( F_63 ( V_2 ) & V_183 ) || ! F_60 ( V_2 ) )
return 1 ;
}
if ( V_92 -> V_184 ( V_2 , V_164 ) )
return 1 ;
if ( ( ( V_164 ^ V_165 ) & V_166 ) ||
( ! ( V_164 & V_142 ) && ( V_165 & V_142 ) ) )
F_69 ( V_2 ) ;
if ( ( V_164 ^ V_165 ) & ( V_147 | V_172 ) )
F_79 ( V_2 ) ;
return 0 ;
}
int F_83 ( struct V_1 * V_2 , unsigned long V_109 )
{
#ifdef F_66
V_109 &= ~ V_185 ;
#endif
if ( V_109 == F_63 ( V_2 ) && ! F_59 ( V_2 ) ) {
F_84 ( V_2 ) ;
F_32 ( V_186 , V_2 ) ;
return 0 ;
}
if ( F_60 ( V_2 ) &&
( V_109 & F_85 ( F_23 ( V_2 ) , 62 ) ) )
return 1 ;
else if ( F_61 ( V_2 ) && F_67 ( V_2 ) &&
! F_56 ( V_2 , V_2 -> V_5 . V_108 , V_109 ) )
return 1 ;
V_2 -> V_5 . V_109 = V_109 ;
F_58 ( V_187 , ( V_188 * ) & V_2 -> V_5 . V_123 ) ;
F_86 ( V_2 ) ;
return 0 ;
}
int F_87 ( struct V_1 * V_2 , unsigned long V_189 )
{
if ( V_189 & V_190 )
return 1 ;
if ( F_88 ( V_2 ) )
F_89 ( V_2 , V_189 ) ;
else
V_2 -> V_5 . V_189 = V_189 ;
return 0 ;
}
unsigned long F_90 ( struct V_1 * V_2 )
{
if ( F_88 ( V_2 ) )
return F_91 ( V_2 ) ;
else
return V_2 -> V_5 . V_189 ;
}
static void F_92 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! ( V_2 -> V_191 & V_192 ) ) {
for ( V_3 = 0 ; V_3 < V_193 ; V_3 ++ )
V_2 -> V_5 . V_194 [ V_3 ] = V_2 -> V_5 . V_195 [ V_3 ] ;
V_2 -> V_5 . V_196 |= V_197 ;
}
}
static void F_93 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_191 & V_192 ) )
V_92 -> V_198 ( V_2 , V_2 -> V_5 . V_199 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
unsigned long V_200 ;
if ( V_2 -> V_191 & V_192 )
V_200 = V_2 -> V_5 . V_201 ;
else
V_200 = V_2 -> V_5 . V_200 ;
V_92 -> V_202 ( V_2 , V_200 ) ;
V_2 -> V_5 . V_196 &= ~ V_203 ;
if ( V_200 & V_204 )
V_2 -> V_5 . V_196 |= V_203 ;
}
static T_2 F_95 ( struct V_1 * V_2 )
{
T_2 V_205 = V_206 ;
if ( ! F_24 ( V_2 , V_207 ) )
V_205 |= V_208 ;
return V_205 ;
}
static int F_96 ( struct V_1 * V_2 , int V_94 , unsigned long V_209 )
{
switch ( V_94 ) {
case 0 ... 3 :
V_2 -> V_5 . V_195 [ V_94 ] = V_209 ;
if ( ! ( V_2 -> V_191 & V_192 ) )
V_2 -> V_5 . V_194 [ V_94 ] = V_209 ;
break;
case 4 :
case 6 :
if ( V_209 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_199 = ( V_209 & V_210 ) | F_95 ( V_2 ) ;
F_93 ( V_2 ) ;
break;
case 5 :
default:
if ( V_209 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_200 = ( V_209 & V_211 ) | V_212 ;
F_94 ( V_2 ) ;
break;
}
return 0 ;
}
int F_97 ( struct V_1 * V_2 , int V_94 , unsigned long V_209 )
{
if ( F_96 ( V_2 , V_94 , V_209 ) ) {
F_38 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_98 ( struct V_1 * V_2 , int V_94 , unsigned long * V_209 )
{
switch ( V_94 ) {
case 0 ... 3 :
* V_209 = V_2 -> V_5 . V_195 [ V_94 ] ;
break;
case 4 :
case 6 :
if ( V_2 -> V_191 & V_192 )
* V_209 = V_2 -> V_5 . V_199 ;
else
* V_209 = V_92 -> V_213 ( V_2 ) ;
break;
case 5 :
default:
* V_209 = V_2 -> V_5 . V_200 ;
break;
}
return 0 ;
}
bool F_99 ( struct V_1 * V_2 )
{
T_1 V_214 = F_100 ( V_2 , V_215 ) ;
T_2 V_39 ;
int V_30 ;
V_30 = F_101 ( V_2 , V_214 , & V_39 ) ;
if ( V_30 )
return V_30 ;
F_102 ( V_2 , V_216 , ( T_1 ) V_39 ) ;
F_102 ( V_2 , V_217 , V_39 >> 32 ) ;
return V_30 ;
}
bool F_103 ( struct V_1 * V_2 , T_2 V_137 )
{
if ( V_137 & V_218 )
return false ;
if ( V_137 & V_219 && ! F_24 ( V_2 , V_220 ) )
return false ;
if ( V_137 & V_221 && ! F_24 ( V_2 , V_222 ) )
return false ;
return true ;
}
static int F_104 ( struct V_1 * V_2 , T_2 V_137 )
{
T_2 V_223 = V_2 -> V_5 . V_137 ;
if ( ! F_103 ( V_2 , V_137 ) )
return 1 ;
if ( F_67 ( V_2 )
&& ( V_2 -> V_5 . V_137 & V_138 ) != ( V_137 & V_138 ) )
return 1 ;
V_137 &= ~ V_224 ;
V_137 |= V_2 -> V_5 . V_137 & V_224 ;
V_92 -> F_104 ( V_2 , V_137 ) ;
if ( ( V_137 ^ V_223 ) & V_225 )
F_69 ( V_2 ) ;
return 0 ;
}
void F_105 ( T_2 V_29 )
{
V_218 &= ~ V_29 ;
}
int F_106 ( struct V_1 * V_2 , struct V_33 * V_22 )
{
switch ( V_22 -> V_152 ) {
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case V_230 :
if ( F_107 ( V_22 -> V_39 , V_2 ) )
return 1 ;
break;
case V_231 :
case V_232 :
V_22 -> V_39 = F_108 ( V_22 -> V_39 , F_109 ( V_2 ) ) ;
}
return V_92 -> V_233 ( V_2 , V_22 ) ;
}
static int F_110 ( struct V_1 * V_2 , unsigned V_152 , T_2 * V_39 )
{
struct V_33 V_22 ;
int V_126 ;
V_22 . V_152 = V_152 ;
V_22 . V_42 = true ;
V_126 = F_111 ( V_2 , & V_22 ) ;
if ( V_126 )
return V_126 ;
* V_39 = V_22 . V_39 ;
return 0 ;
}
static int F_112 ( struct V_1 * V_2 , unsigned V_152 , T_2 * V_39 )
{
struct V_33 V_22 ;
V_22 . V_39 = * V_39 ;
V_22 . V_152 = V_152 ;
V_22 . V_42 = true ;
return F_106 ( V_2 , & V_22 ) ;
}
static void F_113 ( struct V_234 * V_235 )
{
struct V_236 * V_237 = & V_236 ;
T_2 V_238 ;
V_238 = F_114 ( F_115 ( V_235 -> V_239 . V_240 , V_235 -> V_241 ) ) ;
F_116 ( & V_237 -> V_242 ) ;
V_237 -> clock . V_243 = V_235 -> V_239 . clock -> V_244 . V_243 ;
V_237 -> clock . V_245 = V_235 -> V_239 . V_245 ;
V_237 -> clock . V_29 = V_235 -> V_239 . V_29 ;
V_237 -> clock . V_246 = V_235 -> V_239 . V_246 ;
V_237 -> clock . V_247 = V_235 -> V_239 . V_247 ;
V_237 -> V_238 = V_238 ;
V_237 -> V_248 = V_235 -> V_239 . V_249 ;
V_237 -> V_250 = V_235 -> V_251 ;
F_117 ( & V_237 -> V_242 ) ;
}
void F_118 ( struct V_1 * V_2 )
{
F_32 ( V_252 , V_2 ) ;
}
static void F_119 ( struct V_144 * V_144 , T_6 V_253 )
{
int V_254 ;
int V_126 ;
struct V_255 V_256 ;
struct V_257 V_258 ;
if ( ! V_253 )
return;
V_126 = F_120 ( V_144 , V_253 , & V_254 , sizeof( V_254 ) ) ;
if ( V_126 )
return;
if ( V_254 & 1 )
++ V_254 ;
++ V_254 ;
if ( F_121 ( V_144 , V_253 , & V_254 , sizeof( V_254 ) ) )
return;
F_122 ( & V_258 ) ;
if ( V_144 -> V_5 . V_259 ) {
struct V_257 V_260 = F_123 ( V_144 -> V_5 . V_259 ) ;
V_258 = F_124 ( V_258 , V_260 ) ;
}
V_256 . V_261 = ( T_1 ) V_258 . V_262 ;
V_256 . V_263 = V_258 . V_264 ;
V_256 . V_254 = V_254 ;
F_121 ( V_144 , V_253 , & V_256 , sizeof( V_256 ) ) ;
V_254 ++ ;
F_121 ( V_144 , V_253 , & V_254 , sizeof( V_254 ) ) ;
}
static T_7 F_125 ( T_7 V_265 , T_7 V_266 )
{
F_126 ( V_265 , V_266 ) ;
return V_265 ;
}
static void F_127 ( T_8 V_267 , T_8 V_268 ,
T_9 * V_269 , T_1 * V_270 )
{
T_8 V_271 ;
T_10 V_247 = 0 ;
T_8 V_272 ;
T_7 V_273 ;
V_272 = V_268 ;
V_271 = V_267 ;
while ( V_272 > V_271 * 2 || V_272 & 0xffffffff00000000ULL ) {
V_272 >>= 1 ;
V_247 -- ;
}
V_273 = ( T_7 ) V_272 ;
while ( V_273 <= V_271 || V_271 & 0xffffffff00000000ULL ) {
if ( V_271 & 0xffffffff00000000ULL || V_273 & 0x80000000 )
V_271 >>= 1 ;
else
V_273 <<= 1 ;
V_247 ++ ;
}
* V_269 = V_247 ;
* V_270 = F_125 ( V_271 , V_273 ) ;
F_128 ( L_2 ,
V_274 , V_268 , V_267 , V_247 , * V_270 ) ;
}
static T_1 F_129 ( T_1 V_275 , T_11 V_276 )
{
T_2 V_277 = ( T_2 ) V_275 * ( 1000000 + V_276 ) ;
F_130 ( V_277 , 1000000 ) ;
return V_277 ;
}
static int F_131 ( struct V_1 * V_2 , T_1 V_278 , bool V_279 )
{
T_2 V_280 ;
if ( ! V_279 ) {
V_2 -> V_5 . V_281 = V_282 ;
return 0 ;
}
if ( ! V_283 ) {
if ( V_278 > V_284 ) {
V_2 -> V_5 . V_285 = 1 ;
V_2 -> V_5 . V_286 = 1 ;
return 0 ;
} else {
F_132 ( 1 , L_3 ) ;
return - 1 ;
}
}
V_280 = F_133 ( 1ULL << V_287 ,
V_278 , V_284 ) ;
if ( V_280 == 0 || V_280 >= V_288 ) {
F_134 ( 1 , L_4 ,
V_278 ) ;
return - 1 ;
}
V_2 -> V_5 . V_281 = V_280 ;
return 0 ;
}
static int F_135 ( struct V_1 * V_2 , T_1 V_278 )
{
T_1 V_289 , V_290 ;
int V_291 = 0 ;
if ( V_278 == 0 ) {
V_2 -> V_5 . V_281 = V_282 ;
return - 1 ;
}
F_127 ( V_278 * 1000LL , V_292 ,
& V_2 -> V_5 . V_293 ,
& V_2 -> V_5 . V_294 ) ;
V_2 -> V_5 . V_295 = V_278 ;
V_289 = F_129 ( V_284 , - V_296 ) ;
V_290 = F_129 ( V_284 , V_296 ) ;
if ( V_278 < V_289 || V_278 > V_290 ) {
F_128 ( L_5 , V_278 , V_289 , V_290 ) ;
V_291 = 1 ;
}
return F_131 ( V_2 , V_278 , V_291 ) ;
}
static T_2 F_136 ( struct V_1 * V_2 , T_12 V_297 )
{
T_2 V_298 = F_137 ( V_297 - V_2 -> V_5 . V_299 ,
V_2 -> V_5 . V_294 ,
V_2 -> V_5 . V_293 ) ;
V_298 += V_2 -> V_5 . V_300 ;
return V_298 ;
}
static void F_138 ( struct V_1 * V_2 )
{
#ifdef F_66
bool V_301 ;
struct V_302 * V_303 = & V_2 -> V_144 -> V_5 ;
struct V_236 * V_304 = & V_236 ;
V_301 = ( V_303 -> V_305 + 1 ==
F_139 ( & V_2 -> V_144 -> V_306 ) ) ;
if ( V_303 -> V_307 ||
( V_304 -> clock . V_243 == V_308 && V_301 ) )
F_32 ( V_309 , V_2 ) ;
F_140 ( V_2 -> V_310 , V_303 -> V_305 ,
F_139 ( & V_2 -> V_144 -> V_306 ) ,
V_303 -> V_307 , V_304 -> clock . V_243 ) ;
#endif
}
static void F_141 ( struct V_1 * V_2 , T_12 V_99 )
{
T_2 V_311 = V_2 -> V_5 . V_312 ;
V_2 -> V_5 . V_313 += V_99 - V_311 ;
}
static inline T_2 F_142 ( T_2 V_280 , T_2 V_298 )
{
return F_143 ( V_298 , V_280 , V_287 ) ;
}
T_2 F_144 ( struct V_1 * V_2 , T_2 V_298 )
{
T_2 V_314 = V_298 ;
T_2 V_280 = V_2 -> V_5 . V_281 ;
if ( V_280 != V_282 )
V_314 = F_142 ( V_280 , V_298 ) ;
return V_314 ;
}
static T_2 F_145 ( struct V_1 * V_2 , T_2 V_315 )
{
T_2 V_298 ;
V_298 = F_144 ( V_2 , F_146 () ) ;
return V_315 - V_298 ;
}
T_2 F_147 ( struct V_1 * V_2 , T_2 V_316 )
{
return V_2 -> V_5 . V_312 + F_144 ( V_2 , V_316 ) ;
}
static void F_148 ( struct V_1 * V_2 , T_2 V_99 )
{
V_92 -> V_317 ( V_2 , V_99 ) ;
V_2 -> V_5 . V_312 = V_99 ;
}
void F_149 ( struct V_1 * V_2 , struct V_33 * V_22 )
{
struct V_144 * V_144 = V_2 -> V_144 ;
T_2 V_99 , V_318 , V_319 ;
unsigned long V_15 ;
bool V_320 ;
bool V_321 ;
T_2 V_39 = V_22 -> V_39 ;
bool V_322 = false ;
F_150 ( & V_144 -> V_5 . V_323 , V_15 ) ;
V_99 = F_145 ( V_2 , V_39 ) ;
V_318 = F_151 () ;
V_319 = V_318 - V_144 -> V_5 . V_324 ;
if ( V_2 -> V_5 . V_295 ) {
if ( V_39 == 0 && V_22 -> V_42 ) {
V_322 = true ;
} else {
T_2 V_325 = V_144 -> V_5 . V_326 +
F_152 ( V_2 , V_319 ) ;
T_2 V_327 = V_2 -> V_5 . V_295 * 1000LL ;
V_322 = V_39 < V_325 + V_327 &&
V_39 + V_327 > V_325 ;
}
}
if ( V_322 &&
V_2 -> V_5 . V_295 == V_144 -> V_5 . V_328 ) {
if ( ! F_153 () ) {
V_99 = V_144 -> V_5 . V_329 ;
F_128 ( L_6 , V_39 ) ;
} else {
T_2 V_330 = F_152 ( V_2 , V_319 ) ;
V_39 += V_330 ;
V_99 = F_145 ( V_2 , V_39 ) ;
F_128 ( L_7 , V_330 ) ;
}
V_320 = true ;
V_321 = ( V_2 -> V_5 . V_331 == V_144 -> V_5 . V_332 ) ;
} else {
V_144 -> V_5 . V_332 ++ ;
V_144 -> V_5 . V_333 = V_318 ;
V_144 -> V_5 . V_334 = V_39 ;
V_144 -> V_5 . V_329 = V_99 ;
V_320 = false ;
F_128 ( L_8 ,
V_144 -> V_5 . V_332 , V_39 ) ;
}
V_144 -> V_5 . V_324 = V_318 ;
V_144 -> V_5 . V_326 = V_39 ;
V_144 -> V_5 . V_328 = V_2 -> V_5 . V_295 ;
V_2 -> V_5 . V_335 = V_39 ;
V_2 -> V_5 . V_331 = V_144 -> V_5 . V_332 ;
V_2 -> V_5 . V_299 = V_144 -> V_5 . V_333 ;
V_2 -> V_5 . V_300 = V_144 -> V_5 . V_334 ;
if ( ! V_22 -> V_42 && F_24 ( V_2 , V_336 ) )
F_141 ( V_2 , V_99 ) ;
F_148 ( V_2 , V_99 ) ;
F_154 ( & V_144 -> V_5 . V_323 , V_15 ) ;
F_155 ( & V_144 -> V_5 . V_337 ) ;
if ( ! V_320 ) {
V_144 -> V_5 . V_305 = 0 ;
} else if ( ! V_321 ) {
V_144 -> V_5 . V_305 ++ ;
}
F_138 ( V_2 ) ;
F_156 ( & V_144 -> V_5 . V_337 ) ;
}
static inline void F_157 ( struct V_1 * V_2 ,
T_12 V_338 )
{
F_148 ( V_2 , V_2 -> V_5 . V_312 + V_338 ) ;
}
static inline void F_158 ( struct V_1 * V_2 , T_12 V_338 )
{
if ( V_2 -> V_5 . V_281 != V_282 )
F_30 ( V_338 < 0 ) ;
V_338 = F_144 ( V_2 , ( T_2 ) V_338 ) ;
F_157 ( V_2 , V_338 ) ;
}
static T_2 F_159 ( void )
{
T_2 V_113 = ( T_2 ) F_160 () ;
T_2 V_339 = V_236 . clock . V_245 ;
if ( F_161 ( V_113 >= V_339 ) )
return V_113 ;
asm volatile ("");
return V_339 ;
}
static inline T_2 F_162 ( T_2 * V_340 )
{
long V_277 ;
struct V_236 * V_304 = & V_236 ;
* V_340 = F_159 () ;
V_277 = ( * V_340 - V_304 -> clock . V_245 ) & V_304 -> clock . V_29 ;
return V_277 * V_304 -> clock . V_246 ;
}
static int F_163 ( T_12 * V_341 , T_2 * V_340 )
{
struct V_236 * V_304 = & V_236 ;
unsigned long V_242 ;
int V_342 ;
T_2 V_318 ;
do {
V_242 = F_164 ( & V_304 -> V_242 ) ;
V_342 = V_304 -> clock . V_243 ;
V_318 = V_304 -> V_248 ;
V_318 += F_162 ( V_340 ) ;
V_318 >>= V_304 -> clock . V_247 ;
V_318 += V_304 -> V_238 ;
} while ( F_165 ( F_166 ( & V_304 -> V_242 , V_242 ) ) );
* V_341 = V_318 ;
return V_342 ;
}
static int F_167 ( struct V_343 * V_260 , T_2 * V_340 )
{
struct V_236 * V_304 = & V_236 ;
unsigned long V_242 ;
int V_342 ;
T_2 V_318 ;
do {
V_242 = F_164 ( & V_304 -> V_242 ) ;
V_342 = V_304 -> clock . V_243 ;
V_260 -> V_262 = V_304 -> V_250 ;
V_318 = V_304 -> V_248 ;
V_318 += F_162 ( V_340 ) ;
V_318 >>= V_304 -> clock . V_247 ;
} while ( F_165 ( F_166 ( & V_304 -> V_242 , V_242 ) ) );
V_260 -> V_262 += F_168 ( V_318 , V_292 , & V_318 ) ;
V_260 -> V_264 = V_318 ;
return V_342 ;
}
static bool F_169 ( T_12 * V_297 , T_2 * V_340 )
{
if ( V_236 . clock . V_243 != V_308 )
return false ;
return F_163 ( V_297 , V_340 ) == V_308 ;
}
static bool F_170 ( struct V_343 * V_260 ,
T_2 * V_340 )
{
if ( V_236 . clock . V_243 != V_308 )
return false ;
return F_167 ( V_260 , V_340 ) == V_308 ;
}
static void F_171 ( struct V_144 * V_144 )
{
#ifdef F_66
struct V_302 * V_303 = & V_144 -> V_5 ;
int V_243 ;
bool V_344 , V_301 ;
V_301 = ( V_303 -> V_305 + 1 ==
F_139 ( & V_144 -> V_306 ) ) ;
V_344 = F_169 (
& V_303 -> V_345 ,
& V_303 -> V_346 ) ;
V_303 -> V_307 = V_344 && V_301
&& ! V_303 -> V_347
&& ! V_303 -> V_348 ;
if ( V_303 -> V_307 )
F_172 ( & V_349 , 1 ) ;
V_243 = V_236 . clock . V_243 ;
F_173 ( V_303 -> V_307 , V_243 ,
V_301 ) ;
#endif
}
void F_174 ( struct V_144 * V_144 )
{
F_175 ( V_144 , V_350 ) ;
}
static void F_176 ( struct V_144 * V_144 )
{
#ifdef F_66
int V_3 ;
struct V_1 * V_2 ;
struct V_302 * V_303 = & V_144 -> V_5 ;
F_155 ( & V_303 -> V_337 ) ;
F_174 ( V_144 ) ;
F_171 ( V_144 ) ;
F_177 (i, vcpu, kvm)
F_32 ( V_351 , V_2 ) ;
F_177 (i, vcpu, kvm)
F_178 ( V_350 , V_2 ) ;
F_156 ( & V_303 -> V_337 ) ;
#endif
}
T_2 F_179 ( struct V_144 * V_144 )
{
struct V_302 * V_303 = & V_144 -> V_5 ;
struct V_352 V_353 ;
T_2 V_113 ;
F_155 ( & V_303 -> V_337 ) ;
if ( ! V_303 -> V_307 ) {
F_156 ( & V_303 -> V_337 ) ;
return F_151 () + V_303 -> V_259 ;
}
V_353 . V_354 = V_303 -> V_346 ;
V_353 . V_355 = V_303 -> V_345 + V_303 -> V_259 ;
F_156 ( & V_303 -> V_337 ) ;
F_180 () ;
F_127 ( V_292 , F_181 ( V_356 ) * 1000LL ,
& V_353 . V_357 ,
& V_353 . V_358 ) ;
V_113 = F_182 ( & V_353 , F_146 () ) ;
F_183 () ;
return V_113 ;
}
static void F_184 ( struct V_1 * V_277 )
{
struct V_359 * V_2 = & V_277 -> V_5 ;
struct V_352 V_360 ;
if ( F_165 ( F_185 ( V_277 -> V_144 , & V_2 -> V_361 ,
& V_360 , sizeof( V_360 ) ) ) )
return;
F_186 ( F_187 ( struct V_352 , V_254 ) != 0 ) ;
V_2 -> V_353 . V_254 = V_360 . V_254 + 1 ;
F_188 ( V_277 -> V_144 , & V_2 -> V_361 ,
& V_2 -> V_353 ,
sizeof( V_2 -> V_353 . V_254 ) ) ;
F_189 () ;
V_2 -> V_353 . V_15 |= ( V_360 . V_15 & V_362 ) ;
if ( V_2 -> V_363 ) {
V_2 -> V_353 . V_15 |= V_362 ;
V_2 -> V_363 = false ;
}
F_190 ( V_277 -> V_310 , & V_2 -> V_353 ) ;
F_188 ( V_277 -> V_144 , & V_2 -> V_361 ,
& V_2 -> V_353 ,
sizeof( V_2 -> V_353 ) ) ;
F_189 () ;
V_2 -> V_353 . V_254 ++ ;
F_188 ( V_277 -> V_144 , & V_2 -> V_361 ,
& V_2 -> V_353 ,
sizeof( V_2 -> V_353 . V_254 ) ) ;
}
static int F_191 ( struct V_1 * V_277 )
{
unsigned long V_15 , V_364 ;
struct V_359 * V_2 = & V_277 -> V_5 ;
struct V_302 * V_303 = & V_277 -> V_144 -> V_5 ;
T_12 V_297 ;
T_2 V_354 , V_316 ;
T_13 V_365 ;
bool V_307 ;
V_297 = 0 ;
V_316 = 0 ;
F_155 ( & V_303 -> V_337 ) ;
V_307 = V_303 -> V_307 ;
if ( V_307 ) {
V_316 = V_303 -> V_346 ;
V_297 = V_303 -> V_345 ;
}
F_156 ( & V_303 -> V_337 ) ;
F_5 ( V_15 ) ;
V_364 = F_181 ( V_356 ) ;
if ( F_165 ( V_364 == 0 ) ) {
F_7 ( V_15 ) ;
F_32 ( V_351 , V_277 ) ;
return 1 ;
}
if ( ! V_307 ) {
V_316 = F_146 () ;
V_297 = F_151 () ;
}
V_354 = F_147 ( V_277 , V_316 ) ;
if ( V_2 -> V_285 ) {
T_2 V_298 = F_136 ( V_277 , V_297 ) ;
if ( V_298 > V_354 ) {
F_157 ( V_277 , V_298 - V_354 ) ;
V_354 = V_298 ;
}
}
F_7 ( V_15 ) ;
if ( V_283 )
V_364 = F_144 ( V_277 , V_364 ) ;
if ( F_165 ( V_2 -> V_366 != V_364 ) ) {
F_127 ( V_292 , V_364 * 1000LL ,
& V_2 -> V_353 . V_357 ,
& V_2 -> V_353 . V_358 ) ;
V_2 -> V_366 = V_364 ;
}
V_2 -> V_353 . V_354 = V_354 ;
V_2 -> V_353 . V_355 = V_297 + V_277 -> V_144 -> V_5 . V_259 ;
V_2 -> V_335 = V_354 ;
V_365 = 0 ;
if ( V_307 )
V_365 |= V_367 ;
V_2 -> V_353 . V_15 = V_365 ;
if ( V_2 -> V_368 )
F_184 ( V_277 ) ;
if ( V_277 == F_192 ( V_277 -> V_144 , 0 ) )
F_193 ( V_277 -> V_144 , & V_2 -> V_353 ) ;
return 0 ;
}
static void F_194 ( struct V_369 * V_370 )
{
int V_3 ;
struct V_371 * V_372 = F_195 ( V_370 ) ;
struct V_302 * V_303 = F_4 ( V_372 , struct V_302 ,
V_373 ) ;
struct V_144 * V_144 = F_4 ( V_303 , struct V_144 , V_5 ) ;
struct V_1 * V_2 ;
F_177 (i, vcpu, kvm) {
F_32 ( V_351 , V_2 ) ;
F_196 ( V_2 ) ;
}
}
static void F_197 ( struct V_1 * V_277 )
{
struct V_144 * V_144 = V_277 -> V_144 ;
F_32 ( V_351 , V_277 ) ;
F_198 ( & V_144 -> V_5 . V_373 ,
V_374 ) ;
}
static void F_199 ( struct V_369 * V_370 )
{
struct V_371 * V_372 = F_195 ( V_370 ) ;
struct V_302 * V_303 = F_4 ( V_372 , struct V_302 ,
V_375 ) ;
struct V_144 * V_144 = F_4 ( V_303 , struct V_144 , V_5 ) ;
if ( ! V_376 )
return;
F_198 ( & V_144 -> V_5 . V_373 , 0 ) ;
F_198 ( & V_144 -> V_5 . V_375 ,
V_377 ) ;
}
static int F_200 ( struct V_1 * V_2 , T_1 V_22 , T_2 V_39 )
{
T_2 V_378 = V_2 -> V_5 . V_378 ;
unsigned V_379 = V_378 & 0xff ;
switch ( V_22 ) {
case V_380 :
V_2 -> V_5 . V_381 = V_39 ;
break;
case V_382 :
if ( ! ( V_378 & V_383 ) )
return 1 ;
if ( V_39 != 0 && V_39 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_384 = V_39 ;
break;
default:
if ( V_22 >= V_385 &&
V_22 < F_201 ( V_379 ) ) {
T_1 V_99 = V_22 - V_385 ;
if ( ( V_99 & 0x3 ) == 0 &&
V_39 != 0 && ( V_39 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_386 [ V_99 ] = V_39 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_202 ( struct V_1 * V_2 , T_2 V_39 )
{
struct V_144 * V_144 = V_2 -> V_144 ;
int V_387 = F_60 ( V_2 ) ;
T_13 * V_388 = V_387 ? ( T_13 * ) ( long ) V_144 -> V_5 . F_202 . V_389
: ( T_13 * ) ( long ) V_144 -> V_5 . F_202 . V_390 ;
T_13 V_391 = V_387 ? V_144 -> V_5 . F_202 . V_392
: V_144 -> V_5 . F_202 . V_393 ;
T_1 V_394 = V_39 & ~ V_395 ;
T_2 V_396 = V_39 & V_395 ;
T_13 * V_397 ;
int V_126 ;
V_126 = - V_398 ;
if ( V_394 >= V_391 )
goto V_118;
V_126 = - V_399 ;
V_397 = F_203 ( V_388 + ( V_394 * V_112 ) , V_112 ) ;
if ( F_204 ( V_397 ) ) {
V_126 = F_205 ( V_397 ) ;
goto V_118;
}
if ( F_206 ( V_2 , V_396 , V_397 , V_112 ) )
goto V_400;
V_126 = 0 ;
V_400:
F_207 ( V_397 ) ;
V_118:
return V_126 ;
}
static int F_208 ( struct V_1 * V_2 , T_2 V_39 )
{
T_6 V_401 = V_39 & ~ 0x3f ;
if ( V_39 & 0x38 )
return 1 ;
V_2 -> V_5 . V_6 . V_402 = V_39 ;
if ( ! ( V_39 & V_403 ) ) {
F_68 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_209 ( V_2 -> V_144 , & V_2 -> V_5 . V_6 . V_39 , V_401 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_404 = ! ( V_39 & V_405 ) ;
V_2 -> V_5 . V_6 . V_406 = V_39 & V_407 ;
F_210 ( V_2 ) ;
return 0 ;
}
static void F_211 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_368 = false ;
}
static void F_212 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_408 . V_402 & V_409 ) )
return;
if ( F_165 ( F_185 ( V_2 -> V_144 , & V_2 -> V_5 . V_408 . V_410 ,
& V_2 -> V_5 . V_408 . V_411 , sizeof( struct V_412 ) ) ) )
return;
V_2 -> V_5 . V_408 . V_411 . V_413 = 0 ;
if ( V_2 -> V_5 . V_408 . V_411 . V_254 & 1 )
V_2 -> V_5 . V_408 . V_411 . V_254 += 1 ;
V_2 -> V_5 . V_408 . V_411 . V_254 += 1 ;
F_188 ( V_2 -> V_144 , & V_2 -> V_5 . V_408 . V_410 ,
& V_2 -> V_5 . V_408 . V_411 , sizeof( struct V_412 ) ) ;
F_189 () ;
V_2 -> V_5 . V_408 . V_411 . V_411 += V_414 -> V_415 . V_416 -
V_2 -> V_5 . V_408 . V_417 ;
V_2 -> V_5 . V_408 . V_417 = V_414 -> V_415 . V_416 ;
F_188 ( V_2 -> V_144 , & V_2 -> V_5 . V_408 . V_410 ,
& V_2 -> V_5 . V_408 . V_411 , sizeof( struct V_412 ) ) ;
F_189 () ;
V_2 -> V_5 . V_408 . V_411 . V_254 += 1 ;
F_188 ( V_2 -> V_144 , & V_2 -> V_5 . V_408 . V_410 ,
& V_2 -> V_5 . V_408 . V_411 , sizeof( struct V_412 ) ) ;
}
int F_213 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
bool V_418 = false ;
T_1 V_22 = V_34 -> V_152 ;
T_2 V_39 = V_34 -> V_39 ;
switch ( V_22 ) {
case V_419 :
case V_420 :
case V_421 :
case V_422 :
case V_423 :
case V_424 :
case V_425 :
break;
case V_426 :
return F_104 ( V_2 , V_39 ) ;
case V_427 :
V_39 &= ~ ( T_2 ) 0x40 ;
V_39 &= ~ ( T_2 ) 0x100 ;
V_39 &= ~ ( T_2 ) 0x8 ;
V_39 &= ~ ( T_2 ) 0x40000 ;
if ( V_39 != 0 ) {
F_214 ( V_2 , L_9 ,
V_39 ) ;
return 1 ;
}
break;
case V_428 :
if ( V_39 != 0 ) {
F_214 ( V_2 , L_10
L_11 , V_39 ) ;
return 1 ;
}
break;
case V_429 :
if ( ! V_39 ) {
break;
} else if ( V_39 & ~ ( V_430 | V_431 ) ) {
return 1 ;
}
F_214 ( V_2 , L_12 ,
V_274 , V_39 ) ;
break;
case 0x200 ... 0x2ff :
return F_215 ( V_2 , V_22 , V_39 ) ;
case V_432 :
return F_22 ( V_2 , V_34 ) ;
case V_433 ... V_433 + 0x3ff :
return F_216 ( V_2 , V_22 , V_39 ) ;
case V_434 :
F_217 ( V_2 , V_39 ) ;
break;
case V_435 :
if ( F_24 ( V_2 , V_336 ) ) {
if ( ! V_34 -> V_42 ) {
T_12 V_436 = V_39 - V_2 -> V_5 . V_313 ;
F_157 ( V_2 , V_436 ) ;
}
V_2 -> V_5 . V_313 = V_39 ;
}
break;
case V_437 :
V_2 -> V_5 . V_438 = V_39 ;
break;
case V_439 :
if ( ! V_34 -> V_42 )
return 1 ;
V_2 -> V_5 . V_440 = V_39 ;
break;
case V_441 :
case V_442 :
V_2 -> V_144 -> V_5 . V_253 = V_39 ;
F_119 ( V_2 -> V_144 , V_39 ) ;
break;
case V_443 :
case V_444 : {
struct V_302 * V_303 = & V_2 -> V_144 -> V_5 ;
F_211 ( V_2 ) ;
if ( V_2 -> V_310 == 0 && ! V_34 -> V_42 ) {
bool V_445 = ( V_22 == V_444 ) ;
if ( V_303 -> V_348 != V_445 )
F_32 ( V_309 , V_2 ) ;
V_303 -> V_348 = V_445 ;
}
V_2 -> V_5 . time = V_39 ;
F_32 ( V_446 , V_2 ) ;
if ( ! ( V_39 & 1 ) )
break;
if ( F_209 ( V_2 -> V_144 ,
& V_2 -> V_5 . V_361 , V_39 & ~ 1ULL ,
sizeof( struct V_352 ) ) )
V_2 -> V_5 . V_368 = false ;
else
V_2 -> V_5 . V_368 = true ;
break;
}
case V_447 :
if ( F_208 ( V_2 , V_39 ) )
return 1 ;
break;
case V_448 :
if ( F_165 ( ! F_218 () ) )
return 1 ;
if ( V_39 & V_449 )
return 1 ;
if ( F_209 ( V_2 -> V_144 , & V_2 -> V_5 . V_408 . V_410 ,
V_39 & V_450 ,
sizeof( struct V_412 ) ) )
return 1 ;
V_2 -> V_5 . V_408 . V_402 = V_39 ;
if ( ! ( V_39 & V_409 ) )
break;
F_32 ( V_451 , V_2 ) ;
break;
case V_452 :
if ( F_219 ( V_2 , V_39 ) )
return 1 ;
break;
case V_382 :
case V_380 :
case V_385 ... F_201 ( V_453 ) - 1 :
return F_200 ( V_2 , V_22 , V_39 ) ;
case V_454 ... V_455 :
case V_456 ... V_457 :
V_418 = true ;
case V_458 ... V_459 :
case V_460 ... V_461 :
if ( F_220 ( V_2 , V_22 ) )
return F_221 ( V_2 , V_34 ) ;
if ( V_418 || V_39 != 0 )
F_214 ( V_2 , L_13
L_14 , V_22 , V_39 ) ;
break;
case V_462 :
break;
case V_463 ... V_464 :
case V_465 ... V_466 :
case V_467 :
case V_468 ... V_469 :
return F_222 ( V_2 , V_22 , V_39 ,
V_34 -> V_42 ) ;
case V_470 :
F_214 ( V_2 , L_15 , V_22 , V_39 ) ;
break;
case V_471 :
if ( ! F_24 ( V_2 , V_472 ) )
return 1 ;
V_2 -> V_5 . V_473 . V_474 = V_39 ;
break;
case V_475 :
if ( ! F_24 ( V_2 , V_472 ) )
return 1 ;
V_2 -> V_5 . V_473 . V_476 = V_39 ;
break;
case V_477 :
if ( ! V_34 -> V_42 ||
V_39 & ~ V_478 ||
( ! ( V_39 & V_478 ) &&
F_223 ( V_2 ) ) )
return 1 ;
V_2 -> V_5 . V_479 = V_39 ;
break;
case V_480 :
if ( V_39 & ~ V_481 ||
( V_39 & V_481 &&
! F_224 ( V_2 ) ) )
return 1 ;
V_2 -> V_5 . V_482 = V_39 ;
break;
default:
if ( V_22 && ( V_22 == V_2 -> V_144 -> V_5 . F_202 . V_22 ) )
return F_202 ( V_2 , V_39 ) ;
if ( F_220 ( V_2 , V_22 ) )
return F_221 ( V_2 , V_34 ) ;
if ( ! V_483 ) {
F_225 ( V_2 , L_16 ,
V_22 , V_39 ) ;
return 1 ;
} else {
F_214 ( V_2 , L_15 ,
V_22 , V_39 ) ;
break;
}
}
return 0 ;
}
int F_111 ( struct V_1 * V_2 , struct V_33 * V_22 )
{
return V_92 -> V_484 ( V_2 , V_22 ) ;
}
static int F_226 ( struct V_1 * V_2 , T_1 V_22 , T_2 * V_485 )
{
T_2 V_39 ;
T_2 V_378 = V_2 -> V_5 . V_378 ;
unsigned V_379 = V_378 & 0xff ;
switch ( V_22 ) {
case V_486 :
case V_487 :
V_39 = 0 ;
break;
case V_488 :
V_39 = V_2 -> V_5 . V_378 ;
break;
case V_382 :
if ( ! ( V_378 & V_383 ) )
return 1 ;
V_39 = V_2 -> V_5 . V_384 ;
break;
case V_380 :
V_39 = V_2 -> V_5 . V_381 ;
break;
default:
if ( V_22 >= V_385 &&
V_22 < F_201 ( V_379 ) ) {
T_1 V_99 = V_22 - V_385 ;
V_39 = V_2 -> V_5 . V_386 [ V_99 ] ;
break;
}
return 1 ;
}
* V_485 = V_39 ;
return 0 ;
}
int F_227 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
switch ( V_34 -> V_152 ) {
case V_489 :
case V_490 :
case V_429 :
case V_491 :
case V_492 :
case V_493 :
case V_494 :
case V_495 :
case V_496 :
case V_497 :
case V_427 :
case V_422 :
case V_498 :
case V_419 :
case V_428 :
case V_424 :
case V_499 :
case V_425 :
V_34 -> V_39 = 0 ;
break;
case V_458 ... V_459 :
case V_454 ... V_455 :
case V_456 ... V_457 :
case V_460 ... V_461 :
if ( F_220 ( V_2 , V_34 -> V_152 ) )
return F_228 ( V_2 , V_34 -> V_152 , & V_34 -> V_39 ) ;
V_34 -> V_39 = 0 ;
break;
case V_420 :
V_34 -> V_39 = 0x100000000ULL ;
break;
case V_500 :
case 0x200 ... 0x2ff :
return F_229 ( V_2 , V_34 -> V_152 , & V_34 -> V_39 ) ;
case 0xcd :
V_34 -> V_39 = 3 ;
break;
case V_501 :
V_34 -> V_39 = 1 << 24 ;
break;
case V_432 :
V_34 -> V_39 = F_21 ( V_2 ) ;
break;
case V_433 ... V_433 + 0x3ff :
return F_230 ( V_2 , V_34 -> V_152 , & V_34 -> V_39 ) ;
break;
case V_434 :
V_34 -> V_39 = F_231 ( V_2 ) ;
break;
case V_435 :
V_34 -> V_39 = ( T_2 ) V_2 -> V_5 . V_313 ;
break;
case V_437 :
V_34 -> V_39 = V_2 -> V_5 . V_438 ;
break;
case V_439 :
if ( ! V_34 -> V_42 )
return 1 ;
V_34 -> V_39 = V_2 -> V_5 . V_440 ;
break;
case V_502 :
V_34 -> V_39 = 1000ULL ;
V_34 -> V_39 |= ( ( ( T_8 ) 4ULL ) << 40 ) ;
break;
case V_426 :
V_34 -> V_39 = V_2 -> V_5 . V_137 ;
break;
case V_442 :
case V_441 :
V_34 -> V_39 = V_2 -> V_144 -> V_5 . V_253 ;
break;
case V_444 :
case V_443 :
V_34 -> V_39 = V_2 -> V_5 . time ;
break;
case V_447 :
V_34 -> V_39 = V_2 -> V_5 . V_6 . V_402 ;
break;
case V_448 :
V_34 -> V_39 = V_2 -> V_5 . V_408 . V_402 ;
break;
case V_452 :
V_34 -> V_39 = V_2 -> V_5 . V_503 . V_402 ;
break;
case V_486 :
case V_487 :
case V_488 :
case V_382 :
case V_380 :
case V_385 ... F_201 ( V_453 ) - 1 :
return F_226 ( V_2 , V_34 -> V_152 , & V_34 -> V_39 ) ;
case V_462 :
V_34 -> V_39 = 0x20000000 ;
break;
case V_463 ... V_464 :
case V_465 ... V_466 :
case V_467 :
case V_468 ... V_469 :
return F_232 ( V_2 ,
V_34 -> V_152 , & V_34 -> V_39 ) ;
break;
case V_470 :
V_34 -> V_39 = 0xbe702111 ;
break;
case V_471 :
if ( ! F_24 ( V_2 , V_472 ) )
return 1 ;
V_34 -> V_39 = V_2 -> V_5 . V_473 . V_474 ;
break;
case V_475 :
if ( ! F_24 ( V_2 , V_472 ) )
return 1 ;
V_34 -> V_39 = V_2 -> V_5 . V_473 . V_476 ;
break;
case V_477 :
V_34 -> V_39 = V_2 -> V_5 . V_479 ;
break;
case V_480 :
V_34 -> V_39 = V_2 -> V_5 . V_482 ;
break;
default:
if ( F_220 ( V_2 , V_34 -> V_152 ) )
return F_228 ( V_2 , V_34 -> V_152 , & V_34 -> V_39 ) ;
if ( ! V_483 ) {
F_225 ( V_2 , L_17 ,
V_34 -> V_152 ) ;
return 1 ;
} else {
F_214 ( V_2 , L_18 , V_34 -> V_152 ) ;
V_34 -> V_39 = 0 ;
}
break;
}
return 0 ;
}
static int F_233 ( struct V_1 * V_2 , struct V_504 * V_21 ,
struct V_505 * V_506 ,
int (* F_234)( struct V_1 * V_2 ,
unsigned V_152 , T_2 * V_39 ) )
{
int V_3 , V_507 ;
V_507 = F_235 ( & V_2 -> V_144 -> V_508 ) ;
for ( V_3 = 0 ; V_3 < V_21 -> V_509 ; ++ V_3 )
if ( F_234 ( V_2 , V_506 [ V_3 ] . V_152 , & V_506 [ V_3 ] . V_39 ) )
break;
F_236 ( & V_2 -> V_144 -> V_508 , V_507 ) ;
return V_3 ;
}
static int F_237 ( struct V_1 * V_2 , struct V_504 T_14 * V_510 ,
int (* F_234)( struct V_1 * V_2 ,
unsigned V_152 , T_2 * V_39 ) ,
int V_511 )
{
struct V_504 V_21 ;
struct V_505 * V_506 ;
int V_126 , V_512 ;
unsigned V_513 ;
V_126 = - V_106 ;
if ( F_238 ( & V_21 , V_510 , sizeof V_21 ) )
goto V_118;
V_126 = - V_398 ;
if ( V_21 . V_509 >= V_514 )
goto V_118;
V_513 = sizeof( struct V_505 ) * V_21 . V_509 ;
V_506 = F_203 ( V_510 -> V_506 , V_513 ) ;
if ( F_204 ( V_506 ) ) {
V_126 = F_205 ( V_506 ) ;
goto V_118;
}
V_126 = V_512 = F_233 ( V_2 , & V_21 , V_506 , F_234 ) ;
if ( V_126 < 0 )
goto V_400;
V_126 = - V_106 ;
if ( V_511 && F_239 ( V_510 -> V_506 , V_506 , V_513 ) )
goto V_400;
V_126 = V_512 ;
V_400:
F_207 ( V_506 ) ;
V_118:
return V_126 ;
}
int F_240 ( struct V_144 * V_144 , long V_515 )
{
int V_126 ;
switch ( V_515 ) {
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
V_126 = 1 ;
break;
case V_559 :
V_126 = V_560 ;
break;
case V_561 :
V_126 = F_241 () ;
break;
case V_562 :
V_126 = V_92 -> V_563 () ;
break;
case V_564 :
V_126 = ! V_92 -> V_565 () ;
break;
case V_566 :
V_126 = V_567 ;
break;
case V_568 :
V_126 = V_569 ;
break;
case V_570 :
V_126 = V_571 ;
break;
case V_572 :
V_126 = 0 ;
break;
case V_573 :
V_126 = V_453 ;
break;
case V_574 :
V_126 = F_242 ( V_174 ) ;
break;
case V_575 :
V_126 = V_283 ;
break;
case V_576 :
V_126 = V_577 ;
break;
default:
V_126 = 0 ;
break;
}
return V_126 ;
}
long F_243 ( struct V_578 * V_579 ,
unsigned int V_580 , unsigned long V_581 )
{
void T_14 * V_582 = ( void T_14 * ) V_581 ;
long V_126 ;
switch ( V_580 ) {
case V_583 : {
struct V_584 T_14 * V_585 = V_582 ;
struct V_584 V_586 ;
unsigned V_512 ;
V_126 = - V_106 ;
if ( F_238 ( & V_586 , V_585 , sizeof V_586 ) )
goto V_118;
V_512 = V_586 . V_509 ;
V_586 . V_509 = V_587 + V_588 ;
if ( F_239 ( V_585 , & V_586 , sizeof V_586 ) )
goto V_118;
V_126 = - V_398 ;
if ( V_512 < V_586 . V_509 )
goto V_118;
V_126 = - V_106 ;
if ( F_239 ( V_585 -> V_589 , & V_590 ,
V_587 * sizeof( T_1 ) ) )
goto V_118;
if ( F_239 ( V_585 -> V_589 + V_587 ,
& V_591 ,
V_588 * sizeof( T_1 ) ) )
goto V_118;
V_126 = 0 ;
break;
}
case V_592 :
case V_593 : {
struct V_594 T_14 * V_595 = V_582 ;
struct V_594 V_596 ;
V_126 = - V_106 ;
if ( F_238 ( & V_596 , V_595 , sizeof V_596 ) )
goto V_118;
V_126 = F_244 ( & V_596 , V_595 -> V_506 ,
V_580 ) ;
if ( V_126 )
goto V_118;
V_126 = - V_106 ;
if ( F_239 ( V_595 , & V_596 , sizeof V_596 ) )
goto V_118;
V_126 = 0 ;
break;
}
case V_597 : {
V_126 = - V_106 ;
if ( F_239 ( V_582 , & V_598 ,
sizeof( V_598 ) ) )
goto V_118;
V_126 = 0 ;
break;
}
default:
V_126 = - V_599 ;
}
V_118:
return V_126 ;
}
static void F_245 ( void * V_600 )
{
F_246 () ;
}
static bool F_247 ( struct V_1 * V_2 )
{
return F_70 ( V_2 -> V_144 ) ;
}
void F_248 ( struct V_1 * V_2 , int V_24 )
{
if ( F_247 ( V_2 ) ) {
if ( V_92 -> V_601 () )
F_249 ( V_24 , V_2 -> V_5 . V_602 ) ;
else if ( V_2 -> V_24 != - 1 && V_2 -> V_24 != V_24 )
F_250 ( V_2 -> V_24 ,
F_245 , NULL , 1 ) ;
}
V_92 -> V_603 ( V_2 , V_24 ) ;
if ( F_165 ( V_2 -> V_5 . V_604 ) ) {
F_158 ( V_2 , V_2 -> V_5 . V_604 ) ;
V_2 -> V_5 . V_604 = 0 ;
F_32 ( V_351 , V_2 ) ;
}
if ( F_165 ( V_2 -> V_24 != V_24 ) || F_153 () ) {
T_12 V_605 = ! V_2 -> V_5 . V_606 ? 0 :
F_146 () - V_2 -> V_5 . V_606 ;
if ( V_605 < 0 )
F_251 ( L_19 ) ;
if ( F_153 () ) {
T_2 V_99 = F_145 ( V_2 ,
V_2 -> V_5 . V_335 ) ;
F_148 ( V_2 , V_99 ) ;
V_2 -> V_5 . V_285 = 1 ;
}
if ( F_252 ( V_2 ) )
F_253 ( V_2 ) ;
if ( ! V_2 -> V_144 -> V_5 . V_307 || V_2 -> V_24 == - 1 )
F_32 ( V_446 , V_2 ) ;
if ( V_2 -> V_24 != V_24 )
F_32 ( V_607 , V_2 ) ;
V_2 -> V_24 = V_24 ;
}
F_32 ( V_451 , V_2 ) ;
}
static void F_254 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_408 . V_402 & V_409 ) )
return;
V_2 -> V_5 . V_408 . V_411 . V_413 = 1 ;
F_255 ( V_2 -> V_144 , & V_2 -> V_5 . V_408 . V_410 ,
& V_2 -> V_5 . V_408 . V_411 . V_413 ,
F_187 ( struct V_412 , V_413 ) ,
sizeof( V_2 -> V_5 . V_408 . V_411 . V_413 ) ) ;
}
void F_256 ( struct V_1 * V_2 )
{
int V_507 ;
if ( V_2 -> V_413 )
V_2 -> V_5 . V_608 = ! V_92 -> V_93 ( V_2 ) ;
F_257 () ;
V_507 = F_235 ( & V_2 -> V_144 -> V_508 ) ;
F_254 ( V_2 ) ;
F_236 ( & V_2 -> V_144 -> V_508 , V_507 ) ;
F_258 () ;
V_92 -> V_609 ( V_2 ) ;
F_259 ( V_2 ) ;
V_2 -> V_5 . V_606 = F_146 () ;
}
static int F_260 ( struct V_1 * V_2 ,
struct V_610 * V_611 )
{
if ( V_92 -> V_612 && V_2 -> V_5 . V_613 )
V_92 -> V_612 ( V_2 ) ;
return F_261 ( V_2 , V_611 ) ;
}
static int F_262 ( struct V_1 * V_2 ,
struct V_610 * V_611 )
{
int V_126 ;
V_126 = F_263 ( V_2 , V_611 ) ;
if ( V_126 )
return V_126 ;
F_264 ( V_2 ) ;
return 0 ;
}
static int F_265 ( struct V_1 * V_2 )
{
return ( ! F_88 ( V_2 ) ||
F_266 ( V_2 ) ) ;
}
static int F_267 ( struct V_1 * V_2 )
{
return F_268 ( V_2 ) &&
! F_269 ( V_2 ) &&
! F_270 ( V_2 ) &&
F_265 ( V_2 ) ;
}
static int F_271 ( struct V_1 * V_2 ,
struct V_614 * V_615 )
{
if ( V_615 -> V_615 >= V_616 )
return - V_599 ;
if ( ! F_272 ( V_2 -> V_144 ) ) {
F_273 ( V_2 , V_615 -> V_615 , false ) ;
F_32 ( V_69 , V_2 ) ;
return 0 ;
}
if ( F_274 ( V_2 -> V_144 ) )
return - V_617 ;
if ( V_2 -> V_5 . V_618 != - 1 )
return - V_619 ;
V_2 -> V_5 . V_618 = V_615 -> V_615 ;
F_32 ( V_69 , V_2 ) ;
return 0 ;
}
static int F_275 ( struct V_1 * V_2 )
{
F_45 ( V_2 ) ;
return 0 ;
}
static int F_276 ( struct V_1 * V_2 )
{
F_32 ( V_620 , V_2 ) ;
return 0 ;
}
static int F_277 ( struct V_1 * V_2 ,
struct V_621 * V_622 )
{
if ( V_622 -> V_15 )
return - V_599 ;
V_2 -> V_5 . V_623 = ! ! V_622 -> V_624 ;
return 0 ;
}
static int F_278 ( struct V_1 * V_2 ,
T_2 V_378 )
{
int V_126 ;
unsigned V_379 = V_378 & 0xff , V_625 ;
V_126 = - V_599 ;
if ( ! V_379 || V_379 >= V_453 )
goto V_118;
if ( V_378 & ~ ( V_598 | 0xff | 0xff0000 ) )
goto V_118;
V_126 = 0 ;
V_2 -> V_5 . V_378 = V_378 ;
if ( V_378 & V_383 )
V_2 -> V_5 . V_384 = ~ ( T_2 ) 0 ;
for ( V_625 = 0 ; V_625 < V_379 ; V_625 ++ )
V_2 -> V_5 . V_386 [ V_625 * 4 ] = ~ ( T_2 ) 0 ;
if ( V_92 -> V_626 )
V_92 -> V_626 ( V_2 ) ;
V_118:
return V_126 ;
}
static int F_279 ( struct V_1 * V_2 ,
struct V_627 * V_628 )
{
T_2 V_378 = V_2 -> V_5 . V_378 ;
unsigned V_379 = V_378 & 0xff ;
T_2 * V_629 = V_2 -> V_5 . V_386 ;
if ( V_628 -> V_625 >= V_379 || ! ( V_628 -> V_476 & V_630 ) )
return - V_599 ;
if ( ( V_628 -> V_476 & V_631 ) && ( V_378 & V_383 ) &&
V_2 -> V_5 . V_384 != ~ ( T_2 ) 0 )
return 0 ;
V_629 += 4 * V_628 -> V_625 ;
if ( ( V_628 -> V_476 & V_631 ) && V_629 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_628 -> V_476 & V_631 ) {
if ( ( V_2 -> V_5 . V_381 & V_632 ) ||
! F_50 ( V_2 , V_633 ) ) {
F_32 ( V_75 , V_2 ) ;
return 0 ;
}
if ( V_629 [ 1 ] & V_630 )
V_628 -> V_476 |= V_634 ;
V_629 [ 2 ] = V_628 -> V_635 ;
V_629 [ 3 ] = V_628 -> V_636 ;
V_2 -> V_5 . V_381 = V_628 -> V_381 ;
V_629 [ 1 ] = V_628 -> V_476 ;
F_35 ( V_2 , V_60 ) ;
} else if ( ! ( V_629 [ 1 ] & V_630 )
|| ! ( V_629 [ 1 ] & V_631 ) ) {
if ( V_629 [ 1 ] & V_630 )
V_628 -> V_476 |= V_634 ;
V_629 [ 2 ] = V_628 -> V_635 ;
V_629 [ 3 ] = V_628 -> V_636 ;
V_629 [ 1 ] = V_628 -> V_476 ;
} else
V_629 [ 1 ] |= V_634 ;
return 0 ;
}
static void F_280 ( struct V_1 * V_2 ,
struct V_637 * V_638 )
{
F_281 ( V_2 ) ;
V_638 -> V_70 . V_72 =
( V_2 -> V_5 . V_70 . V_71 ||
V_2 -> V_5 . V_70 . V_72 ) &&
! F_282 ( V_2 -> V_5 . V_70 . V_18 ) ;
V_638 -> V_70 . V_18 = V_2 -> V_5 . V_70 . V_18 ;
V_638 -> V_70 . V_74 = V_2 -> V_5 . V_70 . V_74 ;
V_638 -> V_70 . V_639 = 0 ;
V_638 -> V_70 . V_64 = V_2 -> V_5 . V_70 . V_64 ;
V_638 -> V_640 . V_72 =
V_2 -> V_5 . V_640 . V_71 && ! V_2 -> V_5 . V_640 . V_641 ;
V_638 -> V_640 . V_18 = V_2 -> V_5 . V_640 . V_18 ;
V_638 -> V_640 . V_641 = 0 ;
V_638 -> V_640 . V_642 = V_92 -> V_643 ( V_2 ) ;
V_638 -> V_644 . V_72 = V_2 -> V_5 . V_645 ;
V_638 -> V_644 . V_71 = V_2 -> V_5 . V_646 != 0 ;
V_638 -> V_644 . V_647 = V_92 -> V_648 ( V_2 ) ;
V_638 -> V_644 . V_639 = 0 ;
V_638 -> V_649 = 0 ;
V_638 -> V_650 . V_651 = F_283 ( V_2 ) ;
V_638 -> V_650 . V_71 = V_2 -> V_5 . V_652 ;
V_638 -> V_650 . V_653 =
! ! ( V_2 -> V_5 . V_654 & V_655 ) ;
V_638 -> V_650 . V_656 = F_284 ( V_2 ) ;
V_638 -> V_15 = ( V_657
| V_658
| V_659 ) ;
memset ( & V_638 -> V_660 , 0 , sizeof( V_638 -> V_660 ) ) ;
}
static int F_285 ( struct V_1 * V_2 ,
struct V_637 * V_638 )
{
if ( V_638 -> V_15 & ~ ( V_657
| V_661
| V_658
| V_659 ) )
return - V_599 ;
if ( V_638 -> V_70 . V_72 &&
( V_638 -> V_70 . V_18 > 31 || V_638 -> V_70 . V_18 == V_53 ||
F_41 ( V_2 ) ) )
return - V_599 ;
if ( V_638 -> V_15 & V_659 &&
( V_638 -> V_650 . V_651 || V_638 -> V_650 . V_71 ) &&
V_2 -> V_5 . V_662 == V_663 )
return - V_599 ;
F_281 ( V_2 ) ;
V_2 -> V_5 . V_70 . V_72 = false ;
V_2 -> V_5 . V_70 . V_71 = V_638 -> V_70 . V_72 ;
V_2 -> V_5 . V_70 . V_18 = V_638 -> V_70 . V_18 ;
V_2 -> V_5 . V_70 . V_74 = V_638 -> V_70 . V_74 ;
V_2 -> V_5 . V_70 . V_64 = V_638 -> V_70 . V_64 ;
V_2 -> V_5 . V_640 . V_71 = V_638 -> V_640 . V_72 ;
V_2 -> V_5 . V_640 . V_18 = V_638 -> V_640 . V_18 ;
V_2 -> V_5 . V_640 . V_641 = V_638 -> V_640 . V_641 ;
if ( V_638 -> V_15 & V_658 )
V_92 -> V_664 ( V_2 ,
V_638 -> V_640 . V_642 ) ;
V_2 -> V_5 . V_645 = V_638 -> V_644 . V_72 ;
if ( V_638 -> V_15 & V_657 )
V_2 -> V_5 . V_646 = V_638 -> V_644 . V_71 ;
V_92 -> V_665 ( V_2 , V_638 -> V_644 . V_647 ) ;
if ( V_638 -> V_15 & V_661 &&
F_88 ( V_2 ) )
V_2 -> V_5 . V_666 -> V_649 = V_638 -> V_649 ;
if ( V_638 -> V_15 & V_659 ) {
T_1 V_654 = V_2 -> V_5 . V_654 ;
if ( V_638 -> V_650 . V_651 )
V_654 |= V_667 ;
else
V_654 &= ~ V_667 ;
F_286 ( V_2 , V_654 ) ;
V_2 -> V_5 . V_652 = V_638 -> V_650 . V_71 ;
if ( V_638 -> V_650 . V_651 ) {
if ( V_638 -> V_650 . V_653 )
V_2 -> V_5 . V_654 |= V_655 ;
else
V_2 -> V_5 . V_654 &= ~ V_655 ;
if ( F_88 ( V_2 ) ) {
if ( V_638 -> V_650 . V_656 )
F_287 ( V_668 , & V_2 -> V_5 . V_666 -> V_669 ) ;
else
F_288 ( V_668 , & V_2 -> V_5 . V_666 -> V_669 ) ;
}
}
}
F_32 ( V_69 , V_2 ) ;
return 0 ;
}
static void F_289 ( struct V_1 * V_2 ,
struct V_670 * V_671 )
{
unsigned long V_209 ;
memcpy ( V_671 -> V_195 , V_2 -> V_5 . V_195 , sizeof( V_2 -> V_5 . V_195 ) ) ;
F_98 ( V_2 , 6 , & V_209 ) ;
V_671 -> V_199 = V_209 ;
V_671 -> V_200 = V_2 -> V_5 . V_200 ;
V_671 -> V_15 = 0 ;
memset ( & V_671 -> V_660 , 0 , sizeof( V_671 -> V_660 ) ) ;
}
static int F_290 ( struct V_1 * V_2 ,
struct V_670 * V_671 )
{
if ( V_671 -> V_15 )
return - V_599 ;
if ( V_671 -> V_199 & ~ 0xffffffffull )
return - V_599 ;
if ( V_671 -> V_200 & ~ 0xffffffffull )
return - V_599 ;
memcpy ( V_2 -> V_5 . V_195 , V_671 -> V_195 , sizeof( V_2 -> V_5 . V_195 ) ) ;
F_92 ( V_2 ) ;
V_2 -> V_5 . V_199 = V_671 -> V_199 ;
F_93 ( V_2 ) ;
V_2 -> V_5 . V_200 = V_671 -> V_200 ;
F_94 ( V_2 ) ;
return 0 ;
}
static void F_291 ( T_13 * V_672 , struct V_1 * V_2 )
{
struct V_673 * V_674 = & V_2 -> V_5 . V_675 . V_676 . V_674 ;
T_2 V_677 = V_674 -> V_678 . V_679 ;
T_2 V_680 ;
memcpy ( V_672 , V_674 , V_681 ) ;
V_677 &= V_2 -> V_5 . V_159 | V_682 ;
* ( T_2 * ) ( V_672 + V_681 ) = V_677 ;
V_680 = V_677 & ~ V_682 ;
while ( V_680 ) {
T_2 V_683 = V_680 & - V_680 ;
int V_152 = F_292 ( V_683 ) - 1 ;
void * V_684 = F_293 ( V_674 , V_683 ) ;
if ( V_684 ) {
T_1 V_513 , V_99 , V_214 , V_685 ;
F_294 ( V_686 , V_152 ,
& V_513 , & V_99 , & V_214 , & V_685 ) ;
if ( V_683 == V_687 )
memcpy ( V_672 + V_99 , & V_2 -> V_5 . V_688 ,
sizeof( V_2 -> V_5 . V_688 ) ) ;
else
memcpy ( V_672 + V_99 , V_684 , V_513 ) ;
}
V_680 -= V_683 ;
}
}
static void F_295 ( struct V_1 * V_2 , T_13 * V_684 )
{
struct V_673 * V_674 = & V_2 -> V_5 . V_675 . V_676 . V_674 ;
T_2 V_677 = * ( T_2 * ) ( V_684 + V_681 ) ;
T_2 V_680 ;
memcpy ( V_674 , V_684 , V_681 ) ;
V_674 -> V_678 . V_679 = V_677 ;
if ( F_242 ( V_689 ) )
V_674 -> V_678 . V_690 = V_151 | V_691 ;
V_680 = V_677 & ~ V_682 ;
while ( V_680 ) {
T_2 V_683 = V_680 & - V_680 ;
int V_152 = F_292 ( V_683 ) - 1 ;
void * V_672 = F_293 ( V_674 , V_683 ) ;
if ( V_672 ) {
T_1 V_513 , V_99 , V_214 , V_685 ;
F_294 ( V_686 , V_152 ,
& V_513 , & V_99 , & V_214 , & V_685 ) ;
if ( V_683 == V_687 )
memcpy ( & V_2 -> V_5 . V_688 , V_684 + V_99 ,
sizeof( V_2 -> V_5 . V_688 ) ) ;
else
memcpy ( V_672 , V_684 + V_99 , V_513 ) ;
}
V_680 -= V_683 ;
}
}
static void F_296 ( struct V_1 * V_2 ,
struct V_692 * V_693 )
{
if ( F_242 ( V_174 ) ) {
memset ( V_693 , 0 , sizeof( struct V_692 ) ) ;
F_291 ( ( T_13 * ) V_693 -> V_694 , V_2 ) ;
} else {
memcpy ( V_693 -> V_694 ,
& V_2 -> V_5 . V_675 . V_676 . V_695 ,
sizeof( struct V_696 ) ) ;
* ( T_2 * ) & V_693 -> V_694 [ V_681 / sizeof( T_1 ) ] =
V_682 ;
}
}
static int F_297 ( struct V_1 * V_2 ,
struct V_692 * V_693 )
{
T_2 V_677 =
* ( T_2 * ) & V_693 -> V_694 [ V_681 / sizeof( T_1 ) ] ;
T_1 V_697 = * ( T_1 * ) & V_693 -> V_694 [ V_698 / sizeof( T_1 ) ] ;
if ( F_242 ( V_174 ) ) {
if ( V_677 & ~ F_298 () ||
V_697 & ~ V_699 )
return - V_599 ;
F_295 ( V_2 , ( T_13 * ) V_693 -> V_694 ) ;
} else {
if ( V_677 & ~ V_682 ||
V_697 & ~ V_699 )
return - V_599 ;
memcpy ( & V_2 -> V_5 . V_675 . V_676 . V_695 ,
V_693 -> V_694 , sizeof( struct V_696 ) ) ;
}
return 0 ;
}
static void F_299 ( struct V_1 * V_2 ,
struct V_700 * V_701 )
{
if ( ! F_242 ( V_174 ) ) {
V_701 -> V_702 = 0 ;
return;
}
V_701 -> V_702 = 1 ;
V_701 -> V_15 = 0 ;
V_701 -> V_703 [ 0 ] . V_153 = V_149 ;
V_701 -> V_703 [ 0 ] . V_23 = V_2 -> V_5 . V_150 ;
}
static int F_300 ( struct V_1 * V_2 ,
struct V_700 * V_701 )
{
int V_3 , V_126 = 0 ;
if ( ! F_242 ( V_174 ) )
return - V_599 ;
if ( V_701 -> V_702 > V_704 || V_701 -> V_15 )
return - V_599 ;
for ( V_3 = 0 ; V_3 < V_701 -> V_702 ; V_3 ++ )
if ( V_701 -> V_703 [ V_3 ] . V_153 == V_149 ) {
V_126 = F_78 ( V_2 , V_149 ,
V_701 -> V_703 [ V_3 ] . V_23 ) ;
break;
}
if ( V_126 )
V_126 = - V_599 ;
return V_126 ;
}
static int F_301 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_368 )
return - V_599 ;
V_2 -> V_5 . V_363 = true ;
F_32 ( V_351 , V_2 ) ;
return 0 ;
}
static int F_302 ( struct V_1 * V_2 ,
struct V_705 * V_706 )
{
if ( V_706 -> V_15 )
return - V_599 ;
switch ( V_706 -> V_706 ) {
case V_541 :
if ( V_706 -> args [ 0 ] )
return - V_599 ;
case V_540 :
if ( ! F_272 ( V_2 -> V_144 ) )
return - V_599 ;
return F_303 ( V_2 , V_706 -> V_706 ==
V_541 ) ;
default:
return - V_599 ;
}
}
long F_304 ( struct V_578 * V_579 ,
unsigned int V_580 , unsigned long V_581 )
{
struct V_1 * V_2 = V_579 -> V_707 ;
void T_14 * V_582 = ( void T_14 * ) V_581 ;
int V_126 ;
union {
struct V_610 * V_708 ;
struct V_692 * V_674 ;
struct V_700 * V_703 ;
void * V_709 ;
} V_710 ;
V_710 . V_709 = NULL ;
switch ( V_580 ) {
case V_711 : {
V_126 = - V_599 ;
if ( ! F_88 ( V_2 ) )
goto V_118;
V_710 . V_708 = F_305 ( sizeof( struct V_610 ) , V_712 ) ;
V_126 = - V_399 ;
if ( ! V_710 . V_708 )
goto V_118;
V_126 = F_260 ( V_2 , V_710 . V_708 ) ;
if ( V_126 )
goto V_118;
V_126 = - V_106 ;
if ( F_239 ( V_582 , V_710 . V_708 , sizeof( struct V_610 ) ) )
goto V_118;
V_126 = 0 ;
break;
}
case V_713 : {
V_126 = - V_599 ;
if ( ! F_88 ( V_2 ) )
goto V_118;
V_710 . V_708 = F_203 ( V_582 , sizeof( * V_710 . V_708 ) ) ;
if ( F_204 ( V_710 . V_708 ) )
return F_205 ( V_710 . V_708 ) ;
V_126 = F_262 ( V_2 , V_710 . V_708 ) ;
break;
}
case V_714 : {
struct V_614 V_615 ;
V_126 = - V_106 ;
if ( F_238 ( & V_615 , V_582 , sizeof V_615 ) )
goto V_118;
V_126 = F_271 ( V_2 , & V_615 ) ;
break;
}
case V_715 : {
V_126 = F_275 ( V_2 ) ;
break;
}
case V_716 : {
V_126 = F_276 ( V_2 ) ;
break;
}
case V_717 : {
struct V_718 T_14 * V_595 = V_582 ;
struct V_718 V_596 ;
V_126 = - V_106 ;
if ( F_238 ( & V_596 , V_595 , sizeof V_596 ) )
goto V_118;
V_126 = F_306 ( V_2 , & V_596 , V_595 -> V_506 ) ;
break;
}
case V_719 : {
struct V_594 T_14 * V_595 = V_582 ;
struct V_594 V_596 ;
V_126 = - V_106 ;
if ( F_238 ( & V_596 , V_595 , sizeof V_596 ) )
goto V_118;
V_126 = F_307 ( V_2 , & V_596 ,
V_595 -> V_506 ) ;
break;
}
case V_720 : {
struct V_594 T_14 * V_595 = V_582 ;
struct V_594 V_596 ;
V_126 = - V_106 ;
if ( F_238 ( & V_596 , V_595 , sizeof V_596 ) )
goto V_118;
V_126 = F_308 ( V_2 , & V_596 ,
V_595 -> V_506 ) ;
if ( V_126 )
goto V_118;
V_126 = - V_106 ;
if ( F_239 ( V_595 , & V_596 , sizeof V_596 ) )
goto V_118;
V_126 = 0 ;
break;
}
case V_721 :
V_126 = F_237 ( V_2 , V_582 , F_110 , 1 ) ;
break;
case V_722 :
V_126 = F_237 ( V_2 , V_582 , F_112 , 0 ) ;
break;
case V_723 : {
struct V_621 V_622 ;
V_126 = - V_106 ;
if ( F_238 ( & V_622 , V_582 , sizeof V_622 ) )
goto V_118;
V_126 = F_277 ( V_2 , & V_622 ) ;
if ( V_126 )
goto V_118;
V_126 = - V_106 ;
if ( F_239 ( V_582 , & V_622 , sizeof V_622 ) )
goto V_118;
V_126 = 0 ;
break;
} ;
case V_724 : {
struct V_725 V_726 ;
int V_507 ;
V_126 = - V_599 ;
if ( ! F_88 ( V_2 ) )
goto V_118;
V_126 = - V_106 ;
if ( F_238 ( & V_726 , V_582 , sizeof V_726 ) )
goto V_118;
V_507 = F_235 ( & V_2 -> V_144 -> V_508 ) ;
V_126 = F_309 ( V_2 , V_726 . V_727 ) ;
F_236 ( & V_2 -> V_144 -> V_508 , V_507 ) ;
break;
}
case V_728 : {
T_2 V_378 ;
V_126 = - V_106 ;
if ( F_238 ( & V_378 , V_582 , sizeof V_378 ) )
goto V_118;
V_126 = F_278 ( V_2 , V_378 ) ;
break;
}
case V_729 : {
struct V_627 V_628 ;
V_126 = - V_106 ;
if ( F_238 ( & V_628 , V_582 , sizeof V_628 ) )
goto V_118;
V_126 = F_279 ( V_2 , & V_628 ) ;
break;
}
case V_730 : {
struct V_637 V_638 ;
F_280 ( V_2 , & V_638 ) ;
V_126 = - V_106 ;
if ( F_239 ( V_582 , & V_638 , sizeof( struct V_637 ) ) )
break;
V_126 = 0 ;
break;
}
case V_731 : {
struct V_637 V_638 ;
V_126 = - V_106 ;
if ( F_238 ( & V_638 , V_582 , sizeof( struct V_637 ) ) )
break;
V_126 = F_285 ( V_2 , & V_638 ) ;
break;
}
case V_732 : {
struct V_670 V_671 ;
F_289 ( V_2 , & V_671 ) ;
V_126 = - V_106 ;
if ( F_239 ( V_582 , & V_671 ,
sizeof( struct V_670 ) ) )
break;
V_126 = 0 ;
break;
}
case V_733 : {
struct V_670 V_671 ;
V_126 = - V_106 ;
if ( F_238 ( & V_671 , V_582 ,
sizeof( struct V_670 ) ) )
break;
V_126 = F_290 ( V_2 , & V_671 ) ;
break;
}
case V_734 : {
V_710 . V_674 = F_305 ( sizeof( struct V_692 ) , V_712 ) ;
V_126 = - V_399 ;
if ( ! V_710 . V_674 )
break;
F_296 ( V_2 , V_710 . V_674 ) ;
V_126 = - V_106 ;
if ( F_239 ( V_582 , V_710 . V_674 , sizeof( struct V_692 ) ) )
break;
V_126 = 0 ;
break;
}
case V_735 : {
V_710 . V_674 = F_203 ( V_582 , sizeof( * V_710 . V_674 ) ) ;
if ( F_204 ( V_710 . V_674 ) )
return F_205 ( V_710 . V_674 ) ;
V_126 = F_297 ( V_2 , V_710 . V_674 ) ;
break;
}
case V_736 : {
V_710 . V_703 = F_305 ( sizeof( struct V_700 ) , V_712 ) ;
V_126 = - V_399 ;
if ( ! V_710 . V_703 )
break;
F_299 ( V_2 , V_710 . V_703 ) ;
V_126 = - V_106 ;
if ( F_239 ( V_582 , V_710 . V_703 ,
sizeof( struct V_700 ) ) )
break;
V_126 = 0 ;
break;
}
case V_737 : {
V_710 . V_703 = F_203 ( V_582 , sizeof( * V_710 . V_703 ) ) ;
if ( F_204 ( V_710 . V_703 ) )
return F_205 ( V_710 . V_703 ) ;
V_126 = F_300 ( V_2 , V_710 . V_703 ) ;
break;
}
case V_738 : {
T_1 V_278 ;
V_126 = - V_599 ;
V_278 = ( T_1 ) V_581 ;
if ( V_278 >= V_739 )
goto V_118;
if ( V_278 == 0 )
V_278 = V_284 ;
if ( ! F_135 ( V_2 , V_278 ) )
V_126 = 0 ;
goto V_118;
}
case V_740 : {
V_126 = V_2 -> V_5 . V_295 ;
goto V_118;
}
case V_741 : {
V_126 = F_301 ( V_2 ) ;
goto V_118;
}
case V_742 : {
struct V_705 V_706 ;
V_126 = - V_106 ;
if ( F_238 ( & V_706 , V_582 , sizeof( V_706 ) ) )
goto V_118;
V_126 = F_302 ( V_2 , & V_706 ) ;
break;
}
default:
V_126 = - V_599 ;
}
V_118:
F_207 ( V_710 . V_709 ) ;
return V_126 ;
}
int F_310 ( struct V_1 * V_2 , struct V_743 * V_744 )
{
return V_745 ;
}
static int F_311 ( struct V_144 * V_144 , unsigned long V_635 )
{
int V_113 ;
if ( V_635 > ( unsigned int ) ( - 3 * V_112 ) )
return - V_599 ;
V_113 = V_92 -> V_746 ( V_144 , V_635 ) ;
return V_113 ;
}
static int F_312 ( struct V_144 * V_144 ,
T_2 V_747 )
{
V_144 -> V_5 . V_748 = V_747 ;
return 0 ;
}
static int F_313 ( struct V_144 * V_144 ,
T_1 V_749 )
{
if ( V_749 < V_750 )
return - V_599 ;
F_314 ( & V_144 -> V_751 ) ;
F_315 ( V_144 , V_749 ) ;
V_144 -> V_5 . V_752 = V_749 ;
F_316 ( & V_144 -> V_751 ) ;
return 0 ;
}
static int F_317 ( struct V_144 * V_144 )
{
return V_144 -> V_5 . V_753 ;
}
static int F_318 ( struct V_144 * V_144 , struct V_754 * V_755 )
{
struct V_756 * V_757 = V_144 -> V_5 . V_758 ;
int V_126 ;
V_126 = 0 ;
switch ( V_755 -> V_759 ) {
case V_760 :
memcpy ( & V_755 -> V_755 . V_757 , & V_757 -> V_761 [ 0 ] ,
sizeof( struct V_762 ) ) ;
break;
case V_763 :
memcpy ( & V_755 -> V_755 . V_757 , & V_757 -> V_761 [ 1 ] ,
sizeof( struct V_762 ) ) ;
break;
case V_764 :
F_319 ( V_144 , & V_755 -> V_755 . V_765 ) ;
break;
default:
V_126 = - V_599 ;
break;
}
return V_126 ;
}
static int F_320 ( struct V_144 * V_144 , struct V_754 * V_755 )
{
struct V_756 * V_757 = V_144 -> V_5 . V_758 ;
int V_126 ;
V_126 = 0 ;
switch ( V_755 -> V_759 ) {
case V_760 :
F_155 ( & V_757 -> V_766 ) ;
memcpy ( & V_757 -> V_761 [ 0 ] , & V_755 -> V_755 . V_757 ,
sizeof( struct V_762 ) ) ;
F_156 ( & V_757 -> V_766 ) ;
break;
case V_763 :
F_155 ( & V_757 -> V_766 ) ;
memcpy ( & V_757 -> V_761 [ 1 ] , & V_755 -> V_755 . V_757 ,
sizeof( struct V_762 ) ) ;
F_156 ( & V_757 -> V_766 ) ;
break;
case V_764 :
F_321 ( V_144 , & V_755 -> V_755 . V_765 ) ;
break;
default:
V_126 = - V_599 ;
break;
}
F_322 ( V_757 ) ;
return V_126 ;
}
static int F_323 ( struct V_144 * V_144 , struct V_767 * V_768 )
{
struct V_769 * V_770 = & V_144 -> V_5 . V_771 -> V_772 ;
F_186 ( sizeof( * V_768 ) != sizeof( V_770 -> V_773 ) ) ;
F_314 ( & V_770 -> V_766 ) ;
memcpy ( V_768 , & V_770 -> V_773 , sizeof( * V_768 ) ) ;
F_316 ( & V_770 -> V_766 ) ;
return 0 ;
}
static int F_324 ( struct V_144 * V_144 , struct V_767 * V_768 )
{
int V_3 ;
struct V_774 * V_775 = V_144 -> V_5 . V_771 ;
F_314 ( & V_775 -> V_772 . V_766 ) ;
memcpy ( & V_775 -> V_772 . V_773 , V_768 , sizeof( * V_768 ) ) ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
F_325 ( V_775 , V_3 , V_768 -> V_773 [ V_3 ] . V_776 , 0 ) ;
F_316 ( & V_775 -> V_772 . V_766 ) ;
return 0 ;
}
static int F_326 ( struct V_144 * V_144 , struct V_777 * V_768 )
{
F_314 ( & V_144 -> V_5 . V_771 -> V_772 . V_766 ) ;
memcpy ( V_768 -> V_773 , & V_144 -> V_5 . V_771 -> V_772 . V_773 ,
sizeof( V_768 -> V_773 ) ) ;
V_768 -> V_15 = V_144 -> V_5 . V_771 -> V_772 . V_15 ;
F_316 ( & V_144 -> V_5 . V_771 -> V_772 . V_766 ) ;
memset ( & V_768 -> V_660 , 0 , sizeof( V_768 -> V_660 ) ) ;
return 0 ;
}
static int F_327 ( struct V_144 * V_144 , struct V_777 * V_768 )
{
int V_778 = 0 ;
int V_3 ;
T_1 V_779 , V_780 ;
struct V_774 * V_775 = V_144 -> V_5 . V_771 ;
F_314 ( & V_775 -> V_772 . V_766 ) ;
V_779 = V_775 -> V_772 . V_15 & V_781 ;
V_780 = V_768 -> V_15 & V_781 ;
if ( ! V_779 && V_780 )
V_778 = 1 ;
memcpy ( & V_775 -> V_772 . V_773 , & V_768 -> V_773 ,
sizeof( V_775 -> V_772 . V_773 ) ) ;
V_775 -> V_772 . V_15 = V_768 -> V_15 ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
F_325 ( V_775 , V_3 , V_775 -> V_772 . V_773 [ V_3 ] . V_776 ,
V_778 && V_3 == 0 ) ;
F_316 ( & V_775 -> V_772 . V_766 ) ;
return 0 ;
}
static int F_328 ( struct V_144 * V_144 ,
struct V_782 * V_783 )
{
struct V_774 * V_775 = V_144 -> V_5 . V_771 ;
if ( ! V_775 )
return - V_617 ;
F_314 ( & V_775 -> V_772 . V_766 ) ;
F_329 ( V_775 , V_783 -> V_784 ) ;
F_316 ( & V_775 -> V_772 . V_766 ) ;
return 0 ;
}
int F_330 ( struct V_144 * V_144 , struct V_785 * log )
{
bool V_786 = false ;
int V_126 ;
F_314 ( & V_144 -> V_751 ) ;
if ( V_92 -> V_787 )
V_92 -> V_787 ( V_144 ) ;
V_126 = F_331 ( V_144 , log , & V_786 ) ;
F_332 ( & V_144 -> V_751 ) ;
if ( V_786 )
F_333 ( V_144 ) ;
F_316 ( & V_144 -> V_751 ) ;
return V_126 ;
}
int F_334 ( struct V_144 * V_144 , struct V_788 * V_789 ,
bool V_790 )
{
if ( ! F_272 ( V_144 ) )
return - V_617 ;
V_789 -> V_476 = F_335 ( V_144 , V_791 ,
V_789 -> V_615 , V_789 -> V_792 ,
V_790 ) ;
return 0 ;
}
static int F_336 ( struct V_144 * V_144 ,
struct V_705 * V_706 )
{
int V_126 ;
if ( V_706 -> V_15 )
return - V_599 ;
switch ( V_706 -> V_706 ) {
case V_555 :
V_144 -> V_5 . V_793 = V_706 -> args [ 0 ] ;
V_126 = 0 ;
break;
case V_557 : {
F_314 ( & V_144 -> V_766 ) ;
V_126 = - V_599 ;
if ( V_706 -> args [ 0 ] > V_794 )
goto V_795;
V_126 = - V_619 ;
if ( F_272 ( V_144 ) )
goto V_795;
if ( V_144 -> V_796 )
goto V_795;
V_126 = F_337 ( V_144 ) ;
if ( V_126 )
goto V_795;
F_189 () ;
V_144 -> V_5 . V_797 = V_798 ;
V_144 -> V_5 . V_799 = V_706 -> args [ 0 ] ;
V_126 = 0 ;
V_795:
F_316 ( & V_144 -> V_766 ) ;
break;
}
case V_576 :
V_126 = - V_599 ;
if ( V_706 -> args [ 0 ] & ~ V_577 )
break;
if ( V_706 -> args [ 0 ] & V_800 )
V_144 -> V_5 . V_801 = true ;
if ( V_706 -> args [ 0 ] & V_802 )
V_144 -> V_5 . V_803 = true ;
V_126 = 0 ;
break;
default:
V_126 = - V_599 ;
break;
}
return V_126 ;
}
long F_338 ( struct V_578 * V_579 ,
unsigned int V_580 , unsigned long V_581 )
{
struct V_144 * V_144 = V_579 -> V_707 ;
void T_14 * V_582 = ( void T_14 * ) V_581 ;
int V_126 = - V_804 ;
union {
struct V_767 V_768 ;
struct V_777 V_805 ;
struct V_806 V_807 ;
} V_710 ;
switch ( V_580 ) {
case V_808 :
V_126 = F_311 ( V_144 , V_581 ) ;
break;
case V_809 : {
T_2 V_747 ;
V_126 = - V_106 ;
if ( F_238 ( & V_747 , V_582 , sizeof V_747 ) )
goto V_118;
V_126 = F_312 ( V_144 , V_747 ) ;
break;
}
case V_810 :
V_126 = F_313 ( V_144 , V_581 ) ;
break;
case V_811 :
V_126 = F_317 ( V_144 ) ;
break;
case V_812 : {
F_314 ( & V_144 -> V_766 ) ;
V_126 = - V_619 ;
if ( F_272 ( V_144 ) )
goto V_813;
V_126 = - V_599 ;
if ( V_144 -> V_796 )
goto V_813;
V_126 = F_339 ( V_144 ) ;
if ( V_126 )
goto V_813;
V_126 = F_340 ( V_144 ) ;
if ( V_126 ) {
F_341 ( V_144 ) ;
goto V_813;
}
V_126 = F_342 ( V_144 ) ;
if ( V_126 ) {
F_343 ( V_144 ) ;
F_341 ( V_144 ) ;
goto V_813;
}
F_189 () ;
V_144 -> V_5 . V_797 = V_814 ;
V_813:
F_316 ( & V_144 -> V_766 ) ;
break;
}
case V_815 :
V_710 . V_807 . V_15 = V_816 ;
goto V_817;
case V_818 :
V_126 = - V_106 ;
if ( F_238 ( & V_710 . V_807 , V_582 ,
sizeof( struct V_806 ) ) )
goto V_118;
V_817:
F_314 ( & V_144 -> V_766 ) ;
V_126 = - V_619 ;
if ( V_144 -> V_5 . V_771 )
goto V_819;
V_126 = - V_399 ;
V_144 -> V_5 . V_771 = F_344 ( V_144 , V_710 . V_807 . V_15 ) ;
if ( V_144 -> V_5 . V_771 )
V_126 = 0 ;
V_819:
F_316 ( & V_144 -> V_766 ) ;
break;
case V_820 : {
struct V_754 * V_755 ;
V_755 = F_203 ( V_582 , sizeof( * V_755 ) ) ;
if ( F_204 ( V_755 ) ) {
V_126 = F_205 ( V_755 ) ;
goto V_118;
}
V_126 = - V_617 ;
if ( ! F_345 ( V_144 ) )
goto V_821;
V_126 = F_318 ( V_144 , V_755 ) ;
if ( V_126 )
goto V_821;
V_126 = - V_106 ;
if ( F_239 ( V_582 , V_755 , sizeof *V_755 ) )
goto V_821;
V_126 = 0 ;
V_821:
F_207 ( V_755 ) ;
break;
}
case V_822 : {
struct V_754 * V_755 ;
V_755 = F_203 ( V_582 , sizeof( * V_755 ) ) ;
if ( F_204 ( V_755 ) ) {
V_126 = F_205 ( V_755 ) ;
goto V_118;
}
V_126 = - V_617 ;
if ( ! F_345 ( V_144 ) )
goto V_823;
V_126 = F_320 ( V_144 , V_755 ) ;
if ( V_126 )
goto V_823;
V_126 = 0 ;
V_823:
F_207 ( V_755 ) ;
break;
}
case V_824 : {
V_126 = - V_106 ;
if ( F_238 ( & V_710 . V_768 , V_582 , sizeof( struct V_767 ) ) )
goto V_118;
V_126 = - V_617 ;
if ( ! V_144 -> V_5 . V_771 )
goto V_118;
V_126 = F_323 ( V_144 , & V_710 . V_768 ) ;
if ( V_126 )
goto V_118;
V_126 = - V_106 ;
if ( F_239 ( V_582 , & V_710 . V_768 , sizeof( struct V_767 ) ) )
goto V_118;
V_126 = 0 ;
break;
}
case V_825 : {
V_126 = - V_106 ;
if ( F_238 ( & V_710 . V_768 , V_582 , sizeof V_710 . V_768 ) )
goto V_118;
V_126 = - V_617 ;
if ( ! V_144 -> V_5 . V_771 )
goto V_118;
V_126 = F_324 ( V_144 , & V_710 . V_768 ) ;
break;
}
case V_826 : {
V_126 = - V_617 ;
if ( ! V_144 -> V_5 . V_771 )
goto V_118;
V_126 = F_326 ( V_144 , & V_710 . V_805 ) ;
if ( V_126 )
goto V_118;
V_126 = - V_106 ;
if ( F_239 ( V_582 , & V_710 . V_805 , sizeof( V_710 . V_805 ) ) )
goto V_118;
V_126 = 0 ;
break;
}
case V_827 : {
V_126 = - V_106 ;
if ( F_238 ( & V_710 . V_805 , V_582 , sizeof( V_710 . V_805 ) ) )
goto V_118;
V_126 = - V_617 ;
if ( ! V_144 -> V_5 . V_771 )
goto V_118;
V_126 = F_327 ( V_144 , & V_710 . V_805 ) ;
break;
}
case V_828 : {
struct V_782 V_783 ;
V_126 = - V_106 ;
if ( F_238 ( & V_783 , V_582 , sizeof( V_783 ) ) )
goto V_118;
V_126 = F_328 ( V_144 , & V_783 ) ;
break;
}
case V_829 :
V_126 = 0 ;
F_314 ( & V_144 -> V_766 ) ;
if ( V_144 -> V_796 )
V_126 = - V_830 ;
else
V_144 -> V_5 . V_831 = V_581 ;
F_316 ( & V_144 -> V_766 ) ;
break;
case V_832 : {
V_126 = - V_106 ;
if ( F_238 ( & V_144 -> V_5 . F_202 , V_582 ,
sizeof( struct V_833 ) ) )
goto V_118;
V_126 = - V_599 ;
if ( V_144 -> V_5 . F_202 . V_15 )
goto V_118;
V_126 = 0 ;
break;
}
case V_834 : {
struct V_835 V_836 ;
T_2 V_837 ;
V_126 = - V_106 ;
if ( F_238 ( & V_836 , V_582 , sizeof( V_836 ) ) )
goto V_118;
V_126 = - V_599 ;
if ( V_836 . V_15 )
goto V_118;
V_126 = 0 ;
F_176 ( V_144 ) ;
V_837 = F_179 ( V_144 ) ;
V_144 -> V_5 . V_259 += V_836 . clock - V_837 ;
F_175 ( V_144 , V_351 ) ;
break;
}
case V_838 : {
struct V_835 V_836 ;
T_2 V_837 ;
V_837 = F_179 ( V_144 ) ;
V_836 . clock = V_837 ;
V_836 . V_15 = V_144 -> V_5 . V_307 ? V_560 : 0 ;
memset ( & V_836 . V_639 , 0 , sizeof( V_836 . V_639 ) ) ;
V_126 = - V_106 ;
if ( F_239 ( V_582 , & V_836 , sizeof( V_836 ) ) )
goto V_118;
V_126 = 0 ;
break;
}
case V_742 : {
struct V_705 V_706 ;
V_126 = - V_106 ;
if ( F_238 ( & V_706 , V_582 , sizeof( V_706 ) ) )
goto V_118;
V_126 = F_336 ( V_144 , & V_706 ) ;
break;
}
default:
V_126 = - V_804 ;
}
V_118:
return V_126 ;
}
static void F_346 ( void )
{
T_1 V_839 [ 2 ] ;
unsigned V_3 , V_840 ;
for ( V_3 = V_840 = 0 ; V_3 < F_57 ( V_590 ) ; V_3 ++ ) {
if ( F_347 ( V_590 [ V_3 ] , & V_839 [ 0 ] , & V_839 [ 1 ] ) < 0 )
continue;
switch ( V_590 [ V_3 ] ) {
case V_841 :
if ( ! V_92 -> V_842 () )
continue;
break;
case V_843 :
if ( ! V_92 -> V_844 () )
continue;
break;
default:
break;
}
if ( V_840 < V_3 )
V_590 [ V_840 ] = V_590 [ V_3 ] ;
V_840 ++ ;
}
V_587 = V_840 ;
for ( V_3 = V_840 = 0 ; V_3 < F_57 ( V_591 ) ; V_3 ++ ) {
switch ( V_591 [ V_3 ] ) {
case V_439 :
if ( ! V_92 -> V_563 () )
continue;
break;
default:
break;
}
if ( V_840 < V_3 )
V_591 [ V_840 ] = V_591 [ V_3 ] ;
V_840 ++ ;
}
V_588 = V_840 ;
}
static int F_348 ( struct V_1 * V_2 , T_6 V_635 , int V_100 ,
const void * V_277 )
{
int V_845 = 0 ;
int V_512 ;
do {
V_512 = F_349 ( V_100 , 8 ) ;
if ( ! ( F_88 ( V_2 ) &&
! F_350 ( V_2 , & V_2 -> V_5 . V_666 -> V_846 , V_635 , V_512 , V_277 ) )
&& F_351 ( V_2 , V_847 , V_635 , V_512 , V_277 ) )
break;
V_845 += V_512 ;
V_635 += V_512 ;
V_100 -= V_512 ;
V_277 += V_512 ;
} while ( V_100 );
return V_845 ;
}
static int F_352 ( struct V_1 * V_2 , T_6 V_635 , int V_100 , void * V_277 )
{
int V_845 = 0 ;
int V_512 ;
do {
V_512 = F_349 ( V_100 , 8 ) ;
if ( ! ( F_88 ( V_2 ) &&
! F_353 ( V_2 , & V_2 -> V_5 . V_666 -> V_846 ,
V_635 , V_512 , V_277 ) )
&& F_354 ( V_2 , V_847 , V_635 , V_512 , V_277 ) )
break;
F_355 ( V_848 , V_512 , V_635 , * ( T_2 * ) V_277 ) ;
V_845 += V_512 ;
V_635 += V_512 ;
V_100 -= V_512 ;
V_277 += V_512 ;
} while ( V_100 );
return V_845 ;
}
static void F_356 ( struct V_1 * V_2 ,
struct V_849 * V_850 , int V_851 )
{
V_92 -> V_852 ( V_2 , V_850 , V_851 ) ;
}
void F_357 ( struct V_1 * V_2 ,
struct V_849 * V_850 , int V_851 )
{
V_92 -> V_853 ( V_2 , V_850 , V_851 ) ;
}
T_6 F_358 ( struct V_1 * V_2 , T_6 V_401 , T_1 V_101 ,
struct V_76 * V_70 )
{
T_6 V_854 ;
F_15 ( ! F_44 ( V_2 ) ) ;
V_101 |= V_116 ;
V_854 = V_2 -> V_5 . V_88 . V_855 ( V_2 , V_401 , V_101 , V_70 ) ;
return V_854 ;
}
T_6 F_359 ( struct V_1 * V_2 , T_15 V_856 ,
struct V_76 * V_70 )
{
T_1 V_101 = ( V_92 -> V_93 ( V_2 ) == 3 ) ? V_116 : 0 ;
return V_2 -> V_5 . V_108 -> V_855 ( V_2 , V_856 , V_101 , V_70 ) ;
}
T_6 F_360 ( struct V_1 * V_2 , T_15 V_856 ,
struct V_76 * V_70 )
{
T_1 V_101 = ( V_92 -> V_93 ( V_2 ) == 3 ) ? V_116 : 0 ;
V_101 |= V_857 ;
return V_2 -> V_5 . V_108 -> V_855 ( V_2 , V_856 , V_101 , V_70 ) ;
}
T_6 F_361 ( struct V_1 * V_2 , T_15 V_856 ,
struct V_76 * V_70 )
{
T_1 V_101 = ( V_92 -> V_93 ( V_2 ) == 3 ) ? V_116 : 0 ;
V_101 |= V_117 ;
return V_2 -> V_5 . V_108 -> V_855 ( V_2 , V_856 , V_101 , V_70 ) ;
}
T_6 F_362 ( struct V_1 * V_2 , T_15 V_856 ,
struct V_76 * V_70 )
{
return V_2 -> V_5 . V_108 -> V_855 ( V_2 , V_856 , 0 , V_70 ) ;
}
static int F_363 ( T_15 V_635 , void * V_209 , unsigned int V_858 ,
struct V_1 * V_2 , T_1 V_101 ,
struct V_76 * V_70 )
{
void * V_39 = V_209 ;
int V_126 = V_859 ;
while ( V_858 ) {
T_6 V_401 = V_2 -> V_5 . V_108 -> V_855 ( V_2 , V_635 , V_101 ,
V_70 ) ;
unsigned V_99 = V_635 & ( V_112 - 1 ) ;
unsigned V_860 = F_349 ( V_858 , ( unsigned ) V_112 - V_99 ) ;
int V_113 ;
if ( V_401 == V_105 )
return V_861 ;
V_113 = F_54 ( V_2 , V_401 >> V_111 , V_39 ,
V_99 , V_860 ) ;
if ( V_113 < 0 ) {
V_126 = V_862 ;
goto V_118;
}
V_858 -= V_860 ;
V_39 += V_860 ;
V_635 += V_860 ;
}
V_118:
return V_126 ;
}
static int F_364 ( struct V_863 * V_864 ,
T_15 V_635 , void * V_209 , unsigned int V_858 ,
struct V_76 * V_70 )
{
struct V_1 * V_2 = F_365 ( V_864 ) ;
T_1 V_101 = ( V_92 -> V_93 ( V_2 ) == 3 ) ? V_116 : 0 ;
unsigned V_99 ;
int V_113 ;
T_6 V_401 = V_2 -> V_5 . V_108 -> V_855 ( V_2 , V_635 , V_101 | V_857 ,
V_70 ) ;
if ( F_165 ( V_401 == V_105 ) )
return V_861 ;
V_99 = V_635 & ( V_112 - 1 ) ;
if ( F_30 ( V_99 + V_858 > V_112 ) )
V_858 = ( unsigned ) V_112 - V_99 ;
V_113 = F_54 ( V_2 , V_401 >> V_111 , V_209 ,
V_99 , V_858 ) ;
if ( F_165 ( V_113 < 0 ) )
return V_862 ;
return V_859 ;
}
int F_366 ( struct V_863 * V_864 ,
T_15 V_635 , void * V_209 , unsigned int V_858 ,
struct V_76 * V_70 )
{
struct V_1 * V_2 = F_365 ( V_864 ) ;
T_1 V_101 = ( V_92 -> V_93 ( V_2 ) == 3 ) ? V_116 : 0 ;
return F_363 ( V_635 , V_209 , V_858 , V_2 , V_101 ,
V_70 ) ;
}
static int F_367 ( struct V_863 * V_864 ,
T_15 V_635 , void * V_209 , unsigned int V_858 ,
struct V_76 * V_70 )
{
struct V_1 * V_2 = F_365 ( V_864 ) ;
return F_363 ( V_635 , V_209 , V_858 , V_2 , 0 , V_70 ) ;
}
static int F_368 ( struct V_863 * V_864 ,
unsigned long V_635 , void * V_209 , unsigned int V_858 )
{
struct V_1 * V_2 = F_365 ( V_864 ) ;
int V_126 = F_369 ( V_2 , V_635 , V_209 , V_858 ) ;
return V_126 < 0 ? V_862 : V_859 ;
}
int F_370 ( struct V_863 * V_864 ,
T_15 V_635 , void * V_209 ,
unsigned int V_858 ,
struct V_76 * V_70 )
{
struct V_1 * V_2 = F_365 ( V_864 ) ;
void * V_39 = V_209 ;
int V_126 = V_859 ;
while ( V_858 ) {
T_6 V_401 = V_2 -> V_5 . V_108 -> V_855 ( V_2 , V_635 ,
V_117 ,
V_70 ) ;
unsigned V_99 = V_635 & ( V_112 - 1 ) ;
unsigned V_865 = F_349 ( V_858 , ( unsigned ) V_112 - V_99 ) ;
int V_113 ;
if ( V_401 == V_105 )
return V_861 ;
V_113 = F_206 ( V_2 , V_401 , V_39 , V_865 ) ;
if ( V_113 < 0 ) {
V_126 = V_862 ;
goto V_118;
}
V_858 -= V_865 ;
V_39 += V_865 ;
V_635 += V_865 ;
}
V_118:
return V_126 ;
}
static int F_371 ( struct V_1 * V_2 , unsigned long V_856 ,
T_6 V_401 , bool V_866 )
{
if ( ( V_401 & V_395 ) == V_867 )
return 1 ;
if ( F_372 ( V_2 , V_401 ) ) {
F_373 ( V_856 , V_401 , V_866 , true ) ;
return 1 ;
}
return 0 ;
}
static int F_374 ( struct V_1 * V_2 , unsigned long V_856 ,
T_6 * V_401 , struct V_76 * V_70 ,
bool V_866 )
{
T_1 V_101 = ( ( V_92 -> V_93 ( V_2 ) == 3 ) ? V_116 : 0 )
| ( V_866 ? V_117 : 0 ) ;
if ( F_375 ( V_2 , V_856 )
&& ! F_376 ( V_2 , V_2 -> V_5 . V_108 ,
V_2 -> V_5 . V_101 , 0 , V_101 ) ) {
* V_401 = V_2 -> V_5 . V_868 << V_111 |
( V_856 & ( V_112 - 1 ) ) ;
F_373 ( V_856 , * V_401 , V_866 , false ) ;
return 1 ;
}
* V_401 = V_2 -> V_5 . V_108 -> V_855 ( V_2 , V_856 , V_101 , V_70 ) ;
if ( * V_401 == V_105 )
return - 1 ;
return F_371 ( V_2 , V_856 , * V_401 , V_866 ) ;
}
int F_377 ( struct V_1 * V_2 , T_6 V_401 ,
const void * V_209 , int V_858 )
{
int V_113 ;
V_113 = F_206 ( V_2 , V_401 , V_209 , V_858 ) ;
if ( V_113 < 0 )
return 0 ;
F_378 ( V_2 , V_401 , V_209 , V_858 ) ;
return 1 ;
}
static int F_379 ( struct V_1 * V_2 , void * V_209 , int V_858 )
{
if ( V_2 -> V_869 ) {
F_355 ( V_848 , V_858 ,
V_2 -> V_870 [ 0 ] . V_401 , * ( T_2 * ) V_209 ) ;
V_2 -> V_869 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_380 ( struct V_1 * V_2 , T_6 V_401 ,
void * V_209 , int V_858 )
{
return ! F_369 ( V_2 , V_401 , V_209 , V_858 ) ;
}
static int F_381 ( struct V_1 * V_2 , T_6 V_401 ,
void * V_209 , int V_858 )
{
return F_377 ( V_2 , V_401 , V_209 , V_858 ) ;
}
static int F_382 ( struct V_1 * V_2 , T_6 V_401 , int V_858 , void * V_209 )
{
F_355 ( V_871 , V_858 , V_401 , * ( T_2 * ) V_209 ) ;
return F_348 ( V_2 , V_401 , V_858 , V_209 ) ;
}
static int F_383 ( struct V_1 * V_2 , T_6 V_401 ,
void * V_209 , int V_858 )
{
F_355 ( V_872 , V_858 , V_401 , 0 ) ;
return V_862 ;
}
static int F_384 ( struct V_1 * V_2 , T_6 V_401 ,
void * V_209 , int V_858 )
{
struct V_873 * V_874 = & V_2 -> V_870 [ 0 ] ;
memcpy ( V_2 -> V_875 -> V_876 . V_39 , V_874 -> V_39 , F_349 ( 8u , V_874 -> V_100 ) ) ;
return V_859 ;
}
static int F_385 ( unsigned long V_635 , void * V_209 ,
unsigned int V_858 ,
struct V_76 * V_70 ,
struct V_1 * V_2 ,
const struct V_877 * V_878 )
{
T_6 V_401 ;
int V_845 , V_113 ;
bool V_866 = V_878 -> V_866 ;
struct V_873 * V_874 ;
struct V_863 * V_864 = & V_2 -> V_5 . V_879 ;
if ( V_2 -> V_5 . V_880 &&
F_386 ( V_864 ) &&
( V_635 & ~ V_395 ) == ( V_2 -> V_5 . V_881 & ~ V_395 ) ) {
V_401 = V_2 -> V_5 . V_881 ;
V_113 = F_371 ( V_2 , V_635 , V_401 , V_866 ) ;
} else {
V_113 = F_374 ( V_2 , V_635 , & V_401 , V_70 , V_866 ) ;
if ( V_113 < 0 )
return V_861 ;
}
if ( ! V_113 && V_878 -> V_882 ( V_2 , V_401 , V_209 , V_858 ) )
return V_859 ;
V_845 = V_878 -> V_883 ( V_2 , V_401 , V_858 , V_209 ) ;
if ( V_845 == V_858 )
return V_859 ;
V_401 += V_845 ;
V_858 -= V_845 ;
V_209 += V_845 ;
F_30 ( V_2 -> V_884 >= V_885 ) ;
V_874 = & V_2 -> V_870 [ V_2 -> V_884 ++ ] ;
V_874 -> V_401 = V_401 ;
V_874 -> V_39 = V_209 ;
V_874 -> V_100 = V_858 ;
return V_859 ;
}
static int F_387 ( struct V_863 * V_864 ,
unsigned long V_635 ,
void * V_209 , unsigned int V_858 ,
struct V_76 * V_70 ,
const struct V_877 * V_878 )
{
struct V_1 * V_2 = F_365 ( V_864 ) ;
T_6 V_401 ;
int V_886 ;
if ( V_878 -> V_887 &&
V_878 -> V_887 ( V_2 , V_209 , V_858 ) )
return V_859 ;
V_2 -> V_884 = 0 ;
if ( ( ( V_635 + V_858 - 1 ) ^ V_635 ) & V_395 ) {
int V_888 ;
V_888 = - V_635 & ~ V_395 ;
V_886 = F_385 ( V_635 , V_209 , V_888 , V_70 ,
V_2 , V_878 ) ;
if ( V_886 != V_859 )
return V_886 ;
V_635 += V_888 ;
if ( V_864 -> V_342 != V_889 )
V_635 = ( T_1 ) V_635 ;
V_209 += V_888 ;
V_858 -= V_888 ;
}
V_886 = F_385 ( V_635 , V_209 , V_858 , V_70 ,
V_2 , V_878 ) ;
if ( V_886 != V_859 )
return V_886 ;
if ( ! V_2 -> V_884 )
return V_886 ;
V_401 = V_2 -> V_870 [ 0 ] . V_401 ;
V_2 -> V_890 = 1 ;
V_2 -> V_891 = 0 ;
V_2 -> V_875 -> V_876 . V_100 = F_349 ( 8u , V_2 -> V_870 [ 0 ] . V_100 ) ;
V_2 -> V_875 -> V_876 . V_892 = V_2 -> V_893 = V_878 -> V_866 ;
V_2 -> V_875 -> V_894 = V_895 ;
V_2 -> V_875 -> V_876 . V_896 = V_401 ;
return V_878 -> V_897 ( V_2 , V_401 , V_209 , V_858 ) ;
}
static int F_388 ( struct V_863 * V_864 ,
unsigned long V_635 ,
void * V_209 ,
unsigned int V_858 ,
struct V_76 * V_70 )
{
return F_387 ( V_864 , V_635 , V_209 , V_858 ,
V_70 , & V_898 ) ;
}
static int F_389 ( struct V_863 * V_864 ,
unsigned long V_635 ,
const void * V_209 ,
unsigned int V_858 ,
struct V_76 * V_70 )
{
return F_387 ( V_864 , V_635 , ( void * ) V_209 , V_858 ,
V_70 , & V_899 ) ;
}
static int F_390 ( struct V_863 * V_864 ,
unsigned long V_635 ,
const void * V_900 ,
const void * V_901 ,
unsigned int V_858 ,
struct V_76 * V_70 )
{
struct V_1 * V_2 = F_365 ( V_864 ) ;
T_6 V_401 ;
struct V_397 * V_397 ;
char * V_902 ;
bool V_903 ;
if ( V_858 > 8 || ( V_858 & ( V_858 - 1 ) ) )
goto V_904;
V_401 = F_361 ( V_2 , V_635 , NULL ) ;
if ( V_401 == V_105 ||
( V_401 & V_395 ) == V_867 )
goto V_904;
if ( ( ( V_401 + V_858 - 1 ) & V_395 ) != ( V_401 & V_395 ) )
goto V_904;
V_397 = F_391 ( V_2 , V_401 >> V_111 ) ;
if ( F_392 ( V_397 ) )
goto V_904;
V_902 = F_393 ( V_397 ) ;
V_902 += F_394 ( V_401 ) ;
switch ( V_858 ) {
case 1 :
V_903 = F_395 ( T_13 , V_902 , V_900 , V_901 ) ;
break;
case 2 :
V_903 = F_395 ( V_905 , V_902 , V_900 , V_901 ) ;
break;
case 4 :
V_903 = F_395 ( T_1 , V_902 , V_900 , V_901 ) ;
break;
case 8 :
V_903 = F_396 ( V_902 , V_900 , V_901 ) ;
break;
default:
F_27 () ;
}
F_397 ( V_902 ) ;
F_398 ( V_397 ) ;
if ( ! V_903 )
return V_906 ;
F_399 ( V_2 , V_401 >> V_111 ) ;
F_378 ( V_2 , V_401 , V_901 , V_858 ) ;
return V_859 ;
V_904:
F_400 ( V_907 L_20 ) ;
return F_389 ( V_864 , V_635 , V_901 , V_858 , V_70 ) ;
}
static int F_401 ( struct V_1 * V_2 , void * V_908 )
{
int V_126 = 0 , V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 . V_909 . V_776 ; V_3 ++ ) {
if ( V_2 -> V_5 . V_909 . V_910 )
V_126 = F_354 ( V_2 , V_911 , V_2 -> V_5 . V_909 . V_912 ,
V_2 -> V_5 . V_909 . V_513 , V_908 ) ;
else
V_126 = F_351 ( V_2 , V_911 ,
V_2 -> V_5 . V_909 . V_912 , V_2 -> V_5 . V_909 . V_513 ,
V_908 ) ;
if ( V_126 )
break;
V_908 += V_2 -> V_5 . V_909 . V_513 ;
}
return V_126 ;
}
static int F_402 ( struct V_1 * V_2 , int V_513 ,
unsigned short V_912 , void * V_209 ,
unsigned int V_776 , bool V_910 )
{
V_2 -> V_5 . V_909 . V_912 = V_912 ;
V_2 -> V_5 . V_909 . V_910 = V_910 ;
V_2 -> V_5 . V_909 . V_776 = V_776 ;
V_2 -> V_5 . V_909 . V_513 = V_513 ;
if ( ! F_401 ( V_2 , V_2 -> V_5 . V_913 ) ) {
V_2 -> V_5 . V_909 . V_776 = 0 ;
return 1 ;
}
V_2 -> V_875 -> V_894 = V_914 ;
V_2 -> V_875 -> V_915 . V_916 = V_910 ? V_917 : V_918 ;
V_2 -> V_875 -> V_915 . V_513 = V_513 ;
V_2 -> V_875 -> V_915 . V_919 = V_920 * V_112 ;
V_2 -> V_875 -> V_915 . V_776 = V_776 ;
V_2 -> V_875 -> V_915 . V_912 = V_912 ;
return 0 ;
}
static int F_403 ( struct V_863 * V_864 ,
int V_513 , unsigned short V_912 , void * V_209 ,
unsigned int V_776 )
{
struct V_1 * V_2 = F_365 ( V_864 ) ;
int V_113 ;
if ( V_2 -> V_5 . V_909 . V_776 )
goto V_921;
memset ( V_2 -> V_5 . V_913 , 0 , V_513 * V_776 ) ;
V_113 = F_402 ( V_2 , V_513 , V_912 , V_209 , V_776 , true ) ;
if ( V_113 ) {
V_921:
memcpy ( V_209 , V_2 -> V_5 . V_913 , V_513 * V_776 ) ;
F_404 ( V_922 , V_912 , V_513 , V_776 , V_2 -> V_5 . V_913 ) ;
V_2 -> V_5 . V_909 . V_776 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_405 ( struct V_863 * V_864 ,
int V_513 , unsigned short V_912 ,
const void * V_209 , unsigned int V_776 )
{
struct V_1 * V_2 = F_365 ( V_864 ) ;
memcpy ( V_2 -> V_5 . V_913 , V_209 , V_513 * V_776 ) ;
F_404 ( V_923 , V_912 , V_513 , V_776 , V_2 -> V_5 . V_913 ) ;
return F_402 ( V_2 , V_513 , V_912 , ( void * ) V_209 , V_776 , false ) ;
}
static unsigned long F_406 ( struct V_1 * V_2 , int V_851 )
{
return V_92 -> F_406 ( V_2 , V_851 ) ;
}
static void F_407 ( struct V_863 * V_864 , V_188 V_83 )
{
F_408 ( F_365 ( V_864 ) , V_83 ) ;
}
static int F_409 ( struct V_1 * V_2 )
{
if ( ! F_247 ( V_2 ) )
return V_859 ;
if ( V_92 -> V_601 () ) {
int V_24 = F_180 () ;
F_249 ( V_24 , V_2 -> V_5 . V_602 ) ;
F_410 ( V_2 -> V_5 . V_602 ,
F_245 , NULL , 1 ) ;
F_183 () ;
F_411 ( V_2 -> V_5 . V_602 ) ;
} else
F_246 () ;
return V_859 ;
}
int F_412 ( struct V_1 * V_2 )
{
F_409 ( V_2 ) ;
return F_39 ( V_2 ) ;
}
static void F_413 ( struct V_863 * V_864 )
{
F_409 ( F_365 ( V_864 ) ) ;
}
static int F_414 ( struct V_863 * V_864 , int V_94 ,
unsigned long * V_672 )
{
return F_98 ( F_365 ( V_864 ) , V_94 , V_672 ) ;
}
static int F_415 ( struct V_863 * V_864 , int V_94 ,
unsigned long V_23 )
{
return F_96 ( F_365 ( V_864 ) , V_94 , V_23 ) ;
}
static T_2 F_416 ( T_2 V_924 , T_1 V_925 )
{
return ( V_924 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_925 ;
}
static unsigned long F_417 ( struct V_863 * V_864 , int V_926 )
{
struct V_1 * V_2 = F_365 ( V_864 ) ;
unsigned long V_23 ;
switch ( V_926 ) {
case 0 :
V_23 = F_65 ( V_2 ) ;
break;
case 2 :
V_23 = V_2 -> V_5 . V_84 ;
break;
case 3 :
V_23 = F_63 ( V_2 ) ;
break;
case 4 :
V_23 = F_82 ( V_2 ) ;
break;
case 8 :
V_23 = F_90 ( V_2 ) ;
break;
default:
F_418 ( L_21 , V_274 , V_926 ) ;
return 0 ;
}
return V_23 ;
}
static int F_419 ( struct V_863 * V_864 , int V_926 , V_188 V_209 )
{
struct V_1 * V_2 = F_365 ( V_864 ) ;
int V_927 = 0 ;
switch ( V_926 ) {
case 0 :
V_927 = F_64 ( V_2 , F_416 ( F_65 ( V_2 ) , V_209 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_84 = V_209 ;
break;
case 3 :
V_927 = F_83 ( V_2 , V_209 ) ;
break;
case 4 :
V_927 = F_81 ( V_2 , F_416 ( F_82 ( V_2 ) , V_209 ) ) ;
break;
case 8 :
V_927 = F_87 ( V_2 , V_209 ) ;
break;
default:
F_418 ( L_21 , V_274 , V_926 ) ;
V_927 = - 1 ;
}
return V_927 ;
}
static int F_420 ( struct V_863 * V_864 )
{
return V_92 -> V_93 ( F_365 ( V_864 ) ) ;
}
static void F_421 ( struct V_863 * V_864 , struct V_928 * V_929 )
{
V_92 -> V_930 ( F_365 ( V_864 ) , V_929 ) ;
}
static void F_422 ( struct V_863 * V_864 , struct V_928 * V_929 )
{
V_92 -> V_931 ( F_365 ( V_864 ) , V_929 ) ;
}
static void F_423 ( struct V_863 * V_864 , struct V_928 * V_929 )
{
V_92 -> V_932 ( F_365 ( V_864 ) , V_929 ) ;
}
static void F_424 ( struct V_863 * V_864 , struct V_928 * V_929 )
{
V_92 -> V_933 ( F_365 ( V_864 ) , V_929 ) ;
}
static unsigned long F_425 (
struct V_863 * V_864 , int V_851 )
{
return F_406 ( F_365 ( V_864 ) , V_851 ) ;
}
static bool F_426 ( struct V_863 * V_864 , V_905 * V_934 ,
struct V_935 * V_936 , T_1 * V_937 ,
int V_851 )
{
struct V_849 V_850 ;
F_357 ( F_365 ( V_864 ) , & V_850 , V_851 ) ;
* V_934 = V_850 . V_934 ;
if ( V_850 . V_938 ) {
memset ( V_936 , 0 , sizeof( * V_936 ) ) ;
if ( V_937 )
* V_937 = 0 ;
return false ;
}
if ( V_850 . V_939 )
V_850 . V_940 >>= 12 ;
F_427 ( V_936 , V_850 . V_940 ) ;
F_428 ( V_936 , ( unsigned long ) V_850 . V_240 ) ;
#ifdef F_66
if ( V_937 )
* V_937 = V_850 . V_240 >> 32 ;
#endif
V_936 -> type = V_850 . type ;
V_936 -> V_611 = V_850 . V_611 ;
V_936 -> V_941 = V_850 . V_941 ;
V_936 -> V_942 = V_850 . V_943 ;
V_936 -> V_944 = V_850 . V_944 ;
V_936 -> V_945 = V_850 . V_945 ;
V_936 -> V_946 = V_850 . V_195 ;
V_936 -> V_939 = V_850 . V_939 ;
return true ;
}
static void F_429 ( struct V_863 * V_864 , V_905 V_934 ,
struct V_935 * V_936 , T_1 V_937 ,
int V_851 )
{
struct V_1 * V_2 = F_365 ( V_864 ) ;
struct V_849 V_850 ;
V_850 . V_934 = V_934 ;
V_850 . V_240 = F_430 ( V_936 ) ;
#ifdef F_66
V_850 . V_240 |= ( ( T_2 ) V_937 ) << 32 ;
#endif
V_850 . V_940 = F_431 ( V_936 ) ;
if ( V_936 -> V_939 )
V_850 . V_940 = ( V_850 . V_940 << 12 ) | 0xfff ;
V_850 . type = V_936 -> type ;
V_850 . V_941 = V_936 -> V_941 ;
V_850 . V_195 = V_936 -> V_946 ;
V_850 . V_611 = V_936 -> V_611 ;
V_850 . V_945 = V_936 -> V_945 ;
V_850 . V_939 = V_936 -> V_939 ;
V_850 . V_944 = V_936 -> V_944 ;
V_850 . V_943 = V_936 -> V_942 ;
V_850 . V_938 = ! V_850 . V_943 ;
V_850 . V_947 = 0 ;
F_356 ( V_2 , & V_850 , V_851 ) ;
return;
}
static int F_432 ( struct V_863 * V_864 ,
T_1 V_948 , T_2 * V_485 )
{
struct V_33 V_22 ;
int V_126 ;
V_22 . V_152 = V_948 ;
V_22 . V_42 = false ;
V_126 = F_111 ( F_365 ( V_864 ) , & V_22 ) ;
if ( V_126 )
return V_126 ;
* V_485 = V_22 . V_39 ;
return 0 ;
}
static int F_433 ( struct V_863 * V_864 ,
T_1 V_948 , T_2 V_39 )
{
struct V_33 V_22 ;
V_22 . V_39 = V_39 ;
V_22 . V_152 = V_948 ;
V_22 . V_42 = false ;
return F_106 ( F_365 ( V_864 ) , & V_22 ) ;
}
static T_2 F_434 ( struct V_863 * V_864 )
{
struct V_1 * V_2 = F_365 ( V_864 ) ;
return V_2 -> V_5 . V_440 ;
}
static void F_435 ( struct V_863 * V_864 , T_2 V_440 )
{
struct V_1 * V_2 = F_365 ( V_864 ) ;
V_2 -> V_5 . V_440 = V_440 ;
}
static int F_436 ( struct V_863 * V_864 ,
T_1 V_949 )
{
return F_437 ( F_365 ( V_864 ) , V_949 ) ;
}
static int F_438 ( struct V_863 * V_864 ,
T_1 V_949 , T_2 * V_485 )
{
return F_101 ( F_365 ( V_864 ) , V_949 , V_485 ) ;
}
static void F_439 ( struct V_863 * V_864 )
{
F_365 ( V_864 ) -> V_5 . V_950 = 1 ;
}
static void F_440 ( struct V_863 * V_864 )
{
F_441 () ;
F_442 ( F_365 ( V_864 ) ) ;
}
static void F_443 ( struct V_863 * V_864 )
{
F_444 () ;
}
static int F_445 ( struct V_863 * V_864 ,
struct V_951 * V_952 ,
enum V_953 V_954 )
{
return V_92 -> V_955 ( F_365 ( V_864 ) , V_952 , V_954 ) ;
}
static bool F_446 ( struct V_863 * V_864 ,
T_1 * V_956 , T_1 * V_957 , T_1 * V_214 , T_1 * V_685 , bool V_958 )
{
return V_718 ( F_365 ( V_864 ) , V_956 , V_957 , V_214 , V_685 , V_958 ) ;
}
static V_188 F_447 ( struct V_863 * V_864 , unsigned V_959 )
{
return F_100 ( F_365 ( V_864 ) , V_959 ) ;
}
static void F_448 ( struct V_863 * V_864 , unsigned V_959 , V_188 V_209 )
{
F_102 ( F_365 ( V_864 ) , V_959 , V_209 ) ;
}
static void F_449 ( struct V_863 * V_864 , bool V_647 )
{
V_92 -> V_665 ( F_365 ( V_864 ) , V_647 ) ;
}
static unsigned F_450 ( struct V_863 * V_864 )
{
return F_365 ( V_864 ) -> V_5 . V_654 ;
}
static void F_451 ( struct V_863 * V_864 , unsigned V_960 )
{
F_286 ( F_365 ( V_864 ) , V_960 ) ;
}
static void F_452 ( struct V_1 * V_2 , T_1 V_29 )
{
T_1 V_961 = V_92 -> V_643 ( V_2 ) ;
if ( V_961 & V_29 )
V_29 = 0 ;
if ( F_165 ( V_961 || V_29 ) ) {
V_92 -> V_664 ( V_2 , V_29 ) ;
if ( ! V_29 )
F_32 ( V_69 , V_2 ) ;
}
}
static bool F_453 ( struct V_1 * V_2 )
{
struct V_863 * V_864 = & V_2 -> V_5 . V_879 ;
if ( V_864 -> V_70 . V_43 == V_44 )
return F_43 ( V_2 , & V_864 -> V_70 ) ;
if ( V_864 -> V_70 . V_962 )
F_42 ( V_2 , V_864 -> V_70 . V_43 ,
V_864 -> V_70 . V_64 ) ;
else
F_35 ( V_2 , V_864 -> V_70 . V_43 ) ;
return false ;
}
static void F_454 ( struct V_1 * V_2 )
{
struct V_863 * V_864 = & V_2 -> V_5 . V_879 ;
int V_139 , V_140 ;
V_92 -> V_141 ( V_2 , & V_139 , & V_140 ) ;
V_864 -> V_963 = F_455 ( V_2 ) ;
V_864 -> V_964 = ( V_864 -> V_963 & V_965 ) != 0 ;
V_864 -> V_966 = F_456 ( V_2 ) ;
V_864 -> V_342 = ( ! F_33 ( V_2 ) ) ? V_967 :
( V_864 -> V_963 & V_968 ) ? V_969 :
( V_140 && F_60 ( V_2 ) ) ? V_889 :
V_139 ? V_970 :
V_971 ;
F_186 ( V_972 != V_973 ) ;
F_186 ( V_667 != V_974 ) ;
F_186 ( V_655 != V_975 ) ;
F_457 ( V_864 ) ;
V_2 -> V_5 . V_976 = false ;
}
int F_458 ( struct V_1 * V_2 , int V_615 , int V_977 )
{
struct V_863 * V_864 = & V_2 -> V_5 . V_879 ;
int V_113 ;
F_454 ( V_2 ) ;
V_864 -> V_978 = 2 ;
V_864 -> V_979 = 2 ;
V_864 -> V_980 = V_864 -> V_966 + V_977 ;
V_113 = F_459 ( V_864 , V_615 ) ;
if ( V_113 != V_859 )
return V_981 ;
V_864 -> V_966 = V_864 -> V_980 ;
F_460 ( V_2 , V_864 -> V_966 ) ;
F_461 ( V_2 , V_864 -> V_963 ) ;
if ( V_615 == V_53 )
V_2 -> V_5 . V_646 = 0 ;
else
V_2 -> V_5 . V_640 . V_71 = false ;
return V_982 ;
}
static int F_462 ( struct V_1 * V_2 )
{
int V_126 = V_982 ;
++ V_2 -> V_78 . V_983 ;
F_463 ( V_2 ) ;
if ( ! F_41 ( V_2 ) && V_92 -> V_93 ( V_2 ) == 0 ) {
V_2 -> V_875 -> V_894 = V_984 ;
V_2 -> V_875 -> V_985 . V_986 = V_987 ;
V_2 -> V_875 -> V_985 . V_988 = 0 ;
V_126 = V_981 ;
}
F_35 ( V_2 , V_96 ) ;
return V_126 ;
}
static bool F_464 ( struct V_1 * V_2 , T_15 V_84 ,
bool V_989 ,
int V_990 )
{
T_6 V_401 = V_84 ;
T_16 V_991 ;
if ( V_990 & V_992 )
return false ;
if ( ! V_2 -> V_5 . V_88 . V_993 ) {
V_401 = F_361 ( V_2 , V_84 , NULL ) ;
if ( V_401 == V_105 )
return true ;
}
V_991 = F_465 ( V_2 -> V_144 , F_53 ( V_401 ) ) ;
if ( F_466 ( V_991 ) )
return false ;
F_467 ( V_991 ) ;
if ( V_2 -> V_5 . V_88 . V_993 ) {
unsigned int V_994 ;
F_155 ( & V_2 -> V_144 -> V_995 ) ;
V_994 = V_2 -> V_144 -> V_5 . V_994 ;
F_156 ( & V_2 -> V_144 -> V_995 ) ;
if ( V_994 )
F_468 ( V_2 -> V_144 , F_53 ( V_401 ) ) ;
return true ;
}
F_468 ( V_2 -> V_144 , F_53 ( V_401 ) ) ;
return ! V_989 ;
}
static bool F_469 ( struct V_863 * V_864 ,
unsigned long V_84 , int V_990 )
{
struct V_1 * V_2 = F_365 ( V_864 ) ;
unsigned long V_996 , V_997 , V_401 = V_84 ;
V_996 = V_2 -> V_5 . V_996 ;
V_997 = V_2 -> V_5 . V_997 ;
V_2 -> V_5 . V_996 = V_2 -> V_5 . V_997 = 0 ;
if ( ! ( V_990 & V_998 ) )
return false ;
if ( F_470 ( V_864 ) )
return false ;
if ( V_864 -> V_966 == V_996 && V_997 == V_84 )
return false ;
V_2 -> V_5 . V_996 = V_864 -> V_966 ;
V_2 -> V_5 . V_997 = V_84 ;
if ( ! V_2 -> V_5 . V_88 . V_993 )
V_401 = F_361 ( V_2 , V_84 , NULL ) ;
F_468 ( V_2 -> V_144 , F_53 ( V_401 ) ) ;
return true ;
}
static void F_471 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_654 & V_667 ) ) {
F_472 ( V_2 -> V_310 , V_2 -> V_5 . V_440 , false ) ;
F_32 ( V_69 , V_2 ) ;
}
F_69 ( V_2 ) ;
}
static void F_286 ( struct V_1 * V_2 , unsigned V_960 )
{
unsigned V_125 = V_2 -> V_5 . V_654 ^ V_960 ;
V_2 -> V_5 . V_654 = V_960 ;
if ( V_125 & V_667 )
F_471 ( V_2 ) ;
}
static int F_473 ( unsigned long V_635 , T_1 type , T_1 V_200 ,
unsigned long * V_195 )
{
T_1 V_199 = 0 ;
int V_3 ;
T_1 V_999 , V_1000 ;
V_999 = V_200 ;
V_1000 = V_200 >> 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ , V_999 >>= 2 , V_1000 >>= 4 )
if ( ( V_999 & 3 ) && ( V_1000 & 15 ) == type && V_195 [ V_3 ] == V_635 )
V_199 |= ( 1 << V_3 ) ;
return V_199 ;
}
static void F_474 ( struct V_1 * V_2 , int * V_126 )
{
struct V_1001 * V_1001 = V_2 -> V_875 ;
if ( V_2 -> V_191 & V_1002 ) {
V_1001 -> V_1003 . V_5 . V_199 = V_1004 | V_206 | V_208 ;
V_1001 -> V_1003 . V_5 . V_1005 = V_2 -> V_5 . V_1006 ;
V_1001 -> V_1003 . V_5 . V_70 = V_55 ;
V_1001 -> V_894 = V_1007 ;
* V_126 = V_1008 ;
} else {
V_2 -> V_5 . V_199 &= ~ 15 ;
V_2 -> V_5 . V_199 |= V_1004 | V_208 ;
F_35 ( V_2 , V_55 ) ;
}
}
int F_39 ( struct V_1 * V_2 )
{
unsigned long V_1009 = V_92 -> V_1010 ( V_2 ) ;
int V_126 = V_982 ;
V_92 -> V_1011 ( V_2 ) ;
if ( F_165 ( V_1009 & V_965 ) )
F_474 ( V_2 , & V_126 ) ;
return V_126 == V_982 ;
}
static bool F_475 ( struct V_1 * V_2 , int * V_126 )
{
if ( F_165 ( V_2 -> V_191 & V_192 ) &&
( V_2 -> V_5 . V_201 & V_204 ) ) {
struct V_1001 * V_1001 = V_2 -> V_875 ;
unsigned long V_966 = F_476 ( V_2 ) ;
T_1 V_199 = F_473 ( V_966 , 0 ,
V_2 -> V_5 . V_201 ,
V_2 -> V_5 . V_194 ) ;
if ( V_199 != 0 ) {
V_1001 -> V_1003 . V_5 . V_199 = V_199 | V_206 | V_208 ;
V_1001 -> V_1003 . V_5 . V_1005 = V_966 ;
V_1001 -> V_1003 . V_5 . V_70 = V_55 ;
V_1001 -> V_894 = V_1007 ;
* V_126 = V_1008 ;
return true ;
}
}
if ( F_165 ( V_2 -> V_5 . V_200 & V_204 ) &&
! ( F_455 ( V_2 ) & V_1012 ) ) {
unsigned long V_966 = F_476 ( V_2 ) ;
T_1 V_199 = F_473 ( V_966 , 0 ,
V_2 -> V_5 . V_200 ,
V_2 -> V_5 . V_195 ) ;
if ( V_199 != 0 ) {
V_2 -> V_5 . V_199 &= ~ 15 ;
V_2 -> V_5 . V_199 |= V_199 | V_208 ;
F_35 ( V_2 , V_55 ) ;
* V_126 = V_982 ;
return true ;
}
}
return false ;
}
int F_477 ( struct V_1 * V_2 ,
unsigned long V_84 ,
int V_990 ,
void * V_1013 ,
int V_1014 )
{
int V_126 ;
struct V_863 * V_864 = & V_2 -> V_5 . V_879 ;
bool V_511 = true ;
bool V_1015 = V_2 -> V_5 . V_989 ;
V_2 -> V_5 . V_989 = false ;
F_478 ( V_2 ) ;
if ( ! ( V_990 & V_1016 ) ) {
F_454 ( V_2 ) ;
if ( F_475 ( V_2 , & V_126 ) )
return V_126 ;
V_864 -> V_1017 = 0 ;
V_864 -> V_1018 = false ;
V_864 -> V_70 . V_43 = - 1 ;
V_864 -> V_1019 = false ;
V_864 -> V_1020 = V_990 & V_1021 ;
V_126 = F_479 ( V_864 , V_1013 , V_1014 ) ;
F_480 ( V_2 ) ;
++ V_2 -> V_78 . V_1022 ;
if ( V_126 != V_1023 ) {
if ( V_990 & V_1021 )
return V_981 ;
if ( F_464 ( V_2 , V_84 , V_1015 ,
V_990 ) )
return V_982 ;
if ( V_990 & V_1024 )
return V_981 ;
return F_462 ( V_2 ) ;
}
}
if ( V_990 & V_1024 ) {
F_460 ( V_2 , V_864 -> V_980 ) ;
if ( V_864 -> V_963 & V_1012 )
F_461 ( V_2 , V_864 -> V_963 & ~ V_1012 ) ;
return V_982 ;
}
if ( F_469 ( V_864 , V_84 , V_990 ) )
return V_982 ;
if ( V_2 -> V_5 . V_976 ) {
V_2 -> V_5 . V_976 = false ;
F_481 ( V_864 ) ;
}
V_1025:
V_864 -> V_70 . V_83 = V_84 ;
V_126 = F_482 ( V_864 ) ;
if ( V_126 == V_1026 )
return V_982 ;
if ( V_126 == V_1027 ) {
if ( F_464 ( V_2 , V_84 , V_1015 ,
V_990 ) )
return V_982 ;
return F_462 ( V_2 ) ;
}
if ( V_864 -> V_1018 ) {
V_126 = V_982 ;
if ( F_453 ( V_2 ) )
return V_126 ;
} else if ( V_2 -> V_5 . V_909 . V_776 ) {
if ( ! V_2 -> V_5 . V_909 . V_910 ) {
V_2 -> V_5 . V_909 . V_776 = 0 ;
} else {
V_511 = false ;
V_2 -> V_5 . V_1028 = V_1029 ;
}
V_126 = V_1008 ;
} else if ( V_2 -> V_890 ) {
if ( ! V_2 -> V_893 )
V_511 = false ;
V_126 = V_1008 ;
V_2 -> V_5 . V_1028 = V_1030 ;
} else if ( V_126 == V_1031 )
goto V_1025;
else
V_126 = V_982 ;
if ( V_511 ) {
unsigned long V_1009 = V_92 -> V_1010 ( V_2 ) ;
F_452 ( V_2 , V_864 -> V_1017 ) ;
V_2 -> V_5 . V_1032 = false ;
F_460 ( V_2 , V_864 -> V_966 ) ;
if ( V_126 == V_982 &&
( V_864 -> V_964 || ( V_2 -> V_191 & V_1002 ) ) )
F_474 ( V_2 , & V_126 ) ;
if ( ! V_864 -> V_1018 ||
F_29 ( V_864 -> V_70 . V_43 ) == V_58 )
F_483 ( V_2 , V_864 -> V_963 ) ;
if ( F_165 ( ( V_864 -> V_963 & ~ V_1009 ) & V_1033 ) )
F_32 ( V_69 , V_2 ) ;
} else
V_2 -> V_5 . V_1032 = true ;
return V_126 ;
}
int F_484 ( struct V_1 * V_2 , int V_513 , unsigned short V_912 )
{
unsigned long V_209 = F_100 ( V_2 , V_216 ) ;
int V_113 = F_405 ( & V_2 -> V_5 . V_879 ,
V_513 , V_912 , & V_209 , 1 ) ;
V_2 -> V_5 . V_909 . V_776 = 0 ;
return V_113 ;
}
static int F_485 ( struct V_1 * V_2 )
{
unsigned long V_209 ;
F_15 ( V_2 -> V_5 . V_909 . V_776 != 1 ) ;
V_209 = ( V_2 -> V_5 . V_909 . V_513 < 4 ) ? F_100 ( V_2 , V_216 )
: 0 ;
F_403 ( & V_2 -> V_5 . V_879 , V_2 -> V_5 . V_909 . V_513 ,
V_2 -> V_5 . V_909 . V_912 , & V_209 , 1 ) ;
F_102 ( V_2 , V_216 , V_209 ) ;
return 1 ;
}
int F_486 ( struct V_1 * V_2 , int V_513 , unsigned short V_912 )
{
unsigned long V_209 ;
int V_113 ;
V_209 = ( V_513 < 4 ) ? F_100 ( V_2 , V_216 ) : 0 ;
V_113 = F_403 ( & V_2 -> V_5 . V_879 , V_513 , V_912 ,
& V_209 , 1 ) ;
if ( V_113 ) {
F_102 ( V_2 , V_216 , V_209 ) ;
return V_113 ;
}
V_2 -> V_5 . V_1028 = F_485 ;
return 0 ;
}
static int F_487 ( unsigned int V_24 )
{
F_488 ( V_356 , 0 ) ;
return 0 ;
}
static void F_489 ( void * V_39 )
{
struct V_1034 * V_1035 = V_39 ;
unsigned long V_275 = 0 ;
if ( V_39 )
V_275 = V_1035 -> V_901 ;
else if ( ! F_242 ( V_1036 ) )
V_275 = F_490 ( F_491 () ) ;
if ( ! V_275 )
V_275 = V_284 ;
F_488 ( V_356 , V_275 ) ;
}
static int F_492 ( struct V_1037 * V_1038 , unsigned long V_209 ,
void * V_39 )
{
struct V_1034 * V_1035 = V_39 ;
struct V_144 * V_144 ;
struct V_1 * V_2 ;
int V_3 , V_1039 = 0 ;
if ( V_209 == V_1040 && V_1035 -> V_900 > V_1035 -> V_901 )
return 0 ;
if ( V_209 == V_1041 && V_1035 -> V_900 < V_1035 -> V_901 )
return 0 ;
F_250 ( V_1035 -> V_24 , F_489 , V_1035 , 1 ) ;
F_155 ( & V_1042 ) ;
F_493 (kvm, &vm_list, vm_list) {
F_177 (i, vcpu, kvm) {
if ( V_2 -> V_24 != V_1035 -> V_24 )
continue;
F_32 ( V_351 , V_2 ) ;
if ( V_2 -> V_24 != F_10 () )
V_1039 = 1 ;
}
}
F_156 ( & V_1042 ) ;
if ( V_1035 -> V_900 < V_1035 -> V_901 && V_1039 ) {
F_250 ( V_1035 -> V_24 , F_489 , V_1035 , 1 ) ;
}
return 0 ;
}
static int F_494 ( unsigned int V_24 )
{
F_489 ( NULL ) ;
return 0 ;
}
static void F_495 ( void )
{
V_1043 = V_284 ;
if ( ! F_242 ( V_1036 ) ) {
#ifdef F_496
struct V_1044 V_1045 ;
int V_24 ;
memset ( & V_1045 , 0 , sizeof( V_1045 ) ) ;
V_24 = F_180 () ;
F_497 ( & V_1045 , V_24 ) ;
if ( V_1045 . V_1046 . V_1047 )
V_1043 = V_1045 . V_1046 . V_1047 ;
F_183 () ;
#endif
F_498 ( & V_1048 ,
V_1049 ) ;
}
F_128 ( L_22 , V_1043 ) ;
F_499 ( V_1050 , L_23 ,
F_494 , F_487 ) ;
}
int F_500 ( void )
{
return F_181 ( V_1051 ) != NULL ;
}
static int F_501 ( void )
{
int V_1052 = 3 ;
if ( F_181 ( V_1051 ) )
V_1052 = V_92 -> V_93 ( F_181 ( V_1051 ) ) ;
return V_1052 != 0 ;
}
static unsigned long F_502 ( void )
{
unsigned long V_1053 = 0 ;
if ( F_181 ( V_1051 ) )
V_1053 = F_456 ( F_181 ( V_1051 ) ) ;
return V_1053 ;
}
void F_503 ( struct V_1 * V_2 )
{
F_488 ( V_1051 , V_2 ) ;
}
void F_504 ( struct V_1 * V_2 )
{
F_488 ( V_1051 , NULL ) ;
}
static void F_505 ( void )
{
T_2 V_29 ;
int V_1054 = V_1055 . V_1056 ;
V_29 = F_85 ( V_1054 , 51 ) ;
V_29 |= 1ull ;
#ifdef F_66
if ( V_1054 == 52 )
V_29 &= ~ 1ull ;
#endif
F_506 ( V_29 , V_29 ) ;
}
static void F_507 ( struct V_369 * V_370 )
{
struct V_144 * V_144 ;
struct V_1 * V_2 ;
int V_3 ;
F_155 ( & V_1042 ) ;
F_493 (kvm, &vm_list, vm_list)
F_177 (i, vcpu, kvm)
F_32 ( V_309 , V_2 ) ;
F_172 ( & V_349 , 0 ) ;
F_156 ( & V_1042 ) ;
}
static int F_508 ( struct V_1037 * V_1038 , unsigned long V_1057 ,
void * V_1058 )
{
struct V_236 * V_304 = & V_236 ;
struct V_234 * V_235 = V_1058 ;
F_113 ( V_235 ) ;
if ( V_304 -> clock . V_243 != V_308 &&
F_139 ( & V_349 ) != 0 )
F_509 ( V_1059 , & V_1060 ) ;
return 0 ;
}
int F_510 ( void * V_1061 )
{
int V_126 ;
struct V_92 * V_878 = V_1061 ;
if ( V_92 ) {
F_12 ( V_27 L_24 ) ;
V_126 = - V_619 ;
goto V_118;
}
if ( ! V_878 -> V_1062 () ) {
F_12 ( V_27 L_25 ) ;
V_126 = - V_1063 ;
goto V_118;
}
if ( V_878 -> V_1064 () ) {
F_12 ( V_27 L_26 ) ;
V_126 = - V_1063 ;
goto V_118;
}
V_126 = - V_399 ;
V_26 = F_511 ( struct V_11 ) ;
if ( ! V_26 ) {
F_12 ( V_27 L_27 ) ;
goto V_118;
}
V_126 = F_512 () ;
if ( V_126 )
goto V_1065;
F_505 () ;
V_92 = V_878 ;
F_513 ( V_1066 , V_1067 ,
V_1068 , V_1069 , 0 ,
V_119 , 0 , V_1070 ) ;
F_495 () ;
F_514 ( & V_1071 ) ;
if ( F_242 ( V_174 ) )
V_151 = F_515 ( V_149 ) ;
F_516 () ;
#ifdef F_66
F_517 ( & V_1072 ) ;
#endif
return 0 ;
V_1065:
F_518 ( V_26 ) ;
V_118:
return V_126 ;
}
void F_519 ( void )
{
F_520 () ;
F_521 ( & V_1071 ) ;
if ( ! F_242 ( V_1036 ) )
F_522 ( & V_1048 ,
V_1049 ) ;
F_523 ( V_1050 ) ;
#ifdef F_66
F_524 ( & V_1072 ) ;
#endif
V_92 = NULL ;
F_525 () ;
F_518 ( V_26 ) ;
}
int F_526 ( struct V_1 * V_2 )
{
++ V_2 -> V_78 . V_1073 ;
if ( F_88 ( V_2 ) ) {
V_2 -> V_5 . V_662 = V_1074 ;
return 1 ;
} else {
V_2 -> V_875 -> V_894 = V_1075 ;
return 0 ;
}
}
int F_527 ( struct V_1 * V_2 )
{
int V_113 = F_39 ( V_2 ) ;
return F_526 ( V_2 ) && V_113 ;
}
static int F_528 ( struct V_1 * V_2 , T_6 V_1076 ,
unsigned long V_1077 )
{
struct V_1078 V_1079 ;
struct V_343 V_260 ;
T_2 V_1080 ;
int V_113 ;
if ( V_1077 != V_1081 )
return - V_1082 ;
if ( F_170 ( & V_260 , & V_1080 ) == false )
return - V_1082 ;
V_1079 . V_261 = V_260 . V_262 ;
V_1079 . V_263 = V_260 . V_264 ;
V_1079 . V_298 = F_147 ( V_2 , V_1080 ) ;
V_1079 . V_15 = 0 ;
V_113 = 0 ;
if ( F_121 ( V_2 -> V_144 , V_1076 , & V_1079 ,
sizeof( struct V_1078 ) ) )
V_113 = - V_1083 ;
return V_113 ;
}
static void F_529 ( struct V_144 * V_144 , unsigned long V_15 , int V_1084 )
{
struct V_1085 V_1086 ;
V_1086 . V_1087 = 0 ;
V_1086 . V_1088 = 0 ;
V_1086 . V_792 = 0 ;
V_1086 . V_1089 = V_1084 ;
V_1086 . V_1090 = false ;
V_1086 . V_1091 = V_1092 ;
F_530 ( V_144 , NULL , & V_1086 , NULL ) ;
}
void F_531 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_613 = false ;
V_92 -> V_1093 ( V_2 ) ;
}
int F_532 ( struct V_1 * V_2 )
{
unsigned long V_18 , V_1094 , V_1095 , V_1096 , V_1097 , V_113 ;
int V_1098 , V_126 ;
V_126 = F_39 ( V_2 ) ;
if ( F_533 ( V_2 -> V_144 ) )
return F_534 ( V_2 ) ;
V_18 = F_100 ( V_2 , V_216 ) ;
V_1094 = F_100 ( V_2 , V_1099 ) ;
V_1095 = F_100 ( V_2 , V_215 ) ;
V_1096 = F_100 ( V_2 , V_217 ) ;
V_1097 = F_100 ( V_2 , V_1100 ) ;
F_535 ( V_18 , V_1094 , V_1095 , V_1096 , V_1097 ) ;
V_1098 = F_536 ( V_2 ) ;
if ( ! V_1098 ) {
V_18 &= 0xFFFFFFFF ;
V_1094 &= 0xFFFFFFFF ;
V_1095 &= 0xFFFFFFFF ;
V_1096 &= 0xFFFFFFFF ;
V_1097 &= 0xFFFFFFFF ;
}
if ( V_92 -> V_93 ( V_2 ) != 0 ) {
V_113 = - V_1101 ;
goto V_118;
}
switch ( V_18 ) {
case V_1102 :
V_113 = 0 ;
break;
case V_1103 :
F_529 ( V_2 -> V_144 , V_1094 , V_1095 ) ;
V_113 = 0 ;
break;
#ifdef F_66
case V_1104 :
V_113 = F_528 ( V_2 , V_1094 , V_1095 ) ;
break;
#endif
default:
V_113 = - V_1105 ;
break;
}
V_118:
if ( ! V_1098 )
V_113 = ( T_1 ) V_113 ;
F_102 ( V_2 , V_216 , V_113 ) ;
++ V_2 -> V_78 . V_1106 ;
return V_126 ;
}
static int F_537 ( struct V_863 * V_864 )
{
struct V_1 * V_2 = F_365 ( V_864 ) ;
char V_1107 [ 3 ] ;
unsigned long V_1108 = F_456 ( V_2 ) ;
V_92 -> V_1109 ( V_2 , V_1107 ) ;
return F_389 ( V_864 , V_1108 , V_1107 , 3 ,
& V_864 -> V_70 ) ;
}
static int F_538 ( struct V_1 * V_2 )
{
return V_2 -> V_875 -> V_1110 &&
F_161 ( ! F_274 ( V_2 -> V_144 ) ) ;
}
static void F_539 ( struct V_1 * V_2 )
{
struct V_1001 * V_1001 = V_2 -> V_875 ;
V_1001 -> V_1111 = ( F_455 ( V_2 ) & V_1033 ) != 0 ;
V_1001 -> V_15 = F_283 ( V_2 ) ? V_1112 : 0 ;
V_1001 -> V_189 = F_90 ( V_2 ) ;
V_1001 -> V_32 = F_21 ( V_2 ) ;
V_1001 -> V_1113 =
F_274 ( V_2 -> V_144 ) ||
F_267 ( V_2 ) ;
}
static void F_264 ( struct V_1 * V_2 )
{
int V_1114 , V_1115 ;
if ( ! V_92 -> F_264 )
return;
if ( ! F_88 ( V_2 ) )
return;
if ( V_2 -> V_5 . V_613 )
return;
if ( ! V_2 -> V_5 . V_666 -> V_727 )
V_1114 = F_540 ( V_2 ) ;
else
V_1114 = - 1 ;
if ( V_1114 != - 1 )
V_1114 >>= 4 ;
V_1115 = F_91 ( V_2 ) ;
V_92 -> F_264 ( V_2 , V_1115 , V_1114 ) ;
}
static int F_541 ( struct V_1 * V_2 , bool V_1116 )
{
int V_126 ;
if ( V_2 -> V_5 . V_70 . V_72 ) {
V_92 -> V_1117 ( V_2 ) ;
return 0 ;
}
if ( ! V_2 -> V_5 . V_70 . V_71 ) {
if ( V_2 -> V_5 . V_645 ) {
V_92 -> V_1118 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_640 . V_71 ) {
V_92 -> V_1119 ( V_2 ) ;
return 0 ;
}
}
if ( F_41 ( V_2 ) && V_92 -> V_1120 ) {
V_126 = V_92 -> V_1120 ( V_2 , V_1116 ) ;
if ( V_126 != 0 )
return V_126 ;
}
if ( V_2 -> V_5 . V_70 . V_71 ) {
F_542 ( V_2 -> V_5 . V_70 . V_18 ,
V_2 -> V_5 . V_70 . V_74 ,
V_2 -> V_5 . V_70 . V_64 ) ;
V_2 -> V_5 . V_70 . V_71 = false ;
V_2 -> V_5 . V_70 . V_72 = true ;
if ( F_29 ( V_2 -> V_5 . V_70 . V_18 ) == V_62 )
F_483 ( V_2 , F_455 ( V_2 ) |
V_1012 ) ;
if ( V_2 -> V_5 . V_70 . V_18 == V_55 &&
( V_2 -> V_5 . V_200 & V_1121 ) ) {
V_2 -> V_5 . V_200 &= ~ V_1121 ;
F_94 ( V_2 ) ;
}
V_92 -> V_1117 ( V_2 ) ;
} else if ( V_2 -> V_5 . V_652 && ! F_283 ( V_2 ) ) {
V_2 -> V_5 . V_652 = false ;
F_543 ( V_2 ) ;
} else if ( V_2 -> V_5 . V_646 && V_92 -> V_1122 ( V_2 ) ) {
-- V_2 -> V_5 . V_646 ;
V_2 -> V_5 . V_645 = true ;
V_92 -> V_1118 ( V_2 ) ;
} else if ( F_544 ( V_2 ) ) {
if ( F_41 ( V_2 ) && V_92 -> V_1120 ) {
V_126 = V_92 -> V_1120 ( V_2 , V_1116 ) ;
if ( V_126 != 0 )
return V_126 ;
}
if ( V_92 -> V_1123 ( V_2 ) ) {
F_273 ( V_2 , F_545 ( V_2 ) ,
false ) ;
V_92 -> V_1119 ( V_2 ) ;
}
}
return 0 ;
}
static void F_281 ( struct V_1 * V_2 )
{
unsigned V_940 = 2 ;
if ( V_92 -> V_648 ( V_2 ) || V_2 -> V_5 . V_645 )
V_940 = 1 ;
V_2 -> V_5 . V_646 += F_546 ( & V_2 -> V_5 . V_89 , 0 ) ;
V_2 -> V_5 . V_646 = F_349 ( V_2 -> V_5 . V_646 , V_940 ) ;
F_32 ( V_69 , V_2 ) ;
}
static T_1 F_547 ( struct V_849 * V_851 )
{
T_1 V_15 = 0 ;
V_15 |= V_851 -> V_939 << 23 ;
V_15 |= V_851 -> V_195 << 22 ;
V_15 |= V_851 -> V_945 << 21 ;
V_15 |= V_851 -> V_944 << 20 ;
V_15 |= V_851 -> V_943 << 15 ;
V_15 |= V_851 -> V_941 << 13 ;
V_15 |= V_851 -> V_611 << 12 ;
V_15 |= V_851 -> type << 8 ;
return V_15 ;
}
static void F_548 ( struct V_1 * V_2 , char * V_1124 , int V_512 )
{
struct V_849 V_851 ;
int V_99 ;
F_357 ( V_2 , & V_851 , V_512 ) ;
F_549 ( T_1 , V_1124 , 0x7fa8 + V_512 * 4 , V_851 . V_934 ) ;
if ( V_512 < 3 )
V_99 = 0x7f84 + V_512 * 12 ;
else
V_99 = 0x7f2c + ( V_512 - 3 ) * 12 ;
F_549 ( T_1 , V_1124 , V_99 + 8 , V_851 . V_240 ) ;
F_549 ( T_1 , V_1124 , V_99 + 4 , V_851 . V_940 ) ;
F_549 ( T_1 , V_1124 , V_99 , F_547 ( & V_851 ) ) ;
}
static void F_550 ( struct V_1 * V_2 , char * V_1124 , int V_512 )
{
struct V_849 V_851 ;
int V_99 ;
V_905 V_15 ;
F_357 ( V_2 , & V_851 , V_512 ) ;
V_99 = 0x7e00 + V_512 * 16 ;
V_15 = F_547 ( & V_851 ) >> 8 ;
F_549 ( V_905 , V_1124 , V_99 , V_851 . V_934 ) ;
F_549 ( V_905 , V_1124 , V_99 + 2 , V_15 ) ;
F_549 ( T_1 , V_1124 , V_99 + 4 , V_851 . V_940 ) ;
F_549 ( T_2 , V_1124 , V_99 + 8 , V_851 . V_240 ) ;
}
static void F_551 ( struct V_1 * V_2 , char * V_1124 )
{
struct V_928 V_929 ;
struct V_849 V_851 ;
unsigned long V_209 ;
int V_3 ;
F_549 ( T_1 , V_1124 , 0x7ffc , F_65 ( V_2 ) ) ;
F_549 ( T_1 , V_1124 , 0x7ff8 , F_63 ( V_2 ) ) ;
F_549 ( T_1 , V_1124 , 0x7ff4 , F_455 ( V_2 ) ) ;
F_549 ( T_1 , V_1124 , 0x7ff0 , F_456 ( V_2 ) ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
F_549 ( T_1 , V_1124 , 0x7fd0 + V_3 * 4 , F_100 ( V_2 , V_3 ) ) ;
F_98 ( V_2 , 6 , & V_209 ) ;
F_549 ( T_1 , V_1124 , 0x7fcc , ( T_1 ) V_209 ) ;
F_98 ( V_2 , 7 , & V_209 ) ;
F_549 ( T_1 , V_1124 , 0x7fc8 , ( T_1 ) V_209 ) ;
F_357 ( V_2 , & V_851 , V_1125 ) ;
F_549 ( T_1 , V_1124 , 0x7fc4 , V_851 . V_934 ) ;
F_549 ( T_1 , V_1124 , 0x7f64 , V_851 . V_240 ) ;
F_549 ( T_1 , V_1124 , 0x7f60 , V_851 . V_940 ) ;
F_549 ( T_1 , V_1124 , 0x7f5c , F_547 ( & V_851 ) ) ;
F_357 ( V_2 , & V_851 , V_1126 ) ;
F_549 ( T_1 , V_1124 , 0x7fc0 , V_851 . V_934 ) ;
F_549 ( T_1 , V_1124 , 0x7f80 , V_851 . V_240 ) ;
F_549 ( T_1 , V_1124 , 0x7f7c , V_851 . V_940 ) ;
F_549 ( T_1 , V_1124 , 0x7f78 , F_547 ( & V_851 ) ) ;
V_92 -> V_930 ( V_2 , & V_929 ) ;
F_549 ( T_1 , V_1124 , 0x7f74 , V_929 . V_83 ) ;
F_549 ( T_1 , V_1124 , 0x7f70 , V_929 . V_513 ) ;
V_92 -> V_931 ( V_2 , & V_929 ) ;
F_549 ( T_1 , V_1124 , 0x7f58 , V_929 . V_83 ) ;
F_549 ( T_1 , V_1124 , 0x7f54 , V_929 . V_513 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_548 ( V_2 , V_1124 , V_3 ) ;
F_549 ( T_1 , V_1124 , 0x7f14 , F_82 ( V_2 ) ) ;
F_549 ( T_1 , V_1124 , 0x7efc , 0x00020000 ) ;
F_549 ( T_1 , V_1124 , 0x7ef8 , V_2 -> V_5 . V_440 ) ;
}
static void F_552 ( struct V_1 * V_2 , char * V_1124 )
{
#ifdef F_66
struct V_928 V_929 ;
struct V_849 V_851 ;
unsigned long V_209 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ )
F_549 ( T_2 , V_1124 , 0x7ff8 - V_3 * 8 , F_100 ( V_2 , V_3 ) ) ;
F_549 ( T_2 , V_1124 , 0x7f78 , F_456 ( V_2 ) ) ;
F_549 ( T_1 , V_1124 , 0x7f70 , F_455 ( V_2 ) ) ;
F_98 ( V_2 , 6 , & V_209 ) ;
F_549 ( T_2 , V_1124 , 0x7f68 , V_209 ) ;
F_98 ( V_2 , 7 , & V_209 ) ;
F_549 ( T_2 , V_1124 , 0x7f60 , V_209 ) ;
F_549 ( T_2 , V_1124 , 0x7f58 , F_65 ( V_2 ) ) ;
F_549 ( T_2 , V_1124 , 0x7f50 , F_63 ( V_2 ) ) ;
F_549 ( T_2 , V_1124 , 0x7f48 , F_82 ( V_2 ) ) ;
F_549 ( T_1 , V_1124 , 0x7f00 , V_2 -> V_5 . V_440 ) ;
F_549 ( T_1 , V_1124 , 0x7efc , 0x00020064 ) ;
F_549 ( T_2 , V_1124 , 0x7ed0 , V_2 -> V_5 . V_137 ) ;
F_357 ( V_2 , & V_851 , V_1125 ) ;
F_549 ( V_905 , V_1124 , 0x7e90 , V_851 . V_934 ) ;
F_549 ( V_905 , V_1124 , 0x7e92 , F_547 ( & V_851 ) >> 8 ) ;
F_549 ( T_1 , V_1124 , 0x7e94 , V_851 . V_940 ) ;
F_549 ( T_2 , V_1124 , 0x7e98 , V_851 . V_240 ) ;
V_92 -> V_931 ( V_2 , & V_929 ) ;
F_549 ( T_1 , V_1124 , 0x7e84 , V_929 . V_513 ) ;
F_549 ( T_2 , V_1124 , 0x7e88 , V_929 . V_83 ) ;
F_357 ( V_2 , & V_851 , V_1126 ) ;
F_549 ( V_905 , V_1124 , 0x7e70 , V_851 . V_934 ) ;
F_549 ( V_905 , V_1124 , 0x7e72 , F_547 ( & V_851 ) >> 8 ) ;
F_549 ( T_1 , V_1124 , 0x7e74 , V_851 . V_940 ) ;
F_549 ( T_2 , V_1124 , 0x7e78 , V_851 . V_240 ) ;
V_92 -> V_930 ( V_2 , & V_929 ) ;
F_549 ( T_1 , V_1124 , 0x7e64 , V_929 . V_513 ) ;
F_549 ( T_2 , V_1124 , 0x7e68 , V_929 . V_83 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_550 ( V_2 , V_1124 , V_3 ) ;
#else
F_34 ( 1 ) ;
#endif
}
static void F_543 ( struct V_1 * V_2 )
{
struct V_849 V_1127 , V_1128 ;
struct V_928 V_929 ;
char V_1124 [ 512 ] ;
T_1 V_127 ;
F_472 ( V_2 -> V_310 , V_2 -> V_5 . V_440 , true ) ;
V_2 -> V_5 . V_654 |= V_667 ;
memset ( V_1124 , 0 , 512 ) ;
if ( F_24 ( V_2 , V_1129 ) )
F_552 ( V_2 , V_1124 ) ;
else
F_551 ( V_2 , V_1124 ) ;
F_206 ( V_2 , V_2 -> V_5 . V_440 + 0xfe00 , V_1124 , sizeof( V_1124 ) ) ;
if ( V_92 -> V_648 ( V_2 ) )
V_2 -> V_5 . V_654 |= V_655 ;
else
V_92 -> V_665 ( V_2 , true ) ;
F_461 ( V_2 , V_1130 ) ;
F_460 ( V_2 , 0x8000 ) ;
V_127 = V_2 -> V_5 . V_127 & ~ ( V_136 | V_1131 | V_1132 | V_130 ) ;
V_92 -> V_143 ( V_2 , V_127 ) ;
V_2 -> V_5 . V_127 = V_127 ;
V_92 -> V_184 ( V_2 , 0 ) ;
V_929 . V_83 = V_929 . V_513 = 0 ;
V_92 -> V_933 ( V_2 , & V_929 ) ;
F_96 ( V_2 , 7 , V_212 ) ;
V_1127 . V_934 = ( V_2 -> V_5 . V_440 >> 4 ) & 0xffff ;
V_1127 . V_240 = V_2 -> V_5 . V_440 ;
V_1128 . V_934 = 0 ;
V_1128 . V_240 = 0 ;
V_1127 . V_940 = V_1128 . V_940 = 0xffffffff ;
V_1127 . type = V_1128 . type = 0x3 ;
V_1127 . V_941 = V_1128 . V_941 = 0 ;
V_1127 . V_195 = V_1128 . V_195 = 0 ;
V_1127 . V_611 = V_1128 . V_611 = 1 ;
V_1127 . V_945 = V_1128 . V_945 = 0 ;
V_1127 . V_939 = V_1128 . V_939 = 1 ;
V_1127 . V_944 = V_1128 . V_944 = 0 ;
V_1127 . V_943 = V_1128 . V_943 = 1 ;
V_1127 . V_938 = V_1128 . V_938 = 0 ;
V_1127 . V_947 = V_1128 . V_947 = 0 ;
F_356 ( V_2 , & V_1127 , V_1133 ) ;
F_356 ( V_2 , & V_1128 , V_1134 ) ;
F_356 ( V_2 , & V_1128 , V_1135 ) ;
F_356 ( V_2 , & V_1128 , V_1136 ) ;
F_356 ( V_2 , & V_1128 , V_1137 ) ;
F_356 ( V_2 , & V_1128 , V_1138 ) ;
if ( F_24 ( V_2 , V_1129 ) )
V_92 -> F_104 ( V_2 , 0 ) ;
F_79 ( V_2 ) ;
F_69 ( V_2 ) ;
}
static void F_553 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_652 = true ;
F_32 ( V_69 , V_2 ) ;
}
void F_554 ( struct V_144 * V_144 )
{
F_175 ( V_144 , V_1139 ) ;
}
static void F_555 ( struct V_1 * V_2 )
{
T_2 V_1140 [ 4 ] ;
if ( ! F_556 ( V_2 -> V_5 . V_666 ) )
return;
F_557 ( V_2 -> V_5 . V_1141 , 256 ) ;
if ( F_558 ( V_2 -> V_144 ) )
F_559 ( V_2 , V_2 -> V_5 . V_1141 ) ;
else {
if ( V_92 -> V_612 && V_2 -> V_5 . V_613 )
V_92 -> V_612 ( V_2 ) ;
F_560 ( V_2 , V_2 -> V_5 . V_1141 ) ;
}
F_561 ( ( V_188 * ) V_1140 , V_2 -> V_5 . V_1141 ,
F_562 ( V_2 ) -> V_1142 , 256 ) ;
V_92 -> V_1143 ( V_2 , V_1140 ) ;
}
static void F_563 ( struct V_1 * V_2 )
{
++ V_2 -> V_78 . V_1144 ;
V_92 -> V_1144 ( V_2 ) ;
}
void F_564 ( struct V_1 * V_2 )
{
struct V_397 * V_397 = NULL ;
if ( ! F_88 ( V_2 ) )
return;
if ( ! V_92 -> V_1145 )
return;
V_397 = F_565 ( V_2 -> V_144 , V_867 >> V_111 ) ;
if ( F_392 ( V_397 ) )
return;
V_92 -> V_1145 ( V_2 , F_566 ( V_397 ) ) ;
F_567 ( V_397 ) ;
}
static int F_568 ( struct V_1 * V_2 )
{
int V_126 ;
bool V_1116 =
F_538 ( V_2 ) &&
F_265 ( V_2 ) ;
bool V_1146 = false ;
if ( F_569 ( V_2 ) ) {
if ( F_570 ( V_1147 , V_2 ) )
F_571 ( V_2 ) ;
if ( F_570 ( V_607 , V_2 ) )
F_572 ( V_2 ) ;
if ( F_570 ( V_309 , V_2 ) )
F_176 ( V_2 -> V_144 ) ;
if ( F_570 ( V_446 , V_2 ) )
F_197 ( V_2 ) ;
if ( F_570 ( V_351 , V_2 ) ) {
V_126 = F_191 ( V_2 ) ;
if ( F_165 ( V_126 ) )
goto V_118;
}
if ( F_570 ( V_1148 , V_2 ) )
F_84 ( V_2 ) ;
if ( F_570 ( V_186 , V_2 ) )
F_563 ( V_2 ) ;
if ( F_570 ( V_1149 , V_2 ) ) {
V_2 -> V_875 -> V_894 = V_1150 ;
V_126 = 0 ;
goto V_118;
}
if ( F_570 ( V_75 , V_2 ) ) {
V_2 -> V_875 -> V_894 = V_1151 ;
V_2 -> V_890 = 0 ;
V_126 = 0 ;
goto V_118;
}
if ( F_570 ( V_1152 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1153 = true ;
V_126 = 1 ;
goto V_118;
}
if ( F_570 ( V_451 , V_2 ) )
F_212 ( V_2 ) ;
if ( F_570 ( V_620 , V_2 ) )
F_553 ( V_2 ) ;
if ( F_570 ( V_90 , V_2 ) )
F_281 ( V_2 ) ;
if ( F_570 ( V_1154 , V_2 ) )
F_573 ( V_2 ) ;
if ( F_570 ( V_1155 , V_2 ) )
F_574 ( V_2 ) ;
if ( F_570 ( V_1156 , V_2 ) ) {
F_15 ( V_2 -> V_5 . V_1157 > 255 ) ;
if ( F_62 ( V_2 -> V_5 . V_1157 ,
V_2 -> V_5 . V_1141 ) ) {
V_2 -> V_875 -> V_894 = V_1158 ;
V_2 -> V_875 -> V_1159 . V_43 =
V_2 -> V_5 . V_1157 ;
V_126 = 0 ;
goto V_118;
}
}
if ( F_570 ( V_1139 , V_2 ) )
F_555 ( V_2 ) ;
if ( F_570 ( V_1160 , V_2 ) )
F_564 ( V_2 ) ;
if ( F_570 ( V_1161 , V_2 ) ) {
V_2 -> V_875 -> V_894 = V_1162 ;
V_2 -> V_875 -> V_1163 . type = V_1164 ;
V_126 = 0 ;
goto V_118;
}
if ( F_570 ( V_1165 , V_2 ) ) {
V_2 -> V_875 -> V_894 = V_1162 ;
V_2 -> V_875 -> V_1163 . type = V_1166 ;
V_126 = 0 ;
goto V_118;
}
if ( F_570 ( V_1167 , V_2 ) ) {
V_2 -> V_875 -> V_894 = V_1168 ;
V_2 -> V_875 -> V_1169 = V_2 -> V_5 . V_1169 . exit ;
V_126 = 0 ;
goto V_118;
}
if ( F_570 ( V_1170 , V_2 ) )
F_575 ( V_2 ) ;
}
if ( F_570 ( V_69 , V_2 ) || V_1116 ) {
++ V_2 -> V_78 . V_1171 ;
F_576 ( V_2 ) ;
if ( V_2 -> V_5 . V_662 == V_663 ) {
V_126 = 1 ;
goto V_118;
}
if ( F_541 ( V_2 , V_1116 ) != 0 )
V_1146 = true ;
else {
if ( V_2 -> V_5 . V_652 && ! F_283 ( V_2 ) )
V_1146 = true ;
if ( V_2 -> V_5 . V_646 )
V_92 -> V_1172 ( V_2 ) ;
if ( F_544 ( V_2 ) || V_1116 )
V_92 -> V_1173 ( V_2 ) ;
F_30 ( V_2 -> V_5 . V_70 . V_71 ) ;
}
if ( F_577 ( V_2 ) ) {
F_264 ( V_2 ) ;
F_578 ( V_2 ) ;
}
}
V_126 = F_579 ( V_2 ) ;
if ( F_165 ( V_126 ) ) {
goto V_1174;
}
F_441 () ;
V_92 -> V_1175 ( V_2 ) ;
F_442 ( V_2 ) ;
F_580 () ;
V_2 -> V_342 = V_1176 ;
F_236 ( & V_2 -> V_144 -> V_508 , V_2 -> V_1177 ) ;
F_581 () ;
if ( F_577 ( V_2 ) ) {
if ( V_92 -> V_612 && V_2 -> V_5 . V_613 )
V_92 -> V_612 ( V_2 ) ;
}
if ( V_2 -> V_342 == V_1178 || F_569 ( V_2 )
|| F_582 () || F_583 ( V_414 ) ) {
V_2 -> V_342 = V_1179 ;
F_189 () ;
F_584 () ;
F_444 () ;
V_2 -> V_1177 = F_235 ( & V_2 -> V_144 -> V_508 ) ;
V_126 = 1 ;
goto V_1174;
}
F_75 ( V_2 ) ;
if ( V_1146 ) {
F_32 ( V_69 , V_2 ) ;
F_585 ( V_2 -> V_24 ) ;
}
F_586 ( V_2 -> V_310 ) ;
F_587 ( V_2 ) ;
F_588 () ;
if ( F_165 ( V_2 -> V_5 . V_196 ) ) {
F_589 ( 0 , 7 ) ;
F_589 ( V_2 -> V_5 . V_194 [ 0 ] , 0 ) ;
F_589 ( V_2 -> V_5 . V_194 [ 1 ] , 1 ) ;
F_589 ( V_2 -> V_5 . V_194 [ 2 ] , 2 ) ;
F_589 ( V_2 -> V_5 . V_194 [ 3 ] , 3 ) ;
F_589 ( V_2 -> V_5 . V_199 , 6 ) ;
V_2 -> V_5 . V_196 &= ~ V_197 ;
}
V_92 -> V_875 ( V_2 ) ;
if ( F_165 ( V_2 -> V_5 . V_196 & V_1180 ) ) {
F_30 ( V_2 -> V_191 & V_192 ) ;
V_92 -> V_1181 ( V_2 ) ;
F_92 ( V_2 ) ;
F_93 ( V_2 ) ;
F_94 ( V_2 ) ;
V_2 -> V_5 . V_196 &= ~ V_197 ;
}
if ( F_590 () )
F_591 () ;
V_2 -> V_5 . V_335 = F_147 ( V_2 , F_146 () ) ;
V_2 -> V_342 = V_1179 ;
F_189 () ;
F_77 ( V_2 ) ;
V_92 -> V_1182 ( V_2 ) ;
++ V_2 -> V_78 . V_1183 ;
F_592 () ;
F_584 () ;
F_444 () ;
V_2 -> V_1177 = F_235 ( & V_2 -> V_144 -> V_508 ) ;
if ( F_165 ( V_1184 == V_1185 ) ) {
unsigned long V_1108 = F_456 ( V_2 ) ;
F_593 ( V_1185 , ( void * ) V_1108 ) ;
}
if ( F_165 ( V_2 -> V_5 . V_286 ) )
F_32 ( V_351 , V_2 ) ;
if ( V_2 -> V_5 . V_1186 )
F_594 ( V_2 ) ;
V_2 -> V_5 . V_880 = false ;
V_126 = V_92 -> V_1187 ( V_2 ) ;
return V_126 ;
V_1174:
V_92 -> V_1174 ( V_2 ) ;
if ( F_165 ( V_2 -> V_5 . V_1186 ) )
F_594 ( V_2 ) ;
V_118:
return V_126 ;
}
static inline int F_595 ( struct V_144 * V_144 , struct V_1 * V_2 )
{
if ( ! F_596 ( V_2 ) &&
( ! V_92 -> V_1188 || V_92 -> V_1188 ( V_2 ) == 0 ) ) {
F_236 ( & V_144 -> V_508 , V_2 -> V_1177 ) ;
F_597 ( V_2 ) ;
V_2 -> V_1177 = F_235 ( & V_144 -> V_508 ) ;
if ( V_92 -> V_1189 )
V_92 -> V_1189 ( V_2 ) ;
if ( ! F_570 ( V_1190 , V_2 ) )
return 1 ;
}
F_576 ( V_2 ) ;
switch( V_2 -> V_5 . V_662 ) {
case V_1074 :
V_2 -> V_5 . V_1191 . V_1192 = false ;
V_2 -> V_5 . V_662 =
V_1193 ;
case V_1193 :
V_2 -> V_5 . V_6 . V_1153 = false ;
break;
case V_663 :
break;
default:
return - V_1194 ;
break;
}
return 1 ;
}
static inline bool F_598 ( struct V_1 * V_2 )
{
if ( F_41 ( V_2 ) && V_92 -> V_1120 )
V_92 -> V_1120 ( V_2 , false ) ;
return ( V_2 -> V_5 . V_662 == V_1193 &&
! V_2 -> V_5 . V_6 . V_1153 ) ;
}
static int F_599 ( struct V_1 * V_2 )
{
int V_126 ;
struct V_144 * V_144 = V_2 -> V_144 ;
V_2 -> V_1177 = F_235 ( & V_144 -> V_508 ) ;
for (; ; ) {
if ( F_598 ( V_2 ) ) {
V_126 = F_568 ( V_2 ) ;
} else {
V_126 = F_595 ( V_144 , V_2 ) ;
}
if ( V_126 <= 0 )
break;
F_178 ( V_252 , V_2 ) ;
if ( F_600 ( V_2 ) )
F_601 ( V_2 ) ;
if ( F_538 ( V_2 ) &&
F_267 ( V_2 ) ) {
V_126 = 0 ;
V_2 -> V_875 -> V_894 = V_1195 ;
++ V_2 -> V_78 . V_1196 ;
break;
}
F_602 ( V_2 ) ;
if ( F_583 ( V_414 ) ) {
V_126 = - V_1194 ;
V_2 -> V_875 -> V_894 = V_1197 ;
++ V_2 -> V_78 . V_1198 ;
break;
}
if ( F_582 () ) {
F_236 ( & V_144 -> V_508 , V_2 -> V_1177 ) ;
F_603 () ;
V_2 -> V_1177 = F_235 ( & V_144 -> V_508 ) ;
}
}
F_236 ( & V_144 -> V_508 , V_2 -> V_1177 ) ;
return V_126 ;
}
static inline int F_604 ( struct V_1 * V_2 )
{
int V_126 ;
V_2 -> V_1177 = F_235 ( & V_2 -> V_144 -> V_508 ) ;
V_126 = F_605 ( V_2 , V_1016 ) ;
F_236 ( & V_2 -> V_144 -> V_508 , V_2 -> V_1177 ) ;
if ( V_126 != V_982 )
return 0 ;
return 1 ;
}
static int V_1029 ( struct V_1 * V_2 )
{
F_15 ( ! V_2 -> V_5 . V_909 . V_776 ) ;
return F_604 ( V_2 ) ;
}
static int V_1030 ( struct V_1 * V_2 )
{
struct V_1001 * V_875 = V_2 -> V_875 ;
struct V_873 * V_874 ;
unsigned V_100 ;
F_15 ( ! V_2 -> V_890 ) ;
V_874 = & V_2 -> V_870 [ V_2 -> V_891 ] ;
V_100 = F_349 ( 8u , V_874 -> V_100 ) ;
if ( ! V_2 -> V_893 )
memcpy ( V_874 -> V_39 , V_875 -> V_876 . V_39 , V_100 ) ;
if ( V_874 -> V_100 <= 8 ) {
V_874 ++ ;
V_2 -> V_891 ++ ;
} else {
V_874 -> V_39 += V_100 ;
V_874 -> V_401 += V_100 ;
V_874 -> V_100 -= V_100 ;
}
if ( V_2 -> V_891 >= V_2 -> V_884 ) {
V_2 -> V_890 = 0 ;
if ( V_2 -> V_893 )
return 1 ;
V_2 -> V_869 = 1 ;
return F_604 ( V_2 ) ;
}
V_875 -> V_894 = V_895 ;
V_875 -> V_876 . V_896 = V_874 -> V_401 ;
if ( V_2 -> V_893 )
memcpy ( V_875 -> V_876 . V_39 , V_874 -> V_39 , F_349 ( 8u , V_874 -> V_100 ) ) ;
V_875 -> V_876 . V_100 = F_349 ( 8u , V_874 -> V_100 ) ;
V_875 -> V_876 . V_892 = V_2 -> V_893 ;
V_2 -> V_5 . V_1028 = V_1030 ;
return 0 ;
}
int F_606 ( struct V_1 * V_2 , struct V_1001 * V_1001 )
{
struct V_1199 * V_1199 = & V_414 -> V_1200 . V_1199 ;
int V_126 ;
T_17 V_1201 ;
F_607 ( V_1199 ) ;
if ( V_2 -> V_1202 )
F_608 ( V_1203 , & V_2 -> V_1204 , & V_1201 ) ;
if ( F_165 ( V_2 -> V_5 . V_662 == V_1205 ) ) {
if ( V_1001 -> V_1206 ) {
V_126 = - V_1194 ;
goto V_118;
}
F_597 ( V_2 ) ;
F_576 ( V_2 ) ;
F_178 ( V_1190 , V_2 ) ;
V_126 = - V_1207 ;
if ( F_583 ( V_414 ) ) {
V_126 = - V_1194 ;
V_2 -> V_875 -> V_894 = V_1197 ;
++ V_2 -> V_78 . V_1198 ;
}
goto V_118;
}
if ( ! F_88 ( V_2 ) ) {
if ( F_87 ( V_2 , V_1001 -> V_189 ) != 0 ) {
V_126 = - V_599 ;
goto V_118;
}
}
if ( F_165 ( V_2 -> V_5 . V_1028 ) ) {
int (* F_609)( struct V_1 * ) = V_2 -> V_5 . V_1028 ;
V_2 -> V_5 . V_1028 = NULL ;
V_126 = F_609 ( V_2 ) ;
if ( V_126 <= 0 )
goto V_118;
} else
F_30 ( V_2 -> V_5 . V_909 . V_776 || V_2 -> V_890 ) ;
if ( V_1001 -> V_1206 )
V_126 = - V_1194 ;
else
V_126 = F_599 ( V_2 ) ;
V_118:
F_539 ( V_2 ) ;
if ( V_2 -> V_1202 )
F_608 ( V_1203 , & V_1201 , NULL ) ;
return V_126 ;
}
int F_610 ( struct V_1 * V_2 , struct V_1208 * V_1209 )
{
if ( V_2 -> V_5 . V_1032 ) {
F_611 ( & V_2 -> V_5 . V_879 ) ;
V_2 -> V_5 . V_1032 = false ;
}
V_1209 -> V_1210 = F_100 ( V_2 , V_216 ) ;
V_1209 -> V_1211 = F_100 ( V_2 , V_1099 ) ;
V_1209 -> V_1212 = F_100 ( V_2 , V_215 ) ;
V_1209 -> V_1213 = F_100 ( V_2 , V_217 ) ;
V_1209 -> V_1214 = F_100 ( V_2 , V_1100 ) ;
V_1209 -> V_1215 = F_100 ( V_2 , V_1216 ) ;
V_1209 -> V_1217 = F_100 ( V_2 , V_1218 ) ;
V_1209 -> V_1219 = F_100 ( V_2 , V_1220 ) ;
#ifdef F_66
V_1209 -> V_1221 = F_100 ( V_2 , V_1222 ) ;
V_1209 -> V_1223 = F_100 ( V_2 , V_1224 ) ;
V_1209 -> V_1225 = F_100 ( V_2 , V_1226 ) ;
V_1209 -> V_1227 = F_100 ( V_2 , V_1228 ) ;
V_1209 -> V_1229 = F_100 ( V_2 , V_1230 ) ;
V_1209 -> V_1231 = F_100 ( V_2 , V_1232 ) ;
V_1209 -> V_1233 = F_100 ( V_2 , V_1234 ) ;
V_1209 -> V_1235 = F_100 ( V_2 , V_1236 ) ;
#endif
V_1209 -> V_1108 = F_456 ( V_2 ) ;
V_1209 -> V_1009 = F_455 ( V_2 ) ;
return 0 ;
}
int F_612 ( struct V_1 * V_2 , struct V_1208 * V_1209 )
{
V_2 -> V_5 . V_976 = true ;
V_2 -> V_5 . V_1032 = false ;
F_102 ( V_2 , V_216 , V_1209 -> V_1210 ) ;
F_102 ( V_2 , V_1099 , V_1209 -> V_1211 ) ;
F_102 ( V_2 , V_215 , V_1209 -> V_1212 ) ;
F_102 ( V_2 , V_217 , V_1209 -> V_1213 ) ;
F_102 ( V_2 , V_1100 , V_1209 -> V_1214 ) ;
F_102 ( V_2 , V_1216 , V_1209 -> V_1215 ) ;
F_102 ( V_2 , V_1218 , V_1209 -> V_1217 ) ;
F_102 ( V_2 , V_1220 , V_1209 -> V_1219 ) ;
#ifdef F_66
F_102 ( V_2 , V_1222 , V_1209 -> V_1221 ) ;
F_102 ( V_2 , V_1224 , V_1209 -> V_1223 ) ;
F_102 ( V_2 , V_1226 , V_1209 -> V_1225 ) ;
F_102 ( V_2 , V_1228 , V_1209 -> V_1227 ) ;
F_102 ( V_2 , V_1230 , V_1209 -> V_1229 ) ;
F_102 ( V_2 , V_1232 , V_1209 -> V_1231 ) ;
F_102 ( V_2 , V_1234 , V_1209 -> V_1233 ) ;
F_102 ( V_2 , V_1236 , V_1209 -> V_1235 ) ;
#endif
F_460 ( V_2 , V_1209 -> V_1108 ) ;
F_461 ( V_2 , V_1209 -> V_1009 ) ;
V_2 -> V_5 . V_70 . V_71 = false ;
F_32 ( V_69 , V_2 ) ;
return 0 ;
}
void F_613 ( struct V_1 * V_2 , int * V_195 , int * V_945 )
{
struct V_849 V_1127 ;
F_357 ( V_2 , & V_1127 , V_1133 ) ;
* V_195 = V_1127 . V_195 ;
* V_945 = V_1127 . V_945 ;
}
int F_614 ( struct V_1 * V_2 ,
struct V_1237 * V_1238 )
{
struct V_928 V_929 ;
F_357 ( V_2 , & V_1238 -> V_1127 , V_1133 ) ;
F_357 ( V_2 , & V_1238 -> V_1128 , V_1134 ) ;
F_357 ( V_2 , & V_1238 -> V_1239 , V_1135 ) ;
F_357 ( V_2 , & V_1238 -> V_1240 , V_1136 ) ;
F_357 ( V_2 , & V_1238 -> V_1241 , V_1137 ) ;
F_357 ( V_2 , & V_1238 -> V_1242 , V_1138 ) ;
F_357 ( V_2 , & V_1238 -> V_1243 , V_1125 ) ;
F_357 ( V_2 , & V_1238 -> V_1244 , V_1126 ) ;
V_92 -> V_931 ( V_2 , & V_929 ) ;
V_1238 -> V_1245 . V_940 = V_929 . V_513 ;
V_1238 -> V_1245 . V_240 = V_929 . V_83 ;
V_92 -> V_930 ( V_2 , & V_929 ) ;
V_1238 -> V_1246 . V_940 = V_929 . V_513 ;
V_1238 -> V_1246 . V_240 = V_929 . V_83 ;
V_1238 -> V_127 = F_65 ( V_2 ) ;
V_1238 -> V_84 = V_2 -> V_5 . V_84 ;
V_1238 -> V_109 = F_63 ( V_2 ) ;
V_1238 -> V_164 = F_82 ( V_2 ) ;
V_1238 -> V_189 = F_90 ( V_2 ) ;
V_1238 -> V_137 = V_2 -> V_5 . V_137 ;
V_1238 -> V_32 = F_21 ( V_2 ) ;
memset ( V_1238 -> V_1247 , 0 , sizeof V_1238 -> V_1247 ) ;
if ( V_2 -> V_5 . V_640 . V_71 && ! V_2 -> V_5 . V_640 . V_641 )
F_287 ( V_2 -> V_5 . V_640 . V_18 ,
( unsigned long * ) V_1238 -> V_1247 ) ;
return 0 ;
}
int F_615 ( struct V_1 * V_2 ,
struct V_1248 * V_662 )
{
F_576 ( V_2 ) ;
if ( V_2 -> V_5 . V_662 == V_1074 &&
V_2 -> V_5 . V_1191 . V_1192 )
V_662 -> V_662 = V_1193 ;
else
V_662 -> V_662 = V_2 -> V_5 . V_662 ;
return 0 ;
}
int F_616 ( struct V_1 * V_2 ,
struct V_1248 * V_662 )
{
if ( ! F_88 ( V_2 ) &&
V_662 -> V_662 != V_1193 )
return - V_599 ;
if ( ( F_283 ( V_2 ) || V_2 -> V_5 . V_652 ) &&
( V_662 -> V_662 == V_1249 ||
V_662 -> V_662 == V_663 ) )
return - V_599 ;
if ( V_662 -> V_662 == V_1249 ) {
V_2 -> V_5 . V_662 = V_663 ;
F_287 ( V_1250 , & V_2 -> V_5 . V_666 -> V_669 ) ;
} else
V_2 -> V_5 . V_662 = V_662 -> V_662 ;
F_32 ( V_69 , V_2 ) ;
return 0 ;
}
int F_617 ( struct V_1 * V_2 , V_905 V_1251 , int V_1252 ,
int V_1253 , bool V_74 , T_1 V_64 )
{
struct V_863 * V_864 = & V_2 -> V_5 . V_879 ;
int V_113 ;
F_454 ( V_2 ) ;
V_113 = F_618 ( V_864 , V_1251 , V_1252 , V_1253 ,
V_74 , V_64 ) ;
if ( V_113 )
return V_981 ;
F_460 ( V_2 , V_864 -> V_966 ) ;
F_461 ( V_2 , V_864 -> V_963 ) ;
F_32 ( V_69 , V_2 ) ;
return V_982 ;
}
int F_619 ( struct V_1 * V_2 ,
struct V_1237 * V_1238 )
{
struct V_33 V_1254 ;
int V_1255 = 0 ;
int V_1256 , V_1257 , V_507 ;
struct V_928 V_929 ;
if ( ! F_24 ( V_2 , V_174 ) &&
( V_1238 -> V_164 & V_147 ) )
return - V_599 ;
V_1254 . V_39 = V_1238 -> V_32 ;
V_1254 . V_42 = true ;
if ( F_22 ( V_2 , & V_1254 ) )
return - V_599 ;
V_929 . V_513 = V_1238 -> V_1245 . V_940 ;
V_929 . V_83 = V_1238 -> V_1245 . V_240 ;
V_92 -> V_933 ( V_2 , & V_929 ) ;
V_929 . V_513 = V_1238 -> V_1246 . V_940 ;
V_929 . V_83 = V_1238 -> V_1246 . V_240 ;
V_92 -> V_932 ( V_2 , & V_929 ) ;
V_2 -> V_5 . V_84 = V_1238 -> V_84 ;
V_1255 |= F_63 ( V_2 ) != V_1238 -> V_109 ;
V_2 -> V_5 . V_109 = V_1238 -> V_109 ;
F_58 ( V_187 , ( V_188 * ) & V_2 -> V_5 . V_123 ) ;
F_87 ( V_2 , V_1238 -> V_189 ) ;
V_1255 |= V_2 -> V_5 . V_137 != V_1238 -> V_137 ;
V_92 -> F_104 ( V_2 , V_1238 -> V_137 ) ;
V_1255 |= F_65 ( V_2 ) != V_1238 -> V_127 ;
V_92 -> V_143 ( V_2 , V_1238 -> V_127 ) ;
V_2 -> V_5 . V_127 = V_1238 -> V_127 ;
V_1255 |= F_82 ( V_2 ) != V_1238 -> V_164 ;
V_92 -> V_184 ( V_2 , V_1238 -> V_164 ) ;
if ( V_1238 -> V_164 & ( V_147 | V_172 ) )
F_79 ( V_2 ) ;
V_507 = F_235 ( & V_2 -> V_144 -> V_508 ) ;
if ( ! F_60 ( V_2 ) && F_61 ( V_2 ) ) {
F_56 ( V_2 , V_2 -> V_5 . V_108 , F_63 ( V_2 ) ) ;
V_1255 = 1 ;
}
F_236 ( & V_2 -> V_144 -> V_508 , V_507 ) ;
if ( V_1255 )
F_69 ( V_2 ) ;
V_1257 = V_616 ;
V_1256 = F_620 (
( const unsigned long * ) V_1238 -> V_1247 , V_1257 ) ;
if ( V_1256 < V_1257 ) {
F_273 ( V_2 , V_1256 , false ) ;
F_128 ( L_28 , V_1256 ) ;
}
F_356 ( V_2 , & V_1238 -> V_1127 , V_1133 ) ;
F_356 ( V_2 , & V_1238 -> V_1128 , V_1134 ) ;
F_356 ( V_2 , & V_1238 -> V_1239 , V_1135 ) ;
F_356 ( V_2 , & V_1238 -> V_1240 , V_1136 ) ;
F_356 ( V_2 , & V_1238 -> V_1241 , V_1137 ) ;
F_356 ( V_2 , & V_1238 -> V_1242 , V_1138 ) ;
F_356 ( V_2 , & V_1238 -> V_1243 , V_1125 ) ;
F_356 ( V_2 , & V_1238 -> V_1244 , V_1126 ) ;
F_264 ( V_2 ) ;
if ( F_621 ( V_2 ) && F_456 ( V_2 ) == 0xfff0 &&
V_1238 -> V_1127 . V_934 == 0xf000 && V_1238 -> V_1127 . V_240 == 0xffff0000 &&
! F_33 ( V_2 ) )
V_2 -> V_5 . V_662 = V_1193 ;
F_32 ( V_69 , V_2 ) ;
return 0 ;
}
int F_622 ( struct V_1 * V_2 ,
struct V_1258 * V_1259 )
{
unsigned long V_1009 ;
int V_3 , V_126 ;
if ( V_1259 -> V_783 & ( V_1260 | V_1261 ) ) {
V_126 = - V_830 ;
if ( V_2 -> V_5 . V_70 . V_71 )
goto V_118;
if ( V_1259 -> V_783 & V_1260 )
F_35 ( V_2 , V_55 ) ;
else
F_35 ( V_2 , V_56 ) ;
}
V_1009 = F_455 ( V_2 ) ;
V_2 -> V_191 = V_1259 -> V_783 ;
if ( ! ( V_2 -> V_191 & V_1262 ) )
V_2 -> V_191 = 0 ;
if ( V_2 -> V_191 & V_192 ) {
for ( V_3 = 0 ; V_3 < V_193 ; ++ V_3 )
V_2 -> V_5 . V_194 [ V_3 ] = V_1259 -> V_5 . V_1263 [ V_3 ] ;
V_2 -> V_5 . V_201 = V_1259 -> V_5 . V_1263 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_193 ; V_3 ++ )
V_2 -> V_5 . V_194 [ V_3 ] = V_2 -> V_5 . V_195 [ V_3 ] ;
}
F_94 ( V_2 ) ;
if ( V_2 -> V_191 & V_1002 )
V_2 -> V_5 . V_1006 = F_456 ( V_2 ) +
F_406 ( V_2 , V_1133 ) ;
F_461 ( V_2 , V_1009 ) ;
V_92 -> V_1264 ( V_2 ) ;
V_126 = 0 ;
V_118:
return V_126 ;
}
int F_623 ( struct V_1 * V_2 ,
struct V_1265 * V_1243 )
{
unsigned long V_1266 = V_1243 -> V_1267 ;
T_6 V_401 ;
int V_507 ;
V_507 = F_235 ( & V_2 -> V_144 -> V_508 ) ;
V_401 = F_362 ( V_2 , V_1266 , NULL ) ;
F_236 ( & V_2 -> V_144 -> V_508 , V_507 ) ;
V_1243 -> V_1268 = V_401 ;
V_1243 -> V_680 = V_401 != V_105 ;
V_1243 -> V_1269 = 1 ;
V_1243 -> V_1270 = 0 ;
return 0 ;
}
int F_624 ( struct V_1 * V_2 , struct V_1271 * V_1199 )
{
struct V_696 * V_695 =
& V_2 -> V_5 . V_675 . V_676 . V_695 ;
memcpy ( V_1199 -> V_1272 , V_695 -> V_1273 , 128 ) ;
V_1199 -> V_1274 = V_695 -> V_1275 ;
V_1199 -> V_1276 = V_695 -> V_1277 ;
V_1199 -> V_1278 = V_695 -> V_1279 ;
V_1199 -> V_1280 = V_695 -> V_1281 ;
V_1199 -> V_1282 = V_695 -> V_1108 ;
V_1199 -> V_1283 = V_695 -> V_1284 ;
memcpy ( V_1199 -> V_1285 , V_695 -> V_1286 , sizeof V_695 -> V_1286 ) ;
return 0 ;
}
int F_625 ( struct V_1 * V_2 , struct V_1271 * V_1199 )
{
struct V_696 * V_695 =
& V_2 -> V_5 . V_675 . V_676 . V_695 ;
memcpy ( V_695 -> V_1273 , V_1199 -> V_1272 , 128 ) ;
V_695 -> V_1275 = V_1199 -> V_1274 ;
V_695 -> V_1277 = V_1199 -> V_1276 ;
V_695 -> V_1279 = V_1199 -> V_1278 ;
V_695 -> V_1281 = V_1199 -> V_1280 ;
V_695 -> V_1108 = V_1199 -> V_1282 ;
V_695 -> V_1284 = V_1199 -> V_1283 ;
memcpy ( V_695 -> V_1286 , V_1199 -> V_1285 , sizeof V_695 -> V_1286 ) ;
return 0 ;
}
static void F_626 ( struct V_1 * V_2 )
{
F_627 ( & V_2 -> V_5 . V_675 . V_676 ) ;
if ( F_242 ( V_689 ) )
V_2 -> V_5 . V_675 . V_676 . V_674 . V_678 . V_690 =
V_151 | V_691 ;
V_2 -> V_5 . V_150 = V_156 ;
V_2 -> V_5 . V_127 |= V_132 ;
}
void F_442 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1287 )
return;
V_2 -> V_1287 = 1 ;
F_628 () ;
F_629 ( & V_2 -> V_5 . V_675 . V_676 ,
~ V_687 ) ;
F_630 ( 1 ) ;
}
void F_259 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_1287 )
return;
V_2 -> V_1287 = 0 ;
F_631 ( & V_2 -> V_5 . V_675 ) ;
F_632 () ;
++ V_2 -> V_78 . V_1288 ;
F_630 ( 0 ) ;
}
void F_633 ( struct V_1 * V_2 )
{
void * V_602 = V_2 -> V_5 . V_602 ;
F_211 ( V_2 ) ;
V_92 -> V_1289 ( V_2 ) ;
F_634 ( V_602 ) ;
}
struct V_1 * F_635 ( struct V_144 * V_144 ,
unsigned int V_1290 )
{
struct V_1 * V_2 ;
if ( F_153 () && F_139 ( & V_144 -> V_306 ) != 0 )
F_400 ( V_907
L_29
L_30 ) ;
V_2 = V_92 -> V_1291 ( V_144 , V_1290 ) ;
return V_2 ;
}
int F_636 ( struct V_1 * V_2 )
{
int V_126 ;
F_637 ( V_2 ) ;
V_126 = V_603 ( V_2 ) ;
if ( V_126 )
return V_126 ;
F_638 ( V_2 , false ) ;
F_639 ( V_2 ) ;
V_609 ( V_2 ) ;
return V_126 ;
}
void F_640 ( struct V_1 * V_2 )
{
struct V_33 V_22 ;
struct V_144 * V_144 = V_2 -> V_144 ;
F_641 ( V_2 ) ;
if ( V_603 ( V_2 ) )
return;
V_22 . V_39 = 0x0 ;
V_22 . V_152 = V_1292 ;
V_22 . V_42 = true ;
F_149 ( V_2 , & V_22 ) ;
V_609 ( V_2 ) ;
if ( ! V_376 )
return;
F_198 ( & V_144 -> V_5 . V_375 ,
V_377 ) ;
}
void F_642 ( struct V_1 * V_2 )
{
int V_126 ;
V_2 -> V_5 . V_6 . V_402 = 0 ;
V_126 = V_603 ( V_2 ) ;
F_15 ( V_126 ) ;
F_571 ( V_2 ) ;
V_609 ( V_2 ) ;
V_92 -> V_1289 ( V_2 ) ;
}
void F_638 ( struct V_1 * V_2 , bool V_1293 )
{
V_2 -> V_5 . V_654 = 0 ;
V_2 -> V_5 . V_652 = 0 ;
F_172 ( & V_2 -> V_5 . V_89 , 0 ) ;
V_2 -> V_5 . V_646 = 0 ;
V_2 -> V_5 . V_645 = false ;
F_643 ( V_2 ) ;
F_478 ( V_2 ) ;
V_2 -> V_5 . V_70 . V_71 = false ;
memset ( V_2 -> V_5 . V_195 , 0 , sizeof( V_2 -> V_5 . V_195 ) ) ;
F_92 ( V_2 ) ;
V_2 -> V_5 . V_199 = V_1294 ;
F_93 ( V_2 ) ;
V_2 -> V_5 . V_200 = V_212 ;
F_94 ( V_2 ) ;
V_2 -> V_5 . V_84 = 0 ;
F_32 ( V_69 , V_2 ) ;
V_2 -> V_5 . V_6 . V_402 = 0 ;
V_2 -> V_5 . V_408 . V_402 = 0 ;
F_211 ( V_2 ) ;
F_68 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1153 = false ;
if ( ! V_1293 ) {
F_644 ( V_2 ) ;
V_2 -> V_5 . V_440 = 0x30000 ;
V_2 -> V_5 . V_479 = V_478 ;
V_2 -> V_5 . V_482 = 0 ;
}
memset ( V_2 -> V_5 . V_1209 , 0 , sizeof( V_2 -> V_5 . V_1209 ) ) ;
V_2 -> V_5 . V_123 = ~ 0 ;
V_2 -> V_5 . V_124 = ~ 0 ;
V_92 -> V_1295 ( V_2 , V_1293 ) ;
}
void F_645 ( struct V_1 * V_2 , T_13 V_43 )
{
struct V_849 V_1127 ;
F_357 ( V_2 , & V_1127 , V_1133 ) ;
V_1127 . V_934 = V_43 << 8 ;
V_1127 . V_240 = V_43 << 12 ;
F_356 ( V_2 , & V_1127 , V_1133 ) ;
F_460 ( V_2 , 0 ) ;
}
int F_646 ( void )
{
struct V_144 * V_144 ;
struct V_1 * V_2 ;
int V_3 ;
int V_113 ;
T_2 V_1296 ;
T_2 V_1297 = 0 ;
bool V_1298 , V_1299 = false ;
F_16 () ;
V_113 = V_92 -> V_1300 () ;
if ( V_113 != 0 )
return V_113 ;
V_1296 = F_146 () ;
V_1298 = ! F_153 () ;
F_493 (kvm, &vm_list, vm_list) {
F_177 (i, vcpu, kvm) {
if ( ! V_1298 && V_2 -> V_24 == F_10 () )
F_32 ( V_351 , V_2 ) ;
if ( V_1298 && V_2 -> V_5 . V_606 > V_1296 ) {
V_1299 = true ;
if ( V_2 -> V_5 . V_606 > V_1297 )
V_1297 = V_2 -> V_5 . V_606 ;
}
}
}
if ( V_1299 ) {
T_2 V_1301 = V_1297 - V_1296 ;
F_493 (kvm, &vm_list, vm_list) {
V_144 -> V_5 . V_347 = true ;
F_177 (i, vcpu, kvm) {
V_2 -> V_5 . V_604 += V_1301 ;
V_2 -> V_5 . V_606 = V_1296 ;
F_32 ( V_309 , V_2 ) ;
}
V_144 -> V_5 . V_324 = 0 ;
V_144 -> V_5 . V_326 = 0 ;
}
}
return 0 ;
}
void F_647 ( void )
{
V_92 -> V_1302 () ;
F_20 () ;
}
int F_648 ( void )
{
int V_126 ;
V_126 = V_92 -> V_1303 () ;
if ( V_126 != 0 )
return V_126 ;
if ( V_283 ) {
T_2 V_1304 = F_349 ( 0x7fffffffULL ,
F_142 ( V_288 , V_284 ) ) ;
V_739 = V_1304 ;
V_282 = 1ULL << V_287 ;
}
F_346 () ;
return 0 ;
}
void F_649 ( void )
{
V_92 -> V_1305 () ;
}
void F_650 ( void * V_1306 )
{
V_92 -> V_1307 ( V_1306 ) ;
}
bool F_651 ( struct V_1 * V_2 )
{
return V_2 -> V_144 -> V_5 . V_831 == V_2 -> V_310 ;
}
bool F_621 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_32 & V_1308 ) != 0 ;
}
int F_652 ( struct V_1 * V_2 )
{
struct V_397 * V_397 ;
struct V_144 * V_144 ;
int V_126 ;
F_15 ( V_2 -> V_144 == NULL ) ;
V_144 = V_2 -> V_144 ;
V_2 -> V_5 . V_613 = V_92 -> V_1309 ( V_2 ) ;
V_2 -> V_5 . V_1191 . V_1192 = false ;
V_2 -> V_5 . V_879 . V_878 = & V_1310 ;
if ( ! F_272 ( V_144 ) || F_651 ( V_2 ) )
V_2 -> V_5 . V_662 = V_1193 ;
else
V_2 -> V_5 . V_662 = V_1205 ;
V_397 = F_653 ( V_712 | V_1311 ) ;
if ( ! V_397 ) {
V_126 = - V_399 ;
goto V_1312;
}
V_2 -> V_5 . V_913 = F_654 ( V_397 ) ;
F_135 ( V_2 , V_1043 ) ;
V_126 = F_655 ( V_2 ) ;
if ( V_126 < 0 )
goto V_1313;
if ( F_272 ( V_144 ) ) {
V_126 = F_656 ( V_2 ) ;
if ( V_126 < 0 )
goto V_1314;
} else
F_657 ( & V_1315 ) ;
V_2 -> V_5 . V_386 = F_305 ( V_453 * sizeof( T_2 ) * 4 ,
V_712 ) ;
if ( ! V_2 -> V_5 . V_386 ) {
V_126 = - V_399 ;
goto V_1316;
}
V_2 -> V_5 . V_378 = V_453 ;
if ( ! F_658 ( & V_2 -> V_5 . V_602 , V_712 ) ) {
V_126 = - V_399 ;
goto V_1317;
}
F_626 ( V_2 ) ;
V_2 -> V_5 . V_313 = 0x0 ;
V_2 -> V_5 . V_368 = false ;
V_2 -> V_5 . V_159 = 0 ;
V_2 -> V_5 . V_1318 = V_1319 + V_681 ;
V_2 -> V_5 . V_1054 = F_659 ( V_2 ) ;
V_2 -> V_5 . V_1320 = V_1321 ;
F_1 ( V_2 ) ;
F_660 ( V_2 ) ;
V_2 -> V_5 . V_618 = - 1 ;
V_2 -> V_5 . V_608 = false ;
F_661 ( V_2 ) ;
return 0 ;
V_1317:
F_207 ( V_2 -> V_5 . V_386 ) ;
V_1316:
F_662 ( V_2 ) ;
V_1314:
F_663 ( V_2 ) ;
V_1313:
F_664 ( ( unsigned long ) V_2 -> V_5 . V_913 ) ;
V_1312:
return V_126 ;
}
void F_665 ( struct V_1 * V_2 )
{
int V_507 ;
F_666 ( V_2 ) ;
F_667 ( V_2 ) ;
F_207 ( V_2 -> V_5 . V_386 ) ;
F_662 ( V_2 ) ;
V_507 = F_235 ( & V_2 -> V_144 -> V_508 ) ;
F_663 ( V_2 ) ;
F_236 ( & V_2 -> V_144 -> V_508 , V_507 ) ;
F_664 ( ( unsigned long ) V_2 -> V_5 . V_913 ) ;
if ( ! F_88 ( V_2 ) )
F_668 ( & V_1315 ) ;
}
void F_669 ( struct V_1 * V_2 , int V_24 )
{
V_92 -> V_1322 ( V_2 , V_24 ) ;
}
int F_670 ( struct V_144 * V_144 , unsigned long type )
{
if ( type )
return - V_599 ;
F_671 ( & V_144 -> V_5 . V_1323 ) ;
F_672 ( & V_144 -> V_5 . V_1324 ) ;
F_672 ( & V_144 -> V_5 . V_1325 ) ;
F_672 ( & V_144 -> V_5 . V_1326 ) ;
F_172 ( & V_144 -> V_5 . V_1327 , 0 ) ;
F_287 ( V_791 , & V_144 -> V_5 . V_1328 ) ;
F_287 ( V_1329 ,
& V_144 -> V_5 . V_1328 ) ;
F_673 ( & V_144 -> V_5 . V_323 ) ;
F_674 ( & V_144 -> V_5 . V_1330 ) ;
F_674 ( & V_144 -> V_5 . V_1169 . V_1331 ) ;
F_675 ( & V_144 -> V_5 . V_337 ) ;
V_144 -> V_5 . V_259 = - F_151 () ;
F_171 ( V_144 ) ;
F_676 ( & V_144 -> V_5 . V_373 , F_194 ) ;
F_676 ( & V_144 -> V_5 . V_375 , F_199 ) ;
F_677 ( V_144 ) ;
F_678 ( V_144 ) ;
if ( V_92 -> V_1332 )
return V_92 -> V_1332 ( V_144 ) ;
return 0 ;
}
static void F_679 ( struct V_1 * V_2 )
{
int V_126 ;
V_126 = V_603 ( V_2 ) ;
F_15 ( V_126 ) ;
F_571 ( V_2 ) ;
V_609 ( V_2 ) ;
}
static void F_680 ( struct V_144 * V_144 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_177 (i, vcpu, kvm) {
F_68 ( V_2 ) ;
F_679 ( V_2 ) ;
}
F_177 (i, vcpu, kvm)
F_633 ( V_2 ) ;
F_314 ( & V_144 -> V_766 ) ;
for ( V_3 = 0 ; V_3 < F_139 ( & V_144 -> V_306 ) ; V_3 ++ )
V_144 -> V_1333 [ V_3 ] = NULL ;
F_172 ( & V_144 -> V_306 , 0 ) ;
F_316 ( & V_144 -> V_766 ) ;
}
void F_681 ( struct V_144 * V_144 )
{
F_682 ( & V_144 -> V_5 . V_375 ) ;
F_682 ( & V_144 -> V_5 . V_373 ) ;
F_683 ( V_144 ) ;
}
int F_684 ( struct V_144 * V_144 , int V_1290 , T_6 V_401 , T_1 V_513 )
{
int V_3 , V_126 ;
unsigned long V_1334 ;
struct V_1335 * V_1336 = V_1335 ( V_144 ) ;
struct V_1337 * V_10 , V_900 ;
if ( F_30 ( V_1290 >= V_1338 ) )
return - V_599 ;
V_10 = F_685 ( V_1336 , V_1290 ) ;
if ( V_513 ) {
if ( V_10 -> V_1339 )
return - V_619 ;
V_1334 = F_686 ( NULL , 0 , V_513 , V_1340 | V_1341 ,
V_1342 | V_1343 , 0 ) ;
if ( F_204 ( ( void * ) V_1334 ) )
return F_205 ( ( void * ) V_1334 ) ;
} else {
if ( ! V_10 -> V_1339 )
return 0 ;
V_1334 = 0 ;
}
V_900 = * V_10 ;
for ( V_3 = 0 ; V_3 < V_1344 ; V_3 ++ ) {
struct V_1345 V_1346 ;
V_1346 . V_10 = V_1290 | ( V_3 << 16 ) ;
V_1346 . V_15 = 0 ;
V_1346 . V_1347 = V_401 ;
V_1346 . V_1348 = V_1334 ;
V_1346 . V_1349 = V_513 ;
V_126 = F_687 ( V_144 , & V_1346 ) ;
if ( V_126 < 0 )
return V_126 ;
}
if ( ! V_513 ) {
V_126 = F_688 ( V_900 . V_1348 , V_900 . V_1339 * V_112 ) ;
F_30 ( V_126 < 0 ) ;
}
return 0 ;
}
int F_689 ( struct V_144 * V_144 , int V_1290 , T_6 V_401 , T_1 V_513 )
{
int V_126 ;
F_314 ( & V_144 -> V_751 ) ;
V_126 = F_684 ( V_144 , V_1290 , V_401 , V_513 ) ;
F_316 ( & V_144 -> V_751 ) ;
return V_126 ;
}
void F_690 ( struct V_144 * V_144 )
{
if ( V_414 -> V_1350 == V_144 -> V_1350 ) {
F_689 ( V_144 , V_1351 , 0 , 0 ) ;
F_689 ( V_144 , V_1352 , 0 , 0 ) ;
F_689 ( V_144 , V_1353 , 0 , 0 ) ;
}
if ( V_92 -> V_1354 )
V_92 -> V_1354 ( V_144 ) ;
F_341 ( V_144 ) ;
F_343 ( V_144 ) ;
F_680 ( V_144 ) ;
F_691 ( F_692 ( V_144 -> V_5 . V_1355 , 1 ) ) ;
F_693 ( V_144 ) ;
F_694 ( V_144 ) ;
}
void F_695 ( struct V_144 * V_144 , struct V_1337 * free ,
struct V_1337 * V_1356 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1357 ; ++ V_3 ) {
if ( ! V_1356 || free -> V_5 . V_1358 [ V_3 ] != V_1356 -> V_5 . V_1358 [ V_3 ] ) {
F_691 ( free -> V_5 . V_1358 [ V_3 ] ) ;
free -> V_5 . V_1358 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1356 || free -> V_5 . V_1359 [ V_3 - 1 ] !=
V_1356 -> V_5 . V_1359 [ V_3 - 1 ] ) {
F_691 ( free -> V_5 . V_1359 [ V_3 - 1 ] ) ;
free -> V_5 . V_1359 [ V_3 - 1 ] = NULL ;
}
}
F_696 ( free , V_1356 ) ;
}
int F_697 ( struct V_144 * V_144 , struct V_1337 * V_10 ,
unsigned long V_1339 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1357 ; ++ V_3 ) {
struct V_1360 * V_1361 ;
unsigned long V_1362 ;
int V_1363 ;
int V_792 = V_3 + 1 ;
V_1363 = F_698 ( V_10 -> V_1364 + V_1339 - 1 ,
V_10 -> V_1364 , V_792 ) + 1 ;
V_10 -> V_5 . V_1358 [ V_3 ] =
F_699 ( V_1363 * sizeof( * V_10 -> V_5 . V_1358 [ V_3 ] ) , V_712 ) ;
if ( ! V_10 -> V_5 . V_1358 [ V_3 ] )
goto V_400;
if ( V_3 == 0 )
continue;
V_1361 = F_699 ( V_1363 * sizeof( * V_1361 ) , V_712 ) ;
if ( ! V_1361 )
goto V_400;
V_10 -> V_5 . V_1359 [ V_3 - 1 ] = V_1361 ;
if ( V_10 -> V_1364 & ( F_700 ( V_792 ) - 1 ) )
V_1361 [ 0 ] . V_1365 = 1 ;
if ( ( V_10 -> V_1364 + V_1339 ) & ( F_700 ( V_792 ) - 1 ) )
V_1361 [ V_1363 - 1 ] . V_1365 = 1 ;
V_1362 = V_10 -> V_1348 >> V_111 ;
if ( ( V_10 -> V_1364 ^ V_1362 ) & ( F_700 ( V_792 ) - 1 ) ||
! F_701 () ) {
unsigned long V_840 ;
for ( V_840 = 0 ; V_840 < V_1363 ; ++ V_840 )
V_1361 [ V_840 ] . V_1365 = 1 ;
}
}
if ( F_702 ( V_10 , V_1339 ) )
goto V_400;
return 0 ;
V_400:
for ( V_3 = 0 ; V_3 < V_1357 ; ++ V_3 ) {
F_691 ( V_10 -> V_5 . V_1358 [ V_3 ] ) ;
V_10 -> V_5 . V_1358 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_691 ( V_10 -> V_5 . V_1359 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1359 [ V_3 - 1 ] = NULL ;
}
return - V_399 ;
}
void F_703 ( struct V_144 * V_144 , struct V_1335 * V_1336 )
{
F_704 ( V_144 , V_1336 ) ;
}
int F_705 ( struct V_144 * V_144 ,
struct V_1337 * V_1366 ,
const struct V_1345 * V_1367 ,
enum V_1368 V_1369 )
{
return 0 ;
}
static void F_706 ( struct V_144 * V_144 ,
struct V_1337 * V_901 )
{
if ( V_901 -> V_15 & V_1370 ) {
F_707 ( V_144 , V_901 ) ;
return;
}
if ( V_901 -> V_15 & V_1371 ) {
if ( V_92 -> V_1372 )
V_92 -> V_1372 ( V_144 , V_901 ) ;
else
F_707 ( V_144 , V_901 ) ;
} else {
if ( V_92 -> V_1373 )
V_92 -> V_1373 ( V_144 , V_901 ) ;
}
}
void F_708 ( struct V_144 * V_144 ,
const struct V_1345 * V_1367 ,
const struct V_1337 * V_900 ,
const struct V_1337 * V_901 ,
enum V_1368 V_1369 )
{
int V_1374 = 0 ;
if ( ! V_144 -> V_5 . V_752 )
V_1374 = F_709 ( V_144 ) ;
if ( V_1374 )
F_315 ( V_144 , V_1374 ) ;
if ( ( V_1369 != V_1375 ) &&
( V_900 -> V_15 & V_1371 ) &&
! ( V_901 -> V_15 & V_1371 ) )
F_710 ( V_144 , V_901 ) ;
if ( V_1369 != V_1375 )
F_706 ( V_144 , (struct V_1337 * ) V_901 ) ;
}
void F_711 ( struct V_144 * V_144 )
{
F_712 ( V_144 ) ;
}
void F_713 ( struct V_144 * V_144 ,
struct V_1337 * V_10 )
{
F_714 ( V_144 , V_10 ) ;
}
static inline bool F_715 ( struct V_1 * V_2 )
{
if ( ! F_716 ( & V_2 -> V_1376 . V_1377 ) )
return true ;
if ( F_717 ( V_2 ) )
return true ;
if ( V_2 -> V_5 . V_1191 . V_1192 )
return true ;
if ( V_2 -> V_5 . V_70 . V_71 )
return true ;
if ( F_718 ( V_90 , V_2 ) ||
( V_2 -> V_5 . V_646 &&
V_92 -> V_1122 ( V_2 ) ) )
return true ;
if ( F_718 ( V_620 , V_2 ) ||
( V_2 -> V_5 . V_652 && ! F_283 ( V_2 ) ) )
return true ;
if ( F_268 ( V_2 ) &&
F_269 ( V_2 ) )
return true ;
if ( F_719 ( V_2 ) )
return true ;
return false ;
}
int F_596 ( struct V_1 * V_2 )
{
return F_598 ( V_2 ) || F_715 ( V_2 ) ;
}
bool F_720 ( struct V_1 * V_2 )
{
return V_2 -> V_5 . V_608 ;
}
int F_721 ( struct V_1 * V_2 )
{
return F_722 ( V_2 ) == V_1176 ;
}
int F_268 ( struct V_1 * V_2 )
{
return V_92 -> V_1123 ( V_2 ) ;
}
unsigned long F_476 ( struct V_1 * V_2 )
{
if ( F_536 ( V_2 ) )
return F_456 ( V_2 ) ;
return ( T_1 ) ( F_406 ( V_2 , V_1133 ) +
F_456 ( V_2 ) ) ;
}
bool F_723 ( struct V_1 * V_2 , unsigned long V_1378 )
{
return F_476 ( V_2 ) == V_1378 ;
}
unsigned long F_455 ( struct V_1 * V_2 )
{
unsigned long V_1009 ;
V_1009 = V_92 -> V_1010 ( V_2 ) ;
if ( V_2 -> V_191 & V_1002 )
V_1009 &= ~ V_965 ;
return V_1009 ;
}
static void F_483 ( struct V_1 * V_2 , unsigned long V_1009 )
{
if ( V_2 -> V_191 & V_1002 &&
F_723 ( V_2 , V_2 -> V_5 . V_1006 ) )
V_1009 |= V_965 ;
V_92 -> V_1379 ( V_2 , V_1009 ) ;
}
void F_461 ( struct V_1 * V_2 , unsigned long V_1009 )
{
F_483 ( V_2 , V_1009 ) ;
F_32 ( V_69 , V_2 ) ;
}
void F_724 ( struct V_1 * V_2 , struct V_1380 * V_370 )
{
int V_126 ;
if ( ( V_2 -> V_5 . V_88 . V_993 != V_370 -> V_5 . V_993 ) ||
V_370 -> V_1381 )
return;
V_126 = F_579 ( V_2 ) ;
if ( F_165 ( V_126 ) )
return;
if ( ! V_2 -> V_5 . V_88 . V_993 &&
V_370 -> V_5 . V_109 != V_2 -> V_5 . V_88 . V_1382 ( V_2 ) )
return;
V_2 -> V_5 . V_88 . V_1383 ( V_2 , V_370 -> V_856 , 0 , true ) ;
}
static inline T_1 F_725 ( T_5 V_107 )
{
return F_726 ( V_107 & 0xffffffff , F_727 ( V_4 ) ) ;
}
static inline T_1 F_728 ( T_1 V_1384 )
{
return ( V_1384 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_729 ( struct V_1 * V_2 , T_5 V_107 )
{
T_1 V_1384 = F_725 ( V_107 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1384 ] != ~ 0 )
V_1384 = F_728 ( V_1384 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1384 ] = V_107 ;
}
static T_1 F_730 ( struct V_1 * V_2 , T_5 V_107 )
{
int V_3 ;
T_1 V_1384 = F_725 ( V_107 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1384 ] != V_107 &&
V_2 -> V_5 . V_6 . V_7 [ V_1384 ] != ~ 0 ) ; V_3 ++ )
V_1384 = F_728 ( V_1384 ) ;
return V_1384 ;
}
bool F_731 ( struct V_1 * V_2 , T_5 V_107 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_730 ( V_2 , V_107 ) ] == V_107 ;
}
static void F_732 ( struct V_1 * V_2 , T_5 V_107 )
{
T_1 V_3 , V_840 , V_1385 ;
V_3 = V_840 = F_730 ( V_2 , V_107 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_840 = F_728 ( V_840 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_840 ] == ~ 0 )
return;
V_1385 = F_725 ( V_2 -> V_5 . V_6 . V_7 [ V_840 ] ) ;
} while ( ( V_3 <= V_840 ) ? ( V_3 < V_1385 && V_1385 <= V_840 ) : ( V_3 < V_1385 || V_1385 <= V_840 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_840 ] ;
V_3 = V_840 ;
}
}
static int F_733 ( struct V_1 * V_2 , T_1 V_209 )
{
return F_188 ( V_2 -> V_144 , & V_2 -> V_5 . V_6 . V_39 , & V_209 ,
sizeof( V_209 ) ) ;
}
static int F_734 ( struct V_1 * V_2 , T_1 * V_209 )
{
return F_185 ( V_2 -> V_144 , & V_2 -> V_5 . V_6 . V_39 , V_209 ,
sizeof( T_1 ) ) ;
}
void F_735 ( struct V_1 * V_2 ,
struct V_1380 * V_370 )
{
struct V_76 V_77 ;
F_736 ( V_370 -> V_5 . V_1386 , V_370 -> V_856 ) ;
F_729 ( V_2 , V_370 -> V_5 . V_107 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_402 & V_403 ) ||
( V_2 -> V_5 . V_6 . V_404 &&
V_92 -> V_93 ( V_2 ) == 0 ) )
F_32 ( V_1152 , V_2 ) ;
else if ( ! F_733 ( V_2 , V_1387 ) ) {
V_77 . V_43 = V_44 ;
V_77 . V_962 = true ;
V_77 . V_64 = 0 ;
V_77 . V_85 = false ;
V_77 . V_83 = V_370 -> V_5 . V_1386 ;
V_77 . V_81 = true ;
F_40 ( V_2 , & V_77 ) ;
}
}
void F_737 ( struct V_1 * V_2 ,
struct V_1380 * V_370 )
{
struct V_76 V_77 ;
T_1 V_209 ;
if ( V_370 -> V_1381 )
V_370 -> V_5 . V_1386 = ~ 0 ;
else
F_732 ( V_2 , V_370 -> V_5 . V_107 ) ;
F_738 ( V_370 -> V_5 . V_1386 , V_370 -> V_856 ) ;
if ( V_2 -> V_5 . V_6 . V_402 & V_403 &&
! F_734 ( V_2 , & V_209 ) ) {
if ( V_209 == V_1387 &&
V_2 -> V_5 . V_70 . V_71 &&
V_2 -> V_5 . V_70 . V_18 == V_44 &&
! F_733 ( V_2 , 0 ) ) {
V_2 -> V_5 . V_70 . V_72 = false ;
V_2 -> V_5 . V_70 . V_71 = false ;
V_2 -> V_5 . V_70 . V_18 = 0 ;
V_2 -> V_5 . V_70 . V_74 = false ;
V_2 -> V_5 . V_70 . V_64 = 0 ;
} else if ( ! F_733 ( V_2 , V_1388 ) ) {
V_77 . V_43 = V_44 ;
V_77 . V_962 = true ;
V_77 . V_64 = 0 ;
V_77 . V_85 = false ;
V_77 . V_83 = V_370 -> V_5 . V_1386 ;
V_77 . V_81 = true ;
F_40 ( V_2 , & V_77 ) ;
}
}
V_2 -> V_5 . V_6 . V_1153 = false ;
V_2 -> V_5 . V_662 = V_1193 ;
}
bool F_739 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_402 & V_403 ) )
return true ;
else
return F_740 ( V_2 ) ;
}
void F_741 ( struct V_144 * V_144 )
{
F_46 ( & V_144 -> V_5 . V_1389 ) ;
}
void F_742 ( struct V_144 * V_144 )
{
F_743 ( & V_144 -> V_5 . V_1389 ) ;
}
bool F_744 ( struct V_144 * V_144 )
{
return F_139 ( & V_144 -> V_5 . V_1389 ) ;
}
void F_745 ( struct V_144 * V_144 )
{
F_46 ( & V_144 -> V_5 . V_1327 ) ;
}
void F_746 ( struct V_144 * V_144 )
{
F_743 ( & V_144 -> V_5 . V_1327 ) ;
}
bool F_70 ( struct V_144 * V_144 )
{
return F_139 ( & V_144 -> V_5 . V_1327 ) ;
}
bool F_747 ( void )
{
return V_92 -> V_1390 != NULL ;
}
int F_748 ( struct V_1391 * V_1392 ,
struct V_1393 * V_1394 )
{
struct V_1395 * V_1396 =
F_4 ( V_1392 , struct V_1395 , V_1397 ) ;
V_1396 -> V_1398 = V_1394 ;
return V_92 -> V_1390 ( V_1396 -> V_144 ,
V_1394 -> V_615 , V_1396 -> V_1399 , 1 ) ;
}
void F_749 ( struct V_1391 * V_1392 ,
struct V_1393 * V_1394 )
{
int V_113 ;
struct V_1395 * V_1396 =
F_4 ( V_1392 , struct V_1395 , V_1397 ) ;
F_30 ( V_1396 -> V_1398 != V_1394 ) ;
V_1396 -> V_1398 = NULL ;
V_113 = V_92 -> V_1390 ( V_1396 -> V_144 , V_1394 -> V_615 , V_1396 -> V_1399 , 0 ) ;
if ( V_113 )
F_12 ( V_1400 L_31
L_32 , V_1396 -> V_1397 . V_1386 , V_113 ) ;
}
int F_750 ( struct V_144 * V_144 , unsigned int V_1401 ,
T_7 V_1402 , bool V_1403 )
{
if ( ! V_92 -> V_1390 )
return - V_599 ;
return V_92 -> V_1390 ( V_144 , V_1401 , V_1402 , V_1403 ) ;
}
bool F_751 ( void )
{
return V_1404 ;
}
