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
V_227 -> V_240 = V_225 -> V_241 ;
F_122 ( & V_227 -> V_232 ) ;
}
void F_123 ( struct V_1 * V_2 )
{
F_32 ( V_242 , V_2 ) ;
}
static void F_124 ( struct V_139 * V_139 , T_6 V_243 )
{
int V_244 ;
int V_121 ;
struct V_245 V_246 ;
struct V_247 V_248 ;
if ( ! V_243 )
return;
V_121 = F_125 ( V_139 , V_243 , & V_244 , sizeof( V_244 ) ) ;
if ( V_121 )
return;
if ( V_244 & 1 )
++ V_244 ;
++ V_244 ;
if ( F_126 ( V_139 , V_243 , & V_244 , sizeof( V_244 ) ) )
return;
F_127 ( & V_248 ) ;
if ( V_139 -> V_5 . V_249 ) {
struct V_247 V_250 = F_128 ( V_139 -> V_5 . V_249 ) ;
V_248 = F_129 ( V_248 , V_250 ) ;
}
V_246 . V_251 = ( T_1 ) V_248 . V_252 ;
V_246 . V_253 = V_248 . V_254 ;
V_246 . V_244 = V_244 ;
F_126 ( V_139 , V_243 , & V_246 , sizeof( V_246 ) ) ;
V_244 ++ ;
F_126 ( V_139 , V_243 , & V_244 , sizeof( V_244 ) ) ;
}
static T_7 F_130 ( T_7 V_255 , T_7 V_256 )
{
F_131 ( V_255 , V_256 ) ;
return V_255 ;
}
static void F_132 ( T_8 V_257 , T_8 V_258 ,
T_9 * V_259 , T_1 * V_260 )
{
T_8 V_261 ;
T_10 V_237 = 0 ;
T_8 V_262 ;
T_7 V_263 ;
V_262 = V_258 ;
V_261 = V_257 ;
while ( V_262 > V_261 * 2 || V_262 & 0xffffffff00000000ULL ) {
V_262 >>= 1 ;
V_237 -- ;
}
V_263 = ( T_7 ) V_262 ;
while ( V_263 <= V_261 || V_261 & 0xffffffff00000000ULL ) {
if ( V_261 & 0xffffffff00000000ULL || V_263 & 0x80000000 )
V_261 >>= 1 ;
else
V_263 <<= 1 ;
V_237 ++ ;
}
* V_259 = V_237 ;
* V_260 = F_130 ( V_261 , V_263 ) ;
F_133 ( L_2 ,
V_264 , V_258 , V_257 , V_237 , * V_260 ) ;
}
static T_1 F_134 ( T_1 V_265 , T_11 V_266 )
{
T_2 V_267 = ( T_2 ) V_265 * ( 1000000 + V_266 ) ;
F_135 ( V_267 , 1000000 ) ;
return V_267 ;
}
static int F_136 ( struct V_1 * V_2 , T_1 V_268 , bool V_269 )
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
F_137 ( 1 , L_3 ) ;
return - 1 ;
}
}
V_270 = F_138 ( 1ULL << V_277 ,
V_268 , V_274 ) ;
if ( V_270 == 0 || V_270 >= V_278 ) {
F_139 ( 1 , L_4 ,
V_268 ) ;
return - 1 ;
}
V_2 -> V_5 . V_271 = V_270 ;
return 0 ;
}
static int F_140 ( struct V_1 * V_2 , T_1 V_268 )
{
T_1 V_279 , V_280 ;
int V_281 = 0 ;
if ( V_268 == 0 ) {
V_2 -> V_5 . V_271 = V_272 ;
return - 1 ;
}
F_132 ( V_268 * 1000LL , V_282 ,
& V_2 -> V_5 . V_283 ,
& V_2 -> V_5 . V_284 ) ;
V_2 -> V_5 . V_285 = V_268 ;
V_279 = F_134 ( V_274 , - V_286 ) ;
V_280 = F_134 ( V_274 , V_286 ) ;
if ( V_268 < V_279 || V_268 > V_280 ) {
F_133 ( L_5 , V_268 , V_279 , V_280 ) ;
V_281 = 1 ;
}
return F_136 ( V_2 , V_268 , V_281 ) ;
}
static T_2 F_141 ( struct V_1 * V_2 , T_12 V_287 )
{
T_2 V_288 = F_142 ( V_287 - V_2 -> V_5 . V_289 ,
V_2 -> V_5 . V_284 ,
V_2 -> V_5 . V_283 ) ;
V_288 += V_2 -> V_5 . V_290 ;
return V_288 ;
}
static void F_143 ( struct V_1 * V_2 )
{
#ifdef F_64
bool V_291 ;
struct V_292 * V_293 = & V_2 -> V_139 -> V_5 ;
struct V_226 * V_294 = & V_226 ;
V_291 = ( V_293 -> V_295 + 1 ==
F_144 ( & V_2 -> V_139 -> V_296 ) ) ;
if ( V_293 -> V_297 ||
( V_294 -> clock . V_233 == V_298 && V_291 ) )
F_32 ( V_299 , V_2 ) ;
F_145 ( V_2 -> V_300 , V_293 -> V_295 ,
F_144 ( & V_2 -> V_139 -> V_296 ) ,
V_293 -> V_297 , V_294 -> clock . V_233 ) ;
#endif
}
static void F_146 ( struct V_1 * V_2 , T_12 V_94 )
{
T_2 V_301 = V_2 -> V_5 . V_302 ;
V_2 -> V_5 . V_303 += V_94 - V_301 ;
}
static inline T_2 F_147 ( T_2 V_270 , T_2 V_288 )
{
return F_148 ( V_288 , V_270 , V_277 ) ;
}
T_2 F_149 ( struct V_1 * V_2 , T_2 V_288 )
{
T_2 V_304 = V_288 ;
T_2 V_270 = V_2 -> V_5 . V_271 ;
if ( V_270 != V_272 )
V_304 = F_147 ( V_270 , V_288 ) ;
return V_304 ;
}
static T_2 F_150 ( struct V_1 * V_2 , T_2 V_305 )
{
T_2 V_288 ;
V_288 = F_149 ( V_2 , F_151 () ) ;
return V_305 - V_288 ;
}
T_2 F_152 ( struct V_1 * V_2 , T_2 V_306 )
{
return V_2 -> V_5 . V_302 + F_149 ( V_2 , V_306 ) ;
}
static void F_153 ( struct V_1 * V_2 , T_2 V_94 )
{
V_87 -> V_307 ( V_2 , V_94 ) ;
V_2 -> V_5 . V_302 = V_94 ;
}
void F_154 ( struct V_1 * V_2 , struct V_33 * V_22 )
{
struct V_139 * V_139 = V_2 -> V_139 ;
T_2 V_94 , V_308 , V_309 ;
unsigned long V_15 ;
T_12 V_310 ;
bool V_311 ;
bool V_312 ;
T_2 V_39 = V_22 -> V_39 ;
F_155 ( & V_139 -> V_5 . V_313 , V_15 ) ;
V_94 = F_150 ( V_2 , V_39 ) ;
V_308 = F_156 () ;
V_309 = V_308 - V_139 -> V_5 . V_314 ;
if ( V_2 -> V_5 . V_285 ) {
int V_315 = 0 ;
V_310 = V_39 - V_139 -> V_5 . V_316 ;
#ifdef F_64
V_310 = ( V_310 * 1000 ) / V_2 -> V_5 . V_285 ;
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
F_135 ( V_309 , 1000 ) ;
V_310 -= V_309 ;
if ( V_310 < 0 )
V_310 = - V_310 ;
if ( V_315 )
V_310 = V_317 ;
} else
V_310 = V_317 ;
if ( V_310 < V_317 &&
V_2 -> V_5 . V_285 == V_139 -> V_5 . V_318 ) {
if ( ! F_157 () ) {
V_94 = V_139 -> V_5 . V_319 ;
F_133 ( L_6 , V_39 ) ;
} else {
T_2 V_320 = F_158 ( V_2 , V_309 ) ;
V_39 += V_320 ;
V_94 = F_150 ( V_2 , V_39 ) ;
F_133 ( L_7 , V_320 ) ;
}
V_311 = true ;
V_312 = ( V_2 -> V_5 . V_321 == V_139 -> V_5 . V_322 ) ;
} else {
V_139 -> V_5 . V_322 ++ ;
V_139 -> V_5 . V_323 = V_308 ;
V_139 -> V_5 . V_324 = V_39 ;
V_139 -> V_5 . V_319 = V_94 ;
V_311 = false ;
F_133 ( L_8 ,
V_139 -> V_5 . V_322 , V_39 ) ;
}
V_139 -> V_5 . V_314 = V_308 ;
V_139 -> V_5 . V_316 = V_39 ;
V_139 -> V_5 . V_318 = V_2 -> V_5 . V_285 ;
V_2 -> V_5 . V_325 = V_39 ;
V_2 -> V_5 . V_321 = V_139 -> V_5 . V_322 ;
V_2 -> V_5 . V_289 = V_139 -> V_5 . V_323 ;
V_2 -> V_5 . V_290 = V_139 -> V_5 . V_324 ;
if ( F_159 ( V_2 ) && ! V_22 -> V_41 )
F_146 ( V_2 , V_94 ) ;
F_153 ( V_2 , V_94 ) ;
F_160 ( & V_139 -> V_5 . V_313 , V_15 ) ;
F_161 ( & V_139 -> V_5 . V_326 ) ;
if ( ! V_311 ) {
V_139 -> V_5 . V_295 = 0 ;
} else if ( ! V_312 ) {
V_139 -> V_5 . V_295 ++ ;
}
F_143 ( V_2 ) ;
F_162 ( & V_139 -> V_5 . V_326 ) ;
}
static inline void F_163 ( struct V_1 * V_2 ,
T_12 V_327 )
{
F_153 ( V_2 , V_2 -> V_5 . V_302 + V_327 ) ;
}
static inline void F_164 ( struct V_1 * V_2 , T_12 V_327 )
{
if ( V_2 -> V_5 . V_271 != V_272 )
F_30 ( V_327 < 0 ) ;
V_327 = F_149 ( V_2 , ( T_2 ) V_327 ) ;
F_163 ( V_2 , V_327 ) ;
}
static T_2 F_165 ( void )
{
T_2 V_108 = ( T_2 ) F_166 () ;
T_2 V_328 = V_226 . clock . V_235 ;
if ( F_167 ( V_108 >= V_328 ) )
return V_108 ;
asm volatile ("");
return V_328 ;
}
static inline T_2 F_168 ( T_2 * V_329 )
{
long V_267 ;
struct V_226 * V_294 = & V_226 ;
* V_329 = F_165 () ;
V_267 = ( * V_329 - V_294 -> clock . V_235 ) & V_294 -> clock . V_29 ;
return V_267 * V_294 -> clock . V_236 ;
}
static int F_169 ( T_12 * V_330 , T_2 * V_329 )
{
struct V_226 * V_294 = & V_226 ;
unsigned long V_232 ;
int V_331 ;
T_2 V_308 ;
do {
V_232 = F_170 ( & V_294 -> V_232 ) ;
V_331 = V_294 -> clock . V_233 ;
V_308 = V_294 -> V_238 ;
V_308 += F_168 ( V_329 ) ;
V_308 >>= V_294 -> clock . V_237 ;
V_308 += V_294 -> V_228 ;
} while ( F_171 ( F_172 ( & V_294 -> V_232 , V_232 ) ) );
* V_330 = V_308 ;
return V_331 ;
}
static int F_173 ( struct V_332 * V_250 , T_2 * V_329 )
{
struct V_226 * V_294 = & V_226 ;
unsigned long V_232 ;
int V_331 ;
T_2 V_308 ;
do {
V_232 = F_170 ( & V_294 -> V_232 ) ;
V_331 = V_294 -> clock . V_233 ;
V_250 -> V_252 = V_294 -> V_240 ;
V_308 = V_294 -> V_238 ;
V_308 += F_168 ( V_329 ) ;
V_308 >>= V_294 -> clock . V_237 ;
} while ( F_171 ( F_172 ( & V_294 -> V_232 , V_232 ) ) );
V_250 -> V_252 += F_174 ( V_308 , V_282 , & V_308 ) ;
V_250 -> V_254 = V_308 ;
return V_331 ;
}
static bool F_175 ( T_12 * V_287 , T_2 * V_329 )
{
if ( V_226 . clock . V_233 != V_298 )
return false ;
return F_169 ( V_287 , V_329 ) == V_298 ;
}
static bool F_176 ( struct V_332 * V_250 ,
T_2 * V_329 )
{
if ( V_226 . clock . V_233 != V_298 )
return false ;
return F_173 ( V_250 , V_329 ) == V_298 ;
}
static void F_177 ( struct V_139 * V_139 )
{
#ifdef F_64
struct V_292 * V_293 = & V_139 -> V_5 ;
int V_233 ;
bool V_333 , V_291 ;
V_291 = ( V_293 -> V_295 + 1 ==
F_144 ( & V_139 -> V_296 ) ) ;
V_333 = F_175 (
& V_293 -> V_334 ,
& V_293 -> V_335 ) ;
V_293 -> V_297 = V_333 && V_291
&& ! V_336
&& ! V_293 -> V_337 ;
if ( V_293 -> V_297 )
F_178 ( & V_338 , 1 ) ;
V_233 = V_226 . clock . V_233 ;
F_179 ( V_293 -> V_297 , V_233 ,
V_291 ) ;
#endif
}
void F_180 ( struct V_139 * V_139 )
{
F_181 ( V_139 , V_339 ) ;
}
static void F_182 ( struct V_139 * V_139 )
{
#ifdef F_64
int V_3 ;
struct V_1 * V_2 ;
struct V_292 * V_293 = & V_139 -> V_5 ;
F_161 ( & V_293 -> V_326 ) ;
F_180 ( V_139 ) ;
F_177 ( V_139 ) ;
F_183 (i, vcpu, kvm)
F_32 ( V_340 , V_2 ) ;
F_183 (i, vcpu, kvm)
F_184 ( V_339 , & V_2 -> V_341 ) ;
F_162 ( & V_293 -> V_326 ) ;
#endif
}
static T_2 F_185 ( struct V_139 * V_139 )
{
struct V_292 * V_293 = & V_139 -> V_5 ;
struct V_342 V_343 ;
F_161 ( & V_293 -> V_326 ) ;
if ( ! V_293 -> V_297 ) {
F_162 ( & V_293 -> V_326 ) ;
return F_156 () + V_293 -> V_249 ;
}
V_343 . V_344 = V_293 -> V_335 ;
V_343 . V_345 = V_293 -> V_334 + V_293 -> V_249 ;
F_162 ( & V_293 -> V_326 ) ;
F_132 ( V_282 , F_186 ( V_346 ) * 1000LL ,
& V_343 . V_347 ,
& V_343 . V_348 ) ;
return F_187 ( & V_343 , F_151 () ) ;
}
T_2 F_188 ( struct V_139 * V_139 )
{
unsigned long V_15 ;
T_12 V_308 ;
F_5 ( V_15 ) ;
V_308 = F_185 ( V_139 ) ;
F_7 ( V_15 ) ;
return V_308 ;
}
static void F_189 ( struct V_1 * V_267 )
{
struct V_349 * V_2 = & V_267 -> V_5 ;
struct V_342 V_350 ;
if ( F_171 ( F_190 ( V_267 , & V_2 -> V_351 ,
& V_350 , sizeof( V_350 ) ) ) )
return;
F_191 ( F_192 ( struct V_342 , V_244 ) != 0 ) ;
V_2 -> V_343 . V_244 = V_350 . V_244 + 1 ;
F_193 ( V_267 , & V_2 -> V_351 ,
& V_2 -> V_343 ,
sizeof( V_2 -> V_343 . V_244 ) ) ;
F_194 () ;
V_2 -> V_343 . V_15 |= ( V_350 . V_15 & V_352 ) ;
if ( V_2 -> V_353 ) {
V_2 -> V_343 . V_15 |= V_352 ;
V_2 -> V_353 = false ;
}
F_195 ( V_267 -> V_300 , & V_2 -> V_343 ) ;
F_193 ( V_267 , & V_2 -> V_351 ,
& V_2 -> V_343 ,
sizeof( V_2 -> V_343 ) ) ;
F_194 () ;
V_2 -> V_343 . V_244 ++ ;
F_193 ( V_267 , & V_2 -> V_351 ,
& V_2 -> V_343 ,
sizeof( V_2 -> V_343 . V_244 ) ) ;
}
static int F_196 ( struct V_1 * V_267 )
{
unsigned long V_15 , V_354 ;
struct V_349 * V_2 = & V_267 -> V_5 ;
struct V_292 * V_293 = & V_267 -> V_139 -> V_5 ;
T_12 V_287 ;
T_2 V_344 , V_306 ;
T_13 V_355 ;
bool V_297 ;
V_287 = 0 ;
V_306 = 0 ;
F_161 ( & V_293 -> V_326 ) ;
V_297 = V_293 -> V_297 ;
if ( V_297 ) {
V_306 = V_293 -> V_335 ;
V_287 = V_293 -> V_334 ;
}
F_162 ( & V_293 -> V_326 ) ;
F_5 ( V_15 ) ;
V_354 = F_186 ( V_346 ) ;
if ( F_171 ( V_354 == 0 ) ) {
F_7 ( V_15 ) ;
F_32 ( V_340 , V_267 ) ;
return 1 ;
}
if ( ! V_297 ) {
V_306 = F_151 () ;
V_287 = F_156 () ;
}
V_344 = F_152 ( V_267 , V_306 ) ;
if ( V_2 -> V_275 ) {
T_2 V_288 = F_141 ( V_267 , V_287 ) ;
if ( V_288 > V_344 ) {
F_163 ( V_267 , V_288 - V_344 ) ;
V_344 = V_288 ;
}
}
F_7 ( V_15 ) ;
if ( V_273 )
V_354 = F_149 ( V_267 , V_354 ) ;
if ( F_171 ( V_2 -> V_356 != V_354 ) ) {
F_132 ( V_282 , V_354 * 1000LL ,
& V_2 -> V_343 . V_347 ,
& V_2 -> V_343 . V_348 ) ;
V_2 -> V_356 = V_354 ;
}
V_2 -> V_343 . V_344 = V_344 ;
V_2 -> V_343 . V_345 = V_287 + V_267 -> V_139 -> V_5 . V_249 ;
V_2 -> V_325 = V_344 ;
V_355 = 0 ;
if ( V_297 )
V_355 |= V_357 ;
V_2 -> V_343 . V_15 = V_355 ;
if ( V_2 -> V_358 )
F_189 ( V_267 ) ;
if ( V_267 == F_197 ( V_267 -> V_139 , 0 ) )
F_198 ( V_267 -> V_139 , & V_2 -> V_343 ) ;
return 0 ;
}
static void F_199 ( struct V_359 * V_360 )
{
int V_3 ;
struct V_361 * V_362 = F_200 ( V_360 ) ;
struct V_292 * V_293 = F_4 ( V_362 , struct V_292 ,
V_363 ) ;
struct V_139 * V_139 = F_4 ( V_293 , struct V_139 , V_5 ) ;
struct V_1 * V_2 ;
F_183 (i, vcpu, kvm) {
F_32 ( V_340 , V_2 ) ;
F_201 ( V_2 ) ;
}
}
static void F_202 ( struct V_1 * V_267 )
{
struct V_139 * V_139 = V_267 -> V_139 ;
F_32 ( V_340 , V_267 ) ;
F_203 ( & V_139 -> V_5 . V_363 ,
V_364 ) ;
}
static void F_204 ( struct V_359 * V_360 )
{
struct V_361 * V_362 = F_200 ( V_360 ) ;
struct V_292 * V_293 = F_4 ( V_362 , struct V_292 ,
V_365 ) ;
struct V_139 * V_139 = F_4 ( V_293 , struct V_139 , V_5 ) ;
if ( ! V_366 )
return;
F_203 ( & V_139 -> V_5 . V_363 , 0 ) ;
F_203 ( & V_139 -> V_5 . V_365 ,
V_367 ) ;
}
static int F_205 ( struct V_1 * V_2 , T_1 V_22 , T_2 V_39 )
{
T_2 V_368 = V_2 -> V_5 . V_368 ;
unsigned V_369 = V_368 & 0xff ;
switch ( V_22 ) {
case V_370 :
V_2 -> V_5 . V_371 = V_39 ;
break;
case V_372 :
if ( ! ( V_368 & V_373 ) )
return 1 ;
if ( V_39 != 0 && V_39 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_374 = V_39 ;
break;
default:
if ( V_22 >= V_375 &&
V_22 < F_206 ( V_369 ) ) {
T_1 V_94 = V_22 - V_375 ;
if ( ( V_94 & 0x3 ) == 0 &&
V_39 != 0 && ( V_39 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_376 [ V_94 ] = V_39 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_207 ( struct V_1 * V_2 , T_2 V_39 )
{
struct V_139 * V_139 = V_2 -> V_139 ;
int V_377 = F_58 ( V_2 ) ;
T_13 * V_378 = V_377 ? ( T_13 * ) ( long ) V_139 -> V_5 . F_207 . V_379
: ( T_13 * ) ( long ) V_139 -> V_5 . F_207 . V_380 ;
T_13 V_381 = V_377 ? V_139 -> V_5 . F_207 . V_382
: V_139 -> V_5 . F_207 . V_383 ;
T_1 V_384 = V_39 & ~ V_385 ;
T_2 V_386 = V_39 & V_385 ;
T_13 * V_387 ;
int V_121 ;
V_121 = - V_388 ;
if ( V_384 >= V_381 )
goto V_113;
V_121 = - V_389 ;
V_387 = F_208 ( V_378 + ( V_384 * V_107 ) , V_107 ) ;
if ( F_209 ( V_387 ) ) {
V_121 = F_210 ( V_387 ) ;
goto V_113;
}
if ( F_211 ( V_2 , V_386 , V_387 , V_107 ) )
goto V_390;
V_121 = 0 ;
V_390:
F_212 ( V_387 ) ;
V_113:
return V_121 ;
}
static int F_213 ( struct V_1 * V_2 , T_2 V_39 )
{
T_6 V_391 = V_39 & ~ 0x3f ;
if ( V_39 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_392 = V_39 ;
if ( ! ( V_39 & V_393 ) ) {
F_66 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_214 ( V_2 , & V_2 -> V_5 . V_6 . V_39 , V_391 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_394 = ! ( V_39 & V_395 ) ;
F_215 ( V_2 ) ;
return 0 ;
}
static void F_216 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_358 = false ;
}
static void F_217 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_396 . V_392 & V_397 ) )
return;
if ( F_171 ( F_190 ( V_2 , & V_2 -> V_5 . V_396 . V_398 ,
& V_2 -> V_5 . V_396 . V_399 , sizeof( struct V_400 ) ) ) )
return;
V_2 -> V_5 . V_396 . V_399 . V_401 = 0 ;
if ( V_2 -> V_5 . V_396 . V_399 . V_244 & 1 )
V_2 -> V_5 . V_396 . V_399 . V_244 += 1 ;
V_2 -> V_5 . V_396 . V_399 . V_244 += 1 ;
F_193 ( V_2 , & V_2 -> V_5 . V_396 . V_398 ,
& V_2 -> V_5 . V_396 . V_399 , sizeof( struct V_400 ) ) ;
F_194 () ;
V_2 -> V_5 . V_396 . V_399 . V_399 += V_402 -> V_403 . V_404 -
V_2 -> V_5 . V_396 . V_405 ;
V_2 -> V_5 . V_396 . V_405 = V_402 -> V_403 . V_404 ;
F_193 ( V_2 , & V_2 -> V_5 . V_396 . V_398 ,
& V_2 -> V_5 . V_396 . V_399 , sizeof( struct V_400 ) ) ;
F_194 () ;
V_2 -> V_5 . V_396 . V_399 . V_244 += 1 ;
F_193 ( V_2 , & V_2 -> V_5 . V_396 . V_398 ,
& V_2 -> V_5 . V_396 . V_399 , sizeof( struct V_400 ) ) ;
}
int F_218 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
bool V_406 = false ;
T_1 V_22 = V_34 -> V_147 ;
T_2 V_39 = V_34 -> V_39 ;
switch ( V_22 ) {
case V_407 :
case V_408 :
case V_409 :
case V_410 :
case V_411 :
case V_412 :
break;
case V_413 :
return F_110 ( V_2 , V_39 ) ;
case V_414 :
V_39 &= ~ ( T_2 ) 0x40 ;
V_39 &= ~ ( T_2 ) 0x100 ;
V_39 &= ~ ( T_2 ) 0x8 ;
V_39 &= ~ ( T_2 ) 0x40000 ;
if ( V_39 != 0 ) {
F_219 ( V_2 , L_9 ,
V_39 ) ;
return 1 ;
}
break;
case V_415 :
if ( V_39 != 0 ) {
F_219 ( V_2 , L_10
L_11 , V_39 ) ;
return 1 ;
}
break;
case V_416 :
if ( ! V_39 ) {
break;
} else if ( V_39 & ~ ( V_417 | V_418 ) ) {
return 1 ;
}
F_219 ( V_2 , L_12 ,
V_264 , V_39 ) ;
break;
case 0x200 ... 0x2ff :
return F_220 ( V_2 , V_22 , V_39 ) ;
case V_419 :
return F_22 ( V_2 , V_34 ) ;
case V_420 ... V_420 + 0x3ff :
return F_221 ( V_2 , V_22 , V_39 ) ;
case V_421 :
F_222 ( V_2 , V_39 ) ;
break;
case V_422 :
if ( F_159 ( V_2 ) ) {
if ( ! V_34 -> V_41 ) {
T_12 V_423 = V_39 - V_2 -> V_5 . V_303 ;
F_163 ( V_2 , V_423 ) ;
}
V_2 -> V_5 . V_303 = V_39 ;
}
break;
case V_424 :
V_2 -> V_5 . V_425 = V_39 ;
break;
case V_426 :
if ( ! V_34 -> V_41 )
return 1 ;
V_2 -> V_5 . V_427 = V_39 ;
break;
case V_428 :
case V_429 :
V_2 -> V_139 -> V_5 . V_243 = V_39 ;
F_124 ( V_2 -> V_139 , V_39 ) ;
break;
case V_430 :
case V_431 : {
struct V_292 * V_293 = & V_2 -> V_139 -> V_5 ;
F_216 ( V_2 ) ;
if ( V_2 -> V_300 == 0 && ! V_34 -> V_41 ) {
bool V_432 = ( V_22 == V_431 ) ;
if ( V_293 -> V_337 != V_432 )
F_223 ( V_299 ,
& V_2 -> V_341 ) ;
V_293 -> V_337 = V_432 ;
}
V_2 -> V_5 . time = V_39 ;
F_32 ( V_433 , V_2 ) ;
if ( ! ( V_39 & 1 ) )
break;
if ( F_214 ( V_2 ,
& V_2 -> V_5 . V_351 , V_39 & ~ 1ULL ,
sizeof( struct V_342 ) ) )
V_2 -> V_5 . V_358 = false ;
else
V_2 -> V_5 . V_358 = true ;
break;
}
case V_434 :
if ( F_213 ( V_2 , V_39 ) )
return 1 ;
break;
case V_435 :
if ( F_171 ( ! F_224 () ) )
return 1 ;
if ( V_39 & V_436 )
return 1 ;
if ( F_214 ( V_2 , & V_2 -> V_5 . V_396 . V_398 ,
V_39 & V_437 ,
sizeof( struct V_400 ) ) )
return 1 ;
V_2 -> V_5 . V_396 . V_392 = V_39 ;
if ( ! ( V_39 & V_397 ) )
break;
F_32 ( V_438 , V_2 ) ;
break;
case V_439 :
if ( F_225 ( V_2 , V_39 ) )
return 1 ;
break;
case V_372 :
case V_370 :
case V_375 ... F_206 ( V_440 ) - 1 :
return F_205 ( V_2 , V_22 , V_39 ) ;
case V_441 ... V_442 :
case V_443 ... V_444 :
V_406 = true ;
case V_445 ... V_446 :
case V_447 ... V_448 :
if ( F_226 ( V_2 , V_22 ) )
return F_227 ( V_2 , V_34 ) ;
if ( V_406 || V_39 != 0 )
F_219 ( V_2 , L_13
L_14 , V_22 , V_39 ) ;
break;
case V_449 :
break;
case V_450 ... V_451 :
case V_452 ... V_453 :
case V_454 :
case V_455 ... V_456 :
return F_228 ( V_2 , V_22 , V_39 ,
V_34 -> V_41 ) ;
case V_457 :
F_219 ( V_2 , L_15 , V_22 , V_39 ) ;
break;
case V_458 :
if ( ! F_229 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_459 . V_460 = V_39 ;
break;
case V_461 :
if ( ! F_229 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_459 . V_462 = V_39 ;
break;
default:
if ( V_22 && ( V_22 == V_2 -> V_139 -> V_5 . F_207 . V_22 ) )
return F_207 ( V_2 , V_39 ) ;
if ( F_226 ( V_2 , V_22 ) )
return F_227 ( V_2 , V_34 ) ;
if ( ! V_463 ) {
F_230 ( V_2 , L_16 ,
V_22 , V_39 ) ;
return 1 ;
} else {
F_219 ( V_2 , L_15 ,
V_22 , V_39 ) ;
break;
}
}
return 0 ;
}
int F_116 ( struct V_1 * V_2 , struct V_33 * V_22 )
{
return V_87 -> V_464 ( V_2 , V_22 ) ;
}
static int F_231 ( struct V_1 * V_2 , T_1 V_22 , T_2 * V_465 )
{
T_2 V_39 ;
T_2 V_368 = V_2 -> V_5 . V_368 ;
unsigned V_369 = V_368 & 0xff ;
switch ( V_22 ) {
case V_466 :
case V_467 :
V_39 = 0 ;
break;
case V_468 :
V_39 = V_2 -> V_5 . V_368 ;
break;
case V_372 :
if ( ! ( V_368 & V_373 ) )
return 1 ;
V_39 = V_2 -> V_5 . V_374 ;
break;
case V_370 :
V_39 = V_2 -> V_5 . V_371 ;
break;
default:
if ( V_22 >= V_375 &&
V_22 < F_206 ( V_369 ) ) {
T_1 V_94 = V_22 - V_375 ;
V_39 = V_2 -> V_5 . V_376 [ V_94 ] ;
break;
}
return 1 ;
}
* V_465 = V_39 ;
return 0 ;
}
int F_232 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
switch ( V_34 -> V_147 ) {
case V_469 :
case V_470 :
case V_416 :
case V_471 :
case V_472 :
case V_473 :
case V_474 :
case V_475 :
case V_476 :
case V_477 :
case V_414 :
case V_410 :
case V_478 :
case V_407 :
case V_415 :
case V_412 :
case V_479 :
V_34 -> V_39 = 0 ;
break;
case V_445 ... V_446 :
case V_441 ... V_442 :
case V_443 ... V_444 :
case V_447 ... V_448 :
if ( F_226 ( V_2 , V_34 -> V_147 ) )
return F_233 ( V_2 , V_34 -> V_147 , & V_34 -> V_39 ) ;
V_34 -> V_39 = 0 ;
break;
case V_408 :
V_34 -> V_39 = 0x100000000ULL ;
break;
case V_480 :
case 0x200 ... 0x2ff :
return F_234 ( V_2 , V_34 -> V_147 , & V_34 -> V_39 ) ;
case 0xcd :
V_34 -> V_39 = 3 ;
break;
case V_481 :
V_34 -> V_39 = 1 << 24 ;
break;
case V_419 :
V_34 -> V_39 = F_21 ( V_2 ) ;
break;
case V_420 ... V_420 + 0x3ff :
return F_235 ( V_2 , V_34 -> V_147 , & V_34 -> V_39 ) ;
break;
case V_421 :
V_34 -> V_39 = F_236 ( V_2 ) ;
break;
case V_422 :
V_34 -> V_39 = ( T_2 ) V_2 -> V_5 . V_303 ;
break;
case V_424 :
V_34 -> V_39 = V_2 -> V_5 . V_425 ;
break;
case V_426 :
if ( ! V_34 -> V_41 )
return 1 ;
V_34 -> V_39 = V_2 -> V_5 . V_427 ;
break;
case V_482 :
V_34 -> V_39 = 1000ULL ;
V_34 -> V_39 |= ( ( ( T_8 ) 4ULL ) << 40 ) ;
break;
case V_413 :
V_34 -> V_39 = V_2 -> V_5 . V_132 ;
break;
case V_429 :
case V_428 :
V_34 -> V_39 = V_2 -> V_139 -> V_5 . V_243 ;
break;
case V_431 :
case V_430 :
V_34 -> V_39 = V_2 -> V_5 . time ;
break;
case V_434 :
V_34 -> V_39 = V_2 -> V_5 . V_6 . V_392 ;
break;
case V_435 :
V_34 -> V_39 = V_2 -> V_5 . V_396 . V_392 ;
break;
case V_439 :
V_34 -> V_39 = V_2 -> V_5 . V_483 . V_392 ;
break;
case V_466 :
case V_467 :
case V_468 :
case V_372 :
case V_370 :
case V_375 ... F_206 ( V_440 ) - 1 :
return F_231 ( V_2 , V_34 -> V_147 , & V_34 -> V_39 ) ;
case V_449 :
V_34 -> V_39 = 0x20000000 ;
break;
case V_450 ... V_451 :
case V_452 ... V_453 :
case V_454 :
case V_455 ... V_456 :
return F_237 ( V_2 ,
V_34 -> V_147 , & V_34 -> V_39 ) ;
break;
case V_457 :
V_34 -> V_39 = 0xbe702111 ;
break;
case V_458 :
if ( ! F_229 ( V_2 ) )
return 1 ;
V_34 -> V_39 = V_2 -> V_5 . V_459 . V_460 ;
break;
case V_461 :
if ( ! F_229 ( V_2 ) )
return 1 ;
V_34 -> V_39 = V_2 -> V_5 . V_459 . V_462 ;
break;
default:
if ( F_226 ( V_2 , V_34 -> V_147 ) )
return F_233 ( V_2 , V_34 -> V_147 , & V_34 -> V_39 ) ;
if ( ! V_463 ) {
F_230 ( V_2 , L_17 ,
V_34 -> V_147 ) ;
return 1 ;
} else {
F_219 ( V_2 , L_18 , V_34 -> V_147 ) ;
V_34 -> V_39 = 0 ;
}
break;
}
return 0 ;
}
static int F_238 ( struct V_1 * V_2 , struct V_484 * V_21 ,
struct V_485 * V_486 ,
int (* F_239)( struct V_1 * V_2 ,
unsigned V_147 , T_2 * V_39 ) )
{
int V_3 , V_487 ;
V_487 = F_240 ( & V_2 -> V_139 -> V_488 ) ;
for ( V_3 = 0 ; V_3 < V_21 -> V_489 ; ++ V_3 )
if ( F_239 ( V_2 , V_486 [ V_3 ] . V_147 , & V_486 [ V_3 ] . V_39 ) )
break;
F_241 ( & V_2 -> V_139 -> V_488 , V_487 ) ;
return V_3 ;
}
static int F_242 ( struct V_1 * V_2 , struct V_484 T_14 * V_490 ,
int (* F_239)( struct V_1 * V_2 ,
unsigned V_147 , T_2 * V_39 ) ,
int V_491 )
{
struct V_484 V_21 ;
struct V_485 * V_486 ;
int V_121 , V_492 ;
unsigned V_493 ;
V_121 = - V_101 ;
if ( F_243 ( & V_21 , V_490 , sizeof V_21 ) )
goto V_113;
V_121 = - V_388 ;
if ( V_21 . V_489 >= V_494 )
goto V_113;
V_493 = sizeof( struct V_485 ) * V_21 . V_489 ;
V_486 = F_208 ( V_490 -> V_486 , V_493 ) ;
if ( F_209 ( V_486 ) ) {
V_121 = F_210 ( V_486 ) ;
goto V_113;
}
V_121 = V_492 = F_238 ( V_2 , & V_21 , V_486 , F_239 ) ;
if ( V_121 < 0 )
goto V_390;
V_121 = - V_101 ;
if ( V_491 && F_244 ( V_490 -> V_486 , V_486 , V_493 ) )
goto V_390;
V_121 = V_492 ;
V_390:
F_212 ( V_486 ) ;
V_113:
return V_121 ;
}
int F_245 ( struct V_139 * V_139 , long V_495 )
{
int V_121 ;
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
#ifdef F_246
case V_537 :
case V_538 :
#endif
V_121 = 1 ;
break;
case V_539 :
V_121 = V_540 ;
break;
case V_541 :
V_121 = V_87 -> V_542 () ;
break;
case V_543 :
V_121 = V_544 ;
break;
case V_545 :
V_121 = ! V_87 -> V_546 () ;
break;
case V_547 :
V_121 = V_548 ;
break;
case V_549 :
V_121 = V_550 ;
break;
case V_551 :
V_121 = V_552 ;
break;
case V_553 :
V_121 = 0 ;
break;
#ifdef F_246
case V_554 :
V_121 = F_247 ( & V_555 ) ;
break;
#endif
case V_556 :
V_121 = V_440 ;
break;
case V_557 :
V_121 = F_248 ( V_558 ) ;
break;
case V_559 :
V_121 = V_273 ;
break;
case V_560 :
V_121 = V_561 ;
break;
default:
V_121 = 0 ;
break;
}
return V_121 ;
}
long F_249 ( struct V_562 * V_563 ,
unsigned int V_564 , unsigned long V_565 )
{
void T_14 * V_566 = ( void T_14 * ) V_565 ;
long V_121 ;
switch ( V_564 ) {
case V_567 : {
struct V_568 T_14 * V_569 = V_566 ;
struct V_568 V_570 ;
unsigned V_492 ;
V_121 = - V_101 ;
if ( F_243 ( & V_570 , V_569 , sizeof V_570 ) )
goto V_113;
V_492 = V_570 . V_489 ;
V_570 . V_489 = V_571 + V_572 ;
if ( F_244 ( V_569 , & V_570 , sizeof V_570 ) )
goto V_113;
V_121 = - V_388 ;
if ( V_492 < V_570 . V_489 )
goto V_113;
V_121 = - V_101 ;
if ( F_244 ( V_569 -> V_573 , & V_574 ,
V_571 * sizeof( T_1 ) ) )
goto V_113;
if ( F_244 ( V_569 -> V_573 + V_571 ,
& V_575 ,
V_572 * sizeof( T_1 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_576 :
case V_577 : {
struct V_578 T_14 * V_579 = V_566 ;
struct V_578 V_580 ;
V_121 = - V_101 ;
if ( F_243 ( & V_580 , V_579 , sizeof V_580 ) )
goto V_113;
V_121 = F_250 ( & V_580 , V_579 -> V_486 ,
V_564 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_244 ( V_579 , & V_580 , sizeof V_580 ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_581 : {
V_121 = - V_101 ;
if ( F_244 ( V_566 , & V_582 ,
sizeof( V_582 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
default:
V_121 = - V_583 ;
}
V_113:
return V_121 ;
}
static void F_251 ( void * V_584 )
{
F_252 () ;
}
static bool F_253 ( struct V_1 * V_2 )
{
return F_68 ( V_2 -> V_139 ) ;
}
static inline void F_254 ( struct V_1 * V_2 )
{
F_223 ( V_585 , & V_2 -> V_341 ) ;
}
void F_255 ( struct V_1 * V_2 , int V_24 )
{
if ( F_253 ( V_2 ) ) {
if ( V_87 -> V_586 () )
F_256 ( V_24 , V_2 -> V_5 . V_587 ) ;
else if ( V_2 -> V_24 != - 1 && V_2 -> V_24 != V_24 )
F_257 ( V_2 -> V_24 ,
F_251 , NULL , 1 ) ;
}
V_87 -> V_588 ( V_2 , V_24 ) ;
if ( F_171 ( V_2 -> V_5 . V_589 ) ) {
F_164 ( V_2 , V_2 -> V_5 . V_589 ) ;
V_2 -> V_5 . V_589 = 0 ;
F_32 ( V_340 , V_2 ) ;
}
if ( F_171 ( V_2 -> V_24 != V_24 ) || F_157 () ) {
T_12 V_590 = ! V_2 -> V_5 . V_591 ? 0 :
F_151 () - V_2 -> V_5 . V_591 ;
if ( V_590 < 0 )
F_258 ( L_19 ) ;
if ( F_157 () ) {
T_2 V_94 = F_150 ( V_2 ,
V_2 -> V_5 . V_325 ) ;
F_153 ( V_2 , V_94 ) ;
V_2 -> V_5 . V_275 = 1 ;
}
if ( F_259 ( V_2 ) &&
V_87 -> V_592 ( V_2 ,
F_260 ( V_2 ) ) )
F_261 ( V_2 ) ;
if ( ! V_2 -> V_139 -> V_5 . V_297 || V_2 -> V_24 == - 1 )
F_32 ( V_433 , V_2 ) ;
if ( V_2 -> V_24 != V_24 )
F_254 ( V_2 ) ;
V_2 -> V_24 = V_24 ;
}
F_32 ( V_438 , V_2 ) ;
}
static void F_262 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_396 . V_392 & V_397 ) )
return;
V_2 -> V_5 . V_396 . V_399 . V_401 = 1 ;
F_263 ( V_2 , & V_2 -> V_5 . V_396 . V_398 ,
& V_2 -> V_5 . V_396 . V_399 . V_401 ,
F_192 ( struct V_400 , V_401 ) ,
sizeof( V_2 -> V_5 . V_396 . V_399 . V_401 ) ) ;
}
void F_264 ( struct V_1 * V_2 )
{
int V_487 ;
F_265 () ;
V_487 = F_240 ( & V_2 -> V_139 -> V_488 ) ;
F_262 ( V_2 ) ;
F_241 ( & V_2 -> V_139 -> V_488 , V_487 ) ;
F_266 () ;
V_87 -> V_593 ( V_2 ) ;
F_267 ( V_2 ) ;
V_2 -> V_5 . V_591 = F_151 () ;
}
static int F_268 ( struct V_1 * V_2 ,
struct V_594 * V_595 )
{
if ( V_87 -> V_596 && V_2 -> V_5 . V_597 )
V_87 -> V_596 ( V_2 ) ;
return F_269 ( V_2 , V_595 ) ;
}
static int F_270 ( struct V_1 * V_2 ,
struct V_594 * V_595 )
{
int V_121 ;
V_121 = F_271 ( V_2 , V_595 ) ;
if ( V_121 )
return V_121 ;
F_272 ( V_2 ) ;
return 0 ;
}
static int F_273 ( struct V_1 * V_2 )
{
return ( ! F_91 ( V_2 ) ||
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
struct V_598 * V_599 )
{
if ( V_599 -> V_599 >= V_600 )
return - V_583 ;
if ( ! F_280 ( V_2 -> V_139 ) ) {
F_281 ( V_2 , V_599 -> V_599 , false ) ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
if ( F_282 ( V_2 -> V_139 ) )
return - V_601 ;
if ( V_2 -> V_5 . V_602 != - 1 )
return - V_603 ;
V_2 -> V_5 . V_602 = V_599 -> V_599 ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
static int F_283 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
return 0 ;
}
static int F_284 ( struct V_1 * V_2 )
{
F_32 ( V_604 , V_2 ) ;
return 0 ;
}
static int F_285 ( struct V_1 * V_2 ,
struct V_605 * V_606 )
{
if ( V_606 -> V_15 )
return - V_583 ;
V_2 -> V_5 . V_607 = ! ! V_606 -> V_608 ;
return 0 ;
}
static int F_286 ( struct V_1 * V_2 ,
T_2 V_368 )
{
int V_121 ;
unsigned V_369 = V_368 & 0xff , V_609 ;
V_121 = - V_583 ;
if ( ! V_369 || V_369 >= V_440 )
goto V_113;
if ( V_368 & ~ ( V_582 | 0xff | 0xff0000 ) )
goto V_113;
V_121 = 0 ;
V_2 -> V_5 . V_368 = V_368 ;
if ( V_368 & V_373 )
V_2 -> V_5 . V_374 = ~ ( T_2 ) 0 ;
for ( V_609 = 0 ; V_609 < V_369 ; V_609 ++ )
V_2 -> V_5 . V_376 [ V_609 * 4 ] = ~ ( T_2 ) 0 ;
if ( V_87 -> V_610 )
V_87 -> V_610 ( V_2 ) ;
V_113:
return V_121 ;
}
static int F_287 ( struct V_1 * V_2 ,
struct V_611 * V_612 )
{
T_2 V_368 = V_2 -> V_5 . V_368 ;
unsigned V_369 = V_368 & 0xff ;
T_2 * V_613 = V_2 -> V_5 . V_376 ;
if ( V_612 -> V_609 >= V_369 || ! ( V_612 -> V_462 & V_614 ) )
return - V_583 ;
if ( ( V_612 -> V_462 & V_615 ) && ( V_368 & V_373 ) &&
V_2 -> V_5 . V_374 != ~ ( T_2 ) 0 )
return 0 ;
V_613 += 4 * V_612 -> V_609 ;
if ( ( V_612 -> V_462 & V_615 ) && V_613 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_612 -> V_462 & V_615 ) {
if ( ( V_2 -> V_5 . V_371 & V_616 ) ||
! F_48 ( V_2 , V_617 ) ) {
F_32 ( V_73 , V_2 ) ;
return 0 ;
}
if ( V_613 [ 1 ] & V_614 )
V_612 -> V_462 |= V_618 ;
V_613 [ 2 ] = V_612 -> V_619 ;
V_613 [ 3 ] = V_612 -> V_620 ;
V_2 -> V_5 . V_371 = V_612 -> V_371 ;
V_613 [ 1 ] = V_612 -> V_462 ;
F_34 ( V_2 , V_59 ) ;
} else if ( ! ( V_613 [ 1 ] & V_614 )
|| ! ( V_613 [ 1 ] & V_615 ) ) {
if ( V_613 [ 1 ] & V_614 )
V_612 -> V_462 |= V_618 ;
V_613 [ 2 ] = V_612 -> V_619 ;
V_613 [ 3 ] = V_612 -> V_620 ;
V_613 [ 1 ] = V_612 -> V_462 ;
} else
V_613 [ 1 ] |= V_618 ;
return 0 ;
}
static void F_288 ( struct V_1 * V_2 ,
struct V_621 * V_622 )
{
F_289 ( V_2 ) ;
V_622 -> V_69 . V_623 =
V_2 -> V_5 . V_69 . V_70 &&
! F_290 ( V_2 -> V_5 . V_69 . V_18 ) ;
V_622 -> V_69 . V_18 = V_2 -> V_5 . V_69 . V_18 ;
V_622 -> V_69 . V_72 = V_2 -> V_5 . V_69 . V_72 ;
V_622 -> V_69 . V_624 = 0 ;
V_622 -> V_69 . V_63 = V_2 -> V_5 . V_69 . V_63 ;
V_622 -> V_625 . V_623 =
V_2 -> V_5 . V_625 . V_70 && ! V_2 -> V_5 . V_625 . V_626 ;
V_622 -> V_625 . V_18 = V_2 -> V_5 . V_625 . V_18 ;
V_622 -> V_625 . V_626 = 0 ;
V_622 -> V_625 . V_627 = V_87 -> V_628 ( V_2 ) ;
V_622 -> V_629 . V_623 = V_2 -> V_5 . V_630 ;
V_622 -> V_629 . V_70 = V_2 -> V_5 . V_631 != 0 ;
V_622 -> V_629 . V_632 = V_87 -> V_633 ( V_2 ) ;
V_622 -> V_629 . V_624 = 0 ;
V_622 -> V_634 = 0 ;
V_622 -> V_635 . V_636 = F_291 ( V_2 ) ;
V_622 -> V_635 . V_70 = V_2 -> V_5 . V_637 ;
V_622 -> V_635 . V_638 =
! ! ( V_2 -> V_5 . V_639 & V_640 ) ;
V_622 -> V_635 . V_641 = F_292 ( V_2 ) ;
V_622 -> V_15 = ( V_642
| V_643
| V_644 ) ;
memset ( & V_622 -> V_645 , 0 , sizeof( V_622 -> V_645 ) ) ;
}
static int F_293 ( struct V_1 * V_2 ,
struct V_621 * V_622 )
{
if ( V_622 -> V_15 & ~ ( V_642
| V_646
| V_643
| V_644 ) )
return - V_583 ;
if ( V_622 -> V_69 . V_623 &&
( V_622 -> V_69 . V_18 > 31 || V_622 -> V_69 . V_18 == V_52 ) )
return - V_583 ;
F_289 ( V_2 ) ;
V_2 -> V_5 . V_69 . V_70 = V_622 -> V_69 . V_623 ;
V_2 -> V_5 . V_69 . V_18 = V_622 -> V_69 . V_18 ;
V_2 -> V_5 . V_69 . V_72 = V_622 -> V_69 . V_72 ;
V_2 -> V_5 . V_69 . V_63 = V_622 -> V_69 . V_63 ;
V_2 -> V_5 . V_625 . V_70 = V_622 -> V_625 . V_623 ;
V_2 -> V_5 . V_625 . V_18 = V_622 -> V_625 . V_18 ;
V_2 -> V_5 . V_625 . V_626 = V_622 -> V_625 . V_626 ;
if ( V_622 -> V_15 & V_643 )
V_87 -> V_647 ( V_2 ,
V_622 -> V_625 . V_627 ) ;
V_2 -> V_5 . V_630 = V_622 -> V_629 . V_623 ;
if ( V_622 -> V_15 & V_642 )
V_2 -> V_5 . V_631 = V_622 -> V_629 . V_70 ;
V_87 -> V_648 ( V_2 , V_622 -> V_629 . V_632 ) ;
if ( V_622 -> V_15 & V_646 &&
F_91 ( V_2 ) )
V_2 -> V_5 . V_649 -> V_634 = V_622 -> V_634 ;
if ( V_622 -> V_15 & V_644 ) {
T_1 V_639 = V_2 -> V_5 . V_639 ;
if ( V_622 -> V_635 . V_636 )
V_639 |= V_650 ;
else
V_639 &= ~ V_650 ;
F_294 ( V_2 , V_639 ) ;
V_2 -> V_5 . V_637 = V_622 -> V_635 . V_70 ;
if ( V_622 -> V_635 . V_638 )
V_2 -> V_5 . V_639 |= V_640 ;
else
V_2 -> V_5 . V_639 &= ~ V_640 ;
if ( F_91 ( V_2 ) ) {
if ( V_622 -> V_635 . V_641 )
F_223 ( V_651 , & V_2 -> V_5 . V_649 -> V_652 ) ;
else
F_184 ( V_651 , & V_2 -> V_5 . V_649 -> V_652 ) ;
}
}
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
static void F_295 ( struct V_1 * V_2 ,
struct V_653 * V_654 )
{
unsigned long V_196 ;
memcpy ( V_654 -> V_183 , V_2 -> V_5 . V_183 , sizeof( V_2 -> V_5 . V_183 ) ) ;
F_102 ( V_2 , 6 , & V_196 ) ;
V_654 -> V_187 = V_196 ;
V_654 -> V_188 = V_2 -> V_5 . V_188 ;
V_654 -> V_15 = 0 ;
memset ( & V_654 -> V_645 , 0 , sizeof( V_654 -> V_645 ) ) ;
}
static int F_296 ( struct V_1 * V_2 ,
struct V_653 * V_654 )
{
if ( V_654 -> V_15 )
return - V_583 ;
if ( V_654 -> V_187 & ~ 0xffffffffull )
return - V_583 ;
if ( V_654 -> V_188 & ~ 0xffffffffull )
return - V_583 ;
memcpy ( V_2 -> V_5 . V_183 , V_654 -> V_183 , sizeof( V_2 -> V_5 . V_183 ) ) ;
F_95 ( V_2 ) ;
V_2 -> V_5 . V_187 = V_654 -> V_187 ;
F_96 ( V_2 ) ;
V_2 -> V_5 . V_188 = V_654 -> V_188 ;
F_97 ( V_2 ) ;
return 0 ;
}
static void F_297 ( T_13 * V_655 , struct V_1 * V_2 )
{
struct V_656 * V_657 = & V_2 -> V_5 . V_658 . V_659 . V_657 ;
T_2 V_660 = V_657 -> V_661 . V_662 ;
T_2 V_663 ;
memcpy ( V_655 , V_657 , V_664 ) ;
V_660 &= V_2 -> V_5 . V_154 | V_665 ;
* ( T_2 * ) ( V_655 + V_664 ) = V_660 ;
V_663 = V_660 & ~ V_665 ;
while ( V_663 ) {
T_2 V_666 = V_663 & - V_663 ;
int V_147 = F_298 ( V_666 ) - 1 ;
void * V_667 = F_299 ( V_657 , V_666 ) ;
if ( V_667 ) {
T_1 V_493 , V_94 , V_201 , V_209 ;
F_300 ( V_668 , V_147 ,
& V_493 , & V_94 , & V_201 , & V_209 ) ;
memcpy ( V_655 + V_94 , V_667 , V_493 ) ;
}
V_663 -= V_666 ;
}
}
static void F_301 ( struct V_1 * V_2 , T_13 * V_667 )
{
struct V_656 * V_657 = & V_2 -> V_5 . V_658 . V_659 . V_657 ;
T_2 V_660 = * ( T_2 * ) ( V_667 + V_664 ) ;
T_2 V_663 ;
memcpy ( V_657 , V_667 , V_664 ) ;
V_657 -> V_661 . V_662 = V_660 ;
if ( F_248 ( V_669 ) )
V_657 -> V_661 . V_670 = V_146 | V_671 ;
V_663 = V_660 & ~ V_665 ;
while ( V_663 ) {
T_2 V_666 = V_663 & - V_663 ;
int V_147 = F_298 ( V_666 ) - 1 ;
void * V_655 = F_299 ( V_657 , V_666 ) ;
if ( V_655 ) {
T_1 V_493 , V_94 , V_201 , V_209 ;
F_300 ( V_668 , V_147 ,
& V_493 , & V_94 , & V_201 , & V_209 ) ;
memcpy ( V_655 , V_667 + V_94 , V_493 ) ;
}
V_663 -= V_666 ;
}
}
static void F_302 ( struct V_1 * V_2 ,
struct V_672 * V_673 )
{
if ( F_248 ( V_558 ) ) {
memset ( V_673 , 0 , sizeof( struct V_672 ) ) ;
F_297 ( ( T_13 * ) V_673 -> V_674 , V_2 ) ;
} else {
memcpy ( V_673 -> V_674 ,
& V_2 -> V_5 . V_658 . V_659 . V_675 ,
sizeof( struct V_676 ) ) ;
* ( T_2 * ) & V_673 -> V_674 [ V_664 / sizeof( T_1 ) ] =
V_665 ;
}
}
static int F_303 ( struct V_1 * V_2 ,
struct V_672 * V_673 )
{
T_2 V_660 =
* ( T_2 * ) & V_673 -> V_674 [ V_664 / sizeof( T_1 ) ] ;
if ( F_248 ( V_558 ) ) {
if ( V_660 & ~ F_304 () )
return - V_583 ;
F_301 ( V_2 , ( T_13 * ) V_673 -> V_674 ) ;
} else {
if ( V_660 & ~ V_665 )
return - V_583 ;
memcpy ( & V_2 -> V_5 . V_658 . V_659 . V_675 ,
V_673 -> V_674 , sizeof( struct V_676 ) ) ;
}
return 0 ;
}
static void F_305 ( struct V_1 * V_2 ,
struct V_677 * V_678 )
{
if ( ! F_248 ( V_558 ) ) {
V_678 -> V_679 = 0 ;
return;
}
V_678 -> V_679 = 1 ;
V_678 -> V_15 = 0 ;
V_678 -> V_680 [ 0 ] . V_148 = V_144 ;
V_678 -> V_680 [ 0 ] . V_23 = V_2 -> V_5 . V_145 ;
}
static int F_306 ( struct V_1 * V_2 ,
struct V_677 * V_678 )
{
int V_3 , V_121 = 0 ;
if ( ! F_248 ( V_558 ) )
return - V_583 ;
if ( V_678 -> V_679 > V_681 || V_678 -> V_15 )
return - V_583 ;
for ( V_3 = 0 ; V_3 < V_678 -> V_679 ; V_3 ++ )
if ( V_678 -> V_680 [ V_3 ] . V_148 == V_144 ) {
V_121 = F_76 ( V_2 , V_144 ,
V_678 -> V_680 [ V_3 ] . V_23 ) ;
break;
}
if ( V_121 )
V_121 = - V_583 ;
return V_121 ;
}
static int F_307 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_358 )
return - V_583 ;
V_2 -> V_5 . V_353 = true ;
F_32 ( V_340 , V_2 ) ;
return 0 ;
}
static int F_308 ( struct V_1 * V_2 ,
struct V_682 * V_683 )
{
if ( V_683 -> V_15 )
return - V_583 ;
switch ( V_683 -> V_683 ) {
case V_520 :
if ( ! F_280 ( V_2 -> V_139 ) )
return - V_583 ;
return F_309 ( V_2 ) ;
default:
return - V_583 ;
}
}
long F_310 ( struct V_562 * V_563 ,
unsigned int V_564 , unsigned long V_565 )
{
struct V_1 * V_2 = V_563 -> V_684 ;
void T_14 * V_566 = ( void T_14 * ) V_565 ;
int V_121 ;
union {
struct V_594 * V_685 ;
struct V_672 * V_657 ;
struct V_677 * V_680 ;
void * V_686 ;
} V_687 ;
V_687 . V_686 = NULL ;
switch ( V_564 ) {
case V_688 : {
V_121 = - V_583 ;
if ( ! F_91 ( V_2 ) )
goto V_113;
V_687 . V_685 = F_311 ( sizeof( struct V_594 ) , V_689 ) ;
V_121 = - V_389 ;
if ( ! V_687 . V_685 )
goto V_113;
V_121 = F_268 ( V_2 , V_687 . V_685 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_244 ( V_566 , V_687 . V_685 , sizeof( struct V_594 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_690 : {
V_121 = - V_583 ;
if ( ! F_91 ( V_2 ) )
goto V_113;
V_687 . V_685 = F_208 ( V_566 , sizeof( * V_687 . V_685 ) ) ;
if ( F_209 ( V_687 . V_685 ) )
return F_210 ( V_687 . V_685 ) ;
V_121 = F_270 ( V_2 , V_687 . V_685 ) ;
break;
}
case V_691 : {
struct V_598 V_599 ;
V_121 = - V_101 ;
if ( F_243 ( & V_599 , V_566 , sizeof V_599 ) )
goto V_113;
V_121 = F_279 ( V_2 , & V_599 ) ;
break;
}
case V_692 : {
V_121 = F_283 ( V_2 ) ;
break;
}
case V_693 : {
V_121 = F_284 ( V_2 ) ;
break;
}
case V_694 : {
struct V_695 T_14 * V_579 = V_566 ;
struct V_695 V_580 ;
V_121 = - V_101 ;
if ( F_243 ( & V_580 , V_579 , sizeof V_580 ) )
goto V_113;
V_121 = F_312 ( V_2 , & V_580 , V_579 -> V_486 ) ;
break;
}
case V_696 : {
struct V_578 T_14 * V_579 = V_566 ;
struct V_578 V_580 ;
V_121 = - V_101 ;
if ( F_243 ( & V_580 , V_579 , sizeof V_580 ) )
goto V_113;
V_121 = F_313 ( V_2 , & V_580 ,
V_579 -> V_486 ) ;
break;
}
case V_697 : {
struct V_578 T_14 * V_579 = V_566 ;
struct V_578 V_580 ;
V_121 = - V_101 ;
if ( F_243 ( & V_580 , V_579 , sizeof V_580 ) )
goto V_113;
V_121 = F_314 ( V_2 , & V_580 ,
V_579 -> V_486 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_244 ( V_579 , & V_580 , sizeof V_580 ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_698 :
V_121 = F_242 ( V_2 , V_566 , F_115 , 1 ) ;
break;
case V_699 :
V_121 = F_242 ( V_2 , V_566 , F_117 , 0 ) ;
break;
case V_700 : {
struct V_605 V_606 ;
V_121 = - V_101 ;
if ( F_243 ( & V_606 , V_566 , sizeof V_606 ) )
goto V_113;
V_121 = F_285 ( V_2 , & V_606 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_244 ( V_566 , & V_606 , sizeof V_606 ) )
goto V_113;
V_121 = 0 ;
break;
} ;
case V_701 : {
struct V_702 V_703 ;
int V_487 ;
V_121 = - V_583 ;
if ( ! F_91 ( V_2 ) )
goto V_113;
V_121 = - V_101 ;
if ( F_243 ( & V_703 , V_566 , sizeof V_703 ) )
goto V_113;
V_487 = F_240 ( & V_2 -> V_139 -> V_488 ) ;
V_121 = F_315 ( V_2 , V_703 . V_704 ) ;
F_241 ( & V_2 -> V_139 -> V_488 , V_487 ) ;
break;
}
case V_705 : {
T_2 V_368 ;
V_121 = - V_101 ;
if ( F_243 ( & V_368 , V_566 , sizeof V_368 ) )
goto V_113;
V_121 = F_286 ( V_2 , V_368 ) ;
break;
}
case V_706 : {
struct V_611 V_612 ;
V_121 = - V_101 ;
if ( F_243 ( & V_612 , V_566 , sizeof V_612 ) )
goto V_113;
V_121 = F_287 ( V_2 , & V_612 ) ;
break;
}
case V_707 : {
struct V_621 V_622 ;
F_288 ( V_2 , & V_622 ) ;
V_121 = - V_101 ;
if ( F_244 ( V_566 , & V_622 , sizeof( struct V_621 ) ) )
break;
V_121 = 0 ;
break;
}
case V_708 : {
struct V_621 V_622 ;
V_121 = - V_101 ;
if ( F_243 ( & V_622 , V_566 , sizeof( struct V_621 ) ) )
break;
V_121 = F_293 ( V_2 , & V_622 ) ;
break;
}
case V_709 : {
struct V_653 V_654 ;
F_295 ( V_2 , & V_654 ) ;
V_121 = - V_101 ;
if ( F_244 ( V_566 , & V_654 ,
sizeof( struct V_653 ) ) )
break;
V_121 = 0 ;
break;
}
case V_710 : {
struct V_653 V_654 ;
V_121 = - V_101 ;
if ( F_243 ( & V_654 , V_566 ,
sizeof( struct V_653 ) ) )
break;
V_121 = F_296 ( V_2 , & V_654 ) ;
break;
}
case V_711 : {
V_687 . V_657 = F_311 ( sizeof( struct V_672 ) , V_689 ) ;
V_121 = - V_389 ;
if ( ! V_687 . V_657 )
break;
F_302 ( V_2 , V_687 . V_657 ) ;
V_121 = - V_101 ;
if ( F_244 ( V_566 , V_687 . V_657 , sizeof( struct V_672 ) ) )
break;
V_121 = 0 ;
break;
}
case V_712 : {
V_687 . V_657 = F_208 ( V_566 , sizeof( * V_687 . V_657 ) ) ;
if ( F_209 ( V_687 . V_657 ) )
return F_210 ( V_687 . V_657 ) ;
V_121 = F_303 ( V_2 , V_687 . V_657 ) ;
break;
}
case V_713 : {
V_687 . V_680 = F_311 ( sizeof( struct V_677 ) , V_689 ) ;
V_121 = - V_389 ;
if ( ! V_687 . V_680 )
break;
F_305 ( V_2 , V_687 . V_680 ) ;
V_121 = - V_101 ;
if ( F_244 ( V_566 , V_687 . V_680 ,
sizeof( struct V_677 ) ) )
break;
V_121 = 0 ;
break;
}
case V_714 : {
V_687 . V_680 = F_208 ( V_566 , sizeof( * V_687 . V_680 ) ) ;
if ( F_209 ( V_687 . V_680 ) )
return F_210 ( V_687 . V_680 ) ;
V_121 = F_306 ( V_2 , V_687 . V_680 ) ;
break;
}
case V_715 : {
T_1 V_268 ;
V_121 = - V_583 ;
V_268 = ( T_1 ) V_565 ;
if ( V_268 >= V_716 )
goto V_113;
if ( V_268 == 0 )
V_268 = V_274 ;
if ( ! F_140 ( V_2 , V_268 ) )
V_121 = 0 ;
goto V_113;
}
case V_717 : {
V_121 = V_2 -> V_5 . V_285 ;
goto V_113;
}
case V_718 : {
V_121 = F_307 ( V_2 ) ;
goto V_113;
}
case V_719 : {
struct V_682 V_683 ;
V_121 = - V_101 ;
if ( F_243 ( & V_683 , V_566 , sizeof( V_683 ) ) )
goto V_113;
V_121 = F_308 ( V_2 , & V_683 ) ;
break;
}
default:
V_121 = - V_583 ;
}
V_113:
F_212 ( V_687 . V_686 ) ;
return V_121 ;
}
int F_316 ( struct V_1 * V_2 , struct V_720 * V_721 )
{
return V_722 ;
}
static int F_317 ( struct V_139 * V_139 , unsigned long V_619 )
{
int V_108 ;
if ( V_619 > ( unsigned int ) ( - 3 * V_107 ) )
return - V_583 ;
V_108 = V_87 -> V_723 ( V_139 , V_619 ) ;
return V_108 ;
}
static int F_318 ( struct V_139 * V_139 ,
T_2 V_724 )
{
V_139 -> V_5 . V_725 = V_724 ;
return 0 ;
}
static int F_319 ( struct V_139 * V_139 ,
T_1 V_726 )
{
if ( V_726 < V_727 )
return - V_583 ;
F_320 ( & V_139 -> V_728 ) ;
F_321 ( V_139 , V_726 ) ;
V_139 -> V_5 . V_729 = V_726 ;
F_322 ( & V_139 -> V_728 ) ;
return 0 ;
}
static int F_323 ( struct V_139 * V_139 )
{
return V_139 -> V_5 . V_730 ;
}
static int F_324 ( struct V_139 * V_139 , struct V_731 * V_732 )
{
int V_121 ;
V_121 = 0 ;
switch ( V_732 -> V_733 ) {
case V_734 :
memcpy ( & V_732 -> V_732 . V_735 ,
& F_325 ( V_139 ) -> V_736 [ 0 ] ,
sizeof( struct V_737 ) ) ;
break;
case V_738 :
memcpy ( & V_732 -> V_732 . V_735 ,
& F_325 ( V_139 ) -> V_736 [ 1 ] ,
sizeof( struct V_737 ) ) ;
break;
case V_739 :
V_121 = F_326 ( V_139 , & V_732 -> V_732 . V_740 ) ;
break;
default:
V_121 = - V_583 ;
break;
}
return V_121 ;
}
static int F_327 ( struct V_139 * V_139 , struct V_731 * V_732 )
{
int V_121 ;
V_121 = 0 ;
switch ( V_732 -> V_733 ) {
case V_734 :
F_161 ( & F_325 ( V_139 ) -> V_741 ) ;
memcpy ( & F_325 ( V_139 ) -> V_736 [ 0 ] ,
& V_732 -> V_732 . V_735 ,
sizeof( struct V_737 ) ) ;
F_162 ( & F_325 ( V_139 ) -> V_741 ) ;
break;
case V_738 :
F_161 ( & F_325 ( V_139 ) -> V_741 ) ;
memcpy ( & F_325 ( V_139 ) -> V_736 [ 1 ] ,
& V_732 -> V_732 . V_735 ,
sizeof( struct V_737 ) ) ;
F_162 ( & F_325 ( V_139 ) -> V_741 ) ;
break;
case V_739 :
V_121 = F_328 ( V_139 , & V_732 -> V_732 . V_740 ) ;
break;
default:
V_121 = - V_583 ;
break;
}
F_329 ( F_325 ( V_139 ) ) ;
return V_121 ;
}
static int F_330 ( struct V_139 * V_139 , struct V_742 * V_743 )
{
struct V_744 * V_745 = & V_139 -> V_5 . V_746 -> V_747 ;
F_191 ( sizeof( * V_743 ) != sizeof( V_745 -> V_748 ) ) ;
F_320 ( & V_745 -> V_741 ) ;
memcpy ( V_743 , & V_745 -> V_748 , sizeof( * V_743 ) ) ;
F_322 ( & V_745 -> V_741 ) ;
return 0 ;
}
static int F_331 ( struct V_139 * V_139 , struct V_742 * V_743 )
{
int V_3 ;
struct V_749 * V_750 = V_139 -> V_5 . V_746 ;
F_320 ( & V_750 -> V_747 . V_741 ) ;
memcpy ( & V_750 -> V_747 . V_748 , V_743 , sizeof( * V_743 ) ) ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
F_332 ( V_750 , V_3 , V_743 -> V_748 [ V_3 ] . V_751 , 0 ) ;
F_322 ( & V_750 -> V_747 . V_741 ) ;
return 0 ;
}
static int F_333 ( struct V_139 * V_139 , struct V_752 * V_743 )
{
F_320 ( & V_139 -> V_5 . V_746 -> V_747 . V_741 ) ;
memcpy ( V_743 -> V_748 , & V_139 -> V_5 . V_746 -> V_747 . V_748 ,
sizeof( V_743 -> V_748 ) ) ;
V_743 -> V_15 = V_139 -> V_5 . V_746 -> V_747 . V_15 ;
F_322 ( & V_139 -> V_5 . V_746 -> V_747 . V_741 ) ;
memset ( & V_743 -> V_645 , 0 , sizeof( V_743 -> V_645 ) ) ;
return 0 ;
}
static int F_334 ( struct V_139 * V_139 , struct V_752 * V_743 )
{
int V_753 = 0 ;
int V_3 ;
T_1 V_754 , V_755 ;
struct V_749 * V_750 = V_139 -> V_5 . V_746 ;
F_320 ( & V_750 -> V_747 . V_741 ) ;
V_754 = V_750 -> V_747 . V_15 & V_756 ;
V_755 = V_743 -> V_15 & V_756 ;
if ( ! V_754 && V_755 )
V_753 = 1 ;
memcpy ( & V_750 -> V_747 . V_748 , & V_743 -> V_748 ,
sizeof( V_750 -> V_747 . V_748 ) ) ;
V_750 -> V_747 . V_15 = V_743 -> V_15 ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
F_332 ( V_750 , V_3 , V_750 -> V_747 . V_748 [ V_3 ] . V_751 ,
V_753 && V_3 == 0 ) ;
F_322 ( & V_750 -> V_747 . V_741 ) ;
return 0 ;
}
static int F_335 ( struct V_139 * V_139 ,
struct V_757 * V_758 )
{
struct V_749 * V_750 = V_139 -> V_5 . V_746 ;
if ( ! V_750 )
return - V_601 ;
F_320 ( & V_750 -> V_747 . V_741 ) ;
F_336 ( V_750 , V_758 -> V_759 ) ;
F_322 ( & V_750 -> V_747 . V_741 ) ;
return 0 ;
}
int F_337 ( struct V_139 * V_139 , struct V_760 * log )
{
bool V_761 = false ;
int V_121 ;
F_320 ( & V_139 -> V_728 ) ;
if ( V_87 -> V_762 )
V_87 -> V_762 ( V_139 ) ;
V_121 = F_338 ( V_139 , log , & V_761 ) ;
F_339 ( & V_139 -> V_728 ) ;
if ( V_761 )
F_340 ( V_139 ) ;
F_322 ( & V_139 -> V_728 ) ;
return V_121 ;
}
int F_341 ( struct V_139 * V_139 , struct V_763 * V_764 ,
bool V_765 )
{
if ( ! F_280 ( V_139 ) )
return - V_601 ;
V_764 -> V_462 = F_342 ( V_139 , V_766 ,
V_764 -> V_599 , V_764 -> V_767 ,
V_765 ) ;
return 0 ;
}
static int F_343 ( struct V_139 * V_139 ,
struct V_682 * V_683 )
{
int V_121 ;
if ( V_683 -> V_15 )
return - V_583 ;
switch ( V_683 -> V_683 ) {
case V_533 :
V_139 -> V_5 . V_768 = V_683 -> args [ 0 ] ;
V_121 = 0 ;
break;
case V_535 : {
F_320 ( & V_139 -> V_741 ) ;
V_121 = - V_583 ;
if ( V_683 -> args [ 0 ] > V_769 )
goto V_770;
V_121 = - V_603 ;
if ( F_280 ( V_139 ) )
goto V_770;
if ( V_139 -> V_771 )
goto V_770;
V_121 = F_344 ( V_139 ) ;
if ( V_121 )
goto V_770;
F_194 () ;
V_139 -> V_5 . V_772 = V_773 ;
V_139 -> V_5 . V_774 = V_683 -> args [ 0 ] ;
V_121 = 0 ;
V_770:
F_322 ( & V_139 -> V_741 ) ;
break;
}
case V_560 :
V_121 = - V_583 ;
if ( V_683 -> args [ 0 ] & ~ V_561 )
break;
if ( V_683 -> args [ 0 ] & V_775 )
V_139 -> V_5 . V_776 = true ;
if ( V_683 -> args [ 0 ] & V_777 )
V_139 -> V_5 . V_778 = true ;
V_121 = 0 ;
break;
default:
V_121 = - V_583 ;
break;
}
return V_121 ;
}
long F_345 ( struct V_562 * V_563 ,
unsigned int V_564 , unsigned long V_565 )
{
struct V_139 * V_139 = V_563 -> V_684 ;
void T_14 * V_566 = ( void T_14 * ) V_565 ;
int V_121 = - V_779 ;
union {
struct V_742 V_743 ;
struct V_752 V_780 ;
struct V_781 V_782 ;
} V_687 ;
switch ( V_564 ) {
case V_783 :
V_121 = F_317 ( V_139 , V_565 ) ;
break;
case V_784 : {
T_2 V_724 ;
V_121 = - V_101 ;
if ( F_243 ( & V_724 , V_566 , sizeof V_724 ) )
goto V_113;
V_121 = F_318 ( V_139 , V_724 ) ;
break;
}
case V_785 :
V_121 = F_319 ( V_139 , V_565 ) ;
break;
case V_786 :
V_121 = F_323 ( V_139 ) ;
break;
case V_787 : {
F_320 ( & V_139 -> V_741 ) ;
V_121 = - V_603 ;
if ( F_280 ( V_139 ) )
goto V_788;
V_121 = - V_583 ;
if ( V_139 -> V_771 )
goto V_788;
V_121 = F_346 ( V_139 ) ;
if ( V_121 )
goto V_788;
V_121 = F_347 ( V_139 ) ;
if ( V_121 ) {
F_320 ( & V_139 -> V_728 ) ;
F_348 ( V_139 ) ;
F_322 ( & V_139 -> V_728 ) ;
goto V_788;
}
V_121 = F_349 ( V_139 ) ;
if ( V_121 ) {
F_320 ( & V_139 -> V_728 ) ;
F_320 ( & V_139 -> V_789 ) ;
F_350 ( V_139 ) ;
F_348 ( V_139 ) ;
F_322 ( & V_139 -> V_789 ) ;
F_322 ( & V_139 -> V_728 ) ;
goto V_788;
}
F_194 () ;
V_139 -> V_5 . V_772 = V_790 ;
V_788:
F_322 ( & V_139 -> V_741 ) ;
break;
}
case V_791 :
V_687 . V_782 . V_15 = V_792 ;
goto V_793;
case V_794 :
V_121 = - V_101 ;
if ( F_243 ( & V_687 . V_782 , V_566 ,
sizeof( struct V_781 ) ) )
goto V_113;
V_793:
F_320 ( & V_139 -> V_741 ) ;
V_121 = - V_603 ;
if ( V_139 -> V_5 . V_746 )
goto V_795;
V_121 = - V_389 ;
V_139 -> V_5 . V_746 = F_351 ( V_139 , V_687 . V_782 . V_15 ) ;
if ( V_139 -> V_5 . V_746 )
V_121 = 0 ;
V_795:
F_322 ( & V_139 -> V_741 ) ;
break;
case V_796 : {
struct V_731 * V_732 ;
V_732 = F_208 ( V_566 , sizeof( * V_732 ) ) ;
if ( F_209 ( V_732 ) ) {
V_121 = F_210 ( V_732 ) ;
goto V_113;
}
V_121 = - V_601 ;
if ( ! F_352 ( V_139 ) )
goto V_797;
V_121 = F_324 ( V_139 , V_732 ) ;
if ( V_121 )
goto V_797;
V_121 = - V_101 ;
if ( F_244 ( V_566 , V_732 , sizeof *V_732 ) )
goto V_797;
V_121 = 0 ;
V_797:
F_212 ( V_732 ) ;
break;
}
case V_798 : {
struct V_731 * V_732 ;
V_732 = F_208 ( V_566 , sizeof( * V_732 ) ) ;
if ( F_209 ( V_732 ) ) {
V_121 = F_210 ( V_732 ) ;
goto V_113;
}
V_121 = - V_601 ;
if ( ! F_352 ( V_139 ) )
goto V_799;
V_121 = F_327 ( V_139 , V_732 ) ;
if ( V_121 )
goto V_799;
V_121 = 0 ;
V_799:
F_212 ( V_732 ) ;
break;
}
case V_800 : {
V_121 = - V_101 ;
if ( F_243 ( & V_687 . V_743 , V_566 , sizeof( struct V_742 ) ) )
goto V_113;
V_121 = - V_601 ;
if ( ! V_139 -> V_5 . V_746 )
goto V_113;
V_121 = F_330 ( V_139 , & V_687 . V_743 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_244 ( V_566 , & V_687 . V_743 , sizeof( struct V_742 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_801 : {
V_121 = - V_101 ;
if ( F_243 ( & V_687 . V_743 , V_566 , sizeof V_687 . V_743 ) )
goto V_113;
V_121 = - V_601 ;
if ( ! V_139 -> V_5 . V_746 )
goto V_113;
V_121 = F_331 ( V_139 , & V_687 . V_743 ) ;
break;
}
case V_802 : {
V_121 = - V_601 ;
if ( ! V_139 -> V_5 . V_746 )
goto V_113;
V_121 = F_333 ( V_139 , & V_687 . V_780 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_244 ( V_566 , & V_687 . V_780 , sizeof( V_687 . V_780 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_803 : {
V_121 = - V_101 ;
if ( F_243 ( & V_687 . V_780 , V_566 , sizeof( V_687 . V_780 ) ) )
goto V_113;
V_121 = - V_601 ;
if ( ! V_139 -> V_5 . V_746 )
goto V_113;
V_121 = F_334 ( V_139 , & V_687 . V_780 ) ;
break;
}
case V_804 : {
struct V_757 V_758 ;
V_121 = - V_101 ;
if ( F_243 ( & V_758 , V_566 , sizeof( V_758 ) ) )
goto V_113;
V_121 = F_335 ( V_139 , & V_758 ) ;
break;
}
case V_805 :
V_121 = 0 ;
F_320 ( & V_139 -> V_741 ) ;
if ( V_139 -> V_771 )
V_121 = - V_806 ;
else
V_139 -> V_5 . V_807 = V_565 ;
F_322 ( & V_139 -> V_741 ) ;
break;
case V_808 : {
V_121 = - V_101 ;
if ( F_243 ( & V_139 -> V_5 . F_207 , V_566 ,
sizeof( struct V_809 ) ) )
goto V_113;
V_121 = - V_583 ;
if ( V_139 -> V_5 . F_207 . V_15 )
goto V_113;
V_121 = 0 ;
break;
}
case V_810 : {
struct V_811 V_812 ;
T_2 V_813 ;
V_121 = - V_101 ;
if ( F_243 ( & V_812 , V_566 , sizeof( V_812 ) ) )
goto V_113;
V_121 = - V_583 ;
if ( V_812 . V_15 )
goto V_113;
V_121 = 0 ;
F_353 () ;
V_813 = F_185 ( V_139 ) ;
V_139 -> V_5 . V_249 += V_812 . clock - V_813 ;
F_354 () ;
F_182 ( V_139 ) ;
break;
}
case V_814 : {
struct V_811 V_812 ;
T_2 V_813 ;
F_353 () ;
V_813 = F_185 ( V_139 ) ;
V_812 . clock = V_813 ;
V_812 . V_15 = V_139 -> V_5 . V_297 ? V_540 : 0 ;
F_354 () ;
memset ( & V_812 . V_624 , 0 , sizeof( V_812 . V_624 ) ) ;
V_121 = - V_101 ;
if ( F_244 ( V_566 , & V_812 , sizeof( V_812 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_719 : {
struct V_682 V_683 ;
V_121 = - V_101 ;
if ( F_243 ( & V_683 , V_566 , sizeof( V_683 ) ) )
goto V_113;
V_121 = F_343 ( V_139 , & V_683 ) ;
break;
}
default:
V_121 = F_355 ( V_139 , V_564 , V_565 ) ;
}
V_113:
return V_121 ;
}
static void F_356 ( void )
{
T_1 V_815 [ 2 ] ;
unsigned V_3 , V_816 ;
for ( V_3 = V_816 = 0 ; V_3 < F_55 ( V_574 ) ; V_3 ++ ) {
if ( F_357 ( V_574 [ V_3 ] , & V_815 [ 0 ] , & V_815 [ 1 ] ) < 0 )
continue;
switch ( V_574 [ V_3 ] ) {
case V_817 :
if ( ! V_87 -> V_818 () )
continue;
break;
case V_819 :
if ( ! V_87 -> V_820 () )
continue;
break;
default:
break;
}
if ( V_816 < V_3 )
V_574 [ V_816 ] = V_574 [ V_3 ] ;
V_816 ++ ;
}
V_571 = V_816 ;
for ( V_3 = V_816 = 0 ; V_3 < F_55 ( V_575 ) ; V_3 ++ ) {
switch ( V_575 [ V_3 ] ) {
case V_426 :
if ( ! V_87 -> V_542 () )
continue;
break;
default:
break;
}
if ( V_816 < V_3 )
V_575 [ V_816 ] = V_575 [ V_3 ] ;
V_816 ++ ;
}
V_572 = V_816 ;
}
static int F_358 ( struct V_1 * V_2 , T_6 V_619 , int V_95 ,
const void * V_267 )
{
int V_821 = 0 ;
int V_492 ;
do {
V_492 = F_359 ( V_95 , 8 ) ;
if ( ! ( F_91 ( V_2 ) &&
! F_360 ( V_2 , & V_2 -> V_5 . V_649 -> V_822 , V_619 , V_492 , V_267 ) )
&& F_361 ( V_2 , V_823 , V_619 , V_492 , V_267 ) )
break;
V_821 += V_492 ;
V_619 += V_492 ;
V_95 -= V_492 ;
V_267 += V_492 ;
} while ( V_95 );
return V_821 ;
}
static int F_362 ( struct V_1 * V_2 , T_6 V_619 , int V_95 , void * V_267 )
{
int V_821 = 0 ;
int V_492 ;
do {
V_492 = F_359 ( V_95 , 8 ) ;
if ( ! ( F_91 ( V_2 ) &&
! F_363 ( V_2 , & V_2 -> V_5 . V_649 -> V_822 ,
V_619 , V_492 , V_267 ) )
&& F_364 ( V_2 , V_823 , V_619 , V_492 , V_267 ) )
break;
F_365 ( V_824 , V_492 , V_619 , * ( T_2 * ) V_267 ) ;
V_821 += V_492 ;
V_619 += V_492 ;
V_95 -= V_492 ;
V_267 += V_492 ;
} while ( V_95 );
return V_821 ;
}
static void F_366 ( struct V_1 * V_2 ,
struct V_825 * V_826 , int V_827 )
{
V_87 -> V_828 ( V_2 , V_826 , V_827 ) ;
}
void F_367 ( struct V_1 * V_2 ,
struct V_825 * V_826 , int V_827 )
{
V_87 -> V_829 ( V_2 , V_826 , V_827 ) ;
}
T_6 F_368 ( struct V_1 * V_2 , T_6 V_391 , T_1 V_96 ,
struct V_74 * V_69 )
{
T_6 V_830 ;
F_15 ( ! F_42 ( V_2 ) ) ;
V_96 |= V_111 ;
V_830 = V_2 -> V_5 . V_83 . V_831 ( V_2 , V_391 , V_96 , V_69 ) ;
return V_830 ;
}
T_6 F_369 ( struct V_1 * V_2 , T_15 V_832 ,
struct V_74 * V_69 )
{
T_1 V_96 = ( V_87 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
return V_2 -> V_5 . V_103 -> V_831 ( V_2 , V_832 , V_96 , V_69 ) ;
}
T_6 F_370 ( struct V_1 * V_2 , T_15 V_832 ,
struct V_74 * V_69 )
{
T_1 V_96 = ( V_87 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
V_96 |= V_833 ;
return V_2 -> V_5 . V_103 -> V_831 ( V_2 , V_832 , V_96 , V_69 ) ;
}
T_6 F_371 ( struct V_1 * V_2 , T_15 V_832 ,
struct V_74 * V_69 )
{
T_1 V_96 = ( V_87 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
V_96 |= V_112 ;
return V_2 -> V_5 . V_103 -> V_831 ( V_2 , V_832 , V_96 , V_69 ) ;
}
T_6 F_372 ( struct V_1 * V_2 , T_15 V_832 ,
struct V_74 * V_69 )
{
return V_2 -> V_5 . V_103 -> V_831 ( V_2 , V_832 , 0 , V_69 ) ;
}
static int F_373 ( T_15 V_619 , void * V_196 , unsigned int V_834 ,
struct V_1 * V_2 , T_1 V_96 ,
struct V_74 * V_69 )
{
void * V_39 = V_196 ;
int V_121 = V_835 ;
while ( V_834 ) {
T_6 V_391 = V_2 -> V_5 . V_103 -> V_831 ( V_2 , V_619 , V_96 ,
V_69 ) ;
unsigned V_94 = V_619 & ( V_107 - 1 ) ;
unsigned V_836 = F_359 ( V_834 , ( unsigned ) V_107 - V_94 ) ;
int V_108 ;
if ( V_391 == V_100 )
return V_837 ;
V_108 = F_52 ( V_2 , V_391 >> V_106 , V_39 ,
V_94 , V_836 ) ;
if ( V_108 < 0 ) {
V_121 = V_838 ;
goto V_113;
}
V_834 -= V_836 ;
V_39 += V_836 ;
V_619 += V_836 ;
}
V_113:
return V_121 ;
}
static int F_374 ( struct V_839 * V_840 ,
T_15 V_619 , void * V_196 , unsigned int V_834 ,
struct V_74 * V_69 )
{
struct V_1 * V_2 = F_375 ( V_840 ) ;
T_1 V_96 = ( V_87 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
unsigned V_94 ;
int V_108 ;
T_6 V_391 = V_2 -> V_5 . V_103 -> V_831 ( V_2 , V_619 , V_96 | V_833 ,
V_69 ) ;
if ( F_171 ( V_391 == V_100 ) )
return V_837 ;
V_94 = V_619 & ( V_107 - 1 ) ;
if ( F_30 ( V_94 + V_834 > V_107 ) )
V_834 = ( unsigned ) V_107 - V_94 ;
V_108 = F_52 ( V_2 , V_391 >> V_106 , V_196 ,
V_94 , V_834 ) ;
if ( F_171 ( V_108 < 0 ) )
return V_838 ;
return V_835 ;
}
int F_376 ( struct V_839 * V_840 ,
T_15 V_619 , void * V_196 , unsigned int V_834 ,
struct V_74 * V_69 )
{
struct V_1 * V_2 = F_375 ( V_840 ) ;
T_1 V_96 = ( V_87 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
return F_373 ( V_619 , V_196 , V_834 , V_2 , V_96 ,
V_69 ) ;
}
static int F_377 ( struct V_839 * V_840 ,
T_15 V_619 , void * V_196 , unsigned int V_834 ,
struct V_74 * V_69 )
{
struct V_1 * V_2 = F_375 ( V_840 ) ;
return F_373 ( V_619 , V_196 , V_834 , V_2 , 0 , V_69 ) ;
}
static int F_378 ( struct V_839 * V_840 ,
unsigned long V_619 , void * V_196 , unsigned int V_834 )
{
struct V_1 * V_2 = F_375 ( V_840 ) ;
int V_121 = F_379 ( V_2 , V_619 , V_196 , V_834 ) ;
return V_121 < 0 ? V_838 : V_835 ;
}
int F_380 ( struct V_839 * V_840 ,
T_15 V_619 , void * V_196 ,
unsigned int V_834 ,
struct V_74 * V_69 )
{
struct V_1 * V_2 = F_375 ( V_840 ) ;
void * V_39 = V_196 ;
int V_121 = V_835 ;
while ( V_834 ) {
T_6 V_391 = V_2 -> V_5 . V_103 -> V_831 ( V_2 , V_619 ,
V_112 ,
V_69 ) ;
unsigned V_94 = V_619 & ( V_107 - 1 ) ;
unsigned V_841 = F_359 ( V_834 , ( unsigned ) V_107 - V_94 ) ;
int V_108 ;
if ( V_391 == V_100 )
return V_837 ;
V_108 = F_211 ( V_2 , V_391 , V_39 , V_841 ) ;
if ( V_108 < 0 ) {
V_121 = V_838 ;
goto V_113;
}
V_834 -= V_841 ;
V_39 += V_841 ;
V_619 += V_841 ;
}
V_113:
return V_121 ;
}
static int F_381 ( struct V_1 * V_2 , unsigned long V_832 ,
T_6 V_391 , bool V_842 )
{
if ( ( V_391 & V_385 ) == V_843 )
return 1 ;
if ( F_382 ( V_2 , V_391 ) ) {
F_383 ( V_832 , V_391 , V_842 , true ) ;
return 1 ;
}
return 0 ;
}
static int F_384 ( struct V_1 * V_2 , unsigned long V_832 ,
T_6 * V_391 , struct V_74 * V_69 ,
bool V_842 )
{
T_1 V_96 = ( ( V_87 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 )
| ( V_842 ? V_112 : 0 ) ;
if ( F_385 ( V_2 , V_832 )
&& ! F_386 ( V_2 , V_2 -> V_5 . V_103 ,
V_2 -> V_5 . V_96 , 0 , V_96 ) ) {
* V_391 = V_2 -> V_5 . V_844 << V_106 |
( V_832 & ( V_107 - 1 ) ) ;
F_383 ( V_832 , * V_391 , V_842 , false ) ;
return 1 ;
}
* V_391 = V_2 -> V_5 . V_103 -> V_831 ( V_2 , V_832 , V_96 , V_69 ) ;
if ( * V_391 == V_100 )
return - 1 ;
return F_381 ( V_2 , V_832 , * V_391 , V_842 ) ;
}
int F_387 ( struct V_1 * V_2 , T_6 V_391 ,
const void * V_196 , int V_834 )
{
int V_108 ;
V_108 = F_211 ( V_2 , V_391 , V_196 , V_834 ) ;
if ( V_108 < 0 )
return 0 ;
F_388 ( V_2 , V_391 , V_196 , V_834 ) ;
return 1 ;
}
static int F_389 ( struct V_1 * V_2 , void * V_196 , int V_834 )
{
if ( V_2 -> V_845 ) {
F_365 ( V_824 , V_834 ,
V_2 -> V_846 [ 0 ] . V_391 , * ( T_2 * ) V_196 ) ;
V_2 -> V_845 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_390 ( struct V_1 * V_2 , T_6 V_391 ,
void * V_196 , int V_834 )
{
return ! F_379 ( V_2 , V_391 , V_196 , V_834 ) ;
}
static int F_391 ( struct V_1 * V_2 , T_6 V_391 ,
void * V_196 , int V_834 )
{
return F_387 ( V_2 , V_391 , V_196 , V_834 ) ;
}
static int F_392 ( struct V_1 * V_2 , T_6 V_391 , int V_834 , void * V_196 )
{
F_365 ( V_847 , V_834 , V_391 , * ( T_2 * ) V_196 ) ;
return F_358 ( V_2 , V_391 , V_834 , V_196 ) ;
}
static int F_393 ( struct V_1 * V_2 , T_6 V_391 ,
void * V_196 , int V_834 )
{
F_365 ( V_848 , V_834 , V_391 , 0 ) ;
return V_838 ;
}
static int F_394 ( struct V_1 * V_2 , T_6 V_391 ,
void * V_196 , int V_834 )
{
struct V_849 * V_850 = & V_2 -> V_846 [ 0 ] ;
memcpy ( V_2 -> V_851 -> V_852 . V_39 , V_850 -> V_39 , F_359 ( 8u , V_850 -> V_95 ) ) ;
return V_835 ;
}
static int F_395 ( unsigned long V_619 , void * V_196 ,
unsigned int V_834 ,
struct V_74 * V_69 ,
struct V_1 * V_2 ,
const struct V_853 * V_854 )
{
T_6 V_391 ;
int V_821 , V_108 ;
bool V_842 = V_854 -> V_842 ;
struct V_849 * V_850 ;
struct V_839 * V_840 = & V_2 -> V_5 . V_855 ;
if ( V_2 -> V_5 . V_856 &&
F_396 ( V_840 ) &&
F_381 ( V_2 , V_619 , V_69 -> V_79 , V_842 ) &&
( V_619 & ~ V_385 ) == ( V_69 -> V_79 & ~ V_385 ) ) {
V_391 = V_69 -> V_79 ;
goto V_852;
}
V_108 = F_384 ( V_2 , V_619 , & V_391 , V_69 , V_842 ) ;
if ( V_108 < 0 )
return V_837 ;
if ( V_108 )
goto V_852;
if ( V_854 -> V_857 ( V_2 , V_391 , V_196 , V_834 ) )
return V_835 ;
V_852:
V_821 = V_854 -> V_858 ( V_2 , V_391 , V_834 , V_196 ) ;
if ( V_821 == V_834 )
return V_835 ;
V_391 += V_821 ;
V_834 -= V_821 ;
V_196 += V_821 ;
F_30 ( V_2 -> V_859 >= V_860 ) ;
V_850 = & V_2 -> V_846 [ V_2 -> V_859 ++ ] ;
V_850 -> V_391 = V_391 ;
V_850 -> V_39 = V_196 ;
V_850 -> V_95 = V_834 ;
return V_835 ;
}
static int F_397 ( struct V_839 * V_840 ,
unsigned long V_619 ,
void * V_196 , unsigned int V_834 ,
struct V_74 * V_69 ,
const struct V_853 * V_854 )
{
struct V_1 * V_2 = F_375 ( V_840 ) ;
T_6 V_391 ;
int V_861 ;
if ( V_854 -> V_862 &&
V_854 -> V_862 ( V_2 , V_196 , V_834 ) )
return V_835 ;
V_2 -> V_859 = 0 ;
if ( ( ( V_619 + V_834 - 1 ) ^ V_619 ) & V_385 ) {
int V_863 ;
V_863 = - V_619 & ~ V_385 ;
V_861 = F_395 ( V_619 , V_196 , V_863 , V_69 ,
V_2 , V_854 ) ;
if ( V_861 != V_835 )
return V_861 ;
V_619 += V_863 ;
if ( V_840 -> V_331 != V_864 )
V_619 = ( T_1 ) V_619 ;
V_196 += V_863 ;
V_834 -= V_863 ;
}
V_861 = F_395 ( V_619 , V_196 , V_834 , V_69 ,
V_2 , V_854 ) ;
if ( V_861 != V_835 )
return V_861 ;
if ( ! V_2 -> V_859 )
return V_861 ;
V_391 = V_2 -> V_846 [ 0 ] . V_391 ;
V_2 -> V_865 = 1 ;
V_2 -> V_866 = 0 ;
V_2 -> V_851 -> V_852 . V_95 = F_359 ( 8u , V_2 -> V_846 [ 0 ] . V_95 ) ;
V_2 -> V_851 -> V_852 . V_867 = V_2 -> V_868 = V_854 -> V_842 ;
V_2 -> V_851 -> V_869 = V_870 ;
V_2 -> V_851 -> V_852 . V_871 = V_391 ;
return V_854 -> V_872 ( V_2 , V_391 , V_196 , V_834 ) ;
}
static int F_398 ( struct V_839 * V_840 ,
unsigned long V_619 ,
void * V_196 ,
unsigned int V_834 ,
struct V_74 * V_69 )
{
return F_397 ( V_840 , V_619 , V_196 , V_834 ,
V_69 , & V_873 ) ;
}
static int F_399 ( struct V_839 * V_840 ,
unsigned long V_619 ,
const void * V_196 ,
unsigned int V_834 ,
struct V_74 * V_69 )
{
return F_397 ( V_840 , V_619 , ( void * ) V_196 , V_834 ,
V_69 , & V_874 ) ;
}
static int F_400 ( struct V_839 * V_840 ,
unsigned long V_619 ,
const void * V_875 ,
const void * V_876 ,
unsigned int V_834 ,
struct V_74 * V_69 )
{
struct V_1 * V_2 = F_375 ( V_840 ) ;
T_6 V_391 ;
struct V_387 * V_387 ;
char * V_877 ;
bool V_878 ;
if ( V_834 > 8 || ( V_834 & ( V_834 - 1 ) ) )
goto V_879;
V_391 = F_371 ( V_2 , V_619 , NULL ) ;
if ( V_391 == V_100 ||
( V_391 & V_385 ) == V_843 )
goto V_879;
if ( ( ( V_391 + V_834 - 1 ) & V_385 ) != ( V_391 & V_385 ) )
goto V_879;
V_387 = F_401 ( V_2 , V_391 >> V_106 ) ;
if ( F_402 ( V_387 ) )
goto V_879;
V_877 = F_403 ( V_387 ) ;
V_877 += F_404 ( V_391 ) ;
switch ( V_834 ) {
case 1 :
V_878 = F_405 ( T_13 , V_877 , V_875 , V_876 ) ;
break;
case 2 :
V_878 = F_405 ( V_880 , V_877 , V_875 , V_876 ) ;
break;
case 4 :
V_878 = F_405 ( T_1 , V_877 , V_875 , V_876 ) ;
break;
case 8 :
V_878 = F_406 ( V_877 , V_875 , V_876 ) ;
break;
default:
F_27 () ;
}
F_407 ( V_877 ) ;
F_408 ( V_387 ) ;
if ( ! V_878 )
return V_881 ;
F_409 ( V_2 , V_391 >> V_106 ) ;
F_388 ( V_2 , V_391 , V_876 , V_834 ) ;
return V_835 ;
V_879:
F_410 ( V_882 L_20 ) ;
return F_399 ( V_840 , V_619 , V_876 , V_834 , V_69 ) ;
}
static int F_411 ( struct V_1 * V_2 , void * V_883 )
{
int V_121 ;
if ( V_2 -> V_5 . V_884 . V_885 )
V_121 = F_364 ( V_2 , V_886 , V_2 -> V_5 . V_884 . V_887 ,
V_2 -> V_5 . V_884 . V_493 , V_883 ) ;
else
V_121 = F_361 ( V_2 , V_886 ,
V_2 -> V_5 . V_884 . V_887 , V_2 -> V_5 . V_884 . V_493 ,
V_883 ) ;
return V_121 ;
}
static int F_412 ( struct V_1 * V_2 , int V_493 ,
unsigned short V_887 , void * V_196 ,
unsigned int V_751 , bool V_885 )
{
V_2 -> V_5 . V_884 . V_887 = V_887 ;
V_2 -> V_5 . V_884 . V_885 = V_885 ;
V_2 -> V_5 . V_884 . V_751 = V_751 ;
V_2 -> V_5 . V_884 . V_493 = V_493 ;
if ( ! F_411 ( V_2 , V_2 -> V_5 . V_888 ) ) {
V_2 -> V_5 . V_884 . V_751 = 0 ;
return 1 ;
}
V_2 -> V_851 -> V_869 = V_889 ;
V_2 -> V_851 -> V_890 . V_891 = V_885 ? V_892 : V_893 ;
V_2 -> V_851 -> V_890 . V_493 = V_493 ;
V_2 -> V_851 -> V_890 . V_894 = V_895 * V_107 ;
V_2 -> V_851 -> V_890 . V_751 = V_751 ;
V_2 -> V_851 -> V_890 . V_887 = V_887 ;
return 0 ;
}
static int F_413 ( struct V_839 * V_840 ,
int V_493 , unsigned short V_887 , void * V_196 ,
unsigned int V_751 )
{
struct V_1 * V_2 = F_375 ( V_840 ) ;
int V_108 ;
if ( V_2 -> V_5 . V_884 . V_751 )
goto V_896;
V_108 = F_412 ( V_2 , V_493 , V_887 , V_196 , V_751 , true ) ;
if ( V_108 ) {
V_896:
memcpy ( V_196 , V_2 -> V_5 . V_888 , V_493 * V_751 ) ;
F_414 ( V_897 , V_887 , V_493 , V_751 , V_2 -> V_5 . V_888 ) ;
V_2 -> V_5 . V_884 . V_751 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_415 ( struct V_839 * V_840 ,
int V_493 , unsigned short V_887 ,
const void * V_196 , unsigned int V_751 )
{
struct V_1 * V_2 = F_375 ( V_840 ) ;
memcpy ( V_2 -> V_5 . V_888 , V_196 , V_493 * V_751 ) ;
F_414 ( V_898 , V_887 , V_493 , V_751 , V_2 -> V_5 . V_888 ) ;
return F_412 ( V_2 , V_493 , V_887 , ( void * ) V_196 , V_751 , false ) ;
}
static unsigned long F_416 ( struct V_1 * V_2 , int V_827 )
{
return V_87 -> F_416 ( V_2 , V_827 ) ;
}
static void F_417 ( struct V_839 * V_840 , V_176 V_79 )
{
F_418 ( F_375 ( V_840 ) , V_79 ) ;
}
static int F_419 ( struct V_1 * V_2 )
{
if ( ! F_253 ( V_2 ) )
return V_835 ;
if ( V_87 -> V_586 () ) {
int V_24 = F_420 () ;
F_256 ( V_24 , V_2 -> V_5 . V_587 ) ;
F_421 ( V_2 -> V_5 . V_587 ,
F_251 , NULL , 1 ) ;
F_422 () ;
F_423 ( V_2 -> V_5 . V_587 ) ;
} else
F_252 () ;
return V_835 ;
}
int F_424 ( struct V_1 * V_2 )
{
F_419 ( V_2 ) ;
return F_38 ( V_2 ) ;
}
static void F_425 ( struct V_839 * V_840 )
{
F_419 ( F_375 ( V_840 ) ) ;
}
static int F_426 ( struct V_839 * V_840 , int V_89 ,
unsigned long * V_655 )
{
return F_102 ( F_375 ( V_840 ) , V_89 , V_655 ) ;
}
static int F_427 ( struct V_839 * V_840 , int V_89 ,
unsigned long V_23 )
{
return F_100 ( F_375 ( V_840 ) , V_89 , V_23 ) ;
}
static T_2 F_428 ( T_2 V_899 , T_1 V_900 )
{
return ( V_899 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_900 ;
}
static unsigned long F_429 ( struct V_839 * V_840 , int V_901 )
{
struct V_1 * V_2 = F_375 ( V_840 ) ;
unsigned long V_23 ;
switch ( V_901 ) {
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
F_430 ( L_21 , V_264 , V_901 ) ;
return 0 ;
}
return V_23 ;
}
static int F_431 ( struct V_839 * V_840 , int V_901 , V_176 V_196 )
{
struct V_1 * V_2 = F_375 ( V_840 ) ;
int V_902 = 0 ;
switch ( V_901 ) {
case 0 :
V_902 = F_62 ( V_2 , F_428 ( F_63 ( V_2 ) , V_196 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_78 = V_196 ;
break;
case 3 :
V_902 = F_87 ( V_2 , V_196 ) ;
break;
case 4 :
V_902 = F_79 ( V_2 , F_428 ( F_80 ( V_2 ) , V_196 ) ) ;
break;
case 8 :
V_902 = F_90 ( V_2 , V_196 ) ;
break;
default:
F_430 ( L_21 , V_264 , V_901 ) ;
V_902 = - 1 ;
}
return V_902 ;
}
static int F_432 ( struct V_839 * V_840 )
{
return V_87 -> V_88 ( F_375 ( V_840 ) ) ;
}
static void F_433 ( struct V_839 * V_840 , struct V_903 * V_904 )
{
V_87 -> V_905 ( F_375 ( V_840 ) , V_904 ) ;
}
static void F_434 ( struct V_839 * V_840 , struct V_903 * V_904 )
{
V_87 -> V_906 ( F_375 ( V_840 ) , V_904 ) ;
}
static void F_435 ( struct V_839 * V_840 , struct V_903 * V_904 )
{
V_87 -> V_907 ( F_375 ( V_840 ) , V_904 ) ;
}
static void F_436 ( struct V_839 * V_840 , struct V_903 * V_904 )
{
V_87 -> V_908 ( F_375 ( V_840 ) , V_904 ) ;
}
static unsigned long F_437 (
struct V_839 * V_840 , int V_827 )
{
return F_416 ( F_375 ( V_840 ) , V_827 ) ;
}
static bool F_438 ( struct V_839 * V_840 , V_880 * V_909 ,
struct V_910 * V_911 , T_1 * V_912 ,
int V_827 )
{
struct V_825 V_826 ;
F_367 ( F_375 ( V_840 ) , & V_826 , V_827 ) ;
* V_909 = V_826 . V_909 ;
if ( V_826 . V_913 ) {
memset ( V_911 , 0 , sizeof( * V_911 ) ) ;
return false ;
}
if ( V_826 . V_914 )
V_826 . V_915 >>= 12 ;
F_439 ( V_911 , V_826 . V_915 ) ;
F_440 ( V_911 , ( unsigned long ) V_826 . V_230 ) ;
#ifdef F_64
if ( V_912 )
* V_912 = V_826 . V_230 >> 32 ;
#endif
V_911 -> type = V_826 . type ;
V_911 -> V_595 = V_826 . V_595 ;
V_911 -> V_916 = V_826 . V_916 ;
V_911 -> V_917 = V_826 . V_918 ;
V_911 -> V_919 = V_826 . V_919 ;
V_911 -> V_920 = V_826 . V_920 ;
V_911 -> V_921 = V_826 . V_183 ;
V_911 -> V_914 = V_826 . V_914 ;
return true ;
}
static void F_441 ( struct V_839 * V_840 , V_880 V_909 ,
struct V_910 * V_911 , T_1 V_912 ,
int V_827 )
{
struct V_1 * V_2 = F_375 ( V_840 ) ;
struct V_825 V_826 ;
V_826 . V_909 = V_909 ;
V_826 . V_230 = F_442 ( V_911 ) ;
#ifdef F_64
V_826 . V_230 |= ( ( T_2 ) V_912 ) << 32 ;
#endif
V_826 . V_915 = F_443 ( V_911 ) ;
if ( V_911 -> V_914 )
V_826 . V_915 = ( V_826 . V_915 << 12 ) | 0xfff ;
V_826 . type = V_911 -> type ;
V_826 . V_916 = V_911 -> V_916 ;
V_826 . V_183 = V_911 -> V_921 ;
V_826 . V_595 = V_911 -> V_595 ;
V_826 . V_920 = V_911 -> V_920 ;
V_826 . V_914 = V_911 -> V_914 ;
V_826 . V_919 = V_911 -> V_919 ;
V_826 . V_918 = V_911 -> V_917 ;
V_826 . V_913 = ! V_826 . V_918 ;
V_826 . V_922 = 0 ;
F_366 ( V_2 , & V_826 , V_827 ) ;
return;
}
static int F_444 ( struct V_839 * V_840 ,
T_1 V_923 , T_2 * V_465 )
{
struct V_33 V_22 ;
int V_121 ;
V_22 . V_147 = V_923 ;
V_22 . V_41 = false ;
V_121 = F_116 ( F_375 ( V_840 ) , & V_22 ) ;
if ( V_121 )
return V_121 ;
* V_465 = V_22 . V_39 ;
return 0 ;
}
static int F_445 ( struct V_839 * V_840 ,
T_1 V_923 , T_2 V_39 )
{
struct V_33 V_22 ;
V_22 . V_39 = V_39 ;
V_22 . V_147 = V_923 ;
V_22 . V_41 = false ;
return F_112 ( F_375 ( V_840 ) , & V_22 ) ;
}
static T_2 F_446 ( struct V_839 * V_840 )
{
struct V_1 * V_2 = F_375 ( V_840 ) ;
return V_2 -> V_5 . V_427 ;
}
static void F_447 ( struct V_839 * V_840 , T_2 V_427 )
{
struct V_1 * V_2 = F_375 ( V_840 ) ;
V_2 -> V_5 . V_427 = V_427 ;
}
static int F_448 ( struct V_839 * V_840 ,
T_1 V_924 )
{
return F_449 ( F_375 ( V_840 ) , V_924 ) ;
}
static int F_450 ( struct V_839 * V_840 ,
T_1 V_924 , T_2 * V_465 )
{
return F_105 ( F_375 ( V_840 ) , V_924 , V_465 ) ;
}
static void F_451 ( struct V_839 * V_840 )
{
F_375 ( V_840 ) -> V_5 . V_925 = 1 ;
}
static void F_452 ( struct V_839 * V_840 )
{
F_453 () ;
F_454 ( F_375 ( V_840 ) ) ;
}
static void F_455 ( struct V_839 * V_840 )
{
F_456 () ;
}
static int F_457 ( struct V_839 * V_840 ,
struct V_926 * V_927 ,
enum V_928 V_929 )
{
return V_87 -> V_930 ( F_375 ( V_840 ) , V_927 , V_929 ) ;
}
static void F_458 ( struct V_839 * V_840 ,
T_1 * V_931 , T_1 * V_932 , T_1 * V_201 , T_1 * V_209 )
{
V_695 ( F_375 ( V_840 ) , V_931 , V_932 , V_201 , V_209 ) ;
}
static V_176 F_459 ( struct V_839 * V_840 , unsigned V_933 )
{
return F_104 ( F_375 ( V_840 ) , V_933 ) ;
}
static void F_460 ( struct V_839 * V_840 , unsigned V_933 , V_176 V_196 )
{
F_106 ( F_375 ( V_840 ) , V_933 , V_196 ) ;
}
static void F_461 ( struct V_839 * V_840 , bool V_632 )
{
V_87 -> V_648 ( F_375 ( V_840 ) , V_632 ) ;
}
static void F_462 ( struct V_1 * V_2 , T_1 V_29 )
{
T_1 V_934 = V_87 -> V_628 ( V_2 ) ;
if ( V_934 & V_29 )
V_29 = 0 ;
if ( F_171 ( V_934 || V_29 ) ) {
V_87 -> V_647 ( V_2 , V_29 ) ;
if ( ! V_29 )
F_32 ( V_68 , V_2 ) ;
}
}
static bool F_463 ( struct V_1 * V_2 )
{
struct V_839 * V_840 = & V_2 -> V_5 . V_855 ;
if ( V_840 -> V_69 . V_42 == V_43 )
return F_41 ( V_2 , & V_840 -> V_69 ) ;
if ( V_840 -> V_69 . V_935 )
F_40 ( V_2 , V_840 -> V_69 . V_42 ,
V_840 -> V_69 . V_63 ) ;
else
F_34 ( V_2 , V_840 -> V_69 . V_42 ) ;
return false ;
}
static void F_464 ( struct V_1 * V_2 )
{
struct V_839 * V_840 = & V_2 -> V_5 . V_855 ;
int V_134 , V_135 ;
V_87 -> V_136 ( V_2 , & V_134 , & V_135 ) ;
V_840 -> V_936 = F_465 ( V_2 ) ;
V_840 -> V_937 = F_466 ( V_2 ) ;
V_840 -> V_331 = ( ! F_33 ( V_2 ) ) ? V_938 :
( V_840 -> V_936 & V_939 ) ? V_940 :
( V_135 && F_58 ( V_2 ) ) ? V_864 :
V_134 ? V_941 :
V_942 ;
F_191 ( V_943 != V_944 ) ;
F_191 ( V_650 != V_945 ) ;
F_191 ( V_640 != V_946 ) ;
V_840 -> V_947 = V_2 -> V_5 . V_639 ;
F_467 ( V_840 ) ;
V_2 -> V_5 . V_948 = false ;
}
int F_468 ( struct V_1 * V_2 , int V_599 , int V_949 )
{
struct V_839 * V_840 = & V_2 -> V_5 . V_855 ;
int V_108 ;
F_464 ( V_2 ) ;
V_840 -> V_950 = 2 ;
V_840 -> V_951 = 2 ;
V_840 -> V_952 = V_840 -> V_937 + V_949 ;
V_108 = F_469 ( V_840 , V_599 ) ;
if ( V_108 != V_835 )
return V_953 ;
V_840 -> V_937 = V_840 -> V_952 ;
F_470 ( V_2 , V_840 -> V_937 ) ;
F_471 ( V_2 , V_840 -> V_936 ) ;
if ( V_599 == V_52 )
V_2 -> V_5 . V_631 = 0 ;
else
V_2 -> V_5 . V_625 . V_70 = false ;
return V_954 ;
}
static int F_472 ( struct V_1 * V_2 )
{
int V_121 = V_954 ;
++ V_2 -> V_76 . V_955 ;
F_473 ( V_2 ) ;
if ( ! F_474 ( V_2 ) && V_87 -> V_88 ( V_2 ) == 0 ) {
V_2 -> V_851 -> V_869 = V_956 ;
V_2 -> V_851 -> V_957 . V_958 = V_959 ;
V_2 -> V_851 -> V_957 . V_960 = 0 ;
V_121 = V_953 ;
}
F_34 ( V_2 , V_91 ) ;
return V_121 ;
}
static bool F_475 ( struct V_1 * V_2 , T_15 V_78 ,
bool V_961 ,
int V_962 )
{
T_6 V_391 = V_78 ;
T_16 V_963 ;
if ( V_962 & V_964 )
return false ;
if ( ! V_2 -> V_5 . V_83 . V_965 ) {
V_391 = F_371 ( V_2 , V_78 , NULL ) ;
if ( V_391 == V_100 )
return true ;
}
V_963 = F_476 ( V_2 -> V_139 , F_51 ( V_391 ) ) ;
if ( F_477 ( V_963 ) )
return false ;
F_478 ( V_963 ) ;
if ( V_2 -> V_5 . V_83 . V_965 ) {
unsigned int V_966 ;
F_161 ( & V_2 -> V_139 -> V_967 ) ;
V_966 = V_2 -> V_139 -> V_5 . V_966 ;
F_162 ( & V_2 -> V_139 -> V_967 ) ;
if ( V_966 )
F_479 ( V_2 -> V_139 , F_51 ( V_391 ) ) ;
return true ;
}
F_479 ( V_2 -> V_139 , F_51 ( V_391 ) ) ;
return ! V_961 ;
}
static bool F_480 ( struct V_839 * V_840 ,
unsigned long V_78 , int V_962 )
{
struct V_1 * V_2 = F_375 ( V_840 ) ;
unsigned long V_968 , V_969 , V_391 = V_78 ;
V_968 = V_2 -> V_5 . V_968 ;
V_969 = V_2 -> V_5 . V_969 ;
V_2 -> V_5 . V_968 = V_2 -> V_5 . V_969 = 0 ;
if ( ! ( V_962 & V_970 ) )
return false ;
if ( F_481 ( V_840 ) )
return false ;
if ( V_840 -> V_937 == V_968 && V_969 == V_78 )
return false ;
V_2 -> V_5 . V_968 = V_840 -> V_937 ;
V_2 -> V_5 . V_969 = V_78 ;
if ( ! V_2 -> V_5 . V_83 . V_965 )
V_391 = F_371 ( V_2 , V_78 , NULL ) ;
F_479 ( V_2 -> V_139 , F_51 ( V_391 ) ) ;
return true ;
}
static void F_482 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_639 & V_650 ) ) {
F_483 ( V_2 -> V_300 , V_2 -> V_5 . V_427 , false ) ;
F_32 ( V_68 , V_2 ) ;
}
F_67 ( V_2 ) ;
}
static void F_294 ( struct V_1 * V_2 , unsigned V_947 )
{
unsigned V_120 = V_2 -> V_5 . V_639 ^ V_947 ;
V_2 -> V_5 . V_639 = V_947 ;
if ( V_120 & V_650 )
F_482 ( V_2 ) ;
}
static int F_484 ( unsigned long V_619 , T_1 type , T_1 V_188 ,
unsigned long * V_183 )
{
T_1 V_187 = 0 ;
int V_3 ;
T_1 V_971 , V_972 ;
V_971 = V_188 ;
V_972 = V_188 >> 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ , V_971 >>= 2 , V_972 >>= 4 )
if ( ( V_971 & 3 ) && ( V_972 & 15 ) == type && V_183 [ V_3 ] == V_619 )
V_187 |= ( 1 << V_3 ) ;
return V_187 ;
}
static void F_485 ( struct V_1 * V_2 , unsigned long V_973 , int * V_121 )
{
struct V_974 * V_974 = V_2 -> V_851 ;
if ( F_171 ( V_973 & V_975 ) ) {
if ( V_2 -> V_179 & V_976 ) {
V_974 -> V_977 . V_5 . V_187 = V_978 | V_194 |
V_195 ;
V_974 -> V_977 . V_5 . V_979 = V_2 -> V_5 . V_980 ;
V_974 -> V_977 . V_5 . V_69 = V_54 ;
V_974 -> V_869 = V_981 ;
* V_121 = V_982 ;
} else {
V_2 -> V_5 . V_187 &= ~ 15 ;
V_2 -> V_5 . V_187 |= V_978 | V_195 ;
F_34 ( V_2 , V_54 ) ;
}
}
}
int F_38 ( struct V_1 * V_2 )
{
unsigned long V_973 = V_87 -> V_983 ( V_2 ) ;
int V_121 = V_954 ;
V_87 -> V_984 ( V_2 ) ;
F_485 ( V_2 , V_973 , & V_121 ) ;
return V_121 == V_954 ;
}
static bool F_486 ( struct V_1 * V_2 , int * V_121 )
{
if ( F_171 ( V_2 -> V_179 & V_180 ) &&
( V_2 -> V_5 . V_189 & V_192 ) ) {
struct V_974 * V_974 = V_2 -> V_851 ;
unsigned long V_937 = F_487 ( V_2 ) ;
T_1 V_187 = F_484 ( V_937 , 0 ,
V_2 -> V_5 . V_189 ,
V_2 -> V_5 . V_182 ) ;
if ( V_187 != 0 ) {
V_974 -> V_977 . V_5 . V_187 = V_187 | V_194 | V_195 ;
V_974 -> V_977 . V_5 . V_979 = V_937 ;
V_974 -> V_977 . V_5 . V_69 = V_54 ;
V_974 -> V_869 = V_981 ;
* V_121 = V_982 ;
return true ;
}
}
if ( F_171 ( V_2 -> V_5 . V_188 & V_192 ) &&
! ( F_465 ( V_2 ) & V_985 ) ) {
unsigned long V_937 = F_487 ( V_2 ) ;
T_1 V_187 = F_484 ( V_937 , 0 ,
V_2 -> V_5 . V_188 ,
V_2 -> V_5 . V_183 ) ;
if ( V_187 != 0 ) {
V_2 -> V_5 . V_187 &= ~ 15 ;
V_2 -> V_5 . V_187 |= V_187 | V_195 ;
F_34 ( V_2 , V_54 ) ;
* V_121 = V_954 ;
return true ;
}
}
return false ;
}
int F_488 ( struct V_1 * V_2 ,
unsigned long V_78 ,
int V_962 ,
void * V_986 ,
int V_987 )
{
int V_121 ;
struct V_839 * V_840 = & V_2 -> V_5 . V_855 ;
bool V_491 = true ;
bool V_988 = V_2 -> V_5 . V_961 ;
V_2 -> V_5 . V_961 = false ;
F_489 ( V_2 ) ;
if ( ! ( V_962 & V_989 ) ) {
F_464 ( V_2 ) ;
if ( F_486 ( V_2 , & V_121 ) )
return V_121 ;
V_840 -> V_990 = 0 ;
V_840 -> V_991 = false ;
V_840 -> V_69 . V_42 = - 1 ;
V_840 -> V_992 = false ;
V_840 -> V_993 = V_962 & V_994 ;
V_121 = F_490 ( V_840 , V_986 , V_987 ) ;
F_491 ( V_2 ) ;
++ V_2 -> V_76 . V_995 ;
if ( V_121 != V_996 ) {
if ( V_962 & V_994 )
return V_953 ;
if ( F_475 ( V_2 , V_78 , V_988 ,
V_962 ) )
return V_954 ;
if ( V_962 & V_997 )
return V_953 ;
return F_472 ( V_2 ) ;
}
}
if ( V_962 & V_997 ) {
F_470 ( V_2 , V_840 -> V_952 ) ;
if ( V_840 -> V_936 & V_985 )
F_471 ( V_2 , V_840 -> V_936 & ~ V_985 ) ;
return V_954 ;
}
if ( F_480 ( V_840 , V_78 , V_962 ) )
return V_954 ;
if ( V_2 -> V_5 . V_948 ) {
V_2 -> V_5 . V_948 = false ;
F_492 ( V_840 ) ;
}
V_998:
V_840 -> V_69 . V_79 = V_78 ;
V_121 = F_493 ( V_840 ) ;
if ( V_121 == V_999 )
return V_954 ;
if ( V_121 == V_1000 ) {
if ( F_475 ( V_2 , V_78 , V_988 ,
V_962 ) )
return V_954 ;
return F_472 ( V_2 ) ;
}
if ( V_840 -> V_991 ) {
V_121 = V_954 ;
if ( F_463 ( V_2 ) )
return V_121 ;
} else if ( V_2 -> V_5 . V_884 . V_751 ) {
if ( ! V_2 -> V_5 . V_884 . V_885 ) {
V_2 -> V_5 . V_884 . V_751 = 0 ;
} else {
V_491 = false ;
V_2 -> V_5 . V_1001 = V_1002 ;
}
V_121 = V_982 ;
} else if ( V_2 -> V_865 ) {
if ( ! V_2 -> V_868 )
V_491 = false ;
V_121 = V_982 ;
V_2 -> V_5 . V_1001 = V_1003 ;
} else if ( V_121 == V_1004 )
goto V_998;
else
V_121 = V_954 ;
if ( V_491 ) {
unsigned long V_973 = V_87 -> V_983 ( V_2 ) ;
F_462 ( V_2 , V_840 -> V_990 ) ;
V_2 -> V_5 . V_1005 = false ;
if ( V_2 -> V_5 . V_639 != V_840 -> V_947 )
F_294 ( V_2 , V_840 -> V_947 ) ;
F_470 ( V_2 , V_840 -> V_937 ) ;
if ( V_121 == V_954 )
F_485 ( V_2 , V_973 , & V_121 ) ;
if ( ! V_840 -> V_991 ||
F_29 ( V_840 -> V_69 . V_42 ) == V_57 )
F_494 ( V_2 , V_840 -> V_936 ) ;
if ( F_171 ( ( V_840 -> V_936 & ~ V_973 ) & V_1006 ) )
F_32 ( V_68 , V_2 ) ;
} else
V_2 -> V_5 . V_1005 = true ;
return V_121 ;
}
int F_495 ( struct V_1 * V_2 , int V_493 , unsigned short V_887 )
{
unsigned long V_196 = F_104 ( V_2 , V_203 ) ;
int V_108 = F_415 ( & V_2 -> V_5 . V_855 ,
V_493 , V_887 , & V_196 , 1 ) ;
V_2 -> V_5 . V_884 . V_751 = 0 ;
return V_108 ;
}
static int F_496 ( struct V_1 * V_2 )
{
unsigned long V_196 ;
F_15 ( V_2 -> V_5 . V_884 . V_751 != 1 ) ;
V_196 = ( V_2 -> V_5 . V_884 . V_493 < 4 ) ? F_104 ( V_2 , V_203 )
: 0 ;
F_413 ( & V_2 -> V_5 . V_855 , V_2 -> V_5 . V_884 . V_493 ,
V_2 -> V_5 . V_884 . V_887 , & V_196 , 1 ) ;
F_106 ( V_2 , V_203 , V_196 ) ;
return 1 ;
}
int F_497 ( struct V_1 * V_2 , int V_493 , unsigned short V_887 )
{
unsigned long V_196 ;
int V_108 ;
V_196 = ( V_493 < 4 ) ? F_104 ( V_2 , V_203 ) : 0 ;
V_108 = F_413 ( & V_2 -> V_5 . V_855 , V_493 , V_887 ,
& V_196 , 1 ) ;
if ( V_108 ) {
F_106 ( V_2 , V_203 , V_196 ) ;
return V_108 ;
}
V_2 -> V_5 . V_1001 = F_496 ;
return 0 ;
}
static int F_498 ( unsigned int V_24 )
{
F_499 ( V_346 , 0 ) ;
return 0 ;
}
static void F_500 ( void * V_39 )
{
struct V_1007 * V_1008 = V_39 ;
unsigned long V_265 = 0 ;
if ( V_39 )
V_265 = V_1008 -> V_876 ;
else if ( ! F_248 ( V_1009 ) )
V_265 = F_501 ( F_502 () ) ;
if ( ! V_265 )
V_265 = V_274 ;
F_499 ( V_346 , V_265 ) ;
}
static int F_503 ( struct V_1010 * V_1011 , unsigned long V_196 ,
void * V_39 )
{
struct V_1007 * V_1008 = V_39 ;
struct V_139 * V_139 ;
struct V_1 * V_2 ;
int V_3 , V_1012 = 0 ;
if ( V_196 == V_1013 && V_1008 -> V_875 > V_1008 -> V_876 )
return 0 ;
if ( V_196 == V_1014 && V_1008 -> V_875 < V_1008 -> V_876 )
return 0 ;
F_257 ( V_1008 -> V_24 , F_500 , V_1008 , 1 ) ;
F_161 ( & V_1015 ) ;
F_504 (kvm, &vm_list, vm_list) {
F_183 (i, vcpu, kvm) {
if ( V_2 -> V_24 != V_1008 -> V_24 )
continue;
F_32 ( V_340 , V_2 ) ;
if ( V_2 -> V_24 != F_10 () )
V_1012 = 1 ;
}
}
F_162 ( & V_1015 ) ;
if ( V_1008 -> V_875 < V_1008 -> V_876 && V_1012 ) {
F_257 ( V_1008 -> V_24 , F_500 , V_1008 , 1 ) ;
}
return 0 ;
}
static int F_505 ( unsigned int V_24 )
{
F_500 ( NULL ) ;
return 0 ;
}
static void F_506 ( void )
{
V_1016 = V_274 ;
if ( ! F_248 ( V_1009 ) ) {
#ifdef F_507
struct V_1017 V_1018 ;
int V_24 ;
memset ( & V_1018 , 0 , sizeof( V_1018 ) ) ;
V_24 = F_420 () ;
F_508 ( & V_1018 , V_24 ) ;
if ( V_1018 . V_1019 . V_1020 )
V_1016 = V_1018 . V_1019 . V_1020 ;
F_422 () ;
#endif
F_509 ( & V_1021 ,
V_1022 ) ;
}
F_133 ( L_22 , V_1016 ) ;
F_510 ( V_1023 , L_23 ,
F_505 , F_498 ) ;
}
int F_511 ( void )
{
return F_186 ( V_1024 ) != NULL ;
}
static int F_512 ( void )
{
int V_1025 = 3 ;
if ( F_186 ( V_1024 ) )
V_1025 = V_87 -> V_88 ( F_186 ( V_1024 ) ) ;
return V_1025 != 0 ;
}
static unsigned long F_513 ( void )
{
unsigned long V_1026 = 0 ;
if ( F_186 ( V_1024 ) )
V_1026 = F_466 ( F_186 ( V_1024 ) ) ;
return V_1026 ;
}
void F_514 ( struct V_1 * V_2 )
{
F_499 ( V_1024 , V_2 ) ;
}
void F_515 ( struct V_1 * V_2 )
{
F_499 ( V_1024 , NULL ) ;
}
static void F_516 ( void )
{
T_2 V_29 ;
int V_1027 = V_1028 . V_1029 ;
V_29 = F_517 ( V_1027 , 51 ) ;
V_29 |= 1ull ;
#ifdef F_64
if ( V_1027 == 52 )
V_29 &= ~ 1ull ;
#endif
F_518 ( V_29 ) ;
}
static void F_519 ( struct V_359 * V_360 )
{
struct V_139 * V_139 ;
struct V_1 * V_2 ;
int V_3 ;
F_161 ( & V_1015 ) ;
F_504 (kvm, &vm_list, vm_list)
F_183 (i, vcpu, kvm)
F_32 ( V_299 , V_2 ) ;
F_178 ( & V_338 , 0 ) ;
F_162 ( & V_1015 ) ;
}
static int F_520 ( struct V_1010 * V_1011 , unsigned long V_1030 ,
void * V_1031 )
{
struct V_226 * V_294 = & V_226 ;
struct V_224 * V_225 = V_1031 ;
F_118 ( V_225 ) ;
if ( V_294 -> clock . V_233 != V_298 &&
F_144 ( & V_338 ) != 0 )
F_521 ( V_1032 , & V_1033 ) ;
return 0 ;
}
int F_522 ( void * V_1034 )
{
int V_121 ;
struct V_87 * V_854 = V_1034 ;
if ( V_87 ) {
F_12 ( V_27 L_24 ) ;
V_121 = - V_603 ;
goto V_113;
}
if ( ! V_854 -> V_1035 () ) {
F_12 ( V_27 L_25 ) ;
V_121 = - V_1036 ;
goto V_113;
}
if ( V_854 -> V_1037 () ) {
F_12 ( V_27 L_26 ) ;
V_121 = - V_1036 ;
goto V_113;
}
V_121 = - V_389 ;
V_26 = F_523 ( struct V_11 ) ;
if ( ! V_26 ) {
F_12 ( V_27 L_27 ) ;
goto V_113;
}
V_121 = F_524 () ;
if ( V_121 )
goto V_1038;
F_516 () ;
V_87 = V_854 ;
F_525 ( V_1039 , V_1040 ,
V_1041 , V_1042 , 0 ,
V_114 , 0 ) ;
F_506 () ;
F_526 ( & V_1043 ) ;
if ( F_248 ( V_558 ) )
V_146 = F_527 ( V_144 ) ;
F_528 () ;
#ifdef F_64
F_529 ( & V_1044 ) ;
#endif
return 0 ;
V_1038:
F_530 ( V_26 ) ;
V_113:
return V_121 ;
}
void F_531 ( void )
{
F_532 () ;
F_533 ( & V_1043 ) ;
if ( ! F_248 ( V_1009 ) )
F_534 ( & V_1021 ,
V_1022 ) ;
F_535 ( V_1023 ) ;
#ifdef F_64
F_536 ( & V_1044 ) ;
#endif
V_87 = NULL ;
F_537 () ;
F_530 ( V_26 ) ;
}
int F_538 ( struct V_1 * V_2 )
{
++ V_2 -> V_76 . V_1045 ;
if ( F_91 ( V_2 ) ) {
V_2 -> V_5 . V_1046 = V_1047 ;
return 1 ;
} else {
V_2 -> V_851 -> V_869 = V_1048 ;
return 0 ;
}
}
int F_539 ( struct V_1 * V_2 )
{
int V_108 = F_38 ( V_2 ) ;
return F_538 ( V_2 ) && V_108 ;
}
static int F_540 ( struct V_1 * V_2 , T_6 V_1049 ,
unsigned long V_1050 )
{
struct V_1051 V_1052 ;
struct V_332 V_250 ;
T_2 V_1053 ;
int V_108 ;
if ( V_1050 != V_1054 )
return - V_1055 ;
if ( F_176 ( & V_250 , & V_1053 ) == false )
return - V_1055 ;
V_1052 . V_251 = V_250 . V_252 ;
V_1052 . V_253 = V_250 . V_254 ;
V_1052 . V_288 = F_152 ( V_2 , V_1053 ) ;
V_1052 . V_15 = 0 ;
V_108 = 0 ;
if ( F_126 ( V_2 -> V_139 , V_1049 , & V_1052 ,
sizeof( struct V_1051 ) ) )
V_108 = - V_1056 ;
return V_108 ;
}
static void F_541 ( struct V_139 * V_139 , unsigned long V_15 , int V_1057 )
{
struct V_1058 V_1059 ;
V_1059 . V_1060 = 0 ;
V_1059 . V_1061 = 0 ;
V_1059 . V_1062 = V_1057 ;
V_1059 . V_1063 = false ;
V_1059 . V_1064 = V_1065 ;
F_542 ( V_139 , NULL , & V_1059 , NULL ) ;
}
void F_543 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_597 = false ;
V_87 -> V_1066 ( V_2 ) ;
}
int F_544 ( struct V_1 * V_2 )
{
unsigned long V_18 , V_1067 , V_1068 , V_1069 , V_1070 , V_108 ;
int V_1071 , V_121 ;
V_121 = F_38 ( V_2 ) ;
if ( F_545 ( V_2 -> V_139 ) )
return F_546 ( V_2 ) ;
V_18 = F_104 ( V_2 , V_203 ) ;
V_1067 = F_104 ( V_2 , V_1072 ) ;
V_1068 = F_104 ( V_2 , V_202 ) ;
V_1069 = F_104 ( V_2 , V_204 ) ;
V_1070 = F_104 ( V_2 , V_1073 ) ;
F_547 ( V_18 , V_1067 , V_1068 , V_1069 , V_1070 ) ;
V_1071 = F_548 ( V_2 ) ;
if ( ! V_1071 ) {
V_18 &= 0xFFFFFFFF ;
V_1067 &= 0xFFFFFFFF ;
V_1068 &= 0xFFFFFFFF ;
V_1069 &= 0xFFFFFFFF ;
V_1070 &= 0xFFFFFFFF ;
}
if ( V_87 -> V_88 ( V_2 ) != 0 ) {
V_108 = - V_1074 ;
goto V_113;
}
switch ( V_18 ) {
case V_1075 :
V_108 = 0 ;
break;
case V_1076 :
F_541 ( V_2 -> V_139 , V_1067 , V_1068 ) ;
V_108 = 0 ;
break;
#ifdef F_64
case V_1077 :
V_108 = F_540 ( V_2 , V_1067 , V_1068 ) ;
break;
#endif
default:
V_108 = - V_1078 ;
break;
}
V_113:
if ( ! V_1071 )
V_108 = ( T_1 ) V_108 ;
F_106 ( V_2 , V_203 , V_108 ) ;
++ V_2 -> V_76 . V_1079 ;
return V_121 ;
}
static int F_549 ( struct V_839 * V_840 )
{
struct V_1 * V_2 = F_375 ( V_840 ) ;
char V_1080 [ 3 ] ;
unsigned long V_1081 = F_466 ( V_2 ) ;
V_87 -> V_1082 ( V_2 , V_1080 ) ;
return F_399 ( V_840 , V_1081 , V_1080 , 3 ,
& V_840 -> V_69 ) ;
}
static int F_550 ( struct V_1 * V_2 )
{
return V_2 -> V_851 -> V_1083 &&
F_167 ( ! F_282 ( V_2 -> V_139 ) ) ;
}
static void F_551 ( struct V_1 * V_2 )
{
struct V_974 * V_974 = V_2 -> V_851 ;
V_974 -> V_1084 = ( F_465 ( V_2 ) & V_1006 ) != 0 ;
V_974 -> V_15 = F_291 ( V_2 ) ? V_1085 : 0 ;
V_974 -> V_177 = F_93 ( V_2 ) ;
V_974 -> V_32 = F_21 ( V_2 ) ;
V_974 -> V_1086 =
F_282 ( V_2 -> V_139 ) ||
F_275 ( V_2 ) ;
}
static void F_272 ( struct V_1 * V_2 )
{
int V_1087 , V_1088 ;
if ( ! V_87 -> F_272 )
return;
if ( ! F_91 ( V_2 ) )
return;
if ( V_2 -> V_5 . V_597 )
return;
if ( ! V_2 -> V_5 . V_649 -> V_704 )
V_1087 = F_552 ( V_2 ) ;
else
V_1087 = - 1 ;
if ( V_1087 != - 1 )
V_1087 >>= 4 ;
V_1088 = F_94 ( V_2 ) ;
V_87 -> F_272 ( V_2 , V_1088 , V_1087 ) ;
}
static int F_553 ( struct V_1 * V_2 , bool V_1089 )
{
int V_121 ;
if ( V_2 -> V_5 . V_69 . V_70 ) {
F_554 ( V_2 -> V_5 . V_69 . V_18 ,
V_2 -> V_5 . V_69 . V_72 ,
V_2 -> V_5 . V_69 . V_63 ) ;
if ( F_29 ( V_2 -> V_5 . V_69 . V_18 ) == V_61 )
F_494 ( V_2 , F_465 ( V_2 ) |
V_985 ) ;
if ( V_2 -> V_5 . V_69 . V_18 == V_54 &&
( V_2 -> V_5 . V_188 & V_1090 ) ) {
V_2 -> V_5 . V_188 &= ~ V_1090 ;
F_97 ( V_2 ) ;
}
V_87 -> V_1091 ( V_2 , V_2 -> V_5 . V_69 . V_18 ,
V_2 -> V_5 . V_69 . V_72 ,
V_2 -> V_5 . V_69 . V_63 ,
V_2 -> V_5 . V_69 . V_64 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_630 ) {
V_87 -> V_1092 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_625 . V_70 ) {
V_87 -> V_1093 ( V_2 ) ;
return 0 ;
}
if ( F_474 ( V_2 ) && V_87 -> V_1094 ) {
V_121 = V_87 -> V_1094 ( V_2 , V_1089 ) ;
if ( V_121 != 0 )
return V_121 ;
}
if ( V_2 -> V_5 . V_637 && ! F_291 ( V_2 ) ) {
V_2 -> V_5 . V_637 = false ;
F_555 ( V_2 ) ;
} else if ( V_2 -> V_5 . V_631 && V_87 -> V_1095 ( V_2 ) ) {
-- V_2 -> V_5 . V_631 ;
V_2 -> V_5 . V_630 = true ;
V_87 -> V_1092 ( V_2 ) ;
} else if ( F_556 ( V_2 ) ) {
if ( F_474 ( V_2 ) && V_87 -> V_1094 ) {
V_121 = V_87 -> V_1094 ( V_2 , V_1089 ) ;
if ( V_121 != 0 )
return V_121 ;
}
if ( V_87 -> V_1096 ( V_2 ) ) {
F_281 ( V_2 , F_557 ( V_2 ) ,
false ) ;
V_87 -> V_1093 ( V_2 ) ;
}
}
return 0 ;
}
static void F_289 ( struct V_1 * V_2 )
{
unsigned V_915 = 2 ;
if ( V_87 -> V_633 ( V_2 ) || V_2 -> V_5 . V_630 )
V_915 = 1 ;
V_2 -> V_5 . V_631 += F_558 ( & V_2 -> V_5 . V_84 , 0 ) ;
V_2 -> V_5 . V_631 = F_359 ( V_2 -> V_5 . V_631 , V_915 ) ;
F_32 ( V_68 , V_2 ) ;
}
static T_1 F_559 ( struct V_825 * V_827 )
{
T_1 V_15 = 0 ;
V_15 |= V_827 -> V_914 << 23 ;
V_15 |= V_827 -> V_183 << 22 ;
V_15 |= V_827 -> V_920 << 21 ;
V_15 |= V_827 -> V_919 << 20 ;
V_15 |= V_827 -> V_918 << 15 ;
V_15 |= V_827 -> V_916 << 13 ;
V_15 |= V_827 -> V_595 << 12 ;
V_15 |= V_827 -> type << 8 ;
return V_15 ;
}
static void F_560 ( struct V_1 * V_2 , char * V_1097 , int V_492 )
{
struct V_825 V_827 ;
int V_94 ;
F_367 ( V_2 , & V_827 , V_492 ) ;
F_561 ( T_1 , V_1097 , 0x7fa8 + V_492 * 4 , V_827 . V_909 ) ;
if ( V_492 < 3 )
V_94 = 0x7f84 + V_492 * 12 ;
else
V_94 = 0x7f2c + ( V_492 - 3 ) * 12 ;
F_561 ( T_1 , V_1097 , V_94 + 8 , V_827 . V_230 ) ;
F_561 ( T_1 , V_1097 , V_94 + 4 , V_827 . V_915 ) ;
F_561 ( T_1 , V_1097 , V_94 , F_559 ( & V_827 ) ) ;
}
static void F_562 ( struct V_1 * V_2 , char * V_1097 , int V_492 )
{
struct V_825 V_827 ;
int V_94 ;
V_880 V_15 ;
F_367 ( V_2 , & V_827 , V_492 ) ;
V_94 = 0x7e00 + V_492 * 16 ;
V_15 = F_559 ( & V_827 ) >> 8 ;
F_561 ( V_880 , V_1097 , V_94 , V_827 . V_909 ) ;
F_561 ( V_880 , V_1097 , V_94 + 2 , V_15 ) ;
F_561 ( T_1 , V_1097 , V_94 + 4 , V_827 . V_915 ) ;
F_561 ( T_2 , V_1097 , V_94 + 8 , V_827 . V_230 ) ;
}
static void F_563 ( struct V_1 * V_2 , char * V_1097 )
{
struct V_903 V_904 ;
struct V_825 V_827 ;
unsigned long V_196 ;
int V_3 ;
F_561 ( T_1 , V_1097 , 0x7ffc , F_63 ( V_2 ) ) ;
F_561 ( T_1 , V_1097 , 0x7ff8 , F_61 ( V_2 ) ) ;
F_561 ( T_1 , V_1097 , 0x7ff4 , F_465 ( V_2 ) ) ;
F_561 ( T_1 , V_1097 , 0x7ff0 , F_466 ( V_2 ) ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
F_561 ( T_1 , V_1097 , 0x7fd0 + V_3 * 4 , F_104 ( V_2 , V_3 ) ) ;
F_102 ( V_2 , 6 , & V_196 ) ;
F_561 ( T_1 , V_1097 , 0x7fcc , ( T_1 ) V_196 ) ;
F_102 ( V_2 , 7 , & V_196 ) ;
F_561 ( T_1 , V_1097 , 0x7fc8 , ( T_1 ) V_196 ) ;
F_367 ( V_2 , & V_827 , V_1098 ) ;
F_561 ( T_1 , V_1097 , 0x7fc4 , V_827 . V_909 ) ;
F_561 ( T_1 , V_1097 , 0x7f64 , V_827 . V_230 ) ;
F_561 ( T_1 , V_1097 , 0x7f60 , V_827 . V_915 ) ;
F_561 ( T_1 , V_1097 , 0x7f5c , F_559 ( & V_827 ) ) ;
F_367 ( V_2 , & V_827 , V_1099 ) ;
F_561 ( T_1 , V_1097 , 0x7fc0 , V_827 . V_909 ) ;
F_561 ( T_1 , V_1097 , 0x7f80 , V_827 . V_230 ) ;
F_561 ( T_1 , V_1097 , 0x7f7c , V_827 . V_915 ) ;
F_561 ( T_1 , V_1097 , 0x7f78 , F_559 ( & V_827 ) ) ;
V_87 -> V_905 ( V_2 , & V_904 ) ;
F_561 ( T_1 , V_1097 , 0x7f74 , V_904 . V_79 ) ;
F_561 ( T_1 , V_1097 , 0x7f70 , V_904 . V_493 ) ;
V_87 -> V_906 ( V_2 , & V_904 ) ;
F_561 ( T_1 , V_1097 , 0x7f58 , V_904 . V_79 ) ;
F_561 ( T_1 , V_1097 , 0x7f54 , V_904 . V_493 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_560 ( V_2 , V_1097 , V_3 ) ;
F_561 ( T_1 , V_1097 , 0x7f14 , F_80 ( V_2 ) ) ;
F_561 ( T_1 , V_1097 , 0x7efc , 0x00020000 ) ;
F_561 ( T_1 , V_1097 , 0x7ef8 , V_2 -> V_5 . V_427 ) ;
}
static void F_564 ( struct V_1 * V_2 , char * V_1097 )
{
#ifdef F_64
struct V_903 V_904 ;
struct V_825 V_827 ;
unsigned long V_196 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ )
F_561 ( T_2 , V_1097 , 0x7ff8 - V_3 * 8 , F_104 ( V_2 , V_3 ) ) ;
F_561 ( T_2 , V_1097 , 0x7f78 , F_466 ( V_2 ) ) ;
F_561 ( T_1 , V_1097 , 0x7f70 , F_465 ( V_2 ) ) ;
F_102 ( V_2 , 6 , & V_196 ) ;
F_561 ( T_2 , V_1097 , 0x7f68 , V_196 ) ;
F_102 ( V_2 , 7 , & V_196 ) ;
F_561 ( T_2 , V_1097 , 0x7f60 , V_196 ) ;
F_561 ( T_2 , V_1097 , 0x7f58 , F_63 ( V_2 ) ) ;
F_561 ( T_2 , V_1097 , 0x7f50 , F_61 ( V_2 ) ) ;
F_561 ( T_2 , V_1097 , 0x7f48 , F_80 ( V_2 ) ) ;
F_561 ( T_1 , V_1097 , 0x7f00 , V_2 -> V_5 . V_427 ) ;
F_561 ( T_1 , V_1097 , 0x7efc , 0x00020064 ) ;
F_561 ( T_2 , V_1097 , 0x7ed0 , V_2 -> V_5 . V_132 ) ;
F_367 ( V_2 , & V_827 , V_1098 ) ;
F_561 ( V_880 , V_1097 , 0x7e90 , V_827 . V_909 ) ;
F_561 ( V_880 , V_1097 , 0x7e92 , F_559 ( & V_827 ) >> 8 ) ;
F_561 ( T_1 , V_1097 , 0x7e94 , V_827 . V_915 ) ;
F_561 ( T_2 , V_1097 , 0x7e98 , V_827 . V_230 ) ;
V_87 -> V_906 ( V_2 , & V_904 ) ;
F_561 ( T_1 , V_1097 , 0x7e84 , V_904 . V_493 ) ;
F_561 ( T_2 , V_1097 , 0x7e88 , V_904 . V_79 ) ;
F_367 ( V_2 , & V_827 , V_1099 ) ;
F_561 ( V_880 , V_1097 , 0x7e70 , V_827 . V_909 ) ;
F_561 ( V_880 , V_1097 , 0x7e72 , F_559 ( & V_827 ) >> 8 ) ;
F_561 ( T_1 , V_1097 , 0x7e74 , V_827 . V_915 ) ;
F_561 ( T_2 , V_1097 , 0x7e78 , V_827 . V_230 ) ;
V_87 -> V_905 ( V_2 , & V_904 ) ;
F_561 ( T_1 , V_1097 , 0x7e64 , V_904 . V_493 ) ;
F_561 ( T_2 , V_1097 , 0x7e68 , V_904 . V_79 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_562 ( V_2 , V_1097 , V_3 ) ;
#else
F_565 ( 1 ) ;
#endif
}
static void F_555 ( struct V_1 * V_2 )
{
struct V_825 V_1100 , V_1101 ;
struct V_903 V_904 ;
char V_1097 [ 512 ] ;
T_1 V_122 ;
F_483 ( V_2 -> V_300 , V_2 -> V_5 . V_427 , true ) ;
V_2 -> V_5 . V_639 |= V_650 ;
memset ( V_1097 , 0 , 512 ) ;
if ( F_566 ( V_2 ) )
F_564 ( V_2 , V_1097 ) ;
else
F_563 ( V_2 , V_1097 ) ;
F_211 ( V_2 , V_2 -> V_5 . V_427 + 0xfe00 , V_1097 , sizeof( V_1097 ) ) ;
if ( V_87 -> V_633 ( V_2 ) )
V_2 -> V_5 . V_639 |= V_640 ;
else
V_87 -> V_648 ( V_2 , true ) ;
F_471 ( V_2 , V_1102 ) ;
F_470 ( V_2 , 0x8000 ) ;
V_122 = V_2 -> V_5 . V_122 & ~ ( V_131 | V_1103 | V_1104 | V_125 ) ;
V_87 -> V_138 ( V_2 , V_122 ) ;
V_2 -> V_5 . V_122 = V_122 ;
V_87 -> V_171 ( V_2 , 0 ) ;
V_904 . V_79 = V_904 . V_493 = 0 ;
V_87 -> V_908 ( V_2 , & V_904 ) ;
F_100 ( V_2 , 7 , V_199 ) ;
V_1100 . V_909 = ( V_2 -> V_5 . V_427 >> 4 ) & 0xffff ;
V_1100 . V_230 = V_2 -> V_5 . V_427 ;
V_1101 . V_909 = 0 ;
V_1101 . V_230 = 0 ;
V_1100 . V_915 = V_1101 . V_915 = 0xffffffff ;
V_1100 . type = V_1101 . type = 0x3 ;
V_1100 . V_916 = V_1101 . V_916 = 0 ;
V_1100 . V_183 = V_1101 . V_183 = 0 ;
V_1100 . V_595 = V_1101 . V_595 = 1 ;
V_1100 . V_920 = V_1101 . V_920 = 0 ;
V_1100 . V_914 = V_1101 . V_914 = 1 ;
V_1100 . V_919 = V_1101 . V_919 = 0 ;
V_1100 . V_918 = V_1101 . V_918 = 1 ;
V_1100 . V_913 = V_1101 . V_913 = 0 ;
V_1100 . V_922 = V_1101 . V_922 = 0 ;
F_366 ( V_2 , & V_1100 , V_1105 ) ;
F_366 ( V_2 , & V_1101 , V_1106 ) ;
F_366 ( V_2 , & V_1101 , V_1107 ) ;
F_366 ( V_2 , & V_1101 , V_1108 ) ;
F_366 ( V_2 , & V_1101 , V_1109 ) ;
F_366 ( V_2 , & V_1101 , V_1110 ) ;
if ( F_566 ( V_2 ) )
V_87 -> F_110 ( V_2 , 0 ) ;
F_77 ( V_2 ) ;
F_67 ( V_2 ) ;
}
static void F_567 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_637 = true ;
F_32 ( V_68 , V_2 ) ;
}
void F_568 ( struct V_139 * V_139 )
{
F_181 ( V_139 , V_1111 ) ;
}
static void F_569 ( struct V_1 * V_2 )
{
T_2 V_1112 [ 4 ] ;
if ( ! F_570 ( V_2 -> V_5 . V_649 ) )
return;
F_571 ( V_2 -> V_5 . V_1113 , 256 ) ;
if ( F_572 ( V_2 -> V_139 ) )
F_573 ( V_2 , V_2 -> V_5 . V_1113 ) ;
else {
if ( V_87 -> V_596 && V_2 -> V_5 . V_597 )
V_87 -> V_596 ( V_2 ) ;
F_574 ( V_2 , V_2 -> V_5 . V_1113 ) ;
}
F_575 ( ( V_176 * ) V_1112 , V_2 -> V_5 . V_1113 ,
F_576 ( V_2 ) -> V_1114 , 256 ) ;
V_87 -> V_1115 ( V_2 , V_1112 ) ;
}
static void F_577 ( struct V_1 * V_2 )
{
++ V_2 -> V_76 . V_1116 ;
V_87 -> V_1116 ( V_2 ) ;
}
void F_578 ( struct V_1 * V_2 )
{
struct V_387 * V_387 = NULL ;
if ( ! F_91 ( V_2 ) )
return;
if ( ! V_87 -> V_1117 )
return;
V_387 = F_579 ( V_2 -> V_139 , V_843 >> V_106 ) ;
if ( F_402 ( V_387 ) )
return;
V_87 -> V_1117 ( V_2 , F_580 ( V_387 ) ) ;
F_581 ( V_387 ) ;
}
void F_582 ( struct V_139 * V_139 ,
unsigned long V_79 )
{
if ( V_79 == F_583 ( V_139 , V_843 >> V_106 ) )
F_181 ( V_139 , V_1118 ) ;
}
static int F_584 ( struct V_1 * V_2 )
{
int V_121 ;
bool V_1089 =
F_550 ( V_2 ) &&
F_273 ( V_2 ) ;
bool V_1119 = false ;
if ( V_2 -> V_341 ) {
if ( F_585 ( V_1120 , V_2 ) )
F_586 ( V_2 ) ;
if ( F_585 ( V_585 , V_2 ) )
F_587 ( V_2 ) ;
if ( F_585 ( V_299 , V_2 ) )
F_182 ( V_2 -> V_139 ) ;
if ( F_585 ( V_433 , V_2 ) )
F_202 ( V_2 ) ;
if ( F_585 ( V_340 , V_2 ) ) {
V_121 = F_196 ( V_2 ) ;
if ( F_171 ( V_121 ) )
goto V_113;
}
if ( F_585 ( V_1121 , V_2 ) )
F_88 ( V_2 ) ;
if ( F_585 ( V_173 , V_2 ) )
F_577 ( V_2 ) ;
if ( F_585 ( V_1122 , V_2 ) ) {
V_2 -> V_851 -> V_869 = V_1123 ;
V_121 = 0 ;
goto V_113;
}
if ( F_585 ( V_73 , V_2 ) ) {
V_2 -> V_851 -> V_869 = V_1124 ;
V_121 = 0 ;
goto V_113;
}
if ( F_585 ( V_1125 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1126 = true ;
V_121 = 1 ;
goto V_113;
}
if ( F_585 ( V_438 , V_2 ) )
F_217 ( V_2 ) ;
if ( F_585 ( V_604 , V_2 ) )
F_567 ( V_2 ) ;
if ( F_585 ( V_85 , V_2 ) )
F_289 ( V_2 ) ;
if ( F_585 ( V_1127 , V_2 ) )
F_588 ( V_2 ) ;
if ( F_585 ( V_1128 , V_2 ) )
F_589 ( V_2 ) ;
if ( F_585 ( V_1129 , V_2 ) ) {
F_15 ( V_2 -> V_5 . V_1130 > 255 ) ;
if ( F_60 ( V_2 -> V_5 . V_1130 ,
V_2 -> V_5 . V_1113 ) ) {
V_2 -> V_851 -> V_869 = V_1131 ;
V_2 -> V_851 -> V_1132 . V_42 =
V_2 -> V_5 . V_1130 ;
V_121 = 0 ;
goto V_113;
}
}
if ( F_585 ( V_1111 , V_2 ) )
F_569 ( V_2 ) ;
if ( F_585 ( V_1118 , V_2 ) )
F_578 ( V_2 ) ;
if ( F_585 ( V_1133 , V_2 ) ) {
V_2 -> V_851 -> V_869 = V_1134 ;
V_2 -> V_851 -> V_1135 . type = V_1136 ;
V_121 = 0 ;
goto V_113;
}
if ( F_585 ( V_1137 , V_2 ) ) {
V_2 -> V_851 -> V_869 = V_1134 ;
V_2 -> V_851 -> V_1135 . type = V_1138 ;
V_121 = 0 ;
goto V_113;
}
if ( F_585 ( V_1139 , V_2 ) ) {
V_2 -> V_851 -> V_869 = V_1140 ;
V_2 -> V_851 -> V_1141 = V_2 -> V_5 . V_1141 . exit ;
V_121 = 0 ;
goto V_113;
}
if ( F_585 ( V_1142 , V_2 ) )
F_590 ( V_2 ) ;
}
if ( F_585 ( V_68 , V_2 ) || V_1089 ) {
++ V_2 -> V_76 . V_1143 ;
F_591 ( V_2 ) ;
if ( V_2 -> V_5 . V_1046 == V_1144 ) {
V_121 = 1 ;
goto V_113;
}
if ( F_553 ( V_2 , V_1089 ) != 0 )
V_1119 = true ;
else {
if ( V_2 -> V_5 . V_637 && ! F_291 ( V_2 ) )
V_1119 = true ;
if ( V_2 -> V_5 . V_631 )
V_87 -> V_1145 ( V_2 ) ;
if ( F_556 ( V_2 ) || V_1089 )
V_87 -> V_1146 ( V_2 ) ;
}
if ( F_592 ( V_2 ) ) {
F_272 ( V_2 ) ;
F_593 ( V_2 ) ;
}
}
V_121 = F_594 ( V_2 ) ;
if ( F_171 ( V_121 ) ) {
goto V_1147;
}
F_453 () ;
V_87 -> V_1148 ( V_2 ) ;
F_454 ( V_2 ) ;
F_353 () ;
V_2 -> V_331 = V_1149 ;
F_241 ( & V_2 -> V_139 -> V_488 , V_2 -> V_1150 ) ;
F_595 () ;
if ( F_592 ( V_2 ) ) {
if ( V_87 -> V_596 && V_2 -> V_5 . V_597 )
V_87 -> V_596 ( V_2 ) ;
}
if ( V_2 -> V_331 == V_1151 || V_2 -> V_341
|| F_596 () || F_597 ( V_402 ) ) {
V_2 -> V_331 = V_1152 ;
F_194 () ;
F_354 () ;
F_456 () ;
V_2 -> V_1150 = F_240 ( & V_2 -> V_139 -> V_488 ) ;
V_121 = 1 ;
goto V_1147;
}
F_73 ( V_2 ) ;
if ( V_1119 ) {
F_32 ( V_68 , V_2 ) ;
F_598 ( V_2 -> V_24 ) ;
}
F_599 ( V_2 -> V_300 ) ;
F_600 ( V_2 ) ;
F_601 () ;
if ( F_171 ( V_2 -> V_5 . V_184 ) ) {
F_602 ( 0 , 7 ) ;
F_602 ( V_2 -> V_5 . V_182 [ 0 ] , 0 ) ;
F_602 ( V_2 -> V_5 . V_182 [ 1 ] , 1 ) ;
F_602 ( V_2 -> V_5 . V_182 [ 2 ] , 2 ) ;
F_602 ( V_2 -> V_5 . V_182 [ 3 ] , 3 ) ;
F_602 ( V_2 -> V_5 . V_187 , 6 ) ;
V_2 -> V_5 . V_184 &= ~ V_185 ;
}
V_87 -> V_851 ( V_2 ) ;
if ( F_171 ( V_2 -> V_5 . V_184 & V_1153 ) ) {
F_30 ( V_2 -> V_179 & V_180 ) ;
V_87 -> V_1154 ( V_2 ) ;
F_95 ( V_2 ) ;
F_96 ( V_2 ) ;
F_97 ( V_2 ) ;
V_2 -> V_5 . V_184 &= ~ V_185 ;
}
if ( F_603 () )
F_604 () ;
V_2 -> V_5 . V_325 = F_152 ( V_2 , F_151 () ) ;
V_2 -> V_331 = V_1152 ;
F_194 () ;
F_75 ( V_2 ) ;
V_87 -> V_1155 ( V_2 ) ;
++ V_2 -> V_76 . V_1156 ;
F_605 () ;
F_354 () ;
F_456 () ;
V_2 -> V_1150 = F_240 ( & V_2 -> V_139 -> V_488 ) ;
if ( F_171 ( V_1157 == V_1158 ) ) {
unsigned long V_1081 = F_466 ( V_2 ) ;
F_606 ( V_1158 , ( void * ) V_1081 ) ;
}
if ( F_171 ( V_2 -> V_5 . V_276 ) )
F_32 ( V_340 , V_2 ) ;
if ( V_2 -> V_5 . V_1159 )
F_607 ( V_2 ) ;
V_121 = V_87 -> V_1160 ( V_2 ) ;
return V_121 ;
V_1147:
V_87 -> V_1147 ( V_2 ) ;
if ( F_171 ( V_2 -> V_5 . V_1159 ) )
F_607 ( V_2 ) ;
V_113:
return V_121 ;
}
static inline int F_608 ( struct V_139 * V_139 , struct V_1 * V_2 )
{
if ( ! F_609 ( V_2 ) &&
( ! V_87 -> V_1161 || V_87 -> V_1161 ( V_2 ) == 0 ) ) {
F_241 ( & V_139 -> V_488 , V_2 -> V_1150 ) ;
F_610 ( V_2 ) ;
V_2 -> V_1150 = F_240 ( & V_139 -> V_488 ) ;
if ( V_87 -> V_1162 )
V_87 -> V_1162 ( V_2 ) ;
if ( ! F_585 ( V_1163 , V_2 ) )
return 1 ;
}
F_591 ( V_2 ) ;
switch( V_2 -> V_5 . V_1046 ) {
case V_1047 :
V_2 -> V_5 . V_1164 . V_1165 = false ;
V_2 -> V_5 . V_1046 =
V_1166 ;
case V_1166 :
V_2 -> V_5 . V_6 . V_1126 = false ;
break;
case V_1144 :
break;
default:
return - V_1167 ;
break;
}
return 1 ;
}
static inline bool F_611 ( struct V_1 * V_2 )
{
if ( F_474 ( V_2 ) && V_87 -> V_1094 )
V_87 -> V_1094 ( V_2 , false ) ;
return ( V_2 -> V_5 . V_1046 == V_1166 &&
! V_2 -> V_5 . V_6 . V_1126 ) ;
}
static int F_612 ( struct V_1 * V_2 )
{
int V_121 ;
struct V_139 * V_139 = V_2 -> V_139 ;
V_2 -> V_1150 = F_240 ( & V_139 -> V_488 ) ;
for (; ; ) {
if ( F_611 ( V_2 ) ) {
V_121 = F_584 ( V_2 ) ;
} else {
V_121 = F_608 ( V_139 , V_2 ) ;
}
if ( V_121 <= 0 )
break;
F_184 ( V_242 , & V_2 -> V_341 ) ;
if ( F_613 ( V_2 ) )
F_614 ( V_2 ) ;
if ( F_550 ( V_2 ) &&
F_275 ( V_2 ) ) {
V_121 = 0 ;
V_2 -> V_851 -> V_869 = V_1168 ;
++ V_2 -> V_76 . V_1169 ;
break;
}
F_615 ( V_2 ) ;
if ( F_597 ( V_402 ) ) {
V_121 = - V_1167 ;
V_2 -> V_851 -> V_869 = V_1170 ;
++ V_2 -> V_76 . V_1171 ;
break;
}
if ( F_596 () ) {
F_241 ( & V_139 -> V_488 , V_2 -> V_1150 ) ;
F_616 () ;
V_2 -> V_1150 = F_240 ( & V_139 -> V_488 ) ;
}
}
F_241 ( & V_139 -> V_488 , V_2 -> V_1150 ) ;
return V_121 ;
}
static inline int F_617 ( struct V_1 * V_2 )
{
int V_121 ;
V_2 -> V_1150 = F_240 ( & V_2 -> V_139 -> V_488 ) ;
V_121 = F_618 ( V_2 , V_989 ) ;
F_241 ( & V_2 -> V_139 -> V_488 , V_2 -> V_1150 ) ;
if ( V_121 != V_954 )
return 0 ;
return 1 ;
}
static int V_1002 ( struct V_1 * V_2 )
{
F_15 ( ! V_2 -> V_5 . V_884 . V_751 ) ;
return F_617 ( V_2 ) ;
}
static int V_1003 ( struct V_1 * V_2 )
{
struct V_974 * V_851 = V_2 -> V_851 ;
struct V_849 * V_850 ;
unsigned V_95 ;
F_15 ( ! V_2 -> V_865 ) ;
V_850 = & V_2 -> V_846 [ V_2 -> V_866 ] ;
V_95 = F_359 ( 8u , V_850 -> V_95 ) ;
if ( ! V_2 -> V_868 )
memcpy ( V_850 -> V_39 , V_851 -> V_852 . V_39 , V_95 ) ;
if ( V_850 -> V_95 <= 8 ) {
V_850 ++ ;
V_2 -> V_866 ++ ;
} else {
V_850 -> V_39 += V_95 ;
V_850 -> V_391 += V_95 ;
V_850 -> V_95 -= V_95 ;
}
if ( V_2 -> V_866 >= V_2 -> V_859 ) {
V_2 -> V_865 = 0 ;
if ( V_2 -> V_868 )
return 1 ;
V_2 -> V_845 = 1 ;
return F_617 ( V_2 ) ;
}
V_851 -> V_869 = V_870 ;
V_851 -> V_852 . V_871 = V_850 -> V_391 ;
if ( V_2 -> V_868 )
memcpy ( V_851 -> V_852 . V_39 , V_850 -> V_39 , F_359 ( 8u , V_850 -> V_95 ) ) ;
V_851 -> V_852 . V_95 = F_359 ( 8u , V_850 -> V_95 ) ;
V_851 -> V_852 . V_867 = V_2 -> V_868 ;
V_2 -> V_5 . V_1001 = V_1003 ;
return 0 ;
}
int F_619 ( struct V_1 * V_2 , struct V_974 * V_974 )
{
struct V_1172 * V_1172 = & V_402 -> V_1173 . V_1172 ;
int V_121 ;
T_17 V_1174 ;
F_620 ( V_1172 ) ;
if ( V_2 -> V_1175 )
F_621 ( V_1176 , & V_2 -> V_1177 , & V_1174 ) ;
if ( F_171 ( V_2 -> V_5 . V_1046 == V_1178 ) ) {
F_610 ( V_2 ) ;
F_591 ( V_2 ) ;
F_184 ( V_1163 , & V_2 -> V_341 ) ;
V_121 = - V_1179 ;
goto V_113;
}
if ( ! F_91 ( V_2 ) ) {
if ( F_90 ( V_2 , V_974 -> V_177 ) != 0 ) {
V_121 = - V_583 ;
goto V_113;
}
}
if ( F_171 ( V_2 -> V_5 . V_1001 ) ) {
int (* F_622)( struct V_1 * ) = V_2 -> V_5 . V_1001 ;
V_2 -> V_5 . V_1001 = NULL ;
V_121 = F_622 ( V_2 ) ;
if ( V_121 <= 0 )
goto V_113;
} else
F_30 ( V_2 -> V_5 . V_884 . V_751 || V_2 -> V_865 ) ;
if ( V_974 -> V_1180 )
V_121 = - V_1167 ;
else
V_121 = F_612 ( V_2 ) ;
V_113:
F_551 ( V_2 ) ;
if ( V_2 -> V_1175 )
F_621 ( V_1176 , & V_1174 , NULL ) ;
return V_121 ;
}
int F_623 ( struct V_1 * V_2 , struct V_1181 * V_1182 )
{
if ( V_2 -> V_5 . V_1005 ) {
F_624 ( & V_2 -> V_5 . V_855 ) ;
V_2 -> V_5 . V_1005 = false ;
}
V_1182 -> V_1183 = F_104 ( V_2 , V_203 ) ;
V_1182 -> V_1184 = F_104 ( V_2 , V_1072 ) ;
V_1182 -> V_1185 = F_104 ( V_2 , V_202 ) ;
V_1182 -> V_1186 = F_104 ( V_2 , V_204 ) ;
V_1182 -> V_1187 = F_104 ( V_2 , V_1073 ) ;
V_1182 -> V_1188 = F_104 ( V_2 , V_1189 ) ;
V_1182 -> V_1190 = F_104 ( V_2 , V_1191 ) ;
V_1182 -> V_1192 = F_104 ( V_2 , V_1193 ) ;
#ifdef F_64
V_1182 -> V_1194 = F_104 ( V_2 , V_1195 ) ;
V_1182 -> V_1196 = F_104 ( V_2 , V_1197 ) ;
V_1182 -> V_1198 = F_104 ( V_2 , V_1199 ) ;
V_1182 -> V_1200 = F_104 ( V_2 , V_1201 ) ;
V_1182 -> V_1202 = F_104 ( V_2 , V_1203 ) ;
V_1182 -> V_1204 = F_104 ( V_2 , V_1205 ) ;
V_1182 -> V_1206 = F_104 ( V_2 , V_1207 ) ;
V_1182 -> V_1208 = F_104 ( V_2 , V_1209 ) ;
#endif
V_1182 -> V_1081 = F_466 ( V_2 ) ;
V_1182 -> V_973 = F_465 ( V_2 ) ;
return 0 ;
}
int F_625 ( struct V_1 * V_2 , struct V_1181 * V_1182 )
{
V_2 -> V_5 . V_948 = true ;
V_2 -> V_5 . V_1005 = false ;
F_106 ( V_2 , V_203 , V_1182 -> V_1183 ) ;
F_106 ( V_2 , V_1072 , V_1182 -> V_1184 ) ;
F_106 ( V_2 , V_202 , V_1182 -> V_1185 ) ;
F_106 ( V_2 , V_204 , V_1182 -> V_1186 ) ;
F_106 ( V_2 , V_1073 , V_1182 -> V_1187 ) ;
F_106 ( V_2 , V_1189 , V_1182 -> V_1188 ) ;
F_106 ( V_2 , V_1191 , V_1182 -> V_1190 ) ;
F_106 ( V_2 , V_1193 , V_1182 -> V_1192 ) ;
#ifdef F_64
F_106 ( V_2 , V_1195 , V_1182 -> V_1194 ) ;
F_106 ( V_2 , V_1197 , V_1182 -> V_1196 ) ;
F_106 ( V_2 , V_1199 , V_1182 -> V_1198 ) ;
F_106 ( V_2 , V_1201 , V_1182 -> V_1200 ) ;
F_106 ( V_2 , V_1203 , V_1182 -> V_1202 ) ;
F_106 ( V_2 , V_1205 , V_1182 -> V_1204 ) ;
F_106 ( V_2 , V_1207 , V_1182 -> V_1206 ) ;
F_106 ( V_2 , V_1209 , V_1182 -> V_1208 ) ;
#endif
F_470 ( V_2 , V_1182 -> V_1081 ) ;
F_471 ( V_2 , V_1182 -> V_973 ) ;
V_2 -> V_5 . V_69 . V_70 = false ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
void F_626 ( struct V_1 * V_2 , int * V_183 , int * V_920 )
{
struct V_825 V_1100 ;
F_367 ( V_2 , & V_1100 , V_1105 ) ;
* V_183 = V_1100 . V_183 ;
* V_920 = V_1100 . V_920 ;
}
int F_627 ( struct V_1 * V_2 ,
struct V_1210 * V_1211 )
{
struct V_903 V_904 ;
F_367 ( V_2 , & V_1211 -> V_1100 , V_1105 ) ;
F_367 ( V_2 , & V_1211 -> V_1101 , V_1106 ) ;
F_367 ( V_2 , & V_1211 -> V_1212 , V_1107 ) ;
F_367 ( V_2 , & V_1211 -> V_1213 , V_1108 ) ;
F_367 ( V_2 , & V_1211 -> V_1214 , V_1109 ) ;
F_367 ( V_2 , & V_1211 -> V_1215 , V_1110 ) ;
F_367 ( V_2 , & V_1211 -> V_1216 , V_1098 ) ;
F_367 ( V_2 , & V_1211 -> V_1217 , V_1099 ) ;
V_87 -> V_906 ( V_2 , & V_904 ) ;
V_1211 -> V_1218 . V_915 = V_904 . V_493 ;
V_1211 -> V_1218 . V_230 = V_904 . V_79 ;
V_87 -> V_905 ( V_2 , & V_904 ) ;
V_1211 -> V_1219 . V_915 = V_904 . V_493 ;
V_1211 -> V_1219 . V_230 = V_904 . V_79 ;
V_1211 -> V_122 = F_63 ( V_2 ) ;
V_1211 -> V_78 = V_2 -> V_5 . V_78 ;
V_1211 -> V_104 = F_61 ( V_2 ) ;
V_1211 -> V_159 = F_80 ( V_2 ) ;
V_1211 -> V_177 = F_93 ( V_2 ) ;
V_1211 -> V_132 = V_2 -> V_5 . V_132 ;
V_1211 -> V_32 = F_21 ( V_2 ) ;
memset ( V_1211 -> V_1220 , 0 , sizeof V_1211 -> V_1220 ) ;
if ( V_2 -> V_5 . V_625 . V_70 && ! V_2 -> V_5 . V_625 . V_626 )
F_223 ( V_2 -> V_5 . V_625 . V_18 ,
( unsigned long * ) V_1211 -> V_1220 ) ;
return 0 ;
}
int F_628 ( struct V_1 * V_2 ,
struct V_1221 * V_1046 )
{
F_591 ( V_2 ) ;
if ( V_2 -> V_5 . V_1046 == V_1047 &&
V_2 -> V_5 . V_1164 . V_1165 )
V_1046 -> V_1046 = V_1166 ;
else
V_1046 -> V_1046 = V_2 -> V_5 . V_1046 ;
return 0 ;
}
int F_629 ( struct V_1 * V_2 ,
struct V_1221 * V_1046 )
{
if ( ! F_91 ( V_2 ) &&
V_1046 -> V_1046 != V_1166 )
return - V_583 ;
if ( V_1046 -> V_1046 == V_1222 ) {
V_2 -> V_5 . V_1046 = V_1144 ;
F_223 ( V_1223 , & V_2 -> V_5 . V_649 -> V_652 ) ;
} else
V_2 -> V_5 . V_1046 = V_1046 -> V_1046 ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
int F_630 ( struct V_1 * V_2 , V_880 V_1224 , int V_1225 ,
int V_1226 , bool V_72 , T_1 V_63 )
{
struct V_839 * V_840 = & V_2 -> V_5 . V_855 ;
int V_108 ;
F_464 ( V_2 ) ;
V_108 = F_631 ( V_840 , V_1224 , V_1225 , V_1226 ,
V_72 , V_63 ) ;
if ( V_108 )
return V_953 ;
F_470 ( V_2 , V_840 -> V_937 ) ;
F_471 ( V_2 , V_840 -> V_936 ) ;
F_32 ( V_68 , V_2 ) ;
return V_954 ;
}
int F_632 ( struct V_1 * V_2 ,
struct V_1210 * V_1211 )
{
struct V_33 V_1227 ;
int V_1228 = 0 ;
int V_1229 , V_1230 , V_487 ;
struct V_903 V_904 ;
if ( ! F_81 ( V_2 ) && ( V_1211 -> V_159 & V_142 ) )
return - V_583 ;
V_904 . V_493 = V_1211 -> V_1218 . V_915 ;
V_904 . V_79 = V_1211 -> V_1218 . V_230 ;
V_87 -> V_908 ( V_2 , & V_904 ) ;
V_904 . V_493 = V_1211 -> V_1219 . V_915 ;
V_904 . V_79 = V_1211 -> V_1219 . V_230 ;
V_87 -> V_907 ( V_2 , & V_904 ) ;
V_2 -> V_5 . V_78 = V_1211 -> V_78 ;
V_1228 |= F_61 ( V_2 ) != V_1211 -> V_104 ;
V_2 -> V_5 . V_104 = V_1211 -> V_104 ;
F_56 ( V_175 , ( V_176 * ) & V_2 -> V_5 . V_118 ) ;
F_90 ( V_2 , V_1211 -> V_177 ) ;
V_1228 |= V_2 -> V_5 . V_132 != V_1211 -> V_132 ;
V_87 -> F_110 ( V_2 , V_1211 -> V_132 ) ;
V_1227 . V_39 = V_1211 -> V_32 ;
V_1227 . V_41 = true ;
F_22 ( V_2 , & V_1227 ) ;
V_1228 |= F_63 ( V_2 ) != V_1211 -> V_122 ;
V_87 -> V_138 ( V_2 , V_1211 -> V_122 ) ;
V_2 -> V_5 . V_122 = V_1211 -> V_122 ;
V_1228 |= F_80 ( V_2 ) != V_1211 -> V_159 ;
V_87 -> V_171 ( V_2 , V_1211 -> V_159 ) ;
if ( V_1211 -> V_159 & ( V_142 | V_167 ) )
F_77 ( V_2 ) ;
V_487 = F_240 ( & V_2 -> V_139 -> V_488 ) ;
if ( ! F_58 ( V_2 ) && F_59 ( V_2 ) ) {
F_54 ( V_2 , V_2 -> V_5 . V_103 , F_61 ( V_2 ) ) ;
V_1228 = 1 ;
}
F_241 ( & V_2 -> V_139 -> V_488 , V_487 ) ;
if ( V_1228 )
F_67 ( V_2 ) ;
V_1230 = V_600 ;
V_1229 = F_633 (
( const unsigned long * ) V_1211 -> V_1220 , V_1230 ) ;
if ( V_1229 < V_1230 ) {
F_281 ( V_2 , V_1229 , false ) ;
F_133 ( L_28 , V_1229 ) ;
}
F_366 ( V_2 , & V_1211 -> V_1100 , V_1105 ) ;
F_366 ( V_2 , & V_1211 -> V_1101 , V_1106 ) ;
F_366 ( V_2 , & V_1211 -> V_1212 , V_1107 ) ;
F_366 ( V_2 , & V_1211 -> V_1213 , V_1108 ) ;
F_366 ( V_2 , & V_1211 -> V_1214 , V_1109 ) ;
F_366 ( V_2 , & V_1211 -> V_1215 , V_1110 ) ;
F_366 ( V_2 , & V_1211 -> V_1216 , V_1098 ) ;
F_366 ( V_2 , & V_1211 -> V_1217 , V_1099 ) ;
F_272 ( V_2 ) ;
if ( F_634 ( V_2 ) && F_466 ( V_2 ) == 0xfff0 &&
V_1211 -> V_1100 . V_909 == 0xf000 && V_1211 -> V_1100 . V_230 == 0xffff0000 &&
! F_33 ( V_2 ) )
V_2 -> V_5 . V_1046 = V_1166 ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
int F_635 ( struct V_1 * V_2 ,
struct V_1231 * V_1232 )
{
unsigned long V_973 ;
int V_3 , V_121 ;
if ( V_1232 -> V_758 & ( V_1233 | V_1234 ) ) {
V_121 = - V_806 ;
if ( V_2 -> V_5 . V_69 . V_70 )
goto V_113;
if ( V_1232 -> V_758 & V_1233 )
F_34 ( V_2 , V_54 ) ;
else
F_34 ( V_2 , V_55 ) ;
}
V_973 = F_465 ( V_2 ) ;
V_2 -> V_179 = V_1232 -> V_758 ;
if ( ! ( V_2 -> V_179 & V_1235 ) )
V_2 -> V_179 = 0 ;
if ( V_2 -> V_179 & V_180 ) {
for ( V_3 = 0 ; V_3 < V_181 ; ++ V_3 )
V_2 -> V_5 . V_182 [ V_3 ] = V_1232 -> V_5 . V_1236 [ V_3 ] ;
V_2 -> V_5 . V_189 = V_1232 -> V_5 . V_1236 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_181 ; V_3 ++ )
V_2 -> V_5 . V_182 [ V_3 ] = V_2 -> V_5 . V_183 [ V_3 ] ;
}
F_97 ( V_2 ) ;
if ( V_2 -> V_179 & V_976 )
V_2 -> V_5 . V_980 = F_466 ( V_2 ) +
F_416 ( V_2 , V_1105 ) ;
F_471 ( V_2 , V_973 ) ;
V_87 -> V_1237 ( V_2 ) ;
V_121 = 0 ;
V_113:
return V_121 ;
}
int F_636 ( struct V_1 * V_2 ,
struct V_1238 * V_1216 )
{
unsigned long V_1239 = V_1216 -> V_1240 ;
T_6 V_391 ;
int V_487 ;
V_487 = F_240 ( & V_2 -> V_139 -> V_488 ) ;
V_391 = F_372 ( V_2 , V_1239 , NULL ) ;
F_241 ( & V_2 -> V_139 -> V_488 , V_487 ) ;
V_1216 -> V_1241 = V_391 ;
V_1216 -> V_663 = V_391 != V_100 ;
V_1216 -> V_1242 = 1 ;
V_1216 -> V_1243 = 0 ;
return 0 ;
}
int F_637 ( struct V_1 * V_2 , struct V_1244 * V_1172 )
{
struct V_676 * V_675 =
& V_2 -> V_5 . V_658 . V_659 . V_675 ;
memcpy ( V_1172 -> V_1245 , V_675 -> V_1246 , 128 ) ;
V_1172 -> V_1247 = V_675 -> V_1248 ;
V_1172 -> V_1249 = V_675 -> V_1250 ;
V_1172 -> V_1251 = V_675 -> V_1252 ;
V_1172 -> V_1253 = V_675 -> V_1254 ;
V_1172 -> V_1255 = V_675 -> V_1081 ;
V_1172 -> V_1256 = V_675 -> V_1257 ;
memcpy ( V_1172 -> V_1258 , V_675 -> V_1259 , sizeof V_675 -> V_1259 ) ;
return 0 ;
}
int F_638 ( struct V_1 * V_2 , struct V_1244 * V_1172 )
{
struct V_676 * V_675 =
& V_2 -> V_5 . V_658 . V_659 . V_675 ;
memcpy ( V_675 -> V_1246 , V_1172 -> V_1245 , 128 ) ;
V_675 -> V_1248 = V_1172 -> V_1247 ;
V_675 -> V_1250 = V_1172 -> V_1249 ;
V_675 -> V_1252 = V_1172 -> V_1251 ;
V_675 -> V_1254 = V_1172 -> V_1253 ;
V_675 -> V_1081 = V_1172 -> V_1255 ;
V_675 -> V_1257 = V_1172 -> V_1256 ;
memcpy ( V_675 -> V_1259 , V_1172 -> V_1258 , sizeof V_675 -> V_1259 ) ;
return 0 ;
}
static void F_639 ( struct V_1 * V_2 )
{
F_640 ( & V_2 -> V_5 . V_658 . V_659 ) ;
if ( F_248 ( V_669 ) )
V_2 -> V_5 . V_658 . V_659 . V_657 . V_661 . V_670 =
V_146 | V_671 ;
V_2 -> V_5 . V_145 = V_151 ;
V_2 -> V_5 . V_122 |= V_127 ;
}
void F_454 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1260 )
return;
V_2 -> V_1260 = 1 ;
F_641 () ;
F_642 ( & V_2 -> V_5 . V_658 . V_659 ) ;
F_643 ( 1 ) ;
}
void F_267 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_1260 )
return;
V_2 -> V_1260 = 0 ;
F_644 ( & V_2 -> V_5 . V_658 ) ;
F_645 () ;
++ V_2 -> V_76 . V_1261 ;
F_643 ( 0 ) ;
}
void F_646 ( struct V_1 * V_2 )
{
void * V_587 = V_2 -> V_5 . V_587 ;
F_216 ( V_2 ) ;
V_87 -> V_1262 ( V_2 ) ;
F_647 ( V_587 ) ;
}
struct V_1 * F_648 ( struct V_139 * V_139 ,
unsigned int V_1263 )
{
struct V_1 * V_2 ;
if ( F_157 () && F_144 ( & V_139 -> V_296 ) != 0 )
F_410 ( V_882
L_29
L_30 ) ;
V_2 = V_87 -> V_1264 ( V_139 , V_1263 ) ;
return V_2 ;
}
int F_649 ( struct V_1 * V_2 )
{
int V_121 ;
F_650 ( V_2 ) ;
V_121 = V_588 ( V_2 ) ;
if ( V_121 )
return V_121 ;
F_651 ( V_2 , false ) ;
F_652 ( V_2 ) ;
V_593 ( V_2 ) ;
return V_121 ;
}
void F_653 ( struct V_1 * V_2 )
{
struct V_33 V_22 ;
struct V_139 * V_139 = V_2 -> V_139 ;
if ( V_588 ( V_2 ) )
return;
V_22 . V_39 = 0x0 ;
V_22 . V_147 = V_1265 ;
V_22 . V_41 = true ;
F_154 ( V_2 , & V_22 ) ;
V_593 ( V_2 ) ;
if ( ! V_366 )
return;
F_203 ( & V_139 -> V_5 . V_365 ,
V_367 ) ;
}
void F_654 ( struct V_1 * V_2 )
{
int V_121 ;
V_2 -> V_5 . V_6 . V_392 = 0 ;
V_121 = V_588 ( V_2 ) ;
F_15 ( V_121 ) ;
F_586 ( V_2 ) ;
V_593 ( V_2 ) ;
V_87 -> V_1262 ( V_2 ) ;
}
void F_651 ( struct V_1 * V_2 , bool V_1266 )
{
V_2 -> V_5 . V_639 = 0 ;
V_2 -> V_5 . V_637 = 0 ;
F_178 ( & V_2 -> V_5 . V_84 , 0 ) ;
V_2 -> V_5 . V_631 = 0 ;
V_2 -> V_5 . V_630 = false ;
F_655 ( V_2 ) ;
F_489 ( V_2 ) ;
memset ( V_2 -> V_5 . V_183 , 0 , sizeof( V_2 -> V_5 . V_183 ) ) ;
F_95 ( V_2 ) ;
V_2 -> V_5 . V_187 = V_1267 ;
F_96 ( V_2 ) ;
V_2 -> V_5 . V_188 = V_199 ;
F_97 ( V_2 ) ;
V_2 -> V_5 . V_78 = 0 ;
F_32 ( V_68 , V_2 ) ;
V_2 -> V_5 . V_6 . V_392 = 0 ;
V_2 -> V_5 . V_396 . V_392 = 0 ;
F_216 ( V_2 ) ;
F_66 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1126 = false ;
if ( ! V_1266 ) {
F_656 ( V_2 ) ;
V_2 -> V_5 . V_427 = 0x30000 ;
}
memset ( V_2 -> V_5 . V_1182 , 0 , sizeof( V_2 -> V_5 . V_1182 ) ) ;
V_2 -> V_5 . V_118 = ~ 0 ;
V_2 -> V_5 . V_119 = ~ 0 ;
V_87 -> V_1268 ( V_2 , V_1266 ) ;
}
void F_657 ( struct V_1 * V_2 , T_13 V_42 )
{
struct V_825 V_1100 ;
F_367 ( V_2 , & V_1100 , V_1105 ) ;
V_1100 . V_909 = V_42 << 8 ;
V_1100 . V_230 = V_42 << 12 ;
F_366 ( V_2 , & V_1100 , V_1105 ) ;
F_470 ( V_2 , 0 ) ;
}
int F_658 ( void )
{
struct V_139 * V_139 ;
struct V_1 * V_2 ;
int V_3 ;
int V_108 ;
T_2 V_1269 ;
T_2 V_1270 = 0 ;
bool V_1271 , V_1272 = false ;
F_16 () ;
V_108 = V_87 -> V_1273 () ;
if ( V_108 != 0 )
return V_108 ;
V_1269 = F_151 () ;
V_1271 = ! F_157 () ;
F_504 (kvm, &vm_list, vm_list) {
F_183 (i, vcpu, kvm) {
if ( ! V_1271 && V_2 -> V_24 == F_10 () )
F_32 ( V_340 , V_2 ) ;
if ( V_1271 && V_2 -> V_5 . V_591 > V_1269 ) {
V_1272 = true ;
if ( V_2 -> V_5 . V_591 > V_1270 )
V_1270 = V_2 -> V_5 . V_591 ;
}
}
}
if ( V_1272 ) {
T_2 V_1274 = V_1270 - V_1269 ;
V_336 = true ;
F_504 (kvm, &vm_list, vm_list) {
F_183 (i, vcpu, kvm) {
V_2 -> V_5 . V_589 += V_1274 ;
V_2 -> V_5 . V_591 = V_1269 ;
F_32 ( V_299 , V_2 ) ;
}
V_139 -> V_5 . V_314 = 0 ;
V_139 -> V_5 . V_316 = 0 ;
}
}
return 0 ;
}
void F_659 ( void )
{
V_87 -> V_1275 () ;
F_20 () ;
}
int F_660 ( void )
{
int V_121 ;
V_121 = V_87 -> V_1276 () ;
if ( V_121 != 0 )
return V_121 ;
if ( V_273 ) {
T_2 V_1277 = F_359 ( 0x7fffffffULL ,
F_147 ( V_278 , V_274 ) ) ;
V_716 = V_1277 ;
V_272 = 1ULL << V_277 ;
}
F_356 () ;
return 0 ;
}
void F_661 ( void )
{
V_87 -> V_1278 () ;
}
void F_662 ( void * V_1279 )
{
V_87 -> V_1280 ( V_1279 ) ;
}
bool F_663 ( struct V_1 * V_2 )
{
return V_2 -> V_139 -> V_5 . V_807 == V_2 -> V_300 ;
}
bool F_634 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_32 & V_1281 ) != 0 ;
}
int F_664 ( struct V_1 * V_2 )
{
struct V_387 * V_387 ;
struct V_139 * V_139 ;
int V_121 ;
F_15 ( V_2 -> V_139 == NULL ) ;
V_139 = V_2 -> V_139 ;
V_2 -> V_5 . V_597 = V_87 -> V_1282 () ;
V_2 -> V_5 . V_1164 . V_1165 = false ;
V_2 -> V_5 . V_855 . V_854 = & V_1283 ;
if ( ! F_280 ( V_139 ) || F_663 ( V_2 ) )
V_2 -> V_5 . V_1046 = V_1166 ;
else
V_2 -> V_5 . V_1046 = V_1178 ;
V_387 = F_665 ( V_689 | V_1284 ) ;
if ( ! V_387 ) {
V_121 = - V_389 ;
goto V_1285;
}
V_2 -> V_5 . V_888 = F_666 ( V_387 ) ;
F_140 ( V_2 , V_1016 ) ;
V_121 = F_667 ( V_2 ) ;
if ( V_121 < 0 )
goto V_1286;
if ( F_280 ( V_139 ) ) {
V_121 = F_668 ( V_2 ) ;
if ( V_121 < 0 )
goto V_1287;
} else
F_669 ( & V_1288 ) ;
V_2 -> V_5 . V_376 = F_311 ( V_440 * sizeof( T_2 ) * 4 ,
V_689 ) ;
if ( ! V_2 -> V_5 . V_376 ) {
V_121 = - V_389 ;
goto V_1289;
}
V_2 -> V_5 . V_368 = V_440 ;
if ( ! F_670 ( & V_2 -> V_5 . V_587 , V_689 ) ) {
V_121 = - V_389 ;
goto V_1290;
}
F_639 ( V_2 ) ;
V_2 -> V_5 . V_303 = 0x0 ;
V_2 -> V_5 . V_358 = false ;
V_2 -> V_5 . V_154 = 0 ;
V_2 -> V_5 . V_1291 = V_1292 + V_664 ;
V_2 -> V_5 . V_1027 = F_671 ( V_2 ) ;
V_2 -> V_5 . V_1293 = V_1294 ;
F_1 ( V_2 ) ;
F_672 ( V_2 ) ;
V_2 -> V_5 . V_602 = - 1 ;
F_673 ( V_2 ) ;
return 0 ;
V_1290:
F_212 ( V_2 -> V_5 . V_376 ) ;
V_1289:
F_674 ( V_2 ) ;
V_1287:
F_675 ( V_2 ) ;
V_1286:
F_676 ( ( unsigned long ) V_2 -> V_5 . V_888 ) ;
V_1285:
return V_121 ;
}
void F_677 ( struct V_1 * V_2 )
{
int V_487 ;
F_678 ( V_2 ) ;
F_679 ( V_2 ) ;
F_212 ( V_2 -> V_5 . V_376 ) ;
F_674 ( V_2 ) ;
V_487 = F_240 ( & V_2 -> V_139 -> V_488 ) ;
F_675 ( V_2 ) ;
F_241 ( & V_2 -> V_139 -> V_488 , V_487 ) ;
F_676 ( ( unsigned long ) V_2 -> V_5 . V_888 ) ;
if ( ! F_91 ( V_2 ) )
F_680 ( & V_1288 ) ;
}
void F_681 ( struct V_1 * V_2 , int V_24 )
{
V_87 -> V_1295 ( V_2 , V_24 ) ;
}
int F_682 ( struct V_139 * V_139 , unsigned long type )
{
if ( type )
return - V_583 ;
F_683 ( & V_139 -> V_5 . V_1296 ) ;
F_684 ( & V_139 -> V_5 . V_1297 ) ;
F_684 ( & V_139 -> V_5 . V_1298 ) ;
F_684 ( & V_139 -> V_5 . V_1299 ) ;
F_178 ( & V_139 -> V_5 . V_1300 , 0 ) ;
F_223 ( V_766 , & V_139 -> V_5 . V_1301 ) ;
F_223 ( V_1302 ,
& V_139 -> V_5 . V_1301 ) ;
F_685 ( & V_139 -> V_5 . V_313 ) ;
F_686 ( & V_139 -> V_5 . V_1303 ) ;
F_686 ( & V_139 -> V_5 . V_1141 . V_1304 ) ;
F_687 ( & V_139 -> V_5 . V_326 ) ;
V_139 -> V_5 . V_249 = - F_156 () ;
F_177 ( V_139 ) ;
F_688 ( & V_139 -> V_5 . V_363 , F_199 ) ;
F_688 ( & V_139 -> V_5 . V_365 , F_204 ) ;
F_689 ( V_139 ) ;
F_690 ( V_139 ) ;
if ( V_87 -> V_1305 )
return V_87 -> V_1305 ( V_139 ) ;
return 0 ;
}
static void F_691 ( struct V_1 * V_2 )
{
int V_121 ;
V_121 = V_588 ( V_2 ) ;
F_15 ( V_121 ) ;
F_586 ( V_2 ) ;
V_593 ( V_2 ) ;
}
static void F_692 ( struct V_139 * V_139 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_183 (i, vcpu, kvm) {
F_66 ( V_2 ) ;
F_691 ( V_2 ) ;
}
F_183 (i, vcpu, kvm)
F_646 ( V_2 ) ;
F_320 ( & V_139 -> V_741 ) ;
for ( V_3 = 0 ; V_3 < F_144 ( & V_139 -> V_296 ) ; V_3 ++ )
V_139 -> V_1306 [ V_3 ] = NULL ;
F_178 ( & V_139 -> V_296 , 0 ) ;
F_322 ( & V_139 -> V_741 ) ;
}
void F_693 ( struct V_139 * V_139 )
{
F_694 ( & V_139 -> V_5 . V_365 ) ;
F_694 ( & V_139 -> V_5 . V_363 ) ;
F_695 ( V_139 ) ;
F_696 ( V_139 ) ;
}
int F_697 ( struct V_139 * V_139 , int V_1263 , T_6 V_391 , T_1 V_493 )
{
int V_3 , V_121 ;
unsigned long V_1307 ;
struct V_1308 * V_1309 = V_1308 ( V_139 ) ;
struct V_1310 * V_10 , V_875 ;
if ( F_30 ( V_1263 >= V_1311 ) )
return - V_583 ;
V_10 = F_698 ( V_1309 , V_1263 ) ;
if ( V_493 ) {
if ( V_10 -> V_1312 )
return - V_603 ;
V_1307 = F_699 ( NULL , 0 , V_493 , V_1313 | V_1314 ,
V_1315 | V_1316 , 0 ) ;
if ( F_209 ( ( void * ) V_1307 ) )
return F_210 ( ( void * ) V_1307 ) ;
} else {
if ( ! V_10 -> V_1312 )
return 0 ;
V_1307 = 0 ;
}
V_875 = * V_10 ;
for ( V_3 = 0 ; V_3 < V_1317 ; V_3 ++ ) {
struct V_1318 V_1319 ;
V_1319 . V_10 = V_1263 | ( V_3 << 16 ) ;
V_1319 . V_15 = 0 ;
V_1319 . V_1320 = V_391 ;
V_1319 . V_1321 = V_1307 ;
V_1319 . V_1322 = V_493 ;
V_121 = F_700 ( V_139 , & V_1319 ) ;
if ( V_121 < 0 )
return V_121 ;
}
if ( ! V_493 ) {
V_121 = F_701 ( V_875 . V_1321 , V_875 . V_1312 * V_107 ) ;
F_30 ( V_121 < 0 ) ;
}
return 0 ;
}
int F_702 ( struct V_139 * V_139 , int V_1263 , T_6 V_391 , T_1 V_493 )
{
int V_121 ;
F_320 ( & V_139 -> V_728 ) ;
V_121 = F_697 ( V_139 , V_1263 , V_391 , V_493 ) ;
F_322 ( & V_139 -> V_728 ) ;
return V_121 ;
}
void F_703 ( struct V_139 * V_139 )
{
if ( V_402 -> V_1323 == V_139 -> V_1323 ) {
F_702 ( V_139 , V_1324 , 0 , 0 ) ;
F_702 ( V_139 , V_1325 , 0 , 0 ) ;
F_702 ( V_139 , V_1326 , 0 , 0 ) ;
}
if ( V_87 -> V_1327 )
V_87 -> V_1327 ( V_139 ) ;
F_704 ( V_139 ) ;
F_348 ( V_139 ) ;
F_350 ( V_139 ) ;
F_692 ( V_139 ) ;
F_705 ( F_706 ( V_139 -> V_5 . V_1328 , 1 ) ) ;
F_707 ( V_139 ) ;
F_708 ( V_139 ) ;
}
void F_709 ( struct V_139 * V_139 , struct V_1310 * free ,
struct V_1310 * V_1329 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1330 ; ++ V_3 ) {
if ( ! V_1329 || free -> V_5 . V_1331 [ V_3 ] != V_1329 -> V_5 . V_1331 [ V_3 ] ) {
F_705 ( free -> V_5 . V_1331 [ V_3 ] ) ;
free -> V_5 . V_1331 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1329 || free -> V_5 . V_1332 [ V_3 - 1 ] !=
V_1329 -> V_5 . V_1332 [ V_3 - 1 ] ) {
F_705 ( free -> V_5 . V_1332 [ V_3 - 1 ] ) ;
free -> V_5 . V_1332 [ V_3 - 1 ] = NULL ;
}
}
F_710 ( free , V_1329 ) ;
}
int F_711 ( struct V_139 * V_139 , struct V_1310 * V_10 ,
unsigned long V_1312 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1330 ; ++ V_3 ) {
struct V_1333 * V_1334 ;
unsigned long V_1335 ;
int V_1336 ;
int V_767 = V_3 + 1 ;
V_1336 = F_712 ( V_10 -> V_1337 + V_1312 - 1 ,
V_10 -> V_1337 , V_767 ) + 1 ;
V_10 -> V_5 . V_1331 [ V_3 ] =
F_713 ( V_1336 * sizeof( * V_10 -> V_5 . V_1331 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1331 [ V_3 ] )
goto V_390;
if ( V_3 == 0 )
continue;
V_1334 = F_713 ( V_1336 * sizeof( * V_1334 ) ) ;
if ( ! V_1334 )
goto V_390;
V_10 -> V_5 . V_1332 [ V_3 - 1 ] = V_1334 ;
if ( V_10 -> V_1337 & ( F_714 ( V_767 ) - 1 ) )
V_1334 [ 0 ] . V_1338 = 1 ;
if ( ( V_10 -> V_1337 + V_1312 ) & ( F_714 ( V_767 ) - 1 ) )
V_1334 [ V_1336 - 1 ] . V_1338 = 1 ;
V_1335 = V_10 -> V_1321 >> V_106 ;
if ( ( V_10 -> V_1337 ^ V_1335 ) & ( F_714 ( V_767 ) - 1 ) ||
! F_715 () ) {
unsigned long V_816 ;
for ( V_816 = 0 ; V_816 < V_1336 ; ++ V_816 )
V_1334 [ V_816 ] . V_1338 = 1 ;
}
}
if ( F_716 ( V_10 , V_1312 ) )
goto V_390;
return 0 ;
V_390:
for ( V_3 = 0 ; V_3 < V_1330 ; ++ V_3 ) {
F_705 ( V_10 -> V_5 . V_1331 [ V_3 ] ) ;
V_10 -> V_5 . V_1331 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_705 ( V_10 -> V_5 . V_1332 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1332 [ V_3 - 1 ] = NULL ;
}
return - V_389 ;
}
void F_717 ( struct V_139 * V_139 , struct V_1308 * V_1309 )
{
F_718 ( V_139 , V_1309 ) ;
}
int F_719 ( struct V_139 * V_139 ,
struct V_1310 * V_1339 ,
const struct V_1318 * V_1340 ,
enum V_1341 V_1342 )
{
return 0 ;
}
static void F_720 ( struct V_139 * V_139 ,
struct V_1310 * V_876 )
{
if ( V_876 -> V_15 & V_1343 ) {
F_721 ( V_139 , V_876 ) ;
return;
}
if ( V_876 -> V_15 & V_1344 ) {
if ( V_87 -> V_1345 )
V_87 -> V_1345 ( V_139 , V_876 ) ;
else
F_721 ( V_139 , V_876 ) ;
} else {
if ( V_87 -> V_1346 )
V_87 -> V_1346 ( V_139 , V_876 ) ;
}
}
void F_722 ( struct V_139 * V_139 ,
const struct V_1318 * V_1340 ,
const struct V_1310 * V_875 ,
const struct V_1310 * V_876 ,
enum V_1341 V_1342 )
{
int V_1347 = 0 ;
if ( ! V_139 -> V_5 . V_729 )
V_1347 = F_723 ( V_139 ) ;
if ( V_1347 )
F_321 ( V_139 , V_1347 ) ;
if ( ( V_1342 != V_1348 ) &&
( V_875 -> V_15 & V_1344 ) &&
! ( V_876 -> V_15 & V_1344 ) )
F_724 ( V_139 , V_876 ) ;
if ( V_1342 != V_1348 )
F_720 ( V_139 , (struct V_1310 * ) V_876 ) ;
}
void F_725 ( struct V_139 * V_139 )
{
F_726 ( V_139 ) ;
}
void F_727 ( struct V_139 * V_139 ,
struct V_1310 * V_10 )
{
F_728 ( V_139 , V_10 ) ;
}
static inline bool F_729 ( struct V_1 * V_2 )
{
if ( ! F_730 ( & V_2 -> V_1349 . V_1350 ) )
return true ;
if ( F_731 ( V_2 ) )
return true ;
if ( V_2 -> V_5 . V_1164 . V_1165 )
return true ;
if ( F_144 ( & V_2 -> V_5 . V_84 ) )
return true ;
if ( F_60 ( V_604 , & V_2 -> V_341 ) )
return true ;
if ( F_276 ( V_2 ) &&
F_277 ( V_2 ) )
return true ;
if ( F_732 ( V_2 ) )
return true ;
return false ;
}
int F_609 ( struct V_1 * V_2 )
{
return F_611 ( V_2 ) || F_729 ( V_2 ) ;
}
int F_733 ( struct V_1 * V_2 )
{
return F_734 ( V_2 ) == V_1149 ;
}
int F_276 ( struct V_1 * V_2 )
{
return V_87 -> V_1096 ( V_2 ) ;
}
unsigned long F_487 ( struct V_1 * V_2 )
{
if ( F_548 ( V_2 ) )
return F_466 ( V_2 ) ;
return ( T_1 ) ( F_416 ( V_2 , V_1105 ) +
F_466 ( V_2 ) ) ;
}
bool F_735 ( struct V_1 * V_2 , unsigned long V_1351 )
{
return F_487 ( V_2 ) == V_1351 ;
}
unsigned long F_465 ( struct V_1 * V_2 )
{
unsigned long V_973 ;
V_973 = V_87 -> V_983 ( V_2 ) ;
if ( V_2 -> V_179 & V_976 )
V_973 &= ~ V_975 ;
return V_973 ;
}
static void F_494 ( struct V_1 * V_2 , unsigned long V_973 )
{
if ( V_2 -> V_179 & V_976 &&
F_735 ( V_2 , V_2 -> V_5 . V_980 ) )
V_973 |= V_975 ;
V_87 -> V_1352 ( V_2 , V_973 ) ;
}
void F_471 ( struct V_1 * V_2 , unsigned long V_973 )
{
F_494 ( V_2 , V_973 ) ;
F_32 ( V_68 , V_2 ) ;
}
void F_736 ( struct V_1 * V_2 , struct V_1353 * V_360 )
{
int V_121 ;
if ( ( V_2 -> V_5 . V_83 . V_965 != V_360 -> V_5 . V_965 ) ||
V_360 -> V_1354 )
return;
V_121 = F_594 ( V_2 ) ;
if ( F_171 ( V_121 ) )
return;
if ( ! V_2 -> V_5 . V_83 . V_965 &&
V_360 -> V_5 . V_104 != V_2 -> V_5 . V_83 . V_1355 ( V_2 ) )
return;
V_2 -> V_5 . V_83 . V_1356 ( V_2 , V_360 -> V_832 , 0 , true ) ;
}
static inline T_1 F_737 ( T_5 V_102 )
{
return F_738 ( V_102 & 0xffffffff , F_739 ( V_4 ) ) ;
}
static inline T_1 F_740 ( T_1 V_1357 )
{
return ( V_1357 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_741 ( struct V_1 * V_2 , T_5 V_102 )
{
T_1 V_1357 = F_737 ( V_102 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1357 ] != ~ 0 )
V_1357 = F_740 ( V_1357 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1357 ] = V_102 ;
}
static T_1 F_742 ( struct V_1 * V_2 , T_5 V_102 )
{
int V_3 ;
T_1 V_1357 = F_737 ( V_102 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1357 ] != V_102 &&
V_2 -> V_5 . V_6 . V_7 [ V_1357 ] != ~ 0 ) ; V_3 ++ )
V_1357 = F_740 ( V_1357 ) ;
return V_1357 ;
}
bool F_743 ( struct V_1 * V_2 , T_5 V_102 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_742 ( V_2 , V_102 ) ] == V_102 ;
}
static void F_744 ( struct V_1 * V_2 , T_5 V_102 )
{
T_1 V_3 , V_816 , V_1358 ;
V_3 = V_816 = F_742 ( V_2 , V_102 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_816 = F_740 ( V_816 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_816 ] == ~ 0 )
return;
V_1358 = F_737 ( V_2 -> V_5 . V_6 . V_7 [ V_816 ] ) ;
} while ( ( V_3 <= V_816 ) ? ( V_3 < V_1358 && V_1358 <= V_816 ) : ( V_3 < V_1358 || V_1358 <= V_816 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_816 ] ;
V_3 = V_816 ;
}
}
static int F_745 ( struct V_1 * V_2 , T_1 V_196 )
{
return F_193 ( V_2 , & V_2 -> V_5 . V_6 . V_39 , & V_196 ,
sizeof( V_196 ) ) ;
}
void F_746 ( struct V_1 * V_2 ,
struct V_1353 * V_360 )
{
struct V_74 V_75 ;
F_747 ( V_360 -> V_5 . V_1359 , V_360 -> V_832 ) ;
F_741 ( V_2 , V_360 -> V_5 . V_102 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_392 & V_393 ) ||
( V_2 -> V_5 . V_6 . V_394 &&
V_87 -> V_88 ( V_2 ) == 0 ) )
F_32 ( V_1125 , V_2 ) ;
else if ( ! F_745 ( V_2 , V_1360 ) ) {
V_75 . V_42 = V_43 ;
V_75 . V_935 = true ;
V_75 . V_63 = 0 ;
V_75 . V_80 = false ;
V_75 . V_79 = V_360 -> V_5 . V_1359 ;
F_39 ( V_2 , & V_75 ) ;
}
}
void F_748 ( struct V_1 * V_2 ,
struct V_1353 * V_360 )
{
struct V_74 V_75 ;
if ( V_360 -> V_1354 )
V_360 -> V_5 . V_1359 = ~ 0 ;
else
F_744 ( V_2 , V_360 -> V_5 . V_102 ) ;
F_749 ( V_360 -> V_5 . V_1359 , V_360 -> V_832 ) ;
if ( ( V_2 -> V_5 . V_6 . V_392 & V_393 ) &&
! F_745 ( V_2 , V_1361 ) ) {
V_75 . V_42 = V_43 ;
V_75 . V_935 = true ;
V_75 . V_63 = 0 ;
V_75 . V_80 = false ;
V_75 . V_79 = V_360 -> V_5 . V_1359 ;
F_39 ( V_2 , & V_75 ) ;
}
V_2 -> V_5 . V_6 . V_1126 = false ;
V_2 -> V_5 . V_1046 = V_1166 ;
}
bool F_750 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_392 & V_393 ) )
return true ;
else
return ! F_278 ( V_2 ) &&
V_87 -> V_1096 ( V_2 ) ;
}
void F_751 ( struct V_139 * V_139 )
{
F_44 ( & V_139 -> V_5 . V_1362 ) ;
}
void F_752 ( struct V_139 * V_139 )
{
F_753 ( & V_139 -> V_5 . V_1362 ) ;
}
bool F_754 ( struct V_139 * V_139 )
{
return F_144 ( & V_139 -> V_5 . V_1362 ) ;
}
void F_755 ( struct V_139 * V_139 )
{
F_44 ( & V_139 -> V_5 . V_1300 ) ;
}
void F_756 ( struct V_139 * V_139 )
{
F_753 ( & V_139 -> V_5 . V_1300 ) ;
}
bool F_68 ( struct V_139 * V_139 )
{
return F_144 ( & V_139 -> V_5 . V_1300 ) ;
}
bool F_757 ( void )
{
return V_87 -> V_1363 != NULL ;
}
int F_758 ( struct V_1364 * V_1365 ,
struct V_1366 * V_1367 )
{
struct V_1368 * V_1369 =
F_4 ( V_1365 , struct V_1368 , V_1370 ) ;
V_1369 -> V_1371 = V_1367 ;
return V_87 -> V_1363 ( V_1369 -> V_139 ,
V_1367 -> V_599 , V_1369 -> V_1372 , 1 ) ;
}
void F_759 ( struct V_1364 * V_1365 ,
struct V_1366 * V_1367 )
{
int V_108 ;
struct V_1368 * V_1369 =
F_4 ( V_1365 , struct V_1368 , V_1370 ) ;
F_30 ( V_1369 -> V_1371 != V_1367 ) ;
V_1369 -> V_1371 = NULL ;
V_108 = V_87 -> V_1363 ( V_1369 -> V_139 , V_1367 -> V_599 , V_1369 -> V_1372 , 0 ) ;
if ( V_108 )
F_12 ( V_1373 L_31
L_32 , V_1369 -> V_1370 . V_1359 , V_108 ) ;
}
int F_760 ( struct V_139 * V_139 , unsigned int V_1374 ,
T_7 V_1375 , bool V_1376 )
{
if ( ! V_87 -> V_1363 )
return - V_583 ;
return V_87 -> V_1363 ( V_139 , V_1374 , V_1375 , V_1376 ) ;
}
bool F_761 ( void )
{
return V_1377 ;
}
