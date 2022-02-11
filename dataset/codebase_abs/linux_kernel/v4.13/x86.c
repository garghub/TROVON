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
T_2 V_40 = ( ( ~ 0ULL ) << F_23 ( V_2 ) ) |
0x2ff | ( F_24 ( V_2 ) ? 0 : V_37 ) ;
if ( ! V_34 -> V_41 &&
( ( V_34 -> V_39 & V_40 ) != 0 ||
V_38 == V_37 ||
( V_38 == V_36 &&
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
static int F_28 ( int V_42 )
{
switch ( V_42 ) {
case V_43 :
return V_44 ;
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
return V_50 ;
default:
break;
}
return V_51 ;
}
static int F_29 ( int V_42 )
{
unsigned int V_29 ;
if ( F_30 ( V_42 > 31 || V_42 == V_52 ) )
return V_53 ;
V_29 = 1 << V_42 ;
if ( V_29 & ( ( 1 << V_54 ) | ( 1 << V_55 ) | ( 1 << V_56 ) ) )
return V_57 ;
if ( V_29 & ( ( 1 << V_58 ) | ( 1 << V_59 ) ) )
return V_60 ;
return V_61 ;
}
static void F_31 ( struct V_1 * V_2 ,
unsigned V_18 , bool V_62 , T_1 V_63 ,
bool V_64 )
{
T_1 V_65 ;
int V_66 , V_67 ;
F_32 ( V_68 , V_2 ) ;
if ( ! V_2 -> V_5 . V_69 . V_70 ) {
V_71:
if ( V_62 && ! F_33 ( V_2 ) )
V_62 = false ;
V_2 -> V_5 . V_69 . V_70 = true ;
V_2 -> V_5 . V_69 . V_72 = V_62 ;
V_2 -> V_5 . V_69 . V_18 = V_18 ;
V_2 -> V_5 . V_69 . V_63 = V_63 ;
V_2 -> V_5 . V_69 . V_64 = V_64 ;
return;
}
V_65 = V_2 -> V_5 . V_69 . V_18 ;
if ( V_65 == V_58 ) {
F_32 ( V_73 , V_2 ) ;
return;
}
V_66 = F_28 ( V_65 ) ;
V_67 = F_28 ( V_18 ) ;
if ( ( V_66 == V_50 && V_67 == V_50 )
|| ( V_66 == V_44 && V_67 != V_51 ) ) {
V_2 -> V_5 . V_69 . V_70 = true ;
V_2 -> V_5 . V_69 . V_72 = true ;
V_2 -> V_5 . V_69 . V_18 = V_58 ;
V_2 -> V_5 . V_69 . V_63 = 0 ;
} else
goto V_71;
}
void F_34 ( struct V_1 * V_2 , unsigned V_18 )
{
F_31 ( V_2 , V_18 , false , 0 , false ) ;
}
void F_35 ( struct V_1 * V_2 , unsigned V_18 )
{
F_31 ( V_2 , V_18 , false , 0 , true ) ;
}
int F_36 ( struct V_1 * V_2 , int V_30 )
{
if ( V_30 )
F_37 ( V_2 , 0 ) ;
else
return F_38 ( V_2 ) ;
return 1 ;
}
void F_39 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
++ V_2 -> V_76 . V_77 ;
V_2 -> V_5 . V_69 . V_78 =
F_40 ( V_2 ) && V_75 -> V_79 ;
if ( V_2 -> V_5 . V_69 . V_78 )
V_2 -> V_5 . V_6 . V_80 = V_75 -> V_81 ;
else
V_2 -> V_5 . V_82 = V_75 -> V_81 ;
F_41 ( V_2 , V_43 , V_75 -> V_63 ) ;
}
static bool F_42 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
if ( F_43 ( V_2 ) && ! V_75 -> V_83 )
V_2 -> V_5 . V_84 . V_85 ( V_2 , V_75 ) ;
else
V_2 -> V_5 . V_86 . V_85 ( V_2 , V_75 ) ;
return V_75 -> V_83 ;
}
void F_44 ( struct V_1 * V_2 )
{
F_45 ( & V_2 -> V_5 . V_87 ) ;
F_32 ( V_88 , V_2 ) ;
}
void F_41 ( struct V_1 * V_2 , unsigned V_18 , T_1 V_63 )
{
F_31 ( V_2 , V_18 , true , V_63 , false ) ;
}
void F_46 ( struct V_1 * V_2 , unsigned V_18 , T_1 V_63 )
{
F_31 ( V_2 , V_18 , true , V_63 , true ) ;
}
bool F_47 ( struct V_1 * V_2 , int V_89 )
{
if ( V_90 -> V_91 ( V_2 ) <= V_89 )
return true ;
F_41 ( V_2 , V_49 , 0 ) ;
return false ;
}
bool F_48 ( struct V_1 * V_2 , int V_92 )
{
if ( ( V_92 != 4 && V_92 != 5 ) || ! F_49 ( V_2 , V_93 ) )
return true ;
F_34 ( V_2 , V_94 ) ;
return false ;
}
int F_50 ( struct V_1 * V_2 , struct V_95 * V_86 ,
T_5 V_96 , void * V_39 , int V_97 , int V_98 ,
T_1 V_99 )
{
struct V_74 V_69 ;
T_5 V_100 ;
T_6 V_101 ;
V_101 = F_51 ( V_96 ) ;
V_100 = V_86 -> V_102 ( V_2 , V_101 , V_99 , & V_69 ) ;
if ( V_100 == V_103 )
return - V_104 ;
V_100 = F_52 ( V_100 ) ;
return F_53 ( V_2 , V_100 , V_39 , V_97 , V_98 ) ;
}
static int F_54 ( struct V_1 * V_2 , T_5 V_105 ,
void * V_39 , int V_97 , int V_98 , T_1 V_99 )
{
return F_50 ( V_2 , V_2 -> V_5 . V_106 , V_105 ,
V_39 , V_97 , V_98 , V_99 ) ;
}
int F_55 ( struct V_1 * V_2 , struct V_95 * V_86 , unsigned long V_107 )
{
T_5 V_108 = V_107 >> V_109 ;
unsigned V_97 = ( ( V_107 & ( V_110 - 1 ) ) >> 5 ) << 2 ;
int V_3 ;
int V_111 ;
T_2 V_112 [ F_56 ( V_86 -> V_113 ) ] ;
V_111 = F_50 ( V_2 , V_86 , V_108 , V_112 ,
V_97 * sizeof( T_2 ) , sizeof( V_112 ) ,
V_114 | V_115 ) ;
if ( V_111 < 0 ) {
V_111 = 0 ;
goto V_116;
}
for ( V_3 = 0 ; V_3 < F_56 ( V_112 ) ; ++ V_3 ) {
if ( ( V_112 [ V_3 ] & V_117 ) &&
( V_112 [ V_3 ] &
V_2 -> V_5 . V_86 . V_118 . V_119 [ 0 ] [ 2 ] ) ) {
V_111 = 0 ;
goto V_116;
}
}
V_111 = 1 ;
memcpy ( V_86 -> V_113 , V_112 , sizeof( V_86 -> V_113 ) ) ;
F_57 ( V_120 ,
( unsigned long * ) & V_2 -> V_5 . V_121 ) ;
F_57 ( V_120 ,
( unsigned long * ) & V_2 -> V_5 . V_122 ) ;
V_116:
return V_111 ;
}
bool F_58 ( struct V_1 * V_2 )
{
T_2 V_112 [ F_56 ( V_2 -> V_5 . V_106 -> V_113 ) ] ;
bool V_123 = true ;
int V_97 ;
T_5 V_105 ;
int V_124 ;
if ( F_59 ( V_2 ) || ! F_60 ( V_2 ) )
return false ;
if ( ! F_61 ( V_120 ,
( unsigned long * ) & V_2 -> V_5 . V_121 ) )
return true ;
V_105 = ( F_62 ( V_2 ) & 0xffffffe0ul ) >> V_109 ;
V_97 = ( F_62 ( V_2 ) & 0xffffffe0ul ) & ( V_110 - 1 ) ;
V_124 = F_54 ( V_2 , V_105 , V_112 , V_97 , sizeof( V_112 ) ,
V_114 | V_115 ) ;
if ( V_124 < 0 )
goto V_116;
V_123 = memcmp ( V_112 , V_2 -> V_5 . V_106 -> V_113 , sizeof( V_112 ) ) != 0 ;
V_116:
return V_123 ;
}
int F_63 ( struct V_1 * V_2 , unsigned long V_125 )
{
unsigned long V_126 = F_64 ( V_2 ) ;
unsigned long V_127 = V_128 | V_129 ;
V_125 |= V_130 ;
#ifdef F_65
if ( V_125 & 0xffffffff00000000UL )
return 1 ;
#endif
V_125 &= ~ V_131 ;
if ( ( V_125 & V_132 ) && ! ( V_125 & V_133 ) )
return 1 ;
if ( ( V_125 & V_128 ) && ! ( V_125 & V_134 ) )
return 1 ;
if ( ! F_66 ( V_2 ) && ( V_125 & V_128 ) ) {
#ifdef F_65
if ( ( V_2 -> V_5 . V_135 & V_136 ) ) {
int V_137 , V_138 ;
if ( ! F_60 ( V_2 ) )
return 1 ;
V_90 -> V_139 ( V_2 , & V_137 , & V_138 ) ;
if ( V_138 )
return 1 ;
} else
#endif
if ( F_60 ( V_2 ) && ! F_55 ( V_2 , V_2 -> V_5 . V_106 ,
F_62 ( V_2 ) ) )
return 1 ;
}
if ( ! ( V_125 & V_128 ) && F_49 ( V_2 , V_140 ) )
return 1 ;
V_90 -> V_141 ( V_2 , V_125 ) ;
if ( ( V_125 ^ V_126 ) & V_128 ) {
F_67 ( V_2 ) ;
F_1 ( V_2 ) ;
}
if ( ( V_125 ^ V_126 ) & V_127 )
F_68 ( V_2 ) ;
if ( ( ( V_125 ^ V_126 ) & V_133 ) &&
F_69 ( V_2 -> V_142 ) &&
! F_70 ( V_2 -> V_142 , V_143 ) )
F_71 ( V_2 -> V_142 , 0 , ~ 0ULL ) ;
return 0 ;
}
void F_72 ( struct V_1 * V_2 , unsigned long V_144 )
{
( void ) F_63 ( V_2 , F_73 ( V_2 , ~ 0x0eul ) | ( V_144 & 0x0f ) ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
if ( F_49 ( V_2 , V_145 ) &&
! V_2 -> V_146 ) {
F_75 ( V_147 , V_2 -> V_5 . V_148 ) ;
V_2 -> V_146 = 1 ;
}
}
static void F_76 ( struct V_1 * V_2 )
{
if ( V_2 -> V_146 ) {
if ( V_2 -> V_5 . V_148 != V_149 )
F_75 ( V_147 , V_149 ) ;
V_2 -> V_146 = 0 ;
}
}
static int F_77 ( struct V_1 * V_2 , T_1 V_150 , T_2 V_151 )
{
T_2 V_148 = V_151 ;
T_2 V_152 = V_2 -> V_5 . V_148 ;
T_2 V_153 ;
if ( V_150 != V_147 )
return 1 ;
if ( ! ( V_148 & V_154 ) )
return 1 ;
if ( ( V_148 & V_155 ) && ! ( V_148 & V_156 ) )
return 1 ;
V_153 = V_2 -> V_5 . V_157 | V_154 ;
if ( V_148 & ~ V_153 )
return 1 ;
if ( ( ! ( V_148 & V_158 ) ) !=
( ! ( V_148 & V_159 ) ) )
return 1 ;
if ( V_148 & V_160 ) {
if ( ! ( V_148 & V_155 ) )
return 1 ;
if ( ( V_148 & V_160 ) != V_160 )
return 1 ;
}
V_2 -> V_5 . V_148 = V_148 ;
if ( ( V_148 ^ V_152 ) & V_161 )
F_78 ( V_2 ) ;
return 0 ;
}
int F_79 ( struct V_1 * V_2 , T_1 V_150 , T_2 V_151 )
{
if ( V_90 -> V_91 ( V_2 ) != 0 ||
F_77 ( V_2 , V_150 , V_151 ) ) {
F_37 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_80 ( struct V_1 * V_2 , unsigned long V_162 )
{
unsigned long V_163 = F_81 ( V_2 ) ;
unsigned long V_164 = V_165 | V_166 | V_167 |
V_168 | V_169 | V_170 ;
if ( V_162 & V_171 )
return 1 ;
if ( ! F_82 ( V_2 ) && ( V_162 & V_145 ) )
return 1 ;
if ( ! F_83 ( V_2 ) && ( V_162 & V_168 ) )
return 1 ;
if ( ! F_84 ( V_2 ) && ( V_162 & V_169 ) )
return 1 ;
if ( ! F_85 ( V_2 ) && ( V_162 & V_172 ) )
return 1 ;
if ( ! F_86 ( V_2 ) && ( V_162 & V_170 ) )
return 1 ;
if ( F_59 ( V_2 ) ) {
if ( ! ( V_162 & V_167 ) )
return 1 ;
} else if ( F_66 ( V_2 ) && ( V_162 & V_167 )
&& ( ( V_162 ^ V_163 ) & V_164 )
&& ! F_55 ( V_2 , V_2 -> V_5 . V_106 ,
F_62 ( V_2 ) ) )
return 1 ;
if ( ( V_162 & V_140 ) && ! ( V_163 & V_140 ) ) {
if ( ! F_87 ( V_2 ) )
return 1 ;
if ( ( F_62 ( V_2 ) & V_173 ) || ! F_59 ( V_2 ) )
return 1 ;
}
if ( V_90 -> V_174 ( V_2 , V_162 ) )
return 1 ;
if ( ( ( V_162 ^ V_163 ) & V_164 ) ||
( ! ( V_162 & V_140 ) && ( V_163 & V_140 ) ) )
F_68 ( V_2 ) ;
if ( ( V_162 ^ V_163 ) & ( V_145 | V_170 ) )
F_78 ( V_2 ) ;
return 0 ;
}
int F_88 ( struct V_1 * V_2 , unsigned long V_107 )
{
#ifdef F_65
V_107 &= ~ V_175 ;
#endif
if ( V_107 == F_62 ( V_2 ) && ! F_58 ( V_2 ) ) {
F_89 ( V_2 ) ;
F_32 ( V_176 , V_2 ) ;
return 0 ;
}
if ( F_59 ( V_2 ) ) {
if ( V_107 & V_177 )
return 1 ;
} else if ( F_60 ( V_2 ) && F_66 ( V_2 ) &&
! F_55 ( V_2 , V_2 -> V_5 . V_106 , V_107 ) )
return 1 ;
V_2 -> V_5 . V_107 = V_107 ;
F_57 ( V_178 , ( V_179 * ) & V_2 -> V_5 . V_121 ) ;
F_90 ( V_2 ) ;
return 0 ;
}
int F_91 ( struct V_1 * V_2 , unsigned long V_180 )
{
if ( V_180 & V_181 )
return 1 ;
if ( F_92 ( V_2 ) )
F_93 ( V_2 , V_180 ) ;
else
V_2 -> V_5 . V_180 = V_180 ;
return 0 ;
}
unsigned long F_94 ( struct V_1 * V_2 )
{
if ( F_92 ( V_2 ) )
return F_95 ( V_2 ) ;
else
return V_2 -> V_5 . V_180 ;
}
static void F_96 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! ( V_2 -> V_182 & V_183 ) ) {
for ( V_3 = 0 ; V_3 < V_184 ; V_3 ++ )
V_2 -> V_5 . V_185 [ V_3 ] = V_2 -> V_5 . V_186 [ V_3 ] ;
V_2 -> V_5 . V_187 |= V_188 ;
}
}
static void F_97 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_182 & V_183 ) )
V_90 -> V_189 ( V_2 , V_2 -> V_5 . V_190 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
unsigned long V_191 ;
if ( V_2 -> V_182 & V_183 )
V_191 = V_2 -> V_5 . V_192 ;
else
V_191 = V_2 -> V_5 . V_191 ;
V_90 -> V_193 ( V_2 , V_191 ) ;
V_2 -> V_5 . V_187 &= ~ V_194 ;
if ( V_191 & V_195 )
V_2 -> V_5 . V_187 |= V_194 ;
}
static T_2 F_99 ( struct V_1 * V_2 )
{
T_2 V_196 = V_197 ;
if ( ! F_100 ( V_2 ) )
V_196 |= V_198 ;
return V_196 ;
}
static int F_101 ( struct V_1 * V_2 , int V_92 , unsigned long V_199 )
{
switch ( V_92 ) {
case 0 ... 3 :
V_2 -> V_5 . V_186 [ V_92 ] = V_199 ;
if ( ! ( V_2 -> V_182 & V_183 ) )
V_2 -> V_5 . V_185 [ V_92 ] = V_199 ;
break;
case 4 :
case 6 :
if ( V_199 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_190 = ( V_199 & V_200 ) | F_99 ( V_2 ) ;
F_97 ( V_2 ) ;
break;
case 5 :
default:
if ( V_199 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_191 = ( V_199 & V_201 ) | V_202 ;
F_98 ( V_2 ) ;
break;
}
return 0 ;
}
int F_102 ( struct V_1 * V_2 , int V_92 , unsigned long V_199 )
{
if ( F_101 ( V_2 , V_92 , V_199 ) ) {
F_37 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_103 ( struct V_1 * V_2 , int V_92 , unsigned long * V_199 )
{
switch ( V_92 ) {
case 0 ... 3 :
* V_199 = V_2 -> V_5 . V_186 [ V_92 ] ;
break;
case 4 :
case 6 :
if ( V_2 -> V_182 & V_183 )
* V_199 = V_2 -> V_5 . V_190 ;
else
* V_199 = V_90 -> V_203 ( V_2 ) ;
break;
case 5 :
default:
* V_199 = V_2 -> V_5 . V_191 ;
break;
}
return 0 ;
}
bool F_104 ( struct V_1 * V_2 )
{
T_1 V_204 = F_105 ( V_2 , V_205 ) ;
T_2 V_39 ;
int V_30 ;
V_30 = F_106 ( V_2 , V_204 , & V_39 ) ;
if ( V_30 )
return V_30 ;
F_107 ( V_2 , V_206 , ( T_1 ) V_39 ) ;
F_107 ( V_2 , V_207 , V_39 >> 32 ) ;
return V_30 ;
}
bool F_108 ( struct V_1 * V_2 , T_2 V_135 )
{
if ( V_135 & V_208 )
return false ;
if ( V_135 & V_209 ) {
struct V_210 * V_211 ;
V_211 = F_109 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_211 || ! ( V_211 -> V_212 & F_110 ( V_213 ) ) )
return false ;
}
if ( V_135 & V_214 ) {
struct V_210 * V_211 ;
V_211 = F_109 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_211 || ! ( V_211 -> V_204 & F_110 ( V_215 ) ) )
return false ;
}
return true ;
}
static int F_111 ( struct V_1 * V_2 , T_2 V_135 )
{
T_2 V_216 = V_2 -> V_5 . V_135 ;
if ( ! F_108 ( V_2 , V_135 ) )
return 1 ;
if ( F_66 ( V_2 )
&& ( V_2 -> V_5 . V_135 & V_136 ) != ( V_135 & V_136 ) )
return 1 ;
V_135 &= ~ V_217 ;
V_135 |= V_2 -> V_5 . V_135 & V_217 ;
V_90 -> F_111 ( V_2 , V_135 ) ;
if ( ( V_135 ^ V_216 ) & V_218 )
F_68 ( V_2 ) ;
return 0 ;
}
void F_112 ( T_2 V_29 )
{
V_208 &= ~ V_29 ;
}
int F_113 ( struct V_1 * V_2 , struct V_33 * V_22 )
{
switch ( V_22 -> V_150 ) {
case V_219 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
if ( F_114 ( V_22 -> V_39 ) )
return 1 ;
break;
case V_224 :
case V_225 :
V_22 -> V_39 = F_115 ( V_22 -> V_39 ) ;
}
return V_90 -> V_226 ( V_2 , V_22 ) ;
}
static int F_116 ( struct V_1 * V_2 , unsigned V_150 , T_2 * V_39 )
{
struct V_33 V_22 ;
int V_124 ;
V_22 . V_150 = V_150 ;
V_22 . V_41 = true ;
V_124 = F_117 ( V_2 , & V_22 ) ;
if ( V_124 )
return V_124 ;
* V_39 = V_22 . V_39 ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 , unsigned V_150 , T_2 * V_39 )
{
struct V_33 V_22 ;
V_22 . V_39 = * V_39 ;
V_22 . V_150 = V_150 ;
V_22 . V_41 = true ;
return F_113 ( V_2 , & V_22 ) ;
}
static void F_119 ( struct V_227 * V_228 )
{
struct V_229 * V_230 = & V_229 ;
T_2 V_231 ;
V_231 = F_120 ( F_121 ( V_228 -> V_232 . V_233 , V_228 -> V_234 ) ) ;
F_122 ( & V_230 -> V_235 ) ;
V_230 -> clock . V_236 = V_228 -> V_232 . clock -> V_237 . V_236 ;
V_230 -> clock . V_238 = V_228 -> V_232 . V_238 ;
V_230 -> clock . V_29 = V_228 -> V_232 . V_29 ;
V_230 -> clock . V_239 = V_228 -> V_232 . V_239 ;
V_230 -> clock . V_240 = V_228 -> V_232 . V_240 ;
V_230 -> V_231 = V_231 ;
V_230 -> V_241 = V_228 -> V_232 . V_242 ;
V_230 -> V_243 = V_228 -> V_244 ;
F_123 ( & V_230 -> V_235 ) ;
}
void F_124 ( struct V_1 * V_2 )
{
F_32 ( V_245 , V_2 ) ;
}
static void F_125 ( struct V_142 * V_142 , T_6 V_246 )
{
int V_247 ;
int V_124 ;
struct V_248 V_249 ;
struct V_250 V_251 ;
if ( ! V_246 )
return;
V_124 = F_126 ( V_142 , V_246 , & V_247 , sizeof( V_247 ) ) ;
if ( V_124 )
return;
if ( V_247 & 1 )
++ V_247 ;
++ V_247 ;
if ( F_127 ( V_142 , V_246 , & V_247 , sizeof( V_247 ) ) )
return;
F_128 ( & V_251 ) ;
if ( V_142 -> V_5 . V_252 ) {
struct V_250 V_253 = F_129 ( V_142 -> V_5 . V_252 ) ;
V_251 = F_130 ( V_251 , V_253 ) ;
}
V_249 . V_254 = ( T_1 ) V_251 . V_255 ;
V_249 . V_256 = V_251 . V_257 ;
V_249 . V_247 = V_247 ;
F_127 ( V_142 , V_246 , & V_249 , sizeof( V_249 ) ) ;
V_247 ++ ;
F_127 ( V_142 , V_246 , & V_247 , sizeof( V_247 ) ) ;
}
static T_7 F_131 ( T_7 V_258 , T_7 V_259 )
{
F_132 ( V_258 , V_259 ) ;
return V_258 ;
}
static void F_133 ( T_8 V_260 , T_8 V_261 ,
T_9 * V_262 , T_1 * V_263 )
{
T_8 V_264 ;
T_10 V_240 = 0 ;
T_8 V_265 ;
T_7 V_266 ;
V_265 = V_261 ;
V_264 = V_260 ;
while ( V_265 > V_264 * 2 || V_265 & 0xffffffff00000000ULL ) {
V_265 >>= 1 ;
V_240 -- ;
}
V_266 = ( T_7 ) V_265 ;
while ( V_266 <= V_264 || V_264 & 0xffffffff00000000ULL ) {
if ( V_264 & 0xffffffff00000000ULL || V_266 & 0x80000000 )
V_264 >>= 1 ;
else
V_266 <<= 1 ;
V_240 ++ ;
}
* V_262 = V_240 ;
* V_263 = F_131 ( V_264 , V_266 ) ;
F_134 ( L_2 ,
V_267 , V_261 , V_260 , V_240 , * V_263 ) ;
}
static T_1 F_135 ( T_1 V_268 , T_11 V_269 )
{
T_2 V_270 = ( T_2 ) V_268 * ( 1000000 + V_269 ) ;
F_136 ( V_270 , 1000000 ) ;
return V_270 ;
}
static int F_137 ( struct V_1 * V_2 , T_1 V_271 , bool V_272 )
{
T_2 V_273 ;
if ( ! V_272 ) {
V_2 -> V_5 . V_274 = V_275 ;
return 0 ;
}
if ( ! V_276 ) {
if ( V_271 > V_277 ) {
V_2 -> V_5 . V_278 = 1 ;
V_2 -> V_5 . V_279 = 1 ;
return 0 ;
} else {
F_138 ( 1 , L_3 ) ;
return - 1 ;
}
}
V_273 = F_139 ( 1ULL << V_280 ,
V_271 , V_277 ) ;
if ( V_273 == 0 || V_273 >= V_281 ) {
F_140 ( 1 , L_4 ,
V_271 ) ;
return - 1 ;
}
V_2 -> V_5 . V_274 = V_273 ;
return 0 ;
}
static int F_141 ( struct V_1 * V_2 , T_1 V_271 )
{
T_1 V_282 , V_283 ;
int V_284 = 0 ;
if ( V_271 == 0 ) {
V_2 -> V_5 . V_274 = V_275 ;
return - 1 ;
}
F_133 ( V_271 * 1000LL , V_285 ,
& V_2 -> V_5 . V_286 ,
& V_2 -> V_5 . V_287 ) ;
V_2 -> V_5 . V_288 = V_271 ;
V_282 = F_135 ( V_277 , - V_289 ) ;
V_283 = F_135 ( V_277 , V_289 ) ;
if ( V_271 < V_282 || V_271 > V_283 ) {
F_134 ( L_5 , V_271 , V_282 , V_283 ) ;
V_284 = 1 ;
}
return F_137 ( V_2 , V_271 , V_284 ) ;
}
static T_2 F_142 ( struct V_1 * V_2 , T_12 V_290 )
{
T_2 V_291 = F_143 ( V_290 - V_2 -> V_5 . V_292 ,
V_2 -> V_5 . V_287 ,
V_2 -> V_5 . V_286 ) ;
V_291 += V_2 -> V_5 . V_293 ;
return V_291 ;
}
static void F_144 ( struct V_1 * V_2 )
{
#ifdef F_65
bool V_294 ;
struct V_295 * V_296 = & V_2 -> V_142 -> V_5 ;
struct V_229 * V_297 = & V_229 ;
V_294 = ( V_296 -> V_298 + 1 ==
F_145 ( & V_2 -> V_142 -> V_299 ) ) ;
if ( V_296 -> V_300 ||
( V_297 -> clock . V_236 == V_301 && V_294 ) )
F_32 ( V_302 , V_2 ) ;
F_146 ( V_2 -> V_303 , V_296 -> V_298 ,
F_145 ( & V_2 -> V_142 -> V_299 ) ,
V_296 -> V_300 , V_297 -> clock . V_236 ) ;
#endif
}
static void F_147 ( struct V_1 * V_2 , T_12 V_97 )
{
T_2 V_304 = V_2 -> V_5 . V_305 ;
V_2 -> V_5 . V_306 += V_97 - V_304 ;
}
static inline T_2 F_148 ( T_2 V_273 , T_2 V_291 )
{
return F_149 ( V_291 , V_273 , V_280 ) ;
}
T_2 F_150 ( struct V_1 * V_2 , T_2 V_291 )
{
T_2 V_307 = V_291 ;
T_2 V_273 = V_2 -> V_5 . V_274 ;
if ( V_273 != V_275 )
V_307 = F_148 ( V_273 , V_291 ) ;
return V_307 ;
}
static T_2 F_151 ( struct V_1 * V_2 , T_2 V_308 )
{
T_2 V_291 ;
V_291 = F_150 ( V_2 , F_152 () ) ;
return V_308 - V_291 ;
}
T_2 F_153 ( struct V_1 * V_2 , T_2 V_309 )
{
return V_2 -> V_5 . V_305 + F_150 ( V_2 , V_309 ) ;
}
static void F_154 ( struct V_1 * V_2 , T_2 V_97 )
{
V_90 -> V_310 ( V_2 , V_97 ) ;
V_2 -> V_5 . V_305 = V_97 ;
}
void F_155 ( struct V_1 * V_2 , struct V_33 * V_22 )
{
struct V_142 * V_142 = V_2 -> V_142 ;
T_2 V_97 , V_311 , V_312 ;
unsigned long V_15 ;
bool V_313 ;
bool V_314 ;
T_2 V_39 = V_22 -> V_39 ;
bool V_315 = false ;
F_156 ( & V_142 -> V_5 . V_316 , V_15 ) ;
V_97 = F_151 ( V_2 , V_39 ) ;
V_311 = F_157 () ;
V_312 = V_311 - V_142 -> V_5 . V_317 ;
if ( V_2 -> V_5 . V_288 ) {
if ( V_39 == 0 && V_22 -> V_41 ) {
V_315 = true ;
} else {
T_2 V_318 = V_142 -> V_5 . V_319 +
F_158 ( V_2 , V_312 ) ;
T_2 V_320 = V_2 -> V_5 . V_288 * 1000LL ;
V_315 = V_39 < V_318 + V_320 &&
V_39 + V_320 > V_318 ;
}
}
if ( V_315 &&
V_2 -> V_5 . V_288 == V_142 -> V_5 . V_321 ) {
if ( ! F_159 () ) {
V_97 = V_142 -> V_5 . V_322 ;
F_134 ( L_6 , V_39 ) ;
} else {
T_2 V_323 = F_158 ( V_2 , V_312 ) ;
V_39 += V_323 ;
V_97 = F_151 ( V_2 , V_39 ) ;
F_134 ( L_7 , V_323 ) ;
}
V_313 = true ;
V_314 = ( V_2 -> V_5 . V_324 == V_142 -> V_5 . V_325 ) ;
} else {
V_142 -> V_5 . V_325 ++ ;
V_142 -> V_5 . V_326 = V_311 ;
V_142 -> V_5 . V_327 = V_39 ;
V_142 -> V_5 . V_322 = V_97 ;
V_313 = false ;
F_134 ( L_8 ,
V_142 -> V_5 . V_325 , V_39 ) ;
}
V_142 -> V_5 . V_317 = V_311 ;
V_142 -> V_5 . V_319 = V_39 ;
V_142 -> V_5 . V_321 = V_2 -> V_5 . V_288 ;
V_2 -> V_5 . V_328 = V_39 ;
V_2 -> V_5 . V_324 = V_142 -> V_5 . V_325 ;
V_2 -> V_5 . V_292 = V_142 -> V_5 . V_326 ;
V_2 -> V_5 . V_293 = V_142 -> V_5 . V_327 ;
if ( F_160 ( V_2 ) && ! V_22 -> V_41 )
F_147 ( V_2 , V_97 ) ;
F_154 ( V_2 , V_97 ) ;
F_161 ( & V_142 -> V_5 . V_316 , V_15 ) ;
F_162 ( & V_142 -> V_5 . V_329 ) ;
if ( ! V_313 ) {
V_142 -> V_5 . V_298 = 0 ;
} else if ( ! V_314 ) {
V_142 -> V_5 . V_298 ++ ;
}
F_144 ( V_2 ) ;
F_163 ( & V_142 -> V_5 . V_329 ) ;
}
static inline void F_164 ( struct V_1 * V_2 ,
T_12 V_330 )
{
F_154 ( V_2 , V_2 -> V_5 . V_305 + V_330 ) ;
}
static inline void F_165 ( struct V_1 * V_2 , T_12 V_330 )
{
if ( V_2 -> V_5 . V_274 != V_275 )
F_30 ( V_330 < 0 ) ;
V_330 = F_150 ( V_2 , ( T_2 ) V_330 ) ;
F_164 ( V_2 , V_330 ) ;
}
static T_2 F_166 ( void )
{
T_2 V_111 = ( T_2 ) F_167 () ;
T_2 V_331 = V_229 . clock . V_238 ;
if ( F_168 ( V_111 >= V_331 ) )
return V_111 ;
asm volatile ("");
return V_331 ;
}
static inline T_2 F_169 ( T_2 * V_332 )
{
long V_270 ;
struct V_229 * V_297 = & V_229 ;
* V_332 = F_166 () ;
V_270 = ( * V_332 - V_297 -> clock . V_238 ) & V_297 -> clock . V_29 ;
return V_270 * V_297 -> clock . V_239 ;
}
static int F_170 ( T_12 * V_333 , T_2 * V_332 )
{
struct V_229 * V_297 = & V_229 ;
unsigned long V_235 ;
int V_334 ;
T_2 V_311 ;
do {
V_235 = F_171 ( & V_297 -> V_235 ) ;
V_334 = V_297 -> clock . V_236 ;
V_311 = V_297 -> V_241 ;
V_311 += F_169 ( V_332 ) ;
V_311 >>= V_297 -> clock . V_240 ;
V_311 += V_297 -> V_231 ;
} while ( F_172 ( F_173 ( & V_297 -> V_235 , V_235 ) ) );
* V_333 = V_311 ;
return V_334 ;
}
static int F_174 ( struct V_335 * V_253 , T_2 * V_332 )
{
struct V_229 * V_297 = & V_229 ;
unsigned long V_235 ;
int V_334 ;
T_2 V_311 ;
do {
V_235 = F_171 ( & V_297 -> V_235 ) ;
V_334 = V_297 -> clock . V_236 ;
V_253 -> V_255 = V_297 -> V_243 ;
V_311 = V_297 -> V_241 ;
V_311 += F_169 ( V_332 ) ;
V_311 >>= V_297 -> clock . V_240 ;
} while ( F_172 ( F_173 ( & V_297 -> V_235 , V_235 ) ) );
V_253 -> V_255 += F_175 ( V_311 , V_285 , & V_311 ) ;
V_253 -> V_257 = V_311 ;
return V_334 ;
}
static bool F_176 ( T_12 * V_290 , T_2 * V_332 )
{
if ( V_229 . clock . V_236 != V_301 )
return false ;
return F_170 ( V_290 , V_332 ) == V_301 ;
}
static bool F_177 ( struct V_335 * V_253 ,
T_2 * V_332 )
{
if ( V_229 . clock . V_236 != V_301 )
return false ;
return F_174 ( V_253 , V_332 ) == V_301 ;
}
static void F_178 ( struct V_142 * V_142 )
{
#ifdef F_65
struct V_295 * V_296 = & V_142 -> V_5 ;
int V_236 ;
bool V_336 , V_294 ;
V_294 = ( V_296 -> V_298 + 1 ==
F_145 ( & V_142 -> V_299 ) ) ;
V_336 = F_176 (
& V_296 -> V_337 ,
& V_296 -> V_338 ) ;
V_296 -> V_300 = V_336 && V_294
&& ! V_296 -> V_339
&& ! V_296 -> V_340 ;
if ( V_296 -> V_300 )
F_179 ( & V_341 , 1 ) ;
V_236 = V_229 . clock . V_236 ;
F_180 ( V_296 -> V_300 , V_236 ,
V_294 ) ;
#endif
}
void F_181 ( struct V_142 * V_142 )
{
F_182 ( V_142 , V_342 ) ;
}
static void F_183 ( struct V_142 * V_142 )
{
#ifdef F_65
int V_3 ;
struct V_1 * V_2 ;
struct V_295 * V_296 = & V_142 -> V_5 ;
F_162 ( & V_296 -> V_329 ) ;
F_181 ( V_142 ) ;
F_178 ( V_142 ) ;
F_184 (i, vcpu, kvm)
F_32 ( V_343 , V_2 ) ;
F_184 (i, vcpu, kvm)
F_185 ( V_342 , V_2 ) ;
F_163 ( & V_296 -> V_329 ) ;
#endif
}
T_2 F_186 ( struct V_142 * V_142 )
{
struct V_295 * V_296 = & V_142 -> V_5 ;
struct V_344 V_345 ;
T_2 V_111 ;
F_162 ( & V_296 -> V_329 ) ;
if ( ! V_296 -> V_300 ) {
F_163 ( & V_296 -> V_329 ) ;
return F_157 () + V_296 -> V_252 ;
}
V_345 . V_346 = V_296 -> V_338 ;
V_345 . V_347 = V_296 -> V_337 + V_296 -> V_252 ;
F_163 ( & V_296 -> V_329 ) ;
F_187 () ;
F_133 ( V_285 , F_188 ( V_348 ) * 1000LL ,
& V_345 . V_349 ,
& V_345 . V_350 ) ;
V_111 = F_189 ( & V_345 , F_152 () ) ;
F_190 () ;
return V_111 ;
}
static void F_191 ( struct V_1 * V_270 )
{
struct V_351 * V_2 = & V_270 -> V_5 ;
struct V_344 V_352 ;
if ( F_172 ( F_192 ( V_270 -> V_142 , & V_2 -> V_353 ,
& V_352 , sizeof( V_352 ) ) ) )
return;
F_193 ( F_194 ( struct V_344 , V_247 ) != 0 ) ;
V_2 -> V_345 . V_247 = V_352 . V_247 + 1 ;
F_195 ( V_270 -> V_142 , & V_2 -> V_353 ,
& V_2 -> V_345 ,
sizeof( V_2 -> V_345 . V_247 ) ) ;
F_196 () ;
V_2 -> V_345 . V_15 |= ( V_352 . V_15 & V_354 ) ;
if ( V_2 -> V_355 ) {
V_2 -> V_345 . V_15 |= V_354 ;
V_2 -> V_355 = false ;
}
F_197 ( V_270 -> V_303 , & V_2 -> V_345 ) ;
F_195 ( V_270 -> V_142 , & V_2 -> V_353 ,
& V_2 -> V_345 ,
sizeof( V_2 -> V_345 ) ) ;
F_196 () ;
V_2 -> V_345 . V_247 ++ ;
F_195 ( V_270 -> V_142 , & V_2 -> V_353 ,
& V_2 -> V_345 ,
sizeof( V_2 -> V_345 . V_247 ) ) ;
}
static int F_198 ( struct V_1 * V_270 )
{
unsigned long V_15 , V_356 ;
struct V_351 * V_2 = & V_270 -> V_5 ;
struct V_295 * V_296 = & V_270 -> V_142 -> V_5 ;
T_12 V_290 ;
T_2 V_346 , V_309 ;
T_13 V_357 ;
bool V_300 ;
V_290 = 0 ;
V_309 = 0 ;
F_162 ( & V_296 -> V_329 ) ;
V_300 = V_296 -> V_300 ;
if ( V_300 ) {
V_309 = V_296 -> V_338 ;
V_290 = V_296 -> V_337 ;
}
F_163 ( & V_296 -> V_329 ) ;
F_5 ( V_15 ) ;
V_356 = F_188 ( V_348 ) ;
if ( F_172 ( V_356 == 0 ) ) {
F_7 ( V_15 ) ;
F_32 ( V_343 , V_270 ) ;
return 1 ;
}
if ( ! V_300 ) {
V_309 = F_152 () ;
V_290 = F_157 () ;
}
V_346 = F_153 ( V_270 , V_309 ) ;
if ( V_2 -> V_278 ) {
T_2 V_291 = F_142 ( V_270 , V_290 ) ;
if ( V_291 > V_346 ) {
F_164 ( V_270 , V_291 - V_346 ) ;
V_346 = V_291 ;
}
}
F_7 ( V_15 ) ;
if ( V_276 )
V_356 = F_150 ( V_270 , V_356 ) ;
if ( F_172 ( V_2 -> V_358 != V_356 ) ) {
F_133 ( V_285 , V_356 * 1000LL ,
& V_2 -> V_345 . V_349 ,
& V_2 -> V_345 . V_350 ) ;
V_2 -> V_358 = V_356 ;
}
V_2 -> V_345 . V_346 = V_346 ;
V_2 -> V_345 . V_347 = V_290 + V_270 -> V_142 -> V_5 . V_252 ;
V_2 -> V_328 = V_346 ;
V_357 = 0 ;
if ( V_300 )
V_357 |= V_359 ;
V_2 -> V_345 . V_15 = V_357 ;
if ( V_2 -> V_360 )
F_191 ( V_270 ) ;
if ( V_270 == F_199 ( V_270 -> V_142 , 0 ) )
F_200 ( V_270 -> V_142 , & V_2 -> V_345 ) ;
return 0 ;
}
static void F_201 ( struct V_361 * V_362 )
{
int V_3 ;
struct V_363 * V_364 = F_202 ( V_362 ) ;
struct V_295 * V_296 = F_4 ( V_364 , struct V_295 ,
V_365 ) ;
struct V_142 * V_142 = F_4 ( V_296 , struct V_142 , V_5 ) ;
struct V_1 * V_2 ;
F_184 (i, vcpu, kvm) {
F_32 ( V_343 , V_2 ) ;
F_203 ( V_2 ) ;
}
}
static void F_204 ( struct V_1 * V_270 )
{
struct V_142 * V_142 = V_270 -> V_142 ;
F_32 ( V_343 , V_270 ) ;
F_205 ( & V_142 -> V_5 . V_365 ,
V_366 ) ;
}
static void F_206 ( struct V_361 * V_362 )
{
struct V_363 * V_364 = F_202 ( V_362 ) ;
struct V_295 * V_296 = F_4 ( V_364 , struct V_295 ,
V_367 ) ;
struct V_142 * V_142 = F_4 ( V_296 , struct V_142 , V_5 ) ;
if ( ! V_368 )
return;
F_205 ( & V_142 -> V_5 . V_365 , 0 ) ;
F_205 ( & V_142 -> V_5 . V_367 ,
V_369 ) ;
}
static int F_207 ( struct V_1 * V_2 , T_1 V_22 , T_2 V_39 )
{
T_2 V_370 = V_2 -> V_5 . V_370 ;
unsigned V_371 = V_370 & 0xff ;
switch ( V_22 ) {
case V_372 :
V_2 -> V_5 . V_373 = V_39 ;
break;
case V_374 :
if ( ! ( V_370 & V_375 ) )
return 1 ;
if ( V_39 != 0 && V_39 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_376 = V_39 ;
break;
default:
if ( V_22 >= V_377 &&
V_22 < F_208 ( V_371 ) ) {
T_1 V_97 = V_22 - V_377 ;
if ( ( V_97 & 0x3 ) == 0 &&
V_39 != 0 && ( V_39 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_378 [ V_97 ] = V_39 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_209 ( struct V_1 * V_2 , T_2 V_39 )
{
struct V_142 * V_142 = V_2 -> V_142 ;
int V_379 = F_59 ( V_2 ) ;
T_13 * V_380 = V_379 ? ( T_13 * ) ( long ) V_142 -> V_5 . F_209 . V_381
: ( T_13 * ) ( long ) V_142 -> V_5 . F_209 . V_382 ;
T_13 V_383 = V_379 ? V_142 -> V_5 . F_209 . V_384
: V_142 -> V_5 . F_209 . V_385 ;
T_1 V_386 = V_39 & ~ V_387 ;
T_2 V_388 = V_39 & V_387 ;
T_13 * V_389 ;
int V_124 ;
V_124 = - V_390 ;
if ( V_386 >= V_383 )
goto V_116;
V_124 = - V_391 ;
V_389 = F_210 ( V_380 + ( V_386 * V_110 ) , V_110 ) ;
if ( F_211 ( V_389 ) ) {
V_124 = F_212 ( V_389 ) ;
goto V_116;
}
if ( F_213 ( V_2 , V_388 , V_389 , V_110 ) )
goto V_392;
V_124 = 0 ;
V_392:
F_214 ( V_389 ) ;
V_116:
return V_124 ;
}
static int F_215 ( struct V_1 * V_2 , T_2 V_39 )
{
T_6 V_393 = V_39 & ~ 0x3f ;
if ( V_39 & 0x38 )
return 1 ;
V_2 -> V_5 . V_6 . V_394 = V_39 ;
if ( ! ( V_39 & V_395 ) ) {
F_67 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_216 ( V_2 -> V_142 , & V_2 -> V_5 . V_6 . V_39 , V_393 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_396 = ! ( V_39 & V_397 ) ;
V_2 -> V_5 . V_6 . V_398 = V_39 & V_399 ;
F_217 ( V_2 ) ;
return 0 ;
}
static void F_218 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_360 = false ;
}
static void F_219 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_400 . V_394 & V_401 ) )
return;
if ( F_172 ( F_192 ( V_2 -> V_142 , & V_2 -> V_5 . V_400 . V_402 ,
& V_2 -> V_5 . V_400 . V_403 , sizeof( struct V_404 ) ) ) )
return;
V_2 -> V_5 . V_400 . V_403 . V_405 = 0 ;
if ( V_2 -> V_5 . V_400 . V_403 . V_247 & 1 )
V_2 -> V_5 . V_400 . V_403 . V_247 += 1 ;
V_2 -> V_5 . V_400 . V_403 . V_247 += 1 ;
F_195 ( V_2 -> V_142 , & V_2 -> V_5 . V_400 . V_402 ,
& V_2 -> V_5 . V_400 . V_403 , sizeof( struct V_404 ) ) ;
F_196 () ;
V_2 -> V_5 . V_400 . V_403 . V_403 += V_406 -> V_407 . V_408 -
V_2 -> V_5 . V_400 . V_409 ;
V_2 -> V_5 . V_400 . V_409 = V_406 -> V_407 . V_408 ;
F_195 ( V_2 -> V_142 , & V_2 -> V_5 . V_400 . V_402 ,
& V_2 -> V_5 . V_400 . V_403 , sizeof( struct V_404 ) ) ;
F_196 () ;
V_2 -> V_5 . V_400 . V_403 . V_247 += 1 ;
F_195 ( V_2 -> V_142 , & V_2 -> V_5 . V_400 . V_402 ,
& V_2 -> V_5 . V_400 . V_403 , sizeof( struct V_404 ) ) ;
}
int F_220 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
bool V_410 = false ;
T_1 V_22 = V_34 -> V_150 ;
T_2 V_39 = V_34 -> V_39 ;
switch ( V_22 ) {
case V_411 :
case V_412 :
case V_413 :
case V_414 :
case V_415 :
case V_416 :
case V_417 :
break;
case V_418 :
return F_111 ( V_2 , V_39 ) ;
case V_419 :
V_39 &= ~ ( T_2 ) 0x40 ;
V_39 &= ~ ( T_2 ) 0x100 ;
V_39 &= ~ ( T_2 ) 0x8 ;
V_39 &= ~ ( T_2 ) 0x40000 ;
if ( V_39 != 0 ) {
F_221 ( V_2 , L_9 ,
V_39 ) ;
return 1 ;
}
break;
case V_420 :
if ( V_39 != 0 ) {
F_221 ( V_2 , L_10
L_11 , V_39 ) ;
return 1 ;
}
break;
case V_421 :
if ( ! V_39 ) {
break;
} else if ( V_39 & ~ ( V_422 | V_423 ) ) {
return 1 ;
}
F_221 ( V_2 , L_12 ,
V_267 , V_39 ) ;
break;
case 0x200 ... 0x2ff :
return F_222 ( V_2 , V_22 , V_39 ) ;
case V_424 :
return F_22 ( V_2 , V_34 ) ;
case V_425 ... V_425 + 0x3ff :
return F_223 ( V_2 , V_22 , V_39 ) ;
case V_426 :
F_224 ( V_2 , V_39 ) ;
break;
case V_427 :
if ( F_160 ( V_2 ) ) {
if ( ! V_34 -> V_41 ) {
T_12 V_428 = V_39 - V_2 -> V_5 . V_306 ;
F_164 ( V_2 , V_428 ) ;
}
V_2 -> V_5 . V_306 = V_39 ;
}
break;
case V_429 :
V_2 -> V_5 . V_430 = V_39 ;
break;
case V_431 :
if ( ! V_34 -> V_41 )
return 1 ;
V_2 -> V_5 . V_432 = V_39 ;
break;
case V_433 :
case V_434 :
V_2 -> V_142 -> V_5 . V_246 = V_39 ;
F_125 ( V_2 -> V_142 , V_39 ) ;
break;
case V_435 :
case V_436 : {
struct V_295 * V_296 = & V_2 -> V_142 -> V_5 ;
F_218 ( V_2 ) ;
if ( V_2 -> V_303 == 0 && ! V_34 -> V_41 ) {
bool V_437 = ( V_22 == V_436 ) ;
if ( V_296 -> V_340 != V_437 )
F_32 ( V_302 , V_2 ) ;
V_296 -> V_340 = V_437 ;
}
V_2 -> V_5 . time = V_39 ;
F_32 ( V_438 , V_2 ) ;
if ( ! ( V_39 & 1 ) )
break;
if ( F_216 ( V_2 -> V_142 ,
& V_2 -> V_5 . V_353 , V_39 & ~ 1ULL ,
sizeof( struct V_344 ) ) )
V_2 -> V_5 . V_360 = false ;
else
V_2 -> V_5 . V_360 = true ;
break;
}
case V_439 :
if ( F_215 ( V_2 , V_39 ) )
return 1 ;
break;
case V_440 :
if ( F_172 ( ! F_225 () ) )
return 1 ;
if ( V_39 & V_441 )
return 1 ;
if ( F_216 ( V_2 -> V_142 , & V_2 -> V_5 . V_400 . V_402 ,
V_39 & V_442 ,
sizeof( struct V_404 ) ) )
return 1 ;
V_2 -> V_5 . V_400 . V_394 = V_39 ;
if ( ! ( V_39 & V_401 ) )
break;
F_32 ( V_443 , V_2 ) ;
break;
case V_444 :
if ( F_226 ( V_2 , V_39 ) )
return 1 ;
break;
case V_374 :
case V_372 :
case V_377 ... F_208 ( V_445 ) - 1 :
return F_207 ( V_2 , V_22 , V_39 ) ;
case V_446 ... V_447 :
case V_448 ... V_449 :
V_410 = true ;
case V_450 ... V_451 :
case V_452 ... V_453 :
if ( F_227 ( V_2 , V_22 ) )
return F_228 ( V_2 , V_34 ) ;
if ( V_410 || V_39 != 0 )
F_221 ( V_2 , L_13
L_14 , V_22 , V_39 ) ;
break;
case V_454 :
break;
case V_455 ... V_456 :
case V_457 ... V_458 :
case V_459 :
case V_460 ... V_461 :
return F_229 ( V_2 , V_22 , V_39 ,
V_34 -> V_41 ) ;
case V_462 :
F_221 ( V_2 , L_15 , V_22 , V_39 ) ;
break;
case V_463 :
if ( ! F_230 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_464 . V_465 = V_39 ;
break;
case V_466 :
if ( ! F_230 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_464 . V_467 = V_39 ;
break;
case V_468 :
if ( ! V_34 -> V_41 ||
V_39 & ~ V_469 ||
( ! ( V_39 & V_469 ) &&
F_231 ( V_2 ) ) )
return 1 ;
V_2 -> V_5 . V_470 = V_39 ;
break;
case V_471 :
if ( V_39 & ~ V_472 ||
( V_39 & V_472 &&
! F_232 ( V_2 ) ) )
return 1 ;
V_2 -> V_5 . V_473 = V_39 ;
break;
default:
if ( V_22 && ( V_22 == V_2 -> V_142 -> V_5 . F_209 . V_22 ) )
return F_209 ( V_2 , V_39 ) ;
if ( F_227 ( V_2 , V_22 ) )
return F_228 ( V_2 , V_34 ) ;
if ( ! V_474 ) {
F_233 ( V_2 , L_16 ,
V_22 , V_39 ) ;
return 1 ;
} else {
F_221 ( V_2 , L_15 ,
V_22 , V_39 ) ;
break;
}
}
return 0 ;
}
int F_117 ( struct V_1 * V_2 , struct V_33 * V_22 )
{
return V_90 -> V_475 ( V_2 , V_22 ) ;
}
static int F_234 ( struct V_1 * V_2 , T_1 V_22 , T_2 * V_476 )
{
T_2 V_39 ;
T_2 V_370 = V_2 -> V_5 . V_370 ;
unsigned V_371 = V_370 & 0xff ;
switch ( V_22 ) {
case V_477 :
case V_478 :
V_39 = 0 ;
break;
case V_479 :
V_39 = V_2 -> V_5 . V_370 ;
break;
case V_374 :
if ( ! ( V_370 & V_375 ) )
return 1 ;
V_39 = V_2 -> V_5 . V_376 ;
break;
case V_372 :
V_39 = V_2 -> V_5 . V_373 ;
break;
default:
if ( V_22 >= V_377 &&
V_22 < F_208 ( V_371 ) ) {
T_1 V_97 = V_22 - V_377 ;
V_39 = V_2 -> V_5 . V_378 [ V_97 ] ;
break;
}
return 1 ;
}
* V_476 = V_39 ;
return 0 ;
}
int F_235 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
switch ( V_34 -> V_150 ) {
case V_480 :
case V_481 :
case V_421 :
case V_482 :
case V_483 :
case V_484 :
case V_485 :
case V_486 :
case V_487 :
case V_488 :
case V_419 :
case V_414 :
case V_489 :
case V_411 :
case V_420 :
case V_416 :
case V_490 :
case V_417 :
V_34 -> V_39 = 0 ;
break;
case V_450 ... V_451 :
case V_446 ... V_447 :
case V_448 ... V_449 :
case V_452 ... V_453 :
if ( F_227 ( V_2 , V_34 -> V_150 ) )
return F_236 ( V_2 , V_34 -> V_150 , & V_34 -> V_39 ) ;
V_34 -> V_39 = 0 ;
break;
case V_412 :
V_34 -> V_39 = 0x100000000ULL ;
break;
case V_491 :
case 0x200 ... 0x2ff :
return F_237 ( V_2 , V_34 -> V_150 , & V_34 -> V_39 ) ;
case 0xcd :
V_34 -> V_39 = 3 ;
break;
case V_492 :
V_34 -> V_39 = 1 << 24 ;
break;
case V_424 :
V_34 -> V_39 = F_21 ( V_2 ) ;
break;
case V_425 ... V_425 + 0x3ff :
return F_238 ( V_2 , V_34 -> V_150 , & V_34 -> V_39 ) ;
break;
case V_426 :
V_34 -> V_39 = F_239 ( V_2 ) ;
break;
case V_427 :
V_34 -> V_39 = ( T_2 ) V_2 -> V_5 . V_306 ;
break;
case V_429 :
V_34 -> V_39 = V_2 -> V_5 . V_430 ;
break;
case V_431 :
if ( ! V_34 -> V_41 )
return 1 ;
V_34 -> V_39 = V_2 -> V_5 . V_432 ;
break;
case V_493 :
V_34 -> V_39 = 1000ULL ;
V_34 -> V_39 |= ( ( ( T_8 ) 4ULL ) << 40 ) ;
break;
case V_418 :
V_34 -> V_39 = V_2 -> V_5 . V_135 ;
break;
case V_434 :
case V_433 :
V_34 -> V_39 = V_2 -> V_142 -> V_5 . V_246 ;
break;
case V_436 :
case V_435 :
V_34 -> V_39 = V_2 -> V_5 . time ;
break;
case V_439 :
V_34 -> V_39 = V_2 -> V_5 . V_6 . V_394 ;
break;
case V_440 :
V_34 -> V_39 = V_2 -> V_5 . V_400 . V_394 ;
break;
case V_444 :
V_34 -> V_39 = V_2 -> V_5 . V_494 . V_394 ;
break;
case V_477 :
case V_478 :
case V_479 :
case V_374 :
case V_372 :
case V_377 ... F_208 ( V_445 ) - 1 :
return F_234 ( V_2 , V_34 -> V_150 , & V_34 -> V_39 ) ;
case V_454 :
V_34 -> V_39 = 0x20000000 ;
break;
case V_455 ... V_456 :
case V_457 ... V_458 :
case V_459 :
case V_460 ... V_461 :
return F_240 ( V_2 ,
V_34 -> V_150 , & V_34 -> V_39 ) ;
break;
case V_462 :
V_34 -> V_39 = 0xbe702111 ;
break;
case V_463 :
if ( ! F_230 ( V_2 ) )
return 1 ;
V_34 -> V_39 = V_2 -> V_5 . V_464 . V_465 ;
break;
case V_466 :
if ( ! F_230 ( V_2 ) )
return 1 ;
V_34 -> V_39 = V_2 -> V_5 . V_464 . V_467 ;
break;
case V_468 :
V_34 -> V_39 = V_2 -> V_5 . V_470 ;
break;
case V_471 :
V_34 -> V_39 = V_2 -> V_5 . V_473 ;
break;
default:
if ( F_227 ( V_2 , V_34 -> V_150 ) )
return F_236 ( V_2 , V_34 -> V_150 , & V_34 -> V_39 ) ;
if ( ! V_474 ) {
F_233 ( V_2 , L_17 ,
V_34 -> V_150 ) ;
return 1 ;
} else {
F_221 ( V_2 , L_18 , V_34 -> V_150 ) ;
V_34 -> V_39 = 0 ;
}
break;
}
return 0 ;
}
static int F_241 ( struct V_1 * V_2 , struct V_495 * V_21 ,
struct V_496 * V_497 ,
int (* F_242)( struct V_1 * V_2 ,
unsigned V_150 , T_2 * V_39 ) )
{
int V_3 , V_498 ;
V_498 = F_243 ( & V_2 -> V_142 -> V_499 ) ;
for ( V_3 = 0 ; V_3 < V_21 -> V_500 ; ++ V_3 )
if ( F_242 ( V_2 , V_497 [ V_3 ] . V_150 , & V_497 [ V_3 ] . V_39 ) )
break;
F_244 ( & V_2 -> V_142 -> V_499 , V_498 ) ;
return V_3 ;
}
static int F_245 ( struct V_1 * V_2 , struct V_495 T_14 * V_501 ,
int (* F_242)( struct V_1 * V_2 ,
unsigned V_150 , T_2 * V_39 ) ,
int V_502 )
{
struct V_495 V_21 ;
struct V_496 * V_497 ;
int V_124 , V_503 ;
unsigned V_504 ;
V_124 = - V_104 ;
if ( F_246 ( & V_21 , V_501 , sizeof V_21 ) )
goto V_116;
V_124 = - V_390 ;
if ( V_21 . V_500 >= V_505 )
goto V_116;
V_504 = sizeof( struct V_496 ) * V_21 . V_500 ;
V_497 = F_210 ( V_501 -> V_497 , V_504 ) ;
if ( F_211 ( V_497 ) ) {
V_124 = F_212 ( V_497 ) ;
goto V_116;
}
V_124 = V_503 = F_241 ( V_2 , & V_21 , V_497 , F_242 ) ;
if ( V_124 < 0 )
goto V_392;
V_124 = - V_104 ;
if ( V_502 && F_247 ( V_501 -> V_497 , V_497 , V_504 ) )
goto V_392;
V_124 = V_503 ;
V_392:
F_214 ( V_497 ) ;
V_116:
return V_124 ;
}
int F_248 ( struct V_142 * V_142 , long V_506 )
{
int V_124 ;
switch ( V_506 ) {
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
case V_542 :
case V_543 :
case V_544 :
case V_545 :
case V_546 :
case V_547 :
case V_548 :
case V_549 :
V_124 = 1 ;
break;
case V_550 :
V_124 = V_551 ;
break;
case V_552 :
V_124 = F_249 () ;
break;
case V_553 :
V_124 = V_90 -> V_554 () ;
break;
case V_555 :
V_124 = ! V_90 -> V_556 () ;
break;
case V_557 :
V_124 = V_558 ;
break;
case V_559 :
V_124 = V_560 ;
break;
case V_561 :
V_124 = V_562 ;
break;
case V_563 :
V_124 = 0 ;
break;
case V_564 :
V_124 = V_445 ;
break;
case V_565 :
V_124 = F_250 ( V_566 ) ;
break;
case V_567 :
V_124 = V_276 ;
break;
case V_568 :
V_124 = V_569 ;
break;
default:
V_124 = 0 ;
break;
}
return V_124 ;
}
long F_251 ( struct V_570 * V_571 ,
unsigned int V_572 , unsigned long V_573 )
{
void T_14 * V_574 = ( void T_14 * ) V_573 ;
long V_124 ;
switch ( V_572 ) {
case V_575 : {
struct V_576 T_14 * V_577 = V_574 ;
struct V_576 V_578 ;
unsigned V_503 ;
V_124 = - V_104 ;
if ( F_246 ( & V_578 , V_577 , sizeof V_578 ) )
goto V_116;
V_503 = V_578 . V_500 ;
V_578 . V_500 = V_579 + V_580 ;
if ( F_247 ( V_577 , & V_578 , sizeof V_578 ) )
goto V_116;
V_124 = - V_390 ;
if ( V_503 < V_578 . V_500 )
goto V_116;
V_124 = - V_104 ;
if ( F_247 ( V_577 -> V_581 , & V_582 ,
V_579 * sizeof( T_1 ) ) )
goto V_116;
if ( F_247 ( V_577 -> V_581 + V_579 ,
& V_583 ,
V_580 * sizeof( T_1 ) ) )
goto V_116;
V_124 = 0 ;
break;
}
case V_584 :
case V_585 : {
struct V_586 T_14 * V_587 = V_574 ;
struct V_586 V_588 ;
V_124 = - V_104 ;
if ( F_246 ( & V_588 , V_587 , sizeof V_588 ) )
goto V_116;
V_124 = F_252 ( & V_588 , V_587 -> V_497 ,
V_572 ) ;
if ( V_124 )
goto V_116;
V_124 = - V_104 ;
if ( F_247 ( V_587 , & V_588 , sizeof V_588 ) )
goto V_116;
V_124 = 0 ;
break;
}
case V_589 : {
V_124 = - V_104 ;
if ( F_247 ( V_574 , & V_590 ,
sizeof( V_590 ) ) )
goto V_116;
V_124 = 0 ;
break;
}
default:
V_124 = - V_591 ;
}
V_116:
return V_124 ;
}
static void F_253 ( void * V_592 )
{
F_254 () ;
}
static bool F_255 ( struct V_1 * V_2 )
{
return F_69 ( V_2 -> V_142 ) ;
}
void F_256 ( struct V_1 * V_2 , int V_24 )
{
if ( F_255 ( V_2 ) ) {
if ( V_90 -> V_593 () )
F_257 ( V_24 , V_2 -> V_5 . V_594 ) ;
else if ( V_2 -> V_24 != - 1 && V_2 -> V_24 != V_24 )
F_258 ( V_2 -> V_24 ,
F_253 , NULL , 1 ) ;
}
V_90 -> V_595 ( V_2 , V_24 ) ;
if ( F_172 ( V_2 -> V_5 . V_596 ) ) {
F_165 ( V_2 , V_2 -> V_5 . V_596 ) ;
V_2 -> V_5 . V_596 = 0 ;
F_32 ( V_343 , V_2 ) ;
}
if ( F_172 ( V_2 -> V_24 != V_24 ) || F_159 () ) {
T_12 V_597 = ! V_2 -> V_5 . V_598 ? 0 :
F_152 () - V_2 -> V_5 . V_598 ;
if ( V_597 < 0 )
F_259 ( L_19 ) ;
if ( F_159 () ) {
T_2 V_97 = F_151 ( V_2 ,
V_2 -> V_5 . V_328 ) ;
F_154 ( V_2 , V_97 ) ;
V_2 -> V_5 . V_278 = 1 ;
}
if ( F_260 ( V_2 ) )
F_261 ( V_2 ) ;
if ( ! V_2 -> V_142 -> V_5 . V_300 || V_2 -> V_24 == - 1 )
F_32 ( V_438 , V_2 ) ;
if ( V_2 -> V_24 != V_24 )
F_32 ( V_599 , V_2 ) ;
V_2 -> V_24 = V_24 ;
}
F_32 ( V_443 , V_2 ) ;
}
static void F_262 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_400 . V_394 & V_401 ) )
return;
V_2 -> V_5 . V_400 . V_403 . V_405 = 1 ;
F_263 ( V_2 -> V_142 , & V_2 -> V_5 . V_400 . V_402 ,
& V_2 -> V_5 . V_400 . V_403 . V_405 ,
F_194 ( struct V_404 , V_405 ) ,
sizeof( V_2 -> V_5 . V_400 . V_403 . V_405 ) ) ;
}
void F_264 ( struct V_1 * V_2 )
{
int V_498 ;
F_265 () ;
V_498 = F_243 ( & V_2 -> V_142 -> V_499 ) ;
F_262 ( V_2 ) ;
F_244 ( & V_2 -> V_142 -> V_499 , V_498 ) ;
F_266 () ;
V_90 -> V_600 ( V_2 ) ;
F_267 ( V_2 ) ;
V_2 -> V_5 . V_598 = F_152 () ;
}
static int F_268 ( struct V_1 * V_2 ,
struct V_601 * V_602 )
{
if ( V_90 -> V_603 && V_2 -> V_5 . V_604 )
V_90 -> V_603 ( V_2 ) ;
return F_269 ( V_2 , V_602 ) ;
}
static int F_270 ( struct V_1 * V_2 ,
struct V_601 * V_602 )
{
int V_124 ;
V_124 = F_271 ( V_2 , V_602 ) ;
if ( V_124 )
return V_124 ;
F_272 ( V_2 ) ;
return 0 ;
}
static int F_273 ( struct V_1 * V_2 )
{
return ( ! F_92 ( V_2 ) ||
F_274 ( V_2 ) ) ;
}
static int F_275 ( struct V_1 * V_2 )
{
return F_276 ( V_2 ) &&
! F_277 ( V_2 ) &&
! F_278 ( V_2 ) &&
F_273 ( V_2 ) ;
}
static int F_279 ( struct V_1 * V_2 ,
struct V_605 * V_606 )
{
if ( V_606 -> V_606 >= V_607 )
return - V_591 ;
if ( ! F_280 ( V_2 -> V_142 ) ) {
F_281 ( V_2 , V_606 -> V_606 , false ) ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
if ( F_282 ( V_2 -> V_142 ) )
return - V_608 ;
if ( V_2 -> V_5 . V_609 != - 1 )
return - V_610 ;
V_2 -> V_5 . V_609 = V_606 -> V_606 ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
static int F_283 ( struct V_1 * V_2 )
{
F_44 ( V_2 ) ;
return 0 ;
}
static int F_284 ( struct V_1 * V_2 )
{
F_32 ( V_611 , V_2 ) ;
return 0 ;
}
static int F_285 ( struct V_1 * V_2 ,
struct V_612 * V_613 )
{
if ( V_613 -> V_15 )
return - V_591 ;
V_2 -> V_5 . V_614 = ! ! V_613 -> V_615 ;
return 0 ;
}
static int F_286 ( struct V_1 * V_2 ,
T_2 V_370 )
{
int V_124 ;
unsigned V_371 = V_370 & 0xff , V_616 ;
V_124 = - V_591 ;
if ( ! V_371 || V_371 >= V_445 )
goto V_116;
if ( V_370 & ~ ( V_590 | 0xff | 0xff0000 ) )
goto V_116;
V_124 = 0 ;
V_2 -> V_5 . V_370 = V_370 ;
if ( V_370 & V_375 )
V_2 -> V_5 . V_376 = ~ ( T_2 ) 0 ;
for ( V_616 = 0 ; V_616 < V_371 ; V_616 ++ )
V_2 -> V_5 . V_378 [ V_616 * 4 ] = ~ ( T_2 ) 0 ;
if ( V_90 -> V_617 )
V_90 -> V_617 ( V_2 ) ;
V_116:
return V_124 ;
}
static int F_287 ( struct V_1 * V_2 ,
struct V_618 * V_619 )
{
T_2 V_370 = V_2 -> V_5 . V_370 ;
unsigned V_371 = V_370 & 0xff ;
T_2 * V_620 = V_2 -> V_5 . V_378 ;
if ( V_619 -> V_616 >= V_371 || ! ( V_619 -> V_467 & V_621 ) )
return - V_591 ;
if ( ( V_619 -> V_467 & V_622 ) && ( V_370 & V_375 ) &&
V_2 -> V_5 . V_376 != ~ ( T_2 ) 0 )
return 0 ;
V_620 += 4 * V_619 -> V_616 ;
if ( ( V_619 -> V_467 & V_622 ) && V_620 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_619 -> V_467 & V_622 ) {
if ( ( V_2 -> V_5 . V_373 & V_623 ) ||
! F_49 ( V_2 , V_624 ) ) {
F_32 ( V_73 , V_2 ) ;
return 0 ;
}
if ( V_620 [ 1 ] & V_621 )
V_619 -> V_467 |= V_625 ;
V_620 [ 2 ] = V_619 -> V_626 ;
V_620 [ 3 ] = V_619 -> V_627 ;
V_2 -> V_5 . V_373 = V_619 -> V_373 ;
V_620 [ 1 ] = V_619 -> V_467 ;
F_34 ( V_2 , V_59 ) ;
} else if ( ! ( V_620 [ 1 ] & V_621 )
|| ! ( V_620 [ 1 ] & V_622 ) ) {
if ( V_620 [ 1 ] & V_621 )
V_619 -> V_467 |= V_625 ;
V_620 [ 2 ] = V_619 -> V_626 ;
V_620 [ 3 ] = V_619 -> V_627 ;
V_620 [ 1 ] = V_619 -> V_467 ;
} else
V_620 [ 1 ] |= V_625 ;
return 0 ;
}
static void F_288 ( struct V_1 * V_2 ,
struct V_628 * V_629 )
{
F_289 ( V_2 ) ;
V_629 -> V_69 . V_630 =
V_2 -> V_5 . V_69 . V_70 &&
! F_290 ( V_2 -> V_5 . V_69 . V_18 ) ;
V_629 -> V_69 . V_18 = V_2 -> V_5 . V_69 . V_18 ;
V_629 -> V_69 . V_72 = V_2 -> V_5 . V_69 . V_72 ;
V_629 -> V_69 . V_631 = 0 ;
V_629 -> V_69 . V_63 = V_2 -> V_5 . V_69 . V_63 ;
V_629 -> V_632 . V_630 =
V_2 -> V_5 . V_632 . V_70 && ! V_2 -> V_5 . V_632 . V_633 ;
V_629 -> V_632 . V_18 = V_2 -> V_5 . V_632 . V_18 ;
V_629 -> V_632 . V_633 = 0 ;
V_629 -> V_632 . V_634 = V_90 -> V_635 ( V_2 ) ;
V_629 -> V_636 . V_630 = V_2 -> V_5 . V_637 ;
V_629 -> V_636 . V_70 = V_2 -> V_5 . V_638 != 0 ;
V_629 -> V_636 . V_639 = V_90 -> V_640 ( V_2 ) ;
V_629 -> V_636 . V_631 = 0 ;
V_629 -> V_641 = 0 ;
V_629 -> V_642 . V_643 = F_291 ( V_2 ) ;
V_629 -> V_642 . V_70 = V_2 -> V_5 . V_644 ;
V_629 -> V_642 . V_645 =
! ! ( V_2 -> V_5 . V_646 & V_647 ) ;
V_629 -> V_642 . V_648 = F_292 ( V_2 ) ;
V_629 -> V_15 = ( V_649
| V_650
| V_651 ) ;
memset ( & V_629 -> V_652 , 0 , sizeof( V_629 -> V_652 ) ) ;
}
static int F_293 ( struct V_1 * V_2 ,
struct V_628 * V_629 )
{
if ( V_629 -> V_15 & ~ ( V_649
| V_653
| V_650
| V_651 ) )
return - V_591 ;
if ( V_629 -> V_69 . V_630 &&
( V_629 -> V_69 . V_18 > 31 || V_629 -> V_69 . V_18 == V_52 ||
F_40 ( V_2 ) ) )
return - V_591 ;
if ( V_629 -> V_15 & V_651 &&
( V_629 -> V_642 . V_643 || V_629 -> V_642 . V_70 ) &&
V_2 -> V_5 . V_654 == V_655 )
return - V_591 ;
F_289 ( V_2 ) ;
V_2 -> V_5 . V_69 . V_70 = V_629 -> V_69 . V_630 ;
V_2 -> V_5 . V_69 . V_18 = V_629 -> V_69 . V_18 ;
V_2 -> V_5 . V_69 . V_72 = V_629 -> V_69 . V_72 ;
V_2 -> V_5 . V_69 . V_63 = V_629 -> V_69 . V_63 ;
V_2 -> V_5 . V_632 . V_70 = V_629 -> V_632 . V_630 ;
V_2 -> V_5 . V_632 . V_18 = V_629 -> V_632 . V_18 ;
V_2 -> V_5 . V_632 . V_633 = V_629 -> V_632 . V_633 ;
if ( V_629 -> V_15 & V_650 )
V_90 -> V_656 ( V_2 ,
V_629 -> V_632 . V_634 ) ;
V_2 -> V_5 . V_637 = V_629 -> V_636 . V_630 ;
if ( V_629 -> V_15 & V_649 )
V_2 -> V_5 . V_638 = V_629 -> V_636 . V_70 ;
V_90 -> V_657 ( V_2 , V_629 -> V_636 . V_639 ) ;
if ( V_629 -> V_15 & V_653 &&
F_92 ( V_2 ) )
V_2 -> V_5 . V_658 -> V_641 = V_629 -> V_641 ;
if ( V_629 -> V_15 & V_651 ) {
T_1 V_646 = V_2 -> V_5 . V_646 ;
if ( V_629 -> V_642 . V_643 )
V_646 |= V_659 ;
else
V_646 &= ~ V_659 ;
F_294 ( V_2 , V_646 ) ;
V_2 -> V_5 . V_644 = V_629 -> V_642 . V_70 ;
if ( V_629 -> V_642 . V_643 ) {
if ( V_629 -> V_642 . V_645 )
V_2 -> V_5 . V_646 |= V_647 ;
else
V_2 -> V_5 . V_646 &= ~ V_647 ;
if ( F_92 ( V_2 ) ) {
if ( V_629 -> V_642 . V_648 )
F_295 ( V_660 , & V_2 -> V_5 . V_658 -> V_661 ) ;
else
F_296 ( V_660 , & V_2 -> V_5 . V_658 -> V_661 ) ;
}
}
}
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
static void F_297 ( struct V_1 * V_2 ,
struct V_662 * V_663 )
{
unsigned long V_199 ;
memcpy ( V_663 -> V_186 , V_2 -> V_5 . V_186 , sizeof( V_2 -> V_5 . V_186 ) ) ;
F_103 ( V_2 , 6 , & V_199 ) ;
V_663 -> V_190 = V_199 ;
V_663 -> V_191 = V_2 -> V_5 . V_191 ;
V_663 -> V_15 = 0 ;
memset ( & V_663 -> V_652 , 0 , sizeof( V_663 -> V_652 ) ) ;
}
static int F_298 ( struct V_1 * V_2 ,
struct V_662 * V_663 )
{
if ( V_663 -> V_15 )
return - V_591 ;
if ( V_663 -> V_190 & ~ 0xffffffffull )
return - V_591 ;
if ( V_663 -> V_191 & ~ 0xffffffffull )
return - V_591 ;
memcpy ( V_2 -> V_5 . V_186 , V_663 -> V_186 , sizeof( V_2 -> V_5 . V_186 ) ) ;
F_96 ( V_2 ) ;
V_2 -> V_5 . V_190 = V_663 -> V_190 ;
F_97 ( V_2 ) ;
V_2 -> V_5 . V_191 = V_663 -> V_191 ;
F_98 ( V_2 ) ;
return 0 ;
}
static void F_299 ( T_13 * V_664 , struct V_1 * V_2 )
{
struct V_665 * V_666 = & V_2 -> V_5 . V_667 . V_668 . V_666 ;
T_2 V_669 = V_666 -> V_670 . V_671 ;
T_2 V_672 ;
memcpy ( V_664 , V_666 , V_673 ) ;
V_669 &= V_2 -> V_5 . V_157 | V_674 ;
* ( T_2 * ) ( V_664 + V_673 ) = V_669 ;
V_672 = V_669 & ~ V_674 ;
while ( V_672 ) {
T_2 V_675 = V_672 & - V_672 ;
int V_150 = F_300 ( V_675 ) - 1 ;
void * V_676 = F_301 ( V_666 , V_675 ) ;
if ( V_676 ) {
T_1 V_504 , V_97 , V_204 , V_212 ;
F_302 ( V_677 , V_150 ,
& V_504 , & V_97 , & V_204 , & V_212 ) ;
if ( V_675 == V_678 )
memcpy ( V_664 + V_97 , & V_2 -> V_5 . V_679 ,
sizeof( V_2 -> V_5 . V_679 ) ) ;
else
memcpy ( V_664 + V_97 , V_676 , V_504 ) ;
}
V_672 -= V_675 ;
}
}
static void F_303 ( struct V_1 * V_2 , T_13 * V_676 )
{
struct V_665 * V_666 = & V_2 -> V_5 . V_667 . V_668 . V_666 ;
T_2 V_669 = * ( T_2 * ) ( V_676 + V_673 ) ;
T_2 V_672 ;
memcpy ( V_666 , V_676 , V_673 ) ;
V_666 -> V_670 . V_671 = V_669 ;
if ( F_250 ( V_680 ) )
V_666 -> V_670 . V_681 = V_149 | V_682 ;
V_672 = V_669 & ~ V_674 ;
while ( V_672 ) {
T_2 V_675 = V_672 & - V_672 ;
int V_150 = F_300 ( V_675 ) - 1 ;
void * V_664 = F_301 ( V_666 , V_675 ) ;
if ( V_664 ) {
T_1 V_504 , V_97 , V_204 , V_212 ;
F_302 ( V_677 , V_150 ,
& V_504 , & V_97 , & V_204 , & V_212 ) ;
if ( V_675 == V_678 )
memcpy ( & V_2 -> V_5 . V_679 , V_676 + V_97 ,
sizeof( V_2 -> V_5 . V_679 ) ) ;
else
memcpy ( V_664 , V_676 + V_97 , V_504 ) ;
}
V_672 -= V_675 ;
}
}
static void F_304 ( struct V_1 * V_2 ,
struct V_683 * V_684 )
{
if ( F_250 ( V_566 ) ) {
memset ( V_684 , 0 , sizeof( struct V_683 ) ) ;
F_299 ( ( T_13 * ) V_684 -> V_685 , V_2 ) ;
} else {
memcpy ( V_684 -> V_685 ,
& V_2 -> V_5 . V_667 . V_668 . V_686 ,
sizeof( struct V_687 ) ) ;
* ( T_2 * ) & V_684 -> V_685 [ V_673 / sizeof( T_1 ) ] =
V_674 ;
}
}
static int F_305 ( struct V_1 * V_2 ,
struct V_683 * V_684 )
{
T_2 V_669 =
* ( T_2 * ) & V_684 -> V_685 [ V_673 / sizeof( T_1 ) ] ;
T_1 V_688 = * ( T_1 * ) & V_684 -> V_685 [ V_689 / sizeof( T_1 ) ] ;
if ( F_250 ( V_566 ) ) {
if ( V_669 & ~ F_306 () ||
V_688 & ~ V_690 )
return - V_591 ;
F_303 ( V_2 , ( T_13 * ) V_684 -> V_685 ) ;
} else {
if ( V_669 & ~ V_674 ||
V_688 & ~ V_690 )
return - V_591 ;
memcpy ( & V_2 -> V_5 . V_667 . V_668 . V_686 ,
V_684 -> V_685 , sizeof( struct V_687 ) ) ;
}
return 0 ;
}
static void F_307 ( struct V_1 * V_2 ,
struct V_691 * V_692 )
{
if ( ! F_250 ( V_566 ) ) {
V_692 -> V_693 = 0 ;
return;
}
V_692 -> V_693 = 1 ;
V_692 -> V_15 = 0 ;
V_692 -> V_694 [ 0 ] . V_151 = V_147 ;
V_692 -> V_694 [ 0 ] . V_23 = V_2 -> V_5 . V_148 ;
}
static int F_308 ( struct V_1 * V_2 ,
struct V_691 * V_692 )
{
int V_3 , V_124 = 0 ;
if ( ! F_250 ( V_566 ) )
return - V_591 ;
if ( V_692 -> V_693 > V_695 || V_692 -> V_15 )
return - V_591 ;
for ( V_3 = 0 ; V_3 < V_692 -> V_693 ; V_3 ++ )
if ( V_692 -> V_694 [ V_3 ] . V_151 == V_147 ) {
V_124 = F_77 ( V_2 , V_147 ,
V_692 -> V_694 [ V_3 ] . V_23 ) ;
break;
}
if ( V_124 )
V_124 = - V_591 ;
return V_124 ;
}
static int F_309 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_360 )
return - V_591 ;
V_2 -> V_5 . V_355 = true ;
F_32 ( V_343 , V_2 ) ;
return 0 ;
}
static int F_310 ( struct V_1 * V_2 ,
struct V_696 * V_697 )
{
if ( V_697 -> V_15 )
return - V_591 ;
switch ( V_697 -> V_697 ) {
case V_532 :
if ( V_697 -> args [ 0 ] )
return - V_591 ;
case V_531 :
if ( ! F_280 ( V_2 -> V_142 ) )
return - V_591 ;
return F_311 ( V_2 , V_697 -> V_697 ==
V_532 ) ;
default:
return - V_591 ;
}
}
long F_312 ( struct V_570 * V_571 ,
unsigned int V_572 , unsigned long V_573 )
{
struct V_1 * V_2 = V_571 -> V_698 ;
void T_14 * V_574 = ( void T_14 * ) V_573 ;
int V_124 ;
union {
struct V_601 * V_699 ;
struct V_683 * V_666 ;
struct V_691 * V_694 ;
void * V_700 ;
} V_701 ;
V_701 . V_700 = NULL ;
switch ( V_572 ) {
case V_702 : {
V_124 = - V_591 ;
if ( ! F_92 ( V_2 ) )
goto V_116;
V_701 . V_699 = F_313 ( sizeof( struct V_601 ) , V_703 ) ;
V_124 = - V_391 ;
if ( ! V_701 . V_699 )
goto V_116;
V_124 = F_268 ( V_2 , V_701 . V_699 ) ;
if ( V_124 )
goto V_116;
V_124 = - V_104 ;
if ( F_247 ( V_574 , V_701 . V_699 , sizeof( struct V_601 ) ) )
goto V_116;
V_124 = 0 ;
break;
}
case V_704 : {
V_124 = - V_591 ;
if ( ! F_92 ( V_2 ) )
goto V_116;
V_701 . V_699 = F_210 ( V_574 , sizeof( * V_701 . V_699 ) ) ;
if ( F_211 ( V_701 . V_699 ) )
return F_212 ( V_701 . V_699 ) ;
V_124 = F_270 ( V_2 , V_701 . V_699 ) ;
break;
}
case V_705 : {
struct V_605 V_606 ;
V_124 = - V_104 ;
if ( F_246 ( & V_606 , V_574 , sizeof V_606 ) )
goto V_116;
V_124 = F_279 ( V_2 , & V_606 ) ;
break;
}
case V_706 : {
V_124 = F_283 ( V_2 ) ;
break;
}
case V_707 : {
V_124 = F_284 ( V_2 ) ;
break;
}
case V_708 : {
struct V_709 T_14 * V_587 = V_574 ;
struct V_709 V_588 ;
V_124 = - V_104 ;
if ( F_246 ( & V_588 , V_587 , sizeof V_588 ) )
goto V_116;
V_124 = F_314 ( V_2 , & V_588 , V_587 -> V_497 ) ;
break;
}
case V_710 : {
struct V_586 T_14 * V_587 = V_574 ;
struct V_586 V_588 ;
V_124 = - V_104 ;
if ( F_246 ( & V_588 , V_587 , sizeof V_588 ) )
goto V_116;
V_124 = F_315 ( V_2 , & V_588 ,
V_587 -> V_497 ) ;
break;
}
case V_711 : {
struct V_586 T_14 * V_587 = V_574 ;
struct V_586 V_588 ;
V_124 = - V_104 ;
if ( F_246 ( & V_588 , V_587 , sizeof V_588 ) )
goto V_116;
V_124 = F_316 ( V_2 , & V_588 ,
V_587 -> V_497 ) ;
if ( V_124 )
goto V_116;
V_124 = - V_104 ;
if ( F_247 ( V_587 , & V_588 , sizeof V_588 ) )
goto V_116;
V_124 = 0 ;
break;
}
case V_712 :
V_124 = F_245 ( V_2 , V_574 , F_116 , 1 ) ;
break;
case V_713 :
V_124 = F_245 ( V_2 , V_574 , F_118 , 0 ) ;
break;
case V_714 : {
struct V_612 V_613 ;
V_124 = - V_104 ;
if ( F_246 ( & V_613 , V_574 , sizeof V_613 ) )
goto V_116;
V_124 = F_285 ( V_2 , & V_613 ) ;
if ( V_124 )
goto V_116;
V_124 = - V_104 ;
if ( F_247 ( V_574 , & V_613 , sizeof V_613 ) )
goto V_116;
V_124 = 0 ;
break;
} ;
case V_715 : {
struct V_716 V_717 ;
int V_498 ;
V_124 = - V_591 ;
if ( ! F_92 ( V_2 ) )
goto V_116;
V_124 = - V_104 ;
if ( F_246 ( & V_717 , V_574 , sizeof V_717 ) )
goto V_116;
V_498 = F_243 ( & V_2 -> V_142 -> V_499 ) ;
V_124 = F_317 ( V_2 , V_717 . V_718 ) ;
F_244 ( & V_2 -> V_142 -> V_499 , V_498 ) ;
break;
}
case V_719 : {
T_2 V_370 ;
V_124 = - V_104 ;
if ( F_246 ( & V_370 , V_574 , sizeof V_370 ) )
goto V_116;
V_124 = F_286 ( V_2 , V_370 ) ;
break;
}
case V_720 : {
struct V_618 V_619 ;
V_124 = - V_104 ;
if ( F_246 ( & V_619 , V_574 , sizeof V_619 ) )
goto V_116;
V_124 = F_287 ( V_2 , & V_619 ) ;
break;
}
case V_721 : {
struct V_628 V_629 ;
F_288 ( V_2 , & V_629 ) ;
V_124 = - V_104 ;
if ( F_247 ( V_574 , & V_629 , sizeof( struct V_628 ) ) )
break;
V_124 = 0 ;
break;
}
case V_722 : {
struct V_628 V_629 ;
V_124 = - V_104 ;
if ( F_246 ( & V_629 , V_574 , sizeof( struct V_628 ) ) )
break;
V_124 = F_293 ( V_2 , & V_629 ) ;
break;
}
case V_723 : {
struct V_662 V_663 ;
F_297 ( V_2 , & V_663 ) ;
V_124 = - V_104 ;
if ( F_247 ( V_574 , & V_663 ,
sizeof( struct V_662 ) ) )
break;
V_124 = 0 ;
break;
}
case V_724 : {
struct V_662 V_663 ;
V_124 = - V_104 ;
if ( F_246 ( & V_663 , V_574 ,
sizeof( struct V_662 ) ) )
break;
V_124 = F_298 ( V_2 , & V_663 ) ;
break;
}
case V_725 : {
V_701 . V_666 = F_313 ( sizeof( struct V_683 ) , V_703 ) ;
V_124 = - V_391 ;
if ( ! V_701 . V_666 )
break;
F_304 ( V_2 , V_701 . V_666 ) ;
V_124 = - V_104 ;
if ( F_247 ( V_574 , V_701 . V_666 , sizeof( struct V_683 ) ) )
break;
V_124 = 0 ;
break;
}
case V_726 : {
V_701 . V_666 = F_210 ( V_574 , sizeof( * V_701 . V_666 ) ) ;
if ( F_211 ( V_701 . V_666 ) )
return F_212 ( V_701 . V_666 ) ;
V_124 = F_305 ( V_2 , V_701 . V_666 ) ;
break;
}
case V_727 : {
V_701 . V_694 = F_313 ( sizeof( struct V_691 ) , V_703 ) ;
V_124 = - V_391 ;
if ( ! V_701 . V_694 )
break;
F_307 ( V_2 , V_701 . V_694 ) ;
V_124 = - V_104 ;
if ( F_247 ( V_574 , V_701 . V_694 ,
sizeof( struct V_691 ) ) )
break;
V_124 = 0 ;
break;
}
case V_728 : {
V_701 . V_694 = F_210 ( V_574 , sizeof( * V_701 . V_694 ) ) ;
if ( F_211 ( V_701 . V_694 ) )
return F_212 ( V_701 . V_694 ) ;
V_124 = F_308 ( V_2 , V_701 . V_694 ) ;
break;
}
case V_729 : {
T_1 V_271 ;
V_124 = - V_591 ;
V_271 = ( T_1 ) V_573 ;
if ( V_271 >= V_730 )
goto V_116;
if ( V_271 == 0 )
V_271 = V_277 ;
if ( ! F_141 ( V_2 , V_271 ) )
V_124 = 0 ;
goto V_116;
}
case V_731 : {
V_124 = V_2 -> V_5 . V_288 ;
goto V_116;
}
case V_732 : {
V_124 = F_309 ( V_2 ) ;
goto V_116;
}
case V_733 : {
struct V_696 V_697 ;
V_124 = - V_104 ;
if ( F_246 ( & V_697 , V_574 , sizeof( V_697 ) ) )
goto V_116;
V_124 = F_310 ( V_2 , & V_697 ) ;
break;
}
default:
V_124 = - V_591 ;
}
V_116:
F_214 ( V_701 . V_700 ) ;
return V_124 ;
}
int F_318 ( struct V_1 * V_2 , struct V_734 * V_735 )
{
return V_736 ;
}
static int F_319 ( struct V_142 * V_142 , unsigned long V_626 )
{
int V_111 ;
if ( V_626 > ( unsigned int ) ( - 3 * V_110 ) )
return - V_591 ;
V_111 = V_90 -> V_737 ( V_142 , V_626 ) ;
return V_111 ;
}
static int F_320 ( struct V_142 * V_142 ,
T_2 V_738 )
{
V_142 -> V_5 . V_739 = V_738 ;
return 0 ;
}
static int F_321 ( struct V_142 * V_142 ,
T_1 V_740 )
{
if ( V_740 < V_741 )
return - V_591 ;
F_322 ( & V_142 -> V_742 ) ;
F_323 ( V_142 , V_740 ) ;
V_142 -> V_5 . V_743 = V_740 ;
F_324 ( & V_142 -> V_742 ) ;
return 0 ;
}
static int F_325 ( struct V_142 * V_142 )
{
return V_142 -> V_5 . V_744 ;
}
static int F_326 ( struct V_142 * V_142 , struct V_745 * V_746 )
{
struct V_747 * V_748 = V_142 -> V_5 . V_749 ;
int V_124 ;
V_124 = 0 ;
switch ( V_746 -> V_750 ) {
case V_751 :
memcpy ( & V_746 -> V_746 . V_748 , & V_748 -> V_752 [ 0 ] ,
sizeof( struct V_753 ) ) ;
break;
case V_754 :
memcpy ( & V_746 -> V_746 . V_748 , & V_748 -> V_752 [ 1 ] ,
sizeof( struct V_753 ) ) ;
break;
case V_755 :
F_327 ( V_142 , & V_746 -> V_746 . V_756 ) ;
break;
default:
V_124 = - V_591 ;
break;
}
return V_124 ;
}
static int F_328 ( struct V_142 * V_142 , struct V_745 * V_746 )
{
struct V_747 * V_748 = V_142 -> V_5 . V_749 ;
int V_124 ;
V_124 = 0 ;
switch ( V_746 -> V_750 ) {
case V_751 :
F_162 ( & V_748 -> V_757 ) ;
memcpy ( & V_748 -> V_752 [ 0 ] , & V_746 -> V_746 . V_748 ,
sizeof( struct V_753 ) ) ;
F_163 ( & V_748 -> V_757 ) ;
break;
case V_754 :
F_162 ( & V_748 -> V_757 ) ;
memcpy ( & V_748 -> V_752 [ 1 ] , & V_746 -> V_746 . V_748 ,
sizeof( struct V_753 ) ) ;
F_163 ( & V_748 -> V_757 ) ;
break;
case V_755 :
F_329 ( V_142 , & V_746 -> V_746 . V_756 ) ;
break;
default:
V_124 = - V_591 ;
break;
}
F_330 ( V_748 ) ;
return V_124 ;
}
static int F_331 ( struct V_142 * V_142 , struct V_758 * V_759 )
{
struct V_760 * V_761 = & V_142 -> V_5 . V_762 -> V_763 ;
F_193 ( sizeof( * V_759 ) != sizeof( V_761 -> V_764 ) ) ;
F_322 ( & V_761 -> V_757 ) ;
memcpy ( V_759 , & V_761 -> V_764 , sizeof( * V_759 ) ) ;
F_324 ( & V_761 -> V_757 ) ;
return 0 ;
}
static int F_332 ( struct V_142 * V_142 , struct V_758 * V_759 )
{
int V_3 ;
struct V_765 * V_766 = V_142 -> V_5 . V_762 ;
F_322 ( & V_766 -> V_763 . V_757 ) ;
memcpy ( & V_766 -> V_763 . V_764 , V_759 , sizeof( * V_759 ) ) ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
F_333 ( V_766 , V_3 , V_759 -> V_764 [ V_3 ] . V_767 , 0 ) ;
F_324 ( & V_766 -> V_763 . V_757 ) ;
return 0 ;
}
static int F_334 ( struct V_142 * V_142 , struct V_768 * V_759 )
{
F_322 ( & V_142 -> V_5 . V_762 -> V_763 . V_757 ) ;
memcpy ( V_759 -> V_764 , & V_142 -> V_5 . V_762 -> V_763 . V_764 ,
sizeof( V_759 -> V_764 ) ) ;
V_759 -> V_15 = V_142 -> V_5 . V_762 -> V_763 . V_15 ;
F_324 ( & V_142 -> V_5 . V_762 -> V_763 . V_757 ) ;
memset ( & V_759 -> V_652 , 0 , sizeof( V_759 -> V_652 ) ) ;
return 0 ;
}
static int F_335 ( struct V_142 * V_142 , struct V_768 * V_759 )
{
int V_769 = 0 ;
int V_3 ;
T_1 V_770 , V_771 ;
struct V_765 * V_766 = V_142 -> V_5 . V_762 ;
F_322 ( & V_766 -> V_763 . V_757 ) ;
V_770 = V_766 -> V_763 . V_15 & V_772 ;
V_771 = V_759 -> V_15 & V_772 ;
if ( ! V_770 && V_771 )
V_769 = 1 ;
memcpy ( & V_766 -> V_763 . V_764 , & V_759 -> V_764 ,
sizeof( V_766 -> V_763 . V_764 ) ) ;
V_766 -> V_763 . V_15 = V_759 -> V_15 ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
F_333 ( V_766 , V_3 , V_766 -> V_763 . V_764 [ V_3 ] . V_767 ,
V_769 && V_3 == 0 ) ;
F_324 ( & V_766 -> V_763 . V_757 ) ;
return 0 ;
}
static int F_336 ( struct V_142 * V_142 ,
struct V_773 * V_774 )
{
struct V_765 * V_766 = V_142 -> V_5 . V_762 ;
if ( ! V_766 )
return - V_608 ;
F_322 ( & V_766 -> V_763 . V_757 ) ;
F_337 ( V_766 , V_774 -> V_775 ) ;
F_324 ( & V_766 -> V_763 . V_757 ) ;
return 0 ;
}
int F_338 ( struct V_142 * V_142 , struct V_776 * log )
{
bool V_777 = false ;
int V_124 ;
F_322 ( & V_142 -> V_742 ) ;
if ( V_90 -> V_778 )
V_90 -> V_778 ( V_142 ) ;
V_124 = F_339 ( V_142 , log , & V_777 ) ;
F_340 ( & V_142 -> V_742 ) ;
if ( V_777 )
F_341 ( V_142 ) ;
F_324 ( & V_142 -> V_742 ) ;
return V_124 ;
}
int F_342 ( struct V_142 * V_142 , struct V_779 * V_780 ,
bool V_781 )
{
if ( ! F_280 ( V_142 ) )
return - V_608 ;
V_780 -> V_467 = F_343 ( V_142 , V_782 ,
V_780 -> V_606 , V_780 -> V_783 ,
V_781 ) ;
return 0 ;
}
static int F_344 ( struct V_142 * V_142 ,
struct V_696 * V_697 )
{
int V_124 ;
if ( V_697 -> V_15 )
return - V_591 ;
switch ( V_697 -> V_697 ) {
case V_546 :
V_142 -> V_5 . V_784 = V_697 -> args [ 0 ] ;
V_124 = 0 ;
break;
case V_548 : {
F_322 ( & V_142 -> V_757 ) ;
V_124 = - V_591 ;
if ( V_697 -> args [ 0 ] > V_785 )
goto V_786;
V_124 = - V_610 ;
if ( F_280 ( V_142 ) )
goto V_786;
if ( V_142 -> V_787 )
goto V_786;
V_124 = F_345 ( V_142 ) ;
if ( V_124 )
goto V_786;
F_196 () ;
V_142 -> V_5 . V_788 = V_789 ;
V_142 -> V_5 . V_790 = V_697 -> args [ 0 ] ;
V_124 = 0 ;
V_786:
F_324 ( & V_142 -> V_757 ) ;
break;
}
case V_568 :
V_124 = - V_591 ;
if ( V_697 -> args [ 0 ] & ~ V_569 )
break;
if ( V_697 -> args [ 0 ] & V_791 )
V_142 -> V_5 . V_792 = true ;
if ( V_697 -> args [ 0 ] & V_793 )
V_142 -> V_5 . V_794 = true ;
V_124 = 0 ;
break;
default:
V_124 = - V_591 ;
break;
}
return V_124 ;
}
long F_346 ( struct V_570 * V_571 ,
unsigned int V_572 , unsigned long V_573 )
{
struct V_142 * V_142 = V_571 -> V_698 ;
void T_14 * V_574 = ( void T_14 * ) V_573 ;
int V_124 = - V_795 ;
union {
struct V_758 V_759 ;
struct V_768 V_796 ;
struct V_797 V_798 ;
} V_701 ;
switch ( V_572 ) {
case V_799 :
V_124 = F_319 ( V_142 , V_573 ) ;
break;
case V_800 : {
T_2 V_738 ;
V_124 = - V_104 ;
if ( F_246 ( & V_738 , V_574 , sizeof V_738 ) )
goto V_116;
V_124 = F_320 ( V_142 , V_738 ) ;
break;
}
case V_801 :
V_124 = F_321 ( V_142 , V_573 ) ;
break;
case V_802 :
V_124 = F_325 ( V_142 ) ;
break;
case V_803 : {
F_322 ( & V_142 -> V_757 ) ;
V_124 = - V_610 ;
if ( F_280 ( V_142 ) )
goto V_804;
V_124 = - V_591 ;
if ( V_142 -> V_787 )
goto V_804;
V_124 = F_347 ( V_142 ) ;
if ( V_124 )
goto V_804;
V_124 = F_348 ( V_142 ) ;
if ( V_124 ) {
F_349 ( V_142 ) ;
goto V_804;
}
V_124 = F_350 ( V_142 ) ;
if ( V_124 ) {
F_351 ( V_142 ) ;
F_349 ( V_142 ) ;
goto V_804;
}
F_196 () ;
V_142 -> V_5 . V_788 = V_805 ;
V_804:
F_324 ( & V_142 -> V_757 ) ;
break;
}
case V_806 :
V_701 . V_798 . V_15 = V_807 ;
goto V_808;
case V_809 :
V_124 = - V_104 ;
if ( F_246 ( & V_701 . V_798 , V_574 ,
sizeof( struct V_797 ) ) )
goto V_116;
V_808:
F_322 ( & V_142 -> V_757 ) ;
V_124 = - V_610 ;
if ( V_142 -> V_5 . V_762 )
goto V_810;
V_124 = - V_391 ;
V_142 -> V_5 . V_762 = F_352 ( V_142 , V_701 . V_798 . V_15 ) ;
if ( V_142 -> V_5 . V_762 )
V_124 = 0 ;
V_810:
F_324 ( & V_142 -> V_757 ) ;
break;
case V_811 : {
struct V_745 * V_746 ;
V_746 = F_210 ( V_574 , sizeof( * V_746 ) ) ;
if ( F_211 ( V_746 ) ) {
V_124 = F_212 ( V_746 ) ;
goto V_116;
}
V_124 = - V_608 ;
if ( ! F_353 ( V_142 ) )
goto V_812;
V_124 = F_326 ( V_142 , V_746 ) ;
if ( V_124 )
goto V_812;
V_124 = - V_104 ;
if ( F_247 ( V_574 , V_746 , sizeof *V_746 ) )
goto V_812;
V_124 = 0 ;
V_812:
F_214 ( V_746 ) ;
break;
}
case V_813 : {
struct V_745 * V_746 ;
V_746 = F_210 ( V_574 , sizeof( * V_746 ) ) ;
if ( F_211 ( V_746 ) ) {
V_124 = F_212 ( V_746 ) ;
goto V_116;
}
V_124 = - V_608 ;
if ( ! F_353 ( V_142 ) )
goto V_814;
V_124 = F_328 ( V_142 , V_746 ) ;
if ( V_124 )
goto V_814;
V_124 = 0 ;
V_814:
F_214 ( V_746 ) ;
break;
}
case V_815 : {
V_124 = - V_104 ;
if ( F_246 ( & V_701 . V_759 , V_574 , sizeof( struct V_758 ) ) )
goto V_116;
V_124 = - V_608 ;
if ( ! V_142 -> V_5 . V_762 )
goto V_116;
V_124 = F_331 ( V_142 , & V_701 . V_759 ) ;
if ( V_124 )
goto V_116;
V_124 = - V_104 ;
if ( F_247 ( V_574 , & V_701 . V_759 , sizeof( struct V_758 ) ) )
goto V_116;
V_124 = 0 ;
break;
}
case V_816 : {
V_124 = - V_104 ;
if ( F_246 ( & V_701 . V_759 , V_574 , sizeof V_701 . V_759 ) )
goto V_116;
V_124 = - V_608 ;
if ( ! V_142 -> V_5 . V_762 )
goto V_116;
V_124 = F_332 ( V_142 , & V_701 . V_759 ) ;
break;
}
case V_817 : {
V_124 = - V_608 ;
if ( ! V_142 -> V_5 . V_762 )
goto V_116;
V_124 = F_334 ( V_142 , & V_701 . V_796 ) ;
if ( V_124 )
goto V_116;
V_124 = - V_104 ;
if ( F_247 ( V_574 , & V_701 . V_796 , sizeof( V_701 . V_796 ) ) )
goto V_116;
V_124 = 0 ;
break;
}
case V_818 : {
V_124 = - V_104 ;
if ( F_246 ( & V_701 . V_796 , V_574 , sizeof( V_701 . V_796 ) ) )
goto V_116;
V_124 = - V_608 ;
if ( ! V_142 -> V_5 . V_762 )
goto V_116;
V_124 = F_335 ( V_142 , & V_701 . V_796 ) ;
break;
}
case V_819 : {
struct V_773 V_774 ;
V_124 = - V_104 ;
if ( F_246 ( & V_774 , V_574 , sizeof( V_774 ) ) )
goto V_116;
V_124 = F_336 ( V_142 , & V_774 ) ;
break;
}
case V_820 :
V_124 = 0 ;
F_322 ( & V_142 -> V_757 ) ;
if ( V_142 -> V_787 )
V_124 = - V_821 ;
else
V_142 -> V_5 . V_822 = V_573 ;
F_324 ( & V_142 -> V_757 ) ;
break;
case V_823 : {
V_124 = - V_104 ;
if ( F_246 ( & V_142 -> V_5 . F_209 , V_574 ,
sizeof( struct V_824 ) ) )
goto V_116;
V_124 = - V_591 ;
if ( V_142 -> V_5 . F_209 . V_15 )
goto V_116;
V_124 = 0 ;
break;
}
case V_825 : {
struct V_826 V_827 ;
T_2 V_828 ;
V_124 = - V_104 ;
if ( F_246 ( & V_827 , V_574 , sizeof( V_827 ) ) )
goto V_116;
V_124 = - V_591 ;
if ( V_827 . V_15 )
goto V_116;
V_124 = 0 ;
F_183 ( V_142 ) ;
V_828 = F_186 ( V_142 ) ;
V_142 -> V_5 . V_252 += V_827 . clock - V_828 ;
F_182 ( V_142 , V_343 ) ;
break;
}
case V_829 : {
struct V_826 V_827 ;
T_2 V_828 ;
V_828 = F_186 ( V_142 ) ;
V_827 . clock = V_828 ;
V_827 . V_15 = V_142 -> V_5 . V_300 ? V_551 : 0 ;
memset ( & V_827 . V_631 , 0 , sizeof( V_827 . V_631 ) ) ;
V_124 = - V_104 ;
if ( F_247 ( V_574 , & V_827 , sizeof( V_827 ) ) )
goto V_116;
V_124 = 0 ;
break;
}
case V_733 : {
struct V_696 V_697 ;
V_124 = - V_104 ;
if ( F_246 ( & V_697 , V_574 , sizeof( V_697 ) ) )
goto V_116;
V_124 = F_344 ( V_142 , & V_697 ) ;
break;
}
default:
V_124 = - V_795 ;
}
V_116:
return V_124 ;
}
static void F_354 ( void )
{
T_1 V_830 [ 2 ] ;
unsigned V_3 , V_831 ;
for ( V_3 = V_831 = 0 ; V_3 < F_56 ( V_582 ) ; V_3 ++ ) {
if ( F_355 ( V_582 [ V_3 ] , & V_830 [ 0 ] , & V_830 [ 1 ] ) < 0 )
continue;
switch ( V_582 [ V_3 ] ) {
case V_832 :
if ( ! V_90 -> V_833 () )
continue;
break;
case V_834 :
if ( ! V_90 -> V_835 () )
continue;
break;
default:
break;
}
if ( V_831 < V_3 )
V_582 [ V_831 ] = V_582 [ V_3 ] ;
V_831 ++ ;
}
V_579 = V_831 ;
for ( V_3 = V_831 = 0 ; V_3 < F_56 ( V_583 ) ; V_3 ++ ) {
switch ( V_583 [ V_3 ] ) {
case V_431 :
if ( ! V_90 -> V_554 () )
continue;
break;
default:
break;
}
if ( V_831 < V_3 )
V_583 [ V_831 ] = V_583 [ V_3 ] ;
V_831 ++ ;
}
V_580 = V_831 ;
}
static int F_356 ( struct V_1 * V_2 , T_6 V_626 , int V_98 ,
const void * V_270 )
{
int V_836 = 0 ;
int V_503 ;
do {
V_503 = F_357 ( V_98 , 8 ) ;
if ( ! ( F_92 ( V_2 ) &&
! F_358 ( V_2 , & V_2 -> V_5 . V_658 -> V_837 , V_626 , V_503 , V_270 ) )
&& F_359 ( V_2 , V_838 , V_626 , V_503 , V_270 ) )
break;
V_836 += V_503 ;
V_626 += V_503 ;
V_98 -= V_503 ;
V_270 += V_503 ;
} while ( V_98 );
return V_836 ;
}
static int F_360 ( struct V_1 * V_2 , T_6 V_626 , int V_98 , void * V_270 )
{
int V_836 = 0 ;
int V_503 ;
do {
V_503 = F_357 ( V_98 , 8 ) ;
if ( ! ( F_92 ( V_2 ) &&
! F_361 ( V_2 , & V_2 -> V_5 . V_658 -> V_837 ,
V_626 , V_503 , V_270 ) )
&& F_362 ( V_2 , V_838 , V_626 , V_503 , V_270 ) )
break;
F_363 ( V_839 , V_503 , V_626 , * ( T_2 * ) V_270 ) ;
V_836 += V_503 ;
V_626 += V_503 ;
V_98 -= V_503 ;
V_270 += V_503 ;
} while ( V_98 );
return V_836 ;
}
static void F_364 ( struct V_1 * V_2 ,
struct V_840 * V_841 , int V_842 )
{
V_90 -> V_843 ( V_2 , V_841 , V_842 ) ;
}
void F_365 ( struct V_1 * V_2 ,
struct V_840 * V_841 , int V_842 )
{
V_90 -> V_844 ( V_2 , V_841 , V_842 ) ;
}
T_6 F_366 ( struct V_1 * V_2 , T_6 V_393 , T_1 V_99 ,
struct V_74 * V_69 )
{
T_6 V_845 ;
F_15 ( ! F_43 ( V_2 ) ) ;
V_99 |= V_114 ;
V_845 = V_2 -> V_5 . V_86 . V_846 ( V_2 , V_393 , V_99 , V_69 ) ;
return V_845 ;
}
T_6 F_367 ( struct V_1 * V_2 , T_15 V_847 ,
struct V_74 * V_69 )
{
T_1 V_99 = ( V_90 -> V_91 ( V_2 ) == 3 ) ? V_114 : 0 ;
return V_2 -> V_5 . V_106 -> V_846 ( V_2 , V_847 , V_99 , V_69 ) ;
}
T_6 F_368 ( struct V_1 * V_2 , T_15 V_847 ,
struct V_74 * V_69 )
{
T_1 V_99 = ( V_90 -> V_91 ( V_2 ) == 3 ) ? V_114 : 0 ;
V_99 |= V_848 ;
return V_2 -> V_5 . V_106 -> V_846 ( V_2 , V_847 , V_99 , V_69 ) ;
}
T_6 F_369 ( struct V_1 * V_2 , T_15 V_847 ,
struct V_74 * V_69 )
{
T_1 V_99 = ( V_90 -> V_91 ( V_2 ) == 3 ) ? V_114 : 0 ;
V_99 |= V_115 ;
return V_2 -> V_5 . V_106 -> V_846 ( V_2 , V_847 , V_99 , V_69 ) ;
}
T_6 F_370 ( struct V_1 * V_2 , T_15 V_847 ,
struct V_74 * V_69 )
{
return V_2 -> V_5 . V_106 -> V_846 ( V_2 , V_847 , 0 , V_69 ) ;
}
static int F_371 ( T_15 V_626 , void * V_199 , unsigned int V_849 ,
struct V_1 * V_2 , T_1 V_99 ,
struct V_74 * V_69 )
{
void * V_39 = V_199 ;
int V_124 = V_850 ;
while ( V_849 ) {
T_6 V_393 = V_2 -> V_5 . V_106 -> V_846 ( V_2 , V_626 , V_99 ,
V_69 ) ;
unsigned V_97 = V_626 & ( V_110 - 1 ) ;
unsigned V_851 = F_357 ( V_849 , ( unsigned ) V_110 - V_97 ) ;
int V_111 ;
if ( V_393 == V_103 )
return V_852 ;
V_111 = F_53 ( V_2 , V_393 >> V_109 , V_39 ,
V_97 , V_851 ) ;
if ( V_111 < 0 ) {
V_124 = V_853 ;
goto V_116;
}
V_849 -= V_851 ;
V_39 += V_851 ;
V_626 += V_851 ;
}
V_116:
return V_124 ;
}
static int F_372 ( struct V_854 * V_855 ,
T_15 V_626 , void * V_199 , unsigned int V_849 ,
struct V_74 * V_69 )
{
struct V_1 * V_2 = F_373 ( V_855 ) ;
T_1 V_99 = ( V_90 -> V_91 ( V_2 ) == 3 ) ? V_114 : 0 ;
unsigned V_97 ;
int V_111 ;
T_6 V_393 = V_2 -> V_5 . V_106 -> V_846 ( V_2 , V_626 , V_99 | V_848 ,
V_69 ) ;
if ( F_172 ( V_393 == V_103 ) )
return V_852 ;
V_97 = V_626 & ( V_110 - 1 ) ;
if ( F_30 ( V_97 + V_849 > V_110 ) )
V_849 = ( unsigned ) V_110 - V_97 ;
V_111 = F_53 ( V_2 , V_393 >> V_109 , V_199 ,
V_97 , V_849 ) ;
if ( F_172 ( V_111 < 0 ) )
return V_853 ;
return V_850 ;
}
int F_374 ( struct V_854 * V_855 ,
T_15 V_626 , void * V_199 , unsigned int V_849 ,
struct V_74 * V_69 )
{
struct V_1 * V_2 = F_373 ( V_855 ) ;
T_1 V_99 = ( V_90 -> V_91 ( V_2 ) == 3 ) ? V_114 : 0 ;
return F_371 ( V_626 , V_199 , V_849 , V_2 , V_99 ,
V_69 ) ;
}
static int F_375 ( struct V_854 * V_855 ,
T_15 V_626 , void * V_199 , unsigned int V_849 ,
struct V_74 * V_69 )
{
struct V_1 * V_2 = F_373 ( V_855 ) ;
return F_371 ( V_626 , V_199 , V_849 , V_2 , 0 , V_69 ) ;
}
static int F_376 ( struct V_854 * V_855 ,
unsigned long V_626 , void * V_199 , unsigned int V_849 )
{
struct V_1 * V_2 = F_373 ( V_855 ) ;
int V_124 = F_377 ( V_2 , V_626 , V_199 , V_849 ) ;
return V_124 < 0 ? V_853 : V_850 ;
}
int F_378 ( struct V_854 * V_855 ,
T_15 V_626 , void * V_199 ,
unsigned int V_849 ,
struct V_74 * V_69 )
{
struct V_1 * V_2 = F_373 ( V_855 ) ;
void * V_39 = V_199 ;
int V_124 = V_850 ;
while ( V_849 ) {
T_6 V_393 = V_2 -> V_5 . V_106 -> V_846 ( V_2 , V_626 ,
V_115 ,
V_69 ) ;
unsigned V_97 = V_626 & ( V_110 - 1 ) ;
unsigned V_856 = F_357 ( V_849 , ( unsigned ) V_110 - V_97 ) ;
int V_111 ;
if ( V_393 == V_103 )
return V_852 ;
V_111 = F_213 ( V_2 , V_393 , V_39 , V_856 ) ;
if ( V_111 < 0 ) {
V_124 = V_853 ;
goto V_116;
}
V_849 -= V_856 ;
V_39 += V_856 ;
V_626 += V_856 ;
}
V_116:
return V_124 ;
}
static int F_379 ( struct V_1 * V_2 , unsigned long V_847 ,
T_6 V_393 , bool V_857 )
{
if ( ( V_393 & V_387 ) == V_858 )
return 1 ;
if ( F_380 ( V_2 , V_393 ) ) {
F_381 ( V_847 , V_393 , V_857 , true ) ;
return 1 ;
}
return 0 ;
}
static int F_382 ( struct V_1 * V_2 , unsigned long V_847 ,
T_6 * V_393 , struct V_74 * V_69 ,
bool V_857 )
{
T_1 V_99 = ( ( V_90 -> V_91 ( V_2 ) == 3 ) ? V_114 : 0 )
| ( V_857 ? V_115 : 0 ) ;
if ( F_383 ( V_2 , V_847 )
&& ! F_384 ( V_2 , V_2 -> V_5 . V_106 ,
V_2 -> V_5 . V_99 , 0 , V_99 ) ) {
* V_393 = V_2 -> V_5 . V_859 << V_109 |
( V_847 & ( V_110 - 1 ) ) ;
F_381 ( V_847 , * V_393 , V_857 , false ) ;
return 1 ;
}
* V_393 = V_2 -> V_5 . V_106 -> V_846 ( V_2 , V_847 , V_99 , V_69 ) ;
if ( * V_393 == V_103 )
return - 1 ;
return F_379 ( V_2 , V_847 , * V_393 , V_857 ) ;
}
int F_385 ( struct V_1 * V_2 , T_6 V_393 ,
const void * V_199 , int V_849 )
{
int V_111 ;
V_111 = F_213 ( V_2 , V_393 , V_199 , V_849 ) ;
if ( V_111 < 0 )
return 0 ;
F_386 ( V_2 , V_393 , V_199 , V_849 ) ;
return 1 ;
}
static int F_387 ( struct V_1 * V_2 , void * V_199 , int V_849 )
{
if ( V_2 -> V_860 ) {
F_363 ( V_839 , V_849 ,
V_2 -> V_861 [ 0 ] . V_393 , * ( T_2 * ) V_199 ) ;
V_2 -> V_860 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_388 ( struct V_1 * V_2 , T_6 V_393 ,
void * V_199 , int V_849 )
{
return ! F_377 ( V_2 , V_393 , V_199 , V_849 ) ;
}
static int F_389 ( struct V_1 * V_2 , T_6 V_393 ,
void * V_199 , int V_849 )
{
return F_385 ( V_2 , V_393 , V_199 , V_849 ) ;
}
static int F_390 ( struct V_1 * V_2 , T_6 V_393 , int V_849 , void * V_199 )
{
F_363 ( V_862 , V_849 , V_393 , * ( T_2 * ) V_199 ) ;
return F_356 ( V_2 , V_393 , V_849 , V_199 ) ;
}
static int F_391 ( struct V_1 * V_2 , T_6 V_393 ,
void * V_199 , int V_849 )
{
F_363 ( V_863 , V_849 , V_393 , 0 ) ;
return V_853 ;
}
static int F_392 ( struct V_1 * V_2 , T_6 V_393 ,
void * V_199 , int V_849 )
{
struct V_864 * V_865 = & V_2 -> V_861 [ 0 ] ;
memcpy ( V_2 -> V_866 -> V_867 . V_39 , V_865 -> V_39 , F_357 ( 8u , V_865 -> V_98 ) ) ;
return V_850 ;
}
static int F_393 ( unsigned long V_626 , void * V_199 ,
unsigned int V_849 ,
struct V_74 * V_69 ,
struct V_1 * V_2 ,
const struct V_868 * V_869 )
{
T_6 V_393 ;
int V_836 , V_111 ;
bool V_857 = V_869 -> V_857 ;
struct V_864 * V_865 ;
struct V_854 * V_855 = & V_2 -> V_5 . V_870 ;
if ( V_2 -> V_5 . V_871 &&
F_394 ( V_855 ) &&
F_379 ( V_2 , V_626 , V_69 -> V_81 , V_857 ) &&
( V_626 & ~ V_387 ) == ( V_69 -> V_81 & ~ V_387 ) ) {
V_393 = V_69 -> V_81 ;
goto V_867;
}
V_111 = F_382 ( V_2 , V_626 , & V_393 , V_69 , V_857 ) ;
if ( V_111 < 0 )
return V_852 ;
if ( V_111 )
goto V_867;
if ( V_869 -> V_872 ( V_2 , V_393 , V_199 , V_849 ) )
return V_850 ;
V_867:
V_836 = V_869 -> V_873 ( V_2 , V_393 , V_849 , V_199 ) ;
if ( V_836 == V_849 )
return V_850 ;
V_393 += V_836 ;
V_849 -= V_836 ;
V_199 += V_836 ;
F_30 ( V_2 -> V_874 >= V_875 ) ;
V_865 = & V_2 -> V_861 [ V_2 -> V_874 ++ ] ;
V_865 -> V_393 = V_393 ;
V_865 -> V_39 = V_199 ;
V_865 -> V_98 = V_849 ;
return V_850 ;
}
static int F_395 ( struct V_854 * V_855 ,
unsigned long V_626 ,
void * V_199 , unsigned int V_849 ,
struct V_74 * V_69 ,
const struct V_868 * V_869 )
{
struct V_1 * V_2 = F_373 ( V_855 ) ;
T_6 V_393 ;
int V_876 ;
if ( V_869 -> V_877 &&
V_869 -> V_877 ( V_2 , V_199 , V_849 ) )
return V_850 ;
V_2 -> V_874 = 0 ;
if ( ( ( V_626 + V_849 - 1 ) ^ V_626 ) & V_387 ) {
int V_878 ;
V_878 = - V_626 & ~ V_387 ;
V_876 = F_393 ( V_626 , V_199 , V_878 , V_69 ,
V_2 , V_869 ) ;
if ( V_876 != V_850 )
return V_876 ;
V_626 += V_878 ;
if ( V_855 -> V_334 != V_879 )
V_626 = ( T_1 ) V_626 ;
V_199 += V_878 ;
V_849 -= V_878 ;
}
V_876 = F_393 ( V_626 , V_199 , V_849 , V_69 ,
V_2 , V_869 ) ;
if ( V_876 != V_850 )
return V_876 ;
if ( ! V_2 -> V_874 )
return V_876 ;
V_393 = V_2 -> V_861 [ 0 ] . V_393 ;
V_2 -> V_880 = 1 ;
V_2 -> V_881 = 0 ;
V_2 -> V_866 -> V_867 . V_98 = F_357 ( 8u , V_2 -> V_861 [ 0 ] . V_98 ) ;
V_2 -> V_866 -> V_867 . V_882 = V_2 -> V_883 = V_869 -> V_857 ;
V_2 -> V_866 -> V_884 = V_885 ;
V_2 -> V_866 -> V_867 . V_886 = V_393 ;
return V_869 -> V_887 ( V_2 , V_393 , V_199 , V_849 ) ;
}
static int F_396 ( struct V_854 * V_855 ,
unsigned long V_626 ,
void * V_199 ,
unsigned int V_849 ,
struct V_74 * V_69 )
{
return F_395 ( V_855 , V_626 , V_199 , V_849 ,
V_69 , & V_888 ) ;
}
static int F_397 ( struct V_854 * V_855 ,
unsigned long V_626 ,
const void * V_199 ,
unsigned int V_849 ,
struct V_74 * V_69 )
{
return F_395 ( V_855 , V_626 , ( void * ) V_199 , V_849 ,
V_69 , & V_889 ) ;
}
static int F_398 ( struct V_854 * V_855 ,
unsigned long V_626 ,
const void * V_890 ,
const void * V_891 ,
unsigned int V_849 ,
struct V_74 * V_69 )
{
struct V_1 * V_2 = F_373 ( V_855 ) ;
T_6 V_393 ;
struct V_389 * V_389 ;
char * V_892 ;
bool V_893 ;
if ( V_849 > 8 || ( V_849 & ( V_849 - 1 ) ) )
goto V_894;
V_393 = F_369 ( V_2 , V_626 , NULL ) ;
if ( V_393 == V_103 ||
( V_393 & V_387 ) == V_858 )
goto V_894;
if ( ( ( V_393 + V_849 - 1 ) & V_387 ) != ( V_393 & V_387 ) )
goto V_894;
V_389 = F_399 ( V_2 , V_393 >> V_109 ) ;
if ( F_400 ( V_389 ) )
goto V_894;
V_892 = F_401 ( V_389 ) ;
V_892 += F_402 ( V_393 ) ;
switch ( V_849 ) {
case 1 :
V_893 = F_403 ( T_13 , V_892 , V_890 , V_891 ) ;
break;
case 2 :
V_893 = F_403 ( V_895 , V_892 , V_890 , V_891 ) ;
break;
case 4 :
V_893 = F_403 ( T_1 , V_892 , V_890 , V_891 ) ;
break;
case 8 :
V_893 = F_404 ( V_892 , V_890 , V_891 ) ;
break;
default:
F_27 () ;
}
F_405 ( V_892 ) ;
F_406 ( V_389 ) ;
if ( ! V_893 )
return V_896 ;
F_407 ( V_2 , V_393 >> V_109 ) ;
F_386 ( V_2 , V_393 , V_891 , V_849 ) ;
return V_850 ;
V_894:
F_408 ( V_897 L_20 ) ;
return F_397 ( V_855 , V_626 , V_891 , V_849 , V_69 ) ;
}
static int F_409 ( struct V_1 * V_2 , void * V_898 )
{
int V_124 = 0 , V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 . V_899 . V_767 ; V_3 ++ ) {
if ( V_2 -> V_5 . V_899 . V_900 )
V_124 = F_362 ( V_2 , V_901 , V_2 -> V_5 . V_899 . V_902 ,
V_2 -> V_5 . V_899 . V_504 , V_898 ) ;
else
V_124 = F_359 ( V_2 , V_901 ,
V_2 -> V_5 . V_899 . V_902 , V_2 -> V_5 . V_899 . V_504 ,
V_898 ) ;
if ( V_124 )
break;
V_898 += V_2 -> V_5 . V_899 . V_504 ;
}
return V_124 ;
}
static int F_410 ( struct V_1 * V_2 , int V_504 ,
unsigned short V_902 , void * V_199 ,
unsigned int V_767 , bool V_900 )
{
V_2 -> V_5 . V_899 . V_902 = V_902 ;
V_2 -> V_5 . V_899 . V_900 = V_900 ;
V_2 -> V_5 . V_899 . V_767 = V_767 ;
V_2 -> V_5 . V_899 . V_504 = V_504 ;
if ( ! F_409 ( V_2 , V_2 -> V_5 . V_903 ) ) {
V_2 -> V_5 . V_899 . V_767 = 0 ;
return 1 ;
}
V_2 -> V_866 -> V_884 = V_904 ;
V_2 -> V_866 -> V_905 . V_906 = V_900 ? V_907 : V_908 ;
V_2 -> V_866 -> V_905 . V_504 = V_504 ;
V_2 -> V_866 -> V_905 . V_909 = V_910 * V_110 ;
V_2 -> V_866 -> V_905 . V_767 = V_767 ;
V_2 -> V_866 -> V_905 . V_902 = V_902 ;
return 0 ;
}
static int F_411 ( struct V_854 * V_855 ,
int V_504 , unsigned short V_902 , void * V_199 ,
unsigned int V_767 )
{
struct V_1 * V_2 = F_373 ( V_855 ) ;
int V_111 ;
if ( V_2 -> V_5 . V_899 . V_767 )
goto V_911;
memset ( V_2 -> V_5 . V_903 , 0 , V_504 * V_767 ) ;
V_111 = F_410 ( V_2 , V_504 , V_902 , V_199 , V_767 , true ) ;
if ( V_111 ) {
V_911:
memcpy ( V_199 , V_2 -> V_5 . V_903 , V_504 * V_767 ) ;
F_412 ( V_912 , V_902 , V_504 , V_767 , V_2 -> V_5 . V_903 ) ;
V_2 -> V_5 . V_899 . V_767 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_413 ( struct V_854 * V_855 ,
int V_504 , unsigned short V_902 ,
const void * V_199 , unsigned int V_767 )
{
struct V_1 * V_2 = F_373 ( V_855 ) ;
memcpy ( V_2 -> V_5 . V_903 , V_199 , V_504 * V_767 ) ;
F_412 ( V_913 , V_902 , V_504 , V_767 , V_2 -> V_5 . V_903 ) ;
return F_410 ( V_2 , V_504 , V_902 , ( void * ) V_199 , V_767 , false ) ;
}
static unsigned long F_414 ( struct V_1 * V_2 , int V_842 )
{
return V_90 -> F_414 ( V_2 , V_842 ) ;
}
static void F_415 ( struct V_854 * V_855 , V_179 V_81 )
{
F_416 ( F_373 ( V_855 ) , V_81 ) ;
}
static int F_417 ( struct V_1 * V_2 )
{
if ( ! F_255 ( V_2 ) )
return V_850 ;
if ( V_90 -> V_593 () ) {
int V_24 = F_187 () ;
F_257 ( V_24 , V_2 -> V_5 . V_594 ) ;
F_418 ( V_2 -> V_5 . V_594 ,
F_253 , NULL , 1 ) ;
F_190 () ;
F_419 ( V_2 -> V_5 . V_594 ) ;
} else
F_254 () ;
return V_850 ;
}
int F_420 ( struct V_1 * V_2 )
{
F_417 ( V_2 ) ;
return F_38 ( V_2 ) ;
}
static void F_421 ( struct V_854 * V_855 )
{
F_417 ( F_373 ( V_855 ) ) ;
}
static int F_422 ( struct V_854 * V_855 , int V_92 ,
unsigned long * V_664 )
{
return F_103 ( F_373 ( V_855 ) , V_92 , V_664 ) ;
}
static int F_423 ( struct V_854 * V_855 , int V_92 ,
unsigned long V_23 )
{
return F_101 ( F_373 ( V_855 ) , V_92 , V_23 ) ;
}
static T_2 F_424 ( T_2 V_914 , T_1 V_915 )
{
return ( V_914 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_915 ;
}
static unsigned long F_425 ( struct V_854 * V_855 , int V_916 )
{
struct V_1 * V_2 = F_373 ( V_855 ) ;
unsigned long V_23 ;
switch ( V_916 ) {
case 0 :
V_23 = F_64 ( V_2 ) ;
break;
case 2 :
V_23 = V_2 -> V_5 . V_82 ;
break;
case 3 :
V_23 = F_62 ( V_2 ) ;
break;
case 4 :
V_23 = F_81 ( V_2 ) ;
break;
case 8 :
V_23 = F_94 ( V_2 ) ;
break;
default:
F_426 ( L_21 , V_267 , V_916 ) ;
return 0 ;
}
return V_23 ;
}
static int F_427 ( struct V_854 * V_855 , int V_916 , V_179 V_199 )
{
struct V_1 * V_2 = F_373 ( V_855 ) ;
int V_917 = 0 ;
switch ( V_916 ) {
case 0 :
V_917 = F_63 ( V_2 , F_424 ( F_64 ( V_2 ) , V_199 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_82 = V_199 ;
break;
case 3 :
V_917 = F_88 ( V_2 , V_199 ) ;
break;
case 4 :
V_917 = F_80 ( V_2 , F_424 ( F_81 ( V_2 ) , V_199 ) ) ;
break;
case 8 :
V_917 = F_91 ( V_2 , V_199 ) ;
break;
default:
F_426 ( L_21 , V_267 , V_916 ) ;
V_917 = - 1 ;
}
return V_917 ;
}
static int F_428 ( struct V_854 * V_855 )
{
return V_90 -> V_91 ( F_373 ( V_855 ) ) ;
}
static void F_429 ( struct V_854 * V_855 , struct V_918 * V_919 )
{
V_90 -> V_920 ( F_373 ( V_855 ) , V_919 ) ;
}
static void F_430 ( struct V_854 * V_855 , struct V_918 * V_919 )
{
V_90 -> V_921 ( F_373 ( V_855 ) , V_919 ) ;
}
static void F_431 ( struct V_854 * V_855 , struct V_918 * V_919 )
{
V_90 -> V_922 ( F_373 ( V_855 ) , V_919 ) ;
}
static void F_432 ( struct V_854 * V_855 , struct V_918 * V_919 )
{
V_90 -> V_923 ( F_373 ( V_855 ) , V_919 ) ;
}
static unsigned long F_433 (
struct V_854 * V_855 , int V_842 )
{
return F_414 ( F_373 ( V_855 ) , V_842 ) ;
}
static bool F_434 ( struct V_854 * V_855 , V_895 * V_924 ,
struct V_925 * V_926 , T_1 * V_927 ,
int V_842 )
{
struct V_840 V_841 ;
F_365 ( F_373 ( V_855 ) , & V_841 , V_842 ) ;
* V_924 = V_841 . V_924 ;
if ( V_841 . V_928 ) {
memset ( V_926 , 0 , sizeof( * V_926 ) ) ;
if ( V_927 )
* V_927 = 0 ;
return false ;
}
if ( V_841 . V_929 )
V_841 . V_930 >>= 12 ;
F_435 ( V_926 , V_841 . V_930 ) ;
F_436 ( V_926 , ( unsigned long ) V_841 . V_233 ) ;
#ifdef F_65
if ( V_927 )
* V_927 = V_841 . V_233 >> 32 ;
#endif
V_926 -> type = V_841 . type ;
V_926 -> V_602 = V_841 . V_602 ;
V_926 -> V_931 = V_841 . V_931 ;
V_926 -> V_932 = V_841 . V_933 ;
V_926 -> V_934 = V_841 . V_934 ;
V_926 -> V_935 = V_841 . V_935 ;
V_926 -> V_936 = V_841 . V_186 ;
V_926 -> V_929 = V_841 . V_929 ;
return true ;
}
static void F_437 ( struct V_854 * V_855 , V_895 V_924 ,
struct V_925 * V_926 , T_1 V_927 ,
int V_842 )
{
struct V_1 * V_2 = F_373 ( V_855 ) ;
struct V_840 V_841 ;
V_841 . V_924 = V_924 ;
V_841 . V_233 = F_438 ( V_926 ) ;
#ifdef F_65
V_841 . V_233 |= ( ( T_2 ) V_927 ) << 32 ;
#endif
V_841 . V_930 = F_439 ( V_926 ) ;
if ( V_926 -> V_929 )
V_841 . V_930 = ( V_841 . V_930 << 12 ) | 0xfff ;
V_841 . type = V_926 -> type ;
V_841 . V_931 = V_926 -> V_931 ;
V_841 . V_186 = V_926 -> V_936 ;
V_841 . V_602 = V_926 -> V_602 ;
V_841 . V_935 = V_926 -> V_935 ;
V_841 . V_929 = V_926 -> V_929 ;
V_841 . V_934 = V_926 -> V_934 ;
V_841 . V_933 = V_926 -> V_932 ;
V_841 . V_928 = ! V_841 . V_933 ;
V_841 . V_937 = 0 ;
F_364 ( V_2 , & V_841 , V_842 ) ;
return;
}
static int F_440 ( struct V_854 * V_855 ,
T_1 V_938 , T_2 * V_476 )
{
struct V_33 V_22 ;
int V_124 ;
V_22 . V_150 = V_938 ;
V_22 . V_41 = false ;
V_124 = F_117 ( F_373 ( V_855 ) , & V_22 ) ;
if ( V_124 )
return V_124 ;
* V_476 = V_22 . V_39 ;
return 0 ;
}
static int F_441 ( struct V_854 * V_855 ,
T_1 V_938 , T_2 V_39 )
{
struct V_33 V_22 ;
V_22 . V_39 = V_39 ;
V_22 . V_150 = V_938 ;
V_22 . V_41 = false ;
return F_113 ( F_373 ( V_855 ) , & V_22 ) ;
}
static T_2 F_442 ( struct V_854 * V_855 )
{
struct V_1 * V_2 = F_373 ( V_855 ) ;
return V_2 -> V_5 . V_432 ;
}
static void F_443 ( struct V_854 * V_855 , T_2 V_432 )
{
struct V_1 * V_2 = F_373 ( V_855 ) ;
V_2 -> V_5 . V_432 = V_432 ;
}
static int F_444 ( struct V_854 * V_855 ,
T_1 V_939 )
{
return F_445 ( F_373 ( V_855 ) , V_939 ) ;
}
static int F_446 ( struct V_854 * V_855 ,
T_1 V_939 , T_2 * V_476 )
{
return F_106 ( F_373 ( V_855 ) , V_939 , V_476 ) ;
}
static void F_447 ( struct V_854 * V_855 )
{
F_373 ( V_855 ) -> V_5 . V_940 = 1 ;
}
static void F_448 ( struct V_854 * V_855 )
{
F_449 () ;
F_450 ( F_373 ( V_855 ) ) ;
}
static void F_451 ( struct V_854 * V_855 )
{
F_452 () ;
}
static int F_453 ( struct V_854 * V_855 ,
struct V_941 * V_942 ,
enum V_943 V_944 )
{
return V_90 -> V_945 ( F_373 ( V_855 ) , V_942 , V_944 ) ;
}
static void F_454 ( struct V_854 * V_855 ,
T_1 * V_946 , T_1 * V_947 , T_1 * V_204 , T_1 * V_212 )
{
V_709 ( F_373 ( V_855 ) , V_946 , V_947 , V_204 , V_212 ) ;
}
static V_179 F_455 ( struct V_854 * V_855 , unsigned V_948 )
{
return F_105 ( F_373 ( V_855 ) , V_948 ) ;
}
static void F_456 ( struct V_854 * V_855 , unsigned V_948 , V_179 V_199 )
{
F_107 ( F_373 ( V_855 ) , V_948 , V_199 ) ;
}
static void F_457 ( struct V_854 * V_855 , bool V_639 )
{
V_90 -> V_657 ( F_373 ( V_855 ) , V_639 ) ;
}
static unsigned F_458 ( struct V_854 * V_855 )
{
return F_373 ( V_855 ) -> V_5 . V_646 ;
}
static void F_459 ( struct V_854 * V_855 , unsigned V_949 )
{
F_294 ( F_373 ( V_855 ) , V_949 ) ;
}
static void F_460 ( struct V_1 * V_2 , T_1 V_29 )
{
T_1 V_950 = V_90 -> V_635 ( V_2 ) ;
if ( V_950 & V_29 )
V_29 = 0 ;
if ( F_172 ( V_950 || V_29 ) ) {
V_90 -> V_656 ( V_2 , V_29 ) ;
if ( ! V_29 )
F_32 ( V_68 , V_2 ) ;
}
}
static bool F_461 ( struct V_1 * V_2 )
{
struct V_854 * V_855 = & V_2 -> V_5 . V_870 ;
if ( V_855 -> V_69 . V_42 == V_43 )
return F_42 ( V_2 , & V_855 -> V_69 ) ;
if ( V_855 -> V_69 . V_951 )
F_41 ( V_2 , V_855 -> V_69 . V_42 ,
V_855 -> V_69 . V_63 ) ;
else
F_34 ( V_2 , V_855 -> V_69 . V_42 ) ;
return false ;
}
static void F_462 ( struct V_1 * V_2 )
{
struct V_854 * V_855 = & V_2 -> V_5 . V_870 ;
int V_137 , V_138 ;
V_90 -> V_139 ( V_2 , & V_137 , & V_138 ) ;
V_855 -> V_952 = F_463 ( V_2 ) ;
V_855 -> V_953 = ( V_855 -> V_952 & V_954 ) != 0 ;
V_855 -> V_955 = F_464 ( V_2 ) ;
V_855 -> V_334 = ( ! F_33 ( V_2 ) ) ? V_956 :
( V_855 -> V_952 & V_957 ) ? V_958 :
( V_138 && F_59 ( V_2 ) ) ? V_879 :
V_137 ? V_959 :
V_960 ;
F_193 ( V_961 != V_962 ) ;
F_193 ( V_659 != V_963 ) ;
F_193 ( V_647 != V_964 ) ;
F_465 ( V_855 ) ;
V_2 -> V_5 . V_965 = false ;
}
int F_466 ( struct V_1 * V_2 , int V_606 , int V_966 )
{
struct V_854 * V_855 = & V_2 -> V_5 . V_870 ;
int V_111 ;
F_462 ( V_2 ) ;
V_855 -> V_967 = 2 ;
V_855 -> V_968 = 2 ;
V_855 -> V_969 = V_855 -> V_955 + V_966 ;
V_111 = F_467 ( V_855 , V_606 ) ;
if ( V_111 != V_850 )
return V_970 ;
V_855 -> V_955 = V_855 -> V_969 ;
F_468 ( V_2 , V_855 -> V_955 ) ;
F_469 ( V_2 , V_855 -> V_952 ) ;
if ( V_606 == V_52 )
V_2 -> V_5 . V_638 = 0 ;
else
V_2 -> V_5 . V_632 . V_70 = false ;
return V_971 ;
}
static int F_470 ( struct V_1 * V_2 )
{
int V_124 = V_971 ;
++ V_2 -> V_76 . V_972 ;
F_471 ( V_2 ) ;
if ( ! F_40 ( V_2 ) && V_90 -> V_91 ( V_2 ) == 0 ) {
V_2 -> V_866 -> V_884 = V_973 ;
V_2 -> V_866 -> V_974 . V_975 = V_976 ;
V_2 -> V_866 -> V_974 . V_977 = 0 ;
V_124 = V_970 ;
}
F_34 ( V_2 , V_94 ) ;
return V_124 ;
}
static bool F_472 ( struct V_1 * V_2 , T_15 V_82 ,
bool V_978 ,
int V_979 )
{
T_6 V_393 = V_82 ;
T_16 V_980 ;
if ( V_979 & V_981 )
return false ;
if ( ! V_2 -> V_5 . V_86 . V_982 ) {
V_393 = F_369 ( V_2 , V_82 , NULL ) ;
if ( V_393 == V_103 )
return true ;
}
V_980 = F_473 ( V_2 -> V_142 , F_52 ( V_393 ) ) ;
if ( F_474 ( V_980 ) )
return false ;
F_475 ( V_980 ) ;
if ( V_2 -> V_5 . V_86 . V_982 ) {
unsigned int V_983 ;
F_162 ( & V_2 -> V_142 -> V_984 ) ;
V_983 = V_2 -> V_142 -> V_5 . V_983 ;
F_163 ( & V_2 -> V_142 -> V_984 ) ;
if ( V_983 )
F_476 ( V_2 -> V_142 , F_52 ( V_393 ) ) ;
return true ;
}
F_476 ( V_2 -> V_142 , F_52 ( V_393 ) ) ;
return ! V_978 ;
}
static bool F_477 ( struct V_854 * V_855 ,
unsigned long V_82 , int V_979 )
{
struct V_1 * V_2 = F_373 ( V_855 ) ;
unsigned long V_985 , V_986 , V_393 = V_82 ;
V_985 = V_2 -> V_5 . V_985 ;
V_986 = V_2 -> V_5 . V_986 ;
V_2 -> V_5 . V_985 = V_2 -> V_5 . V_986 = 0 ;
if ( ! ( V_979 & V_987 ) )
return false ;
if ( F_478 ( V_855 ) )
return false ;
if ( V_855 -> V_955 == V_985 && V_986 == V_82 )
return false ;
V_2 -> V_5 . V_985 = V_855 -> V_955 ;
V_2 -> V_5 . V_986 = V_82 ;
if ( ! V_2 -> V_5 . V_86 . V_982 )
V_393 = F_369 ( V_2 , V_82 , NULL ) ;
F_476 ( V_2 -> V_142 , F_52 ( V_393 ) ) ;
return true ;
}
static void F_479 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_646 & V_659 ) ) {
F_480 ( V_2 -> V_303 , V_2 -> V_5 . V_432 , false ) ;
F_32 ( V_68 , V_2 ) ;
}
F_68 ( V_2 ) ;
}
static void F_294 ( struct V_1 * V_2 , unsigned V_949 )
{
unsigned V_123 = V_2 -> V_5 . V_646 ^ V_949 ;
V_2 -> V_5 . V_646 = V_949 ;
if ( V_123 & V_659 )
F_479 ( V_2 ) ;
}
static int F_481 ( unsigned long V_626 , T_1 type , T_1 V_191 ,
unsigned long * V_186 )
{
T_1 V_190 = 0 ;
int V_3 ;
T_1 V_988 , V_989 ;
V_988 = V_191 ;
V_989 = V_191 >> 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ , V_988 >>= 2 , V_989 >>= 4 )
if ( ( V_988 & 3 ) && ( V_989 & 15 ) == type && V_186 [ V_3 ] == V_626 )
V_190 |= ( 1 << V_3 ) ;
return V_190 ;
}
static void F_482 ( struct V_1 * V_2 , int * V_124 )
{
struct V_990 * V_990 = V_2 -> V_866 ;
if ( V_2 -> V_182 & V_991 ) {
V_990 -> V_992 . V_5 . V_190 = V_993 | V_197 | V_198 ;
V_990 -> V_992 . V_5 . V_994 = V_2 -> V_5 . V_995 ;
V_990 -> V_992 . V_5 . V_69 = V_54 ;
V_990 -> V_884 = V_996 ;
* V_124 = V_997 ;
} else {
V_2 -> V_5 . V_190 &= ~ 15 ;
V_2 -> V_5 . V_190 |= V_993 | V_198 ;
F_34 ( V_2 , V_54 ) ;
}
}
int F_38 ( struct V_1 * V_2 )
{
unsigned long V_998 = V_90 -> V_999 ( V_2 ) ;
int V_124 = V_971 ;
V_90 -> V_1000 ( V_2 ) ;
if ( F_172 ( V_998 & V_954 ) )
F_482 ( V_2 , & V_124 ) ;
return V_124 == V_971 ;
}
static bool F_483 ( struct V_1 * V_2 , int * V_124 )
{
if ( F_172 ( V_2 -> V_182 & V_183 ) &&
( V_2 -> V_5 . V_192 & V_195 ) ) {
struct V_990 * V_990 = V_2 -> V_866 ;
unsigned long V_955 = F_484 ( V_2 ) ;
T_1 V_190 = F_481 ( V_955 , 0 ,
V_2 -> V_5 . V_192 ,
V_2 -> V_5 . V_185 ) ;
if ( V_190 != 0 ) {
V_990 -> V_992 . V_5 . V_190 = V_190 | V_197 | V_198 ;
V_990 -> V_992 . V_5 . V_994 = V_955 ;
V_990 -> V_992 . V_5 . V_69 = V_54 ;
V_990 -> V_884 = V_996 ;
* V_124 = V_997 ;
return true ;
}
}
if ( F_172 ( V_2 -> V_5 . V_191 & V_195 ) &&
! ( F_463 ( V_2 ) & V_1001 ) ) {
unsigned long V_955 = F_484 ( V_2 ) ;
T_1 V_190 = F_481 ( V_955 , 0 ,
V_2 -> V_5 . V_191 ,
V_2 -> V_5 . V_186 ) ;
if ( V_190 != 0 ) {
V_2 -> V_5 . V_190 &= ~ 15 ;
V_2 -> V_5 . V_190 |= V_190 | V_198 ;
F_34 ( V_2 , V_54 ) ;
* V_124 = V_971 ;
return true ;
}
}
return false ;
}
int F_485 ( struct V_1 * V_2 ,
unsigned long V_82 ,
int V_979 ,
void * V_1002 ,
int V_1003 )
{
int V_124 ;
struct V_854 * V_855 = & V_2 -> V_5 . V_870 ;
bool V_502 = true ;
bool V_1004 = V_2 -> V_5 . V_978 ;
V_2 -> V_5 . V_978 = false ;
F_486 ( V_2 ) ;
if ( ! ( V_979 & V_1005 ) ) {
F_462 ( V_2 ) ;
if ( F_483 ( V_2 , & V_124 ) )
return V_124 ;
V_855 -> V_1006 = 0 ;
V_855 -> V_1007 = false ;
V_855 -> V_69 . V_42 = - 1 ;
V_855 -> V_1008 = false ;
V_855 -> V_1009 = V_979 & V_1010 ;
V_124 = F_487 ( V_855 , V_1002 , V_1003 ) ;
F_488 ( V_2 ) ;
++ V_2 -> V_76 . V_1011 ;
if ( V_124 != V_1012 ) {
if ( V_979 & V_1010 )
return V_970 ;
if ( F_472 ( V_2 , V_82 , V_1004 ,
V_979 ) )
return V_971 ;
if ( V_979 & V_1013 )
return V_970 ;
return F_470 ( V_2 ) ;
}
}
if ( V_979 & V_1013 ) {
F_468 ( V_2 , V_855 -> V_969 ) ;
if ( V_855 -> V_952 & V_1001 )
F_469 ( V_2 , V_855 -> V_952 & ~ V_1001 ) ;
return V_971 ;
}
if ( F_477 ( V_855 , V_82 , V_979 ) )
return V_971 ;
if ( V_2 -> V_5 . V_965 ) {
V_2 -> V_5 . V_965 = false ;
F_489 ( V_855 ) ;
}
V_1014:
V_855 -> V_69 . V_81 = V_82 ;
V_124 = F_490 ( V_855 ) ;
if ( V_124 == V_1015 )
return V_971 ;
if ( V_124 == V_1016 ) {
if ( F_472 ( V_2 , V_82 , V_1004 ,
V_979 ) )
return V_971 ;
return F_470 ( V_2 ) ;
}
if ( V_855 -> V_1007 ) {
V_124 = V_971 ;
if ( F_461 ( V_2 ) )
return V_124 ;
} else if ( V_2 -> V_5 . V_899 . V_767 ) {
if ( ! V_2 -> V_5 . V_899 . V_900 ) {
V_2 -> V_5 . V_899 . V_767 = 0 ;
} else {
V_502 = false ;
V_2 -> V_5 . V_1017 = V_1018 ;
}
V_124 = V_997 ;
} else if ( V_2 -> V_880 ) {
if ( ! V_2 -> V_883 )
V_502 = false ;
V_124 = V_997 ;
V_2 -> V_5 . V_1017 = V_1019 ;
} else if ( V_124 == V_1020 )
goto V_1014;
else
V_124 = V_971 ;
if ( V_502 ) {
unsigned long V_998 = V_90 -> V_999 ( V_2 ) ;
F_460 ( V_2 , V_855 -> V_1006 ) ;
V_2 -> V_5 . V_1021 = false ;
F_468 ( V_2 , V_855 -> V_955 ) ;
if ( V_124 == V_971 &&
( V_855 -> V_953 || ( V_2 -> V_182 & V_991 ) ) )
F_482 ( V_2 , & V_124 ) ;
if ( ! V_855 -> V_1007 ||
F_29 ( V_855 -> V_69 . V_42 ) == V_57 )
F_491 ( V_2 , V_855 -> V_952 ) ;
if ( F_172 ( ( V_855 -> V_952 & ~ V_998 ) & V_1022 ) )
F_32 ( V_68 , V_2 ) ;
} else
V_2 -> V_5 . V_1021 = true ;
return V_124 ;
}
int F_492 ( struct V_1 * V_2 , int V_504 , unsigned short V_902 )
{
unsigned long V_199 = F_105 ( V_2 , V_206 ) ;
int V_111 = F_413 ( & V_2 -> V_5 . V_870 ,
V_504 , V_902 , & V_199 , 1 ) ;
V_2 -> V_5 . V_899 . V_767 = 0 ;
return V_111 ;
}
static int F_493 ( struct V_1 * V_2 )
{
unsigned long V_199 ;
F_15 ( V_2 -> V_5 . V_899 . V_767 != 1 ) ;
V_199 = ( V_2 -> V_5 . V_899 . V_504 < 4 ) ? F_105 ( V_2 , V_206 )
: 0 ;
F_411 ( & V_2 -> V_5 . V_870 , V_2 -> V_5 . V_899 . V_504 ,
V_2 -> V_5 . V_899 . V_902 , & V_199 , 1 ) ;
F_107 ( V_2 , V_206 , V_199 ) ;
return 1 ;
}
int F_494 ( struct V_1 * V_2 , int V_504 , unsigned short V_902 )
{
unsigned long V_199 ;
int V_111 ;
V_199 = ( V_504 < 4 ) ? F_105 ( V_2 , V_206 ) : 0 ;
V_111 = F_411 ( & V_2 -> V_5 . V_870 , V_504 , V_902 ,
& V_199 , 1 ) ;
if ( V_111 ) {
F_107 ( V_2 , V_206 , V_199 ) ;
return V_111 ;
}
V_2 -> V_5 . V_1017 = F_493 ;
return 0 ;
}
static int F_495 ( unsigned int V_24 )
{
F_496 ( V_348 , 0 ) ;
return 0 ;
}
static void F_497 ( void * V_39 )
{
struct V_1023 * V_1024 = V_39 ;
unsigned long V_268 = 0 ;
if ( V_39 )
V_268 = V_1024 -> V_891 ;
else if ( ! F_250 ( V_1025 ) )
V_268 = F_498 ( F_499 () ) ;
if ( ! V_268 )
V_268 = V_277 ;
F_496 ( V_348 , V_268 ) ;
}
static int F_500 ( struct V_1026 * V_1027 , unsigned long V_199 ,
void * V_39 )
{
struct V_1023 * V_1024 = V_39 ;
struct V_142 * V_142 ;
struct V_1 * V_2 ;
int V_3 , V_1028 = 0 ;
if ( V_199 == V_1029 && V_1024 -> V_890 > V_1024 -> V_891 )
return 0 ;
if ( V_199 == V_1030 && V_1024 -> V_890 < V_1024 -> V_891 )
return 0 ;
F_258 ( V_1024 -> V_24 , F_497 , V_1024 , 1 ) ;
F_162 ( & V_1031 ) ;
F_501 (kvm, &vm_list, vm_list) {
F_184 (i, vcpu, kvm) {
if ( V_2 -> V_24 != V_1024 -> V_24 )
continue;
F_32 ( V_343 , V_2 ) ;
if ( V_2 -> V_24 != F_10 () )
V_1028 = 1 ;
}
}
F_163 ( & V_1031 ) ;
if ( V_1024 -> V_890 < V_1024 -> V_891 && V_1028 ) {
F_258 ( V_1024 -> V_24 , F_497 , V_1024 , 1 ) ;
}
return 0 ;
}
static int F_502 ( unsigned int V_24 )
{
F_497 ( NULL ) ;
return 0 ;
}
static void F_503 ( void )
{
V_1032 = V_277 ;
if ( ! F_250 ( V_1025 ) ) {
#ifdef F_504
struct V_1033 V_1034 ;
int V_24 ;
memset ( & V_1034 , 0 , sizeof( V_1034 ) ) ;
V_24 = F_187 () ;
F_505 ( & V_1034 , V_24 ) ;
if ( V_1034 . V_1035 . V_1036 )
V_1032 = V_1034 . V_1035 . V_1036 ;
F_190 () ;
#endif
F_506 ( & V_1037 ,
V_1038 ) ;
}
F_134 ( L_22 , V_1032 ) ;
F_507 ( V_1039 , L_23 ,
F_502 , F_495 ) ;
}
int F_508 ( void )
{
return F_188 ( V_1040 ) != NULL ;
}
static int F_509 ( void )
{
int V_1041 = 3 ;
if ( F_188 ( V_1040 ) )
V_1041 = V_90 -> V_91 ( F_188 ( V_1040 ) ) ;
return V_1041 != 0 ;
}
static unsigned long F_510 ( void )
{
unsigned long V_1042 = 0 ;
if ( F_188 ( V_1040 ) )
V_1042 = F_464 ( F_188 ( V_1040 ) ) ;
return V_1042 ;
}
void F_511 ( struct V_1 * V_2 )
{
F_496 ( V_1040 , V_2 ) ;
}
void F_512 ( struct V_1 * V_2 )
{
F_496 ( V_1040 , NULL ) ;
}
static void F_513 ( void )
{
T_2 V_29 ;
int V_1043 = V_1044 . V_1045 ;
V_29 = F_514 ( V_1043 , 51 ) ;
V_29 |= 1ull ;
#ifdef F_65
if ( V_1043 == 52 )
V_29 &= ~ 1ull ;
#endif
F_515 ( V_29 , V_29 ) ;
}
static void F_516 ( struct V_361 * V_362 )
{
struct V_142 * V_142 ;
struct V_1 * V_2 ;
int V_3 ;
F_162 ( & V_1031 ) ;
F_501 (kvm, &vm_list, vm_list)
F_184 (i, vcpu, kvm)
F_32 ( V_302 , V_2 ) ;
F_179 ( & V_341 , 0 ) ;
F_163 ( & V_1031 ) ;
}
static int F_517 ( struct V_1026 * V_1027 , unsigned long V_1046 ,
void * V_1047 )
{
struct V_229 * V_297 = & V_229 ;
struct V_227 * V_228 = V_1047 ;
F_119 ( V_228 ) ;
if ( V_297 -> clock . V_236 != V_301 &&
F_145 ( & V_341 ) != 0 )
F_518 ( V_1048 , & V_1049 ) ;
return 0 ;
}
int F_519 ( void * V_1050 )
{
int V_124 ;
struct V_90 * V_869 = V_1050 ;
if ( V_90 ) {
F_12 ( V_27 L_24 ) ;
V_124 = - V_610 ;
goto V_116;
}
if ( ! V_869 -> V_1051 () ) {
F_12 ( V_27 L_25 ) ;
V_124 = - V_1052 ;
goto V_116;
}
if ( V_869 -> V_1053 () ) {
F_12 ( V_27 L_26 ) ;
V_124 = - V_1052 ;
goto V_116;
}
V_124 = - V_391 ;
V_26 = F_520 ( struct V_11 ) ;
if ( ! V_26 ) {
F_12 ( V_27 L_27 ) ;
goto V_116;
}
V_124 = F_521 () ;
if ( V_124 )
goto V_1054;
F_513 () ;
V_90 = V_869 ;
F_522 ( V_1055 , V_1056 ,
V_1057 , V_1058 , 0 ,
V_117 , 0 ) ;
F_503 () ;
F_523 ( & V_1059 ) ;
if ( F_250 ( V_566 ) )
V_149 = F_524 ( V_147 ) ;
F_525 () ;
#ifdef F_65
F_526 ( & V_1060 ) ;
#endif
return 0 ;
V_1054:
F_527 ( V_26 ) ;
V_116:
return V_124 ;
}
void F_528 ( void )
{
F_529 () ;
F_530 ( & V_1059 ) ;
if ( ! F_250 ( V_1025 ) )
F_531 ( & V_1037 ,
V_1038 ) ;
F_532 ( V_1039 ) ;
#ifdef F_65
F_533 ( & V_1060 ) ;
#endif
V_90 = NULL ;
F_534 () ;
F_527 ( V_26 ) ;
}
int F_535 ( struct V_1 * V_2 )
{
++ V_2 -> V_76 . V_1061 ;
if ( F_92 ( V_2 ) ) {
V_2 -> V_5 . V_654 = V_1062 ;
return 1 ;
} else {
V_2 -> V_866 -> V_884 = V_1063 ;
return 0 ;
}
}
int F_536 ( struct V_1 * V_2 )
{
int V_111 = F_38 ( V_2 ) ;
return F_535 ( V_2 ) && V_111 ;
}
static int F_537 ( struct V_1 * V_2 , T_6 V_1064 ,
unsigned long V_1065 )
{
struct V_1066 V_1067 ;
struct V_335 V_253 ;
T_2 V_1068 ;
int V_111 ;
if ( V_1065 != V_1069 )
return - V_1070 ;
if ( F_177 ( & V_253 , & V_1068 ) == false )
return - V_1070 ;
V_1067 . V_254 = V_253 . V_255 ;
V_1067 . V_256 = V_253 . V_257 ;
V_1067 . V_291 = F_153 ( V_2 , V_1068 ) ;
V_1067 . V_15 = 0 ;
V_111 = 0 ;
if ( F_127 ( V_2 -> V_142 , V_1064 , & V_1067 ,
sizeof( struct V_1066 ) ) )
V_111 = - V_1071 ;
return V_111 ;
}
static void F_538 ( struct V_142 * V_142 , unsigned long V_15 , int V_1072 )
{
struct V_1073 V_1074 ;
V_1074 . V_1075 = 0 ;
V_1074 . V_1076 = 0 ;
V_1074 . V_783 = 0 ;
V_1074 . V_1077 = V_1072 ;
V_1074 . V_1078 = false ;
V_1074 . V_1079 = V_1080 ;
F_539 ( V_142 , NULL , & V_1074 , NULL ) ;
}
void F_540 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_604 = false ;
V_90 -> V_1081 ( V_2 ) ;
}
int F_541 ( struct V_1 * V_2 )
{
unsigned long V_18 , V_1082 , V_1083 , V_1084 , V_1085 , V_111 ;
int V_1086 , V_124 ;
V_124 = F_38 ( V_2 ) ;
if ( F_542 ( V_2 -> V_142 ) )
return F_543 ( V_2 ) ;
V_18 = F_105 ( V_2 , V_206 ) ;
V_1082 = F_105 ( V_2 , V_1087 ) ;
V_1083 = F_105 ( V_2 , V_205 ) ;
V_1084 = F_105 ( V_2 , V_207 ) ;
V_1085 = F_105 ( V_2 , V_1088 ) ;
F_544 ( V_18 , V_1082 , V_1083 , V_1084 , V_1085 ) ;
V_1086 = F_545 ( V_2 ) ;
if ( ! V_1086 ) {
V_18 &= 0xFFFFFFFF ;
V_1082 &= 0xFFFFFFFF ;
V_1083 &= 0xFFFFFFFF ;
V_1084 &= 0xFFFFFFFF ;
V_1085 &= 0xFFFFFFFF ;
}
if ( V_90 -> V_91 ( V_2 ) != 0 ) {
V_111 = - V_1089 ;
goto V_116;
}
switch ( V_18 ) {
case V_1090 :
V_111 = 0 ;
break;
case V_1091 :
F_538 ( V_2 -> V_142 , V_1082 , V_1083 ) ;
V_111 = 0 ;
break;
#ifdef F_65
case V_1092 :
V_111 = F_537 ( V_2 , V_1082 , V_1083 ) ;
break;
#endif
default:
V_111 = - V_1093 ;
break;
}
V_116:
if ( ! V_1086 )
V_111 = ( T_1 ) V_111 ;
F_107 ( V_2 , V_206 , V_111 ) ;
++ V_2 -> V_76 . V_1094 ;
return V_124 ;
}
static int F_546 ( struct V_854 * V_855 )
{
struct V_1 * V_2 = F_373 ( V_855 ) ;
char V_1095 [ 3 ] ;
unsigned long V_1096 = F_464 ( V_2 ) ;
V_90 -> V_1097 ( V_2 , V_1095 ) ;
return F_397 ( V_855 , V_1096 , V_1095 , 3 ,
& V_855 -> V_69 ) ;
}
static int F_547 ( struct V_1 * V_2 )
{
return V_2 -> V_866 -> V_1098 &&
F_168 ( ! F_282 ( V_2 -> V_142 ) ) ;
}
static void F_548 ( struct V_1 * V_2 )
{
struct V_990 * V_990 = V_2 -> V_866 ;
V_990 -> V_1099 = ( F_463 ( V_2 ) & V_1022 ) != 0 ;
V_990 -> V_15 = F_291 ( V_2 ) ? V_1100 : 0 ;
V_990 -> V_180 = F_94 ( V_2 ) ;
V_990 -> V_32 = F_21 ( V_2 ) ;
V_990 -> V_1101 =
F_282 ( V_2 -> V_142 ) ||
F_275 ( V_2 ) ;
}
static void F_272 ( struct V_1 * V_2 )
{
int V_1102 , V_1103 ;
if ( ! V_90 -> F_272 )
return;
if ( ! F_92 ( V_2 ) )
return;
if ( V_2 -> V_5 . V_604 )
return;
if ( ! V_2 -> V_5 . V_658 -> V_718 )
V_1102 = F_549 ( V_2 ) ;
else
V_1102 = - 1 ;
if ( V_1102 != - 1 )
V_1102 >>= 4 ;
V_1103 = F_95 ( V_2 ) ;
V_90 -> F_272 ( V_2 , V_1103 , V_1102 ) ;
}
static int F_550 ( struct V_1 * V_2 , bool V_1104 )
{
int V_124 ;
if ( V_2 -> V_5 . V_69 . V_70 ) {
F_551 ( V_2 -> V_5 . V_69 . V_18 ,
V_2 -> V_5 . V_69 . V_72 ,
V_2 -> V_5 . V_69 . V_63 ) ;
if ( F_29 ( V_2 -> V_5 . V_69 . V_18 ) == V_61 )
F_491 ( V_2 , F_463 ( V_2 ) |
V_1001 ) ;
if ( V_2 -> V_5 . V_69 . V_18 == V_54 &&
( V_2 -> V_5 . V_191 & V_1105 ) ) {
V_2 -> V_5 . V_191 &= ~ V_1105 ;
F_98 ( V_2 ) ;
}
V_90 -> V_1106 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_637 ) {
V_90 -> V_1107 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_632 . V_70 ) {
V_90 -> V_1108 ( V_2 ) ;
return 0 ;
}
if ( F_40 ( V_2 ) && V_90 -> V_1109 ) {
V_124 = V_90 -> V_1109 ( V_2 , V_1104 ) ;
if ( V_124 != 0 )
return V_124 ;
}
if ( V_2 -> V_5 . V_644 && ! F_291 ( V_2 ) ) {
V_2 -> V_5 . V_644 = false ;
F_552 ( V_2 ) ;
} else if ( V_2 -> V_5 . V_638 && V_90 -> V_1110 ( V_2 ) ) {
-- V_2 -> V_5 . V_638 ;
V_2 -> V_5 . V_637 = true ;
V_90 -> V_1107 ( V_2 ) ;
} else if ( F_553 ( V_2 ) ) {
if ( F_40 ( V_2 ) && V_90 -> V_1109 ) {
V_124 = V_90 -> V_1109 ( V_2 , V_1104 ) ;
if ( V_124 != 0 )
return V_124 ;
}
if ( V_90 -> V_1111 ( V_2 ) ) {
F_281 ( V_2 , F_554 ( V_2 ) ,
false ) ;
V_90 -> V_1108 ( V_2 ) ;
}
}
return 0 ;
}
static void F_289 ( struct V_1 * V_2 )
{
unsigned V_930 = 2 ;
if ( V_90 -> V_640 ( V_2 ) || V_2 -> V_5 . V_637 )
V_930 = 1 ;
V_2 -> V_5 . V_638 += F_555 ( & V_2 -> V_5 . V_87 , 0 ) ;
V_2 -> V_5 . V_638 = F_357 ( V_2 -> V_5 . V_638 , V_930 ) ;
F_32 ( V_68 , V_2 ) ;
}
static T_1 F_556 ( struct V_840 * V_842 )
{
T_1 V_15 = 0 ;
V_15 |= V_842 -> V_929 << 23 ;
V_15 |= V_842 -> V_186 << 22 ;
V_15 |= V_842 -> V_935 << 21 ;
V_15 |= V_842 -> V_934 << 20 ;
V_15 |= V_842 -> V_933 << 15 ;
V_15 |= V_842 -> V_931 << 13 ;
V_15 |= V_842 -> V_602 << 12 ;
V_15 |= V_842 -> type << 8 ;
return V_15 ;
}
static void F_557 ( struct V_1 * V_2 , char * V_1112 , int V_503 )
{
struct V_840 V_842 ;
int V_97 ;
F_365 ( V_2 , & V_842 , V_503 ) ;
F_558 ( T_1 , V_1112 , 0x7fa8 + V_503 * 4 , V_842 . V_924 ) ;
if ( V_503 < 3 )
V_97 = 0x7f84 + V_503 * 12 ;
else
V_97 = 0x7f2c + ( V_503 - 3 ) * 12 ;
F_558 ( T_1 , V_1112 , V_97 + 8 , V_842 . V_233 ) ;
F_558 ( T_1 , V_1112 , V_97 + 4 , V_842 . V_930 ) ;
F_558 ( T_1 , V_1112 , V_97 , F_556 ( & V_842 ) ) ;
}
static void F_559 ( struct V_1 * V_2 , char * V_1112 , int V_503 )
{
struct V_840 V_842 ;
int V_97 ;
V_895 V_15 ;
F_365 ( V_2 , & V_842 , V_503 ) ;
V_97 = 0x7e00 + V_503 * 16 ;
V_15 = F_556 ( & V_842 ) >> 8 ;
F_558 ( V_895 , V_1112 , V_97 , V_842 . V_924 ) ;
F_558 ( V_895 , V_1112 , V_97 + 2 , V_15 ) ;
F_558 ( T_1 , V_1112 , V_97 + 4 , V_842 . V_930 ) ;
F_558 ( T_2 , V_1112 , V_97 + 8 , V_842 . V_233 ) ;
}
static void F_560 ( struct V_1 * V_2 , char * V_1112 )
{
struct V_918 V_919 ;
struct V_840 V_842 ;
unsigned long V_199 ;
int V_3 ;
F_558 ( T_1 , V_1112 , 0x7ffc , F_64 ( V_2 ) ) ;
F_558 ( T_1 , V_1112 , 0x7ff8 , F_62 ( V_2 ) ) ;
F_558 ( T_1 , V_1112 , 0x7ff4 , F_463 ( V_2 ) ) ;
F_558 ( T_1 , V_1112 , 0x7ff0 , F_464 ( V_2 ) ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
F_558 ( T_1 , V_1112 , 0x7fd0 + V_3 * 4 , F_105 ( V_2 , V_3 ) ) ;
F_103 ( V_2 , 6 , & V_199 ) ;
F_558 ( T_1 , V_1112 , 0x7fcc , ( T_1 ) V_199 ) ;
F_103 ( V_2 , 7 , & V_199 ) ;
F_558 ( T_1 , V_1112 , 0x7fc8 , ( T_1 ) V_199 ) ;
F_365 ( V_2 , & V_842 , V_1113 ) ;
F_558 ( T_1 , V_1112 , 0x7fc4 , V_842 . V_924 ) ;
F_558 ( T_1 , V_1112 , 0x7f64 , V_842 . V_233 ) ;
F_558 ( T_1 , V_1112 , 0x7f60 , V_842 . V_930 ) ;
F_558 ( T_1 , V_1112 , 0x7f5c , F_556 ( & V_842 ) ) ;
F_365 ( V_2 , & V_842 , V_1114 ) ;
F_558 ( T_1 , V_1112 , 0x7fc0 , V_842 . V_924 ) ;
F_558 ( T_1 , V_1112 , 0x7f80 , V_842 . V_233 ) ;
F_558 ( T_1 , V_1112 , 0x7f7c , V_842 . V_930 ) ;
F_558 ( T_1 , V_1112 , 0x7f78 , F_556 ( & V_842 ) ) ;
V_90 -> V_920 ( V_2 , & V_919 ) ;
F_558 ( T_1 , V_1112 , 0x7f74 , V_919 . V_81 ) ;
F_558 ( T_1 , V_1112 , 0x7f70 , V_919 . V_504 ) ;
V_90 -> V_921 ( V_2 , & V_919 ) ;
F_558 ( T_1 , V_1112 , 0x7f58 , V_919 . V_81 ) ;
F_558 ( T_1 , V_1112 , 0x7f54 , V_919 . V_504 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_557 ( V_2 , V_1112 , V_3 ) ;
F_558 ( T_1 , V_1112 , 0x7f14 , F_81 ( V_2 ) ) ;
F_558 ( T_1 , V_1112 , 0x7efc , 0x00020000 ) ;
F_558 ( T_1 , V_1112 , 0x7ef8 , V_2 -> V_5 . V_432 ) ;
}
static void F_561 ( struct V_1 * V_2 , char * V_1112 )
{
#ifdef F_65
struct V_918 V_919 ;
struct V_840 V_842 ;
unsigned long V_199 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ )
F_558 ( T_2 , V_1112 , 0x7ff8 - V_3 * 8 , F_105 ( V_2 , V_3 ) ) ;
F_558 ( T_2 , V_1112 , 0x7f78 , F_464 ( V_2 ) ) ;
F_558 ( T_1 , V_1112 , 0x7f70 , F_463 ( V_2 ) ) ;
F_103 ( V_2 , 6 , & V_199 ) ;
F_558 ( T_2 , V_1112 , 0x7f68 , V_199 ) ;
F_103 ( V_2 , 7 , & V_199 ) ;
F_558 ( T_2 , V_1112 , 0x7f60 , V_199 ) ;
F_558 ( T_2 , V_1112 , 0x7f58 , F_64 ( V_2 ) ) ;
F_558 ( T_2 , V_1112 , 0x7f50 , F_62 ( V_2 ) ) ;
F_558 ( T_2 , V_1112 , 0x7f48 , F_81 ( V_2 ) ) ;
F_558 ( T_1 , V_1112 , 0x7f00 , V_2 -> V_5 . V_432 ) ;
F_558 ( T_1 , V_1112 , 0x7efc , 0x00020064 ) ;
F_558 ( T_2 , V_1112 , 0x7ed0 , V_2 -> V_5 . V_135 ) ;
F_365 ( V_2 , & V_842 , V_1113 ) ;
F_558 ( V_895 , V_1112 , 0x7e90 , V_842 . V_924 ) ;
F_558 ( V_895 , V_1112 , 0x7e92 , F_556 ( & V_842 ) >> 8 ) ;
F_558 ( T_1 , V_1112 , 0x7e94 , V_842 . V_930 ) ;
F_558 ( T_2 , V_1112 , 0x7e98 , V_842 . V_233 ) ;
V_90 -> V_921 ( V_2 , & V_919 ) ;
F_558 ( T_1 , V_1112 , 0x7e84 , V_919 . V_504 ) ;
F_558 ( T_2 , V_1112 , 0x7e88 , V_919 . V_81 ) ;
F_365 ( V_2 , & V_842 , V_1114 ) ;
F_558 ( V_895 , V_1112 , 0x7e70 , V_842 . V_924 ) ;
F_558 ( V_895 , V_1112 , 0x7e72 , F_556 ( & V_842 ) >> 8 ) ;
F_558 ( T_1 , V_1112 , 0x7e74 , V_842 . V_930 ) ;
F_558 ( T_2 , V_1112 , 0x7e78 , V_842 . V_233 ) ;
V_90 -> V_920 ( V_2 , & V_919 ) ;
F_558 ( T_1 , V_1112 , 0x7e64 , V_919 . V_504 ) ;
F_558 ( T_2 , V_1112 , 0x7e68 , V_919 . V_81 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_559 ( V_2 , V_1112 , V_3 ) ;
#else
F_562 ( 1 ) ;
#endif
}
static void F_552 ( struct V_1 * V_2 )
{
struct V_840 V_1115 , V_1116 ;
struct V_918 V_919 ;
char V_1112 [ 512 ] ;
T_1 V_125 ;
F_480 ( V_2 -> V_303 , V_2 -> V_5 . V_432 , true ) ;
V_2 -> V_5 . V_646 |= V_659 ;
memset ( V_1112 , 0 , 512 ) ;
if ( F_563 ( V_2 ) )
F_561 ( V_2 , V_1112 ) ;
else
F_560 ( V_2 , V_1112 ) ;
F_213 ( V_2 , V_2 -> V_5 . V_432 + 0xfe00 , V_1112 , sizeof( V_1112 ) ) ;
if ( V_90 -> V_640 ( V_2 ) )
V_2 -> V_5 . V_646 |= V_647 ;
else
V_90 -> V_657 ( V_2 , true ) ;
F_469 ( V_2 , V_1117 ) ;
F_468 ( V_2 , 0x8000 ) ;
V_125 = V_2 -> V_5 . V_125 & ~ ( V_134 | V_1118 | V_1119 | V_128 ) ;
V_90 -> V_141 ( V_2 , V_125 ) ;
V_2 -> V_5 . V_125 = V_125 ;
V_90 -> V_174 ( V_2 , 0 ) ;
V_919 . V_81 = V_919 . V_504 = 0 ;
V_90 -> V_923 ( V_2 , & V_919 ) ;
F_101 ( V_2 , 7 , V_202 ) ;
V_1115 . V_924 = ( V_2 -> V_5 . V_432 >> 4 ) & 0xffff ;
V_1115 . V_233 = V_2 -> V_5 . V_432 ;
V_1116 . V_924 = 0 ;
V_1116 . V_233 = 0 ;
V_1115 . V_930 = V_1116 . V_930 = 0xffffffff ;
V_1115 . type = V_1116 . type = 0x3 ;
V_1115 . V_931 = V_1116 . V_931 = 0 ;
V_1115 . V_186 = V_1116 . V_186 = 0 ;
V_1115 . V_602 = V_1116 . V_602 = 1 ;
V_1115 . V_935 = V_1116 . V_935 = 0 ;
V_1115 . V_929 = V_1116 . V_929 = 1 ;
V_1115 . V_934 = V_1116 . V_934 = 0 ;
V_1115 . V_933 = V_1116 . V_933 = 1 ;
V_1115 . V_928 = V_1116 . V_928 = 0 ;
V_1115 . V_937 = V_1116 . V_937 = 0 ;
F_364 ( V_2 , & V_1115 , V_1120 ) ;
F_364 ( V_2 , & V_1116 , V_1121 ) ;
F_364 ( V_2 , & V_1116 , V_1122 ) ;
F_364 ( V_2 , & V_1116 , V_1123 ) ;
F_364 ( V_2 , & V_1116 , V_1124 ) ;
F_364 ( V_2 , & V_1116 , V_1125 ) ;
if ( F_563 ( V_2 ) )
V_90 -> F_111 ( V_2 , 0 ) ;
F_78 ( V_2 ) ;
F_68 ( V_2 ) ;
}
static void F_564 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_644 = true ;
F_32 ( V_68 , V_2 ) ;
}
void F_565 ( struct V_142 * V_142 )
{
F_182 ( V_142 , V_1126 ) ;
}
static void F_566 ( struct V_1 * V_2 )
{
T_2 V_1127 [ 4 ] ;
if ( ! F_567 ( V_2 -> V_5 . V_658 ) )
return;
F_568 ( V_2 -> V_5 . V_1128 , 256 ) ;
if ( F_569 ( V_2 -> V_142 ) )
F_570 ( V_2 , V_2 -> V_5 . V_1128 ) ;
else {
if ( V_90 -> V_603 && V_2 -> V_5 . V_604 )
V_90 -> V_603 ( V_2 ) ;
F_571 ( V_2 , V_2 -> V_5 . V_1128 ) ;
}
F_572 ( ( V_179 * ) V_1127 , V_2 -> V_5 . V_1128 ,
F_573 ( V_2 ) -> V_1129 , 256 ) ;
V_90 -> V_1130 ( V_2 , V_1127 ) ;
}
static void F_574 ( struct V_1 * V_2 )
{
++ V_2 -> V_76 . V_1131 ;
V_90 -> V_1131 ( V_2 ) ;
}
void F_575 ( struct V_1 * V_2 )
{
struct V_389 * V_389 = NULL ;
if ( ! F_92 ( V_2 ) )
return;
if ( ! V_90 -> V_1132 )
return;
V_389 = F_576 ( V_2 -> V_142 , V_858 >> V_109 ) ;
if ( F_400 ( V_389 ) )
return;
V_90 -> V_1132 ( V_2 , F_577 ( V_389 ) ) ;
F_578 ( V_389 ) ;
}
static int F_579 ( struct V_1 * V_2 )
{
int V_124 ;
bool V_1104 =
F_547 ( V_2 ) &&
F_273 ( V_2 ) ;
bool V_1133 = false ;
if ( F_580 ( V_2 ) ) {
if ( F_581 ( V_1134 , V_2 ) )
F_582 ( V_2 ) ;
if ( F_581 ( V_599 , V_2 ) )
F_583 ( V_2 ) ;
if ( F_581 ( V_302 , V_2 ) )
F_183 ( V_2 -> V_142 ) ;
if ( F_581 ( V_438 , V_2 ) )
F_204 ( V_2 ) ;
if ( F_581 ( V_343 , V_2 ) ) {
V_124 = F_198 ( V_2 ) ;
if ( F_172 ( V_124 ) )
goto V_116;
}
if ( F_581 ( V_1135 , V_2 ) )
F_89 ( V_2 ) ;
if ( F_581 ( V_176 , V_2 ) )
F_574 ( V_2 ) ;
if ( F_581 ( V_1136 , V_2 ) ) {
V_2 -> V_866 -> V_884 = V_1137 ;
V_124 = 0 ;
goto V_116;
}
if ( F_581 ( V_73 , V_2 ) ) {
V_2 -> V_866 -> V_884 = V_1138 ;
V_124 = 0 ;
goto V_116;
}
if ( F_581 ( V_1139 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1140 = true ;
V_124 = 1 ;
goto V_116;
}
if ( F_581 ( V_443 , V_2 ) )
F_219 ( V_2 ) ;
if ( F_581 ( V_611 , V_2 ) )
F_564 ( V_2 ) ;
if ( F_581 ( V_88 , V_2 ) )
F_289 ( V_2 ) ;
if ( F_581 ( V_1141 , V_2 ) )
F_584 ( V_2 ) ;
if ( F_581 ( V_1142 , V_2 ) )
F_585 ( V_2 ) ;
if ( F_581 ( V_1143 , V_2 ) ) {
F_15 ( V_2 -> V_5 . V_1144 > 255 ) ;
if ( F_61 ( V_2 -> V_5 . V_1144 ,
V_2 -> V_5 . V_1128 ) ) {
V_2 -> V_866 -> V_884 = V_1145 ;
V_2 -> V_866 -> V_1146 . V_42 =
V_2 -> V_5 . V_1144 ;
V_124 = 0 ;
goto V_116;
}
}
if ( F_581 ( V_1126 , V_2 ) )
F_566 ( V_2 ) ;
if ( F_581 ( V_1147 , V_2 ) )
F_575 ( V_2 ) ;
if ( F_581 ( V_1148 , V_2 ) ) {
V_2 -> V_866 -> V_884 = V_1149 ;
V_2 -> V_866 -> V_1150 . type = V_1151 ;
V_124 = 0 ;
goto V_116;
}
if ( F_581 ( V_1152 , V_2 ) ) {
V_2 -> V_866 -> V_884 = V_1149 ;
V_2 -> V_866 -> V_1150 . type = V_1153 ;
V_124 = 0 ;
goto V_116;
}
if ( F_581 ( V_1154 , V_2 ) ) {
V_2 -> V_866 -> V_884 = V_1155 ;
V_2 -> V_866 -> V_1156 = V_2 -> V_5 . V_1156 . exit ;
V_124 = 0 ;
goto V_116;
}
if ( F_581 ( V_1157 , V_2 ) )
F_586 ( V_2 ) ;
}
if ( F_581 ( V_68 , V_2 ) || V_1104 ) {
++ V_2 -> V_76 . V_1158 ;
F_587 ( V_2 ) ;
if ( V_2 -> V_5 . V_654 == V_655 ) {
V_124 = 1 ;
goto V_116;
}
if ( F_550 ( V_2 , V_1104 ) != 0 )
V_1133 = true ;
else {
if ( V_2 -> V_5 . V_644 && ! F_291 ( V_2 ) )
V_1133 = true ;
if ( V_2 -> V_5 . V_638 )
V_90 -> V_1159 ( V_2 ) ;
if ( F_553 ( V_2 ) || V_1104 )
V_90 -> V_1160 ( V_2 ) ;
}
if ( F_588 ( V_2 ) ) {
F_272 ( V_2 ) ;
F_589 ( V_2 ) ;
}
}
V_124 = F_590 ( V_2 ) ;
if ( F_172 ( V_124 ) ) {
goto V_1161;
}
F_449 () ;
V_90 -> V_1162 ( V_2 ) ;
F_450 ( V_2 ) ;
F_591 () ;
V_2 -> V_334 = V_1163 ;
F_244 ( & V_2 -> V_142 -> V_499 , V_2 -> V_1164 ) ;
F_592 () ;
if ( F_588 ( V_2 ) ) {
if ( V_90 -> V_603 && V_2 -> V_5 . V_604 )
V_90 -> V_603 ( V_2 ) ;
}
if ( V_2 -> V_334 == V_1165 || F_580 ( V_2 )
|| F_593 () || F_594 ( V_406 ) ) {
V_2 -> V_334 = V_1166 ;
F_196 () ;
F_595 () ;
F_452 () ;
V_2 -> V_1164 = F_243 ( & V_2 -> V_142 -> V_499 ) ;
V_124 = 1 ;
goto V_1161;
}
F_74 ( V_2 ) ;
if ( V_1133 ) {
F_32 ( V_68 , V_2 ) ;
F_596 ( V_2 -> V_24 ) ;
}
F_597 ( V_2 -> V_303 ) ;
F_598 ( V_2 ) ;
F_599 () ;
if ( F_172 ( V_2 -> V_5 . V_187 ) ) {
F_600 ( 0 , 7 ) ;
F_600 ( V_2 -> V_5 . V_185 [ 0 ] , 0 ) ;
F_600 ( V_2 -> V_5 . V_185 [ 1 ] , 1 ) ;
F_600 ( V_2 -> V_5 . V_185 [ 2 ] , 2 ) ;
F_600 ( V_2 -> V_5 . V_185 [ 3 ] , 3 ) ;
F_600 ( V_2 -> V_5 . V_190 , 6 ) ;
V_2 -> V_5 . V_187 &= ~ V_188 ;
}
V_90 -> V_866 ( V_2 ) ;
if ( F_172 ( V_2 -> V_5 . V_187 & V_1167 ) ) {
F_30 ( V_2 -> V_182 & V_183 ) ;
V_90 -> V_1168 ( V_2 ) ;
F_96 ( V_2 ) ;
F_97 ( V_2 ) ;
F_98 ( V_2 ) ;
V_2 -> V_5 . V_187 &= ~ V_188 ;
}
if ( F_601 () )
F_602 () ;
V_2 -> V_5 . V_328 = F_153 ( V_2 , F_152 () ) ;
V_2 -> V_334 = V_1166 ;
F_196 () ;
F_76 ( V_2 ) ;
V_90 -> V_1169 ( V_2 ) ;
++ V_2 -> V_76 . V_1170 ;
F_603 () ;
F_595 () ;
F_452 () ;
V_2 -> V_1164 = F_243 ( & V_2 -> V_142 -> V_499 ) ;
if ( F_172 ( V_1171 == V_1172 ) ) {
unsigned long V_1096 = F_464 ( V_2 ) ;
F_604 ( V_1172 , ( void * ) V_1096 ) ;
}
if ( F_172 ( V_2 -> V_5 . V_279 ) )
F_32 ( V_343 , V_2 ) ;
if ( V_2 -> V_5 . V_1173 )
F_605 ( V_2 ) ;
V_124 = V_90 -> V_1174 ( V_2 ) ;
return V_124 ;
V_1161:
V_90 -> V_1161 ( V_2 ) ;
if ( F_172 ( V_2 -> V_5 . V_1173 ) )
F_605 ( V_2 ) ;
V_116:
return V_124 ;
}
static inline int F_606 ( struct V_142 * V_142 , struct V_1 * V_2 )
{
if ( ! F_607 ( V_2 ) &&
( ! V_90 -> V_1175 || V_90 -> V_1175 ( V_2 ) == 0 ) ) {
F_244 ( & V_142 -> V_499 , V_2 -> V_1164 ) ;
F_608 ( V_2 ) ;
V_2 -> V_1164 = F_243 ( & V_142 -> V_499 ) ;
if ( V_90 -> V_1176 )
V_90 -> V_1176 ( V_2 ) ;
if ( ! F_581 ( V_1177 , V_2 ) )
return 1 ;
}
F_587 ( V_2 ) ;
switch( V_2 -> V_5 . V_654 ) {
case V_1062 :
V_2 -> V_5 . V_1178 . V_1179 = false ;
V_2 -> V_5 . V_654 =
V_1180 ;
case V_1180 :
V_2 -> V_5 . V_6 . V_1140 = false ;
break;
case V_655 :
break;
default:
return - V_1181 ;
break;
}
return 1 ;
}
static inline bool F_609 ( struct V_1 * V_2 )
{
if ( F_40 ( V_2 ) && V_90 -> V_1109 )
V_90 -> V_1109 ( V_2 , false ) ;
return ( V_2 -> V_5 . V_654 == V_1180 &&
! V_2 -> V_5 . V_6 . V_1140 ) ;
}
static int F_610 ( struct V_1 * V_2 )
{
int V_124 ;
struct V_142 * V_142 = V_2 -> V_142 ;
V_2 -> V_1164 = F_243 ( & V_142 -> V_499 ) ;
for (; ; ) {
if ( F_609 ( V_2 ) ) {
V_124 = F_579 ( V_2 ) ;
} else {
V_124 = F_606 ( V_142 , V_2 ) ;
}
if ( V_124 <= 0 )
break;
F_185 ( V_245 , V_2 ) ;
if ( F_611 ( V_2 ) )
F_612 ( V_2 ) ;
if ( F_547 ( V_2 ) &&
F_275 ( V_2 ) ) {
V_124 = 0 ;
V_2 -> V_866 -> V_884 = V_1182 ;
++ V_2 -> V_76 . V_1183 ;
break;
}
F_613 ( V_2 ) ;
if ( F_594 ( V_406 ) ) {
V_124 = - V_1181 ;
V_2 -> V_866 -> V_884 = V_1184 ;
++ V_2 -> V_76 . V_1185 ;
break;
}
if ( F_593 () ) {
F_244 ( & V_142 -> V_499 , V_2 -> V_1164 ) ;
F_614 () ;
V_2 -> V_1164 = F_243 ( & V_142 -> V_499 ) ;
}
}
F_244 ( & V_142 -> V_499 , V_2 -> V_1164 ) ;
return V_124 ;
}
static inline int F_615 ( struct V_1 * V_2 )
{
int V_124 ;
V_2 -> V_1164 = F_243 ( & V_2 -> V_142 -> V_499 ) ;
V_124 = F_616 ( V_2 , V_1005 ) ;
F_244 ( & V_2 -> V_142 -> V_499 , V_2 -> V_1164 ) ;
if ( V_124 != V_971 )
return 0 ;
return 1 ;
}
static int V_1018 ( struct V_1 * V_2 )
{
F_15 ( ! V_2 -> V_5 . V_899 . V_767 ) ;
return F_615 ( V_2 ) ;
}
static int V_1019 ( struct V_1 * V_2 )
{
struct V_990 * V_866 = V_2 -> V_866 ;
struct V_864 * V_865 ;
unsigned V_98 ;
F_15 ( ! V_2 -> V_880 ) ;
V_865 = & V_2 -> V_861 [ V_2 -> V_881 ] ;
V_98 = F_357 ( 8u , V_865 -> V_98 ) ;
if ( ! V_2 -> V_883 )
memcpy ( V_865 -> V_39 , V_866 -> V_867 . V_39 , V_98 ) ;
if ( V_865 -> V_98 <= 8 ) {
V_865 ++ ;
V_2 -> V_881 ++ ;
} else {
V_865 -> V_39 += V_98 ;
V_865 -> V_393 += V_98 ;
V_865 -> V_98 -= V_98 ;
}
if ( V_2 -> V_881 >= V_2 -> V_874 ) {
V_2 -> V_880 = 0 ;
if ( V_2 -> V_883 )
return 1 ;
V_2 -> V_860 = 1 ;
return F_615 ( V_2 ) ;
}
V_866 -> V_884 = V_885 ;
V_866 -> V_867 . V_886 = V_865 -> V_393 ;
if ( V_2 -> V_883 )
memcpy ( V_866 -> V_867 . V_39 , V_865 -> V_39 , F_357 ( 8u , V_865 -> V_98 ) ) ;
V_866 -> V_867 . V_98 = F_357 ( 8u , V_865 -> V_98 ) ;
V_866 -> V_867 . V_882 = V_2 -> V_883 ;
V_2 -> V_5 . V_1017 = V_1019 ;
return 0 ;
}
int F_617 ( struct V_1 * V_2 , struct V_990 * V_990 )
{
struct V_1186 * V_1186 = & V_406 -> V_1187 . V_1186 ;
int V_124 ;
T_17 V_1188 ;
F_618 ( V_1186 ) ;
if ( V_2 -> V_1189 )
F_619 ( V_1190 , & V_2 -> V_1191 , & V_1188 ) ;
if ( F_172 ( V_2 -> V_5 . V_654 == V_1192 ) ) {
F_608 ( V_2 ) ;
F_587 ( V_2 ) ;
F_185 ( V_1177 , V_2 ) ;
V_124 = - V_1193 ;
goto V_116;
}
if ( ! F_92 ( V_2 ) ) {
if ( F_91 ( V_2 , V_990 -> V_180 ) != 0 ) {
V_124 = - V_591 ;
goto V_116;
}
}
if ( F_172 ( V_2 -> V_5 . V_1017 ) ) {
int (* F_620)( struct V_1 * ) = V_2 -> V_5 . V_1017 ;
V_2 -> V_5 . V_1017 = NULL ;
V_124 = F_620 ( V_2 ) ;
if ( V_124 <= 0 )
goto V_116;
} else
F_30 ( V_2 -> V_5 . V_899 . V_767 || V_2 -> V_880 ) ;
if ( V_990 -> V_1194 )
V_124 = - V_1181 ;
else
V_124 = F_610 ( V_2 ) ;
V_116:
F_548 ( V_2 ) ;
if ( V_2 -> V_1189 )
F_619 ( V_1190 , & V_1188 , NULL ) ;
return V_124 ;
}
int F_621 ( struct V_1 * V_2 , struct V_1195 * V_1196 )
{
if ( V_2 -> V_5 . V_1021 ) {
F_622 ( & V_2 -> V_5 . V_870 ) ;
V_2 -> V_5 . V_1021 = false ;
}
V_1196 -> V_1197 = F_105 ( V_2 , V_206 ) ;
V_1196 -> V_1198 = F_105 ( V_2 , V_1087 ) ;
V_1196 -> V_1199 = F_105 ( V_2 , V_205 ) ;
V_1196 -> V_1200 = F_105 ( V_2 , V_207 ) ;
V_1196 -> V_1201 = F_105 ( V_2 , V_1088 ) ;
V_1196 -> V_1202 = F_105 ( V_2 , V_1203 ) ;
V_1196 -> V_1204 = F_105 ( V_2 , V_1205 ) ;
V_1196 -> V_1206 = F_105 ( V_2 , V_1207 ) ;
#ifdef F_65
V_1196 -> V_1208 = F_105 ( V_2 , V_1209 ) ;
V_1196 -> V_1210 = F_105 ( V_2 , V_1211 ) ;
V_1196 -> V_1212 = F_105 ( V_2 , V_1213 ) ;
V_1196 -> V_1214 = F_105 ( V_2 , V_1215 ) ;
V_1196 -> V_1216 = F_105 ( V_2 , V_1217 ) ;
V_1196 -> V_1218 = F_105 ( V_2 , V_1219 ) ;
V_1196 -> V_1220 = F_105 ( V_2 , V_1221 ) ;
V_1196 -> V_1222 = F_105 ( V_2 , V_1223 ) ;
#endif
V_1196 -> V_1096 = F_464 ( V_2 ) ;
V_1196 -> V_998 = F_463 ( V_2 ) ;
return 0 ;
}
int F_623 ( struct V_1 * V_2 , struct V_1195 * V_1196 )
{
V_2 -> V_5 . V_965 = true ;
V_2 -> V_5 . V_1021 = false ;
F_107 ( V_2 , V_206 , V_1196 -> V_1197 ) ;
F_107 ( V_2 , V_1087 , V_1196 -> V_1198 ) ;
F_107 ( V_2 , V_205 , V_1196 -> V_1199 ) ;
F_107 ( V_2 , V_207 , V_1196 -> V_1200 ) ;
F_107 ( V_2 , V_1088 , V_1196 -> V_1201 ) ;
F_107 ( V_2 , V_1203 , V_1196 -> V_1202 ) ;
F_107 ( V_2 , V_1205 , V_1196 -> V_1204 ) ;
F_107 ( V_2 , V_1207 , V_1196 -> V_1206 ) ;
#ifdef F_65
F_107 ( V_2 , V_1209 , V_1196 -> V_1208 ) ;
F_107 ( V_2 , V_1211 , V_1196 -> V_1210 ) ;
F_107 ( V_2 , V_1213 , V_1196 -> V_1212 ) ;
F_107 ( V_2 , V_1215 , V_1196 -> V_1214 ) ;
F_107 ( V_2 , V_1217 , V_1196 -> V_1216 ) ;
F_107 ( V_2 , V_1219 , V_1196 -> V_1218 ) ;
F_107 ( V_2 , V_1221 , V_1196 -> V_1220 ) ;
F_107 ( V_2 , V_1223 , V_1196 -> V_1222 ) ;
#endif
F_468 ( V_2 , V_1196 -> V_1096 ) ;
F_469 ( V_2 , V_1196 -> V_998 ) ;
V_2 -> V_5 . V_69 . V_70 = false ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
void F_624 ( struct V_1 * V_2 , int * V_186 , int * V_935 )
{
struct V_840 V_1115 ;
F_365 ( V_2 , & V_1115 , V_1120 ) ;
* V_186 = V_1115 . V_186 ;
* V_935 = V_1115 . V_935 ;
}
int F_625 ( struct V_1 * V_2 ,
struct V_1224 * V_1225 )
{
struct V_918 V_919 ;
F_365 ( V_2 , & V_1225 -> V_1115 , V_1120 ) ;
F_365 ( V_2 , & V_1225 -> V_1116 , V_1121 ) ;
F_365 ( V_2 , & V_1225 -> V_1226 , V_1122 ) ;
F_365 ( V_2 , & V_1225 -> V_1227 , V_1123 ) ;
F_365 ( V_2 , & V_1225 -> V_1228 , V_1124 ) ;
F_365 ( V_2 , & V_1225 -> V_1229 , V_1125 ) ;
F_365 ( V_2 , & V_1225 -> V_1230 , V_1113 ) ;
F_365 ( V_2 , & V_1225 -> V_1231 , V_1114 ) ;
V_90 -> V_921 ( V_2 , & V_919 ) ;
V_1225 -> V_1232 . V_930 = V_919 . V_504 ;
V_1225 -> V_1232 . V_233 = V_919 . V_81 ;
V_90 -> V_920 ( V_2 , & V_919 ) ;
V_1225 -> V_1233 . V_930 = V_919 . V_504 ;
V_1225 -> V_1233 . V_233 = V_919 . V_81 ;
V_1225 -> V_125 = F_64 ( V_2 ) ;
V_1225 -> V_82 = V_2 -> V_5 . V_82 ;
V_1225 -> V_107 = F_62 ( V_2 ) ;
V_1225 -> V_162 = F_81 ( V_2 ) ;
V_1225 -> V_180 = F_94 ( V_2 ) ;
V_1225 -> V_135 = V_2 -> V_5 . V_135 ;
V_1225 -> V_32 = F_21 ( V_2 ) ;
memset ( V_1225 -> V_1234 , 0 , sizeof V_1225 -> V_1234 ) ;
if ( V_2 -> V_5 . V_632 . V_70 && ! V_2 -> V_5 . V_632 . V_633 )
F_295 ( V_2 -> V_5 . V_632 . V_18 ,
( unsigned long * ) V_1225 -> V_1234 ) ;
return 0 ;
}
int F_626 ( struct V_1 * V_2 ,
struct V_1235 * V_654 )
{
F_587 ( V_2 ) ;
if ( V_2 -> V_5 . V_654 == V_1062 &&
V_2 -> V_5 . V_1178 . V_1179 )
V_654 -> V_654 = V_1180 ;
else
V_654 -> V_654 = V_2 -> V_5 . V_654 ;
return 0 ;
}
int F_627 ( struct V_1 * V_2 ,
struct V_1235 * V_654 )
{
if ( ! F_92 ( V_2 ) &&
V_654 -> V_654 != V_1180 )
return - V_591 ;
if ( ( F_291 ( V_2 ) || V_2 -> V_5 . V_644 ) &&
( V_654 -> V_654 == V_1236 ||
V_654 -> V_654 == V_655 ) )
return - V_591 ;
if ( V_654 -> V_654 == V_1236 ) {
V_2 -> V_5 . V_654 = V_655 ;
F_295 ( V_1237 , & V_2 -> V_5 . V_658 -> V_661 ) ;
} else
V_2 -> V_5 . V_654 = V_654 -> V_654 ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
int F_628 ( struct V_1 * V_2 , V_895 V_1238 , int V_1239 ,
int V_1240 , bool V_72 , T_1 V_63 )
{
struct V_854 * V_855 = & V_2 -> V_5 . V_870 ;
int V_111 ;
F_462 ( V_2 ) ;
V_111 = F_629 ( V_855 , V_1238 , V_1239 , V_1240 ,
V_72 , V_63 ) ;
if ( V_111 )
return V_970 ;
F_468 ( V_2 , V_855 -> V_955 ) ;
F_469 ( V_2 , V_855 -> V_952 ) ;
F_32 ( V_68 , V_2 ) ;
return V_971 ;
}
int F_630 ( struct V_1 * V_2 ,
struct V_1224 * V_1225 )
{
struct V_33 V_1241 ;
int V_1242 = 0 ;
int V_1243 , V_1244 , V_498 ;
struct V_918 V_919 ;
if ( ! F_82 ( V_2 ) && ( V_1225 -> V_162 & V_145 ) )
return - V_591 ;
V_919 . V_504 = V_1225 -> V_1232 . V_930 ;
V_919 . V_81 = V_1225 -> V_1232 . V_233 ;
V_90 -> V_923 ( V_2 , & V_919 ) ;
V_919 . V_504 = V_1225 -> V_1233 . V_930 ;
V_919 . V_81 = V_1225 -> V_1233 . V_233 ;
V_90 -> V_922 ( V_2 , & V_919 ) ;
V_2 -> V_5 . V_82 = V_1225 -> V_82 ;
V_1242 |= F_62 ( V_2 ) != V_1225 -> V_107 ;
V_2 -> V_5 . V_107 = V_1225 -> V_107 ;
F_57 ( V_178 , ( V_179 * ) & V_2 -> V_5 . V_121 ) ;
F_91 ( V_2 , V_1225 -> V_180 ) ;
V_1242 |= V_2 -> V_5 . V_135 != V_1225 -> V_135 ;
V_90 -> F_111 ( V_2 , V_1225 -> V_135 ) ;
V_1241 . V_39 = V_1225 -> V_32 ;
V_1241 . V_41 = true ;
F_22 ( V_2 , & V_1241 ) ;
V_1242 |= F_64 ( V_2 ) != V_1225 -> V_125 ;
V_90 -> V_141 ( V_2 , V_1225 -> V_125 ) ;
V_2 -> V_5 . V_125 = V_1225 -> V_125 ;
V_1242 |= F_81 ( V_2 ) != V_1225 -> V_162 ;
V_90 -> V_174 ( V_2 , V_1225 -> V_162 ) ;
if ( V_1225 -> V_162 & ( V_145 | V_170 ) )
F_78 ( V_2 ) ;
V_498 = F_243 ( & V_2 -> V_142 -> V_499 ) ;
if ( ! F_59 ( V_2 ) && F_60 ( V_2 ) ) {
F_55 ( V_2 , V_2 -> V_5 . V_106 , F_62 ( V_2 ) ) ;
V_1242 = 1 ;
}
F_244 ( & V_2 -> V_142 -> V_499 , V_498 ) ;
if ( V_1242 )
F_68 ( V_2 ) ;
V_1244 = V_607 ;
V_1243 = F_631 (
( const unsigned long * ) V_1225 -> V_1234 , V_1244 ) ;
if ( V_1243 < V_1244 ) {
F_281 ( V_2 , V_1243 , false ) ;
F_134 ( L_28 , V_1243 ) ;
}
F_364 ( V_2 , & V_1225 -> V_1115 , V_1120 ) ;
F_364 ( V_2 , & V_1225 -> V_1116 , V_1121 ) ;
F_364 ( V_2 , & V_1225 -> V_1226 , V_1122 ) ;
F_364 ( V_2 , & V_1225 -> V_1227 , V_1123 ) ;
F_364 ( V_2 , & V_1225 -> V_1228 , V_1124 ) ;
F_364 ( V_2 , & V_1225 -> V_1229 , V_1125 ) ;
F_364 ( V_2 , & V_1225 -> V_1230 , V_1113 ) ;
F_364 ( V_2 , & V_1225 -> V_1231 , V_1114 ) ;
F_272 ( V_2 ) ;
if ( F_632 ( V_2 ) && F_464 ( V_2 ) == 0xfff0 &&
V_1225 -> V_1115 . V_924 == 0xf000 && V_1225 -> V_1115 . V_233 == 0xffff0000 &&
! F_33 ( V_2 ) )
V_2 -> V_5 . V_654 = V_1180 ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
int F_633 ( struct V_1 * V_2 ,
struct V_1245 * V_1246 )
{
unsigned long V_998 ;
int V_3 , V_124 ;
if ( V_1246 -> V_774 & ( V_1247 | V_1248 ) ) {
V_124 = - V_821 ;
if ( V_2 -> V_5 . V_69 . V_70 )
goto V_116;
if ( V_1246 -> V_774 & V_1247 )
F_34 ( V_2 , V_54 ) ;
else
F_34 ( V_2 , V_55 ) ;
}
V_998 = F_463 ( V_2 ) ;
V_2 -> V_182 = V_1246 -> V_774 ;
if ( ! ( V_2 -> V_182 & V_1249 ) )
V_2 -> V_182 = 0 ;
if ( V_2 -> V_182 & V_183 ) {
for ( V_3 = 0 ; V_3 < V_184 ; ++ V_3 )
V_2 -> V_5 . V_185 [ V_3 ] = V_1246 -> V_5 . V_1250 [ V_3 ] ;
V_2 -> V_5 . V_192 = V_1246 -> V_5 . V_1250 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_184 ; V_3 ++ )
V_2 -> V_5 . V_185 [ V_3 ] = V_2 -> V_5 . V_186 [ V_3 ] ;
}
F_98 ( V_2 ) ;
if ( V_2 -> V_182 & V_991 )
V_2 -> V_5 . V_995 = F_464 ( V_2 ) +
F_414 ( V_2 , V_1120 ) ;
F_469 ( V_2 , V_998 ) ;
V_90 -> V_1251 ( V_2 ) ;
V_124 = 0 ;
V_116:
return V_124 ;
}
int F_634 ( struct V_1 * V_2 ,
struct V_1252 * V_1230 )
{
unsigned long V_1253 = V_1230 -> V_1254 ;
T_6 V_393 ;
int V_498 ;
V_498 = F_243 ( & V_2 -> V_142 -> V_499 ) ;
V_393 = F_370 ( V_2 , V_1253 , NULL ) ;
F_244 ( & V_2 -> V_142 -> V_499 , V_498 ) ;
V_1230 -> V_1255 = V_393 ;
V_1230 -> V_672 = V_393 != V_103 ;
V_1230 -> V_1256 = 1 ;
V_1230 -> V_1257 = 0 ;
return 0 ;
}
int F_635 ( struct V_1 * V_2 , struct V_1258 * V_1186 )
{
struct V_687 * V_686 =
& V_2 -> V_5 . V_667 . V_668 . V_686 ;
memcpy ( V_1186 -> V_1259 , V_686 -> V_1260 , 128 ) ;
V_1186 -> V_1261 = V_686 -> V_1262 ;
V_1186 -> V_1263 = V_686 -> V_1264 ;
V_1186 -> V_1265 = V_686 -> V_1266 ;
V_1186 -> V_1267 = V_686 -> V_1268 ;
V_1186 -> V_1269 = V_686 -> V_1096 ;
V_1186 -> V_1270 = V_686 -> V_1271 ;
memcpy ( V_1186 -> V_1272 , V_686 -> V_1273 , sizeof V_686 -> V_1273 ) ;
return 0 ;
}
int F_636 ( struct V_1 * V_2 , struct V_1258 * V_1186 )
{
struct V_687 * V_686 =
& V_2 -> V_5 . V_667 . V_668 . V_686 ;
memcpy ( V_686 -> V_1260 , V_1186 -> V_1259 , 128 ) ;
V_686 -> V_1262 = V_1186 -> V_1261 ;
V_686 -> V_1264 = V_1186 -> V_1263 ;
V_686 -> V_1266 = V_1186 -> V_1265 ;
V_686 -> V_1268 = V_1186 -> V_1267 ;
V_686 -> V_1096 = V_1186 -> V_1269 ;
V_686 -> V_1271 = V_1186 -> V_1270 ;
memcpy ( V_686 -> V_1273 , V_1186 -> V_1272 , sizeof V_686 -> V_1273 ) ;
return 0 ;
}
static void F_637 ( struct V_1 * V_2 )
{
F_638 ( & V_2 -> V_5 . V_667 . V_668 ) ;
if ( F_250 ( V_680 ) )
V_2 -> V_5 . V_667 . V_668 . V_666 . V_670 . V_681 =
V_149 | V_682 ;
V_2 -> V_5 . V_148 = V_154 ;
V_2 -> V_5 . V_125 |= V_130 ;
}
void F_450 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1274 )
return;
V_2 -> V_1274 = 1 ;
F_639 () ;
F_640 ( & V_2 -> V_5 . V_667 . V_668 ,
~ V_678 ) ;
F_641 ( 1 ) ;
}
void F_267 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_1274 )
return;
V_2 -> V_1274 = 0 ;
F_642 ( & V_2 -> V_5 . V_667 ) ;
F_643 () ;
++ V_2 -> V_76 . V_1275 ;
F_641 ( 0 ) ;
}
void F_644 ( struct V_1 * V_2 )
{
void * V_594 = V_2 -> V_5 . V_594 ;
F_218 ( V_2 ) ;
V_90 -> V_1276 ( V_2 ) ;
F_645 ( V_594 ) ;
}
struct V_1 * F_646 ( struct V_142 * V_142 ,
unsigned int V_1277 )
{
struct V_1 * V_2 ;
if ( F_159 () && F_145 ( & V_142 -> V_299 ) != 0 )
F_408 ( V_897
L_29
L_30 ) ;
V_2 = V_90 -> V_1278 ( V_142 , V_1277 ) ;
return V_2 ;
}
int F_647 ( struct V_1 * V_2 )
{
int V_124 ;
F_648 ( V_2 ) ;
V_124 = V_595 ( V_2 ) ;
if ( V_124 )
return V_124 ;
F_649 ( V_2 , false ) ;
F_650 ( V_2 ) ;
V_600 ( V_2 ) ;
return V_124 ;
}
void F_651 ( struct V_1 * V_2 )
{
struct V_33 V_22 ;
struct V_142 * V_142 = V_2 -> V_142 ;
F_652 ( V_2 ) ;
if ( V_595 ( V_2 ) )
return;
V_22 . V_39 = 0x0 ;
V_22 . V_150 = V_1279 ;
V_22 . V_41 = true ;
F_155 ( V_2 , & V_22 ) ;
V_600 ( V_2 ) ;
if ( ! V_368 )
return;
F_205 ( & V_142 -> V_5 . V_367 ,
V_369 ) ;
}
void F_653 ( struct V_1 * V_2 )
{
int V_124 ;
V_2 -> V_5 . V_6 . V_394 = 0 ;
V_124 = V_595 ( V_2 ) ;
F_15 ( V_124 ) ;
F_582 ( V_2 ) ;
V_600 ( V_2 ) ;
V_90 -> V_1276 ( V_2 ) ;
}
void F_649 ( struct V_1 * V_2 , bool V_1280 )
{
V_2 -> V_5 . V_646 = 0 ;
V_2 -> V_5 . V_644 = 0 ;
F_179 ( & V_2 -> V_5 . V_87 , 0 ) ;
V_2 -> V_5 . V_638 = 0 ;
V_2 -> V_5 . V_637 = false ;
F_654 ( V_2 ) ;
F_486 ( V_2 ) ;
memset ( V_2 -> V_5 . V_186 , 0 , sizeof( V_2 -> V_5 . V_186 ) ) ;
F_96 ( V_2 ) ;
V_2 -> V_5 . V_190 = V_1281 ;
F_97 ( V_2 ) ;
V_2 -> V_5 . V_191 = V_202 ;
F_98 ( V_2 ) ;
V_2 -> V_5 . V_82 = 0 ;
F_32 ( V_68 , V_2 ) ;
V_2 -> V_5 . V_6 . V_394 = 0 ;
V_2 -> V_5 . V_400 . V_394 = 0 ;
F_218 ( V_2 ) ;
F_67 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1140 = false ;
if ( ! V_1280 ) {
F_655 ( V_2 ) ;
V_2 -> V_5 . V_432 = 0x30000 ;
V_2 -> V_5 . V_470 = V_469 ;
V_2 -> V_5 . V_473 = 0 ;
}
memset ( V_2 -> V_5 . V_1196 , 0 , sizeof( V_2 -> V_5 . V_1196 ) ) ;
V_2 -> V_5 . V_121 = ~ 0 ;
V_2 -> V_5 . V_122 = ~ 0 ;
V_90 -> V_1282 ( V_2 , V_1280 ) ;
}
void F_656 ( struct V_1 * V_2 , T_13 V_42 )
{
struct V_840 V_1115 ;
F_365 ( V_2 , & V_1115 , V_1120 ) ;
V_1115 . V_924 = V_42 << 8 ;
V_1115 . V_233 = V_42 << 12 ;
F_364 ( V_2 , & V_1115 , V_1120 ) ;
F_468 ( V_2 , 0 ) ;
}
int F_657 ( void )
{
struct V_142 * V_142 ;
struct V_1 * V_2 ;
int V_3 ;
int V_111 ;
T_2 V_1283 ;
T_2 V_1284 = 0 ;
bool V_1285 , V_1286 = false ;
F_16 () ;
V_111 = V_90 -> V_1287 () ;
if ( V_111 != 0 )
return V_111 ;
V_1283 = F_152 () ;
V_1285 = ! F_159 () ;
F_501 (kvm, &vm_list, vm_list) {
F_184 (i, vcpu, kvm) {
if ( ! V_1285 && V_2 -> V_24 == F_10 () )
F_32 ( V_343 , V_2 ) ;
if ( V_1285 && V_2 -> V_5 . V_598 > V_1283 ) {
V_1286 = true ;
if ( V_2 -> V_5 . V_598 > V_1284 )
V_1284 = V_2 -> V_5 . V_598 ;
}
}
}
if ( V_1286 ) {
T_2 V_1288 = V_1284 - V_1283 ;
F_501 (kvm, &vm_list, vm_list) {
V_142 -> V_5 . V_339 = true ;
F_184 (i, vcpu, kvm) {
V_2 -> V_5 . V_596 += V_1288 ;
V_2 -> V_5 . V_598 = V_1283 ;
F_32 ( V_302 , V_2 ) ;
}
V_142 -> V_5 . V_317 = 0 ;
V_142 -> V_5 . V_319 = 0 ;
}
}
return 0 ;
}
void F_658 ( void )
{
V_90 -> V_1289 () ;
F_20 () ;
}
int F_659 ( void )
{
int V_124 ;
V_124 = V_90 -> V_1290 () ;
if ( V_124 != 0 )
return V_124 ;
if ( V_276 ) {
T_2 V_1291 = F_357 ( 0x7fffffffULL ,
F_148 ( V_281 , V_277 ) ) ;
V_730 = V_1291 ;
V_275 = 1ULL << V_280 ;
}
F_354 () ;
return 0 ;
}
void F_660 ( void )
{
V_90 -> V_1292 () ;
}
void F_661 ( void * V_1293 )
{
V_90 -> V_1294 ( V_1293 ) ;
}
bool F_662 ( struct V_1 * V_2 )
{
return V_2 -> V_142 -> V_5 . V_822 == V_2 -> V_303 ;
}
bool F_632 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_32 & V_1295 ) != 0 ;
}
int F_663 ( struct V_1 * V_2 )
{
struct V_389 * V_389 ;
struct V_142 * V_142 ;
int V_124 ;
F_15 ( V_2 -> V_142 == NULL ) ;
V_142 = V_2 -> V_142 ;
V_2 -> V_5 . V_604 = V_90 -> V_1296 () ;
V_2 -> V_5 . V_1178 . V_1179 = false ;
V_2 -> V_5 . V_870 . V_869 = & V_1297 ;
if ( ! F_280 ( V_142 ) || F_662 ( V_2 ) )
V_2 -> V_5 . V_654 = V_1180 ;
else
V_2 -> V_5 . V_654 = V_1192 ;
V_389 = F_664 ( V_703 | V_1298 ) ;
if ( ! V_389 ) {
V_124 = - V_391 ;
goto V_1299;
}
V_2 -> V_5 . V_903 = F_665 ( V_389 ) ;
F_141 ( V_2 , V_1032 ) ;
V_124 = F_666 ( V_2 ) ;
if ( V_124 < 0 )
goto V_1300;
if ( F_280 ( V_142 ) ) {
V_124 = F_667 ( V_2 ) ;
if ( V_124 < 0 )
goto V_1301;
} else
F_668 ( & V_1302 ) ;
V_2 -> V_5 . V_378 = F_313 ( V_445 * sizeof( T_2 ) * 4 ,
V_703 ) ;
if ( ! V_2 -> V_5 . V_378 ) {
V_124 = - V_391 ;
goto V_1303;
}
V_2 -> V_5 . V_370 = V_445 ;
if ( ! F_669 ( & V_2 -> V_5 . V_594 , V_703 ) ) {
V_124 = - V_391 ;
goto V_1304;
}
F_637 ( V_2 ) ;
V_2 -> V_5 . V_306 = 0x0 ;
V_2 -> V_5 . V_360 = false ;
V_2 -> V_5 . V_157 = 0 ;
V_2 -> V_5 . V_1305 = V_1306 + V_673 ;
V_2 -> V_5 . V_1043 = F_670 ( V_2 ) ;
V_2 -> V_5 . V_1307 = V_1308 ;
F_1 ( V_2 ) ;
F_671 ( V_2 ) ;
V_2 -> V_5 . V_609 = - 1 ;
F_672 ( V_2 ) ;
return 0 ;
V_1304:
F_214 ( V_2 -> V_5 . V_378 ) ;
V_1303:
F_673 ( V_2 ) ;
V_1301:
F_674 ( V_2 ) ;
V_1300:
F_675 ( ( unsigned long ) V_2 -> V_5 . V_903 ) ;
V_1299:
return V_124 ;
}
void F_676 ( struct V_1 * V_2 )
{
int V_498 ;
F_677 ( V_2 ) ;
F_678 ( V_2 ) ;
F_214 ( V_2 -> V_5 . V_378 ) ;
F_673 ( V_2 ) ;
V_498 = F_243 ( & V_2 -> V_142 -> V_499 ) ;
F_674 ( V_2 ) ;
F_244 ( & V_2 -> V_142 -> V_499 , V_498 ) ;
F_675 ( ( unsigned long ) V_2 -> V_5 . V_903 ) ;
if ( ! F_92 ( V_2 ) )
F_679 ( & V_1302 ) ;
}
void F_680 ( struct V_1 * V_2 , int V_24 )
{
V_90 -> V_1309 ( V_2 , V_24 ) ;
}
int F_681 ( struct V_142 * V_142 , unsigned long type )
{
if ( type )
return - V_591 ;
F_682 ( & V_142 -> V_5 . V_1310 ) ;
F_683 ( & V_142 -> V_5 . V_1311 ) ;
F_683 ( & V_142 -> V_5 . V_1312 ) ;
F_683 ( & V_142 -> V_5 . V_1313 ) ;
F_179 ( & V_142 -> V_5 . V_1314 , 0 ) ;
F_295 ( V_782 , & V_142 -> V_5 . V_1315 ) ;
F_295 ( V_1316 ,
& V_142 -> V_5 . V_1315 ) ;
F_684 ( & V_142 -> V_5 . V_316 ) ;
F_685 ( & V_142 -> V_5 . V_1317 ) ;
F_685 ( & V_142 -> V_5 . V_1156 . V_1318 ) ;
F_686 ( & V_142 -> V_5 . V_329 ) ;
V_142 -> V_5 . V_252 = - F_157 () ;
F_178 ( V_142 ) ;
F_687 ( & V_142 -> V_5 . V_365 , F_201 ) ;
F_687 ( & V_142 -> V_5 . V_367 , F_206 ) ;
F_688 ( V_142 ) ;
F_689 ( V_142 ) ;
if ( V_90 -> V_1319 )
return V_90 -> V_1319 ( V_142 ) ;
return 0 ;
}
static void F_690 ( struct V_1 * V_2 )
{
int V_124 ;
V_124 = V_595 ( V_2 ) ;
F_15 ( V_124 ) ;
F_582 ( V_2 ) ;
V_600 ( V_2 ) ;
}
static void F_691 ( struct V_142 * V_142 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_184 (i, vcpu, kvm) {
F_67 ( V_2 ) ;
F_690 ( V_2 ) ;
}
F_184 (i, vcpu, kvm)
F_644 ( V_2 ) ;
F_322 ( & V_142 -> V_757 ) ;
for ( V_3 = 0 ; V_3 < F_145 ( & V_142 -> V_299 ) ; V_3 ++ )
V_142 -> V_1320 [ V_3 ] = NULL ;
F_179 ( & V_142 -> V_299 , 0 ) ;
F_324 ( & V_142 -> V_757 ) ;
}
void F_692 ( struct V_142 * V_142 )
{
F_693 ( & V_142 -> V_5 . V_367 ) ;
F_693 ( & V_142 -> V_5 . V_365 ) ;
F_694 ( V_142 ) ;
}
int F_695 ( struct V_142 * V_142 , int V_1277 , T_6 V_393 , T_1 V_504 )
{
int V_3 , V_124 ;
unsigned long V_1321 ;
struct V_1322 * V_1323 = V_1322 ( V_142 ) ;
struct V_1324 * V_10 , V_890 ;
if ( F_30 ( V_1277 >= V_1325 ) )
return - V_591 ;
V_10 = F_696 ( V_1323 , V_1277 ) ;
if ( V_504 ) {
if ( V_10 -> V_1326 )
return - V_610 ;
V_1321 = F_697 ( NULL , 0 , V_504 , V_1327 | V_1328 ,
V_1329 | V_1330 , 0 ) ;
if ( F_211 ( ( void * ) V_1321 ) )
return F_212 ( ( void * ) V_1321 ) ;
} else {
if ( ! V_10 -> V_1326 )
return 0 ;
V_1321 = 0 ;
}
V_890 = * V_10 ;
for ( V_3 = 0 ; V_3 < V_1331 ; V_3 ++ ) {
struct V_1332 V_1333 ;
V_1333 . V_10 = V_1277 | ( V_3 << 16 ) ;
V_1333 . V_15 = 0 ;
V_1333 . V_1334 = V_393 ;
V_1333 . V_1335 = V_1321 ;
V_1333 . V_1336 = V_504 ;
V_124 = F_698 ( V_142 , & V_1333 ) ;
if ( V_124 < 0 )
return V_124 ;
}
if ( ! V_504 ) {
V_124 = F_699 ( V_890 . V_1335 , V_890 . V_1326 * V_110 ) ;
F_30 ( V_124 < 0 ) ;
}
return 0 ;
}
int F_700 ( struct V_142 * V_142 , int V_1277 , T_6 V_393 , T_1 V_504 )
{
int V_124 ;
F_322 ( & V_142 -> V_742 ) ;
V_124 = F_695 ( V_142 , V_1277 , V_393 , V_504 ) ;
F_324 ( & V_142 -> V_742 ) ;
return V_124 ;
}
void F_701 ( struct V_142 * V_142 )
{
if ( V_406 -> V_1337 == V_142 -> V_1337 ) {
F_700 ( V_142 , V_1338 , 0 , 0 ) ;
F_700 ( V_142 , V_1339 , 0 , 0 ) ;
F_700 ( V_142 , V_1340 , 0 , 0 ) ;
}
if ( V_90 -> V_1341 )
V_90 -> V_1341 ( V_142 ) ;
F_349 ( V_142 ) ;
F_351 ( V_142 ) ;
F_691 ( V_142 ) ;
F_702 ( F_703 ( V_142 -> V_5 . V_1342 , 1 ) ) ;
F_704 ( V_142 ) ;
F_705 ( V_142 ) ;
}
void F_706 ( struct V_142 * V_142 , struct V_1324 * free ,
struct V_1324 * V_1343 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1344 ; ++ V_3 ) {
if ( ! V_1343 || free -> V_5 . V_1345 [ V_3 ] != V_1343 -> V_5 . V_1345 [ V_3 ] ) {
F_702 ( free -> V_5 . V_1345 [ V_3 ] ) ;
free -> V_5 . V_1345 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1343 || free -> V_5 . V_1346 [ V_3 - 1 ] !=
V_1343 -> V_5 . V_1346 [ V_3 - 1 ] ) {
F_702 ( free -> V_5 . V_1346 [ V_3 - 1 ] ) ;
free -> V_5 . V_1346 [ V_3 - 1 ] = NULL ;
}
}
F_707 ( free , V_1343 ) ;
}
int F_708 ( struct V_142 * V_142 , struct V_1324 * V_10 ,
unsigned long V_1326 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1344 ; ++ V_3 ) {
struct V_1347 * V_1348 ;
unsigned long V_1349 ;
int V_1350 ;
int V_783 = V_3 + 1 ;
V_1350 = F_709 ( V_10 -> V_1351 + V_1326 - 1 ,
V_10 -> V_1351 , V_783 ) + 1 ;
V_10 -> V_5 . V_1345 [ V_3 ] =
F_710 ( V_1350 * sizeof( * V_10 -> V_5 . V_1345 [ V_3 ] ) , V_703 ) ;
if ( ! V_10 -> V_5 . V_1345 [ V_3 ] )
goto V_392;
if ( V_3 == 0 )
continue;
V_1348 = F_710 ( V_1350 * sizeof( * V_1348 ) , V_703 ) ;
if ( ! V_1348 )
goto V_392;
V_10 -> V_5 . V_1346 [ V_3 - 1 ] = V_1348 ;
if ( V_10 -> V_1351 & ( F_711 ( V_783 ) - 1 ) )
V_1348 [ 0 ] . V_1352 = 1 ;
if ( ( V_10 -> V_1351 + V_1326 ) & ( F_711 ( V_783 ) - 1 ) )
V_1348 [ V_1350 - 1 ] . V_1352 = 1 ;
V_1349 = V_10 -> V_1335 >> V_109 ;
if ( ( V_10 -> V_1351 ^ V_1349 ) & ( F_711 ( V_783 ) - 1 ) ||
! F_712 () ) {
unsigned long V_831 ;
for ( V_831 = 0 ; V_831 < V_1350 ; ++ V_831 )
V_1348 [ V_831 ] . V_1352 = 1 ;
}
}
if ( F_713 ( V_10 , V_1326 ) )
goto V_392;
return 0 ;
V_392:
for ( V_3 = 0 ; V_3 < V_1344 ; ++ V_3 ) {
F_702 ( V_10 -> V_5 . V_1345 [ V_3 ] ) ;
V_10 -> V_5 . V_1345 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_702 ( V_10 -> V_5 . V_1346 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1346 [ V_3 - 1 ] = NULL ;
}
return - V_391 ;
}
void F_714 ( struct V_142 * V_142 , struct V_1322 * V_1323 )
{
F_715 ( V_142 , V_1323 ) ;
}
int F_716 ( struct V_142 * V_142 ,
struct V_1324 * V_1353 ,
const struct V_1332 * V_1354 ,
enum V_1355 V_1356 )
{
return 0 ;
}
static void F_717 ( struct V_142 * V_142 ,
struct V_1324 * V_891 )
{
if ( V_891 -> V_15 & V_1357 ) {
F_718 ( V_142 , V_891 ) ;
return;
}
if ( V_891 -> V_15 & V_1358 ) {
if ( V_90 -> V_1359 )
V_90 -> V_1359 ( V_142 , V_891 ) ;
else
F_718 ( V_142 , V_891 ) ;
} else {
if ( V_90 -> V_1360 )
V_90 -> V_1360 ( V_142 , V_891 ) ;
}
}
void F_719 ( struct V_142 * V_142 ,
const struct V_1332 * V_1354 ,
const struct V_1324 * V_890 ,
const struct V_1324 * V_891 ,
enum V_1355 V_1356 )
{
int V_1361 = 0 ;
if ( ! V_142 -> V_5 . V_743 )
V_1361 = F_720 ( V_142 ) ;
if ( V_1361 )
F_323 ( V_142 , V_1361 ) ;
if ( ( V_1356 != V_1362 ) &&
( V_890 -> V_15 & V_1358 ) &&
! ( V_891 -> V_15 & V_1358 ) )
F_721 ( V_142 , V_891 ) ;
if ( V_1356 != V_1362 )
F_717 ( V_142 , (struct V_1324 * ) V_891 ) ;
}
void F_722 ( struct V_142 * V_142 )
{
F_723 ( V_142 ) ;
}
void F_724 ( struct V_142 * V_142 ,
struct V_1324 * V_10 )
{
F_725 ( V_142 , V_10 ) ;
}
static inline bool F_726 ( struct V_1 * V_2 )
{
if ( ! F_727 ( & V_2 -> V_1363 . V_1364 ) )
return true ;
if ( F_728 ( V_2 ) )
return true ;
if ( V_2 -> V_5 . V_1178 . V_1179 )
return true ;
if ( F_729 ( V_88 , V_2 ) ||
( V_2 -> V_5 . V_638 &&
V_90 -> V_1110 ( V_2 ) ) )
return true ;
if ( F_729 ( V_611 , V_2 ) ||
( V_2 -> V_5 . V_644 && ! F_291 ( V_2 ) ) )
return true ;
if ( F_276 ( V_2 ) &&
F_277 ( V_2 ) )
return true ;
if ( F_730 ( V_2 ) )
return true ;
return false ;
}
int F_607 ( struct V_1 * V_2 )
{
return F_609 ( V_2 ) || F_726 ( V_2 ) ;
}
int F_731 ( struct V_1 * V_2 )
{
return F_732 ( V_2 ) == V_1163 ;
}
int F_276 ( struct V_1 * V_2 )
{
return V_90 -> V_1111 ( V_2 ) ;
}
unsigned long F_484 ( struct V_1 * V_2 )
{
if ( F_545 ( V_2 ) )
return F_464 ( V_2 ) ;
return ( T_1 ) ( F_414 ( V_2 , V_1120 ) +
F_464 ( V_2 ) ) ;
}
bool F_733 ( struct V_1 * V_2 , unsigned long V_1365 )
{
return F_484 ( V_2 ) == V_1365 ;
}
unsigned long F_463 ( struct V_1 * V_2 )
{
unsigned long V_998 ;
V_998 = V_90 -> V_999 ( V_2 ) ;
if ( V_2 -> V_182 & V_991 )
V_998 &= ~ V_954 ;
return V_998 ;
}
static void F_491 ( struct V_1 * V_2 , unsigned long V_998 )
{
if ( V_2 -> V_182 & V_991 &&
F_733 ( V_2 , V_2 -> V_5 . V_995 ) )
V_998 |= V_954 ;
V_90 -> V_1366 ( V_2 , V_998 ) ;
}
void F_469 ( struct V_1 * V_2 , unsigned long V_998 )
{
F_491 ( V_2 , V_998 ) ;
F_32 ( V_68 , V_2 ) ;
}
void F_734 ( struct V_1 * V_2 , struct V_1367 * V_362 )
{
int V_124 ;
if ( ( V_2 -> V_5 . V_86 . V_982 != V_362 -> V_5 . V_982 ) ||
V_362 -> V_1368 )
return;
V_124 = F_590 ( V_2 ) ;
if ( F_172 ( V_124 ) )
return;
if ( ! V_2 -> V_5 . V_86 . V_982 &&
V_362 -> V_5 . V_107 != V_2 -> V_5 . V_86 . V_1369 ( V_2 ) )
return;
V_2 -> V_5 . V_86 . V_1370 ( V_2 , V_362 -> V_847 , 0 , true ) ;
}
static inline T_1 F_735 ( T_5 V_105 )
{
return F_736 ( V_105 & 0xffffffff , F_737 ( V_4 ) ) ;
}
static inline T_1 F_738 ( T_1 V_1371 )
{
return ( V_1371 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_739 ( struct V_1 * V_2 , T_5 V_105 )
{
T_1 V_1371 = F_735 ( V_105 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1371 ] != ~ 0 )
V_1371 = F_738 ( V_1371 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1371 ] = V_105 ;
}
static T_1 F_740 ( struct V_1 * V_2 , T_5 V_105 )
{
int V_3 ;
T_1 V_1371 = F_735 ( V_105 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1371 ] != V_105 &&
V_2 -> V_5 . V_6 . V_7 [ V_1371 ] != ~ 0 ) ; V_3 ++ )
V_1371 = F_738 ( V_1371 ) ;
return V_1371 ;
}
bool F_741 ( struct V_1 * V_2 , T_5 V_105 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_740 ( V_2 , V_105 ) ] == V_105 ;
}
static void F_742 ( struct V_1 * V_2 , T_5 V_105 )
{
T_1 V_3 , V_831 , V_1372 ;
V_3 = V_831 = F_740 ( V_2 , V_105 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_831 = F_738 ( V_831 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_831 ] == ~ 0 )
return;
V_1372 = F_735 ( V_2 -> V_5 . V_6 . V_7 [ V_831 ] ) ;
} while ( ( V_3 <= V_831 ) ? ( V_3 < V_1372 && V_1372 <= V_831 ) : ( V_3 < V_1372 || V_1372 <= V_831 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_831 ] ;
V_3 = V_831 ;
}
}
static int F_743 ( struct V_1 * V_2 , T_1 V_199 )
{
return F_195 ( V_2 -> V_142 , & V_2 -> V_5 . V_6 . V_39 , & V_199 ,
sizeof( V_199 ) ) ;
}
void F_744 ( struct V_1 * V_2 ,
struct V_1367 * V_362 )
{
struct V_74 V_75 ;
F_745 ( V_362 -> V_5 . V_1373 , V_362 -> V_847 ) ;
F_739 ( V_2 , V_362 -> V_5 . V_105 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_394 & V_395 ) ||
( V_2 -> V_5 . V_6 . V_396 &&
V_90 -> V_91 ( V_2 ) == 0 ) )
F_32 ( V_1139 , V_2 ) ;
else if ( ! F_743 ( V_2 , V_1374 ) ) {
V_75 . V_42 = V_43 ;
V_75 . V_951 = true ;
V_75 . V_63 = 0 ;
V_75 . V_83 = false ;
V_75 . V_81 = V_362 -> V_5 . V_1373 ;
V_75 . V_79 = true ;
F_39 ( V_2 , & V_75 ) ;
}
}
void F_746 ( struct V_1 * V_2 ,
struct V_1367 * V_362 )
{
struct V_74 V_75 ;
if ( V_362 -> V_1368 )
V_362 -> V_5 . V_1373 = ~ 0 ;
else
F_742 ( V_2 , V_362 -> V_5 . V_105 ) ;
F_747 ( V_362 -> V_5 . V_1373 , V_362 -> V_847 ) ;
if ( ( V_2 -> V_5 . V_6 . V_394 & V_395 ) &&
! F_743 ( V_2 , V_1375 ) ) {
V_75 . V_42 = V_43 ;
V_75 . V_951 = true ;
V_75 . V_63 = 0 ;
V_75 . V_83 = false ;
V_75 . V_81 = V_362 -> V_5 . V_1373 ;
V_75 . V_79 = true ;
F_39 ( V_2 , & V_75 ) ;
}
V_2 -> V_5 . V_6 . V_1140 = false ;
V_2 -> V_5 . V_654 = V_1180 ;
}
bool F_748 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_394 & V_395 ) )
return true ;
else
return F_749 ( V_2 ) ;
}
void F_750 ( struct V_142 * V_142 )
{
F_45 ( & V_142 -> V_5 . V_1376 ) ;
}
void F_751 ( struct V_142 * V_142 )
{
F_752 ( & V_142 -> V_5 . V_1376 ) ;
}
bool F_753 ( struct V_142 * V_142 )
{
return F_145 ( & V_142 -> V_5 . V_1376 ) ;
}
void F_754 ( struct V_142 * V_142 )
{
F_45 ( & V_142 -> V_5 . V_1314 ) ;
}
void F_755 ( struct V_142 * V_142 )
{
F_752 ( & V_142 -> V_5 . V_1314 ) ;
}
bool F_69 ( struct V_142 * V_142 )
{
return F_145 ( & V_142 -> V_5 . V_1314 ) ;
}
bool F_756 ( void )
{
return V_90 -> V_1377 != NULL ;
}
int F_757 ( struct V_1378 * V_1379 ,
struct V_1380 * V_1381 )
{
struct V_1382 * V_1383 =
F_4 ( V_1379 , struct V_1382 , V_1384 ) ;
V_1383 -> V_1385 = V_1381 ;
return V_90 -> V_1377 ( V_1383 -> V_142 ,
V_1381 -> V_606 , V_1383 -> V_1386 , 1 ) ;
}
void F_758 ( struct V_1378 * V_1379 ,
struct V_1380 * V_1381 )
{
int V_111 ;
struct V_1382 * V_1383 =
F_4 ( V_1379 , struct V_1382 , V_1384 ) ;
F_30 ( V_1383 -> V_1385 != V_1381 ) ;
V_1383 -> V_1385 = NULL ;
V_111 = V_90 -> V_1377 ( V_1383 -> V_142 , V_1381 -> V_606 , V_1383 -> V_1386 , 0 ) ;
if ( V_111 )
F_12 ( V_1387 L_31
L_32 , V_1383 -> V_1384 . V_1373 , V_111 ) ;
}
int F_759 ( struct V_142 * V_142 , unsigned int V_1388 ,
T_7 V_1389 , bool V_1390 )
{
if ( ! V_90 -> V_1377 )
return - V_591 ;
return V_90 -> V_1377 ( V_142 , V_1388 , V_1389 , V_1390 ) ;
}
bool F_760 ( void )
{
return V_1391 ;
}
