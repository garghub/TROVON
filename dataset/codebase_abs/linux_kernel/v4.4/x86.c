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
F_73 ( V_2 ) ;
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
V_164 | V_165 ;
if ( V_158 & V_166 )
return 1 ;
if ( ! F_79 ( V_2 ) && ( V_158 & V_141 ) )
return 1 ;
if ( ! F_80 ( V_2 ) && ( V_158 & V_164 ) )
return 1 ;
if ( ! F_81 ( V_2 ) && ( V_158 & V_165 ) )
return 1 ;
if ( ! F_82 ( V_2 ) && ( V_158 & V_167 ) )
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
if ( ! F_83 ( V_2 ) )
return 1 ;
if ( ( F_59 ( V_2 ) & V_168 ) || ! F_56 ( V_2 ) )
return 1 ;
}
if ( V_73 -> V_169 ( V_2 , V_158 ) )
return 1 ;
if ( ( ( V_158 ^ V_159 ) & V_160 ) ||
( ! ( V_158 & V_136 ) && ( V_159 & V_136 ) ) )
F_65 ( V_2 ) ;
if ( ( V_158 ^ V_159 ) & V_141 )
F_75 ( V_2 ) ;
return 0 ;
}
int F_84 ( struct V_1 * V_2 , unsigned long V_104 )
{
#ifdef F_62
V_104 &= ~ V_170 ;
#endif
if ( V_104 == F_59 ( V_2 ) && ! F_55 ( V_2 ) ) {
F_85 ( V_2 ) ;
F_30 ( V_171 , V_2 ) ;
return 0 ;
}
if ( F_56 ( V_2 ) ) {
if ( V_104 & V_172 )
return 1 ;
} else if ( F_57 ( V_2 ) && F_63 ( V_2 ) &&
! F_51 ( V_2 , V_2 -> V_5 . V_103 , V_104 ) )
return 1 ;
V_2 -> V_5 . V_104 = V_104 ;
F_54 ( V_173 , ( V_174 * ) & V_2 -> V_5 . V_117 ) ;
F_86 ( V_2 ) ;
return 0 ;
}
int F_87 ( struct V_1 * V_2 , unsigned long V_175 )
{
if ( V_175 & V_176 )
return 1 ;
if ( F_88 ( V_2 ) )
F_89 ( V_2 , V_175 ) ;
else
V_2 -> V_5 . V_175 = V_175 ;
return 0 ;
}
unsigned long F_90 ( struct V_1 * V_2 )
{
if ( F_88 ( V_2 ) )
return F_91 ( V_2 ) ;
else
return V_2 -> V_5 . V_175 ;
}
static void F_92 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! ( V_2 -> V_177 & V_178 ) ) {
for ( V_3 = 0 ; V_3 < V_179 ; V_3 ++ )
V_2 -> V_5 . V_180 [ V_3 ] = V_2 -> V_5 . V_181 [ V_3 ] ;
V_2 -> V_5 . V_182 |= V_183 ;
}
}
static void F_93 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_177 & V_178 ) )
V_73 -> V_184 ( V_2 , V_2 -> V_5 . V_185 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
unsigned long V_186 ;
if ( V_2 -> V_177 & V_178 )
V_186 = V_2 -> V_5 . V_187 ;
else
V_186 = V_2 -> V_5 . V_186 ;
V_73 -> V_188 ( V_2 , V_186 ) ;
V_2 -> V_5 . V_182 &= ~ V_189 ;
if ( V_186 & V_190 )
V_2 -> V_5 . V_182 |= V_189 ;
}
static T_2 F_95 ( struct V_1 * V_2 )
{
T_2 V_191 = V_192 ;
if ( ! F_96 ( V_2 ) )
V_191 |= V_193 ;
return V_191 ;
}
static int F_97 ( struct V_1 * V_2 , int V_89 , unsigned long V_194 )
{
switch ( V_89 ) {
case 0 ... 3 :
V_2 -> V_5 . V_181 [ V_89 ] = V_194 ;
if ( ! ( V_2 -> V_177 & V_178 ) )
V_2 -> V_5 . V_180 [ V_89 ] = V_194 ;
break;
case 4 :
case 6 :
if ( V_194 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_185 = ( V_194 & V_195 ) | F_95 ( V_2 ) ;
F_93 ( V_2 ) ;
break;
case 5 :
default:
if ( V_194 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_186 = ( V_194 & V_196 ) | V_197 ;
F_94 ( V_2 ) ;
break;
}
return 0 ;
}
int F_98 ( struct V_1 * V_2 , int V_89 , unsigned long V_194 )
{
if ( F_97 ( V_2 , V_89 , V_194 ) ) {
F_35 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_99 ( struct V_1 * V_2 , int V_89 , unsigned long * V_194 )
{
switch ( V_89 ) {
case 0 ... 3 :
* V_194 = V_2 -> V_5 . V_181 [ V_89 ] ;
break;
case 4 :
case 6 :
if ( V_2 -> V_177 & V_178 )
* V_194 = V_2 -> V_5 . V_185 ;
else
* V_194 = V_73 -> V_198 ( V_2 ) ;
break;
case 5 :
default:
* V_194 = V_2 -> V_5 . V_186 ;
break;
}
return 0 ;
}
bool F_100 ( struct V_1 * V_2 )
{
T_1 V_199 = F_101 ( V_2 , V_200 ) ;
T_2 V_38 ;
int V_29 ;
V_29 = F_102 ( V_2 , V_199 , & V_38 ) ;
if ( V_29 )
return V_29 ;
F_103 ( V_2 , V_201 , ( T_1 ) V_38 ) ;
F_103 ( V_2 , V_202 , V_38 >> 32 ) ;
return V_29 ;
}
bool F_104 ( struct V_1 * V_2 , T_2 V_131 )
{
if ( V_131 & V_203 )
return false ;
if ( V_131 & V_204 ) {
struct V_205 * V_206 ;
V_206 = F_105 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_206 || ! ( V_206 -> V_207 & F_106 ( V_208 ) ) )
return false ;
}
if ( V_131 & V_209 ) {
struct V_205 * V_206 ;
V_206 = F_105 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_206 || ! ( V_206 -> V_199 & F_106 ( V_210 ) ) )
return false ;
}
return true ;
}
static int F_107 ( struct V_1 * V_2 , T_2 V_131 )
{
T_2 V_211 = V_2 -> V_5 . V_131 ;
if ( ! F_104 ( V_2 , V_131 ) )
return 1 ;
if ( F_63 ( V_2 )
&& ( V_2 -> V_5 . V_131 & V_132 ) != ( V_131 & V_132 ) )
return 1 ;
V_131 &= ~ V_212 ;
V_131 |= V_2 -> V_5 . V_131 & V_212 ;
V_73 -> F_107 ( V_2 , V_131 ) ;
if ( ( V_131 ^ V_211 ) & V_213 )
F_65 ( V_2 ) ;
return 0 ;
}
void F_108 ( T_2 V_28 )
{
V_203 &= ~ V_28 ;
}
int F_109 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
switch ( V_21 -> V_146 ) {
case V_214 :
case V_215 :
case V_216 :
case V_217 :
case V_218 :
if ( F_110 ( V_21 -> V_38 ) )
return 1 ;
break;
case V_219 :
case V_220 :
V_21 -> V_38 = F_111 ( V_21 -> V_38 ) ;
}
return V_73 -> V_221 ( V_2 , V_21 ) ;
}
static int F_112 ( struct V_1 * V_2 , unsigned V_146 , T_2 * V_38 )
{
struct V_32 V_21 ;
int V_120 ;
V_21 . V_146 = V_146 ;
V_21 . V_40 = true ;
V_120 = F_113 ( V_2 , & V_21 ) ;
if ( V_120 )
return V_120 ;
* V_38 = V_21 . V_38 ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 , unsigned V_146 , T_2 * V_38 )
{
struct V_32 V_21 ;
V_21 . V_38 = * V_38 ;
V_21 . V_146 = V_146 ;
V_21 . V_40 = true ;
return F_109 ( V_2 , & V_21 ) ;
}
static void F_115 ( struct V_222 * V_223 )
{
struct V_224 * V_225 = & V_224 ;
T_2 V_226 ;
V_226 = F_116 ( F_117 ( V_223 -> V_227 . V_228 , V_223 -> V_229 ) ) ;
F_118 ( & V_225 -> V_230 ) ;
V_225 -> clock . V_231 = V_223 -> V_227 . clock -> V_232 . V_231 ;
V_225 -> clock . V_233 = V_223 -> V_227 . V_233 ;
V_225 -> clock . V_28 = V_223 -> V_227 . V_28 ;
V_225 -> clock . V_234 = V_223 -> V_227 . V_234 ;
V_225 -> clock . V_235 = V_223 -> V_227 . V_235 ;
V_225 -> V_226 = V_226 ;
V_225 -> V_236 = V_223 -> V_227 . V_237 ;
F_119 ( & V_225 -> V_230 ) ;
}
void F_120 ( struct V_1 * V_2 )
{
F_30 ( V_238 , V_2 ) ;
}
static void F_121 ( struct V_138 * V_138 , T_6 V_239 )
{
int V_240 ;
int V_120 ;
struct V_241 V_242 ;
struct V_243 V_244 ;
if ( ! V_239 )
return;
V_120 = F_122 ( V_138 , V_239 , & V_240 , sizeof( V_240 ) ) ;
if ( V_120 )
return;
if ( V_240 & 1 )
++ V_240 ;
++ V_240 ;
F_123 ( V_138 , V_239 , & V_240 , sizeof( V_240 ) ) ;
F_124 ( & V_244 ) ;
if ( V_138 -> V_5 . V_245 ) {
struct V_243 V_246 = F_125 ( V_138 -> V_5 . V_245 ) ;
V_244 = F_126 ( V_244 , V_246 ) ;
}
V_242 . V_247 = V_244 . V_248 ;
V_242 . V_249 = V_244 . V_250 ;
V_242 . V_240 = V_240 ;
F_123 ( V_138 , V_239 , & V_242 , sizeof( V_242 ) ) ;
V_240 ++ ;
F_123 ( V_138 , V_239 , & V_240 , sizeof( V_240 ) ) ;
}
static T_7 F_127 ( T_7 V_251 , T_7 V_252 )
{
T_7 V_253 , V_254 ;
__asm__ ( "divl %4"
: "=a" (quotient), "=d" (remainder)
: "0" (0), "1" (dividend), "r" (divisor) );
return V_253 ;
}
static void F_128 ( T_7 V_255 , T_7 V_256 ,
T_8 * V_257 , T_1 * V_258 )
{
T_9 V_259 ;
T_10 V_235 = 0 ;
T_9 V_260 ;
T_7 V_261 ;
V_260 = V_256 * 1000LL ;
V_259 = V_255 * 1000LL ;
while ( V_260 > V_259 * 2 || V_260 & 0xffffffff00000000ULL ) {
V_260 >>= 1 ;
V_235 -- ;
}
V_261 = ( T_7 ) V_260 ;
while ( V_261 <= V_259 || V_259 & 0xffffffff00000000ULL ) {
if ( V_259 & 0xffffffff00000000ULL || V_261 & 0x80000000 )
V_259 >>= 1 ;
else
V_261 <<= 1 ;
V_235 ++ ;
}
* V_257 = V_235 ;
* V_258 = F_127 ( V_259 , V_261 ) ;
F_129 ( L_2 ,
V_262 , V_256 , V_255 , V_235 , * V_258 ) ;
}
static inline T_2 F_130 ( struct V_1 * V_2 , T_2 V_249 )
{
return F_131 ( V_249 , V_2 -> V_5 . V_263 ,
V_2 -> V_5 . V_264 ) ;
}
static T_1 F_132 ( T_1 V_265 , T_11 V_266 )
{
T_2 V_267 = ( T_2 ) V_265 * ( 1000000 + V_266 ) ;
F_133 ( V_267 , 1000000 ) ;
return V_267 ;
}
static int F_134 ( struct V_1 * V_2 , T_1 V_268 , bool V_269 )
{
T_2 V_270 ;
if ( ! V_269 ) {
V_2 -> V_5 . V_271 = V_272 ;
return 0 ;
}
if ( ! V_273 ) {
if ( V_268 > V_274 ) {
V_2 -> V_5 . V_275 = 1 ;
V_2 -> V_5 . V_276 = 1 ;
return 0 ;
} else {
F_135 ( 1 , L_3 ) ;
return - 1 ;
}
}
V_270 = F_136 ( 1ULL << V_277 ,
V_268 , V_274 ) ;
if ( V_270 == 0 || V_270 >= V_278 ) {
F_137 ( 1 , L_4 ,
V_268 ) ;
return - 1 ;
}
V_2 -> V_5 . V_271 = V_270 ;
return 0 ;
}
static int F_138 ( struct V_1 * V_2 , T_1 V_279 )
{
T_1 V_280 , V_281 ;
int V_282 = 0 ;
if ( V_279 == 0 ) {
V_2 -> V_5 . V_271 = V_272 ;
return - 1 ;
}
F_128 ( V_279 , V_283 / 1000 ,
& V_2 -> V_5 . V_264 ,
& V_2 -> V_5 . V_263 ) ;
V_2 -> V_5 . V_284 = V_279 ;
V_280 = F_132 ( V_274 , - V_285 ) ;
V_281 = F_132 ( V_274 , V_285 ) ;
if ( V_279 < V_280 || V_279 > V_281 ) {
F_129 ( L_5 , V_279 , V_280 , V_281 ) ;
V_282 = 1 ;
}
return F_134 ( V_2 , V_279 , V_282 ) ;
}
static T_2 F_139 ( struct V_1 * V_2 , T_12 V_286 )
{
T_2 V_287 = F_131 ( V_286 - V_2 -> V_5 . V_288 ,
V_2 -> V_5 . V_263 ,
V_2 -> V_5 . V_264 ) ;
V_287 += V_2 -> V_5 . V_289 ;
return V_287 ;
}
static void F_140 ( struct V_1 * V_2 )
{
#ifdef F_62
bool V_290 ;
struct V_291 * V_292 = & V_2 -> V_138 -> V_5 ;
struct V_224 * V_293 = & V_224 ;
V_290 = ( V_292 -> V_294 + 1 ==
F_141 ( & V_2 -> V_138 -> V_295 ) ) ;
if ( V_292 -> V_296 ||
( V_293 -> clock . V_231 == V_297 && V_290 ) )
F_30 ( V_298 , V_2 ) ;
F_142 ( V_2 -> V_299 , V_292 -> V_294 ,
F_141 ( & V_2 -> V_138 -> V_295 ) ,
V_292 -> V_296 , V_293 -> clock . V_231 ) ;
#endif
}
static void F_143 ( struct V_1 * V_2 , T_12 V_94 )
{
T_2 V_300 = V_73 -> V_301 ( V_2 ) ;
V_2 -> V_5 . V_302 += V_94 - V_300 ;
}
static inline T_2 F_144 ( T_2 V_270 , T_2 V_287 )
{
return F_145 ( V_287 , V_270 , V_277 ) ;
}
T_2 F_146 ( struct V_1 * V_2 , T_2 V_287 )
{
T_2 V_303 = V_287 ;
T_2 V_270 = V_2 -> V_5 . V_271 ;
if ( V_270 != V_272 )
V_303 = F_144 ( V_270 , V_287 ) ;
return V_303 ;
}
static T_2 F_147 ( struct V_1 * V_2 , T_2 V_304 )
{
T_2 V_287 ;
V_287 = F_146 ( V_2 , F_148 () ) ;
return V_304 - V_287 ;
}
T_2 F_149 ( struct V_1 * V_2 , T_2 V_305 )
{
return V_73 -> V_306 ( V_2 , F_146 ( V_2 , V_305 ) ) ;
}
void F_150 ( struct V_1 * V_2 , struct V_32 * V_21 )
{
struct V_138 * V_138 = V_2 -> V_138 ;
T_2 V_94 , V_307 , V_308 ;
unsigned long V_309 ;
T_12 V_310 ;
bool V_311 ;
bool V_312 ;
T_2 V_38 = V_21 -> V_38 ;
F_151 ( & V_138 -> V_5 . V_313 , V_309 ) ;
V_94 = F_147 ( V_2 , V_38 ) ;
V_307 = F_152 () ;
V_308 = V_307 - V_138 -> V_5 . V_314 ;
if ( V_2 -> V_5 . V_284 ) {
int V_315 = 0 ;
V_310 = V_38 - V_138 -> V_5 . V_316 ;
#ifdef F_62
V_310 = ( V_310 * 1000 ) / V_2 -> V_5 . V_284 ;
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
F_133 ( V_308 , 1000 ) ;
V_310 -= V_308 ;
if ( V_310 < 0 )
V_310 = - V_310 ;
if ( V_315 )
V_310 = V_317 ;
} else
V_310 = V_317 ;
if ( V_310 < V_317 &&
V_2 -> V_5 . V_284 == V_138 -> V_5 . V_318 ) {
if ( ! F_153 () ) {
V_94 = V_138 -> V_5 . V_319 ;
F_129 ( L_6 , V_38 ) ;
} else {
T_2 V_320 = F_130 ( V_2 , V_308 ) ;
V_38 += V_320 ;
V_94 = F_147 ( V_2 , V_38 ) ;
F_129 ( L_7 , V_320 ) ;
}
V_311 = true ;
V_312 = ( V_2 -> V_5 . V_321 == V_138 -> V_5 . V_322 ) ;
} else {
V_138 -> V_5 . V_322 ++ ;
V_138 -> V_5 . V_323 = V_307 ;
V_138 -> V_5 . V_324 = V_38 ;
V_138 -> V_5 . V_319 = V_94 ;
V_311 = false ;
F_129 ( L_8 ,
V_138 -> V_5 . V_322 , V_38 ) ;
}
V_138 -> V_5 . V_314 = V_307 ;
V_138 -> V_5 . V_316 = V_38 ;
V_138 -> V_5 . V_318 = V_2 -> V_5 . V_284 ;
V_2 -> V_5 . V_325 = V_38 ;
V_2 -> V_5 . V_321 = V_138 -> V_5 . V_322 ;
V_2 -> V_5 . V_288 = V_138 -> V_5 . V_323 ;
V_2 -> V_5 . V_289 = V_138 -> V_5 . V_324 ;
if ( F_154 ( V_2 ) && ! V_21 -> V_40 )
F_143 ( V_2 , V_94 ) ;
V_73 -> V_326 ( V_2 , V_94 ) ;
F_155 ( & V_138 -> V_5 . V_313 , V_309 ) ;
F_156 ( & V_138 -> V_5 . V_327 ) ;
if ( ! V_311 ) {
V_138 -> V_5 . V_294 = 0 ;
} else if ( ! V_312 ) {
V_138 -> V_5 . V_294 ++ ;
}
F_140 ( V_2 ) ;
F_157 ( & V_138 -> V_5 . V_327 ) ;
}
static inline void F_158 ( struct V_1 * V_2 ,
T_12 V_328 )
{
V_73 -> F_158 ( V_2 , V_328 ) ;
}
static inline void F_159 ( struct V_1 * V_2 , T_12 V_328 )
{
if ( V_2 -> V_5 . V_271 != V_272 )
F_28 ( V_328 < 0 ) ;
V_328 = F_146 ( V_2 , ( T_2 ) V_328 ) ;
V_73 -> F_158 ( V_2 , V_328 ) ;
}
static T_13 F_160 ( void )
{
T_13 V_108 = ( T_13 ) F_161 () ;
T_2 V_329 = V_224 . clock . V_233 ;
if ( F_162 ( V_108 >= V_329 ) )
return V_108 ;
asm volatile ("");
return V_329 ;
}
static inline T_2 F_163 ( T_13 * V_330 )
{
long V_267 ;
struct V_224 * V_293 = & V_224 ;
* V_330 = F_160 () ;
V_267 = ( * V_330 - V_293 -> clock . V_233 ) & V_293 -> clock . V_28 ;
return V_267 * V_293 -> clock . V_234 ;
}
static int F_164 ( T_12 * V_331 , T_13 * V_330 )
{
struct V_224 * V_293 = & V_224 ;
unsigned long V_230 ;
int V_332 ;
T_2 V_307 ;
do {
V_230 = F_165 ( & V_293 -> V_230 ) ;
V_332 = V_293 -> clock . V_231 ;
V_307 = V_293 -> V_236 ;
V_307 += F_163 ( V_330 ) ;
V_307 >>= V_293 -> clock . V_235 ;
V_307 += V_293 -> V_226 ;
} while ( F_166 ( F_167 ( & V_293 -> V_230 , V_230 ) ) );
* V_331 = V_307 ;
return V_332 ;
}
static bool F_168 ( T_12 * V_286 , T_13 * V_330 )
{
if ( V_224 . clock . V_231 != V_297 )
return false ;
return F_164 ( V_286 , V_330 ) == V_297 ;
}
static void F_169 ( struct V_138 * V_138 )
{
#ifdef F_62
struct V_291 * V_292 = & V_138 -> V_5 ;
int V_231 ;
bool V_333 , V_290 ;
V_290 = ( V_292 -> V_294 + 1 ==
F_141 ( & V_138 -> V_295 ) ) ;
V_333 = F_168 (
& V_292 -> V_334 ,
& V_292 -> V_335 ) ;
V_292 -> V_296 = V_333 && V_290
&& ! V_336
&& ! V_292 -> V_337 ;
if ( V_292 -> V_296 )
F_170 ( & V_338 , 1 ) ;
V_231 = V_224 . clock . V_231 ;
F_171 ( V_292 -> V_296 , V_231 ,
V_290 ) ;
#endif
}
static void F_172 ( struct V_138 * V_138 )
{
#ifdef F_62
int V_3 ;
struct V_1 * V_2 ;
struct V_291 * V_292 = & V_138 -> V_5 ;
F_156 ( & V_292 -> V_327 ) ;
F_173 ( V_138 ) ;
F_169 ( V_138 ) ;
F_174 (i, vcpu, kvm)
F_30 ( V_339 , V_2 ) ;
F_174 (i, vcpu, kvm)
F_175 ( V_340 , & V_2 -> V_341 ) ;
F_157 ( & V_292 -> V_327 ) ;
#endif
}
static int F_176 ( struct V_1 * V_267 )
{
unsigned long V_309 , V_279 , V_342 ;
struct V_343 * V_2 = & V_267 -> V_5 ;
struct V_291 * V_292 = & V_267 -> V_138 -> V_5 ;
T_12 V_286 ;
T_2 V_344 , V_305 ;
struct V_345 V_346 ;
T_14 V_347 ;
bool V_296 ;
V_286 = 0 ;
V_305 = 0 ;
F_156 ( & V_292 -> V_327 ) ;
V_296 = V_292 -> V_296 ;
if ( V_296 ) {
V_305 = V_292 -> V_335 ;
V_286 = V_292 -> V_334 ;
}
F_157 ( & V_292 -> V_327 ) ;
F_177 ( V_309 ) ;
V_279 = F_178 ( V_348 ) ;
if ( F_166 ( V_279 == 0 ) ) {
F_179 ( V_309 ) ;
F_30 ( V_339 , V_267 ) ;
return 1 ;
}
if ( ! V_296 ) {
V_305 = F_148 () ;
V_286 = F_152 () ;
}
V_344 = F_149 ( V_267 , V_305 ) ;
if ( V_2 -> V_275 ) {
T_2 V_287 = F_139 ( V_267 , V_286 ) ;
if ( V_287 > V_344 ) {
F_158 ( V_267 , V_287 - V_344 ) ;
V_344 = V_287 ;
}
}
F_179 ( V_309 ) ;
if ( ! V_2 -> V_349 )
return 0 ;
if ( F_166 ( V_2 -> V_350 != V_279 ) ) {
V_342 = V_273 ?
V_2 -> V_284 : V_279 ;
F_128 ( V_283 / 1000 , V_342 ,
& V_2 -> V_351 . V_352 ,
& V_2 -> V_351 . V_353 ) ;
V_2 -> V_350 = V_279 ;
}
V_2 -> V_351 . V_344 = V_344 ;
V_2 -> V_351 . V_354 = V_286 + V_267 -> V_138 -> V_5 . V_245 ;
V_2 -> V_325 = V_344 ;
if ( F_166 ( F_180 ( V_267 -> V_138 , & V_2 -> V_355 ,
& V_346 , sizeof( V_346 ) ) ) )
return 0 ;
F_181 ( F_182 ( struct V_345 , V_240 ) != 0 ) ;
V_2 -> V_351 . V_240 = V_346 . V_240 + 1 ;
F_183 ( V_267 -> V_138 , & V_2 -> V_355 ,
& V_2 -> V_351 ,
sizeof( V_2 -> V_351 . V_240 ) ) ;
F_184 () ;
V_347 = ( V_346 . V_309 & V_356 ) ;
if ( V_2 -> V_357 ) {
V_347 |= V_356 ;
V_2 -> V_357 = false ;
}
if ( V_296 )
V_347 |= V_358 ;
V_2 -> V_351 . V_309 = V_347 ;
F_185 ( V_267 -> V_299 , & V_2 -> V_351 ) ;
F_183 ( V_267 -> V_138 , & V_2 -> V_355 ,
& V_2 -> V_351 ,
sizeof( V_2 -> V_351 ) ) ;
F_184 () ;
V_2 -> V_351 . V_240 ++ ;
F_183 ( V_267 -> V_138 , & V_2 -> V_355 ,
& V_2 -> V_351 ,
sizeof( V_2 -> V_351 . V_240 ) ) ;
return 0 ;
}
static void F_186 ( struct V_359 * V_360 )
{
int V_3 ;
struct V_361 * V_362 = F_187 ( V_360 ) ;
struct V_291 * V_292 = F_4 ( V_362 , struct V_291 ,
V_363 ) ;
struct V_138 * V_138 = F_4 ( V_292 , struct V_138 , V_5 ) ;
struct V_1 * V_2 ;
F_174 (i, vcpu, kvm) {
F_30 ( V_339 , V_2 ) ;
F_188 ( V_2 ) ;
}
}
static void F_189 ( struct V_1 * V_267 )
{
struct V_138 * V_138 = V_267 -> V_138 ;
F_30 ( V_339 , V_267 ) ;
F_190 ( & V_138 -> V_5 . V_363 ,
V_364 ) ;
}
static void F_191 ( struct V_359 * V_360 )
{
struct V_361 * V_362 = F_187 ( V_360 ) ;
struct V_291 * V_292 = F_4 ( V_362 , struct V_291 ,
V_365 ) ;
struct V_138 * V_138 = F_4 ( V_292 , struct V_138 , V_5 ) ;
if ( ! V_366 )
return;
F_190 ( & V_138 -> V_5 . V_363 , 0 ) ;
F_190 ( & V_138 -> V_5 . V_365 ,
V_367 ) ;
}
static int F_192 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
{
T_2 V_368 = V_2 -> V_5 . V_368 ;
unsigned V_369 = V_368 & 0xff ;
switch ( V_21 ) {
case V_370 :
V_2 -> V_5 . V_371 = V_38 ;
break;
case V_372 :
if ( ! ( V_368 & V_373 ) )
return 1 ;
if ( V_38 != 0 && V_38 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_374 = V_38 ;
break;
default:
if ( V_21 >= V_375 &&
V_21 < F_193 ( V_369 ) ) {
T_1 V_94 = V_21 - V_375 ;
if ( ( V_94 & 0x3 ) == 0 &&
V_38 != 0 && ( V_38 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_376 [ V_94 ] = V_38 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_194 ( struct V_1 * V_2 , T_2 V_38 )
{
struct V_138 * V_138 = V_2 -> V_138 ;
int V_377 = F_56 ( V_2 ) ;
T_14 * V_378 = V_377 ? ( T_14 * ) ( long ) V_138 -> V_5 . F_194 . V_379
: ( T_14 * ) ( long ) V_138 -> V_5 . F_194 . V_380 ;
T_14 V_381 = V_377 ? V_138 -> V_5 . F_194 . V_382
: V_138 -> V_5 . F_194 . V_383 ;
T_1 V_384 = V_38 & ~ V_385 ;
T_2 V_386 = V_38 & V_385 ;
T_14 * V_387 ;
int V_120 ;
V_120 = - V_388 ;
if ( V_384 >= V_381 )
goto V_113;
V_120 = - V_389 ;
V_387 = F_195 ( V_378 + ( V_384 * V_107 ) , V_107 ) ;
if ( F_196 ( V_387 ) ) {
V_120 = F_197 ( V_387 ) ;
goto V_113;
}
if ( F_198 ( V_2 , V_386 , V_387 , V_107 ) )
goto V_390;
V_120 = 0 ;
V_390:
F_199 ( V_387 ) ;
V_113:
return V_120 ;
}
static int F_200 ( struct V_1 * V_2 , T_2 V_38 )
{
T_6 V_391 = V_38 & ~ 0x3f ;
if ( V_38 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_392 = V_38 ;
if ( ! ( V_38 & V_393 ) ) {
F_64 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_201 ( V_2 -> V_138 , & V_2 -> V_5 . V_6 . V_38 , V_391 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_394 = ! ( V_38 & V_395 ) ;
F_202 ( V_2 ) ;
return 0 ;
}
static void F_203 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_349 = false ;
}
static void F_204 ( struct V_1 * V_2 )
{
T_2 V_320 ;
if ( ! ( V_2 -> V_5 . V_396 . V_392 & V_397 ) )
return;
V_320 = V_398 -> V_399 . V_400 - V_2 -> V_5 . V_396 . V_401 ;
V_2 -> V_5 . V_396 . V_401 = V_398 -> V_399 . V_400 ;
V_2 -> V_5 . V_396 . V_402 = V_320 ;
}
static void F_205 ( struct V_1 * V_2 )
{
F_204 ( V_2 ) ;
if ( ! ( V_2 -> V_5 . V_396 . V_392 & V_397 ) )
return;
if ( F_166 ( F_180 ( V_2 -> V_138 , & V_2 -> V_5 . V_396 . V_403 ,
& V_2 -> V_5 . V_396 . V_404 , sizeof( struct V_405 ) ) ) )
return;
V_2 -> V_5 . V_396 . V_404 . V_404 += V_2 -> V_5 . V_396 . V_402 ;
V_2 -> V_5 . V_396 . V_404 . V_240 += 2 ;
V_2 -> V_5 . V_396 . V_402 = 0 ;
F_183 ( V_2 -> V_138 , & V_2 -> V_5 . V_396 . V_403 ,
& V_2 -> V_5 . V_396 . V_404 , sizeof( struct V_405 ) ) ;
}
int F_206 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
bool V_406 = false ;
T_1 V_21 = V_33 -> V_146 ;
T_2 V_38 = V_33 -> V_38 ;
switch ( V_21 ) {
case V_407 :
case V_408 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
break;
case V_413 :
return F_107 ( V_2 , V_38 ) ;
case V_414 :
V_38 &= ~ ( T_2 ) 0x40 ;
V_38 &= ~ ( T_2 ) 0x100 ;
V_38 &= ~ ( T_2 ) 0x8 ;
V_38 &= ~ ( T_2 ) 0x40000 ;
if ( V_38 != 0 ) {
F_207 ( V_2 , L_9 ,
V_38 ) ;
return 1 ;
}
break;
case V_415 :
if ( V_38 != 0 ) {
F_207 ( V_2 , L_10
L_11 , V_38 ) ;
return 1 ;
}
break;
case V_416 :
if ( ! V_38 ) {
break;
} else if ( V_38 & ~ ( V_417 | V_418 ) ) {
return 1 ;
}
F_207 ( V_2 , L_12 ,
V_262 , V_38 ) ;
break;
case 0x200 ... 0x2ff :
return F_208 ( V_2 , V_21 , V_38 ) ;
case V_419 :
return F_20 ( V_2 , V_33 ) ;
case V_420 ... V_420 + 0x3ff :
return F_209 ( V_2 , V_21 , V_38 ) ;
case V_421 :
F_210 ( V_2 , V_38 ) ;
break;
case V_422 :
if ( F_154 ( V_2 ) ) {
if ( ! V_33 -> V_40 ) {
T_12 V_423 = V_38 - V_2 -> V_5 . V_302 ;
F_158 ( V_2 , V_423 ) ;
}
V_2 -> V_5 . V_302 = V_38 ;
}
break;
case V_424 :
V_2 -> V_5 . V_425 = V_38 ;
break;
case V_426 :
if ( ! V_33 -> V_40 )
return 1 ;
V_2 -> V_5 . V_427 = V_38 ;
break;
case V_428 :
case V_429 :
V_2 -> V_138 -> V_5 . V_239 = V_38 ;
F_121 ( V_2 -> V_138 , V_38 ) ;
break;
case V_430 :
case V_431 : {
T_2 V_432 ;
struct V_291 * V_292 = & V_2 -> V_138 -> V_5 ;
F_203 ( V_2 ) ;
if ( V_2 -> V_299 == 0 && ! V_33 -> V_40 ) {
bool V_433 = ( V_21 == V_431 ) ;
if ( V_292 -> V_337 != V_433 )
F_211 ( V_298 ,
& V_2 -> V_341 ) ;
V_292 -> V_337 = V_433 ;
}
V_2 -> V_5 . time = V_38 ;
F_30 ( V_434 , V_2 ) ;
if ( ! ( V_38 & 1 ) )
break;
V_432 = V_38 & ~ ( V_385 | 1 ) ;
if ( F_201 ( V_2 -> V_138 ,
& V_2 -> V_5 . V_355 , V_38 & ~ 1ULL ,
sizeof( struct V_345 ) ) )
V_2 -> V_5 . V_349 = false ;
else
V_2 -> V_5 . V_349 = true ;
break;
}
case V_435 :
if ( F_200 ( V_2 , V_38 ) )
return 1 ;
break;
case V_436 :
if ( F_166 ( ! F_212 () ) )
return 1 ;
if ( V_38 & V_437 )
return 1 ;
if ( F_201 ( V_2 -> V_138 , & V_2 -> V_5 . V_396 . V_403 ,
V_38 & V_438 ,
sizeof( struct V_405 ) ) )
return 1 ;
V_2 -> V_5 . V_396 . V_392 = V_38 ;
if ( ! ( V_38 & V_397 ) )
break;
F_30 ( V_439 , V_2 ) ;
break;
case V_440 :
if ( F_213 ( V_2 , V_38 ) )
return 1 ;
break;
case V_372 :
case V_370 :
case V_375 ... F_193 ( V_441 ) - 1 :
return F_192 ( V_2 , V_21 , V_38 ) ;
case V_442 ... V_443 :
case V_444 ... V_445 :
V_406 = true ;
case V_446 ... V_447 :
case V_448 ... V_449 :
if ( F_214 ( V_2 , V_21 ) )
return F_215 ( V_2 , V_33 ) ;
if ( V_406 || V_38 != 0 )
F_207 ( V_2 , L_13
L_14 , V_21 , V_38 ) ;
break;
case V_450 :
break;
case V_451 ... V_452 :
case V_453 ... V_454 :
case V_455 :
return F_216 ( V_2 , V_21 , V_38 ,
V_33 -> V_40 ) ;
case V_456 :
F_207 ( V_2 , L_15 , V_21 , V_38 ) ;
break;
case V_457 :
if ( ! F_217 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_458 . V_459 = V_38 ;
break;
case V_460 :
if ( ! F_217 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_458 . V_461 = V_38 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_138 -> V_5 . F_194 . V_21 ) )
return F_194 ( V_2 , V_38 ) ;
if ( F_214 ( V_2 , V_21 ) )
return F_215 ( V_2 , V_33 ) ;
if ( ! V_462 ) {
F_207 ( V_2 , L_16 ,
V_21 , V_38 ) ;
return 1 ;
} else {
F_207 ( V_2 , L_15 ,
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
static int F_218 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_464 )
{
T_2 V_38 ;
T_2 V_368 = V_2 -> V_5 . V_368 ;
unsigned V_369 = V_368 & 0xff ;
switch ( V_21 ) {
case V_465 :
case V_466 :
V_38 = 0 ;
break;
case V_467 :
V_38 = V_2 -> V_5 . V_368 ;
break;
case V_372 :
if ( ! ( V_368 & V_373 ) )
return 1 ;
V_38 = V_2 -> V_5 . V_374 ;
break;
case V_370 :
V_38 = V_2 -> V_5 . V_371 ;
break;
default:
if ( V_21 >= V_375 &&
V_21 < F_193 ( V_369 ) ) {
T_1 V_94 = V_21 - V_375 ;
V_38 = V_2 -> V_5 . V_376 [ V_94 ] ;
break;
}
return 1 ;
}
* V_464 = V_38 ;
return 0 ;
}
int F_219 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
switch ( V_33 -> V_146 ) {
case V_468 :
case V_469 :
case V_416 :
case V_470 :
case V_471 :
case V_472 :
case V_473 :
case V_474 :
case V_475 :
case V_476 :
case V_414 :
case V_410 :
case V_477 :
case V_407 :
case V_415 :
case V_412 :
V_33 -> V_38 = 0 ;
break;
case V_446 ... V_447 :
case V_442 ... V_443 :
case V_444 ... V_445 :
case V_448 ... V_449 :
if ( F_214 ( V_2 , V_33 -> V_146 ) )
return F_220 ( V_2 , V_33 -> V_146 , & V_33 -> V_38 ) ;
V_33 -> V_38 = 0 ;
break;
case V_408 :
V_33 -> V_38 = 0x100000000ULL ;
break;
case V_478 :
case 0x200 ... 0x2ff :
return F_221 ( V_2 , V_33 -> V_146 , & V_33 -> V_38 ) ;
case 0xcd :
V_33 -> V_38 = 3 ;
break;
case V_479 :
V_33 -> V_38 = 1 << 24 ;
break;
case V_419 :
V_33 -> V_38 = F_19 ( V_2 ) ;
break;
case V_420 ... V_420 + 0x3ff :
return F_222 ( V_2 , V_33 -> V_146 , & V_33 -> V_38 ) ;
break;
case V_421 :
V_33 -> V_38 = F_223 ( V_2 ) ;
break;
case V_422 :
V_33 -> V_38 = ( T_2 ) V_2 -> V_5 . V_302 ;
break;
case V_424 :
V_33 -> V_38 = V_2 -> V_5 . V_425 ;
break;
case V_426 :
if ( ! V_33 -> V_40 )
return 1 ;
V_33 -> V_38 = V_2 -> V_5 . V_427 ;
break;
case V_480 :
V_33 -> V_38 = 1000ULL ;
V_33 -> V_38 |= ( ( ( T_9 ) 4ULL ) << 40 ) ;
break;
case V_413 :
V_33 -> V_38 = V_2 -> V_5 . V_131 ;
break;
case V_429 :
case V_428 :
V_33 -> V_38 = V_2 -> V_138 -> V_5 . V_239 ;
break;
case V_431 :
case V_430 :
V_33 -> V_38 = V_2 -> V_5 . time ;
break;
case V_435 :
V_33 -> V_38 = V_2 -> V_5 . V_6 . V_392 ;
break;
case V_436 :
V_33 -> V_38 = V_2 -> V_5 . V_396 . V_392 ;
break;
case V_440 :
V_33 -> V_38 = V_2 -> V_5 . V_481 . V_392 ;
break;
case V_465 :
case V_466 :
case V_467 :
case V_372 :
case V_370 :
case V_375 ... F_193 ( V_441 ) - 1 :
return F_218 ( V_2 , V_33 -> V_146 , & V_33 -> V_38 ) ;
case V_450 :
V_33 -> V_38 = 0x20000000 ;
break;
case V_451 ... V_452 :
case V_453 ... V_454 :
case V_455 :
return F_224 ( V_2 ,
V_33 -> V_146 , & V_33 -> V_38 ) ;
break;
case V_456 :
V_33 -> V_38 = 0xbe702111 ;
break;
case V_457 :
if ( ! F_217 ( V_2 ) )
return 1 ;
V_33 -> V_38 = V_2 -> V_5 . V_458 . V_459 ;
break;
case V_460 :
if ( ! F_217 ( V_2 ) )
return 1 ;
V_33 -> V_38 = V_2 -> V_5 . V_458 . V_461 ;
break;
default:
if ( F_214 ( V_2 , V_33 -> V_146 ) )
return F_220 ( V_2 , V_33 -> V_146 , & V_33 -> V_38 ) ;
if ( ! V_462 ) {
F_207 ( V_2 , L_17 , V_33 -> V_146 ) ;
return 1 ;
} else {
F_207 ( V_2 , L_18 , V_33 -> V_146 ) ;
V_33 -> V_38 = 0 ;
}
break;
}
return 0 ;
}
static int F_225 ( struct V_1 * V_2 , struct V_482 * V_19 ,
struct V_483 * V_484 ,
int (* F_226)( struct V_1 * V_2 ,
unsigned V_146 , T_2 * V_38 ) )
{
int V_3 , V_485 ;
V_485 = F_227 ( & V_2 -> V_138 -> V_486 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_487 ; ++ V_3 )
if ( F_226 ( V_2 , V_484 [ V_3 ] . V_146 , & V_484 [ V_3 ] . V_38 ) )
break;
F_228 ( & V_2 -> V_138 -> V_486 , V_485 ) ;
return V_3 ;
}
static int F_229 ( struct V_1 * V_2 , struct V_482 T_15 * V_488 ,
int (* F_226)( struct V_1 * V_2 ,
unsigned V_146 , T_2 * V_38 ) ,
int V_489 )
{
struct V_482 V_19 ;
struct V_483 * V_484 ;
int V_120 , V_490 ;
unsigned V_491 ;
V_120 = - V_101 ;
if ( F_230 ( & V_19 , V_488 , sizeof V_19 ) )
goto V_113;
V_120 = - V_388 ;
if ( V_19 . V_487 >= V_492 )
goto V_113;
V_491 = sizeof( struct V_483 ) * V_19 . V_487 ;
V_484 = F_195 ( V_488 -> V_484 , V_491 ) ;
if ( F_196 ( V_484 ) ) {
V_120 = F_197 ( V_484 ) ;
goto V_113;
}
V_120 = V_490 = F_225 ( V_2 , & V_19 , V_484 , F_226 ) ;
if ( V_120 < 0 )
goto V_390;
V_120 = - V_101 ;
if ( V_489 && F_231 ( V_488 -> V_484 , V_484 , V_491 ) )
goto V_390;
V_120 = V_490 ;
V_390:
F_199 ( V_484 ) ;
V_113:
return V_120 ;
}
int F_232 ( struct V_138 * V_138 , long V_493 )
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
#ifdef F_233
case V_534 :
case V_535 :
#endif
V_120 = 1 ;
break;
case V_536 :
V_120 = V_73 -> V_537 () ;
break;
case V_538 :
V_120 = V_539 ;
break;
case V_540 :
V_120 = ! V_73 -> V_541 () ;
break;
case V_542 :
V_120 = V_543 ;
break;
case V_544 :
V_120 = V_545 ;
break;
case V_546 :
V_120 = V_547 ;
break;
case V_548 :
V_120 = 0 ;
break;
#ifdef F_233
case V_549 :
V_120 = F_234 ( & V_550 ) ;
break;
#endif
case V_551 :
V_120 = V_441 ;
break;
case V_552 :
V_120 = V_553 ;
break;
case V_554 :
V_120 = V_273 ;
break;
default:
V_120 = 0 ;
break;
}
return V_120 ;
}
long F_235 ( struct V_555 * V_556 ,
unsigned int V_557 , unsigned long V_558 )
{
void T_15 * V_559 = ( void T_15 * ) V_558 ;
long V_120 ;
switch ( V_557 ) {
case V_560 : {
struct V_561 T_15 * V_562 = V_559 ;
struct V_561 V_563 ;
unsigned V_490 ;
V_120 = - V_101 ;
if ( F_230 ( & V_563 , V_562 , sizeof V_563 ) )
goto V_113;
V_490 = V_563 . V_487 ;
V_563 . V_487 = V_564 + V_565 ;
if ( F_231 ( V_562 , & V_563 , sizeof V_563 ) )
goto V_113;
V_120 = - V_388 ;
if ( V_490 < V_563 . V_487 )
goto V_113;
V_120 = - V_101 ;
if ( F_231 ( V_562 -> V_566 , & V_567 ,
V_564 * sizeof( T_1 ) ) )
goto V_113;
if ( F_231 ( V_562 -> V_566 + V_564 ,
& V_568 ,
V_565 * sizeof( T_1 ) ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_569 :
case V_570 : {
struct V_571 T_15 * V_572 = V_559 ;
struct V_571 V_573 ;
V_120 = - V_101 ;
if ( F_230 ( & V_573 , V_572 , sizeof V_573 ) )
goto V_113;
V_120 = F_236 ( & V_573 , V_572 -> V_484 ,
V_557 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_231 ( V_572 , & V_573 , sizeof V_573 ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_574 : {
T_2 V_575 ;
V_575 = V_576 ;
V_120 = - V_101 ;
if ( F_231 ( V_559 , & V_575 , sizeof V_575 ) )
goto V_113;
V_120 = 0 ;
break;
}
default:
V_120 = - V_577 ;
}
V_113:
return V_120 ;
}
static void F_237 ( void * V_578 )
{
F_238 () ;
}
static bool F_239 ( struct V_1 * V_2 )
{
return F_66 ( V_2 -> V_138 ) ;
}
void F_240 ( struct V_1 * V_2 , int V_23 )
{
if ( F_239 ( V_2 ) ) {
if ( V_73 -> V_579 () )
F_241 ( V_23 , V_2 -> V_5 . V_580 ) ;
else if ( V_2 -> V_23 != - 1 && V_2 -> V_23 != V_23 )
F_242 ( V_2 -> V_23 ,
F_237 , NULL , 1 ) ;
}
V_73 -> V_581 ( V_2 , V_23 ) ;
if ( F_166 ( V_2 -> V_5 . V_582 ) ) {
F_159 ( V_2 , V_2 -> V_5 . V_582 ) ;
V_2 -> V_5 . V_582 = 0 ;
F_30 ( V_339 , V_2 ) ;
}
if ( F_166 ( V_2 -> V_23 != V_23 ) || F_153 () ) {
T_12 V_583 = ! V_2 -> V_5 . V_584 ? 0 :
F_148 () - V_2 -> V_5 . V_584 ;
if ( V_583 < 0 )
F_243 ( L_19 ) ;
if ( F_153 () ) {
T_2 V_94 = F_147 ( V_2 ,
V_2 -> V_5 . V_325 ) ;
V_73 -> V_326 ( V_2 , V_94 ) ;
V_2 -> V_5 . V_275 = 1 ;
}
if ( ! V_2 -> V_138 -> V_5 . V_296 || V_2 -> V_23 == - 1 )
F_30 ( V_434 , V_2 ) ;
if ( V_2 -> V_23 != V_23 )
F_244 ( V_2 ) ;
V_2 -> V_23 = V_23 ;
}
F_30 ( V_439 , V_2 ) ;
}
void F_245 ( struct V_1 * V_2 )
{
V_73 -> V_585 ( V_2 ) ;
F_246 ( V_2 ) ;
V_2 -> V_5 . V_584 = F_148 () ;
}
static int F_247 ( struct V_1 * V_2 ,
struct V_586 * V_587 )
{
V_73 -> V_588 ( V_2 ) ;
memcpy ( V_587 -> V_589 , V_2 -> V_5 . V_590 -> V_589 , sizeof *V_587 ) ;
return 0 ;
}
static int F_248 ( struct V_1 * V_2 ,
struct V_586 * V_587 )
{
F_249 ( V_2 , V_587 ) ;
F_250 ( V_2 ) ;
return 0 ;
}
static int F_251 ( struct V_1 * V_2 )
{
return ( ! F_88 ( V_2 ) ||
F_252 ( V_2 ) ) ;
}
static int F_253 ( struct V_1 * V_2 )
{
return F_254 ( V_2 ) &&
! F_255 ( V_2 ) &&
! F_256 ( V_2 ) &&
F_251 ( V_2 ) ;
}
static int F_257 ( struct V_1 * V_2 ,
struct V_591 * V_592 )
{
if ( V_592 -> V_592 >= V_593 )
return - V_577 ;
if ( ! F_258 ( V_2 -> V_138 ) ) {
F_259 ( V_2 , V_592 -> V_592 , false ) ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
if ( F_260 ( V_2 -> V_138 ) )
return - V_594 ;
if ( V_2 -> V_5 . V_595 != - 1 )
return - V_596 ;
V_2 -> V_5 . V_595 = V_592 -> V_592 ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
static int F_261 ( struct V_1 * V_2 )
{
F_40 ( V_2 ) ;
return 0 ;
}
static int F_262 ( struct V_1 * V_2 )
{
F_30 ( V_597 , V_2 ) ;
return 0 ;
}
static int F_263 ( struct V_1 * V_2 ,
struct V_598 * V_599 )
{
if ( V_599 -> V_309 )
return - V_577 ;
V_2 -> V_5 . V_600 = ! ! V_599 -> V_601 ;
return 0 ;
}
static int F_264 ( struct V_1 * V_2 ,
T_2 V_368 )
{
int V_120 ;
unsigned V_369 = V_368 & 0xff , V_602 ;
V_120 = - V_577 ;
if ( ! V_369 || V_369 >= V_441 )
goto V_113;
if ( V_368 & ~ ( V_576 | 0xff | 0xff0000 ) )
goto V_113;
V_120 = 0 ;
V_2 -> V_5 . V_368 = V_368 ;
if ( V_368 & V_373 )
V_2 -> V_5 . V_374 = ~ ( T_2 ) 0 ;
for ( V_602 = 0 ; V_602 < V_369 ; V_602 ++ )
V_2 -> V_5 . V_376 [ V_602 * 4 ] = ~ ( T_2 ) 0 ;
V_113:
return V_120 ;
}
static int F_265 ( struct V_1 * V_2 ,
struct V_603 * V_604 )
{
T_2 V_368 = V_2 -> V_5 . V_368 ;
unsigned V_369 = V_368 & 0xff ;
T_2 * V_605 = V_2 -> V_5 . V_376 ;
if ( V_604 -> V_602 >= V_369 || ! ( V_604 -> V_461 & V_606 ) )
return - V_577 ;
if ( ( V_604 -> V_461 & V_607 ) && ( V_368 & V_373 ) &&
V_2 -> V_5 . V_374 != ~ ( T_2 ) 0 )
return 0 ;
V_605 += 4 * V_604 -> V_602 ;
if ( ( V_604 -> V_461 & V_607 ) && V_605 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_604 -> V_461 & V_607 ) {
if ( ( V_2 -> V_5 . V_371 & V_608 ) ||
! F_45 ( V_2 , V_609 ) ) {
F_30 ( V_72 , V_2 ) ;
return 0 ;
}
if ( V_605 [ 1 ] & V_606 )
V_604 -> V_461 |= V_610 ;
V_605 [ 2 ] = V_604 -> V_611 ;
V_605 [ 3 ] = V_604 -> V_612 ;
V_2 -> V_5 . V_371 = V_604 -> V_371 ;
V_605 [ 1 ] = V_604 -> V_461 ;
F_32 ( V_2 , V_58 ) ;
} else if ( ! ( V_605 [ 1 ] & V_606 )
|| ! ( V_605 [ 1 ] & V_607 ) ) {
if ( V_605 [ 1 ] & V_606 )
V_604 -> V_461 |= V_610 ;
V_605 [ 2 ] = V_604 -> V_611 ;
V_605 [ 3 ] = V_604 -> V_612 ;
V_605 [ 1 ] = V_604 -> V_461 ;
} else
V_605 [ 1 ] |= V_610 ;
return 0 ;
}
static void F_266 ( struct V_1 * V_2 ,
struct V_613 * V_614 )
{
F_267 ( V_2 ) ;
V_614 -> V_68 . V_615 =
V_2 -> V_5 . V_68 . V_69 &&
! F_268 ( V_2 -> V_5 . V_68 . V_16 ) ;
V_614 -> V_68 . V_16 = V_2 -> V_5 . V_68 . V_16 ;
V_614 -> V_68 . V_71 = V_2 -> V_5 . V_68 . V_71 ;
V_614 -> V_68 . V_616 = 0 ;
V_614 -> V_68 . V_62 = V_2 -> V_5 . V_68 . V_62 ;
V_614 -> V_617 . V_615 =
V_2 -> V_5 . V_617 . V_69 && ! V_2 -> V_5 . V_617 . V_618 ;
V_614 -> V_617 . V_16 = V_2 -> V_5 . V_617 . V_16 ;
V_614 -> V_617 . V_618 = 0 ;
V_614 -> V_617 . V_619 = V_73 -> V_620 ( V_2 ) ;
V_614 -> V_621 . V_615 = V_2 -> V_5 . V_622 ;
V_614 -> V_621 . V_69 = V_2 -> V_5 . V_623 != 0 ;
V_614 -> V_621 . V_624 = V_73 -> V_625 ( V_2 ) ;
V_614 -> V_621 . V_616 = 0 ;
V_614 -> V_626 = 0 ;
V_614 -> V_627 . V_628 = F_269 ( V_2 ) ;
V_614 -> V_627 . V_69 = V_2 -> V_5 . V_629 ;
V_614 -> V_627 . V_630 =
! ! ( V_2 -> V_5 . V_631 & V_632 ) ;
V_614 -> V_627 . V_633 = F_270 ( V_2 ) ;
V_614 -> V_309 = ( V_634
| V_635
| V_636 ) ;
memset ( & V_614 -> V_637 , 0 , sizeof( V_614 -> V_637 ) ) ;
}
static int F_271 ( struct V_1 * V_2 ,
struct V_613 * V_614 )
{
if ( V_614 -> V_309 & ~ ( V_634
| V_638
| V_635
| V_636 ) )
return - V_577 ;
F_267 ( V_2 ) ;
V_2 -> V_5 . V_68 . V_69 = V_614 -> V_68 . V_615 ;
V_2 -> V_5 . V_68 . V_16 = V_614 -> V_68 . V_16 ;
V_2 -> V_5 . V_68 . V_71 = V_614 -> V_68 . V_71 ;
V_2 -> V_5 . V_68 . V_62 = V_614 -> V_68 . V_62 ;
V_2 -> V_5 . V_617 . V_69 = V_614 -> V_617 . V_615 ;
V_2 -> V_5 . V_617 . V_16 = V_614 -> V_617 . V_16 ;
V_2 -> V_5 . V_617 . V_618 = V_614 -> V_617 . V_618 ;
if ( V_614 -> V_309 & V_635 )
V_73 -> V_639 ( V_2 ,
V_614 -> V_617 . V_619 ) ;
V_2 -> V_5 . V_622 = V_614 -> V_621 . V_615 ;
if ( V_614 -> V_309 & V_634 )
V_2 -> V_5 . V_623 = V_614 -> V_621 . V_69 ;
V_73 -> V_640 ( V_2 , V_614 -> V_621 . V_624 ) ;
if ( V_614 -> V_309 & V_638 &&
F_272 ( V_2 ) )
V_2 -> V_5 . V_590 -> V_626 = V_614 -> V_626 ;
if ( V_614 -> V_309 & V_636 ) {
if ( V_614 -> V_627 . V_628 )
V_2 -> V_5 . V_631 |= V_641 ;
else
V_2 -> V_5 . V_631 &= ~ V_641 ;
V_2 -> V_5 . V_629 = V_614 -> V_627 . V_69 ;
if ( V_614 -> V_627 . V_630 )
V_2 -> V_5 . V_631 |= V_632 ;
else
V_2 -> V_5 . V_631 &= ~ V_632 ;
if ( F_272 ( V_2 ) ) {
if ( V_614 -> V_627 . V_633 )
F_211 ( V_642 , & V_2 -> V_5 . V_590 -> V_643 ) ;
else
F_175 ( V_642 , & V_2 -> V_5 . V_590 -> V_643 ) ;
}
}
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
static void F_273 ( struct V_1 * V_2 ,
struct V_644 * V_645 )
{
unsigned long V_194 ;
memcpy ( V_645 -> V_181 , V_2 -> V_5 . V_181 , sizeof( V_2 -> V_5 . V_181 ) ) ;
F_99 ( V_2 , 6 , & V_194 ) ;
V_645 -> V_185 = V_194 ;
V_645 -> V_186 = V_2 -> V_5 . V_186 ;
V_645 -> V_309 = 0 ;
memset ( & V_645 -> V_637 , 0 , sizeof( V_645 -> V_637 ) ) ;
}
static int F_274 ( struct V_1 * V_2 ,
struct V_644 * V_645 )
{
if ( V_645 -> V_309 )
return - V_577 ;
memcpy ( V_2 -> V_5 . V_181 , V_645 -> V_181 , sizeof( V_2 -> V_5 . V_181 ) ) ;
F_92 ( V_2 ) ;
V_2 -> V_5 . V_185 = V_645 -> V_185 ;
F_93 ( V_2 ) ;
V_2 -> V_5 . V_186 = V_645 -> V_186 ;
F_94 ( V_2 ) ;
return 0 ;
}
static void F_275 ( T_14 * V_646 , struct V_1 * V_2 )
{
struct V_647 * V_648 = & V_2 -> V_5 . V_649 . V_650 . V_648 ;
T_2 V_651 = V_648 -> V_652 . V_653 ;
T_2 V_654 ;
memcpy ( V_646 , V_648 , V_655 ) ;
* ( T_2 * ) ( V_646 + V_655 ) = V_651 ;
V_654 = V_651 & ~ V_656 ;
while ( V_654 ) {
T_2 V_657 = V_654 & - V_654 ;
int V_146 = F_276 ( V_657 ) - 1 ;
void * V_658 = F_277 ( V_648 , V_657 ) ;
if ( V_658 ) {
T_1 V_491 , V_94 , V_199 , V_207 ;
F_278 ( V_659 , V_146 ,
& V_491 , & V_94 , & V_199 , & V_207 ) ;
memcpy ( V_646 + V_94 , V_658 , V_491 ) ;
}
V_654 -= V_657 ;
}
}
static void F_279 ( struct V_1 * V_2 , T_14 * V_658 )
{
struct V_647 * V_648 = & V_2 -> V_5 . V_649 . V_650 . V_648 ;
T_2 V_651 = * ( T_2 * ) ( V_658 + V_655 ) ;
T_2 V_654 ;
memcpy ( V_648 , V_658 , V_655 ) ;
V_648 -> V_652 . V_653 = V_651 ;
if ( V_660 )
V_648 -> V_652 . V_661 = V_145 | V_662 ;
V_654 = V_651 & ~ V_656 ;
while ( V_654 ) {
T_2 V_657 = V_654 & - V_654 ;
int V_146 = F_276 ( V_657 ) - 1 ;
void * V_646 = F_277 ( V_648 , V_657 ) ;
if ( V_646 ) {
T_1 V_491 , V_94 , V_199 , V_207 ;
F_278 ( V_659 , V_146 ,
& V_491 , & V_94 , & V_199 , & V_207 ) ;
memcpy ( V_646 , V_658 + V_94 , V_491 ) ;
}
V_654 -= V_657 ;
}
}
static void F_280 ( struct V_1 * V_2 ,
struct V_663 * V_664 )
{
if ( V_553 ) {
memset ( V_664 , 0 , sizeof( struct V_663 ) ) ;
F_275 ( ( T_14 * ) V_664 -> V_665 , V_2 ) ;
} else {
memcpy ( V_664 -> V_665 ,
& V_2 -> V_5 . V_649 . V_650 . V_666 ,
sizeof( struct V_667 ) ) ;
* ( T_2 * ) & V_664 -> V_665 [ V_655 / sizeof( T_1 ) ] =
V_656 ;
}
}
static int F_281 ( struct V_1 * V_2 ,
struct V_663 * V_664 )
{
T_2 V_651 =
* ( T_2 * ) & V_664 -> V_665 [ V_655 / sizeof( T_1 ) ] ;
if ( V_553 ) {
if ( V_651 & ~ F_282 () )
return - V_577 ;
F_279 ( V_2 , ( T_14 * ) V_664 -> V_665 ) ;
} else {
if ( V_651 & ~ V_656 )
return - V_577 ;
memcpy ( & V_2 -> V_5 . V_649 . V_650 . V_666 ,
V_664 -> V_665 , sizeof( struct V_667 ) ) ;
}
return 0 ;
}
static void F_283 ( struct V_1 * V_2 ,
struct V_668 * V_669 )
{
if ( ! V_553 ) {
V_669 -> V_670 = 0 ;
return;
}
V_669 -> V_670 = 1 ;
V_669 -> V_309 = 0 ;
V_669 -> V_671 [ 0 ] . V_147 = V_143 ;
V_669 -> V_671 [ 0 ] . V_22 = V_2 -> V_5 . V_144 ;
}
static int F_284 ( struct V_1 * V_2 ,
struct V_668 * V_669 )
{
int V_3 , V_120 = 0 ;
if ( ! V_553 )
return - V_577 ;
if ( V_669 -> V_670 > V_672 || V_669 -> V_309 )
return - V_577 ;
for ( V_3 = 0 ; V_3 < V_669 -> V_670 ; V_3 ++ )
if ( V_669 -> V_671 [ V_3 ] . V_147 == V_143 ) {
V_120 = F_74 ( V_2 , V_143 ,
V_669 -> V_671 [ V_3 ] . V_22 ) ;
break;
}
if ( V_120 )
V_120 = - V_577 ;
return V_120 ;
}
static int F_285 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_349 )
return - V_577 ;
V_2 -> V_5 . V_357 = true ;
F_30 ( V_339 , V_2 ) ;
return 0 ;
}
long F_286 ( struct V_555 * V_556 ,
unsigned int V_557 , unsigned long V_558 )
{
struct V_1 * V_2 = V_556 -> V_673 ;
void T_15 * V_559 = ( void T_15 * ) V_558 ;
int V_120 ;
union {
struct V_586 * V_674 ;
struct V_663 * V_648 ;
struct V_668 * V_671 ;
void * V_675 ;
} V_676 ;
V_676 . V_675 = NULL ;
switch ( V_557 ) {
case V_677 : {
V_120 = - V_577 ;
if ( ! V_2 -> V_5 . V_590 )
goto V_113;
V_676 . V_674 = F_287 ( sizeof( struct V_586 ) , V_678 ) ;
V_120 = - V_389 ;
if ( ! V_676 . V_674 )
goto V_113;
V_120 = F_247 ( V_2 , V_676 . V_674 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_231 ( V_559 , V_676 . V_674 , sizeof( struct V_586 ) ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_679 : {
V_120 = - V_577 ;
if ( ! V_2 -> V_5 . V_590 )
goto V_113;
V_676 . V_674 = F_195 ( V_559 , sizeof( * V_676 . V_674 ) ) ;
if ( F_196 ( V_676 . V_674 ) )
return F_197 ( V_676 . V_674 ) ;
V_120 = F_248 ( V_2 , V_676 . V_674 ) ;
break;
}
case V_680 : {
struct V_591 V_592 ;
V_120 = - V_101 ;
if ( F_230 ( & V_592 , V_559 , sizeof V_592 ) )
goto V_113;
V_120 = F_257 ( V_2 , & V_592 ) ;
break;
}
case V_681 : {
V_120 = F_261 ( V_2 ) ;
break;
}
case V_682 : {
V_120 = F_262 ( V_2 ) ;
break;
}
case V_683 : {
struct V_684 T_15 * V_572 = V_559 ;
struct V_684 V_573 ;
V_120 = - V_101 ;
if ( F_230 ( & V_573 , V_572 , sizeof V_573 ) )
goto V_113;
V_120 = F_288 ( V_2 , & V_573 , V_572 -> V_484 ) ;
break;
}
case V_685 : {
struct V_571 T_15 * V_572 = V_559 ;
struct V_571 V_573 ;
V_120 = - V_101 ;
if ( F_230 ( & V_573 , V_572 , sizeof V_573 ) )
goto V_113;
V_120 = F_289 ( V_2 , & V_573 ,
V_572 -> V_484 ) ;
break;
}
case V_686 : {
struct V_571 T_15 * V_572 = V_559 ;
struct V_571 V_573 ;
V_120 = - V_101 ;
if ( F_230 ( & V_573 , V_572 , sizeof V_573 ) )
goto V_113;
V_120 = F_290 ( V_2 , & V_573 ,
V_572 -> V_484 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_231 ( V_572 , & V_573 , sizeof V_573 ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_687 :
V_120 = F_229 ( V_2 , V_559 , F_112 , 1 ) ;
break;
case V_688 :
V_120 = F_229 ( V_2 , V_559 , F_114 , 0 ) ;
break;
case V_689 : {
struct V_598 V_599 ;
V_120 = - V_101 ;
if ( F_230 ( & V_599 , V_559 , sizeof V_599 ) )
goto V_113;
V_120 = F_263 ( V_2 , & V_599 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_231 ( V_559 , & V_599 , sizeof V_599 ) )
goto V_113;
V_120 = 0 ;
break;
} ;
case V_690 : {
struct V_691 V_692 ;
V_120 = - V_577 ;
if ( ! F_88 ( V_2 ) )
goto V_113;
V_120 = - V_101 ;
if ( F_230 ( & V_692 , V_559 , sizeof V_692 ) )
goto V_113;
V_120 = F_291 ( V_2 , V_692 . V_693 ) ;
break;
}
case V_694 : {
T_2 V_368 ;
V_120 = - V_101 ;
if ( F_230 ( & V_368 , V_559 , sizeof V_368 ) )
goto V_113;
V_120 = F_264 ( V_2 , V_368 ) ;
break;
}
case V_695 : {
struct V_603 V_604 ;
V_120 = - V_101 ;
if ( F_230 ( & V_604 , V_559 , sizeof V_604 ) )
goto V_113;
V_120 = F_265 ( V_2 , & V_604 ) ;
break;
}
case V_696 : {
struct V_613 V_614 ;
F_266 ( V_2 , & V_614 ) ;
V_120 = - V_101 ;
if ( F_231 ( V_559 , & V_614 , sizeof( struct V_613 ) ) )
break;
V_120 = 0 ;
break;
}
case V_697 : {
struct V_613 V_614 ;
V_120 = - V_101 ;
if ( F_230 ( & V_614 , V_559 , sizeof( struct V_613 ) ) )
break;
V_120 = F_271 ( V_2 , & V_614 ) ;
break;
}
case V_698 : {
struct V_644 V_645 ;
F_273 ( V_2 , & V_645 ) ;
V_120 = - V_101 ;
if ( F_231 ( V_559 , & V_645 ,
sizeof( struct V_644 ) ) )
break;
V_120 = 0 ;
break;
}
case V_699 : {
struct V_644 V_645 ;
V_120 = - V_101 ;
if ( F_230 ( & V_645 , V_559 ,
sizeof( struct V_644 ) ) )
break;
V_120 = F_274 ( V_2 , & V_645 ) ;
break;
}
case V_700 : {
V_676 . V_648 = F_287 ( sizeof( struct V_663 ) , V_678 ) ;
V_120 = - V_389 ;
if ( ! V_676 . V_648 )
break;
F_280 ( V_2 , V_676 . V_648 ) ;
V_120 = - V_101 ;
if ( F_231 ( V_559 , V_676 . V_648 , sizeof( struct V_663 ) ) )
break;
V_120 = 0 ;
break;
}
case V_701 : {
V_676 . V_648 = F_195 ( V_559 , sizeof( * V_676 . V_648 ) ) ;
if ( F_196 ( V_676 . V_648 ) )
return F_197 ( V_676 . V_648 ) ;
V_120 = F_281 ( V_2 , V_676 . V_648 ) ;
break;
}
case V_702 : {
V_676 . V_671 = F_287 ( sizeof( struct V_668 ) , V_678 ) ;
V_120 = - V_389 ;
if ( ! V_676 . V_671 )
break;
F_283 ( V_2 , V_676 . V_671 ) ;
V_120 = - V_101 ;
if ( F_231 ( V_559 , V_676 . V_671 ,
sizeof( struct V_668 ) ) )
break;
V_120 = 0 ;
break;
}
case V_703 : {
V_676 . V_671 = F_195 ( V_559 , sizeof( * V_676 . V_671 ) ) ;
if ( F_196 ( V_676 . V_671 ) )
return F_197 ( V_676 . V_671 ) ;
V_120 = F_284 ( V_2 , V_676 . V_671 ) ;
break;
}
case V_704 : {
T_1 V_268 ;
V_120 = - V_577 ;
V_268 = ( T_1 ) V_558 ;
if ( V_268 >= V_705 )
goto V_113;
if ( V_268 == 0 )
V_268 = V_274 ;
if ( ! F_138 ( V_2 , V_268 ) )
V_120 = 0 ;
goto V_113;
}
case V_706 : {
V_120 = V_2 -> V_5 . V_284 ;
goto V_113;
}
case V_707 : {
V_120 = F_285 ( V_2 ) ;
goto V_113;
}
default:
V_120 = - V_577 ;
}
V_113:
F_199 ( V_676 . V_675 ) ;
return V_120 ;
}
int F_292 ( struct V_1 * V_2 , struct V_708 * V_709 )
{
return V_710 ;
}
static int F_293 ( struct V_138 * V_138 , unsigned long V_611 )
{
int V_108 ;
if ( V_611 > ( unsigned int ) ( - 3 * V_107 ) )
return - V_577 ;
V_108 = V_73 -> V_711 ( V_138 , V_611 ) ;
return V_108 ;
}
static int F_294 ( struct V_138 * V_138 ,
T_2 V_712 )
{
V_138 -> V_5 . V_713 = V_712 ;
return 0 ;
}
static int F_295 ( struct V_138 * V_138 ,
T_1 V_714 )
{
if ( V_714 < V_715 )
return - V_577 ;
F_296 ( & V_138 -> V_716 ) ;
F_297 ( V_138 , V_714 ) ;
V_138 -> V_5 . V_717 = V_714 ;
F_298 ( & V_138 -> V_716 ) ;
return 0 ;
}
static int F_299 ( struct V_138 * V_138 )
{
return V_138 -> V_5 . V_718 ;
}
static int F_300 ( struct V_138 * V_138 , struct V_719 * V_720 )
{
int V_120 ;
V_120 = 0 ;
switch ( V_720 -> V_721 ) {
case V_722 :
memcpy ( & V_720 -> V_720 . V_723 ,
& F_301 ( V_138 ) -> V_724 [ 0 ] ,
sizeof( struct V_725 ) ) ;
break;
case V_726 :
memcpy ( & V_720 -> V_720 . V_723 ,
& F_301 ( V_138 ) -> V_724 [ 1 ] ,
sizeof( struct V_725 ) ) ;
break;
case V_727 :
V_120 = F_302 ( V_138 , & V_720 -> V_720 . V_728 ) ;
break;
default:
V_120 = - V_577 ;
break;
}
return V_120 ;
}
static int F_303 ( struct V_138 * V_138 , struct V_719 * V_720 )
{
int V_120 ;
V_120 = 0 ;
switch ( V_720 -> V_721 ) {
case V_722 :
F_156 ( & F_301 ( V_138 ) -> V_729 ) ;
memcpy ( & F_301 ( V_138 ) -> V_724 [ 0 ] ,
& V_720 -> V_720 . V_723 ,
sizeof( struct V_725 ) ) ;
F_157 ( & F_301 ( V_138 ) -> V_729 ) ;
break;
case V_726 :
F_156 ( & F_301 ( V_138 ) -> V_729 ) ;
memcpy ( & F_301 ( V_138 ) -> V_724 [ 1 ] ,
& V_720 -> V_720 . V_723 ,
sizeof( struct V_725 ) ) ;
F_157 ( & F_301 ( V_138 ) -> V_729 ) ;
break;
case V_727 :
V_120 = F_304 ( V_138 , & V_720 -> V_720 . V_728 ) ;
break;
default:
V_120 = - V_577 ;
break;
}
F_305 ( F_301 ( V_138 ) ) ;
return V_120 ;
}
static int F_306 ( struct V_138 * V_138 , struct V_730 * V_731 )
{
F_296 ( & V_138 -> V_5 . V_732 -> V_733 . V_729 ) ;
memcpy ( V_731 , & V_138 -> V_5 . V_732 -> V_733 , sizeof( struct V_730 ) ) ;
F_298 ( & V_138 -> V_5 . V_732 -> V_733 . V_729 ) ;
return 0 ;
}
static int F_307 ( struct V_138 * V_138 , struct V_730 * V_731 )
{
int V_3 ;
F_296 ( & V_138 -> V_5 . V_732 -> V_733 . V_729 ) ;
memcpy ( & V_138 -> V_5 . V_732 -> V_733 , V_731 , sizeof( struct V_730 ) ) ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
F_308 ( V_138 , V_3 , V_731 -> V_734 [ V_3 ] . V_735 , 0 ) ;
F_298 ( & V_138 -> V_5 . V_732 -> V_733 . V_729 ) ;
return 0 ;
}
static int F_309 ( struct V_138 * V_138 , struct V_736 * V_731 )
{
F_296 ( & V_138 -> V_5 . V_732 -> V_733 . V_729 ) ;
memcpy ( V_731 -> V_734 , & V_138 -> V_5 . V_732 -> V_733 . V_734 ,
sizeof( V_731 -> V_734 ) ) ;
V_731 -> V_309 = V_138 -> V_5 . V_732 -> V_733 . V_309 ;
F_298 ( & V_138 -> V_5 . V_732 -> V_733 . V_729 ) ;
memset ( & V_731 -> V_637 , 0 , sizeof( V_731 -> V_637 ) ) ;
return 0 ;
}
static int F_310 ( struct V_138 * V_138 , struct V_736 * V_731 )
{
int V_737 = 0 ;
int V_3 ;
T_1 V_738 , V_739 ;
F_296 ( & V_138 -> V_5 . V_732 -> V_733 . V_729 ) ;
V_738 = V_138 -> V_5 . V_732 -> V_733 . V_309 & V_740 ;
V_739 = V_731 -> V_309 & V_740 ;
if ( ! V_738 && V_739 )
V_737 = 1 ;
memcpy ( & V_138 -> V_5 . V_732 -> V_733 . V_734 , & V_731 -> V_734 ,
sizeof( V_138 -> V_5 . V_732 -> V_733 . V_734 ) ) ;
V_138 -> V_5 . V_732 -> V_733 . V_309 = V_731 -> V_309 ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
F_308 ( V_138 , V_3 , V_138 -> V_5 . V_732 -> V_733 . V_734 [ V_3 ] . V_735 ,
V_737 && V_3 == 0 ) ;
F_298 ( & V_138 -> V_5 . V_732 -> V_733 . V_729 ) ;
return 0 ;
}
static int F_311 ( struct V_138 * V_138 ,
struct V_741 * V_742 )
{
if ( ! V_138 -> V_5 . V_732 )
return - V_594 ;
F_296 ( & V_138 -> V_5 . V_732 -> V_733 . V_729 ) ;
V_138 -> V_5 . V_732 -> V_733 . V_63 = V_742 -> V_743 ;
F_298 ( & V_138 -> V_5 . V_732 -> V_733 . V_729 ) ;
return 0 ;
}
int F_312 ( struct V_138 * V_138 , struct V_744 * log )
{
bool V_745 = false ;
int V_120 ;
F_296 ( & V_138 -> V_716 ) ;
if ( V_73 -> V_746 )
V_73 -> V_746 ( V_138 ) ;
V_120 = F_313 ( V_138 , log , & V_745 ) ;
F_314 ( & V_138 -> V_716 ) ;
if ( V_745 )
F_315 ( V_138 ) ;
F_298 ( & V_138 -> V_716 ) ;
return V_120 ;
}
int F_316 ( struct V_138 * V_138 , struct V_747 * V_748 ,
bool V_749 )
{
if ( ! F_258 ( V_138 ) )
return - V_594 ;
V_748 -> V_461 = F_317 ( V_138 , V_750 ,
V_748 -> V_592 , V_748 -> V_751 ,
V_749 ) ;
return 0 ;
}
static int F_318 ( struct V_138 * V_138 ,
struct V_752 * V_753 )
{
int V_120 ;
if ( V_753 -> V_309 )
return - V_577 ;
switch ( V_753 -> V_753 ) {
case V_531 :
V_138 -> V_5 . V_754 = V_753 -> args [ 0 ] ;
V_120 = 0 ;
break;
case V_533 : {
F_296 ( & V_138 -> V_729 ) ;
V_120 = - V_577 ;
if ( V_753 -> args [ 0 ] > V_755 )
goto V_756;
V_120 = - V_596 ;
if ( F_258 ( V_138 ) )
goto V_756;
if ( F_141 ( & V_138 -> V_295 ) )
goto V_756;
V_120 = F_319 ( V_138 ) ;
if ( V_120 )
goto V_756;
F_184 () ;
V_138 -> V_5 . V_757 = true ;
V_138 -> V_5 . V_758 = V_753 -> args [ 0 ] ;
V_120 = 0 ;
V_756:
F_298 ( & V_138 -> V_729 ) ;
break;
}
default:
V_120 = - V_577 ;
break;
}
return V_120 ;
}
long F_320 ( struct V_555 * V_556 ,
unsigned int V_557 , unsigned long V_558 )
{
struct V_138 * V_138 = V_556 -> V_673 ;
void T_15 * V_559 = ( void T_15 * ) V_558 ;
int V_120 = - V_759 ;
union {
struct V_730 V_731 ;
struct V_736 V_760 ;
struct V_761 V_762 ;
} V_676 ;
switch ( V_557 ) {
case V_763 :
V_120 = F_293 ( V_138 , V_558 ) ;
break;
case V_764 : {
T_2 V_712 ;
V_120 = - V_101 ;
if ( F_230 ( & V_712 , V_559 , sizeof V_712 ) )
goto V_113;
V_120 = F_294 ( V_138 , V_712 ) ;
break;
}
case V_765 :
V_120 = F_295 ( V_138 , V_558 ) ;
break;
case V_766 :
V_120 = F_299 ( V_138 ) ;
break;
case V_767 : {
struct V_768 * V_769 ;
F_296 ( & V_138 -> V_729 ) ;
V_120 = - V_596 ;
if ( V_138 -> V_5 . V_769 )
goto V_770;
V_120 = - V_577 ;
if ( F_141 ( & V_138 -> V_295 ) )
goto V_770;
V_120 = - V_389 ;
V_769 = F_321 ( V_138 ) ;
if ( V_769 ) {
V_120 = F_322 ( V_138 ) ;
if ( V_120 ) {
F_296 ( & V_138 -> V_716 ) ;
F_323 ( V_769 ) ;
F_298 ( & V_138 -> V_716 ) ;
goto V_770;
}
} else
goto V_770;
V_120 = F_324 ( V_138 ) ;
if ( V_120 ) {
F_296 ( & V_138 -> V_716 ) ;
F_296 ( & V_138 -> V_771 ) ;
F_325 ( V_138 ) ;
F_323 ( V_769 ) ;
F_298 ( & V_138 -> V_771 ) ;
F_298 ( & V_138 -> V_716 ) ;
goto V_770;
}
F_184 () ;
V_138 -> V_5 . V_769 = V_769 ;
V_770:
F_298 ( & V_138 -> V_729 ) ;
break;
}
case V_772 :
V_676 . V_762 . V_309 = V_773 ;
goto V_774;
case V_775 :
V_120 = - V_101 ;
if ( F_230 ( & V_676 . V_762 , V_559 ,
sizeof( struct V_761 ) ) )
goto V_113;
V_774:
F_296 ( & V_138 -> V_716 ) ;
V_120 = - V_596 ;
if ( V_138 -> V_5 . V_732 )
goto V_776;
V_120 = - V_389 ;
V_138 -> V_5 . V_732 = F_326 ( V_138 , V_676 . V_762 . V_309 ) ;
if ( V_138 -> V_5 . V_732 )
V_120 = 0 ;
V_776:
F_298 ( & V_138 -> V_716 ) ;
break;
case V_777 : {
struct V_719 * V_720 ;
V_720 = F_195 ( V_559 , sizeof( * V_720 ) ) ;
if ( F_196 ( V_720 ) ) {
V_120 = F_197 ( V_720 ) ;
goto V_113;
}
V_120 = - V_594 ;
if ( ! F_258 ( V_138 ) || V_757 ( V_138 ) )
goto V_778;
V_120 = F_300 ( V_138 , V_720 ) ;
if ( V_120 )
goto V_778;
V_120 = - V_101 ;
if ( F_231 ( V_559 , V_720 , sizeof *V_720 ) )
goto V_778;
V_120 = 0 ;
V_778:
F_199 ( V_720 ) ;
break;
}
case V_779 : {
struct V_719 * V_720 ;
V_720 = F_195 ( V_559 , sizeof( * V_720 ) ) ;
if ( F_196 ( V_720 ) ) {
V_120 = F_197 ( V_720 ) ;
goto V_113;
}
V_120 = - V_594 ;
if ( ! F_258 ( V_138 ) || V_757 ( V_138 ) )
goto V_780;
V_120 = F_303 ( V_138 , V_720 ) ;
if ( V_120 )
goto V_780;
V_120 = 0 ;
V_780:
F_199 ( V_720 ) ;
break;
}
case V_781 : {
V_120 = - V_101 ;
if ( F_230 ( & V_676 . V_731 , V_559 , sizeof( struct V_730 ) ) )
goto V_113;
V_120 = - V_594 ;
if ( ! V_138 -> V_5 . V_732 )
goto V_113;
V_120 = F_306 ( V_138 , & V_676 . V_731 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_231 ( V_559 , & V_676 . V_731 , sizeof( struct V_730 ) ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_782 : {
V_120 = - V_101 ;
if ( F_230 ( & V_676 . V_731 , V_559 , sizeof V_676 . V_731 ) )
goto V_113;
V_120 = - V_594 ;
if ( ! V_138 -> V_5 . V_732 )
goto V_113;
V_120 = F_307 ( V_138 , & V_676 . V_731 ) ;
break;
}
case V_783 : {
V_120 = - V_594 ;
if ( ! V_138 -> V_5 . V_732 )
goto V_113;
V_120 = F_309 ( V_138 , & V_676 . V_760 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_231 ( V_559 , & V_676 . V_760 , sizeof( V_676 . V_760 ) ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_784 : {
V_120 = - V_101 ;
if ( F_230 ( & V_676 . V_760 , V_559 , sizeof( V_676 . V_760 ) ) )
goto V_113;
V_120 = - V_594 ;
if ( ! V_138 -> V_5 . V_732 )
goto V_113;
V_120 = F_310 ( V_138 , & V_676 . V_760 ) ;
break;
}
case V_785 : {
struct V_741 V_742 ;
V_120 = - V_101 ;
if ( F_230 ( & V_742 , V_559 , sizeof( V_742 ) ) )
goto V_113;
V_120 = F_311 ( V_138 , & V_742 ) ;
break;
}
case V_786 :
V_120 = 0 ;
F_296 ( & V_138 -> V_729 ) ;
if ( F_141 ( & V_138 -> V_295 ) != 0 )
V_120 = - V_787 ;
else
V_138 -> V_5 . V_788 = V_558 ;
F_298 ( & V_138 -> V_729 ) ;
break;
case V_789 : {
V_120 = - V_101 ;
if ( F_230 ( & V_138 -> V_5 . F_194 , V_559 ,
sizeof( struct V_790 ) ) )
goto V_113;
V_120 = - V_577 ;
if ( V_138 -> V_5 . F_194 . V_309 )
goto V_113;
V_120 = 0 ;
break;
}
case V_791 : {
struct V_792 V_793 ;
T_2 V_794 ;
T_12 V_320 ;
V_120 = - V_101 ;
if ( F_230 ( & V_793 , V_559 , sizeof( V_793 ) ) )
goto V_113;
V_120 = - V_577 ;
if ( V_793 . V_309 )
goto V_113;
V_120 = 0 ;
F_327 () ;
V_794 = F_152 () ;
V_320 = V_793 . clock - V_794 ;
F_328 () ;
V_138 -> V_5 . V_245 = V_320 ;
F_172 ( V_138 ) ;
break;
}
case V_795 : {
struct V_792 V_793 ;
T_2 V_794 ;
F_327 () ;
V_794 = F_152 () ;
V_793 . clock = V_138 -> V_5 . V_245 + V_794 ;
F_328 () ;
V_793 . V_309 = 0 ;
memset ( & V_793 . V_616 , 0 , sizeof( V_793 . V_616 ) ) ;
V_120 = - V_101 ;
if ( F_231 ( V_559 , & V_793 , sizeof( V_793 ) ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_796 : {
struct V_752 V_753 ;
V_120 = - V_101 ;
if ( F_230 ( & V_753 , V_559 , sizeof( V_753 ) ) )
goto V_113;
V_120 = F_318 ( V_138 , & V_753 ) ;
break;
}
default:
V_120 = F_329 ( V_138 , V_557 , V_558 ) ;
}
V_113:
return V_120 ;
}
static void F_330 ( void )
{
T_1 V_797 [ 2 ] ;
unsigned V_3 , V_798 ;
for ( V_3 = V_798 = 0 ; V_3 < F_52 ( V_567 ) ; V_3 ++ ) {
if ( F_331 ( V_567 [ V_3 ] , & V_797 [ 0 ] , & V_797 [ 1 ] ) < 0 )
continue;
switch ( V_567 [ V_3 ] ) {
case V_799 :
if ( ! V_73 -> V_800 () )
continue;
break;
default:
break;
}
if ( V_798 < V_3 )
V_567 [ V_798 ] = V_567 [ V_3 ] ;
V_798 ++ ;
}
V_564 = V_798 ;
for ( V_3 = V_798 = 0 ; V_3 < F_52 ( V_568 ) ; V_3 ++ ) {
switch ( V_568 [ V_3 ] ) {
case V_426 :
if ( ! V_73 -> V_537 () )
continue;
break;
default:
break;
}
if ( V_798 < V_3 )
V_568 [ V_798 ] = V_568 [ V_3 ] ;
V_798 ++ ;
}
V_565 = V_798 ;
}
static int F_332 ( struct V_1 * V_2 , T_6 V_611 , int V_95 ,
const void * V_267 )
{
int V_801 = 0 ;
int V_490 ;
do {
V_490 = F_333 ( V_95 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_590 &&
! F_334 ( V_2 , & V_2 -> V_5 . V_590 -> V_802 , V_611 , V_490 , V_267 ) )
&& F_335 ( V_2 , V_803 , V_611 , V_490 , V_267 ) )
break;
V_801 += V_490 ;
V_611 += V_490 ;
V_95 -= V_490 ;
V_267 += V_490 ;
} while ( V_95 );
return V_801 ;
}
static int F_336 ( struct V_1 * V_2 , T_6 V_611 , int V_95 , void * V_267 )
{
int V_801 = 0 ;
int V_490 ;
do {
V_490 = F_333 ( V_95 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_590 &&
! F_337 ( V_2 , & V_2 -> V_5 . V_590 -> V_802 ,
V_611 , V_490 , V_267 ) )
&& F_338 ( V_2 , V_803 , V_611 , V_490 , V_267 ) )
break;
F_339 ( V_804 , V_490 , V_611 , * ( T_2 * ) V_267 ) ;
V_801 += V_490 ;
V_611 += V_490 ;
V_95 -= V_490 ;
V_267 += V_490 ;
} while ( V_95 );
return V_801 ;
}
static void F_340 ( struct V_1 * V_2 ,
struct V_805 * V_806 , int V_807 )
{
V_73 -> V_808 ( V_2 , V_806 , V_807 ) ;
}
void F_341 ( struct V_1 * V_2 ,
struct V_805 * V_806 , int V_807 )
{
V_73 -> V_809 ( V_2 , V_806 , V_807 ) ;
}
T_6 F_342 ( struct V_1 * V_2 , T_6 V_391 , T_1 V_96 ,
struct V_75 * V_68 )
{
T_6 V_810 ;
F_13 ( ! F_39 ( V_2 ) ) ;
V_96 |= V_111 ;
V_810 = V_2 -> V_5 . V_84 . V_811 ( V_2 , V_391 , V_96 , V_68 ) ;
return V_810 ;
}
T_6 F_343 ( struct V_1 * V_2 , T_16 V_812 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
return V_2 -> V_5 . V_103 -> V_811 ( V_2 , V_812 , V_96 , V_68 ) ;
}
T_6 F_344 ( struct V_1 * V_2 , T_16 V_812 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
V_96 |= V_813 ;
return V_2 -> V_5 . V_103 -> V_811 ( V_2 , V_812 , V_96 , V_68 ) ;
}
T_6 F_345 ( struct V_1 * V_2 , T_16 V_812 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
V_96 |= V_112 ;
return V_2 -> V_5 . V_103 -> V_811 ( V_2 , V_812 , V_96 , V_68 ) ;
}
T_6 F_346 ( struct V_1 * V_2 , T_16 V_812 ,
struct V_75 * V_68 )
{
return V_2 -> V_5 . V_103 -> V_811 ( V_2 , V_812 , 0 , V_68 ) ;
}
static int F_347 ( T_16 V_611 , void * V_194 , unsigned int V_814 ,
struct V_1 * V_2 , T_1 V_96 ,
struct V_75 * V_68 )
{
void * V_38 = V_194 ;
int V_120 = V_815 ;
while ( V_814 ) {
T_6 V_391 = V_2 -> V_5 . V_103 -> V_811 ( V_2 , V_611 , V_96 ,
V_68 ) ;
unsigned V_94 = V_611 & ( V_107 - 1 ) ;
unsigned V_816 = F_333 ( V_814 , ( unsigned ) V_107 - V_94 ) ;
int V_108 ;
if ( V_391 == V_100 )
return V_817 ;
V_108 = F_49 ( V_2 , V_391 >> V_106 , V_38 ,
V_94 , V_816 ) ;
if ( V_108 < 0 ) {
V_120 = V_818 ;
goto V_113;
}
V_814 -= V_816 ;
V_38 += V_816 ;
V_611 += V_816 ;
}
V_113:
return V_120 ;
}
static int F_348 ( struct V_819 * V_820 ,
T_16 V_611 , void * V_194 , unsigned int V_814 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_349 ( V_820 ) ;
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
unsigned V_94 ;
int V_108 ;
T_6 V_391 = V_2 -> V_5 . V_103 -> V_811 ( V_2 , V_611 , V_96 | V_813 ,
V_68 ) ;
if ( F_166 ( V_391 == V_100 ) )
return V_817 ;
V_94 = V_611 & ( V_107 - 1 ) ;
if ( F_28 ( V_94 + V_814 > V_107 ) )
V_814 = ( unsigned ) V_107 - V_94 ;
V_108 = F_49 ( V_2 , V_391 >> V_106 , V_194 ,
V_94 , V_814 ) ;
if ( F_166 ( V_108 < 0 ) )
return V_818 ;
return V_815 ;
}
int F_350 ( struct V_819 * V_820 ,
T_16 V_611 , void * V_194 , unsigned int V_814 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_349 ( V_820 ) ;
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
return F_347 ( V_611 , V_194 , V_814 , V_2 , V_96 ,
V_68 ) ;
}
static int F_351 ( struct V_819 * V_820 ,
T_16 V_611 , void * V_194 , unsigned int V_814 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_349 ( V_820 ) ;
return F_347 ( V_611 , V_194 , V_814 , V_2 , 0 , V_68 ) ;
}
static int F_352 ( struct V_819 * V_820 ,
unsigned long V_611 , void * V_194 , unsigned int V_814 )
{
struct V_1 * V_2 = F_349 ( V_820 ) ;
int V_120 = F_353 ( V_2 , V_611 , V_194 , V_814 ) ;
return V_120 < 0 ? V_818 : V_815 ;
}
int F_354 ( struct V_819 * V_820 ,
T_16 V_611 , void * V_194 ,
unsigned int V_814 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_349 ( V_820 ) ;
void * V_38 = V_194 ;
int V_120 = V_815 ;
while ( V_814 ) {
T_6 V_391 = V_2 -> V_5 . V_103 -> V_811 ( V_2 , V_611 ,
V_112 ,
V_68 ) ;
unsigned V_94 = V_611 & ( V_107 - 1 ) ;
unsigned V_821 = F_333 ( V_814 , ( unsigned ) V_107 - V_94 ) ;
int V_108 ;
if ( V_391 == V_100 )
return V_817 ;
V_108 = F_198 ( V_2 , V_391 , V_38 , V_821 ) ;
if ( V_108 < 0 ) {
V_120 = V_818 ;
goto V_113;
}
V_814 -= V_821 ;
V_38 += V_821 ;
V_611 += V_821 ;
}
V_113:
return V_120 ;
}
static int F_355 ( struct V_1 * V_2 , unsigned long V_812 ,
T_6 * V_391 , struct V_75 * V_68 ,
bool V_822 )
{
T_1 V_96 = ( ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 )
| ( V_822 ? V_112 : 0 ) ;
if ( F_356 ( V_2 , V_812 )
&& ! F_357 ( V_2 , V_2 -> V_5 . V_103 ,
V_2 -> V_5 . V_96 , V_96 ) ) {
* V_391 = V_2 -> V_5 . V_823 << V_106 |
( V_812 & ( V_107 - 1 ) ) ;
F_358 ( V_812 , * V_391 , V_822 , false ) ;
return 1 ;
}
* V_391 = V_2 -> V_5 . V_103 -> V_811 ( V_2 , V_812 , V_96 , V_68 ) ;
if ( * V_391 == V_100 )
return - 1 ;
if ( ( * V_391 & V_385 ) == V_824 )
return 1 ;
if ( F_359 ( V_2 , * V_391 ) ) {
F_358 ( V_812 , * V_391 , V_822 , true ) ;
return 1 ;
}
return 0 ;
}
int F_360 ( struct V_1 * V_2 , T_6 V_391 ,
const void * V_194 , int V_814 )
{
int V_108 ;
V_108 = F_198 ( V_2 , V_391 , V_194 , V_814 ) ;
if ( V_108 < 0 )
return 0 ;
F_361 ( V_2 , V_391 , V_194 , V_814 ) ;
return 1 ;
}
static int F_362 ( struct V_1 * V_2 , void * V_194 , int V_814 )
{
if ( V_2 -> V_825 ) {
F_339 ( V_804 , V_814 ,
V_2 -> V_826 [ 0 ] . V_391 , * ( T_2 * ) V_194 ) ;
V_2 -> V_825 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_363 ( struct V_1 * V_2 , T_6 V_391 ,
void * V_194 , int V_814 )
{
return ! F_353 ( V_2 , V_391 , V_194 , V_814 ) ;
}
static int F_364 ( struct V_1 * V_2 , T_6 V_391 ,
void * V_194 , int V_814 )
{
return F_360 ( V_2 , V_391 , V_194 , V_814 ) ;
}
static int F_365 ( struct V_1 * V_2 , T_6 V_391 , int V_814 , void * V_194 )
{
F_339 ( V_827 , V_814 , V_391 , * ( T_2 * ) V_194 ) ;
return F_332 ( V_2 , V_391 , V_814 , V_194 ) ;
}
static int F_366 ( struct V_1 * V_2 , T_6 V_391 ,
void * V_194 , int V_814 )
{
F_339 ( V_828 , V_814 , V_391 , 0 ) ;
return V_818 ;
}
static int F_367 ( struct V_1 * V_2 , T_6 V_391 ,
void * V_194 , int V_814 )
{
struct V_829 * V_830 = & V_2 -> V_826 [ 0 ] ;
memcpy ( V_2 -> V_831 -> V_832 . V_38 , V_830 -> V_38 , F_333 ( 8u , V_830 -> V_95 ) ) ;
return V_815 ;
}
static int F_368 ( unsigned long V_611 , void * V_194 ,
unsigned int V_814 ,
struct V_75 * V_68 ,
struct V_1 * V_2 ,
const struct V_833 * V_834 )
{
T_6 V_391 ;
int V_801 , V_108 ;
bool V_822 = V_834 -> V_822 ;
struct V_829 * V_830 ;
V_108 = F_355 ( V_2 , V_611 , & V_391 , V_68 , V_822 ) ;
if ( V_108 < 0 )
return V_817 ;
if ( V_108 )
goto V_832;
if ( V_834 -> V_835 ( V_2 , V_391 , V_194 , V_814 ) )
return V_815 ;
V_832:
V_801 = V_834 -> V_836 ( V_2 , V_391 , V_814 , V_194 ) ;
if ( V_801 == V_814 )
return V_815 ;
V_391 += V_801 ;
V_814 -= V_801 ;
V_194 += V_801 ;
F_28 ( V_2 -> V_837 >= V_838 ) ;
V_830 = & V_2 -> V_826 [ V_2 -> V_837 ++ ] ;
V_830 -> V_391 = V_391 ;
V_830 -> V_38 = V_194 ;
V_830 -> V_95 = V_814 ;
return V_815 ;
}
static int F_369 ( struct V_819 * V_820 ,
unsigned long V_611 ,
void * V_194 , unsigned int V_814 ,
struct V_75 * V_68 ,
const struct V_833 * V_834 )
{
struct V_1 * V_2 = F_349 ( V_820 ) ;
T_6 V_391 ;
int V_839 ;
if ( V_834 -> V_840 &&
V_834 -> V_840 ( V_2 , V_194 , V_814 ) )
return V_815 ;
V_2 -> V_837 = 0 ;
if ( ( ( V_611 + V_814 - 1 ) ^ V_611 ) & V_385 ) {
int V_841 ;
V_841 = - V_611 & ~ V_385 ;
V_839 = F_368 ( V_611 , V_194 , V_841 , V_68 ,
V_2 , V_834 ) ;
if ( V_839 != V_815 )
return V_839 ;
V_611 += V_841 ;
if ( V_820 -> V_332 != V_842 )
V_611 = ( T_1 ) V_611 ;
V_194 += V_841 ;
V_814 -= V_841 ;
}
V_839 = F_368 ( V_611 , V_194 , V_814 , V_68 ,
V_2 , V_834 ) ;
if ( V_839 != V_815 )
return V_839 ;
if ( ! V_2 -> V_837 )
return V_839 ;
V_391 = V_2 -> V_826 [ 0 ] . V_391 ;
V_2 -> V_843 = 1 ;
V_2 -> V_844 = 0 ;
V_2 -> V_831 -> V_832 . V_95 = F_333 ( 8u , V_2 -> V_826 [ 0 ] . V_95 ) ;
V_2 -> V_831 -> V_832 . V_845 = V_2 -> V_846 = V_834 -> V_822 ;
V_2 -> V_831 -> V_847 = V_848 ;
V_2 -> V_831 -> V_832 . V_849 = V_391 ;
return V_834 -> V_850 ( V_2 , V_391 , V_194 , V_814 ) ;
}
static int F_370 ( struct V_819 * V_820 ,
unsigned long V_611 ,
void * V_194 ,
unsigned int V_814 ,
struct V_75 * V_68 )
{
return F_369 ( V_820 , V_611 , V_194 , V_814 ,
V_68 , & V_851 ) ;
}
static int F_371 ( struct V_819 * V_820 ,
unsigned long V_611 ,
const void * V_194 ,
unsigned int V_814 ,
struct V_75 * V_68 )
{
return F_369 ( V_820 , V_611 , ( void * ) V_194 , V_814 ,
V_68 , & V_852 ) ;
}
static int F_372 ( struct V_819 * V_820 ,
unsigned long V_611 ,
const void * V_853 ,
const void * V_854 ,
unsigned int V_814 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_349 ( V_820 ) ;
T_6 V_391 ;
struct V_387 * V_387 ;
char * V_855 ;
bool V_856 ;
if ( V_814 > 8 || ( V_814 & ( V_814 - 1 ) ) )
goto V_857;
V_391 = F_345 ( V_2 , V_611 , NULL ) ;
if ( V_391 == V_100 ||
( V_391 & V_385 ) == V_824 )
goto V_857;
if ( ( ( V_391 + V_814 - 1 ) & V_385 ) != ( V_391 & V_385 ) )
goto V_857;
V_387 = F_373 ( V_2 , V_391 >> V_106 ) ;
if ( F_374 ( V_387 ) )
goto V_857;
V_855 = F_375 ( V_387 ) ;
V_855 += F_376 ( V_391 ) ;
switch ( V_814 ) {
case 1 :
V_856 = F_377 ( T_14 , V_855 , V_853 , V_854 ) ;
break;
case 2 :
V_856 = F_377 ( V_858 , V_855 , V_853 , V_854 ) ;
break;
case 4 :
V_856 = F_377 ( T_1 , V_855 , V_853 , V_854 ) ;
break;
case 8 :
V_856 = F_378 ( V_855 , V_853 , V_854 ) ;
break;
default:
F_25 () ;
}
F_379 ( V_855 ) ;
F_380 ( V_387 ) ;
if ( ! V_856 )
return V_859 ;
F_381 ( V_2 , V_391 >> V_106 ) ;
F_361 ( V_2 , V_391 , V_854 , V_814 ) ;
return V_815 ;
V_857:
F_382 ( V_860 L_20 ) ;
return F_371 ( V_820 , V_611 , V_854 , V_814 , V_68 ) ;
}
static int F_383 ( struct V_1 * V_2 , void * V_861 )
{
int V_120 ;
if ( V_2 -> V_5 . V_862 . V_863 )
V_120 = F_338 ( V_2 , V_864 , V_2 -> V_5 . V_862 . V_865 ,
V_2 -> V_5 . V_862 . V_491 , V_861 ) ;
else
V_120 = F_335 ( V_2 , V_864 ,
V_2 -> V_5 . V_862 . V_865 , V_2 -> V_5 . V_862 . V_491 ,
V_861 ) ;
return V_120 ;
}
static int F_384 ( struct V_1 * V_2 , int V_491 ,
unsigned short V_865 , void * V_194 ,
unsigned int V_735 , bool V_863 )
{
V_2 -> V_5 . V_862 . V_865 = V_865 ;
V_2 -> V_5 . V_862 . V_863 = V_863 ;
V_2 -> V_5 . V_862 . V_735 = V_735 ;
V_2 -> V_5 . V_862 . V_491 = V_491 ;
if ( ! F_383 ( V_2 , V_2 -> V_5 . V_866 ) ) {
V_2 -> V_5 . V_862 . V_735 = 0 ;
return 1 ;
}
V_2 -> V_831 -> V_847 = V_867 ;
V_2 -> V_831 -> V_868 . V_869 = V_863 ? V_870 : V_871 ;
V_2 -> V_831 -> V_868 . V_491 = V_491 ;
V_2 -> V_831 -> V_868 . V_872 = V_873 * V_107 ;
V_2 -> V_831 -> V_868 . V_735 = V_735 ;
V_2 -> V_831 -> V_868 . V_865 = V_865 ;
return 0 ;
}
static int F_385 ( struct V_819 * V_820 ,
int V_491 , unsigned short V_865 , void * V_194 ,
unsigned int V_735 )
{
struct V_1 * V_2 = F_349 ( V_820 ) ;
int V_108 ;
if ( V_2 -> V_5 . V_862 . V_735 )
goto V_874;
V_108 = F_384 ( V_2 , V_491 , V_865 , V_194 , V_735 , true ) ;
if ( V_108 ) {
V_874:
memcpy ( V_194 , V_2 -> V_5 . V_866 , V_491 * V_735 ) ;
F_386 ( V_875 , V_865 , V_491 , V_735 , V_2 -> V_5 . V_866 ) ;
V_2 -> V_5 . V_862 . V_735 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_387 ( struct V_819 * V_820 ,
int V_491 , unsigned short V_865 ,
const void * V_194 , unsigned int V_735 )
{
struct V_1 * V_2 = F_349 ( V_820 ) ;
memcpy ( V_2 -> V_5 . V_866 , V_194 , V_491 * V_735 ) ;
F_386 ( V_876 , V_865 , V_491 , V_735 , V_2 -> V_5 . V_866 ) ;
return F_384 ( V_2 , V_491 , V_865 , ( void * ) V_194 , V_735 , false ) ;
}
static unsigned long F_388 ( struct V_1 * V_2 , int V_807 )
{
return V_73 -> F_388 ( V_2 , V_807 ) ;
}
static void F_389 ( struct V_819 * V_820 , V_174 V_80 )
{
F_390 ( F_349 ( V_820 ) , V_80 ) ;
}
int F_391 ( struct V_1 * V_2 )
{
if ( ! F_239 ( V_2 ) )
return V_815 ;
if ( V_73 -> V_579 () ) {
int V_23 = F_392 () ;
F_241 ( V_23 , V_2 -> V_5 . V_580 ) ;
F_393 ( V_2 -> V_5 . V_580 ,
F_237 , NULL , 1 ) ;
F_394 () ;
F_395 ( V_2 -> V_5 . V_580 ) ;
} else
F_238 () ;
return V_815 ;
}
int F_396 ( struct V_1 * V_2 )
{
V_73 -> V_74 ( V_2 ) ;
return F_391 ( V_2 ) ;
}
static void F_397 ( struct V_819 * V_820 )
{
F_391 ( F_349 ( V_820 ) ) ;
}
static int F_398 ( struct V_819 * V_820 , int V_89 ,
unsigned long * V_646 )
{
return F_99 ( F_349 ( V_820 ) , V_89 , V_646 ) ;
}
static int F_399 ( struct V_819 * V_820 , int V_89 ,
unsigned long V_22 )
{
return F_97 ( F_349 ( V_820 ) , V_89 , V_22 ) ;
}
static T_2 F_400 ( T_2 V_877 , T_1 V_878 )
{
return ( V_877 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_878 ;
}
static unsigned long F_401 ( struct V_819 * V_820 , int V_879 )
{
struct V_1 * V_2 = F_349 ( V_820 ) ;
unsigned long V_22 ;
switch ( V_879 ) {
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
V_22 = F_90 ( V_2 ) ;
break;
default:
F_402 ( L_21 , V_262 , V_879 ) ;
return 0 ;
}
return V_22 ;
}
static int F_403 ( struct V_819 * V_820 , int V_879 , V_174 V_194 )
{
struct V_1 * V_2 = F_349 ( V_820 ) ;
int V_880 = 0 ;
switch ( V_879 ) {
case 0 :
V_880 = F_60 ( V_2 , F_400 ( F_61 ( V_2 ) , V_194 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_79 = V_194 ;
break;
case 3 :
V_880 = F_84 ( V_2 , V_194 ) ;
break;
case 4 :
V_880 = F_77 ( V_2 , F_400 ( F_78 ( V_2 ) , V_194 ) ) ;
break;
case 8 :
V_880 = F_87 ( V_2 , V_194 ) ;
break;
default:
F_402 ( L_21 , V_262 , V_879 ) ;
V_880 = - 1 ;
}
return V_880 ;
}
static int F_404 ( struct V_819 * V_820 )
{
return V_73 -> V_88 ( F_349 ( V_820 ) ) ;
}
static void F_405 ( struct V_819 * V_820 , struct V_881 * V_882 )
{
V_73 -> V_883 ( F_349 ( V_820 ) , V_882 ) ;
}
static void F_406 ( struct V_819 * V_820 , struct V_881 * V_882 )
{
V_73 -> V_884 ( F_349 ( V_820 ) , V_882 ) ;
}
static void F_407 ( struct V_819 * V_820 , struct V_881 * V_882 )
{
V_73 -> V_885 ( F_349 ( V_820 ) , V_882 ) ;
}
static void F_408 ( struct V_819 * V_820 , struct V_881 * V_882 )
{
V_73 -> V_886 ( F_349 ( V_820 ) , V_882 ) ;
}
static unsigned long F_409 (
struct V_819 * V_820 , int V_807 )
{
return F_388 ( F_349 ( V_820 ) , V_807 ) ;
}
static bool F_410 ( struct V_819 * V_820 , V_858 * V_887 ,
struct V_888 * V_889 , T_1 * V_890 ,
int V_807 )
{
struct V_805 V_806 ;
F_341 ( F_349 ( V_820 ) , & V_806 , V_807 ) ;
* V_887 = V_806 . V_887 ;
if ( V_806 . V_891 ) {
memset ( V_889 , 0 , sizeof( * V_889 ) ) ;
return false ;
}
if ( V_806 . V_892 )
V_806 . V_893 >>= 12 ;
F_411 ( V_889 , V_806 . V_893 ) ;
F_412 ( V_889 , ( unsigned long ) V_806 . V_228 ) ;
#ifdef F_62
if ( V_890 )
* V_890 = V_806 . V_228 >> 32 ;
#endif
V_889 -> type = V_806 . type ;
V_889 -> V_587 = V_806 . V_587 ;
V_889 -> V_894 = V_806 . V_894 ;
V_889 -> V_895 = V_806 . V_896 ;
V_889 -> V_897 = V_806 . V_897 ;
V_889 -> V_898 = V_806 . V_898 ;
V_889 -> V_899 = V_806 . V_181 ;
V_889 -> V_892 = V_806 . V_892 ;
return true ;
}
static void F_413 ( struct V_819 * V_820 , V_858 V_887 ,
struct V_888 * V_889 , T_1 V_890 ,
int V_807 )
{
struct V_1 * V_2 = F_349 ( V_820 ) ;
struct V_805 V_806 ;
V_806 . V_887 = V_887 ;
V_806 . V_228 = F_414 ( V_889 ) ;
#ifdef F_62
V_806 . V_228 |= ( ( T_2 ) V_890 ) << 32 ;
#endif
V_806 . V_893 = F_415 ( V_889 ) ;
if ( V_889 -> V_892 )
V_806 . V_893 = ( V_806 . V_893 << 12 ) | 0xfff ;
V_806 . type = V_889 -> type ;
V_806 . V_894 = V_889 -> V_894 ;
V_806 . V_181 = V_889 -> V_899 ;
V_806 . V_587 = V_889 -> V_587 ;
V_806 . V_898 = V_889 -> V_898 ;
V_806 . V_892 = V_889 -> V_892 ;
V_806 . V_897 = V_889 -> V_897 ;
V_806 . V_896 = V_889 -> V_895 ;
V_806 . V_891 = ! V_806 . V_896 ;
V_806 . V_900 = 0 ;
F_340 ( V_2 , & V_806 , V_807 ) ;
return;
}
static int F_416 ( struct V_819 * V_820 ,
T_1 V_901 , T_2 * V_464 )
{
struct V_32 V_21 ;
int V_120 ;
V_21 . V_146 = V_901 ;
V_21 . V_40 = false ;
V_120 = F_113 ( F_349 ( V_820 ) , & V_21 ) ;
if ( V_120 )
return V_120 ;
* V_464 = V_21 . V_38 ;
return 0 ;
}
static int F_417 ( struct V_819 * V_820 ,
T_1 V_901 , T_2 V_38 )
{
struct V_32 V_21 ;
V_21 . V_38 = V_38 ;
V_21 . V_146 = V_901 ;
V_21 . V_40 = false ;
return F_109 ( F_349 ( V_820 ) , & V_21 ) ;
}
static T_2 F_418 ( struct V_819 * V_820 )
{
struct V_1 * V_2 = F_349 ( V_820 ) ;
return V_2 -> V_5 . V_427 ;
}
static void F_419 ( struct V_819 * V_820 , T_2 V_427 )
{
struct V_1 * V_2 = F_349 ( V_820 ) ;
V_2 -> V_5 . V_427 = V_427 ;
}
static int F_420 ( struct V_819 * V_820 ,
T_1 V_902 )
{
return F_421 ( F_349 ( V_820 ) , V_902 ) ;
}
static int F_422 ( struct V_819 * V_820 ,
T_1 V_902 , T_2 * V_464 )
{
return F_102 ( F_349 ( V_820 ) , V_902 , V_464 ) ;
}
static void F_423 ( struct V_819 * V_820 )
{
F_349 ( V_820 ) -> V_5 . V_903 = 1 ;
}
static void F_424 ( struct V_819 * V_820 )
{
F_425 () ;
F_426 ( F_349 ( V_820 ) ) ;
F_427 () ;
}
static void F_428 ( struct V_819 * V_820 )
{
F_429 () ;
}
static int F_430 ( struct V_819 * V_820 ,
struct V_904 * V_905 ,
enum V_906 V_907 )
{
return V_73 -> V_908 ( F_349 ( V_820 ) , V_905 , V_907 ) ;
}
static void F_431 ( struct V_819 * V_820 ,
T_1 * V_909 , T_1 * V_910 , T_1 * V_199 , T_1 * V_207 )
{
V_684 ( F_349 ( V_820 ) , V_909 , V_910 , V_199 , V_207 ) ;
}
static V_174 F_432 ( struct V_819 * V_820 , unsigned V_911 )
{
return F_101 ( F_349 ( V_820 ) , V_911 ) ;
}
static void F_433 ( struct V_819 * V_820 , unsigned V_911 , V_174 V_194 )
{
F_103 ( F_349 ( V_820 ) , V_911 , V_194 ) ;
}
static void F_434 ( struct V_819 * V_820 , bool V_624 )
{
V_73 -> V_640 ( F_349 ( V_820 ) , V_624 ) ;
}
static void F_435 ( struct V_1 * V_2 , T_1 V_28 )
{
T_1 V_912 = V_73 -> V_620 ( V_2 ) ;
if ( V_912 & V_28 )
V_28 = 0 ;
if ( F_166 ( V_912 || V_28 ) ) {
V_73 -> V_639 ( V_2 , V_28 ) ;
if ( ! V_28 )
F_30 ( V_67 , V_2 ) ;
}
}
static bool F_436 ( struct V_1 * V_2 )
{
struct V_819 * V_820 = & V_2 -> V_5 . V_913 ;
if ( V_820 -> V_68 . V_41 == V_42 )
return F_38 ( V_2 , & V_820 -> V_68 ) ;
if ( V_820 -> V_68 . V_914 )
F_37 ( V_2 , V_820 -> V_68 . V_41 ,
V_820 -> V_68 . V_62 ) ;
else
F_32 ( V_2 , V_820 -> V_68 . V_41 ) ;
return false ;
}
static void F_437 ( struct V_1 * V_2 )
{
struct V_819 * V_820 = & V_2 -> V_5 . V_913 ;
int V_133 , V_134 ;
V_73 -> V_135 ( V_2 , & V_133 , & V_134 ) ;
V_820 -> V_915 = F_438 ( V_2 ) ;
V_820 -> V_916 = F_439 ( V_2 ) ;
V_820 -> V_332 = ( ! F_31 ( V_2 ) ) ? V_917 :
( V_820 -> V_915 & V_918 ) ? V_919 :
( V_134 && F_56 ( V_2 ) ) ? V_842 :
V_133 ? V_920 :
V_921 ;
F_181 ( V_922 != V_923 ) ;
F_181 ( V_641 != V_924 ) ;
F_181 ( V_632 != V_925 ) ;
V_820 -> V_926 = V_2 -> V_5 . V_631 ;
F_440 ( V_820 ) ;
V_2 -> V_5 . V_927 = false ;
}
int F_441 ( struct V_1 * V_2 , int V_592 , int V_928 )
{
struct V_819 * V_820 = & V_2 -> V_5 . V_913 ;
int V_108 ;
F_437 ( V_2 ) ;
V_820 -> V_929 = 2 ;
V_820 -> V_930 = 2 ;
V_820 -> V_931 = V_820 -> V_916 + V_928 ;
V_108 = F_442 ( V_820 , V_592 ) ;
if ( V_108 != V_815 )
return V_932 ;
V_820 -> V_916 = V_820 -> V_931 ;
F_443 ( V_2 , V_820 -> V_916 ) ;
F_444 ( V_2 , V_820 -> V_915 ) ;
if ( V_592 == V_51 )
V_2 -> V_5 . V_623 = 0 ;
else
V_2 -> V_5 . V_617 . V_69 = false ;
return V_933 ;
}
static int F_445 ( struct V_1 * V_2 )
{
int V_120 = V_933 ;
++ V_2 -> V_77 . V_934 ;
F_446 ( V_2 ) ;
if ( ! F_447 ( V_2 ) && V_73 -> V_88 ( V_2 ) == 0 ) {
V_2 -> V_831 -> V_847 = V_935 ;
V_2 -> V_831 -> V_936 . V_937 = V_938 ;
V_2 -> V_831 -> V_936 . V_939 = 0 ;
V_120 = V_932 ;
}
F_32 ( V_2 , V_91 ) ;
return V_120 ;
}
static bool F_448 ( struct V_1 * V_2 , T_16 V_79 ,
bool V_940 ,
int V_941 )
{
T_6 V_391 = V_79 ;
T_17 V_942 ;
if ( V_941 & V_943 )
return false ;
if ( ! V_2 -> V_5 . V_84 . V_944 ) {
V_391 = F_345 ( V_2 , V_79 , NULL ) ;
if ( V_391 == V_100 )
return true ;
}
V_942 = F_449 ( V_2 -> V_138 , F_48 ( V_391 ) ) ;
if ( F_450 ( V_942 ) )
return false ;
F_451 ( V_942 ) ;
if ( V_2 -> V_5 . V_84 . V_944 ) {
unsigned int V_945 ;
F_156 ( & V_2 -> V_138 -> V_946 ) ;
V_945 = V_2 -> V_138 -> V_5 . V_945 ;
F_157 ( & V_2 -> V_138 -> V_946 ) ;
if ( V_945 )
F_452 ( V_2 -> V_138 , F_48 ( V_391 ) ) ;
return true ;
}
F_452 ( V_2 -> V_138 , F_48 ( V_391 ) ) ;
return ! V_940 ;
}
static bool F_453 ( struct V_819 * V_820 ,
unsigned long V_79 , int V_941 )
{
struct V_1 * V_2 = F_349 ( V_820 ) ;
unsigned long V_947 , V_948 , V_391 = V_79 ;
V_947 = V_2 -> V_5 . V_947 ;
V_948 = V_2 -> V_5 . V_948 ;
V_2 -> V_5 . V_947 = V_2 -> V_5 . V_948 = 0 ;
if ( ! ( V_941 & V_949 ) )
return false ;
if ( F_454 ( V_820 ) )
return false ;
if ( V_820 -> V_916 == V_947 && V_948 == V_79 )
return false ;
V_2 -> V_5 . V_947 = V_820 -> V_916 ;
V_2 -> V_5 . V_948 = V_79 ;
if ( ! V_2 -> V_5 . V_84 . V_944 )
V_391 = F_345 ( V_2 , V_79 , NULL ) ;
F_452 ( V_2 -> V_138 , F_48 ( V_391 ) ) ;
return true ;
}
static void F_455 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_631 & V_641 ) ) {
F_456 ( V_2 -> V_299 , V_2 -> V_5 . V_427 , false ) ;
if ( F_166 ( V_2 -> V_5 . V_629 ) ) {
F_30 ( V_597 , V_2 ) ;
V_2 -> V_5 . V_629 = 0 ;
} else {
F_30 ( V_67 , V_2 ) ;
}
}
F_65 ( V_2 ) ;
}
static void F_457 ( struct V_1 * V_2 , unsigned V_926 )
{
unsigned V_119 = V_2 -> V_5 . V_631 ^ V_926 ;
V_2 -> V_5 . V_631 = V_926 ;
if ( V_119 & V_641 )
F_455 ( V_2 ) ;
}
static int F_458 ( unsigned long V_611 , T_1 type , T_1 V_186 ,
unsigned long * V_181 )
{
T_1 V_185 = 0 ;
int V_3 ;
T_1 V_950 , V_951 ;
V_950 = V_186 ;
V_951 = V_186 >> 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ , V_950 >>= 2 , V_951 >>= 4 )
if ( ( V_950 & 3 ) && ( V_951 & 15 ) == type && V_181 [ V_3 ] == V_611 )
V_185 |= ( 1 << V_3 ) ;
return V_185 ;
}
static void F_459 ( struct V_1 * V_2 , unsigned long V_952 , int * V_120 )
{
struct V_953 * V_953 = V_2 -> V_831 ;
if ( F_166 ( V_952 & V_954 ) ) {
if ( V_2 -> V_177 & V_955 ) {
V_953 -> V_956 . V_5 . V_185 = V_957 | V_192 |
V_193 ;
V_953 -> V_956 . V_5 . V_958 = V_2 -> V_5 . V_959 ;
V_953 -> V_956 . V_5 . V_68 = V_53 ;
V_953 -> V_847 = V_960 ;
* V_120 = V_961 ;
} else {
V_2 -> V_5 . V_913 . V_915 &= ~ V_954 ;
V_2 -> V_5 . V_185 &= ~ 15 ;
V_2 -> V_5 . V_185 |= V_957 | V_193 ;
F_32 ( V_2 , V_53 ) ;
}
}
}
static bool F_460 ( struct V_1 * V_2 , int * V_120 )
{
if ( F_166 ( V_2 -> V_177 & V_178 ) &&
( V_2 -> V_5 . V_187 & V_190 ) ) {
struct V_953 * V_953 = V_2 -> V_831 ;
unsigned long V_916 = F_461 ( V_2 ) ;
T_1 V_185 = F_458 ( V_916 , 0 ,
V_2 -> V_5 . V_187 ,
V_2 -> V_5 . V_180 ) ;
if ( V_185 != 0 ) {
V_953 -> V_956 . V_5 . V_185 = V_185 | V_192 | V_193 ;
V_953 -> V_956 . V_5 . V_958 = V_916 ;
V_953 -> V_956 . V_5 . V_68 = V_53 ;
V_953 -> V_847 = V_960 ;
* V_120 = V_961 ;
return true ;
}
}
if ( F_166 ( V_2 -> V_5 . V_186 & V_190 ) &&
! ( F_438 ( V_2 ) & V_962 ) ) {
unsigned long V_916 = F_461 ( V_2 ) ;
T_1 V_185 = F_458 ( V_916 , 0 ,
V_2 -> V_5 . V_186 ,
V_2 -> V_5 . V_181 ) ;
if ( V_185 != 0 ) {
V_2 -> V_5 . V_185 &= ~ 15 ;
V_2 -> V_5 . V_185 |= V_185 | V_193 ;
F_32 ( V_2 , V_53 ) ;
* V_120 = V_933 ;
return true ;
}
}
return false ;
}
int F_462 ( struct V_1 * V_2 ,
unsigned long V_79 ,
int V_941 ,
void * V_963 ,
int V_964 )
{
int V_120 ;
struct V_819 * V_820 = & V_2 -> V_5 . V_913 ;
bool V_489 = true ;
bool V_965 = V_2 -> V_5 . V_940 ;
V_2 -> V_5 . V_940 = false ;
F_463 ( V_2 ) ;
if ( ! ( V_941 & V_966 ) ) {
F_437 ( V_2 ) ;
if ( F_460 ( V_2 , & V_120 ) )
return V_120 ;
V_820 -> V_967 = 0 ;
V_820 -> V_968 = false ;
V_820 -> V_68 . V_41 = - 1 ;
V_820 -> V_969 = false ;
V_820 -> V_970 = V_941 & V_971 ;
V_120 = F_464 ( V_820 , V_963 , V_964 ) ;
F_465 ( V_2 ) ;
++ V_2 -> V_77 . V_972 ;
if ( V_120 != V_973 ) {
if ( V_941 & V_971 )
return V_932 ;
if ( F_448 ( V_2 , V_79 , V_965 ,
V_941 ) )
return V_933 ;
if ( V_941 & V_974 )
return V_932 ;
return F_445 ( V_2 ) ;
}
}
if ( V_941 & V_974 ) {
F_443 ( V_2 , V_820 -> V_931 ) ;
if ( V_820 -> V_915 & V_962 )
F_444 ( V_2 , V_820 -> V_915 & ~ V_962 ) ;
return V_933 ;
}
if ( F_453 ( V_820 , V_79 , V_941 ) )
return V_933 ;
if ( V_2 -> V_5 . V_927 ) {
V_2 -> V_5 . V_927 = false ;
F_466 ( V_820 ) ;
}
V_975:
V_120 = F_467 ( V_820 ) ;
if ( V_120 == V_976 )
return V_933 ;
if ( V_120 == V_977 ) {
if ( F_448 ( V_2 , V_79 , V_965 ,
V_941 ) )
return V_933 ;
return F_445 ( V_2 ) ;
}
if ( V_820 -> V_968 ) {
V_120 = V_933 ;
if ( F_436 ( V_2 ) )
return V_120 ;
} else if ( V_2 -> V_5 . V_862 . V_735 ) {
if ( ! V_2 -> V_5 . V_862 . V_863 ) {
V_2 -> V_5 . V_862 . V_735 = 0 ;
} else {
V_489 = false ;
V_2 -> V_5 . V_978 = V_979 ;
}
V_120 = V_961 ;
} else if ( V_2 -> V_843 ) {
if ( ! V_2 -> V_846 )
V_489 = false ;
V_120 = V_961 ;
V_2 -> V_5 . V_978 = V_980 ;
} else if ( V_120 == V_981 )
goto V_975;
else
V_120 = V_933 ;
if ( V_489 ) {
unsigned long V_952 = V_73 -> V_982 ( V_2 ) ;
F_435 ( V_2 , V_820 -> V_967 ) ;
V_2 -> V_5 . V_983 = false ;
if ( V_2 -> V_5 . V_631 != V_820 -> V_926 )
F_457 ( V_2 , V_820 -> V_926 ) ;
F_443 ( V_2 , V_820 -> V_916 ) ;
if ( V_120 == V_933 )
F_459 ( V_2 , V_952 , & V_120 ) ;
if ( ! V_820 -> V_968 ||
F_27 ( V_820 -> V_68 . V_41 ) == V_56 )
F_468 ( V_2 , V_820 -> V_915 ) ;
if ( F_166 ( ( V_820 -> V_915 & ~ V_952 ) & V_984 ) )
F_30 ( V_67 , V_2 ) ;
} else
V_2 -> V_5 . V_983 = true ;
return V_120 ;
}
int F_469 ( struct V_1 * V_2 , int V_491 , unsigned short V_865 )
{
unsigned long V_194 = F_101 ( V_2 , V_201 ) ;
int V_108 = F_387 ( & V_2 -> V_5 . V_913 ,
V_491 , V_865 , & V_194 , 1 ) ;
V_2 -> V_5 . V_862 . V_735 = 0 ;
return V_108 ;
}
static void F_470 ( void * V_905 )
{
F_471 ( V_348 , 0 ) ;
}
static void F_472 ( void * V_38 )
{
struct V_985 * V_986 = V_38 ;
unsigned long V_265 = 0 ;
if ( V_38 )
V_265 = V_986 -> V_854 ;
else if ( ! F_473 ( V_987 ) )
V_265 = F_474 ( F_475 () ) ;
if ( ! V_265 )
V_265 = V_274 ;
F_471 ( V_348 , V_265 ) ;
}
static int F_476 ( struct V_988 * V_989 , unsigned long V_194 ,
void * V_38 )
{
struct V_985 * V_986 = V_38 ;
struct V_138 * V_138 ;
struct V_1 * V_2 ;
int V_3 , V_990 = 0 ;
if ( V_194 == V_991 && V_986 -> V_853 > V_986 -> V_854 )
return 0 ;
if ( V_194 == V_992 && V_986 -> V_853 < V_986 -> V_854 )
return 0 ;
F_242 ( V_986 -> V_23 , F_472 , V_986 , 1 ) ;
F_156 ( & V_993 ) ;
F_477 (kvm, &vm_list, vm_list) {
F_174 (i, vcpu, kvm) {
if ( V_2 -> V_23 != V_986 -> V_23 )
continue;
F_30 ( V_339 , V_2 ) ;
if ( V_2 -> V_23 != F_8 () )
V_990 = 1 ;
}
}
F_157 ( & V_993 ) ;
if ( V_986 -> V_853 < V_986 -> V_854 && V_990 ) {
F_242 ( V_986 -> V_23 , F_472 , V_986 , 1 ) ;
}
return 0 ;
}
static int F_478 ( struct V_988 * V_994 ,
unsigned long V_995 , void * V_996 )
{
unsigned int V_23 = ( unsigned long ) V_996 ;
switch ( V_995 ) {
case V_997 :
case V_998 :
F_242 ( V_23 , F_472 , NULL , 1 ) ;
break;
case V_999 :
F_242 ( V_23 , F_470 , NULL , 1 ) ;
break;
}
return V_1000 ;
}
static void F_479 ( void )
{
int V_23 ;
V_1001 = V_274 ;
F_480 () ;
if ( ! F_473 ( V_987 ) ) {
#ifdef F_481
struct V_1002 V_1003 ;
memset ( & V_1003 , 0 , sizeof( V_1003 ) ) ;
V_23 = F_392 () ;
F_482 ( & V_1003 , V_23 ) ;
if ( V_1003 . V_1004 . V_1005 )
V_1001 = V_1003 . V_1004 . V_1005 ;
F_394 () ;
#endif
F_483 ( & V_1006 ,
V_1007 ) ;
}
F_129 ( L_22 , V_1001 ) ;
F_484 (cpu)
F_242 ( V_23 , F_472 , NULL , 1 ) ;
F_485 ( & V_1008 ) ;
F_486 () ;
}
int F_487 ( void )
{
return F_178 ( V_1009 ) != NULL ;
}
static int F_488 ( void )
{
int V_1010 = 3 ;
if ( F_178 ( V_1009 ) )
V_1010 = V_73 -> V_88 ( F_178 ( V_1009 ) ) ;
return V_1010 != 0 ;
}
static unsigned long F_489 ( void )
{
unsigned long V_1011 = 0 ;
if ( F_178 ( V_1009 ) )
V_1011 = F_439 ( F_178 ( V_1009 ) ) ;
return V_1011 ;
}
void F_490 ( struct V_1 * V_2 )
{
F_471 ( V_1009 , V_2 ) ;
}
void F_491 ( struct V_1 * V_2 )
{
F_471 ( V_1009 , NULL ) ;
}
static void F_492 ( void )
{
T_2 V_28 ;
int V_1012 = V_1013 . V_1014 ;
V_28 = F_493 ( V_1012 , 51 ) ;
V_28 |= 0x3ull << 62 ;
V_28 |= 1ull ;
#ifdef F_62
if ( V_1012 == 52 )
V_28 &= ~ 1ull ;
#endif
F_494 ( V_28 ) ;
}
static void F_495 ( struct V_359 * V_360 )
{
struct V_138 * V_138 ;
struct V_1 * V_2 ;
int V_3 ;
F_156 ( & V_993 ) ;
F_477 (kvm, &vm_list, vm_list)
F_174 (i, vcpu, kvm)
F_30 ( V_298 , V_2 ) ;
F_170 ( & V_338 , 0 ) ;
F_157 ( & V_993 ) ;
}
static int F_496 ( struct V_988 * V_989 , unsigned long V_1015 ,
void * V_1016 )
{
struct V_224 * V_293 = & V_224 ;
struct V_222 * V_223 = V_1016 ;
F_115 ( V_223 ) ;
if ( V_293 -> clock . V_231 != V_297 &&
F_141 ( & V_338 ) != 0 )
F_497 ( V_1017 , & V_1018 ) ;
return 0 ;
}
int F_498 ( void * V_1019 )
{
int V_120 ;
struct V_73 * V_834 = V_1019 ;
if ( V_73 ) {
F_10 ( V_26 L_23 ) ;
V_120 = - V_596 ;
goto V_113;
}
if ( ! V_834 -> V_1020 () ) {
F_10 ( V_26 L_24 ) ;
V_120 = - V_1021 ;
goto V_113;
}
if ( V_834 -> V_1022 () ) {
F_10 ( V_26 L_25 ) ;
V_120 = - V_1021 ;
goto V_113;
}
V_120 = - V_389 ;
V_25 = F_499 ( struct V_11 ) ;
if ( ! V_25 ) {
F_10 ( V_26 L_26 ) ;
goto V_113;
}
V_120 = F_500 () ;
if ( V_120 )
goto V_1023;
F_492 () ;
V_73 = V_834 ;
F_501 ( V_1024 , V_1025 ,
V_1026 , V_1027 , 0 ) ;
F_479 () ;
F_502 ( & V_1028 ) ;
if ( V_553 )
V_145 = F_503 ( V_143 ) ;
F_504 () ;
#ifdef F_62
F_505 ( & V_1029 ) ;
#endif
return 0 ;
V_1023:
F_506 ( V_25 ) ;
V_113:
return V_120 ;
}
void F_507 ( void )
{
F_508 ( & V_1028 ) ;
if ( ! F_473 ( V_987 ) )
F_509 ( & V_1006 ,
V_1007 ) ;
F_510 ( & V_1008 ) ;
#ifdef F_62
F_511 ( & V_1029 ) ;
#endif
V_73 = NULL ;
F_512 () ;
F_506 ( V_25 ) ;
}
int F_513 ( struct V_1 * V_2 )
{
++ V_2 -> V_77 . V_1030 ;
if ( F_88 ( V_2 ) ) {
V_2 -> V_5 . V_1031 = V_1032 ;
return 1 ;
} else {
V_2 -> V_831 -> V_847 = V_1033 ;
return 0 ;
}
}
int F_514 ( struct V_1 * V_2 )
{
V_73 -> V_74 ( V_2 ) ;
return F_513 ( V_2 ) ;
}
static void F_515 ( struct V_138 * V_138 , unsigned long V_309 , int V_1034 )
{
struct V_1035 V_1036 ;
V_1036 . V_1037 = 0 ;
V_1036 . V_1038 = 0 ;
V_1036 . V_1039 = V_1034 ;
V_1036 . V_1040 = false ;
V_1036 . V_1041 = V_1042 ;
F_516 ( V_138 , NULL , & V_1036 , NULL ) ;
}
int F_517 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_1043 , V_1044 , V_1045 , V_1046 , V_108 ;
int V_1047 , V_120 = 1 ;
V_73 -> V_74 ( V_2 ) ;
if ( F_518 ( V_2 -> V_138 ) )
return F_519 ( V_2 ) ;
V_16 = F_101 ( V_2 , V_201 ) ;
V_1043 = F_101 ( V_2 , V_1048 ) ;
V_1044 = F_101 ( V_2 , V_200 ) ;
V_1045 = F_101 ( V_2 , V_202 ) ;
V_1046 = F_101 ( V_2 , V_1049 ) ;
F_520 ( V_16 , V_1043 , V_1044 , V_1045 , V_1046 ) ;
V_1047 = F_521 ( V_2 ) ;
if ( ! V_1047 ) {
V_16 &= 0xFFFFFFFF ;
V_1043 &= 0xFFFFFFFF ;
V_1044 &= 0xFFFFFFFF ;
V_1045 &= 0xFFFFFFFF ;
V_1046 &= 0xFFFFFFFF ;
}
if ( V_73 -> V_88 ( V_2 ) != 0 ) {
V_108 = - V_1050 ;
goto V_113;
}
switch ( V_16 ) {
case V_1051 :
V_108 = 0 ;
break;
case V_1052 :
F_515 ( V_2 -> V_138 , V_1043 , V_1044 ) ;
V_108 = 0 ;
break;
default:
V_108 = - V_1053 ;
break;
}
V_113:
if ( ! V_1047 )
V_108 = ( T_1 ) V_108 ;
F_103 ( V_2 , V_201 , V_108 ) ;
++ V_2 -> V_77 . V_1054 ;
return V_120 ;
}
static int F_522 ( struct V_819 * V_820 )
{
struct V_1 * V_2 = F_349 ( V_820 ) ;
char V_1055 [ 3 ] ;
unsigned long V_1056 = F_439 ( V_2 ) ;
V_73 -> V_1057 ( V_2 , V_1055 ) ;
return F_371 ( V_820 , V_1056 , V_1055 , 3 , NULL ) ;
}
static int F_523 ( struct V_1 * V_2 )
{
return V_2 -> V_831 -> V_1058 &&
F_162 ( ! F_260 ( V_2 -> V_138 ) ) ;
}
static void F_524 ( struct V_1 * V_2 )
{
struct V_953 * V_953 = V_2 -> V_831 ;
V_953 -> V_1059 = ( F_438 ( V_2 ) & V_984 ) != 0 ;
V_953 -> V_309 = F_269 ( V_2 ) ? V_1060 : 0 ;
V_953 -> V_175 = F_90 ( V_2 ) ;
V_953 -> V_31 = F_19 ( V_2 ) ;
V_953 -> V_1061 =
F_260 ( V_2 -> V_138 ) ||
F_253 ( V_2 ) ;
}
static void F_250 ( struct V_1 * V_2 )
{
int V_1062 , V_1063 ;
if ( ! V_73 -> F_250 )
return;
if ( ! V_2 -> V_5 . V_590 )
return;
if ( ! V_2 -> V_5 . V_590 -> V_693 )
V_1062 = F_525 ( V_2 ) ;
else
V_1062 = - 1 ;
if ( V_1062 != - 1 )
V_1062 >>= 4 ;
V_1063 = F_91 ( V_2 ) ;
V_73 -> F_250 ( V_2 , V_1063 , V_1062 ) ;
}
static int F_526 ( struct V_1 * V_2 , bool V_1064 )
{
int V_120 ;
if ( V_2 -> V_5 . V_68 . V_69 ) {
F_527 ( V_2 -> V_5 . V_68 . V_16 ,
V_2 -> V_5 . V_68 . V_71 ,
V_2 -> V_5 . V_68 . V_62 ) ;
if ( F_27 ( V_2 -> V_5 . V_68 . V_16 ) == V_60 )
F_468 ( V_2 , F_438 ( V_2 ) |
V_962 ) ;
if ( V_2 -> V_5 . V_68 . V_16 == V_53 &&
( V_2 -> V_5 . V_186 & V_1065 ) ) {
V_2 -> V_5 . V_186 &= ~ V_1065 ;
F_94 ( V_2 ) ;
}
V_73 -> V_1066 ( V_2 , V_2 -> V_5 . V_68 . V_16 ,
V_2 -> V_5 . V_68 . V_71 ,
V_2 -> V_5 . V_68 . V_62 ,
V_2 -> V_5 . V_68 . V_63 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_622 ) {
V_73 -> V_1067 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_617 . V_69 ) {
V_73 -> V_1068 ( V_2 ) ;
return 0 ;
}
if ( F_447 ( V_2 ) && V_73 -> V_1069 ) {
V_120 = V_73 -> V_1069 ( V_2 , V_1064 ) ;
if ( V_120 != 0 )
return V_120 ;
}
if ( V_2 -> V_5 . V_623 ) {
if ( V_73 -> V_1070 ( V_2 ) ) {
-- V_2 -> V_5 . V_623 ;
V_2 -> V_5 . V_622 = true ;
V_73 -> V_1067 ( V_2 ) ;
}
} else if ( F_528 ( V_2 ) ) {
if ( F_447 ( V_2 ) && V_73 -> V_1069 ) {
V_120 = V_73 -> V_1069 ( V_2 , V_1064 ) ;
if ( V_120 != 0 )
return V_120 ;
}
if ( V_73 -> V_1071 ( V_2 ) ) {
F_259 ( V_2 , F_529 ( V_2 ) ,
false ) ;
V_73 -> V_1068 ( V_2 ) ;
}
}
return 0 ;
}
static void F_267 ( struct V_1 * V_2 )
{
unsigned V_893 = 2 ;
if ( V_73 -> V_625 ( V_2 ) || V_2 -> V_5 . V_622 )
V_893 = 1 ;
V_2 -> V_5 . V_623 += F_530 ( & V_2 -> V_5 . V_85 , 0 ) ;
V_2 -> V_5 . V_623 = F_333 ( V_2 -> V_5 . V_623 , V_893 ) ;
F_30 ( V_67 , V_2 ) ;
}
static T_1 F_531 ( struct V_805 * V_807 )
{
T_1 V_309 = 0 ;
V_309 |= V_807 -> V_892 << 23 ;
V_309 |= V_807 -> V_181 << 22 ;
V_309 |= V_807 -> V_898 << 21 ;
V_309 |= V_807 -> V_897 << 20 ;
V_309 |= V_807 -> V_896 << 15 ;
V_309 |= V_807 -> V_894 << 13 ;
V_309 |= V_807 -> V_587 << 12 ;
V_309 |= V_807 -> type << 8 ;
return V_309 ;
}
static void F_532 ( struct V_1 * V_2 , char * V_1072 , int V_490 )
{
struct V_805 V_807 ;
int V_94 ;
F_341 ( V_2 , & V_807 , V_490 ) ;
F_533 ( T_1 , V_1072 , 0x7fa8 + V_490 * 4 , V_807 . V_887 ) ;
if ( V_490 < 3 )
V_94 = 0x7f84 + V_490 * 12 ;
else
V_94 = 0x7f2c + ( V_490 - 3 ) * 12 ;
F_533 ( T_1 , V_1072 , V_94 + 8 , V_807 . V_228 ) ;
F_533 ( T_1 , V_1072 , V_94 + 4 , V_807 . V_893 ) ;
F_533 ( T_1 , V_1072 , V_94 , F_531 ( & V_807 ) ) ;
}
static void F_534 ( struct V_1 * V_2 , char * V_1072 , int V_490 )
{
struct V_805 V_807 ;
int V_94 ;
V_858 V_309 ;
F_341 ( V_2 , & V_807 , V_490 ) ;
V_94 = 0x7e00 + V_490 * 16 ;
V_309 = F_531 ( & V_807 ) >> 8 ;
F_533 ( V_858 , V_1072 , V_94 , V_807 . V_887 ) ;
F_533 ( V_858 , V_1072 , V_94 + 2 , V_309 ) ;
F_533 ( T_1 , V_1072 , V_94 + 4 , V_807 . V_893 ) ;
F_533 ( T_2 , V_1072 , V_94 + 8 , V_807 . V_228 ) ;
}
static void F_535 ( struct V_1 * V_2 , char * V_1072 )
{
struct V_881 V_882 ;
struct V_805 V_807 ;
unsigned long V_194 ;
int V_3 ;
F_533 ( T_1 , V_1072 , 0x7ffc , F_61 ( V_2 ) ) ;
F_533 ( T_1 , V_1072 , 0x7ff8 , F_59 ( V_2 ) ) ;
F_533 ( T_1 , V_1072 , 0x7ff4 , F_438 ( V_2 ) ) ;
F_533 ( T_1 , V_1072 , 0x7ff0 , F_439 ( V_2 ) ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
F_533 ( T_1 , V_1072 , 0x7fd0 + V_3 * 4 , F_101 ( V_2 , V_3 ) ) ;
F_99 ( V_2 , 6 , & V_194 ) ;
F_533 ( T_1 , V_1072 , 0x7fcc , ( T_1 ) V_194 ) ;
F_99 ( V_2 , 7 , & V_194 ) ;
F_533 ( T_1 , V_1072 , 0x7fc8 , ( T_1 ) V_194 ) ;
F_341 ( V_2 , & V_807 , V_1073 ) ;
F_533 ( T_1 , V_1072 , 0x7fc4 , V_807 . V_887 ) ;
F_533 ( T_1 , V_1072 , 0x7f64 , V_807 . V_228 ) ;
F_533 ( T_1 , V_1072 , 0x7f60 , V_807 . V_893 ) ;
F_533 ( T_1 , V_1072 , 0x7f5c , F_531 ( & V_807 ) ) ;
F_341 ( V_2 , & V_807 , V_1074 ) ;
F_533 ( T_1 , V_1072 , 0x7fc0 , V_807 . V_887 ) ;
F_533 ( T_1 , V_1072 , 0x7f80 , V_807 . V_228 ) ;
F_533 ( T_1 , V_1072 , 0x7f7c , V_807 . V_893 ) ;
F_533 ( T_1 , V_1072 , 0x7f78 , F_531 ( & V_807 ) ) ;
V_73 -> V_883 ( V_2 , & V_882 ) ;
F_533 ( T_1 , V_1072 , 0x7f74 , V_882 . V_80 ) ;
F_533 ( T_1 , V_1072 , 0x7f70 , V_882 . V_491 ) ;
V_73 -> V_884 ( V_2 , & V_882 ) ;
F_533 ( T_1 , V_1072 , 0x7f58 , V_882 . V_80 ) ;
F_533 ( T_1 , V_1072 , 0x7f54 , V_882 . V_491 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_532 ( V_2 , V_1072 , V_3 ) ;
F_533 ( T_1 , V_1072 , 0x7f14 , F_78 ( V_2 ) ) ;
F_533 ( T_1 , V_1072 , 0x7efc , 0x00020000 ) ;
F_533 ( T_1 , V_1072 , 0x7ef8 , V_2 -> V_5 . V_427 ) ;
}
static void F_536 ( struct V_1 * V_2 , char * V_1072 )
{
#ifdef F_62
struct V_881 V_882 ;
struct V_805 V_807 ;
unsigned long V_194 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ )
F_533 ( T_2 , V_1072 , 0x7ff8 - V_3 * 8 , F_101 ( V_2 , V_3 ) ) ;
F_533 ( T_2 , V_1072 , 0x7f78 , F_439 ( V_2 ) ) ;
F_533 ( T_1 , V_1072 , 0x7f70 , F_438 ( V_2 ) ) ;
F_99 ( V_2 , 6 , & V_194 ) ;
F_533 ( T_2 , V_1072 , 0x7f68 , V_194 ) ;
F_99 ( V_2 , 7 , & V_194 ) ;
F_533 ( T_2 , V_1072 , 0x7f60 , V_194 ) ;
F_533 ( T_2 , V_1072 , 0x7f58 , F_61 ( V_2 ) ) ;
F_533 ( T_2 , V_1072 , 0x7f50 , F_59 ( V_2 ) ) ;
F_533 ( T_2 , V_1072 , 0x7f48 , F_78 ( V_2 ) ) ;
F_533 ( T_1 , V_1072 , 0x7f00 , V_2 -> V_5 . V_427 ) ;
F_533 ( T_1 , V_1072 , 0x7efc , 0x00020064 ) ;
F_533 ( T_2 , V_1072 , 0x7ed0 , V_2 -> V_5 . V_131 ) ;
F_341 ( V_2 , & V_807 , V_1073 ) ;
F_533 ( V_858 , V_1072 , 0x7e90 , V_807 . V_887 ) ;
F_533 ( V_858 , V_1072 , 0x7e92 , F_531 ( & V_807 ) >> 8 ) ;
F_533 ( T_1 , V_1072 , 0x7e94 , V_807 . V_893 ) ;
F_533 ( T_2 , V_1072 , 0x7e98 , V_807 . V_228 ) ;
V_73 -> V_884 ( V_2 , & V_882 ) ;
F_533 ( T_1 , V_1072 , 0x7e84 , V_882 . V_491 ) ;
F_533 ( T_2 , V_1072 , 0x7e88 , V_882 . V_80 ) ;
F_341 ( V_2 , & V_807 , V_1074 ) ;
F_533 ( V_858 , V_1072 , 0x7e70 , V_807 . V_887 ) ;
F_533 ( V_858 , V_1072 , 0x7e72 , F_531 ( & V_807 ) >> 8 ) ;
F_533 ( T_1 , V_1072 , 0x7e74 , V_807 . V_893 ) ;
F_533 ( T_2 , V_1072 , 0x7e78 , V_807 . V_228 ) ;
V_73 -> V_883 ( V_2 , & V_882 ) ;
F_533 ( T_1 , V_1072 , 0x7e64 , V_882 . V_491 ) ;
F_533 ( T_2 , V_1072 , 0x7e68 , V_882 . V_80 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_534 ( V_2 , V_1072 , V_3 ) ;
#else
F_537 ( 1 ) ;
#endif
}
static void F_538 ( struct V_1 * V_2 )
{
struct V_805 V_1075 , V_1076 ;
struct V_881 V_882 ;
char V_1072 [ 512 ] ;
T_1 V_121 ;
if ( F_269 ( V_2 ) ) {
V_2 -> V_5 . V_629 = true ;
return;
}
F_456 ( V_2 -> V_299 , V_2 -> V_5 . V_427 , true ) ;
V_2 -> V_5 . V_631 |= V_641 ;
memset ( V_1072 , 0 , 512 ) ;
if ( F_539 ( V_2 ) )
F_536 ( V_2 , V_1072 ) ;
else
F_535 ( V_2 , V_1072 ) ;
F_198 ( V_2 , V_2 -> V_5 . V_427 + 0xfe00 , V_1072 , sizeof( V_1072 ) ) ;
if ( V_73 -> V_625 ( V_2 ) )
V_2 -> V_5 . V_631 |= V_632 ;
else
V_73 -> V_640 ( V_2 , true ) ;
F_444 ( V_2 , V_1077 ) ;
F_443 ( V_2 , 0x8000 ) ;
V_121 = V_2 -> V_5 . V_121 & ~ ( V_130 | V_1078 | V_1079 | V_124 ) ;
V_73 -> V_137 ( V_2 , V_121 ) ;
V_2 -> V_5 . V_121 = V_121 ;
V_73 -> V_169 ( V_2 , 0 ) ;
V_882 . V_80 = V_882 . V_491 = 0 ;
V_73 -> V_886 ( V_2 , & V_882 ) ;
F_97 ( V_2 , 7 , V_197 ) ;
V_1075 . V_887 = ( V_2 -> V_5 . V_427 >> 4 ) & 0xffff ;
V_1075 . V_228 = V_2 -> V_5 . V_427 ;
V_1076 . V_887 = 0 ;
V_1076 . V_228 = 0 ;
V_1075 . V_893 = V_1076 . V_893 = 0xffffffff ;
V_1075 . type = V_1076 . type = 0x3 ;
V_1075 . V_894 = V_1076 . V_894 = 0 ;
V_1075 . V_181 = V_1076 . V_181 = 0 ;
V_1075 . V_587 = V_1076 . V_587 = 1 ;
V_1075 . V_898 = V_1076 . V_898 = 0 ;
V_1075 . V_892 = V_1076 . V_892 = 1 ;
V_1075 . V_897 = V_1076 . V_897 = 0 ;
V_1075 . V_896 = V_1076 . V_896 = 1 ;
V_1075 . V_891 = V_1076 . V_891 = 0 ;
V_1075 . V_900 = V_1076 . V_900 = 0 ;
F_340 ( V_2 , & V_1075 , V_1080 ) ;
F_340 ( V_2 , & V_1076 , V_1081 ) ;
F_340 ( V_2 , & V_1076 , V_1082 ) ;
F_340 ( V_2 , & V_1076 , V_1083 ) ;
F_340 ( V_2 , & V_1076 , V_1084 ) ;
F_340 ( V_2 , & V_1076 , V_1085 ) ;
if ( F_539 ( V_2 ) )
V_73 -> F_107 ( V_2 , 0 ) ;
F_75 ( V_2 ) ;
F_65 ( V_2 ) ;
}
static void F_540 ( struct V_1 * V_2 )
{
if ( ! F_541 ( V_2 -> V_5 . V_590 ) )
return;
memset ( V_2 -> V_5 . V_1086 , 0 , 256 / 8 ) ;
if ( V_757 ( V_2 -> V_138 ) )
F_542 ( V_2 , V_2 -> V_5 . V_1086 ) ;
else {
V_73 -> V_588 ( V_2 ) ;
F_543 ( V_2 , V_2 -> V_5 . V_1086 ) ;
}
V_73 -> V_1087 ( V_2 ) ;
}
static void F_544 ( struct V_1 * V_2 )
{
++ V_2 -> V_77 . V_1088 ;
V_73 -> V_1088 ( V_2 ) ;
}
void F_545 ( struct V_1 * V_2 )
{
struct V_387 * V_387 = NULL ;
if ( ! F_88 ( V_2 ) )
return;
if ( ! V_73 -> V_1089 )
return;
V_387 = F_546 ( V_2 -> V_138 , V_824 >> V_106 ) ;
if ( F_374 ( V_387 ) )
return;
V_73 -> V_1089 ( V_2 , F_547 ( V_387 ) ) ;
F_548 ( V_387 ) ;
}
void F_549 ( struct V_138 * V_138 ,
unsigned long V_80 )
{
if ( V_80 == F_550 ( V_138 , V_824 >> V_106 ) )
F_551 ( V_138 , V_1090 ) ;
}
static int F_552 ( struct V_1 * V_2 )
{
int V_120 ;
bool V_1064 =
F_523 ( V_2 ) &&
F_251 ( V_2 ) ;
bool V_1091 = false ;
if ( V_2 -> V_341 ) {
if ( F_553 ( V_1092 , V_2 ) )
F_554 ( V_2 ) ;
if ( F_553 ( V_1093 , V_2 ) )
F_555 ( V_2 ) ;
if ( F_553 ( V_298 , V_2 ) )
F_172 ( V_2 -> V_138 ) ;
if ( F_553 ( V_434 , V_2 ) )
F_189 ( V_2 ) ;
if ( F_553 ( V_339 , V_2 ) ) {
V_120 = F_176 ( V_2 ) ;
if ( F_166 ( V_120 ) )
goto V_113;
}
if ( F_553 ( V_1094 , V_2 ) )
F_85 ( V_2 ) ;
if ( F_553 ( V_171 , V_2 ) )
F_544 ( V_2 ) ;
if ( F_553 ( V_1095 , V_2 ) ) {
V_2 -> V_831 -> V_847 = V_1096 ;
V_120 = 0 ;
goto V_113;
}
if ( F_553 ( V_72 , V_2 ) ) {
V_2 -> V_831 -> V_847 = V_1097 ;
V_120 = 0 ;
goto V_113;
}
if ( F_553 ( V_1098 , V_2 ) ) {
V_2 -> V_1099 = 0 ;
V_73 -> V_1100 ( V_2 ) ;
}
if ( F_553 ( V_1101 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1102 = true ;
V_120 = 1 ;
goto V_113;
}
if ( F_553 ( V_439 , V_2 ) )
F_205 ( V_2 ) ;
if ( F_553 ( V_597 , V_2 ) )
F_538 ( V_2 ) ;
if ( F_553 ( V_86 , V_2 ) )
F_267 ( V_2 ) ;
if ( F_553 ( V_1103 , V_2 ) )
F_556 ( V_2 ) ;
if ( F_553 ( V_1104 , V_2 ) )
F_557 ( V_2 ) ;
if ( F_553 ( V_1105 , V_2 ) ) {
F_13 ( V_2 -> V_5 . V_1106 > 255 ) ;
if ( F_58 ( V_2 -> V_5 . V_1106 ,
( void * ) V_2 -> V_5 . V_1086 ) ) {
V_2 -> V_831 -> V_847 = V_1107 ;
V_2 -> V_831 -> V_1108 . V_41 =
V_2 -> V_5 . V_1106 ;
V_120 = 0 ;
goto V_113;
}
}
if ( F_553 ( V_1109 , V_2 ) )
F_540 ( V_2 ) ;
if ( F_553 ( V_1090 , V_2 ) )
F_545 ( V_2 ) ;
if ( F_553 ( V_1110 , V_2 ) ) {
V_2 -> V_831 -> V_847 = V_1111 ;
V_2 -> V_831 -> V_1112 . type = V_1113 ;
V_120 = 0 ;
goto V_113;
}
if ( F_553 ( V_1114 , V_2 ) ) {
V_2 -> V_831 -> V_847 = V_1111 ;
V_2 -> V_831 -> V_1112 . type = V_1115 ;
V_120 = 0 ;
goto V_113;
}
}
if ( F_558 ( V_2 ) ) {
if ( V_73 -> V_1116 )
V_73 -> V_1116 ( V_2 ,
F_525 ( V_2 ) ) ;
}
if ( F_553 ( V_67 , V_2 ) || V_1064 ) {
F_559 ( V_2 ) ;
if ( V_2 -> V_5 . V_1031 == V_1117 ) {
V_120 = 1 ;
goto V_113;
}
if ( F_526 ( V_2 , V_1064 ) != 0 )
V_1091 = true ;
else if ( V_2 -> V_5 . V_623 )
V_73 -> V_1118 ( V_2 ) ;
else if ( F_528 ( V_2 ) || V_1064 )
V_73 -> V_1119 ( V_2 ) ;
if ( F_558 ( V_2 ) ) {
F_250 ( V_2 ) ;
F_560 ( V_2 ) ;
}
}
V_120 = F_561 ( V_2 ) ;
if ( F_166 ( V_120 ) ) {
goto V_1120;
}
F_425 () ;
V_73 -> V_1121 ( V_2 ) ;
if ( V_2 -> V_1099 )
F_426 ( V_2 ) ;
F_71 ( V_2 ) ;
V_2 -> V_332 = V_1122 ;
F_228 ( & V_2 -> V_138 -> V_486 , V_2 -> V_1123 ) ;
F_562 () ;
F_327 () ;
if ( V_2 -> V_332 == V_1124 || V_2 -> V_341
|| F_563 () || F_564 ( V_398 ) ) {
V_2 -> V_332 = V_1125 ;
F_184 () ;
F_328 () ;
F_429 () ;
V_2 -> V_1123 = F_227 ( & V_2 -> V_138 -> V_486 ) ;
V_120 = 1 ;
goto V_1120;
}
if ( V_1091 )
F_565 ( V_2 -> V_23 ) ;
F_566 ( V_2 -> V_299 ) ;
F_567 ( V_2 ) ;
F_568 () ;
if ( F_166 ( V_2 -> V_5 . V_182 ) ) {
F_569 ( 0 , 7 ) ;
F_569 ( V_2 -> V_5 . V_180 [ 0 ] , 0 ) ;
F_569 ( V_2 -> V_5 . V_180 [ 1 ] , 1 ) ;
F_569 ( V_2 -> V_5 . V_180 [ 2 ] , 2 ) ;
F_569 ( V_2 -> V_5 . V_180 [ 3 ] , 3 ) ;
F_569 ( V_2 -> V_5 . V_185 , 6 ) ;
V_2 -> V_5 . V_182 &= ~ V_183 ;
}
V_73 -> V_831 ( V_2 ) ;
if ( F_166 ( V_2 -> V_5 . V_182 & V_1126 ) ) {
int V_3 ;
F_28 ( V_2 -> V_177 & V_178 ) ;
V_73 -> V_1127 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_179 ; V_3 ++ )
V_2 -> V_5 . V_180 [ V_3 ] = V_2 -> V_5 . V_181 [ V_3 ] ;
}
if ( F_570 () )
F_571 () ;
V_2 -> V_5 . V_325 = F_149 ( V_2 , F_148 () ) ;
V_2 -> V_332 = V_1125 ;
F_184 () ;
V_73 -> V_1128 ( V_2 ) ;
++ V_2 -> V_77 . V_1129 ;
F_572 () ;
F_573 () ;
F_429 () ;
V_2 -> V_1123 = F_227 ( & V_2 -> V_138 -> V_486 ) ;
if ( F_166 ( V_1130 == V_1131 ) ) {
unsigned long V_1056 = F_439 ( V_2 ) ;
F_574 ( V_1131 , ( void * ) V_1056 ) ;
}
if ( F_166 ( V_2 -> V_5 . V_276 ) )
F_30 ( V_339 , V_2 ) ;
if ( V_2 -> V_5 . V_1132 )
F_575 ( V_2 ) ;
V_120 = V_73 -> V_1133 ( V_2 ) ;
return V_120 ;
V_1120:
V_73 -> V_1120 ( V_2 ) ;
if ( F_166 ( V_2 -> V_5 . V_1132 ) )
F_575 ( V_2 ) ;
V_113:
return V_120 ;
}
static inline int F_576 ( struct V_138 * V_138 , struct V_1 * V_2 )
{
if ( ! F_577 ( V_2 ) &&
( ! V_73 -> V_1134 || V_73 -> V_1134 ( V_2 ) == 0 ) ) {
F_228 ( & V_138 -> V_486 , V_2 -> V_1123 ) ;
F_578 ( V_2 ) ;
V_2 -> V_1123 = F_227 ( & V_138 -> V_486 ) ;
if ( V_73 -> V_1135 )
V_73 -> V_1135 ( V_2 ) ;
if ( ! F_553 ( V_1136 , V_2 ) )
return 1 ;
}
F_559 ( V_2 ) ;
switch( V_2 -> V_5 . V_1031 ) {
case V_1032 :
V_2 -> V_5 . V_1137 . V_1138 = false ;
V_2 -> V_5 . V_1031 =
V_1139 ;
case V_1139 :
V_2 -> V_5 . V_6 . V_1102 = false ;
break;
case V_1117 :
break;
default:
return - V_1140 ;
break;
}
return 1 ;
}
static inline bool F_579 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_1031 == V_1139 &&
! V_2 -> V_5 . V_6 . V_1102 ) ;
}
static int F_580 ( struct V_1 * V_2 )
{
int V_120 ;
struct V_138 * V_138 = V_2 -> V_138 ;
V_2 -> V_1123 = F_227 ( & V_138 -> V_486 ) ;
for (; ; ) {
if ( F_579 ( V_2 ) ) {
V_120 = F_552 ( V_2 ) ;
} else {
V_120 = F_576 ( V_138 , V_2 ) ;
}
if ( V_120 <= 0 )
break;
F_175 ( V_238 , & V_2 -> V_341 ) ;
if ( F_581 ( V_2 ) )
F_582 ( V_2 ) ;
if ( F_523 ( V_2 ) &&
F_253 ( V_2 ) ) {
V_120 = 0 ;
V_2 -> V_831 -> V_847 = V_1141 ;
++ V_2 -> V_77 . V_1142 ;
break;
}
F_583 ( V_2 ) ;
if ( F_564 ( V_398 ) ) {
V_120 = - V_1140 ;
V_2 -> V_831 -> V_847 = V_1143 ;
++ V_2 -> V_77 . V_1144 ;
break;
}
if ( F_563 () ) {
F_228 ( & V_138 -> V_486 , V_2 -> V_1123 ) ;
F_584 () ;
V_2 -> V_1123 = F_227 ( & V_138 -> V_486 ) ;
}
}
F_228 ( & V_138 -> V_486 , V_2 -> V_1123 ) ;
return V_120 ;
}
static inline int F_585 ( struct V_1 * V_2 )
{
int V_120 ;
V_2 -> V_1123 = F_227 ( & V_2 -> V_138 -> V_486 ) ;
V_120 = F_586 ( V_2 , V_966 ) ;
F_228 ( & V_2 -> V_138 -> V_486 , V_2 -> V_1123 ) ;
if ( V_120 != V_933 )
return 0 ;
return 1 ;
}
static int V_979 ( struct V_1 * V_2 )
{
F_13 ( ! V_2 -> V_5 . V_862 . V_735 ) ;
return F_585 ( V_2 ) ;
}
static int V_980 ( struct V_1 * V_2 )
{
struct V_953 * V_831 = V_2 -> V_831 ;
struct V_829 * V_830 ;
unsigned V_95 ;
F_13 ( ! V_2 -> V_843 ) ;
V_830 = & V_2 -> V_826 [ V_2 -> V_844 ] ;
V_95 = F_333 ( 8u , V_830 -> V_95 ) ;
if ( ! V_2 -> V_846 )
memcpy ( V_830 -> V_38 , V_831 -> V_832 . V_38 , V_95 ) ;
if ( V_830 -> V_95 <= 8 ) {
V_830 ++ ;
V_2 -> V_844 ++ ;
} else {
V_830 -> V_38 += V_95 ;
V_830 -> V_391 += V_95 ;
V_830 -> V_95 -= V_95 ;
}
if ( V_2 -> V_844 >= V_2 -> V_837 ) {
V_2 -> V_843 = 0 ;
if ( V_2 -> V_846 )
return 1 ;
V_2 -> V_825 = 1 ;
return F_585 ( V_2 ) ;
}
V_831 -> V_847 = V_848 ;
V_831 -> V_832 . V_849 = V_830 -> V_391 ;
if ( V_2 -> V_846 )
memcpy ( V_831 -> V_832 . V_38 , V_830 -> V_38 , F_333 ( 8u , V_830 -> V_95 ) ) ;
V_831 -> V_832 . V_95 = F_333 ( 8u , V_830 -> V_95 ) ;
V_831 -> V_832 . V_845 = V_2 -> V_846 ;
V_2 -> V_5 . V_978 = V_980 ;
return 0 ;
}
int F_587 ( struct V_1 * V_2 , struct V_953 * V_953 )
{
struct V_1145 * V_1145 = & V_398 -> V_1146 . V_1145 ;
int V_120 ;
T_18 V_1147 ;
F_588 ( V_1145 ) ;
if ( V_2 -> V_1148 )
F_589 ( V_1149 , & V_2 -> V_1150 , & V_1147 ) ;
if ( F_166 ( V_2 -> V_5 . V_1031 == V_1151 ) ) {
F_578 ( V_2 ) ;
F_559 ( V_2 ) ;
F_175 ( V_1136 , & V_2 -> V_341 ) ;
V_120 = - V_1152 ;
goto V_113;
}
if ( ! F_88 ( V_2 ) ) {
if ( F_87 ( V_2 , V_953 -> V_175 ) != 0 ) {
V_120 = - V_577 ;
goto V_113;
}
}
if ( F_166 ( V_2 -> V_5 . V_978 ) ) {
int (* F_590)( struct V_1 * ) = V_2 -> V_5 . V_978 ;
V_2 -> V_5 . V_978 = NULL ;
V_120 = F_590 ( V_2 ) ;
if ( V_120 <= 0 )
goto V_113;
} else
F_28 ( V_2 -> V_5 . V_862 . V_735 || V_2 -> V_843 ) ;
V_120 = F_580 ( V_2 ) ;
V_113:
F_524 ( V_2 ) ;
if ( V_2 -> V_1148 )
F_589 ( V_1149 , & V_1147 , NULL ) ;
return V_120 ;
}
int F_591 ( struct V_1 * V_2 , struct V_1153 * V_589 )
{
if ( V_2 -> V_5 . V_983 ) {
F_592 ( & V_2 -> V_5 . V_913 ) ;
V_2 -> V_5 . V_983 = false ;
}
V_589 -> V_1154 = F_101 ( V_2 , V_201 ) ;
V_589 -> V_1155 = F_101 ( V_2 , V_1048 ) ;
V_589 -> V_1156 = F_101 ( V_2 , V_200 ) ;
V_589 -> V_1157 = F_101 ( V_2 , V_202 ) ;
V_589 -> V_1158 = F_101 ( V_2 , V_1049 ) ;
V_589 -> V_1159 = F_101 ( V_2 , V_1160 ) ;
V_589 -> V_1161 = F_101 ( V_2 , V_1162 ) ;
V_589 -> V_1163 = F_101 ( V_2 , V_1164 ) ;
#ifdef F_62
V_589 -> V_1165 = F_101 ( V_2 , V_1166 ) ;
V_589 -> V_1167 = F_101 ( V_2 , V_1168 ) ;
V_589 -> V_1169 = F_101 ( V_2 , V_1170 ) ;
V_589 -> V_1171 = F_101 ( V_2 , V_1172 ) ;
V_589 -> V_1173 = F_101 ( V_2 , V_1174 ) ;
V_589 -> V_1175 = F_101 ( V_2 , V_1176 ) ;
V_589 -> V_1177 = F_101 ( V_2 , V_1178 ) ;
V_589 -> V_1179 = F_101 ( V_2 , V_1180 ) ;
#endif
V_589 -> V_1056 = F_439 ( V_2 ) ;
V_589 -> V_952 = F_438 ( V_2 ) ;
return 0 ;
}
int F_593 ( struct V_1 * V_2 , struct V_1153 * V_589 )
{
V_2 -> V_5 . V_927 = true ;
V_2 -> V_5 . V_983 = false ;
F_103 ( V_2 , V_201 , V_589 -> V_1154 ) ;
F_103 ( V_2 , V_1048 , V_589 -> V_1155 ) ;
F_103 ( V_2 , V_200 , V_589 -> V_1156 ) ;
F_103 ( V_2 , V_202 , V_589 -> V_1157 ) ;
F_103 ( V_2 , V_1049 , V_589 -> V_1158 ) ;
F_103 ( V_2 , V_1160 , V_589 -> V_1159 ) ;
F_103 ( V_2 , V_1162 , V_589 -> V_1161 ) ;
F_103 ( V_2 , V_1164 , V_589 -> V_1163 ) ;
#ifdef F_62
F_103 ( V_2 , V_1166 , V_589 -> V_1165 ) ;
F_103 ( V_2 , V_1168 , V_589 -> V_1167 ) ;
F_103 ( V_2 , V_1170 , V_589 -> V_1169 ) ;
F_103 ( V_2 , V_1172 , V_589 -> V_1171 ) ;
F_103 ( V_2 , V_1174 , V_589 -> V_1173 ) ;
F_103 ( V_2 , V_1176 , V_589 -> V_1175 ) ;
F_103 ( V_2 , V_1178 , V_589 -> V_1177 ) ;
F_103 ( V_2 , V_1180 , V_589 -> V_1179 ) ;
#endif
F_443 ( V_2 , V_589 -> V_1056 ) ;
F_444 ( V_2 , V_589 -> V_952 ) ;
V_2 -> V_5 . V_68 . V_69 = false ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
void F_594 ( struct V_1 * V_2 , int * V_181 , int * V_898 )
{
struct V_805 V_1075 ;
F_341 ( V_2 , & V_1075 , V_1080 ) ;
* V_181 = V_1075 . V_181 ;
* V_898 = V_1075 . V_898 ;
}
int F_595 ( struct V_1 * V_2 ,
struct V_1181 * V_1182 )
{
struct V_881 V_882 ;
F_341 ( V_2 , & V_1182 -> V_1075 , V_1080 ) ;
F_341 ( V_2 , & V_1182 -> V_1076 , V_1081 ) ;
F_341 ( V_2 , & V_1182 -> V_1183 , V_1082 ) ;
F_341 ( V_2 , & V_1182 -> V_1184 , V_1083 ) ;
F_341 ( V_2 , & V_1182 -> V_1185 , V_1084 ) ;
F_341 ( V_2 , & V_1182 -> V_1186 , V_1085 ) ;
F_341 ( V_2 , & V_1182 -> V_1187 , V_1073 ) ;
F_341 ( V_2 , & V_1182 -> V_1188 , V_1074 ) ;
V_73 -> V_884 ( V_2 , & V_882 ) ;
V_1182 -> V_1189 . V_893 = V_882 . V_491 ;
V_1182 -> V_1189 . V_228 = V_882 . V_80 ;
V_73 -> V_883 ( V_2 , & V_882 ) ;
V_1182 -> V_1190 . V_893 = V_882 . V_491 ;
V_1182 -> V_1190 . V_228 = V_882 . V_80 ;
V_1182 -> V_121 = F_61 ( V_2 ) ;
V_1182 -> V_79 = V_2 -> V_5 . V_79 ;
V_1182 -> V_104 = F_59 ( V_2 ) ;
V_1182 -> V_158 = F_78 ( V_2 ) ;
V_1182 -> V_175 = F_90 ( V_2 ) ;
V_1182 -> V_131 = V_2 -> V_5 . V_131 ;
V_1182 -> V_31 = F_19 ( V_2 ) ;
memset ( V_1182 -> V_1191 , 0 , sizeof V_1182 -> V_1191 ) ;
if ( V_2 -> V_5 . V_617 . V_69 && ! V_2 -> V_5 . V_617 . V_618 )
F_211 ( V_2 -> V_5 . V_617 . V_16 ,
( unsigned long * ) V_1182 -> V_1191 ) ;
return 0 ;
}
int F_596 ( struct V_1 * V_2 ,
struct V_1192 * V_1031 )
{
F_559 ( V_2 ) ;
if ( V_2 -> V_5 . V_1031 == V_1032 &&
V_2 -> V_5 . V_1137 . V_1138 )
V_1031 -> V_1031 = V_1139 ;
else
V_1031 -> V_1031 = V_2 -> V_5 . V_1031 ;
return 0 ;
}
int F_597 ( struct V_1 * V_2 ,
struct V_1192 * V_1031 )
{
if ( ! F_272 ( V_2 ) &&
V_1031 -> V_1031 != V_1139 )
return - V_577 ;
if ( V_1031 -> V_1031 == V_1193 ) {
V_2 -> V_5 . V_1031 = V_1117 ;
F_211 ( V_1194 , & V_2 -> V_5 . V_590 -> V_643 ) ;
} else
V_2 -> V_5 . V_1031 = V_1031 -> V_1031 ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
int F_598 ( struct V_1 * V_2 , V_858 V_1195 , int V_1196 ,
int V_1197 , bool V_71 , T_1 V_62 )
{
struct V_819 * V_820 = & V_2 -> V_5 . V_913 ;
int V_108 ;
F_437 ( V_2 ) ;
V_108 = F_599 ( V_820 , V_1195 , V_1196 , V_1197 ,
V_71 , V_62 ) ;
if ( V_108 )
return V_932 ;
F_443 ( V_2 , V_820 -> V_916 ) ;
F_444 ( V_2 , V_820 -> V_915 ) ;
F_30 ( V_67 , V_2 ) ;
return V_933 ;
}
int F_600 ( struct V_1 * V_2 ,
struct V_1181 * V_1182 )
{
struct V_32 V_1198 ;
int V_1199 = 0 ;
int V_1200 , V_1201 , V_485 ;
struct V_881 V_882 ;
if ( ! F_79 ( V_2 ) && ( V_1182 -> V_158 & V_141 ) )
return - V_577 ;
V_882 . V_491 = V_1182 -> V_1189 . V_893 ;
V_882 . V_80 = V_1182 -> V_1189 . V_228 ;
V_73 -> V_886 ( V_2 , & V_882 ) ;
V_882 . V_491 = V_1182 -> V_1190 . V_893 ;
V_882 . V_80 = V_1182 -> V_1190 . V_228 ;
V_73 -> V_885 ( V_2 , & V_882 ) ;
V_2 -> V_5 . V_79 = V_1182 -> V_79 ;
V_1199 |= F_59 ( V_2 ) != V_1182 -> V_104 ;
V_2 -> V_5 . V_104 = V_1182 -> V_104 ;
F_54 ( V_173 , ( V_174 * ) & V_2 -> V_5 . V_117 ) ;
F_87 ( V_2 , V_1182 -> V_175 ) ;
V_1199 |= V_2 -> V_5 . V_131 != V_1182 -> V_131 ;
V_73 -> F_107 ( V_2 , V_1182 -> V_131 ) ;
V_1198 . V_38 = V_1182 -> V_31 ;
V_1198 . V_40 = true ;
F_20 ( V_2 , & V_1198 ) ;
V_1199 |= F_61 ( V_2 ) != V_1182 -> V_121 ;
V_73 -> V_137 ( V_2 , V_1182 -> V_121 ) ;
V_2 -> V_5 . V_121 = V_1182 -> V_121 ;
V_1199 |= F_78 ( V_2 ) != V_1182 -> V_158 ;
V_73 -> V_169 ( V_2 , V_1182 -> V_158 ) ;
if ( V_1182 -> V_158 & V_141 )
F_75 ( V_2 ) ;
V_485 = F_227 ( & V_2 -> V_138 -> V_486 ) ;
if ( ! F_56 ( V_2 ) && F_57 ( V_2 ) ) {
F_51 ( V_2 , V_2 -> V_5 . V_103 , F_59 ( V_2 ) ) ;
V_1199 = 1 ;
}
F_228 ( & V_2 -> V_138 -> V_486 , V_485 ) ;
if ( V_1199 )
F_65 ( V_2 ) ;
V_1201 = V_593 ;
V_1200 = F_601 (
( const unsigned long * ) V_1182 -> V_1191 , V_1201 ) ;
if ( V_1200 < V_1201 ) {
F_259 ( V_2 , V_1200 , false ) ;
F_129 ( L_27 , V_1200 ) ;
}
F_340 ( V_2 , & V_1182 -> V_1075 , V_1080 ) ;
F_340 ( V_2 , & V_1182 -> V_1076 , V_1081 ) ;
F_340 ( V_2 , & V_1182 -> V_1183 , V_1082 ) ;
F_340 ( V_2 , & V_1182 -> V_1184 , V_1083 ) ;
F_340 ( V_2 , & V_1182 -> V_1185 , V_1084 ) ;
F_340 ( V_2 , & V_1182 -> V_1186 , V_1085 ) ;
F_340 ( V_2 , & V_1182 -> V_1187 , V_1073 ) ;
F_340 ( V_2 , & V_1182 -> V_1188 , V_1074 ) ;
F_250 ( V_2 ) ;
if ( F_602 ( V_2 ) && F_439 ( V_2 ) == 0xfff0 &&
V_1182 -> V_1075 . V_887 == 0xf000 && V_1182 -> V_1075 . V_228 == 0xffff0000 &&
! F_31 ( V_2 ) )
V_2 -> V_5 . V_1031 = V_1139 ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
int F_603 ( struct V_1 * V_2 ,
struct V_1202 * V_1203 )
{
unsigned long V_952 ;
int V_3 , V_120 ;
if ( V_1203 -> V_742 & ( V_1204 | V_1205 ) ) {
V_120 = - V_787 ;
if ( V_2 -> V_5 . V_68 . V_69 )
goto V_113;
if ( V_1203 -> V_742 & V_1204 )
F_32 ( V_2 , V_53 ) ;
else
F_32 ( V_2 , V_54 ) ;
}
V_952 = F_438 ( V_2 ) ;
V_2 -> V_177 = V_1203 -> V_742 ;
if ( ! ( V_2 -> V_177 & V_1206 ) )
V_2 -> V_177 = 0 ;
if ( V_2 -> V_177 & V_178 ) {
for ( V_3 = 0 ; V_3 < V_179 ; ++ V_3 )
V_2 -> V_5 . V_180 [ V_3 ] = V_1203 -> V_5 . V_1207 [ V_3 ] ;
V_2 -> V_5 . V_187 = V_1203 -> V_5 . V_1207 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_179 ; V_3 ++ )
V_2 -> V_5 . V_180 [ V_3 ] = V_2 -> V_5 . V_181 [ V_3 ] ;
}
F_94 ( V_2 ) ;
if ( V_2 -> V_177 & V_955 )
V_2 -> V_5 . V_959 = F_439 ( V_2 ) +
F_388 ( V_2 , V_1080 ) ;
F_444 ( V_2 , V_952 ) ;
V_73 -> V_1208 ( V_2 ) ;
V_120 = 0 ;
V_113:
return V_120 ;
}
int F_604 ( struct V_1 * V_2 ,
struct V_1209 * V_1187 )
{
unsigned long V_1210 = V_1187 -> V_1211 ;
T_6 V_391 ;
int V_485 ;
V_485 = F_227 ( & V_2 -> V_138 -> V_486 ) ;
V_391 = F_346 ( V_2 , V_1210 , NULL ) ;
F_228 ( & V_2 -> V_138 -> V_486 , V_485 ) ;
V_1187 -> V_1212 = V_391 ;
V_1187 -> V_654 = V_391 != V_100 ;
V_1187 -> V_1213 = 1 ;
V_1187 -> V_1214 = 0 ;
return 0 ;
}
int F_605 ( struct V_1 * V_2 , struct V_1215 * V_1145 )
{
struct V_667 * V_666 =
& V_2 -> V_5 . V_649 . V_650 . V_666 ;
memcpy ( V_1145 -> V_1216 , V_666 -> V_1217 , 128 ) ;
V_1145 -> V_1218 = V_666 -> V_1219 ;
V_1145 -> V_1220 = V_666 -> V_1221 ;
V_1145 -> V_1222 = V_666 -> V_1223 ;
V_1145 -> V_1224 = V_666 -> V_1225 ;
V_1145 -> V_1226 = V_666 -> V_1056 ;
V_1145 -> V_1227 = V_666 -> V_1228 ;
memcpy ( V_1145 -> V_1229 , V_666 -> V_1230 , sizeof V_666 -> V_1230 ) ;
return 0 ;
}
int F_606 ( struct V_1 * V_2 , struct V_1215 * V_1145 )
{
struct V_667 * V_666 =
& V_2 -> V_5 . V_649 . V_650 . V_666 ;
memcpy ( V_666 -> V_1217 , V_1145 -> V_1216 , 128 ) ;
V_666 -> V_1219 = V_1145 -> V_1218 ;
V_666 -> V_1221 = V_1145 -> V_1220 ;
V_666 -> V_1223 = V_1145 -> V_1222 ;
V_666 -> V_1225 = V_1145 -> V_1224 ;
V_666 -> V_1056 = V_1145 -> V_1226 ;
V_666 -> V_1228 = V_1145 -> V_1227 ;
memcpy ( V_666 -> V_1230 , V_1145 -> V_1229 , sizeof V_666 -> V_1230 ) ;
return 0 ;
}
static void F_607 ( struct V_1 * V_2 )
{
F_608 ( & V_2 -> V_5 . V_649 . V_650 ) ;
if ( V_660 )
V_2 -> V_5 . V_649 . V_650 . V_648 . V_652 . V_661 =
V_145 | V_662 ;
V_2 -> V_5 . V_144 = V_150 ;
V_2 -> V_5 . V_121 |= V_126 ;
}
void F_426 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1231 )
return;
F_73 ( V_2 ) ;
V_2 -> V_1231 = 1 ;
F_609 () ;
F_610 ( & V_2 -> V_5 . V_649 . V_650 ) ;
F_611 ( 1 ) ;
}
void F_246 ( struct V_1 * V_2 )
{
F_73 ( V_2 ) ;
if ( ! V_2 -> V_1231 ) {
V_2 -> V_1232 = 0 ;
return;
}
V_2 -> V_1231 = 0 ;
F_612 ( & V_2 -> V_5 . V_649 ) ;
F_613 () ;
++ V_2 -> V_77 . V_1233 ;
if ( ! V_2 -> V_5 . V_1234 ) {
if ( ++ V_2 -> V_1232 < 5 )
F_30 ( V_1098 , V_2 ) ;
}
F_611 ( 0 ) ;
}
void F_614 ( struct V_1 * V_2 )
{
F_203 ( V_2 ) ;
F_615 ( V_2 -> V_5 . V_580 ) ;
V_73 -> V_1235 ( V_2 ) ;
}
struct V_1 * F_616 ( struct V_138 * V_138 ,
unsigned int V_1236 )
{
struct V_1 * V_2 ;
if ( F_153 () && F_141 ( & V_138 -> V_295 ) != 0 )
F_382 ( V_860
L_28
L_29 ) ;
V_2 = V_73 -> V_1237 ( V_138 , V_1236 ) ;
return V_2 ;
}
int F_617 ( struct V_1 * V_2 )
{
int V_120 ;
F_618 ( V_2 ) ;
V_120 = V_581 ( V_2 ) ;
if ( V_120 )
return V_120 ;
F_619 ( V_2 , false ) ;
F_620 ( V_2 ) ;
V_585 ( V_2 ) ;
return V_120 ;
}
void F_621 ( struct V_1 * V_2 )
{
struct V_32 V_21 ;
struct V_138 * V_138 = V_2 -> V_138 ;
if ( V_581 ( V_2 ) )
return;
V_21 . V_38 = 0x0 ;
V_21 . V_146 = V_1238 ;
V_21 . V_40 = true ;
F_150 ( V_2 , & V_21 ) ;
V_585 ( V_2 ) ;
if ( ! V_366 )
return;
F_190 ( & V_138 -> V_5 . V_365 ,
V_367 ) ;
}
void F_622 ( struct V_1 * V_2 )
{
int V_120 ;
V_2 -> V_5 . V_6 . V_392 = 0 ;
V_120 = V_581 ( V_2 ) ;
F_13 ( V_120 ) ;
F_554 ( V_2 ) ;
V_585 ( V_2 ) ;
V_73 -> V_1235 ( V_2 ) ;
}
void F_619 ( struct V_1 * V_2 , bool V_1239 )
{
V_2 -> V_5 . V_631 = 0 ;
F_170 ( & V_2 -> V_5 . V_85 , 0 ) ;
V_2 -> V_5 . V_623 = 0 ;
V_2 -> V_5 . V_622 = false ;
F_623 ( V_2 ) ;
F_463 ( V_2 ) ;
memset ( V_2 -> V_5 . V_181 , 0 , sizeof( V_2 -> V_5 . V_181 ) ) ;
F_92 ( V_2 ) ;
V_2 -> V_5 . V_185 = V_1240 ;
F_93 ( V_2 ) ;
V_2 -> V_5 . V_186 = V_197 ;
F_94 ( V_2 ) ;
V_2 -> V_5 . V_79 = 0 ;
F_30 ( V_67 , V_2 ) ;
V_2 -> V_5 . V_6 . V_392 = 0 ;
V_2 -> V_5 . V_396 . V_392 = 0 ;
F_203 ( V_2 ) ;
F_64 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1102 = false ;
if ( ! V_1239 ) {
F_624 ( V_2 ) ;
V_2 -> V_5 . V_427 = 0x30000 ;
}
memset ( V_2 -> V_5 . V_589 , 0 , sizeof( V_2 -> V_5 . V_589 ) ) ;
V_2 -> V_5 . V_117 = ~ 0 ;
V_2 -> V_5 . V_118 = ~ 0 ;
V_73 -> V_1241 ( V_2 , V_1239 ) ;
}
void F_625 ( struct V_1 * V_2 , T_14 V_41 )
{
struct V_805 V_1075 ;
F_341 ( V_2 , & V_1075 , V_1080 ) ;
V_1075 . V_887 = V_41 << 8 ;
V_1075 . V_228 = V_41 << 12 ;
F_340 ( V_2 , & V_1075 , V_1080 ) ;
F_443 ( V_2 , 0 ) ;
}
int F_626 ( void )
{
struct V_138 * V_138 ;
struct V_1 * V_2 ;
int V_3 ;
int V_108 ;
T_2 V_1242 ;
T_2 V_1243 = 0 ;
bool V_1244 , V_1245 = false ;
F_14 () ;
V_108 = V_73 -> V_1246 () ;
if ( V_108 != 0 )
return V_108 ;
V_1242 = F_148 () ;
V_1244 = ! F_153 () ;
F_477 (kvm, &vm_list, vm_list) {
F_174 (i, vcpu, kvm) {
if ( ! V_1244 && V_2 -> V_23 == F_8 () )
F_30 ( V_339 , V_2 ) ;
if ( V_1244 && V_2 -> V_5 . V_584 > V_1242 ) {
V_1245 = true ;
if ( V_2 -> V_5 . V_584 > V_1243 )
V_1243 = V_2 -> V_5 . V_584 ;
}
}
}
if ( V_1245 ) {
T_2 V_1247 = V_1243 - V_1242 ;
V_336 = true ;
F_477 (kvm, &vm_list, vm_list) {
F_174 (i, vcpu, kvm) {
V_2 -> V_5 . V_582 += V_1247 ;
V_2 -> V_5 . V_584 = V_1242 ;
F_30 ( V_298 , V_2 ) ;
}
V_138 -> V_5 . V_314 = 0 ;
V_138 -> V_5 . V_316 = 0 ;
}
}
return 0 ;
}
void F_627 ( void )
{
V_73 -> V_1248 () ;
F_18 () ;
}
int F_628 ( void )
{
int V_120 ;
V_120 = V_73 -> V_1249 () ;
if ( V_120 != 0 )
return V_120 ;
if ( V_273 ) {
T_2 V_1250 = F_333 ( 0x7fffffffULL ,
F_144 ( V_278 , V_274 ) ) ;
V_705 = V_1250 ;
V_272 = 1ULL << V_277 ;
}
F_330 () ;
return 0 ;
}
void F_629 ( void )
{
V_73 -> V_1251 () ;
}
void F_630 ( void * V_1252 )
{
V_73 -> V_1253 ( V_1252 ) ;
}
bool F_631 ( struct V_1 * V_2 )
{
return V_2 -> V_138 -> V_5 . V_788 == V_2 -> V_299 ;
}
bool F_602 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_31 & V_1254 ) != 0 ;
}
bool F_632 ( struct V_1 * V_2 )
{
return F_258 ( V_2 -> V_138 ) == F_88 ( V_2 ) ;
}
int F_633 ( struct V_1 * V_2 )
{
struct V_387 * V_387 ;
struct V_138 * V_138 ;
int V_120 ;
F_13 ( V_2 -> V_138 == NULL ) ;
V_138 = V_2 -> V_138 ;
V_2 -> V_5 . V_1137 . V_1138 = false ;
V_2 -> V_5 . V_913 . V_834 = & V_1255 ;
if ( ! F_258 ( V_138 ) || F_631 ( V_2 ) )
V_2 -> V_5 . V_1031 = V_1139 ;
else
V_2 -> V_5 . V_1031 = V_1151 ;
V_387 = F_634 ( V_678 | V_1256 ) ;
if ( ! V_387 ) {
V_120 = - V_389 ;
goto V_1257;
}
V_2 -> V_5 . V_866 = F_635 ( V_387 ) ;
F_138 ( V_2 , V_1001 ) ;
V_120 = F_636 ( V_2 ) ;
if ( V_120 < 0 )
goto V_1258;
if ( F_258 ( V_138 ) ) {
V_120 = F_637 ( V_2 ) ;
if ( V_120 < 0 )
goto V_1259;
} else
F_638 ( & V_1260 ) ;
V_2 -> V_5 . V_376 = F_287 ( V_441 * sizeof( T_2 ) * 4 ,
V_678 ) ;
if ( ! V_2 -> V_5 . V_376 ) {
V_120 = - V_389 ;
goto V_1261;
}
V_2 -> V_5 . V_368 = V_441 ;
if ( ! F_639 ( & V_2 -> V_5 . V_580 , V_678 ) ) {
V_120 = - V_389 ;
goto V_1262;
}
F_607 ( V_2 ) ;
V_2 -> V_5 . V_302 = 0x0 ;
V_2 -> V_5 . V_349 = false ;
V_2 -> V_5 . V_153 = 0 ;
V_2 -> V_5 . V_1263 = V_1264 + V_655 ;
V_2 -> V_5 . V_1012 = F_640 ( V_2 ) ;
V_2 -> V_5 . V_1265 = V_1266 ;
F_1 ( V_2 ) ;
F_641 ( V_2 ) ;
V_2 -> V_5 . V_595 = - 1 ;
return 0 ;
V_1262:
F_199 ( V_2 -> V_5 . V_376 ) ;
V_1261:
F_642 ( V_2 ) ;
V_1259:
F_643 ( V_2 ) ;
V_1258:
F_644 ( ( unsigned long ) V_2 -> V_5 . V_866 ) ;
V_1257:
return V_120 ;
}
void F_645 ( struct V_1 * V_2 )
{
int V_485 ;
F_646 ( V_2 ) ;
F_199 ( V_2 -> V_5 . V_376 ) ;
F_642 ( V_2 ) ;
V_485 = F_227 ( & V_2 -> V_138 -> V_486 ) ;
F_643 ( V_2 ) ;
F_228 ( & V_2 -> V_138 -> V_486 , V_485 ) ;
F_644 ( ( unsigned long ) V_2 -> V_5 . V_866 ) ;
if ( ! F_88 ( V_2 ) )
F_647 ( & V_1260 ) ;
}
void F_648 ( struct V_1 * V_2 , int V_23 )
{
V_73 -> V_1267 ( V_2 , V_23 ) ;
}
int F_649 ( struct V_138 * V_138 , unsigned long type )
{
if ( type )
return - V_577 ;
F_650 ( & V_138 -> V_5 . V_1268 ) ;
F_651 ( & V_138 -> V_5 . V_1269 ) ;
F_651 ( & V_138 -> V_5 . V_1270 ) ;
F_651 ( & V_138 -> V_5 . V_1271 ) ;
F_170 ( & V_138 -> V_5 . V_1272 , 0 ) ;
F_211 ( V_750 , & V_138 -> V_5 . V_1273 ) ;
F_211 ( V_1274 ,
& V_138 -> V_5 . V_1273 ) ;
F_652 ( & V_138 -> V_5 . V_313 ) ;
F_653 ( & V_138 -> V_5 . V_1275 ) ;
F_654 ( & V_138 -> V_5 . V_327 ) ;
F_169 ( V_138 ) ;
F_655 ( & V_138 -> V_5 . V_363 , F_186 ) ;
F_655 ( & V_138 -> V_5 . V_365 , F_191 ) ;
return 0 ;
}
static void F_656 ( struct V_1 * V_2 )
{
int V_120 ;
V_120 = V_581 ( V_2 ) ;
F_13 ( V_120 ) ;
F_554 ( V_2 ) ;
V_585 ( V_2 ) ;
}
static void F_657 ( struct V_138 * V_138 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_174 (i, vcpu, kvm) {
F_64 ( V_2 ) ;
F_656 ( V_2 ) ;
}
F_174 (i, vcpu, kvm)
F_614 ( V_2 ) ;
F_296 ( & V_138 -> V_729 ) ;
for ( V_3 = 0 ; V_3 < F_141 ( & V_138 -> V_295 ) ; V_3 ++ )
V_138 -> V_1276 [ V_3 ] = NULL ;
F_170 ( & V_138 -> V_295 , 0 ) ;
F_298 ( & V_138 -> V_729 ) ;
}
void F_658 ( struct V_138 * V_138 )
{
F_659 ( & V_138 -> V_5 . V_365 ) ;
F_659 ( & V_138 -> V_5 . V_363 ) ;
F_660 ( V_138 ) ;
F_661 ( V_138 ) ;
}
int F_662 ( struct V_138 * V_138 , int V_1236 , T_6 V_391 , T_1 V_491 )
{
int V_3 , V_120 ;
unsigned long V_1277 ;
struct V_1278 * V_1279 = V_1278 ( V_138 ) ;
struct V_1280 * V_10 , V_853 ;
if ( F_28 ( V_1236 >= V_1281 ) )
return - V_577 ;
V_10 = F_663 ( V_1279 , V_1236 ) ;
if ( V_491 ) {
if ( F_28 ( V_10 -> V_1282 ) )
return - V_596 ;
V_1277 = F_664 ( NULL , 0 , V_491 , V_1283 | V_1284 ,
V_1285 | V_1286 , 0 ) ;
if ( F_196 ( ( void * ) V_1277 ) )
return F_197 ( ( void * ) V_1277 ) ;
} else {
if ( ! V_10 -> V_1282 )
return 0 ;
V_1277 = 0 ;
}
V_853 = * V_10 ;
for ( V_3 = 0 ; V_3 < V_1287 ; V_3 ++ ) {
struct V_1288 V_1289 ;
V_1289 . V_10 = V_1236 | ( V_3 << 16 ) ;
V_1289 . V_309 = 0 ;
V_1289 . V_1290 = V_391 ;
V_1289 . V_1291 = V_1277 ;
V_1289 . V_1292 = V_491 ;
V_120 = F_665 ( V_138 , & V_1289 ) ;
if ( V_120 < 0 )
return V_120 ;
}
if ( ! V_491 ) {
V_120 = F_666 ( V_853 . V_1291 , V_853 . V_1282 * V_107 ) ;
F_28 ( V_120 < 0 ) ;
}
return 0 ;
}
int F_667 ( struct V_138 * V_138 , int V_1236 , T_6 V_391 , T_1 V_491 )
{
int V_120 ;
F_296 ( & V_138 -> V_716 ) ;
V_120 = F_662 ( V_138 , V_1236 , V_391 , V_491 ) ;
F_298 ( & V_138 -> V_716 ) ;
return V_120 ;
}
void F_668 ( struct V_138 * V_138 )
{
if ( V_398 -> V_1293 == V_138 -> V_1293 ) {
F_667 ( V_138 , V_1294 , 0 , 0 ) ;
F_667 ( V_138 , V_1295 , 0 , 0 ) ;
F_667 ( V_138 , V_1296 , 0 , 0 ) ;
}
F_669 ( V_138 ) ;
F_199 ( V_138 -> V_5 . V_769 ) ;
F_199 ( V_138 -> V_5 . V_1297 ) ;
F_657 ( V_138 ) ;
F_199 ( F_670 ( V_138 -> V_5 . V_1298 , 1 ) ) ;
}
void F_671 ( struct V_138 * V_138 , struct V_1280 * free ,
struct V_1280 * V_1299 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1300 ; ++ V_3 ) {
if ( ! V_1299 || free -> V_5 . V_1301 [ V_3 ] != V_1299 -> V_5 . V_1301 [ V_3 ] ) {
F_672 ( free -> V_5 . V_1301 [ V_3 ] ) ;
free -> V_5 . V_1301 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1299 || free -> V_5 . V_1302 [ V_3 - 1 ] !=
V_1299 -> V_5 . V_1302 [ V_3 - 1 ] ) {
F_672 ( free -> V_5 . V_1302 [ V_3 - 1 ] ) ;
free -> V_5 . V_1302 [ V_3 - 1 ] = NULL ;
}
}
}
int F_673 ( struct V_138 * V_138 , struct V_1280 * V_10 ,
unsigned long V_1282 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1300 ; ++ V_3 ) {
unsigned long V_1303 ;
int V_1304 ;
int V_751 = V_3 + 1 ;
V_1304 = F_674 ( V_10 -> V_1305 + V_1282 - 1 ,
V_10 -> V_1305 , V_751 ) + 1 ;
V_10 -> V_5 . V_1301 [ V_3 ] =
F_675 ( V_1304 * sizeof( * V_10 -> V_5 . V_1301 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1301 [ V_3 ] )
goto V_390;
if ( V_3 == 0 )
continue;
V_10 -> V_5 . V_1302 [ V_3 - 1 ] = F_675 ( V_1304 *
sizeof( * V_10 -> V_5 . V_1302 [ V_3 - 1 ] ) ) ;
if ( ! V_10 -> V_5 . V_1302 [ V_3 - 1 ] )
goto V_390;
if ( V_10 -> V_1305 & ( F_676 ( V_751 ) - 1 ) )
V_10 -> V_5 . V_1302 [ V_3 - 1 ] [ 0 ] . V_1306 = 1 ;
if ( ( V_10 -> V_1305 + V_1282 ) & ( F_676 ( V_751 ) - 1 ) )
V_10 -> V_5 . V_1302 [ V_3 - 1 ] [ V_1304 - 1 ] . V_1306 = 1 ;
V_1303 = V_10 -> V_1291 >> V_106 ;
if ( ( V_10 -> V_1305 ^ V_1303 ) & ( F_676 ( V_751 ) - 1 ) ||
! F_677 () ) {
unsigned long V_798 ;
for ( V_798 = 0 ; V_798 < V_1304 ; ++ V_798 )
V_10 -> V_5 . V_1302 [ V_3 - 1 ] [ V_798 ] . V_1306 = 1 ;
}
}
return 0 ;
V_390:
for ( V_3 = 0 ; V_3 < V_1300 ; ++ V_3 ) {
F_672 ( V_10 -> V_5 . V_1301 [ V_3 ] ) ;
V_10 -> V_5 . V_1301 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_672 ( V_10 -> V_5 . V_1302 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1302 [ V_3 - 1 ] = NULL ;
}
return - V_389 ;
}
void F_678 ( struct V_138 * V_138 , struct V_1278 * V_1279 )
{
F_679 ( V_138 , V_1279 ) ;
}
int F_680 ( struct V_138 * V_138 ,
struct V_1280 * V_1307 ,
const struct V_1288 * V_1308 ,
enum V_1309 V_1310 )
{
return 0 ;
}
static void F_681 ( struct V_138 * V_138 ,
struct V_1280 * V_854 )
{
if ( V_854 -> V_309 & V_1311 ) {
F_682 ( V_138 , V_854 ) ;
return;
}
if ( V_854 -> V_309 & V_1312 ) {
if ( V_73 -> V_1313 )
V_73 -> V_1313 ( V_138 , V_854 ) ;
else
F_682 ( V_138 , V_854 ) ;
} else {
if ( V_73 -> V_1314 )
V_73 -> V_1314 ( V_138 , V_854 ) ;
}
}
void F_683 ( struct V_138 * V_138 ,
const struct V_1288 * V_1308 ,
const struct V_1280 * V_853 ,
const struct V_1280 * V_854 ,
enum V_1309 V_1310 )
{
int V_1315 = 0 ;
if ( ! V_138 -> V_5 . V_717 )
V_1315 = F_684 ( V_138 ) ;
if ( V_1315 )
F_297 ( V_138 , V_1315 ) ;
if ( ( V_1310 != V_1316 ) &&
( V_853 -> V_309 & V_1312 ) &&
! ( V_854 -> V_309 & V_1312 ) )
F_685 ( V_138 , V_854 ) ;
if ( V_1310 != V_1316 )
F_681 ( V_138 , (struct V_1280 * ) V_854 ) ;
}
void F_686 ( struct V_138 * V_138 )
{
F_687 ( V_138 ) ;
}
void F_688 ( struct V_138 * V_138 ,
struct V_1280 * V_10 )
{
F_687 ( V_138 ) ;
}
static inline bool F_689 ( struct V_1 * V_2 )
{
if ( ! F_690 ( & V_2 -> V_1317 . V_1318 ) )
return true ;
if ( F_691 ( V_2 ) )
return true ;
if ( V_2 -> V_5 . V_1137 . V_1138 )
return true ;
if ( F_141 ( & V_2 -> V_5 . V_85 ) )
return true ;
if ( F_58 ( V_597 , & V_2 -> V_341 ) )
return true ;
if ( F_254 ( V_2 ) &&
F_255 ( V_2 ) )
return true ;
return false ;
}
int F_577 ( struct V_1 * V_2 )
{
if ( F_447 ( V_2 ) && V_73 -> V_1069 )
V_73 -> V_1069 ( V_2 , false ) ;
return F_579 ( V_2 ) || F_689 ( V_2 ) ;
}
int F_692 ( struct V_1 * V_2 )
{
return F_693 ( V_2 ) == V_1122 ;
}
int F_254 ( struct V_1 * V_2 )
{
return V_73 -> V_1071 ( V_2 ) ;
}
unsigned long F_461 ( struct V_1 * V_2 )
{
if ( F_521 ( V_2 ) )
return F_439 ( V_2 ) ;
return ( T_1 ) ( F_388 ( V_2 , V_1080 ) +
F_439 ( V_2 ) ) ;
}
bool F_694 ( struct V_1 * V_2 , unsigned long V_1319 )
{
return F_461 ( V_2 ) == V_1319 ;
}
unsigned long F_438 ( struct V_1 * V_2 )
{
unsigned long V_952 ;
V_952 = V_73 -> V_982 ( V_2 ) ;
if ( V_2 -> V_177 & V_955 )
V_952 &= ~ V_954 ;
return V_952 ;
}
static void F_468 ( struct V_1 * V_2 , unsigned long V_952 )
{
if ( V_2 -> V_177 & V_955 &&
F_694 ( V_2 , V_2 -> V_5 . V_959 ) )
V_952 |= V_954 ;
V_73 -> V_1320 ( V_2 , V_952 ) ;
}
void F_444 ( struct V_1 * V_2 , unsigned long V_952 )
{
F_468 ( V_2 , V_952 ) ;
F_30 ( V_67 , V_2 ) ;
}
void F_695 ( struct V_1 * V_2 , struct V_1321 * V_360 )
{
int V_120 ;
if ( ( V_2 -> V_5 . V_84 . V_944 != V_360 -> V_5 . V_944 ) ||
V_360 -> V_1322 )
return;
V_120 = F_561 ( V_2 ) ;
if ( F_166 ( V_120 ) )
return;
if ( ! V_2 -> V_5 . V_84 . V_944 &&
V_360 -> V_5 . V_104 != V_2 -> V_5 . V_84 . V_1323 ( V_2 ) )
return;
V_2 -> V_5 . V_84 . V_1324 ( V_2 , V_360 -> V_812 , 0 , true ) ;
}
static inline T_1 F_696 ( T_5 V_102 )
{
return F_697 ( V_102 & 0xffffffff , F_698 ( V_4 ) ) ;
}
static inline T_1 F_699 ( T_1 V_1325 )
{
return ( V_1325 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_700 ( struct V_1 * V_2 , T_5 V_102 )
{
T_1 V_1325 = F_696 ( V_102 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1325 ] != ~ 0 )
V_1325 = F_699 ( V_1325 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1325 ] = V_102 ;
}
static T_1 F_701 ( struct V_1 * V_2 , T_5 V_102 )
{
int V_3 ;
T_1 V_1325 = F_696 ( V_102 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1325 ] != V_102 &&
V_2 -> V_5 . V_6 . V_7 [ V_1325 ] != ~ 0 ) ; V_3 ++ )
V_1325 = F_699 ( V_1325 ) ;
return V_1325 ;
}
bool F_702 ( struct V_1 * V_2 , T_5 V_102 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_701 ( V_2 , V_102 ) ] == V_102 ;
}
static void F_703 ( struct V_1 * V_2 , T_5 V_102 )
{
T_1 V_3 , V_798 , V_1326 ;
V_3 = V_798 = F_701 ( V_2 , V_102 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_798 = F_699 ( V_798 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_798 ] == ~ 0 )
return;
V_1326 = F_696 ( V_2 -> V_5 . V_6 . V_7 [ V_798 ] ) ;
} while ( ( V_3 <= V_798 ) ? ( V_3 < V_1326 && V_1326 <= V_798 ) : ( V_3 < V_1326 || V_1326 <= V_798 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_798 ] ;
V_3 = V_798 ;
}
}
static int F_704 ( struct V_1 * V_2 , T_1 V_194 )
{
return F_183 ( V_2 -> V_138 , & V_2 -> V_5 . V_6 . V_38 , & V_194 ,
sizeof( V_194 ) ) ;
}
void F_705 ( struct V_1 * V_2 ,
struct V_1321 * V_360 )
{
struct V_75 V_76 ;
F_706 ( V_360 -> V_5 . V_1327 , V_360 -> V_812 ) ;
F_700 ( V_2 , V_360 -> V_5 . V_102 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_392 & V_393 ) ||
( V_2 -> V_5 . V_6 . V_394 &&
V_73 -> V_88 ( V_2 ) == 0 ) )
F_30 ( V_1101 , V_2 ) ;
else if ( ! F_704 ( V_2 , V_1328 ) ) {
V_76 . V_41 = V_42 ;
V_76 . V_914 = true ;
V_76 . V_62 = 0 ;
V_76 . V_81 = false ;
V_76 . V_80 = V_360 -> V_5 . V_1327 ;
F_36 ( V_2 , & V_76 ) ;
}
}
void F_707 ( struct V_1 * V_2 ,
struct V_1321 * V_360 )
{
struct V_75 V_76 ;
F_708 ( V_360 -> V_5 . V_1327 , V_360 -> V_812 ) ;
if ( V_360 -> V_1322 )
V_360 -> V_5 . V_1327 = ~ 0 ;
else
F_703 ( V_2 , V_360 -> V_5 . V_102 ) ;
if ( ( V_2 -> V_5 . V_6 . V_392 & V_393 ) &&
! F_704 ( V_2 , V_1329 ) ) {
V_76 . V_41 = V_42 ;
V_76 . V_914 = true ;
V_76 . V_62 = 0 ;
V_76 . V_81 = false ;
V_76 . V_80 = V_360 -> V_5 . V_1327 ;
F_36 ( V_2 , & V_76 ) ;
}
V_2 -> V_5 . V_6 . V_1102 = false ;
V_2 -> V_5 . V_1031 = V_1139 ;
}
bool F_709 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_392 & V_393 ) )
return true ;
else
return ! F_256 ( V_2 ) &&
V_73 -> V_1071 ( V_2 ) ;
}
void F_710 ( struct V_138 * V_138 )
{
F_41 ( & V_138 -> V_5 . V_1330 ) ;
}
void F_711 ( struct V_138 * V_138 )
{
F_712 ( & V_138 -> V_5 . V_1330 ) ;
}
bool F_713 ( struct V_138 * V_138 )
{
return F_141 ( & V_138 -> V_5 . V_1330 ) ;
}
void F_714 ( struct V_138 * V_138 )
{
F_41 ( & V_138 -> V_5 . V_1272 ) ;
}
void F_715 ( struct V_138 * V_138 )
{
F_712 ( & V_138 -> V_5 . V_1272 ) ;
}
bool F_66 ( struct V_138 * V_138 )
{
return F_141 ( & V_138 -> V_5 . V_1272 ) ;
}
int F_716 ( struct V_1331 * V_1332 ,
struct V_1333 * V_1334 )
{
struct V_1335 * V_1336 =
F_4 ( V_1332 , struct V_1335 , V_1337 ) ;
if ( V_73 -> V_1338 ) {
V_1336 -> V_1339 = V_1334 ;
return V_73 -> V_1338 ( V_1336 -> V_138 ,
V_1334 -> V_592 , V_1336 -> V_1340 , 1 ) ;
}
return - V_577 ;
}
void F_717 ( struct V_1331 * V_1332 ,
struct V_1333 * V_1334 )
{
int V_108 ;
struct V_1335 * V_1336 =
F_4 ( V_1332 , struct V_1335 , V_1337 ) ;
if ( ! V_73 -> V_1338 ) {
F_28 ( V_1336 -> V_1339 != NULL ) ;
return;
}
F_28 ( V_1336 -> V_1339 != V_1334 ) ;
V_1336 -> V_1339 = NULL ;
V_108 = V_73 -> V_1338 ( V_1336 -> V_138 , V_1334 -> V_592 , V_1336 -> V_1340 , 0 ) ;
if ( V_108 )
F_10 ( V_1341 L_30
L_31 , V_1336 -> V_1337 . V_1327 , V_108 ) ;
}
int F_718 ( struct V_138 * V_138 , unsigned int V_1342 ,
T_7 V_1343 , bool V_1344 )
{
if ( ! V_73 -> V_1338 )
return - V_577 ;
return V_73 -> V_1338 ( V_138 , V_1342 , V_1343 , V_1344 ) ;
}
