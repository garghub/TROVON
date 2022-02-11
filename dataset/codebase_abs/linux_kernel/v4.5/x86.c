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
if ( F_123 ( V_138 , V_239 , & V_240 , sizeof( V_240 ) ) )
return;
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
void F_172 ( struct V_138 * V_138 )
{
F_173 ( V_138 , V_339 ) ;
}
static void F_174 ( struct V_138 * V_138 )
{
#ifdef F_62
int V_3 ;
struct V_1 * V_2 ;
struct V_291 * V_292 = & V_138 -> V_5 ;
F_156 ( & V_292 -> V_327 ) ;
F_172 ( V_138 ) ;
F_169 ( V_138 ) ;
F_175 (i, vcpu, kvm)
F_30 ( V_340 , V_2 ) ;
F_175 (i, vcpu, kvm)
F_176 ( V_339 , & V_2 -> V_341 ) ;
F_157 ( & V_292 -> V_327 ) ;
#endif
}
static int F_177 ( struct V_1 * V_267 )
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
F_178 ( V_309 ) ;
V_279 = F_179 ( V_348 ) ;
if ( F_166 ( V_279 == 0 ) ) {
F_180 ( V_309 ) ;
F_30 ( V_340 , V_267 ) ;
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
F_180 ( V_309 ) ;
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
if ( F_166 ( F_181 ( V_267 -> V_138 , & V_2 -> V_355 ,
& V_346 , sizeof( V_346 ) ) ) )
return 0 ;
F_182 ( F_183 ( struct V_345 , V_240 ) != 0 ) ;
V_2 -> V_351 . V_240 = V_346 . V_240 + 1 ;
F_184 ( V_267 -> V_138 , & V_2 -> V_355 ,
& V_2 -> V_351 ,
sizeof( V_2 -> V_351 . V_240 ) ) ;
F_185 () ;
V_347 = ( V_346 . V_309 & V_356 ) ;
if ( V_2 -> V_357 ) {
V_347 |= V_356 ;
V_2 -> V_357 = false ;
}
if ( V_296 )
V_347 |= V_358 ;
V_2 -> V_351 . V_309 = V_347 ;
F_186 ( V_267 -> V_299 , & V_2 -> V_351 ) ;
F_184 ( V_267 -> V_138 , & V_2 -> V_355 ,
& V_2 -> V_351 ,
sizeof( V_2 -> V_351 ) ) ;
F_185 () ;
V_2 -> V_351 . V_240 ++ ;
F_184 ( V_267 -> V_138 , & V_2 -> V_355 ,
& V_2 -> V_351 ,
sizeof( V_2 -> V_351 . V_240 ) ) ;
return 0 ;
}
static void F_187 ( struct V_359 * V_360 )
{
int V_3 ;
struct V_361 * V_362 = F_188 ( V_360 ) ;
struct V_291 * V_292 = F_4 ( V_362 , struct V_291 ,
V_363 ) ;
struct V_138 * V_138 = F_4 ( V_292 , struct V_138 , V_5 ) ;
struct V_1 * V_2 ;
F_175 (i, vcpu, kvm) {
F_30 ( V_340 , V_2 ) ;
F_189 ( V_2 ) ;
}
}
static void F_190 ( struct V_1 * V_267 )
{
struct V_138 * V_138 = V_267 -> V_138 ;
F_30 ( V_340 , V_267 ) ;
F_191 ( & V_138 -> V_5 . V_363 ,
V_364 ) ;
}
static void F_192 ( struct V_359 * V_360 )
{
struct V_361 * V_362 = F_188 ( V_360 ) ;
struct V_291 * V_292 = F_4 ( V_362 , struct V_291 ,
V_365 ) ;
struct V_138 * V_138 = F_4 ( V_292 , struct V_138 , V_5 ) ;
if ( ! V_366 )
return;
F_191 ( & V_138 -> V_5 . V_363 , 0 ) ;
F_191 ( & V_138 -> V_5 . V_365 ,
V_367 ) ;
}
static int F_193 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_38 )
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
V_21 < F_194 ( V_369 ) ) {
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
static int F_195 ( struct V_1 * V_2 , T_2 V_38 )
{
struct V_138 * V_138 = V_2 -> V_138 ;
int V_377 = F_56 ( V_2 ) ;
T_14 * V_378 = V_377 ? ( T_14 * ) ( long ) V_138 -> V_5 . F_195 . V_379
: ( T_14 * ) ( long ) V_138 -> V_5 . F_195 . V_380 ;
T_14 V_381 = V_377 ? V_138 -> V_5 . F_195 . V_382
: V_138 -> V_5 . F_195 . V_383 ;
T_1 V_384 = V_38 & ~ V_385 ;
T_2 V_386 = V_38 & V_385 ;
T_14 * V_387 ;
int V_120 ;
V_120 = - V_388 ;
if ( V_384 >= V_381 )
goto V_113;
V_120 = - V_389 ;
V_387 = F_196 ( V_378 + ( V_384 * V_107 ) , V_107 ) ;
if ( F_197 ( V_387 ) ) {
V_120 = F_198 ( V_387 ) ;
goto V_113;
}
if ( F_199 ( V_2 , V_386 , V_387 , V_107 ) )
goto V_390;
V_120 = 0 ;
V_390:
F_200 ( V_387 ) ;
V_113:
return V_120 ;
}
static int F_201 ( struct V_1 * V_2 , T_2 V_38 )
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
if ( F_202 ( V_2 -> V_138 , & V_2 -> V_5 . V_6 . V_38 , V_391 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_394 = ! ( V_38 & V_395 ) ;
F_203 ( V_2 ) ;
return 0 ;
}
static void F_204 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_349 = false ;
}
static void F_205 ( struct V_1 * V_2 )
{
T_2 V_320 ;
if ( ! ( V_2 -> V_5 . V_396 . V_392 & V_397 ) )
return;
V_320 = V_398 -> V_399 . V_400 - V_2 -> V_5 . V_396 . V_401 ;
V_2 -> V_5 . V_396 . V_401 = V_398 -> V_399 . V_400 ;
V_2 -> V_5 . V_396 . V_402 = V_320 ;
}
static void F_206 ( struct V_1 * V_2 )
{
F_205 ( V_2 ) ;
if ( ! ( V_2 -> V_5 . V_396 . V_392 & V_397 ) )
return;
if ( F_166 ( F_181 ( V_2 -> V_138 , & V_2 -> V_5 . V_396 . V_403 ,
& V_2 -> V_5 . V_396 . V_404 , sizeof( struct V_405 ) ) ) )
return;
V_2 -> V_5 . V_396 . V_404 . V_404 += V_2 -> V_5 . V_396 . V_402 ;
V_2 -> V_5 . V_396 . V_404 . V_240 += 2 ;
V_2 -> V_5 . V_396 . V_402 = 0 ;
F_184 ( V_2 -> V_138 , & V_2 -> V_5 . V_396 . V_403 ,
& V_2 -> V_5 . V_396 . V_404 , sizeof( struct V_405 ) ) ;
}
int F_207 ( struct V_1 * V_2 , struct V_32 * V_33 )
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
F_208 ( V_2 , L_9 ,
V_38 ) ;
return 1 ;
}
break;
case V_415 :
if ( V_38 != 0 ) {
F_208 ( V_2 , L_10
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
F_208 ( V_2 , L_12 ,
V_262 , V_38 ) ;
break;
case 0x200 ... 0x2ff :
return F_209 ( V_2 , V_21 , V_38 ) ;
case V_419 :
return F_20 ( V_2 , V_33 ) ;
case V_420 ... V_420 + 0x3ff :
return F_210 ( V_2 , V_21 , V_38 ) ;
case V_421 :
F_211 ( V_2 , V_38 ) ;
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
F_204 ( V_2 ) ;
if ( V_2 -> V_299 == 0 && ! V_33 -> V_40 ) {
bool V_433 = ( V_21 == V_431 ) ;
if ( V_292 -> V_337 != V_433 )
F_212 ( V_298 ,
& V_2 -> V_341 ) ;
V_292 -> V_337 = V_433 ;
}
V_2 -> V_5 . time = V_38 ;
F_30 ( V_434 , V_2 ) ;
if ( ! ( V_38 & 1 ) )
break;
V_432 = V_38 & ~ ( V_385 | 1 ) ;
if ( F_202 ( V_2 -> V_138 ,
& V_2 -> V_5 . V_355 , V_38 & ~ 1ULL ,
sizeof( struct V_345 ) ) )
V_2 -> V_5 . V_349 = false ;
else
V_2 -> V_5 . V_349 = true ;
break;
}
case V_435 :
if ( F_201 ( V_2 , V_38 ) )
return 1 ;
break;
case V_436 :
if ( F_166 ( ! F_213 () ) )
return 1 ;
if ( V_38 & V_437 )
return 1 ;
if ( F_202 ( V_2 -> V_138 , & V_2 -> V_5 . V_396 . V_403 ,
V_38 & V_438 ,
sizeof( struct V_405 ) ) )
return 1 ;
V_2 -> V_5 . V_396 . V_392 = V_38 ;
if ( ! ( V_38 & V_397 ) )
break;
F_30 ( V_439 , V_2 ) ;
break;
case V_440 :
if ( F_214 ( V_2 , V_38 ) )
return 1 ;
break;
case V_372 :
case V_370 :
case V_375 ... F_194 ( V_441 ) - 1 :
return F_193 ( V_2 , V_21 , V_38 ) ;
case V_442 ... V_443 :
case V_444 ... V_445 :
V_406 = true ;
case V_446 ... V_447 :
case V_448 ... V_449 :
if ( F_215 ( V_2 , V_21 ) )
return F_216 ( V_2 , V_33 ) ;
if ( V_406 || V_38 != 0 )
F_208 ( V_2 , L_13
L_14 , V_21 , V_38 ) ;
break;
case V_450 :
break;
case V_451 ... V_452 :
case V_453 ... V_454 :
case V_455 :
case V_456 ... V_457 :
return F_217 ( V_2 , V_21 , V_38 ,
V_33 -> V_40 ) ;
case V_458 :
F_208 ( V_2 , L_15 , V_21 , V_38 ) ;
break;
case V_459 :
if ( ! F_218 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_460 . V_461 = V_38 ;
break;
case V_462 :
if ( ! F_218 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_460 . V_463 = V_38 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_138 -> V_5 . F_195 . V_21 ) )
return F_195 ( V_2 , V_38 ) ;
if ( F_215 ( V_2 , V_21 ) )
return F_216 ( V_2 , V_33 ) ;
if ( ! V_464 ) {
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
return V_73 -> V_465 ( V_2 , V_21 ) ;
}
static int F_219 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_466 )
{
T_2 V_38 ;
T_2 V_368 = V_2 -> V_5 . V_368 ;
unsigned V_369 = V_368 & 0xff ;
switch ( V_21 ) {
case V_467 :
case V_468 :
V_38 = 0 ;
break;
case V_469 :
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
V_21 < F_194 ( V_369 ) ) {
T_1 V_94 = V_21 - V_375 ;
V_38 = V_2 -> V_5 . V_376 [ V_94 ] ;
break;
}
return 1 ;
}
* V_466 = V_38 ;
return 0 ;
}
int F_220 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
switch ( V_33 -> V_146 ) {
case V_470 :
case V_471 :
case V_416 :
case V_472 :
case V_473 :
case V_474 :
case V_475 :
case V_476 :
case V_477 :
case V_478 :
case V_414 :
case V_410 :
case V_479 :
case V_407 :
case V_415 :
case V_412 :
V_33 -> V_38 = 0 ;
break;
case V_446 ... V_447 :
case V_442 ... V_443 :
case V_444 ... V_445 :
case V_448 ... V_449 :
if ( F_215 ( V_2 , V_33 -> V_146 ) )
return F_221 ( V_2 , V_33 -> V_146 , & V_33 -> V_38 ) ;
V_33 -> V_38 = 0 ;
break;
case V_408 :
V_33 -> V_38 = 0x100000000ULL ;
break;
case V_480 :
case 0x200 ... 0x2ff :
return F_222 ( V_2 , V_33 -> V_146 , & V_33 -> V_38 ) ;
case 0xcd :
V_33 -> V_38 = 3 ;
break;
case V_481 :
V_33 -> V_38 = 1 << 24 ;
break;
case V_419 :
V_33 -> V_38 = F_19 ( V_2 ) ;
break;
case V_420 ... V_420 + 0x3ff :
return F_223 ( V_2 , V_33 -> V_146 , & V_33 -> V_38 ) ;
break;
case V_421 :
V_33 -> V_38 = F_224 ( V_2 ) ;
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
case V_482 :
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
V_33 -> V_38 = V_2 -> V_5 . V_483 . V_392 ;
break;
case V_467 :
case V_468 :
case V_469 :
case V_372 :
case V_370 :
case V_375 ... F_194 ( V_441 ) - 1 :
return F_219 ( V_2 , V_33 -> V_146 , & V_33 -> V_38 ) ;
case V_450 :
V_33 -> V_38 = 0x20000000 ;
break;
case V_451 ... V_452 :
case V_453 ... V_454 :
case V_455 :
case V_456 ... V_457 :
return F_225 ( V_2 ,
V_33 -> V_146 , & V_33 -> V_38 ) ;
break;
case V_458 :
V_33 -> V_38 = 0xbe702111 ;
break;
case V_459 :
if ( ! F_218 ( V_2 ) )
return 1 ;
V_33 -> V_38 = V_2 -> V_5 . V_460 . V_461 ;
break;
case V_462 :
if ( ! F_218 ( V_2 ) )
return 1 ;
V_33 -> V_38 = V_2 -> V_5 . V_460 . V_463 ;
break;
default:
if ( F_215 ( V_2 , V_33 -> V_146 ) )
return F_221 ( V_2 , V_33 -> V_146 , & V_33 -> V_38 ) ;
if ( ! V_464 ) {
F_208 ( V_2 , L_17 , V_33 -> V_146 ) ;
return 1 ;
} else {
F_208 ( V_2 , L_18 , V_33 -> V_146 ) ;
V_33 -> V_38 = 0 ;
}
break;
}
return 0 ;
}
static int F_226 ( struct V_1 * V_2 , struct V_484 * V_19 ,
struct V_485 * V_486 ,
int (* F_227)( struct V_1 * V_2 ,
unsigned V_146 , T_2 * V_38 ) )
{
int V_3 , V_487 ;
V_487 = F_228 ( & V_2 -> V_138 -> V_488 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_489 ; ++ V_3 )
if ( F_227 ( V_2 , V_486 [ V_3 ] . V_146 , & V_486 [ V_3 ] . V_38 ) )
break;
F_229 ( & V_2 -> V_138 -> V_488 , V_487 ) ;
return V_3 ;
}
static int F_230 ( struct V_1 * V_2 , struct V_484 T_15 * V_490 ,
int (* F_227)( struct V_1 * V_2 ,
unsigned V_146 , T_2 * V_38 ) ,
int V_491 )
{
struct V_484 V_19 ;
struct V_485 * V_486 ;
int V_120 , V_492 ;
unsigned V_493 ;
V_120 = - V_101 ;
if ( F_231 ( & V_19 , V_490 , sizeof V_19 ) )
goto V_113;
V_120 = - V_388 ;
if ( V_19 . V_489 >= V_494 )
goto V_113;
V_493 = sizeof( struct V_485 ) * V_19 . V_489 ;
V_486 = F_196 ( V_490 -> V_486 , V_493 ) ;
if ( F_197 ( V_486 ) ) {
V_120 = F_198 ( V_486 ) ;
goto V_113;
}
V_120 = V_492 = F_226 ( V_2 , & V_19 , V_486 , F_227 ) ;
if ( V_120 < 0 )
goto V_390;
V_120 = - V_101 ;
if ( V_491 && F_232 ( V_490 -> V_486 , V_486 , V_493 ) )
goto V_390;
V_120 = V_492 ;
V_390:
F_200 ( V_486 ) ;
V_113:
return V_120 ;
}
int F_233 ( struct V_138 * V_138 , long V_495 )
{
int V_120 ;
switch ( V_495 ) {
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
case V_536 :
#ifdef F_234
case V_537 :
case V_538 :
#endif
V_120 = 1 ;
break;
case V_539 :
V_120 = V_73 -> V_540 () ;
break;
case V_541 :
V_120 = V_542 ;
break;
case V_543 :
V_120 = ! V_73 -> V_544 () ;
break;
case V_545 :
V_120 = V_546 ;
break;
case V_547 :
V_120 = V_548 ;
break;
case V_549 :
V_120 = V_550 ;
break;
case V_551 :
V_120 = 0 ;
break;
#ifdef F_234
case V_552 :
V_120 = F_235 ( & V_553 ) ;
break;
#endif
case V_554 :
V_120 = V_441 ;
break;
case V_555 :
V_120 = V_556 ;
break;
case V_557 :
V_120 = V_273 ;
break;
default:
V_120 = 0 ;
break;
}
return V_120 ;
}
long F_236 ( struct V_558 * V_559 ,
unsigned int V_560 , unsigned long V_561 )
{
void T_15 * V_562 = ( void T_15 * ) V_561 ;
long V_120 ;
switch ( V_560 ) {
case V_563 : {
struct V_564 T_15 * V_565 = V_562 ;
struct V_564 V_566 ;
unsigned V_492 ;
V_120 = - V_101 ;
if ( F_231 ( & V_566 , V_565 , sizeof V_566 ) )
goto V_113;
V_492 = V_566 . V_489 ;
V_566 . V_489 = V_567 + V_568 ;
if ( F_232 ( V_565 , & V_566 , sizeof V_566 ) )
goto V_113;
V_120 = - V_388 ;
if ( V_492 < V_566 . V_489 )
goto V_113;
V_120 = - V_101 ;
if ( F_232 ( V_565 -> V_569 , & V_570 ,
V_567 * sizeof( T_1 ) ) )
goto V_113;
if ( F_232 ( V_565 -> V_569 + V_567 ,
& V_571 ,
V_568 * sizeof( T_1 ) ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_572 :
case V_573 : {
struct V_574 T_15 * V_575 = V_562 ;
struct V_574 V_576 ;
V_120 = - V_101 ;
if ( F_231 ( & V_576 , V_575 , sizeof V_576 ) )
goto V_113;
V_120 = F_237 ( & V_576 , V_575 -> V_486 ,
V_560 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_232 ( V_575 , & V_576 , sizeof V_576 ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_577 : {
T_2 V_578 ;
V_578 = V_579 ;
V_120 = - V_101 ;
if ( F_232 ( V_562 , & V_578 , sizeof V_578 ) )
goto V_113;
V_120 = 0 ;
break;
}
default:
V_120 = - V_580 ;
}
V_113:
return V_120 ;
}
static void F_238 ( void * V_581 )
{
F_239 () ;
}
static bool F_240 ( struct V_1 * V_2 )
{
return F_66 ( V_2 -> V_138 ) ;
}
static inline void F_241 ( struct V_1 * V_2 )
{
F_212 ( V_582 , & V_2 -> V_341 ) ;
}
void F_242 ( struct V_1 * V_2 , int V_23 )
{
if ( F_240 ( V_2 ) ) {
if ( V_73 -> V_583 () )
F_243 ( V_23 , V_2 -> V_5 . V_584 ) ;
else if ( V_2 -> V_23 != - 1 && V_2 -> V_23 != V_23 )
F_244 ( V_2 -> V_23 ,
F_238 , NULL , 1 ) ;
}
V_73 -> V_585 ( V_2 , V_23 ) ;
if ( F_166 ( V_2 -> V_5 . V_586 ) ) {
F_159 ( V_2 , V_2 -> V_5 . V_586 ) ;
V_2 -> V_5 . V_586 = 0 ;
F_30 ( V_340 , V_2 ) ;
}
if ( F_166 ( V_2 -> V_23 != V_23 ) || F_153 () ) {
T_12 V_587 = ! V_2 -> V_5 . V_588 ? 0 :
F_148 () - V_2 -> V_5 . V_588 ;
if ( V_587 < 0 )
F_245 ( L_19 ) ;
if ( F_153 () ) {
T_2 V_94 = F_147 ( V_2 ,
V_2 -> V_5 . V_325 ) ;
V_73 -> V_326 ( V_2 , V_94 ) ;
V_2 -> V_5 . V_275 = 1 ;
}
if ( ! V_2 -> V_138 -> V_5 . V_296 || V_2 -> V_23 == - 1 )
F_30 ( V_434 , V_2 ) ;
if ( V_2 -> V_23 != V_23 )
F_241 ( V_2 ) ;
V_2 -> V_23 = V_23 ;
}
F_30 ( V_439 , V_2 ) ;
}
void F_246 ( struct V_1 * V_2 )
{
V_73 -> V_589 ( V_2 ) ;
F_247 ( V_2 ) ;
V_2 -> V_5 . V_588 = F_148 () ;
}
static int F_248 ( struct V_1 * V_2 ,
struct V_590 * V_591 )
{
if ( V_2 -> V_5 . V_592 )
V_73 -> V_593 ( V_2 ) ;
memcpy ( V_591 -> V_594 , V_2 -> V_5 . V_595 -> V_594 , sizeof *V_591 ) ;
return 0 ;
}
static int F_249 ( struct V_1 * V_2 ,
struct V_590 * V_591 )
{
F_250 ( V_2 , V_591 ) ;
F_251 ( V_2 ) ;
return 0 ;
}
static int F_252 ( struct V_1 * V_2 )
{
return ( ! F_88 ( V_2 ) ||
F_253 ( V_2 ) ) ;
}
static int F_254 ( struct V_1 * V_2 )
{
return F_255 ( V_2 ) &&
! F_256 ( V_2 ) &&
! F_257 ( V_2 ) &&
F_252 ( V_2 ) ;
}
static int F_258 ( struct V_1 * V_2 ,
struct V_596 * V_597 )
{
if ( V_597 -> V_597 >= V_598 )
return - V_580 ;
if ( ! F_259 ( V_2 -> V_138 ) ) {
F_260 ( V_2 , V_597 -> V_597 , false ) ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
if ( F_261 ( V_2 -> V_138 ) )
return - V_599 ;
if ( V_2 -> V_5 . V_600 != - 1 )
return - V_601 ;
V_2 -> V_5 . V_600 = V_597 -> V_597 ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
static int F_262 ( struct V_1 * V_2 )
{
F_40 ( V_2 ) ;
return 0 ;
}
static int F_263 ( struct V_1 * V_2 )
{
F_30 ( V_602 , V_2 ) ;
return 0 ;
}
static int F_264 ( struct V_1 * V_2 ,
struct V_603 * V_604 )
{
if ( V_604 -> V_309 )
return - V_580 ;
V_2 -> V_5 . V_605 = ! ! V_604 -> V_606 ;
return 0 ;
}
static int F_265 ( struct V_1 * V_2 ,
T_2 V_368 )
{
int V_120 ;
unsigned V_369 = V_368 & 0xff , V_607 ;
V_120 = - V_580 ;
if ( ! V_369 || V_369 >= V_441 )
goto V_113;
if ( V_368 & ~ ( V_579 | 0xff | 0xff0000 ) )
goto V_113;
V_120 = 0 ;
V_2 -> V_5 . V_368 = V_368 ;
if ( V_368 & V_373 )
V_2 -> V_5 . V_374 = ~ ( T_2 ) 0 ;
for ( V_607 = 0 ; V_607 < V_369 ; V_607 ++ )
V_2 -> V_5 . V_376 [ V_607 * 4 ] = ~ ( T_2 ) 0 ;
V_113:
return V_120 ;
}
static int F_266 ( struct V_1 * V_2 ,
struct V_608 * V_609 )
{
T_2 V_368 = V_2 -> V_5 . V_368 ;
unsigned V_369 = V_368 & 0xff ;
T_2 * V_610 = V_2 -> V_5 . V_376 ;
if ( V_609 -> V_607 >= V_369 || ! ( V_609 -> V_463 & V_611 ) )
return - V_580 ;
if ( ( V_609 -> V_463 & V_612 ) && ( V_368 & V_373 ) &&
V_2 -> V_5 . V_374 != ~ ( T_2 ) 0 )
return 0 ;
V_610 += 4 * V_609 -> V_607 ;
if ( ( V_609 -> V_463 & V_612 ) && V_610 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_609 -> V_463 & V_612 ) {
if ( ( V_2 -> V_5 . V_371 & V_613 ) ||
! F_45 ( V_2 , V_614 ) ) {
F_30 ( V_72 , V_2 ) ;
return 0 ;
}
if ( V_610 [ 1 ] & V_611 )
V_609 -> V_463 |= V_615 ;
V_610 [ 2 ] = V_609 -> V_616 ;
V_610 [ 3 ] = V_609 -> V_617 ;
V_2 -> V_5 . V_371 = V_609 -> V_371 ;
V_610 [ 1 ] = V_609 -> V_463 ;
F_32 ( V_2 , V_58 ) ;
} else if ( ! ( V_610 [ 1 ] & V_611 )
|| ! ( V_610 [ 1 ] & V_612 ) ) {
if ( V_610 [ 1 ] & V_611 )
V_609 -> V_463 |= V_615 ;
V_610 [ 2 ] = V_609 -> V_616 ;
V_610 [ 3 ] = V_609 -> V_617 ;
V_610 [ 1 ] = V_609 -> V_463 ;
} else
V_610 [ 1 ] |= V_615 ;
return 0 ;
}
static void F_267 ( struct V_1 * V_2 ,
struct V_618 * V_619 )
{
F_268 ( V_2 ) ;
V_619 -> V_68 . V_620 =
V_2 -> V_5 . V_68 . V_69 &&
! F_269 ( V_2 -> V_5 . V_68 . V_16 ) ;
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
V_619 -> V_632 . V_633 = F_270 ( V_2 ) ;
V_619 -> V_632 . V_69 = V_2 -> V_5 . V_634 ;
V_619 -> V_632 . V_635 =
! ! ( V_2 -> V_5 . V_636 & V_637 ) ;
V_619 -> V_632 . V_638 = F_271 ( V_2 ) ;
V_619 -> V_309 = ( V_639
| V_640
| V_641 ) ;
memset ( & V_619 -> V_642 , 0 , sizeof( V_619 -> V_642 ) ) ;
}
static int F_272 ( struct V_1 * V_2 ,
struct V_618 * V_619 )
{
if ( V_619 -> V_309 & ~ ( V_639
| V_643
| V_640
| V_641 ) )
return - V_580 ;
F_268 ( V_2 ) ;
V_2 -> V_5 . V_68 . V_69 = V_619 -> V_68 . V_620 ;
V_2 -> V_5 . V_68 . V_16 = V_619 -> V_68 . V_16 ;
V_2 -> V_5 . V_68 . V_71 = V_619 -> V_68 . V_71 ;
V_2 -> V_5 . V_68 . V_62 = V_619 -> V_68 . V_62 ;
V_2 -> V_5 . V_622 . V_69 = V_619 -> V_622 . V_620 ;
V_2 -> V_5 . V_622 . V_16 = V_619 -> V_622 . V_16 ;
V_2 -> V_5 . V_622 . V_623 = V_619 -> V_622 . V_623 ;
if ( V_619 -> V_309 & V_640 )
V_73 -> V_644 ( V_2 ,
V_619 -> V_622 . V_624 ) ;
V_2 -> V_5 . V_627 = V_619 -> V_626 . V_620 ;
if ( V_619 -> V_309 & V_639 )
V_2 -> V_5 . V_628 = V_619 -> V_626 . V_69 ;
V_73 -> V_645 ( V_2 , V_619 -> V_626 . V_629 ) ;
if ( V_619 -> V_309 & V_643 &&
F_273 ( V_2 ) )
V_2 -> V_5 . V_595 -> V_631 = V_619 -> V_631 ;
if ( V_619 -> V_309 & V_641 ) {
if ( V_619 -> V_632 . V_633 )
V_2 -> V_5 . V_636 |= V_646 ;
else
V_2 -> V_5 . V_636 &= ~ V_646 ;
V_2 -> V_5 . V_634 = V_619 -> V_632 . V_69 ;
if ( V_619 -> V_632 . V_635 )
V_2 -> V_5 . V_636 |= V_637 ;
else
V_2 -> V_5 . V_636 &= ~ V_637 ;
if ( F_273 ( V_2 ) ) {
if ( V_619 -> V_632 . V_638 )
F_212 ( V_647 , & V_2 -> V_5 . V_595 -> V_648 ) ;
else
F_176 ( V_647 , & V_2 -> V_5 . V_595 -> V_648 ) ;
}
}
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
static void F_274 ( struct V_1 * V_2 ,
struct V_649 * V_650 )
{
unsigned long V_194 ;
memcpy ( V_650 -> V_181 , V_2 -> V_5 . V_181 , sizeof( V_2 -> V_5 . V_181 ) ) ;
F_99 ( V_2 , 6 , & V_194 ) ;
V_650 -> V_185 = V_194 ;
V_650 -> V_186 = V_2 -> V_5 . V_186 ;
V_650 -> V_309 = 0 ;
memset ( & V_650 -> V_642 , 0 , sizeof( V_650 -> V_642 ) ) ;
}
static int F_275 ( struct V_1 * V_2 ,
struct V_649 * V_650 )
{
if ( V_650 -> V_309 )
return - V_580 ;
memcpy ( V_2 -> V_5 . V_181 , V_650 -> V_181 , sizeof( V_2 -> V_5 . V_181 ) ) ;
F_92 ( V_2 ) ;
V_2 -> V_5 . V_185 = V_650 -> V_185 ;
F_93 ( V_2 ) ;
V_2 -> V_5 . V_186 = V_650 -> V_186 ;
F_94 ( V_2 ) ;
return 0 ;
}
static void F_276 ( T_14 * V_651 , struct V_1 * V_2 )
{
struct V_652 * V_653 = & V_2 -> V_5 . V_654 . V_655 . V_653 ;
T_2 V_656 = V_653 -> V_657 . V_658 ;
T_2 V_659 ;
memcpy ( V_651 , V_653 , V_660 ) ;
* ( T_2 * ) ( V_651 + V_660 ) = V_656 ;
V_659 = V_656 & ~ V_661 ;
while ( V_659 ) {
T_2 V_662 = V_659 & - V_659 ;
int V_146 = F_277 ( V_662 ) - 1 ;
void * V_663 = F_278 ( V_653 , V_662 ) ;
if ( V_663 ) {
T_1 V_493 , V_94 , V_199 , V_207 ;
F_279 ( V_664 , V_146 ,
& V_493 , & V_94 , & V_199 , & V_207 ) ;
memcpy ( V_651 + V_94 , V_663 , V_493 ) ;
}
V_659 -= V_662 ;
}
}
static void F_280 ( struct V_1 * V_2 , T_14 * V_663 )
{
struct V_652 * V_653 = & V_2 -> V_5 . V_654 . V_655 . V_653 ;
T_2 V_656 = * ( T_2 * ) ( V_663 + V_660 ) ;
T_2 V_659 ;
memcpy ( V_653 , V_663 , V_660 ) ;
V_653 -> V_657 . V_658 = V_656 ;
if ( V_665 )
V_653 -> V_657 . V_666 = V_145 | V_667 ;
V_659 = V_656 & ~ V_661 ;
while ( V_659 ) {
T_2 V_662 = V_659 & - V_659 ;
int V_146 = F_277 ( V_662 ) - 1 ;
void * V_651 = F_278 ( V_653 , V_662 ) ;
if ( V_651 ) {
T_1 V_493 , V_94 , V_199 , V_207 ;
F_279 ( V_664 , V_146 ,
& V_493 , & V_94 , & V_199 , & V_207 ) ;
memcpy ( V_651 , V_663 + V_94 , V_493 ) ;
}
V_659 -= V_662 ;
}
}
static void F_281 ( struct V_1 * V_2 ,
struct V_668 * V_669 )
{
if ( V_556 ) {
memset ( V_669 , 0 , sizeof( struct V_668 ) ) ;
F_276 ( ( T_14 * ) V_669 -> V_670 , V_2 ) ;
} else {
memcpy ( V_669 -> V_670 ,
& V_2 -> V_5 . V_654 . V_655 . V_671 ,
sizeof( struct V_672 ) ) ;
* ( T_2 * ) & V_669 -> V_670 [ V_660 / sizeof( T_1 ) ] =
V_661 ;
}
}
static int F_282 ( struct V_1 * V_2 ,
struct V_668 * V_669 )
{
T_2 V_656 =
* ( T_2 * ) & V_669 -> V_670 [ V_660 / sizeof( T_1 ) ] ;
if ( V_556 ) {
if ( V_656 & ~ F_283 () )
return - V_580 ;
F_280 ( V_2 , ( T_14 * ) V_669 -> V_670 ) ;
} else {
if ( V_656 & ~ V_661 )
return - V_580 ;
memcpy ( & V_2 -> V_5 . V_654 . V_655 . V_671 ,
V_669 -> V_670 , sizeof( struct V_672 ) ) ;
}
return 0 ;
}
static void F_284 ( struct V_1 * V_2 ,
struct V_673 * V_674 )
{
if ( ! V_556 ) {
V_674 -> V_675 = 0 ;
return;
}
V_674 -> V_675 = 1 ;
V_674 -> V_309 = 0 ;
V_674 -> V_676 [ 0 ] . V_147 = V_143 ;
V_674 -> V_676 [ 0 ] . V_22 = V_2 -> V_5 . V_144 ;
}
static int F_285 ( struct V_1 * V_2 ,
struct V_673 * V_674 )
{
int V_3 , V_120 = 0 ;
if ( ! V_556 )
return - V_580 ;
if ( V_674 -> V_675 > V_677 || V_674 -> V_309 )
return - V_580 ;
for ( V_3 = 0 ; V_3 < V_674 -> V_675 ; V_3 ++ )
if ( V_674 -> V_676 [ V_3 ] . V_147 == V_143 ) {
V_120 = F_74 ( V_2 , V_143 ,
V_674 -> V_676 [ V_3 ] . V_22 ) ;
break;
}
if ( V_120 )
V_120 = - V_580 ;
return V_120 ;
}
static int F_286 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_349 )
return - V_580 ;
V_2 -> V_5 . V_357 = true ;
F_30 ( V_340 , V_2 ) ;
return 0 ;
}
static int F_287 ( struct V_1 * V_2 ,
struct V_678 * V_679 )
{
if ( V_679 -> V_309 )
return - V_580 ;
switch ( V_679 -> V_679 ) {
case V_521 :
return F_288 ( V_2 ) ;
default:
return - V_580 ;
}
}
long F_289 ( struct V_558 * V_559 ,
unsigned int V_560 , unsigned long V_561 )
{
struct V_1 * V_2 = V_559 -> V_680 ;
void T_15 * V_562 = ( void T_15 * ) V_561 ;
int V_120 ;
union {
struct V_590 * V_681 ;
struct V_668 * V_653 ;
struct V_673 * V_676 ;
void * V_682 ;
} V_683 ;
V_683 . V_682 = NULL ;
switch ( V_560 ) {
case V_684 : {
V_120 = - V_580 ;
if ( ! V_2 -> V_5 . V_595 )
goto V_113;
V_683 . V_681 = F_290 ( sizeof( struct V_590 ) , V_685 ) ;
V_120 = - V_389 ;
if ( ! V_683 . V_681 )
goto V_113;
V_120 = F_248 ( V_2 , V_683 . V_681 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_232 ( V_562 , V_683 . V_681 , sizeof( struct V_590 ) ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_686 : {
V_120 = - V_580 ;
if ( ! V_2 -> V_5 . V_595 )
goto V_113;
V_683 . V_681 = F_196 ( V_562 , sizeof( * V_683 . V_681 ) ) ;
if ( F_197 ( V_683 . V_681 ) )
return F_198 ( V_683 . V_681 ) ;
V_120 = F_249 ( V_2 , V_683 . V_681 ) ;
break;
}
case V_687 : {
struct V_596 V_597 ;
V_120 = - V_101 ;
if ( F_231 ( & V_597 , V_562 , sizeof V_597 ) )
goto V_113;
V_120 = F_258 ( V_2 , & V_597 ) ;
break;
}
case V_688 : {
V_120 = F_262 ( V_2 ) ;
break;
}
case V_689 : {
V_120 = F_263 ( V_2 ) ;
break;
}
case V_690 : {
struct V_691 T_15 * V_575 = V_562 ;
struct V_691 V_576 ;
V_120 = - V_101 ;
if ( F_231 ( & V_576 , V_575 , sizeof V_576 ) )
goto V_113;
V_120 = F_291 ( V_2 , & V_576 , V_575 -> V_486 ) ;
break;
}
case V_692 : {
struct V_574 T_15 * V_575 = V_562 ;
struct V_574 V_576 ;
V_120 = - V_101 ;
if ( F_231 ( & V_576 , V_575 , sizeof V_576 ) )
goto V_113;
V_120 = F_292 ( V_2 , & V_576 ,
V_575 -> V_486 ) ;
break;
}
case V_693 : {
struct V_574 T_15 * V_575 = V_562 ;
struct V_574 V_576 ;
V_120 = - V_101 ;
if ( F_231 ( & V_576 , V_575 , sizeof V_576 ) )
goto V_113;
V_120 = F_293 ( V_2 , & V_576 ,
V_575 -> V_486 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_232 ( V_575 , & V_576 , sizeof V_576 ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_694 :
V_120 = F_230 ( V_2 , V_562 , F_112 , 1 ) ;
break;
case V_695 :
V_120 = F_230 ( V_2 , V_562 , F_114 , 0 ) ;
break;
case V_696 : {
struct V_603 V_604 ;
V_120 = - V_101 ;
if ( F_231 ( & V_604 , V_562 , sizeof V_604 ) )
goto V_113;
V_120 = F_264 ( V_2 , & V_604 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_232 ( V_562 , & V_604 , sizeof V_604 ) )
goto V_113;
V_120 = 0 ;
break;
} ;
case V_697 : {
struct V_698 V_699 ;
V_120 = - V_580 ;
if ( ! F_88 ( V_2 ) )
goto V_113;
V_120 = - V_101 ;
if ( F_231 ( & V_699 , V_562 , sizeof V_699 ) )
goto V_113;
V_120 = F_294 ( V_2 , V_699 . V_700 ) ;
break;
}
case V_701 : {
T_2 V_368 ;
V_120 = - V_101 ;
if ( F_231 ( & V_368 , V_562 , sizeof V_368 ) )
goto V_113;
V_120 = F_265 ( V_2 , V_368 ) ;
break;
}
case V_702 : {
struct V_608 V_609 ;
V_120 = - V_101 ;
if ( F_231 ( & V_609 , V_562 , sizeof V_609 ) )
goto V_113;
V_120 = F_266 ( V_2 , & V_609 ) ;
break;
}
case V_703 : {
struct V_618 V_619 ;
F_267 ( V_2 , & V_619 ) ;
V_120 = - V_101 ;
if ( F_232 ( V_562 , & V_619 , sizeof( struct V_618 ) ) )
break;
V_120 = 0 ;
break;
}
case V_704 : {
struct V_618 V_619 ;
V_120 = - V_101 ;
if ( F_231 ( & V_619 , V_562 , sizeof( struct V_618 ) ) )
break;
V_120 = F_272 ( V_2 , & V_619 ) ;
break;
}
case V_705 : {
struct V_649 V_650 ;
F_274 ( V_2 , & V_650 ) ;
V_120 = - V_101 ;
if ( F_232 ( V_562 , & V_650 ,
sizeof( struct V_649 ) ) )
break;
V_120 = 0 ;
break;
}
case V_706 : {
struct V_649 V_650 ;
V_120 = - V_101 ;
if ( F_231 ( & V_650 , V_562 ,
sizeof( struct V_649 ) ) )
break;
V_120 = F_275 ( V_2 , & V_650 ) ;
break;
}
case V_707 : {
V_683 . V_653 = F_290 ( sizeof( struct V_668 ) , V_685 ) ;
V_120 = - V_389 ;
if ( ! V_683 . V_653 )
break;
F_281 ( V_2 , V_683 . V_653 ) ;
V_120 = - V_101 ;
if ( F_232 ( V_562 , V_683 . V_653 , sizeof( struct V_668 ) ) )
break;
V_120 = 0 ;
break;
}
case V_708 : {
V_683 . V_653 = F_196 ( V_562 , sizeof( * V_683 . V_653 ) ) ;
if ( F_197 ( V_683 . V_653 ) )
return F_198 ( V_683 . V_653 ) ;
V_120 = F_282 ( V_2 , V_683 . V_653 ) ;
break;
}
case V_709 : {
V_683 . V_676 = F_290 ( sizeof( struct V_673 ) , V_685 ) ;
V_120 = - V_389 ;
if ( ! V_683 . V_676 )
break;
F_284 ( V_2 , V_683 . V_676 ) ;
V_120 = - V_101 ;
if ( F_232 ( V_562 , V_683 . V_676 ,
sizeof( struct V_673 ) ) )
break;
V_120 = 0 ;
break;
}
case V_710 : {
V_683 . V_676 = F_196 ( V_562 , sizeof( * V_683 . V_676 ) ) ;
if ( F_197 ( V_683 . V_676 ) )
return F_198 ( V_683 . V_676 ) ;
V_120 = F_285 ( V_2 , V_683 . V_676 ) ;
break;
}
case V_711 : {
T_1 V_268 ;
V_120 = - V_580 ;
V_268 = ( T_1 ) V_561 ;
if ( V_268 >= V_712 )
goto V_113;
if ( V_268 == 0 )
V_268 = V_274 ;
if ( ! F_138 ( V_2 , V_268 ) )
V_120 = 0 ;
goto V_113;
}
case V_713 : {
V_120 = V_2 -> V_5 . V_284 ;
goto V_113;
}
case V_714 : {
V_120 = F_286 ( V_2 ) ;
goto V_113;
}
case V_715 : {
struct V_678 V_679 ;
V_120 = - V_101 ;
if ( F_231 ( & V_679 , V_562 , sizeof( V_679 ) ) )
goto V_113;
V_120 = F_287 ( V_2 , & V_679 ) ;
break;
}
default:
V_120 = - V_580 ;
}
V_113:
F_200 ( V_683 . V_682 ) ;
return V_120 ;
}
int F_295 ( struct V_1 * V_2 , struct V_716 * V_717 )
{
return V_718 ;
}
static int F_296 ( struct V_138 * V_138 , unsigned long V_616 )
{
int V_108 ;
if ( V_616 > ( unsigned int ) ( - 3 * V_107 ) )
return - V_580 ;
V_108 = V_73 -> V_719 ( V_138 , V_616 ) ;
return V_108 ;
}
static int F_297 ( struct V_138 * V_138 ,
T_2 V_720 )
{
V_138 -> V_5 . V_721 = V_720 ;
return 0 ;
}
static int F_298 ( struct V_138 * V_138 ,
T_1 V_722 )
{
if ( V_722 < V_723 )
return - V_580 ;
F_299 ( & V_138 -> V_724 ) ;
F_300 ( V_138 , V_722 ) ;
V_138 -> V_5 . V_725 = V_722 ;
F_301 ( & V_138 -> V_724 ) ;
return 0 ;
}
static int F_302 ( struct V_138 * V_138 )
{
return V_138 -> V_5 . V_726 ;
}
static int F_303 ( struct V_138 * V_138 , struct V_727 * V_728 )
{
int V_120 ;
V_120 = 0 ;
switch ( V_728 -> V_729 ) {
case V_730 :
memcpy ( & V_728 -> V_728 . V_731 ,
& F_304 ( V_138 ) -> V_732 [ 0 ] ,
sizeof( struct V_733 ) ) ;
break;
case V_734 :
memcpy ( & V_728 -> V_728 . V_731 ,
& F_304 ( V_138 ) -> V_732 [ 1 ] ,
sizeof( struct V_733 ) ) ;
break;
case V_735 :
V_120 = F_305 ( V_138 , & V_728 -> V_728 . V_736 ) ;
break;
default:
V_120 = - V_580 ;
break;
}
return V_120 ;
}
static int F_306 ( struct V_138 * V_138 , struct V_727 * V_728 )
{
int V_120 ;
V_120 = 0 ;
switch ( V_728 -> V_729 ) {
case V_730 :
F_156 ( & F_304 ( V_138 ) -> V_737 ) ;
memcpy ( & F_304 ( V_138 ) -> V_732 [ 0 ] ,
& V_728 -> V_728 . V_731 ,
sizeof( struct V_733 ) ) ;
F_157 ( & F_304 ( V_138 ) -> V_737 ) ;
break;
case V_734 :
F_156 ( & F_304 ( V_138 ) -> V_737 ) ;
memcpy ( & F_304 ( V_138 ) -> V_732 [ 1 ] ,
& V_728 -> V_728 . V_731 ,
sizeof( struct V_733 ) ) ;
F_157 ( & F_304 ( V_138 ) -> V_737 ) ;
break;
case V_735 :
V_120 = F_307 ( V_138 , & V_728 -> V_728 . V_736 ) ;
break;
default:
V_120 = - V_580 ;
break;
}
F_308 ( F_304 ( V_138 ) ) ;
return V_120 ;
}
static int F_309 ( struct V_138 * V_138 , struct V_738 * V_739 )
{
F_299 ( & V_138 -> V_5 . V_740 -> V_741 . V_737 ) ;
memcpy ( V_739 , & V_138 -> V_5 . V_740 -> V_741 , sizeof( struct V_738 ) ) ;
F_301 ( & V_138 -> V_5 . V_740 -> V_741 . V_737 ) ;
return 0 ;
}
static int F_310 ( struct V_138 * V_138 , struct V_738 * V_739 )
{
int V_3 ;
F_299 ( & V_138 -> V_5 . V_740 -> V_741 . V_737 ) ;
memcpy ( & V_138 -> V_5 . V_740 -> V_741 , V_739 , sizeof( struct V_738 ) ) ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
F_311 ( V_138 , V_3 , V_739 -> V_742 [ V_3 ] . V_743 , 0 ) ;
F_301 ( & V_138 -> V_5 . V_740 -> V_741 . V_737 ) ;
return 0 ;
}
static int F_312 ( struct V_138 * V_138 , struct V_744 * V_739 )
{
F_299 ( & V_138 -> V_5 . V_740 -> V_741 . V_737 ) ;
memcpy ( V_739 -> V_742 , & V_138 -> V_5 . V_740 -> V_741 . V_742 ,
sizeof( V_739 -> V_742 ) ) ;
V_739 -> V_309 = V_138 -> V_5 . V_740 -> V_741 . V_309 ;
F_301 ( & V_138 -> V_5 . V_740 -> V_741 . V_737 ) ;
memset ( & V_739 -> V_642 , 0 , sizeof( V_739 -> V_642 ) ) ;
return 0 ;
}
static int F_313 ( struct V_138 * V_138 , struct V_744 * V_739 )
{
int V_745 = 0 ;
int V_3 ;
T_1 V_746 , V_747 ;
F_299 ( & V_138 -> V_5 . V_740 -> V_741 . V_737 ) ;
V_746 = V_138 -> V_5 . V_740 -> V_741 . V_309 & V_748 ;
V_747 = V_739 -> V_309 & V_748 ;
if ( ! V_746 && V_747 )
V_745 = 1 ;
memcpy ( & V_138 -> V_5 . V_740 -> V_741 . V_742 , & V_739 -> V_742 ,
sizeof( V_138 -> V_5 . V_740 -> V_741 . V_742 ) ) ;
V_138 -> V_5 . V_740 -> V_741 . V_309 = V_739 -> V_309 ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
F_311 ( V_138 , V_3 , V_138 -> V_5 . V_740 -> V_741 . V_742 [ V_3 ] . V_743 ,
V_745 && V_3 == 0 ) ;
F_301 ( & V_138 -> V_5 . V_740 -> V_741 . V_737 ) ;
return 0 ;
}
static int F_314 ( struct V_138 * V_138 ,
struct V_749 * V_750 )
{
if ( ! V_138 -> V_5 . V_740 )
return - V_599 ;
F_299 ( & V_138 -> V_5 . V_740 -> V_741 . V_737 ) ;
V_138 -> V_5 . V_740 -> V_741 . V_63 = V_750 -> V_751 ;
F_301 ( & V_138 -> V_5 . V_740 -> V_741 . V_737 ) ;
return 0 ;
}
int F_315 ( struct V_138 * V_138 , struct V_752 * log )
{
bool V_753 = false ;
int V_120 ;
F_299 ( & V_138 -> V_724 ) ;
if ( V_73 -> V_754 )
V_73 -> V_754 ( V_138 ) ;
V_120 = F_316 ( V_138 , log , & V_753 ) ;
F_317 ( & V_138 -> V_724 ) ;
if ( V_753 )
F_318 ( V_138 ) ;
F_301 ( & V_138 -> V_724 ) ;
return V_120 ;
}
int F_319 ( struct V_138 * V_138 , struct V_755 * V_756 ,
bool V_757 )
{
if ( ! F_259 ( V_138 ) )
return - V_599 ;
V_756 -> V_463 = F_320 ( V_138 , V_758 ,
V_756 -> V_597 , V_756 -> V_759 ,
V_757 ) ;
return 0 ;
}
static int F_321 ( struct V_138 * V_138 ,
struct V_678 * V_679 )
{
int V_120 ;
if ( V_679 -> V_309 )
return - V_580 ;
switch ( V_679 -> V_679 ) {
case V_534 :
V_138 -> V_5 . V_760 = V_679 -> args [ 0 ] ;
V_120 = 0 ;
break;
case V_536 : {
F_299 ( & V_138 -> V_737 ) ;
V_120 = - V_580 ;
if ( V_679 -> args [ 0 ] > V_761 )
goto V_762;
V_120 = - V_601 ;
if ( F_259 ( V_138 ) )
goto V_762;
if ( F_141 ( & V_138 -> V_295 ) )
goto V_762;
V_120 = F_322 ( V_138 ) ;
if ( V_120 )
goto V_762;
F_185 () ;
V_138 -> V_5 . V_763 = true ;
V_138 -> V_5 . V_764 = V_679 -> args [ 0 ] ;
V_120 = 0 ;
V_762:
F_301 ( & V_138 -> V_737 ) ;
break;
}
default:
V_120 = - V_580 ;
break;
}
return V_120 ;
}
long F_323 ( struct V_558 * V_559 ,
unsigned int V_560 , unsigned long V_561 )
{
struct V_138 * V_138 = V_559 -> V_680 ;
void T_15 * V_562 = ( void T_15 * ) V_561 ;
int V_120 = - V_765 ;
union {
struct V_738 V_739 ;
struct V_744 V_766 ;
struct V_767 V_768 ;
} V_683 ;
switch ( V_560 ) {
case V_769 :
V_120 = F_296 ( V_138 , V_561 ) ;
break;
case V_770 : {
T_2 V_720 ;
V_120 = - V_101 ;
if ( F_231 ( & V_720 , V_562 , sizeof V_720 ) )
goto V_113;
V_120 = F_297 ( V_138 , V_720 ) ;
break;
}
case V_771 :
V_120 = F_298 ( V_138 , V_561 ) ;
break;
case V_772 :
V_120 = F_302 ( V_138 ) ;
break;
case V_773 : {
struct V_774 * V_775 ;
F_299 ( & V_138 -> V_737 ) ;
V_120 = - V_601 ;
if ( V_138 -> V_5 . V_775 )
goto V_776;
V_120 = - V_580 ;
if ( F_141 ( & V_138 -> V_295 ) )
goto V_776;
V_120 = - V_389 ;
V_775 = F_324 ( V_138 ) ;
if ( V_775 ) {
V_120 = F_325 ( V_138 ) ;
if ( V_120 ) {
F_299 ( & V_138 -> V_724 ) ;
F_326 ( V_775 ) ;
F_301 ( & V_138 -> V_724 ) ;
goto V_776;
}
} else
goto V_776;
V_120 = F_327 ( V_138 ) ;
if ( V_120 ) {
F_299 ( & V_138 -> V_724 ) ;
F_299 ( & V_138 -> V_777 ) ;
F_328 ( V_138 ) ;
F_326 ( V_775 ) ;
F_301 ( & V_138 -> V_777 ) ;
F_301 ( & V_138 -> V_724 ) ;
goto V_776;
}
F_185 () ;
V_138 -> V_5 . V_775 = V_775 ;
V_776:
F_301 ( & V_138 -> V_737 ) ;
break;
}
case V_778 :
V_683 . V_768 . V_309 = V_779 ;
goto V_780;
case V_781 :
V_120 = - V_101 ;
if ( F_231 ( & V_683 . V_768 , V_562 ,
sizeof( struct V_767 ) ) )
goto V_113;
V_780:
F_299 ( & V_138 -> V_724 ) ;
V_120 = - V_601 ;
if ( V_138 -> V_5 . V_740 )
goto V_782;
V_120 = - V_389 ;
V_138 -> V_5 . V_740 = F_329 ( V_138 , V_683 . V_768 . V_309 ) ;
if ( V_138 -> V_5 . V_740 )
V_120 = 0 ;
V_782:
F_301 ( & V_138 -> V_724 ) ;
break;
case V_783 : {
struct V_727 * V_728 ;
V_728 = F_196 ( V_562 , sizeof( * V_728 ) ) ;
if ( F_197 ( V_728 ) ) {
V_120 = F_198 ( V_728 ) ;
goto V_113;
}
V_120 = - V_599 ;
if ( ! F_259 ( V_138 ) || V_763 ( V_138 ) )
goto V_784;
V_120 = F_303 ( V_138 , V_728 ) ;
if ( V_120 )
goto V_784;
V_120 = - V_101 ;
if ( F_232 ( V_562 , V_728 , sizeof *V_728 ) )
goto V_784;
V_120 = 0 ;
V_784:
F_200 ( V_728 ) ;
break;
}
case V_785 : {
struct V_727 * V_728 ;
V_728 = F_196 ( V_562 , sizeof( * V_728 ) ) ;
if ( F_197 ( V_728 ) ) {
V_120 = F_198 ( V_728 ) ;
goto V_113;
}
V_120 = - V_599 ;
if ( ! F_259 ( V_138 ) || V_763 ( V_138 ) )
goto V_786;
V_120 = F_306 ( V_138 , V_728 ) ;
if ( V_120 )
goto V_786;
V_120 = 0 ;
V_786:
F_200 ( V_728 ) ;
break;
}
case V_787 : {
V_120 = - V_101 ;
if ( F_231 ( & V_683 . V_739 , V_562 , sizeof( struct V_738 ) ) )
goto V_113;
V_120 = - V_599 ;
if ( ! V_138 -> V_5 . V_740 )
goto V_113;
V_120 = F_309 ( V_138 , & V_683 . V_739 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_232 ( V_562 , & V_683 . V_739 , sizeof( struct V_738 ) ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_788 : {
V_120 = - V_101 ;
if ( F_231 ( & V_683 . V_739 , V_562 , sizeof V_683 . V_739 ) )
goto V_113;
V_120 = - V_599 ;
if ( ! V_138 -> V_5 . V_740 )
goto V_113;
V_120 = F_310 ( V_138 , & V_683 . V_739 ) ;
break;
}
case V_789 : {
V_120 = - V_599 ;
if ( ! V_138 -> V_5 . V_740 )
goto V_113;
V_120 = F_312 ( V_138 , & V_683 . V_766 ) ;
if ( V_120 )
goto V_113;
V_120 = - V_101 ;
if ( F_232 ( V_562 , & V_683 . V_766 , sizeof( V_683 . V_766 ) ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_790 : {
V_120 = - V_101 ;
if ( F_231 ( & V_683 . V_766 , V_562 , sizeof( V_683 . V_766 ) ) )
goto V_113;
V_120 = - V_599 ;
if ( ! V_138 -> V_5 . V_740 )
goto V_113;
V_120 = F_313 ( V_138 , & V_683 . V_766 ) ;
break;
}
case V_791 : {
struct V_749 V_750 ;
V_120 = - V_101 ;
if ( F_231 ( & V_750 , V_562 , sizeof( V_750 ) ) )
goto V_113;
V_120 = F_314 ( V_138 , & V_750 ) ;
break;
}
case V_792 :
V_120 = 0 ;
F_299 ( & V_138 -> V_737 ) ;
if ( F_141 ( & V_138 -> V_295 ) != 0 )
V_120 = - V_793 ;
else
V_138 -> V_5 . V_794 = V_561 ;
F_301 ( & V_138 -> V_737 ) ;
break;
case V_795 : {
V_120 = - V_101 ;
if ( F_231 ( & V_138 -> V_5 . F_195 , V_562 ,
sizeof( struct V_796 ) ) )
goto V_113;
V_120 = - V_580 ;
if ( V_138 -> V_5 . F_195 . V_309 )
goto V_113;
V_120 = 0 ;
break;
}
case V_797 : {
struct V_798 V_799 ;
T_2 V_800 ;
T_12 V_320 ;
V_120 = - V_101 ;
if ( F_231 ( & V_799 , V_562 , sizeof( V_799 ) ) )
goto V_113;
V_120 = - V_580 ;
if ( V_799 . V_309 )
goto V_113;
V_120 = 0 ;
F_330 () ;
V_800 = F_152 () ;
V_320 = V_799 . clock - V_800 ;
F_331 () ;
V_138 -> V_5 . V_245 = V_320 ;
F_174 ( V_138 ) ;
break;
}
case V_801 : {
struct V_798 V_799 ;
T_2 V_800 ;
F_330 () ;
V_800 = F_152 () ;
V_799 . clock = V_138 -> V_5 . V_245 + V_800 ;
F_331 () ;
V_799 . V_309 = 0 ;
memset ( & V_799 . V_621 , 0 , sizeof( V_799 . V_621 ) ) ;
V_120 = - V_101 ;
if ( F_232 ( V_562 , & V_799 , sizeof( V_799 ) ) )
goto V_113;
V_120 = 0 ;
break;
}
case V_715 : {
struct V_678 V_679 ;
V_120 = - V_101 ;
if ( F_231 ( & V_679 , V_562 , sizeof( V_679 ) ) )
goto V_113;
V_120 = F_321 ( V_138 , & V_679 ) ;
break;
}
default:
V_120 = F_332 ( V_138 , V_560 , V_561 ) ;
}
V_113:
return V_120 ;
}
static void F_333 ( void )
{
T_1 V_802 [ 2 ] ;
unsigned V_3 , V_803 ;
for ( V_3 = V_803 = 0 ; V_3 < F_52 ( V_570 ) ; V_3 ++ ) {
if ( F_334 ( V_570 [ V_3 ] , & V_802 [ 0 ] , & V_802 [ 1 ] ) < 0 )
continue;
switch ( V_570 [ V_3 ] ) {
case V_804 :
if ( ! V_73 -> V_805 () )
continue;
break;
case V_806 :
if ( ! V_73 -> V_807 () )
continue;
break;
default:
break;
}
if ( V_803 < V_3 )
V_570 [ V_803 ] = V_570 [ V_3 ] ;
V_803 ++ ;
}
V_567 = V_803 ;
for ( V_3 = V_803 = 0 ; V_3 < F_52 ( V_571 ) ; V_3 ++ ) {
switch ( V_571 [ V_3 ] ) {
case V_426 :
if ( ! V_73 -> V_540 () )
continue;
break;
default:
break;
}
if ( V_803 < V_3 )
V_571 [ V_803 ] = V_571 [ V_3 ] ;
V_803 ++ ;
}
V_568 = V_803 ;
}
static int F_335 ( struct V_1 * V_2 , T_6 V_616 , int V_95 ,
const void * V_267 )
{
int V_808 = 0 ;
int V_492 ;
do {
V_492 = F_336 ( V_95 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_595 &&
! F_337 ( V_2 , & V_2 -> V_5 . V_595 -> V_809 , V_616 , V_492 , V_267 ) )
&& F_338 ( V_2 , V_810 , V_616 , V_492 , V_267 ) )
break;
V_808 += V_492 ;
V_616 += V_492 ;
V_95 -= V_492 ;
V_267 += V_492 ;
} while ( V_95 );
return V_808 ;
}
static int F_339 ( struct V_1 * V_2 , T_6 V_616 , int V_95 , void * V_267 )
{
int V_808 = 0 ;
int V_492 ;
do {
V_492 = F_336 ( V_95 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_595 &&
! F_340 ( V_2 , & V_2 -> V_5 . V_595 -> V_809 ,
V_616 , V_492 , V_267 ) )
&& F_341 ( V_2 , V_810 , V_616 , V_492 , V_267 ) )
break;
F_342 ( V_811 , V_492 , V_616 , * ( T_2 * ) V_267 ) ;
V_808 += V_492 ;
V_616 += V_492 ;
V_95 -= V_492 ;
V_267 += V_492 ;
} while ( V_95 );
return V_808 ;
}
static void F_343 ( struct V_1 * V_2 ,
struct V_812 * V_813 , int V_814 )
{
V_73 -> V_815 ( V_2 , V_813 , V_814 ) ;
}
void F_344 ( struct V_1 * V_2 ,
struct V_812 * V_813 , int V_814 )
{
V_73 -> V_816 ( V_2 , V_813 , V_814 ) ;
}
T_6 F_345 ( struct V_1 * V_2 , T_6 V_391 , T_1 V_96 ,
struct V_75 * V_68 )
{
T_6 V_817 ;
F_13 ( ! F_39 ( V_2 ) ) ;
V_96 |= V_111 ;
V_817 = V_2 -> V_5 . V_84 . V_818 ( V_2 , V_391 , V_96 , V_68 ) ;
return V_817 ;
}
T_6 F_346 ( struct V_1 * V_2 , T_16 V_819 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
return V_2 -> V_5 . V_103 -> V_818 ( V_2 , V_819 , V_96 , V_68 ) ;
}
T_6 F_347 ( struct V_1 * V_2 , T_16 V_819 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
V_96 |= V_820 ;
return V_2 -> V_5 . V_103 -> V_818 ( V_2 , V_819 , V_96 , V_68 ) ;
}
T_6 F_348 ( struct V_1 * V_2 , T_16 V_819 ,
struct V_75 * V_68 )
{
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
V_96 |= V_112 ;
return V_2 -> V_5 . V_103 -> V_818 ( V_2 , V_819 , V_96 , V_68 ) ;
}
T_6 F_349 ( struct V_1 * V_2 , T_16 V_819 ,
struct V_75 * V_68 )
{
return V_2 -> V_5 . V_103 -> V_818 ( V_2 , V_819 , 0 , V_68 ) ;
}
static int F_350 ( T_16 V_616 , void * V_194 , unsigned int V_821 ,
struct V_1 * V_2 , T_1 V_96 ,
struct V_75 * V_68 )
{
void * V_38 = V_194 ;
int V_120 = V_822 ;
while ( V_821 ) {
T_6 V_391 = V_2 -> V_5 . V_103 -> V_818 ( V_2 , V_616 , V_96 ,
V_68 ) ;
unsigned V_94 = V_616 & ( V_107 - 1 ) ;
unsigned V_823 = F_336 ( V_821 , ( unsigned ) V_107 - V_94 ) ;
int V_108 ;
if ( V_391 == V_100 )
return V_824 ;
V_108 = F_49 ( V_2 , V_391 >> V_106 , V_38 ,
V_94 , V_823 ) ;
if ( V_108 < 0 ) {
V_120 = V_825 ;
goto V_113;
}
V_821 -= V_823 ;
V_38 += V_823 ;
V_616 += V_823 ;
}
V_113:
return V_120 ;
}
static int F_351 ( struct V_826 * V_827 ,
T_16 V_616 , void * V_194 , unsigned int V_821 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_352 ( V_827 ) ;
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
unsigned V_94 ;
int V_108 ;
T_6 V_391 = V_2 -> V_5 . V_103 -> V_818 ( V_2 , V_616 , V_96 | V_820 ,
V_68 ) ;
if ( F_166 ( V_391 == V_100 ) )
return V_824 ;
V_94 = V_616 & ( V_107 - 1 ) ;
if ( F_28 ( V_94 + V_821 > V_107 ) )
V_821 = ( unsigned ) V_107 - V_94 ;
V_108 = F_49 ( V_2 , V_391 >> V_106 , V_194 ,
V_94 , V_821 ) ;
if ( F_166 ( V_108 < 0 ) )
return V_825 ;
return V_822 ;
}
int F_353 ( struct V_826 * V_827 ,
T_16 V_616 , void * V_194 , unsigned int V_821 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_352 ( V_827 ) ;
T_1 V_96 = ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
return F_350 ( V_616 , V_194 , V_821 , V_2 , V_96 ,
V_68 ) ;
}
static int F_354 ( struct V_826 * V_827 ,
T_16 V_616 , void * V_194 , unsigned int V_821 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_352 ( V_827 ) ;
return F_350 ( V_616 , V_194 , V_821 , V_2 , 0 , V_68 ) ;
}
static int F_355 ( struct V_826 * V_827 ,
unsigned long V_616 , void * V_194 , unsigned int V_821 )
{
struct V_1 * V_2 = F_352 ( V_827 ) ;
int V_120 = F_356 ( V_2 , V_616 , V_194 , V_821 ) ;
return V_120 < 0 ? V_825 : V_822 ;
}
int F_357 ( struct V_826 * V_827 ,
T_16 V_616 , void * V_194 ,
unsigned int V_821 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_352 ( V_827 ) ;
void * V_38 = V_194 ;
int V_120 = V_822 ;
while ( V_821 ) {
T_6 V_391 = V_2 -> V_5 . V_103 -> V_818 ( V_2 , V_616 ,
V_112 ,
V_68 ) ;
unsigned V_94 = V_616 & ( V_107 - 1 ) ;
unsigned V_828 = F_336 ( V_821 , ( unsigned ) V_107 - V_94 ) ;
int V_108 ;
if ( V_391 == V_100 )
return V_824 ;
V_108 = F_199 ( V_2 , V_391 , V_38 , V_828 ) ;
if ( V_108 < 0 ) {
V_120 = V_825 ;
goto V_113;
}
V_821 -= V_828 ;
V_38 += V_828 ;
V_616 += V_828 ;
}
V_113:
return V_120 ;
}
static int F_358 ( struct V_1 * V_2 , unsigned long V_819 ,
T_6 * V_391 , struct V_75 * V_68 ,
bool V_829 )
{
T_1 V_96 = ( ( V_73 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 )
| ( V_829 ? V_112 : 0 ) ;
if ( F_359 ( V_2 , V_819 )
&& ! F_360 ( V_2 , V_2 -> V_5 . V_103 ,
V_2 -> V_5 . V_96 , V_96 ) ) {
* V_391 = V_2 -> V_5 . V_830 << V_106 |
( V_819 & ( V_107 - 1 ) ) ;
F_361 ( V_819 , * V_391 , V_829 , false ) ;
return 1 ;
}
* V_391 = V_2 -> V_5 . V_103 -> V_818 ( V_2 , V_819 , V_96 , V_68 ) ;
if ( * V_391 == V_100 )
return - 1 ;
if ( ( * V_391 & V_385 ) == V_831 )
return 1 ;
if ( F_362 ( V_2 , * V_391 ) ) {
F_361 ( V_819 , * V_391 , V_829 , true ) ;
return 1 ;
}
return 0 ;
}
int F_363 ( struct V_1 * V_2 , T_6 V_391 ,
const void * V_194 , int V_821 )
{
int V_108 ;
V_108 = F_199 ( V_2 , V_391 , V_194 , V_821 ) ;
if ( V_108 < 0 )
return 0 ;
F_364 ( V_2 , V_391 , V_194 , V_821 ) ;
return 1 ;
}
static int F_365 ( struct V_1 * V_2 , void * V_194 , int V_821 )
{
if ( V_2 -> V_832 ) {
F_342 ( V_811 , V_821 ,
V_2 -> V_833 [ 0 ] . V_391 , * ( T_2 * ) V_194 ) ;
V_2 -> V_832 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_366 ( struct V_1 * V_2 , T_6 V_391 ,
void * V_194 , int V_821 )
{
return ! F_356 ( V_2 , V_391 , V_194 , V_821 ) ;
}
static int F_367 ( struct V_1 * V_2 , T_6 V_391 ,
void * V_194 , int V_821 )
{
return F_363 ( V_2 , V_391 , V_194 , V_821 ) ;
}
static int F_368 ( struct V_1 * V_2 , T_6 V_391 , int V_821 , void * V_194 )
{
F_342 ( V_834 , V_821 , V_391 , * ( T_2 * ) V_194 ) ;
return F_335 ( V_2 , V_391 , V_821 , V_194 ) ;
}
static int F_369 ( struct V_1 * V_2 , T_6 V_391 ,
void * V_194 , int V_821 )
{
F_342 ( V_835 , V_821 , V_391 , 0 ) ;
return V_825 ;
}
static int F_370 ( struct V_1 * V_2 , T_6 V_391 ,
void * V_194 , int V_821 )
{
struct V_836 * V_837 = & V_2 -> V_833 [ 0 ] ;
memcpy ( V_2 -> V_838 -> V_839 . V_38 , V_837 -> V_38 , F_336 ( 8u , V_837 -> V_95 ) ) ;
return V_822 ;
}
static int F_371 ( unsigned long V_616 , void * V_194 ,
unsigned int V_821 ,
struct V_75 * V_68 ,
struct V_1 * V_2 ,
const struct V_840 * V_841 )
{
T_6 V_391 ;
int V_808 , V_108 ;
bool V_829 = V_841 -> V_829 ;
struct V_836 * V_837 ;
V_108 = F_358 ( V_2 , V_616 , & V_391 , V_68 , V_829 ) ;
if ( V_108 < 0 )
return V_824 ;
if ( V_108 )
goto V_839;
if ( V_841 -> V_842 ( V_2 , V_391 , V_194 , V_821 ) )
return V_822 ;
V_839:
V_808 = V_841 -> V_843 ( V_2 , V_391 , V_821 , V_194 ) ;
if ( V_808 == V_821 )
return V_822 ;
V_391 += V_808 ;
V_821 -= V_808 ;
V_194 += V_808 ;
F_28 ( V_2 -> V_844 >= V_845 ) ;
V_837 = & V_2 -> V_833 [ V_2 -> V_844 ++ ] ;
V_837 -> V_391 = V_391 ;
V_837 -> V_38 = V_194 ;
V_837 -> V_95 = V_821 ;
return V_822 ;
}
static int F_372 ( struct V_826 * V_827 ,
unsigned long V_616 ,
void * V_194 , unsigned int V_821 ,
struct V_75 * V_68 ,
const struct V_840 * V_841 )
{
struct V_1 * V_2 = F_352 ( V_827 ) ;
T_6 V_391 ;
int V_846 ;
if ( V_841 -> V_847 &&
V_841 -> V_847 ( V_2 , V_194 , V_821 ) )
return V_822 ;
V_2 -> V_844 = 0 ;
if ( ( ( V_616 + V_821 - 1 ) ^ V_616 ) & V_385 ) {
int V_848 ;
V_848 = - V_616 & ~ V_385 ;
V_846 = F_371 ( V_616 , V_194 , V_848 , V_68 ,
V_2 , V_841 ) ;
if ( V_846 != V_822 )
return V_846 ;
V_616 += V_848 ;
if ( V_827 -> V_332 != V_849 )
V_616 = ( T_1 ) V_616 ;
V_194 += V_848 ;
V_821 -= V_848 ;
}
V_846 = F_371 ( V_616 , V_194 , V_821 , V_68 ,
V_2 , V_841 ) ;
if ( V_846 != V_822 )
return V_846 ;
if ( ! V_2 -> V_844 )
return V_846 ;
V_391 = V_2 -> V_833 [ 0 ] . V_391 ;
V_2 -> V_850 = 1 ;
V_2 -> V_851 = 0 ;
V_2 -> V_838 -> V_839 . V_95 = F_336 ( 8u , V_2 -> V_833 [ 0 ] . V_95 ) ;
V_2 -> V_838 -> V_839 . V_852 = V_2 -> V_853 = V_841 -> V_829 ;
V_2 -> V_838 -> V_854 = V_855 ;
V_2 -> V_838 -> V_839 . V_856 = V_391 ;
return V_841 -> V_857 ( V_2 , V_391 , V_194 , V_821 ) ;
}
static int F_373 ( struct V_826 * V_827 ,
unsigned long V_616 ,
void * V_194 ,
unsigned int V_821 ,
struct V_75 * V_68 )
{
return F_372 ( V_827 , V_616 , V_194 , V_821 ,
V_68 , & V_858 ) ;
}
static int F_374 ( struct V_826 * V_827 ,
unsigned long V_616 ,
const void * V_194 ,
unsigned int V_821 ,
struct V_75 * V_68 )
{
return F_372 ( V_827 , V_616 , ( void * ) V_194 , V_821 ,
V_68 , & V_859 ) ;
}
static int F_375 ( struct V_826 * V_827 ,
unsigned long V_616 ,
const void * V_860 ,
const void * V_861 ,
unsigned int V_821 ,
struct V_75 * V_68 )
{
struct V_1 * V_2 = F_352 ( V_827 ) ;
T_6 V_391 ;
struct V_387 * V_387 ;
char * V_862 ;
bool V_863 ;
if ( V_821 > 8 || ( V_821 & ( V_821 - 1 ) ) )
goto V_864;
V_391 = F_348 ( V_2 , V_616 , NULL ) ;
if ( V_391 == V_100 ||
( V_391 & V_385 ) == V_831 )
goto V_864;
if ( ( ( V_391 + V_821 - 1 ) & V_385 ) != ( V_391 & V_385 ) )
goto V_864;
V_387 = F_376 ( V_2 , V_391 >> V_106 ) ;
if ( F_377 ( V_387 ) )
goto V_864;
V_862 = F_378 ( V_387 ) ;
V_862 += F_379 ( V_391 ) ;
switch ( V_821 ) {
case 1 :
V_863 = F_380 ( T_14 , V_862 , V_860 , V_861 ) ;
break;
case 2 :
V_863 = F_380 ( V_865 , V_862 , V_860 , V_861 ) ;
break;
case 4 :
V_863 = F_380 ( T_1 , V_862 , V_860 , V_861 ) ;
break;
case 8 :
V_863 = F_381 ( V_862 , V_860 , V_861 ) ;
break;
default:
F_25 () ;
}
F_382 ( V_862 ) ;
F_383 ( V_387 ) ;
if ( ! V_863 )
return V_866 ;
F_384 ( V_2 , V_391 >> V_106 ) ;
F_364 ( V_2 , V_391 , V_861 , V_821 ) ;
return V_822 ;
V_864:
F_385 ( V_867 L_20 ) ;
return F_374 ( V_827 , V_616 , V_861 , V_821 , V_68 ) ;
}
static int F_386 ( struct V_1 * V_2 , void * V_868 )
{
int V_120 ;
if ( V_2 -> V_5 . V_869 . V_870 )
V_120 = F_341 ( V_2 , V_871 , V_2 -> V_5 . V_869 . V_872 ,
V_2 -> V_5 . V_869 . V_493 , V_868 ) ;
else
V_120 = F_338 ( V_2 , V_871 ,
V_2 -> V_5 . V_869 . V_872 , V_2 -> V_5 . V_869 . V_493 ,
V_868 ) ;
return V_120 ;
}
static int F_387 ( struct V_1 * V_2 , int V_493 ,
unsigned short V_872 , void * V_194 ,
unsigned int V_743 , bool V_870 )
{
V_2 -> V_5 . V_869 . V_872 = V_872 ;
V_2 -> V_5 . V_869 . V_870 = V_870 ;
V_2 -> V_5 . V_869 . V_743 = V_743 ;
V_2 -> V_5 . V_869 . V_493 = V_493 ;
if ( ! F_386 ( V_2 , V_2 -> V_5 . V_873 ) ) {
V_2 -> V_5 . V_869 . V_743 = 0 ;
return 1 ;
}
V_2 -> V_838 -> V_854 = V_874 ;
V_2 -> V_838 -> V_875 . V_876 = V_870 ? V_877 : V_878 ;
V_2 -> V_838 -> V_875 . V_493 = V_493 ;
V_2 -> V_838 -> V_875 . V_879 = V_880 * V_107 ;
V_2 -> V_838 -> V_875 . V_743 = V_743 ;
V_2 -> V_838 -> V_875 . V_872 = V_872 ;
return 0 ;
}
static int F_388 ( struct V_826 * V_827 ,
int V_493 , unsigned short V_872 , void * V_194 ,
unsigned int V_743 )
{
struct V_1 * V_2 = F_352 ( V_827 ) ;
int V_108 ;
if ( V_2 -> V_5 . V_869 . V_743 )
goto V_881;
V_108 = F_387 ( V_2 , V_493 , V_872 , V_194 , V_743 , true ) ;
if ( V_108 ) {
V_881:
memcpy ( V_194 , V_2 -> V_5 . V_873 , V_493 * V_743 ) ;
F_389 ( V_882 , V_872 , V_493 , V_743 , V_2 -> V_5 . V_873 ) ;
V_2 -> V_5 . V_869 . V_743 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_390 ( struct V_826 * V_827 ,
int V_493 , unsigned short V_872 ,
const void * V_194 , unsigned int V_743 )
{
struct V_1 * V_2 = F_352 ( V_827 ) ;
memcpy ( V_2 -> V_5 . V_873 , V_194 , V_493 * V_743 ) ;
F_389 ( V_883 , V_872 , V_493 , V_743 , V_2 -> V_5 . V_873 ) ;
return F_387 ( V_2 , V_493 , V_872 , ( void * ) V_194 , V_743 , false ) ;
}
static unsigned long F_391 ( struct V_1 * V_2 , int V_814 )
{
return V_73 -> F_391 ( V_2 , V_814 ) ;
}
static void F_392 ( struct V_826 * V_827 , V_174 V_80 )
{
F_393 ( F_352 ( V_827 ) , V_80 ) ;
}
int F_394 ( struct V_1 * V_2 )
{
if ( ! F_240 ( V_2 ) )
return V_822 ;
if ( V_73 -> V_583 () ) {
int V_23 = F_395 () ;
F_243 ( V_23 , V_2 -> V_5 . V_584 ) ;
F_396 ( V_2 -> V_5 . V_584 ,
F_238 , NULL , 1 ) ;
F_397 () ;
F_398 ( V_2 -> V_5 . V_584 ) ;
} else
F_239 () ;
return V_822 ;
}
int F_399 ( struct V_1 * V_2 )
{
V_73 -> V_74 ( V_2 ) ;
return F_394 ( V_2 ) ;
}
static void F_400 ( struct V_826 * V_827 )
{
F_394 ( F_352 ( V_827 ) ) ;
}
static int F_401 ( struct V_826 * V_827 , int V_89 ,
unsigned long * V_651 )
{
return F_99 ( F_352 ( V_827 ) , V_89 , V_651 ) ;
}
static int F_402 ( struct V_826 * V_827 , int V_89 ,
unsigned long V_22 )
{
return F_97 ( F_352 ( V_827 ) , V_89 , V_22 ) ;
}
static T_2 F_403 ( T_2 V_884 , T_1 V_885 )
{
return ( V_884 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_885 ;
}
static unsigned long F_404 ( struct V_826 * V_827 , int V_886 )
{
struct V_1 * V_2 = F_352 ( V_827 ) ;
unsigned long V_22 ;
switch ( V_886 ) {
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
F_405 ( L_21 , V_262 , V_886 ) ;
return 0 ;
}
return V_22 ;
}
static int F_406 ( struct V_826 * V_827 , int V_886 , V_174 V_194 )
{
struct V_1 * V_2 = F_352 ( V_827 ) ;
int V_887 = 0 ;
switch ( V_886 ) {
case 0 :
V_887 = F_60 ( V_2 , F_403 ( F_61 ( V_2 ) , V_194 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_79 = V_194 ;
break;
case 3 :
V_887 = F_84 ( V_2 , V_194 ) ;
break;
case 4 :
V_887 = F_77 ( V_2 , F_403 ( F_78 ( V_2 ) , V_194 ) ) ;
break;
case 8 :
V_887 = F_87 ( V_2 , V_194 ) ;
break;
default:
F_405 ( L_21 , V_262 , V_886 ) ;
V_887 = - 1 ;
}
return V_887 ;
}
static int F_407 ( struct V_826 * V_827 )
{
return V_73 -> V_88 ( F_352 ( V_827 ) ) ;
}
static void F_408 ( struct V_826 * V_827 , struct V_888 * V_889 )
{
V_73 -> V_890 ( F_352 ( V_827 ) , V_889 ) ;
}
static void F_409 ( struct V_826 * V_827 , struct V_888 * V_889 )
{
V_73 -> V_891 ( F_352 ( V_827 ) , V_889 ) ;
}
static void F_410 ( struct V_826 * V_827 , struct V_888 * V_889 )
{
V_73 -> V_892 ( F_352 ( V_827 ) , V_889 ) ;
}
static void F_411 ( struct V_826 * V_827 , struct V_888 * V_889 )
{
V_73 -> V_893 ( F_352 ( V_827 ) , V_889 ) ;
}
static unsigned long F_412 (
struct V_826 * V_827 , int V_814 )
{
return F_391 ( F_352 ( V_827 ) , V_814 ) ;
}
static bool F_413 ( struct V_826 * V_827 , V_865 * V_894 ,
struct V_895 * V_896 , T_1 * V_897 ,
int V_814 )
{
struct V_812 V_813 ;
F_344 ( F_352 ( V_827 ) , & V_813 , V_814 ) ;
* V_894 = V_813 . V_894 ;
if ( V_813 . V_898 ) {
memset ( V_896 , 0 , sizeof( * V_896 ) ) ;
return false ;
}
if ( V_813 . V_899 )
V_813 . V_900 >>= 12 ;
F_414 ( V_896 , V_813 . V_900 ) ;
F_415 ( V_896 , ( unsigned long ) V_813 . V_228 ) ;
#ifdef F_62
if ( V_897 )
* V_897 = V_813 . V_228 >> 32 ;
#endif
V_896 -> type = V_813 . type ;
V_896 -> V_591 = V_813 . V_591 ;
V_896 -> V_901 = V_813 . V_901 ;
V_896 -> V_902 = V_813 . V_903 ;
V_896 -> V_904 = V_813 . V_904 ;
V_896 -> V_905 = V_813 . V_905 ;
V_896 -> V_906 = V_813 . V_181 ;
V_896 -> V_899 = V_813 . V_899 ;
return true ;
}
static void F_416 ( struct V_826 * V_827 , V_865 V_894 ,
struct V_895 * V_896 , T_1 V_897 ,
int V_814 )
{
struct V_1 * V_2 = F_352 ( V_827 ) ;
struct V_812 V_813 ;
V_813 . V_894 = V_894 ;
V_813 . V_228 = F_417 ( V_896 ) ;
#ifdef F_62
V_813 . V_228 |= ( ( T_2 ) V_897 ) << 32 ;
#endif
V_813 . V_900 = F_418 ( V_896 ) ;
if ( V_896 -> V_899 )
V_813 . V_900 = ( V_813 . V_900 << 12 ) | 0xfff ;
V_813 . type = V_896 -> type ;
V_813 . V_901 = V_896 -> V_901 ;
V_813 . V_181 = V_896 -> V_906 ;
V_813 . V_591 = V_896 -> V_591 ;
V_813 . V_905 = V_896 -> V_905 ;
V_813 . V_899 = V_896 -> V_899 ;
V_813 . V_904 = V_896 -> V_904 ;
V_813 . V_903 = V_896 -> V_902 ;
V_813 . V_898 = ! V_813 . V_903 ;
V_813 . V_907 = 0 ;
F_343 ( V_2 , & V_813 , V_814 ) ;
return;
}
static int F_419 ( struct V_826 * V_827 ,
T_1 V_908 , T_2 * V_466 )
{
struct V_32 V_21 ;
int V_120 ;
V_21 . V_146 = V_908 ;
V_21 . V_40 = false ;
V_120 = F_113 ( F_352 ( V_827 ) , & V_21 ) ;
if ( V_120 )
return V_120 ;
* V_466 = V_21 . V_38 ;
return 0 ;
}
static int F_420 ( struct V_826 * V_827 ,
T_1 V_908 , T_2 V_38 )
{
struct V_32 V_21 ;
V_21 . V_38 = V_38 ;
V_21 . V_146 = V_908 ;
V_21 . V_40 = false ;
return F_109 ( F_352 ( V_827 ) , & V_21 ) ;
}
static T_2 F_421 ( struct V_826 * V_827 )
{
struct V_1 * V_2 = F_352 ( V_827 ) ;
return V_2 -> V_5 . V_427 ;
}
static void F_422 ( struct V_826 * V_827 , T_2 V_427 )
{
struct V_1 * V_2 = F_352 ( V_827 ) ;
V_2 -> V_5 . V_427 = V_427 ;
}
static int F_423 ( struct V_826 * V_827 ,
T_1 V_909 )
{
return F_424 ( F_352 ( V_827 ) , V_909 ) ;
}
static int F_425 ( struct V_826 * V_827 ,
T_1 V_909 , T_2 * V_466 )
{
return F_102 ( F_352 ( V_827 ) , V_909 , V_466 ) ;
}
static void F_426 ( struct V_826 * V_827 )
{
F_352 ( V_827 ) -> V_5 . V_910 = 1 ;
}
static void F_427 ( struct V_826 * V_827 )
{
F_428 () ;
F_429 ( F_352 ( V_827 ) ) ;
F_430 () ;
}
static void F_431 ( struct V_826 * V_827 )
{
F_432 () ;
}
static int F_433 ( struct V_826 * V_827 ,
struct V_911 * V_912 ,
enum V_913 V_914 )
{
return V_73 -> V_915 ( F_352 ( V_827 ) , V_912 , V_914 ) ;
}
static void F_434 ( struct V_826 * V_827 ,
T_1 * V_916 , T_1 * V_917 , T_1 * V_199 , T_1 * V_207 )
{
V_691 ( F_352 ( V_827 ) , V_916 , V_917 , V_199 , V_207 ) ;
}
static V_174 F_435 ( struct V_826 * V_827 , unsigned V_918 )
{
return F_101 ( F_352 ( V_827 ) , V_918 ) ;
}
static void F_436 ( struct V_826 * V_827 , unsigned V_918 , V_174 V_194 )
{
F_103 ( F_352 ( V_827 ) , V_918 , V_194 ) ;
}
static void F_437 ( struct V_826 * V_827 , bool V_629 )
{
V_73 -> V_645 ( F_352 ( V_827 ) , V_629 ) ;
}
static void F_438 ( struct V_1 * V_2 , T_1 V_28 )
{
T_1 V_919 = V_73 -> V_625 ( V_2 ) ;
if ( V_919 & V_28 )
V_28 = 0 ;
if ( F_166 ( V_919 || V_28 ) ) {
V_73 -> V_644 ( V_2 , V_28 ) ;
if ( ! V_28 )
F_30 ( V_67 , V_2 ) ;
}
}
static bool F_439 ( struct V_1 * V_2 )
{
struct V_826 * V_827 = & V_2 -> V_5 . V_920 ;
if ( V_827 -> V_68 . V_41 == V_42 )
return F_38 ( V_2 , & V_827 -> V_68 ) ;
if ( V_827 -> V_68 . V_921 )
F_37 ( V_2 , V_827 -> V_68 . V_41 ,
V_827 -> V_68 . V_62 ) ;
else
F_32 ( V_2 , V_827 -> V_68 . V_41 ) ;
return false ;
}
static void F_440 ( struct V_1 * V_2 )
{
struct V_826 * V_827 = & V_2 -> V_5 . V_920 ;
int V_133 , V_134 ;
V_73 -> V_135 ( V_2 , & V_133 , & V_134 ) ;
V_827 -> V_922 = F_441 ( V_2 ) ;
V_827 -> V_923 = F_442 ( V_2 ) ;
V_827 -> V_332 = ( ! F_31 ( V_2 ) ) ? V_924 :
( V_827 -> V_922 & V_925 ) ? V_926 :
( V_134 && F_56 ( V_2 ) ) ? V_849 :
V_133 ? V_927 :
V_928 ;
F_182 ( V_929 != V_930 ) ;
F_182 ( V_646 != V_931 ) ;
F_182 ( V_637 != V_932 ) ;
V_827 -> V_933 = V_2 -> V_5 . V_636 ;
F_443 ( V_827 ) ;
V_2 -> V_5 . V_934 = false ;
}
int F_444 ( struct V_1 * V_2 , int V_597 , int V_935 )
{
struct V_826 * V_827 = & V_2 -> V_5 . V_920 ;
int V_108 ;
F_440 ( V_2 ) ;
V_827 -> V_936 = 2 ;
V_827 -> V_937 = 2 ;
V_827 -> V_938 = V_827 -> V_923 + V_935 ;
V_108 = F_445 ( V_827 , V_597 ) ;
if ( V_108 != V_822 )
return V_939 ;
V_827 -> V_923 = V_827 -> V_938 ;
F_446 ( V_2 , V_827 -> V_923 ) ;
F_447 ( V_2 , V_827 -> V_922 ) ;
if ( V_597 == V_51 )
V_2 -> V_5 . V_628 = 0 ;
else
V_2 -> V_5 . V_622 . V_69 = false ;
return V_940 ;
}
static int F_448 ( struct V_1 * V_2 )
{
int V_120 = V_940 ;
++ V_2 -> V_77 . V_941 ;
F_449 ( V_2 ) ;
if ( ! F_450 ( V_2 ) && V_73 -> V_88 ( V_2 ) == 0 ) {
V_2 -> V_838 -> V_854 = V_942 ;
V_2 -> V_838 -> V_943 . V_944 = V_945 ;
V_2 -> V_838 -> V_943 . V_946 = 0 ;
V_120 = V_939 ;
}
F_32 ( V_2 , V_91 ) ;
return V_120 ;
}
static bool F_451 ( struct V_1 * V_2 , T_16 V_79 ,
bool V_947 ,
int V_948 )
{
T_6 V_391 = V_79 ;
T_17 V_949 ;
if ( V_948 & V_950 )
return false ;
if ( ! V_2 -> V_5 . V_84 . V_951 ) {
V_391 = F_348 ( V_2 , V_79 , NULL ) ;
if ( V_391 == V_100 )
return true ;
}
V_949 = F_452 ( V_2 -> V_138 , F_48 ( V_391 ) ) ;
if ( F_453 ( V_949 ) )
return false ;
F_454 ( V_949 ) ;
if ( V_2 -> V_5 . V_84 . V_951 ) {
unsigned int V_952 ;
F_156 ( & V_2 -> V_138 -> V_953 ) ;
V_952 = V_2 -> V_138 -> V_5 . V_952 ;
F_157 ( & V_2 -> V_138 -> V_953 ) ;
if ( V_952 )
F_455 ( V_2 -> V_138 , F_48 ( V_391 ) ) ;
return true ;
}
F_455 ( V_2 -> V_138 , F_48 ( V_391 ) ) ;
return ! V_947 ;
}
static bool F_456 ( struct V_826 * V_827 ,
unsigned long V_79 , int V_948 )
{
struct V_1 * V_2 = F_352 ( V_827 ) ;
unsigned long V_954 , V_955 , V_391 = V_79 ;
V_954 = V_2 -> V_5 . V_954 ;
V_955 = V_2 -> V_5 . V_955 ;
V_2 -> V_5 . V_954 = V_2 -> V_5 . V_955 = 0 ;
if ( ! ( V_948 & V_956 ) )
return false ;
if ( F_457 ( V_827 ) )
return false ;
if ( V_827 -> V_923 == V_954 && V_955 == V_79 )
return false ;
V_2 -> V_5 . V_954 = V_827 -> V_923 ;
V_2 -> V_5 . V_955 = V_79 ;
if ( ! V_2 -> V_5 . V_84 . V_951 )
V_391 = F_348 ( V_2 , V_79 , NULL ) ;
F_455 ( V_2 -> V_138 , F_48 ( V_391 ) ) ;
return true ;
}
static void F_458 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_636 & V_646 ) ) {
F_459 ( V_2 -> V_299 , V_2 -> V_5 . V_427 , false ) ;
if ( F_166 ( V_2 -> V_5 . V_634 ) ) {
F_30 ( V_602 , V_2 ) ;
V_2 -> V_5 . V_634 = 0 ;
} else {
F_30 ( V_67 , V_2 ) ;
}
}
F_65 ( V_2 ) ;
}
static void F_460 ( struct V_1 * V_2 , unsigned V_933 )
{
unsigned V_119 = V_2 -> V_5 . V_636 ^ V_933 ;
V_2 -> V_5 . V_636 = V_933 ;
if ( V_119 & V_646 )
F_458 ( V_2 ) ;
}
static int F_461 ( unsigned long V_616 , T_1 type , T_1 V_186 ,
unsigned long * V_181 )
{
T_1 V_185 = 0 ;
int V_3 ;
T_1 V_957 , V_958 ;
V_957 = V_186 ;
V_958 = V_186 >> 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ , V_957 >>= 2 , V_958 >>= 4 )
if ( ( V_957 & 3 ) && ( V_958 & 15 ) == type && V_181 [ V_3 ] == V_616 )
V_185 |= ( 1 << V_3 ) ;
return V_185 ;
}
static void F_462 ( struct V_1 * V_2 , unsigned long V_959 , int * V_120 )
{
struct V_960 * V_960 = V_2 -> V_838 ;
if ( F_166 ( V_959 & V_961 ) ) {
if ( V_2 -> V_177 & V_962 ) {
V_960 -> V_963 . V_5 . V_185 = V_964 | V_192 |
V_193 ;
V_960 -> V_963 . V_5 . V_965 = V_2 -> V_5 . V_966 ;
V_960 -> V_963 . V_5 . V_68 = V_53 ;
V_960 -> V_854 = V_967 ;
* V_120 = V_968 ;
} else {
V_2 -> V_5 . V_920 . V_922 &= ~ V_961 ;
V_2 -> V_5 . V_185 &= ~ 15 ;
V_2 -> V_5 . V_185 |= V_964 | V_193 ;
F_32 ( V_2 , V_53 ) ;
}
}
}
static bool F_463 ( struct V_1 * V_2 , int * V_120 )
{
if ( F_166 ( V_2 -> V_177 & V_178 ) &&
( V_2 -> V_5 . V_187 & V_190 ) ) {
struct V_960 * V_960 = V_2 -> V_838 ;
unsigned long V_923 = F_464 ( V_2 ) ;
T_1 V_185 = F_461 ( V_923 , 0 ,
V_2 -> V_5 . V_187 ,
V_2 -> V_5 . V_180 ) ;
if ( V_185 != 0 ) {
V_960 -> V_963 . V_5 . V_185 = V_185 | V_192 | V_193 ;
V_960 -> V_963 . V_5 . V_965 = V_923 ;
V_960 -> V_963 . V_5 . V_68 = V_53 ;
V_960 -> V_854 = V_967 ;
* V_120 = V_968 ;
return true ;
}
}
if ( F_166 ( V_2 -> V_5 . V_186 & V_190 ) &&
! ( F_441 ( V_2 ) & V_969 ) ) {
unsigned long V_923 = F_464 ( V_2 ) ;
T_1 V_185 = F_461 ( V_923 , 0 ,
V_2 -> V_5 . V_186 ,
V_2 -> V_5 . V_181 ) ;
if ( V_185 != 0 ) {
V_2 -> V_5 . V_185 &= ~ 15 ;
V_2 -> V_5 . V_185 |= V_185 | V_193 ;
F_32 ( V_2 , V_53 ) ;
* V_120 = V_940 ;
return true ;
}
}
return false ;
}
int F_465 ( struct V_1 * V_2 ,
unsigned long V_79 ,
int V_948 ,
void * V_970 ,
int V_971 )
{
int V_120 ;
struct V_826 * V_827 = & V_2 -> V_5 . V_920 ;
bool V_491 = true ;
bool V_972 = V_2 -> V_5 . V_947 ;
V_2 -> V_5 . V_947 = false ;
F_466 ( V_2 ) ;
if ( ! ( V_948 & V_973 ) ) {
F_440 ( V_2 ) ;
if ( F_463 ( V_2 , & V_120 ) )
return V_120 ;
V_827 -> V_974 = 0 ;
V_827 -> V_975 = false ;
V_827 -> V_68 . V_41 = - 1 ;
V_827 -> V_976 = false ;
V_827 -> V_977 = V_948 & V_978 ;
V_120 = F_467 ( V_827 , V_970 , V_971 ) ;
F_468 ( V_2 ) ;
++ V_2 -> V_77 . V_979 ;
if ( V_120 != V_980 ) {
if ( V_948 & V_978 )
return V_939 ;
if ( F_451 ( V_2 , V_79 , V_972 ,
V_948 ) )
return V_940 ;
if ( V_948 & V_981 )
return V_939 ;
return F_448 ( V_2 ) ;
}
}
if ( V_948 & V_981 ) {
F_446 ( V_2 , V_827 -> V_938 ) ;
if ( V_827 -> V_922 & V_969 )
F_447 ( V_2 , V_827 -> V_922 & ~ V_969 ) ;
return V_940 ;
}
if ( F_456 ( V_827 , V_79 , V_948 ) )
return V_940 ;
if ( V_2 -> V_5 . V_934 ) {
V_2 -> V_5 . V_934 = false ;
F_469 ( V_827 ) ;
}
V_982:
V_120 = F_470 ( V_827 ) ;
if ( V_120 == V_983 )
return V_940 ;
if ( V_120 == V_984 ) {
if ( F_451 ( V_2 , V_79 , V_972 ,
V_948 ) )
return V_940 ;
return F_448 ( V_2 ) ;
}
if ( V_827 -> V_975 ) {
V_120 = V_940 ;
if ( F_439 ( V_2 ) )
return V_120 ;
} else if ( V_2 -> V_5 . V_869 . V_743 ) {
if ( ! V_2 -> V_5 . V_869 . V_870 ) {
V_2 -> V_5 . V_869 . V_743 = 0 ;
} else {
V_491 = false ;
V_2 -> V_5 . V_985 = V_986 ;
}
V_120 = V_968 ;
} else if ( V_2 -> V_850 ) {
if ( ! V_2 -> V_853 )
V_491 = false ;
V_120 = V_968 ;
V_2 -> V_5 . V_985 = V_987 ;
} else if ( V_120 == V_988 )
goto V_982;
else
V_120 = V_940 ;
if ( V_491 ) {
unsigned long V_959 = V_73 -> V_989 ( V_2 ) ;
F_438 ( V_2 , V_827 -> V_974 ) ;
V_2 -> V_5 . V_990 = false ;
if ( V_2 -> V_5 . V_636 != V_827 -> V_933 )
F_460 ( V_2 , V_827 -> V_933 ) ;
F_446 ( V_2 , V_827 -> V_923 ) ;
if ( V_120 == V_940 )
F_462 ( V_2 , V_959 , & V_120 ) ;
if ( ! V_827 -> V_975 ||
F_27 ( V_827 -> V_68 . V_41 ) == V_56 )
F_471 ( V_2 , V_827 -> V_922 ) ;
if ( F_166 ( ( V_827 -> V_922 & ~ V_959 ) & V_991 ) )
F_30 ( V_67 , V_2 ) ;
} else
V_2 -> V_5 . V_990 = true ;
return V_120 ;
}
int F_472 ( struct V_1 * V_2 , int V_493 , unsigned short V_872 )
{
unsigned long V_194 = F_101 ( V_2 , V_201 ) ;
int V_108 = F_390 ( & V_2 -> V_5 . V_920 ,
V_493 , V_872 , & V_194 , 1 ) ;
V_2 -> V_5 . V_869 . V_743 = 0 ;
return V_108 ;
}
static void F_473 ( void * V_912 )
{
F_474 ( V_348 , 0 ) ;
}
static void F_475 ( void * V_38 )
{
struct V_992 * V_993 = V_38 ;
unsigned long V_265 = 0 ;
if ( V_38 )
V_265 = V_993 -> V_861 ;
else if ( ! F_476 ( V_994 ) )
V_265 = F_477 ( F_478 () ) ;
if ( ! V_265 )
V_265 = V_274 ;
F_474 ( V_348 , V_265 ) ;
}
static int F_479 ( struct V_995 * V_996 , unsigned long V_194 ,
void * V_38 )
{
struct V_992 * V_993 = V_38 ;
struct V_138 * V_138 ;
struct V_1 * V_2 ;
int V_3 , V_997 = 0 ;
if ( V_194 == V_998 && V_993 -> V_860 > V_993 -> V_861 )
return 0 ;
if ( V_194 == V_999 && V_993 -> V_860 < V_993 -> V_861 )
return 0 ;
F_244 ( V_993 -> V_23 , F_475 , V_993 , 1 ) ;
F_156 ( & V_1000 ) ;
F_480 (kvm, &vm_list, vm_list) {
F_175 (i, vcpu, kvm) {
if ( V_2 -> V_23 != V_993 -> V_23 )
continue;
F_30 ( V_340 , V_2 ) ;
if ( V_2 -> V_23 != F_8 () )
V_997 = 1 ;
}
}
F_157 ( & V_1000 ) ;
if ( V_993 -> V_860 < V_993 -> V_861 && V_997 ) {
F_244 ( V_993 -> V_23 , F_475 , V_993 , 1 ) ;
}
return 0 ;
}
static int F_481 ( struct V_995 * V_1001 ,
unsigned long V_1002 , void * V_1003 )
{
unsigned int V_23 = ( unsigned long ) V_1003 ;
switch ( V_1002 ) {
case V_1004 :
case V_1005 :
F_244 ( V_23 , F_475 , NULL , 1 ) ;
break;
case V_1006 :
F_244 ( V_23 , F_473 , NULL , 1 ) ;
break;
}
return V_1007 ;
}
static void F_482 ( void )
{
int V_23 ;
V_1008 = V_274 ;
F_483 () ;
if ( ! F_476 ( V_994 ) ) {
#ifdef F_484
struct V_1009 V_1010 ;
memset ( & V_1010 , 0 , sizeof( V_1010 ) ) ;
V_23 = F_395 () ;
F_485 ( & V_1010 , V_23 ) ;
if ( V_1010 . V_1011 . V_1012 )
V_1008 = V_1010 . V_1011 . V_1012 ;
F_397 () ;
#endif
F_486 ( & V_1013 ,
V_1014 ) ;
}
F_129 ( L_22 , V_1008 ) ;
F_487 (cpu)
F_244 ( V_23 , F_475 , NULL , 1 ) ;
F_488 ( & V_1015 ) ;
F_489 () ;
}
int F_490 ( void )
{
return F_179 ( V_1016 ) != NULL ;
}
static int F_491 ( void )
{
int V_1017 = 3 ;
if ( F_179 ( V_1016 ) )
V_1017 = V_73 -> V_88 ( F_179 ( V_1016 ) ) ;
return V_1017 != 0 ;
}
static unsigned long F_492 ( void )
{
unsigned long V_1018 = 0 ;
if ( F_179 ( V_1016 ) )
V_1018 = F_442 ( F_179 ( V_1016 ) ) ;
return V_1018 ;
}
void F_493 ( struct V_1 * V_2 )
{
F_474 ( V_1016 , V_2 ) ;
}
void F_494 ( struct V_1 * V_2 )
{
F_474 ( V_1016 , NULL ) ;
}
static void F_495 ( void )
{
T_2 V_28 ;
int V_1019 = V_1020 . V_1021 ;
V_28 = F_496 ( V_1019 , 51 ) ;
V_28 |= 0x3ull << 62 ;
V_28 |= 1ull ;
#ifdef F_62
if ( V_1019 == 52 )
V_28 &= ~ 1ull ;
#endif
F_497 ( V_28 ) ;
}
static void F_498 ( struct V_359 * V_360 )
{
struct V_138 * V_138 ;
struct V_1 * V_2 ;
int V_3 ;
F_156 ( & V_1000 ) ;
F_480 (kvm, &vm_list, vm_list)
F_175 (i, vcpu, kvm)
F_30 ( V_298 , V_2 ) ;
F_170 ( & V_338 , 0 ) ;
F_157 ( & V_1000 ) ;
}
static int F_499 ( struct V_995 * V_996 , unsigned long V_1022 ,
void * V_1023 )
{
struct V_224 * V_293 = & V_224 ;
struct V_222 * V_223 = V_1023 ;
F_115 ( V_223 ) ;
if ( V_293 -> clock . V_231 != V_297 &&
F_141 ( & V_338 ) != 0 )
F_500 ( V_1024 , & V_1025 ) ;
return 0 ;
}
int F_501 ( void * V_1026 )
{
int V_120 ;
struct V_73 * V_841 = V_1026 ;
if ( V_73 ) {
F_10 ( V_26 L_23 ) ;
V_120 = - V_601 ;
goto V_113;
}
if ( ! V_841 -> V_1027 () ) {
F_10 ( V_26 L_24 ) ;
V_120 = - V_1028 ;
goto V_113;
}
if ( V_841 -> V_1029 () ) {
F_10 ( V_26 L_25 ) ;
V_120 = - V_1028 ;
goto V_113;
}
V_120 = - V_389 ;
V_25 = F_502 ( struct V_11 ) ;
if ( ! V_25 ) {
F_10 ( V_26 L_26 ) ;
goto V_113;
}
V_120 = F_503 () ;
if ( V_120 )
goto V_1030;
F_495 () ;
V_73 = V_841 ;
F_504 ( V_1031 , V_1032 ,
V_1033 , V_1034 , 0 ) ;
F_482 () ;
F_505 ( & V_1035 ) ;
if ( V_556 )
V_145 = F_506 ( V_143 ) ;
F_507 () ;
#ifdef F_62
F_508 ( & V_1036 ) ;
#endif
return 0 ;
V_1030:
F_509 ( V_25 ) ;
V_113:
return V_120 ;
}
void F_510 ( void )
{
F_511 ( & V_1035 ) ;
if ( ! F_476 ( V_994 ) )
F_512 ( & V_1013 ,
V_1014 ) ;
F_513 ( & V_1015 ) ;
#ifdef F_62
F_514 ( & V_1036 ) ;
#endif
V_73 = NULL ;
F_515 () ;
F_509 ( V_25 ) ;
}
int F_516 ( struct V_1 * V_2 )
{
++ V_2 -> V_77 . V_1037 ;
if ( F_88 ( V_2 ) ) {
V_2 -> V_5 . V_1038 = V_1039 ;
return 1 ;
} else {
V_2 -> V_838 -> V_854 = V_1040 ;
return 0 ;
}
}
int F_517 ( struct V_1 * V_2 )
{
V_73 -> V_74 ( V_2 ) ;
return F_516 ( V_2 ) ;
}
static void F_518 ( struct V_138 * V_138 , unsigned long V_309 , int V_1041 )
{
struct V_1042 V_1043 ;
V_1043 . V_1044 = 0 ;
V_1043 . V_1045 = 0 ;
V_1043 . V_1046 = V_1041 ;
V_1043 . V_1047 = false ;
V_1043 . V_1048 = V_1049 ;
F_519 ( V_138 , NULL , & V_1043 , NULL ) ;
}
void F_520 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_592 = false ;
V_73 -> V_1050 ( V_2 ) ;
}
int F_521 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_1051 , V_1052 , V_1053 , V_1054 , V_108 ;
int V_1055 , V_120 = 1 ;
V_73 -> V_74 ( V_2 ) ;
if ( F_522 ( V_2 -> V_138 ) )
return F_523 ( V_2 ) ;
V_16 = F_101 ( V_2 , V_201 ) ;
V_1051 = F_101 ( V_2 , V_1056 ) ;
V_1052 = F_101 ( V_2 , V_200 ) ;
V_1053 = F_101 ( V_2 , V_202 ) ;
V_1054 = F_101 ( V_2 , V_1057 ) ;
F_524 ( V_16 , V_1051 , V_1052 , V_1053 , V_1054 ) ;
V_1055 = F_525 ( V_2 ) ;
if ( ! V_1055 ) {
V_16 &= 0xFFFFFFFF ;
V_1051 &= 0xFFFFFFFF ;
V_1052 &= 0xFFFFFFFF ;
V_1053 &= 0xFFFFFFFF ;
V_1054 &= 0xFFFFFFFF ;
}
if ( V_73 -> V_88 ( V_2 ) != 0 ) {
V_108 = - V_1058 ;
goto V_113;
}
switch ( V_16 ) {
case V_1059 :
V_108 = 0 ;
break;
case V_1060 :
F_518 ( V_2 -> V_138 , V_1051 , V_1052 ) ;
V_108 = 0 ;
break;
default:
V_108 = - V_1061 ;
break;
}
V_113:
if ( ! V_1055 )
V_108 = ( T_1 ) V_108 ;
F_103 ( V_2 , V_201 , V_108 ) ;
++ V_2 -> V_77 . V_1062 ;
return V_120 ;
}
static int F_526 ( struct V_826 * V_827 )
{
struct V_1 * V_2 = F_352 ( V_827 ) ;
char V_1063 [ 3 ] ;
unsigned long V_1064 = F_442 ( V_2 ) ;
V_73 -> V_1065 ( V_2 , V_1063 ) ;
return F_374 ( V_827 , V_1064 , V_1063 , 3 , NULL ) ;
}
static int F_527 ( struct V_1 * V_2 )
{
return V_2 -> V_838 -> V_1066 &&
F_162 ( ! F_261 ( V_2 -> V_138 ) ) ;
}
static void F_528 ( struct V_1 * V_2 )
{
struct V_960 * V_960 = V_2 -> V_838 ;
V_960 -> V_1067 = ( F_441 ( V_2 ) & V_991 ) != 0 ;
V_960 -> V_309 = F_270 ( V_2 ) ? V_1068 : 0 ;
V_960 -> V_175 = F_90 ( V_2 ) ;
V_960 -> V_31 = F_19 ( V_2 ) ;
V_960 -> V_1069 =
F_261 ( V_2 -> V_138 ) ||
F_254 ( V_2 ) ;
}
static void F_251 ( struct V_1 * V_2 )
{
int V_1070 , V_1071 ;
if ( ! V_73 -> F_251 )
return;
if ( ! V_2 -> V_5 . V_595 )
return;
if ( V_2 -> V_5 . V_592 )
return;
if ( ! V_2 -> V_5 . V_595 -> V_700 )
V_1070 = F_529 ( V_2 ) ;
else
V_1070 = - 1 ;
if ( V_1070 != - 1 )
V_1070 >>= 4 ;
V_1071 = F_91 ( V_2 ) ;
V_73 -> F_251 ( V_2 , V_1071 , V_1070 ) ;
}
static int F_530 ( struct V_1 * V_2 , bool V_1072 )
{
int V_120 ;
if ( V_2 -> V_5 . V_68 . V_69 ) {
F_531 ( V_2 -> V_5 . V_68 . V_16 ,
V_2 -> V_5 . V_68 . V_71 ,
V_2 -> V_5 . V_68 . V_62 ) ;
if ( F_27 ( V_2 -> V_5 . V_68 . V_16 ) == V_60 )
F_471 ( V_2 , F_441 ( V_2 ) |
V_969 ) ;
if ( V_2 -> V_5 . V_68 . V_16 == V_53 &&
( V_2 -> V_5 . V_186 & V_1073 ) ) {
V_2 -> V_5 . V_186 &= ~ V_1073 ;
F_94 ( V_2 ) ;
}
V_73 -> V_1074 ( V_2 , V_2 -> V_5 . V_68 . V_16 ,
V_2 -> V_5 . V_68 . V_71 ,
V_2 -> V_5 . V_68 . V_62 ,
V_2 -> V_5 . V_68 . V_63 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_627 ) {
V_73 -> V_1075 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_622 . V_69 ) {
V_73 -> V_1076 ( V_2 ) ;
return 0 ;
}
if ( F_450 ( V_2 ) && V_73 -> V_1077 ) {
V_120 = V_73 -> V_1077 ( V_2 , V_1072 ) ;
if ( V_120 != 0 )
return V_120 ;
}
if ( V_2 -> V_5 . V_628 ) {
if ( V_73 -> V_1078 ( V_2 ) ) {
-- V_2 -> V_5 . V_628 ;
V_2 -> V_5 . V_627 = true ;
V_73 -> V_1075 ( V_2 ) ;
}
} else if ( F_532 ( V_2 ) ) {
if ( F_450 ( V_2 ) && V_73 -> V_1077 ) {
V_120 = V_73 -> V_1077 ( V_2 , V_1072 ) ;
if ( V_120 != 0 )
return V_120 ;
}
if ( V_73 -> V_1079 ( V_2 ) ) {
F_260 ( V_2 , F_533 ( V_2 ) ,
false ) ;
V_73 -> V_1076 ( V_2 ) ;
}
}
return 0 ;
}
static void F_268 ( struct V_1 * V_2 )
{
unsigned V_900 = 2 ;
if ( V_73 -> V_630 ( V_2 ) || V_2 -> V_5 . V_627 )
V_900 = 1 ;
V_2 -> V_5 . V_628 += F_534 ( & V_2 -> V_5 . V_85 , 0 ) ;
V_2 -> V_5 . V_628 = F_336 ( V_2 -> V_5 . V_628 , V_900 ) ;
F_30 ( V_67 , V_2 ) ;
}
static T_1 F_535 ( struct V_812 * V_814 )
{
T_1 V_309 = 0 ;
V_309 |= V_814 -> V_899 << 23 ;
V_309 |= V_814 -> V_181 << 22 ;
V_309 |= V_814 -> V_905 << 21 ;
V_309 |= V_814 -> V_904 << 20 ;
V_309 |= V_814 -> V_903 << 15 ;
V_309 |= V_814 -> V_901 << 13 ;
V_309 |= V_814 -> V_591 << 12 ;
V_309 |= V_814 -> type << 8 ;
return V_309 ;
}
static void F_536 ( struct V_1 * V_2 , char * V_1080 , int V_492 )
{
struct V_812 V_814 ;
int V_94 ;
F_344 ( V_2 , & V_814 , V_492 ) ;
F_537 ( T_1 , V_1080 , 0x7fa8 + V_492 * 4 , V_814 . V_894 ) ;
if ( V_492 < 3 )
V_94 = 0x7f84 + V_492 * 12 ;
else
V_94 = 0x7f2c + ( V_492 - 3 ) * 12 ;
F_537 ( T_1 , V_1080 , V_94 + 8 , V_814 . V_228 ) ;
F_537 ( T_1 , V_1080 , V_94 + 4 , V_814 . V_900 ) ;
F_537 ( T_1 , V_1080 , V_94 , F_535 ( & V_814 ) ) ;
}
static void F_538 ( struct V_1 * V_2 , char * V_1080 , int V_492 )
{
struct V_812 V_814 ;
int V_94 ;
V_865 V_309 ;
F_344 ( V_2 , & V_814 , V_492 ) ;
V_94 = 0x7e00 + V_492 * 16 ;
V_309 = F_535 ( & V_814 ) >> 8 ;
F_537 ( V_865 , V_1080 , V_94 , V_814 . V_894 ) ;
F_537 ( V_865 , V_1080 , V_94 + 2 , V_309 ) ;
F_537 ( T_1 , V_1080 , V_94 + 4 , V_814 . V_900 ) ;
F_537 ( T_2 , V_1080 , V_94 + 8 , V_814 . V_228 ) ;
}
static void F_539 ( struct V_1 * V_2 , char * V_1080 )
{
struct V_888 V_889 ;
struct V_812 V_814 ;
unsigned long V_194 ;
int V_3 ;
F_537 ( T_1 , V_1080 , 0x7ffc , F_61 ( V_2 ) ) ;
F_537 ( T_1 , V_1080 , 0x7ff8 , F_59 ( V_2 ) ) ;
F_537 ( T_1 , V_1080 , 0x7ff4 , F_441 ( V_2 ) ) ;
F_537 ( T_1 , V_1080 , 0x7ff0 , F_442 ( V_2 ) ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
F_537 ( T_1 , V_1080 , 0x7fd0 + V_3 * 4 , F_101 ( V_2 , V_3 ) ) ;
F_99 ( V_2 , 6 , & V_194 ) ;
F_537 ( T_1 , V_1080 , 0x7fcc , ( T_1 ) V_194 ) ;
F_99 ( V_2 , 7 , & V_194 ) ;
F_537 ( T_1 , V_1080 , 0x7fc8 , ( T_1 ) V_194 ) ;
F_344 ( V_2 , & V_814 , V_1081 ) ;
F_537 ( T_1 , V_1080 , 0x7fc4 , V_814 . V_894 ) ;
F_537 ( T_1 , V_1080 , 0x7f64 , V_814 . V_228 ) ;
F_537 ( T_1 , V_1080 , 0x7f60 , V_814 . V_900 ) ;
F_537 ( T_1 , V_1080 , 0x7f5c , F_535 ( & V_814 ) ) ;
F_344 ( V_2 , & V_814 , V_1082 ) ;
F_537 ( T_1 , V_1080 , 0x7fc0 , V_814 . V_894 ) ;
F_537 ( T_1 , V_1080 , 0x7f80 , V_814 . V_228 ) ;
F_537 ( T_1 , V_1080 , 0x7f7c , V_814 . V_900 ) ;
F_537 ( T_1 , V_1080 , 0x7f78 , F_535 ( & V_814 ) ) ;
V_73 -> V_890 ( V_2 , & V_889 ) ;
F_537 ( T_1 , V_1080 , 0x7f74 , V_889 . V_80 ) ;
F_537 ( T_1 , V_1080 , 0x7f70 , V_889 . V_493 ) ;
V_73 -> V_891 ( V_2 , & V_889 ) ;
F_537 ( T_1 , V_1080 , 0x7f58 , V_889 . V_80 ) ;
F_537 ( T_1 , V_1080 , 0x7f54 , V_889 . V_493 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_536 ( V_2 , V_1080 , V_3 ) ;
F_537 ( T_1 , V_1080 , 0x7f14 , F_78 ( V_2 ) ) ;
F_537 ( T_1 , V_1080 , 0x7efc , 0x00020000 ) ;
F_537 ( T_1 , V_1080 , 0x7ef8 , V_2 -> V_5 . V_427 ) ;
}
static void F_540 ( struct V_1 * V_2 , char * V_1080 )
{
#ifdef F_62
struct V_888 V_889 ;
struct V_812 V_814 ;
unsigned long V_194 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ )
F_537 ( T_2 , V_1080 , 0x7ff8 - V_3 * 8 , F_101 ( V_2 , V_3 ) ) ;
F_537 ( T_2 , V_1080 , 0x7f78 , F_442 ( V_2 ) ) ;
F_537 ( T_1 , V_1080 , 0x7f70 , F_441 ( V_2 ) ) ;
F_99 ( V_2 , 6 , & V_194 ) ;
F_537 ( T_2 , V_1080 , 0x7f68 , V_194 ) ;
F_99 ( V_2 , 7 , & V_194 ) ;
F_537 ( T_2 , V_1080 , 0x7f60 , V_194 ) ;
F_537 ( T_2 , V_1080 , 0x7f58 , F_61 ( V_2 ) ) ;
F_537 ( T_2 , V_1080 , 0x7f50 , F_59 ( V_2 ) ) ;
F_537 ( T_2 , V_1080 , 0x7f48 , F_78 ( V_2 ) ) ;
F_537 ( T_1 , V_1080 , 0x7f00 , V_2 -> V_5 . V_427 ) ;
F_537 ( T_1 , V_1080 , 0x7efc , 0x00020064 ) ;
F_537 ( T_2 , V_1080 , 0x7ed0 , V_2 -> V_5 . V_131 ) ;
F_344 ( V_2 , & V_814 , V_1081 ) ;
F_537 ( V_865 , V_1080 , 0x7e90 , V_814 . V_894 ) ;
F_537 ( V_865 , V_1080 , 0x7e92 , F_535 ( & V_814 ) >> 8 ) ;
F_537 ( T_1 , V_1080 , 0x7e94 , V_814 . V_900 ) ;
F_537 ( T_2 , V_1080 , 0x7e98 , V_814 . V_228 ) ;
V_73 -> V_891 ( V_2 , & V_889 ) ;
F_537 ( T_1 , V_1080 , 0x7e84 , V_889 . V_493 ) ;
F_537 ( T_2 , V_1080 , 0x7e88 , V_889 . V_80 ) ;
F_344 ( V_2 , & V_814 , V_1082 ) ;
F_537 ( V_865 , V_1080 , 0x7e70 , V_814 . V_894 ) ;
F_537 ( V_865 , V_1080 , 0x7e72 , F_535 ( & V_814 ) >> 8 ) ;
F_537 ( T_1 , V_1080 , 0x7e74 , V_814 . V_900 ) ;
F_537 ( T_2 , V_1080 , 0x7e78 , V_814 . V_228 ) ;
V_73 -> V_890 ( V_2 , & V_889 ) ;
F_537 ( T_1 , V_1080 , 0x7e64 , V_889 . V_493 ) ;
F_537 ( T_2 , V_1080 , 0x7e68 , V_889 . V_80 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_538 ( V_2 , V_1080 , V_3 ) ;
#else
F_541 ( 1 ) ;
#endif
}
static void F_542 ( struct V_1 * V_2 )
{
struct V_812 V_1083 , V_1084 ;
struct V_888 V_889 ;
char V_1080 [ 512 ] ;
T_1 V_121 ;
if ( F_270 ( V_2 ) ) {
V_2 -> V_5 . V_634 = true ;
return;
}
F_459 ( V_2 -> V_299 , V_2 -> V_5 . V_427 , true ) ;
V_2 -> V_5 . V_636 |= V_646 ;
memset ( V_1080 , 0 , 512 ) ;
if ( F_543 ( V_2 ) )
F_540 ( V_2 , V_1080 ) ;
else
F_539 ( V_2 , V_1080 ) ;
F_199 ( V_2 , V_2 -> V_5 . V_427 + 0xfe00 , V_1080 , sizeof( V_1080 ) ) ;
if ( V_73 -> V_630 ( V_2 ) )
V_2 -> V_5 . V_636 |= V_637 ;
else
V_73 -> V_645 ( V_2 , true ) ;
F_447 ( V_2 , V_1085 ) ;
F_446 ( V_2 , 0x8000 ) ;
V_121 = V_2 -> V_5 . V_121 & ~ ( V_130 | V_1086 | V_1087 | V_124 ) ;
V_73 -> V_137 ( V_2 , V_121 ) ;
V_2 -> V_5 . V_121 = V_121 ;
V_73 -> V_169 ( V_2 , 0 ) ;
V_889 . V_80 = V_889 . V_493 = 0 ;
V_73 -> V_893 ( V_2 , & V_889 ) ;
F_97 ( V_2 , 7 , V_197 ) ;
V_1083 . V_894 = ( V_2 -> V_5 . V_427 >> 4 ) & 0xffff ;
V_1083 . V_228 = V_2 -> V_5 . V_427 ;
V_1084 . V_894 = 0 ;
V_1084 . V_228 = 0 ;
V_1083 . V_900 = V_1084 . V_900 = 0xffffffff ;
V_1083 . type = V_1084 . type = 0x3 ;
V_1083 . V_901 = V_1084 . V_901 = 0 ;
V_1083 . V_181 = V_1084 . V_181 = 0 ;
V_1083 . V_591 = V_1084 . V_591 = 1 ;
V_1083 . V_905 = V_1084 . V_905 = 0 ;
V_1083 . V_899 = V_1084 . V_899 = 1 ;
V_1083 . V_904 = V_1084 . V_904 = 0 ;
V_1083 . V_903 = V_1084 . V_903 = 1 ;
V_1083 . V_898 = V_1084 . V_898 = 0 ;
V_1083 . V_907 = V_1084 . V_907 = 0 ;
F_343 ( V_2 , & V_1083 , V_1088 ) ;
F_343 ( V_2 , & V_1084 , V_1089 ) ;
F_343 ( V_2 , & V_1084 , V_1090 ) ;
F_343 ( V_2 , & V_1084 , V_1091 ) ;
F_343 ( V_2 , & V_1084 , V_1092 ) ;
F_343 ( V_2 , & V_1084 , V_1093 ) ;
if ( F_543 ( V_2 ) )
V_73 -> F_107 ( V_2 , 0 ) ;
F_75 ( V_2 ) ;
F_65 ( V_2 ) ;
}
void F_544 ( struct V_138 * V_138 )
{
F_173 ( V_138 , V_1094 ) ;
}
static void F_545 ( struct V_1 * V_2 )
{
T_2 V_1095 [ 4 ] ;
if ( ! F_546 ( V_2 -> V_5 . V_595 ) )
return;
F_547 ( V_2 -> V_5 . V_1096 , 256 ) ;
if ( V_763 ( V_2 -> V_138 ) )
F_548 ( V_2 , V_2 -> V_5 . V_1096 ) ;
else {
if ( V_2 -> V_5 . V_592 )
V_73 -> V_593 ( V_2 ) ;
F_549 ( V_2 , V_2 -> V_5 . V_1096 ) ;
}
F_550 ( ( V_174 * ) V_1095 , V_2 -> V_5 . V_1096 ,
F_551 ( V_2 ) -> V_1097 , 256 ) ;
V_73 -> V_1098 ( V_2 , V_1095 ) ;
}
static void F_552 ( struct V_1 * V_2 )
{
++ V_2 -> V_77 . V_1099 ;
V_73 -> V_1099 ( V_2 ) ;
}
void F_553 ( struct V_1 * V_2 )
{
struct V_387 * V_387 = NULL ;
if ( ! F_88 ( V_2 ) )
return;
if ( ! V_73 -> V_1100 )
return;
V_387 = F_554 ( V_2 -> V_138 , V_831 >> V_106 ) ;
if ( F_377 ( V_387 ) )
return;
V_73 -> V_1100 ( V_2 , F_555 ( V_387 ) ) ;
F_556 ( V_387 ) ;
}
void F_557 ( struct V_138 * V_138 ,
unsigned long V_80 )
{
if ( V_80 == F_558 ( V_138 , V_831 >> V_106 ) )
F_173 ( V_138 , V_1101 ) ;
}
static int F_559 ( struct V_1 * V_2 )
{
int V_120 ;
bool V_1072 =
F_527 ( V_2 ) &&
F_252 ( V_2 ) ;
bool V_1102 = false ;
if ( V_2 -> V_341 ) {
if ( F_560 ( V_1103 , V_2 ) )
F_561 ( V_2 ) ;
if ( F_560 ( V_582 , V_2 ) )
F_562 ( V_2 ) ;
if ( F_560 ( V_298 , V_2 ) )
F_174 ( V_2 -> V_138 ) ;
if ( F_560 ( V_434 , V_2 ) )
F_190 ( V_2 ) ;
if ( F_560 ( V_340 , V_2 ) ) {
V_120 = F_177 ( V_2 ) ;
if ( F_166 ( V_120 ) )
goto V_113;
}
if ( F_560 ( V_1104 , V_2 ) )
F_85 ( V_2 ) ;
if ( F_560 ( V_171 , V_2 ) )
F_552 ( V_2 ) ;
if ( F_560 ( V_1105 , V_2 ) ) {
V_2 -> V_838 -> V_854 = V_1106 ;
V_120 = 0 ;
goto V_113;
}
if ( F_560 ( V_72 , V_2 ) ) {
V_2 -> V_838 -> V_854 = V_1107 ;
V_120 = 0 ;
goto V_113;
}
if ( F_560 ( V_1108 , V_2 ) ) {
V_2 -> V_1109 = 0 ;
V_73 -> V_1110 ( V_2 ) ;
}
if ( F_560 ( V_1111 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1112 = true ;
V_120 = 1 ;
goto V_113;
}
if ( F_560 ( V_439 , V_2 ) )
F_206 ( V_2 ) ;
if ( F_560 ( V_602 , V_2 ) )
F_542 ( V_2 ) ;
if ( F_560 ( V_86 , V_2 ) )
F_268 ( V_2 ) ;
if ( F_560 ( V_1113 , V_2 ) )
F_563 ( V_2 ) ;
if ( F_560 ( V_1114 , V_2 ) )
F_564 ( V_2 ) ;
if ( F_560 ( V_1115 , V_2 ) ) {
F_13 ( V_2 -> V_5 . V_1116 > 255 ) ;
if ( F_58 ( V_2 -> V_5 . V_1116 ,
V_2 -> V_5 . V_1096 ) ) {
V_2 -> V_838 -> V_854 = V_1117 ;
V_2 -> V_838 -> V_1118 . V_41 =
V_2 -> V_5 . V_1116 ;
V_120 = 0 ;
goto V_113;
}
}
if ( F_560 ( V_1094 , V_2 ) )
F_545 ( V_2 ) ;
if ( F_560 ( V_1101 , V_2 ) )
F_553 ( V_2 ) ;
if ( F_560 ( V_1119 , V_2 ) ) {
V_2 -> V_838 -> V_854 = V_1120 ;
V_2 -> V_838 -> V_1121 . type = V_1122 ;
V_120 = 0 ;
goto V_113;
}
if ( F_560 ( V_1123 , V_2 ) ) {
V_2 -> V_838 -> V_854 = V_1120 ;
V_2 -> V_838 -> V_1121 . type = V_1124 ;
V_120 = 0 ;
goto V_113;
}
if ( F_560 ( V_1125 , V_2 ) ) {
V_2 -> V_838 -> V_854 = V_1126 ;
V_2 -> V_838 -> V_1127 = V_2 -> V_5 . V_1127 . exit ;
V_120 = 0 ;
goto V_113;
}
if ( F_560 ( V_1128 , V_2 ) )
F_565 ( V_2 ) ;
}
if ( F_566 ( V_2 ) ) {
if ( V_2 -> V_5 . V_592 )
V_73 -> V_1129 ( V_2 ,
F_529 ( V_2 ) ) ;
}
if ( F_560 ( V_67 , V_2 ) || V_1072 ) {
F_567 ( V_2 ) ;
if ( V_2 -> V_5 . V_1038 == V_1130 ) {
V_120 = 1 ;
goto V_113;
}
if ( F_530 ( V_2 , V_1072 ) != 0 )
V_1102 = true ;
else if ( V_2 -> V_5 . V_628 )
V_73 -> V_1131 ( V_2 ) ;
else if ( F_532 ( V_2 ) || V_1072 )
V_73 -> V_1132 ( V_2 ) ;
if ( F_566 ( V_2 ) ) {
F_251 ( V_2 ) ;
F_568 ( V_2 ) ;
}
}
V_120 = F_569 ( V_2 ) ;
if ( F_166 ( V_120 ) ) {
goto V_1133;
}
F_428 () ;
V_73 -> V_1134 ( V_2 ) ;
if ( V_2 -> V_1109 )
F_429 ( V_2 ) ;
F_71 ( V_2 ) ;
V_2 -> V_332 = V_1135 ;
F_229 ( & V_2 -> V_138 -> V_488 , V_2 -> V_1136 ) ;
F_570 () ;
F_330 () ;
if ( V_2 -> V_332 == V_1137 || V_2 -> V_341
|| F_571 () || F_572 ( V_398 ) ) {
V_2 -> V_332 = V_1138 ;
F_185 () ;
F_331 () ;
F_432 () ;
V_2 -> V_1136 = F_228 ( & V_2 -> V_138 -> V_488 ) ;
V_120 = 1 ;
goto V_1133;
}
if ( V_1102 )
F_573 ( V_2 -> V_23 ) ;
F_574 ( V_2 -> V_299 ) ;
F_575 ( V_2 ) ;
F_576 () ;
if ( F_166 ( V_2 -> V_5 . V_182 ) ) {
F_577 ( 0 , 7 ) ;
F_577 ( V_2 -> V_5 . V_180 [ 0 ] , 0 ) ;
F_577 ( V_2 -> V_5 . V_180 [ 1 ] , 1 ) ;
F_577 ( V_2 -> V_5 . V_180 [ 2 ] , 2 ) ;
F_577 ( V_2 -> V_5 . V_180 [ 3 ] , 3 ) ;
F_577 ( V_2 -> V_5 . V_185 , 6 ) ;
V_2 -> V_5 . V_182 &= ~ V_183 ;
}
V_73 -> V_838 ( V_2 ) ;
if ( F_166 ( V_2 -> V_5 . V_182 & V_1139 ) ) {
F_28 ( V_2 -> V_177 & V_178 ) ;
V_73 -> V_1140 ( V_2 ) ;
F_92 ( V_2 ) ;
F_93 ( V_2 ) ;
F_94 ( V_2 ) ;
V_2 -> V_5 . V_182 &= ~ V_183 ;
}
if ( F_578 () )
F_579 () ;
V_2 -> V_5 . V_325 = F_149 ( V_2 , F_148 () ) ;
V_2 -> V_332 = V_1138 ;
F_185 () ;
V_73 -> V_1141 ( V_2 ) ;
++ V_2 -> V_77 . V_1142 ;
F_580 () ;
F_581 () ;
F_432 () ;
V_2 -> V_1136 = F_228 ( & V_2 -> V_138 -> V_488 ) ;
if ( F_166 ( V_1143 == V_1144 ) ) {
unsigned long V_1064 = F_442 ( V_2 ) ;
F_582 ( V_1144 , ( void * ) V_1064 ) ;
}
if ( F_166 ( V_2 -> V_5 . V_276 ) )
F_30 ( V_340 , V_2 ) ;
if ( V_2 -> V_5 . V_1145 )
F_583 ( V_2 ) ;
V_120 = V_73 -> V_1146 ( V_2 ) ;
return V_120 ;
V_1133:
V_73 -> V_1133 ( V_2 ) ;
if ( F_166 ( V_2 -> V_5 . V_1145 ) )
F_583 ( V_2 ) ;
V_113:
return V_120 ;
}
static inline int F_584 ( struct V_138 * V_138 , struct V_1 * V_2 )
{
if ( ! F_585 ( V_2 ) &&
( ! V_73 -> V_1147 || V_73 -> V_1147 ( V_2 ) == 0 ) ) {
F_229 ( & V_138 -> V_488 , V_2 -> V_1136 ) ;
F_586 ( V_2 ) ;
V_2 -> V_1136 = F_228 ( & V_138 -> V_488 ) ;
if ( V_73 -> V_1148 )
V_73 -> V_1148 ( V_2 ) ;
if ( ! F_560 ( V_1149 , V_2 ) )
return 1 ;
}
F_567 ( V_2 ) ;
switch( V_2 -> V_5 . V_1038 ) {
case V_1039 :
V_2 -> V_5 . V_1150 . V_1151 = false ;
V_2 -> V_5 . V_1038 =
V_1152 ;
case V_1152 :
V_2 -> V_5 . V_6 . V_1112 = false ;
break;
case V_1130 :
break;
default:
return - V_1153 ;
break;
}
return 1 ;
}
static inline bool F_587 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_1038 == V_1152 &&
! V_2 -> V_5 . V_6 . V_1112 ) ;
}
static int F_588 ( struct V_1 * V_2 )
{
int V_120 ;
struct V_138 * V_138 = V_2 -> V_138 ;
V_2 -> V_1136 = F_228 ( & V_138 -> V_488 ) ;
for (; ; ) {
if ( F_587 ( V_2 ) ) {
V_120 = F_559 ( V_2 ) ;
} else {
V_120 = F_584 ( V_138 , V_2 ) ;
}
if ( V_120 <= 0 )
break;
F_176 ( V_238 , & V_2 -> V_341 ) ;
if ( F_589 ( V_2 ) )
F_590 ( V_2 ) ;
if ( F_527 ( V_2 ) &&
F_254 ( V_2 ) ) {
V_120 = 0 ;
V_2 -> V_838 -> V_854 = V_1154 ;
++ V_2 -> V_77 . V_1155 ;
break;
}
F_591 ( V_2 ) ;
if ( F_572 ( V_398 ) ) {
V_120 = - V_1153 ;
V_2 -> V_838 -> V_854 = V_1156 ;
++ V_2 -> V_77 . V_1157 ;
break;
}
if ( F_571 () ) {
F_229 ( & V_138 -> V_488 , V_2 -> V_1136 ) ;
F_592 () ;
V_2 -> V_1136 = F_228 ( & V_138 -> V_488 ) ;
}
}
F_229 ( & V_138 -> V_488 , V_2 -> V_1136 ) ;
return V_120 ;
}
static inline int F_593 ( struct V_1 * V_2 )
{
int V_120 ;
V_2 -> V_1136 = F_228 ( & V_2 -> V_138 -> V_488 ) ;
V_120 = F_594 ( V_2 , V_973 ) ;
F_229 ( & V_2 -> V_138 -> V_488 , V_2 -> V_1136 ) ;
if ( V_120 != V_940 )
return 0 ;
return 1 ;
}
static int V_986 ( struct V_1 * V_2 )
{
F_13 ( ! V_2 -> V_5 . V_869 . V_743 ) ;
return F_593 ( V_2 ) ;
}
static int V_987 ( struct V_1 * V_2 )
{
struct V_960 * V_838 = V_2 -> V_838 ;
struct V_836 * V_837 ;
unsigned V_95 ;
F_13 ( ! V_2 -> V_850 ) ;
V_837 = & V_2 -> V_833 [ V_2 -> V_851 ] ;
V_95 = F_336 ( 8u , V_837 -> V_95 ) ;
if ( ! V_2 -> V_853 )
memcpy ( V_837 -> V_38 , V_838 -> V_839 . V_38 , V_95 ) ;
if ( V_837 -> V_95 <= 8 ) {
V_837 ++ ;
V_2 -> V_851 ++ ;
} else {
V_837 -> V_38 += V_95 ;
V_837 -> V_391 += V_95 ;
V_837 -> V_95 -= V_95 ;
}
if ( V_2 -> V_851 >= V_2 -> V_844 ) {
V_2 -> V_850 = 0 ;
if ( V_2 -> V_853 )
return 1 ;
V_2 -> V_832 = 1 ;
return F_593 ( V_2 ) ;
}
V_838 -> V_854 = V_855 ;
V_838 -> V_839 . V_856 = V_837 -> V_391 ;
if ( V_2 -> V_853 )
memcpy ( V_838 -> V_839 . V_38 , V_837 -> V_38 , F_336 ( 8u , V_837 -> V_95 ) ) ;
V_838 -> V_839 . V_95 = F_336 ( 8u , V_837 -> V_95 ) ;
V_838 -> V_839 . V_852 = V_2 -> V_853 ;
V_2 -> V_5 . V_985 = V_987 ;
return 0 ;
}
int F_595 ( struct V_1 * V_2 , struct V_960 * V_960 )
{
struct V_1158 * V_1158 = & V_398 -> V_1159 . V_1158 ;
int V_120 ;
T_18 V_1160 ;
F_596 ( V_1158 ) ;
if ( V_2 -> V_1161 )
F_597 ( V_1162 , & V_2 -> V_1163 , & V_1160 ) ;
if ( F_166 ( V_2 -> V_5 . V_1038 == V_1164 ) ) {
F_586 ( V_2 ) ;
F_567 ( V_2 ) ;
F_176 ( V_1149 , & V_2 -> V_341 ) ;
V_120 = - V_1165 ;
goto V_113;
}
if ( ! F_88 ( V_2 ) ) {
if ( F_87 ( V_2 , V_960 -> V_175 ) != 0 ) {
V_120 = - V_580 ;
goto V_113;
}
}
if ( F_166 ( V_2 -> V_5 . V_985 ) ) {
int (* F_598)( struct V_1 * ) = V_2 -> V_5 . V_985 ;
V_2 -> V_5 . V_985 = NULL ;
V_120 = F_598 ( V_2 ) ;
if ( V_120 <= 0 )
goto V_113;
} else
F_28 ( V_2 -> V_5 . V_869 . V_743 || V_2 -> V_850 ) ;
V_120 = F_588 ( V_2 ) ;
V_113:
F_528 ( V_2 ) ;
if ( V_2 -> V_1161 )
F_597 ( V_1162 , & V_1160 , NULL ) ;
return V_120 ;
}
int F_599 ( struct V_1 * V_2 , struct V_1166 * V_594 )
{
if ( V_2 -> V_5 . V_990 ) {
F_600 ( & V_2 -> V_5 . V_920 ) ;
V_2 -> V_5 . V_990 = false ;
}
V_594 -> V_1167 = F_101 ( V_2 , V_201 ) ;
V_594 -> V_1168 = F_101 ( V_2 , V_1056 ) ;
V_594 -> V_1169 = F_101 ( V_2 , V_200 ) ;
V_594 -> V_1170 = F_101 ( V_2 , V_202 ) ;
V_594 -> V_1171 = F_101 ( V_2 , V_1057 ) ;
V_594 -> V_1172 = F_101 ( V_2 , V_1173 ) ;
V_594 -> V_1174 = F_101 ( V_2 , V_1175 ) ;
V_594 -> V_1176 = F_101 ( V_2 , V_1177 ) ;
#ifdef F_62
V_594 -> V_1178 = F_101 ( V_2 , V_1179 ) ;
V_594 -> V_1180 = F_101 ( V_2 , V_1181 ) ;
V_594 -> V_1182 = F_101 ( V_2 , V_1183 ) ;
V_594 -> V_1184 = F_101 ( V_2 , V_1185 ) ;
V_594 -> V_1186 = F_101 ( V_2 , V_1187 ) ;
V_594 -> V_1188 = F_101 ( V_2 , V_1189 ) ;
V_594 -> V_1190 = F_101 ( V_2 , V_1191 ) ;
V_594 -> V_1192 = F_101 ( V_2 , V_1193 ) ;
#endif
V_594 -> V_1064 = F_442 ( V_2 ) ;
V_594 -> V_959 = F_441 ( V_2 ) ;
return 0 ;
}
int F_601 ( struct V_1 * V_2 , struct V_1166 * V_594 )
{
V_2 -> V_5 . V_934 = true ;
V_2 -> V_5 . V_990 = false ;
F_103 ( V_2 , V_201 , V_594 -> V_1167 ) ;
F_103 ( V_2 , V_1056 , V_594 -> V_1168 ) ;
F_103 ( V_2 , V_200 , V_594 -> V_1169 ) ;
F_103 ( V_2 , V_202 , V_594 -> V_1170 ) ;
F_103 ( V_2 , V_1057 , V_594 -> V_1171 ) ;
F_103 ( V_2 , V_1173 , V_594 -> V_1172 ) ;
F_103 ( V_2 , V_1175 , V_594 -> V_1174 ) ;
F_103 ( V_2 , V_1177 , V_594 -> V_1176 ) ;
#ifdef F_62
F_103 ( V_2 , V_1179 , V_594 -> V_1178 ) ;
F_103 ( V_2 , V_1181 , V_594 -> V_1180 ) ;
F_103 ( V_2 , V_1183 , V_594 -> V_1182 ) ;
F_103 ( V_2 , V_1185 , V_594 -> V_1184 ) ;
F_103 ( V_2 , V_1187 , V_594 -> V_1186 ) ;
F_103 ( V_2 , V_1189 , V_594 -> V_1188 ) ;
F_103 ( V_2 , V_1191 , V_594 -> V_1190 ) ;
F_103 ( V_2 , V_1193 , V_594 -> V_1192 ) ;
#endif
F_446 ( V_2 , V_594 -> V_1064 ) ;
F_447 ( V_2 , V_594 -> V_959 ) ;
V_2 -> V_5 . V_68 . V_69 = false ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
void F_602 ( struct V_1 * V_2 , int * V_181 , int * V_905 )
{
struct V_812 V_1083 ;
F_344 ( V_2 , & V_1083 , V_1088 ) ;
* V_181 = V_1083 . V_181 ;
* V_905 = V_1083 . V_905 ;
}
int F_603 ( struct V_1 * V_2 ,
struct V_1194 * V_1195 )
{
struct V_888 V_889 ;
F_344 ( V_2 , & V_1195 -> V_1083 , V_1088 ) ;
F_344 ( V_2 , & V_1195 -> V_1084 , V_1089 ) ;
F_344 ( V_2 , & V_1195 -> V_1196 , V_1090 ) ;
F_344 ( V_2 , & V_1195 -> V_1197 , V_1091 ) ;
F_344 ( V_2 , & V_1195 -> V_1198 , V_1092 ) ;
F_344 ( V_2 , & V_1195 -> V_1199 , V_1093 ) ;
F_344 ( V_2 , & V_1195 -> V_1200 , V_1081 ) ;
F_344 ( V_2 , & V_1195 -> V_1201 , V_1082 ) ;
V_73 -> V_891 ( V_2 , & V_889 ) ;
V_1195 -> V_1202 . V_900 = V_889 . V_493 ;
V_1195 -> V_1202 . V_228 = V_889 . V_80 ;
V_73 -> V_890 ( V_2 , & V_889 ) ;
V_1195 -> V_1203 . V_900 = V_889 . V_493 ;
V_1195 -> V_1203 . V_228 = V_889 . V_80 ;
V_1195 -> V_121 = F_61 ( V_2 ) ;
V_1195 -> V_79 = V_2 -> V_5 . V_79 ;
V_1195 -> V_104 = F_59 ( V_2 ) ;
V_1195 -> V_158 = F_78 ( V_2 ) ;
V_1195 -> V_175 = F_90 ( V_2 ) ;
V_1195 -> V_131 = V_2 -> V_5 . V_131 ;
V_1195 -> V_31 = F_19 ( V_2 ) ;
memset ( V_1195 -> V_1204 , 0 , sizeof V_1195 -> V_1204 ) ;
if ( V_2 -> V_5 . V_622 . V_69 && ! V_2 -> V_5 . V_622 . V_623 )
F_212 ( V_2 -> V_5 . V_622 . V_16 ,
( unsigned long * ) V_1195 -> V_1204 ) ;
return 0 ;
}
int F_604 ( struct V_1 * V_2 ,
struct V_1205 * V_1038 )
{
F_567 ( V_2 ) ;
if ( V_2 -> V_5 . V_1038 == V_1039 &&
V_2 -> V_5 . V_1150 . V_1151 )
V_1038 -> V_1038 = V_1152 ;
else
V_1038 -> V_1038 = V_2 -> V_5 . V_1038 ;
return 0 ;
}
int F_605 ( struct V_1 * V_2 ,
struct V_1205 * V_1038 )
{
if ( ! F_273 ( V_2 ) &&
V_1038 -> V_1038 != V_1152 )
return - V_580 ;
if ( V_1038 -> V_1038 == V_1206 ) {
V_2 -> V_5 . V_1038 = V_1130 ;
F_212 ( V_1207 , & V_2 -> V_5 . V_595 -> V_648 ) ;
} else
V_2 -> V_5 . V_1038 = V_1038 -> V_1038 ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
int F_606 ( struct V_1 * V_2 , V_865 V_1208 , int V_1209 ,
int V_1210 , bool V_71 , T_1 V_62 )
{
struct V_826 * V_827 = & V_2 -> V_5 . V_920 ;
int V_108 ;
F_440 ( V_2 ) ;
V_108 = F_607 ( V_827 , V_1208 , V_1209 , V_1210 ,
V_71 , V_62 ) ;
if ( V_108 )
return V_939 ;
F_446 ( V_2 , V_827 -> V_923 ) ;
F_447 ( V_2 , V_827 -> V_922 ) ;
F_30 ( V_67 , V_2 ) ;
return V_940 ;
}
int F_608 ( struct V_1 * V_2 ,
struct V_1194 * V_1195 )
{
struct V_32 V_1211 ;
int V_1212 = 0 ;
int V_1213 , V_1214 , V_487 ;
struct V_888 V_889 ;
if ( ! F_79 ( V_2 ) && ( V_1195 -> V_158 & V_141 ) )
return - V_580 ;
V_889 . V_493 = V_1195 -> V_1202 . V_900 ;
V_889 . V_80 = V_1195 -> V_1202 . V_228 ;
V_73 -> V_893 ( V_2 , & V_889 ) ;
V_889 . V_493 = V_1195 -> V_1203 . V_900 ;
V_889 . V_80 = V_1195 -> V_1203 . V_228 ;
V_73 -> V_892 ( V_2 , & V_889 ) ;
V_2 -> V_5 . V_79 = V_1195 -> V_79 ;
V_1212 |= F_59 ( V_2 ) != V_1195 -> V_104 ;
V_2 -> V_5 . V_104 = V_1195 -> V_104 ;
F_54 ( V_173 , ( V_174 * ) & V_2 -> V_5 . V_117 ) ;
F_87 ( V_2 , V_1195 -> V_175 ) ;
V_1212 |= V_2 -> V_5 . V_131 != V_1195 -> V_131 ;
V_73 -> F_107 ( V_2 , V_1195 -> V_131 ) ;
V_1211 . V_38 = V_1195 -> V_31 ;
V_1211 . V_40 = true ;
F_20 ( V_2 , & V_1211 ) ;
V_1212 |= F_61 ( V_2 ) != V_1195 -> V_121 ;
V_73 -> V_137 ( V_2 , V_1195 -> V_121 ) ;
V_2 -> V_5 . V_121 = V_1195 -> V_121 ;
V_1212 |= F_78 ( V_2 ) != V_1195 -> V_158 ;
V_73 -> V_169 ( V_2 , V_1195 -> V_158 ) ;
if ( V_1195 -> V_158 & V_141 )
F_75 ( V_2 ) ;
V_487 = F_228 ( & V_2 -> V_138 -> V_488 ) ;
if ( ! F_56 ( V_2 ) && F_57 ( V_2 ) ) {
F_51 ( V_2 , V_2 -> V_5 . V_103 , F_59 ( V_2 ) ) ;
V_1212 = 1 ;
}
F_229 ( & V_2 -> V_138 -> V_488 , V_487 ) ;
if ( V_1212 )
F_65 ( V_2 ) ;
V_1214 = V_598 ;
V_1213 = F_609 (
( const unsigned long * ) V_1195 -> V_1204 , V_1214 ) ;
if ( V_1213 < V_1214 ) {
F_260 ( V_2 , V_1213 , false ) ;
F_129 ( L_27 , V_1213 ) ;
}
F_343 ( V_2 , & V_1195 -> V_1083 , V_1088 ) ;
F_343 ( V_2 , & V_1195 -> V_1084 , V_1089 ) ;
F_343 ( V_2 , & V_1195 -> V_1196 , V_1090 ) ;
F_343 ( V_2 , & V_1195 -> V_1197 , V_1091 ) ;
F_343 ( V_2 , & V_1195 -> V_1198 , V_1092 ) ;
F_343 ( V_2 , & V_1195 -> V_1199 , V_1093 ) ;
F_343 ( V_2 , & V_1195 -> V_1200 , V_1081 ) ;
F_343 ( V_2 , & V_1195 -> V_1201 , V_1082 ) ;
F_251 ( V_2 ) ;
if ( F_610 ( V_2 ) && F_442 ( V_2 ) == 0xfff0 &&
V_1195 -> V_1083 . V_894 == 0xf000 && V_1195 -> V_1083 . V_228 == 0xffff0000 &&
! F_31 ( V_2 ) )
V_2 -> V_5 . V_1038 = V_1152 ;
F_30 ( V_67 , V_2 ) ;
return 0 ;
}
int F_611 ( struct V_1 * V_2 ,
struct V_1215 * V_1216 )
{
unsigned long V_959 ;
int V_3 , V_120 ;
if ( V_1216 -> V_750 & ( V_1217 | V_1218 ) ) {
V_120 = - V_793 ;
if ( V_2 -> V_5 . V_68 . V_69 )
goto V_113;
if ( V_1216 -> V_750 & V_1217 )
F_32 ( V_2 , V_53 ) ;
else
F_32 ( V_2 , V_54 ) ;
}
V_959 = F_441 ( V_2 ) ;
V_2 -> V_177 = V_1216 -> V_750 ;
if ( ! ( V_2 -> V_177 & V_1219 ) )
V_2 -> V_177 = 0 ;
if ( V_2 -> V_177 & V_178 ) {
for ( V_3 = 0 ; V_3 < V_179 ; ++ V_3 )
V_2 -> V_5 . V_180 [ V_3 ] = V_1216 -> V_5 . V_1220 [ V_3 ] ;
V_2 -> V_5 . V_187 = V_1216 -> V_5 . V_1220 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_179 ; V_3 ++ )
V_2 -> V_5 . V_180 [ V_3 ] = V_2 -> V_5 . V_181 [ V_3 ] ;
}
F_94 ( V_2 ) ;
if ( V_2 -> V_177 & V_962 )
V_2 -> V_5 . V_966 = F_442 ( V_2 ) +
F_391 ( V_2 , V_1088 ) ;
F_447 ( V_2 , V_959 ) ;
V_73 -> V_1221 ( V_2 ) ;
V_120 = 0 ;
V_113:
return V_120 ;
}
int F_612 ( struct V_1 * V_2 ,
struct V_1222 * V_1200 )
{
unsigned long V_1223 = V_1200 -> V_1224 ;
T_6 V_391 ;
int V_487 ;
V_487 = F_228 ( & V_2 -> V_138 -> V_488 ) ;
V_391 = F_349 ( V_2 , V_1223 , NULL ) ;
F_229 ( & V_2 -> V_138 -> V_488 , V_487 ) ;
V_1200 -> V_1225 = V_391 ;
V_1200 -> V_659 = V_391 != V_100 ;
V_1200 -> V_1226 = 1 ;
V_1200 -> V_1227 = 0 ;
return 0 ;
}
int F_613 ( struct V_1 * V_2 , struct V_1228 * V_1158 )
{
struct V_672 * V_671 =
& V_2 -> V_5 . V_654 . V_655 . V_671 ;
memcpy ( V_1158 -> V_1229 , V_671 -> V_1230 , 128 ) ;
V_1158 -> V_1231 = V_671 -> V_1232 ;
V_1158 -> V_1233 = V_671 -> V_1234 ;
V_1158 -> V_1235 = V_671 -> V_1236 ;
V_1158 -> V_1237 = V_671 -> V_1238 ;
V_1158 -> V_1239 = V_671 -> V_1064 ;
V_1158 -> V_1240 = V_671 -> V_1241 ;
memcpy ( V_1158 -> V_1242 , V_671 -> V_1243 , sizeof V_671 -> V_1243 ) ;
return 0 ;
}
int F_614 ( struct V_1 * V_2 , struct V_1228 * V_1158 )
{
struct V_672 * V_671 =
& V_2 -> V_5 . V_654 . V_655 . V_671 ;
memcpy ( V_671 -> V_1230 , V_1158 -> V_1229 , 128 ) ;
V_671 -> V_1232 = V_1158 -> V_1231 ;
V_671 -> V_1234 = V_1158 -> V_1233 ;
V_671 -> V_1236 = V_1158 -> V_1235 ;
V_671 -> V_1238 = V_1158 -> V_1237 ;
V_671 -> V_1064 = V_1158 -> V_1239 ;
V_671 -> V_1241 = V_1158 -> V_1240 ;
memcpy ( V_671 -> V_1243 , V_1158 -> V_1242 , sizeof V_671 -> V_1243 ) ;
return 0 ;
}
static void F_615 ( struct V_1 * V_2 )
{
F_616 ( & V_2 -> V_5 . V_654 . V_655 ) ;
if ( V_665 )
V_2 -> V_5 . V_654 . V_655 . V_653 . V_657 . V_666 =
V_145 | V_667 ;
V_2 -> V_5 . V_144 = V_150 ;
V_2 -> V_5 . V_121 |= V_126 ;
}
void F_429 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1244 )
return;
F_73 ( V_2 ) ;
V_2 -> V_1244 = 1 ;
F_617 () ;
F_618 ( & V_2 -> V_5 . V_654 . V_655 ) ;
F_619 ( 1 ) ;
}
void F_247 ( struct V_1 * V_2 )
{
F_73 ( V_2 ) ;
if ( ! V_2 -> V_1244 ) {
V_2 -> V_1245 = 0 ;
return;
}
V_2 -> V_1244 = 0 ;
F_620 ( & V_2 -> V_5 . V_654 ) ;
F_621 () ;
++ V_2 -> V_77 . V_1246 ;
if ( ! V_2 -> V_5 . V_1247 ) {
if ( ++ V_2 -> V_1245 < 5 )
F_30 ( V_1108 , V_2 ) ;
}
F_619 ( 0 ) ;
}
void F_622 ( struct V_1 * V_2 )
{
F_204 ( V_2 ) ;
F_623 ( V_2 -> V_5 . V_584 ) ;
V_73 -> V_1248 ( V_2 ) ;
}
struct V_1 * F_624 ( struct V_138 * V_138 ,
unsigned int V_1249 )
{
struct V_1 * V_2 ;
if ( F_153 () && F_141 ( & V_138 -> V_295 ) != 0 )
F_385 ( V_867
L_28
L_29 ) ;
V_2 = V_73 -> V_1250 ( V_138 , V_1249 ) ;
return V_2 ;
}
int F_625 ( struct V_1 * V_2 )
{
int V_120 ;
F_626 ( V_2 ) ;
V_120 = V_585 ( V_2 ) ;
if ( V_120 )
return V_120 ;
F_627 ( V_2 , false ) ;
F_628 ( V_2 ) ;
V_589 ( V_2 ) ;
return V_120 ;
}
void F_629 ( struct V_1 * V_2 )
{
struct V_32 V_21 ;
struct V_138 * V_138 = V_2 -> V_138 ;
if ( V_585 ( V_2 ) )
return;
V_21 . V_38 = 0x0 ;
V_21 . V_146 = V_1251 ;
V_21 . V_40 = true ;
F_150 ( V_2 , & V_21 ) ;
V_589 ( V_2 ) ;
if ( ! V_366 )
return;
F_191 ( & V_138 -> V_5 . V_365 ,
V_367 ) ;
}
void F_630 ( struct V_1 * V_2 )
{
int V_120 ;
V_2 -> V_5 . V_6 . V_392 = 0 ;
V_120 = V_585 ( V_2 ) ;
F_13 ( V_120 ) ;
F_561 ( V_2 ) ;
V_589 ( V_2 ) ;
V_73 -> V_1248 ( V_2 ) ;
}
void F_627 ( struct V_1 * V_2 , bool V_1252 )
{
V_2 -> V_5 . V_636 = 0 ;
F_170 ( & V_2 -> V_5 . V_85 , 0 ) ;
V_2 -> V_5 . V_628 = 0 ;
V_2 -> V_5 . V_627 = false ;
F_631 ( V_2 ) ;
F_466 ( V_2 ) ;
memset ( V_2 -> V_5 . V_181 , 0 , sizeof( V_2 -> V_5 . V_181 ) ) ;
F_92 ( V_2 ) ;
V_2 -> V_5 . V_185 = V_1253 ;
F_93 ( V_2 ) ;
V_2 -> V_5 . V_186 = V_197 ;
F_94 ( V_2 ) ;
V_2 -> V_5 . V_79 = 0 ;
F_30 ( V_67 , V_2 ) ;
V_2 -> V_5 . V_6 . V_392 = 0 ;
V_2 -> V_5 . V_396 . V_392 = 0 ;
F_204 ( V_2 ) ;
F_64 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1112 = false ;
if ( ! V_1252 ) {
F_632 ( V_2 ) ;
V_2 -> V_5 . V_427 = 0x30000 ;
}
memset ( V_2 -> V_5 . V_594 , 0 , sizeof( V_2 -> V_5 . V_594 ) ) ;
V_2 -> V_5 . V_117 = ~ 0 ;
V_2 -> V_5 . V_118 = ~ 0 ;
V_73 -> V_1254 ( V_2 , V_1252 ) ;
}
void F_633 ( struct V_1 * V_2 , T_14 V_41 )
{
struct V_812 V_1083 ;
F_344 ( V_2 , & V_1083 , V_1088 ) ;
V_1083 . V_894 = V_41 << 8 ;
V_1083 . V_228 = V_41 << 12 ;
F_343 ( V_2 , & V_1083 , V_1088 ) ;
F_446 ( V_2 , 0 ) ;
}
int F_634 ( void )
{
struct V_138 * V_138 ;
struct V_1 * V_2 ;
int V_3 ;
int V_108 ;
T_2 V_1255 ;
T_2 V_1256 = 0 ;
bool V_1257 , V_1258 = false ;
F_14 () ;
V_108 = V_73 -> V_1259 () ;
if ( V_108 != 0 )
return V_108 ;
V_1255 = F_148 () ;
V_1257 = ! F_153 () ;
F_480 (kvm, &vm_list, vm_list) {
F_175 (i, vcpu, kvm) {
if ( ! V_1257 && V_2 -> V_23 == F_8 () )
F_30 ( V_340 , V_2 ) ;
if ( V_1257 && V_2 -> V_5 . V_588 > V_1255 ) {
V_1258 = true ;
if ( V_2 -> V_5 . V_588 > V_1256 )
V_1256 = V_2 -> V_5 . V_588 ;
}
}
}
if ( V_1258 ) {
T_2 V_1260 = V_1256 - V_1255 ;
V_336 = true ;
F_480 (kvm, &vm_list, vm_list) {
F_175 (i, vcpu, kvm) {
V_2 -> V_5 . V_586 += V_1260 ;
V_2 -> V_5 . V_588 = V_1255 ;
F_30 ( V_298 , V_2 ) ;
}
V_138 -> V_5 . V_314 = 0 ;
V_138 -> V_5 . V_316 = 0 ;
}
}
return 0 ;
}
void F_635 ( void )
{
V_73 -> V_1261 () ;
F_18 () ;
}
int F_636 ( void )
{
int V_120 ;
V_120 = V_73 -> V_1262 () ;
if ( V_120 != 0 )
return V_120 ;
if ( V_273 ) {
T_2 V_1263 = F_336 ( 0x7fffffffULL ,
F_144 ( V_278 , V_274 ) ) ;
V_712 = V_1263 ;
V_272 = 1ULL << V_277 ;
}
F_333 () ;
return 0 ;
}
void F_637 ( void )
{
V_73 -> V_1264 () ;
}
void F_638 ( void * V_1265 )
{
V_73 -> V_1266 ( V_1265 ) ;
}
bool F_639 ( struct V_1 * V_2 )
{
return V_2 -> V_138 -> V_5 . V_794 == V_2 -> V_299 ;
}
bool F_610 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_31 & V_1267 ) != 0 ;
}
bool F_640 ( struct V_1 * V_2 )
{
return F_259 ( V_2 -> V_138 ) == F_88 ( V_2 ) ;
}
int F_641 ( struct V_1 * V_2 )
{
struct V_387 * V_387 ;
struct V_138 * V_138 ;
int V_120 ;
F_13 ( V_2 -> V_138 == NULL ) ;
V_138 = V_2 -> V_138 ;
V_2 -> V_5 . V_592 = V_73 -> V_1268 () ;
V_2 -> V_5 . V_1150 . V_1151 = false ;
V_2 -> V_5 . V_920 . V_841 = & V_1269 ;
if ( ! F_259 ( V_138 ) || F_639 ( V_2 ) )
V_2 -> V_5 . V_1038 = V_1152 ;
else
V_2 -> V_5 . V_1038 = V_1164 ;
V_387 = F_642 ( V_685 | V_1270 ) ;
if ( ! V_387 ) {
V_120 = - V_389 ;
goto V_1271;
}
V_2 -> V_5 . V_873 = F_643 ( V_387 ) ;
F_138 ( V_2 , V_1008 ) ;
V_120 = F_644 ( V_2 ) ;
if ( V_120 < 0 )
goto V_1272;
if ( F_259 ( V_138 ) ) {
V_120 = F_645 ( V_2 ) ;
if ( V_120 < 0 )
goto V_1273;
} else
F_646 ( & V_1274 ) ;
V_2 -> V_5 . V_376 = F_290 ( V_441 * sizeof( T_2 ) * 4 ,
V_685 ) ;
if ( ! V_2 -> V_5 . V_376 ) {
V_120 = - V_389 ;
goto V_1275;
}
V_2 -> V_5 . V_368 = V_441 ;
if ( ! F_647 ( & V_2 -> V_5 . V_584 , V_685 ) ) {
V_120 = - V_389 ;
goto V_1276;
}
F_615 ( V_2 ) ;
V_2 -> V_5 . V_302 = 0x0 ;
V_2 -> V_5 . V_349 = false ;
V_2 -> V_5 . V_153 = 0 ;
V_2 -> V_5 . V_1277 = V_1278 + V_660 ;
V_2 -> V_5 . V_1019 = F_648 ( V_2 ) ;
V_2 -> V_5 . V_1279 = V_1280 ;
F_1 ( V_2 ) ;
F_649 ( V_2 ) ;
V_2 -> V_5 . V_600 = - 1 ;
F_650 ( V_2 ) ;
return 0 ;
V_1276:
F_200 ( V_2 -> V_5 . V_376 ) ;
V_1275:
F_651 ( V_2 ) ;
V_1273:
F_652 ( V_2 ) ;
V_1272:
F_653 ( ( unsigned long ) V_2 -> V_5 . V_873 ) ;
V_1271:
return V_120 ;
}
void F_654 ( struct V_1 * V_2 )
{
int V_487 ;
F_655 ( V_2 ) ;
F_656 ( V_2 ) ;
F_200 ( V_2 -> V_5 . V_376 ) ;
F_651 ( V_2 ) ;
V_487 = F_228 ( & V_2 -> V_138 -> V_488 ) ;
F_652 ( V_2 ) ;
F_229 ( & V_2 -> V_138 -> V_488 , V_487 ) ;
F_653 ( ( unsigned long ) V_2 -> V_5 . V_873 ) ;
if ( ! F_88 ( V_2 ) )
F_657 ( & V_1274 ) ;
}
void F_658 ( struct V_1 * V_2 , int V_23 )
{
V_73 -> V_1281 ( V_2 , V_23 ) ;
}
int F_659 ( struct V_138 * V_138 , unsigned long type )
{
if ( type )
return - V_580 ;
F_660 ( & V_138 -> V_5 . V_1282 ) ;
F_661 ( & V_138 -> V_5 . V_1283 ) ;
F_661 ( & V_138 -> V_5 . V_1284 ) ;
F_661 ( & V_138 -> V_5 . V_1285 ) ;
F_170 ( & V_138 -> V_5 . V_1286 , 0 ) ;
F_212 ( V_758 , & V_138 -> V_5 . V_1287 ) ;
F_212 ( V_1288 ,
& V_138 -> V_5 . V_1287 ) ;
F_662 ( & V_138 -> V_5 . V_313 ) ;
F_663 ( & V_138 -> V_5 . V_1289 ) ;
F_664 ( & V_138 -> V_5 . V_327 ) ;
F_169 ( V_138 ) ;
F_665 ( & V_138 -> V_5 . V_363 , F_187 ) ;
F_665 ( & V_138 -> V_5 . V_365 , F_192 ) ;
return 0 ;
}
static void F_666 ( struct V_1 * V_2 )
{
int V_120 ;
V_120 = V_585 ( V_2 ) ;
F_13 ( V_120 ) ;
F_561 ( V_2 ) ;
V_589 ( V_2 ) ;
}
static void F_667 ( struct V_138 * V_138 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_175 (i, vcpu, kvm) {
F_64 ( V_2 ) ;
F_666 ( V_2 ) ;
}
F_175 (i, vcpu, kvm)
F_622 ( V_2 ) ;
F_299 ( & V_138 -> V_737 ) ;
for ( V_3 = 0 ; V_3 < F_141 ( & V_138 -> V_295 ) ; V_3 ++ )
V_138 -> V_1290 [ V_3 ] = NULL ;
F_170 ( & V_138 -> V_295 , 0 ) ;
F_301 ( & V_138 -> V_737 ) ;
}
void F_668 ( struct V_138 * V_138 )
{
F_669 ( & V_138 -> V_5 . V_365 ) ;
F_669 ( & V_138 -> V_5 . V_363 ) ;
F_670 ( V_138 ) ;
F_671 ( V_138 ) ;
}
int F_672 ( struct V_138 * V_138 , int V_1249 , T_6 V_391 , T_1 V_493 )
{
int V_3 , V_120 ;
unsigned long V_1291 ;
struct V_1292 * V_1293 = V_1292 ( V_138 ) ;
struct V_1294 * V_10 , V_860 ;
if ( F_28 ( V_1249 >= V_1295 ) )
return - V_580 ;
V_10 = F_673 ( V_1293 , V_1249 ) ;
if ( V_493 ) {
if ( F_28 ( V_10 -> V_1296 ) )
return - V_601 ;
V_1291 = F_674 ( NULL , 0 , V_493 , V_1297 | V_1298 ,
V_1299 | V_1300 , 0 ) ;
if ( F_197 ( ( void * ) V_1291 ) )
return F_198 ( ( void * ) V_1291 ) ;
} else {
if ( ! V_10 -> V_1296 )
return 0 ;
V_1291 = 0 ;
}
V_860 = * V_10 ;
for ( V_3 = 0 ; V_3 < V_1301 ; V_3 ++ ) {
struct V_1302 V_1303 ;
V_1303 . V_10 = V_1249 | ( V_3 << 16 ) ;
V_1303 . V_309 = 0 ;
V_1303 . V_1304 = V_391 ;
V_1303 . V_1305 = V_1291 ;
V_1303 . V_1306 = V_493 ;
V_120 = F_675 ( V_138 , & V_1303 ) ;
if ( V_120 < 0 )
return V_120 ;
}
if ( ! V_493 ) {
V_120 = F_676 ( V_860 . V_1305 , V_860 . V_1296 * V_107 ) ;
F_28 ( V_120 < 0 ) ;
}
return 0 ;
}
int F_677 ( struct V_138 * V_138 , int V_1249 , T_6 V_391 , T_1 V_493 )
{
int V_120 ;
F_299 ( & V_138 -> V_724 ) ;
V_120 = F_672 ( V_138 , V_1249 , V_391 , V_493 ) ;
F_301 ( & V_138 -> V_724 ) ;
return V_120 ;
}
void F_678 ( struct V_138 * V_138 )
{
if ( V_398 -> V_1307 == V_138 -> V_1307 ) {
F_677 ( V_138 , V_1308 , 0 , 0 ) ;
F_677 ( V_138 , V_1309 , 0 , 0 ) ;
F_677 ( V_138 , V_1310 , 0 , 0 ) ;
}
F_679 ( V_138 ) ;
F_200 ( V_138 -> V_5 . V_775 ) ;
F_200 ( V_138 -> V_5 . V_1311 ) ;
F_667 ( V_138 ) ;
F_200 ( F_680 ( V_138 -> V_5 . V_1312 , 1 ) ) ;
}
void F_681 ( struct V_138 * V_138 , struct V_1294 * free ,
struct V_1294 * V_1313 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1314 ; ++ V_3 ) {
if ( ! V_1313 || free -> V_5 . V_1315 [ V_3 ] != V_1313 -> V_5 . V_1315 [ V_3 ] ) {
F_682 ( free -> V_5 . V_1315 [ V_3 ] ) ;
free -> V_5 . V_1315 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1313 || free -> V_5 . V_1316 [ V_3 - 1 ] !=
V_1313 -> V_5 . V_1316 [ V_3 - 1 ] ) {
F_682 ( free -> V_5 . V_1316 [ V_3 - 1 ] ) ;
free -> V_5 . V_1316 [ V_3 - 1 ] = NULL ;
}
}
}
int F_683 ( struct V_138 * V_138 , struct V_1294 * V_10 ,
unsigned long V_1296 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1314 ; ++ V_3 ) {
unsigned long V_1317 ;
int V_1318 ;
int V_759 = V_3 + 1 ;
V_1318 = F_684 ( V_10 -> V_1319 + V_1296 - 1 ,
V_10 -> V_1319 , V_759 ) + 1 ;
V_10 -> V_5 . V_1315 [ V_3 ] =
F_685 ( V_1318 * sizeof( * V_10 -> V_5 . V_1315 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1315 [ V_3 ] )
goto V_390;
if ( V_3 == 0 )
continue;
V_10 -> V_5 . V_1316 [ V_3 - 1 ] = F_685 ( V_1318 *
sizeof( * V_10 -> V_5 . V_1316 [ V_3 - 1 ] ) ) ;
if ( ! V_10 -> V_5 . V_1316 [ V_3 - 1 ] )
goto V_390;
if ( V_10 -> V_1319 & ( F_686 ( V_759 ) - 1 ) )
V_10 -> V_5 . V_1316 [ V_3 - 1 ] [ 0 ] . V_1320 = 1 ;
if ( ( V_10 -> V_1319 + V_1296 ) & ( F_686 ( V_759 ) - 1 ) )
V_10 -> V_5 . V_1316 [ V_3 - 1 ] [ V_1318 - 1 ] . V_1320 = 1 ;
V_1317 = V_10 -> V_1305 >> V_106 ;
if ( ( V_10 -> V_1319 ^ V_1317 ) & ( F_686 ( V_759 ) - 1 ) ||
! F_687 () ) {
unsigned long V_803 ;
for ( V_803 = 0 ; V_803 < V_1318 ; ++ V_803 )
V_10 -> V_5 . V_1316 [ V_3 - 1 ] [ V_803 ] . V_1320 = 1 ;
}
}
return 0 ;
V_390:
for ( V_3 = 0 ; V_3 < V_1314 ; ++ V_3 ) {
F_682 ( V_10 -> V_5 . V_1315 [ V_3 ] ) ;
V_10 -> V_5 . V_1315 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_682 ( V_10 -> V_5 . V_1316 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1316 [ V_3 - 1 ] = NULL ;
}
return - V_389 ;
}
void F_688 ( struct V_138 * V_138 , struct V_1292 * V_1293 )
{
F_689 ( V_138 , V_1293 ) ;
}
int F_690 ( struct V_138 * V_138 ,
struct V_1294 * V_1321 ,
const struct V_1302 * V_1322 ,
enum V_1323 V_1324 )
{
return 0 ;
}
static void F_691 ( struct V_138 * V_138 ,
struct V_1294 * V_861 )
{
if ( V_861 -> V_309 & V_1325 ) {
F_692 ( V_138 , V_861 ) ;
return;
}
if ( V_861 -> V_309 & V_1326 ) {
if ( V_73 -> V_1327 )
V_73 -> V_1327 ( V_138 , V_861 ) ;
else
F_692 ( V_138 , V_861 ) ;
} else {
if ( V_73 -> V_1328 )
V_73 -> V_1328 ( V_138 , V_861 ) ;
}
}
void F_693 ( struct V_138 * V_138 ,
const struct V_1302 * V_1322 ,
const struct V_1294 * V_860 ,
const struct V_1294 * V_861 ,
enum V_1323 V_1324 )
{
int V_1329 = 0 ;
if ( ! V_138 -> V_5 . V_725 )
V_1329 = F_694 ( V_138 ) ;
if ( V_1329 )
F_300 ( V_138 , V_1329 ) ;
if ( ( V_1324 != V_1330 ) &&
( V_860 -> V_309 & V_1326 ) &&
! ( V_861 -> V_309 & V_1326 ) )
F_695 ( V_138 , V_861 ) ;
if ( V_1324 != V_1330 )
F_691 ( V_138 , (struct V_1294 * ) V_861 ) ;
}
void F_696 ( struct V_138 * V_138 )
{
F_697 ( V_138 ) ;
}
void F_698 ( struct V_138 * V_138 ,
struct V_1294 * V_10 )
{
F_697 ( V_138 ) ;
}
static inline bool F_699 ( struct V_1 * V_2 )
{
if ( ! F_700 ( & V_2 -> V_1331 . V_1332 ) )
return true ;
if ( F_701 ( V_2 ) )
return true ;
if ( V_2 -> V_5 . V_1150 . V_1151 )
return true ;
if ( F_141 ( & V_2 -> V_5 . V_85 ) )
return true ;
if ( F_58 ( V_602 , & V_2 -> V_341 ) )
return true ;
if ( F_255 ( V_2 ) &&
F_256 ( V_2 ) )
return true ;
if ( F_702 ( V_2 ) )
return true ;
return false ;
}
int F_585 ( struct V_1 * V_2 )
{
if ( F_450 ( V_2 ) && V_73 -> V_1077 )
V_73 -> V_1077 ( V_2 , false ) ;
return F_587 ( V_2 ) || F_699 ( V_2 ) ;
}
int F_703 ( struct V_1 * V_2 )
{
return F_704 ( V_2 ) == V_1135 ;
}
int F_255 ( struct V_1 * V_2 )
{
return V_73 -> V_1079 ( V_2 ) ;
}
unsigned long F_464 ( struct V_1 * V_2 )
{
if ( F_525 ( V_2 ) )
return F_442 ( V_2 ) ;
return ( T_1 ) ( F_391 ( V_2 , V_1088 ) +
F_442 ( V_2 ) ) ;
}
bool F_705 ( struct V_1 * V_2 , unsigned long V_1333 )
{
return F_464 ( V_2 ) == V_1333 ;
}
unsigned long F_441 ( struct V_1 * V_2 )
{
unsigned long V_959 ;
V_959 = V_73 -> V_989 ( V_2 ) ;
if ( V_2 -> V_177 & V_962 )
V_959 &= ~ V_961 ;
return V_959 ;
}
static void F_471 ( struct V_1 * V_2 , unsigned long V_959 )
{
if ( V_2 -> V_177 & V_962 &&
F_705 ( V_2 , V_2 -> V_5 . V_966 ) )
V_959 |= V_961 ;
V_73 -> V_1334 ( V_2 , V_959 ) ;
}
void F_447 ( struct V_1 * V_2 , unsigned long V_959 )
{
F_471 ( V_2 , V_959 ) ;
F_30 ( V_67 , V_2 ) ;
}
void F_706 ( struct V_1 * V_2 , struct V_1335 * V_360 )
{
int V_120 ;
if ( ( V_2 -> V_5 . V_84 . V_951 != V_360 -> V_5 . V_951 ) ||
V_360 -> V_1336 )
return;
V_120 = F_569 ( V_2 ) ;
if ( F_166 ( V_120 ) )
return;
if ( ! V_2 -> V_5 . V_84 . V_951 &&
V_360 -> V_5 . V_104 != V_2 -> V_5 . V_84 . V_1337 ( V_2 ) )
return;
V_2 -> V_5 . V_84 . V_1338 ( V_2 , V_360 -> V_819 , 0 , true ) ;
}
static inline T_1 F_707 ( T_5 V_102 )
{
return F_708 ( V_102 & 0xffffffff , F_709 ( V_4 ) ) ;
}
static inline T_1 F_710 ( T_1 V_1339 )
{
return ( V_1339 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_711 ( struct V_1 * V_2 , T_5 V_102 )
{
T_1 V_1339 = F_707 ( V_102 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1339 ] != ~ 0 )
V_1339 = F_710 ( V_1339 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1339 ] = V_102 ;
}
static T_1 F_712 ( struct V_1 * V_2 , T_5 V_102 )
{
int V_3 ;
T_1 V_1339 = F_707 ( V_102 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1339 ] != V_102 &&
V_2 -> V_5 . V_6 . V_7 [ V_1339 ] != ~ 0 ) ; V_3 ++ )
V_1339 = F_710 ( V_1339 ) ;
return V_1339 ;
}
bool F_713 ( struct V_1 * V_2 , T_5 V_102 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_712 ( V_2 , V_102 ) ] == V_102 ;
}
static void F_714 ( struct V_1 * V_2 , T_5 V_102 )
{
T_1 V_3 , V_803 , V_1340 ;
V_3 = V_803 = F_712 ( V_2 , V_102 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_803 = F_710 ( V_803 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_803 ] == ~ 0 )
return;
V_1340 = F_707 ( V_2 -> V_5 . V_6 . V_7 [ V_803 ] ) ;
} while ( ( V_3 <= V_803 ) ? ( V_3 < V_1340 && V_1340 <= V_803 ) : ( V_3 < V_1340 || V_1340 <= V_803 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_803 ] ;
V_3 = V_803 ;
}
}
static int F_715 ( struct V_1 * V_2 , T_1 V_194 )
{
return F_184 ( V_2 -> V_138 , & V_2 -> V_5 . V_6 . V_38 , & V_194 ,
sizeof( V_194 ) ) ;
}
void F_716 ( struct V_1 * V_2 ,
struct V_1335 * V_360 )
{
struct V_75 V_76 ;
F_717 ( V_360 -> V_5 . V_1341 , V_360 -> V_819 ) ;
F_711 ( V_2 , V_360 -> V_5 . V_102 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_392 & V_393 ) ||
( V_2 -> V_5 . V_6 . V_394 &&
V_73 -> V_88 ( V_2 ) == 0 ) )
F_30 ( V_1111 , V_2 ) ;
else if ( ! F_715 ( V_2 , V_1342 ) ) {
V_76 . V_41 = V_42 ;
V_76 . V_921 = true ;
V_76 . V_62 = 0 ;
V_76 . V_81 = false ;
V_76 . V_80 = V_360 -> V_5 . V_1341 ;
F_36 ( V_2 , & V_76 ) ;
}
}
void F_718 ( struct V_1 * V_2 ,
struct V_1335 * V_360 )
{
struct V_75 V_76 ;
F_719 ( V_360 -> V_5 . V_1341 , V_360 -> V_819 ) ;
if ( V_360 -> V_1336 )
V_360 -> V_5 . V_1341 = ~ 0 ;
else
F_714 ( V_2 , V_360 -> V_5 . V_102 ) ;
if ( ( V_2 -> V_5 . V_6 . V_392 & V_393 ) &&
! F_715 ( V_2 , V_1343 ) ) {
V_76 . V_41 = V_42 ;
V_76 . V_921 = true ;
V_76 . V_62 = 0 ;
V_76 . V_81 = false ;
V_76 . V_80 = V_360 -> V_5 . V_1341 ;
F_36 ( V_2 , & V_76 ) ;
}
V_2 -> V_5 . V_6 . V_1112 = false ;
V_2 -> V_5 . V_1038 = V_1152 ;
}
bool F_720 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_392 & V_393 ) )
return true ;
else
return ! F_257 ( V_2 ) &&
V_73 -> V_1079 ( V_2 ) ;
}
void F_721 ( struct V_138 * V_138 )
{
F_41 ( & V_138 -> V_5 . V_1344 ) ;
}
void F_722 ( struct V_138 * V_138 )
{
F_723 ( & V_138 -> V_5 . V_1344 ) ;
}
bool F_724 ( struct V_138 * V_138 )
{
return F_141 ( & V_138 -> V_5 . V_1344 ) ;
}
void F_725 ( struct V_138 * V_138 )
{
F_41 ( & V_138 -> V_5 . V_1286 ) ;
}
void F_726 ( struct V_138 * V_138 )
{
F_723 ( & V_138 -> V_5 . V_1286 ) ;
}
bool F_66 ( struct V_138 * V_138 )
{
return F_141 ( & V_138 -> V_5 . V_1286 ) ;
}
int F_727 ( struct V_1345 * V_1346 ,
struct V_1347 * V_1348 )
{
struct V_1349 * V_1350 =
F_4 ( V_1346 , struct V_1349 , V_1351 ) ;
if ( V_73 -> V_1352 ) {
V_1350 -> V_1353 = V_1348 ;
return V_73 -> V_1352 ( V_1350 -> V_138 ,
V_1348 -> V_597 , V_1350 -> V_1354 , 1 ) ;
}
return - V_580 ;
}
void F_728 ( struct V_1345 * V_1346 ,
struct V_1347 * V_1348 )
{
int V_108 ;
struct V_1349 * V_1350 =
F_4 ( V_1346 , struct V_1349 , V_1351 ) ;
if ( ! V_73 -> V_1352 ) {
F_28 ( V_1350 -> V_1353 != NULL ) ;
return;
}
F_28 ( V_1350 -> V_1353 != V_1348 ) ;
V_1350 -> V_1353 = NULL ;
V_108 = V_73 -> V_1352 ( V_1350 -> V_138 , V_1348 -> V_597 , V_1350 -> V_1354 , 0 ) ;
if ( V_108 )
F_10 ( V_1355 L_30
L_31 , V_1350 -> V_1351 . V_1341 , V_108 ) ;
}
int F_729 ( struct V_138 * V_138 , unsigned int V_1356 ,
T_7 V_1357 , bool V_1358 )
{
if ( ! V_73 -> V_1352 )
return - V_580 ;
return V_73 -> V_1352 ( V_138 , V_1356 , V_1357 , V_1358 ) ;
}
