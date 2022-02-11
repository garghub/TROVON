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
bool V_310 ;
bool V_311 ;
T_2 V_39 = V_22 -> V_39 ;
bool V_312 = false ;
F_155 ( & V_139 -> V_5 . V_313 , V_15 ) ;
V_94 = F_150 ( V_2 , V_39 ) ;
V_308 = F_156 () ;
V_309 = V_308 - V_139 -> V_5 . V_314 ;
if ( V_2 -> V_5 . V_285 ) {
if ( V_39 == 0 && V_22 -> V_41 ) {
V_312 = true ;
} else {
T_2 V_315 = V_139 -> V_5 . V_316 +
F_157 ( V_2 , V_309 ) ;
T_2 V_317 = V_2 -> V_5 . V_285 * 1000LL ;
V_312 = V_39 < V_315 + V_317 &&
V_39 + V_317 > V_315 ;
}
}
if ( V_312 &&
V_2 -> V_5 . V_285 == V_139 -> V_5 . V_318 ) {
if ( ! F_158 () ) {
V_94 = V_139 -> V_5 . V_319 ;
F_133 ( L_6 , V_39 ) ;
} else {
T_2 V_320 = F_157 ( V_2 , V_309 ) ;
V_39 += V_320 ;
V_94 = F_150 ( V_2 , V_39 ) ;
F_133 ( L_7 , V_320 ) ;
}
V_310 = true ;
V_311 = ( V_2 -> V_5 . V_321 == V_139 -> V_5 . V_322 ) ;
} else {
V_139 -> V_5 . V_322 ++ ;
V_139 -> V_5 . V_323 = V_308 ;
V_139 -> V_5 . V_324 = V_39 ;
V_139 -> V_5 . V_319 = V_94 ;
V_310 = false ;
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
if ( ! V_310 ) {
V_139 -> V_5 . V_295 = 0 ;
} else if ( ! V_311 ) {
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
F_184 ( V_339 , V_2 ) ;
F_162 ( & V_293 -> V_326 ) ;
#endif
}
T_2 F_185 ( struct V_139 * V_139 )
{
struct V_292 * V_293 = & V_139 -> V_5 ;
struct V_341 V_342 ;
T_2 V_108 ;
F_161 ( & V_293 -> V_326 ) ;
if ( ! V_293 -> V_297 ) {
F_162 ( & V_293 -> V_326 ) ;
return F_156 () + V_293 -> V_249 ;
}
V_342 . V_343 = V_293 -> V_335 ;
V_342 . V_344 = V_293 -> V_334 + V_293 -> V_249 ;
F_162 ( & V_293 -> V_326 ) ;
F_186 () ;
F_132 ( V_282 , F_187 ( V_345 ) * 1000LL ,
& V_342 . V_346 ,
& V_342 . V_347 ) ;
V_108 = F_188 ( & V_342 , F_151 () ) ;
F_189 () ;
return V_108 ;
}
static void F_190 ( struct V_1 * V_267 )
{
struct V_348 * V_2 = & V_267 -> V_5 ;
struct V_341 V_349 ;
if ( F_171 ( F_191 ( V_267 -> V_139 , & V_2 -> V_350 ,
& V_349 , sizeof( V_349 ) ) ) )
return;
F_192 ( F_193 ( struct V_341 , V_244 ) != 0 ) ;
V_2 -> V_342 . V_244 = V_349 . V_244 + 1 ;
F_194 ( V_267 -> V_139 , & V_2 -> V_350 ,
& V_2 -> V_342 ,
sizeof( V_2 -> V_342 . V_244 ) ) ;
F_195 () ;
V_2 -> V_342 . V_15 |= ( V_349 . V_15 & V_351 ) ;
if ( V_2 -> V_352 ) {
V_2 -> V_342 . V_15 |= V_351 ;
V_2 -> V_352 = false ;
}
F_196 ( V_267 -> V_300 , & V_2 -> V_342 ) ;
F_194 ( V_267 -> V_139 , & V_2 -> V_350 ,
& V_2 -> V_342 ,
sizeof( V_2 -> V_342 ) ) ;
F_195 () ;
V_2 -> V_342 . V_244 ++ ;
F_194 ( V_267 -> V_139 , & V_2 -> V_350 ,
& V_2 -> V_342 ,
sizeof( V_2 -> V_342 . V_244 ) ) ;
}
static int F_197 ( struct V_1 * V_267 )
{
unsigned long V_15 , V_353 ;
struct V_348 * V_2 = & V_267 -> V_5 ;
struct V_292 * V_293 = & V_267 -> V_139 -> V_5 ;
T_12 V_287 ;
T_2 V_343 , V_306 ;
T_13 V_354 ;
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
V_353 = F_187 ( V_345 ) ;
if ( F_171 ( V_353 == 0 ) ) {
F_7 ( V_15 ) ;
F_32 ( V_340 , V_267 ) ;
return 1 ;
}
if ( ! V_297 ) {
V_306 = F_151 () ;
V_287 = F_156 () ;
}
V_343 = F_152 ( V_267 , V_306 ) ;
if ( V_2 -> V_275 ) {
T_2 V_288 = F_141 ( V_267 , V_287 ) ;
if ( V_288 > V_343 ) {
F_163 ( V_267 , V_288 - V_343 ) ;
V_343 = V_288 ;
}
}
F_7 ( V_15 ) ;
if ( V_273 )
V_353 = F_149 ( V_267 , V_353 ) ;
if ( F_171 ( V_2 -> V_355 != V_353 ) ) {
F_132 ( V_282 , V_353 * 1000LL ,
& V_2 -> V_342 . V_346 ,
& V_2 -> V_342 . V_347 ) ;
V_2 -> V_355 = V_353 ;
}
V_2 -> V_342 . V_343 = V_343 ;
V_2 -> V_342 . V_344 = V_287 + V_267 -> V_139 -> V_5 . V_249 ;
V_2 -> V_325 = V_343 ;
V_354 = 0 ;
if ( V_297 )
V_354 |= V_356 ;
V_2 -> V_342 . V_15 = V_354 ;
if ( V_2 -> V_357 )
F_190 ( V_267 ) ;
if ( V_267 == F_198 ( V_267 -> V_139 , 0 ) )
F_199 ( V_267 -> V_139 , & V_2 -> V_342 ) ;
return 0 ;
}
static void F_200 ( struct V_358 * V_359 )
{
int V_3 ;
struct V_360 * V_361 = F_201 ( V_359 ) ;
struct V_292 * V_293 = F_4 ( V_361 , struct V_292 ,
V_362 ) ;
struct V_139 * V_139 = F_4 ( V_293 , struct V_139 , V_5 ) ;
struct V_1 * V_2 ;
F_183 (i, vcpu, kvm) {
F_32 ( V_340 , V_2 ) ;
F_202 ( V_2 ) ;
}
}
static void F_203 ( struct V_1 * V_267 )
{
struct V_139 * V_139 = V_267 -> V_139 ;
F_32 ( V_340 , V_267 ) ;
F_204 ( & V_139 -> V_5 . V_362 ,
V_363 ) ;
}
static void F_205 ( struct V_358 * V_359 )
{
struct V_360 * V_361 = F_201 ( V_359 ) ;
struct V_292 * V_293 = F_4 ( V_361 , struct V_292 ,
V_364 ) ;
struct V_139 * V_139 = F_4 ( V_293 , struct V_139 , V_5 ) ;
if ( ! V_365 )
return;
F_204 ( & V_139 -> V_5 . V_362 , 0 ) ;
F_204 ( & V_139 -> V_5 . V_364 ,
V_366 ) ;
}
static int F_206 ( struct V_1 * V_2 , T_1 V_22 , T_2 V_39 )
{
T_2 V_367 = V_2 -> V_5 . V_367 ;
unsigned V_368 = V_367 & 0xff ;
switch ( V_22 ) {
case V_369 :
V_2 -> V_5 . V_370 = V_39 ;
break;
case V_371 :
if ( ! ( V_367 & V_372 ) )
return 1 ;
if ( V_39 != 0 && V_39 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_373 = V_39 ;
break;
default:
if ( V_22 >= V_374 &&
V_22 < F_207 ( V_368 ) ) {
T_1 V_94 = V_22 - V_374 ;
if ( ( V_94 & 0x3 ) == 0 &&
V_39 != 0 && ( V_39 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_375 [ V_94 ] = V_39 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_208 ( struct V_1 * V_2 , T_2 V_39 )
{
struct V_139 * V_139 = V_2 -> V_139 ;
int V_376 = F_58 ( V_2 ) ;
T_13 * V_377 = V_376 ? ( T_13 * ) ( long ) V_139 -> V_5 . F_208 . V_378
: ( T_13 * ) ( long ) V_139 -> V_5 . F_208 . V_379 ;
T_13 V_380 = V_376 ? V_139 -> V_5 . F_208 . V_381
: V_139 -> V_5 . F_208 . V_382 ;
T_1 V_383 = V_39 & ~ V_384 ;
T_2 V_385 = V_39 & V_384 ;
T_13 * V_386 ;
int V_121 ;
V_121 = - V_387 ;
if ( V_383 >= V_380 )
goto V_113;
V_121 = - V_388 ;
V_386 = F_209 ( V_377 + ( V_383 * V_107 ) , V_107 ) ;
if ( F_210 ( V_386 ) ) {
V_121 = F_211 ( V_386 ) ;
goto V_113;
}
if ( F_212 ( V_2 , V_385 , V_386 , V_107 ) )
goto V_389;
V_121 = 0 ;
V_389:
F_213 ( V_386 ) ;
V_113:
return V_121 ;
}
static int F_214 ( struct V_1 * V_2 , T_2 V_39 )
{
T_6 V_390 = V_39 & ~ 0x3f ;
if ( V_39 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_391 = V_39 ;
if ( ! ( V_39 & V_392 ) ) {
F_66 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_215 ( V_2 -> V_139 , & V_2 -> V_5 . V_6 . V_39 , V_390 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_393 = ! ( V_39 & V_394 ) ;
F_216 ( V_2 ) ;
return 0 ;
}
static void F_217 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_357 = false ;
}
static void F_218 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_395 . V_391 & V_396 ) )
return;
if ( F_171 ( F_191 ( V_2 -> V_139 , & V_2 -> V_5 . V_395 . V_397 ,
& V_2 -> V_5 . V_395 . V_398 , sizeof( struct V_399 ) ) ) )
return;
V_2 -> V_5 . V_395 . V_398 . V_400 = 0 ;
if ( V_2 -> V_5 . V_395 . V_398 . V_244 & 1 )
V_2 -> V_5 . V_395 . V_398 . V_244 += 1 ;
V_2 -> V_5 . V_395 . V_398 . V_244 += 1 ;
F_194 ( V_2 -> V_139 , & V_2 -> V_5 . V_395 . V_397 ,
& V_2 -> V_5 . V_395 . V_398 , sizeof( struct V_399 ) ) ;
F_195 () ;
V_2 -> V_5 . V_395 . V_398 . V_398 += V_401 -> V_402 . V_403 -
V_2 -> V_5 . V_395 . V_404 ;
V_2 -> V_5 . V_395 . V_404 = V_401 -> V_402 . V_403 ;
F_194 ( V_2 -> V_139 , & V_2 -> V_5 . V_395 . V_397 ,
& V_2 -> V_5 . V_395 . V_398 , sizeof( struct V_399 ) ) ;
F_195 () ;
V_2 -> V_5 . V_395 . V_398 . V_244 += 1 ;
F_194 ( V_2 -> V_139 , & V_2 -> V_5 . V_395 . V_397 ,
& V_2 -> V_5 . V_395 . V_398 , sizeof( struct V_399 ) ) ;
}
int F_219 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
bool V_405 = false ;
T_1 V_22 = V_34 -> V_147 ;
T_2 V_39 = V_34 -> V_39 ;
switch ( V_22 ) {
case V_406 :
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
F_220 ( V_2 , L_9 ,
V_39 ) ;
return 1 ;
}
break;
case V_415 :
if ( V_39 != 0 ) {
F_220 ( V_2 , L_10
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
F_220 ( V_2 , L_12 ,
V_264 , V_39 ) ;
break;
case 0x200 ... 0x2ff :
return F_221 ( V_2 , V_22 , V_39 ) ;
case V_419 :
return F_22 ( V_2 , V_34 ) ;
case V_420 ... V_420 + 0x3ff :
return F_222 ( V_2 , V_22 , V_39 ) ;
case V_421 :
F_223 ( V_2 , V_39 ) ;
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
F_217 ( V_2 ) ;
if ( V_2 -> V_300 == 0 && ! V_34 -> V_41 ) {
bool V_432 = ( V_22 == V_431 ) ;
if ( V_293 -> V_337 != V_432 )
F_32 ( V_299 , V_2 ) ;
V_293 -> V_337 = V_432 ;
}
V_2 -> V_5 . time = V_39 ;
F_32 ( V_433 , V_2 ) ;
if ( ! ( V_39 & 1 ) )
break;
if ( F_215 ( V_2 -> V_139 ,
& V_2 -> V_5 . V_350 , V_39 & ~ 1ULL ,
sizeof( struct V_341 ) ) )
V_2 -> V_5 . V_357 = false ;
else
V_2 -> V_5 . V_357 = true ;
break;
}
case V_434 :
if ( F_214 ( V_2 , V_39 ) )
return 1 ;
break;
case V_435 :
if ( F_171 ( ! F_224 () ) )
return 1 ;
if ( V_39 & V_436 )
return 1 ;
if ( F_215 ( V_2 -> V_139 , & V_2 -> V_5 . V_395 . V_397 ,
V_39 & V_437 ,
sizeof( struct V_399 ) ) )
return 1 ;
V_2 -> V_5 . V_395 . V_391 = V_39 ;
if ( ! ( V_39 & V_396 ) )
break;
F_32 ( V_438 , V_2 ) ;
break;
case V_439 :
if ( F_225 ( V_2 , V_39 ) )
return 1 ;
break;
case V_371 :
case V_369 :
case V_374 ... F_207 ( V_440 ) - 1 :
return F_206 ( V_2 , V_22 , V_39 ) ;
case V_441 ... V_442 :
case V_443 ... V_444 :
V_405 = true ;
case V_445 ... V_446 :
case V_447 ... V_448 :
if ( F_226 ( V_2 , V_22 ) )
return F_227 ( V_2 , V_34 ) ;
if ( V_405 || V_39 != 0 )
F_220 ( V_2 , L_13
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
F_220 ( V_2 , L_15 , V_22 , V_39 ) ;
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
case V_463 :
if ( ! V_34 -> V_41 ||
V_39 & ~ V_464 ||
( ! ( V_39 & V_464 ) &&
F_230 ( V_2 ) ) )
return 1 ;
V_2 -> V_5 . V_465 = V_39 ;
break;
case V_466 :
if ( V_39 & ~ V_467 ||
( V_39 & V_467 &&
! F_231 ( V_2 ) ) )
return 1 ;
V_2 -> V_5 . V_468 = V_39 ;
break;
default:
if ( V_22 && ( V_22 == V_2 -> V_139 -> V_5 . F_208 . V_22 ) )
return F_208 ( V_2 , V_39 ) ;
if ( F_226 ( V_2 , V_22 ) )
return F_227 ( V_2 , V_34 ) ;
if ( ! V_469 ) {
F_232 ( V_2 , L_16 ,
V_22 , V_39 ) ;
return 1 ;
} else {
F_220 ( V_2 , L_15 ,
V_22 , V_39 ) ;
break;
}
}
return 0 ;
}
int F_116 ( struct V_1 * V_2 , struct V_33 * V_22 )
{
return V_87 -> V_470 ( V_2 , V_22 ) ;
}
static int F_233 ( struct V_1 * V_2 , T_1 V_22 , T_2 * V_471 )
{
T_2 V_39 ;
T_2 V_367 = V_2 -> V_5 . V_367 ;
unsigned V_368 = V_367 & 0xff ;
switch ( V_22 ) {
case V_472 :
case V_473 :
V_39 = 0 ;
break;
case V_474 :
V_39 = V_2 -> V_5 . V_367 ;
break;
case V_371 :
if ( ! ( V_367 & V_372 ) )
return 1 ;
V_39 = V_2 -> V_5 . V_373 ;
break;
case V_369 :
V_39 = V_2 -> V_5 . V_370 ;
break;
default:
if ( V_22 >= V_374 &&
V_22 < F_207 ( V_368 ) ) {
T_1 V_94 = V_22 - V_374 ;
V_39 = V_2 -> V_5 . V_375 [ V_94 ] ;
break;
}
return 1 ;
}
* V_471 = V_39 ;
return 0 ;
}
int F_234 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
switch ( V_34 -> V_147 ) {
case V_475 :
case V_476 :
case V_416 :
case V_477 :
case V_478 :
case V_479 :
case V_480 :
case V_481 :
case V_482 :
case V_483 :
case V_414 :
case V_409 :
case V_484 :
case V_406 :
case V_415 :
case V_411 :
case V_485 :
case V_412 :
V_34 -> V_39 = 0 ;
break;
case V_445 ... V_446 :
case V_441 ... V_442 :
case V_443 ... V_444 :
case V_447 ... V_448 :
if ( F_226 ( V_2 , V_34 -> V_147 ) )
return F_235 ( V_2 , V_34 -> V_147 , & V_34 -> V_39 ) ;
V_34 -> V_39 = 0 ;
break;
case V_407 :
V_34 -> V_39 = 0x100000000ULL ;
break;
case V_486 :
case 0x200 ... 0x2ff :
return F_236 ( V_2 , V_34 -> V_147 , & V_34 -> V_39 ) ;
case 0xcd :
V_34 -> V_39 = 3 ;
break;
case V_487 :
V_34 -> V_39 = 1 << 24 ;
break;
case V_419 :
V_34 -> V_39 = F_21 ( V_2 ) ;
break;
case V_420 ... V_420 + 0x3ff :
return F_237 ( V_2 , V_34 -> V_147 , & V_34 -> V_39 ) ;
break;
case V_421 :
V_34 -> V_39 = F_238 ( V_2 ) ;
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
case V_488 :
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
V_34 -> V_39 = V_2 -> V_5 . V_6 . V_391 ;
break;
case V_435 :
V_34 -> V_39 = V_2 -> V_5 . V_395 . V_391 ;
break;
case V_439 :
V_34 -> V_39 = V_2 -> V_5 . V_489 . V_391 ;
break;
case V_472 :
case V_473 :
case V_474 :
case V_371 :
case V_369 :
case V_374 ... F_207 ( V_440 ) - 1 :
return F_233 ( V_2 , V_34 -> V_147 , & V_34 -> V_39 ) ;
case V_449 :
V_34 -> V_39 = 0x20000000 ;
break;
case V_450 ... V_451 :
case V_452 ... V_453 :
case V_454 :
case V_455 ... V_456 :
return F_239 ( V_2 ,
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
case V_463 :
V_34 -> V_39 = V_2 -> V_5 . V_465 ;
break;
case V_466 :
V_34 -> V_39 = V_2 -> V_5 . V_468 ;
break;
default:
if ( F_226 ( V_2 , V_34 -> V_147 ) )
return F_235 ( V_2 , V_34 -> V_147 , & V_34 -> V_39 ) ;
if ( ! V_469 ) {
F_232 ( V_2 , L_17 ,
V_34 -> V_147 ) ;
return 1 ;
} else {
F_220 ( V_2 , L_18 , V_34 -> V_147 ) ;
V_34 -> V_39 = 0 ;
}
break;
}
return 0 ;
}
static int F_240 ( struct V_1 * V_2 , struct V_490 * V_21 ,
struct V_491 * V_492 ,
int (* F_241)( struct V_1 * V_2 ,
unsigned V_147 , T_2 * V_39 ) )
{
int V_3 , V_493 ;
V_493 = F_242 ( & V_2 -> V_139 -> V_494 ) ;
for ( V_3 = 0 ; V_3 < V_21 -> V_495 ; ++ V_3 )
if ( F_241 ( V_2 , V_492 [ V_3 ] . V_147 , & V_492 [ V_3 ] . V_39 ) )
break;
F_243 ( & V_2 -> V_139 -> V_494 , V_493 ) ;
return V_3 ;
}
static int F_244 ( struct V_1 * V_2 , struct V_490 T_14 * V_496 ,
int (* F_241)( struct V_1 * V_2 ,
unsigned V_147 , T_2 * V_39 ) ,
int V_497 )
{
struct V_490 V_21 ;
struct V_491 * V_492 ;
int V_121 , V_498 ;
unsigned V_499 ;
V_121 = - V_101 ;
if ( F_245 ( & V_21 , V_496 , sizeof V_21 ) )
goto V_113;
V_121 = - V_387 ;
if ( V_21 . V_495 >= V_500 )
goto V_113;
V_499 = sizeof( struct V_491 ) * V_21 . V_495 ;
V_492 = F_209 ( V_496 -> V_492 , V_499 ) ;
if ( F_210 ( V_492 ) ) {
V_121 = F_211 ( V_492 ) ;
goto V_113;
}
V_121 = V_498 = F_240 ( V_2 , & V_21 , V_492 , F_241 ) ;
if ( V_121 < 0 )
goto V_389;
V_121 = - V_101 ;
if ( V_497 && F_246 ( V_496 -> V_492 , V_492 , V_499 ) )
goto V_389;
V_121 = V_498 ;
V_389:
F_213 ( V_492 ) ;
V_113:
return V_121 ;
}
int F_247 ( struct V_139 * V_139 , long V_501 )
{
int V_121 ;
switch ( V_501 ) {
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
case V_537 :
case V_538 :
case V_539 :
case V_540 :
case V_541 :
case V_542 :
V_121 = 1 ;
break;
case V_543 :
V_121 = V_544 ;
break;
case V_545 :
V_121 = F_248 () ;
break;
case V_546 :
V_121 = V_87 -> V_547 () ;
break;
case V_548 :
V_121 = ! V_87 -> V_549 () ;
break;
case V_550 :
V_121 = V_551 ;
break;
case V_552 :
V_121 = V_553 ;
break;
case V_554 :
V_121 = V_555 ;
break;
case V_556 :
V_121 = 0 ;
break;
case V_557 :
V_121 = V_440 ;
break;
case V_558 :
V_121 = F_249 ( V_559 ) ;
break;
case V_560 :
V_121 = V_273 ;
break;
case V_561 :
V_121 = V_562 ;
break;
default:
V_121 = 0 ;
break;
}
return V_121 ;
}
long F_250 ( struct V_563 * V_564 ,
unsigned int V_565 , unsigned long V_566 )
{
void T_14 * V_567 = ( void T_14 * ) V_566 ;
long V_121 ;
switch ( V_565 ) {
case V_568 : {
struct V_569 T_14 * V_570 = V_567 ;
struct V_569 V_571 ;
unsigned V_498 ;
V_121 = - V_101 ;
if ( F_245 ( & V_571 , V_570 , sizeof V_571 ) )
goto V_113;
V_498 = V_571 . V_495 ;
V_571 . V_495 = V_572 + V_573 ;
if ( F_246 ( V_570 , & V_571 , sizeof V_571 ) )
goto V_113;
V_121 = - V_387 ;
if ( V_498 < V_571 . V_495 )
goto V_113;
V_121 = - V_101 ;
if ( F_246 ( V_570 -> V_574 , & V_575 ,
V_572 * sizeof( T_1 ) ) )
goto V_113;
if ( F_246 ( V_570 -> V_574 + V_572 ,
& V_576 ,
V_573 * sizeof( T_1 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_577 :
case V_578 : {
struct V_579 T_14 * V_580 = V_567 ;
struct V_579 V_581 ;
V_121 = - V_101 ;
if ( F_245 ( & V_581 , V_580 , sizeof V_581 ) )
goto V_113;
V_121 = F_251 ( & V_581 , V_580 -> V_492 ,
V_565 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_246 ( V_580 , & V_581 , sizeof V_581 ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_582 : {
V_121 = - V_101 ;
if ( F_246 ( V_567 , & V_583 ,
sizeof( V_583 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
default:
V_121 = - V_584 ;
}
V_113:
return V_121 ;
}
static void F_252 ( void * V_585 )
{
F_253 () ;
}
static bool F_254 ( struct V_1 * V_2 )
{
return F_68 ( V_2 -> V_139 ) ;
}
void F_255 ( struct V_1 * V_2 , int V_24 )
{
if ( F_254 ( V_2 ) ) {
if ( V_87 -> V_586 () )
F_256 ( V_24 , V_2 -> V_5 . V_587 ) ;
else if ( V_2 -> V_24 != - 1 && V_2 -> V_24 != V_24 )
F_257 ( V_2 -> V_24 ,
F_252 , NULL , 1 ) ;
}
V_87 -> V_588 ( V_2 , V_24 ) ;
if ( F_171 ( V_2 -> V_5 . V_589 ) ) {
F_164 ( V_2 , V_2 -> V_5 . V_589 ) ;
V_2 -> V_5 . V_589 = 0 ;
F_32 ( V_340 , V_2 ) ;
}
if ( F_171 ( V_2 -> V_24 != V_24 ) || F_158 () ) {
T_12 V_590 = ! V_2 -> V_5 . V_591 ? 0 :
F_151 () - V_2 -> V_5 . V_591 ;
if ( V_590 < 0 )
F_258 ( L_19 ) ;
if ( F_158 () ) {
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
F_32 ( V_593 , V_2 ) ;
V_2 -> V_24 = V_24 ;
}
F_32 ( V_438 , V_2 ) ;
}
static void F_262 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_395 . V_391 & V_396 ) )
return;
V_2 -> V_5 . V_395 . V_398 . V_400 = 1 ;
F_263 ( V_2 -> V_139 , & V_2 -> V_5 . V_395 . V_397 ,
& V_2 -> V_5 . V_395 . V_398 . V_400 ,
F_193 ( struct V_399 , V_400 ) ,
sizeof( V_2 -> V_5 . V_395 . V_398 . V_400 ) ) ;
}
void F_264 ( struct V_1 * V_2 )
{
int V_493 ;
F_265 () ;
V_493 = F_242 ( & V_2 -> V_139 -> V_494 ) ;
F_262 ( V_2 ) ;
F_243 ( & V_2 -> V_139 -> V_494 , V_493 ) ;
F_266 () ;
V_87 -> V_594 ( V_2 ) ;
F_267 ( V_2 ) ;
V_2 -> V_5 . V_591 = F_151 () ;
}
static int F_268 ( struct V_1 * V_2 ,
struct V_595 * V_596 )
{
if ( V_87 -> V_597 && V_2 -> V_5 . V_598 )
V_87 -> V_597 ( V_2 ) ;
return F_269 ( V_2 , V_596 ) ;
}
static int F_270 ( struct V_1 * V_2 ,
struct V_595 * V_596 )
{
int V_121 ;
V_121 = F_271 ( V_2 , V_596 ) ;
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
struct V_599 * V_600 )
{
if ( V_600 -> V_600 >= V_601 )
return - V_584 ;
if ( ! F_280 ( V_2 -> V_139 ) ) {
F_281 ( V_2 , V_600 -> V_600 , false ) ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
if ( F_282 ( V_2 -> V_139 ) )
return - V_602 ;
if ( V_2 -> V_5 . V_603 != - 1 )
return - V_604 ;
V_2 -> V_5 . V_603 = V_600 -> V_600 ;
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
F_32 ( V_605 , V_2 ) ;
return 0 ;
}
static int F_285 ( struct V_1 * V_2 ,
struct V_606 * V_607 )
{
if ( V_607 -> V_15 )
return - V_584 ;
V_2 -> V_5 . V_608 = ! ! V_607 -> V_609 ;
return 0 ;
}
static int F_286 ( struct V_1 * V_2 ,
T_2 V_367 )
{
int V_121 ;
unsigned V_368 = V_367 & 0xff , V_610 ;
V_121 = - V_584 ;
if ( ! V_368 || V_368 >= V_440 )
goto V_113;
if ( V_367 & ~ ( V_583 | 0xff | 0xff0000 ) )
goto V_113;
V_121 = 0 ;
V_2 -> V_5 . V_367 = V_367 ;
if ( V_367 & V_372 )
V_2 -> V_5 . V_373 = ~ ( T_2 ) 0 ;
for ( V_610 = 0 ; V_610 < V_368 ; V_610 ++ )
V_2 -> V_5 . V_375 [ V_610 * 4 ] = ~ ( T_2 ) 0 ;
if ( V_87 -> V_611 )
V_87 -> V_611 ( V_2 ) ;
V_113:
return V_121 ;
}
static int F_287 ( struct V_1 * V_2 ,
struct V_612 * V_613 )
{
T_2 V_367 = V_2 -> V_5 . V_367 ;
unsigned V_368 = V_367 & 0xff ;
T_2 * V_614 = V_2 -> V_5 . V_375 ;
if ( V_613 -> V_610 >= V_368 || ! ( V_613 -> V_462 & V_615 ) )
return - V_584 ;
if ( ( V_613 -> V_462 & V_616 ) && ( V_367 & V_372 ) &&
V_2 -> V_5 . V_373 != ~ ( T_2 ) 0 )
return 0 ;
V_614 += 4 * V_613 -> V_610 ;
if ( ( V_613 -> V_462 & V_616 ) && V_614 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_613 -> V_462 & V_616 ) {
if ( ( V_2 -> V_5 . V_370 & V_617 ) ||
! F_48 ( V_2 , V_618 ) ) {
F_32 ( V_73 , V_2 ) ;
return 0 ;
}
if ( V_614 [ 1 ] & V_615 )
V_613 -> V_462 |= V_619 ;
V_614 [ 2 ] = V_613 -> V_620 ;
V_614 [ 3 ] = V_613 -> V_621 ;
V_2 -> V_5 . V_370 = V_613 -> V_370 ;
V_614 [ 1 ] = V_613 -> V_462 ;
F_34 ( V_2 , V_59 ) ;
} else if ( ! ( V_614 [ 1 ] & V_615 )
|| ! ( V_614 [ 1 ] & V_616 ) ) {
if ( V_614 [ 1 ] & V_615 )
V_613 -> V_462 |= V_619 ;
V_614 [ 2 ] = V_613 -> V_620 ;
V_614 [ 3 ] = V_613 -> V_621 ;
V_614 [ 1 ] = V_613 -> V_462 ;
} else
V_614 [ 1 ] |= V_619 ;
return 0 ;
}
static void F_288 ( struct V_1 * V_2 ,
struct V_622 * V_623 )
{
F_289 ( V_2 ) ;
V_623 -> V_69 . V_624 =
V_2 -> V_5 . V_69 . V_70 &&
! F_290 ( V_2 -> V_5 . V_69 . V_18 ) ;
V_623 -> V_69 . V_18 = V_2 -> V_5 . V_69 . V_18 ;
V_623 -> V_69 . V_72 = V_2 -> V_5 . V_69 . V_72 ;
V_623 -> V_69 . V_625 = 0 ;
V_623 -> V_69 . V_63 = V_2 -> V_5 . V_69 . V_63 ;
V_623 -> V_626 . V_624 =
V_2 -> V_5 . V_626 . V_70 && ! V_2 -> V_5 . V_626 . V_627 ;
V_623 -> V_626 . V_18 = V_2 -> V_5 . V_626 . V_18 ;
V_623 -> V_626 . V_627 = 0 ;
V_623 -> V_626 . V_628 = V_87 -> V_629 ( V_2 ) ;
V_623 -> V_630 . V_624 = V_2 -> V_5 . V_631 ;
V_623 -> V_630 . V_70 = V_2 -> V_5 . V_632 != 0 ;
V_623 -> V_630 . V_633 = V_87 -> V_634 ( V_2 ) ;
V_623 -> V_630 . V_625 = 0 ;
V_623 -> V_635 = 0 ;
V_623 -> V_636 . V_637 = F_291 ( V_2 ) ;
V_623 -> V_636 . V_70 = V_2 -> V_5 . V_638 ;
V_623 -> V_636 . V_639 =
! ! ( V_2 -> V_5 . V_640 & V_641 ) ;
V_623 -> V_636 . V_642 = F_292 ( V_2 ) ;
V_623 -> V_15 = ( V_643
| V_644
| V_645 ) ;
memset ( & V_623 -> V_646 , 0 , sizeof( V_623 -> V_646 ) ) ;
}
static int F_293 ( struct V_1 * V_2 ,
struct V_622 * V_623 )
{
if ( V_623 -> V_15 & ~ ( V_643
| V_647
| V_644
| V_645 ) )
return - V_584 ;
if ( V_623 -> V_69 . V_624 &&
( V_623 -> V_69 . V_18 > 31 || V_623 -> V_69 . V_18 == V_52 ||
F_294 ( V_2 ) ) )
return - V_584 ;
if ( V_623 -> V_15 & V_645 &&
( V_623 -> V_636 . V_637 || V_623 -> V_636 . V_70 ) &&
V_2 -> V_5 . V_648 == V_649 )
return - V_584 ;
F_289 ( V_2 ) ;
V_2 -> V_5 . V_69 . V_70 = V_623 -> V_69 . V_624 ;
V_2 -> V_5 . V_69 . V_18 = V_623 -> V_69 . V_18 ;
V_2 -> V_5 . V_69 . V_72 = V_623 -> V_69 . V_72 ;
V_2 -> V_5 . V_69 . V_63 = V_623 -> V_69 . V_63 ;
V_2 -> V_5 . V_626 . V_70 = V_623 -> V_626 . V_624 ;
V_2 -> V_5 . V_626 . V_18 = V_623 -> V_626 . V_18 ;
V_2 -> V_5 . V_626 . V_627 = V_623 -> V_626 . V_627 ;
if ( V_623 -> V_15 & V_644 )
V_87 -> V_650 ( V_2 ,
V_623 -> V_626 . V_628 ) ;
V_2 -> V_5 . V_631 = V_623 -> V_630 . V_624 ;
if ( V_623 -> V_15 & V_643 )
V_2 -> V_5 . V_632 = V_623 -> V_630 . V_70 ;
V_87 -> V_651 ( V_2 , V_623 -> V_630 . V_633 ) ;
if ( V_623 -> V_15 & V_647 &&
F_91 ( V_2 ) )
V_2 -> V_5 . V_652 -> V_635 = V_623 -> V_635 ;
if ( V_623 -> V_15 & V_645 ) {
T_1 V_640 = V_2 -> V_5 . V_640 ;
if ( V_623 -> V_636 . V_637 )
V_640 |= V_653 ;
else
V_640 &= ~ V_653 ;
F_295 ( V_2 , V_640 ) ;
V_2 -> V_5 . V_638 = V_623 -> V_636 . V_70 ;
if ( V_623 -> V_636 . V_639 )
V_2 -> V_5 . V_640 |= V_641 ;
else
V_2 -> V_5 . V_640 &= ~ V_641 ;
if ( F_91 ( V_2 ) ) {
if ( V_623 -> V_636 . V_642 )
F_296 ( V_654 , & V_2 -> V_5 . V_652 -> V_655 ) ;
else
F_297 ( V_654 , & V_2 -> V_5 . V_652 -> V_655 ) ;
}
}
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
static void F_298 ( struct V_1 * V_2 ,
struct V_656 * V_657 )
{
unsigned long V_196 ;
memcpy ( V_657 -> V_183 , V_2 -> V_5 . V_183 , sizeof( V_2 -> V_5 . V_183 ) ) ;
F_102 ( V_2 , 6 , & V_196 ) ;
V_657 -> V_187 = V_196 ;
V_657 -> V_188 = V_2 -> V_5 . V_188 ;
V_657 -> V_15 = 0 ;
memset ( & V_657 -> V_646 , 0 , sizeof( V_657 -> V_646 ) ) ;
}
static int F_299 ( struct V_1 * V_2 ,
struct V_656 * V_657 )
{
if ( V_657 -> V_15 )
return - V_584 ;
if ( V_657 -> V_187 & ~ 0xffffffffull )
return - V_584 ;
if ( V_657 -> V_188 & ~ 0xffffffffull )
return - V_584 ;
memcpy ( V_2 -> V_5 . V_183 , V_657 -> V_183 , sizeof( V_2 -> V_5 . V_183 ) ) ;
F_95 ( V_2 ) ;
V_2 -> V_5 . V_187 = V_657 -> V_187 ;
F_96 ( V_2 ) ;
V_2 -> V_5 . V_188 = V_657 -> V_188 ;
F_97 ( V_2 ) ;
return 0 ;
}
static void F_300 ( T_13 * V_658 , struct V_1 * V_2 )
{
struct V_659 * V_660 = & V_2 -> V_5 . V_661 . V_662 . V_660 ;
T_2 V_663 = V_660 -> V_664 . V_665 ;
T_2 V_666 ;
memcpy ( V_658 , V_660 , V_667 ) ;
V_663 &= V_2 -> V_5 . V_154 | V_668 ;
* ( T_2 * ) ( V_658 + V_667 ) = V_663 ;
V_666 = V_663 & ~ V_668 ;
while ( V_666 ) {
T_2 V_669 = V_666 & - V_666 ;
int V_147 = F_301 ( V_669 ) - 1 ;
void * V_670 = F_302 ( V_660 , V_669 ) ;
if ( V_670 ) {
T_1 V_499 , V_94 , V_201 , V_209 ;
F_303 ( V_671 , V_147 ,
& V_499 , & V_94 , & V_201 , & V_209 ) ;
memcpy ( V_658 + V_94 , V_670 , V_499 ) ;
}
V_666 -= V_669 ;
}
}
static void F_304 ( struct V_1 * V_2 , T_13 * V_670 )
{
struct V_659 * V_660 = & V_2 -> V_5 . V_661 . V_662 . V_660 ;
T_2 V_663 = * ( T_2 * ) ( V_670 + V_667 ) ;
T_2 V_666 ;
memcpy ( V_660 , V_670 , V_667 ) ;
V_660 -> V_664 . V_665 = V_663 ;
if ( F_249 ( V_672 ) )
V_660 -> V_664 . V_673 = V_146 | V_674 ;
V_666 = V_663 & ~ V_668 ;
while ( V_666 ) {
T_2 V_669 = V_666 & - V_666 ;
int V_147 = F_301 ( V_669 ) - 1 ;
void * V_658 = F_302 ( V_660 , V_669 ) ;
if ( V_658 ) {
T_1 V_499 , V_94 , V_201 , V_209 ;
F_303 ( V_671 , V_147 ,
& V_499 , & V_94 , & V_201 , & V_209 ) ;
memcpy ( V_658 , V_670 + V_94 , V_499 ) ;
}
V_666 -= V_669 ;
}
}
static void F_305 ( struct V_1 * V_2 ,
struct V_675 * V_676 )
{
if ( F_249 ( V_559 ) ) {
memset ( V_676 , 0 , sizeof( struct V_675 ) ) ;
F_300 ( ( T_13 * ) V_676 -> V_677 , V_2 ) ;
} else {
memcpy ( V_676 -> V_677 ,
& V_2 -> V_5 . V_661 . V_662 . V_678 ,
sizeof( struct V_679 ) ) ;
* ( T_2 * ) & V_676 -> V_677 [ V_667 / sizeof( T_1 ) ] =
V_668 ;
}
}
static int F_306 ( struct V_1 * V_2 ,
struct V_675 * V_676 )
{
T_2 V_663 =
* ( T_2 * ) & V_676 -> V_677 [ V_667 / sizeof( T_1 ) ] ;
T_1 V_680 = * ( T_1 * ) & V_676 -> V_677 [ V_681 / sizeof( T_1 ) ] ;
if ( F_249 ( V_559 ) ) {
if ( V_663 & ~ F_307 () ||
V_680 & ~ V_682 )
return - V_584 ;
F_304 ( V_2 , ( T_13 * ) V_676 -> V_677 ) ;
} else {
if ( V_663 & ~ V_668 ||
V_680 & ~ V_682 )
return - V_584 ;
memcpy ( & V_2 -> V_5 . V_661 . V_662 . V_678 ,
V_676 -> V_677 , sizeof( struct V_679 ) ) ;
}
return 0 ;
}
static void F_308 ( struct V_1 * V_2 ,
struct V_683 * V_684 )
{
if ( ! F_249 ( V_559 ) ) {
V_684 -> V_685 = 0 ;
return;
}
V_684 -> V_685 = 1 ;
V_684 -> V_15 = 0 ;
V_684 -> V_686 [ 0 ] . V_148 = V_144 ;
V_684 -> V_686 [ 0 ] . V_23 = V_2 -> V_5 . V_145 ;
}
static int F_309 ( struct V_1 * V_2 ,
struct V_683 * V_684 )
{
int V_3 , V_121 = 0 ;
if ( ! F_249 ( V_559 ) )
return - V_584 ;
if ( V_684 -> V_685 > V_687 || V_684 -> V_15 )
return - V_584 ;
for ( V_3 = 0 ; V_3 < V_684 -> V_685 ; V_3 ++ )
if ( V_684 -> V_686 [ V_3 ] . V_148 == V_144 ) {
V_121 = F_76 ( V_2 , V_144 ,
V_684 -> V_686 [ V_3 ] . V_23 ) ;
break;
}
if ( V_121 )
V_121 = - V_584 ;
return V_121 ;
}
static int F_310 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_357 )
return - V_584 ;
V_2 -> V_5 . V_352 = true ;
F_32 ( V_340 , V_2 ) ;
return 0 ;
}
static int F_311 ( struct V_1 * V_2 ,
struct V_688 * V_689 )
{
if ( V_689 -> V_15 )
return - V_584 ;
switch ( V_689 -> V_689 ) {
case V_526 :
if ( ! F_280 ( V_2 -> V_139 ) )
return - V_584 ;
return F_312 ( V_2 ) ;
default:
return - V_584 ;
}
}
long F_313 ( struct V_563 * V_564 ,
unsigned int V_565 , unsigned long V_566 )
{
struct V_1 * V_2 = V_564 -> V_690 ;
void T_14 * V_567 = ( void T_14 * ) V_566 ;
int V_121 ;
union {
struct V_595 * V_691 ;
struct V_675 * V_660 ;
struct V_683 * V_686 ;
void * V_692 ;
} V_693 ;
V_693 . V_692 = NULL ;
switch ( V_565 ) {
case V_694 : {
V_121 = - V_584 ;
if ( ! F_91 ( V_2 ) )
goto V_113;
V_693 . V_691 = F_314 ( sizeof( struct V_595 ) , V_695 ) ;
V_121 = - V_388 ;
if ( ! V_693 . V_691 )
goto V_113;
V_121 = F_268 ( V_2 , V_693 . V_691 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_246 ( V_567 , V_693 . V_691 , sizeof( struct V_595 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_696 : {
V_121 = - V_584 ;
if ( ! F_91 ( V_2 ) )
goto V_113;
V_693 . V_691 = F_209 ( V_567 , sizeof( * V_693 . V_691 ) ) ;
if ( F_210 ( V_693 . V_691 ) )
return F_211 ( V_693 . V_691 ) ;
V_121 = F_270 ( V_2 , V_693 . V_691 ) ;
break;
}
case V_697 : {
struct V_599 V_600 ;
V_121 = - V_101 ;
if ( F_245 ( & V_600 , V_567 , sizeof V_600 ) )
goto V_113;
V_121 = F_279 ( V_2 , & V_600 ) ;
break;
}
case V_698 : {
V_121 = F_283 ( V_2 ) ;
break;
}
case V_699 : {
V_121 = F_284 ( V_2 ) ;
break;
}
case V_700 : {
struct V_701 T_14 * V_580 = V_567 ;
struct V_701 V_581 ;
V_121 = - V_101 ;
if ( F_245 ( & V_581 , V_580 , sizeof V_581 ) )
goto V_113;
V_121 = F_315 ( V_2 , & V_581 , V_580 -> V_492 ) ;
break;
}
case V_702 : {
struct V_579 T_14 * V_580 = V_567 ;
struct V_579 V_581 ;
V_121 = - V_101 ;
if ( F_245 ( & V_581 , V_580 , sizeof V_581 ) )
goto V_113;
V_121 = F_316 ( V_2 , & V_581 ,
V_580 -> V_492 ) ;
break;
}
case V_703 : {
struct V_579 T_14 * V_580 = V_567 ;
struct V_579 V_581 ;
V_121 = - V_101 ;
if ( F_245 ( & V_581 , V_580 , sizeof V_581 ) )
goto V_113;
V_121 = F_317 ( V_2 , & V_581 ,
V_580 -> V_492 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_246 ( V_580 , & V_581 , sizeof V_581 ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_704 :
V_121 = F_244 ( V_2 , V_567 , F_115 , 1 ) ;
break;
case V_705 :
V_121 = F_244 ( V_2 , V_567 , F_117 , 0 ) ;
break;
case V_706 : {
struct V_606 V_607 ;
V_121 = - V_101 ;
if ( F_245 ( & V_607 , V_567 , sizeof V_607 ) )
goto V_113;
V_121 = F_285 ( V_2 , & V_607 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_246 ( V_567 , & V_607 , sizeof V_607 ) )
goto V_113;
V_121 = 0 ;
break;
} ;
case V_707 : {
struct V_708 V_709 ;
int V_493 ;
V_121 = - V_584 ;
if ( ! F_91 ( V_2 ) )
goto V_113;
V_121 = - V_101 ;
if ( F_245 ( & V_709 , V_567 , sizeof V_709 ) )
goto V_113;
V_493 = F_242 ( & V_2 -> V_139 -> V_494 ) ;
V_121 = F_318 ( V_2 , V_709 . V_710 ) ;
F_243 ( & V_2 -> V_139 -> V_494 , V_493 ) ;
break;
}
case V_711 : {
T_2 V_367 ;
V_121 = - V_101 ;
if ( F_245 ( & V_367 , V_567 , sizeof V_367 ) )
goto V_113;
V_121 = F_286 ( V_2 , V_367 ) ;
break;
}
case V_712 : {
struct V_612 V_613 ;
V_121 = - V_101 ;
if ( F_245 ( & V_613 , V_567 , sizeof V_613 ) )
goto V_113;
V_121 = F_287 ( V_2 , & V_613 ) ;
break;
}
case V_713 : {
struct V_622 V_623 ;
F_288 ( V_2 , & V_623 ) ;
V_121 = - V_101 ;
if ( F_246 ( V_567 , & V_623 , sizeof( struct V_622 ) ) )
break;
V_121 = 0 ;
break;
}
case V_714 : {
struct V_622 V_623 ;
V_121 = - V_101 ;
if ( F_245 ( & V_623 , V_567 , sizeof( struct V_622 ) ) )
break;
V_121 = F_293 ( V_2 , & V_623 ) ;
break;
}
case V_715 : {
struct V_656 V_657 ;
F_298 ( V_2 , & V_657 ) ;
V_121 = - V_101 ;
if ( F_246 ( V_567 , & V_657 ,
sizeof( struct V_656 ) ) )
break;
V_121 = 0 ;
break;
}
case V_716 : {
struct V_656 V_657 ;
V_121 = - V_101 ;
if ( F_245 ( & V_657 , V_567 ,
sizeof( struct V_656 ) ) )
break;
V_121 = F_299 ( V_2 , & V_657 ) ;
break;
}
case V_717 : {
V_693 . V_660 = F_314 ( sizeof( struct V_675 ) , V_695 ) ;
V_121 = - V_388 ;
if ( ! V_693 . V_660 )
break;
F_305 ( V_2 , V_693 . V_660 ) ;
V_121 = - V_101 ;
if ( F_246 ( V_567 , V_693 . V_660 , sizeof( struct V_675 ) ) )
break;
V_121 = 0 ;
break;
}
case V_718 : {
V_693 . V_660 = F_209 ( V_567 , sizeof( * V_693 . V_660 ) ) ;
if ( F_210 ( V_693 . V_660 ) )
return F_211 ( V_693 . V_660 ) ;
V_121 = F_306 ( V_2 , V_693 . V_660 ) ;
break;
}
case V_719 : {
V_693 . V_686 = F_314 ( sizeof( struct V_683 ) , V_695 ) ;
V_121 = - V_388 ;
if ( ! V_693 . V_686 )
break;
F_308 ( V_2 , V_693 . V_686 ) ;
V_121 = - V_101 ;
if ( F_246 ( V_567 , V_693 . V_686 ,
sizeof( struct V_683 ) ) )
break;
V_121 = 0 ;
break;
}
case V_720 : {
V_693 . V_686 = F_209 ( V_567 , sizeof( * V_693 . V_686 ) ) ;
if ( F_210 ( V_693 . V_686 ) )
return F_211 ( V_693 . V_686 ) ;
V_121 = F_309 ( V_2 , V_693 . V_686 ) ;
break;
}
case V_721 : {
T_1 V_268 ;
V_121 = - V_584 ;
V_268 = ( T_1 ) V_566 ;
if ( V_268 >= V_722 )
goto V_113;
if ( V_268 == 0 )
V_268 = V_274 ;
if ( ! F_140 ( V_2 , V_268 ) )
V_121 = 0 ;
goto V_113;
}
case V_723 : {
V_121 = V_2 -> V_5 . V_285 ;
goto V_113;
}
case V_724 : {
V_121 = F_310 ( V_2 ) ;
goto V_113;
}
case V_725 : {
struct V_688 V_689 ;
V_121 = - V_101 ;
if ( F_245 ( & V_689 , V_567 , sizeof( V_689 ) ) )
goto V_113;
V_121 = F_311 ( V_2 , & V_689 ) ;
break;
}
default:
V_121 = - V_584 ;
}
V_113:
F_213 ( V_693 . V_692 ) ;
return V_121 ;
}
int F_319 ( struct V_1 * V_2 , struct V_726 * V_727 )
{
return V_728 ;
}
static int F_320 ( struct V_139 * V_139 , unsigned long V_620 )
{
int V_108 ;
if ( V_620 > ( unsigned int ) ( - 3 * V_107 ) )
return - V_584 ;
V_108 = V_87 -> V_729 ( V_139 , V_620 ) ;
return V_108 ;
}
static int F_321 ( struct V_139 * V_139 ,
T_2 V_730 )
{
V_139 -> V_5 . V_731 = V_730 ;
return 0 ;
}
static int F_322 ( struct V_139 * V_139 ,
T_1 V_732 )
{
if ( V_732 < V_733 )
return - V_584 ;
F_323 ( & V_139 -> V_734 ) ;
F_324 ( V_139 , V_732 ) ;
V_139 -> V_5 . V_735 = V_732 ;
F_325 ( & V_139 -> V_734 ) ;
return 0 ;
}
static int F_326 ( struct V_139 * V_139 )
{
return V_139 -> V_5 . V_736 ;
}
static int F_327 ( struct V_139 * V_139 , struct V_737 * V_738 )
{
struct V_739 * V_740 = V_139 -> V_5 . V_741 ;
int V_121 ;
V_121 = 0 ;
switch ( V_738 -> V_742 ) {
case V_743 :
memcpy ( & V_738 -> V_738 . V_740 , & V_740 -> V_744 [ 0 ] ,
sizeof( struct V_745 ) ) ;
break;
case V_746 :
memcpy ( & V_738 -> V_738 . V_740 , & V_740 -> V_744 [ 1 ] ,
sizeof( struct V_745 ) ) ;
break;
case V_747 :
F_328 ( V_139 , & V_738 -> V_738 . V_748 ) ;
break;
default:
V_121 = - V_584 ;
break;
}
return V_121 ;
}
static int F_329 ( struct V_139 * V_139 , struct V_737 * V_738 )
{
struct V_739 * V_740 = V_139 -> V_5 . V_741 ;
int V_121 ;
V_121 = 0 ;
switch ( V_738 -> V_742 ) {
case V_743 :
F_161 ( & V_740 -> V_749 ) ;
memcpy ( & V_740 -> V_744 [ 0 ] , & V_738 -> V_738 . V_740 ,
sizeof( struct V_745 ) ) ;
F_162 ( & V_740 -> V_749 ) ;
break;
case V_746 :
F_161 ( & V_740 -> V_749 ) ;
memcpy ( & V_740 -> V_744 [ 1 ] , & V_738 -> V_738 . V_740 ,
sizeof( struct V_745 ) ) ;
F_162 ( & V_740 -> V_749 ) ;
break;
case V_747 :
F_330 ( V_139 , & V_738 -> V_738 . V_748 ) ;
break;
default:
V_121 = - V_584 ;
break;
}
F_331 ( V_740 ) ;
return V_121 ;
}
static int F_332 ( struct V_139 * V_139 , struct V_750 * V_751 )
{
struct V_752 * V_753 = & V_139 -> V_5 . V_754 -> V_755 ;
F_192 ( sizeof( * V_751 ) != sizeof( V_753 -> V_756 ) ) ;
F_323 ( & V_753 -> V_749 ) ;
memcpy ( V_751 , & V_753 -> V_756 , sizeof( * V_751 ) ) ;
F_325 ( & V_753 -> V_749 ) ;
return 0 ;
}
static int F_333 ( struct V_139 * V_139 , struct V_750 * V_751 )
{
int V_3 ;
struct V_757 * V_758 = V_139 -> V_5 . V_754 ;
F_323 ( & V_758 -> V_755 . V_749 ) ;
memcpy ( & V_758 -> V_755 . V_756 , V_751 , sizeof( * V_751 ) ) ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
F_334 ( V_758 , V_3 , V_751 -> V_756 [ V_3 ] . V_759 , 0 ) ;
F_325 ( & V_758 -> V_755 . V_749 ) ;
return 0 ;
}
static int F_335 ( struct V_139 * V_139 , struct V_760 * V_751 )
{
F_323 ( & V_139 -> V_5 . V_754 -> V_755 . V_749 ) ;
memcpy ( V_751 -> V_756 , & V_139 -> V_5 . V_754 -> V_755 . V_756 ,
sizeof( V_751 -> V_756 ) ) ;
V_751 -> V_15 = V_139 -> V_5 . V_754 -> V_755 . V_15 ;
F_325 ( & V_139 -> V_5 . V_754 -> V_755 . V_749 ) ;
memset ( & V_751 -> V_646 , 0 , sizeof( V_751 -> V_646 ) ) ;
return 0 ;
}
static int F_336 ( struct V_139 * V_139 , struct V_760 * V_751 )
{
int V_761 = 0 ;
int V_3 ;
T_1 V_762 , V_763 ;
struct V_757 * V_758 = V_139 -> V_5 . V_754 ;
F_323 ( & V_758 -> V_755 . V_749 ) ;
V_762 = V_758 -> V_755 . V_15 & V_764 ;
V_763 = V_751 -> V_15 & V_764 ;
if ( ! V_762 && V_763 )
V_761 = 1 ;
memcpy ( & V_758 -> V_755 . V_756 , & V_751 -> V_756 ,
sizeof( V_758 -> V_755 . V_756 ) ) ;
V_758 -> V_755 . V_15 = V_751 -> V_15 ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
F_334 ( V_758 , V_3 , V_758 -> V_755 . V_756 [ V_3 ] . V_759 ,
V_761 && V_3 == 0 ) ;
F_325 ( & V_758 -> V_755 . V_749 ) ;
return 0 ;
}
static int F_337 ( struct V_139 * V_139 ,
struct V_765 * V_766 )
{
struct V_757 * V_758 = V_139 -> V_5 . V_754 ;
if ( ! V_758 )
return - V_602 ;
F_323 ( & V_758 -> V_755 . V_749 ) ;
F_338 ( V_758 , V_766 -> V_767 ) ;
F_325 ( & V_758 -> V_755 . V_749 ) ;
return 0 ;
}
int F_339 ( struct V_139 * V_139 , struct V_768 * log )
{
bool V_769 = false ;
int V_121 ;
F_323 ( & V_139 -> V_734 ) ;
if ( V_87 -> V_770 )
V_87 -> V_770 ( V_139 ) ;
V_121 = F_340 ( V_139 , log , & V_769 ) ;
F_341 ( & V_139 -> V_734 ) ;
if ( V_769 )
F_342 ( V_139 ) ;
F_325 ( & V_139 -> V_734 ) ;
return V_121 ;
}
int F_343 ( struct V_139 * V_139 , struct V_771 * V_772 ,
bool V_773 )
{
if ( ! F_280 ( V_139 ) )
return - V_602 ;
V_772 -> V_462 = F_344 ( V_139 , V_774 ,
V_772 -> V_600 , V_772 -> V_775 ,
V_773 ) ;
return 0 ;
}
static int F_345 ( struct V_139 * V_139 ,
struct V_688 * V_689 )
{
int V_121 ;
if ( V_689 -> V_15 )
return - V_584 ;
switch ( V_689 -> V_689 ) {
case V_539 :
V_139 -> V_5 . V_776 = V_689 -> args [ 0 ] ;
V_121 = 0 ;
break;
case V_541 : {
F_323 ( & V_139 -> V_749 ) ;
V_121 = - V_584 ;
if ( V_689 -> args [ 0 ] > V_777 )
goto V_778;
V_121 = - V_604 ;
if ( F_280 ( V_139 ) )
goto V_778;
if ( V_139 -> V_779 )
goto V_778;
V_121 = F_346 ( V_139 ) ;
if ( V_121 )
goto V_778;
F_195 () ;
V_139 -> V_5 . V_780 = V_781 ;
V_139 -> V_5 . V_782 = V_689 -> args [ 0 ] ;
V_121 = 0 ;
V_778:
F_325 ( & V_139 -> V_749 ) ;
break;
}
case V_561 :
V_121 = - V_584 ;
if ( V_689 -> args [ 0 ] & ~ V_562 )
break;
if ( V_689 -> args [ 0 ] & V_783 )
V_139 -> V_5 . V_784 = true ;
if ( V_689 -> args [ 0 ] & V_785 )
V_139 -> V_5 . V_786 = true ;
V_121 = 0 ;
break;
default:
V_121 = - V_584 ;
break;
}
return V_121 ;
}
long F_347 ( struct V_563 * V_564 ,
unsigned int V_565 , unsigned long V_566 )
{
struct V_139 * V_139 = V_564 -> V_690 ;
void T_14 * V_567 = ( void T_14 * ) V_566 ;
int V_121 = - V_787 ;
union {
struct V_750 V_751 ;
struct V_760 V_788 ;
struct V_789 V_790 ;
} V_693 ;
switch ( V_565 ) {
case V_791 :
V_121 = F_320 ( V_139 , V_566 ) ;
break;
case V_792 : {
T_2 V_730 ;
V_121 = - V_101 ;
if ( F_245 ( & V_730 , V_567 , sizeof V_730 ) )
goto V_113;
V_121 = F_321 ( V_139 , V_730 ) ;
break;
}
case V_793 :
V_121 = F_322 ( V_139 , V_566 ) ;
break;
case V_794 :
V_121 = F_326 ( V_139 ) ;
break;
case V_795 : {
F_323 ( & V_139 -> V_749 ) ;
V_121 = - V_604 ;
if ( F_280 ( V_139 ) )
goto V_796;
V_121 = - V_584 ;
if ( V_139 -> V_779 )
goto V_796;
V_121 = F_348 ( V_139 ) ;
if ( V_121 )
goto V_796;
V_121 = F_349 ( V_139 ) ;
if ( V_121 ) {
F_350 ( V_139 ) ;
goto V_796;
}
V_121 = F_351 ( V_139 ) ;
if ( V_121 ) {
F_352 ( V_139 ) ;
F_350 ( V_139 ) ;
goto V_796;
}
F_195 () ;
V_139 -> V_5 . V_780 = V_797 ;
V_796:
F_325 ( & V_139 -> V_749 ) ;
break;
}
case V_798 :
V_693 . V_790 . V_15 = V_799 ;
goto V_800;
case V_801 :
V_121 = - V_101 ;
if ( F_245 ( & V_693 . V_790 , V_567 ,
sizeof( struct V_789 ) ) )
goto V_113;
V_800:
F_323 ( & V_139 -> V_749 ) ;
V_121 = - V_604 ;
if ( V_139 -> V_5 . V_754 )
goto V_802;
V_121 = - V_388 ;
V_139 -> V_5 . V_754 = F_353 ( V_139 , V_693 . V_790 . V_15 ) ;
if ( V_139 -> V_5 . V_754 )
V_121 = 0 ;
V_802:
F_325 ( & V_139 -> V_749 ) ;
break;
case V_803 : {
struct V_737 * V_738 ;
V_738 = F_209 ( V_567 , sizeof( * V_738 ) ) ;
if ( F_210 ( V_738 ) ) {
V_121 = F_211 ( V_738 ) ;
goto V_113;
}
V_121 = - V_602 ;
if ( ! F_354 ( V_139 ) )
goto V_804;
V_121 = F_327 ( V_139 , V_738 ) ;
if ( V_121 )
goto V_804;
V_121 = - V_101 ;
if ( F_246 ( V_567 , V_738 , sizeof *V_738 ) )
goto V_804;
V_121 = 0 ;
V_804:
F_213 ( V_738 ) ;
break;
}
case V_805 : {
struct V_737 * V_738 ;
V_738 = F_209 ( V_567 , sizeof( * V_738 ) ) ;
if ( F_210 ( V_738 ) ) {
V_121 = F_211 ( V_738 ) ;
goto V_113;
}
V_121 = - V_602 ;
if ( ! F_354 ( V_139 ) )
goto V_806;
V_121 = F_329 ( V_139 , V_738 ) ;
if ( V_121 )
goto V_806;
V_121 = 0 ;
V_806:
F_213 ( V_738 ) ;
break;
}
case V_807 : {
V_121 = - V_101 ;
if ( F_245 ( & V_693 . V_751 , V_567 , sizeof( struct V_750 ) ) )
goto V_113;
V_121 = - V_602 ;
if ( ! V_139 -> V_5 . V_754 )
goto V_113;
V_121 = F_332 ( V_139 , & V_693 . V_751 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_246 ( V_567 , & V_693 . V_751 , sizeof( struct V_750 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_808 : {
V_121 = - V_101 ;
if ( F_245 ( & V_693 . V_751 , V_567 , sizeof V_693 . V_751 ) )
goto V_113;
V_121 = - V_602 ;
if ( ! V_139 -> V_5 . V_754 )
goto V_113;
V_121 = F_333 ( V_139 , & V_693 . V_751 ) ;
break;
}
case V_809 : {
V_121 = - V_602 ;
if ( ! V_139 -> V_5 . V_754 )
goto V_113;
V_121 = F_335 ( V_139 , & V_693 . V_788 ) ;
if ( V_121 )
goto V_113;
V_121 = - V_101 ;
if ( F_246 ( V_567 , & V_693 . V_788 , sizeof( V_693 . V_788 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_810 : {
V_121 = - V_101 ;
if ( F_245 ( & V_693 . V_788 , V_567 , sizeof( V_693 . V_788 ) ) )
goto V_113;
V_121 = - V_602 ;
if ( ! V_139 -> V_5 . V_754 )
goto V_113;
V_121 = F_336 ( V_139 , & V_693 . V_788 ) ;
break;
}
case V_811 : {
struct V_765 V_766 ;
V_121 = - V_101 ;
if ( F_245 ( & V_766 , V_567 , sizeof( V_766 ) ) )
goto V_113;
V_121 = F_337 ( V_139 , & V_766 ) ;
break;
}
case V_812 :
V_121 = 0 ;
F_323 ( & V_139 -> V_749 ) ;
if ( V_139 -> V_779 )
V_121 = - V_813 ;
else
V_139 -> V_5 . V_814 = V_566 ;
F_325 ( & V_139 -> V_749 ) ;
break;
case V_815 : {
V_121 = - V_101 ;
if ( F_245 ( & V_139 -> V_5 . F_208 , V_567 ,
sizeof( struct V_816 ) ) )
goto V_113;
V_121 = - V_584 ;
if ( V_139 -> V_5 . F_208 . V_15 )
goto V_113;
V_121 = 0 ;
break;
}
case V_817 : {
struct V_818 V_819 ;
T_2 V_820 ;
V_121 = - V_101 ;
if ( F_245 ( & V_819 , V_567 , sizeof( V_819 ) ) )
goto V_113;
V_121 = - V_584 ;
if ( V_819 . V_15 )
goto V_113;
V_121 = 0 ;
V_820 = F_185 ( V_139 ) ;
V_139 -> V_5 . V_249 += V_819 . clock - V_820 ;
F_182 ( V_139 ) ;
break;
}
case V_821 : {
struct V_818 V_819 ;
T_2 V_820 ;
V_820 = F_185 ( V_139 ) ;
V_819 . clock = V_820 ;
V_819 . V_15 = V_139 -> V_5 . V_297 ? V_544 : 0 ;
memset ( & V_819 . V_625 , 0 , sizeof( V_819 . V_625 ) ) ;
V_121 = - V_101 ;
if ( F_246 ( V_567 , & V_819 , sizeof( V_819 ) ) )
goto V_113;
V_121 = 0 ;
break;
}
case V_725 : {
struct V_688 V_689 ;
V_121 = - V_101 ;
if ( F_245 ( & V_689 , V_567 , sizeof( V_689 ) ) )
goto V_113;
V_121 = F_345 ( V_139 , & V_689 ) ;
break;
}
default:
V_121 = - V_787 ;
}
V_113:
return V_121 ;
}
static void F_355 ( void )
{
T_1 V_822 [ 2 ] ;
unsigned V_3 , V_823 ;
for ( V_3 = V_823 = 0 ; V_3 < F_55 ( V_575 ) ; V_3 ++ ) {
if ( F_356 ( V_575 [ V_3 ] , & V_822 [ 0 ] , & V_822 [ 1 ] ) < 0 )
continue;
switch ( V_575 [ V_3 ] ) {
case V_824 :
if ( ! V_87 -> V_825 () )
continue;
break;
case V_826 :
if ( ! V_87 -> V_827 () )
continue;
break;
default:
break;
}
if ( V_823 < V_3 )
V_575 [ V_823 ] = V_575 [ V_3 ] ;
V_823 ++ ;
}
V_572 = V_823 ;
for ( V_3 = V_823 = 0 ; V_3 < F_55 ( V_576 ) ; V_3 ++ ) {
switch ( V_576 [ V_3 ] ) {
case V_426 :
if ( ! V_87 -> V_547 () )
continue;
break;
default:
break;
}
if ( V_823 < V_3 )
V_576 [ V_823 ] = V_576 [ V_3 ] ;
V_823 ++ ;
}
V_573 = V_823 ;
}
static int F_357 ( struct V_1 * V_2 , T_6 V_620 , int V_95 ,
const void * V_267 )
{
int V_828 = 0 ;
int V_498 ;
do {
V_498 = F_358 ( V_95 , 8 ) ;
if ( ! ( F_91 ( V_2 ) &&
! F_359 ( V_2 , & V_2 -> V_5 . V_652 -> V_829 , V_620 , V_498 , V_267 ) )
&& F_360 ( V_2 , V_830 , V_620 , V_498 , V_267 ) )
break;
V_828 += V_498 ;
V_620 += V_498 ;
V_95 -= V_498 ;
V_267 += V_498 ;
} while ( V_95 );
return V_828 ;
}
static int F_361 ( struct V_1 * V_2 , T_6 V_620 , int V_95 , void * V_267 )
{
int V_828 = 0 ;
int V_498 ;
do {
V_498 = F_358 ( V_95 , 8 ) ;
if ( ! ( F_91 ( V_2 ) &&
! F_362 ( V_2 , & V_2 -> V_5 . V_652 -> V_829 ,
V_620 , V_498 , V_267 ) )
&& F_363 ( V_2 , V_830 , V_620 , V_498 , V_267 ) )
break;
F_364 ( V_831 , V_498 , V_620 , * ( T_2 * ) V_267 ) ;
V_828 += V_498 ;
V_620 += V_498 ;
V_95 -= V_498 ;
V_267 += V_498 ;
} while ( V_95 );
return V_828 ;
}
static void F_365 ( struct V_1 * V_2 ,
struct V_832 * V_833 , int V_834 )
{
V_87 -> V_835 ( V_2 , V_833 , V_834 ) ;
}
void F_366 ( struct V_1 * V_2 ,
struct V_832 * V_833 , int V_834 )
{
V_87 -> V_836 ( V_2 , V_833 , V_834 ) ;
}
T_6 F_367 ( struct V_1 * V_2 , T_6 V_390 , T_1 V_96 ,
struct V_74 * V_69 )
{
T_6 V_837 ;
F_15 ( ! F_42 ( V_2 ) ) ;
V_96 |= V_111 ;
V_837 = V_2 -> V_5 . V_83 . V_838 ( V_2 , V_390 , V_96 , V_69 ) ;
return V_837 ;
}
T_6 F_368 ( struct V_1 * V_2 , T_15 V_839 ,
struct V_74 * V_69 )
{
T_1 V_96 = ( V_87 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
return V_2 -> V_5 . V_103 -> V_838 ( V_2 , V_839 , V_96 , V_69 ) ;
}
T_6 F_369 ( struct V_1 * V_2 , T_15 V_839 ,
struct V_74 * V_69 )
{
T_1 V_96 = ( V_87 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
V_96 |= V_840 ;
return V_2 -> V_5 . V_103 -> V_838 ( V_2 , V_839 , V_96 , V_69 ) ;
}
T_6 F_370 ( struct V_1 * V_2 , T_15 V_839 ,
struct V_74 * V_69 )
{
T_1 V_96 = ( V_87 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
V_96 |= V_112 ;
return V_2 -> V_5 . V_103 -> V_838 ( V_2 , V_839 , V_96 , V_69 ) ;
}
T_6 F_371 ( struct V_1 * V_2 , T_15 V_839 ,
struct V_74 * V_69 )
{
return V_2 -> V_5 . V_103 -> V_838 ( V_2 , V_839 , 0 , V_69 ) ;
}
static int F_372 ( T_15 V_620 , void * V_196 , unsigned int V_841 ,
struct V_1 * V_2 , T_1 V_96 ,
struct V_74 * V_69 )
{
void * V_39 = V_196 ;
int V_121 = V_842 ;
while ( V_841 ) {
T_6 V_390 = V_2 -> V_5 . V_103 -> V_838 ( V_2 , V_620 , V_96 ,
V_69 ) ;
unsigned V_94 = V_620 & ( V_107 - 1 ) ;
unsigned V_843 = F_358 ( V_841 , ( unsigned ) V_107 - V_94 ) ;
int V_108 ;
if ( V_390 == V_100 )
return V_844 ;
V_108 = F_52 ( V_2 , V_390 >> V_106 , V_39 ,
V_94 , V_843 ) ;
if ( V_108 < 0 ) {
V_121 = V_845 ;
goto V_113;
}
V_841 -= V_843 ;
V_39 += V_843 ;
V_620 += V_843 ;
}
V_113:
return V_121 ;
}
static int F_373 ( struct V_846 * V_847 ,
T_15 V_620 , void * V_196 , unsigned int V_841 ,
struct V_74 * V_69 )
{
struct V_1 * V_2 = F_374 ( V_847 ) ;
T_1 V_96 = ( V_87 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
unsigned V_94 ;
int V_108 ;
T_6 V_390 = V_2 -> V_5 . V_103 -> V_838 ( V_2 , V_620 , V_96 | V_840 ,
V_69 ) ;
if ( F_171 ( V_390 == V_100 ) )
return V_844 ;
V_94 = V_620 & ( V_107 - 1 ) ;
if ( F_30 ( V_94 + V_841 > V_107 ) )
V_841 = ( unsigned ) V_107 - V_94 ;
V_108 = F_52 ( V_2 , V_390 >> V_106 , V_196 ,
V_94 , V_841 ) ;
if ( F_171 ( V_108 < 0 ) )
return V_845 ;
return V_842 ;
}
int F_375 ( struct V_846 * V_847 ,
T_15 V_620 , void * V_196 , unsigned int V_841 ,
struct V_74 * V_69 )
{
struct V_1 * V_2 = F_374 ( V_847 ) ;
T_1 V_96 = ( V_87 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 ;
return F_372 ( V_620 , V_196 , V_841 , V_2 , V_96 ,
V_69 ) ;
}
static int F_376 ( struct V_846 * V_847 ,
T_15 V_620 , void * V_196 , unsigned int V_841 ,
struct V_74 * V_69 )
{
struct V_1 * V_2 = F_374 ( V_847 ) ;
return F_372 ( V_620 , V_196 , V_841 , V_2 , 0 , V_69 ) ;
}
static int F_377 ( struct V_846 * V_847 ,
unsigned long V_620 , void * V_196 , unsigned int V_841 )
{
struct V_1 * V_2 = F_374 ( V_847 ) ;
int V_121 = F_378 ( V_2 , V_620 , V_196 , V_841 ) ;
return V_121 < 0 ? V_845 : V_842 ;
}
int F_379 ( struct V_846 * V_847 ,
T_15 V_620 , void * V_196 ,
unsigned int V_841 ,
struct V_74 * V_69 )
{
struct V_1 * V_2 = F_374 ( V_847 ) ;
void * V_39 = V_196 ;
int V_121 = V_842 ;
while ( V_841 ) {
T_6 V_390 = V_2 -> V_5 . V_103 -> V_838 ( V_2 , V_620 ,
V_112 ,
V_69 ) ;
unsigned V_94 = V_620 & ( V_107 - 1 ) ;
unsigned V_848 = F_358 ( V_841 , ( unsigned ) V_107 - V_94 ) ;
int V_108 ;
if ( V_390 == V_100 )
return V_844 ;
V_108 = F_212 ( V_2 , V_390 , V_39 , V_848 ) ;
if ( V_108 < 0 ) {
V_121 = V_845 ;
goto V_113;
}
V_841 -= V_848 ;
V_39 += V_848 ;
V_620 += V_848 ;
}
V_113:
return V_121 ;
}
static int F_380 ( struct V_1 * V_2 , unsigned long V_839 ,
T_6 V_390 , bool V_849 )
{
if ( ( V_390 & V_384 ) == V_850 )
return 1 ;
if ( F_381 ( V_2 , V_390 ) ) {
F_382 ( V_839 , V_390 , V_849 , true ) ;
return 1 ;
}
return 0 ;
}
static int F_383 ( struct V_1 * V_2 , unsigned long V_839 ,
T_6 * V_390 , struct V_74 * V_69 ,
bool V_849 )
{
T_1 V_96 = ( ( V_87 -> V_88 ( V_2 ) == 3 ) ? V_111 : 0 )
| ( V_849 ? V_112 : 0 ) ;
if ( F_384 ( V_2 , V_839 )
&& ! F_385 ( V_2 , V_2 -> V_5 . V_103 ,
V_2 -> V_5 . V_96 , 0 , V_96 ) ) {
* V_390 = V_2 -> V_5 . V_851 << V_106 |
( V_839 & ( V_107 - 1 ) ) ;
F_382 ( V_839 , * V_390 , V_849 , false ) ;
return 1 ;
}
* V_390 = V_2 -> V_5 . V_103 -> V_838 ( V_2 , V_839 , V_96 , V_69 ) ;
if ( * V_390 == V_100 )
return - 1 ;
return F_380 ( V_2 , V_839 , * V_390 , V_849 ) ;
}
int F_386 ( struct V_1 * V_2 , T_6 V_390 ,
const void * V_196 , int V_841 )
{
int V_108 ;
V_108 = F_212 ( V_2 , V_390 , V_196 , V_841 ) ;
if ( V_108 < 0 )
return 0 ;
F_387 ( V_2 , V_390 , V_196 , V_841 ) ;
return 1 ;
}
static int F_388 ( struct V_1 * V_2 , void * V_196 , int V_841 )
{
if ( V_2 -> V_852 ) {
F_364 ( V_831 , V_841 ,
V_2 -> V_853 [ 0 ] . V_390 , * ( T_2 * ) V_196 ) ;
V_2 -> V_852 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_389 ( struct V_1 * V_2 , T_6 V_390 ,
void * V_196 , int V_841 )
{
return ! F_378 ( V_2 , V_390 , V_196 , V_841 ) ;
}
static int F_390 ( struct V_1 * V_2 , T_6 V_390 ,
void * V_196 , int V_841 )
{
return F_386 ( V_2 , V_390 , V_196 , V_841 ) ;
}
static int F_391 ( struct V_1 * V_2 , T_6 V_390 , int V_841 , void * V_196 )
{
F_364 ( V_854 , V_841 , V_390 , * ( T_2 * ) V_196 ) ;
return F_357 ( V_2 , V_390 , V_841 , V_196 ) ;
}
static int F_392 ( struct V_1 * V_2 , T_6 V_390 ,
void * V_196 , int V_841 )
{
F_364 ( V_855 , V_841 , V_390 , 0 ) ;
return V_845 ;
}
static int F_393 ( struct V_1 * V_2 , T_6 V_390 ,
void * V_196 , int V_841 )
{
struct V_856 * V_857 = & V_2 -> V_853 [ 0 ] ;
memcpy ( V_2 -> V_858 -> V_859 . V_39 , V_857 -> V_39 , F_358 ( 8u , V_857 -> V_95 ) ) ;
return V_842 ;
}
static int F_394 ( unsigned long V_620 , void * V_196 ,
unsigned int V_841 ,
struct V_74 * V_69 ,
struct V_1 * V_2 ,
const struct V_860 * V_861 )
{
T_6 V_390 ;
int V_828 , V_108 ;
bool V_849 = V_861 -> V_849 ;
struct V_856 * V_857 ;
struct V_846 * V_847 = & V_2 -> V_5 . V_862 ;
if ( V_2 -> V_5 . V_863 &&
F_395 ( V_847 ) &&
F_380 ( V_2 , V_620 , V_69 -> V_79 , V_849 ) &&
( V_620 & ~ V_384 ) == ( V_69 -> V_79 & ~ V_384 ) ) {
V_390 = V_69 -> V_79 ;
goto V_859;
}
V_108 = F_383 ( V_2 , V_620 , & V_390 , V_69 , V_849 ) ;
if ( V_108 < 0 )
return V_844 ;
if ( V_108 )
goto V_859;
if ( V_861 -> V_864 ( V_2 , V_390 , V_196 , V_841 ) )
return V_842 ;
V_859:
V_828 = V_861 -> V_865 ( V_2 , V_390 , V_841 , V_196 ) ;
if ( V_828 == V_841 )
return V_842 ;
V_390 += V_828 ;
V_841 -= V_828 ;
V_196 += V_828 ;
F_30 ( V_2 -> V_866 >= V_867 ) ;
V_857 = & V_2 -> V_853 [ V_2 -> V_866 ++ ] ;
V_857 -> V_390 = V_390 ;
V_857 -> V_39 = V_196 ;
V_857 -> V_95 = V_841 ;
return V_842 ;
}
static int F_396 ( struct V_846 * V_847 ,
unsigned long V_620 ,
void * V_196 , unsigned int V_841 ,
struct V_74 * V_69 ,
const struct V_860 * V_861 )
{
struct V_1 * V_2 = F_374 ( V_847 ) ;
T_6 V_390 ;
int V_868 ;
if ( V_861 -> V_869 &&
V_861 -> V_869 ( V_2 , V_196 , V_841 ) )
return V_842 ;
V_2 -> V_866 = 0 ;
if ( ( ( V_620 + V_841 - 1 ) ^ V_620 ) & V_384 ) {
int V_870 ;
V_870 = - V_620 & ~ V_384 ;
V_868 = F_394 ( V_620 , V_196 , V_870 , V_69 ,
V_2 , V_861 ) ;
if ( V_868 != V_842 )
return V_868 ;
V_620 += V_870 ;
if ( V_847 -> V_331 != V_871 )
V_620 = ( T_1 ) V_620 ;
V_196 += V_870 ;
V_841 -= V_870 ;
}
V_868 = F_394 ( V_620 , V_196 , V_841 , V_69 ,
V_2 , V_861 ) ;
if ( V_868 != V_842 )
return V_868 ;
if ( ! V_2 -> V_866 )
return V_868 ;
V_390 = V_2 -> V_853 [ 0 ] . V_390 ;
V_2 -> V_872 = 1 ;
V_2 -> V_873 = 0 ;
V_2 -> V_858 -> V_859 . V_95 = F_358 ( 8u , V_2 -> V_853 [ 0 ] . V_95 ) ;
V_2 -> V_858 -> V_859 . V_874 = V_2 -> V_875 = V_861 -> V_849 ;
V_2 -> V_858 -> V_876 = V_877 ;
V_2 -> V_858 -> V_859 . V_878 = V_390 ;
return V_861 -> V_879 ( V_2 , V_390 , V_196 , V_841 ) ;
}
static int F_397 ( struct V_846 * V_847 ,
unsigned long V_620 ,
void * V_196 ,
unsigned int V_841 ,
struct V_74 * V_69 )
{
return F_396 ( V_847 , V_620 , V_196 , V_841 ,
V_69 , & V_880 ) ;
}
static int F_398 ( struct V_846 * V_847 ,
unsigned long V_620 ,
const void * V_196 ,
unsigned int V_841 ,
struct V_74 * V_69 )
{
return F_396 ( V_847 , V_620 , ( void * ) V_196 , V_841 ,
V_69 , & V_881 ) ;
}
static int F_399 ( struct V_846 * V_847 ,
unsigned long V_620 ,
const void * V_882 ,
const void * V_883 ,
unsigned int V_841 ,
struct V_74 * V_69 )
{
struct V_1 * V_2 = F_374 ( V_847 ) ;
T_6 V_390 ;
struct V_386 * V_386 ;
char * V_884 ;
bool V_885 ;
if ( V_841 > 8 || ( V_841 & ( V_841 - 1 ) ) )
goto V_886;
V_390 = F_370 ( V_2 , V_620 , NULL ) ;
if ( V_390 == V_100 ||
( V_390 & V_384 ) == V_850 )
goto V_886;
if ( ( ( V_390 + V_841 - 1 ) & V_384 ) != ( V_390 & V_384 ) )
goto V_886;
V_386 = F_400 ( V_2 , V_390 >> V_106 ) ;
if ( F_401 ( V_386 ) )
goto V_886;
V_884 = F_402 ( V_386 ) ;
V_884 += F_403 ( V_390 ) ;
switch ( V_841 ) {
case 1 :
V_885 = F_404 ( T_13 , V_884 , V_882 , V_883 ) ;
break;
case 2 :
V_885 = F_404 ( V_887 , V_884 , V_882 , V_883 ) ;
break;
case 4 :
V_885 = F_404 ( T_1 , V_884 , V_882 , V_883 ) ;
break;
case 8 :
V_885 = F_405 ( V_884 , V_882 , V_883 ) ;
break;
default:
F_27 () ;
}
F_406 ( V_884 ) ;
F_407 ( V_386 ) ;
if ( ! V_885 )
return V_888 ;
F_408 ( V_2 , V_390 >> V_106 ) ;
F_387 ( V_2 , V_390 , V_883 , V_841 ) ;
return V_842 ;
V_886:
F_409 ( V_889 L_20 ) ;
return F_398 ( V_847 , V_620 , V_883 , V_841 , V_69 ) ;
}
static int F_410 ( struct V_1 * V_2 , void * V_890 )
{
int V_121 = 0 , V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 . V_891 . V_759 ; V_3 ++ ) {
if ( V_2 -> V_5 . V_891 . V_892 )
V_121 = F_363 ( V_2 , V_893 , V_2 -> V_5 . V_891 . V_894 ,
V_2 -> V_5 . V_891 . V_499 , V_890 ) ;
else
V_121 = F_360 ( V_2 , V_893 ,
V_2 -> V_5 . V_891 . V_894 , V_2 -> V_5 . V_891 . V_499 ,
V_890 ) ;
if ( V_121 )
break;
V_890 += V_2 -> V_5 . V_891 . V_499 ;
}
return V_121 ;
}
static int F_411 ( struct V_1 * V_2 , int V_499 ,
unsigned short V_894 , void * V_196 ,
unsigned int V_759 , bool V_892 )
{
V_2 -> V_5 . V_891 . V_894 = V_894 ;
V_2 -> V_5 . V_891 . V_892 = V_892 ;
V_2 -> V_5 . V_891 . V_759 = V_759 ;
V_2 -> V_5 . V_891 . V_499 = V_499 ;
if ( ! F_410 ( V_2 , V_2 -> V_5 . V_895 ) ) {
V_2 -> V_5 . V_891 . V_759 = 0 ;
return 1 ;
}
V_2 -> V_858 -> V_876 = V_896 ;
V_2 -> V_858 -> V_897 . V_898 = V_892 ? V_899 : V_900 ;
V_2 -> V_858 -> V_897 . V_499 = V_499 ;
V_2 -> V_858 -> V_897 . V_901 = V_902 * V_107 ;
V_2 -> V_858 -> V_897 . V_759 = V_759 ;
V_2 -> V_858 -> V_897 . V_894 = V_894 ;
return 0 ;
}
static int F_412 ( struct V_846 * V_847 ,
int V_499 , unsigned short V_894 , void * V_196 ,
unsigned int V_759 )
{
struct V_1 * V_2 = F_374 ( V_847 ) ;
int V_108 ;
if ( V_2 -> V_5 . V_891 . V_759 )
goto V_903;
memset ( V_2 -> V_5 . V_895 , 0 , V_499 * V_759 ) ;
V_108 = F_411 ( V_2 , V_499 , V_894 , V_196 , V_759 , true ) ;
if ( V_108 ) {
V_903:
memcpy ( V_196 , V_2 -> V_5 . V_895 , V_499 * V_759 ) ;
F_413 ( V_904 , V_894 , V_499 , V_759 , V_2 -> V_5 . V_895 ) ;
V_2 -> V_5 . V_891 . V_759 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_414 ( struct V_846 * V_847 ,
int V_499 , unsigned short V_894 ,
const void * V_196 , unsigned int V_759 )
{
struct V_1 * V_2 = F_374 ( V_847 ) ;
memcpy ( V_2 -> V_5 . V_895 , V_196 , V_499 * V_759 ) ;
F_413 ( V_905 , V_894 , V_499 , V_759 , V_2 -> V_5 . V_895 ) ;
return F_411 ( V_2 , V_499 , V_894 , ( void * ) V_196 , V_759 , false ) ;
}
static unsigned long F_415 ( struct V_1 * V_2 , int V_834 )
{
return V_87 -> F_415 ( V_2 , V_834 ) ;
}
static void F_416 ( struct V_846 * V_847 , V_176 V_79 )
{
F_417 ( F_374 ( V_847 ) , V_79 ) ;
}
static int F_418 ( struct V_1 * V_2 )
{
if ( ! F_254 ( V_2 ) )
return V_842 ;
if ( V_87 -> V_586 () ) {
int V_24 = F_186 () ;
F_256 ( V_24 , V_2 -> V_5 . V_587 ) ;
F_419 ( V_2 -> V_5 . V_587 ,
F_252 , NULL , 1 ) ;
F_189 () ;
F_420 ( V_2 -> V_5 . V_587 ) ;
} else
F_253 () ;
return V_842 ;
}
int F_421 ( struct V_1 * V_2 )
{
F_418 ( V_2 ) ;
return F_38 ( V_2 ) ;
}
static void F_422 ( struct V_846 * V_847 )
{
F_418 ( F_374 ( V_847 ) ) ;
}
static int F_423 ( struct V_846 * V_847 , int V_89 ,
unsigned long * V_658 )
{
return F_102 ( F_374 ( V_847 ) , V_89 , V_658 ) ;
}
static int F_424 ( struct V_846 * V_847 , int V_89 ,
unsigned long V_23 )
{
return F_100 ( F_374 ( V_847 ) , V_89 , V_23 ) ;
}
static T_2 F_425 ( T_2 V_906 , T_1 V_907 )
{
return ( V_906 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_907 ;
}
static unsigned long F_426 ( struct V_846 * V_847 , int V_908 )
{
struct V_1 * V_2 = F_374 ( V_847 ) ;
unsigned long V_23 ;
switch ( V_908 ) {
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
F_427 ( L_21 , V_264 , V_908 ) ;
return 0 ;
}
return V_23 ;
}
static int F_428 ( struct V_846 * V_847 , int V_908 , V_176 V_196 )
{
struct V_1 * V_2 = F_374 ( V_847 ) ;
int V_909 = 0 ;
switch ( V_908 ) {
case 0 :
V_909 = F_62 ( V_2 , F_425 ( F_63 ( V_2 ) , V_196 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_78 = V_196 ;
break;
case 3 :
V_909 = F_87 ( V_2 , V_196 ) ;
break;
case 4 :
V_909 = F_79 ( V_2 , F_425 ( F_80 ( V_2 ) , V_196 ) ) ;
break;
case 8 :
V_909 = F_90 ( V_2 , V_196 ) ;
break;
default:
F_427 ( L_21 , V_264 , V_908 ) ;
V_909 = - 1 ;
}
return V_909 ;
}
static int F_429 ( struct V_846 * V_847 )
{
return V_87 -> V_88 ( F_374 ( V_847 ) ) ;
}
static void F_430 ( struct V_846 * V_847 , struct V_910 * V_911 )
{
V_87 -> V_912 ( F_374 ( V_847 ) , V_911 ) ;
}
static void F_431 ( struct V_846 * V_847 , struct V_910 * V_911 )
{
V_87 -> V_913 ( F_374 ( V_847 ) , V_911 ) ;
}
static void F_432 ( struct V_846 * V_847 , struct V_910 * V_911 )
{
V_87 -> V_914 ( F_374 ( V_847 ) , V_911 ) ;
}
static void F_433 ( struct V_846 * V_847 , struct V_910 * V_911 )
{
V_87 -> V_915 ( F_374 ( V_847 ) , V_911 ) ;
}
static unsigned long F_434 (
struct V_846 * V_847 , int V_834 )
{
return F_415 ( F_374 ( V_847 ) , V_834 ) ;
}
static bool F_435 ( struct V_846 * V_847 , V_887 * V_916 ,
struct V_917 * V_918 , T_1 * V_919 ,
int V_834 )
{
struct V_832 V_833 ;
F_366 ( F_374 ( V_847 ) , & V_833 , V_834 ) ;
* V_916 = V_833 . V_916 ;
if ( V_833 . V_920 ) {
memset ( V_918 , 0 , sizeof( * V_918 ) ) ;
if ( V_919 )
* V_919 = 0 ;
return false ;
}
if ( V_833 . V_921 )
V_833 . V_922 >>= 12 ;
F_436 ( V_918 , V_833 . V_922 ) ;
F_437 ( V_918 , ( unsigned long ) V_833 . V_230 ) ;
#ifdef F_64
if ( V_919 )
* V_919 = V_833 . V_230 >> 32 ;
#endif
V_918 -> type = V_833 . type ;
V_918 -> V_596 = V_833 . V_596 ;
V_918 -> V_923 = V_833 . V_923 ;
V_918 -> V_924 = V_833 . V_925 ;
V_918 -> V_926 = V_833 . V_926 ;
V_918 -> V_927 = V_833 . V_927 ;
V_918 -> V_928 = V_833 . V_183 ;
V_918 -> V_921 = V_833 . V_921 ;
return true ;
}
static void F_438 ( struct V_846 * V_847 , V_887 V_916 ,
struct V_917 * V_918 , T_1 V_919 ,
int V_834 )
{
struct V_1 * V_2 = F_374 ( V_847 ) ;
struct V_832 V_833 ;
V_833 . V_916 = V_916 ;
V_833 . V_230 = F_439 ( V_918 ) ;
#ifdef F_64
V_833 . V_230 |= ( ( T_2 ) V_919 ) << 32 ;
#endif
V_833 . V_922 = F_440 ( V_918 ) ;
if ( V_918 -> V_921 )
V_833 . V_922 = ( V_833 . V_922 << 12 ) | 0xfff ;
V_833 . type = V_918 -> type ;
V_833 . V_923 = V_918 -> V_923 ;
V_833 . V_183 = V_918 -> V_928 ;
V_833 . V_596 = V_918 -> V_596 ;
V_833 . V_927 = V_918 -> V_927 ;
V_833 . V_921 = V_918 -> V_921 ;
V_833 . V_926 = V_918 -> V_926 ;
V_833 . V_925 = V_918 -> V_924 ;
V_833 . V_920 = ! V_833 . V_925 ;
V_833 . V_929 = 0 ;
F_365 ( V_2 , & V_833 , V_834 ) ;
return;
}
static int F_441 ( struct V_846 * V_847 ,
T_1 V_930 , T_2 * V_471 )
{
struct V_33 V_22 ;
int V_121 ;
V_22 . V_147 = V_930 ;
V_22 . V_41 = false ;
V_121 = F_116 ( F_374 ( V_847 ) , & V_22 ) ;
if ( V_121 )
return V_121 ;
* V_471 = V_22 . V_39 ;
return 0 ;
}
static int F_442 ( struct V_846 * V_847 ,
T_1 V_930 , T_2 V_39 )
{
struct V_33 V_22 ;
V_22 . V_39 = V_39 ;
V_22 . V_147 = V_930 ;
V_22 . V_41 = false ;
return F_112 ( F_374 ( V_847 ) , & V_22 ) ;
}
static T_2 F_443 ( struct V_846 * V_847 )
{
struct V_1 * V_2 = F_374 ( V_847 ) ;
return V_2 -> V_5 . V_427 ;
}
static void F_444 ( struct V_846 * V_847 , T_2 V_427 )
{
struct V_1 * V_2 = F_374 ( V_847 ) ;
V_2 -> V_5 . V_427 = V_427 ;
}
static int F_445 ( struct V_846 * V_847 ,
T_1 V_931 )
{
return F_446 ( F_374 ( V_847 ) , V_931 ) ;
}
static int F_447 ( struct V_846 * V_847 ,
T_1 V_931 , T_2 * V_471 )
{
return F_105 ( F_374 ( V_847 ) , V_931 , V_471 ) ;
}
static void F_448 ( struct V_846 * V_847 )
{
F_374 ( V_847 ) -> V_5 . V_932 = 1 ;
}
static void F_449 ( struct V_846 * V_847 )
{
F_450 () ;
F_451 ( F_374 ( V_847 ) ) ;
}
static void F_452 ( struct V_846 * V_847 )
{
F_453 () ;
}
static int F_454 ( struct V_846 * V_847 ,
struct V_933 * V_934 ,
enum V_935 V_936 )
{
return V_87 -> V_937 ( F_374 ( V_847 ) , V_934 , V_936 ) ;
}
static void F_455 ( struct V_846 * V_847 ,
T_1 * V_938 , T_1 * V_939 , T_1 * V_201 , T_1 * V_209 )
{
V_701 ( F_374 ( V_847 ) , V_938 , V_939 , V_201 , V_209 ) ;
}
static V_176 F_456 ( struct V_846 * V_847 , unsigned V_940 )
{
return F_104 ( F_374 ( V_847 ) , V_940 ) ;
}
static void F_457 ( struct V_846 * V_847 , unsigned V_940 , V_176 V_196 )
{
F_106 ( F_374 ( V_847 ) , V_940 , V_196 ) ;
}
static void F_458 ( struct V_846 * V_847 , bool V_633 )
{
V_87 -> V_651 ( F_374 ( V_847 ) , V_633 ) ;
}
static unsigned F_459 ( struct V_846 * V_847 )
{
return F_374 ( V_847 ) -> V_5 . V_640 ;
}
static void F_460 ( struct V_846 * V_847 , unsigned V_941 )
{
F_295 ( F_374 ( V_847 ) , V_941 ) ;
}
static void F_461 ( struct V_1 * V_2 , T_1 V_29 )
{
T_1 V_942 = V_87 -> V_629 ( V_2 ) ;
if ( V_942 & V_29 )
V_29 = 0 ;
if ( F_171 ( V_942 || V_29 ) ) {
V_87 -> V_650 ( V_2 , V_29 ) ;
if ( ! V_29 )
F_32 ( V_68 , V_2 ) ;
}
}
static bool F_462 ( struct V_1 * V_2 )
{
struct V_846 * V_847 = & V_2 -> V_5 . V_862 ;
if ( V_847 -> V_69 . V_42 == V_43 )
return F_41 ( V_2 , & V_847 -> V_69 ) ;
if ( V_847 -> V_69 . V_943 )
F_40 ( V_2 , V_847 -> V_69 . V_42 ,
V_847 -> V_69 . V_63 ) ;
else
F_34 ( V_2 , V_847 -> V_69 . V_42 ) ;
return false ;
}
static void F_463 ( struct V_1 * V_2 )
{
struct V_846 * V_847 = & V_2 -> V_5 . V_862 ;
int V_134 , V_135 ;
V_87 -> V_136 ( V_2 , & V_134 , & V_135 ) ;
V_847 -> V_944 = F_464 ( V_2 ) ;
V_847 -> V_945 = ( V_847 -> V_944 & V_946 ) != 0 ;
V_847 -> V_947 = F_465 ( V_2 ) ;
V_847 -> V_331 = ( ! F_33 ( V_2 ) ) ? V_948 :
( V_847 -> V_944 & V_949 ) ? V_950 :
( V_135 && F_58 ( V_2 ) ) ? V_871 :
V_134 ? V_951 :
V_952 ;
F_192 ( V_953 != V_954 ) ;
F_192 ( V_653 != V_955 ) ;
F_192 ( V_641 != V_956 ) ;
F_466 ( V_847 ) ;
V_2 -> V_5 . V_957 = false ;
}
int F_467 ( struct V_1 * V_2 , int V_600 , int V_958 )
{
struct V_846 * V_847 = & V_2 -> V_5 . V_862 ;
int V_108 ;
F_463 ( V_2 ) ;
V_847 -> V_959 = 2 ;
V_847 -> V_960 = 2 ;
V_847 -> V_961 = V_847 -> V_947 + V_958 ;
V_108 = F_468 ( V_847 , V_600 ) ;
if ( V_108 != V_842 )
return V_962 ;
V_847 -> V_947 = V_847 -> V_961 ;
F_469 ( V_2 , V_847 -> V_947 ) ;
F_470 ( V_2 , V_847 -> V_944 ) ;
if ( V_600 == V_52 )
V_2 -> V_5 . V_632 = 0 ;
else
V_2 -> V_5 . V_626 . V_70 = false ;
return V_963 ;
}
static int F_471 ( struct V_1 * V_2 )
{
int V_121 = V_963 ;
++ V_2 -> V_76 . V_964 ;
F_472 ( V_2 ) ;
if ( ! F_294 ( V_2 ) && V_87 -> V_88 ( V_2 ) == 0 ) {
V_2 -> V_858 -> V_876 = V_965 ;
V_2 -> V_858 -> V_966 . V_967 = V_968 ;
V_2 -> V_858 -> V_966 . V_969 = 0 ;
V_121 = V_962 ;
}
F_34 ( V_2 , V_91 ) ;
return V_121 ;
}
static bool F_473 ( struct V_1 * V_2 , T_15 V_78 ,
bool V_970 ,
int V_971 )
{
T_6 V_390 = V_78 ;
T_16 V_972 ;
if ( V_971 & V_973 )
return false ;
if ( ! V_2 -> V_5 . V_83 . V_974 ) {
V_390 = F_370 ( V_2 , V_78 , NULL ) ;
if ( V_390 == V_100 )
return true ;
}
V_972 = F_474 ( V_2 -> V_139 , F_51 ( V_390 ) ) ;
if ( F_475 ( V_972 ) )
return false ;
F_476 ( V_972 ) ;
if ( V_2 -> V_5 . V_83 . V_974 ) {
unsigned int V_975 ;
F_161 ( & V_2 -> V_139 -> V_976 ) ;
V_975 = V_2 -> V_139 -> V_5 . V_975 ;
F_162 ( & V_2 -> V_139 -> V_976 ) ;
if ( V_975 )
F_477 ( V_2 -> V_139 , F_51 ( V_390 ) ) ;
return true ;
}
F_477 ( V_2 -> V_139 , F_51 ( V_390 ) ) ;
return ! V_970 ;
}
static bool F_478 ( struct V_846 * V_847 ,
unsigned long V_78 , int V_971 )
{
struct V_1 * V_2 = F_374 ( V_847 ) ;
unsigned long V_977 , V_978 , V_390 = V_78 ;
V_977 = V_2 -> V_5 . V_977 ;
V_978 = V_2 -> V_5 . V_978 ;
V_2 -> V_5 . V_977 = V_2 -> V_5 . V_978 = 0 ;
if ( ! ( V_971 & V_979 ) )
return false ;
if ( F_479 ( V_847 ) )
return false ;
if ( V_847 -> V_947 == V_977 && V_978 == V_78 )
return false ;
V_2 -> V_5 . V_977 = V_847 -> V_947 ;
V_2 -> V_5 . V_978 = V_78 ;
if ( ! V_2 -> V_5 . V_83 . V_974 )
V_390 = F_370 ( V_2 , V_78 , NULL ) ;
F_477 ( V_2 -> V_139 , F_51 ( V_390 ) ) ;
return true ;
}
static void F_480 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_640 & V_653 ) ) {
F_481 ( V_2 -> V_300 , V_2 -> V_5 . V_427 , false ) ;
F_32 ( V_68 , V_2 ) ;
}
F_67 ( V_2 ) ;
}
static void F_295 ( struct V_1 * V_2 , unsigned V_941 )
{
unsigned V_120 = V_2 -> V_5 . V_640 ^ V_941 ;
V_2 -> V_5 . V_640 = V_941 ;
if ( V_120 & V_653 )
F_480 ( V_2 ) ;
}
static int F_482 ( unsigned long V_620 , T_1 type , T_1 V_188 ,
unsigned long * V_183 )
{
T_1 V_187 = 0 ;
int V_3 ;
T_1 V_980 , V_981 ;
V_980 = V_188 ;
V_981 = V_188 >> 16 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ , V_980 >>= 2 , V_981 >>= 4 )
if ( ( V_980 & 3 ) && ( V_981 & 15 ) == type && V_183 [ V_3 ] == V_620 )
V_187 |= ( 1 << V_3 ) ;
return V_187 ;
}
static void F_483 ( struct V_1 * V_2 , int * V_121 )
{
struct V_982 * V_982 = V_2 -> V_858 ;
if ( V_2 -> V_179 & V_983 ) {
V_982 -> V_984 . V_5 . V_187 = V_985 | V_194 | V_195 ;
V_982 -> V_984 . V_5 . V_986 = V_2 -> V_5 . V_987 ;
V_982 -> V_984 . V_5 . V_69 = V_54 ;
V_982 -> V_876 = V_988 ;
* V_121 = V_989 ;
} else {
V_2 -> V_5 . V_187 &= ~ 15 ;
V_2 -> V_5 . V_187 |= V_985 | V_195 ;
F_34 ( V_2 , V_54 ) ;
}
}
int F_38 ( struct V_1 * V_2 )
{
unsigned long V_990 = V_87 -> V_991 ( V_2 ) ;
int V_121 = V_963 ;
V_87 -> V_992 ( V_2 ) ;
if ( F_171 ( V_990 & V_946 ) )
F_483 ( V_2 , & V_121 ) ;
return V_121 == V_963 ;
}
static bool F_484 ( struct V_1 * V_2 , int * V_121 )
{
if ( F_171 ( V_2 -> V_179 & V_180 ) &&
( V_2 -> V_5 . V_189 & V_192 ) ) {
struct V_982 * V_982 = V_2 -> V_858 ;
unsigned long V_947 = F_485 ( V_2 ) ;
T_1 V_187 = F_482 ( V_947 , 0 ,
V_2 -> V_5 . V_189 ,
V_2 -> V_5 . V_182 ) ;
if ( V_187 != 0 ) {
V_982 -> V_984 . V_5 . V_187 = V_187 | V_194 | V_195 ;
V_982 -> V_984 . V_5 . V_986 = V_947 ;
V_982 -> V_984 . V_5 . V_69 = V_54 ;
V_982 -> V_876 = V_988 ;
* V_121 = V_989 ;
return true ;
}
}
if ( F_171 ( V_2 -> V_5 . V_188 & V_192 ) &&
! ( F_464 ( V_2 ) & V_993 ) ) {
unsigned long V_947 = F_485 ( V_2 ) ;
T_1 V_187 = F_482 ( V_947 , 0 ,
V_2 -> V_5 . V_188 ,
V_2 -> V_5 . V_183 ) ;
if ( V_187 != 0 ) {
V_2 -> V_5 . V_187 &= ~ 15 ;
V_2 -> V_5 . V_187 |= V_187 | V_195 ;
F_34 ( V_2 , V_54 ) ;
* V_121 = V_963 ;
return true ;
}
}
return false ;
}
int F_486 ( struct V_1 * V_2 ,
unsigned long V_78 ,
int V_971 ,
void * V_994 ,
int V_995 )
{
int V_121 ;
struct V_846 * V_847 = & V_2 -> V_5 . V_862 ;
bool V_497 = true ;
bool V_996 = V_2 -> V_5 . V_970 ;
V_2 -> V_5 . V_970 = false ;
F_487 ( V_2 ) ;
if ( ! ( V_971 & V_997 ) ) {
F_463 ( V_2 ) ;
if ( F_484 ( V_2 , & V_121 ) )
return V_121 ;
V_847 -> V_998 = 0 ;
V_847 -> V_999 = false ;
V_847 -> V_69 . V_42 = - 1 ;
V_847 -> V_1000 = false ;
V_847 -> V_1001 = V_971 & V_1002 ;
V_121 = F_488 ( V_847 , V_994 , V_995 ) ;
F_489 ( V_2 ) ;
++ V_2 -> V_76 . V_1003 ;
if ( V_121 != V_1004 ) {
if ( V_971 & V_1002 )
return V_962 ;
if ( F_473 ( V_2 , V_78 , V_996 ,
V_971 ) )
return V_963 ;
if ( V_971 & V_1005 )
return V_962 ;
return F_471 ( V_2 ) ;
}
}
if ( V_971 & V_1005 ) {
F_469 ( V_2 , V_847 -> V_961 ) ;
if ( V_847 -> V_944 & V_993 )
F_470 ( V_2 , V_847 -> V_944 & ~ V_993 ) ;
return V_963 ;
}
if ( F_478 ( V_847 , V_78 , V_971 ) )
return V_963 ;
if ( V_2 -> V_5 . V_957 ) {
V_2 -> V_5 . V_957 = false ;
F_490 ( V_847 ) ;
}
V_1006:
V_847 -> V_69 . V_79 = V_78 ;
V_121 = F_491 ( V_847 ) ;
if ( V_121 == V_1007 )
return V_963 ;
if ( V_121 == V_1008 ) {
if ( F_473 ( V_2 , V_78 , V_996 ,
V_971 ) )
return V_963 ;
return F_471 ( V_2 ) ;
}
if ( V_847 -> V_999 ) {
V_121 = V_963 ;
if ( F_462 ( V_2 ) )
return V_121 ;
} else if ( V_2 -> V_5 . V_891 . V_759 ) {
if ( ! V_2 -> V_5 . V_891 . V_892 ) {
V_2 -> V_5 . V_891 . V_759 = 0 ;
} else {
V_497 = false ;
V_2 -> V_5 . V_1009 = V_1010 ;
}
V_121 = V_989 ;
} else if ( V_2 -> V_872 ) {
if ( ! V_2 -> V_875 )
V_497 = false ;
V_121 = V_989 ;
V_2 -> V_5 . V_1009 = V_1011 ;
} else if ( V_121 == V_1012 )
goto V_1006;
else
V_121 = V_963 ;
if ( V_497 ) {
unsigned long V_990 = V_87 -> V_991 ( V_2 ) ;
F_461 ( V_2 , V_847 -> V_998 ) ;
V_2 -> V_5 . V_1013 = false ;
F_469 ( V_2 , V_847 -> V_947 ) ;
if ( V_121 == V_963 &&
( V_847 -> V_945 || ( V_2 -> V_179 & V_983 ) ) )
F_483 ( V_2 , & V_121 ) ;
if ( ! V_847 -> V_999 ||
F_29 ( V_847 -> V_69 . V_42 ) == V_57 )
F_492 ( V_2 , V_847 -> V_944 ) ;
if ( F_171 ( ( V_847 -> V_944 & ~ V_990 ) & V_1014 ) )
F_32 ( V_68 , V_2 ) ;
} else
V_2 -> V_5 . V_1013 = true ;
return V_121 ;
}
int F_493 ( struct V_1 * V_2 , int V_499 , unsigned short V_894 )
{
unsigned long V_196 = F_104 ( V_2 , V_203 ) ;
int V_108 = F_414 ( & V_2 -> V_5 . V_862 ,
V_499 , V_894 , & V_196 , 1 ) ;
V_2 -> V_5 . V_891 . V_759 = 0 ;
return V_108 ;
}
static int F_494 ( struct V_1 * V_2 )
{
unsigned long V_196 ;
F_15 ( V_2 -> V_5 . V_891 . V_759 != 1 ) ;
V_196 = ( V_2 -> V_5 . V_891 . V_499 < 4 ) ? F_104 ( V_2 , V_203 )
: 0 ;
F_412 ( & V_2 -> V_5 . V_862 , V_2 -> V_5 . V_891 . V_499 ,
V_2 -> V_5 . V_891 . V_894 , & V_196 , 1 ) ;
F_106 ( V_2 , V_203 , V_196 ) ;
return 1 ;
}
int F_495 ( struct V_1 * V_2 , int V_499 , unsigned short V_894 )
{
unsigned long V_196 ;
int V_108 ;
V_196 = ( V_499 < 4 ) ? F_104 ( V_2 , V_203 ) : 0 ;
V_108 = F_412 ( & V_2 -> V_5 . V_862 , V_499 , V_894 ,
& V_196 , 1 ) ;
if ( V_108 ) {
F_106 ( V_2 , V_203 , V_196 ) ;
return V_108 ;
}
V_2 -> V_5 . V_1009 = F_494 ;
return 0 ;
}
static int F_496 ( unsigned int V_24 )
{
F_497 ( V_345 , 0 ) ;
return 0 ;
}
static void F_498 ( void * V_39 )
{
struct V_1015 * V_1016 = V_39 ;
unsigned long V_265 = 0 ;
if ( V_39 )
V_265 = V_1016 -> V_883 ;
else if ( ! F_249 ( V_1017 ) )
V_265 = F_499 ( F_500 () ) ;
if ( ! V_265 )
V_265 = V_274 ;
F_497 ( V_345 , V_265 ) ;
}
static int F_501 ( struct V_1018 * V_1019 , unsigned long V_196 ,
void * V_39 )
{
struct V_1015 * V_1016 = V_39 ;
struct V_139 * V_139 ;
struct V_1 * V_2 ;
int V_3 , V_1020 = 0 ;
if ( V_196 == V_1021 && V_1016 -> V_882 > V_1016 -> V_883 )
return 0 ;
if ( V_196 == V_1022 && V_1016 -> V_882 < V_1016 -> V_883 )
return 0 ;
F_257 ( V_1016 -> V_24 , F_498 , V_1016 , 1 ) ;
F_161 ( & V_1023 ) ;
F_502 (kvm, &vm_list, vm_list) {
F_183 (i, vcpu, kvm) {
if ( V_2 -> V_24 != V_1016 -> V_24 )
continue;
F_32 ( V_340 , V_2 ) ;
if ( V_2 -> V_24 != F_10 () )
V_1020 = 1 ;
}
}
F_162 ( & V_1023 ) ;
if ( V_1016 -> V_882 < V_1016 -> V_883 && V_1020 ) {
F_257 ( V_1016 -> V_24 , F_498 , V_1016 , 1 ) ;
}
return 0 ;
}
static int F_503 ( unsigned int V_24 )
{
F_498 ( NULL ) ;
return 0 ;
}
static void F_504 ( void )
{
V_1024 = V_274 ;
if ( ! F_249 ( V_1017 ) ) {
#ifdef F_505
struct V_1025 V_1026 ;
int V_24 ;
memset ( & V_1026 , 0 , sizeof( V_1026 ) ) ;
V_24 = F_186 () ;
F_506 ( & V_1026 , V_24 ) ;
if ( V_1026 . V_1027 . V_1028 )
V_1024 = V_1026 . V_1027 . V_1028 ;
F_189 () ;
#endif
F_507 ( & V_1029 ,
V_1030 ) ;
}
F_133 ( L_22 , V_1024 ) ;
F_508 ( V_1031 , L_23 ,
F_503 , F_496 ) ;
}
int F_509 ( void )
{
return F_187 ( V_1032 ) != NULL ;
}
static int F_510 ( void )
{
int V_1033 = 3 ;
if ( F_187 ( V_1032 ) )
V_1033 = V_87 -> V_88 ( F_187 ( V_1032 ) ) ;
return V_1033 != 0 ;
}
static unsigned long F_511 ( void )
{
unsigned long V_1034 = 0 ;
if ( F_187 ( V_1032 ) )
V_1034 = F_465 ( F_187 ( V_1032 ) ) ;
return V_1034 ;
}
void F_512 ( struct V_1 * V_2 )
{
F_497 ( V_1032 , V_2 ) ;
}
void F_513 ( struct V_1 * V_2 )
{
F_497 ( V_1032 , NULL ) ;
}
static void F_514 ( void )
{
T_2 V_29 ;
int V_1035 = V_1036 . V_1037 ;
V_29 = F_515 ( V_1035 , 51 ) ;
V_29 |= 1ull ;
#ifdef F_64
if ( V_1035 == 52 )
V_29 &= ~ 1ull ;
#endif
F_516 ( V_29 ) ;
}
static void F_517 ( struct V_358 * V_359 )
{
struct V_139 * V_139 ;
struct V_1 * V_2 ;
int V_3 ;
F_161 ( & V_1023 ) ;
F_502 (kvm, &vm_list, vm_list)
F_183 (i, vcpu, kvm)
F_32 ( V_299 , V_2 ) ;
F_178 ( & V_338 , 0 ) ;
F_162 ( & V_1023 ) ;
}
static int F_518 ( struct V_1018 * V_1019 , unsigned long V_1038 ,
void * V_1039 )
{
struct V_226 * V_294 = & V_226 ;
struct V_224 * V_225 = V_1039 ;
F_118 ( V_225 ) ;
if ( V_294 -> clock . V_233 != V_298 &&
F_144 ( & V_338 ) != 0 )
F_519 ( V_1040 , & V_1041 ) ;
return 0 ;
}
int F_520 ( void * V_1042 )
{
int V_121 ;
struct V_87 * V_861 = V_1042 ;
if ( V_87 ) {
F_12 ( V_27 L_24 ) ;
V_121 = - V_604 ;
goto V_113;
}
if ( ! V_861 -> V_1043 () ) {
F_12 ( V_27 L_25 ) ;
V_121 = - V_1044 ;
goto V_113;
}
if ( V_861 -> V_1045 () ) {
F_12 ( V_27 L_26 ) ;
V_121 = - V_1044 ;
goto V_113;
}
V_121 = - V_388 ;
V_26 = F_521 ( struct V_11 ) ;
if ( ! V_26 ) {
F_12 ( V_27 L_27 ) ;
goto V_113;
}
V_121 = F_522 () ;
if ( V_121 )
goto V_1046;
F_514 () ;
V_87 = V_861 ;
F_523 ( V_1047 , V_1048 ,
V_1049 , V_1050 , 0 ,
V_114 , 0 ) ;
F_504 () ;
F_524 ( & V_1051 ) ;
if ( F_249 ( V_559 ) )
V_146 = F_525 ( V_144 ) ;
F_526 () ;
#ifdef F_64
F_527 ( & V_1052 ) ;
#endif
return 0 ;
V_1046:
F_528 ( V_26 ) ;
V_113:
return V_121 ;
}
void F_529 ( void )
{
F_530 () ;
F_531 ( & V_1051 ) ;
if ( ! F_249 ( V_1017 ) )
F_532 ( & V_1029 ,
V_1030 ) ;
F_533 ( V_1031 ) ;
#ifdef F_64
F_534 ( & V_1052 ) ;
#endif
V_87 = NULL ;
F_535 () ;
F_528 ( V_26 ) ;
}
int F_536 ( struct V_1 * V_2 )
{
++ V_2 -> V_76 . V_1053 ;
if ( F_91 ( V_2 ) ) {
V_2 -> V_5 . V_648 = V_1054 ;
return 1 ;
} else {
V_2 -> V_858 -> V_876 = V_1055 ;
return 0 ;
}
}
int F_537 ( struct V_1 * V_2 )
{
int V_108 = F_38 ( V_2 ) ;
return F_536 ( V_2 ) && V_108 ;
}
static int F_538 ( struct V_1 * V_2 , T_6 V_1056 ,
unsigned long V_1057 )
{
struct V_1058 V_1059 ;
struct V_332 V_250 ;
T_2 V_1060 ;
int V_108 ;
if ( V_1057 != V_1061 )
return - V_1062 ;
if ( F_176 ( & V_250 , & V_1060 ) == false )
return - V_1062 ;
V_1059 . V_251 = V_250 . V_252 ;
V_1059 . V_253 = V_250 . V_254 ;
V_1059 . V_288 = F_152 ( V_2 , V_1060 ) ;
V_1059 . V_15 = 0 ;
V_108 = 0 ;
if ( F_126 ( V_2 -> V_139 , V_1056 , & V_1059 ,
sizeof( struct V_1058 ) ) )
V_108 = - V_1063 ;
return V_108 ;
}
static void F_539 ( struct V_139 * V_139 , unsigned long V_15 , int V_1064 )
{
struct V_1065 V_1066 ;
V_1066 . V_1067 = 0 ;
V_1066 . V_1068 = 0 ;
V_1066 . V_1069 = V_1064 ;
V_1066 . V_1070 = false ;
V_1066 . V_1071 = V_1072 ;
F_540 ( V_139 , NULL , & V_1066 , NULL ) ;
}
void F_541 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_598 = false ;
V_87 -> V_1073 ( V_2 ) ;
}
int F_542 ( struct V_1 * V_2 )
{
unsigned long V_18 , V_1074 , V_1075 , V_1076 , V_1077 , V_108 ;
int V_1078 , V_121 ;
V_121 = F_38 ( V_2 ) ;
if ( F_543 ( V_2 -> V_139 ) )
return F_544 ( V_2 ) ;
V_18 = F_104 ( V_2 , V_203 ) ;
V_1074 = F_104 ( V_2 , V_1079 ) ;
V_1075 = F_104 ( V_2 , V_202 ) ;
V_1076 = F_104 ( V_2 , V_204 ) ;
V_1077 = F_104 ( V_2 , V_1080 ) ;
F_545 ( V_18 , V_1074 , V_1075 , V_1076 , V_1077 ) ;
V_1078 = F_546 ( V_2 ) ;
if ( ! V_1078 ) {
V_18 &= 0xFFFFFFFF ;
V_1074 &= 0xFFFFFFFF ;
V_1075 &= 0xFFFFFFFF ;
V_1076 &= 0xFFFFFFFF ;
V_1077 &= 0xFFFFFFFF ;
}
if ( V_87 -> V_88 ( V_2 ) != 0 ) {
V_108 = - V_1081 ;
goto V_113;
}
switch ( V_18 ) {
case V_1082 :
V_108 = 0 ;
break;
case V_1083 :
F_539 ( V_2 -> V_139 , V_1074 , V_1075 ) ;
V_108 = 0 ;
break;
#ifdef F_64
case V_1084 :
V_108 = F_538 ( V_2 , V_1074 , V_1075 ) ;
break;
#endif
default:
V_108 = - V_1085 ;
break;
}
V_113:
if ( ! V_1078 )
V_108 = ( T_1 ) V_108 ;
F_106 ( V_2 , V_203 , V_108 ) ;
++ V_2 -> V_76 . V_1086 ;
return V_121 ;
}
static int F_547 ( struct V_846 * V_847 )
{
struct V_1 * V_2 = F_374 ( V_847 ) ;
char V_1087 [ 3 ] ;
unsigned long V_1088 = F_465 ( V_2 ) ;
V_87 -> V_1089 ( V_2 , V_1087 ) ;
return F_398 ( V_847 , V_1088 , V_1087 , 3 ,
& V_847 -> V_69 ) ;
}
static int F_548 ( struct V_1 * V_2 )
{
return V_2 -> V_858 -> V_1090 &&
F_167 ( ! F_282 ( V_2 -> V_139 ) ) ;
}
static void F_549 ( struct V_1 * V_2 )
{
struct V_982 * V_982 = V_2 -> V_858 ;
V_982 -> V_1091 = ( F_464 ( V_2 ) & V_1014 ) != 0 ;
V_982 -> V_15 = F_291 ( V_2 ) ? V_1092 : 0 ;
V_982 -> V_177 = F_93 ( V_2 ) ;
V_982 -> V_32 = F_21 ( V_2 ) ;
V_982 -> V_1093 =
F_282 ( V_2 -> V_139 ) ||
F_275 ( V_2 ) ;
}
static void F_272 ( struct V_1 * V_2 )
{
int V_1094 , V_1095 ;
if ( ! V_87 -> F_272 )
return;
if ( ! F_91 ( V_2 ) )
return;
if ( V_2 -> V_5 . V_598 )
return;
if ( ! V_2 -> V_5 . V_652 -> V_710 )
V_1094 = F_550 ( V_2 ) ;
else
V_1094 = - 1 ;
if ( V_1094 != - 1 )
V_1094 >>= 4 ;
V_1095 = F_94 ( V_2 ) ;
V_87 -> F_272 ( V_2 , V_1095 , V_1094 ) ;
}
static int F_551 ( struct V_1 * V_2 , bool V_1096 )
{
int V_121 ;
if ( V_2 -> V_5 . V_69 . V_70 ) {
F_552 ( V_2 -> V_5 . V_69 . V_18 ,
V_2 -> V_5 . V_69 . V_72 ,
V_2 -> V_5 . V_69 . V_63 ) ;
if ( F_29 ( V_2 -> V_5 . V_69 . V_18 ) == V_61 )
F_492 ( V_2 , F_464 ( V_2 ) |
V_993 ) ;
if ( V_2 -> V_5 . V_69 . V_18 == V_54 &&
( V_2 -> V_5 . V_188 & V_1097 ) ) {
V_2 -> V_5 . V_188 &= ~ V_1097 ;
F_97 ( V_2 ) ;
}
V_87 -> V_1098 ( V_2 , V_2 -> V_5 . V_69 . V_18 ,
V_2 -> V_5 . V_69 . V_72 ,
V_2 -> V_5 . V_69 . V_63 ,
V_2 -> V_5 . V_69 . V_64 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_631 ) {
V_87 -> V_1099 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_5 . V_626 . V_70 ) {
V_87 -> V_1100 ( V_2 ) ;
return 0 ;
}
if ( F_294 ( V_2 ) && V_87 -> V_1101 ) {
V_121 = V_87 -> V_1101 ( V_2 , V_1096 ) ;
if ( V_121 != 0 )
return V_121 ;
}
if ( V_2 -> V_5 . V_638 && ! F_291 ( V_2 ) ) {
V_2 -> V_5 . V_638 = false ;
F_553 ( V_2 ) ;
} else if ( V_2 -> V_5 . V_632 && V_87 -> V_1102 ( V_2 ) ) {
-- V_2 -> V_5 . V_632 ;
V_2 -> V_5 . V_631 = true ;
V_87 -> V_1099 ( V_2 ) ;
} else if ( F_554 ( V_2 ) ) {
if ( F_294 ( V_2 ) && V_87 -> V_1101 ) {
V_121 = V_87 -> V_1101 ( V_2 , V_1096 ) ;
if ( V_121 != 0 )
return V_121 ;
}
if ( V_87 -> V_1103 ( V_2 ) ) {
F_281 ( V_2 , F_555 ( V_2 ) ,
false ) ;
V_87 -> V_1100 ( V_2 ) ;
}
}
return 0 ;
}
static void F_289 ( struct V_1 * V_2 )
{
unsigned V_922 = 2 ;
if ( V_87 -> V_634 ( V_2 ) || V_2 -> V_5 . V_631 )
V_922 = 1 ;
V_2 -> V_5 . V_632 += F_556 ( & V_2 -> V_5 . V_84 , 0 ) ;
V_2 -> V_5 . V_632 = F_358 ( V_2 -> V_5 . V_632 , V_922 ) ;
F_32 ( V_68 , V_2 ) ;
}
static T_1 F_557 ( struct V_832 * V_834 )
{
T_1 V_15 = 0 ;
V_15 |= V_834 -> V_921 << 23 ;
V_15 |= V_834 -> V_183 << 22 ;
V_15 |= V_834 -> V_927 << 21 ;
V_15 |= V_834 -> V_926 << 20 ;
V_15 |= V_834 -> V_925 << 15 ;
V_15 |= V_834 -> V_923 << 13 ;
V_15 |= V_834 -> V_596 << 12 ;
V_15 |= V_834 -> type << 8 ;
return V_15 ;
}
static void F_558 ( struct V_1 * V_2 , char * V_1104 , int V_498 )
{
struct V_832 V_834 ;
int V_94 ;
F_366 ( V_2 , & V_834 , V_498 ) ;
F_559 ( T_1 , V_1104 , 0x7fa8 + V_498 * 4 , V_834 . V_916 ) ;
if ( V_498 < 3 )
V_94 = 0x7f84 + V_498 * 12 ;
else
V_94 = 0x7f2c + ( V_498 - 3 ) * 12 ;
F_559 ( T_1 , V_1104 , V_94 + 8 , V_834 . V_230 ) ;
F_559 ( T_1 , V_1104 , V_94 + 4 , V_834 . V_922 ) ;
F_559 ( T_1 , V_1104 , V_94 , F_557 ( & V_834 ) ) ;
}
static void F_560 ( struct V_1 * V_2 , char * V_1104 , int V_498 )
{
struct V_832 V_834 ;
int V_94 ;
V_887 V_15 ;
F_366 ( V_2 , & V_834 , V_498 ) ;
V_94 = 0x7e00 + V_498 * 16 ;
V_15 = F_557 ( & V_834 ) >> 8 ;
F_559 ( V_887 , V_1104 , V_94 , V_834 . V_916 ) ;
F_559 ( V_887 , V_1104 , V_94 + 2 , V_15 ) ;
F_559 ( T_1 , V_1104 , V_94 + 4 , V_834 . V_922 ) ;
F_559 ( T_2 , V_1104 , V_94 + 8 , V_834 . V_230 ) ;
}
static void F_561 ( struct V_1 * V_2 , char * V_1104 )
{
struct V_910 V_911 ;
struct V_832 V_834 ;
unsigned long V_196 ;
int V_3 ;
F_559 ( T_1 , V_1104 , 0x7ffc , F_63 ( V_2 ) ) ;
F_559 ( T_1 , V_1104 , 0x7ff8 , F_61 ( V_2 ) ) ;
F_559 ( T_1 , V_1104 , 0x7ff4 , F_464 ( V_2 ) ) ;
F_559 ( T_1 , V_1104 , 0x7ff0 , F_465 ( V_2 ) ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
F_559 ( T_1 , V_1104 , 0x7fd0 + V_3 * 4 , F_104 ( V_2 , V_3 ) ) ;
F_102 ( V_2 , 6 , & V_196 ) ;
F_559 ( T_1 , V_1104 , 0x7fcc , ( T_1 ) V_196 ) ;
F_102 ( V_2 , 7 , & V_196 ) ;
F_559 ( T_1 , V_1104 , 0x7fc8 , ( T_1 ) V_196 ) ;
F_366 ( V_2 , & V_834 , V_1105 ) ;
F_559 ( T_1 , V_1104 , 0x7fc4 , V_834 . V_916 ) ;
F_559 ( T_1 , V_1104 , 0x7f64 , V_834 . V_230 ) ;
F_559 ( T_1 , V_1104 , 0x7f60 , V_834 . V_922 ) ;
F_559 ( T_1 , V_1104 , 0x7f5c , F_557 ( & V_834 ) ) ;
F_366 ( V_2 , & V_834 , V_1106 ) ;
F_559 ( T_1 , V_1104 , 0x7fc0 , V_834 . V_916 ) ;
F_559 ( T_1 , V_1104 , 0x7f80 , V_834 . V_230 ) ;
F_559 ( T_1 , V_1104 , 0x7f7c , V_834 . V_922 ) ;
F_559 ( T_1 , V_1104 , 0x7f78 , F_557 ( & V_834 ) ) ;
V_87 -> V_912 ( V_2 , & V_911 ) ;
F_559 ( T_1 , V_1104 , 0x7f74 , V_911 . V_79 ) ;
F_559 ( T_1 , V_1104 , 0x7f70 , V_911 . V_499 ) ;
V_87 -> V_913 ( V_2 , & V_911 ) ;
F_559 ( T_1 , V_1104 , 0x7f58 , V_911 . V_79 ) ;
F_559 ( T_1 , V_1104 , 0x7f54 , V_911 . V_499 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_558 ( V_2 , V_1104 , V_3 ) ;
F_559 ( T_1 , V_1104 , 0x7f14 , F_80 ( V_2 ) ) ;
F_559 ( T_1 , V_1104 , 0x7efc , 0x00020000 ) ;
F_559 ( T_1 , V_1104 , 0x7ef8 , V_2 -> V_5 . V_427 ) ;
}
static void F_562 ( struct V_1 * V_2 , char * V_1104 )
{
#ifdef F_64
struct V_910 V_911 ;
struct V_832 V_834 ;
unsigned long V_196 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ )
F_559 ( T_2 , V_1104 , 0x7ff8 - V_3 * 8 , F_104 ( V_2 , V_3 ) ) ;
F_559 ( T_2 , V_1104 , 0x7f78 , F_465 ( V_2 ) ) ;
F_559 ( T_1 , V_1104 , 0x7f70 , F_464 ( V_2 ) ) ;
F_102 ( V_2 , 6 , & V_196 ) ;
F_559 ( T_2 , V_1104 , 0x7f68 , V_196 ) ;
F_102 ( V_2 , 7 , & V_196 ) ;
F_559 ( T_2 , V_1104 , 0x7f60 , V_196 ) ;
F_559 ( T_2 , V_1104 , 0x7f58 , F_63 ( V_2 ) ) ;
F_559 ( T_2 , V_1104 , 0x7f50 , F_61 ( V_2 ) ) ;
F_559 ( T_2 , V_1104 , 0x7f48 , F_80 ( V_2 ) ) ;
F_559 ( T_1 , V_1104 , 0x7f00 , V_2 -> V_5 . V_427 ) ;
F_559 ( T_1 , V_1104 , 0x7efc , 0x00020064 ) ;
F_559 ( T_2 , V_1104 , 0x7ed0 , V_2 -> V_5 . V_132 ) ;
F_366 ( V_2 , & V_834 , V_1105 ) ;
F_559 ( V_887 , V_1104 , 0x7e90 , V_834 . V_916 ) ;
F_559 ( V_887 , V_1104 , 0x7e92 , F_557 ( & V_834 ) >> 8 ) ;
F_559 ( T_1 , V_1104 , 0x7e94 , V_834 . V_922 ) ;
F_559 ( T_2 , V_1104 , 0x7e98 , V_834 . V_230 ) ;
V_87 -> V_913 ( V_2 , & V_911 ) ;
F_559 ( T_1 , V_1104 , 0x7e84 , V_911 . V_499 ) ;
F_559 ( T_2 , V_1104 , 0x7e88 , V_911 . V_79 ) ;
F_366 ( V_2 , & V_834 , V_1106 ) ;
F_559 ( V_887 , V_1104 , 0x7e70 , V_834 . V_916 ) ;
F_559 ( V_887 , V_1104 , 0x7e72 , F_557 ( & V_834 ) >> 8 ) ;
F_559 ( T_1 , V_1104 , 0x7e74 , V_834 . V_922 ) ;
F_559 ( T_2 , V_1104 , 0x7e78 , V_834 . V_230 ) ;
V_87 -> V_912 ( V_2 , & V_911 ) ;
F_559 ( T_1 , V_1104 , 0x7e64 , V_911 . V_499 ) ;
F_559 ( T_2 , V_1104 , 0x7e68 , V_911 . V_79 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
F_560 ( V_2 , V_1104 , V_3 ) ;
#else
F_563 ( 1 ) ;
#endif
}
static void F_553 ( struct V_1 * V_2 )
{
struct V_832 V_1107 , V_1108 ;
struct V_910 V_911 ;
char V_1104 [ 512 ] ;
T_1 V_122 ;
F_481 ( V_2 -> V_300 , V_2 -> V_5 . V_427 , true ) ;
V_2 -> V_5 . V_640 |= V_653 ;
memset ( V_1104 , 0 , 512 ) ;
if ( F_564 ( V_2 ) )
F_562 ( V_2 , V_1104 ) ;
else
F_561 ( V_2 , V_1104 ) ;
F_212 ( V_2 , V_2 -> V_5 . V_427 + 0xfe00 , V_1104 , sizeof( V_1104 ) ) ;
if ( V_87 -> V_634 ( V_2 ) )
V_2 -> V_5 . V_640 |= V_641 ;
else
V_87 -> V_651 ( V_2 , true ) ;
F_470 ( V_2 , V_1109 ) ;
F_469 ( V_2 , 0x8000 ) ;
V_122 = V_2 -> V_5 . V_122 & ~ ( V_131 | V_1110 | V_1111 | V_125 ) ;
V_87 -> V_138 ( V_2 , V_122 ) ;
V_2 -> V_5 . V_122 = V_122 ;
V_87 -> V_171 ( V_2 , 0 ) ;
V_911 . V_79 = V_911 . V_499 = 0 ;
V_87 -> V_915 ( V_2 , & V_911 ) ;
F_100 ( V_2 , 7 , V_199 ) ;
V_1107 . V_916 = ( V_2 -> V_5 . V_427 >> 4 ) & 0xffff ;
V_1107 . V_230 = V_2 -> V_5 . V_427 ;
V_1108 . V_916 = 0 ;
V_1108 . V_230 = 0 ;
V_1107 . V_922 = V_1108 . V_922 = 0xffffffff ;
V_1107 . type = V_1108 . type = 0x3 ;
V_1107 . V_923 = V_1108 . V_923 = 0 ;
V_1107 . V_183 = V_1108 . V_183 = 0 ;
V_1107 . V_596 = V_1108 . V_596 = 1 ;
V_1107 . V_927 = V_1108 . V_927 = 0 ;
V_1107 . V_921 = V_1108 . V_921 = 1 ;
V_1107 . V_926 = V_1108 . V_926 = 0 ;
V_1107 . V_925 = V_1108 . V_925 = 1 ;
V_1107 . V_920 = V_1108 . V_920 = 0 ;
V_1107 . V_929 = V_1108 . V_929 = 0 ;
F_365 ( V_2 , & V_1107 , V_1112 ) ;
F_365 ( V_2 , & V_1108 , V_1113 ) ;
F_365 ( V_2 , & V_1108 , V_1114 ) ;
F_365 ( V_2 , & V_1108 , V_1115 ) ;
F_365 ( V_2 , & V_1108 , V_1116 ) ;
F_365 ( V_2 , & V_1108 , V_1117 ) ;
if ( F_564 ( V_2 ) )
V_87 -> F_110 ( V_2 , 0 ) ;
F_77 ( V_2 ) ;
F_67 ( V_2 ) ;
}
static void F_565 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_638 = true ;
F_32 ( V_68 , V_2 ) ;
}
void F_566 ( struct V_139 * V_139 )
{
F_181 ( V_139 , V_1118 ) ;
}
static void F_567 ( struct V_1 * V_2 )
{
T_2 V_1119 [ 4 ] ;
if ( ! F_568 ( V_2 -> V_5 . V_652 ) )
return;
F_569 ( V_2 -> V_5 . V_1120 , 256 ) ;
if ( F_570 ( V_2 -> V_139 ) )
F_571 ( V_2 , V_2 -> V_5 . V_1120 ) ;
else {
if ( V_87 -> V_597 && V_2 -> V_5 . V_598 )
V_87 -> V_597 ( V_2 ) ;
F_572 ( V_2 , V_2 -> V_5 . V_1120 ) ;
}
F_573 ( ( V_176 * ) V_1119 , V_2 -> V_5 . V_1120 ,
F_574 ( V_2 ) -> V_1121 , 256 ) ;
V_87 -> V_1122 ( V_2 , V_1119 ) ;
}
static void F_575 ( struct V_1 * V_2 )
{
++ V_2 -> V_76 . V_1123 ;
V_87 -> V_1123 ( V_2 ) ;
}
void F_576 ( struct V_1 * V_2 )
{
struct V_386 * V_386 = NULL ;
if ( ! F_91 ( V_2 ) )
return;
if ( ! V_87 -> V_1124 )
return;
V_386 = F_577 ( V_2 -> V_139 , V_850 >> V_106 ) ;
if ( F_401 ( V_386 ) )
return;
V_87 -> V_1124 ( V_2 , F_578 ( V_386 ) ) ;
F_579 ( V_386 ) ;
}
void F_580 ( struct V_139 * V_139 ,
unsigned long V_79 )
{
if ( V_79 == F_581 ( V_139 , V_850 >> V_106 ) )
F_181 ( V_139 , V_1125 ) ;
}
static int F_582 ( struct V_1 * V_2 )
{
int V_121 ;
bool V_1096 =
F_548 ( V_2 ) &&
F_273 ( V_2 ) ;
bool V_1126 = false ;
if ( V_2 -> V_1127 ) {
if ( F_583 ( V_1128 , V_2 ) )
F_584 ( V_2 ) ;
if ( F_583 ( V_593 , V_2 ) )
F_585 ( V_2 ) ;
if ( F_583 ( V_299 , V_2 ) )
F_182 ( V_2 -> V_139 ) ;
if ( F_583 ( V_433 , V_2 ) )
F_203 ( V_2 ) ;
if ( F_583 ( V_340 , V_2 ) ) {
V_121 = F_197 ( V_2 ) ;
if ( F_171 ( V_121 ) )
goto V_113;
}
if ( F_583 ( V_1129 , V_2 ) )
F_88 ( V_2 ) ;
if ( F_583 ( V_173 , V_2 ) )
F_575 ( V_2 ) ;
if ( F_583 ( V_1130 , V_2 ) ) {
V_2 -> V_858 -> V_876 = V_1131 ;
V_121 = 0 ;
goto V_113;
}
if ( F_583 ( V_73 , V_2 ) ) {
V_2 -> V_858 -> V_876 = V_1132 ;
V_121 = 0 ;
goto V_113;
}
if ( F_583 ( V_1133 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1134 = true ;
V_121 = 1 ;
goto V_113;
}
if ( F_583 ( V_438 , V_2 ) )
F_218 ( V_2 ) ;
if ( F_583 ( V_605 , V_2 ) )
F_565 ( V_2 ) ;
if ( F_583 ( V_85 , V_2 ) )
F_289 ( V_2 ) ;
if ( F_583 ( V_1135 , V_2 ) )
F_586 ( V_2 ) ;
if ( F_583 ( V_1136 , V_2 ) )
F_587 ( V_2 ) ;
if ( F_583 ( V_1137 , V_2 ) ) {
F_15 ( V_2 -> V_5 . V_1138 > 255 ) ;
if ( F_60 ( V_2 -> V_5 . V_1138 ,
V_2 -> V_5 . V_1120 ) ) {
V_2 -> V_858 -> V_876 = V_1139 ;
V_2 -> V_858 -> V_1140 . V_42 =
V_2 -> V_5 . V_1138 ;
V_121 = 0 ;
goto V_113;
}
}
if ( F_583 ( V_1118 , V_2 ) )
F_567 ( V_2 ) ;
if ( F_583 ( V_1125 , V_2 ) )
F_576 ( V_2 ) ;
if ( F_583 ( V_1141 , V_2 ) ) {
V_2 -> V_858 -> V_876 = V_1142 ;
V_2 -> V_858 -> V_1143 . type = V_1144 ;
V_121 = 0 ;
goto V_113;
}
if ( F_583 ( V_1145 , V_2 ) ) {
V_2 -> V_858 -> V_876 = V_1142 ;
V_2 -> V_858 -> V_1143 . type = V_1146 ;
V_121 = 0 ;
goto V_113;
}
if ( F_583 ( V_1147 , V_2 ) ) {
V_2 -> V_858 -> V_876 = V_1148 ;
V_2 -> V_858 -> V_1149 = V_2 -> V_5 . V_1149 . exit ;
V_121 = 0 ;
goto V_113;
}
if ( F_583 ( V_1150 , V_2 ) )
F_588 ( V_2 ) ;
}
if ( F_583 ( V_68 , V_2 ) || V_1096 ) {
++ V_2 -> V_76 . V_1151 ;
F_589 ( V_2 ) ;
if ( V_2 -> V_5 . V_648 == V_649 ) {
V_121 = 1 ;
goto V_113;
}
if ( F_551 ( V_2 , V_1096 ) != 0 )
V_1126 = true ;
else {
if ( V_2 -> V_5 . V_638 && ! F_291 ( V_2 ) )
V_1126 = true ;
if ( V_2 -> V_5 . V_632 )
V_87 -> V_1152 ( V_2 ) ;
if ( F_554 ( V_2 ) || V_1096 )
V_87 -> V_1153 ( V_2 ) ;
}
if ( F_590 ( V_2 ) ) {
F_272 ( V_2 ) ;
F_591 ( V_2 ) ;
}
}
V_121 = F_592 ( V_2 ) ;
if ( F_171 ( V_121 ) ) {
goto V_1154;
}
F_450 () ;
V_87 -> V_1155 ( V_2 ) ;
F_451 ( V_2 ) ;
F_593 () ;
V_2 -> V_331 = V_1156 ;
F_243 ( & V_2 -> V_139 -> V_494 , V_2 -> V_1157 ) ;
F_594 () ;
if ( F_590 ( V_2 ) ) {
if ( V_87 -> V_597 && V_2 -> V_5 . V_598 )
V_87 -> V_597 ( V_2 ) ;
}
if ( V_2 -> V_331 == V_1158 || V_2 -> V_1127
|| F_595 () || F_596 ( V_401 ) ) {
V_2 -> V_331 = V_1159 ;
F_195 () ;
F_597 () ;
F_453 () ;
V_2 -> V_1157 = F_242 ( & V_2 -> V_139 -> V_494 ) ;
V_121 = 1 ;
goto V_1154;
}
F_73 ( V_2 ) ;
if ( V_1126 ) {
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
V_87 -> V_858 ( V_2 ) ;
if ( F_171 ( V_2 -> V_5 . V_184 & V_1160 ) ) {
F_30 ( V_2 -> V_179 & V_180 ) ;
V_87 -> V_1161 ( V_2 ) ;
F_95 ( V_2 ) ;
F_96 ( V_2 ) ;
F_97 ( V_2 ) ;
V_2 -> V_5 . V_184 &= ~ V_185 ;
}
if ( F_603 () )
F_604 () ;
V_2 -> V_5 . V_325 = F_152 ( V_2 , F_151 () ) ;
V_2 -> V_331 = V_1159 ;
F_195 () ;
F_75 ( V_2 ) ;
V_87 -> V_1162 ( V_2 ) ;
++ V_2 -> V_76 . V_1163 ;
F_605 () ;
F_597 () ;
F_453 () ;
V_2 -> V_1157 = F_242 ( & V_2 -> V_139 -> V_494 ) ;
if ( F_171 ( V_1164 == V_1165 ) ) {
unsigned long V_1088 = F_465 ( V_2 ) ;
F_606 ( V_1165 , ( void * ) V_1088 ) ;
}
if ( F_171 ( V_2 -> V_5 . V_276 ) )
F_32 ( V_340 , V_2 ) ;
if ( V_2 -> V_5 . V_1166 )
F_607 ( V_2 ) ;
V_121 = V_87 -> V_1167 ( V_2 ) ;
return V_121 ;
V_1154:
V_87 -> V_1154 ( V_2 ) ;
if ( F_171 ( V_2 -> V_5 . V_1166 ) )
F_607 ( V_2 ) ;
V_113:
return V_121 ;
}
static inline int F_608 ( struct V_139 * V_139 , struct V_1 * V_2 )
{
if ( ! F_609 ( V_2 ) &&
( ! V_87 -> V_1168 || V_87 -> V_1168 ( V_2 ) == 0 ) ) {
F_243 ( & V_139 -> V_494 , V_2 -> V_1157 ) ;
F_610 ( V_2 ) ;
V_2 -> V_1157 = F_242 ( & V_139 -> V_494 ) ;
if ( V_87 -> V_1169 )
V_87 -> V_1169 ( V_2 ) ;
if ( ! F_583 ( V_1170 , V_2 ) )
return 1 ;
}
F_589 ( V_2 ) ;
switch( V_2 -> V_5 . V_648 ) {
case V_1054 :
V_2 -> V_5 . V_1171 . V_1172 = false ;
V_2 -> V_5 . V_648 =
V_1173 ;
case V_1173 :
V_2 -> V_5 . V_6 . V_1134 = false ;
break;
case V_649 :
break;
default:
return - V_1174 ;
break;
}
return 1 ;
}
static inline bool F_611 ( struct V_1 * V_2 )
{
if ( F_294 ( V_2 ) && V_87 -> V_1101 )
V_87 -> V_1101 ( V_2 , false ) ;
return ( V_2 -> V_5 . V_648 == V_1173 &&
! V_2 -> V_5 . V_6 . V_1134 ) ;
}
static int F_612 ( struct V_1 * V_2 )
{
int V_121 ;
struct V_139 * V_139 = V_2 -> V_139 ;
V_2 -> V_1157 = F_242 ( & V_139 -> V_494 ) ;
for (; ; ) {
if ( F_611 ( V_2 ) ) {
V_121 = F_582 ( V_2 ) ;
} else {
V_121 = F_608 ( V_139 , V_2 ) ;
}
if ( V_121 <= 0 )
break;
F_184 ( V_242 , V_2 ) ;
if ( F_613 ( V_2 ) )
F_614 ( V_2 ) ;
if ( F_548 ( V_2 ) &&
F_275 ( V_2 ) ) {
V_121 = 0 ;
V_2 -> V_858 -> V_876 = V_1175 ;
++ V_2 -> V_76 . V_1176 ;
break;
}
F_615 ( V_2 ) ;
if ( F_596 ( V_401 ) ) {
V_121 = - V_1174 ;
V_2 -> V_858 -> V_876 = V_1177 ;
++ V_2 -> V_76 . V_1178 ;
break;
}
if ( F_595 () ) {
F_243 ( & V_139 -> V_494 , V_2 -> V_1157 ) ;
F_616 () ;
V_2 -> V_1157 = F_242 ( & V_139 -> V_494 ) ;
}
}
F_243 ( & V_139 -> V_494 , V_2 -> V_1157 ) ;
return V_121 ;
}
static inline int F_617 ( struct V_1 * V_2 )
{
int V_121 ;
V_2 -> V_1157 = F_242 ( & V_2 -> V_139 -> V_494 ) ;
V_121 = F_618 ( V_2 , V_997 ) ;
F_243 ( & V_2 -> V_139 -> V_494 , V_2 -> V_1157 ) ;
if ( V_121 != V_963 )
return 0 ;
return 1 ;
}
static int V_1010 ( struct V_1 * V_2 )
{
F_15 ( ! V_2 -> V_5 . V_891 . V_759 ) ;
return F_617 ( V_2 ) ;
}
static int V_1011 ( struct V_1 * V_2 )
{
struct V_982 * V_858 = V_2 -> V_858 ;
struct V_856 * V_857 ;
unsigned V_95 ;
F_15 ( ! V_2 -> V_872 ) ;
V_857 = & V_2 -> V_853 [ V_2 -> V_873 ] ;
V_95 = F_358 ( 8u , V_857 -> V_95 ) ;
if ( ! V_2 -> V_875 )
memcpy ( V_857 -> V_39 , V_858 -> V_859 . V_39 , V_95 ) ;
if ( V_857 -> V_95 <= 8 ) {
V_857 ++ ;
V_2 -> V_873 ++ ;
} else {
V_857 -> V_39 += V_95 ;
V_857 -> V_390 += V_95 ;
V_857 -> V_95 -= V_95 ;
}
if ( V_2 -> V_873 >= V_2 -> V_866 ) {
V_2 -> V_872 = 0 ;
if ( V_2 -> V_875 )
return 1 ;
V_2 -> V_852 = 1 ;
return F_617 ( V_2 ) ;
}
V_858 -> V_876 = V_877 ;
V_858 -> V_859 . V_878 = V_857 -> V_390 ;
if ( V_2 -> V_875 )
memcpy ( V_858 -> V_859 . V_39 , V_857 -> V_39 , F_358 ( 8u , V_857 -> V_95 ) ) ;
V_858 -> V_859 . V_95 = F_358 ( 8u , V_857 -> V_95 ) ;
V_858 -> V_859 . V_874 = V_2 -> V_875 ;
V_2 -> V_5 . V_1009 = V_1011 ;
return 0 ;
}
int F_619 ( struct V_1 * V_2 , struct V_982 * V_982 )
{
struct V_1179 * V_1179 = & V_401 -> V_1180 . V_1179 ;
int V_121 ;
T_17 V_1181 ;
F_620 ( V_1179 ) ;
if ( V_2 -> V_1182 )
F_621 ( V_1183 , & V_2 -> V_1184 , & V_1181 ) ;
if ( F_171 ( V_2 -> V_5 . V_648 == V_1185 ) ) {
F_610 ( V_2 ) ;
F_589 ( V_2 ) ;
F_184 ( V_1170 , V_2 ) ;
V_121 = - V_1186 ;
goto V_113;
}
if ( ! F_91 ( V_2 ) ) {
if ( F_90 ( V_2 , V_982 -> V_177 ) != 0 ) {
V_121 = - V_584 ;
goto V_113;
}
}
if ( F_171 ( V_2 -> V_5 . V_1009 ) ) {
int (* F_622)( struct V_1 * ) = V_2 -> V_5 . V_1009 ;
V_2 -> V_5 . V_1009 = NULL ;
V_121 = F_622 ( V_2 ) ;
if ( V_121 <= 0 )
goto V_113;
} else
F_30 ( V_2 -> V_5 . V_891 . V_759 || V_2 -> V_872 ) ;
if ( V_982 -> V_1187 )
V_121 = - V_1174 ;
else
V_121 = F_612 ( V_2 ) ;
V_113:
F_549 ( V_2 ) ;
if ( V_2 -> V_1182 )
F_621 ( V_1183 , & V_1181 , NULL ) ;
return V_121 ;
}
int F_623 ( struct V_1 * V_2 , struct V_1188 * V_1189 )
{
if ( V_2 -> V_5 . V_1013 ) {
F_624 ( & V_2 -> V_5 . V_862 ) ;
V_2 -> V_5 . V_1013 = false ;
}
V_1189 -> V_1190 = F_104 ( V_2 , V_203 ) ;
V_1189 -> V_1191 = F_104 ( V_2 , V_1079 ) ;
V_1189 -> V_1192 = F_104 ( V_2 , V_202 ) ;
V_1189 -> V_1193 = F_104 ( V_2 , V_204 ) ;
V_1189 -> V_1194 = F_104 ( V_2 , V_1080 ) ;
V_1189 -> V_1195 = F_104 ( V_2 , V_1196 ) ;
V_1189 -> V_1197 = F_104 ( V_2 , V_1198 ) ;
V_1189 -> V_1199 = F_104 ( V_2 , V_1200 ) ;
#ifdef F_64
V_1189 -> V_1201 = F_104 ( V_2 , V_1202 ) ;
V_1189 -> V_1203 = F_104 ( V_2 , V_1204 ) ;
V_1189 -> V_1205 = F_104 ( V_2 , V_1206 ) ;
V_1189 -> V_1207 = F_104 ( V_2 , V_1208 ) ;
V_1189 -> V_1209 = F_104 ( V_2 , V_1210 ) ;
V_1189 -> V_1211 = F_104 ( V_2 , V_1212 ) ;
V_1189 -> V_1213 = F_104 ( V_2 , V_1214 ) ;
V_1189 -> V_1215 = F_104 ( V_2 , V_1216 ) ;
#endif
V_1189 -> V_1088 = F_465 ( V_2 ) ;
V_1189 -> V_990 = F_464 ( V_2 ) ;
return 0 ;
}
int F_625 ( struct V_1 * V_2 , struct V_1188 * V_1189 )
{
V_2 -> V_5 . V_957 = true ;
V_2 -> V_5 . V_1013 = false ;
F_106 ( V_2 , V_203 , V_1189 -> V_1190 ) ;
F_106 ( V_2 , V_1079 , V_1189 -> V_1191 ) ;
F_106 ( V_2 , V_202 , V_1189 -> V_1192 ) ;
F_106 ( V_2 , V_204 , V_1189 -> V_1193 ) ;
F_106 ( V_2 , V_1080 , V_1189 -> V_1194 ) ;
F_106 ( V_2 , V_1196 , V_1189 -> V_1195 ) ;
F_106 ( V_2 , V_1198 , V_1189 -> V_1197 ) ;
F_106 ( V_2 , V_1200 , V_1189 -> V_1199 ) ;
#ifdef F_64
F_106 ( V_2 , V_1202 , V_1189 -> V_1201 ) ;
F_106 ( V_2 , V_1204 , V_1189 -> V_1203 ) ;
F_106 ( V_2 , V_1206 , V_1189 -> V_1205 ) ;
F_106 ( V_2 , V_1208 , V_1189 -> V_1207 ) ;
F_106 ( V_2 , V_1210 , V_1189 -> V_1209 ) ;
F_106 ( V_2 , V_1212 , V_1189 -> V_1211 ) ;
F_106 ( V_2 , V_1214 , V_1189 -> V_1213 ) ;
F_106 ( V_2 , V_1216 , V_1189 -> V_1215 ) ;
#endif
F_469 ( V_2 , V_1189 -> V_1088 ) ;
F_470 ( V_2 , V_1189 -> V_990 ) ;
V_2 -> V_5 . V_69 . V_70 = false ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
void F_626 ( struct V_1 * V_2 , int * V_183 , int * V_927 )
{
struct V_832 V_1107 ;
F_366 ( V_2 , & V_1107 , V_1112 ) ;
* V_183 = V_1107 . V_183 ;
* V_927 = V_1107 . V_927 ;
}
int F_627 ( struct V_1 * V_2 ,
struct V_1217 * V_1218 )
{
struct V_910 V_911 ;
F_366 ( V_2 , & V_1218 -> V_1107 , V_1112 ) ;
F_366 ( V_2 , & V_1218 -> V_1108 , V_1113 ) ;
F_366 ( V_2 , & V_1218 -> V_1219 , V_1114 ) ;
F_366 ( V_2 , & V_1218 -> V_1220 , V_1115 ) ;
F_366 ( V_2 , & V_1218 -> V_1221 , V_1116 ) ;
F_366 ( V_2 , & V_1218 -> V_1222 , V_1117 ) ;
F_366 ( V_2 , & V_1218 -> V_1223 , V_1105 ) ;
F_366 ( V_2 , & V_1218 -> V_1224 , V_1106 ) ;
V_87 -> V_913 ( V_2 , & V_911 ) ;
V_1218 -> V_1225 . V_922 = V_911 . V_499 ;
V_1218 -> V_1225 . V_230 = V_911 . V_79 ;
V_87 -> V_912 ( V_2 , & V_911 ) ;
V_1218 -> V_1226 . V_922 = V_911 . V_499 ;
V_1218 -> V_1226 . V_230 = V_911 . V_79 ;
V_1218 -> V_122 = F_63 ( V_2 ) ;
V_1218 -> V_78 = V_2 -> V_5 . V_78 ;
V_1218 -> V_104 = F_61 ( V_2 ) ;
V_1218 -> V_159 = F_80 ( V_2 ) ;
V_1218 -> V_177 = F_93 ( V_2 ) ;
V_1218 -> V_132 = V_2 -> V_5 . V_132 ;
V_1218 -> V_32 = F_21 ( V_2 ) ;
memset ( V_1218 -> V_1227 , 0 , sizeof V_1218 -> V_1227 ) ;
if ( V_2 -> V_5 . V_626 . V_70 && ! V_2 -> V_5 . V_626 . V_627 )
F_296 ( V_2 -> V_5 . V_626 . V_18 ,
( unsigned long * ) V_1218 -> V_1227 ) ;
return 0 ;
}
int F_628 ( struct V_1 * V_2 ,
struct V_1228 * V_648 )
{
F_589 ( V_2 ) ;
if ( V_2 -> V_5 . V_648 == V_1054 &&
V_2 -> V_5 . V_1171 . V_1172 )
V_648 -> V_648 = V_1173 ;
else
V_648 -> V_648 = V_2 -> V_5 . V_648 ;
return 0 ;
}
int F_629 ( struct V_1 * V_2 ,
struct V_1228 * V_648 )
{
if ( ! F_91 ( V_2 ) &&
V_648 -> V_648 != V_1173 )
return - V_584 ;
if ( ( F_291 ( V_2 ) || V_2 -> V_5 . V_638 ) &&
( V_648 -> V_648 == V_1229 ||
V_648 -> V_648 == V_649 ) )
return - V_584 ;
if ( V_648 -> V_648 == V_1229 ) {
V_2 -> V_5 . V_648 = V_649 ;
F_296 ( V_1230 , & V_2 -> V_5 . V_652 -> V_655 ) ;
} else
V_2 -> V_5 . V_648 = V_648 -> V_648 ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
int F_630 ( struct V_1 * V_2 , V_887 V_1231 , int V_1232 ,
int V_1233 , bool V_72 , T_1 V_63 )
{
struct V_846 * V_847 = & V_2 -> V_5 . V_862 ;
int V_108 ;
F_463 ( V_2 ) ;
V_108 = F_631 ( V_847 , V_1231 , V_1232 , V_1233 ,
V_72 , V_63 ) ;
if ( V_108 )
return V_962 ;
F_469 ( V_2 , V_847 -> V_947 ) ;
F_470 ( V_2 , V_847 -> V_944 ) ;
F_32 ( V_68 , V_2 ) ;
return V_963 ;
}
int F_632 ( struct V_1 * V_2 ,
struct V_1217 * V_1218 )
{
struct V_33 V_1234 ;
int V_1235 = 0 ;
int V_1236 , V_1237 , V_493 ;
struct V_910 V_911 ;
if ( ! F_81 ( V_2 ) && ( V_1218 -> V_159 & V_142 ) )
return - V_584 ;
V_911 . V_499 = V_1218 -> V_1225 . V_922 ;
V_911 . V_79 = V_1218 -> V_1225 . V_230 ;
V_87 -> V_915 ( V_2 , & V_911 ) ;
V_911 . V_499 = V_1218 -> V_1226 . V_922 ;
V_911 . V_79 = V_1218 -> V_1226 . V_230 ;
V_87 -> V_914 ( V_2 , & V_911 ) ;
V_2 -> V_5 . V_78 = V_1218 -> V_78 ;
V_1235 |= F_61 ( V_2 ) != V_1218 -> V_104 ;
V_2 -> V_5 . V_104 = V_1218 -> V_104 ;
F_56 ( V_175 , ( V_176 * ) & V_2 -> V_5 . V_118 ) ;
F_90 ( V_2 , V_1218 -> V_177 ) ;
V_1235 |= V_2 -> V_5 . V_132 != V_1218 -> V_132 ;
V_87 -> F_110 ( V_2 , V_1218 -> V_132 ) ;
V_1234 . V_39 = V_1218 -> V_32 ;
V_1234 . V_41 = true ;
F_22 ( V_2 , & V_1234 ) ;
V_1235 |= F_63 ( V_2 ) != V_1218 -> V_122 ;
V_87 -> V_138 ( V_2 , V_1218 -> V_122 ) ;
V_2 -> V_5 . V_122 = V_1218 -> V_122 ;
V_1235 |= F_80 ( V_2 ) != V_1218 -> V_159 ;
V_87 -> V_171 ( V_2 , V_1218 -> V_159 ) ;
if ( V_1218 -> V_159 & ( V_142 | V_167 ) )
F_77 ( V_2 ) ;
V_493 = F_242 ( & V_2 -> V_139 -> V_494 ) ;
if ( ! F_58 ( V_2 ) && F_59 ( V_2 ) ) {
F_54 ( V_2 , V_2 -> V_5 . V_103 , F_61 ( V_2 ) ) ;
V_1235 = 1 ;
}
F_243 ( & V_2 -> V_139 -> V_494 , V_493 ) ;
if ( V_1235 )
F_67 ( V_2 ) ;
V_1237 = V_601 ;
V_1236 = F_633 (
( const unsigned long * ) V_1218 -> V_1227 , V_1237 ) ;
if ( V_1236 < V_1237 ) {
F_281 ( V_2 , V_1236 , false ) ;
F_133 ( L_28 , V_1236 ) ;
}
F_365 ( V_2 , & V_1218 -> V_1107 , V_1112 ) ;
F_365 ( V_2 , & V_1218 -> V_1108 , V_1113 ) ;
F_365 ( V_2 , & V_1218 -> V_1219 , V_1114 ) ;
F_365 ( V_2 , & V_1218 -> V_1220 , V_1115 ) ;
F_365 ( V_2 , & V_1218 -> V_1221 , V_1116 ) ;
F_365 ( V_2 , & V_1218 -> V_1222 , V_1117 ) ;
F_365 ( V_2 , & V_1218 -> V_1223 , V_1105 ) ;
F_365 ( V_2 , & V_1218 -> V_1224 , V_1106 ) ;
F_272 ( V_2 ) ;
if ( F_634 ( V_2 ) && F_465 ( V_2 ) == 0xfff0 &&
V_1218 -> V_1107 . V_916 == 0xf000 && V_1218 -> V_1107 . V_230 == 0xffff0000 &&
! F_33 ( V_2 ) )
V_2 -> V_5 . V_648 = V_1173 ;
F_32 ( V_68 , V_2 ) ;
return 0 ;
}
int F_635 ( struct V_1 * V_2 ,
struct V_1238 * V_1239 )
{
unsigned long V_990 ;
int V_3 , V_121 ;
if ( V_1239 -> V_766 & ( V_1240 | V_1241 ) ) {
V_121 = - V_813 ;
if ( V_2 -> V_5 . V_69 . V_70 )
goto V_113;
if ( V_1239 -> V_766 & V_1240 )
F_34 ( V_2 , V_54 ) ;
else
F_34 ( V_2 , V_55 ) ;
}
V_990 = F_464 ( V_2 ) ;
V_2 -> V_179 = V_1239 -> V_766 ;
if ( ! ( V_2 -> V_179 & V_1242 ) )
V_2 -> V_179 = 0 ;
if ( V_2 -> V_179 & V_180 ) {
for ( V_3 = 0 ; V_3 < V_181 ; ++ V_3 )
V_2 -> V_5 . V_182 [ V_3 ] = V_1239 -> V_5 . V_1243 [ V_3 ] ;
V_2 -> V_5 . V_189 = V_1239 -> V_5 . V_1243 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_181 ; V_3 ++ )
V_2 -> V_5 . V_182 [ V_3 ] = V_2 -> V_5 . V_183 [ V_3 ] ;
}
F_97 ( V_2 ) ;
if ( V_2 -> V_179 & V_983 )
V_2 -> V_5 . V_987 = F_465 ( V_2 ) +
F_415 ( V_2 , V_1112 ) ;
F_470 ( V_2 , V_990 ) ;
V_87 -> V_1244 ( V_2 ) ;
V_121 = 0 ;
V_113:
return V_121 ;
}
int F_636 ( struct V_1 * V_2 ,
struct V_1245 * V_1223 )
{
unsigned long V_1246 = V_1223 -> V_1247 ;
T_6 V_390 ;
int V_493 ;
V_493 = F_242 ( & V_2 -> V_139 -> V_494 ) ;
V_390 = F_371 ( V_2 , V_1246 , NULL ) ;
F_243 ( & V_2 -> V_139 -> V_494 , V_493 ) ;
V_1223 -> V_1248 = V_390 ;
V_1223 -> V_666 = V_390 != V_100 ;
V_1223 -> V_1249 = 1 ;
V_1223 -> V_1250 = 0 ;
return 0 ;
}
int F_637 ( struct V_1 * V_2 , struct V_1251 * V_1179 )
{
struct V_679 * V_678 =
& V_2 -> V_5 . V_661 . V_662 . V_678 ;
memcpy ( V_1179 -> V_1252 , V_678 -> V_1253 , 128 ) ;
V_1179 -> V_1254 = V_678 -> V_1255 ;
V_1179 -> V_1256 = V_678 -> V_1257 ;
V_1179 -> V_1258 = V_678 -> V_1259 ;
V_1179 -> V_1260 = V_678 -> V_1261 ;
V_1179 -> V_1262 = V_678 -> V_1088 ;
V_1179 -> V_1263 = V_678 -> V_1264 ;
memcpy ( V_1179 -> V_1265 , V_678 -> V_1266 , sizeof V_678 -> V_1266 ) ;
return 0 ;
}
int F_638 ( struct V_1 * V_2 , struct V_1251 * V_1179 )
{
struct V_679 * V_678 =
& V_2 -> V_5 . V_661 . V_662 . V_678 ;
memcpy ( V_678 -> V_1253 , V_1179 -> V_1252 , 128 ) ;
V_678 -> V_1255 = V_1179 -> V_1254 ;
V_678 -> V_1257 = V_1179 -> V_1256 ;
V_678 -> V_1259 = V_1179 -> V_1258 ;
V_678 -> V_1261 = V_1179 -> V_1260 ;
V_678 -> V_1088 = V_1179 -> V_1262 ;
V_678 -> V_1264 = V_1179 -> V_1263 ;
memcpy ( V_678 -> V_1266 , V_1179 -> V_1265 , sizeof V_678 -> V_1266 ) ;
return 0 ;
}
static void F_639 ( struct V_1 * V_2 )
{
F_640 ( & V_2 -> V_5 . V_661 . V_662 ) ;
if ( F_249 ( V_672 ) )
V_2 -> V_5 . V_661 . V_662 . V_660 . V_664 . V_673 =
V_146 | V_674 ;
V_2 -> V_5 . V_145 = V_151 ;
V_2 -> V_5 . V_122 |= V_127 ;
}
void F_451 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1267 )
return;
V_2 -> V_1267 = 1 ;
F_641 () ;
F_642 ( & V_2 -> V_5 . V_661 . V_662 ) ;
F_643 ( 1 ) ;
}
void F_267 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_1267 )
return;
V_2 -> V_1267 = 0 ;
F_644 ( & V_2 -> V_5 . V_661 ) ;
F_645 () ;
++ V_2 -> V_76 . V_1268 ;
F_643 ( 0 ) ;
}
void F_646 ( struct V_1 * V_2 )
{
void * V_587 = V_2 -> V_5 . V_587 ;
F_217 ( V_2 ) ;
V_87 -> V_1269 ( V_2 ) ;
F_647 ( V_587 ) ;
}
struct V_1 * F_648 ( struct V_139 * V_139 ,
unsigned int V_1270 )
{
struct V_1 * V_2 ;
if ( F_158 () && F_144 ( & V_139 -> V_296 ) != 0 )
F_409 ( V_889
L_29
L_30 ) ;
V_2 = V_87 -> V_1271 ( V_139 , V_1270 ) ;
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
V_594 ( V_2 ) ;
return V_121 ;
}
void F_653 ( struct V_1 * V_2 )
{
struct V_33 V_22 ;
struct V_139 * V_139 = V_2 -> V_139 ;
if ( V_588 ( V_2 ) )
return;
V_22 . V_39 = 0x0 ;
V_22 . V_147 = V_1272 ;
V_22 . V_41 = true ;
F_154 ( V_2 , & V_22 ) ;
V_594 ( V_2 ) ;
if ( ! V_365 )
return;
F_204 ( & V_139 -> V_5 . V_364 ,
V_366 ) ;
}
void F_654 ( struct V_1 * V_2 )
{
int V_121 ;
V_2 -> V_5 . V_6 . V_391 = 0 ;
V_121 = V_588 ( V_2 ) ;
F_15 ( V_121 ) ;
F_584 ( V_2 ) ;
V_594 ( V_2 ) ;
V_87 -> V_1269 ( V_2 ) ;
}
void F_651 ( struct V_1 * V_2 , bool V_1273 )
{
V_2 -> V_5 . V_640 = 0 ;
V_2 -> V_5 . V_638 = 0 ;
F_178 ( & V_2 -> V_5 . V_84 , 0 ) ;
V_2 -> V_5 . V_632 = 0 ;
V_2 -> V_5 . V_631 = false ;
F_655 ( V_2 ) ;
F_487 ( V_2 ) ;
memset ( V_2 -> V_5 . V_183 , 0 , sizeof( V_2 -> V_5 . V_183 ) ) ;
F_95 ( V_2 ) ;
V_2 -> V_5 . V_187 = V_1274 ;
F_96 ( V_2 ) ;
V_2 -> V_5 . V_188 = V_199 ;
F_97 ( V_2 ) ;
V_2 -> V_5 . V_78 = 0 ;
F_32 ( V_68 , V_2 ) ;
V_2 -> V_5 . V_6 . V_391 = 0 ;
V_2 -> V_5 . V_395 . V_391 = 0 ;
F_217 ( V_2 ) ;
F_66 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1134 = false ;
if ( ! V_1273 ) {
F_656 ( V_2 ) ;
V_2 -> V_5 . V_427 = 0x30000 ;
V_2 -> V_5 . V_465 = V_464 ;
V_2 -> V_5 . V_468 = 0 ;
}
memset ( V_2 -> V_5 . V_1189 , 0 , sizeof( V_2 -> V_5 . V_1189 ) ) ;
V_2 -> V_5 . V_118 = ~ 0 ;
V_2 -> V_5 . V_119 = ~ 0 ;
V_87 -> V_1275 ( V_2 , V_1273 ) ;
}
void F_657 ( struct V_1 * V_2 , T_13 V_42 )
{
struct V_832 V_1107 ;
F_366 ( V_2 , & V_1107 , V_1112 ) ;
V_1107 . V_916 = V_42 << 8 ;
V_1107 . V_230 = V_42 << 12 ;
F_365 ( V_2 , & V_1107 , V_1112 ) ;
F_469 ( V_2 , 0 ) ;
}
int F_658 ( void )
{
struct V_139 * V_139 ;
struct V_1 * V_2 ;
int V_3 ;
int V_108 ;
T_2 V_1276 ;
T_2 V_1277 = 0 ;
bool V_1278 , V_1279 = false ;
F_16 () ;
V_108 = V_87 -> V_1280 () ;
if ( V_108 != 0 )
return V_108 ;
V_1276 = F_151 () ;
V_1278 = ! F_158 () ;
F_502 (kvm, &vm_list, vm_list) {
F_183 (i, vcpu, kvm) {
if ( ! V_1278 && V_2 -> V_24 == F_10 () )
F_32 ( V_340 , V_2 ) ;
if ( V_1278 && V_2 -> V_5 . V_591 > V_1276 ) {
V_1279 = true ;
if ( V_2 -> V_5 . V_591 > V_1277 )
V_1277 = V_2 -> V_5 . V_591 ;
}
}
}
if ( V_1279 ) {
T_2 V_1281 = V_1277 - V_1276 ;
V_336 = true ;
F_502 (kvm, &vm_list, vm_list) {
F_183 (i, vcpu, kvm) {
V_2 -> V_5 . V_589 += V_1281 ;
V_2 -> V_5 . V_591 = V_1276 ;
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
V_87 -> V_1282 () ;
F_20 () ;
}
int F_660 ( void )
{
int V_121 ;
V_121 = V_87 -> V_1283 () ;
if ( V_121 != 0 )
return V_121 ;
if ( V_273 ) {
T_2 V_1284 = F_358 ( 0x7fffffffULL ,
F_147 ( V_278 , V_274 ) ) ;
V_722 = V_1284 ;
V_272 = 1ULL << V_277 ;
}
F_355 () ;
return 0 ;
}
void F_661 ( void )
{
V_87 -> V_1285 () ;
}
void F_662 ( void * V_1286 )
{
V_87 -> V_1287 ( V_1286 ) ;
}
bool F_663 ( struct V_1 * V_2 )
{
return V_2 -> V_139 -> V_5 . V_814 == V_2 -> V_300 ;
}
bool F_634 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_32 & V_1288 ) != 0 ;
}
int F_664 ( struct V_1 * V_2 )
{
struct V_386 * V_386 ;
struct V_139 * V_139 ;
int V_121 ;
F_15 ( V_2 -> V_139 == NULL ) ;
V_139 = V_2 -> V_139 ;
V_2 -> V_5 . V_598 = V_87 -> V_1289 () ;
V_2 -> V_5 . V_1171 . V_1172 = false ;
V_2 -> V_5 . V_862 . V_861 = & V_1290 ;
if ( ! F_280 ( V_139 ) || F_663 ( V_2 ) )
V_2 -> V_5 . V_648 = V_1173 ;
else
V_2 -> V_5 . V_648 = V_1185 ;
V_386 = F_665 ( V_695 | V_1291 ) ;
if ( ! V_386 ) {
V_121 = - V_388 ;
goto V_1292;
}
V_2 -> V_5 . V_895 = F_666 ( V_386 ) ;
F_140 ( V_2 , V_1024 ) ;
V_121 = F_667 ( V_2 ) ;
if ( V_121 < 0 )
goto V_1293;
if ( F_280 ( V_139 ) ) {
V_121 = F_668 ( V_2 ) ;
if ( V_121 < 0 )
goto V_1294;
} else
F_669 ( & V_1295 ) ;
V_2 -> V_5 . V_375 = F_314 ( V_440 * sizeof( T_2 ) * 4 ,
V_695 ) ;
if ( ! V_2 -> V_5 . V_375 ) {
V_121 = - V_388 ;
goto V_1296;
}
V_2 -> V_5 . V_367 = V_440 ;
if ( ! F_670 ( & V_2 -> V_5 . V_587 , V_695 ) ) {
V_121 = - V_388 ;
goto V_1297;
}
F_639 ( V_2 ) ;
V_2 -> V_5 . V_303 = 0x0 ;
V_2 -> V_5 . V_357 = false ;
V_2 -> V_5 . V_154 = 0 ;
V_2 -> V_5 . V_1298 = V_1299 + V_667 ;
V_2 -> V_5 . V_1035 = F_671 ( V_2 ) ;
V_2 -> V_5 . V_1300 = V_1301 ;
F_1 ( V_2 ) ;
F_672 ( V_2 ) ;
V_2 -> V_5 . V_603 = - 1 ;
F_673 ( V_2 ) ;
return 0 ;
V_1297:
F_213 ( V_2 -> V_5 . V_375 ) ;
V_1296:
F_674 ( V_2 ) ;
V_1294:
F_675 ( V_2 ) ;
V_1293:
F_676 ( ( unsigned long ) V_2 -> V_5 . V_895 ) ;
V_1292:
return V_121 ;
}
void F_677 ( struct V_1 * V_2 )
{
int V_493 ;
F_678 ( V_2 ) ;
F_679 ( V_2 ) ;
F_213 ( V_2 -> V_5 . V_375 ) ;
F_674 ( V_2 ) ;
V_493 = F_242 ( & V_2 -> V_139 -> V_494 ) ;
F_675 ( V_2 ) ;
F_243 ( & V_2 -> V_139 -> V_494 , V_493 ) ;
F_676 ( ( unsigned long ) V_2 -> V_5 . V_895 ) ;
if ( ! F_91 ( V_2 ) )
F_680 ( & V_1295 ) ;
}
void F_681 ( struct V_1 * V_2 , int V_24 )
{
V_87 -> V_1302 ( V_2 , V_24 ) ;
}
int F_682 ( struct V_139 * V_139 , unsigned long type )
{
if ( type )
return - V_584 ;
F_683 ( & V_139 -> V_5 . V_1303 ) ;
F_684 ( & V_139 -> V_5 . V_1304 ) ;
F_684 ( & V_139 -> V_5 . V_1305 ) ;
F_684 ( & V_139 -> V_5 . V_1306 ) ;
F_178 ( & V_139 -> V_5 . V_1307 , 0 ) ;
F_296 ( V_774 , & V_139 -> V_5 . V_1308 ) ;
F_296 ( V_1309 ,
& V_139 -> V_5 . V_1308 ) ;
F_685 ( & V_139 -> V_5 . V_313 ) ;
F_686 ( & V_139 -> V_5 . V_1310 ) ;
F_686 ( & V_139 -> V_5 . V_1149 . V_1311 ) ;
F_687 ( & V_139 -> V_5 . V_326 ) ;
V_139 -> V_5 . V_249 = - F_156 () ;
F_177 ( V_139 ) ;
F_688 ( & V_139 -> V_5 . V_362 , F_200 ) ;
F_688 ( & V_139 -> V_5 . V_364 , F_205 ) ;
F_689 ( V_139 ) ;
F_690 ( V_139 ) ;
if ( V_87 -> V_1312 )
return V_87 -> V_1312 ( V_139 ) ;
return 0 ;
}
static void F_691 ( struct V_1 * V_2 )
{
int V_121 ;
V_121 = V_588 ( V_2 ) ;
F_15 ( V_121 ) ;
F_584 ( V_2 ) ;
V_594 ( V_2 ) ;
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
F_323 ( & V_139 -> V_749 ) ;
for ( V_3 = 0 ; V_3 < F_144 ( & V_139 -> V_296 ) ; V_3 ++ )
V_139 -> V_1313 [ V_3 ] = NULL ;
F_178 ( & V_139 -> V_296 , 0 ) ;
F_325 ( & V_139 -> V_749 ) ;
}
void F_693 ( struct V_139 * V_139 )
{
F_694 ( & V_139 -> V_5 . V_364 ) ;
F_694 ( & V_139 -> V_5 . V_362 ) ;
F_695 ( V_139 ) ;
}
int F_696 ( struct V_139 * V_139 , int V_1270 , T_6 V_390 , T_1 V_499 )
{
int V_3 , V_121 ;
unsigned long V_1314 ;
struct V_1315 * V_1316 = V_1315 ( V_139 ) ;
struct V_1317 * V_10 , V_882 ;
if ( F_30 ( V_1270 >= V_1318 ) )
return - V_584 ;
V_10 = F_697 ( V_1316 , V_1270 ) ;
if ( V_499 ) {
if ( V_10 -> V_1319 )
return - V_604 ;
V_1314 = F_698 ( NULL , 0 , V_499 , V_1320 | V_1321 ,
V_1322 | V_1323 , 0 ) ;
if ( F_210 ( ( void * ) V_1314 ) )
return F_211 ( ( void * ) V_1314 ) ;
} else {
if ( ! V_10 -> V_1319 )
return 0 ;
V_1314 = 0 ;
}
V_882 = * V_10 ;
for ( V_3 = 0 ; V_3 < V_1324 ; V_3 ++ ) {
struct V_1325 V_1326 ;
V_1326 . V_10 = V_1270 | ( V_3 << 16 ) ;
V_1326 . V_15 = 0 ;
V_1326 . V_1327 = V_390 ;
V_1326 . V_1328 = V_1314 ;
V_1326 . V_1329 = V_499 ;
V_121 = F_699 ( V_139 , & V_1326 ) ;
if ( V_121 < 0 )
return V_121 ;
}
if ( ! V_499 ) {
V_121 = F_700 ( V_882 . V_1328 , V_882 . V_1319 * V_107 ) ;
F_30 ( V_121 < 0 ) ;
}
return 0 ;
}
int F_701 ( struct V_139 * V_139 , int V_1270 , T_6 V_390 , T_1 V_499 )
{
int V_121 ;
F_323 ( & V_139 -> V_734 ) ;
V_121 = F_696 ( V_139 , V_1270 , V_390 , V_499 ) ;
F_325 ( & V_139 -> V_734 ) ;
return V_121 ;
}
void F_702 ( struct V_139 * V_139 )
{
if ( V_401 -> V_1330 == V_139 -> V_1330 ) {
F_701 ( V_139 , V_1331 , 0 , 0 ) ;
F_701 ( V_139 , V_1332 , 0 , 0 ) ;
F_701 ( V_139 , V_1333 , 0 , 0 ) ;
}
if ( V_87 -> V_1334 )
V_87 -> V_1334 ( V_139 ) ;
F_350 ( V_139 ) ;
F_352 ( V_139 ) ;
F_692 ( V_139 ) ;
F_703 ( F_704 ( V_139 -> V_5 . V_1335 , 1 ) ) ;
F_705 ( V_139 ) ;
F_706 ( V_139 ) ;
}
void F_707 ( struct V_139 * V_139 , struct V_1317 * free ,
struct V_1317 * V_1336 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1337 ; ++ V_3 ) {
if ( ! V_1336 || free -> V_5 . V_1338 [ V_3 ] != V_1336 -> V_5 . V_1338 [ V_3 ] ) {
F_703 ( free -> V_5 . V_1338 [ V_3 ] ) ;
free -> V_5 . V_1338 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1336 || free -> V_5 . V_1339 [ V_3 - 1 ] !=
V_1336 -> V_5 . V_1339 [ V_3 - 1 ] ) {
F_703 ( free -> V_5 . V_1339 [ V_3 - 1 ] ) ;
free -> V_5 . V_1339 [ V_3 - 1 ] = NULL ;
}
}
F_708 ( free , V_1336 ) ;
}
int F_709 ( struct V_139 * V_139 , struct V_1317 * V_10 ,
unsigned long V_1319 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1337 ; ++ V_3 ) {
struct V_1340 * V_1341 ;
unsigned long V_1342 ;
int V_1343 ;
int V_775 = V_3 + 1 ;
V_1343 = F_710 ( V_10 -> V_1344 + V_1319 - 1 ,
V_10 -> V_1344 , V_775 ) + 1 ;
V_10 -> V_5 . V_1338 [ V_3 ] =
F_711 ( V_1343 * sizeof( * V_10 -> V_5 . V_1338 [ V_3 ] ) , V_695 ) ;
if ( ! V_10 -> V_5 . V_1338 [ V_3 ] )
goto V_389;
if ( V_3 == 0 )
continue;
V_1341 = F_711 ( V_1343 * sizeof( * V_1341 ) , V_695 ) ;
if ( ! V_1341 )
goto V_389;
V_10 -> V_5 . V_1339 [ V_3 - 1 ] = V_1341 ;
if ( V_10 -> V_1344 & ( F_712 ( V_775 ) - 1 ) )
V_1341 [ 0 ] . V_1345 = 1 ;
if ( ( V_10 -> V_1344 + V_1319 ) & ( F_712 ( V_775 ) - 1 ) )
V_1341 [ V_1343 - 1 ] . V_1345 = 1 ;
V_1342 = V_10 -> V_1328 >> V_106 ;
if ( ( V_10 -> V_1344 ^ V_1342 ) & ( F_712 ( V_775 ) - 1 ) ||
! F_713 () ) {
unsigned long V_823 ;
for ( V_823 = 0 ; V_823 < V_1343 ; ++ V_823 )
V_1341 [ V_823 ] . V_1345 = 1 ;
}
}
if ( F_714 ( V_10 , V_1319 ) )
goto V_389;
return 0 ;
V_389:
for ( V_3 = 0 ; V_3 < V_1337 ; ++ V_3 ) {
F_703 ( V_10 -> V_5 . V_1338 [ V_3 ] ) ;
V_10 -> V_5 . V_1338 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_703 ( V_10 -> V_5 . V_1339 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1339 [ V_3 - 1 ] = NULL ;
}
return - V_388 ;
}
void F_715 ( struct V_139 * V_139 , struct V_1315 * V_1316 )
{
F_716 ( V_139 , V_1316 ) ;
}
int F_717 ( struct V_139 * V_139 ,
struct V_1317 * V_1346 ,
const struct V_1325 * V_1347 ,
enum V_1348 V_1349 )
{
return 0 ;
}
static void F_718 ( struct V_139 * V_139 ,
struct V_1317 * V_883 )
{
if ( V_883 -> V_15 & V_1350 ) {
F_719 ( V_139 , V_883 ) ;
return;
}
if ( V_883 -> V_15 & V_1351 ) {
if ( V_87 -> V_1352 )
V_87 -> V_1352 ( V_139 , V_883 ) ;
else
F_719 ( V_139 , V_883 ) ;
} else {
if ( V_87 -> V_1353 )
V_87 -> V_1353 ( V_139 , V_883 ) ;
}
}
void F_720 ( struct V_139 * V_139 ,
const struct V_1325 * V_1347 ,
const struct V_1317 * V_882 ,
const struct V_1317 * V_883 ,
enum V_1348 V_1349 )
{
int V_1354 = 0 ;
if ( ! V_139 -> V_5 . V_735 )
V_1354 = F_721 ( V_139 ) ;
if ( V_1354 )
F_324 ( V_139 , V_1354 ) ;
if ( ( V_1349 != V_1355 ) &&
( V_882 -> V_15 & V_1351 ) &&
! ( V_883 -> V_15 & V_1351 ) )
F_722 ( V_139 , V_883 ) ;
if ( V_1349 != V_1355 )
F_718 ( V_139 , (struct V_1317 * ) V_883 ) ;
}
void F_723 ( struct V_139 * V_139 )
{
F_724 ( V_139 ) ;
}
void F_725 ( struct V_139 * V_139 ,
struct V_1317 * V_10 )
{
F_726 ( V_139 , V_10 ) ;
}
static inline bool F_727 ( struct V_1 * V_2 )
{
if ( ! F_728 ( & V_2 -> V_1356 . V_1357 ) )
return true ;
if ( F_729 ( V_2 ) )
return true ;
if ( V_2 -> V_5 . V_1171 . V_1172 )
return true ;
if ( F_730 ( V_85 , V_2 ) ||
( V_2 -> V_5 . V_632 &&
V_87 -> V_1102 ( V_2 ) ) )
return true ;
if ( F_730 ( V_605 , V_2 ) ||
( V_2 -> V_5 . V_638 && ! F_291 ( V_2 ) ) )
return true ;
if ( F_276 ( V_2 ) &&
F_277 ( V_2 ) )
return true ;
if ( F_731 ( V_2 ) )
return true ;
return false ;
}
int F_609 ( struct V_1 * V_2 )
{
return F_611 ( V_2 ) || F_727 ( V_2 ) ;
}
int F_732 ( struct V_1 * V_2 )
{
return F_733 ( V_2 ) == V_1156 ;
}
int F_276 ( struct V_1 * V_2 )
{
return V_87 -> V_1103 ( V_2 ) ;
}
unsigned long F_485 ( struct V_1 * V_2 )
{
if ( F_546 ( V_2 ) )
return F_465 ( V_2 ) ;
return ( T_1 ) ( F_415 ( V_2 , V_1112 ) +
F_465 ( V_2 ) ) ;
}
bool F_734 ( struct V_1 * V_2 , unsigned long V_1358 )
{
return F_485 ( V_2 ) == V_1358 ;
}
unsigned long F_464 ( struct V_1 * V_2 )
{
unsigned long V_990 ;
V_990 = V_87 -> V_991 ( V_2 ) ;
if ( V_2 -> V_179 & V_983 )
V_990 &= ~ V_946 ;
return V_990 ;
}
static void F_492 ( struct V_1 * V_2 , unsigned long V_990 )
{
if ( V_2 -> V_179 & V_983 &&
F_734 ( V_2 , V_2 -> V_5 . V_987 ) )
V_990 |= V_946 ;
V_87 -> V_1359 ( V_2 , V_990 ) ;
}
void F_470 ( struct V_1 * V_2 , unsigned long V_990 )
{
F_492 ( V_2 , V_990 ) ;
F_32 ( V_68 , V_2 ) ;
}
void F_735 ( struct V_1 * V_2 , struct V_1360 * V_359 )
{
int V_121 ;
if ( ( V_2 -> V_5 . V_83 . V_974 != V_359 -> V_5 . V_974 ) ||
V_359 -> V_1361 )
return;
V_121 = F_592 ( V_2 ) ;
if ( F_171 ( V_121 ) )
return;
if ( ! V_2 -> V_5 . V_83 . V_974 &&
V_359 -> V_5 . V_104 != V_2 -> V_5 . V_83 . V_1362 ( V_2 ) )
return;
V_2 -> V_5 . V_83 . V_1363 ( V_2 , V_359 -> V_839 , 0 , true ) ;
}
static inline T_1 F_736 ( T_5 V_102 )
{
return F_737 ( V_102 & 0xffffffff , F_738 ( V_4 ) ) ;
}
static inline T_1 F_739 ( T_1 V_1364 )
{
return ( V_1364 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_740 ( struct V_1 * V_2 , T_5 V_102 )
{
T_1 V_1364 = F_736 ( V_102 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1364 ] != ~ 0 )
V_1364 = F_739 ( V_1364 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1364 ] = V_102 ;
}
static T_1 F_741 ( struct V_1 * V_2 , T_5 V_102 )
{
int V_3 ;
T_1 V_1364 = F_736 ( V_102 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1364 ] != V_102 &&
V_2 -> V_5 . V_6 . V_7 [ V_1364 ] != ~ 0 ) ; V_3 ++ )
V_1364 = F_739 ( V_1364 ) ;
return V_1364 ;
}
bool F_742 ( struct V_1 * V_2 , T_5 V_102 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_741 ( V_2 , V_102 ) ] == V_102 ;
}
static void F_743 ( struct V_1 * V_2 , T_5 V_102 )
{
T_1 V_3 , V_823 , V_1365 ;
V_3 = V_823 = F_741 ( V_2 , V_102 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_823 = F_739 ( V_823 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_823 ] == ~ 0 )
return;
V_1365 = F_736 ( V_2 -> V_5 . V_6 . V_7 [ V_823 ] ) ;
} while ( ( V_3 <= V_823 ) ? ( V_3 < V_1365 && V_1365 <= V_823 ) : ( V_3 < V_1365 || V_1365 <= V_823 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_823 ] ;
V_3 = V_823 ;
}
}
static int F_744 ( struct V_1 * V_2 , T_1 V_196 )
{
return F_194 ( V_2 -> V_139 , & V_2 -> V_5 . V_6 . V_39 , & V_196 ,
sizeof( V_196 ) ) ;
}
void F_745 ( struct V_1 * V_2 ,
struct V_1360 * V_359 )
{
struct V_74 V_75 ;
F_746 ( V_359 -> V_5 . V_1366 , V_359 -> V_839 ) ;
F_740 ( V_2 , V_359 -> V_5 . V_102 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_391 & V_392 ) ||
( V_2 -> V_5 . V_6 . V_393 &&
V_87 -> V_88 ( V_2 ) == 0 ) )
F_32 ( V_1133 , V_2 ) ;
else if ( ! F_744 ( V_2 , V_1367 ) ) {
V_75 . V_42 = V_43 ;
V_75 . V_943 = true ;
V_75 . V_63 = 0 ;
V_75 . V_80 = false ;
V_75 . V_79 = V_359 -> V_5 . V_1366 ;
F_39 ( V_2 , & V_75 ) ;
}
}
void F_747 ( struct V_1 * V_2 ,
struct V_1360 * V_359 )
{
struct V_74 V_75 ;
if ( V_359 -> V_1361 )
V_359 -> V_5 . V_1366 = ~ 0 ;
else
F_743 ( V_2 , V_359 -> V_5 . V_102 ) ;
F_748 ( V_359 -> V_5 . V_1366 , V_359 -> V_839 ) ;
if ( ( V_2 -> V_5 . V_6 . V_391 & V_392 ) &&
! F_744 ( V_2 , V_1368 ) ) {
V_75 . V_42 = V_43 ;
V_75 . V_943 = true ;
V_75 . V_63 = 0 ;
V_75 . V_80 = false ;
V_75 . V_79 = V_359 -> V_5 . V_1366 ;
F_39 ( V_2 , & V_75 ) ;
}
V_2 -> V_5 . V_6 . V_1134 = false ;
V_2 -> V_5 . V_648 = V_1173 ;
}
bool F_749 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_391 & V_392 ) )
return true ;
else
return F_750 ( V_2 ) ;
}
void F_751 ( struct V_139 * V_139 )
{
F_44 ( & V_139 -> V_5 . V_1369 ) ;
}
void F_752 ( struct V_139 * V_139 )
{
F_753 ( & V_139 -> V_5 . V_1369 ) ;
}
bool F_754 ( struct V_139 * V_139 )
{
return F_144 ( & V_139 -> V_5 . V_1369 ) ;
}
void F_755 ( struct V_139 * V_139 )
{
F_44 ( & V_139 -> V_5 . V_1307 ) ;
}
void F_756 ( struct V_139 * V_139 )
{
F_753 ( & V_139 -> V_5 . V_1307 ) ;
}
bool F_68 ( struct V_139 * V_139 )
{
return F_144 ( & V_139 -> V_5 . V_1307 ) ;
}
bool F_757 ( void )
{
return V_87 -> V_1370 != NULL ;
}
int F_758 ( struct V_1371 * V_1372 ,
struct V_1373 * V_1374 )
{
struct V_1375 * V_1376 =
F_4 ( V_1372 , struct V_1375 , V_1377 ) ;
V_1376 -> V_1378 = V_1374 ;
return V_87 -> V_1370 ( V_1376 -> V_139 ,
V_1374 -> V_600 , V_1376 -> V_1379 , 1 ) ;
}
void F_759 ( struct V_1371 * V_1372 ,
struct V_1373 * V_1374 )
{
int V_108 ;
struct V_1375 * V_1376 =
F_4 ( V_1372 , struct V_1375 , V_1377 ) ;
F_30 ( V_1376 -> V_1378 != V_1374 ) ;
V_1376 -> V_1378 = NULL ;
V_108 = V_87 -> V_1370 ( V_1376 -> V_139 , V_1374 -> V_600 , V_1376 -> V_1379 , 0 ) ;
if ( V_108 )
F_12 ( V_1380 L_31
L_32 , V_1376 -> V_1377 . V_1366 , V_108 ) ;
}
int F_760 ( struct V_139 * V_139 , unsigned int V_1381 ,
T_7 V_1382 , bool V_1383 )
{
if ( ! V_87 -> V_1370 )
return - V_584 ;
return V_87 -> V_1370 ( V_139 , V_1381 , V_1382 , V_1383 ) ;
}
bool F_761 ( void )
{
return V_1384 ;
}
