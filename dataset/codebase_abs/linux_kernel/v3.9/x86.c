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
if ( V_10 >= V_15 . V_16 )
V_15 . V_16 = V_10 + 1 ;
V_15 . V_19 [ V_10 ] = V_21 ;
F_13 () ;
}
static void F_14 ( void )
{
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_15 . V_16 ; ++ V_3 )
F_7 ( V_3 , V_15 . V_19 [ V_3 ] ) ;
}
void F_15 ( unsigned V_10 , T_2 V_22 , T_2 V_27 )
{
unsigned int V_23 = F_8 () ;
struct V_11 * V_24 = F_9 ( V_25 , V_23 ) ;
if ( ( ( V_22 ^ V_24 -> V_14 [ V_10 ] . V_18 ) & V_27 ) == 0 )
return;
V_24 -> V_14 [ V_10 ] . V_18 = V_22 ;
F_5 ( V_15 . V_19 [ V_10 ] , V_22 ) ;
if ( ! V_24 -> V_20 ) {
V_24 -> V_9 . V_28 = F_3 ;
F_16 ( & V_24 -> V_9 ) ;
V_24 -> V_20 = true ;
}
}
static void F_17 ( void * V_29 )
{
unsigned int V_23 = F_8 () ;
struct V_11 * V_24 = F_9 ( V_25 , V_23 ) ;
if ( V_24 -> V_20 )
F_3 ( & V_24 -> V_9 ) ;
}
T_2 F_18 ( struct V_1 * V_2 )
{
return V_2 -> V_5 . V_30 ;
}
void F_19 ( struct V_1 * V_2 , T_2 V_31 )
{
F_20 ( V_2 , V_31 ) ;
}
static int F_21 ( int V_32 )
{
switch ( V_32 ) {
case V_33 :
return V_34 ;
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
return V_40 ;
default:
break;
}
return V_41 ;
}
static void F_22 ( struct V_1 * V_2 ,
unsigned V_16 , bool V_42 , T_1 V_43 ,
bool V_44 )
{
T_1 V_45 ;
int V_46 , V_47 ;
F_23 ( V_48 , V_2 ) ;
if ( ! V_2 -> V_5 . V_49 . V_50 ) {
V_51:
V_2 -> V_5 . V_49 . V_50 = true ;
V_2 -> V_5 . V_49 . V_52 = V_42 ;
V_2 -> V_5 . V_49 . V_16 = V_16 ;
V_2 -> V_5 . V_49 . V_43 = V_43 ;
V_2 -> V_5 . V_49 . V_44 = V_44 ;
return;
}
V_45 = V_2 -> V_5 . V_49 . V_16 ;
if ( V_45 == V_53 ) {
F_23 ( V_54 , V_2 ) ;
return;
}
V_46 = F_21 ( V_45 ) ;
V_47 = F_21 ( V_16 ) ;
if ( ( V_46 == V_40 && V_47 == V_40 )
|| ( V_46 == V_34 && V_47 != V_41 ) ) {
V_2 -> V_5 . V_49 . V_50 = true ;
V_2 -> V_5 . V_49 . V_52 = true ;
V_2 -> V_5 . V_49 . V_16 = V_53 ;
V_2 -> V_5 . V_49 . V_43 = 0 ;
} else
goto V_51;
}
void F_24 ( struct V_1 * V_2 , unsigned V_16 )
{
F_22 ( V_2 , V_16 , false , 0 , false ) ;
}
void F_25 ( struct V_1 * V_2 , unsigned V_16 )
{
F_22 ( V_2 , V_16 , false , 0 , true ) ;
}
void F_26 ( struct V_1 * V_2 , int V_55 )
{
if ( V_55 )
F_27 ( V_2 , 0 ) ;
else
V_56 -> V_57 ( V_2 ) ;
}
void F_28 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
++ V_2 -> V_60 . V_61 ;
V_2 -> V_5 . V_62 = V_59 -> V_63 ;
F_29 ( V_2 , V_33 , V_59 -> V_43 ) ;
}
void F_30 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
if ( F_31 ( V_2 ) && ! V_59 -> V_64 )
V_2 -> V_5 . V_65 . V_66 ( V_2 , V_59 ) ;
else
V_2 -> V_5 . V_67 . V_66 ( V_2 , V_59 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_5 . V_68 ) ;
F_23 ( V_69 , V_2 ) ;
}
void F_29 ( struct V_1 * V_2 , unsigned V_16 , T_1 V_43 )
{
F_22 ( V_2 , V_16 , true , V_43 , false ) ;
}
void F_34 ( struct V_1 * V_2 , unsigned V_16 , T_1 V_43 )
{
F_22 ( V_2 , V_16 , true , V_43 , true ) ;
}
bool F_35 ( struct V_1 * V_2 , int V_70 )
{
if ( V_56 -> V_71 ( V_2 ) <= V_70 )
return true ;
F_29 ( V_2 , V_39 , 0 ) ;
return false ;
}
int F_36 ( struct V_1 * V_2 , struct V_72 * V_67 ,
T_3 V_73 , void * V_31 , int V_74 , int V_75 ,
T_1 V_76 )
{
T_3 V_77 ;
T_4 V_78 ;
V_78 = F_37 ( V_73 ) ;
V_77 = V_67 -> V_79 ( V_2 , V_78 , V_76 ) ;
if ( V_77 == V_80 )
return - V_81 ;
V_77 = F_38 ( V_77 ) ;
return F_39 ( V_2 -> V_82 , V_77 , V_31 , V_74 , V_75 ) ;
}
int F_40 ( struct V_1 * V_2 , T_3 V_83 ,
void * V_31 , int V_74 , int V_75 , T_1 V_76 )
{
return F_36 ( V_2 , V_2 -> V_5 . V_84 , V_83 ,
V_31 , V_74 , V_75 , V_76 ) ;
}
int F_41 ( struct V_1 * V_2 , struct V_72 * V_67 , unsigned long V_85 )
{
T_3 V_86 = V_85 >> V_87 ;
unsigned V_74 = ( ( V_85 & ( V_88 - 1 ) ) >> 5 ) << 2 ;
int V_3 ;
int V_89 ;
T_2 V_90 [ F_42 ( V_67 -> V_91 ) ] ;
V_89 = F_36 ( V_2 , V_67 , V_86 , V_90 ,
V_74 * sizeof( T_2 ) , sizeof( V_90 ) ,
V_92 | V_93 ) ;
if ( V_89 < 0 ) {
V_89 = 0 ;
goto V_94;
}
for ( V_3 = 0 ; V_3 < F_42 ( V_90 ) ; ++ V_3 ) {
if ( F_43 ( V_90 [ V_3 ] ) &&
( V_90 [ V_3 ] & V_2 -> V_5 . V_67 . V_95 [ 0 ] [ 2 ] ) ) {
V_89 = 0 ;
goto V_94;
}
}
V_89 = 1 ;
memcpy ( V_67 -> V_91 , V_90 , sizeof( V_67 -> V_91 ) ) ;
F_44 ( V_96 ,
( unsigned long * ) & V_2 -> V_5 . V_97 ) ;
F_44 ( V_96 ,
( unsigned long * ) & V_2 -> V_5 . V_98 ) ;
V_94:
return V_89 ;
}
static bool F_45 ( struct V_1 * V_2 )
{
T_2 V_90 [ F_42 ( V_2 -> V_5 . V_84 -> V_91 ) ] ;
bool V_99 = true ;
int V_74 ;
T_3 V_83 ;
int V_100 ;
if ( F_46 ( V_2 ) || ! F_47 ( V_2 ) )
return false ;
if ( ! F_48 ( V_96 ,
( unsigned long * ) & V_2 -> V_5 . V_97 ) )
return true ;
V_83 = ( F_49 ( V_2 ) & ~ 31u ) >> V_87 ;
V_74 = ( F_49 ( V_2 ) & ~ 31u ) & ( V_88 - 1 ) ;
V_100 = F_40 ( V_2 , V_83 , V_90 , V_74 , sizeof( V_90 ) ,
V_92 | V_93 ) ;
if ( V_100 < 0 )
goto V_94;
V_99 = memcmp ( V_90 , V_2 -> V_5 . V_84 -> V_91 , sizeof( V_90 ) ) != 0 ;
V_94:
return V_99 ;
}
int F_50 ( struct V_1 * V_2 , unsigned long V_101 )
{
unsigned long V_102 = F_51 ( V_2 ) ;
unsigned long V_103 = V_104 | V_105 |
V_106 | V_107 ;
V_101 |= V_108 ;
#ifdef F_52
if ( V_101 & 0xffffffff00000000UL )
return 1 ;
#endif
V_101 &= ~ V_109 ;
if ( ( V_101 & V_107 ) && ! ( V_101 & V_106 ) )
return 1 ;
if ( ( V_101 & V_104 ) && ! ( V_101 & V_110 ) )
return 1 ;
if ( ! F_53 ( V_2 ) && ( V_101 & V_104 ) ) {
#ifdef F_52
if ( ( V_2 -> V_5 . V_111 & V_112 ) ) {
int V_113 , V_114 ;
if ( ! F_47 ( V_2 ) )
return 1 ;
V_56 -> V_115 ( V_2 , & V_113 , & V_114 ) ;
if ( V_114 )
return 1 ;
} else
#endif
if ( F_47 ( V_2 ) && ! F_41 ( V_2 , V_2 -> V_5 . V_84 ,
F_49 ( V_2 ) ) )
return 1 ;
}
if ( ! ( V_101 & V_104 ) && F_54 ( V_2 , V_116 ) )
return 1 ;
V_56 -> V_117 ( V_2 , V_101 ) ;
if ( ( V_101 ^ V_102 ) & V_104 ) {
F_55 ( V_2 ) ;
F_1 ( V_2 ) ;
}
if ( ( V_101 ^ V_102 ) & V_103 )
F_56 ( V_2 ) ;
return 0 ;
}
void F_57 ( struct V_1 * V_2 , unsigned long V_118 )
{
( void ) F_50 ( V_2 , F_58 ( V_2 , ~ 0x0eul ) | ( V_118 & 0x0f ) ) ;
}
int F_59 ( struct V_1 * V_2 , T_1 V_119 , T_2 V_120 )
{
T_2 V_121 ;
if ( V_119 != V_122 )
return 1 ;
V_121 = V_120 ;
if ( V_56 -> V_71 ( V_2 ) != 0 )
return 1 ;
if ( ! ( V_121 & V_123 ) )
return 1 ;
if ( ( V_121 & V_124 ) && ! ( V_121 & V_125 ) )
return 1 ;
if ( V_121 & ~ V_126 )
return 1 ;
V_2 -> V_5 . V_121 = V_121 ;
V_2 -> V_127 = 0 ;
return 0 ;
}
int F_60 ( struct V_1 * V_2 , T_1 V_119 , T_2 V_120 )
{
if ( F_59 ( V_2 , V_119 , V_120 ) ) {
F_27 ( V_2 , 0 ) ;
return 1 ;
}
return 0 ;
}
int F_61 ( struct V_1 * V_2 , unsigned long V_128 )
{
unsigned long V_129 = F_62 ( V_2 ) ;
unsigned long V_130 = V_131 | V_132 |
V_133 | V_134 ;
if ( V_128 & V_135 )
return 1 ;
if ( ! F_63 ( V_2 ) && ( V_128 & V_136 ) )
return 1 ;
if ( ! F_64 ( V_2 ) && ( V_128 & V_134 ) )
return 1 ;
if ( ! F_65 ( V_2 ) && ( V_128 & V_137 ) )
return 1 ;
if ( F_46 ( V_2 ) ) {
if ( ! ( V_128 & V_133 ) )
return 1 ;
} else if ( F_53 ( V_2 ) && ( V_128 & V_133 )
&& ( ( V_128 ^ V_129 ) & V_130 )
&& ! F_41 ( V_2 , V_2 -> V_5 . V_84 ,
F_49 ( V_2 ) ) )
return 1 ;
if ( ( V_128 & V_116 ) && ! ( V_129 & V_116 ) ) {
if ( ! F_66 ( V_2 ) )
return 1 ;
if ( ( F_49 ( V_2 ) & V_138 ) || ! F_46 ( V_2 ) )
return 1 ;
}
if ( V_56 -> V_139 ( V_2 , V_128 ) )
return 1 ;
if ( ( ( V_128 ^ V_129 ) & V_130 ) ||
( ! ( V_128 & V_116 ) && ( V_129 & V_116 ) ) )
F_56 ( V_2 ) ;
if ( ( V_128 ^ V_129 ) & V_136 )
F_67 ( V_2 ) ;
return 0 ;
}
int F_68 ( struct V_1 * V_2 , unsigned long V_85 )
{
if ( V_85 == F_49 ( V_2 ) && ! F_45 ( V_2 ) ) {
F_69 ( V_2 ) ;
F_70 ( V_2 ) ;
return 0 ;
}
if ( F_46 ( V_2 ) ) {
if ( F_54 ( V_2 , V_116 ) ) {
if ( V_85 & V_140 )
return 1 ;
} else
if ( V_85 & V_141 )
return 1 ;
} else {
if ( F_47 ( V_2 ) ) {
if ( V_85 & V_142 )
return 1 ;
if ( F_53 ( V_2 ) &&
! F_41 ( V_2 , V_2 -> V_5 . V_84 , V_85 ) )
return 1 ;
}
}
if ( F_71 ( ! F_72 ( V_2 -> V_82 , V_85 >> V_87 ) ) )
return 1 ;
V_2 -> V_5 . V_85 = V_85 ;
F_44 ( V_143 , ( V_144 * ) & V_2 -> V_5 . V_97 ) ;
V_2 -> V_5 . V_67 . V_145 ( V_2 ) ;
return 0 ;
}
int F_73 ( struct V_1 * V_2 , unsigned long V_146 )
{
if ( V_146 & V_147 )
return 1 ;
if ( F_74 ( V_2 -> V_82 ) )
F_75 ( V_2 , V_146 ) ;
else
V_2 -> V_5 . V_146 = V_146 ;
return 0 ;
}
unsigned long F_76 ( struct V_1 * V_2 )
{
if ( F_74 ( V_2 -> V_82 ) )
return F_77 ( V_2 ) ;
else
return V_2 -> V_5 . V_146 ;
}
static void F_78 ( struct V_1 * V_2 )
{
unsigned long V_148 ;
if ( V_2 -> V_149 & V_150 )
V_148 = V_2 -> V_5 . V_151 ;
else
V_148 = V_2 -> V_5 . V_148 ;
V_56 -> V_152 ( V_2 , V_148 ) ;
V_2 -> V_5 . V_153 = ( V_148 & V_154 ) ;
}
static int F_79 ( struct V_1 * V_2 , int V_155 , unsigned long V_156 )
{
switch ( V_155 ) {
case 0 ... 3 :
V_2 -> V_5 . V_157 [ V_155 ] = V_156 ;
if ( ! ( V_2 -> V_149 & V_150 ) )
V_2 -> V_5 . V_158 [ V_155 ] = V_156 ;
break;
case 4 :
if ( F_54 ( V_2 , V_159 ) )
return 1 ;
case 6 :
if ( V_156 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_160 = ( V_156 & V_161 ) | V_162 ;
break;
case 5 :
if ( F_54 ( V_2 , V_159 ) )
return 1 ;
default:
if ( V_156 & 0xffffffff00000000ULL )
return - 1 ;
V_2 -> V_5 . V_148 = ( V_156 & V_163 ) | V_164 ;
F_78 ( V_2 ) ;
break;
}
return 0 ;
}
int F_80 ( struct V_1 * V_2 , int V_155 , unsigned long V_156 )
{
int V_165 ;
V_165 = F_79 ( V_2 , V_155 , V_156 ) ;
if ( V_165 > 0 )
F_24 ( V_2 , V_166 ) ;
else if ( V_165 < 0 )
F_27 ( V_2 , 0 ) ;
return V_165 ;
}
static int F_81 ( struct V_1 * V_2 , int V_155 , unsigned long * V_156 )
{
switch ( V_155 ) {
case 0 ... 3 :
* V_156 = V_2 -> V_5 . V_157 [ V_155 ] ;
break;
case 4 :
if ( F_54 ( V_2 , V_159 ) )
return 1 ;
case 6 :
* V_156 = V_2 -> V_5 . V_160 ;
break;
case 5 :
if ( F_54 ( V_2 , V_159 ) )
return 1 ;
default:
* V_156 = V_2 -> V_5 . V_148 ;
break;
}
return 0 ;
}
int F_82 ( struct V_1 * V_2 , int V_155 , unsigned long * V_156 )
{
if ( F_81 ( V_2 , V_155 , V_156 ) ) {
F_24 ( V_2 , V_166 ) ;
return 1 ;
}
return 0 ;
}
bool F_83 ( struct V_1 * V_2 )
{
T_1 V_167 = F_84 ( V_2 , V_168 ) ;
T_2 V_31 ;
int V_55 ;
V_55 = F_85 ( V_2 , V_167 , & V_31 ) ;
if ( V_55 )
return V_55 ;
F_86 ( V_2 , V_169 , ( T_1 ) V_31 ) ;
F_86 ( V_2 , V_170 , V_31 >> 32 ) ;
return V_55 ;
}
static int F_87 ( struct V_1 * V_2 , T_2 V_111 )
{
T_2 V_171 = V_2 -> V_5 . V_111 ;
if ( V_111 & V_172 )
return 1 ;
if ( F_53 ( V_2 )
&& ( V_2 -> V_5 . V_111 & V_112 ) != ( V_111 & V_112 ) )
return 1 ;
if ( V_111 & V_173 ) {
struct V_174 * V_175 ;
V_175 = F_88 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_175 || ! ( V_175 -> V_176 & F_89 ( V_177 ) ) )
return 1 ;
}
if ( V_111 & V_178 ) {
struct V_174 * V_175 ;
V_175 = F_88 ( V_2 , 0x80000001 , 0 ) ;
if ( ! V_175 || ! ( V_175 -> V_167 & F_89 ( V_179 ) ) )
return 1 ;
}
V_111 &= ~ V_180 ;
V_111 |= V_2 -> V_5 . V_111 & V_180 ;
V_56 -> F_87 ( V_2 , V_111 ) ;
if ( ( V_111 ^ V_171 ) & V_181 )
F_56 ( V_2 ) ;
return 0 ;
}
void F_90 ( T_2 V_27 )
{
V_172 &= ~ V_27 ;
}
int F_91 ( struct V_1 * V_2 , struct V_182 * V_21 )
{
return V_56 -> V_183 ( V_2 , V_21 ) ;
}
static int F_92 ( struct V_1 * V_2 , unsigned V_119 , T_2 * V_31 )
{
struct V_182 V_21 ;
V_21 . V_31 = * V_31 ;
V_21 . V_119 = V_119 ;
V_21 . V_184 = true ;
return F_91 ( V_2 , & V_21 ) ;
}
static void F_93 ( struct V_185 * V_186 )
{
struct V_187 * V_188 = & V_187 ;
F_94 ( & V_188 -> V_189 ) ;
V_188 -> clock . V_190 = V_186 -> clock -> V_191 . V_190 ;
V_188 -> clock . V_192 = V_186 -> clock -> V_192 ;
V_188 -> clock . V_27 = V_186 -> clock -> V_27 ;
V_188 -> clock . V_193 = V_186 -> V_193 ;
V_188 -> clock . V_194 = V_186 -> V_194 ;
V_188 -> V_195 = V_186 -> V_196
+ V_186 -> V_197 . V_198 ;
V_188 -> V_199 = V_186 -> V_200
+ ( V_186 -> V_197 . V_201
<< V_186 -> V_194 ) ;
while ( V_188 -> V_199 >=
( ( ( T_2 ) V_202 ) << V_186 -> V_194 ) ) {
V_188 -> V_199 -=
( ( T_2 ) V_202 ) << V_186 -> V_194 ;
V_188 -> V_195 ++ ;
}
F_95 ( & V_188 -> V_189 ) ;
}
static void F_96 ( struct V_82 * V_82 , T_4 V_203 )
{
int V_204 ;
int V_100 ;
struct V_205 V_206 ;
struct V_207 V_208 ;
if ( ! V_203 )
return;
V_100 = F_97 ( V_82 , V_203 , & V_204 , sizeof( V_204 ) ) ;
if ( V_100 )
return;
if ( V_204 & 1 )
++ V_204 ;
++ V_204 ;
F_98 ( V_82 , V_203 , & V_204 , sizeof( V_204 ) ) ;
F_99 ( & V_208 ) ;
if ( V_82 -> V_5 . V_209 ) {
struct V_207 V_210 = F_100 ( V_82 -> V_5 . V_209 ) ;
V_208 = F_101 ( V_208 , V_210 ) ;
}
V_206 . V_211 = V_208 . V_198 ;
V_206 . V_212 = V_208 . V_201 ;
V_206 . V_204 = V_204 ;
F_98 ( V_82 , V_203 , & V_206 , sizeof( V_206 ) ) ;
V_204 ++ ;
F_98 ( V_82 , V_203 , & V_204 , sizeof( V_204 ) ) ;
}
static T_5 F_102 ( T_5 V_213 , T_5 V_214 )
{
T_5 V_215 , V_216 ;
__asm__ ( "divl %4"
: "=a" (quotient), "=d" (remainder)
: "0" (0), "1" (dividend), "r" (divisor) );
return V_215 ;
}
static void F_103 ( T_5 V_217 , T_5 V_218 ,
T_6 * V_219 , T_1 * V_220 )
{
T_7 V_221 ;
T_8 V_194 = 0 ;
T_7 V_222 ;
T_5 V_223 ;
V_222 = V_218 * 1000LL ;
V_221 = V_217 * 1000LL ;
while ( V_222 > V_221 * 2 || V_222 & 0xffffffff00000000ULL ) {
V_222 >>= 1 ;
V_194 -- ;
}
V_223 = ( T_5 ) V_222 ;
while ( V_223 <= V_221 || V_221 & 0xffffffff00000000ULL ) {
if ( V_221 & 0xffffffff00000000ULL || V_223 & 0x80000000 )
V_221 >>= 1 ;
else
V_223 <<= 1 ;
V_194 ++ ;
}
* V_219 = V_194 ;
* V_220 = F_102 ( V_221 , V_223 ) ;
F_104 ( L_2 ,
V_224 , V_218 , V_217 , V_194 , * V_220 ) ;
}
static inline T_2 F_105 ( void )
{
struct V_207 V_210 ;
F_106 ( F_107 () ) ;
F_108 ( & V_210 ) ;
F_109 ( & V_210 ) ;
return F_110 ( & V_210 ) ;
}
static inline T_2 F_111 ( struct V_1 * V_2 , T_2 V_212 )
{
return F_112 ( V_212 , V_2 -> V_5 . V_225 ,
V_2 -> V_5 . V_226 ) ;
}
static T_1 F_113 ( T_1 V_227 , T_9 V_228 )
{
T_2 V_229 = ( T_2 ) V_227 * ( 1000000 + V_228 ) ;
F_114 ( V_229 , 1000000 ) ;
return V_229 ;
}
static void F_115 ( struct V_1 * V_2 , T_1 V_230 )
{
T_1 V_231 , V_232 ;
int V_233 = 0 ;
F_103 ( V_230 , V_202 / 1000 ,
& V_2 -> V_5 . V_226 ,
& V_2 -> V_5 . V_225 ) ;
V_2 -> V_5 . V_234 = V_230 ;
V_231 = F_113 ( V_235 , - V_236 ) ;
V_232 = F_113 ( V_235 , V_236 ) ;
if ( V_230 < V_231 || V_230 > V_232 ) {
F_104 ( L_3 , V_230 , V_231 , V_232 ) ;
V_233 = 1 ;
}
V_56 -> V_237 ( V_2 , V_230 , V_233 ) ;
}
static T_2 F_116 ( struct V_1 * V_2 , T_10 V_238 )
{
T_2 V_239 = F_112 ( V_238 - V_2 -> V_5 . V_240 ,
V_2 -> V_5 . V_225 ,
V_2 -> V_5 . V_226 ) ;
V_239 += V_2 -> V_5 . V_241 ;
return V_239 ;
}
void F_117 ( struct V_1 * V_2 )
{
#ifdef F_52
bool V_242 ;
bool V_243 = false ;
struct V_244 * V_245 = & V_2 -> V_82 -> V_5 ;
struct V_187 * V_246 = & V_187 ;
V_242 = ( V_245 -> V_247 + 1 ==
F_118 ( & V_2 -> V_82 -> V_248 ) ) ;
if ( V_242 && V_246 -> clock . V_190 == V_249 )
if ( ! V_245 -> V_250 )
V_243 = 1 ;
if ( ! V_242 && V_245 -> V_250 )
V_243 = 1 ;
if ( V_243 )
F_23 ( V_251 , V_2 ) ;
F_119 ( V_2 -> V_252 , V_245 -> V_247 ,
F_118 ( & V_2 -> V_82 -> V_248 ) ,
V_245 -> V_250 , V_246 -> clock . V_190 ) ;
#endif
}
static void F_120 ( struct V_1 * V_2 , T_10 V_74 )
{
T_2 V_253 = V_56 -> V_254 ( V_2 ) ;
V_2 -> V_5 . V_255 += V_74 - V_253 ;
}
void F_121 ( struct V_1 * V_2 , struct V_182 * V_21 )
{
struct V_82 * V_82 = V_2 -> V_82 ;
T_2 V_74 , V_256 , V_257 ;
unsigned long V_258 ;
T_10 V_259 ;
bool V_260 ;
T_2 V_31 = V_21 -> V_31 ;
F_122 ( & V_82 -> V_5 . V_261 , V_258 ) ;
V_74 = V_56 -> V_262 ( V_2 , V_31 ) ;
V_256 = F_105 () ;
V_257 = V_256 - V_82 -> V_5 . V_263 ;
V_259 = V_31 - V_82 -> V_5 . V_264 ;
#ifdef F_52
V_259 = ( V_259 * 1000 ) / V_2 -> V_5 . V_234 ;
#else
asm("idivl %2; xor %%edx, %%edx"
: "=A"(usdiff)
: "A"(usdiff * 1000), "rm"(vcpu->arch.virtual_tsc_khz));
#endif
F_114 ( V_257 , 1000 ) ;
V_259 -= V_257 ;
if ( V_259 < 0 )
V_259 = - V_259 ;
if ( V_259 < V_265 &&
V_2 -> V_5 . V_234 == V_82 -> V_5 . V_266 ) {
if ( ! F_123 () ) {
V_74 = V_82 -> V_5 . V_267 ;
F_104 ( L_4 , V_31 ) ;
} else {
T_2 V_268 = F_111 ( V_2 , V_257 ) ;
V_31 += V_268 ;
V_74 = V_56 -> V_262 ( V_2 , V_31 ) ;
F_104 ( L_5 , V_268 ) ;
}
V_260 = true ;
} else {
V_82 -> V_5 . V_269 ++ ;
V_82 -> V_5 . V_270 = V_256 ;
V_82 -> V_5 . V_271 = V_31 ;
V_82 -> V_5 . V_267 = V_74 ;
V_260 = false ;
F_104 ( L_6 ,
V_82 -> V_5 . V_269 , V_31 ) ;
}
V_82 -> V_5 . V_263 = V_256 ;
V_82 -> V_5 . V_264 = V_31 ;
V_82 -> V_5 . V_266 = V_2 -> V_5 . V_234 ;
V_2 -> V_5 . V_272 . V_273 = 0 ;
V_2 -> V_5 . V_274 = V_31 ;
V_2 -> V_5 . V_275 = V_82 -> V_5 . V_269 ;
V_2 -> V_5 . V_240 = V_82 -> V_5 . V_270 ;
V_2 -> V_5 . V_241 = V_82 -> V_5 . V_271 ;
if ( F_124 ( V_2 ) && ! V_21 -> V_184 )
F_120 ( V_2 , V_74 ) ;
V_56 -> V_276 ( V_2 , V_74 ) ;
F_125 ( & V_82 -> V_5 . V_261 , V_258 ) ;
F_126 ( & V_82 -> V_5 . V_277 ) ;
if ( V_260 )
V_82 -> V_5 . V_247 ++ ;
else
V_82 -> V_5 . V_247 = 0 ;
F_117 ( V_2 ) ;
F_127 ( & V_82 -> V_5 . V_277 ) ;
}
static T_11 F_128 ( void )
{
T_11 V_89 ;
T_2 V_278 ;
F_129 () ;
V_89 = ( T_11 ) F_130 () ;
V_278 = V_187 . clock . V_192 ;
if ( F_131 ( V_89 >= V_278 ) )
return V_89 ;
asm volatile ("");
return V_278 ;
}
static inline T_2 F_132 ( T_11 * V_279 )
{
long V_229 ;
struct V_187 * V_246 = & V_187 ;
* V_279 = F_128 () ;
V_229 = ( * V_279 - V_246 -> clock . V_192 ) & V_246 -> clock . V_27 ;
return V_229 * V_246 -> clock . V_193 ;
}
static int F_133 ( struct V_207 * V_210 , T_11 * V_279 )
{
unsigned long V_189 ;
T_2 V_256 ;
int V_280 ;
struct V_187 * V_246 = & V_187 ;
V_210 -> V_201 = 0 ;
do {
V_189 = F_134 ( & V_246 -> V_189 ) ;
V_280 = V_246 -> clock . V_190 ;
V_210 -> V_198 = V_246 -> V_195 ;
V_256 = V_246 -> V_199 ;
V_256 += F_132 ( V_279 ) ;
V_256 >>= V_246 -> clock . V_194 ;
} while ( F_71 ( F_135 ( & V_246 -> V_189 , V_189 ) ) );
F_136 ( V_210 , V_256 ) ;
return V_280 ;
}
static bool F_137 ( T_10 * V_238 , T_11 * V_279 )
{
struct V_207 V_210 ;
if ( V_187 . clock . V_190 != V_249 )
return false ;
if ( F_133 ( & V_210 , V_279 ) != V_249 )
return false ;
F_109 ( & V_210 ) ;
* V_238 = F_110 ( & V_210 ) ;
return true ;
}
static void F_138 ( struct V_82 * V_82 )
{
#ifdef F_52
struct V_244 * V_245 = & V_82 -> V_5 ;
int V_190 ;
bool V_281 , V_242 ;
V_242 = ( V_245 -> V_247 + 1 ==
F_118 ( & V_82 -> V_248 ) ) ;
V_281 = F_137 (
& V_245 -> V_282 ,
& V_245 -> V_283 ) ;
V_245 -> V_250 = V_281 & V_242 ;
if ( V_245 -> V_250 )
F_139 ( & V_284 , 1 ) ;
V_190 = V_187 . clock . V_190 ;
F_140 ( V_245 -> V_250 , V_190 ,
V_242 ) ;
#endif
}
static int F_141 ( struct V_1 * V_229 )
{
unsigned long V_258 , V_230 ;
struct V_285 * V_2 = & V_229 -> V_5 ;
struct V_244 * V_245 = & V_229 -> V_82 -> V_5 ;
T_10 V_238 , V_286 ;
T_2 V_273 , V_287 ;
struct V_288 V_289 ;
T_12 V_290 ;
bool V_250 ;
V_238 = 0 ;
V_287 = 0 ;
F_126 ( & V_245 -> V_277 ) ;
V_250 = V_245 -> V_250 ;
if ( V_250 ) {
V_287 = V_245 -> V_283 ;
V_238 = V_245 -> V_282 ;
}
F_127 ( & V_245 -> V_277 ) ;
F_142 ( V_258 ) ;
V_230 = F_143 ( V_291 ) ;
if ( F_71 ( V_230 == 0 ) ) {
F_144 ( V_258 ) ;
F_23 ( V_292 , V_229 ) ;
return 1 ;
}
if ( ! V_250 ) {
V_287 = F_145 () ;
V_238 = F_105 () ;
}
V_273 = V_56 -> V_293 ( V_229 , V_287 ) ;
if ( V_2 -> V_294 ) {
T_2 V_239 = F_116 ( V_229 , V_238 ) ;
if ( V_239 > V_273 ) {
F_146 ( V_229 , V_239 - V_273 ) ;
V_273 = V_239 ;
}
}
F_144 ( V_258 ) ;
if ( ! V_2 -> V_295 )
return 0 ;
V_286 = 0 ;
if ( V_2 -> V_272 . V_273 ) {
V_286 = V_2 -> V_274 -
V_2 -> V_272 . V_273 ;
V_286 = F_112 ( V_286 ,
V_2 -> V_272 . V_296 ,
V_2 -> V_272 . V_297 ) ;
V_286 += V_2 -> V_298 ;
}
if ( F_71 ( V_2 -> V_299 != V_230 ) ) {
F_103 ( V_202 / 1000 , V_230 ,
& V_2 -> V_272 . V_297 ,
& V_2 -> V_272 . V_296 ) ;
V_2 -> V_299 = V_230 ;
}
if ( ! V_250 ) {
if ( V_286 > V_238 )
V_238 = V_286 ;
}
V_2 -> V_272 . V_273 = V_273 ;
V_2 -> V_272 . V_300 = V_238 + V_229 -> V_82 -> V_5 . V_209 ;
V_2 -> V_298 = V_238 ;
V_2 -> V_274 = V_273 ;
V_2 -> V_272 . V_204 += 2 ;
if ( F_71 ( F_147 ( V_229 -> V_82 , & V_2 -> V_301 ,
& V_289 , sizeof( V_289 ) ) ) )
return 0 ;
V_290 = ( V_289 . V_258 & V_302 ) ;
if ( V_2 -> V_303 ) {
V_290 |= V_302 ;
V_2 -> V_303 = false ;
}
if ( V_250 )
V_290 |= V_304 ;
V_2 -> V_272 . V_258 = V_290 ;
F_148 ( V_229 -> V_82 , & V_2 -> V_301 ,
& V_2 -> V_272 ,
sizeof( V_2 -> V_272 ) ) ;
return 0 ;
}
static bool F_149 ( unsigned V_21 )
{
switch ( V_21 ) {
case 0x200 ... 0x200 + 2 * V_305 - 1 :
case V_306 :
case V_307 :
case V_308 :
case V_309 :
case V_310 :
case V_311 :
case V_312 :
case V_313 :
case V_314 :
case V_315 :
case V_316 :
case V_317 :
case V_318 :
return true ;
case 0x2f8 :
return true ;
}
return false ;
}
static bool F_150 ( unsigned V_319 )
{
return V_319 < 8 && ( 1 << V_319 ) & 0xf3 ;
}
static bool F_151 ( unsigned V_319 )
{
return V_319 < 8 && ( 1 << V_319 ) & 0x73 ;
}
static bool F_152 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
int V_3 ;
if ( ! F_149 ( V_21 ) )
return false ;
if ( V_21 == V_318 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_150 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
} else if ( V_21 == V_317 ) {
if ( V_31 & ~ 0xcff )
return false ;
return F_151 ( V_31 & 0xff ) ;
} else if ( V_21 >= V_306 && V_21 <= V_316 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
if ( ! F_151 ( ( V_31 >> ( V_3 * 8 ) ) & 0xff ) )
return false ;
return true ;
}
return F_151 ( V_31 & 0xff ) ;
}
static int F_153 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
T_2 * V_320 = ( T_2 * ) & V_2 -> V_5 . V_321 . V_322 ;
if ( ! F_152 ( V_2 , V_21 , V_31 ) )
return 1 ;
if ( V_21 == V_317 ) {
V_2 -> V_5 . V_321 . V_323 = V_31 ;
V_2 -> V_5 . V_321 . V_324 = ( V_31 & 0xc00 ) >> 10 ;
} else if ( V_21 == V_306 )
V_320 [ 0 ] = V_31 ;
else if ( V_21 == V_307 || V_21 == V_308 )
V_320 [ 1 + V_21 - V_307 ] = V_31 ;
else if ( V_21 >= V_309 && V_21 <= V_316 )
V_320 [ 3 + V_21 - V_309 ] = V_31 ;
else if ( V_21 == V_318 )
V_2 -> V_5 . V_325 = V_31 ;
else {
int V_326 , V_327 ;
T_2 * V_328 ;
V_326 = ( V_21 - 0x200 ) / 2 ;
V_327 = V_21 - 0x200 - 2 * V_326 ;
if ( ! V_327 )
V_328 =
( T_2 * ) & V_2 -> V_5 . V_321 . V_329 [ V_326 ] . V_330 ;
else
V_328 =
( T_2 * ) & V_2 -> V_5 . V_321 . V_329 [ V_326 ] . V_331 ;
* V_328 = V_31 ;
}
F_56 ( V_2 ) ;
return 0 ;
}
static int F_154 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
T_2 V_332 = V_2 -> V_5 . V_332 ;
unsigned V_333 = V_332 & 0xff ;
switch ( V_21 ) {
case V_334 :
V_2 -> V_5 . V_335 = V_31 ;
break;
case V_336 :
if ( ! ( V_332 & V_337 ) )
return 1 ;
if ( V_31 != 0 && V_31 != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_338 = V_31 ;
break;
default:
if ( V_21 >= V_339 &&
V_21 < V_339 + 4 * V_333 ) {
T_1 V_74 = V_21 - V_339 ;
if ( ( V_74 & 0x3 ) == 0 &&
V_31 != 0 && ( V_31 | ( 1 << 10 ) ) != ~ ( T_2 ) 0 )
return - 1 ;
V_2 -> V_5 . V_340 [ V_74 ] = V_31 ;
break;
}
return 1 ;
}
return 0 ;
}
static int F_155 ( struct V_1 * V_2 , T_2 V_31 )
{
struct V_82 * V_82 = V_2 -> V_82 ;
int V_341 = F_46 ( V_2 ) ;
T_12 * V_342 = V_341 ? ( T_12 * ) ( long ) V_82 -> V_5 . F_155 . V_343
: ( T_12 * ) ( long ) V_82 -> V_5 . F_155 . V_344 ;
T_12 V_345 = V_341 ? V_82 -> V_5 . F_155 . V_346
: V_82 -> V_5 . F_155 . V_347 ;
T_1 V_348 = V_31 & ~ V_349 ;
T_2 V_350 = V_31 & V_349 ;
T_12 * V_351 ;
int V_100 ;
V_100 = - V_352 ;
if ( V_348 >= V_345 )
goto V_94;
V_100 = - V_353 ;
V_351 = F_156 ( V_342 + ( V_348 * V_88 ) , V_88 ) ;
if ( F_157 ( V_351 ) ) {
V_100 = F_158 ( V_351 ) ;
goto V_94;
}
if ( F_98 ( V_82 , V_350 , V_351 , V_88 ) )
goto V_354;
V_100 = 0 ;
V_354:
F_159 ( V_351 ) ;
V_94:
return V_100 ;
}
static bool F_160 ( struct V_82 * V_82 )
{
return V_82 -> V_5 . V_355 & V_356 ;
}
static bool F_161 ( T_1 V_21 )
{
bool V_100 = false ;
switch ( V_21 ) {
case V_357 :
case V_358 :
V_100 = true ;
break;
}
return V_100 ;
}
static int F_162 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
struct V_82 * V_82 = V_2 -> V_82 ;
switch ( V_21 ) {
case V_357 :
V_82 -> V_5 . V_359 = V_31 ;
if ( ! V_82 -> V_5 . V_359 )
V_82 -> V_5 . V_355 &= ~ V_356 ;
break;
case V_358 : {
T_2 V_83 ;
unsigned long V_360 ;
T_12 V_361 [ 4 ] ;
if ( ! V_82 -> V_5 . V_359 )
break;
if ( ! ( V_31 & V_356 ) ) {
V_82 -> V_5 . V_355 = V_31 ;
break;
}
V_83 = V_31 >> V_362 ;
V_360 = F_163 ( V_82 , V_83 ) ;
if ( F_164 ( V_360 ) )
return 1 ;
V_56 -> V_363 ( V_2 , V_361 ) ;
( ( unsigned char * ) V_361 ) [ 3 ] = 0xc3 ;
if ( F_165 ( ( void V_364 * ) V_360 , V_361 , 4 ) )
return 1 ;
V_82 -> V_5 . V_355 = V_31 ;
break;
}
default:
F_166 ( V_2 , L_7
L_8 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_167 ( struct V_1 * V_2 , T_1 V_21 , T_2 V_31 )
{
switch ( V_21 ) {
case V_365 : {
unsigned long V_360 ;
if ( ! ( V_31 & V_366 ) ) {
V_2 -> V_5 . V_367 = V_31 ;
break;
}
V_360 = F_163 ( V_2 -> V_82 , V_31 >>
V_368 ) ;
if ( F_164 ( V_360 ) )
return 1 ;
if ( F_168 ( ( void V_364 * ) V_360 , V_88 ) )
return 1 ;
V_2 -> V_5 . V_367 = V_31 ;
break;
}
case V_369 :
return F_169 ( V_2 , V_370 , V_31 ) ;
case V_371 :
return F_169 ( V_2 , V_372 , V_31 ) ;
case V_373 :
return F_169 ( V_2 , V_374 , V_31 ) ;
default:
F_166 ( V_2 , L_7
L_8 , V_21 , V_31 ) ;
return 1 ;
}
return 0 ;
}
static int F_170 ( struct V_1 * V_2 , T_2 V_31 )
{
T_4 V_375 = V_31 & ~ 0x3f ;
if ( V_31 & 0x3c )
return 1 ;
V_2 -> V_5 . V_6 . V_376 = V_31 ;
if ( ! ( V_31 & V_377 ) ) {
F_55 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
if ( F_171 ( V_2 -> V_82 , & V_2 -> V_5 . V_6 . V_31 , V_375 ,
sizeof( T_1 ) ) )
return 1 ;
V_2 -> V_5 . V_6 . V_378 = ! ( V_31 & V_379 ) ;
F_172 ( V_2 ) ;
return 0 ;
}
static void F_173 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_295 = false ;
}
static void F_174 ( struct V_1 * V_2 )
{
T_2 V_268 ;
if ( ! ( V_2 -> V_5 . V_380 . V_376 & V_381 ) )
return;
V_268 = V_382 -> V_383 . V_384 - V_2 -> V_5 . V_380 . V_385 ;
V_2 -> V_5 . V_380 . V_385 = V_382 -> V_383 . V_384 ;
V_2 -> V_5 . V_380 . V_386 = V_268 ;
}
static void F_175 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_380 . V_376 & V_381 ) )
return;
if ( F_71 ( F_147 ( V_2 -> V_82 , & V_2 -> V_5 . V_380 . V_387 ,
& V_2 -> V_5 . V_380 . V_388 , sizeof( struct V_389 ) ) ) )
return;
V_2 -> V_5 . V_380 . V_388 . V_388 += V_2 -> V_5 . V_380 . V_386 ;
V_2 -> V_5 . V_380 . V_388 . V_204 += 2 ;
V_2 -> V_5 . V_380 . V_386 = 0 ;
F_148 ( V_2 -> V_82 , & V_2 -> V_5 . V_380 . V_387 ,
& V_2 -> V_5 . V_380 . V_388 , sizeof( struct V_389 ) ) ;
}
int F_176 ( struct V_1 * V_2 , struct V_182 * V_390 )
{
bool V_391 = false ;
T_1 V_21 = V_390 -> V_119 ;
T_2 V_31 = V_390 -> V_31 ;
switch ( V_21 ) {
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_397 :
break;
case V_398 :
return F_87 ( V_2 , V_31 ) ;
case V_399 :
V_31 &= ~ ( T_2 ) 0x40 ;
V_31 &= ~ ( T_2 ) 0x100 ;
V_31 &= ~ ( T_2 ) 0x8 ;
if ( V_31 != 0 ) {
F_166 ( V_2 , L_9 ,
V_31 ) ;
return 1 ;
}
break;
case V_400 :
if ( V_31 != 0 ) {
F_166 ( V_2 , L_10
L_11 , V_31 ) ;
return 1 ;
}
break;
case V_401 :
if ( ! V_31 ) {
break;
} else if ( V_31 & ~ ( V_402 | V_403 ) ) {
return 1 ;
}
F_166 ( V_2 , L_12 ,
V_224 , V_31 ) ;
break;
case 0x200 ... 0x2ff :
return F_153 ( V_2 , V_21 , V_31 ) ;
case V_404 :
F_19 ( V_2 , V_31 ) ;
break;
case V_405 ... V_405 + 0x3ff :
return F_177 ( V_2 , V_21 , V_31 ) ;
case V_406 :
F_178 ( V_2 , V_31 ) ;
break;
case V_407 :
if ( F_124 ( V_2 ) ) {
if ( ! V_390 -> V_184 ) {
T_2 V_408 = V_31 - V_2 -> V_5 . V_255 ;
V_56 -> V_409 ( V_2 , V_408 , true ) ;
}
V_2 -> V_5 . V_255 = V_31 ;
}
break;
case V_410 :
V_2 -> V_5 . V_411 = V_31 ;
break;
case V_412 :
case V_413 :
V_2 -> V_82 -> V_5 . V_203 = V_31 ;
F_96 ( V_2 -> V_82 , V_31 ) ;
break;
case V_414 :
case V_415 : {
T_2 V_416 ;
F_173 ( V_2 ) ;
V_2 -> V_5 . time = V_31 ;
F_23 ( V_292 , V_2 ) ;
if ( ! ( V_31 & 1 ) )
break;
V_416 = V_31 & ~ ( V_349 | 1 ) ;
if ( F_171 ( V_2 -> V_82 ,
& V_2 -> V_5 . V_301 , V_31 & ~ 1ULL ,
sizeof( struct V_288 ) ) )
V_2 -> V_5 . V_295 = false ;
else
V_2 -> V_5 . V_295 = true ;
break;
}
case V_417 :
if ( F_170 ( V_2 , V_31 ) )
return 1 ;
break;
case V_418 :
if ( F_71 ( ! F_179 () ) )
return 1 ;
if ( V_31 & V_419 )
return 1 ;
if ( F_171 ( V_2 -> V_82 , & V_2 -> V_5 . V_380 . V_387 ,
V_31 & V_420 ,
sizeof( struct V_389 ) ) )
return 1 ;
V_2 -> V_5 . V_380 . V_376 = V_31 ;
if ( ! ( V_31 & V_381 ) )
break;
V_2 -> V_5 . V_380 . V_385 = V_382 -> V_383 . V_384 ;
F_180 () ;
F_174 ( V_2 ) ;
F_181 () ;
F_23 ( V_421 , V_2 ) ;
break;
case V_422 :
if ( F_182 ( V_2 , V_31 ) )
return 1 ;
break;
case V_336 :
case V_334 :
case V_339 ... V_339 + 4 * V_423 - 1 :
return F_154 ( V_2 , V_21 , V_31 ) ;
case V_424 :
case V_425 :
case V_426 :
case V_427 :
if ( V_31 != 0 )
F_166 ( V_2 , L_13
L_14 , V_21 , V_31 ) ;
break;
case V_428 :
case V_429 :
case V_430 :
case V_431 :
F_166 ( V_2 , L_13
L_14 , V_21 , V_31 ) ;
break;
case V_432 :
case V_433 :
V_391 = true ;
case V_434 :
case V_435 :
if ( F_183 ( V_2 , V_21 ) )
return F_184 ( V_2 , V_21 , V_31 ) ;
if ( V_391 || V_31 != 0 )
F_166 ( V_2 , L_15
L_14 , V_21 , V_31 ) ;
break;
case V_436 :
break;
case V_357 ... V_437 :
if ( F_161 ( V_21 ) ) {
int V_100 ;
F_185 ( & V_2 -> V_82 -> V_438 ) ;
V_100 = F_162 ( V_2 , V_21 , V_31 ) ;
F_186 ( & V_2 -> V_82 -> V_438 ) ;
return V_100 ;
} else
return F_167 ( V_2 , V_21 , V_31 ) ;
break;
case V_439 :
F_166 ( V_2 , L_16 , V_21 , V_31 ) ;
break;
case V_440 :
if ( ! F_187 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_441 . V_442 = V_31 ;
break;
case V_443 :
if ( ! F_187 ( V_2 ) )
return 1 ;
V_2 -> V_5 . V_441 . V_444 = V_31 ;
break;
default:
if ( V_21 && ( V_21 == V_2 -> V_82 -> V_5 . F_155 . V_21 ) )
return F_155 ( V_2 , V_31 ) ;
if ( F_183 ( V_2 , V_21 ) )
return F_184 ( V_2 , V_21 , V_31 ) ;
if ( ! V_445 ) {
F_166 ( V_2 , L_17 ,
V_21 , V_31 ) ;
return 1 ;
} else {
F_166 ( V_2 , L_16 ,
V_21 , V_31 ) ;
break;
}
}
return 0 ;
}
int F_188 ( struct V_1 * V_2 , T_1 V_446 , T_2 * V_447 )
{
return V_56 -> V_448 ( V_2 , V_446 , V_447 ) ;
}
static int F_189 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_447 )
{
T_2 * V_320 = ( T_2 * ) & V_2 -> V_5 . V_321 . V_322 ;
if ( ! F_149 ( V_21 ) )
return 1 ;
if ( V_21 == V_317 )
* V_447 = V_2 -> V_5 . V_321 . V_323 +
( V_2 -> V_5 . V_321 . V_324 << 10 ) ;
else if ( V_21 == V_306 )
* V_447 = V_320 [ 0 ] ;
else if ( V_21 == V_307 || V_21 == V_308 )
* V_447 = V_320 [ 1 + V_21 - V_307 ] ;
else if ( V_21 >= V_309 && V_21 <= V_316 )
* V_447 = V_320 [ 3 + V_21 - V_309 ] ;
else if ( V_21 == V_318 )
* V_447 = V_2 -> V_5 . V_325 ;
else {
int V_326 , V_327 ;
T_2 * V_328 ;
V_326 = ( V_21 - 0x200 ) / 2 ;
V_327 = V_21 - 0x200 - 2 * V_326 ;
if ( ! V_327 )
V_328 =
( T_2 * ) & V_2 -> V_5 . V_321 . V_329 [ V_326 ] . V_330 ;
else
V_328 =
( T_2 * ) & V_2 -> V_5 . V_321 . V_329 [ V_326 ] . V_331 ;
* V_447 = * V_328 ;
}
return 0 ;
}
static int F_190 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_447 )
{
T_2 V_31 ;
T_2 V_332 = V_2 -> V_5 . V_332 ;
unsigned V_333 = V_332 & 0xff ;
switch ( V_21 ) {
case V_449 :
case V_450 :
V_31 = 0 ;
break;
case V_451 :
V_31 = V_2 -> V_5 . V_332 ;
break;
case V_336 :
if ( ! ( V_332 & V_337 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_338 ;
break;
case V_334 :
V_31 = V_2 -> V_5 . V_335 ;
break;
default:
if ( V_21 >= V_339 &&
V_21 < V_339 + 4 * V_333 ) {
T_1 V_74 = V_21 - V_339 ;
V_31 = V_2 -> V_5 . V_340 [ V_74 ] ;
break;
}
return 1 ;
}
* V_447 = V_31 ;
return 0 ;
}
static int F_191 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_447 )
{
T_2 V_31 = 0 ;
struct V_82 * V_82 = V_2 -> V_82 ;
switch ( V_21 ) {
case V_357 :
V_31 = V_82 -> V_5 . V_359 ;
break;
case V_358 :
V_31 = V_82 -> V_5 . V_355 ;
break;
default:
F_166 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_447 = V_31 ;
return 0 ;
}
static int F_192 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_447 )
{
T_2 V_31 = 0 ;
switch ( V_21 ) {
case V_452 : {
int V_100 ;
struct V_1 * V_229 ;
F_193 (r, v, vcpu->kvm)
if ( V_229 == V_2 )
V_31 = V_100 ;
break;
}
case V_369 :
return F_194 ( V_2 , V_370 , V_447 ) ;
case V_371 :
return F_194 ( V_2 , V_372 , V_447 ) ;
case V_373 :
return F_194 ( V_2 , V_374 , V_447 ) ;
case V_365 :
V_31 = V_2 -> V_5 . V_367 ;
break;
default:
F_166 ( V_2 , L_18 , V_21 ) ;
return 1 ;
}
* V_447 = V_31 ;
return 0 ;
}
int F_195 ( struct V_1 * V_2 , T_1 V_21 , T_2 * V_447 )
{
T_2 V_31 ;
switch ( V_21 ) {
case V_453 :
case V_454 :
case V_401 :
case V_455 :
case V_456 :
case V_457 :
case V_458 :
case V_459 :
case V_399 :
case V_395 :
case V_424 :
case V_428 :
case V_460 :
case V_392 :
case V_400 :
case V_397 :
V_31 = 0 ;
break;
case V_432 :
case V_433 :
case V_434 :
case V_435 :
if ( F_183 ( V_2 , V_21 ) )
return F_196 ( V_2 , V_21 , V_447 ) ;
V_31 = 0 ;
break;
case V_393 :
V_31 = 0x100000000ULL ;
break;
case V_461 :
V_31 = 0x500 | V_305 ;
break;
case 0x200 ... 0x2ff :
return F_189 ( V_2 , V_21 , V_447 ) ;
case 0xcd :
V_31 = 3 ;
break;
case V_462 :
V_31 = 1 << 24 ;
break;
case V_404 :
V_31 = F_18 ( V_2 ) ;
break;
case V_405 ... V_405 + 0x3ff :
return F_197 ( V_2 , V_21 , V_447 ) ;
break;
case V_406 :
V_31 = F_198 ( V_2 ) ;
break;
case V_407 :
V_31 = ( T_2 ) V_2 -> V_5 . V_255 ;
break;
case V_410 :
V_31 = V_2 -> V_5 . V_411 ;
break;
case V_463 :
V_31 = 1000ULL ;
V_31 |= ( ( ( T_7 ) 4ULL ) << 40 ) ;
break;
case V_398 :
V_31 = V_2 -> V_5 . V_111 ;
break;
case V_413 :
case V_412 :
V_31 = V_2 -> V_82 -> V_5 . V_203 ;
break;
case V_415 :
case V_414 :
V_31 = V_2 -> V_5 . time ;
break;
case V_417 :
V_31 = V_2 -> V_5 . V_6 . V_376 ;
break;
case V_418 :
V_31 = V_2 -> V_5 . V_380 . V_376 ;
break;
case V_422 :
V_31 = V_2 -> V_5 . V_464 . V_376 ;
break;
case V_449 :
case V_450 :
case V_451 :
case V_336 :
case V_334 :
case V_339 ... V_339 + 4 * V_423 - 1 :
return F_190 ( V_2 , V_21 , V_447 ) ;
case V_436 :
V_31 = 0x20000000 ;
break;
case V_357 ... V_437 :
if ( F_161 ( V_21 ) ) {
int V_100 ;
F_185 ( & V_2 -> V_82 -> V_438 ) ;
V_100 = F_191 ( V_2 , V_21 , V_447 ) ;
F_186 ( & V_2 -> V_82 -> V_438 ) ;
return V_100 ;
} else
return F_192 ( V_2 , V_21 , V_447 ) ;
break;
case V_439 :
V_31 = 0xbe702111 ;
break;
case V_440 :
if ( ! F_187 ( V_2 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_441 . V_442 ;
break;
case V_443 :
if ( ! F_187 ( V_2 ) )
return 1 ;
V_31 = V_2 -> V_5 . V_441 . V_444 ;
break;
default:
if ( F_183 ( V_2 , V_21 ) )
return F_196 ( V_2 , V_21 , V_447 ) ;
if ( ! V_445 ) {
F_166 ( V_2 , L_19 , V_21 ) ;
return 1 ;
} else {
F_166 ( V_2 , L_20 , V_21 ) ;
V_31 = 0 ;
}
break;
}
* V_447 = V_31 ;
return 0 ;
}
static int F_199 ( struct V_1 * V_2 , struct V_465 * V_19 ,
struct V_466 * V_467 ,
int (* F_200)( struct V_1 * V_2 ,
unsigned V_119 , T_2 * V_31 ) )
{
int V_3 , V_326 ;
V_326 = F_201 ( & V_2 -> V_82 -> V_468 ) ;
for ( V_3 = 0 ; V_3 < V_19 -> V_469 ; ++ V_3 )
if ( F_200 ( V_2 , V_467 [ V_3 ] . V_119 , & V_467 [ V_3 ] . V_31 ) )
break;
F_202 ( & V_2 -> V_82 -> V_468 , V_326 ) ;
return V_3 ;
}
static int F_203 ( struct V_1 * V_2 , struct V_465 V_364 * V_470 ,
int (* F_200)( struct V_1 * V_2 ,
unsigned V_119 , T_2 * V_31 ) ,
int V_471 )
{
struct V_465 V_19 ;
struct V_466 * V_467 ;
int V_100 , V_472 ;
unsigned V_473 ;
V_100 = - V_81 ;
if ( F_204 ( & V_19 , V_470 , sizeof V_19 ) )
goto V_94;
V_100 = - V_352 ;
if ( V_19 . V_469 >= V_474 )
goto V_94;
V_473 = sizeof( struct V_466 ) * V_19 . V_469 ;
V_467 = F_156 ( V_470 -> V_467 , V_473 ) ;
if ( F_157 ( V_467 ) ) {
V_100 = F_158 ( V_467 ) ;
goto V_94;
}
V_100 = V_472 = F_199 ( V_2 , & V_19 , V_467 , F_200 ) ;
if ( V_100 < 0 )
goto V_354;
V_100 = - V_81 ;
if ( V_471 && F_205 ( V_470 -> V_467 , V_467 , V_473 ) )
goto V_354;
V_100 = V_472 ;
V_354:
F_159 ( V_467 ) ;
V_94:
return V_100 ;
}
int F_206 ( long V_475 )
{
int V_100 ;
switch ( V_475 ) {
case V_476 :
case V_477 :
case V_478 :
case V_479 :
case V_480 :
case V_481 :
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
V_100 = 1 ;
break;
case V_511 :
V_100 = V_512 ;
break;
case V_513 :
V_100 = ! V_56 -> V_514 () ;
break;
case V_515 :
V_100 = V_516 ;
break;
case V_517 :
V_100 = V_518 ;
break;
case V_519 :
V_100 = V_520 ;
break;
case V_521 :
V_100 = 0 ;
break;
case V_522 :
V_100 = F_207 ( & V_523 ) ;
break;
case V_524 :
V_100 = V_423 ;
break;
case V_525 :
V_100 = V_526 ;
break;
case V_527 :
V_100 = V_528 ;
break;
case V_529 :
V_100 = F_208 ( V_530 ) ;
break;
default:
V_100 = 0 ;
break;
}
return V_100 ;
}
long F_209 ( struct V_531 * V_532 ,
unsigned int V_533 , unsigned long V_534 )
{
void V_364 * V_535 = ( void V_364 * ) V_534 ;
long V_100 ;
switch ( V_533 ) {
case V_536 : {
struct V_537 V_364 * V_538 = V_535 ;
struct V_537 V_539 ;
unsigned V_472 ;
V_100 = - V_81 ;
if ( F_204 ( & V_539 , V_538 , sizeof V_539 ) )
goto V_94;
V_472 = V_539 . V_469 ;
V_539 . V_469 = V_540 + F_42 ( V_541 ) ;
if ( F_205 ( V_538 , & V_539 , sizeof V_539 ) )
goto V_94;
V_100 = - V_352 ;
if ( V_472 < V_539 . V_469 )
goto V_94;
V_100 = - V_81 ;
if ( F_205 ( V_538 -> V_542 , & V_543 ,
V_540 * sizeof( T_1 ) ) )
goto V_94;
if ( F_205 ( V_538 -> V_542 + V_540 ,
& V_541 ,
F_42 ( V_541 ) * sizeof( T_1 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_544 : {
struct V_545 V_364 * V_546 = V_535 ;
struct V_545 V_547 ;
V_100 = - V_81 ;
if ( F_204 ( & V_547 , V_546 , sizeof V_547 ) )
goto V_94;
V_100 = F_210 ( & V_547 ,
V_546 -> V_467 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_205 ( V_546 , & V_547 , sizeof V_547 ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_548 : {
T_2 V_549 ;
V_549 = V_550 ;
V_100 = - V_81 ;
if ( F_205 ( V_535 , & V_549 , sizeof V_549 ) )
goto V_94;
V_100 = 0 ;
break;
}
default:
V_100 = - V_551 ;
}
V_94:
return V_100 ;
}
static void F_211 ( void * V_552 )
{
F_212 () ;
}
static bool F_213 ( struct V_1 * V_2 )
{
return V_2 -> V_82 -> V_5 . V_553 &&
! ( V_2 -> V_82 -> V_5 . V_554 & V_555 ) ;
}
void F_214 ( struct V_1 * V_2 , int V_23 )
{
if ( F_213 ( V_2 ) ) {
if ( V_56 -> V_556 () )
F_215 ( V_23 , V_2 -> V_5 . V_557 ) ;
else if ( V_2 -> V_23 != - 1 && V_2 -> V_23 != V_23 )
F_216 ( V_2 -> V_23 ,
F_211 , NULL , 1 ) ;
}
V_56 -> V_558 ( V_2 , V_23 ) ;
if ( F_71 ( V_2 -> V_5 . V_559 ) ) {
F_217 ( V_2 , V_2 -> V_5 . V_559 ) ;
V_2 -> V_5 . V_559 = 0 ;
F_218 ( V_292 , & V_2 -> V_560 ) ;
}
if ( F_71 ( V_2 -> V_23 != V_23 ) || F_123 () ) {
T_10 V_561 = ! V_2 -> V_5 . V_562 ? 0 :
F_145 () - V_2 -> V_5 . V_562 ;
if ( V_561 < 0 )
F_219 ( L_21 ) ;
if ( F_123 () ) {
T_2 V_74 = V_56 -> V_262 ( V_2 ,
V_2 -> V_5 . V_274 ) ;
V_56 -> V_276 ( V_2 , V_74 ) ;
V_2 -> V_5 . V_294 = 1 ;
}
if ( ! V_2 -> V_82 -> V_5 . V_250 || V_2 -> V_23 == - 1 )
F_23 ( V_292 , V_2 ) ;
if ( V_2 -> V_23 != V_23 )
F_220 ( V_2 ) ;
V_2 -> V_23 = V_23 ;
}
F_174 ( V_2 ) ;
F_23 ( V_421 , V_2 ) ;
}
void F_221 ( struct V_1 * V_2 )
{
V_56 -> V_563 ( V_2 ) ;
F_222 ( V_2 ) ;
V_2 -> V_5 . V_562 = F_145 () ;
}
static int F_223 ( struct V_1 * V_2 ,
struct V_564 * V_565 )
{
memcpy ( V_565 -> V_566 , V_2 -> V_5 . V_567 -> V_566 , sizeof *V_565 ) ;
return 0 ;
}
static int F_224 ( struct V_1 * V_2 ,
struct V_564 * V_565 )
{
F_225 ( V_2 , V_565 ) ;
F_226 ( V_2 ) ;
return 0 ;
}
static int F_227 ( struct V_1 * V_2 ,
struct V_568 * V_569 )
{
if ( V_569 -> V_569 < 0 || V_569 -> V_569 >= V_570 )
return - V_551 ;
if ( F_74 ( V_2 -> V_82 ) )
return - V_571 ;
F_228 ( V_2 , V_569 -> V_569 , false ) ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
static int F_229 ( struct V_1 * V_2 )
{
F_32 ( V_2 ) ;
return 0 ;
}
static int F_230 ( struct V_1 * V_2 ,
struct V_572 * V_573 )
{
if ( V_573 -> V_258 )
return - V_551 ;
V_2 -> V_5 . V_574 = ! ! V_573 -> V_324 ;
return 0 ;
}
static int F_231 ( struct V_1 * V_2 ,
T_2 V_332 )
{
int V_100 ;
unsigned V_333 = V_332 & 0xff , V_575 ;
V_100 = - V_551 ;
if ( ! V_333 || V_333 >= V_423 )
goto V_94;
if ( V_332 & ~ ( V_550 | 0xff | 0xff0000 ) )
goto V_94;
V_100 = 0 ;
V_2 -> V_5 . V_332 = V_332 ;
if ( V_332 & V_337 )
V_2 -> V_5 . V_338 = ~ ( T_2 ) 0 ;
for ( V_575 = 0 ; V_575 < V_333 ; V_575 ++ )
V_2 -> V_5 . V_340 [ V_575 * 4 ] = ~ ( T_2 ) 0 ;
V_94:
return V_100 ;
}
static int F_232 ( struct V_1 * V_2 ,
struct V_576 * V_577 )
{
T_2 V_332 = V_2 -> V_5 . V_332 ;
unsigned V_333 = V_332 & 0xff ;
T_2 * V_578 = V_2 -> V_5 . V_340 ;
if ( V_577 -> V_575 >= V_333 || ! ( V_577 -> V_444 & V_579 ) )
return - V_551 ;
if ( ( V_577 -> V_444 & V_580 ) && ( V_332 & V_337 ) &&
V_2 -> V_5 . V_338 != ~ ( T_2 ) 0 )
return 0 ;
V_578 += 4 * V_577 -> V_575 ;
if ( ( V_577 -> V_444 & V_580 ) && V_578 [ 0 ] != ~ ( T_2 ) 0 )
return 0 ;
if ( V_577 -> V_444 & V_580 ) {
if ( ( V_2 -> V_5 . V_335 & V_581 ) ||
! F_54 ( V_2 , V_582 ) ) {
F_23 ( V_54 , V_2 ) ;
return 0 ;
}
if ( V_578 [ 1 ] & V_579 )
V_577 -> V_444 |= V_583 ;
V_578 [ 2 ] = V_577 -> V_360 ;
V_578 [ 3 ] = V_577 -> V_584 ;
V_2 -> V_5 . V_335 = V_577 -> V_335 ;
V_578 [ 1 ] = V_577 -> V_444 ;
F_24 ( V_2 , V_585 ) ;
} else if ( ! ( V_578 [ 1 ] & V_579 )
|| ! ( V_578 [ 1 ] & V_580 ) ) {
if ( V_578 [ 1 ] & V_579 )
V_577 -> V_444 |= V_583 ;
V_578 [ 2 ] = V_577 -> V_360 ;
V_578 [ 3 ] = V_577 -> V_584 ;
V_578 [ 1 ] = V_577 -> V_444 ;
} else
V_578 [ 1 ] |= V_583 ;
return 0 ;
}
static void F_233 ( struct V_1 * V_2 ,
struct V_586 * V_587 )
{
F_234 ( V_2 ) ;
V_587 -> V_49 . V_588 =
V_2 -> V_5 . V_49 . V_50 &&
! F_235 ( V_2 -> V_5 . V_49 . V_16 ) ;
V_587 -> V_49 . V_16 = V_2 -> V_5 . V_49 . V_16 ;
V_587 -> V_49 . V_52 = V_2 -> V_5 . V_49 . V_52 ;
V_587 -> V_49 . V_589 = 0 ;
V_587 -> V_49 . V_43 = V_2 -> V_5 . V_49 . V_43 ;
V_587 -> V_590 . V_588 =
V_2 -> V_5 . V_590 . V_50 && ! V_2 -> V_5 . V_590 . V_591 ;
V_587 -> V_590 . V_16 = V_2 -> V_5 . V_590 . V_16 ;
V_587 -> V_590 . V_591 = 0 ;
V_587 -> V_590 . V_592 =
V_56 -> V_593 ( V_2 ,
V_594 | V_595 ) ;
V_587 -> V_596 . V_588 = V_2 -> V_5 . V_597 ;
V_587 -> V_596 . V_50 = V_2 -> V_5 . V_598 != 0 ;
V_587 -> V_596 . V_599 = V_56 -> V_600 ( V_2 ) ;
V_587 -> V_596 . V_589 = 0 ;
V_587 -> V_601 = V_2 -> V_5 . V_601 ;
V_587 -> V_258 = ( V_602
| V_603
| V_604 ) ;
memset ( & V_587 -> V_605 , 0 , sizeof( V_587 -> V_605 ) ) ;
}
static int F_236 ( struct V_1 * V_2 ,
struct V_586 * V_587 )
{
if ( V_587 -> V_258 & ~ ( V_602
| V_603
| V_604 ) )
return - V_551 ;
F_234 ( V_2 ) ;
V_2 -> V_5 . V_49 . V_50 = V_587 -> V_49 . V_588 ;
V_2 -> V_5 . V_49 . V_16 = V_587 -> V_49 . V_16 ;
V_2 -> V_5 . V_49 . V_52 = V_587 -> V_49 . V_52 ;
V_2 -> V_5 . V_49 . V_43 = V_587 -> V_49 . V_43 ;
V_2 -> V_5 . V_590 . V_50 = V_587 -> V_590 . V_588 ;
V_2 -> V_5 . V_590 . V_16 = V_587 -> V_590 . V_16 ;
V_2 -> V_5 . V_590 . V_591 = V_587 -> V_590 . V_591 ;
if ( V_587 -> V_258 & V_604 )
V_56 -> V_606 ( V_2 ,
V_587 -> V_590 . V_592 ) ;
V_2 -> V_5 . V_597 = V_587 -> V_596 . V_588 ;
if ( V_587 -> V_258 & V_602 )
V_2 -> V_5 . V_598 = V_587 -> V_596 . V_50 ;
V_56 -> V_607 ( V_2 , V_587 -> V_596 . V_599 ) ;
if ( V_587 -> V_258 & V_603 )
V_2 -> V_5 . V_601 = V_587 -> V_601 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
static void F_237 ( struct V_1 * V_2 ,
struct V_608 * V_609 )
{
memcpy ( V_609 -> V_157 , V_2 -> V_5 . V_157 , sizeof( V_2 -> V_5 . V_157 ) ) ;
V_609 -> V_160 = V_2 -> V_5 . V_160 ;
V_609 -> V_148 = V_2 -> V_5 . V_148 ;
V_609 -> V_258 = 0 ;
memset ( & V_609 -> V_605 , 0 , sizeof( V_609 -> V_605 ) ) ;
}
static int F_238 ( struct V_1 * V_2 ,
struct V_608 * V_609 )
{
if ( V_609 -> V_258 )
return - V_551 ;
memcpy ( V_2 -> V_5 . V_157 , V_609 -> V_157 , sizeof( V_2 -> V_5 . V_157 ) ) ;
V_2 -> V_5 . V_160 = V_609 -> V_160 ;
V_2 -> V_5 . V_148 = V_609 -> V_148 ;
return 0 ;
}
static void F_239 ( struct V_1 * V_2 ,
struct V_610 * V_611 )
{
if ( V_526 )
memcpy ( V_611 -> V_612 ,
& V_2 -> V_5 . V_613 . V_614 -> V_615 ,
V_616 ) ;
else {
memcpy ( V_611 -> V_612 ,
& V_2 -> V_5 . V_613 . V_614 -> V_617 ,
sizeof( struct V_618 ) ) ;
* ( T_2 * ) & V_611 -> V_612 [ V_619 / sizeof( T_1 ) ] =
V_620 ;
}
}
static int F_240 ( struct V_1 * V_2 ,
struct V_610 * V_611 )
{
T_2 V_621 =
* ( T_2 * ) & V_611 -> V_612 [ V_619 / sizeof( T_1 ) ] ;
if ( V_526 )
memcpy ( & V_2 -> V_5 . V_613 . V_614 -> V_615 ,
V_611 -> V_612 , V_616 ) ;
else {
if ( V_621 & ~ V_620 )
return - V_551 ;
memcpy ( & V_2 -> V_5 . V_613 . V_614 -> V_617 ,
V_611 -> V_612 , sizeof( struct V_618 ) ) ;
}
return 0 ;
}
static void F_241 ( struct V_1 * V_2 ,
struct V_622 * V_623 )
{
if ( ! V_526 ) {
V_623 -> V_624 = 0 ;
return;
}
V_623 -> V_624 = 1 ;
V_623 -> V_258 = 0 ;
V_623 -> V_625 [ 0 ] . V_120 = V_122 ;
V_623 -> V_625 [ 0 ] . V_22 = V_2 -> V_5 . V_121 ;
}
static int F_242 ( struct V_1 * V_2 ,
struct V_622 * V_623 )
{
int V_3 , V_100 = 0 ;
if ( ! V_526 )
return - V_551 ;
if ( V_623 -> V_624 > V_626 || V_623 -> V_258 )
return - V_551 ;
for ( V_3 = 0 ; V_3 < V_623 -> V_624 ; V_3 ++ )
if ( V_623 -> V_625 [ 0 ] . V_120 == V_122 ) {
V_100 = F_59 ( V_2 , V_122 ,
V_623 -> V_625 [ 0 ] . V_22 ) ;
break;
}
if ( V_100 )
V_100 = - V_551 ;
return V_100 ;
}
static int F_243 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 . V_295 )
return - V_551 ;
V_2 -> V_5 . V_303 = true ;
F_23 ( V_292 , V_2 ) ;
return 0 ;
}
long F_244 ( struct V_531 * V_532 ,
unsigned int V_533 , unsigned long V_534 )
{
struct V_1 * V_2 = V_532 -> V_627 ;
void V_364 * V_535 = ( void V_364 * ) V_534 ;
int V_100 ;
union {
struct V_564 * V_628 ;
struct V_610 * V_615 ;
struct V_622 * V_625 ;
void * V_629 ;
} V_630 ;
V_630 . V_629 = NULL ;
switch ( V_533 ) {
case V_631 : {
V_100 = - V_551 ;
if ( ! V_2 -> V_5 . V_567 )
goto V_94;
V_630 . V_628 = F_245 ( sizeof( struct V_564 ) , V_632 ) ;
V_100 = - V_353 ;
if ( ! V_630 . V_628 )
goto V_94;
V_100 = F_223 ( V_2 , V_630 . V_628 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_205 ( V_535 , V_630 . V_628 , sizeof( struct V_564 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_633 : {
V_100 = - V_551 ;
if ( ! V_2 -> V_5 . V_567 )
goto V_94;
V_630 . V_628 = F_156 ( V_535 , sizeof( * V_630 . V_628 ) ) ;
if ( F_157 ( V_630 . V_628 ) )
return F_158 ( V_630 . V_628 ) ;
V_100 = F_224 ( V_2 , V_630 . V_628 ) ;
break;
}
case V_634 : {
struct V_568 V_569 ;
V_100 = - V_81 ;
if ( F_204 ( & V_569 , V_535 , sizeof V_569 ) )
goto V_94;
V_100 = F_227 ( V_2 , & V_569 ) ;
break;
}
case V_635 : {
V_100 = F_229 ( V_2 ) ;
break;
}
case V_636 : {
struct V_637 V_364 * V_546 = V_535 ;
struct V_637 V_547 ;
V_100 = - V_81 ;
if ( F_204 ( & V_547 , V_546 , sizeof V_547 ) )
goto V_94;
V_100 = F_246 ( V_2 , & V_547 , V_546 -> V_467 ) ;
break;
}
case V_638 : {
struct V_545 V_364 * V_546 = V_535 ;
struct V_545 V_547 ;
V_100 = - V_81 ;
if ( F_204 ( & V_547 , V_546 , sizeof V_547 ) )
goto V_94;
V_100 = F_247 ( V_2 , & V_547 ,
V_546 -> V_467 ) ;
break;
}
case V_639 : {
struct V_545 V_364 * V_546 = V_535 ;
struct V_545 V_547 ;
V_100 = - V_81 ;
if ( F_204 ( & V_547 , V_546 , sizeof V_547 ) )
goto V_94;
V_100 = F_248 ( V_2 , & V_547 ,
V_546 -> V_467 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_205 ( V_546 , & V_547 , sizeof V_547 ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_640 :
V_100 = F_203 ( V_2 , V_535 , F_188 , 1 ) ;
break;
case V_641 :
V_100 = F_203 ( V_2 , V_535 , F_92 , 0 ) ;
break;
case V_642 : {
struct V_572 V_573 ;
V_100 = - V_81 ;
if ( F_204 ( & V_573 , V_535 , sizeof V_573 ) )
goto V_94;
V_100 = F_230 ( V_2 , & V_573 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_205 ( V_535 , & V_573 , sizeof V_573 ) )
goto V_94;
V_100 = 0 ;
break;
} ;
case V_643 : {
struct V_644 V_645 ;
V_100 = - V_551 ;
if ( ! F_74 ( V_2 -> V_82 ) )
goto V_94;
V_100 = - V_81 ;
if ( F_204 ( & V_645 , V_535 , sizeof V_645 ) )
goto V_94;
V_100 = 0 ;
F_249 ( V_2 , V_645 . V_646 ) ;
break;
}
case V_647 : {
T_2 V_332 ;
V_100 = - V_81 ;
if ( F_204 ( & V_332 , V_535 , sizeof V_332 ) )
goto V_94;
V_100 = F_231 ( V_2 , V_332 ) ;
break;
}
case V_648 : {
struct V_576 V_577 ;
V_100 = - V_81 ;
if ( F_204 ( & V_577 , V_535 , sizeof V_577 ) )
goto V_94;
V_100 = F_232 ( V_2 , & V_577 ) ;
break;
}
case V_649 : {
struct V_586 V_587 ;
F_233 ( V_2 , & V_587 ) ;
V_100 = - V_81 ;
if ( F_205 ( V_535 , & V_587 , sizeof( struct V_586 ) ) )
break;
V_100 = 0 ;
break;
}
case V_650 : {
struct V_586 V_587 ;
V_100 = - V_81 ;
if ( F_204 ( & V_587 , V_535 , sizeof( struct V_586 ) ) )
break;
V_100 = F_236 ( V_2 , & V_587 ) ;
break;
}
case V_651 : {
struct V_608 V_609 ;
F_237 ( V_2 , & V_609 ) ;
V_100 = - V_81 ;
if ( F_205 ( V_535 , & V_609 ,
sizeof( struct V_608 ) ) )
break;
V_100 = 0 ;
break;
}
case V_652 : {
struct V_608 V_609 ;
V_100 = - V_81 ;
if ( F_204 ( & V_609 , V_535 ,
sizeof( struct V_608 ) ) )
break;
V_100 = F_238 ( V_2 , & V_609 ) ;
break;
}
case V_653 : {
V_630 . V_615 = F_245 ( sizeof( struct V_610 ) , V_632 ) ;
V_100 = - V_353 ;
if ( ! V_630 . V_615 )
break;
F_239 ( V_2 , V_630 . V_615 ) ;
V_100 = - V_81 ;
if ( F_205 ( V_535 , V_630 . V_615 , sizeof( struct V_610 ) ) )
break;
V_100 = 0 ;
break;
}
case V_654 : {
V_630 . V_615 = F_156 ( V_535 , sizeof( * V_630 . V_615 ) ) ;
if ( F_157 ( V_630 . V_615 ) )
return F_158 ( V_630 . V_615 ) ;
V_100 = F_240 ( V_2 , V_630 . V_615 ) ;
break;
}
case V_655 : {
V_630 . V_625 = F_245 ( sizeof( struct V_622 ) , V_632 ) ;
V_100 = - V_353 ;
if ( ! V_630 . V_625 )
break;
F_241 ( V_2 , V_630 . V_625 ) ;
V_100 = - V_81 ;
if ( F_205 ( V_535 , V_630 . V_625 ,
sizeof( struct V_622 ) ) )
break;
V_100 = 0 ;
break;
}
case V_656 : {
V_630 . V_625 = F_156 ( V_535 , sizeof( * V_630 . V_625 ) ) ;
if ( F_157 ( V_630 . V_625 ) )
return F_158 ( V_630 . V_625 ) ;
V_100 = F_242 ( V_2 , V_630 . V_625 ) ;
break;
}
case V_657 : {
T_1 V_658 ;
V_100 = - V_551 ;
V_658 = ( T_1 ) V_534 ;
if ( V_658 >= V_659 )
goto V_94;
if ( V_658 == 0 )
V_658 = V_235 ;
F_115 ( V_2 , V_658 ) ;
V_100 = 0 ;
goto V_94;
}
case V_660 : {
V_100 = V_2 -> V_5 . V_234 ;
goto V_94;
}
case V_661 : {
V_100 = F_243 ( V_2 ) ;
goto V_94;
}
default:
V_100 = - V_551 ;
}
V_94:
F_159 ( V_630 . V_629 ) ;
return V_100 ;
}
int F_250 ( struct V_1 * V_2 , struct V_662 * V_663 )
{
return V_664 ;
}
static int F_251 ( struct V_82 * V_82 , unsigned long V_360 )
{
int V_89 ;
if ( V_360 > ( unsigned int ) ( - 3 * V_88 ) )
return - V_551 ;
V_89 = V_56 -> V_665 ( V_82 , V_360 ) ;
return V_89 ;
}
static int F_252 ( struct V_82 * V_82 ,
T_2 V_666 )
{
V_82 -> V_5 . V_667 = V_666 ;
return 0 ;
}
static int F_253 ( struct V_82 * V_82 ,
T_1 V_668 )
{
if ( V_668 < V_669 )
return - V_551 ;
F_185 ( & V_82 -> V_670 ) ;
F_254 ( V_82 , V_668 ) ;
V_82 -> V_5 . V_671 = V_668 ;
F_186 ( & V_82 -> V_670 ) ;
return 0 ;
}
static int F_255 ( struct V_82 * V_82 )
{
return V_82 -> V_5 . V_672 ;
}
static int F_256 ( struct V_82 * V_82 , struct V_673 * V_674 )
{
int V_100 ;
V_100 = 0 ;
switch ( V_674 -> V_675 ) {
case V_676 :
memcpy ( & V_674 -> V_674 . V_677 ,
& F_257 ( V_82 ) -> V_678 [ 0 ] ,
sizeof( struct V_679 ) ) ;
break;
case V_680 :
memcpy ( & V_674 -> V_674 . V_677 ,
& F_257 ( V_82 ) -> V_678 [ 1 ] ,
sizeof( struct V_679 ) ) ;
break;
case V_681 :
V_100 = F_258 ( V_82 , & V_674 -> V_674 . V_682 ) ;
break;
default:
V_100 = - V_551 ;
break;
}
return V_100 ;
}
static int F_259 ( struct V_82 * V_82 , struct V_673 * V_674 )
{
int V_100 ;
V_100 = 0 ;
switch ( V_674 -> V_675 ) {
case V_676 :
F_126 ( & F_257 ( V_82 ) -> V_438 ) ;
memcpy ( & F_257 ( V_82 ) -> V_678 [ 0 ] ,
& V_674 -> V_674 . V_677 ,
sizeof( struct V_679 ) ) ;
F_127 ( & F_257 ( V_82 ) -> V_438 ) ;
break;
case V_680 :
F_126 ( & F_257 ( V_82 ) -> V_438 ) ;
memcpy ( & F_257 ( V_82 ) -> V_678 [ 1 ] ,
& V_674 -> V_674 . V_677 ,
sizeof( struct V_679 ) ) ;
F_127 ( & F_257 ( V_82 ) -> V_438 ) ;
break;
case V_681 :
V_100 = F_260 ( V_82 , & V_674 -> V_674 . V_682 ) ;
break;
default:
V_100 = - V_551 ;
break;
}
F_261 ( F_257 ( V_82 ) ) ;
return V_100 ;
}
static int F_262 ( struct V_82 * V_82 , struct V_683 * V_684 )
{
int V_100 = 0 ;
F_185 ( & V_82 -> V_5 . V_685 -> V_686 . V_438 ) ;
memcpy ( V_684 , & V_82 -> V_5 . V_685 -> V_686 , sizeof( struct V_683 ) ) ;
F_186 ( & V_82 -> V_5 . V_685 -> V_686 . V_438 ) ;
return V_100 ;
}
static int F_263 ( struct V_82 * V_82 , struct V_683 * V_684 )
{
int V_100 = 0 ;
F_185 ( & V_82 -> V_5 . V_685 -> V_686 . V_438 ) ;
memcpy ( & V_82 -> V_5 . V_685 -> V_686 , V_684 , sizeof( struct V_683 ) ) ;
F_264 ( V_82 , 0 , V_684 -> V_687 [ 0 ] . V_688 , 0 ) ;
F_186 ( & V_82 -> V_5 . V_685 -> V_686 . V_438 ) ;
return V_100 ;
}
static int F_265 ( struct V_82 * V_82 , struct V_689 * V_684 )
{
int V_100 = 0 ;
F_185 ( & V_82 -> V_5 . V_685 -> V_686 . V_438 ) ;
memcpy ( V_684 -> V_687 , & V_82 -> V_5 . V_685 -> V_686 . V_687 ,
sizeof( V_684 -> V_687 ) ) ;
V_684 -> V_258 = V_82 -> V_5 . V_685 -> V_686 . V_258 ;
F_186 ( & V_82 -> V_5 . V_685 -> V_686 . V_438 ) ;
memset ( & V_684 -> V_605 , 0 , sizeof( V_684 -> V_605 ) ) ;
return V_100 ;
}
static int F_266 ( struct V_82 * V_82 , struct V_689 * V_684 )
{
int V_100 = 0 , V_690 = 0 ;
T_1 V_691 , V_692 ;
F_185 ( & V_82 -> V_5 . V_685 -> V_686 . V_438 ) ;
V_691 = V_82 -> V_5 . V_685 -> V_686 . V_258 & V_693 ;
V_692 = V_684 -> V_258 & V_693 ;
if ( ! V_691 && V_692 )
V_690 = 1 ;
memcpy ( & V_82 -> V_5 . V_685 -> V_686 . V_687 , & V_684 -> V_687 ,
sizeof( V_82 -> V_5 . V_685 -> V_686 . V_687 ) ) ;
V_82 -> V_5 . V_685 -> V_686 . V_258 = V_684 -> V_258 ;
F_264 ( V_82 , 0 , V_82 -> V_5 . V_685 -> V_686 . V_687 [ 0 ] . V_688 , V_690 ) ;
F_186 ( & V_82 -> V_5 . V_685 -> V_686 . V_438 ) ;
return V_100 ;
}
static int F_267 ( struct V_82 * V_82 ,
struct V_694 * V_695 )
{
if ( ! V_82 -> V_5 . V_685 )
return - V_571 ;
F_185 ( & V_82 -> V_5 . V_685 -> V_686 . V_438 ) ;
V_82 -> V_5 . V_685 -> V_686 . V_44 = V_695 -> V_696 ;
F_186 ( & V_82 -> V_5 . V_685 -> V_686 . V_438 ) ;
return 0 ;
}
int F_268 ( struct V_82 * V_82 , struct V_697 * log )
{
int V_100 ;
struct V_698 * V_699 ;
unsigned long V_472 , V_3 ;
unsigned long * V_700 ;
unsigned long * V_701 ;
bool V_702 = false ;
F_185 ( & V_82 -> V_670 ) ;
V_100 = - V_551 ;
if ( log -> V_10 >= V_520 )
goto V_94;
V_699 = F_269 ( V_82 -> V_703 , log -> V_10 ) ;
V_700 = V_699 -> V_700 ;
V_100 = - V_704 ;
if ( ! V_700 )
goto V_94;
V_472 = F_270 ( V_699 ) ;
V_701 = V_700 + V_472 / sizeof( long ) ;
memset ( V_701 , 0 , V_472 ) ;
F_126 ( & V_82 -> V_705 ) ;
for ( V_3 = 0 ; V_3 < V_472 / sizeof( long ) ; V_3 ++ ) {
unsigned long V_27 ;
T_3 V_74 ;
if ( ! V_700 [ V_3 ] )
continue;
V_702 = true ;
V_27 = F_271 ( & V_700 [ V_3 ] , 0 ) ;
V_701 [ V_3 ] = V_27 ;
V_74 = V_3 * V_706 ;
F_272 ( V_82 , V_699 , V_74 , V_27 ) ;
}
if ( V_702 )
F_273 ( V_82 ) ;
F_127 ( & V_82 -> V_705 ) ;
V_100 = - V_81 ;
if ( F_205 ( log -> V_700 , V_701 , V_472 ) )
goto V_94;
V_100 = 0 ;
V_94:
F_186 ( & V_82 -> V_670 ) ;
return V_100 ;
}
int F_274 ( struct V_82 * V_82 , struct V_707 * V_708 )
{
if ( ! F_74 ( V_82 ) )
return - V_571 ;
V_708 -> V_444 = F_275 ( V_82 , V_709 ,
V_708 -> V_569 , V_708 -> V_710 ) ;
return 0 ;
}
long F_276 ( struct V_531 * V_532 ,
unsigned int V_533 , unsigned long V_534 )
{
struct V_82 * V_82 = V_532 -> V_627 ;
void V_364 * V_535 = ( void V_364 * ) V_534 ;
int V_100 = - V_711 ;
union {
struct V_683 V_684 ;
struct V_689 V_712 ;
struct V_713 V_714 ;
} V_630 ;
switch ( V_533 ) {
case V_715 :
V_100 = F_251 ( V_82 , V_534 ) ;
break;
case V_716 : {
T_2 V_666 ;
V_100 = - V_81 ;
if ( F_204 ( & V_666 , V_535 , sizeof V_666 ) )
goto V_94;
V_100 = F_252 ( V_82 , V_666 ) ;
break;
}
case V_717 :
V_100 = F_253 ( V_82 , V_534 ) ;
break;
case V_718 :
V_100 = F_255 ( V_82 ) ;
break;
case V_719 : {
struct V_720 * V_721 ;
F_185 ( & V_82 -> V_438 ) ;
V_100 = - V_722 ;
if ( V_82 -> V_5 . V_721 )
goto V_723;
V_100 = - V_551 ;
if ( F_118 ( & V_82 -> V_248 ) )
goto V_723;
V_100 = - V_353 ;
V_721 = F_277 ( V_82 ) ;
if ( V_721 ) {
V_100 = F_278 ( V_82 ) ;
if ( V_100 ) {
F_185 ( & V_82 -> V_670 ) ;
F_279 ( V_82 , V_724 ,
& V_721 -> V_725 ) ;
F_279 ( V_82 , V_724 ,
& V_721 -> V_726 ) ;
F_279 ( V_82 , V_724 ,
& V_721 -> V_727 ) ;
F_186 ( & V_82 -> V_670 ) ;
F_159 ( V_721 ) ;
goto V_723;
}
} else
goto V_723;
F_13 () ;
V_82 -> V_5 . V_721 = V_721 ;
F_13 () ;
V_100 = F_280 ( V_82 ) ;
if ( V_100 ) {
F_185 ( & V_82 -> V_670 ) ;
F_185 ( & V_82 -> V_728 ) ;
F_281 ( V_82 ) ;
F_282 ( V_82 ) ;
F_186 ( & V_82 -> V_728 ) ;
F_186 ( & V_82 -> V_670 ) ;
}
V_723:
F_186 ( & V_82 -> V_438 ) ;
break;
}
case V_729 :
V_630 . V_714 . V_258 = V_730 ;
goto V_731;
case V_732 :
V_100 = - V_81 ;
if ( F_204 ( & V_630 . V_714 , V_535 ,
sizeof( struct V_713 ) ) )
goto V_94;
V_731:
F_185 ( & V_82 -> V_670 ) ;
V_100 = - V_722 ;
if ( V_82 -> V_5 . V_685 )
goto V_733;
V_100 = - V_353 ;
V_82 -> V_5 . V_685 = F_283 ( V_82 , V_630 . V_714 . V_258 ) ;
if ( V_82 -> V_5 . V_685 )
V_100 = 0 ;
V_733:
F_186 ( & V_82 -> V_670 ) ;
break;
case V_734 : {
struct V_673 * V_674 ;
V_674 = F_156 ( V_535 , sizeof( * V_674 ) ) ;
if ( F_157 ( V_674 ) ) {
V_100 = F_158 ( V_674 ) ;
goto V_94;
}
V_100 = - V_571 ;
if ( ! F_74 ( V_82 ) )
goto V_735;
V_100 = F_256 ( V_82 , V_674 ) ;
if ( V_100 )
goto V_735;
V_100 = - V_81 ;
if ( F_205 ( V_535 , V_674 , sizeof *V_674 ) )
goto V_735;
V_100 = 0 ;
V_735:
F_159 ( V_674 ) ;
break;
}
case V_736 : {
struct V_673 * V_674 ;
V_674 = F_156 ( V_535 , sizeof( * V_674 ) ) ;
if ( F_157 ( V_674 ) ) {
V_100 = F_158 ( V_674 ) ;
goto V_94;
}
V_100 = - V_571 ;
if ( ! F_74 ( V_82 ) )
goto V_737;
V_100 = F_259 ( V_82 , V_674 ) ;
if ( V_100 )
goto V_737;
V_100 = 0 ;
V_737:
F_159 ( V_674 ) ;
break;
}
case V_738 : {
V_100 = - V_81 ;
if ( F_204 ( & V_630 . V_684 , V_535 , sizeof( struct V_683 ) ) )
goto V_94;
V_100 = - V_571 ;
if ( ! V_82 -> V_5 . V_685 )
goto V_94;
V_100 = F_262 ( V_82 , & V_630 . V_684 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_205 ( V_535 , & V_630 . V_684 , sizeof( struct V_683 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_739 : {
V_100 = - V_81 ;
if ( F_204 ( & V_630 . V_684 , V_535 , sizeof V_630 . V_684 ) )
goto V_94;
V_100 = - V_571 ;
if ( ! V_82 -> V_5 . V_685 )
goto V_94;
V_100 = F_263 ( V_82 , & V_630 . V_684 ) ;
break;
}
case V_740 : {
V_100 = - V_571 ;
if ( ! V_82 -> V_5 . V_685 )
goto V_94;
V_100 = F_265 ( V_82 , & V_630 . V_712 ) ;
if ( V_100 )
goto V_94;
V_100 = - V_81 ;
if ( F_205 ( V_535 , & V_630 . V_712 , sizeof( V_630 . V_712 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
case V_741 : {
V_100 = - V_81 ;
if ( F_204 ( & V_630 . V_712 , V_535 , sizeof( V_630 . V_712 ) ) )
goto V_94;
V_100 = - V_571 ;
if ( ! V_82 -> V_5 . V_685 )
goto V_94;
V_100 = F_266 ( V_82 , & V_630 . V_712 ) ;
break;
}
case V_742 : {
struct V_694 V_695 ;
V_100 = - V_81 ;
if ( F_204 ( & V_695 , V_535 , sizeof( V_695 ) ) )
goto V_94;
V_100 = F_267 ( V_82 , & V_695 ) ;
break;
}
case V_743 : {
V_100 = - V_81 ;
if ( F_204 ( & V_82 -> V_5 . F_155 , V_535 ,
sizeof( struct V_744 ) ) )
goto V_94;
V_100 = - V_551 ;
if ( V_82 -> V_5 . F_155 . V_258 )
goto V_94;
V_100 = 0 ;
break;
}
case V_745 : {
struct V_746 V_747 ;
T_2 V_748 ;
T_10 V_268 ;
V_100 = - V_81 ;
if ( F_204 ( & V_747 , V_535 , sizeof( V_747 ) ) )
goto V_94;
V_100 = - V_551 ;
if ( V_747 . V_258 )
goto V_94;
V_100 = 0 ;
F_284 () ;
V_748 = F_105 () ;
V_268 = V_747 . clock - V_748 ;
F_285 () ;
V_82 -> V_5 . V_209 = V_268 ;
break;
}
case V_749 : {
struct V_746 V_747 ;
T_2 V_748 ;
F_284 () ;
V_748 = F_105 () ;
V_747 . clock = V_82 -> V_5 . V_209 + V_748 ;
F_285 () ;
V_747 . V_258 = 0 ;
memset ( & V_747 . V_589 , 0 , sizeof( V_747 . V_589 ) ) ;
V_100 = - V_81 ;
if ( F_205 ( V_535 , & V_747 , sizeof( V_747 ) ) )
goto V_94;
V_100 = 0 ;
break;
}
default:
;
}
V_94:
return V_100 ;
}
static void F_286 ( void )
{
T_1 V_750 [ 2 ] ;
unsigned V_3 , V_751 ;
for ( V_3 = V_751 = V_752 ; V_3 < F_42 ( V_543 ) ; V_3 ++ ) {
if ( F_287 ( V_543 [ V_3 ] , & V_750 [ 0 ] , & V_750 [ 1 ] ) < 0 )
continue;
if ( V_751 < V_3 )
V_543 [ V_751 ] = V_543 [ V_3 ] ;
V_751 ++ ;
}
V_540 = V_751 ;
}
static int F_288 ( struct V_1 * V_2 , T_4 V_360 , int V_75 ,
const void * V_229 )
{
int V_753 = 0 ;
int V_472 ;
do {
V_472 = F_289 ( V_75 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_567 &&
! F_290 ( & V_2 -> V_5 . V_567 -> V_754 , V_360 , V_472 , V_229 ) )
&& F_291 ( V_2 -> V_82 , V_755 , V_360 , V_472 , V_229 ) )
break;
V_753 += V_472 ;
V_360 += V_472 ;
V_75 -= V_472 ;
V_229 += V_472 ;
} while ( V_75 );
return V_753 ;
}
static int F_292 ( struct V_1 * V_2 , T_4 V_360 , int V_75 , void * V_229 )
{
int V_753 = 0 ;
int V_472 ;
do {
V_472 = F_289 ( V_75 , 8 ) ;
if ( ! ( V_2 -> V_5 . V_567 &&
! F_293 ( & V_2 -> V_5 . V_567 -> V_754 , V_360 , V_472 , V_229 ) )
&& F_294 ( V_2 -> V_82 , V_755 , V_360 , V_472 , V_229 ) )
break;
F_295 ( V_756 , V_472 , V_360 , * ( T_2 * ) V_229 ) ;
V_753 += V_472 ;
V_360 += V_472 ;
V_75 -= V_472 ;
V_229 += V_472 ;
} while ( V_75 );
return V_753 ;
}
static void F_296 ( struct V_1 * V_2 ,
struct V_757 * V_758 , int V_759 )
{
V_56 -> V_760 ( V_2 , V_758 , V_759 ) ;
}
void F_297 ( struct V_1 * V_2 ,
struct V_757 * V_758 , int V_759 )
{
V_56 -> V_761 ( V_2 , V_758 , V_759 ) ;
}
T_4 F_298 ( struct V_1 * V_2 , T_4 V_375 , T_1 V_76 )
{
T_4 V_762 ;
struct V_58 V_49 ;
F_299 ( ! F_31 ( V_2 ) ) ;
V_76 |= V_92 ;
V_762 = V_2 -> V_5 . V_67 . V_763 ( V_2 , V_375 , V_76 , & V_49 ) ;
return V_762 ;
}
T_4 F_300 ( struct V_1 * V_2 , T_13 V_764 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
return V_2 -> V_5 . V_84 -> V_763 ( V_2 , V_764 , V_76 , V_49 ) ;
}
T_4 F_301 ( struct V_1 * V_2 , T_13 V_764 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
V_76 |= V_765 ;
return V_2 -> V_5 . V_84 -> V_763 ( V_2 , V_764 , V_76 , V_49 ) ;
}
T_4 F_302 ( struct V_1 * V_2 , T_13 V_764 ,
struct V_58 * V_49 )
{
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
V_76 |= V_93 ;
return V_2 -> V_5 . V_84 -> V_763 ( V_2 , V_764 , V_76 , V_49 ) ;
}
T_4 F_303 ( struct V_1 * V_2 , T_13 V_764 ,
struct V_58 * V_49 )
{
return V_2 -> V_5 . V_84 -> V_763 ( V_2 , V_764 , 0 , V_49 ) ;
}
static int F_304 ( T_13 V_360 , void * V_156 , unsigned int V_766 ,
struct V_1 * V_2 , T_1 V_76 ,
struct V_58 * V_49 )
{
void * V_31 = V_156 ;
int V_100 = V_767 ;
while ( V_766 ) {
T_4 V_375 = V_2 -> V_5 . V_84 -> V_763 ( V_2 , V_360 , V_76 ,
V_49 ) ;
unsigned V_74 = V_360 & ( V_88 - 1 ) ;
unsigned V_768 = F_289 ( V_766 , ( unsigned ) V_88 - V_74 ) ;
int V_89 ;
if ( V_375 == V_80 )
return V_769 ;
V_89 = F_97 ( V_2 -> V_82 , V_375 , V_31 , V_768 ) ;
if ( V_89 < 0 ) {
V_100 = V_770 ;
goto V_94;
}
V_766 -= V_768 ;
V_31 += V_768 ;
V_360 += V_768 ;
}
V_94:
return V_100 ;
}
static int F_305 ( struct V_771 * V_772 ,
T_13 V_360 , void * V_156 , unsigned int V_766 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_306 ( V_772 ) ;
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
return F_304 ( V_360 , V_156 , V_766 , V_2 ,
V_76 | V_765 ,
V_49 ) ;
}
int F_307 ( struct V_771 * V_772 ,
T_13 V_360 , void * V_156 , unsigned int V_766 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_306 ( V_772 ) ;
T_1 V_76 = ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 ;
return F_304 ( V_360 , V_156 , V_766 , V_2 , V_76 ,
V_49 ) ;
}
static int F_308 ( struct V_771 * V_772 ,
T_13 V_360 , void * V_156 , unsigned int V_766 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_306 ( V_772 ) ;
return F_304 ( V_360 , V_156 , V_766 , V_2 , 0 , V_49 ) ;
}
int F_309 ( struct V_771 * V_772 ,
T_13 V_360 , void * V_156 ,
unsigned int V_766 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_306 ( V_772 ) ;
void * V_31 = V_156 ;
int V_100 = V_767 ;
while ( V_766 ) {
T_4 V_375 = V_2 -> V_5 . V_84 -> V_763 ( V_2 , V_360 ,
V_93 ,
V_49 ) ;
unsigned V_74 = V_360 & ( V_88 - 1 ) ;
unsigned V_773 = F_289 ( V_766 , ( unsigned ) V_88 - V_74 ) ;
int V_89 ;
if ( V_375 == V_80 )
return V_769 ;
V_89 = F_98 ( V_2 -> V_82 , V_375 , V_31 , V_773 ) ;
if ( V_89 < 0 ) {
V_100 = V_770 ;
goto V_94;
}
V_766 -= V_773 ;
V_31 += V_773 ;
V_360 += V_773 ;
}
V_94:
return V_100 ;
}
static int F_310 ( struct V_1 * V_2 , unsigned long V_764 ,
T_4 * V_375 , struct V_58 * V_49 ,
bool V_774 )
{
T_1 V_76 = ( ( V_56 -> V_71 ( V_2 ) == 3 ) ? V_92 : 0 )
| ( V_774 ? V_93 : 0 ) ;
if ( F_311 ( V_2 , V_764 )
&& ! F_312 ( V_2 -> V_5 . V_84 , V_2 -> V_5 . V_76 , V_76 ) ) {
* V_375 = V_2 -> V_5 . V_775 << V_87 |
( V_764 & ( V_88 - 1 ) ) ;
F_313 ( V_764 , * V_375 , V_774 , false ) ;
return 1 ;
}
* V_375 = V_2 -> V_5 . V_84 -> V_763 ( V_2 , V_764 , V_76 , V_49 ) ;
if ( * V_375 == V_80 )
return - 1 ;
if ( ( * V_375 & V_349 ) == V_776 )
return 1 ;
if ( F_314 ( V_2 , * V_375 ) ) {
F_313 ( V_764 , * V_375 , V_774 , true ) ;
return 1 ;
}
return 0 ;
}
int F_315 ( struct V_1 * V_2 , T_4 V_375 ,
const void * V_156 , int V_766 )
{
int V_89 ;
V_89 = F_98 ( V_2 -> V_82 , V_375 , V_156 , V_766 ) ;
if ( V_89 < 0 )
return 0 ;
F_316 ( V_2 , V_375 , V_156 , V_766 ) ;
return 1 ;
}
static int F_317 ( struct V_1 * V_2 , void * V_156 , int V_766 )
{
if ( V_2 -> V_777 ) {
F_295 ( V_756 , V_766 ,
V_2 -> V_778 [ 0 ] . V_375 , * ( T_2 * ) V_156 ) ;
V_2 -> V_777 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_318 ( struct V_1 * V_2 , T_4 V_375 ,
void * V_156 , int V_766 )
{
return ! F_97 ( V_2 -> V_82 , V_375 , V_156 , V_766 ) ;
}
static int F_319 ( struct V_1 * V_2 , T_4 V_375 ,
void * V_156 , int V_766 )
{
return F_315 ( V_2 , V_375 , V_156 , V_766 ) ;
}
static int F_320 ( struct V_1 * V_2 , T_4 V_375 , int V_766 , void * V_156 )
{
F_295 ( V_779 , V_766 , V_375 , * ( T_2 * ) V_156 ) ;
return F_288 ( V_2 , V_375 , V_766 , V_156 ) ;
}
static int F_321 ( struct V_1 * V_2 , T_4 V_375 ,
void * V_156 , int V_766 )
{
F_295 ( V_780 , V_766 , V_375 , 0 ) ;
return V_770 ;
}
static int F_322 ( struct V_1 * V_2 , T_4 V_375 ,
void * V_156 , int V_766 )
{
struct V_781 * V_782 = & V_2 -> V_778 [ 0 ] ;
memcpy ( V_2 -> V_783 -> V_784 . V_31 , V_782 -> V_31 , F_289 ( 8u , V_782 -> V_75 ) ) ;
return V_767 ;
}
static int F_323 ( unsigned long V_360 , void * V_156 ,
unsigned int V_766 ,
struct V_58 * V_49 ,
struct V_1 * V_2 ,
const struct V_785 * V_786 )
{
T_4 V_375 ;
int V_753 , V_89 ;
bool V_774 = V_786 -> V_774 ;
struct V_781 * V_782 ;
V_89 = F_310 ( V_2 , V_360 , & V_375 , V_49 , V_774 ) ;
if ( V_89 < 0 )
return V_769 ;
if ( V_89 )
goto V_784;
if ( V_786 -> V_787 ( V_2 , V_375 , V_156 , V_766 ) )
return V_767 ;
V_784:
V_753 = V_786 -> V_788 ( V_2 , V_375 , V_766 , V_156 ) ;
if ( V_753 == V_766 )
return V_767 ;
V_375 += V_753 ;
V_766 -= V_753 ;
V_156 += V_753 ;
F_106 ( V_2 -> V_789 >= V_790 ) ;
V_782 = & V_2 -> V_778 [ V_2 -> V_789 ++ ] ;
V_782 -> V_375 = V_375 ;
V_782 -> V_31 = V_156 ;
V_782 -> V_75 = V_766 ;
return V_767 ;
}
int F_324 ( struct V_771 * V_772 , unsigned long V_360 ,
void * V_156 , unsigned int V_766 ,
struct V_58 * V_49 ,
const struct V_785 * V_786 )
{
struct V_1 * V_2 = F_306 ( V_772 ) ;
T_4 V_375 ;
int V_791 ;
if ( V_786 -> V_792 &&
V_786 -> V_792 ( V_2 , V_156 , V_766 ) )
return V_767 ;
V_2 -> V_789 = 0 ;
if ( ( ( V_360 + V_766 - 1 ) ^ V_360 ) & V_349 ) {
int V_793 ;
V_793 = - V_360 & ~ V_349 ;
V_791 = F_323 ( V_360 , V_156 , V_793 , V_49 ,
V_2 , V_786 ) ;
if ( V_791 != V_767 )
return V_791 ;
V_360 += V_793 ;
V_156 += V_793 ;
V_766 -= V_793 ;
}
V_791 = F_323 ( V_360 , V_156 , V_766 , V_49 ,
V_2 , V_786 ) ;
if ( V_791 != V_767 )
return V_791 ;
if ( ! V_2 -> V_789 )
return V_791 ;
V_375 = V_2 -> V_778 [ 0 ] . V_375 ;
V_2 -> V_794 = 1 ;
V_2 -> V_795 = 0 ;
V_2 -> V_783 -> V_784 . V_75 = F_289 ( 8u , V_2 -> V_778 [ 0 ] . V_75 ) ;
V_2 -> V_783 -> V_784 . V_796 = V_2 -> V_797 = V_786 -> V_774 ;
V_2 -> V_783 -> V_798 = V_799 ;
V_2 -> V_783 -> V_784 . V_800 = V_375 ;
return V_786 -> V_801 ( V_2 , V_375 , V_156 , V_766 ) ;
}
static int F_325 ( struct V_771 * V_772 ,
unsigned long V_360 ,
void * V_156 ,
unsigned int V_766 ,
struct V_58 * V_49 )
{
return F_324 ( V_772 , V_360 , V_156 , V_766 ,
V_49 , & V_802 ) ;
}
int F_326 ( struct V_771 * V_772 ,
unsigned long V_360 ,
const void * V_156 ,
unsigned int V_766 ,
struct V_58 * V_49 )
{
return F_324 ( V_772 , V_360 , ( void * ) V_156 , V_766 ,
V_49 , & V_803 ) ;
}
static int F_327 ( struct V_771 * V_772 ,
unsigned long V_360 ,
const void * V_804 ,
const void * V_805 ,
unsigned int V_766 ,
struct V_58 * V_49 )
{
struct V_1 * V_2 = F_306 ( V_772 ) ;
T_4 V_375 ;
struct V_351 * V_351 ;
char * V_806 ;
bool V_807 ;
if ( V_766 > 8 || ( V_766 & ( V_766 - 1 ) ) )
goto V_808;
V_375 = F_302 ( V_2 , V_360 , NULL ) ;
if ( V_375 == V_80 ||
( V_375 & V_349 ) == V_776 )
goto V_808;
if ( ( ( V_375 + V_766 - 1 ) & V_349 ) != ( V_375 & V_349 ) )
goto V_808;
V_351 = F_328 ( V_2 -> V_82 , V_375 >> V_87 ) ;
if ( F_329 ( V_351 ) )
goto V_808;
V_806 = F_330 ( V_351 ) ;
V_806 += F_331 ( V_375 ) ;
switch ( V_766 ) {
case 1 :
V_807 = F_332 ( T_12 , V_806 , V_804 , V_805 ) ;
break;
case 2 :
V_807 = F_332 ( V_809 , V_806 , V_804 , V_805 ) ;
break;
case 4 :
V_807 = F_332 ( T_1 , V_806 , V_804 , V_805 ) ;
break;
case 8 :
V_807 = F_333 ( V_806 , V_804 , V_805 ) ;
break;
default:
F_334 () ;
}
F_335 ( V_806 ) ;
F_336 ( V_351 ) ;
if ( ! V_807 )
return V_810 ;
F_316 ( V_2 , V_375 , V_805 , V_766 ) ;
return V_767 ;
V_808:
F_337 ( V_811 L_22 ) ;
return F_326 ( V_772 , V_360 , V_805 , V_766 , V_49 ) ;
}
static int F_338 ( struct V_1 * V_2 , void * V_812 )
{
int V_100 ;
if ( V_2 -> V_5 . V_813 . V_814 )
V_100 = F_294 ( V_2 -> V_82 , V_724 , V_2 -> V_5 . V_813 . V_815 ,
V_2 -> V_5 . V_813 . V_473 , V_812 ) ;
else
V_100 = F_291 ( V_2 -> V_82 , V_724 ,
V_2 -> V_5 . V_813 . V_815 , V_2 -> V_5 . V_813 . V_473 ,
V_812 ) ;
return V_100 ;
}
static int F_339 ( struct V_1 * V_2 , int V_473 ,
unsigned short V_815 , void * V_156 ,
unsigned int V_688 , bool V_814 )
{
F_340 ( ! V_814 , V_815 , V_473 , V_688 ) ;
V_2 -> V_5 . V_813 . V_815 = V_815 ;
V_2 -> V_5 . V_813 . V_814 = V_814 ;
V_2 -> V_5 . V_813 . V_688 = V_688 ;
V_2 -> V_5 . V_813 . V_473 = V_473 ;
if ( ! F_338 ( V_2 , V_2 -> V_5 . V_816 ) ) {
V_2 -> V_5 . V_813 . V_688 = 0 ;
return 1 ;
}
V_2 -> V_783 -> V_798 = V_817 ;
V_2 -> V_783 -> V_818 . V_819 = V_814 ? V_820 : V_821 ;
V_2 -> V_783 -> V_818 . V_473 = V_473 ;
V_2 -> V_783 -> V_818 . V_822 = V_823 * V_88 ;
V_2 -> V_783 -> V_818 . V_688 = V_688 ;
V_2 -> V_783 -> V_818 . V_815 = V_815 ;
return 0 ;
}
static int F_341 ( struct V_771 * V_772 ,
int V_473 , unsigned short V_815 , void * V_156 ,
unsigned int V_688 )
{
struct V_1 * V_2 = F_306 ( V_772 ) ;
int V_89 ;
if ( V_2 -> V_5 . V_813 . V_688 )
goto V_824;
V_89 = F_339 ( V_2 , V_473 , V_815 , V_156 , V_688 , true ) ;
if ( V_89 ) {
V_824:
memcpy ( V_156 , V_2 -> V_5 . V_816 , V_473 * V_688 ) ;
V_2 -> V_5 . V_813 . V_688 = 0 ;
return 1 ;
}
return 0 ;
}
static int F_342 ( struct V_771 * V_772 ,
int V_473 , unsigned short V_815 ,
const void * V_156 , unsigned int V_688 )
{
struct V_1 * V_2 = F_306 ( V_772 ) ;
memcpy ( V_2 -> V_5 . V_816 , V_156 , V_473 * V_688 ) ;
return F_339 ( V_2 , V_473 , V_815 , ( void * ) V_156 , V_688 , false ) ;
}
static unsigned long F_343 ( struct V_1 * V_2 , int V_759 )
{
return V_56 -> F_343 ( V_2 , V_759 ) ;
}
static void F_344 ( struct V_771 * V_772 , V_144 V_63 )
{
F_345 ( F_306 ( V_772 ) , V_63 ) ;
}
int F_346 ( struct V_1 * V_2 )
{
if ( ! F_213 ( V_2 ) )
return V_767 ;
if ( V_56 -> V_556 () ) {
int V_23 = F_347 () ;
F_215 ( V_23 , V_2 -> V_5 . V_557 ) ;
F_348 ( V_2 -> V_5 . V_557 ,
F_211 , NULL , 1 ) ;
F_349 () ;
F_350 ( V_2 -> V_5 . V_557 ) ;
} else
F_212 () ;
return V_767 ;
}
static void F_351 ( struct V_771 * V_772 )
{
F_346 ( F_306 ( V_772 ) ) ;
}
int F_352 ( struct V_771 * V_772 , int V_155 , unsigned long * V_825 )
{
return F_81 ( F_306 ( V_772 ) , V_155 , V_825 ) ;
}
int F_353 ( struct V_771 * V_772 , int V_155 , unsigned long V_22 )
{
return F_79 ( F_306 ( V_772 ) , V_155 , V_22 ) ;
}
static T_2 F_354 ( T_2 V_826 , T_1 V_827 )
{
return ( V_826 & ~ ( ( 1ULL << 32 ) - 1 ) ) | V_827 ;
}
static unsigned long F_355 ( struct V_771 * V_772 , int V_828 )
{
struct V_1 * V_2 = F_306 ( V_772 ) ;
unsigned long V_22 ;
switch ( V_828 ) {
case 0 :
V_22 = F_51 ( V_2 ) ;
break;
case 2 :
V_22 = V_2 -> V_5 . V_62 ;
break;
case 3 :
V_22 = F_49 ( V_2 ) ;
break;
case 4 :
V_22 = F_62 ( V_2 ) ;
break;
case 8 :
V_22 = F_76 ( V_2 ) ;
break;
default:
F_356 ( L_23 , V_224 , V_828 ) ;
return 0 ;
}
return V_22 ;
}
static int F_357 ( struct V_771 * V_772 , int V_828 , V_144 V_156 )
{
struct V_1 * V_2 = F_306 ( V_772 ) ;
int V_165 = 0 ;
switch ( V_828 ) {
case 0 :
V_165 = F_50 ( V_2 , F_354 ( F_51 ( V_2 ) , V_156 ) ) ;
break;
case 2 :
V_2 -> V_5 . V_62 = V_156 ;
break;
case 3 :
V_165 = F_68 ( V_2 , V_156 ) ;
break;
case 4 :
V_165 = F_61 ( V_2 , F_354 ( F_62 ( V_2 ) , V_156 ) ) ;
break;
case 8 :
V_165 = F_73 ( V_2 , V_156 ) ;
break;
default:
F_356 ( L_23 , V_224 , V_828 ) ;
V_165 = - 1 ;
}
return V_165 ;
}
static void F_358 ( struct V_771 * V_772 , V_144 V_156 )
{
F_359 ( F_306 ( V_772 ) , V_156 ) ;
}
static int F_360 ( struct V_771 * V_772 )
{
return V_56 -> V_71 ( F_306 ( V_772 ) ) ;
}
static void F_361 ( struct V_771 * V_772 , struct V_829 * V_830 )
{
V_56 -> V_831 ( F_306 ( V_772 ) , V_830 ) ;
}
static void F_362 ( struct V_771 * V_772 , struct V_829 * V_830 )
{
V_56 -> V_832 ( F_306 ( V_772 ) , V_830 ) ;
}
static void F_363 ( struct V_771 * V_772 , struct V_829 * V_830 )
{
V_56 -> V_833 ( F_306 ( V_772 ) , V_830 ) ;
}
static void F_364 ( struct V_771 * V_772 , struct V_829 * V_830 )
{
V_56 -> V_834 ( F_306 ( V_772 ) , V_830 ) ;
}
static unsigned long F_365 (
struct V_771 * V_772 , int V_759 )
{
return F_343 ( F_306 ( V_772 ) , V_759 ) ;
}
static bool F_366 ( struct V_771 * V_772 , V_809 * V_835 ,
struct V_836 * V_837 , T_1 * V_838 ,
int V_759 )
{
struct V_757 V_758 ;
F_297 ( F_306 ( V_772 ) , & V_758 , V_759 ) ;
* V_835 = V_758 . V_835 ;
if ( V_758 . V_839 ) {
memset ( V_837 , 0 , sizeof( * V_837 ) ) ;
return false ;
}
if ( V_758 . V_840 )
V_758 . V_841 >>= 12 ;
F_367 ( V_837 , V_758 . V_841 ) ;
F_368 ( V_837 , ( unsigned long ) V_758 . V_842 ) ;
#ifdef F_52
if ( V_838 )
* V_838 = V_758 . V_842 >> 32 ;
#endif
V_837 -> type = V_758 . type ;
V_837 -> V_565 = V_758 . V_565 ;
V_837 -> V_843 = V_758 . V_843 ;
V_837 -> V_320 = V_758 . V_844 ;
V_837 -> V_845 = V_758 . V_845 ;
V_837 -> V_846 = V_758 . V_846 ;
V_837 -> V_847 = V_758 . V_157 ;
V_837 -> V_840 = V_758 . V_840 ;
return true ;
}
static void F_369 ( struct V_771 * V_772 , V_809 V_835 ,
struct V_836 * V_837 , T_1 V_838 ,
int V_759 )
{
struct V_1 * V_2 = F_306 ( V_772 ) ;
struct V_757 V_758 ;
V_758 . V_835 = V_835 ;
V_758 . V_842 = F_370 ( V_837 ) ;
#ifdef F_52
V_758 . V_842 |= ( ( T_2 ) V_838 ) << 32 ;
#endif
V_758 . V_841 = F_371 ( V_837 ) ;
if ( V_837 -> V_840 )
V_758 . V_841 = ( V_758 . V_841 << 12 ) | 0xfff ;
V_758 . type = V_837 -> type ;
V_758 . V_844 = V_837 -> V_320 ;
V_758 . V_843 = V_837 -> V_843 ;
V_758 . V_157 = V_837 -> V_847 ;
V_758 . V_565 = V_837 -> V_565 ;
V_758 . V_846 = V_837 -> V_846 ;
V_758 . V_840 = V_837 -> V_840 ;
V_758 . V_845 = V_837 -> V_845 ;
V_758 . V_844 = V_837 -> V_320 ;
V_758 . V_839 = ! V_758 . V_844 ;
V_758 . V_848 = 0 ;
F_296 ( V_2 , & V_758 , V_759 ) ;
return;
}
static int F_372 ( struct V_771 * V_772 ,
T_1 V_446 , T_2 * V_447 )
{
return F_188 ( F_306 ( V_772 ) , V_446 , V_447 ) ;
}
static int F_373 ( struct V_771 * V_772 ,
T_1 V_446 , T_2 V_31 )
{
struct V_182 V_21 ;
V_21 . V_31 = V_31 ;
V_21 . V_119 = V_446 ;
V_21 . V_184 = false ;
return F_91 ( F_306 ( V_772 ) , & V_21 ) ;
}
static int F_374 ( struct V_771 * V_772 ,
T_1 V_849 , T_2 * V_447 )
{
return F_85 ( F_306 ( V_772 ) , V_849 , V_447 ) ;
}
static void F_375 ( struct V_771 * V_772 )
{
F_306 ( V_772 ) -> V_5 . V_850 = 1 ;
}
static void F_376 ( struct V_771 * V_772 )
{
F_180 () ;
F_377 ( F_306 ( V_772 ) ) ;
F_378 () ;
}
static void F_379 ( struct V_771 * V_772 )
{
F_181 () ;
}
static int F_380 ( struct V_771 * V_772 ,
struct V_851 * V_852 ,
enum V_853 V_854 )
{
return V_56 -> V_855 ( F_306 ( V_772 ) , V_852 , V_854 ) ;
}
static void F_381 ( struct V_771 * V_772 ,
T_1 * V_856 , T_1 * V_857 , T_1 * V_167 , T_1 * V_176 )
{
V_637 ( F_306 ( V_772 ) , V_856 , V_857 , V_167 , V_176 ) ;
}
static V_144 F_382 ( struct V_771 * V_772 , unsigned V_858 )
{
return F_84 ( F_306 ( V_772 ) , V_858 ) ;
}
static void F_383 ( struct V_771 * V_772 , unsigned V_858 , V_144 V_156 )
{
F_86 ( F_306 ( V_772 ) , V_858 , V_156 ) ;
}
static void F_384 ( struct V_1 * V_2 , T_1 V_27 )
{
T_1 V_859 = V_56 -> V_593 ( V_2 , V_27 ) ;
if ( ! ( V_859 & V_27 ) )
V_56 -> V_606 ( V_2 , V_27 ) ;
}
static void F_385 ( struct V_1 * V_2 )
{
struct V_771 * V_772 = & V_2 -> V_5 . V_860 ;
if ( V_772 -> V_49 . V_32 == V_33 )
F_30 ( V_2 , & V_772 -> V_49 ) ;
else if ( V_772 -> V_49 . V_861 )
F_29 ( V_2 , V_772 -> V_49 . V_32 ,
V_772 -> V_49 . V_43 ) ;
else
F_24 ( V_2 , V_772 -> V_49 . V_32 ) ;
}
static void F_386 ( struct V_771 * V_772 )
{
memset ( & V_772 -> V_862 , 0 ,
( void * ) & V_772 -> V_863 - ( void * ) & V_772 -> V_862 ) ;
V_772 -> V_864 . V_690 = 0 ;
V_772 -> V_864 . V_865 = 0 ;
V_772 -> V_866 . V_867 = 0 ;
V_772 -> V_866 . V_865 = 0 ;
V_772 -> V_868 . V_867 = 0 ;
V_772 -> V_868 . V_865 = 0 ;
}
static void F_387 ( struct V_1 * V_2 )
{
struct V_771 * V_772 = & V_2 -> V_5 . V_860 ;
int V_113 , V_114 ;
V_56 -> V_115 ( V_2 , & V_113 , & V_114 ) ;
V_772 -> V_869 = F_388 ( V_2 ) ;
V_772 -> V_870 = F_389 ( V_2 ) ;
V_772 -> V_280 = ( ! F_390 ( V_2 ) ) ? V_871 :
( V_772 -> V_869 & V_872 ) ? V_873 :
V_114 ? V_874 :
V_113 ? V_875 :
V_876 ;
V_772 -> V_877 = F_391 ( V_2 ) ;
F_386 ( V_772 ) ;
V_2 -> V_5 . V_878 = false ;
}
int F_392 ( struct V_1 * V_2 , int V_569 , int V_879 )
{
struct V_771 * V_772 = & V_2 -> V_5 . V_860 ;
int V_89 ;
F_387 ( V_2 ) ;
V_772 -> V_880 = 2 ;
V_772 -> V_881 = 2 ;
V_772 -> V_882 = V_772 -> V_870 + V_879 ;
V_89 = F_393 ( V_772 , V_569 ) ;
if ( V_89 != V_767 )
return V_883 ;
V_772 -> V_870 = V_772 -> V_882 ;
F_394 ( V_2 , V_772 -> V_870 ) ;
F_359 ( V_2 , V_772 -> V_869 ) ;
if ( V_569 == V_884 )
V_2 -> V_5 . V_598 = 0 ;
else
V_2 -> V_5 . V_590 . V_50 = false ;
return V_885 ;
}
static int F_395 ( struct V_1 * V_2 )
{
int V_100 = V_885 ;
++ V_2 -> V_60 . V_886 ;
F_396 ( V_2 ) ;
if ( ! F_391 ( V_2 ) ) {
V_2 -> V_783 -> V_798 = V_887 ;
V_2 -> V_783 -> V_888 . V_889 = V_890 ;
V_2 -> V_783 -> V_888 . V_891 = 0 ;
V_100 = V_883 ;
}
F_24 ( V_2 , V_166 ) ;
return V_100 ;
}
static bool F_397 ( struct V_1 * V_2 , T_13 V_62 ,
bool V_892 )
{
T_4 V_375 = V_62 ;
T_14 V_893 ;
if ( ! V_2 -> V_5 . V_67 . V_894 ) {
V_375 = F_302 ( V_2 , V_62 , NULL ) ;
if ( V_375 == V_80 )
return true ;
}
V_893 = F_398 ( V_2 -> V_82 , F_38 ( V_375 ) ) ;
if ( F_399 ( V_893 ) )
return false ;
F_400 ( V_893 ) ;
if ( V_2 -> V_5 . V_67 . V_894 ) {
unsigned int V_895 ;
F_126 ( & V_2 -> V_82 -> V_705 ) ;
V_895 = V_2 -> V_82 -> V_5 . V_895 ;
F_127 ( & V_2 -> V_82 -> V_705 ) ;
if ( V_895 )
F_401 ( V_2 -> V_82 , F_38 ( V_375 ) ) ;
return true ;
}
F_401 ( V_2 -> V_82 , F_38 ( V_375 ) ) ;
return ! V_892 ;
}
static bool F_402 ( struct V_771 * V_772 ,
unsigned long V_62 , int V_896 )
{
struct V_1 * V_2 = F_306 ( V_772 ) ;
unsigned long V_897 , V_898 , V_375 = V_62 ;
V_897 = V_2 -> V_5 . V_897 ;
V_898 = V_2 -> V_5 . V_898 ;
V_2 -> V_5 . V_897 = V_2 -> V_5 . V_898 = 0 ;
if ( ! ( V_896 & V_899 ) )
return false ;
if ( F_403 ( V_772 ) )
return false ;
if ( V_772 -> V_870 == V_897 && V_898 == V_62 )
return false ;
V_2 -> V_5 . V_897 = V_772 -> V_870 ;
V_2 -> V_5 . V_898 = V_62 ;
if ( ! V_2 -> V_5 . V_67 . V_894 )
V_375 = F_302 ( V_2 , V_62 , NULL ) ;
F_401 ( V_2 -> V_82 , F_38 ( V_375 ) ) ;
return true ;
}
int F_404 ( struct V_1 * V_2 ,
unsigned long V_62 ,
int V_896 ,
void * V_900 ,
int V_901 )
{
int V_100 ;
struct V_771 * V_772 = & V_2 -> V_5 . V_860 ;
bool V_471 = true ;
bool V_902 = V_2 -> V_5 . V_892 ;
V_2 -> V_5 . V_892 = false ;
F_405 ( V_2 ) ;
if ( ! ( V_896 & V_903 ) ) {
F_387 ( V_2 ) ;
V_772 -> V_904 = 0 ;
V_772 -> V_905 = false ;
V_772 -> V_906 = false ;
V_772 -> V_907
= V_896 & V_908 ;
V_100 = F_406 ( V_772 , V_900 , V_901 ) ;
F_407 ( V_2 ) ;
++ V_2 -> V_60 . V_909 ;
if ( V_100 != V_910 ) {
if ( V_896 & V_908 )
return V_883 ;
if ( F_397 ( V_2 , V_62 ,
V_902 ) )
return V_885 ;
if ( V_896 & V_911 )
return V_883 ;
return F_395 ( V_2 ) ;
}
}
if ( V_896 & V_911 ) {
F_394 ( V_2 , V_772 -> V_882 ) ;
return V_885 ;
}
if ( F_402 ( V_772 , V_62 , V_896 ) )
return V_885 ;
if ( V_2 -> V_5 . V_878 ) {
V_2 -> V_5 . V_878 = false ;
F_408 ( V_772 ) ;
}
V_912:
V_100 = F_409 ( V_772 ) ;
if ( V_100 == V_913 )
return V_885 ;
if ( V_100 == V_914 ) {
if ( F_397 ( V_2 , V_62 , V_902 ) )
return V_885 ;
return F_395 ( V_2 ) ;
}
if ( V_772 -> V_905 ) {
F_385 ( V_2 ) ;
V_100 = V_885 ;
} else if ( V_2 -> V_5 . V_813 . V_688 ) {
if ( ! V_2 -> V_5 . V_813 . V_814 )
V_2 -> V_5 . V_813 . V_688 = 0 ;
else {
V_471 = false ;
V_2 -> V_5 . V_915 = V_916 ;
}
V_100 = V_917 ;
} else if ( V_2 -> V_794 ) {
if ( ! V_2 -> V_797 )
V_471 = false ;
V_100 = V_917 ;
V_2 -> V_5 . V_915 = V_918 ;
} else if ( V_100 == V_919 )
goto V_912;
else
V_100 = V_885 ;
if ( V_471 ) {
F_384 ( V_2 , V_772 -> V_904 ) ;
F_359 ( V_2 , V_772 -> V_869 ) ;
F_23 ( V_48 , V_2 ) ;
V_2 -> V_5 . V_920 = false ;
F_394 ( V_2 , V_772 -> V_870 ) ;
} else
V_2 -> V_5 . V_920 = true ;
return V_100 ;
}
int F_410 ( struct V_1 * V_2 , int V_473 , unsigned short V_815 )
{
unsigned long V_156 = F_84 ( V_2 , V_169 ) ;
int V_89 = F_342 ( & V_2 -> V_5 . V_860 ,
V_473 , V_815 , & V_156 , 1 ) ;
V_2 -> V_5 . V_813 . V_688 = 0 ;
return V_89 ;
}
static void F_411 ( void * V_852 )
{
F_412 ( V_291 , 0 ) ;
}
static void F_413 ( void * V_31 )
{
struct V_921 * V_922 = V_31 ;
unsigned long V_227 = 0 ;
if ( V_31 )
V_227 = V_922 -> V_805 ;
else if ( ! F_208 ( V_923 ) )
V_227 = F_414 ( F_415 () ) ;
if ( ! V_227 )
V_227 = V_235 ;
F_412 ( V_291 , V_227 ) ;
}
static int F_416 ( struct V_924 * V_925 , unsigned long V_156 ,
void * V_31 )
{
struct V_921 * V_922 = V_31 ;
struct V_82 * V_82 ;
struct V_1 * V_2 ;
int V_3 , V_926 = 0 ;
if ( V_156 == V_927 && V_922 -> V_804 > V_922 -> V_805 )
return 0 ;
if ( V_156 == V_928 && V_922 -> V_804 < V_922 -> V_805 )
return 0 ;
F_216 ( V_922 -> V_23 , F_413 , V_922 , 1 ) ;
F_417 ( & V_929 ) ;
F_418 (kvm, &vm_list, vm_list) {
F_193 (i, vcpu, kvm) {
if ( V_2 -> V_23 != V_922 -> V_23 )
continue;
F_23 ( V_292 , V_2 ) ;
if ( V_2 -> V_23 != F_8 () )
V_926 = 1 ;
}
}
F_419 ( & V_929 ) ;
if ( V_922 -> V_804 < V_922 -> V_805 && V_926 ) {
F_216 ( V_922 -> V_23 , F_413 , V_922 , 1 ) ;
}
return 0 ;
}
static int F_420 ( struct V_924 * V_930 ,
unsigned long V_931 , void * V_932 )
{
unsigned int V_23 = ( unsigned long ) V_932 ;
switch ( V_931 ) {
case V_933 :
case V_934 :
F_216 ( V_23 , F_413 , NULL , 1 ) ;
break;
case V_935 :
F_216 ( V_23 , F_411 , NULL , 1 ) ;
break;
}
return V_936 ;
}
static void F_421 ( void )
{
int V_23 ;
V_937 = V_235 ;
F_422 ( & V_938 ) ;
if ( ! F_208 ( V_923 ) ) {
#ifdef F_423
struct V_939 V_940 ;
memset ( & V_940 , 0 , sizeof( V_940 ) ) ;
V_23 = F_347 () ;
F_424 ( & V_940 , V_23 ) ;
if ( V_940 . V_941 . V_942 )
V_937 = V_940 . V_941 . V_942 ;
F_349 () ;
#endif
F_425 ( & V_943 ,
V_944 ) ;
}
F_104 ( L_24 , V_937 ) ;
F_426 (cpu)
F_216 ( V_23 , F_413 , NULL , 1 ) ;
}
int F_427 ( void )
{
return F_428 ( V_945 ) != NULL ;
}
static int F_429 ( void )
{
int V_946 = 3 ;
if ( F_428 ( V_945 ) )
V_946 = V_56 -> V_71 ( F_428 ( V_945 ) ) ;
return V_946 != 0 ;
}
static unsigned long F_430 ( void )
{
unsigned long V_947 = 0 ;
if ( F_428 ( V_945 ) )
V_947 = F_389 ( F_428 ( V_945 ) ) ;
return V_947 ;
}
void F_431 ( struct V_1 * V_2 )
{
F_412 ( V_945 , V_2 ) ;
}
void F_432 ( struct V_1 * V_2 )
{
F_412 ( V_945 , NULL ) ;
}
static void F_433 ( void )
{
T_2 V_27 ;
int V_948 = V_949 . V_950 ;
V_27 = ( ( 1ull << ( 62 - V_948 + 1 ) ) - 1 ) << V_948 ;
V_27 |= 1ull ;
#ifdef F_52
if ( V_948 == 52 )
V_27 &= ~ 1ull ;
#endif
F_434 ( V_27 ) ;
}
static void F_435 ( struct V_951 * V_952 )
{
struct V_82 * V_82 ;
struct V_1 * V_2 ;
int V_3 ;
F_417 ( & V_929 ) ;
F_418 (kvm, &vm_list, vm_list)
F_193 (i, vcpu, kvm)
F_218 ( V_251 , & V_2 -> V_560 ) ;
F_139 ( & V_284 , 0 ) ;
F_419 ( & V_929 ) ;
}
static int F_436 ( struct V_924 * V_925 , unsigned long V_953 ,
void * V_954 )
{
struct V_187 * V_246 = & V_187 ;
struct V_185 * V_186 = V_954 ;
F_93 ( V_186 ) ;
if ( V_246 -> clock . V_190 != V_249 &&
F_118 ( & V_284 ) != 0 )
F_437 ( V_955 , & V_956 ) ;
return 0 ;
}
int F_438 ( void * V_957 )
{
int V_100 ;
struct V_56 * V_786 = (struct V_56 * ) V_957 ;
if ( V_56 ) {
F_10 ( V_26 L_25 ) ;
V_100 = - V_722 ;
goto V_94;
}
if ( ! V_786 -> V_958 () ) {
F_10 ( V_26 L_26 ) ;
V_100 = - V_959 ;
goto V_94;
}
if ( V_786 -> V_960 () ) {
F_10 ( V_26 L_27 ) ;
V_100 = - V_959 ;
goto V_94;
}
V_100 = - V_353 ;
V_25 = F_439 ( struct V_11 ) ;
if ( ! V_25 ) {
F_10 ( V_26 L_28 ) ;
goto V_94;
}
V_100 = F_440 () ;
if ( V_100 )
goto V_961;
F_433 () ;
F_286 () ;
V_56 = V_786 ;
F_441 ( V_962 , V_963 ,
V_964 , V_965 , 0 ) ;
F_421 () ;
F_442 ( & V_966 ) ;
if ( V_526 )
V_126 = F_443 ( V_122 ) ;
F_444 () ;
#ifdef F_52
F_445 ( & V_967 ) ;
#endif
return 0 ;
V_961:
F_446 ( V_25 ) ;
V_94:
return V_100 ;
}
void F_447 ( void )
{
F_448 ( & V_966 ) ;
if ( ! F_208 ( V_923 ) )
F_449 ( & V_943 ,
V_944 ) ;
F_450 ( & V_938 ) ;
#ifdef F_52
F_451 ( & V_967 ) ;
#endif
V_56 = NULL ;
F_452 () ;
F_446 ( V_25 ) ;
}
int F_453 ( struct V_1 * V_2 )
{
++ V_2 -> V_60 . V_968 ;
if ( F_74 ( V_2 -> V_82 ) ) {
V_2 -> V_5 . V_969 = V_970 ;
return 1 ;
} else {
V_2 -> V_783 -> V_798 = V_971 ;
return 0 ;
}
}
int F_454 ( struct V_1 * V_2 )
{
T_2 V_972 , V_973 , V_974 , V_89 ;
T_15 V_975 , V_976 , V_977 , V_165 = V_978 , V_979 = 0 ;
bool V_980 , V_981 ;
int V_113 , V_114 ;
if ( V_56 -> V_71 ( V_2 ) != 0 || ! F_390 ( V_2 ) ) {
F_24 ( V_2 , V_166 ) ;
return 0 ;
}
V_56 -> V_115 ( V_2 , & V_113 , & V_114 ) ;
V_981 = F_46 ( V_2 ) && V_114 == 1 ;
if ( ! V_981 ) {
V_972 = ( ( T_2 ) F_84 ( V_2 , V_170 ) << 32 ) |
( F_84 ( V_2 , V_169 ) & 0xffffffff ) ;
V_973 = ( ( T_2 ) F_84 ( V_2 , V_982 ) << 32 ) |
( F_84 ( V_2 , V_168 ) & 0xffffffff ) ;
V_974 = ( ( T_2 ) F_84 ( V_2 , V_983 ) << 32 ) |
( F_84 ( V_2 , V_984 ) & 0xffffffff ) ;
}
#ifdef F_52
else {
V_972 = F_84 ( V_2 , V_168 ) ;
V_973 = F_84 ( V_2 , V_170 ) ;
V_974 = F_84 ( V_2 , V_985 ) ;
}
#endif
V_975 = V_972 & 0xffff ;
V_980 = ( V_972 >> 16 ) & 0x1 ;
V_977 = ( V_972 >> 32 ) & 0xfff ;
V_976 = ( V_972 >> 48 ) & 0xfff ;
F_455 ( V_975 , V_980 , V_977 , V_976 , V_973 , V_974 ) ;
switch ( V_975 ) {
case V_986 :
F_456 ( V_2 ) ;
break;
default:
V_165 = V_987 ;
break;
}
V_89 = V_165 | ( ( ( T_2 ) V_979 & 0xfff ) << 32 ) ;
if ( V_981 ) {
F_86 ( V_2 , V_169 , V_89 ) ;
} else {
F_86 ( V_2 , V_170 , V_89 >> 32 ) ;
F_86 ( V_2 , V_169 , V_89 & 0xffffffff ) ;
}
return 1 ;
}
int F_457 ( struct V_1 * V_2 )
{
unsigned long V_16 , V_988 , V_989 , V_990 , V_991 , V_89 ;
int V_100 = 1 ;
if ( F_160 ( V_2 -> V_82 ) )
return F_454 ( V_2 ) ;
V_16 = F_84 ( V_2 , V_169 ) ;
V_988 = F_84 ( V_2 , V_982 ) ;
V_989 = F_84 ( V_2 , V_168 ) ;
V_990 = F_84 ( V_2 , V_170 ) ;
V_991 = F_84 ( V_2 , V_984 ) ;
F_458 ( V_16 , V_988 , V_989 , V_990 , V_991 ) ;
if ( ! F_46 ( V_2 ) ) {
V_16 &= 0xFFFFFFFF ;
V_988 &= 0xFFFFFFFF ;
V_989 &= 0xFFFFFFFF ;
V_990 &= 0xFFFFFFFF ;
V_991 &= 0xFFFFFFFF ;
}
if ( V_56 -> V_71 ( V_2 ) != 0 ) {
V_89 = - V_992 ;
goto V_94;
}
switch ( V_16 ) {
case V_993 :
V_89 = 0 ;
break;
default:
V_89 = - V_994 ;
break;
}
V_94:
F_86 ( V_2 , V_169 , V_89 ) ;
++ V_2 -> V_60 . V_995 ;
return V_100 ;
}
static int F_459 ( struct V_771 * V_772 )
{
struct V_1 * V_2 = F_306 ( V_772 ) ;
char V_996 [ 3 ] ;
unsigned long V_997 = F_389 ( V_2 ) ;
F_460 ( V_2 -> V_82 ) ;
V_56 -> V_363 ( V_2 , V_996 ) ;
return F_326 ( V_772 , V_997 , V_996 , 3 , NULL ) ;
}
static int F_461 ( struct V_1 * V_2 )
{
return ( ! F_74 ( V_2 -> V_82 ) && ! F_462 ( V_2 ) &&
V_2 -> V_783 -> V_998 &&
F_463 ( V_2 ) ) ;
}
static void F_464 ( struct V_1 * V_2 )
{
struct V_999 * V_999 = V_2 -> V_783 ;
V_999 -> V_1000 = ( F_388 ( V_2 ) & V_1001 ) != 0 ;
V_999 -> V_146 = F_76 ( V_2 ) ;
V_999 -> V_30 = F_18 ( V_2 ) ;
if ( F_74 ( V_2 -> V_82 ) )
V_999 -> V_1002 = 1 ;
else
V_999 -> V_1002 =
F_463 ( V_2 ) &&
! F_462 ( V_2 ) &&
! F_465 ( V_2 ) ;
}
static int F_466 ( struct V_1 * V_2 )
{
struct V_1003 * V_567 = V_2 -> V_5 . V_567 ;
struct V_351 * V_351 ;
if ( ! V_567 || ! V_567 -> V_646 )
return 0 ;
V_351 = F_328 ( V_2 -> V_82 , V_567 -> V_646 >> V_87 ) ;
if ( F_329 ( V_351 ) )
return - V_81 ;
V_2 -> V_5 . V_567 -> V_1004 = V_351 ;
return 0 ;
}
static void F_467 ( struct V_1 * V_2 )
{
struct V_1003 * V_567 = V_2 -> V_5 . V_567 ;
int V_326 ;
if ( ! V_567 || ! V_567 -> V_646 )
return;
V_326 = F_201 ( & V_2 -> V_82 -> V_468 ) ;
F_336 ( V_567 -> V_1004 ) ;
F_468 ( V_2 -> V_82 , V_567 -> V_646 >> V_87 ) ;
F_202 ( & V_2 -> V_82 -> V_468 , V_326 ) ;
}
static void F_226 ( struct V_1 * V_2 )
{
int V_1005 , V_1006 ;
if ( ! V_56 -> F_226 )
return;
if ( ! V_2 -> V_5 . V_567 )
return;
if ( ! V_2 -> V_5 . V_567 -> V_646 )
V_1005 = F_469 ( V_2 ) ;
else
V_1005 = - 1 ;
if ( V_1005 != - 1 )
V_1005 >>= 4 ;
V_1006 = F_77 ( V_2 ) ;
V_56 -> F_226 ( V_2 , V_1006 , V_1005 ) ;
}
static void F_470 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_49 . V_50 ) {
F_471 ( V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ) ;
V_56 -> V_1007 ( V_2 , V_2 -> V_5 . V_49 . V_16 ,
V_2 -> V_5 . V_49 . V_52 ,
V_2 -> V_5 . V_49 . V_43 ,
V_2 -> V_5 . V_49 . V_44 ) ;
return;
}
if ( V_2 -> V_5 . V_597 ) {
V_56 -> V_1008 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_590 . V_50 ) {
V_56 -> V_1009 ( V_2 ) ;
return;
}
if ( V_2 -> V_5 . V_598 ) {
if ( V_56 -> V_1010 ( V_2 ) ) {
-- V_2 -> V_5 . V_598 ;
V_2 -> V_5 . V_597 = true ;
V_56 -> V_1008 ( V_2 ) ;
}
} else if ( F_472 ( V_2 ) ) {
if ( V_56 -> V_1011 ( V_2 ) ) {
F_228 ( V_2 , F_473 ( V_2 ) ,
false ) ;
V_56 -> V_1009 ( V_2 ) ;
}
}
}
static void F_474 ( struct V_1 * V_2 )
{
if ( F_54 ( V_2 , V_136 ) &&
! V_2 -> V_127 ) {
F_475 ( V_122 , V_2 -> V_5 . V_121 ) ;
V_2 -> V_127 = 1 ;
}
}
static void F_476 ( struct V_1 * V_2 )
{
if ( V_2 -> V_127 ) {
if ( V_2 -> V_5 . V_121 != V_126 )
F_475 ( V_122 , V_126 ) ;
V_2 -> V_127 = 0 ;
}
}
static void F_234 ( struct V_1 * V_2 )
{
unsigned V_841 = 2 ;
if ( V_56 -> V_600 ( V_2 ) || V_2 -> V_5 . V_597 )
V_841 = 1 ;
V_2 -> V_5 . V_598 += F_477 ( & V_2 -> V_5 . V_68 , 0 ) ;
V_2 -> V_5 . V_598 = F_289 ( V_2 -> V_5 . V_598 , V_841 ) ;
F_23 ( V_48 , V_2 ) ;
}
static void F_478 ( struct V_82 * V_82 )
{
#ifdef F_52
int V_3 ;
struct V_1 * V_2 ;
struct V_244 * V_245 = & V_82 -> V_5 ;
F_126 ( & V_245 -> V_277 ) ;
F_479 ( V_82 ) ;
F_138 ( V_82 ) ;
F_193 (i, vcpu, kvm)
F_218 ( V_292 , & V_2 -> V_560 ) ;
F_193 (i, vcpu, kvm)
F_480 ( V_1012 , & V_2 -> V_560 ) ;
F_127 ( & V_245 -> V_277 ) ;
#endif
}
static void F_481 ( struct V_1 * V_2 )
{
T_2 V_1013 [ 4 ] ;
memset ( V_1013 , 0 , 32 ) ;
F_482 ( V_2 , V_1013 ) ;
V_56 -> V_1014 ( V_2 , V_1013 ) ;
}
static int F_483 ( struct V_1 * V_2 )
{
int V_100 ;
bool V_1015 = ! F_74 ( V_2 -> V_82 ) &&
V_2 -> V_783 -> V_998 ;
bool V_1016 = 0 ;
if ( V_2 -> V_560 ) {
if ( F_484 ( V_1017 , V_2 ) )
F_485 ( V_2 ) ;
if ( F_484 ( V_1018 , V_2 ) )
F_486 ( V_2 ) ;
if ( F_484 ( V_251 , V_2 ) )
F_478 ( V_2 -> V_82 ) ;
if ( F_484 ( V_292 , V_2 ) ) {
V_100 = F_141 ( V_2 ) ;
if ( F_71 ( V_100 ) )
goto V_94;
}
if ( F_484 ( V_1019 , V_2 ) )
F_69 ( V_2 ) ;
if ( F_484 ( V_1020 , V_2 ) )
V_56 -> V_1021 ( V_2 ) ;
if ( F_484 ( V_1022 , V_2 ) ) {
V_2 -> V_783 -> V_798 = V_1023 ;
V_100 = 0 ;
goto V_94;
}
if ( F_484 ( V_54 , V_2 ) ) {
V_2 -> V_783 -> V_798 = V_1024 ;
V_100 = 0 ;
goto V_94;
}
if ( F_484 ( V_1025 , V_2 ) ) {
V_2 -> V_1026 = 0 ;
V_56 -> V_1027 ( V_2 ) ;
}
if ( F_484 ( V_1028 , V_2 ) ) {
V_2 -> V_5 . V_6 . V_1029 = true ;
V_100 = 1 ;
goto V_94;
}
if ( F_484 ( V_421 , V_2 ) )
F_175 ( V_2 ) ;
if ( F_484 ( V_69 , V_2 ) )
F_234 ( V_2 ) ;
V_1016 =
F_484 ( V_1030 , V_2 ) ;
if ( F_484 ( V_1031 , V_2 ) )
F_487 ( V_2 ) ;
if ( F_484 ( V_1032 , V_2 ) )
F_488 ( V_2 ) ;
if ( F_484 ( V_1033 , V_2 ) )
F_481 ( V_2 ) ;
}
if ( F_484 ( V_48 , V_2 ) || V_1015 ) {
F_470 ( V_2 ) ;
if ( V_2 -> V_5 . V_598 )
V_56 -> V_1034 ( V_2 ) ;
else if ( F_472 ( V_2 ) || V_1015 )
V_56 -> V_1035 ( V_2 ) ;
if ( F_489 ( V_2 ) ) {
if ( V_56 -> V_1036 )
V_56 -> V_1036 ( V_2 ,
F_469 ( V_2 ) ) ;
F_226 ( V_2 ) ;
F_490 ( V_2 ) ;
}
}
V_100 = F_491 ( V_2 ) ;
if ( F_71 ( V_100 ) ) {
goto V_1037;
}
F_180 () ;
V_56 -> V_1038 ( V_2 ) ;
if ( V_2 -> V_1026 )
F_377 ( V_2 ) ;
F_474 ( V_2 ) ;
V_2 -> V_280 = V_1039 ;
F_492 () ;
F_284 () ;
if ( V_2 -> V_280 == V_1040 || V_2 -> V_560
|| F_493 () || F_494 ( V_382 ) ) {
V_2 -> V_280 = V_1041 ;
F_13 () ;
F_285 () ;
F_181 () ;
V_100 = 1 ;
goto V_1037;
}
F_202 ( & V_2 -> V_82 -> V_468 , V_2 -> V_1042 ) ;
if ( V_1016 )
F_495 ( V_2 -> V_23 ) ;
F_496 () ;
if ( F_71 ( V_2 -> V_5 . V_153 ) ) {
F_497 ( 0 , 7 ) ;
F_497 ( V_2 -> V_5 . V_158 [ 0 ] , 0 ) ;
F_497 ( V_2 -> V_5 . V_158 [ 1 ] , 1 ) ;
F_497 ( V_2 -> V_5 . V_158 [ 2 ] , 2 ) ;
F_497 ( V_2 -> V_5 . V_158 [ 3 ] , 3 ) ;
}
F_498 ( V_2 -> V_252 ) ;
V_56 -> V_783 ( V_2 ) ;
if ( F_499 () )
F_500 () ;
V_2 -> V_5 . V_274 = V_56 -> V_293 ( V_2 ,
F_145 () ) ;
V_2 -> V_280 = V_1041 ;
F_13 () ;
F_285 () ;
++ V_2 -> V_60 . V_1043 ;
F_501 () ;
F_502 () ;
F_181 () ;
V_2 -> V_1042 = F_201 ( & V_2 -> V_82 -> V_468 ) ;
if ( F_71 ( V_1044 == V_1045 ) ) {
unsigned long V_997 = F_389 ( V_2 ) ;
F_503 ( V_1045 , ( void * ) V_997 ) ;
}
if ( F_71 ( V_2 -> V_5 . V_1046 ) )
F_23 ( V_292 , V_2 ) ;
if ( V_2 -> V_5 . V_1047 )
F_504 ( V_2 ) ;
V_100 = V_56 -> V_1048 ( V_2 ) ;
return V_100 ;
V_1037:
V_56 -> V_1037 ( V_2 ) ;
if ( F_71 ( V_2 -> V_5 . V_1047 ) )
F_504 ( V_2 ) ;
V_94:
return V_100 ;
}
static int F_505 ( struct V_1 * V_2 )
{
int V_100 ;
struct V_82 * V_82 = V_2 -> V_82 ;
if ( F_71 ( V_2 -> V_5 . V_969 == V_1049 ) ) {
F_104 ( L_29 ,
V_2 -> V_252 , V_2 -> V_5 . V_601 ) ;
F_506 ( V_2 ) ;
V_100 = F_507 ( V_2 ) ;
if ( V_100 )
return V_100 ;
V_2 -> V_5 . V_969 = V_1050 ;
}
V_2 -> V_1042 = F_201 ( & V_82 -> V_468 ) ;
V_100 = F_466 ( V_2 ) ;
if ( V_100 ) {
F_202 ( & V_82 -> V_468 , V_2 -> V_1042 ) ;
return V_100 ;
}
V_100 = 1 ;
while ( V_100 > 0 ) {
if ( V_2 -> V_5 . V_969 == V_1050 &&
! V_2 -> V_5 . V_6 . V_1029 )
V_100 = F_483 ( V_2 ) ;
else {
F_202 ( & V_82 -> V_468 , V_2 -> V_1042 ) ;
F_508 ( V_2 ) ;
V_2 -> V_1042 = F_201 ( & V_82 -> V_468 ) ;
if ( F_484 ( V_1051 , V_2 ) )
{
switch( V_2 -> V_5 . V_969 ) {
case V_970 :
V_2 -> V_5 . V_969 =
V_1050 ;
case V_1050 :
V_2 -> V_5 . V_6 . V_1029 = false ;
break;
case V_1049 :
default:
V_100 = - V_1052 ;
break;
}
}
}
if ( V_100 <= 0 )
break;
F_480 ( V_1053 , & V_2 -> V_560 ) ;
if ( F_509 ( V_2 ) )
F_510 ( V_2 ) ;
if ( F_461 ( V_2 ) ) {
V_100 = - V_1052 ;
V_2 -> V_783 -> V_798 = V_1054 ;
++ V_2 -> V_60 . V_1055 ;
}
F_511 ( V_2 ) ;
if ( F_494 ( V_382 ) ) {
V_100 = - V_1052 ;
V_2 -> V_783 -> V_798 = V_1054 ;
++ V_2 -> V_60 . V_1056 ;
}
if ( F_493 () ) {
F_202 ( & V_82 -> V_468 , V_2 -> V_1042 ) ;
F_512 ( V_2 ) ;
V_2 -> V_1042 = F_201 ( & V_82 -> V_468 ) ;
}
}
F_202 ( & V_82 -> V_468 , V_2 -> V_1042 ) ;
F_467 ( V_2 ) ;
return V_100 ;
}
static inline int F_513 ( struct V_1 * V_2 )
{
int V_100 ;
V_2 -> V_1042 = F_201 ( & V_2 -> V_82 -> V_468 ) ;
V_100 = F_514 ( V_2 , V_903 ) ;
F_202 ( & V_2 -> V_82 -> V_468 , V_2 -> V_1042 ) ;
if ( V_100 != V_885 )
return 0 ;
return 1 ;
}
static int V_916 ( struct V_1 * V_2 )
{
F_299 ( ! V_2 -> V_5 . V_813 . V_688 ) ;
return F_513 ( V_2 ) ;
}
static int V_918 ( struct V_1 * V_2 )
{
struct V_999 * V_783 = V_2 -> V_783 ;
struct V_781 * V_782 ;
unsigned V_75 ;
F_299 ( ! V_2 -> V_794 ) ;
V_782 = & V_2 -> V_778 [ V_2 -> V_795 ] ;
V_75 = F_289 ( 8u , V_782 -> V_75 ) ;
if ( ! V_2 -> V_797 )
memcpy ( V_782 -> V_31 , V_783 -> V_784 . V_31 , V_75 ) ;
if ( V_782 -> V_75 <= 8 ) {
V_782 ++ ;
V_2 -> V_795 ++ ;
} else {
V_782 -> V_31 += V_75 ;
V_782 -> V_375 += V_75 ;
V_782 -> V_75 -= V_75 ;
}
if ( V_2 -> V_795 == V_2 -> V_789 ) {
V_2 -> V_794 = 0 ;
if ( V_2 -> V_797 )
return 1 ;
V_2 -> V_777 = 1 ;
return F_513 ( V_2 ) ;
}
V_783 -> V_798 = V_799 ;
V_783 -> V_784 . V_800 = V_782 -> V_375 ;
if ( V_2 -> V_797 )
memcpy ( V_783 -> V_784 . V_31 , V_782 -> V_31 , F_289 ( 8u , V_782 -> V_75 ) ) ;
V_783 -> V_784 . V_75 = F_289 ( 8u , V_782 -> V_75 ) ;
V_783 -> V_784 . V_796 = V_2 -> V_797 ;
V_2 -> V_5 . V_915 = V_918 ;
return 0 ;
}
int F_515 ( struct V_1 * V_2 , struct V_999 * V_999 )
{
int V_100 ;
T_16 V_1057 ;
if ( ! F_516 ( V_382 ) && F_517 ( V_382 ) )
return - V_353 ;
if ( V_2 -> V_1058 )
F_518 ( V_1059 , & V_2 -> V_1060 , & V_1057 ) ;
if ( F_71 ( V_2 -> V_5 . V_969 == V_1061 ) ) {
F_508 ( V_2 ) ;
F_480 ( V_1051 , & V_2 -> V_560 ) ;
V_100 = - V_1062 ;
goto V_94;
}
if ( ! F_74 ( V_2 -> V_82 ) ) {
if ( F_73 ( V_2 , V_999 -> V_146 ) != 0 ) {
V_100 = - V_551 ;
goto V_94;
}
}
if ( F_71 ( V_2 -> V_5 . V_915 ) ) {
int (* F_519)( struct V_1 * ) = V_2 -> V_5 . V_915 ;
V_2 -> V_5 . V_915 = NULL ;
V_100 = F_519 ( V_2 ) ;
if ( V_100 <= 0 )
goto V_94;
} else
F_106 ( V_2 -> V_5 . V_813 . V_688 || V_2 -> V_794 ) ;
V_100 = F_505 ( V_2 ) ;
V_94:
F_464 ( V_2 ) ;
if ( V_2 -> V_1058 )
F_518 ( V_1059 , & V_1057 , NULL ) ;
return V_100 ;
}
int F_520 ( struct V_1 * V_2 , struct V_1063 * V_566 )
{
if ( V_2 -> V_5 . V_920 ) {
F_521 ( & V_2 -> V_5 . V_860 ) ;
V_2 -> V_5 . V_920 = false ;
}
V_566 -> V_1064 = F_84 ( V_2 , V_169 ) ;
V_566 -> V_1065 = F_84 ( V_2 , V_982 ) ;
V_566 -> V_1066 = F_84 ( V_2 , V_168 ) ;
V_566 -> V_1067 = F_84 ( V_2 , V_170 ) ;
V_566 -> V_1068 = F_84 ( V_2 , V_984 ) ;
V_566 -> V_1069 = F_84 ( V_2 , V_983 ) ;
V_566 -> V_1070 = F_84 ( V_2 , V_1071 ) ;
V_566 -> V_1072 = F_84 ( V_2 , V_1073 ) ;
#ifdef F_52
V_566 -> V_1074 = F_84 ( V_2 , V_985 ) ;
V_566 -> V_1075 = F_84 ( V_2 , V_1076 ) ;
V_566 -> V_1077 = F_84 ( V_2 , V_1078 ) ;
V_566 -> V_1079 = F_84 ( V_2 , V_1080 ) ;
V_566 -> V_1081 = F_84 ( V_2 , V_1082 ) ;
V_566 -> V_1083 = F_84 ( V_2 , V_1084 ) ;
V_566 -> V_1085 = F_84 ( V_2 , V_1086 ) ;
V_566 -> V_1087 = F_84 ( V_2 , V_1088 ) ;
#endif
V_566 -> V_997 = F_389 ( V_2 ) ;
V_566 -> V_1089 = F_388 ( V_2 ) ;
return 0 ;
}
int F_522 ( struct V_1 * V_2 , struct V_1063 * V_566 )
{
V_2 -> V_5 . V_878 = true ;
V_2 -> V_5 . V_920 = false ;
F_86 ( V_2 , V_169 , V_566 -> V_1064 ) ;
F_86 ( V_2 , V_982 , V_566 -> V_1065 ) ;
F_86 ( V_2 , V_168 , V_566 -> V_1066 ) ;
F_86 ( V_2 , V_170 , V_566 -> V_1067 ) ;
F_86 ( V_2 , V_984 , V_566 -> V_1068 ) ;
F_86 ( V_2 , V_983 , V_566 -> V_1069 ) ;
F_86 ( V_2 , V_1071 , V_566 -> V_1070 ) ;
F_86 ( V_2 , V_1073 , V_566 -> V_1072 ) ;
#ifdef F_52
F_86 ( V_2 , V_985 , V_566 -> V_1074 ) ;
F_86 ( V_2 , V_1076 , V_566 -> V_1075 ) ;
F_86 ( V_2 , V_1078 , V_566 -> V_1077 ) ;
F_86 ( V_2 , V_1080 , V_566 -> V_1079 ) ;
F_86 ( V_2 , V_1082 , V_566 -> V_1081 ) ;
F_86 ( V_2 , V_1084 , V_566 -> V_1083 ) ;
F_86 ( V_2 , V_1086 , V_566 -> V_1085 ) ;
F_86 ( V_2 , V_1088 , V_566 -> V_1087 ) ;
#endif
F_394 ( V_2 , V_566 -> V_997 ) ;
F_359 ( V_2 , V_566 -> V_1089 ) ;
V_2 -> V_5 . V_49 . V_50 = false ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
void F_523 ( struct V_1 * V_2 , int * V_157 , int * V_846 )
{
struct V_757 V_1090 ;
F_297 ( V_2 , & V_1090 , V_1091 ) ;
* V_157 = V_1090 . V_157 ;
* V_846 = V_1090 . V_846 ;
}
int F_524 ( struct V_1 * V_2 ,
struct V_1092 * V_1093 )
{
struct V_829 V_830 ;
F_297 ( V_2 , & V_1093 -> V_1090 , V_1091 ) ;
F_297 ( V_2 , & V_1093 -> V_1094 , V_1095 ) ;
F_297 ( V_2 , & V_1093 -> V_1096 , V_1097 ) ;
F_297 ( V_2 , & V_1093 -> V_1098 , V_1099 ) ;
F_297 ( V_2 , & V_1093 -> V_1100 , V_1101 ) ;
F_297 ( V_2 , & V_1093 -> V_1102 , V_1103 ) ;
F_297 ( V_2 , & V_1093 -> V_1104 , V_1105 ) ;
F_297 ( V_2 , & V_1093 -> V_1106 , V_1107 ) ;
V_56 -> V_832 ( V_2 , & V_830 ) ;
V_1093 -> V_1108 . V_841 = V_830 . V_473 ;
V_1093 -> V_1108 . V_842 = V_830 . V_63 ;
V_56 -> V_831 ( V_2 , & V_830 ) ;
V_1093 -> V_1109 . V_841 = V_830 . V_473 ;
V_1093 -> V_1109 . V_842 = V_830 . V_63 ;
V_1093 -> V_101 = F_51 ( V_2 ) ;
V_1093 -> V_62 = V_2 -> V_5 . V_62 ;
V_1093 -> V_85 = F_49 ( V_2 ) ;
V_1093 -> V_128 = F_62 ( V_2 ) ;
V_1093 -> V_146 = F_76 ( V_2 ) ;
V_1093 -> V_111 = V_2 -> V_5 . V_111 ;
V_1093 -> V_30 = F_18 ( V_2 ) ;
memset ( V_1093 -> V_1110 , 0 , sizeof V_1093 -> V_1110 ) ;
if ( V_2 -> V_5 . V_590 . V_50 && ! V_2 -> V_5 . V_590 . V_591 )
F_218 ( V_2 -> V_5 . V_590 . V_16 ,
( unsigned long * ) V_1093 -> V_1110 ) ;
return 0 ;
}
int F_525 ( struct V_1 * V_2 ,
struct V_1111 * V_969 )
{
V_969 -> V_969 = V_2 -> V_5 . V_969 ;
return 0 ;
}
int F_526 ( struct V_1 * V_2 ,
struct V_1111 * V_969 )
{
V_2 -> V_5 . V_969 = V_969 -> V_969 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
int F_527 ( struct V_1 * V_2 , V_809 V_1112 , int V_1113 ,
int V_1114 , bool V_52 , T_1 V_43 )
{
struct V_771 * V_772 = & V_2 -> V_5 . V_860 ;
int V_89 ;
F_387 ( V_2 ) ;
V_89 = F_528 ( V_772 , V_1112 , V_1113 , V_1114 ,
V_52 , V_43 ) ;
if ( V_89 )
return V_883 ;
F_394 ( V_2 , V_772 -> V_870 ) ;
F_359 ( V_2 , V_772 -> V_869 ) ;
F_23 ( V_48 , V_2 ) ;
return V_885 ;
}
int F_529 ( struct V_1 * V_2 ,
struct V_1092 * V_1093 )
{
int V_1115 = 0 ;
int V_1116 , V_1117 , V_326 ;
struct V_829 V_830 ;
if ( ! F_63 ( V_2 ) && ( V_1093 -> V_128 & V_136 ) )
return - V_551 ;
V_830 . V_473 = V_1093 -> V_1108 . V_841 ;
V_830 . V_63 = V_1093 -> V_1108 . V_842 ;
V_56 -> V_834 ( V_2 , & V_830 ) ;
V_830 . V_473 = V_1093 -> V_1109 . V_841 ;
V_830 . V_63 = V_1093 -> V_1109 . V_842 ;
V_56 -> V_833 ( V_2 , & V_830 ) ;
V_2 -> V_5 . V_62 = V_1093 -> V_62 ;
V_1115 |= F_49 ( V_2 ) != V_1093 -> V_85 ;
V_2 -> V_5 . V_85 = V_1093 -> V_85 ;
F_44 ( V_143 , ( V_144 * ) & V_2 -> V_5 . V_97 ) ;
F_73 ( V_2 , V_1093 -> V_146 ) ;
V_1115 |= V_2 -> V_5 . V_111 != V_1093 -> V_111 ;
V_56 -> F_87 ( V_2 , V_1093 -> V_111 ) ;
F_19 ( V_2 , V_1093 -> V_30 ) ;
V_1115 |= F_51 ( V_2 ) != V_1093 -> V_101 ;
V_56 -> V_117 ( V_2 , V_1093 -> V_101 ) ;
V_2 -> V_5 . V_101 = V_1093 -> V_101 ;
V_1115 |= F_62 ( V_2 ) != V_1093 -> V_128 ;
V_56 -> V_139 ( V_2 , V_1093 -> V_128 ) ;
if ( V_1093 -> V_128 & V_136 )
F_67 ( V_2 ) ;
V_326 = F_201 ( & V_2 -> V_82 -> V_468 ) ;
if ( ! F_46 ( V_2 ) && F_47 ( V_2 ) ) {
F_41 ( V_2 , V_2 -> V_5 . V_84 , F_49 ( V_2 ) ) ;
V_1115 = 1 ;
}
F_202 ( & V_2 -> V_82 -> V_468 , V_326 ) ;
if ( V_1115 )
F_56 ( V_2 ) ;
V_1117 = V_570 ;
V_1116 = F_530 (
( const unsigned long * ) V_1093 -> V_1110 , V_1117 ) ;
if ( V_1116 < V_1117 ) {
F_228 ( V_2 , V_1116 , false ) ;
F_104 ( L_30 , V_1116 ) ;
}
F_296 ( V_2 , & V_1093 -> V_1090 , V_1091 ) ;
F_296 ( V_2 , & V_1093 -> V_1094 , V_1095 ) ;
F_296 ( V_2 , & V_1093 -> V_1096 , V_1097 ) ;
F_296 ( V_2 , & V_1093 -> V_1098 , V_1099 ) ;
F_296 ( V_2 , & V_1093 -> V_1100 , V_1101 ) ;
F_296 ( V_2 , & V_1093 -> V_1102 , V_1103 ) ;
F_296 ( V_2 , & V_1093 -> V_1104 , V_1105 ) ;
F_296 ( V_2 , & V_1093 -> V_1106 , V_1107 ) ;
F_226 ( V_2 ) ;
if ( F_531 ( V_2 ) && F_389 ( V_2 ) == 0xfff0 &&
V_1093 -> V_1090 . V_835 == 0xf000 && V_1093 -> V_1090 . V_842 == 0xffff0000 &&
! F_390 ( V_2 ) )
V_2 -> V_5 . V_969 = V_1050 ;
F_23 ( V_48 , V_2 ) ;
return 0 ;
}
int F_532 ( struct V_1 * V_2 ,
struct V_1118 * V_1119 )
{
unsigned long V_1089 ;
int V_3 , V_100 ;
if ( V_1119 -> V_695 & ( V_1120 | V_1121 ) ) {
V_100 = - V_1122 ;
if ( V_2 -> V_5 . V_49 . V_50 )
goto V_94;
if ( V_1119 -> V_695 & V_1120 )
F_24 ( V_2 , V_1123 ) ;
else
F_24 ( V_2 , V_1124 ) ;
}
V_1089 = F_388 ( V_2 ) ;
V_2 -> V_149 = V_1119 -> V_695 ;
if ( ! ( V_2 -> V_149 & V_1125 ) )
V_2 -> V_149 = 0 ;
if ( V_2 -> V_149 & V_150 ) {
for ( V_3 = 0 ; V_3 < V_1126 ; ++ V_3 )
V_2 -> V_5 . V_158 [ V_3 ] = V_1119 -> V_5 . V_1127 [ V_3 ] ;
V_2 -> V_5 . V_151 = V_1119 -> V_5 . V_1127 [ 7 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_1126 ; V_3 ++ )
V_2 -> V_5 . V_158 [ V_3 ] = V_2 -> V_5 . V_157 [ V_3 ] ;
}
F_78 ( V_2 ) ;
if ( V_2 -> V_149 & V_1128 )
V_2 -> V_5 . V_1129 = F_389 ( V_2 ) +
F_343 ( V_2 , V_1091 ) ;
F_359 ( V_2 , V_1089 ) ;
V_56 -> V_1130 ( V_2 ) ;
V_100 = 0 ;
V_94:
return V_100 ;
}
int F_533 ( struct V_1 * V_2 ,
struct V_1131 * V_1104 )
{
unsigned long V_1132 = V_1104 -> V_1133 ;
T_4 V_375 ;
int V_326 ;
V_326 = F_201 ( & V_2 -> V_82 -> V_468 ) ;
V_375 = F_303 ( V_2 , V_1132 , NULL ) ;
F_202 ( & V_2 -> V_82 -> V_468 , V_326 ) ;
V_1104 -> V_1134 = V_375 ;
V_1104 -> V_1135 = V_375 != V_80 ;
V_1104 -> V_1136 = 1 ;
V_1104 -> V_1137 = 0 ;
return 0 ;
}
int F_534 ( struct V_1 * V_2 , struct V_1138 * V_1139 )
{
struct V_618 * V_617 =
& V_2 -> V_5 . V_613 . V_614 -> V_617 ;
memcpy ( V_1139 -> V_1140 , V_617 -> V_1141 , 128 ) ;
V_1139 -> V_1142 = V_617 -> V_1143 ;
V_1139 -> V_1144 = V_617 -> V_1145 ;
V_1139 -> V_1146 = V_617 -> V_1147 ;
V_1139 -> V_1148 = V_617 -> V_1149 ;
V_1139 -> V_1150 = V_617 -> V_997 ;
V_1139 -> V_1151 = V_617 -> V_1152 ;
memcpy ( V_1139 -> V_1153 , V_617 -> V_1154 , sizeof V_617 -> V_1154 ) ;
return 0 ;
}
int F_535 ( struct V_1 * V_2 , struct V_1138 * V_1139 )
{
struct V_618 * V_617 =
& V_2 -> V_5 . V_613 . V_614 -> V_617 ;
memcpy ( V_617 -> V_1141 , V_1139 -> V_1140 , 128 ) ;
V_617 -> V_1143 = V_1139 -> V_1142 ;
V_617 -> V_1145 = V_1139 -> V_1144 ;
V_617 -> V_1147 = V_1139 -> V_1146 ;
V_617 -> V_1149 = V_1139 -> V_1148 ;
V_617 -> V_997 = V_1139 -> V_1150 ;
V_617 -> V_1152 = V_1139 -> V_1151 ;
memcpy ( V_617 -> V_1154 , V_1139 -> V_1153 , sizeof V_617 -> V_1154 ) ;
return 0 ;
}
int F_536 ( struct V_1 * V_2 )
{
int V_55 ;
V_55 = F_537 ( & V_2 -> V_5 . V_613 ) ;
if ( V_55 )
return V_55 ;
F_538 ( & V_2 -> V_5 . V_613 ) ;
V_2 -> V_5 . V_121 = V_123 ;
V_2 -> V_5 . V_101 |= V_108 ;
return 0 ;
}
static void F_539 ( struct V_1 * V_2 )
{
F_540 ( & V_2 -> V_5 . V_613 ) ;
}
void F_377 ( struct V_1 * V_2 )
{
if ( V_2 -> V_1155 )
return;
F_476 ( V_2 ) ;
V_2 -> V_1155 = 1 ;
F_541 () ;
F_542 ( & V_2 -> V_5 . V_613 ) ;
F_543 ( 1 ) ;
}
void F_222 ( struct V_1 * V_2 )
{
F_476 ( V_2 ) ;
if ( ! V_2 -> V_1155 )
return;
V_2 -> V_1155 = 0 ;
F_544 ( & V_2 -> V_5 . V_613 ) ;
F_545 () ;
++ V_2 -> V_60 . V_1156 ;
F_23 ( V_1025 , V_2 ) ;
F_543 ( 0 ) ;
}
void F_546 ( struct V_1 * V_2 )
{
F_173 ( V_2 ) ;
F_547 ( V_2 -> V_5 . V_557 ) ;
F_539 ( V_2 ) ;
V_56 -> V_1157 ( V_2 ) ;
}
struct V_1 * F_548 ( struct V_82 * V_82 ,
unsigned int V_1158 )
{
if ( F_123 () && F_118 ( & V_82 -> V_248 ) != 0 )
F_337 ( V_811
L_31
L_32 ) ;
return V_56 -> V_1159 ( V_82 , V_1158 ) ;
}
int F_549 ( struct V_1 * V_2 )
{
int V_100 ;
V_2 -> V_5 . V_321 . V_1160 = 1 ;
V_100 = V_558 ( V_2 ) ;
if ( V_100 )
return V_100 ;
V_100 = F_507 ( V_2 ) ;
if ( V_100 == 0 )
V_100 = F_550 ( V_2 ) ;
V_563 ( V_2 ) ;
return V_100 ;
}
int F_551 ( struct V_1 * V_2 )
{
int V_100 ;
struct V_182 V_21 ;
V_100 = V_558 ( V_2 ) ;
if ( V_100 )
return V_100 ;
V_21 . V_31 = 0x0 ;
V_21 . V_119 = V_1161 ;
V_21 . V_184 = true ;
F_121 ( V_2 , & V_21 ) ;
V_563 ( V_2 ) ;
return V_100 ;
}
void F_552 ( struct V_1 * V_2 )
{
int V_100 ;
V_2 -> V_5 . V_6 . V_376 = 0 ;
V_100 = V_558 ( V_2 ) ;
F_299 ( V_100 ) ;
F_485 ( V_2 ) ;
V_563 ( V_2 ) ;
F_539 ( V_2 ) ;
V_56 -> V_1157 ( V_2 ) ;
}
static int F_507 ( struct V_1 * V_2 )
{
F_139 ( & V_2 -> V_5 . V_68 , 0 ) ;
V_2 -> V_5 . V_598 = 0 ;
V_2 -> V_5 . V_597 = false ;
memset ( V_2 -> V_5 . V_157 , 0 , sizeof( V_2 -> V_5 . V_157 ) ) ;
V_2 -> V_5 . V_160 = V_162 ;
V_2 -> V_5 . V_148 = V_164 ;
F_78 ( V_2 ) ;
F_23 ( V_48 , V_2 ) ;
V_2 -> V_5 . V_6 . V_376 = 0 ;
V_2 -> V_5 . V_380 . V_376 = 0 ;
F_173 ( V_2 ) ;
F_55 ( V_2 ) ;
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_1029 = false ;
F_553 ( V_2 ) ;
memset ( V_2 -> V_5 . V_566 , 0 , sizeof( V_2 -> V_5 . V_566 ) ) ;
V_2 -> V_5 . V_97 = ~ 0 ;
V_2 -> V_5 . V_98 = ~ 0 ;
return V_56 -> V_1162 ( V_2 ) ;
}
int F_554 ( void * V_552 )
{
struct V_82 * V_82 ;
struct V_1 * V_2 ;
int V_3 ;
int V_89 ;
T_2 V_1163 ;
T_2 V_1164 = 0 ;
bool V_1165 , V_1166 = false ;
F_14 () ;
V_89 = V_56 -> V_1167 ( V_552 ) ;
if ( V_89 != 0 )
return V_89 ;
V_1163 = F_145 () ;
V_1165 = ! F_123 () ;
F_418 (kvm, &vm_list, vm_list) {
F_193 (i, vcpu, kvm) {
if ( ! V_1165 && V_2 -> V_23 == F_8 () )
F_218 ( V_292 , & V_2 -> V_560 ) ;
if ( V_1165 && V_2 -> V_5 . V_562 > V_1163 ) {
V_1166 = true ;
if ( V_2 -> V_5 . V_562 > V_1164 )
V_1164 = V_2 -> V_5 . V_562 ;
}
}
}
if ( V_1166 ) {
T_2 V_1168 = V_1164 - V_1163 ;
F_418 (kvm, &vm_list, vm_list) {
F_193 (i, vcpu, kvm) {
V_2 -> V_5 . V_559 += V_1168 ;
V_2 -> V_5 . V_562 = V_1163 ;
F_218 ( V_251 ,
& V_2 -> V_560 ) ;
}
V_82 -> V_5 . V_263 = 0 ;
V_82 -> V_5 . V_264 = 0 ;
}
}
return 0 ;
}
void F_555 ( void * V_552 )
{
V_56 -> V_1169 ( V_552 ) ;
F_17 ( V_552 ) ;
}
int F_556 ( void )
{
return V_56 -> V_1170 () ;
}
void F_557 ( void )
{
V_56 -> V_1171 () ;
}
void F_558 ( void * V_1172 )
{
V_56 -> V_1173 ( V_1172 ) ;
}
bool F_559 ( struct V_1 * V_2 )
{
return F_74 ( V_2 -> V_82 ) == ( V_2 -> V_5 . V_567 != NULL ) ;
}
int F_560 ( struct V_1 * V_2 )
{
struct V_351 * V_351 ;
struct V_82 * V_82 ;
int V_100 ;
F_299 ( V_2 -> V_82 == NULL ) ;
V_82 = V_2 -> V_82 ;
V_2 -> V_5 . V_860 . V_786 = & V_1174 ;
if ( ! F_74 ( V_82 ) || F_531 ( V_2 ) )
V_2 -> V_5 . V_969 = V_1050 ;
else
V_2 -> V_5 . V_969 = V_1061 ;
V_351 = F_561 ( V_632 | V_1175 ) ;
if ( ! V_351 ) {
V_100 = - V_353 ;
goto V_1176;
}
V_2 -> V_5 . V_816 = F_562 ( V_351 ) ;
F_115 ( V_2 , V_937 ) ;
V_100 = F_563 ( V_2 ) ;
if ( V_100 < 0 )
goto V_1177;
if ( F_74 ( V_82 ) ) {
V_100 = F_564 ( V_2 ) ;
if ( V_100 < 0 )
goto V_1178;
} else
F_565 ( & V_1179 ) ;
V_2 -> V_5 . V_340 = F_245 ( V_423 * sizeof( T_2 ) * 4 ,
V_632 ) ;
if ( ! V_2 -> V_5 . V_340 ) {
V_100 = - V_353 ;
goto V_1180;
}
V_2 -> V_5 . V_332 = V_423 ;
if ( ! F_566 ( & V_2 -> V_5 . V_557 , V_632 ) )
goto V_1181;
V_100 = F_536 ( V_2 ) ;
if ( V_100 )
goto V_1182;
V_2 -> V_5 . V_255 = 0x0 ;
V_2 -> V_5 . V_295 = false ;
F_1 ( V_2 ) ;
F_567 ( V_2 ) ;
return 0 ;
V_1182:
F_547 ( V_2 -> V_5 . V_557 ) ;
V_1181:
F_159 ( V_2 -> V_5 . V_340 ) ;
V_1180:
F_568 ( V_2 ) ;
V_1178:
F_569 ( V_2 ) ;
V_1177:
F_570 ( ( unsigned long ) V_2 -> V_5 . V_816 ) ;
V_1176:
return V_100 ;
}
void F_571 ( struct V_1 * V_2 )
{
int V_326 ;
F_572 ( V_2 ) ;
F_159 ( V_2 -> V_5 . V_340 ) ;
F_568 ( V_2 ) ;
V_326 = F_201 ( & V_2 -> V_82 -> V_468 ) ;
F_569 ( V_2 ) ;
F_202 ( & V_2 -> V_82 -> V_468 , V_326 ) ;
F_570 ( ( unsigned long ) V_2 -> V_5 . V_816 ) ;
if ( ! F_74 ( V_2 -> V_82 ) )
F_573 ( & V_1179 ) ;
}
int F_574 ( struct V_82 * V_82 , unsigned long type )
{
if ( type )
return - V_551 ;
F_575 ( & V_82 -> V_5 . V_1183 ) ;
F_575 ( & V_82 -> V_5 . V_1184 ) ;
F_218 ( V_709 , & V_82 -> V_5 . V_1185 ) ;
F_218 ( V_1186 ,
& V_82 -> V_5 . V_1185 ) ;
F_576 ( & V_82 -> V_5 . V_261 ) ;
F_577 ( & V_82 -> V_5 . V_1187 ) ;
F_578 ( & V_82 -> V_5 . V_277 ) ;
F_138 ( V_82 ) ;
return 0 ;
}
static void F_579 ( struct V_1 * V_2 )
{
int V_100 ;
V_100 = V_558 ( V_2 ) ;
F_299 ( V_100 ) ;
F_485 ( V_2 ) ;
V_563 ( V_2 ) ;
}
static void F_580 ( struct V_82 * V_82 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
F_193 (i, vcpu, kvm) {
F_55 ( V_2 ) ;
F_579 ( V_2 ) ;
}
F_193 (i, vcpu, kvm)
F_546 ( V_2 ) ;
F_185 ( & V_82 -> V_438 ) ;
for ( V_3 = 0 ; V_3 < F_118 ( & V_82 -> V_248 ) ; V_3 ++ )
V_82 -> V_1188 [ V_3 ] = NULL ;
F_139 ( & V_82 -> V_248 , 0 ) ;
F_186 ( & V_82 -> V_438 ) ;
}
void F_581 ( struct V_82 * V_82 )
{
F_582 ( V_82 ) ;
F_583 ( V_82 ) ;
}
void F_584 ( struct V_82 * V_82 )
{
F_585 ( V_82 ) ;
F_159 ( V_82 -> V_5 . V_721 ) ;
F_159 ( V_82 -> V_5 . V_1189 ) ;
F_580 ( V_82 ) ;
if ( V_82 -> V_5 . V_1190 )
F_586 ( V_82 -> V_5 . V_1190 ) ;
if ( V_82 -> V_5 . V_1191 )
F_586 ( V_82 -> V_5 . V_1191 ) ;
F_159 ( F_587 ( V_82 -> V_5 . V_1192 , 1 ) ) ;
}
void F_588 ( struct V_698 * free ,
struct V_698 * V_1193 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1194 ; ++ V_3 ) {
if ( ! V_1193 || free -> V_5 . V_1195 [ V_3 ] != V_1193 -> V_5 . V_1195 [ V_3 ] ) {
F_589 ( free -> V_5 . V_1195 [ V_3 ] ) ;
free -> V_5 . V_1195 [ V_3 ] = NULL ;
}
if ( V_3 == 0 )
continue;
if ( ! V_1193 || free -> V_5 . V_1196 [ V_3 - 1 ] !=
V_1193 -> V_5 . V_1196 [ V_3 - 1 ] ) {
F_589 ( free -> V_5 . V_1196 [ V_3 - 1 ] ) ;
free -> V_5 . V_1196 [ V_3 - 1 ] = NULL ;
}
}
}
int F_590 ( struct V_698 * V_10 , unsigned long V_1197 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_1194 ; ++ V_3 ) {
unsigned long V_1198 ;
int V_1199 ;
int V_710 = V_3 + 1 ;
V_1199 = F_591 ( V_10 -> V_1200 + V_1197 - 1 ,
V_10 -> V_1200 , V_710 ) + 1 ;
V_10 -> V_5 . V_1195 [ V_3 ] =
F_592 ( V_1199 * sizeof( * V_10 -> V_5 . V_1195 [ V_3 ] ) ) ;
if ( ! V_10 -> V_5 . V_1195 [ V_3 ] )
goto V_354;
if ( V_3 == 0 )
continue;
V_10 -> V_5 . V_1196 [ V_3 - 1 ] = F_592 ( V_1199 *
sizeof( * V_10 -> V_5 . V_1196 [ V_3 - 1 ] ) ) ;
if ( ! V_10 -> V_5 . V_1196 [ V_3 - 1 ] )
goto V_354;
if ( V_10 -> V_1200 & ( F_593 ( V_710 ) - 1 ) )
V_10 -> V_5 . V_1196 [ V_3 - 1 ] [ 0 ] . V_1201 = 1 ;
if ( ( V_10 -> V_1200 + V_1197 ) & ( F_593 ( V_710 ) - 1 ) )
V_10 -> V_5 . V_1196 [ V_3 - 1 ] [ V_1199 - 1 ] . V_1201 = 1 ;
V_1198 = V_10 -> V_1202 >> V_87 ;
if ( ( V_10 -> V_1200 ^ V_1198 ) & ( F_593 ( V_710 ) - 1 ) ||
! F_594 () ) {
unsigned long V_751 ;
for ( V_751 = 0 ; V_751 < V_1199 ; ++ V_751 )
V_10 -> V_5 . V_1196 [ V_3 - 1 ] [ V_751 ] . V_1201 = 1 ;
}
}
return 0 ;
V_354:
for ( V_3 = 0 ; V_3 < V_1194 ; ++ V_3 ) {
F_589 ( V_10 -> V_5 . V_1195 [ V_3 ] ) ;
V_10 -> V_5 . V_1195 [ V_3 ] = NULL ;
if ( V_3 == 0 )
continue;
F_589 ( V_10 -> V_5 . V_1196 [ V_3 - 1 ] ) ;
V_10 -> V_5 . V_1196 [ V_3 - 1 ] = NULL ;
}
return - V_353 ;
}
int F_595 ( struct V_82 * V_82 ,
struct V_698 * V_699 ,
struct V_698 V_804 ,
struct V_1203 * V_1204 ,
bool V_1205 )
{
int V_1197 = V_699 -> V_1197 ;
if ( ( V_699 -> V_1158 >= V_520 ) && V_1197 && ! V_804 . V_1197 ) {
unsigned long V_1202 ;
V_1202 = F_596 ( NULL , 0 , V_1197 * V_88 ,
V_1206 | V_1207 ,
V_1208 | V_1209 , 0 ) ;
if ( F_157 ( ( void * ) V_1202 ) )
return F_158 ( ( void * ) V_1202 ) ;
V_699 -> V_1202 = V_1202 ;
}
return 0 ;
}
void F_597 ( struct V_82 * V_82 ,
struct V_1203 * V_1204 ,
struct V_698 V_804 ,
bool V_1205 )
{
int V_1210 = 0 , V_1197 = V_1204 -> V_1211 >> V_87 ;
if ( ( V_1204 -> V_10 >= V_520 ) && V_804 . V_1197 && ! V_1197 ) {
int V_89 ;
V_89 = F_598 ( V_804 . V_1202 ,
V_804 . V_1197 * V_88 ) ;
if ( V_89 < 0 )
F_10 ( V_811
L_33
L_34 ) ;
}
if ( ! V_82 -> V_5 . V_671 )
V_1210 = F_599 ( V_82 ) ;
if ( V_1210 )
F_254 ( V_82 , V_1210 ) ;
if ( V_1197 && ( V_1204 -> V_258 & V_1212 ) )
F_600 ( V_82 , V_1204 -> V_10 ) ;
if ( V_1197 && V_804 . V_1200 != V_1204 -> V_1213 >> V_87 ) {
F_460 ( V_82 ) ;
F_601 ( V_82 ) ;
}
}
void F_602 ( struct V_82 * V_82 )
{
F_460 ( V_82 ) ;
F_601 ( V_82 ) ;
}
void F_603 ( struct V_82 * V_82 ,
struct V_698 * V_10 )
{
F_602 ( V_82 ) ;
}
int F_604 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 . V_969 == V_1050 &&
! V_2 -> V_5 . V_6 . V_1029 )
|| ! F_605 ( & V_2 -> V_1214 . V_1215 )
|| V_2 -> V_5 . V_969 == V_1049
|| F_118 ( & V_2 -> V_5 . V_68 ) ||
( F_463 ( V_2 ) &&
F_462 ( V_2 ) ) ;
}
int F_606 ( struct V_1 * V_2 )
{
return F_607 ( V_2 ) == V_1039 ;
}
int F_463 ( struct V_1 * V_2 )
{
return V_56 -> V_1011 ( V_2 ) ;
}
bool F_608 ( struct V_1 * V_2 , unsigned long V_1216 )
{
unsigned long V_1217 = F_389 ( V_2 ) +
F_343 ( V_2 , V_1091 ) ;
return V_1217 == V_1216 ;
}
unsigned long F_388 ( struct V_1 * V_2 )
{
unsigned long V_1089 ;
V_1089 = V_56 -> V_1218 ( V_2 ) ;
if ( V_2 -> V_149 & V_1128 )
V_1089 &= ~ V_1219 ;
return V_1089 ;
}
void F_359 ( struct V_1 * V_2 , unsigned long V_1089 )
{
if ( V_2 -> V_149 & V_1128 &&
F_608 ( V_2 , V_2 -> V_5 . V_1129 ) )
V_1089 |= V_1219 ;
V_56 -> V_1220 ( V_2 , V_1089 ) ;
F_23 ( V_48 , V_2 ) ;
}
void F_609 ( struct V_1 * V_2 , struct V_1221 * V_952 )
{
int V_100 ;
if ( ( V_2 -> V_5 . V_67 . V_894 != V_952 -> V_5 . V_894 ) ||
F_329 ( V_952 -> V_351 ) )
return;
V_100 = F_491 ( V_2 ) ;
if ( F_71 ( V_100 ) )
return;
if ( ! V_2 -> V_5 . V_67 . V_894 &&
V_952 -> V_5 . V_85 != V_2 -> V_5 . V_67 . V_1222 ( V_2 ) )
return;
V_2 -> V_5 . V_67 . V_1223 ( V_2 , V_952 -> V_764 , 0 , true ) ;
}
static inline T_1 F_610 ( T_3 V_83 )
{
return F_611 ( V_83 & 0xffffffff , F_612 ( V_4 ) ) ;
}
static inline T_1 F_613 ( T_1 V_1224 )
{
return ( V_1224 + 1 ) & ( F_2 ( V_4 ) - 1 ) ;
}
static void F_614 ( struct V_1 * V_2 , T_3 V_83 )
{
T_1 V_1224 = F_610 ( V_83 ) ;
while ( V_2 -> V_5 . V_6 . V_7 [ V_1224 ] != ~ 0 )
V_1224 = F_613 ( V_1224 ) ;
V_2 -> V_5 . V_6 . V_7 [ V_1224 ] = V_83 ;
}
static T_1 F_615 ( struct V_1 * V_2 , T_3 V_83 )
{
int V_3 ;
T_1 V_1224 = F_610 ( V_83 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) &&
( V_2 -> V_5 . V_6 . V_7 [ V_1224 ] != V_83 &&
V_2 -> V_5 . V_6 . V_7 [ V_1224 ] != ~ 0 ) ; V_3 ++ )
V_1224 = F_613 ( V_1224 ) ;
return V_1224 ;
}
bool F_616 ( struct V_1 * V_2 , T_3 V_83 )
{
return V_2 -> V_5 . V_6 . V_7 [ F_615 ( V_2 , V_83 ) ] == V_83 ;
}
static void F_617 ( struct V_1 * V_2 , T_3 V_83 )
{
T_1 V_3 , V_751 , V_1225 ;
V_3 = V_751 = F_615 ( V_2 , V_83 ) ;
while ( true ) {
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = ~ 0 ;
do {
V_751 = F_613 ( V_751 ) ;
if ( V_2 -> V_5 . V_6 . V_7 [ V_751 ] == ~ 0 )
return;
V_1225 = F_610 ( V_2 -> V_5 . V_6 . V_7 [ V_751 ] ) ;
} while ( ( V_3 <= V_751 ) ? ( V_3 < V_1225 && V_1225 <= V_751 ) : ( V_3 < V_1225 || V_1225 <= V_751 ) );
V_2 -> V_5 . V_6 . V_7 [ V_3 ] = V_2 -> V_5 . V_6 . V_7 [ V_751 ] ;
V_3 = V_751 ;
}
}
static int F_618 ( struct V_1 * V_2 , T_1 V_156 )
{
return F_148 ( V_2 -> V_82 , & V_2 -> V_5 . V_6 . V_31 , & V_156 ,
sizeof( V_156 ) ) ;
}
void F_619 ( struct V_1 * V_2 ,
struct V_1221 * V_952 )
{
struct V_58 V_59 ;
F_620 ( V_952 -> V_5 . V_1226 , V_952 -> V_764 ) ;
F_614 ( V_2 , V_952 -> V_5 . V_83 ) ;
if ( ! ( V_2 -> V_5 . V_6 . V_376 & V_377 ) ||
( V_2 -> V_5 . V_6 . V_378 &&
V_56 -> V_71 ( V_2 ) == 0 ) )
F_23 ( V_1028 , V_2 ) ;
else if ( ! F_618 ( V_2 , V_1227 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_861 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_952 -> V_5 . V_1226 ;
F_28 ( V_2 , & V_59 ) ;
}
}
void F_621 ( struct V_1 * V_2 ,
struct V_1221 * V_952 )
{
struct V_58 V_59 ;
F_622 ( V_952 -> V_5 . V_1226 , V_952 -> V_764 ) ;
if ( F_329 ( V_952 -> V_351 ) )
V_952 -> V_5 . V_1226 = ~ 0 ;
else
F_617 ( V_2 , V_952 -> V_5 . V_83 ) ;
if ( ( V_2 -> V_5 . V_6 . V_376 & V_377 ) &&
! F_618 ( V_2 , V_1228 ) ) {
V_59 . V_32 = V_33 ;
V_59 . V_861 = true ;
V_59 . V_43 = 0 ;
V_59 . V_64 = false ;
V_59 . V_63 = V_952 -> V_5 . V_1226 ;
F_28 ( V_2 , & V_59 ) ;
}
V_2 -> V_5 . V_6 . V_1029 = false ;
V_2 -> V_5 . V_969 = V_1050 ;
}
bool F_623 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 . V_6 . V_376 & V_377 ) )
return true ;
else
return ! F_465 ( V_2 ) &&
V_56 -> V_1011 ( V_2 ) ;
}
