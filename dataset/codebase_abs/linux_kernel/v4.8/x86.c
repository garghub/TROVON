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
if ( ( V_109 [ V_3 ] & V_114 ) &&
( V_109 [ V_3 ] &
V_2 -> V_5 . V_84 . V_115 . V_116 [ 0 ] [ 2 ] ) ) {
V_108 = 0 ;
goto V_113;
}
}
V_108 = 1 ;
memcpy ( V_84 -> V_110 , V_109 , sizeof( V_84 -> V_110 ) ) ;
F_53 ( V_117 ,
( unsigned long * ) & V_2 -> V_5 . V_118 ) ;
F_53 ( V_117 ,
( unsigned long * ) & V_2 -> V_5 . V_119 ) ;
V_113:
return V_108 ;
}
static bool F_54 ( struct V_1 * V_2 )
{
T_2 V_109 [ F_52 ( V_2 -> V_5 . V_103 -> V_110 ) ] ;
bool V_120 = true ;
int V_94 ;
T_5 V_102 ;
int V_121 ;
if ( F_55 ( V_2 ) || ! F_56 ( V_2 ) )
return false ;
if ( ! F_57 ( V_117 ,
( unsigned long * ) & V_2 -> V_5 . V_118 ) )
return true ;
V_102 = ( F_58 ( V_2 ) & ~ 31u ) >> V_106 ;
V_94 = ( F_58 ( V_2 ) & ~ 31u ) & ( V_107 - 1 ) ;
V_121 = F_50 ( V_2 , V_102 , V_109 , V_94 , sizeof( V_109 ) ,
V_111 | V_112 ) ;
if ( V_121 < 0 )
goto V_113;
V_120 = memcmp ( V_109 , V_2 -> V_5 . V_103 -> V_110 , sizeof( V_109 ) ) != 0 ;
V_113:
return V_120 ;
}
int F_59 ( struct V_1 * V_2 , unsigned long V_122 )
{
unsigned long V_123 = F_60 ( V_2 ) ;
unsigned long V_124 = V_125 | V_126 ;
V_122 |= V_127 ;
#ifdef F_61
if ( V_122 & 0xffffffff00000000UL )
return 1 ;
#endif
V_122 &= ~ V_128 ;
if ( ( V_122 & V_129 ) && ! ( V_122 & V_130 ) )
return 1 ;
if ( ( V_122 & V_125 ) && ! ( V_122 & V_131 ) )
return 1 ;
if ( ! F_62 ( V_2 ) && ( V_122 & V_125 ) ) {
#ifdef F_61
if ( ( V_2 -> V_5 . V_132 & V_133 ) ) {
int V_134 , V_135 ;
if ( ! F_56 ( V_2 ) )
return 1 ;
V_73 -> V_136 ( V_2 , & V_134 , & V_135 ) ;
if ( V_135 )
return 1 ;
} else
#endif
if ( F_56 ( V_2 ) && ! F_51 ( V_2 , V_2 -> V_5 . V_103 ,
F_58 ( V_2 ) ) )
return 1 ;
}
if ( ! ( V_122 & V_125 ) && F_45 ( V_2 , V_137 ) )
return 1 ;
V_73 -> V_138 ( V_2 , V_122 ) ;
if ( ( V_122 ^ V_123 ) & V_125 ) {
F_63 ( V_2 ) ;
F_1 ( V_2 ) ;
}
if ( ( V_122 ^ V_123 ) & V_124 )
F_64 ( V_2 ) ;
if ( ( ( V_122 ^ V_123 ) & V_130 ) &&
F_65 ( V_2 -> V_139 ) &&
! F_66 ( V_2 -> V_139 , V_140 ) )
F_67 ( V_2 -> V_139 , 0 , ~ 0ULL ) ;
return 0 ;
}
void F_68 ( struct V_1 * V_2 , unsigned long V_141 )
{
( void ) F_59 ( V_2 , F_69 ( V_2 , ~ 0x0eul ) | ( V_141 & 0x0f ) ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
if ( F_45 ( V_2 , V_142 ) &&
! V_2 -> V_143 ) {
F_71 ( V_144 , V_2 -> V_5 . V_145 ) ;
V_2 -> V_143 = 1 ;
}
}
static void F_72 ( struct V_1 * V_2 )
{
if ( V_2 -> V_143 ) {
if ( V_2 -> V_5 . V_145 != V_146 )
F_71 ( V_144 , V_146 ) ;
V_2 -> V_143 = 0 ;
}
}
static int F_73 ( struct V_1 * V_2 , T_1 V_147 , T_2 V_148 )
{
T_2 V_145 = V_148 ;
T_2 V_149 = V_2 -> V_5 . V_145 ;
T_2 V_150 ;
if ( V_147 != V_144 )
return 1 ;
if ( ! ( V_145 & V_151 ) )
return 1 ;
if ( ( V_145 & V_152 ) && ! ( V_145 & V_153 ) )
return 1 ;
V_150 = V_2 -> V_5 . V_154 | V_151 ;
if ( V_145 & ~ V_150 )
return 1 ;
if ( ( ! ( V_145 & V_155 ) ) !=
( ! ( V_145 & V_156 ) ) )
return 1 ;
if ( V_145 & V_157 ) {
if ( ! ( V_145 & V_152 ) )
return 1 ;
if ( ( V_145 & V_157 ) != V_157 )
return 1 ;
}
V_2 -> V_5 . V_145 = V_145 ;
if ( ( V_145 ^ V_149 ) & V_158 )
F_74 ( V_2 ) ;
return 0 ;
}
int F_75 ( struct V_1 * V_2 , T_1 V_147 , T_2 V_148 )
{
if ( V_73 -> V_88 ( V_2 ) != 0 ||
F_73 ( V_2 , V_147 , V_148 ) ) {
F_35 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_76 ( struct V_1 * V_2 , unsigned long V_159 )
{
unsigned long V_160 = F_77 ( V_2 ) ;
unsigned long V_161 = V_162 | V_163 | V_164 |
V_165 | V_166 | V_167 ;
if ( V_159 & V_168 )
return 1 ;
if ( ! F_78 ( V_2 ) && ( V_159 & V_142 ) )
return 1 ;
if ( ! F_79 ( V_2 ) && ( V_159 & V_165 ) )
return 1 ;
if ( ! F_80 ( V_2 ) && ( V_159 & V_166 ) )
return 1 ;
if ( ! F_81 ( V_2 ) && ( V_159 & V_169 ) )
return 1 ;
if ( ! F_82 ( V_2 ) && ( V_159 & V_167 ) )
return 1 ;
if ( F_55 ( V_2 ) ) {
if ( ! ( V_159 & V_164 ) )
return 1 ;
} else if ( F_62 ( V_2 ) && ( V_159 & V_164 )
&& ( ( V_159 ^ V_160 ) & V_161 )
&& ! F_51 ( V_2 , V_2 -> V_5 . V_103 ,
F_58 ( V_2 ) ) )
return 1 ;
if ( ( V_159 & V_137 ) && ! ( V_160 & V_137 ) ) {
if ( ! F_83 ( V_2 ) )
return 1 ;
if ( ( F_58 ( V_2 ) & V_170 ) || ! F_55 ( V_2 ) )
return 1 ;
}
if ( V_73 -> V_171 ( V_2 , V_159 ) )
return 1 ;
if ( ( ( V_159 ^ V_160 ) & V_161 ) ||
( ! ( V_159 & V_137 ) && ( V_160 & V_137 ) ) )
F_64 ( V_2 ) ;
if ( ( V_159 ^ V_160 ) & ( V_142 | V_167 ) )
F_74 ( V_2 ) ;
return 0 ;
}
int F_84 ( struct V_1 * V_2 , unsigned long V_104 )
{
#ifdef F_61
V_104 &= ~ V_172 ;
#endif
if ( V_104 == F_58 ( V_2 ) && ! F_54 ( V_2 ) ) {
F_85 ( V_2 ) ;
F_30 ( V_173 , V_2 ) ;
return 0 ;
}
if ( F_55 ( V_2 ) ) {
if ( V_104 & V_174 )
return 1 ;
} else if ( F_56 ( V_2 ) && F_62 ( V_2 ) &&
! F_51 ( V_2 , V_2 -> V_5 . V_103 , V_104 ) )
return 1 ;
V_2 -> V_5 . V_104 = V_104 ;
F_53 ( V_175 , ( V_176 * ) & V_2 -> V_5 . V_118 ) ;
F_86 ( V_2 ) ;
return 0 ;
}
int F_87 ( struct V_1 * V_2 , unsigned long V_177 )
{
if ( V_177 & V_178 )
return 1 ;
if ( F_88 ( V_2 ) )
F_89 ( V_2 , V_177 ) ;
else
V_2 -> V_5 . V_177 = V_177 ;
return 0 ;
}
unsigned long F_90 ( struct V_1 * V_2 )
{
if ( F_88 ( V_2 ) )
return F_91 ( V_2 ) ;
else
return V_2 -> V_5 . V_177 ;
}
static void F_92 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! ( V_2 -> V_179 & V_180 ) ) {
for ( V_3 = 0 ; V_3 < V_181 ; V_3 ++ )
V_2 -> V_5 . V_182 [ V_3 ] = V_2 -> V_5 . V_183 [ V_3 ] ;
V_2 -> V_5 . V_184 |= V_185 ;
}
}
static void F_93 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_179 & V_180 ) )
V_73 -> V_186 ( V_2 , V_2 -> V_5 . V_187 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
unsigned long V_188 ;
if ( V_2 -> V_179 & V_180 )
V_188 = V_2 -> V_5 . V_189 ;
else
V_188 = V_2 -> V_5 . V_188 ;
V_73 -> V_190 ( V_2 , V_188 ) ;
V_2 -> V_5 . V_184 &= ~ V_191 ;
if ( V_188 & V_192 )
V_2 -> V_5 . V_184 |= V_191 ;
}
static T_2 F_95 ( struct V_1 * V_2 )
{
T_2 V_193 = V_194 ;
if ( ! F_96 ( V_2 ) )
V_193 |= V_195 ;
return V_193 ;
}
static int F_97 ( struct V_1 * V_2 , int V_89 , unsigned long V_196 )
{
switch ( V_89 ) {
case 0 ... 3 :
V_2 -> V_5 . V_183 [ V_89 ] = V_196 ;
if ( ! ( V_2 -> V_179 & V_180 ) )
V_2 -> V_5 . V_182 [ V_89 ] = V_196 ;
break;
case 4 :
case 6 :
if ( V_196 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_187 = ( V_196 & V_197 ) | F_95 ( V_2 ) ;
F_93 ( V_2 ) ;
break;
case 5 :
default:
if ( V_196 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_188 = ( V_196 & V_198 ) | V_199 ;
F_94 ( V_2 ) ;
break;
}
return 0 ;
}
int F_98 ( struct V_1 * V_2 , int V_89 , unsigned long V_196 )
{
if ( F_97 ( V_2 , V_89 , V_196 ) ) {
F_35 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_99 ( struct V_1 * V_2 , int V_89 , unsigned long * V_196 )
{
switch ( V_89 ) {
case 0 ... 3 :
* V_196 = V_2 -> V_5 . V_183 [ V_89 ] ;
break;
case 4 :
case 6 :
if ( V_2 -> V_179 & V_180 )
* V_196 = V_2 -> V_5 . V_187 ;
else
* V_196 = V_73 -> V_200 ( V_2 ) ;
break;
case 5 :
default:
* V_196 = V_2 -> V_5 . V_188 ;
break;
}
return 0 ;
}
bool F_100 ( struct V_1 * V_2 )
{
T_1 V_201 = F_101 ( V_2 , V_202 ) ;
T_2 V_38 ;
int V_29 ;
V_29 = F_102 ( V_2 , V_201 , & V_38 ) ;
if ( V_29 )
return V_29 ;
F_103 ( V_2 , V_203 , ( T_1 ) V_38 ) ;
F_103 ( V_2 , V_204 , V_38 >> 32 ) ;
return V_29 ;
}
bool F_104 ( struct V_1 * V_2 , T_2 V_132 )
{
if ( V_132 & V_205 )
return false ;
if ( V_132 & V_206 ) {
struct V_207 * V_208 ;
V_208 = F_105 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_208 || ! ( V_208 -> V_209 & F_106 ( V_210 ) ) )
return false ;
}
if ( V_132 & V_211 ) {
struct V_207 * V_208 ;
V_208 = F_105 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_208 || ! ( V_208 -> V_201 & F_106 ( V_212 ) ) )
return false ;
}
return true ;
}
static int F_107 ( struct V_1 * V_2 , T_2 V_132 )
{
T_2 V_213 = V_2 -> V_5 . V_132 ;
if ( ! F_104 ( V_2 , V_132 ) )
return 1 ;
if ( F_62 ( V_2 )
&& ( V_2 -> V_5 . V_132 & V_133 ) != ( V_132 & V_133 ) )
return 1 ;
V_132 &= ~ V_214 ;
V_132 |= V_2 -> V_5 . V_132 & V_214 ;
V_73 -> F_107 ( V_2 , V_132 ) ;
if ( ( V_132 ^ V_213 ) & V_215 )
F_64 ( V_2 ) ;
return 0 ;
}
void F_108 ( T_2 V_28 )
{
V_205 &= ~ V_28 ;
}
int F_109 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
switch ( V_21 -> V_147 ) {
case V_216 :
case V_217 :
case V_218 :
case V_219 :
case V_220 :
if ( F_110 ( V_21 -> V_38 ) )
return 1 ;
break;
case V_221 :
case V_222 :
V_21 -> V_38 = F_111 ( V_21 -> V_38 ) ;
}
return V_73 -> V_223 ( V_2 , V_21 ) ;
}
static int F_112 ( struct V_1 * V_2 , unsigned V_147 , T_2 * V_38 )
{
struct V_32 V_21 ;
int V_121 ;
V_21 . V_147 = V_147 ;
V_21 . V_40 = true ;
V_121 = F_113 ( V_2 , & V_21 ) ;
if ( V_121 )
return V_121 ;
* V_38 = V_21 . V_38 ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 , unsigned V_147 , T_2 * V_38 )
{
struct V_32 V_21 ;
V_21 . V_38 = * V_38 ;
V_21 . V_147 = V_147 ;
V_21 . V_40 = true ;
return F_109 ( V_2 , & V_21 ) ;
}
static void F_115 ( struct V_224 * V_225 )
{
struct V_226 * V_227 = & V_226 ;
T_2 V_228 ;
V_228 = F_116 ( F_117 ( V_225 -> V_229 . V_230 , V_225 -> V_231 ) ) ;
F_118 ( & V_227 -> V_232 ) ;
V_227 -> clock . V_233 = V_225 -> V_229 . clock -> V_234 . V_233 ;
V_227 -> clock . V_235 = V_225 -> V_229 . V_235 ;
V_227 -> clock . V_28 = V_225 -> V_229 . V_28 ;
V_227 -> clock . V_236 = V_225 -> V_229 . V_236 ;
V_227 -> clock . V_237 = V_225 -> V_229 . V_237 ;
V_227 -> V_228 = V_228 ;
V_227 -> V_238 = V_225 -> V_229 . V_239 ;
F_119 ( & V_227 -> V_232 ) ;
}
void F_120 ( struct V_1 * V_2 )
{
F_30 ( V_240 , V_2 ) ;
}
static void F_121 ( struct V_139 * V_139 , T_6 V_241 )
{
int V_242 ;
int V_121 ;
struct V_243 V_244 ;
struct V_245 V_246 ;
if ( ! V_241 )
return;
V_121 = F_122 ( V_139 , V_241 , & V_242 , sizeof( V_242 ) ) ;
if ( V_121 )
return;
if ( V_242 & 1 )
++ V_242 ;
++ V_242 ;
if ( F_123 ( V_139 , V_241 , & V_242 , sizeof( V_242 ) ) )
return;
F_124 ( & V_246 ) ;
if ( V_139 -> V_5 . V_247 ) {
struct V_245 V_248 = F_125 ( V_139 -> V_5 . V_247 ) ;
V_246 = F_126 ( V_246 , V_248 ) ;
}
V_244 . V_249 = ( T_1 ) V_246 . V_250 ;
V_244 . V_251 = V_246 . V_252 ;
V_244 . V_242 = V_242 ;
F_123 ( V_139 , V_241 , & V_244 , sizeof( V_244 ) ) ;
V_242 ++ ;
F_123 ( V_139 , V_241 , & V_242 , sizeof( V_242 ) ) ;
}
static T_7 F_127 ( T_7 V_253 , T_7 V_254 )
{
F_128 ( V_253 , V_254 ) ;
return V_253 ;
}
static void F_129 ( T_8 V_255 , T_8 V_256 ,
T_9 * V_257 , T_1 * V_258 )
{
T_8 V_259 ;
T_10 V_237 = 0 ;
T_8 V_260 ;
T_7 V_261 ;
V_260 = V_256 ;
V_259 = V_255 ;
while ( V_260 > V_259 * 2 || V_260 & 0xffffffff00000000ULL ) {
V_260 >>= 1 ;
V_237 -- ;
}
V_261 = ( T_7 ) V_260 ;
while ( V_261 <= V_259 || V_259 & 0xffffffff00000000ULL ) {
if ( V_259 & 0xffffffff00000000ULL || V_261 & 0x80000000 )
V_259 >>= 1 ;
else
V_261 <<= 1 ;
V_237 ++ ;
}
* V_257 = V_237 ;
* V_258 = F_127 ( V_259 , V_261 ) ;
F_130 ( L_2 ,
V_262 , V_256 , V_255 , V_237 , * V_258 ) ;
}
static T_1 F_131 ( T_1 V_263 , T_11 V_264 )
{
T_2 V_265 = ( T_2 ) V_263 * ( 1000000 + V_264 ) ;
F_132 ( V_265 , 1000000 ) ;
return V_265 ;
}
static int F_133 ( struct V_1 * V_2 , T_1 V_266 , bool V_267 )
{
T_2 V_268 ;
if ( ! V_267 ) {
V_2 -> V_5 . V_269 = V_270 ;
return 0 ;
}
if ( ! V_271 ) {
if ( V_266 > V_272 ) {
V_2 -> V_5 . V_273 = 1 ;
V_2 -> V_5 . V_274 = 1 ;
return 0 ;
} else {
F_134 ( 1 , L_3 ) ;
return - 1 ;
}
}
V_268 = F_135 ( 1ULL << V_275 ,
V_266 , V_272 ) ;
if ( V_268 == 0 || V_268 >= V_276 ) {
F_136 ( 1 , L_4 ,
V_266 ) ;
return - 1 ;
}
V_2 -> V_5 . V_269 = V_268 ;
return 0 ;
}
static int F_137 ( struct V_1 * V_2 , T_1 V_266 )
{
T_1 V_277 , V_278 ;
int V_279 = 0 ;
if ( V_266 == 0 ) {
V_2 -> V_5 . V_269 = V_270 ;
return - 1 ;
}
F_129 ( V_266 * 1000LL , V_280 ,
& V_2 -> V_5 . V_281 ,
& V_2 -> V_5 . V_282 ) ;
V_2 -> V_5 . V_283 = V_266 ;
V_277 = F_131 ( V_272 , - V_284 ) ;
V_278 = F_131 ( V_272 , V_284 ) ;
if ( V_266 < V_277 || V_266 > V_278 ) {
F_130 ( L_5 , V_266 , V_277 , V_278 ) ;
V_279 = 1 ;
}
return F_133 ( V_2 , V_266 , V_279 ) ;
}
static T_2 F_138 ( struct V_1 * V_2 , T_12 V_285 )
{
T_2 V_286 = F_139 ( V_285 - V_2 -> V_5 . V_287 ,
V_2 -> V_5 . V_282 ,
V_2 -> V_5 . V_281 ) ;
V_286 += V_2 -> V_5 . V_288 ;
return V_286 ;
}
static void F_140 ( struct V_1 * V_2 )
{
#ifdef F_61
bool V_289 ;
struct V_290 * V_291 = & V_2 -> V_139 -> V_5 ;
struct V_226 * V_292 = & V_226 ;
V_289 = ( V_291 -> V_293 + 1 ==
F_141 ( & V_2 -> V_139 -> V_294 ) ) ;
if ( V_291 -> V_295 ||
( V_292 -> clock . V_233 == V_296 && V_289 ) )
F_30 ( V_297 , V_2 ) ;
F_142 ( V_2 -> V_298 , V_291 -> V_293 ,
F_141 ( & V_2 -> V_139 -> V_294 ) ,
V_291 -> V_295 , V_292 -> clock . V_233 ) ;
#endif
}
static void F_143 ( struct V_1 * V_2 , T_12 V_94 )
{
T_2 V_299 = V_73 -> V_300 ( V_2 ) ;
V_2 -> V_5 . V_301 += V_94 - V_299 ;
}
static inline T_2 F_144 ( T_2 V_268 , T_2 V_286 )
{
return F_145 ( V_286 , V_268 , V_275 ) ;
}
T_2 F_146 ( struct V_1 * V_2 , T_2 V_286 )
{
T_2 V_302 = V_286 ;
T_2 V_268 = V_2 -> V_5 . V_269 ;
if ( V_268 != V_270 )
V_302 = F_144 ( V_268 , V_286 ) ;
return V_302 ;
}
static T_2 F_147 ( struct V_1 * V_2 , T_2 V_303 )
{
T_2 V_286 ;
V_286 = F_146 ( V_2 , F_148 () ) ;
return V_303 - V_286 ;
}
T_2 F_149 ( struct V_1 * V_2 , T_2 V_304 )
{
return V_73 -> V_305 ( V_2 , F_146 ( V_2 , V_304 ) ) ;
}
void F_150 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
struct V_139 * V_139 = V_2 -> V_139 ;
T_2 V_94 , V_306 , V_307 ;
unsigned long V_308 ;
T_12 V_309 ;
bool V_310 ;
bool V_311 ;
T_2 V_38 = V_21 -> V_38 ;
F_151 ( & V_139 -> V_5 . V_312 , V_308 ) ;
V_94 = F_147 ( V_2 , V_38 ) ;
V_306 = F_152 () ;
V_307 = V_306 - V_139 -> V_5 . V_313 ;
if ( V_2 -> V_5 . V_283 ) {
int V_314 = 0 ;
V_309 = V_38 - V_139 -> V_5 . V_315 ;
#ifdef F_61
V_309 = ( V_309 * 1000 ) / V_2 -> V_5 . V_283 ;
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
F_132 ( V_307 , 1000 ) ;
V_309 -= V_307 ;
if ( V_309 < 0 )
V_309 = - V_309 ;
if ( V_314 )
V_309 = V_316 ;
} else
V_309 = V_316 ;
if ( V_309 < V_316 &&
V_2 -> V_5 . V_283 == V_139 -> V_5 . V_317 ) {
if ( ! F_153 () ) {
V_94 = V_139 -> V_5 . V_318 ;
F_130 ( L_6 , V_38 ) ;
} else {
T_2 V_319 = F_154 ( V_2 , V_307 ) ;
V_38 += V_319 ;
V_94 = F_147 ( V_2 , V_38 ) ;
F_130 ( L_7 , V_319 ) ;
}
V_310 = true ;
V_311 = ( V_2 -> V_5 . V_320 == V_139 -> V_5 . V_321 ) ;
} else {
V_139 -> V_5 . V_321 ++ ;
V_139 -> V_5 . V_322 = V_306 ;
V_139 -> V_5 . V_323 = V_38 ;
V_139 -> V_5 . V_318 = V_94 ;
V_310 = false ;
F_130 ( L_8 ,
V_139 -> V_5 . V_321 , V_38 ) ;
}
V_139 -> V_5 . V_313 = V_306 ;
V_139 -> V_5 . V_315 = V_38 ;
V_139 -> V_5 . V_317 = V_2 -> V_5 . V_283 ;
V_2 -> V_5 . V_324 = V_38 ;
V_2 -> V_5 . V_320 = V_139 -> V_5 . V_321 ;
V_2 -> V_5 . V_287 = V_139 -> V_5 . V_322 ;
V_2 -> V_5 . V_288 = V_139 -> V_5 . V_323 ;
if ( F_155 ( V_2 ) && ! V_21 -> V_40 )
F_143 ( V_2 , V_94 ) ;
V_73 -> V_325 ( V_2 , V_94 ) ;
F_156 ( & V_139 -> V_5 . V_312 , V_308 ) ;
F_157 ( & V_139 -> V_5 . V_326 ) ;
if ( ! V_310 ) {
V_139 -> V_5 . V_293 = 0 ;
} else if ( ! V_311 ) {
V_139 -> V_5 . V_293 ++ ;
}
F_140 ( V_2 ) ;
F_158 ( & V_139 -> V_5 . V_326 ) ;
}
static inline void F_159 ( struct V_1 * V_2 ,
T_12 V_327 )
{
V_73 -> F_159 ( V_2 , V_327 ) ;
}
static inline void F_160 ( struct V_1 * V_2 , T_12 V_327 )
{
if ( V_2 -> V_5 . V_269 != V_270 )
F_28 ( V_327 < 0 ) ;
V_327 = F_146 ( V_2 , ( T_2 ) V_327 ) ;
V_73 -> F_159 ( V_2 , V_327 ) ;
}
static T_13 F_161 ( void )
{
T_13 V_108 = ( T_13 ) F_162 () ;
T_2 V_328 = V_226 . clock . V_235 ;
if ( F_163 ( V_108 >= V_328 ) )
return V_108 ;
asm volatile ("");
return V_328 ;
}
static inline T_2 F_164 ( T_13 * V_329 )
{
long V_265 ;
struct V_226 * V_292 = & V_226 ;
* V_329 = F_161 () ;
V_265 = ( * V_329 - V_292 -> clock . V_235 ) & V_292 -> clock . V_28 ;
return V_265 * V_292 -> clock . V_236 ;
}
static int F_165 ( T_12 * V_330 , T_13 * V_329 )
{
struct V_226 * V_292 = & V_226 ;
unsigned long V_232 ;
int V_331 ;
T_2 V_306 ;
do {
V_232 = F_166 ( & V_292 -> V_232 ) ;
V_331 = V_292 -> clock . V_233 ;
V_306 = V_292 -> V_238 ;
V_306 += F_164 ( V_329 ) ;
V_306 >>= V_292 -> clock . V_237 ;
V_306 += V_292 -> V_228 ;
} while ( F_167 ( F_168 ( & V_292 -> V_232 , V_232 ) ) );
* V_330 = V_306 ;
return V_331 ;
}
static bool F_169 ( T_12 * V_285 , T_13 * V_329 )
{
if ( V_226 . clock . V_233 != V_296 )
return false ;
return F_165 ( V_285 , V_329 ) == V_296 ;
}
static void F_170 ( struct V_139 * V_139 )
{
#ifdef F_61
struct V_290 * V_291 = & V_139 -> V_5 ;
int V_233 ;
bool V_332 , V_289 ;
V_289 = ( V_291 -> V_293 + 1 ==
F_141 ( & V_139 -> V_294 ) ) ;
V_332 = F_169 (
& V_291 -> V_333 ,
& V_291 -> V_334 ) ;
V_291 -> V_295 = V_332 && V_289
&& ! V_335
&& ! V_291 -> V_336 ;
if ( V_291 -> V_295 )
F_171 ( & V_337 , 1 ) ;
V_233 = V_226 . clock . V_233 ;
F_172 ( V_291 -> V_295 , V_233 ,
V_289 ) ;
#endif
}
void F_173 ( struct V_139 * V_139 )
{
F_174 ( V_139 , V_338 ) ;
}
static void F_175 ( struct V_139 * V_139 )
{
#ifdef F_61
int V_3 ;
struct V_1 * V_2 ;
struct V_290 * V_291 = & V_139 -> V_5 ;
F_157 ( & V_291 -> V_326 ) ;
F_173 ( V_139 ) ;
F_170 ( V_139 ) ;
F_176 (i, vcpu, kvm)
F_30 ( V_339 , V_2 ) ;
F_176 (i, vcpu, kvm)
F_177 ( V_338 , & V_2 -> V_340 ) ;
F_158 ( & V_291 -> V_326 ) ;
#endif
}
static int F_178 ( struct V_1 * V_265 )
{
unsigned long V_308 , V_341 ;
struct V_342 * V_2 = & V_265 -> V_5 ;
struct V_290 * V_291 = & V_265 -> V_139 -> V_5 ;
T_12 V_285 ;
T_2 V_343 , V_304 ;
struct V_344 V_345 ;
T_14 V_346 ;
bool V_295 ;
V_285 = 0 ;
V_304 = 0 ;
F_157 ( & V_291 -> V_326 ) ;
V_295 = V_291 -> V_295 ;
if ( V_295 ) {
V_304 = V_291 -> V_334 ;
V_285 = V_291 -> V_333 ;
}
F_158 ( & V_291 -> V_326 ) ;
F_179 ( V_308 ) ;
V_341 = F_180 ( V_347 ) ;
if ( F_167 ( V_341 == 0 ) ) {
F_181 ( V_308 ) ;
F_30 ( V_339 , V_265 ) ;
return 1 ;
}
if ( ! V_295 ) {
V_304 = F_148 () ;
V_285 = F_152 () ;
}
V_343 = F_149 ( V_265 , V_304 ) ;
if ( V_2 -> V_273 ) {
T_2 V_286 = F_138 ( V_265 , V_285 ) ;
if ( V_286 > V_343 ) {
F_159 ( V_265 , V_286 - V_343 ) ;
V_343 = V_286 ;
}
}
F_181 ( V_308 ) ;
if ( ! V_2 -> V_348 )
return 0 ;
if ( V_271 )
V_341 = F_146 ( V_265 , V_341 ) ;
if ( F_167 ( V_2 -> V_349 != V_341 ) ) {
F_129 ( V_280 , V_341 * 1000LL ,
& V_2 -> V_350 . V_351 ,
& V_2 -> V_350 . V_352 ) ;
V_2 -> V_349 = V_341 ;
}
V_2 -> V_350 . V_343 = V_343 ;
V_2 -> V_350 . V_353 = V_285 + V_265 -> V_139 -> V_5 . V_247 ;
V_2 -> V_324 = V_343 ;
if ( F_167 ( F_182 ( V_265 -> V_139 , & V_2 -> V_354 ,
& V_345 , sizeof( V_345 ) ) ) )
return 0 ;
F_183 ( F_184 ( struct V_344 , V_242 ) != 0 ) ;
V_2 -> V_350 . V_242 = V_345 . V_242 + 1 ;
F_185 ( V_265 -> V_139 , & V_2 -> V_354 ,
& V_2 -> V_350 ,
sizeof( V_2 -> V_350 . V_242 ) ) ;
F_186 () ;
V_346 = ( V_345 . V_308 & V_355 ) ;
if ( V_2 -> V_356 ) {
V_346 |= V_355 ;
V_2 -> V_356 = false ;
}
if ( V_295 )
V_346 |= V_357 ;
V_2 -> V_350 . V_308 = V_346 ;
F_187 ( V_265 -> V_298 , & V_2 -> V_350 ) ;
F_185 ( V_265 -> V_139 , & V_2 -> V_354 ,
& V_2 -> V_350 ,
sizeof( V_2 -> V_350 ) ) ;
F_186 () ;
V_2 -> V_350 . V_242 ++ ;
F_185 ( V_265 -> V_139 , & V_2 -> V_354 ,
& V_2 -> V_350 ,
sizeof( V_2 -> V_350 . V_242 ) ) ;
return 0 ;
}
static void F_188 ( struct V_358 * V_359 )
{
int V_3 ;
struct V_360 * V_361 = F_189 ( V_359 ) ;
struct V_290 * V_291 = F_4 ( V_361 , struct V_290 ,
V_362 ) ;
struct V_139 * V_139 = F_4 ( V_291 , struct V_139 , V_5 ) ;
struct V_1 * V_2 ;
F_176 (i, vcpu, kvm) {
F_30 ( V_339 , V_2 ) ;
F_190 ( V_2 ) ;
}
}
static void F_191 ( struct V_1 * V_265 )
{
struct V_139 * V_139 = V_265 -> V_139 ;
F_30 ( V_339 , V_265 ) ;
F_192 ( & V_139 -> V_5 . V_362 ,
V_363 ) ;
}
static void F_193 ( struct V_358 * V_359 )
{
struct V_360 * V_361 = F_189 ( V_359 ) ;
struct V_290 * V_291 = F_4 ( V_361 , struct V_290 ,
V_364 ) ;
struct V_139 * V_139 = F_4 ( V_291 , struct V_139 , V_5 ) ;
if ( ! V_365 )
return;
F_192 ( & V_139 -> V_5 . V_362 , 0 ) ;
F_192 ( & V_139 -> V_5 . V_364 ,
V_366 ) ;
}
static int F_194 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
T_2 V_367 = V_2 -> V_5 . V_367 ;
unsigned V_368 = V_367 & 0xff ;
switch ( V_21 ) {
case V_369 :
V_2 -> V_5 . V_370 = V_38 ;
break;
case V_371 :
if ( ! ( V_367 & V_372 ) )
return 1 ;
if ( V_38 != 0 && V_38 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_373 = V_38 ;
break;
default:
if ( V_21 >= V_374 &&
V_21 < F_195 ( V_368 ) ) {
T_1 V_94 = V_21 - V_374 ;
if ( ( V_94 & 0x3 ) == 0 &&
V_38 != 0 && ( V_38 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_375 [ V_94 ] = V_38 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_196 ( struct V_1 * V_2 , T_2 V_38 )
{
struct V_139 * V_139 = V_2 -> V_139 ;
int V_376 = F_55 ( V_2 ) ;
T_14 * V_377 = V_376 ? ( T_14 * ) ( long ) V_139 -> V_5 . F_196 . V_378
: ( T_14 * ) ( long ) V_139 -> V_5 . F_196 . V_379 ;
T_14 V_380 = V_376 ? V_139 -> V_5 . F_196 . V_381
: V_139 -> V_5 . F_196 . V_382 ;
T_1 V_383 = V_38 & ~ V_384 ;
T_2 V_385 = V_38 & V_384 ;
T_14 * V_386 ;
int V_121 ;
V_121 = - V_387 ;
if ( V_383 >= V_380 )
goto V_113;
V_121 = - V_388 ;
V_386 = F_197 ( V_377 + ( V_383 * V_107 ) , V_107 ) ;
if ( F_198 ( V_386 ) ) {
V_121 = F_199 ( V_386 ) ;
goto V_113;
}
if ( F_200 ( V_2 , V_385 , V_386 , V_107 ) )
goto V_389;
V_121 = 0 ;
V_389:
F_201 ( V_386 ) ;
V_113:
return V_121 ;
}
static int F_202 ( struct V_1 * V_2 , T_2 V_38 )
{
T_6 V_390 = V_38 & ~ 0x3f ;
if ( V_38 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_391 = V_38 ;
if ( ! ( V_38 & V_392 ) ) {
F_63 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_203 ( V_2 -> V_139 , & V_2 -> V_5 . V_6 . V_38 , V_390 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_393 = ! ( V_38 & V_394 ) ;
F_204 ( V_2 ) ;
return 0 ;
}
static void F_205 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_348 = false ;
}
static void F_206 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_395 . V_391 & V_396 ) )
return;
if ( F_167 ( F_182 ( V_2 -> V_139 , & V_2 -> V_5 . V_395 . V_397 ,
& V_2 -> V_5 . V_395 . V_398 , sizeof( struct V_399 ) ) ) )
return;
if ( V_2 -> V_5 . V_395 . V_398 . V_242 & 1 )
V_2 -> V_5 . V_395 . V_398 . V_242 += 1 ;
V_2 -> V_5 . V_395 . V_398 . V_242 += 1 ;
F_185 ( V_2 -> V_139 , & V_2 -> V_5 . V_395 . V_397 ,
& V_2 -> V_5 . V_395 . V_398 , sizeof( struct V_399 ) ) ;
F_186 () ;
V_2 -> V_5 . V_395 . V_398 . V_398 += V_400 -> V_401 . V_402 -
V_2 -> V_5 . V_395 . V_403 ;
V_2 -> V_5 . V_395 . V_403 = V_400 -> V_401 . V_402 ;
F_185 ( V_2 -> V_139 , & V_2 -> V_5 . V_395 . V_397 ,
& V_2 -> V_5 . V_395 . V_398 , sizeof( struct V_399 ) ) ;
F_186 () ;
V_2 -> V_5 . V_395 . V_398 . V_242 += 1 ;
F_185 ( V_2 -> V_139 , & V_2 -> V_5 . V_395 . V_397 ,
& V_2 -> V_5 . V_395 . V_398 , sizeof( struct V_399 ) ) ;
}
int F_207 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
bool V_404 = false ;
T_1 V_21 = V_33 -> V_147 ;
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
return F_107 ( V_2 , V_38 ) ;
case V_412 :
V_38 &= ~ ( T_2 ) 0x40 ;
V_38 &= ~ ( T_2 ) 0x100 ;
V_38 &= ~ ( T_2 ) 0x8 ;
V_38 &= ~ ( T_2 ) 0x40000 ;
if ( V_38 != 0 ) {
F_208 ( V_2 , L_9 ,
V_38 ) ;
return 1 ;
}
break;
case V_413 :
if ( V_38 != 0 ) {
F_208 ( V_2 , L_10
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
F_208 ( V_2 , L_12 ,
V_262 , V_38 ) ;
break;
case 0x200 ... 0x2ff :
return F_209 ( V_2 , V_21 , V_38 ) ;
case V_417 :
return F_20 ( V_2 , V_33 ) ;
case V_418 ... V_418 + 0x3ff :
return F_210 ( V_2 , V_21 , V_38 ) ;
case V_419 :
F_211 ( V_2 , V_38 ) ;
break;
case V_420 :
if ( F_155 ( V_2 ) ) {
if ( ! V_33 -> V_40 ) {
T_12 V_421 = V_38 - V_2 -> V_5 . V_301 ;
F_159 ( V_2 , V_421 ) ;
}
V_2 -> V_5 . V_301 = V_38 ;
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
V_2 -> V_139 -> V_5 . V_241 = V_38 ;
F_121 ( V_2 -> V_139 , V_38 ) ;
break;
case V_428 :
case V_429 : {
T_2 V_430 ;
struct V_290 * V_291 = & V_2 -> V_139 -> V_5 ;
F_205 ( V_2 ) ;
if ( V_2 -> V_298 == 0 && ! V_33 -> V_40 ) {
bool V_431 = ( V_21 == V_429 ) ;
if ( V_291 -> V_336 != V_431 )
F_212 ( V_297 ,
& V_2 -> V_340 ) ;
V_291 -> V_336 = V_431 ;
}
V_2 -> V_5 . time = V_38 ;
F_30 ( V_432 , V_2 ) ;
if ( ! ( V_38 & 1 ) )
break;
V_430 = V_38 & ~ ( V_384 | 1 ) ;
if ( F_203 ( V_2 -> V_139 ,
& V_2 -> V_5 . V_354 , V_38 & ~ 1ULL ,
sizeof( struct V_344 ) ) )
V_2 -> V_5 . V_348 = false ;
else
V_2 -> V_5 . V_348 = true ;
break;
}
case V_433 :
if ( F_202 ( V_2 , V_38 ) )
return 1 ;
break;
case V_434 :
if ( F_167 ( ! F_213 () ) )
return 1 ;
if ( V_38 & V_435 )
return 1 ;
if ( F_203 ( V_2 -> V_139 , & V_2 -> V_5 . V_395 . V_397 ,
V_38 & V_436 ,
sizeof( struct V_399 ) ) )
return 1 ;
V_2 -> V_5 . V_395 . V_391 = V_38 ;
if ( ! ( V_38 & V_396 ) )
break;
F_30 ( V_437 , V_2 ) ;
break;
case V_438 :
if ( F_214 ( V_2 , V_38 ) )
return 1 ;
break;
case V_371 :
case V_369 :
case V_374 ... F_195 ( V_439 ) - 1 :
return F_194 ( V_2 , V_21 , V_38 ) ;
case V_440 ... V_441 :
case V_442 ... V_443 :
V_404 = true ;
case V_444 ... V_445 :
case V_446 ... V_447 :
if ( F_215 ( V_2 , V_21 ) )
return F_216 ( V_2 , V_33 ) ;
if ( V_404 || V_38 != 0 )
F_208 ( V_2 , L_13
L_14 , V_21 , V_38 ) ;
break;
case V_448 :
break;
case V_449 ... V_450 :
case V_451 ... V_452 :
case V_453 :
case V_454 ... V_455 :
return F_217 ( V_2 , V_21 , V_38 ,
V_33 -> V_40 ) ;
case V_456 :
F_208 ( V_2 , L_15 , V_21 , V_38 ) ;
break;
case V_457 :
if ( ! F_218 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_458 . V_459 = V_38 ;
break;
case V_460 :
if ( ! F_218 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_458 . V_461 = V_38 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_139 -> V_5 . F_196 . V_21 ) )
return F_196 ( V_2 , V_38 ) ;
if ( F_215 ( V_2 , V_21 ) )
return F_216 ( V_2 , V_33 ) ;
if ( ! V_462 ) {
F_208 ( V_2 , L_16 ,
V_21 , V_38 ) ;
return 1 ;
} else {
F_208 ( V_2 , L_15 ,
V_21 , V_38 ) ;
break;
}
}
return 0 ;
}
int F_113 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
return V_73 -> V_463 ( V_2 , V_21 ) ;
}
static int F_219 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_464 )
{
T_2 V_38 ;
T_2 V_367 = V_2 -> V_5 . V_367 ;
unsigned V_368 = V_367 & 0xff ;
switch ( V_21 ) {
case V_465 :
case V_466 :
V_38 = 0 ;
break;
case V_467 :
V_38 = V_2 -> V_5 . V_367 ;
break;
case V_371 :
if ( ! ( V_367 & V_372 ) )
return 1 ;
V_38 = V_2 -> V_5 . V_373 ;
break;
case V_369 :
V_38 = V_2 -> V_5 . V_370 ;
break;
default:
if ( V_21 >= V_374 &&
V_21 < F_195 ( V_368 ) ) {
T_1 V_94 = V_21 - V_374 ;
V_38 = V_2 -> V_5 . V_375 [ V_94 ] ;
break;
}
return 1 ;
}
* V_464 = V_38 ;
return 0 ;
}
int F_220 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
switch ( V_33 -> V_147 ) {
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
case V_478 :
V_33 -> V_38 = 0 ;
break;
case V_444 ... V_445 :
case V_440 ... V_441 :
case V_442 ... V_443 :
case V_446 ... V_447 :
if ( F_215 ( V_2 , V_33 -> V_147 ) )
return F_221 ( V_2 , V_33 -> V_147 , & V_33 -> V_38 ) ;
V_33 -> V_38 = 0 ;
break;
case V_406 :
V_33 -> V_38 = 0x100000000ULL ;
break;
case V_479 :
case 0x200 ... 0x2ff :
return F_222 ( V_2 , V_33 -> V_147 , & V_33 -> V_38 ) ;
case 0xcd :
V_33 -> V_38 = 3 ;
break;
case V_480 :
V_33 -> V_38 = 1 << 24 ;
break;
case V_417 :
V_33 -> V_38 = F_19 ( V_2 ) ;
break;
case V_418 ... V_418 + 0x3ff :
return F_223 ( V_2 , V_33 -> V_147 , & V_33 -> V_38 ) ;
break;
case V_419 :
V_33 -> V_38 = F_224 ( V_2 ) ;
break;
case V_420 :
V_33 -> V_38 = ( T_2 ) V_2 -> V_5 . V_301 ;
break;
case V_422 :
V_33 -> V_38 = V_2 -> V_5 . V_423 ;
break;
case V_424 :
if ( ! V_33 -> V_40 )
return 1 ;
V_33 -> V_38 = V_2 -> V_5 . V_425 ;
break;
case V_481 :
V_33 -> V_38 = 1000ULL ;
V_33 -> V_38 |= ( ( ( T_8 ) 4ULL ) << 40 ) ;
break;
case V_411 :
V_33 -> V_38 = V_2 -> V_5 . V_132 ;
break;
case V_427 :
case V_426 :
V_33 -> V_38 = V_2 -> V_139 -> V_5 . V_241 ;
break;
case V_429 :
case V_428 :
V_33 -> V_38 = V_2 -> V_5 . time ;
break;
case V_433 :
V_33 -> V_38 = V_2 -> V_5 . V_6 . V_391 ;
break;
case V_434 :
V_33 -> V_38 = V_2 -> V_5 . V_395 . V_391 ;
break;
case V_438 :
V_33 -> V_38 = V_2 -> V_5 . V_482 . V_391 ;
break;
case V_465 :
case V_466 :
case V_467 :
case V_371 :
case V_369 :
case V_374 ... F_195 ( V_439 ) - 1 :
return F_219 ( V_2 , V_33 -> V_147 , & V_33 -> V_38 ) ;
case V_448 :
V_33 -> V_38 = 0x20000000 ;
break;
case V_449 ... V_450 :
case V_451 ... V_452 :
case V_453 :
case V_454 ... V_455 :
return F_225 ( V_2 ,
V_33 -> V_147 , & V_33 -> V_38 ) ;
break;
case V_456 :
V_33 -> V_38 = 0xbe702111 ;
break;
case V_457 :
if ( ! F_218 ( V_2 ) )
return 1 ;
V_33 -> V_38 = V_2 -> V_5 . V_458 . V_459 ;
break;
case V_460 :
if ( ! F_218 ( V_2 ) )
return 1 ;
V_33 -> V_38 = V_2 -> V_5 . V_458 . V_461 ;
break;
default:
if ( F_215 ( V_2 , V_33 -> V_147 ) )
return F_221 ( V_2 , V_33 -> V_147 , & V_33 -> V_38 ) ;
if ( ! V_462 ) {
F_208 ( V_2 , L_17 , V_33 -> V_147 ) ;
return 1 ;
} else {
F_208 ( V_2 , L_18 , V_33 -> V_147 ) ;
V_33 -> V_38 = 0 ;
}
break;
}
return 0 ;
}
static int F_226 ( struct V_1 * V_2 , struct V_483 * V_19 ,
struct V_484 * V_485 ,
int (* F_227)( struct V_1 * V_2 ,
unsigned V_147 , T_2 * V_38 ) )
{
int V_3 , V_486 ;
V_486 = F_228 ( & V_2 -> V_139 -> V_487 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_488 ; ++ V_3 )
if ( F_227 ( V_2 , V_485 [ V_3 ] . V_147 , & V_485 [ V_3 ] . V_38 ) )
break;
F_229 ( & V_2 -> V_139 -> V_487 , V_486 ) ;
return V_3 ;
}
static int F_230 ( struct V_1 * V_2 , struct V_483 T_15 * V_489 ,
int (* F_227)( struct V_1 * V_2 ,
unsigned V_147 , T_2 * V_38 ) ,
int V_490 )
{
struct V_483 V_19 ;
struct V_484 * V_485 ;
int V_121 , V_491 ;
unsigned V_492 ;
V_121 = - V_101 ;
if ( F_231 ( & V_19 , V_489 , sizeof V_19 ) )
goto V_113;
V_121 = - V_387 ;
if ( V_19 . V_488 >= V_493 )
goto V_113;
V_492 = sizeof( struct V_484 ) * V_19 . V_488 ;
V_485 = F_197 ( V_489 -> V_485 , V_492 ) ;
if ( F_198 ( V_485 ) ) {
V_121 = F_199 ( V_485 ) ;
goto V_113;
}
V_121 = V_491 = F_226 ( V_2 , & V_19 , V_485 , F_227 ) ;
if ( V_121 < 0 )
goto V_389;
V_121 = - V_101 ;
if ( V_490 && F_232 ( V_489 -> V_485 , V_485 , V_492 ) )
goto V_389;
V_121 = V_491 ;
V_389:
F_201 ( V_485 ) ;
V_113:
return V_121 ;
}
int F_233 ( struct V_139 * V_139 , long V_494 )
{
int V_121 ;
switch ( V_494 ) {
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
case V_535 :
#ifdef F_234
case V_536 :
case V_537 :
#endif
V_121 = 1 ;
break;
case V_538 :
V_121 = V_73 -> V_539 () ;
break;
case V_540 :
V_121 = V_541 ;
break;
case V_542 :
V_121 = ! V_73 -> V_543 () ;
break;
case V_544 :
V_121 = V_545 ;
break;
case V_546 :
V_121 = V_547 ;
break;
case V_548 :
V_121 = V_549 ;
break;
case V_550 :
V_121 = 0 ;
break;
#ifdef F_234
case V_551 :
V_121 = F_235 ( & V_552 ) ;
break;
#endif
case V_553 :
V_121 = V_439 ;
break;
case V_554 :
V_121 = F_236 ( V_555 ) ;
break;
case V_556 :
V_121 = V_271 ;
break;
case V_557 :
V_121 = V_558 ;
break;
default:
V_121 = 0 ;
break;
}
return V_121 ;
}
long F_237 ( struct V_559 * V_560 ,
unsigned int V_561 , unsigned long V_562 )
{
void T_15 * V_563 = ( void T_15 * ) V_562 ;
long V_121 ;
switch ( V_561 ) {
case V_564 : {
struct V_565 T_15 * V_566 = V_563 ;
struct V_565 V_567 ;
unsigned V_491 ;
V_121 = - V_101 ;
if ( F_231 ( & V_567 , V_566 , sizeof V_567 ) )
goto V_113;
V_491 = V_567 . V_488 ;
V_567 . V_488 = V_568 + V_569 ;
if ( F_232 ( V_566 , & V_567 , sizeof V_567 ) )
goto V_113;
V_121 = - V_387 ;
if ( V_491 < V_567 . V_488 )
goto V_113;
V_121 = - V_101 ;
if ( F_232 ( V_566 -> V_570 , & V_571 ,
V_568 * sizeof( T_1 ) ) )
goto V_113;
if ( F_232 ( V_566 -> V_570 + V_568 ,
& V_572 ,
V_569 * sizeof( T_1 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_573 :
case V_574 : {
struct V_575 T_15 * V_576 = V_563 ;
struct V_575 V_577 ;
V_121 = - V_101 ;
if ( F_231 ( & V_577 , V_576 , sizeof V_577 ) )
goto V_113;
V_121 = F_238 ( & V_577 , V_576 -> V_485 ,
V_561 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_232 ( V_576 , & V_577 , sizeof V_577 ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_578 : {
V_121 = - V_101 ;
if ( F_232 ( V_563 , & V_579 ,
sizeof( V_579 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
default:
V_121 = - V_580 ;
}
V_113:
return V_121 ;
}
static void F_239 ( void * V_581 )
{
F_240 () ;
}
static bool F_241 ( struct V_1 * V_2 )
{
return F_65 ( V_2 -> V_139 ) ;
}
static inline void F_242 ( struct V_1 * V_2 )
{
F_212 ( V_582 , & V_2 -> V_340 ) ;
}
void F_243 ( struct V_1 * V_2 , int V_23 )
{
if ( F_241 ( V_2 ) ) {
if ( V_73 -> V_583 () )
F_244 ( V_23 , V_2 -> V_5 . V_584 ) ;
else if ( V_2 -> V_23 != - 1 && V_2 -> V_23 != V_23 )
F_245 ( V_2 -> V_23 ,
F_239 , NULL , 1 ) ;
}
V_73 -> V_585 ( V_2 , V_23 ) ;
if ( F_167 ( V_2 -> V_5 . V_586 ) ) {
F_160 ( V_2 , V_2 -> V_5 . V_586 ) ;
V_2 -> V_5 . V_586 = 0 ;
F_30 ( V_339 , V_2 ) ;
}
if ( F_167 ( V_2 -> V_23 != V_23 ) || F_153 () ) {
T_12 V_587 = ! V_2 -> V_5 . V_588 ? 0 :
F_148 () - V_2 -> V_5 . V_588 ;
if ( V_587 < 0 )
F_246 ( L_19 ) ;
if ( F_153 () ) {
T_2 V_94 = F_147 ( V_2 ,
V_2 -> V_5 . V_324 ) ;
V_73 -> V_325 ( V_2 , V_94 ) ;
V_2 -> V_5 . V_273 = 1 ;
}
if ( F_247 ( V_2 ) &&
V_73 -> V_589 ( V_2 ,
F_224 ( V_2 ) ) )
F_248 ( V_2 ) ;
if ( ! V_2 -> V_139 -> V_5 . V_295 || V_2 -> V_23 == - 1 )
F_30 ( V_432 , V_2 ) ;
if ( V_2 -> V_23 != V_23 )
F_242 ( V_2 ) ;
V_2 -> V_23 = V_23 ;
}
F_30 ( V_437 , V_2 ) ;
}
void F_249 ( struct V_1 * V_2 )
{
V_73 -> V_590 ( V_2 ) ;
F_250 ( V_2 ) ;
V_2 -> V_5 . V_588 = F_148 () ;
}
static int F_251 ( struct V_1 * V_2 ,
struct V_591 * V_592 )
{
if ( V_2 -> V_5 . V_593 )
V_73 -> V_594 ( V_2 ) ;
return F_252 ( V_2 , V_592 ) ;
}
static int F_253 ( struct V_1 * V_2 ,
struct V_591 * V_592 )
{
int V_121 ;
V_121 = F_254 ( V_2 , V_592 ) ;
if ( V_121 )
return V_121 ;
F_255 ( V_2 ) ;
return 0 ;
}
static int F_256 ( struct V_1 * V_2 )
{
return ( ! F_88 ( V_2 ) ||
F_257 ( V_2 ) ) ;
}
static int F_258 ( struct V_1 * V_2 )
{
return F_259 ( V_2 ) &&
! F_260 ( V_2 ) &&
! F_261 ( V_2 ) &&
F_256 ( V_2 ) ;
}
static int F_262 ( struct V_1 * V_2 ,
struct V_595 * V_596 )
{
if ( V_596 -> V_596 >= V_597 )
return - V_580 ;
if ( ! F_263 ( V_2 -> V_139 ) ) {
F_264 ( V_2 , V_596 -> V_596 , false ) ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
if ( F_265 ( V_2 -> V_139 ) )
return - V_598 ;
if ( V_2 -> V_5 . V_599 != - 1 )
return - V_600 ;
V_2 -> V_5 . V_599 = V_596 -> V_596 ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
static int F_266 ( struct V_1 * V_2 )
{
F_40 ( V_2 ) ;
return 0 ;
}
static int F_267 ( struct V_1 * V_2 )
{
F_30 ( V_601 , V_2 ) ;
return 0 ;
}
static int F_268 ( struct V_1 * V_2 ,
struct V_602 * V_603 )
{
if ( V_603 -> V_308 )
return - V_580 ;
V_2 -> V_5 . V_604 = ! ! V_603 -> V_605 ;
return 0 ;
}
static int F_269 ( struct V_1 * V_2 ,
T_2 V_367 )
{
int V_121 ;
unsigned V_368 = V_367 & 0xff , V_606 ;
V_121 = - V_580 ;
if ( ! V_368 || V_368 >= V_439 )
goto V_113;
if ( V_367 & ~ ( V_579 | 0xff | 0xff0000 ) )
goto V_113;
V_121 = 0 ;
V_2 -> V_5 . V_367 = V_367 ;
if ( V_367 & V_372 )
V_2 -> V_5 . V_373 = ~ ( T_2 ) 0 ;
for ( V_606 = 0 ; V_606 < V_368 ; V_606 ++ )
V_2 -> V_5 . V_375 [ V_606 * 4 ] = ~ ( T_2 ) 0 ;
if ( V_73 -> V_607 )
V_73 -> V_607 ( V_2 ) ;
V_113:
return V_121 ;
}
static int F_270 ( struct V_1 * V_2 ,
struct V_608 * V_609 )
{
T_2 V_367 = V_2 -> V_5 . V_367 ;
unsigned V_368 = V_367 & 0xff ;
T_2 * V_610 = V_2 -> V_5 . V_375 ;
if ( V_609 -> V_606 >= V_368 || ! ( V_609 -> V_461 & V_611 ) )
return - V_580 ;
if ( ( V_609 -> V_461 & V_612 ) && ( V_367 & V_372 ) &&
V_2 -> V_5 . V_373 != ~ ( T_2 ) 0 )
return 0 ;
V_610 += 4 * V_609 -> V_606 ;
if ( ( V_609 -> V_461 & V_612 ) && V_610 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_609 -> V_461 & V_612 ) {
if ( ( V_2 -> V_5 . V_370 & V_613 ) ||
! F_45 ( V_2 , V_614 ) ) {
F_30 ( V_72 , V_2 ) ;
return 0 ;
}
if ( V_610 [ 1 ] & V_611 )
V_609 -> V_461 |= V_615 ;
V_610 [ 2 ] = V_609 -> V_616 ;
V_610 [ 3 ] = V_609 -> V_617 ;
V_2 -> V_5 . V_370 = V_609 -> V_370 ;
V_610 [ 1 ] = V_609 -> V_461 ;
F_32 ( V_2 , V_58 ) ;
} else if ( ! ( V_610 [ 1 ] & V_611 )
|| ! ( V_610 [ 1 ] & V_612 ) ) {
if ( V_610 [ 1 ] & V_611 )
V_609 -> V_461 |= V_615 ;
V_610 [ 2 ] = V_609 -> V_616 ;
V_610 [ 3 ] = V_609 -> V_617 ;
V_610 [ 1 ] = V_609 -> V_461 ;
} else
V_610 [ 1 ] |= V_615 ;
return 0 ;
}
static void F_271 ( struct V_1 * V_2 ,
struct V_618 * V_619 )
{
F_272 ( V_2 ) ;
V_619 -> V_68 . V_620 =
V_2 -> V_5 . V_68 . V_69 &&
! F_273 ( V_2 -> V_5 . V_68 . V_16 ) ;
V_619 -> V_68 . V_16 = V_2 -> V_5 . V_68 . V_16 ;
V_619 -> V_68 . V_71 = V_2 -> V_5 . V_68 . V_71 ;
V_619 -> V_68 . V_621 = 0 ;
V_619 -> V_68 . V_62 = V_2 -> V_5 . V_68 . V_62 ;
V_619 -> V_622 . V_620 =
V_2 -> V_5 . V_622 . V_69 && ! V_2 -> V_5 . V_622 . V_623 ;
V_619 -> V_622 . V_16 = V_2 -> V_5 . V_622 . V_16 ;
V_619 -> V_622 . V_623 = 0 ;
V_619 -> V_622 . V_624 = V_73 -> V_625 ( V_2 ) ;
V_619 -> V_626 . V_620 = V_2 -> V_5 . V_627 ;
V_619 -> V_626 . V_69 = V_2 -> V_5 . V_628 != 0 ;
V_619 -> V_626 . V_629 = V_73 -> V_630 ( V_2 ) ;
V_619 -> V_626 . V_621 = 0 ;
V_619 -> V_631 = 0 ;
V_619 -> V_632 . V_633 = F_274 ( V_2 ) ;
V_619 -> V_632 . V_69 = V_2 -> V_5 . V_634 ;
V_619 -> V_632 . V_635 =
! ! ( V_2 -> V_5 . V_636 & V_637 ) ;
V_619 -> V_632 . V_638 = F_275 ( V_2 ) ;
V_619 -> V_308 = ( V_639
| V_640
| V_641 ) ;
memset ( & V_619 -> V_642 , 0 , sizeof( V_619 -> V_642 ) ) ;
}
static int F_276 ( struct V_1 * V_2 ,
struct V_618 * V_619 )
{
if ( V_619 -> V_308 & ~ ( V_639
| V_643
| V_640
| V_641 ) )
return - V_580 ;
if ( V_619 -> V_68 . V_620 &&
( V_619 -> V_68 . V_16 > 31 || V_619 -> V_68 . V_16 == V_51 ) )
return - V_580 ;
F_272 ( V_2 ) ;
V_2 -> V_5 . V_68 . V_69 = V_619 -> V_68 . V_620 ;
V_2 -> V_5 . V_68 . V_16 = V_619 -> V_68 . V_16 ;
V_2 -> V_5 . V_68 . V_71 = V_619 -> V_68 . V_71 ;
V_2 -> V_5 . V_68 . V_62 = V_619 -> V_68 . V_62 ;
V_2 -> V_5 . V_622 . V_69 = V_619 -> V_622 . V_620 ;
V_2 -> V_5 . V_622 . V_16 = V_619 -> V_622 . V_16 ;
V_2 -> V_5 . V_622 . V_623 = V_619 -> V_622 . V_623 ;
if ( V_619 -> V_308 & V_640 )
V_73 -> V_644 ( V_2 ,
V_619 -> V_622 . V_624 ) ;
V_2 -> V_5 . V_627 = V_619 -> V_626 . V_620 ;
if ( V_619 -> V_308 & V_639 )
V_2 -> V_5 . V_628 = V_619 -> V_626 . V_69 ;
V_73 -> V_645 ( V_2 , V_619 -> V_626 . V_629 ) ;
if ( V_619 -> V_308 & V_643 &&
F_88 ( V_2 ) )
V_2 -> V_5 . V_646 -> V_631 = V_619 -> V_631 ;
if ( V_619 -> V_308 & V_641 ) {
if ( V_619 -> V_632 . V_633 )
V_2 -> V_5 . V_636 |= V_647 ;
else
V_2 -> V_5 . V_636 &= ~ V_647 ;
V_2 -> V_5 . V_634 = V_619 -> V_632 . V_69 ;
if ( V_619 -> V_632 . V_635 )
V_2 -> V_5 . V_636 |= V_637 ;
else
V_2 -> V_5 . V_636 &= ~ V_637 ;
if ( F_88 ( V_2 ) ) {
if ( V_619 -> V_632 . V_638 )
F_212 ( V_648 , & V_2 -> V_5 . V_646 -> V_649 ) ;
else
F_177 ( V_648 , & V_2 -> V_5 . V_646 -> V_649 ) ;
}
}
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
static void F_277 ( struct V_1 * V_2 ,
struct V_650 * V_651 )
{
unsigned long V_196 ;
memcpy ( V_651 -> V_183 , V_2 -> V_5 . V_183 , sizeof( V_2 -> V_5 . V_183 ) ) ;
F_99 ( V_2 , 6 , & V_196 ) ;
V_651 -> V_187 = V_196 ;
V_651 -> V_188 = V_2 -> V_5 . V_188 ;
V_651 -> V_308 = 0 ;
memset ( & V_651 -> V_642 , 0 , sizeof( V_651 -> V_642 ) ) ;
}
static int F_278 ( struct V_1 * V_2 ,
struct V_650 * V_651 )
{
if ( V_651 -> V_308 )
return - V_580 ;
if ( V_651 -> V_187 & ~ 0xffffffffull )
return - V_580 ;
if ( V_651 -> V_188 & ~ 0xffffffffull )
return - V_580 ;
memcpy ( V_2 -> V_5 . V_183 , V_651 -> V_183 , sizeof( V_2 -> V_5 . V_183 ) ) ;
F_92 ( V_2 ) ;
V_2 -> V_5 . V_187 = V_651 -> V_187 ;
F_93 ( V_2 ) ;
V_2 -> V_5 . V_188 = V_651 -> V_188 ;
F_94 ( V_2 ) ;
return 0 ;
}
static void F_279 ( T_14 * V_652 , struct V_1 * V_2 )
{
struct V_653 * V_654 = & V_2 -> V_5 . V_655 . V_656 . V_654 ;
T_2 V_657 = V_654 -> V_658 . V_659 ;
T_2 V_660 ;
memcpy ( V_652 , V_654 , V_661 ) ;
* ( T_2 * ) ( V_652 + V_661 ) = V_657 ;
V_660 = V_657 & ~ V_662 ;
while ( V_660 ) {
T_2 V_663 = V_660 & - V_660 ;
int V_147 = F_280 ( V_663 ) - 1 ;
void * V_664 = F_281 ( V_654 , V_663 ) ;
if ( V_664 ) {
T_1 V_492 , V_94 , V_201 , V_209 ;
F_282 ( V_665 , V_147 ,
& V_492 , & V_94 , & V_201 , & V_209 ) ;
memcpy ( V_652 + V_94 , V_664 , V_492 ) ;
}
V_660 -= V_663 ;
}
}
static void F_283 ( struct V_1 * V_2 , T_14 * V_664 )
{
struct V_653 * V_654 = & V_2 -> V_5 . V_655 . V_656 . V_654 ;
T_2 V_657 = * ( T_2 * ) ( V_664 + V_661 ) ;
T_2 V_660 ;
memcpy ( V_654 , V_664 , V_661 ) ;
V_654 -> V_658 . V_659 = V_657 ;
if ( F_236 ( V_666 ) )
V_654 -> V_658 . V_667 = V_146 | V_668 ;
V_660 = V_657 & ~ V_662 ;
while ( V_660 ) {
T_2 V_663 = V_660 & - V_660 ;
int V_147 = F_280 ( V_663 ) - 1 ;
void * V_652 = F_281 ( V_654 , V_663 ) ;
if ( V_652 ) {
T_1 V_492 , V_94 , V_201 , V_209 ;
F_282 ( V_665 , V_147 ,
& V_492 , & V_94 , & V_201 , & V_209 ) ;
memcpy ( V_652 , V_664 + V_94 , V_492 ) ;
}
V_660 -= V_663 ;
}
}
static void F_284 ( struct V_1 * V_2 ,
struct V_669 * V_670 )
{
if ( F_236 ( V_555 ) ) {
memset ( V_670 , 0 , sizeof( struct V_669 ) ) ;
F_279 ( ( T_14 * ) V_670 -> V_671 , V_2 ) ;
} else {
memcpy ( V_670 -> V_671 ,
& V_2 -> V_5 . V_655 . V_656 . V_672 ,
sizeof( struct V_673 ) ) ;
* ( T_2 * ) & V_670 -> V_671 [ V_661 / sizeof( T_1 ) ] =
V_662 ;
}
}
static int F_285 ( struct V_1 * V_2 ,
struct V_669 * V_670 )
{
T_2 V_657 =
* ( T_2 * ) & V_670 -> V_671 [ V_661 / sizeof( T_1 ) ] ;
if ( F_236 ( V_555 ) ) {
if ( V_657 & ~ F_286 () )
return - V_580 ;
F_283 ( V_2 , ( T_14 * ) V_670 -> V_671 ) ;
} else {
if ( V_657 & ~ V_662 )
return - V_580 ;
memcpy ( & V_2 -> V_5 . V_655 . V_656 . V_672 ,
V_670 -> V_671 , sizeof( struct V_673 ) ) ;
}
return 0 ;
}
static void F_287 ( struct V_1 * V_2 ,
struct V_674 * V_675 )
{
if ( ! F_236 ( V_555 ) ) {
V_675 -> V_676 = 0 ;
return;
}
V_675 -> V_676 = 1 ;
V_675 -> V_308 = 0 ;
V_675 -> V_677 [ 0 ] . V_148 = V_144 ;
V_675 -> V_677 [ 0 ] . V_22 = V_2 -> V_5 . V_145 ;
}
static int F_288 ( struct V_1 * V_2 ,
struct V_674 * V_675 )
{
int V_3 , V_121 = 0 ;
if ( ! F_236 ( V_555 ) )
return - V_580 ;
if ( V_675 -> V_676 > V_678 || V_675 -> V_308 )
return - V_580 ;
for ( V_3 = 0 ; V_3 < V_675 -> V_676 ; V_3 ++ )
if ( V_675 -> V_677 [ V_3 ] . V_148 == V_144 ) {
V_121 = F_73 ( V_2 , V_144 ,
V_675 -> V_677 [ V_3 ] . V_22 ) ;
break;
}
if ( V_121 )
V_121 = - V_580 ;
return V_121 ;
}
static int F_289 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_348 )
return - V_580 ;
V_2 -> V_5 . V_356 = true ;
F_30 ( V_339 , V_2 ) ;
return 0 ;
}
static int F_290 ( struct V_1 * V_2 ,
struct V_679 * V_680 )
{
if ( V_680 -> V_308 )
return - V_580 ;
switch ( V_680 -> V_680 ) {
case V_520 :
return F_291 ( V_2 ) ;
default:
return - V_580 ;
}
}
long F_292 ( struct V_559 * V_560 ,
unsigned int V_561 , unsigned long V_562 )
{
struct V_1 * V_2 = V_560 -> V_681 ;
void T_15 * V_563 = ( void T_15 * ) V_562 ;
int V_121 ;
union {
struct V_591 * V_682 ;
struct V_669 * V_654 ;
struct V_674 * V_677 ;
void * V_683 ;
} V_684 ;
V_684 . V_683 = NULL ;
switch ( V_561 ) {
case V_685 : {
V_121 = - V_580 ;
if ( ! F_88 ( V_2 ) )
goto V_113;
V_684 . V_682 = F_293 ( sizeof( struct V_591 ) , V_686 ) ;
V_121 = - V_388 ;
if ( ! V_684 . V_682 )
goto V_113;
V_121 = F_251 ( V_2 , V_684 . V_682 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_232 ( V_563 , V_684 . V_682 , sizeof( struct V_591 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_687 : {
V_121 = - V_580 ;
if ( ! F_88 ( V_2 ) )
goto V_113;
V_684 . V_682 = F_197 ( V_563 , sizeof( * V_684 . V_682 ) ) ;
if ( F_198 ( V_684 . V_682 ) )
return F_199 ( V_684 . V_682 ) ;
V_121 = F_253 ( V_2 , V_684 . V_682 ) ;
break;
}
case V_688 : {
struct V_595 V_596 ;
V_121 = - V_101 ;
if ( F_231 ( & V_596 , V_563 , sizeof V_596 ) )
goto V_113;
V_121 = F_262 ( V_2 , & V_596 ) ;
break;
}
case V_689 : {
V_121 = F_266 ( V_2 ) ;
break;
}
case V_690 : {
V_121 = F_267 ( V_2 ) ;
break;
}
case V_691 : {
struct V_692 T_15 * V_576 = V_563 ;
struct V_692 V_577 ;
V_121 = - V_101 ;
if ( F_231 ( & V_577 , V_576 , sizeof V_577 ) )
goto V_113;
V_121 = F_294 ( V_2 , & V_577 , V_576 -> V_485 ) ;
break;
}
case V_693 : {
struct V_575 T_15 * V_576 = V_563 ;
struct V_575 V_577 ;
V_121 = - V_101 ;
if ( F_231 ( & V_577 , V_576 , sizeof V_577 ) )
goto V_113;
V_121 = F_295 ( V_2 , & V_577 ,
V_576 -> V_485 ) ;
break;
}
case V_694 : {
struct V_575 T_15 * V_576 = V_563 ;
struct V_575 V_577 ;
V_121 = - V_101 ;
if ( F_231 ( & V_577 , V_576 , sizeof V_577 ) )
goto V_113;
V_121 = F_296 ( V_2 , & V_577 ,
V_576 -> V_485 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_232 ( V_576 , & V_577 , sizeof V_577 ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_695 :
V_121 = F_230 ( V_2 , V_563 , F_112 , 1 ) ;
break;
case V_696 :
V_121 = F_230 ( V_2 , V_563 , F_114 , 0 ) ;
break;
case V_697 : {
struct V_602 V_603 ;
V_121 = - V_101 ;
if ( F_231 ( & V_603 , V_563 , sizeof V_603 ) )
goto V_113;
V_121 = F_268 ( V_2 , & V_603 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_232 ( V_563 , & V_603 , sizeof V_603 ) )
goto V_113;
V_121 = 0 ;
break;
} ;
case V_698 : {
struct V_699 V_700 ;
V_121 = - V_580 ;
if ( ! F_88 ( V_2 ) )
goto V_113;
V_121 = - V_101 ;
if ( F_231 ( & V_700 , V_563 , sizeof V_700 ) )
goto V_113;
V_121 = F_297 ( V_2 , V_700 . V_701 ) ;
break;
}
case V_702 : {
T_2 V_367 ;
V_121 = - V_101 ;
if ( F_231 ( & V_367 , V_563 , sizeof V_367 ) )
goto V_113;
V_121 = F_269 ( V_2 , V_367 ) ;
break;
}
case V_703 : {
struct V_608 V_609 ;
V_121 = - V_101 ;
if ( F_231 ( & V_609 , V_563 , sizeof V_609 ) )
goto V_113;
V_121 = F_270 ( V_2 , & V_609 ) ;
break;
}
case V_704 : {
struct V_618 V_619 ;
F_271 ( V_2 , & V_619 ) ;
V_121 = - V_101 ;
if ( F_232 ( V_563 , & V_619 , sizeof( struct V_618 ) ) )
break;
V_121 = 0 ;
break;
}
case V_705 : {
struct V_618 V_619 ;
V_121 = - V_101 ;
if ( F_231 ( & V_619 , V_563 , sizeof( struct V_618 ) ) )
break;
V_121 = F_276 ( V_2 , & V_619 ) ;
break;
}
case V_706 : {
struct V_650 V_651 ;
F_277 ( V_2 , & V_651 ) ;
V_121 = - V_101 ;
if ( F_232 ( V_563 , & V_651 ,
sizeof( struct V_650 ) ) )
break;
V_121 = 0 ;
break;
}
case V_707 : {
struct V_650 V_651 ;
V_121 = - V_101 ;
if ( F_231 ( & V_651 , V_563 ,
sizeof( struct V_650 ) ) )
break;
V_121 = F_278 ( V_2 , & V_651 ) ;
break;
}
case V_708 : {
V_684 . V_654 = F_293 ( sizeof( struct V_669 ) , V_686 ) ;
V_121 = - V_388 ;
if ( ! V_684 . V_654 )
break;
F_284 ( V_2 , V_684 . V_654 ) ;
V_121 = - V_101 ;
if ( F_232 ( V_563 , V_684 . V_654 , sizeof( struct V_669 ) ) )
break;
V_121 = 0 ;
break;
}
case V_709 : {
V_684 . V_654 = F_197 ( V_563 , sizeof( * V_684 . V_654 ) ) ;
if ( F_198 ( V_684 . V_654 ) )
return F_199 ( V_684 . V_654 ) ;
V_121 = F_285 ( V_2 , V_684 . V_654 ) ;
break;
}
case V_710 : {
V_684 . V_677 = F_293 ( sizeof( struct V_674 ) , V_686 ) ;
V_121 = - V_388 ;
if ( ! V_684 . V_677 )
break;
F_287 ( V_2 , V_684 . V_677 ) ;
V_121 = - V_101 ;
if ( F_232 ( V_563 , V_684 . V_677 ,
sizeof( struct V_674 ) ) )
break;
V_121 = 0 ;
break;
}
case V_711 : {
V_684 . V_677 = F_197 ( V_563 , sizeof( * V_684 . V_677 ) ) ;
if ( F_198 ( V_684 . V_677 ) )
return F_199 ( V_684 . V_677 ) ;
V_121 = F_288 ( V_2 , V_684 . V_677 ) ;
break;
}
case V_712 : {
T_1 V_266 ;
V_121 = - V_580 ;
V_266 = ( T_1 ) V_562 ;
if ( V_266 >= V_713 )
goto V_113;
if ( V_266 == 0 )
V_266 = V_272 ;
if ( ! F_137 ( V_2 , V_266 ) )
V_121 = 0 ;
goto V_113;
}
case V_714 : {
V_121 = V_2 -> V_5 . V_283 ;
goto V_113;
}
case V_715 : {
V_121 = F_289 ( V_2 ) ;
goto V_113;
}
case V_716 : {
struct V_679 V_680 ;
V_121 = - V_101 ;
if ( F_231 ( & V_680 , V_563 , sizeof( V_680 ) ) )
goto V_113;
V_121 = F_290 ( V_2 , & V_680 ) ;
break;
}
default:
V_121 = - V_580 ;
}
V_113:
F_201 ( V_684 . V_683 ) ;
return V_121 ;
}
int F_298 ( struct V_1 * V_2 , struct V_717 * V_718 )
{
return V_719 ;
}
static int F_299 ( struct V_139 * V_139 , unsigned long V_616 )
{
int V_108 ;
if ( V_616 > ( unsigned int ) ( - 3 * V_107 ) )
return - V_580 ;
V_108 = V_73 -> V_720 ( V_139 , V_616 ) ;
return V_108 ;
}
static int F_300 ( struct V_139 * V_139 ,
T_2 V_721 )
{
V_139 -> V_5 . V_722 = V_721 ;
return 0 ;
}
static int F_301 ( struct V_139 * V_139 ,
T_1 V_723 )
{
if ( V_723 < V_724 )
return - V_580 ;
F_302 ( & V_139 -> V_725 ) ;
F_303 ( V_139 , V_723 ) ;
V_139 -> V_5 . V_726 = V_723 ;
F_304 ( & V_139 -> V_725 ) ;
return 0 ;
}
static int F_305 ( struct V_139 * V_139 )
{
return V_139 -> V_5 . V_727 ;
}
static int F_306 ( struct V_139 * V_139 , struct V_728 * V_729 )
{
int V_121 ;
V_121 = 0 ;
switch ( V_729 -> V_730 ) {
case V_731 :
memcpy ( & V_729 -> V_729 . V_732 ,
& F_307 ( V_139 ) -> V_733 [ 0 ] ,
sizeof( struct V_734 ) ) ;
break;
case V_735 :
memcpy ( & V_729 -> V_729 . V_732 ,
& F_307 ( V_139 ) -> V_733 [ 1 ] ,
sizeof( struct V_734 ) ) ;
break;
case V_736 :
V_121 = F_308 ( V_139 , & V_729 -> V_729 . V_737 ) ;
break;
default:
V_121 = - V_580 ;
break;
}
return V_121 ;
}
static int F_309 ( struct V_139 * V_139 , struct V_728 * V_729 )
{
int V_121 ;
V_121 = 0 ;
switch ( V_729 -> V_730 ) {
case V_731 :
F_157 ( & F_307 ( V_139 ) -> V_738 ) ;
memcpy ( & F_307 ( V_139 ) -> V_733 [ 0 ] ,
& V_729 -> V_729 . V_732 ,
sizeof( struct V_734 ) ) ;
F_158 ( & F_307 ( V_139 ) -> V_738 ) ;
break;
case V_735 :
F_157 ( & F_307 ( V_139 ) -> V_738 ) ;
memcpy ( & F_307 ( V_139 ) -> V_733 [ 1 ] ,
& V_729 -> V_729 . V_732 ,
sizeof( struct V_734 ) ) ;
F_158 ( & F_307 ( V_139 ) -> V_738 ) ;
break;
case V_736 :
V_121 = F_310 ( V_139 , & V_729 -> V_729 . V_737 ) ;
break;
default:
V_121 = - V_580 ;
break;
}
F_311 ( F_307 ( V_139 ) ) ;
return V_121 ;
}
static int F_312 ( struct V_139 * V_139 , struct V_739 * V_740 )
{
struct V_741 * V_742 = & V_139 -> V_5 . V_743 -> V_744 ;
F_183 ( sizeof( * V_740 ) != sizeof( V_742 -> V_745 ) ) ;
F_302 ( & V_742 -> V_738 ) ;
memcpy ( V_740 , & V_742 -> V_745 , sizeof( * V_740 ) ) ;
F_304 ( & V_742 -> V_738 ) ;
return 0 ;
}
static int F_313 ( struct V_139 * V_139 , struct V_739 * V_740 )
{
int V_3 ;
struct V_746 * V_747 = V_139 -> V_5 . V_743 ;
F_302 ( & V_747 -> V_744 . V_738 ) ;
memcpy ( & V_747 -> V_744 . V_745 , V_740 , sizeof( * V_740 ) ) ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
F_314 ( V_747 , V_3 , V_740 -> V_745 [ V_3 ] . V_748 , 0 ) ;
F_304 ( & V_747 -> V_744 . V_738 ) ;
return 0 ;
}
static int F_315 ( struct V_139 * V_139 , struct V_749 * V_740 )
{
F_302 ( & V_139 -> V_5 . V_743 -> V_744 . V_738 ) ;
memcpy ( V_740 -> V_745 , & V_139 -> V_5 . V_743 -> V_744 . V_745 ,
sizeof( V_740 -> V_745 ) ) ;
V_740 -> V_308 = V_139 -> V_5 . V_743 -> V_744 . V_308 ;
F_304 ( & V_139 -> V_5 . V_743 -> V_744 . V_738 ) ;
memset ( & V_740 -> V_642 , 0 , sizeof( V_740 -> V_642 ) ) ;
return 0 ;
}
static int F_316 ( struct V_139 * V_139 , struct V_749 * V_740 )
{
int V_750 = 0 ;
int V_3 ;
T_1 V_751 , V_752 ;
struct V_746 * V_747 = V_139 -> V_5 . V_743 ;
F_302 ( & V_747 -> V_744 . V_738 ) ;
V_751 = V_747 -> V_744 . V_308 & V_753 ;
V_752 = V_740 -> V_308 & V_753 ;
if ( ! V_751 && V_752 )
V_750 = 1 ;
memcpy ( & V_747 -> V_744 . V_745 , & V_740 -> V_745 ,
sizeof( V_747 -> V_744 . V_745 ) ) ;
V_747 -> V_744 . V_308 = V_740 -> V_308 ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
F_314 ( V_747 , V_3 , V_747 -> V_744 . V_745 [ V_3 ] . V_748 ,
V_750 && V_3 == 0 ) ;
F_304 ( & V_747 -> V_744 . V_738 ) ;
return 0 ;
}
static int F_317 ( struct V_139 * V_139 ,
struct V_754 * V_755 )
{
struct V_746 * V_747 = V_139 -> V_5 . V_743 ;
if ( ! V_747 )
return - V_598 ;
F_302 ( & V_747 -> V_744 . V_738 ) ;
F_318 ( V_747 , V_755 -> V_756 ) ;
F_304 ( & V_747 -> V_744 . V_738 ) ;
return 0 ;
}
int F_319 ( struct V_139 * V_139 , struct V_757 * log )
{
bool V_758 = false ;
int V_121 ;
F_302 ( & V_139 -> V_725 ) ;
if ( V_73 -> V_759 )
V_73 -> V_759 ( V_139 ) ;
V_121 = F_320 ( V_139 , log , & V_758 ) ;
F_321 ( & V_139 -> V_725 ) ;
if ( V_758 )
F_322 ( V_139 ) ;
F_304 ( & V_139 -> V_725 ) ;
return V_121 ;
}
int F_323 ( struct V_139 * V_139 , struct V_760 * V_761 ,
bool V_762 )
{
if ( ! F_263 ( V_139 ) )
return - V_598 ;
V_761 -> V_461 = F_324 ( V_139 , V_763 ,
V_761 -> V_596 , V_761 -> V_764 ,
V_762 ) ;
return 0 ;
}
static int F_325 ( struct V_139 * V_139 ,
struct V_679 * V_680 )
{
int V_121 ;
if ( V_680 -> V_308 )
return - V_580 ;
switch ( V_680 -> V_680 ) {
case V_533 :
V_139 -> V_5 . V_765 = V_680 -> args [ 0 ] ;
V_121 = 0 ;
break;
case V_535 : {
F_302 ( & V_139 -> V_738 ) ;
V_121 = - V_580 ;
if ( V_680 -> args [ 0 ] > V_766 )
goto V_767;
V_121 = - V_600 ;
if ( F_263 ( V_139 ) )
goto V_767;
if ( V_139 -> V_768 )
goto V_767;
V_121 = F_326 ( V_139 ) ;
if ( V_121 )
goto V_767;
F_186 () ;
V_139 -> V_5 . V_769 = true ;
V_139 -> V_5 . V_770 = V_680 -> args [ 0 ] ;
V_121 = 0 ;
V_767:
F_304 ( & V_139 -> V_738 ) ;
break;
}
case V_557 :
V_121 = - V_580 ;
if ( V_680 -> args [ 0 ] & ~ V_558 )
break;
if ( V_680 -> args [ 0 ] & V_771 )
V_139 -> V_5 . V_772 = true ;
if ( V_680 -> args [ 0 ] & V_773 )
V_139 -> V_5 . V_774 = true ;
V_121 = 0 ;
break;
default:
V_121 = - V_580 ;
break;
}
return V_121 ;
}
long F_327 ( struct V_559 * V_560 ,
unsigned int V_561 , unsigned long V_562 )
{
struct V_139 * V_139 = V_560 -> V_681 ;
void T_15 * V_563 = ( void T_15 * ) V_562 ;
int V_121 = - V_775 ;
union {
struct V_739 V_740 ;
struct V_749 V_776 ;
struct V_777 V_778 ;
} V_684 ;
switch ( V_561 ) {
case V_779 :
V_121 = F_299 ( V_139 , V_562 ) ;
break;
case V_780 : {
T_2 V_721 ;
V_121 = - V_101 ;
if ( F_231 ( & V_721 , V_563 , sizeof V_721 ) )
goto V_113;
V_121 = F_300 ( V_139 , V_721 ) ;
break;
}
case V_781 :
V_121 = F_301 ( V_139 , V_562 ) ;
break;
case V_782 :
V_121 = F_305 ( V_139 ) ;
break;
case V_783 : {
struct V_784 * V_785 ;
F_302 ( & V_139 -> V_738 ) ;
V_121 = - V_600 ;
if ( V_139 -> V_5 . V_785 )
goto V_786;
V_121 = - V_580 ;
if ( V_139 -> V_768 )
goto V_786;
V_121 = - V_388 ;
V_785 = F_328 ( V_139 ) ;
if ( V_785 ) {
V_121 = F_329 ( V_139 ) ;
if ( V_121 ) {
F_302 ( & V_139 -> V_725 ) ;
F_330 ( V_785 ) ;
F_304 ( & V_139 -> V_725 ) ;
goto V_786;
}
} else
goto V_786;
V_121 = F_331 ( V_139 ) ;
if ( V_121 ) {
F_302 ( & V_139 -> V_725 ) ;
F_302 ( & V_139 -> V_787 ) ;
F_332 ( V_139 ) ;
F_330 ( V_785 ) ;
F_304 ( & V_139 -> V_787 ) ;
F_304 ( & V_139 -> V_725 ) ;
goto V_786;
}
F_186 () ;
V_139 -> V_5 . V_785 = V_785 ;
V_786:
F_304 ( & V_139 -> V_738 ) ;
break;
}
case V_788 :
V_684 . V_778 . V_308 = V_789 ;
goto V_790;
case V_791 :
V_121 = - V_101 ;
if ( F_231 ( & V_684 . V_778 , V_563 ,
sizeof( struct V_777 ) ) )
goto V_113;
V_790:
F_302 ( & V_139 -> V_738 ) ;
V_121 = - V_600 ;
if ( V_139 -> V_5 . V_743 )
goto V_792;
V_121 = - V_388 ;
V_139 -> V_5 . V_743 = F_333 ( V_139 , V_684 . V_778 . V_308 ) ;
if ( V_139 -> V_5 . V_743 )
V_121 = 0 ;
V_792:
F_304 ( & V_139 -> V_738 ) ;
break;
case V_793 : {
struct V_728 * V_729 ;
V_729 = F_197 ( V_563 , sizeof( * V_729 ) ) ;
if ( F_198 ( V_729 ) ) {
V_121 = F_199 ( V_729 ) ;
goto V_113;
}
V_121 = - V_598 ;
if ( ! F_263 ( V_139 ) || V_769 ( V_139 ) )
goto V_794;
V_121 = F_306 ( V_139 , V_729 ) ;
if ( V_121 )
goto V_794;
V_121 = - V_101 ;
if ( F_232 ( V_563 , V_729 , sizeof *V_729 ) )
goto V_794;
V_121 = 0 ;
V_794:
F_201 ( V_729 ) ;
break;
}
case V_795 : {
struct V_728 * V_729 ;
V_729 = F_197 ( V_563 , sizeof( * V_729 ) ) ;
if ( F_198 ( V_729 ) ) {
V_121 = F_199 ( V_729 ) ;
goto V_113;
}
V_121 = - V_598 ;
if ( ! F_263 ( V_139 ) || V_769 ( V_139 ) )
goto V_796;
V_121 = F_309 ( V_139 , V_729 ) ;
if ( V_121 )
goto V_796;
V_121 = 0 ;
V_796:
F_201 ( V_729 ) ;
break;
}
case V_797 : {
V_121 = - V_101 ;
if ( F_231 ( & V_684 . V_740 , V_563 , sizeof( struct V_739 ) ) )
goto V_113;
V_121 = - V_598 ;
if ( ! V_139 -> V_5 . V_743 )
goto V_113;
V_121 = F_312 ( V_139 , & V_684 . V_740 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_232 ( V_563 , & V_684 . V_740 , sizeof( struct V_739 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_798 : {
V_121 = - V_101 ;
if ( F_231 ( & V_684 . V_740 , V_563 , sizeof V_684 . V_740 ) )
goto V_113;
V_121 = - V_598 ;
if ( ! V_139 -> V_5 . V_743 )
goto V_113;
V_121 = F_313 ( V_139 , & V_684 . V_740 ) ;
break;
}
case V_799 : {
V_121 = - V_598 ;
if ( ! V_139 -> V_5 . V_743 )
goto V_113;
V_121 = F_315 ( V_139 , & V_684 . V_776 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_232 ( V_563 , & V_684 . V_776 , sizeof( V_684 . V_776 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_800 : {
V_121 = - V_101 ;
if ( F_231 ( & V_684 . V_776 , V_563 , sizeof( V_684 . V_776 ) ) )
goto V_113;
V_121 = - V_598 ;
if ( ! V_139 -> V_5 . V_743 )
goto V_113;
V_121 = F_316 ( V_139 , & V_684 . V_776 ) ;
break;
}
case V_801 : {
struct V_754 V_755 ;
V_121 = - V_101 ;
if ( F_231 ( & V_755 , V_563 , sizeof( V_755 ) ) )
goto V_113;
V_121 = F_317 ( V_139 , & V_755 ) ;
break;
}
case V_802 :
V_121 = 0 ;
F_302 ( & V_139 -> V_738 ) ;
if ( V_139 -> V_768 )
V_121 = - V_803 ;
else
V_139 -> V_5 . V_804 = V_562 ;
F_304 ( & V_139 -> V_738 ) ;
break;
case V_805 : {
V_121 = - V_101 ;
if ( F_231 ( & V_139 -> V_5 . F_196 , V_563 ,
sizeof( struct V_806 ) ) )
goto V_113;
V_121 = - V_580 ;
if ( V_139 -> V_5 . F_196 . V_308 )
goto V_113;
V_121 = 0 ;
break;
}
case V_807 : {
struct V_808 V_809 ;
T_2 V_810 ;
T_12 V_319 ;
V_121 = - V_101 ;
if ( F_231 ( & V_809 , V_563 , sizeof( V_809 ) ) )
goto V_113;
V_121 = - V_580 ;
if ( V_809 . V_308 )
goto V_113;
V_121 = 0 ;
F_334 () ;
V_810 = F_152 () ;
V_319 = V_809 . clock - V_810 ;
F_335 () ;
V_139 -> V_5 . V_247 = V_319 ;
F_175 ( V_139 ) ;
break;
}
case V_811 : {
struct V_808 V_809 ;
T_2 V_810 ;
F_334 () ;
V_810 = F_152 () ;
V_809 . clock = V_139 -> V_5 . V_247 + V_810 ;
F_335 () ;
V_809 . V_308 = 0 ;
memset ( & V_809 . V_621 , 0 , sizeof( V_809 . V_621 ) ) ;
V_121 = - V_101 ;
if ( F_232 ( V_563 , & V_809 , sizeof( V_809 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_716 : {
struct V_679 V_680 ;
V_121 = - V_101 ;
if ( F_231 ( & V_680 , V_563 , sizeof( V_680 ) ) )
goto V_113;
V_121 = F_325 ( V_139 , & V_680 ) ;
break;
}
default:
V_121 = F_336 ( V_139 , V_561 , V_562 ) ;
}
V_113:
return V_121 ;
}
static void F_337 ( void )
{
T_1 V_812 [ 2 ] ;
unsigned V_3 , V_813 ;
for ( V_3 = V_813 = 0 ; V_3 < F_52 ( V_571 ) ; V_3 ++ ) {
if ( F_338 ( V_571 [ V_3 ] , & V_812 [ 0 ] , & V_812 [ 1 ] ) < 0 )
continue;
switch ( V_571 [ V_3 ] ) {
case V_814 :
if ( ! V_73 -> V_815 () )
continue;
break;
case V_816 :
if ( ! V_73 -> V_817 () )
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
for ( V_3 = V_813 = 0 ; V_3 < F_52 ( V_572 ) ; V_3 ++ ) {
switch ( V_572 [ V_3 ] ) {
case V_424 :
if ( ! V_73 -> V_539 () )
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
static int F_339 ( struct V_1 * V_2 , T_6 V_616 , int V_95 ,
const void * V_265 )
{
int V_818 = 0 ;
int V_491 ;
do {
V_491 = F_340 ( V_95 , 8 ) ;
if ( ! ( F_88 ( V_2 ) &&
! F_341 ( V_2 , & V_2 -> V_5 . V_646 -> V_819 , V_616 , V_491 , V_265 ) )
&& F_342 ( V_2 , V_820 , V_616 , V_491 , V_265 ) )
break;
V_818 += V_491 ;
V_616 += V_491 ;
V_95 -= V_491 ;
V_265 += V_491 ;
} while ( V_95 );
return V_818 ;
}
static int F_343 ( struct V_1 * V_2 , T_6 V_616 , int V_95 , void * V_265 )
{
int V_818 = 0 ;
int V_491 ;
do {
V_491 = F_340 ( V_95 , 8 ) ;
if ( ! ( F_88 ( V_2 ) &&
! F_344 ( V_2 , & V_2 -> V_5 . V_646 -> V_819 ,
V_616 , V_491 , V_265 ) )
&& F_345 ( V_2 , V_820 , V_616 , V_491 , V_265 ) )
break;
F_346 ( V_821 , V_491 , V_616 , * ( T_2 * ) V_265 ) ;
V_818 += V_491 ;
V_616 += V_491 ;
V_95 -= V_491 ;
V_265 += V_491 ;
} while ( V_95 );
return V_818 ;
}
static void F_347 ( struct V_1 * V_2 ,
struct V_822 * V_823 , int V_824 )
{
V_73 -> V_825 ( V_2 , V_823 , V_824 ) ;
}
void F_348 ( struct V_1 * V_2 ,
struct V_822 * V_823 , int V_824 )
{
V_73 -> V_826 ( V_2 , V_823 , V_824 ) ;
}
T_6 F_349 ( struct V_1 * V_2 , T_6 V_390 , T_1 V_96 ,
struct V_75 * V_68 )
{
T_6 V_827 ;
F_13 ( ! F_39 ( V_2 ) ) ;
V_96 |= V_111 ;
V_827 = V_2 -> V_5 . V_84 . V_828 ( V_2 , V_390 , V_96 , V_68 ) ;
return V_827 ;
}
T_6 F_350 ( struct V_1 * V_2 , T_16 V_829 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
return V_2 -> V_5 . V_103 -> V_828 ( V_2 , V_829 , V_96 , V_68 ) ;
}
T_6 F_351 ( struct V_1 * V_2 , T_16 V_829 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
V_96 |= V_830 ;
return V_2 -> V_5 . V_103 -> V_828 ( V_2 , V_829 , V_96 , V_68 ) ;
}
T_6 F_352 ( struct V_1 * V_2 , T_16 V_829 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
V_96 |= V_112 ;
return V_2 -> V_5 . V_103 -> V_828 ( V_2 , V_829 , V_96 , V_68 ) ;
}
T_6 F_353 ( struct V_1 * V_2 , T_16 V_829 ,
struct V_75 * V_68 )
{
return V_2 -> V_5 . V_103 -> V_828 ( V_2 , V_829 , 0 , V_68 ) ;
}
static int F_354 ( T_16 V_616 , void * V_196 , unsigned int V_831 ,
struct V_1 * V_2 , T_1 V_96 ,
struct V_75 * V_68 )
{
void * V_38 = V_196 ;
int V_121 = V_832 ;
while ( V_831 ) {
T_6 V_390 = V_2 -> V_5 . V_103 -> V_828 ( V_2 , V_616 , V_96 ,
V_68 ) ;
unsigned V_94 = V_616 & ( V_107 - 1 ) ;
unsigned V_833 = F_340 ( V_831 , ( unsigned ) V_107 - V_94 ) ;
int V_108 ;
if ( V_390 == V_100 )
return V_834 ;
V_108 = F_49 ( V_2 , V_390 >> V_106 , V_38 ,
V_94 , V_833 ) ;
if ( V_108 < 0 ) {
V_121 = V_835 ;
goto V_113;
}
V_831 -= V_833 ;
V_38 += V_833 ;
V_616 += V_833 ;
}
V_113:
return V_121 ;
}
static int F_355 ( struct V_836 * V_837 ,
T_16 V_616 , void * V_196 , unsigned int V_831 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_356 ( V_837 ) ;
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
unsigned V_94 ;
int V_108 ;
T_6 V_390 = V_2 -> V_5 . V_103 -> V_828 ( V_2 , V_616 , V_96 | V_830 ,
V_68 ) ;
if ( F_167 ( V_390 == V_100 ) )
return V_834 ;
V_94 = V_616 & ( V_107 - 1 ) ;
if ( F_28 ( V_94 + V_831 > V_107 ) )
V_831 = ( unsigned ) V_107 - V_94 ;
V_108 = F_49 ( V_2 , V_390 >> V_106 , V_196 ,
V_94 , V_831 ) ;
if ( F_167 ( V_108 < 0 ) )
return V_835 ;
return V_832 ;
}
int F_357 ( struct V_836 * V_837 ,
T_16 V_616 , void * V_196 , unsigned int V_831 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_356 ( V_837 ) ;
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
return F_354 ( V_616 , V_196 , V_831 , V_2 , V_96 ,
V_68 ) ;
}
static int F_358 ( struct V_836 * V_837 ,
T_16 V_616 , void * V_196 , unsigned int V_831 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_356 ( V_837 ) ;
return F_354 ( V_616 , V_196 , V_831 , V_2 , 0 , V_68 ) ;
}
static int F_359 ( struct V_836 * V_837 ,
unsigned long V_616 , void * V_196 , unsigned int V_831 )
{
struct V_1 * V_2 = F_356 ( V_837 ) ;
int V_121 = F_360 ( V_2 , V_616 , V_196 , V_831 ) ;
return V_121 < 0 ? V_835 : V_832 ;
}
int F_361 ( struct V_836 * V_837 ,
T_16 V_616 , void * V_196 ,
unsigned int V_831 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_356 ( V_837 ) ;
void * V_38 = V_196 ;
int V_121 = V_832 ;
while ( V_831 ) {
T_6 V_390 = V_2 -> V_5 . V_103 -> V_828 ( V_2 , V_616 ,
V_112 ,
V_68 ) ;
unsigned V_94 = V_616 & ( V_107 - 1 ) ;
unsigned V_838 = F_340 ( V_831 , ( unsigned ) V_107 - V_94 ) ;
int V_108 ;
if ( V_390 == V_100 )
return V_834 ;
V_108 = F_200 ( V_2 , V_390 , V_38 , V_838 ) ;
if ( V_108 < 0 ) {
V_121 = V_835 ;
goto V_113;
}
V_831 -= V_838 ;
V_38 += V_838 ;
V_616 += V_838 ;
}
V_113:
return V_121 ;
}
static int F_362 ( struct V_1 * V_2 , unsigned long V_829 ,
T_6 * V_390 , struct V_75 * V_68 ,
bool V_839 )
{
T_1 V_96 = ( ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 )
| ( V_839 ? V_112 : 0 ) ;
if ( F_363 ( V_2 , V_829 )
&& ! F_364 ( V_2 , V_2 -> V_5 . V_103 ,
V_2 -> V_5 . V_96 , 0 , V_96 ) ) {
* V_390 = V_2 -> V_5 . V_840 << V_106 |
( V_829 & ( V_107 - 1 ) ) ;
F_365 ( V_829 , * V_390 , V_839 , false ) ;
return 1 ;
}
* V_390 = V_2 -> V_5 . V_103 -> V_828 ( V_2 , V_829 , V_96 , V_68 ) ;
if ( * V_390 == V_100 )
return - 1 ;
if ( ( * V_390 & V_384 ) == V_841 )
return 1 ;
if ( F_366 ( V_2 , * V_390 ) ) {
F_365 ( V_829 , * V_390 , V_839 , true ) ;
return 1 ;
}
return 0 ;
}
int F_367 ( struct V_1 * V_2 , T_6 V_390 ,
const void * V_196 , int V_831 )
{
int V_108 ;
V_108 = F_200 ( V_2 , V_390 , V_196 , V_831 ) ;
if ( V_108 < 0 )
return 0 ;
F_368 ( V_2 , V_390 , V_196 , V_831 ) ;
return 1 ;
}
static int F_369 ( struct V_1 * V_2 , void * V_196 , int V_831 )
{
if ( V_2 -> V_842 ) {
F_346 ( V_821 , V_831 ,
V_2 -> V_843 [ 0 ] . V_390 , * ( T_2 * ) V_196 ) ;
V_2 -> V_842 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_370 ( struct V_1 * V_2 , T_6 V_390 ,
void * V_196 , int V_831 )
{
return ! F_360 ( V_2 , V_390 , V_196 , V_831 ) ;
}
static int F_371 ( struct V_1 * V_2 , T_6 V_390 ,
void * V_196 , int V_831 )
{
return F_367 ( V_2 , V_390 , V_196 , V_831 ) ;
}
static int F_372 ( struct V_1 * V_2 , T_6 V_390 , int V_831 , void * V_196 )
{
F_346 ( V_844 , V_831 , V_390 , * ( T_2 * ) V_196 ) ;
return F_339 ( V_2 , V_390 , V_831 , V_196 ) ;
}
static int F_373 ( struct V_1 * V_2 , T_6 V_390 ,
void * V_196 , int V_831 )
{
F_346 ( V_845 , V_831 , V_390 , 0 ) ;
return V_835 ;
}
static int F_374 ( struct V_1 * V_2 , T_6 V_390 ,
void * V_196 , int V_831 )
{
struct V_846 * V_847 = & V_2 -> V_843 [ 0 ] ;
memcpy ( V_2 -> V_848 -> V_849 . V_38 , V_847 -> V_38 , F_340 ( 8u , V_847 -> V_95 ) ) ;
return V_832 ;
}
static int F_375 ( unsigned long V_616 , void * V_196 ,
unsigned int V_831 ,
struct V_75 * V_68 ,
struct V_1 * V_2 ,
const struct V_850 * V_851 )
{
T_6 V_390 ;
int V_818 , V_108 ;
bool V_839 = V_851 -> V_839 ;
struct V_846 * V_847 ;
V_108 = F_362 ( V_2 , V_616 , & V_390 , V_68 , V_839 ) ;
if ( V_108 < 0 )
return V_834 ;
if ( V_108 )
goto V_849;
if ( V_851 -> V_852 ( V_2 , V_390 , V_196 , V_831 ) )
return V_832 ;
V_849:
V_818 = V_851 -> V_853 ( V_2 , V_390 , V_831 , V_196 ) ;
if ( V_818 == V_831 )
return V_832 ;
V_390 += V_818 ;
V_831 -= V_818 ;
V_196 += V_818 ;
F_28 ( V_2 -> V_854 >= V_855 ) ;
V_847 = & V_2 -> V_843 [ V_2 -> V_854 ++ ] ;
V_847 -> V_390 = V_390 ;
V_847 -> V_38 = V_196 ;
V_847 -> V_95 = V_831 ;
return V_832 ;
}
static int F_376 ( struct V_836 * V_837 ,
unsigned long V_616 ,
void * V_196 , unsigned int V_831 ,
struct V_75 * V_68 ,
const struct V_850 * V_851 )
{
struct V_1 * V_2 = F_356 ( V_837 ) ;
T_6 V_390 ;
int V_856 ;
if ( V_851 -> V_857 &&
V_851 -> V_857 ( V_2 , V_196 , V_831 ) )
return V_832 ;
V_2 -> V_854 = 0 ;
if ( ( ( V_616 + V_831 - 1 ) ^ V_616 ) & V_384 ) {
int V_858 ;
V_858 = - V_616 & ~ V_384 ;
V_856 = F_375 ( V_616 , V_196 , V_858 , V_68 ,
V_2 , V_851 ) ;
if ( V_856 != V_832 )
return V_856 ;
V_616 += V_858 ;
if ( V_837 -> V_331 != V_859 )
V_616 = ( T_1 ) V_616 ;
V_196 += V_858 ;
V_831 -= V_858 ;
}
V_856 = F_375 ( V_616 , V_196 , V_831 , V_68 ,
V_2 , V_851 ) ;
if ( V_856 != V_832 )
return V_856 ;
if ( ! V_2 -> V_854 )
return V_856 ;
V_390 = V_2 -> V_843 [ 0 ] . V_390 ;
V_2 -> V_860 = 1 ;
V_2 -> V_861 = 0 ;
V_2 -> V_848 -> V_849 . V_95 = F_340 ( 8u , V_2 -> V_843 [ 0 ] . V_95 ) ;
V_2 -> V_848 -> V_849 . V_862 = V_2 -> V_863 = V_851 -> V_839 ;
V_2 -> V_848 -> V_864 = V_865 ;
V_2 -> V_848 -> V_849 . V_866 = V_390 ;
return V_851 -> V_867 ( V_2 , V_390 , V_196 , V_831 ) ;
}
static int F_377 ( struct V_836 * V_837 ,
unsigned long V_616 ,
void * V_196 ,
unsigned int V_831 ,
struct V_75 * V_68 )
{
return F_376 ( V_837 , V_616 , V_196 , V_831 ,
V_68 , & V_868 ) ;
}
static int F_378 ( struct V_836 * V_837 ,
unsigned long V_616 ,
const void * V_196 ,
unsigned int V_831 ,
struct V_75 * V_68 )
{
return F_376 ( V_837 , V_616 , ( void * ) V_196 , V_831 ,
V_68 , & V_869 ) ;
}
static int F_379 ( struct V_836 * V_837 ,
unsigned long V_616 ,
const void * V_870 ,
const void * V_871 ,
unsigned int V_831 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_356 ( V_837 ) ;
T_6 V_390 ;
struct V_386 * V_386 ;
char * V_872 ;
bool V_873 ;
if ( V_831 > 8 || ( V_831 & ( V_831 - 1 ) ) )
goto V_874;
V_390 = F_352 ( V_2 , V_616 , NULL ) ;
if ( V_390 == V_100 ||
( V_390 & V_384 ) == V_841 )
goto V_874;
if ( ( ( V_390 + V_831 - 1 ) & V_384 ) != ( V_390 & V_384 ) )
goto V_874;
V_386 = F_380 ( V_2 , V_390 >> V_106 ) ;
if ( F_381 ( V_386 ) )
goto V_874;
V_872 = F_382 ( V_386 ) ;
V_872 += F_383 ( V_390 ) ;
switch ( V_831 ) {
case 1 :
V_873 = F_384 ( T_14 , V_872 , V_870 , V_871 ) ;
break;
case 2 :
V_873 = F_384 ( V_875 , V_872 , V_870 , V_871 ) ;
break;
case 4 :
V_873 = F_384 ( T_1 , V_872 , V_870 , V_871 ) ;
break;
case 8 :
V_873 = F_385 ( V_872 , V_870 , V_871 ) ;
break;
default:
F_25 () ;
}
F_386 ( V_872 ) ;
F_387 ( V_386 ) ;
if ( ! V_873 )
return V_876 ;
F_388 ( V_2 , V_390 >> V_106 ) ;
F_368 ( V_2 , V_390 , V_871 , V_831 ) ;
return V_832 ;
V_874:
F_389 ( V_877 L_20 ) ;
return F_378 ( V_837 , V_616 , V_871 , V_831 , V_68 ) ;
}
static int F_390 ( struct V_1 * V_2 , void * V_878 )
{
int V_121 ;
if ( V_2 -> V_5 . V_879 . V_880 )
V_121 = F_345 ( V_2 , V_881 , V_2 -> V_5 . V_879 . V_882 ,
V_2 -> V_5 . V_879 . V_492 , V_878 ) ;
else
V_121 = F_342 ( V_2 , V_881 ,
V_2 -> V_5 . V_879 . V_882 , V_2 -> V_5 . V_879 . V_492 ,
V_878 ) ;
return V_121 ;
}
static int F_391 ( struct V_1 * V_2 , int V_492 ,
unsigned short V_882 , void * V_196 ,
unsigned int V_748 , bool V_880 )
{
V_2 -> V_5 . V_879 . V_882 = V_882 ;
V_2 -> V_5 . V_879 . V_880 = V_880 ;
V_2 -> V_5 . V_879 . V_748 = V_748 ;
V_2 -> V_5 . V_879 . V_492 = V_492 ;
if ( ! F_390 ( V_2 , V_2 -> V_5 . V_883 ) ) {
V_2 -> V_5 . V_879 . V_748 = 0 ;
return 1 ;
}
V_2 -> V_848 -> V_864 = V_884 ;
V_2 -> V_848 -> V_885 . V_886 = V_880 ? V_887 : V_888 ;
V_2 -> V_848 -> V_885 . V_492 = V_492 ;
V_2 -> V_848 -> V_885 . V_889 = V_890 * V_107 ;
V_2 -> V_848 -> V_885 . V_748 = V_748 ;
V_2 -> V_848 -> V_885 . V_882 = V_882 ;
return 0 ;
}
static int F_392 ( struct V_836 * V_837 ,
int V_492 , unsigned short V_882 , void * V_196 ,
unsigned int V_748 )
{
struct V_1 * V_2 = F_356 ( V_837 ) ;
int V_108 ;
if ( V_2 -> V_5 . V_879 . V_748 )
goto V_891;
V_108 = F_391 ( V_2 , V_492 , V_882 , V_196 , V_748 , true ) ;
if ( V_108 ) {
V_891:
memcpy ( V_196 , V_2 -> V_5 . V_883 , V_492 * V_748 ) ;
F_393 ( V_892 , V_882 , V_492 , V_748 , V_2 -> V_5 . V_883 ) ;
V_2 -> V_5 . V_879 . V_748 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_394 ( struct V_836 * V_837 ,
int V_492 , unsigned short V_882 ,
const void * V_196 , unsigned int V_748 )
{
struct V_1 * V_2 = F_356 ( V_837 ) ;
memcpy ( V_2 -> V_5 . V_883 , V_196 , V_492 * V_748 ) ;
F_393 ( V_893 , V_882 , V_492 , V_748 , V_2 -> V_5 . V_883 ) ;
return F_391 ( V_2 , V_492 , V_882 , ( void * ) V_196 , V_748 , false ) ;
}
static unsigned long F_395 ( struct V_1 * V_2 , int V_824 )
{
return V_73 -> F_395 ( V_2 , V_824 ) ;
}
static void F_396 ( struct V_836 * V_837 , V_176 V_80 )
{
F_397 ( F_356 ( V_837 ) , V_80 ) ;
}
int F_398 ( struct V_1 * V_2 )
{
if ( ! F_241 ( V_2 ) )
return V_832 ;
if ( V_73 -> V_583 () ) {
int V_23 = F_399 () ;
F_244 ( V_23 , V_2 -> V_5 . V_584 ) ;
F_400 ( V_2 -> V_5 . V_584 ,
F_239 , NULL , 1 ) ;
F_401 () ;
F_402 ( V_2 -> V_5 . V_584 ) ;
} else
F_240 () ;
return V_832 ;
}
int F_403 ( struct V_1 * V_2 )
{
V_73 -> V_74 ( V_2 ) ;
return F_398 ( V_2 ) ;
}
static void F_404 ( struct V_836 * V_837 )
{
F_398 ( F_356 ( V_837 ) ) ;
}
static int F_405 ( struct V_836 * V_837 , int V_89 ,
unsigned long * V_652 )
{
return F_99 ( F_356 ( V_837 ) , V_89 , V_652 ) ;
}
static int F_406 ( struct V_836 * V_837 , int V_89 ,
unsigned long V_22 )
{
return F_97 ( F_356 ( V_837 ) , V_89 , V_22 ) ;
}
static T_2 F_407 ( T_2 V_894 , T_1 V_895 )
{
return ( V_894 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_895 ;
}
static unsigned long F_408 ( struct V_836 * V_837 , int V_896 )
{
struct V_1 * V_2 = F_356 ( V_837 ) ;
unsigned long V_22 ;
switch ( V_896 ) {
case 0 :
V_22 = F_60 ( V_2 ) ;
break;
case 2 :
V_22 = V_2 -> V_5 . V_79 ;
break;
case 3 :
V_22 = F_58 ( V_2 ) ;
break;
case 4 :
V_22 = F_77 ( V_2 ) ;
break;
case 8 :
V_22 = F_90 ( V_2 ) ;
break;
default:
F_409 ( L_21 , V_262 , V_896 ) ;
return 0 ;
}
return V_22 ;
}
static int F_410 ( struct V_836 * V_837 , int V_896 , V_176 V_196 )
{
struct V_1 * V_2 = F_356 ( V_837 ) ;
int V_897 = 0 ;
switch ( V_896 ) {
case 0 :
V_897 = F_59 ( V_2 , F_407 ( F_60 ( V_2 ) , V_196 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_79 = V_196 ;
break;
case 3 :
V_897 = F_84 ( V_2 , V_196 ) ;
break;
case 4 :
V_897 = F_76 ( V_2 , F_407 ( F_77 ( V_2 ) , V_196 ) ) ;
break;
case 8 :
V_897 = F_87 ( V_2 , V_196 ) ;
break;
default:
F_409 ( L_21 , V_262 , V_896 ) ;
V_897 = - 1 ;
}
return V_897 ;
}
static int F_411 ( struct V_836 * V_837 )
{
return V_73 -> V_88 ( F_356 ( V_837 ) ) ;
}
static void F_412 ( struct V_836 * V_837 , struct V_898 * V_899 )
{
V_73 -> V_900 ( F_356 ( V_837 ) , V_899 ) ;
}
static void F_413 ( struct V_836 * V_837 , struct V_898 * V_899 )
{
V_73 -> V_901 ( F_356 ( V_837 ) , V_899 ) ;
}
static void F_414 ( struct V_836 * V_837 , struct V_898 * V_899 )
{
V_73 -> V_902 ( F_356 ( V_837 ) , V_899 ) ;
}
static void F_415 ( struct V_836 * V_837 , struct V_898 * V_899 )
{
V_73 -> V_903 ( F_356 ( V_837 ) , V_899 ) ;
}
static unsigned long F_416 (
struct V_836 * V_837 , int V_824 )
{
return F_395 ( F_356 ( V_837 ) , V_824 ) ;
}
static bool F_417 ( struct V_836 * V_837 , V_875 * V_904 ,
struct V_905 * V_906 , T_1 * V_907 ,
int V_824 )
{
struct V_822 V_823 ;
F_348 ( F_356 ( V_837 ) , & V_823 , V_824 ) ;
* V_904 = V_823 . V_904 ;
if ( V_823 . V_908 ) {
memset ( V_906 , 0 , sizeof( * V_906 ) ) ;
return false ;
}
if ( V_823 . V_909 )
V_823 . V_910 >>= 12 ;
F_418 ( V_906 , V_823 . V_910 ) ;
F_419 ( V_906 , ( unsigned long ) V_823 . V_230 ) ;
#ifdef F_61
if ( V_907 )
* V_907 = V_823 . V_230 >> 32 ;
#endif
V_906 -> type = V_823 . type ;
V_906 -> V_592 = V_823 . V_592 ;
V_906 -> V_911 = V_823 . V_911 ;
V_906 -> V_912 = V_823 . V_913 ;
V_906 -> V_914 = V_823 . V_914 ;
V_906 -> V_915 = V_823 . V_915 ;
V_906 -> V_916 = V_823 . V_183 ;
V_906 -> V_909 = V_823 . V_909 ;
return true ;
}
static void F_420 ( struct V_836 * V_837 , V_875 V_904 ,
struct V_905 * V_906 , T_1 V_907 ,
int V_824 )
{
struct V_1 * V_2 = F_356 ( V_837 ) ;
struct V_822 V_823 ;
V_823 . V_904 = V_904 ;
V_823 . V_230 = F_421 ( V_906 ) ;
#ifdef F_61
V_823 . V_230 |= ( ( T_2 ) V_907 ) << 32 ;
#endif
V_823 . V_910 = F_422 ( V_906 ) ;
if ( V_906 -> V_909 )
V_823 . V_910 = ( V_823 . V_910 << 12 ) | 0xfff ;
V_823 . type = V_906 -> type ;
V_823 . V_911 = V_906 -> V_911 ;
V_823 . V_183 = V_906 -> V_916 ;
V_823 . V_592 = V_906 -> V_592 ;
V_823 . V_915 = V_906 -> V_915 ;
V_823 . V_909 = V_906 -> V_909 ;
V_823 . V_914 = V_906 -> V_914 ;
V_823 . V_913 = V_906 -> V_912 ;
V_823 . V_908 = ! V_823 . V_913 ;
V_823 . V_917 = 0 ;
F_347 ( V_2 , & V_823 , V_824 ) ;
return;
}
static int F_423 ( struct V_836 * V_837 ,
T_1 V_918 , T_2 * V_464 )
{
struct V_32 V_21 ;
int V_121 ;
V_21 . V_147 = V_918 ;
V_21 . V_40 = false ;
V_121 = F_113 ( F_356 ( V_837 ) , & V_21 ) ;
if ( V_121 )
return V_121 ;
* V_464 = V_21 . V_38 ;
return 0 ;
}
static int F_424 ( struct V_836 * V_837 ,
T_1 V_918 , T_2 V_38 )
{
struct V_32 V_21 ;
V_21 . V_38 = V_38 ;
V_21 . V_147 = V_918 ;
V_21 . V_40 = false ;
return F_109 ( F_356 ( V_837 ) , & V_21 ) ;
}
static T_2 F_425 ( struct V_836 * V_837 )
{
struct V_1 * V_2 = F_356 ( V_837 ) ;
return V_2 -> V_5 . V_425 ;
}
static void F_426 ( struct V_836 * V_837 , T_2 V_425 )
{
struct V_1 * V_2 = F_356 ( V_837 ) ;
V_2 -> V_5 . V_425 = V_425 ;
}
static int F_427 ( struct V_836 * V_837 ,
T_1 V_919 )
{
return F_428 ( F_356 ( V_837 ) , V_919 ) ;
}
static int F_429 ( struct V_836 * V_837 ,
T_1 V_919 , T_2 * V_464 )
{
return F_102 ( F_356 ( V_837 ) , V_919 , V_464 ) ;
}
static void F_430 ( struct V_836 * V_837 )
{
F_356 ( V_837 ) -> V_5 . V_920 = 1 ;
}
static void F_431 ( struct V_836 * V_837 )
{
F_432 () ;
F_433 ( F_356 ( V_837 ) ) ;
F_434 () ;
}
static void F_435 ( struct V_836 * V_837 )
{
F_436 () ;
}
static int F_437 ( struct V_836 * V_837 ,
struct V_921 * V_922 ,
enum V_923 V_924 )
{
return V_73 -> V_925 ( F_356 ( V_837 ) , V_922 , V_924 ) ;
}
static void F_438 ( struct V_836 * V_837 ,
T_1 * V_926 , T_1 * V_927 , T_1 * V_201 , T_1 * V_209 )
{
V_692 ( F_356 ( V_837 ) , V_926 , V_927 , V_201 , V_209 ) ;
}
static V_176 F_439 ( struct V_836 * V_837 , unsigned V_928 )
{
return F_101 ( F_356 ( V_837 ) , V_928 ) ;
}
static void F_440 ( struct V_836 * V_837 , unsigned V_928 , V_176 V_196 )
{
F_103 ( F_356 ( V_837 ) , V_928 , V_196 ) ;
}
static void F_441 ( struct V_836 * V_837 , bool V_629 )
{
V_73 -> V_645 ( F_356 ( V_837 ) , V_629 ) ;
}
static void F_442 ( struct V_1 * V_2 , T_1 V_28 )
{
T_1 V_929 = V_73 -> V_625 ( V_2 ) ;
if ( V_929 & V_28 )
V_28 = 0 ;
if ( F_167 ( V_929 || V_28 ) ) {
V_73 -> V_644 ( V_2 , V_28 ) ;
if ( ! V_28 )
F_30 ( V_67 , V_2 ) ;
}
}
static bool F_443 ( struct V_1 * V_2 )
{
struct V_836 * V_837 = & V_2 -> V_5 . V_930 ;
if ( V_837 -> V_68 . V_41 == V_42 )
return F_38 ( V_2 , & V_837 -> V_68 ) ;
if ( V_837 -> V_68 . V_931 )
F_37 ( V_2 , V_837 -> V_68 . V_41 ,
V_837 -> V_68 . V_62 ) ;
else
F_32 ( V_2 , V_837 -> V_68 . V_41 ) ;
return false ;
}
static void F_444 ( struct V_1 * V_2 )
{
struct V_836 * V_837 = & V_2 -> V_5 . V_930 ;
int V_134 , V_135 ;
V_73 -> V_136 ( V_2 , & V_134 , & V_135 ) ;
V_837 -> V_932 = F_445 ( V_2 ) ;
V_837 -> V_933 = F_446 ( V_2 ) ;
V_837 -> V_331 = ( ! F_31 ( V_2 ) ) ? V_934 :
( V_837 -> V_932 & V_935 ) ? V_936 :
( V_135 && F_55 ( V_2 ) ) ? V_859 :
V_134 ? V_937 :
V_938 ;
F_183 ( V_939 != V_940 ) ;
F_183 ( V_647 != V_941 ) ;
F_183 ( V_637 != V_942 ) ;
V_837 -> V_943 = V_2 -> V_5 . V_636 ;
F_447 ( V_837 ) ;
V_2 -> V_5 . V_944 = false ;
}
int F_448 ( struct V_1 * V_2 , int V_596 , int V_945 )
{
struct V_836 * V_837 = & V_2 -> V_5 . V_930 ;
int V_108 ;
F_444 ( V_2 ) ;
V_837 -> V_946 = 2 ;
V_837 -> V_947 = 2 ;
V_837 -> V_948 = V_837 -> V_933 + V_945 ;
V_108 = F_449 ( V_837 , V_596 ) ;
if ( V_108 != V_832 )
return V_949 ;
V_837 -> V_933 = V_837 -> V_948 ;
F_450 ( V_2 , V_837 -> V_933 ) ;
F_451 ( V_2 , V_837 -> V_932 ) ;
if ( V_596 == V_51 )
V_2 -> V_5 . V_628 = 0 ;
else
V_2 -> V_5 . V_622 . V_69 = false ;
return V_950 ;
}
static int F_452 ( struct V_1 * V_2 )
{
int V_121 = V_950 ;
++ V_2 -> V_77 . V_951 ;
F_453 ( V_2 ) ;
if ( ! F_454 ( V_2 ) && V_73 -> V_88 ( V_2 ) == 0 ) {
V_2 -> V_848 -> V_864 = V_952 ;
V_2 -> V_848 -> V_953 . V_954 = V_955 ;
V_2 -> V_848 -> V_953 . V_956 = 0 ;
V_121 = V_949 ;
}
F_32 ( V_2 , V_91 ) ;
return V_121 ;
}
static bool F_455 ( struct V_1 * V_2 , T_16 V_79 ,
bool V_957 ,
int V_958 )
{
T_6 V_390 = V_79 ;
T_17 V_959 ;
if ( V_958 & V_960 )
return false ;
if ( ! V_2 -> V_5 . V_84 . V_961 ) {
V_390 = F_352 ( V_2 , V_79 , NULL ) ;
if ( V_390 == V_100 )
return true ;
}
V_959 = F_456 ( V_2 -> V_139 , F_48 ( V_390 ) ) ;
if ( F_457 ( V_959 ) )
return false ;
F_458 ( V_959 ) ;
if ( V_2 -> V_5 . V_84 . V_961 ) {
unsigned int V_962 ;
F_157 ( & V_2 -> V_139 -> V_963 ) ;
V_962 = V_2 -> V_139 -> V_5 . V_962 ;
F_158 ( & V_2 -> V_139 -> V_963 ) ;
if ( V_962 )
F_459 ( V_2 -> V_139 , F_48 ( V_390 ) ) ;
return true ;
}
F_459 ( V_2 -> V_139 , F_48 ( V_390 ) ) ;
return ! V_957 ;
}
static bool F_460 ( struct V_836 * V_837 ,
unsigned long V_79 , int V_958 )
{
struct V_1 * V_2 = F_356 ( V_837 ) ;
unsigned long V_964 , V_965 , V_390 = V_79 ;
V_964 = V_2 -> V_5 . V_964 ;
V_965 = V_2 -> V_5 . V_965 ;
V_2 -> V_5 . V_964 = V_2 -> V_5 . V_965 = 0 ;
if ( ! ( V_958 & V_966 ) )
return false ;
if ( F_461 ( V_837 ) )
return false ;
if ( V_837 -> V_933 == V_964 && V_965 == V_79 )
return false ;
V_2 -> V_5 . V_964 = V_837 -> V_933 ;
V_2 -> V_5 . V_965 = V_79 ;
if ( ! V_2 -> V_5 . V_84 . V_961 )
V_390 = F_352 ( V_2 , V_79 , NULL ) ;
F_459 ( V_2 -> V_139 , F_48 ( V_390 ) ) ;
return true ;
}
static void F_462 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_636 & V_647 ) ) {
F_463 ( V_2 -> V_298 , V_2 -> V_5 . V_425 , false ) ;
F_30 ( V_67 , V_2 ) ;
}
F_64 ( V_2 ) ;
}
static void F_464 ( struct V_1 * V_2 , unsigned V_943 )
{
unsigned V_120 = V_2 -> V_5 . V_636 ^ V_943 ;
V_2 -> V_5 . V_636 = V_943 ;
if ( V_120 & V_647 )
F_462 ( V_2 ) ;
}
static int F_465 ( unsigned long V_616 , T_1 type , T_1 V_188 ,
unsigned long * V_183 )
{
T_1 V_187 = 0 ;
int V_3 ;
T_1 V_967 , V_968 ;
V_967 = V_188 ;
V_968 = V_188 >> 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ , V_967 >>= 2 , V_968 >>= 4 )
if ( ( V_967 & 3 ) && ( V_968 & 15 ) == type && V_183 [ V_3 ] == V_616 )
V_187 |= ( 1 << V_3 ) ;
return V_187 ;
}
static void F_466 ( struct V_1 * V_2 , unsigned long V_969 , int * V_121 )
{
struct V_970 * V_970 = V_2 -> V_848 ;
if ( F_167 ( V_969 & V_971 ) ) {
if ( V_2 -> V_179 & V_972 ) {
V_970 -> V_973 . V_5 . V_187 = V_974 | V_194 |
V_195 ;
V_970 -> V_973 . V_5 . V_975 = V_2 -> V_5 . V_976 ;
V_970 -> V_973 . V_5 . V_68 = V_53 ;
V_970 -> V_864 = V_977 ;
* V_121 = V_978 ;
} else {
V_2 -> V_5 . V_930 . V_932 &= ~ V_971 ;
V_2 -> V_5 . V_187 &= ~ 15 ;
V_2 -> V_5 . V_187 |= V_974 | V_195 ;
F_32 ( V_2 , V_53 ) ;
}
}
}
static bool F_467 ( struct V_1 * V_2 , int * V_121 )
{
if ( F_167 ( V_2 -> V_179 & V_180 ) &&
( V_2 -> V_5 . V_189 & V_192 ) ) {
struct V_970 * V_970 = V_2 -> V_848 ;
unsigned long V_933 = F_468 ( V_2 ) ;
T_1 V_187 = F_465 ( V_933 , 0 ,
V_2 -> V_5 . V_189 ,
V_2 -> V_5 . V_182 ) ;
if ( V_187 != 0 ) {
V_970 -> V_973 . V_5 . V_187 = V_187 | V_194 | V_195 ;
V_970 -> V_973 . V_5 . V_975 = V_933 ;
V_970 -> V_973 . V_5 . V_68 = V_53 ;
V_970 -> V_864 = V_977 ;
* V_121 = V_978 ;
return true ;
}
}
if ( F_167 ( V_2 -> V_5 . V_188 & V_192 ) &&
! ( F_445 ( V_2 ) & V_979 ) ) {
unsigned long V_933 = F_468 ( V_2 ) ;
T_1 V_187 = F_465 ( V_933 , 0 ,
V_2 -> V_5 . V_188 ,
V_2 -> V_5 . V_183 ) ;
if ( V_187 != 0 ) {
V_2 -> V_5 . V_187 &= ~ 15 ;
V_2 -> V_5 . V_187 |= V_187 | V_195 ;
F_32 ( V_2 , V_53 ) ;
* V_121 = V_950 ;
return true ;
}
}
return false ;
}
int F_469 ( struct V_1 * V_2 ,
unsigned long V_79 ,
int V_958 ,
void * V_980 ,
int V_981 )
{
int V_121 ;
struct V_836 * V_837 = & V_2 -> V_5 . V_930 ;
bool V_490 = true ;
bool V_982 = V_2 -> V_5 . V_957 ;
V_2 -> V_5 . V_957 = false ;
F_470 ( V_2 ) ;
if ( ! ( V_958 & V_983 ) ) {
F_444 ( V_2 ) ;
if ( F_467 ( V_2 , & V_121 ) )
return V_121 ;
V_837 -> V_984 = 0 ;
V_837 -> V_985 = false ;
V_837 -> V_68 . V_41 = - 1 ;
V_837 -> V_986 = false ;
V_837 -> V_987 = V_958 & V_988 ;
V_121 = F_471 ( V_837 , V_980 , V_981 ) ;
F_472 ( V_2 ) ;
++ V_2 -> V_77 . V_989 ;
if ( V_121 != V_990 ) {
if ( V_958 & V_988 )
return V_949 ;
if ( F_455 ( V_2 , V_79 , V_982 ,
V_958 ) )
return V_950 ;
if ( V_958 & V_991 )
return V_949 ;
return F_452 ( V_2 ) ;
}
}
if ( V_958 & V_991 ) {
F_450 ( V_2 , V_837 -> V_948 ) ;
if ( V_837 -> V_932 & V_979 )
F_451 ( V_2 , V_837 -> V_932 & ~ V_979 ) ;
return V_950 ;
}
if ( F_460 ( V_837 , V_79 , V_958 ) )
return V_950 ;
if ( V_2 -> V_5 . V_944 ) {
V_2 -> V_5 . V_944 = false ;
F_473 ( V_837 ) ;
}
V_992:
V_121 = F_474 ( V_837 ) ;
if ( V_121 == V_993 )
return V_950 ;
if ( V_121 == V_994 ) {
if ( F_455 ( V_2 , V_79 , V_982 ,
V_958 ) )
return V_950 ;
return F_452 ( V_2 ) ;
}
if ( V_837 -> V_985 ) {
V_121 = V_950 ;
if ( F_443 ( V_2 ) )
return V_121 ;
} else if ( V_2 -> V_5 . V_879 . V_748 ) {
if ( ! V_2 -> V_5 . V_879 . V_880 ) {
V_2 -> V_5 . V_879 . V_748 = 0 ;
} else {
V_490 = false ;
V_2 -> V_5 . V_995 = V_996 ;
}
V_121 = V_978 ;
} else if ( V_2 -> V_860 ) {
if ( ! V_2 -> V_863 )
V_490 = false ;
V_121 = V_978 ;
V_2 -> V_5 . V_995 = V_997 ;
} else if ( V_121 == V_998 )
goto V_992;
else
V_121 = V_950 ;
if ( V_490 ) {
unsigned long V_969 = V_73 -> V_999 ( V_2 ) ;
F_442 ( V_2 , V_837 -> V_984 ) ;
V_2 -> V_5 . V_1000 = false ;
if ( V_2 -> V_5 . V_636 != V_837 -> V_943 )
F_464 ( V_2 , V_837 -> V_943 ) ;
F_450 ( V_2 , V_837 -> V_933 ) ;
if ( V_121 == V_950 )
F_466 ( V_2 , V_969 , & V_121 ) ;
if ( ! V_837 -> V_985 ||
F_27 ( V_837 -> V_68 . V_41 ) == V_56 )
F_475 ( V_2 , V_837 -> V_932 ) ;
if ( F_167 ( ( V_837 -> V_932 & ~ V_969 ) & V_1001 ) )
F_30 ( V_67 , V_2 ) ;
} else
V_2 -> V_5 . V_1000 = true ;
return V_121 ;
}
int F_476 ( struct V_1 * V_2 , int V_492 , unsigned short V_882 )
{
unsigned long V_196 = F_101 ( V_2 , V_203 ) ;
int V_108 = F_394 ( & V_2 -> V_5 . V_930 ,
V_492 , V_882 , & V_196 , 1 ) ;
V_2 -> V_5 . V_879 . V_748 = 0 ;
return V_108 ;
}
static int F_477 ( unsigned int V_23 )
{
F_478 ( V_347 , 0 ) ;
return 0 ;
}
static void F_479 ( void * V_38 )
{
struct V_1002 * V_1003 = V_38 ;
unsigned long V_263 = 0 ;
if ( V_38 )
V_263 = V_1003 -> V_871 ;
else if ( ! F_236 ( V_1004 ) )
V_263 = F_480 ( F_481 () ) ;
if ( ! V_263 )
V_263 = V_272 ;
F_478 ( V_347 , V_263 ) ;
}
static int F_482 ( struct V_1005 * V_1006 , unsigned long V_196 ,
void * V_38 )
{
struct V_1002 * V_1003 = V_38 ;
struct V_139 * V_139 ;
struct V_1 * V_2 ;
int V_3 , V_1007 = 0 ;
if ( V_196 == V_1008 && V_1003 -> V_870 > V_1003 -> V_871 )
return 0 ;
if ( V_196 == V_1009 && V_1003 -> V_870 < V_1003 -> V_871 )
return 0 ;
F_245 ( V_1003 -> V_23 , F_479 , V_1003 , 1 ) ;
F_157 ( & V_1010 ) ;
F_483 (kvm, &vm_list, vm_list) {
F_176 (i, vcpu, kvm) {
if ( V_2 -> V_23 != V_1003 -> V_23 )
continue;
F_30 ( V_339 , V_2 ) ;
if ( V_2 -> V_23 != F_8 () )
V_1007 = 1 ;
}
}
F_158 ( & V_1010 ) ;
if ( V_1003 -> V_870 < V_1003 -> V_871 && V_1007 ) {
F_245 ( V_1003 -> V_23 , F_479 , V_1003 , 1 ) ;
}
return 0 ;
}
static int F_484 ( unsigned int V_23 )
{
F_479 ( NULL ) ;
return 0 ;
}
static void F_485 ( void )
{
int V_23 ;
V_1011 = V_272 ;
if ( ! F_236 ( V_1004 ) ) {
#ifdef F_486
struct V_1012 V_1013 ;
memset ( & V_1013 , 0 , sizeof( V_1013 ) ) ;
V_23 = F_399 () ;
F_487 ( & V_1013 , V_23 ) ;
if ( V_1013 . V_1014 . V_1015 )
V_1011 = V_1013 . V_1014 . V_1015 ;
F_401 () ;
#endif
F_488 ( & V_1016 ,
V_1017 ) ;
}
F_130 ( L_22 , V_1011 ) ;
F_489 ( V_1018 , L_23 ,
F_484 , F_477 ) ;
}
int F_490 ( void )
{
return F_180 ( V_1019 ) != NULL ;
}
static int F_491 ( void )
{
int V_1020 = 3 ;
if ( F_180 ( V_1019 ) )
V_1020 = V_73 -> V_88 ( F_180 ( V_1019 ) ) ;
return V_1020 != 0 ;
}
static unsigned long F_492 ( void )
{
unsigned long V_1021 = 0 ;
if ( F_180 ( V_1019 ) )
V_1021 = F_446 ( F_180 ( V_1019 ) ) ;
return V_1021 ;
}
void F_493 ( struct V_1 * V_2 )
{
F_478 ( V_1019 , V_2 ) ;
}
void F_494 ( struct V_1 * V_2 )
{
F_478 ( V_1019 , NULL ) ;
}
static void F_495 ( void )
{
T_2 V_28 ;
int V_1022 = V_1023 . V_1024 ;
V_28 = F_496 ( V_1022 , 51 ) ;
V_28 |= 0x3ull << 62 ;
V_28 |= 1ull ;
#ifdef F_61
if ( V_1022 == 52 )
V_28 &= ~ 1ull ;
#endif
F_497 ( V_28 ) ;
}
static void F_498 ( struct V_358 * V_359 )
{
struct V_139 * V_139 ;
struct V_1 * V_2 ;
int V_3 ;
F_157 ( & V_1010 ) ;
F_483 (kvm, &vm_list, vm_list)
F_176 (i, vcpu, kvm)
F_30 ( V_297 , V_2 ) ;
F_171 ( & V_337 , 0 ) ;
F_158 ( & V_1010 ) ;
}
static int F_499 ( struct V_1005 * V_1006 , unsigned long V_1025 ,
void * V_1026 )
{
struct V_226 * V_292 = & V_226 ;
struct V_224 * V_225 = V_1026 ;
F_115 ( V_225 ) ;
if ( V_292 -> clock . V_233 != V_296 &&
F_141 ( & V_337 ) != 0 )
F_500 ( V_1027 , & V_1028 ) ;
return 0 ;
}
int F_501 ( void * V_1029 )
{
int V_121 ;
struct V_73 * V_851 = V_1029 ;
if ( V_73 ) {
F_10 ( V_26 L_24 ) ;
V_121 = - V_600 ;
goto V_113;
}
if ( ! V_851 -> V_1030 () ) {
F_10 ( V_26 L_25 ) ;
V_121 = - V_1031 ;
goto V_113;
}
if ( V_851 -> V_1032 () ) {
F_10 ( V_26 L_26 ) ;
V_121 = - V_1031 ;
goto V_113;
}
V_121 = - V_388 ;
V_25 = F_502 ( struct V_11 ) ;
if ( ! V_25 ) {
F_10 ( V_26 L_27 ) ;
goto V_113;
}
V_121 = F_503 () ;
if ( V_121 )
goto V_1033;
F_495 () ;
V_73 = V_851 ;
F_504 ( V_1034 , V_1035 ,
V_1036 , V_1037 , 0 ,
V_114 ) ;
F_485 () ;
F_505 ( & V_1038 ) ;
if ( F_236 ( V_555 ) )
V_146 = F_506 ( V_144 ) ;
F_507 () ;
#ifdef F_61
F_508 ( & V_1039 ) ;
#endif
return 0 ;
V_1033:
F_509 ( V_25 ) ;
V_113:
return V_121 ;
}
void F_510 ( void )
{
F_511 ( & V_1038 ) ;
if ( ! F_236 ( V_1004 ) )
F_512 ( & V_1016 ,
V_1017 ) ;
F_513 ( V_1018 ) ;
#ifdef F_61
F_514 ( & V_1039 ) ;
#endif
V_73 = NULL ;
F_515 () ;
F_509 ( V_25 ) ;
}
int F_516 ( struct V_1 * V_2 )
{
++ V_2 -> V_77 . V_1040 ;
if ( F_88 ( V_2 ) ) {
V_2 -> V_5 . V_1041 = V_1042 ;
return 1 ;
} else {
V_2 -> V_848 -> V_864 = V_1043 ;
return 0 ;
}
}
int F_517 ( struct V_1 * V_2 )
{
V_73 -> V_74 ( V_2 ) ;
return F_516 ( V_2 ) ;
}
static void F_518 ( struct V_139 * V_139 , unsigned long V_308 , int V_1044 )
{
struct V_1045 V_1046 ;
V_1046 . V_1047 = 0 ;
V_1046 . V_1048 = 0 ;
V_1046 . V_1049 = V_1044 ;
V_1046 . V_1050 = false ;
V_1046 . V_1051 = V_1052 ;
F_519 ( V_139 , NULL , & V_1046 , NULL ) ;
}
void F_520 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_593 = false ;
V_73 -> V_1053 ( V_2 ) ;
}
int F_521 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_1054 , V_1055 , V_1056 , V_1057 , V_108 ;
int V_1058 , V_121 = 1 ;
V_73 -> V_74 ( V_2 ) ;
if ( F_522 ( V_2 -> V_139 ) )
return F_523 ( V_2 ) ;
V_16 = F_101 ( V_2 , V_203 ) ;
V_1054 = F_101 ( V_2 , V_1059 ) ;
V_1055 = F_101 ( V_2 , V_202 ) ;
V_1056 = F_101 ( V_2 , V_204 ) ;
V_1057 = F_101 ( V_2 , V_1060 ) ;
F_524 ( V_16 , V_1054 , V_1055 , V_1056 , V_1057 ) ;
V_1058 = F_525 ( V_2 ) ;
if ( ! V_1058 ) {
V_16 &= 0xFFFFFFFF ;
V_1054 &= 0xFFFFFFFF ;
V_1055 &= 0xFFFFFFFF ;
V_1056 &= 0xFFFFFFFF ;
V_1057 &= 0xFFFFFFFF ;
}
if ( V_73 -> V_88 ( V_2 ) != 0 ) {
V_108 = - V_1061 ;
goto V_113;
}
switch ( V_16 ) {
case V_1062 :
V_108 = 0 ;
break;
case V_1063 :
F_518 ( V_2 -> V_139 , V_1054 , V_1055 ) ;
V_108 = 0 ;
break;
default:
V_108 = - V_1064 ;
break;
}
V_113:
if ( ! V_1058 )
V_108 = ( T_1 ) V_108 ;
F_103 ( V_2 , V_203 , V_108 ) ;
++ V_2 -> V_77 . V_1065 ;
return V_121 ;
}
static int F_526 ( struct V_836 * V_837 )
{
struct V_1 * V_2 = F_356 ( V_837 ) ;
char V_1066 [ 3 ] ;
unsigned long V_1067 = F_446 ( V_2 ) ;
V_73 -> V_1068 ( V_2 , V_1066 ) ;
return F_378 ( V_837 , V_1067 , V_1066 , 3 , NULL ) ;
}
static int F_527 ( struct V_1 * V_2 )
{
return V_2 -> V_848 -> V_1069 &&
F_163 ( ! F_265 ( V_2 -> V_139 ) ) ;
}
static void F_528 ( struct V_1 * V_2 )
{
struct V_970 * V_970 = V_2 -> V_848 ;
V_970 -> V_1070 = ( F_445 ( V_2 ) & V_1001 ) != 0 ;
V_970 -> V_308 = F_274 ( V_2 ) ? V_1071 : 0 ;
V_970 -> V_177 = F_90 ( V_2 ) ;
V_970 -> V_31 = F_19 ( V_2 ) ;
V_970 -> V_1072 =
F_265 ( V_2 -> V_139 ) ||
F_258 ( V_2 ) ;
}
static void F_255 ( struct V_1 * V_2 )
{
int V_1073 , V_1074 ;
if ( ! V_73 -> F_255 )
return;
if ( ! F_88 ( V_2 ) )
return;
if ( V_2 -> V_5 . V_593 )
return;
if ( ! V_2 -> V_5 . V_646 -> V_701 )
V_1073 = F_529 ( V_2 ) ;
else
V_1073 = - 1 ;
if ( V_1073 != - 1 )
V_1073 >>= 4 ;
V_1074 = F_91 ( V_2 ) ;
V_73 -> F_255 ( V_2 , V_1074 , V_1073 ) ;
}
static int F_530 ( struct V_1 * V_2 , bool V_1075 )
{
int V_121 ;
if ( V_2 -> V_5 . V_68 . V_69 ) {
F_531 ( V_2 -> V_5 . V_68 . V_16 ,
V_2 -> V_5 . V_68 . V_71 ,
V_2 -> V_5 . V_68 . V_62 ) ;
if ( F_27 ( V_2 -> V_5 . V_68 . V_16 ) == V_60 )
F_475 ( V_2 , F_445 ( V_2 ) |
V_979 ) ;
if ( V_2 -> V_5 . V_68 . V_16 == V_53 &&
( V_2 -> V_5 . V_188 & V_1076 ) ) {
V_2 -> V_5 . V_188 &= ~ V_1076 ;
F_94 ( V_2 ) ;
}
V_73 -> V_1077 ( V_2 , V_2 -> V_5 . V_68 . V_16 ,
V_2 -> V_5 . V_68 . V_71 ,
V_2 -> V_5 . V_68 . V_62 ,
V_2 -> V_5 . V_68 . V_63 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_627 ) {
V_73 -> V_1078 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_622 . V_69 ) {
V_73 -> V_1079 ( V_2 ) ;
return 0 ;
}
if ( F_454 ( V_2 ) && V_73 -> V_1080 ) {
V_121 = V_73 -> V_1080 ( V_2 , V_1075 ) ;
if ( V_121 != 0 )
return V_121 ;
}
if ( V_2 -> V_5 . V_634 && ! F_274 ( V_2 ) ) {
V_2 -> V_5 . V_634 = false ;
F_532 ( V_2 ) ;
} else if ( V_2 -> V_5 . V_628 && V_73 -> V_1081 ( V_2 ) ) {
-- V_2 -> V_5 . V_628 ;
V_2 -> V_5 . V_627 = true ;
V_73 -> V_1078 ( V_2 ) ;
} else if ( F_533 ( V_2 ) ) {
if ( F_454 ( V_2 ) && V_73 -> V_1080 ) {
V_121 = V_73 -> V_1080 ( V_2 , V_1075 ) ;
if ( V_121 != 0 )
return V_121 ;
}
if ( V_73 -> V_1082 ( V_2 ) ) {
F_264 ( V_2 , F_534 ( V_2 ) ,
false ) ;
V_73 -> V_1079 ( V_2 ) ;
}
}
return 0 ;
}
static void F_272 ( struct V_1 * V_2 )
{
unsigned V_910 = 2 ;
if ( V_73 -> V_630 ( V_2 ) || V_2 -> V_5 . V_627 )
V_910 = 1 ;
V_2 -> V_5 . V_628 += F_535 ( & V_2 -> V_5 . V_85 , 0 ) ;
V_2 -> V_5 . V_628 = F_340 ( V_2 -> V_5 . V_628 , V_910 ) ;
F_30 ( V_67 , V_2 ) ;
}
static T_1 F_536 ( struct V_822 * V_824 )
{
T_1 V_308 = 0 ;
V_308 |= V_824 -> V_909 << 23 ;
V_308 |= V_824 -> V_183 << 22 ;
V_308 |= V_824 -> V_915 << 21 ;
V_308 |= V_824 -> V_914 << 20 ;
V_308 |= V_824 -> V_913 << 15 ;
V_308 |= V_824 -> V_911 << 13 ;
V_308 |= V_824 -> V_592 << 12 ;
V_308 |= V_824 -> type << 8 ;
return V_308 ;
}
static void F_537 ( struct V_1 * V_2 , char * V_1083 , int V_491 )
{
struct V_822 V_824 ;
int V_94 ;
F_348 ( V_2 , & V_824 , V_491 ) ;
F_538 ( T_1 , V_1083 , 0x7fa8 + V_491 * 4 , V_824 . V_904 ) ;
if ( V_491 < 3 )
V_94 = 0x7f84 + V_491 * 12 ;
else
V_94 = 0x7f2c + ( V_491 - 3 ) * 12 ;
F_538 ( T_1 , V_1083 , V_94 + 8 , V_824 . V_230 ) ;
F_538 ( T_1 , V_1083 , V_94 + 4 , V_824 . V_910 ) ;
F_538 ( T_1 , V_1083 , V_94 , F_536 ( & V_824 ) ) ;
}
static void F_539 ( struct V_1 * V_2 , char * V_1083 , int V_491 )
{
struct V_822 V_824 ;
int V_94 ;
V_875 V_308 ;
F_348 ( V_2 , & V_824 , V_491 ) ;
V_94 = 0x7e00 + V_491 * 16 ;
V_308 = F_536 ( & V_824 ) >> 8 ;
F_538 ( V_875 , V_1083 , V_94 , V_824 . V_904 ) ;
F_538 ( V_875 , V_1083 , V_94 + 2 , V_308 ) ;
F_538 ( T_1 , V_1083 , V_94 + 4 , V_824 . V_910 ) ;
F_538 ( T_2 , V_1083 , V_94 + 8 , V_824 . V_230 ) ;
}
static void F_540 ( struct V_1 * V_2 , char * V_1083 )
{
struct V_898 V_899 ;
struct V_822 V_824 ;
unsigned long V_196 ;
int V_3 ;
F_538 ( T_1 , V_1083 , 0x7ffc , F_60 ( V_2 ) ) ;
F_538 ( T_1 , V_1083 , 0x7ff8 , F_58 ( V_2 ) ) ;
F_538 ( T_1 , V_1083 , 0x7ff4 , F_445 ( V_2 ) ) ;
F_538 ( T_1 , V_1083 , 0x7ff0 , F_446 ( V_2 ) ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
F_538 ( T_1 , V_1083 , 0x7fd0 + V_3 * 4 , F_101 ( V_2 , V_3 ) ) ;
F_99 ( V_2 , 6 , & V_196 ) ;
F_538 ( T_1 , V_1083 , 0x7fcc , ( T_1 ) V_196 ) ;
F_99 ( V_2 , 7 , & V_196 ) ;
F_538 ( T_1 , V_1083 , 0x7fc8 , ( T_1 ) V_196 ) ;
F_348 ( V_2 , & V_824 , V_1084 ) ;
F_538 ( T_1 , V_1083 , 0x7fc4 , V_824 . V_904 ) ;
F_538 ( T_1 , V_1083 , 0x7f64 , V_824 . V_230 ) ;
F_538 ( T_1 , V_1083 , 0x7f60 , V_824 . V_910 ) ;
F_538 ( T_1 , V_1083 , 0x7f5c , F_536 ( & V_824 ) ) ;
F_348 ( V_2 , & V_824 , V_1085 ) ;
F_538 ( T_1 , V_1083 , 0x7fc0 , V_824 . V_904 ) ;
F_538 ( T_1 , V_1083 , 0x7f80 , V_824 . V_230 ) ;
F_538 ( T_1 , V_1083 , 0x7f7c , V_824 . V_910 ) ;
F_538 ( T_1 , V_1083 , 0x7f78 , F_536 ( & V_824 ) ) ;
V_73 -> V_900 ( V_2 , & V_899 ) ;
F_538 ( T_1 , V_1083 , 0x7f74 , V_899 . V_80 ) ;
F_538 ( T_1 , V_1083 , 0x7f70 , V_899 . V_492 ) ;
V_73 -> V_901 ( V_2 , & V_899 ) ;
F_538 ( T_1 , V_1083 , 0x7f58 , V_899 . V_80 ) ;
F_538 ( T_1 , V_1083 , 0x7f54 , V_899 . V_492 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_537 ( V_2 , V_1083 , V_3 ) ;
F_538 ( T_1 , V_1083 , 0x7f14 , F_77 ( V_2 ) ) ;
F_538 ( T_1 , V_1083 , 0x7efc , 0x00020000 ) ;
F_538 ( T_1 , V_1083 , 0x7ef8 , V_2 -> V_5 . V_425 ) ;
}
static void F_541 ( struct V_1 * V_2 , char * V_1083 )
{
#ifdef F_61
struct V_898 V_899 ;
struct V_822 V_824 ;
unsigned long V_196 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ )
F_538 ( T_2 , V_1083 , 0x7ff8 - V_3 * 8 , F_101 ( V_2 , V_3 ) ) ;
F_538 ( T_2 , V_1083 , 0x7f78 , F_446 ( V_2 ) ) ;
F_538 ( T_1 , V_1083 , 0x7f70 , F_445 ( V_2 ) ) ;
F_99 ( V_2 , 6 , & V_196 ) ;
F_538 ( T_2 , V_1083 , 0x7f68 , V_196 ) ;
F_99 ( V_2 , 7 , & V_196 ) ;
F_538 ( T_2 , V_1083 , 0x7f60 , V_196 ) ;
F_538 ( T_2 , V_1083 , 0x7f58 , F_60 ( V_2 ) ) ;
F_538 ( T_2 , V_1083 , 0x7f50 , F_58 ( V_2 ) ) ;
F_538 ( T_2 , V_1083 , 0x7f48 , F_77 ( V_2 ) ) ;
F_538 ( T_1 , V_1083 , 0x7f00 , V_2 -> V_5 . V_425 ) ;
F_538 ( T_1 , V_1083 , 0x7efc , 0x00020064 ) ;
F_538 ( T_2 , V_1083 , 0x7ed0 , V_2 -> V_5 . V_132 ) ;
F_348 ( V_2 , & V_824 , V_1084 ) ;
F_538 ( V_875 , V_1083 , 0x7e90 , V_824 . V_904 ) ;
F_538 ( V_875 , V_1083 , 0x7e92 , F_536 ( & V_824 ) >> 8 ) ;
F_538 ( T_1 , V_1083 , 0x7e94 , V_824 . V_910 ) ;
F_538 ( T_2 , V_1083 , 0x7e98 , V_824 . V_230 ) ;
V_73 -> V_901 ( V_2 , & V_899 ) ;
F_538 ( T_1 , V_1083 , 0x7e84 , V_899 . V_492 ) ;
F_538 ( T_2 , V_1083 , 0x7e88 , V_899 . V_80 ) ;
F_348 ( V_2 , & V_824 , V_1085 ) ;
F_538 ( V_875 , V_1083 , 0x7e70 , V_824 . V_904 ) ;
F_538 ( V_875 , V_1083 , 0x7e72 , F_536 ( & V_824 ) >> 8 ) ;
F_538 ( T_1 , V_1083 , 0x7e74 , V_824 . V_910 ) ;
F_538 ( T_2 , V_1083 , 0x7e78 , V_824 . V_230 ) ;
V_73 -> V_900 ( V_2 , & V_899 ) ;
F_538 ( T_1 , V_1083 , 0x7e64 , V_899 . V_492 ) ;
F_538 ( T_2 , V_1083 , 0x7e68 , V_899 . V_80 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_539 ( V_2 , V_1083 , V_3 ) ;
#else
F_542 ( 1 ) ;
#endif
}
static void F_532 ( struct V_1 * V_2 )
{
struct V_822 V_1086 , V_1087 ;
struct V_898 V_899 ;
char V_1083 [ 512 ] ;
T_1 V_122 ;
F_463 ( V_2 -> V_298 , V_2 -> V_5 . V_425 , true ) ;
V_2 -> V_5 . V_636 |= V_647 ;
memset ( V_1083 , 0 , 512 ) ;
if ( F_543 ( V_2 ) )
F_541 ( V_2 , V_1083 ) ;
else
F_540 ( V_2 , V_1083 ) ;
F_200 ( V_2 , V_2 -> V_5 . V_425 + 0xfe00 , V_1083 , sizeof( V_1083 ) ) ;
if ( V_73 -> V_630 ( V_2 ) )
V_2 -> V_5 . V_636 |= V_637 ;
else
V_73 -> V_645 ( V_2 , true ) ;
F_451 ( V_2 , V_1088 ) ;
F_450 ( V_2 , 0x8000 ) ;
V_122 = V_2 -> V_5 . V_122 & ~ ( V_131 | V_1089 | V_1090 | V_125 ) ;
V_73 -> V_138 ( V_2 , V_122 ) ;
V_2 -> V_5 . V_122 = V_122 ;
V_73 -> V_171 ( V_2 , 0 ) ;
V_899 . V_80 = V_899 . V_492 = 0 ;
V_73 -> V_903 ( V_2 , & V_899 ) ;
F_97 ( V_2 , 7 , V_199 ) ;
V_1086 . V_904 = ( V_2 -> V_5 . V_425 >> 4 ) & 0xffff ;
V_1086 . V_230 = V_2 -> V_5 . V_425 ;
V_1087 . V_904 = 0 ;
V_1087 . V_230 = 0 ;
V_1086 . V_910 = V_1087 . V_910 = 0xffffffff ;
V_1086 . type = V_1087 . type = 0x3 ;
V_1086 . V_911 = V_1087 . V_911 = 0 ;
V_1086 . V_183 = V_1087 . V_183 = 0 ;
V_1086 . V_592 = V_1087 . V_592 = 1 ;
V_1086 . V_915 = V_1087 . V_915 = 0 ;
V_1086 . V_909 = V_1087 . V_909 = 1 ;
V_1086 . V_914 = V_1087 . V_914 = 0 ;
V_1086 . V_913 = V_1087 . V_913 = 1 ;
V_1086 . V_908 = V_1087 . V_908 = 0 ;
V_1086 . V_917 = V_1087 . V_917 = 0 ;
F_347 ( V_2 , & V_1086 , V_1091 ) ;
F_347 ( V_2 , & V_1087 , V_1092 ) ;
F_347 ( V_2 , & V_1087 , V_1093 ) ;
F_347 ( V_2 , & V_1087 , V_1094 ) ;
F_347 ( V_2 , & V_1087 , V_1095 ) ;
F_347 ( V_2 , & V_1087 , V_1096 ) ;
if ( F_543 ( V_2 ) )
V_73 -> F_107 ( V_2 , 0 ) ;
F_74 ( V_2 ) ;
F_64 ( V_2 ) ;
}
static void F_544 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_634 = true ;
F_30 ( V_67 , V_2 ) ;
}
void F_545 ( struct V_139 * V_139 )
{
F_174 ( V_139 , V_1097 ) ;
}
static void F_546 ( struct V_1 * V_2 )
{
T_2 V_1098 [ 4 ] ;
if ( ! F_547 ( V_2 -> V_5 . V_646 ) )
return;
F_548 ( V_2 -> V_5 . V_1099 , 256 ) ;
if ( V_769 ( V_2 -> V_139 ) )
F_549 ( V_2 , V_2 -> V_5 . V_1099 ) ;
else {
if ( V_2 -> V_5 . V_593 )
V_73 -> V_594 ( V_2 ) ;
F_550 ( V_2 , V_2 -> V_5 . V_1099 ) ;
}
F_551 ( ( V_176 * ) V_1098 , V_2 -> V_5 . V_1099 ,
F_552 ( V_2 ) -> V_1100 , 256 ) ;
V_73 -> V_1101 ( V_2 , V_1098 ) ;
}
static void F_553 ( struct V_1 * V_2 )
{
++ V_2 -> V_77 . V_1102 ;
V_73 -> V_1102 ( V_2 ) ;
}
void F_554 ( struct V_1 * V_2 )
{
struct V_386 * V_386 = NULL ;
if ( ! F_88 ( V_2 ) )
return;
if ( ! V_73 -> V_1103 )
return;
V_386 = F_555 ( V_2 -> V_139 , V_841 >> V_106 ) ;
if ( F_381 ( V_386 ) )
return;
V_73 -> V_1103 ( V_2 , F_556 ( V_386 ) ) ;
F_557 ( V_386 ) ;
}
void F_558 ( struct V_139 * V_139 ,
unsigned long V_80 )
{
if ( V_80 == F_559 ( V_139 , V_841 >> V_106 ) )
F_174 ( V_139 , V_1104 ) ;
}
static int F_560 ( struct V_1 * V_2 )
{
int V_121 ;
bool V_1075 =
F_527 ( V_2 ) &&
F_256 ( V_2 ) ;
bool V_1105 = false ;
if ( V_2 -> V_340 ) {
if ( F_561 ( V_1106 , V_2 ) )
F_562 ( V_2 ) ;
if ( F_561 ( V_582 , V_2 ) )
F_563 ( V_2 ) ;
if ( F_561 ( V_297 , V_2 ) )
F_175 ( V_2 -> V_139 ) ;
if ( F_561 ( V_432 , V_2 ) )
F_191 ( V_2 ) ;
if ( F_561 ( V_339 , V_2 ) ) {
V_121 = F_178 ( V_2 ) ;
if ( F_167 ( V_121 ) )
goto V_113;
}
if ( F_561 ( V_1107 , V_2 ) )
F_85 ( V_2 ) ;
if ( F_561 ( V_173 , V_2 ) )
F_553 ( V_2 ) ;
if ( F_561 ( V_1108 , V_2 ) ) {
V_2 -> V_848 -> V_864 = V_1109 ;
V_121 = 0 ;
goto V_113;
}
if ( F_561 ( V_72 , V_2 ) ) {
V_2 -> V_848 -> V_864 = V_1110 ;
V_121 = 0 ;
goto V_113;
}
if ( F_561 ( V_1111 , V_2 ) ) {
V_2 -> V_1112 = 0 ;
V_73 -> V_1113 ( V_2 ) ;
}
if ( F_561 ( V_1114 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1115 = true ;
V_121 = 1 ;
goto V_113;
}
if ( F_561 ( V_437 , V_2 ) )
F_206 ( V_2 ) ;
if ( F_561 ( V_601 , V_2 ) )
F_544 ( V_2 ) ;
if ( F_561 ( V_86 , V_2 ) )
F_272 ( V_2 ) ;
if ( F_561 ( V_1116 , V_2 ) )
F_564 ( V_2 ) ;
if ( F_561 ( V_1117 , V_2 ) )
F_565 ( V_2 ) ;
if ( F_561 ( V_1118 , V_2 ) ) {
F_13 ( V_2 -> V_5 . V_1119 > 255 ) ;
if ( F_57 ( V_2 -> V_5 . V_1119 ,
V_2 -> V_5 . V_1099 ) ) {
V_2 -> V_848 -> V_864 = V_1120 ;
V_2 -> V_848 -> V_1121 . V_41 =
V_2 -> V_5 . V_1119 ;
V_121 = 0 ;
goto V_113;
}
}
if ( F_561 ( V_1097 , V_2 ) )
F_546 ( V_2 ) ;
if ( F_561 ( V_1104 , V_2 ) )
F_554 ( V_2 ) ;
if ( F_561 ( V_1122 , V_2 ) ) {
V_2 -> V_848 -> V_864 = V_1123 ;
V_2 -> V_848 -> V_1124 . type = V_1125 ;
V_121 = 0 ;
goto V_113;
}
if ( F_561 ( V_1126 , V_2 ) ) {
V_2 -> V_848 -> V_864 = V_1123 ;
V_2 -> V_848 -> V_1124 . type = V_1127 ;
V_121 = 0 ;
goto V_113;
}
if ( F_561 ( V_1128 , V_2 ) ) {
V_2 -> V_848 -> V_864 = V_1129 ;
V_2 -> V_848 -> V_1130 = V_2 -> V_5 . V_1130 . exit ;
V_121 = 0 ;
goto V_113;
}
if ( F_561 ( V_1131 , V_2 ) )
F_566 ( V_2 ) ;
}
if ( F_567 ( V_2 ) ) {
if ( V_2 -> V_5 . V_593 )
V_73 -> V_1132 ( V_2 ,
F_529 ( V_2 ) ) ;
}
if ( F_561 ( V_67 , V_2 ) || V_1075 ) {
F_568 ( V_2 ) ;
if ( V_2 -> V_5 . V_1041 == V_1133 ) {
V_121 = 1 ;
goto V_113;
}
if ( F_530 ( V_2 , V_1075 ) != 0 )
V_1105 = true ;
else {
if ( V_2 -> V_5 . V_634 && ! F_274 ( V_2 ) )
V_1105 = true ;
if ( V_2 -> V_5 . V_628 )
V_73 -> V_1134 ( V_2 ) ;
if ( F_533 ( V_2 ) || V_1075 )
V_73 -> V_1135 ( V_2 ) ;
}
if ( F_567 ( V_2 ) ) {
F_255 ( V_2 ) ;
F_569 ( V_2 ) ;
}
}
V_121 = F_570 ( V_2 ) ;
if ( F_167 ( V_121 ) ) {
goto V_1136;
}
F_432 () ;
V_73 -> V_1137 ( V_2 ) ;
if ( V_2 -> V_1112 )
F_433 ( V_2 ) ;
V_2 -> V_331 = V_1138 ;
F_229 ( & V_2 -> V_139 -> V_487 , V_2 -> V_1139 ) ;
F_571 () ;
F_334 () ;
if ( V_2 -> V_331 == V_1140 || V_2 -> V_340
|| F_572 () || F_573 ( V_400 ) ) {
V_2 -> V_331 = V_1141 ;
F_186 () ;
F_335 () ;
F_436 () ;
V_2 -> V_1139 = F_228 ( & V_2 -> V_139 -> V_487 ) ;
V_121 = 1 ;
goto V_1136;
}
F_70 ( V_2 ) ;
if ( V_1105 ) {
F_30 ( V_67 , V_2 ) ;
F_574 ( V_2 -> V_23 ) ;
}
F_575 ( V_2 -> V_298 ) ;
F_576 ( V_2 ) ;
F_577 () ;
if ( F_167 ( V_2 -> V_5 . V_184 ) ) {
F_578 ( 0 , 7 ) ;
F_578 ( V_2 -> V_5 . V_182 [ 0 ] , 0 ) ;
F_578 ( V_2 -> V_5 . V_182 [ 1 ] , 1 ) ;
F_578 ( V_2 -> V_5 . V_182 [ 2 ] , 2 ) ;
F_578 ( V_2 -> V_5 . V_182 [ 3 ] , 3 ) ;
F_578 ( V_2 -> V_5 . V_187 , 6 ) ;
V_2 -> V_5 . V_184 &= ~ V_185 ;
}
V_73 -> V_848 ( V_2 ) ;
if ( F_167 ( V_2 -> V_5 . V_184 & V_1142 ) ) {
F_28 ( V_2 -> V_179 & V_180 ) ;
V_73 -> V_1143 ( V_2 ) ;
F_92 ( V_2 ) ;
F_93 ( V_2 ) ;
F_94 ( V_2 ) ;
V_2 -> V_5 . V_184 &= ~ V_185 ;
}
if ( F_579 () )
F_580 () ;
V_2 -> V_5 . V_324 = F_149 ( V_2 , F_148 () ) ;
V_2 -> V_331 = V_1141 ;
F_186 () ;
F_72 ( V_2 ) ;
V_73 -> V_1144 ( V_2 ) ;
++ V_2 -> V_77 . V_1145 ;
F_581 () ;
F_335 () ;
F_436 () ;
V_2 -> V_1139 = F_228 ( & V_2 -> V_139 -> V_487 ) ;
if ( F_167 ( V_1146 == V_1147 ) ) {
unsigned long V_1067 = F_446 ( V_2 ) ;
F_582 ( V_1147 , ( void * ) V_1067 ) ;
}
if ( F_167 ( V_2 -> V_5 . V_274 ) )
F_30 ( V_339 , V_2 ) ;
if ( V_2 -> V_5 . V_1148 )
F_583 ( V_2 ) ;
V_121 = V_73 -> V_1149 ( V_2 ) ;
return V_121 ;
V_1136:
V_73 -> V_1136 ( V_2 ) ;
if ( F_167 ( V_2 -> V_5 . V_1148 ) )
F_583 ( V_2 ) ;
V_113:
return V_121 ;
}
static inline int F_584 ( struct V_139 * V_139 , struct V_1 * V_2 )
{
if ( ! F_585 ( V_2 ) &&
( ! V_73 -> V_1150 || V_73 -> V_1150 ( V_2 ) == 0 ) ) {
F_229 ( & V_139 -> V_487 , V_2 -> V_1139 ) ;
F_586 ( V_2 ) ;
V_2 -> V_1139 = F_228 ( & V_139 -> V_487 ) ;
if ( V_73 -> V_1151 )
V_73 -> V_1151 ( V_2 ) ;
if ( ! F_561 ( V_1152 , V_2 ) )
return 1 ;
}
F_568 ( V_2 ) ;
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
static inline bool F_587 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_1041 == V_1155 &&
! V_2 -> V_5 . V_6 . V_1115 ) ;
}
static int F_588 ( struct V_1 * V_2 )
{
int V_121 ;
struct V_139 * V_139 = V_2 -> V_139 ;
V_2 -> V_1139 = F_228 ( & V_139 -> V_487 ) ;
for (; ; ) {
if ( F_587 ( V_2 ) ) {
V_121 = F_560 ( V_2 ) ;
} else {
V_121 = F_584 ( V_139 , V_2 ) ;
}
if ( V_121 <= 0 )
break;
F_177 ( V_240 , & V_2 -> V_340 ) ;
if ( F_589 ( V_2 ) )
F_590 ( V_2 ) ;
if ( F_527 ( V_2 ) &&
F_258 ( V_2 ) ) {
V_121 = 0 ;
V_2 -> V_848 -> V_864 = V_1157 ;
++ V_2 -> V_77 . V_1158 ;
break;
}
F_591 ( V_2 ) ;
if ( F_573 ( V_400 ) ) {
V_121 = - V_1156 ;
V_2 -> V_848 -> V_864 = V_1159 ;
++ V_2 -> V_77 . V_1160 ;
break;
}
if ( F_572 () ) {
F_229 ( & V_139 -> V_487 , V_2 -> V_1139 ) ;
F_592 () ;
V_2 -> V_1139 = F_228 ( & V_139 -> V_487 ) ;
}
}
F_229 ( & V_139 -> V_487 , V_2 -> V_1139 ) ;
return V_121 ;
}
static inline int F_593 ( struct V_1 * V_2 )
{
int V_121 ;
V_2 -> V_1139 = F_228 ( & V_2 -> V_139 -> V_487 ) ;
V_121 = F_594 ( V_2 , V_983 ) ;
F_229 ( & V_2 -> V_139 -> V_487 , V_2 -> V_1139 ) ;
if ( V_121 != V_950 )
return 0 ;
return 1 ;
}
static int V_996 ( struct V_1 * V_2 )
{
F_13 ( ! V_2 -> V_5 . V_879 . V_748 ) ;
return F_593 ( V_2 ) ;
}
static int V_997 ( struct V_1 * V_2 )
{
struct V_970 * V_848 = V_2 -> V_848 ;
struct V_846 * V_847 ;
unsigned V_95 ;
F_13 ( ! V_2 -> V_860 ) ;
V_847 = & V_2 -> V_843 [ V_2 -> V_861 ] ;
V_95 = F_340 ( 8u , V_847 -> V_95 ) ;
if ( ! V_2 -> V_863 )
memcpy ( V_847 -> V_38 , V_848 -> V_849 . V_38 , V_95 ) ;
if ( V_847 -> V_95 <= 8 ) {
V_847 ++ ;
V_2 -> V_861 ++ ;
} else {
V_847 -> V_38 += V_95 ;
V_847 -> V_390 += V_95 ;
V_847 -> V_95 -= V_95 ;
}
if ( V_2 -> V_861 >= V_2 -> V_854 ) {
V_2 -> V_860 = 0 ;
if ( V_2 -> V_863 )
return 1 ;
V_2 -> V_842 = 1 ;
return F_593 ( V_2 ) ;
}
V_848 -> V_864 = V_865 ;
V_848 -> V_849 . V_866 = V_847 -> V_390 ;
if ( V_2 -> V_863 )
memcpy ( V_848 -> V_849 . V_38 , V_847 -> V_38 , F_340 ( 8u , V_847 -> V_95 ) ) ;
V_848 -> V_849 . V_95 = F_340 ( 8u , V_847 -> V_95 ) ;
V_848 -> V_849 . V_862 = V_2 -> V_863 ;
V_2 -> V_5 . V_995 = V_997 ;
return 0 ;
}
int F_595 ( struct V_1 * V_2 , struct V_970 * V_970 )
{
struct V_1161 * V_1161 = & V_400 -> V_1162 . V_1161 ;
int V_121 ;
T_18 V_1163 ;
F_596 ( V_1161 ) ;
if ( V_2 -> V_1164 )
F_597 ( V_1165 , & V_2 -> V_1166 , & V_1163 ) ;
if ( F_167 ( V_2 -> V_5 . V_1041 == V_1167 ) ) {
F_586 ( V_2 ) ;
F_568 ( V_2 ) ;
F_177 ( V_1152 , & V_2 -> V_340 ) ;
V_121 = - V_1168 ;
goto V_113;
}
if ( ! F_88 ( V_2 ) ) {
if ( F_87 ( V_2 , V_970 -> V_177 ) != 0 ) {
V_121 = - V_580 ;
goto V_113;
}
}
if ( F_167 ( V_2 -> V_5 . V_995 ) ) {
int (* F_598)( struct V_1 * ) = V_2 -> V_5 . V_995 ;
V_2 -> V_5 . V_995 = NULL ;
V_121 = F_598 ( V_2 ) ;
if ( V_121 <= 0 )
goto V_113;
} else
F_28 ( V_2 -> V_5 . V_879 . V_748 || V_2 -> V_860 ) ;
V_121 = F_588 ( V_2 ) ;
V_113:
F_528 ( V_2 ) ;
if ( V_2 -> V_1164 )
F_597 ( V_1165 , & V_1163 , NULL ) ;
return V_121 ;
}
int F_599 ( struct V_1 * V_2 , struct V_1169 * V_1170 )
{
if ( V_2 -> V_5 . V_1000 ) {
F_600 ( & V_2 -> V_5 . V_930 ) ;
V_2 -> V_5 . V_1000 = false ;
}
V_1170 -> V_1171 = F_101 ( V_2 , V_203 ) ;
V_1170 -> V_1172 = F_101 ( V_2 , V_1059 ) ;
V_1170 -> V_1173 = F_101 ( V_2 , V_202 ) ;
V_1170 -> V_1174 = F_101 ( V_2 , V_204 ) ;
V_1170 -> V_1175 = F_101 ( V_2 , V_1060 ) ;
V_1170 -> V_1176 = F_101 ( V_2 , V_1177 ) ;
V_1170 -> V_1178 = F_101 ( V_2 , V_1179 ) ;
V_1170 -> V_1180 = F_101 ( V_2 , V_1181 ) ;
#ifdef F_61
V_1170 -> V_1182 = F_101 ( V_2 , V_1183 ) ;
V_1170 -> V_1184 = F_101 ( V_2 , V_1185 ) ;
V_1170 -> V_1186 = F_101 ( V_2 , V_1187 ) ;
V_1170 -> V_1188 = F_101 ( V_2 , V_1189 ) ;
V_1170 -> V_1190 = F_101 ( V_2 , V_1191 ) ;
V_1170 -> V_1192 = F_101 ( V_2 , V_1193 ) ;
V_1170 -> V_1194 = F_101 ( V_2 , V_1195 ) ;
V_1170 -> V_1196 = F_101 ( V_2 , V_1197 ) ;
#endif
V_1170 -> V_1067 = F_446 ( V_2 ) ;
V_1170 -> V_969 = F_445 ( V_2 ) ;
return 0 ;
}
int F_601 ( struct V_1 * V_2 , struct V_1169 * V_1170 )
{
V_2 -> V_5 . V_944 = true ;
V_2 -> V_5 . V_1000 = false ;
F_103 ( V_2 , V_203 , V_1170 -> V_1171 ) ;
F_103 ( V_2 , V_1059 , V_1170 -> V_1172 ) ;
F_103 ( V_2 , V_202 , V_1170 -> V_1173 ) ;
F_103 ( V_2 , V_204 , V_1170 -> V_1174 ) ;
F_103 ( V_2 , V_1060 , V_1170 -> V_1175 ) ;
F_103 ( V_2 , V_1177 , V_1170 -> V_1176 ) ;
F_103 ( V_2 , V_1179 , V_1170 -> V_1178 ) ;
F_103 ( V_2 , V_1181 , V_1170 -> V_1180 ) ;
#ifdef F_61
F_103 ( V_2 , V_1183 , V_1170 -> V_1182 ) ;
F_103 ( V_2 , V_1185 , V_1170 -> V_1184 ) ;
F_103 ( V_2 , V_1187 , V_1170 -> V_1186 ) ;
F_103 ( V_2 , V_1189 , V_1170 -> V_1188 ) ;
F_103 ( V_2 , V_1191 , V_1170 -> V_1190 ) ;
F_103 ( V_2 , V_1193 , V_1170 -> V_1192 ) ;
F_103 ( V_2 , V_1195 , V_1170 -> V_1194 ) ;
F_103 ( V_2 , V_1197 , V_1170 -> V_1196 ) ;
#endif
F_450 ( V_2 , V_1170 -> V_1067 ) ;
F_451 ( V_2 , V_1170 -> V_969 ) ;
V_2 -> V_5 . V_68 . V_69 = false ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
void F_602 ( struct V_1 * V_2 , int * V_183 , int * V_915 )
{
struct V_822 V_1086 ;
F_348 ( V_2 , & V_1086 , V_1091 ) ;
* V_183 = V_1086 . V_183 ;
* V_915 = V_1086 . V_915 ;
}
int F_603 ( struct V_1 * V_2 ,
struct V_1198 * V_1199 )
{
struct V_898 V_899 ;
F_348 ( V_2 , & V_1199 -> V_1086 , V_1091 ) ;
F_348 ( V_2 , & V_1199 -> V_1087 , V_1092 ) ;
F_348 ( V_2 , & V_1199 -> V_1200 , V_1093 ) ;
F_348 ( V_2 , & V_1199 -> V_1201 , V_1094 ) ;
F_348 ( V_2 , & V_1199 -> V_1202 , V_1095 ) ;
F_348 ( V_2 , & V_1199 -> V_1203 , V_1096 ) ;
F_348 ( V_2 , & V_1199 -> V_1204 , V_1084 ) ;
F_348 ( V_2 , & V_1199 -> V_1205 , V_1085 ) ;
V_73 -> V_901 ( V_2 , & V_899 ) ;
V_1199 -> V_1206 . V_910 = V_899 . V_492 ;
V_1199 -> V_1206 . V_230 = V_899 . V_80 ;
V_73 -> V_900 ( V_2 , & V_899 ) ;
V_1199 -> V_1207 . V_910 = V_899 . V_492 ;
V_1199 -> V_1207 . V_230 = V_899 . V_80 ;
V_1199 -> V_122 = F_60 ( V_2 ) ;
V_1199 -> V_79 = V_2 -> V_5 . V_79 ;
V_1199 -> V_104 = F_58 ( V_2 ) ;
V_1199 -> V_159 = F_77 ( V_2 ) ;
V_1199 -> V_177 = F_90 ( V_2 ) ;
V_1199 -> V_132 = V_2 -> V_5 . V_132 ;
V_1199 -> V_31 = F_19 ( V_2 ) ;
memset ( V_1199 -> V_1208 , 0 , sizeof V_1199 -> V_1208 ) ;
if ( V_2 -> V_5 . V_622 . V_69 && ! V_2 -> V_5 . V_622 . V_623 )
F_212 ( V_2 -> V_5 . V_622 . V_16 ,
( unsigned long * ) V_1199 -> V_1208 ) ;
return 0 ;
}
int F_604 ( struct V_1 * V_2 ,
struct V_1209 * V_1041 )
{
F_568 ( V_2 ) ;
if ( V_2 -> V_5 . V_1041 == V_1042 &&
V_2 -> V_5 . V_1153 . V_1154 )
V_1041 -> V_1041 = V_1155 ;
else
V_1041 -> V_1041 = V_2 -> V_5 . V_1041 ;
return 0 ;
}
int F_605 ( struct V_1 * V_2 ,
struct V_1209 * V_1041 )
{
if ( ! F_88 ( V_2 ) &&
V_1041 -> V_1041 != V_1155 )
return - V_580 ;
if ( V_1041 -> V_1041 == V_1210 ) {
V_2 -> V_5 . V_1041 = V_1133 ;
F_212 ( V_1211 , & V_2 -> V_5 . V_646 -> V_649 ) ;
} else
V_2 -> V_5 . V_1041 = V_1041 -> V_1041 ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
int F_606 ( struct V_1 * V_2 , V_875 V_1212 , int V_1213 ,
int V_1214 , bool V_71 , T_1 V_62 )
{
struct V_836 * V_837 = & V_2 -> V_5 . V_930 ;
int V_108 ;
F_444 ( V_2 ) ;
V_108 = F_607 ( V_837 , V_1212 , V_1213 , V_1214 ,
V_71 , V_62 ) ;
if ( V_108 )
return V_949 ;
F_450 ( V_2 , V_837 -> V_933 ) ;
F_451 ( V_2 , V_837 -> V_932 ) ;
F_30 ( V_67 , V_2 ) ;
return V_950 ;
}
int F_608 ( struct V_1 * V_2 ,
struct V_1198 * V_1199 )
{
struct V_32 V_1215 ;
int V_1216 = 0 ;
int V_1217 , V_1218 , V_486 ;
struct V_898 V_899 ;
if ( ! F_78 ( V_2 ) && ( V_1199 -> V_159 & V_142 ) )
return - V_580 ;
V_899 . V_492 = V_1199 -> V_1206 . V_910 ;
V_899 . V_80 = V_1199 -> V_1206 . V_230 ;
V_73 -> V_903 ( V_2 , & V_899 ) ;
V_899 . V_492 = V_1199 -> V_1207 . V_910 ;
V_899 . V_80 = V_1199 -> V_1207 . V_230 ;
V_73 -> V_902 ( V_2 , & V_899 ) ;
V_2 -> V_5 . V_79 = V_1199 -> V_79 ;
V_1216 |= F_58 ( V_2 ) != V_1199 -> V_104 ;
V_2 -> V_5 . V_104 = V_1199 -> V_104 ;
F_53 ( V_175 , ( V_176 * ) & V_2 -> V_5 . V_118 ) ;
F_87 ( V_2 , V_1199 -> V_177 ) ;
V_1216 |= V_2 -> V_5 . V_132 != V_1199 -> V_132 ;
V_73 -> F_107 ( V_2 , V_1199 -> V_132 ) ;
V_1215 . V_38 = V_1199 -> V_31 ;
V_1215 . V_40 = true ;
F_20 ( V_2 , & V_1215 ) ;
V_1216 |= F_60 ( V_2 ) != V_1199 -> V_122 ;
V_73 -> V_138 ( V_2 , V_1199 -> V_122 ) ;
V_2 -> V_5 . V_122 = V_1199 -> V_122 ;
V_1216 |= F_77 ( V_2 ) != V_1199 -> V_159 ;
V_73 -> V_171 ( V_2 , V_1199 -> V_159 ) ;
if ( V_1199 -> V_159 & ( V_142 | V_167 ) )
F_74 ( V_2 ) ;
V_486 = F_228 ( & V_2 -> V_139 -> V_487 ) ;
if ( ! F_55 ( V_2 ) && F_56 ( V_2 ) ) {
F_51 ( V_2 , V_2 -> V_5 . V_103 , F_58 ( V_2 ) ) ;
V_1216 = 1 ;
}
F_229 ( & V_2 -> V_139 -> V_487 , V_486 ) ;
if ( V_1216 )
F_64 ( V_2 ) ;
V_1218 = V_597 ;
V_1217 = F_609 (
( const unsigned long * ) V_1199 -> V_1208 , V_1218 ) ;
if ( V_1217 < V_1218 ) {
F_264 ( V_2 , V_1217 , false ) ;
F_130 ( L_28 , V_1217 ) ;
}
F_347 ( V_2 , & V_1199 -> V_1086 , V_1091 ) ;
F_347 ( V_2 , & V_1199 -> V_1087 , V_1092 ) ;
F_347 ( V_2 , & V_1199 -> V_1200 , V_1093 ) ;
F_347 ( V_2 , & V_1199 -> V_1201 , V_1094 ) ;
F_347 ( V_2 , & V_1199 -> V_1202 , V_1095 ) ;
F_347 ( V_2 , & V_1199 -> V_1203 , V_1096 ) ;
F_347 ( V_2 , & V_1199 -> V_1204 , V_1084 ) ;
F_347 ( V_2 , & V_1199 -> V_1205 , V_1085 ) ;
F_255 ( V_2 ) ;
if ( F_610 ( V_2 ) && F_446 ( V_2 ) == 0xfff0 &&
V_1199 -> V_1086 . V_904 == 0xf000 && V_1199 -> V_1086 . V_230 == 0xffff0000 &&
! F_31 ( V_2 ) )
V_2 -> V_5 . V_1041 = V_1155 ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
int F_611 ( struct V_1 * V_2 ,
struct V_1219 * V_1220 )
{
unsigned long V_969 ;
int V_3 , V_121 ;
if ( V_1220 -> V_755 & ( V_1221 | V_1222 ) ) {
V_121 = - V_803 ;
if ( V_2 -> V_5 . V_68 . V_69 )
goto V_113;
if ( V_1220 -> V_755 & V_1221 )
F_32 ( V_2 , V_53 ) ;
else
F_32 ( V_2 , V_54 ) ;
}
V_969 = F_445 ( V_2 ) ;
V_2 -> V_179 = V_1220 -> V_755 ;
if ( ! ( V_2 -> V_179 & V_1223 ) )
V_2 -> V_179 = 0 ;
if ( V_2 -> V_179 & V_180 ) {
for ( V_3 = 0 ; V_3 < V_181 ; ++ V_3 )
V_2 -> V_5 . V_182 [ V_3 ] = V_1220 -> V_5 . V_1224 [ V_3 ] ;
V_2 -> V_5 . V_189 = V_1220 -> V_5 . V_1224 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_181 ; V_3 ++ )
V_2 -> V_5 . V_182 [ V_3 ] = V_2 -> V_5 . V_183 [ V_3 ] ;
}
F_94 ( V_2 ) ;
if ( V_2 -> V_179 & V_972 )
V_2 -> V_5 . V_976 = F_446 ( V_2 ) +
F_395 ( V_2 , V_1091 ) ;
F_451 ( V_2 , V_969 ) ;
V_73 -> V_1225 ( V_2 ) ;
V_121 = 0 ;
V_113:
return V_121 ;
}
int F_612 ( struct V_1 * V_2 ,
struct V_1226 * V_1204 )
{
unsigned long V_1227 = V_1204 -> V_1228 ;
T_6 V_390 ;
int V_486 ;
V_486 = F_228 ( & V_2 -> V_139 -> V_487 ) ;
V_390 = F_353 ( V_2 , V_1227 , NULL ) ;
F_229 ( & V_2 -> V_139 -> V_487 , V_486 ) ;
V_1204 -> V_1229 = V_390 ;
V_1204 -> V_660 = V_390 != V_100 ;
V_1204 -> V_1230 = 1 ;
V_1204 -> V_1231 = 0 ;
return 0 ;
}
int F_613 ( struct V_1 * V_2 , struct V_1232 * V_1161 )
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
int F_614 ( struct V_1 * V_2 , struct V_1232 * V_1161 )
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
static void F_615 ( struct V_1 * V_2 )
{
F_616 ( & V_2 -> V_5 . V_655 . V_656 ) ;
if ( F_236 ( V_666 ) )
V_2 -> V_5 . V_655 . V_656 . V_654 . V_658 . V_667 =
V_146 | V_668 ;
V_2 -> V_5 . V_145 = V_151 ;
V_2 -> V_5 . V_122 |= V_127 ;
}
void F_433 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1248 )
return;
V_2 -> V_1248 = 1 ;
F_617 () ;
F_618 ( & V_2 -> V_5 . V_655 . V_656 ) ;
F_619 ( 1 ) ;
}
void F_250 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_1248 ) {
V_2 -> V_1249 = 0 ;
return;
}
V_2 -> V_1248 = 0 ;
F_620 ( & V_2 -> V_5 . V_655 ) ;
F_621 () ;
++ V_2 -> V_77 . V_1250 ;
if ( ! F_622 () ) {
if ( ++ V_2 -> V_1249 < 5 )
F_30 ( V_1111 , V_2 ) ;
}
F_619 ( 0 ) ;
}
void F_623 ( struct V_1 * V_2 )
{
F_205 ( V_2 ) ;
F_624 ( V_2 -> V_5 . V_584 ) ;
V_73 -> V_1251 ( V_2 ) ;
}
struct V_1 * F_625 ( struct V_139 * V_139 ,
unsigned int V_1252 )
{
struct V_1 * V_2 ;
if ( F_153 () && F_141 ( & V_139 -> V_294 ) != 0 )
F_389 ( V_877
L_29
L_30 ) ;
V_2 = V_73 -> V_1253 ( V_139 , V_1252 ) ;
return V_2 ;
}
int F_626 ( struct V_1 * V_2 )
{
int V_121 ;
F_627 ( V_2 ) ;
V_121 = V_585 ( V_2 ) ;
if ( V_121 )
return V_121 ;
F_628 ( V_2 , false ) ;
F_629 ( V_2 ) ;
V_590 ( V_2 ) ;
return V_121 ;
}
void F_630 ( struct V_1 * V_2 )
{
struct V_32 V_21 ;
struct V_139 * V_139 = V_2 -> V_139 ;
if ( V_585 ( V_2 ) )
return;
V_21 . V_38 = 0x0 ;
V_21 . V_147 = V_1254 ;
V_21 . V_40 = true ;
F_150 ( V_2 , & V_21 ) ;
V_590 ( V_2 ) ;
if ( ! V_365 )
return;
F_192 ( & V_139 -> V_5 . V_364 ,
V_366 ) ;
}
void F_631 ( struct V_1 * V_2 )
{
int V_121 ;
V_2 -> V_5 . V_6 . V_391 = 0 ;
V_121 = V_585 ( V_2 ) ;
F_13 ( V_121 ) ;
F_562 ( V_2 ) ;
V_590 ( V_2 ) ;
V_73 -> V_1251 ( V_2 ) ;
}
void F_628 ( struct V_1 * V_2 , bool V_1255 )
{
V_2 -> V_5 . V_636 = 0 ;
V_2 -> V_5 . V_634 = 0 ;
F_171 ( & V_2 -> V_5 . V_85 , 0 ) ;
V_2 -> V_5 . V_628 = 0 ;
V_2 -> V_5 . V_627 = false ;
F_632 ( V_2 ) ;
F_470 ( V_2 ) ;
memset ( V_2 -> V_5 . V_183 , 0 , sizeof( V_2 -> V_5 . V_183 ) ) ;
F_92 ( V_2 ) ;
V_2 -> V_5 . V_187 = V_1256 ;
F_93 ( V_2 ) ;
V_2 -> V_5 . V_188 = V_199 ;
F_94 ( V_2 ) ;
V_2 -> V_5 . V_79 = 0 ;
F_30 ( V_67 , V_2 ) ;
V_2 -> V_5 . V_6 . V_391 = 0 ;
V_2 -> V_5 . V_395 . V_391 = 0 ;
F_205 ( V_2 ) ;
F_63 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1115 = false ;
if ( ! V_1255 ) {
F_633 ( V_2 ) ;
V_2 -> V_5 . V_425 = 0x30000 ;
}
memset ( V_2 -> V_5 . V_1170 , 0 , sizeof( V_2 -> V_5 . V_1170 ) ) ;
V_2 -> V_5 . V_118 = ~ 0 ;
V_2 -> V_5 . V_119 = ~ 0 ;
V_73 -> V_1257 ( V_2 , V_1255 ) ;
}
void F_634 ( struct V_1 * V_2 , T_14 V_41 )
{
struct V_822 V_1086 ;
F_348 ( V_2 , & V_1086 , V_1091 ) ;
V_1086 . V_904 = V_41 << 8 ;
V_1086 . V_230 = V_41 << 12 ;
F_347 ( V_2 , & V_1086 , V_1091 ) ;
F_450 ( V_2 , 0 ) ;
}
int F_635 ( void )
{
struct V_139 * V_139 ;
struct V_1 * V_2 ;
int V_3 ;
int V_108 ;
T_2 V_1258 ;
T_2 V_1259 = 0 ;
bool V_1260 , V_1261 = false ;
F_14 () ;
V_108 = V_73 -> V_1262 () ;
if ( V_108 != 0 )
return V_108 ;
V_1258 = F_148 () ;
V_1260 = ! F_153 () ;
F_483 (kvm, &vm_list, vm_list) {
F_176 (i, vcpu, kvm) {
if ( ! V_1260 && V_2 -> V_23 == F_8 () )
F_30 ( V_339 , V_2 ) ;
if ( V_1260 && V_2 -> V_5 . V_588 > V_1258 ) {
V_1261 = true ;
if ( V_2 -> V_5 . V_588 > V_1259 )
V_1259 = V_2 -> V_5 . V_588 ;
}
}
}
if ( V_1261 ) {
T_2 V_1263 = V_1259 - V_1258 ;
V_335 = true ;
F_483 (kvm, &vm_list, vm_list) {
F_176 (i, vcpu, kvm) {
V_2 -> V_5 . V_586 += V_1263 ;
V_2 -> V_5 . V_588 = V_1258 ;
F_30 ( V_297 , V_2 ) ;
}
V_139 -> V_5 . V_313 = 0 ;
V_139 -> V_5 . V_315 = 0 ;
}
}
return 0 ;
}
void F_636 ( void )
{
V_73 -> V_1264 () ;
F_18 () ;
}
int F_637 ( void )
{
int V_121 ;
V_121 = V_73 -> V_1265 () ;
if ( V_121 != 0 )
return V_121 ;
if ( V_271 ) {
T_2 V_1266 = F_340 ( 0x7fffffffULL ,
F_144 ( V_276 , V_272 ) ) ;
V_713 = V_1266 ;
V_270 = 1ULL << V_275 ;
}
F_337 () ;
return 0 ;
}
void F_638 ( void )
{
V_73 -> V_1267 () ;
}
void F_639 ( void * V_1268 )
{
V_73 -> V_1269 ( V_1268 ) ;
}
bool F_640 ( struct V_1 * V_2 )
{
return V_2 -> V_139 -> V_5 . V_804 == V_2 -> V_298 ;
}
bool F_610 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_31 & V_1270 ) != 0 ;
}
int F_641 ( struct V_1 * V_2 )
{
struct V_386 * V_386 ;
struct V_139 * V_139 ;
int V_121 ;
F_13 ( V_2 -> V_139 == NULL ) ;
V_139 = V_2 -> V_139 ;
V_2 -> V_5 . V_593 = V_73 -> V_1271 () ;
V_2 -> V_5 . V_1153 . V_1154 = false ;
V_2 -> V_5 . V_930 . V_851 = & V_1272 ;
if ( ! F_263 ( V_139 ) || F_640 ( V_2 ) )
V_2 -> V_5 . V_1041 = V_1155 ;
else
V_2 -> V_5 . V_1041 = V_1167 ;
V_386 = F_642 ( V_686 | V_1273 ) ;
if ( ! V_386 ) {
V_121 = - V_388 ;
goto V_1274;
}
V_2 -> V_5 . V_883 = F_643 ( V_386 ) ;
F_137 ( V_2 , V_1011 ) ;
V_121 = F_644 ( V_2 ) ;
if ( V_121 < 0 )
goto V_1275;
if ( F_263 ( V_139 ) ) {
V_121 = F_645 ( V_2 ) ;
if ( V_121 < 0 )
goto V_1276;
} else
F_646 ( & V_1277 ) ;
V_2 -> V_5 . V_375 = F_293 ( V_439 * sizeof( T_2 ) * 4 ,
V_686 ) ;
if ( ! V_2 -> V_5 . V_375 ) {
V_121 = - V_388 ;
goto V_1278;
}
V_2 -> V_5 . V_367 = V_439 ;
if ( ! F_647 ( & V_2 -> V_5 . V_584 , V_686 ) ) {
V_121 = - V_388 ;
goto V_1279;
}
F_615 ( V_2 ) ;
V_2 -> V_5 . V_301 = 0x0 ;
V_2 -> V_5 . V_348 = false ;
V_2 -> V_5 . V_154 = 0 ;
V_2 -> V_5 . V_1280 = V_1281 + V_661 ;
V_2 -> V_5 . V_1022 = F_648 ( V_2 ) ;
V_2 -> V_5 . V_1282 = V_1283 ;
F_1 ( V_2 ) ;
F_649 ( V_2 ) ;
V_2 -> V_5 . V_599 = - 1 ;
F_650 ( V_2 ) ;
return 0 ;
V_1279:
F_201 ( V_2 -> V_5 . V_375 ) ;
V_1278:
F_651 ( V_2 ) ;
V_1276:
F_652 ( V_2 ) ;
V_1275:
F_653 ( ( unsigned long ) V_2 -> V_5 . V_883 ) ;
V_1274:
return V_121 ;
}
void F_654 ( struct V_1 * V_2 )
{
int V_486 ;
F_655 ( V_2 ) ;
F_656 ( V_2 ) ;
F_201 ( V_2 -> V_5 . V_375 ) ;
F_651 ( V_2 ) ;
V_486 = F_228 ( & V_2 -> V_139 -> V_487 ) ;
F_652 ( V_2 ) ;
F_229 ( & V_2 -> V_139 -> V_487 , V_486 ) ;
F_653 ( ( unsigned long ) V_2 -> V_5 . V_883 ) ;
if ( ! F_88 ( V_2 ) )
F_657 ( & V_1277 ) ;
}
void F_658 ( struct V_1 * V_2 , int V_23 )
{
V_73 -> V_1284 ( V_2 , V_23 ) ;
}
int F_659 ( struct V_139 * V_139 , unsigned long type )
{
if ( type )
return - V_580 ;
F_660 ( & V_139 -> V_5 . V_1285 ) ;
F_661 ( & V_139 -> V_5 . V_1286 ) ;
F_661 ( & V_139 -> V_5 . V_1287 ) ;
F_661 ( & V_139 -> V_5 . V_1288 ) ;
F_171 ( & V_139 -> V_5 . V_1289 , 0 ) ;
F_212 ( V_763 , & V_139 -> V_5 . V_1290 ) ;
F_212 ( V_1291 ,
& V_139 -> V_5 . V_1290 ) ;
F_662 ( & V_139 -> V_5 . V_312 ) ;
F_663 ( & V_139 -> V_5 . V_1292 ) ;
F_664 ( & V_139 -> V_5 . V_326 ) ;
F_170 ( V_139 ) ;
F_665 ( & V_139 -> V_5 . V_362 , F_188 ) ;
F_665 ( & V_139 -> V_5 . V_364 , F_193 ) ;
F_666 ( V_139 ) ;
F_667 ( V_139 ) ;
if ( V_73 -> V_1293 )
return V_73 -> V_1293 ( V_139 ) ;
return 0 ;
}
static void F_668 ( struct V_1 * V_2 )
{
int V_121 ;
V_121 = V_585 ( V_2 ) ;
F_13 ( V_121 ) ;
F_562 ( V_2 ) ;
V_590 ( V_2 ) ;
}
static void F_669 ( struct V_139 * V_139 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_176 (i, vcpu, kvm) {
F_63 ( V_2 ) ;
F_668 ( V_2 ) ;
}
F_176 (i, vcpu, kvm)
F_623 ( V_2 ) ;
F_302 ( & V_139 -> V_738 ) ;
for ( V_3 = 0 ; V_3 < F_141 ( & V_139 -> V_294 ) ; V_3 ++ )
V_139 -> V_1294 [ V_3 ] = NULL ;
F_171 ( & V_139 -> V_294 , 0 ) ;
F_304 ( & V_139 -> V_738 ) ;
}
void F_670 ( struct V_139 * V_139 )
{
F_671 ( & V_139 -> V_5 . V_364 ) ;
F_671 ( & V_139 -> V_5 . V_362 ) ;
F_672 ( V_139 ) ;
F_673 ( V_139 ) ;
}
int F_674 ( struct V_139 * V_139 , int V_1252 , T_6 V_390 , T_1 V_492 )
{
int V_3 , V_121 ;
unsigned long V_1295 ;
struct V_1296 * V_1297 = V_1296 ( V_139 ) ;
struct V_1298 * V_10 , V_870 ;
if ( F_28 ( V_1252 >= V_1299 ) )
return - V_580 ;
V_10 = F_675 ( V_1297 , V_1252 ) ;
if ( V_492 ) {
if ( V_10 -> V_1300 )
return - V_600 ;
V_1295 = F_676 ( NULL , 0 , V_492 , V_1301 | V_1302 ,
V_1303 | V_1304 , 0 ) ;
if ( F_198 ( ( void * ) V_1295 ) )
return F_199 ( ( void * ) V_1295 ) ;
} else {
if ( ! V_10 -> V_1300 )
return 0 ;
V_1295 = 0 ;
}
V_870 = * V_10 ;
for ( V_3 = 0 ; V_3 < V_1305 ; V_3 ++ ) {
struct V_1306 V_1307 ;
V_1307 . V_10 = V_1252 | ( V_3 << 16 ) ;
V_1307 . V_308 = 0 ;
V_1307 . V_1308 = V_390 ;
V_1307 . V_1309 = V_1295 ;
V_1307 . V_1310 = V_492 ;
V_121 = F_677 ( V_139 , & V_1307 ) ;
if ( V_121 < 0 )
return V_121 ;
}
if ( ! V_492 ) {
V_121 = F_678 ( V_870 . V_1309 , V_870 . V_1300 * V_107 ) ;
F_28 ( V_121 < 0 ) ;
}
return 0 ;
}
int F_679 ( struct V_139 * V_139 , int V_1252 , T_6 V_390 , T_1 V_492 )
{
int V_121 ;
F_302 ( & V_139 -> V_725 ) ;
V_121 = F_674 ( V_139 , V_1252 , V_390 , V_492 ) ;
F_304 ( & V_139 -> V_725 ) ;
return V_121 ;
}
void F_680 ( struct V_139 * V_139 )
{
if ( V_400 -> V_1311 == V_139 -> V_1311 ) {
F_679 ( V_139 , V_1312 , 0 , 0 ) ;
F_679 ( V_139 , V_1313 , 0 , 0 ) ;
F_679 ( V_139 , V_1314 , 0 , 0 ) ;
}
if ( V_73 -> V_1315 )
V_73 -> V_1315 ( V_139 ) ;
F_681 ( V_139 ) ;
F_201 ( V_139 -> V_5 . V_785 ) ;
F_201 ( V_139 -> V_5 . V_1316 ) ;
F_669 ( V_139 ) ;
F_682 ( F_683 ( V_139 -> V_5 . V_1317 , 1 ) ) ;
F_684 ( V_139 ) ;
}
void F_685 ( struct V_139 * V_139 , struct V_1298 * free ,
struct V_1298 * V_1318 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1319 ; ++ V_3 ) {
if ( ! V_1318 || free -> V_5 . V_1320 [ V_3 ] != V_1318 -> V_5 . V_1320 [ V_3 ] ) {
F_682 ( free -> V_5 . V_1320 [ V_3 ] ) ;
free -> V_5 . V_1320 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1318 || free -> V_5 . V_1321 [ V_3 - 1 ] !=
V_1318 -> V_5 . V_1321 [ V_3 - 1 ] ) {
F_682 ( free -> V_5 . V_1321 [ V_3 - 1 ] ) ;
free -> V_5 . V_1321 [ V_3 - 1 ] = NULL ;
}
}
F_686 ( free , V_1318 ) ;
}
int F_687 ( struct V_139 * V_139 , struct V_1298 * V_10 ,
unsigned long V_1300 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1319 ; ++ V_3 ) {
struct V_1322 * V_1323 ;
unsigned long V_1324 ;
int V_1325 ;
int V_764 = V_3 + 1 ;
V_1325 = F_688 ( V_10 -> V_1326 + V_1300 - 1 ,
V_10 -> V_1326 , V_764 ) + 1 ;
V_10 -> V_5 . V_1320 [ V_3 ] =
F_689 ( V_1325 * sizeof( * V_10 -> V_5 . V_1320 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1320 [ V_3 ] )
goto V_389;
if ( V_3 == 0 )
continue;
V_1323 = F_689 ( V_1325 * sizeof( * V_1323 ) ) ;
if ( ! V_1323 )
goto V_389;
V_10 -> V_5 . V_1321 [ V_3 - 1 ] = V_1323 ;
if ( V_10 -> V_1326 & ( F_690 ( V_764 ) - 1 ) )
V_1323 [ 0 ] . V_1327 = 1 ;
if ( ( V_10 -> V_1326 + V_1300 ) & ( F_690 ( V_764 ) - 1 ) )
V_1323 [ V_1325 - 1 ] . V_1327 = 1 ;
V_1324 = V_10 -> V_1309 >> V_106 ;
if ( ( V_10 -> V_1326 ^ V_1324 ) & ( F_690 ( V_764 ) - 1 ) ||
! F_691 () ) {
unsigned long V_813 ;
for ( V_813 = 0 ; V_813 < V_1325 ; ++ V_813 )
V_1323 [ V_813 ] . V_1327 = 1 ;
}
}
if ( F_692 ( V_10 , V_1300 ) )
goto V_389;
return 0 ;
V_389:
for ( V_3 = 0 ; V_3 < V_1319 ; ++ V_3 ) {
F_682 ( V_10 -> V_5 . V_1320 [ V_3 ] ) ;
V_10 -> V_5 . V_1320 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_682 ( V_10 -> V_5 . V_1321 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1321 [ V_3 - 1 ] = NULL ;
}
return - V_388 ;
}
void F_693 ( struct V_139 * V_139 , struct V_1296 * V_1297 )
{
F_694 ( V_139 , V_1297 ) ;
}
int F_695 ( struct V_139 * V_139 ,
struct V_1298 * V_1328 ,
const struct V_1306 * V_1329 ,
enum V_1330 V_1331 )
{
return 0 ;
}
static void F_696 ( struct V_139 * V_139 ,
struct V_1298 * V_871 )
{
if ( V_871 -> V_308 & V_1332 ) {
F_697 ( V_139 , V_871 ) ;
return;
}
if ( V_871 -> V_308 & V_1333 ) {
if ( V_73 -> V_1334 )
V_73 -> V_1334 ( V_139 , V_871 ) ;
else
F_697 ( V_139 , V_871 ) ;
} else {
if ( V_73 -> V_1335 )
V_73 -> V_1335 ( V_139 , V_871 ) ;
}
}
void F_698 ( struct V_139 * V_139 ,
const struct V_1306 * V_1329 ,
const struct V_1298 * V_870 ,
const struct V_1298 * V_871 ,
enum V_1330 V_1331 )
{
int V_1336 = 0 ;
if ( ! V_139 -> V_5 . V_726 )
V_1336 = F_699 ( V_139 ) ;
if ( V_1336 )
F_303 ( V_139 , V_1336 ) ;
if ( ( V_1331 != V_1337 ) &&
( V_870 -> V_308 & V_1333 ) &&
! ( V_871 -> V_308 & V_1333 ) )
F_700 ( V_139 , V_871 ) ;
if ( V_1331 != V_1337 )
F_696 ( V_139 , (struct V_1298 * ) V_871 ) ;
}
void F_701 ( struct V_139 * V_139 )
{
F_702 ( V_139 ) ;
}
void F_703 ( struct V_139 * V_139 ,
struct V_1298 * V_10 )
{
F_702 ( V_139 ) ;
}
static inline bool F_704 ( struct V_1 * V_2 )
{
if ( ! F_705 ( & V_2 -> V_1338 . V_1339 ) )
return true ;
if ( F_706 ( V_2 ) )
return true ;
if ( V_2 -> V_5 . V_1153 . V_1154 )
return true ;
if ( F_141 ( & V_2 -> V_5 . V_85 ) )
return true ;
if ( F_57 ( V_601 , & V_2 -> V_340 ) )
return true ;
if ( F_259 ( V_2 ) &&
F_260 ( V_2 ) )
return true ;
if ( F_707 ( V_2 ) )
return true ;
return false ;
}
int F_585 ( struct V_1 * V_2 )
{
if ( F_454 ( V_2 ) && V_73 -> V_1080 )
V_73 -> V_1080 ( V_2 , false ) ;
return F_587 ( V_2 ) || F_704 ( V_2 ) ;
}
int F_708 ( struct V_1 * V_2 )
{
return F_709 ( V_2 ) == V_1138 ;
}
int F_259 ( struct V_1 * V_2 )
{
return V_73 -> V_1082 ( V_2 ) ;
}
unsigned long F_468 ( struct V_1 * V_2 )
{
if ( F_525 ( V_2 ) )
return F_446 ( V_2 ) ;
return ( T_1 ) ( F_395 ( V_2 , V_1091 ) +
F_446 ( V_2 ) ) ;
}
bool F_710 ( struct V_1 * V_2 , unsigned long V_1340 )
{
return F_468 ( V_2 ) == V_1340 ;
}
unsigned long F_445 ( struct V_1 * V_2 )
{
unsigned long V_969 ;
V_969 = V_73 -> V_999 ( V_2 ) ;
if ( V_2 -> V_179 & V_972 )
V_969 &= ~ V_971 ;
return V_969 ;
}
static void F_475 ( struct V_1 * V_2 , unsigned long V_969 )
{
if ( V_2 -> V_179 & V_972 &&
F_710 ( V_2 , V_2 -> V_5 . V_976 ) )
V_969 |= V_971 ;
V_73 -> V_1341 ( V_2 , V_969 ) ;
}
void F_451 ( struct V_1 * V_2 , unsigned long V_969 )
{
F_475 ( V_2 , V_969 ) ;
F_30 ( V_67 , V_2 ) ;
}
void F_711 ( struct V_1 * V_2 , struct V_1342 * V_359 )
{
int V_121 ;
if ( ( V_2 -> V_5 . V_84 . V_961 != V_359 -> V_5 . V_961 ) ||
V_359 -> V_1343 )
return;
V_121 = F_570 ( V_2 ) ;
if ( F_167 ( V_121 ) )
return;
if ( ! V_2 -> V_5 . V_84 . V_961 &&
V_359 -> V_5 . V_104 != V_2 -> V_5 . V_84 . V_1344 ( V_2 ) )
return;
V_2 -> V_5 . V_84 . V_1345 ( V_2 , V_359 -> V_829 , 0 , true ) ;
}
static inline T_1 F_712 ( T_5 V_102 )
{
return F_713 ( V_102 & 0xffffffff , F_714 ( V_4 ) ) ;
}
static inline T_1 F_715 ( T_1 V_1346 )
{
return ( V_1346 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_716 ( struct V_1 * V_2 , T_5 V_102 )
{
T_1 V_1346 = F_712 ( V_102 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1346 ] != ~ 0 )
V_1346 = F_715 ( V_1346 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1346 ] = V_102 ;
}
static T_1 F_717 ( struct V_1 * V_2 , T_5 V_102 )
{
int V_3 ;
T_1 V_1346 = F_712 ( V_102 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1346 ] != V_102 &&
V_2 -> V_5 . V_6 . V_7 [ V_1346 ] != ~ 0 ) ; V_3 ++ )
V_1346 = F_715 ( V_1346 ) ;
return V_1346 ;
}
bool F_718 ( struct V_1 * V_2 , T_5 V_102 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_717 ( V_2 , V_102 ) ] == V_102 ;
}
static void F_719 ( struct V_1 * V_2 , T_5 V_102 )
{
T_1 V_3 , V_813 , V_1347 ;
V_3 = V_813 = F_717 ( V_2 , V_102 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_813 = F_715 ( V_813 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_813 ] == ~ 0 )
return;
V_1347 = F_712 ( V_2 -> V_5 . V_6 . V_7 [ V_813 ] ) ;
} while ( ( V_3 <= V_813 ) ? ( V_3 < V_1347 && V_1347 <= V_813 ) : ( V_3 < V_1347 || V_1347 <= V_813 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_813 ] ;
V_3 = V_813 ;
}
}
static int F_720 ( struct V_1 * V_2 , T_1 V_196 )
{
return F_185 ( V_2 -> V_139 , & V_2 -> V_5 . V_6 . V_38 , & V_196 ,
sizeof( V_196 ) ) ;
}
void F_721 ( struct V_1 * V_2 ,
struct V_1342 * V_359 )
{
struct V_75 V_76 ;
F_722 ( V_359 -> V_5 . V_1348 , V_359 -> V_829 ) ;
F_716 ( V_2 , V_359 -> V_5 . V_102 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_391 & V_392 ) ||
( V_2 -> V_5 . V_6 . V_393 &&
V_73 -> V_88 ( V_2 ) == 0 ) )
F_30 ( V_1114 , V_2 ) ;
else if ( ! F_720 ( V_2 , V_1349 ) ) {
V_76 . V_41 = V_42 ;
V_76 . V_931 = true ;
V_76 . V_62 = 0 ;
V_76 . V_81 = false ;
V_76 . V_80 = V_359 -> V_5 . V_1348 ;
F_36 ( V_2 , & V_76 ) ;
}
}
void F_723 ( struct V_1 * V_2 ,
struct V_1342 * V_359 )
{
struct V_75 V_76 ;
F_724 ( V_359 -> V_5 . V_1348 , V_359 -> V_829 ) ;
if ( V_359 -> V_1343 )
V_359 -> V_5 . V_1348 = ~ 0 ;
else
F_719 ( V_2 , V_359 -> V_5 . V_102 ) ;
if ( ( V_2 -> V_5 . V_6 . V_391 & V_392 ) &&
! F_720 ( V_2 , V_1350 ) ) {
V_76 . V_41 = V_42 ;
V_76 . V_931 = true ;
V_76 . V_62 = 0 ;
V_76 . V_81 = false ;
V_76 . V_80 = V_359 -> V_5 . V_1348 ;
F_36 ( V_2 , & V_76 ) ;
}
V_2 -> V_5 . V_6 . V_1115 = false ;
V_2 -> V_5 . V_1041 = V_1155 ;
}
bool F_725 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_391 & V_392 ) )
return true ;
else
return ! F_261 ( V_2 ) &&
V_73 -> V_1082 ( V_2 ) ;
}
void F_726 ( struct V_139 * V_139 )
{
F_41 ( & V_139 -> V_5 . V_1351 ) ;
}
void F_727 ( struct V_139 * V_139 )
{
F_728 ( & V_139 -> V_5 . V_1351 ) ;
}
bool F_729 ( struct V_139 * V_139 )
{
return F_141 ( & V_139 -> V_5 . V_1351 ) ;
}
void F_730 ( struct V_139 * V_139 )
{
F_41 ( & V_139 -> V_5 . V_1289 ) ;
}
void F_731 ( struct V_139 * V_139 )
{
F_728 ( & V_139 -> V_5 . V_1289 ) ;
}
bool F_65 ( struct V_139 * V_139 )
{
return F_141 ( & V_139 -> V_5 . V_1289 ) ;
}
bool F_732 ( void )
{
return V_73 -> V_1352 != NULL ;
}
int F_733 ( struct V_1353 * V_1354 ,
struct V_1355 * V_1356 )
{
struct V_1357 * V_1358 =
F_4 ( V_1354 , struct V_1357 , V_1359 ) ;
V_1358 -> V_1360 = V_1356 ;
return V_73 -> V_1352 ( V_1358 -> V_139 ,
V_1356 -> V_596 , V_1358 -> V_1361 , 1 ) ;
}
void F_734 ( struct V_1353 * V_1354 ,
struct V_1355 * V_1356 )
{
int V_108 ;
struct V_1357 * V_1358 =
F_4 ( V_1354 , struct V_1357 , V_1359 ) ;
F_28 ( V_1358 -> V_1360 != V_1356 ) ;
V_1358 -> V_1360 = NULL ;
V_108 = V_73 -> V_1352 ( V_1358 -> V_139 , V_1356 -> V_596 , V_1358 -> V_1361 , 0 ) ;
if ( V_108 )
F_10 ( V_1362 L_31
L_32 , V_1358 -> V_1359 . V_1348 , V_108 ) ;
}
int F_735 ( struct V_139 * V_139 , unsigned int V_1363 ,
T_7 V_1364 , bool V_1365 )
{
if ( ! V_73 -> V_1352 )
return - V_580 ;
return V_73 -> V_1352 ( V_139 , V_1363 , V_1364 , V_1365 ) ;
}
bool F_736 ( void )
{
return V_1366 ;
}
