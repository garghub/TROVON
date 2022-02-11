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
if ( ( V_121 ^ V_122 ) & V_129 )
F_66 ( V_2 -> V_138 , 0 , ~ 0ULL ) ;
return 0 ;
}
void F_67 ( struct V_1 * V_2 , unsigned long V_139 )
{
( void ) F_60 ( V_2 , F_68 ( V_2 , ~ 0x0eul ) | ( V_139 & 0x0f ) ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
if ( F_45 ( V_2 , V_140 ) &&
! V_2 -> V_141 ) {
F_70 ( V_142 , V_2 -> V_5 . V_143 ) ;
V_2 -> V_141 = 1 ;
}
}
static void F_71 ( struct V_1 * V_2 )
{
if ( V_2 -> V_141 ) {
if ( V_2 -> V_5 . V_143 != V_144 )
F_70 ( V_142 , V_144 ) ;
V_2 -> V_141 = 0 ;
}
}
static int F_72 ( struct V_1 * V_2 , T_1 V_145 , T_2 V_146 )
{
T_2 V_143 = V_146 ;
T_2 V_147 = V_2 -> V_5 . V_143 ;
T_2 V_148 ;
if ( V_145 != V_142 )
return 1 ;
if ( ! ( V_143 & V_149 ) )
return 1 ;
if ( ( V_143 & V_150 ) && ! ( V_143 & V_151 ) )
return 1 ;
V_148 = V_2 -> V_5 . V_152 | V_149 ;
if ( V_143 & ~ V_148 )
return 1 ;
if ( ( ! ( V_143 & V_153 ) ) != ( ! ( V_143 & V_154 ) ) )
return 1 ;
if ( V_143 & V_155 ) {
if ( ! ( V_143 & V_150 ) )
return 1 ;
if ( ( V_143 & V_155 ) != V_155 )
return 1 ;
}
F_71 ( V_2 ) ;
V_2 -> V_5 . V_143 = V_143 ;
if ( ( V_143 ^ V_147 ) & V_156 )
F_73 ( V_2 ) ;
return 0 ;
}
int F_74 ( struct V_1 * V_2 , T_1 V_145 , T_2 V_146 )
{
if ( V_73 -> V_88 ( V_2 ) != 0 ||
F_72 ( V_2 , V_145 , V_146 ) ) {
F_35 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_75 ( struct V_1 * V_2 , unsigned long V_157 )
{
unsigned long V_158 = F_76 ( V_2 ) ;
unsigned long V_159 = V_160 | V_161 | V_162 |
V_163 | V_164 ;
if ( V_157 & V_165 )
return 1 ;
if ( ! F_77 ( V_2 ) && ( V_157 & V_140 ) )
return 1 ;
if ( ! F_78 ( V_2 ) && ( V_157 & V_163 ) )
return 1 ;
if ( ! F_79 ( V_2 ) && ( V_157 & V_164 ) )
return 1 ;
if ( ! F_80 ( V_2 ) && ( V_157 & V_166 ) )
return 1 ;
if ( F_56 ( V_2 ) ) {
if ( ! ( V_157 & V_162 ) )
return 1 ;
} else if ( F_63 ( V_2 ) && ( V_157 & V_162 )
&& ( ( V_157 ^ V_158 ) & V_159 )
&& ! F_51 ( V_2 , V_2 -> V_5 . V_103 ,
F_59 ( V_2 ) ) )
return 1 ;
if ( ( V_157 & V_136 ) && ! ( V_158 & V_136 ) ) {
if ( ! F_81 ( V_2 ) )
return 1 ;
if ( ( F_59 ( V_2 ) & V_167 ) || ! F_56 ( V_2 ) )
return 1 ;
}
if ( V_73 -> V_168 ( V_2 , V_157 ) )
return 1 ;
if ( ( ( V_157 ^ V_158 ) & V_159 ) ||
( ! ( V_157 & V_136 ) && ( V_158 & V_136 ) ) )
F_65 ( V_2 ) ;
if ( ( V_157 ^ V_158 ) & V_140 )
F_73 ( V_2 ) ;
return 0 ;
}
int F_82 ( struct V_1 * V_2 , unsigned long V_104 )
{
#ifdef F_62
V_104 &= ~ V_169 ;
#endif
if ( V_104 == F_59 ( V_2 ) && ! F_55 ( V_2 ) ) {
F_83 ( V_2 ) ;
F_30 ( V_170 , V_2 ) ;
return 0 ;
}
if ( F_56 ( V_2 ) ) {
if ( V_104 & V_171 )
return 1 ;
} else if ( F_57 ( V_2 ) && F_63 ( V_2 ) &&
! F_51 ( V_2 , V_2 -> V_5 . V_103 , V_104 ) )
return 1 ;
V_2 -> V_5 . V_104 = V_104 ;
F_54 ( V_172 , ( V_173 * ) & V_2 -> V_5 . V_117 ) ;
F_84 ( V_2 ) ;
return 0 ;
}
int F_85 ( struct V_1 * V_2 , unsigned long V_174 )
{
if ( V_174 & V_175 )
return 1 ;
if ( F_86 ( V_2 -> V_138 ) )
F_87 ( V_2 , V_174 ) ;
else
V_2 -> V_5 . V_174 = V_174 ;
return 0 ;
}
unsigned long F_88 ( struct V_1 * V_2 )
{
if ( F_86 ( V_2 -> V_138 ) )
return F_89 ( V_2 ) ;
else
return V_2 -> V_5 . V_174 ;
}
static void F_90 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! ( V_2 -> V_176 & V_177 ) ) {
for ( V_3 = 0 ; V_3 < V_178 ; V_3 ++ )
V_2 -> V_5 . V_179 [ V_3 ] = V_2 -> V_5 . V_180 [ V_3 ] ;
V_2 -> V_5 . V_181 |= V_182 ;
}
}
static void F_91 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_176 & V_177 ) )
V_73 -> V_183 ( V_2 , V_2 -> V_5 . V_184 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
unsigned long V_185 ;
if ( V_2 -> V_176 & V_177 )
V_185 = V_2 -> V_5 . V_186 ;
else
V_185 = V_2 -> V_5 . V_185 ;
V_73 -> V_187 ( V_2 , V_185 ) ;
V_2 -> V_5 . V_181 &= ~ V_188 ;
if ( V_185 & V_189 )
V_2 -> V_5 . V_181 |= V_188 ;
}
static T_2 F_93 ( struct V_1 * V_2 )
{
T_2 V_190 = V_191 ;
if ( ! F_94 ( V_2 ) )
V_190 |= V_192 ;
return V_190 ;
}
static int F_95 ( struct V_1 * V_2 , int V_89 , unsigned long V_193 )
{
switch ( V_89 ) {
case 0 ... 3 :
V_2 -> V_5 . V_180 [ V_89 ] = V_193 ;
if ( ! ( V_2 -> V_176 & V_177 ) )
V_2 -> V_5 . V_179 [ V_89 ] = V_193 ;
break;
case 4 :
case 6 :
if ( V_193 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_184 = ( V_193 & V_194 ) | F_93 ( V_2 ) ;
F_91 ( V_2 ) ;
break;
case 5 :
default:
if ( V_193 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_185 = ( V_193 & V_195 ) | V_196 ;
F_92 ( V_2 ) ;
break;
}
return 0 ;
}
int F_96 ( struct V_1 * V_2 , int V_89 , unsigned long V_193 )
{
if ( F_95 ( V_2 , V_89 , V_193 ) ) {
F_35 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_97 ( struct V_1 * V_2 , int V_89 , unsigned long * V_193 )
{
switch ( V_89 ) {
case 0 ... 3 :
* V_193 = V_2 -> V_5 . V_180 [ V_89 ] ;
break;
case 4 :
case 6 :
if ( V_2 -> V_176 & V_177 )
* V_193 = V_2 -> V_5 . V_184 ;
else
* V_193 = V_73 -> V_197 ( V_2 ) ;
break;
case 5 :
default:
* V_193 = V_2 -> V_5 . V_185 ;
break;
}
return 0 ;
}
bool F_98 ( struct V_1 * V_2 )
{
T_1 V_198 = F_99 ( V_2 , V_199 ) ;
T_2 V_38 ;
int V_29 ;
V_29 = F_100 ( V_2 , V_198 , & V_38 ) ;
if ( V_29 )
return V_29 ;
F_101 ( V_2 , V_200 , ( T_1 ) V_38 ) ;
F_101 ( V_2 , V_201 , V_38 >> 32 ) ;
return V_29 ;
}
bool F_102 ( struct V_1 * V_2 , T_2 V_131 )
{
if ( V_131 & V_202 )
return false ;
if ( V_131 & V_203 ) {
struct V_204 * V_205 ;
V_205 = F_103 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_205 || ! ( V_205 -> V_206 & F_104 ( V_207 ) ) )
return false ;
}
if ( V_131 & V_208 ) {
struct V_204 * V_205 ;
V_205 = F_103 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_205 || ! ( V_205 -> V_198 & F_104 ( V_209 ) ) )
return false ;
}
return true ;
}
static int F_105 ( struct V_1 * V_2 , T_2 V_131 )
{
T_2 V_210 = V_2 -> V_5 . V_131 ;
if ( ! F_102 ( V_2 , V_131 ) )
return 1 ;
if ( F_63 ( V_2 )
&& ( V_2 -> V_5 . V_131 & V_132 ) != ( V_131 & V_132 ) )
return 1 ;
V_131 &= ~ V_211 ;
V_131 |= V_2 -> V_5 . V_131 & V_211 ;
V_73 -> F_105 ( V_2 , V_131 ) ;
if ( ( V_131 ^ V_210 ) & V_212 )
F_65 ( V_2 ) ;
return 0 ;
}
void F_106 ( T_2 V_28 )
{
V_202 &= ~ V_28 ;
}
int F_107 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
switch ( V_21 -> V_145 ) {
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 :
if ( F_108 ( V_21 -> V_38 ) )
return 1 ;
break;
case V_218 :
case V_219 :
V_21 -> V_38 = F_109 ( V_21 -> V_38 ) ;
}
return V_73 -> V_220 ( V_2 , V_21 ) ;
}
static int F_110 ( struct V_1 * V_2 , unsigned V_145 , T_2 * V_38 )
{
struct V_32 V_21 ;
int V_120 ;
V_21 . V_145 = V_145 ;
V_21 . V_40 = true ;
V_120 = F_111 ( V_2 , & V_21 ) ;
if ( V_120 )
return V_120 ;
* V_38 = V_21 . V_38 ;
return 0 ;
}
static int F_112 ( struct V_1 * V_2 , unsigned V_145 , T_2 * V_38 )
{
struct V_32 V_21 ;
V_21 . V_38 = * V_38 ;
V_21 . V_145 = V_145 ;
V_21 . V_40 = true ;
return F_107 ( V_2 , & V_21 ) ;
}
static void F_113 ( struct V_221 * V_222 )
{
struct V_223 * V_224 = & V_223 ;
T_2 V_225 ;
V_225 = F_114 ( F_115 ( V_222 -> V_226 . V_227 , V_222 -> V_228 ) ) ;
F_116 ( & V_224 -> V_229 ) ;
V_224 -> clock . V_230 = V_222 -> V_226 . clock -> V_231 . V_230 ;
V_224 -> clock . V_232 = V_222 -> V_226 . V_232 ;
V_224 -> clock . V_28 = V_222 -> V_226 . V_28 ;
V_224 -> clock . V_233 = V_222 -> V_226 . V_233 ;
V_224 -> clock . V_234 = V_222 -> V_226 . V_234 ;
V_224 -> V_225 = V_225 ;
V_224 -> V_235 = V_222 -> V_226 . V_236 ;
F_117 ( & V_224 -> V_229 ) ;
}
void F_118 ( struct V_1 * V_2 )
{
F_30 ( V_237 , V_2 ) ;
}
static void F_119 ( struct V_138 * V_138 , T_6 V_238 )
{
int V_239 ;
int V_120 ;
struct V_240 V_241 ;
struct V_242 V_243 ;
if ( ! V_238 )
return;
V_120 = F_120 ( V_138 , V_238 , & V_239 , sizeof( V_239 ) ) ;
if ( V_120 )
return;
if ( V_239 & 1 )
++ V_239 ;
++ V_239 ;
F_121 ( V_138 , V_238 , & V_239 , sizeof( V_239 ) ) ;
F_122 ( & V_243 ) ;
if ( V_138 -> V_5 . V_244 ) {
struct V_242 V_245 = F_123 ( V_138 -> V_5 . V_244 ) ;
V_243 = F_124 ( V_243 , V_245 ) ;
}
V_241 . V_246 = V_243 . V_247 ;
V_241 . V_248 = V_243 . V_249 ;
V_241 . V_239 = V_239 ;
F_121 ( V_138 , V_238 , & V_241 , sizeof( V_241 ) ) ;
V_239 ++ ;
F_121 ( V_138 , V_238 , & V_239 , sizeof( V_239 ) ) ;
}
static T_7 F_125 ( T_7 V_250 , T_7 V_251 )
{
T_7 V_252 , V_253 ;
__asm__ ( "divl %4"
: "=a" (quotient), "=d" (remainder)
: "0" (0), "1" (dividend), "r" (divisor) );
return V_252 ;
}
static void F_126 ( T_7 V_254 , T_7 V_255 ,
T_8 * V_256 , T_1 * V_257 )
{
T_9 V_258 ;
T_10 V_234 = 0 ;
T_9 V_259 ;
T_7 V_260 ;
V_259 = V_255 * 1000LL ;
V_258 = V_254 * 1000LL ;
while ( V_259 > V_258 * 2 || V_259 & 0xffffffff00000000ULL ) {
V_259 >>= 1 ;
V_234 -- ;
}
V_260 = ( T_7 ) V_259 ;
while ( V_260 <= V_258 || V_258 & 0xffffffff00000000ULL ) {
if ( V_258 & 0xffffffff00000000ULL || V_260 & 0x80000000 )
V_258 >>= 1 ;
else
V_260 <<= 1 ;
V_234 ++ ;
}
* V_256 = V_234 ;
* V_257 = F_125 ( V_258 , V_260 ) ;
F_127 ( L_2 ,
V_261 , V_255 , V_254 , V_234 , * V_257 ) ;
}
static inline T_2 F_128 ( struct V_1 * V_2 , T_2 V_248 )
{
return F_129 ( V_248 , V_2 -> V_5 . V_262 ,
V_2 -> V_5 . V_263 ) ;
}
static T_1 F_130 ( T_1 V_264 , T_11 V_265 )
{
T_2 V_266 = ( T_2 ) V_264 * ( 1000000 + V_265 ) ;
F_131 ( V_266 , 1000000 ) ;
return V_266 ;
}
static void F_132 ( struct V_1 * V_2 , T_1 V_267 )
{
T_1 V_268 , V_269 ;
int V_270 = 0 ;
if ( V_267 == 0 )
return;
F_126 ( V_267 , V_271 / 1000 ,
& V_2 -> V_5 . V_263 ,
& V_2 -> V_5 . V_262 ) ;
V_2 -> V_5 . V_272 = V_267 ;
V_268 = F_130 ( V_273 , - V_274 ) ;
V_269 = F_130 ( V_273 , V_274 ) ;
if ( V_267 < V_268 || V_267 > V_269 ) {
F_127 ( L_3 , V_267 , V_268 , V_269 ) ;
V_270 = 1 ;
}
V_73 -> V_275 ( V_2 , V_267 , V_270 ) ;
}
static T_2 F_133 ( struct V_1 * V_2 , T_12 V_276 )
{
T_2 V_277 = F_129 ( V_276 - V_2 -> V_5 . V_278 ,
V_2 -> V_5 . V_262 ,
V_2 -> V_5 . V_263 ) ;
V_277 += V_2 -> V_5 . V_279 ;
return V_277 ;
}
static void F_134 ( struct V_1 * V_2 )
{
#ifdef F_62
bool V_280 ;
struct V_281 * V_282 = & V_2 -> V_138 -> V_5 ;
struct V_223 * V_283 = & V_223 ;
V_280 = ( V_282 -> V_284 + 1 ==
F_135 ( & V_2 -> V_138 -> V_285 ) ) ;
if ( V_282 -> V_286 ||
( V_283 -> clock . V_230 == V_287 && V_280 ) )
F_30 ( V_288 , V_2 ) ;
F_136 ( V_2 -> V_289 , V_282 -> V_284 ,
F_135 ( & V_2 -> V_138 -> V_285 ) ,
V_282 -> V_286 , V_283 -> clock . V_230 ) ;
#endif
}
static void F_137 ( struct V_1 * V_2 , T_12 V_94 )
{
T_2 V_290 = V_73 -> V_291 ( V_2 ) ;
V_2 -> V_5 . V_292 += V_94 - V_290 ;
}
void F_138 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
struct V_138 * V_138 = V_2 -> V_138 ;
T_2 V_94 , V_293 , V_294 ;
unsigned long V_295 ;
T_12 V_296 ;
bool V_297 ;
bool V_298 ;
T_2 V_38 = V_21 -> V_38 ;
F_139 ( & V_138 -> V_5 . V_299 , V_295 ) ;
V_94 = V_73 -> V_300 ( V_2 , V_38 ) ;
V_293 = F_140 () ;
V_294 = V_293 - V_138 -> V_5 . V_301 ;
if ( V_2 -> V_5 . V_272 ) {
int V_302 = 0 ;
V_296 = V_38 - V_138 -> V_5 . V_303 ;
#ifdef F_62
V_296 = ( V_296 * 1000 ) / V_2 -> V_5 . V_272 ;
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
F_131 ( V_294 , 1000 ) ;
V_296 -= V_294 ;
if ( V_296 < 0 )
V_296 = - V_296 ;
if ( V_302 )
V_296 = V_304 ;
} else
V_296 = V_304 ;
if ( V_296 < V_304 &&
V_2 -> V_5 . V_272 == V_138 -> V_5 . V_305 ) {
if ( ! F_141 () ) {
V_94 = V_138 -> V_5 . V_306 ;
F_127 ( L_4 , V_38 ) ;
} else {
T_2 V_307 = F_128 ( V_2 , V_294 ) ;
V_38 += V_307 ;
V_94 = V_73 -> V_300 ( V_2 , V_38 ) ;
F_127 ( L_5 , V_307 ) ;
}
V_297 = true ;
V_298 = ( V_2 -> V_5 . V_308 == V_138 -> V_5 . V_309 ) ;
} else {
V_138 -> V_5 . V_309 ++ ;
V_138 -> V_5 . V_310 = V_293 ;
V_138 -> V_5 . V_311 = V_38 ;
V_138 -> V_5 . V_306 = V_94 ;
V_297 = false ;
F_127 ( L_6 ,
V_138 -> V_5 . V_309 , V_38 ) ;
}
V_138 -> V_5 . V_301 = V_293 ;
V_138 -> V_5 . V_303 = V_38 ;
V_138 -> V_5 . V_305 = V_2 -> V_5 . V_272 ;
V_2 -> V_5 . V_312 = V_38 ;
V_2 -> V_5 . V_308 = V_138 -> V_5 . V_309 ;
V_2 -> V_5 . V_278 = V_138 -> V_5 . V_310 ;
V_2 -> V_5 . V_279 = V_138 -> V_5 . V_311 ;
if ( F_142 ( V_2 ) && ! V_21 -> V_40 )
F_137 ( V_2 , V_94 ) ;
V_73 -> V_313 ( V_2 , V_94 ) ;
F_143 ( & V_138 -> V_5 . V_299 , V_295 ) ;
F_144 ( & V_138 -> V_5 . V_314 ) ;
if ( ! V_297 ) {
V_138 -> V_5 . V_284 = 0 ;
} else if ( ! V_298 ) {
V_138 -> V_5 . V_284 ++ ;
}
F_134 ( V_2 ) ;
F_145 ( & V_138 -> V_5 . V_314 ) ;
}
static T_13 F_146 ( void )
{
T_13 V_108 = ( T_13 ) F_147 () ;
T_2 V_315 = V_223 . clock . V_232 ;
if ( F_148 ( V_108 >= V_315 ) )
return V_108 ;
asm volatile ("");
return V_315 ;
}
static inline T_2 F_149 ( T_13 * V_316 )
{
long V_266 ;
struct V_223 * V_283 = & V_223 ;
* V_316 = F_146 () ;
V_266 = ( * V_316 - V_283 -> clock . V_232 ) & V_283 -> clock . V_28 ;
return V_266 * V_283 -> clock . V_233 ;
}
static int F_150 ( T_12 * V_317 , T_13 * V_316 )
{
struct V_223 * V_283 = & V_223 ;
unsigned long V_229 ;
int V_318 ;
T_2 V_293 ;
do {
V_229 = F_151 ( & V_283 -> V_229 ) ;
V_318 = V_283 -> clock . V_230 ;
V_293 = V_283 -> V_235 ;
V_293 += F_149 ( V_316 ) ;
V_293 >>= V_283 -> clock . V_234 ;
V_293 += V_283 -> V_225 ;
} while ( F_152 ( F_153 ( & V_283 -> V_229 , V_229 ) ) );
* V_317 = V_293 ;
return V_318 ;
}
static bool F_154 ( T_12 * V_276 , T_13 * V_316 )
{
if ( V_223 . clock . V_230 != V_287 )
return false ;
return F_150 ( V_276 , V_316 ) == V_287 ;
}
static void F_155 ( struct V_138 * V_138 )
{
#ifdef F_62
struct V_281 * V_282 = & V_138 -> V_5 ;
int V_230 ;
bool V_319 , V_280 ;
V_280 = ( V_282 -> V_284 + 1 ==
F_135 ( & V_138 -> V_285 ) ) ;
V_319 = F_154 (
& V_282 -> V_320 ,
& V_282 -> V_321 ) ;
V_282 -> V_286 = V_319 && V_280
&& ! V_322
&& ! V_282 -> V_323 ;
if ( V_282 -> V_286 )
F_156 ( & V_324 , 1 ) ;
V_230 = V_223 . clock . V_230 ;
F_157 ( V_282 -> V_286 , V_230 ,
V_280 ) ;
#endif
}
static void F_158 ( struct V_138 * V_138 )
{
#ifdef F_62
int V_3 ;
struct V_1 * V_2 ;
struct V_281 * V_282 = & V_138 -> V_5 ;
F_144 ( & V_282 -> V_314 ) ;
F_159 ( V_138 ) ;
F_155 ( V_138 ) ;
F_160 (i, vcpu, kvm)
F_30 ( V_325 , V_2 ) ;
F_160 (i, vcpu, kvm)
F_161 ( V_326 , & V_2 -> V_327 ) ;
F_145 ( & V_282 -> V_314 ) ;
#endif
}
static int F_162 ( struct V_1 * V_266 )
{
unsigned long V_295 , V_267 ;
struct V_328 * V_2 = & V_266 -> V_5 ;
struct V_281 * V_282 = & V_266 -> V_138 -> V_5 ;
T_12 V_276 ;
T_2 V_329 , V_330 ;
struct V_331 V_332 ;
T_14 V_333 ;
bool V_286 ;
V_276 = 0 ;
V_330 = 0 ;
F_144 ( & V_282 -> V_314 ) ;
V_286 = V_282 -> V_286 ;
if ( V_286 ) {
V_330 = V_282 -> V_321 ;
V_276 = V_282 -> V_320 ;
}
F_145 ( & V_282 -> V_314 ) ;
F_163 ( V_295 ) ;
V_267 = F_164 ( V_334 ) ;
if ( F_152 ( V_267 == 0 ) ) {
F_165 ( V_295 ) ;
F_30 ( V_325 , V_266 ) ;
return 1 ;
}
if ( ! V_286 ) {
V_330 = F_166 () ;
V_276 = F_140 () ;
}
V_329 = V_73 -> V_335 ( V_266 , V_330 ) ;
if ( V_2 -> V_336 ) {
T_2 V_277 = F_133 ( V_266 , V_276 ) ;
if ( V_277 > V_329 ) {
F_167 ( V_266 , V_277 - V_329 ) ;
V_329 = V_277 ;
}
}
F_165 ( V_295 ) ;
if ( ! V_2 -> V_337 )
return 0 ;
if ( F_152 ( V_2 -> V_338 != V_267 ) ) {
F_126 ( V_271 / 1000 , V_267 ,
& V_2 -> V_339 . V_340 ,
& V_2 -> V_339 . V_341 ) ;
V_2 -> V_338 = V_267 ;
}
V_2 -> V_339 . V_329 = V_329 ;
V_2 -> V_339 . V_342 = V_276 + V_266 -> V_138 -> V_5 . V_244 ;
V_2 -> V_312 = V_329 ;
if ( F_152 ( F_168 ( V_266 -> V_138 , & V_2 -> V_343 ,
& V_332 , sizeof( V_332 ) ) ) )
return 0 ;
F_169 ( F_170 ( struct V_331 , V_239 ) != 0 ) ;
V_2 -> V_339 . V_239 = V_332 . V_239 + 1 ;
F_171 ( V_266 -> V_138 , & V_2 -> V_343 ,
& V_2 -> V_339 ,
sizeof( V_2 -> V_339 . V_239 ) ) ;
F_172 () ;
V_333 = ( V_332 . V_295 & V_344 ) ;
if ( V_2 -> V_345 ) {
V_333 |= V_344 ;
V_2 -> V_345 = false ;
}
if ( V_286 )
V_333 |= V_346 ;
V_2 -> V_339 . V_295 = V_333 ;
F_173 ( V_266 -> V_289 , & V_2 -> V_339 ) ;
F_171 ( V_266 -> V_138 , & V_2 -> V_343 ,
& V_2 -> V_339 ,
sizeof( V_2 -> V_339 ) ) ;
F_172 () ;
V_2 -> V_339 . V_239 ++ ;
F_171 ( V_266 -> V_138 , & V_2 -> V_343 ,
& V_2 -> V_339 ,
sizeof( V_2 -> V_339 . V_239 ) ) ;
return 0 ;
}
static void F_174 ( struct V_347 * V_348 )
{
int V_3 ;
struct V_349 * V_350 = F_175 ( V_348 ) ;
struct V_281 * V_282 = F_4 ( V_350 , struct V_281 ,
V_351 ) ;
struct V_138 * V_138 = F_4 ( V_282 , struct V_138 , V_5 ) ;
struct V_1 * V_2 ;
F_160 (i, vcpu, kvm) {
F_30 ( V_325 , V_2 ) ;
F_176 ( V_2 ) ;
}
}
static void F_177 ( struct V_1 * V_266 )
{
struct V_138 * V_138 = V_266 -> V_138 ;
F_30 ( V_325 , V_266 ) ;
F_178 ( & V_138 -> V_5 . V_351 ,
V_352 ) ;
}
static void F_179 ( struct V_347 * V_348 )
{
struct V_349 * V_350 = F_175 ( V_348 ) ;
struct V_281 * V_282 = F_4 ( V_350 , struct V_281 ,
V_353 ) ;
struct V_138 * V_138 = F_4 ( V_282 , struct V_138 , V_5 ) ;
if ( ! V_354 )
return;
F_178 ( & V_138 -> V_5 . V_351 , 0 ) ;
F_178 ( & V_138 -> V_5 . V_353 ,
V_355 ) ;
}
static int F_180 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
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
V_21 < F_181 ( V_357 ) ) {
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
static int F_182 ( struct V_1 * V_2 , T_2 V_38 )
{
struct V_138 * V_138 = V_2 -> V_138 ;
int V_365 = F_56 ( V_2 ) ;
T_14 * V_366 = V_365 ? ( T_14 * ) ( long ) V_138 -> V_5 . F_182 . V_367
: ( T_14 * ) ( long ) V_138 -> V_5 . F_182 . V_368 ;
T_14 V_369 = V_365 ? V_138 -> V_5 . F_182 . V_370
: V_138 -> V_5 . F_182 . V_371 ;
T_1 V_372 = V_38 & ~ V_373 ;
T_2 V_374 = V_38 & V_373 ;
T_14 * V_375 ;
int V_120 ;
V_120 = - V_376 ;
if ( V_372 >= V_369 )
goto V_113;
V_120 = - V_377 ;
V_375 = F_183 ( V_366 + ( V_372 * V_107 ) , V_107 ) ;
if ( F_184 ( V_375 ) ) {
V_120 = F_185 ( V_375 ) ;
goto V_113;
}
if ( F_186 ( V_2 , V_374 , V_375 , V_107 ) )
goto V_378;
V_120 = 0 ;
V_378:
F_187 ( V_375 ) ;
V_113:
return V_120 ;
}
static int F_188 ( struct V_1 * V_2 , T_2 V_38 )
{
T_6 V_379 = V_38 & ~ 0x3f ;
if ( V_38 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_380 = V_38 ;
if ( ! ( V_38 & V_381 ) ) {
F_64 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_189 ( V_2 -> V_138 , & V_2 -> V_5 . V_6 . V_38 , V_379 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_382 = ! ( V_38 & V_383 ) ;
F_190 ( V_2 ) ;
return 0 ;
}
static void F_191 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_337 = false ;
}
static void F_192 ( struct V_1 * V_2 )
{
T_2 V_307 ;
if ( ! ( V_2 -> V_5 . V_384 . V_380 & V_385 ) )
return;
V_307 = V_386 -> V_387 . V_388 - V_2 -> V_5 . V_384 . V_389 ;
V_2 -> V_5 . V_384 . V_389 = V_386 -> V_387 . V_388 ;
V_2 -> V_5 . V_384 . V_390 = V_307 ;
}
static void F_193 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_384 . V_380 & V_385 ) )
return;
if ( F_152 ( F_168 ( V_2 -> V_138 , & V_2 -> V_5 . V_384 . V_391 ,
& V_2 -> V_5 . V_384 . V_392 , sizeof( struct V_393 ) ) ) )
return;
V_2 -> V_5 . V_384 . V_392 . V_392 += V_2 -> V_5 . V_384 . V_390 ;
V_2 -> V_5 . V_384 . V_392 . V_239 += 2 ;
V_2 -> V_5 . V_384 . V_390 = 0 ;
F_171 ( V_2 -> V_138 , & V_2 -> V_5 . V_384 . V_391 ,
& V_2 -> V_5 . V_384 . V_392 , sizeof( struct V_393 ) ) ;
}
int F_194 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
bool V_394 = false ;
T_1 V_21 = V_33 -> V_145 ;
T_2 V_38 = V_33 -> V_38 ;
switch ( V_21 ) {
case V_395 :
case V_396 :
case V_397 :
case V_398 :
case V_399 :
case V_400 :
break;
case V_401 :
return F_105 ( V_2 , V_38 ) ;
case V_402 :
V_38 &= ~ ( T_2 ) 0x40 ;
V_38 &= ~ ( T_2 ) 0x100 ;
V_38 &= ~ ( T_2 ) 0x8 ;
V_38 &= ~ ( T_2 ) 0x40000 ;
if ( V_38 != 0 ) {
F_195 ( V_2 , L_7 ,
V_38 ) ;
return 1 ;
}
break;
case V_403 :
if ( V_38 != 0 ) {
F_195 ( V_2 , L_8
L_9 , V_38 ) ;
return 1 ;
}
break;
case V_404 :
if ( ! V_38 ) {
break;
} else if ( V_38 & ~ ( V_405 | V_406 ) ) {
return 1 ;
}
F_195 ( V_2 , L_10 ,
V_261 , V_38 ) ;
break;
case 0x200 ... 0x2ff :
return F_196 ( V_2 , V_21 , V_38 ) ;
case V_407 :
return F_20 ( V_2 , V_33 ) ;
case V_408 ... V_408 + 0x3ff :
return F_197 ( V_2 , V_21 , V_38 ) ;
case V_409 :
F_198 ( V_2 , V_38 ) ;
break;
case V_410 :
if ( F_142 ( V_2 ) ) {
if ( ! V_33 -> V_40 ) {
T_12 V_411 = V_38 - V_2 -> V_5 . V_292 ;
F_167 ( V_2 , V_411 ) ;
}
V_2 -> V_5 . V_292 = V_38 ;
}
break;
case V_412 :
V_2 -> V_5 . V_413 = V_38 ;
break;
case V_414 :
if ( ! V_33 -> V_40 )
return 1 ;
V_2 -> V_5 . V_415 = V_38 ;
break;
case V_416 :
case V_417 :
V_2 -> V_138 -> V_5 . V_238 = V_38 ;
F_119 ( V_2 -> V_138 , V_38 ) ;
break;
case V_418 :
case V_419 : {
T_2 V_420 ;
struct V_281 * V_282 = & V_2 -> V_138 -> V_5 ;
F_191 ( V_2 ) ;
if ( V_2 -> V_289 == 0 && ! V_33 -> V_40 ) {
bool V_421 = ( V_21 == V_419 ) ;
if ( V_282 -> V_323 != V_421 )
F_199 ( V_288 ,
& V_2 -> V_327 ) ;
V_282 -> V_323 = V_421 ;
}
V_2 -> V_5 . time = V_38 ;
F_30 ( V_422 , V_2 ) ;
if ( ! ( V_38 & 1 ) )
break;
V_420 = V_38 & ~ ( V_373 | 1 ) ;
if ( F_189 ( V_2 -> V_138 ,
& V_2 -> V_5 . V_343 , V_38 & ~ 1ULL ,
sizeof( struct V_331 ) ) )
V_2 -> V_5 . V_337 = false ;
else
V_2 -> V_5 . V_337 = true ;
break;
}
case V_423 :
if ( F_188 ( V_2 , V_38 ) )
return 1 ;
break;
case V_424 :
if ( F_152 ( ! F_200 () ) )
return 1 ;
if ( V_38 & V_425 )
return 1 ;
if ( F_189 ( V_2 -> V_138 , & V_2 -> V_5 . V_384 . V_391 ,
V_38 & V_426 ,
sizeof( struct V_393 ) ) )
return 1 ;
V_2 -> V_5 . V_384 . V_380 = V_38 ;
if ( ! ( V_38 & V_385 ) )
break;
V_2 -> V_5 . V_384 . V_389 = V_386 -> V_387 . V_388 ;
F_201 () ;
F_192 ( V_2 ) ;
F_202 () ;
F_30 ( V_427 , V_2 ) ;
break;
case V_428 :
if ( F_203 ( V_2 , V_38 ) )
return 1 ;
break;
case V_360 :
case V_358 :
case V_363 ... F_181 ( V_429 ) - 1 :
return F_180 ( V_2 , V_21 , V_38 ) ;
case V_430 ... V_431 :
case V_432 ... V_433 :
V_394 = true ;
case V_434 ... V_435 :
case V_436 ... V_437 :
if ( F_204 ( V_2 , V_21 ) )
return F_205 ( V_2 , V_33 ) ;
if ( V_394 || V_38 != 0 )
F_195 ( V_2 , L_11
L_12 , V_21 , V_38 ) ;
break;
case V_438 :
break;
case V_439 ... V_440 :
case V_441 ... V_442 :
case V_443 :
return F_206 ( V_2 , V_21 , V_38 ,
V_33 -> V_40 ) ;
case V_444 :
F_195 ( V_2 , L_13 , V_21 , V_38 ) ;
break;
case V_445 :
if ( ! F_207 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_446 . V_447 = V_38 ;
break;
case V_448 :
if ( ! F_207 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_446 . V_449 = V_38 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_138 -> V_5 . F_182 . V_21 ) )
return F_182 ( V_2 , V_38 ) ;
if ( F_204 ( V_2 , V_21 ) )
return F_205 ( V_2 , V_33 ) ;
if ( ! V_450 ) {
F_195 ( V_2 , L_14 ,
V_21 , V_38 ) ;
return 1 ;
} else {
F_195 ( V_2 , L_13 ,
V_21 , V_38 ) ;
break;
}
}
return 0 ;
}
int F_111 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
return V_73 -> V_451 ( V_2 , V_21 ) ;
}
static int F_208 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_452 )
{
T_2 V_38 ;
T_2 V_356 = V_2 -> V_5 . V_356 ;
unsigned V_357 = V_356 & 0xff ;
switch ( V_21 ) {
case V_453 :
case V_454 :
V_38 = 0 ;
break;
case V_455 :
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
V_21 < F_181 ( V_357 ) ) {
T_1 V_94 = V_21 - V_363 ;
V_38 = V_2 -> V_5 . V_364 [ V_94 ] ;
break;
}
return 1 ;
}
* V_452 = V_38 ;
return 0 ;
}
int F_209 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
switch ( V_33 -> V_145 ) {
case V_456 :
case V_457 :
case V_404 :
case V_458 :
case V_459 :
case V_460 :
case V_461 :
case V_462 :
case V_463 :
case V_464 :
case V_402 :
case V_398 :
case V_465 :
case V_395 :
case V_403 :
case V_400 :
V_33 -> V_38 = 0 ;
break;
case V_434 ... V_435 :
case V_430 ... V_431 :
case V_432 ... V_433 :
case V_436 ... V_437 :
if ( F_204 ( V_2 , V_33 -> V_145 ) )
return F_210 ( V_2 , V_33 -> V_145 , & V_33 -> V_38 ) ;
V_33 -> V_38 = 0 ;
break;
case V_396 :
V_33 -> V_38 = 0x100000000ULL ;
break;
case V_466 :
case 0x200 ... 0x2ff :
return F_211 ( V_2 , V_33 -> V_145 , & V_33 -> V_38 ) ;
case 0xcd :
V_33 -> V_38 = 3 ;
break;
case V_467 :
V_33 -> V_38 = 1 << 24 ;
break;
case V_407 :
V_33 -> V_38 = F_19 ( V_2 ) ;
break;
case V_408 ... V_408 + 0x3ff :
return F_212 ( V_2 , V_33 -> V_145 , & V_33 -> V_38 ) ;
break;
case V_409 :
V_33 -> V_38 = F_213 ( V_2 ) ;
break;
case V_410 :
V_33 -> V_38 = ( T_2 ) V_2 -> V_5 . V_292 ;
break;
case V_412 :
V_33 -> V_38 = V_2 -> V_5 . V_413 ;
break;
case V_414 :
if ( ! V_33 -> V_40 )
return 1 ;
V_33 -> V_38 = V_2 -> V_5 . V_415 ;
break;
case V_468 :
V_33 -> V_38 = 1000ULL ;
V_33 -> V_38 |= ( ( ( T_9 ) 4ULL ) << 40 ) ;
break;
case V_401 :
V_33 -> V_38 = V_2 -> V_5 . V_131 ;
break;
case V_417 :
case V_416 :
V_33 -> V_38 = V_2 -> V_138 -> V_5 . V_238 ;
break;
case V_419 :
case V_418 :
V_33 -> V_38 = V_2 -> V_5 . time ;
break;
case V_423 :
V_33 -> V_38 = V_2 -> V_5 . V_6 . V_380 ;
break;
case V_424 :
V_33 -> V_38 = V_2 -> V_5 . V_384 . V_380 ;
break;
case V_428 :
V_33 -> V_38 = V_2 -> V_5 . V_469 . V_380 ;
break;
case V_453 :
case V_454 :
case V_455 :
case V_360 :
case V_358 :
case V_363 ... F_181 ( V_429 ) - 1 :
return F_208 ( V_2 , V_33 -> V_145 , & V_33 -> V_38 ) ;
case V_438 :
V_33 -> V_38 = 0x20000000 ;
break;
case V_439 ... V_440 :
case V_441 ... V_442 :
case V_443 :
return F_214 ( V_2 ,
V_33 -> V_145 , & V_33 -> V_38 ) ;
break;
case V_444 :
V_33 -> V_38 = 0xbe702111 ;
break;
case V_445 :
if ( ! F_207 ( V_2 ) )
return 1 ;
V_33 -> V_38 = V_2 -> V_5 . V_446 . V_447 ;
break;
case V_448 :
if ( ! F_207 ( V_2 ) )
return 1 ;
V_33 -> V_38 = V_2 -> V_5 . V_446 . V_449 ;
break;
default:
if ( F_204 ( V_2 , V_33 -> V_145 ) )
return F_210 ( V_2 , V_33 -> V_145 , & V_33 -> V_38 ) ;
if ( ! V_450 ) {
F_195 ( V_2 , L_15 , V_33 -> V_145 ) ;
return 1 ;
} else {
F_195 ( V_2 , L_16 , V_33 -> V_145 ) ;
V_33 -> V_38 = 0 ;
}
break;
}
return 0 ;
}
static int F_215 ( struct V_1 * V_2 , struct V_470 * V_19 ,
struct V_471 * V_472 ,
int (* F_216)( struct V_1 * V_2 ,
unsigned V_145 , T_2 * V_38 ) )
{
int V_3 , V_473 ;
V_473 = F_217 ( & V_2 -> V_138 -> V_474 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_475 ; ++ V_3 )
if ( F_216 ( V_2 , V_472 [ V_3 ] . V_145 , & V_472 [ V_3 ] . V_38 ) )
break;
F_218 ( & V_2 -> V_138 -> V_474 , V_473 ) ;
return V_3 ;
}
static int F_219 ( struct V_1 * V_2 , struct V_470 T_15 * V_476 ,
int (* F_216)( struct V_1 * V_2 ,
unsigned V_145 , T_2 * V_38 ) ,
int V_477 )
{
struct V_470 V_19 ;
struct V_471 * V_472 ;
int V_120 , V_478 ;
unsigned V_479 ;
V_120 = - V_101 ;
if ( F_220 ( & V_19 , V_476 , sizeof V_19 ) )
goto V_113;
V_120 = - V_376 ;
if ( V_19 . V_475 >= V_480 )
goto V_113;
V_479 = sizeof( struct V_471 ) * V_19 . V_475 ;
V_472 = F_183 ( V_476 -> V_472 , V_479 ) ;
if ( F_184 ( V_472 ) ) {
V_120 = F_185 ( V_472 ) ;
goto V_113;
}
V_120 = V_478 = F_215 ( V_2 , & V_19 , V_472 , F_216 ) ;
if ( V_120 < 0 )
goto V_378;
V_120 = - V_101 ;
if ( V_477 && F_221 ( V_476 -> V_472 , V_472 , V_479 ) )
goto V_378;
V_120 = V_478 ;
V_378:
F_187 ( V_472 ) ;
V_113:
return V_120 ;
}
int F_222 ( struct V_138 * V_138 , long V_481 )
{
int V_120 ;
switch ( V_481 ) {
case V_482 :
case V_483 :
case V_484 :
case V_485 :
case V_486 :
case V_487 :
case V_488 :
case V_489 :
case V_490 :
case V_491 :
case V_492 :
case V_493 :
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
#ifdef F_223
case V_521 :
case V_522 :
#endif
V_120 = 1 ;
break;
case V_523 :
V_120 = V_73 -> V_524 () ;
break;
case V_525 :
V_120 = V_526 ;
break;
case V_527 :
V_120 = ! V_73 -> V_528 () ;
break;
case V_529 :
V_120 = V_530 ;
break;
case V_531 :
V_120 = V_532 ;
break;
case V_533 :
V_120 = V_534 ;
break;
case V_535 :
V_120 = 0 ;
break;
#ifdef F_223
case V_536 :
V_120 = F_224 ( & V_537 ) ;
break;
#endif
case V_538 :
V_120 = V_429 ;
break;
case V_539 :
V_120 = V_540 ;
break;
case V_541 :
V_120 = V_542 ;
break;
default:
V_120 = 0 ;
break;
}
return V_120 ;
}
long F_225 ( struct V_543 * V_544 ,
unsigned int V_545 , unsigned long V_546 )
{
void T_15 * V_547 = ( void T_15 * ) V_546 ;
long V_120 ;
switch ( V_545 ) {
case V_548 : {
struct V_549 T_15 * V_550 = V_547 ;
struct V_549 V_551 ;
unsigned V_478 ;
V_120 = - V_101 ;
if ( F_220 ( & V_551 , V_550 , sizeof V_551 ) )
goto V_113;
V_478 = V_551 . V_475 ;
V_551 . V_475 = V_552 + V_553 ;
if ( F_221 ( V_550 , & V_551 , sizeof V_551 ) )
goto V_113;
V_120 = - V_376 ;
if ( V_478 < V_551 . V_475 )
goto V_113;
V_120 = - V_101 ;
if ( F_221 ( V_550 -> V_554 , & V_555 ,
V_552 * sizeof( T_1 ) ) )
goto V_113;
if ( F_221 ( V_550 -> V_554 + V_552 ,
& V_556 ,
V_553 * sizeof( T_1 ) ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_557 :
case V_558 : {
struct V_559 T_15 * V_560 = V_547 ;
struct V_559 V_561 ;
V_120 = - V_101 ;
if ( F_220 ( & V_561 , V_560 , sizeof V_561 ) )
goto V_113;
V_120 = F_226 ( & V_561 , V_560 -> V_472 ,
V_545 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_221 ( V_560 , & V_561 , sizeof V_561 ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_562 : {
T_2 V_563 ;
V_563 = V_564 ;
V_120 = - V_101 ;
if ( F_221 ( V_547 , & V_563 , sizeof V_563 ) )
goto V_113;
V_120 = 0 ;
break;
}
default:
V_120 = - V_565 ;
}
V_113:
return V_120 ;
}
static void F_227 ( void * V_566 )
{
F_228 () ;
}
static bool F_229 ( struct V_1 * V_2 )
{
return F_230 ( V_2 -> V_138 ) ;
}
void F_231 ( struct V_1 * V_2 , int V_23 )
{
if ( F_229 ( V_2 ) ) {
if ( V_73 -> V_567 () )
F_232 ( V_23 , V_2 -> V_5 . V_568 ) ;
else if ( V_2 -> V_23 != - 1 && V_2 -> V_23 != V_23 )
F_233 ( V_2 -> V_23 ,
F_227 , NULL , 1 ) ;
}
V_73 -> V_569 ( V_2 , V_23 ) ;
if ( F_152 ( V_2 -> V_5 . V_570 ) ) {
F_234 ( V_2 , V_2 -> V_5 . V_570 ) ;
V_2 -> V_5 . V_570 = 0 ;
F_30 ( V_325 , V_2 ) ;
}
if ( F_152 ( V_2 -> V_23 != V_23 ) || F_141 () ) {
T_12 V_571 = ! V_2 -> V_5 . V_572 ? 0 :
F_166 () - V_2 -> V_5 . V_572 ;
if ( V_571 < 0 )
F_235 ( L_17 ) ;
if ( F_141 () ) {
T_2 V_94 = V_73 -> V_300 ( V_2 ,
V_2 -> V_5 . V_312 ) ;
V_73 -> V_313 ( V_2 , V_94 ) ;
V_2 -> V_5 . V_336 = 1 ;
}
if ( ! V_2 -> V_138 -> V_5 . V_286 || V_2 -> V_23 == - 1 )
F_30 ( V_422 , V_2 ) ;
if ( V_2 -> V_23 != V_23 )
F_236 ( V_2 ) ;
V_2 -> V_23 = V_23 ;
}
F_192 ( V_2 ) ;
F_30 ( V_427 , V_2 ) ;
}
void F_237 ( struct V_1 * V_2 )
{
V_73 -> V_573 ( V_2 ) ;
F_238 ( V_2 ) ;
V_2 -> V_5 . V_572 = F_166 () ;
}
static int F_239 ( struct V_1 * V_2 ,
struct V_574 * V_575 )
{
V_73 -> V_576 ( V_2 ) ;
memcpy ( V_575 -> V_577 , V_2 -> V_5 . V_578 -> V_577 , sizeof *V_575 ) ;
return 0 ;
}
static int F_240 ( struct V_1 * V_2 ,
struct V_574 * V_575 )
{
F_241 ( V_2 , V_575 ) ;
F_242 ( V_2 ) ;
return 0 ;
}
static int F_243 ( struct V_1 * V_2 ,
struct V_579 * V_580 )
{
if ( V_580 -> V_580 >= V_581 )
return - V_565 ;
if ( F_86 ( V_2 -> V_138 ) )
return - V_582 ;
F_244 ( V_2 , V_580 -> V_580 , false ) ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
static int F_245 ( struct V_1 * V_2 )
{
F_40 ( V_2 ) ;
return 0 ;
}
static int F_246 ( struct V_1 * V_2 )
{
F_30 ( V_583 , V_2 ) ;
return 0 ;
}
static int F_247 ( struct V_1 * V_2 ,
struct V_584 * V_585 )
{
if ( V_585 -> V_295 )
return - V_565 ;
V_2 -> V_5 . V_586 = ! ! V_585 -> V_587 ;
return 0 ;
}
static int F_248 ( struct V_1 * V_2 ,
T_2 V_356 )
{
int V_120 ;
unsigned V_357 = V_356 & 0xff , V_588 ;
V_120 = - V_565 ;
if ( ! V_357 || V_357 >= V_429 )
goto V_113;
if ( V_356 & ~ ( V_564 | 0xff | 0xff0000 ) )
goto V_113;
V_120 = 0 ;
V_2 -> V_5 . V_356 = V_356 ;
if ( V_356 & V_361 )
V_2 -> V_5 . V_362 = ~ ( T_2 ) 0 ;
for ( V_588 = 0 ; V_588 < V_357 ; V_588 ++ )
V_2 -> V_5 . V_364 [ V_588 * 4 ] = ~ ( T_2 ) 0 ;
V_113:
return V_120 ;
}
static int F_249 ( struct V_1 * V_2 ,
struct V_589 * V_590 )
{
T_2 V_356 = V_2 -> V_5 . V_356 ;
unsigned V_357 = V_356 & 0xff ;
T_2 * V_591 = V_2 -> V_5 . V_364 ;
if ( V_590 -> V_588 >= V_357 || ! ( V_590 -> V_449 & V_592 ) )
return - V_565 ;
if ( ( V_590 -> V_449 & V_593 ) && ( V_356 & V_361 ) &&
V_2 -> V_5 . V_362 != ~ ( T_2 ) 0 )
return 0 ;
V_591 += 4 * V_590 -> V_588 ;
if ( ( V_590 -> V_449 & V_593 ) && V_591 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_590 -> V_449 & V_593 ) {
if ( ( V_2 -> V_5 . V_359 & V_594 ) ||
! F_45 ( V_2 , V_595 ) ) {
F_30 ( V_72 , V_2 ) ;
return 0 ;
}
if ( V_591 [ 1 ] & V_592 )
V_590 -> V_449 |= V_596 ;
V_591 [ 2 ] = V_590 -> V_597 ;
V_591 [ 3 ] = V_590 -> V_598 ;
V_2 -> V_5 . V_359 = V_590 -> V_359 ;
V_591 [ 1 ] = V_590 -> V_449 ;
F_32 ( V_2 , V_58 ) ;
} else if ( ! ( V_591 [ 1 ] & V_592 )
|| ! ( V_591 [ 1 ] & V_593 ) ) {
if ( V_591 [ 1 ] & V_592 )
V_590 -> V_449 |= V_596 ;
V_591 [ 2 ] = V_590 -> V_597 ;
V_591 [ 3 ] = V_590 -> V_598 ;
V_591 [ 1 ] = V_590 -> V_449 ;
} else
V_591 [ 1 ] |= V_596 ;
return 0 ;
}
static void F_250 ( struct V_1 * V_2 ,
struct V_599 * V_600 )
{
F_251 ( V_2 ) ;
V_600 -> V_68 . V_601 =
V_2 -> V_5 . V_68 . V_69 &&
! F_252 ( V_2 -> V_5 . V_68 . V_16 ) ;
V_600 -> V_68 . V_16 = V_2 -> V_5 . V_68 . V_16 ;
V_600 -> V_68 . V_71 = V_2 -> V_5 . V_68 . V_71 ;
V_600 -> V_68 . V_602 = 0 ;
V_600 -> V_68 . V_62 = V_2 -> V_5 . V_68 . V_62 ;
V_600 -> V_603 . V_601 =
V_2 -> V_5 . V_603 . V_69 && ! V_2 -> V_5 . V_603 . V_604 ;
V_600 -> V_603 . V_16 = V_2 -> V_5 . V_603 . V_16 ;
V_600 -> V_603 . V_604 = 0 ;
V_600 -> V_603 . V_605 = V_73 -> V_606 ( V_2 ) ;
V_600 -> V_607 . V_601 = V_2 -> V_5 . V_608 ;
V_600 -> V_607 . V_69 = V_2 -> V_5 . V_609 != 0 ;
V_600 -> V_607 . V_610 = V_73 -> V_611 ( V_2 ) ;
V_600 -> V_607 . V_602 = 0 ;
V_600 -> V_612 = 0 ;
V_600 -> V_613 . V_614 = F_253 ( V_2 ) ;
V_600 -> V_613 . V_69 = V_2 -> V_5 . V_615 ;
V_600 -> V_613 . V_616 =
! ! ( V_2 -> V_5 . V_617 & V_618 ) ;
V_600 -> V_613 . V_619 = F_254 ( V_2 ) ;
V_600 -> V_295 = ( V_620
| V_621
| V_622 ) ;
memset ( & V_600 -> V_623 , 0 , sizeof( V_600 -> V_623 ) ) ;
}
static int F_255 ( struct V_1 * V_2 ,
struct V_599 * V_600 )
{
if ( V_600 -> V_295 & ~ ( V_620
| V_624
| V_621
| V_622 ) )
return - V_565 ;
F_251 ( V_2 ) ;
V_2 -> V_5 . V_68 . V_69 = V_600 -> V_68 . V_601 ;
V_2 -> V_5 . V_68 . V_16 = V_600 -> V_68 . V_16 ;
V_2 -> V_5 . V_68 . V_71 = V_600 -> V_68 . V_71 ;
V_2 -> V_5 . V_68 . V_62 = V_600 -> V_68 . V_62 ;
V_2 -> V_5 . V_603 . V_69 = V_600 -> V_603 . V_601 ;
V_2 -> V_5 . V_603 . V_16 = V_600 -> V_603 . V_16 ;
V_2 -> V_5 . V_603 . V_604 = V_600 -> V_603 . V_604 ;
if ( V_600 -> V_295 & V_621 )
V_73 -> V_625 ( V_2 ,
V_600 -> V_603 . V_605 ) ;
V_2 -> V_5 . V_608 = V_600 -> V_607 . V_601 ;
if ( V_600 -> V_295 & V_620 )
V_2 -> V_5 . V_609 = V_600 -> V_607 . V_69 ;
V_73 -> V_626 ( V_2 , V_600 -> V_607 . V_610 ) ;
if ( V_600 -> V_295 & V_624 &&
F_256 ( V_2 ) )
V_2 -> V_5 . V_578 -> V_612 = V_600 -> V_612 ;
if ( V_600 -> V_295 & V_622 ) {
if ( V_600 -> V_613 . V_614 )
V_2 -> V_5 . V_617 |= V_627 ;
else
V_2 -> V_5 . V_617 &= ~ V_627 ;
V_2 -> V_5 . V_615 = V_600 -> V_613 . V_69 ;
if ( V_600 -> V_613 . V_616 )
V_2 -> V_5 . V_617 |= V_618 ;
else
V_2 -> V_5 . V_617 &= ~ V_618 ;
if ( F_256 ( V_2 ) ) {
if ( V_600 -> V_613 . V_619 )
F_199 ( V_628 , & V_2 -> V_5 . V_578 -> V_629 ) ;
else
F_161 ( V_628 , & V_2 -> V_5 . V_578 -> V_629 ) ;
}
}
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
static void F_257 ( struct V_1 * V_2 ,
struct V_630 * V_631 )
{
unsigned long V_193 ;
memcpy ( V_631 -> V_180 , V_2 -> V_5 . V_180 , sizeof( V_2 -> V_5 . V_180 ) ) ;
F_97 ( V_2 , 6 , & V_193 ) ;
V_631 -> V_184 = V_193 ;
V_631 -> V_185 = V_2 -> V_5 . V_185 ;
V_631 -> V_295 = 0 ;
memset ( & V_631 -> V_623 , 0 , sizeof( V_631 -> V_623 ) ) ;
}
static int F_258 ( struct V_1 * V_2 ,
struct V_630 * V_631 )
{
if ( V_631 -> V_295 )
return - V_565 ;
memcpy ( V_2 -> V_5 . V_180 , V_631 -> V_180 , sizeof( V_2 -> V_5 . V_180 ) ) ;
F_90 ( V_2 ) ;
V_2 -> V_5 . V_184 = V_631 -> V_184 ;
F_91 ( V_2 ) ;
V_2 -> V_5 . V_185 = V_631 -> V_185 ;
F_92 ( V_2 ) ;
return 0 ;
}
static void F_259 ( T_14 * V_632 , struct V_1 * V_2 )
{
struct V_633 * V_634 = & V_2 -> V_5 . V_635 . V_636 . V_634 ;
T_2 V_637 = V_634 -> V_638 . V_639 ;
T_2 V_640 ;
memcpy ( V_632 , V_634 , V_641 ) ;
* ( T_2 * ) ( V_632 + V_641 ) = V_637 ;
V_640 = V_637 & ~ V_642 ;
while ( V_640 ) {
T_2 V_643 = V_640 & - V_640 ;
int V_145 = F_260 ( V_643 ) - 1 ;
void * V_644 = F_261 ( V_634 , V_643 ) ;
if ( V_644 ) {
T_1 V_479 , V_94 , V_198 , V_206 ;
F_262 ( V_645 , V_145 ,
& V_479 , & V_94 , & V_198 , & V_206 ) ;
memcpy ( V_632 + V_94 , V_644 , V_479 ) ;
}
V_640 -= V_643 ;
}
}
static void F_263 ( struct V_1 * V_2 , T_14 * V_644 )
{
struct V_633 * V_634 = & V_2 -> V_5 . V_635 . V_636 . V_634 ;
T_2 V_637 = * ( T_2 * ) ( V_644 + V_641 ) ;
T_2 V_640 ;
memcpy ( V_634 , V_644 , V_641 ) ;
V_634 -> V_638 . V_639 = V_637 ;
if ( V_646 )
V_634 -> V_638 . V_647 = V_144 | V_648 ;
V_640 = V_637 & ~ V_642 ;
while ( V_640 ) {
T_2 V_643 = V_640 & - V_640 ;
int V_145 = F_260 ( V_643 ) - 1 ;
void * V_632 = F_261 ( V_634 , V_643 ) ;
if ( V_632 ) {
T_1 V_479 , V_94 , V_198 , V_206 ;
F_262 ( V_645 , V_145 ,
& V_479 , & V_94 , & V_198 , & V_206 ) ;
memcpy ( V_632 , V_644 + V_94 , V_479 ) ;
}
V_640 -= V_643 ;
}
}
static void F_264 ( struct V_1 * V_2 ,
struct V_649 * V_650 )
{
if ( V_540 ) {
memset ( V_650 , 0 , sizeof( struct V_649 ) ) ;
F_259 ( ( T_14 * ) V_650 -> V_651 , V_2 ) ;
} else {
memcpy ( V_650 -> V_651 ,
& V_2 -> V_5 . V_635 . V_636 . V_652 ,
sizeof( struct V_653 ) ) ;
* ( T_2 * ) & V_650 -> V_651 [ V_641 / sizeof( T_1 ) ] =
V_642 ;
}
}
static int F_265 ( struct V_1 * V_2 ,
struct V_649 * V_650 )
{
T_2 V_637 =
* ( T_2 * ) & V_650 -> V_651 [ V_641 / sizeof( T_1 ) ] ;
if ( V_540 ) {
if ( V_637 & ~ F_266 () )
return - V_565 ;
F_263 ( V_2 , ( T_14 * ) V_650 -> V_651 ) ;
} else {
if ( V_637 & ~ V_642 )
return - V_565 ;
memcpy ( & V_2 -> V_5 . V_635 . V_636 . V_652 ,
V_650 -> V_651 , sizeof( struct V_653 ) ) ;
}
return 0 ;
}
static void F_267 ( struct V_1 * V_2 ,
struct V_654 * V_655 )
{
if ( ! V_540 ) {
V_655 -> V_656 = 0 ;
return;
}
V_655 -> V_656 = 1 ;
V_655 -> V_295 = 0 ;
V_655 -> V_657 [ 0 ] . V_146 = V_142 ;
V_655 -> V_657 [ 0 ] . V_22 = V_2 -> V_5 . V_143 ;
}
static int F_268 ( struct V_1 * V_2 ,
struct V_654 * V_655 )
{
int V_3 , V_120 = 0 ;
if ( ! V_540 )
return - V_565 ;
if ( V_655 -> V_656 > V_658 || V_655 -> V_295 )
return - V_565 ;
for ( V_3 = 0 ; V_3 < V_655 -> V_656 ; V_3 ++ )
if ( V_655 -> V_657 [ V_3 ] . V_146 == V_142 ) {
V_120 = F_72 ( V_2 , V_142 ,
V_655 -> V_657 [ V_3 ] . V_22 ) ;
break;
}
if ( V_120 )
V_120 = - V_565 ;
return V_120 ;
}
static int F_269 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_337 )
return - V_565 ;
V_2 -> V_5 . V_345 = true ;
F_30 ( V_325 , V_2 ) ;
return 0 ;
}
long F_270 ( struct V_543 * V_544 ,
unsigned int V_545 , unsigned long V_546 )
{
struct V_1 * V_2 = V_544 -> V_659 ;
void T_15 * V_547 = ( void T_15 * ) V_546 ;
int V_120 ;
union {
struct V_574 * V_660 ;
struct V_649 * V_634 ;
struct V_654 * V_657 ;
void * V_661 ;
} V_662 ;
V_662 . V_661 = NULL ;
switch ( V_545 ) {
case V_663 : {
V_120 = - V_565 ;
if ( ! V_2 -> V_5 . V_578 )
goto V_113;
V_662 . V_660 = F_271 ( sizeof( struct V_574 ) , V_664 ) ;
V_120 = - V_377 ;
if ( ! V_662 . V_660 )
goto V_113;
V_120 = F_239 ( V_2 , V_662 . V_660 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_221 ( V_547 , V_662 . V_660 , sizeof( struct V_574 ) ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_665 : {
V_120 = - V_565 ;
if ( ! V_2 -> V_5 . V_578 )
goto V_113;
V_662 . V_660 = F_183 ( V_547 , sizeof( * V_662 . V_660 ) ) ;
if ( F_184 ( V_662 . V_660 ) )
return F_185 ( V_662 . V_660 ) ;
V_120 = F_240 ( V_2 , V_662 . V_660 ) ;
break;
}
case V_666 : {
struct V_579 V_580 ;
V_120 = - V_101 ;
if ( F_220 ( & V_580 , V_547 , sizeof V_580 ) )
goto V_113;
V_120 = F_243 ( V_2 , & V_580 ) ;
break;
}
case V_667 : {
V_120 = F_245 ( V_2 ) ;
break;
}
case V_668 : {
V_120 = F_246 ( V_2 ) ;
break;
}
case V_669 : {
struct V_670 T_15 * V_560 = V_547 ;
struct V_670 V_561 ;
V_120 = - V_101 ;
if ( F_220 ( & V_561 , V_560 , sizeof V_561 ) )
goto V_113;
V_120 = F_272 ( V_2 , & V_561 , V_560 -> V_472 ) ;
break;
}
case V_671 : {
struct V_559 T_15 * V_560 = V_547 ;
struct V_559 V_561 ;
V_120 = - V_101 ;
if ( F_220 ( & V_561 , V_560 , sizeof V_561 ) )
goto V_113;
V_120 = F_273 ( V_2 , & V_561 ,
V_560 -> V_472 ) ;
break;
}
case V_672 : {
struct V_559 T_15 * V_560 = V_547 ;
struct V_559 V_561 ;
V_120 = - V_101 ;
if ( F_220 ( & V_561 , V_560 , sizeof V_561 ) )
goto V_113;
V_120 = F_274 ( V_2 , & V_561 ,
V_560 -> V_472 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_221 ( V_560 , & V_561 , sizeof V_561 ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_673 :
V_120 = F_219 ( V_2 , V_547 , F_110 , 1 ) ;
break;
case V_674 :
V_120 = F_219 ( V_2 , V_547 , F_112 , 0 ) ;
break;
case V_675 : {
struct V_584 V_585 ;
V_120 = - V_101 ;
if ( F_220 ( & V_585 , V_547 , sizeof V_585 ) )
goto V_113;
V_120 = F_247 ( V_2 , & V_585 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_221 ( V_547 , & V_585 , sizeof V_585 ) )
goto V_113;
V_120 = 0 ;
break;
} ;
case V_676 : {
struct V_677 V_678 ;
V_120 = - V_565 ;
if ( ! F_86 ( V_2 -> V_138 ) )
goto V_113;
V_120 = - V_101 ;
if ( F_220 ( & V_678 , V_547 , sizeof V_678 ) )
goto V_113;
V_120 = F_275 ( V_2 , V_678 . V_679 ) ;
break;
}
case V_680 : {
T_2 V_356 ;
V_120 = - V_101 ;
if ( F_220 ( & V_356 , V_547 , sizeof V_356 ) )
goto V_113;
V_120 = F_248 ( V_2 , V_356 ) ;
break;
}
case V_681 : {
struct V_589 V_590 ;
V_120 = - V_101 ;
if ( F_220 ( & V_590 , V_547 , sizeof V_590 ) )
goto V_113;
V_120 = F_249 ( V_2 , & V_590 ) ;
break;
}
case V_682 : {
struct V_599 V_600 ;
F_250 ( V_2 , & V_600 ) ;
V_120 = - V_101 ;
if ( F_221 ( V_547 , & V_600 , sizeof( struct V_599 ) ) )
break;
V_120 = 0 ;
break;
}
case V_683 : {
struct V_599 V_600 ;
V_120 = - V_101 ;
if ( F_220 ( & V_600 , V_547 , sizeof( struct V_599 ) ) )
break;
V_120 = F_255 ( V_2 , & V_600 ) ;
break;
}
case V_684 : {
struct V_630 V_631 ;
F_257 ( V_2 , & V_631 ) ;
V_120 = - V_101 ;
if ( F_221 ( V_547 , & V_631 ,
sizeof( struct V_630 ) ) )
break;
V_120 = 0 ;
break;
}
case V_685 : {
struct V_630 V_631 ;
V_120 = - V_101 ;
if ( F_220 ( & V_631 , V_547 ,
sizeof( struct V_630 ) ) )
break;
V_120 = F_258 ( V_2 , & V_631 ) ;
break;
}
case V_686 : {
V_662 . V_634 = F_271 ( sizeof( struct V_649 ) , V_664 ) ;
V_120 = - V_377 ;
if ( ! V_662 . V_634 )
break;
F_264 ( V_2 , V_662 . V_634 ) ;
V_120 = - V_101 ;
if ( F_221 ( V_547 , V_662 . V_634 , sizeof( struct V_649 ) ) )
break;
V_120 = 0 ;
break;
}
case V_687 : {
V_662 . V_634 = F_183 ( V_547 , sizeof( * V_662 . V_634 ) ) ;
if ( F_184 ( V_662 . V_634 ) )
return F_185 ( V_662 . V_634 ) ;
V_120 = F_265 ( V_2 , V_662 . V_634 ) ;
break;
}
case V_688 : {
V_662 . V_657 = F_271 ( sizeof( struct V_654 ) , V_664 ) ;
V_120 = - V_377 ;
if ( ! V_662 . V_657 )
break;
F_267 ( V_2 , V_662 . V_657 ) ;
V_120 = - V_101 ;
if ( F_221 ( V_547 , V_662 . V_657 ,
sizeof( struct V_654 ) ) )
break;
V_120 = 0 ;
break;
}
case V_689 : {
V_662 . V_657 = F_183 ( V_547 , sizeof( * V_662 . V_657 ) ) ;
if ( F_184 ( V_662 . V_657 ) )
return F_185 ( V_662 . V_657 ) ;
V_120 = F_268 ( V_2 , V_662 . V_657 ) ;
break;
}
case V_690 : {
T_1 V_691 ;
V_120 = - V_565 ;
V_691 = ( T_1 ) V_546 ;
if ( V_691 >= V_692 )
goto V_113;
if ( V_691 == 0 )
V_691 = V_273 ;
F_132 ( V_2 , V_691 ) ;
V_120 = 0 ;
goto V_113;
}
case V_693 : {
V_120 = V_2 -> V_5 . V_272 ;
goto V_113;
}
case V_694 : {
V_120 = F_269 ( V_2 ) ;
goto V_113;
}
default:
V_120 = - V_565 ;
}
V_113:
F_187 ( V_662 . V_661 ) ;
return V_120 ;
}
int F_276 ( struct V_1 * V_2 , struct V_695 * V_696 )
{
return V_697 ;
}
static int F_277 ( struct V_138 * V_138 , unsigned long V_597 )
{
int V_108 ;
if ( V_597 > ( unsigned int ) ( - 3 * V_107 ) )
return - V_565 ;
V_108 = V_73 -> V_698 ( V_138 , V_597 ) ;
return V_108 ;
}
static int F_278 ( struct V_138 * V_138 ,
T_2 V_699 )
{
V_138 -> V_5 . V_700 = V_699 ;
return 0 ;
}
static int F_279 ( struct V_138 * V_138 ,
T_1 V_701 )
{
if ( V_701 < V_702 )
return - V_565 ;
F_280 ( & V_138 -> V_703 ) ;
F_281 ( V_138 , V_701 ) ;
V_138 -> V_5 . V_704 = V_701 ;
F_282 ( & V_138 -> V_703 ) ;
return 0 ;
}
static int F_283 ( struct V_138 * V_138 )
{
return V_138 -> V_5 . V_705 ;
}
static int F_284 ( struct V_138 * V_138 , struct V_706 * V_707 )
{
int V_120 ;
V_120 = 0 ;
switch ( V_707 -> V_708 ) {
case V_709 :
memcpy ( & V_707 -> V_707 . V_710 ,
& F_285 ( V_138 ) -> V_711 [ 0 ] ,
sizeof( struct V_712 ) ) ;
break;
case V_713 :
memcpy ( & V_707 -> V_707 . V_710 ,
& F_285 ( V_138 ) -> V_711 [ 1 ] ,
sizeof( struct V_712 ) ) ;
break;
case V_714 :
V_120 = F_286 ( V_138 , & V_707 -> V_707 . V_715 ) ;
break;
default:
V_120 = - V_565 ;
break;
}
return V_120 ;
}
static int F_287 ( struct V_138 * V_138 , struct V_706 * V_707 )
{
int V_120 ;
V_120 = 0 ;
switch ( V_707 -> V_708 ) {
case V_709 :
F_144 ( & F_285 ( V_138 ) -> V_716 ) ;
memcpy ( & F_285 ( V_138 ) -> V_711 [ 0 ] ,
& V_707 -> V_707 . V_710 ,
sizeof( struct V_712 ) ) ;
F_145 ( & F_285 ( V_138 ) -> V_716 ) ;
break;
case V_713 :
F_144 ( & F_285 ( V_138 ) -> V_716 ) ;
memcpy ( & F_285 ( V_138 ) -> V_711 [ 1 ] ,
& V_707 -> V_707 . V_710 ,
sizeof( struct V_712 ) ) ;
F_145 ( & F_285 ( V_138 ) -> V_716 ) ;
break;
case V_714 :
V_120 = F_288 ( V_138 , & V_707 -> V_707 . V_715 ) ;
break;
default:
V_120 = - V_565 ;
break;
}
F_289 ( F_285 ( V_138 ) ) ;
return V_120 ;
}
static int F_290 ( struct V_138 * V_138 , struct V_717 * V_718 )
{
int V_120 = 0 ;
F_280 ( & V_138 -> V_5 . V_719 -> V_720 . V_716 ) ;
memcpy ( V_718 , & V_138 -> V_5 . V_719 -> V_720 , sizeof( struct V_717 ) ) ;
F_282 ( & V_138 -> V_5 . V_719 -> V_720 . V_716 ) ;
return V_120 ;
}
static int F_291 ( struct V_138 * V_138 , struct V_717 * V_718 )
{
int V_120 = 0 ;
F_280 ( & V_138 -> V_5 . V_719 -> V_720 . V_716 ) ;
memcpy ( & V_138 -> V_5 . V_719 -> V_720 , V_718 , sizeof( struct V_717 ) ) ;
F_292 ( V_138 , 0 , V_718 -> V_721 [ 0 ] . V_722 , 0 ) ;
F_282 ( & V_138 -> V_5 . V_719 -> V_720 . V_716 ) ;
return V_120 ;
}
static int F_293 ( struct V_138 * V_138 , struct V_723 * V_718 )
{
int V_120 = 0 ;
F_280 ( & V_138 -> V_5 . V_719 -> V_720 . V_716 ) ;
memcpy ( V_718 -> V_721 , & V_138 -> V_5 . V_719 -> V_720 . V_721 ,
sizeof( V_718 -> V_721 ) ) ;
V_718 -> V_295 = V_138 -> V_5 . V_719 -> V_720 . V_295 ;
F_282 ( & V_138 -> V_5 . V_719 -> V_720 . V_716 ) ;
memset ( & V_718 -> V_623 , 0 , sizeof( V_718 -> V_623 ) ) ;
return V_120 ;
}
static int F_294 ( struct V_138 * V_138 , struct V_723 * V_718 )
{
int V_120 = 0 , V_724 = 0 ;
T_1 V_725 , V_726 ;
F_280 ( & V_138 -> V_5 . V_719 -> V_720 . V_716 ) ;
V_725 = V_138 -> V_5 . V_719 -> V_720 . V_295 & V_727 ;
V_726 = V_718 -> V_295 & V_727 ;
if ( ! V_725 && V_726 )
V_724 = 1 ;
memcpy ( & V_138 -> V_5 . V_719 -> V_720 . V_721 , & V_718 -> V_721 ,
sizeof( V_138 -> V_5 . V_719 -> V_720 . V_721 ) ) ;
V_138 -> V_5 . V_719 -> V_720 . V_295 = V_718 -> V_295 ;
F_292 ( V_138 , 0 , V_138 -> V_5 . V_719 -> V_720 . V_721 [ 0 ] . V_722 , V_724 ) ;
F_282 ( & V_138 -> V_5 . V_719 -> V_720 . V_716 ) ;
return V_120 ;
}
static int F_295 ( struct V_138 * V_138 ,
struct V_728 * V_729 )
{
if ( ! V_138 -> V_5 . V_719 )
return - V_582 ;
F_280 ( & V_138 -> V_5 . V_719 -> V_720 . V_716 ) ;
V_138 -> V_5 . V_719 -> V_720 . V_63 = V_729 -> V_730 ;
F_282 ( & V_138 -> V_5 . V_719 -> V_720 . V_716 ) ;
return 0 ;
}
int F_296 ( struct V_138 * V_138 , struct V_731 * log )
{
bool V_732 = false ;
int V_120 ;
F_280 ( & V_138 -> V_703 ) ;
if ( V_73 -> V_733 )
V_73 -> V_733 ( V_138 ) ;
V_120 = F_297 ( V_138 , log , & V_732 ) ;
F_298 ( & V_138 -> V_703 ) ;
if ( V_732 )
F_299 ( V_138 ) ;
F_282 ( & V_138 -> V_703 ) ;
return V_120 ;
}
int F_300 ( struct V_138 * V_138 , struct V_734 * V_735 ,
bool V_736 )
{
if ( ! F_86 ( V_138 ) )
return - V_582 ;
V_735 -> V_449 = F_301 ( V_138 , V_737 ,
V_735 -> V_580 , V_735 -> V_738 ,
V_736 ) ;
return 0 ;
}
static int F_302 ( struct V_138 * V_138 ,
struct V_739 * V_740 )
{
int V_120 ;
if ( V_740 -> V_295 )
return - V_565 ;
switch ( V_740 -> V_740 ) {
case V_519 :
V_138 -> V_5 . V_741 = V_740 -> args [ 0 ] ;
V_120 = 0 ;
break;
default:
V_120 = - V_565 ;
break;
}
return V_120 ;
}
long F_303 ( struct V_543 * V_544 ,
unsigned int V_545 , unsigned long V_546 )
{
struct V_138 * V_138 = V_544 -> V_659 ;
void T_15 * V_547 = ( void T_15 * ) V_546 ;
int V_120 = - V_742 ;
union {
struct V_717 V_718 ;
struct V_723 V_743 ;
struct V_744 V_745 ;
} V_662 ;
switch ( V_545 ) {
case V_746 :
V_120 = F_277 ( V_138 , V_546 ) ;
break;
case V_747 : {
T_2 V_699 ;
V_120 = - V_101 ;
if ( F_220 ( & V_699 , V_547 , sizeof V_699 ) )
goto V_113;
V_120 = F_278 ( V_138 , V_699 ) ;
break;
}
case V_748 :
V_120 = F_279 ( V_138 , V_546 ) ;
break;
case V_749 :
V_120 = F_283 ( V_138 ) ;
break;
case V_750 : {
struct V_751 * V_752 ;
F_280 ( & V_138 -> V_716 ) ;
V_120 = - V_753 ;
if ( V_138 -> V_5 . V_752 )
goto V_754;
V_120 = - V_565 ;
if ( F_135 ( & V_138 -> V_285 ) )
goto V_754;
V_120 = - V_377 ;
V_752 = F_304 ( V_138 ) ;
if ( V_752 ) {
V_120 = F_305 ( V_138 ) ;
if ( V_120 ) {
F_280 ( & V_138 -> V_703 ) ;
F_306 ( V_752 ) ;
F_282 ( & V_138 -> V_703 ) ;
goto V_754;
}
} else
goto V_754;
V_120 = F_307 ( V_138 ) ;
if ( V_120 ) {
F_280 ( & V_138 -> V_703 ) ;
F_280 ( & V_138 -> V_755 ) ;
F_308 ( V_138 ) ;
F_306 ( V_752 ) ;
F_282 ( & V_138 -> V_755 ) ;
F_282 ( & V_138 -> V_703 ) ;
goto V_754;
}
F_172 () ;
V_138 -> V_5 . V_752 = V_752 ;
V_754:
F_282 ( & V_138 -> V_716 ) ;
break;
}
case V_756 :
V_662 . V_745 . V_295 = V_757 ;
goto V_758;
case V_759 :
V_120 = - V_101 ;
if ( F_220 ( & V_662 . V_745 , V_547 ,
sizeof( struct V_744 ) ) )
goto V_113;
V_758:
F_280 ( & V_138 -> V_703 ) ;
V_120 = - V_753 ;
if ( V_138 -> V_5 . V_719 )
goto V_760;
V_120 = - V_377 ;
V_138 -> V_5 . V_719 = F_309 ( V_138 , V_662 . V_745 . V_295 ) ;
if ( V_138 -> V_5 . V_719 )
V_120 = 0 ;
V_760:
F_282 ( & V_138 -> V_703 ) ;
break;
case V_761 : {
struct V_706 * V_707 ;
V_707 = F_183 ( V_547 , sizeof( * V_707 ) ) ;
if ( F_184 ( V_707 ) ) {
V_120 = F_185 ( V_707 ) ;
goto V_113;
}
V_120 = - V_582 ;
if ( ! F_86 ( V_138 ) )
goto V_762;
V_120 = F_284 ( V_138 , V_707 ) ;
if ( V_120 )
goto V_762;
V_120 = - V_101 ;
if ( F_221 ( V_547 , V_707 , sizeof *V_707 ) )
goto V_762;
V_120 = 0 ;
V_762:
F_187 ( V_707 ) ;
break;
}
case V_763 : {
struct V_706 * V_707 ;
V_707 = F_183 ( V_547 , sizeof( * V_707 ) ) ;
if ( F_184 ( V_707 ) ) {
V_120 = F_185 ( V_707 ) ;
goto V_113;
}
V_120 = - V_582 ;
if ( ! F_86 ( V_138 ) )
goto V_764;
V_120 = F_287 ( V_138 , V_707 ) ;
if ( V_120 )
goto V_764;
V_120 = 0 ;
V_764:
F_187 ( V_707 ) ;
break;
}
case V_765 : {
V_120 = - V_101 ;
if ( F_220 ( & V_662 . V_718 , V_547 , sizeof( struct V_717 ) ) )
goto V_113;
V_120 = - V_582 ;
if ( ! V_138 -> V_5 . V_719 )
goto V_113;
V_120 = F_290 ( V_138 , & V_662 . V_718 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_221 ( V_547 , & V_662 . V_718 , sizeof( struct V_717 ) ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_766 : {
V_120 = - V_101 ;
if ( F_220 ( & V_662 . V_718 , V_547 , sizeof V_662 . V_718 ) )
goto V_113;
V_120 = - V_582 ;
if ( ! V_138 -> V_5 . V_719 )
goto V_113;
V_120 = F_291 ( V_138 , & V_662 . V_718 ) ;
break;
}
case V_767 : {
V_120 = - V_582 ;
if ( ! V_138 -> V_5 . V_719 )
goto V_113;
V_120 = F_293 ( V_138 , & V_662 . V_743 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_221 ( V_547 , & V_662 . V_743 , sizeof( V_662 . V_743 ) ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_768 : {
V_120 = - V_101 ;
if ( F_220 ( & V_662 . V_743 , V_547 , sizeof( V_662 . V_743 ) ) )
goto V_113;
V_120 = - V_582 ;
if ( ! V_138 -> V_5 . V_719 )
goto V_113;
V_120 = F_294 ( V_138 , & V_662 . V_743 ) ;
break;
}
case V_769 : {
struct V_728 V_729 ;
V_120 = - V_101 ;
if ( F_220 ( & V_729 , V_547 , sizeof( V_729 ) ) )
goto V_113;
V_120 = F_295 ( V_138 , & V_729 ) ;
break;
}
case V_770 :
V_120 = 0 ;
F_280 ( & V_138 -> V_716 ) ;
if ( F_135 ( & V_138 -> V_285 ) != 0 )
V_120 = - V_771 ;
else
V_138 -> V_5 . V_772 = V_546 ;
F_282 ( & V_138 -> V_716 ) ;
break;
case V_773 : {
V_120 = - V_101 ;
if ( F_220 ( & V_138 -> V_5 . F_182 , V_547 ,
sizeof( struct V_774 ) ) )
goto V_113;
V_120 = - V_565 ;
if ( V_138 -> V_5 . F_182 . V_295 )
goto V_113;
V_120 = 0 ;
break;
}
case V_775 : {
struct V_776 V_777 ;
T_2 V_778 ;
T_12 V_307 ;
V_120 = - V_101 ;
if ( F_220 ( & V_777 , V_547 , sizeof( V_777 ) ) )
goto V_113;
V_120 = - V_565 ;
if ( V_777 . V_295 )
goto V_113;
V_120 = 0 ;
F_310 () ;
V_778 = F_140 () ;
V_307 = V_777 . clock - V_778 ;
F_311 () ;
V_138 -> V_5 . V_244 = V_307 ;
F_158 ( V_138 ) ;
break;
}
case V_779 : {
struct V_776 V_777 ;
T_2 V_778 ;
F_310 () ;
V_778 = F_140 () ;
V_777 . clock = V_138 -> V_5 . V_244 + V_778 ;
F_311 () ;
V_777 . V_295 = 0 ;
memset ( & V_777 . V_602 , 0 , sizeof( V_777 . V_602 ) ) ;
V_120 = - V_101 ;
if ( F_221 ( V_547 , & V_777 , sizeof( V_777 ) ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_780 : {
struct V_739 V_740 ;
V_120 = - V_101 ;
if ( F_220 ( & V_740 , V_547 , sizeof( V_740 ) ) )
goto V_113;
V_120 = F_302 ( V_138 , & V_740 ) ;
break;
}
default:
V_120 = F_312 ( V_138 , V_545 , V_546 ) ;
}
V_113:
return V_120 ;
}
static void F_313 ( void )
{
T_1 V_781 [ 2 ] ;
unsigned V_3 , V_782 ;
for ( V_3 = V_782 = 0 ; V_3 < F_52 ( V_555 ) ; V_3 ++ ) {
if ( F_314 ( V_555 [ V_3 ] , & V_781 [ 0 ] , & V_781 [ 1 ] ) < 0 )
continue;
switch ( V_555 [ V_3 ] ) {
case V_783 :
if ( ! V_73 -> V_784 () )
continue;
break;
default:
break;
}
if ( V_782 < V_3 )
V_555 [ V_782 ] = V_555 [ V_3 ] ;
V_782 ++ ;
}
V_552 = V_782 ;
for ( V_3 = V_782 = 0 ; V_3 < F_52 ( V_556 ) ; V_3 ++ ) {
switch ( V_556 [ V_3 ] ) {
case V_414 :
if ( ! V_73 -> V_524 () )
continue;
break;
default:
break;
}
if ( V_782 < V_3 )
V_556 [ V_782 ] = V_556 [ V_3 ] ;
V_782 ++ ;
}
V_553 = V_782 ;
}
static int F_315 ( struct V_1 * V_2 , T_6 V_597 , int V_95 ,
const void * V_266 )
{
int V_785 = 0 ;
int V_478 ;
do {
V_478 = F_316 ( V_95 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_578 &&
! F_317 ( V_2 , & V_2 -> V_5 . V_578 -> V_786 , V_597 , V_478 , V_266 ) )
&& F_318 ( V_2 , V_787 , V_597 , V_478 , V_266 ) )
break;
V_785 += V_478 ;
V_597 += V_478 ;
V_95 -= V_478 ;
V_266 += V_478 ;
} while ( V_95 );
return V_785 ;
}
static int F_319 ( struct V_1 * V_2 , T_6 V_597 , int V_95 , void * V_266 )
{
int V_785 = 0 ;
int V_478 ;
do {
V_478 = F_316 ( V_95 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_578 &&
! F_320 ( V_2 , & V_2 -> V_5 . V_578 -> V_786 ,
V_597 , V_478 , V_266 ) )
&& F_321 ( V_2 , V_787 , V_597 , V_478 , V_266 ) )
break;
F_322 ( V_788 , V_478 , V_597 , * ( T_2 * ) V_266 ) ;
V_785 += V_478 ;
V_597 += V_478 ;
V_95 -= V_478 ;
V_266 += V_478 ;
} while ( V_95 );
return V_785 ;
}
static void F_323 ( struct V_1 * V_2 ,
struct V_789 * V_790 , int V_791 )
{
V_73 -> V_792 ( V_2 , V_790 , V_791 ) ;
}
void F_324 ( struct V_1 * V_2 ,
struct V_789 * V_790 , int V_791 )
{
V_73 -> V_793 ( V_2 , V_790 , V_791 ) ;
}
T_6 F_325 ( struct V_1 * V_2 , T_6 V_379 , T_1 V_96 ,
struct V_75 * V_68 )
{
T_6 V_794 ;
F_13 ( ! F_39 ( V_2 ) ) ;
V_96 |= V_111 ;
V_794 = V_2 -> V_5 . V_84 . V_795 ( V_2 , V_379 , V_96 , V_68 ) ;
return V_794 ;
}
T_6 F_326 ( struct V_1 * V_2 , T_16 V_796 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
return V_2 -> V_5 . V_103 -> V_795 ( V_2 , V_796 , V_96 , V_68 ) ;
}
T_6 F_327 ( struct V_1 * V_2 , T_16 V_796 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
V_96 |= V_797 ;
return V_2 -> V_5 . V_103 -> V_795 ( V_2 , V_796 , V_96 , V_68 ) ;
}
T_6 F_328 ( struct V_1 * V_2 , T_16 V_796 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
V_96 |= V_112 ;
return V_2 -> V_5 . V_103 -> V_795 ( V_2 , V_796 , V_96 , V_68 ) ;
}
T_6 F_329 ( struct V_1 * V_2 , T_16 V_796 ,
struct V_75 * V_68 )
{
return V_2 -> V_5 . V_103 -> V_795 ( V_2 , V_796 , 0 , V_68 ) ;
}
static int F_330 ( T_16 V_597 , void * V_193 , unsigned int V_798 ,
struct V_1 * V_2 , T_1 V_96 ,
struct V_75 * V_68 )
{
void * V_38 = V_193 ;
int V_120 = V_799 ;
while ( V_798 ) {
T_6 V_379 = V_2 -> V_5 . V_103 -> V_795 ( V_2 , V_597 , V_96 ,
V_68 ) ;
unsigned V_94 = V_597 & ( V_107 - 1 ) ;
unsigned V_800 = F_316 ( V_798 , ( unsigned ) V_107 - V_94 ) ;
int V_108 ;
if ( V_379 == V_100 )
return V_801 ;
V_108 = F_49 ( V_2 , V_379 >> V_106 , V_38 ,
V_94 , V_800 ) ;
if ( V_108 < 0 ) {
V_120 = V_802 ;
goto V_113;
}
V_798 -= V_800 ;
V_38 += V_800 ;
V_597 += V_800 ;
}
V_113:
return V_120 ;
}
static int F_331 ( struct V_803 * V_804 ,
T_16 V_597 , void * V_193 , unsigned int V_798 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_332 ( V_804 ) ;
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
unsigned V_94 ;
int V_108 ;
T_6 V_379 = V_2 -> V_5 . V_103 -> V_795 ( V_2 , V_597 , V_96 | V_797 ,
V_68 ) ;
if ( F_152 ( V_379 == V_100 ) )
return V_801 ;
V_94 = V_597 & ( V_107 - 1 ) ;
if ( F_28 ( V_94 + V_798 > V_107 ) )
V_798 = ( unsigned ) V_107 - V_94 ;
V_108 = F_49 ( V_2 , V_379 >> V_106 , V_193 ,
V_94 , V_798 ) ;
if ( F_152 ( V_108 < 0 ) )
return V_802 ;
return V_799 ;
}
int F_333 ( struct V_803 * V_804 ,
T_16 V_597 , void * V_193 , unsigned int V_798 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_332 ( V_804 ) ;
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
return F_330 ( V_597 , V_193 , V_798 , V_2 , V_96 ,
V_68 ) ;
}
static int F_334 ( struct V_803 * V_804 ,
T_16 V_597 , void * V_193 , unsigned int V_798 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_332 ( V_804 ) ;
return F_330 ( V_597 , V_193 , V_798 , V_2 , 0 , V_68 ) ;
}
int F_335 ( struct V_803 * V_804 ,
T_16 V_597 , void * V_193 ,
unsigned int V_798 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_332 ( V_804 ) ;
void * V_38 = V_193 ;
int V_120 = V_799 ;
while ( V_798 ) {
T_6 V_379 = V_2 -> V_5 . V_103 -> V_795 ( V_2 , V_597 ,
V_112 ,
V_68 ) ;
unsigned V_94 = V_597 & ( V_107 - 1 ) ;
unsigned V_805 = F_316 ( V_798 , ( unsigned ) V_107 - V_94 ) ;
int V_108 ;
if ( V_379 == V_100 )
return V_801 ;
V_108 = F_186 ( V_2 , V_379 , V_38 , V_805 ) ;
if ( V_108 < 0 ) {
V_120 = V_802 ;
goto V_113;
}
V_798 -= V_805 ;
V_38 += V_805 ;
V_597 += V_805 ;
}
V_113:
return V_120 ;
}
static int F_336 ( struct V_1 * V_2 , unsigned long V_796 ,
T_6 * V_379 , struct V_75 * V_68 ,
bool V_806 )
{
T_1 V_96 = ( ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 )
| ( V_806 ? V_112 : 0 ) ;
if ( F_337 ( V_2 , V_796 )
&& ! F_338 ( V_2 , V_2 -> V_5 . V_103 ,
V_2 -> V_5 . V_96 , V_96 ) ) {
* V_379 = V_2 -> V_5 . V_807 << V_106 |
( V_796 & ( V_107 - 1 ) ) ;
F_339 ( V_796 , * V_379 , V_806 , false ) ;
return 1 ;
}
* V_379 = V_2 -> V_5 . V_103 -> V_795 ( V_2 , V_796 , V_96 , V_68 ) ;
if ( * V_379 == V_100 )
return - 1 ;
if ( ( * V_379 & V_373 ) == V_808 )
return 1 ;
if ( F_340 ( V_2 , * V_379 ) ) {
F_339 ( V_796 , * V_379 , V_806 , true ) ;
return 1 ;
}
return 0 ;
}
int F_341 ( struct V_1 * V_2 , T_6 V_379 ,
const void * V_193 , int V_798 )
{
int V_108 ;
V_108 = F_186 ( V_2 , V_379 , V_193 , V_798 ) ;
if ( V_108 < 0 )
return 0 ;
F_342 ( V_2 , V_379 , V_193 , V_798 ) ;
return 1 ;
}
static int F_343 ( struct V_1 * V_2 , void * V_193 , int V_798 )
{
if ( V_2 -> V_809 ) {
F_322 ( V_788 , V_798 ,
V_2 -> V_810 [ 0 ] . V_379 , * ( T_2 * ) V_193 ) ;
V_2 -> V_809 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_344 ( struct V_1 * V_2 , T_6 V_379 ,
void * V_193 , int V_798 )
{
return ! F_345 ( V_2 , V_379 , V_193 , V_798 ) ;
}
static int F_346 ( struct V_1 * V_2 , T_6 V_379 ,
void * V_193 , int V_798 )
{
return F_341 ( V_2 , V_379 , V_193 , V_798 ) ;
}
static int F_347 ( struct V_1 * V_2 , T_6 V_379 , int V_798 , void * V_193 )
{
F_322 ( V_811 , V_798 , V_379 , * ( T_2 * ) V_193 ) ;
return F_315 ( V_2 , V_379 , V_798 , V_193 ) ;
}
static int F_348 ( struct V_1 * V_2 , T_6 V_379 ,
void * V_193 , int V_798 )
{
F_322 ( V_812 , V_798 , V_379 , 0 ) ;
return V_802 ;
}
static int F_349 ( struct V_1 * V_2 , T_6 V_379 ,
void * V_193 , int V_798 )
{
struct V_813 * V_814 = & V_2 -> V_810 [ 0 ] ;
memcpy ( V_2 -> V_815 -> V_816 . V_38 , V_814 -> V_38 , F_316 ( 8u , V_814 -> V_95 ) ) ;
return V_799 ;
}
static int F_350 ( unsigned long V_597 , void * V_193 ,
unsigned int V_798 ,
struct V_75 * V_68 ,
struct V_1 * V_2 ,
const struct V_817 * V_818 )
{
T_6 V_379 ;
int V_785 , V_108 ;
bool V_806 = V_818 -> V_806 ;
struct V_813 * V_814 ;
V_108 = F_336 ( V_2 , V_597 , & V_379 , V_68 , V_806 ) ;
if ( V_108 < 0 )
return V_801 ;
if ( V_108 )
goto V_816;
if ( V_818 -> V_819 ( V_2 , V_379 , V_193 , V_798 ) )
return V_799 ;
V_816:
V_785 = V_818 -> V_820 ( V_2 , V_379 , V_798 , V_193 ) ;
if ( V_785 == V_798 )
return V_799 ;
V_379 += V_785 ;
V_798 -= V_785 ;
V_193 += V_785 ;
F_28 ( V_2 -> V_821 >= V_822 ) ;
V_814 = & V_2 -> V_810 [ V_2 -> V_821 ++ ] ;
V_814 -> V_379 = V_379 ;
V_814 -> V_38 = V_193 ;
V_814 -> V_95 = V_798 ;
return V_799 ;
}
static int F_351 ( struct V_803 * V_804 ,
unsigned long V_597 ,
void * V_193 , unsigned int V_798 ,
struct V_75 * V_68 ,
const struct V_817 * V_818 )
{
struct V_1 * V_2 = F_332 ( V_804 ) ;
T_6 V_379 ;
int V_823 ;
if ( V_818 -> V_824 &&
V_818 -> V_824 ( V_2 , V_193 , V_798 ) )
return V_799 ;
V_2 -> V_821 = 0 ;
if ( ( ( V_597 + V_798 - 1 ) ^ V_597 ) & V_373 ) {
int V_825 ;
V_825 = - V_597 & ~ V_373 ;
V_823 = F_350 ( V_597 , V_193 , V_825 , V_68 ,
V_2 , V_818 ) ;
if ( V_823 != V_799 )
return V_823 ;
V_597 += V_825 ;
if ( V_804 -> V_318 != V_826 )
V_597 = ( T_1 ) V_597 ;
V_193 += V_825 ;
V_798 -= V_825 ;
}
V_823 = F_350 ( V_597 , V_193 , V_798 , V_68 ,
V_2 , V_818 ) ;
if ( V_823 != V_799 )
return V_823 ;
if ( ! V_2 -> V_821 )
return V_823 ;
V_379 = V_2 -> V_810 [ 0 ] . V_379 ;
V_2 -> V_827 = 1 ;
V_2 -> V_828 = 0 ;
V_2 -> V_815 -> V_816 . V_95 = F_316 ( 8u , V_2 -> V_810 [ 0 ] . V_95 ) ;
V_2 -> V_815 -> V_816 . V_829 = V_2 -> V_830 = V_818 -> V_806 ;
V_2 -> V_815 -> V_831 = V_832 ;
V_2 -> V_815 -> V_816 . V_833 = V_379 ;
return V_818 -> V_834 ( V_2 , V_379 , V_193 , V_798 ) ;
}
static int F_352 ( struct V_803 * V_804 ,
unsigned long V_597 ,
void * V_193 ,
unsigned int V_798 ,
struct V_75 * V_68 )
{
return F_351 ( V_804 , V_597 , V_193 , V_798 ,
V_68 , & V_835 ) ;
}
static int F_353 ( struct V_803 * V_804 ,
unsigned long V_597 ,
const void * V_193 ,
unsigned int V_798 ,
struct V_75 * V_68 )
{
return F_351 ( V_804 , V_597 , ( void * ) V_193 , V_798 ,
V_68 , & V_836 ) ;
}
static int F_354 ( struct V_803 * V_804 ,
unsigned long V_597 ,
const void * V_837 ,
const void * V_838 ,
unsigned int V_798 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_332 ( V_804 ) ;
T_6 V_379 ;
struct V_375 * V_375 ;
char * V_839 ;
bool V_840 ;
if ( V_798 > 8 || ( V_798 & ( V_798 - 1 ) ) )
goto V_841;
V_379 = F_328 ( V_2 , V_597 , NULL ) ;
if ( V_379 == V_100 ||
( V_379 & V_373 ) == V_808 )
goto V_841;
if ( ( ( V_379 + V_798 - 1 ) & V_373 ) != ( V_379 & V_373 ) )
goto V_841;
V_375 = F_355 ( V_2 , V_379 >> V_106 ) ;
if ( F_356 ( V_375 ) )
goto V_841;
V_839 = F_357 ( V_375 ) ;
V_839 += F_358 ( V_379 ) ;
switch ( V_798 ) {
case 1 :
V_840 = F_359 ( T_14 , V_839 , V_837 , V_838 ) ;
break;
case 2 :
V_840 = F_359 ( V_842 , V_839 , V_837 , V_838 ) ;
break;
case 4 :
V_840 = F_359 ( T_1 , V_839 , V_837 , V_838 ) ;
break;
case 8 :
V_840 = F_360 ( V_839 , V_837 , V_838 ) ;
break;
default:
F_25 () ;
}
F_361 ( V_839 ) ;
F_362 ( V_375 ) ;
if ( ! V_840 )
return V_843 ;
F_363 ( V_2 , V_379 >> V_106 ) ;
F_342 ( V_2 , V_379 , V_838 , V_798 ) ;
return V_799 ;
V_841:
F_364 ( V_844 L_18 ) ;
return F_353 ( V_804 , V_597 , V_838 , V_798 , V_68 ) ;
}
static int F_365 ( struct V_1 * V_2 , void * V_845 )
{
int V_120 ;
if ( V_2 -> V_5 . V_846 . V_847 )
V_120 = F_321 ( V_2 , V_848 , V_2 -> V_5 . V_846 . V_849 ,
V_2 -> V_5 . V_846 . V_479 , V_845 ) ;
else
V_120 = F_318 ( V_2 , V_848 ,
V_2 -> V_5 . V_846 . V_849 , V_2 -> V_5 . V_846 . V_479 ,
V_845 ) ;
return V_120 ;
}
static int F_366 ( struct V_1 * V_2 , int V_479 ,
unsigned short V_849 , void * V_193 ,
unsigned int V_722 , bool V_847 )
{
V_2 -> V_5 . V_846 . V_849 = V_849 ;
V_2 -> V_5 . V_846 . V_847 = V_847 ;
V_2 -> V_5 . V_846 . V_722 = V_722 ;
V_2 -> V_5 . V_846 . V_479 = V_479 ;
if ( ! F_365 ( V_2 , V_2 -> V_5 . V_850 ) ) {
V_2 -> V_5 . V_846 . V_722 = 0 ;
return 1 ;
}
V_2 -> V_815 -> V_831 = V_851 ;
V_2 -> V_815 -> V_852 . V_853 = V_847 ? V_854 : V_855 ;
V_2 -> V_815 -> V_852 . V_479 = V_479 ;
V_2 -> V_815 -> V_852 . V_856 = V_857 * V_107 ;
V_2 -> V_815 -> V_852 . V_722 = V_722 ;
V_2 -> V_815 -> V_852 . V_849 = V_849 ;
return 0 ;
}
static int F_367 ( struct V_803 * V_804 ,
int V_479 , unsigned short V_849 , void * V_193 ,
unsigned int V_722 )
{
struct V_1 * V_2 = F_332 ( V_804 ) ;
int V_108 ;
if ( V_2 -> V_5 . V_846 . V_722 )
goto V_858;
V_108 = F_366 ( V_2 , V_479 , V_849 , V_193 , V_722 , true ) ;
if ( V_108 ) {
V_858:
memcpy ( V_193 , V_2 -> V_5 . V_850 , V_479 * V_722 ) ;
F_368 ( V_859 , V_849 , V_479 , V_722 , V_2 -> V_5 . V_850 ) ;
V_2 -> V_5 . V_846 . V_722 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_369 ( struct V_803 * V_804 ,
int V_479 , unsigned short V_849 ,
const void * V_193 , unsigned int V_722 )
{
struct V_1 * V_2 = F_332 ( V_804 ) ;
memcpy ( V_2 -> V_5 . V_850 , V_193 , V_479 * V_722 ) ;
F_368 ( V_860 , V_849 , V_479 , V_722 , V_2 -> V_5 . V_850 ) ;
return F_366 ( V_2 , V_479 , V_849 , ( void * ) V_193 , V_722 , false ) ;
}
static unsigned long F_370 ( struct V_1 * V_2 , int V_791 )
{
return V_73 -> F_370 ( V_2 , V_791 ) ;
}
static void F_371 ( struct V_803 * V_804 , V_173 V_80 )
{
F_372 ( F_332 ( V_804 ) , V_80 ) ;
}
int F_373 ( struct V_1 * V_2 )
{
if ( ! F_229 ( V_2 ) )
return V_799 ;
if ( V_73 -> V_567 () ) {
int V_23 = F_374 () ;
F_232 ( V_23 , V_2 -> V_5 . V_568 ) ;
F_375 ( V_2 -> V_5 . V_568 ,
F_227 , NULL , 1 ) ;
F_376 () ;
F_377 ( V_2 -> V_5 . V_568 ) ;
} else
F_228 () ;
return V_799 ;
}
int F_378 ( struct V_1 * V_2 )
{
V_73 -> V_74 ( V_2 ) ;
return F_373 ( V_2 ) ;
}
static void F_379 ( struct V_803 * V_804 )
{
F_373 ( F_332 ( V_804 ) ) ;
}
static int F_380 ( struct V_803 * V_804 , int V_89 ,
unsigned long * V_632 )
{
return F_97 ( F_332 ( V_804 ) , V_89 , V_632 ) ;
}
static int F_381 ( struct V_803 * V_804 , int V_89 ,
unsigned long V_22 )
{
return F_95 ( F_332 ( V_804 ) , V_89 , V_22 ) ;
}
static T_2 F_382 ( T_2 V_861 , T_1 V_862 )
{
return ( V_861 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_862 ;
}
static unsigned long F_383 ( struct V_803 * V_804 , int V_863 )
{
struct V_1 * V_2 = F_332 ( V_804 ) ;
unsigned long V_22 ;
switch ( V_863 ) {
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
V_22 = F_76 ( V_2 ) ;
break;
case 8 :
V_22 = F_88 ( V_2 ) ;
break;
default:
F_384 ( L_19 , V_261 , V_863 ) ;
return 0 ;
}
return V_22 ;
}
static int F_385 ( struct V_803 * V_804 , int V_863 , V_173 V_193 )
{
struct V_1 * V_2 = F_332 ( V_804 ) ;
int V_864 = 0 ;
switch ( V_863 ) {
case 0 :
V_864 = F_60 ( V_2 , F_382 ( F_61 ( V_2 ) , V_193 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_79 = V_193 ;
break;
case 3 :
V_864 = F_82 ( V_2 , V_193 ) ;
break;
case 4 :
V_864 = F_75 ( V_2 , F_382 ( F_76 ( V_2 ) , V_193 ) ) ;
break;
case 8 :
V_864 = F_85 ( V_2 , V_193 ) ;
break;
default:
F_384 ( L_19 , V_261 , V_863 ) ;
V_864 = - 1 ;
}
return V_864 ;
}
static int F_386 ( struct V_803 * V_804 )
{
return V_73 -> V_88 ( F_332 ( V_804 ) ) ;
}
static void F_387 ( struct V_803 * V_804 , struct V_865 * V_866 )
{
V_73 -> V_867 ( F_332 ( V_804 ) , V_866 ) ;
}
static void F_388 ( struct V_803 * V_804 , struct V_865 * V_866 )
{
V_73 -> V_868 ( F_332 ( V_804 ) , V_866 ) ;
}
static void F_389 ( struct V_803 * V_804 , struct V_865 * V_866 )
{
V_73 -> V_869 ( F_332 ( V_804 ) , V_866 ) ;
}
static void F_390 ( struct V_803 * V_804 , struct V_865 * V_866 )
{
V_73 -> V_870 ( F_332 ( V_804 ) , V_866 ) ;
}
static unsigned long F_391 (
struct V_803 * V_804 , int V_791 )
{
return F_370 ( F_332 ( V_804 ) , V_791 ) ;
}
static bool F_392 ( struct V_803 * V_804 , V_842 * V_871 ,
struct V_872 * V_873 , T_1 * V_874 ,
int V_791 )
{
struct V_789 V_790 ;
F_324 ( F_332 ( V_804 ) , & V_790 , V_791 ) ;
* V_871 = V_790 . V_871 ;
if ( V_790 . V_875 ) {
memset ( V_873 , 0 , sizeof( * V_873 ) ) ;
return false ;
}
if ( V_790 . V_876 )
V_790 . V_877 >>= 12 ;
F_393 ( V_873 , V_790 . V_877 ) ;
F_394 ( V_873 , ( unsigned long ) V_790 . V_227 ) ;
#ifdef F_62
if ( V_874 )
* V_874 = V_790 . V_227 >> 32 ;
#endif
V_873 -> type = V_790 . type ;
V_873 -> V_575 = V_790 . V_575 ;
V_873 -> V_878 = V_790 . V_878 ;
V_873 -> V_879 = V_790 . V_880 ;
V_873 -> V_881 = V_790 . V_881 ;
V_873 -> V_882 = V_790 . V_882 ;
V_873 -> V_883 = V_790 . V_180 ;
V_873 -> V_876 = V_790 . V_876 ;
return true ;
}
static void F_395 ( struct V_803 * V_804 , V_842 V_871 ,
struct V_872 * V_873 , T_1 V_874 ,
int V_791 )
{
struct V_1 * V_2 = F_332 ( V_804 ) ;
struct V_789 V_790 ;
V_790 . V_871 = V_871 ;
V_790 . V_227 = F_396 ( V_873 ) ;
#ifdef F_62
V_790 . V_227 |= ( ( T_2 ) V_874 ) << 32 ;
#endif
V_790 . V_877 = F_397 ( V_873 ) ;
if ( V_873 -> V_876 )
V_790 . V_877 = ( V_790 . V_877 << 12 ) | 0xfff ;
V_790 . type = V_873 -> type ;
V_790 . V_878 = V_873 -> V_878 ;
V_790 . V_180 = V_873 -> V_883 ;
V_790 . V_575 = V_873 -> V_575 ;
V_790 . V_882 = V_873 -> V_882 ;
V_790 . V_876 = V_873 -> V_876 ;
V_790 . V_881 = V_873 -> V_881 ;
V_790 . V_880 = V_873 -> V_879 ;
V_790 . V_875 = ! V_790 . V_880 ;
V_790 . V_884 = 0 ;
F_323 ( V_2 , & V_790 , V_791 ) ;
return;
}
static int F_398 ( struct V_803 * V_804 ,
T_1 V_885 , T_2 * V_452 )
{
struct V_32 V_21 ;
int V_120 ;
V_21 . V_145 = V_885 ;
V_21 . V_40 = false ;
V_120 = F_111 ( F_332 ( V_804 ) , & V_21 ) ;
if ( V_120 )
return V_120 ;
* V_452 = V_21 . V_38 ;
return 0 ;
}
static int F_399 ( struct V_803 * V_804 ,
T_1 V_885 , T_2 V_38 )
{
struct V_32 V_21 ;
V_21 . V_38 = V_38 ;
V_21 . V_145 = V_885 ;
V_21 . V_40 = false ;
return F_107 ( F_332 ( V_804 ) , & V_21 ) ;
}
static T_2 F_400 ( struct V_803 * V_804 )
{
struct V_1 * V_2 = F_332 ( V_804 ) ;
return V_2 -> V_5 . V_415 ;
}
static void F_401 ( struct V_803 * V_804 , T_2 V_415 )
{
struct V_1 * V_2 = F_332 ( V_804 ) ;
V_2 -> V_5 . V_415 = V_415 ;
}
static int F_402 ( struct V_803 * V_804 ,
T_1 V_886 )
{
return F_403 ( F_332 ( V_804 ) , V_886 ) ;
}
static int F_404 ( struct V_803 * V_804 ,
T_1 V_886 , T_2 * V_452 )
{
return F_100 ( F_332 ( V_804 ) , V_886 , V_452 ) ;
}
static void F_405 ( struct V_803 * V_804 )
{
F_332 ( V_804 ) -> V_5 . V_887 = 1 ;
}
static void F_406 ( struct V_803 * V_804 )
{
F_201 () ;
F_407 ( F_332 ( V_804 ) ) ;
F_408 () ;
}
static void F_409 ( struct V_803 * V_804 )
{
F_202 () ;
}
static int F_410 ( struct V_803 * V_804 ,
struct V_888 * V_889 ,
enum V_890 V_891 )
{
return V_73 -> V_892 ( F_332 ( V_804 ) , V_889 , V_891 ) ;
}
static void F_411 ( struct V_803 * V_804 ,
T_1 * V_893 , T_1 * V_894 , T_1 * V_198 , T_1 * V_206 )
{
V_670 ( F_332 ( V_804 ) , V_893 , V_894 , V_198 , V_206 ) ;
}
static V_173 F_412 ( struct V_803 * V_804 , unsigned V_895 )
{
return F_99 ( F_332 ( V_804 ) , V_895 ) ;
}
static void F_413 ( struct V_803 * V_804 , unsigned V_895 , V_173 V_193 )
{
F_101 ( F_332 ( V_804 ) , V_895 , V_193 ) ;
}
static void F_414 ( struct V_803 * V_804 , bool V_610 )
{
V_73 -> V_626 ( F_332 ( V_804 ) , V_610 ) ;
}
static void F_415 ( struct V_1 * V_2 , T_1 V_28 )
{
T_1 V_896 = V_73 -> V_606 ( V_2 ) ;
if ( V_896 & V_28 )
V_28 = 0 ;
if ( F_152 ( V_896 || V_28 ) ) {
V_73 -> V_625 ( V_2 , V_28 ) ;
if ( ! V_28 )
F_30 ( V_67 , V_2 ) ;
}
}
static bool F_416 ( struct V_1 * V_2 )
{
struct V_803 * V_804 = & V_2 -> V_5 . V_897 ;
if ( V_804 -> V_68 . V_41 == V_42 )
return F_38 ( V_2 , & V_804 -> V_68 ) ;
if ( V_804 -> V_68 . V_898 )
F_37 ( V_2 , V_804 -> V_68 . V_41 ,
V_804 -> V_68 . V_62 ) ;
else
F_32 ( V_2 , V_804 -> V_68 . V_41 ) ;
return false ;
}
static void F_417 ( struct V_1 * V_2 )
{
struct V_803 * V_804 = & V_2 -> V_5 . V_897 ;
int V_133 , V_134 ;
V_73 -> V_135 ( V_2 , & V_133 , & V_134 ) ;
V_804 -> V_899 = F_418 ( V_2 ) ;
V_804 -> V_900 = F_419 ( V_2 ) ;
V_804 -> V_318 = ( ! F_31 ( V_2 ) ) ? V_901 :
( V_804 -> V_899 & V_902 ) ? V_903 :
( V_134 && F_56 ( V_2 ) ) ? V_826 :
V_133 ? V_904 :
V_905 ;
F_169 ( V_906 != V_907 ) ;
F_169 ( V_627 != V_908 ) ;
F_169 ( V_618 != V_909 ) ;
V_804 -> V_910 = V_2 -> V_5 . V_617 ;
F_420 ( V_804 ) ;
V_2 -> V_5 . V_911 = false ;
}
int F_421 ( struct V_1 * V_2 , int V_580 , int V_912 )
{
struct V_803 * V_804 = & V_2 -> V_5 . V_897 ;
int V_108 ;
F_417 ( V_2 ) ;
V_804 -> V_913 = 2 ;
V_804 -> V_914 = 2 ;
V_804 -> V_915 = V_804 -> V_900 + V_912 ;
V_108 = F_422 ( V_804 , V_580 ) ;
if ( V_108 != V_799 )
return V_916 ;
V_804 -> V_900 = V_804 -> V_915 ;
F_423 ( V_2 , V_804 -> V_900 ) ;
F_424 ( V_2 , V_804 -> V_899 ) ;
if ( V_580 == V_51 )
V_2 -> V_5 . V_609 = 0 ;
else
V_2 -> V_5 . V_603 . V_69 = false ;
return V_917 ;
}
static int F_425 ( struct V_1 * V_2 )
{
int V_120 = V_917 ;
++ V_2 -> V_77 . V_918 ;
F_426 ( V_2 ) ;
if ( ! F_427 ( V_2 ) && V_73 -> V_88 ( V_2 ) == 0 ) {
V_2 -> V_815 -> V_831 = V_919 ;
V_2 -> V_815 -> V_920 . V_921 = V_922 ;
V_2 -> V_815 -> V_920 . V_923 = 0 ;
V_120 = V_916 ;
}
F_32 ( V_2 , V_91 ) ;
return V_120 ;
}
static bool F_428 ( struct V_1 * V_2 , T_16 V_79 ,
bool V_924 ,
int V_925 )
{
T_6 V_379 = V_79 ;
T_17 V_926 ;
if ( V_925 & V_927 )
return false ;
if ( ! V_2 -> V_5 . V_84 . V_928 ) {
V_379 = F_328 ( V_2 , V_79 , NULL ) ;
if ( V_379 == V_100 )
return true ;
}
V_926 = F_429 ( V_2 -> V_138 , F_48 ( V_379 ) ) ;
if ( F_430 ( V_926 ) )
return false ;
F_431 ( V_926 ) ;
if ( V_2 -> V_5 . V_84 . V_928 ) {
unsigned int V_929 ;
F_144 ( & V_2 -> V_138 -> V_930 ) ;
V_929 = V_2 -> V_138 -> V_5 . V_929 ;
F_145 ( & V_2 -> V_138 -> V_930 ) ;
if ( V_929 )
F_432 ( V_2 -> V_138 , F_48 ( V_379 ) ) ;
return true ;
}
F_432 ( V_2 -> V_138 , F_48 ( V_379 ) ) ;
return ! V_924 ;
}
static bool F_433 ( struct V_803 * V_804 ,
unsigned long V_79 , int V_925 )
{
struct V_1 * V_2 = F_332 ( V_804 ) ;
unsigned long V_931 , V_932 , V_379 = V_79 ;
V_931 = V_2 -> V_5 . V_931 ;
V_932 = V_2 -> V_5 . V_932 ;
V_2 -> V_5 . V_931 = V_2 -> V_5 . V_932 = 0 ;
if ( ! ( V_925 & V_933 ) )
return false ;
if ( F_434 ( V_804 ) )
return false ;
if ( V_804 -> V_900 == V_931 && V_932 == V_79 )
return false ;
V_2 -> V_5 . V_931 = V_804 -> V_900 ;
V_2 -> V_5 . V_932 = V_79 ;
if ( ! V_2 -> V_5 . V_84 . V_928 )
V_379 = F_328 ( V_2 , V_79 , NULL ) ;
F_432 ( V_2 -> V_138 , F_48 ( V_379 ) ) ;
return true ;
}
static void F_435 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_617 & V_627 ) ) {
F_436 ( V_2 -> V_289 , V_2 -> V_5 . V_415 , false ) ;
if ( F_152 ( V_2 -> V_5 . V_615 ) ) {
F_30 ( V_583 , V_2 ) ;
V_2 -> V_5 . V_615 = 0 ;
} else {
F_30 ( V_67 , V_2 ) ;
}
}
F_65 ( V_2 ) ;
}
static void F_437 ( struct V_1 * V_2 , unsigned V_910 )
{
unsigned V_119 = V_2 -> V_5 . V_617 ^ V_910 ;
V_2 -> V_5 . V_617 = V_910 ;
if ( V_119 & V_627 )
F_435 ( V_2 ) ;
}
static int F_438 ( unsigned long V_597 , T_1 type , T_1 V_185 ,
unsigned long * V_180 )
{
T_1 V_184 = 0 ;
int V_3 ;
T_1 V_934 , V_935 ;
V_934 = V_185 ;
V_935 = V_185 >> 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ , V_934 >>= 2 , V_935 >>= 4 )
if ( ( V_934 & 3 ) && ( V_935 & 15 ) == type && V_180 [ V_3 ] == V_597 )
V_184 |= ( 1 << V_3 ) ;
return V_184 ;
}
static void F_439 ( struct V_1 * V_2 , unsigned long V_936 , int * V_120 )
{
struct V_937 * V_937 = V_2 -> V_815 ;
if ( F_152 ( V_936 & V_938 ) ) {
if ( V_2 -> V_176 & V_939 ) {
V_937 -> V_940 . V_5 . V_184 = V_941 | V_191 |
V_192 ;
V_937 -> V_940 . V_5 . V_942 = V_2 -> V_5 . V_943 ;
V_937 -> V_940 . V_5 . V_68 = V_53 ;
V_937 -> V_831 = V_944 ;
* V_120 = V_945 ;
} else {
V_2 -> V_5 . V_897 . V_899 &= ~ V_938 ;
V_2 -> V_5 . V_184 &= ~ 15 ;
V_2 -> V_5 . V_184 |= V_941 | V_192 ;
F_32 ( V_2 , V_53 ) ;
}
}
}
static bool F_440 ( struct V_1 * V_2 , int * V_120 )
{
if ( F_152 ( V_2 -> V_176 & V_177 ) &&
( V_2 -> V_5 . V_186 & V_189 ) ) {
struct V_937 * V_937 = V_2 -> V_815 ;
unsigned long V_900 = F_441 ( V_2 ) ;
T_1 V_184 = F_438 ( V_900 , 0 ,
V_2 -> V_5 . V_186 ,
V_2 -> V_5 . V_179 ) ;
if ( V_184 != 0 ) {
V_937 -> V_940 . V_5 . V_184 = V_184 | V_191 | V_192 ;
V_937 -> V_940 . V_5 . V_942 = V_900 ;
V_937 -> V_940 . V_5 . V_68 = V_53 ;
V_937 -> V_831 = V_944 ;
* V_120 = V_945 ;
return true ;
}
}
if ( F_152 ( V_2 -> V_5 . V_185 & V_189 ) &&
! ( F_418 ( V_2 ) & V_946 ) ) {
unsigned long V_900 = F_441 ( V_2 ) ;
T_1 V_184 = F_438 ( V_900 , 0 ,
V_2 -> V_5 . V_185 ,
V_2 -> V_5 . V_180 ) ;
if ( V_184 != 0 ) {
V_2 -> V_5 . V_184 &= ~ 15 ;
V_2 -> V_5 . V_184 |= V_184 | V_192 ;
F_32 ( V_2 , V_53 ) ;
* V_120 = V_917 ;
return true ;
}
}
return false ;
}
int F_442 ( struct V_1 * V_2 ,
unsigned long V_79 ,
int V_925 ,
void * V_947 ,
int V_948 )
{
int V_120 ;
struct V_803 * V_804 = & V_2 -> V_5 . V_897 ;
bool V_477 = true ;
bool V_949 = V_2 -> V_5 . V_924 ;
V_2 -> V_5 . V_924 = false ;
F_443 ( V_2 ) ;
if ( ! ( V_925 & V_950 ) ) {
F_417 ( V_2 ) ;
if ( F_440 ( V_2 , & V_120 ) )
return V_120 ;
V_804 -> V_951 = 0 ;
V_804 -> V_952 = false ;
V_804 -> V_68 . V_41 = - 1 ;
V_804 -> V_953 = false ;
V_804 -> V_954 = V_925 & V_955 ;
V_120 = F_444 ( V_804 , V_947 , V_948 ) ;
F_445 ( V_2 ) ;
++ V_2 -> V_77 . V_956 ;
if ( V_120 != V_957 ) {
if ( V_925 & V_955 )
return V_916 ;
if ( F_428 ( V_2 , V_79 , V_949 ,
V_925 ) )
return V_917 ;
if ( V_925 & V_958 )
return V_916 ;
return F_425 ( V_2 ) ;
}
}
if ( V_925 & V_958 ) {
F_423 ( V_2 , V_804 -> V_915 ) ;
if ( V_804 -> V_899 & V_946 )
F_424 ( V_2 , V_804 -> V_899 & ~ V_946 ) ;
return V_917 ;
}
if ( F_433 ( V_804 , V_79 , V_925 ) )
return V_917 ;
if ( V_2 -> V_5 . V_911 ) {
V_2 -> V_5 . V_911 = false ;
F_446 ( V_804 ) ;
}
V_959:
V_120 = F_447 ( V_804 ) ;
if ( V_120 == V_960 )
return V_917 ;
if ( V_120 == V_961 ) {
if ( F_428 ( V_2 , V_79 , V_949 ,
V_925 ) )
return V_917 ;
return F_425 ( V_2 ) ;
}
if ( V_804 -> V_952 ) {
V_120 = V_917 ;
if ( F_416 ( V_2 ) )
return V_120 ;
} else if ( V_2 -> V_5 . V_846 . V_722 ) {
if ( ! V_2 -> V_5 . V_846 . V_847 ) {
V_2 -> V_5 . V_846 . V_722 = 0 ;
} else {
V_477 = false ;
V_2 -> V_5 . V_962 = V_963 ;
}
V_120 = V_945 ;
} else if ( V_2 -> V_827 ) {
if ( ! V_2 -> V_830 )
V_477 = false ;
V_120 = V_945 ;
V_2 -> V_5 . V_962 = V_964 ;
} else if ( V_120 == V_965 )
goto V_959;
else
V_120 = V_917 ;
if ( V_477 ) {
unsigned long V_936 = V_73 -> V_966 ( V_2 ) ;
F_415 ( V_2 , V_804 -> V_951 ) ;
V_2 -> V_5 . V_967 = false ;
if ( V_2 -> V_5 . V_617 != V_804 -> V_910 )
F_437 ( V_2 , V_804 -> V_910 ) ;
F_423 ( V_2 , V_804 -> V_900 ) ;
if ( V_120 == V_917 )
F_439 ( V_2 , V_936 , & V_120 ) ;
if ( ! V_804 -> V_952 ||
F_27 ( V_804 -> V_68 . V_41 ) == V_56 )
F_448 ( V_2 , V_804 -> V_899 ) ;
if ( F_152 ( ( V_804 -> V_899 & ~ V_936 ) & V_968 ) )
F_30 ( V_67 , V_2 ) ;
} else
V_2 -> V_5 . V_967 = true ;
return V_120 ;
}
int F_449 ( struct V_1 * V_2 , int V_479 , unsigned short V_849 )
{
unsigned long V_193 = F_99 ( V_2 , V_200 ) ;
int V_108 = F_369 ( & V_2 -> V_5 . V_897 ,
V_479 , V_849 , & V_193 , 1 ) ;
V_2 -> V_5 . V_846 . V_722 = 0 ;
return V_108 ;
}
static void F_450 ( void * V_889 )
{
F_451 ( V_334 , 0 ) ;
}
static void F_452 ( void * V_38 )
{
struct V_969 * V_970 = V_38 ;
unsigned long V_264 = 0 ;
if ( V_38 )
V_264 = V_970 -> V_838 ;
else if ( ! F_453 ( V_971 ) )
V_264 = F_454 ( F_455 () ) ;
if ( ! V_264 )
V_264 = V_273 ;
F_451 ( V_334 , V_264 ) ;
}
static int F_456 ( struct V_972 * V_973 , unsigned long V_193 ,
void * V_38 )
{
struct V_969 * V_970 = V_38 ;
struct V_138 * V_138 ;
struct V_1 * V_2 ;
int V_3 , V_974 = 0 ;
if ( V_193 == V_975 && V_970 -> V_837 > V_970 -> V_838 )
return 0 ;
if ( V_193 == V_976 && V_970 -> V_837 < V_970 -> V_838 )
return 0 ;
F_233 ( V_970 -> V_23 , F_452 , V_970 , 1 ) ;
F_144 ( & V_977 ) ;
F_457 (kvm, &vm_list, vm_list) {
F_160 (i, vcpu, kvm) {
if ( V_2 -> V_23 != V_970 -> V_23 )
continue;
F_30 ( V_325 , V_2 ) ;
if ( V_2 -> V_23 != F_8 () )
V_974 = 1 ;
}
}
F_145 ( & V_977 ) ;
if ( V_970 -> V_837 < V_970 -> V_838 && V_974 ) {
F_233 ( V_970 -> V_23 , F_452 , V_970 , 1 ) ;
}
return 0 ;
}
static int F_458 ( struct V_972 * V_978 ,
unsigned long V_979 , void * V_980 )
{
unsigned int V_23 = ( unsigned long ) V_980 ;
switch ( V_979 ) {
case V_981 :
case V_982 :
F_233 ( V_23 , F_452 , NULL , 1 ) ;
break;
case V_983 :
F_233 ( V_23 , F_450 , NULL , 1 ) ;
break;
}
return V_984 ;
}
static void F_459 ( void )
{
int V_23 ;
V_985 = V_273 ;
F_460 () ;
if ( ! F_453 ( V_971 ) ) {
#ifdef F_461
struct V_986 V_987 ;
memset ( & V_987 , 0 , sizeof( V_987 ) ) ;
V_23 = F_374 () ;
F_462 ( & V_987 , V_23 ) ;
if ( V_987 . V_988 . V_989 )
V_985 = V_987 . V_988 . V_989 ;
F_376 () ;
#endif
F_463 ( & V_990 ,
V_991 ) ;
}
F_127 ( L_20 , V_985 ) ;
F_464 (cpu)
F_233 ( V_23 , F_452 , NULL , 1 ) ;
F_465 ( & V_992 ) ;
F_466 () ;
}
int F_467 ( void )
{
return F_164 ( V_993 ) != NULL ;
}
static int F_468 ( void )
{
int V_994 = 3 ;
if ( F_164 ( V_993 ) )
V_994 = V_73 -> V_88 ( F_164 ( V_993 ) ) ;
return V_994 != 0 ;
}
static unsigned long F_469 ( void )
{
unsigned long V_995 = 0 ;
if ( F_164 ( V_993 ) )
V_995 = F_419 ( F_164 ( V_993 ) ) ;
return V_995 ;
}
void F_470 ( struct V_1 * V_2 )
{
F_451 ( V_993 , V_2 ) ;
}
void F_471 ( struct V_1 * V_2 )
{
F_451 ( V_993 , NULL ) ;
}
static void F_472 ( void )
{
T_2 V_28 ;
int V_996 = V_997 . V_998 ;
V_28 = F_473 ( V_996 , 51 ) ;
V_28 |= 0x3ull << 62 ;
V_28 |= 1ull ;
#ifdef F_62
if ( V_996 == 52 )
V_28 &= ~ 1ull ;
#endif
F_474 ( V_28 ) ;
}
static void F_475 ( struct V_347 * V_348 )
{
struct V_138 * V_138 ;
struct V_1 * V_2 ;
int V_3 ;
F_144 ( & V_977 ) ;
F_457 (kvm, &vm_list, vm_list)
F_160 (i, vcpu, kvm)
F_30 ( V_288 , V_2 ) ;
F_156 ( & V_324 , 0 ) ;
F_145 ( & V_977 ) ;
}
static int F_476 ( struct V_972 * V_973 , unsigned long V_999 ,
void * V_1000 )
{
struct V_223 * V_283 = & V_223 ;
struct V_221 * V_222 = V_1000 ;
F_113 ( V_222 ) ;
if ( V_283 -> clock . V_230 != V_287 &&
F_135 ( & V_324 ) != 0 )
F_477 ( V_1001 , & V_1002 ) ;
return 0 ;
}
int F_478 ( void * V_1003 )
{
int V_120 ;
struct V_73 * V_818 = V_1003 ;
if ( V_73 ) {
F_10 ( V_26 L_21 ) ;
V_120 = - V_753 ;
goto V_113;
}
if ( ! V_818 -> V_1004 () ) {
F_10 ( V_26 L_22 ) ;
V_120 = - V_1005 ;
goto V_113;
}
if ( V_818 -> V_1006 () ) {
F_10 ( V_26 L_23 ) ;
V_120 = - V_1005 ;
goto V_113;
}
V_120 = - V_377 ;
V_25 = F_479 ( struct V_11 ) ;
if ( ! V_25 ) {
F_10 ( V_26 L_24 ) ;
goto V_113;
}
V_120 = F_480 () ;
if ( V_120 )
goto V_1007;
F_472 () ;
V_73 = V_818 ;
F_481 ( V_1008 , V_1009 ,
V_1010 , V_1011 , 0 ) ;
F_459 () ;
F_482 ( & V_1012 ) ;
if ( V_540 )
V_144 = F_483 ( V_142 ) ;
F_484 () ;
#ifdef F_62
F_485 ( & V_1013 ) ;
#endif
return 0 ;
V_1007:
F_486 ( V_25 ) ;
V_113:
return V_120 ;
}
void F_487 ( void )
{
F_488 ( & V_1012 ) ;
if ( ! F_453 ( V_971 ) )
F_489 ( & V_990 ,
V_991 ) ;
F_490 ( & V_992 ) ;
#ifdef F_62
F_491 ( & V_1013 ) ;
#endif
V_73 = NULL ;
F_492 () ;
F_486 ( V_25 ) ;
}
int F_493 ( struct V_1 * V_2 )
{
++ V_2 -> V_77 . V_1014 ;
if ( F_86 ( V_2 -> V_138 ) ) {
V_2 -> V_5 . V_1015 = V_1016 ;
return 1 ;
} else {
V_2 -> V_815 -> V_831 = V_1017 ;
return 0 ;
}
}
int F_494 ( struct V_1 * V_2 )
{
V_73 -> V_74 ( V_2 ) ;
return F_493 ( V_2 ) ;
}
static void F_495 ( struct V_138 * V_138 , unsigned long V_295 , int V_1018 )
{
struct V_1019 V_1020 ;
V_1020 . V_1021 = 0 ;
V_1020 . V_1022 = 0 ;
V_1020 . V_1023 = V_1018 ;
V_1020 . V_1024 = false ;
V_1020 . V_1025 = V_1026 ;
F_496 ( V_138 , NULL , & V_1020 , NULL ) ;
}
int F_497 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_1027 , V_1028 , V_1029 , V_1030 , V_108 ;
int V_1031 , V_120 = 1 ;
V_73 -> V_74 ( V_2 ) ;
if ( F_498 ( V_2 -> V_138 ) )
return F_499 ( V_2 ) ;
V_16 = F_99 ( V_2 , V_200 ) ;
V_1027 = F_99 ( V_2 , V_1032 ) ;
V_1028 = F_99 ( V_2 , V_199 ) ;
V_1029 = F_99 ( V_2 , V_201 ) ;
V_1030 = F_99 ( V_2 , V_1033 ) ;
F_500 ( V_16 , V_1027 , V_1028 , V_1029 , V_1030 ) ;
V_1031 = F_501 ( V_2 ) ;
if ( ! V_1031 ) {
V_16 &= 0xFFFFFFFF ;
V_1027 &= 0xFFFFFFFF ;
V_1028 &= 0xFFFFFFFF ;
V_1029 &= 0xFFFFFFFF ;
V_1030 &= 0xFFFFFFFF ;
}
if ( V_73 -> V_88 ( V_2 ) != 0 ) {
V_108 = - V_1034 ;
goto V_113;
}
switch ( V_16 ) {
case V_1035 :
V_108 = 0 ;
break;
case V_1036 :
F_495 ( V_2 -> V_138 , V_1027 , V_1028 ) ;
V_108 = 0 ;
break;
default:
V_108 = - V_1037 ;
break;
}
V_113:
if ( ! V_1031 )
V_108 = ( T_1 ) V_108 ;
F_101 ( V_2 , V_200 , V_108 ) ;
++ V_2 -> V_77 . V_1038 ;
return V_120 ;
}
static int F_502 ( struct V_803 * V_804 )
{
struct V_1 * V_2 = F_332 ( V_804 ) ;
char V_1039 [ 3 ] ;
unsigned long V_1040 = F_419 ( V_2 ) ;
V_73 -> V_1041 ( V_2 , V_1039 ) ;
return F_353 ( V_804 , V_1040 , V_1039 , 3 , NULL ) ;
}
static int F_503 ( struct V_1 * V_2 )
{
return ( ! F_86 ( V_2 -> V_138 ) && ! F_504 ( V_2 ) &&
V_2 -> V_815 -> V_1042 &&
F_505 ( V_2 ) ) ;
}
static void F_506 ( struct V_1 * V_2 )
{
struct V_937 * V_937 = V_2 -> V_815 ;
V_937 -> V_1043 = ( F_418 ( V_2 ) & V_968 ) != 0 ;
V_937 -> V_295 = F_253 ( V_2 ) ? V_1044 : 0 ;
V_937 -> V_174 = F_88 ( V_2 ) ;
V_937 -> V_31 = F_19 ( V_2 ) ;
if ( F_86 ( V_2 -> V_138 ) )
V_937 -> V_1045 = 1 ;
else
V_937 -> V_1045 =
F_505 ( V_2 ) &&
! F_504 ( V_2 ) &&
! F_507 ( V_2 ) ;
}
static void F_242 ( struct V_1 * V_2 )
{
int V_1046 , V_1047 ;
if ( ! V_73 -> F_242 )
return;
if ( ! V_2 -> V_5 . V_578 )
return;
if ( ! V_2 -> V_5 . V_578 -> V_679 )
V_1046 = F_508 ( V_2 ) ;
else
V_1046 = - 1 ;
if ( V_1046 != - 1 )
V_1046 >>= 4 ;
V_1047 = F_89 ( V_2 ) ;
V_73 -> F_242 ( V_2 , V_1047 , V_1046 ) ;
}
static int F_509 ( struct V_1 * V_2 , bool V_1048 )
{
int V_120 ;
if ( V_2 -> V_5 . V_68 . V_69 ) {
F_510 ( V_2 -> V_5 . V_68 . V_16 ,
V_2 -> V_5 . V_68 . V_71 ,
V_2 -> V_5 . V_68 . V_62 ) ;
if ( F_27 ( V_2 -> V_5 . V_68 . V_16 ) == V_60 )
F_448 ( V_2 , F_418 ( V_2 ) |
V_946 ) ;
if ( V_2 -> V_5 . V_68 . V_16 == V_53 &&
( V_2 -> V_5 . V_185 & V_1049 ) ) {
V_2 -> V_5 . V_185 &= ~ V_1049 ;
F_92 ( V_2 ) ;
}
V_73 -> V_1050 ( V_2 , V_2 -> V_5 . V_68 . V_16 ,
V_2 -> V_5 . V_68 . V_71 ,
V_2 -> V_5 . V_68 . V_62 ,
V_2 -> V_5 . V_68 . V_63 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_608 ) {
V_73 -> V_1051 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_603 . V_69 ) {
V_73 -> V_1052 ( V_2 ) ;
return 0 ;
}
if ( F_427 ( V_2 ) && V_73 -> V_1053 ) {
V_120 = V_73 -> V_1053 ( V_2 , V_1048 ) ;
if ( V_120 != 0 )
return V_120 ;
}
if ( V_2 -> V_5 . V_609 ) {
if ( V_73 -> V_1054 ( V_2 ) ) {
-- V_2 -> V_5 . V_609 ;
V_2 -> V_5 . V_608 = true ;
V_73 -> V_1051 ( V_2 ) ;
}
} else if ( F_511 ( V_2 ) ) {
if ( F_427 ( V_2 ) && V_73 -> V_1053 ) {
V_120 = V_73 -> V_1053 ( V_2 , V_1048 ) ;
if ( V_120 != 0 )
return V_120 ;
}
if ( V_73 -> V_1055 ( V_2 ) ) {
F_244 ( V_2 , F_512 ( V_2 ) ,
false ) ;
V_73 -> V_1052 ( V_2 ) ;
}
}
return 0 ;
}
static void F_251 ( struct V_1 * V_2 )
{
unsigned V_877 = 2 ;
if ( V_73 -> V_611 ( V_2 ) || V_2 -> V_5 . V_608 )
V_877 = 1 ;
V_2 -> V_5 . V_609 += F_513 ( & V_2 -> V_5 . V_85 , 0 ) ;
V_2 -> V_5 . V_609 = F_316 ( V_2 -> V_5 . V_609 , V_877 ) ;
F_30 ( V_67 , V_2 ) ;
}
static T_1 F_514 ( struct V_789 * V_791 )
{
T_1 V_295 = 0 ;
V_295 |= V_791 -> V_876 << 23 ;
V_295 |= V_791 -> V_180 << 22 ;
V_295 |= V_791 -> V_882 << 21 ;
V_295 |= V_791 -> V_881 << 20 ;
V_295 |= V_791 -> V_880 << 15 ;
V_295 |= V_791 -> V_878 << 13 ;
V_295 |= V_791 -> V_575 << 12 ;
V_295 |= V_791 -> type << 8 ;
return V_295 ;
}
static void F_515 ( struct V_1 * V_2 , char * V_1056 , int V_478 )
{
struct V_789 V_791 ;
int V_94 ;
F_324 ( V_2 , & V_791 , V_478 ) ;
F_516 ( T_1 , V_1056 , 0x7fa8 + V_478 * 4 , V_791 . V_871 ) ;
if ( V_478 < 3 )
V_94 = 0x7f84 + V_478 * 12 ;
else
V_94 = 0x7f2c + ( V_478 - 3 ) * 12 ;
F_516 ( T_1 , V_1056 , V_94 + 8 , V_791 . V_227 ) ;
F_516 ( T_1 , V_1056 , V_94 + 4 , V_791 . V_877 ) ;
F_516 ( T_1 , V_1056 , V_94 , F_514 ( & V_791 ) ) ;
}
static void F_517 ( struct V_1 * V_2 , char * V_1056 , int V_478 )
{
struct V_789 V_791 ;
int V_94 ;
V_842 V_295 ;
F_324 ( V_2 , & V_791 , V_478 ) ;
V_94 = 0x7e00 + V_478 * 16 ;
V_295 = F_514 ( & V_791 ) >> 8 ;
F_516 ( V_842 , V_1056 , V_94 , V_791 . V_871 ) ;
F_516 ( V_842 , V_1056 , V_94 + 2 , V_295 ) ;
F_516 ( T_1 , V_1056 , V_94 + 4 , V_791 . V_877 ) ;
F_516 ( T_2 , V_1056 , V_94 + 8 , V_791 . V_227 ) ;
}
static void F_518 ( struct V_1 * V_2 , char * V_1056 )
{
struct V_865 V_866 ;
struct V_789 V_791 ;
unsigned long V_193 ;
int V_3 ;
F_516 ( T_1 , V_1056 , 0x7ffc , F_61 ( V_2 ) ) ;
F_516 ( T_1 , V_1056 , 0x7ff8 , F_59 ( V_2 ) ) ;
F_516 ( T_1 , V_1056 , 0x7ff4 , F_418 ( V_2 ) ) ;
F_516 ( T_1 , V_1056 , 0x7ff0 , F_419 ( V_2 ) ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
F_516 ( T_1 , V_1056 , 0x7fd0 + V_3 * 4 , F_99 ( V_2 , V_3 ) ) ;
F_97 ( V_2 , 6 , & V_193 ) ;
F_516 ( T_1 , V_1056 , 0x7fcc , ( T_1 ) V_193 ) ;
F_97 ( V_2 , 7 , & V_193 ) ;
F_516 ( T_1 , V_1056 , 0x7fc8 , ( T_1 ) V_193 ) ;
F_324 ( V_2 , & V_791 , V_1057 ) ;
F_516 ( T_1 , V_1056 , 0x7fc4 , V_791 . V_871 ) ;
F_516 ( T_1 , V_1056 , 0x7f64 , V_791 . V_227 ) ;
F_516 ( T_1 , V_1056 , 0x7f60 , V_791 . V_877 ) ;
F_516 ( T_1 , V_1056 , 0x7f5c , F_514 ( & V_791 ) ) ;
F_324 ( V_2 , & V_791 , V_1058 ) ;
F_516 ( T_1 , V_1056 , 0x7fc0 , V_791 . V_871 ) ;
F_516 ( T_1 , V_1056 , 0x7f80 , V_791 . V_227 ) ;
F_516 ( T_1 , V_1056 , 0x7f7c , V_791 . V_877 ) ;
F_516 ( T_1 , V_1056 , 0x7f78 , F_514 ( & V_791 ) ) ;
V_73 -> V_867 ( V_2 , & V_866 ) ;
F_516 ( T_1 , V_1056 , 0x7f74 , V_866 . V_80 ) ;
F_516 ( T_1 , V_1056 , 0x7f70 , V_866 . V_479 ) ;
V_73 -> V_868 ( V_2 , & V_866 ) ;
F_516 ( T_1 , V_1056 , 0x7f58 , V_866 . V_80 ) ;
F_516 ( T_1 , V_1056 , 0x7f54 , V_866 . V_479 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_515 ( V_2 , V_1056 , V_3 ) ;
F_516 ( T_1 , V_1056 , 0x7f14 , F_76 ( V_2 ) ) ;
F_516 ( T_1 , V_1056 , 0x7efc , 0x00020000 ) ;
F_516 ( T_1 , V_1056 , 0x7ef8 , V_2 -> V_5 . V_415 ) ;
}
static void F_519 ( struct V_1 * V_2 , char * V_1056 )
{
#ifdef F_62
struct V_865 V_866 ;
struct V_789 V_791 ;
unsigned long V_193 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ )
F_516 ( T_2 , V_1056 , 0x7ff8 - V_3 * 8 , F_99 ( V_2 , V_3 ) ) ;
F_516 ( T_2 , V_1056 , 0x7f78 , F_419 ( V_2 ) ) ;
F_516 ( T_1 , V_1056 , 0x7f70 , F_418 ( V_2 ) ) ;
F_97 ( V_2 , 6 , & V_193 ) ;
F_516 ( T_2 , V_1056 , 0x7f68 , V_193 ) ;
F_97 ( V_2 , 7 , & V_193 ) ;
F_516 ( T_2 , V_1056 , 0x7f60 , V_193 ) ;
F_516 ( T_2 , V_1056 , 0x7f58 , F_61 ( V_2 ) ) ;
F_516 ( T_2 , V_1056 , 0x7f50 , F_59 ( V_2 ) ) ;
F_516 ( T_2 , V_1056 , 0x7f48 , F_76 ( V_2 ) ) ;
F_516 ( T_1 , V_1056 , 0x7f00 , V_2 -> V_5 . V_415 ) ;
F_516 ( T_1 , V_1056 , 0x7efc , 0x00020064 ) ;
F_516 ( T_2 , V_1056 , 0x7ed0 , V_2 -> V_5 . V_131 ) ;
F_324 ( V_2 , & V_791 , V_1057 ) ;
F_516 ( V_842 , V_1056 , 0x7e90 , V_791 . V_871 ) ;
F_516 ( V_842 , V_1056 , 0x7e92 , F_514 ( & V_791 ) >> 8 ) ;
F_516 ( T_1 , V_1056 , 0x7e94 , V_791 . V_877 ) ;
F_516 ( T_2 , V_1056 , 0x7e98 , V_791 . V_227 ) ;
V_73 -> V_868 ( V_2 , & V_866 ) ;
F_516 ( T_1 , V_1056 , 0x7e84 , V_866 . V_479 ) ;
F_516 ( T_2 , V_1056 , 0x7e88 , V_866 . V_80 ) ;
F_324 ( V_2 , & V_791 , V_1058 ) ;
F_516 ( V_842 , V_1056 , 0x7e70 , V_791 . V_871 ) ;
F_516 ( V_842 , V_1056 , 0x7e72 , F_514 ( & V_791 ) >> 8 ) ;
F_516 ( T_1 , V_1056 , 0x7e74 , V_791 . V_877 ) ;
F_516 ( T_2 , V_1056 , 0x7e78 , V_791 . V_227 ) ;
V_73 -> V_867 ( V_2 , & V_866 ) ;
F_516 ( T_1 , V_1056 , 0x7e64 , V_866 . V_479 ) ;
F_516 ( T_2 , V_1056 , 0x7e68 , V_866 . V_80 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_517 ( V_2 , V_1056 , V_3 ) ;
#else
F_520 ( 1 ) ;
#endif
}
static void F_521 ( struct V_1 * V_2 )
{
struct V_789 V_1059 , V_1060 ;
struct V_865 V_866 ;
char V_1056 [ 512 ] ;
T_1 V_121 ;
if ( F_253 ( V_2 ) ) {
V_2 -> V_5 . V_615 = true ;
return;
}
F_436 ( V_2 -> V_289 , V_2 -> V_5 . V_415 , true ) ;
V_2 -> V_5 . V_617 |= V_627 ;
memset ( V_1056 , 0 , 512 ) ;
if ( F_522 ( V_2 ) )
F_519 ( V_2 , V_1056 ) ;
else
F_518 ( V_2 , V_1056 ) ;
F_186 ( V_2 , V_2 -> V_5 . V_415 + 0xfe00 , V_1056 , sizeof( V_1056 ) ) ;
if ( V_73 -> V_611 ( V_2 ) )
V_2 -> V_5 . V_617 |= V_618 ;
else
V_73 -> V_626 ( V_2 , true ) ;
F_424 ( V_2 , V_1061 ) ;
F_423 ( V_2 , 0x8000 ) ;
V_121 = V_2 -> V_5 . V_121 & ~ ( V_130 | V_1062 | V_1063 | V_124 ) ;
V_73 -> V_137 ( V_2 , V_121 ) ;
V_2 -> V_5 . V_121 = V_121 ;
V_73 -> V_168 ( V_2 , 0 ) ;
V_866 . V_80 = V_866 . V_479 = 0 ;
V_73 -> V_870 ( V_2 , & V_866 ) ;
F_95 ( V_2 , 7 , V_196 ) ;
V_1059 . V_871 = ( V_2 -> V_5 . V_415 >> 4 ) & 0xffff ;
V_1059 . V_227 = V_2 -> V_5 . V_415 ;
V_1060 . V_871 = 0 ;
V_1060 . V_227 = 0 ;
V_1059 . V_877 = V_1060 . V_877 = 0xffffffff ;
V_1059 . type = V_1060 . type = 0x3 ;
V_1059 . V_878 = V_1060 . V_878 = 0 ;
V_1059 . V_180 = V_1060 . V_180 = 0 ;
V_1059 . V_575 = V_1060 . V_575 = 1 ;
V_1059 . V_882 = V_1060 . V_882 = 0 ;
V_1059 . V_876 = V_1060 . V_876 = 1 ;
V_1059 . V_881 = V_1060 . V_881 = 0 ;
V_1059 . V_880 = V_1060 . V_880 = 1 ;
V_1059 . V_875 = V_1060 . V_875 = 0 ;
V_1059 . V_884 = V_1060 . V_884 = 0 ;
F_323 ( V_2 , & V_1059 , V_1064 ) ;
F_323 ( V_2 , & V_1060 , V_1065 ) ;
F_323 ( V_2 , & V_1060 , V_1066 ) ;
F_323 ( V_2 , & V_1060 , V_1067 ) ;
F_323 ( V_2 , & V_1060 , V_1068 ) ;
F_323 ( V_2 , & V_1060 , V_1069 ) ;
if ( F_522 ( V_2 ) )
V_73 -> F_105 ( V_2 , 0 ) ;
F_73 ( V_2 ) ;
F_65 ( V_2 ) ;
}
static void F_523 ( struct V_1 * V_2 )
{
T_2 V_1070 [ 4 ] ;
T_1 V_1071 [ 8 ] ;
if ( ! F_524 ( V_2 -> V_5 . V_578 ) )
return;
memset ( V_1070 , 0 , 32 ) ;
memset ( V_1071 , 0 , 32 ) ;
F_525 ( V_2 , V_1070 , V_1071 ) ;
V_73 -> V_1072 ( V_2 , V_1070 ) ;
F_526 ( V_2 , V_1071 ) ;
}
static void F_527 ( struct V_1 * V_2 )
{
++ V_2 -> V_77 . V_1073 ;
V_73 -> V_1073 ( V_2 ) ;
}
void F_528 ( struct V_1 * V_2 )
{
struct V_375 * V_375 = NULL ;
if ( ! F_86 ( V_2 -> V_138 ) )
return;
if ( ! V_73 -> V_1074 )
return;
V_375 = F_529 ( V_2 -> V_138 , V_808 >> V_106 ) ;
if ( F_356 ( V_375 ) )
return;
V_73 -> V_1074 ( V_2 , F_530 ( V_375 ) ) ;
F_531 ( V_375 ) ;
}
void F_532 ( struct V_138 * V_138 ,
unsigned long V_80 )
{
if ( V_80 == F_533 ( V_138 , V_808 >> V_106 ) )
F_534 ( V_138 , V_1075 ) ;
}
static int F_535 ( struct V_1 * V_2 )
{
int V_120 ;
bool V_1048 = ! F_86 ( V_2 -> V_138 ) &&
V_2 -> V_815 -> V_1042 ;
bool V_1076 = false ;
if ( V_2 -> V_327 ) {
if ( F_536 ( V_1077 , V_2 ) )
F_537 ( V_2 ) ;
if ( F_536 ( V_1078 , V_2 ) )
F_538 ( V_2 ) ;
if ( F_536 ( V_288 , V_2 ) )
F_158 ( V_2 -> V_138 ) ;
if ( F_536 ( V_422 , V_2 ) )
F_177 ( V_2 ) ;
if ( F_536 ( V_325 , V_2 ) ) {
V_120 = F_162 ( V_2 ) ;
if ( F_152 ( V_120 ) )
goto V_113;
}
if ( F_536 ( V_1079 , V_2 ) )
F_83 ( V_2 ) ;
if ( F_536 ( V_170 , V_2 ) )
F_527 ( V_2 ) ;
if ( F_536 ( V_1080 , V_2 ) ) {
V_2 -> V_815 -> V_831 = V_1081 ;
V_120 = 0 ;
goto V_113;
}
if ( F_536 ( V_72 , V_2 ) ) {
V_2 -> V_815 -> V_831 = V_1082 ;
V_120 = 0 ;
goto V_113;
}
if ( F_536 ( V_1083 , V_2 ) ) {
V_2 -> V_1084 = 0 ;
V_73 -> V_1085 ( V_2 ) ;
}
if ( F_536 ( V_1086 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1087 = true ;
V_120 = 1 ;
goto V_113;
}
if ( F_536 ( V_427 , V_2 ) )
F_193 ( V_2 ) ;
if ( F_536 ( V_583 , V_2 ) )
F_521 ( V_2 ) ;
if ( F_536 ( V_86 , V_2 ) )
F_251 ( V_2 ) ;
if ( F_536 ( V_1088 , V_2 ) )
F_539 ( V_2 ) ;
if ( F_536 ( V_1089 , V_2 ) )
F_540 ( V_2 ) ;
if ( F_536 ( V_1090 , V_2 ) )
F_523 ( V_2 ) ;
if ( F_536 ( V_1075 , V_2 ) )
F_528 ( V_2 ) ;
if ( F_536 ( V_1091 , V_2 ) ) {
V_2 -> V_815 -> V_831 = V_1092 ;
V_2 -> V_815 -> V_1093 . type = V_1094 ;
V_120 = 0 ;
goto V_113;
}
}
if ( F_536 ( V_67 , V_2 ) || V_1048 ) {
F_541 ( V_2 ) ;
if ( V_2 -> V_5 . V_1015 == V_1095 ) {
V_120 = 1 ;
goto V_113;
}
if ( F_509 ( V_2 , V_1048 ) != 0 )
V_1076 = true ;
else if ( V_2 -> V_5 . V_609 )
V_73 -> V_1096 ( V_2 ) ;
else if ( F_511 ( V_2 ) || V_1048 )
V_73 -> V_1097 ( V_2 ) ;
if ( F_542 ( V_2 ) ) {
if ( V_73 -> V_1098 )
V_73 -> V_1098 ( V_2 ,
F_508 ( V_2 ) ) ;
F_242 ( V_2 ) ;
F_543 ( V_2 ) ;
}
}
V_120 = F_544 ( V_2 ) ;
if ( F_152 ( V_120 ) ) {
goto V_1099;
}
F_201 () ;
V_73 -> V_1100 ( V_2 ) ;
if ( V_2 -> V_1084 )
F_407 ( V_2 ) ;
F_69 ( V_2 ) ;
V_2 -> V_318 = V_1101 ;
F_218 ( & V_2 -> V_138 -> V_474 , V_2 -> V_1102 ) ;
F_545 () ;
F_310 () ;
if ( V_2 -> V_318 == V_1103 || V_2 -> V_327
|| F_546 () || F_547 ( V_386 ) ) {
V_2 -> V_318 = V_1104 ;
F_172 () ;
F_311 () ;
F_202 () ;
V_2 -> V_1102 = F_217 ( & V_2 -> V_138 -> V_474 ) ;
V_120 = 1 ;
goto V_1099;
}
if ( V_1076 )
F_548 ( V_2 -> V_23 ) ;
F_549 () ;
if ( F_152 ( V_2 -> V_5 . V_181 ) ) {
F_550 ( 0 , 7 ) ;
F_550 ( V_2 -> V_5 . V_179 [ 0 ] , 0 ) ;
F_550 ( V_2 -> V_5 . V_179 [ 1 ] , 1 ) ;
F_550 ( V_2 -> V_5 . V_179 [ 2 ] , 2 ) ;
F_550 ( V_2 -> V_5 . V_179 [ 3 ] , 3 ) ;
F_550 ( V_2 -> V_5 . V_184 , 6 ) ;
V_2 -> V_5 . V_181 &= ~ V_182 ;
}
F_551 ( V_2 -> V_289 ) ;
F_552 ( V_2 ) ;
V_73 -> V_815 ( V_2 ) ;
if ( F_152 ( V_2 -> V_5 . V_181 & V_1105 ) ) {
int V_3 ;
F_28 ( V_2 -> V_176 & V_177 ) ;
V_73 -> V_1106 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_178 ; V_3 ++ )
V_2 -> V_5 . V_179 [ V_3 ] = V_2 -> V_5 . V_180 [ V_3 ] ;
}
if ( F_553 () )
F_554 () ;
V_2 -> V_5 . V_312 = V_73 -> V_335 ( V_2 ,
F_166 () ) ;
V_2 -> V_318 = V_1104 ;
F_172 () ;
V_73 -> V_1107 ( V_2 ) ;
++ V_2 -> V_77 . V_1108 ;
F_555 () ;
F_556 () ;
F_202 () ;
V_2 -> V_1102 = F_217 ( & V_2 -> V_138 -> V_474 ) ;
if ( F_152 ( V_1109 == V_1110 ) ) {
unsigned long V_1040 = F_419 ( V_2 ) ;
F_557 ( V_1110 , ( void * ) V_1040 ) ;
}
if ( F_152 ( V_2 -> V_5 . V_1111 ) )
F_30 ( V_325 , V_2 ) ;
if ( V_2 -> V_5 . V_1112 )
F_558 ( V_2 ) ;
V_120 = V_73 -> V_1113 ( V_2 ) ;
return V_120 ;
V_1099:
V_73 -> V_1099 ( V_2 ) ;
if ( F_152 ( V_2 -> V_5 . V_1112 ) )
F_558 ( V_2 ) ;
V_113:
return V_120 ;
}
static inline int F_559 ( struct V_138 * V_138 , struct V_1 * V_2 )
{
if ( ! F_560 ( V_2 ) ) {
F_218 ( & V_138 -> V_474 , V_2 -> V_1102 ) ;
F_561 ( V_2 ) ;
V_2 -> V_1102 = F_217 ( & V_138 -> V_474 ) ;
if ( ! F_536 ( V_1114 , V_2 ) )
return 1 ;
}
F_541 ( V_2 ) ;
switch( V_2 -> V_5 . V_1015 ) {
case V_1016 :
V_2 -> V_5 . V_1115 . V_1116 = false ;
V_2 -> V_5 . V_1015 =
V_1117 ;
case V_1117 :
V_2 -> V_5 . V_6 . V_1087 = false ;
break;
case V_1095 :
break;
default:
return - V_1118 ;
break;
}
return 1 ;
}
static inline bool F_562 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_1015 == V_1117 &&
! V_2 -> V_5 . V_6 . V_1087 ) ;
}
static int F_563 ( struct V_1 * V_2 )
{
int V_120 ;
struct V_138 * V_138 = V_2 -> V_138 ;
V_2 -> V_1102 = F_217 ( & V_138 -> V_474 ) ;
for (; ; ) {
if ( F_562 ( V_2 ) )
V_120 = F_535 ( V_2 ) ;
else
V_120 = F_559 ( V_138 , V_2 ) ;
if ( V_120 <= 0 )
break;
F_161 ( V_237 , & V_2 -> V_327 ) ;
if ( F_564 ( V_2 ) )
F_565 ( V_2 ) ;
if ( F_503 ( V_2 ) ) {
V_120 = - V_1118 ;
V_2 -> V_815 -> V_831 = V_1119 ;
++ V_2 -> V_77 . V_1120 ;
break;
}
F_566 ( V_2 ) ;
if ( F_547 ( V_386 ) ) {
V_120 = - V_1118 ;
V_2 -> V_815 -> V_831 = V_1119 ;
++ V_2 -> V_77 . V_1121 ;
break;
}
if ( F_546 () ) {
F_218 ( & V_138 -> V_474 , V_2 -> V_1102 ) ;
F_567 () ;
V_2 -> V_1102 = F_217 ( & V_138 -> V_474 ) ;
}
}
F_218 ( & V_138 -> V_474 , V_2 -> V_1102 ) ;
return V_120 ;
}
static inline int F_568 ( struct V_1 * V_2 )
{
int V_120 ;
V_2 -> V_1102 = F_217 ( & V_2 -> V_138 -> V_474 ) ;
V_120 = F_569 ( V_2 , V_950 ) ;
F_218 ( & V_2 -> V_138 -> V_474 , V_2 -> V_1102 ) ;
if ( V_120 != V_917 )
return 0 ;
return 1 ;
}
static int V_963 ( struct V_1 * V_2 )
{
F_13 ( ! V_2 -> V_5 . V_846 . V_722 ) ;
return F_568 ( V_2 ) ;
}
static int V_964 ( struct V_1 * V_2 )
{
struct V_937 * V_815 = V_2 -> V_815 ;
struct V_813 * V_814 ;
unsigned V_95 ;
F_13 ( ! V_2 -> V_827 ) ;
V_814 = & V_2 -> V_810 [ V_2 -> V_828 ] ;
V_95 = F_316 ( 8u , V_814 -> V_95 ) ;
if ( ! V_2 -> V_830 )
memcpy ( V_814 -> V_38 , V_815 -> V_816 . V_38 , V_95 ) ;
if ( V_814 -> V_95 <= 8 ) {
V_814 ++ ;
V_2 -> V_828 ++ ;
} else {
V_814 -> V_38 += V_95 ;
V_814 -> V_379 += V_95 ;
V_814 -> V_95 -= V_95 ;
}
if ( V_2 -> V_828 >= V_2 -> V_821 ) {
V_2 -> V_827 = 0 ;
if ( V_2 -> V_830 )
return 1 ;
V_2 -> V_809 = 1 ;
return F_568 ( V_2 ) ;
}
V_815 -> V_831 = V_832 ;
V_815 -> V_816 . V_833 = V_814 -> V_379 ;
if ( V_2 -> V_830 )
memcpy ( V_815 -> V_816 . V_38 , V_814 -> V_38 , F_316 ( 8u , V_814 -> V_95 ) ) ;
V_815 -> V_816 . V_95 = F_316 ( 8u , V_814 -> V_95 ) ;
V_815 -> V_816 . V_829 = V_2 -> V_830 ;
V_2 -> V_5 . V_962 = V_964 ;
return 0 ;
}
int F_570 ( struct V_1 * V_2 , struct V_937 * V_937 )
{
struct V_1122 * V_1122 = & V_386 -> V_1123 . V_1122 ;
int V_120 ;
T_18 V_1124 ;
F_571 ( V_1122 ) ;
if ( V_2 -> V_1125 )
F_572 ( V_1126 , & V_2 -> V_1127 , & V_1124 ) ;
if ( F_152 ( V_2 -> V_5 . V_1015 == V_1128 ) ) {
F_561 ( V_2 ) ;
F_541 ( V_2 ) ;
F_161 ( V_1114 , & V_2 -> V_327 ) ;
V_120 = - V_1129 ;
goto V_113;
}
if ( ! F_86 ( V_2 -> V_138 ) ) {
if ( F_85 ( V_2 , V_937 -> V_174 ) != 0 ) {
V_120 = - V_565 ;
goto V_113;
}
}
if ( F_152 ( V_2 -> V_5 . V_962 ) ) {
int (* F_573)( struct V_1 * ) = V_2 -> V_5 . V_962 ;
V_2 -> V_5 . V_962 = NULL ;
V_120 = F_573 ( V_2 ) ;
if ( V_120 <= 0 )
goto V_113;
} else
F_28 ( V_2 -> V_5 . V_846 . V_722 || V_2 -> V_827 ) ;
V_120 = F_563 ( V_2 ) ;
V_113:
F_506 ( V_2 ) ;
if ( V_2 -> V_1125 )
F_572 ( V_1126 , & V_1124 , NULL ) ;
return V_120 ;
}
int F_574 ( struct V_1 * V_2 , struct V_1130 * V_577 )
{
if ( V_2 -> V_5 . V_967 ) {
F_575 ( & V_2 -> V_5 . V_897 ) ;
V_2 -> V_5 . V_967 = false ;
}
V_577 -> V_1131 = F_99 ( V_2 , V_200 ) ;
V_577 -> V_1132 = F_99 ( V_2 , V_1032 ) ;
V_577 -> V_1133 = F_99 ( V_2 , V_199 ) ;
V_577 -> V_1134 = F_99 ( V_2 , V_201 ) ;
V_577 -> V_1135 = F_99 ( V_2 , V_1033 ) ;
V_577 -> V_1136 = F_99 ( V_2 , V_1137 ) ;
V_577 -> V_1138 = F_99 ( V_2 , V_1139 ) ;
V_577 -> V_1140 = F_99 ( V_2 , V_1141 ) ;
#ifdef F_62
V_577 -> V_1142 = F_99 ( V_2 , V_1143 ) ;
V_577 -> V_1144 = F_99 ( V_2 , V_1145 ) ;
V_577 -> V_1146 = F_99 ( V_2 , V_1147 ) ;
V_577 -> V_1148 = F_99 ( V_2 , V_1149 ) ;
V_577 -> V_1150 = F_99 ( V_2 , V_1151 ) ;
V_577 -> V_1152 = F_99 ( V_2 , V_1153 ) ;
V_577 -> V_1154 = F_99 ( V_2 , V_1155 ) ;
V_577 -> V_1156 = F_99 ( V_2 , V_1157 ) ;
#endif
V_577 -> V_1040 = F_419 ( V_2 ) ;
V_577 -> V_936 = F_418 ( V_2 ) ;
return 0 ;
}
int F_576 ( struct V_1 * V_2 , struct V_1130 * V_577 )
{
V_2 -> V_5 . V_911 = true ;
V_2 -> V_5 . V_967 = false ;
F_101 ( V_2 , V_200 , V_577 -> V_1131 ) ;
F_101 ( V_2 , V_1032 , V_577 -> V_1132 ) ;
F_101 ( V_2 , V_199 , V_577 -> V_1133 ) ;
F_101 ( V_2 , V_201 , V_577 -> V_1134 ) ;
F_101 ( V_2 , V_1033 , V_577 -> V_1135 ) ;
F_101 ( V_2 , V_1137 , V_577 -> V_1136 ) ;
F_101 ( V_2 , V_1139 , V_577 -> V_1138 ) ;
F_101 ( V_2 , V_1141 , V_577 -> V_1140 ) ;
#ifdef F_62
F_101 ( V_2 , V_1143 , V_577 -> V_1142 ) ;
F_101 ( V_2 , V_1145 , V_577 -> V_1144 ) ;
F_101 ( V_2 , V_1147 , V_577 -> V_1146 ) ;
F_101 ( V_2 , V_1149 , V_577 -> V_1148 ) ;
F_101 ( V_2 , V_1151 , V_577 -> V_1150 ) ;
F_101 ( V_2 , V_1153 , V_577 -> V_1152 ) ;
F_101 ( V_2 , V_1155 , V_577 -> V_1154 ) ;
F_101 ( V_2 , V_1157 , V_577 -> V_1156 ) ;
#endif
F_423 ( V_2 , V_577 -> V_1040 ) ;
F_424 ( V_2 , V_577 -> V_936 ) ;
V_2 -> V_5 . V_68 . V_69 = false ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
void F_577 ( struct V_1 * V_2 , int * V_180 , int * V_882 )
{
struct V_789 V_1059 ;
F_324 ( V_2 , & V_1059 , V_1064 ) ;
* V_180 = V_1059 . V_180 ;
* V_882 = V_1059 . V_882 ;
}
int F_578 ( struct V_1 * V_2 ,
struct V_1158 * V_1159 )
{
struct V_865 V_866 ;
F_324 ( V_2 , & V_1159 -> V_1059 , V_1064 ) ;
F_324 ( V_2 , & V_1159 -> V_1060 , V_1065 ) ;
F_324 ( V_2 , & V_1159 -> V_1160 , V_1066 ) ;
F_324 ( V_2 , & V_1159 -> V_1161 , V_1067 ) ;
F_324 ( V_2 , & V_1159 -> V_1162 , V_1068 ) ;
F_324 ( V_2 , & V_1159 -> V_1163 , V_1069 ) ;
F_324 ( V_2 , & V_1159 -> V_1164 , V_1057 ) ;
F_324 ( V_2 , & V_1159 -> V_1165 , V_1058 ) ;
V_73 -> V_868 ( V_2 , & V_866 ) ;
V_1159 -> V_1166 . V_877 = V_866 . V_479 ;
V_1159 -> V_1166 . V_227 = V_866 . V_80 ;
V_73 -> V_867 ( V_2 , & V_866 ) ;
V_1159 -> V_1167 . V_877 = V_866 . V_479 ;
V_1159 -> V_1167 . V_227 = V_866 . V_80 ;
V_1159 -> V_121 = F_61 ( V_2 ) ;
V_1159 -> V_79 = V_2 -> V_5 . V_79 ;
V_1159 -> V_104 = F_59 ( V_2 ) ;
V_1159 -> V_157 = F_76 ( V_2 ) ;
V_1159 -> V_174 = F_88 ( V_2 ) ;
V_1159 -> V_131 = V_2 -> V_5 . V_131 ;
V_1159 -> V_31 = F_19 ( V_2 ) ;
memset ( V_1159 -> V_1168 , 0 , sizeof V_1159 -> V_1168 ) ;
if ( V_2 -> V_5 . V_603 . V_69 && ! V_2 -> V_5 . V_603 . V_604 )
F_199 ( V_2 -> V_5 . V_603 . V_16 ,
( unsigned long * ) V_1159 -> V_1168 ) ;
return 0 ;
}
int F_579 ( struct V_1 * V_2 ,
struct V_1169 * V_1015 )
{
F_541 ( V_2 ) ;
if ( V_2 -> V_5 . V_1015 == V_1016 &&
V_2 -> V_5 . V_1115 . V_1116 )
V_1015 -> V_1015 = V_1117 ;
else
V_1015 -> V_1015 = V_2 -> V_5 . V_1015 ;
return 0 ;
}
int F_580 ( struct V_1 * V_2 ,
struct V_1169 * V_1015 )
{
if ( ! F_256 ( V_2 ) &&
V_1015 -> V_1015 != V_1117 )
return - V_565 ;
if ( V_1015 -> V_1015 == V_1170 ) {
V_2 -> V_5 . V_1015 = V_1095 ;
F_199 ( V_1171 , & V_2 -> V_5 . V_578 -> V_629 ) ;
} else
V_2 -> V_5 . V_1015 = V_1015 -> V_1015 ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
int F_581 ( struct V_1 * V_2 , V_842 V_1172 , int V_1173 ,
int V_1174 , bool V_71 , T_1 V_62 )
{
struct V_803 * V_804 = & V_2 -> V_5 . V_897 ;
int V_108 ;
F_417 ( V_2 ) ;
V_108 = F_582 ( V_804 , V_1172 , V_1173 , V_1174 ,
V_71 , V_62 ) ;
if ( V_108 )
return V_916 ;
F_423 ( V_2 , V_804 -> V_900 ) ;
F_424 ( V_2 , V_804 -> V_899 ) ;
F_30 ( V_67 , V_2 ) ;
return V_917 ;
}
int F_583 ( struct V_1 * V_2 ,
struct V_1158 * V_1159 )
{
struct V_32 V_1175 ;
int V_1176 = 0 ;
int V_1177 , V_1178 , V_473 ;
struct V_865 V_866 ;
if ( ! F_77 ( V_2 ) && ( V_1159 -> V_157 & V_140 ) )
return - V_565 ;
V_866 . V_479 = V_1159 -> V_1166 . V_877 ;
V_866 . V_80 = V_1159 -> V_1166 . V_227 ;
V_73 -> V_870 ( V_2 , & V_866 ) ;
V_866 . V_479 = V_1159 -> V_1167 . V_877 ;
V_866 . V_80 = V_1159 -> V_1167 . V_227 ;
V_73 -> V_869 ( V_2 , & V_866 ) ;
V_2 -> V_5 . V_79 = V_1159 -> V_79 ;
V_1176 |= F_59 ( V_2 ) != V_1159 -> V_104 ;
V_2 -> V_5 . V_104 = V_1159 -> V_104 ;
F_54 ( V_172 , ( V_173 * ) & V_2 -> V_5 . V_117 ) ;
F_85 ( V_2 , V_1159 -> V_174 ) ;
V_1176 |= V_2 -> V_5 . V_131 != V_1159 -> V_131 ;
V_73 -> F_105 ( V_2 , V_1159 -> V_131 ) ;
V_1175 . V_38 = V_1159 -> V_31 ;
V_1175 . V_40 = true ;
F_20 ( V_2 , & V_1175 ) ;
V_1176 |= F_61 ( V_2 ) != V_1159 -> V_121 ;
V_73 -> V_137 ( V_2 , V_1159 -> V_121 ) ;
V_2 -> V_5 . V_121 = V_1159 -> V_121 ;
V_1176 |= F_76 ( V_2 ) != V_1159 -> V_157 ;
V_73 -> V_168 ( V_2 , V_1159 -> V_157 ) ;
if ( V_1159 -> V_157 & V_140 )
F_73 ( V_2 ) ;
V_473 = F_217 ( & V_2 -> V_138 -> V_474 ) ;
if ( ! F_56 ( V_2 ) && F_57 ( V_2 ) ) {
F_51 ( V_2 , V_2 -> V_5 . V_103 , F_59 ( V_2 ) ) ;
V_1176 = 1 ;
}
F_218 ( & V_2 -> V_138 -> V_474 , V_473 ) ;
if ( V_1176 )
F_65 ( V_2 ) ;
V_1178 = V_581 ;
V_1177 = F_584 (
( const unsigned long * ) V_1159 -> V_1168 , V_1178 ) ;
if ( V_1177 < V_1178 ) {
F_244 ( V_2 , V_1177 , false ) ;
F_127 ( L_25 , V_1177 ) ;
}
F_323 ( V_2 , & V_1159 -> V_1059 , V_1064 ) ;
F_323 ( V_2 , & V_1159 -> V_1060 , V_1065 ) ;
F_323 ( V_2 , & V_1159 -> V_1160 , V_1066 ) ;
F_323 ( V_2 , & V_1159 -> V_1161 , V_1067 ) ;
F_323 ( V_2 , & V_1159 -> V_1162 , V_1068 ) ;
F_323 ( V_2 , & V_1159 -> V_1163 , V_1069 ) ;
F_323 ( V_2 , & V_1159 -> V_1164 , V_1057 ) ;
F_323 ( V_2 , & V_1159 -> V_1165 , V_1058 ) ;
F_242 ( V_2 ) ;
if ( F_585 ( V_2 ) && F_419 ( V_2 ) == 0xfff0 &&
V_1159 -> V_1059 . V_871 == 0xf000 && V_1159 -> V_1059 . V_227 == 0xffff0000 &&
! F_31 ( V_2 ) )
V_2 -> V_5 . V_1015 = V_1117 ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
int F_586 ( struct V_1 * V_2 ,
struct V_1179 * V_1180 )
{
unsigned long V_936 ;
int V_3 , V_120 ;
if ( V_1180 -> V_729 & ( V_1181 | V_1182 ) ) {
V_120 = - V_771 ;
if ( V_2 -> V_5 . V_68 . V_69 )
goto V_113;
if ( V_1180 -> V_729 & V_1181 )
F_32 ( V_2 , V_53 ) ;
else
F_32 ( V_2 , V_54 ) ;
}
V_936 = F_418 ( V_2 ) ;
V_2 -> V_176 = V_1180 -> V_729 ;
if ( ! ( V_2 -> V_176 & V_1183 ) )
V_2 -> V_176 = 0 ;
if ( V_2 -> V_176 & V_177 ) {
for ( V_3 = 0 ; V_3 < V_178 ; ++ V_3 )
V_2 -> V_5 . V_179 [ V_3 ] = V_1180 -> V_5 . V_1184 [ V_3 ] ;
V_2 -> V_5 . V_186 = V_1180 -> V_5 . V_1184 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_178 ; V_3 ++ )
V_2 -> V_5 . V_179 [ V_3 ] = V_2 -> V_5 . V_180 [ V_3 ] ;
}
F_92 ( V_2 ) ;
if ( V_2 -> V_176 & V_939 )
V_2 -> V_5 . V_943 = F_419 ( V_2 ) +
F_370 ( V_2 , V_1064 ) ;
F_424 ( V_2 , V_936 ) ;
V_73 -> V_1185 ( V_2 ) ;
V_120 = 0 ;
V_113:
return V_120 ;
}
int F_587 ( struct V_1 * V_2 ,
struct V_1186 * V_1164 )
{
unsigned long V_1187 = V_1164 -> V_1188 ;
T_6 V_379 ;
int V_473 ;
V_473 = F_217 ( & V_2 -> V_138 -> V_474 ) ;
V_379 = F_329 ( V_2 , V_1187 , NULL ) ;
F_218 ( & V_2 -> V_138 -> V_474 , V_473 ) ;
V_1164 -> V_1189 = V_379 ;
V_1164 -> V_640 = V_379 != V_100 ;
V_1164 -> V_1190 = 1 ;
V_1164 -> V_1191 = 0 ;
return 0 ;
}
int F_588 ( struct V_1 * V_2 , struct V_1192 * V_1122 )
{
struct V_653 * V_652 =
& V_2 -> V_5 . V_635 . V_636 . V_652 ;
memcpy ( V_1122 -> V_1193 , V_652 -> V_1194 , 128 ) ;
V_1122 -> V_1195 = V_652 -> V_1196 ;
V_1122 -> V_1197 = V_652 -> V_1198 ;
V_1122 -> V_1199 = V_652 -> V_1200 ;
V_1122 -> V_1201 = V_652 -> V_1202 ;
V_1122 -> V_1203 = V_652 -> V_1040 ;
V_1122 -> V_1204 = V_652 -> V_1205 ;
memcpy ( V_1122 -> V_1206 , V_652 -> V_1207 , sizeof V_652 -> V_1207 ) ;
return 0 ;
}
int F_589 ( struct V_1 * V_2 , struct V_1192 * V_1122 )
{
struct V_653 * V_652 =
& V_2 -> V_5 . V_635 . V_636 . V_652 ;
memcpy ( V_652 -> V_1194 , V_1122 -> V_1193 , 128 ) ;
V_652 -> V_1196 = V_1122 -> V_1195 ;
V_652 -> V_1198 = V_1122 -> V_1197 ;
V_652 -> V_1200 = V_1122 -> V_1199 ;
V_652 -> V_1202 = V_1122 -> V_1201 ;
V_652 -> V_1040 = V_1122 -> V_1203 ;
V_652 -> V_1205 = V_1122 -> V_1204 ;
memcpy ( V_652 -> V_1207 , V_1122 -> V_1206 , sizeof V_652 -> V_1207 ) ;
return 0 ;
}
static void F_590 ( struct V_1 * V_2 )
{
F_591 ( & V_2 -> V_5 . V_635 . V_636 ) ;
if ( V_646 )
V_2 -> V_5 . V_635 . V_636 . V_634 . V_638 . V_647 =
V_144 | V_648 ;
V_2 -> V_5 . V_143 = V_149 ;
V_2 -> V_5 . V_121 |= V_126 ;
}
void F_407 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1208 )
return;
F_71 ( V_2 ) ;
V_2 -> V_1208 = 1 ;
F_592 () ;
F_593 ( & V_2 -> V_5 . V_635 . V_636 ) ;
F_594 ( 1 ) ;
}
void F_238 ( struct V_1 * V_2 )
{
F_71 ( V_2 ) ;
if ( ! V_2 -> V_1208 ) {
V_2 -> V_1209 = 0 ;
return;
}
V_2 -> V_1208 = 0 ;
F_595 ( & V_2 -> V_5 . V_635 ) ;
F_596 () ;
++ V_2 -> V_77 . V_1210 ;
if ( ! V_2 -> V_5 . V_1211 ) {
if ( ++ V_2 -> V_1209 < 5 )
F_30 ( V_1083 , V_2 ) ;
}
F_594 ( 0 ) ;
}
void F_597 ( struct V_1 * V_2 )
{
F_191 ( V_2 ) ;
F_598 ( V_2 -> V_5 . V_568 ) ;
V_73 -> V_1212 ( V_2 ) ;
}
struct V_1 * F_599 ( struct V_138 * V_138 ,
unsigned int V_1213 )
{
struct V_1 * V_2 ;
if ( F_141 () && F_135 ( & V_138 -> V_285 ) != 0 )
F_364 ( V_844
L_26
L_27 ) ;
V_2 = V_73 -> V_1214 ( V_138 , V_1213 ) ;
return V_2 ;
}
int F_600 ( struct V_1 * V_2 )
{
int V_120 ;
F_601 ( V_2 ) ;
V_120 = V_569 ( V_2 ) ;
if ( V_120 )
return V_120 ;
F_602 ( V_2 , false ) ;
F_603 ( V_2 ) ;
V_573 ( V_2 ) ;
return V_120 ;
}
void F_604 ( struct V_1 * V_2 )
{
struct V_32 V_21 ;
struct V_138 * V_138 = V_2 -> V_138 ;
if ( V_569 ( V_2 ) )
return;
V_21 . V_38 = 0x0 ;
V_21 . V_145 = V_1215 ;
V_21 . V_40 = true ;
F_138 ( V_2 , & V_21 ) ;
V_573 ( V_2 ) ;
if ( ! V_354 )
return;
F_178 ( & V_138 -> V_5 . V_353 ,
V_355 ) ;
}
void F_605 ( struct V_1 * V_2 )
{
int V_120 ;
V_2 -> V_5 . V_6 . V_380 = 0 ;
V_120 = V_569 ( V_2 ) ;
F_13 ( V_120 ) ;
F_537 ( V_2 ) ;
V_573 ( V_2 ) ;
V_73 -> V_1212 ( V_2 ) ;
}
void F_602 ( struct V_1 * V_2 , bool V_1216 )
{
V_2 -> V_5 . V_617 = 0 ;
F_156 ( & V_2 -> V_5 . V_85 , 0 ) ;
V_2 -> V_5 . V_609 = 0 ;
V_2 -> V_5 . V_608 = false ;
F_606 ( V_2 ) ;
F_443 ( V_2 ) ;
memset ( V_2 -> V_5 . V_180 , 0 , sizeof( V_2 -> V_5 . V_180 ) ) ;
F_90 ( V_2 ) ;
V_2 -> V_5 . V_184 = V_1217 ;
F_91 ( V_2 ) ;
V_2 -> V_5 . V_185 = V_196 ;
F_92 ( V_2 ) ;
V_2 -> V_5 . V_79 = 0 ;
F_30 ( V_67 , V_2 ) ;
V_2 -> V_5 . V_6 . V_380 = 0 ;
V_2 -> V_5 . V_384 . V_380 = 0 ;
F_191 ( V_2 ) ;
F_64 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1087 = false ;
if ( ! V_1216 ) {
F_607 ( V_2 ) ;
V_2 -> V_5 . V_415 = 0x30000 ;
}
memset ( V_2 -> V_5 . V_577 , 0 , sizeof( V_2 -> V_5 . V_577 ) ) ;
V_2 -> V_5 . V_117 = ~ 0 ;
V_2 -> V_5 . V_118 = ~ 0 ;
V_73 -> V_1218 ( V_2 , V_1216 ) ;
}
void F_608 ( struct V_1 * V_2 , T_14 V_41 )
{
struct V_789 V_1059 ;
F_324 ( V_2 , & V_1059 , V_1064 ) ;
V_1059 . V_871 = V_41 << 8 ;
V_1059 . V_227 = V_41 << 12 ;
F_323 ( V_2 , & V_1059 , V_1064 ) ;
F_423 ( V_2 , 0 ) ;
}
int F_609 ( void )
{
struct V_138 * V_138 ;
struct V_1 * V_2 ;
int V_3 ;
int V_108 ;
T_2 V_1219 ;
T_2 V_1220 = 0 ;
bool V_1221 , V_1222 = false ;
F_14 () ;
V_108 = V_73 -> V_1223 () ;
if ( V_108 != 0 )
return V_108 ;
V_1219 = F_166 () ;
V_1221 = ! F_141 () ;
F_457 (kvm, &vm_list, vm_list) {
F_160 (i, vcpu, kvm) {
if ( ! V_1221 && V_2 -> V_23 == F_8 () )
F_30 ( V_325 , V_2 ) ;
if ( V_1221 && V_2 -> V_5 . V_572 > V_1219 ) {
V_1222 = true ;
if ( V_2 -> V_5 . V_572 > V_1220 )
V_1220 = V_2 -> V_5 . V_572 ;
}
}
}
if ( V_1222 ) {
T_2 V_1224 = V_1220 - V_1219 ;
V_322 = true ;
F_457 (kvm, &vm_list, vm_list) {
F_160 (i, vcpu, kvm) {
V_2 -> V_5 . V_570 += V_1224 ;
V_2 -> V_5 . V_572 = V_1219 ;
F_30 ( V_288 , V_2 ) ;
}
V_138 -> V_5 . V_301 = 0 ;
V_138 -> V_5 . V_303 = 0 ;
}
}
return 0 ;
}
void F_610 ( void )
{
V_73 -> V_1225 () ;
F_18 () ;
}
int F_611 ( void )
{
int V_120 ;
V_120 = V_73 -> V_1226 () ;
if ( V_120 != 0 )
return V_120 ;
F_313 () ;
return 0 ;
}
void F_612 ( void )
{
V_73 -> V_1227 () ;
}
void F_613 ( void * V_1228 )
{
V_73 -> V_1229 ( V_1228 ) ;
}
bool F_614 ( struct V_1 * V_2 )
{
return V_2 -> V_138 -> V_5 . V_772 == V_2 -> V_289 ;
}
bool F_585 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_31 & V_1230 ) != 0 ;
}
bool F_615 ( struct V_1 * V_2 )
{
return F_86 ( V_2 -> V_138 ) == ( V_2 -> V_5 . V_578 != NULL ) ;
}
int F_616 ( struct V_1 * V_2 )
{
struct V_375 * V_375 ;
struct V_138 * V_138 ;
int V_120 ;
F_13 ( V_2 -> V_138 == NULL ) ;
V_138 = V_2 -> V_138 ;
V_2 -> V_5 . V_1115 . V_1116 = false ;
V_2 -> V_5 . V_897 . V_818 = & V_1231 ;
if ( ! F_86 ( V_138 ) || F_614 ( V_2 ) )
V_2 -> V_5 . V_1015 = V_1117 ;
else
V_2 -> V_5 . V_1015 = V_1128 ;
V_375 = F_617 ( V_664 | V_1232 ) ;
if ( ! V_375 ) {
V_120 = - V_377 ;
goto V_1233;
}
V_2 -> V_5 . V_850 = F_618 ( V_375 ) ;
F_132 ( V_2 , V_985 ) ;
V_120 = F_619 ( V_2 ) ;
if ( V_120 < 0 )
goto V_1234;
if ( F_86 ( V_138 ) ) {
V_120 = F_620 ( V_2 ) ;
if ( V_120 < 0 )
goto V_1235;
} else
F_621 ( & V_1236 ) ;
V_2 -> V_5 . V_364 = F_271 ( V_429 * sizeof( T_2 ) * 4 ,
V_664 ) ;
if ( ! V_2 -> V_5 . V_364 ) {
V_120 = - V_377 ;
goto V_1237;
}
V_2 -> V_5 . V_356 = V_429 ;
if ( ! F_622 ( & V_2 -> V_5 . V_568 , V_664 ) ) {
V_120 = - V_377 ;
goto V_1238;
}
F_590 ( V_2 ) ;
V_2 -> V_5 . V_292 = 0x0 ;
V_2 -> V_5 . V_337 = false ;
V_2 -> V_5 . V_152 = 0 ;
V_2 -> V_5 . V_1239 = V_1240 + V_641 ;
V_2 -> V_5 . V_996 = F_623 ( V_2 ) ;
V_2 -> V_5 . V_1241 = V_1242 ;
F_1 ( V_2 ) ;
F_624 ( V_2 ) ;
return 0 ;
V_1238:
F_187 ( V_2 -> V_5 . V_364 ) ;
V_1237:
F_625 ( V_2 ) ;
V_1235:
F_626 ( V_2 ) ;
V_1234:
F_627 ( ( unsigned long ) V_2 -> V_5 . V_850 ) ;
V_1233:
return V_120 ;
}
void F_628 ( struct V_1 * V_2 )
{
int V_473 ;
F_629 ( V_2 ) ;
F_187 ( V_2 -> V_5 . V_364 ) ;
F_625 ( V_2 ) ;
V_473 = F_217 ( & V_2 -> V_138 -> V_474 ) ;
F_626 ( V_2 ) ;
F_218 ( & V_2 -> V_138 -> V_474 , V_473 ) ;
F_627 ( ( unsigned long ) V_2 -> V_5 . V_850 ) ;
if ( ! F_86 ( V_2 -> V_138 ) )
F_630 ( & V_1236 ) ;
}
void F_631 ( struct V_1 * V_2 , int V_23 )
{
V_73 -> V_1243 ( V_2 , V_23 ) ;
}
int F_632 ( struct V_138 * V_138 , unsigned long type )
{
if ( type )
return - V_565 ;
F_633 ( & V_138 -> V_5 . V_1244 ) ;
F_634 ( & V_138 -> V_5 . V_1245 ) ;
F_634 ( & V_138 -> V_5 . V_1246 ) ;
F_634 ( & V_138 -> V_5 . V_1247 ) ;
F_156 ( & V_138 -> V_5 . V_1248 , 0 ) ;
F_199 ( V_737 , & V_138 -> V_5 . V_1249 ) ;
F_199 ( V_1250 ,
& V_138 -> V_5 . V_1249 ) ;
F_635 ( & V_138 -> V_5 . V_299 ) ;
F_636 ( & V_138 -> V_5 . V_1251 ) ;
F_637 ( & V_138 -> V_5 . V_314 ) ;
F_155 ( V_138 ) ;
F_638 ( & V_138 -> V_5 . V_351 , F_174 ) ;
F_638 ( & V_138 -> V_5 . V_353 , F_179 ) ;
return 0 ;
}
static void F_639 ( struct V_1 * V_2 )
{
int V_120 ;
V_120 = V_569 ( V_2 ) ;
F_13 ( V_120 ) ;
F_537 ( V_2 ) ;
V_573 ( V_2 ) ;
}
static void F_640 ( struct V_138 * V_138 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_160 (i, vcpu, kvm) {
F_64 ( V_2 ) ;
F_639 ( V_2 ) ;
}
F_160 (i, vcpu, kvm)
F_597 ( V_2 ) ;
F_280 ( & V_138 -> V_716 ) ;
for ( V_3 = 0 ; V_3 < F_135 ( & V_138 -> V_285 ) ; V_3 ++ )
V_138 -> V_1252 [ V_3 ] = NULL ;
F_156 ( & V_138 -> V_285 , 0 ) ;
F_282 ( & V_138 -> V_716 ) ;
}
void F_641 ( struct V_138 * V_138 )
{
F_642 ( & V_138 -> V_5 . V_353 ) ;
F_642 ( & V_138 -> V_5 . V_351 ) ;
F_643 ( V_138 ) ;
F_644 ( V_138 ) ;
}
int F_645 ( struct V_138 * V_138 , int V_1213 , T_6 V_379 , T_1 V_479 )
{
int V_3 , V_120 ;
unsigned long V_1253 ;
struct V_1254 * V_1255 = V_1254 ( V_138 ) ;
struct V_1256 * V_10 , V_837 ;
if ( F_28 ( V_1213 >= V_1257 ) )
return - V_565 ;
V_10 = F_646 ( V_1255 , V_1213 ) ;
if ( V_479 ) {
if ( F_28 ( V_10 -> V_1258 ) )
return - V_753 ;
V_1253 = F_647 ( NULL , 0 , V_479 , V_1259 | V_1260 ,
V_1261 | V_1262 , 0 ) ;
if ( F_184 ( ( void * ) V_1253 ) )
return F_185 ( ( void * ) V_1253 ) ;
} else {
if ( ! V_10 -> V_1258 )
return 0 ;
V_1253 = 0 ;
}
V_837 = * V_10 ;
for ( V_3 = 0 ; V_3 < V_1263 ; V_3 ++ ) {
struct V_1264 V_1265 ;
V_1265 . V_10 = V_1213 | ( V_3 << 16 ) ;
V_1265 . V_295 = 0 ;
V_1265 . V_1266 = V_379 ;
V_1265 . V_1267 = V_1253 ;
V_1265 . V_1268 = V_479 ;
V_120 = F_648 ( V_138 , & V_1265 ) ;
if ( V_120 < 0 )
return V_120 ;
}
if ( ! V_479 ) {
V_120 = F_649 ( V_837 . V_1267 , V_837 . V_1258 * V_107 ) ;
F_28 ( V_120 < 0 ) ;
}
return 0 ;
}
int F_650 ( struct V_138 * V_138 , int V_1213 , T_6 V_379 , T_1 V_479 )
{
int V_120 ;
F_280 ( & V_138 -> V_703 ) ;
V_120 = F_645 ( V_138 , V_1213 , V_379 , V_479 ) ;
F_282 ( & V_138 -> V_703 ) ;
return V_120 ;
}
void F_651 ( struct V_138 * V_138 )
{
if ( V_386 -> V_1269 == V_138 -> V_1269 ) {
F_650 ( V_138 , V_1270 , 0 , 0 ) ;
F_650 ( V_138 , V_1271 , 0 , 0 ) ;
F_650 ( V_138 , V_1272 , 0 , 0 ) ;
}
F_652 ( V_138 ) ;
F_187 ( V_138 -> V_5 . V_752 ) ;
F_187 ( V_138 -> V_5 . V_1273 ) ;
F_640 ( V_138 ) ;
F_187 ( F_653 ( V_138 -> V_5 . V_1274 , 1 ) ) ;
}
void F_654 ( struct V_138 * V_138 , struct V_1256 * free ,
struct V_1256 * V_1275 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1276 ; ++ V_3 ) {
if ( ! V_1275 || free -> V_5 . V_1277 [ V_3 ] != V_1275 -> V_5 . V_1277 [ V_3 ] ) {
F_655 ( free -> V_5 . V_1277 [ V_3 ] ) ;
free -> V_5 . V_1277 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1275 || free -> V_5 . V_1278 [ V_3 - 1 ] !=
V_1275 -> V_5 . V_1278 [ V_3 - 1 ] ) {
F_655 ( free -> V_5 . V_1278 [ V_3 - 1 ] ) ;
free -> V_5 . V_1278 [ V_3 - 1 ] = NULL ;
}
}
}
int F_656 ( struct V_138 * V_138 , struct V_1256 * V_10 ,
unsigned long V_1258 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1276 ; ++ V_3 ) {
unsigned long V_1279 ;
int V_1280 ;
int V_738 = V_3 + 1 ;
V_1280 = F_657 ( V_10 -> V_1281 + V_1258 - 1 ,
V_10 -> V_1281 , V_738 ) + 1 ;
V_10 -> V_5 . V_1277 [ V_3 ] =
F_658 ( V_1280 * sizeof( * V_10 -> V_5 . V_1277 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1277 [ V_3 ] )
goto V_378;
if ( V_3 == 0 )
continue;
V_10 -> V_5 . V_1278 [ V_3 - 1 ] = F_658 ( V_1280 *
sizeof( * V_10 -> V_5 . V_1278 [ V_3 - 1 ] ) ) ;
if ( ! V_10 -> V_5 . V_1278 [ V_3 - 1 ] )
goto V_378;
if ( V_10 -> V_1281 & ( F_659 ( V_738 ) - 1 ) )
V_10 -> V_5 . V_1278 [ V_3 - 1 ] [ 0 ] . V_1282 = 1 ;
if ( ( V_10 -> V_1281 + V_1258 ) & ( F_659 ( V_738 ) - 1 ) )
V_10 -> V_5 . V_1278 [ V_3 - 1 ] [ V_1280 - 1 ] . V_1282 = 1 ;
V_1279 = V_10 -> V_1267 >> V_106 ;
if ( ( V_10 -> V_1281 ^ V_1279 ) & ( F_659 ( V_738 ) - 1 ) ||
! F_660 () ) {
unsigned long V_782 ;
for ( V_782 = 0 ; V_782 < V_1280 ; ++ V_782 )
V_10 -> V_5 . V_1278 [ V_3 - 1 ] [ V_782 ] . V_1282 = 1 ;
}
}
return 0 ;
V_378:
for ( V_3 = 0 ; V_3 < V_1276 ; ++ V_3 ) {
F_655 ( V_10 -> V_5 . V_1277 [ V_3 ] ) ;
V_10 -> V_5 . V_1277 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_655 ( V_10 -> V_5 . V_1278 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1278 [ V_3 - 1 ] = NULL ;
}
return - V_377 ;
}
void F_661 ( struct V_138 * V_138 , struct V_1254 * V_1255 )
{
F_662 ( V_138 , V_1255 ) ;
}
int F_663 ( struct V_138 * V_138 ,
struct V_1256 * V_1283 ,
const struct V_1264 * V_1284 ,
enum V_1285 V_1286 )
{
return 0 ;
}
static void F_664 ( struct V_138 * V_138 ,
struct V_1256 * V_838 )
{
if ( V_838 -> V_295 & V_1287 ) {
F_665 ( V_138 , V_838 ) ;
return;
}
if ( V_838 -> V_295 & V_1288 ) {
if ( V_73 -> V_1289 )
V_73 -> V_1289 ( V_138 , V_838 ) ;
else
F_665 ( V_138 , V_838 ) ;
} else {
if ( V_73 -> V_1290 )
V_73 -> V_1290 ( V_138 , V_838 ) ;
}
}
void F_666 ( struct V_138 * V_138 ,
const struct V_1264 * V_1284 ,
const struct V_1256 * V_837 ,
const struct V_1256 * V_838 ,
enum V_1285 V_1286 )
{
int V_1291 = 0 ;
if ( ! V_138 -> V_5 . V_704 )
V_1291 = F_667 ( V_138 ) ;
if ( V_1291 )
F_281 ( V_138 , V_1291 ) ;
if ( ( V_1286 != V_1292 ) &&
( V_837 -> V_295 & V_1288 ) &&
! ( V_838 -> V_295 & V_1288 ) )
F_668 ( V_138 , V_838 ) ;
if ( V_1286 != V_1292 )
F_664 ( V_138 , (struct V_1256 * ) V_838 ) ;
}
void F_669 ( struct V_138 * V_138 )
{
F_670 ( V_138 ) ;
}
void F_671 ( struct V_138 * V_138 ,
struct V_1256 * V_10 )
{
F_670 ( V_138 ) ;
}
static inline bool F_672 ( struct V_1 * V_2 )
{
if ( ! F_673 ( & V_2 -> V_1293 . V_1294 ) )
return true ;
if ( F_674 ( V_2 ) )
return true ;
if ( V_2 -> V_5 . V_1115 . V_1116 )
return true ;
if ( F_135 ( & V_2 -> V_5 . V_85 ) )
return true ;
if ( F_58 ( V_583 , & V_2 -> V_327 ) )
return true ;
if ( F_505 ( V_2 ) &&
F_504 ( V_2 ) )
return true ;
return false ;
}
int F_560 ( struct V_1 * V_2 )
{
if ( F_427 ( V_2 ) && V_73 -> V_1053 )
V_73 -> V_1053 ( V_2 , false ) ;
return F_562 ( V_2 ) || F_672 ( V_2 ) ;
}
int F_675 ( struct V_1 * V_2 )
{
return F_676 ( V_2 ) == V_1101 ;
}
int F_505 ( struct V_1 * V_2 )
{
return V_73 -> V_1055 ( V_2 ) ;
}
unsigned long F_441 ( struct V_1 * V_2 )
{
if ( F_501 ( V_2 ) )
return F_419 ( V_2 ) ;
return ( T_1 ) ( F_370 ( V_2 , V_1064 ) +
F_419 ( V_2 ) ) ;
}
bool F_677 ( struct V_1 * V_2 , unsigned long V_1295 )
{
return F_441 ( V_2 ) == V_1295 ;
}
unsigned long F_418 ( struct V_1 * V_2 )
{
unsigned long V_936 ;
V_936 = V_73 -> V_966 ( V_2 ) ;
if ( V_2 -> V_176 & V_939 )
V_936 &= ~ V_938 ;
return V_936 ;
}
static void F_448 ( struct V_1 * V_2 , unsigned long V_936 )
{
if ( V_2 -> V_176 & V_939 &&
F_677 ( V_2 , V_2 -> V_5 . V_943 ) )
V_936 |= V_938 ;
V_73 -> V_1296 ( V_2 , V_936 ) ;
}
void F_424 ( struct V_1 * V_2 , unsigned long V_936 )
{
F_448 ( V_2 , V_936 ) ;
F_30 ( V_67 , V_2 ) ;
}
void F_678 ( struct V_1 * V_2 , struct V_1297 * V_348 )
{
int V_120 ;
if ( ( V_2 -> V_5 . V_84 . V_928 != V_348 -> V_5 . V_928 ) ||
V_348 -> V_1298 )
return;
V_120 = F_544 ( V_2 ) ;
if ( F_152 ( V_120 ) )
return;
if ( ! V_2 -> V_5 . V_84 . V_928 &&
V_348 -> V_5 . V_104 != V_2 -> V_5 . V_84 . V_1299 ( V_2 ) )
return;
V_2 -> V_5 . V_84 . V_1300 ( V_2 , V_348 -> V_796 , 0 , true ) ;
}
static inline T_1 F_679 ( T_5 V_102 )
{
return F_680 ( V_102 & 0xffffffff , F_681 ( V_4 ) ) ;
}
static inline T_1 F_682 ( T_1 V_1301 )
{
return ( V_1301 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_683 ( struct V_1 * V_2 , T_5 V_102 )
{
T_1 V_1301 = F_679 ( V_102 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1301 ] != ~ 0 )
V_1301 = F_682 ( V_1301 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1301 ] = V_102 ;
}
static T_1 F_684 ( struct V_1 * V_2 , T_5 V_102 )
{
int V_3 ;
T_1 V_1301 = F_679 ( V_102 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1301 ] != V_102 &&
V_2 -> V_5 . V_6 . V_7 [ V_1301 ] != ~ 0 ) ; V_3 ++ )
V_1301 = F_682 ( V_1301 ) ;
return V_1301 ;
}
bool F_685 ( struct V_1 * V_2 , T_5 V_102 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_684 ( V_2 , V_102 ) ] == V_102 ;
}
static void F_686 ( struct V_1 * V_2 , T_5 V_102 )
{
T_1 V_3 , V_782 , V_1302 ;
V_3 = V_782 = F_684 ( V_2 , V_102 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_782 = F_682 ( V_782 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_782 ] == ~ 0 )
return;
V_1302 = F_679 ( V_2 -> V_5 . V_6 . V_7 [ V_782 ] ) ;
} while ( ( V_3 <= V_782 ) ? ( V_3 < V_1302 && V_1302 <= V_782 ) : ( V_3 < V_1302 || V_1302 <= V_782 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_782 ] ;
V_3 = V_782 ;
}
}
static int F_687 ( struct V_1 * V_2 , T_1 V_193 )
{
return F_171 ( V_2 -> V_138 , & V_2 -> V_5 . V_6 . V_38 , & V_193 ,
sizeof( V_193 ) ) ;
}
void F_688 ( struct V_1 * V_2 ,
struct V_1297 * V_348 )
{
struct V_75 V_76 ;
F_689 ( V_348 -> V_5 . V_1303 , V_348 -> V_796 ) ;
F_683 ( V_2 , V_348 -> V_5 . V_102 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_380 & V_381 ) ||
( V_2 -> V_5 . V_6 . V_382 &&
V_73 -> V_88 ( V_2 ) == 0 ) )
F_30 ( V_1086 , V_2 ) ;
else if ( ! F_687 ( V_2 , V_1304 ) ) {
V_76 . V_41 = V_42 ;
V_76 . V_898 = true ;
V_76 . V_62 = 0 ;
V_76 . V_81 = false ;
V_76 . V_80 = V_348 -> V_5 . V_1303 ;
F_36 ( V_2 , & V_76 ) ;
}
}
void F_690 ( struct V_1 * V_2 ,
struct V_1297 * V_348 )
{
struct V_75 V_76 ;
F_691 ( V_348 -> V_5 . V_1303 , V_348 -> V_796 ) ;
if ( V_348 -> V_1298 )
V_348 -> V_5 . V_1303 = ~ 0 ;
else
F_686 ( V_2 , V_348 -> V_5 . V_102 ) ;
if ( ( V_2 -> V_5 . V_6 . V_380 & V_381 ) &&
! F_687 ( V_2 , V_1305 ) ) {
V_76 . V_41 = V_42 ;
V_76 . V_898 = true ;
V_76 . V_62 = 0 ;
V_76 . V_81 = false ;
V_76 . V_80 = V_348 -> V_5 . V_1303 ;
F_36 ( V_2 , & V_76 ) ;
}
V_2 -> V_5 . V_6 . V_1087 = false ;
V_2 -> V_5 . V_1015 = V_1117 ;
}
bool F_692 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_380 & V_381 ) )
return true ;
else
return ! F_507 ( V_2 ) &&
V_73 -> V_1055 ( V_2 ) ;
}
void F_693 ( struct V_138 * V_138 )
{
F_41 ( & V_138 -> V_5 . V_1306 ) ;
}
void F_694 ( struct V_138 * V_138 )
{
F_695 ( & V_138 -> V_5 . V_1306 ) ;
}
bool F_696 ( struct V_138 * V_138 )
{
return F_135 ( & V_138 -> V_5 . V_1306 ) ;
}
void F_697 ( struct V_138 * V_138 )
{
F_41 ( & V_138 -> V_5 . V_1248 ) ;
}
void F_698 ( struct V_138 * V_138 )
{
F_695 ( & V_138 -> V_5 . V_1248 ) ;
}
bool F_230 ( struct V_138 * V_138 )
{
return F_135 ( & V_138 -> V_5 . V_1248 ) ;
}
