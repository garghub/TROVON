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
V_2 -> V_5 . V_78 = V_75 -> V_79 ;
F_40 ( V_2 , V_43 , V_75 -> V_63 ) ;
}
static bool F_41 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
if ( F_42 ( V_2 ) && ! V_75 -> V_80 )
V_2 -> V_5 . V_81 . V_82 ( V_2 , V_75 ) ;
else
V_2 -> V_5 . V_83 . V_82 ( V_2 , V_75 ) ;
return V_75 -> V_80 ;
}
void F_43 ( struct V_1 * V_2 )
{
F_44 ( & V_2 -> V_5 . V_84 ) ;
F_32 ( V_85 , V_2 ) ;
}
void F_40 ( struct V_1 * V_2 , unsigned V_18 , T_1 V_63 )
{
F_31 ( V_2 , V_18 , true , V_63 , false ) ;
}
void F_45 ( struct V_1 * V_2 , unsigned V_18 , T_1 V_63 )
{
F_31 ( V_2 , V_18 , true , V_63 , true ) ;
}
bool F_46 ( struct V_1 * V_2 , int V_86 )
{
if ( V_87 -> V_88 ( V_2 ) <= V_86 )
return true ;
F_40 ( V_2 , V_49 , 0 ) ;
return false ;
}
bool F_47 ( struct V_1 * V_2 , int V_89 )
{
if ( ( V_89 != 4 && V_89 != 5 ) || ! F_48 ( V_2 , V_90 ) )
return true ;
F_34 ( V_2 , V_91 ) ;
return false ;
}
int F_49 ( struct V_1 * V_2 , struct V_92 * V_83 ,
T_5 V_93 , void * V_39 , int V_94 , int V_95 ,
T_1 V_96 )
{
struct V_74 V_69 ;
T_5 V_97 ;
T_6 V_98 ;
V_98 = F_50 ( V_93 ) ;
V_97 = V_83 -> V_99 ( V_2 , V_98 , V_96 , & V_69 ) ;
if ( V_97 == V_100 )
return - V_101 ;
V_97 = F_51 ( V_97 ) ;
return F_52 ( V_2 , V_97 , V_39 , V_94 , V_95 ) ;
}
static int F_53 ( struct V_1 * V_2 , T_5 V_102 ,
void * V_39 , int V_94 , int V_95 , T_1 V_96 )
{
return F_49 ( V_2 , V_2 -> V_5 . V_103 , V_102 ,
V_39 , V_94 , V_95 , V_96 ) ;
}
int F_54 ( struct V_1 * V_2 , struct V_92 * V_83 , unsigned long V_104 )
{
T_5 V_105 = V_104 >> V_106 ;
unsigned V_94 = ( ( V_104 & ( V_107 - 1 ) ) >> 5 ) << 2 ;
int V_3 ;
int V_108 ;
T_2 V_109 [ F_55 ( V_83 -> V_110 ) ] ;
V_108 = F_49 ( V_2 , V_83 , V_105 , V_109 ,
V_94 * sizeof( T_2 ) , sizeof( V_109 ) ,
V_111 | V_112 ) ;
if ( V_108 < 0 ) {
V_108 = 0 ;
goto V_113;
}
for ( V_3 = 0 ; V_3 < F_55 ( V_109 ) ; ++ V_3 ) {
if ( ( V_109 [ V_3 ] & V_114 ) &&
( V_109 [ V_3 ] &
V_2 -> V_5 . V_83 . V_115 . V_116 [ 0 ] [ 2 ] ) ) {
V_108 = 0 ;
goto V_113;
}
}
V_108 = 1 ;
memcpy ( V_83 -> V_110 , V_109 , sizeof( V_83 -> V_110 ) ) ;
F_56 ( V_117 ,
( unsigned long * ) & V_2 -> V_5 . V_118 ) ;
F_56 ( V_117 ,
( unsigned long * ) & V_2 -> V_5 . V_119 ) ;
V_113:
return V_108 ;
}
bool F_57 ( struct V_1 * V_2 )
{
T_2 V_109 [ F_55 ( V_2 -> V_5 . V_103 -> V_110 ) ] ;
bool V_120 = true ;
int V_94 ;
T_5 V_102 ;
int V_121 ;
if ( F_58 ( V_2 ) || ! F_59 ( V_2 ) )
return false ;
if ( ! F_60 ( V_117 ,
( unsigned long * ) & V_2 -> V_5 . V_118 ) )
return true ;
V_102 = ( F_61 ( V_2 ) & ~ 31u ) >> V_106 ;
V_94 = ( F_61 ( V_2 ) & ~ 31u ) & ( V_107 - 1 ) ;
V_121 = F_53 ( V_2 , V_102 , V_109 , V_94 , sizeof( V_109 ) ,
V_111 | V_112 ) ;
if ( V_121 < 0 )
goto V_113;
V_120 = memcmp ( V_109 , V_2 -> V_5 . V_103 -> V_110 , sizeof( V_109 ) ) != 0 ;
V_113:
return V_120 ;
}
int F_62 ( struct V_1 * V_2 , unsigned long V_122 )
{
unsigned long V_123 = F_63 ( V_2 ) ;
unsigned long V_124 = V_125 | V_126 ;
V_122 |= V_127 ;
#ifdef F_64
if ( V_122 & 0xffffffff00000000UL )
return 1 ;
#endif
V_122 &= ~ V_128 ;
if ( ( V_122 & V_129 ) && ! ( V_122 & V_130 ) )
return 1 ;
if ( ( V_122 & V_125 ) && ! ( V_122 & V_131 ) )
return 1 ;
if ( ! F_65 ( V_2 ) && ( V_122 & V_125 ) ) {
#ifdef F_64
if ( ( V_2 -> V_5 . V_132 & V_133 ) ) {
int V_134 , V_135 ;
if ( ! F_59 ( V_2 ) )
return 1 ;
V_87 -> V_136 ( V_2 , & V_134 , & V_135 ) ;
if ( V_135 )
return 1 ;
} else
#endif
if ( F_59 ( V_2 ) && ! F_54 ( V_2 , V_2 -> V_5 . V_103 ,
F_61 ( V_2 ) ) )
return 1 ;
}
if ( ! ( V_122 & V_125 ) && F_48 ( V_2 , V_137 ) )
return 1 ;
V_87 -> V_138 ( V_2 , V_122 ) ;
if ( ( V_122 ^ V_123 ) & V_125 ) {
F_66 ( V_2 ) ;
F_1 ( V_2 ) ;
}
if ( ( V_122 ^ V_123 ) & V_124 )
F_67 ( V_2 ) ;
if ( ( ( V_122 ^ V_123 ) & V_130 ) &&
F_68 ( V_2 -> V_139 ) &&
! F_69 ( V_2 -> V_139 , V_140 ) )
F_70 ( V_2 -> V_139 , 0 , ~ 0ULL ) ;
return 0 ;
}
void F_71 ( struct V_1 * V_2 , unsigned long V_141 )
{
( void ) F_62 ( V_2 , F_72 ( V_2 , ~ 0x0eul ) | ( V_141 & 0x0f ) ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
if ( F_48 ( V_2 , V_142 ) &&
! V_2 -> V_143 ) {
F_74 ( V_144 , V_2 -> V_5 . V_145 ) ;
V_2 -> V_143 = 1 ;
}
}
static void F_75 ( struct V_1 * V_2 )
{
if ( V_2 -> V_143 ) {
if ( V_2 -> V_5 . V_145 != V_146 )
F_74 ( V_144 , V_146 ) ;
V_2 -> V_143 = 0 ;
}
}
static int F_76 ( struct V_1 * V_2 , T_1 V_147 , T_2 V_148 )
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
F_77 ( V_2 ) ;
return 0 ;
}
int F_78 ( struct V_1 * V_2 , T_1 V_147 , T_2 V_148 )
{
if ( V_87 -> V_88 ( V_2 ) != 0 ||
F_76 ( V_2 , V_147 , V_148 ) ) {
F_37 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_79 ( struct V_1 * V_2 , unsigned long V_159 )
{
unsigned long V_160 = F_80 ( V_2 ) ;
unsigned long V_161 = V_162 | V_163 | V_164 |
V_165 | V_166 | V_167 ;
if ( V_159 & V_168 )
return 1 ;
if ( ! F_81 ( V_2 ) && ( V_159 & V_142 ) )
return 1 ;
if ( ! F_82 ( V_2 ) && ( V_159 & V_165 ) )
return 1 ;
if ( ! F_83 ( V_2 ) && ( V_159 & V_166 ) )
return 1 ;
if ( ! F_84 ( V_2 ) && ( V_159 & V_169 ) )
return 1 ;
if ( ! F_85 ( V_2 ) && ( V_159 & V_167 ) )
return 1 ;
if ( F_58 ( V_2 ) ) {
if ( ! ( V_159 & V_164 ) )
return 1 ;
} else if ( F_65 ( V_2 ) && ( V_159 & V_164 )
&& ( ( V_159 ^ V_160 ) & V_161 )
&& ! F_54 ( V_2 , V_2 -> V_5 . V_103 ,
F_61 ( V_2 ) ) )
return 1 ;
if ( ( V_159 & V_137 ) && ! ( V_160 & V_137 ) ) {
if ( ! F_86 ( V_2 ) )
return 1 ;
if ( ( F_61 ( V_2 ) & V_170 ) || ! F_58 ( V_2 ) )
return 1 ;
}
if ( V_87 -> V_171 ( V_2 , V_159 ) )
return 1 ;
if ( ( ( V_159 ^ V_160 ) & V_161 ) ||
( ! ( V_159 & V_137 ) && ( V_160 & V_137 ) ) )
F_67 ( V_2 ) ;
if ( ( V_159 ^ V_160 ) & ( V_142 | V_167 ) )
F_77 ( V_2 ) ;
return 0 ;
}
int F_87 ( struct V_1 * V_2 , unsigned long V_104 )
{
#ifdef F_64
V_104 &= ~ V_172 ;
#endif
if ( V_104 == F_61 ( V_2 ) && ! F_57 ( V_2 ) ) {
F_88 ( V_2 ) ;
F_32 ( V_173 , V_2 ) ;
return 0 ;
}
if ( F_58 ( V_2 ) ) {
if ( V_104 & V_174 )
return 1 ;
} else if ( F_59 ( V_2 ) && F_65 ( V_2 ) &&
! F_54 ( V_2 , V_2 -> V_5 . V_103 , V_104 ) )
return 1 ;
V_2 -> V_5 . V_104 = V_104 ;
F_56 ( V_175 , ( V_176 * ) & V_2 -> V_5 . V_118 ) ;
F_89 ( V_2 ) ;
return 0 ;
}
int F_90 ( struct V_1 * V_2 , unsigned long V_177 )
{
if ( V_177 & V_178 )
return 1 ;
if ( F_91 ( V_2 ) )
F_92 ( V_2 , V_177 ) ;
else
V_2 -> V_5 . V_177 = V_177 ;
return 0 ;
}
unsigned long F_93 ( struct V_1 * V_2 )
{
if ( F_91 ( V_2 ) )
return F_94 ( V_2 ) ;
else
return V_2 -> V_5 . V_177 ;
}
static void F_95 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! ( V_2 -> V_179 & V_180 ) ) {
for ( V_3 = 0 ; V_3 < V_181 ; V_3 ++ )
V_2 -> V_5 . V_182 [ V_3 ] = V_2 -> V_5 . V_183 [ V_3 ] ;
V_2 -> V_5 . V_184 |= V_185 ;
}
}
static void F_96 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_179 & V_180 ) )
V_87 -> V_186 ( V_2 , V_2 -> V_5 . V_187 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
unsigned long V_188 ;
if ( V_2 -> V_179 & V_180 )
V_188 = V_2 -> V_5 . V_189 ;
else
V_188 = V_2 -> V_5 . V_188 ;
V_87 -> V_190 ( V_2 , V_188 ) ;
V_2 -> V_5 . V_184 &= ~ V_191 ;
if ( V_188 & V_192 )
V_2 -> V_5 . V_184 |= V_191 ;
}
static T_2 F_98 ( struct V_1 * V_2 )
{
T_2 V_193 = V_194 ;
if ( ! F_99 ( V_2 ) )
V_193 |= V_195 ;
return V_193 ;
}
static int F_100 ( struct V_1 * V_2 , int V_89 , unsigned long V_196 )
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
V_2 -> V_5 . V_187 = ( V_196 & V_197 ) | F_98 ( V_2 ) ;
F_96 ( V_2 ) ;
break;
case 5 :
default:
if ( V_196 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_188 = ( V_196 & V_198 ) | V_199 ;
F_97 ( V_2 ) ;
break;
}
return 0 ;
}
int F_101 ( struct V_1 * V_2 , int V_89 , unsigned long V_196 )
{
if ( F_100 ( V_2 , V_89 , V_196 ) ) {
F_37 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_102 ( struct V_1 * V_2 , int V_89 , unsigned long * V_196 )
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
* V_196 = V_87 -> V_200 ( V_2 ) ;
break;
case 5 :
default:
* V_196 = V_2 -> V_5 . V_188 ;
break;
}
return 0 ;
}
bool F_103 ( struct V_1 * V_2 )
{
T_1 V_201 = F_104 ( V_2 , V_202 ) ;
T_2 V_39 ;
int V_30 ;
V_30 = F_105 ( V_2 , V_201 , & V_39 ) ;
if ( V_30 )
return V_30 ;
F_106 ( V_2 , V_203 , ( T_1 ) V_39 ) ;
F_106 ( V_2 , V_204 , V_39 >> 32 ) ;
return V_30 ;
}
bool F_107 ( struct V_1 * V_2 , T_2 V_132 )
{
if ( V_132 & V_205 )
return false ;
if ( V_132 & V_206 ) {
struct V_207 * V_208 ;
V_208 = F_108 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_208 || ! ( V_208 -> V_209 & F_109 ( V_210 ) ) )
return false ;
}
if ( V_132 & V_211 ) {
struct V_207 * V_208 ;
V_208 = F_108 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_208 || ! ( V_208 -> V_201 & F_109 ( V_212 ) ) )
return false ;
}
return true ;
}
static int F_110 ( struct V_1 * V_2 , T_2 V_132 )
{
T_2 V_213 = V_2 -> V_5 . V_132 ;
if ( ! F_107 ( V_2 , V_132 ) )
return 1 ;
if ( F_65 ( V_2 )
&& ( V_2 -> V_5 . V_132 & V_133 ) != ( V_132 & V_133 ) )
return 1 ;
V_132 &= ~ V_214 ;
V_132 |= V_2 -> V_5 . V_132 & V_214 ;
V_87 -> F_110 ( V_2 , V_132 ) ;
if ( ( V_132 ^ V_213 ) & V_215 )
F_67 ( V_2 ) ;
return 0 ;
}
void F_111 ( T_2 V_29 )
{
V_205 &= ~ V_29 ;
}
int F_112 ( struct V_1 * V_2 , struct V_33 * V_22 )
{
switch ( V_22 -> V_147 ) {
case V_216 :
case V_217 :
case V_218 :
case V_219 :
case V_220 :
if ( F_113 ( V_22 -> V_39 ) )
return 1 ;
break;
case V_221 :
case V_222 :
V_22 -> V_39 = F_114 ( V_22 -> V_39 ) ;
}
return V_87 -> V_223 ( V_2 , V_22 ) ;
}
static int F_115 ( struct V_1 * V_2 , unsigned V_147 , T_2 * V_39 )
{
struct V_33 V_22 ;
int V_121 ;
V_22 . V_147 = V_147 ;
V_22 . V_41 = true ;
V_121 = F_116 ( V_2 , & V_22 ) ;
if ( V_121 )
return V_121 ;
* V_39 = V_22 . V_39 ;
return 0 ;
}
static int F_117 ( struct V_1 * V_2 , unsigned V_147 , T_2 * V_39 )
{
struct V_33 V_22 ;
V_22 . V_39 = * V_39 ;
V_22 . V_147 = V_147 ;
V_22 . V_41 = true ;
return F_112 ( V_2 , & V_22 ) ;
}
static void F_118 ( struct V_224 * V_225 )
{
struct V_226 * V_227 = & V_226 ;
T_2 V_228 ;
V_228 = F_119 ( F_120 ( V_225 -> V_229 . V_230 , V_225 -> V_231 ) ) ;
F_121 ( & V_227 -> V_232 ) ;
V_227 -> clock . V_233 = V_225 -> V_229 . clock -> V_234 . V_233 ;
V_227 -> clock . V_235 = V_225 -> V_229 . V_235 ;
V_227 -> clock . V_29 = V_225 -> V_229 . V_29 ;
V_227 -> clock . V_236 = V_225 -> V_229 . V_236 ;
V_227 -> clock . V_237 = V_225 -> V_229 . V_237 ;
V_227 -> V_228 = V_228 ;
V_227 -> V_238 = V_225 -> V_229 . V_239 ;
F_122 ( & V_227 -> V_232 ) ;
}
void F_123 ( struct V_1 * V_2 )
{
F_32 ( V_240 , V_2 ) ;
}
static void F_124 ( struct V_139 * V_139 , T_6 V_241 )
{
int V_242 ;
int V_121 ;
struct V_243 V_244 ;
struct V_245 V_246 ;
if ( ! V_241 )
return;
V_121 = F_125 ( V_139 , V_241 , & V_242 , sizeof( V_242 ) ) ;
if ( V_121 )
return;
if ( V_242 & 1 )
++ V_242 ;
++ V_242 ;
if ( F_126 ( V_139 , V_241 , & V_242 , sizeof( V_242 ) ) )
return;
F_127 ( & V_246 ) ;
if ( V_139 -> V_5 . V_247 ) {
struct V_245 V_248 = F_128 ( V_139 -> V_5 . V_247 ) ;
V_246 = F_129 ( V_246 , V_248 ) ;
}
V_244 . V_249 = ( T_1 ) V_246 . V_250 ;
V_244 . V_251 = V_246 . V_252 ;
V_244 . V_242 = V_242 ;
F_126 ( V_139 , V_241 , & V_244 , sizeof( V_244 ) ) ;
V_242 ++ ;
F_126 ( V_139 , V_241 , & V_242 , sizeof( V_242 ) ) ;
}
static T_7 F_130 ( T_7 V_253 , T_7 V_254 )
{
F_131 ( V_253 , V_254 ) ;
return V_253 ;
}
static void F_132 ( T_8 V_255 , T_8 V_256 ,
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
* V_258 = F_130 ( V_259 , V_261 ) ;
F_133 ( L_2 ,
V_262 , V_256 , V_255 , V_237 , * V_258 ) ;
}
static T_1 F_134 ( T_1 V_263 , T_11 V_264 )
{
T_2 V_265 = ( T_2 ) V_263 * ( 1000000 + V_264 ) ;
F_135 ( V_265 , 1000000 ) ;
return V_265 ;
}
static int F_136 ( struct V_1 * V_2 , T_1 V_266 , bool V_267 )
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
F_137 ( 1 , L_3 ) ;
return - 1 ;
}
}
V_268 = F_138 ( 1ULL << V_275 ,
V_266 , V_272 ) ;
if ( V_268 == 0 || V_268 >= V_276 ) {
F_139 ( 1 , L_4 ,
V_266 ) ;
return - 1 ;
}
V_2 -> V_5 . V_269 = V_268 ;
return 0 ;
}
static int F_140 ( struct V_1 * V_2 , T_1 V_266 )
{
T_1 V_277 , V_278 ;
int V_279 = 0 ;
if ( V_266 == 0 ) {
V_2 -> V_5 . V_269 = V_270 ;
return - 1 ;
}
F_132 ( V_266 * 1000LL , V_280 ,
& V_2 -> V_5 . V_281 ,
& V_2 -> V_5 . V_282 ) ;
V_2 -> V_5 . V_283 = V_266 ;
V_277 = F_134 ( V_272 , - V_284 ) ;
V_278 = F_134 ( V_272 , V_284 ) ;
if ( V_266 < V_277 || V_266 > V_278 ) {
F_133 ( L_5 , V_266 , V_277 , V_278 ) ;
V_279 = 1 ;
}
return F_136 ( V_2 , V_266 , V_279 ) ;
}
static T_2 F_141 ( struct V_1 * V_2 , T_12 V_285 )
{
T_2 V_286 = F_142 ( V_285 - V_2 -> V_5 . V_287 ,
V_2 -> V_5 . V_282 ,
V_2 -> V_5 . V_281 ) ;
V_286 += V_2 -> V_5 . V_288 ;
return V_286 ;
}
static void F_143 ( struct V_1 * V_2 )
{
#ifdef F_64
bool V_289 ;
struct V_290 * V_291 = & V_2 -> V_139 -> V_5 ;
struct V_226 * V_292 = & V_226 ;
V_289 = ( V_291 -> V_293 + 1 ==
F_144 ( & V_2 -> V_139 -> V_294 ) ) ;
if ( V_291 -> V_295 ||
( V_292 -> clock . V_233 == V_296 && V_289 ) )
F_32 ( V_297 , V_2 ) ;
F_145 ( V_2 -> V_298 , V_291 -> V_293 ,
F_144 ( & V_2 -> V_139 -> V_294 ) ,
V_291 -> V_295 , V_292 -> clock . V_233 ) ;
#endif
}
static void F_146 ( struct V_1 * V_2 , T_12 V_94 )
{
T_2 V_299 = V_2 -> V_5 . V_300 ;
V_2 -> V_5 . V_301 += V_94 - V_299 ;
}
static inline T_2 F_147 ( T_2 V_268 , T_2 V_286 )
{
return F_148 ( V_286 , V_268 , V_275 ) ;
}
T_2 F_149 ( struct V_1 * V_2 , T_2 V_286 )
{
T_2 V_302 = V_286 ;
T_2 V_268 = V_2 -> V_5 . V_269 ;
if ( V_268 != V_270 )
V_302 = F_147 ( V_268 , V_286 ) ;
return V_302 ;
}
static T_2 F_150 ( struct V_1 * V_2 , T_2 V_303 )
{
T_2 V_286 ;
V_286 = F_149 ( V_2 , F_151 () ) ;
return V_303 - V_286 ;
}
T_2 F_152 ( struct V_1 * V_2 , T_2 V_304 )
{
return V_2 -> V_5 . V_300 + F_149 ( V_2 , V_304 ) ;
}
static void F_153 ( struct V_1 * V_2 , T_2 V_94 )
{
V_87 -> V_305 ( V_2 , V_94 ) ;
V_2 -> V_5 . V_300 = V_94 ;
}
void F_154 ( struct V_1 * V_2 , struct V_33 * V_22 )
{
struct V_139 * V_139 = V_2 -> V_139 ;
T_2 V_94 , V_306 , V_307 ;
unsigned long V_15 ;
T_12 V_308 ;
bool V_309 ;
bool V_310 ;
T_2 V_39 = V_22 -> V_39 ;
F_155 ( & V_139 -> V_5 . V_311 , V_15 ) ;
V_94 = F_150 ( V_2 , V_39 ) ;
V_306 = F_156 () ;
V_307 = V_306 - V_139 -> V_5 . V_312 ;
if ( V_2 -> V_5 . V_283 ) {
int V_313 = 0 ;
V_308 = V_39 - V_139 -> V_5 . V_314 ;
#ifdef F_64
V_308 = ( V_308 * 1000 ) / V_2 -> V_5 . V_283 ;
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
F_135 ( V_307 , 1000 ) ;
V_308 -= V_307 ;
if ( V_308 < 0 )
V_308 = - V_308 ;
if ( V_313 )
V_308 = V_315 ;
} else
V_308 = V_315 ;
if ( V_308 < V_315 &&
V_2 -> V_5 . V_283 == V_139 -> V_5 . V_316 ) {
if ( ! F_157 () ) {
V_94 = V_139 -> V_5 . V_317 ;
F_133 ( L_6 , V_39 ) ;
} else {
T_2 V_318 = F_158 ( V_2 , V_307 ) ;
V_39 += V_318 ;
V_94 = F_150 ( V_2 , V_39 ) ;
F_133 ( L_7 , V_318 ) ;
}
V_309 = true ;
V_310 = ( V_2 -> V_5 . V_319 == V_139 -> V_5 . V_320 ) ;
} else {
V_139 -> V_5 . V_320 ++ ;
V_139 -> V_5 . V_321 = V_306 ;
V_139 -> V_5 . V_322 = V_39 ;
V_139 -> V_5 . V_317 = V_94 ;
V_309 = false ;
F_133 ( L_8 ,
V_139 -> V_5 . V_320 , V_39 ) ;
}
V_139 -> V_5 . V_312 = V_306 ;
V_139 -> V_5 . V_314 = V_39 ;
V_139 -> V_5 . V_316 = V_2 -> V_5 . V_283 ;
V_2 -> V_5 . V_323 = V_39 ;
V_2 -> V_5 . V_319 = V_139 -> V_5 . V_320 ;
V_2 -> V_5 . V_287 = V_139 -> V_5 . V_321 ;
V_2 -> V_5 . V_288 = V_139 -> V_5 . V_322 ;
if ( F_159 ( V_2 ) && ! V_22 -> V_41 )
F_146 ( V_2 , V_94 ) ;
F_153 ( V_2 , V_94 ) ;
F_160 ( & V_139 -> V_5 . V_311 , V_15 ) ;
F_161 ( & V_139 -> V_5 . V_324 ) ;
if ( ! V_309 ) {
V_139 -> V_5 . V_293 = 0 ;
} else if ( ! V_310 ) {
V_139 -> V_5 . V_293 ++ ;
}
F_143 ( V_2 ) ;
F_162 ( & V_139 -> V_5 . V_324 ) ;
}
static inline void F_163 ( struct V_1 * V_2 ,
T_12 V_325 )
{
F_153 ( V_2 , V_2 -> V_5 . V_300 + V_325 ) ;
}
static inline void F_164 ( struct V_1 * V_2 , T_12 V_325 )
{
if ( V_2 -> V_5 . V_269 != V_270 )
F_30 ( V_325 < 0 ) ;
V_325 = F_149 ( V_2 , ( T_2 ) V_325 ) ;
F_163 ( V_2 , V_325 ) ;
}
static T_2 F_165 ( void )
{
T_2 V_108 = ( T_2 ) F_166 () ;
T_2 V_326 = V_226 . clock . V_235 ;
if ( F_167 ( V_108 >= V_326 ) )
return V_108 ;
asm volatile ("");
return V_326 ;
}
static inline T_2 F_168 ( T_2 * V_327 )
{
long V_265 ;
struct V_226 * V_292 = & V_226 ;
* V_327 = F_165 () ;
V_265 = ( * V_327 - V_292 -> clock . V_235 ) & V_292 -> clock . V_29 ;
return V_265 * V_292 -> clock . V_236 ;
}
static int F_169 ( T_12 * V_328 , T_2 * V_327 )
{
struct V_226 * V_292 = & V_226 ;
unsigned long V_232 ;
int V_329 ;
T_2 V_306 ;
do {
V_232 = F_170 ( & V_292 -> V_232 ) ;
V_329 = V_292 -> clock . V_233 ;
V_306 = V_292 -> V_238 ;
V_306 += F_168 ( V_327 ) ;
V_306 >>= V_292 -> clock . V_237 ;
V_306 += V_292 -> V_228 ;
} while ( F_171 ( F_172 ( & V_292 -> V_232 , V_232 ) ) );
* V_328 = V_306 ;
return V_329 ;
}
static bool F_173 ( T_12 * V_285 , T_2 * V_327 )
{
if ( V_226 . clock . V_233 != V_296 )
return false ;
return F_169 ( V_285 , V_327 ) == V_296 ;
}
static void F_174 ( struct V_139 * V_139 )
{
#ifdef F_64
struct V_290 * V_291 = & V_139 -> V_5 ;
int V_233 ;
bool V_330 , V_289 ;
V_289 = ( V_291 -> V_293 + 1 ==
F_144 ( & V_139 -> V_294 ) ) ;
V_330 = F_173 (
& V_291 -> V_331 ,
& V_291 -> V_332 ) ;
V_291 -> V_295 = V_330 && V_289
&& ! V_333
&& ! V_291 -> V_334 ;
if ( V_291 -> V_295 )
F_175 ( & V_335 , 1 ) ;
V_233 = V_226 . clock . V_233 ;
F_176 ( V_291 -> V_295 , V_233 ,
V_289 ) ;
#endif
}
void F_177 ( struct V_139 * V_139 )
{
F_178 ( V_139 , V_336 ) ;
}
static void F_179 ( struct V_139 * V_139 )
{
#ifdef F_64
int V_3 ;
struct V_1 * V_2 ;
struct V_290 * V_291 = & V_139 -> V_5 ;
F_161 ( & V_291 -> V_324 ) ;
F_177 ( V_139 ) ;
F_174 ( V_139 ) ;
F_180 (i, vcpu, kvm)
F_32 ( V_337 , V_2 ) ;
F_180 (i, vcpu, kvm)
F_181 ( V_336 , & V_2 -> V_338 ) ;
F_162 ( & V_291 -> V_324 ) ;
#endif
}
static T_2 F_182 ( struct V_139 * V_139 )
{
struct V_290 * V_291 = & V_139 -> V_5 ;
struct V_339 V_340 ;
F_161 ( & V_291 -> V_324 ) ;
if ( ! V_291 -> V_295 ) {
F_162 ( & V_291 -> V_324 ) ;
return F_156 () + V_291 -> V_247 ;
}
V_340 . V_341 = V_291 -> V_332 ;
V_340 . V_342 = V_291 -> V_331 + V_291 -> V_247 ;
F_162 ( & V_291 -> V_324 ) ;
F_132 ( V_280 , F_183 ( V_343 ) * 1000LL ,
& V_340 . V_344 ,
& V_340 . V_345 ) ;
return F_184 ( & V_340 , F_151 () ) ;
}
T_2 F_185 ( struct V_139 * V_139 )
{
unsigned long V_15 ;
T_12 V_306 ;
F_5 ( V_15 ) ;
V_306 = F_182 ( V_139 ) ;
F_7 ( V_15 ) ;
return V_306 ;
}
static void F_186 ( struct V_1 * V_265 )
{
struct V_346 * V_2 = & V_265 -> V_5 ;
struct V_339 V_347 ;
if ( F_171 ( F_187 ( V_265 -> V_139 , & V_2 -> V_348 ,
& V_347 , sizeof( V_347 ) ) ) )
return;
F_188 ( F_189 ( struct V_339 , V_242 ) != 0 ) ;
V_2 -> V_340 . V_242 = V_347 . V_242 + 1 ;
F_190 ( V_265 -> V_139 , & V_2 -> V_348 ,
& V_2 -> V_340 ,
sizeof( V_2 -> V_340 . V_242 ) ) ;
F_191 () ;
V_2 -> V_340 . V_15 |= ( V_347 . V_15 & V_349 ) ;
if ( V_2 -> V_350 ) {
V_2 -> V_340 . V_15 |= V_349 ;
V_2 -> V_350 = false ;
}
F_192 ( V_265 -> V_298 , & V_2 -> V_340 ) ;
F_190 ( V_265 -> V_139 , & V_2 -> V_348 ,
& V_2 -> V_340 ,
sizeof( V_2 -> V_340 ) ) ;
F_191 () ;
V_2 -> V_340 . V_242 ++ ;
F_190 ( V_265 -> V_139 , & V_2 -> V_348 ,
& V_2 -> V_340 ,
sizeof( V_2 -> V_340 . V_242 ) ) ;
}
static int F_193 ( struct V_1 * V_265 )
{
unsigned long V_15 , V_351 ;
struct V_346 * V_2 = & V_265 -> V_5 ;
struct V_290 * V_291 = & V_265 -> V_139 -> V_5 ;
T_12 V_285 ;
T_2 V_341 , V_304 ;
T_13 V_352 ;
bool V_295 ;
V_285 = 0 ;
V_304 = 0 ;
F_161 ( & V_291 -> V_324 ) ;
V_295 = V_291 -> V_295 ;
if ( V_295 ) {
V_304 = V_291 -> V_332 ;
V_285 = V_291 -> V_331 ;
}
F_162 ( & V_291 -> V_324 ) ;
F_5 ( V_15 ) ;
V_351 = F_183 ( V_343 ) ;
if ( F_171 ( V_351 == 0 ) ) {
F_7 ( V_15 ) ;
F_32 ( V_337 , V_265 ) ;
return 1 ;
}
if ( ! V_295 ) {
V_304 = F_151 () ;
V_285 = F_156 () ;
}
V_341 = F_152 ( V_265 , V_304 ) ;
if ( V_2 -> V_273 ) {
T_2 V_286 = F_141 ( V_265 , V_285 ) ;
if ( V_286 > V_341 ) {
F_163 ( V_265 , V_286 - V_341 ) ;
V_341 = V_286 ;
}
}
F_7 ( V_15 ) ;
if ( V_271 )
V_351 = F_149 ( V_265 , V_351 ) ;
if ( F_171 ( V_2 -> V_353 != V_351 ) ) {
F_132 ( V_280 , V_351 * 1000LL ,
& V_2 -> V_340 . V_344 ,
& V_2 -> V_340 . V_345 ) ;
V_2 -> V_353 = V_351 ;
}
V_2 -> V_340 . V_341 = V_341 ;
V_2 -> V_340 . V_342 = V_285 + V_265 -> V_139 -> V_5 . V_247 ;
V_2 -> V_323 = V_341 ;
V_352 = 0 ;
if ( V_295 )
V_352 |= V_354 ;
V_2 -> V_340 . V_15 = V_352 ;
if ( V_2 -> V_355 )
F_186 ( V_265 ) ;
if ( V_265 == F_194 ( V_265 -> V_139 , 0 ) )
F_195 ( V_265 -> V_139 , & V_2 -> V_340 ) ;
return 0 ;
}
static void F_196 ( struct V_356 * V_357 )
{
int V_3 ;
struct V_358 * V_359 = F_197 ( V_357 ) ;
struct V_290 * V_291 = F_4 ( V_359 , struct V_290 ,
V_360 ) ;
struct V_139 * V_139 = F_4 ( V_291 , struct V_139 , V_5 ) ;
struct V_1 * V_2 ;
F_180 (i, vcpu, kvm) {
F_32 ( V_337 , V_2 ) ;
F_198 ( V_2 ) ;
}
}
static void F_199 ( struct V_1 * V_265 )
{
struct V_139 * V_139 = V_265 -> V_139 ;
F_32 ( V_337 , V_265 ) ;
F_200 ( & V_139 -> V_5 . V_360 ,
V_361 ) ;
}
static void F_201 ( struct V_356 * V_357 )
{
struct V_358 * V_359 = F_197 ( V_357 ) ;
struct V_290 * V_291 = F_4 ( V_359 , struct V_290 ,
V_362 ) ;
struct V_139 * V_139 = F_4 ( V_291 , struct V_139 , V_5 ) ;
if ( ! V_363 )
return;
F_200 ( & V_139 -> V_5 . V_360 , 0 ) ;
F_200 ( & V_139 -> V_5 . V_362 ,
V_364 ) ;
}
static int F_202 ( struct V_1 * V_2 , T_1 V_22 , T_2 V_39 )
{
T_2 V_365 = V_2 -> V_5 . V_365 ;
unsigned V_366 = V_365 & 0xff ;
switch ( V_22 ) {
case V_367 :
V_2 -> V_5 . V_368 = V_39 ;
break;
case V_369 :
if ( ! ( V_365 & V_370 ) )
return 1 ;
if ( V_39 != 0 && V_39 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_371 = V_39 ;
break;
default:
if ( V_22 >= V_372 &&
V_22 < F_203 ( V_366 ) ) {
T_1 V_94 = V_22 - V_372 ;
if ( ( V_94 & 0x3 ) == 0 &&
V_39 != 0 && ( V_39 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_373 [ V_94 ] = V_39 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_204 ( struct V_1 * V_2 , T_2 V_39 )
{
struct V_139 * V_139 = V_2 -> V_139 ;
int V_374 = F_58 ( V_2 ) ;
T_13 * V_375 = V_374 ? ( T_13 * ) ( long ) V_139 -> V_5 . F_204 . V_376
: ( T_13 * ) ( long ) V_139 -> V_5 . F_204 . V_377 ;
T_13 V_378 = V_374 ? V_139 -> V_5 . F_204 . V_379
: V_139 -> V_5 . F_204 . V_380 ;
T_1 V_381 = V_39 & ~ V_382 ;
T_2 V_383 = V_39 & V_382 ;
T_13 * V_384 ;
int V_121 ;
V_121 = - V_385 ;
if ( V_381 >= V_378 )
goto V_113;
V_121 = - V_386 ;
V_384 = F_205 ( V_375 + ( V_381 * V_107 ) , V_107 ) ;
if ( F_206 ( V_384 ) ) {
V_121 = F_207 ( V_384 ) ;
goto V_113;
}
if ( F_208 ( V_2 , V_383 , V_384 , V_107 ) )
goto V_387;
V_121 = 0 ;
V_387:
F_209 ( V_384 ) ;
V_113:
return V_121 ;
}
static int F_210 ( struct V_1 * V_2 , T_2 V_39 )
{
T_6 V_388 = V_39 & ~ 0x3f ;
if ( V_39 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_389 = V_39 ;
if ( ! ( V_39 & V_390 ) ) {
F_66 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_211 ( V_2 -> V_139 , & V_2 -> V_5 . V_6 . V_39 , V_388 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_391 = ! ( V_39 & V_392 ) ;
F_212 ( V_2 ) ;
return 0 ;
}
static void F_213 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_355 = false ;
}
static void F_214 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_393 . V_389 & V_394 ) )
return;
if ( F_171 ( F_187 ( V_2 -> V_139 , & V_2 -> V_5 . V_393 . V_395 ,
& V_2 -> V_5 . V_393 . V_396 , sizeof( struct V_397 ) ) ) )
return;
V_2 -> V_5 . V_393 . V_396 . V_398 = 0 ;
if ( V_2 -> V_5 . V_393 . V_396 . V_242 & 1 )
V_2 -> V_5 . V_393 . V_396 . V_242 += 1 ;
V_2 -> V_5 . V_393 . V_396 . V_242 += 1 ;
F_190 ( V_2 -> V_139 , & V_2 -> V_5 . V_393 . V_395 ,
& V_2 -> V_5 . V_393 . V_396 , sizeof( struct V_397 ) ) ;
F_191 () ;
V_2 -> V_5 . V_393 . V_396 . V_396 += V_399 -> V_400 . V_401 -
V_2 -> V_5 . V_393 . V_402 ;
V_2 -> V_5 . V_393 . V_402 = V_399 -> V_400 . V_401 ;
F_190 ( V_2 -> V_139 , & V_2 -> V_5 . V_393 . V_395 ,
& V_2 -> V_5 . V_393 . V_396 , sizeof( struct V_397 ) ) ;
F_191 () ;
V_2 -> V_5 . V_393 . V_396 . V_242 += 1 ;
F_190 ( V_2 -> V_139 , & V_2 -> V_5 . V_393 . V_395 ,
& V_2 -> V_5 . V_393 . V_396 , sizeof( struct V_397 ) ) ;
}
int F_215 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
bool V_403 = false ;
T_1 V_22 = V_34 -> V_147 ;
T_2 V_39 = V_34 -> V_39 ;
switch ( V_22 ) {
case V_404 :
case V_405 :
case V_406 :
case V_407 :
case V_408 :
case V_409 :
break;
case V_410 :
return F_110 ( V_2 , V_39 ) ;
case V_411 :
V_39 &= ~ ( T_2 ) 0x40 ;
V_39 &= ~ ( T_2 ) 0x100 ;
V_39 &= ~ ( T_2 ) 0x8 ;
V_39 &= ~ ( T_2 ) 0x40000 ;
if ( V_39 != 0 ) {
F_216 ( V_2 , L_9 ,
V_39 ) ;
return 1 ;
}
break;
case V_412 :
if ( V_39 != 0 ) {
F_216 ( V_2 , L_10
L_11 , V_39 ) ;
return 1 ;
}
break;
case V_413 :
if ( ! V_39 ) {
break;
} else if ( V_39 & ~ ( V_414 | V_415 ) ) {
return 1 ;
}
F_216 ( V_2 , L_12 ,
V_262 , V_39 ) ;
break;
case 0x200 ... 0x2ff :
return F_217 ( V_2 , V_22 , V_39 ) ;
case V_416 :
return F_22 ( V_2 , V_34 ) ;
case V_417 ... V_417 + 0x3ff :
return F_218 ( V_2 , V_22 , V_39 ) ;
case V_418 :
F_219 ( V_2 , V_39 ) ;
break;
case V_419 :
if ( F_159 ( V_2 ) ) {
if ( ! V_34 -> V_41 ) {
T_12 V_420 = V_39 - V_2 -> V_5 . V_301 ;
F_163 ( V_2 , V_420 ) ;
}
V_2 -> V_5 . V_301 = V_39 ;
}
break;
case V_421 :
V_2 -> V_5 . V_422 = V_39 ;
break;
case V_423 :
if ( ! V_34 -> V_41 )
return 1 ;
V_2 -> V_5 . V_424 = V_39 ;
break;
case V_425 :
case V_426 :
V_2 -> V_139 -> V_5 . V_241 = V_39 ;
F_124 ( V_2 -> V_139 , V_39 ) ;
break;
case V_427 :
case V_428 : {
struct V_290 * V_291 = & V_2 -> V_139 -> V_5 ;
F_213 ( V_2 ) ;
if ( V_2 -> V_298 == 0 && ! V_34 -> V_41 ) {
bool V_429 = ( V_22 == V_428 ) ;
if ( V_291 -> V_334 != V_429 )
F_220 ( V_297 ,
& V_2 -> V_338 ) ;
V_291 -> V_334 = V_429 ;
}
V_2 -> V_5 . time = V_39 ;
F_32 ( V_430 , V_2 ) ;
if ( ! ( V_39 & 1 ) )
break;
if ( F_211 ( V_2 -> V_139 ,
& V_2 -> V_5 . V_348 , V_39 & ~ 1ULL ,
sizeof( struct V_339 ) ) )
V_2 -> V_5 . V_355 = false ;
else
V_2 -> V_5 . V_355 = true ;
break;
}
case V_431 :
if ( F_210 ( V_2 , V_39 ) )
return 1 ;
break;
case V_432 :
if ( F_171 ( ! F_221 () ) )
return 1 ;
if ( V_39 & V_433 )
return 1 ;
if ( F_211 ( V_2 -> V_139 , & V_2 -> V_5 . V_393 . V_395 ,
V_39 & V_434 ,
sizeof( struct V_397 ) ) )
return 1 ;
V_2 -> V_5 . V_393 . V_389 = V_39 ;
if ( ! ( V_39 & V_394 ) )
break;
F_32 ( V_435 , V_2 ) ;
break;
case V_436 :
if ( F_222 ( V_2 , V_39 ) )
return 1 ;
break;
case V_369 :
case V_367 :
case V_372 ... F_203 ( V_437 ) - 1 :
return F_202 ( V_2 , V_22 , V_39 ) ;
case V_438 ... V_439 :
case V_440 ... V_441 :
V_403 = true ;
case V_442 ... V_443 :
case V_444 ... V_445 :
if ( F_223 ( V_2 , V_22 ) )
return F_224 ( V_2 , V_34 ) ;
if ( V_403 || V_39 != 0 )
F_216 ( V_2 , L_13
L_14 , V_22 , V_39 ) ;
break;
case V_446 :
break;
case V_447 ... V_448 :
case V_449 ... V_450 :
case V_451 :
case V_452 ... V_453 :
return F_225 ( V_2 , V_22 , V_39 ,
V_34 -> V_41 ) ;
case V_454 :
F_216 ( V_2 , L_15 , V_22 , V_39 ) ;
break;
case V_455 :
if ( ! F_226 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_456 . V_457 = V_39 ;
break;
case V_458 :
if ( ! F_226 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_456 . V_459 = V_39 ;
break;
default:
if ( V_22 && ( V_22 == V_2 -> V_139 -> V_5 . F_204 . V_22 ) )
return F_204 ( V_2 , V_39 ) ;
if ( F_223 ( V_2 , V_22 ) )
return F_224 ( V_2 , V_34 ) ;
if ( ! V_460 ) {
F_227 ( V_2 , L_16 ,
V_22 , V_39 ) ;
return 1 ;
} else {
F_216 ( V_2 , L_15 ,
V_22 , V_39 ) ;
break;
}
}
return 0 ;
}
int F_116 ( struct V_1 * V_2 , struct V_33 * V_22 )
{
return V_87 -> V_461 ( V_2 , V_22 ) ;
}
static int F_228 ( struct V_1 * V_2 , T_1 V_22 , T_2 * V_462 )
{
T_2 V_39 ;
T_2 V_365 = V_2 -> V_5 . V_365 ;
unsigned V_366 = V_365 & 0xff ;
switch ( V_22 ) {
case V_463 :
case V_464 :
V_39 = 0 ;
break;
case V_465 :
V_39 = V_2 -> V_5 . V_365 ;
break;
case V_369 :
if ( ! ( V_365 & V_370 ) )
return 1 ;
V_39 = V_2 -> V_5 . V_371 ;
break;
case V_367 :
V_39 = V_2 -> V_5 . V_368 ;
break;
default:
if ( V_22 >= V_372 &&
V_22 < F_203 ( V_366 ) ) {
T_1 V_94 = V_22 - V_372 ;
V_39 = V_2 -> V_5 . V_373 [ V_94 ] ;
break;
}
return 1 ;
}
* V_462 = V_39 ;
return 0 ;
}
int F_229 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
switch ( V_34 -> V_147 ) {
case V_466 :
case V_467 :
case V_413 :
case V_468 :
case V_469 :
case V_470 :
case V_471 :
case V_472 :
case V_473 :
case V_474 :
case V_411 :
case V_407 :
case V_475 :
case V_404 :
case V_412 :
case V_409 :
case V_476 :
V_34 -> V_39 = 0 ;
break;
case V_442 ... V_443 :
case V_438 ... V_439 :
case V_440 ... V_441 :
case V_444 ... V_445 :
if ( F_223 ( V_2 , V_34 -> V_147 ) )
return F_230 ( V_2 , V_34 -> V_147 , & V_34 -> V_39 ) ;
V_34 -> V_39 = 0 ;
break;
case V_405 :
V_34 -> V_39 = 0x100000000ULL ;
break;
case V_477 :
case 0x200 ... 0x2ff :
return F_231 ( V_2 , V_34 -> V_147 , & V_34 -> V_39 ) ;
case 0xcd :
V_34 -> V_39 = 3 ;
break;
case V_478 :
V_34 -> V_39 = 1 << 24 ;
break;
case V_416 :
V_34 -> V_39 = F_21 ( V_2 ) ;
break;
case V_417 ... V_417 + 0x3ff :
return F_232 ( V_2 , V_34 -> V_147 , & V_34 -> V_39 ) ;
break;
case V_418 :
V_34 -> V_39 = F_233 ( V_2 ) ;
break;
case V_419 :
V_34 -> V_39 = ( T_2 ) V_2 -> V_5 . V_301 ;
break;
case V_421 :
V_34 -> V_39 = V_2 -> V_5 . V_422 ;
break;
case V_423 :
if ( ! V_34 -> V_41 )
return 1 ;
V_34 -> V_39 = V_2 -> V_5 . V_424 ;
break;
case V_479 :
V_34 -> V_39 = 1000ULL ;
V_34 -> V_39 |= ( ( ( T_8 ) 4ULL ) << 40 ) ;
break;
case V_410 :
V_34 -> V_39 = V_2 -> V_5 . V_132 ;
break;
case V_426 :
case V_425 :
V_34 -> V_39 = V_2 -> V_139 -> V_5 . V_241 ;
break;
case V_428 :
case V_427 :
V_34 -> V_39 = V_2 -> V_5 . time ;
break;
case V_431 :
V_34 -> V_39 = V_2 -> V_5 . V_6 . V_389 ;
break;
case V_432 :
V_34 -> V_39 = V_2 -> V_5 . V_393 . V_389 ;
break;
case V_436 :
V_34 -> V_39 = V_2 -> V_5 . V_480 . V_389 ;
break;
case V_463 :
case V_464 :
case V_465 :
case V_369 :
case V_367 :
case V_372 ... F_203 ( V_437 ) - 1 :
return F_228 ( V_2 , V_34 -> V_147 , & V_34 -> V_39 ) ;
case V_446 :
V_34 -> V_39 = 0x20000000 ;
break;
case V_447 ... V_448 :
case V_449 ... V_450 :
case V_451 :
case V_452 ... V_453 :
return F_234 ( V_2 ,
V_34 -> V_147 , & V_34 -> V_39 ) ;
break;
case V_454 :
V_34 -> V_39 = 0xbe702111 ;
break;
case V_455 :
if ( ! F_226 ( V_2 ) )
return 1 ;
V_34 -> V_39 = V_2 -> V_5 . V_456 . V_457 ;
break;
case V_458 :
if ( ! F_226 ( V_2 ) )
return 1 ;
V_34 -> V_39 = V_2 -> V_5 . V_456 . V_459 ;
break;
default:
if ( F_223 ( V_2 , V_34 -> V_147 ) )
return F_230 ( V_2 , V_34 -> V_147 , & V_34 -> V_39 ) ;
if ( ! V_460 ) {
F_227 ( V_2 , L_17 ,
V_34 -> V_147 ) ;
return 1 ;
} else {
F_216 ( V_2 , L_18 , V_34 -> V_147 ) ;
V_34 -> V_39 = 0 ;
}
break;
}
return 0 ;
}
static int F_235 ( struct V_1 * V_2 , struct V_481 * V_21 ,
struct V_482 * V_483 ,
int (* F_236)( struct V_1 * V_2 ,
unsigned V_147 , T_2 * V_39 ) )
{
int V_3 , V_484 ;
V_484 = F_237 ( & V_2 -> V_139 -> V_485 ) ;
for ( V_3 = 0 ; V_3 < V_21 -> V_486 ; ++ V_3 )
if ( F_236 ( V_2 , V_483 [ V_3 ] . V_147 , & V_483 [ V_3 ] . V_39 ) )
break;
F_238 ( & V_2 -> V_139 -> V_485 , V_484 ) ;
return V_3 ;
}
static int F_239 ( struct V_1 * V_2 , struct V_481 T_14 * V_487 ,
int (* F_236)( struct V_1 * V_2 ,
unsigned V_147 , T_2 * V_39 ) ,
int V_488 )
{
struct V_481 V_21 ;
struct V_482 * V_483 ;
int V_121 , V_489 ;
unsigned V_490 ;
V_121 = - V_101 ;
if ( F_240 ( & V_21 , V_487 , sizeof V_21 ) )
goto V_113;
V_121 = - V_385 ;
if ( V_21 . V_486 >= V_491 )
goto V_113;
V_490 = sizeof( struct V_482 ) * V_21 . V_486 ;
V_483 = F_205 ( V_487 -> V_483 , V_490 ) ;
if ( F_206 ( V_483 ) ) {
V_121 = F_207 ( V_483 ) ;
goto V_113;
}
V_121 = V_489 = F_235 ( V_2 , & V_21 , V_483 , F_236 ) ;
if ( V_121 < 0 )
goto V_387;
V_121 = - V_101 ;
if ( V_488 && F_241 ( V_487 -> V_483 , V_483 , V_490 ) )
goto V_387;
V_121 = V_489 ;
V_387:
F_209 ( V_483 ) ;
V_113:
return V_121 ;
}
int F_242 ( struct V_139 * V_139 , long V_492 )
{
int V_121 ;
switch ( V_492 ) {
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
#ifdef F_243
case V_533 :
case V_534 :
#endif
V_121 = 1 ;
break;
case V_535 :
V_121 = V_536 ;
break;
case V_537 :
V_121 = V_87 -> V_538 () ;
break;
case V_539 :
V_121 = V_540 ;
break;
case V_541 :
V_121 = ! V_87 -> V_542 () ;
break;
case V_543 :
V_121 = V_544 ;
break;
case V_545 :
V_121 = V_546 ;
break;
case V_547 :
V_121 = V_548 ;
break;
case V_549 :
V_121 = 0 ;
break;
#ifdef F_243
case V_550 :
V_121 = F_244 ( & V_551 ) ;
break;
#endif
case V_552 :
V_121 = V_437 ;
break;
case V_553 :
V_121 = F_245 ( V_554 ) ;
break;
case V_555 :
V_121 = V_271 ;
break;
case V_556 :
V_121 = V_557 ;
break;
default:
V_121 = 0 ;
break;
}
return V_121 ;
}
long F_246 ( struct V_558 * V_559 ,
unsigned int V_560 , unsigned long V_561 )
{
void T_14 * V_562 = ( void T_14 * ) V_561 ;
long V_121 ;
switch ( V_560 ) {
case V_563 : {
struct V_564 T_14 * V_565 = V_562 ;
struct V_564 V_566 ;
unsigned V_489 ;
V_121 = - V_101 ;
if ( F_240 ( & V_566 , V_565 , sizeof V_566 ) )
goto V_113;
V_489 = V_566 . V_486 ;
V_566 . V_486 = V_567 + V_568 ;
if ( F_241 ( V_565 , & V_566 , sizeof V_566 ) )
goto V_113;
V_121 = - V_385 ;
if ( V_489 < V_566 . V_486 )
goto V_113;
V_121 = - V_101 ;
if ( F_241 ( V_565 -> V_569 , & V_570 ,
V_567 * sizeof( T_1 ) ) )
goto V_113;
if ( F_241 ( V_565 -> V_569 + V_567 ,
& V_571 ,
V_568 * sizeof( T_1 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_572 :
case V_573 : {
struct V_574 T_14 * V_575 = V_562 ;
struct V_574 V_576 ;
V_121 = - V_101 ;
if ( F_240 ( & V_576 , V_575 , sizeof V_576 ) )
goto V_113;
V_121 = F_247 ( & V_576 , V_575 -> V_483 ,
V_560 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_241 ( V_575 , & V_576 , sizeof V_576 ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_577 : {
V_121 = - V_101 ;
if ( F_241 ( V_562 , & V_578 ,
sizeof( V_578 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
default:
V_121 = - V_579 ;
}
V_113:
return V_121 ;
}
static void F_248 ( void * V_580 )
{
F_249 () ;
}
static bool F_250 ( struct V_1 * V_2 )
{
return F_68 ( V_2 -> V_139 ) ;
}
static inline void F_251 ( struct V_1 * V_2 )
{
F_220 ( V_581 , & V_2 -> V_338 ) ;
}
void F_252 ( struct V_1 * V_2 , int V_24 )
{
if ( F_250 ( V_2 ) ) {
if ( V_87 -> V_582 () )
F_253 ( V_24 , V_2 -> V_5 . V_583 ) ;
else if ( V_2 -> V_24 != - 1 && V_2 -> V_24 != V_24 )
F_254 ( V_2 -> V_24 ,
F_248 , NULL , 1 ) ;
}
V_87 -> V_584 ( V_2 , V_24 ) ;
if ( F_171 ( V_2 -> V_5 . V_585 ) ) {
F_164 ( V_2 , V_2 -> V_5 . V_585 ) ;
V_2 -> V_5 . V_585 = 0 ;
F_32 ( V_337 , V_2 ) ;
}
if ( F_171 ( V_2 -> V_24 != V_24 ) || F_157 () ) {
T_12 V_586 = ! V_2 -> V_5 . V_587 ? 0 :
F_151 () - V_2 -> V_5 . V_587 ;
if ( V_586 < 0 )
F_255 ( L_19 ) ;
if ( F_157 () ) {
T_2 V_94 = F_150 ( V_2 ,
V_2 -> V_5 . V_323 ) ;
F_153 ( V_2 , V_94 ) ;
V_2 -> V_5 . V_273 = 1 ;
}
if ( F_256 ( V_2 ) &&
V_87 -> V_588 ( V_2 ,
F_257 ( V_2 ) ) )
F_258 ( V_2 ) ;
if ( ! V_2 -> V_139 -> V_5 . V_295 || V_2 -> V_24 == - 1 )
F_32 ( V_430 , V_2 ) ;
if ( V_2 -> V_24 != V_24 )
F_251 ( V_2 ) ;
V_2 -> V_24 = V_24 ;
}
F_32 ( V_435 , V_2 ) ;
}
static void F_259 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_393 . V_389 & V_394 ) )
return;
V_2 -> V_5 . V_393 . V_396 . V_398 = 1 ;
F_260 ( V_2 -> V_139 , & V_2 -> V_5 . V_393 . V_395 ,
& V_2 -> V_5 . V_393 . V_396 . V_398 ,
F_189 ( struct V_397 , V_398 ) ,
sizeof( V_2 -> V_5 . V_393 . V_396 . V_398 ) ) ;
}
void F_261 ( struct V_1 * V_2 )
{
int V_484 ;
F_262 () ;
V_484 = F_237 ( & V_2 -> V_139 -> V_485 ) ;
F_259 ( V_2 ) ;
F_238 ( & V_2 -> V_139 -> V_485 , V_484 ) ;
F_263 () ;
V_87 -> V_589 ( V_2 ) ;
F_264 ( V_2 ) ;
V_2 -> V_5 . V_587 = F_151 () ;
}
static int F_265 ( struct V_1 * V_2 ,
struct V_590 * V_591 )
{
if ( V_2 -> V_5 . V_592 )
V_87 -> V_593 ( V_2 ) ;
return F_266 ( V_2 , V_591 ) ;
}
static int F_267 ( struct V_1 * V_2 ,
struct V_590 * V_591 )
{
int V_121 ;
V_121 = F_268 ( V_2 , V_591 ) ;
if ( V_121 )
return V_121 ;
F_269 ( V_2 ) ;
return 0 ;
}
static int F_270 ( struct V_1 * V_2 )
{
return ( ! F_91 ( V_2 ) ||
F_271 ( V_2 ) ) ;
}
static int F_272 ( struct V_1 * V_2 )
{
return F_273 ( V_2 ) &&
! F_274 ( V_2 ) &&
! F_275 ( V_2 ) &&
F_270 ( V_2 ) ;
}
static int F_276 ( struct V_1 * V_2 ,
struct V_594 * V_595 )
{
if ( V_595 -> V_595 >= V_596 )
return - V_579 ;
if ( ! F_277 ( V_2 -> V_139 ) ) {
F_278 ( V_2 , V_595 -> V_595 , false ) ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
if ( F_279 ( V_2 -> V_139 ) )
return - V_597 ;
if ( V_2 -> V_5 . V_598 != - 1 )
return - V_599 ;
V_2 -> V_5 . V_598 = V_595 -> V_595 ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
static int F_280 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
return 0 ;
}
static int F_281 ( struct V_1 * V_2 )
{
F_32 ( V_600 , V_2 ) ;
return 0 ;
}
static int F_282 ( struct V_1 * V_2 ,
struct V_601 * V_602 )
{
if ( V_602 -> V_15 )
return - V_579 ;
V_2 -> V_5 . V_603 = ! ! V_602 -> V_604 ;
return 0 ;
}
static int F_283 ( struct V_1 * V_2 ,
T_2 V_365 )
{
int V_121 ;
unsigned V_366 = V_365 & 0xff , V_605 ;
V_121 = - V_579 ;
if ( ! V_366 || V_366 >= V_437 )
goto V_113;
if ( V_365 & ~ ( V_578 | 0xff | 0xff0000 ) )
goto V_113;
V_121 = 0 ;
V_2 -> V_5 . V_365 = V_365 ;
if ( V_365 & V_370 )
V_2 -> V_5 . V_371 = ~ ( T_2 ) 0 ;
for ( V_605 = 0 ; V_605 < V_366 ; V_605 ++ )
V_2 -> V_5 . V_373 [ V_605 * 4 ] = ~ ( T_2 ) 0 ;
if ( V_87 -> V_606 )
V_87 -> V_606 ( V_2 ) ;
V_113:
return V_121 ;
}
static int F_284 ( struct V_1 * V_2 ,
struct V_607 * V_608 )
{
T_2 V_365 = V_2 -> V_5 . V_365 ;
unsigned V_366 = V_365 & 0xff ;
T_2 * V_609 = V_2 -> V_5 . V_373 ;
if ( V_608 -> V_605 >= V_366 || ! ( V_608 -> V_459 & V_610 ) )
return - V_579 ;
if ( ( V_608 -> V_459 & V_611 ) && ( V_365 & V_370 ) &&
V_2 -> V_5 . V_371 != ~ ( T_2 ) 0 )
return 0 ;
V_609 += 4 * V_608 -> V_605 ;
if ( ( V_608 -> V_459 & V_611 ) && V_609 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_608 -> V_459 & V_611 ) {
if ( ( V_2 -> V_5 . V_368 & V_612 ) ||
! F_48 ( V_2 , V_613 ) ) {
F_32 ( V_73 , V_2 ) ;
return 0 ;
}
if ( V_609 [ 1 ] & V_610 )
V_608 -> V_459 |= V_614 ;
V_609 [ 2 ] = V_608 -> V_615 ;
V_609 [ 3 ] = V_608 -> V_616 ;
V_2 -> V_5 . V_368 = V_608 -> V_368 ;
V_609 [ 1 ] = V_608 -> V_459 ;
F_34 ( V_2 , V_59 ) ;
} else if ( ! ( V_609 [ 1 ] & V_610 )
|| ! ( V_609 [ 1 ] & V_611 ) ) {
if ( V_609 [ 1 ] & V_610 )
V_608 -> V_459 |= V_614 ;
V_609 [ 2 ] = V_608 -> V_615 ;
V_609 [ 3 ] = V_608 -> V_616 ;
V_609 [ 1 ] = V_608 -> V_459 ;
} else
V_609 [ 1 ] |= V_614 ;
return 0 ;
}
static void F_285 ( struct V_1 * V_2 ,
struct V_617 * V_618 )
{
F_286 ( V_2 ) ;
V_618 -> V_69 . V_619 =
V_2 -> V_5 . V_69 . V_70 &&
! F_287 ( V_2 -> V_5 . V_69 . V_18 ) ;
V_618 -> V_69 . V_18 = V_2 -> V_5 . V_69 . V_18 ;
V_618 -> V_69 . V_72 = V_2 -> V_5 . V_69 . V_72 ;
V_618 -> V_69 . V_620 = 0 ;
V_618 -> V_69 . V_63 = V_2 -> V_5 . V_69 . V_63 ;
V_618 -> V_621 . V_619 =
V_2 -> V_5 . V_621 . V_70 && ! V_2 -> V_5 . V_621 . V_622 ;
V_618 -> V_621 . V_18 = V_2 -> V_5 . V_621 . V_18 ;
V_618 -> V_621 . V_622 = 0 ;
V_618 -> V_621 . V_623 = V_87 -> V_624 ( V_2 ) ;
V_618 -> V_625 . V_619 = V_2 -> V_5 . V_626 ;
V_618 -> V_625 . V_70 = V_2 -> V_5 . V_627 != 0 ;
V_618 -> V_625 . V_628 = V_87 -> V_629 ( V_2 ) ;
V_618 -> V_625 . V_620 = 0 ;
V_618 -> V_630 = 0 ;
V_618 -> V_631 . V_632 = F_288 ( V_2 ) ;
V_618 -> V_631 . V_70 = V_2 -> V_5 . V_633 ;
V_618 -> V_631 . V_634 =
! ! ( V_2 -> V_5 . V_635 & V_636 ) ;
V_618 -> V_631 . V_637 = F_289 ( V_2 ) ;
V_618 -> V_15 = ( V_638
| V_639
| V_640 ) ;
memset ( & V_618 -> V_641 , 0 , sizeof( V_618 -> V_641 ) ) ;
}
static int F_290 ( struct V_1 * V_2 ,
struct V_617 * V_618 )
{
if ( V_618 -> V_15 & ~ ( V_638
| V_642
| V_639
| V_640 ) )
return - V_579 ;
if ( V_618 -> V_69 . V_619 &&
( V_618 -> V_69 . V_18 > 31 || V_618 -> V_69 . V_18 == V_52 ) )
return - V_579 ;
F_286 ( V_2 ) ;
V_2 -> V_5 . V_69 . V_70 = V_618 -> V_69 . V_619 ;
V_2 -> V_5 . V_69 . V_18 = V_618 -> V_69 . V_18 ;
V_2 -> V_5 . V_69 . V_72 = V_618 -> V_69 . V_72 ;
V_2 -> V_5 . V_69 . V_63 = V_618 -> V_69 . V_63 ;
V_2 -> V_5 . V_621 . V_70 = V_618 -> V_621 . V_619 ;
V_2 -> V_5 . V_621 . V_18 = V_618 -> V_621 . V_18 ;
V_2 -> V_5 . V_621 . V_622 = V_618 -> V_621 . V_622 ;
if ( V_618 -> V_15 & V_639 )
V_87 -> V_643 ( V_2 ,
V_618 -> V_621 . V_623 ) ;
V_2 -> V_5 . V_626 = V_618 -> V_625 . V_619 ;
if ( V_618 -> V_15 & V_638 )
V_2 -> V_5 . V_627 = V_618 -> V_625 . V_70 ;
V_87 -> V_644 ( V_2 , V_618 -> V_625 . V_628 ) ;
if ( V_618 -> V_15 & V_642 &&
F_91 ( V_2 ) )
V_2 -> V_5 . V_645 -> V_630 = V_618 -> V_630 ;
if ( V_618 -> V_15 & V_640 ) {
T_1 V_635 = V_2 -> V_5 . V_635 ;
if ( V_618 -> V_631 . V_632 )
V_635 |= V_646 ;
else
V_635 &= ~ V_646 ;
F_291 ( V_2 , V_635 ) ;
V_2 -> V_5 . V_633 = V_618 -> V_631 . V_70 ;
if ( V_618 -> V_631 . V_634 )
V_2 -> V_5 . V_635 |= V_636 ;
else
V_2 -> V_5 . V_635 &= ~ V_636 ;
if ( F_91 ( V_2 ) ) {
if ( V_618 -> V_631 . V_637 )
F_220 ( V_647 , & V_2 -> V_5 . V_645 -> V_648 ) ;
else
F_181 ( V_647 , & V_2 -> V_5 . V_645 -> V_648 ) ;
}
}
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
static void F_292 ( struct V_1 * V_2 ,
struct V_649 * V_650 )
{
unsigned long V_196 ;
memcpy ( V_650 -> V_183 , V_2 -> V_5 . V_183 , sizeof( V_2 -> V_5 . V_183 ) ) ;
F_102 ( V_2 , 6 , & V_196 ) ;
V_650 -> V_187 = V_196 ;
V_650 -> V_188 = V_2 -> V_5 . V_188 ;
V_650 -> V_15 = 0 ;
memset ( & V_650 -> V_641 , 0 , sizeof( V_650 -> V_641 ) ) ;
}
static int F_293 ( struct V_1 * V_2 ,
struct V_649 * V_650 )
{
if ( V_650 -> V_15 )
return - V_579 ;
if ( V_650 -> V_187 & ~ 0xffffffffull )
return - V_579 ;
if ( V_650 -> V_188 & ~ 0xffffffffull )
return - V_579 ;
memcpy ( V_2 -> V_5 . V_183 , V_650 -> V_183 , sizeof( V_2 -> V_5 . V_183 ) ) ;
F_95 ( V_2 ) ;
V_2 -> V_5 . V_187 = V_650 -> V_187 ;
F_96 ( V_2 ) ;
V_2 -> V_5 . V_188 = V_650 -> V_188 ;
F_97 ( V_2 ) ;
return 0 ;
}
static void F_294 ( T_13 * V_651 , struct V_1 * V_2 )
{
struct V_652 * V_653 = & V_2 -> V_5 . V_654 . V_655 . V_653 ;
T_2 V_656 = V_653 -> V_657 . V_658 ;
T_2 V_659 ;
memcpy ( V_651 , V_653 , V_660 ) ;
V_656 &= V_2 -> V_5 . V_154 | V_661 ;
* ( T_2 * ) ( V_651 + V_660 ) = V_656 ;
V_659 = V_656 & ~ V_661 ;
while ( V_659 ) {
T_2 V_662 = V_659 & - V_659 ;
int V_147 = F_295 ( V_662 ) - 1 ;
void * V_663 = F_296 ( V_653 , V_662 ) ;
if ( V_663 ) {
T_1 V_490 , V_94 , V_201 , V_209 ;
F_297 ( V_664 , V_147 ,
& V_490 , & V_94 , & V_201 , & V_209 ) ;
memcpy ( V_651 + V_94 , V_663 , V_490 ) ;
}
V_659 -= V_662 ;
}
}
static void F_298 ( struct V_1 * V_2 , T_13 * V_663 )
{
struct V_652 * V_653 = & V_2 -> V_5 . V_654 . V_655 . V_653 ;
T_2 V_656 = * ( T_2 * ) ( V_663 + V_660 ) ;
T_2 V_659 ;
memcpy ( V_653 , V_663 , V_660 ) ;
V_653 -> V_657 . V_658 = V_656 ;
if ( F_245 ( V_665 ) )
V_653 -> V_657 . V_666 = V_146 | V_667 ;
V_659 = V_656 & ~ V_661 ;
while ( V_659 ) {
T_2 V_662 = V_659 & - V_659 ;
int V_147 = F_295 ( V_662 ) - 1 ;
void * V_651 = F_296 ( V_653 , V_662 ) ;
if ( V_651 ) {
T_1 V_490 , V_94 , V_201 , V_209 ;
F_297 ( V_664 , V_147 ,
& V_490 , & V_94 , & V_201 , & V_209 ) ;
memcpy ( V_651 , V_663 + V_94 , V_490 ) ;
}
V_659 -= V_662 ;
}
}
static void F_299 ( struct V_1 * V_2 ,
struct V_668 * V_669 )
{
if ( F_245 ( V_554 ) ) {
memset ( V_669 , 0 , sizeof( struct V_668 ) ) ;
F_294 ( ( T_13 * ) V_669 -> V_670 , V_2 ) ;
} else {
memcpy ( V_669 -> V_670 ,
& V_2 -> V_5 . V_654 . V_655 . V_671 ,
sizeof( struct V_672 ) ) ;
* ( T_2 * ) & V_669 -> V_670 [ V_660 / sizeof( T_1 ) ] =
V_661 ;
}
}
static int F_300 ( struct V_1 * V_2 ,
struct V_668 * V_669 )
{
T_2 V_656 =
* ( T_2 * ) & V_669 -> V_670 [ V_660 / sizeof( T_1 ) ] ;
if ( F_245 ( V_554 ) ) {
if ( V_656 & ~ F_301 () )
return - V_579 ;
F_298 ( V_2 , ( T_13 * ) V_669 -> V_670 ) ;
} else {
if ( V_656 & ~ V_661 )
return - V_579 ;
memcpy ( & V_2 -> V_5 . V_654 . V_655 . V_671 ,
V_669 -> V_670 , sizeof( struct V_672 ) ) ;
}
return 0 ;
}
static void F_302 ( struct V_1 * V_2 ,
struct V_673 * V_674 )
{
if ( ! F_245 ( V_554 ) ) {
V_674 -> V_675 = 0 ;
return;
}
V_674 -> V_675 = 1 ;
V_674 -> V_15 = 0 ;
V_674 -> V_676 [ 0 ] . V_148 = V_144 ;
V_674 -> V_676 [ 0 ] . V_23 = V_2 -> V_5 . V_145 ;
}
static int F_303 ( struct V_1 * V_2 ,
struct V_673 * V_674 )
{
int V_3 , V_121 = 0 ;
if ( ! F_245 ( V_554 ) )
return - V_579 ;
if ( V_674 -> V_675 > V_677 || V_674 -> V_15 )
return - V_579 ;
for ( V_3 = 0 ; V_3 < V_674 -> V_675 ; V_3 ++ )
if ( V_674 -> V_676 [ V_3 ] . V_148 == V_144 ) {
V_121 = F_76 ( V_2 , V_144 ,
V_674 -> V_676 [ V_3 ] . V_23 ) ;
break;
}
if ( V_121 )
V_121 = - V_579 ;
return V_121 ;
}
static int F_304 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_355 )
return - V_579 ;
V_2 -> V_5 . V_350 = true ;
F_32 ( V_337 , V_2 ) ;
return 0 ;
}
static int F_305 ( struct V_1 * V_2 ,
struct V_678 * V_679 )
{
if ( V_679 -> V_15 )
return - V_579 ;
switch ( V_679 -> V_679 ) {
case V_517 :
if ( ! F_277 ( V_2 -> V_139 ) )
return - V_579 ;
return F_306 ( V_2 ) ;
default:
return - V_579 ;
}
}
long F_307 ( struct V_558 * V_559 ,
unsigned int V_560 , unsigned long V_561 )
{
struct V_1 * V_2 = V_559 -> V_680 ;
void T_14 * V_562 = ( void T_14 * ) V_561 ;
int V_121 ;
union {
struct V_590 * V_681 ;
struct V_668 * V_653 ;
struct V_673 * V_676 ;
void * V_682 ;
} V_683 ;
V_683 . V_682 = NULL ;
switch ( V_560 ) {
case V_684 : {
V_121 = - V_579 ;
if ( ! F_91 ( V_2 ) )
goto V_113;
V_683 . V_681 = F_308 ( sizeof( struct V_590 ) , V_685 ) ;
V_121 = - V_386 ;
if ( ! V_683 . V_681 )
goto V_113;
V_121 = F_265 ( V_2 , V_683 . V_681 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_241 ( V_562 , V_683 . V_681 , sizeof( struct V_590 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_686 : {
V_121 = - V_579 ;
if ( ! F_91 ( V_2 ) )
goto V_113;
V_683 . V_681 = F_205 ( V_562 , sizeof( * V_683 . V_681 ) ) ;
if ( F_206 ( V_683 . V_681 ) )
return F_207 ( V_683 . V_681 ) ;
V_121 = F_267 ( V_2 , V_683 . V_681 ) ;
break;
}
case V_687 : {
struct V_594 V_595 ;
V_121 = - V_101 ;
if ( F_240 ( & V_595 , V_562 , sizeof V_595 ) )
goto V_113;
V_121 = F_276 ( V_2 , & V_595 ) ;
break;
}
case V_688 : {
V_121 = F_280 ( V_2 ) ;
break;
}
case V_689 : {
V_121 = F_281 ( V_2 ) ;
break;
}
case V_690 : {
struct V_691 T_14 * V_575 = V_562 ;
struct V_691 V_576 ;
V_121 = - V_101 ;
if ( F_240 ( & V_576 , V_575 , sizeof V_576 ) )
goto V_113;
V_121 = F_309 ( V_2 , & V_576 , V_575 -> V_483 ) ;
break;
}
case V_692 : {
struct V_574 T_14 * V_575 = V_562 ;
struct V_574 V_576 ;
V_121 = - V_101 ;
if ( F_240 ( & V_576 , V_575 , sizeof V_576 ) )
goto V_113;
V_121 = F_310 ( V_2 , & V_576 ,
V_575 -> V_483 ) ;
break;
}
case V_693 : {
struct V_574 T_14 * V_575 = V_562 ;
struct V_574 V_576 ;
V_121 = - V_101 ;
if ( F_240 ( & V_576 , V_575 , sizeof V_576 ) )
goto V_113;
V_121 = F_311 ( V_2 , & V_576 ,
V_575 -> V_483 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_241 ( V_575 , & V_576 , sizeof V_576 ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_694 :
V_121 = F_239 ( V_2 , V_562 , F_115 , 1 ) ;
break;
case V_695 :
V_121 = F_239 ( V_2 , V_562 , F_117 , 0 ) ;
break;
case V_696 : {
struct V_601 V_602 ;
V_121 = - V_101 ;
if ( F_240 ( & V_602 , V_562 , sizeof V_602 ) )
goto V_113;
V_121 = F_282 ( V_2 , & V_602 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_241 ( V_562 , & V_602 , sizeof V_602 ) )
goto V_113;
V_121 = 0 ;
break;
} ;
case V_697 : {
struct V_698 V_699 ;
int V_484 ;
V_121 = - V_579 ;
if ( ! F_91 ( V_2 ) )
goto V_113;
V_121 = - V_101 ;
if ( F_240 ( & V_699 , V_562 , sizeof V_699 ) )
goto V_113;
V_484 = F_237 ( & V_2 -> V_139 -> V_485 ) ;
V_121 = F_312 ( V_2 , V_699 . V_700 ) ;
F_238 ( & V_2 -> V_139 -> V_485 , V_484 ) ;
break;
}
case V_701 : {
T_2 V_365 ;
V_121 = - V_101 ;
if ( F_240 ( & V_365 , V_562 , sizeof V_365 ) )
goto V_113;
V_121 = F_283 ( V_2 , V_365 ) ;
break;
}
case V_702 : {
struct V_607 V_608 ;
V_121 = - V_101 ;
if ( F_240 ( & V_608 , V_562 , sizeof V_608 ) )
goto V_113;
V_121 = F_284 ( V_2 , & V_608 ) ;
break;
}
case V_703 : {
struct V_617 V_618 ;
F_285 ( V_2 , & V_618 ) ;
V_121 = - V_101 ;
if ( F_241 ( V_562 , & V_618 , sizeof( struct V_617 ) ) )
break;
V_121 = 0 ;
break;
}
case V_704 : {
struct V_617 V_618 ;
V_121 = - V_101 ;
if ( F_240 ( & V_618 , V_562 , sizeof( struct V_617 ) ) )
break;
V_121 = F_290 ( V_2 , & V_618 ) ;
break;
}
case V_705 : {
struct V_649 V_650 ;
F_292 ( V_2 , & V_650 ) ;
V_121 = - V_101 ;
if ( F_241 ( V_562 , & V_650 ,
sizeof( struct V_649 ) ) )
break;
V_121 = 0 ;
break;
}
case V_706 : {
struct V_649 V_650 ;
V_121 = - V_101 ;
if ( F_240 ( & V_650 , V_562 ,
sizeof( struct V_649 ) ) )
break;
V_121 = F_293 ( V_2 , & V_650 ) ;
break;
}
case V_707 : {
V_683 . V_653 = F_308 ( sizeof( struct V_668 ) , V_685 ) ;
V_121 = - V_386 ;
if ( ! V_683 . V_653 )
break;
F_299 ( V_2 , V_683 . V_653 ) ;
V_121 = - V_101 ;
if ( F_241 ( V_562 , V_683 . V_653 , sizeof( struct V_668 ) ) )
break;
V_121 = 0 ;
break;
}
case V_708 : {
V_683 . V_653 = F_205 ( V_562 , sizeof( * V_683 . V_653 ) ) ;
if ( F_206 ( V_683 . V_653 ) )
return F_207 ( V_683 . V_653 ) ;
V_121 = F_300 ( V_2 , V_683 . V_653 ) ;
break;
}
case V_709 : {
V_683 . V_676 = F_308 ( sizeof( struct V_673 ) , V_685 ) ;
V_121 = - V_386 ;
if ( ! V_683 . V_676 )
break;
F_302 ( V_2 , V_683 . V_676 ) ;
V_121 = - V_101 ;
if ( F_241 ( V_562 , V_683 . V_676 ,
sizeof( struct V_673 ) ) )
break;
V_121 = 0 ;
break;
}
case V_710 : {
V_683 . V_676 = F_205 ( V_562 , sizeof( * V_683 . V_676 ) ) ;
if ( F_206 ( V_683 . V_676 ) )
return F_207 ( V_683 . V_676 ) ;
V_121 = F_303 ( V_2 , V_683 . V_676 ) ;
break;
}
case V_711 : {
T_1 V_266 ;
V_121 = - V_579 ;
V_266 = ( T_1 ) V_561 ;
if ( V_266 >= V_712 )
goto V_113;
if ( V_266 == 0 )
V_266 = V_272 ;
if ( ! F_140 ( V_2 , V_266 ) )
V_121 = 0 ;
goto V_113;
}
case V_713 : {
V_121 = V_2 -> V_5 . V_283 ;
goto V_113;
}
case V_714 : {
V_121 = F_304 ( V_2 ) ;
goto V_113;
}
case V_715 : {
struct V_678 V_679 ;
V_121 = - V_101 ;
if ( F_240 ( & V_679 , V_562 , sizeof( V_679 ) ) )
goto V_113;
V_121 = F_305 ( V_2 , & V_679 ) ;
break;
}
default:
V_121 = - V_579 ;
}
V_113:
F_209 ( V_683 . V_682 ) ;
return V_121 ;
}
int F_313 ( struct V_1 * V_2 , struct V_716 * V_717 )
{
return V_718 ;
}
static int F_314 ( struct V_139 * V_139 , unsigned long V_615 )
{
int V_108 ;
if ( V_615 > ( unsigned int ) ( - 3 * V_107 ) )
return - V_579 ;
V_108 = V_87 -> V_719 ( V_139 , V_615 ) ;
return V_108 ;
}
static int F_315 ( struct V_139 * V_139 ,
T_2 V_720 )
{
V_139 -> V_5 . V_721 = V_720 ;
return 0 ;
}
static int F_316 ( struct V_139 * V_139 ,
T_1 V_722 )
{
if ( V_722 < V_723 )
return - V_579 ;
F_317 ( & V_139 -> V_724 ) ;
F_318 ( V_139 , V_722 ) ;
V_139 -> V_5 . V_725 = V_722 ;
F_319 ( & V_139 -> V_724 ) ;
return 0 ;
}
static int F_320 ( struct V_139 * V_139 )
{
return V_139 -> V_5 . V_726 ;
}
static int F_321 ( struct V_139 * V_139 , struct V_727 * V_728 )
{
int V_121 ;
V_121 = 0 ;
switch ( V_728 -> V_729 ) {
case V_730 :
memcpy ( & V_728 -> V_728 . V_731 ,
& F_322 ( V_139 ) -> V_732 [ 0 ] ,
sizeof( struct V_733 ) ) ;
break;
case V_734 :
memcpy ( & V_728 -> V_728 . V_731 ,
& F_322 ( V_139 ) -> V_732 [ 1 ] ,
sizeof( struct V_733 ) ) ;
break;
case V_735 :
V_121 = F_323 ( V_139 , & V_728 -> V_728 . V_736 ) ;
break;
default:
V_121 = - V_579 ;
break;
}
return V_121 ;
}
static int F_324 ( struct V_139 * V_139 , struct V_727 * V_728 )
{
int V_121 ;
V_121 = 0 ;
switch ( V_728 -> V_729 ) {
case V_730 :
F_161 ( & F_322 ( V_139 ) -> V_737 ) ;
memcpy ( & F_322 ( V_139 ) -> V_732 [ 0 ] ,
& V_728 -> V_728 . V_731 ,
sizeof( struct V_733 ) ) ;
F_162 ( & F_322 ( V_139 ) -> V_737 ) ;
break;
case V_734 :
F_161 ( & F_322 ( V_139 ) -> V_737 ) ;
memcpy ( & F_322 ( V_139 ) -> V_732 [ 1 ] ,
& V_728 -> V_728 . V_731 ,
sizeof( struct V_733 ) ) ;
F_162 ( & F_322 ( V_139 ) -> V_737 ) ;
break;
case V_735 :
V_121 = F_325 ( V_139 , & V_728 -> V_728 . V_736 ) ;
break;
default:
V_121 = - V_579 ;
break;
}
F_326 ( F_322 ( V_139 ) ) ;
return V_121 ;
}
static int F_327 ( struct V_139 * V_139 , struct V_738 * V_739 )
{
struct V_740 * V_741 = & V_139 -> V_5 . V_742 -> V_743 ;
F_188 ( sizeof( * V_739 ) != sizeof( V_741 -> V_744 ) ) ;
F_317 ( & V_741 -> V_737 ) ;
memcpy ( V_739 , & V_741 -> V_744 , sizeof( * V_739 ) ) ;
F_319 ( & V_741 -> V_737 ) ;
return 0 ;
}
static int F_328 ( struct V_139 * V_139 , struct V_738 * V_739 )
{
int V_3 ;
struct V_745 * V_746 = V_139 -> V_5 . V_742 ;
F_317 ( & V_746 -> V_743 . V_737 ) ;
memcpy ( & V_746 -> V_743 . V_744 , V_739 , sizeof( * V_739 ) ) ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
F_329 ( V_746 , V_3 , V_739 -> V_744 [ V_3 ] . V_747 , 0 ) ;
F_319 ( & V_746 -> V_743 . V_737 ) ;
return 0 ;
}
static int F_330 ( struct V_139 * V_139 , struct V_748 * V_739 )
{
F_317 ( & V_139 -> V_5 . V_742 -> V_743 . V_737 ) ;
memcpy ( V_739 -> V_744 , & V_139 -> V_5 . V_742 -> V_743 . V_744 ,
sizeof( V_739 -> V_744 ) ) ;
V_739 -> V_15 = V_139 -> V_5 . V_742 -> V_743 . V_15 ;
F_319 ( & V_139 -> V_5 . V_742 -> V_743 . V_737 ) ;
memset ( & V_739 -> V_641 , 0 , sizeof( V_739 -> V_641 ) ) ;
return 0 ;
}
static int F_331 ( struct V_139 * V_139 , struct V_748 * V_739 )
{
int V_749 = 0 ;
int V_3 ;
T_1 V_750 , V_751 ;
struct V_745 * V_746 = V_139 -> V_5 . V_742 ;
F_317 ( & V_746 -> V_743 . V_737 ) ;
V_750 = V_746 -> V_743 . V_15 & V_752 ;
V_751 = V_739 -> V_15 & V_752 ;
if ( ! V_750 && V_751 )
V_749 = 1 ;
memcpy ( & V_746 -> V_743 . V_744 , & V_739 -> V_744 ,
sizeof( V_746 -> V_743 . V_744 ) ) ;
V_746 -> V_743 . V_15 = V_739 -> V_15 ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
F_329 ( V_746 , V_3 , V_746 -> V_743 . V_744 [ V_3 ] . V_747 ,
V_749 && V_3 == 0 ) ;
F_319 ( & V_746 -> V_743 . V_737 ) ;
return 0 ;
}
static int F_332 ( struct V_139 * V_139 ,
struct V_753 * V_754 )
{
struct V_745 * V_746 = V_139 -> V_5 . V_742 ;
if ( ! V_746 )
return - V_597 ;
F_317 ( & V_746 -> V_743 . V_737 ) ;
F_333 ( V_746 , V_754 -> V_755 ) ;
F_319 ( & V_746 -> V_743 . V_737 ) ;
return 0 ;
}
int F_334 ( struct V_139 * V_139 , struct V_756 * log )
{
bool V_757 = false ;
int V_121 ;
F_317 ( & V_139 -> V_724 ) ;
if ( V_87 -> V_758 )
V_87 -> V_758 ( V_139 ) ;
V_121 = F_335 ( V_139 , log , & V_757 ) ;
F_336 ( & V_139 -> V_724 ) ;
if ( V_757 )
F_337 ( V_139 ) ;
F_319 ( & V_139 -> V_724 ) ;
return V_121 ;
}
int F_338 ( struct V_139 * V_139 , struct V_759 * V_760 ,
bool V_761 )
{
if ( ! F_277 ( V_139 ) )
return - V_597 ;
V_760 -> V_459 = F_339 ( V_139 , V_762 ,
V_760 -> V_595 , V_760 -> V_763 ,
V_761 ) ;
return 0 ;
}
static int F_340 ( struct V_139 * V_139 ,
struct V_678 * V_679 )
{
int V_121 ;
if ( V_679 -> V_15 )
return - V_579 ;
switch ( V_679 -> V_679 ) {
case V_530 :
V_139 -> V_5 . V_764 = V_679 -> args [ 0 ] ;
V_121 = 0 ;
break;
case V_532 : {
F_317 ( & V_139 -> V_737 ) ;
V_121 = - V_579 ;
if ( V_679 -> args [ 0 ] > V_765 )
goto V_766;
V_121 = - V_599 ;
if ( F_277 ( V_139 ) )
goto V_766;
if ( V_139 -> V_767 )
goto V_766;
V_121 = F_341 ( V_139 ) ;
if ( V_121 )
goto V_766;
F_191 () ;
V_139 -> V_5 . V_768 = true ;
V_139 -> V_5 . V_769 = V_679 -> args [ 0 ] ;
V_121 = 0 ;
V_766:
F_319 ( & V_139 -> V_737 ) ;
break;
}
case V_556 :
V_121 = - V_579 ;
if ( V_679 -> args [ 0 ] & ~ V_557 )
break;
if ( V_679 -> args [ 0 ] & V_770 )
V_139 -> V_5 . V_771 = true ;
if ( V_679 -> args [ 0 ] & V_772 )
V_139 -> V_5 . V_773 = true ;
V_121 = 0 ;
break;
default:
V_121 = - V_579 ;
break;
}
return V_121 ;
}
long F_342 ( struct V_558 * V_559 ,
unsigned int V_560 , unsigned long V_561 )
{
struct V_139 * V_139 = V_559 -> V_680 ;
void T_14 * V_562 = ( void T_14 * ) V_561 ;
int V_121 = - V_774 ;
union {
struct V_738 V_739 ;
struct V_748 V_775 ;
struct V_776 V_777 ;
} V_683 ;
switch ( V_560 ) {
case V_778 :
V_121 = F_314 ( V_139 , V_561 ) ;
break;
case V_779 : {
T_2 V_720 ;
V_121 = - V_101 ;
if ( F_240 ( & V_720 , V_562 , sizeof V_720 ) )
goto V_113;
V_121 = F_315 ( V_139 , V_720 ) ;
break;
}
case V_780 :
V_121 = F_316 ( V_139 , V_561 ) ;
break;
case V_781 :
V_121 = F_320 ( V_139 ) ;
break;
case V_782 : {
struct V_783 * V_784 ;
F_317 ( & V_139 -> V_737 ) ;
V_121 = - V_599 ;
if ( V_139 -> V_5 . V_784 )
goto V_785;
V_121 = - V_579 ;
if ( V_139 -> V_767 )
goto V_785;
V_121 = - V_386 ;
V_784 = F_343 ( V_139 ) ;
if ( V_784 ) {
V_121 = F_344 ( V_139 ) ;
if ( V_121 ) {
F_317 ( & V_139 -> V_724 ) ;
F_345 ( V_784 ) ;
F_319 ( & V_139 -> V_724 ) ;
goto V_785;
}
} else
goto V_785;
V_121 = F_346 ( V_139 ) ;
if ( V_121 ) {
F_317 ( & V_139 -> V_724 ) ;
F_317 ( & V_139 -> V_786 ) ;
F_347 ( V_139 ) ;
F_345 ( V_784 ) ;
F_319 ( & V_139 -> V_786 ) ;
F_319 ( & V_139 -> V_724 ) ;
goto V_785;
}
F_191 () ;
V_139 -> V_5 . V_784 = V_784 ;
V_785:
F_319 ( & V_139 -> V_737 ) ;
break;
}
case V_787 :
V_683 . V_777 . V_15 = V_788 ;
goto V_789;
case V_790 :
V_121 = - V_101 ;
if ( F_240 ( & V_683 . V_777 , V_562 ,
sizeof( struct V_776 ) ) )
goto V_113;
V_789:
F_317 ( & V_139 -> V_737 ) ;
V_121 = - V_599 ;
if ( V_139 -> V_5 . V_742 )
goto V_791;
V_121 = - V_386 ;
V_139 -> V_5 . V_742 = F_348 ( V_139 , V_683 . V_777 . V_15 ) ;
if ( V_139 -> V_5 . V_742 )
V_121 = 0 ;
V_791:
F_319 ( & V_139 -> V_737 ) ;
break;
case V_792 : {
struct V_727 * V_728 ;
V_728 = F_205 ( V_562 , sizeof( * V_728 ) ) ;
if ( F_206 ( V_728 ) ) {
V_121 = F_207 ( V_728 ) ;
goto V_113;
}
V_121 = - V_597 ;
if ( ! F_277 ( V_139 ) || V_768 ( V_139 ) )
goto V_793;
V_121 = F_321 ( V_139 , V_728 ) ;
if ( V_121 )
goto V_793;
V_121 = - V_101 ;
if ( F_241 ( V_562 , V_728 , sizeof *V_728 ) )
goto V_793;
V_121 = 0 ;
V_793:
F_209 ( V_728 ) ;
break;
}
case V_794 : {
struct V_727 * V_728 ;
V_728 = F_205 ( V_562 , sizeof( * V_728 ) ) ;
if ( F_206 ( V_728 ) ) {
V_121 = F_207 ( V_728 ) ;
goto V_113;
}
V_121 = - V_597 ;
if ( ! F_277 ( V_139 ) || V_768 ( V_139 ) )
goto V_795;
V_121 = F_324 ( V_139 , V_728 ) ;
if ( V_121 )
goto V_795;
V_121 = 0 ;
V_795:
F_209 ( V_728 ) ;
break;
}
case V_796 : {
V_121 = - V_101 ;
if ( F_240 ( & V_683 . V_739 , V_562 , sizeof( struct V_738 ) ) )
goto V_113;
V_121 = - V_597 ;
if ( ! V_139 -> V_5 . V_742 )
goto V_113;
V_121 = F_327 ( V_139 , & V_683 . V_739 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_241 ( V_562 , & V_683 . V_739 , sizeof( struct V_738 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_797 : {
V_121 = - V_101 ;
if ( F_240 ( & V_683 . V_739 , V_562 , sizeof V_683 . V_739 ) )
goto V_113;
V_121 = - V_597 ;
if ( ! V_139 -> V_5 . V_742 )
goto V_113;
V_121 = F_328 ( V_139 , & V_683 . V_739 ) ;
break;
}
case V_798 : {
V_121 = - V_597 ;
if ( ! V_139 -> V_5 . V_742 )
goto V_113;
V_121 = F_330 ( V_139 , & V_683 . V_775 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_241 ( V_562 , & V_683 . V_775 , sizeof( V_683 . V_775 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_799 : {
V_121 = - V_101 ;
if ( F_240 ( & V_683 . V_775 , V_562 , sizeof( V_683 . V_775 ) ) )
goto V_113;
V_121 = - V_597 ;
if ( ! V_139 -> V_5 . V_742 )
goto V_113;
V_121 = F_331 ( V_139 , & V_683 . V_775 ) ;
break;
}
case V_800 : {
struct V_753 V_754 ;
V_121 = - V_101 ;
if ( F_240 ( & V_754 , V_562 , sizeof( V_754 ) ) )
goto V_113;
V_121 = F_332 ( V_139 , & V_754 ) ;
break;
}
case V_801 :
V_121 = 0 ;
F_317 ( & V_139 -> V_737 ) ;
if ( V_139 -> V_767 )
V_121 = - V_802 ;
else
V_139 -> V_5 . V_803 = V_561 ;
F_319 ( & V_139 -> V_737 ) ;
break;
case V_804 : {
V_121 = - V_101 ;
if ( F_240 ( & V_139 -> V_5 . F_204 , V_562 ,
sizeof( struct V_805 ) ) )
goto V_113;
V_121 = - V_579 ;
if ( V_139 -> V_5 . F_204 . V_15 )
goto V_113;
V_121 = 0 ;
break;
}
case V_806 : {
struct V_807 V_808 ;
T_2 V_809 ;
V_121 = - V_101 ;
if ( F_240 ( & V_808 , V_562 , sizeof( V_808 ) ) )
goto V_113;
V_121 = - V_579 ;
if ( V_808 . V_15 )
goto V_113;
V_121 = 0 ;
F_349 () ;
V_809 = F_182 ( V_139 ) ;
V_139 -> V_5 . V_247 += V_808 . clock - V_809 ;
F_350 () ;
F_179 ( V_139 ) ;
break;
}
case V_810 : {
struct V_807 V_808 ;
T_2 V_809 ;
F_349 () ;
V_809 = F_182 ( V_139 ) ;
V_808 . clock = V_809 ;
V_808 . V_15 = V_139 -> V_5 . V_295 ? V_536 : 0 ;
F_350 () ;
memset ( & V_808 . V_620 , 0 , sizeof( V_808 . V_620 ) ) ;
V_121 = - V_101 ;
if ( F_241 ( V_562 , & V_808 , sizeof( V_808 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_715 : {
struct V_678 V_679 ;
V_121 = - V_101 ;
if ( F_240 ( & V_679 , V_562 , sizeof( V_679 ) ) )
goto V_113;
V_121 = F_340 ( V_139 , & V_679 ) ;
break;
}
default:
V_121 = F_351 ( V_139 , V_560 , V_561 ) ;
}
V_113:
return V_121 ;
}
static void F_352 ( void )
{
T_1 V_811 [ 2 ] ;
unsigned V_3 , V_812 ;
for ( V_3 = V_812 = 0 ; V_3 < F_55 ( V_570 ) ; V_3 ++ ) {
if ( F_353 ( V_570 [ V_3 ] , & V_811 [ 0 ] , & V_811 [ 1 ] ) < 0 )
continue;
switch ( V_570 [ V_3 ] ) {
case V_813 :
if ( ! V_87 -> V_814 () )
continue;
break;
case V_815 :
if ( ! V_87 -> V_816 () )
continue;
break;
default:
break;
}
if ( V_812 < V_3 )
V_570 [ V_812 ] = V_570 [ V_3 ] ;
V_812 ++ ;
}
V_567 = V_812 ;
for ( V_3 = V_812 = 0 ; V_3 < F_55 ( V_571 ) ; V_3 ++ ) {
switch ( V_571 [ V_3 ] ) {
case V_423 :
if ( ! V_87 -> V_538 () )
continue;
break;
default:
break;
}
if ( V_812 < V_3 )
V_571 [ V_812 ] = V_571 [ V_3 ] ;
V_812 ++ ;
}
V_568 = V_812 ;
}
static int F_354 ( struct V_1 * V_2 , T_6 V_615 , int V_95 ,
const void * V_265 )
{
int V_817 = 0 ;
int V_489 ;
do {
V_489 = F_355 ( V_95 , 8 ) ;
if ( ! ( F_91 ( V_2 ) &&
! F_356 ( V_2 , & V_2 -> V_5 . V_645 -> V_818 , V_615 , V_489 , V_265 ) )
&& F_357 ( V_2 , V_819 , V_615 , V_489 , V_265 ) )
break;
V_817 += V_489 ;
V_615 += V_489 ;
V_95 -= V_489 ;
V_265 += V_489 ;
} while ( V_95 );
return V_817 ;
}
static int F_358 ( struct V_1 * V_2 , T_6 V_615 , int V_95 , void * V_265 )
{
int V_817 = 0 ;
int V_489 ;
do {
V_489 = F_355 ( V_95 , 8 ) ;
if ( ! ( F_91 ( V_2 ) &&
! F_359 ( V_2 , & V_2 -> V_5 . V_645 -> V_818 ,
V_615 , V_489 , V_265 ) )
&& F_360 ( V_2 , V_819 , V_615 , V_489 , V_265 ) )
break;
F_361 ( V_820 , V_489 , V_615 , * ( T_2 * ) V_265 ) ;
V_817 += V_489 ;
V_615 += V_489 ;
V_95 -= V_489 ;
V_265 += V_489 ;
} while ( V_95 );
return V_817 ;
}
static void F_362 ( struct V_1 * V_2 ,
struct V_821 * V_822 , int V_823 )
{
V_87 -> V_824 ( V_2 , V_822 , V_823 ) ;
}
void F_363 ( struct V_1 * V_2 ,
struct V_821 * V_822 , int V_823 )
{
V_87 -> V_825 ( V_2 , V_822 , V_823 ) ;
}
T_6 F_364 ( struct V_1 * V_2 , T_6 V_388 , T_1 V_96 ,
struct V_74 * V_69 )
{
T_6 V_826 ;
F_15 ( ! F_42 ( V_2 ) ) ;
V_96 |= V_111 ;
V_826 = V_2 -> V_5 . V_83 . V_827 ( V_2 , V_388 , V_96 , V_69 ) ;
return V_826 ;
}
T_6 F_365 ( struct V_1 * V_2 , T_15 V_828 ,
struct V_74 * V_69 )
{
T_1 V_96 = ( V_87 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
return V_2 -> V_5 . V_103 -> V_827 ( V_2 , V_828 , V_96 , V_69 ) ;
}
T_6 F_366 ( struct V_1 * V_2 , T_15 V_828 ,
struct V_74 * V_69 )
{
T_1 V_96 = ( V_87 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
V_96 |= V_829 ;
return V_2 -> V_5 . V_103 -> V_827 ( V_2 , V_828 , V_96 , V_69 ) ;
}
T_6 F_367 ( struct V_1 * V_2 , T_15 V_828 ,
struct V_74 * V_69 )
{
T_1 V_96 = ( V_87 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
V_96 |= V_112 ;
return V_2 -> V_5 . V_103 -> V_827 ( V_2 , V_828 , V_96 , V_69 ) ;
}
T_6 F_368 ( struct V_1 * V_2 , T_15 V_828 ,
struct V_74 * V_69 )
{
return V_2 -> V_5 . V_103 -> V_827 ( V_2 , V_828 , 0 , V_69 ) ;
}
static int F_369 ( T_15 V_615 , void * V_196 , unsigned int V_830 ,
struct V_1 * V_2 , T_1 V_96 ,
struct V_74 * V_69 )
{
void * V_39 = V_196 ;
int V_121 = V_831 ;
while ( V_830 ) {
T_6 V_388 = V_2 -> V_5 . V_103 -> V_827 ( V_2 , V_615 , V_96 ,
V_69 ) ;
unsigned V_94 = V_615 & ( V_107 - 1 ) ;
unsigned V_832 = F_355 ( V_830 , ( unsigned ) V_107 - V_94 ) ;
int V_108 ;
if ( V_388 == V_100 )
return V_833 ;
V_108 = F_52 ( V_2 , V_388 >> V_106 , V_39 ,
V_94 , V_832 ) ;
if ( V_108 < 0 ) {
V_121 = V_834 ;
goto V_113;
}
V_830 -= V_832 ;
V_39 += V_832 ;
V_615 += V_832 ;
}
V_113:
return V_121 ;
}
static int F_370 ( struct V_835 * V_836 ,
T_15 V_615 , void * V_196 , unsigned int V_830 ,
struct V_74 * V_69 )
{
struct V_1 * V_2 = F_371 ( V_836 ) ;
T_1 V_96 = ( V_87 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
unsigned V_94 ;
int V_108 ;
T_6 V_388 = V_2 -> V_5 . V_103 -> V_827 ( V_2 , V_615 , V_96 | V_829 ,
V_69 ) ;
if ( F_171 ( V_388 == V_100 ) )
return V_833 ;
V_94 = V_615 & ( V_107 - 1 ) ;
if ( F_30 ( V_94 + V_830 > V_107 ) )
V_830 = ( unsigned ) V_107 - V_94 ;
V_108 = F_52 ( V_2 , V_388 >> V_106 , V_196 ,
V_94 , V_830 ) ;
if ( F_171 ( V_108 < 0 ) )
return V_834 ;
return V_831 ;
}
int F_372 ( struct V_835 * V_836 ,
T_15 V_615 , void * V_196 , unsigned int V_830 ,
struct V_74 * V_69 )
{
struct V_1 * V_2 = F_371 ( V_836 ) ;
T_1 V_96 = ( V_87 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
return F_369 ( V_615 , V_196 , V_830 , V_2 , V_96 ,
V_69 ) ;
}
static int F_373 ( struct V_835 * V_836 ,
T_15 V_615 , void * V_196 , unsigned int V_830 ,
struct V_74 * V_69 )
{
struct V_1 * V_2 = F_371 ( V_836 ) ;
return F_369 ( V_615 , V_196 , V_830 , V_2 , 0 , V_69 ) ;
}
static int F_374 ( struct V_835 * V_836 ,
unsigned long V_615 , void * V_196 , unsigned int V_830 )
{
struct V_1 * V_2 = F_371 ( V_836 ) ;
int V_121 = F_375 ( V_2 , V_615 , V_196 , V_830 ) ;
return V_121 < 0 ? V_834 : V_831 ;
}
int F_376 ( struct V_835 * V_836 ,
T_15 V_615 , void * V_196 ,
unsigned int V_830 ,
struct V_74 * V_69 )
{
struct V_1 * V_2 = F_371 ( V_836 ) ;
void * V_39 = V_196 ;
int V_121 = V_831 ;
while ( V_830 ) {
T_6 V_388 = V_2 -> V_5 . V_103 -> V_827 ( V_2 , V_615 ,
V_112 ,
V_69 ) ;
unsigned V_94 = V_615 & ( V_107 - 1 ) ;
unsigned V_837 = F_355 ( V_830 , ( unsigned ) V_107 - V_94 ) ;
int V_108 ;
if ( V_388 == V_100 )
return V_833 ;
V_108 = F_208 ( V_2 , V_388 , V_39 , V_837 ) ;
if ( V_108 < 0 ) {
V_121 = V_834 ;
goto V_113;
}
V_830 -= V_837 ;
V_39 += V_837 ;
V_615 += V_837 ;
}
V_113:
return V_121 ;
}
static int F_377 ( struct V_1 * V_2 , unsigned long V_828 ,
T_6 * V_388 , struct V_74 * V_69 ,
bool V_838 )
{
T_1 V_96 = ( ( V_87 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 )
| ( V_838 ? V_112 : 0 ) ;
if ( F_378 ( V_2 , V_828 )
&& ! F_379 ( V_2 , V_2 -> V_5 . V_103 ,
V_2 -> V_5 . V_96 , 0 , V_96 ) ) {
* V_388 = V_2 -> V_5 . V_839 << V_106 |
( V_828 & ( V_107 - 1 ) ) ;
F_380 ( V_828 , * V_388 , V_838 , false ) ;
return 1 ;
}
* V_388 = V_2 -> V_5 . V_103 -> V_827 ( V_2 , V_828 , V_96 , V_69 ) ;
if ( * V_388 == V_100 )
return - 1 ;
if ( ( * V_388 & V_382 ) == V_840 )
return 1 ;
if ( F_381 ( V_2 , * V_388 ) ) {
F_380 ( V_828 , * V_388 , V_838 , true ) ;
return 1 ;
}
return 0 ;
}
int F_382 ( struct V_1 * V_2 , T_6 V_388 ,
const void * V_196 , int V_830 )
{
int V_108 ;
V_108 = F_208 ( V_2 , V_388 , V_196 , V_830 ) ;
if ( V_108 < 0 )
return 0 ;
F_383 ( V_2 , V_388 , V_196 , V_830 ) ;
return 1 ;
}
static int F_384 ( struct V_1 * V_2 , void * V_196 , int V_830 )
{
if ( V_2 -> V_841 ) {
F_361 ( V_820 , V_830 ,
V_2 -> V_842 [ 0 ] . V_388 , * ( T_2 * ) V_196 ) ;
V_2 -> V_841 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_385 ( struct V_1 * V_2 , T_6 V_388 ,
void * V_196 , int V_830 )
{
return ! F_375 ( V_2 , V_388 , V_196 , V_830 ) ;
}
static int F_386 ( struct V_1 * V_2 , T_6 V_388 ,
void * V_196 , int V_830 )
{
return F_382 ( V_2 , V_388 , V_196 , V_830 ) ;
}
static int F_387 ( struct V_1 * V_2 , T_6 V_388 , int V_830 , void * V_196 )
{
F_361 ( V_843 , V_830 , V_388 , * ( T_2 * ) V_196 ) ;
return F_354 ( V_2 , V_388 , V_830 , V_196 ) ;
}
static int F_388 ( struct V_1 * V_2 , T_6 V_388 ,
void * V_196 , int V_830 )
{
F_361 ( V_844 , V_830 , V_388 , 0 ) ;
return V_834 ;
}
static int F_389 ( struct V_1 * V_2 , T_6 V_388 ,
void * V_196 , int V_830 )
{
struct V_845 * V_846 = & V_2 -> V_842 [ 0 ] ;
memcpy ( V_2 -> V_847 -> V_848 . V_39 , V_846 -> V_39 , F_355 ( 8u , V_846 -> V_95 ) ) ;
return V_831 ;
}
static int F_390 ( unsigned long V_615 , void * V_196 ,
unsigned int V_830 ,
struct V_74 * V_69 ,
struct V_1 * V_2 ,
const struct V_849 * V_850 )
{
T_6 V_388 ;
int V_817 , V_108 ;
bool V_838 = V_850 -> V_838 ;
struct V_845 * V_846 ;
V_108 = F_377 ( V_2 , V_615 , & V_388 , V_69 , V_838 ) ;
if ( V_108 < 0 )
return V_833 ;
if ( V_108 )
goto V_848;
if ( V_850 -> V_851 ( V_2 , V_388 , V_196 , V_830 ) )
return V_831 ;
V_848:
V_817 = V_850 -> V_852 ( V_2 , V_388 , V_830 , V_196 ) ;
if ( V_817 == V_830 )
return V_831 ;
V_388 += V_817 ;
V_830 -= V_817 ;
V_196 += V_817 ;
F_30 ( V_2 -> V_853 >= V_854 ) ;
V_846 = & V_2 -> V_842 [ V_2 -> V_853 ++ ] ;
V_846 -> V_388 = V_388 ;
V_846 -> V_39 = V_196 ;
V_846 -> V_95 = V_830 ;
return V_831 ;
}
static int F_391 ( struct V_835 * V_836 ,
unsigned long V_615 ,
void * V_196 , unsigned int V_830 ,
struct V_74 * V_69 ,
const struct V_849 * V_850 )
{
struct V_1 * V_2 = F_371 ( V_836 ) ;
T_6 V_388 ;
int V_855 ;
if ( V_850 -> V_856 &&
V_850 -> V_856 ( V_2 , V_196 , V_830 ) )
return V_831 ;
V_2 -> V_853 = 0 ;
if ( ( ( V_615 + V_830 - 1 ) ^ V_615 ) & V_382 ) {
int V_857 ;
V_857 = - V_615 & ~ V_382 ;
V_855 = F_390 ( V_615 , V_196 , V_857 , V_69 ,
V_2 , V_850 ) ;
if ( V_855 != V_831 )
return V_855 ;
V_615 += V_857 ;
if ( V_836 -> V_329 != V_858 )
V_615 = ( T_1 ) V_615 ;
V_196 += V_857 ;
V_830 -= V_857 ;
}
V_855 = F_390 ( V_615 , V_196 , V_830 , V_69 ,
V_2 , V_850 ) ;
if ( V_855 != V_831 )
return V_855 ;
if ( ! V_2 -> V_853 )
return V_855 ;
V_388 = V_2 -> V_842 [ 0 ] . V_388 ;
V_2 -> V_859 = 1 ;
V_2 -> V_860 = 0 ;
V_2 -> V_847 -> V_848 . V_95 = F_355 ( 8u , V_2 -> V_842 [ 0 ] . V_95 ) ;
V_2 -> V_847 -> V_848 . V_861 = V_2 -> V_862 = V_850 -> V_838 ;
V_2 -> V_847 -> V_863 = V_864 ;
V_2 -> V_847 -> V_848 . V_865 = V_388 ;
return V_850 -> V_866 ( V_2 , V_388 , V_196 , V_830 ) ;
}
static int F_392 ( struct V_835 * V_836 ,
unsigned long V_615 ,
void * V_196 ,
unsigned int V_830 ,
struct V_74 * V_69 )
{
return F_391 ( V_836 , V_615 , V_196 , V_830 ,
V_69 , & V_867 ) ;
}
static int F_393 ( struct V_835 * V_836 ,
unsigned long V_615 ,
const void * V_196 ,
unsigned int V_830 ,
struct V_74 * V_69 )
{
return F_391 ( V_836 , V_615 , ( void * ) V_196 , V_830 ,
V_69 , & V_868 ) ;
}
static int F_394 ( struct V_835 * V_836 ,
unsigned long V_615 ,
const void * V_869 ,
const void * V_870 ,
unsigned int V_830 ,
struct V_74 * V_69 )
{
struct V_1 * V_2 = F_371 ( V_836 ) ;
T_6 V_388 ;
struct V_384 * V_384 ;
char * V_871 ;
bool V_872 ;
if ( V_830 > 8 || ( V_830 & ( V_830 - 1 ) ) )
goto V_873;
V_388 = F_367 ( V_2 , V_615 , NULL ) ;
if ( V_388 == V_100 ||
( V_388 & V_382 ) == V_840 )
goto V_873;
if ( ( ( V_388 + V_830 - 1 ) & V_382 ) != ( V_388 & V_382 ) )
goto V_873;
V_384 = F_395 ( V_2 , V_388 >> V_106 ) ;
if ( F_396 ( V_384 ) )
goto V_873;
V_871 = F_397 ( V_384 ) ;
V_871 += F_398 ( V_388 ) ;
switch ( V_830 ) {
case 1 :
V_872 = F_399 ( T_13 , V_871 , V_869 , V_870 ) ;
break;
case 2 :
V_872 = F_399 ( V_874 , V_871 , V_869 , V_870 ) ;
break;
case 4 :
V_872 = F_399 ( T_1 , V_871 , V_869 , V_870 ) ;
break;
case 8 :
V_872 = F_400 ( V_871 , V_869 , V_870 ) ;
break;
default:
F_27 () ;
}
F_401 ( V_871 ) ;
F_402 ( V_384 ) ;
if ( ! V_872 )
return V_875 ;
F_403 ( V_2 , V_388 >> V_106 ) ;
F_383 ( V_2 , V_388 , V_870 , V_830 ) ;
return V_831 ;
V_873:
F_404 ( V_876 L_20 ) ;
return F_393 ( V_836 , V_615 , V_870 , V_830 , V_69 ) ;
}
static int F_405 ( struct V_1 * V_2 , void * V_877 )
{
int V_121 ;
if ( V_2 -> V_5 . V_878 . V_879 )
V_121 = F_360 ( V_2 , V_880 , V_2 -> V_5 . V_878 . V_881 ,
V_2 -> V_5 . V_878 . V_490 , V_877 ) ;
else
V_121 = F_357 ( V_2 , V_880 ,
V_2 -> V_5 . V_878 . V_881 , V_2 -> V_5 . V_878 . V_490 ,
V_877 ) ;
return V_121 ;
}
static int F_406 ( struct V_1 * V_2 , int V_490 ,
unsigned short V_881 , void * V_196 ,
unsigned int V_747 , bool V_879 )
{
V_2 -> V_5 . V_878 . V_881 = V_881 ;
V_2 -> V_5 . V_878 . V_879 = V_879 ;
V_2 -> V_5 . V_878 . V_747 = V_747 ;
V_2 -> V_5 . V_878 . V_490 = V_490 ;
if ( ! F_405 ( V_2 , V_2 -> V_5 . V_882 ) ) {
V_2 -> V_5 . V_878 . V_747 = 0 ;
return 1 ;
}
V_2 -> V_847 -> V_863 = V_883 ;
V_2 -> V_847 -> V_884 . V_885 = V_879 ? V_886 : V_887 ;
V_2 -> V_847 -> V_884 . V_490 = V_490 ;
V_2 -> V_847 -> V_884 . V_888 = V_889 * V_107 ;
V_2 -> V_847 -> V_884 . V_747 = V_747 ;
V_2 -> V_847 -> V_884 . V_881 = V_881 ;
return 0 ;
}
static int F_407 ( struct V_835 * V_836 ,
int V_490 , unsigned short V_881 , void * V_196 ,
unsigned int V_747 )
{
struct V_1 * V_2 = F_371 ( V_836 ) ;
int V_108 ;
if ( V_2 -> V_5 . V_878 . V_747 )
goto V_890;
V_108 = F_406 ( V_2 , V_490 , V_881 , V_196 , V_747 , true ) ;
if ( V_108 ) {
V_890:
memcpy ( V_196 , V_2 -> V_5 . V_882 , V_490 * V_747 ) ;
F_408 ( V_891 , V_881 , V_490 , V_747 , V_2 -> V_5 . V_882 ) ;
V_2 -> V_5 . V_878 . V_747 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_409 ( struct V_835 * V_836 ,
int V_490 , unsigned short V_881 ,
const void * V_196 , unsigned int V_747 )
{
struct V_1 * V_2 = F_371 ( V_836 ) ;
memcpy ( V_2 -> V_5 . V_882 , V_196 , V_490 * V_747 ) ;
F_408 ( V_892 , V_881 , V_490 , V_747 , V_2 -> V_5 . V_882 ) ;
return F_406 ( V_2 , V_490 , V_881 , ( void * ) V_196 , V_747 , false ) ;
}
static unsigned long F_410 ( struct V_1 * V_2 , int V_823 )
{
return V_87 -> F_410 ( V_2 , V_823 ) ;
}
static void F_411 ( struct V_835 * V_836 , V_176 V_79 )
{
F_412 ( F_371 ( V_836 ) , V_79 ) ;
}
static int F_413 ( struct V_1 * V_2 )
{
if ( ! F_250 ( V_2 ) )
return V_831 ;
if ( V_87 -> V_582 () ) {
int V_24 = F_414 () ;
F_253 ( V_24 , V_2 -> V_5 . V_583 ) ;
F_415 ( V_2 -> V_5 . V_583 ,
F_248 , NULL , 1 ) ;
F_416 () ;
F_417 ( V_2 -> V_5 . V_583 ) ;
} else
F_249 () ;
return V_831 ;
}
int F_418 ( struct V_1 * V_2 )
{
F_413 ( V_2 ) ;
return F_38 ( V_2 ) ;
}
static void F_419 ( struct V_835 * V_836 )
{
F_413 ( F_371 ( V_836 ) ) ;
}
static int F_420 ( struct V_835 * V_836 , int V_89 ,
unsigned long * V_651 )
{
return F_102 ( F_371 ( V_836 ) , V_89 , V_651 ) ;
}
static int F_421 ( struct V_835 * V_836 , int V_89 ,
unsigned long V_23 )
{
return F_100 ( F_371 ( V_836 ) , V_89 , V_23 ) ;
}
static T_2 F_422 ( T_2 V_893 , T_1 V_894 )
{
return ( V_893 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_894 ;
}
static unsigned long F_423 ( struct V_835 * V_836 , int V_895 )
{
struct V_1 * V_2 = F_371 ( V_836 ) ;
unsigned long V_23 ;
switch ( V_895 ) {
case 0 :
V_23 = F_63 ( V_2 ) ;
break;
case 2 :
V_23 = V_2 -> V_5 . V_78 ;
break;
case 3 :
V_23 = F_61 ( V_2 ) ;
break;
case 4 :
V_23 = F_80 ( V_2 ) ;
break;
case 8 :
V_23 = F_93 ( V_2 ) ;
break;
default:
F_424 ( L_21 , V_262 , V_895 ) ;
return 0 ;
}
return V_23 ;
}
static int F_425 ( struct V_835 * V_836 , int V_895 , V_176 V_196 )
{
struct V_1 * V_2 = F_371 ( V_836 ) ;
int V_896 = 0 ;
switch ( V_895 ) {
case 0 :
V_896 = F_62 ( V_2 , F_422 ( F_63 ( V_2 ) , V_196 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_78 = V_196 ;
break;
case 3 :
V_896 = F_87 ( V_2 , V_196 ) ;
break;
case 4 :
V_896 = F_79 ( V_2 , F_422 ( F_80 ( V_2 ) , V_196 ) ) ;
break;
case 8 :
V_896 = F_90 ( V_2 , V_196 ) ;
break;
default:
F_424 ( L_21 , V_262 , V_895 ) ;
V_896 = - 1 ;
}
return V_896 ;
}
static int F_426 ( struct V_835 * V_836 )
{
return V_87 -> V_88 ( F_371 ( V_836 ) ) ;
}
static void F_427 ( struct V_835 * V_836 , struct V_897 * V_898 )
{
V_87 -> V_899 ( F_371 ( V_836 ) , V_898 ) ;
}
static void F_428 ( struct V_835 * V_836 , struct V_897 * V_898 )
{
V_87 -> V_900 ( F_371 ( V_836 ) , V_898 ) ;
}
static void F_429 ( struct V_835 * V_836 , struct V_897 * V_898 )
{
V_87 -> V_901 ( F_371 ( V_836 ) , V_898 ) ;
}
static void F_430 ( struct V_835 * V_836 , struct V_897 * V_898 )
{
V_87 -> V_902 ( F_371 ( V_836 ) , V_898 ) ;
}
static unsigned long F_431 (
struct V_835 * V_836 , int V_823 )
{
return F_410 ( F_371 ( V_836 ) , V_823 ) ;
}
static bool F_432 ( struct V_835 * V_836 , V_874 * V_903 ,
struct V_904 * V_905 , T_1 * V_906 ,
int V_823 )
{
struct V_821 V_822 ;
F_363 ( F_371 ( V_836 ) , & V_822 , V_823 ) ;
* V_903 = V_822 . V_903 ;
if ( V_822 . V_907 ) {
memset ( V_905 , 0 , sizeof( * V_905 ) ) ;
return false ;
}
if ( V_822 . V_908 )
V_822 . V_909 >>= 12 ;
F_433 ( V_905 , V_822 . V_909 ) ;
F_434 ( V_905 , ( unsigned long ) V_822 . V_230 ) ;
#ifdef F_64
if ( V_906 )
* V_906 = V_822 . V_230 >> 32 ;
#endif
V_905 -> type = V_822 . type ;
V_905 -> V_591 = V_822 . V_591 ;
V_905 -> V_910 = V_822 . V_910 ;
V_905 -> V_911 = V_822 . V_912 ;
V_905 -> V_913 = V_822 . V_913 ;
V_905 -> V_914 = V_822 . V_914 ;
V_905 -> V_915 = V_822 . V_183 ;
V_905 -> V_908 = V_822 . V_908 ;
return true ;
}
static void F_435 ( struct V_835 * V_836 , V_874 V_903 ,
struct V_904 * V_905 , T_1 V_906 ,
int V_823 )
{
struct V_1 * V_2 = F_371 ( V_836 ) ;
struct V_821 V_822 ;
V_822 . V_903 = V_903 ;
V_822 . V_230 = F_436 ( V_905 ) ;
#ifdef F_64
V_822 . V_230 |= ( ( T_2 ) V_906 ) << 32 ;
#endif
V_822 . V_909 = F_437 ( V_905 ) ;
if ( V_905 -> V_908 )
V_822 . V_909 = ( V_822 . V_909 << 12 ) | 0xfff ;
V_822 . type = V_905 -> type ;
V_822 . V_910 = V_905 -> V_910 ;
V_822 . V_183 = V_905 -> V_915 ;
V_822 . V_591 = V_905 -> V_591 ;
V_822 . V_914 = V_905 -> V_914 ;
V_822 . V_908 = V_905 -> V_908 ;
V_822 . V_913 = V_905 -> V_913 ;
V_822 . V_912 = V_905 -> V_911 ;
V_822 . V_907 = ! V_822 . V_912 ;
V_822 . V_916 = 0 ;
F_362 ( V_2 , & V_822 , V_823 ) ;
return;
}
static int F_438 ( struct V_835 * V_836 ,
T_1 V_917 , T_2 * V_462 )
{
struct V_33 V_22 ;
int V_121 ;
V_22 . V_147 = V_917 ;
V_22 . V_41 = false ;
V_121 = F_116 ( F_371 ( V_836 ) , & V_22 ) ;
if ( V_121 )
return V_121 ;
* V_462 = V_22 . V_39 ;
return 0 ;
}
static int F_439 ( struct V_835 * V_836 ,
T_1 V_917 , T_2 V_39 )
{
struct V_33 V_22 ;
V_22 . V_39 = V_39 ;
V_22 . V_147 = V_917 ;
V_22 . V_41 = false ;
return F_112 ( F_371 ( V_836 ) , & V_22 ) ;
}
static T_2 F_440 ( struct V_835 * V_836 )
{
struct V_1 * V_2 = F_371 ( V_836 ) ;
return V_2 -> V_5 . V_424 ;
}
static void F_441 ( struct V_835 * V_836 , T_2 V_424 )
{
struct V_1 * V_2 = F_371 ( V_836 ) ;
V_2 -> V_5 . V_424 = V_424 ;
}
static int F_442 ( struct V_835 * V_836 ,
T_1 V_918 )
{
return F_443 ( F_371 ( V_836 ) , V_918 ) ;
}
static int F_444 ( struct V_835 * V_836 ,
T_1 V_918 , T_2 * V_462 )
{
return F_105 ( F_371 ( V_836 ) , V_918 , V_462 ) ;
}
static void F_445 ( struct V_835 * V_836 )
{
F_371 ( V_836 ) -> V_5 . V_919 = 1 ;
}
static void F_446 ( struct V_835 * V_836 )
{
F_447 () ;
F_448 ( F_371 ( V_836 ) ) ;
}
static void F_449 ( struct V_835 * V_836 )
{
F_450 () ;
}
static int F_451 ( struct V_835 * V_836 ,
struct V_920 * V_921 ,
enum V_922 V_923 )
{
return V_87 -> V_924 ( F_371 ( V_836 ) , V_921 , V_923 ) ;
}
static void F_452 ( struct V_835 * V_836 ,
T_1 * V_925 , T_1 * V_926 , T_1 * V_201 , T_1 * V_209 )
{
V_691 ( F_371 ( V_836 ) , V_925 , V_926 , V_201 , V_209 ) ;
}
static V_176 F_453 ( struct V_835 * V_836 , unsigned V_927 )
{
return F_104 ( F_371 ( V_836 ) , V_927 ) ;
}
static void F_454 ( struct V_835 * V_836 , unsigned V_927 , V_176 V_196 )
{
F_106 ( F_371 ( V_836 ) , V_927 , V_196 ) ;
}
static void F_455 ( struct V_835 * V_836 , bool V_628 )
{
V_87 -> V_644 ( F_371 ( V_836 ) , V_628 ) ;
}
static void F_456 ( struct V_1 * V_2 , T_1 V_29 )
{
T_1 V_928 = V_87 -> V_624 ( V_2 ) ;
if ( V_928 & V_29 )
V_29 = 0 ;
if ( F_171 ( V_928 || V_29 ) ) {
V_87 -> V_643 ( V_2 , V_29 ) ;
if ( ! V_29 )
F_32 ( V_68 , V_2 ) ;
}
}
static bool F_457 ( struct V_1 * V_2 )
{
struct V_835 * V_836 = & V_2 -> V_5 . V_929 ;
if ( V_836 -> V_69 . V_42 == V_43 )
return F_41 ( V_2 , & V_836 -> V_69 ) ;
if ( V_836 -> V_69 . V_930 )
F_40 ( V_2 , V_836 -> V_69 . V_42 ,
V_836 -> V_69 . V_63 ) ;
else
F_34 ( V_2 , V_836 -> V_69 . V_42 ) ;
return false ;
}
static void F_458 ( struct V_1 * V_2 )
{
struct V_835 * V_836 = & V_2 -> V_5 . V_929 ;
int V_134 , V_135 ;
V_87 -> V_136 ( V_2 , & V_134 , & V_135 ) ;
V_836 -> V_931 = F_459 ( V_2 ) ;
V_836 -> V_932 = F_460 ( V_2 ) ;
V_836 -> V_329 = ( ! F_33 ( V_2 ) ) ? V_933 :
( V_836 -> V_931 & V_934 ) ? V_935 :
( V_135 && F_58 ( V_2 ) ) ? V_858 :
V_134 ? V_936 :
V_937 ;
F_188 ( V_938 != V_939 ) ;
F_188 ( V_646 != V_940 ) ;
F_188 ( V_636 != V_941 ) ;
V_836 -> V_942 = V_2 -> V_5 . V_635 ;
F_461 ( V_836 ) ;
V_2 -> V_5 . V_943 = false ;
}
int F_462 ( struct V_1 * V_2 , int V_595 , int V_944 )
{
struct V_835 * V_836 = & V_2 -> V_5 . V_929 ;
int V_108 ;
F_458 ( V_2 ) ;
V_836 -> V_945 = 2 ;
V_836 -> V_946 = 2 ;
V_836 -> V_947 = V_836 -> V_932 + V_944 ;
V_108 = F_463 ( V_836 , V_595 ) ;
if ( V_108 != V_831 )
return V_948 ;
V_836 -> V_932 = V_836 -> V_947 ;
F_464 ( V_2 , V_836 -> V_932 ) ;
F_465 ( V_2 , V_836 -> V_931 ) ;
if ( V_595 == V_52 )
V_2 -> V_5 . V_627 = 0 ;
else
V_2 -> V_5 . V_621 . V_70 = false ;
return V_949 ;
}
static int F_466 ( struct V_1 * V_2 )
{
int V_121 = V_949 ;
++ V_2 -> V_76 . V_950 ;
F_467 ( V_2 ) ;
if ( ! F_468 ( V_2 ) && V_87 -> V_88 ( V_2 ) == 0 ) {
V_2 -> V_847 -> V_863 = V_951 ;
V_2 -> V_847 -> V_952 . V_953 = V_954 ;
V_2 -> V_847 -> V_952 . V_955 = 0 ;
V_121 = V_948 ;
}
F_34 ( V_2 , V_91 ) ;
return V_121 ;
}
static bool F_469 ( struct V_1 * V_2 , T_15 V_78 ,
bool V_956 ,
int V_957 )
{
T_6 V_388 = V_78 ;
T_16 V_958 ;
if ( V_957 & V_959 )
return false ;
if ( ! V_2 -> V_5 . V_83 . V_960 ) {
V_388 = F_367 ( V_2 , V_78 , NULL ) ;
if ( V_388 == V_100 )
return true ;
}
V_958 = F_470 ( V_2 -> V_139 , F_51 ( V_388 ) ) ;
if ( F_471 ( V_958 ) )
return false ;
F_472 ( V_958 ) ;
if ( V_2 -> V_5 . V_83 . V_960 ) {
unsigned int V_961 ;
F_161 ( & V_2 -> V_139 -> V_962 ) ;
V_961 = V_2 -> V_139 -> V_5 . V_961 ;
F_162 ( & V_2 -> V_139 -> V_962 ) ;
if ( V_961 )
F_473 ( V_2 -> V_139 , F_51 ( V_388 ) ) ;
return true ;
}
F_473 ( V_2 -> V_139 , F_51 ( V_388 ) ) ;
return ! V_956 ;
}
static bool F_474 ( struct V_835 * V_836 ,
unsigned long V_78 , int V_957 )
{
struct V_1 * V_2 = F_371 ( V_836 ) ;
unsigned long V_963 , V_964 , V_388 = V_78 ;
V_963 = V_2 -> V_5 . V_963 ;
V_964 = V_2 -> V_5 . V_964 ;
V_2 -> V_5 . V_963 = V_2 -> V_5 . V_964 = 0 ;
if ( ! ( V_957 & V_965 ) )
return false ;
if ( F_475 ( V_836 ) )
return false ;
if ( V_836 -> V_932 == V_963 && V_964 == V_78 )
return false ;
V_2 -> V_5 . V_963 = V_836 -> V_932 ;
V_2 -> V_5 . V_964 = V_78 ;
if ( ! V_2 -> V_5 . V_83 . V_960 )
V_388 = F_367 ( V_2 , V_78 , NULL ) ;
F_473 ( V_2 -> V_139 , F_51 ( V_388 ) ) ;
return true ;
}
static void F_476 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_635 & V_646 ) ) {
F_477 ( V_2 -> V_298 , V_2 -> V_5 . V_424 , false ) ;
F_32 ( V_68 , V_2 ) ;
}
F_67 ( V_2 ) ;
}
static void F_291 ( struct V_1 * V_2 , unsigned V_942 )
{
unsigned V_120 = V_2 -> V_5 . V_635 ^ V_942 ;
V_2 -> V_5 . V_635 = V_942 ;
if ( V_120 & V_646 )
F_476 ( V_2 ) ;
}
static int F_478 ( unsigned long V_615 , T_1 type , T_1 V_188 ,
unsigned long * V_183 )
{
T_1 V_187 = 0 ;
int V_3 ;
T_1 V_966 , V_967 ;
V_966 = V_188 ;
V_967 = V_188 >> 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ , V_966 >>= 2 , V_967 >>= 4 )
if ( ( V_966 & 3 ) && ( V_967 & 15 ) == type && V_183 [ V_3 ] == V_615 )
V_187 |= ( 1 << V_3 ) ;
return V_187 ;
}
static void F_479 ( struct V_1 * V_2 , unsigned long V_968 , int * V_121 )
{
struct V_969 * V_969 = V_2 -> V_847 ;
if ( F_171 ( V_968 & V_970 ) ) {
if ( V_2 -> V_179 & V_971 ) {
V_969 -> V_972 . V_5 . V_187 = V_973 | V_194 |
V_195 ;
V_969 -> V_972 . V_5 . V_974 = V_2 -> V_5 . V_975 ;
V_969 -> V_972 . V_5 . V_69 = V_54 ;
V_969 -> V_863 = V_976 ;
* V_121 = V_977 ;
} else {
V_2 -> V_5 . V_187 &= ~ 15 ;
V_2 -> V_5 . V_187 |= V_973 | V_195 ;
F_34 ( V_2 , V_54 ) ;
}
}
}
int F_38 ( struct V_1 * V_2 )
{
unsigned long V_968 = V_87 -> V_978 ( V_2 ) ;
int V_121 = V_949 ;
V_87 -> V_979 ( V_2 ) ;
F_479 ( V_2 , V_968 , & V_121 ) ;
return V_121 == V_949 ;
}
static bool F_480 ( struct V_1 * V_2 , int * V_121 )
{
if ( F_171 ( V_2 -> V_179 & V_180 ) &&
( V_2 -> V_5 . V_189 & V_192 ) ) {
struct V_969 * V_969 = V_2 -> V_847 ;
unsigned long V_932 = F_481 ( V_2 ) ;
T_1 V_187 = F_478 ( V_932 , 0 ,
V_2 -> V_5 . V_189 ,
V_2 -> V_5 . V_182 ) ;
if ( V_187 != 0 ) {
V_969 -> V_972 . V_5 . V_187 = V_187 | V_194 | V_195 ;
V_969 -> V_972 . V_5 . V_974 = V_932 ;
V_969 -> V_972 . V_5 . V_69 = V_54 ;
V_969 -> V_863 = V_976 ;
* V_121 = V_977 ;
return true ;
}
}
if ( F_171 ( V_2 -> V_5 . V_188 & V_192 ) &&
! ( F_459 ( V_2 ) & V_980 ) ) {
unsigned long V_932 = F_481 ( V_2 ) ;
T_1 V_187 = F_478 ( V_932 , 0 ,
V_2 -> V_5 . V_188 ,
V_2 -> V_5 . V_183 ) ;
if ( V_187 != 0 ) {
V_2 -> V_5 . V_187 &= ~ 15 ;
V_2 -> V_5 . V_187 |= V_187 | V_195 ;
F_34 ( V_2 , V_54 ) ;
* V_121 = V_949 ;
return true ;
}
}
return false ;
}
int F_482 ( struct V_1 * V_2 ,
unsigned long V_78 ,
int V_957 ,
void * V_981 ,
int V_982 )
{
int V_121 ;
struct V_835 * V_836 = & V_2 -> V_5 . V_929 ;
bool V_488 = true ;
bool V_983 = V_2 -> V_5 . V_956 ;
V_2 -> V_5 . V_956 = false ;
F_483 ( V_2 ) ;
if ( ! ( V_957 & V_984 ) ) {
F_458 ( V_2 ) ;
if ( F_480 ( V_2 , & V_121 ) )
return V_121 ;
V_836 -> V_985 = 0 ;
V_836 -> V_986 = false ;
V_836 -> V_69 . V_42 = - 1 ;
V_836 -> V_987 = false ;
V_836 -> V_988 = V_957 & V_989 ;
V_121 = F_484 ( V_836 , V_981 , V_982 ) ;
F_485 ( V_2 ) ;
++ V_2 -> V_76 . V_990 ;
if ( V_121 != V_991 ) {
if ( V_957 & V_989 )
return V_948 ;
if ( F_469 ( V_2 , V_78 , V_983 ,
V_957 ) )
return V_949 ;
if ( V_957 & V_992 )
return V_948 ;
return F_466 ( V_2 ) ;
}
}
if ( V_957 & V_992 ) {
F_464 ( V_2 , V_836 -> V_947 ) ;
if ( V_836 -> V_931 & V_980 )
F_465 ( V_2 , V_836 -> V_931 & ~ V_980 ) ;
return V_949 ;
}
if ( F_474 ( V_836 , V_78 , V_957 ) )
return V_949 ;
if ( V_2 -> V_5 . V_943 ) {
V_2 -> V_5 . V_943 = false ;
F_486 ( V_836 ) ;
}
V_993:
V_121 = F_487 ( V_836 ) ;
if ( V_121 == V_994 )
return V_949 ;
if ( V_121 == V_995 ) {
if ( F_469 ( V_2 , V_78 , V_983 ,
V_957 ) )
return V_949 ;
return F_466 ( V_2 ) ;
}
if ( V_836 -> V_986 ) {
V_121 = V_949 ;
if ( F_457 ( V_2 ) )
return V_121 ;
} else if ( V_2 -> V_5 . V_878 . V_747 ) {
if ( ! V_2 -> V_5 . V_878 . V_879 ) {
V_2 -> V_5 . V_878 . V_747 = 0 ;
} else {
V_488 = false ;
V_2 -> V_5 . V_996 = V_997 ;
}
V_121 = V_977 ;
} else if ( V_2 -> V_859 ) {
if ( ! V_2 -> V_862 )
V_488 = false ;
V_121 = V_977 ;
V_2 -> V_5 . V_996 = V_998 ;
} else if ( V_121 == V_999 )
goto V_993;
else
V_121 = V_949 ;
if ( V_488 ) {
unsigned long V_968 = V_87 -> V_978 ( V_2 ) ;
F_456 ( V_2 , V_836 -> V_985 ) ;
V_2 -> V_5 . V_1000 = false ;
if ( V_2 -> V_5 . V_635 != V_836 -> V_942 )
F_291 ( V_2 , V_836 -> V_942 ) ;
F_464 ( V_2 , V_836 -> V_932 ) ;
if ( V_121 == V_949 )
F_479 ( V_2 , V_968 , & V_121 ) ;
if ( ! V_836 -> V_986 ||
F_29 ( V_836 -> V_69 . V_42 ) == V_57 )
F_488 ( V_2 , V_836 -> V_931 ) ;
if ( F_171 ( ( V_836 -> V_931 & ~ V_968 ) & V_1001 ) )
F_32 ( V_68 , V_2 ) ;
} else
V_2 -> V_5 . V_1000 = true ;
return V_121 ;
}
int F_489 ( struct V_1 * V_2 , int V_490 , unsigned short V_881 )
{
unsigned long V_196 = F_104 ( V_2 , V_203 ) ;
int V_108 = F_409 ( & V_2 -> V_5 . V_929 ,
V_490 , V_881 , & V_196 , 1 ) ;
V_2 -> V_5 . V_878 . V_747 = 0 ;
return V_108 ;
}
static int F_490 ( struct V_1 * V_2 )
{
unsigned long V_196 ;
F_15 ( V_2 -> V_5 . V_878 . V_747 != 1 ) ;
V_196 = ( V_2 -> V_5 . V_878 . V_490 < 4 ) ? F_104 ( V_2 , V_203 )
: 0 ;
F_407 ( & V_2 -> V_5 . V_929 , V_2 -> V_5 . V_878 . V_490 ,
V_2 -> V_5 . V_878 . V_881 , & V_196 , 1 ) ;
F_106 ( V_2 , V_203 , V_196 ) ;
return 1 ;
}
int F_491 ( struct V_1 * V_2 , int V_490 , unsigned short V_881 )
{
unsigned long V_196 ;
int V_108 ;
V_196 = ( V_490 < 4 ) ? F_104 ( V_2 , V_203 ) : 0 ;
V_108 = F_407 ( & V_2 -> V_5 . V_929 , V_490 , V_881 ,
& V_196 , 1 ) ;
if ( V_108 ) {
F_106 ( V_2 , V_203 , V_196 ) ;
return V_108 ;
}
V_2 -> V_5 . V_996 = F_490 ;
return 0 ;
}
static int F_492 ( unsigned int V_24 )
{
F_493 ( V_343 , 0 ) ;
return 0 ;
}
static void F_494 ( void * V_39 )
{
struct V_1002 * V_1003 = V_39 ;
unsigned long V_263 = 0 ;
if ( V_39 )
V_263 = V_1003 -> V_870 ;
else if ( ! F_245 ( V_1004 ) )
V_263 = F_495 ( F_496 () ) ;
if ( ! V_263 )
V_263 = V_272 ;
F_493 ( V_343 , V_263 ) ;
}
static int F_497 ( struct V_1005 * V_1006 , unsigned long V_196 ,
void * V_39 )
{
struct V_1002 * V_1003 = V_39 ;
struct V_139 * V_139 ;
struct V_1 * V_2 ;
int V_3 , V_1007 = 0 ;
if ( V_196 == V_1008 && V_1003 -> V_869 > V_1003 -> V_870 )
return 0 ;
if ( V_196 == V_1009 && V_1003 -> V_869 < V_1003 -> V_870 )
return 0 ;
F_254 ( V_1003 -> V_24 , F_494 , V_1003 , 1 ) ;
F_161 ( & V_1010 ) ;
F_498 (kvm, &vm_list, vm_list) {
F_180 (i, vcpu, kvm) {
if ( V_2 -> V_24 != V_1003 -> V_24 )
continue;
F_32 ( V_337 , V_2 ) ;
if ( V_2 -> V_24 != F_10 () )
V_1007 = 1 ;
}
}
F_162 ( & V_1010 ) ;
if ( V_1003 -> V_869 < V_1003 -> V_870 && V_1007 ) {
F_254 ( V_1003 -> V_24 , F_494 , V_1003 , 1 ) ;
}
return 0 ;
}
static int F_499 ( unsigned int V_24 )
{
F_494 ( NULL ) ;
return 0 ;
}
static void F_500 ( void )
{
V_1011 = V_272 ;
if ( ! F_245 ( V_1004 ) ) {
#ifdef F_501
struct V_1012 V_1013 ;
int V_24 ;
memset ( & V_1013 , 0 , sizeof( V_1013 ) ) ;
V_24 = F_414 () ;
F_502 ( & V_1013 , V_24 ) ;
if ( V_1013 . V_1014 . V_1015 )
V_1011 = V_1013 . V_1014 . V_1015 ;
F_416 () ;
#endif
F_503 ( & V_1016 ,
V_1017 ) ;
}
F_133 ( L_22 , V_1011 ) ;
F_504 ( V_1018 , L_23 ,
F_499 , F_492 ) ;
}
int F_505 ( void )
{
return F_183 ( V_1019 ) != NULL ;
}
static int F_506 ( void )
{
int V_1020 = 3 ;
if ( F_183 ( V_1019 ) )
V_1020 = V_87 -> V_88 ( F_183 ( V_1019 ) ) ;
return V_1020 != 0 ;
}
static unsigned long F_507 ( void )
{
unsigned long V_1021 = 0 ;
if ( F_183 ( V_1019 ) )
V_1021 = F_460 ( F_183 ( V_1019 ) ) ;
return V_1021 ;
}
void F_508 ( struct V_1 * V_2 )
{
F_493 ( V_1019 , V_2 ) ;
}
void F_509 ( struct V_1 * V_2 )
{
F_493 ( V_1019 , NULL ) ;
}
static void F_510 ( void )
{
T_2 V_29 ;
int V_1022 = V_1023 . V_1024 ;
V_29 = F_511 ( V_1022 , 51 ) ;
V_29 |= 0x3ull << 62 ;
V_29 |= 1ull ;
#ifdef F_64
if ( V_1022 == 52 )
V_29 &= ~ 1ull ;
#endif
F_512 ( V_29 ) ;
}
static void F_513 ( struct V_356 * V_357 )
{
struct V_139 * V_139 ;
struct V_1 * V_2 ;
int V_3 ;
F_161 ( & V_1010 ) ;
F_498 (kvm, &vm_list, vm_list)
F_180 (i, vcpu, kvm)
F_32 ( V_297 , V_2 ) ;
F_175 ( & V_335 , 0 ) ;
F_162 ( & V_1010 ) ;
}
static int F_514 ( struct V_1005 * V_1006 , unsigned long V_1025 ,
void * V_1026 )
{
struct V_226 * V_292 = & V_226 ;
struct V_224 * V_225 = V_1026 ;
F_118 ( V_225 ) ;
if ( V_292 -> clock . V_233 != V_296 &&
F_144 ( & V_335 ) != 0 )
F_515 ( V_1027 , & V_1028 ) ;
return 0 ;
}
int F_516 ( void * V_1029 )
{
int V_121 ;
struct V_87 * V_850 = V_1029 ;
if ( V_87 ) {
F_12 ( V_27 L_24 ) ;
V_121 = - V_599 ;
goto V_113;
}
if ( ! V_850 -> V_1030 () ) {
F_12 ( V_27 L_25 ) ;
V_121 = - V_1031 ;
goto V_113;
}
if ( V_850 -> V_1032 () ) {
F_12 ( V_27 L_26 ) ;
V_121 = - V_1031 ;
goto V_113;
}
V_121 = - V_386 ;
V_26 = F_517 ( struct V_11 ) ;
if ( ! V_26 ) {
F_12 ( V_27 L_27 ) ;
goto V_113;
}
V_121 = F_518 () ;
if ( V_121 )
goto V_1033;
F_510 () ;
V_87 = V_850 ;
F_519 ( V_1034 , V_1035 ,
V_1036 , V_1037 , 0 ,
V_114 ) ;
F_500 () ;
F_520 ( & V_1038 ) ;
if ( F_245 ( V_554 ) )
V_146 = F_521 ( V_144 ) ;
F_522 () ;
#ifdef F_64
F_523 ( & V_1039 ) ;
#endif
return 0 ;
V_1033:
F_524 ( V_26 ) ;
V_113:
return V_121 ;
}
void F_525 ( void )
{
F_526 () ;
F_527 ( & V_1038 ) ;
if ( ! F_245 ( V_1004 ) )
F_528 ( & V_1016 ,
V_1017 ) ;
F_529 ( V_1018 ) ;
#ifdef F_64
F_530 ( & V_1039 ) ;
#endif
V_87 = NULL ;
F_531 () ;
F_524 ( V_26 ) ;
}
int F_532 ( struct V_1 * V_2 )
{
++ V_2 -> V_76 . V_1040 ;
if ( F_91 ( V_2 ) ) {
V_2 -> V_5 . V_1041 = V_1042 ;
return 1 ;
} else {
V_2 -> V_847 -> V_863 = V_1043 ;
return 0 ;
}
}
int F_533 ( struct V_1 * V_2 )
{
int V_108 = F_38 ( V_2 ) ;
return F_532 ( V_2 ) && V_108 ;
}
static void F_534 ( struct V_139 * V_139 , unsigned long V_15 , int V_1044 )
{
struct V_1045 V_1046 ;
V_1046 . V_1047 = 0 ;
V_1046 . V_1048 = 0 ;
V_1046 . V_1049 = V_1044 ;
V_1046 . V_1050 = false ;
V_1046 . V_1051 = V_1052 ;
F_535 ( V_139 , NULL , & V_1046 , NULL ) ;
}
void F_536 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_592 = false ;
V_87 -> V_1053 ( V_2 ) ;
}
int F_537 ( struct V_1 * V_2 )
{
unsigned long V_18 , V_1054 , V_1055 , V_1056 , V_1057 , V_108 ;
int V_1058 , V_121 ;
V_121 = F_38 ( V_2 ) ;
if ( F_538 ( V_2 -> V_139 ) )
return F_539 ( V_2 ) ;
V_18 = F_104 ( V_2 , V_203 ) ;
V_1054 = F_104 ( V_2 , V_1059 ) ;
V_1055 = F_104 ( V_2 , V_202 ) ;
V_1056 = F_104 ( V_2 , V_204 ) ;
V_1057 = F_104 ( V_2 , V_1060 ) ;
F_540 ( V_18 , V_1054 , V_1055 , V_1056 , V_1057 ) ;
V_1058 = F_541 ( V_2 ) ;
if ( ! V_1058 ) {
V_18 &= 0xFFFFFFFF ;
V_1054 &= 0xFFFFFFFF ;
V_1055 &= 0xFFFFFFFF ;
V_1056 &= 0xFFFFFFFF ;
V_1057 &= 0xFFFFFFFF ;
}
if ( V_87 -> V_88 ( V_2 ) != 0 ) {
V_108 = - V_1061 ;
goto V_113;
}
switch ( V_18 ) {
case V_1062 :
V_108 = 0 ;
break;
case V_1063 :
F_534 ( V_2 -> V_139 , V_1054 , V_1055 ) ;
V_108 = 0 ;
break;
default:
V_108 = - V_1064 ;
break;
}
V_113:
if ( ! V_1058 )
V_108 = ( T_1 ) V_108 ;
F_106 ( V_2 , V_203 , V_108 ) ;
++ V_2 -> V_76 . V_1065 ;
return V_121 ;
}
static int F_542 ( struct V_835 * V_836 )
{
struct V_1 * V_2 = F_371 ( V_836 ) ;
char V_1066 [ 3 ] ;
unsigned long V_1067 = F_460 ( V_2 ) ;
V_87 -> V_1068 ( V_2 , V_1066 ) ;
return F_393 ( V_836 , V_1067 , V_1066 , 3 ,
& V_836 -> V_69 ) ;
}
static int F_543 ( struct V_1 * V_2 )
{
return V_2 -> V_847 -> V_1069 &&
F_167 ( ! F_279 ( V_2 -> V_139 ) ) ;
}
static void F_544 ( struct V_1 * V_2 )
{
struct V_969 * V_969 = V_2 -> V_847 ;
V_969 -> V_1070 = ( F_459 ( V_2 ) & V_1001 ) != 0 ;
V_969 -> V_15 = F_288 ( V_2 ) ? V_1071 : 0 ;
V_969 -> V_177 = F_93 ( V_2 ) ;
V_969 -> V_32 = F_21 ( V_2 ) ;
V_969 -> V_1072 =
F_279 ( V_2 -> V_139 ) ||
F_272 ( V_2 ) ;
}
static void F_269 ( struct V_1 * V_2 )
{
int V_1073 , V_1074 ;
if ( ! V_87 -> F_269 )
return;
if ( ! F_91 ( V_2 ) )
return;
if ( V_2 -> V_5 . V_592 )
return;
if ( ! V_2 -> V_5 . V_645 -> V_700 )
V_1073 = F_545 ( V_2 ) ;
else
V_1073 = - 1 ;
if ( V_1073 != - 1 )
V_1073 >>= 4 ;
V_1074 = F_94 ( V_2 ) ;
V_87 -> F_269 ( V_2 , V_1074 , V_1073 ) ;
}
static int F_546 ( struct V_1 * V_2 , bool V_1075 )
{
int V_121 ;
if ( V_2 -> V_5 . V_69 . V_70 ) {
F_547 ( V_2 -> V_5 . V_69 . V_18 ,
V_2 -> V_5 . V_69 . V_72 ,
V_2 -> V_5 . V_69 . V_63 ) ;
if ( F_29 ( V_2 -> V_5 . V_69 . V_18 ) == V_61 )
F_488 ( V_2 , F_459 ( V_2 ) |
V_980 ) ;
if ( V_2 -> V_5 . V_69 . V_18 == V_54 &&
( V_2 -> V_5 . V_188 & V_1076 ) ) {
V_2 -> V_5 . V_188 &= ~ V_1076 ;
F_97 ( V_2 ) ;
}
V_87 -> V_1077 ( V_2 , V_2 -> V_5 . V_69 . V_18 ,
V_2 -> V_5 . V_69 . V_72 ,
V_2 -> V_5 . V_69 . V_63 ,
V_2 -> V_5 . V_69 . V_64 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_626 ) {
V_87 -> V_1078 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_621 . V_70 ) {
V_87 -> V_1079 ( V_2 ) ;
return 0 ;
}
if ( F_468 ( V_2 ) && V_87 -> V_1080 ) {
V_121 = V_87 -> V_1080 ( V_2 , V_1075 ) ;
if ( V_121 != 0 )
return V_121 ;
}
if ( V_2 -> V_5 . V_633 && ! F_288 ( V_2 ) ) {
V_2 -> V_5 . V_633 = false ;
F_548 ( V_2 ) ;
} else if ( V_2 -> V_5 . V_627 && V_87 -> V_1081 ( V_2 ) ) {
-- V_2 -> V_5 . V_627 ;
V_2 -> V_5 . V_626 = true ;
V_87 -> V_1078 ( V_2 ) ;
} else if ( F_549 ( V_2 ) ) {
if ( F_468 ( V_2 ) && V_87 -> V_1080 ) {
V_121 = V_87 -> V_1080 ( V_2 , V_1075 ) ;
if ( V_121 != 0 )
return V_121 ;
}
if ( V_87 -> V_1082 ( V_2 ) ) {
F_278 ( V_2 , F_550 ( V_2 ) ,
false ) ;
V_87 -> V_1079 ( V_2 ) ;
}
}
return 0 ;
}
static void F_286 ( struct V_1 * V_2 )
{
unsigned V_909 = 2 ;
if ( V_87 -> V_629 ( V_2 ) || V_2 -> V_5 . V_626 )
V_909 = 1 ;
V_2 -> V_5 . V_627 += F_551 ( & V_2 -> V_5 . V_84 , 0 ) ;
V_2 -> V_5 . V_627 = F_355 ( V_2 -> V_5 . V_627 , V_909 ) ;
F_32 ( V_68 , V_2 ) ;
}
static T_1 F_552 ( struct V_821 * V_823 )
{
T_1 V_15 = 0 ;
V_15 |= V_823 -> V_908 << 23 ;
V_15 |= V_823 -> V_183 << 22 ;
V_15 |= V_823 -> V_914 << 21 ;
V_15 |= V_823 -> V_913 << 20 ;
V_15 |= V_823 -> V_912 << 15 ;
V_15 |= V_823 -> V_910 << 13 ;
V_15 |= V_823 -> V_591 << 12 ;
V_15 |= V_823 -> type << 8 ;
return V_15 ;
}
static void F_553 ( struct V_1 * V_2 , char * V_1083 , int V_489 )
{
struct V_821 V_823 ;
int V_94 ;
F_363 ( V_2 , & V_823 , V_489 ) ;
F_554 ( T_1 , V_1083 , 0x7fa8 + V_489 * 4 , V_823 . V_903 ) ;
if ( V_489 < 3 )
V_94 = 0x7f84 + V_489 * 12 ;
else
V_94 = 0x7f2c + ( V_489 - 3 ) * 12 ;
F_554 ( T_1 , V_1083 , V_94 + 8 , V_823 . V_230 ) ;
F_554 ( T_1 , V_1083 , V_94 + 4 , V_823 . V_909 ) ;
F_554 ( T_1 , V_1083 , V_94 , F_552 ( & V_823 ) ) ;
}
static void F_555 ( struct V_1 * V_2 , char * V_1083 , int V_489 )
{
struct V_821 V_823 ;
int V_94 ;
V_874 V_15 ;
F_363 ( V_2 , & V_823 , V_489 ) ;
V_94 = 0x7e00 + V_489 * 16 ;
V_15 = F_552 ( & V_823 ) >> 8 ;
F_554 ( V_874 , V_1083 , V_94 , V_823 . V_903 ) ;
F_554 ( V_874 , V_1083 , V_94 + 2 , V_15 ) ;
F_554 ( T_1 , V_1083 , V_94 + 4 , V_823 . V_909 ) ;
F_554 ( T_2 , V_1083 , V_94 + 8 , V_823 . V_230 ) ;
}
static void F_556 ( struct V_1 * V_2 , char * V_1083 )
{
struct V_897 V_898 ;
struct V_821 V_823 ;
unsigned long V_196 ;
int V_3 ;
F_554 ( T_1 , V_1083 , 0x7ffc , F_63 ( V_2 ) ) ;
F_554 ( T_1 , V_1083 , 0x7ff8 , F_61 ( V_2 ) ) ;
F_554 ( T_1 , V_1083 , 0x7ff4 , F_459 ( V_2 ) ) ;
F_554 ( T_1 , V_1083 , 0x7ff0 , F_460 ( V_2 ) ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
F_554 ( T_1 , V_1083 , 0x7fd0 + V_3 * 4 , F_104 ( V_2 , V_3 ) ) ;
F_102 ( V_2 , 6 , & V_196 ) ;
F_554 ( T_1 , V_1083 , 0x7fcc , ( T_1 ) V_196 ) ;
F_102 ( V_2 , 7 , & V_196 ) ;
F_554 ( T_1 , V_1083 , 0x7fc8 , ( T_1 ) V_196 ) ;
F_363 ( V_2 , & V_823 , V_1084 ) ;
F_554 ( T_1 , V_1083 , 0x7fc4 , V_823 . V_903 ) ;
F_554 ( T_1 , V_1083 , 0x7f64 , V_823 . V_230 ) ;
F_554 ( T_1 , V_1083 , 0x7f60 , V_823 . V_909 ) ;
F_554 ( T_1 , V_1083 , 0x7f5c , F_552 ( & V_823 ) ) ;
F_363 ( V_2 , & V_823 , V_1085 ) ;
F_554 ( T_1 , V_1083 , 0x7fc0 , V_823 . V_903 ) ;
F_554 ( T_1 , V_1083 , 0x7f80 , V_823 . V_230 ) ;
F_554 ( T_1 , V_1083 , 0x7f7c , V_823 . V_909 ) ;
F_554 ( T_1 , V_1083 , 0x7f78 , F_552 ( & V_823 ) ) ;
V_87 -> V_899 ( V_2 , & V_898 ) ;
F_554 ( T_1 , V_1083 , 0x7f74 , V_898 . V_79 ) ;
F_554 ( T_1 , V_1083 , 0x7f70 , V_898 . V_490 ) ;
V_87 -> V_900 ( V_2 , & V_898 ) ;
F_554 ( T_1 , V_1083 , 0x7f58 , V_898 . V_79 ) ;
F_554 ( T_1 , V_1083 , 0x7f54 , V_898 . V_490 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_553 ( V_2 , V_1083 , V_3 ) ;
F_554 ( T_1 , V_1083 , 0x7f14 , F_80 ( V_2 ) ) ;
F_554 ( T_1 , V_1083 , 0x7efc , 0x00020000 ) ;
F_554 ( T_1 , V_1083 , 0x7ef8 , V_2 -> V_5 . V_424 ) ;
}
static void F_557 ( struct V_1 * V_2 , char * V_1083 )
{
#ifdef F_64
struct V_897 V_898 ;
struct V_821 V_823 ;
unsigned long V_196 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ )
F_554 ( T_2 , V_1083 , 0x7ff8 - V_3 * 8 , F_104 ( V_2 , V_3 ) ) ;
F_554 ( T_2 , V_1083 , 0x7f78 , F_460 ( V_2 ) ) ;
F_554 ( T_1 , V_1083 , 0x7f70 , F_459 ( V_2 ) ) ;
F_102 ( V_2 , 6 , & V_196 ) ;
F_554 ( T_2 , V_1083 , 0x7f68 , V_196 ) ;
F_102 ( V_2 , 7 , & V_196 ) ;
F_554 ( T_2 , V_1083 , 0x7f60 , V_196 ) ;
F_554 ( T_2 , V_1083 , 0x7f58 , F_63 ( V_2 ) ) ;
F_554 ( T_2 , V_1083 , 0x7f50 , F_61 ( V_2 ) ) ;
F_554 ( T_2 , V_1083 , 0x7f48 , F_80 ( V_2 ) ) ;
F_554 ( T_1 , V_1083 , 0x7f00 , V_2 -> V_5 . V_424 ) ;
F_554 ( T_1 , V_1083 , 0x7efc , 0x00020064 ) ;
F_554 ( T_2 , V_1083 , 0x7ed0 , V_2 -> V_5 . V_132 ) ;
F_363 ( V_2 , & V_823 , V_1084 ) ;
F_554 ( V_874 , V_1083 , 0x7e90 , V_823 . V_903 ) ;
F_554 ( V_874 , V_1083 , 0x7e92 , F_552 ( & V_823 ) >> 8 ) ;
F_554 ( T_1 , V_1083 , 0x7e94 , V_823 . V_909 ) ;
F_554 ( T_2 , V_1083 , 0x7e98 , V_823 . V_230 ) ;
V_87 -> V_900 ( V_2 , & V_898 ) ;
F_554 ( T_1 , V_1083 , 0x7e84 , V_898 . V_490 ) ;
F_554 ( T_2 , V_1083 , 0x7e88 , V_898 . V_79 ) ;
F_363 ( V_2 , & V_823 , V_1085 ) ;
F_554 ( V_874 , V_1083 , 0x7e70 , V_823 . V_903 ) ;
F_554 ( V_874 , V_1083 , 0x7e72 , F_552 ( & V_823 ) >> 8 ) ;
F_554 ( T_1 , V_1083 , 0x7e74 , V_823 . V_909 ) ;
F_554 ( T_2 , V_1083 , 0x7e78 , V_823 . V_230 ) ;
V_87 -> V_899 ( V_2 , & V_898 ) ;
F_554 ( T_1 , V_1083 , 0x7e64 , V_898 . V_490 ) ;
F_554 ( T_2 , V_1083 , 0x7e68 , V_898 . V_79 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_555 ( V_2 , V_1083 , V_3 ) ;
#else
F_558 ( 1 ) ;
#endif
}
static void F_548 ( struct V_1 * V_2 )
{
struct V_821 V_1086 , V_1087 ;
struct V_897 V_898 ;
char V_1083 [ 512 ] ;
T_1 V_122 ;
F_477 ( V_2 -> V_298 , V_2 -> V_5 . V_424 , true ) ;
V_2 -> V_5 . V_635 |= V_646 ;
memset ( V_1083 , 0 , 512 ) ;
if ( F_559 ( V_2 ) )
F_557 ( V_2 , V_1083 ) ;
else
F_556 ( V_2 , V_1083 ) ;
F_208 ( V_2 , V_2 -> V_5 . V_424 + 0xfe00 , V_1083 , sizeof( V_1083 ) ) ;
if ( V_87 -> V_629 ( V_2 ) )
V_2 -> V_5 . V_635 |= V_636 ;
else
V_87 -> V_644 ( V_2 , true ) ;
F_465 ( V_2 , V_1088 ) ;
F_464 ( V_2 , 0x8000 ) ;
V_122 = V_2 -> V_5 . V_122 & ~ ( V_131 | V_1089 | V_1090 | V_125 ) ;
V_87 -> V_138 ( V_2 , V_122 ) ;
V_2 -> V_5 . V_122 = V_122 ;
V_87 -> V_171 ( V_2 , 0 ) ;
V_898 . V_79 = V_898 . V_490 = 0 ;
V_87 -> V_902 ( V_2 , & V_898 ) ;
F_100 ( V_2 , 7 , V_199 ) ;
V_1086 . V_903 = ( V_2 -> V_5 . V_424 >> 4 ) & 0xffff ;
V_1086 . V_230 = V_2 -> V_5 . V_424 ;
V_1087 . V_903 = 0 ;
V_1087 . V_230 = 0 ;
V_1086 . V_909 = V_1087 . V_909 = 0xffffffff ;
V_1086 . type = V_1087 . type = 0x3 ;
V_1086 . V_910 = V_1087 . V_910 = 0 ;
V_1086 . V_183 = V_1087 . V_183 = 0 ;
V_1086 . V_591 = V_1087 . V_591 = 1 ;
V_1086 . V_914 = V_1087 . V_914 = 0 ;
V_1086 . V_908 = V_1087 . V_908 = 1 ;
V_1086 . V_913 = V_1087 . V_913 = 0 ;
V_1086 . V_912 = V_1087 . V_912 = 1 ;
V_1086 . V_907 = V_1087 . V_907 = 0 ;
V_1086 . V_916 = V_1087 . V_916 = 0 ;
F_362 ( V_2 , & V_1086 , V_1091 ) ;
F_362 ( V_2 , & V_1087 , V_1092 ) ;
F_362 ( V_2 , & V_1087 , V_1093 ) ;
F_362 ( V_2 , & V_1087 , V_1094 ) ;
F_362 ( V_2 , & V_1087 , V_1095 ) ;
F_362 ( V_2 , & V_1087 , V_1096 ) ;
if ( F_559 ( V_2 ) )
V_87 -> F_110 ( V_2 , 0 ) ;
F_77 ( V_2 ) ;
F_67 ( V_2 ) ;
}
static void F_560 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_633 = true ;
F_32 ( V_68 , V_2 ) ;
}
void F_561 ( struct V_139 * V_139 )
{
F_178 ( V_139 , V_1097 ) ;
}
static void F_562 ( struct V_1 * V_2 )
{
T_2 V_1098 [ 4 ] ;
if ( ! F_563 ( V_2 -> V_5 . V_645 ) )
return;
F_564 ( V_2 -> V_5 . V_1099 , 256 ) ;
if ( V_768 ( V_2 -> V_139 ) )
F_565 ( V_2 , V_2 -> V_5 . V_1099 ) ;
else {
if ( V_2 -> V_5 . V_592 )
V_87 -> V_593 ( V_2 ) ;
F_566 ( V_2 , V_2 -> V_5 . V_1099 ) ;
}
F_567 ( ( V_176 * ) V_1098 , V_2 -> V_5 . V_1099 ,
F_568 ( V_2 ) -> V_1100 , 256 ) ;
V_87 -> V_1101 ( V_2 , V_1098 ) ;
}
static void F_569 ( struct V_1 * V_2 )
{
++ V_2 -> V_76 . V_1102 ;
V_87 -> V_1102 ( V_2 ) ;
}
void F_570 ( struct V_1 * V_2 )
{
struct V_384 * V_384 = NULL ;
if ( ! F_91 ( V_2 ) )
return;
if ( ! V_87 -> V_1103 )
return;
V_384 = F_571 ( V_2 -> V_139 , V_840 >> V_106 ) ;
if ( F_396 ( V_384 ) )
return;
V_87 -> V_1103 ( V_2 , F_572 ( V_384 ) ) ;
F_573 ( V_384 ) ;
}
void F_574 ( struct V_139 * V_139 ,
unsigned long V_79 )
{
if ( V_79 == F_575 ( V_139 , V_840 >> V_106 ) )
F_178 ( V_139 , V_1104 ) ;
}
static int F_576 ( struct V_1 * V_2 )
{
int V_121 ;
bool V_1075 =
F_543 ( V_2 ) &&
F_270 ( V_2 ) ;
bool V_1105 = false ;
if ( V_2 -> V_338 ) {
if ( F_577 ( V_1106 , V_2 ) )
F_578 ( V_2 ) ;
if ( F_577 ( V_581 , V_2 ) )
F_579 ( V_2 ) ;
if ( F_577 ( V_297 , V_2 ) )
F_179 ( V_2 -> V_139 ) ;
if ( F_577 ( V_430 , V_2 ) )
F_199 ( V_2 ) ;
if ( F_577 ( V_337 , V_2 ) ) {
V_121 = F_193 ( V_2 ) ;
if ( F_171 ( V_121 ) )
goto V_113;
}
if ( F_577 ( V_1107 , V_2 ) )
F_88 ( V_2 ) ;
if ( F_577 ( V_173 , V_2 ) )
F_569 ( V_2 ) ;
if ( F_577 ( V_1108 , V_2 ) ) {
V_2 -> V_847 -> V_863 = V_1109 ;
V_121 = 0 ;
goto V_113;
}
if ( F_577 ( V_73 , V_2 ) ) {
V_2 -> V_847 -> V_863 = V_1110 ;
V_121 = 0 ;
goto V_113;
}
if ( F_577 ( V_1111 , V_2 ) ) {
V_2 -> V_1112 = 0 ;
V_87 -> V_1113 ( V_2 ) ;
}
if ( F_577 ( V_1114 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1115 = true ;
V_121 = 1 ;
goto V_113;
}
if ( F_577 ( V_435 , V_2 ) )
F_214 ( V_2 ) ;
if ( F_577 ( V_600 , V_2 ) )
F_560 ( V_2 ) ;
if ( F_577 ( V_85 , V_2 ) )
F_286 ( V_2 ) ;
if ( F_577 ( V_1116 , V_2 ) )
F_580 ( V_2 ) ;
if ( F_577 ( V_1117 , V_2 ) )
F_581 ( V_2 ) ;
if ( F_577 ( V_1118 , V_2 ) ) {
F_15 ( V_2 -> V_5 . V_1119 > 255 ) ;
if ( F_60 ( V_2 -> V_5 . V_1119 ,
V_2 -> V_5 . V_1099 ) ) {
V_2 -> V_847 -> V_863 = V_1120 ;
V_2 -> V_847 -> V_1121 . V_42 =
V_2 -> V_5 . V_1119 ;
V_121 = 0 ;
goto V_113;
}
}
if ( F_577 ( V_1097 , V_2 ) )
F_562 ( V_2 ) ;
if ( F_577 ( V_1104 , V_2 ) )
F_570 ( V_2 ) ;
if ( F_577 ( V_1122 , V_2 ) ) {
V_2 -> V_847 -> V_863 = V_1123 ;
V_2 -> V_847 -> V_1124 . type = V_1125 ;
V_121 = 0 ;
goto V_113;
}
if ( F_577 ( V_1126 , V_2 ) ) {
V_2 -> V_847 -> V_863 = V_1123 ;
V_2 -> V_847 -> V_1124 . type = V_1127 ;
V_121 = 0 ;
goto V_113;
}
if ( F_577 ( V_1128 , V_2 ) ) {
V_2 -> V_847 -> V_863 = V_1129 ;
V_2 -> V_847 -> V_1130 = V_2 -> V_5 . V_1130 . exit ;
V_121 = 0 ;
goto V_113;
}
if ( F_577 ( V_1131 , V_2 ) )
F_582 ( V_2 ) ;
}
if ( F_583 ( V_2 ) ) {
if ( V_2 -> V_5 . V_592 )
V_87 -> V_1132 ( V_2 ,
F_545 ( V_2 ) ) ;
}
if ( F_577 ( V_68 , V_2 ) || V_1075 ) {
F_584 ( V_2 ) ;
if ( V_2 -> V_5 . V_1041 == V_1133 ) {
V_121 = 1 ;
goto V_113;
}
if ( F_546 ( V_2 , V_1075 ) != 0 )
V_1105 = true ;
else {
if ( V_2 -> V_5 . V_633 && ! F_288 ( V_2 ) )
V_1105 = true ;
if ( V_2 -> V_5 . V_627 )
V_87 -> V_1134 ( V_2 ) ;
if ( F_549 ( V_2 ) || V_1075 )
V_87 -> V_1135 ( V_2 ) ;
}
if ( F_583 ( V_2 ) ) {
F_269 ( V_2 ) ;
F_585 ( V_2 ) ;
}
}
V_121 = F_586 ( V_2 ) ;
if ( F_171 ( V_121 ) ) {
goto V_1136;
}
F_447 () ;
V_87 -> V_1137 ( V_2 ) ;
if ( V_2 -> V_1112 )
F_448 ( V_2 ) ;
V_2 -> V_329 = V_1138 ;
F_238 ( & V_2 -> V_139 -> V_485 , V_2 -> V_1139 ) ;
F_587 () ;
F_349 () ;
if ( V_2 -> V_329 == V_1140 || V_2 -> V_338
|| F_588 () || F_589 ( V_399 ) ) {
V_2 -> V_329 = V_1141 ;
F_191 () ;
F_350 () ;
F_450 () ;
V_2 -> V_1139 = F_237 ( & V_2 -> V_139 -> V_485 ) ;
V_121 = 1 ;
goto V_1136;
}
F_73 ( V_2 ) ;
if ( V_1105 ) {
F_32 ( V_68 , V_2 ) ;
F_590 ( V_2 -> V_24 ) ;
}
F_591 ( V_2 -> V_298 ) ;
F_592 ( V_2 ) ;
F_593 () ;
if ( F_171 ( V_2 -> V_5 . V_184 ) ) {
F_594 ( 0 , 7 ) ;
F_594 ( V_2 -> V_5 . V_182 [ 0 ] , 0 ) ;
F_594 ( V_2 -> V_5 . V_182 [ 1 ] , 1 ) ;
F_594 ( V_2 -> V_5 . V_182 [ 2 ] , 2 ) ;
F_594 ( V_2 -> V_5 . V_182 [ 3 ] , 3 ) ;
F_594 ( V_2 -> V_5 . V_187 , 6 ) ;
V_2 -> V_5 . V_184 &= ~ V_185 ;
}
V_87 -> V_847 ( V_2 ) ;
if ( F_171 ( V_2 -> V_5 . V_184 & V_1142 ) ) {
F_30 ( V_2 -> V_179 & V_180 ) ;
V_87 -> V_1143 ( V_2 ) ;
F_95 ( V_2 ) ;
F_96 ( V_2 ) ;
F_97 ( V_2 ) ;
V_2 -> V_5 . V_184 &= ~ V_185 ;
}
if ( F_595 () )
F_596 () ;
V_2 -> V_5 . V_323 = F_152 ( V_2 , F_151 () ) ;
V_2 -> V_329 = V_1141 ;
F_191 () ;
F_75 ( V_2 ) ;
V_87 -> V_1144 ( V_2 ) ;
++ V_2 -> V_76 . V_1145 ;
F_597 () ;
F_350 () ;
F_450 () ;
V_2 -> V_1139 = F_237 ( & V_2 -> V_139 -> V_485 ) ;
if ( F_171 ( V_1146 == V_1147 ) ) {
unsigned long V_1067 = F_460 ( V_2 ) ;
F_598 ( V_1147 , ( void * ) V_1067 ) ;
}
if ( F_171 ( V_2 -> V_5 . V_274 ) )
F_32 ( V_337 , V_2 ) ;
if ( V_2 -> V_5 . V_1148 )
F_599 ( V_2 ) ;
V_121 = V_87 -> V_1149 ( V_2 ) ;
return V_121 ;
V_1136:
V_87 -> V_1136 ( V_2 ) ;
if ( F_171 ( V_2 -> V_5 . V_1148 ) )
F_599 ( V_2 ) ;
V_113:
return V_121 ;
}
static inline int F_600 ( struct V_139 * V_139 , struct V_1 * V_2 )
{
if ( ! F_601 ( V_2 ) &&
( ! V_87 -> V_1150 || V_87 -> V_1150 ( V_2 ) == 0 ) ) {
F_238 ( & V_139 -> V_485 , V_2 -> V_1139 ) ;
F_602 ( V_2 ) ;
V_2 -> V_1139 = F_237 ( & V_139 -> V_485 ) ;
if ( V_87 -> V_1151 )
V_87 -> V_1151 ( V_2 ) ;
if ( ! F_577 ( V_1152 , V_2 ) )
return 1 ;
}
F_584 ( V_2 ) ;
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
static inline bool F_603 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_1041 == V_1155 &&
! V_2 -> V_5 . V_6 . V_1115 ) ;
}
static int F_604 ( struct V_1 * V_2 )
{
int V_121 ;
struct V_139 * V_139 = V_2 -> V_139 ;
V_2 -> V_1139 = F_237 ( & V_139 -> V_485 ) ;
for (; ; ) {
if ( F_603 ( V_2 ) ) {
V_121 = F_576 ( V_2 ) ;
} else {
V_121 = F_600 ( V_139 , V_2 ) ;
}
if ( V_121 <= 0 )
break;
F_181 ( V_240 , & V_2 -> V_338 ) ;
if ( F_605 ( V_2 ) )
F_606 ( V_2 ) ;
if ( F_543 ( V_2 ) &&
F_272 ( V_2 ) ) {
V_121 = 0 ;
V_2 -> V_847 -> V_863 = V_1157 ;
++ V_2 -> V_76 . V_1158 ;
break;
}
F_607 ( V_2 ) ;
if ( F_589 ( V_399 ) ) {
V_121 = - V_1156 ;
V_2 -> V_847 -> V_863 = V_1159 ;
++ V_2 -> V_76 . V_1160 ;
break;
}
if ( F_588 () ) {
F_238 ( & V_139 -> V_485 , V_2 -> V_1139 ) ;
F_608 () ;
V_2 -> V_1139 = F_237 ( & V_139 -> V_485 ) ;
}
}
F_238 ( & V_139 -> V_485 , V_2 -> V_1139 ) ;
return V_121 ;
}
static inline int F_609 ( struct V_1 * V_2 )
{
int V_121 ;
V_2 -> V_1139 = F_237 ( & V_2 -> V_139 -> V_485 ) ;
V_121 = F_610 ( V_2 , V_984 ) ;
F_238 ( & V_2 -> V_139 -> V_485 , V_2 -> V_1139 ) ;
if ( V_121 != V_949 )
return 0 ;
return 1 ;
}
static int V_997 ( struct V_1 * V_2 )
{
F_15 ( ! V_2 -> V_5 . V_878 . V_747 ) ;
return F_609 ( V_2 ) ;
}
static int V_998 ( struct V_1 * V_2 )
{
struct V_969 * V_847 = V_2 -> V_847 ;
struct V_845 * V_846 ;
unsigned V_95 ;
F_15 ( ! V_2 -> V_859 ) ;
V_846 = & V_2 -> V_842 [ V_2 -> V_860 ] ;
V_95 = F_355 ( 8u , V_846 -> V_95 ) ;
if ( ! V_2 -> V_862 )
memcpy ( V_846 -> V_39 , V_847 -> V_848 . V_39 , V_95 ) ;
if ( V_846 -> V_95 <= 8 ) {
V_846 ++ ;
V_2 -> V_860 ++ ;
} else {
V_846 -> V_39 += V_95 ;
V_846 -> V_388 += V_95 ;
V_846 -> V_95 -= V_95 ;
}
if ( V_2 -> V_860 >= V_2 -> V_853 ) {
V_2 -> V_859 = 0 ;
if ( V_2 -> V_862 )
return 1 ;
V_2 -> V_841 = 1 ;
return F_609 ( V_2 ) ;
}
V_847 -> V_863 = V_864 ;
V_847 -> V_848 . V_865 = V_846 -> V_388 ;
if ( V_2 -> V_862 )
memcpy ( V_847 -> V_848 . V_39 , V_846 -> V_39 , F_355 ( 8u , V_846 -> V_95 ) ) ;
V_847 -> V_848 . V_95 = F_355 ( 8u , V_846 -> V_95 ) ;
V_847 -> V_848 . V_861 = V_2 -> V_862 ;
V_2 -> V_5 . V_996 = V_998 ;
return 0 ;
}
int F_611 ( struct V_1 * V_2 , struct V_969 * V_969 )
{
struct V_1161 * V_1161 = & V_399 -> V_1162 . V_1161 ;
int V_121 ;
T_17 V_1163 ;
F_612 ( V_1161 ) ;
if ( V_2 -> V_1164 )
F_613 ( V_1165 , & V_2 -> V_1166 , & V_1163 ) ;
if ( F_171 ( V_2 -> V_5 . V_1041 == V_1167 ) ) {
F_602 ( V_2 ) ;
F_584 ( V_2 ) ;
F_181 ( V_1152 , & V_2 -> V_338 ) ;
V_121 = - V_1168 ;
goto V_113;
}
if ( ! F_91 ( V_2 ) ) {
if ( F_90 ( V_2 , V_969 -> V_177 ) != 0 ) {
V_121 = - V_579 ;
goto V_113;
}
}
if ( F_171 ( V_2 -> V_5 . V_996 ) ) {
int (* F_614)( struct V_1 * ) = V_2 -> V_5 . V_996 ;
V_2 -> V_5 . V_996 = NULL ;
V_121 = F_614 ( V_2 ) ;
if ( V_121 <= 0 )
goto V_113;
} else
F_30 ( V_2 -> V_5 . V_878 . V_747 || V_2 -> V_859 ) ;
V_121 = F_604 ( V_2 ) ;
V_113:
F_544 ( V_2 ) ;
if ( V_2 -> V_1164 )
F_613 ( V_1165 , & V_1163 , NULL ) ;
return V_121 ;
}
int F_615 ( struct V_1 * V_2 , struct V_1169 * V_1170 )
{
if ( V_2 -> V_5 . V_1000 ) {
F_616 ( & V_2 -> V_5 . V_929 ) ;
V_2 -> V_5 . V_1000 = false ;
}
V_1170 -> V_1171 = F_104 ( V_2 , V_203 ) ;
V_1170 -> V_1172 = F_104 ( V_2 , V_1059 ) ;
V_1170 -> V_1173 = F_104 ( V_2 , V_202 ) ;
V_1170 -> V_1174 = F_104 ( V_2 , V_204 ) ;
V_1170 -> V_1175 = F_104 ( V_2 , V_1060 ) ;
V_1170 -> V_1176 = F_104 ( V_2 , V_1177 ) ;
V_1170 -> V_1178 = F_104 ( V_2 , V_1179 ) ;
V_1170 -> V_1180 = F_104 ( V_2 , V_1181 ) ;
#ifdef F_64
V_1170 -> V_1182 = F_104 ( V_2 , V_1183 ) ;
V_1170 -> V_1184 = F_104 ( V_2 , V_1185 ) ;
V_1170 -> V_1186 = F_104 ( V_2 , V_1187 ) ;
V_1170 -> V_1188 = F_104 ( V_2 , V_1189 ) ;
V_1170 -> V_1190 = F_104 ( V_2 , V_1191 ) ;
V_1170 -> V_1192 = F_104 ( V_2 , V_1193 ) ;
V_1170 -> V_1194 = F_104 ( V_2 , V_1195 ) ;
V_1170 -> V_1196 = F_104 ( V_2 , V_1197 ) ;
#endif
V_1170 -> V_1067 = F_460 ( V_2 ) ;
V_1170 -> V_968 = F_459 ( V_2 ) ;
return 0 ;
}
int F_617 ( struct V_1 * V_2 , struct V_1169 * V_1170 )
{
V_2 -> V_5 . V_943 = true ;
V_2 -> V_5 . V_1000 = false ;
F_106 ( V_2 , V_203 , V_1170 -> V_1171 ) ;
F_106 ( V_2 , V_1059 , V_1170 -> V_1172 ) ;
F_106 ( V_2 , V_202 , V_1170 -> V_1173 ) ;
F_106 ( V_2 , V_204 , V_1170 -> V_1174 ) ;
F_106 ( V_2 , V_1060 , V_1170 -> V_1175 ) ;
F_106 ( V_2 , V_1177 , V_1170 -> V_1176 ) ;
F_106 ( V_2 , V_1179 , V_1170 -> V_1178 ) ;
F_106 ( V_2 , V_1181 , V_1170 -> V_1180 ) ;
#ifdef F_64
F_106 ( V_2 , V_1183 , V_1170 -> V_1182 ) ;
F_106 ( V_2 , V_1185 , V_1170 -> V_1184 ) ;
F_106 ( V_2 , V_1187 , V_1170 -> V_1186 ) ;
F_106 ( V_2 , V_1189 , V_1170 -> V_1188 ) ;
F_106 ( V_2 , V_1191 , V_1170 -> V_1190 ) ;
F_106 ( V_2 , V_1193 , V_1170 -> V_1192 ) ;
F_106 ( V_2 , V_1195 , V_1170 -> V_1194 ) ;
F_106 ( V_2 , V_1197 , V_1170 -> V_1196 ) ;
#endif
F_464 ( V_2 , V_1170 -> V_1067 ) ;
F_465 ( V_2 , V_1170 -> V_968 ) ;
V_2 -> V_5 . V_69 . V_70 = false ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
void F_618 ( struct V_1 * V_2 , int * V_183 , int * V_914 )
{
struct V_821 V_1086 ;
F_363 ( V_2 , & V_1086 , V_1091 ) ;
* V_183 = V_1086 . V_183 ;
* V_914 = V_1086 . V_914 ;
}
int F_619 ( struct V_1 * V_2 ,
struct V_1198 * V_1199 )
{
struct V_897 V_898 ;
F_363 ( V_2 , & V_1199 -> V_1086 , V_1091 ) ;
F_363 ( V_2 , & V_1199 -> V_1087 , V_1092 ) ;
F_363 ( V_2 , & V_1199 -> V_1200 , V_1093 ) ;
F_363 ( V_2 , & V_1199 -> V_1201 , V_1094 ) ;
F_363 ( V_2 , & V_1199 -> V_1202 , V_1095 ) ;
F_363 ( V_2 , & V_1199 -> V_1203 , V_1096 ) ;
F_363 ( V_2 , & V_1199 -> V_1204 , V_1084 ) ;
F_363 ( V_2 , & V_1199 -> V_1205 , V_1085 ) ;
V_87 -> V_900 ( V_2 , & V_898 ) ;
V_1199 -> V_1206 . V_909 = V_898 . V_490 ;
V_1199 -> V_1206 . V_230 = V_898 . V_79 ;
V_87 -> V_899 ( V_2 , & V_898 ) ;
V_1199 -> V_1207 . V_909 = V_898 . V_490 ;
V_1199 -> V_1207 . V_230 = V_898 . V_79 ;
V_1199 -> V_122 = F_63 ( V_2 ) ;
V_1199 -> V_78 = V_2 -> V_5 . V_78 ;
V_1199 -> V_104 = F_61 ( V_2 ) ;
V_1199 -> V_159 = F_80 ( V_2 ) ;
V_1199 -> V_177 = F_93 ( V_2 ) ;
V_1199 -> V_132 = V_2 -> V_5 . V_132 ;
V_1199 -> V_32 = F_21 ( V_2 ) ;
memset ( V_1199 -> V_1208 , 0 , sizeof V_1199 -> V_1208 ) ;
if ( V_2 -> V_5 . V_621 . V_70 && ! V_2 -> V_5 . V_621 . V_622 )
F_220 ( V_2 -> V_5 . V_621 . V_18 ,
( unsigned long * ) V_1199 -> V_1208 ) ;
return 0 ;
}
int F_620 ( struct V_1 * V_2 ,
struct V_1209 * V_1041 )
{
F_584 ( V_2 ) ;
if ( V_2 -> V_5 . V_1041 == V_1042 &&
V_2 -> V_5 . V_1153 . V_1154 )
V_1041 -> V_1041 = V_1155 ;
else
V_1041 -> V_1041 = V_2 -> V_5 . V_1041 ;
return 0 ;
}
int F_621 ( struct V_1 * V_2 ,
struct V_1209 * V_1041 )
{
if ( ! F_91 ( V_2 ) &&
V_1041 -> V_1041 != V_1155 )
return - V_579 ;
if ( V_1041 -> V_1041 == V_1210 ) {
V_2 -> V_5 . V_1041 = V_1133 ;
F_220 ( V_1211 , & V_2 -> V_5 . V_645 -> V_648 ) ;
} else
V_2 -> V_5 . V_1041 = V_1041 -> V_1041 ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
int F_622 ( struct V_1 * V_2 , V_874 V_1212 , int V_1213 ,
int V_1214 , bool V_72 , T_1 V_63 )
{
struct V_835 * V_836 = & V_2 -> V_5 . V_929 ;
int V_108 ;
F_458 ( V_2 ) ;
V_108 = F_623 ( V_836 , V_1212 , V_1213 , V_1214 ,
V_72 , V_63 ) ;
if ( V_108 )
return V_948 ;
F_464 ( V_2 , V_836 -> V_932 ) ;
F_465 ( V_2 , V_836 -> V_931 ) ;
F_32 ( V_68 , V_2 ) ;
return V_949 ;
}
int F_624 ( struct V_1 * V_2 ,
struct V_1198 * V_1199 )
{
struct V_33 V_1215 ;
int V_1216 = 0 ;
int V_1217 , V_1218 , V_484 ;
struct V_897 V_898 ;
if ( ! F_81 ( V_2 ) && ( V_1199 -> V_159 & V_142 ) )
return - V_579 ;
V_898 . V_490 = V_1199 -> V_1206 . V_909 ;
V_898 . V_79 = V_1199 -> V_1206 . V_230 ;
V_87 -> V_902 ( V_2 , & V_898 ) ;
V_898 . V_490 = V_1199 -> V_1207 . V_909 ;
V_898 . V_79 = V_1199 -> V_1207 . V_230 ;
V_87 -> V_901 ( V_2 , & V_898 ) ;
V_2 -> V_5 . V_78 = V_1199 -> V_78 ;
V_1216 |= F_61 ( V_2 ) != V_1199 -> V_104 ;
V_2 -> V_5 . V_104 = V_1199 -> V_104 ;
F_56 ( V_175 , ( V_176 * ) & V_2 -> V_5 . V_118 ) ;
F_90 ( V_2 , V_1199 -> V_177 ) ;
V_1216 |= V_2 -> V_5 . V_132 != V_1199 -> V_132 ;
V_87 -> F_110 ( V_2 , V_1199 -> V_132 ) ;
V_1215 . V_39 = V_1199 -> V_32 ;
V_1215 . V_41 = true ;
F_22 ( V_2 , & V_1215 ) ;
V_1216 |= F_63 ( V_2 ) != V_1199 -> V_122 ;
V_87 -> V_138 ( V_2 , V_1199 -> V_122 ) ;
V_2 -> V_5 . V_122 = V_1199 -> V_122 ;
V_1216 |= F_80 ( V_2 ) != V_1199 -> V_159 ;
V_87 -> V_171 ( V_2 , V_1199 -> V_159 ) ;
if ( V_1199 -> V_159 & ( V_142 | V_167 ) )
F_77 ( V_2 ) ;
V_484 = F_237 ( & V_2 -> V_139 -> V_485 ) ;
if ( ! F_58 ( V_2 ) && F_59 ( V_2 ) ) {
F_54 ( V_2 , V_2 -> V_5 . V_103 , F_61 ( V_2 ) ) ;
V_1216 = 1 ;
}
F_238 ( & V_2 -> V_139 -> V_485 , V_484 ) ;
if ( V_1216 )
F_67 ( V_2 ) ;
V_1218 = V_596 ;
V_1217 = F_625 (
( const unsigned long * ) V_1199 -> V_1208 , V_1218 ) ;
if ( V_1217 < V_1218 ) {
F_278 ( V_2 , V_1217 , false ) ;
F_133 ( L_28 , V_1217 ) ;
}
F_362 ( V_2 , & V_1199 -> V_1086 , V_1091 ) ;
F_362 ( V_2 , & V_1199 -> V_1087 , V_1092 ) ;
F_362 ( V_2 , & V_1199 -> V_1200 , V_1093 ) ;
F_362 ( V_2 , & V_1199 -> V_1201 , V_1094 ) ;
F_362 ( V_2 , & V_1199 -> V_1202 , V_1095 ) ;
F_362 ( V_2 , & V_1199 -> V_1203 , V_1096 ) ;
F_362 ( V_2 , & V_1199 -> V_1204 , V_1084 ) ;
F_362 ( V_2 , & V_1199 -> V_1205 , V_1085 ) ;
F_269 ( V_2 ) ;
if ( F_626 ( V_2 ) && F_460 ( V_2 ) == 0xfff0 &&
V_1199 -> V_1086 . V_903 == 0xf000 && V_1199 -> V_1086 . V_230 == 0xffff0000 &&
! F_33 ( V_2 ) )
V_2 -> V_5 . V_1041 = V_1155 ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
int F_627 ( struct V_1 * V_2 ,
struct V_1219 * V_1220 )
{
unsigned long V_968 ;
int V_3 , V_121 ;
if ( V_1220 -> V_754 & ( V_1221 | V_1222 ) ) {
V_121 = - V_802 ;
if ( V_2 -> V_5 . V_69 . V_70 )
goto V_113;
if ( V_1220 -> V_754 & V_1221 )
F_34 ( V_2 , V_54 ) ;
else
F_34 ( V_2 , V_55 ) ;
}
V_968 = F_459 ( V_2 ) ;
V_2 -> V_179 = V_1220 -> V_754 ;
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
F_97 ( V_2 ) ;
if ( V_2 -> V_179 & V_971 )
V_2 -> V_5 . V_975 = F_460 ( V_2 ) +
F_410 ( V_2 , V_1091 ) ;
F_465 ( V_2 , V_968 ) ;
V_87 -> V_1225 ( V_2 ) ;
V_121 = 0 ;
V_113:
return V_121 ;
}
int F_628 ( struct V_1 * V_2 ,
struct V_1226 * V_1204 )
{
unsigned long V_1227 = V_1204 -> V_1228 ;
T_6 V_388 ;
int V_484 ;
V_484 = F_237 ( & V_2 -> V_139 -> V_485 ) ;
V_388 = F_368 ( V_2 , V_1227 , NULL ) ;
F_238 ( & V_2 -> V_139 -> V_485 , V_484 ) ;
V_1204 -> V_1229 = V_388 ;
V_1204 -> V_659 = V_388 != V_100 ;
V_1204 -> V_1230 = 1 ;
V_1204 -> V_1231 = 0 ;
return 0 ;
}
int F_629 ( struct V_1 * V_2 , struct V_1232 * V_1161 )
{
struct V_672 * V_671 =
& V_2 -> V_5 . V_654 . V_655 . V_671 ;
memcpy ( V_1161 -> V_1233 , V_671 -> V_1234 , 128 ) ;
V_1161 -> V_1235 = V_671 -> V_1236 ;
V_1161 -> V_1237 = V_671 -> V_1238 ;
V_1161 -> V_1239 = V_671 -> V_1240 ;
V_1161 -> V_1241 = V_671 -> V_1242 ;
V_1161 -> V_1243 = V_671 -> V_1067 ;
V_1161 -> V_1244 = V_671 -> V_1245 ;
memcpy ( V_1161 -> V_1246 , V_671 -> V_1247 , sizeof V_671 -> V_1247 ) ;
return 0 ;
}
int F_630 ( struct V_1 * V_2 , struct V_1232 * V_1161 )
{
struct V_672 * V_671 =
& V_2 -> V_5 . V_654 . V_655 . V_671 ;
memcpy ( V_671 -> V_1234 , V_1161 -> V_1233 , 128 ) ;
V_671 -> V_1236 = V_1161 -> V_1235 ;
V_671 -> V_1238 = V_1161 -> V_1237 ;
V_671 -> V_1240 = V_1161 -> V_1239 ;
V_671 -> V_1242 = V_1161 -> V_1241 ;
V_671 -> V_1067 = V_1161 -> V_1243 ;
V_671 -> V_1245 = V_1161 -> V_1244 ;
memcpy ( V_671 -> V_1247 , V_1161 -> V_1246 , sizeof V_671 -> V_1247 ) ;
return 0 ;
}
static void F_631 ( struct V_1 * V_2 )
{
F_632 ( & V_2 -> V_5 . V_654 . V_655 ) ;
if ( F_245 ( V_665 ) )
V_2 -> V_5 . V_654 . V_655 . V_653 . V_657 . V_666 =
V_146 | V_667 ;
V_2 -> V_5 . V_145 = V_151 ;
V_2 -> V_5 . V_122 |= V_127 ;
}
void F_448 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1248 )
return;
V_2 -> V_1248 = 1 ;
F_633 () ;
F_634 ( & V_2 -> V_5 . V_654 . V_655 ) ;
F_635 ( 1 ) ;
}
void F_264 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_1248 )
return;
V_2 -> V_1248 = 0 ;
F_636 ( & V_2 -> V_5 . V_654 ) ;
F_637 () ;
++ V_2 -> V_76 . V_1249 ;
F_635 ( 0 ) ;
}
void F_638 ( struct V_1 * V_2 )
{
void * V_583 = V_2 -> V_5 . V_583 ;
F_213 ( V_2 ) ;
V_87 -> V_1250 ( V_2 ) ;
F_639 ( V_583 ) ;
}
struct V_1 * F_640 ( struct V_139 * V_139 ,
unsigned int V_1251 )
{
struct V_1 * V_2 ;
if ( F_157 () && F_144 ( & V_139 -> V_294 ) != 0 )
F_404 ( V_876
L_29
L_30 ) ;
V_2 = V_87 -> V_1252 ( V_139 , V_1251 ) ;
return V_2 ;
}
int F_641 ( struct V_1 * V_2 )
{
int V_121 ;
F_642 ( V_2 ) ;
V_121 = V_584 ( V_2 ) ;
if ( V_121 )
return V_121 ;
F_643 ( V_2 , false ) ;
F_644 ( V_2 ) ;
V_589 ( V_2 ) ;
return V_121 ;
}
void F_645 ( struct V_1 * V_2 )
{
struct V_33 V_22 ;
struct V_139 * V_139 = V_2 -> V_139 ;
if ( V_584 ( V_2 ) )
return;
V_22 . V_39 = 0x0 ;
V_22 . V_147 = V_1253 ;
V_22 . V_41 = true ;
F_154 ( V_2 , & V_22 ) ;
V_589 ( V_2 ) ;
if ( ! V_363 )
return;
F_200 ( & V_139 -> V_5 . V_362 ,
V_364 ) ;
}
void F_646 ( struct V_1 * V_2 )
{
int V_121 ;
V_2 -> V_5 . V_6 . V_389 = 0 ;
V_121 = V_584 ( V_2 ) ;
F_15 ( V_121 ) ;
F_578 ( V_2 ) ;
V_589 ( V_2 ) ;
V_87 -> V_1250 ( V_2 ) ;
}
void F_643 ( struct V_1 * V_2 , bool V_1254 )
{
V_2 -> V_5 . V_635 = 0 ;
V_2 -> V_5 . V_633 = 0 ;
F_175 ( & V_2 -> V_5 . V_84 , 0 ) ;
V_2 -> V_5 . V_627 = 0 ;
V_2 -> V_5 . V_626 = false ;
F_647 ( V_2 ) ;
F_483 ( V_2 ) ;
memset ( V_2 -> V_5 . V_183 , 0 , sizeof( V_2 -> V_5 . V_183 ) ) ;
F_95 ( V_2 ) ;
V_2 -> V_5 . V_187 = V_1255 ;
F_96 ( V_2 ) ;
V_2 -> V_5 . V_188 = V_199 ;
F_97 ( V_2 ) ;
V_2 -> V_5 . V_78 = 0 ;
F_32 ( V_68 , V_2 ) ;
V_2 -> V_5 . V_6 . V_389 = 0 ;
V_2 -> V_5 . V_393 . V_389 = 0 ;
F_213 ( V_2 ) ;
F_66 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1115 = false ;
if ( ! V_1254 ) {
F_648 ( V_2 ) ;
V_2 -> V_5 . V_424 = 0x30000 ;
}
memset ( V_2 -> V_5 . V_1170 , 0 , sizeof( V_2 -> V_5 . V_1170 ) ) ;
V_2 -> V_5 . V_118 = ~ 0 ;
V_2 -> V_5 . V_119 = ~ 0 ;
V_87 -> V_1256 ( V_2 , V_1254 ) ;
}
void F_649 ( struct V_1 * V_2 , T_13 V_42 )
{
struct V_821 V_1086 ;
F_363 ( V_2 , & V_1086 , V_1091 ) ;
V_1086 . V_903 = V_42 << 8 ;
V_1086 . V_230 = V_42 << 12 ;
F_362 ( V_2 , & V_1086 , V_1091 ) ;
F_464 ( V_2 , 0 ) ;
}
int F_650 ( void )
{
struct V_139 * V_139 ;
struct V_1 * V_2 ;
int V_3 ;
int V_108 ;
T_2 V_1257 ;
T_2 V_1258 = 0 ;
bool V_1259 , V_1260 = false ;
F_16 () ;
V_108 = V_87 -> V_1261 () ;
if ( V_108 != 0 )
return V_108 ;
V_1257 = F_151 () ;
V_1259 = ! F_157 () ;
F_498 (kvm, &vm_list, vm_list) {
F_180 (i, vcpu, kvm) {
if ( ! V_1259 && V_2 -> V_24 == F_10 () )
F_32 ( V_337 , V_2 ) ;
if ( V_1259 && V_2 -> V_5 . V_587 > V_1257 ) {
V_1260 = true ;
if ( V_2 -> V_5 . V_587 > V_1258 )
V_1258 = V_2 -> V_5 . V_587 ;
}
}
}
if ( V_1260 ) {
T_2 V_1262 = V_1258 - V_1257 ;
V_333 = true ;
F_498 (kvm, &vm_list, vm_list) {
F_180 (i, vcpu, kvm) {
V_2 -> V_5 . V_585 += V_1262 ;
V_2 -> V_5 . V_587 = V_1257 ;
F_32 ( V_297 , V_2 ) ;
}
V_139 -> V_5 . V_312 = 0 ;
V_139 -> V_5 . V_314 = 0 ;
}
}
return 0 ;
}
void F_651 ( void )
{
V_87 -> V_1263 () ;
F_20 () ;
}
int F_652 ( void )
{
int V_121 ;
V_121 = V_87 -> V_1264 () ;
if ( V_121 != 0 )
return V_121 ;
if ( V_271 ) {
T_2 V_1265 = F_355 ( 0x7fffffffULL ,
F_147 ( V_276 , V_272 ) ) ;
V_712 = V_1265 ;
V_270 = 1ULL << V_275 ;
}
F_352 () ;
return 0 ;
}
void F_653 ( void )
{
V_87 -> V_1266 () ;
}
void F_654 ( void * V_1267 )
{
V_87 -> V_1268 ( V_1267 ) ;
}
bool F_655 ( struct V_1 * V_2 )
{
return V_2 -> V_139 -> V_5 . V_803 == V_2 -> V_298 ;
}
bool F_626 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_32 & V_1269 ) != 0 ;
}
int F_656 ( struct V_1 * V_2 )
{
struct V_384 * V_384 ;
struct V_139 * V_139 ;
int V_121 ;
F_15 ( V_2 -> V_139 == NULL ) ;
V_139 = V_2 -> V_139 ;
V_2 -> V_5 . V_592 = V_87 -> V_1270 () ;
V_2 -> V_5 . V_1153 . V_1154 = false ;
V_2 -> V_5 . V_929 . V_850 = & V_1271 ;
if ( ! F_277 ( V_139 ) || F_655 ( V_2 ) )
V_2 -> V_5 . V_1041 = V_1155 ;
else
V_2 -> V_5 . V_1041 = V_1167 ;
V_384 = F_657 ( V_685 | V_1272 ) ;
if ( ! V_384 ) {
V_121 = - V_386 ;
goto V_1273;
}
V_2 -> V_5 . V_882 = F_658 ( V_384 ) ;
F_140 ( V_2 , V_1011 ) ;
V_121 = F_659 ( V_2 ) ;
if ( V_121 < 0 )
goto V_1274;
if ( F_277 ( V_139 ) ) {
V_121 = F_660 ( V_2 ) ;
if ( V_121 < 0 )
goto V_1275;
} else
F_661 ( & V_1276 ) ;
V_2 -> V_5 . V_373 = F_308 ( V_437 * sizeof( T_2 ) * 4 ,
V_685 ) ;
if ( ! V_2 -> V_5 . V_373 ) {
V_121 = - V_386 ;
goto V_1277;
}
V_2 -> V_5 . V_365 = V_437 ;
if ( ! F_662 ( & V_2 -> V_5 . V_583 , V_685 ) ) {
V_121 = - V_386 ;
goto V_1278;
}
F_631 ( V_2 ) ;
V_2 -> V_5 . V_301 = 0x0 ;
V_2 -> V_5 . V_355 = false ;
V_2 -> V_5 . V_154 = 0 ;
V_2 -> V_5 . V_1279 = V_1280 + V_660 ;
V_2 -> V_5 . V_1022 = F_663 ( V_2 ) ;
V_2 -> V_5 . V_1281 = V_1282 ;
F_1 ( V_2 ) ;
F_664 ( V_2 ) ;
V_2 -> V_5 . V_598 = - 1 ;
F_665 ( V_2 ) ;
return 0 ;
V_1278:
F_209 ( V_2 -> V_5 . V_373 ) ;
V_1277:
F_666 ( V_2 ) ;
V_1275:
F_667 ( V_2 ) ;
V_1274:
F_668 ( ( unsigned long ) V_2 -> V_5 . V_882 ) ;
V_1273:
return V_121 ;
}
void F_669 ( struct V_1 * V_2 )
{
int V_484 ;
F_670 ( V_2 ) ;
F_671 ( V_2 ) ;
F_209 ( V_2 -> V_5 . V_373 ) ;
F_666 ( V_2 ) ;
V_484 = F_237 ( & V_2 -> V_139 -> V_485 ) ;
F_667 ( V_2 ) ;
F_238 ( & V_2 -> V_139 -> V_485 , V_484 ) ;
F_668 ( ( unsigned long ) V_2 -> V_5 . V_882 ) ;
if ( ! F_91 ( V_2 ) )
F_672 ( & V_1276 ) ;
}
void F_673 ( struct V_1 * V_2 , int V_24 )
{
V_87 -> V_1283 ( V_2 , V_24 ) ;
}
int F_674 ( struct V_139 * V_139 , unsigned long type )
{
if ( type )
return - V_579 ;
F_675 ( & V_139 -> V_5 . V_1284 ) ;
F_676 ( & V_139 -> V_5 . V_1285 ) ;
F_676 ( & V_139 -> V_5 . V_1286 ) ;
F_676 ( & V_139 -> V_5 . V_1287 ) ;
F_175 ( & V_139 -> V_5 . V_1288 , 0 ) ;
F_220 ( V_762 , & V_139 -> V_5 . V_1289 ) ;
F_220 ( V_1290 ,
& V_139 -> V_5 . V_1289 ) ;
F_677 ( & V_139 -> V_5 . V_311 ) ;
F_678 ( & V_139 -> V_5 . V_1291 ) ;
F_678 ( & V_139 -> V_5 . V_1130 . V_1292 ) ;
F_679 ( & V_139 -> V_5 . V_324 ) ;
V_139 -> V_5 . V_247 = - F_156 () ;
F_174 ( V_139 ) ;
F_680 ( & V_139 -> V_5 . V_360 , F_196 ) ;
F_680 ( & V_139 -> V_5 . V_362 , F_201 ) ;
F_681 ( V_139 ) ;
F_682 ( V_139 ) ;
if ( V_87 -> V_1293 )
return V_87 -> V_1293 ( V_139 ) ;
return 0 ;
}
static void F_683 ( struct V_1 * V_2 )
{
int V_121 ;
V_121 = V_584 ( V_2 ) ;
F_15 ( V_121 ) ;
F_578 ( V_2 ) ;
V_589 ( V_2 ) ;
}
static void F_684 ( struct V_139 * V_139 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_180 (i, vcpu, kvm) {
F_66 ( V_2 ) ;
F_683 ( V_2 ) ;
}
F_180 (i, vcpu, kvm)
F_638 ( V_2 ) ;
F_317 ( & V_139 -> V_737 ) ;
for ( V_3 = 0 ; V_3 < F_144 ( & V_139 -> V_294 ) ; V_3 ++ )
V_139 -> V_1294 [ V_3 ] = NULL ;
F_175 ( & V_139 -> V_294 , 0 ) ;
F_319 ( & V_139 -> V_737 ) ;
}
void F_685 ( struct V_139 * V_139 )
{
F_686 ( & V_139 -> V_5 . V_362 ) ;
F_686 ( & V_139 -> V_5 . V_360 ) ;
F_687 ( V_139 ) ;
F_688 ( V_139 ) ;
}
int F_689 ( struct V_139 * V_139 , int V_1251 , T_6 V_388 , T_1 V_490 )
{
int V_3 , V_121 ;
unsigned long V_1295 ;
struct V_1296 * V_1297 = V_1296 ( V_139 ) ;
struct V_1298 * V_10 , V_869 ;
if ( F_30 ( V_1251 >= V_1299 ) )
return - V_579 ;
V_10 = F_690 ( V_1297 , V_1251 ) ;
if ( V_490 ) {
if ( V_10 -> V_1300 )
return - V_599 ;
V_1295 = F_691 ( NULL , 0 , V_490 , V_1301 | V_1302 ,
V_1303 | V_1304 , 0 ) ;
if ( F_206 ( ( void * ) V_1295 ) )
return F_207 ( ( void * ) V_1295 ) ;
} else {
if ( ! V_10 -> V_1300 )
return 0 ;
V_1295 = 0 ;
}
V_869 = * V_10 ;
for ( V_3 = 0 ; V_3 < V_1305 ; V_3 ++ ) {
struct V_1306 V_1307 ;
V_1307 . V_10 = V_1251 | ( V_3 << 16 ) ;
V_1307 . V_15 = 0 ;
V_1307 . V_1308 = V_388 ;
V_1307 . V_1309 = V_1295 ;
V_1307 . V_1310 = V_490 ;
V_121 = F_692 ( V_139 , & V_1307 ) ;
if ( V_121 < 0 )
return V_121 ;
}
if ( ! V_490 ) {
V_121 = F_693 ( V_869 . V_1309 , V_869 . V_1300 * V_107 ) ;
F_30 ( V_121 < 0 ) ;
}
return 0 ;
}
int F_694 ( struct V_139 * V_139 , int V_1251 , T_6 V_388 , T_1 V_490 )
{
int V_121 ;
F_317 ( & V_139 -> V_724 ) ;
V_121 = F_689 ( V_139 , V_1251 , V_388 , V_490 ) ;
F_319 ( & V_139 -> V_724 ) ;
return V_121 ;
}
void F_695 ( struct V_139 * V_139 )
{
if ( V_399 -> V_1311 == V_139 -> V_1311 ) {
F_694 ( V_139 , V_1312 , 0 , 0 ) ;
F_694 ( V_139 , V_1313 , 0 , 0 ) ;
F_694 ( V_139 , V_1314 , 0 , 0 ) ;
}
if ( V_87 -> V_1315 )
V_87 -> V_1315 ( V_139 ) ;
F_696 ( V_139 ) ;
F_209 ( V_139 -> V_5 . V_784 ) ;
F_209 ( V_139 -> V_5 . V_1316 ) ;
F_684 ( V_139 ) ;
F_697 ( F_698 ( V_139 -> V_5 . V_1317 , 1 ) ) ;
F_699 ( V_139 ) ;
}
void F_700 ( struct V_139 * V_139 , struct V_1298 * free ,
struct V_1298 * V_1318 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1319 ; ++ V_3 ) {
if ( ! V_1318 || free -> V_5 . V_1320 [ V_3 ] != V_1318 -> V_5 . V_1320 [ V_3 ] ) {
F_697 ( free -> V_5 . V_1320 [ V_3 ] ) ;
free -> V_5 . V_1320 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1318 || free -> V_5 . V_1321 [ V_3 - 1 ] !=
V_1318 -> V_5 . V_1321 [ V_3 - 1 ] ) {
F_697 ( free -> V_5 . V_1321 [ V_3 - 1 ] ) ;
free -> V_5 . V_1321 [ V_3 - 1 ] = NULL ;
}
}
F_701 ( free , V_1318 ) ;
}
int F_702 ( struct V_139 * V_139 , struct V_1298 * V_10 ,
unsigned long V_1300 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1319 ; ++ V_3 ) {
struct V_1322 * V_1323 ;
unsigned long V_1324 ;
int V_1325 ;
int V_763 = V_3 + 1 ;
V_1325 = F_703 ( V_10 -> V_1326 + V_1300 - 1 ,
V_10 -> V_1326 , V_763 ) + 1 ;
V_10 -> V_5 . V_1320 [ V_3 ] =
F_704 ( V_1325 * sizeof( * V_10 -> V_5 . V_1320 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1320 [ V_3 ] )
goto V_387;
if ( V_3 == 0 )
continue;
V_1323 = F_704 ( V_1325 * sizeof( * V_1323 ) ) ;
if ( ! V_1323 )
goto V_387;
V_10 -> V_5 . V_1321 [ V_3 - 1 ] = V_1323 ;
if ( V_10 -> V_1326 & ( F_705 ( V_763 ) - 1 ) )
V_1323 [ 0 ] . V_1327 = 1 ;
if ( ( V_10 -> V_1326 + V_1300 ) & ( F_705 ( V_763 ) - 1 ) )
V_1323 [ V_1325 - 1 ] . V_1327 = 1 ;
V_1324 = V_10 -> V_1309 >> V_106 ;
if ( ( V_10 -> V_1326 ^ V_1324 ) & ( F_705 ( V_763 ) - 1 ) ||
! F_706 () ) {
unsigned long V_812 ;
for ( V_812 = 0 ; V_812 < V_1325 ; ++ V_812 )
V_1323 [ V_812 ] . V_1327 = 1 ;
}
}
if ( F_707 ( V_10 , V_1300 ) )
goto V_387;
return 0 ;
V_387:
for ( V_3 = 0 ; V_3 < V_1319 ; ++ V_3 ) {
F_697 ( V_10 -> V_5 . V_1320 [ V_3 ] ) ;
V_10 -> V_5 . V_1320 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_697 ( V_10 -> V_5 . V_1321 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1321 [ V_3 - 1 ] = NULL ;
}
return - V_386 ;
}
void F_708 ( struct V_139 * V_139 , struct V_1296 * V_1297 )
{
F_709 ( V_139 , V_1297 ) ;
}
int F_710 ( struct V_139 * V_139 ,
struct V_1298 * V_1328 ,
const struct V_1306 * V_1329 ,
enum V_1330 V_1331 )
{
return 0 ;
}
static void F_711 ( struct V_139 * V_139 ,
struct V_1298 * V_870 )
{
if ( V_870 -> V_15 & V_1332 ) {
F_712 ( V_139 , V_870 ) ;
return;
}
if ( V_870 -> V_15 & V_1333 ) {
if ( V_87 -> V_1334 )
V_87 -> V_1334 ( V_139 , V_870 ) ;
else
F_712 ( V_139 , V_870 ) ;
} else {
if ( V_87 -> V_1335 )
V_87 -> V_1335 ( V_139 , V_870 ) ;
}
}
void F_713 ( struct V_139 * V_139 ,
const struct V_1306 * V_1329 ,
const struct V_1298 * V_869 ,
const struct V_1298 * V_870 ,
enum V_1330 V_1331 )
{
int V_1336 = 0 ;
if ( ! V_139 -> V_5 . V_725 )
V_1336 = F_714 ( V_139 ) ;
if ( V_1336 )
F_318 ( V_139 , V_1336 ) ;
if ( ( V_1331 != V_1337 ) &&
( V_869 -> V_15 & V_1333 ) &&
! ( V_870 -> V_15 & V_1333 ) )
F_715 ( V_139 , V_870 ) ;
if ( V_1331 != V_1337 )
F_711 ( V_139 , (struct V_1298 * ) V_870 ) ;
}
void F_716 ( struct V_139 * V_139 )
{
F_717 ( V_139 ) ;
}
void F_718 ( struct V_139 * V_139 ,
struct V_1298 * V_10 )
{
F_719 ( V_139 , V_10 ) ;
}
static inline bool F_720 ( struct V_1 * V_2 )
{
if ( ! F_721 ( & V_2 -> V_1338 . V_1339 ) )
return true ;
if ( F_722 ( V_2 ) )
return true ;
if ( V_2 -> V_5 . V_1153 . V_1154 )
return true ;
if ( F_144 ( & V_2 -> V_5 . V_84 ) )
return true ;
if ( F_60 ( V_600 , & V_2 -> V_338 ) )
return true ;
if ( F_273 ( V_2 ) &&
F_274 ( V_2 ) )
return true ;
if ( F_723 ( V_2 ) )
return true ;
return false ;
}
int F_601 ( struct V_1 * V_2 )
{
if ( F_468 ( V_2 ) && V_87 -> V_1080 )
V_87 -> V_1080 ( V_2 , false ) ;
return F_603 ( V_2 ) || F_720 ( V_2 ) ;
}
int F_724 ( struct V_1 * V_2 )
{
return F_725 ( V_2 ) == V_1138 ;
}
int F_273 ( struct V_1 * V_2 )
{
return V_87 -> V_1082 ( V_2 ) ;
}
unsigned long F_481 ( struct V_1 * V_2 )
{
if ( F_541 ( V_2 ) )
return F_460 ( V_2 ) ;
return ( T_1 ) ( F_410 ( V_2 , V_1091 ) +
F_460 ( V_2 ) ) ;
}
bool F_726 ( struct V_1 * V_2 , unsigned long V_1340 )
{
return F_481 ( V_2 ) == V_1340 ;
}
unsigned long F_459 ( struct V_1 * V_2 )
{
unsigned long V_968 ;
V_968 = V_87 -> V_978 ( V_2 ) ;
if ( V_2 -> V_179 & V_971 )
V_968 &= ~ V_970 ;
return V_968 ;
}
static void F_488 ( struct V_1 * V_2 , unsigned long V_968 )
{
if ( V_2 -> V_179 & V_971 &&
F_726 ( V_2 , V_2 -> V_5 . V_975 ) )
V_968 |= V_970 ;
V_87 -> V_1341 ( V_2 , V_968 ) ;
}
void F_465 ( struct V_1 * V_2 , unsigned long V_968 )
{
F_488 ( V_2 , V_968 ) ;
F_32 ( V_68 , V_2 ) ;
}
void F_727 ( struct V_1 * V_2 , struct V_1342 * V_357 )
{
int V_121 ;
if ( ( V_2 -> V_5 . V_83 . V_960 != V_357 -> V_5 . V_960 ) ||
V_357 -> V_1343 )
return;
V_121 = F_586 ( V_2 ) ;
if ( F_171 ( V_121 ) )
return;
if ( ! V_2 -> V_5 . V_83 . V_960 &&
V_357 -> V_5 . V_104 != V_2 -> V_5 . V_83 . V_1344 ( V_2 ) )
return;
V_2 -> V_5 . V_83 . V_1345 ( V_2 , V_357 -> V_828 , 0 , true ) ;
}
static inline T_1 F_728 ( T_5 V_102 )
{
return F_729 ( V_102 & 0xffffffff , F_730 ( V_4 ) ) ;
}
static inline T_1 F_731 ( T_1 V_1346 )
{
return ( V_1346 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_732 ( struct V_1 * V_2 , T_5 V_102 )
{
T_1 V_1346 = F_728 ( V_102 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1346 ] != ~ 0 )
V_1346 = F_731 ( V_1346 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1346 ] = V_102 ;
}
static T_1 F_733 ( struct V_1 * V_2 , T_5 V_102 )
{
int V_3 ;
T_1 V_1346 = F_728 ( V_102 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1346 ] != V_102 &&
V_2 -> V_5 . V_6 . V_7 [ V_1346 ] != ~ 0 ) ; V_3 ++ )
V_1346 = F_731 ( V_1346 ) ;
return V_1346 ;
}
bool F_734 ( struct V_1 * V_2 , T_5 V_102 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_733 ( V_2 , V_102 ) ] == V_102 ;
}
static void F_735 ( struct V_1 * V_2 , T_5 V_102 )
{
T_1 V_3 , V_812 , V_1347 ;
V_3 = V_812 = F_733 ( V_2 , V_102 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_812 = F_731 ( V_812 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_812 ] == ~ 0 )
return;
V_1347 = F_728 ( V_2 -> V_5 . V_6 . V_7 [ V_812 ] ) ;
} while ( ( V_3 <= V_812 ) ? ( V_3 < V_1347 && V_1347 <= V_812 ) : ( V_3 < V_1347 || V_1347 <= V_812 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_812 ] ;
V_3 = V_812 ;
}
}
static int F_736 ( struct V_1 * V_2 , T_1 V_196 )
{
return F_190 ( V_2 -> V_139 , & V_2 -> V_5 . V_6 . V_39 , & V_196 ,
sizeof( V_196 ) ) ;
}
void F_737 ( struct V_1 * V_2 ,
struct V_1342 * V_357 )
{
struct V_74 V_75 ;
F_738 ( V_357 -> V_5 . V_1348 , V_357 -> V_828 ) ;
F_732 ( V_2 , V_357 -> V_5 . V_102 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_389 & V_390 ) ||
( V_2 -> V_5 . V_6 . V_391 &&
V_87 -> V_88 ( V_2 ) == 0 ) )
F_32 ( V_1114 , V_2 ) ;
else if ( ! F_736 ( V_2 , V_1349 ) ) {
V_75 . V_42 = V_43 ;
V_75 . V_930 = true ;
V_75 . V_63 = 0 ;
V_75 . V_80 = false ;
V_75 . V_79 = V_357 -> V_5 . V_1348 ;
F_39 ( V_2 , & V_75 ) ;
}
}
void F_739 ( struct V_1 * V_2 ,
struct V_1342 * V_357 )
{
struct V_74 V_75 ;
F_740 ( V_357 -> V_5 . V_1348 , V_357 -> V_828 ) ;
if ( V_357 -> V_1343 )
V_357 -> V_5 . V_1348 = ~ 0 ;
else
F_735 ( V_2 , V_357 -> V_5 . V_102 ) ;
if ( ( V_2 -> V_5 . V_6 . V_389 & V_390 ) &&
! F_736 ( V_2 , V_1350 ) ) {
V_75 . V_42 = V_43 ;
V_75 . V_930 = true ;
V_75 . V_63 = 0 ;
V_75 . V_80 = false ;
V_75 . V_79 = V_357 -> V_5 . V_1348 ;
F_39 ( V_2 , & V_75 ) ;
}
V_2 -> V_5 . V_6 . V_1115 = false ;
V_2 -> V_5 . V_1041 = V_1155 ;
}
bool F_741 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_389 & V_390 ) )
return true ;
else
return ! F_275 ( V_2 ) &&
V_87 -> V_1082 ( V_2 ) ;
}
void F_742 ( struct V_139 * V_139 )
{
F_44 ( & V_139 -> V_5 . V_1351 ) ;
}
void F_743 ( struct V_139 * V_139 )
{
F_744 ( & V_139 -> V_5 . V_1351 ) ;
}
bool F_745 ( struct V_139 * V_139 )
{
return F_144 ( & V_139 -> V_5 . V_1351 ) ;
}
void F_746 ( struct V_139 * V_139 )
{
F_44 ( & V_139 -> V_5 . V_1288 ) ;
}
void F_747 ( struct V_139 * V_139 )
{
F_744 ( & V_139 -> V_5 . V_1288 ) ;
}
bool F_68 ( struct V_139 * V_139 )
{
return F_144 ( & V_139 -> V_5 . V_1288 ) ;
}
bool F_748 ( void )
{
return V_87 -> V_1352 != NULL ;
}
int F_749 ( struct V_1353 * V_1354 ,
struct V_1355 * V_1356 )
{
struct V_1357 * V_1358 =
F_4 ( V_1354 , struct V_1357 , V_1359 ) ;
V_1358 -> V_1360 = V_1356 ;
return V_87 -> V_1352 ( V_1358 -> V_139 ,
V_1356 -> V_595 , V_1358 -> V_1361 , 1 ) ;
}
void F_750 ( struct V_1353 * V_1354 ,
struct V_1355 * V_1356 )
{
int V_108 ;
struct V_1357 * V_1358 =
F_4 ( V_1354 , struct V_1357 , V_1359 ) ;
F_30 ( V_1358 -> V_1360 != V_1356 ) ;
V_1358 -> V_1360 = NULL ;
V_108 = V_87 -> V_1352 ( V_1358 -> V_139 , V_1356 -> V_595 , V_1358 -> V_1361 , 0 ) ;
if ( V_108 )
F_12 ( V_1362 L_31
L_32 , V_1358 -> V_1359 . V_1348 , V_108 ) ;
}
int F_751 ( struct V_139 * V_139 , unsigned int V_1363 ,
T_7 V_1364 , bool V_1365 )
{
if ( ! V_87 -> V_1352 )
return - V_579 ;
return V_87 -> V_1352 ( V_139 , V_1363 , V_1364 , V_1365 ) ;
}
bool F_752 ( void )
{
return V_1366 ;
}
